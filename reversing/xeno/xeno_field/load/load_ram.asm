////////////////////////////////
// func1dc22c
801DC22C-801DC2CC
////////////////////////////////



////////////////////////////////
// load_init_skeleton_data_create_packets
801DC2D0-801DC5BC
////////////////////////////////



func1dc5c0:	; 801DC5C0
801DC5C0	addiu  sp, sp, $ffc8 (=-$38)
801DC5C4	sw     s2, $0018(sp)
801DC5C8	addu   s2, a0, zero
801DC5CC	sw     s4, $0020(sp)
801DC5D0	addu   s4, s2, zero
801DC5D4	sw     ra, $0030(sp)
801DC5D8	sw     s7, $002c(sp)
801DC5DC	sw     s6, $0028(sp)
801DC5E0	sw     s5, $0024(sp)
801DC5E4	sw     s3, $001c(sp)
801DC5E8	sw     s1, $0014(sp)
801DC5EC	sw     s0, $0010(sp)
801DC5F0	lw     v0, $005c(s4)

L1dc5f4:	; 801DC5F4
801DC5F4	lw     v1, $0060(s4)
801DC5F8	lw     a0, $0064(s4)
801DC5FC	lhu    s6, $000a(s4)
801DC600	addu   s1, a1, zero
801DC604	sw     v0, $0040(s4)
801DC608	lbu    v0, $0006(s4)
801DC60C	lui    s0, $1f80
801DC610	sw     v1, $0044(s4)
801DC614	beq    v0, zero, L1dc630 [$801dc630]
801DC618	sw     a0, $0048(s4)
801DC61C	addiu  a0, s4, $0054
801DC620	jal    func4a7d4 [$8004a7d4]
801DC624	addiu  a1, s4, $002c
801DC628	j      L1dc63c [$801dc63c]
801DC62C	nop

L1dc630:	; 801DC630
801DC630	addiu  a0, s4, $0054
801DC634	jal    func3f5e0 [$8003f5e0]
801DC638	addiu  a1, s4, $002c

L1dc63c:	; 801DC63C
801DC63C	lh     v0, $004c(s2)
801DC640	nop
801DC644	mult   s1, v0
801DC648	sh     zero, $0002(s0)
801DC64C	sh     zero, $0004(s0)
801DC650	sh     zero, $0006(s0)
801DC654	mflo   v0
801DC658	sra    v0, v0, $0c

L1dc65c:	; 801DC65C
801DC65C	sh     v0, $0000(s0)
801DC660	lh     v0, $004e(s2)
801DC664	nop
801DC668	mult   s1, v0
801DC66C	sh     zero, $000a(s0)
801DC670	sh     zero, $000c(s0)
801DC674	sh     zero, $000e(s0)
801DC678	mflo   v0
801DC67C	sra    v0, v0, $0c
801DC680	sh     v0, $0008(s0)
801DC684	lh     v0, $0050(s2)
801DC688	nop
801DC68C	mult   s1, v0
801DC690	addiu  s5, s2, $002c
801DC694	addu   a0, s5, zero
801DC698	addu   a1, s0, zero
801DC69C	addiu  s3, s2, $000c
801DC6A0	addu   a2, s3, zero

loop1dc6a4:	; 801DC6A4
801DC6A4	mflo   v0

L1dc6a8:	; 801DC6A8
801DC6A8	sra    v0, v0, $0c
801DC6AC	jal    func490b4 [$800490b4]
801DC6B0	sh     v0, $0010(a1)
801DC6B4	lw     v0, $0040(s2)
801DC6B8	lw     v1, $0044(s2)
801DC6BC	lw     a0, $0048(s2)
801DC6C0	ori    s1, zero, $0001
801DC6C4	sw     v0, $0020(s2)
801DC6C8	sltu   v0, s1, s6
801DC6CC	sw     v1, $0024(s2)
801DC6D0	beq    v0, zero, L1dc7f8 [$801dc7f8]
801DC6D4	sw     a0, $0028(s2)
801DC6D8	ori    s7, zero, $0001

L1dc6dc:	; 801DC6DC
801DC6DC	addu   s0, s5, zero
801DC6E0	addiu  s5, s2, $0054
801DC6E4	addiu  s0, s0, $007c

loop1dc6e8:	; 801DC6E8
801DC6E8	addiu  s3, s3, $007c
801DC6EC	addiu  s5, s5, $007c
801DC6F0	lbu    v0, $ffd9(s0)
801DC6F4	nop
801DC6F8	beq    v0, zero, L1dc72c [$801dc72c]
801DC6FC	addiu  s2, s2, $007c
801DC700	lbu    v0, $ffda(s0)
801DC704	nop
801DC708	beq    v0, zero, L1dc720 [$801dc720]
801DC70C	addu   a0, s5, zero
801DC710	jal    func4a7d4 [$8004a7d4]
801DC714	addu   a1, s3, zero
801DC718	j      L1dc72c [$801dc72c]
801DC71C	sb     zero, $ffd9(s0)

L1dc720:	; 801DC720
801DC720	jal    func3f5e0 [$8003f5e0]

loop1dc724:	; 801DC724
801DC724	addu   a1, s3, zero

L1dc728:	; 801DC728
801DC728	sb     zero, $ffd9(s0)

L1dc72c:	; 801DC72C
801DC72C	lw     v0, $0000(s2)
801DC730	nop
801DC734	beq    v0, zero, L1dc750 [$801dc750]
801DC738	nop
801DC73C	lbu    v0, $0004(v0)
801DC740	nop
801DC744	bne    v0, s7, L1dc750 [$801dc750]
801DC748	nop
801DC74C	sb     s7, $ffd8(s0)

L1dc750:	; 801DC750
801DC750	lbu    v0, $ffd8(s0)
801DC754	nop
801DC758	beq    v0, zero, L1dc7dc [$801dc7dc]

L1dc75c:	; 801DC75C
801DC75C	nop
801DC760	lw     v0, $0030(s0)
801DC764	lw     v1, $0034(s0)
801DC768	lw     a0, $0038(s0)
801DC76C	sw     v0, $fff4(s0)
801DC770	sw     v1, $fff8(s0)
801DC774	sw     a0, $fffc(s0)
801DC778	lw     a0, $0000(s2)
801DC77C	nop
801DC780	beq    a0, zero, L1dc79c [$801dc79c]
801DC784	addiu  a0, a0, $002c
801DC788	addu   a1, s3, zero
801DC78C	jal    func491c4 [$800491c4]
801DC790	addu   a2, s0, zero
801DC794	j      L1dc7e0 [$801dc7e0]
801DC798	addiu  s1, s1, $0001

L1dc79c:	; 801DC79C
801DC79C	lw     v0, $ffe0(s0)
801DC7A0	lw     v1, $ffe4(s0)
801DC7A4	lw     a0, $ffe8(s0)
801DC7A8	lw     a1, $ffec(s0)
801DC7AC	sw     v0, $0000(s0)
801DC7B0	sw     v1, $0004(s0)
801DC7B4	sw     a0, $0008(s0)
801DC7B8	sw     a1, $000c(s0)
801DC7BC	lw     v0, $fff0(s0)
801DC7C0	lw     v1, $fff4(s0)
801DC7C4	lw     a0, $fff8(s0)

L1dc7c8:	; 801DC7C8
801DC7C8	lw     a1, $fffc(s0)
801DC7CC	sw     v0, $0010(s0)
801DC7D0	sw     v1, $0014(s0)
801DC7D4	sw     a0, $0018(s0)
801DC7D8	sw     a1, $001c(s0)

L1dc7dc:	; 801DC7DC
801DC7DC	addiu  s1, s1, $0001

L1dc7e0:	; 801DC7E0
801DC7E0	sltu   v0, s1, s6
801DC7E4	bne    v0, zero, loop1dc6e8 [$801dc6e8]
801DC7E8	addiu  s0, s0, $007c
801DC7EC	addiu  s0, s0, $ff84 (=-$7c)
801DC7F0	ori    s1, zero, $0001
801DC7F4	sltu   v0, s1, s6

L1dc7f8:	; 801DC7F8
801DC7F8	beq    v0, zero, L1dc818 [$801dc818]
801DC7FC	addu   v0, s6, zero

loop1dc800:	; 801DC800
801DC800	addiu  s4, s4, $007c
801DC804	addiu  s1, s1, $0001
801DC808	sltu   v0, s1, s6
801DC80C	bne    v0, zero, loop1dc800 [$801dc800]
801DC810	sb     zero, $0004(s4)
801DC814	addu   v0, s6, zero

L1dc818:	; 801DC818
801DC818	lw     ra, $0030(sp)
801DC81C	lw     s7, $002c(sp)
801DC820	lw     s6, $0028(sp)
801DC824	lw     s5, $0024(sp)
801DC828	lw     s4, $0020(sp)
801DC82C	lw     s3, $001c(sp)
801DC830	lw     s2, $0018(sp)
801DC834	lw     s1, $0014(sp)
801DC838	lw     s0, $0010(sp)
801DC83C	addiu  sp, sp, $0038
801DC840	jr     ra 
801DC844	nop


func1dc848:	; 801DC848
801DC848	addiu  sp, sp, $ffc8 (=-$38)
801DC84C	sw     s3, $001c(sp)
801DC850	addu   s3, a0, zero
801DC854	sw     s6, $0028(sp)
801DC858	addu   s6, s3, zero
801DC85C	sw     ra, $0034(sp)
801DC860	sw     fp, $0030(sp)
801DC864	sw     s7, $002c(sp)
801DC868	sw     s5, $0024(sp)
801DC86C	sw     s4, $0020(sp)
801DC870	sw     s2, $0018(sp)
801DC874	sw     s1, $0014(sp)
801DC878	sw     s0, $0010(sp)
801DC87C	lw     v0, $005c(s6)
801DC880	lw     v1, $0060(s6)
801DC884	lw     a0, $0064(s6)
801DC888	lhu    fp, $000a(s6)
801DC88C	addu   s1, a1, zero
801DC890	sw     v0, $0040(s6)
801DC894	lbu    v0, $0006(s6)
801DC898	lui    s0, $1f80
801DC89C	sw     v1, $0044(s6)
801DC8A0	beq    v0, zero, L1dc8bc [$801dc8bc]
801DC8A4	sw     a0, $0048(s6)
801DC8A8	addiu  a0, s6, $0054
801DC8AC	jal    func4a7d4 [$8004a7d4]
801DC8B0	addiu  a1, s6, $002c
801DC8B4	j      L1dc8c8 [$801dc8c8]
801DC8B8	nop

L1dc8bc:	; 801DC8BC
801DC8BC	addiu  a0, s6, $0054
801DC8C0	jal    func3f5e0 [$8003f5e0]
801DC8C4	addiu  a1, s6, $002c

L1dc8c8:	; 801DC8C8
801DC8C8	lh     v0, $004c(s3)
801DC8CC	nop
801DC8D0	mult   s1, v0
801DC8D4	sh     zero, $0002(s0)
801DC8D8	sh     zero, $0004(s0)
801DC8DC	sh     zero, $0006(s0)
801DC8E0	mflo   v0
801DC8E4	sra    v0, v0, $0c
801DC8E8	sh     v0, $0000(s0)
801DC8EC	lh     v0, $004e(s3)
801DC8F0	nop
801DC8F4	mult   s1, v0
801DC8F8	sh     zero, $000a(s0)
801DC8FC	sh     zero, $000c(s0)
801DC900	sh     zero, $000e(s0)
801DC904	mflo   v0
801DC908	sra    v0, v0, $0c
801DC90C	sh     v0, $0008(s0)
801DC910	lh     v0, $0050(s3)
801DC914	nop
801DC918	mult   s1, v0
801DC91C	addiu  s2, s3, $002c
801DC920	addu   a0, s2, zero
801DC924	addu   a1, s0, zero
801DC928	addiu  s1, s3, $000c
801DC92C	addu   a2, s1, zero
801DC930	mflo   v0

L1dc934:	; 801DC934
801DC934	sra    v0, v0, $0c

L1dc938:	; 801DC938
801DC938	jal    func490b4 [$800490b4]
801DC93C	sh     v0, $0010(a1)
801DC940	lw     v0, $0040(s3)
801DC944	lw     v1, $0044(s3)
801DC948	lw     a0, $0048(s3)
801DC94C	ori    s4, zero, $0001
801DC950	sw     v0, $0020(s3)
801DC954	sltu   v0, s4, fp
801DC958	sw     v1, $0024(s3)
801DC95C	beq    v0, zero, L1dcbd8 [$801dcbd8]
801DC960	sw     a0, $0028(s3)
801DC964	lui    s7, $0100
801DC968	addu   s0, s2, zero
801DC96C	addu   s2, s1, zero
801DC970	addiu  s5, s3, $0054
801DC974	addiu  s0, s0, $007c

L1dc978:	; 801DC978
801DC978	addiu  s2, s2, $007c

L1dc97c:	; 801DC97C
801DC97C	addiu  s3, s3, $007c
801DC980	lw     v0, $0000(s3)
801DC984	nop
801DC988	beq    v0, zero, L1dc9c4 [$801dc9c4]
801DC98C	addiu  s5, s5, $007c
801DC990	lbu    v0, $0005(v0)
801DC994	ori    a3, zero, $0001
801DC998	bne    v0, a3, L1dc9a4 [$801dc9a4]

L1dc99c:	; 801DC99C
801DC99C	ori    a3, zero, $0001
801DC9A0	sb     a3, $ffd9(s0)

L1dc9a4:	; 801DC9A4
801DC9A4	lw     v0, $0000(s3)
801DC9A8	nop
801DC9AC	lbu    v0, $0004(v0)
801DC9B0	ori    a3, zero, $0001
801DC9B4	bne    v0, a3, L1dc9c4 [$801dc9c4]
801DC9B8	nop
801DC9BC	ori    a3, zero, $0001
801DC9C0	sb     a3, $ffd8(s0)

L1dc9c4:	; 801DC9C4
801DC9C4	lbu    v0, $ffd9(s0)
801DC9C8	nop
801DC9CC	beq    v0, zero, L1dcb30 [$801dcb30]
801DC9D0	nop
801DC9D4	lbu    v0, $ffda(s0)
801DC9D8	nop
801DC9DC	beq    v0, zero, L1dc9f8 [$801dc9f8]
801DC9E0	lui    s1, $1f80
801DC9E4	addu   a0, s5, zero
801DC9E8	jal    func4a7d4 [$8004a7d4]
801DC9EC	addu   a1, s2, zero
801DC9F0	j      L1dca04 [$801dca04]
801DC9F4	nop

L1dc9f8:	; 801DC9F8
801DC9F8	addu   a0, s5, zero
801DC9FC	jal    func3f5e0 [$8003f5e0]
801DCA00	addu   a1, s2, zero

L1dca04:	; 801DCA04
801DCA04	lhu    v0, $0020(s0)
801DCA08	addu   a0, s2, zero
801DCA0C	sh     zero, $0002(s1)
801DCA10	sh     zero, $0004(s1)
801DCA14	sh     zero, $0006(s1)
801DCA18	sh     v0, $0000(s1)
801DCA1C	lhu    v0, $0022(s0)
801DCA20	addu   a1, s1, zero
801DCA24	sh     zero, $000a(s1)
801DCA28	sh     zero, $000c(s1)
801DCA2C	sh     zero, $000e(s1)

L1dca30:	; 801DCA30
801DCA30	sh     v0, $0008(s1)
801DCA34	lhu    v0, $0024(s0)
801DCA38	addu   a2, s2, zero
801DCA3C	jal    func490b4 [$800490b4]
801DCA40	sh     v0, $0010(s1)
801DCA44	lw     v0, $0000(s3)
801DCA48	nop
801DCA4C	beq    v0, zero, L1dcb30 [$801dcb30]
801DCA50	addu   a0, s1, zero
801DCA54	lh     v0, $004c(v0)
801DCA58	nop
801DCA5C	div    s7, v0
801DCA60	bne    v0, zero, L1dca6c [$801dca6c]
801DCA64	nop
801DCA68	break   $01c00

L1dca6c:	; 801DCA6C
801DCA6C	addiu  at, zero, $ffff (=-$1)
801DCA70	bne    v0, at, L1dca84 [$801dca84]
801DCA74	lui    at, $8000
801DCA78	bne    s7, at, L1dca84 [$801dca84]
801DCA7C	nop
801DCA80	break   $01800

L1dca84:	; 801DCA84
801DCA84	mflo   v0
801DCA88	sh     zero, $0002(s1)

L1dca8c:	; 801DCA8C
801DCA8C	sh     zero, $0004(s1)
801DCA90	sh     zero, $0006(s1)
801DCA94	sh     v0, $0000(s1)
801DCA98	lw     v0, $0000(s3)
801DCA9C	nop
801DCAA0	lh     v0, $004e(v0)
801DCAA4	nop
801DCAA8	div    s7, v0
801DCAAC	bne    v0, zero, L1dcab8 [$801dcab8]
801DCAB0	nop
801DCAB4	break   $01c00

L1dcab8:	; 801DCAB8
801DCAB8	addiu  at, zero, $ffff (=-$1)
801DCABC	bne    v0, at, L1dcad0 [$801dcad0]
801DCAC0	lui    at, $8000
801DCAC4	bne    s7, at, L1dcad0 [$801dcad0]
801DCAC8	nop
801DCACC	break   $01800

L1dcad0:	; 801DCAD0
801DCAD0	mflo   v0
801DCAD4	sh     zero, $000a(s1)
801DCAD8	sh     zero, $000c(s1)
801DCADC	sh     zero, $000e(s1)
801DCAE0	sh     v0, $0008(s1)
801DCAE4	lw     v0, $0000(s3)
801DCAE8	nop
801DCAEC	lh     v0, $0050(v0)
801DCAF0	nop
801DCAF4	div    s7, v0
801DCAF8	bne    v0, zero, L1dcb04 [$801dcb04]
801DCAFC	nop
801DCB00	break   $01c00

L1dcb04:	; 801DCB04
801DCB04	addiu  at, zero, $ffff (=-$1)
801DCB08	bne    v0, at, L1dcb1c [$801dcb1c]
801DCB0C	lui    at, $8000
801DCB10	bne    s7, at, L1dcb1c [$801dcb1c]
801DCB14	nop
801DCB18	break   $01800

L1dcb1c:	; 801DCB1C
801DCB1C	mflo   v0
801DCB20	addu   a1, s2, zero
801DCB24	addu   a2, s2, zero
801DCB28	jal    func490b4 [$800490b4]
801DCB2C	sh     v0, $0010(a0)

L1dcb30:	; 801DCB30
801DCB30	lbu    v0, $ffd8(s0)

L1dcb34:	; 801DCB34
801DCB34	nop
801DCB38	beq    v0, zero, L1dcbbc [$801dcbbc]
801DCB3C	nop
801DCB40	lw     v0, $0030(s0)
801DCB44	lw     v1, $0034(s0)
801DCB48	lw     a0, $0038(s0)
801DCB4C	sw     v0, $fff4(s0)
801DCB50	sw     v1, $fff8(s0)
801DCB54	sw     a0, $fffc(s0)
801DCB58	lw     a0, $0000(s3)
801DCB5C	nop
801DCB60	beq    a0, zero, L1dcb7c [$801dcb7c]
801DCB64	addiu  a0, a0, $002c
801DCB68	addu   a1, s2, zero
801DCB6C	jal    func491c4 [$800491c4]
801DCB70	addu   a2, s0, zero
801DCB74	j      L1dcbc0 [$801dcbc0]
801DCB78	addiu  s4, s4, $0001

L1dcb7c:	; 801DCB7C
801DCB7C	lw     v0, $ffe0(s0)
801DCB80	lw     v1, $ffe4(s0)
801DCB84	lw     a0, $ffe8(s0)
801DCB88	lw     a1, $ffec(s0)
801DCB8C	sw     v0, $0000(s0)
801DCB90	sw     v1, $0004(s0)
801DCB94	sw     a0, $0008(s0)
801DCB98	sw     a1, $000c(s0)
801DCB9C	lw     v0, $fff0(s0)
801DCBA0	lw     v1, $fff4(s0)
801DCBA4	lw     a0, $fff8(s0)
801DCBA8	lw     a1, $fffc(s0)
801DCBAC	sw     v0, $0010(s0)
801DCBB0	sw     v1, $0014(s0)
801DCBB4	sw     a0, $0018(s0)
801DCBB8	sw     a1, $001c(s0)

L1dcbbc:	; 801DCBBC
801DCBBC	addiu  s4, s4, $0001

L1dcbc0:	; 801DCBC0
801DCBC0	sltu   v0, s4, fp
801DCBC4	bne    v0, zero, L1dc978 [$801dc978]
801DCBC8	addiu  s0, s0, $007c
801DCBCC	addiu  s0, s0, $ff84 (=-$7c)
801DCBD0	ori    s4, zero, $0001
801DCBD4	sltu   v0, s4, fp

L1dcbd8:	; 801DCBD8
801DCBD8	beq    v0, zero, L1dcc00 [$801dcc00]
801DCBDC	addu   v0, fp, zero
801DCBE0	addiu  a0, s6, $0004

loop1dcbe4:	; 801DCBE4
801DCBE4	addiu  a0, a0, $007c
801DCBE8	addiu  s4, s4, $0001

L1dcbec:	; 801DCBEC
801DCBEC	sltu   v0, s4, fp
801DCBF0	sb     zero, $0001(a0)
801DCBF4	bne    v0, zero, loop1dcbe4 [$801dcbe4]
801DCBF8	sb     zero, $0000(a0)
801DCBFC	addu   v0, fp, zero

L1dcc00:	; 801DCC00
801DCC00	lw     ra, $0034(sp)

L1dcc04:	; 801DCC04
801DCC04	lw     fp, $0030(sp)
801DCC08	lw     s7, $002c(sp)
801DCC0C	lw     s6, $0028(sp)
801DCC10	lw     s5, $0024(sp)
801DCC14	lw     s4, $0020(sp)
801DCC18	lw     s3, $001c(sp)
801DCC1C	lw     s2, $0018(sp)
801DCC20	lw     s1, $0014(sp)
801DCC24	lw     s0, $0010(sp)
801DCC28	addiu  sp, sp, $0038
801DCC2C	jr     ra 
801DCC30	nop

801DCC34	jr     ra 
801DCC38	nop

801DCC3C	addiu  sp, sp, $ffc8 (=-$38)
801DCC40	sw     s7, $002c(sp)
801DCC44	addu   s7, a0, zero

L1dcc48:	; 801DCC48
801DCC48	sw     s1, $0014(sp)
801DCC4C	addu   s1, a1, zero
801DCC50	sw     s0, $0010(sp)
801DCC54	addu   s0, a2, zero
801DCC58	sw     fp, $0030(sp)
801DCC5C	lui    fp, $1f80
801DCC60	ori    fp, fp, $0020
801DCC64	sw     s6, $0028(sp)
801DCC68	lui    s6, $1f80
801DCC6C	ori    s6, s6, $0040
801DCC70	addu   a0, a3, zero
801DCC74	addiu  a1, s1, $002c
801DCC78	lui    a2, $1f80
801DCC7C	ori    a2, a2, $0020
801DCC80	sw     ra, $0034(sp)

L1dcc84:	; 801DCC84
801DCC84	sw     s5, $0024(sp)
801DCC88	sw     s4, $0020(sp)
801DCC8C	sw     s3, $001c(sp)
801DCC90	jal    func490b4 [$800490b4]
801DCC94	sw     s2, $0018(sp)
801DCC98	addu   a0, s0, zero
801DCC9C	addiu  a1, s1, $000c
801DCCA0	lui    a2, $1f80
801DCCA4	jal    func491c4 [$800491c4]
801DCCA8	ori    a2, a2, $0040
801DCCAC	lhu    s5, $000a(s1)
801DCCB0	addiu  s1, s1, $007c
801DCCB4	ori    s3, zero, $0001
801DCCB8	sltu   v0, s3, s5
801DCCBC	beq    v0, zero, L1dcd58 [$801dcd58]
801DCCC0	lui    s4, $1f80
801DCCC4	addiu  s2, s1, $0008

loop1dccc8:	; 801DCCC8
801DCCC8	lhu    v1, $0000(s2)
801DCCCC	ori    v0, zero, $ffff
801DCCD0	beq    v1, v0, L1dcd48 [$801dcd48]
801DCCD4	addiu  s3, s3, $0001
801DCCD8	addu   a0, fp, zero
801DCCDC	addiu  s0, s1, $002c
801DCCE0	addu   a1, s0, zero
801DCCE4	jal    func490b4 [$800490b4]
801DCCE8	addu   a2, s4, zero
801DCCEC	jal    func49dd4 [$80049dd4]
801DCCF0	addu   a0, s4, zero
801DCCF4	addu   a0, s6, zero
801DCCF8	addu   a1, s0, zero
801DCCFC	jal    func491c4 [$800491c4]
801DCD00	addu   a2, s4, zero

L1dcd04:	; 801DCD04
801DCD04	jal    func49da4 [$80049da4]
801DCD08	addu   a0, s4, zero
801DCD0C	jal    func49e34 [$80049e34]
801DCD10	addu   a0, s4, zero
801DCD14	lw     a2, $004c(sp)
801DCD18	lw     t0, $0050(sp)
801DCD1C	lw     v1, $0000(s7)
801DCD20	sll    v0, t0, $02
801DCD24	addu   v0, v0, s1

L1dcd28:	; 801DCD28
801DCD28	lw     a1, $0068(v0)
801DCD2C	lhu    v0, $0000(s2)
801DCD30	lw     a3, $0048(sp)
801DCD34	sll    v0, v0, $02
801DCD38	addu   v0, v0, v1
801DCD3C	lw     a0, $0000(v0)
801DCD40	jal    func2c510 [$8002c510]
801DCD44	nop

L1dcd48:	; 801DCD48
801DCD48	addiu  s2, s2, $007c
801DCD4C	sltu   v0, s3, s5
801DCD50	bne    v0, zero, loop1dccc8 [$801dccc8]
801DCD54	addiu  s1, s1, $007c

L1dcd58:	; 801DCD58
801DCD58	lw     ra, $0034(sp)
801DCD5C	lw     fp, $0030(sp)
801DCD60	lw     s7, $002c(sp)
801DCD64	lw     s6, $0028(sp)
801DCD68	lw     s5, $0024(sp)
801DCD6C	lw     s4, $0020(sp)
801DCD70	lw     s3, $001c(sp)
801DCD74	lw     s2, $0018(sp)
801DCD78	lw     s1, $0014(sp)
801DCD7C	lw     s0, $0010(sp)
801DCD80	addiu  sp, sp, $0038
801DCD84	jr     ra 
801DCD88	nop


func1dcd8c:	; 801DCD8C
801DCD8C	addiu  sp, sp, $ffd8 (=-$28)
801DCD90	sw     s2, $0020(sp)
801DCD94	addu   s2, a0, zero
801DCD98	sw     ra, $0024(sp)
801DCD9C	sw     s1, $001c(sp)
801DCDA0	beq    s2, zero, L1dcdfc [$801dcdfc]
801DCDA4	sw     s0, $0018(sp)
801DCDA8	lhu    v0, $000a(s2)
801DCDAC	nop
801DCDB0	blez   v0, L1dcdf0 [$801dcdf0]
801DCDB4	addu   s1, zero, zero
801DCDB8	addiu  s0, s2, $006c

loop1dcdbc:	; 801DCDBC
801DCDBC	lw     a0, $fffc(s0)
801DCDC0	nop
801DCDC4	beq    a0, zero, L1dcddc [$801dcddc]
801DCDC8	addiu  s1, s1, $0001
801DCDCC	jal    func31f0c [$80031f0c]
801DCDD0	nop
801DCDD4	sw     zero, $fffc(s0)
801DCDD8	sw     zero, $0000(s0)

L1dcddc:	; 801DCDDC
801DCDDC	lhu    v0, $000a(s2)
801DCDE0	nop
801DCDE4	slt    v0, s1, v0
801DCDE8	bne    v0, zero, loop1dcdbc [$801dcdbc]
801DCDEC	addiu  s0, s0, $007c

L1dcdf0:	; 801DCDF0
801DCDF0	sh     zero, $000a(s2)
801DCDF4	jal    func31f0c [$80031f0c]
801DCDF8	addu   a0, s2, zero

L1dcdfc:	; 801DCDFC
801DCDFC	lw     ra, $0024(sp)
801DCE00	lw     s2, $0020(sp)
801DCE04	lw     s1, $001c(sp)
801DCE08	lw     s0, $0018(sp)
801DCE0C	addiu  sp, sp, $0028
801DCE10	jr     ra 
801DCE14	nop


func1dce18:	; 801DCE18
801DCE18	addiu  sp, sp, $ffd8 (=-$28)
801DCE1C	sw     s1, $001c(sp)
801DCE20	addu   s1, a0, zero
801DCE24	sw     s2, $0020(sp)
801DCE28	addu   s2, a1, zero
801DCE2C	sw     ra, $0024(sp)
801DCE30	beq    s1, zero, L1dceac [$801dceac]
801DCE34	sw     s0, $0018(sp)
801DCE38	lw     v0, $0004(s1)
801DCE3C	nop
801DCE40	beq    v0, zero, L1dce90 [$801dce90]
801DCE44	addu   s0, zero, zero

loop1dce48:	; 801DCE48
801DCE48	lw     v1, $0000(s1)
801DCE4C	nop
801DCE50	beq    v1, zero, L1dce7c [$801dce7c]
801DCE54	sll    v0, s0, $02
801DCE58	addu   v0, v0, v1
801DCE5C	lw     a0, $0000(v0)
801DCE60	nop
801DCE64	beq    a0, zero, L1dce7c [$801dce7c]
801DCE68	nop
801DCE6C	beq    s2, zero, L1dce7c [$801dce7c]
801DCE70	nop
801DCE74	jal    func2c9cc [$8002c9cc]
801DCE78	nop

L1dce7c:	; 801DCE7C
801DCE7C	lw     v0, $0004(s1)
801DCE80	addiu  s0, s0, $0001
801DCE84	sltu   v0, s0, v0
801DCE88	bne    v0, zero, loop1dce48 [$801dce48]
801DCE8C	nop

L1dce90:	; 801DCE90
801DCE90	lw     a0, $0000(s1)
801DCE94	nop
801DCE98	beq    a0, zero, L1dceac [$801dceac]
801DCE9C	nop
801DCEA0	jal    func31f0c [$80031f0c]
801DCEA4	nop
801DCEA8	sw     zero, $0000(s1)

L1dceac:	; 801DCEAC
801DCEAC	lw     ra, $0024(sp)
801DCEB0	lw     s2, $0020(sp)
801DCEB4	lw     s1, $001c(sp)
801DCEB8	lw     s0, $0018(sp)
801DCEBC	addiu  sp, sp, $0028
801DCEC0	jr     ra 
801DCEC4	nop


func1dcec8:	; 801DCEC8
801DCEC8	addiu  sp, sp, $ff20 (=-$e0)
801DCECC	sw     s5, $00cc(sp)
801DCED0	addu   s5, a0, zero
801DCED4	sw     s1, $00bc(sp)
801DCED8	addu   s1, a2, zero
801DCEDC	sw     s6, $00d0(sp)
801DCEE0	lui    s6, $1f80
801DCEE4	ori    s6, s6, $0020
801DCEE8	lui    t2, $1f80
801DCEEC	ori    t2, t2, $0040
801DCEF0	sw     ra, $00dc(sp)
801DCEF4	sw     fp, $00d8(sp)
801DCEF8	sw     s7, $00d4(sp)
801DCEFC	sw     s4, $00c8(sp)
801DCF00	sw     s3, $00c4(sp)
801DCF04	sw     s2, $00c0(sp)
801DCF08	sw     s0, $00b8(sp)
801DCF0C	sw     a1, $0068(sp)
801DCF10	sw     a3, $0070(sp)
801DCF14	sw     t2, $0088(sp)
801DCF18	lbu    v0, $0034(s5)
801DCF1C	nop
801DCF20	beq    v0, zero, loop1ddbc4 [$801ddbc4]
801DCF24	lui    s7, $1f80
801DCF28	lui    a2, $1f80
801DCF2C	lw     a0, $0068(sp)
801DCF30	lw     s2, $0004(s5)
801DCF34	ori    a2, a2, $0040
801DCF38	sw     s2, $0078(sp)
801DCF3C	addiu  s0, s2, $000c
801DCF40	lw     fp, $0000(s5)
801DCF44	lhu    t2, $001c(s5)
801DCF48	nop
801DCF4C	sh     t2, $0080(sp)
801DCF50	lhu    s3, $000a(s2)
801DCF54	jal    func491c4 [$800491c4]
801DCF58	addu   a1, s0, zero
801DCF5C	lhu    v0, $004a(s5)
801DCF60	nop
801DCF64	andi   v0, v0, $0001
801DCF68	bne    v0, zero, L1dd314 [$801dd314]
801DCF6C	addu   a0, s0, zero
801DCF70	lw     a1, $0004(s5)
801DCF74	lui    a2, $1f80
801DCF78	jal    func491c4 [$800491c4]
801DCF7C	addiu  a1, a1, $00a8
801DCF80	jal    func49da4 [$80049da4]
801DCF84	lui    a0, $1f80

L1dcf88:	; 801DCF88
801DCF88	jal    func49e34 [$80049e34]
801DCF8C	lui    a0, $1f80
801DCF90	ori    v0, zero, $1000
801DCF94	addiu  s0, sp, $0020
801DCF98	sh     zero, $0020(sp)
801DCF9C	sh     zero, $0022(sp)
801DCFA0	sh     v0, $0024(sp)
801DCFA4	lwc2   zero, $0000(s0)
801DCFA8	lwc2   at, $0004(s0)
801DCFAC	nop
801DCFB0	nop
801DCFB4	gte_func18t0,r11r12
801DCFB8	addiu  v0, sp, $0028
801DCFBC	swc2   t9, $0000(v0)
801DCFC0	swc2   k0, $0004(v0)
801DCFC4	swc2   k1, $0008(v0)
801DCFC8	sh     zero, $0020(sp)
801DCFCC	sh     zero, $0022(sp)
801DCFD0	sh     zero, $0024(sp)
801DCFD4	lwc2   zero, $0000(s0)
801DCFD8	lwc2   at, $0004(s0)
801DCFDC	nop
801DCFE0	nop
801DCFE4	gte_func18t0,r11r12
801DCFE8	addiu  v0, sp, $0038
801DCFEC	swc2   t9, $0000(v0)
801DCFF0	swc2   k0, $0004(v0)
801DCFF4	swc2   k1, $0008(v0)
801DCFF8	lw     v1, $0030(sp)
801DCFFC	lw     a0, $0040(sp)
801DD000	lw     v0, $0028(sp)
801DD004	lw     a1, $0038(sp)
801DD008	subu   a0, v1, a0
801DD00C	jal    func4b1d4 [$8004b1d4]
801DD010	subu   a1, v0, a1
801DD014	addu   a0, s0, zero
801DD018	lui    a1, $1f80
801DD01C	ori    a1, a1, $0020
801DD020	subu   v0, zero, v0
801DD024	sh     v0, $0022(sp)
801DD028	sh     zero, $0020(sp)
801DD02C	jal    func3f5e0 [$8003f5e0]
801DD030	sh     zero, $0024(sp)
801DD034	lui    a1, $1f80
801DD038	ori    a1, a1, $0020
801DD03C	lw     a0, $0068(sp)
801DD040	lw     v0, $0038(sp)
801DD044	lui    a2, $1f80
801DD048	lui    at, $1f80
801DD04C	sw     v0, $0034(at)
801DD050	lh     v1, $0060(s5)
801DD054	lw     v0, $0040(sp)
801DD058	lui    at, $1f80
801DD05C	sw     v0, $003c(at)
801DD060	lui    at, $1f80
801DD064	sw     v1, $0038(at)
801DD068	jal    func491c4 [$800491c4]
801DD06C	ori    a2, a2, $0020
801DD070	lw     v0, $0004(s5)
801DD074	lh     v1, $0060(s5)
801DD078	lw     v0, $0060(v0)
801DD07C	nop
801DD080	subu   v0, v1, v0
801DD084	lh     v1, $001c(s5)
801DD088	bgez   v0, L1dd094 [$801dd094]
801DD08C	nop
801DD090	addiu  v0, v0, $0003

L1dd094:	; 801DD094
801DD094	sra    v0, v0, $02

L1dd098:	; 801DD098
801DD098	subu   v0, v1, v0
801DD09C	bgez   v0, L1dd0a8 [$801dd0a8]
801DD0A0	lui    a0, $1f80
801DD0A4	addu   v0, zero, zero

L1dd0a8:	; 801DD0A8
801DD0A8	ori    a0, a0, $0020
801DD0AC	sh     v0, $0000(s7)
801DD0B0	lui    at, $1f80
801DD0B4	sh     zero, $0002(at)
801DD0B8	lui    at, $1f80
801DD0BC	sh     zero, $0004(at)
801DD0C0	lui    at, $1f80
801DD0C4	sh     zero, $0006(at)
801DD0C8	lui    at, $1f80
801DD0CC	sh     v0, $0008(at)
801DD0D0	lui    at, $1f80
801DD0D4	sh     zero, $000a(at)
801DD0D8	lui    at, $1f80
801DD0DC	sh     zero, $000c(at)
801DD0E0	lui    at, $1f80
801DD0E4	sh     zero, $000e(at)
801DD0E8	lui    at, $1f80
801DD0EC	sh     v0, $0010(at)
801DD0F0	jal    func49974 [$80049974]

L1dd0f4:	; 801DD0F4
801DD0F4	lui    a1, $1f80
801DD0F8	lui    a0, $1f80
801DD0FC	jal    func49da4 [$80049da4]
801DD100	ori    a0, a0, $0020
801DD104	lui    a0, $1f80
801DD108	jal    func49e34 [$80049e34]
801DD10C	ori    a0, a0, $0020
801DD110	lhu    v0, $0026(s5)
801DD114	sh     zero, $0022(sp)
801DD118	sh     v0, $0020(sp)
801DD11C	lhu    v0, $0028(s5)
801DD120	nop
801DD124	sh     v0, $0024(sp)
801DD128	lwc2   zero, $0000(s0)

L1dd12c:	; 801DD12C
801DD12C	lwc2   at, $0004(s0)
801DD130	nop
801DD134	nop
801DD138	gte_func16t8,r11r12
801DD13C	lw     t2, $00f8(sp)
801DD140	nop
801DD144	sll    v0, t2, $02
801DD148	addu   v0, v0, t2
801DD14C	sll    a3, v0, $03
801DD150	addiu  v0, a3, $00b8
801DD154	addu   t1, s5, v0
801DD158	addiu  v0, t1, $0008
801DD15C	swc2   t6, $0000(v0)
801DD160	addiu  v0, sp, $0048
801DD164	mfc2   t4,lb1lb2
801DD168	nop
801DD16C	sra    t4, t4, $02
801DD170	sw     t4, $0000(v0)
801DD174	lhu    v0, $0026(s5)
801DD178	nop
801DD17C	subu   v0, zero, v0
801DD180	sh     v0, $0020(sp)
801DD184	lwc2   zero, $0000(s0)
801DD188	lwc2   at, $0004(s0)
801DD18C	nop
801DD190	nop
801DD194	gte_func16t8,r11r12
801DD198	addiu  v0, t1, $0010
801DD19C	swc2   t6, $0000(v0)
801DD1A0	addiu  a0, sp, $004c

L1dd1a4:	; 801DD1A4
801DD1A4	mfc2   t4,lb1lb2
801DD1A8	nop

L1dd1ac:	; 801DD1AC
801DD1AC	sra    t4, t4, $02

L1dd1b0:	; 801DD1B0
801DD1B0	sw     t4, $0000(a0)
801DD1B4	lw     v1, $004c(sp)

L1dd1b8:	; 801DD1B8
801DD1B8	lw     v0, $0048(sp)
801DD1BC	nop
801DD1C0	slt    v0, v1, v0
801DD1C4	beq    v0, zero, L1dd1d0 [$801dd1d0]
801DD1C8	nop
801DD1CC	sw     v1, $0048(sp)

L1dd1d0:	; 801DD1D0
801DD1D0	lhu    v0, $0026(s5)
801DD1D4	nop
801DD1D8	sh     v0, $0020(sp)
801DD1DC	lhu    v0, $0028(s5)
801DD1E0	nop
801DD1E4	subu   v0, zero, v0
801DD1E8	sh     v0, $0024(sp)

L1dd1ec:	; 801DD1EC
801DD1EC	lwc2   zero, $0000(s0)
801DD1F0	lwc2   at, $0004(s0)
801DD1F4	nop
801DD1F8	nop
801DD1FC	gte_func16t8,r11r12
801DD200	addiu  v0, t1, $0018
801DD204	swc2   t6, $0000(v0)
801DD208	mfc2   t4,lb1lb2
801DD20C	nop
801DD210	sra    t4, t4, $02
801DD214	sw     t4, $0000(a0)
801DD218	lw     v1, $004c(sp)
801DD21C	lw     v0, $0048(sp)
801DD220	nop

L1dd224:	; 801DD224
801DD224	slt    v0, v1, v0
801DD228	beq    v0, zero, L1dd234 [$801dd234]

L1dd22c:	; 801DD22C
801DD22C	nop
801DD230	sw     v1, $0048(sp)

L1dd234:	; 801DD234
801DD234	lhu    v0, $0026(s5)
801DD238	nop
801DD23C	subu   v0, zero, v0
801DD240	sh     v0, $0020(sp)
801DD244	lwc2   zero, $0000(s0)
801DD248	lwc2   at, $0004(s0)
801DD24C	nop
801DD250	nop
801DD254	gte_func16t8,r11r12
801DD258	addiu  v0, t1, $0020
801DD25C	swc2   t6, $0000(v0)
801DD260	mfc2   t4,lb1lb2
801DD264	nop
801DD268	sra    t4, t4, $02
801DD26C	sw     t4, $0000(a0)
801DD270	lw     v1, $004c(sp)
801DD274	lw     v0, $0048(sp)
801DD278	nop

L1dd27c:	; 801DD27C
801DD27C	slt    v0, v1, v0
801DD280	beq    v0, zero, L1dd28c [$801dd28c]
801DD284	lui    a2, $00ff
801DD288	sw     v1, $0048(sp)

L1dd28c:	; 801DD28C
801DD28C	ori    a2, a2, $ffff
801DD290	addu   a3, a3, s5
801DD294	lui    t0, $ff00
801DD298	lw     a0, $0048(sp)
801DD29C	lui    v0, $8005
801DD2A0	lw     v0, $f7a4(v0)
801DD2A4	lw     t2, $00f4(sp)
801DD2A8	lw     v1, $00b8(a3)
801DD2AC	srav   a0, v0, a0
801DD2B0	sll    a1, a0, $02
801DD2B4	addu   a1, a1, t2
801DD2B8	lw     v0, $0000(a1)
801DD2BC	and    v1, v1, t0
801DD2C0	and    v0, v0, a2
801DD2C4	or     v1, v1, v0
801DD2C8	sw     v1, $00b8(a3)
801DD2CC	lw     v0, $0000(a1)
801DD2D0	and    a2, t1, a2
801DD2D4	sw     a0, $0048(sp)
801DD2D8	slti   a0, a0, $02d9
801DD2DC	and    v0, v0, t0
801DD2E0	or     v0, v0, a2
801DD2E4	bne    a0, zero, L1dd2f4 [$801dd2f4]
801DD2E8	sw     v0, $0000(a1)
801DD2EC	ori    v0, zero, $02d8
801DD2F0	sw     v0, $0048(sp)

L1dd2f4:	; 801DD2F4
801DD2F4	lw     v1, $0048(sp)
801DD2F8	nop
801DD2FC	bgez   v1, L1dd308 [$801dd308]
801DD300	ori    v0, zero, $006b
801DD304	addiu  v1, v1, $0007

L1dd308:	; 801DD308
801DD308	sra    v1, v1, $03
801DD30C	subu   v0, v0, v1
801DD310	sb     v0, $0039(s5)

L1dd314:	; 801DD314
801DD314	addu   a0, s1, zero
801DD318	addiu  a1, s2, $002c
801DD31C	jal    func490b4 [$800490b4]
801DD320	addu   a2, s6, zero
801DD324	ori    s4, zero, $0001
801DD328	sltu   v0, s4, s3
801DD32C	beq    v0, zero, L1dd450 [$801dd450]
801DD330	addiu  s2, s2, $007c
801DD334	addiu  s1, s2, $0008

loop1dd338:	; 801DD338
801DD338	lhu    v1, $0000(s1)
801DD33C	ori    v0, zero, $ffff
801DD340	beq    v1, v0, L1dd43c [$801dd43c]
801DD344	nop
801DD348	lbu    v0, $ffff(s1)
801DD34C	nop
801DD350	beq    v0, zero, L1dd43c [$801dd43c]
801DD354	addu   a0, s6, zero
801DD358	addiu  s0, s2, $002c
801DD35C	addu   a1, s0, zero
801DD360	jal    func490b4 [$800490b4]
801DD364	addu   a2, s7, zero
801DD368	jal    func49dd4 [$80049dd4]
801DD36C	addu   a0, s7, zero
801DD370	addu   a1, s0, zero
801DD374	lw     a0, $0088(sp)
801DD378	jal    func491c4 [$800491c4]
801DD37C	addu   a2, s7, zero
801DD380	lh     v0, $004a(s1)
801DD384	nop
801DD388	blez   v0, L1dd3f8 [$801dd3f8]
801DD38C	nop
801DD390	lhu    v0, $001c(s5)
801DD394	sh     zero, $0004(s7)
801DD398	sh     zero, $0006(s7)
801DD39C	sh     zero, $000a(s7)
801DD3A0	sh     zero, $000c(s7)
801DD3A4	sh     v0, $0000(s7)
801DD3A8	lhu    v0, $001c(s5)
801DD3AC	nop
801DD3B0	sh     v0, $0010(s7)
801DD3B4	lh     v1, $004a(s1)
801DD3B8	ori    v0, zero, $0001
801DD3BC	bne    v1, v0, L1dd3e8 [$801dd3e8]
801DD3C0	nop
801DD3C4	lw     t2, $0088(sp)
801DD3C8	nop
801DD3CC	lhu    v0, $0002(t2)
801DD3D0	lhu    v1, $0008(t2)
801DD3D4	lhu    a0, $000e(t2)
801DD3D8	sh     v0, $0002(s7)
801DD3DC	sh     v1, $0008(s7)
801DD3E0	j      L1dd3f8 [$801dd3f8]
801DD3E4	sh     a0, $000e(s7)

L1dd3e8:	; 801DD3E8
801DD3E8	sh     zero, $0002(s7)
801DD3EC	lhu    v0, $001c(s5)

L1dd3f0:	; 801DD3F0
801DD3F0	sh     zero, $000e(s7)
801DD3F4	sh     v0, $0008(s7)

L1dd3f8:	; 801DD3F8
801DD3F8	jal    func49da4 [$80049da4]
801DD3FC	addu   a0, s7, zero
801DD400	jal    func49e34 [$80049e34]
801DD404	addu   a0, s7, zero
801DD408	lw     a2, $00f4(sp)
801DD40C	lw     t2, $00f8(sp)
801DD410	lw     v1, $0000(fp)
801DD414	sll    v0, t2, $02
801DD418	addu   v0, v0, s2
801DD41C	lw     a1, $0068(v0)
801DD420	lhu    v0, $0000(s1)
801DD424	lw     a3, $0070(sp)
801DD428	sll    v0, v0, $02
801DD42C	addu   v0, v0, v1
801DD430	lw     a0, $0000(v0)
801DD434	jal    func2c510 [$8002c510]
801DD438	nop

L1dd43c:	; 801DD43C
801DD43C	addiu  s4, s4, $0001
801DD440	addiu  s1, s1, $007c
801DD444	sltu   v0, s4, s3
801DD448	bne    v0, zero, loop1dd338 [$801dd338]
801DD44C	addiu  s2, s2, $007c

L1dd450:	; 801DD450
801DD450	lbu    v0, $010d(s5)
801DD454	lw     s6, $0114(s5)
801DD458	blez   v0, L1dd6b8 [$801dd6b8]
801DD45C	addu   s4, zero, zero
801DD460	addiu  fp, sp, $0050
801DD464	addiu  s3, s6, $000a

L1dd468:	; 801DD468
801DD468	lh     v0, $0000(s6)
801DD46C	nop
801DD470	bltz   v0, L1dd6a0 [$801dd6a0]
801DD474	nop
801DD478	lw     t2, $0078(sp)
801DD47C	nop
801DD480	lh     a0, $0056(t2)
801DD484	jal    func3f774 [$8003f774]
801DD488	addiu  a0, a0, $0400
801DD48C	lui    v1, $801f
801DD490	lh     v1, $8698(v1)
801DD494	nop
801DD498	subu   v1, zero, v1
801DD49C	mult   v1, v0
801DD4A0	mflo   v0
801DD4A4	bgez   v0, L1dd4b0 [$801dd4b0]
801DD4A8	nop
801DD4AC	addiu  v0, v0, $0fff

L1dd4b0:	; 801DD4B0
801DD4B0	lw     t2, $0078(sp)
801DD4B4	sra    v0, v0, $0c
801DD4B8	sh     v0, $0060(sp)
801DD4BC	lh     a0, $0056(t2)
801DD4C0	jal    func3f758 [$8003f758]
801DD4C4	addiu  a0, a0, $0400
801DD4C8	lui    v1, $801f
801DD4CC	lh     v1, $8698(v1)
801DD4D0	nop
801DD4D4	mult   v1, v0
801DD4D8	mflo   v0
801DD4DC	bgez   v0, L1dd4e8 [$801dd4e8]
801DD4E0	addu   a2, s7, zero
801DD4E4	addiu  v0, v0, $0fff

L1dd4e8:	; 801DD4E8
801DD4E8	sra    v0, v0, $0c
801DD4EC	sh     v0, $0064(sp)
801DD4F0	lhu    v0, $003e(s5)
801DD4F4	lw     t2, $0078(sp)
801DD4F8	sh     v0, $0062(sp)
801DD4FC	lh     v0, $0000(s6)
801DD500	addiu  a0, t2, $000c
801DD504	sll    a1, v0, $05
801DD508	subu   a1, a1, v0
801DD50C	sll    a1, a1, $02
801DD510	addu   a1, t2, a1
801DD514	jal    func491c4 [$800491c4]
801DD518	addiu  a1, a1, $002c
801DD51C	jal    func49da4 [$80049da4]
801DD520	addu   a0, s7, zero
801DD524	jal    func49e34 [$80049e34]
801DD528	addu   a0, s7, zero
801DD52C	lh     v0, $fffa(s3)
801DD530	nop
801DD534	blez   v0, L1dd5d0 [$801dd5d0]
801DD538	addu   s1, zero, zero

loop1dd53c:	; 801DD53C
801DD53C	lw     v1, $000a(s3)
801DD540	sll    v0, s1, $03
801DD544	addu   v0, v0, v1
801DD548	lwc2   zero, $0000(v0)
801DD54C	lwc2   at, $0004(v0)
801DD550	nop
801DD554	nop
801DD558	gte_func18t0,r11r12
801DD55C	swc2   t9, $0000(fp)
801DD560	swc2   k0, $0004(fp)
801DD564	swc2   k1, $0008(fp)
801DD568	lw     v0, $0012(s3)
801DD56C	sll    v1, s1, $02
801DD570	addu   v0, v1, v0
801DD574	lw     a0, $0000(v0)
801DD578	lhu    v0, $0050(sp)
801DD57C	nop
801DD580	sh     v0, $0004(a0)
801DD584	lw     v0, $0012(s3)
801DD588	nop
801DD58C	addu   v0, v1, v0
801DD590	lw     a0, $0000(v0)
801DD594	lhu    v0, $0054(sp)
801DD598	nop

L1dd59c:	; 801DD59C
801DD59C	sh     v0, $0006(a0)
801DD5A0	lw     v0, $0012(s3)
801DD5A4	nop
801DD5A8	addu   v1, v1, v0
801DD5AC	lw     v1, $0000(v1)
801DD5B0	lhu    v0, $0058(sp)
801DD5B4	nop
801DD5B8	sh     v0, $0008(v1)
801DD5BC	lh     v0, $fffa(s3)
801DD5C0	addiu  s1, s1, $0001
801DD5C4	slt    v0, s1, v0
801DD5C8	bne    v0, zero, loop1dd53c [$801dd53c]
801DD5CC	nop

L1dd5d0:	; 801DD5D0
801DD5D0	lh     v0, $0000(s3)
801DD5D4	lw     s2, $000e(s3)
801DD5D8	blez   v0, L1dd674 [$801dd674]
801DD5DC	addu   s1, zero, zero
801DD5E0	addiu  s0, s2, $000c

loop1dd5e4:	; 801DD5E4
801DD5E4	addu   a2, s7, zero
801DD5E8	lw     t2, $0078(sp)
801DD5EC	lh     v0, $fffa(s0)
801DD5F0	addiu  a0, t2, $000c
801DD5F4	sll    a1, v0, $05
801DD5F8	subu   a1, a1, v0
801DD5FC	sll    a1, a1, $02
801DD600	addu   a1, t2, a1
801DD604	jal    func491c4 [$800491c4]
801DD608	addiu  a1, a1, $002c

L1dd60c:	; 801DD60C
801DD60C	jal    func49da4 [$80049da4]
801DD610	addu   a0, s7, zero
801DD614	jal    func49e34 [$80049e34]
801DD618	addu   a0, s7, zero
801DD61C	lwc2   zero, $0000(s2)
801DD620	lwc2   at, $0004(s2)
801DD624	nop
801DD628	nop
801DD62C	gte_func18t0,r11r12
801DD630	swc2   t9, $0000(fp)
801DD634	swc2   k0, $0004(fp)
801DD638	swc2   k1, $0008(fp)
801DD63C	lhu    v0, $0050(sp)
801DD640	nop
801DD644	sh     v0, $fffc(s0)
801DD648	lhu    v0, $0054(sp)
801DD64C	addiu  s1, s1, $0001
801DD650	sh     v0, $fffe(s0)
801DD654	lhu    v0, $0058(sp)
801DD658	addiu  s2, s2, $0010
801DD65C	sh     v0, $0000(s0)
801DD660	lh     v0, $0000(s3)
801DD664	nop
801DD668	slt    v0, s1, v0
801DD66C	bne    v0, zero, loop1dd5e4 [$801dd5e4]
801DD670	addiu  s0, s0, $0010

L1dd674:	; 801DD674
801DD674	lw     t2, $00f8(sp)
801DD678	lw     a2, $0068(sp)
801DD67C	lw     a3, $00f4(sp)
801DD680	sw     t2, $0010(sp)
801DD684	lhu    t2, $0080(sp)
801DD688	addu   a0, s6, zero

loop1dd68c:	; 801DD68C
801DD68C	sw     t2, $0014(sp)

L1dd690:	; 801DD690
801DD690	lh     v0, $0060(s5)
801DD694	addiu  a1, sp, $0060
801DD698	jal    func1e22f8 [$801e22f8]
801DD69C	sw     v0, $0018(sp)

L1dd6a0:	; 801DD6A0
801DD6A0	addiu  s3, s3, $0024
801DD6A4	lbu    v0, $010d(s5)
801DD6A8	addiu  s4, s4, $0001
801DD6AC	slt    v0, s4, v0
801DD6B0	bne    v0, zero, L1dd468 [$801dd468]
801DD6B4	addiu  s6, s6, $0024

L1dd6b8:	; 801DD6B8
801DD6B8	lbu    v0, $010e(s5)
801DD6BC	lw     s0, $0118(s5)
801DD6C0	blez   v0, L1dd6ec [$801dd6ec]
801DD6C4	addu   s4, zero, zero

loop1dd6c8:	; 801DD6C8
801DD6C8	lw     a1, $00f0(sp)
801DD6CC	jal    func1e1258 [$801e1258]
801DD6D0	addu   a0, s0, zero
801DD6D4	addiu  s4, s4, $0001
801DD6D8	lbu    v0, $010e(s5)
801DD6DC	nop
801DD6E0	slt    v0, s4, v0

L1dd6e4:	; 801DD6E4
801DD6E4	bne    v0, zero, loop1dd6c8 [$801dd6c8]
801DD6E8	addiu  s0, s0, $0030

L1dd6ec:	; 801DD6EC
801DD6EC	lbu    v0, $010c(s5)
801DD6F0	lw     s2, $0110(s5)
801DD6F4	blez   v0, loop1ddbc4 [$801ddbc4]
801DD6F8	addu   s4, zero, zero
801DD6FC	addiu  s1, s2, $0008

L1dd700:	; 801DD700
801DD700	lh     v0, $0000(s2)
801DD704	nop
801DD708	bltz   v0, L1ddba8 [$801ddba8]
801DD70C	nop
801DD710	lhu    v0, $0054(s1)

L1dd714:	; 801DD714
801DD714	lbu    v1, $fffa(s1)
801DD718	addiu  v0, v0, $ffff (=-$1)
801DD71C	andi   v0, v0, $0007
801DD720	bne    v1, zero, L1dd960 [$801dd960]
801DD724	sh     v0, $0054(s1)
801DD728	addu   a2, s7, zero
801DD72C	lw     a0, $0088(sp)
801DD730	lh     v0, $0000(s2)
801DD734	lw     t2, $0078(sp)
801DD738	sll    a1, v0, $05
801DD73C	subu   a1, a1, v0
801DD740	sll    a1, a1, $02
801DD744	addu   a1, t2, a1
801DD748	jal    func491c4 [$800491c4]
801DD74C	addiu  a1, a1, $002c
801DD750	jal    func49da4 [$80049da4]
801DD754	addu   a0, s7, zero
801DD758	jal    func49e34 [$80049e34]
801DD75C	addu   a0, s7, zero

L1dd760:	; 801DD760
801DD760	addiu  v0, s2, $000c

L1dd764:	; 801DD764
801DD764	lwc2   zero, $0000(v0)
801DD768	lwc2   at, $0004(v0)
801DD76C	nop
801DD770	nop
801DD774	gte_func16t8,r11r12

loop1dd778:	; 801DD778
801DD778	lh     v0, $0054(s1)
801DD77C	nop
801DD780	sll    v0, v0, $02
801DD784	addiu  v0, v0, $001c
801DD788	addu   v0, s2, v0
801DD78C	swc2   t6, $0000(v0)
801DD790	addiu  v0, s2, $0014
801DD794	lwc2   zero, $0000(v0)
801DD798	lwc2   at, $0004(v0)
801DD79C	nop
801DD7A0	nop
801DD7A4	gte_func16t8,r11r12
801DD7A8	lh     v0, $0054(s1)
801DD7AC	nop
801DD7B0	sll    v0, v0, $02
801DD7B4	addiu  v0, v0, $003c
801DD7B8	addu   v0, s2, v0
801DD7BC	swc2   t6, $0000(v0)
801DD7C0	lhu    v0, $0056(s1)
801DD7C4	nop
801DD7C8	addiu  v0, v0, $0001
801DD7CC	sh     v0, $0056(s1)
801DD7D0	sll    v0, v0, $10
801DD7D4	sra    v1, v0, $10
801DD7D8	beq    v1, zero, L1ddbb0 [$801ddbb0]

L1dd7dc:	; 801DD7DC
801DD7DC	nop
801DD7E0	lh     v0, $0058(s1)
801DD7E4	nop
801DD7E8	slt    v0, v0, v1
801DD7EC	bne    v0, zero, L1dd804 [$801dd804]
801DD7F0	ori    t2, zero, $0001
801DD7F4	lw     v0, $0000(s1)
801DD7F8	nop
801DD7FC	bne    v0, zero, L1dd8f0 [$801dd8f0]
801DD800	nop

L1dd804:	; 801DD804
801DD804	lw     a0, $fffc(s1)
801DD808	lbu    a1, $fffb(s1)
801DD80C	jal    func1e0248 [$801e0248]
801DD810	sh     t2, $0056(s1)
801DD814	sw     v0, $0000(s1)
801DD818	sh     zero, $000e(v0)
801DD81C	lw     v0, $0000(s1)
801DD820	nop
801DD824	sh     zero, $0016(v0)
801DD828	lw     v1, $0000(s1)
801DD82C	lhu    v0, $005a(s1)
801DD830	nop
801DD834	sh     v0, $001e(v1)
801DD838	lw     v1, $0000(s1)
801DD83C	lhu    v0, $005c(s1)
801DD840	nop
801DD844	sh     v0, $0020(v1)

L1dd848:	; 801DD848
801DD848	lw     v1, $0000(s1)
801DD84C	lhu    v0, $005e(s1)
801DD850	nop
801DD854	sh     v0, $0022(v1)
801DD858	lw     v1, $0000(s1)

L1dd85c:	; 801DD85C
801DD85C	lhu    v0, $0060(s1)
801DD860	nop
801DD864	sh     v0, $0024(v1)
801DD868	lw     v1, $0000(s1)
801DD86C	lhu    v0, $0062(s1)
801DD870	nop
801DD874	sh     v0, $0026(v1)
801DD878	lw     v1, $0000(s1)

L1dd87c:	; 801DD87C
801DD87C	lhu    v0, $0064(s1)
801DD880	nop
801DD884	sh     v0, $0028(v1)
801DD888	lw     v1, $0000(s1)
801DD88C	lhu    v0, $0066(s1)
801DD890	nop
801DD894	sh     v0, $002a(v1)
801DD898	lh     v1, $0054(s1)
801DD89C	lh     v0, $0056(s1)
801DD8A0	lw     a0, $0000(s1)
801DD8A4	addu   v1, v1, v0
801DD8A8	andi   v1, v1, $0007

L1dd8ac:	; 801DD8AC
801DD8AC	sll    v1, v1, $02
801DD8B0	addu   v1, v1, s2
801DD8B4	lhu    v0, $001c(v1)
801DD8B8	nop
801DD8BC	sh     v0, $0000(a0)
801DD8C0	lw     a0, $0000(s1)

L1dd8c4:	; 801DD8C4
801DD8C4	lhu    v0, $001e(v1)

L1dd8c8:	; 801DD8C8
801DD8C8	nop

L1dd8cc:	; 801DD8CC
801DD8CC	sh     v0, $0002(a0)

L1dd8d0:	; 801DD8D0
801DD8D0	lw     a0, $0000(s1)
801DD8D4	lhu    v0, $003c(v1)

L1dd8d8:	; 801DD8D8
801DD8D8	nop
801DD8DC	sh     v0, $0010(a0)
801DD8E0	lw     a0, $0000(s1)
801DD8E4	lhu    v0, $003e(v1)
801DD8E8	nop
801DD8EC	sh     v0, $0012(a0)

L1dd8f0:	; 801DD8F0
801DD8F0	lh     v0, $0054(s1)
801DD8F4	lw     v1, $0000(s1)
801DD8F8	sll    v0, v0, $02
801DD8FC	addu   v0, v0, s2
801DD900	lhu    v0, $001c(v0)

L1dd904:	; 801DD904
801DD904	nop
801DD908	sh     v0, $0008(v1)
801DD90C	lh     v0, $0054(s1)
801DD910	lw     v1, $0000(s1)
801DD914	sll    v0, v0, $02
801DD918	addu   v0, v0, s2
801DD91C	lhu    v0, $001e(v0)
801DD920	nop
801DD924	sh     v0, $000a(v1)
801DD928	lh     v0, $0054(s1)
801DD92C	lw     v1, $0000(s1)
801DD930	sll    v0, v0, $02
801DD934	addu   v0, v0, s2
801DD938	lhu    v0, $003c(v0)
801DD93C	nop
801DD940	sh     v0, $0018(v1)
801DD944	lh     v0, $0054(s1)
801DD948	lw     v1, $0000(s1)

L1dd94c:	; 801DD94C
801DD94C	sll    v0, v0, $02
801DD950	addu   v0, v0, s2
801DD954	lhu    v0, $003e(v0)

L1dd958:	; 801DD958
801DD958	j      L1ddba8 [$801ddba8]
801DD95C	sh     v0, $001a(v1)

L1dd960:	; 801DD960
801DD960	addu   a2, s7, zero
801DD964	lw     t2, $0078(sp)
801DD968	lh     v0, $0000(s2)
801DD96C	addiu  a0, t2, $000c
801DD970	sll    a1, v0, $05
801DD974	subu   a1, a1, v0
801DD978	sll    a1, a1, $02
801DD97C	addu   a1, t2, a1
801DD980	jal    func491c4 [$800491c4]
801DD984	addiu  a1, a1, $002c
801DD988	jal    func49da4 [$80049da4]

L1dd98c:	; 801DD98C
801DD98C	addu   a0, s7, zero
801DD990	jal    func49e34 [$80049e34]
801DD994	addu   a0, s7, zero
801DD998	lhu    v0, $0054(s1)

L1dd99c:	; 801DD99C
801DD99C	nop
801DD9A0	andi   fp, v0, $0001
801DD9A4	sll    v1, fp, $04
801DD9A8	addiu  v0, v1, $001c
801DD9AC	addu   s3, s2, v0
801DD9B0	addiu  v1, v1, $003c
801DD9B4	addu   s6, s2, v1
801DD9B8	addiu  v0, s2, $000c
801DD9BC	lwc2   zero, $0000(v0)
801DD9C0	lwc2   at, $0004(v0)
801DD9C4	nop
801DD9C8	nop
801DD9CC	gte_func18t0,r11r12

L1dd9d0:	; 801DD9D0
801DD9D0	swc2   t9, $0000(s3)

L1dd9d4:	; 801DD9D4
801DD9D4	swc2   k0, $0004(s3)
801DD9D8	swc2   k1, $0008(s3)
801DD9DC	addiu  v0, s2, $0014
801DD9E0	lwc2   zero, $0000(v0)
801DD9E4	lwc2   at, $0004(v0)
801DD9E8	nop

L1dd9ec:	; 801DD9EC
801DD9EC	nop
801DD9F0	gte_func18t0,r11r12
801DD9F4	swc2   t9, $0000(s6)

L1dd9f8:	; 801DD9F8
801DD9F8	swc2   k0, $0004(s6)
801DD9FC	swc2   k1, $0008(s6)
801DDA00	lhu    v0, $0056(s1)
801DDA04	nop
801DDA08	addiu  v0, v0, $0001
801DDA0C	sh     v0, $0056(s1)
801DDA10	sll    v0, v0, $10
801DDA14	sra    v1, v0, $10
801DDA18	beq    v1, zero, L1ddbb0 [$801ddbb0]
801DDA1C	nop
801DDA20	lh     v0, $0058(s1)
801DDA24	nop
801DDA28	slt    v0, v0, v1
801DDA2C	bne    v0, zero, L1dda44 [$801dda44]
801DDA30	ori    s0, zero, $0001
801DDA34	lw     v0, $0000(s1)
801DDA38	nop
801DDA3C	bne    v0, zero, L1ddb48 [$801ddb48]
801DDA40	nop

L1dda44:	; 801DDA44
801DDA44	lw     a0, $fffc(s1)
801DDA48	lbu    a1, $fffb(s1)
801DDA4C	jal    func1e0248 [$801e0248]
801DDA50	sh     s0, $0056(s1)
801DDA54	sw     v0, $0000(s1)
801DDA58	sh     s0, $000e(v0)
801DDA5C	lw     v0, $0000(s1)
801DDA60	nop
801DDA64	sh     zero, $0016(v0)
801DDA68	lw     v1, $0000(s1)
801DDA6C	lhu    v0, $005a(s1)
801DDA70	nop
801DDA74	sh     v0, $001e(v1)
801DDA78	lw     v1, $0000(s1)
801DDA7C	lhu    v0, $005c(s1)
801DDA80	nop

L1dda84:	; 801DDA84
801DDA84	sh     v0, $0020(v1)
801DDA88	lw     v1, $0000(s1)
801DDA8C	lhu    v0, $005e(s1)
801DDA90	nop
801DDA94	sh     v0, $0022(v1)
801DDA98	lw     v1, $0000(s1)
801DDA9C	lhu    v0, $0060(s1)
801DDAA0	nop
801DDAA4	sh     v0, $0024(v1)
801DDAA8	lw     v1, $0000(s1)
801DDAAC	lhu    v0, $0062(s1)
801DDAB0	nop
801DDAB4	sh     v0, $0026(v1)

L1ddab8:	; 801DDAB8
801DDAB8	lw     v1, $0000(s1)
801DDABC	lhu    v0, $0064(s1)
801DDAC0	nop
801DDAC4	sh     v0, $0028(v1)
801DDAC8	lw     v1, $0000(s1)
801DDACC	lhu    v0, $0066(s1)
801DDAD0	ori    t2, zero, $0001
801DDAD4	sh     v0, $002a(v1)
801DDAD8	subu   v1, t2, fp
801DDADC	sll    v1, v1, $04

L1ddae0:	; 801DDAE0
801DDAE0	addiu  a0, v1, $001c
801DDAE4	addu   a0, s2, a0
801DDAE8	lw     a1, $0000(s1)

L1ddaec:	; 801DDAEC
801DDAEC	lhu    v0, $0000(a0)
801DDAF0	nop

L1ddaf4:	; 801DDAF4
801DDAF4	sh     v0, $0000(a1)

L1ddaf8:	; 801DDAF8
801DDAF8	lw     a1, $0000(s1)

L1ddafc:	; 801DDAFC
801DDAFC	lhu    v0, $0004(a0)

L1ddb00:	; 801DDB00
801DDB00	addiu  v1, v1, $003c
801DDB04	sh     v0, $0002(a1)
801DDB08	lw     a1, $0000(s1)
801DDB0C	lhu    v0, $0008(a0)
801DDB10	addu   v1, s2, v1
801DDB14	sh     v0, $0004(a1)
801DDB18	lw     a0, $0000(s1)
801DDB1C	lhu    v0, $0000(v1)
801DDB20	nop
801DDB24	sh     v0, $0010(a0)
801DDB28	lw     a0, $0000(s1)
801DDB2C	lhu    v0, $0004(v1)

L1ddb30:	; 801DDB30
801DDB30	nop

L1ddb34:	; 801DDB34
801DDB34	sh     v0, $0012(a0)
801DDB38	lw     a0, $0000(s1)
801DDB3C	lhu    v0, $0008(v1)
801DDB40	nop

loop1ddb44:	; 801DDB44
801DDB44	sh     v0, $0014(a0)

L1ddb48:	; 801DDB48
801DDB48	lw     v1, $0000(s1)
801DDB4C	lhu    v0, $0000(s3)
801DDB50	nop
801DDB54	sh     v0, $0008(v1)
801DDB58	lw     v1, $0000(s1)
801DDB5C	lhu    v0, $0004(s3)
801DDB60	nop
801DDB64	sh     v0, $000a(v1)
801DDB68	lw     v1, $0000(s1)
801DDB6C	lhu    v0, $0008(s3)
801DDB70	nop
801DDB74	sh     v0, $000c(v1)

L1ddb78:	; 801DDB78
801DDB78	lw     v1, $0000(s1)

L1ddb7c:	; 801DDB7C
801DDB7C	lhu    v0, $0000(s6)

L1ddb80:	; 801DDB80
801DDB80	nop
801DDB84	sh     v0, $0018(v1)
801DDB88	lw     v1, $0000(s1)
801DDB8C	lhu    v0, $0004(s6)
801DDB90	nop
801DDB94	sh     v0, $001a(v1)
801DDB98	lw     v1, $0000(s1)
801DDB9C	lhu    v0, $0008(s6)
801DDBA0	nop
801DDBA4	sh     v0, $001c(v1)

L1ddba8:	; 801DDBA8
801DDBA8	addiu  s1, s1, $0070
801DDBAC	addiu  s2, s2, $0070

L1ddbb0:	; 801DDBB0
801DDBB0	lbu    v0, $010c(s5)
801DDBB4	addiu  s4, s4, $0001
801DDBB8	slt    v0, s4, v0
801DDBBC	bne    v0, zero, L1dd700 [$801dd700]
801DDBC0	nop

loop1ddbc4:	; 801DDBC4
801DDBC4	lw     ra, $00dc(sp)
801DDBC8	lw     fp, $00d8(sp)
801DDBCC	lw     s7, $00d4(sp)
801DDBD0	lw     s6, $00d0(sp)
801DDBD4	lw     s5, $00cc(sp)

L1ddbd8:	; 801DDBD8
801DDBD8	lw     s4, $00c8(sp)
801DDBDC	lw     s3, $00c4(sp)
801DDBE0	lw     s2, $00c0(sp)
801DDBE4	lw     s1, $00bc(sp)
801DDBE8	lw     s0, $00b8(sp)
801DDBEC	addiu  sp, sp, $00e0
801DDBF0	jr     ra 
801DDBF4	nop


func1ddbf8:	; 801DDBF8
801DDBF8	addiu  sp, sp, $ff48 (=-$b8)

L1ddbfc:	; 801DDBFC
801DDBFC	sw     ra, $00b4(sp)

L1ddc00:	; 801DDC00
801DDC00	sw     fp, $00b0(sp)
801DDC04	sw     s7, $00ac(sp)
801DDC08	sw     s6, $00a8(sp)
801DDC0C	sw     s5, $00a4(sp)
801DDC10	sw     s4, $00a0(sp)
801DDC14	sw     s3, $009c(sp)
801DDC18	sw     s2, $0098(sp)
801DDC1C	sw     s1, $0094(sp)

L1ddc20:	; 801DDC20
801DDC20	sw     s0, $0090(sp)

L1ddc24:	; 801DDC24
801DDC24	sw     a0, $0028(sp)

L1ddc28:	; 801DDC28
801DDC28	sw     a1, $0030(sp)
801DDC2C	sw     a2, $0038(sp)
801DDC30	sw     a3, $0040(sp)
801DDC34	sw     zero, $0048(sp)
801DDC38	lhu    t4, $000a(a1)
801DDC3C	addu   s5, zero, zero
801DDC40	beq    t4, zero, L1deed8 [$801deed8]
801DDC44	sw     t4, $0050(sp)
801DDC48	addiu  s1, a1, $0004

L1ddc4c:	; 801DDC4C
801DDC4C	lw     a1, $006c(s1)
801DDC50	nop
801DDC54	beq    a1, zero, L1de3ec [$801de3ec]
801DDC58	addu   s0, a1, zero

L1ddc5c:	; 801DDC5C
801DDC5C	lbu    fp, $0002(s0)

L1ddc60:	; 801DDC60
801DDC60	nop
801DDC64	andi   v1, fp, $000f
801DDC68	sltiu  v0, v1, $0009
801DDC6C	beq    v0, zero, L1de308 [$801de308]
801DDC70	sll    v0, v1, $02
801DDC74	lui    at, $801e
801DDC78	addu   at, at, v0
801DDC7C	lw     v0, $c000(at)
801DDC80	nop
801DDC84	jr     v0 
801DDC88	nop

801DDC8C	lw     a0, $0008(s0)

L1ddc90:	; 801DDC90
801DDC90	andi   v0, fp, $0010
801DDC94	bne    v0, zero, L1ddcbc [$801ddcbc]
801DDC98	andi   v0, fp, $0020
801DDC9C	lhu    v0, $0000(a0)
801DDCA0	nop
801DDCA4	sh     v0, $0050(s1)
801DDCA8	lw     v0, $0008(s0)
801DDCAC	addiu  a0, a0, $0002
801DDCB0	addiu  v0, v0, $0002
801DDCB4	sw     v0, $0008(s0)
801DDCB8	andi   v0, fp, $0020

L1ddcbc:	; 801DDCBC
801DDCBC	bne    v0, zero, L1ddce4 [$801ddce4]

L1ddcc0:	; 801DDCC0
801DDCC0	andi   v0, fp, $0040
801DDCC4	lhu    v0, $0000(a0)

L1ddcc8:	; 801DDCC8
801DDCC8	nop

L1ddccc:	; 801DDCCC
801DDCCC	sh     v0, $0052(s1)

L1ddcd0:	; 801DDCD0
801DDCD0	lw     v0, $0008(s0)

L1ddcd4:	; 801DDCD4
801DDCD4	addiu  a0, a0, $0002
801DDCD8	addiu  v0, v0, $0002

L1ddcdc:	; 801DDCDC
801DDCDC	sw     v0, $0008(s0)

L1ddce0:	; 801DDCE0
801DDCE0	andi   v0, fp, $0040

L1ddce4:	; 801DDCE4
801DDCE4	bne    v0, zero, L1de308 [$801de308]
801DDCE8	nop
801DDCEC	lhu    v0, $0000(a0)
801DDCF0	j      L1ddea4 [$801ddea4]
801DDCF4	sh     v0, $0054(s1)
801DDCF8	andi   v0, fp, $0010
801DDCFC	bne    v0, zero, L1ddd5c [$801ddd5c]
801DDD00	andi   v0, fp, $0020
801DDD04	lw     v1, $0008(s0)
801DDD08	nop

L1ddd0c:	; 801DDD0C
801DDD0C	addiu  v0, v1, $0001

L1ddd10:	; 801DDD10
801DDD10	sw     v0, $0008(s0)
801DDD14	lb     a0, $0000(v1)
801DDD18	addiu  v0, zero, $ff80 (=-$80)
801DDD1C	beq    a0, v0, L1ddd30 [$801ddd30]
801DDD20	nop
801DDD24	lhu    v0, $0050(s1)
801DDD28	j      L1ddd54 [$801ddd54]
801DDD2C	addu   v0, v0, a0

L1ddd30:	; 801DDD30
801DDD30	addiu  v0, v1, $0002
801DDD34	sw     v0, $0008(s0)
801DDD38	lbu    a0, $0001(v1)
801DDD3C	addiu  v0, v1, $0003
801DDD40	sw     v0, $0008(s0)
801DDD44	lb     v0, $0002(v1)
801DDD48	nop

L1ddd4c:	; 801DDD4C
801DDD4C	sll    v0, v0, $08

L1ddd50:	; 801DDD50
801DDD50	or     v0, a0, v0

L1ddd54:	; 801DDD54
801DDD54	sh     v0, $0050(s1)

L1ddd58:	; 801DDD58
801DDD58	andi   v0, fp, $0020

L1ddd5c:	; 801DDD5C
801DDD5C	bne    v0, zero, L1dddbc [$801dddbc]
801DDD60	andi   v0, fp, $0040
801DDD64	lw     v1, $0008(s0)
801DDD68	nop
801DDD6C	addiu  v0, v1, $0001
801DDD70	sw     v0, $0008(s0)
801DDD74	lb     a0, $0000(v1)
801DDD78	addiu  v0, zero, $ff80 (=-$80)
801DDD7C	beq    a0, v0, L1ddd90 [$801ddd90]

L1ddd80:	; 801DDD80
801DDD80	nop
801DDD84	lhu    v0, $0052(s1)
801DDD88	j      L1dddb4 [$801dddb4]
801DDD8C	addu   v0, v0, a0

L1ddd90:	; 801DDD90
801DDD90	addiu  v0, v1, $0002

L1ddd94:	; 801DDD94
801DDD94	sw     v0, $0008(s0)
801DDD98	lbu    a0, $0001(v1)
801DDD9C	addiu  v0, v1, $0003
801DDDA0	sw     v0, $0008(s0)
801DDDA4	lb     v0, $0002(v1)
801DDDA8	nop
801DDDAC	sll    v0, v0, $08
801DDDB0	or     v0, a0, v0

L1dddb4:	; 801DDDB4
801DDDB4	sh     v0, $0052(s1)
801DDDB8	andi   v0, fp, $0040

L1dddbc:	; 801DDDBC
801DDDBC	bne    v0, zero, L1de308 [$801de308]
801DDDC0	nop
801DDDC4	lw     v1, $0008(s0)
801DDDC8	nop

loop1dddcc:	; 801DDDCC
801DDDCC	addiu  v0, v1, $0001

L1dddd0:	; 801DDDD0
801DDDD0	sw     v0, $0008(s0)

L1dddd4:	; 801DDDD4
801DDDD4	lb     a0, $0000(v1)

L1dddd8:	; 801DDDD8
801DDDD8	addiu  v0, zero, $ff80 (=-$80)
801DDDDC	beq    a0, v0, L1dddf8 [$801dddf8]
801DDDE0	addiu  v0, v1, $0002
801DDDE4	lhu    v0, $0054(s1)

loop1ddde8:	; 801DDDE8
801DDDE8	nop
801DDDEC	addu   v0, v0, a0
801DDDF0	j      L1de308 [$801de308]
801DDDF4	sh     v0, $0054(s1)

L1dddf8:	; 801DDDF8
801DDDF8	sw     v0, $0008(s0)
801DDDFC	lbu    a0, $0001(v1)
801DDE00	addiu  v0, v1, $0003
801DDE04	sw     v0, $0008(s0)
801DDE08	lb     v0, $0002(v1)
801DDE0C	nop

L1dde10:	; 801DDE10
801DDE10	sll    v0, v0, $08
801DDE14	or     v0, a0, v0
801DDE18	j      L1de308 [$801de308]
801DDE1C	sh     v0, $0054(s1)
801DDE20	lw     a0, $0008(s0)
801DDE24	andi   v0, fp, $0010
801DDE28	bne    v0, zero, L1dde58 [$801dde58]
801DDE2C	andi   v0, fp, $0020
801DDE30	lhu    v0, $0050(s1)
801DDE34	lhu    v1, $0000(a0)
801DDE38	nop
801DDE3C	addu   v0, v0, v1
801DDE40	sh     v0, $0050(s1)
801DDE44	lw     v0, $0008(s0)
801DDE48	addiu  a0, a0, $0002
801DDE4C	addiu  v0, v0, $0002

loop1dde50:	; 801DDE50
801DDE50	sw     v0, $0008(s0)

L1dde54:	; 801DDE54
801DDE54	andi   v0, fp, $0020

L1dde58:	; 801DDE58
801DDE58	bne    v0, zero, L1dde88 [$801dde88]
801DDE5C	andi   v0, fp, $0040
801DDE60	lhu    v0, $0052(s1)
801DDE64	lhu    v1, $0000(a0)
801DDE68	nop
801DDE6C	addu   v0, v0, v1
801DDE70	sh     v0, $0052(s1)
801DDE74	lw     v0, $0008(s0)
801DDE78	addiu  a0, a0, $0002
801DDE7C	addiu  v0, v0, $0002
801DDE80	sw     v0, $0008(s0)

L1dde84:	; 801DDE84
801DDE84	andi   v0, fp, $0040

L1dde88:	; 801DDE88
801DDE88	bne    v0, zero, L1de308 [$801de308]
801DDE8C	nop

L1dde90:	; 801DDE90
801DDE90	lhu    v0, $0054(s1)
801DDE94	lhu    v1, $0000(a0)
801DDE98	nop
801DDE9C	addu   v0, v0, v1
801DDEA0	sh     v0, $0054(s1)

L1ddea4:	; 801DDEA4
801DDEA4	lw     v0, $0008(s0)
801DDEA8	nop
801DDEAC	addiu  v0, v0, $0002
801DDEB0	j      L1de308 [$801de308]
801DDEB4	sw     v0, $0008(s0)
801DDEB8	lhu    a0, $0010(s0)
801DDEBC	lh     v0, $000a(s0)
801DDEC0	addiu  a0, a0, $0001

L1ddec4:	; 801DDEC4
801DDEC4	sll    a0, a0, $10
801DDEC8	sra    a0, a0, $10
801DDECC	mult   v0, a0
801DDED0	mflo   v1
801DDED4	lh     v0, $0012(s0)
801DDED8	nop

L1ddedc:	; 801DDEDC
801DDEDC	div    v1, v0
801DDEE0	bne    v0, zero, L1ddeec [$801ddeec]
801DDEE4	nop
801DDEE8	break   $01c00

L1ddeec:	; 801DDEEC
801DDEEC	addiu  at, zero, $ffff (=-$1)
801DDEF0	bne    v0, at, L1ddf04 [$801ddf04]
801DDEF4	lui    at, $8000
801DDEF8	bne    v1, at, L1ddf04 [$801ddf04]
801DDEFC	nop

L1ddf00:	; 801DDF00
801DDF00	break   $01800

L1ddf04:	; 801DDF04
801DDF04	mflo   v1
801DDF08	lhu    v0, $0004(s0)
801DDF0C	nop

L1ddf10:	; 801DDF10
801DDF10	addu   v0, v0, v1
801DDF14	sh     v0, $0050(s1)

L1ddf18:	; 801DDF18
801DDF18	lh     v0, $000c(s0)
801DDF1C	nop
801DDF20	mult   v0, a0
801DDF24	mflo   v1
801DDF28	lh     v0, $0012(s0)
801DDF2C	nop
801DDF30	div    v1, v0
801DDF34	bne    v0, zero, L1ddf40 [$801ddf40]
801DDF38	nop
801DDF3C	break   $01c00

L1ddf40:	; 801DDF40
801DDF40	addiu  at, zero, $ffff (=-$1)

L1ddf44:	; 801DDF44
801DDF44	bne    v0, at, L1ddf58 [$801ddf58]
801DDF48	lui    at, $8000
801DDF4C	bne    v1, at, L1ddf58 [$801ddf58]
801DDF50	nop
801DDF54	break   $01800

L1ddf58:	; 801DDF58
801DDF58	mflo   v1
801DDF5C	lhu    v0, $0006(s0)
801DDF60	nop
801DDF64	addu   v0, v0, v1
801DDF68	sh     v0, $0052(s1)

L1ddf6c:	; 801DDF6C
801DDF6C	lh     v0, $000e(s0)
801DDF70	nop
801DDF74	mult   v0, a0
801DDF78	mflo   v1
801DDF7C	lh     v0, $0012(s0)
801DDF80	nop
801DDF84	div    v1, v0
801DDF88	bne    v0, zero, L1ddf94 [$801ddf94]
801DDF8C	nop
801DDF90	break   $01c00

L1ddf94:	; 801DDF94
801DDF94	addiu  at, zero, $ffff (=-$1)
801DDF98	bne    v0, at, L1ddfac [$801ddfac]
801DDF9C	lui    at, $8000
801DDFA0	bne    v1, at, L1ddfac [$801ddfac]
801DDFA4	nop
801DDFA8	break   $01800

L1ddfac:	; 801DDFAC
801DDFAC	mflo   v1
801DDFB0	lhu    v0, $0008(s0)
801DDFB4	j      L1de150 [$801de150]
801DDFB8	addu   s6, s0, zero
801DDFBC	lh     a0, $000a(s0)
801DDFC0	lh     v0, $0050(s1)
801DDFC4	lh     a1, $0012(s0)
801DDFC8	subu   a0, a0, v0
801DDFCC	div    a0, a1
801DDFD0	bne    a1, zero, L1ddfdc [$801ddfdc]
801DDFD4	nop
801DDFD8	break   $01c00

L1ddfdc:	; 801DDFDC
801DDFDC	addiu  at, zero, $ffff (=-$1)
801DDFE0	bne    a1, at, L1ddff4 [$801ddff4]
801DDFE4	lui    at, $8000
801DDFE8	bne    a0, at, L1ddff4 [$801ddff4]
801DDFEC	nop
801DDFF0	break   $01800

L1ddff4:	; 801DDFF4
801DDFF4	mflo   a0
801DDFF8	lh     v1, $0052(s1)
801DDFFC	lh     v0, $000c(s0)
801DE000	nop
801DE004	subu   v0, v0, v1
801DE008	div    v0, a1
801DE00C	bne    a1, zero, L1de018 [$801de018]
801DE010	nop
801DE014	break   $01c00

L1de018:	; 801DE018
801DE018	addiu  at, zero, $ffff (=-$1)

loop1de01c:	; 801DE01C
801DE01C	bne    a1, at, L1de030 [$801de030]

L1de020:	; 801DE020
801DE020	lui    at, $8000
801DE024	bne    v0, at, L1de030 [$801de030]
801DE028	nop
801DE02C	break   $01800

L1de030:	; 801DE030
801DE030	mflo   a2
801DE034	lh     v0, $000e(s0)
801DE038	lh     v1, $0054(s1)

L1de03c:	; 801DE03C
801DE03C	nop
801DE040	subu   v0, v0, v1
801DE044	div    v0, a1
801DE048	bne    a1, zero, L1de054 [$801de054]
801DE04C	nop
801DE050	break   $01c00

L1de054:	; 801DE054
801DE054	addiu  at, zero, $ffff (=-$1)
801DE058	bne    a1, at, L1de06c [$801de06c]
801DE05C	lui    at, $8000
801DE060	bne    v0, at, L1de06c [$801de06c]
801DE064	nop
801DE068	break   $01800

L1de06c:	; 801DE06C
801DE06C	mflo   v1

L1de070:	; 801DE070
801DE070	addu   s6, s0, zero
801DE074	addu   a3, a0, zero
801DE078	sll    a0, a0, $10
801DE07C	addu   t0, a2, zero
801DE080	bne    a0, zero, L1de0c0 [$801de0c0]
801DE084	addu   t1, v1, zero
801DE088	sll    v0, a2, $10
801DE08C	bne    v0, zero, L1de0c0 [$801de0c0]
801DE090	sll    v0, v1, $10
801DE094	bne    v0, zero, L1de0c0 [$801de0c0]
801DE098	nop
801DE09C	lhu    v0, $000a(s0)

L1de0a0:	; 801DE0A0
801DE0A0	sh     a1, $0010(s0)
801DE0A4	sh     v0, $0050(s1)
801DE0A8	lhu    v0, $000c(s0)

L1de0ac:	; 801DE0AC
801DE0AC	nop
801DE0B0	sh     v0, $0052(s1)
801DE0B4	lhu    v0, $000e(s0)
801DE0B8	j      L1de308 [$801de308]
801DE0BC	sh     v0, $0054(s1)

L1de0c0:	; 801DE0C0
801DE0C0	lhu    v0, $0050(s1)
801DE0C4	lhu    v1, $0054(s1)
801DE0C8	addu   v0, a3, v0
801DE0CC	sh     v0, $0050(s1)
801DE0D0	lhu    v0, $0052(s1)
801DE0D4	addu   v1, t1, v1
801DE0D8	sh     v1, $0054(s1)
801DE0DC	addu   v0, t0, v0
801DE0E0	sh     v0, $0052(s1)
801DE0E4	j      L1de308 [$801de308]
801DE0E8	sh     zero, $0010(s0)
801DE0EC	lhu    v1, $0004(s0)
801DE0F0	lhu    v0, $000a(s0)
801DE0F4	nop
801DE0F8	addu   v1, v1, v0
801DE0FC	sh     v1, $0004(s0)
801DE100	lhu    v0, $0050(s1)
801DE104	nop
801DE108	addu   v0, v0, v1
801DE10C	sh     v0, $0050(s1)
801DE110	lhu    v1, $0006(s0)
801DE114	lhu    v0, $000c(s0)
801DE118	nop

L1de11c:	; 801DE11C
801DE11C	addu   v1, v1, v0

loop1de120:	; 801DE120
801DE120	sh     v1, $0006(s0)

L1de124:	; 801DE124
801DE124	lhu    v0, $0052(s1)

L1de128:	; 801DE128
801DE128	nop

L1de12c:	; 801DE12C
801DE12C	addu   v0, v0, v1
801DE130	sh     v0, $0052(s1)
801DE134	lhu    v1, $0008(s0)
801DE138	lhu    v0, $000e(s0)
801DE13C	nop

L1de140:	; 801DE140
801DE140	addu   v1, v1, v0
801DE144	sh     v1, $0008(s0)
801DE148	lhu    v0, $0054(s1)
801DE14C	addu   s6, s0, zero

L1de150:	; 801DE150
801DE150	addu   v0, v0, v1
801DE154	j      L1de308 [$801de308]
801DE158	sh     v0, $0054(s1)
801DE15C	lh     v1, $000a(s0)
801DE160	lw     v0, $0058(s1)
801DE164	nop
801DE168	subu   s3, v1, v0
801DE16C	mult   s3, s3
801DE170	lh     v1, $000c(s0)
801DE174	lw     v0, $005c(s1)
801DE178	mflo   a1
801DE17C	subu   s7, v1, v0
801DE180	nop
801DE184	mult   s7, s7
801DE188	lh     v1, $000e(s0)
801DE18C	lw     v0, $0060(s1)

loop1de190:	; 801DE190
801DE190	mflo   a0
801DE194	subu   s2, v1, v0
801DE198	nop
801DE19C	mult   s2, s2
801DE1A0	addu   a1, a1, a0

L1de1a4:	; 801DE1A4
801DE1A4	mflo   a0

L1de1a8:	; 801DE1A8
801DE1A8	jal    system_square_root [$80048af4]
801DE1AC	addu   a0, a1, a0
801DE1B0	subu   a0, zero, s3
801DE1B4	subu   a1, zero, s2
801DE1B8	jal    func4b1d4 [$8004b1d4]
801DE1BC	addiu  s4, v0, $0001
801DE1C0	lh     v1, $0052(s1)
801DE1C4	addu   s6, s0, zero
801DE1C8	subu   v0, v0, v1
801DE1CC	andi   a0, v0, $0fff
801DE1D0	slti   v0, a0, $0800
801DE1D4	bne    v0, zero, L1de1e0 [$801de1e0]
801DE1D8	addu   a1, v1, zero
801DE1DC	addiu  a0, a0, $f000 (=-$1000)

L1de1e0:	; 801DE1E0
801DE1E0	lh     v0, $0010(s0)
801DE1E4	lh     v1, $0008(s0)
801DE1E8	addu   v0, s4, v0
801DE1EC	mult   v0, v1
801DE1F0	mflo   v1
801DE1F4	lh     v0, $0004(s0)

L1de1f8:	; 801DE1F8
801DE1F8	nop
801DE1FC	div    v1, v0
801DE200	bne    v0, zero, L1de20c [$801de20c]
801DE204	nop
801DE208	break   $01c00

L1de20c:	; 801DE20C
801DE20C	addiu  at, zero, $ffff (=-$1)
801DE210	bne    v0, at, L1de224 [$801de224]
801DE214	lui    at, $8000
801DE218	bne    v1, at, L1de224 [$801de224]
801DE21C	nop

L1de220:	; 801DE220
801DE220	break   $01800

L1de224:	; 801DE224
801DE224	mflo   v1
801DE228	lh     v0, $0006(s0)

L1de22c:	; 801DE22C
801DE22C	nop
801DE230	addu   s0, v0, v1
801DE234	bgez   a0, L1de240 [$801de240]
801DE238	addu   v0, a0, zero
801DE23C	subu   v0, zero, v0

L1de240:	; 801DE240
801DE240	slt    v0, v0, s0
801DE244	bne    v0, zero, L1de258 [$801de258]

L1de248:	; 801DE248
801DE248	addu   v0, a1, a0
801DE24C	bgez   a0, L1de258 [$801de258]
801DE250	addu   v0, a1, s0
801DE254	subu   v0, a1, s0

L1de258:	; 801DE258
801DE258	sh     v0, $0052(s1)
801DE25C	andi   v1, fp, $000f
801DE260	ori    v0, zero, $0007
801DE264	bne    v1, v0, L1de2dc [$801de2dc]
801DE268	mult   s3, s3
801DE26C	mflo   v0
801DE270	nop
801DE274	nop

loop1de278:	; 801DE278
801DE278	mult   s2, s2
801DE27C	mflo   a0
801DE280	jal    system_square_root [$80048af4]
801DE284	addu   a0, v0, a0
801DE288	addu   a0, s7, zero
801DE28C	jal    func4b1d4 [$8004b1d4]
801DE290	addu   a1, v0, zero
801DE294	lh     v1, $0050(s1)
801DE298	nop
801DE29C	subu   v0, v0, v1
801DE2A0	andi   a0, v0, $0fff
801DE2A4	slti   v0, a0, $0800
801DE2A8	bne    v0, zero, L1de2b4 [$801de2b4]
801DE2AC	nop
801DE2B0	addiu  a0, a0, $f000 (=-$1000)

L1de2b4:	; 801DE2B4
801DE2B4	bgez   a0, L1de2c0 [$801de2c0]
801DE2B8	addu   v0, a0, zero
801DE2BC	subu   v0, zero, v0

L1de2c0:	; 801DE2C0
801DE2C0	slt    v0, v0, s0
801DE2C4	bne    v0, zero, L1de2d8 [$801de2d8]
801DE2C8	addu   v0, v1, a0
801DE2CC	bgez   a0, L1de2d8 [$801de2d8]
801DE2D0	addu   v0, v1, s0
801DE2D4	subu   v0, v1, s0

L1de2d8:	; 801DE2D8
801DE2D8	sh     v0, $0050(s1)

L1de2dc:	; 801DE2DC
801DE2DC	lh     v0, $0010(s6)
801DE2E0	nop
801DE2E4	addu   v1, v0, zero
801DE2E8	slti   v0, v0, $7d00
801DE2EC	beq    v0, zero, L1de3e4 [$801de3e4]
801DE2F0	ori    v0, zero, $0001
801DE2F4	lhu    v0, $0012(s6)
801DE2F8	nop
801DE2FC	addu   v0, v1, v0
801DE300	j      L1de3e0 [$801de3e0]
801DE304	sh     v0, $0010(s6)

L1de308:	; 801DE308
801DE308	lhu    v0, $0010(s0)
801DE30C	lh     v1, $0012(s0)
801DE310	addiu  v0, v0, $0001
801DE314	sh     v0, $0010(s0)
801DE318	sll    v0, v0, $10
801DE31C	sra    v0, v0, $10

L1de320:	; 801DE320
801DE320	slt    v0, v0, v1
801DE324	bne    v0, zero, L1de3c4 [$801de3c4]

L1de328:	; 801DE328
801DE328	nop
801DE32C	lbu    v0, $0001(s0)
801DE330	nop
801DE334	bne    v0, zero, L1de36c [$801de36c]
801DE338	nop
801DE33C	lbu    v0, $0003(s0)
801DE340	lw     t3, $0038(sp)
801DE344	nop
801DE348	bne    v0, t3, L1de354 [$801de354]
801DE34C	nop
801DE350	ori    s5, s5, $0002

L1de354:	; 801DE354
801DE354	ori    s5, s5, $0200
801DE358	lw     a0, $0028(sp)
801DE35C	jal    func1df7a8 [$801df7a8]
801DE360	addu   a1, s0, zero
801DE364	j      L1de3e0 [$801de3e0]
801DE368	sw     zero, $006c(s1)

L1de36c:	; 801DE36C
801DE36C	lbu    v0, $0003(s0)
801DE370	lw     t4, $0038(sp)
801DE374	nop
801DE378	bne    v0, t4, L1de384 [$801de384]
801DE37C	andi   v1, fp, $000f
801DE380	ori    s5, s5, $0004

L1de384:	; 801DE384
801DE384	sltiu  v0, v1, $0003
801DE388	beq    v0, zero, L1de3a0 [$801de3a0]
801DE38C	ori    s5, s5, $0400
801DE390	lw     v0, $0004(s0)
801DE394	sh     zero, $0010(s0)
801DE398	j      L1de3e0 [$801de3e0]
801DE39C	sw     v0, $0008(s0)

L1de3a0:	; 801DE3A0
801DE3A0	addiu  v0, zero, $ffff (=-$1)
801DE3A4	sh     v0, $0010(s0)
801DE3A8	ori    v0, zero, $0005
801DE3AC	bne    v1, v0, L1de3e4 [$801de3e4]
801DE3B0	ori    v0, zero, $0001
801DE3B4	sh     zero, $000a(s6)
801DE3B8	sh     zero, $000c(s6)
801DE3BC	j      L1de3e4 [$801de3e4]
801DE3C0	sh     zero, $000e(s6)

L1de3c4:	; 801DE3C4
801DE3C4	lbu    v0, $0003(s0)
801DE3C8	lw     t3, $0038(sp)
801DE3CC	nop
801DE3D0	bne    v0, t3, L1de3dc [$801de3dc]
801DE3D4	nop
801DE3D8	ori    s5, s5, $0001

L1de3dc:	; 801DE3DC
801DE3DC	ori    s5, s5, $0100

L1de3e0:	; 801DE3E0
801DE3E0	ori    v0, zero, $0001

L1de3e4:	; 801DE3E4
801DE3E4	sb     v0, $0001(s1)
801DE3E8	sb     v0, $0000(s1)

L1de3ec:	; 801DE3EC
801DE3EC	lw     a1, $0070(s1)
801DE3F0	nop
801DE3F4	beq    a1, zero, L1dead0 [$801dead0]
801DE3F8	addu   s0, a1, zero
801DE3FC	lbu    s2, $0002(s0)
801DE400	nop
801DE404	andi   v1, s2, $000f
801DE408	sltiu  v0, v1, $0006
801DE40C	beq    v0, zero, L1de9f0 [$801de9f0]
801DE410	sll    v0, v1, $02
801DE414	lui    at, $801e
801DE418	addu   at, at, v0
801DE41C	lw     v0, $c028(at)
801DE420	nop
801DE424	jr     v0 
801DE428	nop

801DE42C	lw     a0, $0008(s0)
801DE430	andi   v0, s2, $0010
801DE434	bne    v0, zero, L1de45c [$801de45c]
801DE438	andi   v0, s2, $0020
801DE43C	lh     v0, $0000(a0)
801DE440	nop
801DE444	sw     v0, $0058(s1)
801DE448	lw     v0, $0008(s0)
801DE44C	addiu  a0, a0, $0002
801DE450	addiu  v0, v0, $0002

L1de454:	; 801DE454
801DE454	sw     v0, $0008(s0)
801DE458	andi   v0, s2, $0020

L1de45c:	; 801DE45C
801DE45C	bne    v0, zero, L1de484 [$801de484]
801DE460	andi   v0, s2, $0040
801DE464	lh     v0, $0000(a0)
801DE468	nop
801DE46C	sw     v0, $005c(s1)
801DE470	lw     v0, $0008(s0)
801DE474	addiu  a0, a0, $0002
801DE478	addiu  v0, v0, $0002
801DE47C	sw     v0, $0008(s0)
801DE480	andi   v0, s2, $0040

L1de484:	; 801DE484
801DE484	bne    v0, zero, L1de9f0 [$801de9f0]
801DE488	nop
801DE48C	lh     v0, $0000(a0)
801DE490	nop
801DE494	sw     v0, $0060(s1)
801DE498	lw     v0, $0008(s0)
801DE49C	nop
801DE4A0	addiu  v0, v0, $0002
801DE4A4	j      L1de9f0 [$801de9f0]

L1de4a8:	; 801DE4A8
801DE4A8	sw     v0, $0008(s0)
801DE4AC	andi   v0, s2, $0010
801DE4B0	bne    v0, zero, L1de510 [$801de510]
801DE4B4	andi   v0, s2, $0020
801DE4B8	lw     v1, $0008(s0)
801DE4BC	nop
801DE4C0	addiu  v0, v1, $0001
801DE4C4	sw     v0, $0008(s0)
801DE4C8	lb     a0, $0000(v1)

L1de4cc:	; 801DE4CC
801DE4CC	addiu  v0, zero, $ff80 (=-$80)
801DE4D0	beq    a0, v0, L1de4e4 [$801de4e4]
801DE4D4	nop
801DE4D8	lw     v0, $0058(s1)
801DE4DC	j      L1de508 [$801de508]
801DE4E0	addu   v0, a0, v0

L1de4e4:	; 801DE4E4
801DE4E4	addiu  v0, v1, $0002
801DE4E8	sw     v0, $0008(s0)
801DE4EC	lbu    a0, $0001(v1)
801DE4F0	addiu  v0, v1, $0003
801DE4F4	sw     v0, $0008(s0)
801DE4F8	lb     v0, $0002(v1)
801DE4FC	nop
801DE500	sll    v0, v0, $08
801DE504	or     v0, a0, v0

L1de508:	; 801DE508
801DE508	sw     v0, $0058(s1)
801DE50C	andi   v0, s2, $0020

L1de510:	; 801DE510
801DE510	bne    v0, zero, L1de570 [$801de570]
801DE514	andi   v0, s2, $0040
801DE518	lw     v1, $0008(s0)
801DE51C	nop
801DE520	addiu  v0, v1, $0001
801DE524	sw     v0, $0008(s0)
801DE528	lb     a0, $0000(v1)
801DE52C	addiu  v0, zero, $ff80 (=-$80)
801DE530	beq    a0, v0, L1de544 [$801de544]
801DE534	nop
801DE538	lw     v0, $005c(s1)
801DE53C	j      L1de568 [$801de568]
801DE540	addu   v0, a0, v0

L1de544:	; 801DE544
801DE544	addiu  v0, v1, $0002
801DE548	sw     v0, $0008(s0)
801DE54C	lbu    a0, $0001(v1)
801DE550	addiu  v0, v1, $0003
801DE554	sw     v0, $0008(s0)
801DE558	lb     v0, $0002(v1)
801DE55C	nop
801DE560	sll    v0, v0, $08
801DE564	or     v0, a0, v0

L1de568:	; 801DE568
801DE568	sw     v0, $005c(s1)
801DE56C	andi   v0, s2, $0040

L1de570:	; 801DE570
801DE570	bne    v0, zero, L1de9f0 [$801de9f0]
801DE574	nop
801DE578	lw     v1, $0008(s0)
801DE57C	nop
801DE580	addiu  v0, v1, $0001
801DE584	sw     v0, $0008(s0)
801DE588	lb     a0, $0000(v1)
801DE58C	addiu  v0, zero, $ff80 (=-$80)
801DE590	beq    a0, v0, L1de5a4 [$801de5a4]
801DE594	nop
801DE598	lw     v0, $0060(s1)
801DE59C	j      L1de9ec [$801de9ec]
801DE5A0	addu   v0, a0, v0

L1de5a4:	; 801DE5A4
801DE5A4	addiu  v0, v1, $0002
801DE5A8	sw     v0, $0008(s0)
801DE5AC	lbu    a0, $0001(v1)
801DE5B0	addiu  v0, v1, $0003
801DE5B4	sw     v0, $0008(s0)
801DE5B8	lb     v0, $0002(v1)
801DE5BC	nop
801DE5C0	sll    v0, v0, $08
801DE5C4	j      L1de9ec [$801de9ec]
801DE5C8	or     v0, a0, v0
801DE5CC	lw     a0, $0008(s0)
801DE5D0	andi   v0, s2, $0010
801DE5D4	bne    v0, zero, L1de5fc [$801de5fc]
801DE5D8	nop
801DE5DC	lhu    v0, $0000(a0)
801DE5E0	nop
801DE5E4	sh     v0, $0010(sp)
801DE5E8	lw     v0, $0008(s0)
801DE5EC	addiu  a0, a0, $0002
801DE5F0	addiu  v0, v0, $0002
801DE5F4	j      L1de600 [$801de600]
801DE5F8	sw     v0, $0008(s0)

L1de5fc:	; 801DE5FC
801DE5FC	sh     zero, $0010(sp)

L1de600:	; 801DE600
801DE600	andi   v0, s2, $0020
801DE604	bne    v0, zero, L1de62c [$801de62c]
801DE608	nop
801DE60C	lhu    v0, $0000(a0)
801DE610	nop
801DE614	sh     v0, $0012(sp)
801DE618	lw     v0, $0008(s0)
801DE61C	addiu  a0, a0, $0002

L1de620:	; 801DE620
801DE620	addiu  v0, v0, $0002
801DE624	j      L1de630 [$801de630]
801DE628	sw     v0, $0008(s0)

L1de62c:	; 801DE62C
801DE62C	sh     zero, $0012(sp)

L1de630:	; 801DE630
801DE630	andi   v0, s2, $0040
801DE634	bne    v0, zero, L1de65c [$801de65c]
801DE638	nop
801DE63C	lhu    v0, $0000(a0)
801DE640	nop
801DE644	sh     v0, $0014(sp)
801DE648	lw     v0, $0008(s0)
801DE64C	nop
801DE650	addiu  v0, v0, $0002
801DE654	j      L1de660 [$801de660]
801DE658	sw     v0, $0008(s0)

L1de65c:	; 801DE65C
801DE65C	sh     zero, $0014(sp)

L1de660:	; 801DE660
801DE660	lh     v1, $0010(sp)
801DE664	lh     v0, $0048(s1)
801DE668	nop
801DE66C	mult   v1, v0
801DE670	lh     v1, $0012(sp)
801DE674	mflo   v0
801DE678	sra    v0, v0, $0c
801DE67C	sh     v0, $0010(sp)
801DE680	lh     v0, $004a(s1)
801DE684	nop
801DE688	mult   v1, v0
801DE68C	lh     v1, $0014(sp)
801DE690	mflo   v0
801DE694	sra    v0, v0, $0c
801DE698	sh     v0, $0012(sp)
801DE69C	lh     v0, $004c(s1)
801DE6A0	nop
801DE6A4	mult   v1, v0
801DE6A8	addiu  a1, sp, $0010
801DE6AC	lw     t4, $0030(sp)
801DE6B0	addiu  a2, sp, $0018
801DE6B4	addiu  a0, t4, $002c
801DE6B8	mflo   v0
801DE6BC	sra    v0, v0, $0c
801DE6C0	jal    system_matrix_vector_multiply_GTE [$80049b94]
801DE6C4	sh     v0, $0014(sp)
801DE6C8	lw     v0, $0018(sp)
801DE6CC	lw     t3, $0040(sp)
801DE6D0	nop
801DE6D4	mult   t3, v0
801DE6D8	lw     v1, $0058(s1)
801DE6DC	mflo   v0
801DE6E0	sra    v0, v0, $0c
801DE6E4	addu   v0, v0, v1
801DE6E8	sw     v0, $0058(s1)
801DE6EC	lw     v0, $001c(sp)
801DE6F0	nop
801DE6F4	mult   t3, v0
801DE6F8	lw     v1, $005c(s1)
801DE6FC	mflo   v0
801DE700	sra    v0, v0, $0c
801DE704	addu   v0, v0, v1
801DE708	sw     v0, $005c(s1)
801DE70C	lw     v0, $0020(sp)
801DE710	nop
801DE714	mult   t3, v0
801DE718	lw     v1, $0060(s1)
801DE71C	mflo   v0
801DE720	j      L1de9e8 [$801de9e8]
801DE724	sra    v0, v0, $0c
801DE728	lhu    a0, $0010(s0)
801DE72C	lh     v0, $000a(s0)
801DE730	addiu  a0, a0, $0001
801DE734	sll    a0, a0, $10
801DE738	sra    a0, a0, $10
801DE73C	mult   v0, a0
801DE740	mflo   v1
801DE744	lh     v0, $0012(s0)
801DE748	nop
801DE74C	div    v1, v0

L1de750:	; 801DE750
801DE750	bne    v0, zero, L1de75c [$801de75c]
801DE754	nop
801DE758	break   $01c00

L1de75c:	; 801DE75C
801DE75C	addiu  at, zero, $ffff (=-$1)
801DE760	bne    v0, at, L1de774 [$801de774]
801DE764	lui    at, $8000
801DE768	bne    v1, at, L1de774 [$801de774]
801DE76C	nop
801DE770	break   $01800

L1de774:	; 801DE774
801DE774	mflo   v1
801DE778	lh     v0, $0004(s0)
801DE77C	nop
801DE780	addu   v0, v0, v1
801DE784	sw     v0, $0058(s1)
801DE788	lh     v0, $000c(s0)
801DE78C	nop
801DE790	mult   v0, a0
801DE794	mflo   v1
801DE798	lh     v0, $0012(s0)
801DE79C	nop
801DE7A0	div    v1, v0
801DE7A4	bne    v0, zero, L1de7b0 [$801de7b0]
801DE7A8	nop
801DE7AC	break   $01c00

L1de7b0:	; 801DE7B0
801DE7B0	addiu  at, zero, $ffff (=-$1)
801DE7B4	bne    v0, at, L1de7c8 [$801de7c8]
801DE7B8	lui    at, $8000
801DE7BC	bne    v1, at, L1de7c8 [$801de7c8]
801DE7C0	nop
801DE7C4	break   $01800

L1de7c8:	; 801DE7C8
801DE7C8	mflo   v1
801DE7CC	lh     v0, $0006(s0)
801DE7D0	nop
801DE7D4	addu   v0, v0, v1
801DE7D8	sw     v0, $005c(s1)
801DE7DC	lh     v0, $000e(s0)

L1de7e0:	; 801DE7E0
801DE7E0	nop
801DE7E4	mult   v0, a0
801DE7E8	mflo   v1
801DE7EC	lh     v0, $0012(s0)
801DE7F0	nop
801DE7F4	div    v1, v0
801DE7F8	bne    v0, zero, L1de804 [$801de804]
801DE7FC	nop
801DE800	break   $01c00

L1de804:	; 801DE804
801DE804	addiu  at, zero, $ffff (=-$1)
801DE808	bne    v0, at, L1de81c [$801de81c]
801DE80C	lui    at, $8000
801DE810	bne    v1, at, L1de81c [$801de81c]
801DE814	nop
801DE818	break   $01800

L1de81c:	; 801DE81C
801DE81C	mflo   v1
801DE820	lh     v0, $0008(s0)
801DE824	j      L1de9e8 [$801de9e8]
801DE828	addu   s6, s0, zero
801DE82C	lh     a0, $000a(s0)
801DE830	lw     v0, $0058(s1)
801DE834	lh     a1, $0012(s0)
801DE838	subu   a0, a0, v0
801DE83C	div    a0, a1
801DE840	bne    a1, zero, L1de84c [$801de84c]
801DE844	nop
801DE848	break   $01c00

L1de84c:	; 801DE84C
801DE84C	addiu  at, zero, $ffff (=-$1)
801DE850	bne    a1, at, L1de864 [$801de864]
801DE854	lui    at, $8000
801DE858	bne    a0, at, L1de864 [$801de864]
801DE85C	nop

L1de860:	; 801DE860
801DE860	break   $01800

L1de864:	; 801DE864
801DE864	mflo   a0

L1de868:	; 801DE868
801DE868	lw     v1, $005c(s1)
801DE86C	lh     v0, $000c(s0)
801DE870	nop
801DE874	subu   v0, v0, v1
801DE878	div    v0, a1
801DE87C	bne    a1, zero, L1de888 [$801de888]
801DE880	nop
801DE884	break   $01c00

L1de888:	; 801DE888
801DE888	addiu  at, zero, $ffff (=-$1)
801DE88C	bne    a1, at, L1de8a0 [$801de8a0]
801DE890	lui    at, $8000
801DE894	bne    v0, at, L1de8a0 [$801de8a0]
801DE898	nop
801DE89C	break   $01800

L1de8a0:	; 801DE8A0
801DE8A0	mflo   a2
801DE8A4	lh     v0, $000e(s0)
801DE8A8	lw     v1, $0060(s1)
801DE8AC	nop
801DE8B0	subu   v0, v0, v1
801DE8B4	div    v0, a1
801DE8B8	bne    a1, zero, L1de8c4 [$801de8c4]
801DE8BC	nop
801DE8C0	break   $01c00

L1de8c4:	; 801DE8C4
801DE8C4	addiu  at, zero, $ffff (=-$1)
801DE8C8	bne    a1, at, L1de8dc [$801de8dc]
801DE8CC	lui    at, $8000
801DE8D0	bne    v0, at, L1de8dc [$801de8dc]
801DE8D4	nop
801DE8D8	break   $01800

L1de8dc:	; 801DE8DC
801DE8DC	mflo   v1
801DE8E0	addu   s6, s0, zero
801DE8E4	addu   a3, a0, zero
801DE8E8	sll    a0, a0, $10

L1de8ec:	; 801DE8EC
801DE8EC	addu   t0, a2, zero
801DE8F0	bne    a0, zero, L1de934 [$801de934]
801DE8F4	addu   t1, v1, zero
801DE8F8	sll    v0, a2, $10
801DE8FC	bne    v0, zero, L1de938 [$801de938]
801DE900	sll    v0, a3, $10
801DE904	sll    v0, v1, $10
801DE908	bne    v0, zero, L1de938 [$801de938]
801DE90C	sll    v0, a3, $10
801DE910	lh     v0, $000a(s0)
801DE914	sh     a1, $0010(s0)
801DE918	sw     v0, $0058(s1)
801DE91C	lh     v0, $000c(s0)
801DE920	nop
801DE924	sw     v0, $005c(s1)
801DE928	lh     v0, $000e(s0)
801DE92C	j      L1de9f0 [$801de9f0]
801DE930	sw     v0, $0060(s1)

L1de934:	; 801DE934
801DE934	sll    v0, a3, $10

L1de938:	; 801DE938
801DE938	lw     v1, $0058(s1)
801DE93C	sra    v0, v0, $10
801DE940	addu   v0, v0, v1
801DE944	sw     v0, $0058(s1)
801DE948	sll    v0, t0, $10
801DE94C	lw     v1, $005c(s1)
801DE950	sra    v0, v0, $10
801DE954	addu   v0, v0, v1

L1de958:	; 801DE958
801DE958	sw     v0, $005c(s1)
801DE95C	sll    v0, t1, $10
801DE960	lw     v1, $0060(s1)

L1de964:	; 801DE964
801DE964	sra    v0, v0, $10
801DE968	addu   v0, v0, v1
801DE96C	sw     v0, $0060(s1)
801DE970	j      L1de9f0 [$801de9f0]
801DE974	sh     zero, $0010(s0)
801DE978	lhu    v0, $0004(s0)
801DE97C	lhu    v1, $000a(s0)
801DE980	nop
801DE984	addu   v0, v0, v1
801DE988	sh     v0, $0004(s0)
801DE98C	sll    v0, v0, $10
801DE990	lw     v1, $0058(s1)
801DE994	sra    v0, v0, $10
801DE998	addu   v0, v0, v1
801DE99C	sw     v0, $0058(s1)
801DE9A0	lhu    v0, $0006(s0)
801DE9A4	lhu    v1, $000c(s0)
801DE9A8	nop

L1de9ac:	; 801DE9AC
801DE9AC	addu   v0, v0, v1
801DE9B0	sh     v0, $0006(s0)
801DE9B4	sll    v0, v0, $10
801DE9B8	lw     v1, $005c(s1)
801DE9BC	sra    v0, v0, $10
801DE9C0	addu   v0, v0, v1
801DE9C4	sw     v0, $005c(s1)
801DE9C8	lhu    v0, $0008(s0)
801DE9CC	lhu    v1, $000e(s0)
801DE9D0	addu   s6, s0, zero
801DE9D4	addu   v0, v0, v1
801DE9D8	sh     v0, $0008(s0)
801DE9DC	sll    v0, v0, $10
801DE9E0	lw     v1, $0060(s1)
801DE9E4	sra    v0, v0, $10

L1de9e8:	; 801DE9E8
801DE9E8	addu   v0, v0, v1

L1de9ec:	; 801DE9EC
801DE9EC	sw     v0, $0060(s1)

L1de9f0:	; 801DE9F0
801DE9F0	lhu    v0, $0010(s0)
801DE9F4	lh     v1, $0012(s0)
801DE9F8	addiu  v0, v0, $0001
801DE9FC	sh     v0, $0010(s0)
801DEA00	sll    v0, v0, $10
801DEA04	sra    v0, v0, $10
801DEA08	slt    v0, v0, v1
801DEA0C	bne    v0, zero, L1deaac [$801deaac]
801DEA10	nop
801DEA14	lbu    v0, $0001(s0)
801DEA18	nop
801DEA1C	bne    v0, zero, L1dea54 [$801dea54]
801DEA20	nop
801DEA24	lbu    v0, $0003(s0)
801DEA28	lw     t4, $0038(sp)
801DEA2C	nop
801DEA30	bne    v0, t4, L1dea3c [$801dea3c]
801DEA34	nop
801DEA38	ori    s5, s5, $0002

L1dea3c:	; 801DEA3C
801DEA3C	ori    s5, s5, $0200
801DEA40	lw     a0, $0028(sp)
801DEA44	jal    func1df7a8 [$801df7a8]
801DEA48	addu   a1, s0, zero
801DEA4C	j      L1deac8 [$801deac8]
801DEA50	sw     zero, $0070(s1)

L1dea54:	; 801DEA54
801DEA54	lbu    v0, $0003(s0)
801DEA58	lw     t3, $0038(sp)
801DEA5C	nop
801DEA60	bne    v0, t3, L1dea6c [$801dea6c]
801DEA64	andi   v1, s2, $000f
801DEA68	ori    s5, s5, $0004

L1dea6c:	; 801DEA6C
801DEA6C	sltiu  v0, v1, $0003
801DEA70	beq    v0, zero, L1dea88 [$801dea88]
801DEA74	ori    s5, s5, $0400
801DEA78	lw     v0, $0004(s0)
801DEA7C	sh     zero, $0010(s0)
801DEA80	j      L1deac8 [$801deac8]
801DEA84	sw     v0, $0008(s0)

L1dea88:	; 801DEA88
801DEA88	addiu  v0, zero, $ffff (=-$1)
801DEA8C	sh     v0, $0010(s0)
801DEA90	ori    v0, zero, $0005
801DEA94	bne    v1, v0, L1deacc [$801deacc]
801DEA98	ori    v0, zero, $0001
801DEA9C	sh     zero, $000a(s6)
801DEAA0	sh     zero, $000c(s6)
801DEAA4	j      L1deacc [$801deacc]

L1deaa8:	; 801DEAA8
801DEAA8	sh     zero, $000e(s6)

L1deaac:	; 801DEAAC
801DEAAC	lbu    v0, $0003(s0)
801DEAB0	lw     t4, $0038(sp)
801DEAB4	nop
801DEAB8	bne    v0, t4, L1deac4 [$801deac4]
801DEABC	nop
801DEAC0	ori    s5, s5, $0001

L1deac4:	; 801DEAC4
801DEAC4	ori    s5, s5, $0100

L1deac8:	; 801DEAC8
801DEAC8	ori    v0, zero, $0001

L1deacc:	; 801DEACC
801DEACC	sb     v0, $0000(s1)

L1dead0:	; 801DEAD0
801DEAD0	lw     a1, $0074(s1)
801DEAD4	nop
801DEAD8	beq    a1, zero, L1deeb0 [$801deeb0]
801DEADC	addu   s0, a1, zero
801DEAE0	lbu    v0, $0002(s0)
801DEAE4	nop
801DEAE8	andi   t2, v0, $000f
801DEAEC	andi   v1, t2, $00ff
801DEAF0	ori    v0, zero, $0004
801DEAF4	beq    v1, v0, L1dec2c [$801dec2c]
801DEAF8	slti   v0, v1, $0005
801DEAFC	beq    v0, zero, L1deb14 [$801deb14]
801DEB00	ori    v0, zero, $0003
801DEB04	beq    v1, v0, L1deb28 [$801deb28]
801DEB08	nop
801DEB0C	j      L1dede8 [$801dede8]
801DEB10	nop

L1deb14:	; 801DEB14
801DEB14	ori    v0, zero, $0005
801DEB18	beq    v1, v0, L1ded7c [$801ded7c]
801DEB1C	nop
801DEB20	j      L1dede8 [$801dede8]
801DEB24	nop

L1deb28:	; 801DEB28
801DEB28	lhu    a0, $0010(s0)
801DEB2C	lh     v0, $000a(s0)
801DEB30	addiu  a0, a0, $0001
801DEB34	sll    a0, a0, $10
801DEB38	sra    a0, a0, $10
801DEB3C	mult   v0, a0
801DEB40	mflo   v1
801DEB44	lh     v0, $0012(s0)
801DEB48	nop
801DEB4C	div    v1, v0
801DEB50	bne    v0, zero, L1deb5c [$801deb5c]
801DEB54	nop
801DEB58	break   $01c00

L1deb5c:	; 801DEB5C
801DEB5C	addiu  at, zero, $ffff (=-$1)
801DEB60	bne    v0, at, L1deb74 [$801deb74]
801DEB64	lui    at, $8000
801DEB68	bne    v1, at, L1deb74 [$801deb74]
801DEB6C	nop
801DEB70	break   $01800

L1deb74:	; 801DEB74
801DEB74	mflo   v1
801DEB78	lhu    v0, $0004(s0)
801DEB7C	nop
801DEB80	addu   v0, v0, v1
801DEB84	sh     v0, $0048(s1)
801DEB88	lh     v0, $000c(s0)
801DEB8C	nop
801DEB90	mult   v0, a0
801DEB94	mflo   v1
801DEB98	lh     v0, $0012(s0)
801DEB9C	nop
801DEBA0	div    v1, v0
801DEBA4	bne    v0, zero, L1debb0 [$801debb0]
801DEBA8	nop
801DEBAC	break   $01c00

L1debb0:	; 801DEBB0
801DEBB0	addiu  at, zero, $ffff (=-$1)
801DEBB4	bne    v0, at, L1debc8 [$801debc8]
801DEBB8	lui    at, $8000
801DEBBC	bne    v1, at, L1debc8 [$801debc8]
801DEBC0	nop
801DEBC4	break   $01800

L1debc8:	; 801DEBC8
801DEBC8	mflo   v1
801DEBCC	lhu    v0, $0006(s0)
801DEBD0	nop
801DEBD4	addu   v0, v0, v1
801DEBD8	sh     v0, $004a(s1)
801DEBDC	lh     v0, $000e(s0)
801DEBE0	nop
801DEBE4	mult   v0, a0
801DEBE8	mflo   v1
801DEBEC	lh     v0, $0012(s0)
801DEBF0	nop
801DEBF4	div    v1, v0
801DEBF8	bne    v0, zero, L1dec04 [$801dec04]
801DEBFC	nop
801DEC00	break   $01c00

L1dec04:	; 801DEC04
801DEC04	addiu  at, zero, $ffff (=-$1)
801DEC08	bne    v0, at, L1dec1c [$801dec1c]
801DEC0C	lui    at, $8000

L1dec10:	; 801DEC10
801DEC10	bne    v1, at, L1dec1c [$801dec1c]

L1dec14:	; 801DEC14
801DEC14	nop
801DEC18	break   $01800

L1dec1c:	; 801DEC1C
801DEC1C	mflo   v1

L1dec20:	; 801DEC20
801DEC20	lhu    v0, $0008(s0)
801DEC24	j      L1dede0 [$801dede0]
801DEC28	addu   s6, s0, zero

L1dec2c:	; 801DEC2C
801DEC2C	lh     a0, $000a(s0)
801DEC30	lh     v0, $0004(s0)
801DEC34	lh     a1, $0012(s0)
801DEC38	subu   a0, a0, v0
801DEC3C	div    a0, a1
801DEC40	bne    a1, zero, L1dec4c [$801dec4c]
801DEC44	nop
801DEC48	break   $01c00

L1dec4c:	; 801DEC4C
801DEC4C	addiu  at, zero, $ffff (=-$1)
801DEC50	bne    a1, at, L1dec64 [$801dec64]
801DEC54	lui    at, $8000
801DEC58	bne    a0, at, L1dec64 [$801dec64]
801DEC5C	nop

L1dec60:	; 801DEC60
801DEC60	break   $01800

L1dec64:	; 801DEC64
801DEC64	mflo   a0
801DEC68	lh     v1, $0006(s0)
801DEC6C	lh     v0, $000c(s0)
801DEC70	nop
801DEC74	subu   v0, v0, v1
801DEC78	div    v0, a1
801DEC7C	bne    a1, zero, L1dec88 [$801dec88]
801DEC80	nop
801DEC84	break   $01c00

L1dec88:	; 801DEC88
801DEC88	addiu  at, zero, $ffff (=-$1)
801DEC8C	bne    a1, at, L1deca0 [$801deca0]
801DEC90	lui    at, $8000
801DEC94	bne    v0, at, L1deca0 [$801deca0]
801DEC98	nop
801DEC9C	break   $01800

L1deca0:	; 801DECA0
801DECA0	mflo   a2
801DECA4	lh     v0, $000e(s0)
801DECA8	lh     v1, $0008(s0)

L1decac:	; 801DECAC
801DECAC	nop
801DECB0	subu   v0, v0, v1
801DECB4	div    v0, a1
801DECB8	bne    a1, zero, L1decc4 [$801decc4]
801DECBC	nop
801DECC0	break   $01c00

L1decc4:	; 801DECC4
801DECC4	addiu  at, zero, $ffff (=-$1)
801DECC8	bne    a1, at, L1decdc [$801decdc]
801DECCC	lui    at, $8000
801DECD0	bne    v0, at, L1decdc [$801decdc]
801DECD4	nop
801DECD8	break   $01800

L1decdc:	; 801DECDC
801DECDC	mflo   v1
801DECE0	addu   s6, s0, zero
801DECE4	addu   a3, a0, zero
801DECE8	sll    a0, a0, $10
801DECEC	addu   t0, a2, zero
801DECF0	bne    a0, zero, L1ded30 [$801ded30]
801DECF4	addu   t1, v1, zero
801DECF8	sll    v0, a2, $10
801DECFC	bne    v0, zero, L1ded30 [$801ded30]
801DED00	sll    v0, v1, $10
801DED04	bne    v0, zero, L1ded30 [$801ded30]
801DED08	nop
801DED0C	lhu    v0, $000a(s0)
801DED10	sh     a1, $0010(s0)
801DED14	sh     v0, $0048(s1)
801DED18	lhu    v0, $000c(s0)
801DED1C	nop
801DED20	sh     v0, $004a(s1)
801DED24	lhu    v0, $000e(s0)
801DED28	j      L1dede8 [$801dede8]
801DED2C	sh     v0, $004c(s1)

L1ded30:	; 801DED30
801DED30	lhu    v0, $0004(s6)
801DED34	lhu    v1, $0006(s6)
801DED38	addu   v0, a3, v0
801DED3C	sh     v0, $0004(s6)
801DED40	lhu    v0, $0008(s6)
801DED44	addu   v1, t0, v1
801DED48	sh     v1, $0006(s6)
801DED4C	lhu    v1, $0004(s6)
801DED50	addu   v0, t1, v0
801DED54	sh     v0, $0008(s6)
801DED58	sh     v1, $0048(s1)
801DED5C	lhu    v0, $0006(s6)
801DED60	nop
801DED64	sh     v0, $004a(s1)
801DED68	lhu    v0, $0008(s6)
801DED6C	nop
801DED70	sh     v0, $004c(s1)
801DED74	j      L1dede8 [$801dede8]
801DED78	sh     zero, $0010(s0)

L1ded7c:	; 801DED7C
801DED7C	lhu    v1, $0004(s0)
801DED80	lhu    v0, $000a(s0)
801DED84	nop
801DED88	addu   v1, v1, v0
801DED8C	sh     v1, $0004(s0)
801DED90	lhu    v0, $0048(s1)
801DED94	nop
801DED98	addu   v0, v0, v1
801DED9C	sh     v0, $0048(s1)
801DEDA0	lhu    v1, $0006(s0)
801DEDA4	lhu    v0, $000c(s0)
801DEDA8	nop
801DEDAC	addu   v1, v1, v0
801DEDB0	sh     v1, $0006(s0)
801DEDB4	lhu    v0, $004a(s1)
801DEDB8	nop
801DEDBC	addu   v0, v0, v1
801DEDC0	sh     v0, $004a(s1)
801DEDC4	lhu    v1, $0008(s0)
801DEDC8	lhu    v0, $000e(s0)
801DEDCC	nop
801DEDD0	addu   v1, v1, v0
801DEDD4	sh     v1, $0008(s0)

L1dedd8:	; 801DEDD8
801DEDD8	lhu    v0, $004c(s1)
801DEDDC	addu   s6, s0, zero

L1dede0:	; 801DEDE0
801DEDE0	addu   v0, v0, v1
801DEDE4	sh     v0, $004c(s1)

L1dede8:	; 801DEDE8
801DEDE8	lhu    v0, $0010(s0)
801DEDEC	lh     v1, $0012(s0)
801DEDF0	addiu  v0, v0, $0001
801DEDF4	sh     v0, $0010(s0)
801DEDF8	sll    v0, v0, $10
801DEDFC	sra    v0, v0, $10
801DEE00	slt    v0, v0, v1
801DEE04	bne    v0, zero, L1dee88 [$801dee88]
801DEE08	nop
801DEE0C	lbu    v0, $0001(s0)
801DEE10	nop
801DEE14	bne    v0, zero, L1dee4c [$801dee4c]
801DEE18	nop
801DEE1C	lbu    v0, $0003(s0)
801DEE20	lw     t3, $0038(sp)
801DEE24	nop
801DEE28	bne    v0, t3, L1dee34 [$801dee34]
801DEE2C	nop
801DEE30	ori    s5, s5, $0002

L1dee34:	; 801DEE34
801DEE34	ori    s5, s5, $0200
801DEE38	lw     a0, $0028(sp)
801DEE3C	jal    func1df7a8 [$801df7a8]
801DEE40	addu   a1, s0, zero
801DEE44	j      L1deea4 [$801deea4]
801DEE48	sw     zero, $0074(s1)

L1dee4c:	; 801DEE4C
801DEE4C	lbu    v0, $0003(s0)
801DEE50	lw     t4, $0038(sp)

L1dee54:	; 801DEE54
801DEE54	nop

L1dee58:	; 801DEE58
801DEE58	bne    v0, t4, L1dee64 [$801dee64]

L1dee5c:	; 801DEE5C
801DEE5C	andi   v1, t2, $00ff
801DEE60	ori    s5, s5, $0004

L1dee64:	; 801DEE64
801DEE64	addiu  v0, zero, $ffff (=-$1)
801DEE68	sh     v0, $0010(s0)
801DEE6C	ori    v0, zero, $0005
801DEE70	bne    v1, v0, L1deea4 [$801deea4]
801DEE74	ori    s5, s5, $0400
801DEE78	sh     zero, $000a(s6)
801DEE7C	sh     zero, $000c(s6)
801DEE80	j      L1deea4 [$801deea4]
801DEE84	sh     zero, $000e(s6)

L1dee88:	; 801DEE88
801DEE88	lbu    v0, $0003(s0)
801DEE8C	lw     t3, $0038(sp)
801DEE90	nop
801DEE94	bne    v0, t3, L1deea0 [$801deea0]
801DEE98	nop
801DEE9C	ori    s5, s5, $0001

L1deea0:	; 801DEEA0
801DEEA0	ori    s5, s5, $0100

L1deea4:	; 801DEEA4
801DEEA4	ori    v0, zero, $0001

L1deea8:	; 801DEEA8
801DEEA8	sb     v0, $0001(s1)
801DEEAC	sb     v0, $0000(s1)

L1deeb0:	; 801DEEB0
801DEEB0	addiu  s1, s1, $007c
801DEEB4	lw     t3, $0030(sp)
801DEEB8	lw     t4, $0048(sp)
801DEEBC	addiu  t3, t3, $007c
801DEEC0	sw     t3, $0030(sp)
801DEEC4	lw     t3, $0050(sp)
801DEEC8	addiu  t4, t4, $0001
801DEECC	sltu   v0, t4, t3
801DEED0	bne    v0, zero, L1ddc4c [$801ddc4c]
801DEED4	sw     t4, $0048(sp)

L1deed8:	; 801DEED8
801DEED8	addu   v0, s5, zero
801DEEDC	lw     ra, $00b4(sp)
801DEEE0	lw     fp, $00b0(sp)
801DEEE4	lw     s7, $00ac(sp)
801DEEE8	lw     s6, $00a8(sp)
801DEEEC	lw     s5, $00a4(sp)
801DEEF0	lw     s4, $00a0(sp)
801DEEF4	lw     s3, $009c(sp)
801DEEF8	lw     s2, $0098(sp)
801DEEFC	lw     s1, $0094(sp)
801DEF00	lw     s0, $0090(sp)
801DEF04	addiu  sp, sp, $00b8
801DEF08	jr     ra 
801DEF0C	nop



////////////////////////////////
// func1def10
801DEF10-801DF0B0
////////////////////////////////



////////////////////////////////
// func1df0b4
801DF0B4-801DF528
////////////////////////////////



////////////////////////////////
// func1df52c
801DF52C-801DF5F0
////////////////////////////////



func1df5f4:	; 801DF5F4
801DF5F4	addiu  sp, sp, $ffe0 (=-$20)
801DF5F8	sw     s1, $0014(sp)
801DF5FC	addu   s1, a0, zero
801DF600	sw     s0, $0010(sp)
801DF604	addu   s0, a1, zero
801DF608	blez   s0, L1df63c [$801df63c]
801DF60C	sw     ra, $0018(sp)
801DF610	ori    a0, zero, $0004
801DF614	addu   a1, zero, zero
801DF618	jal    func322bc [$800322bc]
801DF61C	sh     s0, $0006(s1)
801DF620	sll    a0, s0, $02
801DF624	addu   a0, a0, s0
801DF628	sll    a0, a0, $02
801DF62C	jal    system_memory_allocate [$800319ec]
801DF630	addu   a1, zero, zero
801DF634	bne    v0, zero, L1df644 [$801df644]
801DF638	sw     v0, $0000(s1)

L1df63c:	; 801DF63C
801DF63C	j      L1df650 [$801df650]

L1df640:	; 801DF640
801DF640	addu   v0, zero, zero

L1df644:	; 801DF644
801DF644	jal    func1df6a8 [$801df6a8]
801DF648	addu   a0, s1, zero
801DF64C	addu   v0, s1, zero

L1df650:	; 801DF650
801DF650	lw     ra, $0018(sp)
801DF654	lw     s1, $0014(sp)
801DF658	lw     s0, $0010(sp)
801DF65C	addiu  sp, sp, $0020
801DF660	jr     ra 
801DF664	nop


func1df668:	; 801DF668
801DF668	addiu  sp, sp, $ffe8 (=-$18)
801DF66C	sw     s0, $0010(sp)
801DF670	addu   s0, a0, zero
801DF674	sw     ra, $0014(sp)
801DF678	lw     a0, $0000(s0)
801DF67C	nop
801DF680	beq    a0, zero, L1df690 [$801df690]
801DF684	sh     zero, $0004(s0)
801DF688	jal    func31f0c [$80031f0c]
801DF68C	nop

L1df690:	; 801DF690
801DF690	sw     zero, $0000(s0)
801DF694	lw     ra, $0014(sp)
801DF698	lw     s0, $0010(sp)
801DF69C	addiu  sp, sp, $0018
801DF6A0	jr     ra 
801DF6A4	nop


func1df6a8:	; 801DF6A8
801DF6A8	lw     v0, $0000(a0)
801DF6AC	nop
801DF6B0	beq    v0, zero, L1df6e4 [$801df6e4]
801DF6B4	addiu  sp, sp, $fff8 (=-$8)
801DF6B8	addu   a1, v0, zero
801DF6BC	lhu    v0, $0006(a0)
801DF6C0	addu   v1, zero, zero
801DF6C4	blez   v0, L1df6e4 [$801df6e4]
801DF6C8	sh     zero, $0004(a0)

loop1df6cc:	; 801DF6CC
801DF6CC	sb     zero, $0000(a1)
801DF6D0	lhu    v0, $0006(a0)
801DF6D4	addiu  v1, v1, $0001
801DF6D8	slt    v0, v1, v0
801DF6DC	bne    v0, zero, loop1df6cc [$801df6cc]
801DF6E0	addiu  a1, a1, $0014

L1df6e4:	; 801DF6E4
801DF6E4	addiu  sp, sp, $0008
801DF6E8	jr     ra 
801DF6EC	nop


func1df6f0:	; 801DF6F0
801DF6F0	lhu    v1, $0004(a0)
801DF6F4	lhu    v0, $0006(a0)
801DF6F8	nop
801DF6FC	sltu   v0, v1, v0
801DF700	beq    v0, zero, L1df79c [$801df79c]
801DF704	sll    v0, v1, $02
801DF708	addu   v0, v0, v1
801DF70C	lw     v1, $0000(a0)
801DF710	sll    v0, v0, $02
801DF714	addu   a3, v0, v1
801DF718	lbu    v0, $0000(a3)
801DF71C	nop
801DF720	bne    v0, zero, L1df7a0 [$801df7a0]
801DF724	addu   v0, zero, zero
801DF728	lhu    v0, $0004(a0)
801DF72C	lhu    a1, $0006(a0)
801DF730	addiu  v0, v0, $0001
801DF734	sh     v0, $0004(a0)
801DF738	lhu    v1, $0004(a0)
801DF73C	nop
801DF740	sltu   v0, v1, a1
801DF744	beq    v0, zero, L1df7a0 [$801df7a0]
801DF748	addu   v0, a3, zero
801DF74C	lw     a2, $0000(a0)
801DF750	sll    v0, v1, $02

loop1df754:	; 801DF754
801DF754	addu   v0, v0, v1
801DF758	sll    v0, v0, $02
801DF75C	addu   v0, v0, a2
801DF760	lbu    v0, $0000(v0)
801DF764	nop
801DF768	beq    v0, zero, L1df7a0 [$801df7a0]
801DF76C	addu   v0, a3, zero
801DF770	lhu    v0, $0004(a0)
801DF774	nop
801DF778	addiu  v0, v0, $0001
801DF77C	sh     v0, $0004(a0)
801DF780	lhu    v1, $0004(a0)
801DF784	nop
801DF788	sltu   v0, v1, a1
801DF78C	bne    v0, zero, loop1df754 [$801df754]
801DF790	sll    v0, v1, $02
801DF794	j      L1df7a0 [$801df7a0]
801DF798	addu   v0, a3, zero

L1df79c:	; 801DF79C
801DF79C	addu   v0, zero, zero

L1df7a0:	; 801DF7A0
801DF7A0	jr     ra 
801DF7A4	nop



////////////////////////////////
// func1df7a8
801DF7A8-801DF7F0
////////////////////////////////



func1df7f4:	; 801DF7F4
801DF7F4	addiu  sp, sp, $ffb8 (=-$48)
801DF7F8	sw     s4, $0030(sp)
801DF7FC	addu   s4, a0, zero
801DF800	sw     s0, $0020(sp)
801DF804	addu   s0, a1, zero
801DF808	sw     s1, $0024(sp)
801DF80C	addu   s1, a2, zero
801DF810	sw     ra, $0044(sp)
801DF814	sw     fp, $0040(sp)
801DF818	sw     s7, $003c(sp)

L1df81c:	; 801DF81C
801DF81C	sw     s6, $0038(sp)
801DF820	sw     s5, $0034(sp)
801DF824	sw     s3, $002c(sp)
801DF828	sw     s2, $0028(sp)
801DF82C	lhu    v0, $0006(s1)
801DF830	nop
801DF834	beq    v0, zero, L1df858 [$801df858]
801DF838	addu   s6, a3, zero
801DF83C	jal    func1dfe8c [$801dfe8c]
801DF840	nop
801DF844	addu   a0, s0, zero
801DF848	jal    func1def10 [$801def10]
801DF84C	addu   a1, s1, zero

loop1df850:	; 801DF850
801DF850	j      L1dfa90 [$801dfa90]
801DF854	ori    v0, zero, $0001

L1df858:	; 801DF858
801DF858	lhu    a1, $000c(s1)
801DF85C	lhu    t0, $000a(s0)
801DF860	andi   a0, a1, $ffff
801DF864	addiu  v1, a0, $0001
801DF868	slt    v0, v1, t0
801DF86C	sh     t0, $0010(sp)
801DF870	lhu    a2, $000e(s1)
801DF874	beq    v0, zero, L1df884 [$801df884]
801DF878	andi   s6, s6, $0001
801DF87C	addiu  a1, a1, $0001
801DF880	sh     a1, $0010(sp)

L1df884:	; 801DF884
801DF884	lhu    fp, $0002(s1)
801DF888	bne    s6, zero, L1df894 [$801df894]
801DF88C	sll    v0, v1, $01
801DF890	addiu  fp, fp, $ffff (=-$1)

L1df894:	; 801DF894
801DF894	lhu    a1, $0004(s1)
801DF898	addiu  s1, s1, $0018
801DF89C	addu   v0, v0, v1
801DF8A0	sll    v0, v0, $01
801DF8A4	addu   s3, s1, v0
801DF8A8	andi   v0, a1, $0001
801DF8AC	bne    v0, zero, L1df8c8 [$801df8c8]
801DF8B0	andi   v0, a1, $0002
801DF8B4	sll    v0, a0, $01
801DF8B8	addu   v0, v0, a0
801DF8BC	sll    v0, v0, $01
801DF8C0	addu   s3, s3, v0
801DF8C4	andi   v0, a1, $0002

L1df8c8:	; 801DF8C8
801DF8C8	bne    v0, zero, L1df8e0 [$801df8e0]

L1df8cc:	; 801DF8CC
801DF8CC	addu   s2, zero, zero
801DF8D0	sll    v0, a2, $01
801DF8D4	addu   v0, v0, a2
801DF8D8	sll    v0, v0, $01
801DF8DC	addu   s3, s3, v0

L1df8e0:	; 801DF8E0
801DF8E0	lhu    v0, $0010(sp)
801DF8E4	nop
801DF8E8	blez   v0, L1dfa90 [$801dfa90]
801DF8EC	addu   v0, zero, zero
801DF8F0	ori    s7, zero, $00ff
801DF8F4	addiu  s0, s0, $0074

loop1df8f8:	; 801DF8F8
801DF8F8	lhu    v0, $0000(s1)
801DF8FC	ori    t0, zero, $ffff
801DF900	beq    v0, t0, L1df980 [$801df980]
801DF904	addiu  s5, s1, $0004
801DF908	lw     v0, $fffc(s0)
801DF90C	nop
801DF910	beq    v0, zero, L1df930 [$801df930]
801DF914	addu   v1, v0, zero

L1df918:	; 801DF918
801DF918	lbu    v0, $0003(v1)
801DF91C	nop
801DF920	beq    v0, s7, L1df9b4 [$801df9b4]
801DF924	nop
801DF928	j      L1df93c [$801df93c]
801DF92C	nop

L1df930:	; 801DF930
801DF930	jal    func1df6f0 [$801df6f0]
801DF934	addu   a0, s4, zero
801DF938	addu   v1, v0, zero

L1df93c:	; 801DF93C
801DF93C	beq    v1, zero, L1df9b4 [$801df9b4]
801DF940	ori    v0, zero, $0001

loop1df944:	; 801DF944
801DF944	sb     v0, $0000(v1)
801DF948	sb     s6, $0001(v1)
801DF94C	lbu    v0, $0000(s5)
801DF950	lbu    t0, $0058(sp)
801DF954	nop
801DF958	sb     t0, $0003(v1)
801DF95C	sb     v0, $0002(v1)
801DF960	lhu    v0, $0000(s1)
801DF964	sh     zero, $0010(v1)
801DF968	sh     fp, $0012(v1)
801DF96C	addu   v0, s3, v0
801DF970	sw     v0, $0004(v1)
801DF974	sw     v0, $0008(v1)
801DF978	j      L1df9b4 [$801df9b4]

L1df97c:	; 801DF97C
801DF97C	sw     v1, $fffc(s0)

L1df980:	; 801DF980
801DF980	lw     a1, $fffc(s0)
801DF984	nop
801DF988	beq    a1, zero, L1df9b4 [$801df9b4]
801DF98C	nop
801DF990	beq    s2, zero, L1df9b4 [$801df9b4]
801DF994	nop
801DF998	lbu    v0, $0003(a1)
801DF99C	nop
801DF9A0	beq    v0, s7, L1df9b4 [$801df9b4]
801DF9A4	nop
801DF9A8	jal    func1df7a8 [$801df7a8]
801DF9AC	addu   a0, s4, zero
801DF9B0	sw     zero, $fffc(s0)

L1df9b4:	; 801DF9B4
801DF9B4	addiu  s1, s1, $0002
801DF9B8	lhu    v0, $0000(s1)
801DF9BC	ori    t0, zero, $ffff
801DF9C0	beq    v0, t0, L1dfa40 [$801dfa40]
801DF9C4	nop
801DF9C8	lw     v0, $0000(s0)
801DF9CC	nop
801DF9D0	beq    v0, zero, L1df9f0 [$801df9f0]
801DF9D4	addu   v1, v0, zero
801DF9D8	lbu    v0, $0003(v1)
801DF9DC	nop
801DF9E0	beq    v0, s7, L1dfa74 [$801dfa74]
801DF9E4	nop
801DF9E8	j      L1df9fc [$801df9fc]
801DF9EC	nop

L1df9f0:	; 801DF9F0
801DF9F0	jal    func1df6f0 [$801df6f0]
801DF9F4	addu   a0, s4, zero
801DF9F8	addu   v1, v0, zero

L1df9fc:	; 801DF9FC
801DF9FC	beq    v1, zero, L1dfa74 [$801dfa74]
801DFA00	ori    v0, zero, $0001
801DFA04	sb     v0, $0000(v1)
801DFA08	sb     s6, $0001(v1)
801DFA0C	lbu    v0, $0001(s5)
801DFA10	lbu    t0, $0058(sp)
801DFA14	nop
801DFA18	sb     t0, $0003(v1)
801DFA1C	sb     v0, $0002(v1)
801DFA20	lhu    v0, $0000(s1)
801DFA24	sh     zero, $0010(v1)
801DFA28	sh     fp, $0012(v1)
801DFA2C	addu   v0, s3, v0
801DFA30	sw     v0, $0004(v1)
801DFA34	sw     v0, $0008(v1)
801DFA38	j      L1dfa74 [$801dfa74]
801DFA3C	sw     v1, $0000(s0)

L1dfa40:	; 801DFA40
801DFA40	lw     a1, $0000(s0)

L1dfa44:	; 801DFA44
801DFA44	nop
801DFA48	beq    a1, zero, L1dfa74 [$801dfa74]
801DFA4C	nop
801DFA50	beq    s2, zero, L1dfa74 [$801dfa74]
801DFA54	nop
801DFA58	lbu    v0, $0003(a1)
801DFA5C	nop
801DFA60	beq    v0, s7, L1dfa74 [$801dfa74]
801DFA64	nop
801DFA68	jal    func1df7a8 [$801df7a8]
801DFA6C	addu   a0, s4, zero
801DFA70	sw     zero, $0000(s0)

L1dfa74:	; 801DFA74
801DFA74	addiu  s1, s1, $0004
801DFA78	lhu    v0, $0010(sp)
801DFA7C	addiu  s2, s2, $0001

L1dfa80:	; 801DFA80
801DFA80	slt    v0, s2, v0
801DFA84	bne    v0, zero, loop1df8f8 [$801df8f8]
801DFA88	addiu  s0, s0, $007c
801DFA8C	addu   v0, zero, zero

L1dfa90:	; 801DFA90
801DFA90	lw     ra, $0044(sp)
801DFA94	lw     fp, $0040(sp)
801DFA98	lw     s7, $003c(sp)
801DFA9C	lw     s6, $0038(sp)
801DFAA0	lw     s5, $0034(sp)
801DFAA4	lw     s4, $0030(sp)
801DFAA8	lw     s3, $002c(sp)
801DFAAC	lw     s2, $0028(sp)
801DFAB0	lw     s1, $0024(sp)
801DFAB4	lw     s0, $0020(sp)
801DFAB8	addiu  sp, sp, $0048
801DFABC	jr     ra 
801DFAC0	nop

801DFAC4	addiu  sp, sp, $ff88 (=-$78)
801DFAC8	sw     s1, $0054(sp)
801DFACC	addu   s1, a1, zero
801DFAD0	sw     s2, $0058(sp)

L1dfad4:	; 801DFAD4
801DFAD4	addu   s2, a2, zero
801DFAD8	sw     ra, $0074(sp)
801DFADC	sw     fp, $0070(sp)
801DFAE0	sw     s7, $006c(sp)
801DFAE4	sw     s6, $0068(sp)
801DFAE8	sw     s5, $0064(sp)
801DFAEC	sw     s4, $0060(sp)
801DFAF0	sw     s3, $005c(sp)
801DFAF4	sw     s0, $0050(sp)
801DFAF8	sw     a0, $0010(sp)
801DFAFC	lhu    v0, $0006(s2)
801DFB00	nop
801DFB04	beq    v0, zero, L1dfb2c [$801dfb2c]
801DFB08	addu   fp, a3, zero
801DFB0C	lw     a0, $0010(sp)
801DFB10	jal    func1dfe8c [$801dfe8c]
801DFB14	nop
801DFB18	addu   a0, s1, zero
801DFB1C	jal    func1def10 [$801def10]
801DFB20	addu   a1, s2, zero
801DFB24	j      L1dfe58 [$801dfe58]
801DFB28	ori    v0, zero, $0001

L1dfb2c:	; 801DFB2C
801DFB2C	andi   fp, fp, $0001
801DFB30	lhu    t0, $000c(s2)
801DFB34	addu   s5, zero, zero
801DFB38	sh     t0, $0020(sp)
801DFB3C	lhu    a0, $0020(sp)
801DFB40	lhu    t0, $000a(s1)
801DFB44	addiu  v1, a0, $0001
801DFB48	slt    v0, v1, t0

L1dfb4c:	; 801DFB4C
801DFB4C	sh     t0, $0030(sp)
801DFB50	lhu    t0, $000e(s2)
801DFB54	addu   s4, zero, zero
801DFB58	beq    v0, zero, L1dfb70 [$801dfb70]
801DFB5C	sh     t0, $0028(sp)
801DFB60	lhu    t0, $0020(sp)
801DFB64	nop
801DFB68	addiu  t0, t0, $0001
801DFB6C	sh     t0, $0030(sp)

L1dfb70:	; 801DFB70
801DFB70	lhu    t0, $0002(s2)
801DFB74	bne    fp, zero, L1dfb84 [$801dfb84]
801DFB78	sh     t0, $0038(sp)
801DFB7C	addiu  t0, t0, $ffff (=-$1)
801DFB80	sh     t0, $0038(sp)

L1dfb84:	; 801DFB84
801DFB84	lhu    s6, $0004(s2)
801DFB88	addiu  s2, s2, $0018
801DFB8C	sll    v0, v1, $01
801DFB90	addu   v0, v0, v1
801DFB94	sll    v0, v0, $01
801DFB98	addu   s0, s2, v0
801DFB9C	andi   v0, s6, $0001
801DFBA0	bne    v0, zero, L1dfbb8 [$801dfbb8]
801DFBA4	addu   s7, s0, zero
801DFBA8	sll    v0, a0, $01
801DFBAC	addu   v0, v0, a0
801DFBB0	sll    v0, v0, $01
801DFBB4	addu   s7, s0, v0

L1dfbb8:	; 801DFBB8
801DFBB8	andi   v0, s6, $0002
801DFBBC	bne    v0, zero, L1dfbdc [$801dfbdc]
801DFBC0	addu   s3, zero, zero
801DFBC4	lhu    t0, $0028(sp)
801DFBC8	nop
801DFBCC	sll    v0, t0, $01
801DFBD0	addu   v0, v0, t0
801DFBD4	sll    v0, v0, $01
801DFBD8	addu   s7, s7, v0

L1dfbdc:	; 801DFBDC
801DFBDC	lhu    v0, $0030(sp)
801DFBE0	nop
801DFBE4	blez   v0, L1dfe58 [$801dfe58]
801DFBE8	addu   v0, zero, zero
801DFBEC	ori    a1, zero, $0001
801DFBF0	addiu  s1, s1, $0074

L1dfbf4:	; 801DFBF4
801DFBF4	addiu  t0, s2, $0004
801DFBF8	sw     t0, $0018(sp)
801DFBFC	lhu    v1, $0000(s2)
801DFC00	ori    v0, zero, $ffff
801DFC04	beq    v1, v0, L1dfcf0 [$801dfcf0]
801DFC08	andi   v0, s6, $0001
801DFC0C	lw     v0, $fffc(s1)
801DFC10	nop
801DFC14	beq    v0, zero, L1dfc34 [$801dfc34]
801DFC18	addu   a0, v0, zero
801DFC1C	lbu    v1, $0003(a0)
801DFC20	ori    v0, zero, $00ff
801DFC24	beq    v1, v0, L1dfcf0 [$801dfcf0]
801DFC28	andi   v0, s6, $0001
801DFC2C	j      L1dfc4c [$801dfc4c]
801DFC30	nop

L1dfc34:	; 801DFC34
801DFC34	lw     a0, $0010(sp)
801DFC38	jal    func1df6f0 [$801df6f0]
801DFC3C	sw     a1, $0048(sp)
801DFC40	addu   a0, v0, zero
801DFC44	lw     a1, $0048(sp)
801DFC48	andi   v0, s6, $0001

L1dfc4c:	; 801DFC4C
801DFC4C	bne    v0, zero, L1dfca0 [$801dfca0]
801DFC50	nop
801DFC54	beq    s3, zero, L1dfca0 [$801dfca0]
801DFC58	andi   v0, s5, $ffff
801DFC5C	lhu    t0, $0020(sp)
801DFC60	nop
801DFC64	sltu   v0, v0, t0
801DFC68	beq    v0, zero, L1dfca0 [$801dfca0]
801DFC6C	nop
801DFC70	lhu    v0, $0000(s0)
801DFC74	addiu  s0, s0, $0002
801DFC78	addiu  s5, s5, $0001
801DFC7C	sh     v0, $ffe0(s1)
801DFC80	lhu    v0, $0000(s0)
801DFC84	addiu  s0, s0, $0002

L1dfc88:	; 801DFC88
801DFC88	sh     v0, $ffe2(s1)
801DFC8C	lhu    v0, $0000(s0)
801DFC90	addiu  s0, s0, $0002
801DFC94	sb     a1, $ff90(s1)
801DFC98	sb     a1, $ff91(s1)
801DFC9C	sh     v0, $ffe4(s1)

L1dfca0:	; 801DFCA0
801DFCA0	beq    a0, zero, L1dfd1c [$801dfd1c]
801DFCA4	nop
801DFCA8	sb     a1, $0000(a0)
801DFCAC	sb     fp, $0001(a0)
801DFCB0	lw     t0, $0018(sp)
801DFCB4	nop
801DFCB8	lbu    v0, $0000(t0)
801DFCBC	lbu    t0, $0088(sp)
801DFCC0	nop
801DFCC4	sb     t0, $0003(a0)
801DFCC8	sb     v0, $0002(a0)
801DFCCC	lhu    v0, $0000(s2)
801DFCD0	sh     zero, $0010(a0)
801DFCD4	lhu    t0, $0038(sp)
801DFCD8	addu   v0, s7, v0
801DFCDC	sh     t0, $0012(a0)
801DFCE0	sw     v0, $0004(a0)
801DFCE4	sw     v0, $0008(a0)
801DFCE8	j      L1dfd1c [$801dfd1c]
801DFCEC	sw     a0, $fffc(s1)

L1dfcf0:	; 801DFCF0
801DFCF0	bne    v0, zero, L1dfd1c [$801dfd1c]
801DFCF4	nop
801DFCF8	beq    s3, zero, L1dfd1c [$801dfd1c]
801DFCFC	andi   v0, s5, $ffff
801DFD00	lhu    t0, $0020(sp)
801DFD04	nop
801DFD08	sltu   v0, v0, t0
801DFD0C	beq    v0, zero, L1dfd1c [$801dfd1c]
801DFD10	nop
801DFD14	addiu  s0, s0, $0006
801DFD18	addiu  s5, s5, $0001

L1dfd1c:	; 801DFD1C
801DFD1C	addiu  s2, s2, $0002
801DFD20	lhu    v1, $0000(s2)
801DFD24	ori    v0, zero, $ffff
801DFD28	beq    v1, v0, L1dfe10 [$801dfe10]
801DFD2C	andi   v0, s6, $0002
801DFD30	lw     v0, $0000(s1)
801DFD34	nop
801DFD38	beq    v0, zero, L1dfd58 [$801dfd58]
801DFD3C	addu   a0, v0, zero
801DFD40	lbu    v1, $0003(a0)
801DFD44	ori    v0, zero, $00ff
801DFD48	beq    v1, v0, L1dfe10 [$801dfe10]

L1dfd4c:	; 801DFD4C
801DFD4C	andi   v0, s6, $0002
801DFD50	j      L1dfd70 [$801dfd70]
801DFD54	nop

L1dfd58:	; 801DFD58
801DFD58	lw     a0, $0010(sp)
801DFD5C	jal    func1df6f0 [$801df6f0]
801DFD60	sw     a1, $0048(sp)
801DFD64	addu   a0, v0, zero
801DFD68	lw     a1, $0048(sp)
801DFD6C	andi   v0, s6, $0002

L1dfd70:	; 801DFD70
801DFD70	bne    v0, zero, L1dfdc0 [$801dfdc0]
801DFD74	nop
801DFD78	beq    s3, zero, L1dfdc0 [$801dfdc0]
801DFD7C	andi   v0, s4, $ffff
801DFD80	lhu    t0, $0028(sp)
801DFD84	nop
801DFD88	sltu   v0, v0, t0
801DFD8C	beq    v0, zero, L1dfdc0 [$801dfdc0]
801DFD90	nop
801DFD94	lh     v0, $0000(s0)
801DFD98	addiu  s0, s0, $0002
801DFD9C	addiu  s4, s4, $0001
801DFDA0	sw     v0, $ffe8(s1)
801DFDA4	lh     v0, $0000(s0)
801DFDA8	addiu  s0, s0, $0002
801DFDAC	sw     v0, $ffec(s1)
801DFDB0	lh     v0, $0000(s0)
801DFDB4	addiu  s0, s0, $0002
801DFDB8	sb     a1, $ff90(s1)
801DFDBC	sw     v0, $fff0(s1)

L1dfdc0:	; 801DFDC0
801DFDC0	beq    a0, zero, L1dfe3c [$801dfe3c]
801DFDC4	nop
801DFDC8	sb     a1, $0000(a0)
801DFDCC	sb     fp, $0001(a0)
801DFDD0	lw     t0, $0018(sp)
801DFDD4	nop
801DFDD8	lbu    v0, $0001(t0)
801DFDDC	lbu    t0, $0088(sp)
801DFDE0	nop
801DFDE4	sb     t0, $0003(a0)
801DFDE8	sb     v0, $0002(a0)
801DFDEC	lhu    v0, $0000(s2)
801DFDF0	sh     zero, $0010(a0)
801DFDF4	lhu    t0, $0038(sp)
801DFDF8	addu   v0, s7, v0
801DFDFC	sh     t0, $0012(a0)
801DFE00	sw     v0, $0004(a0)
801DFE04	sw     v0, $0008(a0)
801DFE08	j      L1dfe3c [$801dfe3c]
801DFE0C	sw     a0, $0000(s1)

L1dfe10:	; 801DFE10
801DFE10	bne    v0, zero, L1dfe3c [$801dfe3c]
801DFE14	nop
801DFE18	beq    s3, zero, L1dfe3c [$801dfe3c]
801DFE1C	andi   v0, s4, $ffff
801DFE20	lhu    t0, $0028(sp)
801DFE24	nop
801DFE28	sltu   v0, v0, t0

L1dfe2c:	; 801DFE2C
801DFE2C	beq    v0, zero, L1dfe3c [$801dfe3c]
801DFE30	nop
801DFE34	addiu  s0, s0, $0006
801DFE38	addiu  s4, s4, $0001

L1dfe3c:	; 801DFE3C
801DFE3C	addiu  s2, s2, $0004
801DFE40	lhu    v0, $0030(sp)
801DFE44	addiu  s3, s3, $0001
801DFE48	slt    v0, s3, v0
801DFE4C	bne    v0, zero, L1dfbf4 [$801dfbf4]
801DFE50	addiu  s1, s1, $007c

L1dfe54:	; 801DFE54
801DFE54	addu   v0, zero, zero

L1dfe58:	; 801DFE58
801DFE58	lw     ra, $0074(sp)

L1dfe5c:	; 801DFE5C
801DFE5C	lw     fp, $0070(sp)
801DFE60	lw     s7, $006c(sp)
801DFE64	lw     s6, $0068(sp)
801DFE68	lw     s5, $0064(sp)
801DFE6C	lw     s4, $0060(sp)
801DFE70	lw     s3, $005c(sp)
801DFE74	lw     s2, $0058(sp)
801DFE78	lw     s1, $0054(sp)
801DFE7C	lw     s0, $0050(sp)
801DFE80	addiu  sp, sp, $0078
801DFE84	jr     ra 
801DFE88	nop



////////////////////////////////
// func1dfe8c
801DFE8C-801DFF74
////////////////////////////////



func1dff78:	; 801DFF78
801DFF78	addiu  sp, sp, $ffd0 (=-$30)
801DFF7C	sw     s3, $0024(sp)
801DFF80	addu   s3, a0, zero
801DFF84	sw     ra, $002c(sp)
801DFF88	sw     s4, $0028(sp)
801DFF8C	sw     s2, $0020(sp)
801DFF90	sw     s1, $001c(sp)
801DFF94	sw     s0, $0018(sp)
801DFF98	lhu    s4, $000a(a1)
801DFF9C	nop
801DFFA0	beq    s4, zero, L1e0040 [$801e0040]

L1dffa4:	; 801DFFA4
801DFFA4	addu   s1, zero, zero
801DFFA8	andi   s2, a2, $00ff
801DFFAC	addiu  s0, a1, $0078

loop1dffb0:	; 801DFFB0
801DFFB0	lw     a1, $fff8(s0)
801DFFB4	nop
801DFFB8	beq    a1, zero, L1dffdc [$801dffdc]
801DFFBC	nop
801DFFC0	lbu    v0, $0003(a1)
801DFFC4	nop
801DFFC8	bne    v0, s2, L1dffdc [$801dffdc]
801DFFCC	nop
801DFFD0	jal    func1df7a8 [$801df7a8]
801DFFD4	addu   a0, s3, zero
801DFFD8	sw     zero, $fff8(s0)

L1dffdc:	; 801DFFDC
801DFFDC	lw     a1, $fffc(s0)
801DFFE0	nop
801DFFE4	beq    a1, zero, L1e0008 [$801e0008]
801DFFE8	nop
801DFFEC	lbu    v0, $0003(a1)
801DFFF0	nop
801DFFF4	bne    v0, s2, L1e0008 [$801e0008]
801DFFF8	nop
801DFFFC	jal    func1df7a8 [$801df7a8]
801E0000	addu   a0, s3, zero
801E0004	sw     zero, $fffc(s0)

L1e0008:	; 801E0008
801E0008	lw     a1, $0000(s0)
801E000C	nop
801E0010	beq    a1, zero, L1e0034 [$801e0034]
801E0014	addiu  s1, s1, $0001
801E0018	lbu    v0, $0003(a1)
801E001C	nop
801E0020	bne    v0, s2, L1e0038 [$801e0038]
801E0024	slt    v0, s1, s4
801E0028	jal    func1df7a8 [$801df7a8]
801E002C	addu   a0, s3, zero
801E0030	sw     zero, $0000(s0)

L1e0034:	; 801E0034
801E0034	slt    v0, s1, s4

L1e0038:	; 801E0038
801E0038	bne    v0, zero, loop1dffb0 [$801dffb0]
801E003C	addiu  s0, s0, $007c

L1e0040:	; 801E0040
801E0040	lw     ra, $002c(sp)
801E0044	lw     s4, $0028(sp)
801E0048	lw     s3, $0024(sp)

L1e004c:	; 801E004C
801E004C	lw     s2, $0020(sp)
801E0050	lw     s1, $001c(sp)
801E0054	lw     s0, $0018(sp)
801E0058	addiu  sp, sp, $0030
801E005C	jr     ra 
801E0060	nop


func1e0064:	; 801E0064
801E0064	addiu  sp, sp, $ffe0 (=-$20)
801E0068	sw     s1, $0014(sp)
801E006C	addu   s1, a0, zero
801E0070	sw     s0, $0010(sp)
801E0074	addu   s0, a1, zero
801E0078	ori    a0, zero, $0004
801E007C	sw     ra, $0018(sp)

L1e0080:	; 801E0080
801E0080	jal    func322bc [$800322bc]
801E0084	addu   a1, zero, zero
801E0088	addiu  v0, s0, $0001
801E008C	sll    a0, v0, $05
801E0090	subu   a0, a0, v0
801E0094	sll    a0, a0, $02
801E0098	addu   a1, zero, zero
801E009C	sh     s0, $0004(s1)
801E00A0	jal    system_memory_allocate [$800319ec]
801E00A4	sh     zero, $0006(s1)
801E00A8	bne    v0, zero, L1e00b8 [$801e00b8]
801E00AC	sw     v0, $0000(s1)
801E00B0	j      L1e00c4 [$801e00c4]
801E00B4	addu   v0, zero, zero

L1e00b8:	; 801E00B8
801E00B8	jal    func1e011c [$801e011c]
801E00BC	addu   a0, s1, zero
801E00C0	addu   v0, s1, zero

L1e00c4:	; 801E00C4
801E00C4	lw     ra, $0018(sp)
801E00C8	lw     s1, $0014(sp)

L1e00cc:	; 801E00CC
801E00CC	lw     s0, $0010(sp)
801E00D0	addiu  sp, sp, $0020
801E00D4	jr     ra 
801E00D8	nop


func1e00dc:	; 801E00DC
801E00DC	addiu  sp, sp, $ffe8 (=-$18)
801E00E0	sw     s0, $0010(sp)
801E00E4	addu   s0, a0, zero
801E00E8	sw     ra, $0014(sp)
801E00EC	lw     a0, $0000(s0)
801E00F0	sh     zero, $0004(s0)
801E00F4	beq    a0, zero, L1e0104 [$801e0104]

L1e00f8:	; 801E00F8
801E00F8	sh     zero, $0006(s0)
801E00FC	jal    func31f0c [$80031f0c]
801E0100	nop

L1e0104:	; 801E0104
801E0104	sw     zero, $0000(s0)
801E0108	lw     ra, $0014(sp)
801E010C	lw     s0, $0010(sp)
801E0110	addiu  sp, sp, $0018
801E0114	jr     ra 
801E0118	nop


func1e011c:	; 801E011C
801E011C	addiu  sp, sp, $ffc0 (=-$40)
801E0120	sw     fp, $0038(sp)
801E0124	addu   fp, a0, zero
801E0128	sw     s6, $0030(sp)
801E012C	sw     ra, $003c(sp)
801E0130	sw     s7, $0034(sp)
801E0134	sw     s5, $002c(sp)
801E0138	sw     s4, $0028(sp)
801E013C	sw     s3, $0024(sp)
801E0140	sw     s2, $0020(sp)
801E0144	sw     s1, $001c(sp)
801E0148	sw     s0, $0018(sp)
801E014C	lh     v0, $0004(fp)
801E0150	lw     s4, $0000(fp)
801E0154	addiu  v0, v0, $0001
801E0158	blez   v0, L1e0214 [$801e0214]

L1e015c:	; 801E015C
801E015C	addu   s6, zero, zero
801E0160	ori    s7, zero, $00bd
801E0164	addiu  s5, s4, $001e

loop1e0168:	; 801E0168
801E0168	addu   s3, zero, zero
801E016C	addu   s1, s4, zero

L1e0170:	; 801E0170
801E0170	ori    s2, zero, $002c
801E0174	addiu  v0, zero, $ffff (=-$1)
801E0178	sh     v0, $fff8(s5)
801E017C	sh     zero, $0000(s5)

loop1e0180:	; 801E0180
801E0180	addu   s0, s4, s2
801E0184	jal    func43b28 [$80043b28]
801E0188	addu   a0, s0, zero
801E018C	addu   a0, s0, zero
801E0190	jal    system_set_draw_packet_transparency [$80043a74]
801E0194	ori    a1, zero, $0001
801E0198	addu   a0, zero, zero

L1e019c:	; 801E019C
801E019C	jal    func438d0 [$800438d0]
801E01A0	ori    a1, zero, $01cd
801E01A4	addu   a0, zero, zero
801E01A8	ori    a1, zero, $0001
801E01AC	ori    a2, zero, $0340
801E01B0	ori    a3, zero, $0100
801E01B4	jal    func43894 [$80043894]
801E01B8	sh     v0, $003a(s1)
801E01BC	ori    v1, zero, $000f
801E01C0	sb     v1, $0048(s1)
801E01C4	sh     v0, $0042(s1)
801E01C8	sb     zero, $0038(s1)
801E01CC	sb     s7, $0039(s1)
801E01D0	sb     zero, $0040(s1)
801E01D4	sb     s7, $0041(s1)
801E01D8	sb     s7, $0049(s1)
801E01DC	sb     v1, $0050(s1)
801E01E0	sb     s7, $0051(s1)
801E01E4	addiu  s1, s1, $0028
801E01E8	addiu  s3, s3, $0001
801E01EC	slti   v0, s3, $0002

L1e01f0:	; 801E01F0
801E01F0	bne    v0, zero, loop1e0180 [$801e0180]
801E01F4	addiu  s2, s2, $0028

L1e01f8:	; 801E01F8
801E01F8	addiu  s5, s5, $007c
801E01FC	lh     v0, $0004(fp)
801E0200	addiu  s6, s6, $0001
801E0204	addiu  v0, v0, $0001
801E0208	slt    v0, s6, v0

L1e020c:	; 801E020C
801E020C	bne    v0, zero, loop1e0168 [$801e0168]

L1e0210:	; 801E0210
801E0210	addiu  s4, s4, $007c

L1e0214:	; 801E0214
801E0214	lw     ra, $003c(sp)

L1e0218:	; 801E0218
801E0218	lw     fp, $0038(sp)
801E021C	lw     s7, $0034(sp)
801E0220	lw     s6, $0030(sp)
801E0224	lw     s5, $002c(sp)
801E0228	lw     s4, $0028(sp)
801E022C	lw     s3, $0024(sp)
801E0230	lw     s2, $0020(sp)
801E0234	lw     s1, $001c(sp)
801E0238	lw     s0, $0018(sp)
801E023C	addiu  sp, sp, $0040
801E0240	jr     ra 
801E0244	nop


func1e0248:	; 801E0248
801E0248	addiu  sp, sp, $ffd0 (=-$30)
801E024C	sw     ra, $0028(sp)
801E0250	sw     s1, $0024(sp)
801E0254	sw     s0, $0020(sp)
801E0258	lh     v1, $0006(a0)
801E025C	lh     v0, $0004(a0)
801E0260	nop
801E0264	slt    v0, v1, v0
801E0268	beq    v0, zero, L1e0320 [$801e0320]
801E026C	addu   a2, v1, zero
801E0270	sll    v0, v1, $05
801E0274	subu   v0, v0, v1
801E0278	lw     v1, $0000(a0)
801E027C	sll    v0, v0, $02
801E0280	addu   s1, v0, v1
801E0284	lh     v1, $0016(s1)
801E0288	addiu  v0, zero, $ffff (=-$1)
801E028C	bne    v1, v0, L1e0320 [$801e0320]
801E0290	addiu  v0, a2, $0001
801E0294	sh     v0, $0006(a0)
801E0298	sll    v0, v0, $10
801E029C	lh     v1, $0004(a0)
801E02A0	sra    v0, v0, $10
801E02A4	slt    v0, v0, v1
801E02A8	beq    v0, zero, L1e02f8 [$801e02f8]
801E02AC	addiu  t0, zero, $ffff (=-$1)
801E02B0	lw     a3, $0000(a0)
801E02B4	addu   a2, v1, zero

loop1e02b8:	; 801E02B8
801E02B8	lh     v0, $0006(a0)
801E02BC	nop
801E02C0	sll    v1, v0, $05
801E02C4	subu   v1, v1, v0
801E02C8	sll    v1, v1, $02
801E02CC	addu   v1, v1, a3
801E02D0	lh     v1, $0016(v1)
801E02D4	nop
801E02D8	beq    v1, t0, L1e02f8 [$801e02f8]
801E02DC	addiu  v0, v0, $0001
801E02E0	sh     v0, $0006(a0)
801E02E4	sll    v0, v0, $10
801E02E8	sra    v0, v0, $10

L1e02ec:	; 801E02EC
801E02EC	slt    v0, v0, a2

L1e02f0:	; 801E02F0
801E02F0	bne    v0, zero, loop1e02b8 [$801e02b8]

L1e02f4:	; 801E02F4
801E02F4	nop

L1e02f8:	; 801E02F8
801E02F8	addiu  a0, s1, $002c
801E02FC	sll    s0, a1, $10
801E0300	sra    s0, s0, $10
801E0304	jal    system_set_draw_packet_transparency [$80043a74]
801E0308	addu   a1, s0, zero
801E030C	addiu  a0, s1, $0054
801E0310	jal    system_set_draw_packet_transparency [$80043a74]
801E0314	addu   a1, s0, zero
801E0318	j      L1e033c [$801e033c]
801E031C	addu   v0, s1, zero

L1e0320:	; 801E0320
801E0320	lh     v1, $0004(a0)
801E0324	nop
801E0328	sll    v0, v1, $05
801E032C	subu   v0, v0, v1
801E0330	lw     v1, $0000(a0)
801E0334	sll    v0, v0, $02
801E0338	addu   v0, v0, v1

L1e033c:	; 801E033C
801E033C	lw     ra, $0028(sp)
801E0340	lw     s1, $0024(sp)
801E0344	lw     s0, $0020(sp)
801E0348	addiu  sp, sp, $0030
801E034C	jr     ra 
801E0350	nop


func1e0354:	; 801E0354
801E0354	lui    v1, $2108
801E0358	lw     v0, $0000(a0)
801E035C	ori    v1, v1, $4211
801E0360	subu   v0, a1, v0
801E0364	srl    v0, v0, $02
801E0368	multu  v0, v1
801E036C	lh     v0, $0006(a0)

L1e0370:	; 801E0370
801E0370	mfhi   v1
801E0374	srl    v1, v1, $02
801E0378	slt    v0, v0, v1
801E037C	bne    v0, zero, L1e0388 [$801e0388]
801E0380	nop
801E0384	sh     v1, $0006(a0)

L1e0388:	; 801E0388
801E0388	addiu  v0, zero, $ffff (=-$1)
801E038C	sh     v0, $0016(a1)
801E0390	jr     ra 
801E0394	addu   v0, v1, zero


func1e0398:	; 801E0398
801E0398	addiu  sp, sp, $ffb8 (=-$48)
801E039C	sw     s7, $003c(sp)

L1e03a0:	; 801E03A0
801E03A0	addu   s7, a0, zero
801E03A4	sw     s0, $0020(sp)
801E03A8	addu   s0, a1, zero
801E03AC	sw     s3, $002c(sp)
801E03B0	addu   s3, a2, zero
801E03B4	sw     s4, $0030(sp)
801E03B8	addu   s4, a3, zero
801E03BC	sw     fp, $0040(sp)
801E03C0	lw     fp, $0058(sp)
801E03C4	addu   a0, s0, zero
801E03C8	sw     ra, $0044(sp)
801E03CC	sw     s6, $0038(sp)
801E03D0	sw     s5, $0034(sp)
801E03D4	sw     s2, $0028(sp)
801E03D8	jal    func49da4 [$80049da4]
801E03DC	sw     s1, $0024(sp)
801E03E0	jal    func49e34 [$80049e34]
801E03E4	addu   a0, s0, zero
801E03E8	lh     v0, $0004(s7)
801E03EC	lw     s1, $0000(s7)
801E03F0	blez   v0, L1e0664 [$801e0664]
801E03F4	addu   s5, zero, zero

L1e03f8:	; 801E03F8
801E03F8	lui    s2, $00ff
801E03FC	ori    s2, s2, $ffff
801E0400	lui    s6, $ff00
801E0404	addiu  s0, s1, $0024

L1e0408:	; 801E0408
801E0408	lh     v1, $fff2(s0)
801E040C	addiu  v0, zero, $ffff (=-$1)
801E0410	beq    v1, v0, L1e0648 [$801e0648]
801E0414	nop
801E0418	lh     v0, $fffa(s0)
801E041C	nop

L1e0420:	; 801E0420
801E0420	slt    v0, v1, v0
801E0424	bne    v0, zero, L1e0440 [$801e0440]
801E0428	sll    v0, fp, $02
801E042C	addu   a0, s7, zero
801E0430	jal    func1e0354 [$801e0354]
801E0434	addu   a1, s1, zero
801E0438	j      L1e064c [$801e064c]
801E043C	addiu  s5, s5, $0001

L1e0440:	; 801E0440
801E0440	addu   v0, v0, fp
801E0444	sll    a1, v0, $03
801E0448	lhu    v1, $fffc(s0)
801E044C	addu   a2, s1, a1
801E0450	srl    v1, v1, $06
801E0454	sb     v1, $0030(a2)
801E0458	lhu    v0, $fffe(s0)
801E045C	nop
801E0460	srl    v0, v0, $06
801E0464	sb     v0, $0031(a2)
801E0468	lhu    v0, $0000(s0)
801E046C	nop
801E0470	srl    v0, v0, $06
801E0474	sb     v0, $0032(a2)
801E0478	lh     v0, $ffea(s0)
801E047C	nop
801E0480	bne    v0, zero, L1e051c [$801e051c]
801E0484	addiu  v1, s1, $0008
801E0488	lhu    v0, $0000(s1)
801E048C	lw     v1, $002c(a2)
801E0490	sh     v0, $0034(a2)
801E0494	lhu    v0, $ffde(s0)
801E0498	nop
801E049C	sh     v0, $0036(a2)
801E04A0	lhu    v0, $ffe4(s0)
801E04A4	nop
801E04A8	sh     v0, $003c(a2)
801E04AC	lhu    v0, $ffe6(s0)
801E04B0	nop
801E04B4	sh     v0, $003e(a2)
801E04B8	lhu    v0, $ffec(s0)
801E04BC	nop
801E04C0	sh     v0, $0044(a2)
801E04C4	lhu    v0, $ffee(s0)
801E04C8	nop
801E04CC	sh     v0, $0046(a2)
801E04D0	lhu    v0, $fff4(s0)
801E04D4	nop
801E04D8	sh     v0, $004c(a2)
801E04DC	lhu    v0, $fff6(s0)
801E04E0	nop
801E04E4	sh     v0, $004e(a2)
801E04E8	lw     v0, $0000(s4)
801E04EC	and    v1, v1, s6
801E04F0	and    v0, v0, s2
801E04F4	or     v1, v1, v0
801E04F8	addiu  v0, a1, $002c
801E04FC	addu   v0, s1, v0
801E0500	sw     v1, $002c(a2)
801E0504	lw     v1, $0000(s4)
801E0508	and    v0, v0, s2
801E050C	and    v1, v1, s6
801E0510	or     v1, v1, v0
801E0514	j      L1e05e8 [$801e05e8]
801E0518	sw     v1, $0000(s4)

L1e051c:	; 801E051C
801E051C	addiu  v0, s1, $0010
801E0520	lwc2   zero, $0000(s1)

L1e0524:	; 801E0524
801E0524	lwc2   at, $0004(s1)
801E0528	lwc2   v0, $0000(v1)
801E052C	lwc2   v1, $0004(v1)

L1e0530:	; 801E0530
801E0530	lwc2   a0, $0000(v0)
801E0534	lwc2   a1, $0004(v0)
801E0538	nop
801E053C	nop
801E0540	gte_func17t0,r11r12
801E0544	addiu  a1, a1, $002c
801E0548	addu   a1, s1, a1
801E054C	addiu  a0, a1, $0008
801E0550	addiu  v1, a1, $0010
801E0554	addiu  v0, a1, $0018
801E0558	swc2   t4, $0000(a0)
801E055C	swc2   t5, $0000(v1)
801E0560	swc2   t6, $0000(v0)
801E0564	addiu  v0, sp, $0010
801E0568	mfc2   t4,lb1lb2
801E056C	nop
801E0570	sra    t4, t4, $02
801E0574	sw     t4, $0000(v0)
801E0578	lw     v0, $0010(sp)
801E057C	lui    v1, $8005
801E0580	lw     v1, $f7a4(v1)
801E0584	nop
801E0588	srav   v0, v1, v0
801E058C	sw     v0, $0010(sp)
801E0590	addiu  v0, s1, $0018
801E0594	lwc2   zero, $0000(v0)
801E0598	lwc2   at, $0004(v0)
801E059C	nop

L1e05a0:	; 801E05A0
801E05A0	nop
801E05A4	gte_func16t8,r11r12
801E05A8	addiu  v0, a1, $0020

L1e05ac:	; 801E05AC
801E05AC	swc2   t6, $0000(v0)

L1e05b0:	; 801E05B0
801E05B0	lw     a0, $0010(sp)

L1e05b4:	; 801E05B4
801E05B4	lw     v1, $002c(a2)

L1e05b8:	; 801E05B8
801E05B8	sll    a0, a0, $02
801E05BC	addu   a0, a0, s4
801E05C0	lw     v0, $0000(a0)
801E05C4	and    v1, v1, s6
801E05C8	and    v0, v0, s2
801E05CC	or     v1, v1, v0
801E05D0	sw     v1, $002c(a2)
801E05D4	lw     v0, $0000(a0)
801E05D8	and    a1, a1, s2
801E05DC	and    v0, v0, s6
801E05E0	or     v0, v0, a1
801E05E4	sw     v0, $0000(a0)

L1e05e8:	; 801E05E8
801E05E8	lh     v0, $0002(s0)
801E05EC	nop

L1e05f0:	; 801E05F0
801E05F0	mult   v0, s3
801E05F4	mflo   a1
801E05F8	lh     v0, $0004(s0)
801E05FC	nop
801E0600	mult   v0, s3
801E0604	mflo   a0
801E0608	lh     v0, $0006(s0)
801E060C	nop
801E0610	mult   v0, s3
801E0614	lhu    v0, $fff2(s0)
801E0618	lhu    v1, $fffe(s0)
801E061C	addu   v0, v0, s3

L1e0620:	; 801E0620
801E0620	sh     v0, $fff2(s0)

L1e0624:	; 801E0624
801E0624	lhu    v0, $fffc(s0)
801E0628	subu   v1, v1, a0
801E062C	sh     v1, $fffe(s0)
801E0630	subu   v0, v0, a1
801E0634	sh     v0, $fffc(s0)
801E0638	lhu    v0, $0000(s0)
801E063C	mflo   v1
801E0640	subu   v0, v0, v1

L1e0644:	; 801E0644
801E0644	sh     v0, $0000(s0)

L1e0648:	; 801E0648
801E0648	addiu  s5, s5, $0001

L1e064c:	; 801E064C
801E064C	addiu  s0, s0, $007c
801E0650	lh     v0, $0004(s7)
801E0654	nop
801E0658	slt    v0, s5, v0
801E065C	bne    v0, zero, L1e0408 [$801e0408]
801E0660	addiu  s1, s1, $007c

L1e0664:	; 801E0664
801E0664	lw     ra, $0044(sp)
801E0668	lw     fp, $0040(sp)
801E066C	lw     s7, $003c(sp)
801E0670	lw     s6, $0038(sp)
801E0674	lw     s5, $0034(sp)
801E0678	lw     s4, $0030(sp)
801E067C	lw     s3, $002c(sp)
801E0680	lw     s2, $0028(sp)
801E0684	lw     s1, $0024(sp)
801E0688	lw     s0, $0020(sp)
801E068C	addiu  sp, sp, $0048
801E0690	jr     ra 
801E0694	nop

801E0698	addiu  sp, sp, $fff0 (=-$10)
801E069C	lw     t5, $0020(sp)

L1e06a0:	; 801E06A0
801E06A0	lhu    t9, $0024(sp)
801E06A4	lbu    t7, $0028(sp)
801E06A8	sw     s0, $0000(sp)
801E06AC	lbu    s0, $002c(sp)
801E06B0	sw     s2, $0008(sp)
801E06B4	lbu    s2, $0030(sp)
801E06B8	lbu    t8, $0034(sp)
801E06BC	sw     s1, $0004(sp)
801E06C0	lbu    s1, $0038(sp)
801E06C4	addu   t0, a0, zero
801E06C8	sw     s3, $000c(sp)
801E06CC	lbu    s3, $003c(sp)
801E06D0	lhu    v1, $0040(sp)
801E06D4	lhu    a0, $0044(sp)
801E06D8	lhu    t1, $0048(sp)
801E06DC	lhu    t2, $004c(sp)
801E06E0	lhu    t3, $0050(sp)
801E06E4	lhu    t4, $0054(sp)
801E06E8	lhu    v0, $0058(sp)
801E06EC	beq    t0, zero, L1e0828 [$801e0828]
801E06F0	addu   t6, t5, zero
801E06F4	sb     v0, $0003(t0)
801E06F8	addiu  v0, zero, $ffff (=-$1)
801E06FC	sh     v0, $005e(t0)
801E0700	sll    v0, t5, $10
801E0704	sra    v0, v0, $10
801E0708	slti   v0, v0, $0007
801E070C	sh     a2, $0000(t0)
801E0710	sb     a3, $0002(t0)
801E0714	sw     a1, $0004(t0)
801E0718	sh     v1, $000c(t0)
801E071C	sh     a0, $000e(t0)
801E0720	sh     t1, $0010(t0)
801E0724	sh     t2, $0014(t0)
801E0728	sh     t3, $0016(t0)
801E072C	sh     t4, $0018(t0)
801E0730	beq    v0, zero, L1e0740 [$801e0740]
801E0734	sh     zero, $005c(t0)
801E0738	j      L1e0748 [$801e0748]
801E073C	sh     t6, $0060(t0)

L1e0740:	; 801E0740
801E0740	ori    v0, zero, $0007
801E0744	sh     v0, $0060(t0)

L1e0748:	; 801E0748
801E0748	sll    v0, t7, $06
801E074C	sh     v0, $0064(t0)
801E0750	sll    v0, t8, $06
801E0754	sll    v1, t9, $10
801E0758	lh     a2, $0064(t0)
801E075C	sra    v1, v1, $10
801E0760	subu   a2, a2, v0
801E0764	div    a2, v1
801E0768	bne    v1, zero, L1e0774 [$801e0774]
801E076C	nop
801E0770	break   $01c00

L1e0774:	; 801E0774
801E0774	addiu  at, zero, $ffff (=-$1)
801E0778	bne    v1, at, L1e078c [$801e078c]
801E077C	lui    at, $8000
801E0780	bne    a2, at, L1e078c [$801e078c]
801E0784	nop
801E0788	break   $01800

L1e078c:	; 801E078C
801E078C	mflo   a2
801E0790	sll    v0, s0, $06
801E0794	sh     v0, $0066(t0)
801E0798	lh     a1, $0066(t0)
801E079C	sll    v0, s1, $06
801E07A0	subu   a1, a1, v0
801E07A4	div    a1, v1
801E07A8	bne    v1, zero, L1e07b4 [$801e07b4]
801E07AC	nop
801E07B0	break   $01c00

L1e07b4:	; 801E07B4
801E07B4	addiu  at, zero, $ffff (=-$1)
801E07B8	bne    v1, at, L1e07cc [$801e07cc]
801E07BC	lui    at, $8000
801E07C0	bne    a1, at, L1e07cc [$801e07cc]
801E07C4	nop
801E07C8	break   $01800

L1e07cc:	; 801E07CC
801E07CC	mflo   a1
801E07D0	sll    v0, s2, $06
801E07D4	sh     v0, $0068(t0)
801E07D8	lh     a0, $0068(t0)
801E07DC	sll    v0, s3, $06
801E07E0	subu   a0, a0, v0
801E07E4	div    a0, v1
801E07E8	bne    v1, zero, L1e07f4 [$801e07f4]
801E07EC	nop
801E07F0	break   $01c00

L1e07f4:	; 801E07F4
801E07F4	addiu  at, zero, $ffff (=-$1)
801E07F8	bne    v1, at, L1e080c [$801e080c]
801E07FC	lui    at, $8000
801E0800	bne    a0, at, L1e080c [$801e080c]
801E0804	nop

L1e0808:	; 801E0808
801E0808	break   $01800

L1e080c:	; 801E080C
801E080C	mflo   a0
801E0810	sh     t9, $0062(t0)
801E0814	sw     zero, $0008(t0)

L1e0818:	; 801E0818
801E0818	addu   v0, zero, zero
801E081C	sh     a2, $006a(t0)
801E0820	sh     a1, $006c(t0)
801E0824	sh     a0, $006e(t0)

L1e0828:	; 801E0828
801E0828	lw     s3, $000c(sp)
801E082C	lw     s2, $0008(sp)
801E0830	lw     s1, $0004(sp)
801E0834	lw     s0, $0000(sp)
801E0838	addiu  sp, sp, $0010
801E083C	jr     ra 
801E0840	nop


func1e0844:	; 801E0844
801E0844	addiu  v0, zero, $ffff (=-$1)
801E0848	jr     ra 
801E084C	sh     v0, $0000(a0)

801E0850	addiu  sp, sp, $ffe0 (=-$20)
801E0854	sw     s0, $0010(sp)
801E0858	addu   s0, a1, zero
801E085C	sw     s1, $0014(sp)
801E0860	addu   s1, a2, zero
801E0864	sll    a0, a0, $10
801E0868	sw     ra, $0018(sp)
801E086C	jal    func3f774 [$8003f774]
801E0870	sra    a0, a0, $10
801E0874	addiu  v0, v0, $1000
801E0878	sll    s0, s0, $10
801E087C	sra    s0, s0, $10
801E0880	div    v0, s0
801E0884	bne    s0, zero, L1e0890 [$801e0890]

L1e0888:	; 801E0888
801E0888	nop
801E088C	break   $01c00

L1e0890:	; 801E0890
801E0890	addiu  at, zero, $ffff (=-$1)
801E0894	bne    s0, at, L1e08a8 [$801e08a8]

L1e0898:	; 801E0898
801E0898	lui    at, $8000
801E089C	bne    v0, at, L1e08a8 [$801e08a8]
801E08A0	nop
801E08A4	break   $01800

L1e08a8:	; 801E08A8
801E08A8	mflo   v0
801E08AC	nop
801E08B0	addu   s1, s1, v0
801E08B4	sll    s1, s1, $10
801E08B8	sra    v0, s1, $10
801E08BC	lw     ra, $0018(sp)
801E08C0	lw     s1, $0014(sp)
801E08C4	lw     s0, $0010(sp)
801E08C8	addiu  sp, sp, $0020
801E08CC	jr     ra 
801E08D0	nop

801E08D4	sll    a0, a0, $10
801E08D8	sra    a0, a0, $10
801E08DC	sll    a1, a1, $10
801E08E0	sra    a1, a1, $10
801E08E4	div    a0, a1
801E08E8	bne    a1, zero, L1e08f4 [$801e08f4]
801E08EC	nop
801E08F0	break   $01c00

L1e08f4:	; 801E08F4
801E08F4	addiu  at, zero, $ffff (=-$1)
801E08F8	bne    a1, at, L1e090c [$801e090c]
801E08FC	lui    at, $8000
801E0900	bne    a0, at, L1e090c [$801e090c]
801E0904	nop
801E0908	break   $01800

L1e090c:	; 801E090C
801E090C	mflo   a0
801E0910	nop
801E0914	addu   a2, a2, a0

L1e0918:	; 801E0918
801E0918	sll    a2, a2, $10
801E091C	sra    a2, a2, $10
801E0920	slti   v1, a2, $0021
801E0924	beq    v1, zero, L1e0930 [$801e0930]
801E0928	addiu  v0, zero, $ffff (=-$1)
801E092C	addu   v0, a2, zero

L1e0930:	; 801E0930
801E0930	jr     ra 
801E0934	nop

801E0938	sll    a0, a0, $10
801E093C	sra    a0, a0, $10

L1e0940:	; 801E0940
801E0940	sll    a1, a1, $10
801E0944	sra    a1, a1, $10
801E0948	div    a0, a1
801E094C	bne    a1, zero, L1e0958 [$801e0958]
801E0950	nop
801E0954	break   $01c00

L1e0958:	; 801E0958
801E0958	addiu  at, zero, $ffff (=-$1)
801E095C	bne    a1, at, L1e0970 [$801e0970]
801E0960	lui    at, $8000
801E0964	bne    a0, at, L1e0970 [$801e0970]
801E0968	nop
801E096C	break   $01800

L1e0970:	; 801E0970
801E0970	mflo   a0
801E0974	nop
801E0978	subu   v0, a2, a0
801E097C	sll    v0, v0, $10
801E0980	jr     ra 

L1e0984:	; 801E0984
801E0984	sra    v0, v0, $10

801E0988	sll    a0, a0, $10
801E098C	sra    a0, a0, $10
801E0990	sll    a1, a1, $10
801E0994	sra    a1, a1, $10
801E0998	div    a0, a1
801E099C	bne    a1, zero, L1e09a8 [$801e09a8]
801E09A0	nop
801E09A4	break   $01c00

L1e09a8:	; 801E09A8
801E09A8	addiu  at, zero, $ffff (=-$1)
801E09AC	bne    a1, at, L1e09c0 [$801e09c0]
801E09B0	lui    at, $8000
801E09B4	bne    a0, at, L1e09c0 [$801e09c0]
801E09B8	nop
801E09BC	break   $01800

L1e09c0:	; 801E09C0
801E09C0	mflo   a0
801E09C4	ori    v0, zero, $0020
801E09C8	subu   v0, v0, a0
801E09CC	addu   v1, v0, zero
801E09D0	addu   a0, a2, zero
801E09D4	sll    v0, v0, $10
801E09D8	sra    v0, v0, $10
801E09DC	sll    a2, a2, $10
801E09E0	sra    a2, a2, $10
801E09E4	slt    v0, v0, a2
801E09E8	beq    v0, zero, L1e09f4 [$801e09f4]
801E09EC	nop
801E09F0	addu   v1, a0, zero

L1e09f4:	; 801E09F4
801E09F4	sll    v0, v1, $10
801E09F8	jr     ra 
801E09FC	sra    v0, v0, $10


func1e0a00:	; 801E0A00
801E0A00	addiu  sp, sp, $fef8 (=-$108)
801E0A04	sw     s5, $00f4(sp)
801E0A08	sw     a3, $0028(sp)
801E0A0C	lhu    s5, $0028(sp)
801E0A10	lw     t6, $013c(sp)
801E0A14	sw     s3, $00ec(sp)
801E0A18	sw     t6, $0078(sp)
801E0A1C	lw     t6, $0140(sp)
801E0A20	lhu    s3, $0078(sp)
801E0A24	sw     s2, $00e8(sp)
801E0A28	sw     t6, $0080(sp)
801E0A2C	lw     t6, $0118(sp)
801E0A30	lhu    s2, $0080(sp)
801E0A34	sw     t6, $0030(sp)
801E0A38	lw     t6, $0150(sp)
801E0A3C	sw     s4, $00f0(sp)

L1e0a40:	; 801E0A40
801E0A40	sw     t6, $0088(sp)
801E0A44	lhu    t6, $011c(sp)
801E0A48	addu   s4, a2, zero
801E0A4C	sh     t6, $0038(sp)
801E0A50	lhu    t6, $0120(sp)
801E0A54	sw     ra, $0104(sp)
801E0A58	sw     fp, $0100(sp)
801E0A5C	sw     s7, $00fc(sp)
801E0A60	sw     s6, $00f8(sp)
801E0A64	sw     s1, $00e4(sp)
801E0A68	sw     s0, $00e0(sp)
801E0A6C	sw     a1, $0018(sp)
801E0A70	sh     s4, $0020(sp)
801E0A74	sh     t6, $0040(sp)
801E0A78	lhu    t6, $0124(sp)
801E0A7C	nop
801E0A80	sh     t6, $0048(sp)
801E0A84	lhu    t6, $0128(sp)
801E0A88	nop
801E0A8C	sh     t6, $0050(sp)
801E0A90	lhu    t6, $012c(sp)
801E0A94	lhu    s7, $0144(sp)
801E0A98	lhu    fp, $0148(sp)
801E0A9C	sh     t6, $0058(sp)

L1e0aa0:	; 801E0AA0
801E0AA0	lhu    t6, $0130(sp)
801E0AA4	nop
801E0AA8	sh     t6, $0060(sp)
801E0AAC	lhu    t6, $0134(sp)

L1e0ab0:	; 801E0AB0
801E0AB0	nop

L1e0ab4:	; 801E0AB4
801E0AB4	sh     t6, $0068(sp)
801E0AB8	lhu    t6, $0138(sp)
801E0ABC	addu   s0, a0, zero

L1e0ac0:	; 801E0AC0
801E0AC0	sh     t6, $0070(sp)
801E0AC4	lhu    v0, $001a(s0)
801E0AC8	lhu    s6, $014c(sp)
801E0ACC	bne    v0, zero, L1e1224 [$801e1224]
801E0AD0	addu   v0, zero, zero
801E0AD4	ori    a0, zero, $0004
801E0AD8	jal    func322bc [$800322bc]
801E0ADC	addu   a1, zero, zero
801E0AE0	ori    v0, zero, $0001
801E0AE4	sh     v0, $001a(s0)
801E0AE8	lbu    t6, $0020(sp)
801E0AEC	sb     zero, $0011(s0)
801E0AF0	sb     t6, $0010(s0)
801E0AF4	lw     t6, $0018(sp)
801E0AF8	ori    v0, zero, $ffff
801E0AFC	sw     t6, $0000(s0)
801E0B00	sh     zero, $0014(s0)
801E0B04	sh     v0, $0018(s0)
801E0B08	sh     s7, $0016(s0)

L1e0b0c:	; 801E0B0C
801E0B0C	sh     fp, $0020(s0)
801E0B10	sh     s6, $0022(s0)
801E0B14	lw     t6, $0088(sp)
801E0B18	nop
801E0B1C	sw     t6, $0024(s0)

L1e0b20:	; 801E0B20
801E0B20	lw     t6, $0030(sp)
801E0B24	andi   v0, s4, $0001
801E0B28	bne    v0, zero, L1e0b3c [$801e0b3c]
801E0B2C	sw     t6, $001c(s0)

L1e0b30:	; 801E0B30
801E0B30	lw     t6, $0028(sp)
801E0B34	nop
801E0B38	andi   s5, t6, $fd0f

L1e0b3c:	; 801E0B3C
801E0B3C	andi   v0, s4, $0004
801E0B40	beq    v0, zero, L1e0b4c [$801e0b4c]
801E0B44	nop
801E0B48	andi   s5, s5, $feff

L1e0b4c:	; 801E0B4C
801E0B4C	lw     t6, $0078(sp)
801E0B50	nop
801E0B54	sll    v0, t6, $10

L1e0b58:	; 801E0B58
801E0B58	bne    v0, zero, L1e0b64 [$801e0b64]
801E0B5C	nop
801E0B60	ori    s3, zero, $0100

L1e0b64:	; 801E0B64
801E0B64	lw     t6, $0080(sp)
801E0B68	nop
801E0B6C	sll    v0, t6, $10
801E0B70	bne    v0, zero, L1e0b7c [$801e0b7c]
801E0B74	nop

L1e0b78:	; 801E0B78
801E0B78	ori    s2, zero, $0100

L1e0b7c:	; 801E0B7C
801E0B7C	lhu    v1, $0020(sp)
801E0B80	nop
801E0B84	bltz   v1, L1e1220 [$801e1220]
801E0B88	slti   v0, v1, $0002
801E0B8C	bne    v0, zero, L1e0bb0 [$801e0bb0]
801E0B90	sll    v0, s3, $10
801E0B94	slti   v0, v1, $0006
801E0B98	beq    v0, zero, L1e1220 [$801e1220]
801E0B9C	slti   v0, v1, $0004
801E0BA0	bne    v0, zero, L1e1224 [$801e1224]
801E0BA4	addu   v0, s0, zero
801E0BA8	j      L1e0e18 [$801e0e18]
801E0BAC	mult   s3, s2

L1e0bb0:	; 801E0BB0
801E0BB0	sra    v0, v0, $10
801E0BB4	addiu  v0, v0, $0001
801E0BB8	srl    v1, v0, $1f
801E0BBC	addu   v0, v0, v1
801E0BC0	sra    s1, v0, $01
801E0BC4	sll    v0, s1, $01
801E0BC8	mult   v0, s2
801E0BCC	lhu    t6, $0068(sp)
801E0BD0	nop
801E0BD4	sh     t6, $0028(s0)
801E0BD8	lhu    t6, $0070(sp)
801E0BDC	addu   s3, v0, zero
801E0BE0	sh     t6, $002a(s0)
801E0BE4	sh     s3, $002c(s0)
801E0BE8	sh     s2, $002e(s0)
801E0BEC	mflo   v0
801E0BF0	sh     v0, $0012(s0)
801E0BF4	andi   v0, s5, $0100
801E0BF8	beq    v0, zero, L1e0c24 [$801e0c24]

L1e0bfc:	; 801E0BFC
801E0BFC	sll    v0, s1, $11
801E0C00	sra    v0, v0, $10
801E0C04	sll    v1, s2, $10
801E0C08	sra    v1, v1, $10
801E0C0C	mult   v0, v1
801E0C10	addu   a1, zero, zero
801E0C14	mflo   a0
801E0C18	jal    system_memory_allocate [$800319ec]
801E0C1C	sll    a0, a0, $01
801E0C20	sw     v0, $000c(s0)

L1e0c24:	; 801E0C24
801E0C24	andi   v0, s5, $0200
801E0C28	beq    v0, zero, L1e0c54 [$801e0c54]
801E0C2C	sll    v0, s1, $11
801E0C30	sra    v0, v0, $10
801E0C34	sll    v1, s2, $10
801E0C38	sra    v1, v1, $10
801E0C3C	mult   v0, v1
801E0C40	addu   a1, zero, zero
801E0C44	mflo   a0
801E0C48	jal    system_memory_allocate [$800319ec]
801E0C4C	sll    a0, a0, $01
801E0C50	sw     v0, $0008(s0)

L1e0c54:	; 801E0C54
801E0C54	andi   v0, s5, $0400
801E0C58	beq    v0, zero, L1e0c84 [$801e0c84]
801E0C5C	sll    v0, s1, $11
801E0C60	sra    v0, v0, $10
801E0C64	sll    v1, s2, $10
801E0C68	sra    v1, v1, $10

L1e0c6c:	; 801E0C6C
801E0C6C	mult   v0, v1
801E0C70	addu   a1, zero, zero
801E0C74	mflo   a0
801E0C78	jal    system_memory_allocate [$800319ec]

L1e0c7c:	; 801E0C7C
801E0C7C	sll    a0, a0, $01
801E0C80	sw     v0, $0004(s0)

L1e0c84:	; 801E0C84
801E0C84	andi   v1, s5, $000f
801E0C88	ori    v0, zero, $0001
801E0C8C	beq    v1, v0, L1e0ca4 [$801e0ca4]
801E0C90	ori    v0, zero, $0002
801E0C94	beq    v1, v0, L1e0cdc [$801e0cdc]
801E0C98	sll    v1, s1, $11
801E0C9C	j      L1e0d4c [$801e0d4c]
801E0CA0	srl    v0, s5, $04

L1e0ca4:	; 801E0CA4
801E0CA4	lhu    t6, $0038(sp)
801E0CA8	nop
801E0CAC	sh     t6, $0010(sp)
801E0CB0	lhu    t6, $0040(sp)
801E0CB4	sh     s3, $0014(sp)
801E0CB8	sh     s2, $0016(sp)
801E0CBC	sh     t6, $0012(sp)
801E0CC0	lw     a1, $0004(s0)
801E0CC4	jal    func44770 [$80044770]
801E0CC8	addiu  a0, sp, $0010
801E0CCC	jal    func44448 [$80044448]
801E0CD0	addu   a0, zero, zero
801E0CD4	j      L1e0d4c [$801e0d4c]
801E0CD8	srl    v0, s5, $04

L1e0cdc:	; 801E0CDC
801E0CDC	sra    v1, v1, $10
801E0CE0	sll    v0, s2, $10
801E0CE4	sra    v0, v0, $10
801E0CE8	mult   v1, v0
801E0CEC	lhu    t6, $0048(sp)

L1e0cf0:	; 801E0CF0
801E0CF0	nop
801E0CF4	andi   v1, t6, $003f
801E0CF8	lhu    t6, $0040(sp)

L1e0cfc:	; 801E0CFC
801E0CFC	sll    v1, v1, $0a
801E0D00	andi   v0, t6, $001f
801E0D04	sll    v0, v0, $05
801E0D08	lhu    t6, $0038(sp)
801E0D0C	addu   v1, v1, v0
801E0D10	andi   v0, t6, $001f
801E0D14	or     a0, v1, v0
801E0D18	mflo   v0
801E0D1C	blez   v0, L1e0d48 [$801e0d48]
801E0D20	addu   a3, zero, zero
801E0D24	addu   a1, v0, zero
801E0D28	sll    v0, a3, $01

loop1e0d2c:	; 801E0D2C
801E0D2C	lw     v1, $0004(s0)
801E0D30	addiu  a3, a3, $0001
801E0D34	addu   v0, v0, v1
801E0D38	sh     a0, $0000(v0)
801E0D3C	slt    v0, a3, a1
801E0D40	bne    v0, zero, loop1e0d2c [$801e0d2c]
801E0D44	sll    v0, a3, $01

L1e0d48:	; 801E0D48
801E0D48	srl    v0, s5, $04

L1e0d4c:	; 801E0D4C
801E0D4C	andi   v1, v0, $000f
801E0D50	ori    v0, zero, $0001
801E0D54	beq    v1, v0, L1e0d6c [$801e0d6c]
801E0D58	ori    v0, zero, $0002
801E0D5C	beq    v1, v0, L1e0da4 [$801e0da4]
801E0D60	sll    v1, s3, $10
801E0D64	j      L1e1224 [$801e1224]
801E0D68	addu   v0, s0, zero

L1e0d6c:	; 801E0D6C
801E0D6C	lhu    t6, $0050(sp)
801E0D70	nop
801E0D74	sh     t6, $0010(sp)
801E0D78	lhu    t6, $0058(sp)

L1e0d7c:	; 801E0D7C
801E0D7C	sh     s3, $0014(sp)
801E0D80	sh     s2, $0016(sp)
801E0D84	sh     t6, $0012(sp)
801E0D88	lw     a1, $0008(s0)
801E0D8C	jal    func44770 [$80044770]
801E0D90	addiu  a0, sp, $0010
801E0D94	jal    func44448 [$80044448]
801E0D98	addu   a0, zero, zero
801E0D9C	j      L1e1224 [$801e1224]
801E0DA0	addu   v0, s0, zero

L1e0da4:	; 801E0DA4
801E0DA4	sra    v1, v1, $10
801E0DA8	sll    v0, s2, $10
801E0DAC	sra    v0, v0, $10
801E0DB0	mult   v1, v0
801E0DB4	lhu    t6, $0060(sp)
801E0DB8	nop
801E0DBC	andi   v1, t6, $003f
801E0DC0	lhu    t6, $0058(sp)
801E0DC4	sll    v1, v1, $0a
801E0DC8	andi   v0, t6, $001f
801E0DCC	sll    v0, v0, $05
801E0DD0	lhu    t6, $0050(sp)
801E0DD4	addu   v1, v1, v0
801E0DD8	andi   v0, t6, $001f
801E0DDC	or     a0, v1, v0
801E0DE0	mflo   v0
801E0DE4	blez   v0, L1e1220 [$801e1220]
801E0DE8	addu   a3, zero, zero
801E0DEC	addu   a1, v0, zero
801E0DF0	sll    v0, a3, $01

loop1e0df4:	; 801E0DF4
801E0DF4	lw     v1, $0008(s0)
801E0DF8	addiu  a3, a3, $0001

L1e0dfc:	; 801E0DFC
801E0DFC	addu   v0, v0, v1
801E0E00	sh     a0, $0000(v0)
801E0E04	slt    v0, a3, a1
801E0E08	bne    v0, zero, loop1e0df4 [$801e0df4]
801E0E0C	sll    v0, a3, $01
801E0E10	j      L1e1224 [$801e1224]
801E0E14	addu   v0, s0, zero

L1e0e18:	; 801E0E18
801E0E18	lhu    t6, $0068(sp)
801E0E1C	nop
801E0E20	sh     t6, $0028(s0)
801E0E24	lhu    t6, $0070(sp)
801E0E28	sh     s3, $002c(s0)
801E0E2C	sh     s2, $002e(s0)
801E0E30	sh     t6, $002a(s0)
801E0E34	mflo   v0
801E0E38	sh     v0, $0012(s0)
801E0E3C	andi   v0, s5, $0100
801E0E40	beq    v0, zero, L1e0e6c [$801e0e6c]
801E0E44	sll    v0, s3, $10
801E0E48	sra    v0, v0, $10
801E0E4C	sll    v1, s2, $10
801E0E50	sra    v1, v1, $10
801E0E54	mult   v0, v1
801E0E58	addu   a1, zero, zero

L1e0e5c:	; 801E0E5C
801E0E5C	mflo   a0
801E0E60	jal    system_memory_allocate [$800319ec]
801E0E64	sll    a0, a0, $01
801E0E68	sw     v0, $000c(s0)

L1e0e6c:	; 801E0E6C
801E0E6C	andi   v0, s5, $0200
801E0E70	beq    v0, zero, L1e0e9c [$801e0e9c]
801E0E74	sll    v0, s3, $10
801E0E78	sra    v0, v0, $10

L1e0e7c:	; 801E0E7C
801E0E7C	sll    v1, s2, $10
801E0E80	sra    v1, v1, $10
801E0E84	mult   v0, v1
801E0E88	addu   a1, zero, zero
801E0E8C	mflo   a0
801E0E90	jal    system_memory_allocate [$800319ec]
801E0E94	sll    a0, a0, $01
801E0E98	sw     v0, $0008(s0)

L1e0e9c:	; 801E0E9C
801E0E9C	andi   v0, s5, $0400
801E0EA0	beq    v0, zero, L1e0ecc [$801e0ecc]
801E0EA4	sll    v0, s3, $10
801E0EA8	sra    v0, v0, $10
801E0EAC	sll    v1, s2, $10
801E0EB0	sra    v1, v1, $10
801E0EB4	mult   v0, v1
801E0EB8	addu   a1, zero, zero
801E0EBC	mflo   a0
801E0EC0	jal    system_memory_allocate [$800319ec]
801E0EC4	sll    a0, a0, $01
801E0EC8	sw     v0, $0004(s0)

L1e0ecc:	; 801E0ECC
801E0ECC	andi   v1, s5, $000f
801E0ED0	ori    v0, zero, $0001
801E0ED4	beq    v1, v0, L1e0eec [$801e0eec]
801E0ED8	ori    v0, zero, $0002
801E0EDC	beq    v1, v0, L1e0f98 [$801e0f98]
801E0EE0	sll    v0, s2, $10
801E0EE4	j      L1e1078 [$801e1078]
801E0EE8	srl    v0, s5, $04

L1e0eec:	; 801E0EEC
801E0EEC	sll    v0, s2, $10
801E0EF0	blez   v0, L1e1074 [$801e1074]
801E0EF4	addu   a3, zero, zero
801E0EF8	sll    t3, s3, $10

L1e0efc:	; 801E0EFC
801E0EFC	lhu    t6, $0040(sp)
801E0F00	sra    t5, t3, $10
801E0F04	sll    v0, t6, $10
801E0F08	lhu    t6, $0038(sp)
801E0F0C	sra    t4, v0, $10
801E0F10	sll    v0, t6, $10
801E0F14	sra    t2, v0, $10

loop1e0f18:	; 801E0F18
801E0F18	addu   a2, zero, zero
801E0F1C	blez   t5, L1e0f78 [$801e0f78]
801E0F20	addu   t1, t3, zero
801E0F24	addu   v1, t4, a3
801E0F28	sll    v0, v1, $01
801E0F2C	addu   v0, v0, v1
801E0F30	lw     t6, $0030(sp)
801E0F34	sll    v0, v0, $01
801E0F38	addu   t0, v0, t6

loop1e0f3c:	; 801E0F3C
801E0F3C	sra    a1, t1, $10
801E0F40	mult   a3, a1
801E0F44	addu   v0, t2, a2
801E0F48	sll    v0, v0, $01
801E0F4C	addu   v0, v0, t0
801E0F50	lw     a0, $0004(s0)
801E0F54	lhu    v0, $0000(v0)
801E0F58	mflo   v1
801E0F5C	addu   v1, v1, a2
801E0F60	addiu  a2, a2, $0001
801E0F64	sll    v1, v1, $01
801E0F68	addu   v1, v1, a0
801E0F6C	slt    a1, a2, a1
801E0F70	bne    a1, zero, loop1e0f3c [$801e0f3c]
801E0F74	sh     v0, $0000(v1)

L1e0f78:	; 801E0F78
801E0F78	addiu  a3, a3, $0001

L1e0f7c:	; 801E0F7C
801E0F7C	sll    v0, s2, $10
801E0F80	sra    v0, v0, $10
801E0F84	slt    v0, a3, v0
801E0F88	bne    v0, zero, loop1e0f18 [$801e0f18]
801E0F8C	srl    v0, s5, $04
801E0F90	j      L1e1078 [$801e1078]
801E0F94	nop

L1e0f98:	; 801E0F98
801E0F98	blez   v0, L1e1074 [$801e1074]
801E0F9C	addu   a3, zero, zero
801E0FA0	sll    v0, s3, $10
801E0FA4	sra    t0, v0, $10
801E0FA8	lhu    t6, $0070(sp)
801E0FAC	lui    t1, $5555
801E0FB0	ori    t1, t1, $5556
801E0FB4	addu   a1, zero, zero
801E0FB8	sll    v0, t6, $10
801E0FBC	sra    t2, v0, $10

loop1e0fc0:	; 801E0FC0
801E0FC0	blez   t0, L1e105c [$801e105c]
801E0FC4	addu   a2, zero, zero
801E0FC8	addu   a0, t2, a3
801E0FCC	mult   a0, t1

L1e0fd0:	; 801E0FD0
801E0FD0	sra    v0, a0, $1f
801E0FD4	mfhi   v1
801E0FD8	subu   v1, v1, v0
801E0FDC	sll    v0, v1, $01
801E0FE0	addu   v0, v0, v1
801E0FE4	subu   a0, a0, v0
801E0FE8	ori    v0, zero, $0001

loop1e0fec:	; 801E0FEC
801E0FEC	beq    a0, v0, L1e102c [$801e102c]
801E0FF0	slti   v0, a0, $0002
801E0FF4	beq    v0, zero, L1e100c [$801e100c]
801E0FF8	nop

L1e0ffc:	; 801E0FFC
801E0FFC	beq    a0, zero, L1e1020 [$801e1020]
801E1000	addu   v0, a1, a2
801E1004	j      L1e103c [$801e103c]
801E1008	nop

L1e100c:	; 801E100C
801E100C	ori    v0, zero, $0002
801E1010	beq    a0, v0, L1e1038 [$801e1038]
801E1014	addu   v0, a1, a2
801E1018	j      L1e103c [$801e103c]
801E101C	nop

L1e1020:	; 801E1020
801E1020	lhu    s1, $0038(sp)
801E1024	j      L1e103c [$801e103c]
801E1028	nop

L1e102c:	; 801E102C
801E102C	lhu    s1, $0040(sp)
801E1030	j      L1e103c [$801e103c]
801E1034	addu   v0, a1, a2

L1e1038:	; 801E1038
801E1038	lhu    s1, $0048(sp)

L1e103c:	; 801E103C
801E103C	addiu  a2, a2, $0001
801E1040	lw     v1, $0004(s0)
801E1044	sll    v0, v0, $01
801E1048	addu   v0, v0, v1
801E104C	sh     s1, $0000(v0)
801E1050	slt    v0, a2, t0
801E1054	bne    v0, zero, loop1e0fec [$801e0fec]
801E1058	ori    v0, zero, $0001

L1e105c:	; 801E105C
801E105C	addiu  a3, a3, $0001
801E1060	sll    v0, s2, $10
801E1064	sra    v0, v0, $10
801E1068	slt    v0, a3, v0
801E106C	bne    v0, zero, loop1e0fc0 [$801e0fc0]
801E1070	addu   a1, a1, t0

L1e1074:	; 801E1074
801E1074	srl    v0, s5, $04

L1e1078:	; 801E1078
801E1078	andi   v1, v0, $000f
801E107C	ori    v0, zero, $0001
801E1080	beq    v1, v0, L1e1098 [$801e1098]
801E1084	ori    v0, zero, $0002
801E1088	beq    v1, v0, L1e1144 [$801e1144]
801E108C	sll    v0, s2, $10
801E1090	j      L1e1224 [$801e1224]
801E1094	addu   v0, s0, zero

L1e1098:	; 801E1098
801E1098	sll    v0, s2, $10
801E109C	blez   v0, L1e1220 [$801e1220]
801E10A0	addu   a3, zero, zero
801E10A4	sll    t3, s3, $10
801E10A8	lhu    t6, $0058(sp)
801E10AC	sra    t5, t3, $10

L1e10b0:	; 801E10B0
801E10B0	sll    v0, t6, $10

L1e10b4:	; 801E10B4
801E10B4	lhu    t6, $0050(sp)
801E10B8	sra    t4, v0, $10
801E10BC	sll    v0, t6, $10
801E10C0	sra    t2, v0, $10
801E10C4	addu   a2, zero, zero

loop1e10c8:	; 801E10C8
801E10C8	blez   t5, L1e1124 [$801e1124]
801E10CC	addu   t1, t3, zero
801E10D0	addu   v1, t4, a3
801E10D4	sll    v0, v1, $01
801E10D8	addu   v0, v0, v1
801E10DC	lw     t6, $0030(sp)
801E10E0	sll    v0, v0, $01
801E10E4	addu   t0, v0, t6

loop1e10e8:	; 801E10E8
801E10E8	sra    a1, t1, $10
801E10EC	mult   a3, a1
801E10F0	addu   v0, t2, a2
801E10F4	sll    v0, v0, $01
801E10F8	addu   v0, v0, t0
801E10FC	lw     a0, $0008(s0)
801E1100	lhu    v0, $0000(v0)
801E1104	mflo   v1
801E1108	addu   v1, v1, a2
801E110C	addiu  a2, a2, $0001
801E1110	sll    v1, v1, $01
801E1114	addu   v1, v1, a0
801E1118	slt    a1, a2, a1
801E111C	bne    a1, zero, loop1e10e8 [$801e10e8]
801E1120	sh     v0, $0000(v1)

L1e1124:	; 801E1124
801E1124	addiu  a3, a3, $0001
801E1128	sll    v0, s2, $10
801E112C	sra    v0, v0, $10

L1e1130:	; 801E1130
801E1130	slt    v0, a3, v0
801E1134	bne    v0, zero, loop1e10c8 [$801e10c8]
801E1138	addu   a2, zero, zero
801E113C	j      L1e1224 [$801e1224]
801E1140	addu   v0, s0, zero

L1e1144:	; 801E1144
801E1144	blez   v0, L1e1220 [$801e1220]
801E1148	addu   a3, zero, zero
801E114C	sll    v0, s3, $10
801E1150	sra    t0, v0, $10
801E1154	lhu    t6, $0070(sp)
801E1158	lui    t1, $5555
801E115C	ori    t1, t1, $5556
801E1160	addu   a1, zero, zero
801E1164	sll    v0, t6, $10
801E1168	sra    t2, v0, $10

loop1e116c:	; 801E116C
801E116C	blez   t0, L1e1208 [$801e1208]
801E1170	addu   a2, zero, zero
801E1174	addu   a0, t2, a3
801E1178	mult   a0, t1
801E117C	sra    v0, a0, $1f
801E1180	mfhi   v1
801E1184	subu   v1, v1, v0
801E1188	sll    v0, v1, $01
801E118C	addu   v0, v0, v1
801E1190	subu   a0, a0, v0
801E1194	ori    v0, zero, $0001

loop1e1198:	; 801E1198
801E1198	beq    a0, v0, L1e11d8 [$801e11d8]
801E119C	slti   v0, a0, $0002
801E11A0	beq    v0, zero, L1e11b8 [$801e11b8]
801E11A4	nop
801E11A8	beq    a0, zero, L1e11cc [$801e11cc]
801E11AC	addu   v0, a1, a2
801E11B0	j      L1e11e8 [$801e11e8]
801E11B4	nop

L1e11b8:	; 801E11B8
801E11B8	ori    v0, zero, $0002
801E11BC	beq    a0, v0, L1e11e4 [$801e11e4]
801E11C0	addu   v0, a1, a2
801E11C4	j      L1e11e8 [$801e11e8]
801E11C8	nop

L1e11cc:	; 801E11CC
801E11CC	lhu    s1, $0050(sp)
801E11D0	j      L1e11e8 [$801e11e8]
801E11D4	nop

L1e11d8:	; 801E11D8
801E11D8	lhu    s1, $0058(sp)
801E11DC	j      L1e11e8 [$801e11e8]
801E11E0	addu   v0, a1, a2

L1e11e4:	; 801E11E4
801E11E4	lhu    s1, $0060(sp)

L1e11e8:	; 801E11E8
801E11E8	addiu  a2, a2, $0001
801E11EC	lw     v1, $0008(s0)
801E11F0	sll    v0, v0, $01

L1e11f4:	; 801E11F4
801E11F4	addu   v0, v0, v1
801E11F8	sh     s1, $0000(v0)
801E11FC	slt    v0, a2, t0
801E1200	bne    v0, zero, loop1e1198 [$801e1198]
801E1204	ori    v0, zero, $0001

L1e1208:	; 801E1208
801E1208	addiu  a3, a3, $0001
801E120C	sll    v0, s2, $10
801E1210	sra    v0, v0, $10
801E1214	slt    v0, a3, v0
801E1218	bne    v0, zero, loop1e116c [$801e116c]
801E121C	addu   a1, a1, t0

L1e1220:	; 801E1220
801E1220	addu   v0, s0, zero

L1e1224:	; 801E1224
801E1224	lw     ra, $0104(sp)
801E1228	lw     fp, $0100(sp)
801E122C	lw     s7, $00fc(sp)
801E1230	lw     s6, $00f8(sp)
801E1234	lw     s5, $00f4(sp)
801E1238	lw     s4, $00f0(sp)
801E123C	lw     s3, $00ec(sp)
801E1240	lw     s2, $00e8(sp)
801E1244	lw     s1, $00e4(sp)
801E1248	lw     s0, $00e0(sp)
801E124C	addiu  sp, sp, $0108
801E1250	jr     ra 
801E1254	nop


func1e1258:	; 801E1258
801E1258	addiu  sp, sp, $ff88 (=-$78)
801E125C	sw     s0, $0068(sp)
801E1260	addu   s0, a0, zero
801E1264	sw     ra, $0074(sp)
801E1268	sw     s2, $0070(sp)
801E126C	sw     s1, $006c(sp)
801E1270	lhu    v0, $001a(s0)
801E1274	nop
801E1278	bne    v0, zero, L1e1288 [$801e1288]
801E127C	addiu  v0, a1, $0001
801E1280	j      L1e1640 [$801e1640]
801E1284	addiu  v0, zero, $ffff (=-$1)

L1e1288:	; 801E1288
801E1288	lhu    v1, $0016(s0)
801E128C	nop
801E1290	mult   v1, v0
801E1294	lh     a1, $0020(s0)

L1e1298:	; 801E1298
801E1298	lh     a2, $0022(s0)
801E129C	lhu    v0, $0014(s0)
801E12A0	mflo   v1
801E12A4	addu   v0, v0, v1
801E12A8	sh     v0, $0014(s0)
801E12AC	lhu    a0, $0014(s0)
801E12B0	lw     v0, $0024(s0)
801E12B4	nop
801E12B8	jalr   v0 ra
801E12BC	nop
801E12C0	addu   s2, v0, zero
801E12C4	sll    v0, s2, $10
801E12C8	sra    s1, v0, $10
801E12CC	bgez   s1, L1e12e4 [$801e12e4]
801E12D0	nop
801E12D4	jal    func1e165c [$801e165c]
801E12D8	addu   a0, s0, zero
801E12DC	j      L1e1640 [$801e1640]
801E12E0	addu   v0, s1, zero

L1e12e4:	; 801E12E4
801E12E4	lhu    v0, $0018(s0)
801E12E8	nop
801E12EC	beq    s1, v0, L1e1640 [$801e1640]
801E12F0	nop
801E12F4	lbu    v1, $0010(s0)
801E12F8	ori    v0, zero, $0001
801E12FC	beq    v1, v0, L1e1358 [$801e1358]
801E1300	sh     s2, $0018(s0)
801E1304	slti   v0, v1, $0002
801E1308	beq    v0, zero, L1e1320 [$801e1320]
801E130C	nop
801E1310	beq    v1, zero, L1e133c [$801e133c]
801E1314	nop
801E1318	j      L1e13b4 [$801e13b4]
801E131C	nop

L1e1320:	; 801E1320
801E1320	ori    v0, zero, $0004
801E1324	beq    v1, v0, L1e1398 [$801e1398]
801E1328	ori    v0, zero, $0005
801E132C	beq    v1, v0, L1e13ac [$801e13ac]
801E1330	addu   a0, s0, zero
801E1334	j      L1e13b4 [$801e13b4]
801E1338	nop

L1e133c:	; 801E133C
801E133C	lh     a0, $0012(s0)
801E1340	lw     a2, $000c(s0)
801E1344	lw     a3, $0004(s0)
801E1348	jal    func26d54 [$80026d54]
801E134C	addu   a1, s1, zero
801E1350	j      L1e1374 [$801e1374]
801E1354	nop

L1e1358:	; 801E1358
801E1358	lw     v0, $0004(s0)
801E135C	lh     a0, $0012(s0)
801E1360	sw     v0, $0010(sp)
801E1364	lw     a2, $000c(s0)
801E1368	lw     a3, $0008(s0)
801E136C	jal    func26df8 [$80026df8]
801E1370	addu   a1, s1, zero

L1e1374:	; 801E1374
801E1374	lw     v0, $0000(s0)
801E1378	nop
801E137C	bne    v0, zero, L1e13b4 [$801e13b4]
801E1380	nop
801E1384	lw     a1, $000c(s0)
801E1388	jal    func4470c [$8004470c]
801E138C	addiu  a0, s0, $0028
801E1390	j      L1e13b4 [$801e13b4]
801E1394	nop

L1e1398:	; 801E1398
801E1398	addu   a0, s0, zero
801E139C	jal    func1e1708 [$801e1708]
801E13A0	addu   a1, s1, zero
801E13A4	j      L1e13b4 [$801e13b4]
801E13A8	nop

L1e13ac:	; 801E13AC
801E13AC	jal    func1e17b8 [$801e17b8]
801E13B0	addu   a1, s1, zero

L1e13b4:	; 801E13B4
801E13B4	lw     t1, $0000(s0)
801E13B8	nop
801E13BC	beq    t1, zero, L1e163c [$801e163c]
801E13C0	sll    v0, s2, $10
801E13C4	lhu    v0, $001a(t1)
801E13C8	nop
801E13CC	beq    v0, zero, L1e163c [$801e163c]
801E13D0	sll    v0, s2, $10
801E13D4	lh     v0, $0028(t1)
801E13D8	lh     v1, $0028(s0)
801E13DC	addu   a1, v0, zero
801E13E0	slt    v0, v0, v1
801E13E4	beq    v0, zero, L1e140c [$801e140c]
801E13E8	addu   a0, v1, zero
801E13EC	subu   v0, a0, a1
801E13F0	sh     v0, $0020(sp)
801E13F4	sh     zero, $0018(sp)
801E13F8	lhu    v0, $0028(t1)
801E13FC	lhu    v1, $002c(t1)
801E1400	lhu    a0, $0028(s0)
801E1404	j      L1e1434 [$801e1434]
801E1408	addu   v0, v0, v1

L1e140c:	; 801E140C
801E140C	sh     zero, $0020(sp)
801E1410	lhu    v0, $0028(t1)
801E1414	lhu    v1, $0028(s0)
801E1418	nop
801E141C	subu   v0, v0, v1

L1e1420:	; 801E1420
801E1420	sh     v0, $0018(sp)
801E1424	lhu    v0, $0028(s0)
801E1428	lhu    v1, $002c(s0)

L1e142c:	; 801E142C
801E142C	lhu    a0, $0028(t1)
801E1430	addu   v0, v0, v1

L1e1434:	; 801E1434
801E1434	subu   v0, v0, a0
801E1438	sh     v0, $0024(sp)
801E143C	lh     v0, $002a(t1)
801E1440	lh     v1, $002a(s0)
801E1444	addu   a1, v0, zero
801E1448	slt    v0, v0, v1
801E144C	beq    v0, zero, L1e1474 [$801e1474]
801E1450	addu   a0, v1, zero
801E1454	subu   v0, a0, a1
801E1458	sh     v0, $0022(sp)
801E145C	sh     zero, $001a(sp)
801E1460	lhu    v0, $002a(t1)
801E1464	lhu    v1, $002e(t1)
801E1468	lhu    a0, $002a(s0)
801E146C	j      L1e149c [$801e149c]
801E1470	addu   v0, v0, v1

L1e1474:	; 801E1474
801E1474	sh     zero, $0022(sp)
801E1478	lhu    v0, $002a(t1)
801E147C	lhu    v1, $002a(s0)
801E1480	nop
801E1484	subu   v0, v0, v1
801E1488	sh     v0, $001a(sp)
801E148C	lhu    v0, $002a(s0)
801E1490	lhu    v1, $002e(s0)
801E1494	lhu    a0, $002a(t1)
801E1498	addu   v0, v0, v1

L1e149c:	; 801E149C
801E149C	subu   v0, v0, a0
801E14A0	sh     v0, $0026(sp)
801E14A4	lh     v0, $0024(sp)
801E14A8	nop
801E14AC	blez   v0, L1e163c [$801e163c]

L1e14b0:	; 801E14B0
801E14B0	sll    v0, s2, $10
801E14B4	lh     v0, $0026(sp)
801E14B8	nop
801E14BC	blez   v0, L1e1638 [$801e1638]
801E14C0	ori    v0, zero, $0001
801E14C4	lbu    v1, $0010(t1)
801E14C8	lw     t3, $0004(t1)
801E14CC	sltiu  v1, v1, $0004
801E14D0	beq    v1, zero, L1e158c [$801e158c]
801E14D4	sb     v0, $0011(t1)
801E14D8	lh     v0, $0026(sp)
801E14DC	lw     t2, $000c(s0)
801E14E0	blez   v0, L1e1638 [$801e1638]
801E14E4	addu   t0, zero, zero

loop1e14e8:	; 801E14E8
801E14E8	lh     v0, $0024(sp)

L1e14ec:	; 801E14EC
801E14EC	nop
801E14F0	blez   v0, L1e1570 [$801e1570]
801E14F4	addu   a3, zero, zero

loop1e14f8:	; 801E14F8
801E14F8	lh     v0, $0022(sp)
801E14FC	lh     v1, $002c(t1)
801E1500	addu   v0, v0, t0
801E1504	mult   v0, v1
801E1508	lh     v0, $001a(sp)
801E150C	mflo   a2
801E1510	lh     v1, $002c(s0)
801E1514	addu   v0, v0, t0
801E1518	mult   v0, v1
801E151C	lh     a0, $0020(sp)
801E1520	sll    a1, a3, $01
801E1524	sll    a0, a0, $01
801E1528	addu   a0, a0, t3
801E152C	addu   a0, a1, a0
801E1530	lh     v0, $0018(sp)
801E1534	sll    a2, a2, $01
801E1538	sll    v0, v0, $01

L1e153c:	; 801E153C
801E153C	addu   v0, v0, t2
801E1540	addu   a1, a1, v0
801E1544	mflo   v1
801E1548	sll    v1, v1, $01
801E154C	addu   v1, v1, a1
801E1550	lhu    v0, $0000(v1)
801E1554	addu   a2, a2, a0
801E1558	sh     v0, $0000(a2)
801E155C	lh     v0, $0024(sp)
801E1560	addiu  a3, a3, $0001
801E1564	slt    v0, a3, v0
801E1568	bne    v0, zero, loop1e14f8 [$801e14f8]
801E156C	nop

L1e1570:	; 801E1570
801E1570	lh     v0, $0026(sp)
801E1574	addiu  t0, t0, $0001
801E1578	slt    v0, t0, v0
801E157C	bne    v0, zero, loop1e14e8 [$801e14e8]
801E1580	sll    v0, s2, $10
801E1584	j      L1e163c [$801e163c]
801E1588	nop

L1e158c:	; 801E158C
801E158C	lh     v0, $0026(sp)
801E1590	nop
801E1594	blez   v0, L1e1638 [$801e1638]
801E1598	addu   t0, zero, zero

loop1e159c:	; 801E159C
801E159C	lh     v0, $0024(sp)
801E15A0	nop
801E15A4	blez   v0, L1e1624 [$801e1624]
801E15A8	addu   a3, zero, zero
801E15AC	sll    a2, a3, $01

loop1e15b0:	; 801E15B0
801E15B0	lh     v0, $0022(sp)
801E15B4	lh     v1, $002c(t1)
801E15B8	lh     a0, $001a(sp)
801E15BC	addu   v0, v0, t0
801E15C0	addu   a0, a0, t0
801E15C4	mult   v0, v1
801E15C8	sll    v1, a0, $01
801E15CC	addu   v1, v1, a0
801E15D0	sll    v1, v1, $01
801E15D4	lh     v0, $0020(sp)
801E15D8	lw     a0, $001c(s0)
801E15DC	sll    v0, v0, $01
801E15E0	addu   v0, v0, t3
801E15E4	addu   a2, a2, v0
801E15E8	lh     v0, $0018(sp)
801E15EC	addu   v1, v1, a0

L1e15f0:	; 801E15F0
801E15F0	addu   v0, v0, a3
801E15F4	sll    v0, v0, $01
801E15F8	addu   v0, v0, v1
801E15FC	lhu    v0, $0000(v0)
801E1600	mflo   a1
801E1604	sll    a1, a1, $01
801E1608	addu   a1, a1, a2

L1e160c:	; 801E160C
801E160C	sh     v0, $0000(a1)
801E1610	lh     v0, $0024(sp)
801E1614	addiu  a3, a3, $0001
801E1618	slt    v0, a3, v0
801E161C	bne    v0, zero, loop1e15b0 [$801e15b0]
801E1620	sll    a2, a3, $01

L1e1624:	; 801E1624
801E1624	lh     v0, $0026(sp)
801E1628	addiu  t0, t0, $0001
801E162C	slt    v0, t0, v0
801E1630	bne    v0, zero, loop1e159c [$801e159c]
801E1634	nop

L1e1638:	; 801E1638
801E1638	sll    v0, s2, $10

L1e163c:	; 801E163C
801E163C	sra    v0, v0, $10

L1e1640:	; 801E1640
801E1640	lw     ra, $0074(sp)
801E1644	lw     s2, $0070(sp)
801E1648	lw     s1, $006c(sp)
801E164C	lw     s0, $0068(sp)
801E1650	addiu  sp, sp, $0078
801E1654	jr     ra 
801E1658	nop


func1e165c:	; 801E165C
801E165C	addiu  sp, sp, $ffe8 (=-$18)
801E1660	sw     s0, $0010(sp)
801E1664	addu   s0, a0, zero
801E1668	sw     ra, $0014(sp)
801E166C	lhu    v0, $001a(s0)
801E1670	nop
801E1674	beq    v0, zero, L1e16f4 [$801e16f4]
801E1678	nop
801E167C	lw     a1, $0004(s0)
801E1680	nop
801E1684	beq    a1, zero, L1e16b8 [$801e16b8]
801E1688	nop
801E168C	lbu    v0, $0010(s0)
801E1690	nop
801E1694	sltiu  v0, v0, $0004
801E1698	beq    v0, zero, L1e16a8 [$801e16a8]
801E169C	nop
801E16A0	jal    func4470c [$8004470c]
801E16A4	addiu  a0, s0, $0028

L1e16a8:	; 801E16A8
801E16A8	lw     a0, $0004(s0)
801E16AC	jal    func31f0c [$80031f0c]
801E16B0	nop
801E16B4	sw     zero, $0004(s0)

L1e16b8:	; 801E16B8
801E16B8	lw     a0, $0008(s0)
801E16BC	nop
801E16C0	beq    a0, zero, L1e16d4 [$801e16d4]
801E16C4	nop
801E16C8	jal    func31f0c [$80031f0c]
801E16CC	nop
801E16D0	sw     zero, $0008(s0)

L1e16d4:	; 801E16D4
801E16D4	lw     a0, $000c(s0)
801E16D8	nop
801E16DC	beq    a0, zero, L1e16f0 [$801e16f0]
801E16E0	nop
801E16E4	jal    func31f0c [$80031f0c]
801E16E8	nop
801E16EC	sw     zero, $000c(s0)

L1e16f0:	; 801E16F0
801E16F0	sh     zero, $001a(s0)

L1e16f4:	; 801E16F4
801E16F4	lw     ra, $0014(sp)
801E16F8	lw     s0, $0010(sp)
801E16FC	addiu  sp, sp, $0018
801E1700	jr     ra 
801E1704	nop


func1e1708:	; 801E1708
801E1708	addiu  sp, sp, $fff0 (=-$10)
801E170C	addu   a3, a0, zero
801E1710	lh     v0, $002e(a3)
801E1714	lw     t1, $0004(a3)
801E1718	blez   v0, L1e17ac [$801e17ac]
801E171C	addu   t0, zero, zero
801E1720	sll    v0, a1, $10
801E1724	sra    t2, v0, $10

loop1e1728:	; 801E1728
801E1728	lh     v0, $002c(a3)
801E172C	nop
801E1730	blez   v0, L1e1798 [$801e1798]
801E1734	addu   a2, zero, zero

loop1e1738:	; 801E1738
801E1738	lhu    v0, $0000(t1)
801E173C	nop
801E1740	mult   v0, t2
801E1744	lh     v0, $002a(a3)
801E1748	lw     a0, $001c(a3)
801E174C	addu   v0, v0, t0
801E1750	sll    v1, v0, $01
801E1754	addu   v1, v1, v0
801E1758	sll    v1, v1, $01
801E175C	lh     v0, $0028(a3)
801E1760	addu   v1, v1, a0
801E1764	addu   v0, v0, a2
801E1768	sll    v0, v0, $01
801E176C	mflo   a1
801E1770	bgez   a1, L1e177c [$801e177c]
801E1774	addu   v1, v0, v1
801E1778	addiu  a1, a1, $001f

L1e177c:	; 801E177C
801E177C	sra    v0, a1, $05
801E1780	sh     v0, $0000(v1)
801E1784	lh     v0, $002c(a3)
801E1788	addiu  a2, a2, $0001
801E178C	slt    v0, a2, v0
801E1790	bne    v0, zero, loop1e1738 [$801e1738]
801E1794	addiu  t1, t1, $0002

L1e1798:	; 801E1798
801E1798	lh     v0, $002e(a3)
801E179C	addiu  t0, t0, $0001
801E17A0	slt    v0, t0, v0
801E17A4	bne    v0, zero, loop1e1728 [$801e1728]
801E17A8	nop

L1e17ac:	; 801E17AC
801E17AC	addiu  sp, sp, $0010
801E17B0	jr     ra 
801E17B4	nop


func1e17b8:	; 801E17B8
801E17B8	addiu  sp, sp, $fff0 (=-$10)
801E17BC	addu   a3, a0, zero
801E17C0	lw     t2, $0004(a3)
801E17C4	lh     v0, $002e(a3)
801E17C8	lw     t0, $0008(a3)
801E17CC	blez   v0, L1e1874 [$801e1874]
801E17D0	addu   t1, zero, zero
801E17D4	sll    v0, a1, $10
801E17D8	sra    t3, v0, $10

loop1e17dc:	; 801E17DC
801E17DC	lh     v0, $002c(a3)
801E17E0	nop
801E17E4	blez   v0, L1e1860 [$801e1860]
801E17E8	addu   a2, zero, zero

loop1e17ec:	; 801E17EC
801E17EC	lhu    v0, $0000(t2)
801E17F0	lhu    v1, $0000(t0)
801E17F4	nop
801E17F8	subu   v0, v0, v1
801E17FC	mult   v0, t3
801E1800	lh     v0, $002a(a3)
801E1804	lw     a0, $001c(a3)
801E1808	addu   v0, v0, t1
801E180C	sll    v1, v0, $01
801E1810	addu   v1, v1, v0
801E1814	sll    v1, v1, $01
801E1818	lh     v0, $0028(a3)
801E181C	addu   v1, v1, a0
801E1820	addu   v0, v0, a2
801E1824	sll    v0, v0, $01
801E1828	mflo   a1
801E182C	bgez   a1, L1e1838 [$801e1838]
801E1830	addu   a0, v0, v1
801E1834	addiu  a1, a1, $001f

L1e1838:	; 801E1838
801E1838	addiu  t2, t2, $0002
801E183C	lhu    v0, $0000(t0)
801E1840	sra    v1, a1, $05

L1e1844:	; 801E1844
801E1844	addu   v0, v0, v1
801E1848	sh     v0, $0000(a0)
801E184C	lh     v0, $002c(a3)
801E1850	addiu  a2, a2, $0001
801E1854	slt    v0, a2, v0
801E1858	bne    v0, zero, loop1e17ec [$801e17ec]
801E185C	addiu  t0, t0, $0002

L1e1860:	; 801E1860
801E1860	lh     v0, $002e(a3)
801E1864	addiu  t1, t1, $0001
801E1868	slt    v0, t1, v0
801E186C	bne    v0, zero, loop1e17dc [$801e17dc]
801E1870	nop

L1e1874:	; 801E1874
801E1874	addiu  sp, sp, $0010
801E1878	jr     ra 
801E187C	nop


func1e1880:	; 801E1880
801E1880	addiu  sp, sp, $ffc0 (=-$40)
801E1884	sw     s5, $0034(sp)
801E1888	addu   s5, a0, zero
801E188C	sw     s4, $0030(sp)
801E1890	lui    s4, $1f80
801E1894	sw     s1, $0024(sp)
801E1898	lui    s1, $801f
801E189C	addiu  s1, s1, $864c (=-$79b4)
801E18A0	sw     s3, $002c(sp)
801E18A4	addiu  s3, s1, $fffe (=-$2)
801E18A8	sw     s2, $0028(sp)

L1e18ac:	; 801E18AC
801E18AC	addiu  s2, s1, $fffc (=-$4)
801E18B0	sw     s0, $0020(sp)
801E18B4	addu   s0, zero, zero
801E18B8	sw     ra, $0038(sp)

L1e18bc:	; 801E18BC
801E18BC	lui    at, $801f
801E18C0	addu   at, at, s0
801E18C4	lh     v0, $864e(at)
801E18C8	nop
801E18CC	beq    v0, zero, L1e19cc [$801e19cc]
801E18D0	nop
801E18D4	lui    at, $801f
801E18D8	addu   at, at, s0
801E18DC	lh     v0, $8658(at)
801E18E0	nop
801E18E4	bltz   v0, L1e1990 [$801e1990]
801E18E8	sll    v0, v0, $02
801E18EC	addu   v0, v0, s5
801E18F0	lw     v0, $0000(v0)
801E18F4	nop
801E18F8	beq    v0, zero, L1e1990 [$801e1990]
801E18FC	addu   a2, s4, zero
801E1900	lw     v1, $0004(v0)
801E1904	lui    at, $801f
801E1908	addu   at, at, s0
801E190C	lh     v0, $865a(at)
801E1910	addiu  a0, v1, $000c
801E1914	sll    a1, v0, $05
801E1918	subu   a1, a1, v0

L1e191c:	; 801E191C
801E191C	sll    a1, a1, $02
801E1920	addu   a1, a1, v1
801E1924	jal    func491c4 [$800491c4]
801E1928	addiu  a1, a1, $00a8
801E192C	jal    func49da4 [$80049da4]
801E1930	addu   a0, s4, zero
801E1934	jal    func49e34 [$80049e34]
801E1938	addu   a0, s4, zero
801E193C	lui    v0, $801f
801E1940	addiu  v0, v0, $8650 (=-$79b0)
801E1944	addu   v0, s0, v0
801E1948	lwc2   zero, $0000(v0)
801E194C	lwc2   at, $0004(v0)
801E1950	nop
801E1954	nop
801E1958	gte_func18t0,r11r12
801E195C	addiu  v0, sp, $0010
801E1960	swc2   t9, $0000(v0)
801E1964	swc2   k0, $0004(v0)
801E1968	swc2   k1, $0008(v0)
801E196C	lhu    v0, $0010(sp)
801E1970	nop
801E1974	sh     v0, $0000(s2)
801E1978	lhu    v0, $0014(sp)
801E197C	nop
801E1980	sh     v0, $0000(s3)
801E1984	lhu    v0, $0018(sp)
801E1988	j      L1e19cc [$801e19cc]
801E198C	sh     v0, $0000(s1)

L1e1990:	; 801E1990
801E1990	lui    at, $801f
801E1994	addu   at, at, s0
801E1998	lhu    v0, $8650(at)
801E199C	nop
801E19A0	sh     v0, $0000(s2)
801E19A4	lui    at, $801f
801E19A8	addu   at, at, s0
801E19AC	lhu    v0, $8652(at)
801E19B0	nop
801E19B4	sh     v0, $0000(s3)
801E19B8	lui    at, $801f
801E19BC	addu   at, at, s0
801E19C0	lhu    v0, $8654(at)
801E19C4	nop
801E19C8	sh     v0, $0000(s1)

L1e19cc:	; 801E19CC
801E19CC	addiu  s1, s1, $0014
801E19D0	addiu  s3, s3, $0014
801E19D4	addiu  s2, s2, $0014
801E19D8	lui    v0, $801f
801E19DC	addiu  v0, v0, $8674 (=-$798c)
801E19E0	slt    v0, s1, v0
801E19E4	bne    v0, zero, L1e18bc [$801e18bc]
801E19E8	addiu  s0, s0, $0014
801E19EC	lw     ra, $0038(sp)
801E19F0	lw     s5, $0034(sp)
801E19F4	lw     s4, $0030(sp)
801E19F8	lw     s3, $002c(sp)
801E19FC	lw     s2, $0028(sp)
801E1A00	lw     s1, $0024(sp)
801E1A04	lw     s0, $0020(sp)
801E1A08	addiu  sp, sp, $0040
801E1A0C	jr     ra 
801E1A10	nop



////////////////////////////////
// func1e1a14
801E1A14-801E22F4
////////////////////////////////



func1e22f8:	; 801E22F8
801E22F8	addiu  sp, sp, $ff28 (=-$d8)
801E22FC	sw     s6, $00c8(sp)
801E2300	lw     s6, $00ec(sp)
801E2304	sw     s4, $00c0(sp)
801E2308	addu   s4, a0, zero
801E230C	sw     s7, $00cc(sp)
801E2310	sw     ra, $00d4(sp)
801E2314	sw     fp, $00d0(sp)
801E2318	sw     s5, $00c4(sp)
801E231C	sw     s3, $00bc(sp)
801E2320	sw     s2, $00b8(sp)
801E2324	sw     s1, $00b4(sp)
801E2328	sw     s0, $00b0(sp)
801E232C	sw     a2, $0078(sp)
801E2330	sw     a3, $0080(sp)
801E2334	lw     v0, $0014(s4)
801E2338	lhu    fp, $00f0(sp)
801E233C	beq    v0, zero, L1e3404 [$801e3404]
801E2340	addu   s7, a1, zero
801E2344	lw     v0, $0020(s4)
801E2348	nop
801E234C	lbu    v0, $000f(v0)
801E2350	nop
801E2354	sb     v0, $0063(sp)
801E2358	lh     v0, $0004(s4)
801E235C	nop
801E2360	blez   v0, L1e29bc [$801e29bc]
801E2364	addu   s5, zero, zero
801E2368	lui    s3, $000f
801E236C	ori    s3, s3, $ffff

L1e2370:	; 801E2370
801E2370	lw     v0, $001c(s4)
801E2374	sll    v1, s5, $02
801E2378	addu   v1, v1, v0
801E237C	lw     s2, $0000(v1)
801E2380	nop
801E2384	lh     v0, $0000(s2)
801E2388	nop
801E238C	beq    v0, zero, L1e29a8 [$801e29a8]
801E2390	nop
801E2394	addiu  s0, s2, $0020

L1e2398:	; 801E2398
801E2398	lh     v0, $fffc(s0)
801E239C	lh     v1, $ffe4(s0)
801E23A0	lh     a0, $0000(s7)
801E23A4	subu   v0, v0, v1
801E23A8	addu   v0, v0, a0
801E23AC	mult   v0, v0
801E23B0	sw     v0, $0010(sp)
801E23B4	lh     v0, $fffe(s0)
801E23B8	lh     v1, $ffe6(s0)
801E23BC	lh     a0, $ffe2(s0)
801E23C0	subu   v0, v0, v1
801E23C4	lh     v1, $0002(s7)
801E23C8	mflo   a1
801E23CC	addu   v0, v0, v1
801E23D0	addu   v0, v0, a0
801E23D4	mult   v0, v0
801E23D8	sw     v0, $0014(sp)
801E23DC	lh     v1, $ffe8(s0)
801E23E0	lh     a0, $0004(s7)
801E23E4	lh     v0, $0000(s0)
801E23E8	mflo   a2
801E23EC	subu   v0, v0, v1
801E23F0	addu   v0, v0, a0
801E23F4	mult   v0, v0
801E23F8	sw     v0, $0018(sp)
801E23FC	addu   a1, a1, a2
801E2400	mflo   a0
801E2404	jal    system_square_root [$80048af4]
801E2408	addu   a0, a1, a0
801E240C	addu   a2, v0, zero
801E2410	beq    a2, zero, L1e24d0 [$801e24d0]
801E2414	nop
801E2418	lw     a0, $0010(sp)
801E241C	nop
801E2420	sll    a0, a0, $08
801E2424	div    a0, a2
801E2428	bne    a2, zero, L1e2434 [$801e2434]
801E242C	nop
801E2430	break   $01c00

L1e2434:	; 801E2434
801E2434	addiu  at, zero, $ffff (=-$1)
801E2438	bne    a2, at, L1e244c [$801e244c]
801E243C	lui    at, $8000
801E2440	bne    a0, at, L1e244c [$801e244c]

L1e2444:	; 801E2444
801E2444	nop
801E2448	break   $01800

L1e244c:	; 801E244C
801E244C	mflo   a0
801E2450	lw     v1, $0014(sp)
801E2454	nop
801E2458	sll    v1, v1, $08
801E245C	div    v1, a2
801E2460	bne    a2, zero, L1e246c [$801e246c]
801E2464	nop
801E2468	break   $01c00

L1e246c:	; 801E246C
801E246C	addiu  at, zero, $ffff (=-$1)
801E2470	bne    a2, at, L1e2484 [$801e2484]
801E2474	lui    at, $8000
801E2478	bne    v1, at, L1e2484 [$801e2484]
801E247C	nop
801E2480	break   $01800

L1e2484:	; 801E2484
801E2484	mflo   v1
801E2488	lw     v0, $0018(sp)
801E248C	nop
801E2490	sll    v0, v0, $08
801E2494	div    v0, a2
801E2498	bne    a2, zero, L1e24a4 [$801e24a4]
801E249C	nop
801E24A0	break   $01c00

L1e24a4:	; 801E24A4
801E24A4	addiu  at, zero, $ffff (=-$1)
801E24A8	bne    a2, at, L1e24bc [$801e24bc]
801E24AC	lui    at, $8000
801E24B0	bne    v0, at, L1e24bc [$801e24bc]
801E24B4	nop
801E24B8	break   $01800

L1e24bc:	; 801E24BC
801E24BC	mflo   v0

L1e24c0:	; 801E24C0
801E24C0	sw     a0, $0010(sp)
801E24C4	sw     v1, $0014(sp)
801E24C8	j      L1e24dc [$801e24dc]
801E24CC	sw     v0, $0018(sp)

L1e24d0:	; 801E24D0
801E24D0	sw     zero, $0010(sp)
801E24D4	sw     zero, $0014(sp)
801E24D8	sw     zero, $0018(sp)

L1e24dc:	; 801E24DC
801E24DC	lh     v0, $0000(s2)
801E24E0	lw     v1, $0010(sp)
801E24E4	nop
801E24E8	mult   v0, v1

L1e24ec:	; 801E24EC
801E24EC	mflo   v0
801E24F0	nop
801E24F4	nop
801E24F8	mult   v0, s6
801E24FC	mflo   v1
801E2500	bgez   v1, L1e250c [$801e250c]
801E2504	nop
801E2508	addu   v1, v1, s3

L1e250c:	; 801E250C
801E250C	lhu    v0, $ffe4(s0)
801E2510	sra    v1, v1, $14
801E2514	addu   v0, v0, v1
801E2518	sh     v0, $fffc(s0)
801E251C	lh     v1, $0000(s2)
801E2520	lw     v0, $0014(sp)
801E2524	nop
801E2528	mult   v1, v0
801E252C	mflo   v0
801E2530	nop
801E2534	nop
801E2538	mult   v0, s6

L1e253c:	; 801E253C
801E253C	mflo   v1
801E2540	bgez   v1, L1e254c [$801e254c]
801E2544	nop
801E2548	addu   v1, v1, s3

L1e254c:	; 801E254C
801E254C	lhu    v0, $ffe6(s0)
801E2550	sra    v1, v1, $14
801E2554	addu   v0, v0, v1
801E2558	sh     v0, $fffe(s0)
801E255C	lh     v1, $0000(s2)
801E2560	lw     v0, $0018(sp)
801E2564	nop
801E2568	mult   v1, v0
801E256C	mflo   v0
801E2570	nop
801E2574	nop
801E2578	mult   v0, s6
801E257C	mflo   v1
801E2580	bgez   v1, L1e258c [$801e258c]
801E2584	nop
801E2588	addu   v1, v1, s3

L1e258c:	; 801E258C
801E258C	lhu    v0, $ffe8(s0)
801E2590	sra    v1, v1, $14
801E2594	addu   v0, v0, v1
801E2598	sh     v0, $0000(s0)
801E259C	sll    v0, fp, $10
801E25A0	lh     v1, $fffe(s0)
801E25A4	sra    v0, v0, $10
801E25A8	slt    v0, v0, v1
801E25AC	beq    v0, zero, L1e25b8 [$801e25b8]
801E25B0	nop
801E25B4	sh     fp, $fffe(s0)

L1e25b8:	; 801E25B8
801E25B8	sw     zero, $0068(sp)

L1e25bc:	; 801E25BC
801E25BC	lh     v0, $000a(s4)
801E25C0	lw     v1, $0018(s4)
801E25C4	blez   v0, L1e2994 [$801e2994]
801E25C8	nop
801E25CC	addiu  s1, v1, $000c

L1e25d0:	; 801E25D0
801E25D0	lh     v0, $fffc(s0)
801E25D4	lh     v1, $fffc(s1)
801E25D8	nop
801E25DC	subu   v0, v0, v1
801E25E0	mult   v0, v0
801E25E4	sw     v0, $0010(sp)
801E25E8	lh     v0, $fffe(s0)
801E25EC	lh     v1, $fffe(s1)
801E25F0	mflo   a1
801E25F4	subu   v0, v0, v1
801E25F8	nop
801E25FC	mult   v0, v0
801E2600	sw     v0, $0014(sp)
801E2604	lh     v1, $0000(s1)
801E2608	lh     v0, $0000(s0)
801E260C	mflo   a0
801E2610	subu   v0, v0, v1
801E2614	nop
801E2618	mult   v0, v0
801E261C	sw     v0, $0018(sp)
801E2620	addu   a1, a1, a0
801E2624	mflo   a0
801E2628	jal    system_square_root [$80048af4]
801E262C	addu   a0, a1, a0
801E2630	lh     v1, $0002(s1)
801E2634	nop
801E2638	mult   v1, s6
801E263C	addu   a2, v0, zero
801E2640	mflo   v0
801E2644	bgez   v0, L1e2650 [$801e2650]
801E2648	nop
801E264C	addiu  v0, v0, $0fff

L1e2650:	; 801E2650
801E2650	sll    v0, v0, $04
801E2654	sra    v1, v0, $10
801E2658	slt    v0, a2, v1
801E265C	beq    v0, zero, L1e2978 [$801e2978]
801E2660	nop
801E2664	beq    a2, zero, L1e2764 [$801e2764]
801E2668	nop
801E266C	lw     v0, $0010(sp)
801E2670	nop
801E2674	mult   v1, v0
801E2678	mflo   a1
801E267C	nop
801E2680	nop

L1e2684:	; 801E2684
801E2684	div    a1, a2
801E2688	bne    a2, zero, L1e2694 [$801e2694]
801E268C	nop
801E2690	break   $01c00

L1e2694:	; 801E2694
801E2694	addiu  at, zero, $ffff (=-$1)
801E2698	bne    a2, at, L1e26ac [$801e26ac]
801E269C	lui    at, $8000
801E26A0	bne    a1, at, L1e26ac [$801e26ac]
801E26A4	nop
801E26A8	break   $01800

L1e26ac:	; 801E26AC
801E26AC	mflo   a1
801E26B0	lw     v0, $0014(sp)
801E26B4	nop
801E26B8	mult   v1, v0
801E26BC	mflo   a0
801E26C0	nop
801E26C4	nop
801E26C8	div    a0, a2
801E26CC	bne    a2, zero, L1e26d8 [$801e26d8]
801E26D0	nop
801E26D4	break   $01c00

L1e26d8:	; 801E26D8
801E26D8	addiu  at, zero, $ffff (=-$1)
801E26DC	bne    a2, at, L1e26f0 [$801e26f0]
801E26E0	lui    at, $8000
801E26E4	bne    a0, at, L1e26f0 [$801e26f0]
801E26E8	nop
801E26EC	break   $01800

L1e26f0:	; 801E26F0
801E26F0	mflo   a0
801E26F4	lw     v0, $0018(sp)
801E26F8	nop
801E26FC	mult   v1, v0
801E2700	mflo   v1
801E2704	nop
801E2708	nop
801E270C	div    v1, a2
801E2710	bne    a2, zero, L1e271c [$801e271c]
801E2714	nop
801E2718	break   $01c00

L1e271c:	; 801E271C
801E271C	addiu  at, zero, $ffff (=-$1)
801E2720	bne    a2, at, L1e2734 [$801e2734]
801E2724	lui    at, $8000
801E2728	bne    v1, at, L1e2734 [$801e2734]
801E272C	nop
801E2730	break   $01800

L1e2734:	; 801E2734
801E2734	mflo   v1
801E2738	lh     v0, $fffc(s1)
801E273C	nop
801E2740	addu   v0, v0, a1
801E2744	sw     v0, $0010(sp)
801E2748	lh     v0, $fffe(s1)
801E274C	nop
801E2750	addu   v0, v0, a0
801E2754	sw     v0, $0014(sp)
801E2758	lh     v0, $0000(s1)
801E275C	j      L1e2780 [$801e2780]
801E2760	addu   v0, v0, v1

L1e2764:	; 801E2764
801E2764	lh     v0, $fffc(s1)
801E2768	nop
801E276C	sw     v0, $0010(sp)
801E2770	lh     v0, $fffe(s1)
801E2774	nop
801E2778	sw     v0, $0014(sp)
801E277C	lh     v0, $0000(s1)

L1e2780:	; 801E2780
801E2780	nop
801E2784	sw     v0, $0018(sp)
801E2788	lh     v1, $ffe4(s0)
801E278C	lw     v0, $0010(sp)
801E2790	nop
801E2794	subu   v0, v0, v1
801E2798	mult   v0, v0
801E279C	sw     v0, $0010(sp)
801E27A0	lh     v1, $ffe6(s0)
801E27A4	lw     v0, $0014(sp)
801E27A8	mflo   a1
801E27AC	subu   v0, v0, v1
801E27B0	nop
801E27B4	mult   v0, v0
801E27B8	sw     v0, $0014(sp)
801E27BC	lh     v1, $ffe8(s0)
801E27C0	lw     v0, $0018(sp)
801E27C4	mflo   a0
801E27C8	subu   v0, v0, v1
801E27CC	nop
801E27D0	mult   v0, v0
801E27D4	sw     v0, $0018(sp)
801E27D8	addu   a1, a1, a0
801E27DC	mflo   a0
801E27E0	jal    system_square_root [$80048af4]
801E27E4	addu   a0, a1, a0
801E27E8	addu   a2, v0, zero
801E27EC	beq    a2, zero, L1e28ac [$801e28ac]
801E27F0	nop
801E27F4	lw     a1, $0010(sp)
801E27F8	nop
801E27FC	sll    a1, a1, $08
801E2800	div    a1, a2
801E2804	bne    a2, zero, L1e2810 [$801e2810]

L1e2808:	; 801E2808
801E2808	nop
801E280C	break   $01c00

L1e2810:	; 801E2810
801E2810	addiu  at, zero, $ffff (=-$1)
801E2814	bne    a2, at, L1e2828 [$801e2828]
801E2818	lui    at, $8000
801E281C	bne    a1, at, L1e2828 [$801e2828]
801E2820	nop
801E2824	break   $01800

L1e2828:	; 801E2828
801E2828	mflo   a1
801E282C	lw     v1, $0014(sp)
801E2830	nop
801E2834	sll    v1, v1, $08
801E2838	div    v1, a2
801E283C	bne    a2, zero, L1e2848 [$801e2848]
801E2840	nop
801E2844	break   $01c00

L1e2848:	; 801E2848
801E2848	addiu  at, zero, $ffff (=-$1)
801E284C	bne    a2, at, L1e2860 [$801e2860]
801E2850	lui    at, $8000
801E2854	bne    v1, at, L1e2860 [$801e2860]
801E2858	nop
801E285C	break   $01800

L1e2860:	; 801E2860
801E2860	mflo   v1
801E2864	lw     v0, $0018(sp)
801E2868	nop
801E286C	sll    v0, v0, $08
801E2870	div    v0, a2
801E2874	bne    a2, zero, L1e2880 [$801e2880]
801E2878	nop
801E287C	break   $01c00

L1e2880:	; 801E2880
801E2880	addiu  at, zero, $ffff (=-$1)
801E2884	bne    a2, at, L1e2898 [$801e2898]
801E2888	lui    at, $8000
801E288C	bne    v0, at, L1e2898 [$801e2898]
801E2890	nop
801E2894	break   $01800

L1e2898:	; 801E2898
801E2898	mflo   v0
801E289C	sw     a1, $0010(sp)
801E28A0	sw     v1, $0014(sp)
801E28A4	j      L1e28b8 [$801e28b8]
801E28A8	sw     v0, $0018(sp)

L1e28ac:	; 801E28AC
801E28AC	sw     zero, $0010(sp)
801E28B0	sw     zero, $0014(sp)
801E28B4	sw     zero, $0018(sp)

L1e28b8:	; 801E28B8
801E28B8	lh     v0, $0000(s2)
801E28BC	lw     v1, $0010(sp)
801E28C0	nop
801E28C4	mult   v0, v1
801E28C8	mflo   v0
801E28CC	nop
801E28D0	nop
801E28D4	mult   v0, s6
801E28D8	mflo   v0
801E28DC	bgez   v0, L1e28e8 [$801e28e8]
801E28E0	nop
801E28E4	addu   v0, v0, s3

L1e28e8:	; 801E28E8
801E28E8	lhu    v1, $ffe4(s0)
801E28EC	sra    v0, v0, $14
801E28F0	addu   v1, v1, v0
801E28F4	sh     v1, $fffc(s0)
801E28F8	lh     v1, $0000(s2)
801E28FC	lw     v0, $0014(sp)
801E2900	nop
801E2904	mult   v1, v0
801E2908	mflo   v0
801E290C	nop
801E2910	nop
801E2914	mult   v0, s6
801E2918	mflo   v0
801E291C	bgez   v0, L1e2928 [$801e2928]
801E2920	nop
801E2924	addu   v0, v0, s3

L1e2928:	; 801E2928
801E2928	lhu    v1, $ffe6(s0)
801E292C	sra    v0, v0, $14
801E2930	addu   v1, v1, v0
801E2934	sh     v1, $fffe(s0)
801E2938	lh     v1, $0000(s2)
801E293C	lw     v0, $0018(sp)
801E2940	nop
801E2944	mult   v1, v0
801E2948	mflo   v0
801E294C	nop
801E2950	nop
801E2954	mult   v0, s6
801E2958	mflo   v0
801E295C	bgez   v0, L1e2968 [$801e2968]
801E2960	nop
801E2964	addu   v0, v0, s3

L1e2968:	; 801E2968
801E2968	lhu    v1, $ffe8(s0)
801E296C	sra    v0, v0, $14
801E2970	addu   v1, v1, v0
801E2974	sh     v1, $0000(s0)

L1e2978:	; 801E2978
801E2978	lw     v0, $0068(sp)
801E297C	lh     v1, $000a(s4)
801E2980	addiu  v0, v0, $0001
801E2984	sw     v0, $0068(sp)
801E2988	slt    v0, v0, v1
801E298C	bne    v0, zero, L1e25d0 [$801e25d0]
801E2990	addiu  s1, s1, $0010

L1e2994:	; 801E2994
801E2994	addiu  s2, s2, $0018
801E2998	lh     v0, $0000(s2)
801E299C	nop
801E29A0	bne    v0, zero, L1e2398 [$801e2398]
801E29A4	addiu  s0, s0, $0018

L1e29a8:	; 801E29A8
801E29A8	lh     v0, $0004(s4)
801E29AC	addiu  s5, s5, $0001
801E29B0	slt    v0, s5, v0
801E29B4	bne    v0, zero, L1e2370 [$801e2370]
801E29B8	nop

L1e29bc:	; 801E29BC
801E29BC	lw     v0, $001c(s4)
801E29C0	lh     v1, $0008(s4)
801E29C4	lw     s2, $0000(v0)
801E29C8	blez   v1, L1e29f8 [$801e29f8]
801E29CC	addu   s5, zero, zero
801E29D0	addiu  v1, s2, $0014

loop1e29d4:	; 801E29D4
801E29D4	sh     zero, $fff6(v1)
801E29D8	sw     zero, $fff8(v1)
801E29DC	sw     zero, $fffc(v1)
801E29E0	sw     zero, $0000(v1)
801E29E4	lh     v0, $0008(s4)
801E29E8	addiu  s5, s5, $0001
801E29EC	slt    v0, s5, v0
801E29F0	bne    v0, zero, loop1e29d4 [$801e29d4]
801E29F4	addiu  v1, v1, $0018

L1e29f8:	; 801E29F8
801E29F8	lw     s1, $0020(s4)
801E29FC	lw     v0, $001c(s4)
801E2A00	lh     v1, $0006(s4)
801E2A04	lw     s2, $0000(v0)
801E2A08	blez   v1, L1e2e0c [$801e2e0c]
801E2A0C	addu   s5, zero, zero
801E2A10	addiu  s6, sp, $0028
801E2A14	addiu  s3, sp, $0048
801E2A18	addiu  s0, s1, $0004

L1e2a1c:	; 801E2A1C
801E2A1C	lh     v0, $0000(s1)
801E2A20	lh     a0, $fffe(s0)
801E2A24	sll    v1, v0, $01
801E2A28	addu   v1, v1, v0

L1e2a2c:	; 801E2A2C
801E2A2C	sll    v1, v1, $03
801E2A30	addu   v1, v1, s2
801E2A34	sll    v0, a0, $01
801E2A38	addu   v0, v0, a0
801E2A3C	sll    v0, v0, $03
801E2A40	addu   v0, v0, s2
801E2A44	lh     v1, $0004(v1)
801E2A48	lh     v0, $0004(v0)
801E2A4C	nop
801E2A50	subu   v1, v1, v0
801E2A54	sw     v1, $0028(sp)
801E2A58	lh     v0, $0000(s1)
801E2A5C	lh     a0, $fffe(s0)
801E2A60	sll    v1, v0, $01
801E2A64	addu   v1, v1, v0
801E2A68	sll    v1, v1, $03
801E2A6C	addu   v1, v1, s2
801E2A70	sll    v0, a0, $01
801E2A74	addu   v0, v0, a0
801E2A78	sll    v0, v0, $03
801E2A7C	addu   v0, v0, s2
801E2A80	lh     v1, $0006(v1)
801E2A84	lh     v0, $0006(v0)
801E2A88	nop
801E2A8C	subu   v1, v1, v0
801E2A90	sw     v1, $002c(sp)
801E2A94	lh     v0, $0000(s1)
801E2A98	lh     a0, $fffe(s0)
801E2A9C	sll    v1, v0, $01
801E2AA0	addu   v1, v1, v0
801E2AA4	sll    v1, v1, $03
801E2AA8	addu   v1, v1, s2
801E2AAC	sll    v0, a0, $01
801E2AB0	addu   v0, v0, a0
801E2AB4	sll    v0, v0, $03
801E2AB8	addu   v0, v0, s2
801E2ABC	lh     v1, $0008(v1)
801E2AC0	lh     v0, $0008(v0)
801E2AC4	nop

L1e2ac8:	; 801E2AC8
801E2AC8	subu   v1, v1, v0
801E2ACC	sw     v1, $0030(sp)
801E2AD0	lh     v0, $0000(s1)
801E2AD4	lh     a0, $0000(s0)
801E2AD8	sll    v1, v0, $01
801E2ADC	addu   v1, v1, v0
801E2AE0	sll    v1, v1, $03
801E2AE4	addu   v1, v1, s2
801E2AE8	sll    v0, a0, $01
801E2AEC	addu   v0, v0, a0
801E2AF0	sll    v0, v0, $03
801E2AF4	addu   v0, v0, s2
801E2AF8	lh     v1, $0004(v1)
801E2AFC	lh     v0, $0004(v0)
801E2B00	nop
801E2B04	subu   v1, v1, v0
801E2B08	sw     v1, $0038(sp)
801E2B0C	lh     v0, $0000(s1)
801E2B10	lh     a0, $0000(s0)
801E2B14	sll    v1, v0, $01
801E2B18	addu   v1, v1, v0
801E2B1C	sll    v1, v1, $03
801E2B20	addu   v1, v1, s2
801E2B24	sll    v0, a0, $01
801E2B28	addu   v0, v0, a0
801E2B2C	sll    v0, v0, $03
801E2B30	addu   v0, v0, s2
801E2B34	lh     v1, $0006(v1)
801E2B38	lh     v0, $0006(v0)
801E2B3C	nop
801E2B40	subu   v1, v1, v0
801E2B44	sw     v1, $003c(sp)
801E2B48	lh     v0, $0000(s1)
801E2B4C	lh     a0, $0000(s0)
801E2B50	sll    v1, v0, $01
801E2B54	addu   v1, v1, v0
801E2B58	sll    v1, v1, $03
801E2B5C	addu   v1, v1, s2
801E2B60	sll    v0, a0, $01
801E2B64	addu   v0, v0, a0

L1e2b68:	; 801E2B68
801E2B68	sll    v0, v0, $03
801E2B6C	addu   v0, v0, s2
801E2B70	lh     v1, $0008(v1)
801E2B74	lh     v0, $0008(v0)
801E2B78	nop
801E2B7C	subu   v1, v1, v0
801E2B80	sw     v1, $0040(sp)
801E2B84	lw     t4, $0000(s6)
801E2B88	lw     t5, $0004(s6)
801E2B8C	ctc2   t4,vxy0
801E2B90	lw     t6, $0008(s6)
801E2B94	ctc2   t5,vxy1
801E2B98	ctc2   t6,vxy2
801E2B9C	addiu  v0, sp, $0038
801E2BA0	lwc2   t3, $0008(v0)
801E2BA4	lwc2   t1, $0000(v0)
801E2BA8	lwc2   t2, $0004(v0)
801E2BAC	nop
801E2BB0	nop
801E2BB4	gte_func27s0,r11r12
801E2BB8	swc2   t9, $0000(s3)
801E2BBC	swc2   k0, $0004(s3)
801E2BC0	swc2   k1, $0008(s3)
801E2BC4	lw     v0, $0048(sp)
801E2BC8	nop
801E2BCC	bgez   v0, L1e2bd8 [$801e2bd8]
801E2BD0	nop
801E2BD4	addiu  v0, v0, $0007

L1e2bd8:	; 801E2BD8
801E2BD8	lw     v1, $004c(sp)
801E2BDC	sra    v0, v0, $03
801E2BE0	bgez   v1, L1e2bec [$801e2bec]
801E2BE4	sw     v0, $0048(sp)
801E2BE8	addiu  v1, v1, $0007

L1e2bec:	; 801E2BEC
801E2BEC	lw     a1, $0050(sp)
801E2BF0	sra    v0, v1, $03
801E2BF4	bgez   a1, L1e2c00 [$801e2c00]
801E2BF8	sw     v0, $004c(sp)
801E2BFC	addiu  a1, a1, $0007

L1e2c00:	; 801E2C00
801E2C00	addu   a0, s3, zero
801E2C04	sra    v0, a1, $03
801E2C08	addu   a1, s6, zero

L1e2c0c:	; 801E2C0C
801E2C0C	jal    system_normalize_word_vector_T0_T1_T2_to_word [$80048c24]
801E2C10	sw     v0, $0050(sp)

L1e2c14:	; 801E2C14
801E2C14	lh     v1, $0000(s1)
801E2C18	lw     a0, $0028(sp)
801E2C1C	sll    v0, v1, $01
801E2C20	addu   v0, v0, v1
801E2C24	sll    v0, v0, $03

L1e2c28:	; 801E2C28
801E2C28	addu   v0, v0, s2
801E2C2C	lw     v1, $000c(v0)
801E2C30	nop
801E2C34	addu   v1, v1, a0
801E2C38	sw     v1, $000c(v0)
801E2C3C	lh     v1, $0000(s1)
801E2C40	lw     a0, $002c(sp)
801E2C44	sll    v0, v1, $01
801E2C48	addu   v0, v0, v1
801E2C4C	sll    v0, v0, $03
801E2C50	addu   v0, v0, s2
801E2C54	lw     v1, $0010(v0)
801E2C58	nop
801E2C5C	addu   v1, v1, a0
801E2C60	sw     v1, $0010(v0)
801E2C64	lh     v1, $0000(s1)

L1e2c68:	; 801E2C68
801E2C68	lw     a0, $0030(sp)
801E2C6C	sll    v0, v1, $01
801E2C70	addu   v0, v0, v1
801E2C74	sll    v0, v0, $03
801E2C78	addu   v0, v0, s2
801E2C7C	lw     v1, $0014(v0)
801E2C80	nop
801E2C84	addu   v1, v1, a0
801E2C88	sw     v1, $0014(v0)
801E2C8C	lh     v1, $0000(s1)
801E2C90	nop
801E2C94	sll    v0, v1, $01
801E2C98	addu   v0, v0, v1
801E2C9C	sll    v0, v0, $03
801E2CA0	addu   v0, v0, s2
801E2CA4	lhu    v1, $000a(v0)
801E2CA8	nop
801E2CAC	addiu  v1, v1, $0001
801E2CB0	sh     v1, $000a(v0)
801E2CB4	lh     v1, $fffe(s0)
801E2CB8	lw     a0, $0028(sp)
801E2CBC	sll    v0, v1, $01
801E2CC0	addu   v0, v0, v1
801E2CC4	sll    v0, v0, $03
801E2CC8	addu   v0, v0, s2
801E2CCC	lw     v1, $000c(v0)
801E2CD0	nop
801E2CD4	addu   v1, v1, a0
801E2CD8	sw     v1, $000c(v0)
801E2CDC	lh     v1, $fffe(s0)
801E2CE0	lw     a0, $002c(sp)

L1e2ce4:	; 801E2CE4
801E2CE4	sll    v0, v1, $01

L1e2ce8:	; 801E2CE8
801E2CE8	addu   v0, v0, v1
801E2CEC	sll    v0, v0, $03
801E2CF0	addu   v0, v0, s2
801E2CF4	lw     v1, $0010(v0)
801E2CF8	nop
801E2CFC	addu   v1, v1, a0
801E2D00	sw     v1, $0010(v0)
801E2D04	lh     v1, $fffe(s0)
801E2D08	lw     a0, $0030(sp)
801E2D0C	sll    v0, v1, $01
801E2D10	addu   v0, v0, v1
801E2D14	sll    v0, v0, $03
801E2D18	addu   v0, v0, s2

L1e2d1c:	; 801E2D1C
801E2D1C	lw     v1, $0014(v0)
801E2D20	nop
801E2D24	addu   v1, v1, a0
801E2D28	sw     v1, $0014(v0)
801E2D2C	lh     v1, $fffe(s0)
801E2D30	nop
801E2D34	sll    v0, v1, $01
801E2D38	addu   v0, v0, v1
801E2D3C	sll    v0, v0, $03
801E2D40	addu   v0, v0, s2
801E2D44	lhu    v1, $000a(v0)
801E2D48	nop
801E2D4C	addiu  v1, v1, $0001
801E2D50	sh     v1, $000a(v0)
801E2D54	lh     v1, $0000(s0)
801E2D58	lw     a0, $0028(sp)
801E2D5C	sll    v0, v1, $01
801E2D60	addu   v0, v0, v1
801E2D64	sll    v0, v0, $03

L1e2d68:	; 801E2D68
801E2D68	addu   v0, v0, s2
801E2D6C	lw     v1, $000c(v0)
801E2D70	nop
801E2D74	addu   v1, v1, a0
801E2D78	sw     v1, $000c(v0)
801E2D7C	lh     v1, $0000(s0)
801E2D80	lw     a0, $002c(sp)
801E2D84	sll    v0, v1, $01
801E2D88	addu   v0, v0, v1
801E2D8C	sll    v0, v0, $03
801E2D90	addu   v0, v0, s2
801E2D94	lw     v1, $0010(v0)
801E2D98	nop
801E2D9C	addu   v1, v1, a0
801E2DA0	sw     v1, $0010(v0)
801E2DA4	lh     v1, $0000(s0)
801E2DA8	lw     a0, $0030(sp)
801E2DAC	sll    v0, v1, $01
801E2DB0	addu   v0, v0, v1

L1e2db4:	; 801E2DB4
801E2DB4	sll    v0, v0, $03
801E2DB8	addu   v0, v0, s2
801E2DBC	lw     v1, $0014(v0)
801E2DC0	nop
801E2DC4	addu   v1, v1, a0
801E2DC8	sw     v1, $0014(v0)
801E2DCC	lh     v1, $0000(s0)
801E2DD0	addiu  s5, s5, $0001
801E2DD4	sll    v0, v1, $01
801E2DD8	addu   v0, v0, v1
801E2DDC	sll    v0, v0, $03
801E2DE0	addu   v0, v0, s2
801E2DE4	lhu    v1, $000a(v0)

L1e2de8:	; 801E2DE8
801E2DE8	addiu  s1, s1, $0058
801E2DEC	addiu  v1, v1, $0001
801E2DF0	sh     v1, $000a(v0)

L1e2df4:	; 801E2DF4
801E2DF4	lh     v0, $0006(s4)
801E2DF8	nop
801E2DFC	slt    v0, s5, v0
801E2E00	bne    v0, zero, L1e2a1c [$801e2a1c]
801E2E04	addiu  s0, s0, $0058
801E2E08	lw     v0, $001c(s4)

L1e2e0c:	; 801E2E0C
801E2E0C	lh     v1, $0008(s4)
801E2E10	lw     s2, $0000(v0)
801E2E14	blez   v1, L1e2eec [$801e2eec]
801E2E18	addu   s5, zero, zero
801E2E1C	addiu  a2, s2, $0014

loop1e2e20:	; 801E2E20
801E2E20	lh     v0, $fff6(a2)

L1e2e24:	; 801E2E24
801E2E24	lw     a1, $fff8(a2)
801E2E28	nop
801E2E2C	div    a1, v0

L1e2e30:	; 801E2E30
801E2E30	bne    v0, zero, L1e2e3c [$801e2e3c]
801E2E34	nop
801E2E38	break   $01c00

L1e2e3c:	; 801E2E3C
801E2E3C	addiu  at, zero, $ffff (=-$1)
801E2E40	bne    v0, at, L1e2e54 [$801e2e54]
801E2E44	lui    at, $8000
801E2E48	bne    a1, at, L1e2e54 [$801e2e54]
801E2E4C	nop
801E2E50	break   $01800

L1e2e54:	; 801E2E54
801E2E54	mflo   a1
801E2E58	lw     a0, $fffc(a2)
801E2E5C	lh     v0, $fff6(a2)
801E2E60	nop
801E2E64	div    a0, v0
801E2E68	bne    v0, zero, L1e2e74 [$801e2e74]
801E2E6C	nop
801E2E70	break   $01c00

L1e2e74:	; 801E2E74
801E2E74	addiu  at, zero, $ffff (=-$1)
801E2E78	bne    v0, at, L1e2e8c [$801e2e8c]
801E2E7C	lui    at, $8000
801E2E80	bne    a0, at, L1e2e8c [$801e2e8c]
801E2E84	nop
801E2E88	break   $01800

L1e2e8c:	; 801E2E8C
801E2E8C	mflo   a0
801E2E90	lw     v1, $0000(a2)
801E2E94	lh     v0, $fff6(a2)
801E2E98	nop
801E2E9C	div    v1, v0
801E2EA0	bne    v0, zero, L1e2eac [$801e2eac]
801E2EA4	nop
801E2EA8	break   $01c00

L1e2eac:	; 801E2EAC
801E2EAC	addiu  at, zero, $ffff (=-$1)
801E2EB0	bne    v0, at, L1e2ec4 [$801e2ec4]
801E2EB4	lui    at, $8000

L1e2eb8:	; 801E2EB8
801E2EB8	bne    v1, at, L1e2ec4 [$801e2ec4]
801E2EBC	nop
801E2EC0	break   $01800

L1e2ec4:	; 801E2EC4
801E2EC4	mflo   v1
801E2EC8	addiu  s5, s5, $0001
801E2ECC	sw     a1, $fff8(a2)
801E2ED0	sw     a0, $fffc(a2)
801E2ED4	sw     v1, $0000(a2)
801E2ED8	lh     v0, $0008(s4)
801E2EDC	nop
801E2EE0	slt    v0, s5, v0
801E2EE4	bne    v0, zero, loop1e2e20 [$801e2e20]
801E2EE8	addiu  a2, a2, $0018

L1e2eec:	; 801E2EEC
801E2EEC	lw     a0, $0078(sp)
801E2EF0	jal    func49da4 [$80049da4]
801E2EF4	addu   s5, zero, zero
801E2EF8	lw     a0, $0078(sp)
801E2EFC	jal    func49e34 [$80049e34]
801E2F00	nop
801E2F04	lw     s1, $0020(s4)
801E2F08	lw     v0, $001c(s4)
801E2F0C	lh     v1, $0006(s4)
801E2F10	lw     s2, $0000(v0)
801E2F14	blez   v1, L1e3404 [$801e3404]
801E2F18	addiu  t3, sp, $0020
801E2F1C	lw     t7, $00e8(sp)
801E2F20	addiu  t1, s1, $0004
801E2F24	sll    v0, t7, $02
801E2F28	addu   v0, v0, t7
801E2F2C	sll    t5, v0, $03
801E2F30	addiu  v0, t5, $0008
801E2F34	addu   t2, s1, v0

L1e2f38:	; 801E2F38
801E2F38	lh     v0, $0000(s1)
801E2F3C	lh     a1, $0000(t1)
801E2F40	sll    a0, v0, $01
801E2F44	addu   a0, a0, v0
801E2F48	sll    a0, a0, $03
801E2F4C	addu   a0, s2, a0
801E2F50	lh     v0, $fffe(t1)
801E2F54	addiu  a0, a0, $0004
801E2F58	sll    v1, v0, $01
801E2F5C	addu   v1, v1, v0
801E2F60	sll    v1, v1, $03
801E2F64	addu   v1, s2, v1
801E2F68	addiu  v1, v1, $0004
801E2F6C	sll    v0, a1, $01
801E2F70	addu   v0, v0, a1
801E2F74	sll    v0, v0, $03
801E2F78	addu   v0, s2, v0
801E2F7C	addiu  v0, v0, $0004
801E2F80	lwc2   zero, $0000(a0)
801E2F84	lwc2   at, $0004(a0)
801E2F88	lwc2   v0, $0000(v1)
801E2F8C	lwc2   v1, $0004(v1)
801E2F90	lwc2   a0, $0000(v0)
801E2F94	lwc2   a1, $0004(v0)
801E2F98	nop
801E2F9C	nop
801E2FA0	gte_func17t0,r11r12
801E2FA4	addiu  v0, sp, $0068
801E2FA8	sw     zero, $0068(sp)
801E2FAC	cfc2   t4,lzcr
801E2FB0	nop
801E2FB4	sw     t4, $0000(v0)
801E2FB8	lw     v0, $0068(sp)
801E2FBC	lui    v1, $0004
801E2FC0	and    v0, v0, v1
801E2FC4	bne    v0, zero, L1e33f0 [$801e33f0]
801E2FC8	nop
801E2FCC	nop
801E2FD0	nop
801E2FD4	gte_func26zero,r11r12
801E2FD8	addiu  v0, sp, $006c
801E2FDC	swc2   t8, $0000(v0)
801E2FE0	addiu  a0, t2, $0008
801E2FE4	addiu  v1, t2, $0014
801E2FE8	addiu  v0, t2, $0020
801E2FEC	swc2   t4, $0000(a0)
801E2FF0	swc2   t5, $0000(v1)
801E2FF4	swc2   t6, $0000(v0)
801E2FF8	nop
801E2FFC	nop
801E3000	gte_func26t8,r11r12
801E3004	addiu  v0, sp, $0070
801E3008	swc2   a3, $0000(v0)
801E300C	lw     v0, $0070(sp)
801E3010	lui    v1, $8005
801E3014	lw     v1, $f7a4(v1)
801E3018	lw     a0, $006c(sp)

L1e301c:	; 801E301C
801E301C	srav   v0, v1, v0
801E3020	bgez   a0, L1e30b8 [$801e30b8]
801E3024	sw     v0, $0070(sp)
801E3028	lbu    v0, $000c(s4)

L1e302c:	; 801E302C
801E302C	nop

L1e3030:	; 801E3030
801E3030	sb     v0, $0060(sp)
801E3034	lbu    v0, $000d(s4)
801E3038	nop
801E303C	sb     v0, $0061(sp)
801E3040	lbu    v0, $000e(s4)
801E3044	nop
801E3048	sb     v0, $0062(sp)
801E304C	lh     v1, $0000(s1)
801E3050	nop
801E3054	sll    v0, v1, $01
801E3058	addu   v0, v0, v1
801E305C	sll    v0, v0, $03
801E3060	addu   v0, v0, s2
801E3064	lhu    v0, $000c(v0)
801E3068	nop
801E306C	sh     v0, $0020(sp)
801E3070	lh     v1, $0000(s1)
801E3074	nop
801E3078	sll    v0, v1, $01
801E307C	addu   v0, v0, v1
801E3080	sll    v0, v0, $03
801E3084	addu   v0, v0, s2
801E3088	lhu    v0, $0010(v0)
801E308C	nop
801E3090	sh     v0, $0022(sp)
801E3094	lh     v1, $0000(s1)
801E3098	nop
801E309C	sll    v0, v1, $01
801E30A0	addu   v0, v0, v1
801E30A4	sll    v0, v0, $03

L1e30a8:	; 801E30A8
801E30A8	addu   v0, v0, s2
801E30AC	lhu    v0, $0014(v0)

L1e30b0:	; 801E30B0
801E30B0	j      L1e3154 [$801e3154]
801E30B4	sh     v0, $0024(sp)

L1e30b8:	; 801E30B8
801E30B8	lbu    v0, $000f(s4)
801E30BC	nop
801E30C0	sb     v0, $0060(sp)
801E30C4	lbu    v0, $0010(s4)
801E30C8	nop
801E30CC	sb     v0, $0061(sp)
801E30D0	lbu    v0, $0011(s4)

L1e30d4:	; 801E30D4
801E30D4	nop
801E30D8	sb     v0, $0062(sp)
801E30DC	lh     v1, $0000(s1)
801E30E0	nop
801E30E4	sll    v0, v1, $01

L1e30e8:	; 801E30E8
801E30E8	addu   v0, v0, v1
801E30EC	sll    v0, v0, $03
801E30F0	addu   v0, v0, s2
801E30F4	lhu    v0, $000c(v0)
801E30F8	nop
801E30FC	subu   v0, zero, v0
801E3100	sh     v0, $0020(sp)
801E3104	lh     v1, $0000(s1)
801E3108	nop
801E310C	sll    v0, v1, $01
801E3110	addu   v0, v0, v1
801E3114	sll    v0, v0, $03
801E3118	addu   v0, v0, s2
801E311C	lhu    v0, $0010(v0)
801E3120	nop
801E3124	subu   v0, zero, v0

L1e3128:	; 801E3128
801E3128	sh     v0, $0022(sp)
801E312C	lh     v1, $0000(s1)

L1e3130:	; 801E3130
801E3130	nop
801E3134	sll    v0, v1, $01
801E3138	addu   v0, v0, v1
801E313C	sll    v0, v0, $03
801E3140	addu   v0, v0, s2
801E3144	lhu    v0, $0014(v0)
801E3148	nop
801E314C	subu   v0, zero, v0
801E3150	sh     v0, $0024(sp)

L1e3154:	; 801E3154
801E3154	lwc2   zero, $0000(t3)
801E3158	lwc2   at, $0004(t3)
801E315C	addiu  v0, sp, $0060
801E3160	lwc2   a2, $0000(v0)
801E3164	nop
801E3168	nop
801E316C	gte_func24t0,r11r12
801E3170	addiu  v0, t2, $0004
801E3174	swc2   s6, $0000(v0)
801E3178	lw     v0, $006c(sp)
801E317C	nop
801E3180	bgez   v0, L1e31f4 [$801e31f4]
801E3184	nop
801E3188	lh     v1, $fffe(t1)
801E318C	nop
801E3190	sll    v0, v1, $01
801E3194	addu   v0, v0, v1
801E3198	sll    v0, v0, $03
801E319C	addu   v0, v0, s2
801E31A0	lhu    v0, $000c(v0)
801E31A4	nop

L1e31a8:	; 801E31A8
801E31A8	sh     v0, $0020(sp)
801E31AC	lh     v1, $fffe(t1)
801E31B0	nop

L1e31b4:	; 801E31B4
801E31B4	sll    v0, v1, $01
801E31B8	addu   v0, v0, v1
801E31BC	sll    v0, v0, $03
801E31C0	addu   v0, v0, s2
801E31C4	lhu    v0, $0010(v0)
801E31C8	nop
801E31CC	sh     v0, $0022(sp)
801E31D0	lh     v1, $fffe(t1)
801E31D4	nop
801E31D8	sll    v0, v1, $01

L1e31dc:	; 801E31DC
801E31DC	addu   v0, v0, v1

L1e31e0:	; 801E31E0
801E31E0	sll    v0, v0, $03

L1e31e4:	; 801E31E4
801E31E4	addu   v0, v0, s2
801E31E8	lhu    v0, $0014(v0)
801E31EC	j      L1e326c [$801e326c]
801E31F0	sh     v0, $0024(sp)

L1e31f4:	; 801E31F4
801E31F4	lh     v1, $fffe(t1)
801E31F8	nop
801E31FC	sll    v0, v1, $01
801E3200	addu   v0, v0, v1
801E3204	sll    v0, v0, $03
801E3208	addu   v0, v0, s2
801E320C	lhu    v0, $000c(v0)
801E3210	nop
801E3214	subu   v0, zero, v0
801E3218	sh     v0, $0020(sp)
801E321C	lh     v1, $fffe(t1)
801E3220	nop
801E3224	sll    v0, v1, $01
801E3228	addu   v0, v0, v1
801E322C	sll    v0, v0, $03
801E3230	addu   v0, v0, s2
801E3234	lhu    v0, $0010(v0)
801E3238	nop
801E323C	subu   v0, zero, v0
801E3240	sh     v0, $0022(sp)
801E3244	lh     v1, $fffe(t1)
801E3248	nop
801E324C	sll    v0, v1, $01
801E3250	addu   v0, v0, v1
801E3254	sll    v0, v0, $03
801E3258	addu   v0, v0, s2
801E325C	lhu    v0, $0014(v0)
801E3260	nop
801E3264	subu   v0, zero, v0
801E3268	sh     v0, $0024(sp)

L1e326c:	; 801E326C
801E326C	lwc2   zero, $0000(t3)
801E3270	lwc2   at, $0004(t3)
801E3274	nop
801E3278	nop
801E327C	gte_func24t0,r11r12
801E3280	addiu  v0, t2, $0010
801E3284	swc2   s6, $0000(v0)
801E3288	lw     v0, $006c(sp)
801E328C	nop
801E3290	bgez   v0, L1e3304 [$801e3304]
801E3294	nop
801E3298	lh     v1, $0000(t1)
801E329C	nop
801E32A0	sll    v0, v1, $01
801E32A4	addu   v0, v0, v1
801E32A8	sll    v0, v0, $03
801E32AC	addu   v0, v0, s2
801E32B0	lhu    v0, $000c(v0)
801E32B4	nop
801E32B8	sh     v0, $0020(sp)
801E32BC	lh     v1, $0000(t1)
801E32C0	nop
801E32C4	sll    v0, v1, $01
801E32C8	addu   v0, v0, v1
801E32CC	sll    v0, v0, $03
801E32D0	addu   v0, v0, s2
801E32D4	lhu    v0, $0010(v0)
801E32D8	nop
801E32DC	sh     v0, $0022(sp)
801E32E0	lh     v1, $0000(t1)
801E32E4	nop
801E32E8	sll    v0, v1, $01

L1e32ec:	; 801E32EC
801E32EC	addu   v0, v0, v1
801E32F0	sll    v0, v0, $03
801E32F4	addu   v0, v0, s2
801E32F8	lhu    v0, $0014(v0)
801E32FC	j      L1e337c [$801e337c]
801E3300	sh     v0, $0024(sp)

L1e3304:	; 801E3304
801E3304	lh     v1, $0000(t1)
801E3308	nop
801E330C	sll    v0, v1, $01
801E3310	addu   v0, v0, v1
801E3314	sll    v0, v0, $03
801E3318	addu   v0, v0, s2

L1e331c:	; 801E331C
801E331C	lhu    v0, $000c(v0)
801E3320	nop
801E3324	subu   v0, zero, v0
801E3328	sh     v0, $0020(sp)

L1e332c:	; 801E332C
801E332C	lh     v1, $0000(t1)
801E3330	nop
801E3334	sll    v0, v1, $01
801E3338	addu   v0, v0, v1
801E333C	sll    v0, v0, $03
801E3340	addu   v0, v0, s2
801E3344	lhu    v0, $0010(v0)
801E3348	nop
801E334C	subu   v0, zero, v0
801E3350	sh     v0, $0022(sp)
801E3354	lh     v1, $0000(t1)
801E3358	nop
801E335C	sll    v0, v1, $01
801E3360	addu   v0, v0, v1
801E3364	sll    v0, v0, $03
801E3368	addu   v0, v0, s2
801E336C	lhu    v0, $0014(v0)
801E3370	nop
801E3374	subu   v0, zero, v0
801E3378	sh     v0, $0024(sp)

L1e337c:	; 801E337C
801E337C	lwc2   zero, $0000(t3)
801E3380	lwc2   at, $0004(t3)
801E3384	nop
801E3388	nop
801E338C	gte_func24t0,r11r12
801E3390	addiu  v0, t2, $001c
801E3394	swc2   s6, $0000(v0)
801E3398	lui    a1, $00ff
801E339C	ori    a1, a1, $ffff
801E33A0	and    t0, t2, a1
801E33A4	addiu  t2, t2, $0058
801E33A8	addiu  t1, t1, $0058
801E33AC	addu   a2, t5, s1
801E33B0	lui    a3, $ff00
801E33B4	lw     a0, $0070(sp)
801E33B8	lw     t7, $0080(sp)
801E33BC	lw     v1, $0008(a2)
801E33C0	sll    a0, a0, $02
801E33C4	addu   a0, a0, t7
801E33C8	lw     v0, $0000(a0)
801E33CC	and    v1, v1, a3
801E33D0	and    v0, v0, a1
801E33D4	or     v1, v1, v0
801E33D8	sw     v1, $0008(a2)

L1e33dc:	; 801E33DC
801E33DC	lw     v0, $0000(a0)
801E33E0	addiu  s1, s1, $0058
801E33E4	and    v0, v0, a3
801E33E8	or     v0, v0, t0
801E33EC	sw     v0, $0000(a0)

L1e33f0:	; 801E33F0
801E33F0	lh     v0, $0006(s4)
801E33F4	addiu  s5, s5, $0001
801E33F8	slt    v0, s5, v0
801E33FC	bne    v0, zero, L1e2f38 [$801e2f38]
801E3400	nop

L1e3404:	; 801E3404
801E3404	lw     ra, $00d4(sp)
801E3408	lw     fp, $00d0(sp)
801E340C	lw     s7, $00cc(sp)
801E3410	lw     s6, $00c8(sp)
801E3414	lw     s5, $00c4(sp)
801E3418	lw     s4, $00c0(sp)
801E341C	lw     s3, $00bc(sp)
801E3420	lw     s2, $00b8(sp)
801E3424	lw     s1, $00b4(sp)
801E3428	lw     s0, $00b0(sp)
801E342C	addiu  sp, sp, $00d8
801E3430	jr     ra 
801E3434	nop


func1e3438:	; 801E3438
801E3438	addiu  sp, sp, $ffe8 (=-$18)
801E343C	sw     s0, $0010(sp)
801E3440	addu   s0, a0, zero
801E3444	sw     ra, $0014(sp)
801E3448	lw     a0, $0014(s0)
801E344C	nop
801E3450	beq    a0, zero, L1e34a8 [$801e34a8]
801E3454	nop
801E3458	jal    func31f0c [$80031f0c]
801E345C	nop
801E3460	lw     v0, $001c(s0)
801E3464	nop
801E3468	lw     a0, $0000(v0)
801E346C	jal    func31f0c [$80031f0c]
801E3470	nop
801E3474	lw     a0, $001c(s0)
801E3478	jal    func31f0c [$80031f0c]
801E347C	nop
801E3480	lw     a0, $0020(s0)
801E3484	jal    func31f0c [$80031f0c]
801E3488	nop
801E348C	lw     a0, $0018(s0)
801E3490	nop
801E3494	beq    a0, zero, L1e34a4 [$801e34a4]
801E3498	nop
801E349C	jal    func31f0c [$80031f0c]

L1e34a0:	; 801E34A0
801E34A0	nop

L1e34a4:	; 801E34A4
801E34A4	sw     zero, $0014(s0)

L1e34a8:	; 801E34A8
801E34A8	lw     ra, $0014(sp)
801E34AC	lw     s0, $0010(sp)
801E34B0	addiu  sp, sp, $0018
801E34B4	jr     ra 
801E34B8	nop


func1e34bc:	; 801E34BC
801E34BC	ori    v0, zero, $0002
801E34C0	beq    a0, v0, L1e3504 [$801e3504]
801E34C4	slti   v0, a0, $0003
801E34C8	beq    v0, zero, L1e34e0 [$801e34e0]
801E34CC	ori    v0, zero, $0001
801E34D0	beq    a0, v0, L1e34f4 [$801e34f4]
801E34D4	nop
801E34D8	j      L1e3524 [$801e3524]
801E34DC	nop

L1e34e0:	; 801E34E0
801E34E0	ori    v0, zero, $0003
801E34E4	beq    a0, v0, L1e3514 [$801e3514]
801E34E8	nop
801E34EC	j      L1e3524 [$801e3524]
801E34F0	nop

L1e34f4:	; 801E34F4
801E34F4	lui    v0, $801e
801E34F8	addiu  v0, v0, $08d4
801E34FC	j      L1e352c [$801e352c]
801E3500	nop

L1e3504:	; 801E3504
801E3504	lui    v0, $801e
801E3508	addiu  v0, v0, $0938
801E350C	j      L1e352c [$801e352c]
801E3510	nop

L1e3514:	; 801E3514
801E3514	lui    v0, $801e
801E3518	addiu  v0, v0, $0988

L1e351c:	; 801E351C
801E351C	j      L1e352c [$801e352c]
801E3520	nop

L1e3524:	; 801E3524
801E3524	lui    v0, $801e
801E3528	addiu  v0, v0, $0850

L1e352c:	; 801E352C
801E352C	jr     ra 
801E3530	nop



////////////////////////////////
// func1e3534
801E3534-801E35CC
////////////////////////////////



////////////////////////////////
// func1e35d0
801E35D0-801E36B8
////////////////////////////////



func1e36bc:	; 801E36BC
801E36BC	addiu  sp, sp, $ffc0 (=-$40)
801E36C0	sw     s0, $0020(sp)
801E36C4	addu   s0, a0, zero
801E36C8	sw     s3, $002c(sp)
801E36CC	addu   s3, a1, zero
801E36D0	sw     s4, $0030(sp)
801E36D4	addu   s4, a2, zero
801E36D8	sw     s5, $0034(sp)
801E36DC	sw     ra, $003c(sp)
801E36E0	sw     s6, $0038(sp)
801E36E4	sw     s2, $0028(sp)
801E36E8	sw     s1, $0024(sp)
801E36EC	lw     v0, $0000(s0)
801E36F0	lw     s6, $0050(sp)
801E36F4	beq    v0, zero, L1e37a0 [$801e37a0]
801E36F8	addu   s5, a3, zero
801E36FC	lbu    v0, $0034(s0)
801E3700	nop
801E3704	beq    v0, zero, L1e3788 [$801e3788]
801E3708	addu   s2, zero, zero
801E370C	jal    func1e7298 [$801e7298]
801E3710	nop
801E3714	lbu    v0, $0037(s0)
801E3718	nop
801E371C	beq    v0, zero, L1e373c [$801e373c]
801E3720	nop
801E3724	lw     a0, $0004(s0)
801E3728	lh     a1, $001c(s0)
801E372C	jal    func1dc848 [$801dc848]
801E3730	addu   s1, zero, zero
801E3734	j      L1e374c [$801e374c]
801E3738	nop

L1e373c:	; 801E373C
801E373C	lw     a0, $0004(s0)
801E3740	lh     a1, $001c(s0)
801E3744	jal    func1dc5c0 [$801dc5c0]
801E3748	addu   s1, zero, zero

L1e374c:	; 801E374C
801E374C	blez   s4, L1e3788 [$801e3788]
801E3750	addu   a0, s3, zero

loop1e3754:	; 801E3754
801E3754	lw     a1, $0004(s0)
801E3758	lhu    a2, $003c(s0)
801E375C	lh     a3, $001c(s0)
801E3760	jal    func1ddbf8 [$801ddbf8]
801E3764	addiu  s1, s1, $0001
801E3768	or     s2, s2, v0
801E376C	addu   a0, s0, zero
801E3770	addu   a1, s3, zero
801E3774	jal    func1e5d44 [$801e5d44]
801E3778	addu   a2, s5, zero
801E377C	slt    v0, s1, s4
801E3780	bne    v0, zero, loop1e3754 [$801e3754]
801E3784	addu   a0, s3, zero

L1e3788:	; 801E3788
801E3788	sw     s6, $0010(sp)
801E378C	addu   a0, s0, zero
801E3790	addu   a1, s3, zero
801E3794	addu   a2, s2, zero
801E3798	jal    func1e39f0 [$801e39f0]

L1e379c:	; 801E379C
801E379C	addu   a3, s4, zero

L1e37a0:	; 801E37A0
801E37A0	addu   v0, s2, zero
801E37A4	lw     ra, $003c(sp)
801E37A8	lw     s6, $0038(sp)
801E37AC	lw     s5, $0034(sp)
801E37B0	lw     s4, $0030(sp)
801E37B4	lw     s3, $002c(sp)
801E37B8	lw     s2, $0028(sp)
801E37BC	lw     s1, $0024(sp)
801E37C0	lw     s0, $0020(sp)
801E37C4	addiu  sp, sp, $0040
801E37C8	jr     ra 
801E37CC	nop


func1e37d0:	; 801E37D0
801E37D0	addiu  sp, sp, $ffd0 (=-$30)

loop1e37d4:	; 801E37D4
801E37D4	sw     s0, $0020(sp)
801E37D8	addu   s0, a0, zero
801E37DC	sw     ra, $0028(sp)
801E37E0	sw     s1, $0024(sp)

L1e37e4:	; 801E37E4
801E37E4	lbu    v0, $005c(s0)
801E37E8	nop
801E37EC	sll    v0, v0, $02
801E37F0	lui    at, $801f
801E37F4	addu   at, at, v0
801E37F8	lw     v1, $8670(at)
801E37FC	lui    a0, $801f
801E3800	addiu  a0, a0, $8670 (=-$7990)
801E3804	beq    v1, zero, L1e39d0 [$801e39d0]
801E3808	lui    s1, $1f80
801E380C	lhu    v0, $004a(s0)
801E3810	nop
801E3814	andi   v0, v0, $0010
801E3818	bne    v0, zero, L1e382c [$801e382c]
801E381C	nop
801E3820	lbu    v0, $0034(v1)
801E3824	nop
801E3828	sb     v0, $0034(s0)

L1e382c:	; 801E382C
801E382C	lbu    v0, $0034(s0)
801E3830	nop
801E3834	beq    v0, zero, L1e39d8 [$801e39d8]
801E3838	nop
801E383C	lbu    v0, $005d(s0)
801E3840	nop
801E3844	beq    v0, zero, L1e38d8 [$801e38d8]
801E3848	nop
801E384C	lh     v1, $005e(s0)
801E3850	nop
801E3854	beq    v1, zero, L1e3894 [$801e3894]
801E3858	lui    a2, $1f80
801E385C	lbu    v0, $005c(s0)
801E3860	sll    a1, v1, $05
801E3864	sll    v0, v0, $02
801E3868	addu   v0, v0, a0
801E386C	lw     v0, $0000(v0)
801E3870	subu   a1, a1, v1
801E3874	lw     v0, $0004(v0)
801E3878	sll    a1, a1, $02
801E387C	addiu  a0, v0, $002c
801E3880	addu   a1, a1, v0
801E3884	jal    func490b4 [$800490b4]
801E3888	addiu  a1, a1, $002c
801E388C	j      L1e38b8 [$801e38b8]
801E3890	nop

L1e3894:	; 801E3894
801E3894	lbu    v0, $005c(s0)
801E3898	nop
801E389C	sll    v0, v0, $02
801E38A0	addu   v0, v0, a0
801E38A4	lw     v0, $0000(v0)
801E38A8	nop
801E38AC	lw     v0, $0004(v0)
801E38B0	nop
801E38B4	addiu  s1, v0, $002c

L1e38b8:	; 801E38B8
801E38B8	lw     a1, $0004(s0)
801E38BC	addu   a0, s1, zero
801E38C0	jal    func49a84 [$80049a84]
801E38C4	addiu  a1, a1, $000c
801E38C8	lw     a1, $0004(s0)
801E38CC	addu   a0, s1, zero
801E38D0	jal    func49a84 [$80049a84]
801E38D4	addiu  a1, a1, $002c

L1e38d8:	; 801E38D8
801E38D8	lh     v1, $005e(s0)
801E38DC	nop
801E38E0	beq    v1, zero, L1e3924 [$801e3924]
801E38E4	addu   a2, s1, zero
801E38E8	lbu    v0, $005c(s0)
801E38EC	sll    a1, v1, $05
801E38F0	sll    v0, v0, $02
801E38F4	lui    at, $801f
801E38F8	addu   at, at, v0
801E38FC	lw     v0, $8670(at)
801E3900	subu   a1, a1, v1
801E3904	lw     v0, $0004(v0)
801E3908	sll    a1, a1, $02
801E390C	addiu  a0, v0, $000c
801E3910	addu   a1, a1, v0
801E3914	jal    func491c4 [$800491c4]
801E3918	addiu  a1, a1, $002c
801E391C	j      L1e394c [$801e394c]
801E3920	nop

L1e3924:	; 801E3924
801E3924	lbu    v0, $005c(s0)
801E3928	nop
801E392C	sll    v0, v0, $02
801E3930	lui    at, $801f
801E3934	addu   at, at, v0
801E3938	lw     v0, $8670(at)
801E393C	nop
801E3940	lw     v0, $0004(v0)
801E3944	nop
801E3948	addiu  s1, v0, $000c

L1e394c:	; 801E394C
801E394C	jal    func49da4 [$80049da4]
801E3950	addu   a0, s1, zero
801E3954	jal    func49e34 [$80049e34]
801E3958	addu   a0, s1, zero
801E395C	lhu    v0, $006a(s0)
801E3960	nop

L1e3964:	; 801E3964
801E3964	sh     v0, $0010(sp)
801E3968	lhu    v0, $006c(s0)
801E396C	nop
801E3970	sh     v0, $0012(sp)
801E3974	lhu    v0, $006e(s0)
801E3978	nop
801E397C	sh     v0, $0014(sp)
801E3980	addiu  v0, sp, $0010
801E3984	lwc2   zero, $0000(v0)
801E3988	lwc2   at, $0004(v0)
801E398C	nop
801E3990	nop
801E3994	gte_func18t0,r11r12
801E3998	lw     v0, $0004(s0)
801E399C	nop
801E39A0	addiu  v0, v0, $0020
801E39A4	swc2   t9, $0000(v0)
801E39A8	swc2   k0, $0004(v0)
801E39AC	swc2   k1, $0008(v0)
801E39B0	lw     v0, $0004(s0)
801E39B4	nop
801E39B8	addiu  v0, v0, $005c
801E39BC	swc2   t9, $0000(v0)
801E39C0	swc2   k0, $0004(v0)
801E39C4	swc2   k1, $0008(v0)
801E39C8	j      L1e39d8 [$801e39d8]
801E39CC	nop

L1e39d0:	; 801E39D0
801E39D0	ori    v0, zero, $00ff
801E39D4	sb     v0, $005c(s0)

L1e39d8:	; 801E39D8
801E39D8	lw     ra, $0028(sp)
801E39DC	lw     s1, $0024(sp)
801E39E0	lw     s0, $0020(sp)
801E39E4	addiu  sp, sp, $0030
801E39E8	jr     ra 
801E39EC	nop



////////////////////////////////
// func1e39f0
801E39F0-801E59D0
////////////////////////////////



func1e59d4:	; 801E59D4
801E59D4	addiu  sp, sp, $ffd8 (=-$28)
801E59D8	sw     s2, $0018(sp)
801E59DC	lw     s2, $0038(sp)
801E59E0	sw     s0, $0010(sp)
801E59E4	addu   s0, a1, zero
801E59E8	sw     s4, $0020(sp)
801E59EC	addu   s4, a2, zero
801E59F0	sw     s1, $0014(sp)
801E59F4	addu   s1, a3, zero
801E59F8	sw     s3, $001c(sp)
801E59FC	lw     s3, $003c(sp)
801E5A00	slti   v0, s4, $0002
801E5A04	beq    v0, zero, L1e5a24 [$801e5a24]
801E5A08	sw     ra, $0024(sp)
801E5A0C	ori    v0, zero, $0001
801E5A10	sh     s1, $0054(s0)
801E5A14	sh     s2, $0056(s0)
801E5A18	sh     s3, $0058(s0)
801E5A1C	j      L1e5b2c [$801e5b2c]
801E5A20	sb     v0, $0005(s0)

L1e5a24:	; 801E5A24
801E5A24	lh     v0, $0054(s0)
801E5A28	nop
801E5A2C	bne    v0, s1, L1e5a54 [$801e5a54]
801E5A30	nop
801E5A34	lh     v0, $0056(s0)
801E5A38	nop
801E5A3C	bne    v0, s2, L1e5a54 [$801e5a54]
801E5A40	nop
801E5A44	lh     v0, $0058(s0)
801E5A48	nop
801E5A4C	beq    v0, s3, L1e5b2c [$801e5b2c]
801E5A50	nop

L1e5a54:	; 801E5A54
801E5A54	lw     v0, $0070(s0)
801E5A58	nop
801E5A5C	bne    v0, zero, L1e5a70 [$801e5a70]
801E5A60	addu   v1, v0, zero
801E5A64	jal    func1df6f0 [$801df6f0]
801E5A68	nop
801E5A6C	addu   v1, v0, zero

L1e5a70:	; 801E5A70
801E5A70	beq    v1, zero, L1e5b2c [$801e5b2c]
801E5A74	ori    v0, zero, $0001
801E5A78	sb     v0, $0000(v1)
801E5A7C	ori    v0, zero, $0003
801E5A80	sb     v0, $0002(v1)
801E5A84	ori    v0, zero, $00fe
801E5A88	sb     zero, $0001(v1)
801E5A8C	sb     v0, $0003(v1)
801E5A90	lhu    v0, $0054(s0)
801E5A94	nop
801E5A98	sh     v0, $0004(v1)
801E5A9C	lhu    v0, $0056(s0)
801E5AA0	nop
801E5AA4	sh     v0, $0006(v1)
801E5AA8	lhu    v0, $0058(s0)
801E5AAC	nop
801E5AB0	sh     v0, $0008(v1)
801E5AB4	lh     v0, $0054(s0)
801E5AB8	nop
801E5ABC	subu   v0, s1, v0
801E5AC0	andi   s1, v0, $0fff
801E5AC4	slti   v0, s1, $0800
801E5AC8	bne    v0, zero, L1e5ad4 [$801e5ad4]
801E5ACC	nop
801E5AD0	addiu  s1, s1, $f000 (=-$1000)

L1e5ad4:	; 801E5AD4
801E5AD4	sh     s1, $000a(v1)
801E5AD8	lh     v0, $0056(s0)
801E5ADC	nop
801E5AE0	subu   v0, s2, v0
801E5AE4	andi   s2, v0, $0fff
801E5AE8	slti   v0, s2, $0800
801E5AEC	bne    v0, zero, L1e5af8 [$801e5af8]
801E5AF0	nop
801E5AF4	addiu  s2, s2, $f000 (=-$1000)

L1e5af8:	; 801E5AF8
801E5AF8	sh     s2, $000c(v1)
801E5AFC	lh     v0, $0058(s0)
801E5B00	nop
801E5B04	subu   v0, s3, v0
801E5B08	andi   s3, v0, $0fff
801E5B0C	slti   v0, s3, $0800
801E5B10	bne    v0, zero, L1e5b1c [$801e5b1c]
801E5B14	nop
801E5B18	addiu  s3, s3, $f000 (=-$1000)

L1e5b1c:	; 801E5B1C
801E5B1C	sh     s3, $000e(v1)
801E5B20	sh     zero, $0010(v1)
801E5B24	sh     s4, $0012(v1)
801E5B28	sw     v1, $0070(s0)

L1e5b2c:	; 801E5B2C
801E5B2C	lw     ra, $0024(sp)
801E5B30	lw     s4, $0020(sp)
801E5B34	lw     s3, $001c(sp)
801E5B38	lw     s2, $0018(sp)
801E5B3C	lw     s1, $0014(sp)
801E5B40	lw     s0, $0010(sp)
801E5B44	addiu  sp, sp, $0028
801E5B48	jr     ra 
801E5B4C	nop


func1e5b50:	; 801E5B50
801E5B50	addiu  sp, sp, $ffc8 (=-$38)
801E5B54	sw     s7, $002c(sp)
801E5B58	lw     s7, $0048(sp)
801E5B5C	sw     fp, $0030(sp)
801E5B60	lw     fp, $004c(sp)
801E5B64	sw     s5, $0024(sp)
801E5B68	lw     s5, $0050(sp)
801E5B6C	sw     s6, $0028(sp)
801E5B70	lw     s6, $0054(sp)
801E5B74	sw     s1, $0014(sp)
801E5B78	addu   s1, a1, zero
801E5B7C	sw     s2, $0018(sp)
801E5B80	addu   s2, a2, zero
801E5B84	sw     s3, $001c(sp)
801E5B88	sw     ra, $0034(sp)
801E5B8C	sw     s4, $0020(sp)
801E5B90	sw     s0, $0010(sp)
801E5B94	lw     v0, $0070(s1)
801E5B98	lw     s4, $0058(sp)
801E5B9C	bne    v0, zero, L1e5bac [$801e5bac]
801E5BA0	addu   s3, a3, zero
801E5BA4	jal    func1df6f0 [$801df6f0]
801E5BA8	nop

L1e5bac:	; 801E5BAC
801E5BAC	addu   s0, v0, zero
801E5BB0	beq    s0, zero, L1e5c40 [$801e5c40]
801E5BB4	ori    v0, zero, $0001
801E5BB8	sb     v0, $0000(s0)
801E5BBC	addiu  v0, s2, $0007
801E5BC0	sb     v0, $0002(s0)
801E5BC4	ori    v0, zero, $00fe
801E5BC8	sb     zero, $0001(s0)
801E5BCC	sb     v0, $0003(s0)
801E5BD0	lw     v0, $005c(s1)
801E5BD4	nop
801E5BD8	subu   v0, s5, v0
801E5BDC	mult   v0, v0
801E5BE0	lw     v0, $0060(s1)
801E5BE4	mflo   v1
801E5BE8	subu   v0, s6, v0
801E5BEC	nop
801E5BF0	mult   v0, v0
801E5BF4	lw     v0, $0064(s1)
801E5BF8	mflo   a0
801E5BFC	subu   v0, s4, v0
801E5C00	nop
801E5C04	mult   v0, v0
801E5C08	addu   v1, v1, a0
801E5C0C	mflo   a0
801E5C10	jal    system_square_root [$80048af4]
801E5C14	addu   a0, v1, a0
801E5C18	addiu  v0, v0, $0001
801E5C1C	sh     v0, $0004(s0)
801E5C20	sh     s3, $0006(s0)
801E5C24	sh     s7, $0008(s0)
801E5C28	sh     s5, $000a(s0)
801E5C2C	sh     s6, $000c(s0)
801E5C30	sh     s4, $000e(s0)
801E5C34	sh     zero, $0010(s0)
801E5C38	sh     fp, $0012(s0)
801E5C3C	sw     s0, $0070(s1)

L1e5c40:	; 801E5C40
801E5C40	lw     ra, $0034(sp)
801E5C44	lw     fp, $0030(sp)
801E5C48	lw     s7, $002c(sp)
801E5C4C	lw     s6, $0028(sp)
801E5C50	lw     s5, $0024(sp)
801E5C54	lw     s4, $0020(sp)
801E5C58	lw     s3, $001c(sp)
801E5C5C	lw     s2, $0018(sp)
801E5C60	lw     s1, $0014(sp)
801E5C64	lw     s0, $0010(sp)
801E5C68	addiu  sp, sp, $0038
801E5C6C	jr     ra 
801E5C70	nop


func1e5c74:	; 801E5C74
801E5C74	lhu    v0, $0012(a1)
801E5C78	nop
801E5C7C	beq    v0, zero, L1e5cc8 [$801e5cc8]
801E5C80	nop
801E5C84	beq    a2, zero, L1e5c98 [$801e5c98]
801E5C88	sh     zero, $0098(a0)
801E5C8C	lhu    v0, $0002(a1)
801E5C90	j      L1e5ca0 [$801e5ca0]
801E5C94	sh     v0, $009a(a0)

L1e5c98:	; 801E5C98
801E5C98	addiu  v0, zero, $ffff (=-$1)
801E5C9C	sh     v0, $009a(a0)

L1e5ca0:	; 801E5CA0
801E5CA0	sh     zero, $009c(a0)
801E5CA4	lhu    v0, $0012(a1)
801E5CA8	nop
801E5CAC	sh     v0, $009e(a0)
801E5CB0	lw     v0, $0014(a1)
801E5CB4	nop
801E5CB8	addu   v0, a1, v0
801E5CBC	sw     v0, $00a0(a0)
801E5CC0	j      L1e5cd0 [$801e5cd0]
801E5CC4	sw     v0, $00a4(a0)

L1e5cc8:	; 801E5CC8
801E5CC8	addiu  v0, zero, $ffff (=-$1)
801E5CCC	sh     v0, $0098(a0)

L1e5cd0:	; 801E5CD0
801E5CD0	jr     ra 
801E5CD4	nop


func1e5cd8:	; 801E5CD8
801E5CD8	bne    a1, zero, L1e5cf0 [$801e5cf0]
801E5CDC	nop
801E5CE0	lui    v0, $8006
801E5CE4	lw     v0, $883c(v0)
801E5CE8	j      L1e5d10 [$801e5d10]
801E5CEC	nop

L1e5cf0:	; 801E5CF0
801E5CF0	ori    v0, zero, $0001
801E5CF4	beq    a1, v0, L1e5d20 [$801e5d20]
801E5CF8	ori    v0, zero, $0002
801E5CFC	bne    a1, v0, L1e5d3c [$801e5d3c]
801E5D00	nop
801E5D04	lw     v0, $00b4(a0)
801E5D08	nop
801E5D0C	lw     v0, $0008(v0)

L1e5d10:	; 801E5D10
801E5D10	nop
801E5D14	lhu    v0, $0014(v0)
801E5D18	j      L1e5d3c [$801e5d3c]
801E5D1C	sll    v0, v0, $10

L1e5d20:	; 801E5D20
801E5D20	lw     v0, $00b0(a0)
801E5D24	nop
801E5D28	lw     v0, $0008(v0)
801E5D2C	nop
801E5D30	lhu    v0, $0014(v0)
801E5D34	nop
801E5D38	sll    v0, v0, $10

L1e5d3c:	; 801E5D3C
801E5D3C	jr     ra 
801E5D40	nop


func1e5d44:	; 801E5D44
801E5D44	addiu  sp, sp, $ff78 (=-$88)
801E5D48	sw     s1, $0064(sp)
801E5D4C	addu   s1, a0, zero
801E5D50	sw     ra, $0084(sp)
801E5D54	sw     fp, $0080(sp)
801E5D58	sw     s7, $007c(sp)
801E5D5C	sw     s6, $0078(sp)
801E5D60	sw     s5, $0074(sp)
801E5D64	sw     s4, $0070(sp)
801E5D68	sw     s3, $006c(sp)
801E5D6C	sw     s2, $0068(sp)
801E5D70	sw     s0, $0060(sp)
801E5D74	lh     v0, $0098(s1)
801E5D78	nop
801E5D7C	bltz   v0, L1e62f8 [$801e62f8]
801E5D80	addu   fp, a2, zero
801E5D84	lh     v0, $009c(s1)
801E5D88	lh     v1, $009e(s1)
801E5D8C	nop
801E5D90	slt    v0, v0, v1
801E5D94	beq    v0, zero, L1e62c0 [$801e62c0]
801E5D98	nop

L1e5d9c:	; 801E5D9C
801E5D9C	lw     s0, $00a0(s1)
801E5DA0	lh     v1, $0098(s1)
801E5DA4	lh     v0, $0000(s0)
801E5DA8	nop
801E5DAC	bne    v1, v0, L1e62c0 [$801e62c0]
801E5DB0	nop
801E5DB4	lbu    v0, $0002(s0)
801E5DB8	nop
801E5DBC	addiu  v1, v0, $ffff (=-$1)
801E5DC0	sltiu  v0, v1, $0009
801E5DC4	beq    v0, zero, L1e629c [$801e629c]
801E5DC8	sll    v0, v1, $02
801E5DCC	lui    at, $801e
801E5DD0	addu   at, at, v0
801E5DD4	lw     v0, $c208(at)
801E5DD8	nop
801E5DDC	jr     v0 
801E5DE0	nop

801E5DE4	lw     v0, $00a0(s1)
801E5DE8	j      L1e6298 [$801e6298]
801E5DEC	addiu  v0, v0, $0014
801E5DF0	lbu    v0, $0004(s0)
801E5DF4	nop
801E5DF8	beq    v0, zero, L1e5f60 [$801e5f60]
801E5DFC	nop
801E5E00	lbu    v1, $0003(s0)

L1e5e04:	; 801E5E04
801E5E04	nop
801E5E08	sltiu  v0, v1, $0002
801E5E0C	beq    v0, zero, L1e5f54 [$801e5f54]
801E5E10	nop
801E5E14	lbu    v0, $0005(s0)
801E5E18	nop
801E5E1C	beq    v0, zero, L1e5e38 [$801e5e38]
801E5E20	addu   a1, s0, zero
801E5E24	sll    v0, v1, $02
801E5E28	addu   v0, v0, v1
801E5E2C	sll    v0, v0, $02
801E5E30	j      L1e5e48 [$801e5e48]
801E5E34	addiu  v1, zero, $ffff (=-$1)

L1e5e38:	; 801E5E38
801E5E38	sll    v0, v1, $02
801E5E3C	addu   v0, v0, v1
801E5E40	lbu    v1, $0020(s1)
801E5E44	sll    v0, v0, $02

L1e5e48:	; 801E5E48
801E5E48	lui    at, $801f
801E5E4C	addu   at, at, v0
801E5E50	sh     v1, $8658(at)
801E5E54	lbu    v1, $0003(a1)
801E5E58	lui    a0, $801f
801E5E5C	lw     a0, $8644(a0)
801E5E60	sll    v0, v1, $02
801E5E64	addu   v0, v0, v1
801E5E68	lbu    v1, $0006(a1)
801E5E6C	sll    v0, v0, $02
801E5E70	lui    at, $801f
801E5E74	addu   at, at, v0
801E5E78	sh     v1, $865a(at)
801E5E7C	lbu    v1, $0003(a1)
801E5E80	lbu    v0, $0007(a1)
801E5E84	sll    v1, v1, $01
801E5E88	addu   v1, v1, a0
801E5E8C	sll    v0, v0, $04
801E5E90	sh     v0, $0002(v1)
801E5E94	lbu    v1, $0003(a1)
801E5E98	lbu    v0, $0008(a1)
801E5E9C	sll    v1, v1, $01
801E5EA0	addu   v1, a0, v1
801E5EA4	sll    v0, v0, $04
801E5EA8	sh     v0, $0008(v1)
801E5EAC	lbu    v0, $0003(a1)
801E5EB0	lbu    v1, $0009(a1)
801E5EB4	sll    v0, v0, $01
801E5EB8	addu   a0, a0, v0
801E5EBC	sll    v1, v1, $04
801E5EC0	sh     v1, $000e(a0)
801E5EC4	lbu    v1, $0003(a1)
801E5EC8	nop
801E5ECC	sll    v0, v1, $02
801E5ED0	addu   v0, v0, v1
801E5ED4	lhu    v1, $000a(a1)
801E5ED8	sll    v0, v0, $02
801E5EDC	lui    at, $801f
801E5EE0	addu   at, at, v0
801E5EE4	sh     v1, $8650(at)
801E5EE8	lbu    v1, $0003(a1)
801E5EEC	nop
801E5EF0	sll    v0, v1, $02
801E5EF4	addu   v0, v0, v1
801E5EF8	lhu    v1, $000c(a1)
801E5EFC	sll    v0, v0, $02
801E5F00	lui    at, $801f
801E5F04	addu   at, at, v0
801E5F08	sh     v1, $8652(at)
801E5F0C	lbu    v1, $0003(a1)
801E5F10	nop
801E5F14	sll    v0, v1, $02
801E5F18	addu   v0, v0, v1
801E5F1C	lhu    v1, $000e(a1)
801E5F20	sll    v0, v0, $02
801E5F24	lui    at, $801f
801E5F28	addu   at, at, v0
801E5F2C	sh     v1, $8654(at)
801E5F30	lbu    v1, $0003(a1)
801E5F34	nop
801E5F38	sll    v0, v1, $02
801E5F3C	addu   v0, v0, v1
801E5F40	lhu    v1, $0010(a1)
801E5F44	sll    v0, v0, $02
801E5F48	lui    at, $801f
801E5F4C	addu   at, at, v0
801E5F50	sh     v1, $864e(at)

L1e5f54:	; 801E5F54
801E5F54	lw     v0, $00a0(s1)
801E5F58	j      L1e6298 [$801e6298]
801E5F5C	addiu  v0, v0, $0012

L1e5f60:	; 801E5F60
801E5F60	lbu    v0, $0003(s0)
801E5F64	nop
801E5F68	sll    v1, v0, $02
801E5F6C	addu   v1, v1, v0
801E5F70	sll    v1, v1, $02
801E5F74	lui    at, $801f
801E5F78	addu   at, at, v1
801E5F7C	sh     zero, $864e(at)
801E5F80	j      L1e628c [$801e628c]
801E5F84	nop
801E5F88	lbu    v0, $0003(s0)
801E5F8C	addu   a1, fp, zero
801E5F90	sll    a0, v0, $03
801E5F94	subu   a0, a0, v0
801E5F98	lw     v0, $0110(s1)
801E5F9C	sll    a0, a0, $04
801E5FA0	jal    func1e0844 [$801e0844]
801E5FA4	addu   a0, a0, v0
801E5FA8	lbu    v0, $0004(s0)
801E5FAC	nop
801E5FB0	beq    v0, zero, L1e628c [$801e628c]
801E5FB4	nop
801E5FB8	lw     v0, $00a0(s1)
801E5FBC	j      L1e6298 [$801e6298]
801E5FC0	addiu  v0, v0, $001c
801E5FC4	lw     v0, $00a0(s1)
801E5FC8	j      L1e6298 [$801e6298]
801E5FCC	addiu  v0, v0, $0008
801E5FD0	lw     v0, $00a0(s1)
801E5FD4	j      L1e6298 [$801e6298]
801E5FD8	addiu  v0, v0, $0004
801E5FDC	lbu    v1, $0004(s0)
801E5FE0	lw     a0, $0004(s1)
801E5FE4	sll    v0, v1, $05
801E5FE8	subu   v0, v0, v1
801E5FEC	sll    v0, v0, $02
801E5FF0	lbu    v1, $0005(s0)
801E5FF4	addu   v0, v0, a0
801E5FF8	andi   v1, v1, $0001
801E5FFC	j      L1e628c [$801e628c]
801E6000	sb     v1, $0007(v0)
801E6004	addu   s6, s0, zero
801E6008	addu   s0, zero, zero
801E600C	lui    s2, $801f
801E6010	addiu  s2, s2, $8670 (=-$7990)
801E6014	lhu    t7, $0050(sp)
801E6018	lui    v1, $801f
801E601C	lh     v1, $86b0(v1)
801E6020	lui    s7, $801f
801E6024	lhu    s7, $863c(s7)
801E6028	sll    v0, t7, $10
801E602C	sra    s5, v0, $10
801E6030	addu   s4, v1, zero
801E6034	ori    v0, zero, $0001
801E6038	sllv   s3, v1, v0

loop1e603c:	; 801E603C
801E603C	lhu    v0, $010a(s1)
801E6040	nop
801E6044	srav   v0, s0, v0
801E6048	andi   v0, v0, $0001
801E604C	beq    v0, zero, L1e6098 [$801e6098]
801E6050	nop
801E6054	lw     v0, $0000(s2)
801E6058	lbu    a3, $0005(s6)
801E605C	beq    v0, zero, L1e6098 [$801e6098]
801E6060	nop
801E6064	blez   a3, L1e6098 [$801e6098]
801E6068	nop
801E606C	beq    s5, zero, L1e6088 [$801e6088]
801E6070	addu   a0, s1, zero
801E6074	andi   a1, s0, $ffff
801E6078	jal    func1e8394 [$801e8394]
801E607C	andi   a2, s3, $ffff
801E6080	j      L1e609c [$801e609c]
801E6084	addiu  s0, s0, $0001

L1e6088:	; 801E6088
801E6088	andi   a0, s0, $ffff
801E608C	andi   a1, s3, $ffff
801E6090	jal    func1e8330 [$801e8330]
801E6094	addu   a2, a3, zero

L1e6098:	; 801E6098
801E6098	addiu  s0, s0, $0001

L1e609c:	; 801E609C
801E609C	slti   v0, s0, $0008
801E60A0	bne    v0, zero, loop1e603c [$801e603c]
801E60A4	addiu  s2, s2, $0004
801E60A8	lw     v0, $00a0(s1)
801E60AC	lui    at, $801f
801E60B0	sh     s4, $86b0(at)
801E60B4	lui    at, $801f
801E60B8	sh     s7, $863c(at)
801E60BC	j      L1e6298 [$801e6298]
801E60C0	addiu  v0, v0, $000a
801E60C4	lbu    v0, $0004(s0)
801E60C8	nop
801E60CC	beq    v0, zero, L1e626c [$801e626c]
801E60D0	nop
801E60D4	lbu    v0, $0003(s0)
801E60D8	lbu    a0, $010e(s1)
801E60DC	nop
801E60E0	sltu   v0, v0, a0

L1e60e4:	; 801E60E4
801E60E4	beq    v0, zero, L1e6260 [$801e6260]
801E60E8	nop
801E60EC	lbu    v1, $0005(s0)
801E60F0	ori    v0, zero, $00ff
801E60F4	beq    v1, v0, L1e6118 [$801e6118]
801E60F8	sltu   v0, v1, a0
801E60FC	beq    v0, zero, L1e6118 [$801e6118]
801E6100	sll    v0, v1, $01
801E6104	addu   v0, v0, v1
801E6108	lw     v1, $0118(s1)
801E610C	sll    v0, v0, $04
801E6110	j      L1e611c [$801e611c]
801E6114	addu   s3, v0, v1

L1e6118:	; 801E6118
801E6118	addu   s3, zero, zero

L1e611c:	; 801E611C
801E611C	lbu    v0, $0006(s0)
801E6120	nop
801E6124	andi   v0, v0, $007f
801E6128	sltiu  v0, v0, $0004
801E612C	bne    v0, zero, L1e613c [$801e613c]
801E6130	addu   s2, zero, zero
801E6134	lui    s2, $801f
801E6138	lw     s2, $8644(s2)

L1e613c:	; 801E613C
801E613C	lbu    a0, $0007(s0)
801E6140	jal    func1e34bc [$801e34bc]
801E6144	nop
801E6148	lhu    a0, $0008(s0)
801E614C	lhu    t2, $000a(s0)
801E6150	lhu    t3, $000c(s0)
801E6154	lhu    t4, $000e(s0)
801E6158	lbu    v1, $0006(s0)
801E615C	lhu    t5, $0010(s0)
801E6160	andi   v1, v1, $0080
801E6164	beq    v1, zero, L1e61b8 [$801e61b8]
801E6168	addu   t6, v0, zero
801E616C	lh     v0, $0090(s1)
801E6170	nop
801E6174	bltz   v0, L1e629c [$801e629c]
801E6178	nop
801E617C	lhu    a1, $0094(s1)
801E6180	lhu    a2, $0096(s1)
801E6184	lbu    v1, $0012(s0)
801E6188	addu   v0, a0, a1
801E618C	addu   a0, v0, zero
801E6190	addu   v0, t2, a2
801E6194	addu   t2, v0, zero
801E6198	srl    v1, v1, $04
801E619C	ori    v0, zero, $0001
801E61A0	bne    v1, v0, L1e61b8 [$801e61b8]
801E61A4	nop
801E61A8	addu   v0, t3, a1
801E61AC	addu   t3, v0, zero
801E61B0	addu   v0, t4, a2
801E61B4	addu   t4, v0, zero

L1e61b8:	; 801E61B8
801E61B8	sll    a0, a0, $10
801E61BC	sra    a0, a0, $10
801E61C0	sll    v1, t2, $10
801E61C4	sra    v1, v1, $10
801E61C8	sll    v0, t3, $10
801E61CC	lbu    t0, $0003(s0)
801E61D0	lw     t1, $0118(s1)
801E61D4	lbu    a2, $0006(s0)
801E61D8	lbu    a3, $0012(s0)
801E61DC	sra    v0, v0, $10
801E61E0	sw     v0, $0020(sp)
801E61E4	sll    v0, t4, $10
801E61E8	sra    v0, v0, $10
801E61EC	sw     v0, $0024(sp)
801E61F0	sll    v0, t5, $10
801E61F4	sra    v0, v0, $10
801E61F8	addu   a1, s3, zero
801E61FC	sw     s2, $0010(sp)
801E6200	sw     a0, $0014(sp)
801E6204	sw     v1, $0018(sp)
801E6208	sw     zero, $001c(sp)
801E620C	sw     v0, $0028(sp)
801E6210	sw     a0, $002c(sp)
801E6214	sw     v1, $0030(sp)
801E6218	lbu    v0, $0013(s0)
801E621C	sll    a0, t0, $01

L1e6220:	; 801E6220
801E6220	addu   a0, a0, t0
801E6224	sw     v0, $0034(sp)
801E6228	lbu    v0, $0014(s0)
801E622C	sll    a0, a0, $04
801E6230	sw     v0, $0038(sp)
801E6234	lh     v0, $0016(s0)
801E6238	addu   a0, a0, t1
801E623C	sw     v0, $003c(sp)
801E6240	lh     v0, $0018(s0)
801E6244	andi   a2, a2, $007f
801E6248	sw     v0, $0040(sp)
801E624C	lh     v0, $001a(s0)
801E6250	ori    a3, a3, $0700
801E6254	sw     t6, $0048(sp)
801E6258	jal    func1e0a00 [$801e0a00]
801E625C	sw     v0, $0044(sp)

L1e6260:	; 801E6260
801E6260	lw     v0, $00a0(s1)
801E6264	j      L1e6298 [$801e6298]
801E6268	addiu  v0, v0, $001c

L1e626c:	; 801E626C
801E626C	lbu    v0, $0003(s0)
801E6270	nop
801E6274	sll    a0, v0, $01
801E6278	addu   a0, a0, v0
801E627C	lw     v0, $0118(s1)
801E6280	sll    a0, a0, $04
801E6284	jal    func1e165c [$801e165c]
801E6288	addu   a0, a0, v0

L1e628c:	; 801E628C
801E628C	lw     v0, $00a0(s1)
801E6290	nop
801E6294	addiu  v0, v0, $0006

L1e6298:	; 801E6298
801E6298	sw     v0, $00a0(s1)

L1e629c:	; 801E629C
801E629C	lhu    v0, $009c(s1)
801E62A0	lh     v1, $009e(s1)
801E62A4	addiu  v0, v0, $0001
801E62A8	sh     v0, $009c(s1)
801E62AC	sll    v0, v0, $10
801E62B0	sra    v0, v0, $10
801E62B4	slt    v0, v0, v1
801E62B8	bne    v0, zero, L1e5d9c [$801e5d9c]
801E62BC	nop

L1e62c0:	; 801E62C0
801E62C0	lhu    v0, $0098(s1)
801E62C4	lh     v1, $009a(s1)
801E62C8	addiu  v0, v0, $0001
801E62CC	bltz   v1, L1e62f8 [$801e62f8]
801E62D0	sh     v0, $0098(s1)
801E62D4	sll    v0, v0, $10
801E62D8	sra    v0, v0, $10
801E62DC	slt    v0, v0, v1
801E62E0	bne    v0, zero, L1e62f8 [$801e62f8]
801E62E4	nop
801E62E8	lw     v0, $00a4(s1)
801E62EC	sh     zero, $0098(s1)
801E62F0	sh     zero, $009c(s1)
801E62F4	sw     v0, $00a0(s1)

L1e62f8:	; 801E62F8
801E62F8	lw     ra, $0084(sp)

L1e62fc:	; 801E62FC
801E62FC	lw     fp, $0080(sp)
801E6300	lw     s7, $007c(sp)
801E6304	lw     s6, $0078(sp)
801E6308	lw     s5, $0074(sp)
801E630C	lw     s4, $0070(sp)
801E6310	lw     s3, $006c(sp)
801E6314	lw     s2, $0068(sp)
801E6318	lw     s1, $0064(sp)
801E631C	lw     s0, $0060(sp)
801E6320	addiu  sp, sp, $0088
801E6324	jr     ra 
801E6328	nop



////////////////////////////////
// func1e632c
801E632C-801E6334
////////////////////////////////



func1e6338:	; 801E6338
801E6338	addiu  sp, sp, $ffe8 (=-$18)
801E633C	sw     ra, $0010(sp)
801E6340	lw     a2, $0004(a0)
801E6344	lh     v0, $0088(a0)
801E6348	lw     v1, $005c(a2)
801E634C	nop
801E6350	subu   v0, v0, v1
801E6354	mult   v0, v0
801E6358	lh     v0, $008a(a0)
801E635C	lw     v1, $0060(a2)
801E6360	mflo   a1
801E6364	subu   v0, v0, v1
801E6368	nop
801E636C	mult   v0, v0
801E6370	lw     v1, $0064(a2)
801E6374	lh     v0, $008c(a0)
801E6378	mflo   a0
801E637C	subu   v0, v0, v1
801E6380	nop
801E6384	mult   v0, v0
801E6388	addu   a1, a1, a0
801E638C	mflo   a0
801E6390	jal    system_square_root [$80048af4]
801E6394	addu   a0, a1, a0
801E6398	lw     ra, $0010(sp)
801E639C	addiu  sp, sp, $0018
801E63A0	jr     ra 
801E63A4	nop


func1e63a8:	; 801E63A8
801E63A8	addiu  sp, sp, $ffc8 (=-$38)
801E63AC	sw     s0, $0028(sp)
801E63B0	addu   s0, a0, zero
801E63B4	sw     ra, $0030(sp)
801E63B8	sw     s1, $002c(sp)
801E63BC	lh     v1, $0058(s0)
801E63C0	ori    v0, zero, $00ff
801E63C4	bne    v1, v0, L1e63f8 [$801e63f8]
801E63C8	addu   a0, zero, zero
801E63CC	lhu    v1, $010a(s0)
801E63D0	nop
801E63D4	srav   v0, a0, v1

loop1e63d8:	; 801E63D8
801E63D8	andi   v0, v0, $0001
801E63DC	bne    v0, zero, L1e63f4 [$801e63f4]
801E63E0	nop
801E63E4	addiu  a0, a0, $0001
801E63E8	slti   v0, a0, $0008
801E63EC	bne    v0, zero, loop1e63d8 [$801e63d8]
801E63F0	srav   v0, a0, v1

L1e63f4:	; 801E63F4
801E63F4	lh     v1, $0058(s0)

L1e63f8:	; 801E63F8
801E63F8	ori    v0, zero, $00fe
801E63FC	bne    v1, v0, L1e640c [$801e640c]
801E6400	addu   a1, v1, zero
801E6404	lui    a0, $801f
801E6408	lhu    a0, $86b0(a0)

L1e640c:	; 801E640C
801E640C	ori    v0, zero, $00fd
801E6410	bne    v1, v0, L1e641c [$801e641c]
801E6414	ori    v0, zero, $00fc
801E6418	lbu    a0, $0020(s0)

L1e641c:	; 801E641C
801E641C	bne    v1, v0, L1e6428 [$801e6428]
801E6420	ori    v0, zero, $00fa
801E6424	lbu    a0, $0021(s0)

L1e6428:	; 801E6428
801E6428	bne    v1, v0, L1e6434 [$801e6434]

L1e642c:	; 801E642C
801E642C	addiu  v0, a1, $ffff (=-$1)
801E6430	ori    a0, zero, $000a

L1e6434:	; 801E6434
801E6434	sltiu  v0, v0, $007f
801E6438	beq    v0, zero, L1e6448 [$801e6448]
801E643C	sll    v0, a0, $02
801E6440	addiu  a0, v1, $ffff (=-$1)
801E6444	sll    v0, a0, $02

L1e6448:	; 801E6448
801E6448	lui    at, $801f
801E644C	addu   at, at, v0
801E6450	lw     a1, $8670(at)
801E6454	nop
801E6458	beq    a1, zero, L1e6560 [$801e6560]
801E645C	nop
801E6460	lbu    v0, $0020(s0)
801E6464	nop
801E6468	beq    a0, v0, L1e6560 [$801e6560]
801E646C	nop
801E6470	lh     v1, $005a(s0)
801E6474	nop
801E6478	beq    v1, zero, L1e64ac [$801e64ac]
801E647C	lui    s1, $1f80
801E6480	lw     v0, $0004(a1)
801E6484	sll    a1, v1, $05
801E6488	subu   a1, a1, v1
801E648C	sll    a1, a1, $02
801E6490	lui    a2, $1f80
801E6494	addiu  a0, v0, $000c
801E6498	addu   a1, a1, v0

L1e649c:	; 801E649C
801E649C	jal    func491c4 [$800491c4]
801E64A0	addiu  a1, a1, $002c
801E64A4	j      L1e64b8 [$801e64b8]
801E64A8	nop

L1e64ac:	; 801E64AC
801E64AC	lw     v0, $0004(a1)
801E64B0	nop
801E64B4	addiu  s1, v0, $000c

L1e64b8:	; 801E64B8
801E64B8	jal    func49da4 [$80049da4]
801E64BC	addu   a0, s1, zero
801E64C0	jal    func49e34 [$80049e34]
801E64C4	addu   a0, s1, zero
801E64C8	addiu  v0, s0, $0064
801E64CC	lwc2   zero, $0000(v0)
801E64D0	lwc2   at, $0004(v0)
801E64D4	nop
801E64D8	nop
801E64DC	gte_func18t0,r11r12
801E64E0	addiu  v0, sp, $0010
801E64E4	swc2   t9, $0000(v0)
801E64E8	swc2   k0, $0004(v0)
801E64EC	swc2   k1, $0008(v0)
801E64F0	lhu    v0, $0010(sp)
801E64F4	lw     v1, $0004(s0)
801E64F8	sh     v0, $0088(s0)
801E64FC	lhu    v0, $0014(sp)
801E6500	nop
801E6504	sh     v0, $008a(s0)
801E6508	lhu    v0, $0018(sp)
801E650C	nop
801E6510	sh     v0, $008c(s0)
801E6514	lw     v1, $0070(v1)
801E6518	nop
801E651C	beq    v1, zero, L1e6560 [$801e6560]
801E6520	nop
801E6524	lbu    v0, $0002(v1)
801E6528	nop
801E652C	addiu  v0, v0, $fff9 (=-$7)
801E6530	sltiu  v0, v0, $0002
801E6534	beq    v0, zero, L1e6560 [$801e6560]
801E6538	nop
801E653C	lhu    v0, $0010(sp)
801E6540	nop
801E6544	sh     v0, $000a(v1)

L1e6548:	; 801E6548
801E6548	lhu    v0, $0014(sp)
801E654C	nop
801E6550	sh     v0, $000c(v1)
801E6554	lhu    v0, $0018(sp)
801E6558	nop
801E655C	sh     v0, $000e(v1)

L1e6560:	; 801E6560
801E6560	lw     ra, $0030(sp)
801E6564	lw     s1, $002c(sp)
801E6568	lw     s0, $0028(sp)
801E656C	addiu  sp, sp, $0038
801E6570	jr     ra 
801E6574	nop


func1e6578:	; 801E6578
801E6578	addiu  sp, sp, $ffd0 (=-$30)
801E657C	sw     s3, $001c(sp)
801E6580	addu   s3, a0, zero
801E6584	sw     s4, $0020(sp)
801E6588	addu   s4, a2, zero
801E658C	sw     s2, $0018(sp)
801E6590	addu   s2, s4, zero
801E6594	sll    v0, a1, $05
801E6598	subu   v0, v0, a1
801E659C	sll    v0, v0, $02
801E65A0	sw     s0, $0010(sp)
801E65A4	addu   s0, v0, s4
801E65A8	sw     s5, $0024(sp)
801E65AC	addu   s5, a3, zero
801E65B0	addu   v0, v0, s5
801E65B4	sw     ra, $002c(sp)
801E65B8	sw     s6, $0028(sp)
801E65BC	sw     s1, $0014(sp)
801E65C0	lhu    s6, $000a(s4)
801E65C4	ori    v1, zero, $0001
801E65C8	sb     zero, $0007(s0)
801E65CC	sb     v1, $0007(v0)
801E65D0	lw     a1, $0070(s0)
801E65D4	jal    func1df7a8 [$801df7a8]
801E65D8	ori    s1, zero, $0001
801E65DC	lw     a1, $0074(s0)
801E65E0	addu   a0, s3, zero
801E65E4	jal    func1df7a8 [$801df7a8]
801E65E8	sw     zero, $0070(s0)
801E65EC	lw     a1, $0078(s0)
801E65F0	addu   a0, s3, zero
801E65F4	jal    func1df7a8 [$801df7a8]
801E65F8	sw     zero, $0074(s0)
801E65FC	slt    v0, s1, s6
801E6600	beq    v0, zero, L1e663c [$801e663c]
801E6604	sw     zero, $0078(s0)
801E6608	addiu  s2, s2, $007c

loop1e660c:	; 801E660C
801E660C	lw     v0, $0000(s2)
801E6610	nop
801E6614	bne    v0, s0, L1e6630 [$801e6630]
801E6618	addiu  s1, s1, $0001
801E661C	addu   a0, s3, zero
801E6620	lhu    a1, $000a(s2)
801E6624	addu   a2, s4, zero
801E6628	jal    func1e6578 [$801e6578]
801E662C	addu   a3, s5, zero

L1e6630:	; 801E6630
801E6630	slt    v0, s1, s6
801E6634	bne    v0, zero, loop1e660c [$801e660c]
801E6638	addiu  s2, s2, $007c

L1e663c:	; 801E663C
801E663C	lw     ra, $002c(sp)
801E6640	lw     s6, $0028(sp)
801E6644	lw     s5, $0024(sp)
801E6648	lw     s4, $0020(sp)
801E664C	lw     s3, $001c(sp)
801E6650	lw     s2, $0018(sp)
801E6654	lw     s1, $0014(sp)
801E6658	lw     s0, $0010(sp)
801E665C	addiu  sp, sp, $0030
801E6660	jr     ra 
801E6664	nop


func1e6668:	; 801E6668
801E6668	lhu    a2, $000a(a0)
801E666C	ori    v1, zero, $0001
801E6670	slt    v0, v1, a2
801E6674	beq    v0, zero, L1e66b4 [$801e66b4]
801E6678	nop
801E667C	ori    a3, zero, $0001
801E6680	addiu  a0, a0, $0007
801E6684	addiu  a0, a0, $007c

loop1e6688:	; 801E6688
801E6688	lbu    v0, $0000(a0)
801E668C	nop
801E6690	beq    v0, zero, L1e66a0 [$801e66a0]
801E6694	addiu  a1, a1, $007c
801E6698	sb     zero, $0000(a0)
801E669C	sb     a3, $0007(a1)

L1e66a0:	; 801E66A0
801E66A0	addiu  v1, v1, $0001
801E66A4	slt    v0, v1, a2
801E66A8	bne    v0, zero, loop1e6688 [$801e6688]
801E66AC	addiu  a0, a0, $007c
801E66B0	addiu  a0, a0, $ff84 (=-$7c)

L1e66b4:	; 801E66B4
801E66B4	jr     ra 
801E66B8	nop


func1e66bc:	; 801E66BC
801E66BC	addiu  sp, sp, $ffd0 (=-$30)
801E66C0	sw     s1, $0024(sp)
801E66C4	addu   s1, a0, zero
801E66C8	addu   a0, a1, zero
801E66CC	sw     s2, $0028(sp)
801E66D0	addu   s2, a3, zero
801E66D4	addu   a1, a2, zero
801E66D8	addiu  a2, sp, $0010
801E66DC	sw     ra, $002c(sp)
801E66E0	jal    system_outer_product2_A0_A1_to_A2 [$8004a328]
801E66E4	sw     s0, $0020(sp)
801E66E8	lw     a1, $0010(sp)
801E66EC	lw     v0, $0000(s1)
801E66F0	nop
801E66F4	mult   a1, v0
801E66F8	lw     v1, $0014(sp)
801E66FC	mflo   s0
801E6700	lw     v0, $0004(s1)

L1e6704:	; 801E6704
801E6704	nop
801E6708	mult   v1, v0
801E670C	lw     a0, $0018(sp)
801E6710	mflo   a3
801E6714	lw     v0, $0008(s1)
801E6718	nop
801E671C	mult   a0, v0
801E6720	mflo   a2
801E6724	nop
801E6728	nop
801E672C	mult   a1, a1
801E6730	mflo   v0
801E6734	nop
801E6738	nop
801E673C	mult   v1, v1
801E6740	mflo   v1
801E6744	nop
801E6748	nop
801E674C	mult   a0, a0
801E6750	addu   s0, s0, a3
801E6754	addu   s0, s0, a2
801E6758	addu   v0, v0, v1
801E675C	mflo   a0
801E6760	jal    system_square_root [$80048af4]
801E6764	addu   a0, v0, a0
801E6768	addiu  v0, v0, $0001
801E676C	sll    s0, s0, $04
801E6770	div    s0, v0
801E6774	bne    v0, zero, L1e6780 [$801e6780]
801E6778	nop
801E677C	break   $01c00

L1e6780:	; 801E6780
801E6780	addiu  at, zero, $ffff (=-$1)
801E6784	bne    v0, at, L1e6798 [$801e6798]
801E6788	lui    at, $8000
801E678C	bne    s0, at, L1e6798 [$801e6798]
801E6790	nop
801E6794	break   $01800

L1e6798:	; 801E6798
801E6798	mflo   s0
801E679C	nop
801E67A0	sll    s0, s0, $08
801E67A4	div    s0, s2
801E67A8	bne    s2, zero, L1e67b4 [$801e67b4]
801E67AC	nop
801E67B0	break   $01c00

L1e67b4:	; 801E67B4
801E67B4	addiu  at, zero, $ffff (=-$1)
801E67B8	bne    s2, at, L1e67cc [$801e67cc]
801E67BC	lui    at, $8000
801E67C0	bne    s0, at, L1e67cc [$801e67cc]
801E67C4	nop
801E67C8	break   $01800

L1e67cc:	; 801E67CC
801E67CC	mflo   s0
801E67D0	nop
801E67D4	sll    s0, s0, $10
801E67D8	sra    v0, s0, $10
801E67DC	lw     ra, $002c(sp)
801E67E0	lw     s2, $0028(sp)
801E67E4	lw     s1, $0024(sp)
801E67E8	lw     s0, $0020(sp)
801E67EC	addiu  sp, sp, $0030
801E67F0	jr     ra 
801E67F4	nop


func1e67f8:	; 801E67F8
801E67F8	addu   v1, zero, zero
801E67FC	lui    a0, $801f
801E6800	lhu    a0, $863c(a0)

loop1e6804:	; 801E6804
801E6804	nop
801E6808	srav   v0, v1, a0
801E680C	andi   v0, v0, $0001
801E6810	bne    v0, zero, L1e6828 [$801e6828]
801E6814	nop
801E6818	addiu  v1, v1, $0001
801E681C	slti   v0, v1, $0008
801E6820	bne    v0, zero, loop1e6804 [$801e6804]
801E6824	nop

L1e6828:	; 801E6828
801E6828	jr     ra 
801E682C	addu   v0, v1, zero


func1e6830:	; 801E6830
801E6830	addiu  sp, sp, $ffe8 (=-$18)
801E6834	sw     s0, $0010(sp)
801E6838	addu   s0, a2, zero
801E683C	andi   v1, a1, $00ff
801E6840	ori    v0, zero, $00ff
801E6844	bne    v1, v0, L1e685c [$801e685c]
801E6848	sw     ra, $0014(sp)
801E684C	jal    func1e67f8 [$801e67f8]
801E6850	nop
801E6854	j      L1e68ec [$801e68ec]
801E6858	addu   a1, v0, zero

L1e685c:	; 801E685C
801E685C	ori    v0, zero, $00fe
801E6860	bne    v1, v0, L1e6878 [$801e6878]
801E6864	ori    v0, zero, $00fd
801E6868	lui    a1, $801f

L1e686c:	; 801E686C
801E686C	lbu    a1, $86b0(a1)
801E6870	j      L1e68f0 [$801e68f0]
801E6874	andi   v0, a1, $00ff

L1e6878:	; 801E6878
801E6878	beq    v1, v0, L1e6888 [$801e6888]
801E687C	ori    v0, zero, $00f9
801E6880	bne    v1, v0, L1e6894 [$801e6894]
801E6884	ori    v0, zero, $00fc

L1e6888:	; 801E6888
801E6888	lbu    a1, $0020(a0)
801E688C	j      L1e68f0 [$801e68f0]
801E6890	andi   v0, a1, $00ff

L1e6894:	; 801E6894
801E6894	bne    v1, v0, L1e68a8 [$801e68a8]
801E6898	ori    v0, zero, $00fa
801E689C	lbu    a1, $0021(a0)
801E68A0	j      L1e68f0 [$801e68f0]
801E68A4	andi   v0, a1, $00ff

L1e68a8:	; 801E68A8
801E68A8	bne    v1, v0, L1e68b8 [$801e68b8]
801E68AC	ori    v0, zero, $00f8
801E68B0	j      L1e68ec [$801e68ec]
801E68B4	ori    a1, zero, $000a

L1e68b8:	; 801E68B8
801E68B8	bne    v1, v0, L1e68d4 [$801e68d4]
801E68BC	ori    v0, zero, $00f7
801E68C0	lbu    v0, $0020(a0)
801E68C4	nop
801E68C8	sll    v0, v0, $01
801E68CC	j      L1e68ec [$801e68ec]
801E68D0	addiu  a1, v0, $0008

L1e68d4:	; 801E68D4
801E68D4	bne    v1, v0, L1e68f0 [$801e68f0]
801E68D8	andi   v0, a1, $00ff
801E68DC	lbu    v0, $0020(a0)
801E68E0	nop
801E68E4	sll    v0, v0, $01
801E68E8	addiu  a1, v0, $0009

L1e68ec:	; 801E68EC
801E68EC	andi   v0, a1, $00ff

L1e68f0:	; 801E68F0
801E68F0	ori    v1, zero, $0001
801E68F4	sllv   v1, v0, v1
801E68F8	sh     v1, $0000(s0)
801E68FC	lw     ra, $0014(sp)
801E6900	lw     s0, $0010(sp)
801E6904	addiu  sp, sp, $0018
801E6908	jr     ra 
801E690C	nop



////////////////////////////////
// func1e6910
801E6910-801E6970
////////////////////////////////



func1e6974:	; 801E6974
801E6974	addiu  sp, sp, $ff60 (=-$a0)
801E6978	sw     s3, $0084(sp)
801E697C	lbu    s3, $00b0(sp)
801E6980	lbu    t3, $00b4(sp)
801E6984	sw     s4, $0088(sp)
801E6988	lhu    s4, $00bc(sp)
801E698C	sw     s5, $008c(sp)
801E6990	lhu    s5, $00c0(sp)
801E6994	sb     t3, $0040(sp)
801E6998	lbu    t3, $00b8(sp)
801E699C	sw     fp, $0098(sp)
801E69A0	sb     t3, $0048(sp)
801E69A4	lhu    t3, $00c4(sp)
801E69A8	addu   fp, a0, zero
801E69AC	sw     s0, $0078(sp)
801E69B0	sh     t3, $0050(sp)
801E69B4	lhu    t3, $00c8(sp)
801E69B8	addu   s0, a2, zero
801E69BC	sw     s1, $007c(sp)
801E69C0	sh     t3, $0058(sp)
801E69C4	lhu    t3, $00cc(sp)
801E69C8	andi   s1, a3, $0007
801E69CC	sw     s7, $0094(sp)
801E69D0	sh     t3, $0060(sp)
801E69D4	lhu    t3, $00d0(sp)
801E69D8	addu   s7, a3, zero
801E69DC	sh     t3, $0068(sp)
801E69E0	lhu    t3, $00d4(sp)
801E69E4	andi   v1, s1, $00ff
801E69E8	sw     ra, $009c(sp)
801E69EC	sw     s6, $0090(sp)
801E69F0	sw     s2, $0080(sp)
801E69F4	sw     a1, $0038(sp)
801E69F8	bne    v1, zero, L1e6a0c [$801e6a0c]
801E69FC	sh     t3, $0070(sp)
801E6A00	lw     a0, $0070(s0)
801E6A04	j      L1e6a28 [$801e6a28]
801E6A08	nop

L1e6a0c:	; 801E6A0C
801E6A0C	ori    v0, zero, $0001
801E6A10	bne    v1, v0, L1e6a24 [$801e6a24]
801E6A14	nop
801E6A18	lw     a0, $0074(s0)
801E6A1C	j      L1e6a28 [$801e6a28]
801E6A20	nop

L1e6a24:	; 801E6A24
801E6A24	lw     a0, $0078(s0)

L1e6a28:	; 801E6A28
801E6A28	nop
801E6A2C	bne    a0, zero, L1e6a4c [$801e6a4c]
801E6A30	ori    v0, zero, $0001
801E6A34	lw     a0, $0038(sp)
801E6A38	jal    func1df6f0 [$801df6f0]
801E6A3C	nop
801E6A40	addu   a0, v0, zero
801E6A44	beq    a0, zero, L1e6c7c [$801e6c7c]
801E6A48	ori    v0, zero, $0001

L1e6a4c:	; 801E6A4C
801E6A4C	sb     v0, $0000(a0)
801E6A50	lbu    t3, $0048(sp)
801E6A54	addiu  v0, s3, $0003
801E6A58	sb     v0, $0002(a0)
801E6A5C	sb     t3, $0001(a0)
801E6A60	lbu    t3, $0040(sp)
801E6A64	andi   v0, s7, $0020
801E6A68	beq    v0, zero, L1e6ac0 [$801e6ac0]
801E6A6C	sb     t3, $0003(a0)
801E6A70	andi   v1, s1, $00ff
801E6A74	bne    v1, zero, L1e6a90 [$801e6a90]
801E6A78	ori    v0, zero, $0001
801E6A7C	lhu    t2, $0054(s0)
801E6A80	lhu    t1, $0056(s0)
801E6A84	lhu    t0, $0058(s0)
801E6A88	j      L1e6ad0 [$801e6ad0]
801E6A8C	andi   v0, s7, $0040

L1e6a90:	; 801E6A90
801E6A90	bne    v1, v0, L1e6aac [$801e6aac]
801E6A94	andi   v0, s7, $0040
801E6A98	lhu    t2, $005c(s0)
801E6A9C	lhu    t1, $0060(s0)
801E6AA0	lhu    t0, $0064(s0)
801E6AA4	j      L1e6ad0 [$801e6ad0]
801E6AA8	nop

L1e6aac:	; 801E6AAC
801E6AAC	lhu    t2, $004c(s0)
801E6AB0	lhu    t1, $004e(s0)
801E6AB4	lhu    t0, $0050(s0)
801E6AB8	j      L1e6ad0 [$801e6ad0]
801E6ABC	nop

L1e6ac0:	; 801E6AC0
801E6AC0	addu   t2, zero, zero
801E6AC4	addu   t1, zero, zero
801E6AC8	addu   t0, zero, zero
801E6ACC	andi   v0, s7, $0040

L1e6ad0:	; 801E6AD0
801E6AD0	beq    v0, zero, L1e6b24 [$801e6b24]
801E6AD4	andi   v1, s1, $00ff
801E6AD8	bne    v1, zero, L1e6af4 [$801e6af4]
801E6ADC	ori    v0, zero, $0001
801E6AE0	lhu    a1, $0054(s0)
801E6AE4	lhu    a2, $0056(s0)
801E6AE8	lhu    a3, $0058(s0)
801E6AEC	j      L1e6b34 [$801e6b34]
801E6AF0	addu   v0, s4, t2

L1e6af4:	; 801E6AF4
801E6AF4	bne    v1, v0, L1e6b10 [$801e6b10]
801E6AF8	addu   v0, s4, t2
801E6AFC	lhu    a1, $005c(s0)
801E6B00	lhu    a2, $0060(s0)
801E6B04	lhu    a3, $0064(s0)
801E6B08	j      L1e6b34 [$801e6b34]
801E6B0C	nop

L1e6b10:	; 801E6B10
801E6B10	lhu    a1, $004c(s0)
801E6B14	lhu    a2, $004e(s0)
801E6B18	lhu    a3, $0050(s0)
801E6B1C	j      L1e6b34 [$801e6b34]
801E6B20	nop

L1e6b24:	; 801E6B24
801E6B24	addu   a1, zero, zero
801E6B28	addu   a2, zero, zero
801E6B2C	addu   a3, zero, zero
801E6B30	addu   v0, s4, t2

L1e6b34:	; 801E6B34
801E6B34	sh     v0, $0004(a0)
801E6B38	addu   v0, s5, t1
801E6B3C	sh     v0, $0006(a0)
801E6B40	lhu    t3, $0050(sp)
801E6B44	nop
801E6B48	addu   v0, t3, t0
801E6B4C	bne    s3, zero, L1e6b90 [$801e6b90]
801E6B50	sh     v0, $0008(a0)
801E6B54	lhu    t3, $0058(sp)
801E6B58	lhu    v1, $0004(a0)
801E6B5C	addu   v0, t3, a1
801E6B60	subu   v0, v0, v1
801E6B64	sh     v0, $000a(a0)
801E6B68	lhu    t3, $0060(sp)
801E6B6C	lhu    v1, $0006(a0)
801E6B70	addu   v0, t3, a2
801E6B74	subu   v0, v0, v1
801E6B78	sh     v0, $000c(a0)
801E6B7C	lhu    t3, $0068(sp)
801E6B80	lhu    v1, $0008(a0)
801E6B84	addu   v0, t3, a3
801E6B88	j      L1e6bbc [$801e6bbc]
801E6B8C	subu   v0, v0, v1

L1e6b90:	; 801E6B90
801E6B90	lhu    t3, $0058(sp)
801E6B94	nop
801E6B98	addu   v0, t3, a1
801E6B9C	sh     v0, $000a(a0)
801E6BA0	lhu    t3, $0060(sp)
801E6BA4	nop
801E6BA8	addu   v0, t3, a2
801E6BAC	sh     v0, $000c(a0)
801E6BB0	lhu    t3, $0068(sp)
801E6BB4	nop
801E6BB8	addu   v0, t3, a3

L1e6bbc:	; 801E6BBC
801E6BBC	sh     v0, $000e(a0)
801E6BC0	sh     zero, $0010(a0)
801E6BC4	lhu    t3, $0070(sp)
801E6BC8	andi   a3, s1, $00ff
801E6BCC	bne    a3, zero, L1e6c0c [$801e6c0c]
801E6BD0	sh     t3, $0012(a0)
801E6BD4	sltiu  v0, s3, $0002
801E6BD8	beq    v0, zero, L1e6c04 [$801e6c04]
801E6BDC	nop
801E6BE0	lhu    v0, $0004(a0)
801E6BE4	nop
801E6BE8	sh     v0, $0054(s0)
801E6BEC	lhu    v0, $0006(a0)
801E6BF0	nop
801E6BF4	sh     v0, $0056(s0)
801E6BF8	lhu    v0, $0008(a0)
801E6BFC	nop
801E6C00	sh     v0, $0058(s0)

L1e6c04:	; 801E6C04
801E6C04	j      L1e6c7c [$801e6c7c]
801E6C08	sw     a0, $0070(s0)

L1e6c0c:	; 801E6C0C
801E6C0C	ori    v0, zero, $0001
801E6C10	bne    a3, v0, L1e6c4c [$801e6c4c]
801E6C14	sltiu  v0, s3, $0002
801E6C18	beq    v0, zero, L1e6c44 [$801e6c44]
801E6C1C	nop
801E6C20	lh     v0, $0004(a0)
801E6C24	nop
801E6C28	sw     v0, $005c(s0)
801E6C2C	lh     v0, $0006(a0)
801E6C30	nop
801E6C34	sw     v0, $0060(s0)
801E6C38	lh     v0, $0008(a0)
801E6C3C	nop
801E6C40	sw     v0, $0064(s0)

L1e6c44:	; 801E6C44
801E6C44	j      L1e6c7c [$801e6c7c]
801E6C48	sw     a0, $0074(s0)

L1e6c4c:	; 801E6C4C
801E6C4C	beq    v0, zero, L1e6c78 [$801e6c78]
801E6C50	nop
801E6C54	lhu    v0, $0004(a0)
801E6C58	nop
801E6C5C	sh     v0, $004c(s0)
801E6C60	lhu    v0, $0006(a0)
801E6C64	nop
801E6C68	sh     v0, $004e(s0)
801E6C6C	lhu    v0, $0008(a0)
801E6C70	nop
801E6C74	sh     v0, $0050(s0)

L1e6c78:	; 801E6C78
801E6C78	sw     a0, $0078(s0)

L1e6c7c:	; 801E6C7C
801E6C7C	andi   v0, s7, $0080
801E6C80	beq    v0, zero, L1e6d60 [$801e6d60]
801E6C84	ori    s2, zero, $0001
801E6C88	lw     s1, $0004(fp)
801E6C8C	nop
801E6C90	lhu    v0, $000a(s1)
801E6C94	nop
801E6C98	slt    v0, s2, v0
801E6C9C	beq    v0, zero, L1e6d60 [$801e6d60]
801E6CA0	sll    v0, s4, $10
801E6CA4	sra    s6, v0, $10
801E6CA8	sll    v0, s5, $10
801E6CAC	lhu    t3, $0050(sp)
801E6CB0	sra    s5, v0, $10
801E6CB4	sll    v0, t3, $10
801E6CB8	sra    s4, v0, $10
801E6CBC	addiu  s1, s1, $007c

loop1e6cc0:	; 801E6CC0
801E6CC0	lw     v0, $0000(s1)
801E6CC4	nop
801E6CC8	bne    v0, s0, L1e6d44 [$801e6d44]
801E6CCC	addiu  s2, s2, $0001
801E6CD0	lbu    t3, $0040(sp)
801E6CD4	lw     a1, $0038(sp)
801E6CD8	addu   a0, fp, zero
801E6CDC	sw     t3, $0014(sp)
801E6CE0	lbu    t3, $0048(sp)
801E6CE4	addu   a2, s1, zero
801E6CE8	sw     t3, $0018(sp)
801E6CEC	lhu    t3, $0058(sp)
801E6CF0	andi   a3, s7, $00ff
801E6CF4	sw     s3, $0010(sp)
801E6CF8	sw     s6, $001c(sp)
801E6CFC	sw     s5, $0020(sp)
801E6D00	sw     s4, $0024(sp)
801E6D04	sll    v0, t3, $10
801E6D08	lhu    t3, $0060(sp)
801E6D0C	sra    v0, v0, $10
801E6D10	sw     v0, $0028(sp)
801E6D14	sll    v0, t3, $10
801E6D18	lhu    t3, $0068(sp)
801E6D1C	sra    v0, v0, $10
801E6D20	sw     v0, $002c(sp)
801E6D24	sll    v0, t3, $10
801E6D28	lhu    t3, $0070(sp)

loop1e6d2c:	; 801E6D2C
801E6D2C	sra    v0, v0, $10
801E6D30	sw     v0, $0030(sp)
801E6D34	sll    v0, t3, $10
801E6D38	sra    v0, v0, $10
801E6D3C	jal    func1e6974 [$801e6974]
801E6D40	sw     v0, $0034(sp)

L1e6d44:	; 801E6D44
801E6D44	lw     v0, $0004(fp)
801E6D48	nop
801E6D4C	lhu    v0, $000a(v0)
801E6D50	nop
801E6D54	slt    v0, s2, v0
801E6D58	bne    v0, zero, loop1e6cc0 [$801e6cc0]
801E6D5C	addiu  s1, s1, $007c

L1e6d60:	; 801E6D60
801E6D60	lw     ra, $009c(sp)
801E6D64	lw     fp, $0098(sp)
801E6D68	lw     s7, $0094(sp)
801E6D6C	lw     s6, $0090(sp)
801E6D70	lw     s5, $008c(sp)
801E6D74	lw     s4, $0088(sp)
801E6D78	lw     s3, $0084(sp)
801E6D7C	lw     s2, $0080(sp)
801E6D80	lw     s1, $007c(sp)
801E6D84	lw     s0, $0078(sp)
801E6D88	addiu  sp, sp, $00a0
801E6D8C	jr     ra 
801E6D90	nop


func1e6d94:	; 801E6D94
801E6D94	addiu  sp, sp, $ffd8 (=-$28)
801E6D98	sw     s2, $0018(sp)
801E6D9C	sw     s4, $0020(sp)
801E6DA0	addu   s4, a1, zero
801E6DA4	sw     s3, $001c(sp)
801E6DA8	addu   s3, a2, zero
801E6DAC	andi   v0, s3, $0001
801E6DB0	sw     ra, $0024(sp)
801E6DB4	sw     s1, $0014(sp)
801E6DB8	sw     s0, $0010(sp)
801E6DBC	sb     v0, $0007(s4)
801E6DC0	andi   v0, s3, $0080
801E6DC4	beq    v0, zero, L1e6e24 [$801e6e24]
801E6DC8	addu   s2, a0, zero
801E6DCC	lw     s0, $0004(s2)
801E6DD0	nop
801E6DD4	lhu    v0, $000a(s0)
801E6DD8	ori    s1, zero, $0001
801E6DDC	slt    v0, s1, v0
801E6DE0	beq    v0, zero, L1e6e24 [$801e6e24]
801E6DE4	addiu  s0, s0, $007c

loop1e6de8:	; 801E6DE8
801E6DE8	lw     v0, $0000(s0)
801E6DEC	nop
801E6DF0	bne    v0, s4, L1e6e08 [$801e6e08]
801E6DF4	addiu  s1, s1, $0001
801E6DF8	addu   a0, s2, zero
801E6DFC	addu   a1, s0, zero
801E6E00	jal    func1e6d94 [$801e6d94]
801E6E04	addu   a2, s3, zero

L1e6e08:	; 801E6E08
801E6E08	lw     v0, $0004(s2)
801E6E0C	nop
801E6E10	lhu    v0, $000a(v0)
801E6E14	nop
801E6E18	slt    v0, s1, v0
801E6E1C	bne    v0, zero, loop1e6de8 [$801e6de8]

L1e6e20:	; 801E6E20
801E6E20	addiu  s0, s0, $007c

L1e6e24:	; 801E6E24
801E6E24	lw     ra, $0024(sp)
801E6E28	lw     s4, $0020(sp)
801E6E2C	lw     s3, $001c(sp)
801E6E30	lw     s2, $0018(sp)
801E6E34	lw     s1, $0014(sp)
801E6E38	lw     s0, $0010(sp)
801E6E3C	addiu  sp, sp, $0028
801E6E40	jr     ra 
801E6E44	nop

801E6E48	addiu  sp, sp, $ffd0 (=-$30)
801E6E4C	addu   v0, a0, zero
801E6E50	sw     s2, $0018(sp)
801E6E54	lw     s2, $0040(sp)
801E6E58	addu   a0, a1, zero
801E6E5C	sw     s5, $0024(sp)
801E6E60	lw     s5, $0044(sp)
801E6E64	addu   a1, v0, zero
801E6E68	sw     s0, $0010(sp)
801E6E6C	addu   s0, a3, zero
801E6E70	sw     s3, $001c(sp)
801E6E74	lw     s3, $0048(sp)
801E6E78	ori    a3, zero, $0018
801E6E7C	sw     ra, $0028(sp)
801E6E80	sw     s4, $0020(sp)
801E6E84	jal    func23e0c [$80023e0c]
801E6E88	sw     s1, $0014(sp)
801E6E8C	addu   s4, v0, zero
801E6E90	addiu  s1, s4, $0038
801E6E94	addu   a0, s1, zero
801E6E98	sll    s0, s0, $10
801E6E9C	sra    s0, s0, $10
801E6EA0	jal    func21e40 [$80021e40]
801E6EA4	addu   a1, s0, zero
801E6EA8	addu   a0, s1, zero
801E6EAC	jal    func22218 [$80022218]
801E6EB0	addu   a1, s0, zero
801E6EB4	addu   a0, s1, zero
801E6EB8	sll    s2, s2, $10
801E6EBC	jal    func21e60 [$80021e60]
801E6EC0	sra    a1, s2, $10
801E6EC4	lh     v0, $00be(s4)
801E6EC8	nop
801E6ECC	addu   s0, s4, v0
801E6ED0	sw     s3, $0008(s0)
801E6ED4	lbu    v0, $0005(s5)
801E6ED8	nop
801E6EDC	sh     v0, $000c(s0)
801E6EE0	lbu    v0, $0013(s5)
801E6EE4	nop
801E6EE8	beq    v0, zero, L1e6f3c [$801e6f3c]
801E6EEC	nop
801E6EF0	jal    func1cc08 [$8001cc08]
801E6EF4	addu   a0, s4, zero
801E6EF8	addu   a0, s4, zero
801E6EFC	lui    a1, $801e
801E6F00	addiu  a1, a1, $6f64
801E6F04	jal    func1cbf8 [$8001cbf8]
801E6F08	sw     v0, $0004(s0)
801E6F0C	lhu    v0, $0006(s5)
801E6F10	nop
801E6F14	sh     v0, $0010(s0)
801E6F18	lhu    v0, $0008(s5)
801E6F1C	nop
801E6F20	sh     v0, $0012(s0)
801E6F24	lhu    v0, $000a(s5)
801E6F28	nop
801E6F2C	sh     v0, $0014(s0)
801E6F30	lbu    v0, $000c(s5)
801E6F34	nop
801E6F38	sh     v0, $000e(s0)

L1e6f3c:	; 801E6F3C
801E6F3C	lw     ra, $0028(sp)
801E6F40	lw     s5, $0024(sp)
801E6F44	lw     s4, $0020(sp)
801E6F48	lw     s3, $001c(sp)
801E6F4C	lw     s2, $0018(sp)
801E6F50	lw     s1, $0014(sp)

L1e6f54:	; 801E6F54
801E6F54	lw     s0, $0010(sp)
801E6F58	addiu  sp, sp, $0030
801E6F5C	jr     ra 
801E6F60	nop

801E6F64	addiu  sp, sp, $ffd0 (=-$30)
801E6F68	sw     s2, $0028(sp)
801E6F6C	addu   s2, a0, zero
801E6F70	sw     ra, $002c(sp)
801E6F74	sw     s1, $0024(sp)
801E6F78	sw     s0, $0020(sp)
801E6F7C	lh     v0, $00be(s2)
801E6F80	nop
801E6F84	addu   s0, s2, v0
801E6F88	lh     v1, $000c(s0)
801E6F8C	nop
801E6F90	beq    v1, zero, L1e6fc8 [$801e6fc8]
801E6F94	lui    s1, $1f80
801E6F98	sll    a1, v1, $05
801E6F9C	subu   a1, a1, v1
801E6FA0	lw     v0, $0008(s0)
801E6FA4	sll    a1, a1, $02
801E6FA8	lw     v0, $0004(v0)

L1e6fac:	; 801E6FAC
801E6FAC	lui    a2, $1f80
801E6FB0	addiu  a0, v0, $000c
801E6FB4	addu   a1, a1, v0
801E6FB8	jal    func491c4 [$800491c4]
801E6FBC	addiu  a1, a1, $002c
801E6FC0	j      L1e6fdc [$801e6fdc]
801E6FC4	nop

L1e6fc8:	; 801E6FC8
801E6FC8	lw     v0, $0008(s0)
801E6FCC	nop
801E6FD0	lw     v0, $0004(v0)
801E6FD4	nop
801E6FD8	addiu  s1, v0, $000c

L1e6fdc:	; 801E6FDC
801E6FDC	jal    func49da4 [$80049da4]
801E6FE0	addu   a0, s1, zero
801E6FE4	jal    func49e34 [$80049e34]
801E6FE8	addu   a0, s1, zero
801E6FEC	addiu  v0, s0, $0010
801E6FF0	lwc2   zero, $0000(v0)
801E6FF4	lwc2   at, $0004(v0)
801E6FF8	nop
801E6FFC	nop
801E7000	gte_func18t0,r11r12
801E7004	addiu  v0, sp, $0010
801E7008	swc2   t9, $0000(v0)

L1e700c:	; 801E700C
801E700C	swc2   k0, $0004(v0)
801E7010	swc2   k1, $0008(v0)
801E7014	lh     v0, $000e(s0)
801E7018	nop
801E701C	beq    v0, zero, L1e7038 [$801e7038]
801E7020	nop
801E7024	lw     v0, $0008(s0)
801E7028	nop
801E702C	lh     v0, $0060(v0)
801E7030	nop
801E7034	sw     v0, $0014(sp)

L1e7038:	; 801E7038
801E7038	lw     v0, $0010(sp)
801E703C	nop
801E7040	sll    v0, v0, $10
801E7044	sw     v0, $0038(s2)
801E7048	lw     v0, $0014(sp)
801E704C	nop
801E7050	sll    v0, v0, $10
801E7054	sw     v0, $003c(s2)
801E7058	lw     v0, $0018(sp)
801E705C	nop
801E7060	sll    v0, v0, $10
801E7064	sw     v0, $0040(s2)
801E7068	lw     v0, $0004(s0)
801E706C	nop
801E7070	jalr   v0 ra
801E7074	addu   a0, s2, zero
801E7078	lw     ra, $002c(sp)
801E707C	lw     s2, $0028(sp)
801E7080	lw     s1, $0024(sp)
801E7084	lw     s0, $0020(sp)
801E7088	addiu  sp, sp, $0030
801E708C	jr     ra 
801E7090	nop


func1e7094:	; 801E7094
801E7094	addiu  sp, sp, $ffc0 (=-$40)
801E7098	sw     s6, $0030(sp)
801E709C	addu   s6, a0, zero
801E70A0	sw     s0, $0018(sp)
801E70A4	addu   s0, a1, zero
801E70A8	sw     s7, $0034(sp)
801E70AC	addu   s7, a2, zero
801E70B0	addu   t2, a3, zero
801E70B4	lw     a0, $0050(sp)
801E70B8	lw     a1, $0054(sp)
801E70BC	andi   v1, a2, $0007
801E70C0	sw     ra, $0038(sp)
801E70C4	sw     s5, $002c(sp)
801E70C8	sw     s4, $0028(sp)
801E70CC	sw     s3, $0024(sp)
801E70D0	sw     s2, $0020(sp)
801E70D4	sw     s1, $001c(sp)

L1e70d8:	; 801E70D8
801E70D8	addu   t0, a0, zero
801E70DC	bne    v1, zero, L1e7128 [$801e7128]

L1e70e0:	; 801E70E0
801E70E0	addu   t1, a1, zero
801E70E4	andi   v0, a2, $0020
801E70E8	beq    v0, zero, L1e7118 [$801e7118]
801E70EC	nop
801E70F0	lhu    v0, $0054(s0)
801E70F4	lhu    v1, $0058(s0)
801E70F8	addu   v0, a3, v0
801E70FC	sh     v0, $0054(s0)
801E7100	lhu    v0, $0056(s0)
801E7104	addu   v1, a1, v1
801E7108	sh     v1, $0058(s0)

L1e710c:	; 801E710C
801E710C	addu   v0, a0, v0
801E7110	j      L1e71d8 [$801e71d8]
801E7114	sh     v0, $0056(s0)

L1e7118:	; 801E7118
801E7118	sh     t2, $0054(s0)
801E711C	sh     t0, $0056(s0)
801E7120	j      L1e71d8 [$801e71d8]
801E7124	sh     t1, $0058(s0)

L1e7128:	; 801E7128
801E7128	ori    v0, zero, $0001
801E712C	bne    v1, v0, L1e719c [$801e719c]
801E7130	andi   v0, a2, $0020
801E7134	beq    v0, zero, L1e7178 [$801e7178]
801E7138	sll    v0, a3, $10
801E713C	lw     v1, $005c(s0)
801E7140	sra    v0, v0, $10
801E7144	addu   v0, v0, v1
801E7148	sw     v0, $005c(s0)
801E714C	sll    v0, a0, $10
801E7150	lw     v1, $0060(s0)
801E7154	sra    v0, v0, $10
801E7158	addu   v0, v0, v1
801E715C	sw     v0, $0060(s0)
801E7160	sll    v0, a1, $10
801E7164	lw     v1, $0064(s0)
801E7168	sra    v0, v0, $10
801E716C	addu   v0, v0, v1
801E7170	j      L1e71d8 [$801e71d8]
801E7174	sw     v0, $0064(s0)

L1e7178:	; 801E7178
801E7178	sra    v0, v0, $10
801E717C	sw     v0, $005c(s0)
801E7180	sll    v0, a0, $10
801E7184	sra    v0, v0, $10
801E7188	sw     v0, $0060(s0)
801E718C	sll    v0, a1, $10
801E7190	sra    v0, v0, $10
801E7194	j      L1e71d8 [$801e71d8]
801E7198	sw     v0, $0064(s0)

L1e719c:	; 801E719C
801E719C	beq    v0, zero, L1e71cc [$801e71cc]
801E71A0	nop
801E71A4	lhu    v0, $004c(s0)
801E71A8	lhu    v1, $0050(s0)
801E71AC	addu   v0, a3, v0
801E71B0	sh     v0, $004c(s0)
801E71B4	lhu    v0, $004e(s0)
801E71B8	addu   v1, a1, v1
801E71BC	sh     v1, $0050(s0)
801E71C0	addu   v0, a0, v0
801E71C4	j      L1e71d8 [$801e71d8]
801E71C8	sh     v0, $004e(s0)

L1e71cc:	; 801E71CC
801E71CC	sh     t2, $004c(s0)
801E71D0	sh     t0, $004e(s0)

L1e71d4:	; 801E71D4
801E71D4	sh     t1, $0050(s0)

L1e71d8:	; 801E71D8
801E71D8	ori    v0, zero, $0001
801E71DC	sb     v0, $0004(s0)
801E71E0	sb     v0, $0005(s0)

L1e71e4:	; 801E71E4
801E71E4	andi   v0, s7, $0080
801E71E8	beq    v0, zero, L1e7268 [$801e7268]
801E71EC	ori    s2, zero, $0001
801E71F0	lw     s1, $0004(s6)
801E71F4	nop
801E71F8	lhu    v0, $000a(s1)
801E71FC	nop
801E7200	slt    v0, s2, v0
801E7204	beq    v0, zero, L1e7268 [$801e7268]
801E7208	sll    s5, t2, $10

L1e720c:	; 801E720C
801E720C	sll    v0, t0, $10
801E7210	sra    s4, v0, $10
801E7214	sll    v0, t1, $10
801E7218	sra    s3, v0, $10

L1e721c:	; 801E721C
801E721C	addiu  s1, s1, $007c

loop1e7220:	; 801E7220
801E7220	lw     v0, $0000(s1)
801E7224	nop
801E7228	bne    v0, s0, L1e724c [$801e724c]
801E722C	addiu  s2, s2, $0001
801E7230	addu   a0, s6, zero

L1e7234:	; 801E7234
801E7234	addu   a1, s1, zero
801E7238	andi   a2, s7, $00ff
801E723C	sra    a3, s5, $10
801E7240	sw     s4, $0010(sp)
801E7244	jal    func1e7094 [$801e7094]
801E7248	sw     s3, $0014(sp)

L1e724c:	; 801E724C
801E724C	lw     v0, $0004(s6)
801E7250	nop

L1e7254:	; 801E7254
801E7254	lhu    v0, $000a(v0)
801E7258	nop
801E725C	slt    v0, s2, v0
801E7260	bne    v0, zero, loop1e7220 [$801e7220]
801E7264	addiu  s1, s1, $007c

L1e7268:	; 801E7268
801E7268	lw     ra, $0038(sp)
801E726C	lw     s7, $0034(sp)
801E7270	lw     s6, $0030(sp)
801E7274	lw     s5, $002c(sp)
801E7278	lw     s4, $0028(sp)
801E727C	lw     s3, $0024(sp)
801E7280	lw     s2, $0020(sp)
801E7284	lw     s1, $001c(sp)
801E7288	lw     s0, $0018(sp)
801E728C	addiu  sp, sp, $0040

L1e7290:	; 801E7290
801E7290	jr     ra 
801E7294	nop


func1e7298:	; 801E7298
801E7298	lhu    v1, $0060(a0)
801E729C	addiu  sp, sp, $ffe8 (=-$18)
801E72A0	sh     v1, $0012(sp)
801E72A4	lbu    v0, $0036(a0)
801E72A8	nop
801E72AC	bne    v0, zero, L1e72c0 [$801e72c0]
801E72B0	sll    v0, v1, $10
801E72B4	lw     v1, $0004(a0)
801E72B8	sra    v0, v0, $10
801E72BC	sw     v0, $0060(v1)

L1e72c0:	; 801E72C0
801E72C0	addiu  sp, sp, $0018
801E72C4	jr     ra 
801E72C8	nop


func1e72cc:	; 801E72CC
801E72CC	addiu  sp, sp, $ffc8 (=-$38)
801E72D0	sll    a2, a2, $02
801E72D4	sw     ra, $0030(sp)
801E72D8	lui    at, $801f
801E72DC	addu   at, at, a2
801E72E0	lw     v0, $8670(at)
801E72E4	nop
801E72E8	beq    v0, zero, L1e7368 [$801e7368]
801E72EC	addu   t0, a0, zero
801E72F0	beq    a3, zero, L1e7320 [$801e7320]
801E72F4	sll    a1, a3, $05
801E72F8	lw     a0, $0004(v0)
801E72FC	subu   a1, a1, a3
801E7300	sll    a1, a1, $02
801E7304	addu   a2, t0, zero
801E7308	addu   a1, a1, a0
801E730C	addiu  a0, a0, $000c

L1e7310:	; 801E7310
801E7310	jal    func491c4 [$800491c4]
801E7314	addiu  a1, a1, $002c
801E7318	j      L1e7368 [$801e7368]
801E731C	nop

L1e7320:	; 801E7320
801E7320	lw     v0, $0004(v0)
801E7324	nop
801E7328	lw     v1, $000c(v0)
801E732C	lw     a0, $0010(v0)
801E7330	lw     a1, $0014(v0)
801E7334	lw     a2, $0018(v0)
801E7338	sw     v1, $0000(t0)
801E733C	sw     a0, $0004(t0)
801E7340	sw     a1, $0008(t0)

L1e7344:	; 801E7344
801E7344	sw     a2, $000c(t0)
801E7348	lw     v1, $001c(v0)
801E734C	lw     a0, $0020(v0)
801E7350	lw     a1, $0024(v0)
801E7354	lw     a2, $0028(v0)
801E7358	sw     v1, $0010(t0)
801E735C	sw     a0, $0014(t0)
801E7360	sw     a1, $0018(t0)
801E7364	sw     a2, $001c(t0)

L1e7368:	; 801E7368
801E7368	lw     ra, $0030(sp)
801E736C	addiu  sp, sp, $0038
801E7370	jr     ra 

L1e7374:	; 801E7374
801E7374	nop


func1e7378:	; 801E7378
801E7378	andi   a0, a0, $0001

L1e737c:	; 801E737C
801E737C	lui    at, $801f
801E7380	sw     a0, $85cc(at)
801E7384	jr     ra 
801E7388	nop


func1e738c:	; 801E738C
801E738C	addiu  sp, sp, $ffe8 (=-$18)
801E7390	addu   a1, a0, zero
801E7394	lui    a0, $801f
801E7398	addiu  a0, a0, $86a8 (=-$7958)
801E739C	sw     ra, $0010(sp)
801E73A0	lui    at, $801f
801E73A4	sw     zero, $8640(at)
801E73A8	lui    at, $801f
801E73AC	sh     zero, $869c(at)
801E73B0	jal    func1df5f4 [$801df5f4]
801E73B4	nop
801E73B8	lui    a0, $801f
801E73BC	addiu  a0, a0, $86a0 (=-$7960)
801E73C0	jal    func1e0064 [$801e0064]
801E73C4	ori    a1, zero, $0010
801E73C8	ori    v1, zero, $0009
801E73CC	lui    v0, $801f
801E73D0	addiu  v0, v0, $8694 (=-$796c)

loop1e73d4:	; 801E73D4
801E73D4	sw     zero, $0000(v0)
801E73D8	addiu  v1, v1, $ffff (=-$1)
801E73DC	bgez   v1, loop1e73d4 [$801e73d4]
801E73E0	addiu  v0, v0, $fffc (=-$4)
801E73E4	ori    v0, zero, $0038

loop1e73e8:	; 801E73E8
801E73E8	lui    at, $801f
801E73EC	addu   at, at, v0
801E73F0	sw     zero, $85f4(at)
801E73F4	addiu  v0, v0, $fff8 (=-$8)
801E73F8	bgez   v0, loop1e73e8 [$801e73e8]
801E73FC	nop
801E7400	ori    v0, zero, $0014

loop1e7404:	; 801E7404
801E7404	lui    at, $801f
801E7408	addu   at, at, v0
801E740C	sh     zero, $864e(at)
801E7410	addiu  v0, v0, $ffec (=-$14)
801E7414	bgez   v0, loop1e7404 [$801e7404]
801E7418	nop
801E741C	lw     ra, $0010(sp)
801E7420	addiu  sp, sp, $0018
801E7424	jr     ra 
801E7428	nop



///////////////////////////////////////////
// func1e742c
801E742C-801E7D10
///////////////////////////////////////////



func1e7d14:	; 801E7D14
801E7D14	addiu  sp, sp, $ffb8 (=-$48)
801E7D18	lui    v0, $801f
801E7D1C	lw     v0, $8640(v0)
801E7D20	lw     v1, $0058(sp)
801E7D24	sw     s4, $0038(sp)
801E7D28	addu   s4, a0, zero
801E7D2C	sw     s6, $0040(sp)
801E7D30	addu   s6, a1, zero
801E7D34	sw     s5, $003c(sp)
801E7D38	addu   s5, a2, zero
801E7D3C	sw     s3, $0034(sp)
801E7D40	addu   s3, a3, zero
801E7D44	sw     s2, $0030(sp)
801E7D48	sw     ra, $0044(sp)
801E7D4C	sw     s1, $002c(sp)
801E7D50	sw     s0, $0028(sp)
801E7D54	addiu  v0, v0, $0001
801E7D58	addu   v0, v0, v1
801E7D5C	lui    at, $801f
801E7D60	sw     v0, $8640(at)
801E7D64	slti   v0, v0, $0007
801E7D68	bne    v0, zero, L1e7d7c [$801e7d7c]
801E7D6C	addu   s2, zero, zero
801E7D70	ori    v0, zero, $0006
801E7D74	lui    at, $801f
801E7D78	sw     v0, $8640(at)

L1e7d7c:	; 801E7D7C
801E7D7C	lui    v1, $801f
801E7D80	lw     v1, $8640(v1)
801E7D84	nop
801E7D88	slti   v0, v1, $0002
801E7D8C	bne    v0, zero, L1e7db4 [$801e7db4]
801E7D90	sll    v0, s2, $03

loop1e7d94:	; 801E7D94
801E7D94	addiu  v0, v1, $fffe (=-$2)
801E7D98	lui    at, $801f
801E7D9C	sw     v0, $8640(at)
801E7DA0	addu   v1, v0, zero
801E7DA4	slti   v0, v1, $0002
801E7DA8	beq    v0, zero, loop1e7d94 [$801e7d94]
801E7DAC	addiu  s2, s2, $0001
801E7DB0	sll    v0, s2, $03

L1e7db4:	; 801E7DB4
801E7DB4	subu   v0, v0, s2
801E7DB8	lui    v1, $801f
801E7DBC	lhu    v1, $869c(v1)
801E7DC0	sll    v0, v0, $03
801E7DC4	addu   v1, v1, v0
801E7DC8	sll    a0, v1, $10
801E7DCC	lui    at, $801f
801E7DD0	sh     v1, $869c(at)
801E7DD4	jal    func3f774 [$8003f774]
801E7DD8	sra    a0, a0, $10
801E7DDC	lui    v1, $51eb
801E7DE0	ori    v1, v1, $851f
801E7DE4	addiu  v0, v0, $1000
801E7DE8	mult   v0, v1
801E7DEC	addu   s1, zero, zero
801E7DF0	lui    s0, $801f
801E7DF4	addiu  s0, s0, $8670 (=-$7990)
801E7DF8	sra    v0, v0, $1f
801E7DFC	mfhi   v1
801E7E00	sra    v1, v1, $08
801E7E04	subu   v1, v1, v0
801E7E08	addiu  v1, v1, $0004
801E7E0C	lui    at, $801f
801E7E10	sh     v1, $8698(at)

loop1e7e14:	; 801E7E14
801E7E14	lw     v1, $0000(s0)
801E7E18	nop
801E7E1C	beq    v1, zero, L1e7e88 [$801e7e88]
801E7E20	addiu  s1, s1, $0001
801E7E24	lw     v0, $0004(v1)
801E7E28	nop
801E7E2C	lw     v0, $005c(v0)
801E7E30	nop
801E7E34	sw     v0, $011c(v1)
801E7E38	lw     v1, $0000(s0)
801E7E3C	nop
801E7E40	lw     v0, $0004(v1)
801E7E44	nop
801E7E48	lw     v0, $0060(v0)
801E7E4C	nop
801E7E50	sw     v0, $0120(v1)
801E7E54	lw     v1, $0000(s0)
801E7E58	nop
801E7E5C	lw     v0, $0004(v1)
801E7E60	lui    a1, $801f
801E7E64	addiu  a1, a1, $86a8 (=-$7958)
801E7E68	lw     v0, $0064(v0)
801E7E6C	addu   a2, s2, zero
801E7E70	sw     v0, $0124(v1)
801E7E74	ori    v0, zero, $0001
801E7E78	sw     v0, $0010(sp)
801E7E7C	lw     a0, $0000(s0)
801E7E80	jal    func1e36bc [$801e36bc]
801E7E84	addu   a3, s3, zero

L1e7e88:	; 801E7E88
801E7E88	slti   v0, s1, $000a
801E7E8C	bne    v0, zero, loop1e7e14 [$801e7e14]
801E7E90	addiu  s0, s0, $0004
801E7E94	addu   s1, zero, zero
801E7E98	lui    s0, $801f
801E7E9C	addiu  s0, s0, $8670 (=-$7990)

loop1e7ea0:	; 801E7EA0
801E7EA0	lw     a0, $0000(s0)
801E7EA4	nop
801E7EA8	beq    a0, zero, L1e7ecc [$801e7ecc]
801E7EAC	addiu  s0, s0, $0004
801E7EB0	lbu    v0, $005c(a0)
801E7EB4	nop
801E7EB8	sltiu  v0, v0, $00ff
801E7EBC	beq    v0, zero, L1e7ecc [$801e7ecc]
801E7EC0	nop
801E7EC4	jal    func1e37d0 [$801e37d0]
801E7EC8	nop

L1e7ecc:	; 801E7ECC
801E7ECC	addiu  s1, s1, $0001
801E7ED0	slti   v0, s1, $000a
801E7ED4	bne    v0, zero, loop1e7ea0 [$801e7ea0]
801E7ED8	nop
801E7EDC	lui    s0, $801f

L1e7ee0:	; 801E7EE0
801E7EE0	addiu  s0, s0, $8670 (=-$7990)
801E7EE4	jal    func1e1880 [$801e1880]
801E7EE8	addu   a0, s0, zero
801E7EEC	lui    a0, $801f
801E7EF0	lw     a0, $8644(a0)
801E7EF4	jal    func49e04 [$80049e04]
801E7EF8	addu   s1, zero, zero

loop1e7efc:	; 801E7EFC
801E7EFC	lw     a0, $0000(s0)
801E7F00	nop
801E7F04	beq    a0, zero, L1e7f80 [$801e7f80]
801E7F08	addiu  s1, s1, $0001
801E7F0C	lw     v1, $0004(a0)
801E7F10	lw     v0, $011c(a0)
801E7F14	lw     v1, $005c(v1)
801E7F18	nop
801E7F1C	subu   v0, v0, v1
801E7F20	sw     v0, $0128(a0)
801E7F24	lw     a0, $0000(s0)
801E7F28	nop
801E7F2C	lw     v1, $0004(a0)
801E7F30	lw     v0, $0120(a0)
801E7F34	lw     v1, $0060(v1)
801E7F38	nop
801E7F3C	subu   v0, v0, v1
801E7F40	sw     v0, $012c(a0)
801E7F44	lw     a0, $0000(s0)
801E7F48	addu   a1, s4, zero
801E7F4C	lw     v1, $0004(a0)
801E7F50	lw     v0, $0124(a0)
801E7F54	lw     v1, $0064(v1)
801E7F58	addu   a2, s6, zero
801E7F5C	subu   v0, v0, v1
801E7F60	sw     v0, $0130(a0)
801E7F64	ori    v0, zero, $0001
801E7F68	sw     v0, $0010(sp)
801E7F6C	sw     s5, $0014(sp)
801E7F70	sw     s3, $0018(sp)
801E7F74	lw     a0, $0000(s0)
801E7F78	jal    func1dcec8 [$801dcec8]
801E7F7C	ori    a3, zero, $0001

L1e7f80:	; 801E7F80
801E7F80	slti   v0, s1, $000a
801E7F84	bne    v0, zero, loop1e7efc [$801e7efc]
801E7F88	addiu  s0, s0, $0004
801E7F8C	sw     s3, $0010(sp)
801E7F90	lui    a0, $801f
801E7F94	addiu  a0, a0, $86a0 (=-$7960)
801E7F98	addu   a1, s4, zero
801E7F9C	addu   a2, s2, zero
801E7FA0	jal    func1e0398 [$801e0398]
801E7FA4	addu   a3, s5, zero
801E7FA8	lw     ra, $0044(sp)
801E7FAC	lw     s6, $0040(sp)
801E7FB0	lw     s5, $003c(sp)
801E7FB4	lw     s4, $0038(sp)
801E7FB8	lw     s3, $0034(sp)
801E7FBC	lw     s2, $0030(sp)
801E7FC0	lw     s1, $002c(sp)
801E7FC4	lw     s0, $0028(sp)
801E7FC8	addiu  sp, sp, $0048
801E7FCC	jr     ra 
801E7FD0	nop


func1e7fd4:	; 801E7FD4
801E7FD4	addiu  sp, sp, $ffe8 (=-$18)
801E7FD8	sw     s0, $0010(sp)
801E7FDC	addu   s0, zero, zero
801E7FE0	sw     ra, $0014(sp)

loop1e7fe4:	; 801E7FE4
801E7FE4	jal    func1e8030 [$801e8030]
801E7FE8	addu   a0, s0, zero
801E7FEC	addiu  s0, s0, $0001
801E7FF0	slti   v0, s0, $000a
801E7FF4	bne    v0, zero, loop1e7fe4 [$801e7fe4]
801E7FF8	nop
801E7FFC	lui    a0, $801f
801E8000	addiu  a0, a0, $86a8 (=-$7958)
801E8004	jal    func1df668 [$801df668]
801E8008	nop
801E800C	lui    a0, $801f
801E8010	addiu  a0, a0, $86a0 (=-$7960)
801E8014	jal    func1e00dc [$801e00dc]
801E8018	nop
801E801C	lw     ra, $0014(sp)
801E8020	lw     s0, $0010(sp)
801E8024	addiu  sp, sp, $0018
801E8028	jr     ra 
801E802C	nop


func1e8030:	; 801E8030
801E8030	addiu  sp, sp, $ffb8 (=-$48)
801E8034	sw     s4, $0038(sp)
801E8038	addu   s4, a0, zero
801E803C	lui    v1, $801f
801E8040	addiu  v1, v1, $8670 (=-$7990)
801E8044	sll    v0, s4, $02
801E8048	sw     s1, $002c(sp)
801E804C	addu   s1, v0, v1
801E8050	sw     ra, $0040(sp)
801E8054	sw     s5, $003c(sp)
801E8058	sw     s3, $0034(sp)
801E805C	sw     s2, $0030(sp)
801E8060	sw     s0, $0028(sp)
801E8064	lw     a0, $0000(s1)
801E8068	nop
801E806C	beq    a0, zero, L1e8308 [$801e8308]
801E8070	nop
801E8074	lw     a0, $00a8(a0)
801E8078	nop
801E807C	beq    a0, zero, L1e80a0 [$801e80a0]
801E8080	nop
801E8084	jal    func31f0c [$80031f0c]
801E8088	nop
801E808C	lw     v0, $0000(s1)
801E8090	nop
801E8094	lw     a0, $0000(v0)
801E8098	jal    func1dce18 [$801dce18]
801E809C	ori    a1, zero, $0001

L1e80a0:	; 801E80A0
801E80A0	lw     v1, $0000(s1)
801E80A4	nop
801E80A8	lbu    v0, $0062(v1)
801E80AC	nop
801E80B0	beq    v0, zero, L1e80cc [$801e80cc]
801E80B4	nop
801E80B8	lw     v0, $00b0(v1)
801E80BC	nop
801E80C0	lw     a0, $0008(v0)
801E80C4	jal    func383d4 [$800383d4]
801E80C8	nop

L1e80cc:	; 801E80CC
801E80CC	lw     v0, $0000(s1)
801E80D0	nop
801E80D4	lw     a0, $00ac(v0)
801E80D8	nop
801E80DC	beq    a0, zero, L1e80f0 [$801e80f0]
801E80E0	addiu  v0, s4, $fff8 (=-$8)
801E80E4	jal    func31f0c [$80031f0c]
801E80E8	nop
801E80EC	addiu  v0, s4, $fff8 (=-$8)

L1e80f0:	; 801E80F0
801E80F0	sltiu  v0, v0, $0002
801E80F4	bne    v0, zero, L1e8164 [$801e8164]
801E80F8	nop
801E80FC	lw     v0, $0000(s1)
801E8100	nop
801E8104	lw     a1, $0004(v0)
801E8108	nop
801E810C	beq    a1, zero, L1e81b4 [$801e81b4]
801E8110	nop
801E8114	lui    s0, $801f
801E8118	addiu  s0, s0, $86a8 (=-$7958)
801E811C	jal    func1dfe8c [$801dfe8c]
801E8120	addu   a0, s0, zero
801E8124	lw     v0, $0000(s1)
801E8128	addu   a0, s0, zero
801E812C	lw     a1, $0004(v0)
801E8130	jal    func1dff78 [$801dff78]

L1e8134:	; 801E8134
801E8134	ori    a2, zero, $00ff
801E8138	lw     v0, $0000(s1)
801E813C	nop
801E8140	lw     a0, $0004(v0)
801E8144	jal    func1dcd8c [$801dcd8c]
801E8148	nop
801E814C	lw     v0, $0000(s1)
801E8150	nop
801E8154	sw     zero, $0000(v0)
801E8158	lw     v0, $0000(s1)
801E815C	j      L1e81b4 [$801e81b4]
801E8160	sw     zero, $0004(v0)

L1e8164:	; 801E8164
801E8164	lw     v0, $0000(s1)
801E8168	nop
801E816C	lw     a1, $0004(v0)
801E8170	nop
801E8174	beq    a1, zero, L1e81b4 [$801e81b4]
801E8178	nop
801E817C	lui    s0, $801f
801E8180	addiu  s0, s0, $86a8 (=-$7958)
801E8184	jal    func1dfe8c [$801dfe8c]
801E8188	addu   a0, s0, zero
801E818C	lw     v0, $0000(s1)
801E8190	addu   a0, s0, zero
801E8194	lw     a1, $0004(v0)
801E8198	jal    func1dff78 [$801dff78]
801E819C	ori    a2, zero, $00ff
801E81A0	lw     v0, $0000(s1)
801E81A4	nop
801E81A8	lw     a0, $0004(v0)
801E81AC	jal    func31f0c [$80031f0c]
801E81B0	nop

L1e81b4:	; 801E81B4
801E81B4	lui    v0, $801f
801E81B8	addiu  v0, v0, $8670 (=-$7990)
801E81BC	sll    v1, s4, $02
801E81C0	addu   s0, v1, v0
801E81C4	lw     v1, $0000(s0)
801E81C8	nop
801E81CC	lbu    v0, $010c(v1)
801E81D0	nop
801E81D4	beq    v0, zero, L1e81e8 [$801e81e8]
801E81D8	nop
801E81DC	lw     a0, $0110(v1)
801E81E0	jal    func31f0c [$80031f0c]
801E81E4	nop

L1e81e8:	; 801E81E8
801E81E8	lw     v0, $0000(s0)
801E81EC	nop
801E81F0	lbu    v0, $010e(v0)
801E81F4	nop
801E81F8	beq    v0, zero, L1e8260 [$801e8260]
801E81FC	sll    s2, s4, $02
801E8200	beq    v0, zero, L1e8240 [$801e8240]
801E8204	addu   s1, zero, zero
801E8208	addu   s2, s0, zero
801E820C	addu   s0, zero, zero

loop1e8210:	; 801E8210
801E8210	lw     v0, $0000(s2)
801E8214	nop
801E8218	lw     a0, $0118(v0)
801E821C	jal    func1e165c [$801e165c]
801E8220	addu   a0, s0, a0
801E8224	lw     v0, $0000(s2)
801E8228	addiu  s1, s1, $0001
801E822C	lbu    v0, $010e(v0)
801E8230	nop
801E8234	slt    v0, s1, v0
801E8238	bne    v0, zero, loop1e8210 [$801e8210]
801E823C	addiu  s0, s0, $0030

L1e8240:	; 801E8240
801E8240	sll    v0, s4, $02
801E8244	lui    at, $801f
801E8248	addu   at, at, v0
801E824C	lw     v0, $8670(at)
801E8250	nop
801E8254	lw     a0, $0118(v0)
801E8258	jal    func31f0c [$80031f0c]
801E825C	sll    s2, s4, $02

L1e8260:	; 801E8260
801E8260	lui    at, $801f
801E8264	addu   at, at, s2
801E8268	lw     v0, $8670(at)
801E826C	nop
801E8270	lbu    v0, $010d(v0)
801E8274	lui    v1, $801f
801E8278	addiu  v1, v1, $8670 (=-$7990)
801E827C	beq    v0, zero, L1e82e8 [$801e82e8]
801E8280	nop
801E8284	beq    v0, zero, L1e82c8 [$801e82c8]
801E8288	addu   s1, zero, zero
801E828C	addu   s5, v1, zero
801E8290	addu   s3, zero, zero

loop1e8294:	; 801E8294
801E8294	addu   s0, s2, s5
801E8298	lw     v0, $0000(s0)
801E829C	nop
801E82A0	lw     a0, $0114(v0)
801E82A4	jal    func1e3438 [$801e3438]
801E82A8	addu   a0, s3, a0
801E82AC	lw     v0, $0000(s0)
801E82B0	addiu  s1, s1, $0001
801E82B4	lbu    v0, $010d(v0)
801E82B8	nop
801E82BC	slt    v0, s1, v0
801E82C0	bne    v0, zero, loop1e8294 [$801e8294]
801E82C4	addiu  s3, s3, $0024

L1e82c8:	; 801E82C8
801E82C8	sll    v0, s4, $02
801E82CC	lui    at, $801f
801E82D0	addu   at, at, v0
801E82D4	lw     v0, $8670(at)
801E82D8	nop
801E82DC	lw     a0, $0114(v0)
801E82E0	jal    func31f0c [$80031f0c]
801E82E4	nop

L1e82e8:	; 801E82E8
801E82E8	lui    v0, $801f
801E82EC	addiu  v0, v0, $8670 (=-$7990)
801E82F0	sll    s0, s4, $02
801E82F4	addu   s0, s0, v0
801E82F8	lw     a0, $0000(s0)
801E82FC	jal    func31f0c [$80031f0c]
801E8300	nop
801E8304	sw     zero, $0000(s0)

L1e8308:	; 801E8308
801E8308	lw     ra, $0040(sp)
801E830C	lw     s5, $003c(sp)
801E8310	lw     s4, $0038(sp)
801E8314	lw     s3, $0034(sp)
801E8318	lw     s2, $0030(sp)
801E831C	lw     s1, $002c(sp)
801E8320	lw     s0, $0028(sp)
801E8324	addiu  sp, sp, $0048
801E8328	jr     ra 
801E832C	nop


func1e8330:	; 801E8330
801E8330	addiu  sp, sp, $ffe8 (=-$18)
801E8334	andi   v0, a0, $ffff
801E8338	lui    v1, $801f
801E833C	addiu  v1, v1, $8670 (=-$7990)
801E8340	sll    v0, v0, $02
801E8344	addu   v0, v0, v1
801E8348	sw     ra, $0010(sp)
801E834C	lw     v1, $0000(v0)
801E8350	lui    at, $801f
801E8354	sh     a0, $86b0(at)
801E8358	lui    at, $801f
801E835C	sh     a1, $863c(at)
801E8360	sb     zero, $0035(v1)
801E8364	lw     a0, $0000(v0)
801E8368	nop
801E836C	beq    a0, zero, L1e8384 [$801e8384]
801E8370	addu   a3, a2, zero
801E8374	lui    a2, $801f
801E8378	addiu  a2, a2, $86a8 (=-$7958)
801E837C	jal    func1e35d0 [$801e35d0]
801E8380	addu   a1, a0, zero

L1e8384:	; 801E8384
801E8384	lw     ra, $0010(sp)
801E8388	addiu  sp, sp, $0018
801E838C	jr     ra 
801E8390	nop


func1e8394:	; 801E8394
801E8394	addiu  sp, sp, $ffd8 (=-$28)
801E8398	sw     s2, $0018(sp)
801E839C	andi   s2, a1, $ffff
801E83A0	lui    v1, $801f
801E83A4	addiu  v1, v1, $8670 (=-$7990)
801E83A8	sll    v0, s2, $02
801E83AC	sw     s0, $0010(sp)
801E83B0	addu   s0, v0, v1
801E83B4	sw     ra, $0020(sp)
801E83B8	sw     s3, $001c(sp)
801E83BC	sw     s1, $0014(sp)
801E83C0	lw     v0, $0000(s0)
801E83C4	addu   s3, a0, zero
801E83C8	lui    at, $801f
801E83CC	sh     a1, $86b0(at)
801E83D0	lui    at, $801f
801E83D4	sh     a2, $863c(at)
801E83D8	sb     zero, $0035(v0)
801E83DC	lw     v0, $0000(s0)
801E83E0	nop
801E83E4	beq    v0, zero, L1e8410 [$801e8410]
801E83E8	addu   s1, a3, zero
801E83EC	jal    func1e67f8 [$801e67f8]
801E83F0	nop
801E83F4	beq    s2, v0, L1e8410 [$801e8410]
801E83F8	addu   a1, s3, zero
801E83FC	lw     a0, $0000(s0)
801E8400	lui    a2, $801f
801E8404	addiu  a2, a2, $86a8 (=-$7958)
801E8408	jal    func1e35d0 [$801e35d0]

L1e840c:	; 801E840C
801E840C	addu   a3, s1, zero

L1e8410:	; 801E8410
801E8410	lw     ra, $0020(sp)
801E8414	lw     s3, $001c(sp)
801E8418	lw     s2, $0018(sp)
801E841C	lw     s1, $0014(sp)
801E8420	lw     s0, $0010(sp)
801E8424	addiu  sp, sp, $0028
801E8428	jr     ra 
801E842C	nop

801E8430	sll    a0, a0, $02
801E8434	lui    at, $801f
801E8438	addu   at, at, a0
801E843C	lw     a0, $8670(at)
801E8440	nop
801E8444	beq    a0, zero, L1e8478 [$801e8478]
801E8448	addu   v0, zero, zero
801E844C	lw     v0, $0004(a0)
801E8450	lh     v1, $001c(a0)
801E8454	lh     v0, $004e(v0)
801E8458	nop
801E845C	mult   v1, v0
801E8460	mflo   v0
801E8464	lh     v1, $0024(a0)
801E8468	sra    v0, v0, $0c
801E846C	mult   v1, v0
801E8470	mflo   v0
801E8474	sra    v0, v0, $0c

L1e8478:	; 801E8478
801E8478	jr     ra 
801E847C	nop


func1e8480:	; 801E8480
801E8480	sll    v0, a0, $02
801E8484	lui    at, $801f
801E8488	addu   at, at, v0
801E848C	lw     v1, $8670(at)
801E8490	nop
801E8494	beq    v1, zero, L1e8508 [$801e8508]
801E8498	addu   v0, zero, zero
801E849C	lhu    v0, $004a(v1)
801E84A0	nop
801E84A4	andi   v0, v0, $0008
801E84A8	beq    v0, zero, L1e84c4 [$801e84c4]
801E84AC	nop
801E84B0	lw     v0, $0004(v1)
801E84B4	lh     a1, $0026(v1)
801E84B8	lh     v1, $004c(v0)
801E84BC	j      L1e84d4 [$801e84d4]
801E84C0	sll    v0, a0, $02

L1e84c4:	; 801E84C4
801E84C4	lw     v0, $0004(v1)
801E84C8	lh     a1, $0028(v1)
801E84CC	lh     v1, $0050(v0)
801E84D0	sll    v0, a0, $02

L1e84d4:	; 801E84D4
801E84D4	lui    at, $801f
801E84D8	addu   at, at, v0
801E84DC	lw     v0, $8670(at)
801E84E0	nop
801E84E4	lh     v0, $001c(v0)
801E84E8	nop
801E84EC	mult   v0, v1
801E84F0	mflo   v0

func1e84f4:	; 801E84F4
801E84F4	sra    v0, v0, $0c
801E84F8	nop
801E84FC	mult   a1, v0
801E8500	mflo   v0
801E8504	sra    v0, v0, $0c

L1e8508:	; 801E8508
801E8508	jr     ra 
801E850C	nop



////////////////////////////////
// func1e8510
801E8510-801E858C
////////////////////////////////
