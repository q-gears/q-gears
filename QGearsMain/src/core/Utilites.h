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



Ogre::StringVector
StringTokenise( const Ogre::String& str, const Ogre::String& delimiters = "\t\n ", const Ogre::String& delimiters_preserve = "", const Ogre::String& quote = "\"", const Ogre::String& esc = "\\" );



#endif // UTILITES_H
