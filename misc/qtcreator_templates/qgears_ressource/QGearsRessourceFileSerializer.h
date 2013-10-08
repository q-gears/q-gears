#ifndef __%NameSpace%%ClassName%Serializer_H__
#define __%NameSpace%%ClassName%Serializer_H__

#include "common/TypeDefine.h"

#include "QGearsSerializer.h"
#include "%NameSpace%%ClassName%.h"

namespace %NameSpace%
{
    class %ClassName%Serializer : public Serializer
    {
    public:
                        %ClassName%Serializer();
        virtual        ~%ClassName%Serializer();

        virtual void    import%ClassName%( Ogre::DataStreamPtr &stream, %ClassName% *pDest );

    protected:

    private:
    };
}

#endif // __%NameSpace%%ClassName%Serializer_H__
