#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

#include<OgreSingleton.h>
#include <boost/thread.hpp>
#include <vorbis/vorbisfile.h>

#if defined(__WIN32__) || defined(_WIN32)
	#include <al.h>
	#include <alc.h>
#else
	#include <AL/al.h>
	#include <AL/alc.h>
#endif

class AudioManager : public Ogre::Singleton<AudioManager>
{
   public:
   /* Holds info about music file */
   struct Music
   {
      Ogre::String Name;
      Ogre::String File;
      float        Loop;
   };

   class Player
   {
      public:
      Player(const Ogre::String& id);
      ~Player();

      void Play();
      void PlayFile(const Ogre::String& file);
      void Stop();
      void Pause();

      void SetLoop(const float loop);

      const bool IsActive();
      void Update();
      float GetPosition();

      private:
      Ogre::String   m_ID;
      float          m_Loop;
      OggVorbis_File m_VorbisFile;
      vorbis_info   *m_VorbisInfo;
      int            m_VorbisSection;
      bool           m_StreamFinished;
      ALuint         m_Source;

      ALsizei FillBuffer();
   };

   public:
   AudioManager();
   virtual ~AudioManager();

   /* I guess boost uses this? */
   void operator()();

   void Pause();
   void Play();
   void Stop();
   void Update();

   void AddMusic(const AudioManager::Music &music);
   AudioManager::Music* GetMusic(const Ogre::String& name);

   static const float m_DEFAULT_LOOP;

   private:
   std::list<AudioManager::Player*> playerList;
   std::list<AudioManager::Music> musicList;

	// allocate for every new player two 96Kb buffer chunks
	// every chunk would buffer ~0.5 seconds of 44100Hz stereo 16-bit data
	// in that case we can sleep updating buffers for 250ms
   static const int m_CH_BUF_COUNT;
   static const ALsizei m_CH_BUF_SIZE;

   static const ALfloat m_LISTENER_POS[3];
   static const ALfloat m_LISTENER_VEL[3];
   static const ALfloat m_LISTENER_ORI[6];

   bool m_Initialized;
   ALCdevice *m_ALDevice;
   ALCcontext *m_ALContext;
   char *m_Buffer;

   static const uint32_t m_THREAD_SLEEP_TIME;
   boost::recursive_mutex m_UpdateMutex;
   boost::thread *m_UpdateThread;
   bool m_ThreadContinue;

   const bool Init();

   const char *ALError();
   const char *ALCError(const ALCdevice *device);
};

#endif /* AUDIOSYSTEM_H */
