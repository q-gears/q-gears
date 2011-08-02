
Entry:	; 801D0000
801D0000	addiu  sp, sp, $ffb0 (=-$50)
801D0004	sw     s2, $0048(sp)
801D0008	lui    s2, $801d
801D000C	addiu  s2, s2, $01e0
801D0010	addu   a0, s2, zero
801D0014	addu   a1, zero, zero
801D0018	addu   a2, zero, zero
801D001C	ori    a3, zero, $0001
801D0020	sw     s1, $0044(sp)
801D0024	ori    s1, zero, $0003
801D0028	sw     s0, $0040(sp)
801D002C	ori    s0, zero, $0001
801D0030	sw     ra, $004c(sp)
801D0034	sw     s1, $0010(sp)
801D0038	sw     zero, $0014(sp)
801D003C	sw     zero, $0018(sp)
801D0040	sw     s0, $001c(sp)
801D0044	sw     s1, $0020(sp)
801D0048	sw     zero, $0024(sp)
801D004C	sw     zero, $0028(sp)
801D0050	sw     zero, $002c(sp)
801D0054	sw     s0, $0030(sp)
801D0058	jal    $80026448
801D005C	sw     zero, $0034(sp)
801D0060	addiu  a0, s2, $0012
801D0064	addu   a1, zero, zero
801D0068	addu   a2, zero, zero
801D006C	ori    a3, zero, $0001
801D0070	ori    v0, zero, $0009
801D0074	sw     s1, $0010(sp)
801D0078	sw     zero, $0014(sp)
801D007C	sw     zero, $0018(sp)
801D0080	sw     s0, $001c(sp)
801D0084	sw     v0, $0020(sp)
801D0088	sw     zero, $0024(sp)
801D008C	sw     zero, $0028(sp)
801D0090	sw     zero, $002c(sp)
801D0094	sw     zero, $0030(sp)
801D0098	jal    $80026448
801D009C	sw     zero, $0034(sp)
801D00A0	lui    at, $801d
801D00A4	sw     zero, $01c4(at)
801D00A8	lw     ra, $004c(sp)
801D00AC	lw     s2, $0048(sp)
801D00B0	lw     s1, $0044(sp)
801D00B4	lw     s0, $0040(sp)
801D00B8	addiu  sp, sp, $0050
801D00BC	jr     ra 
801D00C0	nop

801D00C4	lui    a0, $8006
801D00C8	lw     a0, $2f58(a0)
801D00CC	addiu  sp, sp, $ffd0 (=-$30)
801D00D0	sw     ra, $0028(sp)
801D00D4	sw     s1, $0024(sp)
801D00D8	jal    $800230c4
801D00DC	sw     s0, $0020(sp)
801D00E0	lui    v0, $801d
801D00E4	lw     v0, $01c4(v0)
801D00E8	nop
if (V0 == 0)
{
    801D00F8	lui    v0, $801d
    801D00FC	lb     v0, $01eb(v0)
    801D0100	lui    a1, $801d
    801D0104	lh     a1, $01d2(a1)
    801D0108	sll    v0, v0, $06
    801D010C	addu   a1, a1, v0
    801D0114	addiu  a1, a1, $0020

    A0 = 0;
    func1eb2c; // cursor
}

801D0118	ori    a0, zero, $0010
801D011C	ori    a1, zero, $000b
801D0120	lui    a2, $801d
801D0124	addiu  a2, a2, $01d8
801D0128	jal    $80026f44
801D012C	ori    a3, zero, $0007
801D0130	addu   s1, zero, zero
801D0134	lui    s0, $801d
801D0138	addiu  s0, s0, $01c8

loop1d013c:	; 801D013C
801D013C	jal    $8001e040
801D0140	addu   a0, s0, zero
801D0144	addiu  s1, s1, $0001
801D0148	slti   v0, s1, $0002
801D014C	bne    v0, zero, loop1d013c [$801d013c]
801D0150	addiu  s0, s0, $0008
801D0154	lui    v0, $801d
801D0158	lw     v0, $01c4(v0)
801D015C	nop
801D0160	sll    a0, v0, $03
801D0164	addu   a0, a0, v0
801D0168	sll    a0, a0, $01
801D016C	lui    v0, $801d
801D0170	addiu  v0, v0, $01e0
801D0174	jal    $800264a8
801D0178	addu   a0, a0, v0
801D017C	lui    v0, $8006
801D0180	lhu    v0, $2d7e(v0)
801D0184	nop
801D0188	andi   v0, v0, $0040
801D018C	beq    v0, zero, L1d01a4 [$801d01a4]
801D0190	ori    a0, zero, $0005
801D0194	jal    $8002305c
801D0198	addu   a1, zero, zero
801D019C	jal    $8002120c
801D01A0	addu   a0, zero, zero

L1d01a4:	; 801D01A4
801D01A4	lw     ra, $0028(sp)
801D01A8	lw     s1, $0024(sp)
801D01AC	lw     s0, $0020(sp)
801D01B0	addiu  sp, sp, $0030
801D01B4	jr     ra 
801D01B8	nop

801D01BC	jr     ra 
801D01C0	nop
