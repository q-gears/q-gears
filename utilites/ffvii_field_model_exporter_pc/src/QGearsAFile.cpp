/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-12 Tobias Peters <tobias.peters@kreativeffekt.at>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "QGearsAFile.h"

#include <OgreBone.h>

namespace QGears
{
   //-------------------------------------------------------------------------
   const Ogre::Real AFile::ANIMATION_FRAME_RATE( 30 );

   //-------------------------------------------------------------------------
    AFile::AFile()
    {
    }

    //-------------------------------------------------------------------------
    AFile::~AFile()
    {
    }

    //-------------------------------------------------------------------------
    void
    AFile::add( Ogre::SkeletonPtr skeleton, const String& name ) const
    {
        Ogre::Real length( m_frames.size() / ANIMATION_FRAME_RATE );
        Ogre::Animation* anim( skeleton->createAnimation(name, length ));
        uint16 track_handle( 0 );
        Ogre::Bone* bone( skeleton->getBone( "root" ) );
        Ogre::NodeAnimationTrack* track;
        track = anim->createNodeTrack( track_handle, bone );
    }

    //-------------------------------------------------------------------------
}
