////////////////////////////////
// opcode_cycle
800BB3A8	addiu  sp, sp, $ffd0 (=-$30)
800BB3AC	lui    a1, $91a2
800BB3B0	lui    a0, $800a
800BB3B4	addiu  a0, a0, $d264 (=-$2d9c)
800BB3B8	sw     ra, $0028(sp)
800BB3BC	sw     s3, $0024(sp)
800BB3C0	sw     s2, $0020(sp)
800BB3C4	sw     s1, $001c(sp)
800BB3C8	sw     s0, $0018(sp)
800BB3CC	lw     v0, $0000(a0)
800BB3D0	ori    a1, a1, $b3c5
800BB3D4	multu  v0, a1
800BB3D8	mfhi   v0
800BB3DC	srl    v1, v0, $0b
800BB3E0	andi   v0, v1, $ffff
800BB3E4	sltiu  v0, v0, $0100
800BB3E8	bne    v0, zero, Lbb3f4 [$800bb3f4]
800BB3EC	addu   s1, zero, zero
800BB3F0	ori    v1, zero, $00ff

Lbb3f4:	; 800BB3F4
800BB3F4	lw     a0, $0000(a0)
800BB3F8	nop
800BB3FC	multu  a0, a1
800BB400	lui    at, $800a
800BB404	sb     v1, $d298(at)
800BB408	lui    a1, $8888
800BB40C	ori    a1, a1, $8889
800BB410	mfhi   v1
800BB414	srl    v1, v1, $0b
800BB418	sll    v0, v1, $03
800BB41C	subu   v0, v0, v1
800BB420	sll    v0, v0, $05
800BB424	addu   v0, v0, v1
800BB428	sll    v0, v0, $04
800BB42C	subu   v1, a0, v0
800BB430	andi   a0, v1, $ffff
800BB434	multu  a0, a1
800BB438	mfhi   v1
800BB43C	srl    v1, v1, $05
800BB440	sll    v0, v1, $04
800BB444	subu   v0, v0, v1
800BB448	sll    v0, v0, $02
800BB44C	subu   a0, a0, v0
800BB450	lui    at, $800a
800BB454	sb     v1, $d299(at)
800BB458	lui    v1, $800a
800BB45C	lbu    v1, $d29a(v1)
800BB460	andi   v0, a0, $ffff
800BB464	beq    v1, v0, Lbb484 [$800bb484]
800BB468	lui    a1, $91a2
800BB46C	lui    at, $800a
800BB470	sb     a0, $d29a(at)
800BB474	lui    at, $800a
800BB478	sb     zero, $d29b(at)
800BB47C	j      Lbb49c [$800bb49c]
800BB480	nop

Lbb484:	; 800BB484
800BB484	lui    v0, $800a
800BB488	lbu    v0, $d29b(v0)
800BB48C	nop
800BB490	addiu  v0, v0, $0001
800BB494	lui    at, $800a
800BB498	sb     v0, $d29b(at)

Lbb49c:	; 800BB49C
800BB49C	lui    a0, $800a
800BB4A0	addiu  a0, a0, $d268 (=-$2d98)
800BB4A4	lw     v0, $0000(a0)
800BB4A8	ori    a1, a1, $b3c5
800BB4AC	multu  v0, a1
800BB4B0	mfhi   v0
800BB4B4	srl    v1, v0, $0b
800BB4B8	andi   v0, v1, $ffff
800BB4BC	sltiu  v0, v0, $0100
800BB4C0	bne    v0, zero, Lbb4cc [$800bb4cc]
800BB4C4	nop
800BB4C8	ori    v1, zero, $00ff

Lbb4cc:	; 800BB4CC
800BB4CC	lw     a0, $0000(a0)
800BB4D0	nop
800BB4D4	multu  a0, a1
800BB4D8	lui    at, $800a
800BB4DC	sb     v1, $d29c(at)
800BB4E0	lui    a1, $8888
800BB4E4	ori    a1, a1, $8889
800BB4E8	mfhi   v1
800BB4EC	srl    v1, v1, $0b
800BB4F0	sll    v0, v1, $03
800BB4F4	subu   v0, v0, v1
800BB4F8	sll    v0, v0, $05
800BB4FC	addu   v0, v0, v1
800BB500	sll    v0, v0, $04
800BB504	subu   v1, a0, v0
800BB508	andi   a0, v1, $ffff
800BB50C	multu  a0, a1
800BB510	mfhi   v1
800BB514	srl    v1, v1, $05
800BB518	sll    v0, v1, $04
800BB51C	subu   v0, v0, v1
800BB520	sll    v0, v0, $02
800BB524	subu   a0, a0, v0
800BB528	lui    at, $800a
800BB52C	sb     v1, $d29d(at)
800BB530	lui    v1, $800a
800BB534	lbu    v1, $d29e(v1)
800BB538	andi   v0, a0, $ffff
800BB53C	beq    v1, v0, Lbb554 [$800bb554]
800BB540	ori    v0, zero, $001e
800BB544	lui    at, $800a
800BB548	sb     a0, $d29e(at)
800BB54C	j      Lbb568 [$800bb568]
800BB550	nop

Lbb554:	; 800BB554
800BB554	lui    v0, $800a
800BB558	lbu    v0, $d29f(v0)
800BB55C	nop
800BB560	beq    v0, zero, Lbb570 [$800bb570]
800BB564	addiu  v0, v0, $ffff (=-$1)

Lbb568:	; 800BB568
800BB568	lui    at, $800a
800BB56C	sb     v0, $d29f(at)

Lbb570:	; 800BB570
V0 = w[8009C6DC];
// number of visible entity
S2 = bu[V0 + 3];
if (S2 != 0)
{
    S0 = 0;

    loopbb590:	; 800BB590

    // talk with entity
    V1 = w[8009C544];
    V0 = bu[V1 + S0 + 5A];
    if (V0 != 0)
    {
        V0 = w[8009C6E0];
        V0 = bu[V0 + 32];

        if (V0 == 0 && S1 == 0)
        {
            S1 = 1;

            A0 = bu[V1 + 57];
            A1 = 1;
            A2 = 1;
            script_request_run;
        }

        [V1 + S0 + 5A] = b(0);
    }



    // collide with entity
    V1 = w[8009C544];
    V0 = bu[V1 + S0 + 58];
    if (V0 != 0)
    {
        A0 = bu[V1 + 57];
        A1 = 1;
        A2 = 2;
        script_request_run;

        [V1 + S0 + 58] = b(0);
    }

    S0 = S0 + 84;
    V0 = S2 * 84;
    V0 = S0 < V0;

    800BB64C	bne    v0, zero, loopbb590 [$800bb590]
}



V0 = h[80095D54]; // number of inited lines
if (V0 > 0)
{
    S1 = 0;
    S0 = 0;

    Lbb66c:	; 800BB66C
        // if we talk to line
        V0 = bu[8007E7AC + S0 + 11];
        if (V0 != 0)
        {
            game_data = w[8009C6E0];
            V0 = bu[game_data + 32];
            if (V0 == 0)
            {
                A0 = bu[8007E7AC + S0 + 0D];
                A1 = 1;
                A2 = 1;
                script_request_run;
            }

            [8007E7AC + S0 + 11] = b(0);
        }



        // entity move in line
        V0 = bu[8007E7AC + S0 + 10];
        if (V0 != 0)
        {
            A0 = bu[8007E7AC + S0 + 0D];
            A1 = 1;
            A2 = 2;
            script_request_run;

            [8007E7AC + S0 + 10] = b(0);
        }



        // entity cross line
        V0 = bu[8007E7AC + S0 + 0F];
        if (V0 != 0)
        {
            A0 = bu[8007E7AC + S0 + 0D];
            A1 = 1;
            A2 = 3;
            script_request_run;

            [8007E7AC + S0 + 0F] = b(0);
        }



        // entity enter line
        V0 = bu[8007E7AC + S0 + 12];
        if (V0 != 0)
        {
            A0 = bu[8007E7AC + S0 + 0D];
            A1 = 1;
            A2 = 5;
            script_request_run;

            [8007E7AC + S0 + 12] = b(0);
        }



        // entity leave line
        V0 = bu[8007E7AC + S0 + 13];
        if (V0 != 0)
        {
            A0 = bu[8007E7AC + S0 + 0D];
            A1 = 1;
            A2 = 6;
            script_request_run;

            [8007E7AC + S0 + 13] = b(0);
        }



        // entity inside line
        V0 = bu[8007E7AC + S0 + 0E];
        if (V0 != 0)
        {
            A0 = bu[8007E7AC + S0 + 0D];
            A1 = 1;
            A2 = 4;
            script_request_run;
        }



        S1 = S1 + 1;
        V0 = h[80095D84];
        V0 = S1 < V0;
        S0 = S0 + 18;
    800BB824	bne    v0, zero, Lbb66c [$800bb66c]
}

V0 = w[8009C6DC];
S3 = 5;
S2 = bu[V0 + 2]; // number of entity

Lbb83c:	; 800BB83C
800BB83C	lui    v0, $800a
800BB840	lw     v0, $c6dc(v0)
800BB844	lui    v1, $8007
800BB848	lbu    v1, $22c4(v1)
800BB84C	lbu    v0, $0002(v0)
800BB850	nop
800BB854	sltu   v1, v1, v0
800BB858	bne    v1, zero, Lbb868 [$800bb868]
800BB85C	nop
800BB860	lui    at, $8007
800BB864	sb     zero, $22c4(at)

Lbb868:	; 800BB868
800BB868	lui    v0, $8007
800BB86C	lbu    v0, $1e24(v0)
800BB870	nop
800BB874	andi   v0, v0, $0003
800BB878	beq    v0, zero, Lbb890 [$800bb890]
800BB87C	nop
800BB880	lui    a1, $8007
800BB884	lbu    a1, $22c4(a1)
800BB888	jal    funcbc9fc [$800bc9fc]
800BB88C	ori    a0, zero, $0004

Lbb890:	; 800BB890
800BB890	lui    v1, $8007
800BB894	lbu    v1, $22c4(v1)
800BB898	nop
800BB89C	lui    at, $8008
800BB8A0	addiu  at, at, $1d90
800BB8A4	addu   at, at, v1
800BB8A8	lbu    v0, $0000(at)
800BB8AC	nop
800BB8B0	beq    v0, zero, Lbb8cc [$800bb8cc]
800BB8B4	nop
800BB8B8	lui    v0, $800e
800BB8BC	lbu    v0, $48f0(v0)
800BB8C0	nop
if (V0 != V1)
{
    V0 = bu[800722C4];
    V0 = V0 + 1;
    [800722C4] = b(V0);

    V1 = bu[80099FFC];
    S2 = S2 - 1;
    if (V1 == S3)
    {
        V1 = bu[80071E24];
        V0 = V1 & 1;

        if (V0 != 0)
        {
            V0 = V1 & 4;

            if (V0 == 0)
            {
                V1 = bu[80099FFC];
                if (V1 == 5)
                {
                    [80070788] = b(0);
                }

                handle_animation_state;
                return;
            }

            V0 = bu[800722C4];
            V0 = bu[80114498 + V0];

            if (V0 == 0)
            {
                V1 = bu[80099FFC];
                if (V1 == 5)
                {
                    [80070788] = b(0);
                }

                handle_animation_state;
                return;
            }
        }
    }

    800BBB80	bne    s2, zero, Lbb83c [$800bb83c]

    V1 = bu[80099FFC];
    if (V1 == 5)
    {
        [80070788] = b(0);
    }

    handle_animation_state;
    return;
}

Lbb8cc:	; 800BB8CC
S0 = 8;

Lbb8d0:	; 800BB8D0
V0 = bu[80099FFC];
800BB8DC	bne    v0, s3, Lbb964 [$800bb964]
800BB8E0	nop
800BB8E4	lui    v0, $800a
800BB8E8	lbu    v0, $d820(v0)
800BB8EC	nop
800BB8F0	andi   v0, v0, $0001
800BB8F4	beq    v0, zero, Lbb964 [$800bb964]
800BB8F8	nop
800BB8FC	lui    v0, $8007
800BB900	lbu    v0, $1e24(v0)
800BB904	nop
800BB908	andi   v0, v0, $0004
800BB90C	beq    v0, zero, Lbb93c [$800bb93c]
800BB910	ori    a0, zero, $0003
800BB914	lui    v0, $8007
800BB918	lbu    v0, $22c4(v0)
800BB91C	nop
800BB920	lui    at, $8011
800BB924	addiu  at, at, $4498
800BB928	addu   at, at, v0
800BB92C	lbu    v0, $0000(at)
800BB930	nop
800BB934	beq    v0, zero, Lbb964 [$800bb964]
800BB938	nop

Lbb93c:	; 800BB93C
800BB93C	ori    s1, zero, $0001

loopbb940:	; 800BB940
800BB940	sll    a1, s1, $10
800BB944	lui    a2, $800a
800BB948	addiu  a2, a2, $013c
800BB94C	jal    funcda124 [$800da124]
800BB950	sra    a1, a1, $10
800BB954	addiu  s1, s1, $0001
800BB958	slti   v0, s1, $0009
800BB95C	bne    v0, zero, loopbb940 [$800bb940]
800BB960	ori    a0, zero, $0003

Lbb964:	; 800BB964
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

// 800BB994
// read opcode
[8009A058] = b(bu[V0 + V1]);
V0 = bu[8009A058];
V0 = w[800e0228 + V0 * 4];
// call opcode function
08 78FE0C80
09 80010D80
0a 00F20C80
0b BCF20C80
0c 540B0C80
0d 540B0C80
0e 3C520C80
0f 64210D80
10 A03F0C801C400C80A03E0C801C3F0C80E41D0C80EC1E0C808C220C8094230C8054270C805C280C80540B0C80540B0C80540B0C80540B0C80540B0C80540B0C80
20 C4430C80
21 E84E0C80
24 180C0C80
26 20440D80
2a 3C7C0C80
30 FC2B0C80
31 A82C0C80
32 542D0C80
34 C0810C80
35 88850C80
39 883B0D80
3a 183C0D80
3b A83C0D80
3c 8C360D80
3d 8C360D80
3e 48350D80
3f 8C360D80
44 540B0C80
45 28370D80
46 540B0C80
47 40380D80
4c 540B0C80
4d 58390D80
4e 540B0C80
4f 703A0D80
58 201F0D80
59 DC1F0D80
5a 98200D80
5b 8C290D80
5c 702A0D80
5d 602B0D80
5f E80B0C80
60 A4400C80
69 BC540C80
6e 3C1D0D80
73 54A20C80
74 3C2F0D80
75 7CA70C80
76 F4BB0C80
77 40BD0C80
78 94BE0C80
79 DCBF0C80
7a 58C50C80
7b 70C60C80
7c 8CC70C80
7d A8C80C80
7e 24AA0C80
7f ECC90C80
80 E00D0C805C0E0C8074160C8014170C80B8170C805CBB0C80A4BC0C80FCBD0C8040BF0C8098C00C8034C10C80D4C10C8084C20C8058C30C8004C40C80C0B70C80
90 58B80C80
91 F4B80C80
92 8CB90C80
93 28BA0C80
94 C0BA0C80
95 D8C40C80
96 ECC50C800CC70C8024C80C8044C90C80DC0E0C80580F0C80D80F0C807C100C8014120C80B0130C80
be 540B0C80
c1 D4A50C80
cb 18F70C80
cc 74F80C80
d2 C4D00C80
d8 B0420C80
d9 50430C80
da 04480C80
db 8C720C80
f8 54CD0C80
f9 94CE0C80
fa E8CF0C80
fb 64550C80
ff 0C560C80


jalr v0 ra;
ret = V0;

V1 = bu[800722C4];
q_1 = bu[80099FFC];
q_2 = bu[8009D820];
q_3 = bu[80071E24];
q_4 = bu[80114498 + V1];

if (q_1 != S3 || q_2 & 1 == 0 || (q_3 & 4 != 0 && q_4 == 0))
{
    if (ret == 0)
    {
        S0 = S0 - 1;
        800BBB0C	bne    s0, zero, Lbb8d0 [$800bb8d0]   check if we have left opcodes to execute
    }

    // if we pause execution or opcodes limit is over
    // go to nex entity
    V0 = bu[800722C4];
    V0 = V0 + 1;
    [800722C4] = b(V0);

    if (q_1 == S3 && q_3 & 1 != 0 && (q_3 & 4 == 0 || q_4 == 0))
    {
        if (q_1 == 5)
        {
            [80070788] = b(0);
        }

        handle_animation_state;
        return;
    }

    // if we have entity left
    S2 = S2 - 1;
    800BBB80	bne    s2, zero, Lbb83c [$800bb83c]
}
else
{
    // if script is paused - go to next entity
    if (ret != 0)
    {
        V0 = bu[800722C4];
        V0 = V0 + 1;
        [800722C4] = b(V0);
    }
    else
    {
        V0 = w[8009A064];
        V0 = V0 + 1;
        [8009A064] = w(V0);

        if (V0 >= 8)
        {
            [8009A064] = w(0);

            V0 = bu[800722C4];
            V0 = V0 + 1;
            [800722C4] = b(V0);
        }
    }
}

if (q_1 == 5)
{
    [80070788] = b(0);
}

handle_animation_state;
////////////////////////////////



////////////////////////////////
// script_request_run
entity_id                 = A0;
priority_id               = A1;
script_id                 = A2;

model_data_offset         = w[8009C544];
current_priority_slot     = bu[8009A1C4 + entity_id];
script_state              = bu[800833F8 + entity_id * 8 + priority_id];
field_file_offset         = 8009C6DC;
extra_offset_number       = hu[field_file_offset + 6]
entity_number             = bu[field_file_offset + 2];


if (priority_id < current_priority_slot)
{
    if (script_state != 0)
    {
        return script_state;
    }

    // get offset for this script
    script_offset = hu[field_file_offset + entity_id * 40 + entity_number * 8 + extra_offset_number * 4 + script_id * 2 + 20];

    // read opcode
    V0 = bu[field_file_offset + script_offset];

    // if not return opcode - add this script to priority slot
    if (V0 != 0)
    {
        // add script to priority queue
        [801142D4 + T0 * 8 + priority_id] = b(script_id);

        // store curently active script pointer
        active_slot     = bu[8009A1C4 + entity_id];
        current_pointer = hu[800831FC + entity_id * 2];
        [80071748 + entity_id * 10 + active_slot * 2] = h(current_pointer);

        // set new active script pointer and new priority slot
        [800831FC + entity_id * 2] = h(script_offset);
        [8009A1C4 + entity_id] = b(priority_id);

        // get model data
        V1 = bu[8007EB98 + entity_id];
        if (V1 != FF)
        {
            V0 = bu[model_data_offset + V1 * 84 + 5D];

            if (V0 == 1)
            {
                [model_data_offset + V1 * 84 + 5E] = b(0);
                [model_data_offset + V1 * 84 + 62] = h(0);
                [model_data_offset + V1 * 84 + 64] = h(0);
            }

            [model_data_offset + V1 * 84 + 5D] = b(0);
        }

        [800716DC + entity_id * 2] = h(0);
    }

    return 1;
}
else
{
    return 0;
}
////////////////////////////////



////////////////////////////////
// funca8304
// we check talk here
if (w[8009abf4 + 78] & 0020) // if ok button pressed
{
    V0 = w[8009abf4 + 7c];
    if (V0 & 20 == 0) // if ok not repeated
    {
        S0 = 0;

        V0 = h[800965e0]; // pc
        [SP + 10] = w(w[80074eb0 + V0 * 84] >> c);
        [SP + 14] = w(w[80074eb4 + V0 * 84] >> c);
        [SP + 18] = w(w[80074eb8 + V0 * 84] >> c);

        V1 = h[8009abf4 + 28]; // number of model

        if (V1 > 0)
        {
            S4 = 100;
            S1 = 0;
            S3 = SP + 10;
            S2 = S3;

            loopa83cc:	; 800A83CC
                [S2 + 20] = h(S4);
                V0 = h[800965e0]
                if (S0 != V0) // if not pc
                {
                    if (bu[80074EA4 + S1 + 5b] == 0) // if model talkable
                    {
                        V1 = w[80074eb0 + S1];
                        V1 = V1 >> c;
                        [SP + 20] = w(V1);

                        V0 = w[80074eb4 + S1];
                        A2 = V0 >> c;
                        [SP + 24] = w(A2);

                        V0 = w[80074eb8 + S1];
                        A1 = V0 >> c;
                        [SP + 28] = w(A1);

                        if (w[SP + 10] != V1 || w[SP + 14] != A2)
                        {
                            if ((w[SP + 18] - A1 + ff) < 1ff)
                            {
                                A0 = SP + 10;
                                A1 = SP + 20;
                                A2 = SP + 50;
                                calculate_direction_by_vectors;

                                A0 = [800965e0];
                                V1 = bu[80074edc + A0 * 84];
                                V1 = V1 - V0;
                                V1 = V1 & ff;

                                if (V1 >= 81)
                                {
                                    [S2 + 20] = h(S4 - V1);
                                }
                                else
                                {
                                    [S2 + 20] = h(V1);
                                }

                                V1 = h[900965e0];
                                A0 = hu[80074ea4 + V1 * 84 + 6c]; // pc solid
                                V1 = hu[80074ea4 + S1 + 6e]; // talk range
                                V1 = V1 + A0;
                                if (V1 <= w[SP + 50]) // if pc solid + entity talk less than distance than we too far
                                {
                                    [S2 + 20] = h(S4);
                                }
                            }
                        }
                    }
                }

                S1 = S1 + 84;
                V0 = h[8009ac1c];
                S0 = S0 + 1;
                S2 = S2 + 2;
                800A8534	slt    v0, s0, v0
            800A8538	bne    v0, zero, loopa83cc [$800a83cc]
        }

        A3 = 40;
        V0 = h[8009ac1c];
        A2 = hu[800965e0];

        if (V0 > 0)
        {
            S0 = 0;
            T0 = V0;
            A1 = SP + 10;

            loopa8564:	; 800A8564
                V1 = h[A1 + 20];
                V0 = A3;
                A0 = V1;
                if (V1 < V0)
                {
                    A3 = A0;
                    A2 = S0;
                }

                A1 = A1 + 2;
                S0 = S0 + 1;
                V0 = S0 < T0;
            800A8590	bne    v0, zero, loopa8564 [$800a8564]
        }

        if (A2 != h[800965e0])
        {
            V0 = A3;
            if (V0 != 40)
            {
                [80074efe + A2 * 84] = b(1);
            }
        }
    }
}
////////////////////////////////