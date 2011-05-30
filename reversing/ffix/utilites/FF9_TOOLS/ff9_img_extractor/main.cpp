#include <fstream>
#include <io.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;


ifstream oo;


struct Dirs{
unsigned int Type;
unsigned int Files;
unsigned int Sector;
unsigned int First_Sector;
};

struct Dir{
unsigned int Flag;
unsigned int Sector;
};

void ToFile(unsigned int addr,unsigned int ln, string file)
{
unsigned int i;
char bt;
ofstream of;

oo.seekg(addr);

of.open(file.c_str(),ios_base::binary | ios_base::out);

for (i=1; i<=ln;i++)
{
    oo.read(&bt,1);
    of.write(&bt,1);
}

of.close();
}


void ExtractDir(string dir,unsigned int dir_n,unsigned int sector,unsigned int files)
{
unsigned int i,offset;
Dir tmp1,tmp2;
FILE * fil;
char drname[50];
string path;
string path2;

memset(drname,0,50);
itoa(dir_n,drname,10);
path=dir;
path.append(drname);
path.append("/");
mkdir((path).c_str());


fil=fopen(string(path+"log.txt").c_str(),"w");
fprintf(fil,"Normal Dir\n");
oo.seekg(sector<<11); //seeks to dir sector;
cout<<"Normal Dir :"<<dec<<dir_n<<" Files:"<<files<<endl;
for (i=0;i<files;i++)
{
    oo.read((char *)&tmp1,sizeof(tmp1));
    offset=oo.tellg();
    oo.read((char *)&tmp2,sizeof(tmp2));

    memset(drname,0,50);
    itoa(i,drname,10);
    path2=path;
    path2.append(drname);

    fprintf(fil,"%d     Flag:%x     Start Sector:   %x     End Sector:  %x \n",i,tmp1.Flag,tmp1.Sector,tmp2.Sector);
    cout<<"Extracting File, Flag:"<<hex<<tmp1.Flag<<" Start Sector:"<<tmp1.Sector<<" End Sector:"<<tmp2.Sector<<endl;
    ToFile(tmp1.Sector<<11,(tmp2.Sector-tmp1.Sector)<<11,path2);

    oo.seekg(offset);
}
cout<<"Dir Ended"<<endl<<endl;
fclose(fil);
}

void ExtractScope(string dir,unsigned int dir_n,unsigned int sector,unsigned int startSector,unsigned int files)
{
unsigned int i,offset,rep_off;
unsigned short tmp1,tmp2;
FILE * fil;
char drname[50];
string path;
string path2;

memset(drname,0,50);
itoa(dir_n,drname,10);
path=dir;
path.append(drname);
mkdir((path).c_str());
path.append("/");

fil=fopen(string(path+"log.txt").c_str(),"w");
fprintf(fil,"File Scope\n");

cout<<"File Scope Dir :"<<dec<<dir_n<<" Files:"<<files<<endl;

oo.seekg(sector<<11); //seeks to dir sector;
rep_off=0;
for (i=0;i<files;i++)
{
    oo.read((char *)&tmp1,sizeof(tmp1));
    offset=oo.tellg();
    oo.read((char *)&tmp2,sizeof(tmp2));



    if ((tmp2==0xFFFF)&&(tmp1!=0xFFFF))
    {
        rep_off=tmp1;
        tmp2=tmp1;
    }

    if ((tmp1==0xFFFF)&&(tmp2!=0xFFFF))
    {
        tmp1=rep_off;
    }

    if ((tmp1==0xffff)&&(tmp2==0xffff))
    {
        tmp1=0;
        tmp2=0;
    }



    memset(drname,0,50);
    itoa(i,drname,10);
    path2=path;
    path2.append(drname);

    fprintf(fil,"%d     Start Sector:   %x     End Sector:  %x \n",i,tmp1+startSector,tmp2+startSector);
    cout<<"Extracting File"<<hex<<" Start Sector:"<<tmp1+startSector<<" End Sector:"<<tmp2+startSector<<endl;
    ToFile((tmp1+startSector)<<11,(tmp2-tmp1)<<11,path2);

    oo.seekg(offset);
}
fclose(fil);
cout<<"Dir Ended"<<endl<<endl;
}

int main(int argc, char *argv[])
{
unsigned int kols,i,offset;
char tmp[16];
string ttl;
string ff9;

Dirs tmp1,tmp2;


if (argc==3)
    {
        oo.open(argv[1],ios_base::binary|ios_base::in);
        if (!oo.is_open())
        {
        cout << "Can`t open FF9.img" << endl;
        return 0;
        }

        memset(tmp,0,16);
        oo.read(tmp,3);
        ff9=tmp;

        if (ff9!="FF9")
        {
        cout << "It is not FF9.img file." << endl;
        oo.close();
        return 0;
        }

        ttl=argv[2];                            //Directory to extract

        mkdir(ttl.c_str());

        oo.seekg(8);                            //seeking to position with number of dirs
        oo.read((char *)&kols,sizeof(kols));    //reading number of entries in ff9.img

        oo.seekg(0x10);                         //seeking to first dir
        for (i=0;i<kols;i++)                    //loop reading and extracts dirs
        {
        oo.read((char *)&tmp1,sizeof(tmp1));    //Reads current dir info
        offset=oo.tellg();
        oo.read((char *)&tmp2,sizeof(tmp2));    //reads next dir info


        switch (tmp1.Type){
        case 0x02:
        cout<<"Standart directory. Files:"<<dec<<tmp1.Files<<" Sector(Dir):"<<hex<<tmp1.Sector<<endl;
        ExtractDir(ttl+"/",i,tmp1.Sector,tmp1.Files);
        break;
        case 0x03:
        cout<<"Files, many files. Files:"<<dec<<tmp1.Files<<" Sector(Scope):"<<hex<<tmp1.Sector<<endl;
        ExtractScope(ttl+"/",i,tmp1.Sector,tmp1.First_Sector,tmp1.Files);
        break;
        case 0x04:
        cout<<"End of FF9.img"<<endl;
        break;
        }

        oo.seekg(offset);
        }

        oo.close();
        cout << endl << endl << "All files are extracted succesful." << endl;
        return 0;
    }



 	cout <<"Can`t find file, or directory incorrect!" << endl<<endl<< "2 parameters:"<<endl<<
 	"First is full path to FF9.img file"<< endl<< "Second is path to directory for extract with slash at end"<<endl<<endl<<"Usage: FF9_img_extractor.exe <FF9.img> <Directory/>"<< endl;
	return 0;
}
