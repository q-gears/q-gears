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
#ifndef __QGearsMapFileXMLSerializer_H__
#define __QGearsMapFileXMLSerializer_H__

#include "common/TypeDefine.h"
#include "data/QGearsXMLSerializer.h"

#include "QGearsMapFile.h"

namespace QGears
{
    class MapFileXMLSerializer : public XMLSerializer
    {
    public:
        MapFileXMLSerializer();
        virtual        ~MapFileXMLSerializer();
        
        virtual void    importMapFile( Ogre::DataStreamPtr &stream, MapFile *pDest );
        
    protected:
        
    private:
    };
}

#endif // __QGearsMapFileXMLSerializer_H__

