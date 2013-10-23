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
#include "common/FF7NameLookup.h"

namespace QGears
{
    namespace FF7
    {
        //----------------------------------------------------------------------
        const NameLookup::LookupMap NameLookup::ms_animations   ( NameLookup::createAnimations() );

        //----------------------------------------------------------------------
        NameLookup::NameLookup()
        {
        }

        //----------------------------------------------------------------------
        NameLookup::~NameLookup()
        {
        }

        //----------------------------------------------------------------------
        NameLookup::LookupMap
        NameLookup::createAnimations()
        {
            LookupMap lookup;
            lookup.insert( LookupMap::value_type( "acfe", "Idle" ) );
            lookup.insert( LookupMap::value_type( "aaff", "Walk" ) );
            lookup.insert( LookupMap::value_type( "aaga", "Run" ) );
            lookup.insert( LookupMap::value_type( "bvjf", "JumpFromTrain" ) );

            // barret
            lookup.insert( LookupMap::value_type( "adcb", "Idle" ) );
            lookup.insert( LookupMap::value_type( "adcc", "Walk" ) );
            lookup.insert( LookupMap::value_type( "adcd", "Run" ) );
            lookup.insert( LookupMap::value_type( "bwaa", "Invitation" ) );

            return lookup;
        }

        //----------------------------------------------------------------------
        const String&
        NameLookup::lookup( const String &key, const NameLookup::LookupMap &data )
        {
            LookupMap::const_iterator found( data.find( key ) );
            if( found == data.end() ) return key;

            return found->second;
        }

        //----------------------------------------------------------------------
        const String&
        NameLookup::animation( const String &key )
        {
            return lookup( key, ms_animations );
        }

        //----------------------------------------------------------------------
    }
}
