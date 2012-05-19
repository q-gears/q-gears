﻿0x0A SPTYE 800cf200
0x0B GTPYE 800cf2bc
0x39 GOLDu 800d3b88
0x3A GOLDd 800d3c18
0x3C HMPMAX1 800d368c
0x3D HMPMAX2 800d368c
0x3E MHMMX 800d3548
0x3F HMPMAX3 800d368c
0x45 MPu 800d3728
0x47 MPd 800d3840
0x4D HPu 800d3958
0x4F HPd 800d3a70

0x58 STITM 800d1f20
0x59 DLITM 800d1fdc
0x5A CKITM 800d2098
0x5B SMTRA 800d298c
0x5C DMTRA 800d2a70
0x5D CMTRA 800d2b60

0x74 GETPC 800d2f3c

0xCB IFPRTYQ 800cf718
0xCC IFMEMBQ 800cf874



////////////////////////////////
// 0x3B CHGLD
current_entity        = bu[800722c4];
script_pointer_offset = 800831fc + current_entity * 2;

system_get_party_gil;
gil = V0;
A0 = 1;
A1 = 2;
A2 = (gil << 10) >> 10;
store_memory_block_two_bytes;

A0 = 2;
A1 = 3;
A2 = gil >> 10;
store_memory_block_two_bytes;

[script_pointer_offset] = h(hu[script_pointer_offset] + 4);
////////////////////////////////



////////////////////////////////
// 0xC8 PRTYP
V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];
character_id = bu[V0 + V1 + 1];



// if character already in party
A0 = 0;
loopceeac:	; 800CEEAC
    V0 = bu[8009c6e4 + 0cad + A0]; // party info in savemap
    if (V0 == character_id)
    {
        V1 = bu[800722c4];
        [800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

        field_set_1st_party_character_as_manual_model;

        field_copy_party_to_battle_party;

        return 0;
    }

    A0 = A0 + 1;
    V0 = A0 < 3;
800CEEFC	bne    v0, zero, loopceeac [$800ceeac]



// if not in party
A0 = 0;
loopcef14:	; 800CEF14
    V0 = bu[8009c6e4 + 0cad + A0]; // party info in savemap

    if (V0 == ff)
    {
        [8009c6e4 + 0cad + A0] = b(character_id);

        if (character_id != ff)
        {
            V1 = hu[8009c6e4 + +10a6];
            V0 = 1 << character_id;
            V1 = V1 | V0;
            [8009c6e4 + +10a6] = h(V1);
        }

        V1 = bu[800722c4];
        [800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

        field_set_1st_party_character_as_manual_model;

        field_copy_party_to_battle_party;

        return 0;
    }

    A0 = A0 + 1;
    V0 = A0 < 3;
800CEF70	bne    v0, zero, loopcef14 [$800cef14]



// else add in last slot
[8009c6e4 + 0cad + 2] = b(character_id);
if (character_id != ff)
{
    V1 = hu[8009c6e4 + +10a6];
    V0 = 1 << character_id;
    V1 = V1 | V0;
    [8009c6e4 + +10a6] = h(V1);
}

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

A0 = A0;
field_set_1st_party_character_as_manual_model;

A0 = 1;
field_copy_party_to_battle_party;

return 0;
////////////////////////////////



////////////////////////////////
// 0xC9 PRTYM
V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];
character_id = bu[V0 + V1 + 1];

i = 0;
loopcf098:	; 800CF098
    V0 = bu[8009d391 + i];
    if (V0 == character_id)
    {
        [8009d391 + i] = b(ff);

        field_copy_party_to_battle_party;

        field_set_1st_party_character_as_manual_model;

        V1 = bu[800722c4];
        [800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);
        return 0;
    }

    i = i + 1
    V0 = i < 3;
800CF0EC	bne    v0, zero, loopcf098 [$800cf098]

field_copy_party_to_battle_party;
field_set_1st_party_character_as_manual_model;

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCA PRTYE
A0 = 0;
loopcf178:	; 800CF178
    V0 = bu[800722c4];
    V1 = hu[800831fc + V0 * 2];
    V0 = w[8009c6dc];
    [SP + 10 + A0] = b(bu[V0 + V1 + A0 + 1]);

    A0 = A0 + 1;
    V0 = A0 < 3;
800CF1B4	bne    v0, zero, loopcf178 [$800cf178]

A0 = SP + 10;
funccf368;

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 4);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCD MMBud
V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];
A2 = bu[V0 + V1 + 2];
V1 = bu[V0 + V1 + 1];

if (V1 != 0)
{
    A0 = hu[8009c6e4 + 10a6];
    V1 = 1 << A2;
    A0 = A0 | V1;
    [8009c6e4 + 10a6] = h(A0);
}
else
{
    V1 = hu[8009c6e4 + 10a6];
    V0 = 1 << A2;
    V0 = 0 NOR V0;
    V1 = V1 & V0;
    [8009c6e4 + 10a6] = h(V1);

    V1 = 0;
    loopcfa6c:	; 800CFA6C
        V0 = bu[8009d391 + V1];
        if (V0 == A2)
        {
            [8009d391 + V1] = b(ff);
        }

        V1 = V1 + 1;
        V0 = V1 < 3;
    800CFAAC	bne    v0, zero, loopcfa6c [$800cfa6c]
}

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 3);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCE MMBLK
A0 = bu[800722c4];
V1 = hu[800831fc + A0 * 2];
V0 = w[8009c6dc];
A1 = bu[V0 + V1 + 1];

V0 = hu[8009c6e4 + 10a4];
V1 = 1 << A1;
V0 = V0 | V1;
[8009c6e4 + 10a4] = h(V0);

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCF MMBUK
A0 = bu[800722c4];
V1 = hu[800831fc + A0 * 2];
V0 = w[8009c6dc];
A1 = bu[V0 + V1 + 1];

V0 = hu[8009c6e4 + 10a4];
V1 = 1 << A1;
V0 = 0 NOR V1;
V1 = V1 & V0;
[8009c6e4 + 10a4] = h(V1);

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

return 0;
////////////////////////////////








////////////////////////////////
// field_set_1st_party_character_as_manual_model
V0 = bu[8009c6e4 + 0cad];
if (V0 != ff) // if character exist
{
    A0 = bu[8009ad30 + V0];
    if (A0 != ff) // if entity exist
    {
        V0 = bu[8007eb98 + A0];
        if (V1 != ff) // if model exist
        {
            V1 = w[8009c6e0];
            V0 = bu[8007eb98 + A0];
            [V1 + 2a] = h(V0); // manual model id
        }
    }
}
////////////////////////////////



////////////////////////////////
// field_copy_party_to_battle_party
A0 = 8009c6e4 + 04f8; // party used in battle
A1 = 8009c6e4 + 0cad; // party
A2 = SP + 10; // if something in A1 which is not in A0
A3 = SP + 18; // if something in A0 which is not in A1
funccf4cc;

// remove characters from battle party if they removed from party
A0 = 8009c6e4 + 04f8;
A1 = SP + 18;
funccf66c;

// add missing characters
A0 = 8009c6e4 + 04f8;
A1 = SP + 10;
funccf6c0;

[80071e34] = b(1);
////////////////////////////////



////////////////////////////////
// funccf4cc
i = 0;
loopcf4dc:	; 800CF4DC
    [A2 + i] = b(ff);
    [A3 + i] = b(ff);

    i = i + 1;
    V0 = i < 3;
800CF4EC	bne    v0, zero, loopcf4dc [$800cf4dc]



i = 0;
loopcf500:	; 800CF500
    T2 = bu[A1 + i];

    V1 = 0;
    loopcf508:	; 800CF508
        V0 = bu[A0 + V1];

        if (T2 == V0)
        {
            break;
        }

        V1 = V1 + 1;
        V0 = V1 < 3;
    800CF520	bne    v0, zero, loopcf508 [$800cf508]

    if (V1 == 3)
    {
        [A2] = b(bu[A1 + i])
        A2 = A2 + 1;
    }

    i = i + 1;
    V0 = i < 3;
800CF540	bne    v0, zero, loopcf500 [$800cf500]



i = 0;
loopcf54c:	; 800CF54C
    T0 = bu[A0 + i];

    V1 = 0;
    loopcf558:	; 800CF558
        V0 = bu[A1 + V1];

        if (T0 == V0)
        {
            break;
        }

        V1 = V1 + 1;
        V0 = V1 < 3;
    800CF570	bne    v0, zero, loopcf558 [$800cf558]

    if (V1 == 3)
    {
        [A3] = b(bu[A0 + i]);
        A3 = A3 + 1;
    }

    V0 = i < 3;
800CF590	bne    v0, zero, loopcf54c [$800cf54c]
////////////////////////////////



////////////////////////////////
// funccf66c
//A0 = 8009c6e4 + 04f8; // party used in battle
//A1 = SP + 18; // if something in A0 which is not in A1

i = 0;
loopcf674:	; 800CF674
    j = 0;
    loopcf680:	; 800CF680
        if (bu[A1 + i] == bu[A0 + j])
        {
            [A0 + j] = b(ff);
        }

        j = j + 1;
        V0 = j < 3;
    800CF6A0	bne    v0, zero, loopcf680 [$800cf680]

    i = i + 1;
    V0 = i < 3;
800CF6B0	bne    v0, zero, loopcf674 [$800cf674]
////////////////////////////////



////////////////////////////////
// funccf6c0
A0 = 8009c6e4 + 04f8; // party used in battle
A1 = SP + 10; // if something in party which is not in battle party

i = 0;
loopcf6c8:	; 800CF6C8
    j = 0;
    loopcf6d4:	; 800CF6D4
        if (bu[A0 + j] == ff)
        {
            [A0 + j] = b(b[A1 + i]);

            break;
        }

        j = j + 1;
        V0 = j < 3;
    800CF6F8	bne    v0, zero, loopcf6d4 [$800cf6d4]

    i = i + 1;
    V0 = i < 3;
800CF708	bne    v0, zero, loopcf6c8 [$800cf6c8]
////////////////////////////////



////////////////////////////////
// funccf368
i = 0;
loopcf37c:	; 800CF37C
    V0 = bu[A0 + i];
    if (V0 != ff)
    {
        j = 0;
        loopcf39c:	; 800CF39C
            if (bu[8009c6e4 + 0cad + j] == bu[A0 + i])
            {
                [8009c6e4 + 0cad + j] = b(ff);
            }

            j = j + 1;
            V0 = j < 3;
        800CF3BC	bne    v0, zero, loopcf39c [$800cf39c]
    }

    i = i + 1;
    V0 = i < 3;
800CF3CC	bne    v0, zero, loopcf37c [$800cf37c]



i = 0;
loopcf3e0:	; 800CF3E0
    V0 = bu[8009c6e4 + 0cad + i];
    if (V0 != ff)
    {
        j = 0;
        loopcf3f8:	; 800CF3F8
            V0 = bu[A0 + j];
            if (V0 == ff)
            {
                [A0 + j] = b(bu[8009c6e4 + 0cad + i]);
                break;
            }

            j = j + 1;
            V0 = j < 3;
        800CF420	bne    v0, zero, loopcf3f8 [$800cf3f8]
    }

    i = i + 1;
    V0 = i < 3;
800CF430	bne    v0, zero, loopcf3e0 [$800cf3e0]



i = 0;
loopcf450:	; 800CF450
    V0 = bu[A0 + i];
    if (V0 == fe)
    {
        [A0 + i] = b(ff);
    }

    [8009d391 + i] = b(bu[A0 + i]);

    V0 = bu[A0 + i];
    if (V0 != ff)
    {
        V0 = bu[A0 + i];
        V1 = hu[8009c6e4 + 10a6];
        V0 = 1 << V0;
        V1 = V1 | V0;
        [8009c6e4 + 10a6] = h(V1);
    }

    i = i + 1;
    V0 = i < 3;
800CF4A4	bne    v0, zero, loopcf450 [$800cf450]



field_copy_party_to_battle_party;
field_set_1st_party_character_as_manual_model;
////////////////////////////////