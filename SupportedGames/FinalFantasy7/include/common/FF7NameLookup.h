/*
-----------------------------------------------------------------------------
Copyright (c) 15.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

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
#ifndef __FF7NameLookup_H__
#define __FF7NameLookup_H__

#include "common/TypeDefine.h"

namespace QGears
{
    namespace FF7
    {
        class NameLookup
        {
        public:
                        NameLookup();
            virtual    ~NameLookup();

            static const String& animation( const String &key );

        protected:
            typedef std::map<const String, const String>    LookupMap;

            static LookupMap createAnimations();

            static const String& lookup( const String &key, const LookupMap &data );

        private:
            static const LookupMap  ms_animations;
        };
    }
}

#endif // __FF7NameLookup_H__
