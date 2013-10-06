#include "%SubPath%/QGears%ClassName%Serializer.%CppHeaderSuffix%"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //--------------------------------------------------------------------------
    %ClassName%Serializer::%ClassName%Serializer() :
        Serializer()
    {
    }

    //--------------------------------------------------------------------------
    %ClassName%Serializer::~%ClassName%Serializer()
    {
    }

    //--------------------------------------------------------------------------
    void
    %ClassName%Serializer::import%ClassName%( Ogre::DataStreamPtr &stream, %ClassName% *pDest )
    {
    }

    //--------------------------------------------------------------------------
}
