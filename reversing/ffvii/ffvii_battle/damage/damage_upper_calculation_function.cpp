////////////////////////////////////////////////////
// upper_function_00
// physical hit
address = w[80063014];

attacker_id = w[address + 0]; // unit_id
target_id = w[address + 208];

funcb0c14;

S0 = -1;
S1 = 800f83e0 + attacker_id * 68;

if (w[address + 234] & 0001)
{
    S0 = ff;
}

if (w[address + 230] & 63)
{
    S0 = ff;
}



// if target has movement restriction statuses
// paralize, manipulate, petrify, stop, confusion, sleep, death
if (w[address + 228] & 02404445)
{
    S0 = ff;

    // if target sleeps
    if (w[address + 228] & 00000004)
    {
        [address + 23c] = w(w[address + 23c] | 00000004);
    }

    // if target is confused
    if (w[address + 228] & 00000040)
    {
        [address + 23c] = w(w[address + 23c] | 00000040);
    }

    // if target manipulated
    if (w[address + 228] & 00400000)
    {
        [address + 23c] = w(w[address + 23c] | 00a00000);
    }
}

if (w[address + 218] & 00000020)
{
    S0 = ff;
}

A1 = bu[800f83e0 + attacker_id * 68 + 14];
A2 = 5;
funcb1218; // calculate dexterity
attacker_dex = V0;
S2 = w[address + 260] + attacker_dex / 4;

A0 = attacker_id;
funcb0b94; // calculate evade for attacker
S1 = V0;


A0 = target_id;
funcb0b94; // calculate evade for target
V1 = V0;


if (S0 == -1)
{
    A0 = S2 + S1 - V1;
    funcb0e5c;
    S0 = V0;
}

if (S0 <= 0)
{
    S0 = 1;
}

A0 = 64;
func14ba8;
A2 = V0;

luck = bu[800f83e0 + attacker_id * 68 + 15]; // luck
if (A2 < luck / 4)
{
    S0 = ff;
}
else if (attacker_id >= 4 && target_id < 3)
{
    if (A2 < bu[800f83e0 + target_id * 68 + 15] / 4)
    {
        S0 = 0;
    }
}

battle_get_random_0x1-0x64;

if (V0 < S0)
{
    funcb0df8;
}
else
{
    [address + 218] = w(w[address + 218] | 00000001);
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// upper_function_01
// magical hit
address = w[80063014];

V1 = w[address + 208];
S0 = w[address + 260];
target_level = bu[800f83e0 + V1 * 68 + 9];
attacker_level = w[address + 4];
S3 = attacker_level - target_level / 2;

A0 = 64;
func14ba8;
S1 = V0;

A0 = 64;
func14ba8;
S2 = V0 + 1;

if (S0 < ff)
{
    V0 = w[address + 230];
    V0 = V0 & 63;
    if (V0 == 0)
    {
        if (w[address + 6c] & 0200 || (w[address + 228] & 00040000) == 0) // can't be reflected or not in status reflect
        {
            if (w[address + 80] != 0 || (w[address + 228] & 02004445) == 0)
            {
                A0 = S0;
                funcb0e5c;

                V1 = w[address + 208];
                V1 = bu[800f83e0 + V1 * 68 + 4d]; // magic evade

                if (S1 < V1 || S2 >= (V0 + S3))
                {
                    [address + 218] = w(w[address + 218] | 00000001);
                }
            }
        }
    }
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// upper_function_02
// critical hit
address = w[80063014];
V0 = w[address + 218];
A2 = w[address + 0];
A0 = w[address + 208];

if ((V0 & 00000001) == 0)
{
    // if attacker not in lucky girl
    if ((w[address + c8] & 40000000) == 0)
    {
        S0 = (w[address + 4] + bu[800f83e0 + A2 * 68 + 15] - bu[800f83e0 + A0 * 68 + 9]) / 4;

        if (A2 < 3)
        {
            // add weapon critical hit
            S0 = S0 + bu[800f5efc + A2 * 18 + 5];
        }
    }
    else
    {
        S0 = ff;
    }

    battle_get_random_0x1-0x64;

    if (S0 >= V0)
    {
        [address + 220] = w(w[address + 220] | 0002);
    }
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// upper_function_03
return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// upper_function_06
// hit if can be manipulated
S2 = 0;
V1 = 0;
address = w[80063014];
A0 = 0;

S1 = w[address + 208]; // target entity id

// go through player data
loopb093c:	; 800B093C
    V0 = bu[800f5e60 + A0 + 6];
    if (V0 == S1)
    {
        break;
    }
    V1 = V1 + 1;
    V0 = V1 < 3;
    A0 = A0 + 34;
800B095C	bne    v0, zero, loopb093c [$800b093c]

if (V1 == 3)
{
    if (S1 >= 4)
    {
        A1 = w[address + 0]; // attacker id
        if (A1 < 3)
        {
            V0 = bu[800f5e60 + A1 * 34 + 6];
            if (V0 == 0)
            {
                V0 = w[address + 228];
                V0 = V0 & 00400000;
                if (V0 == 0) // if enemy not manipulated
                {
                    V0 = hu[800f5bb8 + S1 * 44 + 2]; // time value addition
                    if (V0 != 0)
                    {
                        A2 = w[address + 230]; // mask of immunities to current attack
                        V0 = A2 & 20; // nullify
                        if (V0 == 0)
                        {
                            V0 = w[address + 254]; // target level
                            V1 = w[address + 4]; // attacker level
                            S0 = V1 - V0 + 32;
                            if (S0 < 0)
                            {
                                S0 = 0;
                            }

                            V0 = w[address + b8]; // number of targets
                            if (V0 >= 2)
                            {
                                S0 = S0 * 4 / 5;
                            }

                            V0 = w[address + ac];
                            if (V0 != 0)
                            {
                                S0 = S0 / 2;
                            }

                            if (A2 & 02)
                            {
                                S0 = ff;
                            }

                            V1 = bu[800f5bb8 + A1 * 44 + d]; // if hypno crown equipped
                            if (V1 == 5 && S0 < 64)
                            {
                                S0 = 64;
                            }

                            A0 = 64;
                            func14ba8;

                            if (V0 < S0)
                            {
                                S2 = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

if (S2 != 0)
{
    [SP + 12] = h(ffff);
    [SP + 10] = h(S1);
    A0 = bu[800f5bb8 + S1 * 44 + f]; // enemy type number

    V1 = A0 & ff
    if (V1 != ff)
    {
        [SP + 12] = h(A0);
    }

    attacker_id = w[address + 0];
    [800f5e60 + attacker_id * 34 + 6] = b(S1); // store target entity id

    A0 = w[address + 0];
    A1 = 5a; // string "Manipulated {VAR:TargetName}{VAR:TargetLetter}." id
    A2 = 1;
    A3 = SP + 10;
    battle_add_string_to_display;

    [address + e4] = w(-1);
}
else
{
    [address + 218] = w(w[address + 218] | 00000001);
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// upper_function_07
// hit by hit % target level
address = w[80063014];
hit = w[address + 3c];
if (hit != 0)
{
    target_level = w[address + 254];
    if (target_level % hit)
    {
        [address + 218] = w(w[address + 218] | 00000001);
    }
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb0c14
address = w[80063014];
T1 = 0;
target_column   = 0;
attacker_column = 0;
attacker_id   = w[address + 0]; // unit id
attacker_mask = 1 << attacker_id;
target_mask   = 1 << w[address + 208];

if (w[800f83e0 + attacker_id * 68 + 04] & 00000080)
{
    A3 = attacker_mask & target_mask;
}
else
{
    A3 = 0;
}

T4 = A3;



// go through right, middle and left fighters mask.
V1 = 0;
loopb0cac:	; 800B0CAC
    A0 = bu[8016376e + V1 * 2];
    if (A0 & attacker_mask) // if attacker in this row
    {
        attacker_column = V1;
    }

    if (A0 & target_mask) // if target in this row
    {
        target_column = V1;
    }

    V1 = V1 + 1;
    V0 = V1 < 3;
800B0CD8	bne    v0, zero, loopb0cac [$800b0cac]



// attacker is middle fighter
if (attacker_column == 1)
{
    // target is right fighter
    if (target_column == 0)
    {
        if ((A3 & attacker_mask) == 0)
        {
            A3 = A3 XOR attacker_mask;
        }
    }
    // target is left fighter
    else if (target_column == 2)
    {
        if (A3 & attacker_mask)
        {
            A3 = A3 XOR attacker_mask;
        }
    }
}



if (attacker_mask & A3)
{
    T1 = T1 XOR 0001;
}
if (target_mask & A3)
{
    T1 = T1 XOR 0001;
}



if (attacker_column != target_column && T1 == 0)
{
    [address + 234] = w(w[address + 234] | 0001);

    A3 = A3 XOR target_mask;
}

A3 = A3 XOR T4;
if (A3 & attacker_mask)
{
    V1 = w[800f83e0 + attacker_id * 68 + 4];
    V1 = V1 XOR 00000080;
    [800f83e0 + attacker_id * 68 + 4] = w(V1);
}

if (A3 & target_mask)
{
    [address + 234] = w(w[address + 234] | 0002);
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb0e5c
if (A0 < ff)
{
    if (w[address + c8] & 00000020) // attacker in fury
    {
        A0 = A0 * 7 / a;
    }
}

return A0;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb0b94
if (A0 < 4)
{
    A1 = bu[800f83e0 + A0 * 68 + 14] / 4 + bu[800f83e0 + A0 * 68 + f];
}
else
{
    A1 = bu[800f83e0 + A0 * 68 + f];
}

A2 = 4;
funcb1218;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// battle_get_random_0x1-0x64
// get random value from 1 to 0x64
battle_opcodes_get_random;
V0 = V0 & ffff;
V1 = V0 * 61;
A1 = hi[V1 * 80008001];
V0 = A1 + V1;
V0 = V0 >> f;
V1 = V1 >> 1f;
V0 = V0 - V1 + 1;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb0df8
address = w[80063014];
if (w[address + 234] & 0002)
{
    V0 = w[address + 208];
    [800f83e0 + V0 * 68 + 4] = w(w[800f83e0 + V0 * 68 + 4] XOR 00000080);
}
////////////////////////////////////////////////////