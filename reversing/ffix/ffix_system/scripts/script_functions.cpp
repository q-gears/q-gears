////////////////////////////////
// system_save_from_stack_command_not_from_script
S7 = w[8007b6f0];
func51e8c;
[8007b6f0] = w(S7);
////////////////////////////////



////////////////////////////////
// func37738
A1 = w[8007b6f0];
A0 = w[A1 - 8];
V0 = (A0 >> 1a) & 7;
S1 = 0;
if (V0 != 5)
{
    [8007b6f0] = w(A1 - 4);
    system_read_from_stack_command_not_from_script;
    A0 = V0;
    A1 = 0;
    [8007b6f0] = w(w[8007b6f0] - 8);
}
else
{
    S0 = A0 & 7;
    if (S0 == 2)
    {
        A0 = 0;
        battle_get_units_mask;
        [8007ae14] = h(V0);
    }
    else if (S0 == 3)
    {
        A0 = 1;
        battle_get_units_mask;
        [8007ae16] = h(V0);
    }
    else if (S0 == 4)
    {
        A0 = 2;
        battle_get_units_mask;
        [8007ae18] = h(V0);
    }

    A0 = hu[8007ae10 + S0 * 2]
    A1 = 0;
}

if ((A0 & 1) == 0)
{
    A1 = 1;
    A0 = A0 >> 1;
    if ((A0 & 1) == 0)
    {
        loop3783c:	; 8003783C
            A1 = A1 + 1;
            if (A1 >= 8)
            {
                [8007b6f0] = w(w[8007b6f0] - 8);
                return 0;
            }

            A0 = A0 >> 1;
            V0 = A0 & 1;
        8003784C	beq    v0, zero, loop3783c [$8003783c]
    }
}

if (A1 < 8)
{
    [8007b700] = w(w[8007aed0 + A1 * 4]);
    system_read_from_stack_command_not_from_script;
    S1 = V0;
}
else
{
    [8007b6f0] = w(w[8007b6f0] - 4);
}

[8007b6f0] = w(w[8007b6f0] - 4);

return S1;
////////////////////////////////



////////////////////////////////
// system_pick_random_active_bit

system_read_from_stack_command_not_from_script;
A0 = V0;

S0 = 0;
V1 = 0;
loop4b5f0:	; 8004B5F0
    if (A0 & 1)
    {
        [SP + 10 + S0] = b(V1);
        S0 = S0 + 1;
    }

    V1 = V1 + 1;
    A0 = A0 >> 1;
    V0 = V1 < 8;
8004B60C	bne    v0, zero, loop4b5f0 [$8004b5f0]

if (S0 == 0)
{
    return 0;
}

if (w[8007b720] >= 8007b92d)
{
    system_reset_random;
}

V1 = w[8007b720];
V0 = (S0 * bu[V1]) >> 8;
[8007b720] = w(V1 + 1);

return 1 << bu[SP + 10 + V0];
////////////////////////////////



////////////////////////////////
// system_count_bits_in_pop_stack
S0 = 0;
system_read_from_stack_command_not_from_script;
A0 = V0;

V1 = 1;

loop4b594:	; 8004B594
    S0 = S0 + ((A0 & V1) == true);
    V1 = V1 << 1;
    V1 = V1 & 0000ffff;
8004B5B0	bne    v1, zero, loop4b594 [$8004b594]

return S0;
////////////////////////////////



////////////////////////////////
// func27f34
V0 = w[8006794c];
V1 = w[V0 + 1c] + 574;

T0 = 0;

A1 = 0;
loop27f4c:	; 80027F4C
    if ((bu[V1 + 1] != 0) && (bu[V1 + 0] == A0))
    {
        T0 = V1;
        break;
    }
    A1 = A1 + 1;
    V1 = V1 + 2;
    V0 = A1 < 100;
80027F74	bne    v0, zero, loop27f4c [$80027f4c]

if (T0 != 0)
{
    return bu[T0 + 1];
}

return 0;
////////////////////////////////



////////////////////////////////
// func281a4
V0 = w[8006794c];
V0 = w[V0 + 1c];
return (bu[V0 + 774 + A0 >> 2] >> ((A0 & 3) << 1)) & 1;
////////////////////////////////



////////////////////////////////
// func62560
A2 = 0;

A1 = 0;
loop62574:	; 80062574
    if (bu[8008324e + A1 * 6] == A0)
    {
        A2 = A2 + 1;
    }

    A1 = A1 + 1;
    V0 = A1 < 69;
80062590	bne    v0, zero, loop62574 [$80062574]

return A2;
////////////////////////////////



////////////////////////////////
// func50068
[8007bbec] = w(1);
[8007bbf4] = w(A0);
////////////////////////////////



////////////////////////////////
// func4b040
// get pointer to allocated memory
V0 = w[8007aecc];
V1 = w[V0 + 16d8]; // first element in script list
if (V1 != 0)
{
    loop4b05c:	; 8004B05C
        V0 = w[V1 + 4];
        if (bu[V0 + 7] == A0)
        {
            break;
        }

        V1 = w[V1 + 0];
    8004B07C	bne    v1, zero, loop4b05c [$8004b05c]
}

if (V1 != 0)
{
    return w[V1 + 4];
}

return 0;
////////////////////////////////



////////////////////////////////
// func52834
V0 = S5 & 1;
S5 = S5 >> 1;
if (V0 == 0)
{
    S6 = S6 + 1;
    return bu[S6];
}
else
{
    system_script_parse_stack;

    system_read_from_stack_command_from_script;

    return V0;
}
////////////////////////////////



////////////////////////////////
// func4ec98
V0 = h[8007b9c0 + A0 * 2c + 8];
////////////////////////////////



////////////////////////////////
// func38278

entity_scripts_settings = w[8007adf8];
scripting_system        = w[8007aecc];

entity_struct = A0; // pointer to allocated memory



if (bu[entity_struct + a] >= 2) // if there is yielded scripts
{
    A1 = entity_struct + bu[entity_struct + 9] * 4 + bu[entity_struct + a] * 4 - 4;
    stored_script_settings = w[A1];

    V0 = w[entity_struct + 4];
    if ((V0 & ff0000ff) == 0) // if priority and memory share id == 0
    {
        A0 = w[scripting_system + 16d8];
        if (A0 != 0)
        {
            loop382e4:	; 800382E4
                V1 = w[A0 + 4];
                if (bu[V1 + 7] != 0)
                {
                    [V1 + e] = b(bu[V1 + 12]);
                }

                A0 = w[A0];
            80038310	bne    a0, zero, loop382e4 [$800382e4]
        }
    }

    [entity_struct + a] = b(bu[entity_struct + a] - 2); // reduce yielded scripts stack

    [entity_struct + d] = b(stored_script_settings); // restore wait
    [entity_struct + 4] = b(stored_script_settings >> 8); // restore priority
    [entity_struct + 0] = w(w[scripting_system + 16f0] + w[A1 - 4]); // restore script pointer

    V0 = ( stored_script_settings >> 10 ) & ff;
    if (V0 == ff) // it there is no scripts that paused just finish
    {
        return;
    }

    V1 = w[scripting_system + 16d8];
    if (V1 != 0)
    {
        A0 = stored_script_settings >> 18;

        loop38374:	; 80038374
            V0 = w[V1 + 4];
            if (bu[V0 + 7] == A0)
            {
                break;
            }

            V1 = w[V1];
        80038394	bne    v1, zero, loop38374 [$80038374]
    }

    A0 = 0;
    if (V1 != 0)
    {
        A0 = w[V1 + 4];
    }

    if (A0 == 0)
    {
        return;
    }

    if (bu[A0 + d] == ff) // unpause and return
    {
        [A0 + d] = b(0);
        return;
    }

    if (bu[A0 + a] * 4 - 4 <= 0) // if there is no yielded scripts that mean script unpause somehow and we not need to unpause it
    {
        return;
    }

    // search for maused yielded scripts
    A0 = A0 + bu[A0 + 9] * 4;
    A1 = A0 + bu[A0 + a] * 4 - 4;
    loop383f4:	; 800383F4
        if (bu[A1 + 0] == ff)
        {
            break;
        }
        A1 = A1 - 8;
        V0 = A0 < A1;
    8003840C	bne    v0, zero, loop383f4 [$800383f4]

    if (A0 >= A1) // if we didn't found any - return
    {
        return;
    }

    [A1 + 0] = w(w[A1 + 0] & ffffff00); // unpause founded yielded script
    return;
}



if (bu[entity_struct + e] == 2) // if script is runned then we stop it and run script 1 with lowest priority
{
    [entity_struct + e] = b(1);

    entity_id = bu[entity_struct + 6];
    V1 = entity_scripts_settings + hu[entity_scripts_settings + entity_id * 8];
    number_of_scripts = hu[V1] >> 8;

    A0 = V1 + 2;

    if (number_of_scripts != 0)
    {
        loop38478:	; 80038478
            if (hu[A0] == 1)
            {
                A0 = A0 + 2;
                break;
            }

            A0 = A0 + 2;
            number_of_scripts = number_of_scripts - 1;
        8003848C	bne    number_of_scripts, zero, loop38478 [$80038478]

        if (number_of_scripts != 0)
        {
            V1 = V1 + hu[A0] + 2;
        }
        else
        {
            V1 = 0;
        }
    }
    else
    {
        V1 = 0;
    }

    [entity_struct + 0] = w(V1);
    [entity_struct + 4] = b(7);
    return;
}

[entity_struct + 0] = w(0);
////////////////////////////////



////////////////////////////////
// func384d0
// run script
// A3 = 0; pause current script or not

entity_scripts_settings = w[8007adf8];
scripting_system        = w[8007aecc];

entity_struct   = A0;
priority        = A1;
script_to_start = A2;

script_pointer  = 0;

if (entity_struct != 0)
{
    if (priority < bu[entity_struct + 4])
    {
        entity_id = bu[entity_struct + 6];
        V1 = entity_scripts_settings + hu[entity_scripts_settings + entity_id * 8];
        number_of_scripts = hu[V1] >> 8;

        A0 = V1 + 2;

        if (number_of_scripts != 0)
        {
            loop38524:	; 80038524
                if (hu[A0] == script_to_start)
                {
                    break;
                }

                A0 = A0 + 4;
                number_of_scripts = number_of_scripts - 1;
            80038538	bne    number_of_scripts, zero, loop38524 [$80038524]

            if (number_of_scripts != 0)
            {
                script_pointer = V1 + hu[A0] + 4;
            }
        }

        if (script_pointer != 0)
        {
            A2 = entity_struct + bu[entity_struct + 9] * 4 + bu[entity_struct + a] * 4;

            [A2 + 0] = w(w[entity_struct + 0] - w[scripting_system + 16f0]);

            A1 = w[8007b70c];

            if (A3 != 0)
            {
                [A2 + 4] = w((bu[A1 + 7] << 18) | (bu[A1 + 4] << 10) | (bu[entity_struct + 4] << 8) | bu[entity_struct + d]);
            }
            else
            {
                [A2 + 4] = w((bu[A1 + 7] << 18) | 00ff0000           | (bu[entity_struct + 4] << 8) | bu[entity_struct + d]);
            }

            if (A3 != 0)
            {
                V1 = w[8007b70c];
                [V1 + d] = b(ff); // pause script
            }

            [entity_struct + 0] = w(script_pointer);
            [entity_struct + 4] = b(priority);
            [entity_struct + a] = b(bu[entity_struct + a] + 2); // increment runned script stack
            [entity_struct + d] = b(0); // set pause to 0
        }
    }
}

return script_pointer != 0;
////////////////////////////////



////////////////////////////////
// func4bb30
A1 = 8007aed0;

V1 = 0;
loop4bb3c:	; 8004BB3C
    V0 = w[A1];
    if (V0 == A0)
    {
        break;
    }
    A1 = A1 + 4;

    V1 = V1 + 1;
    V0 = V1 < 8;
8004BB54	bne    v0, zero, loop4bb3c [$8004bb3c]

if (V1 < 8)
{
    [8007ae12] = h(1 << V1);
}
////////////////////////////////



/////////////////////////////////////////////////////
// func37d6c
if (A0 < 20)
{
DC7D0380 1
287E0380 4
387E0380 5
E87E0380 7
F87E0380 8
187F0380 a
287F0380 b
587F0380 e
887F0380 10
A87F0380 11
B87F0380 12
D87F0380 14
04800380 15
14800380 16
24800380 17
34800380 18
54800380 19
7C800380 1b
9C800380 1c
B4800380 1d
C4800380 1e
EC800380 1f

    V0 = w[80011594 + A0 * 4];
    80037D98	jr     v0 

    case 0: // A07D0380
    {
        if (w[8007b720] >= 8007b92d)
        {
            system_reset_random;
        }

        V0 = w[8007b720];
        V1 = bu[V0];
        [8007b720] = w(V0 + 1);

        return V1;
    }
    break;

    80037DDC	jal    funcc1b5c [$800c1b5c]
    80037DE0	addiu  a0, sp, $0018
    80037DE4	lbu    v1, $0018(sp)
    80037DE8	j      L3813c [$8003813c]
    80037DEC	nop

    case 2: // F07D0380
    {
        V0 = w[8007aecc];
        return bu[V0 + 16ec];
    }

    case 3: // 087E0380
    {
        A0 = c00;
        A1 = ffffffff;
        A2 = 0;
        A3 = 0;
        A4 = 0;
        funcb0124;

        return V0;
    }

    case 6: // C87E0380
    {
        V0 = w[8006794c];
        V0 = w[V0 + 1c];
        return w[V0 + 560];
    }
    break;

    case 9: // 087F0380
    {
        func4ecc4;
        return V0;
    }
    break;

    case c: // 387F0380
    {
        return w[8007ae2c];
    }
    break;

    case d: // 487F0380
    {
        return w[8007ae30];
    }
    break;

    case f: // 707F0380
    {
        A0 = 3;
        A1 = 0;
        A2 = 0;
        funcad944;

        return V0;
    }
    break;

    case 13: // C87F0380
    {
        func625f8;
        return v0;
    }
    break;

    80037E28	lui    v0, $8008
    80037E2C	lw     v1, $ae20(v0)
    80037E30	j      L3813c [$8003813c]
    80037E34	nop
    80037E38	lui    v1, $8008
    80037E3C	lui    v0, $8008
    80037E40	lw     v0, $aecc(v0)
    80037E44	lw     a0, $b70c(v1)
    80037E48	lw     a1, $16d8(v0)
    80037E4C	lbu    v1, $000a(a0)
    80037E50	lbu    v0, $0009(a0)
    80037E54	sll    v1, v1, $02
    80037E58	sll    v0, v0, $02
    80037E5C	addu   v0, v0, a0
    80037E60	addu   v1, v1, v0
    80037E64	lbu    v1, $ffff(v1)
    80037E68	beq    a1, zero, L37e98 [$80037e98]
    80037E6C	nop

    loop37e70:	; 80037E70
    80037E70	lw     v0, $0004(a1)
    80037E74	nop
    80037E78	lbu    v0, $0007(v0)
    80037E7C	nop
    80037E80	beq    v0, v1, L37e98 [$80037e98]
    80037E84	nop
    80037E88	lw     a1, $0000(a1)
    80037E8C	nop
    80037E90	bne    a1, zero, loop37e70 [$80037e70]
    80037E94	nop

    L37e98:	; 80037E98
    80037E98	beq    a1, zero, L37ea4 [$80037ea4]
    80037E9C	addu   a0, zero, zero
    80037EA0	lw     a0, $0004(a1)

    L37ea4:	; 80037EA4
    80037EA4	nop
    80037EA8	beq    a0, zero, L3813c [$8003813c]
    80037EAC	addiu  v1, zero, $ffff (=-$1)
    80037EB0	lui    v0, $8008
    80037EB4	lbu    v1, $0006(a0)
    80037EB8	lw     v0, $adfc(v0)
    80037EBC	addiu  v1, v1, $0009
    80037EC0	j      L3813c [$8003813c]
    80037EC4	subu   v1, v1, v0

    80037EE8	lui    v0, $8008
    80037EEC	lw     v1, $aec4(v0)
    80037EF0	j      L3813c [$8003813c]
    80037EF4	nop
    80037EF8	lui    v0, $8008
    80037EFC	lw     v1, $bbd8(v0)
    80037F00	j      L3813c [$8003813c]
    80037F04	nop

    80037F18	lui    v0, $8008
    80037F1C	lw     v1, $ae24(v0)
    80037F20	j      L3813c [$8003813c]
    80037F24	nop
    80037F28	lui    v0, $8008
    80037F2C	lw     v1, $ae28(v0)
    80037F30	j      L3813c [$8003813c]
    80037F34	nop

    80037F58	addiu  a0, zero, $0004
    80037F5C	addu   a1, zero, zero
    80037F60	jal    funcad944 [$800ad944]
    80037F64	addu   a2, a1, zero
    80037F68	j      L3813c [$8003813c]
    80037F6C	addu   v1, v0, zero

    80037F88	lui    v0, $8006
    80037F8C	lw     v0, $794c(v0)
    80037F90	nop
    80037F94	lw     v0, $001c(v0)
    80037F98	nop
    80037F9C	lh     v1, $0568(v0)
    80037FA0	j      L3813c [$8003813c]
    80037FA4	nop
    80037FA8	jal    func2414c [$8002414c]
    80037FAC	nop
    80037FB0	j      L3813c [$8003813c]
    80037FB4	addu   v1, v0, zero
    80037FB8	jal    func6275c [$8006275c]
    80037FBC	nop
    80037FC0	j      L3813c [$8003813c]
    80037FC4	addu   v1, v0, zero

    80037FD8	jal    func24048 [$80024048]
    80037FDC	nop
    80037FE0	addu   v1, v0, zero
    80037FE4	lui    v0, $007f
    80037FE8	ori    v0, v0, $ffff
    80037FEC	slt    v0, v0, v1
    80037FF0	beq    v0, zero, L3813c [$8003813c]
    80037FF4	nop
    80037FF8	lui    v1, $007f
    80037FFC	j      L3813c [$8003813c]
    80038000	ori    v1, v1, $ffff
    80038004	jal    func240e8 [$800240e8]
    80038008	nop
    8003800C	j      L3813c [$8003813c]
    80038010	andi   v1, v0, $00ff
    80038014	lui    v0, $8008
    80038018	lw     v1, $ae38(v0)
    8003801C	j      L3813c [$8003813c]
    80038020	nop
    80038024	lui    v0, $8008
    80038028	lw     v1, $ae3c(v0)
    8003802C	j      L3813c [$8003813c]
    80038030	nop
    80038034	lui    v0, $8006
    80038038	lw     v0, $794c(v0)
    8003803C	nop
    80038040	lw     v0, $001c(v0)
    80038044	nop
    80038048	lh     v1, $000e(v0)
    8003804C	j      L3813c [$8003813c]
    80038050	nop
    80038054	jal    funcca774 [$800ca774]
    80038058	nop
    8003805C	j      L3813c [$8003813c]
    80038060	andi   v1, v0, $00ff



    case 1a:
    {
        return w[8007b708] == 4;
    }
    break;



    8003807C	lui    v0, $8006
    80038080	lw     v0, $794c(v0)
    80038084	nop
    80038088	lw     v0, $001c(v0)
    8003808C	nop
    80038090	lbu    v1, $056e(v0)
    80038094	j      L3813c [$8003813c]
    80038098	nop
    8003809C	lui    v0, $8008
    800380A0	lw     v0, $ae34(v0)
    800380A4	nop
    800380A8	sra    v0, v0, $08
    800380AC	j      L3813c [$8003813c]
    800380B0	andi   v1, v0, $00ff
    800380B4	lui    v0, $8008
    800380B8	lbu    v1, $ae34(v0)
    800380BC	j      L3813c [$8003813c]
    800380C0	nop
    800380C4	lui    v0, $8006
    800380C8	lw     v0, $794c(v0)
    800380CC	nop
    800380D0	lw     v0, $001c(v0)
    800380D4	nop
    800380D8	lw     v0, $08e4(v0)
    800380DC	nop
    800380E0	lbu    v1, $0d80(v0)
    800380E4	j      L3813c [$8003813c]
    800380E8	nop
    800380EC	lui    v0, $8006
    800380F0	lw     v0, $794c(v0)
    800380F4	nop
    800380F8	lw     v0, $001c(v0)
    800380FC	nop
    80038100	lw     v0, $08e4(v0)
    80038104	nop
    80038108	lbu    v1, $1340(v0)
    8003810C	j      L3813c [$8003813c]
    80038110	nop
}

80038114	slti   v0, a0, $00c0
80038118	bne    v0, zero, L38130 [$80038130]
8003811C	nop
80038120	jal    funcb7a14 [$800b7a14]
80038124	nop
80038128	j      L3813c [$8003813c]
8003812C	addu   v1, v0, zero

L38130:	; 80038130
80038130	jal    funcbe784 [$800be784]
80038134	nop
80038138	addu   v1, v0, zero

L3813c:	; 8003813C
return V1;
////////////////////////////////



////////////////////////////////
// func51e8c
// save
S7 = S7 - 4;
T0 = w[S7];

A3 = A0;
A2 = T0 >> 1a;

if (A2 & 4)
{
    if (A2 & 2)
    {
        80051EEC	lui    a0, $8008
        80051EF0	lw     a0, $b700(a0)
        80051EF4	andi   a1, t0, $00ff
        80051EF8	j      L4b7a4 [$8004b7a4]
        80051EFC	addu   a2, a3, zero
    }

    if (A2 & 1)
    {
        [8007ae10 + (T0 & 7) * 2] = h(A3);
    }
}
else
{
    if (A2 & 2)
    {
        A0 = w[8007bcf8];
    }
    else if (A2 & 1)
    {
        A0 = w[8007aecc];
    }
    else
    {
        A0 = 8007aef0;
    }

    A1 = T0 & ffff;
    if (A2 & 20)
    {
        if (A2 & 10)
        {
            [A0 + A1 + 0] = b(A3);
            [A0 + A1 + 1] = b(A3 >> 8);
        }
        else
        {
            [A0 + A1] = b(A3);
        }
    }
    else
    {
        if (A2 & 10)
        {
            A0 = A0 + A1;
            [A0] = b(A3);
            A3 = A3 >> 8;
            [A0 + 1] = b(A3);
            A3 = A3 >> 8;
            [A0 + 2] = b(A3);
        }
        else
        {
            value = b[A0 + A1 >> 3];
            if (A3 == 0)
            {
                A2 = 1 << (A1 & 7);
                A2 = A2 XOR ff;
                value = value & A2;
            }
            else
            {
                A2 = 1 << (A1 & 7);
                value = value | A2;
            }

            [A0 + A1 >> 3] = b(value);
        }
    }
}
////////////////////////////////



////////////////////////////////
// func51f18
V0 = A0 & 3;
V0 = V0 << 1a;
A1 = A0 & 1c;
A1 = A1 << 1b;
V0 = V0 | A1;
A1 = bu[S6];
S6 = S6 + 1;

if (A0 & 20)
{
    V0 = V0 | A1;
    A1 = bu[S6];
    S6 = S6 + 1;
    A1 = A1 << 8;
}

return V0 | A1;
////////////////////////////////



////////////////////////////////
// system_read_from_stack_command_from_script
// read
S7 = S7 - 4;
stack_value = w[S7];

A2 = stack_value >> 1a;
if ((A2 & 4) == 0)
{
    if (A2 & 2)
    {
        A0 = w[8007bcf8];
    }
    else if (A2 & 1)
    {
        A0 = w[8007aecc];
    }
    else
    {
        A0 = 8007aef0;
    }

    A1 = stack_value & ffff;
    if (A2 & 20)
    {
        if (A2 & 10)
        {
            if (A2 & 8)
            {
                return (bu[A0 + A1 + 1] << 8) | bu[A0 + A1 + 0];
            }
            else
            {
                return (b[A0 + A1 + 1] << 8) | bu[A0 + A1 + 0];
            }
        }
        else
        {
            if (A2 & 8)
            {
                return bu[A0 + A1];
            }
            else
            {
                return b[A0 + A1];
            }
        }
    }
    else
    {
        if (A2 & 10)
        {
            return (b[A0 + A1 + 2] << 10) | (bu[A0 + A1 + 1] << 8) | (bu[A0 + A1 + 0]);
        }
        else
        {
            return b[A0 + (A1 >> 3)] >> (A1 & 7) & 1;
        }
    }
}
if ((A2 & 2) == 0)
{
    if ((A2 & 1) == 0)
    {
        A0 = stack_value >> 8;
        A0 = A0 & ff;
        system_get_entity_script_data_pointer;

        A0 = V0;
        A1 = stack_value & ff;
        80051DB0	j      L4b68c [$8004b68c]
    }

    S0 = stack_value & 7;
    if (S0 == 4)
    {
        A0 = 2;
        battle_get_units_mask;
        [8007ae10 + S0 * 2] = h(V0);
        return V0;
    }
    elseif (S0 == 3)
    {
        A0 = 1;
        battle_get_units_mask;
        [8007ae10 + S0 * 2] = h(V0);
        return V0;
    }
    elseif (S0 == 2)
    {
        A0 = 0;
        battle_get_units_mask;
        [8007ae10 + S0 * 2] = h(V0);
        return V0;
    }
    else
    {
        return hu[8007ae10 + S0 * 2];
    }
}

stack_value = (stack_value << 6) >> 6;

if ((A2 & 1) == 0)
{
    A0 = w[8007b700];
    A1 = stack_value;

    L4b68c:	; 8004B68C
    S0 = A1;
    switch (S0)
    {
        case 0: return w[A0 + 14];
        case 1: return w[A0 + 18];
        case 2: return w[A0 + 1c];
        case 3: return (hu[A0 + 22] >> 4) & ff;
        case 4: return bu[A0 + f];
        case 5: return bu[A0 + 7];
        case 6: return bu[A0 + 4];
        case 7: return bu[A0 + 3a];
    }

    V1 = 0;
    loop4b740:	; 8004B740
        V0 = w[8007aed0 + V1 * 4];
        if (V0 == A0)
        {
            break;
        }

        V1 = V1 + 1;
        V0 = V1 < 8;
    8004B758	bne    v0, zero, loop4b740 [$8004b740]

    S1 = 0;
    if (V1 < 8)
    {
        A0 = (1 << V1) & ffff;
        battle_get_units_data_pointer_by_mask;
        if (V0 != 0)
        {
            A0 = V0;
            A1 = S0;
            funcbded4;

            S1 = V0;
        }
    }

    return S1;
}

return stack_value;
////////////////////////////////



////////////////////////////////
// system_get_entity_script_data_pointer
script = w[8007aecc];

if (A0 == ff)
{
    return w[8007b704];
}
if (A0 == fa)
{
    A0 = bu[script + 16ed];
}
else
{
    V1 = A0 - fb;
    if (V1 < 4)
    {
        A0 = bu[script + 16e4 + V1];
    }
}

V0 = w[8007aecc];
V1 = w[V0 + 16d8];
if (V1 != 0)
{
    loop4b538:	; 8004B538
        V0 = w[V1 + 4];
        if (bu[V0 + 7] == A0)
        {
            break;
        }

        V1 = w[V1 + 0];
    8004B558	bne    v1, zero, loop4b538 [$8004b538]
}

if (V1 == 0)
{
    return 0;
}

return w[V1 + 4];
////////////////////////////////



////////////////////////////////
// func52da0
S1 = w[8007b70c];
S6 = w[S1];
system_script_parse_stack;
////////////////////////////////



////////////////////////////////
// system_read_from_stack_command_not_from_script
S7 = w[8007b6f0];
system_read_from_stack_command_from_script;
[8007b6f0] = w(S7);
////////////////////////////////



////////////////////////////////
// system_get_entity_script_data_pointer_from_script
[8007b6f8] = w(1);

get8byte;
A2 = A0;

if (A2 == ff)
{
    V0 = w[8007b704];
}
else
{
    if (A2 == fa)
    {
        V0 = w[8007aecc];
        A2 = bu[V0 + 16ed];
    }
    else
    {
        V1 = A2 - fb;
        if (V1 < 4)
        {
            V0 = w[8007aecc];
            V0 = V0 + V1;
            A2 = bu[V0 + 16e4];
        }
    }

    V0 = w[8007aecc];
    V1 = w[V0 + 16d8];
    if (V1 != 0)
    {
        loop38234:	; 80038234
            V0 = w[V1 + 4];
            if (bu[V0 + 7] == A2)
            {
                break;
            }

            V1 = w[V1];
        80038254	bne    v1, zero, loop38234 [$80038234]
    }

    V0 = 0;
    if (V1 != 0)
    {
        V0 = w[V1 + 4];
    }
}

return V0;
////////////////////////////////