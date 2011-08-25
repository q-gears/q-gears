#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <OgreSingleton.h>
#include <boost/thread.hpp>
#include <vorbis/vorbisfile.h>

#if defined(__WIN32__) || defined(_WIN32)
    #include <al.h>
    #include <alc.h>
#else
    #include <AL/al.h>
    #include <AL/alc.h>
#endif



class AudioManager : public Ogre::Singleton< AudioManager >
{
public:
    AudioManager();
    virtual ~AudioManager();

    // boost uses this
    void operator()();

    void Update();
    void MusicPause();
    void MusicPlay( const Ogre::String& name );
    void MusicStop();

    struct Music
    {
        Ogre::String name;
        Ogre::String file;
        float        loop;
    };
    void AddMusic( const AudioManager::Music& music );
    AudioManager::Music* GetMusic( const Ogre::String& name );

private:
    const bool Init();
    const char* ALError();
    const char* ALCError( const ALCdevice* device );

    class Player
    {
    public:
        Player( boost::recursive_mutex* mutex );
        ~Player();

        void Pause();
        void Play( const Ogre::String& file );
        void Stop();

        void SetLoop( const float loop );

        void Update();
        float GetPosition();

    private:
        boost::recursive_mutex* m_UpdateMutex;
        float                   m_Loop;
        OggVorbis_File          m_VorbisFile;
        vorbis_info*            m_VorbisInfo;
        int                     m_VorbisSection;
        bool                    m_StreamFinished;
        ALuint                  m_Source;

        ALsizei FillBuffer();
    };



private:
    bool                   m_Initialized;

    ALCdevice*             m_ALDevice;
    ALCcontext*            m_ALContext;
    char*                  m_Buffer;

    boost::recursive_mutex m_UpdateMutex;
    boost::thread*         m_UpdateThread;
    bool                   m_ThreadContinue;

    AudioManager::Player             m_Music;
    std::list< AudioManager::Music > m_MusicList;

    // allocate for every new player two 96Kb buffer chunks
    // every chunk would buffer ~0.5 seconds of 44100Hz stereo 16-bit data
    // in that case we can sleep updating buffers for 250ms
    static ALsizei m_ChannelBufferSize;
    static int m_ChannelBufferNumber;
};



#endif // AUDIO_MANAGER_H
