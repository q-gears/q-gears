////////////////////////////////
// func3cedc
V0 = w[8005049c];
V1 = w[800504a0];
8003CEFC	lw     s0, $0000(v0)
8003CF00	lw     v0, $0000(v1)
8003CF04	lui    v1, $8005
8003CF08	lw     v1, $04a4(v1)
8003CF0C	nop
8003CF10	subu   v0, v0, v1
8003CF14	bgez   a0, L3cf2c [$8003cf2c]
8003CF18	andi   s1, v0, $ffff
8003CF1C	lui    v0, $8005
8003CF20	lw     v0, $1568(v0)
8003CF24	j      L3d00c [$8003d00c]
8003CF28	nop

L3cf2c:	; 8003CF2C
8003CF2C	ori    v0, zero, $0001
8003CF30	beq    a0, v0, L3d00c [$8003d00c]
8003CF34	addu   v0, s1, zero
8003CF38	blez   a0, L3cf58 [$8003cf58]
8003CF3C	nop
8003CF40	lui    v0, $8005
8003CF44	lw     v0, $04a8(v0)
8003CF48	nop
8003CF4C	addiu  v0, v0, $ffff (=-$1)
8003CF50	j      L3cf60 [$8003cf60]
8003CF54	addu   v0, v0, a0

L3cf58:	; 8003CF58
8003CF58	lui    v0, $8005
8003CF5C	lw     v0, $04a8(v0)

L3cf60:	; 8003CF60
8003CF60	blez   a0, L3cf6c [$8003cf6c]
8003CF64	addu   a1, zero, zero
8003CF68	addiu  a1, a0, $ffff (=-$1)

L3cf6c:	; 8003CF6C
8003CF6C	jal    func3d024 [$8003d024]
8003CF70	addu   a0, v0, zero
8003CF74	lui    v0, $8005
8003CF78	lw     v0, $049c(v0)
8003CF7C	nop
8003CF80	lw     s0, $0000(v0)
8003CF84	lui    a0, $8005
8003CF88	lw     a0, $1568(a0)
8003CF8C	ori    a1, zero, $0001
8003CF90	jal    func3d024 [$8003d024]
8003CF94	addiu  a0, a0, $0001
8003CF98	lui    v0, $0008
8003CF9C	and    v0, s0, v0
8003CFA0	beq    v0, zero, L3cfe4 [$8003cfe4]
8003CFA4	nop
8003CFA8	lui    v1, $8005
8003CFAC	lw     v1, $049c(v1)
8003CFB0	nop
8003CFB4	lw     v0, $0000(v1)
8003CFB8	nop
8003CFBC	xor    v0, s0, v0
8003CFC0	bltz   v0, L3cfe4 [$8003cfe4]
8003CFC4	nop
8003CFC8	lui    a0, $8000

loop3cfcc:	; 8003CFCC
8003CFCC	lw     v0, $0000(v1)
8003CFD0	nop
8003CFD4	xor    v0, s0, v0
8003CFD8	and    v0, v0, a0
8003CFDC	beq    v0, zero, loop3cfcc [$8003cfcc]
8003CFE0	nop

L3cfe4:	; 8003CFE4
8003CFE4	lui    v0, $8005
8003CFE8	lw     v0, $1568(v0)
8003CFEC	lui    v1, $8005
8003CFF0	lw     v1, $04a0(v1)
8003CFF4	lui    at, $8005
8003CFF8	sw     v0, $04a8(at)
8003CFFC	lw     v1, $0000(v1)
8003D000	addu   v0, s1, zero
8003D004	lui    at, $8005
8003D008	sw     v1, $04a4(at)

L3d00c:	; 8003D00C
////////////////////////////////



////////////////////////////////
// func14578
A3 = A2;
A2 = A1;
A1 = w[80048d84 + A0 * 8 + 4];
A0 = w[80048d84 + A0 * 8 + 0];
func33e34;
////////////////////////////////



////////////////////////////////
// func145bc
loop145cc:	; 800145CC
    func34b44;

    if (V0 == 0)
    {
        return;
    }

    800145DC	beq    s0, zero, loop145cc [$800145cc]
    800145E0	nop
    800145E4	jalr   s0 ra
    800145E8	nop
800145EC	j      loop145cc [$800145cc]
////////////////////////////////



////////////////////////////////
// func34b44
if (w[80071a60] >= 15)
{
    L34b60:	; 80034B60
    80034B60	j      L34b60 [$80034b60]
    80034B64	nop
}

V0 = w[80071a60];
V0 = w[8004a634 + V0 * 4];

20440380 0
7C440380 1
C0440380 2
BC450380 3
00460380 4
F8460380 5
54470380 6
28440380 7
44570380 8
30540380 9
20440380 a
B4470380 b
F8470380 c
F4480380 d
74490380 e
20440380 f
44440380 10
30440380 11
20440380 12
584A0380 13
904A0380 14

80034B90	jalr   v0 ra

V0 = w[80071a60];
////////////////////////////////