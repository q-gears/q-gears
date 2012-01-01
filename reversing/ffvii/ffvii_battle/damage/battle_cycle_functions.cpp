////////////////////////////////////////////////////
// funca3354
A0 = w[800f3944];
800A3364	jal    funca32c0 [$800a32c0]
800A3368	nop
800A336C	lui    v0, $800f
800A3370	lw     v0, $3944(v0)
800A3374	nop
800A3378	beq    v0, zero, La3390 [$800a3390]
800A337C	nop
800A3380	jal    funca2f4c [$800a2f4c]
800A3384	nop
800A3388	addiu  v1, zero, $ffff (=-$1)
800A338C	sb     v1, $0000(v0)

La3390:	; 800A3390
800A3390	jal    func155b0 [$800155b0]
800A3394	nop
800A3398	addu   a1, zero, zero
800A339C	addiu  a3, zero, $ffff (=-$1)
800A33A0	addu   a2, zero, zero

loopa33a4:	; 800A33A4
800A33A4	lui    at, $8016
800A33A8	addu   at, at, a2

La33ac:	; 800A33AC
800A33AC	lb     a0, $3798(at)
800A33B0	nop

La33b4:	; 800A33B4
800A33B4	beq    a0, a3, La3404 [$800a3404]
800A33B8	addiu  v0, a0, $fffc (=-$4)
800A33BC	sltiu  v0, v0, $0006
800A33C0	beq    v0, zero, La33f4 [$800a33f4]
800A33C4	sll    v0, a0, $01

La33c8:	; 800A33C8
800A33C8	addu   v0, v0, a0
800A33CC	sll    v0, v0, $02
800A33D0	addu   v0, v0, a0
800A33D4	sll    v0, v0, $03
800A33D8	lui    at, $8010
800A33DC	addu   at, at, v0
800A33E0	lbu    v1, $83f0(at)
800A33E4	sll    v0, a0, $04
800A33E8	lui    at, $8016
800A33EC	addu   at, at, v0
800A33F0	sb     v1, $36b9(at)

La33f4:	; 800A33F4
800A33F4	addiu  a1, a1, $0001
800A33F8	slti   v0, a1, $0040
800A33FC	bne    v0, zero, loopa33a4 [$800a33a4]
800A3400	addiu  a2, a2, $000c

La3404:	; 800A3404
800A3404	jal    funcb6d6c [$800b6d6c]
800A3408	nop
800A340C	jal    funca3278 [$800a3278]
800A3410	nop
800A3414	ori    a1, zero, $0004
800A3418	ori    a0, zero, $01a0
800A341C	ori    v1, zero, $0040

loopa3420:	; 800A3420
800A3420	lui    at, $8010
800A3424	addu   at, at, a0
800A3428	lbu    v0, $83f0(at)
800A342C	addiu  a0, a0, $0068
800A3430	addiu  a1, a1, $0001
800A3434	lui    at, $8016
800A3438	addu   at, at, v1
800A343C	sb     v0, $36b9(at)
800A3440	slti   v0, a1, $000a
800A3444	bne    v0, zero, loopa3420 [$800a3420]
800A3448	addiu  v1, v1, $0010
////////////////////////////////////////////////////