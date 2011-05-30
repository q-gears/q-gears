#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <boost/filesystem/operations.hpp>
#include "typedefs.h"
#include "walkthrough.hh"



using namespace std;
using namespace boost::filesystem;



struct AkaoHeader
{
	u8 magic[4];
	u16 id;
	u16 length;
	u16 reverb_mode;
	u8 unused[6];
};

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

enum ReaderState
{
	RS_MAGIC,
	RS_FOUND,
	
	RS_COUNT
};

static const char *g_MAGIC = "AKAO";
static const string g_AKAO_EXT("akao");
static const string g_PSF_DRV_FN("ff7_scus94163_psf_v10.bin");
static const u32 g_PSF_DRV_OFFSET = 0x1a8800;
static const u32 g_PSX_TEXT_START = 0x800;
static const u32 g_PSX_TEXT_SIZE = 0x1E0000;
static const u32 g_PSX_PSF_JUMP_OFFSET = 0x1960;
static const u32 g_PSX_PSF_JUMP_DATA = 0x0806e00f;

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
void psf_create_cb(void *, string);



int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		// dump akao frames to directory
//		create_directory(g_AKAO_EXT);
//		walkthrough(string(argv[1]), akao_extract_cb, NULL);
		
		// create psf driver binary
		walkthrough(g_AKAO_EXT, psf_create_cb, argv[1]);
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
	ifstream iF;
	iF.open(a_file.c_str(), ios::binary);
	if(iF.is_open())
	{
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
				{
					state = RS_FOUND;
					++akao_counter;
				}
				break;
			
			case RS_FOUND:
			{
				// fill akao header
				AkaoHeader header;
				memcpy(header.magic, g_MAGIC, strlen(g_MAGIC));
				memcpy(&header.id, &buffer[input_offset], sizeof(header) - sizeof(header.magic));
				input_offset += sizeof(header) - sizeof(header.magic);
				
				// construct save path
				path output_path(path(g_AKAO_EXT) / (path(str_lowercase(a_file)).stem()
					+ '_' + string(path(str_lowercase(a_file)).extension(), 1, path(str_lowercase(a_file)).extension().length() - 1)
					+ '_' + int_to_str(akao_counter) + '.' + g_AKAO_EXT));
				
				cout << "dumping " << output_path << "... ";
				ofstream oF;
				oF.open(output_path.string().c_str(), ios::binary);
				oF.write((char *)&header, sizeof(header));
				oF.write((char *)&buffer[input_offset], header.length);
				input_offset += header.length;
				oF.close();
				cout << "done" << endl;
				
				magic_pos = 0;
				state = RS_MAGIC;
			}
				break;
			
			default:
				;
			}
		}
		
		delete [] buffer;
	}
	else
	{
		cout << "error: unable to open " << a_file << endl;
	}
}


void psf_create_cb(void *a_data, string a_file)
{
	path data_path((char *)a_data);
	
	// read full file to memory
	u8 *buffer = new u8[g_PSX_TEXT_START + g_PSX_TEXT_SIZE];
	memset(buffer, 0, g_PSX_TEXT_START + g_PSX_TEXT_SIZE);
	file_read(buffer, (data_path / "SCUS_941.63").string());
	
	// convert psx executable to psf driver
	PsxExeHeader &header = *(PsxExeHeader *)buffer;
	// set maximal possible size to executable
	header.t_size = g_PSX_TEXT_SIZE;
	// set jump offset to psf driver
	*(u32 *)&buffer[g_PSX_PSF_JUMP_OFFSET] = g_PSX_PSF_JUMP_DATA;
	// inject sound data to executable
	for(u32 i = 0; i < sizeof(g_PSX_PSF_PATCHES) / sizeof(g_PSX_PSF_PATCHES[0]); ++i)
		file_read(&buffer[g_PSX_PSF_PATCHES[i].offset], (data_path / g_PSX_PSF_PATCHES[i].filename).string());
	// inject psf driver payload
	file_read(&buffer[g_PSF_DRV_OFFSET], g_PSF_DRV_FN);
	
	//DEBUG
	{
		ofstream oF("output.bin", ios::binary);
		oF.write((char *)buffer, g_PSX_TEXT_START + g_PSX_TEXT_SIZE);
	}

	delete [] buffer;
}
