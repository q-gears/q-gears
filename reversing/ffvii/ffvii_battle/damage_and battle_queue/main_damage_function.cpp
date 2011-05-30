////////////////////////////////////////////////////
// main damage function
// funca1798
address = w[80063014];

[800F7DB8] = h(0);
attack_stack_offset = A0; // 800f692c



// increment GP + D4 (0-7 and repeat)
increment_seed_for_random;



if (bu[attack_stack_offset + 0] >= 2) // if action priority 2 3 4 5 or 6 store attacker mask
{
    V1 = b[attack_stack_offset + 2];
    V0 = 1 << V1;
    [800f7dd8] = h(V0);
}

[800f83a4 + 0] = b(bu[attack_stack_offset + 3] & 3F);
[800f83a4 + 1] = b(hu[attack_stack_offset + 4]);



if (bu[attack_stack_offset + 0] != 0) // if action priority not 0 - run scripts 7 for all entity
{
    S0 = 0;

    loopa1830:	; 800A1830
        A0 = S0
        A1 = 7;
        A2 = 0;
        // script executed here
        funca6000;
        S0 = S0 + 1;
        V0 = S0 < A;
    800A1844	bne    v0, zero, loopa1830 [$800a1830]
}



// reset all temp array
S0 = FF;
V0 = address + 3fc;

loopa185c:	; 800A185C
    [V0] = w(0);
    S0 = S0 - 1;
    V0 = V0 - 4;
800A1864	bgez   s0, loopa185c [$800a185c]



attacker_id = b[attack_stack_offset + 2];



///////////////////////////////////////////////////////////////////////
// unknown
S1 = -1;
V0 = bu[attack_stack_offset + 3];
if (V0 & 40)
{
    S0 = 0;

    loopa18a8:	; 800A18A8
        V0 = hu[800f5e60 + attacker_id * 34 + 18 + S0 * 2];
        if (V0 != -1)
        {
            S1 = V0;
            [800f5e60 + attacker_id * 34 + 18 + S0 * 2] = h(-1);
            break;
        }

        S0 = S0 + 1;
        V0 = S0 < 2;
    800A18C0	bne    v0, zero, loopa18a8 [$800a18a8]
}
///////////////////////////////////////////////////////////////////////
// store leftover part back
V0 = bu[attack_stack_offset + 3];
S0 = V0 & 3F;
[attack_stack_offset + 3] = b(S0);



if (attacker_id < 3 && w[800F83E0 + attacker_id * 68] & 00000800) // if player in frog status
{
    A0 = attacker_id;
    battle_get_berserk_toad_action_id_for_player;

    if (S0 == V0) // if berserk attack is the same as one we requested - set toad attack
    {
        [attack_stack_offset + 3] = b(1);

        A0 = hu[attack_stack_offset + 6];
        select_random_bit;
        [attack_stack_offset + 6] = h(V0);
    }
}



[address + 0] = w(attacker_id);



action_type = b[attack_stack_offset + 3];
[address + c] = w(action_type);



attack_index = hu[attack_stack_offset + 4];
[address + 10] = w(attack_index);
[address + 98] = w(attack_index);



attack_mask = hu[attack_stack_offset + 6];
[address + 18] = w(attack_mask);
[address + 94] = w(attack_mask);



attacker_level = bu[800f83e0 + attacker_id * 68 + 09];
[address + 4] = w(attacker_level);



// store current attacker status
A3 = w[800f83e0 + attacker_id * 68 + 00];
[address + c8] = w(A3);



// set default values for attack type
V1 = bu[800a0000 + action_type * 4];
[address + 20] = w(V1);
attack_formula = bu[800A0001 + action_type * 4];
[address + 40] = w(attack_formula);
A1 = hu[800A0002 + action_type * 4];
[address + 90] = w(A1);



[address + 1c] = w(1);
[address + b4] = w(1);



[address + 08] = w(-1);
[address + 14] = w(-1);
[address + 54] = w(-1);
[address + 58] = w(-1);
[address + 5c] = w(-1);
[address + 60] = w(-1);
[address + 64] = w(-1);
[address + 68] = w(-1);
[address + 6c] = w(-1);
[address + bc] = w(-1);
[address + dc] = w(-1);
[address + e4] = w(-1);

[address + 50] = w(FF);
[address + 8c] = w(FF);



V1 = 1 << attacker_id;
[address + 30] = w(V1); // attacker mask



S0 = 0;
loopa1a3c:	; 800A1A3C
    [address + d0 + S0] = b(FF);
    S0 = S0 + 1;
    V0 = S0 < 8;
800A1A58	bne    v0, zero, loopa1a3c [$800a1a3c]



// if there is no target (for player) or more than one
A0 = attack_mask;
count_active_bits;
if ((V0 == 0 && attacker_id < 3 ) || V0 >= 2)
{
    V0 = w[address + 90];
    V0 = V0 | 00000200;
    [address + 90] = w(V0);
}



// set default target type for action type < 20 from kernel
if (w[address + c] < 20)
{
    [address + 50] = w(bu[800707c4 + A0 * 8 + 1]);
}



///////////////////////////////////////////////////////////////////////
// unknown
if (S1 != -1)
{
    A0 = S1 >> 8;
    if (A0 != 0)
    {
        funca8e54;
    }

    [address + f0] = w(S1 & ff);

    V0 = w[address + 90];
    V0 = V0 | 00400000;
    [address + 90] = w(V0);
}
///////////////////////////////////////////////////////////////////////



// if player unit
if (attacker_id < 3)
{
    A0 = attacker_id;
    funca2bf4; // search current attack id.

    V0 = w[address + 90];
    V0 = V0 & 00400000;
    if (V0 == 0)
    {
        S0 = 0;

        loopa1b90:	; 800A1B90
            V1 = bu[8009d84c + attacker_id * 440 + 4c + S0 * 6];
            action_type = w[address + c];

            if (V1 == action_type)
            {
                if (bu[800f692c + 0] >= 5) // if priority 5 or 6
                {
                    [address + f0] = w(bu[8009d84c + attacker_id * 440 + 4c + S0 * 6 + 5]);
                }

                switch (action_type)
                {
                    case 0x5 0x6 0x9 0xA 0xB 0x11: // only this actions use megaall
                    {
                        if (w[address + 90] & 00000200) // if there no target for player of more than one
                        {
                            V0 = bu[8009d84c + attacker_id * 440 + 4c + S0 * 6 + 4];
                            if (V0 != 0)
                            {
                                V0 = V0 - 1;
                                [8009d84c + attacker_id * 440 + 4c + S0 * 6 + 4] = b(V0); // reduce mega all number of stars

                                A0 = 2;
                                A1 = attacker_id;
                                A2 = 15;
                                A3 = 1;
                                funca7254;
                            }
                            else
                            {
                                [address + 90] = w(w[address + 90] | 00100000);
                            }
                        }

                        [address + 50] = w(bu[8009d84c + attacker_id * 440 + 4c + S0 * 6 + 2]);
                    }
                }

                break;
            }

            S0 = S0 + 1;
            V0 = S0 < 10;
        800A1C84	bne    v0, zero, loopa1b90 [$800a1b90]
    }
}



A0 = bu[800f5bb8 + attacker_id * 44 + 29];
if (A0 & 80)
{
    V0 = A0 & 7F;
    [800F5BB8 + attacker_id * 44 + 29] = b(V0);

    V1 = hu[800f5bb8 +  + attacker_id * 44 + 3c];
    if (V1 == 1e61)
    {
        [800f7dbe] = h(51);
        [800f7dc0] = h(2f);
    }
}



[address + 28] = w(w[address + c]);


// replace 15 with 2, 16 with 3, 17 with 4
A0 = 0;
loopa1d04:	; 800A1D04
    V1 = w[address + 28];
    V0 = w[800a0108 + A0];
    if (V1 == V0)
    {
        [address + 28] = w(w[800a010c + A0]);
    }

    A0 = A0 + 8;
    V0 = A0 < 18;
800A1D3C	bne    v0, zero, loopa1d04 [$800a1d04]



V1 = w[address + c];
if (V1 < 20) // if action type less than 20
{
    [address + 60] = w(hu[800707c4 + V1 * 8 + 4]);
    [address + 64] = w(hu[800707c4 + V1 * 8 + 6]);
}



if (attacker_id >= 4)
{
    V0 = attacker_id - 4;
    V0 = h[80163658 + V0 * 10];
    [address + 8] = w(V0); // enemy index
}



// copy string to output
V0 = bu[800f5bb8 + attacker_id * 44 + 29];
if (V0 & 04)
{
    [SP + 18] = h(attacker_id);

    A0 = attacker_id;
    A1 = 7a; // string "XX was cought by surprize" id
    A2 = 1;
    A3 = SP + 18;
    funcb0ffc; // we copy string here

    V0 = bu[800F5BB8 + attacker_id * 44 + 29];
    V0 = V0 & FB;
    [800F5BB8 + attacker_id * 44 + 29] = b(V0);
}




V0 = w[address + c];

// after each function
        // if error - we finish
        V0 = w[GP + 01d0];
        if (V0 >= 0)
        {
            return;
        }
//////////////////////

switch (V0)
{
    // attack, mug, slash-all
    case 0x01 0x11 0x18:
    {
        action_type_0E; // load player attack data based on equipped weapon
        action_type_09; // calculate and apply damage
    }
    break;

    // magic, w-magic
    case 0x02 0x15:
    {
        action_type_00; // set attack id as attack index
        action_type_0C; // load attack data
        action_type_09; // calculate and apply damage
    }
    break;

    // summon, w-summon
    case 0x03 0x16:
    {
        action_type_01; // set attack id as attack index + 38
        action_type_0C; // load attack data
        action_type_09; // calculate and apply damage
    }
    break;

    // item, w-item
    case 0x04 0x17:
    {
        action_type_02; // set attack id and animations
        action_type_0D; // load item attack data
        action_type_09; // calculate and apply damage
    }
    break;

    // steal
    case 0x05:
    {
        action_type_1E; // set target type acording to player equipped weapon
        action_type_09; // calculate and apply damage
    }
    break;

    // sense
    case 0x06:
    {
        action_type_0A;
        action_type_16;
        action_type_09; // calculate and apply damage
    }
    break;

    // coin
    case 0x07:
    {
        60750A80 // 1D
        action_type_09; // calculate and apply damage
    }
    break;

    // throw
    case 0x08:
    {
        58740A80 // 19
        action_type_09; // calculate and apply damage
    }
    break;

    // morph
    case 0x09:
    {
        action_type_0E; // load player attack data based on equipped weapon
        048D0A80 // 1C
        action_type_09; // calculate and apply damage
    }
    break;

    //death blow
    case 0x0A:
    {
        action_type_0E; // load player attack data based on equipped weapon
        C88C0A80 // 1B
        action_type_09; // calculate and apply damage
    }
    break;

    // manipulate
    case 0x0B:
    {
        40790A80 // 1A
        action_type_09; // calculate and apply damage
    }
    break;

    // mime
    case 0x0C:
    {
        6C8A0A80 // 17
    }
    break;

    // enemy skill
    case 0x0D:
    {
        AC760A80 // 3
        action_type_0C; // load attack data
        action_type_09; // calculate and apply damage
    }
    break;

    // change
    case 0x12:
    {
        action_type_04; // se animation to play and switch rows
        action_type_0B; // set target type and target mask to self
        action_type_0F; // add action to perform
    }
    break;

    // defend
    case 0x13:
    {
        action_type_05; // this just returns
    }
    break;

    // limit
    case 0x14:
    {
        8C770A80 // 6
        action_type_0C; // load attack data
        action_type_09; // calculate and apply damage
    }
    break;

    // 2x-cut
    case 0x19:
    {
        A0850A80 // 12
        action_type_0E; // load player attack data based on equipped weapon
        action_type_09; // calculate and apply damage
    }
    break;

    // flash
    case 0x1A:
    {
        action_type_0E; // load player attack data based on equipped weapon
        948C0A80 // 18
        action_type_09; // calculate and apply damage
    }
    break;

    // 4x cut
    case 0x1B:
    {
        28850A80 // 10
        action_type_0E; // load player attack data based on equipped weapon
        action_type_09; // calculate and apply damage
    }
    break;

    // enemy attack
    case 0x20:
    {
        action_type_07; // modify some action id and attack id because we can use global attacks for enemies attack (magic summons enemy_skills limits)
        action_type_0C; // load attack data
        action_type_09; // calculate and apply damage
    }
    break;

    // ???
    case 0x21:
    {
        5C790A80 // 8
    }
    break;

    // Run Script
    case 0x22:
    {
        3C850A80 // 11
    }
    break;

    // ???
    case 0x23:
    {
        B4850A80 // 13
        action_type_09; // calculate and apply damage
    }
    break;

    // pause battle engine while display string
    case 0x24:
    {
        action_type_14;
    }
    break;

    // ???
    case 0x25:
    {
        action_type_15;
        action_type_0F; // add action to perform
    }
    break;
}

A0 = A0 + 1;
funca304c;



if (attacker_id < 3)
{
    V0 = w[80063014];

    800A1ED0	lw     v1, $000c(v0)
    800A1ED4	ori    v0, zero, $000c
    800A1ED8	beq    v1, v0, La2028 [$800a2028]
    800A1EDC	slti   v0, v1, $0020
    800A1EE0	beq    v0, zero, La2028 [$800a2028]
    800A1EE4	sll    v0, attacker_id, $04
    800A1EE8	addu   v0, v0, attacker_id
    800A1EEC	sll    v0, v0, $02
    800A1EF0	lui    at, $800f
    800A1EF4	addu   at, at, v0
    800A1EF8	lbu    a3, $5be2(at)
    800A1EFC	addu   a2, zero, zero
    800A1F00	ori    t0, zero, $0003
    800A1F04	addiu  t1, zero, $ffff (=-$1)
    800A1F08	lui    a1, $800f
    800A1F0C	addiu  a1, a1, $7dda
    800A1F10	addiu  v1, a1, $edac (=-$1254)
    800A1F14	addu   a0, zero, zero

    loopa1f18:	; 800A1F18
        800A1F18	lbu    v0, $0000(attack_stack_offset)
        800A1F1C	nop
        800A1F20	beq    v0, t0, La2010 [$800a2010]
        800A1F24	nop
        800A1F28	lb     v0, $0000(v1)
        800A1F2C	nop
        800A1F30	bne    v0, attacker_id, La1f70 [$800a1f70]
        800A1F34	nop
        800A1F38	lui    at, $800f
        800A1F3C	addu   at, at, a0
        800A1F40	lbu    v0, $6b85(at)
        800A1F44	nop
        800A1F48	bne    v0, a3, La1f70 [$800a1f70]
        800A1F4C	nop
        800A1F50	lui    v0, $8006
        800A1F54	lw     v0, $3014(v0)
        800A1F58	nop
        800A1F5C	lw     v0, $000c(v0)
        800A1F60	nop
        800A1F64	slti   v0, v0, $0015
        800A1F68	beq    v0, zero, La2010 [$800a2010]
        800A1F6C	nop

        La1f70:	; 800A1F70
        800A1F70	sb     attacker_id, $0000(v1)
        800A1F74	lui    at, $800f
        800A1F78	addu   at, at, a0
        800A1F7C	sb     a3, $6b85(at)
        800A1F80	lui    v0, $8006
        800A1F84	lw     v0, $3014(v0)
        800A1F88	nop
        800A1F8C	lw     v0, $000c(v0)
        800A1F90	lui    at, $800f
        800A1F94	addu   at, at, a0
        800A1F98	sb     v0, $6b87(at)
        800A1F9C	lui    v1, $8006
        800A1FA0	lw     v1, $3014(v1)
        800A1FA4	nop
        800A1FA8	lw     v0, $0010(v1)
        800A1FAC	lui    at, $800f
        800A1FB0	addu   at, at, a0
        800A1FB4	sh     v0, $6b88(at)
        800A1FB8	lw     v0, $0094(v1)
        800A1FBC	lui    at, $800f
        800A1FC0	addu   at, at, a0
        800A1FC4	sh     v0, $6b8a(at)
        800A1FC8	lw     a0, $00f0(v1)
        800A1FCC	nop
        800A1FD0	sh     a0, $0000(a1)
        800A1FD4	lw     v0, $00f8(v1)
        800A1FD8	nop
        800A1FDC	beq    v0, zero, La1fec [$800a1fec]
        800A1FE0	sll    v0, v0, $08
        800A1FE4	or     v0, a0, v0
        800A1FE8	sh     v0, $0000(a1)

        La1fec:	; 800A1FEC
        800A1FEC	addiu  v1, a2, $0001
        800A1FF0	slti   v0, v1, $0002
        800A1FF4	beq    v0, zero, La2028 [$800a2028]
        800A1FF8	sll    v0, v1, $03
        800A1FFC	lui    at, $800f
        800A2000	addu   at, at, v0
        800A2004	sb     t1, $6b86(at)
        800A2008	j      La2028 [$800a2028]
        800A200C	nop

        La2010:	; 800A2010
        800A2010	addiu  a1, a1, $0002
        800A2014	addiu  v1, v1, $0008
        800A2018	addiu  a2, a2, $0001
        800A2024	addiu  a0, a0, $0008
        800A201C	slti   v0, a2, $0002
    800A2020	bne    v0, zero, loopa1f18 [$800a1f18]
}

La2028:	; 800A2028
800A2028	lui    v1, $8006
800A202C	lw     v1, $3014(v1)
800A2030	nop
800A2034	lw     v0, $0090(v1)
800A2038	nop
800A203C	andi   v0, v0, $0800
800A2040	beq    v0, zero, La2060 [$800a2060]
800A2044	addu   a0, attacker_id, zero
800A2048	ori    a1, zero, $0003
800A204C	ori    a2, zero, $0001
800A2050	lw     v0, $0094(v1)
800A2054	addu   a3, zero, zero
800A2058	jal    funca3e98 [$800a3e98]
800A205C	sw     v0, $0010(sp)

La2060:	; 800A2060
800A2060	lui    a0, $8006
800A2064	lw     a0, $3014(a0)
800A2068	nop
800A206C	lw     v1, $0028(a0)
800A2070	ori    v0, zero, $0006
800A2074	bne    v1, v0, La2084 [$800a2084]
800A2078	nop
800A207C	sw     zero, $0078(a0)
800A2080	sw     zero, $00a8(a0)

La2084:	; 800A2084
800A2084	lui    v1, $8006
800A2088	lw     v1, $3014(v1)
800A208C	addu   s0, zero, zero
800A2090	lw     v0, $006c(v1)
800A2094	ori    s7, zero, $0001
800A2098	lui    at, $8010
800A209C	sh     v0, $83d2(at)
800A20A0	lw     v0, $000c(v1)
800A20A4	sllv   s3, attacker_id, s7
800A20A8	lui    at, $8010
800A20AC	sb     v0, $83a4(at)
800A20B0	lw     v0, $0010(v1)
800A20B4	lui    a0, $800f
800A20B8	addiu  a0, a0, $7dcc
800A20BC	lui    at, $8010
800A20C0	sb     v0, $83a5(at)
800A20C4	lw     v0, $002c(v1)
800A20C8	addiu  s5, a0, $000c
800A20CC	lui    at, $8010
800A20D0	sh     v0, $83ce(at)
800A20D4	lw     v0, $0044(v1)
800A20D8	addu   s1, zero, zero
800A20DC	lui    at, $8010
800A20E0	sh     v0, $83c8(at)
800A20E4	lhu    a1, $0000(a0)
800A20E8	lui    v0, $800f
800A20EC	lhu    v0, $7de0(v0)
800A20F0	lw     a0, $0078(v1)
800A20F4	nor    v0, v0, a1
800A20F8	and    a0, a0, v0
800A20FC	sw     a0, $0020(sp)
800A2100	lw     a0, $00a8(v1)
800A2104	lw     v1, $007c(v1)
800A2108	and    fp, a0, v0
800A210C	and    s6, v1, v0

loopa2110:	; 800A2110
800A2110	srav   v0, s0, s6
800A2114	andi   v0, v0, $0001
800A2118	beq    v0, zero, La2140 [$800a2140]
800A211C	addu   a0, attacker_id, zero
800A2120	lui    at, $8010
800A2124	addu   at, at, s1
800A2128	sh     s3, $83fa(at)
800A212C	addu   a1, s0, zero
800A2130	jal    funca6278 [$800a6278]
800A2134	addu   a2, zero, zero
800A2138	j      La2218 [$800a2218]
800A213C	addiu  s0, s0, $0001

La2140:	; 800A2140
800A2140	lw     t2, $0020(sp)
800A2144	nop
800A2148	srav   v0, s0, t2
800A214C	andi   v0, v0, $0001
800A2150	beq    v0, zero, La2214 [$800a2214]
800A2154	nop
800A2158	lhu    a3, $0000(s5)
800A215C	nop
800A2160	srav   v0, s0, a3
800A2164	andi   v0, v0, $0001
800A2168	bne    v0, zero, La2214 [$800a2214]

V0 = w[800F83E0 + S1];
if (V0 & 02404404)
{
    V0 = S7 << S0;
    V0 = A3 | V0;
    [S5] = h(V0);
    [800F83FA + S1] = h(S3);

    A0 = S0;
    A1 = 2;
    A2 = 0;
    funca6000;

    800A21B0	srav   v0, s0, fp
    800A21B4	andi   v0, v0, $0001
    800A21B8	beq    v0, zero, La2214 [$800a2214]
    800A21BC	slti   v0, attacker_id, $0004
    if (V0 == 0)
    {
        A0 = S0;
        A1 = 2;
        funca5bc8;
    }

    V0 = hu[800F83A4 + 2E];
    if (V0 & 0004)
    {
        [800F83E0 + S1 + 1E] = h(S3);
        A1 = 5;
    }
    else
    {
        [800F83E0 + S1 + 1C] = h(S3);
        A1 = 4;
    }

    A0 = S0;
    A2 = 0;
    funca6000;
}

La2214:	; 800A2214
800A2214	addiu  s0, s0, $0001

La2218:	; 800A2218
800A2218	slti   v0, s0, $000a
800A221C	bne    v0, zero, loopa2110 [$800a2110]
800A2220	addiu  s1, s1, $0068
800A2224	jal    funca2894 [$800a2894]
800A2228	nop
800A222C	lui    v0, $8015
800A2230	lw     v0, $17b8(v0)
800A2234	nop
800A2238	beq    v0, zero, La2250 [$800a2250]
800A223C	addiu  v0, v0, $ffff (=-$1)
800A2240	lui    at, $8015
800A2244	sw     v0, $17b8(at)
800A2248	j      La228c [$800a228c]
800A224C	nop

La2250:	; 800A2250
800A2250	lbu    v0, $0000(attack_stack_offset)
800A2254	nop
800A2258	sltiu  v0, v0, $0003
800A225C	beq    v0, zero, La228c [$800a228c]
800A2260	sll    v1, attacker_id, $04
800A2264	addu   v1, v1, attacker_id
800A2268	sll    v1, v1, $02
800A226C	lui    at, $800f
800A2270	addu   at, at, v1
800A2274	lbu    v0, $5be2(at)
800A2278	nop
800A227C	addiu  v0, v0, $0001
800A2280	lui    at, $800f
800A2284	addu   at, at, v1
800A2288	sb     v0, $5be2(at)

La228c:	; 800A228C
return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funca8e54
address = w[80063014];

[address + f8] = w(A0);
A0 = A0 + 3;
[address + ac] = w(A0);
if (A0 >= 9)
{
    [address + ac] = w(8);
}

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funca2bf4
// A0 - attacker_id (unit id)
address = w[80063014];
V1 = w[address + c];

T0 = 0; // skip records
A1 = 0; // number of records

switch (V1)
{
    case 0x2 0x15: // magic
        T0 = 0;
        A1 = 38;
    break;

    case 0x3 0x16: // summon
        T0 = 38;
        A1 = 10;
    break;

    case 0xD: // enemy skill
        T0 = 48;
        A1 = 18;
    break;
}

if (A1 == 0)
{
    return;
}

attack_index = w[address + 10];

V1 = 0;
loopa2c94:	; 800A2C94
    V0 = bu[8009d84c + A0 * 440 + 108 + (V1 + T0) * 8];

    if (V0 == attack_index)
    {
        [address + 14] = w(A0);
        return;
    }

    V1 = V1 + 1;
    V0 = V1 < A1;
800A2CB0	bne    v0, zero, loopa2c94 [$800a2c94]

return;
////////////////////////////////////////////////////




////////////////////////////////////////////////////
// funca304c
A0 = 9;
V0 = SP + 24;
loopa305c:	; 800A305C
    [V0] = w(-1);
    A0 = A0 - 1;
    V0 = V0 - 4;
800A3064	bgez   a0, loopa305c [$800a305c]

T0 = w[800f3948];
if (T0 > 0)
{
    A0 = 0;
    loopa308c:	; 800A308C
        target_id = b[800fa9d0 + A0 * c + 0];
        if (target_id != -1)
        {
            V0 = hu[800fa9d0 + A0 * c  + 4];
            if (V0 & 0004)
            {
                V0 = w[SP + target_id * 4]
                if (V0 != -1)
                {
                    [800fa9d0 + V0 * c + 4] = h(hu[800fa9d0 + V0 * c + 4] & fffb);
                }
                [SP + target_id * 4] = w(A0);
            }
        }

        A0 = A0 + 1;
        V0 = A0 < T0;
    800A3108	bne    v0, zero, loopa308c [$800a308c]
}
////////////////////////////////////////////////////