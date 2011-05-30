
Entry:	; 80000000
80000000	addiu  sp, sp, $ffe8 (=-$18)
80000004	sw     ra, $0010(sp)
80000008	jal    $801b06cc
8000000C	nop
80000010	lw     ra, $0010(sp)
80000014	addiu  sp, sp, $0018
80000018	jr     ra 
8000001C	nop

80000020	addiu  sp, sp, $ffc8 (=-$38)
80000024	lui    v0, $8015
80000028	lh     v0, $169c(v0)
8000002C	lui    v1, $8016
80000030	addiu  v1, v1, $2978
80000034	sw     ra, $0034(sp)
80000038	sw     s0, $0030(sp)
8000003C	sll    v0, v0, $05
80000040	addu   s0, v0, v1
80000044	lh     v1, $0002(s0)
80000048	nop
8000004C	slti   v0, v1, $0008
80000050	beq    v0, zero, L0068 [$80000068]
80000054	ori    v0, zero, $0080
80000058	lui    at, $801c
8000005C	sh     v0, $0e56(at)
80000060	j      $801b009c
80000064	nop

L0068:	; 80000068
80000068	slti   v0, v1, $0010
8000006C	beq    v0, zero, L0090 [$80000090]
80000070	addiu  v1, v1, $fff8 (=-$8)
80000074	sll    v1, v1, $04
80000078	ori    v0, zero, $0080
8000007C	subu   v0, v0, v1
80000080	lui    at, $801c
80000084	sh     v0, $0e56(at)
80000088	j      $801b009c
8000008C	nop

L0090:	; 80000090
80000090	addiu  v0, zero, $ffff (=-$1)
80000094	j      $801b016c
80000098	sh     v0, $0000(s0)
8000009C	lhu    v0, $0016(s0)
800000A0	lui    a1, $801c
800000A4	addiu  a1, a1, $0e2c
800000A8	lui    at, $801c
800000AC	sh     v0, $0e3a(at)
800000B0	sh     v0, $0000(a1)
800000B4	lhu    v0, $0016(s0)
800000B8	nop
800000BC	subu   v0, zero, v0
800000C0	lui    at, $801c
800000C4	sh     v0, $0e36(at)
800000C8	lh     v0, $0004(s0)
800000CC	nop
800000D0	lui    at, $801c
800000D4	sw     v0, $0e40(at)
800000D8	lh     v0, $0006(s0)
800000DC	lui    a0, $8010
800000E0	addiu  a0, a0, $a63c (=-$59c4)
800000E4	lui    at, $801c
800000E8	sw     v0, $0e44(at)
800000EC	lh     v0, $0008(s0)
800000F0	nop
800000F4	lui    at, $801c
800000F8	sw     v0, $0e48(at)
800000FC	jal    $8003a63c
80000100	addiu  a2, sp, $0010
80000104	jal    $8003b48c
80000108	addiu  a0, sp, $0010
8000010C	jal    $8003b51c
80000110	addiu  a0, sp, $0010
80000114	lui    a0, $801c
80000118	addiu  a0, a0, $0e4c
8000011C	ori    a2, zero, $000c
80000120	lui    a1, $8015
80000124	lw     a1, $17c0(a1)
80000128	lui    a3, $801e
8000012C	lw     a3, $0e78(a3)
80000130	jal    $800d29d4
80000134	addiu  a1, a1, $0070
80000138	lui    v1, $8006
8000013C	lbu    v1, $2d98(v1)
80000140	lui    at, $801e
80000144	sw     v0, $0e78(at)
80000148	bne    v1, zero, L016c [$8000016c]
8000014C	nop
80000150	lhu    v0, $0002(s0)
80000154	lhu    v1, $0016(s0)
80000158	lhu    a0, $0018(s0)
8000015C	addiu  v0, v0, $0001
80000160	addu   v1, v1, a0
80000164	sh     v0, $0002(s0)
80000168	sh     v1, $0016(s0)

L016c:	; 8000016C
8000016C	lw     ra, $0034(sp)
80000170	lw     s0, $0030(sp)
80000174	addiu  sp, sp, $0038
80000178	jr     ra 
8000017C	nop

80000180	addiu  sp, sp, $ffe8 (=-$18)
80000184	ori    a1, zero, $2000
80000188	lui    v0, $8015
8000018C	lh     v0, $169c(v0)
80000190	lui    v1, $8016
80000194	addiu  v1, v1, $2978
80000198	sw     ra, $0014(sp)
8000019C	sw     s0, $0010(sp)
800001A0	sll    v0, v0, $05
800001A4	addu   s0, v0, v1
800001A8	lh     a2, $001c(s0)
800001AC	jal    $800d4368
800001B0	addiu  a0, s0, $0004
800001B4	lui    v1, $801c
800001B8	addiu  v1, v1, $0e64
800001BC	addiu  a0, v1, $fff8 (=-$8)
800001C0	ori    a2, zero, $000c
800001C4	lui    a1, $8015
800001C8	lw     a1, $17c0(a1)
800001CC	lhu    v0, $0002(s0)
800001D0	lui    a3, $801e
800001D4	lw     a3, $0e78(a3)
800001D8	addiu  a1, a1, $0070
800001DC	sll    v0, v0, $10
800001E0	sra    v0, v0, $11
800001E4	jal    $800d4d90
800001E8	sh     v0, $0000(v1)
800001EC	lui    v1, $8006
800001F0	lbu    v1, $2d98(v1)
800001F4	lui    at, $801e
800001F8	sw     v0, $0e78(at)
800001FC	bne    v1, zero, L0228 [$80000228]
80000200	ori    v1, zero, $0009
80000204	lhu    v0, $0002(s0)
80000208	nop
8000020C	addiu  v0, v0, $0001
80000210	sh     v0, $0002(s0)
80000214	sll    v0, v0, $10
80000218	sra    v0, v0, $10
8000021C	bne    v0, v1, L0228 [$80000228]
80000220	addiu  v0, zero, $ffff (=-$1)
80000224	sh     v0, $0000(s0)

L0228:	; 80000228
80000228	lw     ra, $0014(sp)
8000022C	lw     s0, $0010(sp)
80000230	addiu  sp, sp, $0018
80000234	jr     ra 
80000238	nop

8000023C	addiu  sp, sp, $ffe0 (=-$20)
80000240	ori    a1, zero, $2000
80000244	lui    v0, $8015
80000248	lh     v0, $169c(v0)
8000024C	lui    v1, $8016
80000250	addiu  v1, v1, $2978
80000254	sw     ra, $0018(sp)
80000258	sw     s1, $0014(sp)
8000025C	sw     s0, $0010(sp)
80000260	sll    v0, v0, $05
80000264	addu   s1, v0, v1
80000268	lh     a2, $001c(s1)
8000026C	jal    $800d4368
80000270	addiu  a0, s1, $0004
80000274	lhu    v1, $001a(s1)
80000278	nop
8000027C	andi   v1, v1, $0001
80000280	beq    v1, zero, L0298 [$80000298]
80000284	addu   s0, v0, zero
80000288	lhu    v0, $0000(s0)
8000028C	nop
80000290	subu   v0, zero, v0
80000294	sh     v0, $0000(s0)

L0298:	; 80000298
80000298	lhu    v0, $001a(s1)
8000029C	nop
800002A0	andi   v0, v0, $0002
800002A4	beq    v0, zero, L02bc [$800002bc]
800002A8	nop
800002AC	lhu    v0, $0008(s0)
800002B0	nop
800002B4	subu   v0, zero, v0
800002B8	sh     v0, $0008(s0)

L02bc:	; 800002BC
800002BC	jal    $8003b48c
800002C0	addu   a0, s0, zero
800002C4	jal    $8003b51c
800002C8	addu   a0, s0, zero
800002CC	lui    v1, $801c
800002D0	addiu  v1, v1, $0e70
800002D4	addiu  a0, v1, $fff8 (=-$8)
800002D8	ori    a2, zero, $000c
800002DC	lhu    v0, $0002(s1)
800002E0	lui    a1, $8015
800002E4	lw     a1, $17c0(a1)
800002E8	lui    a3, $801e
800002EC	lw     a3, $0e78(a3)
800002F0	addiu  a1, a1, $0070
800002F4	jal    $800d4d90
800002F8	sh     v0, $0000(v1)
800002FC	lui    v1, $8006
80000300	lbu    v1, $2d98(v1)
80000304	lui    at, $801e
80000308	sw     v0, $0e78(at)
8000030C	bne    v1, zero, L0338 [$80000338]
80000310	ori    v1, zero, $0008
80000314	lhu    v0, $0002(s1)
80000318	nop
8000031C	addiu  v0, v0, $0001
80000320	sh     v0, $0002(s1)
80000324	sll    v0, v0, $10
80000328	sra    v0, v0, $10
8000032C	bne    v0, v1, L0338 [$80000338]
80000330	addiu  v0, zero, $ffff (=-$1)
80000334	sh     v0, $0000(s1)

L0338:	; 80000338
80000338	lw     ra, $0018(sp)
8000033C	lw     s1, $0014(sp)
80000340	lw     s0, $0010(sp)
80000344	addiu  sp, sp, $0020
80000348	jr     ra 
8000034C	nop

80000350	lui    v0, $8015
80000354	lh     v0, $169c(v0)
80000358	lui    v1, $8006
8000035C	lbu    v1, $2d98(v1)
80000360	addiu  sp, sp, $ffe0 (=-$20)
80000364	sw     s0, $0010(sp)
80000368	lui    s0, $8016
8000036C	addiu  s0, s0, $2978
80000370	sw     ra, $001c(sp)
80000374	sw     s2, $0018(sp)
80000378	sw     s1, $0014(sp)
8000037C	sll    v0, v0, $05
80000380	bne    v1, zero, L0588 [$80000588]
80000384	addu   s2, v0, s0
80000388	lh     v0, $0002(s2)
8000038C	nop
80000390	bne    v0, zero, L0460 [$80000460]
80000394	slti   v0, v0, $0002
80000398	lui    a0, $801b
8000039C	addiu  a0, a0, $0180
800003A0	jal    $800bbeac
800003A4	nop
800003A8	sll    v0, v0, $05
800003AC	addu   s1, v0, s0
800003B0	lwl    v0, $0007(s2)
800003B4	lwr    v0, $0004(s2)
800003B8	lwl    v1, $000b(s2)
800003BC	lwr    v1, $0008(s2)
800003C0	swl    v0, $0007(s1)
800003C4	swr    v0, $0004(s1)
800003C8	swl    v1, $000b(s1)
800003CC	swr    v1, $0008(s1)
800003D0	sh     zero, $0006(s1)
800003D4	lhu    v0, $001c(s2)
800003D8	nop
800003DC	sh     v0, $001c(s1)
800003E0	lh     a0, $0014(s2)
800003E4	jal    $800d5774
800003E8	nop
800003EC	lh     v0, $0002(s2)
800003F0	nop
800003F4	bne    v0, zero, L0460 [$80000460]
800003F8	slti   v0, v0, $0002
800003FC	lui    a0, $801b
80000400	addiu  a0, a0, $0020
80000404	jal    $800bbeac
80000408	nop
8000040C	sll    v0, v0, $05
80000410	addu   s1, v0, s0
80000414	lwl    v0, $0007(s2)
80000418	lwr    v0, $0004(s2)
8000041C	lwl    v1, $000b(s2)
80000420	lwr    v1, $0008(s2)
80000424	swl    v0, $0007(s1)
80000428	swr    v0, $0004(s1)
8000042C	swl    v1, $000b(s1)
80000430	swr    v1, $0008(s1)
80000434	ori    v0, zero, $1000
80000438	sh     v0, $0016(s1)
8000043C	ori    v0, zero, $0200
80000440	sh     zero, $0006(s1)
80000444	sh     v0, $0018(s1)
80000448	lhu    v0, $001c(s2)
8000044C	nop
80000450	sh     v0, $001c(s1)
80000454	lh     v0, $0002(s2)
80000458	nop
8000045C	slti   v0, v0, $0002

L0460:	; 80000460
80000460	bne    v0, zero, L0564 [$80000564]
80000464	nop
80000468	lui    a0, $801b
8000046C	addiu  a0, a0, $023c
80000470	jal    $800bbeac
80000474	lui    s0, $1062
80000478	sll    v0, v0, $05
8000047C	lui    v1, $8016
80000480	addiu  v1, v1, $2978
80000484	jal    $80042da8
80000488	addu   s1, v0, v1
8000048C	ori    s0, s0, $4dd3
80000490	mult   v0, s0
80000494	sra    v1, v0, $1f
80000498	mfhi   a0
8000049C	sra    a0, a0, $06
800004A0	subu   a0, a0, v1
800004A4	sll    v1, a0, $05
800004A8	subu   v1, v1, a0
800004AC	sll    v1, v1, $02
800004B0	addu   v1, v1, a0
800004B4	sll    v1, v1, $03
800004B8	lhu    a0, $0004(s2)
800004BC	subu   v0, v0, v1
800004C0	addu   a0, a0, v0
800004C4	addiu  a0, a0, $fe0c (=-$1f4)
800004C8	jal    $80042da8
800004CC	sh     a0, $0004(s1)
800004D0	mult   v0, s0
800004D4	sra    v1, v0, $1f
800004D8	mfhi   a0
800004DC	sra    a0, a0, $06
800004E0	subu   a0, a0, v1
800004E4	sll    v1, a0, $05
800004E8	subu   v1, v1, a0
800004EC	sll    v1, v1, $02
800004F0	addu   v1, v1, a0
800004F4	sll    v1, v1, $03
800004F8	lhu    a0, $0006(s2)
800004FC	subu   v0, v0, v1
80000500	addu   a0, a0, v0
80000504	addiu  a0, a0, $fe0c (=-$1f4)
80000508	jal    $80042da8
8000050C	sh     a0, $0006(s1)
80000510	mult   v0, s0
80000514	sra    v1, v0, $1f
80000518	mfhi   a0
8000051C	sra    a0, a0, $06
80000520	subu   a0, a0, v1
80000524	sll    v1, a0, $05
80000528	subu   v1, v1, a0
8000052C	sll    v1, v1, $02
80000530	addu   v1, v1, a0
80000534	sll    v1, v1, $03
80000538	lhu    a0, $0008(s2)
8000053C	subu   v0, v0, v1
80000540	addu   a0, a0, v0
80000544	addiu  a0, a0, $fe0c (=-$1f4)
80000548	jal    $80042da8
8000054C	sh     a0, $0008(s1)
80000550	andi   v0, v0, $0003
80000554	sh     v0, $001a(s1)
80000558	lhu    v0, $001c(s2)
8000055C	nop
80000560	sh     v0, $001c(s1)

L0564:	; 80000564
80000564	lhu    v0, $0002(s2)
80000568	ori    v1, zero, $0010
8000056C	addiu  v0, v0, $0001
80000570	sh     v0, $0002(s2)
80000574	sll    v0, v0, $10
80000578	sra    v0, v0, $10
8000057C	bne    v0, v1, L0588 [$80000588]
80000580	addiu  v0, zero, $ffff (=-$1)
80000584	sh     v0, $0000(s2)

L0588:	; 80000588
80000588	lw     ra, $001c(sp)
8000058C	lw     s2, $0018(sp)
80000590	lw     s1, $0014(sp)
80000594	lw     s0, $0010(sp)
80000598	addiu  sp, sp, $0020
8000059C	jr     ra 
800005A0	nop

800005A4	addiu  sp, sp, $ffd8 (=-$28)
800005A8	sw     s2, $0018(sp)
800005AC	addu   s2, a0, zero
800005B0	lui    a0, $801b
800005B4	addiu  a0, a0, $0350
800005B8	sw     ra, $0020(sp)
800005BC	sw     s3, $001c(sp)
800005C0	sw     s1, $0014(sp)
800005C4	jal    $800bbeac
800005C8	sw     s0, $0010(sp)
800005CC	addu   a0, s2, zero
800005D0	sll    v1, s2, $01
800005D4	addu   v1, v1, s2
800005D8	sll    s0, v1, $05
800005DC	subu   s0, s0, v1
800005E0	sll    s0, s0, $03
800005E4	subu   s0, s0, s2
800005E8	sll    s0, s0, $02
800005EC	sll    s1, v0, $05
800005F0	lui    v0, $8016
800005F4	addiu  v0, v0, $2978
800005F8	addu   s1, s1, v0
800005FC	addiu  s3, s1, $0004
80000600	lui    at, $8015
80000604	addiu  at, at, $190f
80000608	addu   at, at, s0
8000060C	lbu    a1, $0000(at)
80000610	jal    $800d3994
80000614	addu   a2, s3, zero
80000618	sh     s2, $0014(s1)
8000061C	lui    at, $8015
80000620	addiu  at, at, $18f6
80000624	addu   at, at, s0
80000628	lhu    v0, $0000(at)
8000062C	addu   a0, s3, zero
80000630	subu   v0, zero, v0
80000634	jal    $800d56a8
80000638	sh     v0, $001c(s1)
8000063C	ori    a0, zero, $0020
80000640	addu   a1, v0, zero
80000644	jal    $800d55f4
80000648	ori    a2, zero, $000b
8000064C	lw     ra, $0020(sp)
80000650	lw     s3, $001c(sp)
80000654	lw     s2, $0018(sp)
80000658	lw     s1, $0014(sp)
8000065C	lw     s0, $0010(sp)
80000660	addiu  sp, sp, $0028
80000664	jr     ra 
80000668	nop

8000066C	lui    v0, $8015
80000670	lh     v0, $169c(v0)
80000674	lui    v1, $8016
80000678	addiu  v1, v1, $2978
8000067C	sll    v0, v0, $05
80000680	addu   a0, v0, v1
80000684	lh     v0, $0002(a0)
80000688	lui    v1, $801c
8000068C	addiu  v1, v1, $0e78
80000690	sll    v0, v0, $10
80000694	addu   v0, v0, v1
80000698	lui    at, $801e
8000069C	sw     v0, $0e78(at)
800006A0	lhu    v0, $0002(a0)
800006A4	lui    v1, $8016
800006A8	lh     v1, $2080(v1)
800006AC	xori   v0, v0, $0001
800006B0	slti   v1, v1, $0002
800006B4	beq    v1, zero, L06c4 [$800006c4]
800006B8	sh     v0, $0002(a0)
800006BC	addiu  v0, zero, $ffff (=-$1)
800006C0	sh     v0, $0000(a0)

L06c4:	; 800006C4
800006C4	jr     ra 
800006C8	nop

800006CC	addiu  sp, sp, $ffe0 (=-$20)
800006D0	sw     s0, $0010(sp)
800006D4	addu   s0, a0, zero
800006D8	sw     s1, $0014(sp)
800006DC	addu   s1, a1, zero
800006E0	lui    a0, $801b
800006E4	addiu  a0, a0, $0dac
800006E8	addu   a1, zero, zero
800006EC	addu   a2, zero, zero
800006F0	sw     ra, $0018(sp)
800006F4	jal    $800d2980
800006F8	addu   a3, zero, zero
800006FC	lui    a0, $801b
80000700	addiu  a0, a0, $066c
80000704	jal    $800bbeac
80000708	nop
8000070C	addu   a0, s0, zero
80000710	addu   a1, s1, zero
80000714	lui    a3, $801b
80000718	addiu  a3, a3, $05a4
8000071C	jal    $800d5444
80000720	ori    a2, zero, $0002
80000724	lw     ra, $0018(sp)
80000728	lw     s1, $0014(sp)
8000072C	lw     s0, $0010(sp)
80000730	addiu  sp, sp, $0020
80000734	jr     ra 
80000738	nop
