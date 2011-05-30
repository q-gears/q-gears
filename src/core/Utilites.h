#ifndef UTILITES_H
#define UTILITES_H

#include <OgreString.h>
#include <OgreStringVector.h>
#include <OIS.h>



const Ogre::String
CreateAutoName( const Ogre::String prefix );



Ogre::String
KeyToString( OIS::KeyCode key );

OIS::KeyCode
StringToKey( const Ogre::String& str );



// until someone fix tokenise in ogre - use this fixed version
Ogre::StringVector
StringTokenise( const Ogre::String& str, const Ogre::String& delims = "\t\n ", const Ogre::String& doubleDelims = "\"", unsigned int maxSplits = 0 );



#endif // UTILITES_H
