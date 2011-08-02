////////////////////////////////
801D0198-801D01EC

801D01A0	lui    a0, $801d
801D01A4	addiu  a0, a0, $41cc
801D01A8	jal    $80025b8c
801D01AC	nop
801D01B0	jal    $80043dd8
801D01B4	addu   a0, zero, zero
801D01B8	lui    a0, $801d
801D01BC	addiu  a0, a0, $19cc
801D01C0	jal    $80025c14
801D01C4	nop
801D01C8	jal    $80043dd8
801D01CC	addu   a0, zero, zero
801D01D0	jal    $80025df8
801D01D4	nop
801D01D8	jal    $80043dd8
801D01DC	addu   a0, zero, zero
////////////////////////////////



////////////////////////////////
// func1d01f0
801D01F0-801D024C
801D01F8	lui    a0, $8007
801D01FC	addiu  a0, a0, $56f8
801D0200	jal    $80025c94
801D0204	nop
801D0208	jal    $80043dd8
801D020C	addu   a0, zero, zero
801D0210	lui    a0, $801d
801D0214	addiu  a0, a0, $41cc
801D0218	jal    $80025bd0
801D021C	nop
801D0220	jal    $80043dd8
801D0224	addu   a0, zero, zero
801D0228	lui    a0, $801d
801D022C	addiu  a0, a0, $19cc
801D0230	jal    $80025c54
801D0234	nop
801D0238	jal    $80043dd8
801D023C	addu   a0, zero, zero
////////////////////////////////



////////////////////////////////
// 801D0250-801D0658

A0 = w[80062f58];

S4 = 30;
S2 = 20;
S0 = 8009cbdc;
S1 = 38;
S3= 24;

801D0288	jal    $800230c4

A0 = 10;
A1 = w[801d0694] * 38 + 34;
func1eb2c; // cursor


loop1d02b0:	; 801D02B0
    V1 = b[S0]; // character id
    if (V1 != -1 && V1 < 9)
    {
        A0 = a0;
        A1 = S1;
        A2 = 8009c6e4 + 54 + V1 * 84 + 10;
        A3 = 7;
        func26f44;
    }
    else
    {
        L1d02fc:	; 801D02FC
        801D02FC	ori    a0, zero, $00a0
        801D0300	addu   a1, s1, zero
        801D0304	ori    a3, zero, $0005
        801D0308	lbu    a2, $0000(s0)
        801D030C	ori    v0, zero, $0007
        801D0310	jal    $80028e00
        801D0314	sw     v0, $0010(sp)
    }

    801D0318	lb     v1, $0000(s0)
    801D031C	addiu  v0, zero, $ffff (=-$1)
    801D0320	beq    v1, v0, L1d03e0 [$801d03e0]
    801D0324	addu   a0, v1, zero
    801D0328	andi   a0, a0, $00ff
    801D032C	sltiu  v0, a0, $0009
    801D0330	beq    v0, zero, L1d03e0 [$801d03e0]
    801D0334	sll    v0, a0, $05
    801D0338	addu   v0, v0, a0
    801D033C	sll    v0, v0, $02
    801D0340	lui    at, $800a
    801D0344	addiu  at, at, $c758 (=-$38a8)
    801D0348	addu   at, at, v0
    801D034C	lbu    v1, $0000(at)
    801D0350	nop
    801D0354	xori   v1, v1, $0001
    801D0358	andi   v1, v1, $0001
    801D035C	sll    v0, v1, $01
    801D0360	addu   v0, v0, v1
    801D0364	sll    v0, v0, $03
    801D0368	addiu  v1, v0, $0050
    801D036C	sltiu  v0, a0, $0005
    801D0370	bne    v0, zero, L1d0380 [$801d0380]
    801D0374	addu   a1, s3, zero
    801D0378	j      L1d0384 [$801d0384]
    801D037C	sw     s4, $0010(sp)

    L1d0380:	; 801D0380
    801D0380	sw     zero, $0010(sp)

    L1d0384:	; 801D0384
    801D0384	lbu    a3, $0000(s0)
    801D0388	lui    v0, $cccc
    801D038C	ori    v0, v0, $cccd
    801D0390	multu  a3, v0
    801D0394	addu   a0, v1, zero
    801D0398	ori    a2, zero, $0030
    801D039C	sw     s4, $0018(sp)
    801D03A0	sw     s4, $001c(sp)
    801D03A4	mfhi   t0
    801D03A8	srl    v1, t0, $02
    801D03AC	sll    v0, v1, $02
    801D03B0	addu   v0, v0, v1
    801D03B4	subu   a3, a3, v0
    801D03B8	andi   a3, a3, $00ff
    801D03BC	sll    v0, a3, $01
    801D03C0	addu   v0, v0, a3
    801D03C4	sll    v0, v0, $04
    801D03C8	sw     v0, $0014(sp)
    801D03CC	lbu    v0, $0000(s0)
    801D03D0	ori    a3, zero, $0030
    801D03D4	sw     zero, $0024(sp)
    801D03D8	jal    $8001d180
    801D03DC	sw     v0, $0020(sp)

    L1d03e0:	; 801D03E0
    801D03E0	addu   a0, zero, zero
    801D03E4	ori    a1, zero, $0001
    801D03E8	ori    a2, zero, $007f
    801D03EC	addiu  a3, sp, $0030
    801D03F0	ori    v0, zero, $0100
    801D03F4	sh     zero, $0030(sp)
    801D03F8	sh     zero, $0032(sp)
    801D03FC	sh     v0, $0034(sp)
    801D0400	jal    $80026a34
    801D0404	sh     v0, $0036(sp)
    801D0408	addiu  a0, sp, $0028
    801D040C	addu   a1, zero, zero
    801D0410	addu   a2, s2, zero
    801D0414	ori    a3, zero, $016c
    801D0418	ori    v0, zero, $0038
    801D041C	jal    $8001de0c
    801D0420	sw     v0, $0010(sp)
    801D0424	jal    $8001e040
    801D0428	addiu  a0, sp, $0028
    801D042C	addiu  s2, s2, $0038
    801D0430	addiu  s0, s0, $0001
    801D0434	addiu  s3, s3, $0038
    S1 = S1 + 38;
    V0 = S2 < c8;
801D043C	bne    v0, zero, loop1d02b0 [$801d02b0]

if (hu[80062d7e] & 4000) // pressed down?
{
    [801d0694] = w((w[801d0694] + 1) % 3);
}

if (hu[80062d7e] & 1000) // pressed up?
{
    [801d0694] = w(w[801d0694] - 1);
    if (V0 < 0)
    {
        [801d0694] = w(2);
    }
}

if (hu[80062d7e] & 2000) // pressed right?
{
    V1 = w[801d0694];
    [8009cbdc + V1] = b(bu[8009cbdc + V1] + 1);

    if (b[8009cbdc + V1] == b)
    {
        [8009cbdc + V1] = b(ff);
    }

    801D051C	bne    v1, v0, L1d0528 [$801d0528]
    801D0520	ori    v0, zero, $00ff
    801D0524	sb     v0, $0000(a0)
}

if (hu[80062d7e] & 8000) // pressed left?
{
    V1 = w[801d0694];
    [8009cbdc + V1] = b(bu[8009cbdc + V1] - 1);

    if (b[8009cbdc + V1] == -2)
    {
        [8009cbdc + V1] = b(a);
    }
}

if (hu[80062d7e] & 0020) // pressed circle?
{
    V0 = w[801d0694];
    V0 = bu[8009cbdc + V0]; // character id
    [8009c6e4 + 54 + V0 * 84 + 20] = b(bu[8009c6e4 + 54 + V0 * 84 + 20] ^ 1);
}

if (hu[80062d7e] & 0040) // pressed cross?
{
    A0 = 5;
    A1 = 0;
    801D060C	jal    $8002305c

    A0 = 0;
    801D0614	jal    $8002120c

    801D061C	jal    $800260dc

    [80062f90] = w(1);

    func1d01f0;
}
////////////////////////////////