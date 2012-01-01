////////////////////////////////
// main action function
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
                        if( w[address + 90] & 00000200 ) // if there no target for player of more than one
                        {
                            V0 = bu[8009d84c + attacker_id * 440 + 4c + S0 * 6 + 4];
                            if( V0 != 0 )
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
    battle_add_string_to_display;

    V0 = bu[800F5BB8 + attacker_id * 44 + 29];
    V0 = V0 & fb;
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
        action_type_1C; // set morph (power modifier to 2)
        action_type_09; // calculate and apply damage
    }
    break;

    //death blow
    case 0x0A:
    {
        action_type_0E; // load player attack data based on equipped weapon
        action_type_1B; // set death blow (set cricical and reduce hit% by 3)
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
        action_type_06;
        action_type_0C; // load attack data
        action_type_09; // calculate and apply damage
    }
    break;

    // 2x-cut
    case 0x19:
    {
        action_type_12; // set number of attacks to 2
        action_type_0E; // load player attack data based on equipped weapon
        action_type_09; // calculate and apply damage
    }
    break;

    // flash
    case 0x1A:
    {
        action_type_0E; // load player attack data based on equipped weapon
        action_type_18; // set flash attack (reduce hit% by 2, damage formula 0xb0, add death status and non missable status infliction)
        action_type_09; // calculate and apply damage
    }
    break;

    // 4x cut
    case 0x1B:
    {
        action_type_10; // set number of attacks to 4
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



// for players
if( attacker_id < 3 )
{
    action_id = w[address + c];
    if( action_id != c )
    {
        if( action_id < 20 )
        {
            A3 = bu[800f5bb8 + attacker_id * 44 + 2a];
            A2 = 0;

            loopa1f18:	; 800A1F18
                if( bu[attack_stack_offset] != 3 )
                {
                    if( ( b[800f6b84 + A2 * 8 + 2] != attacker_id ) || ( bu[800f6b85 + A2 * 8] != A3 ) || ( action_id < 15 ) )
                    {
                        [800f6b84 + A2 * 8 + 1] = b(A3); // order
                        [800f6b84 + A2 * 8 + 2] = b(attacker_id);
                        [800f6b84 + A2 * 8 + 3] = b(action_id);
                        [800f6b84 + A2 * 8 + 4] = b(w[address + 10]); // attack index
                        [800f6b84 + A2 * 8 + 6] = b(w[address + 94]); // attack mask
                        [800f7dda + A2 * 2] = h(w[address + f0]);

                        V0 = w[address + f8] << 8;
                        if( V0 != 0 )
                        {
                            [800f7dda + A2 * 2] = h(w[address + f0] | V0);
                        }

                        A2 = A2 + 1;
                        if( A2 < 2 )
                        {
                            [800f6b84 + A2 * 8 + 2] = b(-1);
                        }
                        break;
                    }
                }

                A2 = A2 + 1;
                V0 = A2 < 2;
            800A2020	bne    v0, zero, loopa1f18 [$800a1f18]
        }
    }
}



if( w[address + 90] & 0800 ) // add cut execution to priority queue
{
    A0 = attacker_id;
    A1 = 3;
    A2 = 1;
    A3 = 0;
    A4 = w[address + 94];
    battle_add_action_to_battle_queue;
}



if( w[address + 28] == 6 ) // action id == sense
{
    [address + 78] = w(0);
    [address + a8] = w(0);
}



S0 = 0;
S3 = 1 << attacker_id;
S1 = 0;
[800f83d2] = h(w[address + 6c]);
[800f83a4] = b(w[address + c]);
[800f83a5] = b(w[address + 10]);
[800f83ce] = h(w[address + 2c]);
[800f83c8] = h(w[address + 44]);

mask1 = w[address + 78] & (hu[800f7de0] NOR hu[800f7dcc]);
mask2 = w[address + a8] & hu[800f7de0];
mask3 = w[address + 7c] & hu[800f7de0];

loopa2110:	; 800A2110
    if( ( mask3 >> S0 ) & 1 )
    {
        [800f83e0 + S1 + 1a] = h(S3);

        A0 = attacker_id;
        A1 = S0;
        A2 = 0;
        funca6278;
    }
    else
    {
        if( ( mask1 >> S0 ) & 1 )
        {
            if( ( ( S3 >> S0 ) & 1 ) == 0 )
            {
                if( w[800f83e0 + S1] & 02404404 )
                {
                    [800f7dd8] = h(hu[800f7dd8] | (1 << S0));
                    [800f83e0 + S1 + 1a] = h(S3);

                    A0 = S0;
                    A1 = 2;
                    A2 = 0;
                    funca6000; // run counter script

                    if( mask2 >> S0 & 1 )
                    {
                        if( attacker_id >= 4 )
                        {
                            A0 = S0;
                            A1 = 2;
                            funca5bc8; // counter attack
                        }

                        if( hu[800f83a4 + 2e] & 0004 )
                        {
                            [800f83e0 + S1 + 1e] = h(S3);
                            A1 = 5;
                        }
                        else
                        {
                            [800f83e0 + S1 + 1c] = h(S3);
                            A1 = 4;
                        }

                        A0 = S0;
                        A2 = 0;
                        funca6000; // run magical or physical counter script
                    }
                }
            }
        }
    }

    S0 = S0 + 1;
    S1 = S1 + 68;
    V0 = S0 < a;
800A221C	bne    v0, zero, loopa2110 [$800a2110]



funca2894; // lucky 7777



V0 = w[801517b8];
if( V0 != 0 )
{
    [801517b8] = w(V0 - 1);
}
else if( attacker_id < 3 )
{
    [800f5bb8 + attacker_id * 44 + 2a] = b(bu[800f5bb8 + attacker_id * 44 + 2a] + 1)
}
////////////////////////////////



////////////////////////////////
// funca6278
800A6280	addu   s1, a0, zero
800A6288	addu   s0, a1, zero
800A6290	addu   s5, a2, zero
800A6298	addu   s3, zero, zero
800A629C	slti   v0, s0, $0004
800A62A8	bne    v0, zero, La6324 [$800a6324]

800A62B0	sll    v0, s0, $04
800A62B4	addu   v0, v0, s0
800A62B8	sll    a0, v0, $02
800A62BC	lui    at, $800f
800A62C0	addu   at, at, a0
800A62C4	lbu    v1, $5be1(at)
800A62C8	nop
800A62CC	andi   v0, v1, $0020
800A62D0	bne    v0, zero, La6328 [$800a6328]
800A62D4	sll    v0, s0, $01
800A62D8	ori    v0, v1, $0020
800A62DC	lui    at, $800f
800A62E0	addu   at, at, a0
800A62E4	sb     v0, $5be1(at)
800A62E8	slti   v0, s1, $0003
800A62EC	beq    v0, zero, La6324 [$800a6324]
800A62F0	sll    v0, s1, $01
800A62F4	addu   v0, v0, s1
800A62F8	sll    v0, v0, $02
800A62FC	addu   v0, v0, s1
800A6300	sll    v0, v0, $02
800A6304	lui    at, $800f
800A6308	addu   at, at, v0
800A630C	lbu    v1, $5e67(at)
800A6310	nop
800A6314	addiu  v1, v1, $0001
800A6318	lui    at, $800f
800A631C	addu   at, at, v0
800A6320	sb     v1, $5e67(at)

La6324:	; 800A6324
800A6324	sll    v0, s0, $01

La6328:	; 800A6328
800A6328	addu   v0, v0, s0
800A632C	sll    v0, v0, $02
800A6330	addu   v0, v0, s0
800A6334	sll    s2, v0, $03
V1 = w[800F83E4 + S2];
V0 = V1 & 00002000;
if (V0 == 0)
{
    800A6354	lui    s4, $800f
    800A6358	lbu    s4, $6b9b(s4)
    V0 = V1 | 00002000;
    [800F83E4 + S2] = w(V0);
    800A636C	slti   v0, s1, $0004
    800A6370	bne    v0, zero, La6380 [$800a6380]
    800A6374	addu   a0, s0, zero
    800A6378	jal    funca5bc8 [$800a5bc8]
    800A637C	addu   a1, zero, zero

    La6380:	; 800A6380
    800A6380	beq    s1, s0, La63a0 [$800a63a0]
    800A6384	ori    v0, zero, $0001
    800A6388	sllv   v0, s1, v0
    800A638C	lui    at, $8010
    800A6390	addu   at, at, s2
    800A6394	sh     v0, $83fa(at)
    800A6398	j      La63b0 [$800a63b0]
    800A639C	addu   a0, s0, zero

    La63a0:	; 800A63A0
    800A63A0	lui    at, $8010
    800A63A4	addu   at, at, s2
    800A63A8	sh     zero, $83fa(at)
    800A63AC	addu   a0, s0, zero

    La63b0:	; 800A63B0
    800A63B0	ori    a1, zero, $0003
    800A63B4	jal    funca6000 [$800a6000] // run script 3
    800A63B8	addu   a2, zero, zero
    800A63BC	lui    v0, $800f
    800A63C0	lbu    v0, $6b9b(v0)
    800A63C4	nop
    800A63C8	bne    v0, s4, La63d8 [$800a63d8]
    800A63CC	nop
    800A63D0	beq    s5, zero, La6430 [$800a6430]
    800A63D4	sll    v0, s0, $01

    La63d8:	; 800A63D8
    800A63D8	sll    v0, s0, $01
    800A63DC	addu   v0, v0, s0
    800A63E0	sll    v0, v0, $02
    800A63E4	addu   v0, v0, s0
    800A63E8	sll    v0, v0, $03
    800A63EC	lui    at, $8010
    800A63F0	addu   at, at, v0
    800A63F4	lw     v0, $83e4(at)
    800A63F8	nop
    800A63FC	andi   v0, v0, $1000
    800A6400	bne    v0, zero, La642c [$800a642c]
    800A6404	ori    s3, zero, $0001
    800A6408	ori    v0, zero, $0001
    800A640C	sllv   v0, s0, v0
    800A6410	lui    at, $8010
    800A6414	sh     v0, $83b2(at)
    800A6418	addu   a0, s0, zero
    800A641C	ori    a1, zero, $0025
    800A6420	jal    funcb2b5c [$800b2b5c]
    800A6424	addu   a2, zero, zero
    800A6428	ori    s3, zero, $0001

    La642c:	; 800A642C
}

La6430:	; 800A6430
800A6350	sll    v0, s0, $01
800A6430	addu   v0, v0, s0
800A6434	sll    v0, v0, $02
800A6438	addu   v0, v0, s0
800A643C	sll    v0, v0, $03
800A6440	lui    at, $8010
800A6444	addu   at, at, v0
800A6448	lw     v0, $83e4(at)
800A644C	nop
800A6450	andi   v0, v0, $1000
800A6454	beq    v0, zero, La6460 [$800a6460]
800A6458	nop
800A645C	ori    s3, zero, $0001

La6460:	; 800A6460
800A6460	beq    s3, zero, La6478 [$800a6478]
800A6464	nop
800A6468	bne    s5, zero, La6478 [$800a6478]
800A646C	nop
800A6470	jal    funca3488 [$800a3488]
800A6474	addu   a0, s0, zero

La6478:	; 800A6478
800A6478	lw     ra, $0028(sp)
800A647C	lw     s5, $0024(sp)
800A6480	lw     s4, $0020(sp)
800A6484	lw     s3, $001c(sp)
800A6488	lw     s2, $0018(sp)
800A648C	lw     s1, $0014(sp)
800A6490	lw     s0, $0010(sp)
800A6494	addiu  sp, sp, $0030
800A6498	jr     ra 
800A649C	nop
////////////////////////////////



////////////////////////////////
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
////////////////////////////////



////////////////////////////////
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
////////////////////////////////



////////////////////////////////
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
////////////////////////////////
