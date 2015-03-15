#ifndef UTILITES_H
#define UTILITES_H

#include <OgreColourValue.h>
#include <OgreMatrix4.h>
#include <OgreString.h>
#include <OgreStringVector.h>
#include <OgreVector2.h>
#include <OgreVector3.h>
#include <OgreVector4.h>
#include <OgreUTFString.h>
#include <OIS.h>

#include <tinyxml/tinyxml.h>

bool                      GetBool( TiXmlNode* node, const Ogre::String& tag, bool def = false );
int                       GetInt( TiXmlNode* node, const Ogre::String& tag, int def = 0 );
float                     GetFloat( TiXmlNode* node, const Ogre::String& tag, float def = 0.0f );
const Ogre::String        GetString( TiXmlNode* node, const Ogre::String& tag, const Ogre::String& def = "" );
const Ogre::UTFString     GetUTFString( TiXmlNode* node, const Ogre::String& tag, const Ogre::UTFString& def = "" );
const Ogre::Vector2       GetVector2( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector2& def = Ogre::Vector2::ZERO );
const Ogre::Vector3       GetVector3( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector3& def = Ogre::Vector3::ZERO );
const Ogre::Vector4       GetVector4( TiXmlNode* node, const Ogre::String& tag, const Ogre::Vector4& def = Ogre::Vector4::ZERO );
const Ogre::Matrix4       GetMatrix4( TiXmlNode* node, const Ogre::String& tag, const Ogre::Matrix4& def = Ogre::Matrix4::IDENTITY );
const Ogre::Quaternion    GetQuaternion( TiXmlNode* node, const Ogre::String& tag, const Ogre::Quaternion& def = Ogre::Quaternion::IDENTITY );
const Ogre::ColourValue   GetColourValue( TiXmlNode* node, const Ogre::String& tag, const Ogre::ColourValue& def = Ogre::ColourValue::ZERO );

void                      ParsePersent( float& value_percent, float& value, const Ogre::String& string );
float                     ParseKeyFrameTime( const float length, const Ogre::String& string );



const Ogre::String
CreateAutoName( const Ogre::String prefix );



Ogre::String
KeyToString( OIS::KeyCode key );



OIS::KeyCode
StringToKey( const Ogre::String& str );



Ogre::StringVector
StringTokenise( const Ogre::String& str, const Ogre::String& delimiters = "\t\n ", const Ogre::String& delimiters_preserve = "", const Ogre::String& quote = "\"", const Ogre::String& esc = "\\" );



#endif // UTILITES_H
