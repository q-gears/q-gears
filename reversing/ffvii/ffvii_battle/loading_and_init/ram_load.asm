///////////////////////////////////////////////////////////////////
// func1b0050
801B0050-801B048C
///////////////////////////////////////////////////////////////////



801B0490	lui    v0, $8016
801B0494	lhu    v0, $376c(v0)

func1b0498:	; 801B0498
801B0498	addiu  sp, sp, $ffd0 (=-$30)
801B049C	sw     s5, $0024(sp)
801B04A0	addu   s5, a0, zero
801B04A4	sw     s1, $0014(sp)
801B04A8	ori    s1, zero, $0004
801B04AC	sw     ra, $0028(sp)
801B04B0	sw     s4, $0020(sp)

L1b04b4:	; 801B04B4
801B04B4	sw     s3, $001c(sp)
801B04B8	sw     s2, $0018(sp)
801B04BC	beq    v0, zero, L1b04f0 [$801b04f0]

func1b04c0:	; 801B04C0
801B04C0	sw     s0, $0010(sp)
801B04C4	addu   s1, zero, zero
801B04C8	addu   a0, zero, zero
801B04CC	addu   a1, zero, zero
801B04D0	ori    a2, zero, $000f
801B04D4	jal    funca7254 [$800a7254]
801B04D8	addu   a3, zero, zero
801B04DC	addu   a0, zero, zero
801B04E0	addu   a1, zero, zero
801B04E4	ori    a2, zero, $000e
801B04E8	jal    funca7254 [$800a7254]
801B04EC	addu   a3, zero, zero

L1b04f0:	; 801B04F0
801B04F0	addu   s0, zero, zero

L1b04f4:	; 801B04F4
801B04F4	addiu  a0, zero, $ffff (=-$1)
801B04F8	lui    v1, $800f
801B04FC	addiu  v1, v1, $6936

loop1b0500:	; 801B0500
801B0500	lb     v0, $0000(v1)
801B0504	nop
801B0508	slt    v0, v0, s1
801B050C	bne    v0, zero, L1b0518 [$801b0518]
801B0510	nop
801B0514	sb     a0, $0000(v1)

L1b0518:	; 801B0518
801B0518	addiu  s0, s0, $0001
801B051C	slti   v0, s0, $0040
801B0520	bne    v0, zero, loop1b0500 [$801b0500]
801B0524	addiu  v1, v1, $0008
801B0528	ori    v0, zero, $0068

loop1b052c:	; 801B052C
801B052C	lui    at, $800f
801B0530	addu   at, at, v0
801B0534	sb     zero, $5e66(at)
801B0538	addiu  v0, v0, $ffcc (=-$34)
801B053C	bgez   v0, loop1b052c [$801b052c]
801B0540	nop
801B0544	lui    v0, $8016
801B0548	lhu    v0, $376c(v0)
801B054C	nop
801B0550	beq    v0, zero, L1b0560 [$801b0560]
801B0554	nop
801B0558	jal    func1b0f08 [$801b0f08]
801B055C	nop

L1b0560:	; 801B0560
801B0560	lui    a1, $800a
801B0564	addiu  a1, a1, $3354
801B0568	jal    initbattle_load_enemy_from_scene [$801b23e0]
801B056C	addu   a0, s5, zero
801B0570	jal    func1b1e0c [$801b1e0c]
801B0574	addu   s0, zero, zero
801B0578	lui    v0, $8010
801B057C	addiu  v0, v0, $83ae (=-$7c52)
801B0580	sh     zero, $0000(v0)
801B0584	addiu  s4, zero, $ffff (=-$1)
801B0588	ori    s3, zero, $0001
801B058C	addiu  s2, v0, $0032
801B0590	addu   s1, s2, zero

loop1b0594:	; 801B0594
801B0594	jal    funcae954 [$800ae954]
801B0598	addu   a0, s0, zero
801B059C	lb     v0, $0008(s1)
801B05A0	nop
801B05A4	beq    v0, s4, L1b05bc [$801b05bc]
801B05A8	sllv   v1, s0, s3
801B05AC	lhu    v0, $ffce(s2)
801B05B0	nop
801B05B4	or     v0, v0, v1

L1b05b8:	; 801B05B8
801B05B8	sh     v0, $ffce(s2)

L1b05bc:	; 801B05BC
801B05BC	addiu  s0, s0, $0001
801B05C0	slti   v0, s0, $000a
801B05C4	bne    v0, zero, loop1b0594 [$801b0594]
801B05C8	addiu  s1, s1, $0068
801B05CC	ori    s0, zero, $0004
801B05D0	lui    v0, $8016
801B05D4	lbu    v0, $3626(v0)
801B05D8	lui    at, $8010

L1b05dc:	; 801B05DC
801B05DC	sh     s5, $83cc(at)
801B05E0	lui    at, $8010
801B05E4	sb     v0, $83a8(at)

L1b05e8:	; 801B05E8
801B05E8	jal    func1b19ac [$801b19ac]
801B05EC	ori    s1, zero, $0110
801B05F0	jal    battle_update_unit_mask [$800a4540]
801B05F4	nop
801B05F8	jal    func1b2308 [$801b2308]
801B05FC	nop
801B0600	jal    battle_update_unit_mask [$800a4540]
801B0604	nop

loop1b0608:	; 801B0608
801B0608	jal    func14ba8 [$80014ba8]
801B060C	ori    a0, zero, $0040
801B0610	andi   v0, v0, $00ff
801B0614	addiu  v0, v0, $0080
801B0618	sll    v0, v0, $08
801B061C	lui    at, $800f
801B0620	addu   at, at, s1
801B0624	sh     v0, $5bbc(at)
801B0628	jal    funcb108c [$800b108c]
801B062C	addu   a0, s0, zero
801B0630	addiu  s0, s0, $0001
801B0634	slti   v0, s0, $000a
801B0638	bne    v0, zero, loop1b0608 [$801b0608]
801B063C	addiu  s1, s1, $0044
801B0640	lw     ra, $0028(sp)
801B0644	lw     s5, $0024(sp)
801B0648	lw     s4, $0020(sp)
801B064C	lw     s3, $001c(sp)
801B0650	lw     s2, $0018(sp)
801B0654	lw     s1, $0014(sp)

L1b0658:	; 801B0658
801B0658	lw     s0, $0010(sp)
801B065C	addiu  sp, sp, $0030
801B0660	jr     ra 
801B0664	nop



////////////////////////////////////////////////////
// battleinit_init_units_time_value
801B0668-801B0858
////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////
// func1b085c
801B085C-801B08BC
///////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// initbattle_init_player
801B08C0-801B0F04
//////////////////////////////////////////////////////////////////////



func1b0f08:	; 801B0F08
801B0F08	addiu  sp, sp, $ffc8 (=-$38)
801B0F0C	sw     s4, $0020(sp)

L1b0f10:	; 801B0F10
801B0F10	addu   s4, zero, zero
801B0F14	sw     fp, $0030(sp)
801B0F18	lui    fp, $800f
801B0F1C	addiu  fp, fp, $5bb8
801B0F20	sw     s3, $001c(sp)
801B0F24	addiu  s3, fp, $0344
801B0F28	sw     s7, $002c(sp)
801B0F2C	addu   s7, zero, zero
801B0F30	sw     s6, $0028(sp)
801B0F34	addu   s6, zero, zero
801B0F38	sw     s5, $0024(sp)
801B0F3C	addu   s5, zero, zero
801B0F40	sw     s2, $0018(sp)
801B0F44	addu   s2, fp, zero
801B0F48	sw     ra, $0034(sp)
801B0F4C	sw     s1, $0014(sp)

L1b0f50:	; 801B0F50
801B0F50	sw     s0, $0010(sp)

L1b0f54:	; 801B0F54
801B0F54	addiu  v0, fp, $02a8
801B0F58	addu   a1, s5, v0
801B0F5C	lui    v0, $800a
801B0F60	addiu  v0, v0, $d84c (=-$27b4)
801B0F64	addu   s0, s6, v0
801B0F68	lui    v0, $8010
801B0F6C	addiu  v0, v0, $83e0 (=-$7c20)
801B0F70	addu   a2, s7, v0

L1b0f74:	; 801B0F74
801B0F74	lui    at, $800a
801B0F78	addu   at, at, s4
801B0F7C	lbu    a3, $cbdc(at)
801B0F80	ori    v0, zero, $00ff
801B0F84	beq    a3, v0, L1b10cc [$801b10cc]
801B0F88	nop
801B0F8C	addu   a0, zero, zero
801B0F90	addu   v1, zero, zero

loop1b0f94:	; 801B0F94
801B0F94	lui    v0, $800a
801B0F98	addiu  v0, v0, $c738 (=-$38c8)
801B0F9C	addu   s1, v1, v0
801B0FA0	lbu    v0, $0000(s1)
801B0FA4	nop
801B0FA8	bne    v0, a3, L1b10c0 [$801b10c0]
801B0FAC	addiu  a0, a0, $0001
801B0FB0	lbu    v0, $0001(s1)
801B0FB4	nop

L1b0fb8:	; 801B0FB8
801B0FB8	sb     v0, $0009(a2)
801B0FBC	lhu    v0, $002c(s1)
801B0FC0	nop
801B0FC4	sw     v0, $002c(a2)
801B0FC8	lhu    v0, $0030(s1)
801B0FCC	lw     v1, $002c(a2)
801B0FD0	sh     v0, $0028(a2)
801B0FD4	sh     v1, $003c(s2)
801B0FD8	lhu    v0, $0028(a2)
801B0FDC	addu   a0, s0, zero
801B0FE0	jal    func1b18f8 [$801b18f8]
801B0FE4	sh     v0, $003e(s2)
801B0FE8	lw     v0, $0048(s0)
801B0FEC	nop
801B0FF0	sw     v0, $0034(s2)
801B0FF4	lhu    v0, $0418(s0)
801B0FF8	lhu    v1, $003c(s0)
801B0FFC	nop
801B1000	or     v0, v0, v1
801B1004	sh     v0, $000e(s3)
801B1008	lw     v0, $0044(s0)
801B100C	nop
801B1010	sw     v0, $0014(s3)
801B1014	lbu    v0, $0410(s0)
801B1018	nop
801B101C	sb     v0, $0003(s3)
801B1020	lbu    v0, $0408(s0)
801B1024	nop
801B1028	sb     v0, $0000(s3)
801B102C	lbu    v0, $0029(s2)
801B1030	nop
801B1034	andi   v0, v0, $00fd
801B1038	sb     v0, $0029(s2)
801B103C	lbu    v0, $0023(s0)
801B1040	nop
801B1044	andi   v0, v0, $0004
801B1048	beq    v0, zero, L1b1060 [$801b1060]
801B104C	nop
801B1050	lbu    v0, $0000(s3)
801B1054	nop
801B1058	andi   v0, v0, $00df
801B105C	sb     v0, $0000(s3)

L1b1060:	; 801B1060
801B1060	lbu    v0, $0000(s3)
801B1064	nop
801B1068	andi   v0, v0, $0020
801B106C	bne    v0, zero, L1b1084 [$801b1084]
801B1070	nop
801B1074	lbu    v0, $0029(s2)
801B1078	nop
801B107C	ori    v0, v0, $0002
801B1080	sb     v0, $0029(s2)

L1b1084:	; 801B1084
801B1084	lbu    a1, $001e(s1)
801B1088	jal    func1b1598 [$801b1598]
801B108C	addu   a0, s4, zero
801B1090	jal    func1b11bc [$801b11bc]
801B1094	addu   a0, s4, zero
801B1098	jal    funca4ba4 [$800a4ba4]
801B109C	addu   a0, s4, zero
801B10A0	jal    func1b1734 [$801b1734]
801B10A4	addu   a0, s4, zero
801B10A8	bne    v0, zero, L1b10cc [$801b10cc]
801B10AC	nop
801B10B0	jal    funcb108c [$800b108c]
801B10B4	addu   a0, s4, zero

L1b10b8:	; 801B10B8
801B10B8	j      L1b10d0 [$801b10d0]

L1b10bc:	; 801B10BC
801B10BC	addiu  s3, s3, $0018

L1b10c0:	; 801B10C0
801B10C0	slti   v0, a0, $0009
801B10C4	bne    v0, zero, loop1b0f94 [$801b0f94]
801B10C8	addiu  v1, v1, $0084

L1b10cc:	; 801B10CC
801B10CC	addiu  s3, s3, $0018

L1b10d0:	; 801B10D0
801B10D0	addiu  s7, s7, $0068
801B10D4	addiu  s6, s6, $0440
801B10D8	addiu  s5, s5, $0034
801B10DC	addiu  s4, s4, $0001
801B10E0	slti   v0, s4, $0003
801B10E4	bne    v0, zero, L1b0f54 [$801b0f54]
801B10E8	addiu  s2, s2, $0044
801B10EC	lw     ra, $0034(sp)
801B10F0	lw     fp, $0030(sp)

L1b10f4:	; 801B10F4
801B10F4	lw     s7, $002c(sp)
801B10F8	lw     s6, $0028(sp)
801B10FC	lw     s5, $0024(sp)
801B1100	lw     s4, $0020(sp)
801B1104	lw     s3, $001c(sp)
801B1108	lw     s2, $0018(sp)
801B110C	lw     s1, $0014(sp)
801B1110	lw     s0, $0010(sp)
801B1114	addiu  sp, sp, $0038
801B1118	jr     ra 
801B111C	nop



/////////////////////////////////////////////////////////
// func1b1120
801B1120-801B11B8
/////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// func1b11bc
801B11BC-801B1378
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// func1b137c
801B137C-801B13D8
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// func1b13dc
801B13DC-801B14E4
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// func1b14e8
801B14E8-801B152C
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// func1b1530
801B1530-801B1594
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// func1b1598
801B1598-801B1730
//////////////////////////////////////////////////////////////////////



func1b1734:	; 801B1734
801B1734	addiu  sp, sp, $ffd8 (=-$28)
801B1738	sw     s1, $0014(sp)
801B173C	addu   s1, a0, zero
801B1740	lui    a0, $ffdf
801B1744	ori    a0, a0, $ffff
801B1748	sll    v1, s1, $04
801B174C	addu   v1, v1, s1
801B1750	sll    v1, v1, $02
801B1754	sll    v0, s1, $01
801B1758	addu   v0, v0, s1
801B175C	sll    v0, v0, $02
801B1760	addu   v0, v0, s1
801B1764	sll    a1, v0, $03
801B1768	sw     ra, $0024(sp)
801B176C	sw     s4, $0020(sp)
801B1770	sw     s3, $001c(sp)
801B1774	sw     s2, $0018(sp)
801B1778	sw     s0, $0010(sp)
801B177C	lui    at, $8010
801B1780	addu   at, at, a1
801B1784	lw     v0, $83e0(at)

L1b1788:	; 801B1788
801B1788	lui    at, $800f
801B178C	addu   at, at, v1
801B1790	lw     s3, $5bec(at)
801B1794	and    v0, v0, a0
801B1798	lui    at, $8010
801B179C	addu   at, at, a1
801B17A0	sw     v0, $83e0(at)
801B17A4	lui    at, $800f
801B17A8	addu   at, at, v1
801B17AC	lbu    v0, $5be1(at)
801B17B0	nop
801B17B4	andi   v0, v0, $0008
801B17B8	beq    v0, zero, L1b17c4 [$801b17c4]
801B17BC	addu   s4, zero, zero
801B17C0	ori    s3, s3, $0800

L1b17c4:	; 801B17C4
801B17C4	lui    v0, $8010
801B17C8	lbu    v0, $9da0(v0)
801B17CC	nop
801B17D0	andi   v0, v0, $0010
801B17D4	beq    v0, zero, L1b1844 [$801b1844]
801B17D8	addu   s0, zero, zero

L1b17dc:	; 801B17DC
801B17DC	lui    at, $8010
801B17E0	addu   at, at, a1
801B17E4	lw     v1, $8410(at)
801B17E8	lui    at, $8010
801B17EC	addu   at, at, a1
801B17F0	lw     v0, $840c(at)
801B17F4	lui    at, $8010
801B17F8	addu   at, at, a1
801B17FC	lw     a0, $8410(at)
801B1800	srl    v1, v1, $01
801B1804	addu   v0, v0, v1
801B1808	lui    at, $8010
801B180C	addu   at, at, a1
801B1810	sw     v0, $840c(at)
801B1814	sltu   v0, a0, v0
801B1818	beq    v0, zero, L1b182c [$801b182c]
801B181C	nop
801B1820	lui    at, $8010
801B1824	addu   at, at, a1
801B1828	sw     a0, $840c(at)

L1b182c:	; 801B182C
801B182C	ori    a0, zero, $0002
801B1830	addu   a1, s1, zero
801B1834	ori    a2, zero, $0017
801B1838	jal    funca7254 [$800a7254]
801B183C	addu   a3, zero, zero
801B1840	addu   s0, zero, zero

L1b1844:	; 801B1844
801B1844	sll    v0, s1, $01
801B1848	addu   v0, v0, s1
801B184C	sll    v0, v0, $02

L1b1850:	; 801B1850
801B1850	addu   v0, v0, s1
801B1854	sll    s2, v0, $03

loop1b1858:	; 801B1858
801B1858	lui    v0, $8010
801B185C	lbu    v0, $9da0(v0)
801B1860	nop
801B1864	srav   v0, s0, v0
801B1868	andi   v0, v0, $0001
801B186C	beq    v0, zero, L1b18c4 [$801b18c4]
801B1870	ori    a0, zero, $0002
801B1874	addu   a1, s1, zero
801B1878	ori    a2, zero, $0017
801B187C	sll    v0, s0, $02
801B1880	nor    t0, zero, s3
801B1884	lui    at, $801b
801B1888	addu   at, at, v0
801B188C	lw     a3, $002c(at)
801B1890	lui    at, $801b
801B1894	addu   at, at, v0
801B1898	lw     v0, $001c(at)
801B189C	lui    at, $8010
801B18A0	addu   at, at, s2
801B18A4	lw     v1, $83e0(at)
801B18A8	and    v0, v0, t0
801B18AC	or     v1, v1, v0
801B18B0	lui    at, $8010
801B18B4	addu   at, at, s2
801B18B8	sw     v1, $83e0(at)
801B18BC	jal    funca7254 [$800a7254]
801B18C0	ori    s4, zero, $0001

L1b18c4:	; 801B18C4
801B18C4	addiu  s0, s0, $0001
801B18C8	slti   v0, s0, $0004
801B18CC	bne    v0, zero, loop1b1858 [$801b1858]
801B18D0	addu   v0, s4, zero
801B18D4	lw     ra, $0024(sp)
801B18D8	lw     s4, $0020(sp)
801B18DC	lw     s3, $001c(sp)
801B18E0	lw     s2, $0018(sp)
801B18E4	lw     s1, $0014(sp)
801B18E8	lw     s0, $0010(sp)
801B18EC	addiu  sp, sp, $0028
801B18F0	jr     ra 
801B18F4	nop



//////////////////////////////////////////////////////////////////////
// func1b18f8
801B18F8-801B19A8
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// func1b19ac
801B19AC-801B1CAC
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// initbattle_init_item
801B1CB0801B1E08
//////////////////////////////////////////////////////////////////////



func1b1e0c:	; 801B1E0C
801B1E0C	addiu  sp, sp, $ffd0 (=-$30)
801B1E10	ori    t3, zero, $0002
801B1E14	lui    v0, $800f
801B1E18	addiu  v0, v0, $7dd6
801B1E1C	sw     fp, $0028(sp)
801B1E20	sw     s7, $0024(sp)
801B1E24	sw     s6, $0020(sp)

L1b1e28:	; 801B1E28
801B1E28	sw     s5, $001c(sp)
801B1E2C	sw     s4, $0018(sp)
801B1E30	sw     s3, $0014(sp)
801B1E34	sw     s2, $0010(sp)
801B1E38	sw     s1, $000c(sp)
801B1E3C	sw     s0, $0008(sp)

L1b1e40:	; 801B1E40
801B1E40	lui    at, $8010
801B1E44	sh     zero, $83be(at)

loop1b1e48:	; 801B1E48
801B1E48	sb     zero, $0000(v0)
801B1E4C	addiu  t3, t3, $ffff (=-$1)
801B1E50	bgez   t3, loop1b1e48 [$801b1e48]
801B1E54	addiu  v0, v0, $ffff (=-$1)
801B1E58	addu   t3, zero, zero
801B1E5C	lui    v1, $8010
801B1E60	addiu  v1, v1, $89f0 (=-$7610)

loop1b1e64:	; 801B1E64
801B1E64	ori    a2, zero, $001f
801B1E68	addiu  v0, v1, $007c

loop1b1e6c:	; 801B1E6C
801B1E6C	sw     zero, $0000(v0)
801B1E70	addiu  a2, a2, $ffff (=-$1)
801B1E74	bgez   a2, loop1b1e6c [$801b1e6c]
801B1E78	addiu  v0, v0, $fffc (=-$4)
801B1E7C	addiu  t3, t3, $0001
801B1E80	slti   v0, t3, $0006
801B1E84	bne    v0, zero, loop1b1e64 [$801b1e64]
801B1E88	addiu  v1, v1, $0080
801B1E8C	addu   t3, zero, zero
801B1E90	ori    t7, zero, $00ff
801B1E94	lui    fp, $800f
801B1E98	addiu  fp, fp, $64ec
801B1E9C	lui    s6, $8016
801B1EA0	addiu  s6, s6, $6f78
801B1EA4	ori    s5, zero, $0003
801B1EA8	addu   s0, zero, zero
801B1EAC	ori    s4, zero, $0004
801B1EB0	lui    s7, $8016
801B1EB4	addiu  s7, s7, $360c
801B1EB8	addiu  t9, s7, $004c
801B1EBC	addu   t8, zero, zero
801B1EC0	ori    s3, zero, $0020
801B1EC4	addu   s2, zero, zero
801B1EC8	addu   s1, zero, zero

L1b1ecc:	; 801B1ECC
801B1ECC	ori    a2, zero, $000f
801B1ED0	lui    v0, $800f
801B1ED4	addiu  v0, v0, $5cc8
801B1ED8	addu   t4, s1, v0
801B1EDC	addiu  v1, t4, $000f
801B1EE0	lui    v0, $8010
801B1EE4	addiu  v0, v0, $8580 (=-$7a80)
801B1EE8	addu   a1, s2, v0
801B1EEC	lhu    a0, $0000(t9)
801B1EF0	addiu  v0, zero, $ffff (=-$1)
801B1EF4	sb     v0, $0008(a1)
801B1EF8	ori    v0, zero, $ffff
801B1EFC	sh     v0, $0024(a1)
801B1F00	sw     zero, $0004(a1)
801B1F04	sw     zero, $0000(a1)
801B1F08	sb     t7, $004f(a1)
801B1F0C	lui    at, $800f
801B1F10	addu   at, at, s3
801B1F14	sb     t7, $6b34(at)

loop1b1f18:	; 801B1F18
801B1F18	sb     zero, $0010(v1)
801B1F1C	addiu  a2, a2, $ffff (=-$1)
801B1F20	bgez   a2, loop1b1f18 [$801b1f18]
801B1F24	addiu  v1, v1, $ffff (=-$1)
801B1F28	ori    a2, zero, $0007
801B1F2C	addiu  v0, t4, $0007

loop1b1f30:	; 801B1F30
801B1F30	sb     zero, $0020(v0)
801B1F34	addiu  a2, a2, $ffff (=-$1)
801B1F38	bgez   a2, loop1b1f30 [$801b1f30]
801B1F3C	addiu  v0, v0, $ffff (=-$1)
801B1F40	sll    v0, a0, $10
801B1F44	sra    v1, v0, $10
801B1F48	addiu  v0, zero, $ffff (=-$1)
801B1F4C	beq    v1, v0, L1b2248 [$801b2248]
801B1F50	nop
801B1F54	sh     a0, $0024(a1)
801B1F58	addu   a2, zero, zero

L1b1f5c:	; 801B1F5C
801B1F5C	addu   a0, v1, zero
801B1F60	addu   v1, s7, zero

loop1b1f64:	; 801B1F64
801B1F64	lh     v0, $0000(v1)
801B1F68	nop
801B1F6C	beq    v0, a0, L1b1f84 [$801b1f84]
801B1F70	nop
801B1F74	addiu  a2, a2, $0001
801B1F78	slti   v0, a2, $0003
801B1F7C	bne    v0, zero, loop1b1f64 [$801b1f64]
801B1F80	addiu  v1, v1, $0002

L1b1f84:	; 801B1F84
801B1F84	addu   a0, a2, zero
801B1F88	sll    v1, a2, $10
801B1F8C	lui    at, $800f
801B1F90	addu   at, at, a2
801B1F94	lbu    v0, $7dd4(at)
801B1F98	sra    v1, v1, $10
801B1F9C	addiu  v0, v0, $0001
801B1FA0	lui    at, $800f

L1b1fa4:	; 801B1FA4
801B1FA4	addu   at, at, a2
801B1FA8	sb     v0, $7dd4(at)
801B1FAC	sll    v0, v1, $01
801B1FB0	addu   v0, v0, v1
801B1FB4	sll    v0, v0, $03
801B1FB8	subu   v0, v0, v1
801B1FBC	sll    v0, v0, $03
801B1FC0	lui    v1, $800f
801B1FC4	addiu  v1, v1, $5f44
801B1FC8	addu   a3, v0, v1
801B1FCC	sh     a0, $0000(t9)
801B1FD0	sb     a0, $0008(a1)
801B1FD4	lw     v0, $00a4(a3)
801B1FD8	nop
801B1FDC	sw     v0, $0030(a1)
801B1FE0	sw     v0, $002c(a1)
801B1FE4	lhu    v0, $009c(a3)
801B1FE8	nop
801B1FEC	sh     v0, $002a(a1)
801B1FF0	sh     v0, $0028(a1)
801B1FF4	lbu    v0, $0024(a3)
801B1FF8	nop
801B1FFC	sb     v0, $000d(a1)
801B2000	lbu    v0, $0026(a3)
801B2004	nop

L1b2008:	; 801B2008
801B2008	sb     v0, $000e(a1)
801B200C	lbu    v0, $0025(a3)
801B2010	nop
801B2014	sll    v0, v0, $01
801B2018	sh     v0, $0020(a1)
801B201C	lbu    v0, $0027(a3)
801B2020	nop
801B2024	sll    v0, v0, $01
801B2028	sh     v0, $0022(a1)
801B202C	lbu    v0, $0023(a3)
801B2030	nop
801B2034	sb     v0, $000f(a1)
801B2038	lbu    v0, $0021(a3)
801B203C	nop
801B2040	sb     v0, $0014(a1)
801B2044	lbu    v0, $0022(a3)
801B2048	nop
801B204C	sb     v0, $0015(a1)
801B2050	lbu    v0, $0020(a3)
801B2054	nop
801B2058	sb     v0, $0009(a1)
801B205C	lbu    v0, $00a2(a3)
801B2060	nop
801B2064	sb     v0, $0012(a1)
801B2068	lw     v0, $00ac(a3)
801B206C	nop
801B2070	sw     v0, $0058(a1)
801B2074	lw     v1, $00a8(a3)
801B2078	ori    v0, zero, $0001
801B207C	sb     v0, $0011(a1)
801B2080	sw     v1, $005c(a1)
801B2084	sb     v0, $004c(a1)
801B2088	ori    v0, zero, $0002
801B208C	sb     v0, $0056(a1)
801B2090	ori    v0, zero, $ffff
801B2094	sb     zero, $0010(a1)

L1b2098:	; 801B2098
801B2098	sw     zero, $0000(a1)
801B209C	sw     zero, $0044(a1)
801B20A0	sh     zero, $0050(a1)
801B20A4	sh     v0, $0052(a1)
801B20A8	lui    at, $8016
801B20AC	addu   at, at, t8
801B20B0	lw     v0, $3664(at)
801B20B4	addu   a2, zero, zero
801B20B8	andi   v0, v0, $001f
801B20BC	sw     v0, $0004(a1)
801B20C0	lui    at, $8016
801B20C4	addu   at, at, t8
801B20C8	lhu    v0, $3660(at)
801B20CC	nop
801B20D0	sb     v0, $004e(a1)
801B20D4	sw     a3, $0038(t4)
801B20D8	sb     t7, $000d(t4)
801B20DC	sb     t7, $000c(t4)
801B20E0	sb     t7, $000f(t4)
801B20E4	lw     v0, $00b0(a3)
801B20E8	lui    a0, $8010
801B20EC	addiu  a0, a0, $83be (=-$7c42)
801B20F0	nor    v0, zero, v0

L1b20f4:	; 801B20F4
801B20F4	sw     v0, $0034(t4)
801B20F8	ori    v0, zero, $0001
801B20FC	lhu    v1, $0000(a0)
801B2100	sllv   v0, s4, v0
801B2104	or     v1, v1, v0
801B2108	sh     v1, $0000(a0)
801B210C	blez   t3, L1b2154 [$801b2154]
801B2110	sb     zero, $000c(a1)
801B2114	lhu    a0, $0024(a1)
801B2118	ori    v1, zero, $01a0

loop1b211c:	; 801B211C
801B211C	lui    at, $8010
801B2120	addu   at, at, v1
801B2124	lhu    v0, $8404(at)
801B2128	nop
801B212C	bne    v0, a0, L1b2144 [$801b2144]
801B2130	nop
801B2134	lbu    v0, $000c(a1)
801B2138	nop
801B213C	addiu  v0, v0, $0001
801B2140	sb     v0, $000c(a1)

L1b2144:	; 801B2144
801B2144	addiu  a2, a2, $0001
801B2148	slt    v0, a2, t3
801B214C	bne    v0, zero, loop1b211c [$801b211c]
801B2150	addiu  v1, v1, $0068

L1b2154:	; 801B2154
801B2154	ori    t6, zero, $0003
801B2158	addu   a2, zero, zero
801B215C	addu   t5, s0, zero
801B2160	addu   t2, a3, zero
801B2164	addu   t1, zero, zero

loop1b2168:	; 801B2168
801B2168	addu   v0, t1, s6
801B216C	addu   t0, t5, v0
801B2170	lhu    v1, $0094(t2)
801B2174	ori    v0, zero, $ffff
801B2178	sb     t7, $0000(t0)
801B217C	sb     zero, $0001(t0)
801B2180	sb     zero, $0002(t0)
801B2184	andi   v1, v1, $ffff
801B2188	beq    v1, v0, L1b21ec [$801b21ec]
801B218C	sb     s5, $0003(t0)
801B2190	addu   a1, zero, zero
801B2194	addu   a3, zero, zero
801B2198	addu   a0, fp, zero

loop1b219c:	; 801B219C
801B219C	lhu    v0, $0000(a0)

L1b21a0:	; 801B21A0
801B21A0	nop
801B21A4	bne    v0, v1, L1b21d8 [$801b21d8]
801B21A8	nop
801B21AC	lui    at, $800f
801B21B0	addu   at, at, a3
801B21B4	lbu    v0, $6178(at)
801B21B8	nop

L1b21bc:	; 801B21BC
801B21BC	beq    v0, zero, L1b21c8 [$801b21c8]
801B21C0	nop
801B21C4	xori   v0, v0, $0002

L1b21c8:	; 801B21C8
801B21C8	sb     a1, $0000(t0)
801B21CC	sb     v0, $0002(t0)
801B21D0	j      L1b21ec [$801b21ec]
801B21D4	sb     zero, $0003(t0)

L1b21d8:	; 801B21D8
801B21D8	addiu  a3, a3, $001c
801B21DC	addiu  a1, a1, $0001
801B21E0	slti   v0, a1, $0020
801B21E4	bne    v0, zero, loop1b219c [$801b219c]
801B21E8	addiu  a0, a0, $0002

L1b21ec:	; 801B21EC
801B21EC	addiu  t2, t2, $0002
801B21F0	addiu  a2, a2, $0001
801B21F4	slt    v0, a2, t6
801B21F8	bne    v0, zero, loop1b2168 [$801b2168]
801B21FC	addiu  t1, t1, $0006
801B2200	addu   a2, t6, zero
801B2204	slti   v0, a2, $0010
801B2208	beq    v0, zero, L1b2244 [$801b2244]

L1b220c:	; 801B220C
801B220C	sll    v0, a2, $01
801B2210	addu   a0, s0, zero
801B2214	addu   v0, v0, a2
801B2218	sll    v0, v0, $01
801B221C	addu   v1, v0, s6

loop1b2220:	; 801B2220
801B2220	addu   v0, a0, v1
801B2224	addiu  a2, a2, $0001
801B2228	sb     t7, $0000(v0)
801B222C	sb     zero, $0001(v0)
801B2230	sb     zero, $0002(v0)
801B2234	sb     s5, $0003(v0)
801B2238	slti   v0, a2, $0010
801B223C	bne    v0, zero, loop1b2220 [$801b2220]
801B2240	addiu  v1, v1, $0006

L1b2244:	; 801B2244
801B2244	sb     zero, $0029(t4)

L1b2248:	; 801B2248
801B2248	addiu  s0, s0, $0060

L1b224c:	; 801B224C
801B224C	addiu  s4, s4, $0001
801B2250	addiu  t9, t9, $0010
801B2254	addiu  t8, t8, $0010
801B2258	addiu  s3, s3, $0008
801B225C	addiu  s2, s2, $0068
801B2260	addiu  t3, t3, $0001
801B2264	slti   v0, t3, $0006
801B2268	bne    v0, zero, L1b1ecc [$801b1ecc]
801B226C	addiu  s1, s1, $0044
801B2270	addu   t3, zero, zero
801B2274	ori    a1, zero, $01a0
801B2278	ori    a0, zero, $0110
801B227C	ori    v1, zero, $0040

loop1b2280:	; 801B2280
801B2280	lui    at, $8016
801B2284	addu   at, at, v1
801B2288	lh     v0, $3618(at)
801B228C	lui    at, $800f
801B2290	addu   at, at, v0
801B2294	lbu    v0, $7dd4(at)
801B2298	nop
801B229C	sltiu  v0, v0, $0002
801B22A0	bne    v0, zero, L1b22c0 [$801b22c0]
801B22A4	nop
801B22A8	lui    at, $8010
801B22AC	addu   at, at, a1
801B22B0	lbu    v0, $83ec(at)
801B22B4	lui    at, $800f
801B22B8	addu   at, at, a0
801B22BC	sb     v0, $5bc7(at)

L1b22c0:	; 801B22C0
801B22C0	addiu  a1, a1, $0068
801B22C4	addiu  a0, a0, $0044
801B22C8	addiu  t3, t3, $0001
801B22CC	slti   v0, t3, $0006
801B22D0	bne    v0, zero, loop1b2280 [$801b2280]
801B22D4	addiu  v1, v1, $0010
801B22D8	lw     fp, $0028(sp)
801B22DC	lw     s7, $0024(sp)
801B22E0	lw     s6, $0020(sp)
801B22E4	lw     s5, $001c(sp)
801B22E8	lw     s4, $0018(sp)
801B22EC	lw     s3, $0014(sp)
801B22F0	lw     s2, $0010(sp)
801B22F4	lw     s1, $000c(sp)
801B22F8	lw     s0, $0008(sp)
801B22FC	addiu  sp, sp, $0030
801B2300	jr     ra 
801B2304	nop



/////////////////////////////////////////////////////////
// func1b2308
801B2308-801B23DC
/////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
// initbattle_load_enemy_from_scene
801B23E0-801B2734
//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
// initbattle_get_id_of_scene_file_with_battle_id
801B2738-801B276C
//////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////
// initbattle_calculate_stat_add25_percent
801B2770-801B27B0
//////////////////////////////////////////////////////////////