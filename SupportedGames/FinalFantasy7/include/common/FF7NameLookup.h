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
            NameLookup() = default;
            virtual ~NameLookup() = default;

            static const String& animation(const String &key)
            {
                return lookup(key, ms_animations);
            }

            static const String& model(const String &key)
            {
                return lookup(key, ms_models);
            }

        protected:
            typedef std::map<const String, const String>    LookupMap;

            static LookupMap createAnimations()
            {
                LookupMap lookup;
                lookup.insert(LookupMap::value_type("acfe", "Idle"));
                lookup.insert(LookupMap::value_type("aaff", "Walk"));
                lookup.insert(LookupMap::value_type("aaga", "Run"));
                lookup.insert(LookupMap::value_type("bvjf", "JumpFromTrain"));

                // barret
                lookup.insert(LookupMap::value_type("adcb", "Idle"));
                lookup.insert(LookupMap::value_type("adcc", "Walk"));
                lookup.insert(LookupMap::value_type("adcd", "Run"));
                lookup.insert(LookupMap::value_type("bwaa", "Invitation"));

                // sd_red
                lookup.insert(LookupMap::value_type("aeae", "Idle"));
                lookup.insert(LookupMap::value_type("aeaf", "Walk"));
                lookup.insert(LookupMap::value_type("aeba", "Run"));

                return lookup;
            }

            static LookupMap createModels()
            {
                LookupMap lookup;
                lookup.insert(LookupMap::value_type("aaaa", "n_cloud"));
                lookup.insert(LookupMap::value_type("adda", "sd_red"));

                return lookup;
            }

            static const String& lookup(const String &key, const LookupMap &data)
            {
                LookupMap::const_iterator found(data.find(key));
                if (found == data.end()) return key;

                return found->second;
            }

        private:
            static LookupMap  ms_animations;
            static LookupMap  ms_models;
        };
    }
}

#endif // __FF7NameLookup_H__
