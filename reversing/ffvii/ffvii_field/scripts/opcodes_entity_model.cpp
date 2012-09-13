////////////////////////////////
// 0x08 JOIN
800CFEA4	lui    v0, $8007
800CFEA8	lbu    v0, $22c4(v0)
800CFEAC	lui    a0, $800a
800CFEB0	lbu    a0, $d392(a0)
800CFEB4	lui    at, $800e
800CFEB8	sb     v0, $48f0(at)
800CFEBC	ori    v0, zero, $00ff
800CFEC0	beq    a0, v0, Lcff14 [$800cff14]
800CFEC4	ori    s0, zero, $0001
800CFEC8	lui    v0, $8007
800CFECC	lbu    v0, $22c4(v0)
800CFED0	nop
800CFED4	sll    v0, v0, $01
800CFED8	lui    at, $8008
800CFEDC	addiu  at, at, $31fc
800CFEE0	addu   at, at, v0
800CFEE4	lhu    v1, $0000(at)
800CFEE8	lui    v0, $800a
800CFEEC	lw     v0, $c6dc(v0)
800CFEF0	lui    at, $800a
800CFEF4	addiu  at, at, $ad30 (=-$52d0)
800CFEF8	addu   at, at, a0
800CFEFC	lbu    a0, $0000(at)
800CFF00	addu   v0, v0, v1
800CFF04	lbu    a1, $0001(v0)
800CFF08	jal    funcd0518 [$800d0518]
800CFF0C	nop
800CFF10	addu   s0, v0, zero

Lcff14:	; 800CFF14
800CFF14	lui    a0, $800a
800CFF18	lbu    a0, $d393(a0)
800CFF1C	ori    v0, zero, $00ff
800CFF20	beq    a0, v0, Lcff78 [$800cff78]
800CFF24	nop
800CFF28	lui    v0, $8007
800CFF2C	lbu    v0, $22c4(v0)
800CFF30	nop
800CFF34	sll    v0, v0, $01
800CFF38	lui    at, $8008
800CFF3C	addiu  at, at, $31fc
800CFF40	addu   at, at, v0
800CFF44	lhu    v1, $0000(at)
800CFF48	lui    v0, $800a
800CFF4C	lw     v0, $c6dc(v0)
800CFF50	lui    at, $800a
800CFF54	addiu  at, at, $ad30 (=-$52d0)
800CFF58	addu   at, at, a0
800CFF5C	lbu    a0, $0000(at)
800CFF60	addu   v0, v0, v1
800CFF64	lbu    a1, $0001(v0)
800CFF68	jal    funcd0518 [$800d0518]
800CFF6C	nop
800CFF70	j      Lcff7c [$800cff7c]
800CFF74	addu   v1, v0, zero

Lcff78:	; 800CFF78
800CFF78	ori    v1, zero, $0001

Lcff7c:	; 800CFF7C
800CFF7C	sll    v0, s0, $10
800CFF80	beq    v0, zero, Ld0098 [$800d0098]
800CFF84	sll    v0, v1, $10
800CFF88	beq    v0, zero, Ld0098 [$800d0098]
800CFF8C	addu   a1, zero, zero
800CFF90	ori    a2, zero, $00ff
800CFF94	sll    v0, a1, $10

loopcff98:	; 800CFF98
800CFF98	sra    a0, v0, $10
800CFF9C	lui    at, $800a
800CFFA0	addiu  at, at, $d391 (=-$2c6f)
800CFFA4	addu   at, at, a0
800CFFA8	lbu    v1, $0000(at)
800CFFAC	nop
800CFFB0	beq    v1, a2, Ld0034 [$800d0034]
800CFFB4	addiu  v0, a1, $0001
800CFFB8	lui    at, $800a
800CFFBC	addiu  at, at, $ad30 (=-$52d0)
800CFFC0	addu   at, at, v1
800CFFC4	lbu    v0, $0000(at)
800CFFC8	nop
800CFFCC	lui    at, $8008
800CFFD0	addiu  at, at, $1d90
800CFFD4	addu   at, at, v0
800CFFD8	sb     zero, $0000(at)
800CFFDC	bne    a0, zero, Ld0034 [$800d0034]
800CFFE0	addiu  v0, a1, $0001
800CFFE4	lui    at, $800a
800CFFE8	addiu  at, at, $ad30 (=-$52d0)
800CFFEC	addu   at, at, v1
800CFFF0	lbu    v0, $0000(at)
800CFFF4	nop
800CFFF8	beq    v0, a2, Ld0030 [$800d0030]
800CFFFC	nop
800D0000	lui    at, $8008
800D0004	addiu  at, at, $eb98 (=-$1468)
800D0008	addu   at, at, v0
800D000C	lbu    v0, $0000(at)
800D0010	nop
800D0014	sll    v1, v0, $05
800D0018	addu   v1, v1, v0
800D001C	lui    v0, $800a
800D0020	lw     v0, $c544(v0)
800D0024	sll    v1, v1, $02
800D0028	addu   v1, v1, v0
800D002C	sb     zero, $0059(v1)

Ld0030:	; 800D0030
800D0030	addiu  v0, a1, $0001

Ld0034:	; 800D0034
800D0034	addu   a1, v0, zero
800D0038	sll    v0, v0, $10
800D003C	sra    v0, v0, $10
800D0040	slti   v0, v0, $0003
800D0044	bne    v0, zero, loopcff98 [$800cff98]
800D0048	sll    v0, a1, $10
800D004C	lui    a0, $800a
800D0050	lw     a0, $c6e0(a0)
800D0054	lui    v1, $8008
800D0058	lbu    v1, $1dc4(v1)
800D005C	addu   v0, zero, zero
800D0060	sb     v1, $0032(a0)
800D0064	lui    a1, $8007
800D0068	lbu    a1, $22c4(a1)
800D006C	lui    v1, $8008
800D0070	addiu  v1, v1, $31fc
800D0074	sll    a1, a1, $01
800D0078	addu   a1, a1, v1
800D007C	lhu    v1, $0000(a1)
800D0080	ori    a0, zero, $00ff
800D0084	lui    at, $800e
800D0088	sb     a0, $48f0(at)
800D008C	addiu  v1, v1, $0002
800D0090	j      Ld016c [$800d016c]
800D0094	sh     v1, $0000(a1)

Ld0098:	; 800D0098
800D0098	lui    v0, $800a
800D009C	lw     v0, $c6e0(v0)
800D00A0	ori    a2, zero, $0001
800D00A4	sb     a2, $0032(v0)
800D00A8	lui    v0, $800a
800D00AC	lbu    v0, $d391(v0)
800D00B0	ori    v1, zero, $00ff
800D00B4	beq    v0, v1, Ld0168 [$800d0168]
800D00B8	nop
800D00BC	lui    at, $800a
800D00C0	addiu  at, at, $ad30 (=-$52d0)
800D00C4	addu   at, at, v0
800D00C8	lbu    a1, $0000(at)
800D00CC	nop
800D00D0	beq    a1, v1, Ld016c [$800d016c]
800D00D4	ori    v0, zero, $0001
800D00D8	lui    at, $8008
800D00DC	addiu  at, at, $eb98 (=-$1468)
800D00E0	addu   at, at, a1
800D00E4	lbu    v1, $0000(at)
800D00E8	lui    at, $8008
800D00EC	addiu  at, at, $1d90
800D00F0	addu   at, at, a1
800D00F4	sb     a2, $0000(at)
800D00F8	sll    v0, v1, $05
800D00FC	addu   v0, v0, v1
800D0100	lui    v1, $800a
800D0104	lw     v1, $c544(v1)
800D0108	sll    v0, v0, $02
800D010C	addu   v0, v0, v1
800D0110	sb     zero, $005d(v0)
800D0114	lui    at, $8008
800D0118	addiu  at, at, $eb98 (=-$1468)
800D011C	addu   at, at, a1
800D0120	lbu    v1, $0000(at)
800D0124	lui    a0, $800a
800D0128	lw     a0, $c544(a0)
800D012C	sll    v0, v1, $05
800D0130	addu   v0, v0, v1
800D0134	sll    v0, v0, $02
800D0138	addu   v0, v0, a0
800D013C	sh     zero, $006a(v0)
800D0140	lui    at, $8008
800D0144	addiu  at, at, $eb98 (=-$1468)
800D0148	addu   at, at, a1
800D014C	lbu    v1, $0000(at)
800D0150	nop
800D0154	sll    v0, v1, $05
800D0158	addu   v0, v0, v1
800D015C	sll    v0, v0, $02
800D0160	addu   v0, v0, a0
800D0164	sb     a2, $0059(v0)

Ld0168:	; 800D0168
800D0168	ori    v0, zero, $0001

Ld016c:	; 800D016C
800D016C	lw     ra, $0014(sp)
800D0170	lw     s0, $0010(sp)
800D0174	addiu  sp, sp, $0018
800D0178	jr     ra 
800D017C	nop
////////////////////////////////



////////////////////////////////
// 0x09 SPLIT
V0 = bu[800722C4];
[800E48F0] = b(V0);

S2 = bu[8009D392]; // second party member
if (S2 != FF)
{
    A0 = 1;
    A1 = 4;
    read_memory_block_two_bytes;
    x1 = V0;

    A0 = 2;
    A1 = 6;
    read_memory_block_two_bytes;
    y1 = V0;

    A0 = 3;
    A1 = 8;
    read_memory_block_one_byte;
    dir1 = V0;

    V1 = bu[800722C4];
    A0 = hu[800831FC + V1 * 2];
    field_file_offset = w[8009C6DC];
    speed = bu[field_file_offset + A0 + E];

    A0 = bu[8009AD30 + S2];
    A1 = x1;
    A2 = y1;
    A3 = dir1;
    [SP + 10] = w(speed);
    funcd0938;
    S2 = V0;
}
else
{
    S2 = 1;
}

S3 = bu[8009D393]; // third party member
if (S3 != FF)
{
    A0 = 4;
    A1 = 9;
    read_memory_block_two_bytes;
    x2 = V0;

    A0 = 5;
    A1 = B;
    read_memory_block_two_bytes;
    y2 = V0;

    A0 = 6;
    A1 = D;
    read_memory_block_one_byte;
    dir2 = V0;

    V1 = w[800722C4];
    A0 = hu[800831FC + V1 * 2];
    field_file_offset = w[8009C6DC];
    speed = bu[field_file_offset + A0 + E];

    A0 = bu[8009AD30 + S3];
    A1 = x2
    A2 = y2;
    A3 = dir2;
    [SP + 10] = w(speed);
    funcd0938;
    V1 = V0;
}
else
{
    V1 = 1;
}



// if all characters finish moving
if (S2 != 0 && V1 != 0)
{
    // set solid on for all characters
    party_id = 0;
    loopd0324:	; 800D0324
        character_id = bu[8009D391 + A1];
        if (character_id != FF)
        {
            entity_id = bu[8009AD30 + character_id];
            [80081D90 + entity_id] = b(0);
            if (A1 == 0 && entity_id != FF)
            {
                // set solid on
                model_id = bu[8007EB98 + entity_id];
                V1 = w[8009C544];
                [V1 + model_id * 84 + 59] = b(0);
            }
        }

        party_id = party_id + 1;
        V0 = party_id < 3;
    800D03D0	bne    v0, zero, loopd0324 [$800d0324]

    A0 = w[8009C6E0];
    previous_uc = bu[80081DC4];
    [A0 + 32] = b(previous_uc); // set UC

    [800E48F0] = b(FF);

    // move csript pointer by F
    A1 = bu[800722C4];
    V1 = hu[800831FC + A1 * 2];
    V1 = V1 + F;
    [800831FC + A1 * 2] = h(V1);

    return 0;
}
else
{
    V0 = w[8009C6E0];
    [V0 + 32] = b(1); // set UC

    character_id = bu[8009D391]; // character in slot 1
    if (character_id != FF)
    {
        entity_id = bu[8009AD30 + character_id];
        if (entity_id != FF)
        {
            [80081D90 + entity_id] = b(1);

            A0 = w[8009C544];
            model_id = bu[8007EB98 + entity_id];
            [A0 + model_id * 84 + 5D] = b(0);
            [A0 + model_id * 84 + 6A] = h(0);
            [A0 + model_id * 84 + 59] = b(1); // solid off
        }
    }
}

return 1;
////////////////////////////////



////////////////////////////////
// 0x26 BLINK
800D4448	lui    v1, $8007
800D444C	lbu    v1, $22c4(v1)
800D4450	nop
800D4454	lui    at, $8008
800D4458	addiu  at, at, $eb98 (=-$1468)
800D445C	addu   at, at, v1
800D4460	lbu    a0, $0000(at)
800D4464	ori    v0, zero, $00ff
800D4468	beq    a0, v0, Ld44ac [$800d44ac]
800D446C	sll    v0, a0, $05
800D4470	addu   v0, v0, a0
800D4474	sll    v1, v1, $01
800D4478	lui    at, $8008
800D447C	addiu  at, at, $31fc
800D4480	addu   at, at, v1
800D4484	lhu    a0, $0000(at)
800D4488	lui    v1, $800a
800D448C	lw     v1, $c6dc(v1)
800D4490	sll    v0, v0, $02
800D4494	addu   v1, v1, a0
800D4498	lui    a0, $800a
800D449C	lw     a0, $c544(a0)
800D44A0	lbu    v1, $0001(v1)
800D44A4	addu   v0, v0, a0
800D44A8	sb     v1, $0008(v0)

Ld44ac:	; 800D44AC
800D44AC	lui    v0, $8007
800D44B0	lbu    v0, $22c4(v0)
800D44B4	lui    v1, $8008
800D44B8	addiu  v1, v1, $31fc
800D44BC	sll    v0, v0, $01
800D44C0	addu   v0, v0, v1
800D44C4	lhu    v1, $0000(v0)
800D44C8	nop
800D44CC	addiu  v1, v1, $0002
800D44D0	sh     v1, $0000(v0)
800D44D4	addu   v0, zero, zero
800D44D8	lw     ra, $0010(sp)
800D44DC	addiu  sp, sp, $0018
800D44E0	jr     ra 
800D44E4	nop
////////////////////////////////



////////////////////////////////
// 0x2A PMOVA
800C7C3C	lui    v0, $800a
800C7C40	lbu    v0, $d820(v0)
800C7C44	addiu  sp, sp, $ffe8 (=-$18)
800C7C48	andi   v0, v0, $0003
800C7C4C	beq    v0, zero, Lc7c64 [$800c7c64]
800C7C50	sw     ra, $0010(sp)
800C7C54	lui    a0, $800a
800C7C58	addiu  a0, a0, $099c
800C7C5C	jal    funcbead4 [$800bead4]
800C7C60	ori    a1, zero, $0001

Lc7c64:	; 800C7C64
800C7C64	lui    v0, $8007
800C7C68	lbu    v0, $22c4(v0)
800C7C6C	nop
800C7C70	sll    v0, v0, $01
800C7C74	lui    at, $8008
800C7C78	addiu  at, at, $31fc
800C7C7C	addu   at, at, v0
800C7C80	lhu    v1, $0000(at)
800C7C84	lui    v0, $800a
800C7C88	lw     v0, $c6dc(v0)
800C7C8C	nop
800C7C90	addu   v0, v0, v1
800C7C94	lbu    v0, $0001(v0)
800C7C98	nop
800C7C9C	lui    at, $800a
800C7CA0	addiu  at, at, $d391 (=-$2c6f)
800C7CA4	addu   at, at, v0
800C7CA8	lbu    a0, $0000(at)
800C7CAC	ori    v0, zero, $00ff
800C7CB0	bne    a0, v0, Lc7cc0 [$800c7cc0]
800C7CB4	nop
800C7CB8	j      Lc7cd0 [$800c7cd0]
800C7CBC	ori    a0, zero, $00ff

Lc7cc0:	; 800C7CC0
800C7CC0	lui    at, $800a
800C7CC4	addiu  at, at, $ad30 (=-$52d0)
800C7CC8	addu   at, at, a0
800C7CCC	lbu    a0, $0000(at)

Lc7cd0:	; 800C7CD0
800C7CD0	jal    funcc7d5c [$800c7d5c]
800C7CD4	nop
800C7CD8	lw     ra, $0010(sp)
800C7CDC	addiu  sp, sp, $0018
800C7CE0	jr     ra 
800C7CE4	nop
////////////////////////////////



////////////////////////////////
// 0x33 UC
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
V0 = bu[V0 + V1 + 1];

V1 = w[8009C6E0];
[V1 + 32] = b(V0);
[80081DC4] = b(V0);

V0 = bu[80081DC4];
if (V0 == 0)
{
    V0 = w[8009C6E0];
    V0 = [V0 + 2A];
    [800756E8 + V0] = b(00);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0x34 PDIRA
800C81E8	lui    v0, $8007
800C81EC	lbu    v0, $22c4(v0)
800C81F0	nop
800C81F4	sll    v0, v0, $01
800C81F8	lui    at, $8008
800C81FC	addiu  at, at, $31fc
800C8200	addu   at, at, v0
800C8204	lhu    v1, $0000(at)
800C8208	lui    v0, $800a
800C820C	lw     v0, $c6dc(v0)
800C8210	nop
800C8214	addu   v0, v0, v1
800C8218	lbu    v0, $0001(v0)
800C821C	nop
800C8220	lui    at, $800a
800C8224	addiu  at, at, $d391 (=-$2c6f)
800C8228	addu   at, at, v0
800C822C	lbu    a0, $0000(at)
800C8230	ori    v0, zero, $00ff
800C8234	bne    a0, v0, Lc8244 [$800c8244]
800C8238	nop
800C823C	j      Lc8254 [$800c8254]
800C8240	ori    a0, zero, $00ff

Lc8244:	; 800C8244
800C8244	lui    at, $800a
800C8248	addiu  at, at, $ad30 (=-$52d0)
800C824C	addu   at, at, a0
800C8250	lbu    a0, $0000(at)

Lc8254:	; 800C8254
800C8254	jal    set_direction_to_current_entity_by_entity_id [$800c826c]
800C8258	nop
800C825C	lw     ra, $0010(sp)
800C8260	addiu  sp, sp, $0018
800C8264	jr     ra 
800C8268	nop
////////////////////////////////



////////////////////////////////
// 0x35 PTURA
800C85B0	lui    v0, $8007
800C85B4	lbu    v0, $22c4(v0)
800C85B8	nop
800C85BC	sll    v0, v0, $01
800C85C0	lui    at, $8008
800C85C4	addiu  at, at, $31fc
800C85C8	addu   at, at, v0
800C85CC	lhu    v1, $0000(at)
800C85D0	lui    v0, $800a
800C85D4	lw     v0, $c6dc(v0)
800C85D8	nop
800C85DC	addu   v0, v0, v1
800C85E0	lbu    v0, $0001(v0)
800C85E4	nop
800C85E8	lui    at, $800a
800C85EC	addiu  at, at, $d391 (=-$2c6f)
800C85F0	addu   at, at, v0
800C85F4	lbu    a0, $0000(at)
800C85F8	ori    v0, zero, $00ff
800C85FC	bne    a0, v0, Lc860c [$800c860c]
800C8600	nop
800C8604	j      Lc861c [$800c861c]
800C8608	ori    a0, zero, $00ff

Lc860c:	; 800C860C
800C860C	lui    at, $800a
800C8610	addiu  at, at, $ad30 (=-$52d0)
800C8614	addu   at, at, a0
800C8618	lbu    a0, $0000(at)

Lc861c:	; 800C861C
800C861C	jal    funcc8634 [$800c8634]
800C8620	nop
800C8624	lw     ra, $0010(sp)
800C8628	addiu  sp, sp, $0018
800C862C	jr     ra 
800C8630	nop
////////////////////////////////



////////////////////////////////
// 0x6D IDLCK
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A2 = V0 + V1;
V1 = bu[A2 + 2];
V0 = bu[A2 + 1];
V1 = V1 << 8;
V0 = V0 | V1; // xxxxxxxx triangle id
A0 = V0;
A1 = V0 >> 3; // 000xxxxx
V0 = A1 << 3; // xxxxx000
V1 = bu[A2 + 3];

A2 = A0 - V0; // 00000xxx

if (V1 != 0)
{
    V0 = w[8009C6E0];
    V0 = V0 + A1;
    V1 = 1 << A2;
    A0 = [V0 + B2];
    A0 = A0 | V1;
}
else
{
    V0 = w[8009C6E0];
    V1 = 1 << A2;
    V0 = V0 + A1;
    A0 = [V0 + B2];
    V1 = 0 NOR V1;
    A0 = A0 & V1;
}

[V0 + B2] = b(A0);

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);
////////////////////////////////



////////////////////////////////
// 0x73 PGTDR
800CA254	lui    v0, $8007
800CA258	lbu    v0, $22c4(v0)
800CA25C	addiu  sp, sp, $ffe8 (=-$18)
800CA260	sw     ra, $0014(sp)
800CA264	sw     s0, $0010(sp)
800CA268	sll    v0, v0, $01
800CA26C	lui    at, $8008
800CA270	addiu  at, at, $31fc
800CA274	addu   at, at, v0
800CA278	lhu    v1, $0000(at)
800CA27C	lui    v0, $800a
800CA280	lw     v0, $c6dc(v0)
800CA284	nop
800CA288	addu   v0, v0, v1
800CA28C	lbu    v1, $0002(v0)
800CA290	nop
800CA294	sltiu  v0, v1, $0003
800CA298	beq    v0, zero, Lca354 [$800ca354]
800CA29C	nop
800CA2A0	lui    at, $800a
800CA2A4	addiu  at, at, $d391 (=-$2c6f)
800CA2A8	addu   at, at, v1
800CA2AC	lbu    v0, $0000(at)
800CA2B0	ori    v1, zero, $00ff
800CA2B4	beq    v0, v1, Lca354 [$800ca354]
800CA2B8	nop
800CA2BC	lui    at, $800a
800CA2C0	addiu  at, at, $ad30 (=-$52d0)
800CA2C4	addu   at, at, v0
800CA2C8	lbu    s0, $0000(at)
800CA2CC	nop
800CA2D0	beq    s0, v1, Lca354 [$800ca354]
800CA2D4	nop
800CA2D8	lui    at, $8008
800CA2DC	addiu  at, at, $eb98 (=-$1468)
800CA2E0	addu   at, at, s0
800CA2E4	lbu    v0, $0000(at)
800CA2E8	nop
800CA2EC	beq    v0, v1, Lca354 [$800ca354]
800CA2F0	nop
800CA2F4	lui    v0, $800a
800CA2F8	lbu    v0, $d820(v0)
800CA2FC	nop
800CA300	andi   v0, v0, $0003
800CA304	beq    v0, zero, Lca31c [$800ca31c]
800CA308	nop
800CA30C	lui    a0, $800a
800CA310	addiu  a0, a0, $0a60
800CA314	jal    funcbead4 [$800bead4]
800CA318	ori    a1, zero, $0003

Lca31c:	; 800CA31C
800CA31C	lui    at, $8008
800CA320	addiu  at, at, $eb98 (=-$1468)
800CA324	addu   at, at, s0
800CA328	lbu    v0, $0000(at)
800CA32C	ori    a0, zero, $0002
800CA330	sll    v1, v0, $05
800CA334	addu   v1, v1, v0
800CA338	lui    v0, $800a
800CA33C	lw     v0, $c544(v0)
800CA340	sll    v1, v1, $02
800CA344	addu   v1, v1, v0
800CA348	lbu    a2, $0038(v1)
800CA34C	jal    store_memory_block_one_byte [$800bf3ac]
800CA350	ori    a1, zero, $0003

Lca354:	; 800CA354
800CA354	lui    v0, $8007
800CA358	lbu    v0, $22c4(v0)
800CA35C	lui    v1, $8008
800CA360	addiu  v1, v1, $31fc
800CA364	sll    v0, v0, $01
800CA368	addu   v0, v0, v1
800CA36C	lhu    v1, $0000(v0)
800CA370	nop
800CA374	addiu  v1, v1, $0004
800CA378	sh     v1, $0000(v0)
800CA37C	addu   v0, zero, zero
800CA380	lw     ra, $0014(sp)
800CA384	lw     s0, $0010(sp)
800CA388	addiu  sp, sp, $0018
800CA38C	jr     ra 
800CA390	nop
////////////////////////////////



////////////////////////////////
// 0x74 GETPC
800D2F3C	lui    v0, $800a
800D2F40	lbu    v0, $d820(v0)
800D2F44	addiu  sp, sp, $ffe0 (=-$20)
800D2F48	sw     ra, $001c(sp)
800D2F4C	andi   v0, v0, $0003
800D2F50	beq    v0, zero, Ld2f68 [$800d2f68]
800D2F54	sw     s0, $0018(sp)
800D2F58	lui    a0, $800a
800D2F5C	addiu  a0, a0, $0f40
800D2F60	jal    funcbead4 [$800bead4]
800D2F64	ori    a1, zero, $0003

Ld2f68:	; 800D2F68
800D2F68	lui    v0, $8007
800D2F6C	lbu    v0, $22c4(v0)
800D2F70	nop
800D2F74	sll    v0, v0, $01
800D2F78	lui    at, $8008
800D2F7C	addiu  at, at, $31fc
800D2F80	addu   at, at, v0
800D2F84	lhu    v1, $0000(at)
800D2F88	lui    v0, $800a
800D2F8C	lw     v0, $c6dc(v0)
800D2F90	nop
800D2F94	addu   v0, v0, v1
800D2F98	lbu    v1, $0002(v0)
800D2F9C	lui    s0, $8008
800D2FA0	addiu  s0, s0, $31fc
800D2FA4	slti   v0, v1, $0003
800D2FA8	beq    v0, zero, Ld2fc8 [$800d2fc8]
800D2FAC	ori    a0, zero, $0002
800D2FB0	lui    at, $800a
800D2FB4	addiu  at, at, $cbdc (=-$3424)
800D2FB8	addu   at, at, v1
800D2FBC	lbu    a2, $0000(at)
800D2FC0	jal    store_memory_block_one_byte [$800bf3ac]
800D2FC4	ori    a1, zero, $0003

Ld2fc8:	; 800D2FC8
800D2FC8	lui    v1, $8007
800D2FCC	lbu    v1, $22c4(v1)
800D2FD0	nop
800D2FD4	sll    v1, v1, $01
800D2FD8	addu   v1, v1, s0
800D2FDC	lhu    v0, $0000(v1)
800D2FE0	nop
800D2FE4	addiu  v0, v0, $0004
800D2FE8	sh     v0, $0000(v1)
800D2FEC	addu   v0, zero, zero
800D2FF0	lw     ra, $001c(sp)
800D2FF4	lw     s0, $0018(sp)
800D2FF8	addiu  sp, sp, $0020
800D2FFC	jr     ra 
800D3000	nop
////////////////////////////////



////////////////////////////////
// 0x75 PXYZI
800CA77C	lui    v0, $8007
800CA780	lbu    v0, $22c4(v0)
800CA784	lui    v1, $800a
800CA788	lbu    v1, $d820(v1)
800CA78C	addiu  sp, sp, $ffe8 (=-$18)
800CA790	sw     ra, $0014(sp)
800CA794	sw     s0, $0010(sp)
800CA798	sll    v0, v0, $01
800CA79C	lui    at, $8008
800CA7A0	addiu  at, at, $31fc
800CA7A4	addu   at, at, v0
800CA7A8	lhu    a0, $0000(at)
800CA7AC	lui    v0, $800a
800CA7B0	lw     v0, $c6dc(v0)
800CA7B4	andi   v1, v1, $0003
800CA7B8	addu   v0, v0, a0
800CA7BC	lbu    s0, $0003(v0)
800CA7C0	beq    v1, zero, Lca7dc [$800ca7dc]
800CA7C4	andi   v1, s0, $00ff
800CA7C8	lui    a0, $800a
800CA7CC	addiu  a0, a0, $0a80
800CA7D0	jal    funcbead4 [$800bead4]
800CA7D4	ori    a1, zero, $0007
800CA7D8	andi   v1, s0, $00ff

Lca7dc:	; 800CA7DC
800CA7DC	sltiu  v0, v1, $0003
800CA7E0	beq    v0, zero, Lca91c [$800ca91c]
800CA7E4	nop
800CA7E8	lui    at, $800a
800CA7EC	addiu  at, at, $d391 (=-$2c6f)
800CA7F0	addu   at, at, v1
800CA7F4	lbu    v1, $0000(at)
800CA7F8	nop
800CA7FC	sltiu  v0, v1, $0009
800CA800	beq    v0, zero, Lca91c [$800ca91c]
800CA804	ori    v0, zero, $00ff
800CA808	lui    at, $800a
800CA80C	addiu  at, at, $ad30 (=-$52d0)
800CA810	addu   at, at, v1
800CA814	lbu    s0, $0000(at)
800CA818	nop
800CA81C	lui    at, $8008
800CA820	addiu  at, at, $eb98 (=-$1468)
800CA824	addu   at, at, s0
800CA828	lbu    v1, $0000(at)
800CA82C	nop
800CA830	beq    v1, v0, Lca91c [$800ca91c]
800CA834	ori    a0, zero, $0001
800CA838	sll    v0, v1, $05
800CA83C	addu   v0, v0, v1
800CA840	lui    v1, $800a
800CA844	lw     v1, $c544(v1)
800CA848	sll    v0, v0, $02
800CA84C	addu   v0, v0, v1
800CA850	lw     a2, $000c(v0)
800CA854	ori    a1, zero, $0004
800CA858	sll    a2, a2, $04
800CA85C	jal    store_memory_block_two_bytes [$800c0248]
800CA860	sra    a2, a2, $10
800CA864	lui    at, $8008
800CA868	addiu  at, at, $eb98 (=-$1468)
800CA86C	addu   at, at, s0
800CA870	lbu    v1, $0000(at)
800CA874	ori    a0, zero, $0002
800CA878	sll    v0, v1, $05
800CA87C	addu   v0, v0, v1
800CA880	lui    v1, $800a
800CA884	lw     v1, $c544(v1)
800CA888	sll    v0, v0, $02
800CA88C	addu   v0, v0, v1
800CA890	lw     a2, $0010(v0)
800CA894	ori    a1, zero, $0005
800CA898	sll    a2, a2, $04
800CA89C	jal    store_memory_block_two_bytes [$800c0248]
800CA8A0	sra    a2, a2, $10
800CA8A4	lui    at, $8008
800CA8A8	addiu  at, at, $eb98 (=-$1468)
800CA8AC	addu   at, at, s0
800CA8B0	lbu    v1, $0000(at)
800CA8B4	ori    a0, zero, $0003
800CA8B8	sll    v0, v1, $05
800CA8BC	addu   v0, v0, v1
800CA8C0	lui    v1, $800a
800CA8C4	lw     v1, $c544(v1)
800CA8C8	sll    v0, v0, $02
800CA8CC	addu   v0, v0, v1
800CA8D0	lw     a2, $0014(v0)
800CA8D4	ori    a1, zero, $0006
800CA8D8	sll    a2, a2, $04
800CA8DC	jal    store_memory_block_two_bytes [$800c0248]
800CA8E0	sra    a2, a2, $10
800CA8E4	lui    at, $8008
800CA8E8	addiu  at, at, $eb98 (=-$1468)
800CA8EC	addu   at, at, s0
800CA8F0	lbu    v1, $0000(at)
800CA8F4	ori    a0, zero, $0004
800CA8F8	sll    v0, v1, $05
800CA8FC	addu   v0, v0, v1
800CA900	lui    v1, $800a
800CA904	lw     v1, $c544(v1)
800CA908	sll    v0, v0, $02
800CA90C	addu   v0, v0, v1
800CA910	lh     a2, $0072(v0)
800CA914	jal    store_memory_block_two_bytes [$800c0248]
800CA918	ori    a1, zero, $0007

Lca91c:	; 800CA91C
800CA91C	lui    v0, $8007
800CA920	lbu    v0, $22c4(v0)
800CA924	lui    v1, $8008
800CA928	addiu  v1, v1, $31fc
800CA92C	sll    v0, v0, $01
800CA930	addu   v0, v0, v1
800CA934	lhu    v1, $0000(v0)
800CA938	nop
800CA93C	addiu  v1, v1, $0008
800CA940	sh     v1, $0000(v0)
800CA944	addu   v0, zero, zero
800CA948	lw     ra, $0014(sp)
800CA94C	lw     s0, $0010(sp)
800CA950	addiu  sp, sp, $0018
800CA954	jr     ra 
800CA958	nop
////////////////////////////////



////////////////////////////////
// 0x7E TLKON
V1 = bu[800722C4];
A0 = bu[8007EB98 + V1];

if (A0 != FF)
{
    A0 = hu[800831FC + V1 * 2];
    V1 = w[8009C6DC];
    V1 = bu[V1 + A0 + 1];
    V0 = w[8009C544];
    [V0 + A0 * 84 + 5B] = b(V1);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xA0 PC
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V0 = w[8009C6DC];
A2 = bu[V0 + V1 + 1];

[8009AD30 + A2] = b(A0); // assign entity to pc

V0 = bu[8009D391]; // party info (1st character)

if (V0 == A2)
{
    V0 = bu[800722C4];
    V0 = [8007EB98 + V0];

    V1 = w[8009C6E0];
    [V1 + 2A] = h(V0);
}
else
{
    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = w[8009C544];
    [V0 + V1 * 84 + 59] = b(01);
    [V0 + V1 * 84 + 5B] = b(01);
    [V0 + V1 * 84 + 5C] = b(00);
}

// move pointer by 2
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 2;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// 0xA1 CHAR
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model_offset  = model_data_offset + current_model * 84;

V1 = bu[8009C6C4];
V0 = V1 + 1;
[8009C6C4] = b(V0);
[8007EB98 + current_entity] = b(V1);

A0 = hu[800831FC + current_entity * 2]; // get current entity script pointer
V1 = bu[8007EB98 + current_entity];     // get current entity model id

V1 = w[8009C6DC];           // current field file offset
V1 = V1 + A0;               // current entity script pointer in global offset

V1 = bu[V1 + 1];            // read second byte
[current_model_offset + 66] = h(V1);

V1 = bu[8007EB98 + A1];
[current_model_offset + 5C] = b(01);

V1 = bu[8007EB98 + current_entity];
[current_model_offset + 57] = b(current_entity);

// move pointer by 2
V0 = hu[800831FC + current_entity * 2];
V0 = V0 + 2;
[800831FC + current_entity * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xA4 VISI
V1 = bu[800722C4];
A0 = bu[8007EB98 + V1];

if (A0 != FF)
{
    V0 = A0 * 84;
    A0 = hu[800831FC + V1 * 2];
    V1 = w[8009C6DC];
    V1 = V1 + A0;
    V1 = bu[V1 + 1];
    A0 = w[8009C544];
    V0 = V0 + A0;
    [V0 + 5C] = b(V1);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xA5 XYZI
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;

if (current_model != FF)
{
    A0 = 1;
    A1 = 3;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 0C] = w(V0);

    A0 = 2;
    A1 = 5;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 10] = w(V0);

    A0 = 3;
    A1 = 7;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 14] = w(V0);

    A0 = 4;
    A1 = 9;
    read_memory_block_two_bytes;
    [current_model_offset + 72] = h(V0);
}

// move pointer by B
V0 = hu[800831FC + current_entity * 2];
V0 = V0 + B;
[800831FC + current_entity * 2] = h(V0);

return 1;
////////////////////////////////



////////////////////////////////
// 0xA6 XYI
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;

if (current_model != FF)
{
    A0 = 1;
    A1 = 3;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 0C] = w(V0);

    A0 = 2;
    A1 = 5;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 10] = w(V0);

    A0 = 3;
    A1 = 7;
    read_memory_block_two_bytes;
    [current_model_offset + 72] = w(V0);
}

// move pointer by 9
[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 9);

return 1;
////////////////////////////////



////////////////////////////////
// 0xA7 XYZ
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;

if (current_model != FF)
{
    A0 = 1;
    A1 = 3;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 0C] = w(V0);

    A0 = 2;
    A1 = 5;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 10] = w(V0);

    A0 = 3;
    A1 = 7;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 14] = w(V0);
}

// move pointer by 9
V0 = hu[800831FC + current_entity  * 2];
V0 = V0 + 9;
[800831FC + current_entity  * 2] = h(V0);

return 1;
////////////////////////////////



////////////////////////////////
0xA8 MOVE
current_entity        = bu[800722c4];
model_data_offset     = w[8009c544];
current_model         = bu[8007eb98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831fc + current_entity * 2;
game_data_offset      = w[8009c6e0];
movement_speed        = hu[current_model_offset + 70]



if( current_model == ff ) // if not visible entity
{
    [script_pointer_offset] = h(hu[script_pointer_offset] + 6);
    return 0;
}

// init some value
[current_model_offset + 68] = h(0);
// not lock rotation
[current_model_offset + 37] = b(0);

// set destination X
A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
V0 = V0 << 0c;
[current_model_offset + 78] = w(V0);

// set destination Y
A0 = 2;
A1 = 4;
read_memory_block_two_bytes;
V0 = V0 << 0c;
[current_model_offset + 7C] = w(V0);



A0 = hu[game_data_offset + 10];
if( A0 * 3 < movement_speed )
{
    if( bu[current_model_offset + 5e] == 2 ) // run animation
    {
        [800756E8 + current_model] = b(01);

        A1 = bu[current_model_offset + 5D];

        if (A0 != 1)
        {
            [current_model_offset + 5D] = b(01);
            [current_model_offset + 6A] = h(00);

            return 1;
        }

        A0 = h[current_model_offset + 6A];

        if (A0 == 1)
        {
            return 1;
        }
        elseif (A0 == 2)
        {
            [current_model_offset + 5D] = b(00);
            [current_model_offset + 6A] = b(00);

            [800756E8 + current_model] = b(00);

            V0 = hu[script_pointer_offset];
            V0 = V0 + 6;
            [script_pointer_offset] = h(V0);
            return 0;
        }

        [current_model_offset + 5D] = b(01);
        [current_model_offset + 6A] = b(00);

        return 1;
    }

    [current_model_offset + 5e] = b(02);
}
else
{
    if( bu[current_model_offset + 5E] == 1 ) // walk animation
    {
        [800756E8 + current_model] = b(01);

        A1 = bu[current_model_offset + 5D];

        if (A1 != 1)
        {
            [current_model_offset + 5D] = b(01);
            [current_model_offset + 6A] = b(00);

            return 1;
        }

        A0 = h[current_model_offset + 6A];

        if (A0 == 1)
        {
            return 1;
        }
        elseif (A0 == 2)
        {
            [current_model_offset + 5D] = b(00);
            [current_model_offset + 6A] = b(00);

            [800756E8 + current_model] = b(00);

            V0 = hu[script_pointer_offset];
            V0 = V0 + 6;
            [script_pointer_offset] = h(V0);
            return 0;
        }

        [current_model_offset + 5D] = b(01);
        [current_model_offset + 6A] = b(00);

        return 1;
    }

    [current_model_offset + 5E] = b(01);
}



[current_model_offset + 60] = h(10);
[current_model_offset + 62] = h(00);

V1 = w[8008357C];
A1 = bu[V1 + current_model * 8 + 04];
V1 = w[8004A62C];
V1 = w[V1 + 04];

A0 = w[V1 + A1 * 24 + 1C];
A1 = hu[V1 + A1 * 24 + 1A];

V0 = bu[80074F02 + current_model * 84];
V0 = hu[A0 + A1 + V0 * 10];
V0 = V0 - 1;
[current_model_offset + 64] = h(V0)

[800756E8 + current_model] = b(01);

A1 = bu[current_model_offset + 5D];

if (A1 != 1)
{
    [current_model_offset + 5D] = b(01);
    [current_model_offset + 6A] = b(00);

    return 1;
}

A0 = h[current_model_offset + 6A];

if (A0 == A1)
{
    return 1;
}

if (A0 == 2)
{
    [current_model_offset + 5D] = b(00);
    [current_model_offset + 6A] = b(00);

    [800756E8 + current_model] = b(00);

    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);

    return 0;
}

[current_model_offset + 5D] = b(01);
[current_model_offset + 6A] = b(00);
return 1;
////////////////////////////////



////////////////////////////////
// 0xA9 CMOVE
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831FC + current_entity * 2;

if (current_model == FF) // if not visible entity
{
    [script_pointer_offset] = h(hu[script_pointer_offset] + 6);
    return 0;
}

// init some value
[current_model_offset + 68] = h(0);
// lock rotation
[current_model_offset + 37] = b(1);

// set destination X
A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 78] = w(V0);

// set destination Y
A0 = 2;
A1 = 4;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 7C] = w(V0);

A1 = [current_model_offset + 5D];

if (A1 != 1)
{
    [current_model_offset + 5D] = b(1);
    [current_model_offset + 6A] = h(0);
    return 1;
}

A0 = h[current_model_offset + 6A];
if (A0 == 1)
{
    return 1;
}

if (A0 == 2)
{
    // unlock rotation
    [current_model_offset + 37] = b(0);
    [current_model_offset + 5D] = b(0);
    [current_model_offset + 6A] = b(0);

    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);
    return 0;
}

[current_model_offset + 5D] = b(1);
[current_model_offset + 6A] = h(0);
return 1;
////////////////////////////////



////////////////////////////////
// 0xAA MOVA
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A0 = bu[V0 + V1 + 1];
funcc7d5c;

return V0;
////////////////////////////////



////////////////////////////////
// 0xAB TURA
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = bu[V0 + V1 + 1];
funcc8634;

return V0;
////////////////////////////////



////////////////////////////////
// 0xAD FMOVE
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831FC + current_entity * 2;

if (current_model == FF) // if not visible entity
{
    [script_pointer_offset] = h(hu[script_pointer_offset] + 6);

    return 0;
}

[current_model_offset + 68] = h(0);
[current_model_offset + 37] = b(0);

// set destination X
A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 78] = w(V0);

// set destination Y
A0 = 2;
A1 = 4;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 7C] = w(V0);

A1 = [current_model_offset + 5D];
if (A1 != 1)
{
    [current_model_offset + 5D] = b(1);
    [current_model_offset + 6A] = h(0);
    return 1;
}

A0 = h[current_model_offset + 6A];
if (A0 == 1)
{
    return 1;
}

if (A0 == 2)
{
    [current_model_offset + 5D] = b(0);
    [current_model_offset + 6A] = b(0);

    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);
    return 0;
}

[current_model_offset + 5D] = b(1);
[current_model_offset + 6A] = h(0);
return 1;
////////////////////////////////



////////////////////////////////
// 0xB2 MSPED
current_entity        = bu[800722c4];
model_data_offset     = w[8009c544];
current_model         = bu[8007eb98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831fc + current_entity * 2;
game_data_offset      = w[8009c6e0];

if( current_model != ff )
{
    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;

    [current_model_offset + 70] = h(( V0 * h[game_data_offset + 10] ) >> 09);
}

// move pointer by 4
[script_pointer_offset] = h(hu[script_pointer_offset] + 4);
////////////////////////////////



////////////////////////////////
// 0xB3 DIR
A0 = bu[800722C4];
V1 = bu[8007EB98 + A0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_one_byte;
    V1 = bu[800722C4];
    V1 = bu[8007EB98 + V1];
    A2 = [8009C544];
    [A2 + V1 * 84 + 38] = b(V0);

    V0 = bu[800722C4];
    V0 = bu[8007EB98 + V0];
    V1 = [8009C544];
    [V1 + V0 * 84 + 3B] = b(00);

    V0 = bu[800722C4];
    V0 = bu[8007EB98 + V0];
    V1 = [8009C544];
    [V1 + V0 * 84 + 3A] = b(00);

    V0 = 1;
}
else
{
    V0 = 0;
}

// move pointer by 3
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 3;
[800831FC + V1 * 2] = h(V0);

return V0;
////////////////////////////////



////////////////////////////////
// 0xB4 TURNGEN
field_file_offset    = w[8009C6DC];
current_entity       = bu[800722C4];
model_id             = bu[8007EB98 + current_entity];
offset_to_model_data = w[8009C544];
model_data           = offset_to_model_data + model_id * 84;
script_pointer       = hu[800831FC + current_entity * 2]

V1 = bu[8007EB98 + current_entity];
if (V1 != FF)
{
    A2 = bu[model_data + 3B];
    if (A2 == 3)
    {
        [model_data + 39] = b(0);
        [model_data + 3A] = b(0);
        [model_data + 3B] = b(0);
    }
    else
    {
        if (bu[model_data + 39] != bu[script_pointer + 4] ||
            bu[model_data + 3A] == 0 ||
            bu[model_data + 3B] != bu[script_pointer + 5])
        {
            V1 = bu[model_data + 38]
            [model_data + 3C] = h(V1);

            V1 = bu[script_pointer + 5];
            [model_data + 3B] = b(V1);

            V1 = bu[script_pointer + 4];
            [model_data + 39] = b(V1);

            A0 = 2;
            A1 = 2;
            read_memory_block_one_byte;
            [model_data + 3E] = h(V0);

            // rotate clockwise/anti-clockwise/closest
            V1 = bu[script_pointer + 3];

            if (V1 == 1)
            {
                if (h[model_data + 3E] >= bu[model_data + 38])
                {
                    V0 = h[model_data + 3E] - 100;
                    [model_data + 3E] = h(V0);
                }
            }
            else if (V1 == 2)
            {
                A1 = h[model_data + 3E];
                A3 = h[model_data + 3C];
                V0 = A1 - A3;

                if (V0 < 0)
                {
                    V0 = 0 NOR V1;
                    A0 = V0 + 1;
                }
                else
                {
                    A0 = V1;
                }

                if (A0 >= 81)
                {
                    if (A3 < A1)
                    {
                        V0 = A1 - 100;
                        [model_data + 3E] = h(V0);
                    }
                    else
                    {
                        V0 = A1 + 100;
                        [model_data + 3E] = h(V0);
                    }
                }
            }
            else if (V1 == 0)
            {
                if (h[model_data + 3E] >= bu[model_data + 38])
                {
                    V0 = h[model_data + 3E] + 100;
                    [model_data + 3E] = h(V0);
                }
            }
        }

        return 1;
    }
}

script_pointer = script_pointer + 6;
[800831FC + current_entity * 2] = hu(script_pointer);
return 0;
////////////////////////////////



////////////////////////////////
// 0xB5 TURN
field_file_offset    = w[8009C6DC];
current_entity       = bu[800722C4];
model_id             = bu[8007EB98 + current_entity];
offset_to_model_data = w[8009C544];
model_data           = offset_to_model_data + model_id * 84;
script_pointer       = hu[800831FC + current_entity * 2]

if (model_id != FF)
{
    V1 = bu[model_data + 3B];

    if (V1 == 3)
    {
        [model_data + 39] = b(0);
        [model_data + 3A] = b(0);
        [model_data + 3B] = b(0);
    }
    else
    {
        A0 = 2;
        A1 = 2;
        read_memory_block_two_bytes;
        A2 = V0;

        if (bu[model_data + 3A] == 0 ||
            A2 != h[model_data + 3E] ||
            bu[model_data + 3B] != bu[field_file_offset + script_pointer + 5] ||
            bu[model_data + 39] != bu[field_file_offset + script_pointer + 4])
        {
            V1 = bu[model_data + 38];
            [model_data + 3C] = h[V1];

            V1 = bu[field_file_offset + script_pointer + 5];
            [model_data + 3B] = b(V1);

            V1 = bu[field_file_offset + script_pointer + 4];
            [model_data + 39] = b(V1);

            [model_data + 3E] = h(A2);
        }

        return 1;
    }
}

// move pointer by 6
script_pointer = script_pointer + 6;
[800831FC + current_entity * 2] = h(script_pointer);
////////////////////////////////



////////////////////////////////
// 0xB6 DIRA
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A0 = bu[V0 + V1 + 1]; // entity id

set_direction_to_current_entity_by_entity_id

return V0;
////////////////////////////////



////////////////////////////////
// 0xB7 GETDIR
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
S0 = bu[V0 + V1 + 2]; // entity id

V1 = bu[8007EB98 + S0];

if (V1 != FF)
{
    V0 = w[8009C544];
    A2 = bu[V0 + V1 * 84 + 38];

    A0 = 2;
    A1 = 3;
    store_memory_block_one_byte;
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xB8 GETAXY
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
S0 = bu[V0 + V1 + 2]; // entity id

V1 = bu[8007EB98 + S0];

if (V1 != FF)
{
    V0 = V1 * 84;
    V1 = w[8009C544];
    V0 = V0 + V1;
    A2 = w[V0 + 0C];

    A0 = 1;
    A1 = 3;
    A2 = A2 << 4;
    A2 = A2 >> 10;
    store_memory_block_two_bytes;

    A0 = 2;
    A1 = 4;
    A2 = w[V0 + 10];
    A2 = A2 << 4;
    A2 = A2 >> 10;
    store_memory_block_two_bytes;
}

// move pointer by 5
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 5;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xB9 GETAI
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
S0 = bu[V0 + V1 + 2]; // entity id

V1 = bu[8007EB98 + S0];

if (V1 != FF)
{
    V0 = V1 * 84;
    V1 = w[8009C544];
    V0 = V0 + V1;
    A2 = h[V0 + 72];

    A0 = 2;
    A1 = 3;
    store_memory_block_two_bytes;
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xBF CC
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A0 = bu[V0 + V1 + 1]; // entity id

V1 = bu[8007EB98 + A0];

if (V1 != FF)
{
    V1 = w[8009C6E0];
    V0 = bu[8007EB98 + A0];
    [V1 + 2A] = V0;
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xC0 JUMP
A0 = current_entity    = bu[800722C4];
V1 = model_id          = bu[8007EB98 + current_entity];
model_data_offset = w[8009C544] + model_id * 84;

if (model_id == FF)
{
    // move pointer by B
    V0 = hu[800831FC + current_entity * 2];
    V0 = V0 + F;
    [800831FC + V1 * 2] = h(V0);
    return 0;
}

V1 = bu[model_data_offset + 5D];

if (V1 == 3)
{
    V1 = h[model_data_offset + 6A];
    if (V1 == 1)
    {
        return 1;
    }

    if (V1 == 2)
    {
        [model_data_offset + 5D] = b(0);
        [model_data_offset + 6A] = h(0);

        // move pointer by B
        V0 = hu[800831FC + current_entity * 2];
        V0 = V0 + F;
        [800831FC + V1 * 2] = h(V0);
        return 0;
    }
}

[model_data_offset + 5D] = b(3);
[model_data_offset + 6A] = h(0);

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 78] = w(V0);

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 7С] = w(V0);

A0 = 3;
A1 = 7;
read_memory_block_two_bytes;
[model_data_offset + 74] = h(V0);

A0 = 4
A1 = 9;
read_memory_block_two_bytes;
[model_data_offset + 30] = h(V0);

return 1;
////////////////////////////////



////////////////////////////////
// 0xC1 AXYZI
800CA5D4	lui    v0, $8007
800CA5D8	lbu    v0, $22c4(v0)
800CA5DC	lui    v1, $800a
800CA5E0	lbu    v1, $d820(v1)
800CA5E4	addiu  sp, sp, $ffd8 (=-$28)
800CA5E8	sw     s1, $001c(sp)
800CA5EC	lui    s1, $8008
800CA5F0	addiu  s1, s1, $31fc
800CA5F4	sw     ra, $0020(sp)
800CA5F8	sw     s0, $0018(sp)
800CA5FC	sll    v0, v0, $01
800CA600	lui    at, $8008
800CA604	addiu  at, at, $31fc
800CA608	addu   at, at, v0
800CA60C	lhu    a0, $0000(at)
800CA610	lui    v0, $800a
800CA614	lw     v0, $c6dc(v0)
800CA618	andi   v1, v1, $0003
800CA61C	addu   v0, v0, a0
800CA620	lbu    s0, $0003(v0)
800CA624	beq    v1, zero, Lca63c [$800ca63c]
800CA628	andi   s0, s0, $00ff
800CA62C	lui    a0, $800a
800CA630	addiu  a0, a0, $0a78
800CA634	jal    funcbead4 [$800bead4]
800CA638	ori    a1, zero, $0007

Lca63c:	; 800CA63C
800CA63C	lui    at, $8008
800CA640	addiu  at, at, $eb98 (=-$1468)
800CA644	addu   at, at, s0
800CA648	lbu    v1, $0000(at)
800CA64C	ori    v0, zero, $00ff
800CA650	beq    v1, v0, Lca73c [$800ca73c]
800CA654	ori    a0, zero, $0001
800CA658	sll    v0, v1, $05
800CA65C	addu   v0, v0, v1
800CA660	lui    v1, $800a
800CA664	lw     v1, $c544(v1)
800CA668	sll    v0, v0, $02
800CA66C	addu   v0, v0, v1
800CA670	lw     a2, $000c(v0)
800CA674	ori    a1, zero, $0004
800CA678	sll    a2, a2, $04
800CA67C	jal    store_memory_block_two_bytes [$800c0248]
800CA680	sra    a2, a2, $10
800CA684	lui    at, $8008
800CA688	addiu  at, at, $eb98 (=-$1468)
800CA68C	addu   at, at, s0
800CA690	lbu    v1, $0000(at)
800CA694	ori    a0, zero, $0002
800CA698	sll    v0, v1, $05
800CA69C	addu   v0, v0, v1
800CA6A0	lui    v1, $800a
800CA6A4	lw     v1, $c544(v1)
800CA6A8	sll    v0, v0, $02
800CA6AC	addu   v0, v0, v1
800CA6B0	lw     a2, $0010(v0)
800CA6B4	ori    a1, zero, $0005
800CA6B8	sll    a2, a2, $04
800CA6BC	jal    store_memory_block_two_bytes [$800c0248]
800CA6C0	sra    a2, a2, $10
800CA6C4	lui    at, $8008
800CA6C8	addiu  at, at, $eb98 (=-$1468)
800CA6CC	addu   at, at, s0
800CA6D0	lbu    v1, $0000(at)
800CA6D4	ori    a0, zero, $0003
800CA6D8	sll    v0, v1, $05
800CA6DC	addu   v0, v0, v1
800CA6E0	lui    v1, $800a
800CA6E4	lw     v1, $c544(v1)
800CA6E8	sll    v0, v0, $02
800CA6EC	addu   v0, v0, v1
800CA6F0	lw     a2, $0014(v0)
800CA6F4	ori    a1, zero, $0006
800CA6F8	sll    a2, a2, $04
800CA6FC	jal    store_memory_block_two_bytes [$800c0248]
800CA700	sra    a2, a2, $10
800CA704	lui    at, $8008
800CA708	addiu  at, at, $eb98 (=-$1468)
800CA70C	addu   at, at, s0
800CA710	lbu    v1, $0000(at)
800CA714	ori    a0, zero, $0004
800CA718	sll    v0, v1, $05
800CA71C	addu   v0, v0, v1
800CA720	lui    v1, $800a
800CA724	lw     v1, $c544(v1)
800CA728	sll    v0, v0, $02
800CA72C	addu   v0, v0, v1
800CA730	lh     a2, $0072(v0)
800CA734	jal    store_memory_block_two_bytes [$800c0248]
800CA738	ori    a1, zero, $0007

Lca73c:	; 800CA73C
800CA73C	lui    v1, $8007
800CA740	lbu    v1, $22c4(v1)
800CA744	nop
800CA748	sll    v1, v1, $01
800CA74C	addu   v1, v1, s1
800CA750	lhu    v0, $0000(v1)
800CA754	nop
800CA758	addiu  v0, v0, $0008
800CA75C	sh     v0, $0000(v1)
800CA760	addu   v0, zero, zero
800CA764	lw     ra, $0020(sp)
800CA768	lw     s1, $001c(sp)
800CA76C	lw     s0, $0018(sp)
800CA770	addiu  sp, sp, $0028
800CA774	jr     ra 
800CA778	nop
////////////////////////////////



////////////////////////////////
// 0xC2 LADER
current_entity    = bu[800722C4];
model_id          = bu[8007EB98 + current_entity];
model_data_offset = w[8009C544] + model_id * 84;

if (model_id == FF)
{
    // move pointer by 15
    V0 = hu[800831FC + current_entity * 2];
    V0 = V0 + F;
    [800831FC + V1 * 2] = h(V0);
    return 0;
}

V1 = bu[model_data_offset + 5D];

if (V1 == 4 || V1 == 5)
{
    V1 = h[model_data_offset + 6A];
    if (V1 == 1)
    {
        return 1;
    }
    else if (V1 == 2)
    {
        [model_data_offset + 5D] = b(0);
        [model_data_offset + 6A] = h(0);

        // move pointer by 15
        V0 = hu[800831FC + current_entity * 2];
        V0 = V0 + F;
        [800831FC + current_entity * 2] = h(V0);
        return 0;
    }
}



// init
V1 = hu[800831FC + current_entity * 2];
V0 = w[8009C6DC];
V0 = V0 + V1;
V1 = bu[V0 + B];

if (V1 == 0 || V1 == 1)
{
    [model_data_offset + 5D] = bu(4);
}
else if (V1 == 2 || V1 == 3)
{
    [model_data_offset + 5D] = bu(5);
}

if (V1 == 0 || V1 == 2)
{
    [model_data_offset + 68] = h(0);
}
else if (V1 == 1 || V1 == 3)
{
    [model_data_offset + 68] = h(1);
}

[model_data_offset + 6A] = h(0);

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 78] = w(V0);

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 7C] = w(V0);

A0 = 3;
A1 = 7;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 80] = w(V0);

A0 = 4;
A1 = 9;
read_memory_block_two_bytes;
[model_data_offset + 74] = h(V0);



// animation id
V1 = hu[800831FC + current_entity * 2];
V0 = w[8009C6DC];
V1 = bu[V0 + V1 + c];
[model_data_offset + 5E] = b(V1);



// speed of movement
A1 = hu[800831FC + current_entity * 2];
V0 = w[8009C6DC];
V1 = h[8009d828 + model_id * 2] / bu[V0 + A1 + e];
[model_data_offset + 60] = h(V1);



[model_data_offset + 62] = h(0);



// animation related
V1 = w[8008357C];
V1 = bu[V1 + model_id * 8 + 4];
animation_id = bu[80074EA4 + model_id * 84 + 5E];
A0 = w[8004A62C];
V0 = w[A0 + 4];
A1 = w[V0 + V1 * 24 + 1C];
A0 = hu[V0 + V1 * 24 + 1A];
V0 = hu[A1 + A0 + animation_id * 10];
V0 = V0 - 1;
[model_data_offset + 64] = h(V0);



// animation state array
[800756E8 + model_id] = b(0);



// set direction for model
A1 = hu[800831FC + current_entity * 2];
A0 = w[8009C6DC];
A0 = bu[A0 + A1 + D];
// set direction
[model_data_offset + 38] = b(A0);
return 1;
////////////////////////////////



////////////////////////////////
// 0xC3 OFST
entity_id = bu[800722c4];
model_id = bu[8007eb98 + entity_id];
if (model_id != ff)
{
    model_data = w[8009c544];

    [model_data + model_id * 84 + 54] = h(0);

    A0 = 4;
    A1 = a;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 52] = h(V0);

    A0 = 1;
    A1 = 4;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 44] = h(V0);

    A0 = 2;
    A1 = 6;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 4a] = h(V0);

    A0 = 3;
    A1 = 8;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 50] = h(V0);

    A1 = entity_id * 2;
    A0 = hu[800831fc + entity_id * 2];
    V0 = w[8009c6dc];
    V1 = bu[V0 + A0 + 3]; // read type
    [model_data + model_id * 84 + 56] = b(V1);

    if (V1 != 0)
    {
        [model_data + model_id * 84 + 42] = h[hu[model_data + model_id * 84 + 40]];
        [model_data + model_id * 84 + 48] = h[hu[model_data + model_id * 84 + 46]];
        [model_data + model_id * 84 + 4e] = h[hu[model_data + model_id * 84 + 4c]];
    }
    else
    {
        [model_data + model_id * 84 + 40] = h[hu[model_data + model_id * 84 + 44]];
        [model_data + model_id * 84 + 46] = h[hu[model_data + model_id * 84 + 4a]];
        [model_data + model_id * 84 + 4c] = h[hu[model_data + model_id * 84 + 50]];
    }
}

V0 = hu[800831FC + entity_id * 2];
V0 = V0 + c;
[800831FC + entity_id * 2] = h(V0);
return 0;
////////////////////////////////



////////////////////////////////
// 0xC4 OFSTW
entity_id = bu[800722c4];
model_id = bu[8007eb98 + entity_id];
model_data = w[8009c544];

if (model_id != ff)
{
    V1 = bu[model_data + model_id * 84 + 56];

    if (V1 != 3)
    {
        return 1;
    }

    [model_data + model_id * 84 + 52] = h(0);
    [model_data + model_id * 84 + 54] = h(0);
    [model_data + model_id * 84 + 56] = b(0);
}

V0 = hu[800831FC + entity_id * 2];
V0 = V0 + 1;
[800831FC + entity_id * 2] = h(V0);
return 0;
////////////////////////////////



////////////////////////////////
// 0xC5 TALKR
V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_one_byte;

    V1 = w[8009C6E0];
    V1 = h[V1 + 10];
    V0 = V0 & FF;
    HI/LO = V0 * V1;
    A0 = LO;

    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = V1 * 84;
    V1 = w[8009C544];
    V1 = V0 + V1;

    if (A0 < 0)
    {
        A0 = A0 + 01FF;
    }

    V0 = A0 >> 09;
    [V1 + 6E] = h(V0);
}

// move pointer by 3
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 3;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xC6 SLIDR
current_entity        = bu[800722c4];
model_data_offset     = w[8009c544];
current_model         = bu[8007eb98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831fc + current_entity * 2;


V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if( current_model != ff )
{
    A0 = 2;
    A1 = 2;
    read_memory_block_one_byte;

    V1 = w[8009c6e0];
    AO = V0 * h[V1 + 10]; // multiply by field_scale

    if( A0 < 0 )
    {
        A0 = A0 + 01ff;
    }

    [current_model_offset + 6c] = h(A0 >> 09);
}

[script_pointer_offset] = h(hu[script_pointer_offset] + 3);
////////////////////////////////



////////////////////////////////
// 0xC7 SOLID
V1 = bu[800722C4];
model_id = bu[8007EB98 + V1];

if (A0 != FF)
{
    A0 = hu[800831FC + V1 * 2];
    V1 = w[8009C6DC];
    V1 = bu[V1 + A0 + 1];
    A0 = w[8009C544];
    [A0 + model_id * 84 + 59] = b(V1);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xD6 TLKR2
V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;

    V1 = w[8009C6E0];
    V1 = h[V1 + 10];
    HI/LO = V0 * V1;
    A0 = LO;

    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = V1 * 84;
    V1 = w[8009C544];
    V1 = V0 + V1;
    V0 = A0 >> 09;
    [V1 + 6E] = h(V0);
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xD7 SLDR2
V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;

    V1 = w[8009C6E0];
    V1 = h[V1 + 10];
    HI/LO = V0 * V1;
    A0 = LO;

    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = V1 * 84;
    V1 = w[8009C544];
    V1 = V0 + V1;

    V0 = A0 >> 09;
    [V1 + 6C] = h(V0);
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xDB FCFIX
V1 = entity_id = bu[800722C4];
A0 = bu[8007EB98 + entity_id];
if (A0 != FF)
{
    V0 = A0 * 84;
    A0 = hu[800831FC + entity_id * 2];

    V1 = V1 + A0;
    V1 = bu[V1 + 1];

    A0 = w[8009C544];
    V0 = V0 + A0;
    [V0 + 37] = b(V1);
}

V1 = hu[800831FC + entity_id * 2];
V1 = V1 + 2;
[800831FC + A0 * 2] = hu[V1];

return 0;
////////////////////////////////



////////////////////////////////
// 0xDE TURNW
entity_id = bu[800722C4];
model_id = bu[8007EB98 + entity_id];
if (model_id != FF)
{
    V0 = w[8009C544];
    V1 = V0 + model_id * 84;
    A1 = bu[V1 + 3B];
    if (A1 != 0)
    {
        if (A1 != 3)
        {
            return 1;
        }

        [V1 + 3B] = b(0);
        [V1 + 3A] = b(0)
        [V1 + 39] = b(0)
    }
}

V1 = hu[800831FC + entity_id * 2];
V1 = V1 + 1;
[800831FC + A0 * 2] = hu[V1]
return 0;
////////////////////////////////



////////////////////////////////
// funcc8634
rotate_entity = A0;
current_entity         = bu[800722C4];
current_model          = bu[8007EB98 + current_entity];
rotate_model          = bu[8007EB98 + rotate_entity];
current_script_pointer = hu[800831FC + current_entity * 2];
field_file_offset      = w[8009C6DC];
models_offset          = w[8009C544];

//[models_offset + current_model * 84 + 60] = h(V1);

if (current_model == FF || rotate_entity == FF)
{
    // move pointer by 4
    current_script_pointer = current_script_pointer + 4;
    [800831FC + current_entity * 2] = h(current_script_pointer);
    return 0;
}

V1 = bu[models_offset + current_model * 84 + 3B];
if (V1 == 3)
{
    [models_offset + current_model * 84 + 3B] = b(0)
    [models_offset + current_model * 84 + 3A] = b(0)
    [models_offset + current_model * 84 + 39] = b(0)
    // move pointer by 4
    current_script_pointer = current_script_pointer + 4;
    [800831FC + current_entity * 2] = h(current_script_pointer);
    return 0;
}

if (bu[models_offset + current_model * 84 + 3A] != 0 &&
    bu[models_offset + current_model * 84 + 3B] == 2 &&
    bu[models_offset + current_model * 84 + 39] == bu[field_file_offset + current_script_pointer + 2])
{
    V1 = bu[models_offset + current_model * 84 + 38];
    [models_offset + current_model * 84 + 3C] = h(V1);
    [models_offset + current_model * 84 + 3B] = h(2);

    V1 = bu[field_file_offset + current_script_pointer + 2]
    [models_offset + current_model * 84 + 39] = b(V1);

    V0 = w[models_offset + current_model * 84 + C];
    T0 = V0 >> C;
    [SP + 10] = w(T0);
    V0 = w[models_offset + current_model * 84 + 10];
    T1 = V0 >> C;
    [SP + 14] = w(T1);
    V0 = w[models_offset + current_model * 84 + 14];
    V0 = V0 >> C;
    [SP + 18] = w(V0);

    V0 = w[models_offset + rotate_model * 84 + C];
    A1 = V0 >> C;
    [SP + 20] = w(A1);
    V0 = w[models_offset + rotate_model * 84 + 10];
    A3 = V0 >> C;
    [SP + 24] = w(A3);
    V0 = w[models_offset + rotate_model * 84 + 14];
    V0 = V0 >> C;
    [SP + 28] = w(V0);

    if (T0 == A1 && T1 == A3)
    {
        V0 = T0 + 1;
        [SP + 10] = w(V0);
    }

    A0 = SP + 10;
    A1 = SP + 20;
    A2 = SP + 30;
    calculate_direction_by_vectors;

    [models_offset + current_model * 84 + 3E] = h(V0);

    V1 = bu[field_file_offset + current_script_pointer + 3]

    if (V1 == 0)
    {
        V0 = h[models_offset + current_model * 84 + 3E];
        V1 = bu[models_offset + current_model * 84 + 38];
        if (V0 < V1)
        {
            V0 = V0 + 100;
            [models_offset + current_model * 84 + 3E] = h(V0);
        }
    }
    else if (V1 == 1)
    {
        V1 = h[models_offset + current_model * 84 + 3E];
        V0 = bu[models_offset + current_model * 84 + 38];
        if (V0 < V1)
        {
            V0 = V1 - 100;
            [models_offset + current_model * 84 + 3E] = h(V0);
        }
    }
    if (V1 == 2)
    {
        A1 = hu[models_offset + current_model * 84 + 3E];
        A3 = hu[models_offset + current_model * 84 + 3C];
        V0 = A1 - A3;

        if (V0 < 0)
        {
            V0 = 0 NOR V1;
            A0 = V0 + 1;
        }
        else
        {
            A0 = V1;
        }

        if (A0 >= 81)
        {
            V1 = A1;
            V0 = A3;
            if (V0 < V1)
            {
                V0 = A1 - 100;
                [models_offset + current_model * 84 + 3E] = h(V0);
            }
            else
            {
                V0 = A1 + 100;
                [models_offset + current_model * 84 + 3E] = h(V0);
            }
        }
    }
}

return 1;
////////////////////////////////



////////////////////////////////
// set_direction_to_current_entity_by_entity_id
A0 - entity to get

// if current entity not visible entity
A2 = bu[800722C4];
V1 = bu[8007EB98 + A2];
if (V1 == FF)
{
    V1 = hu[800831FC + A2 * 2];
    V1 = V1 + 2;
    [800831FC + A2 * 2] = h(V1);

    return 0;
}

// if entity to which we want set direction not visible entity
A3 = A0;
V0 = bu[8007EB98 + A3];
if (V0 == FF)
{
    V1 = hu[800831FC + A2 * 2];
    V1 = V1 + 2;
    [800831FC + A2 * 2] = h(V1);

    return 0;
}

A1 = w[8009C544];

V1 = bu[8007EB98 + A2];
V0 = w[A1 + V1 * 84 + 0C];
T0 = V0 >> 0C;
[SP + 10] = w(T0);

V1 = bu[8007EB98 + A2];
V0 = w[A1 + V1 * 84 + 10];
T1 = V0 >> 0C;
[SP + 14] = w(T1);

V1 = bu[8007EB98 + A2];
V0 = w[A1 + V1 * 84 + 14];
V0 = V0 >> 0C;
[SP + 18] = w(V0);



V1 = bu[8007EB98 + A3];
V0 = V1 * 84;
A0 = w[A1 + V0 + 0C];
A0 = A0 >> 0C;
[SP + 20] = w(A0);

V1 = bu[8007EB98 + A3];
V0 = V1 * 84;
V0 = w[A1 + V0 + 10];
A2 = V0 >> 0C;
[SP + 24] = w(A2);

V1 = bu[8007EB98 + A3];
V0 = V1 * 84;
V0 = w[A1 + V0 + 14];
V0 = V0 >> 0C;
[SP + 28] = w(V0);

if (T0 == A0 && T1 == A2) // if X1 == X2 && Y1 = Y2
{
    V0 = T0 + 1;
    [SP + 10] = V0;
}

A0 = SP + 10;
A1 = SP + 20;
A2 = SP + 30;

calculate_direction_by_vectors;

V1 = bu[800722C4];
A0 = bu[8007EB98 + V1];
V1 = A0 * 84;
A0 = w[8009C544];
[V1 + A0 + 38] = b(V0);

V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];
V0 = V1 * 84;
V1 = w[8009C544];
[V1 + A0 + 3B] = b(0);

V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];
V0 = V1 * 84;
V1 = w[8009C544];
[V1 + A0 + 3A] = b(0);

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 1;
////////////////////////////////



////////////////////////////////
calculate_direction_by_vectors
A0 - address of rotated entity pos
A1 - address of entity pos to which we want rotate to
A2 - output address

V1 = w[A1 + 00];
V0 = w[A0 + 00];
S2 = V1 - V0;
HI/LO = S2 * S2;
A0 = LO;

V1 = w[A1 + 04];
V0 = w[A0 + 04];
S1 = V1 - V0;
HI/LO = S1 * S1;
V0 = LO;

S0 = A2;
A0 = A0 + V0;
[S0 + 00] = w(A0);

system_square_root;

A0 = V0;
V0 = S2 << 0C;
HI/LO = V0 / A0;
V1 = LO;
[S0 + 00] = w(A0);

if (V1 < 0)
{
    V1 = V1 + 1F;
}

V0 = S1 << 0C;
HI/LO = V0 / A0;
A0 = LO;

if (A0 < 0)
{
    A0 = A0 + 1F;
}

S2 = V1 >> 5;
HI/LO = S2 * S2;
V1 = LO;

S1 = A0 >> 5;
HI/LO = S1 * S1;
V0 = LO;

if (V0 < V1)
{
    if (S2 > 0)
    {
        if (S1 > 0)
        {
            V0 = bu[800DEF88 + S1 * 2];
            V0 = V0 + 40;
        }
        else
        {
            V0 = bu[800DEF88 - S1 * 2];
            V0 = 40 - V0;
        }
    }
    else
    {
        if (S1 > 0)
        {
            V1 = bu[800DEF88 + S1 * 2];
            V0 = - 40 - V1;
        }
        else
        {
            V0 = bu[800DEF88 - S1 * 2];
            V0 = V0 - 40;
        }
    }
}
else
{
    if (S1 > 0)
    {
        if (S2 > 0)
        {
            V1 = bu[800DEF88 + S1 * 2];
            V0 = 80 - V1;
        }
        else
        {
            V0 = bu[800DEF88 - S1 * 2];
            V0 = V0 + 80;
        }
    }
    else
    {
        if (S2 > 0)
        {
            V0 = bu[800DEF88 + S1 * 2];
        }
        else
        {
            V1 = bu[800DEF88 - S1 * 2];
            V0 = - V1;
        }
    }
}

return V0;
////////////////////////////////



////////////////////////////////
// funcd0938
speed = [SP + 40];
entity_id = A0;
end_x = A1;
end_y = A2;
direction = A3;
if (entity_id == FF)
{
    return 1;
}

V1 = bu[80081D90 + entity_id];
if (V1 == 0)
{
    A0 = entity_id;
    A1 = end_x;
    A2 = end_y;
    [SP + 10] = w(1);
    A3 = speed;
    funcd0b4c;

    [80081D90 + entity_id] = b(1);
    return 0;
}
else if (V1 == 1)
{
    A0 = entity_id;
    funcd1200;

    if (V0 == 0)
    {
        return 0;
    }

    model_id = bu[8007EB98 + entity_id];
    V0 = w[8009C544];
    [V0 + model_id * 84 + 59] = b(0);
    [V0 + model_id * 84 + 5B] = b(0);

    A0 = entity_id;
    A1 = bu[V0 + model_id * 84 + 38]; // direction
    A2 = direction;
    funcd1350;

    [80081D90 + entity_id] = b(2);
    return 0;
}
else if (V1 == 2)
{
    A0 = entity_id;
    funcd152c;

    if (V0 != 0)
    {
        [80081D90 + entity_id] = b(3);
        return 1;
    }

    return 0;
}
else if (V1 == 3)
{
    return 1;
}
else
{
    return 0;
}
////////////////////////////////



////////////////////////////////
// funcc7d5c
A1 = bu[800722C4];
V0 = bu[8007EB98 + A1];
A3 = A0;
A0 = bu[8007EB98 + A3];

if (V0 == FF || A0 == FF)
{
    V1 = hu[800831FC + A1 * 2];
    V1 = V1 + 2;
    [800831FC + A1 * 2] = h(V1);
    return 0;
}

V1 = V0 * 84;
V0 = A0 * 84;
A0 = w[8009C544];
V0 = V0 + A0;
V0 = hu[V0 + 6C]; // solid
[V1 + 68] = h(V0);
V1 = V1 + A0;
V1 = bu[8007EB98 + A1];
V0 = V1 * 84;
V0 = V0 + A0;
[V0 + 37] = b(0);

A2 = bu[800722c4];
A1 = w[8009c544];

A0 = bu[8007eb98 + A3];
V0 = bu[8007eb98 + A2];
[A1 + V0 * 84 + 78] = w(w[A1 + A0 * 84 + c]);
[A1 + V0 * 84 + 7c] = w(w[A1 + A0 * 84 + 10]);

V1 = bu[A1 + V0 * 84 + 5d];
if (V1 == 1)
{
    A2 = [A1 + V0 * 84 + 6a];
    if (A2 == 1)
    {
        V0 = w[8009c6e0];
        V1 = h[V0 + 10];
        A0 = hu[A1 + 70];
        V0 = V1 * 3;
        V0 = V0 < A0;

        800C7F18	beq    v0, zero, Lc7f38 [$800c7f38]
        800C7F1C	ori    v0, zero, $0002
        800C7F20	lbu    v1, $005e(a1)
        800C7F24	nop
        800C7F28	beq    v1, v0, Lc8030 [$800c8030]
        800C7F2C	ori    v0, zero, $0002
        800C7F30	j      Lc7f4c [$800c7f4c]
        800C7F34	sb     v0, $005e(a1)
    }
    else if (A2 == 2)
    {
        [A1 + V0 * 84 + 5d] = b(0);
        V0 = bu[800722c4];
        V0 = bu[8007eb98 + V0];
        [800756e8 + V0] = b(0);

        A0 = bu[800722c4];
        [800831fc + A0 * 2] = h(hu[800831fc + A0 * 2] + 2);
        return 0;
    }

    800C7EF0	j      Lc80c8 [$800c80c8]

    Lc7f38:	; 800C7F38
    800C7F38	lbu    v0, $005e(a1)
    800C7F3C	nop
    if (V0 != A2)
    {
        800C7F40	beq    v0, a2, Lc8030 [$800c8030]
        800C7F44	ori    v0, zero, $0001
        800C7F48	sb     v0, $005e(a1)

        Lc7f4c:	; 800C7F4C
        A0 = bu[800722c4];
        V1 = bu[8007eb98 + A0];
        A2 = w[8009c544];
        V0 = A2 + V1 * 84;
        [V0 + 60] = h(10);
        [V0 + 62] = h(0);

        A0 = V1;

        V1 = w[8008357c];
        V0 = V1 + A0 * 8;
        A1 = bu[V0 + 4];


        800C7FD4	lui    v1, $8005
        800C7FD8	lw     v1, $a62c(v1)
        800C7FDC	sll    v0, a1, $03
        800C7FE0	addu   v0, v0, a1
        800C7FE4	lw     v1, $0004(v1)
        800C7FE8	sll    v0, v0, $02
        800C7FEC	addu   v0, v0, v1
        800C7FF0	sll    v1, a0, $05
        800C7FF4	addu   v1, v1, a0
        800C7FF8	sll    v1, v1, $02
        800C7FFC	lhu    a1, $001a(v0)
        800C8000	lw     a0, $001c(v0)
        800C8004	lui    at, $8007
        800C8008	addiu  at, at, $4f02
        800C800C	addu   at, at, v1
        800C8010	lbu    v0, $0000(at)
        800C8014	addu   a1, a1, a0
        800C8018	sll    v0, v0, $04
        800C801C	addu   v0, v0, a1
        800C8020	lhu    v0, $0000(v0)
        800C8024	addu   v1, v1, a2
        800C8028	addiu  v0, v0, $ffff (=-$1)
        800C802C	sh     v0, $0064(v1)
    }

    Lc8030:	; 800C8030
    V1 = bu[800722c4];
    A0 = bu[8007eb98 + V1];
    [800756e8 + A0] = b(1);
    return 1;
}

Lc80c8:	; 800C80C8
V0 = bu[800722c4];
V1 = bu[8007eb98 + V0];
V0 = w[8009c544];
V0 = V0 + V1 * 84;
[V0 + 5d] = b(1);
[V0 + 6a] = b(0);
return 1;
////////////////////////////////
