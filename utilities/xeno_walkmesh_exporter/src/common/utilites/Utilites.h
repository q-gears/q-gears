// $Id: Utilites.h 76 2006-08-25 18:41:20Z crazy_otaku $

#ifndef UTILITES_H
#define UTILITES_H
// Few helpfull functions and macross



#define SAFE_DELETE(p) { delete (p); (p) = NULL; }



inline unsigned long swap_32(unsigned long n)
{
    return (n >> 24) | ((n >>  8) & 0x0000FF00) | ((n <<  8) & 0x00FF0000) | (n << 24);
}

inline unsigned short swap_16(unsigned short n)
{
    return (n >>  8) | (n <<  8);
}



int power_of_two(int input);



#endif // UTILITES_H
