////////////////////////////////
// func2e954:	; 8002E954
8002E95C	addu   s0, a0, zero
8002E968	lhu    v0, $005c(s0)
8002E96C	nop
8002E970	beq    v0, zero, L2e9b8 [$8002e9b8]
8002E974	addu   s1, a1, zero
8002E978	lhu    v0, $005c(s0)
8002E97C	lw     v1, $0044(s0)
8002E980	lw     a0, $0048(s0)
8002E984	addiu  v0, v0, $ffff (=-$1)
8002E988	addu   a1, v1, a0
8002E98C	sh     v0, $005c(s0)
8002E990	lui    v0, $ffe0
8002E994	and    a0, a1, v0
8002E998	and    v1, v1, v0
8002E99C	beq    a0, v1, L2e9b4 [$8002e9b4]
8002E9A0	nop
8002E9A4	lw     v0, $00e0(s0)
8002E9A8	nop
8002E9AC	ori    v0, v0, $0003
8002E9B0	sw     v0, $00e0(s0)

L2e9b4:	; 8002E9B4
8002E9B4	sw     a1, $0044(s0)

L2e9b8:	; 8002E9B8
8002E9B8	lhu    v0, $00a4(s0)
8002E9BC	nop
8002E9C0	beq    v0, zero, L2ea14 [$8002ea14]
8002E9C4	nop
8002E9C8	lhu    v0, $00a4(s0)
8002E9CC	nop
8002E9D0	addiu  v0, v0, $ffff (=-$1)
8002E9D4	sh     v0, $00a4(s0)
8002E9D8	andi   v0, v0, $ffff
8002E9DC	bne    v0, zero, L2ea14 [$8002ea14]
8002E9E0	nop
8002E9E4	lui    v0, $800a
8002E9E8	lw     v0, $9fec(v0)
8002E9EC	lui    v1, $800a
8002E9F0	lw     v1, $a13c(v1)
8002E9F4	xor    v0, s1, v0
8002E9F8	ori    v1, v1, $0010
8002E9FC	lui    at, $800a
8002EA00	sw     v0, $9fec(at)
8002EA04	lui    at, $800a
8002EA08	sw     v1, $a13c(at)
8002EA0C	jal    func2ff4c [$8002ff4c]
8002EA10	nop

L2ea14:	; 8002EA14
8002EA14	lhu    v0, $00a6(s0)
8002EA18	nop
8002EA1C	beq    v0, zero, L2ea60 [$8002ea60]
8002EA20	nop
8002EA24	lhu    v0, $00a6(s0)
8002EA28	nop
8002EA2C	addiu  v0, v0, $ffff (=-$1)
8002EA30	sh     v0, $00a6(s0)
8002EA34	andi   v0, v0, $ffff
8002EA38	bne    v0, zero, L2ea60 [$8002ea60]
8002EA3C	nop
8002EA40	lui    v0, $800a
8002EA44	lw     v0, $9ff4(v0)
8002EA48	nop
8002EA4C	xor    v0, s1, v0
8002EA50	lui    at, $800a
8002EA54	sw     v0, $9ff4(at)
8002EA58	jal    func30148 [$80030148]
8002EA5C	nop

L2ea60:	; 8002EA60
8002EA60	lhu    v0, $0080(s0)
8002EA64	nop
8002EA68	beq    v0, zero, L2eb54 [$8002eb54]
8002EA6C	nop
8002EA70	lhu    v1, $0080(s0)
8002EA74	lhu    v0, $007e(s0)
8002EA78	lhu    a0, $0082(s0)
8002EA7C	addiu  v1, v1, $ffff (=-$1)
8002EA80	addu   v0, v0, a0
8002EA84	sh     v1, $0080(s0)
8002EA88	andi   v1, v0, $7f00
8002EA8C	sh     v0, $007e(s0)
8002EA90	andi   v0, v0, $8000
8002EA94	beq    v0, zero, L2eaa8 [$8002eaa8]
8002EA98	srl    a0, v1, $08
8002EA9C	lw     v0, $0030(s0)
8002EAA0	j      L2eac0 [$8002eac0]
8002EAA4	mult   a0, v0

L2eaa8:	; 8002EAA8
8002EAA8	lw     v0, $0030(s0)
8002EAAC	nop
8002EAB0	sll    v1, v0, $04
8002EAB4	subu   v1, v1, v0
8002EAB8	srl    v1, v1, $08
8002EABC	mult   a0, v1

L2eac0:	; 8002EAC0
8002EAC0	mflo   v0
8002EAC4	srl    v0, v0, $07
8002EAC8	lhu    v1, $0078(s0)
8002EACC	sh     v0, $007c(s0)
8002EAD0	ori    v0, zero, $0001
8002EAD4	beq    v1, v0, L2eb54 [$8002eb54]
8002EAD8	nop
8002EADC	lw     a0, $0018(s0)
8002EAE0	nop
8002EAE4	lh     v0, $0000(a0)
8002EAE8	nop
8002EAEC	bne    v0, zero, L2eb14 [$8002eb14]
8002EAF0	nop
8002EAF4	lh     v0, $0002(a0)
8002EAF8	nop
8002EAFC	bne    v0, zero, L2eb14 [$8002eb14]
8002EB00	nop
8002EB04	lh     v0, $0004(a0)
8002EB08	nop
8002EB0C	sll    v0, v0, $01
8002EB10	addu   a0, a0, v0

L2eb14:	; 8002EB14
8002EB14	lhu    v1, $007c(s0)
8002EB18	lh     v0, $0000(a0)
8002EB1C	nop
8002EB20	mult   v1, v0
8002EB24	lh     v1, $00d6(s0)
8002EB28	mflo   v0
8002EB2C	sra    a1, v0, $10
8002EB30	beq    a1, v1, L2eb54 [$8002eb54]
8002EB34	nop
8002EB38	lw     v0, $00e0(s0)
8002EB3C	sh     a1, $00d6(s0)
8002EB40	ori    v0, v0, $0010
8002EB44	bltz   a1, L2eb54 [$8002eb54]
8002EB48	sw     v0, $00e0(s0)
8002EB4C	sll    v0, a1, $01
8002EB50	sh     v0, $00d6(s0)

L2eb54:	; 8002EB54
8002EB54	lhu    v0, $0092(s0)
8002EB58	nop
8002EB5C	beq    v0, zero, L2ec24 [$8002ec24]
8002EB60	nop
8002EB64	lhu    v1, $0090(s0)
8002EB68	lhu    a0, $0094(s0)
8002EB6C	lhu    v0, $0092(s0)
8002EB70	addu   v1, v1, a0
8002EB74	sh     v1, $0090(s0)
8002EB78	lhu    v1, $008c(s0)
8002EB7C	addiu  v0, v0, $ffff (=-$1)
8002EB80	sh     v0, $0092(s0)
8002EB84	ori    v0, zero, $0001
8002EB88	beq    v1, v0, L2ec24 [$8002ec24]
8002EB8C	nop
8002EB90	lw     a0, $001c(s0)
8002EB94	nop
8002EB98	lh     v0, $0000(a0)
8002EB9C	nop
8002EBA0	bne    v0, zero, L2ebc8 [$8002ebc8]
8002EBA4	nop
8002EBA8	lh     v0, $0002(a0)
8002EBAC	nop
8002EBB0	bne    v0, zero, L2ebc8 [$8002ebc8]
8002EBB4	nop
8002EBB8	lh     v0, $0004(a0)
8002EBBC	nop
8002EBC0	sll    v0, v0, $01
8002EBC4	addu   a0, a0, v0

L2ebc8:	; 8002EBC8
8002EBC8	lh     v1, $0046(s0)
8002EBCC	lw     v0, $002c(s0)
8002EBD0	nop
8002EBD4	mult   v1, v0
8002EBD8	lhu    v1, $0090(s0)
8002EBDC	mflo   v0
8002EBE0	srl    v1, v1, $08
8002EBE4	srl    v0, v0, $07
8002EBE8	mult   v0, v1
8002EBEC	lh     v1, $0000(a0)
8002EBF0	mflo   v0
8002EBF4	sll    v0, v0, $09
8002EBF8	sra    a1, v0, $10
8002EBFC	mult   a1, v1
8002EC00	lh     v1, $00d8(s0)
8002EC04	mflo   v0
8002EC08	sra    a1, v0, $0f
8002EC0C	beq    a1, v1, L2ec24 [$8002ec24]
8002EC10	nop
8002EC14	lw     v0, $00e0(s0)
8002EC18	sh     a1, $00d8(s0)
8002EC1C	ori    v0, v0, $0003
8002EC20	sw     v0, $00e0(s0)

L2ec24:	; 8002EC24
8002EC24	lhu    v0, $00a0(s0)
8002EC28	nop
8002EC2C	beq    v0, zero, L2eccc [$8002eccc]
8002EC30	nop
8002EC34	lhu    v1, $009e(s0)
8002EC38	lhu    a0, $00a2(s0)
8002EC3C	lhu    v0, $00a0(s0)
8002EC40	addu   v1, v1, a0
8002EC44	sh     v1, $009e(s0)
8002EC48	lhu    v1, $009a(s0)
8002EC4C	addiu  v0, v0, $ffff (=-$1)
8002EC50	sh     v0, $00a0(s0)
8002EC54	ori    v0, zero, $0001
8002EC58	beq    v1, v0, L2eccc [$8002eccc]
8002EC5C	nop
8002EC60	lw     a0, $0020(s0)
8002EC64	nop
8002EC68	lh     v0, $0000(a0)
8002EC6C	nop
8002EC70	bne    v0, zero, L2ec98 [$8002ec98]
8002EC74	nop
8002EC78	lh     v0, $0002(a0)
8002EC7C	nop
8002EC80	bne    v0, zero, L2ec98 [$8002ec98]
8002EC84	nop
8002EC88	lh     v0, $0004(a0)
8002EC8C	nop
8002EC90	sll    v0, v0, $01
8002EC94	addu   a0, a0, v0

L2ec98:	; 8002EC98
8002EC98	lhu    v0, $009e(s0)
8002EC9C	lh     v1, $0000(a0)
8002ECA0	srl    v0, v0, $08
8002ECA4	mult   v0, v1
8002ECA8	lh     v1, $00da(s0)
8002ECAC	mflo   v0
8002ECB0	sra    a1, v0, $0f
8002ECB4	beq    a1, v1, L2eccc [$8002eccc]
8002ECB8	nop
8002ECBC	lw     v0, $00e0(s0)
8002ECC0	sh     a1, $00da(s0)
8002ECC4	ori    v0, v0, $0003
8002ECC8	sw     v0, $00e0(s0)

L2eccc:	; 8002ECCC
8002ECCC	lhu    v0, $0064(s0)
8002ECD0	nop
8002ECD4	beq    v0, zero, L2ed1c [$8002ed1c]
8002ECD8	nop
8002ECDC	lhu    v0, $0064(s0)
V1 = w[S0 + 34];
8002ECE8	addiu  v0, v0, $ffff (=-$1)
A1 = V1 + w[S0 + 4c];
8002ECF0	sh     v0, $0064(s0)
8002ECF4	lui    v0, $ffff
8002ECF8	and    a0, a1, v0
8002ECFC	and    v1, v1, v0
8002ED00	beq    a0, v1, L2ed18 [$8002ed18]
8002ED04	nop
8002ED08	lw     v0, $00e0(s0)
8002ED0C	nop
8002ED10	ori    v0, v0, $0010
8002ED14	sw     v0, $00e0(s0)

L2ed18:	; 8002ED18
[S0 + 34] = w(A1);

L2ed1c:	; 8002ED1C
////////////////////////////////