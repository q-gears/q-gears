
Entry:	; 80000000
80000000	addiu  sp, sp, $ffe8 (=-$18)
80000004	sw     ra, $0010(sp)
80000008	jal    $801b099c
8000000C	nop
80000010	lw     ra, $0010(sp)
80000014	addiu  sp, sp, $0018
80000018	jr     ra 
8000001C	nop

80000020	lui    v0, $8015
80000024	lh     v0, $169c(v0)
80000028	lui    v1, $8016
8000002C	addiu  v1, v1, $2978
80000030	sll    v0, v0, $05
80000034	addu   a0, v0, v1
80000038	lh     v1, $0002(a0)
8000003C	nop
80000040	sll    v0, v1, $01
80000044	addu   v0, v0, v1
80000048	sll    v0, v0, $0e
8000004C	lui    v1, $801b
80000050	addiu  v1, v1, $3d20
80000054	addu   v0, v0, v1
80000058	lui    at, $801d
8000005C	sw     v0, $bd20(at)
80000060	lhu    v0, $0002(a0)
80000064	lui    v1, $8016
80000068	lh     v1, $2080(v1)
8000006C	xori   v0, v0, $0001
80000070	slti   v1, v1, $0002
80000074	beq    v1, zero, L0084 [$80000084]
80000078	sh     v0, $0002(a0)
8000007C	addiu  v0, zero, $ffff (=-$1)
80000080	sh     v0, $0000(a0)

L0084:	; 80000084
80000084	jr     ra 
80000088	nop

8000008C	addiu  sp, sp, $ffc8 (=-$38)
80000090	lui    a0, $801b
80000094	addiu  a0, a0, $3cd0
80000098	addiu  a1, sp, $0010
8000009C	lui    v0, $8015
800000A0	lh     v0, $169c(v0)
800000A4	lui    v1, $8016
800000A8	addiu  v1, v1, $2978
800000AC	sw     ra, $0034(sp)
800000B0	sw     s0, $0030(sp)
800000B4	sll    v0, v0, $05
800000B8	jal    $8003c21c
800000BC	addu   s0, v0, v1
800000C0	lui    a0, $801d
800000C4	addiu  a0, a0, $bd24 (=-$42dc)
800000C8	addiu  a1, sp, $0010
800000CC	jal    $8003a79c
800000D0	addu   a2, a1, zero
800000D4	lui    a1, $801b
800000D8	addiu  a1, a1, $3cd8
800000DC	jal    $8003b35c
800000E0	addiu  a0, sp, $0010
800000E4	lh     v0, $0004(s0)
800000E8	lui    a0, $8010
800000EC	addiu  a0, a0, $a63c (=-$59c4)
800000F0	sw     v0, $0024(sp)
800000F4	lh     v0, $0006(s0)
800000F8	addiu  a1, sp, $0010
800000FC	sw     v0, $0028(sp)
80000100	lh     v0, $0008(s0)
80000104	addu   a2, a1, zero
80000108	jal    $8003a63c
8000010C	sw     v0, $002c(sp)
80000110	jal    $8003b48c
80000114	addiu  a0, sp, $0010
80000118	jal    $8003b51c
8000011C	addiu  a0, sp, $0010
80000120	lh     v0, $0002(s0)
80000124	lui    v1, $801b
80000128	lw     v1, $3c60(v1)
8000012C	nop
80000130	div    v0, v1
80000134	bne    v1, zero, L0140 [$80000140]
80000138	nop
8000013C	break   $01c00

L0140:	; 80000140
80000140	addiu  at, zero, $ffff (=-$1)
80000144	bne    v1, at, L0158 [$80000158]
80000148	lui    at, $8000
8000014C	bne    v0, at, L0158 [$80000158]
80000150	nop
80000154	break   $01800

L0158:	; 80000158
80000158	mfhi   v1
8000015C	ori    a2, zero, $000c
80000160	lui    a1, $8015
80000164	lw     a1, $17c0(a1)
80000168	lui    a3, $801d
8000016C	lw     a3, $bd20(a3)
80000170	lui    v0, $801b
80000174	addiu  v0, v0, $3ccc
80000178	addiu  a0, v0, $fff8 (=-$8)
8000017C	addiu  a1, a1, $0070
80000180	jal    $800d4d90
80000184	sh     v1, $0000(v0)
80000188	lui    v1, $8006
8000018C	lbu    v1, $2d98(v1)
80000190	lui    at, $801d
80000194	sw     v0, $bd20(at)
80000198	bne    v1, zero, L01c4 [$800001c4]
8000019C	ori    v1, zero, $0014
800001A0	lhu    v0, $0002(s0)
800001A4	nop
800001A8	addiu  v0, v0, $0001
800001AC	sh     v0, $0002(s0)
800001B0	sll    v0, v0, $10
800001B4	sra    v0, v0, $10
800001B8	bne    v0, v1, L01c4 [$800001c4]
800001BC	addiu  v0, zero, $ffff (=-$1)
800001C0	sh     v0, $0000(s0)

L01c4:	; 800001C4
800001C4	lw     ra, $0034(sp)
800001C8	lw     s0, $0030(sp)
800001CC	addiu  sp, sp, $0038
800001D0	jr     ra 
800001D4	nop

800001D8	addiu  sp, sp, $ffe8 (=-$18)
800001DC	ori    a1, zero, $1000
800001E0	lui    v0, $8015
800001E4	lh     v0, $169c(v0)
800001E8	lui    v1, $8016
800001EC	addiu  v1, v1, $2978
800001F0	sw     ra, $0014(sp)
800001F4	sw     s0, $0010(sp)
800001F8	sll    v0, v0, $05
800001FC	addu   s0, v0, v1
80000200	lh     a2, $0016(s0)
80000204	jal    $800d4368
80000208	addiu  a0, s0, $0004
8000020C	lui    v1, $801b
80000210	addiu  v1, v1, $3cf0
80000214	addiu  a0, v1, $fff8 (=-$8)
80000218	ori    a2, zero, $000c
8000021C	lhu    v0, $0002(s0)
80000220	lui    a1, $8015
80000224	lw     a1, $17c0(a1)
80000228	lui    a3, $801d
8000022C	lw     a3, $bd20(a3)
80000230	addiu  a1, a1, $0070
80000234	jal    $800d4d90
80000238	sh     v0, $0000(v1)
8000023C	lui    v1, $8006
80000240	lbu    v1, $2d98(v1)
80000244	lui    at, $801d
80000248	sw     v0, $bd20(at)
8000024C	bne    v1, zero, L0280 [$80000280]
80000250	nop
80000254	lhu    v0, $0002(s0)
80000258	lui    v1, $801b
8000025C	lw     v1, $1b58(v1)
80000260	addiu  v0, v0, $0001
80000264	sh     v0, $0002(s0)
80000268	sll    v0, v0, $10
8000026C	sra    v0, v0, $10
80000270	slt    v0, v0, v1
80000274	bne    v0, zero, L0280 [$80000280]
80000278	addiu  v0, zero, $ffff (=-$1)
8000027C	sh     v0, $0000(s0)

L0280:	; 80000280
80000280	lw     ra, $0014(sp)
80000284	lw     s0, $0010(sp)
80000288	addiu  sp, sp, $0018
8000028C	jr     ra 
80000290	nop

80000294	addiu  sp, sp, $ffa8 (=-$58)
80000298	lui    a0, $801b
8000029C	addiu  a0, a0, $3d14
800002A0	addiu  a1, sp, $0010
800002A4	lui    v0, $8015
800002A8	lh     v0, $169c(v0)
800002AC	lui    v1, $8016
800002B0	addiu  v1, v1, $2978
800002B4	sw     ra, $0054(sp)
800002B8	sw     s0, $0050(sp)
800002BC	sll    v0, v0, $05
800002C0	jal    $8003bf8c
800002C4	addu   s0, v0, v1
800002C8	lui    a0, $801d
800002CC	addiu  a0, a0, $bd24 (=-$42dc)
800002D0	addiu  a1, sp, $0010
800002D4	jal    $8003a79c
800002D8	addu   a2, a1, zero
800002DC	lui    a1, $801b
800002E0	addiu  a1, a1, $3cf4
800002E4	jal    $8003b35c
800002E8	addiu  a0, sp, $0010
800002EC	lh     v0, $0004(s0)
800002F0	lui    a0, $8010
800002F4	addiu  a0, a0, $a63c (=-$59c4)
800002F8	sw     v0, $0024(sp)
800002FC	lh     v0, $0006(s0)
80000300	addiu  a1, sp, $0010
80000304	sw     v0, $0028(sp)
80000308	lh     v0, $0008(s0)
8000030C	addu   a2, a1, zero
80000310	jal    $8003a63c
80000314	sw     v0, $002c(sp)
80000318	jal    $8003b48c
8000031C	addiu  a0, sp, $0010
80000320	jal    $8003b51c
80000324	addiu  a0, sp, $0010
80000328	addu   a0, zero, zero
8000032C	addu   a1, zero, zero
80000330	jal    $8003b69c
80000334	addu   a2, zero, zero
80000338	lui    a0, $801b
8000033C	addiu  a0, a0, $3d04
80000340	ori    a2, zero, $000c
80000344	lui    a1, $8015
80000348	lw     a1, $17c0(a1)
8000034C	lui    a3, $801d
80000350	lw     a3, $bd20(a3)
80000354	jal    $800d29d4
80000358	addiu  a1, a1, $0070
8000035C	lui    v1, $8006
80000360	lbu    v1, $2d98(v1)
80000364	lui    at, $801d
80000368	sw     v0, $bd20(at)
8000036C	bne    v1, zero, L03c8 [$800003c8]
80000370	nop
80000374	lhu    v0, $0004(s0)
80000378	lhu    a0, $000c(s0)
8000037C	lhu    v1, $0006(s0)
80000380	lhu    a1, $000e(s0)
80000384	addu   v0, v0, a0
80000388	addu   v1, v1, a1
8000038C	sh     v1, $0006(s0)
80000390	lhu    v1, $0008(s0)
80000394	lhu    a0, $0010(s0)
80000398	sh     v0, $0004(s0)
8000039C	lhu    v0, $0002(s0)
800003A0	addu   v1, v1, a0
800003A4	addiu  v0, v0, $0001
800003A8	sh     v0, $0002(s0)
800003AC	sll    v0, v0, $10
800003B0	sra    v0, v0, $10
800003B4	sh     v1, $0008(s0)
800003B8	ori    v1, zero, $0007
800003BC	bne    v0, v1, L03c8 [$800003c8]
800003C0	addiu  v0, zero, $ffff (=-$1)
800003C4	sh     v0, $0000(s0)

L03c8:	; 800003C8
800003C8	lw     ra, $0054(sp)
800003CC	lw     s0, $0050(sp)
800003D0	addiu  sp, sp, $0058
800003D4	jr     ra 
800003D8	nop

800003DC	lui    v0, $8015
800003E0	lh     v0, $169c(v0)
800003E4	lui    v1, $8006
800003E8	lbu    v1, $2d98(v1)
800003EC	addiu  sp, sp, $ff90 (=-$70)
800003F0	sw     s1, $005c(sp)
800003F4	lui    s1, $8016
800003F8	addiu  s1, s1, $2978
800003FC	sw     ra, $0068(sp)
80000400	sw     s3, $0064(sp)
80000404	sw     s2, $0060(sp)
80000408	sw     s0, $0058(sp)
8000040C	sll    v0, v0, $05
80000410	bne    v1, zero, L0844 [$80000844]
80000414	addu   s2, v0, s1
80000418	lh     v0, $0002(s2)
8000041C	nop
80000420	bne    v0, zero, L04cc [$800004cc]
80000424	slti   v0, v0, $000f
80000428	ori    v0, zero, $01f4
8000042C	sh     zero, $0028(sp)
80000430	sh     zero, $002a(sp)
80000434	sh     v0, $002c(sp)
80000438	lh     v0, $0004(s2)
8000043C	lui    s0, $801d
80000440	addiu  s0, s0, $bd38 (=-$42c8)
80000444	sw     v0, $0000(s0)
80000448	lh     v0, $0006(s2)
8000044C	addiu  s0, s0, $ffec (=-$14)
80000450	lui    at, $801d
80000454	sw     v0, $bd3c(at)
80000458	lh     v0, $0008(s2)
8000045C	nop
80000460	lui    at, $801d
80000464	sw     v0, $bd40(at)
80000468	jal    $8003b48c
8000046C	addu   a0, s0, zero
80000470	jal    $8003b51c
80000474	addu   a0, s0, zero
80000478	addiu  a0, sp, $0028
8000047C	addiu  a1, s2, $0004
80000480	jal    $8003badc
80000484	addiu  a2, sp, $0050
80000488	lui    a0, $801b
8000048C	addiu  a0, a0, $008c
80000490	jal    $800bbeac
80000494	nop
80000498	sll    v0, v0, $05
8000049C	lhu    v1, $0004(s2)
800004A0	addu   s1, v0, s1
800004A4	sh     v1, $0004(s1)
800004A8	lhu    v0, $0006(s2)
800004AC	nop
800004B0	sh     v0, $0006(s1)
800004B4	lhu    v0, $0008(s2)
800004B8	nop
800004BC	sh     v0, $0008(s1)
800004C0	lh     v0, $0002(s2)
800004C4	nop
800004C8	slti   v0, v0, $000f

L04cc:	; 800004CC
800004CC	beq    v0, zero, L067c [$8000067c]
800004D0	nop
800004D4	lh     v0, $0004(s2)
800004D8	lui    s0, $801d
800004DC	addiu  s0, s0, $bd38 (=-$42c8)
800004E0	sw     v0, $0000(s0)
800004E4	lh     v0, $0006(s2)
800004E8	addiu  s0, s0, $ffec (=-$14)
800004EC	lui    at, $801d
800004F0	sw     v0, $bd3c(at)
800004F4	lh     v0, $0008(s2)
800004F8	nop
800004FC	lui    at, $801d
80000500	sw     v0, $bd40(at)
80000504	jal    $8003b48c
80000508	addu   a0, s0, zero
8000050C	jal    $8003b51c
80000510	addu   a0, s0, zero
80000514	lh     v1, $000c(s2)
80000518	lh     v0, $0004(s2)
8000051C	nop
80000520	subu   v0, v1, v0
80000524	bgez   v0, L0530 [$80000530]
80000528	nop
8000052C	addiu  v0, v0, $0007

L0530:	; 80000530
80000530	sra    v0, v0, $03
80000534	sh     v0, $0020(sp)
80000538	lh     v1, $000e(s2)
8000053C	lh     v0, $0006(s2)
80000540	nop
80000544	subu   v0, v1, v0
80000548	bgez   v0, L0554 [$80000554]
8000054C	nop
80000550	addiu  v0, v0, $0007

L0554:	; 80000554
80000554	sra    v0, v0, $03
80000558	sh     v0, $0022(sp)
8000055C	lh     v1, $0010(s2)
80000560	lh     v0, $0008(s2)
80000564	nop
80000568	subu   v0, v1, v0
8000056C	bgez   v0, L0578 [$80000578]
80000570	addu   s3, zero, zero
80000574	addiu  v0, v0, $0007

L0578:	; 80000578
80000578	sra    v0, v0, $03
8000057C	sh     v0, $0024(sp)

loop0580:	; 80000580
80000580	lui    a0, $801b
80000584	addiu  a0, a0, $0294
80000588	jal    $800bbeac
8000058C	nop
80000590	sll    v0, v0, $05
80000594	lui    v1, $8016
80000598	addiu  v1, v1, $2978
8000059C	addu   s1, v0, v1
800005A0	sll    v0, s3, $10
800005A4	sra    v0, v0, $10
800005A8	sll    s0, v0, $02
800005AC	addu   s0, s0, v0
800005B0	sll    s0, s0, $02
800005B4	addu   s0, s0, v0
800005B8	sll    v0, s0, $06
800005BC	lh     a0, $0002(s2)
800005C0	addu   s0, s0, v0
800005C4	sll    a0, a0, $09
800005C8	jal    $80039b40
800005CC	addu   a0, a0, s0
800005D0	sra    v0, v0, $05
800005D4	sh     v0, $0018(sp)
800005D8	lh     a0, $0002(s2)
800005DC	nop
800005E0	sll    a0, a0, $09
800005E4	jal    $80039a74
800005E8	addu   a0, a0, s0
800005EC	sra    v0, v0, $05
800005F0	jal    $80042da8
800005F4	sh     v0, $001a(sp)
800005F8	lui    v1, $51eb
800005FC	ori    v1, v1, $851f
80000600	mult   v0, v1
80000604	addiu  a0, sp, $0018
80000608	addiu  a1, s1, $0004
8000060C	addiu  a2, sp, $0050
80000610	sra    v1, v0, $1f
80000614	mfhi   a3
80000618	sra    a3, a3, $05
8000061C	subu   a3, a3, v1
80000620	sll    v1, a3, $01
80000624	addu   v1, v1, a3
80000628	sll    v1, v1, $03
8000062C	addu   v1, v1, a3
80000630	sll    v1, v1, $02
80000634	subu   v0, v0, v1
80000638	addiu  v0, v0, $ffce (=-$32)
8000063C	jal    $8003badc
80000640	sh     v0, $001c(sp)
80000644	lhu    v0, $0020(sp)
80000648	nop
8000064C	sh     v0, $000c(s1)
80000650	lhu    v0, $0022(sp)
80000654	nop
80000658	sh     v0, $000e(s1)
8000065C	addiu  v0, s3, $0001
80000660	addu   s3, v0, zero
80000664	sll    v0, v0, $10
80000668	sra    v0, v0, $10
8000066C	lhu    v1, $0024(sp)
80000670	slti   v0, v0, $0003
80000674	bne    v0, zero, loop0580 [$80000580]
80000678	sh     v1, $0010(s1)

L067c:	; 8000067C
8000067C	lhu    v0, $0002(s2)
80000680	nop
80000684	addiu  v0, v0, $fff7 (=-$9)
80000688	sltiu  v0, v0, $0013
8000068C	beq    v0, zero, L0804 [$80000804]
80000690	nop
80000694	lui    a0, $801b
80000698	addiu  a0, a0, $01d8
8000069C	jal    $800bbeac
800006A0	lui    s0, $51eb
800006A4	sll    v0, v0, $05
800006A8	lui    v1, $8016
800006AC	addiu  v1, v1, $2978
800006B0	addu   s1, v0, v1
800006B4	addiu  a2, s1, $0004
800006B8	lui    a1, $8010
800006BC	lbu    a1, $a6d4(a1)
800006C0	lh     a0, $001c(s2)
800006C4	sll    v1, a1, $01
800006C8	addu   v1, v1, a1
800006CC	sll    v0, v1, $05
800006D0	subu   v0, v0, v1
800006D4	sll    v0, v0, $03
800006D8	subu   v0, v0, a1
800006DC	sll    v0, v0, $02
800006E0	lui    at, $8015
800006E4	addiu  at, at, $190f
800006E8	addu   at, at, v0
800006EC	lbu    a1, $0000(at)
800006F0	jal    $800d3994
800006F4	ori    s0, s0, $851f
800006F8	jal    $80042da8
800006FC	nop
80000700	mult   v0, s0
80000704	lhu    a1, $0004(s1)
80000708	sra    v1, v0, $1f
8000070C	addiu  a1, a1, $fe70 (=-$190)
80000710	mfhi   a0
80000714	sra    a0, a0, $08
80000718	subu   a0, a0, v1
8000071C	sll    v1, a0, $01
80000720	addu   v1, v1, a0
80000724	sll    v1, v1, $03
80000728	addu   v1, v1, a0
8000072C	sll    v1, v1, $05
80000730	subu   v0, v0, v1
80000734	addu   a1, a1, v0
80000738	jal    $80042da8
8000073C	sh     a1, $0004(s1)
80000740	mult   v0, s0
80000744	lhu    a1, $0006(s1)
80000748	sra    v1, v0, $1f
8000074C	addiu  a1, a1, $fe70 (=-$190)
80000750	mfhi   a0
80000754	sra    a0, a0, $08
80000758	subu   a0, a0, v1
8000075C	sll    v1, a0, $01
80000760	addu   v1, v1, a0
80000764	sll    v1, v1, $03
80000768	addu   v1, v1, a0
8000076C	sll    v1, v1, $05
80000770	subu   v0, v0, v1
80000774	addu   a1, a1, v0
80000778	jal    $80042da8
8000077C	sh     a1, $0006(s1)
80000780	mult   v0, s0
80000784	lhu    a1, $0008(s1)
80000788	ori    v1, zero, $3000
8000078C	sh     v1, $0014(s1)
80000790	sra    v1, v0, $1f
80000794	addiu  a1, a1, $fe70 (=-$190)
80000798	mfhi   a0
8000079C	sra    a0, a0, $08
800007A0	subu   a0, a0, v1
800007A4	sll    v1, a0, $01
800007A8	addu   v1, v1, a0
800007AC	sll    v1, v1, $03
800007B0	addu   v1, v1, a0
800007B4	sll    v1, v1, $05
800007B8	subu   v0, v0, v1
800007BC	lui    a0, $8010
800007C0	lbu    a0, $a6d4(a0)
800007C4	addu   a1, a1, v0
800007C8	sh     a1, $0008(s1)
800007CC	sll    v1, a0, $01
800007D0	addu   v1, v1, a0
800007D4	sll    v0, v1, $05
800007D8	subu   v0, v0, v1
800007DC	sll    v0, v0, $03
800007E0	subu   v0, v0, a0
800007E4	sll    v0, v0, $02
800007E8	lui    at, $8015
800007EC	addiu  at, at, $18f6
800007F0	addu   at, at, v0
800007F4	lhu    v0, $0000(at)
800007F8	nop
800007FC	subu   v0, zero, v0
80000800	sh     v0, $0016(s1)

L0804:	; 80000804
80000804	lh     v1, $0002(s2)
80000808	ori    v0, zero, $000f
8000080C	bne    v1, v0, L0820 [$80000820]
80000810	nop
80000814	lh     a0, $001c(s2)
80000818	jal    $800d5774
8000081C	nop

L0820:	; 80000820
80000820	lhu    v0, $0002(s2)
80000824	ori    v1, zero, $0028
80000828	addiu  v0, v0, $0001
8000082C	sh     v0, $0002(s2)
80000830	sll    v0, v0, $10
80000834	sra    v0, v0, $10
80000838	bne    v0, v1, L0844 [$80000844]
8000083C	addiu  v0, zero, $ffff (=-$1)
80000840	sh     v0, $0000(s2)

L0844:	; 80000844
80000844	lw     ra, $0068(sp)
80000848	lw     s3, $0064(sp)
8000084C	lw     s2, $0060(sp)
80000850	lw     s1, $005c(sp)
80000854	lw     s0, $0058(sp)
80000858	addiu  sp, sp, $0070
8000085C	jr     ra 
80000860	nop

80000864	addiu  sp, sp, $ffd8 (=-$28)
80000868	sw     s1, $001c(sp)
8000086C	addu   s1, a0, zero
80000870	sw     s0, $0018(sp)
80000874	lui    a0, $801b
80000878	addiu  a0, a0, $03dc
8000087C	sw     ra, $0020(sp)
80000880	jal    $800bbeac
80000884	addu   s0, a1, zero
80000888	addu   a0, s0, zero
8000088C	sll    a1, a0, $01
80000890	addu   a1, a1, a0
80000894	sll    v1, a1, $05
80000898	subu   v1, v1, a1
8000089C	sll    v1, v1, $03
800008A0	subu   v1, v1, a0
800008A4	sll    v1, v1, $02
800008A8	sll    v0, v0, $05
800008AC	lui    at, $8015
800008B0	addiu  at, at, $1915
800008B4	addu   at, at, v1
800008B8	lbu    a1, $0000(at)
800008BC	lui    v1, $8016
800008C0	addiu  v1, v1, $2978
800008C4	addu   s0, v0, v1
800008C8	jal    $800d3994
800008CC	addiu  a2, s0, $0004
800008D0	addu   a0, s1, zero
800008D4	sll    v1, s1, $01
800008D8	addu   v1, v1, s1
800008DC	sll    v0, v1, $05
800008E0	subu   v0, v0, v1
800008E4	sll    v0, v0, $03
800008E8	subu   v0, v0, s1
800008EC	sll    v0, v0, $02
800008F0	lui    at, $8015
800008F4	addiu  at, at, $190f
800008F8	addu   at, at, v0
800008FC	lbu    a1, $0000(at)
80000900	jal    $800d3994
80000904	addiu  a2, s0, $000c
80000908	lh     v1, $000c(s0)
8000090C	lh     v0, $0004(s0)
80000910	nop
80000914	subu   v0, v1, v0
80000918	bgez   v0, L0924 [$80000924]
8000091C	sh     s1, $001c(s0)
80000920	addiu  v0, v0, $0007

L0924:	; 80000924
80000924	sra    v0, v0, $03
80000928	sh     v0, $0010(sp)
8000092C	lh     v1, $000e(s0)
80000930	lh     v0, $0006(s0)
80000934	nop
80000938	subu   v0, v1, v0
8000093C	bgez   v0, L0948 [$80000948]
80000940	nop
80000944	addiu  v0, v0, $0007

L0948:	; 80000948
80000948	sra    v0, v0, $03
8000094C	sh     v0, $0012(sp)
80000950	lh     v1, $0010(s0)
80000954	lh     v0, $0008(s0)
80000958	nop
8000095C	subu   v0, v1, v0
80000960	bgez   v0, L096c [$8000096c]
80000964	nop
80000968	addiu  v0, v0, $0007

L096c:	; 8000096C
8000096C	sra    v0, v0, $03
80000970	sh     v0, $0014(sp)
80000974	lui    a1, $801d
80000978	addiu  a1, a1, $bd24 (=-$42dc)
8000097C	jal    $800d44e8
80000980	addiu  a0, sp, $0010
80000984	lw     ra, $0020(sp)
80000988	lw     s1, $001c(sp)
8000098C	lw     s0, $0018(sp)
80000990	addiu  sp, sp, $0028
80000994	jr     ra 
80000998	nop

8000099C	addiu  sp, sp, $ffe0 (=-$20)
800009A0	sw     s1, $0014(sp)
800009A4	addu   s1, a0, zero
800009A8	sw     s0, $0010(sp)
800009AC	lui    a0, $801b
800009B0	addiu  a0, a0, $0020
800009B4	sw     ra, $0018(sp)
800009B8	jal    $800bbeac
800009BC	addu   s0, a1, zero
800009C0	lui    a0, $801b
800009C4	addiu  a0, a0, $1c1c
800009C8	addu   a1, zero, zero
800009CC	addu   a2, zero, zero
800009D0	jal    $800d2980
800009D4	addu   a3, zero, zero
800009D8	lui    a0, $801b
800009DC	addiu  a0, a0, $0b14
800009E0	addu   a1, zero, zero
800009E4	addu   a2, zero, zero
800009E8	jal    $800d2980
800009EC	addu   a3, zero, zero
800009F0	addu   a0, s1, zero
800009F4	addu   a1, s0, zero
800009F8	lui    a3, $801b
800009FC	addiu  a3, a3, $0864
80000A00	jal    $800d5444
80000A04	ori    a2, zero, $0004
80000A08	ori    a0, zero, $0065
80000A0C	addu   a1, s0, zero
80000A10	jal    $800bba84
80000A14	addu   a2, zero, zero
80000A18	lw     ra, $0018(sp)
80000A1C	lw     s1, $0014(sp)
80000A20	lw     s0, $0010(sp)
80000A24	addiu  sp, sp, $0020
80000A28	jr     ra 
80000A2C	nop
