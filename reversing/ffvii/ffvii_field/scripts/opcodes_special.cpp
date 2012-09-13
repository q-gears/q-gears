////////////////////////////////
// 0x0F SPECIAL
800D2164	lui    v0, $800a
800D2168	lbu    v0, $d820(v0)
800D216C	addiu  sp, sp, $ffd0 (=-$30)
800D2170	sw     ra, $002c(sp)
800D2174	andi   v0, v0, $0003
800D2178	beq    v0, zero, Ld2190 [$800d2190]
800D217C	sw     s0, $0028(sp)
800D2180	lui    a0, $800a
800D2184	addiu  a0, a0, $0e78
800D2188	jal    funcbead4 [$800bead4]
800D218C	ori    a1, zero, $0008

Ld2190:	; 800D2190
800D2190	lui    v0, $8007
800D2194	lbu    v0, $22c4(v0)
800D2198	nop
800D219C	sll    v0, v0, $01
800D21A0	lui    at, $8008
800D21A4	addiu  at, at, $31fc
800D21A8	addu   at, at, v0
800D21AC	lhu    v1, $0000(at)
800D21B0	lui    v0, $800a
800D21B4	lw     v0, $c6dc(v0)
800D21B8	nop
800D21BC	addu   v0, v0, v1
800D21C0	lbu    v0, $0001(v0)
800D21C4	lui    s0, $8008
800D21C8	addiu  s0, s0, $31fc
800D21CC	addiu  v1, v0, $ff0b (=-$f5)
800D21D0	sltiu  v0, v1, $000b
800D21D4	beq    v0, zero, Ld2734 [$800d2734]
800D21D8	sll    v0, v1, $02
800D21DC	lui    at, $800a
800D21E0	addiu  at, at, $0ee4
800D21E4	addu   at, at, v0
800D21E8	lw     v0, $0000(at)
800D21EC	nop
800D21F0	jr     v0 
800D21F4	nop

800D21F8	lui    v0, $800a
800D21FC	lbu    v0, $d820(v0)
800D2200	nop
800D2204	andi   v0, v0, $0003
800D2208	beq    v0, zero, Ld2220 [$800d2220]
800D220C	addu   s0, zero, zero
800D2210	lui    a0, $800a
800D2214	addiu  a0, a0, $0e80
800D2218	jal    funcbead4 [$800bead4]
800D221C	ori    a1, zero, $0008

Ld2220:	; 800D2220
800D2220	ori    a0, s0, $c600

loopd2224:	; 800D2224
800D2224	jal    func25288 [$80025288]
800D2228	andi   a0, a0, $ffff
800D222C	addiu  s0, s0, $0001
800D2230	slti   v0, s0, $0200
800D2234	bne    v0, zero, loopd2224 [$800d2224]
800D2238	ori    a0, s0, $c600
800D223C	j      Ld2480 [$800d2480]
800D2240	nop
800D2244	lui    v0, $800a
800D2248	lbu    v0, $d820(v0)
800D224C	nop
800D2250	andi   v0, v0, $0003
800D2254	beq    v0, zero, Ld226c [$800d226c]
800D2258	nop
800D225C	lui    a0, $800a
800D2260	addiu  a0, a0, $0e88
800D2264	jal    funcbead4 [$800bead4]
800D2268	ori    a1, zero, $0008

Ld226c:	; 800D226C
800D226C	jal    func33a90 [$80033a90]
800D2270	nop
800D2274	j      Ld2480 [$800d2480]
800D2278	nop
800D227C	lui    v0, $800a
800D2280	lbu    v0, $d820(v0)
800D2284	nop
800D2288	andi   v0, v0, $0003
800D228C	beq    v0, zero, Ld22a4 [$800d22a4]
800D2290	nop
800D2294	lui    a0, $800a
800D2298	addiu  a0, a0, $0e90
800D229C	jal    funcbead4 [$800bead4]
800D22A0	ori    a1, zero, $0008

Ld22a4:	; 800D22A4
800D22A4	lui    v0, $8007
800D22A8	lbu    v0, $22c4(v0)
800D22AC	nop
800D22B0	sll    v0, v0, $01
800D22B4	lui    at, $8008
800D22B8	addiu  at, at, $31fc
800D22BC	addu   at, at, v0
800D22C0	lhu    v1, $0000(at)
800D22C4	lui    v0, $800a
800D22C8	lw     v0, $c6dc(v0)
800D22CC	nop
800D22D0	addu   v0, v0, v1
800D22D4	lbu    a0, $0002(v0)
800D22D8	lbu    a1, $0003(v0)
800D22DC	jal    funcd7c98 [$800d7c98]
800D22E0	nop
800D22E4	lui    a0, $8007
800D22E8	lbu    a0, $22c4(a0)
800D22EC	lui    v0, $8008
800D22F0	addiu  v0, v0, $31fc
800D22F4	sll    a0, a0, $01
800D22F8	addu   a0, a0, v0
800D22FC	lhu    v1, $0000(a0)
800D2300	addu   v0, zero, zero
800D2304	j      Ld277c [$800d277c]
800D2308	addiu  v1, v1, $0004
800D230C	lui    v0, $800a
800D2310	lbu    v0, $d820(v0)
800D2314	nop
800D2318	andi   v0, v0, $0003
800D231C	beq    v0, zero, Ld2334 [$800d2334]
800D2320	nop
800D2324	lui    a0, $800a
800D2328	addiu  a0, a0, $0e98
800D232C	jal    funcbead4 [$800bead4]
800D2330	ori    a1, zero, $0002

Ld2334:	; 800D2334
800D2334	lui    v0, $8008
800D2338	addiu  v0, v0, $31fc
800D233C	lui    a0, $8007
800D2340	lbu    a0, $22c4(a0)
800D2344	lui    a1, $800a
800D2348	lw     a1, $c6dc(a1)
800D234C	sll    a0, a0, $01
800D2350	addu   a0, a0, v0
800D2354	lhu    v1, $0000(a0)
800D2358	nop
800D235C	addu   a1, a1, v1
800D2360	lhu    v1, $0000(a0)
800D2364	lbu    a1, $0002(a1)
800D2368	addiu  v1, v1, $0003
800D236C	sh     v1, $0000(a0)
800D2370	lui    at, $8007
800D2374	sb     a1, $16cc(at)
800D2378	j      Ld2780 [$800d2780]
800D237C	addu   v0, zero, zero
800D2380	lui    v0, $800a
800D2384	lbu    v0, $d820(v0)
800D2388	nop
800D238C	andi   v0, v0, $0003
800D2390	beq    v0, zero, Ld23a8 [$800d23a8]
800D2394	nop
800D2398	lui    a0, $800a
800D239C	addiu  a0, a0, $0ea0
800D23A0	jal    funcbead4 [$800bead4]
800D23A4	ori    a1, zero, $0002

Ld23a8:	; 800D23A8
800D23A8	lui    v0, $8008
800D23AC	addiu  v0, v0, $31fc
800D23B0	lui    a0, $8007
800D23B4	lbu    a0, $22c4(a0)
800D23B8	lui    a1, $800a
800D23BC	lw     a1, $c6dc(a1)
800D23C0	sll    a0, a0, $01
800D23C4	addu   a0, a0, v0
800D23C8	lhu    v1, $0000(a0)
800D23CC	nop
800D23D0	addu   a1, a1, v1
800D23D4	lhu    v1, $0000(a0)
800D23D8	lbu    a1, $0002(a1)
800D23DC	addiu  v1, v1, $0003
800D23E0	sh     v1, $0000(a0)
800D23E4	lui    at, $8007
800D23E8	sb     a1, $1e30(at)
800D23EC	j      Ld2780 [$800d2780]
800D23F0	addu   v0, zero, zero
800D23F4	lui    v0, $800a
800D23F8	lbu    v0, $d820(v0)
800D23FC	nop
800D2400	andi   v0, v0, $0003
800D2404	beq    v0, zero, Ld241c [$800d241c]
800D2408	addu   s0, zero, zero
800D240C	lui    a0, $800a
800D2410	addiu  a0, a0, $0ea8
800D2414	jal    funcbead4 [$800bead4]
800D2418	ori    a1, zero, $0008

Ld241c:	; 800D241C
800D241C	ori    a0, s0, $c600

loopd2420:	; 800D2420
800D2420	jal    func25380 [$80025380]
800D2424	andi   a0, a0, $ffff
800D2428	addiu  s0, s0, $0001
800D242C	slti   v0, s0, $0200
800D2430	bne    v0, zero, loopd2420 [$800d2420]
800D2434	ori    a0, s0, $c600
800D2438	j      Ld2480 [$800d2480]
800D243C	nop
800D2440	lui    v0, $800a
800D2444	lbu    v0, $d820(v0)
800D2448	nop
800D244C	andi   v0, v0, $0003
800D2450	beq    v0, zero, Ld2468 [$800d2468]
800D2454	addu   s0, zero, zero
800D2458	lui    a0, $800a
800D245C	addiu  a0, a0, $0eb0
800D2460	jal    funcbead4 [$800bead4]
800D2464	ori    a1, zero, $0008

Ld2468:	; 800D2468
800D2468	jal    func2542c [$8002542c]
800D246C	addu   a0, s0, zero
800D2470	addiu  s0, s0, $0001
800D2474	slti   v0, s0, $0050
800D2478	bne    v0, zero, Ld2468 [$800d2468]
800D247C	nop

Ld2480:	; 800D2480
800D2480	lui    v1, $8007
800D2484	lbu    v1, $22c4(v1)
800D2488	lui    v0, $8008
800D248C	addiu  v0, v0, $31fc
800D2490	sll    v1, v1, $01
800D2494	addu   v1, v1, v0
800D2498	lhu    a0, $0000(v1)
800D249C	addu   v0, zero, zero
800D24A0	addiu  a0, a0, $0002
800D24A4	j      Ld2780 [$800d2780]
800D24A8	sh     a0, $0000(v1)
800D24AC	lui    v0, $800a
800D24B0	lbu    v0, $d820(v0)
800D24B4	nop
800D24B8	andi   v0, v0, $0003
800D24BC	beq    v0, zero, Ld24d8 [$800d24d8]
800D24C0	ori    a0, zero, $0004
800D24C4	lui    a0, $800a
800D24C8	addiu  a0, a0, $0eb8
800D24CC	jal    funcbead4 [$800bead4]
800D24D0	ori    a1, zero, $0003
800D24D4	ori    a0, zero, $0004

Ld24d8:	; 800D24D8
800D24D8	jal    read_memory_block_one_byte [$800bee10]
800D24DC	ori    a1, zero, $0003
800D24E0	lui    a0, $8007
800D24E4	lbu    a0, $22c4(a0)
800D24E8	nor    v0, zero, v0
800D24EC	lui    at, $800a
800D24F0	sb     v0, $d7d0(at)
800D24F4	lui    v0, $8008
800D24F8	addiu  v0, v0, $31fc
800D24FC	sll    a0, a0, $01
800D2500	addu   a0, a0, v0
800D2504	lhu    v1, $0000(a0)
800D2508	addu   v0, zero, zero
800D250C	j      Ld277c [$800d277c]
800D2510	addiu  v1, v1, $0004
800D2514	lui    v0, $800a
800D2518	lbu    v0, $d820(v0)
800D251C	nop
800D2520	andi   v0, v0, $0003
800D2524	beq    v0, zero, Ld2540 [$800d2540]
800D2528	ori    a0, zero, $0004
800D252C	lui    a0, $800a
800D2530	addiu  a0, a0, $0ec0
800D2534	jal    funcbead4 [$800bead4]
800D2538	ori    a1, zero, $0003
800D253C	ori    a0, zero, $0004

Ld2540:	; 800D2540
800D2540	lui    a2, $800a
800D2544	lbu    a2, $d7d0(a2)
800D2548	ori    a1, zero, $0003
800D254C	nor    a2, zero, a2
800D2550	jal    store_memory_block_one_byte [$800bf3ac]
800D2554	andi   a2, a2, $00ff
800D2558	lui    a0, $8007
800D255C	lbu    a0, $22c4(a0)
800D2560	lui    v0, $8008
800D2564	addiu  v0, v0, $31fc
800D2568	sll    a0, a0, $01
800D256C	addu   a0, a0, v0
800D2570	lhu    v1, $0000(a0)
800D2574	addu   v0, zero, zero
800D2578	j      Ld277c [$800d277c]
800D257C	addiu  v1, v1, $0004
800D2580	lui    v0, $800a
800D2584	lbu    v0, $d820(v0)
800D2588	nop
800D258C	andi   v0, v0, $0003
800D2590	beq    v0, zero, Ld25a8 [$800d25a8]
800D2594	nop
800D2598	lui    a0, $800a
800D259C	addiu  a0, a0, $0ec8
800D25A0	jal    funcbead4 [$800bead4]
800D25A4	ori    a1, zero, $0008

Ld25a8:	; 800D25A8
800D25A8	ori    a0, zero, $0003
800D25AC	jal    read_memory_block_one_byte [$800bee10]
800D25B0	ori    a1, zero, $0003
800D25B4	jal    system_get_character_name_offset [$800257cc]
800D25B8	andi   a0, v0, $00ff
800D25BC	lui    v1, $8007
800D25C0	lbu    v1, $22c4(v1)
800D25C4	addu   a2, v0, zero
800D25C8	sll    v1, v1, $01
800D25CC	lui    at, $8008
800D25D0	addiu  at, at, $31fc
800D25D4	addu   at, at, v1
800D25D8	lhu    a0, $0000(at)
800D25DC	lui    v1, $800a
800D25E0	lw     v1, $c6dc(v1)
800D25E4	nop
800D25E8	addu   v1, v1, a0
800D25EC	lbu    v0, $0002(v1)
800D25F0	lbu    v1, $0005(v1)
800D25F4	andi   a0, v0, $000f
800D25F8	ori    v0, zero, $000b
800D25FC	beq    a0, v0, Ld263c [$800d263c]
800D2600	addu   a1, zero, zero
800D2604	slti   v0, a0, $000c
800D2608	beq    v0, zero, Ld2620 [$800d2620]
800D260C	ori    v0, zero, $0003
800D2610	beq    a0, v0, Ld2640 [$800d2640]
800D2614	andi   a0, v1, $ffff
800D2618	j      Ld2648 [$800d2648]
800D261C	nop

Ld2620:	; 800D2620
800D2620	ori    v0, zero, $000d
800D2624	beq    a0, v0, Ld2638 [$800d2638]
800D2628	ori    v0, zero, $000f
800D262C	bne    a0, v0, Ld2648 [$800d2648]
800D2630	andi   a0, v1, $ffff
800D2634	ori    a1, zero, $0100

Ld2638:	; 800D2638
800D2638	addiu  a1, a1, $0100

Ld263c:	; 800D263C
800D263C	addiu  a1, a1, $0100

Ld2640:	; 800D2640
800D2640	addiu  a1, a1, $0100
800D2644	andi   a0, v1, $ffff

Ld2648:	; 800D2648
800D2648	blez   a0, Ld267c [$800d267c]
800D264C	addu   s0, zero, zero
800D2650	andi   a3, a1, $ffff
800D2654	lui    t0, $800a
800D2658	addiu  t0, t0, $d288 (=-$2d78)

loopd265c:	; 800D265C
800D265C	lbu    v0, $0000(a2)
800D2660	addu   v1, a3, s0
800D2664	addiu  s0, s0, $0001
800D2668	addu   v1, v1, t0
800D266C	sb     v0, $0000(v1)
800D2670	slt    v0, s0, a0
800D2674	bne    v0, zero, loopd265c [$800d265c]
800D2678	addiu  a2, a2, $0001

Ld267c:	; 800D267C
800D267C	andi   v0, a1, $ffff
800D2680	addu   v0, v0, s0
800D2684	ori    v1, zero, $00ff
800D2688	lui    at, $800a
800D268C	addiu  at, at, $d288 (=-$2d78)
800D2690	addu   at, at, v0
800D2694	sb     v1, $0000(at)
800D2698	lui    a0, $8007
800D269C	lbu    a0, $22c4(a0)
800D26A0	lui    v0, $8008
800D26A4	addiu  v0, v0, $31fc
800D26A8	sll    a0, a0, $01
800D26AC	addu   a0, a0, v0
800D26B0	lhu    v1, $0000(a0)
800D26B4	addu   v0, zero, zero
800D26B8	j      Ld277c [$800d277c]
800D26BC	addiu  v1, v1, $0006
800D26C0	lui    v0, $800a
800D26C4	lbu    v0, $d820(v0)
800D26C8	nop
800D26CC	andi   v0, v0, $0003
800D26D0	beq    v0, zero, Ld26e8 [$800d26e8]
800D26D4	nop
800D26D8	lui    a0, $800a
800D26DC	addiu  a0, a0, $0ed0
800D26E0	jal    funcbead4 [$800bead4]
800D26E4	ori    a1, zero, $0008

Ld26e8:	; 800D26E8
800D26E8	lui    v0, $8008
800D26EC	addiu  v0, v0, $31fc
800D26F0	lui    a0, $8007
800D26F4	lbu    a0, $22c4(a0)
800D26F8	lui    a1, $800a
800D26FC	lw     a1, $c6dc(a1)
800D2700	sll    a0, a0, $01
800D2704	addu   a0, a0, v0
800D2708	lhu    v1, $0000(a0)
800D270C	nop
800D2710	addu   a1, a1, v1
800D2714	lhu    v1, $0000(a0)
800D2718	lbu    a1, $0002(a1)
800D271C	addiu  v1, v1, $0003
800D2720	sh     v1, $0000(a0)
800D2724	lui    at, $8007
800D2728	sb     a1, $1c1c(at)
800D272C	j      Ld2780 [$800d2780]
800D2730	addu   v0, zero, zero

Ld2734:	; 800D2734
800D2734	lui    v0, $800a
800D2738	lbu    v0, $d820(v0)
800D273C	nop
800D2740	andi   v0, v0, $0003
800D2744	beq    v0, zero, Ld275c [$800d275c]
800D2748	nop
800D274C	lui    a0, $800a
800D2750	addiu  a0, a0, $0ed8
800D2754	jal    funcbead4 [$800bead4]
800D2758	ori    a1, zero, $0008

Ld275c:	; 800D275C
800D275C	lui    a0, $8007
800D2760	lbu    a0, $22c4(a0)
800D2764	nop
800D2768	sll    a0, a0, $01
800D276C	addu   a0, a0, s0
800D2770	lhu    v1, $0000(a0)
800D2774	addu   v0, zero, zero
800D2778	addiu  v1, v1, $0002

Ld277c:	; 800D277C
800D277C	sh     v1, $0000(a0)

Ld2780:	; 800D2780
800D2780	lw     ra, $002c(sp)
800D2784	lw     s0, $0028(sp)
800D2788	addiu  sp, sp, $0030
800D278C	jr     ra 
800D2790	nop
////////////////////////////////

