#include <fstream>
#include <io.h>
#include <string.h>

using namespace std;

void ReadDB(string pth);

ifstream oo;


string fTitle(string filepath)
{
 int i,ln,dot;
string titl;

 ln=filepath.length();
 dot=ln;
 for (i=(ln);i>=1;i--)
    {
        if (filepath[i]==46) dot=i-1;
        if (filepath[i]==47 || filepath[i]==92) break;
    }
 i++;
 //titl=new char[dot-i+2];
 //memcpy(&titl[0],&filepath[i],dot-i+1);
 //titl[dot-i+1]=0;
 titl=filepath.substr(i,dot-i+1);
 //titl[0]=dot-i+1;
return titl;
}

string fPath(string filepath)
{
 int i,ln;
string path;

 ln=filepath.length();
 for (i=ln;i>0;i--)
    {
        if (filepath[i]==47 || filepath[i]==92) break;
    }

 path=filepath.substr(0,i+1);//new char[i+1];

 //memcpy(&path[0],&filepath[0],i+1);
 //filepath[i]=0;
 //path[0]=i;
return path;
}

void ToFile(int addr,int ln, int tpe, string file)
{
int nach,i;
char bt;
string path;
ofstream of;

nach=oo.tellg();
oo.seekg(addr);

//memset(path,0,255);
//strcpy(path,file);
path=file;
switch (tpe)
    {
    case 2:
    path.append(".model");
    //strcat(path,".model");
    break;
    case 3:
    path.append(".animation");
    //strcat(path,".animation");
    break;
    case 4:
    path.append(".tim");
    //strcat(path,".tim");
    break;
    case 5:
    path.append(".script");
    //strcat(path,".script");
    break;
    case 8:
    path.append(".akao");
    //strcat(path,".akao");
    break;
    case 0x0a:
    path.append(".tileinfo");
    //strcat(path,".akao");
    break;
    case 0x0b:
    path.append(".walkmesh");
    //strcat(path,".akao");
    break;
    };
of.open(path.c_str(),ios_base::binary | ios_base::out);

for (i=1; i<=ln;i++)
{
    oo.read(&bt,1);
    of.write(&bt,1);
}

of.close();

oo.seekg(nach);
}

void Extract(string pth)
{
    int i,nach,lnach,lkon,tmp1,tmp2;
    char tip,items,items2;

    string path;
    char drname[50];
    path=pth;

    oo.read(&tip,1);
    oo.read(&items,1);
    oo.read((char*)&tmp1,2);

    items2=items;


    if ((items & 1) == 1) items2=items+1;

    for (i=1;i<=items2;i++)
    {
        oo.read((char*)&tmp1,2);
    }

    nach=oo.tellg();
    lnach=nach;
    lkon=lnach;

    for (i=1; i<=(items-1); i++)
        {
        lnach=oo.tellg();
        oo.read((char *)&tmp1,4);
        lkon=oo.tellg();
        oo.read((char *)&tmp2,4);
        oo.seekg(lkon);
        path=pth;
    //    memset(path,0,255);
        memset(drname,0,50);
    //    strcpy(path,pth);
        itoa(i,drname,10);
    //    strcat(path,drname);
        path.append(drname);

        ToFile(tmp1+lnach,(tmp2+lkon)-(tmp1+lnach),tip,path);
    }

    path=pth;
    //memset(path,0,255);
    memset(drname,0,50);
    //strcpy(path,pth);
    itoa(i,drname,10);
    //strcat(path,drname);
    path.append(drname);
    oo.read((char *)&tmp1,4);
    oo.read((char *)&tmp2,4);
    ToFile(tmp1+lkon,(tmp2+nach)-(tmp1+lkon),tip,path);
}



void Read1B(string pth)
{
int i,lnach,tmp1,tmp2;
char tip,items,items2;

string path;
path=pth;
char drname[50];

oo.read(&tip,1);
oo.read(&items,1);
oo.read((char*)&tmp1,2);

items2=items;

    if ((items & 1) == 1)
    {
        items2 = items + 1;
    }

    for (i = 1; i <= items2; ++i)
    {
        oo.read((char*)&tmp1,2);
    }

    for (i = 1; i <= items; ++i)
    {
        lnach=oo.tellg();
        oo.read((char *)&tmp1,4);
        tmp2=oo.tellg();
        //memset(path,0,255);
        memset(drname,0,50);
        //strcpy(path,pth);
        path=pth;
        itoa(i,drname,10);
        path.append(drname);
        //strcat(path,drname);
        mkdir(path.c_str());
        //strcat(path,"\\");
        oo.seekg(tmp1+lnach);
        ReadDB(path+"/");
        oo.seekg(tmp2);
    }
}

void ReadDB(string pth)
{
    char tchr1=0,items=0;
    short tshrt1=0;
    int grip=0,i=0,tint1=0,tmppos=0;

    string path;
    char drname[50];
    oo.read((char *)&tint1,1);

    if (tint1!=0xDB){printf ("%s \n","fuck"); return;}

    oo.read(&items,1);
    oo.read((char *)&tshrt1,2);


    for (i=1;i<=items;i++)
    {
        grip=oo.tellg();
        tint1=0;
        oo.read((char *)&tint1,3);
        oo.read(&tchr1,1);

        tmppos=oo.tellg();

        path=pth;
    //    memset(path,0,255);
        memset(drname,0,50);
    //    strcpy(path,pth);
        itoa(tchr1,drname,16);
    //    strcat(path,drname);

        path.append(drname);

        mkdir(path.c_str());
        //strcat(path,"\\");

        oo.seekg(grip+tint1);
        if (tchr1==0x1B)
        {
            Read1B(path+"/");
        }
        else
        {
            Extract(path+"/");
        };

        oo.seekg(tmppos);
    }
}


int main(int argc, char *argv[])
{
string path,title,arg;
    if (argc==2)
    {
        arg=argv[1];
        oo.open(arg.c_str(),ios_base::binary|ios_base::in);

        title=fTitle(arg);
        path=fPath(arg);
//        strcat(path,title);
        mkdir((path+title).c_str());
//        strcat(path,"\\");

        ReadDB(path+title+"/");
        oo.close();
    }


	return 0;
}
