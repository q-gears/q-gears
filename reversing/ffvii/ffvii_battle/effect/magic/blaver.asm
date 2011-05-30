
Entry:	; 80000000
80000000	addiu  sp, sp, $ffe8 (=-$18)
80000004	sw     ra, $0010(sp)
80000008	jal    $801b0730
8000000C	nop
80000010	lui    v0, $801b
80000014	addiu  v0, v0, $07a0
80000018	lw     ra, $0010(sp)
8000001C	addiu  sp, sp, $0018
80000020	jr     ra 
80000024	nop

80000028	addiu  sp, sp, $ffd8 (=-$28)
8000002C	lui    v0, $8015
80000030	lh     v0, $169c(v0)
80000034	lui    v1, $8016

func0038:	; 80000038
80000038	addiu  v1, v1, $2978
8000003C	sw     s2, $0020(sp)
80000040	lui    s2, $801c
80000044	addiu  s2, s2, $e97c (=-$1684)
80000048	sw     ra, $0024(sp)
8000004C	sw     s1, $001c(sp)
80000050	sw     s0, $0018(sp)
80000054	sll    v0, v0, $05
80000058	addu   s1, v0, v1
8000005C	lhu    v0, $0002(s1)
80000060	lui    v1, $801c
80000064	lw     v1, $e62c(v1)
80000068	sll    v0, v0, $10
8000006C	sra    v0, v0, $18
80000070	sh     v0, $0000(s2)
80000074	andi   v0, v0, $ffff
80000078	slt    v0, v0, v1
8000007C	bne    v0, zero, L008c [$8000008c]
80000080	addiu  v0, zero, $ffff (=-$1)
80000084	j      $801b0130
80000088	sh     v0, $0000(s1)

L008c:	; 8000008C
8000008C	lh     a0, $0006(s1)
80000090	lui    s0, $8010
80000094	addiu  s0, s0, $a6e0 (=-$5920)
80000098	sll    a0, a0, $06
8000009C	jal    $8003b48c
800000A0	addu   a0, a0, s0
800000A4	lh     a0, $0006(s1)
800000A8	nop
800000AC	sll    a0, a0, $06
800000B0	jal    $8003b51c
800000B4	addu   a0, a0, s0
800000B8	lui    a0, $801c
800000BC	addiu  a0, a0, $e980 (=-$1680)
800000C0	lui    s0, $801c
800000C4	addiu  s0, s0, $e99c (=-$1664)
800000C8	addu   a1, s0, zero
800000CC	jal    $8003bc6c
800000D0	addiu  a2, sp, $0010
800000D4	addiu  s0, s0, $ffec (=-$14)
800000D8	jal    $8003b48c
800000DC	addu   a0, s0, zero
800000E0	jal    $8003b51c
800000E4	addu   a0, s0, zero
800000E8	addiu  a0, s2, $fff8 (=-$8)
800000EC	ori    a2, zero, $000c
800000F0	lui    a1, $8015
800000F4	lw     a1, $17c0(a1)
800000F8	lui    a3, $801e
800000FC	lw     a3, $ead4(a3)
80000100	jal    $800d4d90
80000104	addiu  a1, a1, $0070
80000108	lui    v1, $8006
8000010C	lbu    v1, $2d98(v1)
80000110	lui    at, $801e
80000114	sw     v0, $ead4(at)
80000118	bne    v1, zero, L0130 [$80000130]
8000011C	nop
80000120	lhu    v0, $0002(s1)
80000124	nop
80000128	addiu  v0, v0, $0100
8000012C	sh     v0, $0002(s1)

L0130:	; 80000130
80000130	lw     ra, $0024(sp)
80000134	lw     s2, $0020(sp)
80000138	lw     s1, $001c(sp)
8000013C	lw     s0, $0018(sp)
80000140	addiu  sp, sp, $0028
80000144	jr     ra 
80000148	nop

8000014C	addiu  sp, sp, $ff80 (=-$80)
80000150	sw     s5, $0074(sp)
80000154	lui    s5, $8010
80000158	addiu  s5, s5, $a63c (=-$59c4)
8000015C	addu   a0, s5, zero
80000160	lui    v1, $8016
80000164	addiu  v1, v1, $2978
80000168	lui    v0, $8015
8000016C	lh     v0, $169c(v0)
80000170	addiu  a2, sp, $0028
80000174	sw     ra, $0078(sp)
80000178	sw     s4, $0070(sp)
8000017C	sw     s3, $006c(sp)
80000180	sw     s2, $0068(sp)
80000184	sw     s1, $0064(sp)
80000188	sw     s0, $0060(sp)
8000018C	sll    v0, v0, $05
80000190	addu   s3, v0, v1
80000194	lh     a1, $0006(s3)
80000198	lui    v0, $8010
8000019C	addiu  v0, v0, $a6e0 (=-$5920)
800001A0	sll    a1, a1, $06
800001A4	jal    $800d41fc
800001A8	addu   a1, a1, v0
800001AC	jal    $8003b48c
800001B0	addiu  a0, sp, $0028
800001B4	jal    $8003b51c
800001B8	addiu  a0, sp, $0028
800001BC	lui    a0, $801c
800001C0	addiu  a0, a0, $e9b0 (=-$1650)
800001C4	addiu  a1, sp, $0048
800001C8	lui    v0, $801b
800001CC	lw     v0, $15a0(v0)
800001D0	lhu    v1, $003c(sp)
800001D4	sll    v0, v0, $04
800001D8	lui    at, $801c
800001DC	addiu  at, at, $e9d4 (=-$162c)
800001E0	addu   at, at, v0
800001E4	sh     v1, $0000(at)
800001E8	lhu    v1, $0040(sp)
800001EC	addiu  s4, sp, $0058
800001F0	lui    at, $801c
800001F4	addiu  at, at, $e9d6 (=-$162a)
800001F8	addu   at, at, v0
800001FC	sh     v1, $0000(at)
80000200	lhu    v1, $0044(sp)
80000204	nop
80000208	lui    at, $801c
8000020C	addiu  at, at, $e9d8 (=-$1628)
80000210	addu   at, at, v0
80000214	sh     v1, $0000(at)
80000218	jal    $8003bc6c
8000021C	addu   a2, s4, zero
80000220	lui    s1, $801b
80000224	lw     s1, $15a0(s1)
80000228	lhu    v0, $0048(sp)
8000022C	sll    v1, s1, $04
80000230	lui    at, $801c
80000234	addiu  at, at, $e9dc (=-$1624)
80000238	addu   at, at, v1
8000023C	sh     v0, $0000(at)
80000240	lhu    v0, $004c(sp)
80000244	nop
80000248	lui    at, $801c
8000024C	addiu  at, at, $e9de (=-$1622)
80000250	addu   at, at, v1
80000254	sh     v0, $0000(at)
80000258	lhu    v0, $0050(sp)
8000025C	nop
80000260	lui    at, $801c
80000264	addiu  at, at, $e9e0 (=-$1620)
80000268	addu   at, at, v1
8000026C	sh     v0, $0000(at)
80000270	lh     v1, $0002(s3)
80000274	nop
80000278	slti   v0, v1, $0014
8000027C	beq    v0, zero, L038c [$8000038c]
80000280	nop
80000284	blez   v1, L0394 [$80000394]
80000288	addu   a0, s5, zero
8000028C	andi   s0, s1, $000f
80000290	addiu  s1, s1, $ffff (=-$1)
80000294	lui    s2, $801e
80000298	lw     s2, $ead4(s2)
8000029C	jal    $8003b48c
800002A0	andi   s1, s1, $000f
800002A4	jal    $8003b51c
800002A8	addu   a0, s5, zero
800002AC	sll    s0, s0, $04
800002B0	lui    a2, $801c
800002B4	addiu  a2, a2, $e9d4 (=-$162c)
800002B8	addu   a0, s0, a2
800002BC	addiu  a3, a2, $0008

func02c0:	; 800002C0
800002C0	addu   a1, s0, a3
800002C4	sll    s1, s1, $04
800002C8	addu   a2, s1, a2
800002CC	addiu  v0, sp, $005c
800002D0	addu   a3, s1, a3
800002D4	sw     v0, $0020(sp)
800002D8	sw     s4, $0024(sp)
800002DC	addiu  v0, s2, $0008
800002E0	sw     v0, $0010(sp)
800002E4	addiu  v0, s2, $0010
800002E8	sw     v0, $0014(sp)
800002EC	addiu  v0, s2, $0018
800002F0	sw     v0, $0018(sp)
800002F4	addiu  v0, s2, $0020
800002F8	jal    $8003bd7c
800002FC	sw     v0, $001c(sp)
80000300	addu   a0, v0, zero
80000304	lw     v0, $0058(sp)
80000308	lui    v1, $0006
8000030C	and    v0, v0, v1
80000310	bne    v0, zero, L0394 [$80000394]
80000314	lui    v1, $2e80
80000318	ori    v1, v1, $8080
8000031C	addu   a1, s2, zero
80000320	lui    v0, $0900
80000324	sw     v0, $0000(s2)
80000328	ori    v0, zero, $5080
8000032C	sh     v0, $000c(s2)
80000330	ori    v0, zero, $50c0
80000334	sh     v0, $0014(s2)
80000338	ori    v0, zero, $0080
8000033C	sh     v0, $001c(s2)
80000340	ori    v0, zero, $00c0
80000344	sh     v0, $0024(s2)
80000348	ori    v0, zero, $7888
8000034C	sh     v0, $000e(s2)
80000350	ori    v0, zero, $002d
80000354	sra    a0, a0, $02
80000358	sll    a0, a0, $02
8000035C	sw     v1, $0004(s2)
80000360	sh     v0, $0016(s2)
80000364	lui    v0, $8015
80000368	lw     v0, $17c0(v0)
8000036C	addiu  a0, a0, $0070
80000370	jal    $80046794
80000374	addu   a0, a0, v0
80000378	addiu  v0, s2, $0028
8000037C	lui    at, $801e
80000380	sw     v0, $ead4(at)
80000384	j      $801b0394
80000388	nop

L038c:	; 8000038C
8000038C	addiu  v0, zero, $ffff (=-$1)
80000390	sh     v0, $0000(s3)

L0394:	; 80000394
80000394	lui    v0, $8006
80000398	lbu    v0, $2d98(v0)
8000039C	nop
800003A0	bne    v0, zero, L03cc [$800003cc]
800003A4	nop
800003A8	lhu    v1, $0002(s3)
800003AC	lui    v0, $801b
800003B0	lw     v0, $15a0(v0)
800003B4	addiu  v1, v1, $0001
800003B8	addiu  v0, v0, $0001
800003BC	andi   v0, v0, $000f
800003C0	lui    at, $801b
800003C4	sw     v0, $15a0(at)
800003C8	sh     v1, $0002(s3)

L03cc:	; 800003CC
800003CC	lw     ra, $0078(sp)
800003D0	lw     s5, $0074(sp)
800003D4	lw     s4, $0070(sp)
800003D8	lw     s3, $006c(sp)
800003DC	lw     s2, $0068(sp)
800003E0	lw     s1, $0064(sp)
800003E4	lw     s0, $0060(sp)
800003E8	addiu  sp, sp, $0080
800003EC	jr     ra 
800003F0	nop

800003F4	addiu  sp, sp, $ffe8 (=-$18)
800003F8	lui    v0, $8015
800003FC	lh     v0, $169c(v0)
80000400	lui    v1, $8016
80000404	addiu  v1, v1, $2978
80000408	sw     ra, $0014(sp)
8000040C	sw     s0, $0010(sp)
80000410	sll    v0, v0, $05
80000414	addu   s0, v0, v1
80000418	lhu    v0, $0002(s0)
8000041C	lui    v1, $801c
80000420	lw     v1, $e8c8(v1)
80000424	sll    v0, v0, $10
80000428	sra    v0, v0, $18
8000042C	slt    v1, v0, v1
80000430	beq    v1, zero, L0448 [$80000448]
80000434	addiu  a0, s0, $0008
80000438	lui    at, $801c
8000043C	sh     v0, $e9d0(at)
80000440	j      $801b0454
80000444	nop

L0448:	; 80000448
80000448	addiu  v0, zero, $ffff (=-$1)
8000044C	j      $801b04ac
80000450	sh     v0, $0000(s0)
80000454	lh     a2, $0010(s0)
80000458	jal    $800d4368
8000045C	ori    a1, zero, $1000
80000460	lui    a0, $801c
80000464	addiu  a0, a0, $e9c8 (=-$1638)
80000468	ori    a2, zero, $000c
8000046C	lui    a1, $8015
80000470	lw     a1, $17c0(a1)
80000474	lui    a3, $801e
80000478	lw     a3, $ead4(a3)
8000047C	jal    $800d4d90
80000480	addiu  a1, a1, $0070
80000484	lui    v1, $8006
80000488	lbu    v1, $2d98(v1)
8000048C	lui    at, $801e
80000490	sw     v0, $ead4(at)
80000494	bne    v1, zero, L04ac [$800004ac]
80000498	nop
8000049C	lhu    v0, $0002(s0)
800004A0	nop
800004A4	addiu  v0, v0, $0100
800004A8	sh     v0, $0002(s0)

L04ac:	; 800004AC
800004AC	lw     ra, $0014(sp)
800004B0	lw     s0, $0010(sp)
800004B4	addiu  sp, sp, $0018
800004B8	jr     ra 
800004BC	nop

800004C0	lui    v0, $8015
800004C4	lh     v0, $169c(v0)
800004C8	lui    v1, $8006
800004CC	lbu    v1, $2d98(v1)
800004D0	addiu  sp, sp, $ffe0 (=-$20)
800004D4	sw     s0, $0010(sp)
800004D8	lui    s0, $8016
800004DC	addiu  s0, s0, $2978
800004E0	sw     ra, $001c(sp)
800004E4	sw     s2, $0018(sp)

L04e8:	; 800004E8
800004E8	sw     s1, $0014(sp)
800004EC	sll    v0, v0, $05
800004F0	bne    v1, zero, L0660 [$80000660]
800004F4	addu   s1, v0, s0
800004F8	lh     v1, $0002(s1)
800004FC	ori    v0, zero, $000a
80000500	bne    v1, v0, L0530 [$80000530]
80000504	ori    v0, zero, $0011
80000508	lui    a0, $801b
8000050C	addiu  a0, a0, $0028
80000510	jal    $800bbeac
80000514	nop
80000518	sll    v0, v0, $05
8000051C	lhu    v1, $0006(s1)
80000520	addu   s2, v0, s0
80000524	sh     v1, $0006(s2)
80000528	lh     v1, $0002(s1)
8000052C	ori    v0, zero, $0011

L0530:	; 80000530
80000530	bne    v1, v0, L0558 [$80000558]
80000534	nop
80000538	lui    a0, $801b
8000053C	addiu  a0, a0, $014c
80000540	jal    $800bbeac
80000544	nop
80000548	sll    v0, v0, $05
8000054C	lhu    v1, $0006(s1)
80000550	addu   s2, v0, s0
80000554	sh     v1, $0006(s2)

L0558:	; 80000558
80000558	lh     v1, $0002(s1)
8000055C	ori    v0, zero, $001a
80000560	bne    v1, v0, L0624 [$80000624]
80000564	nop
80000568	lui    a0, $801b
8000056C	addiu  a0, a0, $03f4
80000570	jal    $800bbeac
80000574	nop
80000578	sll    v0, v0, $05
8000057C	addu   s2, v0, s0
80000580	lh     a0, $0004(s1)
80000584	addiu  s0, s2, $0008
80000588	sll    v1, a0, $01
8000058C	addu   v1, v1, a0
80000590	sll    v0, v1, $05
80000594	subu   v0, v0, v1
80000598	sll    v0, v0, $03
8000059C	subu   v0, v0, a0
800005A0	sll    v0, v0, $02
800005A4	lui    at, $8015
800005A8	addiu  at, at, $190f
800005AC	addu   at, at, v0
800005B0	lbu    a1, $0000(at)
800005B4	jal    $800d3994
800005B8	addu   a2, s0, zero
800005BC	lh     a0, $0004(s1)
800005C0	nop
800005C4	sll    v1, a0, $01
800005C8	addu   v1, v1, a0
800005CC	sll    v0, v1, $05
800005D0	subu   v0, v0, v1
800005D4	sll    v0, v0, $03
800005D8	subu   v0, v0, a0
800005DC	sll    v0, v0, $02
800005E0	lui    at, $8015
800005E4	addiu  at, at, $18f6
800005E8	addu   at, at, v0
800005EC	lhu    v0, $0000(at)
800005F0	addu   a0, s0, zero
800005F4	subu   v0, zero, v0
800005F8	jal    $800d56a8
800005FC	sh     v0, $0010(s2)
80000600	ori    a0, zero, $0020
80000604	addu   a1, v0, zero
80000608	jal    $800d55f4
8000060C	ori    a2, zero, $001b
80000610	lh     a0, $0004(s1)
80000614	jal    $800d5774
80000618	nop
8000061C	jal    $800d5138
80000620	ori    a0, zero, $0001

L0624:	; 80000624
80000624	lh     s0, $0002(s1)
80000628	ori    v0, zero, $001b
8000062C	bne    s0, v0, L0650 [$80000650]
80000630	nop
80000634	jal    $800d51d4
80000638	ori    a0, zero, $0001
8000063C	lh     v0, $0002(s1)
80000640	nop
80000644	bne    v0, s0, L0650 [$80000650]
80000648	addiu  v0, zero, $ffff (=-$1)
8000064C	sh     v0, $0000(s1)

L0650:	; 80000650
80000650	lhu    v0, $0002(s1)
80000654	nop
80000658	addiu  v0, v0, $0001
8000065C	sh     v0, $0002(s1)

L0660:	; 80000660
80000660	lw     ra, $001c(sp)
80000664	lw     s2, $0018(sp)
80000668	lw     s1, $0014(sp)
8000066C	lw     s0, $0010(sp)
80000670	addiu  sp, sp, $0020
80000674	jr     ra 
80000678	nop

8000067C	addiu  sp, sp, $ffe0 (=-$20)
80000680	sw     s0, $0010(sp)
80000684	addu   s0, a0, zero
80000688	sw     s1, $0014(sp)
8000068C	lui    a0, $801b
80000690	addiu  a0, a0, $04c0
80000694	sw     ra, $0018(sp)
80000698	jal    $800bbeac
8000069C	addu   s1, a1, zero
800006A0	sll    v0, v0, $05
800006A4	lui    v1, $8016
800006A8	addiu  v1, v1, $2978
800006AC	addu   v0, v0, v1
800006B0	sh     s0, $0004(v0)
800006B4	sh     s1, $0006(v0)
800006B8	lw     ra, $0018(sp)
800006BC	lw     s1, $0014(sp)
800006C0	lw     s0, $0010(sp)
800006C4	addiu  sp, sp, $0020
800006C8	jr     ra 
800006CC	nop

800006D0	lui    v0, $8015
800006D4	lh     v0, $169c(v0)
800006D8	lui    v1, $8016
800006DC	addiu  v1, v1, $2978
800006E0	sll    v0, v0, $05
800006E4	addu   a0, v0, v1
800006E8	lh     v0, $0002(a0)
800006EC	lui    v1, $801c
800006F0	addiu  v1, v1, $ead4 (=-$152c)
800006F4	sll    v0, v0, $10
800006F8	addu   v0, v0, v1
800006FC	lui    at, $801e
80000700	sw     v0, $ead4(at)
80000704	lhu    v0, $0002(a0)
80000708	lui    v1, $8016
8000070C	lh     v1, $2080(v1)
80000710	xori   v0, v0, $0001
80000714	slti   v1, v1, $0002
80000718	beq    v1, zero, L0728 [$80000728]
8000071C	sh     v0, $0002(a0)
80000720	addiu  v0, zero, $ffff (=-$1)
80000724	sh     v0, $0000(a0)

L0728:	; 80000728
80000728	jr     ra 
8000072C	nop

80000730	addiu  sp, sp, $ffe0 (=-$20)
80000734	sw     s0, $0010(sp)
80000738	addu   s0, a0, zero
8000073C	sw     s1, $0014(sp)
80000740	addu   s1, a1, zero
80000744	lui    a0, $801b
80000748	addiu  a0, a0, $15a8
8000074C	addu   a1, zero, zero
80000750	addu   a2, zero, zero
80000754	sw     ra, $0018(sp)
80000758	jal    $800d2980
8000075C	addu   a3, zero, zero
80000760	lui    a0, $801b
80000764	addiu  a0, a0, $06d0
80000768	jal    $800bbeac
8000076C	nop
80000770	addu   a0, s0, zero
80000774	addu   a1, s1, zero
80000778	lui    a3, $801b
8000077C	addiu  a3, a3, $067c
80000780	jal    $800d5444
80000784	addu   a2, zero, zero
80000788	lw     ra, $0018(sp)
8000078C	lw     s1, $0014(sp)
80000790	lw     s0, $0010(sp)
80000794	addiu  sp, sp, $0020
80000798	jr     ra 
8000079C	nop
