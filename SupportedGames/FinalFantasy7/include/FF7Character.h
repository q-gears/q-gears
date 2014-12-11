/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2013-08-13 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __FFVIICharacter_H__
#define __FFVIICharacter_H__

#include "common/TypeDefine.h"

namespace FFVII
{
    class Character
    {
    public:
                    Character();
        virtual    ~Character();

        enum CharacterId
        {
            CLOUD   = 0
           ,TIFA    = 1
           ,AERIS   = 2
           ,BARRET  = 3
           ,RED     = 4
           ,CID     = 5
           ,VINCENT = 6
           ,YUVI    = 7
           ,KETCY   = 8
           ,UNKNOWN = 9
        };

        static CharacterId getIdByName( const QGears::String& name );

    private:
        typedef std::map<QGears::String, CharacterId> ChracterIdLookupMap;

        static          ChracterIdLookupMap createLookupMap();
        static const    ChracterIdLookupMap ms_character_id_lookups;
    };
}

#endif // __FFVIICharacter_H__
