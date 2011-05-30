////////////////////////////////
// func3bec8
8003BEC8	lui    v0, $8006
8003BECC	lhu    v0, $8c18(v0)
8003BEE4	andi   v0, v0, $0040
if (V0 != 0)
{
    return 0;
}

8003BEF0	lui    a0, $f200
8003BEF4	jal    func40508 [$80040508]
8003BEF8	ori    a0, a0, $0002
8003BEFC	lui    v1, $8006
8003BF00	lw     v1, $8ba0(v1)
8003BF04	nop
8003BF08	addiu  a0, v1, $0001
8003BF0C	andi   v1, v1, $0001
8003BF10	lui    at, $8006
8003BF14	sw     a0, $8ba0(at)
S3 = V0;
if (V1 != 0)
{
    S0 = 80059a94;

    8003BF28	lh     v0, $0000(s0)
    8003BF2C	nop
    8003BF30	beq    v0, zero, L3bf70 [$8003bf70]
    8003BF34	nop
    8003BF38	jal    func3c32c [$8003c32c]
    8003BF3C	addiu  a0, s0, $fff8 (=-$8)
    8003BF40	addiu  a1, s0, $ffcc (=-$34)
    8003BF44	lh     a0, $fffa(s0)
    8003BF48	lui    at, $8006
    8003BF4C	sh     a0, $9a84(at)
    8003BF50	jal    func38d14 [$80038d14]
    8003BF54	addu   a2, zero, zero
    8003BF58	lui    v0, $8006
    8003BF5C	lw     v0, $9a5c(v0)
    8003BF60	nop
    8003BF64	ori    v0, v0, $0003
    8003BF68	lui    at, $8006
    8003BF6C	sw     v0, $9a5c(at)

    L3bf70:	; 8003BF70
    8003BF70	lui    v0, $8006
    8003BF74	lh     v0, $9aa0(v0)
    8003BF78	nop
    8003BF7C	beq    v0, zero, L3bfbc [$8003bfbc]
    8003BF80	nop
    8003BF84	jal    func3c32c [$8003c32c]
    8003BF88	addiu  a0, s0, $0004
    8003BF8C	lui    v0, $8006
    8003BF90	lw     v0, $9a5c(v0)
    8003BF94	lhu    v1, $0006(s0)
    8003BF98	ori    v0, v0, $00c0
    8003BF9C	lui    at, $8006
    8003BFA0	sh     v1, $9a86(at)
    8003BFA4	lui    at, $8006
    8003BFA8	sh     v1, $9a6e(at)
    8003BFAC	lui    at, $8006
    8003BFB0	sh     v1, $9a6c(at)
    8003BFB4	lui    at, $8006
    8003BFB8	sw     v0, $9a5c(at)

    L3bfbc:	; 8003BFBC
    8003BFBC	lw     v0, $ffc8(s0)
    8003BFC0	nop
    A0 = S0 - 38;
    if (V0 != 0)
    {
        8003BFCC	jal    func4d830 [$8004d830]
        8003BFD0	nop
        8003BFD4	sw     zero, $ffc8(s0)
    }
}

func3e7a8; // update spu registers

8003BFE0	lui    s0, $8006
8003BFE4	lw     s0, $8c00(s0)
8003BFE8	nop
8003BFEC	beq    s0, zero, L3c234 [$8003c234]
8003BFF0	nop

L3bff4:	; 8003BFF4
8003BFF4	lh     v0, $0010(s0)
8003BFF8	nop
8003BFFC	bgez   v0, L3c21c [$8003c21c]
8003C000	nop
8003C004	lw     v1, $002c(s0)
8003C008	nop
8003C00C	beq    v1, zero, L3c030 [$8003c030]
8003C010	nop
8003C014	lw     v0, $0024(s0)
8003C018	nop
8003C01C	sltu   v0, v0, v1

L3c020:	; 8003C020
8003C020	bne    v0, zero, L3c030 [$8003c030]
8003C024	nop
8003C028	jal    func3ad2c [$8003ad2c]
8003C02C	addu   a0, s0, zero

L3c030:	; 8003C030
8003C030	lh     v0, $006c(s0)
8003C034	nop
8003C038	beq    v0, zero, L3c060 [$8003c060]
8003C03C	nop
8003C040	jal    func3c32c [$8003c32c]
8003C044	addiu  a0, s0, $0064
8003C048	lh     v0, $005a(s0)
8003C04C	lh     v1, $0066(s0)
8003C050	nop
8003C054	mult   v0, v1
8003C058	mflo   v0
8003C05C	sw     v0, $0054(s0)

L3c060:	; 8003C060
8003C060	lh     v0, $0078(s0)
8003C064	nop
8003C068	beq    v0, zero, L3c084 [$8003c084]
8003C06C	nop
8003C070	jal    func3c32c [$8003c32c]
8003C074	addiu  a0, s0, $0070
8003C078	ori    a0, zero, $0100
8003C07C	jal    func3e528 [$8003e528]
8003C080	addu   a1, s0, zero

L3c084:	; 8003C084
8003C084	lh     v0, $0084(s0)
8003C088	nop
8003C08C	beq    v0, zero, L3c0a8 [$8003c0a8]
8003C090	nop
8003C094	jal    func3c32c [$8003c32c]
8003C098	addiu  a0, s0, $007c
8003C09C	ori    a0, zero, $0200
8003C0A0	jal    func3e528 [$8003e528]
8003C0A4	addu   a1, s0, zero

L3c0a8:	; 8003C0A8
8003C0A8	lh     v0, $0090(s0)
8003C0AC	nop
8003C0B0	beq    v0, zero, L3c0cc [$8003c0cc]
8003C0B4	nop
8003C0B8	jal    func3c32c [$8003c32c]
8003C0BC	addiu  a0, s0, $0088
8003C0C0	ori    a0, zero, $0100
8003C0C4	jal    func3e528 [$8003e528]
8003C0C8	addu   a1, s0, zero

L3c0cc:	; 8003C0CC
8003C0CC	lw     v0, $0020(s0)
8003C0D0	lh     v1, $0066(s0)
8003C0D4	lw     a0, $0028(s0)
8003C0D8	lw     a1, $0054(s0)
8003C0DC	addiu  v0, v0, $0001
8003C0E0	sw     v0, $0020(s0)
8003C0E4	lw     v0, $0050(s0)
8003C0E8	addu   v1, v1, a0
8003C0EC	sw     v1, $0028(s0)
8003C0F0	subu   v0, v0, a1
8003C0F4	bgez   v0, L3c21c [$8003c21c]
8003C0F8	sw     v0, $0050(s0)
8003C0FC	lui    a0, $0001

loop3c100:	; 8003C100
8003C100	lhu    v0, $0036(s0)
8003C104	lw     v1, $0050(s0)
8003C108	addiu  v0, v0, $ffff (=-$1)
8003C10C	addu   v1, v1, a0
8003C110	sh     v0, $0036(s0)
8003C114	andi   v0, v0, $ffff
8003C118	bne    v0, zero, L3c158 [$8003c158]
8003C11C	sw     v1, $0050(s0)
8003C120	lhu    v1, $003a(s0)
8003C124	lhu    v0, $0034(s0)
8003C128	sh     v1, $0036(s0)
8003C12C	lhu    v1, $0038(s0)
8003C130	addiu  v0, v0, $0001
8003C134	sh     v0, $0034(s0)
8003C138	andi   v0, v0, $ffff
8003C13C	sltu   v1, v1, v0
8003C140	beq    v1, zero, L3c158 [$8003c158]
8003C144	ori    v0, zero, $0001
8003C148	lhu    v1, $0032(s0)
8003C14C	sh     v0, $0034(s0)
8003C150	addiu  v1, v1, $0001
8003C154	sh     v1, $0032(s0)

L3c158:	; 8003C158
8003C158	lbu    s1, $0014(s0)
8003C15C	nop
8003C160	beq    s1, zero, L3c188 [$8003c188]
8003C164	addiu  s2, s0, $0094
8003C168	addu   a0, s0, zero
8003C16C	addu   a1, s2, zero
8003C170	jal    func3c36c [$8003c36c]
8003C174	addu   a2, s1, zero
8003C178	addu   a0, s0, zero
8003C17C	addu   a1, s2, zero
8003C180	jal    func3c590 [$8003c590]
8003C184	addu   a2, s1, zero

L3c188:	; 8003C188
8003C188	lw     v0, $0048(s0)
8003C18C	nop
8003C190	beq    v0, zero, L3c1f8 [$8003c1f8]
8003C194	nop
8003C198	lw     v0, $0024(s0)
8003C19C	lw     v1, $0070(s0)
8003C1A0	addiu  v0, v0, $0001
8003C1A4	bne    v1, zero, L3c1c4 [$8003c1c4]
8003C1A8	sw     v0, $0024(s0)
8003C1AC	jal    func39af4 [$80039af4]
8003C1B0	addu   a0, s0, zero
8003C1B4	lhu    v0, $0010(s0)
8003C1B8	nop
8003C1BC	ori    v0, v0, $0100
8003C1C0	sh     v0, $0010(s0)

L3c1c4:	; 8003C1C4
8003C1C4	lhu    v1, $0032(s0)
8003C1C8	lhu    v0, $001e(s0)
8003C1CC	nop
8003C1D0	bne    v1, v0, L3c20c [$8003c20c]
8003C1D4	addu   a0, s0, zero
8003C1D8	addu   a1, zero, zero
8003C1DC	lhu    v0, $0010(s0)
8003C1E0	addu   a2, zero, zero
8003C1E4	andi   v0, v0, $ffdf
8003C1E8	jal    func3a6e0 [$8003a6e0]
8003C1EC	sh     v0, $0010(s0)
8003C1F0	j      L3c20c [$8003c20c]
8003C1F4	sh     zero, $001e(s0)

L3c1f8:	; 8003C1F8
8003C1F8	lhu    v0, $0010(s0)
8003C1FC	nop
8003C200	andi   v0, v0, $7fff
8003C204	j      L3c21c [$8003c21c]
8003C208	sh     v0, $0010(s0)

L3c20c:	; 8003C20C
8003C20C	lw     v0, $0050(s0)
8003C210	nop
8003C214	bltz   v0, loop3c100 [$8003c100]
8003C218	lui    a0, $0001

L3c21c:	; 8003C21C
8003C21C	lw     s0, $0000(s0)
8003C220	nop
8003C224	bne    s0, zero, L3bff4 [$8003bff4]
8003C228	nop
8003C22C	lui    s0, $8006
8003C230	lw     s0, $8c00(s0)

L3c234:	; 8003C234
8003C234	nop
8003C238	beq    s0, zero, L3c290 [$8003c290]
8003C23C	nop

loop3c240:	; 8003C240
8003C240	lh     v0, $0010(s0)
8003C244	nop
8003C248	bgez   v0, L3c280 [$8003c280]
8003C24C	nop
8003C250	lbu    s1, $0014(s0)
8003C254	nop
8003C258	beq    s1, zero, L3c280 [$8003c280]
8003C25C	addiu  s2, s0, $0094
8003C260	addu   a0, s0, zero
8003C264	addu   a1, s2, zero
8003C268	jal    func3ee8c [$8003ee8c]
8003C26C	addu   a2, s1, zero
8003C270	addu   a0, s0, zero
8003C274	addu   a1, s2, zero
8003C278	jal    func3ea98 [$8003ea98]
8003C27C	addu   a2, s1, zero

L3c280:	; 8003C280
8003C280	lw     s0, $0000(s0)
8003C284	nop
8003C288	bne    s0, zero, loop3c240 [$8003c240]
8003C28C	nop

L3c290:	; 8003C290
8003C290	jal    func3ea04 [$8003ea04]
8003C294	nop
8003C298	lui    v1, $8006
8003C29C	lhu    v1, $8bf8(v1)
8003C2A0	nop
8003C2A4	andi   v0, v1, $0001
8003C2A8	beq    v0, zero, L3c2c0 [$8003c2c0]
8003C2AC	andi   v0, v1, $fffe
8003C2B0	lui    at, $8006
8003C2B4	sh     v0, $8bf8(at)
8003C2B8	jal    func4d4a8 [$8004d4a8]
8003C2BC	ori    a0, zero, $0001

L3c2c0:	; 8003C2C0
8003C2C0	lui    a0, $f200
8003C2C4	jal    func40508 [$80040508]
8003C2C8	ori    a0, a0, $0002
8003C2CC	addu   v1, v0, zero
8003C2D0	sltu   v0, v1, s3
8003C2D4	bne    v0, zero, L3c30c [$8003c30c]
8003C2D8	addu   v0, zero, zero
8003C2DC	subu   v0, v1, s3
8003C2E0	lui    a0, $8006
8003C2E4	lw     a0, $8c60(a0)
8003C2E8	lui    v1, $8006
8003C2EC	lw     v1, $8bdc(v1)
8003C2F0	addu   v0, v0, a0
8003C2F4	addiu  v1, v1, $0001
8003C2F8	lui    at, $8006
8003C2FC	sw     v0, $8c60(at)
8003C300	lui    at, $8006
8003C304	sw     v1, $8bdc(at)

L3c308:	; 8003C308
8003C308	addu   v0, zero, zero

L3c30c:	; 8003C30C
////////////////////////////////
