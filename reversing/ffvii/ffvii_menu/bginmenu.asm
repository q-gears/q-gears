
Entry:	; 80000000
80000000	addiu  sp, sp, $ffb0 (=-$50)
80000004	sw     s2, $0048(sp)
80000008	lui    s2, $801d
8000000C	addiu  s2, s2, $0860
80000010	addu   a0, s2, zero
80000014	addu   a1, zero, zero
80000018	addu   a2, zero, zero
8000001C	ori    a3, zero, $0001
80000020	sw     s1, $0044(sp)
80000024	ori    s1, zero, $0003
80000028	sw     s0, $0040(sp)
8000002C	ori    s0, zero, $0001
80000030	sw     ra, $004c(sp)
80000034	sw     s1, $0010(sp)
80000038	sw     zero, $0014(sp)
8000003C	sw     zero, $0018(sp)
80000040	sw     s0, $001c(sp)
80000044	sw     s1, $0020(sp)
80000048	sw     zero, $0024(sp)
8000004C	sw     zero, $0028(sp)
80000050	sw     zero, $002c(sp)
80000054	sw     s0, $0030(sp)
80000058	jal    $80026448
8000005C	sw     zero, $0034(sp)
80000060	addiu  a0, s2, $0012
80000064	addu   a1, zero, zero
80000068	addu   a2, zero, zero
8000006C	ori    a3, zero, $0001
80000070	ori    v0, zero, $0009
80000074	sw     s1, $0010(sp)
80000078	sw     zero, $0014(sp)
8000007C	sw     zero, $0018(sp)
80000080	sw     s0, $001c(sp)
80000084	sw     v0, $0020(sp)
80000088	sw     zero, $0024(sp)
8000008C	sw     zero, $0028(sp)
80000090	sw     zero, $002c(sp)
80000094	sw     zero, $0030(sp)
80000098	jal    $80026448
8000009C	sw     zero, $0034(sp)
800000A0	lui    at, $801d
800000A4	sw     zero, $07f0(at)
800000A8	lw     ra, $004c(sp)
800000AC	lw     s2, $0048(sp)
800000B0	lw     s1, $0044(sp)
800000B4	lw     s0, $0040(sp)
800000B8	addiu  sp, sp, $0050
800000BC	jr     ra 
800000C0	nop

800000C4	lui    a0, $8006
800000C8	lw     a0, $2f58(a0)
800000CC	addiu  sp, sp, $ffd0 (=-$30)
800000D0	sw     ra, $0028(sp)
800000D4	sw     s1, $0024(sp)
800000D8	jal    $800230c4
800000DC	sw     s0, $0020(sp)
800000E0	lui    v0, $801d
800000E4	lw     v0, $07f0(v0)
800000E8	nop
800000EC	bne    v0, zero, L0118 [$80000118]
800000F0	nop
800000F4	addu   a0, zero, zero
800000F8	lui    v0, $801d
800000FC	lb     v0, $086b(v0)
80000100	lui    a1, $801d
80000104	lh     a1, $07fe(a1)
80000108	sll    v0, v0, $06
8000010C	addu   a1, a1, v0
80000110	jal    $8001eb2c
80000114	addiu  a1, a1, $0020

L0118:	; 80000118
80000118	ori    a0, zero, $0010
8000011C	ori    a1, zero, $000b
80000120	lui    a2, $801d
80000124	addiu  a2, a2, $0804
80000128	jal    $80026f44
8000012C	ori    a3, zero, $0007
80000130	addu   s1, zero, zero
80000134	lui    s0, $801d
80000138	addiu  s0, s0, $07f4

loop013c:	; 8000013C
8000013C	jal    $8001e040
80000140	addu   a0, s0, zero
80000144	addiu  s1, s1, $0001
80000148	slti   v0, s1, $0002
8000014C	bne    v0, zero, loop013c [$8000013c]
80000150	addiu  s0, s0, $0008
80000154	lui    v0, $801d
80000158	lw     v0, $07f0(v0)
8000015C	nop
80000160	sll    a0, v0, $03
80000164	addu   a0, a0, v0
80000168	sll    a0, a0, $01
8000016C	lui    v0, $801d
80000170	addiu  v0, v0, $0860
80000174	jal    $800264a8
80000178	addu   a0, a0, v0
8000017C	lui    v0, $8006
80000180	lhu    v0, $2d7e(v0)
80000184	nop
80000188	andi   v0, v0, $0040
8000018C	beq    v0, zero, L01a4 [$800001a4]
80000190	ori    a0, zero, $0005
80000194	jal    $8002305c
80000198	addu   a1, zero, zero
8000019C	jal    $8002120c
800001A0	addu   a0, zero, zero

L01a4:	; 800001A4
800001A4	lw     ra, $0028(sp)
800001A8	lw     s1, $0024(sp)
800001AC	lw     s0, $0020(sp)
800001B0	addiu  sp, sp, $0030
800001B4	jr     ra 
800001B8	nop

800001BC	jr     ra 
800001C0	nop

800001C4	addu   a1, zero, zero
800001C8	addu   a2, zero, zero
800001CC	addiu  a3, zero, $ffff (=-$1)
800001D0	sll    v0, a0, $05
800001D4	addu   v0, v0, a0
800001D8	sll    v0, v0, $02
800001DC	lui    v1, $800a
800001E0	addiu  v1, v1, $c778 (=-$3888)
800001E4	addu   v1, v0, v1

loop01e8:	; 800001E8
800001E8	lw     v0, $0000(v1)
800001EC	nop
800001F0	beq    v0, a3, L01fc [$800001fc]
800001F4	nop
800001F8	addiu  a2, a2, $0001

L01fc:	; 800001FC
800001FC	addiu  a1, a1, $0001
80000200	slti   v0, a1, $0008
80000204	bne    v0, zero, loop01e8 [$800001e8]
80000208	addiu  v1, v1, $0004
8000020C	addu   a1, zero, zero
80000210	addiu  a3, zero, $ffff (=-$1)
80000214	sll    v0, a0, $05
80000218	addu   v0, v0, a0
8000021C	sll    v0, v0, $02
80000220	lui    v1, $800a
80000224	addiu  v1, v1, $c798 (=-$3868)
80000228	addu   v1, v0, v1

loop022c:	; 8000022C
8000022C	lw     v0, $0000(v1)
80000230	nop
80000234	beq    v0, a3, L0240 [$80000240]
80000238	nop
8000023C	addiu  a2, a2, $0001

L0240:	; 80000240
80000240	addiu  a1, a1, $0001
80000244	slti   v0, a1, $0008
80000248	bne    v0, zero, loop022c [$8000022c]
8000024C	addiu  v1, v1, $0004
80000250	jr     ra 
80000254	addu   v0, a2, zero

80000258	lbu    v0, $0001(a0)
8000025C	lbu    v1, $0000(a0)
80000260	sll    v0, v0, $08
80000264	jr     ra 
80000268	or     v0, v1, v0

8000026C	srl    v0, a1, $08
80000270	sb     a1, $0000(a0)
80000274	jr     ra 
80000278	sb     v0, $0001(a0)

8000027C	addiu  sp, sp, $ffd8 (=-$28)
80000280	sw     s2, $0018(sp)
80000284	addu   s2, zero, zero
80000288	sw     s3, $001c(sp)
8000028C	lui    s3, $8000
80000290	ori    s3, s3, $8001
80000294	lui    v0, $800a
80000298	addiu  v0, v0, $d3fc (=-$2c04)
8000029C	sw     s0, $0010(sp)
800002A0	addiu  s0, v0, $f368 (=-$c98)
800002A4	sw     s1, $0014(sp)
800002A8	addu   s1, v0, zero
800002AC	sw     ra, $0020(sp)

loop02b0:	; 800002B0
800002B0	jal    $801d0258
800002B4	addu   a0, s1, zero
800002B8	lhu    v1, $0000(s0)
800002BC	nop
800002C0	mult   v1, v0
800002C4	mflo   v1
800002C8	mult   v1, s3
800002CC	mfhi   a1
800002D0	addu   v0, a1, v1
800002D4	sra    v0, v0, $0f
800002D8	sra    v1, v1, $1f
800002DC	subu   v0, v0, v1
800002E0	bgtz   v0, L02ec [$800002ec]
800002E4	nop
800002E8	ori    v0, zero, $0001

L02ec:	; 800002EC
800002EC	sh     v0, $0000(s0)
800002F0	addiu  s0, s0, $0084
800002F4	addiu  s2, s2, $0001
800002F8	slti   v0, s2, $0005
800002FC	bne    v0, zero, loop02b0 [$800002b0]
80000300	addiu  s1, s1, $0002
80000304	lw     ra, $0020(sp)
80000308	lw     s3, $001c(sp)
8000030C	lw     s2, $0018(sp)
80000310	lw     s1, $0014(sp)
80000314	lw     s0, $0010(sp)
80000318	addiu  sp, sp, $0028
8000031C	jr     ra 
80000320	nop

80000324	addiu  v0, zero, $ff00 (=-$100)
80000328	or     a0, a0, v0
8000032C	addu   a2, zero, zero
80000330	addiu  t1, zero, $ffff (=-$1)
80000334	lui    t2, $800a
80000338	addiu  t2, t2, $d78a (=-$2876)
8000033C	addiu  t0, t2, $f00e (=-$ff2)
80000340	addiu  a3, t2, $efee (=-$1012)

loop0344:	; 80000344
80000344	lhu    v0, $0000(t2)
80000348	nop
8000034C	srav   v0, a2, v0
80000350	andi   v0, v0, $0001
80000354	beq    v0, zero, L03b4 [$800003b4]
80000358	nop
8000035C	addu   a1, zero, zero
80000360	addu   v1, a3, zero

loop0364:	; 80000364
80000364	lw     v0, $0000(v1)
80000368	nop
8000036C	beq    v0, a0, L039c [$8000039c]
80000370	nop
80000374	addiu  a1, a1, $0001
80000378	slti   v0, a1, $0008
8000037C	bne    v0, zero, loop0364 [$80000364]
80000380	addiu  v1, v1, $0004
80000384	addu   a1, zero, zero
80000388	addu   v1, t0, zero

loop038c:	; 8000038C
8000038C	lw     v0, $0000(v1)
80000390	nop
80000394	bne    v0, a0, L03a4 [$800003a4]
80000398	nop

L039c:	; 8000039C
8000039C	j      $801d0400
800003A0	sw     t1, $0000(v1)

L03a4:	; 800003A4
800003A4	addiu  a1, a1, $0001
800003A8	slti   v0, a1, $0008
800003AC	bne    v0, zero, loop038c [$8000038c]
800003B0	addiu  v1, v1, $0004

L03b4:	; 800003B4
800003B4	addiu  t0, t0, $0084
800003B8	addiu  a2, a2, $0001
800003BC	slti   v0, a2, $0009
800003C0	bne    v0, zero, loop0344 [$80000344]
800003C4	addiu  a3, a3, $0084
800003C8	addu   a1, zero, zero
800003CC	addiu  a2, zero, $ffff (=-$1)
800003D0	lui    v1, $800a
800003D4	addiu  v1, v1, $ce60 (=-$31a0)

loop03d8:	; 800003D8
800003D8	lw     v0, $0000(v1)
800003DC	nop
800003E0	bne    v0, a0, L03f0 [$800003f0]
800003E4	nop
800003E8	j      $801d0400
800003EC	sw     a2, $0000(v1)

L03f0:	; 800003F0
800003F0	addiu  a1, a1, $0001
800003F4	slti   v0, a1, $00c8
800003F8	bne    v0, zero, loop03d8 [$800003d8]
800003FC	addiu  v1, v1, $0004
80000400	jr     ra 
80000404	nop

80000408	addu   a3, zero, zero
8000040C	lui    v0, $800a
80000410	addiu  v0, v0, $d78a (=-$2876)
80000414	lhu    t3, $0000(v0)
80000418	lui    t2, $00ff
8000041C	ori    t2, t2, $ffff
80000420	addiu  t1, v0, $f00e (=-$ff2)
80000424	addiu  t0, v0, $efee (=-$1012)

loop0428:	; 80000428
80000428	srav   v0, a3, t3
8000042C	andi   v0, v0, $0001
80000430	beq    v0, zero, L04a0 [$800004a0]
80000434	nop
80000438	addu   a1, zero, zero
8000043C	addu   a2, t0, zero

loop0440:	; 80000440
80000440	lw     v0, $0000(a2)
80000444	nop
80000448	srl    v1, v0, $08
8000044C	bne    v1, t2, L045c [$8000045c]
80000450	andi   v0, v0, $00ff
80000454	beq    v0, a0, L04f8 [$800004f8]
80000458	ori    v0, zero, $0001

L045c:	; 8000045C
8000045C	addiu  a1, a1, $0001
80000460	slti   v0, a1, $0008
80000464	bne    v0, zero, loop0440 [$80000440]
80000468	addiu  a2, a2, $0004
8000046C	addu   a1, zero, zero
80000470	addu   a2, t1, zero

loop0474:	; 80000474
80000474	lw     v0, $0000(a2)
80000478	nop
8000047C	srl    v1, v0, $08
80000480	bne    v1, t2, L0490 [$80000490]
80000484	andi   v0, v0, $00ff
80000488	beq    v0, a0, L04f8 [$800004f8]
8000048C	ori    v0, zero, $0001

L0490:	; 80000490
80000490	addiu  a1, a1, $0001
80000494	slti   v0, a1, $0008
80000498	bne    v0, zero, loop0474 [$80000474]
8000049C	addiu  a2, a2, $0004

L04a0:	; 800004A0
800004A0	addiu  t1, t1, $0084
800004A4	addiu  a3, a3, $0001
800004A8	slti   v0, a3, $0009
800004AC	bne    v0, zero, loop0428 [$80000428]
800004B0	addiu  t0, t0, $0084
800004B4	addu   a1, zero, zero
800004B8	lui    a3, $00ff
800004BC	ori    a3, a3, $ffff
800004C0	lui    a2, $800a
800004C4	addiu  a2, a2, $ce60 (=-$31a0)

loop04c8:	; 800004C8
800004C8	lw     v0, $0000(a2)
800004CC	nop
800004D0	srl    v1, v0, $08
800004D4	bne    v1, a3, L04e4 [$800004e4]
800004D8	andi   v0, v0, $00ff
800004DC	beq    v0, a0, L04f8 [$800004f8]
800004E0	ori    v0, zero, $0001

L04e4:	; 800004E4
800004E4	addiu  a1, a1, $0001
800004E8	slti   v0, a1, $00c8
800004EC	bne    v0, zero, loop04c8 [$800004c8]
800004F0	addiu  a2, a2, $0004
800004F4	addu   v0, zero, zero

L04f8:	; 800004F8
800004F8	jr     ra 
800004FC	nop

80000500	addu   a2, zero, zero
80000504	lui    v0, $800a
80000508	addiu  v0, v0, $d78a (=-$2876)
8000050C	lhu    t1, $0000(v0)
80000510	addiu  t0, v0, $f00e (=-$ff2)
80000514	addiu  a3, v0, $efee (=-$1012)

loop0518:	; 80000518
80000518	srav   v0, a2, t1
8000051C	andi   v0, v0, $0001
80000520	beq    v0, zero, L0578 [$80000578]
80000524	nop
80000528	addu   v1, zero, zero
8000052C	addu   a1, a3, zero

loop0530:	; 80000530
80000530	lbu    v0, $0000(a1)
80000534	nop
80000538	beq    v0, a0, L05bc [$800005bc]
8000053C	ori    v0, zero, $0001
80000540	addiu  v1, v1, $0001
80000544	slti   v0, v1, $0008
80000548	bne    v0, zero, loop0530 [$80000530]
8000054C	addiu  a1, a1, $0004
80000550	addu   v1, zero, zero
80000554	addu   a1, t0, zero

loop0558:	; 80000558
80000558	lbu    v0, $0000(a1)
8000055C	nop
80000560	beq    v0, a0, L05bc [$800005bc]
80000564	ori    v0, zero, $0001
80000568	addiu  v1, v1, $0001
8000056C	slti   v0, v1, $0008
80000570	bne    v0, zero, loop0558 [$80000558]
80000574	addiu  a1, a1, $0004

L0578:	; 80000578
80000578	addiu  t0, t0, $0084
8000057C	addiu  a2, a2, $0001
80000580	slti   v0, a2, $0009
80000584	bne    v0, zero, loop0518 [$80000518]
80000588	addiu  a3, a3, $0084
8000058C	addu   v1, zero, zero
80000590	lui    a1, $800a
80000594	addiu  a1, a1, $ce60 (=-$31a0)

loop0598:	; 80000598
80000598	lbu    v0, $0000(a1)
8000059C	nop
800005A0	beq    v0, a0, L05bc [$800005bc]
800005A4	ori    v0, zero, $0001
800005A8	addiu  v1, v1, $0001
800005AC	slti   v0, v1, $00c8
800005B0	bne    v0, zero, loop0598 [$80000598]
800005B4	addiu  a1, a1, $0004
800005B8	addu   v0, zero, zero

L05bc:	; 800005BC
800005BC	jr     ra 
800005C0	nop

800005C4	addiu  sp, sp, $ffe8 (=-$18)
800005C8	ori    v0, zero, $0001
800005CC	sw     ra, $0014(sp)
800005D0	sw     s0, $0010(sp)
800005D4	lui    at, $800a
800005D8	sb     zero, $d6f7(at)
800005DC	beq    a0, v0, L064c [$8000064c]
800005E0	slti   v0, a0, $0002
800005E4	beq    v0, zero, L05fc [$800005fc]
800005E8	nop
800005EC	beq    a0, zero, L0618 [$80000618]
800005F0	addu   s0, zero, zero
800005F4	j      $801d06e8
800005F8	ori    v0, zero, $0001

L05fc:	; 800005FC
800005FC	ori    v0, zero, $0002
80000600	beq    a0, v0, L0684 [$80000684]
80000604	ori    v0, zero, $0003
80000608	beq    a0, v0, L06bc [$800006bc]
8000060C	addu   s0, zero, zero
80000610	j      $801d06e8
80000614	ori    v0, zero, $0001

L0618:	; 80000618
80000618	lui    at, $801d
8000061C	addiu  at, at, $082c
80000620	addu   at, at, s0
80000624	lbu    a0, $0000(at)
80000628	jal    $801d0408
8000062C	nop
80000630	beq    v0, zero, L06f0 [$800006f0]
80000634	addiu  s0, s0, $0001
80000638	slti   v0, s0, $0015
8000063C	bne    v0, zero, L0618 [$80000618]
80000640	ori    v0, zero, $0001
80000644	j      $801d06e8
80000648	nop

L064c:	; 8000064C
8000064C	addu   s0, zero, zero

loop0650:	; 80000650
80000650	lui    at, $801d
80000654	addiu  at, at, $0844
80000658	addu   at, at, s0
8000065C	lbu    a0, $0000(at)
80000660	jal    $801d0408
80000664	nop
80000668	beq    v0, zero, L06f0 [$800006f0]
8000066C	addiu  s0, s0, $0001
80000670	slti   v0, s0, $0010
80000674	bne    v0, zero, loop0650 [$80000650]
80000678	ori    v0, zero, $0001
8000067C	j      $801d06e8
80000680	nop

L0684:	; 80000684
80000684	addu   s0, zero, zero

loop0688:	; 80000688
80000688	lui    at, $801d
8000068C	addiu  at, at, $0854
80000690	addu   at, at, s0
80000694	lbu    a0, $0000(at)
80000698	jal    $801d0408
8000069C	nop
800006A0	beq    v0, zero, L06f0 [$800006f0]
800006A4	addiu  s0, s0, $0001
800006A8	slti   v0, s0, $0007
800006AC	bne    v0, zero, loop0688 [$80000688]
800006B0	ori    v0, zero, $0001
800006B4	j      $801d06e8
800006B8	nop

L06bc:	; 800006BC
800006BC	lui    at, $801d
800006C0	addiu  at, at, $085c
800006C4	addu   at, at, s0
800006C8	lbu    a0, $0000(at)
800006CC	jal    $801d0500
800006D0	nop
800006D4	beq    v0, zero, L06f0 [$800006f0]
800006D8	addiu  s0, s0, $0001
800006DC	slti   v0, s0, $0002
800006E0	bne    v0, zero, L06bc [$800006bc]
800006E4	ori    v0, zero, $0001
800006E8	lui    at, $800a
800006EC	sb     v0, $d6f7(at)

L06f0:	; 800006F0
800006F0	lw     ra, $0014(sp)
800006F4	lw     s0, $0010(sp)
800006F8	addiu  sp, sp, $0018
800006FC	jr     ra 
80000700	nop

80000704	addiu  sp, sp, $ffe8 (=-$18)
80000708	ori    v0, zero, $0001
8000070C	sw     ra, $0014(sp)
80000710	beq    a0, v0, L077c [$8000077c]
80000714	sw     s0, $0010(sp)
80000718	slti   v0, a0, $0002
8000071C	beq    v0, zero, L0734 [$80000734]
80000720	nop
80000724	beq    a0, zero, L0750 [$80000750]
80000728	addu   s0, zero, zero
8000072C	j      $801d07dc
80000730	nop

L0734:	; 80000734
80000734	ori    v0, zero, $0002
80000738	beq    a0, v0, L07ac [$800007ac]
8000073C	ori    v0, zero, $0003
80000740	beq    a0, v0, L07d4 [$800007d4]
80000744	ori    a0, zero, $0058
80000748	j      $801d07dc
8000074C	nop

L0750:	; 80000750
80000750	lui    at, $801d
80000754	addiu  at, at, $082c
80000758	addu   at, at, s0
8000075C	lbu    a0, $0000(at)
80000760	jal    $801d0324
80000764	addiu  s0, s0, $0001
80000768	slti   v0, s0, $0015
8000076C	bne    v0, zero, L0750 [$80000750]
80000770	ori    a0, zero, $0049
80000774	j      $801d07d4
80000778	nop

L077c:	; 8000077C
8000077C	addu   s0, zero, zero

loop0780:	; 80000780
80000780	lui    at, $801d
80000784	addiu  at, at, $0844
80000788	addu   at, at, s0
8000078C	lbu    a0, $0000(at)
80000790	jal    $801d0324
80000794	addiu  s0, s0, $0001
80000798	slti   v0, s0, $0010
8000079C	bne    v0, zero, loop0780 [$80000780]
800007A0	ori    a0, zero, $005a
800007A4	j      $801d07d4
800007A8	nop

L07ac:	; 800007AC
800007AC	addu   s0, zero, zero

loop07b0:	; 800007B0
800007B0	lui    at, $801d
800007B4	addiu  at, at, $0854
800007B8	addu   at, at, s0
800007BC	lbu    a0, $0000(at)
800007C0	jal    $801d0324
800007C4	addiu  s0, s0, $0001
800007C8	slti   v0, s0, $0007
800007CC	bne    v0, zero, loop07b0 [$800007b0]
800007D0	ori    a0, zero, $0030

L07d4:	; 800007D4
800007D4	jal    $8002542c
800007D8	nop
800007DC	lw     ra, $0014(sp)
800007E0	lw     s0, $0010(sp)
800007E4	addiu  sp, sp, $0018
800007E8	jr     ra 
800007EC	nop

800007F0	FFFFFFFF	....
800007F4	sll    zero, a1, $00
800007F8	0018016C	l...
800007FC	sll    zero, sp, $00
80000800	00C3016C	l...
80000804	61176953	Si.a
80000808	addu   t5, a3, ra
8000080C	sllv   zero, zero, zero
80000810	sra    zero, zero, $00
80000814	srl    zero, zero, $00
80000818	00000001	....
8000081C	FFFFFFFF	....
80000820	FFFFFFFF	....
80000824	FFFFFFFF	....
80000828	FFFFFFFF	....
8000082C	ori    s3, at, $3231
80000830	xori   s7, at, $3635
80000834	lui    k1, $3a39
80000838	41403E3D	=>@A
8000083C	47464544	DEFG
80000840	jr     zero 
80000844	4D4C4B4A	JKLM
80000848	51504F4E	NOPQ
8000084C	55545352	RSTU
80000850	59585756	VWXY
80000854	slti   a3, at, $2524
80000858	002B2A29	)*+.
8000085C	mthi   zero
80000860	nop
80000864	nop
80000868	nop
8000086C	nop
80000870	nop
80000874	nop
80000878	nop
8000087C	nop
80000880	nop
80000884	nop
80000888	nop
8000088C	nop
80000890	nop
80000894	nop
