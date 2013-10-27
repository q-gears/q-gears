/*
-----------------------------------------------------------------------------
Copyright (c) 26.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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

#ifndef __QGearsUtility_H__
#define __QGearsUtility_H__

#include "common/QGearsApplication.h"
#include "common/OgreBase.h"

namespace QGears
{
    class Utility : public Application
    {
    public:
        Utility( int argc, char *argv[] );
        virtual ~Utility();

        virtual Ogre::Camera*   getCamera( void );

    protected:
        virtual void initComponents( void );
        virtual void destroyComponents( void );

    private:
        Utility();
        DisplayFrameListener   *m_frame_listener;
        Ogre::SceneManager     *m_scene_manager;
        Ogre::Camera           *m_camera;
        Ogre::Viewport         *m_viewport;
    };
}

#endif // __QGearsUtility_H__
