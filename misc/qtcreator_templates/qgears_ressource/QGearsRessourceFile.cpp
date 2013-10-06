#include "%SubPath%/QGears%ClassName%.%CppHeaderSuffix%"



#include "%SubPath%/QGears%ClassName%Serializer.%CppHeaderSuffix%"

namespace QGears
{
    //---------------------------------------------------------------------
    const String    %ClassName%::RESOURCE_TYPE( "QGears%ClassName%" );

    //---------------------------------------------------------------------
    %ClassName%::%ClassName%( Ogre::ResourceManager *creator
                 ,const String &name, Ogre::ResourceHandle handle
                 ,const String &group, bool isManual
                 ,Ogre::ManualResourceLoader *loader ) :
        Resource( creator, name, handle, group, isManual, loader )
    {
    }

    //---------------------------------------------------------------------
    %ClassName%::~%ClassName%()
    {
        unload();
    }

    //---------------------------------------------------------------------
    void
    %ClassName%::loadImpl()
    {
        %ClassName%Serializer serializer;
        Ogre::DataStreamPtr stream( openResource() );
        serializer.import%ClassName%( stream, this );
    }

    //---------------------------------------------------------------------
    void
    %ClassName%::unloadImpl()
    {
    }

    //---------------------------------------------------------------------
    size_t
    %ClassName%::calculateSize() const
    {
        return 0;
    }

    //---------------------------------------------------------------------
}
