#include <fstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstring>
#include "typedefs.h"



using namespace std;



static const u32 g_FREQUENCY = 44100;
static const u32 g_SECONDS_COUNT = 60;



streampos file_get_size(ifstream &a_if)
{
    streampos last_pos = a_if.tellg();
    a_if.seekg(0, ios::end);
    streampos result = a_if.tellg();
    a_if.seekg(last_pos);

    return result;
}


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
    	cout << "usage: " << argv[0] << " <file.wav>" << endl;
    	return 1;
    }

	ifstream iF(argv[1], ios::binary);

	if(!iF.is_open())
	{
		cout << "error: unable to open " << argv[1] << endl;
		return 2;
	}

	u32 buffer_size = file_get_size(iF);
	assert(!(buffer_size % sizeof(u32)));
	u32 buffer_size32 = buffer_size / sizeof(u32);
	u32 *buffer = new u32[buffer_size32];
	iF.read((char *)buffer, buffer_size);
	cout << "read: " << iF.gcount() << endl;
	iF.close();
	cout << setfill('0');

	bool found = false;
	u32 *ptr_end = &buffer[buffer_size32];
	for(u32 *i_ptr = &buffer[0]; i_ptr < ptr_end; ++i_ptr)
	{
		for(u32 *j_ptr = i_ptr + 1; j_ptr < ptr_end; ++j_ptr)
		{
		u32 seconds = (j_ptr - &buffer[0]) / g_FREQUENCY;
		cout << "\rposition: " << setw(2) << (seconds / g_SECONDS_COUNT)
			<< ":" << setw(2) << (seconds % g_SECONDS_COUNT) << flush;

			u32 *i_subptr = i_ptr;
			u32 *j_subptr = j_ptr;

			while(*i_subptr++ == *j_subptr++)
			{
				// first chunk gets to start of second
				if(i_subptr == j_ptr)
				{
					u32 data_size = i_subptr - i_ptr;
//					cout << (i_ptr - &buffer[0]) << " == " << (j_ptr - &buffer[0])
//						<< " [" << data_size << "]" << endl;

					// check all following data
					bool tail_looped = true;
					while(j_subptr < ptr_end)
					{
						if(memcmp(i_ptr, j_subptr, min(data_size, (u32)(ptr_end - j_subptr)) * sizeof(u32)))
						{
							tail_looped = false;
							break;
						}

						j_subptr += data_size;
					}

					if(tail_looped)
					{
						cout << endl << "attack size: " << (i_ptr - &buffer[0]) << endl;
						cout << "loop size: " << data_size << endl;
						found = true;
					}

					break;
				}
			}
		}

		if(found)
			break;
	}

	delete [] buffer;
    return 0;
}
