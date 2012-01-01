////////////////////////////////
// funca3278
[800f3944] = w(0);
[800f3948] = w(0);
[80163798] = b(ff);
////////////////////////////////



////////////////////////////////
// funca283c
V1 = 0;
A1 = 0;
A0 = 0;

loopa2850:	; 800A2850
    if (V1 == A1)
    {
        [800f38ac + A0] = w(V1);
        A0 = A0 + 4;
    }

    V0 = bu[800a0098 + V1];
    if (V0 == 1f)
    {
        A1 = V1 + 1;
    }

    V1 = V1 + 1;
    V0 = V1 < 6d;
800A2884	bne    v0, zero, loopa2850 [$800a2850]
////////////////////////////////



////////////////////////////////
// funcad480
A1 = 0;
V1 = 0;
A2 = 0;
A0 = 0;

loopad498:	; 800AD498
    if (A1 < 10)
    {
        if (V1 == A2)
        {
            [800f495c + A0] = w(V1);
            A0 = A0 + 4;
            A1 = A1 + 1;
        }

        V0 = bu[800e7bcc + V1];
        if (V0 == 8)
        {
            A2 = V1 + 1;
        }
    }

    V1 = V1 + 1;
    V0 = V1 < 1e;
800AD4DC	bne    v0, zero, loopad498 [$800ad498]
////////////////////////////////



////////////////////////////////
// funca71f4
A0 = 0;
A3 = ff;
A2 = 800f4914;
A1 = 800f4908;

loopa720c:	; 800A720C
    V1 = 7f;
    V0 = A0 << 9;
    V0 = V0 + 1fc;

    loopa7218:	; 800A7218
        [800f4308 + V0] = b(A3);

        V0 = V0 - 4;
        V1 = V1 - 1;
    800A7228	bgez   v1, loopa7218 [$800a7218]

    [A1] = w(0);
    [A2] = w(0);

    A2 = A2 + 4;
    A0 = A0 + 1;
    A1 = A1 + 4;
    V0 = A0 < 3;
800A7244	bne    v0, zero, loopa720c [$800a720c]
////////////////////////////////



////////////////////////////////
// funca55bc
V1 = 0;
loopa55c4:	; 800A55C4
    [800f3a40 + V1] = h(ffff);
    [800f3a42 + V1] = h(ffff);

    V1 = V1 + 4;
    V0 = V1 < 40;
800A55E4	bne    v0, zero, loopa55c4 [$800a55c4]
////////////////////////////////



////////////////////////////////
// initbattle_init_player
// init player unit
T4 = 800f5bb8;
S5 = 800f5efc;
structure_44 = 800f5bb8;

total_dexterity = w(0);
number_of_party = w(0);

[800f83a4 + 18] = h(0);



party_id = 0;
L1b0928:	; 801B0928
    FP = bu[8009cbdc + party_id]; // character id in party slot

    [801636b8 + party_id * 10] = b(-1);

    ui_structure = 800f5e60 + party_id * 34;
    structure_440 = 8009d84c + party_id * 440;
    structure_68 = 800f83e0 + party_id * 68;

    if (FP != ff)
    {
        T2 = 0;
        T3 = party_id * 10;
        T4 = party_id * 44;
        T1 = 0;

        L1b09a8:	; 801B09A8
            savemap_player = 8009c738 + T1; // player records in savemap



            V0 = hu[8016376A]; // previous battle result
            if (V0 & 0040)
            {
                A3 = 80167938;
                A2 = savemap_player;
                T0 = savemap_player + 80;

                loop1b09d8:	; 801B09D8
                    [A3 + 0] = w(w[A2 + 0]);
                    [A3 + 4] = w(w[A2 + 4]);
                    [A3 + 8] = w(w[A2 + 8]);
                    [A3 + c] = w(w[A2 + c]);

                    A2 = A2 + 10;
                    A3 = A3 + 10;
                801B09FC	bne    a2, t0, loop1b09d8 [$801b09d8]

                [A3] = w(w[A2]);
            }



            // init player data for this player
            V0 = bu[savemap_player];
            if (V0 == FP)
            {
                [structure_44 + party_id * 44 + 0c] = b(FF);
                [structure_44 + party_id * 44 + 0f] = b(FF);
                [structure_44 + party_id * 44 + 29] = b(1);

                [801636b8 + T3] = b(FP);

                [structure_68 + 04] = w(00000008);
                [structure_68 + 08] = b(FP); // enemy index
                [structure_68 + 09] = b(bu[savemap_player + 1]); // set level
                [structure_68 + 0c] = b(FP + 10); // formation id
                [structure_68 + 11] = b(5);
                [structure_68 + 16] = b(0);
                [structure_68 + 56] = b(8);

                [ui_structure + 0] = w(savemap_player);



                // add bits for player units
                T4 = party_id;
                V0 = hu[800f83bc];
                V1 = 1 << T4;
                V0 = V0 | V1;
                [800f83bc] = h(V0);



                V0 = bu[savemap_player + 20]; // row of character in savemap
                if (V0 & 01 == 0) // if back row
                {
                    V0 = w[structure_68 + 4];
                    V0 = V0 | 00000040;
                    [structure_68 + 4] = w(V0);
                }



                // set hp/mp
                [structure_68 + 2C] = w(h[structure_440 + 10]);
                [structure_68 + 28] = h(h[structure_440 + 14]);
                [ui_structure + 0E] = h(w[structure_68 + 2C]);
                [ui_structure + 0C] = h(h[structure_68 + 28]);



                // copy and init some values
                A0 = structure_440;
                A1 = ui_structure;
                A2 = structure_68;
                func1b18f8;



                [structure_68 + 12] = b(10);
                [structure_68 + 44] = w(0);



                // set sadness/fury flags
                V0 = bu[savemap_player + 1f];
                V0 = V0 & 30;
                [structure_68 + 0] = w(V0);



                // set status protect.
                [structure_44 + party_id * 44 + 34] = w(w[structure_440 + 48]);



                // init attack data from weapon
                [S5 + party_id * 18 + 00] = b(bu[structure_440 + 408 + 0]);
                [S5 + party_id * 18 + 01] = b(bu[structure_440 + 408 + 1]);
                [S5 + party_id * 18 + 02] = b(bu[structure_440 + 408 + 2]);
                [S5 + party_id * 18 + 03] = b(bu[structure_440 + 408 + 8]);
                [S5 + party_id * 18 + 04] = b(bu[structure_440 + 408 + 27]);
                [S5 + party_id * 18 + 05] = b(bu[structure_440 + 408 + 7]);
                [S5 + party_id * 18 + 0e] = h(hu[structure_440 + 408 + 10] | hu[structure_440 + 3c]); // attack element
                [S5 + party_id * 18 + 10] = h(hu[structure_440 + 408 + c]);
                [S5 + party_id * 18 + 12] = h(hu[structure_440 + 408 + 28]);
                [S5 + party_id * 18 + 14] = w(w[structure_440 + 44]); // status attack



                V1 = bu[savemap_player + 1d]; // armor id
                [structure_68 + 0f] = b(bu[80071e44 + V1 * 24 + 4]); // evade
                [structure_68 + 4d] = b(bu[80071e44 + V1 * 24 + 5]); // magic evade



                // add permanent statuses from accessory
                A0 = party_id;
                A1 = bu[savemap_player + 1e]; // equipped accessory
                func1b1598;



                [structure_68 + 50] = h(0);
                [structure_68 + 52] = h(ffff);



                // 
                A0 = 0;
                A1 = S5 + party_id * 18;
                S6 = 1;
                loop1b0be4:	; 801B0BE4
                    V1 = bu[structure_440 + 408 + 24 + A0];
                    V0 = bu[structure_440 + 408 + b];
                    if (V0 & S6)
                    {
                        V1 = V1 | 0100;
                    }

                    [A1 + 8] = h(V1);

                    S6 = S6 + 1;
                    A0 = A0 + 1;
                    A1 = A1 + 2;
                    V0 = A0 < 3;
                801B0C10	bne    v0, zero, loop1b0be4 [$801b0be4]



                // remove long range flag
                V0 = bu[structure_44 + party_id * 44 + 29];
                V0 = V0 & fd;
                [structure_44 + party_id * 44 + 29] = b(V0);

                // if long range materia equipped set weaon to long range
                V0 = bu[structure_440 + 23];
                if (V0 & 04)
                {
                    V0 = bu[S5 + party_id * 18 + 0];
                    V0 = V0 & df;
                    [S5 + party_id * 18 + 0] = b(V0);
                }

                // add long range flag if such weapon is equipped
                if ((bu[S5 + party_id * 18 + 0] & 20) == 0)
                {
                    V0 = bu[structure_44 + party_id * 44 + 29];
                    V0 = V0 | 2;
                    [structure_44 + party_id * 44 + 29] = b(V0);
                }



                [structure_44 + party_id * 44 + 4] = h(0);

                [structure_440 + 18] = h(0);
                [structure_440 + 1a] = h(0);
                [structure_440 + 1c] = h(0);
                [structure_440 + 1e] = h(0);
                [structure_440 + 20] = b(1);
                [structure_440 + 22] = b(0);



                // unset limit
                [ui_structure + 5] = b(ff);



                // if players with limit
                if (FP < 9)
                {
                    limit_level = bu[savemap_player + e] - 1; // current limit level

                    [ui_structure + 5] = b(limit_level);
                    V0 = bu[savemap_player + f]; // limit bar
                    [ui_structure + 8] = h(V0);
                    [ui_structure + a] = h(V0);
                    [ui_structure + 1c] = w(w[80082268 + FP * 38 + 28 + limit_level * 4]); // HP Divisor

                    [structure_440 + 1a] = h(hu[ui_structure + 8] * 100);
                    [structure_440 + 20] = b(bu[savemap_player + e]);

                    A0 = FP;
                    A1 = hu[savemap_player + 22];
                    A2 = structure_440 + ac;
                    func1b13dc;
                }



                // add activate flag
                V0 = w[structure_68 + 4];
                V0 = V0 | 00000008;
                [structure_68 + 4] = w(V0);



                // if hp == 0 set death
                V1 = w[structure_68 + 2c]; // current hp
                if (V1 == 0)
                {
                    V0 = w[structure_68 + 0];
                    V0 = V0 | 00000001;
                    [structure_68 + 0] = w(V0);
                }



                // change some attack types
                A0 = party_id;
                func1b11bc;



                A0 = party_id;
                funca4ba4;



                // if currently limit break
                V0 = hu[ui_structure + 8];
                if (V0 == ff)
                {
                    A0 = party_id;
                    funca4e80;

                    V0 = hu[800f5bc0 + party_id * 44];
                    V0 = V0 & fffe;
                    [800f5bc0 + party_id * 44] = h(V0);
                }



                // if we have some status write something to 80163798 stack
                V0 = w[structure_68 + 0];
                if (V0 != 0)
                {
                    A0 = party_id;
                    funcb108c;
                }



                A0 = savemap_player;
                func1b1530; // we check enemy skill materia here.
                [ui_structure + 24] = w(V0);
                [ui_structure + 28] = w(V0);



                number_of_party = number_of_party + 1;

                V0 = bu[savemap_player + 6]; // dexterity
                total_dexterity = total_dexterity + V0;

                break;
            }

            T2 = T2 + 1;
            T1 = T1 + 84;
            V0 = T2 < 9;
        801B0E00	bne    v0, zero, L1b09a8 [$801b09a8]
    }

    party_id = party_id + 1;
    V0 = party_id < 3;
801B0E68	bne    v0, zero, L1b0928 [$801b0928]



if (number_of_party != 0)
{
    [800f7da8] = h((total_dexterity - 1 + number_of_party) / number_of_party + 32);
}
////////////////////////////////



////////////////////////////////
// func1b18f8
//                A0 = S0; 0x440
//                A1 = S4; // ui
//                A2 = S1; // 0x68

[A2 + 14] = b(bu[A0 + 06]); // dexterity
[A2 + 15] = b(bu[A0 + 07]); // luck
[A2 + 30] = w(h[A0 + 12]);  // max hp
[A2 + 2a] = h(h[A0 + 16]);  // max mp
[A2 + 0d] = b(hu[A0 + 08]); // attack
[A2 + 0e] = b(hu[A0 + 0c]); // magic
[A2 + 20] = h(hu[A0 + 0a]); // defense
[A2 + 22] = h(hu[A0 + 0e]); // magic defense

V1 = bu[A2 + d];
if (V1 == 0)
{
    [A2 + d] = b(1);
}

[A1 + 12] = h(w[A2 + 30]); // max hp
[A1 + 10] = h(hu[A2 + 2a]); // max mp

V0 = bu[A0 + 23];
if (V0 & 08) // hp<>mp equipped
{
    [A1 + 16] = h(03e7);
    [A1 + 14] = h(270f);
}
else
{
    [A1 + 16] = h(270f);
    [A1 + 14] = h(03e7);
}
////////////////////////////////



////////////////////////////////
// func1b1598
// add permanent statuses from accessory
party_id = A0;
// A1 = equipped accessory
T0 = A1;

V0 = w[800f5e60 + A0 * 34 + 20];
V1 = w[800f83e0 + A0 * 68 + 0]; // current status of player
V0 = 0 NOR V0;
V1 = V1 & V0;
[800f83e0 + A0 * 68 + 0] = w(V1);

V0 = w[800f5e60 + A0 * 34 + 20];
V1 = w[800f5bb8 + A0 * 44 + 34]; // status protect
V0 = 0 NOR V0;
V1 = V1 & V0;
[800f5bb8 + A0 * 44 + 34] = w(V1);

[800f5e60 + A0 * 34 + 20] = w(0);
[800f5bb8 + A0 * 44 + d] = b(ff);

if (T0 != ff)
{
    V0 = bu[80071c24 + T0 * 10 + 5]; // special effect
    V1 = V0 & ff;
    [A0 + d] = b(V0);

    switch (V0)
    {
        case 0: // haste
        {
            [800f83e0 + A0 * 68 + 00] = w(w[800f83e0 + A0 * 68 + 00] | 00000100);
            [800f5bb8 + A0 * 44 + 34] = w(w[800f5bb8 + A0 * 44 + 34] | 00000100);
            [800f5e60 + A0 * 34 + 20] = w(w[800f5e60 + A0 * 34 + 20] | 00000100);
        }
        break;

        case 1: // fury
        {
            [800f83e0 + A0 * 68 + 00] = w(w[800f83e0 + A0 * 68 + 00] | 00800000);
            [800f5bb8 + A0 * 44 + 34] = w(w[800f5bb8 + A0 * 44 + 34] | 00800000);
            [800f5e60 + A0 * 34 + 20] = w(w[800f5e60 + A0 * 34 + 20] | 00800000);
        }
        break;

        case 2: // death sentense
        {
            [800f83e0 + A0 * 68 + 00] = w(w[800f83e0 + A0 * 68 + 00] | 00200000);
            [800f5bb8 + A0 * 44 + 34] = w(w[800f5bb8 + A0 * 44 + 34] | 00200000);
            [800f5bb8 + A0 * 44 + 12] = b(ff);
            [800f5e60 + A0 * 34 + 20] = w(w[800f5e60 + A0 * 34 + 20] | 00200000);
        }
        break;

        case 3: // reflect
        {
            [800f83e0 + A0 * 68 + 00] = w(w[800f83e0 + A0 * 68 + 00] | 00040000);
            [800f5bb8 + A0 * 44 + 34] = w(w[800f5bb8 + A0 * 44 + 34] | 00040000);
            [800f5e60 + A0 * 34 + 20] = w(w[800f5e60 + A0 * 34 + 20] | 00040000);
        }
        break;

        case 6: // barrier + magic barrier
        {
            [800f83e0 + A0 * 68 + 00] = w(w[800f83e0 + A0 * 68 + 00] | 00030000);
            [800f5bb8 + A0 * 44 + 34] = w(w[800f5bb8 + A0 * 44 + 34] | 00030000);
            [800f5e60 + A0 * 34 + 20] = w(w[800f5e60 + A0 * 34 + 20] | 00030000);
        }
        break;
    }
}
////////////////////////////////



////////////////////////////////
// func1b13dc
//                    A0 = FP;
//                    A1 = hu[savemap_player + 22];
//                    A2 = structure_440 + ac;

S7 = A0;
learned_limit = A1;
S6 = A2; // structure_440ac

active_limit = 0;
S3 = S6;
S1 = S6;

S4 = 0;
loop1b1424:	; 801B1424
    S0 = 0;
    V1 = bu[S1 + 0];
    if (V1 != ff)
    {
        loop1b143c:	; 801B143C
            A0 = S7; // party id
            A1 = S0;
            system_get_limit_id;

            V1 = bu[S1 + 0];
            if (V0 == V1)
            {
                break;
            }

            S0 = S0 + 1;
            V0 = S0 < c;
        801B145C	bne    v0, zero, loop1b143c [$801b143c]

        if (S0 == c)
        {
            A0 = 26;
            func155a4
        }
        else
        {
            V0 = learned_limit >> S0;
            if (V0 & 01)
            {
                active_limit = active_limit + 1;
                [S1 + 3] = b(bu[S3 + 14]);
            }
        }
    }

    S3 = S3 + 1c;
    S1 = S1 + 1;
    S4 = S4 + 1;
    V0 = S4 < 3;
801B14A4	bne    v0, zero, loop1b1424 [$801b1424]

[S6 + 7] = b(0);
[S6 + 6] = b(active_limit); // number of activated limit
////////////////////////////////



////////////////////////////////
// system_get_limit_id
if (A0 < 9)
{
    V1 = bu[80082268 + A0 * 38 + 0c + A1] - 80;
}
else
{
    V1 = 7f;
}

return V1;
////////////////////////////////



////////////////////////////////
// func1b11bc
party_id = A0;
T0 = 8009d84c + party_id * 440;
[T0 + 21] = b(1);
A3 = 0;
T1 = ff;
T2 = party_id * 18;
A1 = party_id * 44;
A0 = T0;

loop1b11f8:	; 801B11F8
    V1 = bu[A0 + 4c];

    if (V1 != ff)
    {
        A2 = bu[800707c4 + V1 * 8 + 1]; // default target type
        if (A2 == ff)
        {
            A2 = bu[800f5efc + party_id * 18]; // first byte from weapon info
        }

        // if attack replacers
        if (V1 < 1c && V1 >= 18)
        {
            [A0 + 4c + 4] = b(ff);
        }

        // action 1 5 11 19 single enemy/ally attack
        V1 = bu[A0 + 4c + 1];
        if (V1 == 7)
        {
            // if long ranged
            V0 = bu[800F5BB8 + A1 + 29];
            if (V0 & 2)
            {
                [A0 + 4c + 1] = b(0);
            }

            V0 = bu[A0 + 4c + 4];
            V1 = bu[A0 + 4c + 0];
            if (V0 != 0 && V1 != 19)
            {
                A2 = A2 | 000c;
            }

            // if steal or mug
            if (V1 == 5 || V1 == 11)
            {
                A2 = A2 | 0010;

                V0 = bu[A0 + 4c + 4];
                if (V0 != 0)
                {
                    [A0 + 4c + 1] = b(0);
                }
            }
        }

        V0 = A3 / 4;
        V0 = V0 + 1;
        [T0 + 21] = b(V0);
    }

    [A0 + 4c + 2] = b(A2);
    A3 = A3 + 1;
    A0 = A0 + 6;
    V0 = A3 < 10;
801B12E4	bne    v0, zero, loop1b11f8 [$801b11f8]



T1 = ff;
V1 = T0;
T0 = V1 + 240;
A1 = V1 + 1c0;
A3 = A1;
A2 = V1 + 300;

loop1b1304:	; 801B1304
    A0 = bu[V1 + 108];
    if (A0 != ff)
    {
        if (V1 >= T0)
        {
            A0 = A0 + 48;
        }
        else
        {
            801B1318	slt    v0, v1, a3
            801B1324	bne    v0, zero, L1b133c [$801b133c]

            A0 = A0 + 8;
        }

        if (V1 < A1)
        {
            L1b133c:	; 801B133C
            V0 = bu[800708c4 + A0 * 1c + c]; // attack type
            V0 = V0 & 08;
            if (V0 == 0)
            {
                [V1 + 10a] = b(0);
            }
        }
    }

    V1 = V1 + 8;
    V0 = V1 < A2;
801B136C	bne    v0, zero, loop1b1304 [$801b1304]
////////////////////////////////



////////////////////////////////
// funca4ba4
party_id = A0;

// copy usual attack command
[800f39f0 + party_id * 6 + 0] = w(w[8009d84c + party_id * 440 + 4c + 0]);
[800f39f0 + party_id * 6 + 4] = b(b[8009d84c + party_id * 440 + 4c + 4]);
[800f39f0 + party_id * 6 + 5] = b(b[8009d84c + party_id * 440 + 4c + 5]);

[800f3a04 + party_id * 6 + 0] = w(w[800f39f0 + party_id * 6 + 0]);
[800f3a04 + party_id * 6 + 4] = b(b[800f39f0 + party_id * 6 + 4]);
[800f3a04 + party_id * 6 + 5] = b(b[800f39f0 + party_id * 6 + 5]);

[800f3a04 + party_id * 6 + 0] = b(1);

V0 = nu[800f5bb8 + party_id * 44 + 29];
V0 = V0 & 2; // if long ranged
V0 = V0 < 1; // if not long
V0 = 0 - V0;
V0 = V0 & 7;
[800f3a04 + party_id * 6 + 1] = b(V0); // set 0 if long ranged, 0x07 otherwise
[800f3a04 + party_id * 6 + 2] = b(bu[800f5efc + party_id * 18 + 0]);
////////////////////////////////



////////////////////////////////
// funca4e80
party_id = A0;
V1 = bu[800f5e65 + party_id * 34]; // limit level
if (V1 != ff)
{
    V1 = hu[80163762];
    V0 = 1 << party_id;
    V1 = V1 | V0;
    [80163762] = h(V1);

    [800f5bb8 + party_id * 44 + 8] = h(hu[800f5bb8 + party_id * 44 + 8] | 0001);
    [800f5bb8 + party_id * 44 + e] = b(bu[800f5bb8 + party_id * 44 + e] | 01);
}
////////////////////////////////



////////////////////////////////
// funcb108c
A0 = party_id = A0;
A1 = 5;
A2 = 0;
A3 = 0;
funca31a0;
////////////////////////////////



////////////////////////////////
// func1b1530
savemap_player = S0 = A0;

S1 = 0;
S2 = 0
loop1b1550:	; 801B1550
    A0 = w[savemap_player + 40 + S2 * 4]; // weapon materia
    func1b14e8;

    S1 = S1 | V0;

    A0 = w[savemap_player + 60 + S2 * 4]; // armor materia
    func1b14e8;

    S1 = S1 | V0;

    S2 = S2 + 1;
    V0 = S2 < 8;
801B1574	bne    v0, zero, loop1b1550 [$801b1550]

return S1;
////////////////////////////////



////////////////////////////////
// func1b14e8
A1 = 0;
materia_id = A0 & FF;
if (materia_id != FF)
{
    V0 = bu[800730D0 + materia_id * 14 + 0d]; // materia type from kernel

    V0 = V0 & f;
    if (V0 == 7) // enemy skill materia?
    {
        V1 = A0 >> 8;
        A1 = V1 | 80000000;
    }
}

return A1;
////////////////////////////////



////////////////////////////////
// initbattle_init_item
T0 = 0;
A3 = 0;
T1 = 0;

loop1b1cbc:	; 801B1CBC
    T2 = 0;
    A1 = 0;
    A2 = 801671b8 + T1;
    A0 = hu[8009cbe0 + A3 * 2]; // party item
    if (A0 != ffff)
    {
        V1 = b;
        T2 = A0 >> 9;
        A0 = A0 & 1ff;

        // usual item
        if (A0 < 80)
        {
            V1 = hu[800722cc + A0 * 1c + a]; // item command restriction
            V1 = V1 & b;
            A1 = bu[800722cc + A0 * 1c + c]; // attack target
        }
        // weapon
        else if (A0 < 100)
        {
            V0 = hu[800738a0 + (A0 - 80) * 2c + 2a]; // item command restriction
            V1 = V0 & b;
            A1 = bu[800738a0 + (A0 - 80) * 2c + 00]; // attack target
        }
        // armor
        else if (A0 < 120)
        {
            V0 = hu[80071e44 + (A0 - 100) * 24 + 20];
            V1 = V0 & b;
            A1 = 3;
        }
        // accesory
        else if (A0 < 140)
        {
            V0 = hu[80071c32 + (A0 - 120) * 10];
            V1 = V0 & b;
            A1 = 3;
        }

        T0 = A3 + 1;
    }

    T1 = T1 + 6;
    A3 = A3 + 1;
    V0 = A3 < 140;

    [A2 + 0] = h(A0);
    [A2 + 2] = b(T2);
    [A2 + 3] = b(A1);
    [A2 + 4] = b(V1);
801B1DD4	bne    v0, zero, loop1b1cbc [$801b1cbc]



V0 = T0 + 1;
V1 = V0 >> 1f;
V0 = V0 + V1;
V1 = V0 >> 1;
if (V1 < 3)
{
    V1 = 3;
}

[80166f74] = b(V1);
////////////////////////////////
