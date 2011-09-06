////////////////////////////////
// func1c788
if( w[GP + 150] != 0 )
{
    [GP + 150] = w(w[GP + 150] - 1);
}
else
{
    if( w[GP + b4] != 1 )
    {
        func34b44;
        if( V0 == 0 )
        {
            func1c5bc;

            return V0;
        }
    }
}
return 0;
////////////////////////////////



////////////////////////////////
// func1f6e4
[GP + a0] = b(A0);
A0 = A0 << 10;
if( A0 != 0 )
{
    [GP + a2] = h(A1);
    [GP + a4] = h(A2);
}
else
{
    [GP + 97] = b(0);
}
////////////////////////////////



////////////////////////////////
// func1f6c0
[GP + 97] = b(1);
[GP + 98] = b(A1);
[GP + 9c] = w(28);
[GP + a1] = b(1);
[GP + 174] = w(A0);
////////////////////////////////



////////////////////////////////
// func1c4e8
S0 = A0;

A0 = 1;
A1 = h[GP + 2e];
A2 = h[GP + 30];
[GP + 2d] = b(1);
func1f6e4;

[GP + 97] = b(1);
[GP + 98] = b(7);
[GP + 9c] = w(28);
[GP + a1] = b(1);
[GP + 174] = w(S0);

A0 = 0;
A1 = ff;

loop1c524:	; 8001C524
    V1 = bu[S0 + 0];
    if( V1 < ff || V1 >= fa )
    {
        S0 = S0 + 2;
    }
    else
    {
        S0 = S0 + 1;
    }

    if( bu[S0 + 0] == ff )
    {
        S0 = S0 + 1;
        break;
    }

    A0 = A0 + 1;
    V0 = A0 < 100;
8001C56C	bne    v0, zero, loop1c524 [$8001c524]

return S0;
////////////////////////////////



////////////////////////////////
// func1c5bc
8001C5BC	lbu    v0, $002d(gp)
8001C5C8	addu   s0, zero, zero

if( V0 != 0 )
{
    8001C5D4	jal    func1c58c [$8001c58c]

    return S0;
}

V0 = w[GP + 158]; // pointer to tutorial data
//12 0A 00 0A 00 10
V1 = V0 + 1;
[GP + 158] = w(V1);
V1 = bu[V0];
if( V1 < 13 )
{
    V0 = w[800102b4 + V1 * 4];
    8001C61C	jr     v0 

24C60180 0
70C70180 1
60C60180 2
68C60180 3
70C60180 4
78C60180 5
90C60180 6
98C60180 7
80C60180 8
88C60180 9
A0C60180 a
A8C60180 b
B0C60180 c
B8C60180 d
70C70180 e
70C70180 f
54C70180 11

    8001C624	lw     v0, $0158(gp)
    8001C628	nop
    8001C62C	addiu  v1, v0, $0001
    8001C630	sw     v1, $0158(gp)
    8001C634	lbu    a0, $0000(v0)
    8001C638	nop
    8001C63C	sw     a0, $0150(gp)
    8001C640	lbu    v1, $0001(v0)
    8001C644	addiu  v0, v0, $0002
    8001C648	sw     v0, $0158(gp)
    8001C64C	sll    v1, v1, $08
    8001C650	addu   a0, a0, v1
    8001C654	sw     a0, $0150(gp)
    return S0;

    8001C660	j      L1c6bc [$8001c6bc]
    8001C664	ori    s0, zero, $1000
    8001C668	j      L1c6bc [$8001c6bc]
    8001C66C	ori    s0, zero, $4000
    8001C670	j      L1c6bc [$8001c6bc]
    8001C674	ori    s0, zero, $8000
    8001C678	j      L1c6bc [$8001c6bc]
    8001C67C	ori    s0, zero, $2000
    8001C680	j      L1c6bc [$8001c6bc]
    8001C684	ori    s0, zero, $0080
    8001C688	j      L1c6bc [$8001c6bc]
    8001C68C	ori    s0, zero, $0020
    8001C690	j      L1c6bc [$8001c6bc]
    8001C694	ori    s0, zero, $0010
    8001C698	j      L1c6bc [$8001c6bc]
    8001C69C	ori    s0, zero, $0040
    8001C6A0	j      L1c6bc [$8001c6bc]
    8001C6A4	ori    s0, zero, $0008
    8001C6A8	j      L1c6bc [$8001c6bc]
    8001C6AC	ori    s0, zero, $0002
    8001C6B0	j      L1c6bc [$8001c6bc]
    8001C6B4	ori    s0, zero, $0004
    8001C6B8	ori    s0, zero, $0001

    L1c6bc:	; 8001C6BC
    8001C6BC	ori    v0, zero, $0014
    8001C6C0	sw     v0, $0150(gp)
    return S0;

    case 10: // CCC60180 10
    {
        A0 = w[GP + 158];
        func1c4e8;

        [GP + 150] = w(50);
        [GP + 158] = w(V0);
        return S0;
    }
    break;

    case 12: // ECC60180 12
    {
        V0 = w[GP + 158];
        [GP + 2e] = h(hu[V0 + 0]);
        [GP + 30] = h(hu[V0 + 2]);
        [GP + 150] = w(3c);
        [GP + 158] = w(V0 + 4);

        return S0;
    }
    break;

    8001C754	addu   a0, zero, zero
    8001C758	addu   a1, zero, zero
    A2 = 0;
    func1f6e4;

    8001C764	lui    at, $8006
    8001C768	sw     zero, $2fa0(at)
    8001C76C	sw     zero, $0150(gp)
}

return S0;
////////////////////////////////



////////////////////////////////
// func1c808
if( w[80062fa0] == 0 )
{
    if( bu[800696ac] != ff )
    {
        if( bu[800696ad] == 41 )
        {
            V0 = bu[800696ae] << 8;
            V1 = bu[800696af];

            A0 = V1 NOR V0;
        }
        else
        {
            A0 = 0;
        }
    }
    else
    {
        A0 = 0;
    }
}
else // tutorial
{
    func1c788;

    A0 = V0;
}

8001C874	lui    v1, $8007
8001C878	lbu    v1, $96ce(v1)
8001C87C	ori    v0, zero, $00ff
8001C880	beq    v1, v0, L1c8bc [$8001c8bc]
8001C884	addu   v0, zero, zero
8001C888	lui    v1, $8007
8001C88C	lbu    v1, $96cf(v1)
8001C890	ori    v0, zero, $0041
8001C894	bne    v1, v0, L1c8b8 [$8001c8b8]
8001C898	nop
8001C89C	lui    v0, $8007
8001C8A0	lbu    v0, $96d0(v0)
8001C8A4	lui    v1, $8007
8001C8A8	lbu    v1, $96d1(v1)
8001C8AC	sll    v0, v0, $08
8001C8B0	j      L1c8bc [$8001c8bc]
8001C8B4	nor    v0, v1, v0

L1c8b8:	; 8001C8B8
8001C8B8	addu   v0, zero, zero

L1c8bc:	; 8001C8BC
8001C8BC	andi   v1, a0, $ffff
8001C8C0	sll    v0, v0, $10
8001C8C8	or     v0, v1, v0
////////////////////////////////



////////////////////////////////
// func1cb48
func1c808;

8001CB58	addu   a1, v0, zero
8001CB5C	lui    v0, $800a
8001CB60	lhu    v0, $d7be(v0)
8001CB64	srl    v1, a1, $10
8001CB68	lui    at, $8006
8001CB6C	sh     v1, $2d80(at)
8001CB70	srl    v0, v0, $02
8001CB74	andi   v0, v0, $0003
8001CB78	beq    v0, zero, L1cbf0 [$8001cbf0]
8001CB7C	nop
8001CB80	lui    v0, $8006
8001CB84	lw     v0, $2fa0(v0)
8001CB88	nop
8001CB8C	bne    v0, zero, L1cbf0 [$8001cbf0]
8001CB90	addu   a0, zero, zero
8001CB94	lui    at, $8006
8001CB98	sh     zero, $2d78(at)
8001CB9C	ori    a2, zero, $0001
8001CBA0	sllv   v0, a0, a2

loop1cba4:	; 8001CBA4
8001CBA4	and    v0, a1, v0
8001CBA8	beq    v0, zero, L1cbd8 [$8001cbd8]
8001CBAC	nop
8001CBB0	lui    at, $800a
8001CBB4	addiu  at, at, $d7c0 (=-$2840)
8001CBB8	addu   at, at, a0
8001CBBC	lbu    v0, $0000(at)
8001CBC0	lui    v1, $8006
8001CBC4	lhu    v1, $2d78(v1)
8001CBC8	sllv   v0, v0, a2
8001CBCC	or     v1, v1, v0
8001CBD0	lui    at, $8006
8001CBD4	sh     v1, $2d78(at)

L1cbd8:	; 8001CBD8
8001CBD8	addiu  a0, a0, $0001
8001CBDC	slti   v0, a0, $0010
8001CBE0	bne    v0, zero, loop1cba4 [$8001cba4]
8001CBE4	sllv   v0, a0, a2
8001CBE8	j      L1cbf8 [$8001cbf8]
8001CBEC	nop

L1cbf0:	; 8001CBF0
8001CBF0	lui    at, $8006
8001CBF4	sh     a1, $2d78(at)

L1cbf8:	; 8001CBF8
8001CBF8	lui    a1, $8006
8001CBFC	lhu    a1, $2d78(a1)
8001CC00	lui    v1, $8006
8001CC04	lhu    v1, $2d7a(v1)
8001CC08	lui    at, $8006
8001CC0C	sh     zero, $2d7e(at)
8001CC10	xor    v0, a1, v1
8001CC14	and    v0, v0, a1
8001CC18	lui    at, $8006
8001CC1C	sh     v0, $2d7c(at)
8001CC20	beq    a1, v1, L1cc38 [$8001cc38]
8001CC24	nop
8001CC28	sh     zero, $0020(gp)
8001CC2C	sh     zero, $001c(gp)
8001CC30	j      L1cc98 [$8001cc98]
8001CC34	nop

L1cc38:	; 8001CC38
8001CC38	lh     v0, $001c(gp)
8001CC3C	nop
8001CC40	beq    v0, zero, L1cc6c [$8001cc6c]
8001CC44	ori    v0, zero, $0003
8001CC48	lh     v1, $0020(gp)
8001CC4C	nop
8001CC50	bne    v1, v0, L1cc90 [$8001cc90]
8001CC54	addu   a0, v1, zero
8001CC58	lui    at, $8006
8001CC5C	sh     a1, $2d7e(at)
8001CC60	sh     zero, $0020(gp)
8001CC64	j      L1cc98 [$8001cc98]
8001CC68	nop

L1cc6c:	; 8001CC6C
8001CC6C	lh     v1, $0020(gp)
8001CC70	ori    v0, zero, $000f
8001CC74	bne    v1, v0, L1cc90 [$8001cc90]
8001CC78	addu   a0, v1, zero
8001CC7C	ori    v0, zero, $0001
8001CC80	sh     v0, $001c(gp)
8001CC84	sh     zero, $0020(gp)
8001CC88	j      L1cc98 [$8001cc98]
8001CC8C	nop

L1cc90:	; 8001CC90
8001CC90	addiu  v0, a0, $0001
8001CC94	sh     v0, $0020(gp)

L1cc98:	; 8001CC98
8001CC98	lui    a1, $8006
8001CC9C	lhu    a1, $2d80(a1)
8001CCA0	lui    v1, $8006
8001CCA4	lhu    v1, $2d82(v1)
8001CCA8	nop
8001CCAC	xor    v0, a1, v1
8001CCB0	and    v0, v0, a1
8001CCB4	lui    at, $8006
8001CCB8	sh     v0, $2d84(at)
8001CCBC	beq    a1, v1, L1ccd4 [$8001ccd4]
8001CCC0	nop
8001CCC4	sh     zero, $001e(gp)
8001CCC8	sh     zero, $0022(gp)
8001CCCC	j      L1cd3c [$8001cd3c]
8001CCD0	nop

L1ccd4:	; 8001CCD4
8001CCD4	lh     v0, $001e(gp)
8001CCD8	nop
8001CCDC	beq    v0, zero, L1cd08 [$8001cd08]
8001CCE0	ori    v0, zero, $0003
8001CCE4	lh     v1, $0022(gp)
8001CCE8	nop
8001CCEC	bne    v1, v0, L1cd2c [$8001cd2c]
8001CCF0	addu   a0, v1, zero
8001CCF4	lui    at, $8006
8001CCF8	sh     a1, $2d86(at)
8001CCFC	sh     zero, $0022(gp)
8001CD00	j      L1cd3c [$8001cd3c]
8001CD04	nop

L1cd08:	; 8001CD08
8001CD08	lh     v1, $0022(gp)
8001CD0C	ori    v0, zero, $000f
8001CD10	bne    v1, v0, L1cd2c [$8001cd2c]
8001CD14	addu   a0, v1, zero
8001CD18	ori    v0, zero, $0001
8001CD1C	sh     v0, $001e(gp)
8001CD20	sh     zero, $0022(gp)
8001CD24	j      L1cd34 [$8001cd34]
8001CD28	nop

L1cd2c:	; 8001CD2C
8001CD2C	addiu  v0, a0, $0001
8001CD30	sh     v0, $0022(gp)

L1cd34:	; 8001CD34
8001CD34	lui    at, $8006
8001CD38	sh     zero, $2d86(at)

L1cd3c:	; 8001CD3C
8001CD3C	lui    v0, $8006
8001CD40	lhu    v0, $2d7e(v0)
8001CD44	lui    v1, $8006
8001CD48	lhu    v1, $2d7c(v1)

L1cd4c:	; 8001CD4C
8001CD4C	lui    a0, $8006
8001CD50	lhu    a0, $2d78(a0)
8001CD54	lui    a1, $8006
8001CD58	lhu    a1, $2d80(a1)
8001CD5C	or     v0, v0, v1
8001CD60	lui    at, $8006
8001CD64	sh     v0, $2d7e(at)
8001CD68	lui    v0, $8006
8001CD6C	lhu    v0, $2d86(v0)
8001CD70	lui    v1, $8006
8001CD74	lhu    v1, $2d84(v1)
8001CD78	lui    at, $8006
8001CD7C	sh     a0, $2d7a(at)
8001CD80	lui    at, $8006
8001CD84	sh     a1, $2d82(at)
8001CD88	or     v0, v0, v1
8001CD8C	lui    at, $8006
8001CD90	sh     v0, $2d86(at)
8001CD94	lw     ra, $0030(sp)
8001CD98	addiu  sp, sp, $0038
8001CD9C	jr     ra 
8001CDA0	nop
////////////////////////////////



////////////////////////////////
// func1f710
8001F710	lbu    v0, $0097(gp)
8001F714	addiu  sp, sp, $ffd0 (=-$30)
8001F718	sw     ra, $002c(sp)
8001F71C	sw     s2, $0028(sp)
8001F720	sw     s1, $0024(sp)
8001F724	beq    v0, zero, L1fa0c [$8001fa0c]
8001F728	sw     s0, $0020(sp)

A0 = w[GP + 174];
func26b70;

8001F738	addu   s2, v0, zero
8001F73C	lbu    v1, $0097(gp)
8001F740	ori    v0, zero, $0002
8001F744	beq    v1, v0, L1f83c [$8001f83c]
8001F748	slti   v0, v1, $0003
8001F74C	beq    v0, zero, L1f764 [$8001f764]
8001F750	ori    v0, zero, $0001
8001F754	beq    v1, v0, L1f778 [$8001f778]
8001F758	lui    v0, $5555
8001F75C	j      L1f9e4 [$8001f9e4]
8001F760	nop

L1f764:	; 8001F764
8001F764	ori    v0, zero, $0003
8001F768	beq    v1, v0, L1f92c [$8001f92c]
8001F76C	lui    v0, $5555
8001F770	j      L1f9e4 [$8001f9e4]
8001F774	nop

L1f778:	; 8001F778
8001F778	ori    v0, v0, $5556
8001F77C	mult   s2, v0
8001F780	sra    v0, s2, $1f
8001F784	mfhi   t0
8001F788	lbu    a0, $00a1(gp)
8001F78C	subu   v0, t0, v0
8001F790	mult   v0, a0
8001F794	lbu    v1, $00a0(gp)
8001F798	mflo   a3
8001F79C	bne    v1, zero, L1f7cc [$8001f7cc]
8001F7A0	sll    a2, a0, $03
8001F7A4	ori    s1, zero, $00b4
8001F7A8	ori    s0, zero, $0068
8001F7AC	sw     a2, $0010(sp)
8001F7B0	addiu  a0, sp, $0018
8001F7B4	srl    a1, a3, $1f
8001F7B8	addu   a1, a3, a1
8001F7BC	sra    a1, a1, $01
8001F7C0	subu   a1, s1, a1
8001F7C4	j      L1f808 [$8001f808]
8001F7C8	srl    a2, a2, $01

L1f7cc:	; 8001F7CC
8001F7CC	addiu  a0, sp, $0018
8001F7D0	addiu  a1, s2, $0010
8001F7D4	srl    v0, a1, $1f
8001F7D8	addu   a1, a1, v0
8001F7DC	sra    a1, a1, $01
8001F7E0	srl    v0, a3, $1f
8001F7E4	addu   v0, a3, v0
8001F7E8	sra    v0, v0, $01
8001F7EC	sw     a2, $0010(sp)
8001F7F0	srl    a2, a2, $01
8001F7F4	addiu  a2, a2, $fff4 (=-$c)
8001F7F8	lh     s1, $00a2(gp)
8001F7FC	lh     s0, $00a4(gp)
8001F800	addu   a1, s1, a1
8001F804	subu   a1, a1, v0

L1f808:	; 8001F808
8001F808	jal    func1de0c [$8001de0c]
8001F80C	subu   a2, s0, a2
8001F810	lbu    v0, $00a1(gp)
8001F814	ori    v1, zero, $0003
8001F818	addiu  v0, v0, $0001
8001F81C	sb     v0, $00a1(gp)
8001F820	andi   v0, v0, $00ff
8001F824	bne    v0, v1, L1f9e4 [$8001f9e4]
8001F828	ori    v0, zero, $0002
8001F82C	sb     v0, $00a1(gp)
8001F830	sb     v0, $0097(gp)
8001F834	j      L1f9e4 [$8001f9e4]
8001F838	nop

L1f83c:	; 8001F83C
8001F83C	lbu    v0, $00a0(gp)
8001F840	nop
8001F844	bne    v0, zero, L1f880 [$8001f880]
8001F848	ori    s1, zero, $00b4
8001F84C	srl    s0, s2, $1f
8001F850	addu   s0, s2, s0
8001F854	sra    s0, s0, $01
8001F858	subu   s0, s1, s0
8001F85C	addu   a0, s0, zero
8001F860	lw     a2, $0174(gp)
8001F864	lbu    a3, $0098(gp)
8001F868	jal    func26f44 [$80026f44]
8001F86C	ori    a1, zero, $0062
8001F870	addiu  a0, sp, $0018
8001F874	addiu  a1, s0, $fff8 (=-$8)
8001F878	j      L1f8a8 [$8001f8a8]
8001F87C	ori    a2, zero, $005c

L1f880:	; 8001F880
8001F880	lh     s1, $00a2(gp)
8001F884	lh     s0, $00a4(gp)
8001F888	lw     a2, $0174(gp)
8001F88C	lbu    a3, $0098(gp)
8001F890	addiu  a0, s1, $0008
8001F894	jal    func26f44 [$80026f44]
8001F898	addiu  a1, s0, $0006
8001F89C	addiu  a0, sp, $0018
8001F8A0	addu   a1, s1, zero
8001F8A4	addu   a2, s0, zero

L1f8a8:	; 8001F8A8
8001F8A8	addiu  a3, s2, $0010
8001F8AC	ori    v0, zero, $0018
8001F8B0	jal    func1de0c [$8001de0c]
8001F8B4	sw     v0, $0010(sp)
8001F8B8	lw     v0, $009c(gp)
8001F8BC	nop
8001F8C0	beq    v0, zero, L1f8cc [$8001f8cc]
8001F8C4	addiu  v0, v0, $ffff (=-$1)
8001F8C8	sw     v0, $009c(gp)

L1f8cc:	; 8001F8CC
8001F8CC	lw     v0, $009c(gp)
8001F8D0	nop
8001F8D4	slti   v0, v0, $0014
8001F8D8	beq    v0, zero, L1f9e4 [$8001f9e4]
8001F8DC	nop
8001F8E0	jal    func34b44 [$80034b44]
8001F8E4	nop
8001F8E8	bne    v0, zero, L1f9e4 [$8001f9e4]
8001F8EC	nop
8001F8F0	lbu    v0, $00a0(gp)
8001F8F4	nop
8001F8F8	bne    v0, zero, L1f910 [$8001f910]
8001F8FC	nop
8001F900	lw     v0, $009c(gp)
8001F904	nop
8001F908	beq    v0, zero, L1f920 [$8001f920]
8001F90C	ori    v0, zero, $0003

L1f910:	; 8001F910
8001F910	jal    func1c498 [$8001c498]
8001F914	nop
8001F918	beq    v0, zero, L1f9e4 [$8001f9e4]
8001F91C	ori    v0, zero, $0003

L1f920:	; 8001F920
8001F920	sb     v0, $0097(gp)
8001F924	j      L1f9e4 [$8001f9e4]
8001F928	nop

L1f92c:	; 8001F92C
8001F92C	ori    v0, v0, $5556
8001F930	mult   s2, v0
8001F934	sra    v0, s2, $1f
8001F938	mfhi   t0
8001F93C	lbu    a0, $00a1(gp)
8001F940	subu   v0, t0, v0
8001F944	mult   v0, a0
8001F948	lbu    v1, $00a0(gp)
8001F94C	mflo   a3
8001F950	bne    v1, zero, L1f980 [$8001f980]
8001F954	sll    a2, a0, $03
8001F958	ori    s1, zero, $00b4
8001F95C	ori    s0, zero, $0068
8001F960	sw     a2, $0010(sp)
8001F964	addiu  a0, sp, $0018
8001F968	srl    a1, a3, $1f
8001F96C	addu   a1, a3, a1
8001F970	sra    a1, a1, $01
8001F974	subu   a1, s1, a1
8001F978	j      L1f9bc [$8001f9bc]
8001F97C	srl    a2, a2, $01

L1f980:	; 8001F980
8001F980	addiu  a0, sp, $0018
8001F984	addiu  a1, s2, $0010
8001F988	srl    v0, a1, $1f
8001F98C	addu   a1, a1, v0
8001F990	sra    a1, a1, $01
8001F994	srl    v0, a3, $1f
8001F998	addu   v0, a3, v0
8001F99C	sra    v0, v0, $01
8001F9A0	sw     a2, $0010(sp)
8001F9A4	srl    a2, a2, $01
8001F9A8	addiu  a2, a2, $fff4 (=-$c)
8001F9AC	lh     s1, $00a2(gp)
8001F9B0	lh     s0, $00a4(gp)
8001F9B4	addu   a1, s1, a1
8001F9B8	subu   a1, a1, v0

L1f9bc:	; 8001F9BC
8001F9BC	jal    func1de0c [$8001de0c]
8001F9C0	subu   a2, s0, a2
8001F9C4	lbu    v0, $00a1(gp)
8001F9C8	nop
8001F9CC	addiu  v0, v0, $ffff (=-$1)
8001F9D0	sb     v0, $00a1(gp)
8001F9D4	andi   v0, v0, $00ff
8001F9D8	bne    v0, zero, L1f9e4 [$8001f9e4]
8001F9DC	nop
8001F9E0	sb     zero, $0097(gp)

L1f9e4:	; 8001F9E4
8001F9E4	jal    func1de70 [$8001de70]
8001F9E8	nop
8001F9EC	lui    a0, $8005
8001F9F0	addiu  a0, a0, $9384 (=-$6c7c)
8001F9F4	jal    func1def0 [$8001def0]
8001F9F8	nop
8001F9FC	jal    func1e040 [$8001e040]
8001FA00	addiu  a0, sp, $0018
8001FA04	jal    func1deb0 [$8001deb0]
8001FA08	nop

L1fa0c:	; 8001FA0C
////////////////////////////////



////////////////////////////////
// func26b70
80026B74	addu   a2, zero, zero
80026B78	lbu    v0, $00b8(gp)

if( V0 <= 0 )
{
    return 0;
}

A1 = 0;

80026B88	ori    t2, zero, $00ff
80026B8C	lui    t1, $8001
80026B90	addiu  t1, t1, $0360
80026B94	lui    t0, $8007
80026B98	lw     t0, $07c0(t0)
80026B9C	addu   a3, v0, zero

loop26ba0:	; 80026BA0
    if( A0 == 0 )
    {
        return A1;
    }

    V0 = bu[A0];

    if( V0 == A2 )
    {
        return A1;
    }

    80026BB8	addiu  v1, v0, $ff06 (=-$fa)
    80026BBC	sltiu  v0, v1, $0005
    if( V1 < 5 )
    {
        80026BC4	sll    v0, v1, $02
        80026BC8	addu   v0, v0, t1
        80026BCC	lw     v0, $0000(v0)
        80026BD0	nop
        80026BD4	jr     v0 
        80026BD8	nop

        80026BDC	addiu  a0, a0, $0001
        80026BE0	j      L26c1c [$80026c1c]
        80026BE4	ori    v1, zero, $00e7
        80026BE8	addiu  a0, a0, $0001
        80026BEC	j      L26c1c [$80026c1c]
        80026BF0	ori    v1, zero, $01b9
        80026BF4	addiu  a0, a0, $0001
        80026BF8	j      L26c1c [$80026c1c]
        80026BFC	ori    v1, zero, $02a0
        80026C00	addiu  a0, a0, $0001
        80026C04	j      L26c1c [$80026c1c]
        80026C08	ori    v1, zero, $0372
        80026C0C	addiu  a0, a0, $0001
        80026C10	j      L26c1c [$80026c1c]
        80026C14	ori    v1, zero, $0444
    }
    else
    {
        V1 = 0;
    }

    L26c1c:	; 80026C1C
    80026C1C	lbu    v0, $0000(a0)
    80026C20	addiu  a0, a0, $0001
    80026C24	addu   v0, v0, v1
    80026C28	addu   v0, t0, v0
    80026C2C	lbu    v1, $0000(v0)
    80026C30	addiu  a2, a2, $0001
    80026C34	srl    v0, v1, $05
    80026C38	addu   a1, a1, v0
    80026C3C	andi   v1, v1, $001f
    80026C48	addu   a1, a1, v1
    80026C40	slt    v0, a2, a3
80026C44	bne    v0, zero, loop26ba0 [$80026ba0]

return A1;
////////////////////////////////
