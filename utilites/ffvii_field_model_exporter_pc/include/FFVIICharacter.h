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
