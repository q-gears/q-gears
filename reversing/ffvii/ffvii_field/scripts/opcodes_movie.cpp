////////////////////////////////
// 0xF8 PMVIE
800CCD54	lui    v0, $800a
800CCD58	lbu    v0, $d820(v0)
800CCD5C	addiu  sp, sp, $ffe8 (=-$18)
800CCD60	andi   v0, v0, $0003
800CCD64	beq    v0, zero, Lccd7c [$800ccd7c]
800CCD68	sw     ra, $0010(sp)
800CCD6C	lui    a0, $800a
800CCD70	addiu  a0, a0, $0be8
800CCD74	jal    funcbead4 [$800bead4]
800CCD78	ori    a1, zero, $0001

Lccd7c:	; 800CCD7C
800CCD7C	lui    v0, $8007
800CCD80	lbu    v0, $16cc(v0)
800CCD84	nop
800CCD88	beq    v0, zero, Lccdbc [$800ccdbc]
800CCD8C	nop
800CCD90	lui    v1, $8007
800CCD94	lbu    v1, $22c4(v1)
800CCD98	lui    v0, $8008
800CCD9C	addiu  v0, v0, $31fc
800CCDA0	sll    v1, v1, $01
800CCDA4	addu   v1, v1, v0
800CCDA8	lhu    a0, $0000(v1)
800CCDAC	addu   v0, zero, zero
800CCDB0	addiu  a0, a0, $0002
800CCDB4	j      Lcce84 [$800cce84]
800CCDB8	sh     a0, $0000(v1)

Lccdbc:	; 800CCDBC
800CCDBC	lui    v1, $800a
800CCDC0	lw     v1, $c6e0(v1)
800CCDC4	nop
800CCDC8	lbu    a0, $0001(v1)
800CCDCC	nop
800CCDD0	beq    a0, zero, Lcce34 [$800cce34]
800CCDD4	ori    v0, zero, $0003
800CCDD8	bne    a0, v0, Lcce84 [$800cce84]
800CCDDC	ori    v0, zero, $0001
800CCDE0	lh     a0, $0026(v1)
800CCDE4	nop
800CCDE8	beq    a0, v0, Lcce80 [$800cce80]
800CCDEC	ori    v0, zero, $0002
800CCDF0	bne    a0, v0, Lcce84 [$800cce84]
800CCDF4	ori    v0, zero, $0001
800CCDF8	sb     zero, $0001(v1)
800CCDFC	lui    v0, $800a
800CCE00	lw     v0, $c6e0(v0)
800CCE04	lui    a0, $8007
800CCE08	lbu    a0, $22c4(a0)
800CCE0C	sh     zero, $0026(v0)
800CCE10	lui    v0, $8008
800CCE14	addiu  v0, v0, $31fc
800CCE18	sll    a0, a0, $01
800CCE1C	addu   a0, a0, v0
800CCE20	lhu    v1, $0000(a0)
800CCE24	addu   v0, zero, zero
800CCE28	addiu  v1, v1, $0002
800CCE2C	j      Lcce84 [$800cce84]
800CCE30	sh     v1, $0000(a0)

Lcce34:	; 800CCE34
800CCE34	ori    v0, zero, $0003
800CCE38	sb     v0, $0001(v1)
800CCE3C	lui    v0, $8007
800CCE40	lbu    v0, $22c4(v0)
800CCE44	nop
800CCE48	sll    v0, v0, $01
800CCE4C	lui    at, $8008
800CCE50	addiu  at, at, $31fc
800CCE54	addu   at, at, v0
800CCE58	lhu    v1, $0000(at)
800CCE5C	lui    v0, $800a
800CCE60	lw     v0, $c6dc(v0)
800CCE64	nop
800CCE68	addu   v0, v0, v1
800CCE6C	lui    v1, $800a
800CCE70	lw     v1, $c6e0(v1)
800CCE74	lbu    v0, $0001(v0)
800CCE78	sh     zero, $0026(v1)
800CCE7C	sh     v0, $0002(v1)

Lcce80:	; 800CCE80
800CCE80	ori    v0, zero, $0001

Lcce84:	; 800CCE84
800CCE84	lw     ra, $0010(sp)
800CCE88	addiu  sp, sp, $0018
800CCE8C	jr     ra 
800CCE90	nop
////////////////////////////////



////////////////////////////////
// 0xF9 MOVIE
800CCE94	lui    v0, $800a
800CCE98	lbu    v0, $d820(v0)
800CCE9C	addiu  sp, sp, $ffe8 (=-$18)
800CCEA0	andi   v0, v0, $0003
800CCEA4	beq    v0, zero, Lccebc [$800ccebc]
800CCEA8	sw     ra, $0010(sp)
800CCEAC	lui    a0, $800a
800CCEB0	addiu  a0, a0, $0bf0
800CCEB4	jal    funcbead4 [$800bead4]
800CCEB8	addu   a1, zero, zero

Lccebc:	; 800CCEBC
800CCEBC	lui    v1, $8007
800CCEC0	lbu    v1, $16cc(v1)
800CCEC4	ori    v0, zero, $0001
800CCEC8	lui    at, $8007
800CCECC	sb     v0, $1c1c(at)
800CCED0	beq    v1, zero, Lccef8 [$800ccef8]
800CCED4	ori    v0, zero, $0004
800CCED8	lui    v1, $8007
800CCEDC	lbu    v1, $22c4(v1)
800CCEE0	lui    v0, $8008
800CCEE4	addiu  v0, v0, $31fc
800CCEE8	lui    at, $8011
800CCEEC	sh     zero, $44d4(at)
800CCEF0	j      Lccfa8 [$800ccfa8]
800CCEF4	sll    v1, v1, $01

Lccef8:	; 800CCEF8
800CCEF8	lui    a0, $800a
800CCEFC	lw     a0, $c6e0(a0)
800CCF00	nop
800CCF04	lbu    v1, $0001(a0)
800CCF08	nop
800CCF0C	beq    v1, v0, Lccf40 [$800ccf40]
800CCF10	slti   v0, v1, $0005
800CCF14	beq    v0, zero, Lccf2c [$800ccf2c]
800CCF18	nop
800CCF1C	beq    v1, zero, Lccfc0 [$800ccfc0]
800CCF20	ori    v0, zero, $0004
800CCF24	j      Lccfd8 [$800ccfd8]
800CCF28	ori    v0, zero, $0001

Lccf2c:	; 800CCF2C
800CCF2C	ori    v0, zero, $0014
800CCF30	beq    v1, v0, Lccf94 [$800ccf94]
800CCF34	ori    v0, zero, $0001
800CCF38	j      Lccfd8 [$800ccfd8]
800CCF3C	nop

Lccf40:	; 800CCF40
800CCF40	lh     v1, $0026(a0)
800CCF44	ori    v0, zero, $0001
800CCF48	beq    v1, v0, Lccfd4 [$800ccfd4]
800CCF4C	ori    v0, zero, $0002
800CCF50	bne    v1, v0, Lccfd8 [$800ccfd8]
800CCF54	ori    v0, zero, $0001
800CCF58	sb     zero, $0001(a0)
800CCF5C	lui    v0, $800a
800CCF60	lw     v0, $c6e0(v0)
800CCF64	lui    a0, $8007
800CCF68	lbu    a0, $22c4(a0)
800CCF6C	sh     zero, $0026(v0)
800CCF70	lui    v0, $8008
800CCF74	addiu  v0, v0, $31fc
800CCF78	sll    a0, a0, $01
800CCF7C	addu   a0, a0, v0
800CCF80	lhu    v1, $0000(a0)
800CCF84	addu   v0, zero, zero
800CCF88	addiu  v1, v1, $0001
800CCF8C	j      Lccfd8 [$800ccfd8]
800CCF90	sh     v1, $0000(a0)

Lccf94:	; 800CCF94
800CCF94	lui    v1, $8007
800CCF98	lbu    v1, $22c4(v1)
800CCF9C	lui    v0, $8008
800CCFA0	addiu  v0, v0, $31fc
800CCFA4	sll    v1, v1, $01

Lccfa8:	; 800CCFA8
800CCFA8	addu   v1, v1, v0
800CCFAC	lhu    a0, $0000(v1)
800CCFB0	addu   v0, zero, zero
800CCFB4	addiu  a0, a0, $0001
800CCFB8	j      Lccfd8 [$800ccfd8]
800CCFBC	sh     a0, $0000(v1)

Lccfc0:	; 800CCFC0
800CCFC0	sb     v0, $0001(a0)
800CCFC4	lui    v0, $800a
800CCFC8	lw     v0, $c6e0(v0)
800CCFCC	nop
800CCFD0	sh     zero, $0026(v0)

Lccfd4:	; 800CCFD4
800CCFD4	ori    v0, zero, $0001

Lccfd8:	; 800CCFD8
800CCFD8	lw     ra, $0010(sp)
800CCFDC	addiu  sp, sp, $0018
800CCFE0	jr     ra 
800CCFE4	nop
////////////////////////////////



////////////////////////////////
// 0xFA MVIEF
800CCFE8	lui    v0, $800a
800CCFEC	lbu    v0, $d820(v0)
800CCFF0	addiu  sp, sp, $ffe8 (=-$18)
800CCFF4	andi   v0, v0, $0003
800CCFF8	beq    v0, zero, Lcd010 [$800cd010]
800CCFFC	sw     ra, $0010(sp)
800CD000	lui    a0, $800a
800CD004	addiu  a0, a0, $0bf8
800CD008	jal    funcbead4 [$800bead4]
800CD00C	ori    a1, zero, $0002

Lcd010:	; 800CD010
800CD010	lui    v0, $8007
800CD014	lbu    v0, $16cc(v0)
800CD018	nop
800CD01C	bne    v0, zero, Lcd068 [$800cd068]
800CD020	ori    a0, zero, $0002
800CD024	lui    v0, $800a
800CD028	lw     v0, $c6e0(v0)
800CD02C	nop
800CD030	lh     a2, $0088(v0)
800CD034	jal    store_memory_block_two_bytes [$800c0248]
800CD038	ori    a1, zero, $0002
800CD03C	lui    a0, $8007
800CD040	lbu    a0, $22c4(a0)
800CD044	lui    v0, $8008
800CD048	addiu  v0, v0, $31fc
800CD04C	sll    a0, a0, $01
800CD050	addu   a0, a0, v0
800CD054	lhu    v1, $0000(a0)
800CD058	addu   v0, zero, zero
800CD05C	addiu  v1, v1, $0003
800CD060	j      Lcd0b4 [$800cd0b4]
800CD064	sh     v1, $0000(a0)

Lcd068:	; 800CD068
800CD068	lui    a2, $8011
800CD06C	lh     a2, $44d4(a2)
800CD070	jal    store_memory_block_two_bytes [$800c0248]
800CD074	ori    a1, zero, $0002
800CD078	addu   v0, zero, zero
800CD07C	lui    a1, $8007
800CD080	lbu    a1, $22c4(a1)
800CD084	lui    v1, $8008
800CD088	addiu  v1, v1, $31fc
800CD08C	sll    a1, a1, $01
800CD090	addu   a1, a1, v1
800CD094	lui    v1, $8011
800CD098	lhu    v1, $44d4(v1)
800CD09C	lhu    a0, $0000(a1)
800CD0A0	addiu  v1, v1, $0001
800CD0A4	addiu  a0, a0, $0003
800CD0A8	lui    at, $8011
800CD0AC	sh     v1, $44d4(at)
800CD0B0	sh     a0, $0000(a1)

Lcd0b4:	; 800CD0B4
800CD0B4	lw     ra, $0010(sp)
800CD0B8	addiu  sp, sp, $0018
800CD0BC	jr     ra 
800CD0C0	nop
////////////////////////////////



////////////////////////////////
// 0xFB MVCAM
800C5564	lui    v0, $800a
800C5568	lbu    v0, $d820(v0)
800C556C	addiu  sp, sp, $ffe0 (=-$20)
800C5570	andi   v0, v0, $0003
800C5574	beq    v0, zero, Lc558c [$800c558c]
800C5578	sw     ra, $0018(sp)
800C557C	lui    a0, $800a
800C5580	addiu  a0, a0, $0910
800C5584	jal    funcbead4 [$800bead4]
800C5588	ori    a1, zero, $0001

Lc558c:	; 800C558C
800C558C	lui    v0, $8007
800C5590	lbu    v0, $22c4(v0)
800C5594	nop
800C5598	sll    v0, v0, $01
800C559C	lui    at, $8008
800C55A0	addiu  at, at, $31fc
800C55A4	addu   at, at, v0
800C55A8	lhu    v1, $0000(at)
800C55AC	lui    v0, $800a
800C55B0	lw     v0, $c6dc(v0)
800C55B4	nop
800C55B8	addu   v0, v0, v1
800C55BC	lui    v1, $800a
800C55C0	lw     v1, $c6e0(v1)
800C55C4	lbu    v0, $0001(v0)
800C55C8	nop
800C55CC	sb     v0, $0039(v1)
800C55D0	lui    v1, $8007
800C55D4	lbu    v1, $22c4(v1)
800C55D8	lui    v0, $8008
800C55DC	addiu  v0, v0, $31fc
800C55E0	sll    v1, v1, $01
800C55E4	addu   v1, v1, v0
800C55E8	lhu    v0, $0000(v1)
800C55EC	nop
800C55F0	addiu  v0, v0, $0002
800C55F4	sh     v0, $0000(v1)
800C55F8	addu   v0, zero, zero
800C55FC	lw     ra, $0018(sp)
800C5600	addiu  sp, sp, $0020
800C5604	jr     ra 
800C5608	nop
////////////////////////////////
