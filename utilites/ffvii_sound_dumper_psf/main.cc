#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <list>
#include <cstdlib>
#include <cstring>
#include <zlib.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
extern "C"
{
#include <upse.h>
}

#include "typedefs.h"
#include "walkthrough.hh"



using namespace std;
using namespace boost::filesystem;



static const bool g_WRITE_PSF = false;



struct AkaoHeader
{
	u8 magic[4];
	u16 id;
	u16 length;
	u16 reverb_mode;
	struct TimeStamp
	{
		u8 year;
		u8 month;
		u8 day;
		u8 hour;
		u8 minute;
		u8 second;
	} __attribute__((packed)) timestamp;
} __attribute__((packed));

struct PsxExeHeader
{
	char magic[8];
	u32 text;
	u32 data;
	u32 pc0;
	u32 gp0;
	u32 t_addr;
	u32 t_size;
	u32 d_addr;
	u32 d_size;
	u32 b_addr;
	u32 b_size;
	u32 s_addr;
	u32 s_size;
	u32 saved_sp;
	u32 saved_fp;
	u32 saved_gp;
	u32 saved_ra;
	u32 saved_s0;
};

struct PsfHeader
{
	char magic[3];
	u8 version;
	u32 reserved_size;
	u32 program_size;
	u32 program_crc;
};

enum ReaderState
{
	RS_MAGIC,
	RS_FOUND,

	RS_COUNT
};

static const char *g_MAGIC = "AKAO";
static const u8 g_MAGIC2[] = {0x96, 0x12, 0x18, 0x22};
static const string g_AKAO_EXT("akao");
static const string g_PSF_EXT("psf");
static const string g_WAV_EXT("wav");
static const string g_PSF_DRV_FN("ff7_scus94163_psf_v10.bin");
static const u32 g_PSF_DRV_OFFSET = 0x1a8800;
static const u32 g_PSF_SEQ_OFFSET = 0x1c0800;
static const u32 g_PSX_TEXT_START = 0x800;
static const u32 g_PSX_TEXT_SIZE = 0x1e0000;
static const u32 g_PSX_PSF_JUMP_OFFSET = 0x1960;
static const u32 g_PSX_PSF_JUMP_DATA = 0x0806e00f;
static const u32 g_AKAO_OPCODE_TABLE_OFFSET = 0x3a028;

struct PatchEntry
{
	string filename;
	u32 offset;
};

static const PatchEntry g_PSX_PSF_PATCHES[4] =
{
	{"SOUND/INSTR.ALL" , 0x000e0800},
	{"SOUND/INSTR.DAT" , 0x00156800},
	{"SOUND/INSTR2.ALL", 0x00158800},
	{"SOUND/INSTR2.DAT", 0x00196800}
};

#define MATH_ROUNDUP(x, base)   (((x) + ((base)-1)) & ~((base)-1))

streampos file_get_size(ifstream &);
void file_read(u8 *r_data, string a_path);
string int_to_str(int);
string str_lowercase(string);
bool lzs_detect(const u8 *, u32);
u8 *lzs_extract(u32 &, const u8 *, u32);
void akao_extract_cb(void *, string);
void file_list_cb(void *, string);
void psf_create(string, list<string> &);
bool akao_timestamp_valid(const AkaoHeader::TimeStamp &);
void files_delete_duplicates(list<string> &);
void psf_decode_wav(string, string);



int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		// dump akao frames to directory
		create_directory(g_AKAO_EXT);
		walkthrough(string(argv[1]), akao_extract_cb, NULL);

		// remove duplicates
		list<string> akao_file_list;
		walkthrough(g_AKAO_EXT, file_list_cb, &akao_file_list);

		files_delete_duplicates(akao_file_list);

		// create psf tracks
		create_directory(g_PSF_EXT);
		create_directory(g_WAV_EXT);
		psf_create(argv[1], akao_file_list);
	}
	else
	{
		cout << "usage: " << argv[0] << " <data_directory>" << endl;
	}

    return 0;
}


streampos file_get_size(ifstream &a_if)
{
    streampos last_pos = a_if.tellg();
    a_if.seekg(0, ios::end);
    streampos result = a_if.tellg();
    a_if.seekg(last_pos);

    return result;
}


void file_read(u8 *r_data, string a_path)
{
	ifstream iF(a_path.c_str(), ios::binary);
	if(iF.is_open())
		iF.read((char *)r_data, file_get_size(iF));
	else
		cout << "error: unable to open file " << a_path << endl;
}


string int_to_str(int a_value)
{
	string result;

	stringstream sS;
	sS << setfill('0') << setw(2) << a_value;
	sS >> result;

	return result;
}


string str_lowercase(string a_str)
{
	string result;
	result.resize(a_str.size());
	transform(a_str.begin(), a_str.end(), result.begin(), ::tolower);

	return result;
}


bool lzs_detect(const u8 *a_buffer, u32 a_size)
{
	return *(u32 *)a_buffer == a_size - sizeof(u32);
}


u8 *lzs_extract(u32 &r_output_size, const u8 *a_input, u32 a_size)
{
	const u8 *input_ptr = a_input + sizeof(u32);
	u32 input_size = *(u32 *)a_input;

	u32 buffer_size = MATH_ROUNDUP(a_size, 0xff);
	u8 *buffer = (u8 *)malloc(buffer_size);

	u32  input_offset = 0;
	r_output_size = 0;
	u8 control_byte = 0;
	u8 control_bit  = 0;

	while(input_offset < input_size)
	{
		if(control_bit == 0)
		{
			control_byte = input_ptr[input_offset++];
			control_bit = 8;
		}

		if(control_byte & 1)
		{
			buffer[r_output_size++] = input_ptr[input_offset++];

			if(r_output_size == buffer_size)
			{
				buffer_size += 0xff;
				buffer = (u8*)realloc(buffer, buffer_size);
			}
		}
		else
		{
			u8 reference1 = input_ptr[input_offset++];
			u8 reference2 = input_ptr[input_offset++];

			u16 reference_offset = reference1 | ((reference2 & 0xF0) << 4);

			u8 reference_length = (reference2 & 0xF) + 3;

			int real_offset = r_output_size - ((r_output_size - 18 - reference_offset) & 0xFFF);

			for(u32 j = 0; j < reference_length; ++j)
			{
				buffer[r_output_size++] = real_offset < 0 ? 0 : buffer[real_offset];

				if(r_output_size == buffer_size)
				{
					buffer_size += 0xff;
					buffer = (u8*)realloc(buffer, buffer_size);
				}

				++real_offset;
			}
		}

		control_byte >>= 1;
		--control_bit;
	}

	return buffer;
}


void akao_extract_cb(void *a_data, string a_file)
{
	ifstream iF(a_file.c_str(), ios::binary);
	if(!iF.is_open())
	{
		cout << "error: unable to open " << a_file << endl;
		return;
	}

	// read full file to memory
	u32 buffer_size = file_get_size(iF);
	u8 *buffer = new u8[buffer_size];
	iF.read((char *)buffer, buffer_size);
	iF.close();

	// detect and extract if compressed
	if(lzs_detect(buffer, buffer_size))
	{
		u8 *buffer_old = buffer;
		buffer = lzs_extract(buffer_size, buffer_old, buffer_size);
		delete [] buffer_old;
	}

	ReaderState state = RS_MAGIC;
	u32 magic_pos = 0;
	u32 input_offset = 0;
	int akao_counter = 0;
	while(input_offset < buffer_size)
	{
		switch(state)
		{
		case RS_MAGIC:
			magic_pos = buffer[input_offset++] == g_MAGIC[magic_pos] ? magic_pos + 1 : 0;
			if(magic_pos >= strlen(g_MAGIC))
				state = RS_FOUND;
			break;

		case RS_FOUND:
		{
			// fill akao header
			AkaoHeader header;
			memcpy(header.magic, g_MAGIC, strlen(g_MAGIC));
			memcpy(&header.id, &buffer[input_offset], sizeof(header) - sizeof(header.magic));

			if(akao_timestamp_valid(header.timestamp))
			{
				input_offset += sizeof(header) - sizeof(header.magic);
				++akao_counter;

				// construct save path
				path output_path(path(g_AKAO_EXT) / (path(str_lowercase(a_file)).stem()
					+ '_' + string(path(str_lowercase(a_file)).extension(), 1, path(str_lowercase(a_file)).extension().length() - 1)
					+ '_' + int_to_str(akao_counter) + '.' + g_AKAO_EXT));

				ofstream oF;
				oF.open(output_path.string().c_str(), ios::binary);
				oF.write((char *)&header, sizeof(header));
				oF.write((char *)&buffer[input_offset], header.length);
				input_offset += header.length;
				oF.close();
			}

			magic_pos = 0;
			state = RS_MAGIC;
		}
			break;

		default:
			;
		}
	}

	cout << "found: " << akao_counter << " ["  << a_file << "]" << endl;

	delete [] buffer;
}


void psf_create(string a_game_path, list<string> &a_file_list)
{
	path data_path(a_game_path);

	// read full file to memory
	u8 *psf_driver = new u8[g_PSX_TEXT_START + g_PSX_TEXT_SIZE];
	memset(psf_driver, 0, g_PSX_TEXT_START + g_PSX_TEXT_SIZE);
	file_read(psf_driver, (data_path / "SCUS_941.63").string());

	// convert psx executable to psf driver
	PsxExeHeader &header = *(PsxExeHeader *)psf_driver;

	// set maximal possible size to executable
	header.t_size = g_PSX_TEXT_SIZE;

	// set jump offset to psf driver
	*(u32 *)&psf_driver[g_PSX_PSF_JUMP_OFFSET] = g_PSX_PSF_JUMP_DATA;

	// inject sound data to executable
	for(u32 i = 0; i < sizeof(g_PSX_PSF_PATCHES) / sizeof(g_PSX_PSF_PATCHES[0]); ++i)
		file_read(&psf_driver[g_PSX_PSF_PATCHES[i].offset], (data_path / g_PSX_PSF_PATCHES[i].filename).string());

	// inject psf driver payload
	file_read(&psf_driver[g_PSF_DRV_OFFSET], g_PSF_DRV_FN);

	// patch akao opcode call table to replace
	// EE opcode (loop back channel stream) with A0 opcode (finish channel stream)
//	*(u32 *)&psf_driver[g_AKAO_OPCODE_TABLE_OFFSET + 0xee * sizeof(u32)] = *(u32 *)&psf_driver[g_AKAO_OPCODE_TABLE_OFFSET + 0xa0 * sizeof(u32)];

	for(list<string>::iterator it = a_file_list.begin(); it != a_file_list.end(); ++it)
	{
		u8 *buffer = new u8[g_PSX_TEXT_START + g_PSX_TEXT_SIZE];
		memcpy(buffer, psf_driver, g_PSX_TEXT_START + g_PSX_TEXT_SIZE);

		// inject akao frame with sequence
		file_read(&buffer[g_PSF_SEQ_OFFSET], *it);

		// compress data
		uLong zlib_length = compressBound(g_PSX_TEXT_START + g_PSX_TEXT_SIZE);
		u8 *psf_data = (u8 *)malloc(sizeof(PsfHeader) + zlib_length);
		Bytef *zlib_data = (Bytef *)(psf_data + sizeof(PsfHeader));

		if(compress2(zlib_data, &zlib_length, buffer, g_PSX_TEXT_START + g_PSX_TEXT_SIZE, 9) == Z_OK)
		{
			// write psf
			PsfHeader &psf_header = *(PsfHeader *)psf_data;
			memcpy(psf_header.magic, "PSF", sizeof(psf_header.magic));
			psf_header.version = 1;
			psf_header.reserved_size = 0;
			psf_header.program_size = zlib_length;
			psf_header.program_crc = crc32(crc32(0, Z_NULL, 0), zlib_data, zlib_length);

			u32 psf_length = sizeof(psf_header) + zlib_length;

			path output_path(path(g_PSF_EXT) / (path(*it).stem() + '.' + g_PSF_EXT));
			ofstream oF(output_path.string().c_str(), ios::binary);
			oF.write((char *)psf_data, psf_length);
			oF.close();

			psf_decode_wav(path(path(g_WAV_EXT) / (path(*it).stem() + '.' + g_WAV_EXT)).string(), output_path.string());
		}
		else
		{
			cout << "error: unable to compress psx executable" << endl;
		}

		free(psf_data);
		delete [] buffer;
	}

	delete [] psf_driver;
}


void file_list_cb(void *a_data, string a_file)
{
	list<string> &file_list = *(list<string> *)a_data;
	file_list.push_back(a_file);
}


bool akao_timestamp_valid(const AkaoHeader::TimeStamp &a_timestamp)
{
	static const u8 LIMIT_YEAR   = 0x99;
	static const u8 LIMIT_MONTH  = 0x12;
	static const u8 LIMIT_DAY    = 0x31;
	static const u8 LIMIT_HOUR   = 0x23;
	static const u8 LIMIT_MINUTE = 0x59;
	static const u8 LIMIT_SECOND = 0x59;

	return a_timestamp.year <= LIMIT_YEAR &&
		a_timestamp.month <= LIMIT_MONTH &&
		a_timestamp.day <= LIMIT_DAY &&
		a_timestamp.hour <= LIMIT_HOUR &&
		a_timestamp.minute <= LIMIT_MINUTE &&
		a_timestamp.second <= LIMIT_SECOND;
}


void files_delete_duplicates(list<string> &r_file_list)
{
	for(list<string>::iterator it = r_file_list.begin(); it != r_file_list.end(); ++it)
	{
		ifstream iF1(it->c_str(), ios::binary);

		if(!iF1.is_open())
			continue;

		u32 buffer1_size = file_get_size(iF1);
		u8 *buffer1 = new u8[buffer1_size];
		iF1.read((char *)buffer1, buffer1_size);
		iF1.close();

		list<string>::iterator jt = it;
		++jt;
		while(jt != r_file_list.end())
		{
			bool erased = false;

			ifstream iF2(jt->c_str(), ios::binary);
			if(iF2.is_open())
			{
				u32 buffer2_size = file_get_size(iF2);
				if(buffer1_size == buffer2_size)
				{
					u8 *buffer2 = new u8[buffer2_size];
					iF2.read((char *)buffer2, buffer2_size);

					if(!memcmp(buffer1, buffer2, buffer1_size))
					{
						remove(path(*jt));
						jt = r_file_list.erase(jt);
						erased = true;
					}

					delete [] buffer2;
				}
			}

			if(!erased)
				++jt;
		}

		delete [] buffer1;
	}
}



static void *upse_open_cb(char *path, char *mode)
{
    return fopen(path, mode);
}

static size_t upse_read_cb(void *ptr, size_t sz, size_t nmemb, void *file)
{
    return fread((FILE *)ptr, sz, nmemb, (FILE *)file);
}

static int upse_seek_cb(void *ptr, long offset, int whence)
{
    return fseek((FILE *)ptr, offset, whence);
}

static int upse_close_cb(void *ptr)
{
    return fclose((FILE *)ptr);
}


static upse_iofuncs_t upse_iofuncs =
{
    upse_open_cb,
    upse_read_cb,
    upse_seek_cb,
    upse_close_cb
};

static upse_psf_t *psf_ctx;
static u32 psf_pos;
static u32 psf_pos_samples;
static ofstream *psf_wav_fstream;
static const u32 g_PSF_FREQUENCY = 44100;
static const u32 g_PCM_TIME_LIMIT = 6 * 60;


void upse_write_audio_cb(unsigned char *data, long bytes, void *unused)
{
	psf_pos_samples += bytes / (sizeof(s16) * 2);
	psf_wav_fstream->write(const_cast<const char *>((char *)data), bytes);
	if(psf_pos_samples / g_PSF_FREQUENCY >= g_PCM_TIME_LIMIT)
		upse_stop();

	// show some time
	psf_pos += ((bytes / 4 * 1000) / 44100);
	cout << "\r";
	cout << setfill('0') << "Time: "
		<< setw(2) << ((u32)(psf_pos / 1000.0) / 60) << ":"
		<< setw(2) << ((u32)(psf_pos / 1000.0) % 60) << "."
		<< setw(2) << ((u32)(psf_pos / 10.0) % 100)
		<< flush;
}

void psf_decode_wav(string a_out_fn, string a_in_fn)
{
	cout << "decoding " << a_in_fn << " => " << a_out_fn << "... " << endl;

	// decode options
//	upse_set_reverb_mode(0);
//	upse_set_reverb_no_downsample(1);
//	upse_set_custom_bios(optarg);

	// set audio write callback
    upse_set_audio_callback(upse_write_audio_cb, NULL);

	if((psf_ctx = upse_load(const_cast<char *>(a_in_fn.c_str()), &upse_iofuncs)) == NULL)
	{
		cout << "failed to load " << a_in_fn << endl;
		return;
	}

	psf_pos = 0;
	psf_pos_samples = 0;
	ofstream oF(a_out_fn.c_str(), ios::binary);
	psf_wav_fstream = &oF;

	if(oF.is_open())
		upse_execute();

	oF.close();
	upse_free_psf_metadata(psf_ctx);

	// turn off audio write callback
    upse_set_audio_callback(NULL, NULL);
}
