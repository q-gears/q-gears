#ifndef __%NameSpace%%ClassNameSerializer%_H__
#define __%NameSpace%%ClassNameSerializer%_H__

#include "common/TypeDefine.h"

#include "QGearsSerializer.h"
#include "%NameSpace%%ClassName%.h"

namespace %NameSpace%
{
    class %ClassNameSerializer% : public Serializer
    {
    public:
                        %ClassNameSerializer%();
        virtual        ~%ClassNameSerializer%();

        virtual void    import%ClassName%( Ogre::DataStreamPtr &stream, %ClassName% *pDest );

    protected:

    private:
    };
}

#endif // __%NameSpace%%ClassNameSerializer%_H__
