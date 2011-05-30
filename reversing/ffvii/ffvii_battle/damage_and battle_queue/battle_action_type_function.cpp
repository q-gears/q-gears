////////////////////////////////
// action_type_00
address = w[80063014];
[address + 2c] = w(w[address + 10]);
////////////////////////////////



////////////////////////////////
// action_type_01
address = w[80063014];
[address + 2c] = w(w[address + 10] + 38);
////////////////////////////////



////////////////////////////////
// action_type_02
address = w[80063014];

[address + 24] = w(w[address + 10]);
[address + 2c] = w(w[address + 10]);

A0 = h[address + 0];
A1 = h[address + 2c];
funca55f4;

if (w[address + 18] & f)
{
    [address + 20] = w(20);
}
else
{
    [address + 20] = w(21);
}
////////////////////////////////



////////////////////////////////
// action_type_04
address = w[80063014];
[address + 20] = w(-1);

funcb12dc;

if (V0 != 0)
{
    V0 = w[address + 0];
    if (w[800f83e0 + V0 * 68 + 4] & 00000040)
    {
        [address + 20] = w(3);
    }
    else
    {
        [address + 20] = w(4);
    }

    V0 = w[address + 0];


    [800f83e0 + V0 * 68 + 4] = w(w[800f83e0 + V0 * 68 + 4] XOR 00000040);
}
////////////////////////////////



////////////////////////////////
// action_type_05
return;
////////////////////////////////



////////////////////////////////
// action_type_07
//
// modify action type by attack id.
// if attack id less then folowing data action set to magic summon enemy skill or limit.
// 0000 3800 4800 6000 0001
//      02   03   0D   14

address = w[80063014];
attack_index = w[address + 10];

attack_id = hu[800f64ec + attack_index * 2];
[address + 2c] = w(attack_id);

[SP + 00] = h(h(800a0290 + 0));
[SP + 02] = h(h(800a0290 + 2));
[SP + 04] = h(h(800a0290 + 4));
[SP + 06] = h(h(800a0290 + 6));
[SP + 08] = h(h(800a0290 + 8));

[SP + 10] = h(h(800a0290 + c));
[SP + 12] = h(h(800a0290 + e));

A2 = 0;
loopa78ec:	; 800A78EC
    V0 = hu[SP + 2 + A2 * 2];
    if (attack_id < V0)
    {
        [address + 28] = w(bu[SP + 10 + A2]);

        V1 = hu[SP + A2 * 2];
        V0 = attack_id - V1;
        [address + 98] = w(V0); // attack id in group magic summon enemy skill or limit
        return;
    }

    A2 = A2 + 1;
    V0 = A2 < 4;
800A792C	bne    v0, zero, loopa78ec [$800a78ec]

return;
////////////////////////////////



////////////////////////////////
// action_type_09
// apply damage

[800f4920] = w(0);

address = w[80063014];

V0 = w[address + 20];
if (V0 != -1)
{
    S0 = w[address + dc];
    if (S0 != -1)
    {
        A0 = S0;
        funcaca4c;
    }
    else
    {
        V0 = w[address + 28];
        if (V0 < 21)
        {
            funcacb98; // check if we have enough mana

            if (V0 != 0)
            {
                return;
            }
        }

        // add flags addcut, addsteal and so on
        A0 = w[address + f0];
        if (A0 != 0)
        {
            funca2b28;
        }

        [address + ec] = w(w[address + 18]);
        [address + c4] = w(w[address + 48]);

        V1 = w[address + b4] - 1;
        [address + b4] = w(V1);

        if (V1 != -1)
        {
            Laacc0:	; 800AACC0
                S1 = 0;
                loopaacc4:	; 800AACC4
                    S0 = bu[address + d0 + S1];
                    if (S0 != ff)
                    {
                        [address + d0 + S1] = b(ff);

                        V1 = S0 & 7f;
                        [address + 2c] = w(V1);
                        [address + 98] = w(V1);
                        [address + 50] = w(ff);

                        action_type_0C;

                        if (S0 & 80)
                        {
                            [address + 6c] = w(w[address + 6c] & ffffdfff);
                        }

                        break;
                    }

                    S1 = S1 + 1;
                    V0 = S1 < 8;
                800AAD38	bne    v0, zero, loopaacc4 [$800aacc4]



                [800f4958] = h(0);
                [address + 18] = w(w[address + ec]);
                [address + fc] = w(w[address + b0]);

                funcaf9c8; // update target mask based on status and target type flags

                funcab674; // update target mask exluding units that we can't reach

                if (w[address + 90] & 00080000)
                {
                    S1 = 0;
                    loopaad98:	; 800AAD98
                        V0 = w[address + 18] >> S1;
                        if (V0 & 1)
                        {
                            if (w[800f83e0 + S1 * 68 + 0] & 00000001) // if dead
                            {
                                V0 = 1 << S1;
                                V0 = 0 NOR V0;
                                [address + 18] = w(w[address + 18] & V0);
                            }
                        }

                        S1 = S1 + 1;
                        V0 = S1 < a;
                    800AADE0	bne    v0, zero, loopaad98 [$800aad98]

                    if (w[address + 18] == 0)
                    {
                        A0 = w[address + 20];
                        funca2cc4;

                        800AAE10	j      Lab28c [$800ab28c]
                    }
                }
                elseif (w[address + 18] == 0)
                {
                    A0 = w[address + dc];
                    funcaca4c;

                    800AAC30	j      Lab28c [$800ab28c]
                }



                S1 = 0;
                loopaae30:	; 800AAE30
                    [800f4938 + S1 * 2] = h(0);
                    [800f494c + S1] = b(-1);
                    S1 = S1 + 1;
                    V0 = S1 < a;
                800AAE48	bne    v0, zero, loopaae30 [$800aae30]



                // we set upper and lower formula bits here and calculate base damage.
                funcad5e8;



                V0 = w[address + 0];
                [800f4938 + V0 * 2] = h(w[address + 18]);

                [800f4920] = w(w[800f4920] | 0009);



                Laae9c:	; 800AAE9C
                    A0 = w[800f4920];
                    if (A0 & 0006)
                    {
                        [800f4920] = w(A0 & fffd);

                        if (w[address + 28] != 3)
                        {
                            [address + 1c] = w(3);
                        }
                    }



                    S1 = 0;
                    loopaaee8:	; 800AAEE8
                        [800f4924 + S1 * 2] = h(hu[800f4938 + S1 * 2]);
                        [800f4938 + S1 * 2] = h(0);

                        S1 = S1 + 1;
                        V0 = S1 < a;
                    800AAF00	bne    v0, zero, loopaaee8 [$800aaee8]



                    S1 = 0;
                    loopaaf10:	; 800AAF10
                        S2 = hu[800f4924 + S1 * 2];
                        if (S2 != 0)
                        {
                            [address + f4] = w(S1);
                            [address + e0] = w(0);
                            [address + b0] = w(w[address + fc]);

                            [800f3950] = w(w[800f3944]);
                            [800f3954] = w(w[800f3948]);



                            A0 = S2;
                            funcaa738;



                            loopaaf4c:	; 800AAF4C
                                [address + 18] = w(S2);

                                A1 = w[address + b0] > 0;

                                if (w[address + ac] != 0)
                                {
                                    // if not attacks all attack
                                    V1 = w[address + 50] & 0c;
                                    if (V1 != 04)
                                    {
                                        A1 = 1;
                                    }
                                }

                                //if random target among selected
                                V0 = w[address + 50];
                                if (V0 & 80)
                                {
                                    A1 = 1;
                                }

                                // summon affects all
                                V0 = w[address + 28];
                                if (V0 == 3)
                                {
                                    A1 = 0;
                                }

                                // leave only one random bit
                                if (A1 != 0)
                                {
                                    A0 = w[address + 18];
                                    select_random_bit;
                                    [address + 18] = w(V0);
                                }



                                // attack every unit
                                S0 = 0;
                                Laafe0:	; 800AAFE0
                                    V0 = w[address + 18];
                                    V0 = V0 >> S0;
                                    if (V0 & 1)
                                    {
                                        // we call function that calculate and apply damage here.
                                        A0 = S1;
                                        A1 = S0;
                                        funcabb0c;
                                    }
                                    S0 = S0 + 1;
                                    V0 = S0 < a;
                                800AB014	bne    v0, zero, Laafe0 [$800aafe0]



                                V0 = w[address + b0];
                                if (V0 == 0)
                                {
                                    break;
                                }

                                V0 = V0 - 1;
                                [address + b0] = w(V0);
                            800AB038	bne    v0, zero, loopaaf4c [$800aaf4c]



                            funca317c;

                            A0 = 5;
                            funca8e84;
                        }

                        S1 = S1 + 1;
                        V0 = S1 < a;
                    800AB058	bne    v0, zero, loopaaf10 [$800aaf10]



                    S1 = 0;
                    loopab068:	; 800AB068
                        V0 = w[800f5bb8 + S1 * 44 + 2c];
                        if (V0 != 0)
                        {
                            A0 = S1;
                            A1 = 0;
                            funcab9c4;
                        }

                        V0 = w[800f5bb8 + S1 * 44 + 30];
                        if (V0 != 0)
                        {
                            A0 = S1;
                            A1 = 1;
                            funcab9c4;
                        }

                        S1 = S1 + 1;
                        V0 = S1 < a;
                    800AB0B0	bne    v0, zero, loopab068 [$800ab068]



                    if ((w[800f4920] & 2) == 0)
                    {
                        V0 = w[address + ac];
                        if (V0 != 0)
                        {
                            V0 = V0 - 1;
                            [address + ac] = w(V0);
                            if (V0 != 0)
                            {
                                A0 = w[address + 18];
                                if (w[address + 28] == 3) // if action is summon
                                {
                                    A0 = hu[80163758] & 3f0; // target all enemies
                                }

                                if (A0 != 0)
                                {
                                    // remove dead units
                                    V1 = 0;
                                    loopab120:	; 800AB120
                                        if (w[800f83e0 + V1 * 68] & 00000001)
                                        {
                                            V0 = 1 << V1;
                                            V0 = 0 NOR V0;
                                            A0 = A0 & V0;
                                        }

                                        V1 = V1 + 1;
                                        V0 = V1 < a;
                                    800AB14C	bne    v0, zero, loopab120 [$800ab120]

                                    V0 = w[address + 0];
                                    [800f4938 + V0 * 2] = h(A0);
                                    if (A0 == 0)
                                    {
                                        [address + ac] = w(0);
                                    }
                                }

                                V0 = w[address + ac];
                                if (V0 != 0)
                                {
                                    V0 = w[800f8920] | 00000004;
                                }
                                else
                                {
                                    V0 = w[800f8920] & fffffffe;
                                }
                            }
                        }
                        else
                        {
                            V0 = w[800f8920] & fffffffe;
                        }

                        [800f4920] = w(V0);
                    }

                    if ((w[address + 90] & 00001000) == 0)
                    {
                        [address + 60] = w(-4);
                    }
                    else
                    {
                        [address + 60] = w(-1);
                    }

                    [address + 64] = w(w[address + 60]);

                    V1 = w[800f4920];
                    V1 = V1 & 1;
                800AB200	bne    v1, zero, Laae9c [$800aae9c]

                // for 2x cut and 4x cut
                V0 = w[address + 20];
                if (V1 == 18)
                {
                    [address + 20] = w(19);
                }
                if (V1 == 19)
                {
                    [address + 20] = w(1a);
                }
                if (V1 == 1a)
                {
                    [address + 20] = w(1b);
                }
                if (V1 == 16)
                {
                    [address + 20] = w(17);
                    [address + ec] = w(w[address + 18]);
                }

                V1 = w[address + b4] - 1;
                [address + b4] = w(V1);
                V0 = -1;
            800AB284	bne    v1, v0, Laacc0 [$800aacc0]

        }

        Lab28c:	; 800AB28C
        if (w[address + 90] & 00000001)
        {
            A0 = 47;
            funca2cc4;
        }

        A0 = w[address + e4];
        if (A0 != -1)
        {
            funcb1060;
        }
    }
}

Lab2d8:	; 800AB2D8
////////////////////////////////



////////////////////////////////
// action_type_0A
// set target for sense
funcaf9c8;
return;
////////////////////////////////



////////////////////////////////
// action_type_0B
address = w[80063014];

// set target type to 0 (self)
[address + 50] = w(0);

// set target mask (self)
A0 = w[address + 0];
V1 = 1 << A0;
[address + 18] = w(V1);

return;
////////////////////////////////



////////////////////////////////
// action_type_0C
//
// load attack data
address = w[80063014];



S4 = 0;
[SP + 10] = w(0);



// set MP cost by default
[address + 38] = w(-1);



V1 = w[address + 28];
if (V1 == 20)
{
    A0 = w[address + 2C];
    battle_get_attack_index_by_attack_id;
    [address + 98] = w(V0);

    S4 = 800f616C + V0 * 1c;
}
else
{
    A0 = w[address + 2C];
    if (A0 < 80)
    {
        S4 = 800708C4 + A0 * 1C;

        if (A0 >= 60)
        {
            V1 = bu[800A0240 + A0];
            if (V1 != -1)
            {
                [address + 20] = w(V1);
            }

            [address + 14] = w(-1);
        }
    }
    else
    {
        // if player character
        A0 = w[address + 0];
        if (A0 < 3)
        {
            800A7AC4	sll    v1, a0, $04
            800A7AC8	lui    at, $8016
            800A7ACC	addu   at, at, v1
            800A7AD0	lb     s6, $36b8(at)
            800A7AD4	addu   a1, zero, zero
            800A7AD8	ori    s7, zero, $007f
            800A7ADC	ori    s3, zero, $0008
            800A7AE0	addu   v1, v1, a0
            800A7AE4	sll    v1, v1, $06
            800A7AE8	lui    v0, $800a
            800A7AEC	addiu  v0, v0, $d8f8 (=-$2708)
            800A7AF0	addu   s5, v1, v0
            800A7AF4	addu   a0, s5, zero

            loopa7af8:	; 800A7AF8
            800A7AF8	lui    v0, $8006
            800A7AFC	lw     v0, $3014(v0)
            800A7B00	lbu    s2, $0000(a0)
            800A7B04	lw     v1, $002c(v0)
            800A7B08	addiu  v0, s2, $0080
            800A7B0C	bne    v0, v1, La7b64 [$800a7b64]
            800A7B10	addiu  a1, a1, $0001
            800A7B14	addu   s1, zero, zero
            800A7B18	addu   s0, zero, zero
            800A7B1C	addu   a0, s6, zero

            loopa7b20:	; 800A7B20
            800A7B20	jal    func15afc [$80015afc]
            800A7B24	addu   a1, s0, zero
            800A7B28	beq    v0, s7, La7b3c [$800a7b3c]
            800A7B2C	nop
            800A7B30	beq    v0, s2, La7b4c [$800a7b4c]
            800A7B34	nop
            800A7B38	addiu  s1, s1, $0001

            La7b3c:	; 800A7B3C
            800A7B3C	addiu  s0, s0, $0001
            800A7B40	slti   v0, s0, $000c
            800A7B44	bne    v0, zero, loopa7b20 [$800a7b20]

            La7b48:	; 800A7B48
            800A7B48	addu   a0, s6, zero

            La7b4c:	; 800A7B4C
            800A7B4C	addu   s4, s5, s3
            800A7B50	lui    v1, $8006
            800A7B54	lw     v1, $3014(v1)
            800A7B58	addiu  v0, s1, $003c
            800A7B5C	j      La7b74 [$800a7b74]
            800A7B60	sw     v0, $0020(v1)

            La7b64:	; 800A7B64
            800A7B64	addiu  s3, s3, $001c
            800A7B68	slti   v0, a1, $0003
            800A7B6C	bne    v0, zero, loopa7af8 [$800a7af8]
            800A7B70	addiu  a0, a0, $0001
        }
    }
}

La7b74:	; 800A7B74
if (S4 == 0)
{
    A0 = 20;
    func155a4;

    return;
}



// we use magic 0x36 (there is only 0x35 magic in game)
if (w[address + c] == 2 && w[address + 2c] == 36)
{
    [SP + 10] = w(1);
}



A1 = w[address + 14];
if (A1 != -1)
{
    V0 = w[address + 90];
    V0 = V0 & 00400000;
    if (V0 == 0)
    {
        V1 = w[address + 0];
        S0 = 8009d84c + V1 * 440 + 108 + A1 * 8;
        V0 = bu[S0 + 1];
        [address + 38] = w(V0);

        if (bu[S0 + 4] != 0 && bu[S0 + 3] != 0)
        {
            V1 = bu[S0 + 4];
            [S0 + 4] = b(V1 - 1);

            A0 = bu[S0 + 3];
            funca8e54;

            A0 = 2;
            A1 = w[address + 0];
            A2 = 15;
            A3 = 6;
            funca7254;
        }
        else
        {
            A1 = address;
            V1 = w[address + 28];
            if (V1 == 3)
            {
                A0 = bu[S0 + 2];
                800A7C88	andi   v1, a0, $00ff
                800A7C8C	beq    v1, zero, La7cc4 [$800a7cc4]
                800A7C90	ori    v0, zero, $00ff
                800A7C94	beq    v1, v0, La7d5c [$800a7d5c]
                800A7C98	addiu  v0, a0, $ffff (=-$1)
                800A7C9C	ori    a0, zero, $0002
                800A7CA0	sb     v0, $0002(s0)
                800A7CA4	lui    v0, $8006
                800A7CA8	lw     v0, $3014(v0)
                800A7CAC	ori    a2, zero, $0015
                800A7CB0	lw     a1, $0000(v0)
                800A7CB4	jal    funca7254 [$800a7254]
                800A7CB8	ori    a3, zero, $0004
                800A7CBC	j      La7d5c [$800a7d5c]
                800A7CC0	nop

                La7cc4:	; 800A7CC4
                800A7CC4	ori    v0, zero, $0079
                800A7CC8	j      La7d5c [$800a7d5c]
                800A7CCC	sw     v0, $00dc(a1)
            }
            else
            {
                La7cd0:	; 800A7CD0
                800A7CD0	lw     a2, $0090(a1)
                800A7CD4	nop
                800A7CD8	andi   v0, a2, $0200
                800A7CDC	beq    v0, zero, La7d5c [$800a7d5c]
                800A7CE0	nop
                800A7CE4	lbu    a0, $0002(s0)
                800A7CE8	nop

                La7cec:	; 800A7CEC
                800A7CEC	andi   v1, a0, $00ff
                800A7CF0	beq    v1, zero, La7d40 [$800a7d40]
                800A7CF4	ori    v0, zero, $00ff
                800A7CF8	beq    v1, v0, La7d5c [$800a7d5c]
                800A7CFC	addiu  v0, a0, $ffff (=-$1)
                800A7D00	ori    a0, zero, $0002
                800A7D04	sb     v0, $0002(s0)
                800A7D08	lui    v0, $8006
                800A7D0C	lw     v0, $3014(v0)
                800A7D10	ori    a2, zero, $0015
                800A7D14	lw     a1, $0000(v0)
                800A7D18	jal    funca7254 [$800a7254]
                800A7D1C	ori    a3, zero, $0002
                800A7D20	j      La7d5c [$800a7d5c]
                800A7D24	nop

                La7d40:	; 800A7D40
                V0 = bu[S4 + C];
                if (V0 & 08)
                {
                    V0 = A2 | 00100000;
                    [address + 90] = w(V0);
                }
            }
        }


        La7d5c:	; 800A7D5C
        800A7D5C	lui    v0, $800f
        800A7D60	lbu    v0, $692c(v0)
        800A7D64	nop
        800A7D68	sltiu  v0, v0, $0005
        if (V0 == 0)
        {
            La7d70:	; 800A7D70
            800A7D70	lui    v1, $0040
            800A7D74	lui    a0, $8006
            800A7D78	lw     a0, $3014(a0)
            800A7D7C	nop
            800A7D80	lw     v0, $0090(a0)
            800A7D84	nop
            800A7D88	and    v0, v0, v1
            if (V0 == 0)
            {
                800A7D94	lbu    v0, $0007(s0)
                800A7D98	nop
                800A7D9C	sw     v0, $00f0(a0)
            }
        }
    }
}



T0 = w[SP + 10];

if (T0 != 0)
{
    [address + 20] = w(34);
}
else
{
    V0 = w[address + 0];
    if (V0 >= 4)
    {
        A1 = 0;
        V0 = w[address + 8];
        A3 = w[address + 2c];
        V1 = 800F5F44 + V0 * b8;
        A0 = V1;

        loopa7e00:	; 800A7E00
            V0 = hu[A0 + 48];
            if (A3 == V0)
            {
                [address + 20] = w(bu[V1 + A1 + 38]); // attack action script id
                FP = hu[A0 + 68];
                break;
            }

            A1 = A1 + 1;
            A0 = A0 + 2;
            V0 = A1 < 10;
        800A7E18	bne    v0, zero, loopa7e00 [$800a7e00]

        if (A1 == 10)
        {
            A0 = 20;
            func155a4;
            return;
        }
    }
}


// MP cost
V0 = w[address + 38];
if (V0 < 0)
{
    V0 = hu[S4 + 4];
    [address + 38] = w(V0);
}

V1 = bu[800F692C + 00]; // attack queue
if (V1 == 3 || (w[address + 90] & 00400000)) // set magic cost 0 if action priority 3 or 00400000 bit is set
{
    [address + 38] = w(0);
}



V0 = bu[S4 + 0]; // attack%
[address + 3C] = w(V0);



V0 = bu[S4 + E]; // attack formula
[address + 40] = w(V0);



// set element
V1 = hu[S4 + 18];
V1 = (V1 == -1) ? 0 : V1;
[address + 44] = w(V1);



[address + 48] = w(bu[S4 + f]);
[address + cc] = w(bu[S4 + 2]);



// set target according to target data
A0 = bu[S4 + c];
battle_copy_target_type_data_to_temp;



V1 = w[address + 28];
if (V1 == 14)
{
    V0 = hu[800F83A4 + 2C];
    V0 = V0 >>> 2;
    V0 = V0 & 0002;
    FP = hu[S4 + 8 + V0]
}

if (FP == -1)
{
    V0 = hu[S4 + 8];
    [address + 60] = w(V0);
    V0 = hu[S4 + a];
    [address + 64] = w(V0);
}
else
{
    [address + 60] = w(FP);
    [address + 64] = w(FP);
}



// set impact effect.
if (bu[S4 + 1] != -1)
{
    [address + 68] = w(V1);
}


// attack effect id
V0 = bu[S4 + D];
[address + 24] = w(V0);



V0 = hu[S4 + 1A]; // special flags
[address + 6c] = w(V0);



V0 = h[S4 + 6];
[address + 54] = w(V0);
[address + 58] = w(V0);
[address + 5C] = w(V0);



// if this is not magic attack
V0 = w[address + 6C];
V0 = V0 & 0004
if (V0 == 0)
{
    // if in darkness halve attack%
    V1 = w[address + 0];
    V0 = w[800F83E0 + V1 * 68];
    if (V0 & 04000000)
    {
        V0 = w[address + 3C];
        V0 = V0 / 2;
        [address + 3C] = w(V0);
    }
}



A0 = bu[S4 + 11]; // status%
A1 = w[S4 + 14]; // status
battle_copy_status_data_to_temp;



T0 = w[SP + 10];
if (T0 != 0)
{
    // remove death sentence
    V1 = w[address + 0];
    V1 = w[800F83E0 + V1 * 68];
    V1 = V1 & FFDFFFFF;
    [800F83E0 + V1 * 68] = w(V1);
}



A0 = bu[S4 + 12];
A1 = bu[S4 + 13];
funca8d88;
////////////////////////////////



////////////////////////////////
// action_type_0D
// load item data
address = w[80163014];
V1 = w[address + 2c];
[address + 3c] = w(ff);
S0 = 800722cc + V1 * 1c;
[address + 40] = bu[S0 + e];
[address + 48] = bu[S0 + f];

V1 = hu[S0 + 18];
if (V1 != ffff)
{
    [address + 44] = w(V1);
}

[address + 60] = w(hu[S0 + 8]);
[address + 64] = w(hu[S0 + 8]);

[address + 24] = w(bu[S0 + d]);
[address + 6c] = w(hu[S0 + 1a]);

A0 = bu[S0 + c];
battle_copy_target_type_data_to_temp;

A0 = bu[S0 + 11];
A1 = w[S0 + 14];
battle_copy_status_data_to_temp;

A0 = bu[S0 + 12];
A1 = bu[S0 + 13];
funca8d88;
////////////////////////////////



////////////////////////////////
// action_type_0E
temp = w[80063014];

[temp + 48] = w(10);

attacker_id = w[temp + 0];
if (attacker_id < 3) // if player
{
    S0 = 800f5efc + V1 * 18;

    [temp + 24] = w(bu[S0 + 1]); // effect id
    [temp + 40] = w(bu[S0 + 2]); // damage formula id
    [temp + 3c] = w(bu[S0 + 3]); // hit chance
    [temp + 44] = w(hu[S0 + e]); // attack elements mask
    [temp + 68] = w(bu[S0 + 4]); // impact effect id
    [temp + 6c] = w(hu[S0 + 12]); // special attack flags

    A0 = 5;
    A1 = w[S0 + 14];
    battle_copy_status_data_to_temp;

    V0 = w[temp + 60];
    if (V0 == ffff)
    {
        [temp + 60] = w(hu[S0 + 10]);
    }

    V0 = w[temp + 64];
    if (V0 == ffff)
    {
        [temp + 64] = w(hu[S0 + 10]);
    }

    A0 = bu[S0 + 0];
    battle_copy_target_type_data_to_temp; // to temp + 50

    // copy normal critical and miss attack sounds
    A1 = 0;
    loopa82c0:	; 800A82C0
        [temp + 54 + A1 * 4] = w(h[S0 + 8 + A1 * 2]);
        A1 = A1 + 1;
        V0 = A1 < 3;
    800A82D4	bne    v0, zero, loopa82c0 [$800a82c0]

    // add attack element type from unit 440 data (here all materias flags stored)
    [temp + 44] = w(w[temp + 44] | w[8009d888 + attacker_id * 440]);
}

// if in darkness
V0 = w[800f83e0 + attacker_id * 68];
if (V1 & 04000000)
{
    V0 = w[temp + 3c];
    V0 = V0 >> 1;
    [temp + 3c] = w(V0);
}

// if in frog set frog sounds
V0 = w[800f83e0 + attacker_id * 68];
if ( V0 & 00000800)
{
    [temp + 54] = w(16b);
    [temp + 58] = w(16c);
    [temp + 5c] = w(5);
    [temp + 68] = w(0);
}

// if lucky 7777 then no statuses or elements
V1 = w[800f5bf4 + attacker_id * 44];
if (V1 == 1e61)
{
    [temp + 44] = w(0);
    [temp + 80] = w(0);
    [temp + 84] = w(0);
    [temp + 88] = w(0);
}
////////////////////////////////



////////////////////////////////
// action_type_0F
address = w[80063014];
V0 = w[address + 20];
if (V0 >= 0)
{
    funca2f4c;

    [V0 + 0] = b(w[address + 0]);
    [V0 + 1] = b(w[address + 1c]);
    [V0 + 2] = b(w[address + 24]);
    [V0 + 3] = b(w[address + 28]);
    [V0 + 4] = b(0);
    [V0 + 5] = b(w[address + 20]);
    [V0 + 8] = b(w[address + 60]);


    funca2fd0;

    [V0 + 0] = b(w[address + 0]);
    [V0 + 1] = b(w[address + 0]);
    [V0 + 2] = b(0);
    [V0 + 4] = h(0);

    funca317c;
}
////////////////////////////////



////////////////////////////////
// action_type_14
V0 = hu[800f9da4];
if (V0 & 2)
{
    loopa4b0c:	; 800A4B0C
        funcb6d6c;

        V0 = hu[800f9da4];
        V0 = V0 & 2;
    800A4B24	bne    v0, zero, loopa4b0c [$800a4b0c]
}
////////////////////////////////



////////////////////////////////
// action_type_15
address = w[80063014];
V0 = w[address + 0];
if (V0 >= 3)
{
    [address + c] = w(1);
    [address + 50] = w(0);

    A0 = hu[address + 18];
    battle_opcodes_get_random_bit;

    A0 = V0 & ffff;
    [address + 18] = w(A0);
    get_last_significant_bit_number;

    [address + 0] = w(V0);
    [address + 20] = w(2f);
}
else
{
    [address + 20] = w(-1);
}
////////////////////////////////



////////////////////////////////
// action_type_16
800A8670	ori    t0, zero, $0020
800A8678	addu   s6, zero, zero
800A867C	addu   a3, zero, zero
800A8680	addiu  a0, zero, $ffff (=-$1)
800A8684	sw     s3, $0074(sp)
800A8688	ori    s3, zero, $0002

address = V0 = w[80063014];
800A8694	addiu  v1, sp, $0018
FP = w[address + 18]; // target mask

loopa86c0:	; 800A86C0
800A86C0	sw     a0, $0028(v1)
800A86C4	addiu  s3, s3, $ffff (=-$1)
800A86C8	bgez   s3, loopa86c0 [$800a86c0]
800A86CC	addiu  v1, v1, $fffc (=-$4)
800A86D0	addu   s3, zero, zero
800A86D4	ori    a0, zero, $0001
800A86D8	addu   v1, zero, zero

loopa86dc:	; 800A86DC
    V0 = FP >> S3;
    if (V0 & 1) // if this unit in target mask
    {
        V0 = w[800F83E0 + 30]; // Max HP
        if (V0 >= 7530) // if HP > 30000
        {
            V0 = 1 << S3;
            V0 = 0 NOR V0;
            FP = FP & V0;
        }
    }

    S3 = S3 + 1;
    V1 = V1 + 68;
    V0 = S3 < A;
800A8718	bne    v0, zero, loopa86dc [$800a86dc]

if (FP == 0)
{
    A0 = w[address + 0]
    A1 = 76; // string "couldn't sense" id
    A2 = w[SP + 50];
    A3 = SP + 48;
    funcb0ffc; // we copy couldn't sense here

    return;
}

S3 = 0;
800A874C	addiu  s7, sp, $0010
800A8750	addu   s4, s7, zero
800A8754	addu   s5, zero, zero

loopa8758:	; 800A8758
    V0 = FP >> S3;
    
    800A875C	andi   v0, v0, $0001
    800A8760	beq    v0, zero, La8828 [$800a8828]
    800A8764	sw     zero, $0000(s4)
    800A8768	lui    at, $8010
    800A876C	addu   at, at, s5
    800A8770	lhu    a0, $8404(at)
    800A8774	addu   s0, zero, zero
    800A8778	addu   v1, s7, zero

    loopa877c:	; 800A877C
        800A877C	lw     v0, $0028(v1)
        800A8780	nop
        800A8784	beq    a0, v0, La87a0 [$800a87a0]
        800A8788	ori    v0, zero, $0003
        800A878C	addiu  s0, s0, $0001
        800A8798	addiu  v1, v1, $0004
        800A8790	slti   v0, s0, $0003
    800A8794	bne    v0, zero, loopa877c [$800a877c]

    800A879C	ori    v0, zero, $0003

    La87a0:	; 800A87A0
    800A87A0	bne    s0, v0, La8824 [$800a8824]
    800A87A4	addu   v1, s7, zero
    800A87A8	addu   s0, zero, zero

    loopa87ac:	; 800A87AC
    800A87AC	lw     v0, $0028(v1)
    800A87B0	addiu  t0, zero, $ffff (=-$1)
    800A87B4	bne    v0, t0, La87c4 [$800a87c4]
    800A87B8	addiu  s0, s0, $0001
    800A87BC	j      La87d0 [$800a87d0]
    800A87C0	sw     a0, $0028(v1)

    La87c4:	; 800A87C4
    800A87C4	slti   v0, s0, $0003
    800A87C8	bne    v0, zero, loopa87ac [$800a87ac]
    800A87CC	addiu  v1, v1, $0004

    La87d0:	; 800A87D0
    800A87D0	addu   s0, zero, zero
    800A87D4	addu   s2, s4, zero
    800A87D8	addu   a0, s3, zero

    loopa87dc:	; 800A87DC
    800A87DC	ori    t0, zero, $0001
    800A87E0	sllv   s1, s0, t0
    800A87E4	addu   a1, s1, zero
    800A87E8	addu   a2, zero, zero
    800A87EC	jal    funcae6c0 [$800ae6c0]
    800A87F0	sw     a3, $0060(sp)
    800A87F4	slti   v0, v0, $0003
    800A87F8	lw     a3, $0060(sp)
    800A87FC	beq    v0, zero, La8814 [$800a8814]
    800A8800	nop
    800A8804	lw     v0, $0000(s2)
    800A8808	addiu  s6, s6, $0001
    800A880C	or     v0, v0, s1
    800A8810	sw     v0, $0000(s2)

    La8814:	; 800A8814
    800A8814	addiu  s0, s0, $0001
    800A8818	slti   v0, s0, $0010
    800A881C	bne    v0, zero, loopa87dc [$800a87dc]
    800A8820	addu   a0, s3, zero

    La8824:	; 800A8824
    800A8824	addiu  a3, a3, $0001

    La8828:	; 800A8828
    800A8828	addiu  s4, s4, $0004
    800A882C	addiu  s3, s3, $0001
    800A8838	addiu  s5, s5, $0068
    800A8830	slti   v0, s3, $000a
800A8834	bne    v0, zero, loopa8758 [$800a8758]

800A883C	slti   v0, a3, $0002
800A8840	bne    v0, zero, La884c [$800a884c]
800A8844	ori    s2, zero, $003c
800A8848	ori    s2, zero, $005a

La884c:	; 800A884C
800A884C	sll    v0, a3, $01
800A8850	addu   v0, v0, s6
800A8854	beq    v0, zero, La8888 [$800a8888]

La8858:	; 800A8858
800A8858	nop
800A885C	div    s2, v0
800A8860	bne    v0, zero, La886c [$800a886c]
800A8864	nop
800A8868	break   $01c00

La886c:	; 800A886C
800A886C	addiu  at, zero, $ffff (=-$1)
800A8870	bne    v0, at, La8884 [$800a8884]
800A8874	lui    at, $8000
800A8878	bne    s2, at, La8884 [$800a8884]
800A887C	nop
800A8880	break   $01800

La8884:	; 800A8884
800A8884	mflo   s2

La8888:	; 800A8888
800A8888	nop
800A888C	slti   v0, s2, $0004
800A8890	beq    v0, zero, La889c [$800a889c]
800A8894	addu   s3, zero, zero
800A8898	ori    s2, zero, $0004

La889c:	; 800A889C
800A889C	addiu  t0, sp, $0048
800A88A0	sw     t0, $0058(sp)
800A88A4	addiu  s7, sp, $0010
800A88A8	lui    s5, $8010
800A88AC	addiu  s5, s5, $840a (=-$7bf6)
800A88B0	addu   s1, zero, zero
800A88B4	addu   s6, zero, zero

loopa88b8:	; 800A88B8
800A88B8	srav   v0, s3, fp
800A88BC	andi   v0, v0, $0001
800A88C0	beq    v0, zero, La8a1c [$800a8a1c]
800A88C4	ori    a0, zero, $0002
800A88C8	addu   a1, s3, zero
800A88CC	ori    a2, zero, $0016
800A88D0	jal    funca7254 [$800a7254]
800A88D4	addu   a3, zero, zero
800A88D8	ori    v0, zero, $ffff
800A88DC	sh     s3, $0048(sp)
800A88E0	sh     v0, $004a(sp)
800A88E4	lui    at, $800f
800A88E8	addu   at, at, s6
800A88EC	lbu    a0, $5bc7(at)
800A88F0	ori    v0, zero, $00ff
800A88F4	andi   v1, a0, $00ff
800A88F8	beq    v1, v0, La8904 [$800a8904]
800A88FC	nop
800A8900	sh     a0, $004a(sp)

La8904:	; 800A8904
800A8904	lui    at, $8010
800A8908	addu   at, at, s1
800A890C	lbu    v0, $83e9(at)
800A8910	lui    v1, $8006
800A8914	lw     v1, $3014(v1)
800A8918	lw     a2, $0050(sp)
800A891C	lw     a3, $0058(sp)
800A8920	sh     v0, $004c(sp)
800A8924	lw     a0, $0000(v1)
A1 = 74;
funcb0ffc;

800A8930	addu   a0, s2, zero
800A8934	jal    funca3208 [$800a3208]
800A8938	ori    a1, zero, $02d7
800A893C	lui    at, $8010
800A8940	addu   at, at, s1
800A8944	lw     v0, $840c(at)
800A8948	nop
800A894C	sh     v0, $0048(sp)
800A8950	lui    at, $8010
800A8954	addu   at, at, s1
800A8958	lw     v0, $8410(at)
800A895C	nop
800A8960	sh     v0, $004a(sp)
800A8964	lui    at, $8010
800A8968	addu   at, at, s1
800A896C	lhu    v0, $8408(at)
800A8970	nop
800A8974	sh     v0, $004c(sp)
800A8978	lhu    v0, $0000(s5)
800A897C	nop
800A8980	sh     v0, $004e(sp)
800A8984	lhu    v0, $0000(s5)
800A8988	nop
if (V0 != 0)
{
    A1 = 75;
}
else
{
    A1 = 72;
}
800A8998	ori    a2, zero, $0001
800A899C	addu   s0, zero, zero
800A89A0	lui    v0, $8006
800A89A4	lw     v0, $3014(v0)
800A89A8	lw     a3, $0058(sp)
800A89AC	lw     a0, $0000(v0)
800A89B0	jal    funcb0ffc [$800b0ffc]
800A89B4	addu   s4, s7, zero
800A89B8	addu   a0, s2, zero
800A89BC	jal    funca3208 [$800a3208]
800A89C0	addu   a1, zero, zero

loopa89c4:	; 800A89C4
800A89C4	lw     v0, $0000(s4)
800A89C8	nop
800A89CC	srav   v0, s0, v0
800A89D0	andi   v0, v0, $0001
800A89D4	beq    v0, zero, La8a08 [$800a8a08]
800A89D8	ori    a2, zero, $0001
800A89E0	lui    v1, $8006
800A89E4	lw     v1, $3014(v1)
800A89E8	addiu  v0, s0, $005d
800A89EC	sh     v0, $0048(sp)
800A89F0	lw     a0, $0000(v1)
A1 = 6D;
funcb0ffc;
800A89F8	addiu  a3, sp, $0048
800A89FC	addu   a0, s2, zero
800A8A00	jal    funca3208 [$800a3208]
800A8A04	addu   a1, zero, zero

La8a08:	; 800A8A08
800A8A08	addiu  s0, s0, $0001
800A8A0C	slti   v0, s0, $0010
800A8A10	bne    v0, zero, loopa89c4 [$800a89c4]
800A8A14	ori    t0, zero, $0001
800A8A18	sw     t0, $0050(sp)

La8a1c:	; 800A8A1C
800A8A1C	addiu  s7, s7, $0004
800A8A20	addiu  s5, s5, $0068
800A8A24	addiu  s1, s1, $0068
800A8A28	addiu  s3, s3, $0001
800A8A2C	slti   v0, s3, $000a
800A8A30	bne    v0, zero, loopa88b8 [$800a88b8]
800A8A34	addiu  s6, s6, $0044
return;
////////////////////////////////



////////////////////////////////
// action_type_1E
address = w[80063014];
V1 = w[address + 0];
A0 = bu[800f5efc + V1 * 18];
battle_copy_target_type_data_to_temp;

return;
////////////////////////////////



////////////////////////////////
// funca317c
funca2fd0;

[V0 + 0] = b(-1);
////////////////////////////////




////////////////////////////////
// funca8e54
address = V1 = w[80063014];
[address + F8] = w(A0);
A0 = A0 + 3;
[address + AC] = w(A0);

if (A0 >= 9)
{
    [address + AC] = w(8);
}

return;
////////////////////////////////



////////////////////////////////
// funcaf9c8
// sets target mask according to different units masks and target type.
address = w[80063014];

S0 = hu[8016375a];
S2 = w[address + 50]; // target type data

if ((w[address + 90] & 01000000) == 0)
{
    V0 = hu[80163758]; // all enemy mask
    S0 = S0 & V0;

    V1 = w[address + 6c];
    if ((V1 & 0900) != 0900)
    {
        V0 = hu[800f7dcc];
        V1 = hu[80163766]; // dead enemy mask
        V0 = 0 NOR V0;
        V1 = V1 & V0;
        S0 = S0 | V1;
    }
}
else
{
    V0 = hu[80163766];
    S0 = S0 | V0;
}



V1 = w[address + 18];
V0 = V1 XOR S0;
A3 = V0 & V1;
if (A3 != 0)
{
    A0 = 0;
    loopafa90:	; 800AFA90
        V0 = A3 >> A0;
        if (V0 & 1)
        {
            V1 = hu[800f5bb8 + A0 * 44 + c];
            if (V1 != ff)
            {
                V1 = 1 << V1;

                V0 = w[address + 18];
                V0 = V0 | V1;
                [address + 18] = w(V0);
            }
        }

        A0 = A0 + 1;
        V0 = A0 < a;
    800AFAD0	bne    v0, zero, loopafa90 [$800afa90]
}



if (S2 == 0) // if target type is 00 - set attacker as target
{
    V1 = w[address + 0];
    V0 = 1 << V1;
    [address + 18] = w(V0);
}
else if (S2 & 40) // everyone
{
    V0 = hu[80163766];
    V1 = hu[80163758];
    V0 = 0 NOR V0;
    V1 = V1 & V0;
    [address + 18] = w(V1);
}
else
{
    S3 = 0;

    attack_player = (S2 & 02) != 0;

    A0 = w[address + 0];
    if (A0 < 4) // if attacker not enemy
    {
        attack_player = attack_player XOR 0001;
    }

    confused = 0;

    V1 = w[address + 28];
    if (V1 != 3 && V1 != 14)
    {
        V0 = w[800F83E0 + A0 * 68];
        if (V0 & 00400040) // confuse or manipulate
        {
            attack_player = attack_player XOR 0001;
        }
        if (V0 & 00000040) // confuse
        {
            confused = 1;
        }
    }

    if ((S2 & 0C) == 4) // if "target all" and not set "can select one/all"
    {
        S3 = 1;
    }

    if (w[address + ac] != 0) // if all materia?? add all flag
    {
        S3 = 1;
        S2 = S2 | 4;
    }

    if (attack_player != 0)
    {
        S1 = 000F;
    }
    else
    {
        S1 = 03F0;
    }

    if (confused != 0) // confuse
    {
        [address + 18] = w(S1);

        V0 = w[address + 90];
        if ((V0 & 00000200) == 0)
        {
            A0 = S1;
            select_random_bit;
            [address + 18] = w(V0);
        }
    }

    if (S2 & 10)
    {
        S0 = S0 & S1;
    }
    else if (S2 & 20)
    {
        V0 = w[8016375C];
        S0 = S0 & V0;
    }

    V0 = w[address + 18];
    A1 = V0 & S0; // left only alive units
    [address + 18] = w(A1);

    S1 = S1 & S0;



    V0 = w[address + 90];
    if ((V0 & 00200000) == 0)
    {
        A0 = w[address + 94];
        count_active_bits;

        if (S3 != 0 || (A1 != 0 && V0 >= 2)
        {
            V0 = w[address + 18];
            if (V0 & 000f)
            {
                S0 = S0 & 000f;
            }
            else
            {
                S0 = S0 & 03f0;
            }

            V1 = hu[8016376e];
            A0 = w[address + 18];
            V0 = A0 & V1;
            if (V0 == 0)
            {
                V0 = 0 NOR V1;
                S0 = S0 & V0;
            }

            V1 = hu[80163772];
            V0 = A1 & V1;
            if (V0 == 0)
            {
                V0 = 0 NOR V1;
                S0 = S0 & V0;
            }

            [address + 18] = w(S0);
        }

        V0 = w[address + 18];
        if (V0 == 0)
        {
            if (S2 & 04 && S2 & 08)
            {
                V0 = w[address + 90];
                if ((V0 & 0200) == 0)
                {
                    A0 = S1;
                    select_random_bit;
                    S1 = V0;
                }
            }

            [address + 18] = w(S1);
        }

        if (S2 & 04)
        {
            V0 = w[address + 90];
            V0 = V0 & 00100200;
            if (V0 == 00100200)
            {
                A0 = w[address + 18];
                select_random_bit;
                [address + 18] = w(V0);
            }
        }
        else
        {
            A0 = w[address + 18];
            select_random_bit;
            [address + 18] = w(V0);
        }
    }

    V0 = hu[8016376E];
    V1 = w[address + 18];
    if (V1 & V0)
    {
        V0 = hu[80163772];
        if (V1 & V0)
        {
            get_random_byte_from_table;
            V0 = V0 & 0002;
            V0 = V0 << 1;
            V0 = 8016376E + V0;

            A1 = hu[V0];
            V1 = w[address + 18];
            V1 = V1 & A1;
            [address + 18] = w(V1);

            V1 = hu[V0];
            V0 = w[address + ec];
            V0 = V0 & V1;
            [address + ec] = w(V0);
        }
    }
}

if (w[address + 94] == 0)
{
    [address + 94] = w(w[address + 18]);
}

return;
////////////////////////////////



////////////////////////////////
// funcacb98
address = w[80063014];
V0 = w[address + 0];
V0 = w[800f83e4 + V0 * 68 + 0];
if ((V0 & 00000400) == 0)
{
    if (w[address + 20] != 34)
    {
        forbid = 0;

        // if attacker in silence
        if (w[address + c8] & 00000080)
        {
            V0 = w[address + 28];
            if (V0 == 2 || V0 == 3 || V0 == d || V0 == 15 || V0 == 16 || (V0 == 20 && w[address + 38] != 0))
            {
                forbid = 1;
            }
        }

        // if attacker in frog status
        if (w[address + c8] & 00000800)
        {
            V0 = w[address + 28];
            // if this is magic attack and casted magic not toad
            if (V0 == 2)
            {
                if (w[address + 2c] != a)
                {
                    forbid = 1;
                }
            }
            // if this is enemy attack and magic cost greater than 0
            else if (V0 == 20)
            {
                if (w[address + 38] != 0)
                {
                    forbid = 1;
                }
            }
            else if (V0 == 3 (5 6 7 8 9 a b c d e f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f))
            {
                forbid = 1;
            }
        }

        A0 = -1;
        if (forbid == 0)
        {
            A0 = w[address + 0];
            A1 = w[address + 38];
            A2 = hu[800f83e4 + A0 * 68 + 24];
            if (A2 >= A1)
            {
                [800f83e4 + A0 * 68 + 24] = h(A2 - A1);
                [address + 38] = w(0);
                return 0;
            }

            if (A0 < 3)
            {
                V1 = 5b; // "not enough mana" text id
            }
            else
            {
                V1 = 5c; // "skill power used" text id
            }

            A0 = V1;
        }

        funcaca4c;

        [address + 38] = w(0);
        return 1;
    }
}

[address + 38] = w(0);
return 0;
////////////////////////////////



////////////////////////////////
// funcaca4c
// if we need to cancel action (for example if not enough mana of silenced).
// A0 = text to display (-1 if there is no text)

800ACA4C	lui    v0, $8006
800ACA50	lw     v0, $3014(v0)
800ACA54	addiu  sp, sp, $ffd8 (=-$28)
800ACA58	sw     s1, $001c(sp)
800ACA5C	sw     ra, $0020(sp)
800ACA60	sw     s0, $0018(sp)
800ACA64	lw     v1, $0028(v0)
800ACA68	ori    s0, zero, $0003
800ACA6C	beq    v1, s0, Lacab4 [$800acab4]
800ACA70	addu   s1, a0, zero
800ACA74	slti   v0, v1, $0004
800ACA78	beq    v0, zero, Laca90 [$800aca90]
800ACA7C	ori    v0, zero, $0002
800ACA80	beq    v1, v0, Lacaac [$800acaac]
800ACA84	nop
800ACA88	j      Lacac8 [$800acac8]
800ACA8C	nop

Laca90:	; 800ACA90
800ACA90	ori    v0, zero, $000d
800ACA94	beq    v1, v0, Lacabc [$800acabc]
800ACA98	ori    v0, zero, $0014
800ACA9C	beq    v1, v0, Lacac4 [$800acac4]
800ACAA0	nop
800ACAA4	j      Lacac8 [$800acac8]
800ACAA8	nop

Lacaac:	; 800ACAAC
800ACAAC	j      Lacac8 [$800acac8]
800ACAB0	ori    s0, zero, $0038

Lacab4:	; 800ACAB4
800ACAB4	j      Lacac8 [$800acac8]
800ACAB8	ori    s0, zero, $0036

Lacabc:	; 800ACABC
800ACABC	j      Lacac8 [$800acac8]
800ACAC0	ori    s0, zero, $0037

Lacac4:	; 800ACAC4
800ACAC4	ori    s0, zero, $0035

Lacac8:	; 800ACAC8
800ACAC8	lui    a0, $8006
800ACACC	lw     a0, $3014(a0)
800ACAD0	nop
800ACAD4	lw     v1, $0000(a0)
800ACAD8	nop
800ACADC	slti   v0, v1, $0003
800ACAE0	beq    v0, zero, Lacb28 [$800acb28]
800ACAE4	addiu  v0, zero, $ffff (=-$1)
800ACAE8	jal    funca2cc4 [$800a2cc4]
800ACAEC	addu   a0, s0, zero
800ACAF0	addiu  v0, zero, $ffff (=-$1)
800ACAF4	beq    s1, v0, Lacb10 [$800acb10]
800ACAF8	ori    v0, zero, $0003
800ACAFC	jal    funcb1060 [$800b1060]
800ACB00	addu   a0, s1, zero
800ACB04	jal    funca2cc4 [$800a2cc4]
800ACB08	ori    a0, zero, $003b
800ACB0C	ori    v0, zero, $0003

Lacb10:	; 800ACB10
800ACB10	bne    s0, v0, Lacb80 [$800acb80]
800ACB14	nop
800ACB18	jal    funca2cc4 [$800a2cc4]
800ACB1C	ori    a0, zero, $0004
800ACB20	j      Lacb80 [$800acb80]
800ACB24	nop

Lacb28:	; 800ACB28
800ACB28	beq    s1, v0, Lacb80 [$800acb80]
800ACB2C	ori    v0, zero, $ffff
800ACB30	sh     v1, $0010(sp)
800ACB34	sh     v0, $0012(sp)
800ACB38	lw     v1, $0000(a0)
800ACB3C	nop
800ACB40	sll    v0, v1, $04
800ACB44	addu   v0, v0, v1
800ACB48	sll    v0, v0, $02
800ACB4C	lui    at, $800f
800ACB50	addu   at, at, v0
800ACB54	lbu    a1, $5bc7(at)

Lacb58:	; 800ACB58
800ACB58	ori    v0, zero, $00ff
800ACB5C	andi   v1, a1, $00ff
800ACB60	beq    v1, v0, Lacb6c [$800acb6c]
800ACB64	nop
800ACB68	sh     a1, $0012(sp)

Lacb6c:	; 800ACB6C
800ACB6C	lw     a0, $0000(a0)
800ACB70	addu   a1, s1, zero
800ACB74	ori    a2, zero, $0001
800ACB78	jal    funcb0ffc [$800b0ffc]
800ACB7C	addiu  a3, sp, $0010

Lacb80:	; 800ACB80
800ACB80	lw     ra, $0020(sp)
800ACB84	lw     s1, $001c(sp)
800ACB88	lw     s0, $0018(sp)
800ACB8C	addiu  sp, sp, $0028
800ACB90	jr     ra 
800ACB94	nop
////////////////////////////////



////////////////////////////////
// funca2b28
address = w[80063014];

// mp absorb
if (A0 & 0001)
{
    [address + 90] = w(w[address + 90] | 00000080);
}

// hp absorb
if (A0 & 0002)
{
    [address + 90] = w(w[address + 90] | 00000040);
}

// steal as well
if (A0 & 0008)
{
    [address + 90] = w(w[address + 90] | 00000004);
}

// add cut
if (A0 & 0010)
{
    [address + 90] = w(w[address + 90] | 00000800);
}

if (A0 & 00e0)
{
    V0 = A0 >> 5;
    [address + e8] = w(V0 * a);
}
////////////////////////////////



////////////////////////////////
// funcab674
address = w[80063014];
if ((w[address + 90] & 0010) == 0)
{
    V0 = w[address + 0];
    if (V0 < 3)
    {
        if (w[address + 44] & 1c00 || w[address + 28] == 5) // if punch hit cut || attack == steal
        {
            A1 = w[address + 18];

            V1 = 4;
            loopab6dc:	; 800AB6DC
                V0 = bu[800f83e0 + V1 * 68 + 4e];
                if (V0 >= 10)
                {
                    V0 = 1 << V1;
                    V0 = 0 NOR V0;
                    A1 = A1 & V0;
                }

                V1 = V1 + 1;
                V0 = V1 < a;
            800AB708	bne    v0, zero, loopab6dc [$800ab6dc]

            V0 = w[address + 18];
            if (A1 != V0)
            {
                V0 = w[address + 0];
                // long ranged materia equipped
                V0 = bu[8009d84c + V0 * 440 + 23];
                if (V0 & 4)
                {
                    [address + 90] = w(w[address + 90] | 00020000);
                }
                else
                {
                    [address + 18] = w(A1);
                    if (A1 == 0)
                    {
                        [address + dc] = w(77); // Can't reach!! text id
                    }
                }
            }
        }
    }
}
////////////////////////////////



////////////////////////////////
// funcad5e8
address = w[80063014];



V1 = w[address + 40]; // load formula
upper = V1 >> 4;
[address + a0] = w(upper); // upper

V1 = V1 & f;
[address + a4] = w(V1); // lower

// set physical attack
if (upper == 0 || upper == 1 || upper == 3 || upper == 6 || upper == a || upper == b)
{
    [address + 6c] = w(w[address + 6c] & fffb);
}

// use special formulas
if (upper == 6 || upper == 7)
{
    [address + a4] = w(w[address + a4] | 10);
}

// this is only for A attack type. This is physical attack with special atribures. Set them.
// reset lower bit to 1 but set some data to bc (maybe special formula)
if (upper == a)
{
    V0 = w[address + a4];
    [address + a4] = w(00000001);

    V1 = bu[800a04b0 + V0]; // 0A 0B 0C 0D 1E 1F 20 21 22
    [address + bc] = w(V1);
}



// if this is magic attack
V0 = w[address + 6c];
if (V0 & 0004)
{
    A0 = w[address + 0];
    A1 = bu[800f83e0 + A0 * 68 + e];
    A2 = 1;
}
else
{
    A0 = w[address + 0];
    A1 = bu[800F83E0 + A0 * 68 + d];
    A2 = 0;
}

modifier = b[800f5bb8 + A0 * 44 + 20 + A2];

[address + 4c] = w(A1 + (A1 * modifier) / 64);
////////////////////////////////



////////////////////////////////
// funca2efc
[800f3950] = w(w[800f3944]);
[800f3954] = w(w[800f3948]);
////////////////////////////////



////////////////////////////////
// funcaa738
// fill attack action struct
address = w[80063014];

S0 = A0; // target mask

funca2f4c;
S1 = V0;

A0 = S0;
count_active_bits;
[address + b8] = w(V0);

[S1 + 0] = b(w[address + 0]);
[S1 + 1] = b(w[address + 1c]);
[S1 + 5] = b(w[address + 20]);

V0 = w[address + 0];
if (V0 >= 4)
{
    if (w[address + c8] & 00000800) // attacker frog
    {
        if (w[address + 20] != 34)
        {
            if (w[address + 28] == 20 && w[address + 24] == ff) // action id == 20 and attack effect id == ff
            {
                [S1 + 5] = b(14);
            }
            else if (w[address + 28] < 21)
            {
                [S1 + 5] = b(1d);
            }
        }
    }
}
else if (V0 < 3)
{
    // replace single animation action with their multiple analog
    if (w[address + b8] >= 2 || w[address + 90] & 00000002)
    {
        A0 = b[S1 + 5];

        V1 = 0;
        loopaa898:	; 800AA898
            V0 = bu[800e7bbc + V1];
            if (A0 == V0)
            {
                [S1 + 5] = b(bu[800e7bbd + V1]);
                break;
            }

            V1 = V1 + 2;
            V0 = V1 < e;
        800AA8B8	bne    v0, zero, loopaa898 [$800aa898]
    }
}

[S1 + 2] = b(w[address + 24]);
[S1 + 3] = b(w[address + 28]);

V0 = w[address + b8];
if (V0 >= 2)
{
    V1 = hu[address + 64];
}
else
{
    V1 = hu[address + 60];
}

[S1 + 8] = h(V1);
[S1 + 4] = b(0);
[S1 + 6] = h(w[address + 98]);
////////////////////////////////



////////////////////////////////
// funcb6d6c
800B6D6C	lui    a0, $8016
800B6D70	lbu    a0, $90e0(a0)
800B6D74	addiu  sp, sp, $ffd0 (=-$30)
800B6D78	sw     ra, $0028(sp)
800B6D7C	sw     s5, $0024(sp)
800B6D80	sw     s4, $0020(sp)
800B6D84	sw     s3, $001c(sp)
800B6D88	sw     s2, $0018(sp)
800B6D8C	sw     s1, $0014(sp)
800B6D90	sw     s0, $0010(sp)
800B6D94	sll    v0, a0, $01
800B6D98	addu   v0, v0, a0
800B6D9C	sll    v0, v0, $02
800B6DA0	lui    at, $8016
800B6DA4	addiu  at, at, $3798
800B6DA8	addu   at, at, v0
800B6DAC	lb     v1, $0000(at)
800B6DB0	addiu  v0, zero, $ffff (=-$1)
800B6DB4	beq    v1, v0, Lb772c [$800b772c]
800B6DB8	sll    v0, a0, $01
800B6DBC	lui    s4, $1f80
800B6DC0	ori    s4, s4, $0004
800B6DC4	lui    s3, $1f80
800B6DC8	ori    s3, s3, $0008
800B6DCC	addiu  s1, zero, $ffff (=-$1)
800B6DD0	lui    s5, $8016
800B6DD4	addiu  s5, s5, $3798
S2 = 1;

Lb6ddc:	; 800B6DDC
800B6DDC	addu   v0, v0, a0
800B6DE0	sll    v0, v0, $02
V1 = b[80163798 + V0 + 1];
800B6DF8	sltiu  v0, v1, $0006
800B6DFC	beq    v0, zero, Lb76f8 [$800b76f8]
800B6E00	sll    v0, v1, $02
V0 = w[800a05fc + V0];
800B6E18	jr     v0 
800B6E1C	nop

800B6E20	lui    v1, $8016
800B6E24	lbu    v1, $90e0(v1)
800B6E28	nop
800B6E2C	sll    v0, v1, $01
800B6E30	addu   v0, v0, v1
800B6E34	sll    v0, v0, $02
800B6E38	lui    at, $8016
800B6E3C	addiu  at, at, $3798
800B6E40	addu   at, at, v0
800B6E44	lb     a0, $0000(at)
800B6E48	nop
800B6E4C	sll    v1, a0, $01
800B6E50	addu   v1, v1, a0
800B6E54	sll    v0, v1, $05
800B6E58	subu   v0, v0, v1
800B6E5C	sll    v0, v0, $03
800B6E60	subu   v0, v0, a0
800B6E64	sll    v0, v0, $02
800B6E68	lui    at, $8015
800B6E6C	addiu  at, at, $1922
800B6E70	addu   at, at, v0
800B6E74	lbu    v1, $0000(at)
800B6E78	nop
800B6E7C	ori    v1, v1, $0020
800B6E80	lui    at, $8015
800B6E84	addiu  at, at, $1922
800B6E88	addu   at, at, v0
800B6E8C	sb     v1, $0000(at)
800B6E90	lui    v0, $8016
800B6E94	lbu    v0, $90e0(v0)
800B6E98	nop
800B6E9C	sll    a0, v0, $01
800B6EA0	addu   a0, a0, v0
800B6EA4	sll    a0, a0, $02
800B6EA8	lui    at, $8016
800B6EAC	addiu  at, at, $3798
800B6EB0	addu   at, at, a0
800B6EB4	lb     v1, $0000(at)
800B6EB8	lui    at, $8016
800B6EBC	addiu  at, at, $3798
800B6EC0	addu   at, at, a0
800B6EC4	lb     a0, $0000(at)
800B6EC8	sll    v0, v1, $03
800B6ECC	subu   v0, v0, v1
800B6ED0	sll    v0, v0, $02
800B6ED4	addu   v0, v0, v1
800B6ED8	sll    v1, v1, $04
800B6EDC	lui    at, $8016
800B6EE0	addiu  at, at, $36c0
800B6EE4	addu   at, at, v1
800B6EE8	lw     v1, $0000(at)
800B6EEC	sll    v0, v0, $02
800B6EF0	lui    at, $8015
800B6EF4	addiu  at, at, $1200
800B6EF8	addu   at, at, v0
800B6EFC	sw     v1, $0000(at)
800B6F00	sll    v0, a0, $03
800B6F04	subu   v0, v0, a0
800B6F08	sll    v0, v0, $02
800B6F0C	addu   v0, v0, a0
800B6F10	sll    v0, v0, $02
800B6F14	lui    at, $8015
800B6F18	addiu  at, at, $1200
800B6F1C	addu   at, at, v0
800B6F20	lw     v1, $0000(at)
800B6F24	ori    v0, zero, $0010
800B6F28	beq    v1, v0, Lb6f74 [$800b6f74]
800B6F2C	ori    v0, zero, $0020
800B6F30	beq    v1, v0, Lb6f74 [$800b6f74]
800B6F34	sll    v0, a0, $01
800B6F38	addu   v0, v0, a0
800B6F3C	sll    v1, v0, $05
800B6F40	subu   v1, v1, v0
800B6F44	sll    v1, v1, $03
800B6F48	subu   v1, v1, a0
800B6F4C	sll    v1, v1, $02
800B6F50	lui    at, $8015
800B6F54	addiu  at, at, $18fc
800B6F58	addu   at, at, v1
800B6F5C	lhu    v0, $0000(at)
800B6F60	nop
800B6F64	lui    at, $8015
800B6F68	addiu  at, at, $1a46
800B6F6C	addu   at, at, v1
800B6F70	sh     v0, $0000(at)

Lb6f74:	; 800B6F74
800B6F74	jal    funcb7fdc [$800b7fdc]
800B6F78	nop
800B6F7C	j      Lb76e0 [$800b76e0]
800B6F80	nop
800B6F84	lui    a0, $800c
800B6F88	addiu  a0, a0, $494c
800B6F8C	jal    funcbc04c [$800bc04c]
800B6F90	nop
800B6F94	jal    funcb7fdc [$800b7fdc]
800B6F98	nop
800B6F9C	j      Lb76e0 [$800b76e0]
800B6FA0	nop
800B6FA4	lui    v0, $8016
800B6FA8	lbu    v0, $90e0(v0)
800B6FAC	nop
800B6FB0	sll    v1, v0, $01
800B6FB4	addu   v1, v1, v0
800B6FB8	sll    v1, v1, $02
800B6FBC	lui    at, $8016
800B6FC0	addiu  at, at, $379e
800B6FC4	addu   at, at, v1
800B6FC8	lh     a0, $0000(at)
800B6FCC	lui    at, $8016
800B6FD0	addiu  at, at, $379d
800B6FD4	addu   at, at, v1
800B6FD8	lbu    a1, $0000(at)
800B6FDC	lui    at, $8016
800B6FE0	addiu  at, at, $379b
800B6FE4	addu   at, at, v1
800B6FE8	lbu    a2, $0000(at)
800B6FEC	lui    at, $8016
800B6FF0	addiu  at, at, $379a
800B6FF4	addu   at, at, v1
800B6FF8	lbu    a3, $0000(at)
800B6FFC	jal    funcc5c18 [$800c5c18]
800B7000	nop
800B7004	jal    funcb7fdc [$800b7fdc]
800B7008	nop
800B700C	j      Lb76e0 [$800b76e0]
800B7010	nop
800B7014	lui    v0, $800f
800B7018	lbu    v0, $7de4(v0)
800B701C	nop
800B7020	beq    v0, zero, Lb76c4 [$800b76c4]
800B7024	nop
800B7028	lui    v0, $8016
800B702C	lbu    v0, $90e0(v0)
800B7030	lui    at, $800f
800B7034	sb     zero, $7de4(at)
800B7038	sll    v1, v0, $01
800B703C	addu   v1, v1, v0
800B7040	sll    v1, v1, $02
800B7044	lui    at, $8016
800B7048	addiu  at, at, $379d
800B704C	addu   at, at, v1
800B7050	lb     v0, $0000(at)
800B7054	nop
800B7058	sll    v0, v0, $08
800B705C	sw     v0, $0000(s4)
800B7060	lui    at, $8016
800B7064	addiu  at, at, $3798
800B7068	addu   at, at, v1
800B706C	lb     a0, $0000(at)
800B7070	nop
800B7074	sll    v1, a0, $01
800B7078	addu   v1, v1, a0
800B707C	sll    v0, v1, $05
800B7080	subu   v0, v0, v1
800B7084	sll    v0, v0, $03
800B7088	subu   v0, v0, a0
800B708C	sll    v0, v0, $02
800B7090	lui    at, $8015
800B7094	addiu  at, at, $18ea
800B7098	addu   at, at, v0
800B709C	lh     v0, $0000(at)
800B70A0	lui    a0, $800c
800B70A4	addiu  a0, a0, $5694
800B70A8	jal    funcbbeac [$800bbeac]
800B70AC	sw     v0, $0000(s3)
800B70B0	lw     a1, $0000(s4)
800B70B4	lw     a0, $0000(s3)
800B70B8	addu   a2, v0, zero
800B70BC	slt    v0, a1, a0
800B70C0	beq    v0, zero, Lb70f8 [$800b70f8]
800B70C4	nop
800B70C8	lui    v1, $8016
800B70CC	lbu    v1, $90e0(v1)
800B70D0	nop
800B70D4	sll    v0, v1, $01
800B70D8	addu   v0, v0, v1
800B70DC	sll    v0, v0, $02
800B70E0	lui    at, $8016
800B70E4	addiu  at, at, $379e
800B70E8	addu   at, at, v0
800B70EC	lh     v1, $0000(at)
800B70F0	j      Lb7124 [$800b7124]
800B70F4	subu   v0, a0, a1

Lb70f8:	; 800B70F8
800B70F8	lui    v1, $8016
800B70FC	lbu    v1, $90e0(v1)
800B7100	nop
800B7104	sll    v0, v1, $01
800B7108	addu   v0, v0, v1
800B710C	sll    v0, v0, $02
800B7110	lui    at, $8016
800B7114	addiu  at, at, $379e
800B7118	addu   at, at, v0
800B711C	lh     v1, $0000(at)
800B7120	subu   v0, a1, a0

Lb7124:	; 800B7124
800B7124	div    v0, v1
800B714C	mflo   v0
800B7150	sll    v1, a2, $05
800B7154	lui    at, $8016
800B7158	addiu  at, at, $297a
800B715C	addu   at, at, v1
800B7160	sh     v0, $0000(at)
800B7164	lui    v1, $8016
800B7168	lbu    v1, $90e0(v1)
800B716C	nop
800B7170	sll    v0, v1, $01
800B7174	addu   v0, v0, v1
800B7178	sll    v0, v0, $02
800B717C	lui    at, $8016
800B7180	addiu  at, at, $3798
800B7184	addu   at, at, v0
800B7188	lb     a0, $0000(at)
800B718C	nop
800B7190	sll    v1, a0, $01
800B7194	addu   v1, v1, a0
800B7198	sll    v0, v1, $05
800B719C	subu   v0, v0, v1
800B71A0	sll    v0, v0, $03
800B71A4	subu   v0, v0, a0
800B71A8	sll    v0, v0, $02
800B71AC	lui    at, $8015
800B71B0	addiu  at, at, $190a
800B71B4	addu   at, at, v0
800B71B8	sb     zero, $0000(at)
800B71BC	lui    v0, $8016
800B71C0	lbu    v0, $90e0(v0)
800B71C4	nop
800B71C8	sll    v1, v0, $01
800B71CC	addu   v1, v1, v0
800B71D0	sll    v1, v1, $02
800B71D4	lui    at, $8016
800B71D8	addiu  at, at, $3798
800B71DC	addu   at, at, v1
800B71E0	lbu    v0, $0000(at)
800B71E4	sll    a0, a2, $05
800B71E8	sll    v0, v0, $18
800B71EC	sra    v0, v0, $18
800B71F0	lui    at, $8016
800B71F4	addiu  at, at, $297e
800B71F8	addu   at, at, a0
800B71FC	sh     v0, $0000(at)
800B7200	lui    at, $8016
800B7204	addiu  at, at, $379e
800B7208	addu   at, at, v1
800B720C	lhu    v0, $0000(at)
800B7210	nop
800B7214	lui    at, $8016
800B7218	addiu  at, at, $297c
800B721C	addu   at, at, a0
800B7220	sh     v0, $0000(at)
800B7224	lui    at, $8016
800B7228	addiu  at, at, $37a0
800B722C	addu   at, at, v1
800B7230	sh     s1, $0000(at)
800B7234	j      Lb76c4 [$800b76c4]
800B7238	nop
800B723C	lui    v0, $800f
800B7240	lbu    v0, $7de4(v0)
800B7244	nop
800B7248	beq    v0, zero, Lb76c4 [$800b76c4]
800B724C	nop
800B7250	lui    at, $800f
800B7254	sb     zero, $7de4(at)
800B7258	jal    funcbb684 [$800bb684]
800B725C	nop
800B7260	lui    v1, $8016
800B7264	lbu    v1, $90e0(v1)
800B7268	nop
800B726C	sll    v0, v1, $01
800B7270	addu   v0, v0, v1
800B7274	sll    v0, v0, $02
800B7278	lui    at, $8016
800B727C	addiu  at, at, $37a2
800B7280	addu   at, at, v0
800B7284	lh     v1, $0000(at)
800B7288	nop
800B728C	sll    v0, v1, $01
800B7290	addu   v0, v0, v1
800B7294	sll    v0, v0, $02
800B7298	lui    at, $8010
800B729C	addiu  at, at, $a9d1 (=-$562f)
800B72A0	addu   at, at, v0
800B72A4	lbu    v0, $0000(at)
800B72A8	nop
800B72AC	lui    at, $8016
800B72B0	sb     v0, $90cc(at)
800B72B4	lui    a0, $8016
800B72B8	lbu    a0, $90cc(a0)
800B72BC	nop
800B72C0	sll    v1, a0, $01
800B72C4	addu   v1, v1, a0
800B72C8	sll    v0, v1, $05
800B72CC	subu   v0, v0, v1
800B72D0	sll    v0, v0, $03
800B72D4	subu   v0, v0, a0
800B72D8	sll    v0, v0, $02
[801518e4 + V0 + 26] = b(S2);
800B72EC	jal    funcb7764 [$800b7764]
800B72F0	nop
800B72F4	lui    v1, $8016
800B72F8	lbu    v1, $90e0(v1)
800B72FC	nop
800B7300	sll    v0, v1, $01
800B7304	addu   v0, v0, v1
800B7308	sll    v0, v0, $02
800B730C	lui    at, $8016
800B7310	addiu  at, at, $37a2
800B7314	addu   at, at, v0
800B7318	lh     v1, $0000(at)
[800f9774] = b(0);
800B7324	sll    v0, v1, $01
800B7328	addu   v0, v0, v1
800B732C	sll    v0, v0, $02
800B7330	lui    at, $8010
800B7334	addiu  at, at, $a9d0 (=-$5630)
800B7338	addu   at, at, v0
800B733C	lb     v0, $0000(at)
800B7340	nop
800B7344	beq    v0, s1, Lb73c4 [$800b73c4]
800B7348	addiu  s0, zero, $ffff (=-$1)

loopb734c:	; 800B734C
800B734C	jal    funcb79f0 [$800b79f0]
800B7350	nop
800B7354	lui    v1, $8016
800B7358	lbu    v1, $90e0(v1)
800B735C	nop
800B7360	sll    v0, v1, $01
800B7364	addu   v0, v0, v1
800B7368	sll    v0, v0, $02
800B736C	lui    at, $8016
800B7370	addiu  at, at, $37a2
800B7374	addu   at, at, v0
800B7378	lhu    v1, $0000(at)
800B737C	addu   a0, v0, s5
800B7380	addiu  v1, v1, $0001
800B7384	sh     v1, $000a(a0)
800B7388	lui    at, $8016
800B738C	addiu  at, at, $37a2
800B7390	addu   at, at, v0
800B7394	lh     v1, $0000(at)
800B7398	nop
800B739C	sll    v0, v1, $01
800B73A0	addu   v0, v0, v1
800B73A4	sll    v0, v0, $02
800B73A8	lui    at, $8010
800B73AC	addiu  at, at, $a9d0 (=-$5630)
800B73B0	addu   at, at, v0
800B73B4	lb     v0, $0000(at)
800B73B8	nop
800B73BC	bne    v0, s0, loopb734c [$800b734c]
800B73C0	nop

Lb73c4:	; 800B73C4
800B73C4	ori    v0, zero, $0001
800B73C8	lui    at, $8015
800B73CC	sb     v0, $17bc(at)
800B73D0	jal    funcb7db4 [$800b7db4]
800B73D4	nop
800B73D8	j      Lb76c4 [$800b76c4]
800B73DC	nop
800B73E0	lui    v0, $800f
800B73E4	lbu    v0, $7de4(v0)
800B73E8	nop
800B73EC	beq    v0, zero, Lb76bc [$800b76bc]
800B73F0	nop
800B73F4	lui    at, $800f
800B73F8	sb     zero, $7de4(at)
800B73FC	jal    funcbb684 [$800bb684]
800B7400	nop
800B7404	lui    v1, $8016
800B7408	lbu    v1, $90e0(v1)
800B740C	nop
800B7410	sll    v0, v1, $01
800B7414	addu   v0, v0, v1
800B7418	sll    v0, v0, $02
800B741C	lui    at, $8016
800B7420	addiu  at, at, $3798
800B7424	addu   at, at, v0
800B7428	lbu    v0, $0000(at)
800B742C	nop
800B7430	lui    at, $8016
800B7434	sb     v0, $90cc(at)
800B7438	lui    a0, $8016
800B743C	lbu    a0, $90cc(a0)
800B7440	nop
800B7444	sll    v1, a0, $01
800B7448	addu   v1, v1, a0
800B744C	sll    v0, v1, $05
800B7450	subu   v0, v0, v1
800B7454	sll    v0, v0, $03
800B7458	subu   v0, v0, a0
800B745C	sll    v0, v0, $02
800B7460	lui    at, $8015
800B7464	addiu  at, at, $1922
800B7468	addu   at, at, v0
800B746C	lbu    v1, $0000(at)
800B7470	nop
800B7474	ori    v1, v1, $0001
800B7478	lui    at, $8015
800B747C	addiu  at, at, $1922
800B7480	addu   at, at, v0
800B7484	sb     v1, $0000(at)
800B7488	lui    a0, $8016
800B748C	lbu    a0, $90cc(a0)
800B7490	nop
800B7494	sll    v1, a0, $01
800B7498	addu   v1, v1, a0
800B749C	sll    v0, v1, $05
800B74A0	subu   v0, v0, v1
800B74A4	sll    v0, v0, $03
800B74A8	subu   v0, v0, a0
800B74AC	sll    v0, v0, $02
800B74B0	lui    at, $8015
800B74B4	addiu  at, at, $190a
800B74B8	addu   at, at, v0
800B74BC	sb     zero, $0000(at)
funcb7764; // we call this function where we assign action to enemy unit
800B74C4	nop
800B74C8	lui    a1, $8016
800B74CC	lbu    a1, $90e0(a1)
800B74D0	nop
800B74D4	sll    v0, a1, $01
800B74D8	addu   v0, v0, a1
800B74DC	sll    v0, v0, $02
800B74E0	lui    at, $8016
800B74E4	addiu  at, at, $37a2
800B74E8	addu   at, at, v0
800B74EC	lh     v1, $0000(at)
[800f9774] = b(0);
800B74F8	j      Lb7690 [$800b7690]

Lb7624:	; 800B7624
800B7624	lui    at, $8010
800B7628	sb     v0, $a6d4(at)
800B762C	lui    at, $8016
800B7630	sb     v0, $1eec(at)
800B7634	lui    at, $8010
800B7638	sb     v0, $99e8(at)
[801031f0] = b(S2);

Lb7644:	; 800B7644
800B7644	lui    a1, $8016
800B7648	lbu    a1, $90e0(a1)
800B764C	nop
800B7650	sll    v0, a1, $01
800B7654	addu   v0, v0, a1
800B7658	sll    v0, v0, $02
800B765C	lui    at, $8016
800B7660	addiu  at, at, $37a2
800B7664	addu   at, at, v0
800B7668	lhu    v1, $0000(at)
800B766C	addu   a0, v0, s5
800B7670	addiu  v1, v1, $0001
800B7674	sh     v1, $000a(a0)
800B7678	lui    at, $8016
800B767C	addiu  at, at, $37a2
800B7680	addu   at, at, v0
800B7684	lh     v1, $0000(at)
800B7688	nop

Lb7690:	; 800B7690
V0 = b[800fa9d0 + V1 * c + 0];
if (V0 != -1)
{
    V1 = h[801537a2 + A1 * c];
    [800fafe0] = b(bu[800fa9d0 + V1 * c + 1]); // attacker id

    funcb79f0;

    V0 = bu[800f9774];

    800B7558	bne    v0, s2, Lb7624 [$800b7624]
    800B755C	ori    v0, zero, $000f
    800B7560	lui    v0, $8016
    800B7564	lbu    v0, $90e0(v0)
    800B7568	nop
    800B756C	sll    a0, v0, $01
    800B7570	addu   a0, a0, v0
    800B7574	sll    a0, a0, $02
    800B7578	lui    at, $8016
    800B757C	addiu  at, at, $37a2
    800B7580	addu   at, at, a0
    800B7584	lh     v1, $0000(at)
    800B7588	nop
    800B758C	sll    v0, v1, $01
    800B7590	addu   v0, v0, v1
    800B7594	sll    v0, v0, $02
    V0 = bu[800fa9d0 + V0 + 0];
    800B75A8	lui    at, $8016
    800B75AC	addiu  at, at, $37a2
    800B75B0	addu   at, at, a0
    800B75B4	lh     v1, $0000(at)
    800B75B8	lui    at, $8010
    800B75BC	sb     v0, $a6d4(at)
    [800f99e8] = b(V0);
    800B75C8	lui    at, $8016
    800B75CC	sb     v0, $1eec(at)
    800B75D0	sll    v0, v1, $01
    800B75D4	addu   v0, v0, v1
    800B75D8	sll    a0, v0, $02
    800B75DC	lui    at, $8010
    800B75E0	addiu  at, at, $a9d2 (=-$562e)
    800B75E4	addu   at, at, a0
    800B75E8	lb     v1, $0000(at)
    800B75EC	ori    v0, zero, $0009
    if (V1 == V0)
    {
        800B75F8	lui    at, $8010
        800B75FC	addiu  at, at, $a9d1 (=-$562f)
        800B7600	addu   at, at, a0
        800B7604	lbu    v0, $0000(at)
        800B7608	nop
        800B760C	lui    at, $8010
        800B7610	sb     v0, $99e8(at)
    }

    [801031f0] = b(0);
    800B7614	lui    at, $8010
    800B7618	sb     zero, $31f0(at)
    800B761C	j      Lb7644 [$800b7644]
    800B7620	nop
}

800B76B4	jal    funcb7db4 [$800b7db4]

Lb76bc:	; 800B76BC
800B76BC	lui    at, $8015
800B76C0	sb     zero, $17bc(at)

Lb76c4:	; 800B76C4
800B76C4	jal    funcb7fdc [$800b7fdc]
800B76C8	nop
800B76CC	lui    v0, $800f
800B76D0	lbu    v0, $7de4(v0)
800B76D4	nop
800B76D8	beq    v0, zero, Lb76f8 [$800b76f8]
800B76DC	nop

Lb76e0:	; 800B76E0
800B76E0	lui    v0, $8016
800B76E4	lbu    v0, $90e0(v0)
800B76E8	nop
800B76EC	addiu  v0, v0, $0001
800B76F0	lui    at, $8016
800B76F4	sb     v0, $90e0(at)

Lb76f8:	; 800B76F8
800B76F8	lui    a0, $8016
800B76FC	lbu    a0, $90e0(a0)
800B7700	nop
800B7704	sll    v0, a0, $01
800B7708	addu   v0, v0, a0
800B770C	sll    v0, v0, $02
800B7710	lui    at, $8016
800B7714	addiu  at, at, $3798
800B7718	addu   at, at, v0
800B771C	lb     v0, $0000(at)
800B7720	nop
800B7724	bne    v0, s1, Lb6ddc [$800b6ddc]
800B7728	sll    v0, a0, $01

Lb772c:	; 800B772C
800B772C	lui    at, $8016
800B7730	sb     zero, $90e0(at)
800B7734	jal    funcb7fdc [$800b7fdc]
800B7738	nop
800B773C	lw     ra, $0028(sp)
800B7740	lw     s5, $0024(sp)
800B7744	lw     s4, $0020(sp)
800B7748	lw     s3, $001c(sp)
800B774C	lw     s2, $0018(sp)
800B7750	lw     s1, $0014(sp)
800B7754	lw     s0, $0010(sp)
800B7758	addiu  sp, sp, $0030
800B775C	jr     ra 
800B7760	nop
////////////////////////////////



////////////////////////////////
// funca55f4
A3 = 0;
loopa5618:	; 800A5618
    if (h[800f3a40 + A3 * 4 + 0] == A0 && h[800f3a40 + A3 * 4 + 2] == A1)
    {
        [800f3a40 + A3 * 4 + 0] = h(ffff);
        [800f3a40 + A3 * 4 + 2] = h(ffff);
        break;
    }

    A3 = A3 + 1;
    V0 = A3 < 10;
800A5650	bne    v0, zero, loopa5618 [$800a5618]
////////////////////////////////



////////////////////////////////
// funcab9c4
S0 = A0;
S1 = A1;

V0 = w[800f83e0 + S0 * 68 + 0]; // status
if ((V0 & 00000001) == 0)
{
    funca2f4c;

    [V0 + 0] = b(S0);
    [V0 + 1] = b(1);
    [V0 + 2] = b(0);
    [V0 + 3] = b(0);
    [V0 + 4] = b(0);
    [V0 + 5] = b(2e);
    [V0 + 6] = h(0);
    [V0 + 8] = h(ffff);

    A0 = S0;
    A1 = S1;
    funcab830;

    funca317c;
}
////////////////////////////////



////////////////////////////////
// funcb79f0
action_struct_id = bu[801590e0];
index = h[80163798 + action_struct_id * c + a];
target_count = bu[800f9774];

[80163cc0 + target_count * 8] = b(bu[800fa9d0 + index * c + 0]); // target id
[801517f0 + target_count] = b(bu[800fa9d0 + index * c + 0]); // target id


[80163cc2 + target_count * 8] = h(hu[800fa9d0 + index * c + 4]); // flags

[80163cc4 + target_count * 8] = w(w[800fa9d0 + index * c + 8]); // store status of target

A0 = bu[80163cc0 + target_count * 8];
[801518e8 + A0 * b9c] = h(bu[800fa9d0 + index * c + 2]); // hurt animation

V1 = b[800fa9d0 + index * c + 3];
[800f99ec + target_count * c] = h(hu[800f9f3c + V1 * e + 2]); // damage
[800f99ee + target_count * c] = h(hu[800f9f3c + V1 * e + 4]); // flags
[800f99f4 + target_count * c] = h(V1);
[800f99f6 + target_count * c] = h(index);

V1 = b[800fa9d3 + index * c];
if (V1 == -1)
{
    [800f99f0 + target_count * c] = h(-1);
    [800f99f2 + target_count * c] = h(-1);
}
else
{
    [800f99f0 + target_count * c] = h(hu[800f9f3c + V1 * e + a]); // impact sound
    [800f99f2 + target_count * c] = h(hu[800f9f3c + V1 * e + c]); // impact effect id
}

[800f9774] = b(target_count + 1);
////////////////////////////////