////////////////////////////////
// func1b0050
// main init function
// we load scene and unit data here
S5 = A0; // battle id

A0 = -1;
func3cedc;

A0 = V0;
func14c44;

A0 = -1;
func3cedc;



// init player
// init data in player structure
S0 = 0;
loop1b0090:	; 801B0090
    A0 = S0;
    system_init_player_weapon_stat;

    A0 = S0;
    system_init_player_materia;

    S0 = S0 + 1;
    V0 = S0 < 3;
801B00A8	bne    v0, zero, loop1b0090 [$801b0090]



system_calculate_total_lure_gil_preemptive_value;



// read 0x7e battle string from kernel to temp
A0 = 7e;
func1521c;

// write 0x10
[800fafd0] = w(bu[V0 + 0]);
// write 0x21
[800f7ed0] = w(bu[V0 + 1]);



// init some values
funca3278;
// init some array
funca283c;
// init some array
funcad480;



// clear attack stack data.
V0 = 1f8;
loop1b00f8:	; 801B00F8
    [800f692c + 8 + V0] = b(ff); // init priority
    V0 = V0 - 8;
801B0108	bgez   v0, loop1b00f8 [$801b00f8]



V0 = 48;
loop1b0118:	; 801B0118
    [800f6b34 + V0] = b(ff);
    V0 = V0 - 8;
801B0128	bgez   v0, loop1b0118 [$801b0118]



V0 = 8;
loop1b0138:	; 801B0138
    [800f6b86 + V0] = b(ff);
    V0 = V0 - 8;
801B0148	bgez   v0, loop1b0138 [$801b0138]



funca71f4;



[801620a8] = w(-1);



A0 = -1;
funcdcf94;



// init some values in unit structures
S0 = 0;
loop1b0178:	; 801B0178
    [800f83e0 + S0 * 68 + 08] = b(ff);
    [800f83e0 + S0 * 68 + 13] = b(10);
    S0 = S0 + 1;
    V0 = S0 < a;
801B0198	bne    v0, zero, loop1b0178 [$801b0178]



funca55bc;

initbattle_init_player; // init player unit.

initbattle_init_item; // init items



// init enemy
S4 = -1;
S3 = 1;
A0 = S5;
A1 = 0;
initbattle_load_enemy_from_scene; // load scene file



battle_init_unit_datas;



// battle speed
A0 = bu[8009d7bc];
func1b085c;



// set atb type
V0 = hu[8009d7be]; // config flags
V0 = V0 & c000; // atb type
V0 = V0 >> 6;
[800f7daa] = h(V0);



S0 = 0;
loop1b0200:	; 801B0200
    A0 = S0;
    funcae954;

    if (b[800f83e0 + S0 * 68 + 8] != -1)
    {
        [800f83a4 + a] = h(hu[800f83a4 + a] | (1 << S0));
    }

    S0 = S0 + 1;
    V0 = S0 < a;
801B0230	bne    v0, zero, loop1b0200 [$801b0200]



[800f83a4 + 04] = b(bu[8016360c + 8 + 12]);
[800f83a4 + 28] = h(S5); // battle id



func1b19ac;

battle_update_unit_mask;

// we run player setup ai if needed here
func1b1120;

// we run enemy setup here
func1b2308;

// run scripts for unit 3
funca61d4;

battle_update_unit_mask;

// init time values for units
battleinit_init_units_time_value;

// copy current hp and mp to 0x44 structure
funca4480;



[800f7de8] = h(hu[800f7de8] | 1);



// try sneack attacks
S0 = 0;
loop1b02ac:	; 801B02AC
    A0 = S0;
    A1 = 1;
    funca5bc8;

    S0 = S0 + 1;
    V0 = S0 < 3;
801B02BC	bne    v0, zero, loop1b02ac [$801b02ac]



// if not preemprive battle
V0 = hu[800f83a4 + 2c];
if (V0 & 0008 == 0)
{
    funca2894;
}
else
{
    // set battle speed to 0x80
    A0 = 0080;
    func1b085c;

    // set atb type to 0
    [800f7daa] = h(0); // atb type

    S0 = 0;
    L1b02f0:	; 801B02F0
        A0 = S0;
        func1b137c;

        S0 = S0 + 1;
        V0 = S0 < 3;
    801B0300	beq    v0, zero, L1b0318 [$801b0318]
    801B0304	nop
    801B0308	j      L1b02f0 [$801b02f0]
}



V0 = hu[800f83a4 + 2c];
if (V0 & 0004)
{
    V1 = w[GP + 244];
    if (V1 & 0004 == 0)
    {
        V0 = V1 | 0004;
        [GP + 244] = w(V0);
        [80075d04] = w(-1);
    }



    A2 = 80075d08;
    T1 = 80075d04;
    A3 = 1a0;
    A1 = hu[800f83a4 + 30];
    V1 = 1;
    801B0380	sll    v0, a1, $01
    801B0384	addu   v0, v0, a1
    801B0388	sll    a0, v0, $01
    801B038C	sllv   a0, a0, v1
    801B0390	addiu  v1, a2, $0004
    801B0394	sll    v0, v0, $03
    801B0398	addu   t0, v0, v1
    801B039C	sw     a1, $0000(a2)

    S0 = 0;
    loop1b03a0:	; 801B03A0
        V1 = w[T1];
        if( V1 & A0 )
        {
            801B03B0	nor    v0, zero, a0
            801B03B4	and    v0, v1, v0
            801B03BC	sw     v0, $0000(t1)
        }
        else
        {
            V0 = b[800f83e0 + A3 + 8];
            if (V0 != -1)
            {
                V0 = w[T0];
                [800f83e0 + A3 + 2c] = w(V0); // current hp
                if (V0 == 0)
                {
                    [800f83e0 + A3 +  0] = w(w[800f83e0 + A3 +  0] | 00000001); // current status
                    [800f83e0 + A3 + 44] = w(w[800f83e0 + A3 + 44] | 00000001); // init status
                    [800f83e4 + A3] = w(w[800f83e4 + A3] & ffffffe7);
                }
            }
        }

        L1b0448:	; 801B0448
        A0 = A0 << 1;
        T0 = T0 + 4;
        S0 = S0 + 1;
        A3 = A3 + 68;
        V0 = S0 < 6;
    801B0458	bne    v0, zero, loop1b03a0 [$801b03a0]

    battle_update_unit_mask;
}
////////////////////////////////



////////////////////////////////
// func1b085c
config_speed = A0;

V0 = 10000 / (((config_speed * 1e0 / 100) + 78) * 2);

[800f7da6] = h(V0);
////////////////////////////////



////////////////////////////////
// funcae954
unit_id = A0;
battle_speed = 0;
S3 = 0;
S1 = w[800f83e0 + unit_id * 68 + 0]; // current status
if (S1 < 0) // if imprisoned
{
    V1 = hu[800f7dc6];
    if (V1 == 1)
    {
        S1 = S1 | 02000000;
    }
    else if (V1 == 3)
    {
        S1 = S1 | 00000400;
    }
}

// if not stopped or dead
if ((S1 & 00000401) == 0)
{
    S3 = 22;
    battle_speed = hu[800f7da6]; // calculated battle speed

    if ((S1 & 00000200) == 0) // if not slowed
    {
        battle_speed = battle_speed << 1;
        S3 = 44;
        if (S1 & 00000100) // if haste
        {
            battle_speed = battle_speed << 1;
            S3 = 88;
        }
    }
}



// for players
if (unit_id < 3)
{
    A0 = unit_id;
    A1 = bu[800f83e0 + unit_id * 68 + 14]; // dexterity
    A2 = 5;
    funcb1218;

    unit_dexterity = V0 + 32;
}
// for enemy
else
{
    unit_dexterity = bu[800f83e0 + unit_id * 68 + 14]; // dexterity
}

party_dexterity = hu[800f7da8]; // party dexterity
V1 = battle_speed * unit_dexterity / party_dexterity;

// if paralized, petrified or sleep
if (S1 & 02004004)
{
    V1 = 0;
}

[800f5bb8 + unit_id * 44 + 0] = h[battle_speed];
[800f5bb8 + unit_id * 44 + 2] = h[V1];
[800f5bb8 + unit_id * 44 + a] = h[S3];
////////////////////////////////



////////////////////////////////
// func1b19ac
enemy_mask = hu[800f83a4 + 1a];
player_mask = hu[800f83a4 + 18]; // player mask

S2 = 5;
if (bu[8016360c + 8 + 12] == 7)
{
    S2 = fffffffa; // -6
}

V0 = hu[800f7dc8];
A0 = bu[801b003c + V0];

if (A0 != ff) // FF 32 33 34 35 FF
{
    if (hu[800f83a4 + 28] != 03d6) // ruby weapon battle id
    {
        funcb1060;
    }
}



A2 = 0;
[SP + 10] = h(0); // right fighter
[SP + 12] = h(0); // middle fighter
[SP + 14] = h(0); // left fighter

V1 = hu[800f7dc8];
if (V1 == 0)
{
    A2 = enemy_mask;
    [SP + 10] = h(player_mask); // right fighter
    [SP + 12] = h(enemy_mask); // middle fighter
}
else if (V1 == 1 || V1 == 3 || V1 == 5)
{
    V1 = 0 NOR S2;
    A2 = player_mask & V1;

    [SP + 10] = h(player_mask & S2);
    [SP + 12] = h(enemy_mask);
    [SP + 14] = h(player_mask & V1);

    A1 = 0;
    loop1b1b48:	; 801B1B48
        V0 = enemy_mask >> (A1 + 4);
        if (V0 & 1)
        {
            V0 = h[80163658 + A1 * 10 + 6];
            if (V0 >= 0)
            {
                V0 = 1 << (A1 + 4);
                A2 = A2 | V0;
            }
        }

        A1 = A1 + 1;
        V0 = A1 < 6;
    801B1B80	bne    v0, zero, loop1b1b48 [$801b1b48]
}
else if (V1 == 2)
{
    A2 = player_mask;
    [SP + 10] = h(enemy_mask);
    [SP + 12] = h(player_mask);
}
else if (V1 == 4)
{
    [SP + 12] = h(player_mask);

    A1 = 0;
    loop1b1aa8:	; 801B1AA8
        V0 = enemy_mask >> (A1 + 4);
        A0 = 1 << (A1 + 4);
        if (V0 & 1)
        {
            V0 = w[800f83e0 + 4 * 68 + A1 * 68 + 4];
            V0 = V0 & 00000002;
            V1 = hu[SP + 10 + V0 * 2];
            V1 = V1 | A0;
            [SP + 10 + V0 * 2] = h(V1);
        }

        A1 = A1 + 1;
        V0 = A1 < 6;
    801B1AF0	bne    v0, zero, loop1b1aa8 [$801b1aa8]



    V1 = hu[SP + 14];
    A2 = V1 | (player_mask & 0002);
    if (hu[800f83a4 + 28] == 3d6) // if battle with ruby weapon
    {
        A2 = A2 & (0 NOR player_mask);
    }
}



A1 = 0;
loop1b1b9c:	; 801B1B9C
    [800f83e0 + A1 * 68 + 4] = w(w[800f83e0 + A1 * 68 + 4] & ffffff7d); // remove 0x00000080 and 0x00000002 bits

    // if we in left command add 0x00000002 bit
    V0 = hu[SP + 14] >> A1;
    if (V0 & 1)
    {
        [800f83e0 + A1 * 68 + 4] = w(w[800f83e0 + A1 * 68 + 4] | 00000002);
    }

    // looks like models that looks different direction
    V0 = A2 & ffff >> A1;
    if (V0 & 1)
    {
        [800f83e0 + A1 * 68 + 4] = w(w[800f83e0 + A1 * 68 + 4] | 00000080);
    }

    A1 = A1 + 1;
    V0 = A1 < a;
801B1BF0	bne    v0, zero, loop1b1b9c [$801b1b9c]



A3 = 0;
loop1b1c14:	; 801B1C14
    A2 = w[800f83e0 + A3 * 68 + 4];
    V1 = hu[800f7dc8];
    A0 = A2 >> 6;
    A0 = A0 & 1;

    if (V1 >= 2)
    {
        if (V1 == 2)
        {
            A0 = A0 < 1;
            [800f83e0 + A3 * 68 + 4] = w(w[800f83e0 + A3 * 68 + 4] XOR 0040);
        }
        else
        {
            A0 = 0;
            // remove backrow if this is 3 row battle
            [800f83e0 + A3 * 68 + 4] = w(w[800f83e0 + A3 * 68 + 4] & ffffffbf);
        }
    }

    [801636be + A3 * 10] = h(A0);
    A3 = A3 + 1;
    V0 = A3 < 3;
801B1C68	bne    v0, zero, loop1b1c14 [$801b1c14]



[8016376e] = h(hu[SP + 10]);
[80163770] = h(hu[SP + 12]);
[80163772] = h(hu[SP + 14]);
////////////////////////////////



////////////////////////////////
// funcb1060
A3 = A0;
A0 = a;
A1 = 2;
A2 = 1;
funca31a0;
////////////////////////////////



////////////////////////////////
// battle_update_unit_mask
// we update unit states masks
S2 = 0;
mask_enabled_units   = 0;
S1 = 0;
mask_petrified_units = 0;
mask_dead_units      = 0;



A1 = 0;
loopa4580:	; 800A4580
    state  = w[800f83e0 + A1 * 68 + 04];
    status = w[800f83e0 + A1 * 68 + 00];

    A0 = 1 << A1;

    if (state & 00000008)
    {
        mask_enabled_units = mask_enabled_units | A0;
    }
    if (state & 00000010)
    {
        S1 = S1 | A0;
    }
    if (status & 00004000) // petrified
    {
        mask_petrified_units = mask_petrified_units | A0;
    }
    if (status & 00000001) // if unit is dead
    {
        mask_dead_units = mask_dead_units | A0;
    }
    if (status & 80000000) // if unit inprisoned
    {
        V0 = hu[800f7dc6];
        if (V0 == 0 || V0 == 3)
        {
            mask_dead_units = mask_dead_units | A0;
        }
    }

    A1 = A1 + 1;
    V0 = A1 < a;
800A45FC	bne    v0, zero, loopa4580 [$800a4580]



[800f7dce] = h(mask_petrified_units);
[80163758] = h(mask_enabled_units);
[80163768] = h(S1);
[80163766] = h(mask_dead_units);



T9 = ffff;



// loop through enemies
T6 = 4;
loopa4640:	; 800A4640
    enemy_bit = 1 << T6;

    if (mask_enabled_units & enemy_bit) // if this enemy exist
    {
        A3 = 0;
        A0 = 4;

        T2 = bu[800f83e0 + T6 * 68 + 4e]; // row from battle formation

        // remove backrow and something
        [800f83e0 + T6 * 68 + 4] = w(w[800f83e0 + T6 * 68 + 4] & fffff7bf); // remove 0x00000800 and 0x00000040

        loopa4688:	; 800A4688
            V0 = mask_enabled_units >> A0;
            if (V0 & 0001)
            {
                V0 = bu[800f83e0 + A0 * 68 + 4e]; // row from battle formation
                if (V0 < T2)
                {
                    V0 = hu[8016360c + 8 + 14 + 30 + (A0 - 4) * 10 + a];
                    A3 = A3 | V0;
                }
            }

            A0 = A0 + 1;
            V0 = A0 < a;
        800A46D8	bne    v0, zero, loopa4688 [$800a4688]



        V0 = hu[8016360c + 8 + 14 + 30 + (T6 - 4) * 10 + a]; // 0xa byte from battle formation
        if (V0 & A3)
        {
            S2 = S2 | enemy_bit;

            [800f83e0 + T6 * 68 + 4] = w(w[800f83e0 + T6 * 68 + 4] | 00000800);
        }



        if (T2 < T9)
        {
            T9 = T2;
        }
    }

    T6 = T6 + 1;
    V0 = T6 < a;
800A4734	bne    v0, zero, loopa4640 [$800a4640]



A1 = 0;
A0 = mask_enabled_units & ffff;
V1 = 1a0;

loopa4748:	; 800A4748
    V0 = A1 + 4;
    V0 = A1 >> V0;
    if (V0 & 1)
    {
        V0 = bu[800f842e + V1];
        if (V0 != T9)
        {
            V0 = w[800f83e0 + V1 + 4];
            V0 = V0 | 00000040;
            [800f83e0 + V1 + 4] = w(V0);
        }
    }

    A1 = A1 + 1;
    V1 = A1 < 6;
    V1 = V1 + 68;
800A479C	bne    v0, zero, loopa4748 [$800a4748]



V0 = mask_enabled_units XOR S2;
[8016375c] = h(V0);



V1 = 0 NOR mask_dead_units; // alive units
V1 = V1 & 000f; // leave only player
V0 = S1 | mask_enabled_units; // all enabled units
V0 = V0 & 03f0; // leave only enemy
V1 = V1 | V0;
A0 = hu[800f83a4 + a];
A0 = A0 & V1;
[8016375a] = h(A0);
[8016375e] = h(mask_enabled_units);



V1 = hu[800f7dc8];
if (V1 == 4)
{
    A0 = A0 & 3f0;

    A1 = 0;
    loopa4804:	; 800A4804
        V0 = hu[8016376e + A1 * 4];
        V0 = A0 & V0;
        if (V0 == 0)
        {
            break;
        }

        A1 = A1 + 1;
        V0 = A1 < 2;
    800A4820	bne    v0, zero, loopa4804 [$800a4804]

    [80163780] = h(A1);
}
////////////////////////////////



////////////////////////////////
// func1b1120
S0 = 0;
loop1b1148:	; 801B1148
    V0 = bu[801636b8 + S0 * 10];
    if (V0 != -1)
    {
        V0 = w[800f83e0 + S0 * 68 + 0];
        V0 = V0 & 00000001;
        if (V0 == 0) // if not dead
        {
            // execute script 0 for players
            A0 = S0;
            A1 = 0;
            A2 = 0;
            funca6000;
        }
    }

    S0 = S0 + 1;
    V0 = S0 < 3;
801B1194	bne    v0, zero, loop1b1148 [$801b1148]
////////////////////////////////



////////////////////////////////
// func1b2308
S2 = -1;

S0 = 0;
loop1b2328:	; 801B2328
    V0 = h[80163658 + S0 * 10 + 0];
    if (V0 != -1)
    {
        A0 = S0 + 4;
        A1 = 0
        A2 = 0;
        funca6000;
    }

    S0 = S0 + 1;
    V0 = S0 < 6;
801B2354	bne    v0, zero, loop1b2328 [$801b2328]



S0 = 0;
loop1b2368:	; 801B2368
    [80163658 + S0 * 10 + c] = w(w[800f83e0 + (S0 + 4) * 68 + 4]);
    [801636b9 + (S0 + 4) * 10] = b(bu[800f83e0 + (S0 + 4) * 68 + 10]);
    [800f83e0 + (S0 + 4) * 68 + 44] = w(w[800f83e0 + (S0 + 4) * 68 + 0]);

    S0 = S0 + 1;
    V0 = S0 < 6;
801B23BC	bne    v0, zero, loop1b2368 [$801b2368]
////////////////////////////////



////////////////////////////////
// funca61d4
A0 = -1;
A1 = 0;
funcb2a2c;

S0 = 0;
loopa61fc:	; 800A61FC
    V1 = hu[800f7dbc];
    V0 = V1 >> S0;
    if (V0 & 1)
    {
        // turn off this script bit.
        V0 = 1 << S0;
        V0 = 0 NOR V0;
        V0 = V1 & V0;
        [800f7dbc] = h(V0);

        A0 = 800f6ba4;
        A1 = hu[800f83a4 + 28]; // battle id
        A1 = A1 & 3;
        A2 = S0;
        get_enemy_ai_script_offset;

        if (V0 != 0)
        {
            A0 = 3;
            A1 = V0;
            A2 = -1;
            battle_opcodes_cycle;
        }
    }

    S0 = S0 + 1;
    V0 = S0 < 8;
800A6258	bne    v0, zero, loopa61fc [$800a61fc]
////////////////////////////////



////////////////////////////////
// battleinit_init_units_time_value
S4 = hu[8016375a];
S3 = 0;
S0 = 0;
loop1b069c:	; 801B069C
    [800f5bbc + S0 * 44] = h(0);
    V0 = S4 >> S0;
    V0 = V0 & 1;
    V1 = 0;
    if (V0 != 0)
    {
        battle_opcodes_get_random;
        V0 = V0 & ffff;

        V1 = V0 / 2;
        if (S3 < V1)
        {
            S3 = V1;
        }
    }

    [SP + 10 + S0 * 4] = w(V1);
    S0 = S0 + 1;
    V0 = S0 < a;
801B06E8	bne    v0, zero, loop1b069c [$801b069c]



S0 = 0;
loop1b0700:	; 801B0700
    V0 = S4 >> S0;
    V0 = V0 & 1;
    if (V0 != 0)
    {
        V1 = hu[800f7dc8];
        if (V1 == 0 || V1 == 5)
        {
            [SP + 10 + S0 * 4] = w(w[SP + 10 + S0 * 4] + e000 - S3);
        }
        if (V1 == 1 || V1 == 3)
        {
            if (S0 >= 4)
            {
                V0 = w[SP + 10 + S0 * 4];
                [SP + 10 + S0 * 4] = w(V0 / 8);
            }
            else
            {
                [SP + 10 + S0 * 4] = w(fffe);
            }
        }
        if (V1 == 2 || V1 == 4)
        {
            if (S0 >= 4)
            {
                [SP + 10 + S0 * 4] = w(w[SP + 10 + S0 * 4] + f000);
            }
            else
            {
                [SP + 10 + S0 * 4] = w(0);
            }
        }



        V0 = hu[800f83a4 + 2c];
        if (V0 & 8)
        {
            if (S0 < 3)
            {
                [SP + 10 + S0 * 4] = w(fffe);
            }
            else
            {
                [SP + 10 + S0 * 4] = w(0);
            }
        }

        [800f5bb8 + S0 * 44 + 4] = h(w[SP + 10 + S0 * 4]);
    }

    S0 = S0 + 1;
    V0 = S0 < a;
801B07F8	bne    v0, zero, loop1b0700 [$801b0700]



S0 = 0;
loop1b080c:	; 801B080C
    [8009d84c + S0 * 440 + 18] = h(hu[800f5bb8 + S0 * 44 + 4]);
    S0 = S0 + 1;
    V0 = S0 < 3;
801B0830	bne    v0, zero, loop1b080c [$801b080c]
////////////////////////////////



////////////////////////////////
// funca4480
A1 = 0;
loopa448c:	; 800A448C
    [800f5bb8 + A1 * 44 + 3c] = h(w[800f83e0 + A1 * 68 + 2c]); // current hp
    [800f5bb8 + A1 * 44 + 3e] = h(hu[800f83e0 + A1 * 68 + 28]); // current mp

    A1 = A1 + 1;
    V0 = A1 < a;
800A44C8	bne    v0, zero, loopa448c [$800a448c]
////////////////////////////////



////////////////////////////////
// funca5bc8
unit_id = A0;
S4 = A1; // 2 - counter/1 - sneak/0 - final

if (S4 == 0 || (w[800f83e0 + unit_id * 68 + 0] & 82804c44) == 0) // no statuses that remove control or A1 == 0
{
    if (unit_id < 3)
    {
        V0 = w[800f83e0 + unit_id * 68 + 4];
        V0 = V0 & 00000010;
        if (V0 == 0)
        {
            S6 = 0;
            FP = S4 * 3 + 1;

            loopa5c94:	; 800A5C94
                S1 = 0;
                loopa5ca4:	; 800A5CA4
                    V1 = bu[8009d84c + unit_id * 440 + 24 + S6 * 3 + 0];
                    if (V1 == FP + S1)
                    {
                        // if there is a chance for this action to work
                        S0 = bu[8009d84c + unit_id * 440 + 24 + S6 * 3 + 2];
                        if (S0 != 0)
                        {
                            if (S4 == 0)
                            {
                                [8009d84c + unit_id * 440 + 24 + S6 * 3 + 2] = b(S0 - 1);
                                S0 = 64;
                            }

                            // random 0-63
                            A0 = 64;
                            func14ba8;

                            // if this action must be played
                            if (V0 < S0)
                            {
                                A0 = unit_id;
                                A1 = S1;
                                A2 = bu[8009d84c + unit_id * 440 + 24 + S6 * 3 + 1];
                                A3 = SP + 18;
                                funca5ac8;

                                if (V0 & 02) // if second bit in target type
                                {
                                    A1 = hu[800f83e0 + unit_id * 68 + 1a];
                                }
                                else
                                {
                                    A1 = 1 << unit_id;
                                }

                                if (S4 == 0) // final
                                {
                                    priority = 0;
                                    A1 = A1 & f;
                                }
                                else if (S4 == 1) // sneak
                                {
                                    [800f5bb8 + unit_id * 44 + 29] = b(bu[800f5bb8 + unit_id * 44 + 29] | 4)
                                    priority = 1;
                                    A1 = 0;
                                }
                                else if (S4 == 2) // counter
                                {
                                    priority = 1;
                                }

                                // add action
                                A0 = unit_id;
                                A2 = w[SP + 18]; // action id
                                A3 = w[SP + 1c]; // attack id
                                [SP + 10] = w(A1);
                                A1 = priority;
                                battle_add_action_to_battle_queue;
                        }
                    }

                    S1 = S1 + 1;
                    V0 = S1 < 3;
                800A5DC0	bne    v0, zero, loopa5ca4 [$800a5ca4]



                S6 = S6 + 1;
                V0 = S6 < 8;
            800A5DD0	bne    v0, zero, loopa5c94 [$800a5c94]
        }
    }
}
////////////////////////////////



////////////////////////////////
// funca5ac8
unit_id = A0;
A1; // 0 - magic/summon, 1 - command, 2 - attack
action_id = A2;
// A3 = SP + 18;

//02 FF 01
V0 = bu[800a028c + A1];
S0 = A3;
[S0 + 4] = w(-1); // command id
[S0 + 0] = w(V0);

if (w[S0 + 0] == 1)
{
    return 3;
}

if (A2 >= fd)
{
    V0 = w[8009fe8c + A2 * 4];

    5C5A0A80 // master command
    885A0A80 // master magic
    A85A0A80 // master summon
    800A5B24	jalr   v0 ra

    [S0 + 4] = w(V0);
}
else
{
    [S0 + 4] = w(A2);
}

V1 = w[S0 + 0];
if (V1 == 2)
{
    T0 = bu[800708c4 + w[S0 + 4] * 1c + c];

    if (V1 < 38)
    {
        return T0;
    }

    [S0 + 0] = w(3);
    [S0 + 4] = w(w[S0 + 4] - 38);
    return T0;
}
else
{
    [S0 + 0] = w(w[S0 + 4]);
    [S0 + 4] = w(-1);
    return bu[800707c4 + w[S0 + 0] * 8 + 1];
}
////////////////////////////////



////////////////////////////////
// master command counter/sneak/final
// random 0-6
A0 = 7;
func14ba8;

return = bu[800a0278 + V0];
////////////////////////////////



////////////////////////////////
// master magic counter/sneak/final
A0 = 36;
func14ba8;

return V0;
////////////////////////////////



////////////////////////////////
// master summon counter/sneak/final
A0 = 10;
func14ba8;

return V0 + 38;
////////////////////////////////



////////////////////////////////
// funca2894
S1 = 0;
loopa28c0:	; 800A28C0
    // if lucky 7777
    V1 = w[800f83e0 + S1 * 68 + 2c];
    if (V1 == 1e61)
    {
        V0 = bu[800f5bb8 + S1 * 44 + 29];
        if (V0 & 80 == 0)
        {
            V1 = hu[800f7de2];
            [800f7de2] = h(V1 + 1);

            if (V1 < 40)
            {
                [800f5bb8 + S1 * 44 + 29] = b(bu[800f5bb8 + S1 * 44 + 29] | 80);

                A0 = S1; // unit id
                A1 = 1; // priority
                A2 = 1; // action id
                A3 = 0; // attack id
                [SP + 10] = w(0); // target mask
                battle_add_action_to_battle_queue;
            }
        }
    }

    S1 = S1 + 1;
    V0 = S1 < 3;
800A294C	bne    v0, zero, loopa28c0 [$800a28c0]
////////////////////////////////



////////////////////////////////
// func1b137c
[8009d84c + A0 * 440 + 21] = b(1);

A1 = 1;
loop1b13ac:	; 801B13AC
    [8009d84c + A0 * 440 + 4c + A1 * 6 + 0] = b(ff);
    [8009d84c + A0 * 440 + 4c + A1 * 6 + 1] = b(0);
    [8009d84c + A0 * 440 + 4c + A1 * 6 + 2] = b(0);
    [8009d84c + A0 * 440 + 4c + A1 * 6 + 3] = b(3);
    [8009d84c + A0 * 440 + 4c + A1 * 6 + 4] = b(0);
    [8009d84c + A0 * 440 + 4c + A1 * 6 + 5] = b(0);

    A1 = A1 + 1;
    V0 = A1 < 4;
801B13CC	bne    v0, zero, loop1b13ac [$801b13ac]
////////////////////////////////
