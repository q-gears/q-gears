#include "XmlMusicFile.h"
#include "AudioManager.h"
#include "Logger.h"


XmlMusicFile::XmlMusicFile( const Ogre::String& name, const Ogre::String& file, float loop ):
   MusicName( name ),
   MusicFile( file ),
   MusicLoop( loop )
{
}

XmlMusicFile::~XmlMusicFile()
{
}

void
XmlMusicFile::LoadMusic()
{
   AudioManager &engine = AudioManager::getSingleton();

   AudioManager::Music Music;
   Music.Name = MusicName;
   Music.File = MusicFile;
   Music.Loop = MusicLoop;

   engine.AddMusic(Music);
}
