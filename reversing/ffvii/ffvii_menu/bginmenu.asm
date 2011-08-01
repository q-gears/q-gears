
Entry:	; 801D0000
801D0000	addiu  sp, sp, $ffb0 (=-$50)
801D0004	sw     s2, $0048(sp)
801D0008	lui    s2, $801d
801D000C	addiu  s2, s2, $0860
801D0010	addu   a0, s2, zero
801D0014	addu   a1, zero, zero
801D0018	addu   a2, zero, zero
801D001C	ori    a3, zero, $0001
801D0020	sw     s1, $0044(sp)
801D0024	ori    s1, zero, $0003
801D0028	sw     s0, $0040(sp)
801D002C	ori    s0, zero, $0001
801D0030	sw     ra, $004c(sp)
801D0034	sw     s1, $0010(sp)
801D0038	sw     zero, $0014(sp)
801D003C	sw     zero, $0018(sp)
801D0040	sw     s0, $001c(sp)
801D0044	sw     s1, $0020(sp)
801D0048	sw     zero, $0024(sp)
801D004C	sw     zero, $0028(sp)
801D0050	sw     zero, $002c(sp)
801D0054	sw     s0, $0030(sp)
801D0058	jal    $80026448
801D005C	sw     zero, $0034(sp)
801D0060	addiu  a0, s2, $0012
801D0064	addu   a1, zero, zero
801D0068	addu   a2, zero, zero
801D006C	ori    a3, zero, $0001
801D0070	ori    v0, zero, $0009
801D0074	sw     s1, $0010(sp)
801D0078	sw     zero, $0014(sp)
801D007C	sw     zero, $0018(sp)
801D0080	sw     s0, $001c(sp)
801D0084	sw     v0, $0020(sp)
801D0088	sw     zero, $0024(sp)
801D008C	sw     zero, $0028(sp)
801D0090	sw     zero, $002c(sp)
801D0094	sw     zero, $0030(sp)
801D0098	jal    $80026448
801D009C	sw     zero, $0034(sp)
801D00A0	lui    at, $801d
801D00A4	sw     zero, $07f0(at)
801D00A8	lw     ra, $004c(sp)
801D00AC	lw     s2, $0048(sp)
801D00B0	lw     s1, $0044(sp)
801D00B4	lw     s0, $0040(sp)
801D00B8	addiu  sp, sp, $0050
801D00BC	jr     ra 
801D00C0	nop

801D00C4	lui    a0, $8006
801D00C8	lw     a0, $2f58(a0)
801D00CC	addiu  sp, sp, $ffd0 (=-$30)
801D00D0	sw     ra, $0028(sp)
801D00D4	sw     s1, $0024(sp)
801D00D8	jal    $800230c4
801D00DC	sw     s0, $0020(sp)
801D00E0	lui    v0, $801d
801D00E4	lw     v0, $07f0(v0)
801D00E8	nop
801D00EC	bne    v0, zero, L1d0118 [$801d0118]
801D00F0	nop
801D00F4	addu   a0, zero, zero
801D00F8	lui    v0, $801d
801D00FC	lb     v0, $086b(v0)
801D0100	lui    a1, $801d
801D0104	lh     a1, $07fe(a1)
801D0108	sll    v0, v0, $06
801D010C	addu   a1, a1, v0
801D0110	jal    $8001eb2c
801D0114	addiu  a1, a1, $0020

L1d0118:	; 801D0118
801D0118	ori    a0, zero, $0010
801D011C	ori    a1, zero, $000b
801D0120	lui    a2, $801d
801D0124	addiu  a2, a2, $0804
801D0128	jal    $80026f44
801D012C	ori    a3, zero, $0007
801D0130	addu   s1, zero, zero
801D0134	lui    s0, $801d
801D0138	addiu  s0, s0, $07f4

loop1d013c:	; 801D013C
801D013C	jal    $8001e040
801D0140	addu   a0, s0, zero
801D0144	addiu  s1, s1, $0001
801D0148	slti   v0, s1, $0002
801D014C	bne    v0, zero, loop1d013c [$801d013c]
801D0150	addiu  s0, s0, $0008
801D0154	lui    v0, $801d
801D0158	lw     v0, $07f0(v0)
801D015C	nop
801D0160	sll    a0, v0, $03
801D0164	addu   a0, a0, v0
801D0168	sll    a0, a0, $01
801D016C	lui    v0, $801d
801D0170	addiu  v0, v0, $0860
801D0174	jal    $800264a8
801D0178	addu   a0, a0, v0
801D017C	lui    v0, $8006
801D0180	lhu    v0, $2d7e(v0)
801D0184	nop
801D0188	andi   v0, v0, $0040
801D018C	beq    v0, zero, L1d01a4 [$801d01a4]
801D0190	ori    a0, zero, $0005
801D0194	jal    $8002305c
801D0198	addu   a1, zero, zero
801D019C	jal    $8002120c
801D01A0	addu   a0, zero, zero

L1d01a4:	; 801D01A4
801D01A4	lw     ra, $0028(sp)
801D01A8	lw     s1, $0024(sp)
801D01AC	lw     s0, $0020(sp)
801D01B0	addiu  sp, sp, $0030
801D01B4	jr     ra 
801D01B8	nop

801D01BC	jr     ra 
801D01C0	nop

801D01C4	addu   a1, zero, zero
801D01C8	addu   a2, zero, zero
801D01CC	addiu  a3, zero, $ffff (=-$1)
801D01D0	sll    v0, a0, $05
801D01D4	addu   v0, v0, a0
801D01D8	sll    v0, v0, $02
801D01DC	lui    v1, $800a
801D01E0	addiu  v1, v1, $c778 (=-$3888)
801D01E4	addu   v1, v0, v1

loop1d01e8:	; 801D01E8
801D01E8	lw     v0, $0000(v1)
801D01EC	nop
801D01F0	beq    v0, a3, L1d01fc [$801d01fc]
801D01F4	nop
801D01F8	addiu  a2, a2, $0001

L1d01fc:	; 801D01FC
801D01FC	addiu  a1, a1, $0001
801D0200	slti   v0, a1, $0008
801D0204	bne    v0, zero, loop1d01e8 [$801d01e8]
801D0208	addiu  v1, v1, $0004
801D020C	addu   a1, zero, zero
801D0210	addiu  a3, zero, $ffff (=-$1)
801D0214	sll    v0, a0, $05
801D0218	addu   v0, v0, a0
801D021C	sll    v0, v0, $02
801D0220	lui    v1, $800a
801D0224	addiu  v1, v1, $c798 (=-$3868)
801D0228	addu   v1, v0, v1

loop1d022c:	; 801D022C
801D022C	lw     v0, $0000(v1)
801D0230	nop
801D0234	beq    v0, a3, L1d0240 [$801d0240]
801D0238	nop
801D023C	addiu  a2, a2, $0001

L1d0240:	; 801D0240
801D0240	addiu  a1, a1, $0001
801D0244	slti   v0, a1, $0008
801D0248	bne    v0, zero, loop1d022c [$801d022c]
801D024C	addiu  v1, v1, $0004
801D0250	jr     ra 
801D0254	addu   v0, a2, zero


func1d0258:	; 801D0258
801D0258	lbu    v0, $0001(a0)
801D025C	lbu    v1, $0000(a0)
801D0260	sll    v0, v0, $08
801D0264	jr     ra 
801D0268	or     v0, v1, v0

801D026C	srl    v0, a1, $08
801D0270	sb     a1, $0000(a0)
801D0274	jr     ra 
801D0278	sb     v0, $0001(a0)

801D027C	addiu  sp, sp, $ffd8 (=-$28)
801D0280	sw     s2, $0018(sp)
801D0284	addu   s2, zero, zero
801D0288	sw     s3, $001c(sp)
801D028C	lui    s3, $8000
801D0290	ori    s3, s3, $8001
801D0294	lui    v0, $800a
801D0298	addiu  v0, v0, $d3fc (=-$2c04)
801D029C	sw     s0, $0010(sp)
801D02A0	addiu  s0, v0, $f368 (=-$c98)
801D02A4	sw     s1, $0014(sp)
801D02A8	addu   s1, v0, zero
801D02AC	sw     ra, $0020(sp)

loop1d02b0:	; 801D02B0
801D02B0	jal    func1d0258 [$801d0258]
801D02B4	addu   a0, s1, zero
801D02B8	lhu    v1, $0000(s0)
801D02BC	nop
801D02C0	mult   v1, v0
801D02C4	mflo   v1
801D02C8	mult   v1, s3
801D02CC	mfhi   a1
801D02D0	addu   v0, a1, v1
801D02D4	sra    v0, v0, $0f
801D02D8	sra    v1, v1, $1f
801D02DC	subu   v0, v0, v1
801D02E0	bgtz   v0, L1d02ec [$801d02ec]
801D02E4	nop
801D02E8	ori    v0, zero, $0001

L1d02ec:	; 801D02EC
801D02EC	sh     v0, $0000(s0)
801D02F0	addiu  s0, s0, $0084
801D02F4	addiu  s2, s2, $0001
801D02F8	slti   v0, s2, $0005
801D02FC	bne    v0, zero, loop1d02b0 [$801d02b0]
801D0300	addiu  s1, s1, $0002
801D0304	lw     ra, $0020(sp)
801D0308	lw     s3, $001c(sp)
801D030C	lw     s2, $0018(sp)
801D0310	lw     s1, $0014(sp)
801D0314	lw     s0, $0010(sp)
801D0318	addiu  sp, sp, $0028
801D031C	jr     ra 
801D0320	nop


func1d0324:	; 801D0324
801D0324	addiu  v0, zero, $ff00 (=-$100)
801D0328	or     a0, a0, v0
801D032C	addu   a2, zero, zero
801D0330	addiu  t1, zero, $ffff (=-$1)
801D0334	lui    t2, $800a
801D0338	addiu  t2, t2, $d78a (=-$2876)
801D033C	addiu  t0, t2, $f00e (=-$ff2)
801D0340	addiu  a3, t2, $efee (=-$1012)

loop1d0344:	; 801D0344
801D0344	lhu    v0, $0000(t2)
801D0348	nop
801D034C	srav   v0, a2, v0
801D0350	andi   v0, v0, $0001
801D0354	beq    v0, zero, L1d03b4 [$801d03b4]
801D0358	nop
801D035C	addu   a1, zero, zero
801D0360	addu   v1, a3, zero

loop1d0364:	; 801D0364
801D0364	lw     v0, $0000(v1)
801D0368	nop
801D036C	beq    v0, a0, L1d039c [$801d039c]
801D0370	nop
801D0374	addiu  a1, a1, $0001
801D0378	slti   v0, a1, $0008
801D037C	bne    v0, zero, loop1d0364 [$801d0364]
801D0380	addiu  v1, v1, $0004
801D0384	addu   a1, zero, zero
801D0388	addu   v1, t0, zero

loop1d038c:	; 801D038C
801D038C	lw     v0, $0000(v1)
801D0390	nop
801D0394	bne    v0, a0, L1d03a4 [$801d03a4]
801D0398	nop

L1d039c:	; 801D039C
801D039C	j      L1d0400 [$801d0400]
801D03A0	sw     t1, $0000(v1)

L1d03a4:	; 801D03A4
801D03A4	addiu  a1, a1, $0001
801D03A8	slti   v0, a1, $0008
801D03AC	bne    v0, zero, loop1d038c [$801d038c]
801D03B0	addiu  v1, v1, $0004

L1d03b4:	; 801D03B4
801D03B4	addiu  t0, t0, $0084
801D03B8	addiu  a2, a2, $0001
801D03BC	slti   v0, a2, $0009
801D03C0	bne    v0, zero, loop1d0344 [$801d0344]
801D03C4	addiu  a3, a3, $0084
801D03C8	addu   a1, zero, zero
801D03CC	addiu  a2, zero, $ffff (=-$1)
801D03D0	lui    v1, $800a
801D03D4	addiu  v1, v1, $ce60 (=-$31a0)

loop1d03d8:	; 801D03D8
801D03D8	lw     v0, $0000(v1)
801D03DC	nop
801D03E0	bne    v0, a0, L1d03f0 [$801d03f0]
801D03E4	nop
801D03E8	j      L1d0400 [$801d0400]
801D03EC	sw     a2, $0000(v1)

L1d03f0:	; 801D03F0
801D03F0	addiu  a1, a1, $0001
801D03F4	slti   v0, a1, $00c8
801D03F8	bne    v0, zero, loop1d03d8 [$801d03d8]
801D03FC	addiu  v1, v1, $0004

L1d0400:	; 801D0400
801D0400	jr     ra 
801D0404	nop


func1d0408:	; 801D0408
801D0408	addu   a3, zero, zero
801D040C	lui    v0, $800a
801D0410	addiu  v0, v0, $d78a (=-$2876)
801D0414	lhu    t3, $0000(v0)
801D0418	lui    t2, $00ff
801D041C	ori    t2, t2, $ffff
801D0420	addiu  t1, v0, $f00e (=-$ff2)
801D0424	addiu  t0, v0, $efee (=-$1012)

loop1d0428:	; 801D0428
801D0428	srav   v0, a3, t3
801D042C	andi   v0, v0, $0001
801D0430	beq    v0, zero, L1d04a0 [$801d04a0]
801D0434	nop
801D0438	addu   a1, zero, zero
801D043C	addu   a2, t0, zero

loop1d0440:	; 801D0440
801D0440	lw     v0, $0000(a2)
801D0444	nop
801D0448	srl    v1, v0, $08
801D044C	bne    v1, t2, L1d045c [$801d045c]
801D0450	andi   v0, v0, $00ff
801D0454	beq    v0, a0, L1d04f8 [$801d04f8]
801D0458	ori    v0, zero, $0001

L1d045c:	; 801D045C
801D045C	addiu  a1, a1, $0001
801D0460	slti   v0, a1, $0008
801D0464	bne    v0, zero, loop1d0440 [$801d0440]
801D0468	addiu  a2, a2, $0004
801D046C	addu   a1, zero, zero
801D0470	addu   a2, t1, zero

loop1d0474:	; 801D0474
801D0474	lw     v0, $0000(a2)
801D0478	nop
801D047C	srl    v1, v0, $08
801D0480	bne    v1, t2, L1d0490 [$801d0490]
801D0484	andi   v0, v0, $00ff
801D0488	beq    v0, a0, L1d04f8 [$801d04f8]
801D048C	ori    v0, zero, $0001

L1d0490:	; 801D0490
801D0490	addiu  a1, a1, $0001
801D0494	slti   v0, a1, $0008
801D0498	bne    v0, zero, loop1d0474 [$801d0474]
801D049C	addiu  a2, a2, $0004

L1d04a0:	; 801D04A0
801D04A0	addiu  t1, t1, $0084
801D04A4	addiu  a3, a3, $0001
801D04A8	slti   v0, a3, $0009
801D04AC	bne    v0, zero, loop1d0428 [$801d0428]
801D04B0	addiu  t0, t0, $0084
801D04B4	addu   a1, zero, zero
801D04B8	lui    a3, $00ff
801D04BC	ori    a3, a3, $ffff
801D04C0	lui    a2, $800a
801D04C4	addiu  a2, a2, $ce60 (=-$31a0)

loop1d04c8:	; 801D04C8
801D04C8	lw     v0, $0000(a2)
801D04CC	nop
801D04D0	srl    v1, v0, $08
801D04D4	bne    v1, a3, L1d04e4 [$801d04e4]
801D04D8	andi   v0, v0, $00ff
801D04DC	beq    v0, a0, L1d04f8 [$801d04f8]
801D04E0	ori    v0, zero, $0001

L1d04e4:	; 801D04E4
801D04E4	addiu  a1, a1, $0001
801D04E8	slti   v0, a1, $00c8
801D04EC	bne    v0, zero, loop1d04c8 [$801d04c8]
801D04F0	addiu  a2, a2, $0004
801D04F4	addu   v0, zero, zero

L1d04f8:	; 801D04F8
801D04F8	jr     ra 
801D04FC	nop


func1d0500:	; 801D0500
801D0500	addu   a2, zero, zero
801D0504	lui    v0, $800a
801D0508	addiu  v0, v0, $d78a (=-$2876)
801D050C	lhu    t1, $0000(v0)
801D0510	addiu  t0, v0, $f00e (=-$ff2)
801D0514	addiu  a3, v0, $efee (=-$1012)

loop1d0518:	; 801D0518
801D0518	srav   v0, a2, t1
801D051C	andi   v0, v0, $0001
801D0520	beq    v0, zero, L1d0578 [$801d0578]
801D0524	nop
801D0528	addu   v1, zero, zero
801D052C	addu   a1, a3, zero

loop1d0530:	; 801D0530
801D0530	lbu    v0, $0000(a1)
801D0534	nop
801D0538	beq    v0, a0, L1d05bc [$801d05bc]
801D053C	ori    v0, zero, $0001
801D0540	addiu  v1, v1, $0001
801D0544	slti   v0, v1, $0008
801D0548	bne    v0, zero, loop1d0530 [$801d0530]
801D054C	addiu  a1, a1, $0004
801D0550	addu   v1, zero, zero
801D0554	addu   a1, t0, zero

loop1d0558:	; 801D0558
801D0558	lbu    v0, $0000(a1)
801D055C	nop
801D0560	beq    v0, a0, L1d05bc [$801d05bc]
801D0564	ori    v0, zero, $0001
801D0568	addiu  v1, v1, $0001
801D056C	slti   v0, v1, $0008
801D0570	bne    v0, zero, loop1d0558 [$801d0558]
801D0574	addiu  a1, a1, $0004

L1d0578:	; 801D0578
801D0578	addiu  t0, t0, $0084
801D057C	addiu  a2, a2, $0001
801D0580	slti   v0, a2, $0009
801D0584	bne    v0, zero, loop1d0518 [$801d0518]
801D0588	addiu  a3, a3, $0084
801D058C	addu   v1, zero, zero
801D0590	lui    a1, $800a
801D0594	addiu  a1, a1, $ce60 (=-$31a0)

loop1d0598:	; 801D0598
801D0598	lbu    v0, $0000(a1)
801D059C	nop
801D05A0	beq    v0, a0, L1d05bc [$801d05bc]
801D05A4	ori    v0, zero, $0001
801D05A8	addiu  v1, v1, $0001
801D05AC	slti   v0, v1, $00c8
801D05B0	bne    v0, zero, loop1d0598 [$801d0598]
801D05B4	addiu  a1, a1, $0004
801D05B8	addu   v0, zero, zero

L1d05bc:	; 801D05BC
801D05BC	jr     ra 
801D05C0	nop

801D05C4	addiu  sp, sp, $ffe8 (=-$18)
801D05C8	ori    v0, zero, $0001
801D05CC	sw     ra, $0014(sp)
801D05D0	sw     s0, $0010(sp)
801D05D4	lui    at, $800a
801D05D8	sb     zero, $d6f7(at)
801D05DC	beq    a0, v0, L1d064c [$801d064c]
801D05E0	slti   v0, a0, $0002
801D05E4	beq    v0, zero, L1d05fc [$801d05fc]
801D05E8	nop
801D05EC	beq    a0, zero, L1d0618 [$801d0618]
801D05F0	addu   s0, zero, zero
801D05F4	j      L1d06e8 [$801d06e8]
801D05F8	ori    v0, zero, $0001

L1d05fc:	; 801D05FC
801D05FC	ori    v0, zero, $0002
801D0600	beq    a0, v0, L1d0684 [$801d0684]
801D0604	ori    v0, zero, $0003
801D0608	beq    a0, v0, L1d06bc [$801d06bc]
801D060C	addu   s0, zero, zero
801D0610	j      L1d06e8 [$801d06e8]
801D0614	ori    v0, zero, $0001

L1d0618:	; 801D0618
801D0618	lui    at, $801d
801D061C	addiu  at, at, $082c
801D0620	addu   at, at, s0
801D0624	lbu    a0, $0000(at)
801D0628	jal    func1d0408 [$801d0408]
801D062C	nop
801D0630	beq    v0, zero, L1d06f0 [$801d06f0]
801D0634	addiu  s0, s0, $0001
801D0638	slti   v0, s0, $0015
801D063C	bne    v0, zero, L1d0618 [$801d0618]
801D0640	ori    v0, zero, $0001
801D0644	j      L1d06e8 [$801d06e8]
801D0648	nop

L1d064c:	; 801D064C
801D064C	addu   s0, zero, zero

loop1d0650:	; 801D0650
801D0650	lui    at, $801d
801D0654	addiu  at, at, $0844
801D0658	addu   at, at, s0
801D065C	lbu    a0, $0000(at)
801D0660	jal    func1d0408 [$801d0408]
801D0664	nop
801D0668	beq    v0, zero, L1d06f0 [$801d06f0]
801D066C	addiu  s0, s0, $0001
801D0670	slti   v0, s0, $0010
801D0674	bne    v0, zero, loop1d0650 [$801d0650]
801D0678	ori    v0, zero, $0001
801D067C	j      L1d06e8 [$801d06e8]
801D0680	nop

L1d0684:	; 801D0684
801D0684	addu   s0, zero, zero

loop1d0688:	; 801D0688
801D0688	lui    at, $801d
801D068C	addiu  at, at, $0854
801D0690	addu   at, at, s0
801D0694	lbu    a0, $0000(at)
801D0698	jal    func1d0408 [$801d0408]
801D069C	nop
801D06A0	beq    v0, zero, L1d06f0 [$801d06f0]
801D06A4	addiu  s0, s0, $0001
801D06A8	slti   v0, s0, $0007
801D06AC	bne    v0, zero, loop1d0688 [$801d0688]
801D06B0	ori    v0, zero, $0001
801D06B4	j      L1d06e8 [$801d06e8]
801D06B8	nop

L1d06bc:	; 801D06BC
801D06BC	lui    at, $801d
801D06C0	addiu  at, at, $085c
801D06C4	addu   at, at, s0
801D06C8	lbu    a0, $0000(at)
801D06CC	jal    func1d0500 [$801d0500]
801D06D0	nop
801D06D4	beq    v0, zero, L1d06f0 [$801d06f0]
801D06D8	addiu  s0, s0, $0001
801D06DC	slti   v0, s0, $0002
801D06E0	bne    v0, zero, L1d06bc [$801d06bc]
801D06E4	ori    v0, zero, $0001

L1d06e8:	; 801D06E8
801D06E8	lui    at, $800a
801D06EC	sb     v0, $d6f7(at)

L1d06f0:	; 801D06F0
801D06F0	lw     ra, $0014(sp)
801D06F4	lw     s0, $0010(sp)
801D06F8	addiu  sp, sp, $0018
801D06FC	jr     ra 
801D0700	nop

801D0704	addiu  sp, sp, $ffe8 (=-$18)
801D0708	ori    v0, zero, $0001
801D070C	sw     ra, $0014(sp)
801D0710	beq    a0, v0, L1d077c [$801d077c]
801D0714	sw     s0, $0010(sp)
801D0718	slti   v0, a0, $0002
801D071C	beq    v0, zero, L1d0734 [$801d0734]
801D0720	nop
801D0724	beq    a0, zero, L1d0750 [$801d0750]
801D0728	addu   s0, zero, zero
801D072C	j      L1d07dc [$801d07dc]
801D0730	nop

L1d0734:	; 801D0734
801D0734	ori    v0, zero, $0002
801D0738	beq    a0, v0, L1d07ac [$801d07ac]
801D073C	ori    v0, zero, $0003
801D0740	beq    a0, v0, L1d07d4 [$801d07d4]
801D0744	ori    a0, zero, $0058
801D0748	j      L1d07dc [$801d07dc]
801D074C	nop

L1d0750:	; 801D0750
801D0750	lui    at, $801d
801D0754	addiu  at, at, $082c
801D0758	addu   at, at, s0
801D075C	lbu    a0, $0000(at)
801D0760	jal    func1d0324 [$801d0324]
801D0764	addiu  s0, s0, $0001
801D0768	slti   v0, s0, $0015
801D076C	bne    v0, zero, L1d0750 [$801d0750]
801D0770	ori    a0, zero, $0049
801D0774	j      L1d07d4 [$801d07d4]
801D0778	nop

L1d077c:	; 801D077C
801D077C	addu   s0, zero, zero

loop1d0780:	; 801D0780
801D0780	lui    at, $801d
801D0784	addiu  at, at, $0844
801D0788	addu   at, at, s0
801D078C	lbu    a0, $0000(at)
801D0790	jal    func1d0324 [$801d0324]
801D0794	addiu  s0, s0, $0001
801D0798	slti   v0, s0, $0010
801D079C	bne    v0, zero, loop1d0780 [$801d0780]
801D07A0	ori    a0, zero, $005a
801D07A4	j      L1d07d4 [$801d07d4]
801D07A8	nop

L1d07ac:	; 801D07AC
801D07AC	addu   s0, zero, zero

loop1d07b0:	; 801D07B0
801D07B0	lui    at, $801d
801D07B4	addiu  at, at, $0854
801D07B8	addu   at, at, s0
801D07BC	lbu    a0, $0000(at)
801D07C0	jal    func1d0324 [$801d0324]
801D07C4	addiu  s0, s0, $0001
801D07C8	slti   v0, s0, $0007
801D07CC	bne    v0, zero, loop1d07b0 [$801d07b0]
801D07D0	ori    a0, zero, $0030

L1d07d4:	; 801D07D4
801D07D4	jal    $8002542c
801D07D8	nop

L1d07dc:	; 801D07DC
801D07DC	lw     ra, $0014(sp)
801D07E0	lw     s0, $0010(sp)
801D07E4	addiu  sp, sp, $0018
801D07E8	jr     ra 
801D07EC	nop
