#include "%SubPath%/%NameSpace%%ClassNameSerializer%.%CppHeaderSuffix%"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace %NameSpace%
{
    //--------------------------------------------------------------------------
    %ClassNameSerializer%::%ClassNameSerializer%() :
        Serializer()
    {
    }

    //--------------------------------------------------------------------------
    %ClassNameSerializer%::~%ClassNameSerializer%()
    {
    }

    //--------------------------------------------------------------------------
    void
    %ClassNameSerializer%::import%ClassName%( Ogre::DataStreamPtr &stream, %ClassName% *pDest )
    {
    }

    //--------------------------------------------------------------------------
}
