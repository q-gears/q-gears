
Entry:	; 80000000
80000000	addiu  sp, sp, $ffe8 (=-$18)
80000004	sw     ra, $0010(sp)
80000008	jal    $801b103c
8000000C	nop
80000010	lui    v0, $801b
80000014	addiu  v0, v0, $10ac
80000018	lw     ra, $0010(sp)
8000001C	addiu  sp, sp, $0018
80000020	jr     ra 
80000024	nop

80000028	addiu  sp, sp, $ff88 (=-$78)
8000002C	lui    v0, $8015
80000030	lh     v0, $169c(v0)
80000034	lui    v1, $8016
80000038	addiu  v1, v1, $2978
8000003C	sw     ra, $0074(sp)
80000040	sw     s6, $0070(sp)
80000044	sw     s5, $006c(sp)
80000048	sw     s4, $0068(sp)
8000004C	sw     s3, $0064(sp)
80000050	sw     s2, $0060(sp)
80000054	sw     s1, $005c(sp)
80000058	sw     s0, $0058(sp)
8000005C	sll    v0, v0, $05
80000060	addu   s5, v0, v1
80000064	lh     s6, $0002(s5)
80000068	nop
8000006C	slti   v0, s6, $0016
80000070	beq    v0, zero, L0200 [$80000200]
80000074	lui    v1, $2e8b
80000078	ori    v1, v1, $a2e9
8000007C	sll    v0, s6, $03
80000080	subu   v0, v0, s6
80000084	sll    v0, v0, $09
80000088	mult   v0, v1
8000008C	sra    v0, v0, $1f
80000090	mfhi   v1
80000094	sra    v1, v1, $02
80000098	subu   v1, v1, v0
8000009C	lui    v0, $8006
800000A0	lbu    v0, $2d98(v0)
800000A4	addiu  v1, v1, $0200
800000A8	sw     v1, $0018(sp)
800000AC	sw     v1, $0014(sp)
800000B0	bne    v0, zero, L00e0 [$800000e0]
800000B4	sw     v1, $0010(sp)
800000B8	lui    a0, $801b
800000BC	addiu  a0, a0, $52e8
800000C0	lui    a1, $801b
800000C4	addiu  a1, a1, $52f0
800000C8	lhu    v0, $0000(a0)
800000CC	lhu    v1, $0000(a1)
800000D0	addiu  v0, v0, $0280
800000D4	addiu  v1, v1, $fe40 (=-$1c0)
800000D8	sh     v0, $0000(a0)
800000DC	sh     v1, $0000(a1)

L00e0:	; 800000E0
800000E0	lui    a0, $801b
800000E4	addiu  a0, a0, $52e4
800000E8	lui    s0, $801b
800000EC	addiu  s0, s0, $52b4
800000F0	jal    $8003c21c
800000F4	addu   a1, s0, zero
800000F8	addu   a0, s0, zero
800000FC	jal    $8003b35c
80000100	addiu  a1, sp, $0010
80000104	addu   a1, s0, zero
80000108	addiu  s1, sp, $0020
8000010C	addu   a2, s1, zero
80000110	lh     a0, $0006(s5)
80000114	lui    s4, $8010
80000118	addiu  s4, s4, $a6e0 (=-$5920)
8000011C	sll    a0, a0, $06
80000120	jal    $8003a63c
80000124	addu   a0, a0, s4
80000128	jal    $8003b48c
8000012C	addu   a0, s1, zero
80000130	jal    $8003b51c
80000134	addu   a0, s1, zero
80000138	lui    s2, $801b
8000013C	addiu  s2, s2, $52d8
80000140	addiu  s3, s2, $fffc (=-$4)
80000144	addu   a0, s3, zero
80000148	lui    a3, $801d
8000014C	lw     a3, $59f8(a3)
80000150	lui    a1, $8015
80000154	lw     a1, $17c0(a1)
80000158	ori    a2, zero, $000c
8000015C	sw     zero, $0000(s2)
80000160	jal    $800d29d4
80000164	addiu  a1, a1, $0070
80000168	lui    a0, $801b
8000016C	addiu  a0, a0, $52ec
80000170	lui    at, $801d
80000174	sw     v0, $59f8(at)
80000178	jal    $8003c21c
8000017C	addu   a1, s0, zero
80000180	addu   a0, s0, zero
80000184	jal    $8003b35c
80000188	addiu  a1, sp, $0010
8000018C	addu   a1, s0, zero
80000190	lh     a0, $0006(s5)
80000194	addu   a2, s1, zero
80000198	sll    a0, a0, $06
8000019C	jal    $8003a63c
800001A0	addu   a0, a0, s4
800001A4	lui    a1, $801b
800001A8	addiu  a1, a1, $52f8
800001AC	jal    $8003b35c
800001B0	addu   a0, s1, zero
800001B4	jal    $8003b48c
800001B8	addu   a0, s1, zero
800001BC	addu   a0, s3, zero
800001C0	ori    a2, zero, $000c
800001C4	lui    a3, $801d
800001C8	lw     a3, $59f8(a3)
800001CC	lui    a1, $8015
800001D0	lw     a1, $17c0(a1)
800001D4	ori    v0, zero, $0008
800001D8	sw     v0, $0000(s2)
800001DC	jal    $800d29d4
800001E0	addiu  a1, a1, $0070
800001E4	lui    at, $801d
800001E8	sw     v0, $59f8(at)
800001EC	ori    v0, zero, $0015
800001F0	bne    s6, v0, L0208 [$80000208]
800001F4	nop
800001F8	jal    $800d5138
800001FC	ori    a0, zero, $0001

L0200:	; 80000200
80000200	addiu  v0, zero, $ffff (=-$1)
80000204	sh     v0, $0000(s5)

L0208:	; 80000208
80000208	lui    v0, $8006
8000020C	lbu    v0, $2d98(v0)
80000210	nop
80000214	bne    v0, zero, L022c [$8000022c]
80000218	nop
8000021C	lhu    v0, $0002(s5)
80000220	nop
80000224	addiu  v0, v0, $0001
80000228	sh     v0, $0002(s5)

L022c:	; 8000022C
8000022C	lw     ra, $0074(sp)
80000230	lw     s6, $0070(sp)
80000234	lw     s5, $006c(sp)
80000238	lw     s4, $0068(sp)
8000023C	lw     s3, $0064(sp)
80000240	lw     s2, $0060(sp)
80000244	lw     s1, $005c(sp)
80000248	lw     s0, $0058(sp)
8000024C	addiu  sp, sp, $0078
80000250	jr     ra 
80000254	nop

80000258	addiu  sp, sp, $ffe8 (=-$18)
8000025C	lui    v0, $8015
80000260	lh     v0, $169c(v0)
80000264	lui    v1, $8016
80000268	addiu  v1, v1, $2978
8000026C	sw     ra, $0014(sp)
80000270	sw     s0, $0010(sp)
80000274	sll    v0, v0, $05
80000278	addu   s0, v0, v1
8000027C	lh     a0, $0002(s0)
80000280	nop
80000284	slti   v0, a0, $0004
80000288	beq    v0, zero, L02c8 [$800002c8]
8000028C	nop
80000290	sll    a0, a0, $05
80000294	lh     v0, $0000(s0)
80000298	lui    v1, $801b
8000029C	addiu  v1, v1, $5308
800002A0	sll    v0, v0, $04
800002A4	addu   v1, v0, v1
800002A8	sb     a0, $000a(v1)
800002AC	sb     a0, $0009(v1)
800002B0	lui    at, $801b
800002B4	addiu  at, at, $5310
800002B8	addu   at, at, v0
800002BC	sb     a0, $0000(at)
800002C0	j      $801b031c
800002C4	addiu  a0, s0, $0008

L02c8:	; 800002C8
800002C8	addiu  a0, a0, $fffc (=-$4)
800002CC	slti   v0, a0, $0004
800002D0	beq    v0, zero, L0310 [$80000310]
800002D4	ori    v0, zero, $0080
800002D8	lui    v1, $801b
800002DC	addiu  v1, v1, $5308
800002E0	lh     a0, $0000(s0)
800002E4	nop
800002E8	sll    a0, a0, $04
800002EC	addu   v1, a0, v1
800002F0	sb     v0, $000a(v1)
800002F4	sb     v0, $0009(v1)
800002F8	lui    at, $801b
800002FC	addiu  at, at, $5310
80000300	addu   at, at, a0
80000304	sb     v0, $0000(at)
80000308	j      $801b031c
8000030C	addiu  a0, s0, $0008

L0310:	; 80000310
80000310	addiu  v0, zero, $ffff (=-$1)
80000314	j      $801b03ac
80000318	sh     v0, $0000(s0)
8000031C	lh     a1, $0018(s0)
80000320	jal    $800d4368
80000324	addu   a2, zero, zero
80000328	ori    a2, zero, $000c
8000032C	lui    v0, $801b
80000330	addiu  v0, v0, $5308
80000334	lh     a0, $0000(s0)
80000338	lui    a1, $8015
8000033C	lw     a1, $17c0(a1)
80000340	lui    a3, $801d
80000344	lw     a3, $59f8(a3)
80000348	sll    a0, a0, $04
8000034C	addu   a0, a0, v0
80000350	jal    $800d6260
80000354	addiu  a1, a1, $0070
80000358	lui    v1, $8006
8000035C	lbu    v1, $2d98(v1)
80000360	lui    at, $801d
80000364	sw     v0, $59f8(at)
80000368	bne    v1, zero, L03ac [$800003ac]
8000036C	nop
80000370	lhu    v0, $0002(s0)
80000374	lhu    v1, $0008(s0)
80000378	lhu    a0, $0010(s0)
8000037C	lhu    a1, $0014(s0)
80000380	addiu  v0, v0, $0001
80000384	addu   v1, v1, a0
80000388	sh     v0, $0002(s0)
8000038C	lhu    v0, $000a(s0)
80000390	lhu    a0, $0012(s0)
80000394	sh     v1, $0008(s0)
80000398	lhu    v1, $000c(s0)
8000039C	addu   v0, v0, a0
800003A0	addu   v1, v1, a1
800003A4	sh     v0, $000a(s0)
800003A8	sh     v1, $000c(s0)

L03ac:	; 800003AC
800003AC	lw     ra, $0014(sp)
800003B0	lw     s0, $0010(sp)
800003B4	addiu  sp, sp, $0018
800003B8	jr     ra 
800003BC	nop

800003C0	addiu  sp, sp, $ffa8 (=-$58)
800003C4	lui    v0, $8015
800003C8	lh     v0, $169c(v0)
800003CC	lui    v1, $8016
800003D0	addiu  v1, v1, $2978
800003D4	sw     ra, $0050(sp)
800003D8	sw     s1, $004c(sp)
800003DC	sw     s0, $0048(sp)
800003E0	sll    v0, v0, $05
800003E4	addu   s1, v0, v1
800003E8	lh     v1, $0002(s1)
800003EC	nop
800003F0	slti   v0, v1, $000e
800003F4	beq    v0, zero, L0438 [$80000438]
800003F8	ori    v0, zero, $0080
800003FC	lui    v1, $801b
80000400	addiu  v1, v1, $5338
80000404	lh     a0, $0000(s1)
80000408	nop
8000040C	sll    a0, a0, $04
80000410	addu   v1, a0, v1
80000414	sb     v0, $000a(v1)
80000418	sb     v0, $0009(v1)
8000041C	lui    at, $801b
80000420	addiu  at, at, $5340
80000424	addu   at, at, a0
80000428	sb     v0, $0000(at)
8000042C	lh     v0, $0000(s1)
80000430	j      $801b0490
80000434	ori    v1, zero, $002c

L0438:	; 80000438
80000438	addiu  v1, v1, $fff2 (=-$e)
8000043C	slti   v0, v1, $0008
80000440	beq    v0, zero, L0660 [$80000660]
80000444	sll    v1, v1, $07
80000448	lh     v0, $0000(s1)
8000044C	subu   v1, zero, v1
80000450	sll    a1, v0, $04
80000454	lui    v0, $801b
80000458	addiu  v0, v0, $5338
8000045C	bgez   v1, L0468 [$80000468]
80000460	addu   a0, a1, v0
80000464	addiu  v1, v1, $0007

L0468:	; 80000468
80000468	sra    v0, v1, $03
8000046C	addiu  v0, v0, $ff80 (=-$80)
80000470	sb     v0, $000a(a0)
80000474	sb     v0, $0009(a0)
80000478	lui    at, $801b
8000047C	addiu  at, at, $5340
80000480	addu   at, at, a1
80000484	sb     v0, $0000(at)
80000488	lh     v0, $0000(s1)
8000048C	ori    v1, zero, $002e
80000490	sll    v0, v0, $04
80000494	lui    at, $801b
80000498	addiu  at, at, $5343
8000049C	addu   at, at, v0
800004A0	sb     v1, $0000(at)
800004A4	addiu  a1, sp, $0010
800004A8	lui    a0, $8015
800004AC	lh     a0, $169c(a0)
800004B0	lui    v0, $801b
800004B4	addiu  v0, v0, $53b8
800004B8	sll    a0, a0, $04
800004BC	jal    $8003c21c
800004C0	addu   a0, a0, v0
800004C4	addiu  a0, sp, $0010
800004C8	lh     v0, $0018(s1)
800004CC	addiu  a1, sp, $0030
800004D0	sw     v0, $0038(sp)
800004D4	sw     v0, $0034(sp)
800004D8	jal    $8003b35c
800004DC	sw     v0, $0030(sp)
800004E0	lui    s0, $8010
800004E4	addiu  s0, s0, $a63c (=-$59c4)
800004E8	jal    $8003b48c
800004EC	addu   a0, s0, zero
800004F0	jal    $8003b51c
800004F4	addu   a0, s0, zero
800004F8	addiu  a0, s1, $0008
800004FC	addiu  a1, sp, $0024
80000500	jal    $8003bc6c
80000504	addiu  a2, sp, $0040
80000508	jal    $8003b48c
8000050C	addiu  a0, sp, $0010
80000510	jal    $8003b51c
80000514	addiu  a0, sp, $0010
80000518	ori    a2, zero, $000c
8000051C	lui    v0, $801b
80000520	addiu  v0, v0, $5338
80000524	lh     a0, $0000(s1)
80000528	lui    a1, $8015
8000052C	lw     a1, $17c0(a1)
80000530	lui    a3, $801d
80000534	lw     a3, $59f8(a3)
80000538	sll    a0, a0, $04
8000053C	addu   a0, a0, v0
80000540	jal    $800d6260
80000544	addiu  a1, a1, $0070
80000548	lui    v1, $8006
8000054C	lbu    v1, $2d98(v1)
80000550	lui    at, $801d
80000554	sw     v0, $59f8(at)
80000558	bne    v1, zero, L0668 [$80000668]
8000055C	nop
80000560	lhu    v0, $0002(s1)
80000564	lhu    v1, $0008(s1)
80000568	lhu    a0, $0010(s1)
8000056C	lhu    a1, $0014(s1)
80000570	addiu  v0, v0, $0001
80000574	addu   v1, v1, a0
80000578	sh     v0, $0002(s1)
8000057C	lhu    v0, $000a(s1)
80000580	lhu    a0, $0012(s1)
80000584	sh     v1, $0008(s1)
80000588	lhu    v1, $000c(s1)
8000058C	addu   v0, v0, a0
80000590	sh     v0, $000a(s1)
80000594	lhu    v0, $0012(s1)
80000598	addu   v1, v1, a1
8000059C	sh     v1, $000c(s1)
800005A0	lui    v1, $8015
800005A4	lh     v1, $169c(v1)
800005A8	addiu  v0, v0, $000a
800005AC	sll    v1, v1, $04
800005B0	sh     v0, $0012(s1)
800005B4	lui    at, $801b
800005B8	addiu  at, at, $53b8
800005BC	addu   at, at, v1
800005C0	lhu    v0, $0000(at)
800005C4	lui    at, $801b
800005C8	addiu  at, at, $53c0
800005CC	addu   at, at, v1
800005D0	lhu    a0, $0000(at)
800005D4	lui    at, $801b
800005D8	addiu  at, at, $53c2
800005DC	addu   at, at, v1
800005E0	lhu    a1, $0000(at)
800005E4	lui    at, $801b
800005E8	addiu  at, at, $53c4
800005EC	addu   at, at, v1
800005F0	lhu    a2, $0000(at)
800005F4	addu   v0, v0, a0
800005F8	lui    at, $801b
800005FC	addiu  at, at, $53b8
80000600	addu   at, at, v1
80000604	sh     v0, $0000(at)
80000608	lui    at, $801b
8000060C	addiu  at, at, $53ba
80000610	addu   at, at, v1
80000614	lhu    v0, $0000(at)
80000618	lui    at, $801b
8000061C	addiu  at, at, $53bc
80000620	addu   at, at, v1
80000624	lhu    a0, $0000(at)
80000628	addu   v0, v0, a1
8000062C	addu   a0, a0, a2
80000630	lui    at, $801b
80000634	addiu  at, at, $53ba
80000638	addu   at, at, v1
8000063C	sh     v0, $0000(at)
80000640	lui    at, $801b
80000644	addiu  at, at, $53bc
80000648	addu   at, at, v1
8000064C	sh     a0, $0000(at)
80000650	lh     v0, $000a(s1)
80000654	nop
80000658	blez   v0, L0668 [$80000668]
8000065C	nop

L0660:	; 80000660
80000660	addiu  v0, zero, $ffff (=-$1)
80000664	sh     v0, $0000(s1)

L0668:	; 80000668
80000668	lw     ra, $0050(sp)
8000066C	lw     s1, $004c(sp)
80000670	lw     s0, $0048(sp)
80000674	addiu  sp, sp, $0058
80000678	jr     ra 
8000067C	nop

80000680	addiu  sp, sp, $ffe8 (=-$18)
80000684	lui    v0, $8015
80000688	lh     v0, $169c(v0)
8000068C	lui    v1, $8016
80000690	addiu  v1, v1, $2978
80000694	sw     ra, $0014(sp)
80000698	sw     s0, $0010(sp)
8000069C	sll    v0, v0, $05
800006A0	addu   s0, v0, v1
800006A4	lh     v1, $0002(s0)
800006A8	nop
800006AC	slti   v0, v1, $000e
800006B0	beq    v0, zero, L06f0 [$800006f0]
800006B4	ori    v0, zero, $0080
800006B8	lui    v1, $801b
800006BC	addiu  v1, v1, $5368
800006C0	lh     a0, $0000(s0)
800006C4	nop
800006C8	sll    a0, a0, $04
800006CC	addu   v1, a0, v1
800006D0	sb     v0, $000a(v1)
800006D4	sb     v0, $0009(v1)
800006D8	lui    at, $801b
800006DC	addiu  at, at, $5370
800006E0	addu   at, at, a0
800006E4	sb     v0, $0000(at)
800006E8	j      $801b0744
800006EC	addiu  a0, s0, $0008

L06f0:	; 800006F0
800006F0	addiu  v1, v1, $fff2 (=-$e)
800006F4	slti   v0, v1, $0008
800006F8	beq    v0, zero, L07dc [$800007dc]
800006FC	sll    v1, v1, $07
80000700	lh     v0, $0000(s0)
80000704	subu   v1, zero, v1
80000708	sll    a1, v0, $04
8000070C	lui    v0, $801b
80000710	addiu  v0, v0, $5368
80000714	bgez   v1, L0720 [$80000720]
80000718	addu   a0, a1, v0
8000071C	addiu  v1, v1, $0007

L0720:	; 80000720
80000720	sra    v0, v1, $03
80000724	addiu  v0, v0, $ff80 (=-$80)
80000728	sb     v0, $000a(a0)
8000072C	sb     v0, $0009(a0)
80000730	lui    at, $801b
80000734	addiu  at, at, $5370
80000738	addu   at, at, a1
8000073C	sb     v0, $0000(at)
80000740	addiu  a0, s0, $0008
80000744	lh     a1, $0018(s0)
80000748	jal    $800d4368
8000074C	addu   a2, zero, zero
80000750	ori    a2, zero, $000c
80000754	lui    v0, $801b
80000758	addiu  v0, v0, $5368
8000075C	lh     a0, $0000(s0)
80000760	lui    a1, $8015
80000764	lw     a1, $17c0(a1)
80000768	lui    a3, $801d
8000076C	lw     a3, $59f8(a3)
80000770	sll    a0, a0, $04
80000774	addu   a0, a0, v0
80000778	jal    $800d6260
8000077C	addiu  a1, a1, $0070
80000780	lui    v1, $8006
80000784	lbu    v1, $2d98(v1)
80000788	lui    at, $801d
8000078C	sw     v0, $59f8(at)
80000790	bne    v1, zero, L07e4 [$800007e4]
80000794	nop
80000798	lhu    v0, $0002(s0)
8000079C	lhu    a0, $0010(s0)
800007A0	lhu    v1, $000a(s0)
800007A4	lhu    a1, $0012(s0)
800007A8	addiu  v0, v0, $0001
800007AC	sh     v0, $0002(s0)
800007B0	lhu    v0, $0008(s0)
800007B4	addu   v1, v1, a1
800007B8	sh     v1, $000a(s0)
800007BC	lhu    v1, $0014(s0)
800007C0	addu   v0, v0, a0
800007C4	sh     v0, $0008(s0)
800007C8	lhu    v0, $000c(s0)
800007CC	lh     a0, $000a(s0)
800007D0	addu   v0, v0, v1
800007D4	blez   a0, L07e4 [$800007e4]
800007D8	sh     v0, $000c(s0)

L07dc:	; 800007DC
800007DC	addiu  v0, zero, $ffff (=-$1)
800007E0	sh     v0, $0000(s0)

L07e4:	; 800007E4
800007E4	lw     ra, $0014(sp)
800007E8	lw     s0, $0010(sp)
800007EC	addiu  sp, sp, $0018
800007F0	jr     ra 
800007F4	nop

800007F8	lui    v0, $8015
800007FC	lh     v0, $169c(v0)
80000800	lui    v1, $8006
80000804	lbu    v1, $2d98(v1)
80000808	addiu  sp, sp, $ff68 (=-$98)
8000080C	sw     s1, $007c(sp)
80000810	lui    s1, $8016
80000814	addiu  s1, s1, $2978
80000818	sw     ra, $0090(sp)
8000081C	sw     s5, $008c(sp)
80000820	sw     s4, $0088(sp)
80000824	sw     s3, $0084(sp)
80000828	sw     s2, $0080(sp)
8000082C	sw     s0, $0078(sp)
80000830	sll    v0, v0, $05
80000834	bne    v1, zero, L0f60 [$80000f60]
80000838	addu   s3, v0, s1
8000083C	lh     s0, $0002(s3)
80000840	nop
80000844	bltz   s0, L0f50 [$80000f50]
80000848	slti   v0, s0, $0016
8000084C	beq    v0, zero, L0ab4 [$80000ab4]
80000850	nop
80000854	bne    s0, zero, L08d0 [$800008d0]
80000858	slti   v0, s0, $000e
8000085C	lui    a0, $801b
80000860	addiu  a0, a0, $0028
80000864	jal    $800bbeac
80000868	nop
8000086C	sll    v0, v0, $05
80000870	lhu    v1, $0004(s3)
80000874	addu   s1, v0, s1
80000878	sh     v1, $0004(s1)
8000087C	lhu    v0, $0006(s3)
80000880	nop
80000884	sh     v0, $0006(s1)
80000888	lh     v1, $0006(s3)
8000088C	nop
80000890	sll    v0, v1, $01
80000894	addu   v0, v0, v1
80000898	sll    a0, v0, $05
8000089C	subu   a0, a0, v0
800008A0	sll    a0, a0, $03
800008A4	subu   a0, a0, v1
800008A8	sll    a0, a0, $02
800008AC	lui    v0, $8015
800008B0	addiu  v0, v0, $1a4c
800008B4	jal    $800d56a8
800008B8	addu   a0, a0, v0
800008BC	ori    a0, zero, $0020
800008C0	addu   a1, v0, zero
800008C4	jal    $800d55f4
800008C8	ori    a2, zero, $0028
800008CC	slti   v0, s0, $000e

L08d0:	; 800008D0
800008D0	beq    v0, zero, L0f50 [$80000f50]
800008D4	addiu  a2, sp, $0040
800008D8	lui    a0, $8010
800008DC	addiu  a0, a0, $a63c (=-$59c4)
800008E0	addu   s2, zero, zero
800008E4	lh     a1, $0006(s3)
800008E8	addiu  s0, sp, $0020
800008EC	lui    v0, $8010
800008F0	addiu  v0, v0, $a6e0 (=-$5920)
800008F4	sll    a1, a1, $06
800008F8	jal    $800d41fc
800008FC	addu   a1, a1, v0
80000900	lui    a0, $801b
80000904	addiu  a0, a0, $0258
80000908	jal    $800bbeac
8000090C	nop
80000910	sll    v0, v0, $05
80000914	lui    v1, $8016
80000918	addiu  v1, v1, $2978
8000091C	addu   s1, v0, v1
80000920	sh     zero, $001a(sp)
80000924	jal    $80042da8
80000928	sh     zero, $0018(sp)
8000092C	lui    v1, $1062
80000930	ori    v1, v1, $4dd3
80000934	mult   v0, v1
80000938	sra    v1, v0, $1f
8000093C	mfhi   a0
80000940	sra    a0, a0, $06
80000944	subu   a0, a0, v1
80000948	sll    v1, a0, $05
8000094C	subu   v1, v1, a0
80000950	sll    v1, v1, $02
80000954	addu   v1, v1, a0
80000958	sll    v1, v1, $03
8000095C	subu   v0, v0, v1
80000960	addiu  v0, v0, $03e8
80000964	subu   v0, zero, v0
80000968	jal    $80042da8
8000096C	sh     v0, $001c(sp)
80000970	andi   v0, v0, $03ff
80000974	addiu  v0, v0, $fe00 (=-$200)
80000978	jal    $80042da8
8000097C	sh     v0, $0010(sp)
80000980	addiu  a0, sp, $0010
80000984	addu   a1, s0, zero
80000988	andi   v0, v0, $03ff
8000098C	addiu  v0, v0, $fe00 (=-$200)
80000990	sh     v0, $0012(sp)
80000994	jal    $8003c21c
80000998	sh     zero, $0014(sp)
8000099C	addiu  a0, sp, $0040
800009A0	addu   a1, s0, zero
800009A4	addu   a2, s0, zero
800009A8	addiu  v0, zero, $ff4c (=-$b4)
800009AC	sw     v0, $003c(sp)
800009B0	sw     v0, $0038(sp)
800009B4	jal    $8003a63c
800009B8	sw     v0, $0034(sp)
800009BC	jal    $8003b48c
800009C0	addu   a0, s0, zero
800009C4	jal    $8003b51c
800009C8	addu   a0, s0, zero
800009CC	addiu  a0, sp, $0018
800009D0	addiu  a1, sp, $0060
800009D4	jal    $8003bc6c
800009D8	addiu  a2, sp, $0070
800009DC	lhu    v0, $0060(sp)
800009E0	nop
800009E4	sh     v0, $0008(s1)
800009E8	lhu    v0, $0064(sp)
800009EC	nop
800009F0	sh     v0, $000a(s1)
800009F4	lhu    v0, $0068(sp)
800009F8	nop
800009FC	sh     v0, $000c(s1)
80000A00	lw     v1, $0034(sp)
80000A04	lw     v0, $0060(sp)
80000A08	nop
80000A0C	subu   v0, v1, v0
80000A10	bgez   v0, L0a1c [$80000a1c]
80000A14	nop
80000A18	addiu  v0, v0, $0007

L0a1c:	; 80000A1C
80000A1C	sra    v0, v0, $03
80000A20	sh     v0, $0010(s1)
80000A24	lw     v1, $0038(sp)
80000A28	lw     v0, $0064(sp)
80000A2C	nop
80000A30	subu   v0, v1, v0
80000A34	bgez   v0, L0a40 [$80000a40]
80000A38	nop
80000A3C	addiu  v0, v0, $0007

L0a40:	; 80000A40
80000A40	sra    v0, v0, $03
80000A44	sh     v0, $0012(s1)
80000A48	lw     v1, $003c(sp)
80000A4C	lw     v0, $0068(sp)
80000A50	nop
80000A54	subu   v0, v1, v0
80000A58	bgez   v0, L0a64 [$80000a64]
80000A5C	addiu  s2, s2, $0001
80000A60	addiu  v0, v0, $0007

L0a64:	; 80000A64
80000A64	sra    v0, v0, $03
80000A68	jal    $80042da8
80000A6C	sh     v0, $0014(s1)
80000A70	lui    v1, $5555
80000A74	ori    v1, v1, $5556
80000A78	mult   v0, v1
80000A7C	ori    v1, zero, $1000
80000A80	sh     v1, $0018(s1)
80000A84	sra    v1, v0, $1f
80000A88	mfhi   a0
80000A8C	subu   a0, a0, v1
80000A90	sll    v1, a0, $01
80000A94	addu   v1, v1, a0
80000A98	subu   v0, v0, v1
80000A9C	sh     v0, $0000(s1)
80000AA0	slti   v0, s2, $0002
80000AA4	beq    v0, zero, L0f50 [$80000f50]
80000AA8	nop
80000AAC	j      $801b0900
80000AB0	nop

L0ab4:	; 80000AB4
80000AB4	addiu  s0, s0, $ffea (=-$16)
80000AB8	slti   v0, s0, $0007
80000ABC	beq    v0, zero, L0f3c [$80000f3c]
80000AC0	nop
80000AC4	bne    s0, zero, L0f50 [$80000f50]
80000AC8	nop
80000ACC	jal    $800d51d4
80000AD0	ori    a0, zero, $0002
80000AD4	lh     a0, $0004(s3)
80000AD8	addu   s2, zero, zero
80000ADC	addiu  s5, sp, $0020
80000AE0	lui    s4, $1b4e
80000AE4	jal    $800d5774
80000AE8	ori    s4, s4, $81b5

L0aec:	; 80000AEC
80000AEC	lui    a0, $801b
80000AF0	addiu  a0, a0, $03c0
80000AF4	jal    $800bbeac
80000AF8	addiu  s2, s2, $0001
80000AFC	addu   s0, v0, zero
80000B00	sll    v1, s0, $05
80000B04	lui    v0, $8016
80000B08	addiu  v0, v0, $2978
80000B0C	lh     a0, $0004(s3)
80000B10	addu   s1, v1, v0
80000B14	sll    v1, a0, $01
80000B18	addu   v1, v1, a0
80000B1C	sll    v0, v1, $05
80000B20	subu   v0, v0, v1
80000B24	sll    v0, v0, $03
80000B28	subu   v0, v0, a0
80000B2C	sll    v0, v0, $02
80000B30	lui    at, $8015
80000B34	addiu  at, at, $190f
80000B38	addu   at, at, v0
80000B3C	lbu    a1, $0000(at)
80000B40	jal    $800d3994
80000B44	addiu  a2, s1, $0008
80000B48	sh     zero, $001a(sp)
80000B4C	jal    $80042da8
80000B50	sh     zero, $0018(sp)
80000B54	lui    v1, $51eb
80000B58	ori    v1, v1, $851f
80000B5C	mult   v0, v1
80000B60	sra    v1, v0, $1f
80000B64	mfhi   a0
80000B68	sra    a0, a0, $06
80000B6C	subu   a0, a0, v1
80000B70	sll    v1, a0, $01
80000B74	addu   v1, v1, a0
80000B78	sll    v1, v1, $03
80000B7C	addu   v1, v1, a0
80000B80	sll    v1, v1, $03
80000B84	subu   v0, v0, v1
80000B88	addiu  v1, zero, $ff9c (=-$64)
80000B8C	subu   v1, v1, v0
80000B90	jal    $80042da8
80000B94	sh     v1, $001c(sp)
80000B98	andi   v0, v0, $07ff
80000B9C	addiu  v0, v0, $fc00 (=-$400)
80000BA0	jal    $80042da8
80000BA4	sh     v0, $0010(sp)
80000BA8	addiu  a0, sp, $0010
80000BAC	lh     a2, $0006(s3)
80000BB0	andi   v0, v0, $07ff
80000BB4	sll    a1, a2, $01
80000BB8	addu   a1, a1, a2
80000BBC	sll    v1, a1, $05
80000BC0	subu   v1, v1, a1
80000BC4	sll    v1, v1, $03
80000BC8	subu   v1, v1, a2
80000BCC	sll    v1, v1, $02
80000BD0	lui    at, $8015
80000BD4	addiu  at, at, $1a46
80000BD8	addu   at, at, v1
80000BDC	lhu    v1, $0000(at)
80000BE0	addu   a1, s5, zero
80000BE4	sh     zero, $0014(sp)
80000BE8	addu   v1, v1, v0
80000BEC	addiu  v1, v1, $0400
80000BF0	jal    $8003c21c
80000BF4	sh     v1, $0012(sp)
80000BF8	addu   a0, s5, zero
80000BFC	addiu  a1, sp, $0018
80000C00	jal    $8003b2cc
80000C04	addiu  a2, s1, $0010
80000C08	jal    $80042da8
80000C0C	sll    s0, s0, $04
80000C10	lui    v1, $2aaa
80000C14	ori    v1, v1, $aaab
80000C18	mult   v0, v1
80000C1C	sra    v1, v0, $1f
80000C20	mfhi   a0
80000C24	sra    a0, a0, $0a
80000C28	subu   a0, a0, v1
80000C2C	sll    v1, a0, $01
80000C30	addu   v1, v1, a0
80000C34	sll    v1, v1, $0b
80000C38	subu   v0, v0, v1
80000C3C	addiu  v0, v0, $0800
80000C40	jal    $80042da8
80000C44	sh     v0, $0018(s1)
80000C48	lui    v1, $5555
80000C4C	ori    v1, v1, $5556
80000C50	mult   v0, v1
80000C54	sra    v1, v0, $1f
80000C58	mfhi   a0
80000C5C	subu   a0, a0, v1
80000C60	sll    v1, a0, $01
80000C64	addu   v1, v1, a0
80000C68	subu   v0, v0, v1
80000C6C	jal    $80042da8
80000C70	sh     v0, $0000(s1)
80000C74	andi   v0, v0, $0fff
80000C78	lui    at, $801b
80000C7C	addiu  at, at, $53b8
80000C80	addu   at, at, s0
80000C84	sh     v0, $0000(at)
80000C88	jal    $80042da8
80000C8C	nop
80000C90	andi   v0, v0, $0fff
80000C94	lui    at, $801b
80000C98	addiu  at, at, $53ba
80000C9C	addu   at, at, s0
80000CA0	sh     v0, $0000(at)
80000CA4	jal    $80042da8
80000CA8	nop
80000CAC	andi   v0, v0, $0fff
80000CB0	lui    at, $801b
80000CB4	addiu  at, at, $53bc
80000CB8	addu   at, at, s0
80000CBC	sh     v0, $0000(at)
80000CC0	jal    $80042da8
80000CC4	nop
80000CC8	mult   v0, s4
80000CCC	sra    a0, v0, $1f
80000CD0	mfhi   v1
80000CD4	sra    v1, v1, $04
80000CD8	subu   v1, v1, a0
80000CDC	sll    a0, v1, $02
80000CE0	addu   a0, a0, v1
80000CE4	sll    v1, a0, $04
80000CE8	subu   v1, v1, a0
80000CEC	sll    v1, v1, $01
80000CF0	subu   v0, v0, v1
80000CF4	addiu  v0, v0, $0032
80000CF8	lui    at, $801b
80000CFC	addiu  at, at, $53c0
80000D00	addu   at, at, s0
80000D04	sh     v0, $0000(at)
80000D08	jal    $80042da8
80000D0C	nop
80000D10	mult   v0, s4
80000D14	sra    a0, v0, $1f
80000D18	mfhi   v1
80000D1C	sra    v1, v1, $04
80000D20	subu   v1, v1, a0
80000D24	sll    a0, v1, $02
80000D28	addu   a0, a0, v1
80000D2C	sll    v1, a0, $04
80000D30	subu   v1, v1, a0
80000D34	sll    v1, v1, $01
80000D38	subu   v0, v0, v1
80000D3C	addiu  v0, v0, $0032
80000D40	lui    at, $801b
80000D44	addiu  at, at, $53c2
80000D48	addu   at, at, s0
80000D4C	sh     v0, $0000(at)
80000D50	jal    $80042da8
80000D54	nop
80000D58	mult   v0, s4
80000D5C	sra    a0, v0, $1f
80000D60	mfhi   v1
80000D64	sra    v1, v1, $04
80000D68	subu   v1, v1, a0
80000D6C	sll    a0, v1, $02
80000D70	addu   a0, a0, v1
80000D74	sll    v1, a0, $04
80000D78	subu   v1, v1, a0
80000D7C	sll    v1, v1, $01
80000D80	subu   v0, v0, v1
80000D84	addiu  v0, v0, $0032
80000D88	lui    at, $801b
80000D8C	addiu  at, at, $53c4
80000D90	addu   at, at, s0
80000D94	sh     v0, $0000(at)
80000D98	slti   v0, s2, $0032
80000D9C	bne    v0, zero, L0aec [$80000aec]
80000DA0	addu   s0, s5, zero
80000DA4	addu   s2, zero, zero
80000DA8	lui    a0, $801b
80000DAC	addiu  a0, a0, $0680
80000DB0	jal    $800bbeac
80000DB4	addiu  s2, s2, $0001
80000DB8	sll    v0, v0, $05
80000DBC	lui    v1, $8016
80000DC0	addiu  v1, v1, $2978
80000DC4	lh     a0, $0004(s3)
80000DC8	addu   s1, v0, v1
80000DCC	sll    v1, a0, $01
80000DD0	addu   v1, v1, a0
80000DD4	sll    v0, v1, $05
80000DD8	subu   v0, v0, v1
80000DDC	sll    v0, v0, $03
80000DE0	subu   v0, v0, a0
80000DE4	sll    v0, v0, $02
80000DE8	lui    at, $8015
80000DEC	addiu  at, at, $190f
80000DF0	addu   at, at, v0
80000DF4	lbu    a1, $0000(at)
80000DF8	jal    $800d3994
80000DFC	addiu  a2, s1, $0008
80000E00	sh     zero, $001a(sp)
80000E04	jal    $80042da8
80000E08	sh     zero, $0018(sp)
80000E0C	lui    v1, $1b4e
80000E10	ori    v1, v1, $81b5
80000E14	mult   v0, v1
80000E18	sra    a0, v0, $1f
80000E1C	mfhi   v1
80000E20	sra    v1, v1, $05
80000E24	subu   v1, v1, a0
80000E28	sll    a0, v1, $02
80000E2C	addu   a0, a0, v1
80000E30	sll    v1, a0, $04
80000E34	subu   v1, v1, a0
80000E38	sll    v1, v1, $02
80000E3C	subu   v0, v0, v1
80000E40	addiu  v1, zero, $fe0c (=-$1f4)
80000E44	subu   v1, v1, v0
80000E48	jal    $80042da8
80000E4C	sh     v1, $001c(sp)
80000E50	andi   v0, v0, $07ff
80000E54	addiu  v0, v0, $fc00 (=-$400)
80000E58	jal    $80042da8
80000E5C	sh     v0, $0010(sp)
80000E60	addiu  a0, sp, $0010
80000E64	lh     a2, $0006(s3)
80000E68	andi   v0, v0, $07ff
80000E6C	sll    a1, a2, $01
80000E70	addu   a1, a1, a2
80000E74	sll    v1, a1, $05
80000E78	subu   v1, v1, a1
80000E7C	sll    v1, v1, $03
80000E80	subu   v1, v1, a2
80000E84	sll    v1, v1, $02
80000E88	lui    at, $8015
80000E8C	addiu  at, at, $1a46
80000E90	addu   at, at, v1
80000E94	lhu    v1, $0000(at)
80000E98	addu   a1, s0, zero
80000E9C	sh     zero, $0014(sp)
80000EA0	addu   v1, v1, v0
80000EA4	addiu  v1, v1, $0400
80000EA8	jal    $8003c21c
80000EAC	sh     v1, $0012(sp)
80000EB0	addu   a0, s0, zero
80000EB4	addiu  a1, sp, $0018
80000EB8	jal    $8003b2cc
80000EBC	addiu  a2, s1, $0010
80000EC0	jal    $80042da8
80000EC4	nop
80000EC8	lui    v1, $2aaa
80000ECC	ori    v1, v1, $aaab
80000ED0	mult   v0, v1
80000ED4	sra    v1, v0, $1f
80000ED8	mfhi   a0
80000EDC	sra    a0, a0, $0a
80000EE0	subu   a0, a0, v1
80000EE4	sll    v1, a0, $01
80000EE8	addu   v1, v1, a0
80000EEC	sll    v1, v1, $0b
80000EF0	subu   v0, v0, v1
80000EF4	addiu  v0, v0, $0800
80000EF8	jal    $80042da8
80000EFC	sh     v0, $0018(s1)
80000F00	lui    v1, $5555
80000F04	ori    v1, v1, $5556
80000F08	mult   v0, v1
80000F0C	sra    v1, v0, $1f
80000F10	mfhi   a0
80000F14	subu   a0, a0, v1
80000F18	sll    v1, a0, $01
80000F1C	addu   v1, v1, a0
80000F20	subu   v0, v0, v1
80000F24	sh     v0, $0000(s1)
80000F28	slti   v0, s2, $001e
80000F2C	beq    v0, zero, L0f50 [$80000f50]
80000F30	nop
80000F34	j      $801b0da8
80000F38	nop

L0f3c:	; 80000F3C
80000F3C	addiu  s0, s0, $fff9 (=-$7)
80000F40	slti   v0, s0, $000f
80000F44	bne    v0, zero, L0f50 [$80000f50]
80000F48	addiu  v0, zero, $ffff (=-$1)
80000F4C	sh     v0, $0000(s3)

L0f50:	; 80000F50
80000F50	lhu    v0, $0002(s3)
80000F54	nop
80000F58	addiu  v0, v0, $0001
80000F5C	sh     v0, $0002(s3)

L0f60:	; 80000F60
80000F60	lw     ra, $0090(sp)
80000F64	lw     s5, $008c(sp)
80000F68	lw     s4, $0088(sp)
80000F6C	lw     s3, $0084(sp)
80000F70	lw     s2, $0080(sp)
80000F74	lw     s1, $007c(sp)
80000F78	lw     s0, $0078(sp)
80000F7C	addiu  sp, sp, $0098
80000F80	jr     ra 
80000F84	nop

80000F88	addiu  sp, sp, $ffe0 (=-$20)
80000F8C	sw     s0, $0010(sp)
80000F90	addu   s0, a0, zero
80000F94	sw     s1, $0014(sp)
80000F98	lui    a0, $801b
80000F9C	addiu  a0, a0, $07f8
80000FA0	sw     ra, $0018(sp)
80000FA4	jal    $800bbeac
80000FA8	addu   s1, a1, zero
80000FAC	sll    v0, v0, $05
80000FB0	lui    v1, $8016
80000FB4	addiu  v1, v1, $2978
80000FB8	addu   v0, v0, v1
80000FBC	sh     s0, $0004(v0)
80000FC0	sh     s1, $0006(v0)
80000FC4	lw     ra, $0018(sp)
80000FC8	lw     s1, $0014(sp)
80000FCC	lw     s0, $0010(sp)
80000FD0	addiu  sp, sp, $0020
80000FD4	jr     ra 
80000FD8	nop

80000FDC	lui    v0, $8015
80000FE0	lh     v0, $169c(v0)
80000FE4	lui    v1, $8016
80000FE8	addiu  v1, v1, $2978
80000FEC	sll    v0, v0, $05
80000FF0	addu   a0, v0, v1
80000FF4	lh     v0, $0002(a0)
80000FF8	lui    v1, $801b
80000FFC	addiu  v1, v1, $59f8
80001000	sll    v0, v0, $10
80001004	addu   v0, v0, v1
80001008	lui    at, $801d
8000100C	sw     v0, $59f8(at)
80001010	lhu    v0, $0002(a0)
80001014	lui    v1, $8016
80001018	lh     v1, $2080(v1)
8000101C	xori   v0, v0, $0001
80001020	slti   v1, v1, $0002
80001024	beq    v1, zero, L1034 [$80001034]
80001028	sh     v0, $0002(a0)
8000102C	addiu  v0, zero, $ffff (=-$1)
80001030	sh     v0, $0000(a0)

L1034:	; 80001034
80001034	jr     ra 
80001038	nop

8000103C	addiu  sp, sp, $ffe0 (=-$20)
80001040	sw     s0, $0010(sp)
80001044	addu   s0, a0, zero
80001048	sw     s1, $0014(sp)
8000104C	addu   s1, a1, zero
80001050	lui    a0, $801b
80001054	addiu  a0, a0, $1a18
80001058	addu   a1, zero, zero
8000105C	addu   a2, zero, zero
80001060	sw     ra, $0018(sp)
80001064	jal    $800d2980
80001068	addu   a3, zero, zero
8000106C	lui    a0, $801b
80001070	addiu  a0, a0, $0fdc
80001074	jal    $800bbeac
80001078	nop
8000107C	addu   a0, s0, zero
80001080	addu   a1, s1, zero
80001084	lui    a3, $801b
80001088	addiu  a3, a3, $0f88
8000108C	jal    $800d5444
80001090	addu   a2, zero, zero
80001094	lw     ra, $0018(sp)
80001098	lw     s1, $0014(sp)
8000109C	lw     s0, $0010(sp)
800010A0	addiu  sp, sp, $0020
800010A4	jr     ra 
800010A8	nop
