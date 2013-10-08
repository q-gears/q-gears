#ifndef __%NameSpace%%ClassName%_H__
#define __%NameSpace%%ClassName%_H__

#include "common/QGearsResource.h"

namespace %NameSpace%
{
    class %ClassName% : public Resource
    {
    public:

        %ClassName%( Ogre::ResourceManager *creator, const String &name
              ,Ogre::ResourceHandle handle, const String &group
              ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );

        virtual ~%ClassName%();

        static const String RESOURCE_TYPE;

    protected:
        virtual void loadImpl( void );
        virtual void unloadImpl( void );
        virtual size_t calculateSize( void ) const;

    private:
    };

    //--------------------------------------------------------------------------
    class %ClassName%Ptr : public Ogre::SharedPtr<%ClassName%>
    {
    public:
        %ClassName%Ptr() : Ogre::SharedPtr<%ClassName%>() {}
        explicit %ClassName%Ptr( %ClassName% *rep ) : Ogre::SharedPtr<%ClassName%>(rep) {}
        %ClassName%Ptr( const %ClassName%Ptr &r ) : Ogre::SharedPtr<%ClassName%>(r) {}
        %ClassName%Ptr( const Ogre::ResourcePtr &r ) : Ogre::SharedPtr<%ClassName%>()
        {
            if( r.isNull() )
                return;
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<%ClassName%*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
        }

        /// Operator used to convert a ResourcePtr to a %ClassName%Ptr
        %ClassName%Ptr& operator=( const Ogre::ResourcePtr &r )
        {
            if(pRep == static_cast<%ClassName%*>(r.getPointer()))
                return *this;
            release();
            if( r.isNull() )
                return *this; // resource ptr is null, so the call to release above has done all we need to do.
            // lock & copy other mutex pointer
            OGRE_LOCK_MUTEX(*r.OGRE_AUTO_MUTEX_NAME)
            OGRE_COPY_AUTO_SHARED_MUTEX(r.OGRE_AUTO_MUTEX_NAME)
            pRep = static_cast<%ClassName%*>(r.getPointer());
            pUseCount = r.useCountPointer();
            useFreeMethod = r.freeMethod();
            if (pUseCount)
            {
                ++(*pUseCount);
            }
            return *this;
        }
    };
}
#endif // __%NameSpace%%ClassName%_H__
