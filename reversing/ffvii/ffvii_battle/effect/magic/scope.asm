
Entry:	; 80000000
80000000	nop
80000004	nop
80000008	nop
8000000C	nop
80000010	nop
80000014	nop
80000018	nop
8000001C	nop
80000020	lb     k1, $d720(zero)
80000024	lb     k1, $d7e8(zero)
80000028	addiu  sp, sp, $ffc0 (=-$40)
8000002C	sw     s2, $0030(sp)
80000030	addu   s2, a1, zero
80000034	sw     s1, $002c(sp)
80000038	addu   s1, zero, zero
8000003C	sw     s0, $0028(sp)
80000040	addu   s0, zero, zero
80000044	sll    a0, a0, $10
80000048	sw     s3, $0034(sp)
8000004C	sra    s3, a0, $10
80000050	sw     ra, $0038(sp)
80000054	sw     zero, $0018(sp)
80000058	sw     zero, $0014(sp)
8000005C	sw     zero, $0010(sp)
80000060	sll    v0, s0, $10

loop0064:	; 80000064
80000064	sra    a0, v0, $10
80000068	srav   v0, a0, s3
8000006C	andi   v0, v0, $0001
80000070	beq    v0, zero, L00e4 [$800000e4]
80000074	addiu  v0, s0, $0001
80000078	sll    v1, a0, $01
8000007C	addu   v1, v1, a0
80000080	sll    v0, v1, $05
80000084	subu   v0, v0, v1
80000088	sll    v0, v0, $03
8000008C	subu   v0, v0, a0
80000090	sll    v0, v0, $02
80000094	lui    at, $8015
80000098	addiu  at, at, $190f
8000009C	addu   at, at, v0
800000A0	lbu    a1, $0000(at)
800000A4	jal    $800d3994
800000A8	addiu  a2, sp, $0020
800000AC	addiu  s1, s1, $0001
800000B0	lh     v0, $0020(sp)
800000B4	lw     v1, $0010(sp)
800000B8	lw     a0, $0014(sp)
800000BC	lw     a1, $0018(sp)
800000C0	addu   v0, v0, v1
800000C4	sw     v0, $0010(sp)
800000C8	lh     v0, $0022(sp)
800000CC	lh     v1, $0024(sp)
800000D0	addu   v0, v0, a0
800000D4	addu   v1, v1, a1
800000D8	sw     v0, $0014(sp)
800000DC	sw     v1, $0018(sp)
800000E0	addiu  v0, s0, $0001

L00e4:	; 800000E4
800000E4	addu   s0, v0, zero
800000E8	sll    v0, v0, $10
800000EC	sra    v0, v0, $10
800000F0	slti   v0, v0, $000a
800000F4	bne    v0, zero, loop0064 [$80000064]
800000F8	sll    v0, s0, $10
800000FC	sll    v1, s1, $10
80000100	lw     v0, $0010(sp)
80000104	sra    v1, v1, $10
80000108	div    v0, v1
8000010C	bne    v1, zero, L0118 [$80000118]
80000110	nop
80000114	break   $01c00

L0118:	; 80000118
80000118	addiu  at, zero, $ffff (=-$1)
8000011C	bne    v1, at, L0130 [$80000130]
80000120	lui    at, $8000
80000124	bne    v0, at, L0130 [$80000130]
80000128	nop
8000012C	break   $01800

L0130:	; 80000130
80000130	mflo   v0
80000134	nop
80000138	sh     v0, $0000(s2)
8000013C	lw     v0, $0014(sp)
80000140	nop
80000144	div    v0, v1
80000148	bne    v1, zero, L0154 [$80000154]
8000014C	nop
80000150	break   $01c00

L0154:	; 80000154
80000154	addiu  at, zero, $ffff (=-$1)
80000158	bne    v1, at, L016c [$8000016c]
8000015C	lui    at, $8000
80000160	bne    v0, at, L016c [$8000016c]
80000164	nop
80000168	break   $01800

L016c:	; 8000016C
8000016C	mflo   v0
80000170	nop
80000174	sh     v0, $0002(s2)
80000178	lw     v0, $0018(sp)
8000017C	nop
80000180	div    v0, v1
80000184	bne    v1, zero, L0190 [$80000190]
80000188	nop
8000018C	break   $01c00

L0190:	; 80000190
80000190	addiu  at, zero, $ffff (=-$1)
80000194	bne    v1, at, L01a8 [$800001a8]
80000198	lui    at, $8000
8000019C	bne    v0, at, L01a8 [$800001a8]
800001A0	nop
800001A4	break   $01800

L01a8:	; 800001A8
800001A8	mflo   v0
800001AC	nop
800001B0	sh     v0, $0004(s2)
800001B4	lw     ra, $0038(sp)
800001B8	lw     s3, $0034(sp)
800001BC	lw     s2, $0030(sp)
800001C0	lw     s1, $002c(sp)
800001C4	lw     s0, $0028(sp)
800001C8	addiu  sp, sp, $0040
800001CC	jr     ra 
800001D0	nop

800001D4	addiu  sp, sp, $ffa8 (=-$58)
800001D8	sw     s0, $0040(sp)
800001DC	addu   s0, a0, zero
800001E0	sw     s1, $0044(sp)
800001E4	addu   s1, a1, zero
800001E8	sw     s3, $004c(sp)
800001EC	addu   s3, a2, zero
800001F0	sw     ra, $0050(sp)
800001F4	sw     s2, $0048(sp)
800001F8	sh     zero, $0014(sp)
800001FC	jal    $80042da8
80000200	sh     zero, $0010(sp)
80000204	sll    v1, s1, $10
80000208	sra    v1, v1, $10
8000020C	div    v0, v1
80000210	bne    v1, zero, L021c [$8000021c]
80000214	nop
80000218	break   $01c00

L021c:	; 8000021C
8000021C	addiu  at, zero, $ffff (=-$1)
80000220	bne    v1, at, L0234 [$80000234]
80000224	lui    at, $8000
80000228	bne    v0, at, L0234 [$80000234]
8000022C	nop
80000230	break   $01800

L0234:	; 80000234
80000234	mfhi   v1
80000238	lui    s2, $51eb
8000023C	ori    s2, s2, $851f
80000240	sh     zero, $001a(sp)
80000244	sll    v1, v1, $01
80000248	subu   v1, v1, s1
8000024C	addu   s0, s0, v1
80000250	jal    $80042da8
80000254	sh     s0, $0012(sp)
80000258	mult   v0, s2
8000025C	sra    v1, v0, $1f
80000260	mfhi   a0
80000264	sra    a0, a0, $08
80000268	subu   a0, a0, v1
8000026C	sll    v1, a0, $01
80000270	addu   v1, v1, a0
80000274	sll    v1, v1, $03
80000278	addu   v1, v1, a0
8000027C	sll    v1, v1, $05
80000280	subu   v0, v0, v1
80000284	addiu  v0, v0, $fe70 (=-$190)
80000288	jal    $80042da8
8000028C	sh     v0, $0018(sp)
80000290	mult   v0, s2
80000294	addiu  a0, sp, $0018
80000298	addiu  s0, sp, $0020
8000029C	addu   a1, s0, zero
800002A0	sra    v1, v0, $1f
800002A4	mfhi   a2
800002A8	sra    a2, a2, $08
800002AC	subu   a2, a2, v1
800002B0	sll    v1, a2, $01
800002B4	addu   v1, v1, a2
800002B8	sll    v1, v1, $03
800002BC	addu   v1, v1, a2
800002C0	sll    v1, v1, $05
800002C4	subu   v0, v0, v1
800002C8	addiu  v0, v0, $fe70 (=-$190)
800002CC	jal    $8003bf8c
800002D0	sh     v0, $001c(sp)
800002D4	addu   a0, s0, zero
800002D8	addiu  a1, sp, $0010
800002DC	jal    $8003b2cc
800002E0	addu   a2, s3, zero
800002E4	lw     ra, $0050(sp)
800002E8	lw     s3, $004c(sp)
800002EC	lw     s2, $0048(sp)
800002F0	lw     s1, $0044(sp)
800002F4	lw     s0, $0040(sp)
800002F8	addiu  sp, sp, $0058
800002FC	jr     ra 
80000300	nop

80000304	addiu  sp, sp, $ff80 (=-$80)
80000308	sw     s3, $0074(sp)
8000030C	addu   s3, a0, zero
80000310	sw     s4, $0078(sp)
80000314	addu   s4, a1, zero
80000318	sw     s1, $006c(sp)
8000031C	addu   s1, a3, zero
80000320	sw     s2, $0070(sp)
80000324	addu   s2, a2, zero
80000328	addu   a0, zero, zero
8000032C	addiu  a1, sp, $0010
80000330	sw     ra, $007c(sp)
80000334	sw     s0, $0068(sp)

loop0338:	; 80000338
80000338	sll    v0, a0, $10
8000033C	addiu  v1, a0, $0001
80000340	addu   a0, v1, zero
80000344	sra    v0, v0, $0f
80000348	addu   v0, v0, a1
8000034C	sll    v1, v1, $10
80000350	sra    v1, v1, $10
80000354	slti   v1, v1, $0003
80000358	sh     zero, $000c(v0)
8000035C	sh     zero, $0006(v0)
80000360	bne    v1, zero, loop0338 [$80000338]
80000364	sh     zero, $0000(v0)
80000368	lui    s0, $8010
8000036C	addiu  s0, s0, $a63c (=-$59c4)
80000370	jal    $8003b48c
80000374	addu   a0, s0, zero
80000378	jal    $8003b51c
8000037C	addu   a0, s0, zero
80000380	addu   a0, s3, zero
80000384	addiu  s0, sp, $0024
80000388	addu   a1, s0, zero
8000038C	jal    $8003bc6c
80000390	addiu  a2, sp, $0060
80000394	beq    s1, zero, L0408 [$80000408]
80000398	nop
8000039C	addu   a0, s0, zero
800003A0	jal    $8003a08c
800003A4	addiu  a1, sp, $0050
800003A8	lw     v0, $0050(sp)
800003AC	nop
800003B0	mult   s1, v0
800003B4	mflo   v1
800003B8	lw     v0, $0054(sp)
800003BC	nop
800003C0	mult   s1, v0
800003C4	mflo   a0
800003C8	lw     v0, $0058(sp)
800003CC	nop
800003D0	mult   s1, v0
800003D4	lw     v0, $0024(sp)
800003D8	sra    v1, v1, $0c
800003DC	addu   v1, v1, v0
800003E0	lw     v0, $0028(sp)
800003E4	sra    a0, a0, $0c
800003E8	sw     v1, $0024(sp)
800003EC	lw     v1, $002c(sp)
800003F0	addu   a0, a0, v0
800003F4	sw     a0, $0028(sp)
800003F8	mflo   v0
800003FC	sra    v0, v0, $0c
80000400	addu   v0, v0, v1
80000404	sw     v0, $002c(sp)

L0408:	; 80000408
80000408	addu   a0, s4, zero
8000040C	addiu  s0, sp, $0030
80000410	addu   a1, s0, zero
80000414	sh     s2, $0020(sp)
80000418	sh     s2, $0018(sp)
8000041C	jal    $8003c21c
80000420	sh     s2, $0010(sp)
80000424	addiu  a0, sp, $0010
80000428	jal    $8003b05c
8000042C	addu   a1, s0, zero
80000430	jal    $8003b48c
80000434	addiu  a0, sp, $0010
80000438	jal    $8003b51c
8000043C	addiu  a0, sp, $0010
80000440	lw     ra, $007c(sp)
80000444	lw     s4, $0078(sp)
80000448	lw     s3, $0074(sp)
8000044C	lw     s2, $0070(sp)
80000450	lw     s1, $006c(sp)
80000454	lw     s0, $0068(sp)
80000458	addiu  sp, sp, $0080
8000045C	jr     ra 
80000460	nop

80000464	lui    v0, $8015
80000468	lh     v0, $169c(v0)
8000046C	lui    v1, $8016
80000470	addiu  v1, v1, $2978
80000474	sll    v0, v0, $05
80000478	addu   a0, v0, v1
8000047C	lh     v1, $0002(a0)
80000480	nop
80000484	sll    v0, v1, $01
80000488	addu   v0, v0, v1
8000048C	sll    v0, v0, $0e
80000490	lui    v1, $801c
80000494	addiu  v1, v1, $d964 (=-$269c)
80000498	addu   v0, v0, v1
8000049C	lui    at, $801d
800004A0	sw     v0, $5964(at)
800004A4	lhu    v0, $0002(a0)
800004A8	lui    v1, $8016
800004AC	lh     v1, $2080(v1)
800004B0	xori   v0, v0, $0001
800004B4	slti   v1, v1, $0002
800004B8	beq    v1, zero, L04c8 [$800004c8]
800004BC	sh     v0, $0002(a0)
800004C0	addiu  v0, zero, $ffff (=-$1)
800004C4	sh     v0, $0000(a0)

L04c8:	; 800004C8
800004C8	jr     ra 
800004CC	nop

800004D0	addiu  sp, sp, $ff88 (=-$78)
800004D4	sw     s3, $006c(sp)
800004D8	addu   s3, a1, zero
800004DC	sw     ra, $0070(sp)
800004E0	sw     s2, $0068(sp)
800004E4	sw     s1, $0064(sp)
800004E8	sw     s0, $0060(sp)
800004EC	lui    a1, $801b
800004F0	addiu  a1, a1, $0000
800004F4	lw     v0, $0000(a1)
800004F8	lw     v1, $0004(a1)
800004FC	lw     a0, $0008(a1)
80000500	sw     v0, $0030(sp)
80000504	sw     v1, $0034(sp)
80000508	sw     a0, $0038(sp)
8000050C	lw     v0, $000c(a1)
80000510	lw     v1, $0010(a1)
80000514	lw     a0, $0014(a1)
80000518	sw     v0, $003c(sp)
8000051C	sw     v1, $0040(sp)
80000520	sw     a0, $0044(sp)
80000524	lw     v0, $0018(a1)
80000528	lw     v1, $001c(a1)
8000052C	sw     v0, $0048(sp)
80000530	sw     v1, $004c(sp)
80000534	lui    s0, $8010
80000538	addiu  s0, s0, $a63c (=-$59c4)
8000053C	addu   a0, s0, zero
80000540	jal    $8003b48c
80000544	addu   s1, a2, zero
80000548	jal    $8003b51c
8000054C	addu   a0, s0, zero
80000550	addiu  s2, sp, $0030
80000554	addu   a0, s2, zero
80000558	addu   a1, s0, zero
8000055C	sh     s1, $0040(sp)
80000560	sh     s1, $0038(sp)
80000564	jal    $8003b05c
80000568	sh     s1, $0030(sp)
8000056C	addu   a0, s3, zero
80000570	jal    $8003c21c
80000574	addiu  a1, sp, $0010
80000578	addu   a0, s2, zero
8000057C	jal    $8003b05c
80000580	addiu  a1, sp, $0010
80000584	jal    $8003b48c
80000588	addu   a0, s2, zero
8000058C	jal    $8003b51c
80000590	addu   a0, s2, zero
80000594	lw     ra, $0070(sp)
80000598	lw     s3, $006c(sp)
8000059C	lw     s2, $0068(sp)
800005A0	lw     s1, $0064(sp)
800005A4	lw     s0, $0060(sp)
800005A8	addiu  sp, sp, $0078
800005AC	jr     ra 
800005B0	nop

800005B4	addiu  sp, sp, $ffd8 (=-$28)
800005B8	sw     ra, $0020(sp)
800005BC	sw     s1, $001c(sp)
800005C0	sw     s0, $0018(sp)
800005C4	lui    v0, $801b
800005C8	lw     v0, $0020(v0)
800005CC	lui    v1, $801b
800005D0	lw     v1, $0024(v1)
800005D4	sw     v0, $0010(sp)
800005D8	sw     v1, $0014(sp)
800005DC	ori    a1, zero, $2400
800005E0	addu   a2, zero, zero
800005E4	lui    v0, $8015
800005E8	lh     v0, $169c(v0)
800005EC	lui    v1, $8016
800005F0	addiu  v1, v1, $2978
800005F4	sll    v0, v0, $05
800005F8	addu   s0, v0, v1
800005FC	jal    $800d4368
80000600	addiu  a0, s0, $0004
80000604	lui    a0, $801c
80000608	addiu  a0, a0, $d910 (=-$26f0)
8000060C	addiu  s1, sp, $0010
80000610	lh     v0, $001a(s0)
80000614	lui    a1, $8015
80000618	lw     a1, $17c0(a1)
8000061C	lui    a3, $801d
80000620	lw     a3, $5964(a3)
80000624	sll    v0, v0, $02
80000628	addu   v0, v0, s1
8000062C	lw     v0, $0000(v0)
80000630	ori    a2, zero, $000c
80000634	sw     v0, $0000(a0)
80000638	lhu    v0, $0002(s0)
8000063C	nop
80000640	lui    at, $801c
80000644	sh     v0, $d918(at)
80000648	jal    $800d4d90
8000064C	addiu  a1, a1, $0070
80000650	lui    v1, $8006
80000654	lbu    v1, $2d98(v1)
80000658	lui    at, $801d
8000065C	sw     v0, $5964(at)
80000660	bne    v1, zero, L06b8 [$800006b8]
80000664	nop
80000668	lhu    v1, $0002(s0)
8000066C	lh     a0, $001a(s0)
80000670	addiu  v1, v1, $0001
80000674	sll    v0, a0, $02
80000678	addu   v0, v0, s1
8000067C	sh     v1, $0002(s0)
80000680	lw     v0, $0000(v0)
80000684	sll    v1, v1, $10
80000688	lw     v0, $0004(v0)
8000068C	sra    v1, v1, $10
80000690	slt    v1, v1, v0
80000694	bne    v1, zero, L06b8 [$800006b8]
80000698	nop
8000069C	bne    a0, zero, L06b4 [$800006b4]
800006A0	addiu  v0, zero, $ffff (=-$1)
800006A4	ori    v0, zero, $0001
800006A8	sh     v0, $001a(s0)
800006AC	j      $801b06b8
800006B0	sh     zero, $0002(s0)

L06b4:	; 800006B4
800006B4	sh     v0, $0000(s0)

L06b8:	; 800006B8
800006B8	lw     ra, $0020(sp)
800006BC	lw     s1, $001c(sp)
800006C0	lw     s0, $0018(sp)
800006C4	addiu  sp, sp, $0028
800006C8	jr     ra 
800006CC	nop

800006D0	addiu  sp, sp, $ff70 (=-$90)
800006D4	lui    v0, $8015
800006D8	lh     v0, $169c(v0)
800006DC	lui    v1, $8016
800006E0	addiu  v1, v1, $2978
800006E4	sw     ra, $0088(sp)
800006E8	sw     s1, $0084(sp)
800006EC	sw     s0, $0080(sp)
800006F0	sll    v0, v0, $05
800006F4	addu   s1, v0, v1
800006F8	lh     a0, $0002(s1)
800006FC	lhu    s0, $0016(s1)
80000700	sll    a0, a0, $08
80000704	sll    s0, s0, $10
80000708	sra    s0, s0, $11
8000070C	sll    s0, s0, $01
80000710	jal    $80039a74
80000714	addiu  s0, s0, $ffff (=-$1)
80000718	lui    v1, $6666
8000071C	ori    v1, v1, $6667
80000720	mult   v0, v1
80000724	sra    v0, v0, $1f
80000728	sll    s0, s0, $10
8000072C	sra    s0, s0, $10
80000730	mfhi   v1
80000734	sra    v1, v1, $04
80000738	subu   v1, v1, v0
8000073C	mult   v1, s0
80000740	mflo   v0
80000744	sh     v0, $0050(sp)
80000748	sh     v0, $0058(sp)
8000074C	lh     a0, $0002(s1)
80000750	jal    $80039a74
80000754	sll    a0, a0, $07
80000758	sra    v0, v0, $04
8000075C	mult   v0, s0
80000760	addiu  a0, sp, $0050
80000764	lhu    v0, $0050(sp)
80000768	addiu  a1, sp, $0010
8000076C	sh     zero, $0054(sp)
80000770	sh     zero, $005c(sp)
80000774	addiu  v0, v0, $fc00 (=-$400)
80000778	sh     v0, $0050(sp)
8000077C	mflo   v0
80000780	sh     v0, $0052(sp)
80000784	jal    $8003c21c
80000788	sh     v0, $005a(sp)
8000078C	lui    a0, $801c
80000790	addiu  a0, a0, $d940 (=-$26c0)
80000794	addiu  a1, sp, $0010
80000798	jal    $8003a79c
8000079C	addu   a2, a1, zero
800007A0	lh     v0, $0014(s1)
800007A4	nop
800007A8	sw     v0, $006c(sp)
800007AC	lhu    v0, $0016(s1)
800007B0	nop
800007B4	andi   v0, v0, $0001
800007B8	bne    v0, zero, L07c4 [$800007c4]
800007BC	ori    v1, zero, $4000
800007C0	ori    v1, zero, $3000

L07c4:	; 800007C4
800007C4	addiu  a0, sp, $0010
800007C8	addiu  a1, sp, $0068
800007CC	sw     v1, $0070(sp)
800007D0	jal    $8003b35c
800007D4	sw     v1, $0068(sp)
800007D8	lh     v0, $0004(s1)
800007DC	lui    a0, $8010
800007E0	addiu  a0, a0, $a63c (=-$59c4)
800007E4	sw     v0, $0024(sp)
800007E8	lh     v0, $0006(s1)
800007EC	addiu  a1, sp, $0010
800007F0	sw     v0, $0028(sp)
800007F4	lh     v0, $0008(s1)
800007F8	addu   a2, a1, zero
800007FC	jal    $8003a63c
80000800	sw     v0, $002c(sp)
80000804	jal    $8003b48c
80000808	addiu  a0, sp, $0010
8000080C	jal    $8003b51c
80000810	addiu  a0, sp, $0010
80000814	addu   a0, zero, zero
80000818	addu   a1, zero, zero
8000081C	jal    $8003b69c
80000820	addu   a2, zero, zero
80000824	lui    v1, $801c
80000828	addiu  v1, v1, $ce38 (=-$31c8)
8000082C	lhu    v0, $0016(s1)
80000830	lui    a0, $801c
80000834	addiu  a0, a0, $d920 (=-$26e0)
80000838	andi   v0, v0, $0001
8000083C	bne    v0, zero, L084c [$8000084c]
80000840	addiu  a1, a0, $000a
80000844	lui    v1, $801c
80000848	addiu  v1, v1, $d21c (=-$2de4)

L084c:	; 8000084C
8000084C	sw     v1, $0000(a0)
80000850	lhu    v0, $0016(s1)
80000854	nop
80000858	andi   v0, v0, $0001
8000085C	bne    v0, zero, L087c [$8000087c]
80000860	ori    v1, zero, $1000
80000864	lui    v0, $801c
80000868	lh     v0, $d91c(v0)
8000086C	nop
80000870	sll    v0, v0, $05
80000874	j      $801b089c
80000878	subu   v0, v1, v0

L087c:	; 8000087C
8000087C	lui    v0, $801c
80000880	lh     v0, $d91c(v0)
80000884	nop
80000888	sll    v1, v0, $01
8000088C	addu   v1, v1, v0
80000890	sll    v1, v1, $03
80000894	ori    v0, zero, $1000
80000898	subu   v0, v0, v1
8000089C	lui    a0, $801c
800008A0	addiu  a0, a0, $d920 (=-$26e0)
800008A4	ori    a2, zero, $000c
800008A8	sh     v0, $0000(a1)
800008AC	lui    a1, $8015
800008B0	lw     a1, $17c0(a1)
800008B4	lui    a3, $801d
800008B8	lw     a3, $5964(a3)
800008BC	jal    $800d29d4
800008C0	addiu  a1, a1, $0070
800008C4	lui    v1, $8006
800008C8	lbu    v1, $2d98(v1)
800008CC	lui    at, $801d
800008D0	sw     v0, $5964(at)
800008D4	bne    v1, zero, L0a30 [$80000a30]
800008D8	nop
800008DC	lhu    v0, $0016(s1)
800008E0	nop
800008E4	andi   v0, v0, $0001
800008E8	bne    v0, zero, L09b0 [$800009b0]
800008EC	nop
800008F0	lui    a0, $801b
800008F4	addiu  a0, a0, $05b4
800008F8	jal    $800bbeac
800008FC	nop
80000900	sll    s0, v0, $05
80000904	lui    v0, $8016
80000908	addiu  v0, v0, $2978
8000090C	lhu    v1, $0004(s1)
80000910	addu   s0, s0, v0
80000914	sh     v1, $0004(s0)
80000918	lhu    v0, $0006(s1)
8000091C	nop
80000920	sh     v0, $0006(s0)
80000924	lhu    v0, $0008(s1)
80000928	addiu  a0, sp, $0058
8000092C	sh     v0, $0008(s0)
80000930	sh     zero, $0060(sp)
80000934	sh     zero, $0062(sp)
80000938	lhu    v0, $0018(s1)
8000093C	addiu  a1, sp, $0010
80000940	jal    $8003c21c
80000944	sh     v0, $0064(sp)
80000948	lui    a0, $801c
8000094C	addiu  a0, a0, $d940 (=-$26c0)
80000950	addiu  a1, sp, $0010
80000954	jal    $8003a79c
80000958	addu   a2, a1, zero
8000095C	lh     v0, $0004(s0)
80000960	nop
80000964	sw     v0, $0024(sp)
80000968	lh     v0, $0006(s0)
8000096C	nop
80000970	sw     v0, $0028(sp)
80000974	lh     v0, $0008(s0)
80000978	addiu  a0, sp, $0010
8000097C	jal    $8003b48c
80000980	sw     v0, $002c(sp)
80000984	jal    $8003b51c
80000988	addiu  a0, sp, $0010
8000098C	addiu  a0, sp, $0060
80000990	addiu  a1, s0, $0004
80000994	jal    $8003badc
80000998	addiu  a2, sp, $0078
8000099C	sh     zero, $000c(s0)
800009A0	lhu    v0, $000e(s1)
800009A4	sh     zero, $0010(s0)
800009A8	sh     zero, $001a(s0)
800009AC	sh     v0, $000e(s0)

L09b0:	; 800009B0
800009B0	lh     v0, $0002(s1)
800009B4	nop
800009B8	slti   v0, v0, $0008
800009BC	beq    v0, zero, L09dc [$800009dc]
800009C0	nop
800009C4	lui    v0, $801c
800009C8	lhu    v0, $d91c(v0)
800009CC	nop
800009D0	addiu  v0, v0, $0001
800009D4	lui    at, $801c
800009D8	sh     v0, $d91c(at)

L09dc:	; 800009DC
800009DC	lh     v0, $0002(s1)
800009E0	nop
800009E4	slti   v0, v0, $0019
800009E8	bne    v0, zero, L0a08 [$80000a08]
800009EC	ori    v1, zero, $0020
800009F0	lui    v0, $801c
800009F4	lhu    v0, $d91c(v0)
800009F8	nop
800009FC	addiu  v0, v0, $ffff (=-$1)
80000A00	lui    at, $801c
80000A04	sh     v0, $d91c(at)

L0a08:	; 80000A08
80000A08	lhu    v0, $0002(s1)
80000A0C	nop
80000A10	addiu  v0, v0, $0001
80000A14	sh     v0, $0002(s1)
80000A18	sll    v0, v0, $10
80000A1C	sra    v0, v0, $10
80000A20	bne    v0, v1, L0a30 [$80000a30]
80000A24	nop
80000A28	addiu  v0, zero, $ffff (=-$1)
80000A2C	sh     v0, $0000(s1)

L0a30:	; 80000A30
80000A30	lw     ra, $0088(sp)
80000A34	lw     s1, $0084(sp)
80000A38	lw     s0, $0080(sp)
80000A3C	addiu  sp, sp, $0090
80000A40	jr     ra 
80000A44	nop

80000A48	addiu  sp, sp, $ffa0 (=-$60)
80000A4C	lui    v0, $8015
80000A50	lh     v0, $169c(v0)
80000A54	lui    a0, $8006
80000A58	lbu    a0, $2d98(a0)
80000A5C	lui    v1, $8016
80000A60	addiu  v1, v1, $2978
80000A64	sw     ra, $0058(sp)
80000A68	sw     s5, $0054(sp)
80000A6C	sw     s4, $0050(sp)
80000A70	sw     s3, $004c(sp)
80000A74	sw     s2, $0048(sp)
80000A78	sw     s1, $0044(sp)
80000A7C	sw     s0, $0040(sp)
80000A80	sll    v0, v0, $05
80000A84	bne    a0, zero, L0c6c [$80000c6c]
80000A88	addu   s1, v0, v1
80000A8C	lh     v0, $0002(s1)
80000A90	nop
80000A94	bne    v0, zero, L0be4 [$80000be4]
80000A98	nop
80000A9C	lhu    v1, $000c(s1)
80000AA0	lhu    v0, $0004(s1)
80000AA4	nop
80000AA8	subu   v1, v1, v0
80000AAC	sll    v0, v1, $10
80000AB0	sra    v0, v0, $10
80000AB4	mult   v0, v0
80000AB8	lui    at, $801c
80000ABC	sh     v1, $d938(at)
80000AC0	lhu    v1, $000e(s1)
80000AC4	lhu    v0, $0006(s1)
80000AC8	nop
80000ACC	subu   v1, v1, v0
80000AD0	mflo   a1
80000AD4	sll    v0, v1, $10
80000AD8	sra    v0, v0, $10
80000ADC	mult   v0, v0
80000AE0	lui    at, $801c
80000AE4	sh     v1, $d93a(at)
80000AE8	lhu    v1, $0010(s1)
80000AEC	lhu    v0, $0008(s1)
80000AF0	nop
80000AF4	subu   v1, v1, v0
80000AF8	mflo   a0
80000AFC	sll    v0, v1, $10
80000B00	sra    v0, v0, $10
80000B04	mult   v0, v0
80000B08	addu   s2, zero, zero
80000B0C	lui    at, $801c
80000B10	sh     v1, $d93c(at)
80000B14	addu   a1, a1, a0
80000B18	mflo   a0
80000B1C	jal    $80039f5c
80000B20	addu   a0, a1, a0
80000B24	addu   s5, v0, zero
80000B28	sll    v0, v0, $10
80000B2C	sra    v0, v0, $10
80000B30	sll    v1, v0, $02
80000B34	addu   v1, v1, v0
80000B38	sll    v1, v1, $02
80000B3C	addu   v1, v1, v0
80000B40	sll    s3, v1, $08
80000B44	sra    s4, s3, $1f

loop0b48:	; 80000B48
80000B48	lui    a0, $801b
80000B4C	addiu  a0, a0, $06d0
80000B50	jal    $800bbeac
80000B54	nop
80000B58	sll    s0, v0, $05
80000B5C	lui    v0, $8016
80000B60	addiu  v0, v0, $2978
80000B64	lhu    v1, $0004(s1)
80000B68	addu   s0, s0, v0
80000B6C	sh     v1, $0004(s0)
80000B70	lhu    v0, $0006(s1)
80000B74	nop
80000B78	sh     v0, $0006(s0)
80000B7C	lhu    v0, $0008(s1)
80000B80	nop
80000B84	sh     v0, $0008(s0)
80000B88	lh     v1, $000c(s1)
80000B8C	lh     a0, $0004(s1)
80000B90	lh     v0, $0010(s1)
80000B94	lh     a1, $0008(s1)
80000B98	subu   a0, v1, a0
80000B9C	jal    $8003cc1c
80000BA0	subu   a1, v0, a1
80000BA4	lui    v1, $5d9f
80000BA8	ori    v1, v1, $7391
80000BAC	mult   s3, v1
80000BB0	addiu  v1, s2, $0001
80000BB4	sh     s2, $0016(s0)
80000BB8	addu   s2, v1, zero
80000BBC	sll    v1, v1, $10
80000BC0	sra    v1, v1, $10
80000BC4	slti   v1, v1, $0004
80000BC8	sh     v0, $000e(s0)
80000BCC	sh     s5, $0018(s0)
80000BD0	mfhi   v0
80000BD4	sra    v0, v0, $0a
80000BD8	subu   v0, v0, s4
80000BDC	bne    v1, zero, loop0b48 [$80000b48]
80000BE0	sh     v0, $0014(s0)

L0be4:	; 80000BE4
80000BE4	lh     v1, $0002(s1)
80000BE8	ori    v0, zero, $0020
80000BEC	bne    v1, v0, L0c3c [$80000c3c]
80000BF0	nop
80000BF4	addu   s2, zero, zero

loop0bf8:	; 80000BF8
80000BF8	lui    v1, $8015
80000BFC	lh     v1, $1774(v1)
80000C00	sll    v0, s2, $10
80000C04	sra    a0, v0, $10
80000C08	srav   v1, a0, v1
80000C0C	andi   v1, v1, $0001
80000C10	beq    v1, zero, L0c24 [$80000c24]
80000C14	addiu  v0, s2, $0001
80000C18	jal    $800d5774
80000C1C	nop
80000C20	addiu  v0, s2, $0001

L0c24:	; 80000C24
80000C24	addu   s2, v0, zero
80000C28	sll    v0, v0, $10
80000C2C	sra    v0, v0, $10
80000C30	slti   v0, v0, $000a
80000C34	bne    v0, zero, loop0bf8 [$80000bf8]
80000C38	nop

L0c3c:	; 80000C3C
80000C3C	lhu    v0, $0002(s1)
80000C40	ori    v1, zero, $0028
80000C44	addiu  v0, v0, $0001
80000C48	sh     v0, $0002(s1)
80000C4C	sll    v0, v0, $10
80000C50	sra    v0, v0, $10
80000C54	bne    v0, v1, L0c6c [$80000c6c]
80000C58	addiu  v0, zero, $ffff (=-$1)
80000C5C	sh     v0, $0000(s1)
80000C60	addu   a0, zero, zero
80000C64	jal    $800d52a0
80000C68	ori    a1, zero, $000a

L0c6c:	; 80000C6C
80000C6C	lw     ra, $0058(sp)
80000C70	lw     s5, $0054(sp)
80000C74	lw     s4, $0050(sp)
80000C78	lw     s3, $004c(sp)
80000C7C	lw     s2, $0048(sp)
80000C80	lw     s1, $0044(sp)
80000C84	lw     s0, $0040(sp)
80000C88	addiu  sp, sp, $0060
80000C8C	jr     ra 
80000C90	nop

80000C94	addiu  sp, sp, $ffd8 (=-$28)
80000C98	sw     s1, $001c(sp)
80000C9C	addu   s1, a0, zero
80000CA0	sw     s2, $0020(sp)
80000CA4	addu   s2, a1, zero
80000CA8	lui    a0, $801b
80000CAC	addiu  a0, a0, $0dd8
80000CB0	addu   a1, zero, zero
80000CB4	addu   a2, zero, zero
80000CB8	addu   a3, zero, zero
80000CBC	sw     ra, $0024(sp)
80000CC0	jal    $800d2980
80000CC4	sw     s0, $0018(sp)
80000CC8	lui    a0, $801b
80000CCC	addiu  a0, a0, $0464
80000CD0	jal    $800bbeac
80000CD4	nop
80000CD8	lui    a0, $801b
80000CDC	addiu  a0, a0, $0a48
80000CE0	lui    at, $801c
80000CE4	sh     s1, $d960(at)
80000CE8	jal    $800bbeac
80000CEC	sll    s1, s1, $10
80000CF0	addu   a0, s2, zero
80000CF4	sll    a1, s2, $01
80000CF8	addu   a1, a1, s2
80000CFC	sll    v1, a1, $05
80000D00	subu   v1, v1, a1
80000D04	sll    v1, v1, $03
80000D08	subu   v1, v1, s2
80000D0C	sll    v1, v1, $02
80000D10	sll    s0, v0, $05
80000D14	lui    v0, $8016
80000D18	addiu  v0, v0, $2978
80000D1C	addu   s0, s0, v0
80000D20	lui    at, $8015
80000D24	addiu  at, at, $1918
80000D28	addu   at, at, v1
80000D2C	lbu    a1, $0000(at)
80000D30	jal    $800d3994
80000D34	addiu  a2, s0, $0004
80000D38	sra    a0, s1, $10
80000D3C	jal    $801b0028
80000D40	addiu  a1, s0, $000c
80000D44	lhu    v0, $000c(s0)
80000D48	lhu    v1, $0004(s0)
80000D4C	nop
80000D50	subu   v0, v0, v1
80000D54	sh     v0, $0010(sp)
80000D58	lhu    v0, $000e(s0)
80000D5C	lhu    v1, $0006(s0)
80000D60	addiu  a0, sp, $0010
80000D64	subu   v0, v0, v1
80000D68	sh     v0, $0012(sp)
80000D6C	lhu    v0, $0010(s0)
80000D70	lhu    v1, $0008(s0)
80000D74	lui    a1, $801c
80000D78	addiu  a1, a1, $d940 (=-$26c0)
80000D7C	subu   v0, v0, v1
80000D80	jal    $800d44e8
80000D84	sh     v0, $0014(sp)
80000D88	ori    a0, zero, $0400
80000D8C	lui    at, $800f
80000D90	sb     zero, $5b72(at)
80000D94	lui    at, $800f
80000D98	sb     zero, $5b71(at)
80000D9C	lui    at, $800f
80000DA0	sb     zero, $5b70(at)
80000DA4	jal    $800d52a0
80000DA8	ori    a1, zero, $000a
80000DAC	ori    a0, zero, $0062
80000DB0	addu   a1, s2, zero
80000DB4	jal    $800bba84
80000DB8	ori    a2, zero, $0040
80000DBC	lw     ra, $0024(sp)
80000DC0	lw     s2, $0020(sp)
80000DC4	lw     s1, $001c(sp)
80000DC8	lw     s0, $0018(sp)
80000DCC	addiu  sp, sp, $0028
80000DD0	jr     ra 
80000DD4	nop
