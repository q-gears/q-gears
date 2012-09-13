////////////////////////////////
// 0x00 RET
current_entity = bu[800722c4];
current_priority = bu[8009a1c4 + current_entity];

if (current_priority >= 7)
{
    return 1;
}

// if script set to REQEW then te this script as finished
V1 = bu[800833F8 + current_entity * 8 + current_priority];
if (V1 == 1)
{
    [800833F8 + current_entity * 8 + current_priority] = b(02);
}

current_priority = current_priority + 1;
[8009A1C4 + current_entity] = b(current_priority);

V1 = hu[80071748 + current_entity * 10 + current_priority * 2]; // get current script pointer for next script
[800831FC + current_entity * 2] = h(V1);                      // set new script pointer

if (V1 == 0)
{
    for (;;)
    {
        loopc3b28:	; 800C3B28
        if (current_priority >= 7)
        {
            break;
        }

        // go to next script
        current_priority = current_priority + 1;
        [8009A1C4 + current_entity] = b(current_priority);

        V0 = hu[80071748 + current_entity * 10 + current_priority * 2]; // get new script pointer for next script
        [800831fc + current_entity * 2] = h(V0);                      // set new script pointer

        800C3BB4	beq    v0, zero, loopc3b28 [$800c3b28]
    }
}

[80071748 + current_entity * 10 + current_priority * 2] = h(00); // set current script pointer for this script to 0
return 0;
////////////////////////////////



////////////////////////////////
// 0x01 REQ
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 1;
A1 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;
funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x02 REQSW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 2;
A1 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;
funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x03 REQEW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 3;
A1 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;
funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x04 PREQ
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 1;
V0 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;

A1 = bu[8009D391 + V0];

if (A1 != FF)
{
    A1 = bu[8009AD30 + A1];
}
else
{
    A1 = FF;
}

funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x05 PRQSW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 2;
V0 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;

A1 = bu[8009D391 + V0];

if (A1 != FF)
{
    A1 = bu[8009AD30 + A1];
}
else
{
    A1 = FF;
}

funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x06 PRQEW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 3;
V0 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;

A1 = bu[8009D391 + V0];

if (A1 != FF)
{
    A1 = bu[8009AD30 + A1];
}
else
{
    A1 = FF;
}

funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x07 RETTO
current_entity            = bu[800722c4];
current_script_pointer    = 800831fc + current_entity * 2;
field_file_offset         = w[8009c6dc];
entity_current_slot       = 8009a1c4 + current_entity;

V1 = hu[current_script_pointer];
V1 = bu[field_file_offset + V1 + 1];
V0 = bu[field_file_offset + V1 + 1];
priority_id               = V1 >> 5;
script_id                 = V0 & 1F;
V0 = bu[entity_current_slot];
priority_id = priority_id - 1;

if (V0 < priority_id)
{
    loopc3cd8:	; 800C3CD8
        V1 = [entity_current_slot];

        if (V1 < 7)
        {
            break;
        }

        V0 = bu[800833F8 + current_entity * 8 + V1];
        if (V0 == 1)
        {
            [800833F8 + current_entity * 8 + V1] = b(2);
        }

        V0 = bu[entity_current_slot];
        V0 = V0 + 1;
        [entity_current_slot] = b(V0);

        V0 = bu[entity_current_slot];
        [80071748 + current_entity * 10 + V0 * 2] = h(0);
        V0 = bu[entity_current_slot];
        V0 = V0 < priority_id;

    800C3D90	bne    v0, zero, loopc3cd8 [$800c3cd8]
}

[801142D4 + current_entity * 8 + priority_id] = b(script_id);
A2 = hu[field_file_offset + 6];
V0 = bu[field_file_offset + 2];
A0 = hu[field_file_offset + current_entity * 40 + V0 * 8 + A2 * 4 + script_id * 2 + 20];
[current_script_pointer] = h(A0);
[entity_current_slot] = b(priority_id);

return 0;
////////////////////////////////



////////////////////////////////
// 0x10 JMPF
800C3FC8	lui    a0, $8007
800C3FCC	lbu    a0, $22c4(a0)
800C3FD0	lui    v0, $8008
800C3FD4	addiu  v0, v0, $31fc
800C3FD8	sll    a0, a0, $01
800C3FDC	addu   a0, a0, v0
800C3FE0	lhu    v1, $0000(a0)
800C3FE4	lui    v0, $800a
800C3FE8	lw     v0, $c6dc(v0)
800C3FEC	nop
800C3FF0	addu   v0, v0, v1
800C3FF4	lhu    v1, $0000(a0)
800C3FF8	lbu    v0, $0001(v0)
800C3FFC	addiu  v1, v1, $0001
800C4000	addu   v0, v0, v1
800C4004	sh     v0, $0000(a0)
800C4008	addu   v0, zero, zero
800C400C	lw     ra, $0010(sp)
800C4010	addiu  sp, sp, $0018
800C4014	jr     ra 
800C4018	nop
////////////////////////////////



////////////////////////////////
// 0x11 JMPFL
800C4044	lui    a1, $8007
800C4048	lbu    a1, $22c4(a1)
800C404C	lui    v0, $8008
800C4050	addiu  v0, v0, $31fc
800C4054	sll    a1, a1, $01
800C4058	addu   a1, a1, v0
800C405C	lhu    v1, $0000(a1)
800C4060	lui    v0, $800a
800C4064	lw     v0, $c6dc(v0)
800C4068	nop
800C406C	addu   v0, v0, v1
800C4070	lbu    a0, $0002(v0)
800C4074	lbu    v1, $0001(v0)
800C4078	lhu    v0, $0000(a1)
800C407C	sll    a0, a0, $08
800C4080	or     v1, v1, a0
800C4084	addiu  v0, v0, $0001
800C4088	addu   v1, v1, v0
800C408C	addu   v0, zero, zero
800C4090	sh     v1, $0000(a1)
800C4094	lw     ra, $0010(sp)
800C4098	addiu  sp, sp, $0018
800C409C	jr     ra 
800C40A0	nop
////////////////////////////////



////////////////////////////////
// 0x12 JMPB
current_entity            = bu[800722c4];
current_script_pointer    = 800831fc + current_entity * 2;
field_file_offset         = w[8009c6dc];
A0 = hu[current_script_pointer + 0];

[current_script_pointer] = h(hu[current_script_pointer] - bu[field_file_offset + A0 + 1]);

return 1;
////////////////////////////////



////////////////////////////////
// 0x13 JMPBL
800C3F44	lui    a1, $8007
800C3F48	lbu    a1, $22c4(a1)
800C3F4C	lui    v0, $8008
800C3F50	addiu  v0, v0, $31fc
800C3F54	sll    a1, a1, $01
800C3F58	addu   a1, a1, v0
800C3F5C	lhu    v1, $0000(a1)
800C3F60	lui    v0, $800a
800C3F64	lw     v0, $c6dc(v0)
800C3F68	nop
800C3F6C	addu   v0, v0, v1
800C3F70	lbu    a0, $0002(v0)
800C3F74	lbu    v0, $0001(v0)
800C3F78	lhu    v1, $0000(a1)
800C3F7C	sll    a0, a0, $08
800C3F80	or     v0, v0, a0
800C3F84	subu   v1, v1, v0
800C3F88	ori    v0, zero, $0001
800C3F8C	sh     v1, $0000(a1)
800C3F90	lw     ra, $0010(sp)
800C3F94	addiu  sp, sp, $0018
800C3F98	jr     ra 
800C3F9C	nop
////////////////////////////////



////////////////////////////////
// 0x14 IFUB
800C1E0C	jal    funcc2000 [$800c2000]
800C1E10	nop
800C1E14	beq    v0, zero, Lc1e70 [$800c1e70]
800C1E18	nop
800C1E1C	lui    v0, $800a
800C1E20	lbu    v0, $d820(v0)
800C1E24	nop
800C1E28	andi   v0, v0, $0003
800C1E2C	beq    v0, zero, Lc1e44 [$800c1e44]
800C1E30	addu   a1, zero, zero
800C1E34	lui    a0, $800a
800C1E38	addiu  a0, a0, $0644
800C1E3C	jal    funcbeca4 [$800beca4]
800C1E40	addu   a2, zero, zero

Lc1e44:	; 800C1E44
800C1E44	lui    v0, $8007
800C1E48	lbu    v0, $22c4(v0)
800C1E4C	lui    v1, $8008
800C1E50	addiu  v1, v1, $31fc
800C1E54	sll    v0, v0, $01
800C1E58	addu   v0, v0, v1
800C1E5C	lhu    v1, $0000(v0)
800C1E60	nop
800C1E64	addiu  v1, v1, $0006
800C1E68	j      Lc1ed8 [$800c1ed8]
800C1E6C	sh     v1, $0000(v0)

Lc1e70:	; 800C1E70
800C1E70	lui    v0, $800a
800C1E74	lbu    v0, $d820(v0)
800C1E78	nop
800C1E7C	andi   v0, v0, $0003
800C1E80	beq    v0, zero, Lc1e98 [$800c1e98]
800C1E84	addu   a1, zero, zero
800C1E88	lui    a0, $800a
800C1E8C	addiu  a0, a0, $064c
800C1E90	jal    funcbeca4 [$800beca4]
800C1E94	addu   a2, zero, zero

Lc1e98:	; 800C1E98
800C1E98	lui    a0, $8007
800C1E9C	lbu    a0, $22c4(a0)
800C1EA0	lui    v0, $8008
800C1EA4	addiu  v0, v0, $31fc
800C1EA8	sll    a0, a0, $01
800C1EAC	addu   a0, a0, v0
800C1EB0	lhu    v1, $0000(a0)
800C1EB4	lui    v0, $800a
800C1EB8	lw     v0, $c6dc(v0)
800C1EBC	nop
800C1EC0	addu   v0, v0, v1
800C1EC4	lhu    v1, $0000(a0)
800C1EC8	lbu    v0, $0005(v0)
800C1ECC	addiu  v1, v1, $0005
800C1ED0	addu   v0, v0, v1
800C1ED4	sh     v0, $0000(a0)

Lc1ed8:	; 800C1ED8
800C1ED8	addu   v0, zero, zero
800C1EDC	lw     ra, $0010(sp)
800C1EE0	addiu  sp, sp, $0018
800C1EE4	jr     ra 
800C1EE8	nop
////////////////////////////////



////////////////////////////////
// 0x15 IFUBL
800C1F14	jal    funcc2000 [$800c2000]
800C1F18	nop
800C1F1C	beq    v0, zero, Lc1f78 [$800c1f78]
800C1F20	nop
800C1F24	lui    v0, $800a
800C1F28	lbu    v0, $d820(v0)
800C1F2C	nop
800C1F30	andi   v0, v0, $0003
800C1F34	beq    v0, zero, Lc1f4c [$800c1f4c]
800C1F38	addu   a1, zero, zero
800C1F3C	lui    a0, $800a
800C1F40	addiu  a0, a0, $065c
800C1F44	jal    funcbeca4 [$800beca4]
800C1F48	addu   a2, zero, zero

Lc1f4c:	; 800C1F4C
800C1F4C	lui    v0, $8007
800C1F50	lbu    v0, $22c4(v0)
800C1F54	lui    v1, $8008
800C1F58	addiu  v1, v1, $31fc
800C1F5C	sll    v0, v0, $01
800C1F60	addu   v0, v0, v1
800C1F64	lhu    v1, $0000(v0)
800C1F68	nop
800C1F6C	addiu  v1, v1, $0007
800C1F70	j      Lc1fec [$800c1fec]
800C1F74	sh     v1, $0000(v0)

Lc1f78:	; 800C1F78
800C1F78	lui    v0, $800a
800C1F7C	lbu    v0, $d820(v0)
800C1F80	nop
800C1F84	andi   v0, v0, $0003
800C1F88	beq    v0, zero, Lc1fa0 [$800c1fa0]
800C1F8C	addu   a1, zero, zero
800C1F90	lui    a0, $800a
800C1F94	addiu  a0, a0, $0668
800C1F98	jal    funcbeca4 [$800beca4]
800C1F9C	addu   a2, zero, zero

Lc1fa0:	; 800C1FA0
800C1FA0	lui    a1, $8007
800C1FA4	lbu    a1, $22c4(a1)
800C1FA8	lui    v0, $8008
800C1FAC	addiu  v0, v0, $31fc
800C1FB0	sll    a1, a1, $01
800C1FB4	addu   a1, a1, v0
800C1FB8	lhu    v1, $0000(a1)
800C1FBC	lui    v0, $800a
800C1FC0	lw     v0, $c6dc(v0)
800C1FC4	nop
800C1FC8	addu   v0, v0, v1
800C1FCC	lbu    v1, $0006(v0)
800C1FD0	lbu    a0, $0005(v0)
800C1FD4	lhu    v0, $0000(a1)
800C1FD8	sll    v1, v1, $08
800C1FDC	or     a0, a0, v1
800C1FE0	addiu  a0, a0, $0005
800C1FE4	addu   v0, v0, a0
800C1FE8	sh     v0, $0000(a1)

Lc1fec:	; 800C1FEC
800C1FEC	addu   v0, zero, zero
800C1FF0	lw     ra, $0010(sp)
800C1FF4	addiu  sp, sp, $0018

Lc1ff8:	; 800C1FF8
800C1FF8	jr     ra 
800C1FFC	nop
////////////////////////////////



////////////////////////////////
// 0x16 IFSW
800C22B4	jal    funcc24a8 [$800c24a8]
800C22B8	nop
800C22BC	beq    v0, zero, Lc2318 [$800c2318]
800C22C0	nop
800C22C4	lui    v0, $800a
800C22C8	lbu    v0, $d820(v0)
800C22CC	nop
800C22D0	andi   v0, v0, $0003
800C22D4	beq    v0, zero, Lc22ec [$800c22ec]
800C22D8	addu   a1, zero, zero
800C22DC	lui    a0, $800a
800C22E0	addiu  a0, a0, $06b4
800C22E4	jal    funcbeca4 [$800beca4]
800C22E8	addu   a2, zero, zero

Lc22ec:	; 800C22EC
800C22EC	lui    v0, $8007
800C22F0	lbu    v0, $22c4(v0)
800C22F4	lui    v1, $8008
800C22F8	addiu  v1, v1, $31fc
800C22FC	sll    v0, v0, $01
800C2300	addu   v0, v0, v1
800C2304	lhu    v1, $0000(v0)
800C2308	nop
800C230C	addiu  v1, v1, $0008
800C2310	j      Lc2380 [$800c2380]
800C2314	sh     v1, $0000(v0)

Lc2318:	; 800C2318
800C2318	lui    v0, $800a
800C231C	lbu    v0, $d820(v0)
800C2320	nop
800C2324	andi   v0, v0, $0003
800C2328	beq    v0, zero, Lc2340 [$800c2340]
800C232C	addu   a1, zero, zero
800C2330	lui    a0, $800a
800C2334	addiu  a0, a0, $06c0
800C2338	jal    funcbeca4 [$800beca4]
800C233C	addu   a2, zero, zero

Lc2340:	; 800C2340
800C2340	lui    a0, $8007
800C2344	lbu    a0, $22c4(a0)
800C2348	lui    v0, $8008
800C234C	addiu  v0, v0, $31fc
800C2350	sll    a0, a0, $01
800C2354	addu   a0, a0, v0
800C2358	lhu    v1, $0000(a0)
800C235C	lui    v0, $800a
800C2360	lw     v0, $c6dc(v0)
800C2364	nop
800C2368	addu   v0, v0, v1
800C236C	lhu    v1, $0000(a0)
800C2370	lbu    v0, $0007(v0)
800C2374	addiu  v1, v1, $0007
800C2378	addu   v0, v0, v1
800C237C	sh     v0, $0000(a0)

Lc2380:	; 800C2380
800C2380	addu   v0, zero, zero
800C2384	lw     ra, $0010(sp)
800C2388	addiu  sp, sp, $0018
800C238C	jr     ra 
800C2390	nop
////////////////////////////////



////////////////////////////////
// 0x17 IFSWL
800C23BC	jal    funcc24a8 [$800c24a8]
800C23C0	nop
800C23C4	beq    v0, zero, Lc2420 [$800c2420]
800C23C8	nop
800C23CC	lui    v0, $800a
800C23D0	lbu    v0, $d820(v0)
800C23D4	nop
800C23D8	andi   v0, v0, $0003
800C23DC	beq    v0, zero, Lc23f4 [$800c23f4]
800C23E0	addu   a1, zero, zero
800C23E4	lui    a0, $800a
800C23E8	addiu  a0, a0, $06d4
800C23EC	jal    funcbeca4 [$800beca4]
800C23F0	addu   a2, zero, zero

Lc23f4:	; 800C23F4
800C23F4	lui    v0, $8007
800C23F8	lbu    v0, $22c4(v0)
800C23FC	lui    v1, $8008
800C2400	addiu  v1, v1, $31fc
800C2404	sll    v0, v0, $01

Lc2408:	; 800C2408
800C2408	addu   v0, v0, v1
800C240C	lhu    v1, $0000(v0)
800C2410	nop
800C2414	addiu  v1, v1, $0009
800C2418	j      Lc2494 [$800c2494]

funcc241c:	; 800C241C
800C241C	sh     v1, $0000(v0)

Lc2420:	; 800C2420
800C2420	lui    v0, $800a
800C2424	lbu    v0, $d820(v0)
800C2428	nop
800C242C	andi   v0, v0, $0003
800C2430	beq    v0, zero, Lc2448 [$800c2448]
800C2434	addu   a1, zero, zero
800C2438	lui    a0, $800a
800C243C	addiu  a0, a0, $06e0
800C2440	jal    funcbeca4 [$800beca4]
800C2444	addu   a2, zero, zero

Lc2448:	; 800C2448
800C2448	lui    a1, $8007
800C244C	lbu    a1, $22c4(a1)
800C2450	lui    v0, $8008
800C2454	addiu  v0, v0, $31fc
800C2458	sll    a1, a1, $01
800C245C	addu   a1, a1, v0
800C2460	lhu    v1, $0000(a1)
800C2464	lui    v0, $800a
800C2468	lw     v0, $c6dc(v0)
800C246C	nop
800C2470	addu   v0, v0, v1
800C2474	lbu    v1, $0008(v0)
800C2478	lbu    a0, $0007(v0)
800C247C	lhu    v0, $0000(a1)
800C2480	sll    v1, v1, $08
800C2484	or     a0, a0, v1
800C2488	addiu  a0, a0, $0007
800C248C	addu   v0, v0, a0
800C2490	sh     v0, $0000(a1)

Lc2494:	; 800C2494
800C2494	addu   v0, zero, zero
800C2498	lw     ra, $0010(sp)
800C249C	addiu  sp, sp, $0018
800C24A0	jr     ra 
800C24A4	nop
////////////////////////////////



////////////////////////////////
// 0x18 IFUW
800C277C	jal    funcc2970 [$800c2970]
800C2780	nop
800C2784	beq    v0, zero, Lc27e0 [$800c27e0]
800C2788	nop
800C278C	lui    v0, $800a
800C2790	lbu    v0, $d820(v0)
800C2794	nop
800C2798	andi   v0, v0, $0003
800C279C	beq    v0, zero, Lc27b4 [$800c27b4]
800C27A0	addu   a1, zero, zero
800C27A4	lui    a0, $800a
800C27A8	addiu  a0, a0, $06b4
800C27AC	jal    funcbeca4 [$800beca4]
800C27B0	addu   a2, zero, zero

Lc27b4:	; 800C27B4
800C27B4	lui    v0, $8007
800C27B8	lbu    v0, $22c4(v0)
800C27BC	lui    v1, $8008
800C27C0	addiu  v1, v1, $31fc
800C27C4	sll    v0, v0, $01
800C27C8	addu   v0, v0, v1
800C27CC	lhu    v1, $0000(v0)
800C27D0	nop
800C27D4	addiu  v1, v1, $0008
800C27D8	j      Lc2848 [$800c2848]
800C27DC	sh     v1, $0000(v0)

Lc27e0:	; 800C27E0
800C27E0	lui    v0, $800a
800C27E4	lbu    v0, $d820(v0)
800C27E8	nop
800C27EC	andi   v0, v0, $0003
800C27F0	beq    v0, zero, Lc2808 [$800c2808]
800C27F4	addu   a1, zero, zero
800C27F8	lui    a0, $800a
800C27FC	addiu  a0, a0, $06c0
800C2800	jal    funcbeca4 [$800beca4]
800C2804	addu   a2, zero, zero

Lc2808:	; 800C2808
800C2808	lui    a0, $8007
800C280C	lbu    a0, $22c4(a0)
800C2810	lui    v0, $8008
800C2814	addiu  v0, v0, $31fc
800C2818	sll    a0, a0, $01
800C281C	addu   a0, a0, v0
800C2820	lhu    v1, $0000(a0)
800C2824	lui    v0, $800a
800C2828	lw     v0, $c6dc(v0)
800C282C	nop
800C2830	addu   v0, v0, v1
800C2834	lhu    v1, $0000(a0)
800C2838	lbu    v0, $0007(v0)
800C283C	addiu  v1, v1, $0007
800C2840	addu   v0, v0, v1
800C2844	sh     v0, $0000(a0)

Lc2848:	; 800C2848
800C2848	addu   v0, zero, zero
800C284C	lw     ra, $0010(sp)
800C2850	addiu  sp, sp, $0018
800C2854	jr     ra 
800C2858	nop
////////////////////////////////



////////////////////////////////
// 0x19 IFUWL
800C285C	lui    v0, $800a
800C2860	lbu    v0, $d820(v0)
800C2864	addiu  sp, sp, $ffe8 (=-$18)
800C2868	andi   v0, v0, $0003
800C286C	beq    v0, zero, Lc2884 [$800c2884]
800C2870	sw     ra, $0010(sp)
800C2874	lui    a0, $800a
800C2878	addiu  a0, a0, $06cc
800C287C	jal    funcbead4 [$800bead4]
800C2880	ori    a1, zero, $0008

Lc2884:	; 800C2884
800C2884	jal    funcc2970 [$800c2970]
800C2888	nop
800C288C	beq    v0, zero, Lc28e8 [$800c28e8]
800C2890	nop
800C2894	lui    v0, $800a
800C2898	lbu    v0, $d820(v0)
800C289C	nop
800C28A0	andi   v0, v0, $0003
800C28A4	beq    v0, zero, Lc28bc [$800c28bc]
800C28A8	addu   a1, zero, zero
800C28AC	lui    a0, $800a
800C28B0	addiu  a0, a0, $06d4
800C28B4	jal    funcbeca4 [$800beca4]
800C28B8	addu   a2, zero, zero

Lc28bc:	; 800C28BC
800C28BC	lui    v0, $8007
800C28C0	lbu    v0, $22c4(v0)
800C28C4	lui    v1, $8008
800C28C8	addiu  v1, v1, $31fc
800C28CC	sll    v0, v0, $01
800C28D0	addu   v0, v0, v1
800C28D4	lhu    v1, $0000(v0)
800C28D8	nop
800C28DC	addiu  v1, v1, $0009
800C28E0	j      Lc295c [$800c295c]
800C28E4	sh     v1, $0000(v0)

Lc28e8:	; 800C28E8
800C28E8	lui    v0, $800a
800C28EC	lbu    v0, $d820(v0)
800C28F0	nop
800C28F4	andi   v0, v0, $0003
800C28F8	beq    v0, zero, Lc2910 [$800c2910]
800C28FC	addu   a1, zero, zero
800C2900	lui    a0, $800a
800C2904	addiu  a0, a0, $06e0
800C2908	jal    funcbeca4 [$800beca4]
800C290C	addu   a2, zero, zero

Lc2910:	; 800C2910
800C2910	lui    a1, $8007
800C2914	lbu    a1, $22c4(a1)
800C2918	lui    v0, $8008
800C291C	addiu  v0, v0, $31fc
800C2920	sll    a1, a1, $01
800C2924	addu   a1, a1, v0
800C2928	lhu    v1, $0000(a1)
800C292C	lui    v0, $800a
800C2930	lw     v0, $c6dc(v0)
800C2934	nop
800C2938	addu   v0, v0, v1
800C293C	lbu    v1, $0008(v0)
800C2940	lbu    a0, $0007(v0)
800C2944	lhu    v0, $0000(a1)
800C2948	sll    v1, v1, $08
800C294C	or     a0, a0, v1
800C2950	addiu  a0, a0, $0007
800C2954	addu   v0, v0, a0
800C2958	sh     v0, $0000(a1)

Lc295c:	; 800C295C
800C295C	addu   v0, zero, zero
800C2960	lw     ra, $0010(sp)
800C2964	addiu  sp, sp, $0018
800C2968	jr     ra 
800C296C	nop
////////////////////////////////



////////////////////////////////
// 0x24 WAIT
800C0C18	lui    v0, $800a
800C0C1C	lbu    v0, $d820(v0)
800C0C20	addiu  sp, sp, $ffe0 (=-$20)
800C0C24	sw     ra, $0018(sp)
800C0C28	sw     s1, $0014(sp)
800C0C2C	andi   v0, v0, $0003
800C0C30	beq    v0, zero, Lc0c48 [$800c0c48]
800C0C34	sw     s0, $0010(sp)
800C0C38	lui    a0, $800a
800C0C3C	addiu  a0, a0, $04d4

funcc0c40:	; 800C0C40
800C0C40	jal    funcbead4 [$800bead4]
800C0C44	ori    a1, zero, $0002

Lc0c48:	; 800C0C48
800C0C48	lui    v0, $8007
800C0C4C	lbu    v0, $22c4(v0)
800C0C50	lui    s0, $8007
800C0C54	addiu  s0, s0, $16dc
800C0C58	sll    v0, v0, $01
800C0C5C	addu   a2, v0, s0
800C0C60	lhu    a1, $0000(a2)
800C0C64	nop
800C0C68	bne    a1, zero, Lc0d10 [$800c0d10]
800C0C6C	nop
800C0C70	lui    s1, $8008
800C0C74	addiu  s1, s1, $31fc
800C0C78	addu   a1, v0, s1
800C0C7C	lhu    v0, $0000(a1)
800C0C80	lui    v1, $800a
800C0C84	lw     v1, $c6dc(v1)
800C0C88	nop
800C0C8C	addu   v0, v1, v0
800C0C90	lbu    a0, $0001(v0)
800C0C94	nop
800C0C98	sh     a0, $0000(a2)
800C0C9C	lhu    v0, $0000(a1)
800C0CA0	nop
800C0CA4	addu   v1, v1, v0
800C0CA8	lbu    v0, $0002(v1)
800C0CAC	lui    v1, $800a
800C0CB0	lbu    v1, $d820(v1)
800C0CB4	sll    v0, v0, $08
800C0CB8	or     a0, a0, v0
800C0CBC	andi   v1, v1, $0003
800C0CC0	beq    v1, zero, Lc0cdc [$800c0cdc]
800C0CC4	sh     a0, $0000(a2)
800C0CC8	lui    a0, $800a
800C0CCC	addiu  a0, a0, $04dc
800C0CD0	lhu    a1, $0000(a2)
800C0CD4	jal    funcbeca4 [$800beca4]
800C0CD8	ori    a2, zero, $0004

Lc0cdc:	; 800C0CDC
800C0CDC	lui    v0, $8007
800C0CE0	lbu    v0, $22c4(v0)
800C0CE4	nop

Lc0ce8:	; 800C0CE8
800C0CE8	sll    a0, v0, $01
800C0CEC	addu   v0, a0, s0
800C0CF0	lhu    v0, $0000(v0)
800C0CF4	nop
800C0CF8	bne    v0, zero, Lc0dc8 [$800c0dc8]
800C0CFC	ori    v0, zero, $0001
800C0D00	addu   a0, a0, s1
800C0D04	lhu    v1, $0000(a0)
800C0D08	j      Lc0dc4 [$800c0dc4]
800C0D0C	addiu  v1, v1, $0003

Lc0d10:	; 800C0D10
800C0D10	ori    v0, zero, $0001
800C0D14	bne    a1, v0, Lc0d7c [$800c0d7c]
800C0D18	nop
800C0D1C	lui    v0, $800a
800C0D20	lbu    v0, $d820(v0)
800C0D24	nop
800C0D28	andi   v0, v0, $0003
800C0D2C	beq    v0, zero, Lc0d44 [$800c0d44]
800C0D30	ori    a1, zero, $0001
800C0D34	lui    a0, $800a
800C0D38	addiu  a0, a0, $04e8
800C0D3C	jal    funcbeca4 [$800beca4]
800C0D40	ori    a2, zero, $0004

Lc0d44:	; 800C0D44
800C0D44	lui    v1, $8007
800C0D48	lbu    v1, $22c4(v1)
800C0D4C	nop
800C0D50	sll    v1, v1, $01
800C0D54	addu   v0, v1, s0
800C0D58	sh     zero, $0000(v0)
800C0D5C	lui    v0, $8008
800C0D60	addiu  v0, v0, $31fc
800C0D64	addu   v1, v1, v0
800C0D68	lhu    a0, $0000(v1)
800C0D6C	addu   v0, zero, zero
800C0D70	addiu  a0, a0, $0003
800C0D74	j      Lc0dc8 [$800c0dc8]
800C0D78	sh     a0, $0000(v1)

Lc0d7c:	; 800C0D7C
800C0D7C	lui    v0, $800a

funcc0d80:	; 800C0D80
800C0D80	lbu    v0, $d820(v0)
800C0D84	nop
800C0D88	andi   v0, v0, $0003
800C0D8C	beq    v0, zero, Lc0da4 [$800c0da4]
800C0D90	nop
800C0D94	lui    a0, $800a
800C0D98	addiu  a0, a0, $04f4
800C0D9C	jal    funcbeca4 [$800beca4]
800C0DA0	ori    a2, zero, $0004

Lc0da4:	; 800C0DA4
800C0DA4	lui    a0, $8007
800C0DA8	lbu    a0, $22c4(a0)
800C0DAC	nop
800C0DB0	sll    a0, a0, $01
800C0DB4	addu   a0, a0, s0
800C0DB8	lhu    v1, $0000(a0)
800C0DBC	ori    v0, zero, $0001
800C0DC0	addiu  v1, v1, $ffff (=-$1)

Lc0dc4:	; 800C0DC4
800C0DC4	sh     v1, $0000(a0)

Lc0dc8:	; 800C0DC8
800C0DC8	lw     ra, $0018(sp)
800C0DCC	lw     s1, $0014(sp)
800C0DD0	lw     s0, $0010(sp)
800C0DD4	addiu  sp, sp, $0020
800C0DD8	jr     ra 
800C0DDC	nop
////////////////////////////////



////////////////////////////////
// 0x30 IFKEY
800C2BFC	lui    v0, $800a
800C2C00	lbu    v0, $d820(v0)
800C2C04	addiu  sp, sp, $ffe8 (=-$18)
800C2C08	andi   v0, v0, $0003
800C2C0C	beq    v0, zero, Lc2c24 [$800c2c24]
800C2C10	sw     ra, $0010(sp)
800C2C14	lui    a0, $800a
800C2C18	addiu  a0, a0, $0748
800C2C1C	jal    funcbead4 [$800bead4]
800C2C20	ori    a1, zero, $0003

Lc2c24:	; 800C2C24
800C2C24	lui    v0, $8007
800C2C28	lbu    v0, $22c4(v0)
800C2C2C	nop
800C2C30	sll    v0, v0, $01
800C2C34	lui    at, $8008
800C2C38	addiu  at, at, $31fc
800C2C3C	addu   at, at, v0
800C2C40	lhu    v1, $0000(at)
800C2C44	lui    v0, $800a
800C2C48	lw     v0, $c6dc(v0)
800C2C4C	nop
800C2C50	addu   v0, v0, v1
800C2C54	lbu    v0, $0002(v0)
800C2C58	nop
800C2C5C	andi   v0, v0, $0002
800C2C60	bne    v0, zero, Lc2c80 [$800c2c80]
800C2C64	nop
800C2C68	lui    v0, $800a
800C2C6C	lw     v0, $c6e0(v0)
800C2C70	nop
800C2C74	lhu    a0, $0068(v0)
800C2C78	j      Lc2c90 [$800c2c90]
800C2C7C	nop

Lc2c80:	; 800C2C80
800C2C80	lui    v0, $800a
800C2C84	lw     v0, $c6e0(v0)
800C2C88	nop
800C2C8C	lhu    a0, $0078(v0)

Lc2c90:	; 800C2C90
800C2C90	jal    funcc2e00 [$800c2e00]
800C2C94	nop
800C2C98	lw     ra, $0010(sp)
800C2C9C	addiu  sp, sp, $0018
800C2CA0	jr     ra 
800C2CA4	nop
////////////////////////////////



////////////////////////////////
// 0x31 IFKEYON
800C2CA8	lui    v0, $800a
800C2CAC	lbu    v0, $d820(v0)
800C2CB0	addiu  sp, sp, $ffe8 (=-$18)
800C2CB4	andi   v0, v0, $0003
800C2CB8	beq    v0, zero, Lc2cd0 [$800c2cd0]
800C2CBC	sw     ra, $0010(sp)
800C2CC0	lui    a0, $800a
800C2CC4	addiu  a0, a0, $0750
800C2CC8	jal    funcbead4 [$800bead4]
800C2CCC	ori    a1, zero, $0003

Lc2cd0:	; 800C2CD0
800C2CD0	lui    v0, $8007
800C2CD4	lbu    v0, $22c4(v0)
800C2CD8	nop
800C2CDC	sll    v0, v0, $01
800C2CE0	lui    at, $8008
800C2CE4	addiu  at, at, $31fc
800C2CE8	addu   at, at, v0
800C2CEC	lhu    v1, $0000(at)
800C2CF0	lui    v0, $800a
800C2CF4	lw     v0, $c6dc(v0)
800C2CF8	nop
800C2CFC	addu   v0, v0, v1
800C2D00	lbu    v0, $0002(v0)
800C2D04	nop
800C2D08	andi   v0, v0, $0002
800C2D0C	bne    v0, zero, Lc2d2c [$800c2d2c]
800C2D10	nop
800C2D14	lui    v0, $800a

Lc2d18:	; 800C2D18
800C2D18	lw     v0, $c6e0(v0)
800C2D1C	nop
800C2D20	lhu    a0, $0070(v0)
800C2D24	j      Lc2d3c [$800c2d3c]
800C2D28	nop

Lc2d2c:	; 800C2D2C
800C2D2C	lui    v0, $800a
800C2D30	lw     v0, $c6e0(v0)
800C2D34	nop
800C2D38	lhu    a0, $0080(v0)

Lc2d3c:	; 800C2D3C
800C2D3C	jal    funcc2e00 [$800c2e00]
800C2D40	nop
800C2D44	lw     ra, $0010(sp)
800C2D48	addiu  sp, sp, $0018
800C2D4C	jr     ra 
800C2D50	nop
////////////////////////////////



////////////////////////////////
// 0x32 IFKEYOFF
800C2D54	lui    v0, $800a
800C2D58	lbu    v0, $d820(v0)
800C2D5C	addiu  sp, sp, $ffe8 (=-$18)
800C2D60	andi   v0, v0, $0003
800C2D64	beq    v0, zero, Lc2d7c [$800c2d7c]
800C2D68	sw     ra, $0010(sp)
800C2D6C	lui    a0, $800a
800C2D70	addiu  a0, a0, $0758
800C2D74	jal    funcbead4 [$800bead4]
800C2D78	ori    a1, zero, $0003

Lc2d7c:	; 800C2D7C
800C2D7C	lui    v0, $8007
800C2D80	lbu    v0, $22c4(v0)
800C2D84	nop
800C2D88	sll    v0, v0, $01
800C2D8C	lui    at, $8008
800C2D90	addiu  at, at, $31fc
800C2D94	addu   at, at, v0
800C2D98	lhu    v1, $0000(at)
800C2D9C	lui    v0, $800a
800C2DA0	lw     v0, $c6dc(v0)
800C2DA4	nop
800C2DA8	addu   v0, v0, v1
800C2DAC	lbu    v0, $0002(v0)
800C2DB0	nop
800C2DB4	andi   v0, v0, $0002
800C2DB8	bne    v0, zero, Lc2dd8 [$800c2dd8]
800C2DBC	nop
800C2DC0	lui    v0, $800a
800C2DC4	lw     v0, $c6e0(v0)
800C2DC8	nop
800C2DCC	lhu    a0, $0074(v0)
800C2DD0	j      Lc2de8 [$800c2de8]
800C2DD4	nop

Lc2dd8:	; 800C2DD8
800C2DD8	lui    v0, $800a
800C2DDC	lw     v0, $c6e0(v0)
800C2DE0	nop
800C2DE4	lhu    a0, $0084(v0)

Lc2de8:	; 800C2DE8
800C2DE8	jal    funcc2e00 [$800c2e00]
800C2DEC	nop
800C2DF0	lw     ra, $0010(sp)
800C2DF4	addiu  sp, sp, $0018
800C2DF8	jr     ra 
800C2DFC	nop
////////////////////////////////



////////////////////////////////
// 0x5F NOP
800C0BE8	lui    v0, $8007
800C0BEC	lbu    v0, $22c4(v0)
800C0BF0	lui    v1, $8008
800C0BF4	addiu  v1, v1, $31fc
800C0BF8	sll    v0, v0, $01
800C0BFC	addu   v0, v0, v1
800C0C00	lhu    v1, $0000(v0)
800C0C04	nop
800C0C08	addiu  v1, v1, $0001

Lc0c0c:	; 800C0C0C
800C0C0C	sh     v1, $0000(v0)
800C0C10	jr     ra 
800C0C14	ori    v0, zero, $0001
////////////////////////////////



////////////////////////////////
// 0xCB IFPRTYQ
800CF718	lui    v0, $800a
800CF71C	lbu    v0, $d820(v0)
800CF720	addiu  sp, sp, $ffe0 (=-$20)
800CF724	sw     ra, $001c(sp)
800CF728	andi   v0, v0, $0003
800CF72C	beq    v0, zero, Lcf744 [$800cf744]
800CF730	sw     s0, $0018(sp)
800CF734	lui    a0, $800a
800CF738	addiu  a0, a0, $0cc4
800CF73C	jal    funcbead4 [$800bead4]
800CF740	ori    a1, zero, $0002

Lcf744:	; 800CF744
800CF744	lui    v0, $8007
800CF748	lbu    v0, $22c4(v0)
800CF74C	addu   a0, zero, zero
800CF750	sll    v0, v0, $01
800CF754	lui    at, $8008
800CF758	addiu  at, at, $31fc
800CF75C	addu   at, at, v0
800CF760	lhu    v1, $0000(at)
800CF764	lui    v0, $800a
800CF768	lw     v0, $c6dc(v0)
800CF76C	lui    s0, $8008
800CF770	addiu  s0, s0, $31fc
800CF774	addu   v0, v0, v1
800CF778	lbu    v1, $0001(v0)

loopcf77c:	; 800CF77C
800CF77C	lui    at, $800a
800CF780	addiu  at, at, $d391 (=-$2c6f)
800CF784	addu   at, at, a0
800CF788	lbu    v0, $0000(at)
800CF78C	nop
800CF790	bne    v0, v1, Lcf7e8 [$800cf7e8]
800CF794	nop
800CF798	lui    v0, $800a
800CF79C	lbu    v0, $d820(v0)
800CF7A0	nop
800CF7A4	andi   v0, v0, $0003
800CF7A8	beq    v0, zero, Lcf7c0 [$800cf7c0]
800CF7AC	addu   a1, zero, zero
800CF7B0	lui    a0, $800a
800CF7B4	addiu  a0, a0, $0ccc
800CF7B8	jal    funcbeca4 [$800beca4]
800CF7BC	addu   a2, zero, zero

Lcf7c0:	; 800CF7C0
800CF7C0	lui    a0, $8007
800CF7C4	lbu    a0, $22c4(a0)
800CF7C8	nop
800CF7CC	sll    a0, a0, $01
800CF7D0	addu   a0, a0, s0
800CF7D4	lhu    v1, $0000(a0)
800CF7D8	addu   v0, zero, zero
800CF7DC	addiu  v1, v1, $0003
800CF7E0	j      Lcf860 [$800cf860]
800CF7E4	sh     v1, $0000(a0)

Lcf7e8:	; 800CF7E8
800CF7E8	addiu  a0, a0, $0001
800CF7EC	slti   v0, a0, $0003
800CF7F0	bne    v0, zero, loopcf77c [$800cf77c]
800CF7F4	nop
800CF7F8	lui    v0, $800a
800CF7FC	lbu    v0, $d820(v0)
800CF800	nop
800CF804	andi   v0, v0, $0003
800CF808	beq    v0, zero, Lcf820 [$800cf820]
800CF80C	addu   a1, zero, zero
800CF810	lui    a0, $800a
800CF814	addiu  a0, a0, $0cd8
800CF818	jal    funcbeca4 [$800beca4]
800CF81C	addu   a2, zero, zero

Lcf820:	; 800CF820
800CF820	lui    v0, $8008
800CF824	addiu  v0, v0, $31fc
800CF828	lui    a1, $8007
800CF82C	lbu    a1, $22c4(a1)
800CF830	lui    a0, $800a
800CF834	lw     a0, $c6dc(a0)
800CF838	sll    a1, a1, $01
800CF83C	addu   a1, a1, v0
800CF840	lhu    v1, $0000(a1)
800CF844	addu   v0, zero, zero
800CF848	addu   a0, a0, v1
800CF84C	lhu    v1, $0000(a1)
800CF850	lbu    a0, $0002(a0)
800CF854	addiu  v1, v1, $0002
800CF858	addu   a0, a0, v1
800CF85C	sh     a0, $0000(a1)

Lcf860:	; 800CF860
800CF860	lw     ra, $001c(sp)
800CF864	lw     s0, $0018(sp)
800CF868	addiu  sp, sp, $0020
800CF86C	jr     ra 
800CF870	nop
////////////////////////////////



////////////////////////////////
// 0xCC IFMEMBQ
800CF874	lui    v0, $800a
800CF878	lbu    v0, $d820(v0)
800CF87C	addiu  sp, sp, $ffe0 (=-$20)
800CF880	sw     ra, $001c(sp)
800CF884	andi   v0, v0, $0003
800CF888	beq    v0, zero, Lcf8a0 [$800cf8a0]
800CF88C	sw     s0, $0018(sp)
800CF890	lui    a0, $800a
800CF894	addiu  a0, a0, $0ce4
800CF898	jal    funcbead4 [$800bead4]
800CF89C	ori    a1, zero, $0002

Lcf8a0:	; 800CF8A0
800CF8A0	lui    v0, $8007
800CF8A4	lbu    v0, $22c4(v0)
800CF8A8	nop
800CF8AC	sll    v0, v0, $01
800CF8B0	lui    at, $8008
800CF8B4	addiu  at, at, $31fc
800CF8B8	addu   at, at, v0
800CF8BC	lhu    v1, $0000(at)
800CF8C0	lui    v0, $800a
800CF8C4	lw     v0, $c6dc(v0)
800CF8C8	nop
800CF8CC	addu   v0, v0, v1
800CF8D0	lui    v1, $800a
800CF8D4	lhu    v1, $d78a(v1)
800CF8D8	lbu    v0, $0001(v0)
800CF8DC	lui    s0, $8008
800CF8E0	addiu  s0, s0, $31fc
800CF8E4	srav   v1, v0, v1
800CF8E8	andi   v1, v1, $0001
800CF8EC	beq    v1, zero, Lcf944 [$800cf944]
800CF8F0	nop
800CF8F4	lui    v0, $800a
800CF8F8	lbu    v0, $d820(v0)
800CF8FC	nop
800CF900	andi   v0, v0, $0003
800CF904	beq    v0, zero, Lcf91c [$800cf91c]
800CF908	addu   a1, zero, zero
800CF90C	lui    a0, $800a
800CF910	addiu  a0, a0, $0cec
800CF914	jal    funcbeca4 [$800beca4]
800CF918	addu   a2, zero, zero

Lcf91c:	; 800CF91C
800CF91C	lui    a0, $8007
800CF920	lbu    a0, $22c4(a0)
800CF924	nop
800CF928	sll    a0, a0, $01
800CF92C	addu   a0, a0, s0
800CF930	lhu    v1, $0000(a0)
800CF934	addu   v0, zero, zero
800CF938	addiu  v1, v1, $0003
800CF93C	j      Lcf9a4 [$800cf9a4]
800CF940	sh     v1, $0000(a0)

Lcf944:	; 800CF944
800CF944	lui    v0, $800a
800CF948	lbu    v0, $d820(v0)
800CF94C	nop
800CF950	andi   v0, v0, $0003
800CF954	beq    v0, zero, Lcf96c [$800cf96c]
800CF958	addu   a1, zero, zero
800CF95C	lui    a0, $800a
800CF960	addiu  a0, a0, $0cf8
800CF964	jal    funcbeca4 [$800beca4]
800CF968	addu   a2, zero, zero

Lcf96c:	; 800CF96C
800CF96C	lui    a1, $8007
800CF970	lbu    a1, $22c4(a1)
800CF974	lui    a0, $800a
800CF978	lw     a0, $c6dc(a0)
800CF97C	sll    a1, a1, $01
800CF980	addu   a1, a1, s0
800CF984	lhu    v1, $0000(a1)
800CF988	addu   v0, zero, zero
800CF98C	addu   a0, a0, v1
800CF990	lhu    v1, $0000(a1)
800CF994	lbu    a0, $0002(a0)
800CF998	addiu  v1, v1, $0002
800CF99C	addu   a0, a0, v1
800CF9A0	sh     a0, $0000(a1)

Lcf9a4:	; 800CF9A4
800CF9A4	lw     ra, $001c(sp)
800CF9A8	lw     s0, $0018(sp)
800CF9AC	addiu  sp, sp, $0020
800CF9B0	jr     ra 
800CF9B4	nop
////////////////////////////////



////////////////////////////////
// funcc33b4
current_entity            = bu[800722c4];
current_script_pointer    = 800831fc + current_entity * 2;
target_script_pointer     = 800831fc + target_id * 2;
target_current_slot       = 8009a1c4 + target_id;
request_id                = A0; // 3 - reqEW
target_id                 = A1;
priority_id               = A2;
script_id                 = A3;
script_state              = 800833f8 + target_id * 8 + priority_id;
field_file_offset         = w[8009c6dc];
field_extra_offset_number = hu[field_file_offset + 6]
field_entity_number       = bu[field_file_offset + 2];

if (target_id == FF)
{
    A0 = hu[current_script_pointer];
    A0 = A0 + 3;
    [current_script_pointer] = h(A0);
    return 0;
}

if (request_id == 3)
{
    V1 = bu[80071A88 + target_id * 8 + priority_id];

    if (V1 == current_entity)
    {
        V1 = bu[script_state];

        if (V1 == 1)
        {
            return 1;
        }

        if (V1 == 2)
        {
            [script_state] = b(0);
            [80071A88 + target_id * 8 + priority_id] = b(FF);

            V1 = hu[current_script_pointer];
            V1 = V1 + 3;
            [current_script_pointer] = h(V1);
            return 0;
        }
    }
}

V0 = bu[target_current_slot];

if (V0 != priority_id)
{
    if (V0 > priority_id)
    {
        V0 = bu[script_state];

        if (V0 == 0)
        {
            return 1;
        }

        [801142D4 + target_id * 8 + priority_id] = b(script_id);

        // store script pointer
        V0 = bu[target_current_slot];
        A0 = hu[target_script_pointer];
        [80071748 + target_id * 10 + V0 * 2] = h(A0);

        // get requested script offset and store it to target entity script start point
        A1 = hu[field_file_offset + target_id * 40 + field_entity_number * 8 + field_extra_offset_number * 4 + script_id * 2 + 20];
        [target_script_pointer] = h(A1);

        [target_current_slot] = b(priority_id);

        V1 = bu[8007EB98 + target_id];
        if (V1 != FF)
        {
            V0 = w[8009C544];
            [V0 + V1 * 84 + 5D] = b(0);
        }

        [800716DC + target_id * 2] = h(0);

        if (request_id < 3)
        {
            V1 = hu[current_script_pointer];
            V1 = V1 + 3;
            [current_script_pointer] = h(V1);
            return 0;
        }

        if (request_id == 3)
        {
            [80071A88 + target_id * 8 + priority_id] = b(current_entity);
            [script_state] = b(1);
        }
        return 1;
    }
    else
    {
        V0 = hu[80071748 + target_id * 10 + priority_id * 2];

        if (V0 == 0)
        {
            // get requested script offset and store it to target entity script start point
            A1 = hu[field_file_offset + target_id * 40 + field_entity_number * 8 + field_extra_offset_number * 4 + script_id * 2 + 20];
            [80071748 + target_id * 10 + priority_id * 2] = h(A1);

            if (request_id < 3)
            {
                A0 = hu[current_script_pointer];
                A0 = A0 + 3;
                [current_script_pointer] = h(A0);
                return 0;
            }

            if (request_id == 3)
            {
                [80071A88 + target_id * 8 + priority_id] = b(current_entity);
                [script_state] = b(1);
            }

            return 1;
        }
    }
}

if (request_id == 1)
{
    [current_script_pointer] = h(hu[current_script_pointer] + 3);
    return 0;
}

return 1;
////////////////////////////////