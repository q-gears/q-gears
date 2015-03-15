#include <cstdlib>
#include <cstring>
#include <cmath>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

// TODO: This tool needs the "libupse" fixing so it can build properly

#include <zlib.h>
extern "C"
{
//#include <upse.h>
}
#include <tinyxml/tinyxml.h>
#ifdef QGears_SOUND
#include <vorbis/codec.h>
#include <vorbis/vorbisenc.h>
#endif

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include "typedefs.h"
#include "walkthrough.hh"



using namespace std;
using namespace boost::filesystem;



#define SIZEOF(arg__) (sizeof(arg__) / sizeof(arg__[0]))
#define MATH_ROUNDUP(x, base)   (((x) + ((base)-1)) & ~((base)-1))

#ifdef linux
#define ESC_RED     "\33[31m"
#define ESC_GREEN   "\33[32m"
#define ESC_ORANGE  "\33[33m"
#define ESC_BLUE    "\33[34m"
#define ESC_MAGENTA "\33[35m"
#define ESC_CYAN    "\33[36m"
#define ESC_GREY    "\33[37m"
#define ESC_RESET   "\33[0m"
#else
#define ESC_RED     ""
#define ESC_GREEN   ""
#define ESC_ORANGE  ""
#define ESC_BLUE    ""
#define ESC_MAGENTA ""
#define ESC_CYAN    ""
#define ESC_GREY    ""
#define ESC_RESET   ""
#endif



static const u32 g_PSF_FREQUENCY = 44100;
static const u32 g_PSF_CHANNELS_COUNT = 2;
static const u32 g_TIME_DELTA = g_PSF_FREQUENCY * 5 / 100; // 0.05 seconds
static const char *g_MAGIC = "AKAO";
static const string g_AKAO_EXT("akao");
static const string g_PSF_EXT("psf");
static const string g_PCM_EXT("pcm");
static const string g_OGG_EXT("ogg");
static const string g_PSF_DRV_FN("ff7_scus94163_psf_v10.bin");
static const u32 g_PSF_DRV_OFFSET = 0x1a8800;
static const u32 g_PSF_SEQ_OFFSET = 0x1c0800;
static const u32 g_PSX_TEXT_START = 0x800;
static const u32 g_PSX_TEXT_SIZE = 0x1e0000;
static const u32 g_PSX_PSF_JUMP_OFFSET = 0x1960;
static const u32 g_PSX_PSF_JUMP_DATA = 0x0806e00f;
static const u32 g_AKAO_OPCODE_TABLE_OFFSET = 0x3a028;
static const string g_CONFIG_FN("config.xml");



static const struct
{
	u8 id;
	u8 count;
} g_OP_PARAMS[] =
{
	{0xa0, 0}, {0xa6, 0}, {0xa7, 0}, {0xb3, 0}, {0xb6, 0}, {0xba, 0}, {0xbe, 0}, {0xc2, 0},
	{0xc3, 0}, {0xc4, 0}, {0xc5, 0}, {0xc6, 0}, {0xc7, 0}, {0xc8, 0}, {0xca, 0}, {0xcb, 0},
	{0xcc, 0}, {0xcd, 0}, {0xd0, 0}, {0xd1, 0}, {0xd4, 0}, {0xd5, 0}, {0xd6, 0}, {0xd7, 0},
	{0xdb, 0}, {0xe0, 0}, {0xe1, 0}, {0xe2, 0}, {0xe3, 0}, {0xe4, 0}, {0xe5, 0}, {0xe6, 0},
	{0xe7, 0}, {0xed, 0}, {0xf3, 0}, {0xf5, 0}, {0xf9, 0}, {0xfa, 0}, {0xfb, 0}, {0xfc, 0},
	{0xff, 0}, {0xa1, 1}, {0xa2, 1}, {0xa3, 1}, {0xa5, 1}, {0xa8, 1}, {0xaa, 1}, {0xac, 1},
	{0xad, 1}, {0xae, 1}, {0xaf, 1}, {0xb1, 1}, {0xb2, 1}, {0xb5, 1}, {0xb7, 1}, {0xb9, 1},
	{0xbb, 1}, {0xbd, 1}, {0xbf, 1}, {0xc0, 1}, {0xc1, 1}, {0xc9, 1}, {0xce, 1}, {0xcf, 1},
	{0xd2, 1}, {0xd3, 1}, {0xd8, 1}, {0xd9, 1}, {0xda, 1}, {0xdc, 1}, {0xf2, 1}, {0xf6, 1},
	{0xf8, 1}, {0xa4, 2}, {0xa9, 2}, {0xab, 2}, {0xb0, 2}, {0xbc, 2}, {0xdd, 2}, {0xde, 2},
	{0xdf, 2}, {0xe8, 2}, {0xea, 2}, {0xec, 2}, {0xee, 2}, {0xf4, 2}, {0xf7, 2}, {0xfd, 2},
	{0xfe, 2}, {0xb4, 3}, {0xb8, 3}, {0xe9, 3}, {0xeb, 3}, {0xef, 3}, {0xf0, 3}, {0xf1, 3}
};

static const struct OpcodeTable
{
	u8 data[0x100];

	OpcodeTable()
	{
		memset((char *)data, 0x00, sizeof(data));
		for(u32 i = 0; i < SIZEOF(g_OP_PARAMS); ++i)
			data[g_OP_PARAMS[i].id] = g_OP_PARAMS[i].count;
	}
} g_OPCODE_TABLE;

static const struct PatchEntry
{
	string filename;
	u32 offset;
}g_PSX_PSF_PATCHES[4] =
{
	{"SOUND/INSTR.ALL" , 0x000e0800},
	{"SOUND/INSTR.DAT" , 0x00156800},
	{"SOUND/INSTR2.ALL", 0x00158800},
	{"SOUND/INSTR2.DAT", 0x00196800}
};

enum ReaderState
{
	RS_MAGIC,
	RS_FOUND,

	RS_COUNT
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

struct PsfHeader
{
	char magic[3];
	u8 version;
	u32 reserved_size;
	u32 program_size;
	u32 program_crc;
};

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
        //} __attribute__((packed)) timestamp;
        //} __attribute__((packed));
    };
};

struct Channel
{
	u32 index;
	u8 *stream;
	u32 length;
	u32 length_file;
	u32 loop_start;
	u32 loop_end;
	bool control_only;
};

struct ChannelParam
{
	u32 attack_size;
	u32 loop_size;
};

struct VorbisEncoderContext
{
#ifdef QGears_SOUND
	vorbis_info vi;
	vorbis_dsp_state vds;
	vorbis_comment vc;
	vorbis_block vb;

	ogg_stream_state os;
	ogg_page og;
	ogg_packet op;
#endif
	ofstream ofs_file;
};

struct PsfContext
{
	u32 samples_decoded;
	u32 samples_total;
	ofstream of_pcm;

	VorbisEncoderContext venc_ctx;
};



template <typename T>
string to_string(T arg)
{
	string result;

	stringstream sS;
	sS << arg;
	sS >> result;

	return result;
}



vector<Channel> akao_frame_parse(u8 *, u32);
void akao_frame_print(const vector<Channel> &, u8 *, u32);
bool akao_timestamp_valid(const AkaoHeader::TimeStamp &);
bool operator<(const Channel &, const Channel &);

void akao_extract_cb(void *, path);
void file_list_cb(void *, path);
void files_delete_duplicates(list<path> &);
void audio_tracks_create(path, list<path> &, path, path, path, const char *, float, bool, bool);

bool lzs_detect(const u8 *, u32);
u8 *lzs_extract(u32 &, const u8 *, u32);

void psf_decode(path, path, bool, char *, u32, u32, u32, float);
u32 psf_decode_time(char *, u32);
void psf_write(string, const u8 *, u32);
char *psf_alloc(u32 &, const u8 *, u32);
void psf_free(char *);

void upse_write_audio_cb(unsigned char *, long, void *);
void upse_breakpoint_cb(u32, void *);

static void *upse_open_cb(char *, char *);
static size_t upse_read_cb(void *, size_t, size_t, void *);
static int upse_seek_cb(void *, long, int);
static int upse_close_cb(void *);

int vorbis_encoder_init(VorbisEncoderContext &, path, u32, float);
void vorbis_encoder_free(VorbisEncoderContext &);
int vorbis_encoder_update(VorbisEncoderContext &, s16 *, u32, u32, bool);

string str_lowercase(string);
streampos file_get_size(ifstream &);
void file_read(u8 *r_data, string a_path);
void print_channel_stat(ChannelParam);
string samples_to_time(u32);


/*
static upse_iofuncs_t upse_iofuncs =
{
    upse_open_cb,
    upse_read_cb,
    upse_seek_cb,
    upse_close_cb
};
*/


// this is needed as workaround for dumb libupse io callbacks
u32 g_psf_data_size;
u32 g_psf_data_offset;



int main(int argc, char *argv[])
{
	bool print_usage = true;
	bool mode_print_frame = false;

	if(argc == 2)
	{
		path argument(argv[1]);

		// passed akao frame
		string extension(argument.extension().string());
		if(extension.size() && string(extension, 1, argument.extension().string().size() - 1) == g_AKAO_EXT)
		{
			mode_print_frame = true;
			print_usage = false;
		}
		// passed game directory
		else if(is_directory(argument) && exists(argument))
		{
			print_usage = false;
		}
	}
	if(print_usage)
	{
		cout << "usage: " << argv[0] << " <game_directory | akao_frame_file>" << endl;
		return 1;
	}

	string argument(argv[1]);

	if(mode_print_frame)
	{
		ifstream iF(argument.c_str(), ios::binary);
		if(iF.is_open())
		{
			u32 frame_size = static_cast<u32>(file_get_size(iF));
			u8 *frame = new u8[frame_size];
			iF.read((char *)frame, frame_size);
			iF.close();
			vector<Channel> channels = akao_frame_parse(frame, frame_size);
			akao_frame_print(channels, frame, frame_size);
			delete [] frame;
		}
		else
		{
			cout << "error: unable to open file " << argument << endl;
		}
	}
	else
	{
		TiXmlDocument config_xml(g_CONFIG_FN.c_str());
		if(config_xml.LoadFile())
		{
			TiXmlElement *config_node = config_xml.RootElement();

			// dump akao frames to directory
			cout << "searching data files for akao frames:" << endl;
			create_directory(g_AKAO_EXT);
			walkthrough(argument, akao_extract_cb, NULL);
			cout << endl;

			// remove duplicates
			cout << "removing duplicates:" << endl;
			list<path> akao_file_list;
			walkthrough(g_AKAO_EXT, file_list_cb, &akao_file_list);
			akao_file_list.sort();
			files_delete_duplicates(akao_file_list);
			cout << endl;

			// create audio tracks
			int dump_psf = 0;
			int dump_pcm = 0;
			float ogg_quality = 0.4f;
			if(config_node->QueryIntAttribute("dump_psf", &dump_psf) != TIXML_SUCCESS)
				cout << "error: dump_psf isn't integer" << endl;
			if(config_node->QueryIntAttribute("dump_pcm", &dump_pcm) != TIXML_SUCCESS)
				cout << "error: dump_pcm isn't integer" << endl;
			if(config_node->QueryFloatAttribute("ogg_quality", &ogg_quality) != TIXML_SUCCESS)
				cout << "error: ogg_quality isn't float" << endl;
			cout << "creating audio tracks:" << endl;
			audio_tracks_create(argument, akao_file_list,
				config_node->Attribute("output_directory"),
				config_node->Attribute("music_xml"),
				config_node->Attribute("music_directory"),
				config_node->Attribute("custom_bios"),
				ogg_quality, dump_psf > 0, dump_pcm > 0);
			cout << endl;
		}
		else
		{
			cout << "error: unable to load configuration file" << endl;
			return 1;
		}
	}

	return 0;
}


vector<Channel> akao_frame_parse(u8 *a_frame, u32 a_frame_size)
{
	vector<Channel> channels;

	AkaoHeader &header = *((AkaoHeader *)a_frame);

	u32 file_index = sizeof(header);
	u32 channels_mask = *(u32 *)&a_frame[file_index];
	file_index += sizeof(u32);

	Channel ch;
	for(u32 i = 0; i < sizeof(u32) * 8; ++i)
		if(channels_mask & (1 << i))
		{
			ch.index = i;
			ch.stream = &a_frame[file_index + sizeof(u16) + *(u16 *)&a_frame[file_index]];
			file_index += sizeof(u16);
			ch.control_only = true;

			channels.push_back(ch);
		}
	sort(channels.begin(), channels.end());

	// loop start and end detection
	for(u32 i = 0; i < channels.size(); ++i)
	{
		u32 state = 0;

		u32 c8_start = channels[i].loop_start = channels[i].length = channels[i].length_file =
			(i < channels.size() - 1 ? channels[i + 1].stream
			: &a_frame[min((u32)(sizeof(header) + header.length), (u32)a_frame_size)]) - channels[i].stream;
		for(u32 j = 0; j < channels[i].length; ++j)
		{
			if(state)
			{
				--state;
			}
			else
			{
				if(channels[i].stream[j] < 0xa0)
					channels[i].control_only = false;

				state = g_OPCODE_TABLE.data[channels[i].stream[j]];
				channels[i].loop_end = j;

				switch(channels[i].stream[j])
				{
					case 0xc8:
						if(c8_start == channels[i].length)
							c8_start = j;
						break;

					case 0xee:
						channels[i].loop_start = j + 3 + *(s16 *)&channels[i].stream[j + 1];
						channels[i].length = j + 1 + state;
						break;

					case 0xa0:
						channels[i].length = j + 1 + state;
						break;

					case 0xca:
						channels[i].loop_start = c8_start;
						channels[i].length = j + 1 + state;
				}
			}

		}
	}

	return channels;
}


void akao_frame_print(const vector<Channel> &a_channels, u8 *a_frame, u32 a_frame_size)
{
	AkaoHeader &header = *((AkaoHeader *)a_frame);

	cout << setfill('0');
	cout << dec;
	cout << "id: " << ESC_GREEN << header.id << ESC_RESET << endl;
	cout << "size: " << ESC_GREEN << header.length << ESC_RESET << endl;
	cout << "reverb mode: " << ESC_GREEN << header.reverb_mode << ESC_RESET << endl;

	cout << hex;
#ifdef QGears_SOUND
	cout << "date: " << ESC_GREEN
		<< setw(2) << (int)header.timestamp.year    << '/'
		<< setw(2) << (int)header.timestamp.month   << '/'
		<< setw(2) << (int)header.timestamp.day     << ' '
		<< setw(2) << (int)header.timestamp.hour    << ':'
		<< setw(2) << (int)header.timestamp.minute  << ':'
		<< setw(2) << (int)header.timestamp.second
		<< ESC_RESET << endl;
#endif

	cout << "channels count: " << dec << ESC_GREEN << a_channels.size() << ESC_RESET << hex << endl;

	for(u32 i = 0; i < a_channels.size(); ++i)
	{
		u32 state = 0;
		const char *color = ESC_RED;

		cout << "channel " << dec << (a_channels[i].index + 1) << hex << " [size: "
			<< dec << a_channels[i].length << hex << "]: " << endl;
		for(u32 j = 0; j < a_channels[i].length; ++j)
		{
			if(state)
			{
				color = ESC_ORANGE;
				--state;
			}
			else
			{
				color = a_channels[i].stream[j] < 0xa0 ? ESC_MAGENTA : ESC_RED;
				if(j == a_channels[i].loop_start || j == a_channels[i].loop_end)
					color = ESC_CYAN;
				state = g_OPCODE_TABLE.data[a_channels[i].stream[j]];
			}

			cout << color << setw(2) << (int)a_channels[i].stream[j] << ' ';
		}

		cout << ESC_RESET << endl;
	}
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
		a_timestamp.month   <= LIMIT_MONTH &&
		a_timestamp.day     <= LIMIT_DAY &&
		a_timestamp.hour    <= LIMIT_HOUR &&
		a_timestamp.minute  <= LIMIT_MINUTE &&
		a_timestamp.second  <= LIMIT_SECOND;
}


bool operator<(const Channel &a_ch1, const Channel &a_ch2)
{
	return a_ch1.stream < a_ch2.stream;
}


void akao_extract_cb(void *a_data, path a_file)
{
	ifstream iF(a_file.string().c_str(), ios::binary);
	if(!iF.is_open())
	{
		cout << "error: unable to open " << a_file << endl;
		return;
	}

	// read full file to memory
	u32 buffer_size = static_cast<u32>(file_get_size(iF));
	u8 *buffer = new u8[buffer_size];
	iF.read((char *)buffer, buffer_size);
	iF.close();

	cout << "searching in " << a_file << "... " << endl;

	// detect and extract if compressed
	if(lzs_detect(buffer, buffer_size))
	{
		u8 *buffer_old = buffer;
		buffer = lzs_extract(buffer_size, buffer_old, buffer_size);
		delete [] buffer_old;
	}

	cout << setfill('0');
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
#ifdef QGears_SOUND
			if(akao_timestamp_valid(header.timestamp))
			{
				input_offset += sizeof(header) - sizeof(header.magic);
				++akao_counter;

				// construct save path
				string output_fn(a_file.filename().string());
				size_t dot_pos;
				while((dot_pos = output_fn.find_last_of(".")) != string::npos)
					output_fn.replace(dot_pos, 1, "_");
				output_fn += "_" + to_string(akao_counter);

				output_fn = str_lowercase(output_fn);

				path output_path(g_AKAO_EXT / path(output_fn));
				output_path.replace_extension(g_AKAO_EXT);

				ofstream oF;
				oF.open(output_path.string().c_str(), ios::binary);
				if(oF.is_open())
				{
					cout << "\tfound id 0x" << hex << setw(2) << header.id << dec << ", dumping to " << output_path << "... ";
					oF.write((char *)&header, sizeof(header));
					oF.write((char *)&buffer[input_offset], header.length);
					input_offset += header.length;
					oF.close();
					cout << "done" << endl;
				}
				else
				{
					cout << "error: unable to open " << output_path << endl;
					return;
				}
			}
#endif
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


void file_list_cb(void *a_data, path a_file)
{
	list<path> &file_list = *(list<path> *)a_data;
	file_list.push_back(a_file);
}


void files_delete_duplicates(list<path> &r_file_list)
{
	for(list<path>::iterator it = r_file_list.begin(); it != r_file_list.end(); ++it)
	{
		ifstream iF1(it->string().c_str(), ios::binary);

		if(!iF1.is_open())
		{
			cout << "error: unable to open " << *it << endl;
			continue;
		}

		u32 buffer1_size = static_cast<u32>(file_get_size(iF1));
		u8 *buffer1 = new u8[buffer1_size];
		iF1.read((char *)buffer1, buffer1_size);
		iF1.close();

		list<path>::iterator jt = it;
		++jt;
		while(jt != r_file_list.end())
		{
			bool erased = false;

			ifstream iF2(jt->string().c_str(), ios::binary);
			if(iF2.is_open())
			{
				u32 buffer2_size = static_cast<u32>(file_get_size(iF2));
				if(buffer1_size == buffer2_size)
				{
					u8 *buffer2 = new u8[buffer2_size];
					iF2.read((char *)buffer2, buffer2_size);

					if(!memcmp(buffer1, buffer2, buffer1_size))
					{
						cout << "\t file " << *it << " equal to " << *jt << ", removing the latter" << endl;
						remove(path(*jt));
						jt = r_file_list.erase(jt);
						erased = true;
					}

					delete [] buffer2;
				}
			}
			else
			{
				cout << "error: unable to open " << *jt << endl;
			}

			if(!erased)
				++jt;
		}

		delete [] buffer1;
	}
}


void audio_tracks_create(path a_game_path, list<path> &a_file_list, path a_output_path, path a_music_xml_fn,
		path a_music_path, const char *a_bios_fn, float a_ogg_quality, bool a_dump_psf, bool a_dump_pcm)
{
    /*
	cout << "creating psf driver template... ";

	// read full file to memory
	u32 psf_driver_size = g_PSX_TEXT_START + g_PSX_TEXT_SIZE;
	u8 *psf_driver = new u8[psf_driver_size];
	memset(psf_driver, 0, psf_driver_size);
	file_read(psf_driver, (a_game_path / "SCUS_941.63").string());

	// convert psx executable to psf driver
	PsxExeHeader &header = *(PsxExeHeader *)psf_driver;

	// set maximal possible size to executable
	header.t_size = g_PSX_TEXT_SIZE;

	// set jump offset to psf driver
	*(u32 *)&psf_driver[g_PSX_PSF_JUMP_OFFSET] = g_PSX_PSF_JUMP_DATA;

	// inject sound data to executable
	for(u32 i = 0; i < SIZEOF(g_PSX_PSF_PATCHES); ++i)
		file_read(&psf_driver[g_PSX_PSF_PATCHES[i].offset], (a_game_path / g_PSX_PSF_PATCHES[i].filename).string());

	// inject psf driver payload
	file_read(&psf_driver[g_PSF_DRV_OFFSET], g_PSF_DRV_FN);

	cout << "done" << endl;

	if(a_bios_fn != NULL && strlen(a_bios_fn))
	{
		cout << "setting custom bios " << a_bios_fn << "... ";
		upse_set_custom_bios(a_bios_fn);
		cout << "done" << endl;
	}

	create_directory(a_output_path);
	create_directory(a_output_path / a_music_path);

	// create xml structure
	TiXmlDocument music_xml;
	music_xml.LinkEndChild(new TiXmlDeclaration("1.0", "utf-8", ""));
	TiXmlElement *music_xml_root = new TiXmlElement("musics");
	music_xml.LinkEndChild(music_xml_root);

	for(list<path>::iterator it = a_file_list.begin(); it != a_file_list.end(); ++it)
	{
		// read file
		ifstream iF(it->string().c_str(), ios::binary);
		if(!iF.is_open())
		{
			cout << "error: unable to open file " << *it << endl;
			continue;
		}

		cout << "processing " << *it << "... " << endl;

		u32 file_size = file_get_size(iF);
		u8 *file_data = new u8[file_size];
		iF.read((char *)file_data, file_size);
		iF.close();

		// analyze channels and get loop and total channel times
		vector<Channel> channels = akao_frame_parse(file_data, file_size);
		vector<ChannelParam> channel_params;
		for(u32 i = 0; i < channels.size(); ++i)
		{
			cout << "\tchannel " << setw(2) << channels[i].index + 1;
			if(channels[i].control_only)
			{
				cout << " contains only control opcodes, skipping" << endl;
				continue;
			}

			cout << " detecting properties... ";

			u32 time_loop = 0;
			u8 opcode_backup;
			bool loop_enabled = channels[i].loop_start != channels[i].length_file;

			// if track is looped, calculate channel loop start time
			if(loop_enabled)
			{
				// place a0 opcode to loop start, place breakpoint at a0 and get time
				u8 &loop_start = channels[i].stream[channels[i].loop_start];
				opcode_backup = loop_start;

				// patch opcode, write psf and get time
				loop_start = 0xa0;
				memcpy(&psf_driver[g_PSF_SEQ_OFFSET], file_data, file_size);
				u32 psf_data_size;
				char *psf_data = psf_alloc(psf_data_size, psf_driver, psf_driver_size);
				memset(&psf_driver[g_PSF_SEQ_OFFSET], 0, file_size);
				time_loop = psf_decode_time(psf_data, psf_data_size);
				psf_free(psf_data);

				// restore previous opcode
				loop_start = opcode_backup;
			}

			// calculate channel end time
			u8 &loop_end = channels[i].stream[channels[i].loop_end];
			opcode_backup = loop_end;

			// patch opcode, write psf and get time
			loop_end = 0xa0;
			memcpy(&psf_driver[g_PSF_SEQ_OFFSET], file_data, file_size);
			u32 psf_data_size;
			char *psf_data = psf_alloc(psf_data_size, psf_driver, psf_driver_size);
			memset(&psf_driver[g_PSF_SEQ_OFFSET], 0, file_size);
			u32 time_end = psf_decode_time(psf_data, psf_data_size);
			psf_free(psf_data);

			// restore previous opcode
			loop_end = opcode_backup;

			ChannelParam ch_param;
			if(loop_enabled)
			{
				ch_param.attack_size = time_loop;
				ch_param.loop_size = time_end - time_loop;
			}
			else
			{
				ch_param.attack_size = time_end;
				ch_param.loop_size = 0;
			}
			channel_params.push_back(ch_param);

			cout << "attack/loop/total: ";
			print_channel_stat(ch_param);
			cout << endl;
		}

		// if full track isn't empty
		if(channel_params.size())
		{
			// find maximal attack and loop sizes
			u32 attack_max_index = 0;
			u32 loop_max_index = 0;
			for(u32 i = 0; i < channel_params.size(); ++i)
			{
				if(channel_params[i].attack_size > channel_params[attack_max_index].attack_size)
					attack_max_index = i;
				if(channel_params[i].loop_size > channel_params[loop_max_index].loop_size)
					loop_max_index = i;
			}

			// take average loop size
			u32 loop_sum = 0;
			u32 loop_count = 0;
			for(u32 i = 0; i < channel_params.size(); ++i)
			{
				if(abs((s64)channel_params[i].loop_size -
						(s64)channel_params[loop_max_index].loop_size) <= g_TIME_DELTA)
				{
					loop_sum += channel_params[i].loop_size;
					++loop_count;
				}
			}

			ChannelParam ch_final;
			ch_final.attack_size = channel_params[attack_max_index].attack_size;
			ch_final.loop_size = loop_sum / loop_count;

			cout << "final attack/loop/total: ";
			print_channel_stat(ch_final);
			cout << endl;

			// decode psf to wav
			memcpy(&psf_driver[g_PSF_SEQ_OFFSET], file_data, file_size);
			u32 psf_data_size;
			char *psf_data = psf_alloc(psf_data_size, psf_driver, psf_driver_size);
			if(a_dump_psf)
			{
				path psf_fn(a_output_path / a_music_path / it->filename());
				psf_fn.replace_extension(g_PSF_EXT);
				cout << psf_fn << endl;

				ofstream oF(psf_fn.string().c_str(), ios::binary);
				if(oF.is_open())
				{
					cout << "\twriting file " << psf_fn << "... ";
					oF.write(psf_data, psf_data_size);
					cout << "done" << endl;
				}
				else
				{
					cout << "error: unable to open " << psf_fn << endl;
				}
			}
			memset(&psf_driver[g_PSF_SEQ_OFFSET], 0, file_size);
			path ogg_fn(a_music_path / it->filename());
			ogg_fn.replace_extension(g_OGG_EXT);
			path raw_fn(a_music_path / it->filename());
			raw_fn.replace_extension(g_PCM_EXT);

			// add xml record about track
			TiXmlElement *xml_node = new TiXmlElement("music");
			music_xml_root->LinkEndChild(xml_node);
			xml_node->SetAttribute("name", ogg_fn.stem().string() );
			xml_node->SetAttribute("file_name", ogg_fn.string() );
			xml_node->SetAttribute("loop", ch_final.attack_size);

			psf_decode(a_output_path / ogg_fn, a_output_path / raw_fn, a_dump_pcm,
					psf_data, psf_data_size, ch_final.attack_size, ch_final.loop_size, a_ogg_quality);
			psf_free(psf_data);
		}
		else
		{
			cout << "\ttrack contains only control opcodes, skipping" << endl;
		}

		delete [] file_data;
	}

	music_xml.SaveFile((a_output_path / a_music_xml_fn).string().c_str());

    delete [] psf_driver;*/
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


void psf_decode(path a_ogg_fn, path a_raw_fn, bool a_dump_pcm, char *a_psf_data, u32 a_psf_data_size,
		u32 a_attack_size, u32 a_loop_size, float a_ogg_quality)
{
    /*
	PsfContext ctx;

    upse_set_audio_callback(upse_write_audio_cb, (void *)&ctx);

	g_psf_data_size = a_psf_data_size;
	g_psf_data_offset = 0;
	upse_psf_t *psf_ctx = upse_load(a_psf_data, &upse_iofuncs);
	if(psf_ctx != NULL)
	{
		ctx.samples_decoded = 0;
		ctx.samples_total = a_attack_size + a_loop_size;

		int result = vorbis_encoder_init(ctx.venc_ctx, a_ogg_fn, a_attack_size, a_ogg_quality);
		if(a_dump_pcm)
			ctx.of_pcm.open(a_raw_fn.string().c_str(), ios::binary);

		if(!result && (!a_dump_pcm || ctx.of_pcm.is_open()))
		{
			upse_execute();

			vorbis_encoder_free(ctx.venc_ctx);
			if(a_dump_pcm)
				ctx.of_pcm.close();
		}
		else
		{
			cout << "error: failed to initialize vorbis encoder" << endl;
		}

		upse_free_psf_metadata(psf_ctx);
	}
	else
	{
		cout << "error: failed to load psf data" << endl;
	}

    upse_set_audio_callback(NULL, NULL);*/
}


u32 psf_decode_time(char *a_psf_data, u32 a_psf_data_size)
{
	u32 time = 0;

    /*
    upse_set_breakpoint_callback(upse_breakpoint_cb, (void *)&time, 0x80033894); //@[0x80049828 + 0xa0 * 4]

	g_psf_data_size = a_psf_data_size;
	g_psf_data_offset = 0;
	upse_psf_t *psf_ctx = upse_load(a_psf_data, &upse_iofuncs);
	if(psf_ctx != NULL)
	{
		upse_execute();
		upse_free_psf_metadata(psf_ctx);
	}
	else
	{
		cout << "error: failed to load psf data" << endl;
	}

	upse_set_breakpoint_callback(NULL, NULL, 0);
*/
    return time;
}


void psf_write(string a_out_fn, const u8 *a_buffer, u32 a_buffer_size)
{
	// compress data
	uLong zlib_length = compressBound(a_buffer_size);
	u8 *psf_data = (u8 *)malloc(sizeof(PsfHeader) + zlib_length);
	Bytef *zlib_data = (Bytef *)(psf_data + sizeof(PsfHeader));

	if(compress2(zlib_data, &zlib_length, a_buffer, a_buffer_size, 9) == Z_OK)
	{
		// write psf
		PsfHeader &psf_header = *(PsfHeader *)psf_data;
		memcpy(psf_header.magic, "PSF", sizeof(psf_header.magic));
		psf_header.version = 1;
		psf_header.reserved_size = 0;
		psf_header.program_size = zlib_length;
		psf_header.program_crc = crc32(crc32(0, Z_NULL, 0), zlib_data, zlib_length);

		u32 psf_length = sizeof(psf_header) + zlib_length;

		ofstream oF(a_out_fn.c_str(), ios::binary);
		oF.write((char *)psf_data, psf_length);
		oF.close();

	}
	else
	{
		cout << "error: unable to compress psx executable" << endl;
	}

	free(psf_data);
}


char *psf_alloc(u32 &r_size, const u8 *a_buffer, u32 a_buffer_size)
{
	// compress data
	uLong zlib_length = compressBound(a_buffer_size);
	char *psf_data = (char *)malloc(sizeof(PsfHeader) + zlib_length);
	Bytef *zlib_data = (Bytef *)(psf_data + sizeof(PsfHeader));

	if(compress2(zlib_data, &zlib_length, a_buffer, a_buffer_size, 9) == Z_OK)
	{
		// write psf
		PsfHeader &psf_header = *(PsfHeader *)psf_data;
		memcpy(psf_header.magic, "PSF", sizeof(psf_header.magic));
		psf_header.version = 1;
		psf_header.reserved_size = 0;
		psf_header.program_size = zlib_length;
		psf_header.program_crc = crc32(crc32(0, Z_NULL, 0), zlib_data, zlib_length);

		r_size = sizeof(psf_header) + zlib_length;
	}
	else
	{
		cout << "error: unable to compress psx executable" << endl;
	}

	return psf_data;
}


void psf_free(char *a_psf_data)
{
	free(a_psf_data);
}


void upse_write_audio_cb(unsigned char *data, long bytes, void *user_data)
{
	PsfContext &ctx = *(PsfContext *)user_data;

	u32 samples_to_write = min<u32>(bytes / (sizeof(s16) * g_PSF_CHANNELS_COUNT), ctx.samples_total - ctx.samples_decoded);
	ctx.samples_decoded += samples_to_write;

	if(ctx.of_pcm.is_open())
		ctx.of_pcm.write((char *)data, samples_to_write * sizeof(s16) * g_PSF_CHANNELS_COUNT);
	vorbis_encoder_update(ctx.venc_ctx, (s16 *)data, samples_to_write, g_PSF_CHANNELS_COUNT, ctx.samples_decoded >= ctx.samples_total);

	cout << "\r" << "\tdecoding " << samples_to_time(ctx.samples_decoded)
		<< "/" << samples_to_time(ctx.samples_total) << "... " << flush;

	if(ctx.samples_decoded >= ctx.samples_total)
	{
//		upse_stop();
		cout << "done" << endl;
	}
}


void upse_breakpoint_cb(u32 samples_count, void *user_data)
{
	*(u32 *)user_data = samples_count;
    //upse_stop();
}


void *upse_open_cb(char *path, char *mode)
{
	return path;
}


size_t upse_read_cb(void *ptr, size_t sz, size_t nmemb, void *file)
{
	char *data = (char *)file;
	size_t bytes_to_write = min((g_psf_data_size - g_psf_data_offset) / sz, nmemb) * sz;
	memcpy(ptr, &data[g_psf_data_offset], bytes_to_write);
	g_psf_data_offset += bytes_to_write;
	return bytes_to_write / sz;
}


int upse_seek_cb(void *ptr, long offset, int whence)
{
	switch(whence)
	{
	case SEEK_SET:
		g_psf_data_offset = offset;
		break;

	case SEEK_CUR:
		g_psf_data_offset += offset;
		break;

	case SEEK_END:
		g_psf_data_offset = g_psf_data_offset + offset;
		break;

	default:
		return 1;
	}

	return 0;
}


int upse_close_cb(void *ptr)
{
	return 0;
}


int vorbis_encoder_init(VorbisEncoderContext &ctx, path a_ogg_fn, u32 a_attack_size, float a_ogg_quality)
{
	int result = 1;
#ifdef QGears_SOUND
	ctx.ofs_file.open(a_ogg_fn.string().c_str(), ios::binary);
	if(!ctx.ofs_file.is_open())
		return result;

	vorbis_info_init(&ctx.vi);
	if((result = vorbis_encode_init_vbr(&ctx.vi, 2, 44100, a_ogg_quality)))
		return result;

	if((result = vorbis_analysis_init(&ctx.vds, &ctx.vi)))
		return result;

	vorbis_comment_init(&ctx.vc);
	vorbis_comment_add_tag(&ctx.vc, "LOOP", to_string(a_attack_size).c_str());

	if((result = vorbis_block_init(&ctx.vds, &ctx.vb)))
		return result;

	srand(time(NULL));
	if((result = ogg_stream_init(&ctx.os, rand())))
		return result;

	ogg_packet headers[3];
	if((result = vorbis_analysis_headerout(&ctx.vds, &ctx.vc, &headers[0], &headers[1], &headers[2])))
		return result;

	for(u32 i = 0; i < SIZEOF(headers); ++i)
		if((result = ogg_stream_packetin(&ctx.os, &headers[i])))
			return result;

	// this ensures the actual audio data will start on a new page, as per spec
	while(ogg_stream_flush(&ctx.os, &ctx.og))
	{
		ctx.ofs_file.write((char *)ctx.og.header, ctx.og.header_len);
		ctx.ofs_file.write((char *)ctx.og.body, ctx.og.body_len);
	}

	result = 0;
#endif
	return result;
}


void vorbis_encoder_free(VorbisEncoderContext &ctx)
{
#ifdef QGears_SOUND
	ogg_stream_clear(&ctx.os);
	vorbis_block_clear(&ctx.vb);
	vorbis_comment_clear(&ctx.vc);
	vorbis_dsp_clear(&ctx.vds);
	vorbis_info_clear(&ctx.vi);
#endif
}


int vorbis_encoder_update(VorbisEncoderContext &ctx, s16 *a_samples, u32 a_samples_count, u32 a_channels_count, bool a_end)
{
	int result = 0;
#ifdef QGears_SOUND
	// 3rd argument done in tricky way because we can encode audio in chunks later
	bool end = a_end;
	for(u32 samples = a_samples_count; samples || end; samples = 0)
	{
		if(samples)
		{
			// uninterleave and submit samples
			float **buffer = vorbis_analysis_buffer(&ctx.vds, samples);
			for(u32 i = 0; i < samples * a_channels_count; ++i)
				buffer[i % a_channels_count][i / a_channels_count] = a_samples[i] / 32768.f;
		}
		else
		{
			end = false;
		}
		if((result = vorbis_analysis_wrote(&ctx.vds, samples)))
			return result;

		// vorbis does some data preanalysis, then divvies up blocks for
		// more involved (potentially parallel) processing. Get a single
		// block for encoding now
		while(vorbis_analysis_blockout(&ctx.vds, &ctx.vb) == 1)
		{
			// analysis, assume we want to use bitrate management
			if((result = vorbis_analysis(&ctx.vb, NULL)))
				return result;
			if((result = vorbis_bitrate_addblock(&ctx.vb)))
				return result;

			while((result = vorbis_bitrate_flushpacket(&ctx.vds, &ctx.op)) == 1)
			{
				if((result = ogg_stream_packetin(&ctx.os, &ctx.op)))
					return result;

				while(ogg_stream_pageout(&ctx.os, &ctx.og))
				{
					ctx.ofs_file.write((char *)ctx.og.header, ctx.og.header_len);
					ctx.ofs_file.write((char *)ctx.og.body, ctx.og.body_len);

					if(ogg_page_eos(&ctx.og))
						break;
				}
			}

			if(result < 0)
				return result;
		}
	}

	result = 0;
#endif
	return result;
}


string str_lowercase(string a_str)
{
	string result;
	result.resize(a_str.size());
	transform(a_str.begin(), a_str.end(), result.begin(), ::tolower);

	return result;
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


void print_channel_stat(ChannelParam a_ch_param)
{
	u32 total_size = a_ch_param.attack_size + a_ch_param.loop_size;
	cout << samples_to_time(a_ch_param.attack_size) << "(" << a_ch_param.attack_size << ")/"
		<< samples_to_time(a_ch_param.loop_size) << "(" << a_ch_param.loop_size << ")/"
		<< samples_to_time(total_size) << "(" << total_size << ")";
}


string samples_to_time(u32 a_samples)
{
	string result;
	u32 time_seconds = a_samples / g_PSF_FREQUENCY;
	u32 milli = (a_samples % g_PSF_FREQUENCY) / (g_PSF_FREQUENCY / 100);
	u32 seconds = time_seconds % 60;
	u32 minutes = time_seconds / 60;
	stringstream sS;
	sS << setfill('0');
	sS << setw(2) << minutes << ':' << setw(2) << seconds << '.' << setw(2) << milli;
	sS >> result;

	return result;
}
