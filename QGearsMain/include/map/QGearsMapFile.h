/*
-----------------------------------------------------------------------------
Copyright (c) 27.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#ifndef __QGearsMapFile_H__
#define __QGearsMapFile_H__

#include "common/QGearsResource.h"
#include "core/EntityPoint.h"
#include "core/EntityTrigger.h"

namespace QGears
{
    class MapFile : public Resource
    {
    public:
        static const String RESOURCE_TYPE;

        MapFile( Ogre::ResourceManager *creator, const String &name
                ,Ogre::ResourceHandle handle, const String &group
                ,bool isManual = false, Ogre::ManualResourceLoader *loader = NULL );
        
        virtual ~MapFile();

        typedef EntityPoint             Point;
        typedef std::vector<Point>      PointList;
        typedef EntityTrigger           Trigger;
        typedef std::vector<Trigger>    TriggerList;

        virtual const String&       getScriptName       ( void ) const;
        virtual const String&       getBackground2dName ( void ) const;
        virtual const String&       getWalkmeshName     ( void ) const;
        virtual const Ogre::Real&   getForwardDirection ( void ) const;
        virtual       PointList&    getPoints           ( void );
        virtual       TriggerList&  getTriggers         ( void );

        virtual void setScriptName      ( const String &script_name );
        virtual void setBackground2dName( const String &background2d_name );
        virtual void setWalkmeshName    ( const String &walkmesh_name );
        virtual void setForwardDirection( const Ogre::Real &forward_direction );

    protected:
        virtual void loadImpl( void );
        virtual void unloadImpl( void );
        virtual size_t calculateSize( void ) const;
        
    private:
        String      m_script_name;
        String      m_background2d_name;
        String      m_walkmesh_name;
        Ogre::Real  m_forward_direction;
        PointList   m_points;
        TriggerList m_triggers;
    };
    
    typedef Ogre::SharedPtr<MapFile> MapFilePtr;
}
#endif // __QGearsMapFile_H__

