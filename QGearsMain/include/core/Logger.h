#ifndef LOGGER_H
#define LOGGER_H

#include <OgreLogManager.h>
#include <OgreString.h>
#include <OgreStringConverter.h>
#include <string>


#define LOG_ERROR( message ) Ogre::LogManager::getSingleton().logMessage( "[ERROR] " + Ogre::String( __FILE__ ) + " " + Ogre::StringConverter::toString( __LINE__ ) + ": " + message, Ogre::LML_CRITICAL )
#define LOG_WARNING( message ) Ogre::LogManager::getSingleton().logMessage( "[WARNING] " + Ogre::String( __FILE__ ) + " " + Ogre::StringConverter::toString( __LINE__ ) + ": " + message, Ogre::LML_NORMAL )
#define LOG_TRIVIAL( message ) Ogre::LogManager::getSingleton().logMessage( message, Ogre::LML_TRIVIAL )
#define LOG_CONSOLE( message) Ogre::LogManager::getSingleton().logMessage( message, Ogre::LML_NORMAL )

#ifdef _MSC_VER
#define LOG_DEBUG_EX( message ) Ogre::LogManager::getSingleton().logMessage( "[DEBUG] (" +  __FILE__ + " " + Ogre::StringConverter::toString( __LINE__ ) + ")(" + std::string( __FUNCTION__ ) + "): " + message, Ogre::LML_CRITICAL )
#define LOG_DEBUG( message ) Ogre::LogManager::getSingleton().logMessage( "[DEBUG] (" + std::string( __FUNCTION__ ) + "): " + message, Ogre::LML_CRITICAL )
#else
#define LOG_DEBUG_EX( message ) Ogre::LogManager::getSingleton().logMessage( "[DEBUG] (" +  __FILE__ + " " + Ogre::StringConverter::toString( __LINE__ ) + ")(" + std::string( __PRETTY_FUNCTION__ ) + "): " + message, Ogre::LML_CRITICAL )
#define LOG_DEBUG( message ) Ogre::LogManager::getSingleton().logMessage( "[DEBUG] (" + std::string( __PRETTY_FUNCTION__ ) + "): " + message, Ogre::LML_CRITICAL )
#endif

#endif // LOGGER_H
