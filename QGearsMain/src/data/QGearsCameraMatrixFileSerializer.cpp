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
#include "data/QGearsCameraMatrixFileSerializer.h"

#include <OgreLogManager.h>
#include <OgreException.h>

namespace QGears
{
    //---------------------------------------------------------------------
    CameraMatrixFileSerializer::CameraMatrixFileSerializer() :
        Serializer()
    {
    }

    //---------------------------------------------------------------------
    CameraMatrixFileSerializer::~CameraMatrixFileSerializer()
    {
    }

    //---------------------------------------------------------------------
    void
    CameraMatrixFileSerializer::importCameraMatrixFile( Ogre::DataStreamPtr &stream, CameraMatrixFile* pDest )
    {
        // Read matrix
        sint16 matrix_sint16[CAMERA_MATRIX_ROW_COUNT][CAMERA_MATRIX_COL_COUNT];
        readInt16(stream, matrix_sint16[0][0]);
        readInt16(stream, matrix_sint16[1][0]);
        readInt16(stream, matrix_sint16[2][0]);
        readInt16(stream, matrix_sint16[0][1]);
        readInt16(stream, matrix_sint16[1][1]);
        readInt16(stream, matrix_sint16[2][1]);
        readInt16(stream, matrix_sint16[0][2]);
        readInt16(stream, matrix_sint16[1][2]);
        readInt16(stream, matrix_sint16[2][2]);
        stream->skip( 2 ); // unused
    
        // Array to matrix
        Ogre::Matrix3 camera_matrix;
        camera_matrix[0][0] = static_cast<float>(matrix_sint16[0][0]) / 4096.0f;
        camera_matrix[1][0] = static_cast<float>(matrix_sint16[1][0]) / 4096.0f;
        camera_matrix[2][0] = static_cast<float>(matrix_sint16[2][0]) / 4096.0f;
        camera_matrix[0][1] = static_cast<float>(matrix_sint16[0][1]) / 4096.0f;
        camera_matrix[1][1] = static_cast<float>(matrix_sint16[1][1]) / 4096.0f;
        camera_matrix[2][1] = static_cast<float>(matrix_sint16[2][1]) / 4096.0f;
        camera_matrix[0][2] = static_cast<float>(matrix_sint16[0][2]) / 4096.0f;
        camera_matrix[1][2] = static_cast<float>(matrix_sint16[1][2]) / 4096.0f;
        camera_matrix[2][2] = static_cast<float>(matrix_sint16[2][2]) / 4096.0f;

        // Read POS
        sint32 pos[CAMERA_MATRIX_ROW_COUNT];
        readInts(stream, reinterpret_cast<uint32*>(pos), CAMERA_MATRIX_ROW_COUNT);

        // Array to vector
        Ogre::Vector3 position;
        for (int i = 0; i < 3; i++)
        {
            position[i] = -Ogre::Real(pos[i]);
        }

        Ogre::Quaternion orientation;
        orientation.FromRotationMatrix(camera_matrix);
        position = orientation * (position / 128.0f);

        // Matrix fix up
        camera_matrix[0][0] = camera_matrix[0][0];
        camera_matrix[1][0] = camera_matrix[1][0];
        camera_matrix[2][0] = camera_matrix[2][0];
        camera_matrix[0][1] = -camera_matrix[0][1];
        camera_matrix[1][1] = -camera_matrix[1][1];
        camera_matrix[2][1] = -camera_matrix[2][1];
        camera_matrix[0][2] = -camera_matrix[0][2];
        camera_matrix[1][2] = -camera_matrix[1][2];
        camera_matrix[2][2] = -camera_matrix[2][2];

        pDest->setMatrix( camera_matrix );
        pDest->setPosition( position );

        Pixel offset;
        readObject( stream, offset );
        pDest->setOffset( offset );

        uint16 focal_length;
        readShort( stream, focal_length );
        pDest->setFocalLength( focal_length );

        size_t count( 1 );
        while( !stream->eof() )
        {
            stream->skip( TOTAL_DATA_SIZE );
            ++count;
        }
        pDest->setCount( count );
    }

    //---------------------------------------------------------------------
}
