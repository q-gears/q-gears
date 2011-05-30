#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <direct.h>

FILE *infile;
FILE *index_file;

int cd;

int file_position, i;

//unsigned long cd1_size = 718738272; // english version
unsigned long cd1_size = 718199664; // japanese version
unsigned long cd2_size = 688700880; // english version
//unsigned long cd2_size = 729929088; // japanese version

char strindex[44] = {82,73,70,70,0, 0, 0, 0, 67,68,88,65,0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



void parse_file(unsigned long start_sector, unsigned long file_size, int id, char *file_name)
{



    unsigned char arfile[2352];
    unsigned char type[4];
    char* extention;
    unsigned long file_type;

    char number[10];

    int size_to_skip, size_to_read;

    int i;

    int ultimo;

    FILE *file;


    // find file start sector
    file_position = fseek(infile, 2352L * start_sector, 0);
    // skip sector header
    file_position = fseek(infile, 24L, 1);
    // read type
    file_position = fread(type, 1, 4, infile);
    // move back to start of sector
    file_position = fseek(infile, -28L, 1);

    // reverse byte order
    file_type = type[3] | (type[2] << 8) | (type[1] << 16) | (type[0] << 24);
    printf("file_type = 0x%x\n", file_type);

    // by default we skip sector header
    size_to_skip = 24;
    size_to_read = 2048;
    extention = "";

    // TIM
    if (file_type == 0x10000000)
    {
        extention = ".tim";
    }
    // SND
    if (file_type == 0x77647320)
    {
        extention = ".snd";
    }
    // SMD
    if (file_type == 0x736d6473)
    {
        extention = ".smd";
    }
    // SED
    if (file_type == 0x73656473)
    {
        extention = ".sed";
    }
    // DUMMY (Stringhe generate dal programma che ha creato il CD originale.)
    if (file_type == 0x49742773)
    {
        extention = ".dummy";
    }
    // UNK1
    if (file_type == 0x01000000)
    {
        extention = ".unk1";
    }
    // UNK2
    if (file_type == 0x02000000)
    {
        extention = ".unk2";
    }
    // UNK3
    if (file_type == 0x03000000)
    {
        extention = ".unk3";
    }
    // UNK4
    if (file_type == 0x04000000)
    {
        extention = ".unk4";
    }
    // UNK5
    if (file_type == 0x05000000)
    {
        extention = ".unk5";
    }
    // UNK6
    if (file_type == 0x06000000)
    {
        extention = ".unk6";
    }
    // UNK7
    if (file_type == 0x07000000)
    {
        extention = ".unk7";
    }
    // UNK8
    if (file_type == 0x08000000)
    {
        extention = ".unk8";
    }
    // STR
    if (file_type == 0x60010180)
    {
        // if we have str format we read with file sector
        size_to_skip = 0;
        size_to_read = 2352;
        extention = ".str";
    }
    // RAW
    if (file_type == 0x00120000)
    {
        extention = ".raw1";
    }
    // RAW
    if (file_type == 0x01120000)
    {
        extention = ".raw2";
    }



    // add zeros to file name 0000.xxx
    if (id < 1000)
    {
        strcat(file_name, "0");
    }
    if (id < 100)
    {
        strcat(file_name, "0");
    }
    if (id < 10)
    {
        strcat(file_name, "0");
    }

    // add number to filepath/filename
    sprintf(number, "%d", id);
    strcat(file_name, number);
    strcat(file_name, extention);



    FILE* desc_file = fopen("description.txt", "a+");
    char desc[ 255 ];
    sprintf(desc, "%s - 0x%04x, 0x%04x\n", file_name, start_sector, file_size);
    fputs (desc, desc_file);
    fclose(desc_file);



    printf("File name: \\%s\n\n", file_name);

    file = fopen(file_name, "wb");

    // if this is str then write str index
    if (size_to_read == 2352)
    {
        file_position = fwrite(strindex, 1, 44, file);
    }

    while ((file_size / (long)size_to_read) >= 1)
    {
        file_position = fseek(infile, (long)size_to_skip, 1);
        file_position = fread(arfile, 1, size_to_read, infile);
        file_position = fwrite(arfile, 1, size_to_read, file);
        file_position = fseek(infile, 2352L - (((long)size_to_read) + ((long)size_to_skip)), 1);
        file_size = file_size - (long)size_to_read;
    }

    if (size_to_read == 2048)
    {
        file_position = fseek(infile, (long)size_to_skip, 1);
        file_position = fread(arfile, 1, file_size, infile);
        file_position = fwrite(arfile, 1, file_size, file);
    }

    for(i = 0; ; i++)
    {
        if (file_name[i] == 0)
        {
            break;
        }
        if (file_name[i] == '\\')
        {
            ultimo = i;
        }
    }
    file_name[ultimo + 1] = 0;

    fclose(file);
}



// create file with cd file index
void create_index_file()
{
    // array for one sector
    unsigned char arfile[2048];

    printf("Creating index_file file list\n");
    if (cd == 1)
    {
        index_file = fopen("index_cd1.bin", "wb");
    }
    else if (cd == 2)
    {
        index_file = fopen("index_cd2.bin", "wb");
    }

    // find start of game files (the first file in the 24 sector)
    file_position = fseek(infile, 24L * 2352L, 0);

    // the size of index - 16 sectors
    for (i = 0; i < 16; i++)
    {
        printf("Sector %d\n", 24 + i);
        // pass sector header
        file_position = fseek(infile, 24L, 1);
        // read and write sector data
        file_position = fread(arfile, 1, 2048, infile);
        file_position = fwrite(arfile, 1, 2048, index_file);
        // go to next sector
        file_position = fseek(infile, 280L, 1);
    }

    fclose(index_file);
}



void extract(char *filename)
{
    signed long start_sector, file_size;
    unsigned char start[3], size[4];
    char numero[10];
    // first directory number 0
    int directory_number = 0;

    // create file with cd file index
    create_index_file();

    if (cd == 1)
    {
        index_file = fopen("index_cd1.bin", "rb");
    }
    else if (cd == 2)
    {
        index_file = fopen("index_cd2.bin", "rb");
    }

    for (i = 0; ; i++)
    {
        file_position = fread(start, 1, 3, index_file);
        file_position = fread(size, 1, 4, index_file);

        // reverse bytes order (low endian)
        start_sector = start[0] | (start[1] << 8) | (start[2] << 16);
        file_size = size[0] | (size[1] << 8) | (size[2] << 16) | (size[3] << 24);

        // end of file
        if (file_size == 0x00ffffff)
        {
            break;
        }
        if (start_sector == 0 && file_size > 0)
        {
            filename[9] = 0;
        }
        // directory
        if (file_size > 0xff000000)
        {
            // create directory name (name - number of directory)
            filename[9] = 0;
            sprintf(numero, "%d", directory_number++);
            strcat(filename, numero);
            strcat(filename, "\\");
            mkdir(filename);
            printf("number of file %d, in dir %d", -file_size, directory_number);
        }
        // file
        if (start_sector != 0 && file_size < 0xff000000 && file_size > 0)
        {
            printf("file number %d, size: 0x%x byte - ", i, file_size);
            parse_file(start_sector, file_size, i, filename);
        }
    }
}



int verify_iso()
{
    unsigned long position, size;

    position = ftell(infile);
    // set cursor to end of file
    fseek(infile, 0L, SEEK_END);
    size = ftell(infile);
    // set cursor to beginning of file
    fseek(infile, position, SEEK_SET);
    if (size == cd1_size)
    {
        printf("Found a valid Xenogears CD1 image (size: %ld bytes)\n", size);
        return 1;
    }   
    if (size == cd2_size)
    {
        printf("Found a valid Xenogears CD2 image (size: %ld bytes)\n", size);
        return 2;
    }
    else
    {
        printf("Found image (size: %ld bytes)\n", size);
        printf("ERROR: Selected file is not a valid Xenogears image.\n       Check if you are using the correct file or if the CD/ISO is damaged.\n");
        return 0;
    }
}



int
main(int argc, char *argv[])
{
    char filename[20] = "STRIPCD";

    printf("Xenogears Main Disk Dumper v0.9.67\n  Created by Graph and _Ombra_\n\n");

    if (argc != 2)
    {
        printf("USAGE:'extract.exe isofile' extract files from xeno cd image.\n");
        return EXIT_FAILURE;
    }

    if ((infile = fopen(argv[1], "rb")) == NULL)
    {
        printf("The file %s does not exist, Please check the file name.\n", argv[1]);
        return EXIT_FAILURE;
    }

    cd = verify_iso();
    if (cd == 0)
    {
        return EXIT_FAILURE;
    }
    else if (cd == 1)
    {
        strcat(filename, "1\\");
    }
    else if (cd == 2)
    {
        strcat(filename, "2\\");
    }

    mkdir(filename);
    extract(filename);
    fclose(infile);
    return EXIT_SUCCESS;
}