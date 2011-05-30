
Entry:	; 80000000
80000000	lb     k1, $0aa0(zero)
80000004	lb     k1, $02c4(zero)
80000008	lb     k1, $031c(zero)
8000000C	lb     k1, $0430(zero)
80000010	lb     k1, $078c(zero)
80000014	lb     k1, $0944(zero)
80000018	lb     k1, $0a38(zero)
8000001C	lb     k1, $0a8c(zero)
80000020	lb     k1, $0ab8(zero)
80000024	lb     k1, $0aa0(zero)
80000028	lb     k1, $0d90(zero)
8000002C	lb     k1, $0d90(zero)
80000030	lb     k1, $0ba8(zero)
80000034	lb     k1, $0be4(zero)
80000038	lb     k1, $0b6c(zero)
8000003C	lb     k1, $0d00(zero)
80000040	addiu  sp, sp, $ffe8 (=-$18)
80000044	sw     ra, $0010(sp)
80000048	jal    $801b3bb0
8000004C	nop
80000050	lui    v0, $801e
80000054	addiu  v0, v0, $d188 (=-$2e78)
80000058	lw     ra, $0010(sp)
8000005C	addiu  sp, sp, $0018
80000060	jr     ra 
80000064	nop

80000068	lw     v1, $0000(a0)
8000006C	nop
80000070	addiu  v0, v1, $0002
80000074	sw     v0, $0000(a0)
80000078	lh     v1, $0000(v1)
8000007C	nop
80000080	bgez   v1, L009c [$8000009c]
80000084	nop
80000088	lui    v0, $801f
8000008C	addiu  v0, v0, $0482
80000090	sll    v1, v1, $01
80000094	subu   v0, v0, v1
80000098	lh     v1, $0000(v0)

L009c:	; 8000009C
8000009C	jr     ra 
800000A0	addu   v0, v1, zero

800000A4	addiu  sp, sp, $ffc8 (=-$38)
800000A8	sw     s2, $0028(sp)
800000AC	addu   s2, a1, zero
800000B0	sw     s3, $002c(sp)
800000B4	addu   s3, a0, zero
800000B8	sw     ra, $0030(sp)
800000BC	sw     s1, $0024(sp)
800000C0	blez   s2, L0104 [$80000104]
800000C4	sw     s0, $0020(sp)
800000C8	sra    s1, s2, $08
800000CC	blez   s1, L014c [$8000014c]
800000D0	addu   s0, zero, zero

loop00d4:	; 800000D4
800000D4	bgez   a0, L00e0 [$800000e0]
800000D8	addu   v0, a0, zero
800000DC	addiu  v0, a0, $0003

L00e0:	; 800000E0
800000E0	jal    func39a74 [$80039a74]
800000E4	sra    a0, v0, $02
800000E8	addu   a0, v0, zero
800000EC	addiu  s0, s0, $0001
800000F0	slt    v0, s0, s1
800000F4	bne    v0, zero, loop00d4 [$800000d4]
800000F8	nop
800000FC	j      $801b0150
80000100	andi   v0, s2, $00ff

L0104:	; 80000104
80000104	subu   s2, zero, s2
80000108	sra    s1, s2, $08
8000010C	ori    v0, zero, $1000
80000110	subu   a0, v0, a0
80000114	blez   s1, L0148 [$80000148]
80000118	addu   s0, zero, zero

loop011c:	; 8000011C
8000011C	bgez   a0, L0128 [$80000128]
80000120	addu   v0, a0, zero
80000124	addiu  v0, a0, $0003

L0128:	; 80000128
80000128	jal    func39a74 [$80039a74]
8000012C	sra    a0, v0, $02
80000130	addu   a0, v0, zero
80000134	addiu  s0, s0, $0001
80000138	slt    v0, s0, s1
8000013C	bne    v0, zero, loop011c [$8000011c]
80000140	nop
80000144	ori    v0, zero, $1000

L0148:	; 80000148
80000148	subu   a0, v0, a0

L014c:	; 8000014C
8000014C	andi   v0, s2, $00ff
80000150	addiu  s1, v0, $0001
80000154	mult   a0, s1
80000158	mflo   v0
8000015C	ori    v1, zero, $0100
80000160	subu   v1, v1, s1
80000164	mult   s3, v1
80000168	mflo   v1
8000016C	addu   v0, v0, v1
80000170	sra    v0, v0, $08
80000174	lw     ra, $0030(sp)
80000178	lw     s3, $002c(sp)
8000017C	lw     s2, $0028(sp)
80000180	lw     s1, $0024(sp)
80000184	lw     s0, $0020(sp)
80000188	addiu  sp, sp, $0038
8000018C	jr     ra 
80000190	nop

80000194	addiu  sp, sp, $fed0 (=-$130)
80000198	sw     s2, $0120(sp)
8000019C	lui    s2, $1f80
800001A0	ori    s2, s2, $0008
800001A4	sw     s4, $0128(sp)
800001A8	lui    s4, $1f80
800001AC	ori    s4, s4, $0010
800001B0	lui    v0, $8015
800001B4	lh     v0, $169c(v0)
800001B8	lui    v1, $8016
800001BC	addiu  v1, v1, $2978
800001C0	sw     s1, $011c(sp)
800001C4	sw     s0, $0118(sp)
800001C8	sll    v0, v0, $05
800001CC	addu   s0, v0, v1
800001D0	lui    v0, $8006
800001D4	lbu    v0, $2d98(v0)
800001D8	lui    s1, $1f80
800001DC	sw     ra, $012c(sp)
800001E0	bne    v0, zero, L0dd0 [$80000dd0]
800001E4	sw     s3, $0124(sp)
800001E8	lh     v0, $0002(s0)
800001EC	nop
800001F0	bne    v0, zero, L0ae8 [$80000ae8]
800001F4	addiu  v0, zero, $ffff (=-$1)
800001F8	lui    at, $801f
800001FC	sh     v0, $02f8(at)

L0200:	; 80000200
80000200	lui    at, $801f
80000204	sh     v0, $0324(at)
80000208	ori    v0, zero, $0001
8000020C	lui    at, $801f
80000210	sh     zero, $02ee(at)
80000214	lui    at, $801f
80000218	sh     zero, $031a(at)
8000021C	j      $801b0ae8
80000220	sh     v0, $0002(s0)

L0224:	; 80000224
80000224	lw     v0, $000c(s0)
80000228	nop
8000022C	addiu  v1, v0, $0002
80000230	sw     v1, $000c(s0)
80000234	lhu    v1, $0000(v0)
80000238	nop
8000023C	andi   v0, v1, $0040
80000240	beq    v0, zero, L0268 [$80000268]
80000244	nop
80000248	lui    v0, $801f
8000024C	addiu  v0, v0, $02ec
80000250	lui    at, $801f
80000254	sw     v0, $0344(at)
80000258	lui    v0, $801f
8000025C	addiu  v0, v0, $0318
80000260	j      $801b0280
80000264	nop

L0268:	; 80000268
80000268	lui    v0, $801f
8000026C	addiu  v0, v0, $0318
80000270	lui    at, $801f
80000274	sw     v0, $0344(at)
80000278	lui    v0, $801f
8000027C	addiu  v0, v0, $02ec
80000280	lui    at, $801f
80000284	sw     v0, $0348(at)
80000288	lui    v0, $801f
8000028C	lw     v0, $0344(v0)
80000290	andi   v1, v1, $ff3f
80000294	sh     v1, $0000(v0)
80000298	sll    v1, v1, $10
8000029C	sra    v1, v1, $10
800002A0	sltiu  v0, v1, $000a
800002A4	beq    v0, zero, L0adc [$80000adc]
800002A8	sll    v0, v1, $02
800002AC	lui    at, $801b
800002B0	addu   at, at, v0
800002B4	lw     v0, $0000(at)
800002B8	nop
800002BC	jr     v0 
800002C0	nop

800002C4	lw     v1, $000c(s0)
800002C8	lui    a0, $801f
800002CC	lw     a0, $0344(a0)
800002D0	addiu  v0, v1, $0002
800002D4	sw     v0, $000c(s0)
800002D8	lhu    v0, $0000(v1)
800002DC	nop
800002E0	sh     v0, $0010(a0)
800002E4	lw     v1, $000c(s0)
800002E8	nop
800002EC	addiu  v0, v1, $0002
800002F0	sw     v0, $000c(s0)
800002F4	lhu    v0, $0000(v1)
800002F8	nop
800002FC	sh     v0, $0012(a0)
80000300	lw     v1, $000c(s0)
80000304	nop
80000308	addiu  v0, v1, $0002
8000030C	sw     v0, $000c(s0)
80000310	lhu    v0, $0000(v1)
80000314	j      $801b0ae8
80000318	sh     v0, $0014(a0)
8000031C	jal    $801b0068
80000320	addiu  a0, s0, $000c

L0324:	; 80000324
80000324	lui    a1, $801f
80000328	lw     a1, $0344(a1)
8000032C	nop
80000330	sh     v0, $0002(a1)
80000334	lw     v1, $000c(s0)
80000338	nop
8000033C	addiu  v0, v1, $0002
80000340	sw     v0, $000c(s0)
80000344	lh     v0, $0000(v1)
80000348	lh     a0, $0010(a1)
8000034C	lh     v1, $0002(a1)
80000350	subu   v0, v0, a0
80000354	div    v0, v1
8000037C	mflo   v0
80000380	nop
80000384	sh     v0, $0020(a1)
80000388	lw     v1, $000c(s0)
8000038C	nop
80000390	addiu  v0, v1, $0002
80000394	sw     v0, $000c(s0)
80000398	lh     v0, $0000(v1)
8000039C	lh     a0, $0012(a1)
800003A0	lh     v1, $0002(a1)
800003A4	subu   v0, v0, a0
800003A8	div    v0, v1
800003D0	mflo   v0
800003D4	nop
800003D8	sh     v0, $0022(a1)
800003DC	lw     v1, $000c(s0)
800003E0	nop
800003E4	addiu  v0, v1, $0002
800003E8	sw     v0, $000c(s0)
800003EC	lh     v0, $0000(v1)
800003F0	lh     a0, $0014(a1)
800003F4	lh     v1, $0002(a1)
800003F8	subu   v0, v0, a0
800003FC	div    v0, v1
80000424	mflo   v0
80000428	j      $801b0ae8
8000042C	sh     v0, $0024(a1)
80000430	lui    a0, $801f
80000434	lw     a0, $0348(a0)
80000438	lui    a2, $801f
8000043C	lw     a2, $0344(a2)
80000440	lhu    v0, $0010(a0)
80000444	lhu    v1, $0010(a2)
80000448	nop
8000044C	subu   v0, v0, v1
80000450	sh     v0, $0000(s1)
80000454	lh     v0, $0000(s1)
80000458	nop
8000045C	mult   v0, v0
80000460	lhu    v1, $0012(a2)
80000464	lhu    v0, $0012(a0)
80000468	nop
8000046C	subu   v0, v0, v1
80000470	sh     v0, $0002(s1)
80000474	lhu    v0, $0002(s1)
80000478	mflo   a1
8000047C	sll    v0, v0, $10
80000480	sra    v0, v0, $10
80000484	mult   v0, v0
80000488	lhu    v1, $0014(a0)
8000048C	lhu    v0, $0014(a2)
80000490	nop
80000494	subu   v1, v1, v0
80000498	mflo   a0
8000049C	sll    v0, v1, $10
800004A0	sra    v0, v0, $10
800004A4	mult   v0, v0
800004A8	sh     v1, $0004(s1)
800004AC	addu   a1, a1, a0
800004B0	mflo   a0
800004B4	jal    func39f5c [$80039f5c]
800004B8	addu   a0, a1, a0
800004BC	lui    v1, $801f
800004C0	lw     v1, $0344(v1)
800004C4	nop
800004C8	sw     v0, $0004(v1)
800004CC	lwl    v0, $0013(v1)
800004D0	lwr    v0, $0010(v1)
800004D4	lwl    a1, $0017(v1)
800004D8	lwr    a1, $0014(v1)
800004DC	swl    v0, $001b(v1)
800004E0	swr    v0, $0018(v1)
800004E4	swl    a1, $001f(v1)
800004E8	swr    a1, $001c(v1)
800004EC	jal    $801b0068
800004F0	addiu  a0, s0, $000c
800004F4	lui    a1, $801f
800004F8	lw     a1, $0344(a1)
800004FC	nop
80000500	sh     v0, $0002(a1)
80000504	lw     v1, $000c(s0)
80000508	nop
8000050C	addiu  v0, v1, $0002
80000510	sw     v0, $000c(s0)
80000514	lhu    v0, $0000(v1)
80000518	nop
8000051C	sh     v0, $0000(s1)
80000520	lw     v1, $000c(s0)
80000524	nop
80000528	addiu  v0, v1, $0002
8000052C	sw     v0, $000c(s0)
80000530	lhu    v0, $0000(v1)
80000534	nop
80000538	sh     v0, $0002(s1)
8000053C	lw     v1, $000c(s0)
80000540	nop
80000544	addiu  v0, v1, $0002
80000548	sw     v0, $000c(s0)
8000054C	lhu    v0, $0000(v1)
80000550	nop
80000554	sh     v0, $0004(s1)
80000558	lh     v0, $0000(s1)
8000055C	lh     a0, $0010(a1)
80000560	lh     v1, $0002(a1)
80000564	subu   v0, v0, a0
80000568	div    v0, v1
80000590	mflo   v0
80000594	lh     a0, $0012(a1)
80000598	sh     v0, $0020(a1)
8000059C	lhu    v0, $0002(s1)
800005A0	lh     v1, $0002(a1)
800005A4	sll    v0, v0, $10
800005A8	sra    v0, v0, $10
800005AC	subu   v0, v0, a0
800005B0	div    v0, v1
800005D8	mflo   v0
800005DC	lh     a0, $0014(a1)

L05e0:	; 800005E0
800005E0	sh     v0, $0022(a1)
800005E4	lhu    v0, $0004(s1)
800005E8	lh     v1, $0002(a1)
800005EC	sll    v0, v0, $10
800005F0	sra    v0, v0, $10
800005F4	subu   v0, v0, a0
800005F8	div    v0, v1
80000620	mflo   v0
80000624	lui    a0, $801f
80000628	lw     a0, $0348(a0)
8000062C	sh     v0, $0024(a1)
80000630	lh     v1, $0000(a0)
80000634	ori    v0, zero, $0002
80000638	bne    v1, v0, L06a0 [$800006a0]
8000063C	nop
80000640	lhu    v1, $0020(a0)
80000644	lhu    v0, $0002(a0)
80000648	nop
8000064C	mult   v1, v0
80000650	lhu    v0, $0010(a0)
80000654	mflo   v1
80000658	addu   v0, v0, v1
8000065C	sh     v0, $0000(s2)
80000660	lhu    v1, $0022(a0)
80000664	lhu    v0, $0002(a0)
80000668	nop
8000066C	mult   v1, v0
80000670	lhu    v0, $0012(a0)
80000674	mflo   v1
80000678	addu   v0, v0, v1
8000067C	sh     v0, $0002(s2)
80000680	lhu    v1, $0024(a0)
80000684	lhu    v0, $0002(a0)
80000688	nop
8000068C	mult   v1, v0
80000690	lhu    v0, $0014(a0)
80000694	mflo   v1
80000698	j      $801b06bc
8000069C	addu   v0, v0, v1

L06a0:	; 800006A0
800006A0	lhu    v0, $0010(a0)
800006A4	nop
800006A8	sh     v0, $0000(s2)
800006AC	lhu    v0, $0012(a0)
800006B0	nop
800006B4	sh     v0, $0002(s2)
800006B8	lhu    v0, $0014(a0)
800006BC	nop
800006C0	sh     v0, $0004(s2)
800006C4	lhu    v0, $0000(s1)
800006C8	lhu    v1, $0000(s2)
800006CC	nop
800006D0	subu   v0, v0, v1
800006D4	sh     v0, $0000(s1)
800006D8	lh     v0, $0000(s1)
800006DC	nop
800006E0	mult   v0, v0
800006E4	lhu    v1, $0002(s2)
800006E8	lhu    v0, $0002(s1)
800006EC	nop
800006F0	subu   v0, v0, v1
800006F4	sh     v0, $0002(s1)
800006F8	lhu    v0, $0002(s1)
800006FC	mflo   a1
80000700	sll    v0, v0, $10
80000704	sra    v0, v0, $10
80000708	mult   v0, v0
8000070C	lhu    v1, $0004(s1)
80000710	lhu    v0, $0004(s2)
80000714	nop
80000718	subu   v1, v1, v0
8000071C	mflo   a0
80000720	sll    v0, v1, $10
80000724	sra    v0, v0, $10
80000728	mult   v0, v0
8000072C	sh     v1, $0004(s1)
80000730	addu   a1, a1, a0
80000734	mflo   a0
80000738	jal    func39f5c [$80039f5c]
8000073C	addu   a0, a1, a0
80000740	lui    a0, $801f
80000744	lw     a0, $0344(a0)
80000748	nop
8000074C	lw     a1, $0004(a0)
80000750	lh     v1, $0002(a0)
80000754	subu   v0, v0, a1
80000758	div    v0, v1
80000780	mflo   v0
80000784	j      $801b0ae8
80000788	sw     v0, $0008(a0)
8000078C	jal    $801b0068
80000790	addiu  a0, s0, $000c
80000794	lui    a1, $801f
80000798	lw     a1, $0344(a1)
8000079C	nop
800007A0	sh     v0, $0002(a1)
800007A4	lw     v1, $000c(s0)
800007A8	nop
800007AC	addiu  v0, v1, $0002
800007B0	sw     v0, $000c(s0)
800007B4	lhu    v0, $0000(v1)
800007B8	lhu    v1, $0010(a1)
800007BC	nop
800007C0	subu   v0, v0, v1
800007C4	sh     v0, $0000(s1)
800007C8	lw     v1, $000c(s0)
800007CC	nop
800007D0	addiu  v0, v1, $0002
800007D4	sw     v0, $000c(s0)
800007D8	lhu    v0, $0000(v1)
800007DC	lhu    v1, $0012(a1)
800007E0	nop
800007E4	subu   v0, v0, v1
800007E8	sh     v0, $0002(s1)
800007EC	lw     v1, $000c(s0)
800007F0	nop
800007F4	addiu  v0, v1, $0002
800007F8	sw     v0, $000c(s0)
800007FC	lhu    v0, $0000(v1)

func0800:	; 80000800
80000800	lhu    v1, $0014(a1)
80000804	nop
80000808	subu   v0, v0, v1
8000080C	sh     v0, $0004(s1)
80000810	lh     v1, $0020(a1)
80000814	lh     v0, $0002(a1)
80000818	nop
8000081C	mult   v1, v0
80000820	mflo   a0
80000824	nop
80000828	nop
8000082C	mult   v0, v0
80000830	lh     v1, $0000(s1)
80000834	mflo   v0
80000838	subu   v1, v1, a0
8000083C	sll    v1, v1, $01
80000840	div    v1, v0
80000868	mflo   v1
8000086C	lh     a0, $0022(a1)
80000870	lh     v0, $0002(a1)
80000874	nop
80000878	mult   a0, v0
8000087C	mflo   a0
80000880	nop
80000884	nop
80000888	mult   v0, v0
8000088C	sh     v1, $0018(a1)
80000890	lhu    v0, $0002(s1)
80000894	mflo   v1
80000898	sll    v0, v0, $10
8000089C	sra    v0, v0, $10
800008A0	subu   v0, v0, a0
800008A4	sll    v0, v0, $01
800008A8	div    v0, v1
800008D0	mflo   v0
800008D4	lh     a0, $0024(a1)
800008D8	lh     v1, $0002(a1)
800008DC	nop
800008E0	mult   a0, v1
800008E4	mflo   a0
800008E8	nop
800008EC	nop
800008F0	mult   v1, v1
800008F4	sh     v0, $001a(a1)
800008F8	lhu    v0, $0004(s1)
800008FC	mflo   v1
80000900	sll    v0, v0, $10
80000904	sra    v0, v0, $10
80000908	subu   v0, v0, a0
8000090C	sll    v0, v0, $01
80000910	div    v0, v1
80000938	mflo   v0
8000093C	j      $801b0ae8
80000940	sh     v0, $001c(a1)
80000944	jal    $801b0068
80000948	addiu  a0, s0, $000c
8000094C	lui    a0, $801f
80000950	lw     a0, $0344(a0)
80000954	nop
80000958	sh     v0, $0002(a0)
8000095C	lw     a1, $000c(s0)
80000960	nop
80000964	addiu  v0, a1, $0002
80000968	sw     v0, $000c(s0)
8000096C	lh     v0, $0002(a0)
80000970	ori    v1, zero, $1000
80000974	div    v1, v0
8000099C	mflo   v1
800009A0	lhu    a2, $0012(a0)
800009A4	lhu    a3, $0014(a0)
800009A8	lhu    v0, $0000(a1)
800009AC	lhu    a1, $0010(a0)
800009B0	sw     zero, $0004(a0)
800009B4	sh     a2, $001a(a0)
800009B8	sh     a3, $001c(a0)
800009BC	sh     v0, $0028(a0)
800009C0	sh     a1, $0018(a0)
800009C4	sw     v1, $0008(a0)
800009C8	lw     v1, $000c(s0)
800009CC	nop
800009D0	addiu  v0, v1, $0002
800009D4	sw     v0, $000c(s0)
800009D8	lhu    v0, $0000(v1)
800009DC	lhu    v1, $0010(a0)
800009E0	nop
800009E4	subu   v0, v0, v1
800009E8	sh     v0, $0020(a0)
800009EC	lw     v1, $000c(s0)
800009F0	nop
800009F4	addiu  v0, v1, $0002
800009F8	sw     v0, $000c(s0)
800009FC	lhu    v0, $0000(v1)
80000A00	lhu    v1, $0012(a0)
80000A04	nop
80000A08	subu   v0, v0, v1
80000A0C	sh     v0, $0022(a0)
80000A10	lw     v1, $000c(s0)
80000A14	nop
80000A18	addiu  v0, v1, $0002
80000A1C	sw     v0, $000c(s0)
80000A20	lhu    v0, $0000(v1)
80000A24	lhu    v1, $0014(a0)
80000A28	nop
80000A2C	subu   v0, v0, v1
80000A30	j      $801b0ae8
80000A34	sh     v0, $0024(a0)
80000A38	lw     v0, $000c(s0)
80000A3C	nop
80000A40	addiu  v1, v0, $0002
80000A44	sw     v1, $000c(s0)
80000A48	lui    v1, $801f
80000A4C	lw     v1, $0344(v1)
80000A50	lhu    v0, $0000(v0)
80000A54	nop
80000A58	bne    v0, zero, L0a6c [$80000a6c]
80000A5C	sh     v0, $000c(v1)
80000A60	lhu    v0, $0014(s0)
80000A64	nop
80000A68	sh     v0, $000c(v1)

L0a6c:	; 80000A6C
80000A6C	lw     a0, $000c(s0)
80000A70	lui    v1, $801f
80000A74	lw     v1, $0344(v1)
80000A78	addiu  v0, a0, $0002
80000A7C	sw     v0, $000c(s0)
80000A80	lhu    v0, $0000(a0)
80000A84	j      $801b0ae8
80000A88	sh     v0, $000e(v1)
80000A8C	lui    v1, $801f
80000A90	lw     v1, $0344(v1)
80000A94	addiu  v0, zero, $ffff (=-$1)
80000A98	j      $801b0ae8
80000A9C	sh     v0, $000c(v1)
80000AA0	jal    $801b0068
80000AA4	addiu  a0, s0, $000c
80000AA8	lui    v1, $801f
80000AAC	lw     v1, $0344(v1)
80000AB0	j      $801b0ae8
80000AB4	sh     v0, $0002(v1)
80000AB8	lw     v0, $000c(s0)
80000ABC	nop
80000AC0	addiu  v1, v0, $0002
80000AC4	sw     v1, $000c(s0)
80000AC8	lhu    v0, $0000(v0)
80000ACC	lui    at, $8016
80000AD0	sh     v0, $2084(at)
80000AD4	j      $801b0ae8
80000AD8	nop

L0adc:	; 80000ADC
80000ADC	addiu  v0, zero, $ffff (=-$1)
80000AE0	j      $801b1198
80000AE4	sh     v0, $0000(s0)

L0ae8:	; 80000AE8
80000AE8	lui    v0, $801f
80000AEC	lh     v0, $02ee(v0)
80000AF0	nop
80000AF4	beq    v0, zero, L0224 [$80000224]
80000AF8	nop
80000AFC	lui    v0, $801f
80000B00	lh     v0, $031a(v0)
80000B04	nop
80000B08	beq    v0, zero, L0224 [$80000224]
80000B0C	nop
80000B10	addu   s2, zero, zero
80000B14	lui    v0, $801f
80000B18	addiu  v0, v0, $02ec
80000B1C	lui    at, $801f
80000B20	sw     v0, $0344(at)
80000B24	lui    v0, $801f
80000B28	addiu  v0, v0, $0318
80000B2C	lui    at, $801f
80000B30	sw     v0, $0348(at)

L0b34:	; 80000B34
80000B34	lui    v0, $801f
80000B38	lw     v0, $0344(v0)
80000B3C	nop
80000B40	lh     v1, $0000(v0)
80000B44	nop
80000B48	sltiu  v0, v1, $0006
80000B4C	beq    v0, zero, L0d90 [$80000d90]
80000B50	sll    v0, v1, $02
80000B54	lui    at, $801b
80000B58	addu   at, at, v0
80000B5C	lw     v0, $0028(at)
80000B60	nop
80000B64	jr     v0 
80000B68	nop

80000B6C	lui    a0, $801f
80000B70	lw     a0, $0344(a0)
80000B74	nop
80000B78	lhu    v0, $0020(a0)
80000B7C	lhu    v1, $0018(a0)
80000B80	lhu    a1, $001a(a0)
80000B84	lhu    a2, $001c(a0)
80000B88	addu   v0, v0, v1
80000B8C	sh     v0, $0020(a0)
80000B90	lhu    v0, $0022(a0)
80000B94	lhu    v1, $0024(a0)
80000B98	addu   v0, v0, a1
80000B9C	addu   v1, v1, a2
80000BA0	sh     v0, $0022(a0)
80000BA4	sh     v1, $0024(a0)
80000BA8	lui    a0, $801f
80000BAC	lw     a0, $0344(a0)
80000BB0	nop
80000BB4	lhu    v0, $0010(a0)
80000BB8	lhu    v1, $0020(a0)
80000BBC	lhu    a1, $0022(a0)
80000BC0	lhu    a2, $0024(a0)
80000BC4	addu   v0, v0, v1
80000BC8	sh     v0, $0010(a0)
80000BCC	lhu    v0, $0012(a0)
80000BD0	lhu    v1, $0014(a0)
80000BD4	addu   v0, v0, a1
80000BD8	addu   v1, v1, a2
80000BDC	j      $801b0d8c
80000BE0	sh     v0, $0012(a0)
80000BE4	lui    a1, $801f
80000BE8	lw     a1, $0344(a1)
80000BEC	nop
80000BF0	lhu    v0, $0018(a1)
80000BF4	lhu    v1, $0020(a1)
80000BF8	lhu    a0, $0022(a1)
80000BFC	lhu    a2, $0024(a1)
80000C00	addu   v0, v0, v1
80000C04	sh     v0, $0018(a1)
80000C08	lhu    v0, $001a(a1)
80000C0C	lhu    v1, $001c(a1)
80000C10	addu   v0, v0, a0
80000C14	sh     v0, $001a(a1)
80000C18	lw     v0, $0004(a1)
80000C1C	addu   v1, v1, a2
80000C20	sh     v1, $001c(a1)
80000C24	lw     v1, $0008(a1)
80000C28	lui    a2, $801f
80000C2C	lw     a2, $0348(a2)
80000C30	addu   v0, v0, v1
80000C34	sw     v0, $0004(a1)
80000C38	lh     v0, $0010(a2)
80000C3C	lh     v1, $0018(a1)
80000C40	nop
80000C44	subu   v0, v0, v1
80000C48	sw     v0, $0000(s4)
80000C4C	lh     v0, $0012(a2)
80000C50	lh     v1, $001a(a1)
80000C54	addu   a0, s4, zero
80000C58	subu   v0, v0, v1
80000C5C	sw     v0, $0004(s4)
80000C60	lh     v0, $0014(a2)
80000C64	lh     v1, $001c(a1)
80000C68	addu   a1, s1, zero
80000C6C	subu   v0, v0, v1
80000C70	jal    func3a078 [$8003a078]
80000C74	sw     v0, $0008(s4)
80000C78	lui    a0, $801f
80000C7C	lw     a0, $0344(a0)
80000C80	lh     v1, $0000(s1)
80000C84	lw     v0, $0004(a0)
80000C88	nop
80000C8C	mult   v1, v0
80000C90	lui    a1, $801f
80000C94	lw     a1, $0348(a1)
80000C98	nop
80000C9C	lhu    v1, $0010(a1)
80000CA0	mflo   v0
80000CA4	sra    v0, v0, $0c
80000CA8	subu   v1, v1, v0
80000CAC	sh     v1, $0010(a0)
80000CB0	lhu    v0, $0002(s1)
80000CB4	lw     v1, $0004(a0)
80000CB8	sll    v0, v0, $10
80000CBC	sra    v0, v0, $10
80000CC0	mult   v0, v1
80000CC4	lhu    v1, $0012(a1)
80000CC8	mflo   v0
80000CCC	sra    v0, v0, $0c
80000CD0	subu   v1, v1, v0
80000CD4	sh     v1, $0012(a0)
80000CD8	lhu    v0, $0004(s1)
80000CDC	lw     v1, $0004(a0)
80000CE0	sll    v0, v0, $10
80000CE4	sra    v0, v0, $10
80000CE8	mult   v0, v1
80000CEC	lhu    v1, $0014(a1)
80000CF0	mflo   v0
80000CF4	sra    v0, v0, $0c
80000CF8	j      $801b0d8c
80000CFC	subu   v1, v1, v0
80000D00	lui    v0, $801f
80000D04	lw     v0, $0344(v0)
80000D08	nop
80000D0C	lw     a0, $0004(v0)
80000D10	lw     v1, $0008(v0)
80000D14	lh     a1, $0028(v0)
80000D18	addu   a0, a0, v1
80000D1C	jal    $801b00a4
80000D20	sw     a0, $0004(v0)
80000D24	lui    a0, $801f
80000D28	lw     a0, $0344(a0)
80000D2C	nop
80000D30	lh     v1, $0020(a0)
80000D34	nop
80000D38	mult   v1, v0
80000D3C	mflo   a1
80000D40	lh     v1, $0022(a0)
80000D44	nop
80000D48	mult   v1, v0
80000D4C	mflo   a2
80000D50	lh     v1, $0024(a0)
80000D54	nop
80000D58	mult   v1, v0
80000D5C	sra    a1, a1, $0c
80000D60	lhu    v0, $0018(a0)
80000D64	sra    a2, a2, $0c
80000D68	addu   v0, v0, a1
80000D6C	sh     v0, $0010(a0)
80000D70	lhu    v0, $001a(a0)
80000D74	lhu    v1, $001c(a0)
80000D78	addu   v0, v0, a2
80000D7C	sh     v0, $0012(a0)
80000D80	mflo   v0
80000D84	sra    v0, v0, $0c
80000D88	addu   v1, v1, v0
80000D8C	sh     v1, $0014(a0)

L0d90:	; 80000D90
80000D90	addiu  s2, s2, $0001
80000D94	lui    a0, $801f
80000D98	lw     a0, $0344(a0)
80000D9C	lui    v0, $801f
80000DA0	addiu  v0, v0, $0318
80000DA4	lui    at, $801f
80000DA8	sw     v0, $0344(at)
80000DAC	lui    v0, $801f
80000DB0	addiu  v0, v0, $02ec
80000DB4	lui    at, $801f
80000DB8	sw     v0, $0348(at)
80000DBC	lhu    v1, $0002(a0)
80000DC0	slti   v0, s2, $0002
80000DC4	addiu  v1, v1, $ffff (=-$1)
80000DC8	bne    v0, zero, L0b34 [$80000b34]
80000DCC	sh     v1, $0002(a0)

L0dd0:	; 80000DD0
80000DD0	lw     a0, $0010(s0)
80000DD4	nop
80000DD8	beq    a0, zero, L1110 [$80001110]
80000DDC	ori    v0, zero, $0009
80000DE0	lui    s2, $801f
80000DE4	addiu  s2, s2, $02ec
80000DE8	lh     v1, $0000(s2)
80000DEC	nop
80000DF0	beq    v1, v0, L0f88 [$80000f88]
80000DF4	nop
80000DF8	jal    func3b48c [$8003b48c]
80000DFC	addiu  s3, zero, $ffff (=-$1)
80000E00	lw     a0, $0010(s0)
80000E04	jal    func3b51c [$8003b51c]
80000E08	nop
80000E0C	lui    v0, $801f
80000E10	lh     v0, $02f8(v0)
80000E14	nop
80000E18	bne    v0, s3, L0e58 [$80000e58]
80000E1C	addiu  a0, s2, $0010
80000E20	addu   a1, s4, zero
80000E24	jal    func3bc6c [$8003bc6c]
80000E28	addiu  a2, sp, $0110
80000E2C	lhu    v0, $0000(s4)
80000E30	lhu    v1, $0004(s4)
80000E34	lhu    a0, $0008(s4)
80000E38	lui    at, $8016
80000E3C	sh     v0, $8d00(at)
80000E40	lui    at, $8016
80000E44	sh     v1, $8d02(at)
80000E48	lui    at, $8016
80000E4C	sh     a0, $8d04(at)
80000E50	j      $801b0f88
80000E54	nop

L0e58:	; 80000E58
80000E58	jal    func3ace4 [$8003ace4]
80000E5C	addu   a1, s4, zero
80000E60	lui    a1, $801f
80000E64	lh     a1, $02fa(a1)
80000E68	nop
80000E6C	beq    a1, s3, L0e8c [$80000e8c]
80000E70	nop
80000E74	lui    a0, $801f
80000E78	lh     a0, $02f8(a0)
80000E7C	jal    $800d3994
80000E80	addu   a2, s1, zero
80000E84	j      $801b0f30
80000E88	nop

L0e8c:	; 80000E8C
80000E8C	lui    a0, $801f
80000E90	lh     a0, $02f8(a0)
80000E94	nop
80000E98	sll    v1, a0, $01
80000E9C	addu   v1, v1, a0
80000EA0	sll    v0, v1, $05
80000EA4	subu   v0, v0, v1
80000EA8	sll    v0, v0, $03
80000EAC	subu   v0, v0, a0
80000EB0	sll    v0, v0, $02
80000EB4	lui    a0, $801f
80000EB8	lh     a0, $02f8(a0)
80000EBC	lui    at, $8015
80000EC0	addu   at, at, v0
80000EC4	lhu    v0, $1a4c(at)
80000EC8	sll    v1, a0, $01
80000ECC	addu   v1, v1, a0
80000ED0	sh     v0, $0000(s1)
80000ED4	sll    v0, v1, $05
80000ED8	subu   v0, v0, v1
80000EDC	sll    v0, v0, $03
80000EE0	subu   v0, v0, a0
80000EE4	sll    v0, v0, $02
80000EE8	lui    a0, $801f
80000EEC	lh     a0, $02f8(a0)
80000EF0	lui    at, $8015
80000EF4	addu   at, at, v0
80000EF8	lhu    v0, $1a4e(at)
80000EFC	sll    v1, a0, $01
80000F00	addu   v1, v1, a0
80000F04	sh     v0, $0002(s1)
80000F08	sll    v0, v1, $05
80000F0C	subu   v0, v0, v1
80000F10	sll    v0, v0, $03
80000F14	subu   v0, v0, a0
80000F18	sll    v0, v0, $02
80000F1C	lui    at, $8015
80000F20	addu   at, at, v0
80000F24	lhu    v0, $1a50(at)
80000F28	nop
80000F2C	sh     v0, $0004(s1)
80000F30	lhu    v0, $0000(s4)
80000F34	lhu    v1, $0000(s1)
80000F38	nop
80000F3C	addu   v0, v0, v1
80000F40	lui    at, $8016
80000F44	sh     v0, $8d00(at)
80000F48	lhu    v0, $0004(s4)
80000F4C	lhu    a0, $0002(s1)
80000F50	lhu    v1, $0008(s4)
80000F54	lhu    a1, $0004(s1)
80000F58	addu   v0, v0, a0
80000F5C	addu   v1, v1, a1
80000F60	lui    at, $8016
80000F64	sh     v0, $8d02(at)
80000F68	lui    at, $8016
80000F6C	sh     v1, $8d04(at)
80000F70	lw     a0, $0010(s0)
80000F74	jal    func3b48c [$8003b48c]
80000F78	nop
80000F7C	lw     a0, $0010(s0)
80000F80	jal    func3b51c [$8003b51c]
80000F84	nop

L0f88:	; 80000F88
80000F88	lui    a0, $801f
80000F8C	addiu  a0, a0, $0318
80000F90	lh     v1, $0000(a0)
80000F94	ori    v0, zero, $0009
80000F98	beq    v1, v0, L1198 [$80001198]
80000F9C	addiu  s0, zero, $ffff (=-$1)
80000FA0	lui    v0, $801f
80000FA4	lh     v0, $0324(v0)
80000FA8	nop
80000FAC	bne    v0, s0, L0fec [$80000fec]
80000FB0	addu   a1, s4, zero
80000FB4	addiu  a0, a0, $0010
80000FB8	jal    func3bc6c [$8003bc6c]
80000FBC	addiu  a2, sp, $0110
80000FC0	lhu    v0, $0000(s4)
80000FC4	lhu    v1, $0004(s4)
80000FC8	lhu    a0, $0008(s4)
80000FCC	lui    at, $8010
80000FD0	sh     v0, $31e8(at)
80000FD4	lui    at, $8010
80000FD8	sh     v1, $31ea(at)
80000FDC	lui    at, $8010
80000FE0	sh     a0, $31ec(at)
80000FE4	j      $801b1198
80000FE8	nop

L0fec:	; 80000FEC
80000FEC	addiu  a0, a0, $0010
80000FF0	jal    func3ace4 [$8003ace4]
80000FF4	addu   a1, s4, zero
80000FF8	lui    a1, $801f
80000FFC	lh     a1, $0326(a1)
80001000	nop
80001004	beq    a1, s0, L1024 [$80001024]
80001008	nop
8000100C	lui    a0, $801f
80001010	lh     a0, $0324(a0)
80001014	jal    $800d3994
80001018	addu   a2, s1, zero
8000101C	j      $801b10c8
80001020	nop

L1024:	; 80001024
80001024	lui    a0, $801f
80001028	lh     a0, $0324(a0)
8000102C	nop
80001030	sll    v1, a0, $01
80001034	addu   v1, v1, a0
80001038	sll    v0, v1, $05
8000103C	subu   v0, v0, v1
80001040	sll    v0, v0, $03
80001044	subu   v0, v0, a0
80001048	sll    v0, v0, $02
8000104C	lui    a0, $801f
80001050	lh     a0, $0324(a0)
80001054	lui    at, $8015
80001058	addu   at, at, v0
8000105C	lhu    v0, $1a4c(at)
80001060	sll    v1, a0, $01
80001064	addu   v1, v1, a0
80001068	sh     v0, $0000(s1)
8000106C	sll    v0, v1, $05
80001070	subu   v0, v0, v1
80001074	sll    v0, v0, $03
80001078	subu   v0, v0, a0
8000107C	sll    v0, v0, $02
80001080	lui    a0, $801f
80001084	lh     a0, $0324(a0)
80001088	lui    at, $8015
8000108C	addu   at, at, v0
80001090	lhu    v0, $1a4e(at)
80001094	sll    v1, a0, $01
80001098	addu   v1, v1, a0
8000109C	sh     v0, $0002(s1)
800010A0	sll    v0, v1, $05
800010A4	subu   v0, v0, v1
800010A8	sll    v0, v0, $03
800010AC	subu   v0, v0, a0
800010B0	sll    v0, v0, $02
800010B4	lui    at, $8015
800010B8	addu   at, at, v0
800010BC	lhu    v0, $1a50(at)
800010C0	nop
800010C4	sh     v0, $0004(s1)
800010C8	lhu    v0, $0000(s4)
800010CC	lhu    v1, $0000(s1)
800010D0	nop
800010D4	addu   v0, v0, v1
800010D8	lui    at, $8010
800010DC	sh     v0, $31e8(at)
800010E0	lhu    v0, $0004(s4)
800010E4	lhu    a0, $0002(s1)
800010E8	lhu    v1, $0008(s4)
800010EC	lhu    a1, $0004(s1)
800010F0	addu   v0, v0, a0
800010F4	addu   v1, v1, a1
800010F8	lui    at, $8010
800010FC	sh     v0, $31ea(at)
80001100	lui    at, $8010
80001104	sh     v1, $31ec(at)
80001108	j      $801b1198
8000110C	nop

L1110:	; 80001110
80001110	lui    v0, $801f
80001114	lh     v0, $02ec(v0)
80001118	ori    a2, zero, $0009
8000111C	beq    v0, a2, L1154 [$80001154]
80001120	nop
80001124	lui    a1, $801f
80001128	addiu  a1, a1, $02fc
8000112C	lui    a0, $8016
80001130	addiu  a0, a0, $8d00 (=-$7300)
80001134	lwl    v0, $0003(a1)
80001138	lwr    v0, $0000(a1)
8000113C	lwl    v1, $0007(a1)
80001140	lwr    v1, $0004(a1)
80001144	swl    v0, $0003(a0)
80001148	swr    v0, $0000(a0)
8000114C	swl    v1, $0007(a0)
80001150	swr    v1, $0004(a0)

L1154:	; 80001154
80001154	lui    v0, $801f
80001158	lh     v0, $0318(v0)
8000115C	nop
80001160	beq    v0, a2, L1198 [$80001198]
80001164	nop
80001168	lui    a1, $801f
8000116C	addiu  a1, a1, $0328
80001170	lui    a0, $8010
80001174	addiu  a0, a0, $31e8
80001178	lwl    v0, $0003(a1)
8000117C	lwr    v0, $0000(a1)
80001180	lwl    v1, $0007(a1)
80001184	lwr    v1, $0004(a1)
80001188	swl    v0, $0003(a0)
8000118C	swr    v0, $0000(a0)
80001190	swl    v1, $0007(a0)
80001194	swr    v1, $0004(a0)

L1198:	; 80001198
80001198	lw     ra, $012c(sp)
8000119C	lw     s4, $0128(sp)
800011A0	lw     s3, $0124(sp)
800011A4	lw     s2, $0120(sp)
800011A8	lw     s1, $011c(sp)
800011AC	lw     s0, $0118(sp)
800011B0	addiu  sp, sp, $0130
800011B4	jr     ra 
800011B8	nop

800011BC	addiu  sp, sp, $ffe0 (=-$20)
800011C0	sw     s0, $0010(sp)
800011C4	addu   s0, a0, zero
800011C8	sw     s1, $0014(sp)
800011CC	addu   s1, a1, zero
800011D0	sw     s2, $0018(sp)
800011D4	lui    a0, $801b
800011D8	addiu  a0, a0, $0194
800011DC	sw     ra, $001c(sp)
800011E0	jal    $800bbeac
800011E4	addu   s2, a2, zero
800011E8	sll    v0, v0, $05
800011EC	lui    v1, $8016
800011F0	addiu  v1, v1, $2978
800011F4	addu   v0, v0, v1
800011F8	sw     s0, $000c(v0)
800011FC	sw     s1, $0010(v0)
80001200	sh     s2, $0014(v0)
80001204	lw     ra, $001c(sp)
80001208	lw     s2, $0018(sp)
8000120C	lw     s1, $0014(sp)
80001210	lw     s0, $0010(sp)
80001214	addiu  sp, sp, $0020
80001218	jr     ra 
8000121C	nop

80001220	addiu  sp, sp, $ffc0 (=-$40)
80001224	sw     s1, $002c(sp)
80001228	addu   s1, a0, zero
8000122C	sw     s0, $0028(sp)
80001230	lui    s0, $801f
80001234	addiu  s0, s0, $0450
80001238	addu   a0, s0, zero
8000123C	sw     s3, $0034(sp)
80001240	lui    s3, $801f
80001244	addiu  s3, s3, $00a8
80001248	sw     s2, $0030(sp)
8000124C	addu   s2, a2, zero
80001250	sw     ra, $0038(sp)
80001254	lui    at, $801f
80001258	sh     a1, $00b8(at)
8000125C	lui    at, $801f
80001260	sh     a1, $00b0(at)
80001264	jal    func3b48c [$8003b48c]
80001268	sh     a1, $0000(s3)
8000126C	jal    func3b51c [$8003b51c]
80001270	addu   a0, s0, zero
80001274	addu   a0, s1, zero
80001278	addiu  s0, s3, $0014
8000127C	addu   a1, s0, zero
80001280	jal    func3bc6c [$8003bc6c]
80001284	addiu  a2, sp, $0020
80001288	beq    s2, zero, L1308 [$80001308]
8000128C	addu   a0, s0, zero
80001290	jal    func3a08c [$8003a08c]
80001294	addiu  a1, sp, $0010
80001298	lw     v0, $0010(sp)
8000129C	nop
800012A0	mult   s2, v0
800012A4	mflo   v1
800012A8	lw     v0, $0014(sp)
800012AC	nop
800012B0	mult   s2, v0
800012B4	mflo   a0
800012B8	lw     v0, $0018(sp)
800012BC	nop
800012C0	mult   s2, v0
800012C4	sra    v1, v1, $0c
800012C8	lw     v0, $0014(s3)
800012CC	sra    a0, a0, $0c
800012D0	addu   v1, v1, v0
800012D4	sw     v1, $0014(s3)
800012D8	lui    v0, $801f
800012DC	lw     v0, $00c0(v0)
800012E0	lui    v1, $801f
800012E4	lw     v1, $00c4(v1)
800012E8	addu   a0, a0, v0
800012EC	lui    at, $801f
800012F0	sw     a0, $00c0(at)
800012F4	mflo   v0
800012F8	sra    v0, v0, $0c
800012FC	addu   v0, v0, v1
80001300	lui    at, $801f
80001304	sw     v0, $00c4(at)

L1308:	; 80001308
80001308	jal    func3b48c [$8003b48c]
8000130C	addu   a0, s3, zero
80001310	jal    func3b51c [$8003b51c]
80001314	addu   a0, s3, zero
80001318	addu   v0, s3, zero
8000131C	lw     ra, $0038(sp)
80001320	lw     s3, $0034(sp)
80001324	lw     s2, $0030(sp)
80001328	lw     s1, $002c(sp)
8000132C	lw     s0, $0028(sp)
80001330	addiu  sp, sp, $0040
80001334	jr     ra 
80001338	nop

8000133C	addiu  sp, sp, $ffd8 (=-$28)
80001340	sw     s0, $0018(sp)
80001344	lui    s0, $8010
80001348	addiu  s0, s0, $a63c (=-$59c4)
8000134C	lui    v0, $8015
80001350	lh     v0, $169c(v0)
80001354	addu   a0, s0, zero
80001358	sw     s2, $0020(sp)
8000135C	lui    s2, $8016
80001360	lw     s2, $3c74(s2)
80001364	lui    v1, $8016
80001368	addiu  v1, v1, $2978
8000136C	sw     ra, $0024(sp)
80001370	sw     s1, $001c(sp)
80001374	sll    v0, v0, $05
80001378	jal    func3b48c [$8003b48c]
8000137C	addu   s1, v0, v1
80001380	jal    func3b51c [$8003b51c]
80001384	addu   a0, s0, zero
80001388	addiu  a0, s1, $0004
8000138C	addiu  a1, s2, $0008
80001390	addiu  a2, sp, $0010
80001394	jal    func3bbdc [$8003bbdc]
80001398	addiu  a3, sp, $0014
8000139C	lhu    v1, $0008(s2)
800013A0	nop
800013A4	sltiu  v1, v1, $0140
800013A8	beq    v1, zero, L14c4 [$800014c4]
800013AC	addu   s0, v0, zero
800013B0	lhu    v0, $000a(s2)
800013B4	nop
800013B8	sltiu  v0, v0, $00a6
800013BC	beq    v0, zero, L14c4 [$800014c4]
800013C0	lui    v1, $0006
800013C4	lw     v0, $0014(sp)
800013C8	nop
800013CC	and    v0, v0, v1
800013D0	bne    v0, zero, L142c [$8000142c]
800013D4	nop
800013D8	jal    $800469b0
800013DC	addu   a0, s2, zero
800013E0	ori    v0, zero, $00ff
800013E4	jal    $80042da8
800013E8	sb     v0, $0004(s2)
800013EC	addu   a1, s2, zero
800013F0	sb     v0, $0005(s2)
800013F4	ori    v0, zero, $0002
800013F8	sra    a0, s0, $02
800013FC	sll    a0, a0, $02
80001400	sb     zero, $0006(s2)
80001404	sh     v0, $000c(s2)
80001408	sh     v0, $000e(s2)
8000140C	lui    v0, $8015
80001410	lw     v0, $17c0(v0)
80001414	addiu  a0, a0, $0070
80001418	jal    $80046794
8000141C	addu   a0, a0, v0
80001420	addiu  v0, s2, $0010
80001424	lui    at, $8016
80001428	sw     v0, $3c74(at)

L142c:	; 8000142C
8000142C	lui    v0, $8006
80001430	lbu    v0, $2d98(v0)
80001434	nop
80001438	bne    v0, zero, L14cc [$800014cc]
8000143C	nop
80001440	lhu    v0, $0004(s1)
80001444	lhu    a0, $000c(s1)
80001448	lhu    v1, $0006(s1)
8000144C	lhu    a1, $000e(s1)
80001450	addu   v0, v0, a0
80001454	sh     v0, $0004(s1)
80001458	lhu    v0, $0008(s1)
8000145C	addu   v1, v1, a1
80001460	sh     v1, $0006(s1)
80001464	lhu    v1, $0010(s1)
80001468	lh     a0, $000c(s1)
8000146C	addu   v0, v0, v1
80001470	sh     v0, $0008(s1)
80001474	sll    v0, a0, $03
80001478	subu   v0, v0, a0
8000147C	lh     v1, $000e(s1)
80001480	sra    v0, v0, $03
80001484	sh     v0, $000c(s1)
80001488	sll    v0, v1, $03
8000148C	subu   v0, v0, v1
80001490	lh     v1, $0010(s1)
80001494	sra    v0, v0, $03
80001498	sh     v0, $000e(s1)
8000149C	sll    v0, v1, $03
800014A0	subu   v0, v0, v1
800014A4	lhu    v1, $0002(s1)
800014A8	sra    v0, v0, $03
800014AC	sh     v0, $0010(s1)
800014B0	addiu  v1, v1, $ffff (=-$1)
800014B4	sh     v1, $0002(s1)
800014B8	sll    v1, v1, $10
800014BC	bne    v1, zero, L14cc [$800014cc]
800014C0	nop

L14c4:	; 800014C4
800014C4	addiu  v0, zero, $ffff (=-$1)
800014C8	sh     v0, $0000(s1)

L14cc:	; 800014CC
800014CC	lw     ra, $0024(sp)
800014D0	lw     s2, $0020(sp)
800014D4	lw     s1, $001c(sp)
800014D8	lw     s0, $0018(sp)
800014DC	addiu  sp, sp, $0028
800014E0	jr     ra 
800014E4	nop

800014E8	addiu  sp, sp, $ffe0 (=-$20)
800014EC	lui    v0, $8015
800014F0	lh     v0, $169c(v0)
800014F4	lui    v1, $8016
800014F8	addiu  v1, v1, $2978
800014FC	sw     ra, $0018(sp)
80001500	sw     s1, $0014(sp)
80001504	sw     s0, $0010(sp)
80001508	sll    v0, v0, $05
8000150C	addu   s1, v0, v1
80001510	lh     v1, $0002(s1)
80001514	nop
80001518	slti   v0, v1, $000a
8000151C	beq    v0, zero, L1548 [$80001548]
80001520	lui    s0, $1f80
80001524	lui    v0, $6666
80001528	ori    v0, v0, $6667
8000152C	sll    v1, v1, $0c
80001530	mult   v1, v0
80001534	sra    v1, v1, $1f
80001538	mfhi   v0
8000153C	sra    v0, v0, $02
80001540	j      $801b1564
80001544	subu   v0, v0, v1

L1548:	; 80001548
80001548	addiu  v1, v1, $fff6 (=-$a)
8000154C	slti   v0, v1, $001e
80001550	bne    v0, zero, L1564 [$80001564]
80001554	ori    v0, zero, $1000
80001558	addiu  v0, zero, $ffff (=-$1)
8000155C	j      $801b1780
80001560	sh     v0, $0000(s1)

L1564:	; 80001564
80001564	lui    at, $801f
80001568	sh     v0, $00f8(at)
8000156C	lui    at, $801f
80001570	sh     v0, $00f0(at)
80001574	lui    at, $801f
80001578	sh     v0, $00e8(at)
8000157C	lui    a0, $801f
80001580	addiu  a0, a0, $0430
80001584	lui    a1, $801f
80001588	addiu  a1, a1, $00e8
8000158C	jal    func3a63c [$8003a63c]
80001590	addu   a2, s0, zero
80001594	lui    a0, $8010
80001598	addiu  a0, a0, $a63c (=-$59c4)
8000159C	addu   a1, s0, zero
800015A0	jal    func3a63c [$8003a63c]
800015A4	addu   a2, s0, zero
800015A8	jal    func3b48c [$8003b48c]
800015AC	addu   a0, s0, zero
800015B0	jal    func3b51c [$8003b51c]
800015B4	addu   a0, s0, zero
800015B8	lui    a0, $801f
800015BC	addiu  a0, a0, $00c8
800015C0	ori    a2, zero, $000c
800015C4	lui    a1, $8015
800015C8	lw     a1, $17c0(a1)
800015CC	lui    a3, $8016
800015D0	lw     a3, $3c74(a3)
800015D4	jal    $800d29d4
800015D8	addiu  a1, a1, $0070
800015DC	lui    a0, $801f
800015E0	addiu  a0, a0, $00d8
800015E4	addu   a2, zero, zero
800015E8	lui    a1, $8015
800015EC	lw     a1, $17c0(a1)
800015F0	addu   a3, v0, zero
800015F4	lui    at, $8016
800015F8	sw     a3, $3c74(at)
800015FC	jal    $800d29d4
80001600	addiu  a1, a1, $406c
80001604	lui    a0, $8015
80001608	lw     a0, $17c0(a0)
8000160C	ori    a1, zero, $0040
80001610	lui    at, $8016
80001614	sw     v0, $3c74(at)
80001618	jal    $800d4484
8000161C	addiu  a0, a0, $406c
80001620	lui    v0, $8006
80001624	lbu    v0, $2d98(v0)
80001628	nop
8000162C	bne    v0, zero, L1780 [$80001780]
80001630	nop
80001634	lh     v1, $0002(s1)
80001638	nop
8000163C	slti   v0, v1, $0024
80001640	beq    v0, zero, L1770 [$80001770]
80001644	andi   v0, v1, $0003
80001648	bne    v0, zero, L1710 [$80001710]
8000164C	addu   v0, v1, zero
80001650	bgez   v0, L165c [$8000165c]
80001654	addu   t1, zero, zero
80001658	addiu  v0, v0, $0003

L165c:	; 8000165C
8000165C	lui    a2, $801d
80001660	addiu  a2, a2, $4290
80001664	addiu  a3, a2, $0004
80001668	sra    v0, v0, $02
8000166C	sll    v0, v0, $02
80001670	lui    at, $801f
80001674	addu   at, at, v0
80001678	lw     t0, $0108(at)
8000167C	lui    a0, $801f
80001680	lw     a0, $fec4(a0)
80001684	addiu  a1, t0, $0004

loop1688:	; 80001688
80001688	lh     v1, $0000(t0)
8000168C	lh     v0, $0000(a2)
80001690	nop
80001694	subu   v0, v1, v0
80001698	bgez   v0, L16a4 [$800016a4]
8000169C	nop
800016A0	addiu  v0, v0, $0003

L16a4:	; 800016A4
800016A4	sra    v0, v0, $02
800016A8	sh     v0, $0000(a0)
800016AC	lh     v1, $fffe(a1)
800016B0	lh     v0, $fffe(a3)
800016B4	nop
800016B8	subu   v0, v1, v0
800016BC	bgez   v0, L16c8 [$800016c8]
800016C0	nop
800016C4	addiu  v0, v0, $0003

L16c8:	; 800016C8
800016C8	sra    v0, v0, $02
800016CC	sh     v0, $0002(a0)
800016D0	lh     v1, $0000(a1)
800016D4	lh     v0, $0000(a3)
800016D8	nop
800016DC	subu   v0, v1, v0
800016E0	bgez   v0, L16ec [$800016ec]
800016E4	addiu  a1, a1, $0008
800016E8	addiu  v0, v0, $0003

L16ec:	; 800016EC
800016EC	sra    v0, v0, $02
800016F0	sh     v0, $0004(a0)
800016F4	addiu  t0, t0, $0008
800016F8	addiu  a3, a3, $0008
800016FC	addiu  a2, a2, $0008
80001700	addiu  t1, t1, $0001
80001704	slti   v0, t1, $00ca
80001708	bne    v0, zero, loop1688 [$80001688]
8000170C	addiu  a0, a0, $0008

L1710:	; 80001710
80001710	lui    a2, $801d
80001714	addiu  a2, a2, $4290
80001718	addu   t1, zero, zero
8000171C	lui    a1, $801f
80001720	lw     a1, $fec4(a1)
80001724	addiu  a0, a2, $0004

loop1728:	; 80001728
80001728	lhu    v0, $0000(a2)
8000172C	lhu    v1, $0000(a1)
80001730	addiu  t1, t1, $0001
80001734	addu   v0, v0, v1
80001738	sh     v0, $0000(a2)
8000173C	lhu    v0, $fffe(a0)
80001740	lhu    v1, $0002(a1)
80001744	addiu  a2, a2, $0008
80001748	addu   v0, v0, v1
8000174C	sh     v0, $fffe(a0)
80001750	lhu    v0, $0000(a0)
80001754	lhu    v1, $0004(a1)
80001758	addiu  a1, a1, $0008
8000175C	addu   v0, v0, v1
80001760	sh     v0, $0000(a0)
80001764	slti   v0, t1, $00ca
80001768	bne    v0, zero, loop1728 [$80001728]
8000176C	addiu  a0, a0, $0008

L1770:	; 80001770
80001770	lhu    v0, $0002(s1)
80001774	nop
80001778	addiu  v0, v0, $0001
8000177C	sh     v0, $0002(s1)

L1780:	; 80001780
80001780	lw     ra, $0018(sp)
80001784	lw     s1, $0014(sp)
80001788	lw     s0, $0010(sp)
8000178C	addiu  sp, sp, $0020
80001790	jr     ra 
80001794	nop

80001798	addiu  sp, sp, $ffe0 (=-$20)
8000179C	lui    v0, $8015
800017A0	lh     v0, $169c(v0)
800017A4	lui    v1, $8016
800017A8	addiu  v1, v1, $2978
800017AC	sw     ra, $0018(sp)
800017B0	sw     s1, $0014(sp)
800017B4	sw     s0, $0010(sp)
800017B8	sll    v0, v0, $05
800017BC	addu   s0, v0, v1
800017C0	lh     a2, $0002(s0)
800017C4	nop
800017C8	slti   v0, a2, $000a
800017CC	beq    v0, zero, L1840 [$80001840]
800017D0	lui    s1, $1f80
800017D4	lui    a1, $6666
800017D8	ori    a1, a1, $6667

L17dc:	; 800017DC
800017DC	sll    a0, a2, $0b
800017E0	mult   a0, a1
800017E4	sll    v1, a2, $01
800017E8	mfhi   v0
800017EC	addu   v1, v1, a2
800017F0	sll    v1, v1, $0c
800017F4	mult   v1, a1
800017F8	sra    a0, a0, $1f
800017FC	lui    at, $801f
80001800	sh     zero, $0136(at)
80001804	sra    v0, v0, $02
80001808	subu   v0, v0, a0
8000180C	addiu  v0, v0, $2000
80001810	sra    v1, v1, $1f
80001814	lui    at, $801f
80001818	sh     v0, $014c(at)
8000181C	lui    at, $801f
80001820	sh     v0, $013c(at)
80001824	mfhi   v0
80001828	sra    v0, v0, $02
8000182C	subu   v0, v0, v1
80001830	lui    at, $801f
80001834	sh     v0, $0144(at)
80001838	j      $801b18a8
8000183C	nop

L1840:	; 80001840
80001840	addiu  a2, a2, $fff6 (=-$a)
80001844	slti   v0, a2, $0005
80001848	beq    v0, zero, L189c [$8000189c]
8000184C	lui    v0, $6666
80001850	ori    v0, v0, $6667
80001854	sll    v1, a2, $0c
80001858	mult   v1, v0
8000185C	ori    v0, zero, $2800
80001860	lui    at, $801f
80001864	sh     v0, $014c(at)
80001868	lui    at, $801f
8000186C	sh     v0, $013c(at)
80001870	ori    v0, zero, $3000
80001874	sra    v1, v1, $1f
80001878	lui    at, $801f
8000187C	sh     v0, $0144(at)
80001880	mfhi   v0
80001884	sra    v0, v0, $01
80001888	subu   v0, v0, v1
8000188C	lui    at, $801f
80001890	sh     v0, $0136(at)
80001894	j      $801b18a8
80001898	nop

L189c:	; 8000189C
8000189C	addiu  v0, zero, $ffff (=-$1)
800018A0	j      $801b1940
800018A4	sh     v0, $0000(s0)
800018A8	lui    a0, $801f
800018AC	addiu  a0, a0, $0430
800018B0	lui    a1, $801f
800018B4	addiu  a1, a1, $013c
800018B8	jal    func3a63c [$8003a63c]
800018BC	addu   a2, s1, zero
800018C0	lui    a0, $8010
800018C4	addiu  a0, a0, $a63c (=-$59c4)
800018C8	addu   a1, s1, zero
800018CC	jal    func3a63c [$8003a63c]
800018D0	addu   a2, s1, zero
800018D4	jal    func3b48c [$8003b48c]
800018D8	addu   a0, s1, zero
800018DC	jal    func3b51c [$8003b51c]
800018E0	addu   a0, s1, zero
800018E4	addu   a0, zero, zero
800018E8	addu   a1, zero, zero
800018EC	jal    func3b69c [$8003b69c]
800018F0	addu   a2, zero, zero
800018F4	lui    a0, $801f
800018F8	addiu  a0, a0, $012c
800018FC	ori    a2, zero, $000c
80001900	lui    a1, $8015
80001904	lw     a1, $17c0(a1)
80001908	lui    a3, $8016
8000190C	lw     a3, $3c74(a3)
80001910	jal    $800d29d4
80001914	addiu  a1, a1, $0070
80001918	lui    v1, $8006
8000191C	lbu    v1, $2d98(v1)
80001920	lui    at, $8016
80001924	sw     v0, $3c74(at)
80001928	bne    v1, zero, L1940 [$80001940]
8000192C	nop
80001930	lhu    v0, $0002(s0)
80001934	nop
80001938	addiu  v0, v0, $0001
8000193C	sh     v0, $0002(s0)

L1940:	; 80001940
80001940	lw     ra, $0018(sp)
80001944	lw     s1, $0014(sp)
80001948	lw     s0, $0010(sp)
8000194C	addiu  sp, sp, $0020
80001950	jr     ra 
80001954	nop

80001958	addiu  sp, sp, $ffc8 (=-$38)
8000195C	sw     s1, $0014(sp)
80001960	lui    s1, $1f80
80001964	ori    s1, s1, $0020
80001968	sw     s7, $002c(sp)
8000196C	lui    s7, $1f80
80001970	ori    s7, s7, $0030
80001974	lui    v0, $8015
80001978	lh     v0, $169c(v0)
8000197C	lui    v1, $8016
80001980	addiu  v1, v1, $2978
80001984	sw     ra, $0030(sp)
80001988	sw     s6, $0028(sp)
8000198C	sw     s5, $0024(sp)
80001990	sw     s4, $0020(sp)
80001994	sw     s3, $001c(sp)
80001998	sw     s2, $0018(sp)
8000199C	sw     s0, $0010(sp)
800019A0	sll    v0, v0, $05
800019A4	addu   s5, v0, v1
800019A8	lh     a1, $0002(s5)
800019AC	nop
800019B0	slti   v0, a1, $001e
800019B4	beq    v0, zero, L1a34 [$80001a34]
800019B8	lui    s4, $1f80
800019BC	lui    v0, $8888
800019C0	ori    v0, v0, $8889
800019C4	sll    v1, a1, $05
800019C8	subu   v1, v1, a1
800019CC	sll    v1, v1, $02
800019D0	addu   v1, v1, a1
800019D4	sll    v1, v1, $04
800019D8	subu   v1, zero, v1
800019DC	mult   v1, v0
800019E0	ori    v0, zero, $1a00
800019E4	lui    at, $1f80
800019E8	sw     v0, $0028(at)
800019EC	lui    at, $1f80
800019F0	sw     v0, $0024(at)
800019F4	sw     v0, $0000(s1)
800019F8	ori    v0, zero, $1c00
800019FC	lui    at, $1f80
80001A00	sw     v0, $0038(at)
80001A04	lui    at, $1f80
80001A08	sw     v0, $0034(at)
80001A0C	sw     v0, $0000(s7)
80001A10	lui    at, $801f
80001A14	sh     zero, $0166(at)
80001A18	mfhi   v0
80001A1C	addu   v0, v0, v1
80001A20	sra    v0, v0, $04
80001A24	sra    v1, v1, $1f
80001A28	subu   v0, v0, v1
80001A2C	j      $801b1b1c
80001A30	addiu  s6, v0, $fb50 (=-$4b0)

L1a34:	; 80001A34
80001A34	addiu  a1, a1, $ffe2 (=-$1e)
80001A38	slti   v0, a1, $0032
80001A3C	beq    v0, zero, L1b10 [$80001b10]
80001A40	lui    a0, $51eb
80001A44	ori    a0, a0, $851f
80001A48	sll    v0, a1, $02
80001A4C	addu   v0, v0, a1
80001A50	sll    v0, v0, $0c
80001A54	mult   v0, a0
80001A58	sll    a1, a1, $0c
80001A5C	sra    v0, v0, $1f
80001A60	mfhi   v1
80001A64	sra    v1, v1, $04
80001A68	subu   v1, v1, v0
80001A6C	addiu  v1, v1, $1000
80001A70	sll    v0, v1, $01
80001A74	addu   v0, v0, v1
80001A78	mult   a1, a0
80001A7C	sll    v0, v0, $02
80001A80	addu   v0, v0, v1
80001A84	sll    v0, v0, $09
80001A88	sra    v0, v0, $0c
80001A8C	lui    at, $1f80
80001A90	sw     v0, $0024(at)
80001A94	sll    v0, v1, $03
80001A98	subu   v0, v0, v1
80001A9C	sll    v0, v0, $0a
80001AA0	sra    v0, v0, $0c
80001AA4	sra    a1, a1, $1f
80001AA8	sw     v0, $0000(s7)
80001AAC	mfhi   a0
80001AB0	sra    a0, a0, $04
80001AB4	subu   a0, a0, a1
80001AB8	addiu  v1, a0, $1000
80001ABC	sll    v0, v1, $01
80001AC0	addu   v0, v0, v1
80001AC4	sll    v0, v0, $02
80001AC8	addu   v0, v0, v1
80001ACC	sll    v0, v0, $09
80001AD0	sra    v0, v0, $0c
80001AD4	lui    at, $1f80
80001AD8	sw     v0, $0028(at)
80001ADC	sw     v0, $0000(s1)
80001AE0	sll    v0, v1, $03
80001AE4	subu   v0, v0, v1
80001AE8	sll    v0, v0, $0a
80001AEC	sra    v0, v0, $0c
80001AF0	lui    at, $1f80
80001AF4	sw     v0, $0038(at)
80001AF8	lui    at, $1f80
80001AFC	sw     v0, $0034(at)
80001B00	lui    at, $801f
80001B04	sh     a0, $0166(at)
80001B08	j      $801b1b1c
80001B0C	addiu  s6, zero, $f380 (=-$c80)

L1b10:	; 80001B10
80001B10	addiu  v0, zero, $ffff (=-$1)
80001B14	j      $801b1c58
80001B18	sh     v0, $0000(s5)
80001B1C	addu   a0, zero, zero
80001B20	addu   a1, zero, zero
80001B24	jal    func3b69c [$8003b69c]
80001B28	addu   a2, zero, zero
80001B2C	lui    s0, $801f
80001B30	addiu  s0, s0, $016e
80001B34	addiu  s2, s0, $fffe (=-$2)
80001B38	addu   a0, s2, zero
80001B3C	lh     v0, $0002(s5)
80001B40	addu   a1, s4, zero
80001B44	sll    v0, v0, $06
80001B48	jal    func3c21c [$8003c21c]
80001B4C	sh     v0, $0000(s0)
80001B50	addu   a0, s4, zero
80001B54	jal    func3ad14 [$8003ad14]
80001B58	addu   a1, s1, zero
80001B5C	lui    s3, $801f
80001B60	addiu  s3, s3, $0450
80001B64	addu   a0, s3, zero
80001B68	addu   a1, s4, zero
80001B6C	addu   a2, s4, zero
80001B70	sw     zero, $0014(s4)
80001B74	sw     s6, $0018(s4)
80001B78	jal    func3a63c [$8003a63c]
80001B7C	sw     zero, $001c(s4)
80001B80	jal    func3b48c [$8003b48c]
80001B84	addu   a0, s4, zero
80001B88	jal    func3b51c [$8003b51c]
80001B8C	addu   a0, s4, zero
80001B90	lui    s1, $801f
80001B94	addiu  s1, s1, $015c
80001B98	addu   a0, s1, zero
80001B9C	ori    a2, zero, $000c
80001BA0	lui    a1, $8015
80001BA4	lw     a1, $17c0(a1)
80001BA8	lui    a3, $8016
80001BAC	lw     a3, $3c74(a3)
80001BB0	jal    $800d29d4
80001BB4	addiu  a1, a1, $0070
80001BB8	addu   a0, s2, zero
80001BBC	lh     v1, $0002(s5)
80001BC0	addu   a1, s4, zero
80001BC4	lui    at, $8016
80001BC8	sw     v0, $3c74(at)
80001BCC	sll    v1, v1, $06
80001BD0	jal    func3c21c [$8003c21c]
80001BD4	sh     v1, $0000(s0)
80001BD8	addu   a0, s4, zero
80001BDC	jal    func3ad14 [$8003ad14]
80001BE0	addu   a1, s7, zero
80001BE4	addu   a0, s3, zero
80001BE8	addu   a1, s4, zero
80001BEC	addu   a2, s4, zero
80001BF0	sw     zero, $0014(s4)
80001BF4	sw     s6, $0018(s4)
80001BF8	jal    func3a63c [$8003a63c]
80001BFC	sw     zero, $001c(s4)
80001C00	jal    func3b48c [$8003b48c]
80001C04	addu   a0, s4, zero
80001C08	jal    func3b51c [$8003b51c]
80001C0C	addu   a0, s4, zero
80001C10	addu   a0, s1, zero
80001C14	ori    a2, zero, $000c
80001C18	lui    a1, $8015
80001C1C	lw     a1, $17c0(a1)
80001C20	lui    a3, $8016
80001C24	lw     a3, $3c74(a3)
80001C28	jal    $800d29d4
80001C2C	addiu  a1, a1, $0070
80001C30	lui    v1, $8006
80001C34	lbu    v1, $2d98(v1)
80001C38	lui    at, $8016
80001C3C	sw     v0, $3c74(at)
80001C40	bne    v1, zero, L1c58 [$80001c58]
80001C44	nop
80001C48	lhu    v0, $0002(s5)
80001C4C	nop
80001C50	addiu  v0, v0, $0001
80001C54	sh     v0, $0002(s5)

L1c58:	; 80001C58
80001C58	lw     ra, $0030(sp)
80001C5C	lw     s7, $002c(sp)
80001C60	lw     s6, $0028(sp)
80001C64	lw     s5, $0024(sp)
80001C68	lw     s4, $0020(sp)
80001C6C	lw     s3, $001c(sp)
80001C70	lw     s2, $0018(sp)
80001C74	lw     s1, $0014(sp)
80001C78	lw     s0, $0010(sp)
80001C7C	addiu  sp, sp, $0038
80001C80	jr     ra 
80001C84	nop

80001C88	addiu  sp, sp, $ffe0 (=-$20)
80001C8C	lui    v0, $8015
80001C90	lh     v0, $169c(v0)
80001C94	lui    v1, $8016
80001C98	addiu  v1, v1, $2978
80001C9C	sw     ra, $0018(sp)
80001CA0	sw     s1, $0014(sp)
80001CA4	sw     s0, $0010(sp)
80001CA8	sll    v0, v0, $05
80001CAC	addu   s0, v0, v1
80001CB0	lh     v1, $0002(s0)
80001CB4	nop
80001CB8	slti   v0, v1, $0005
80001CBC	beq    v0, zero, L1cd4 [$80001cd4]
80001CC0	lui    s1, $1f80
80001CC4	lui    at, $801f
80001CC8	sh     zero, $017e(at)
80001CCC	j      $801b1d1c
80001CD0	nop

L1cd4:	; 80001CD4
80001CD4	addiu  v1, v1, $fffb (=-$5)
80001CD8	slti   v0, v1, $0005
80001CDC	beq    v0, zero, L1d10 [$80001d10]
80001CE0	lui    v0, $6666
80001CE4	ori    v0, v0, $6667
80001CE8	sll    v1, v1, $0c
80001CEC	mult   v1, v0
80001CF0	sra    v1, v1, $1f
80001CF4	mfhi   v0
80001CF8	sra    v0, v0, $01
80001CFC	subu   v0, v0, v1
80001D00	lui    at, $801f
80001D04	sh     v0, $017e(at)
80001D08	j      $801b1d1c
80001D0C	nop

L1d10:	; 80001D10
80001D10	addiu  v0, zero, $ffff (=-$1)
80001D14	j      $801b1e40
80001D18	sh     v0, $0000(s0)
80001D1C	lh     v0, $000c(s0)
80001D20	lh     v1, $0002(s0)
80001D24	addiu  v0, v0, $fd00 (=-$300)
80001D28	mult   v0, v1
80001D2C	mflo   v1
80001D30	lui    a0, $6666
80001D34	ori    a0, a0, $6667
80001D38	mult   v1, a0
80001D3C	lui    a1, $801f
80001D40	addiu  a1, a1, $0184
80001D44	sra    v1, v1, $1f
80001D48	mfhi   v0
80001D4C	sra    v0, v0, $02
80001D50	subu   v0, v0, v1
80001D54	addiu  v0, v0, $0300
80001D58	lui    at, $801f
80001D5C	sh     v0, $018c(at)
80001D60	sh     v0, $0000(a1)
80001D64	lh     v0, $000e(s0)
80001D68	lh     v1, $0002(s0)
80001D6C	addiu  v0, v0, $fd00 (=-$300)
80001D70	mult   v0, v1
80001D74	mflo   v1
80001D78	nop
80001D7C	nop
80001D80	mult   v1, a0
80001D84	sra    v1, v1, $1f
80001D88	mfhi   v0
80001D8C	sra    v0, v0, $02
80001D90	subu   v0, v0, v1
80001D94	addiu  v0, v0, $0300
80001D98	lui    at, $801f
80001D9C	sh     v0, $0194(at)
80001DA0	lh     v0, $0004(s0)
80001DA4	lui    at, $801f
80001DA8	sw     v0, $0198(at)
80001DAC	lh     v0, $0006(s0)
80001DB0	lui    at, $801f
80001DB4	sw     v0, $019c(at)
80001DB8	lh     v0, $0008(s0)
80001DBC	lui    a0, $801f
80001DC0	addiu  a0, a0, $0450
80001DC4	lui    at, $801f
80001DC8	sw     v0, $01a0(at)
80001DCC	jal    func3a63c [$8003a63c]
80001DD0	addu   a2, s1, zero
80001DD4	jal    func3b48c [$8003b48c]
80001DD8	addu   a0, s1, zero
80001DDC	jal    func3b51c [$8003b51c]
80001DE0	addu   a0, s1, zero
80001DE4	addu   a0, zero, zero
80001DE8	addu   a1, zero, zero
80001DEC	jal    func3b69c [$8003b69c]
80001DF0	addu   a2, zero, zero
80001DF4	lui    a0, $801f
80001DF8	addiu  a0, a0, $0174
80001DFC	ori    a2, zero, $000c
80001E00	lui    a1, $8015
80001E04	lw     a1, $17c0(a1)
80001E08	lui    a3, $8016
80001E0C	lw     a3, $3c74(a3)
80001E10	jal    $800d29d4
80001E14	addiu  a1, a1, $0070
80001E18	lui    v1, $8006
80001E1C	lbu    v1, $2d98(v1)
80001E20	lui    at, $8016
80001E24	sw     v0, $3c74(at)
80001E28	bne    v1, zero, L1e40 [$80001e40]
80001E2C	nop
80001E30	lhu    v0, $0002(s0)
80001E34	nop
80001E38	addiu  v0, v0, $0001
80001E3C	sh     v0, $0002(s0)

L1e40:	; 80001E40
80001E40	lw     ra, $0018(sp)
80001E44	lw     s1, $0014(sp)
80001E48	lw     s0, $0010(sp)
80001E4C	addiu  sp, sp, $0020
80001E50	jr     ra 
80001E54	nop

80001E58	addiu  sp, sp, $ffc8 (=-$38)
80001E5C	sw     s4, $0028(sp)
80001E60	lui    s4, $1f80
80001E64	ori    s4, s4, $0040
80001E68	sw     s2, $0020(sp)
80001E6C	lui    s2, $1f80
80001E70	lui    v0, $8015
80001E74	lh     v0, $169c(v0)
80001E78	ori    s2, s2, $0048
80001E7C	sw     s0, $0018(sp)
80001E80	lui    s0, $8016
80001E84	addiu  s0, s0, $2978
80001E88	sw     ra, $0030(sp)
80001E8C	sw     s5, $002c(sp)
80001E90	sw     s3, $0024(sp)
80001E94	sw     s1, $001c(sp)
80001E98	sll    v0, v0, $05
80001E9C	addu   s5, v0, s0
80001EA0	lh     t0, $0002(s5)
80001EA4	nop
80001EA8	slti   v0, t0, $0014
80001EAC	bne    v0, zero, L1ec0 [$80001ec0]
80001EB0	lui    s3, $1f80
80001EB4	addiu  v0, zero, $ffff (=-$1)
80001EB8	j      $801b21cc
80001EBC	sh     v0, $0000(s5)

L1ec0:	; 80001EC0
80001EC0	lui    v0, $6666
80001EC4	ori    v0, v0, $6667
80001EC8	lui    a0, $801f
80001ECC	addiu  a0, a0, $0430
80001ED0	sll    v1, t0, $02
80001ED4	addu   v1, v1, t0
80001ED8	sll    v1, v1, $02
80001EDC	addu   v1, v1, t0
80001EE0	sll    v1, v1, $08
80001EE4	lui    a3, $801f
80001EE8	addiu  a3, a3, $01c4
80001EEC	addiu  a1, a3, $fff0 (=-$10)
80001EF0	mult   v1, v0
80001EF4	lui    a2, $1f80
80001EF8	sll    v0, t0, $01
80001EFC	addu   v0, v0, t0
80001F00	sll    v0, v0, $04
80001F04	subu   v0, v0, t0
80001F08	sll    v0, v0, $03
80001F0C	subu   v0, v0, t0
80001F10	sll    v0, v0, $02
80001F14	addiu  v0, v0, $ec78 (=-$1388)
80001F18	sra    v1, v1, $1f
80001F1C	lui    at, $801f
80001F20	sw     v0, $01d0(at)
80001F24	mfhi   v0
80001F28	sra    v0, v0, $03
80001F2C	subu   v0, v0, v1
80001F30	addiu  v0, v0, $0300
80001F34	subu   v0, zero, v0
80001F38	jal    func3a63c [$8003a63c]
80001F3C	sh     v0, $0000(a3)
80001F40	lui    a0, $8010
80001F44	addiu  a0, a0, $a63c (=-$59c4)
80001F48	lui    a1, $1f80
80001F4C	lui    a2, $1f80
80001F50	jal    func3a63c [$8003a63c]
80001F54	ori    a2, a2, $0020
80001F58	lui    a0, $1f80
80001F5C	jal    func3b48c [$8003b48c]
80001F60	ori    a0, a0, $0020
80001F64	lui    a0, $1f80
80001F68	jal    func3b51c [$8003b51c]
80001F6C	ori    a0, a0, $0020
80001F70	lui    a0, $801f
80001F74	addiu  a0, a0, $01a4
80001F78	ori    a2, zero, $000c
80001F7C	lui    a1, $8015
80001F80	lw     a1, $17c0(a1)
80001F84	lui    a3, $8016
80001F88	lw     a3, $3c74(a3)
80001F8C	jal    $800d29d4
80001F90	addiu  a1, a1, $0070
80001F94	lui    v1, $8006
80001F98	lbu    v1, $2d98(v1)
80001F9C	lui    at, $8016
80001FA0	sw     v0, $3c74(at)
80001FA4	bne    v1, zero, L21cc [$800021cc]
80001FA8	nop
80001FAC	lhu    v0, $0002(s5)
80001FB0	nop
80001FB4	andi   v0, v0, $0001
80001FB8	bne    v0, zero, L2058 [$80002058]
80001FBC	nop
80001FC0	lui    a0, $801b
80001FC4	addiu  a0, a0, $1c88
80001FC8	jal    $800bbeac
80001FCC	nop
80001FD0	sll    v0, v0, $05
80001FD4	lui    v1, $801f
80001FD8	lhu    v1, $01c8(v1)
80001FDC	addu   s1, v0, s0
80001FE0	sh     v1, $0004(s1)
80001FE4	lui    v0, $801f
80001FE8	lhu    v0, $01cc(v0)
80001FEC	nop
80001FF0	sh     v0, $0006(s1)
80001FF4	lui    v0, $801f
80001FF8	lhu    v0, $01d0(v0)
80001FFC	nop
80002000	addiu  v0, v0, $fc18 (=-$3e8)
80002004	jal    $80042da8
80002008	sh     v0, $0008(s1)
8000200C	addu   v1, v0, zero
80002010	bgez   v1, L2020 [$80002020]
80002014	sra    v0, v0, $08
80002018	addiu  v0, v1, $00ff
8000201C	sra    v0, v0, $08

L2020:	; 80002020
80002020	sll    v0, v0, $08
80002024	subu   v0, v1, v0
80002028	addiu  v0, v0, $0300
8000202C	jal    $80042da8
80002030	sh     v0, $000c(s1)
80002034	addu   v1, v0, zero
80002038	bgez   v1, L2048 [$80002048]
8000203C	sra    v0, v0, $09
80002040	addiu  v0, v1, $01ff
80002044	sra    v0, v0, $09

L2048:	; 80002048
80002048	sll    v0, v0, $09
8000204C	subu   v0, v1, v0
80002050	addiu  v0, v0, $0400
80002054	sh     v0, $000e(s1)

L2058:	; 80002058
80002058	jal    func3b48c [$8003b48c]
8000205C	addu   a0, s3, zero
80002060	jal    func3b51c [$8003b51c]
80002064	addu   a0, s3, zero
80002068	addu   s3, zero, zero

loop206c:	; 8000206C
8000206C	lui    a0, $801b
80002070	addiu  a0, a0, $133c
80002074	jal    $800bbeac
80002078	addiu  s3, s3, $0001
8000207C	sll    v0, v0, $05
80002080	lui    v1, $8016
80002084	addiu  v1, v1, $2978
80002088	jal    $80042da8
8000208C	addu   s1, v0, v1
80002090	lui    v1, $0779
80002094	ori    v1, v1, $75b9
80002098	mult   v0, v1
8000209C	lui    s0, $801e
800020A0	addiu  s0, s0, $9860 (=-$67a0)
800020A4	addu   a1, s2, zero
800020A8	addiu  a2, sp, $0010
800020AC	sra    v1, v0, $1f
800020B0	mfhi   a0
800020B4	sra    a0, a0, $02
800020B8	subu   a0, a0, v1
800020BC	sll    v1, a0, $04
800020C0	addu   v1, v1, a0
800020C4	sll    v1, v1, $03
800020C8	addu   v1, v1, a0
800020CC	subu   v0, v0, v1
800020D0	sll    v0, v0, $03
800020D4	addu   s0, v0, s0
800020D8	jal    func3bc6c [$8003bc6c]
800020DC	addu   a0, s0, zero
800020E0	lhu    v0, $0000(s2)
800020E4	nop
800020E8	sh     v0, $0004(s1)
800020EC	lhu    v0, $0004(s2)
800020F0	nop
800020F4	sh     v0, $0006(s1)
800020F8	lhu    v0, $0008(s2)
800020FC	nop

L2100:	; 80002100
80002100	sh     v0, $0008(s1)
80002104	lhu    v0, $0000(s0)
80002108	nop
8000210C	sll    v0, v0, $10
80002110	sra    v1, v0, $10
80002114	srl    v0, v0, $1f
80002118	addu   v1, v1, v0
8000211C	sra    v1, v1, $01
80002120	sh     v1, $0000(s4)
80002124	lhu    v0, $0002(s0)
80002128	nop
8000212C	sll    v0, v0, $10
80002130	sra    v1, v0, $10
80002134	srl    v0, v0, $1f
80002138	addu   v1, v1, v0
8000213C	sra    v1, v1, $01
80002140	jal    $80042da8
80002144	sh     v1, $0002(s4)
80002148	lui    v1, $51eb
8000214C	ori    v1, v1, $851f
80002150	mult   v0, v1
80002154	addu   a0, s4, zero
80002158	addu   a1, s2, zero
8000215C	sra    v1, v0, $1f
80002160	mfhi   a2
80002164	sra    a2, a2, $04
80002168	subu   a2, a2, v1
8000216C	sll    v1, a2, $01
80002170	addu   v1, v1, a2
80002174	sll    v1, v1, $03
80002178	addu   v1, v1, a2
8000217C	sll    v1, v1, $01
80002180	subu   v0, v0, v1
80002184	jal    func3ace4 [$8003ace4]
80002188	sh     v0, $0004(s4)
8000218C	lhu    v0, $0000(s2)
80002190	nop
80002194	sh     v0, $000c(s1)
80002198	lhu    v0, $0004(s2)
8000219C	nop
800021A0	sh     v0, $000e(s1)
800021A4	lhu    v1, $0008(s2)
800021A8	ori    v0, zero, $000f
800021AC	sh     v0, $0002(s1)
800021B0	slti   v0, s3, $000f
800021B4	bne    v0, zero, loop206c [$8000206c]
800021B8	sh     v1, $0010(s1)
800021BC	lhu    v0, $0002(s5)
800021C0	nop
800021C4	addiu  v0, v0, $0001
800021C8	sh     v0, $0002(s5)

L21cc:	; 800021CC
800021CC	lw     ra, $0030(sp)
800021D0	lw     s5, $002c(sp)
800021D4	lw     s4, $0028(sp)
800021D8	lw     s3, $0024(sp)
800021DC	lw     s2, $0020(sp)
800021E0	lw     s1, $001c(sp)
800021E4	lw     s0, $0018(sp)
800021E8	addiu  sp, sp, $0038
800021EC	jr     ra 
800021F0	nop

800021F4	addiu  sp, sp, $ffe8 (=-$18)
800021F8	lui    v0, $8015
800021FC	lh     v0, $169c(v0)
80002200	lui    v1, $8016
80002204	addiu  v1, v1, $2978
80002208	sw     ra, $0014(sp)
8000220C	sw     s0, $0010(sp)
80002210	sll    v0, v0, $05
80002214	addu   s0, v0, v1
80002218	lh     v0, $0004(s0)
8000221C	lui    a1, $801f
80002220	addiu  a1, a1, $0218
80002224	lui    at, $801f
80002228	sw     zero, $021c(at)
8000222C	sw     v0, $0000(a1)
80002230	lh     v0, $0008(s0)
80002234	lui    a0, $801f
80002238	addiu  a0, a0, $0450
8000223C	lui    at, $801f
80002240	sw     v0, $0220(at)
80002244	lhu    v0, $000c(s0)
80002248	lui    a2, $1f80
8000224C	lui    at, $801f
80002250	sh     v0, $0210(at)
80002254	lhu    v0, $000e(s0)
80002258	lui    at, $801f
8000225C	sh     v0, $020c(at)
80002260	jal    func3a63c [$8003a63c]
80002264	addiu  a1, a1, $ffec (=-$14)
80002268	jal    func3b48c [$8003b48c]
8000226C	lui    a0, $1f80
80002270	jal    func3b51c [$8003b51c]
80002274	lui    a0, $1f80
80002278	lui    v1, $38e3
8000227C	lhu    v0, $0002(s0)
80002280	ori    v1, v1, $8e39
80002284	sll    v0, v0, $10
80002288	sra    a1, v0, $10
8000228C	mult   a1, v1
80002290	lui    a0, $801f
80002294	addiu  a0, a0, $01d4
80002298	ori    a2, zero, $000c
8000229C	sra    v0, v0, $1f
800022A0	mfhi   v1
800022A4	sra    v1, v1, $01
800022A8	subu   v1, v1, v0
800022AC	sll    v0, v1, $03
800022B0	addu   v0, v0, v1
800022B4	subu   a1, a1, v0
800022B8	sll    a1, a1, $10
800022BC	sra    a1, a1, $0e
800022C0	lui    at, $801f
800022C4	addu   at, at, a1
800022C8	lw     v0, $01e0(at)
800022CC	lui    a1, $8015
800022D0	lw     a1, $17c0(a1)
800022D4	lui    a3, $8016
800022D8	lw     a3, $3c74(a3)
800022DC	addiu  a1, a1, $0070
800022E0	jal    $800d4d90
800022E4	sw     v0, $0000(a0)
800022E8	lui    v1, $8006
800022EC	lbu    v1, $2d98(v1)
800022F0	lui    at, $8016
800022F4	sw     v0, $3c74(at)
800022F8	bne    v1, zero, L2328 [$80002328]
800022FC	nop
80002300	lhu    v0, $0002(s0)
80002304	nop
80002308	addiu  v0, v0, $0001
8000230C	sh     v0, $0002(s0)
80002310	sll    v0, v0, $10
80002314	sra    v0, v0, $10
80002318	slti   v0, v0, $0009
8000231C	bne    v0, zero, L2328 [$80002328]
80002320	addiu  v0, zero, $ffff (=-$1)
80002324	sh     v0, $0000(s0)

L2328:	; 80002328
80002328	lw     ra, $0014(sp)
8000232C	lw     s0, $0010(sp)
80002330	addiu  sp, sp, $0018
80002334	jr     ra 
80002338	nop

8000233C	addiu  sp, sp, $ffe0 (=-$20)
80002340	lui    v0, $8015
80002344	lh     v0, $169c(v0)
80002348	lui    a0, $8006
8000234C	lbu    a0, $2d98(a0)
80002350	lui    v1, $8016
80002354	addiu  v1, v1, $2978
80002358	sw     ra, $001c(sp)
8000235C	sw     s2, $0018(sp)
80002360	sw     s1, $0014(sp)
80002364	sw     s0, $0010(sp)
80002368	sll    v0, v0, $05
8000236C	bne    a0, zero, L24a8 [$800024a8]
80002370	addu   s2, v0, v1
80002374	addu   s1, zero, zero

loop2378:	; 80002378
80002378	lui    a0, $801b
8000237C	addiu  a0, a0, $21f4
80002380	jal    $800bbeac
80002384	nop
80002388	sll    v0, v0, $05
8000238C	lui    v1, $8016
80002390	addiu  v1, v1, $2978
80002394	jal    $80042da8
80002398	addu   s0, v0, v1
8000239C	lui    v1, $0576
800023A0	ori    v1, v1, $19f1
800023A4	mult   v0, v1
800023A8	sra    v1, v0, $1f
800023AC	mfhi   a0
800023B0	sra    a0, a0, $07
800023B4	subu   a0, a0, v1
800023B8	sll    v1, a0, $01
800023BC	addu   v1, v1, a0
800023C0	sll    v1, v1, $04
800023C4	subu   v1, v1, a0
800023C8	sll    v1, v1, $03
800023CC	subu   v1, v1, a0
800023D0	sll    v1, v1, $04
800023D4	subu   v0, v0, v1
800023D8	addiu  v0, v0, $f448 (=-$bb8)
800023DC	jal    $80042da8
800023E0	sh     v0, $0004(s0)
800023E4	lui    v1, $68db
800023E8	ori    v1, v1, $8bad
800023EC	mult   v0, v1
800023F0	sra    v1, v0, $1f
800023F4	mfhi   a0
800023F8	sra    a0, a0, $0c
800023FC	subu   a0, a0, v1
80002400	sll    v1, a0, $02
80002404	addu   v1, v1, a0
80002408	sll    v1, v1, $03
8000240C	subu   v1, v1, a0
80002410	sll    v1, v1, $04
80002414	addu   v1, v1, a0
80002418	sll    v1, v1, $04
8000241C	subu   v0, v0, v1
80002420	jal    $80042da8
80002424	sh     v0, $0008(s0)
80002428	addu   v1, v0, zero
8000242C	bgez   v1, L243c [$8000243c]
80002430	sra    v0, v0, $0c
80002434	addiu  v0, v1, $0fff
80002438	sra    v0, v0, $0c

L243c:	; 8000243C
8000243C	sll    v0, v0, $0c
80002440	subu   v0, v1, v0
80002444	addiu  v0, v0, $1800
80002448	jal    $80042da8
8000244C	sh     v0, $000c(s0)
80002450	addu   v1, v0, zero
80002454	bgez   v1, L2460 [$80002460]
80002458	addiu  s1, s1, $0001
8000245C	addiu  v0, v1, $0fff

L2460:	; 80002460
80002460	sra    v0, v0, $0c
80002464	sll    v0, v0, $0c
80002468	subu   v0, v1, v0
8000246C	addiu  v0, v0, $1800
80002470	sh     v0, $000e(s0)
80002474	slti   v0, s1, $0003
80002478	bne    v0, zero, loop2378 [$80002378]
8000247C	nop
80002480	lhu    v0, $0002(s2)
80002484	nop
80002488	addiu  v0, v0, $0001
8000248C	sh     v0, $0002(s2)
80002490	sll    v0, v0, $10
80002494	sra    v0, v0, $10
80002498	slti   v0, v0, $0006
8000249C	bne    v0, zero, L24a8 [$800024a8]
800024A0	addiu  v0, zero, $ffff (=-$1)
800024A4	sh     v0, $0000(s2)

L24a8:	; 800024A8
800024A8	lw     ra, $001c(sp)
800024AC	lw     s2, $0018(sp)
800024B0	lw     s1, $0014(sp)
800024B4	lw     s0, $0010(sp)
800024B8	addiu  sp, sp, $0020
800024BC	jr     ra 
800024C0	nop

800024C4	addiu  sp, sp, $ffc8 (=-$38)
800024C8	lui    v0, $8015
800024CC	lh     v0, $169c(v0)
800024D0	lui    v1, $8016
800024D4	addiu  v1, v1, $2978
800024D8	sw     ra, $0030(sp)
800024DC	sw     s5, $002c(sp)
800024E0	sw     s4, $0028(sp)
800024E4	sw     s3, $0024(sp)
800024E8	sw     s2, $0020(sp)
800024EC	sw     s1, $001c(sp)
800024F0	sw     s0, $0018(sp)
800024F4	sll    v0, v0, $05
800024F8	addu   s4, v0, v1
800024FC	lh     v0, $0002(s4)
80002500	nop
80002504	bne    v0, zero, L28ec [$800028ec]
80002508	nop
8000250C	lui    a0, $801f
80002510	addiu  a0, a0, $0228
80002514	lui    a1, $801f
80002518	addiu  a1, a1, $0230
8000251C	jal    $800d2538
80002520	addu   s0, zero, zero
80002524	lui    t6, $0900
80002528	lui    t5, $2e80
8000252C	ori    t5, t5, $80ff
80002530	ori    s3, zero, $010c
80002534	ori    s2, zero, $0041
80002538	ori    t7, zero, $00ff
8000253C	addu   t2, zero, zero
80002540	addu   t1, zero, zero
80002544	addu   s5, zero, zero

L2548:	; 80002548
80002548	lui    v0, $801f
8000254C	lw     v0, $0224(v0)
80002550	addu   a3, zero, zero
80002554	addu   v0, s5, v0
80002558	lui    at, $801f
8000255C	sw     v0, $03dc(at)
80002560	slti   v0, a3, $0014

loop2564:	; 80002564
80002564	beq    v0, zero, L2578 [$80002578]
80002568	sll    t0, a3, $03
8000256C	addiu  v0, a3, $0001
80002570	j      $801b257c
80002574	sll    s1, v0, $03

L2578:	; 80002578
80002578	ori    s1, zero, $00a6
8000257C	lui    v0, $801f
80002580	lw     v0, $03dc(v0)
80002584	nop
80002588	sw     t5, $0004(v0)
8000258C	sb     zero, $001c(v0)
80002590	sb     zero, $000c(v0)
80002594	lui    v1, $801f
80002598	lw     v1, $03dc(v1)
8000259C	addiu  a3, a3, $0001
800025A0	sw     t6, $0000(v0)
800025A4	sh     s3, $0016(v0)
800025A8	sb     t7, $0024(v1)
800025AC	sb     t7, $0014(v1)
800025B0	lui    v1, $801f
800025B4	lw     v1, $03dc(v1)
800025B8	addu   v0, t0, zero
800025BC	sb     v0, $0015(v1)
800025C0	sb     v0, $000d(v1)
800025C4	lui    v1, $801f
800025C8	lw     v1, $03dc(v1)
800025CC	addu   v0, s1, zero
800025D0	sb     v0, $0025(v1)
800025D4	sb     v0, $001d(v1)
800025D8	lui    v1, $801f
800025DC	lw     v1, $03dc(v1)
800025E0	addu   v0, t0, zero
800025E4	sh     v0, $0012(v1)
800025E8	sh     v0, $000a(v1)
800025EC	addu   v0, s1, zero
800025F0	sh     v0, $0022(v1)
800025F4	sh     v0, $001a(v1)
800025F8	addiu  v1, v1, $0028
800025FC	slti   v0, a3, $0015
80002600	lui    at, $801f
80002604	sw     v1, $03dc(at)
80002608	bne    v0, zero, loop2564 [$80002564]
8000260C	slti   v0, a3, $0014
80002610	addu   a3, zero, zero

loop2614:	; 80002614
80002614	sll    t0, a3, $03
80002618	addiu  a1, a3, $0001
8000261C	lui    v0, $801f
80002620	lw     v0, $03dc(v0)
80002624	sll    s1, a1, $03
80002628	sw     t5, $0004(v0)
8000262C	sb     zero, $001c(v0)
80002630	sb     zero, $000c(v0)
80002634	lui    v1, $801f
80002638	lw     v1, $03dc(v1)
8000263C	addiu  a0, t0, $ffa6 (=-$5a)
80002640	sw     t6, $0000(v0)
80002644	sh     s3, $0016(v0)
80002648	sb     s2, $0024(v1)
8000264C	sb     s2, $0014(v1)
80002650	lui    v0, $801f
80002654	lw     v0, $03dc(v0)
80002658	addu   a3, a1, zero
8000265C	sb     a0, $0015(v0)
80002660	sb     a0, $000d(v0)
80002664	lui    v0, $801f
80002668	lw     v0, $03dc(v0)
8000266C	addiu  v1, s1, $ffa6 (=-$5a)
80002670	sb     v1, $0025(v0)
80002674	sb     v1, $001d(v0)
80002678	lui    v1, $801f
8000267C	lw     v1, $03dc(v1)
80002680	addu   v0, t0, zero
80002684	sh     v0, $0012(v1)
80002688	sh     v0, $000a(v1)
8000268C	addu   v0, s1, zero
80002690	sh     v0, $0022(v1)
80002694	sh     v0, $001a(v1)
80002698	addiu  v1, v1, $0028
8000269C	slti   v0, a3, $000b
800026A0	lui    at, $801f
800026A4	sw     v1, $03dc(at)
800026A8	bne    v0, zero, loop2614 [$80002614]
800026AC	ori    t4, zero, $0041
800026B0	addu   a3, zero, zero
800026B4	ori    t3, zero, $0082
800026B8	slti   v0, a3, $0009

loop26bc:	; 800026BC
800026BC	beq    v0, zero, L26d0 [$800026d0]
800026C0	sll    t0, a3, $03
800026C4	addiu  v0, a3, $0001
800026C8	j      $801b26d4
800026CC	sll    s1, v0, $03

L26d0:	; 800026D0
800026D0	ori    s1, zero, $004e
800026D4	lui    v0, $801f
800026D8	lw     v0, $03dc(v0)
800026DC	addiu  a2, t0, $ffa6 (=-$5a)
800026E0	sw     t5, $0004(v0)
800026E4	sb     t4, $001c(v0)
800026E8	sb     t4, $000c(v0)
800026EC	lui    v1, $801f
800026F0	lw     v1, $03dc(v1)
800026F4	addiu  a1, s1, $ffa6 (=-$5a)
800026F8	sw     t6, $0000(v0)
800026FC	sh     s3, $0016(v0)
80002700	sb     t3, $0024(v1)
80002704	sb     t3, $0014(v1)
80002708	lui    v0, $801f
8000270C	lw     v0, $03dc(v0)
80002710	addiu  a0, t0, $0058
80002714	sb     a2, $0015(v0)
80002718	sb     a2, $000d(v0)
8000271C	lui    v0, $801f
80002720	lw     v0, $03dc(v0)
80002724	addiu  a3, a3, $0001
80002728	sb     a1, $0025(v0)
8000272C	sb     a1, $001d(v0)
80002730	lui    v0, $801f
80002734	lw     v0, $03dc(v0)
80002738	addiu  v1, s1, $0058
8000273C	sh     a0, $0012(v0)
80002740	sh     a0, $000a(v0)
80002744	sh     v1, $0022(v0)
80002748	sh     v1, $001a(v0)
8000274C	addiu  v0, v0, $0028
80002750	lui    at, $801f
80002754	sw     v0, $03dc(at)
80002758	slti   v0, a3, $000a
8000275C	bne    v0, zero, loop26bc [$800026bc]
80002760	slti   v0, a3, $0009
80002764	ori    v1, zero, $0300
80002768	ori    v0, zero, $0100
8000276C	ori    a0, zero, $00a6
80002770	lui    at, $801f
80002774	addu   at, at, t1
80002778	sh     v0, $0360(at)
8000277C	ori    v0, zero, $0058
80002780	lui    at, $801f
80002784	addu   at, at, t1
80002788	sh     v0, $037a(at)
8000278C	ori    v0, zero, $0341
80002790	lui    at, $801f
80002794	addu   at, at, t1
80002798	sh     v0, $038c(at)
8000279C	ori    v0, zero, $004e
800027A0	lui    at, $801f
800027A4	addu   at, at, t1
800027A8	sh     v0, $0392(at)
800027AC	lui    v0, $2e00
800027B0	lui    at, $801f
800027B4	addu   at, at, t1
800027B8	sh     v1, $035c(at)
800027BC	lui    at, $801f
800027C0	addu   at, at, t1
800027C4	sh     zero, $035e(at)
800027C8	lui    at, $801f
800027CC	addu   at, at, t1
800027D0	sh     a0, $0362(at)
800027D4	lui    at, $801f
800027D8	addu   at, at, t1
800027DC	sh     v1, $0374(at)
800027E0	lui    at, $801f
800027E4	addu   at, at, t1
800027E8	sh     a0, $0376(at)
800027EC	lui    at, $801f
800027F0	addu   at, at, t1
800027F4	sh     s2, $0378(at)
800027F8	lui    at, $801f
800027FC	addu   at, at, t1
80002800	sh     t7, $0370(at)
80002804	lui    at, $801f
80002808	addu   at, at, t1
8000280C	sh     a0, $038e(at)
80002810	lui    at, $801f
80002814	addu   at, at, t1
80002818	sh     s2, $0390(at)
8000281C	lui    at, $801f
80002820	addu   at, at, t1
80002824	sh     t7, $0388(at)
80002828	lui    at, $801f
8000282C	addu   at, at, t2
80002830	sw     v0, $03e4(at)
80002834	ori    v0, zero, $012c
80002838	lui    v1, $801f
8000283C	addiu  v1, v1, $03e0
80002840	addu   v1, t2, v1
80002844	lui    at, $801f
80002848	addu   at, at, t2
8000284C	sh     v0, $03f6(at)
80002850	ori    v0, zero, $00ff
80002854	lui    at, $801f
80002858	addu   at, at, t2
8000285C	sw     t6, $03e0(at)

L2860:	; 80002860
80002860	sb     v0, $0024(v1)
80002864	sb     v0, $001c(v1)
80002868	sb     v0, $0014(v1)
8000286C	lui    at, $801f
80002870	addu   at, at, t2
80002874	sb     v0, $03ec(at)
80002878	sb     v0, $0025(v1)
8000287C	sb     v0, $001d(v1)

L2880:	; 80002880
80002880	sb     v0, $0015(v1)
80002884	lui    at, $801f
80002888	addu   at, at, t2
8000288C	sb     v0, $03ed(at)
80002890	ori    v0, zero, $0140
80002894	sh     zero, $0018(v1)
80002898	lui    at, $801f
8000289C	addu   at, at, t2
800028A0	sh     zero, $03e8(at)
800028A4	sh     v0, $0020(v1)
800028A8	lui    at, $801f
800028AC	addu   at, at, t2
800028B0	sh     v0, $03f0(at)
800028B4	sh     zero, $0012(v1)
800028B8	lui    at, $801f
800028BC	addu   at, at, t2
800028C0	sh     zero, $03ea(at)
800028C4	sh     a0, $0022(v1)
800028C8	lui    at, $801f
800028CC	addu   at, at, t2
800028D0	sh     a0, $03fa(at)
800028D4	addiu  t2, t2, $0028
800028D8	addiu  t1, t1, $0048
800028DC	addiu  s0, s0, $0001
800028E0	slti   v0, s0, $0002
800028E4	bne    v0, zero, L2548 [$80002548]
800028E8	addiu  s5, s5, $0690

L28ec:	; 800028EC
800028EC	lh     a0, $0002(s4)
800028F0	nop
800028F4	slti   v0, a0, $0005
800028F8	beq    v0, zero, L2928 [$80002928]
800028FC	lui    v0, $6666
80002900	ori    v0, v0, $6667
80002904	sll    v1, a0, $07
80002908	subu   v1, v1, a0
8000290C	mult   v1, v0
80002910	sra    v1, v1, $1f
80002914	mfhi   v0
80002918	sra    v0, v0, $01
8000291C	subu   v0, v0, v1
80002920	j      $801b2968
80002924	addiu  s5, v0, $ff80 (=-$80)

L2928:	; 80002928
80002928	addiu  a0, a0, $fffb (=-$5)
8000292C	slti   v0, a0, $0005
80002930	bne    v0, zero, L2944 [$80002944]
80002934	lui    v0, $6666
80002938	addiu  v0, zero, $ffff (=-$1)
8000293C	j      $801b2df4
80002940	sh     v0, $0000(s4)

L2944:	; 80002944
80002944	ori    v0, v0, $6667
80002948	sll    v1, a0, $07
8000294C	subu   v1, a0, v1
80002950	mult   v1, v0
80002954	sra    v1, v1, $1f
80002958	mfhi   v0
8000295C	sra    v0, v0, $01
80002960	subu   v0, v0, v1
80002964	addiu  s5, v0, $ffff (=-$1)
80002968	lui    v0, $8010
8000296C	lw     v0, $8368(v0)
80002970	lui    s0, $801f
80002974	addiu  s0, s0, $034c
80002978	sll    a0, v0, $03
8000297C	addu   a0, a0, v0
80002980	sll    a0, a0, $03
80002984	jal    $80046a80
80002988	addu   a0, a0, s0
8000298C	lui    v1, $8010
80002990	lw     v1, $8368(v1)
80002994	lui    a3, $8010
80002998	lw     a3, $8368(a3)
8000299C	lui    a2, $8010
800029A0	lw     a2, $8368(a2)
800029A4	lui    a0, $8015
800029A8	lw     a0, $17c0(a0)
800029AC	lui    v0, $8010
800029B0	lw     v0, $8368(v0)
800029B4	addiu  a0, a0, $4084
800029B8	sll    a1, v0, $03
800029BC	addu   a1, a1, v0
800029C0	sll    a1, a1, $03
800029C4	sll    v0, v1, $03
800029C8	addu   v0, v0, v1
800029CC	sll    v0, v0, $03
800029D0	sll    v1, a3, $03
800029D4	addu   v1, v1, a3
800029D8	sll    v1, v1, $03
800029DC	xori   a2, a2, $0001
800029E0	lui    at, $801f
800029E4	addu   at, at, v0
800029E8	sh     zero, $0358(at)
800029EC	sll    v0, a2, $04
800029F0	subu   v0, v0, a2
800029F4	sll    v0, v0, $04
800029F8	lui    at, $801f
800029FC	addu   at, at, v1
80002A00	sh     v0, $035a(at)
80002A04	jal    $80046794
80002A08	addu   a1, a1, s0
80002A0C	lui    v0, $8010
80002A10	lw     v0, $8368(v0)
80002A14	addiu  s1, s0, $0018
80002A18	sll    a0, v0, $03
80002A1C	addu   a0, a0, v0
80002A20	sll    a0, a0, $03
80002A24	jal    $80046a80
80002A28	addu   a0, a0, s1
80002A2C	lui    a3, $8010
80002A30	lw     a3, $8368(a3)
80002A34	lui    a2, $8010
80002A38	lw     a2, $8368(a2)
80002A3C	lui    a0, $8015
80002A40	lw     a0, $17c0(a0)
80002A44	lui    v0, $8010
80002A48	lw     v0, $8368(v0)
80002A4C	addiu  a0, a0, $4084
80002A50	sll    a1, v0, $03
80002A54	addu   a1, a1, v0
80002A58	sll    a1, a1, $03
80002A5C	sll    v1, a3, $03
80002A60	addu   v1, v1, a3
80002A64	sll    v1, v1, $03
80002A68	xori   a2, a2, $0001
80002A6C	sll    v0, a2, $04
80002A70	subu   v0, v0, a2
80002A74	sll    v0, v0, $04
80002A78	lui    at, $801f
80002A7C	addu   at, at, v1
80002A80	sh     v0, $0372(at)
80002A84	jal    $80046794
80002A88	addu   a1, a1, s1
80002A8C	lui    v0, $8010
80002A90	lw     v0, $8368(v0)
80002A94	addiu  s0, s0, $0030
80002A98	sll    a0, v0, $03
80002A9C	addu   a0, a0, v0
80002AA0	sll    a0, a0, $03
80002AA4	jal    $80046a80
80002AA8	addu   a0, a0, s0
80002AAC	lui    a3, $8010
80002AB0	lw     a3, $8368(a3)
80002AB4	lui    a2, $8010
80002AB8	lw     a2, $8368(a2)
80002ABC	lui    a0, $8015
80002AC0	lw     a0, $17c0(a0)
80002AC4	lui    v0, $8010
80002AC8	lw     v0, $8368(v0)
80002ACC	addiu  a0, a0, $4084
80002AD0	sll    a1, v0, $03
80002AD4	addu   a1, a1, v0
80002AD8	sll    a1, a1, $03
80002ADC	sll    v1, a3, $03
80002AE0	addu   v1, v1, a3
80002AE4	sll    v1, v1, $03
80002AE8	xori   a2, a2, $0001
80002AEC	sll    v0, a2, $04
80002AF0	subu   v0, v0, a2
80002AF4	sll    v0, v0, $04
80002AF8	addiu  v0, v0, $0058
80002AFC	lui    at, $801f
80002B00	addu   at, at, v1
80002B04	sh     v0, $038a(at)
80002B08	jal    $80046794
80002B0C	addu   a1, a1, s0
80002B10	lui    a0, $8015
80002B14	lw     a0, $17c0(a0)
80002B18	lui    v0, $8010
80002B1C	lw     v0, $8368(v0)
80002B20	addiu  a0, a0, $4084
80002B24	sll    a1, v0, $02
80002B28	addu   a1, a1, v0
80002B2C	sll    a1, a1, $03
80002B30	lui    v0, $801f
80002B34	addiu  v0, v0, $03e0
80002B38	jal    $80046794
80002B3C	addu   a1, a1, v0
80002B40	lh     v0, $0002(s4)
80002B44	nop
80002B48	beq    v0, zero, L2dd0 [$80002dd0]
80002B4C	nop
80002B50	lui    v0, $8010
80002B54	lw     v0, $8368(v0)
80002B58	addu   s0, zero, zero
80002B5C	sll    v1, v0, $03
80002B60	subu   v1, v1, v0
80002B64	sll    v0, v1, $04
80002B68	subu   v0, v0, v1
80002B6C	lui    v1, $801f
80002B70	lw     v1, $0224(v1)
80002B74	sll    v0, v0, $04
80002B78	addu   v0, v0, v1
80002B7C	lui    at, $801f
80002B80	sw     v0, $03dc(at)
80002B84	slti   v0, s0, $0014

loop2b88:	; 80002B88
80002B88	beq    v0, zero, L2b9c [$80002b9c]
80002B8C	sll    t0, s0, $03
80002B90	addiu  v0, s0, $0001
80002B94	j      $801b2ba0
80002B98	sll    s1, v0, $03

L2b9c:	; 80002B9C
80002B9C	ori    s1, zero, $00a6
80002BA0	lui    v0, $801f
80002BA4	lw     v0, $03dc(v0)
80002BA8	nop
80002BAC	sb     s5, $0004(v0)
80002BB0	lh     a0, $0002(s4)
80002BB4	nop
80002BB8	sll    a0, a0, $03
80002BBC	addu   a0, t0, a0
80002BC0	jal    func39a74 [$80039a74]
80002BC4	sll    a0, a0, $06
80002BC8	addiu  v0, v0, $0200
80002BCC	lui    v1, $801f
80002BD0	lw     v1, $03dc(v1)
80002BD4	sra    v0, v0, $0a
80002BD8	sh     v0, $0008(v1)
80002BDC	addiu  v0, v0, $00ff
80002BE0	sh     v0, $0010(v1)
80002BE4	lh     a0, $0002(s4)
80002BE8	nop
80002BEC	sll    a0, a0, $03
80002BF0	addu   a0, s1, a0
80002BF4	jal    func39a74 [$80039a74]
80002BF8	sll    a0, a0, $06
80002BFC	addiu  v0, v0, $0200
80002C00	sra    v0, v0, $0a
80002C04	lui    a0, $8015
80002C08	lw     a0, $17c0(a0)
80002C0C	lui    a1, $801f
80002C10	lw     a1, $03dc(a1)
80002C14	addiu  a0, a0, $4084
80002C18	sh     v0, $0018(a1)
80002C1C	addiu  v0, v0, $00ff
80002C20	jal    $80046794
80002C24	sh     v0, $0020(a1)
80002C28	lui    v0, $801f
80002C2C	lw     v0, $03dc(v0)
80002C30	addiu  s0, s0, $0001
80002C34	addiu  v0, v0, $0028
80002C38	lui    at, $801f
80002C3C	sw     v0, $03dc(at)
80002C40	slti   v0, s0, $0015
80002C44	bne    v0, zero, loop2b88 [$80002b88]
80002C48	slti   v0, s0, $0014
80002C4C	addu   s0, zero, zero

loop2c50:	; 80002C50
80002C50	lui    v0, $801f
80002C54	lw     v0, $03dc(v0)
80002C58	nop
80002C5C	sb     s5, $0004(v0)
80002C60	lh     a0, $0002(s4)
80002C64	nop
80002C68	addu   a0, a0, s0
80002C6C	jal    func39a74 [$80039a74]
80002C70	sll    a0, a0, $09
80002C74	addiu  v0, v0, $0200
80002C78	sra    v0, v0, $0a
80002C7C	addiu  v1, v0, $00ff
80002C80	addiu  v0, v0, $0140
80002C84	lui    a0, $801f
80002C88	lw     a0, $03dc(a0)
80002C8C	addiu  s0, s0, $0001
80002C90	sh     v1, $0008(a0)
80002C94	sh     v0, $0010(a0)
80002C98	lh     a0, $0002(s4)
80002C9C	sll    s1, s0, $03
80002CA0	sll    a0, a0, $03
80002CA4	addu   a0, s1, a0
80002CA8	jal    func39a74 [$80039a74]
80002CAC	sll    a0, a0, $06
80002CB0	addiu  v0, v0, $0200
80002CB4	sra    v0, v0, $0a
80002CB8	addiu  v1, v0, $00ff
80002CBC	addiu  v0, v0, $0140
80002CC0	lui    a0, $8015
80002CC4	lw     a0, $17c0(a0)
80002CC8	lui    a1, $801f
80002CCC	lw     a1, $03dc(a1)
80002CD0	addiu  a0, a0, $4084
80002CD4	sh     v1, $0018(a1)
80002CD8	jal    $80046794
80002CDC	sh     v0, $0020(a1)
80002CE0	lui    v0, $801f
80002CE4	lw     v0, $03dc(v0)
80002CE8	nop
80002CEC	addiu  v0, v0, $0028
80002CF0	lui    at, $801f
80002CF4	sw     v0, $03dc(at)
80002CF8	slti   v0, s0, $000b
80002CFC	bne    v0, zero, loop2c50 [$80002c50]
80002D00	ori    s3, zero, $0008
80002D04	addu   s0, zero, zero
80002D08	ori    s2, zero, $0058

loop2d0c:	; 80002D0C
80002D0C	slti   v0, s0, $0009
80002D10	beq    v0, zero, L2d1c [$80002d1c]
80002D14	ori    s1, zero, $00a6
80002D18	addiu  s1, s3, $0058

L2d1c:	; 80002D1C
80002D1C	lui    v0, $801f
80002D20	lw     v0, $03dc(v0)
80002D24	nop
80002D28	sb     s5, $0004(v0)
80002D2C	lh     a0, $0002(s4)
80002D30	addiu  s3, s3, $0008
80002D34	sll    a0, a0, $03
80002D38	addu   a0, s2, a0
80002D3C	jal    func39a74 [$80039a74]
80002D40	sll    a0, a0, $06
80002D44	addiu  v0, v0, $0200
80002D48	sra    v0, v0, $0a
80002D4C	addiu  v1, v0, $00ff
80002D50	lui    a0, $801f
80002D54	lw     a0, $03dc(a0)
80002D58	addiu  v0, v0, $0140
80002D5C	sh     v1, $0008(a0)
80002D60	sh     v0, $0010(a0)
80002D64	lh     a0, $0002(s4)
80002D68	addiu  s0, s0, $0001
80002D6C	sll    a0, a0, $03
80002D70	addu   a0, s1, a0
80002D74	jal    func39a74 [$80039a74]
80002D78	sll    a0, a0, $06
80002D7C	addiu  v0, v0, $0200
80002D80	sra    v0, v0, $0a
80002D84	addiu  v1, v0, $00ff
80002D88	addiu  v0, v0, $0140
80002D8C	lui    a0, $8015
80002D90	lw     a0, $17c0(a0)
80002D94	lui    a1, $801f
80002D98	lw     a1, $03dc(a1)
80002D9C	addiu  a0, a0, $4084
80002DA0	sh     v1, $0018(a1)
80002DA4	jal    $80046794
80002DA8	sh     v0, $0020(a1)
80002DAC	lui    v0, $801f
80002DB0	lw     v0, $03dc(v0)
80002DB4	nop
80002DB8	addiu  v0, v0, $0028
80002DBC	lui    at, $801f
80002DC0	sw     v0, $03dc(at)
80002DC4	slti   v0, s0, $000a
80002DC8	bne    v0, zero, loop2d0c [$80002d0c]
80002DCC	addiu  s2, s2, $0008

L2dd0:	; 80002DD0
80002DD0	lui    v0, $8006
80002DD4	lbu    v0, $2d98(v0)
80002DD8	nop
80002DDC	bne    v0, zero, L2df4 [$80002df4]
80002DE0	nop
80002DE4	lhu    v0, $0002(s4)
80002DE8	nop
80002DEC	addiu  v0, v0, $0001
80002DF0	sh     v0, $0002(s4)

L2df4:	; 80002DF4
80002DF4	lw     ra, $0030(sp)
80002DF8	lw     s5, $002c(sp)
80002DFC	lw     s4, $0028(sp)
80002E00	lw     s3, $0024(sp)
80002E04	lw     s2, $0020(sp)
80002E08	lw     s1, $001c(sp)
80002E0C	lw     s0, $0018(sp)
80002E10	addiu  sp, sp, $0038
80002E14	jr     ra 
80002E18	nop

80002E1C	addiu  sp, sp, $ffe0 (=-$20)
80002E20	lui    v0, $8015
80002E24	lh     v0, $169c(v0)
80002E28	lui    a0, $8006
80002E2C	lbu    a0, $2d98(a0)
80002E30	lui    v1, $8016
80002E34	addiu  v1, v1, $2978
80002E38	sw     ra, $0018(sp)
80002E3C	sw     s1, $0014(sp)
80002E40	sw     s0, $0010(sp)
80002E44	sll    v0, v0, $05
80002E48	bne    a0, zero, L3004 [$80003004]
80002E4C	addu   s1, v0, v1
80002E50	lh     a0, $0002(s1)
80002E54	nop
80002E58	slti   v0, a0, $001e
80002E5C	beq    v0, zero, L2ea8 [$80002ea8]
80002E60	lui    v0, $8888
80002E64	ori    v0, v0, $8889
80002E68	sll    v1, a0, $05
80002E6C	subu   v1, v1, a0
80002E70	sll    v1, v1, $02
80002E74	addu   v1, v1, a0
80002E78	sll    v1, v1, $04
80002E7C	subu   v1, zero, v1
80002E80	mult   v1, v0
80002E84	mfhi   v0
80002E88	addu   v0, v0, v1
80002E8C	sra    v0, v0, $04
80002E90	sra    v1, v1, $1f
80002E94	subu   v0, v0, v1
80002E98	lui    at, $801f
80002E9C	sh     v0, $0236(at)
80002EA0	j      $801b2f94
80002EA4	nop

L2ea8:	; 80002EA8
80002EA8	addiu  a0, a0, $ffe2 (=-$1e)
80002EAC	slti   v0, a0, $0064
80002EB0	bne    v0, zero, L2f94 [$80002f94]
80002EB4	addiu  a0, a0, $ff9c (=-$64)
80002EB8	slti   v0, a0, $000f
80002EBC	beq    v0, zero, L2ef4 [$80002ef4]
80002EC0	addiu  a0, a0, $fff1 (=-$f)
80002EC4	lui    v1, $801f
80002EC8	addiu  v1, v1, $0234
80002ECC	lhu    v0, $0000(v1)
80002ED0	nop
80002ED4	sh     v0, $0000(v1)
80002ED8	lui    v0, $801f
80002EDC	lhu    v0, $0236(v0)
80002EE0	lui    v1, $801f
80002EE4	lhu    v1, $0238(v1)
80002EE8	addiu  v0, v0, $fff6 (=-$a)
80002EEC	j      $801b2f2c
80002EF0	addiu  v1, v1, $ffec (=-$14)

L2ef4:	; 80002EF4
80002EF4	slti   v0, a0, $0003
80002EF8	beq    v0, zero, L2f44 [$80002f44]
80002EFC	addiu  a0, a0, $fffd (=-$3)
80002F00	lui    v1, $801f
80002F04	addiu  v1, v1, $0234
80002F08	lhu    v0, $0000(v1)
80002F0C	nop
80002F10	sh     v0, $0000(v1)
80002F14	lui    v0, $801f
80002F18	lhu    v0, $0236(v0)
80002F1C	lui    v1, $801f
80002F20	lhu    v1, $0238(v1)
80002F24	addiu  v0, v0, $03e8
80002F28	addiu  v1, v1, $07d0
80002F2C	lui    at, $801f
80002F30	sh     v0, $0236(at)
80002F34	lui    at, $801f
80002F38	sh     v1, $0238(at)
80002F3C	j      $801b2f94
80002F40	nop

L2f44:	; 80002F44
80002F44	slti   v0, a0, $0014
80002F48	bne    v0, zero, L2f5c [$80002f5c]
80002F4C	ori    v0, zero, $01f4
80002F50	addiu  v0, zero, $ffff (=-$1)
80002F54	j      $801b3004
80002F58	sh     v0, $0000(s1)

L2f5c:	; 80002F5C
80002F5C	lui    at, $801f
80002F60	sh     v0, $0236(at)
80002F64	sll    v0, a0, $01
80002F68	addu   v0, v0, a0
80002F6C	sll    v0, v0, $04
80002F70	subu   v0, v0, a0
80002F74	sll    v0, v0, $03
80002F78	subu   v0, v0, a0
80002F7C	sll    v0, v0, $02
80002F80	addiu  v0, v0, $ec78 (=-$1388)
80002F84	lui    at, $801f
80002F88	sh     zero, $0234(at)
80002F8C	lui    at, $801f
80002F90	sh     v0, $0238(at)

L2f94:	; 80002F94
80002F94	lui    s0, $801f
80002F98	addiu  s0, s0, $0430
80002F9C	jal    func3b48c [$8003b48c]
80002FA0	addu   a0, s0, zero
80002FA4	jal    func3b51c [$8003b51c]
80002FA8	addu   a0, s0, zero
80002FAC	lui    a1, $801f
80002FB0	lw     a1, $023c(a1)
80002FB4	lui    a0, $801f
80002FB8	addiu  a0, a0, $0234
80002FBC	jal    func3bc6c [$8003bc6c]
80002FC0	addiu  a2, a1, $0010
80002FC4	lui    v1, $801f
80002FC8	lw     v1, $023c(v1)
80002FCC	nop
80002FD0	lhu    v0, $0000(v1)
80002FD4	lui    at, $8015
80002FD8	sh     v0, $3d20(at)
80002FDC	lhu    v0, $0004(v1)
80002FE0	lui    at, $8015
80002FE4	sh     v0, $3d22(at)
80002FE8	lhu    v0, $0008(v1)
80002FEC	lui    at, $8015
80002FF0	sh     v0, $3d24(at)
80002FF4	lhu    v0, $0002(s1)
80002FF8	nop
80002FFC	addiu  v0, v0, $0001
80003000	sh     v0, $0002(s1)

L3004:	; 80003004
80003004	lw     ra, $0018(sp)
80003008	lw     s1, $0014(sp)
8000300C	lw     s0, $0010(sp)
80003010	addiu  sp, sp, $0020
80003014	jr     ra 
80003018	nop

8000301C	addiu  sp, sp, $ffe0 (=-$20)
80003020	lui    v0, $8015
80003024	lh     v0, $169c(v0)
80003028	lui    v1, $8016
8000302C	addiu  v1, v1, $2978
80003030	sw     ra, $001c(sp)
80003034	sw     s2, $0018(sp)
80003038	sw     s1, $0014(sp)
8000303C	sw     s0, $0010(sp)
80003040	sll    v0, v0, $05
80003044	addu   s2, v0, v1
80003048	lhu    v1, $0002(s2)
8000304C	nop
80003050	andi   v0, v1, $0001
80003054	sltiu  v0, v0, $0001
80003058	sll    s1, v0, $0b
8000305C	sll    v1, v1, $10
80003060	sra    v1, v1, $10
80003064	slti   v0, v1, $000f
80003068	beq    v0, zero, L30dc [$800030dc]
8000306C	addiu  v0, s1, $f000 (=-$1000)
80003070	mult   v0, v1
80003074	mflo   v1
80003078	lui    v0, $8888
8000307C	ori    v0, v0, $8889
80003080	mult   v1, v0
80003084	mfhi   v0
80003088	addu   v0, v0, v1
8000308C	sra    v0, v0, $03
80003090	sra    v1, v1, $1f
80003094	subu   v0, v0, v1
80003098	lui    v1, $8006
8000309C	lbu    v1, $2d98(v1)
800030A0	nop
800030A4	bne    v1, zero, L3144 [$80003144]
800030A8	addiu  s1, v0, $1000
800030AC	lui    v1, $801f
800030B0	addiu  v1, v1, $027c
800030B4	lw     v0, $0000(v1)
800030B8	nop
800030BC	sw     v0, $0000(v1)
800030C0	lui    v0, $801f
800030C4	lw     v0, $0280(v0)
800030C8	lui    v1, $801f
800030CC	lw     v1, $0284(v1)
800030D0	addiu  v0, v0, $fff6 (=-$a)
800030D4	j      $801b3134
800030D8	addiu  v1, v1, $ffec (=-$14)

L30dc:	; 800030DC
800030DC	addiu  v1, v1, $fff1 (=-$f)
800030E0	slti   v0, v1, $0003
800030E4	bne    v0, zero, L30f4 [$800030f4]
800030E8	addiu  v0, zero, $ffff (=-$1)
800030EC	j      $801b3284
800030F0	sh     v0, $0000(s2)

L30f4:	; 800030F4
800030F4	lui    v0, $8006
800030F8	lbu    v0, $2d98(v0)
800030FC	nop
80003100	bne    v0, zero, L3144 [$80003144]
80003104	addu   s1, zero, zero
80003108	lui    v1, $801f
8000310C	addiu  v1, v1, $027c
80003110	lw     v0, $0000(v1)
80003114	nop
80003118	sw     v0, $0000(v1)
8000311C	lui    v0, $801f
80003120	lw     v0, $0280(v0)
80003124	lui    v1, $801f
80003128	lw     v1, $0284(v1)
8000312C	addiu  v0, v0, $03e8
80003130	addiu  v1, v1, $07d0
80003134	lui    at, $801f
80003138	sw     v0, $0280(at)
8000313C	lui    at, $801f
80003140	sw     v1, $0284(at)

L3144:	; 80003144
80003144	lui    a0, $801f
80003148	addiu  a0, a0, $0250
8000314C	lui    s0, $801f
80003150	addiu  s0, s0, $0268
80003154	jal    func3c21c [$8003c21c]
80003158	addu   a1, s0, zero
8000315C	lui    a1, $801f
80003160	addiu  a1, a1, $0258
80003164	jal    func3b35c [$8003b35c]
80003168	addu   a0, s0, zero
8000316C	lui    a0, $801f
80003170	addiu  a0, a0, $0450
80003174	lui    a2, $801f
80003178	lw     a2, $0288(a2)
8000317C	jal    func3a63c [$8003a63c]
80003180	addu   a1, s0, zero
80003184	lui    a0, $801f
80003188	lw     a0, $0288(a0)
8000318C	jal    func3b48c [$8003b48c]
80003190	nop
80003194	lui    a0, $801f
80003198	lw     a0, $0288(a0)
8000319C	jal    func3b51c [$8003b51c]
800031A0	nop
800031A4	addu   a0, zero, zero
800031A8	addu   a1, zero, zero
800031AC	jal    func3b69c [$8003b69c]
800031B0	addu   a2, zero, zero
800031B4	lui    v0, $801f
800031B8	addiu  v0, v0, $024a
800031BC	addiu  a0, v0, $fff6 (=-$a)
800031C0	lui    a1, $8015
800031C4	lw     a1, $17c0(a1)
800031C8	lui    a3, $8016
800031CC	lw     a3, $3c74(a3)
800031D0	ori    a2, zero, $000c
800031D4	sh     s1, $0000(v0)
800031D8	jal    $800d29d4
800031DC	addiu  a1, a1, $0070
800031E0	lui    v1, $8006
800031E4	lbu    v1, $2d98(v1)
800031E8	lui    at, $8016
800031EC	sw     v0, $3c74(at)
800031F0	bne    v1, zero, L3284 [$80003284]
800031F4	lui    a1, $38e3
800031F8	lhu    a0, $0002(s2)
800031FC	ori    a1, a1, $8e39
80003200	addiu  a0, a0, $0001
80003204	sll    v0, a0, $10
80003208	sra    v0, v0, $10
8000320C	sll    v1, v0, $01
80003210	addu   v1, v1, v0
80003214	sll    v1, v1, $04
80003218	mult   v1, a1
8000321C	lui    a1, $8888
80003220	sh     a0, $0002(s2)
80003224	lui    a0, $801f
80003228	lhu    a0, $0254(a0)
8000322C	sra    v1, v1, $1f
80003230	addiu  a0, a0, $0010
80003234	mfhi   v0
80003238	sra    v0, v0, $02
8000323C	subu   v0, v0, v1
80003240	addu   a0, a0, v0
80003244	lui    at, $801f
80003248	sh     a0, $0254(at)
8000324C	lh     v0, $0002(s2)
80003250	ori    a1, a1, $8889
80003254	sll    v1, v0, $03
80003258	subu   v1, v1, v0
8000325C	sll    v1, v1, $08
80003260	mult   v1, a1
80003264	mfhi   v0
80003268	addu   v0, v0, v1
8000326C	sra    v0, v0, $03
80003270	sra    v1, v1, $1f
80003274	subu   v0, v0, v1
80003278	addiu  v0, v0, $0100
8000327C	lui    at, $801f
80003280	sw     v0, $0260(at)

L3284:	; 80003284
80003284	lw     ra, $001c(sp)
80003288	lw     s2, $0018(sp)
8000328C	lw     s1, $0014(sp)
80003290	lw     s0, $0010(sp)
80003294	addiu  sp, sp, $0020
80003298	jr     ra 
8000329C	nop

800032A0	addiu  sp, sp, $ffe8 (=-$18)
800032A4	lui    v0, $8015
800032A8	lh     v0, $169c(v0)
800032AC	lui    v1, $8016
800032B0	addiu  v1, v1, $2978
800032B4	sw     ra, $0014(sp)
800032B8	sw     s0, $0010(sp)
800032BC	sll    v0, v0, $05
800032C0	addu   s0, v0, v1
800032C4	lh     v1, $0002(s0)
800032C8	nop
800032CC	slti   v0, v1, $000a
800032D0	beq    v0, zero, L330c [$8000330c]
800032D4	lui    v0, $6666
800032D8	ori    v0, v0, $6667
800032DC	sll    v1, v1, $0c
800032E0	subu   v1, zero, v1
800032E4	mult   v1, v0
800032E8	sra    v1, v1, $1f
800032EC	mfhi   v0
800032F0	sra    v0, v0, $02
800032F4	subu   v0, v0, v1
800032F8	addiu  v0, v0, $1000
800032FC	lui    at, $801f
80003300	sh     v0, $0296(at)
80003304	j      $801b3354
80003308	lui    v0, $6666

L330c:	; 8000330C
8000330C	addiu  v1, v1, $fff6 (=-$a)
80003310	slti   v0, v1, $000a
80003314	beq    v0, zero, L3348 [$80003348]
80003318	lui    v0, $6666
8000331C	ori    v0, v0, $6667
80003320	sll    v1, v1, $0c
80003324	mult   v1, v0
80003328	sra    v1, v1, $1f
8000332C	mfhi   v0
80003330	sra    v0, v0, $02
80003334	subu   v0, v0, v1
80003338	lui    at, $801f
8000333C	sh     v0, $0296(at)
80003340	j      $801b3354
80003344	lui    v0, $6666

L3348:	; 80003348
80003348	addiu  v0, zero, $ffff (=-$1)
8000334C	j      $801b3498
80003350	sh     v0, $0000(s0)
80003354	lh     v1, $0002(s0)
80003358	ori    v0, v0, $6667
8000335C	sll    v1, v1, $0c
80003360	mult   v1, v0
80003364	sra    v1, v1, $1f
80003368	mfhi   v0
8000336C	sra    v0, v0, $03
80003370	subu   v0, v0, v1
80003374	bgez   v0, L3380 [$80003380]
80003378	nop
8000337C	addiu  v0, v0, $0003

L3380:	; 80003380
80003380	jal    func39a74 [$80039a74]
80003384	sra    a0, v0, $02
80003388	sll    v1, v0, $01
8000338C	addu   v1, v1, v0
80003390	sll    v1, v1, $0c
80003394	sra    v1, v1, $0c
80003398	lh     v0, $0014(s0)
8000339C	addiu  v1, v1, $1000
800033A0	mult   v0, v1
800033A4	lui    a1, $801f
800033A8	lw     a1, $02bc(a1)
800033AC	mflo   v0
800033B0	sra    v0, v0, $0c
800033B4	sw     v0, $0028(a1)
800033B8	sw     v0, $0020(a1)
800033BC	lh     v0, $0014(s0)
800033C0	addiu  a0, s0, $000c
800033C4	jal    func3c21c [$8003c21c]
800033C8	sw     v0, $0024(a1)
800033CC	lui    a0, $801f
800033D0	lw     a0, $02bc(a0)
800033D4	lh     v0, $0004(s0)
800033D8	nop
800033DC	sw     v0, $0014(a0)
800033E0	lh     v0, $0006(s0)
800033E4	nop
800033E8	sw     v0, $0018(a0)
800033EC	lh     v0, $0008(s0)
800033F0	addiu  a1, a0, $0020
800033F4	jal    func3b35c [$8003b35c]
800033F8	sw     v0, $001c(a0)
800033FC	lui    a1, $801f
80003400	lw     a1, $02bc(a1)
80003404	lui    a0, $801f
80003408	addiu  a0, a0, $0450
8000340C	jal    func3a63c [$8003a63c]
80003410	addu   a2, a1, zero
80003414	lui    a0, $801f
80003418	lw     a0, $02bc(a0)
8000341C	jal    func3b48c [$8003b48c]
80003420	nop
80003424	lui    a0, $801f
80003428	lw     a0, $02bc(a0)
8000342C	jal    func3b51c [$8003b51c]
80003430	nop
80003434	addu   a0, zero, zero
80003438	addu   a1, zero, zero
8000343C	jal    func3b69c [$8003b69c]
80003440	addu   a2, zero, zero
80003444	lui    a0, $801f
80003448	addiu  a0, a0, $028c
8000344C	ori    a2, zero, $000c
80003450	lui    a1, $8015
80003454	lw     a1, $17c0(a1)
80003458	lui    a3, $8016
8000345C	lw     a3, $3c74(a3)
80003460	jal    $800d29d4
80003464	addiu  a1, a1, $0070
80003468	lui    v1, $8006
8000346C	lbu    v1, $2d98(v1)
80003470	lui    at, $8016
80003474	sw     v0, $3c74(at)
80003478	bne    v1, zero, L3498 [$80003498]
8000347C	nop
80003480	lhu    v0, $0002(s0)
80003484	lhu    v1, $000e(s0)
80003488	addiu  v0, v0, $0001
8000348C	addiu  v1, v1, $0080
80003490	sh     v0, $0002(s0)
80003494	sh     v1, $000e(s0)

L3498:	; 80003498
80003498	lw     ra, $0014(sp)
8000349C	lw     s0, $0010(sp)
800034A0	addiu  sp, sp, $0018
800034A4	jr     ra 
800034A8	nop

800034AC	addiu  sp, sp, $ffe8 (=-$18)
800034B0	addu   a2, zero, zero
800034B4	lui    v0, $8015
800034B8	lh     v0, $169c(v0)
800034BC	lui    v1, $8016
800034C0	addiu  v1, v1, $2978
800034C4	sw     ra, $0014(sp)
800034C8	sw     s0, $0010(sp)
800034CC	sll    v0, v0, $05
800034D0	addu   s0, v0, v1
800034D4	lh     a1, $0014(s0)
800034D8	jal    $800d4368
800034DC	addiu  a0, s0, $0004
800034E0	lui    v1, $801f
800034E4	addiu  v1, v1, $02c8
800034E8	addiu  a0, v1, $fff8 (=-$8)
800034EC	ori    a2, zero, $000c
800034F0	lhu    v0, $0002(s0)
800034F4	lui    a1, $8015
800034F8	lw     a1, $17c0(a1)
800034FC	lui    a3, $8016
80003500	lw     a3, $3c74(a3)
80003504	addiu  a1, a1, $0070
80003508	jal    $800d4d90
8000350C	sh     v0, $0000(v1)
80003510	lui    v1, $8006
80003514	lbu    v1, $2d98(v1)
80003518	lui    at, $8016
8000351C	sw     v0, $3c74(at)
80003520	bne    v1, zero, L35e8 [$800035e8]
80003524	nop
80003528	lhu    v0, $0002(s0)
8000352C	nop
80003530	addiu  v0, v0, $0001
80003534	sh     v0, $0002(s0)
80003538	sll    v0, v0, $10
8000353C	sra    v0, v0, $10
80003540	slti   v0, v0, $0010
80003544	bne    v0, zero, L3554 [$80003554]
80003548	addiu  v0, zero, $ffff (=-$1)
8000354C	j      $801b35e8
80003550	sh     v0, $0000(s0)

L3554:	; 80003554
80003554	lui    a0, $801f
80003558	addiu  a0, a0, $0430
8000355C	lui    a2, $801f
80003560	lw     a2, $02cc(a2)
80003564	jal    func3b2cc [$8003b2cc]
80003568	addiu  a1, s0, $000c
8000356C	lui    a1, $801f
80003570	lw     a1, $02cc(a1)
80003574	lhu    v0, $0004(s0)
80003578	lhu    v1, $0000(a1)
8000357C	nop
80003580	subu   v0, v0, v1
80003584	sh     v0, $0004(s0)
80003588	lhu    v0, $0006(s0)
8000358C	lhu    v1, $0002(a1)
80003590	lh     a0, $000c(s0)
80003594	addu   v0, v0, v1
80003598	sh     v0, $0006(s0)
8000359C	sll    v0, a0, $04
800035A0	subu   v0, v0, a0
800035A4	lhu    a0, $0004(a1)
800035A8	lh     v1, $000e(s0)
800035AC	sra    v0, v0, $04
800035B0	sh     v0, $000c(s0)
800035B4	sll    v0, v1, $04
800035B8	subu   v0, v0, v1
800035BC	lh     v1, $0010(s0)
800035C0	sra    v0, v0, $04
800035C4	sh     v0, $000e(s0)
800035C8	sll    v0, v1, $04
800035CC	subu   v0, v0, v1
800035D0	sra    v0, v0, $04
800035D4	lhu    v1, $0008(s0)
800035D8	addiu  v0, v0, $0005
800035DC	sh     v0, $0010(s0)
800035E0	subu   v1, v1, a0
800035E4	sh     v1, $0008(s0)

L35e8:	; 800035E8
800035E8	lw     ra, $0014(sp)
800035EC	lw     s0, $0010(sp)
800035F0	addiu  sp, sp, $0018
800035F4	jr     ra 
800035F8	nop

800035FC	addiu  sp, sp, $ffd0 (=-$30)
80003600	sw     s1, $001c(sp)
80003604	lui    s1, $8010
80003608	addiu  s1, s1, $a63c (=-$59c4)
8000360C	addu   a0, s1, zero
80003610	lui    a1, $801f
80003614	addiu  a1, a1, $0430
80003618	lui    v0, $8015
8000361C	lh     v0, $169c(v0)
80003620	lui    a2, $801f
80003624	addiu  a2, a2, $0450
80003628	sw     s2, $0020(sp)
8000362C	lui    s2, $8016
80003630	addiu  s2, s2, $2978
80003634	sw     ra, $0028(sp)
80003638	sw     s3, $0024(sp)
8000363C	sw     s0, $0018(sp)
80003640	sll    v0, v0, $05
80003644	jal    func3a63c [$8003a63c]
80003648	addu   s3, v0, s2
8000364C	lui    v0, $8006
80003650	lbu    v0, $2d98(v0)
80003654	nop
80003658	bne    v0, zero, L3b90 [$80003b90]
8000365C	nop
80003660	lh     s0, $0002(s3)
80003664	nop
80003668	slti   v0, s0, $0004
8000366C	beq    v0, zero, L36a8 [$800036a8]
80003670	nop
80003674	bne    s0, zero, L3b80 [$80003b80]
80003678	ori    a0, zero, $0400
8000367C	jal    $800d52a0
80003680	ori    a1, zero, $0004
80003684	ori    v0, zero, $0080
80003688	lui    at, $800f
8000368C	sb     v0, $5b70(at)
80003690	lui    at, $800f
80003694	sb     zero, $5b71(at)
80003698	lui    at, $800f
8000369C	sb     zero, $5b72(at)
800036A0	j      $801b3b80
800036A4	nop

L36a8:	; 800036A8
800036A8	addiu  s0, s0, $fffc (=-$4)
800036AC	slti   v0, s0, $000a
800036B0	beq    v0, zero, L36f4 [$800036f4]
800036B4	nop
800036B8	bne    s0, zero, L3b80 [$80003b80]
800036BC	nop
800036C0	lui    a0, $801b
800036C4	addiu  a0, a0, $14e8
800036C8	jal    $800bbeac

A0 = 22;
A1 = 40;
A2 = 1ac;
A3 = 1ad;
[SP + 10] = w(1ae);
funcd55f4; // we play sound here


800036EC	j      $801b3b80
800036F0	nop

L36f4:	; 800036F4
800036F4	addiu  s0, s0, $fff6 (=-$a)
800036F8	slti   v0, s0, $000a
800036FC	beq    v0, zero, L3788 [$80003788]
80003700	nop
80003704	bne    s0, zero, L3b80 [$80003b80]
80003708	nop
8000370C	jal    $800d4fa8
80003710	ori    a0, zero, $0001
80003714	lui    v1, $801f
80003718	lhu    v1, $0444(v1)
8000371C	nop
80003720	sh     v1, $0004(v0)
80003724	lui    v1, $801f
80003728	lhu    v1, $0448(v1)
8000372C	nop
80003730	sh     v1, $0006(v0)
80003734	lui    v1, $801f
80003738	lhu    v1, $044c(v1)
8000373C	nop
80003740	sh     v1, $0008(v0)
80003744	lui    v1, $801f
80003748	lhu    v1, $feca(v1)
8000374C	lui    a0, $801b
80003750	addiu  a0, a0, $1798
80003754	xori   v1, v1, $0800
80003758	jal    $800bbeac
8000375C	sh     v1, $0010(v0)
80003760	lui    a0, $801b
80003764	addiu  a0, a0, $1958
80003768	jal    $800bbeac
8000376C	nop
80003770	lui    a0, $801b
80003774	addiu  a0, a0, $2e1c
80003778	jal    $800bbeac
8000377C	nop
80003780	j      $801b3b80
80003784	nop

L3788:	; 80003788
80003788	addiu  s0, s0, $fff6 (=-$a)
8000378C	slti   v0, s0, $0014
80003790	bne    v0, zero, L3b80 [$80003b80]
80003794	addiu  s0, s0, $ffec (=-$14)
80003798	slti   v0, s0, $0032
8000379C	beq    v0, zero, L3874 [$80003874]
800037A0	nop
800037A4	bne    s0, zero, L37cc [$800037cc]
800037A8	slti   v0, s0, $0005

A0 = 22;
A1 = 40;
A2 = 1af;
A3 = 1b0;
[SP + 10] = w(1b1);
funcd55f4; // we play sound here

800037C8	slti   v0, s0, $0005

L37cc:	; 800037CC
800037CC	beq    v0, zero, L3b80 [$80003b80]
800037D0	nop
800037D4	lui    a0, $801b
800037D8	addiu  a0, a0, $32a0
800037DC	jal    $800bbeac
800037E0	nop
800037E4	sll    v0, v0, $05
800037E8	addu   s0, v0, s2
800037EC	jal    $80042da8
800037F0	sh     zero, $0004(s0)
800037F4	lui    v1, $1062
800037F8	ori    v1, v1, $4dd3
800037FC	mult   v0, v1
80003800	sra    v1, v0, $1f
80003804	sh     zero, $0008(s0)
80003808	sh     zero, $000c(s0)
8000380C	mfhi   a0
80003810	sra    a0, a0, $06
80003814	subu   a0, a0, v1
80003818	sll    v1, a0, $05
8000381C	subu   v1, v1, a0
80003820	sll    v1, v1, $02
80003824	addu   v1, v1, a0
80003828	sll    v1, v1, $03
8000382C	subu   v0, v0, v1
80003830	addiu  v0, v0, $f254 (=-$dac)
80003834	jal    $80042da8
80003838	sh     v0, $0006(s0)
8000383C	andi   v0, v0, $0fff
80003840	sh     v0, $000e(s0)
80003844	jal    $80042da8
80003848	sh     zero, $0010(s0)
8000384C	addu   v1, v0, zero
80003850	bgez   v1, L3860 [$80003860]
80003854	sra    v0, v0, $07
80003858	addiu  v0, v1, $007f
8000385C	sra    v0, v0, $07

L3860:	; 80003860
80003860	sll    v0, v0, $07
80003864	subu   v0, v1, v0
80003868	addiu  v0, v0, $0180
8000386C	j      $801b3b80
80003870	sh     v0, $0014(s0)

L3874:	; 80003874
80003874	addiu  s0, s0, $ffce (=-$32)
80003878	slti   v0, s0, $0015
8000387C	beq    v0, zero, L38ac [$800038ac]
80003880	nop
80003884	bne    s0, zero, L3b80 [$80003b80]

A0 = 22;
A1 = 40;
A2 = 1b2;
A3 = 1b3;
[SP + 10] = w(1b4);
funcd55f4; // we play sound here

800038A4	j      $801b3b80
800038A8	nop

L38ac:	; 800038AC
800038AC	addiu  s0, s0, $ffeb (=-$15)
800038B0	slti   v0, s0, $001d
800038B4	beq    v0, zero, L3a50 [$80003a50]
800038B8	addu   a0, s1, zero
800038BC	lui    a1, $8015
800038C0	addiu  a1, a1, $3e30
800038C4	lui    a2, $801f
800038C8	lw     a2, $02e8(a2)
800038CC	jal    $800d41fc
800038D0	lui    s2, $6666
800038D4	lui    a0, $801f
800038D8	lw     a0, $02e8(a0)
800038DC	jal    func3b48c [$8003b48c]
800038E0	ori    s2, s2, $6667
800038E4	lui    a0, $801f
800038E8	lw     a0, $02e8(a0)
800038EC	jal    func3b51c [$8003b51c]
800038F0	addu   s1, zero, zero
800038F4	lui    a2, $801f
800038F8	lw     a2, $02e8(a2)
800038FC	lui    a0, $801f
80003900	addiu  a0, a0, $02e0
80003904	addiu  a1, a2, $0020
80003908	jal    func3bc6c [$8003bc6c]
8000390C	addiu  a2, a2, $0030
80003910	lui    a0, $801b
80003914	addiu  a0, a0, $34ac
80003918	jal    $800bbeac
8000391C	nop
80003920	sll    v0, v0, $05
80003924	lui    a1, $801f
80003928	lw     a1, $02e8(a1)
8000392C	lui    v1, $8016
80003930	addiu  v1, v1, $2978
80003934	lhu    a0, $0020(a1)
80003938	addu   s0, v0, v1
8000393C	sh     a0, $0004(s0)
80003940	lhu    v0, $0024(a1)
80003944	nop
80003948	sh     v0, $0006(s0)
8000394C	lhu    v0, $0028(a1)
80003950	jal    $80042da8
80003954	sh     v0, $0008(s0)
80003958	mult   v0, s2
8000395C	sra    v1, v0, $1f
80003960	mfhi   a0
80003964	sra    a0, a0, $02
80003968	subu   a0, a0, v1
8000396C	sll    v1, a0, $02
80003970	addu   v1, v1, a0
80003974	sll    v1, v1, $01
80003978	lui    at, $801f
8000397C	addu   at, at, s1
80003980	lhu    a0, $02d0(at)
80003984	subu   v0, v0, v1
80003988	addu   a0, a0, v0
8000398C	addiu  a0, a0, $fffb (=-$5)
80003990	jal    $80042da8
80003994	sh     a0, $000c(s0)
80003998	mult   v0, s2
8000399C	sra    v1, v0, $1f
800039A0	mfhi   a0
800039A4	sra    a0, a0, $02
800039A8	subu   a0, a0, v1
800039AC	sll    v1, a0, $02
800039B0	addu   v1, v1, a0
800039B4	sll    v1, v1, $01
800039B8	lui    at, $801f
800039BC	addu   at, at, s1
800039C0	lhu    a0, $02d2(at)
800039C4	subu   v0, v0, v1
800039C8	addu   a0, a0, v0
800039CC	addiu  a0, a0, $fffb (=-$5)
800039D0	jal    $80042da8
800039D4	sh     a0, $000e(s0)
800039D8	mult   v0, s2
800039DC	sra    v1, v0, $1f
800039E0	mfhi   a0
800039E4	sra    a0, a0, $02
800039E8	subu   a0, a0, v1
800039EC	sll    v1, a0, $02
800039F0	addu   v1, v1, a0
800039F4	sll    v1, v1, $01
800039F8	lui    at, $801f
800039FC	addu   at, at, s1
80003A00	lhu    a0, $02d4(at)
80003A04	subu   v0, v0, v1
80003A08	addu   a0, a0, v0
80003A0C	addiu  a0, a0, $fffb (=-$5)
80003A10	jal    $80042da8
80003A14	sh     a0, $0010(s0)
80003A18	addu   v1, v0, zero
80003A1C	bgez   v1, L3a28 [$80003a28]
80003A20	addiu  s1, s1, $0008
80003A24	addiu  v0, v1, $01ff

L3a28:	; 80003A28
80003A28	sra    v0, v0, $09
80003A2C	sll    v0, v0, $09
80003A30	subu   v0, v1, v0
80003A34	addiu  v0, v0, $0200
80003A38	sh     v0, $0014(s0)
80003A3C	slti   v0, s1, $0010
80003A40	beq    v0, zero, L3b80 [$80003b80]
80003A44	nop
80003A48	j      $801b3910
80003A4C	nop

L3a50:	; 80003A50
80003A50	addiu  s0, s0, $ffe3 (=-$1d)
80003A54	slti   v0, s0, $0012
80003A58	beq    v0, zero, L3a80 [$80003a80]
80003A5C	nop
80003A60	bne    s0, zero, L3b80 [$80003b80]
80003A64	nop
80003A68	lui    a0, $801b
80003A6C	addiu  a0, a0, $301c
80003A70	jal    $800bbeac
80003A74	nop
80003A78	j      $801b3b80
80003A7C	nop

L3a80:	; 80003A80
80003A80	addiu  s0, s0, $ffee (=-$12)
80003A84	slti   v0, s0, $0014
80003A88	beq    v0, zero, L3acc [$80003acc]
80003A8C	nop
80003A90	bne    s0, zero, L3b80 [$80003b80]
80003A94	nop
80003A98	lui    a0, $801b
80003A9C	addiu  a0, a0, $1e58
80003AA0	jal    $800bbeac

A0 = 22;
A1 = 40;
A2 = 1b5;
A3 = 1b6;
[SP + 10] = w(1b7);
funcd55f4; // we play sound here

80003AC4	j      $801b3b80
80003AC8	nop

L3acc:	; 80003ACC
80003ACC	addiu  s0, s0, $ffec (=-$14)
80003AD0	slti   v0, s0, $000f
80003AD4	beq    v0, zero, L3b04 [$80003b04]
80003AD8	nop
80003ADC	bne    s0, zero, L3b80 [$80003b80]
80003AE0	nop
80003AE4	lui    a0, $801b
80003AE8	addiu  a0, a0, $233c
80003AEC	jal    $800bbeac
80003AF0	nop
80003AF4	jal    $800d4fa8
80003AF8	ori    a0, zero, $0002
80003AFC	j      $801b3b80
80003B00	nop

L3b04:	; 80003B04
80003B04	addiu  s0, s0, $fff1 (=-$f)
80003B08	slti   v0, s0, $000f
80003B0C	beq    v0, zero, L3b68 [$80003b68]
80003B10	addu   a0, zero, zero
80003B14	bne    s0, zero, L3b80 [$80003b80]
80003B18	addu   s0, zero, zero

loop3b1c:	; 80003B1C
80003B1C	lui    v0, $801f
80003B20	lw     v0, $0480(v0)
80003B24	nop
80003B28	srav   v0, s0, v0
80003B2C	andi   v0, v0, $0001
80003B30	beq    v0, zero, L3b40 [$80003b40]
80003B34	nop
80003B38	jal    $800d5774
80003B3C	addu   a0, s0, zero

L3b40:	; 80003B40
80003B40	addiu  s0, s0, $0001
80003B44	slti   v0, s0, $000a
80003B48	bne    v0, zero, loop3b1c [$80003b1c]
80003B4C	nop
80003B50	lui    a0, $801b
80003B54	addiu  a0, a0, $24c4
80003B58	jal    $800bbeac
80003B5C	nop
80003B60	j      $801b3b80
80003B64	nop

L3b68:	; 80003B68
80003B68	jal    $800d52a0
80003B6C	ori    a1, zero, $0004
80003B70	addiu  v0, zero, $ffff (=-$1)
80003B74	lui    at, $8010
80003B78	sb     zero, $8380(at)
80003B7C	sh     v0, $0000(s3)

L3b80:	; 80003B80
80003B80	lhu    v0, $0002(s3)
80003B84	nop
80003B88	addiu  v0, v0, $0001
80003B8C	sh     v0, $0002(s3)

L3b90:	; 80003B90
80003B90	lw     ra, $0028(sp)
80003B94	lw     s3, $0024(sp)
80003B98	lw     s2, $0020(sp)
80003B9C	lw     s1, $001c(sp)
80003BA0	lw     s0, $0018(sp)
80003BA4	addiu  sp, sp, $0030
80003BA8	jr     ra 
80003BAC	nop

80003BB0	addiu  sp, sp, $ffe0 (=-$20)
80003BB4	sw     s0, $0010(sp)
80003BB8	addu   s0, a0, zero
80003BBC	sw     s1, $0014(sp)
80003BC0	addu   s1, a1, zero
80003BC4	lui    a0, $801b
80003BC8	addiu  a0, a0, $3cf0
80003BCC	addu   a1, zero, zero
80003BD0	addu   a2, zero, zero
80003BD4	sw     ra, $0018(sp)
80003BD8	jal    $800d2980
80003BDC	addu   a3, zero, zero
80003BE0	addu   a0, s0, zero
80003BE4	lui    at, $801f
80003BE8	sw     zero, $0448(at)
80003BEC	lui    at, $801f
80003BF0	sw     zero, $0444(at)
80003BF4	lui    at, $801f
80003BF8	sw     a0, $0480(at)
80003BFC	jal    $800d54ec
80003C00	lui    a1, $1f80
80003C04	sll    v1, s1, $01
80003C08	addu   v1, v1, s1
80003C0C	sll    v0, v1, $05
80003C10	subu   v0, v0, v1
80003C14	sll    v0, v0, $03
80003C18	subu   v0, v0, s1
80003C1C	sll    v0, v0, $02
80003C20	lui    v1, $1f80
80003C24	lh     v1, $0004(v1)
80003C28	lui    at, $8015
80003C2C	addu   at, at, v0
80003C30	lh     v0, $1a50(at)
80003C34	nop
80003C38	slt    v0, v1, v0
80003C3C	beq    v0, zero, L3c60 [$80003c60]
80003C40	addiu  v0, v1, $1388
80003C44	lui    at, $801f
80003C48	sw     v0, $044c(at)
80003C4C	ori    v0, zero, $0800
80003C50	lui    at, $801f
80003C54	sh     v0, $feca(at)
80003C58	j      $801b3c6c
80003C5C	nop

L3c60:	; 80003C60
80003C60	addiu  v0, v1, $ec78 (=-$1388)
80003C64	lui    at, $801f
80003C68	sw     v0, $044c(at)
80003C6C	lui    a0, $801f
80003C70	addiu  a0, a0, $fec8 (=-$138)
80003C74	lui    s0, $801f
80003C78	addiu  s0, s0, $0430
80003C7C	jal    func3c21c [$8003c21c]
80003C80	addu   a1, s0, zero
80003C84	lui    a0, $801b
80003C88	addiu  a0, a0, $35fc
80003C8C	jal    $800bbeac
80003C90	nop
80003C94	jal    $80042da8
80003C98	nop
80003C9C	andi   v0, v0, $0100
80003CA0	lui    a0, $801f
80003CA4	addiu  a0, a0, $ffb8 (=-$48)
80003CA8	beq    v0, zero, L3cb8 [$80003cb8]
80003CAC	addu   a1, s0, zero
80003CB0	lui    a0, $801f
80003CB4	addiu  a0, a0, $fed0 (=-$130)

L3cb8:	; 80003CB8
80003CB8	jal    $801b11bc
80003CBC	addu   a2, s1, zero
80003CC0	lui    v0, $8010
80003CC4	lbu    v0, $8380(v0)
80003CC8	nop
80003CCC	ori    v0, v0, $0008
80003CD0	lui    at, $8010
80003CD4	sb     v0, $8380(at)
80003CD8	lw     ra, $0018(sp)
80003CDC	lw     s1, $0014(sp)
80003CE0	lw     s0, $0010(sp)
80003CE4	addiu  sp, sp, $0020
80003CE8	jr     ra 
80003CEC	nop
