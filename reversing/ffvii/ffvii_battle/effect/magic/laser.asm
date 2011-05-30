
Entry:	; 80000000
80000000	addiu  sp, sp, $ffe8 (=-$18)
80000004	sw     ra, $0010(sp)
80000008	jal    $801b06f4
8000000C	nop
80000010	lw     ra, $0010(sp)
80000014	addiu  sp, sp, $0018
80000018	jr     ra 
8000001C	nop

80000020	addiu  sp, sp, $ffb0 (=-$50)
80000024	sw     s0, $0038(sp)
80000028	lui    s0, $8010
8000002C	addiu  s0, s0, $a63c (=-$59c4)
80000030	addu   a0, s0, zero
80000034	lui    v1, $8015
80000038	lh     v1, $169c(v1)
8000003C	lui    v0, $8016
80000040	addiu  v0, v0, $2978
80000044	sw     ra, $0048(sp)
80000048	sw     s3, $0044(sp)
8000004C	sw     s2, $0040(sp)
80000050	sw     s1, $003c(sp)
80000054	sll    v1, v1, $05
80000058	jal    $8003b48c
8000005C	addu   s3, v1, v0
80000060	jal    $8003b51c
80000064	addu   a0, s0, zero
80000068	addiu  a0, s3, $0004
8000006C	addiu  a1, sp, $0010
80000070	addiu  s2, sp, $0030
80000074	addu   a2, s2, zero
80000078	addiu  s1, sp, $0034
8000007C	jal    $8003bbdc
80000080	addu   a3, s1, zero
80000084	addu   s0, v0, zero
80000088	addiu  a0, s3, $000c
8000008C	addiu  a1, sp, $0018
80000090	addu   a2, s2, zero
80000094	jal    $8003bbdc
80000098	addu   a3, s1, zero
8000009C	addu   s0, s0, v0
800000A0	srl    v0, s0, $1f
800000A4	addu   s2, s0, v0
800000A8	sra    s1, s2, $01
800000AC	blez   s1, L02a0 [$800002a0]
800000B0	addiu  a0, sp, $0020
800000B4	lui    s0, $801f
800000B8	lw     s0, $88f4(s0)
800000BC	lh     a2, $0010(sp)
800000C0	lh     v1, $001a(sp)
800000C4	lh     a3, $0012(sp)
800000C8	addu   a1, a0, zero
800000CC	sw     zero, $0028(sp)
800000D0	addiu  v0, s0, $0028
800000D4	lui    at, $801f
800000D8	sw     v0, $88f4(at)
800000DC	lh     v0, $0018(sp)
800000E0	subu   v1, v1, a3
800000E4	sw     v1, $0024(sp)
800000E8	subu   v0, v0, a2
800000EC	jal    $8003a08c
800000F0	sw     v0, $0020(sp)
800000F4	jal    $8003b66c
800000F8	nop
800000FC	lw     v1, $0020(sp)
80000100	nop
80000104	mult   v0, v1
80000108	mflo   a0
8000010C	div    a0, s1
80000110	bne    s1, zero, L011c [$8000011c]
80000114	nop
80000118	break   $01c00

L011c:	; 8000011C
8000011C	addiu  at, zero, $ffff (=-$1)
80000120	bne    s1, at, L0134 [$80000134]
80000124	lui    at, $8000
80000128	bne    a0, at, L0134 [$80000134]
8000012C	nop
80000130	break   $01800

L0134:	; 80000134
80000134	mflo   a0
80000138	lw     v1, $0024(sp)
8000013C	nop
80000140	mult   v0, v1
80000144	mflo   v0
80000148	div    v0, s1
8000014C	bne    s1, zero, L0158 [$80000158]
80000150	nop
80000154	break   $01c00

L0158:	; 80000158
80000158	addiu  at, zero, $ffff (=-$1)
8000015C	bne    s1, at, L0170 [$80000170]
80000160	lui    at, $8000
80000164	bne    v0, at, L0170 [$80000170]
80000168	nop
8000016C	break   $01800

L0170:	; 80000170
80000170	mflo   v0
80000174	lui    v1, $2e80
80000178	ori    v1, v1, $8080
8000017C	sra    a0, a0, $06
80000180	sw     a0, $0020(sp)
80000184	sra    v0, v0, $06
80000188	sw     v0, $0024(sp)
8000018C	lui    v0, $0900
80000190	sw     v0, $0000(s0)
80000194	sw     v1, $0004(s0)
80000198	lhu    v0, $0010(sp)
8000019C	lhu    v1, $0024(sp)
800001A0	nop
800001A4	addu   v0, v0, v1
800001A8	sh     v0, $0008(s0)
800001AC	lhu    v0, $0012(sp)
800001B0	lhu    v1, $0020(sp)
800001B4	nop
800001B8	subu   v0, v0, v1
800001BC	sh     v0, $000a(s0)
800001C0	lhu    v0, $0010(sp)
800001C4	lhu    v1, $0024(sp)
800001C8	nop
800001CC	subu   v0, v0, v1
800001D0	sh     v0, $0010(s0)
800001D4	lhu    v0, $0012(sp)
800001D8	lhu    v1, $0020(sp)
800001DC	nop
800001E0	addu   v0, v0, v1
800001E4	sh     v0, $0012(s0)
800001E8	lhu    v0, $0018(sp)
800001EC	lhu    v1, $0024(sp)
800001F0	nop
800001F4	addu   v0, v0, v1
800001F8	sh     v0, $0018(s0)
800001FC	lhu    v0, $001a(sp)
80000200	lhu    v1, $0020(sp)
80000204	nop
80000208	subu   v0, v0, v1
8000020C	sh     v0, $001a(s0)
80000210	lhu    v0, $0018(sp)
80000214	lhu    v1, $0024(sp)
80000218	nop
8000021C	subu   v0, v0, v1
80000220	sh     v0, $0020(s0)
80000224	lhu    v0, $001a(sp)
80000228	lhu    a0, $0020(sp)
8000022C	ori    v1, zero, $00ff
80000230	sb     zero, $0014(s0)
80000234	sb     zero, $000c(s0)
80000238	sb     v1, $0024(s0)
8000023C	addu   v0, v0, a0
80000240	sh     v0, $0022(s0)
80000244	sb     v1, $001c(s0)
80000248	lh     v0, $0002(s3)
8000024C	nop
80000250	sll    v0, v0, $05
80000254	sb     v0, $001d(s0)
80000258	sb     v0, $000d(s0)
8000025C	lh     v1, $0002(s3)
80000260	ori    v0, zero, $002e
80000264	sh     v0, $0016(s0)
80000268	ori    v0, zero, $7808
8000026C	sh     v0, $000e(s0)
80000270	sra    v0, s2, $03
80000274	sll    v1, v1, $05
80000278	ori    v1, v1, $001f
8000027C	sb     v1, $0025(s0)
80000280	sb     v1, $0015(s0)
80000284	lui    v1, $8015
80000288	lw     v1, $17c0(v1)
8000028C	sll    v0, v0, $02
80000290	addu   v0, v0, v1
80000294	lw     a0, $0070(v0)
80000298	jal    $80046794
8000029C	addu   a1, s0, zero

L02a0:	; 800002A0
800002A0	lui    v0, $8006
800002A4	lbu    v0, $2d98(v0)
800002A8	nop
800002AC	bne    v0, zero, L02d8 [$800002d8]
800002B0	ori    v1, zero, $0008
800002B4	lhu    v0, $0002(s3)
800002B8	nop
800002BC	addiu  v0, v0, $0001
800002C0	sh     v0, $0002(s3)
800002C4	sll    v0, v0, $10
800002C8	sra    v0, v0, $10
800002CC	bne    v0, v1, L02d8 [$800002d8]
800002D0	addiu  v0, zero, $ffff (=-$1)
800002D4	sh     v0, $0000(s3)

L02d8:	; 800002D8
800002D8	lw     ra, $0048(sp)
800002DC	lw     s3, $0044(sp)
800002E0	lw     s2, $0040(sp)
800002E4	lw     s1, $003c(sp)
800002E8	lw     s0, $0038(sp)
800002EC	addiu  sp, sp, $0050
800002F0	jr     ra 
800002F4	nop

800002F8	addiu  sp, sp, $ffe8 (=-$18)
800002FC	ori    a1, zero, $1000
80000300	addiu  a2, zero, $ff38 (=-$c8)
80000304	lui    v0, $8015
80000308	lh     v0, $169c(v0)
8000030C	lui    v1, $8016
80000310	addiu  v1, v1, $2978
80000314	sw     ra, $0014(sp)
80000318	sw     s0, $0010(sp)
8000031C	sll    v0, v0, $05
80000320	addu   s0, v0, v1
80000324	jal    $800d4368
80000328	addiu  a0, s0, $0004
8000032C	lui    v0, $5555
80000330	lhu    v1, $0002(s0)
80000334	ori    v0, v0, $5556
80000338	sll    v1, v1, $10
8000033C	sra    t0, v1, $10
80000340	mult   t0, v0
80000344	lui    t1, $801d
80000348	addiu  t1, t1, $88e4 (=-$771c)
8000034C	addiu  a0, t1, $fff8 (=-$8)
80000350	ori    a2, zero, $000c
80000354	lui    a1, $8015
80000358	lw     a1, $17c0(a1)
8000035C	lui    a3, $801f
80000360	lw     a3, $88f4(a3)
80000364	addiu  a1, a1, $0070
80000368	sra    v1, v1, $1f
8000036C	mfhi   v0
80000370	subu   v0, v0, v1
80000374	sll    v1, v0, $01
80000378	addu   v1, v1, v0
8000037C	subu   t0, t0, v1
80000380	jal    $800d4d90
80000384	sh     t0, $0000(t1)
80000388	lui    v1, $8006
8000038C	lbu    v1, $2d98(v1)
80000390	lui    at, $801f
80000394	sw     v0, $88f4(at)
80000398	bne    v1, zero, L03c4 [$800003c4]
8000039C	ori    v1, zero, $0008
800003A0	lhu    v0, $0002(s0)
800003A4	nop
800003A8	addiu  v0, v0, $0001
800003AC	sh     v0, $0002(s0)
800003B0	sll    v0, v0, $10
800003B4	sra    v0, v0, $10
800003B8	bne    v0, v1, L03c4 [$800003c4]
800003BC	addiu  v0, zero, $ffff (=-$1)
800003C0	sh     v0, $0000(s0)

L03c4:	; 800003C4
800003C4	lw     ra, $0014(sp)
800003C8	lw     s0, $0010(sp)
800003CC	addiu  sp, sp, $0018
800003D0	jr     ra 
800003D4	nop

800003D8	addiu  sp, sp, $ffe8 (=-$18)
800003DC	ori    a1, zero, $1000
800003E0	addiu  a2, zero, $ff38 (=-$c8)
800003E4	lui    v0, $8015
800003E8	lh     v0, $169c(v0)
800003EC	lui    v1, $8016
800003F0	addiu  v1, v1, $2978
800003F4	sw     ra, $0014(sp)
800003F8	sw     s0, $0010(sp)
800003FC	sll    v0, v0, $05
80000400	addu   s0, v0, v1
80000404	jal    $800d4368
80000408	addiu  a0, s0, $0004
8000040C	lui    v1, $801d
80000410	addiu  v1, v1, $88f0 (=-$7710)
80000414	addiu  a0, v1, $fff8 (=-$8)
80000418	ori    a2, zero, $000c
8000041C	lhu    v0, $0002(s0)
80000420	lui    a1, $8015
80000424	lw     a1, $17c0(a1)
80000428	lui    a3, $801f
8000042C	lw     a3, $88f4(a3)
80000430	addiu  a1, a1, $0070
80000434	jal    $800d4d90
80000438	sh     v0, $0000(v1)
8000043C	lui    v1, $8006
80000440	lbu    v1, $2d98(v1)
80000444	lui    at, $801f
80000448	sw     v0, $88f4(at)
8000044C	bne    v1, zero, L0478 [$80000478]
80000450	ori    v1, zero, $0008
80000454	lhu    v0, $0002(s0)
80000458	nop
8000045C	addiu  v0, v0, $0001
80000460	sh     v0, $0002(s0)
80000464	sll    v0, v0, $10
80000468	sra    v0, v0, $10
8000046C	bne    v0, v1, L0478 [$80000478]
80000470	addiu  v0, zero, $ffff (=-$1)
80000474	sh     v0, $0000(s0)

L0478:	; 80000478
80000478	lw     ra, $0014(sp)
8000047C	lw     s0, $0010(sp)
80000480	addiu  sp, sp, $0018
80000484	jr     ra 
80000488	nop

8000048C	lui    v0, $8015
80000490	lh     v0, $169c(v0)
80000494	lui    v1, $8006
80000498	lbu    v1, $2d98(v1)
8000049C	addiu  sp, sp, $ffa8 (=-$58)
800004A0	sw     s2, $0050(sp)
800004A4	lui    s2, $8016
800004A8	addiu  s2, s2, $2978
800004AC	sw     ra, $0054(sp)
800004B0	sw     s1, $004c(sp)
800004B4	sw     s0, $0048(sp)
800004B8	sll    v0, v0, $05
800004BC	bne    v1, zero, L0624 [$80000624]
800004C0	addu   s1, v0, s2
800004C4	lh     v1, $0002(s1)
800004C8	ori    v0, zero, $0003
800004CC	bne    v1, v0, L05a8 [$800005a8]
800004D0	ori    v0, zero, $0007
800004D4	lui    a0, $801b
800004D8	addiu  a0, a0, $0020
800004DC	jal    $800bbeac
800004E0	nop
800004E4	sll    v0, v0, $05
800004E8	lh     a0, $0016(s1)
800004EC	addu   s0, v0, s2
800004F0	sll    v1, a0, $01
800004F4	addu   v1, v1, a0
800004F8	sll    v0, v1, $05
800004FC	subu   v0, v0, v1
80000500	sll    v0, v0, $03
80000504	subu   v0, v0, a0
80000508	sll    v0, v0, $02
8000050C	lui    at, $8015
80000510	addiu  at, at, $1918
80000514	addu   at, at, v0
80000518	lbu    a1, $0000(at)
8000051C	jal    $800d3994
80000520	addiu  a2, s0, $0004
80000524	lh     a0, $0014(s1)
80000528	nop
8000052C	sll    v1, a0, $01
80000530	addu   v1, v1, a0
80000534	sll    v0, v1, $05
80000538	subu   v0, v0, v1
8000053C	sll    v0, v0, $03
80000540	subu   v0, v0, a0
80000544	sll    v0, v0, $02
80000548	lui    at, $8015
8000054C	addiu  at, at, $190f
80000550	addu   at, at, v0
80000554	lbu    a1, $0000(at)
80000558	jal    $800d3994
8000055C	addiu  a2, s0, $000c
80000560	lui    a0, $801b
80000564	addiu  a0, a0, $02f8
80000568	jal    $800bbeac
8000056C	nop
80000570	sll    v0, v0, $05
80000574	addu   s0, v0, s2
80000578	lhu    v0, $0038(sp)
8000057C	ori    a0, zero, $0020
80000580	sh     v0, $0004(s0)
80000584	lhu    v0, $003c(sp)
80000588	addiu  a1, s0, $000c
8000058C	sh     v0, $0006(s0)
80000590	lhu    v0, $0040(sp)
80000594	ori    a2, zero, $003a
80000598	jal    $800d55f4
8000059C	sh     v0, $0008(s0)
800005A0	j      $801b0614
800005A4	nop

L05a8:	; 800005A8
800005A8	bne    v1, v0, L0614 [$80000614]
800005AC	nop
800005B0	lui    a0, $801b
800005B4	addiu  a0, a0, $03d8
800005B8	jal    $800bbeac
800005BC	nop
800005C0	sll    v0, v0, $05
800005C4	lh     a0, $0014(s1)
800005C8	addu   s0, v0, s2
800005CC	sll    v1, a0, $01
800005D0	addu   v1, v1, a0
800005D4	sll    v0, v1, $05
800005D8	subu   v0, v0, v1
800005DC	sll    v0, v0, $03
800005E0	subu   v0, v0, a0
800005E4	sll    v0, v0, $02
800005E8	lui    at, $8015
800005EC	addiu  at, at, $190f
800005F0	addu   at, at, v0
800005F4	lbu    a1, $0000(at)
800005F8	jal    $800d3994
800005FC	addiu  a2, s0, $0004
80000600	lh     a0, $0014(s1)
80000604	jal    $800d5774
80000608	nop
8000060C	addiu  v0, zero, $ffff (=-$1)
80000610	sh     v0, $0000(s1)

L0614:	; 80000614
80000614	lhu    v0, $0002(s1)
80000618	nop
8000061C	addiu  v0, v0, $0001
80000620	sh     v0, $0002(s1)

L0624:	; 80000624
80000624	lw     ra, $0054(sp)
80000628	lw     s2, $0050(sp)
8000062C	lw     s1, $004c(sp)
80000630	lw     s0, $0048(sp)
80000634	addiu  sp, sp, $0058
80000638	jr     ra 
8000063C	nop

80000640	addiu  sp, sp, $ffe0 (=-$20)
80000644	sw     s0, $0010(sp)
80000648	addu   s0, a0, zero
8000064C	sw     s1, $0014(sp)
80000650	lui    a0, $801b
80000654	addiu  a0, a0, $048c
80000658	sw     ra, $0018(sp)
8000065C	jal    $800bbeac
80000660	addu   s1, a1, zero
80000664	sll    v0, v0, $05
80000668	lui    v1, $8016
8000066C	addiu  v1, v1, $2978
80000670	addu   v0, v0, v1
80000674	sh     s0, $0014(v0)
80000678	sh     s1, $0016(v0)
8000067C	lw     ra, $0018(sp)
80000680	lw     s1, $0014(sp)
80000684	lw     s0, $0010(sp)
80000688	addiu  sp, sp, $0020
8000068C	jr     ra 
80000690	nop



////////////////////////////////
// 801B0694-801B06F0
V0 = h[8015169c];
A0 = 80162978 + V0 * 20;

[801e88f4] = w(801c88f4 + (h[A0 + 2] << 10));

[A0 + 2] = h(hu[A0 + 2] XOR 1);

if (h[80162080] < 2)
{
    [A0 + 0] = h(-1);
}
////////////////////////////////



////////////////////////////////
// 801B06F4-801B0760
S0 = A0; // target mask
S1 = A1; // attacker id

// load texture
A0 = 801b0764;
A1 = 0;
A2 = 0;
A3 = 0;
funcd2980;

A0 = 801b0694;
funcbbeac;

A0 = S0;
A1 = S1;
A2 = 1;
A3 = 801b0640;
funcd5444; // call function for all units in target mask
////////////////////////////////
