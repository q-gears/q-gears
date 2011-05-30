
Entry:	; 80000000
80000000	addiu  sp, sp, $ffb0 (=-$50)
80000004	lui    v0, $8015
80000008	lh     v0, $169c(v0)
8000000C	lui    v1, $8016
80000010	addiu  v1, v1, $2978
80000014	sw     ra, $0048(sp)
80000018	sw     s1, $0044(sp)
8000001C	sw     s0, $0040(sp)
80000020	sll    v0, v0, $05
80000024	addu   s0, v0, v1
80000028	lh     v1, $0018(s0)
8000002C	lh     a0, $0002(s0)
80000030	sll    v0, v1, $03
80000034	subu   v0, v0, v1
80000038	sll    v0, v0, $03
8000003C	subu   v0, v0, v1
80000040	sll    v0, v0, $02
80000044	subu   v0, v0, v1
80000048	sll    v0, v0, $02
8000004C	addu   v0, v0, v1
80000050	mult   a0, v0
80000054	mflo   v0
80000058	sra    v1, v0, $0c
8000005C	ori    v0, zero, $7fff
80000060	slt    v0, v0, v1
80000064	beq    v0, zero, L0070 [$80000070]
80000068	nop
8000006C	ori    v1, zero, $7fff

L0070:	; 80000070
80000070	sw     v1, $0038(sp)
80000074	sw     v1, $0034(sp)
80000078	sw     v1, $0030(sp)
8000007C	lh     v1, $0002(s0)
80000080	nop
80000084	bgez   v1, L0094 [$80000094]
80000088	sll    v0, v1, $03
8000008C	j      $801b00a4
80000090	addu   s1, zero, zero

L0094:	; 80000094
80000094	addu   v0, v0, v1
80000098	sll    v0, v0, $03
8000009C	addu   v0, v0, v1
800000A0	sll    s1, v0, $02
800000A4	addiu  a0, s0, $0008
800000A8	jal    $8003c21c
800000AC	addiu  a1, sp, $0010
800000B0	addiu  a0, sp, $0010
800000B4	jal    $8003b35c
800000B8	addiu  a1, sp, $0030
800000BC	lh     v0, $0010(s0)
800000C0	lui    a0, $8010
800000C4	addiu  a0, a0, $a63c (=-$59c4)
800000C8	sw     v0, $0024(sp)
800000CC	lh     v0, $0012(s0)
800000D0	addiu  a1, sp, $0010
800000D4	sw     v0, $0028(sp)
800000D8	lh     v0, $0014(s0)
800000DC	addu   a2, a1, zero
800000E0	jal    $8003a63c
800000E4	sw     v0, $002c(sp)
800000E8	jal    $8003b48c
800000EC	addiu  a0, sp, $0010
800000F0	jal    $8003b51c
800000F4	addiu  a0, sp, $0010
800000F8	addu   a0, zero, zero
800000FC	addu   a1, zero, zero
80000100	jal    $8003b69c
80000104	addu   a2, zero, zero
80000108	lui    v0, $801b
8000010C	addiu  v0, v0, $100e
80000110	addiu  a0, v0, $fff6 (=-$a)
80000114	lui    a1, $8015
80000118	lw     a1, $17c0(a1)
8000011C	lui    a3, $801d
80000120	lw     a3, $1014(a3)
80000124	ori    a2, zero, $000c
80000128	sh     s1, $0000(v0)
8000012C	jal    $800d29d4
80000130	addiu  a1, a1, $0070
80000134	lui    v1, $8006
80000138	lbu    v1, $2d98(v1)
8000013C	lui    at, $801d
80000140	sw     v0, $1014(at)
80000144	bne    v1, zero, L0174 [$80000174]
80000148	nop
8000014C	lhu    v0, $0002(s0)
80000150	nop
80000154	addiu  v0, v0, $0001
80000158	sh     v0, $0002(s0)
8000015C	sll    v0, v0, $10
80000160	sra    v0, v0, $10
80000164	slti   v0, v0, $000f
80000168	bne    v0, zero, L0174 [$80000174]
8000016C	addiu  v0, zero, $ffff (=-$1)
80000170	sh     v0, $0000(s0)

L0174:	; 80000174
80000174	lw     ra, $0048(sp)
80000178	lw     s1, $0044(sp)
8000017C	lw     s0, $0040(sp)
80000180	addiu  sp, sp, $0050
80000184	jr     ra 
80000188	nop

8000018C	lui    v0, $8015
80000190	lh     v0, $169c(v0)
80000194	lui    v1, $8006
80000198	lbu    v1, $2d98(v1)
8000019C	addiu  sp, sp, $ffe0 (=-$20)
800001A0	sw     s2, $0018(sp)
800001A4	lui    s2, $8016
800001A8	addiu  s2, s2, $2978
800001AC	sw     ra, $001c(sp)
800001B0	sw     s1, $0014(sp)
800001B4	sw     s0, $0010(sp)
800001B8	sll    v0, v0, $05
800001BC	bne    v1, zero, L0270 [$80000270]
800001C0	addu   s1, v0, s2
800001C4	lh     v0, $0002(s1)
800001C8	nop
800001CC	bne    v0, zero, L0260 [$80000260]
800001D0	nop
800001D4	lui    a0, $801b
800001D8	addiu  a0, a0, $0000
800001DC	jal    $800bbeac
800001E0	nop
800001E4	sll    s0, v0, $05
800001E8	lh     a0, $0004(s1)
800001EC	addu   s0, s0, s2
800001F0	sll    v1, a0, $01
800001F4	addu   v1, v1, a0
800001F8	sll    v0, v1, $05
800001FC	subu   v0, v0, v1
80000200	sll    v0, v0, $03
80000204	subu   v0, v0, a0
80000208	sll    v0, v0, $02
8000020C	lui    at, $8015
80000210	addiu  at, at, $190f
80000214	addu   at, at, v0
80000218	lbu    a1, $0000(at)
8000021C	jal    $800d3994
80000220	addiu  a2, s0, $0010
80000224	sh     zero, $000c(s0)
80000228	sh     zero, $000a(s0)
8000022C	sh     zero, $0008(s0)
80000230	lh     a0, $0004(s1)
80000234	jal    $800d55a4
80000238	nop
8000023C	sh     v0, $0018(s0)
80000240	lh     a0, $0004(s1)
80000244	jal    $800d5774
80000248	nop
8000024C	lh     v0, $0002(s1)
80000250	nop
80000254	bne    v0, zero, L0260 [$80000260]
80000258	addiu  v0, zero, $ffff (=-$1)
8000025C	sh     v0, $0000(s1)

L0260:	; 80000260
80000260	lhu    v0, $0002(s1)
80000264	nop
80000268	addiu  v0, v0, $0001
8000026C	sh     v0, $0002(s1)

L0270:	; 80000270
80000270	lw     ra, $001c(sp)
80000274	lw     s2, $0018(sp)
80000278	lw     s1, $0014(sp)
8000027C	lw     s0, $0010(sp)
80000280	addiu  sp, sp, $0020
80000284	jr     ra 
80000288	nop

8000028C	addiu  sp, sp, $ffe8 (=-$18)
80000290	sw     s0, $0010(sp)
80000294	addu   s0, a0, zero
80000298	lui    a0, $801b
8000029C	addiu  a0, a0, $018c
800002A0	sw     ra, $0014(sp)
800002A4	jal    $800bbeac
800002A8	nop
800002AC	sll    v0, v0, $05
800002B0	lui    at, $8016
800002B4	addiu  at, at, $297c
800002B8	addu   at, at, v0
800002BC	sh     s0, $0000(at)
800002C0	lw     ra, $0014(sp)
800002C4	lw     s0, $0010(sp)
800002C8	addiu  sp, sp, $0018
800002CC	jr     ra 
800002D0	nop

800002D4	addiu  sp, sp, $ffe8 (=-$18)
800002D8	sw     s0, $0010(sp)
800002DC	addu   s0, a0, zero
800002E0	lui    a0, $801b
800002E4	addiu  a0, a0, $018c
800002E8	sw     ra, $0014(sp)
800002EC	jal    $800bbeac
800002F0	nop
800002F4	sll    v0, v0, $05
800002F8	lui    at, $8016
800002FC	addiu  at, at, $297c
80000300	addu   at, at, v0
80000304	sh     s0, $0000(at)
80000308	lw     ra, $0014(sp)
8000030C	lw     s0, $0010(sp)
80000310	addiu  sp, sp, $0018
80000314	jr     ra 
80000318	nop

8000031C	lui    v0, $8015
80000320	lh     v0, $169c(v0)
80000324	lui    v1, $8016
80000328	addiu  v1, v1, $2978
8000032C	sll    v0, v0, $05
80000330	addu   a0, v0, v1
80000334	lh     v0, $0002(a0)
80000338	lui    v1, $801b
8000033C	addiu  v1, v1, $1014
80000340	sll    v0, v0, $10
80000344	addu   v0, v0, v1
80000348	lui    at, $801d
8000034C	sw     v0, $1014(at)
80000350	lhu    v0, $0002(a0)
80000354	lui    v1, $8016
80000358	lh     v1, $2080(v1)
8000035C	xori   v0, v0, $0001
80000360	slti   v1, v1, $0002
80000364	beq    v1, zero, L0374 [$80000374]
80000368	sh     v0, $0002(a0)
8000036C	addiu  v0, zero, $ffff (=-$1)
80000370	sh     v0, $0000(a0)

L0374:	; 80000374
80000374	jr     ra 
80000378	nop

8000037C	addiu  sp, sp, $ffe0 (=-$20)
80000380	sw     s0, $0010(sp)
80000384	addu   s0, a0, zero
80000388	sw     s1, $0014(sp)
8000038C	lui    a0, $801b
80000390	addiu  a0, a0, $031c
80000394	sw     ra, $0018(sp)
80000398	jal    $800bbeac
8000039C	addu   s1, a1, zero
800003A0	addu   a0, s0, zero
800003A4	addu   a1, s1, zero
800003A8	lui    a3, $801b
800003AC	addiu  a3, a3, $02d4
800003B0	jal    $800d5444
800003B4	ori    a2, zero, $0004
800003B8	lui    a0, $8015
800003BC	lh     a0, $1774(a0)
800003C0	jal    $800d574c
800003C4	nop
800003C8	ori    a0, zero, $0020
800003CC	addu   a1, v0, zero
800003D0	jal    $800d55f4
800003D4	ori    a2, zero, $0018
800003D8	lw     ra, $0018(sp)
800003DC	lw     s1, $0014(sp)
800003E0	lw     s0, $0010(sp)
800003E4	addiu  sp, sp, $0020
800003E8	jr     ra 
800003EC	nop
