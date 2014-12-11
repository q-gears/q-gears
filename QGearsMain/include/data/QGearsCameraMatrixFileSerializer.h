/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-09-02 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __QGearsCameraMatrixFileSerializer_H__
#define __QGearsCameraMatrixFileSerializer_H__

#include "common/TypeDefine.h"

#include "QGearsCameraMatrixFile.h"
#include "QGearsSerializer.h"

namespace QGears
{
    class CameraMatrixFileSerializer : public Serializer
    {
    public:
                        CameraMatrixFileSerializer();
        virtual        ~CameraMatrixFileSerializer();

        enum
        {
            CAMERA_MATRIX_ROW_COUNT     = 3
           ,CAMERA_MATRIX_COL_COUNT     = CAMERA_MATRIX_ROW_COUNT
           ,CAMERA_MATRIX_ENTRY_COUNT   = CAMERA_MATRIX_ROW_COUNT * CAMERA_MATRIX_COL_COUNT
           ,TOTAL_DATA_SIZE             = 0x26
        };

        virtual void    importCameraMatrixFile( Ogre::DataStreamPtr &stream, CameraMatrixFile* pDest );

    protected:

    private:
        // http://en.wikipedia.org/wiki/Angle_of_view
    };
}

#endif // __QGearsCameraMatrixFileSerializer_H__
