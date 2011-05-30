#ifndef FFVIISTRING_H
#define FFVIISTRING_H



#include <Ogre.h>
#include <vector>



typedef std::vector<unsigned char> FFVIIString;



// converter
FFVIIString  RStringToFFVIIString(const Ogre::String& string);
Ogre::String FFVIIStringToRString(const FFVIIString& string);



#endif
