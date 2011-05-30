#ifndef LOGGER_H
#define LOGGER_H

#include <OgreLogManager.h>
#include <OgreString.h>
#include <OgreStringConverter.h>



#define LOG_ERROR( message ) Ogre::LogManager::getSingleton().logMessage( "[ERROR] " + Ogre::String( __FILE__ ) + " " + Ogre::StringConverter::toString( __LINE__ ) + ": " + message, Ogre::LML_CRITICAL )
#define LOG_WARNING( message ) Ogre::LogManager::getSingleton().logMessage( "[WARNING] " + Ogre::String( __FILE__ ) + " " + Ogre::StringConverter::toString( __LINE__ ) + ": " + message, Ogre::LML_NORMAL )
#define LOG_TRIVIAL( message ) Ogre::LogManager::getSingleton().logMessage( message, Ogre::LML_TRIVIAL )



#endif // LOGGER_H
