#include "AudioManager.h"

#include <list>
#include <boost/thread.hpp>

#include "XmlMusicsFile.h"
#include "Logger.h"



template<>AudioManager *Ogre::Singleton< AudioManager >::ms_Singleton = NULL;

ALsizei AudioManager::m_ChannelBufferNumber = 2;
int AudioManager::m_ChannelBufferSize = 96 * 1024;



AudioManager::AudioManager():
    m_Initialized( false ),
    m_ThreadContinue( true ),
    m_UpdateMutex(),
    m_Music( &m_UpdateMutex )
{
    m_ALDevice = alcOpenDevice( NULL );
    if( m_ALDevice != NULL )
    {
        m_ALContext = alcCreateContext( m_ALDevice, NULL );
        if( m_ALContext != NULL )
        {
            alcMakeContextCurrent( m_ALContext );

            // listeners
            ALfloat position[ 3 ] = { 0.0f, 0.0f, 0.0f };
            ALfloat velocity[ 3 ] = { 0.0f, 0.0f, 0.0f };
            ALfloat orientation[ 6 ] = { 0.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f };
            alListenerfv( AL_POSITION, position );
            alListenerfv( AL_VELOCITY, velocity );
            alListenerfv( AL_ORIENTATION, orientation );
            m_Initialized = true;

            m_Buffer       = new char[ m_ChannelBufferSize ];
            m_UpdateThread = new boost::thread( boost::ref( *this ) );

            LOG_TRIVIAL( "AudioManager initialised." );
        }
        else
        {
            LOG_ERROR( "AudioManager failed to initialised. Could not create context for sound device." );
        }
    }
    else
    {
        LOG_ERROR( "AudioManager failed to initialised. There's no default sound device." );
    }



    // Load musics
    XmlMusicsFile musics( "./data/musics.xml" );
    musics.LoadMusics();
}



AudioManager::~AudioManager()
{
    MusicStop();

    if( m_Initialized )
    {
        m_ThreadContinue = false;
        m_UpdateThread->join();
        delete m_UpdateThread;
        delete[] m_Buffer;

        alcMakeContextCurrent( NULL );
        alcDestroyContext( m_ALContext );
        alcCloseDevice( m_ALDevice );
        LOG_TRIVIAL( "AudioManager destroyed." );
    }
}



void
AudioManager::operator()()
{
    while( m_ThreadContinue )
    {
        Update();

        boost::xtime xt;
        boost::xtime_get( &xt, boost::TIME_UTC );
        xt.nsec += 250000000; // sleep for 250 ms
        boost::thread::sleep( xt );

        m_UpdateThread->yield();
    }
}



void
AudioManager::Update()
{
    boost::recursive_mutex::scoped_lock lock( m_UpdateMutex );

    m_Music.Update();
}



void
AudioManager::MusicPause()
{
    boost::recursive_mutex::scoped_lock lock( m_UpdateMutex );

    m_Music.Pause();
}



void
AudioManager::MusicPlay( const Ogre::String& name )
{
    if( m_Initialized )
    {
        boost::recursive_mutex::scoped_lock lock( m_UpdateMutex );

        AudioManager::Music* music = GetMusic( name );
        if( music == NULL )
        {
            LOG_ERROR( "No music found with name \"" + name + "\"." );
            return;
        }

        m_Music.SetLoop( music->loop );
        m_Music.Play( music->file );
    }
}



void
AudioManager::MusicStop()
{
    boost::recursive_mutex::scoped_lock lock( m_UpdateMutex );

    m_Music.Stop();
}



void
AudioManager::AddMusic( const AudioManager::Music& music )
{
    boost::recursive_mutex::scoped_lock lock( m_UpdateMutex );

    for( std::list< AudioManager::Music >::iterator it = m_MusicList.begin(); it != m_MusicList.end(); ++it )
    {
        if( it->name == music.name )
        {
            LOG_ERROR( "Music with name '" + music.name + "' already exists." );
            return;
        }
    }

    m_MusicList.push_back( music );
}



AudioManager::Music*
AudioManager::GetMusic( const Ogre::String& name )
{
    boost::recursive_mutex::scoped_lock lock( m_UpdateMutex );

    for( std::list< AudioManager::Music >::iterator it = m_MusicList.begin(); it != m_MusicList.end(); ++it )
    {
        if( it->name == name )
        {
            return &( *it );
        }
    }

    return NULL;
}



const char*
AudioManager::ALError()
{
    //ALenum error_code = alGetError();
    //if( error_code == AL_NO_ERROR )
    {
        return NULL;
    }
    //else
    //{
        //return alGetString( error_code );
    //}
}



const char*
AudioManager::ALCError( const ALCdevice* device )
{
    //const ALCdevice *alc_device = ( ( device == NULL ) ? const_cast< ALCdevice* >( m_ALDevice ) : const_cast< ALCdevice* >( device ) );

    //ALCenum error_code = alcGetError( const_cast< ALCdevice* >( alc_device ) );
    //if( error_code == ALC_NO_ERROR )
    {
        return NULL;
    }
    //else
    //{
        //return alcGetString( const_cast< ALCdevice* >( device ), error_code );
    //}
}



AudioManager::Player::Player( boost::recursive_mutex* mutex ):
    m_Loop( -1.0 ),
    m_VorbisInfo( NULL ),
    m_VorbisSection( 0 ),
    m_StreamFinished( false ),
    m_UpdateMutex( mutex )
{
}



AudioManager::Player::~Player()
{
    Stop();
}



void
AudioManager::Player::Pause()
{
    boost::recursive_mutex::scoped_lock lock( *m_UpdateMutex );

    alSourcePause( m_Source );
}



void
AudioManager::Player::Play( const Ogre::String &file )
{
    boost::recursive_mutex::scoped_lock lock( *m_UpdateMutex );

    // open vorbis file
    if( ov_fopen( const_cast< char* >( file.c_str() ), &m_VorbisFile ) )
    {
        LOG_ERROR( "Can't play file \"" + file + "\"." );
        return;
    }

    // get file info
    m_VorbisInfo = ov_info( &m_VorbisFile, -1.0f );

    // create sound source
    alGenSources( 1, &m_Source );

    // create buffers
    ALuint buffers[ m_ChannelBufferNumber ];
    alGenBuffers( m_ChannelBufferNumber, buffers );

    // set source parameters
    alSourcei( m_Source, AL_LOOPING, AL_FALSE );

    // fill buffers
    for( int i = 0; i < m_ChannelBufferNumber; ++i )
    {
        ALsizei buffer_size = FillBuffer();

        if( buffer_size )
        {
            alBufferData( buffers[ i ], m_VorbisInfo->channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16, ( const ALvoid* )AudioManager::getSingleton().m_Buffer, ( ALsizei )buffer_size, ( ALsizei )m_VorbisInfo->rate );
            alSourceQueueBuffers( m_Source, 1, &buffers[ i ] );
        }
        else
        {
            m_StreamFinished = true;
            alDeleteBuffers( 1, &buffers[ i ] );
        }
    }

    // start playback
    alSourcePlay( m_Source );
}


void
AudioManager::Player::Stop()
{
    boost::recursive_mutex::scoped_lock lock( *m_UpdateMutex );

    // stop source
    alSourceStop( m_Source );

    // get source buffers
    int queued_count = 0;
    alGetSourcei( m_Source, AL_BUFFERS_QUEUED, &queued_count );

    // unqueue and delete buffers
    for( int i = 0; i < queued_count; ++i )
    {
        ALuint buffer_id;
        alSourceUnqueueBuffers( m_Source, 1, &buffer_id );
        alDeleteBuffers( 1, &buffer_id );
    }

    // delete source
    alDeleteSources( 1, &m_Source );

    // rest cleanup
    ov_clear( &m_VorbisFile );
}



void
AudioManager::Player::SetLoop( const float loop )
{
    boost::recursive_mutex::scoped_lock lock( *m_UpdateMutex );

    m_Loop = loop;
}



void
AudioManager::Player::Update()
{
    // try to fill processed buffers
    {
        int processed;
        alGetSourcei( m_Source, AL_BUFFERS_PROCESSED, &processed );

        for( int i = 0; i < processed; ++i )
        {
            // try fill buffer
            ALsizei buffer_size = FillBuffer();

            if( buffer_size )
            {
                ALuint buffer_id;
                alSourceUnqueueBuffers( m_Source, 1, &buffer_id );
                alBufferData( buffer_id, m_VorbisInfo->channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16, ( const ALvoid* )AudioManager::getSingleton().m_Buffer, ( ALsizei )buffer_size, ( ALsizei )m_VorbisInfo->rate );
                alSourceQueueBuffers( m_Source, 1, &buffer_id );
            }
            // finished reading stream
            else
            {
                m_StreamFinished = true;
                break;
            }
        }
    }

    // manage source state
    {
        int processed;
        alGetSourcei( m_Source, AL_BUFFERS_PROCESSED, &processed );

        int queued;
        alGetSourcei( m_Source, AL_BUFFERS_QUEUED, &queued );

        if( m_StreamFinished && processed == queued )
        {
            Stop();
        }
        else
        {
            ALenum source_state;
            alGetSourcei( m_Source, AL_SOURCE_STATE, &source_state );
            if( source_state == AL_STOPPED )
            {
                alSourcePlay( m_Source );
            }
        }
    }
}



ALsizei
AudioManager::Player::FillBuffer()
{
    ALsizei read = 0;

    if( m_StreamFinished )
    {
        return read;
    }

    char *&buffer = AudioManager::getSingleton().m_Buffer;

    bool finished = false;
    do
    {
        long result = ov_read( &m_VorbisFile, buffer + read, m_ChannelBufferSize - read, 0, 2, 1, &m_VorbisSection );

        switch( result )
        {
            // error
            case OV_HOLE:
            case OV_EBADLINK:
            case OV_EINVAL:
            {
                finished = true;
            }
            break;

            // end of stream
            case 0:
            {
                // if there isn't loop point or can't seek
                if( m_Loop < 0.0f || ov_time_seek( &m_VorbisFile, m_Loop ) )
                {
                    finished = true;
                }
            }
            break;

            // readed "result" bytes
            default:
            {
                read += result;
                if( read == m_ChannelBufferSize )
                {
                    finished = true;
                }
            }
        }
    }
    while( finished == false );

    return read;
}



float
AudioManager::Player::GetPosition()
{
    boost::recursive_mutex::scoped_lock lock( *m_UpdateMutex );

    int play_offset;
    alGetSourcei( m_Source, AL_SAMPLE_OFFSET, &play_offset );
    return ( ov_pcm_tell( &m_VorbisFile ) - ( m_ChannelBufferNumber * m_ChannelBufferSize / m_VorbisInfo->channels / sizeof( int16_t ) - play_offset ) ) * 1000 / m_VorbisInfo->rate;
}




























