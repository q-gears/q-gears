#ifndef FFVIISTRING_H
#define FFVIISTRING_H



#include <Ogre.h>
#include <vector>



typedef std::vector< unsigned char > FFVIIString;



// converter
FFVIIString  StringToFFVIIString( const Ogre::String& string );
Ogre::String FFVIIStringToString( const FFVIIString& string );



#endif
