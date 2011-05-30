
Entry:	; 80000000
80000000	addiu  sp, sp, $ffe8 (=-$18)
80000004	sw     ra, $0010(sp)
80000008	jal    $801b0364
8000000C	nop
80000010	lw     ra, $0010(sp)
80000014	addiu  sp, sp, $0018
80000018	jr     ra 
8000001C	nop

80000020	addiu  sp, sp, $ffe8 (=-$18)
80000024	addu   a2, zero, zero
80000028	lui    v0, $8015
8000002C	lh     v0, $169c(v0)
80000030	lui    v1, $8016
80000034	addiu  v1, v1, $2978
80000038	sw     ra, $0014(sp)
8000003C	sw     s0, $0010(sp)
80000040	sll    v0, v0, $05
80000044	addu   s0, v0, v1
80000048	lh     a1, $0014(s0)
8000004C	jal    $800d4368
80000050	addiu  a0, s0, $0004
80000054	lui    v1, $801c
80000058	addiu  v1, v1, $8550 (=-$7ab0)
8000005C	addiu  a0, v1, $fff8 (=-$8)
80000060	ori    a2, zero, $000c
80000064	lhu    v0, $0002(s0)
80000068	lui    a1, $8015
8000006C	lw     a1, $17c0(a1)
80000070	lui    a3, $801e
80000074	lw     a3, $8554(a3)
80000078	addiu  a1, a1, $0070
8000007C	jal    $800d4d90
80000080	sh     v0, $0000(v1)
80000084	lui    v1, $8006
80000088	lbu    v1, $2d98(v1)
8000008C	lui    at, $801e
80000090	sw     v0, $8554(at)
80000094	bne    v1, zero, L00c8 [$800000c8]
80000098	nop
8000009C	lhu    v0, $0002(s0)
800000A0	lui    v1, $801c
800000A4	lw     v1, $8454(v1)
800000A8	addiu  v0, v0, $0001
800000AC	sh     v0, $0002(s0)
800000B0	sll    v0, v0, $10
800000B4	sra    v0, v0, $10
800000B8	slt    v0, v0, v1
800000BC	bne    v0, zero, L00c8 [$800000c8]
800000C0	addiu  v0, zero, $ffff (=-$1)
800000C4	sh     v0, $0000(s0)

L00c8:	; 800000C8
800000C8	lw     ra, $0014(sp)
800000CC	lw     s0, $0010(sp)
800000D0	addiu  sp, sp, $0018
800000D4	jr     ra 
800000D8	nop

800000DC	lui    v0, $8015
800000E0	lh     v0, $169c(v0)
800000E4	lui    v1, $8006
800000E8	lbu    v1, $2d98(v1)
800000EC	addiu  sp, sp, $ffe0 (=-$20)
800000F0	sw     s1, $0014(sp)
800000F4	lui    s1, $8016
800000F8	addiu  s1, s1, $2978
800000FC	sw     ra, $0018(sp)
80000100	sw     s0, $0010(sp)
80000104	sll    v0, v0, $05
80000108	bne    v1, zero, L01c0 [$800001c0]
8000010C	addu   s0, v0, s1
80000110	lui    a0, $801b
80000114	addiu  a0, a0, $0020
80000118	lhu    v0, $0004(s0)
8000011C	lhu    v1, $000c(s0)
80000120	lhu    a1, $000e(s0)
80000124	lhu    a2, $0010(s0)
80000128	addu   v0, v0, v1
8000012C	sh     v0, $0004(s0)
80000130	lhu    v0, $0006(s0)
80000134	lhu    v1, $0008(s0)
80000138	addu   v0, v0, a1
8000013C	addu   v1, v1, a2
80000140	sh     v0, $0006(s0)
80000144	jal    $800bbeac
80000148	sh     v1, $0008(s0)
8000014C	sll    v0, v0, $05
80000150	addu   v0, v0, s1
80000154	lwl    v1, $0007(s0)
80000158	lwr    v1, $0004(s0)
8000015C	lwl    a0, $000b(s0)
80000160	lwr    a0, $0008(s0)
80000164	swl    v1, $0007(v0)
80000168	swr    v1, $0004(v0)
8000016C	swl    a0, $000b(v0)
80000170	swr    a0, $0008(v0)
80000174	ori    v1, zero, $2000
80000178	sh     v1, $0014(v0)
8000017C	lhu    v0, $0002(s0)
80000180	nop
80000184	addiu  v0, v0, $0001
80000188	sh     v0, $0002(s0)
8000018C	sll    v0, v0, $10
80000190	sra    v0, v0, $10
80000194	slti   v0, v0, $0010
80000198	bne    v0, zero, L01c0 [$800001c0]
8000019C	nop
800001A0	lh     a0, $0016(s0)
800001A4	jal    $800d4d4c
800001A8	ori    a1, zero, $0032
800001AC	lh     a0, $0016(s0)
800001B0	jal    $800d5774
800001B4	nop
800001B8	addiu  v0, zero, $ffff (=-$1)
800001BC	sh     v0, $0000(s0)

L01c0:	; 800001C0
800001C0	lw     ra, $0018(sp)
800001C4	lw     s1, $0014(sp)
800001C8	lw     s0, $0010(sp)
800001CC	addiu  sp, sp, $0020
800001D0	jr     ra 
800001D4	nop

800001D8	addiu  sp, sp, $ffd8 (=-$28)
800001DC	sw     s1, $001c(sp)
800001E0	addu   s1, a0, zero
800001E4	sw     s0, $0018(sp)
800001E8	lui    a0, $801b
800001EC	addiu  a0, a0, $00dc
800001F0	sw     ra, $0020(sp)
800001F4	jal    $800bbeac
800001F8	addu   s0, a1, zero
800001FC	addu   a0, s0, zero
80000200	sll    a1, a0, $01
80000204	addu   a1, a1, a0
80000208	sll    v1, a1, $05
8000020C	subu   v1, v1, a1
80000210	sll    v1, v1, $03
80000214	subu   v1, v1, a0
80000218	sll    v1, v1, $02
8000021C	sll    v0, v0, $05
80000220	lui    at, $8015
80000224	addiu  at, at, $1917
80000228	addu   at, at, v1
8000022C	lbu    a1, $0000(at)
80000230	lui    v1, $8016
80000234	addiu  v1, v1, $2978
80000238	addu   s0, v0, v1
8000023C	jal    $800d3994
80000240	addiu  a2, s0, $0004
80000244	addu   a0, s1, zero
80000248	sll    v1, s1, $01
8000024C	addu   v1, v1, s1
80000250	sll    v0, v1, $05
80000254	subu   v0, v0, v1
80000258	sll    v0, v0, $03
8000025C	subu   v0, v0, s1
80000260	sll    v0, v0, $02
80000264	lui    at, $8015
80000268	addiu  at, at, $190f
8000026C	addu   at, at, v0
80000270	lbu    a1, $0000(at)
80000274	jal    $800d3994
80000278	addiu  a2, sp, $0010
8000027C	lh     v1, $0010(sp)
80000280	lh     v0, $0004(s0)
80000284	nop
80000288	subu   v0, v1, v0
8000028C	bgez   v0, L0298 [$80000298]
80000290	nop
80000294	addiu  v0, v0, $000f

L0298:	; 80000298
80000298	sra    v0, v0, $04
8000029C	sh     v0, $000c(s0)
800002A0	lh     v1, $0012(sp)
800002A4	lh     v0, $0006(s0)
800002A8	nop
800002AC	subu   v0, v1, v0
800002B0	bgez   v0, L02bc [$800002bc]
800002B4	nop
800002B8	addiu  v0, v0, $000f

L02bc:	; 800002BC
800002BC	sra    v0, v0, $04
800002C0	sh     v0, $000e(s0)
800002C4	lh     v1, $0014(sp)
800002C8	lh     v0, $0008(s0)
800002CC	nop
800002D0	subu   v0, v1, v0
800002D4	bgez   v0, L02e0 [$800002e0]
800002D8	nop
800002DC	addiu  v0, v0, $000f

L02e0:	; 800002E0
800002E0	sra    v0, v0, $04
800002E4	sh     v0, $0010(s0)
800002E8	sh     s1, $0016(s0)
800002EC	lw     ra, $0020(sp)
800002F0	lw     s1, $001c(sp)
800002F4	lw     s0, $0018(sp)
800002F8	addiu  sp, sp, $0028
800002FC	jr     ra 
80000300	nop

80000304	lui    v0, $8015
80000308	lh     v0, $169c(v0)
8000030C	lui    v1, $8016
80000310	addiu  v1, v1, $2978
80000314	sll    v0, v0, $05
80000318	addu   a0, v0, v1
8000031C	lh     v0, $0002(a0)
80000320	lui    v1, $801c
80000324	addiu  v1, v1, $8554 (=-$7aac)
80000328	sll    v0, v0, $10
8000032C	addu   v0, v0, v1
80000330	lui    at, $801e
80000334	sw     v0, $8554(at)
80000338	lhu    v0, $0002(a0)
8000033C	lui    v1, $8016
80000340	lh     v1, $2080(v1)
80000344	xori   v0, v0, $0001
80000348	slti   v1, v1, $0002
8000034C	beq    v1, zero, L035c [$8000035c]
80000350	sh     v0, $0002(a0)
80000354	addiu  v0, zero, $ffff (=-$1)
80000358	sh     v0, $0000(a0)

L035c:	; 8000035C
8000035C	jr     ra 
80000360	nop

80000364	addiu  sp, sp, $ffe0 (=-$20)
80000368	sw     s1, $0014(sp)
8000036C	addu   s1, a0, zero
80000370	sw     s0, $0010(sp)
80000374	addu   s0, a1, zero
80000378	lui    a0, $801b
8000037C	addiu  a0, a0, $0410
80000380	addu   a1, zero, zero
80000384	addu   a2, zero, zero
80000388	sw     ra, $0018(sp)
8000038C	jal    $800d2980
80000390	addu   a3, zero, zero
80000394	lui    a0, $801b
80000398	addiu  a0, a0, $0304
8000039C	jal    $800bbeac
800003A0	nop
800003A4	addu   a0, s1, zero
800003A8	addu   a1, s0, zero
800003AC	lui    a3, $801b
800003B0	addiu  a3, a3, $01d8
800003B4	jal    $800d5444
800003B8	ori    a2, zero, $0004
800003BC	sll    v0, s0, $01
800003C0	addu   v0, v0, s0
800003C4	sll    a0, v0, $05
800003C8	subu   a0, a0, v0
800003CC	sll    a0, a0, $03
800003D0	subu   a0, a0, s0
800003D4	sll    a0, a0, $02
800003D8	lui    v0, $8015
800003DC	addiu  v0, v0, $1a4c
800003E0	jal    $800d56a8
800003E4	addu   a0, a0, v0
800003E8	ori    a0, zero, $0020
800003EC	addu   a1, v0, zero
800003F0	jal    $800d55f4
800003F4	ori    a2, zero, $0031
800003F8	lw     ra, $0018(sp)
800003FC	lw     s1, $0014(sp)
80000400	lw     s0, $0010(sp)
80000404	addiu  sp, sp, $0020
80000408	jr     ra 
8000040C	nop
