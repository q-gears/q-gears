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
#ifndef __QGearsAFile_H__
#define __QGearsAFile_H__

#include <OgreSkeleton.h>
#include <OgreVector3.h>

#include "common/TypeDefine.h"

namespace QGears
{
    class AFile
    {
    public:
        AFile();
        virtual ~AFile();

        static const Ogre::Real FRAME_DURATION;

        virtual void addTo( Ogre::SkeletonPtr skeleton, const String& name ) const;

        typedef std::vector<Ogre::Vector3>  BoneRotationList;

        struct Frame
        {
            Ogre::Vector3       root_rotation;
            Ogre::Vector3       root_translation;
            BoneRotationList    bone_rotations;
        };

        typedef std::vector<Frame>  FrameList;
        virtual FrameList&  getFrames() { return m_frames; };

        virtual void    setBoneCount( const uint32 bone_count );
    protected:

        virtual void    setFrameRotation( Ogre::TransformKeyFrame* key_frame
                                         ,const Ogre::Vector3& rotation ) const;

    private:
        uint32      m_bone_count;
        FrameList   m_frames;
    };
}

#endif // __QGearsAFile_H__
