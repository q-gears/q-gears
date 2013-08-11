#include "FFVIICharacter.h"

namespace FFVII
{

    //-------------------------------------------------------------------------
    Character::Character()
    {

    }

    //-------------------------------------------------------------------------
    Character::~Character()
    {

    }

    //-------------------------------------------------------------------------
    Character::ChracterIdLookupMap
    Character::createLookupMap()
    {
        ChracterIdLookupMap lookup;
        lookup["AAAA"]      = CLOUD;
        lookup["n_cloud"]   = CLOUD;
        lookup["AAGB"]      = TIFA;
        lookup["n_tifa"]    = TIFA;
        lookup["AUFF"]      = AERIS;
        lookup["CAHC"]      = AERIS;
        lookup["n_erith"]   = AERIS;
        lookup["earithf"]   = AERIS;
        lookup["ACGD"]      = BARRET;
        lookup["ballet"]    = BARRET;
        lookup["ADDA"]      = RED;
        lookup["red"]       = RED;
        lookup["ABDA"]      = CID;
        lookup["cid"]       = CID;
        lookup["AEHD"]      = VINCENT;
        lookup["vincent"]   = VINCENT;
        lookup["ABJB"]      = YUVI;
        lookup["yufi"]      = YUVI;
        lookup["AEBC"]      = KETCY;
        lookup["ketcy"]     = KETCY;
        return lookup;
    }

    //-------------------------------------------------------------------------
    const Character::ChracterIdLookupMap
    Character::ms_character_id_lookups( Character::createLookupMap() );

    //-------------------------------------------------------------------------
    Character::CharacterId
    Character::getIdByName( const QGears::String& name )
    {
        ChracterIdLookupMap::const_iterator entry;
        entry = ms_character_id_lookups.find( name );
        if( entry != ms_character_id_lookups.end() )
        {
            return entry->second;
        }
        return UNKNOWN;
    }
    //-------------------------------------------------------------------------
}
