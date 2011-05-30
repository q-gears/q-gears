//////////////////////////////////////////////////////////////
initbattle_load_enemy_from_scene
battle_id = A0;
// A1 = 0;
801B23E0	addiu  sp, sp, $e050 (=-$1fb0)
S4 = battle_id;
S2 = A1;
S0 = S4;
S5 = 801c0000;

if (S4 != 0)
{
    S0 = S4 + 3;
}

S0 = S0 / 4;
A0 = S0;
initbattle_get_id_of_scene_file_with_battle_id;
S1 = V0;

// get offset to scene file.
A0 = 7;
func144d8;

// extract scene file
A0 = V0 + S1 * 4;
A1 = 2000;
A2 = 801c0000;
A3 = 0;
func33e34;



V0 = bu[80083184 + S1];
S3 = S0 - V0;

// unknown
A0 = S2;
func145bc;

S3 = w[801c0000 + S3 * 4];



// extract???
A0 = 801c0000 + S3 * 4;
A1 = SP + 110;
func17108;



// id in battle file
S3 = S4 - S0 * 4;



// copy enemy ID
A0 = 8016360C;
A1 = SP + 110;
A2 = 8;
func14a00;

// copy battle setup 1
A0 = 8016360C + 8;
A1 = SP + 110 + S3 * 14 + 8;
A2 = 14;
func14a00;

// copy battle setup 2
A0 = 8016360C + 1C;
A1 = SP + 110 + S3 * 30 + 58;
A2 = 30;
func14a00;

// copy battle formation
A0 = 8016360C + 4C;
A1 = SP + 110 + S3 * 60 + 118;
A2 = 60;
func14a00;

// copy enemy data
A0 = 800f5f44;
A1 = SP + 110 + 298;
A2 = 228;
func14a00;

// copy attack data
A0 = 800f616c;
A1 = SP + 110 + 4c0;
A2 = 380;
func14a00;

// copy attack ID
A0 = 800f5f44 + 5a8;
A1 = SP + 110 + 840;
A2 = 40;
func14a00;

// copy attack names
A0 = 800f5f44 + 5e8;
A1 = SP + 110 + 880;
A2 = 400;
func14a00;

// copy FF padding
A0 = 800f6ba4;
A1 = SP + 110 + c80;
A2 = 200;
func14a00;

// copy enemy AI
A0 = 800f6da4;
A1 = SP + 110 + e80;
A2 = 1000;
func14a00;



// some camera modification acording to previous battle result some flag and camera
if ((hu[8016376a] & 4) && (hu[8016360C + 8 + 10] & 10) && (bu[8016360C + 8 + 12] == 0))
{
    [8016360c + 8 + 12] = b(1);
}



V0 = bu[8016360c + 8 + 12];
//00 01 02 03 04 03 03 03 05
[800f7dc8] = h(bu[801b0044 + V0]);



// previous battle result modification
V1 = hu[8016376a];
// if we must continue arena battle
if (V1 & 40)
{
    V0 = hu[8016360c + 8 + 10];
    V0 = V0 | 4;
    [8016360c + 8 + 10] = h(V0);

    [80163614] = h(25); // set battle location id to 0x25

    get_random_byte_from_table;

    [8016360c + 8 + 13] = b((V0 & 3) + 60);
    [8016360c + 8 + 04] = h(1);

    // boost enemy
    S3 = 0;
    loop1b2630:	; 801B2630
        // enemy hp doubled
        [800f5f44 + S3 * b8 + a4] = w(w[800f5f44 + S3 * b8 + a4] * 2);

        A0 = bu[800f5f44 + S3 * b8 + 24];
        initbattle_calculate_stat_add25_percent;
        [800f5f44 + S3 * B8 + 24] = b(V0);

        A0 = bu[800f5f44 + S3 * b8 + 26];
        initbattle_calculate_stat_add25_percent;
        [800f5f44 + S3 * b8 + 26] = b(V0);

        S3 = S3 + 1;
        V0 = S3 < 3;
    801B2664	bne    v0, zero, loop1b2630 [$801b2630]
}
else if (V1 & 08)
{
    V0 = hu[8016360c + 8 + 10];
    V0 = V0 & fffb;
    [8016360c + 8 + 10] = h(V0);
}



V0 = hu[8016360c + 8 + 10];
if ((V0 & 4) == 0)
{
    [8016376a] = h(hu[8016376a] | 8);
}



[800f7db2] = h(hu[8016360c + 8 + 4]);



V1 = hu[800f7dc8];
if (V1 == 1 || V1 == 3)
{
    [800f7db2] = h(1);
}

[800f7db6] = h(hu[800f7db2]);
///////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
// initbattle_get_id_of_scene_file_with_battle_id
V1 = 1;

loop1b273c:	; 801B273C
    V0 = bu[80082268 + f1c + V1]; // id of file
    if (A0 < V0)
    {
        break;
    }

    V1 = V1 + 1;
    V0 = V1 < 40;
801B2760	bne    v0, zero, loop1b273c [$801b273c]

return V1 - 1;
//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
// initbattle_calculate_stat_add25_percent
A0 = A0 + A0 * 25 / 100;

if (A0 >= 100)
{
    A0 = ff;
}

return A0;
//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////
// battle_init_unit_datas
[800f83be] = h(0);



// clear number of enemies with same id
V0 = 800f7dd6;
T3 = 2;
loop1b1e48:	; 801B1E48
    [V0] = b(0);
    T3 = T3 - 1;
    V0 = V0 - 1;
801B1E50	bgez   t3, loop1b1e48 [$801b1e48]



// init enemy 0x80 structure with zeros
T3 = 0;
V1 = 800f89f0;
loop1b1e64:	; 801B1E64
    A2 = 1F;
    V0 = V1 + 7C;

    loop1b1e6c:	; 801B1E6C
        [V0] = w(0);

        A2 = A2 - 1;
        V0 = V0 - 4;
    801B1E74	bgez   a2, loop1b1e6c [$801b1e6c]

    T3 = T3 + 1;
    V1 = V1 + 80;
    V0 = T3 < 6;
801B1E84	bne    v0, zero, loop1b1e64 [$801b1e64]



T3 = 0;
L1b1ecc:	; 801B1ECC
    [800f8580 + T3 * 68 + 00] = w(0);
    [800f8580 + T3 * 68 + 04] = w(0);
    [800f8580 + T3 * 68 + 08] = b(ff);
    [800f8580 + T3 * 68 + 24] = h(ffff);
    [800f8580 + T3 * 68 + 4F] = b(ff);

    [800f692c + 208 + 20 + T3 * 8] = b(ff);



    // init 10-1f with zeros
    A2 = F;
    V1 = 800f5cc8 + T3 * 44 + 1F;
    loop1b1f18:	; 801B1F18
        [V1] = b(0);

        A2 = A2 - 1;
        V1 = V1 - 1;
    801B1F20	bgez   a2, loop1b1f18 [$801b1f18]



    // init 20-27 with zeros
    A2 = 7;
    V0 = 800f5cc8 + T3 * 44 + 27;
    loop1b1f30:	; 801B1F30
        [V0] = b(0);

        A2 = A2 - 1;
        V0 = V0 - 1;
    801B1F38	bgez   a2, loop1b1f30 [$801b1f30]



    A0 = hu[8016360c + 4c + T3 * 10];
    // if enemy exist
    if (A0 != -1)
    {
        [800f8580 + T3 * 68 + 24] = h(A0);



        index = 0;
        loop1b1f64:	; 801B1F64
            V0 = h[8016360c + index * 2];
            if (V0 == A0)
            {
                break;
            }

            index = index + 1;
            V0 = index < 3;
        801B1F7C	bne    v0, zero, loop1b1f64 [$801b1f64]



        // increment enemy index
        V0 = bu[800f7dd4 + index];
        V0 = V0 + 1;
        [800f7dd4 + index] = b(V0);



        [8016360c + 4c + T3 * 10 + 00] = h(index); // store index here instead of real enemy id

        [800f8580 + T3 * 68 + 00] = w(0);
        [800f8580 + T3 * 68 + 08] = b(index);
        [800f8580 + T3 * 68 + 09] = b(bu[800f5f44 + index * b8 + 20]);
        [800f8580 + T3 * 68 + 0d] = b(bu[800f5f44 + index * b8 + 24]);
        [800f8580 + T3 * 68 + 0e] = b(bu[800f5f44 + index * b8 + 26]);
        [800f8580 + T3 * 68 + 0f] = b(bu[800f5f44 + index * b8 + 23]);
        [800f8580 + T3 * 68 + 10] = b(0);
        [800f8580 + T3 * 68 + 11] = b(1);
        [800f8580 + T3 * 68 + 12] = b(bu[800f5f44 + index * b8 + a2]);
        [800f8580 + T3 * 68 + 14] = b(bu[800f5f44 + index * b8 + 21]);
        [800f8580 + T3 * 68 + 15] = b(bu[800f5f44 + index * b8 + 22]);
        [800f8580 + T3 * 68 + 20] = h(bu[800f5f44 + index * b8 + 25] * 2);
        [800f8580 + T3 * 68 + 22] = h(bu[800f5f44 + index * b8 + 27] * 2);
        [800f8580 + T3 * 68 + 28] = h(hu[800f5f44 + index * b8 + 9c]);
        [800f8580 + T3 * 68 + 2a] = h(hu[800f5f44 + index * b8 + 9c]);
        [800f8580 + T3 * 68 + 2c] = w(w[800f5f44 + index * b8 + a4]);
        [800f8580 + T3 * 68 + 30] = w(w[800f5f44 + index * b8 + a4]);
        [800f8580 + T3 * 68 + 44] = w(0);
        [800f8580 + T3 * 68 + 4c] = b(1);
        [800f8580 + T3 * 68 + 4e] = b(hu[8016360C + 8 + 14 + 30 + T3 * 10 + 8]);
        [800f8580 + T3 * 68 + 50] = h(0);
        [800f8580 + T3 * 68 + 52] = h(ffff);
        [800f8580 + T3 * 68 + 56] = b(2);
        [800f8580 + T3 * 68 + 58] = w(w[800f5f44 + index * b8 + ac]);
        [800f8580 + T3 * 68 + 5c] = w(w[800f5f44 + index * b8 + a8]);

        V0 = w[8016360c + 8 + 14 + 30 + T3 * 10 + c];
        V0 = V0 & 0000001f;
        [800f8580 + T3 * 68 + 04] = w(V0);



        [800f5cc8 + T3 * 44 + 38] = w(800f5f44 + index * b8);
        [800f5cc8 + T3 * 44 + 0c] = b(ff);
        [800f5cc8 + T3 * 44 + 0d] = b(ff);
        [800f5cc8 + T3 * 44 + 0f] = b(ff);

        // set status innumities
        V0 = w[800f5f44 + index * b8 + b0];
        V0 = 0 nor V0;
        [800f5cc8 + T3 * 44 + 34] = w(V0);



        // add bits for inited enemy
        V1 = hu[800f83a4 + 1a];
        V0 = 1 << (T3 + 4);
        V1 = V1 | V0;
        [800f83a4 + 1a] = h(V1);



        // init formation number
        [800f8580 + T3 * 68 + 0c] = b(0);
        if (T3 > 0)
        {
            A0 = hu[800f8580 + T3 * 68 + 24]; // real enemy id
            A2 = 0;
            loop1b211c:	; 801B211C
                V0 = hu[800f83e0 + 4 * 68 + V1 + 24];
                if (V0 == A0)
                {
                    V0 = bu[800f8580 + T3 * 68 + 0c];
                    V0 = V0 + 1;
                    [800f8580 + T3 * 68 + 0c] = b(V0);
                }

                A2 = A2 + 1;
                V1 = V1 + 68;

                V0 = A2 < T3;
            801B214C	bne    v0, zero, loop1b211c [$801b211c]
        }



        // add manipulate
        A2 = 0;
        // go through all manipulate
        loop1b2168:	; 801B2168
            [80166f78 + T3 * 60 + A2 * 6 + 00] = b(ff);
            [80166f78 + T3 * 60 + A2 * 6 + 01] = b(0);
            [80166f78 + T3 * 60 + A2 * 6 + 02] = b(0);
            [80166f78 + T3 * 60 + A2 * 6 + 03] = b(3);

            V1 = hu[800f5f44 + index * b8 + 94 + A2 * 2]; // manipulate attacks id
            if (V1 != ffff)
            {
                A1 = 0;

                // search for this attack
                loop1b219c:	; 801B219C
                    V0 = hu[800f64ec + A1 * 2];
                    if (V0 == V1)
                    {
                        V0 = bu[800f616c + A1 * 1c + c]; // target from attack data
                        if (V0 != 0)
                        {
                            V0 = V0 XOR 2;
                        }

                        [80166F78 + T3 * 60 + A2 * 6 + 00] = b(A1);
                        [80166F78 + T3 * 60 + A2 * 6 + 02] = b(V0);
                        [80166F78 + T3 * 60 + A2 * 6 + 03] = b(0);
                        break;
                    }

                    A1 = A1 + 1;
                    V0 = A1 < 20;
                801B21E4	bne    v0, zero, loop1b219c [$801b219c]
            }

            A2 = A2 + 1;
            V0 = A2 < 3;
        801B21F8	bne    v0, zero, loop1b2168 [$801b2168]



        A2 = 3;
        loop1b2220:	; 801B2220
            V0 = 80166f78 + T3 * 60 + A2 * 6;
            [V0 + 00] = b(FF);
            [V0 + 01] = b(0);
            [V0 + 02] = b(0);
            [V0 + 03] = b(3);

            A2 = A2 + 1;
            V0 = A2 < 10;
        801B223C	bne    v0, zero, loop1b2220 [$801b2220]



        [800f5cc8 + T3 * 44 + 29] = b(0);
    }

    T3 = T3 + 1;
    V0 = T3 < 6;
801B2268	bne    v0, zero, L1b1ecc [$801b1ecc]



T3 = 0;
loop1b2280:	; 801B2280
    V0 = h[8016360c + 8 + 14 + 30 + T3 * 10]; // enemy index
    V0 = bu[800f7dd4 + V0];
    if (V0 >= 2)
    {
        [800f5cc8 + T3 * 44 + f] = b(bu[800f83e0 + 4 * 68 + T3 * 68 + c]);
    }

    T3 = T3 + 1;
    V0 = T3 < 6;
801B22D0	bne    v0, zero, loop1b2280 [$801b2280]

return;
//////////////////////////////////////////////////////////////