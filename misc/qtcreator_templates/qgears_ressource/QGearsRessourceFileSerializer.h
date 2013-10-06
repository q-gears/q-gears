#ifndef __QGears%ClassName%Serializer_H__
#define __QGears%ClassName%Serializer_H__

#include "common/TypeDefine.h"

#include "QGearsSerializer.h"
#include "QGears%ClassName%.h"

namespace QGears
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

#endif // __QGears%ClassName%Serializer_H__
