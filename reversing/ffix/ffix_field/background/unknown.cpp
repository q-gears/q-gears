////////////////////////////////
// funcbe158
T2 = A0;
V0 = w[800c9da4];
T4 = w[T2 + 30];
T0 = w[800c9da4 + 10];
A0 = bu[V0];
T9 = hu[T2 + 26];
V0 = A0 << 2;
V0 = V0 + 800c9da4;
S5 = w[V0 + 8];
V0 = T9 << 1;
if( A0 != 0 )
{
    V0 = V0 + T9;
    V0 = V0 << 3;
    T4 = T4 + V0;
}

V1 = hu[T2 + c];
A0 = hu[T2 + e];
T6 = V1 + hu[T0 + 30];
T5 = A0 + hu[T0 + 32];
V1 = hu[T0 + 1e];
V0 = w[T2 + 0] >> 8;
V0 = V0 & 0fff;
S4 = V1 + V0;
V0 = w[T2 + 28];
V1 = bu[T2 + 0];
T3 = T0 + V0;
V0 = V1 & 4;
800BE1F8	beq    v0, zero, Lbe7ac [$800be7ac]

if( V1 & 1 )
{
    V0 = w[T2 + 24] >> 7;
    V1 = 800ca068;
    V0 = V0 & 1fc;
    V0 = V0 + V1;
    T8 = hu[V0 + a8];
    T7 = hu[V0 + aa];
}
else
{
    A0 = 800ca068;
    V0 = w[T2 + 24] >> 7;
    A1 = hu[A0 + 4];
    V0 = V0 & 1fc;
    V0 = V0 + A0;
    V1 = hu[V0 + a8];
    V0 = hu[V0 + aa];
    V1 = V1 + a0;
    T8 = V1 - A1;
    V1 = hu[A0 + 6];
    V0 = V0 + 70;
    T7 = V0 - V1;
}

V1 = 800ca068;
V0 = w[T2 + 24];
A1 = h[T2 + 1c];
V0 = V0 >> 7;
V0 = V0 & 1fc;
V0 = V0 + V1;
A2 = hu[V0 + b8];
A3 = hu[V0 + ba];
V1 = 100;
if( A1 < 0 )
{
    V1 = V1 - A1;
    V1 = (V1 << 10) >> 10;

    800BE29C	lh     v0, $000c(t2)
    800BE2A0	lh     a0, $0020(t2)
    800BE2A4	sll    v0, v0, $08
    800BE2A8	or     v0, v0, a0
    800BE2AC	addu   v0, v0, v1
    800BE2B0	lhu    v1, $0030(t0)
    800BE2B4	sra    v0, v0, $08
    800BE2B8	addu   t6, v1, v0
}

800BE2BC	lh     t1, $001e(t2)
800BE2C0	nop
800BE2C4	bgez   t1, Lbe2f8 [$800be2f8]
800BE2C8	addiu  v1, zero, $0100
800BE2CC	subu   v1, v1, a1
800BE2D0	sll    v1, v1, $10
800BE2D4	sra    v1, v1, $10
800BE2D8	lh     v0, $000e(t2)
800BE2DC	lh     a0, $0022(t2)
800BE2E0	sll    v0, v0, $08
800BE2E4	or     v0, v0, a0
800BE2E8	addu   v0, v0, v1
800BE2EC	lhu    v1, $0032(t0)
800BE2F0	sra    v0, v0, $08
800BE2F4	addu   t5, v1, v0

Lbe2f8:	; 800BE2F8
800BE2F8	beq    a1, zero, Lbe34c [$800be34c]
800BE2FC	sll    v0, t6, $10
800BE300	sra    v0, v0, $10
800BE304	sll    v1, a2, $10
800BE308	lhu    a0, $0004(t2)
800BE30C	sra    v1, v1, $10
800BE310	subu   v1, v1, a0
800BE314	subu   v0, v0, v1
800BE318	div    v0, a0
800BE340	mfhi   v1
800BE344	subu   a0, a2, a0
800BE348	addu   t6, v1, a0

Lbe34c:	; 800BE34C
800BE34C	beq    t1, zero, Lbe3a0 [$800be3a0]
800BE350	sll    v0, t5, $10
800BE354	sra    v0, v0, $10
800BE358	sll    v1, a3, $10
800BE35C	lhu    a0, $0006(t2)
800BE360	sra    v1, v1, $10
800BE364	subu   v1, v1, a0
800BE368	subu   v0, v0, v1
800BE36C	div    v0, a0
800BE394	mfhi   v1
800BE398	subu   a0, a3, a0
800BE39C	addu   t5, v1, a0

Lbe3a0:	; 800BE3A0
800BE3A0	beq    t9, zero, Lbedb4 [$800bedb4]
800BE3A4	addu   t0, zero, zero
800BE3A8	sll    v0, t8, $10
800BE3AC	sra    s2, v0, $10
800BE3B0	sll    v0, a2, $10
800BE3B4	sra    s1, v0, $10
800BE3B8	addu   s6, s2, s1
800BE3BC	sll    v0, t7, $10
800BE3C0	sra    s0, v0, $10
800BE3C4	sll    v0, a3, $10
800BE3C8	sra    t1, v0, $10
800BE3CC	addu   s3, s0, t1

Lbe3d0:	; 800BE3D0
800BE3D0	lbu    v0, $0000(t2)
800BE3D4	nop
800BE3D8	andi   v0, v0, $0001
800BE3DC	beq    v0, zero, Lbe540 [$800be540]
800BE3E0	sll    v0, t0, $10
800BE3E4	sra    v0, v0, $0e
800BE3E8	addu   v0, v0, t3
800BE3EC	lw     v0, $0000(v0)
800BE3F0	nop
800BE3F4	srl    v0, v0, $16
800BE3F8	addu   a0, t6, v0
800BE3FC	lh     v0, $001c(t2)
800BE400	nop
800BE404	beq    v0, zero, Lbe43c [$800be43c]
800BE408	addu   a3, a0, zero
800BE40C	sll    v0, a0, $10
800BE410	sra    a1, v0, $10
800BE414	lhu    v1, $0004(t2)
800BE418	addiu  v0, a1, $0010
800BE41C	slt    v0, v0, v1
800BE420	bne    v0, zero, Lbe430 [$800be430]
800BE424	slti   v0, a1, $fff1 (=-$f)
800BE428	j      Lbe43c [$800be43c]
800BE42C	subu   a3, a0, v1

Lbe430:	; 800BE430
800BE430	beq    v0, zero, Lbe440 [$800be440]
800BE434	sll    v0, a3, $10
800BE438	addu   a3, a0, v1

Lbe43c:	; 800BE43C
800BE43C	sll    v0, a3, $10

Lbe440:	; 800BE440
800BE440	sra    v1, v0, $10
800BE444	addu   v0, v1, s2
800BE448	slti   v0, v0, $fff1 (=-$f)
800BE44C	bne    v0, zero, Lbe78c [$800be78c]
800BE450	addiu  v0, t0, $0001
800BE454	slt    v0, s1, v1
800BE458	bne    v0, zero, Lbe78c [$800be78c]
800BE45C	addiu  v0, t0, $0001
800BE460	sll    v0, t0, $10
800BE464	sra    v0, v0, $0e
800BE468	addu   v0, v0, t3
800BE46C	lw     v0, $0000(v0)
800BE470	nop
800BE474	srl    v0, v0, $0c
800BE478	andi   v0, v0, $03ff
800BE47C	addu   a0, t5, v0
800BE480	lh     v0, $001e(t2)
800BE484	nop
800BE488	beq    v0, zero, Lbe4c0 [$800be4c0]
800BE48C	addu   a2, a0, zero
800BE490	sll    v0, a0, $10
800BE494	sra    a1, v0, $10
800BE498	lhu    v1, $0006(t2)
800BE49C	addiu  v0, a1, $0010
800BE4A0	slt    v0, v0, v1
800BE4A4	bne    v0, zero, Lbe4b4 [$800be4b4]
800BE4A8	slti   v0, a1, $fff1 (=-$f)
800BE4AC	j      Lbe4c0 [$800be4c0]
800BE4B0	subu   a2, a0, v1

Lbe4b4:	; 800BE4B4
800BE4B4	beq    v0, zero, Lbe4c4 [$800be4c4]
800BE4B8	sll    v0, a2, $10
800BE4BC	addu   a2, a0, v1

Lbe4c0:	; 800BE4C0
800BE4C0	sll    v0, a2, $10

Lbe4c4:	; 800BE4C4
800BE4C4	sra    v1, v0, $10
800BE4C8	addu   v0, v1, s0
800BE4CC	slti   v0, v0, $fff1 (=-$f)
800BE4D0	bne    v0, zero, Lbe78c [$800be78c]
800BE4D4	addiu  v0, t0, $0001
800BE4D8	slt    v0, v1, t1
800BE4DC	beq    v0, zero, Lbe78c [$800be78c]
800BE4E0	addiu  v0, t0, $0001
800BE4E4	sll    v0, t0, $10
800BE4E8	sra    v1, v0, $10
800BE4EC	sll    v0, v1, $02
800BE4F0	addu   v0, v0, t3
800BE4F4	lhu    v0, $0000(v0)
800BE4F8	nop
800BE4FC	andi   v0, v0, $0fff
800BE500	addu   v0, s4, v0
800BE504	addu   a1, v0, zero
800BE508	addiu  v0, v0, $fff8 (=-$8)
800BE50C	andi   v0, v0, $ffff
800BE510	sltiu  v0, v0, $0ff1
800BE514	beq    v0, zero, Lbe78c [$800be78c]
800BE518	addiu  v0, t0, $0001
800BE51C	sll    v0, v1, $01
800BE520	addu   v0, v0, v1
800BE524	sll    v0, v0, $03
800BE528	addu   v0, v0, t4
800BE52C	addu   v1, a3, t8
800BE530	sh     v1, $0010(v0)
800BE534	addu   v1, a2, t7
800BE538	j      Lbe72c [$800be72c]
800BE53C	sh     v1, $0012(v0)

Lbe540:	; 800BE540
800BE540	sra    a0, v0, $10
800BE544	sll    v0, a0, $02
800BE548	addu   v0, v0, t3
800BE54C	lw     v0, $0000(v0)
800BE550	nop
800BE554	srl    v0, v0, $16
800BE558	addu   a1, t6, v0
800BE55C	lh     v0, $001c(t2)
800BE560	nop
800BE564	beq    v0, zero, Lbe5e4 [$800be5e4]
800BE568	addu   a3, a1, zero
800BE56C	sll    v0, a1, $10
800BE570	sra    a0, v0, $10
800BE574	lhu    v1, $0004(t2)
800BE578	addiu  v0, a0, $0010

funcbe57c:	; 800BE57C
800BE57C	slt    v0, v0, v1
800BE580	bne    v0, zero, Lbe590 [$800be590]
800BE584	slti   v0, a0, $fff1 (=-$f)
800BE588	j      Lbe59c [$800be59c]
800BE58C	subu   a3, a1, v1

Lbe590:	; 800BE590
800BE590	beq    v0, zero, Lbe5a0 [$800be5a0]
800BE594	sll    v0, a3, $10
800BE598	addu   a3, a1, v1

Lbe59c:	; 800BE59C
800BE59C	sll    v0, a3, $10

Lbe5a0:	; 800BE5A0
800BE5A0	sra    v1, v0, $10
800BE5A4	addu   v0, v1, s2
800BE5A8	slti   v0, v0, $fff1 (=-$f)
800BE5AC	bne    v0, zero, Lbe78c [$800be78c]
800BE5B0	addiu  v0, t0, $0001
800BE5B4	slt    v0, v1, s1
800BE5B8	beq    v0, zero, Lbe78c [$800be78c]
800BE5BC	addiu  v0, t0, $0001
800BE5C0	sll    v0, t0, $10
800BE5C4	sra    v0, v0, $10
800BE5C8	sll    v1, v0, $01
800BE5CC	addu   v1, v1, v0
800BE5D0	sll    v1, v1, $03
800BE5D4	addu   v1, v1, t4
800BE5D8	addu   v0, a3, t8
800BE5DC	j      Lbe618 [$800be618]
800BE5E0	sh     v0, $0010(v1)

Lbe5e4:	; 800BE5E4
800BE5E4	sll    v0, a1, $10
800BE5E8	sra    v1, v0, $10
800BE5EC	slti   v0, v1, $fff1 (=-$f)
800BE5F0	bne    v0, zero, Lbe78c [$800be78c]
800BE5F4	addiu  v0, t0, $0001
800BE5F8	slt    v0, v1, s6
800BE5FC	beq    v0, zero, Lbe78c [$800be78c]
800BE600	addiu  v0, t0, $0001
800BE604	sll    v0, a0, $01
800BE608	addu   v0, v0, a0
800BE60C	sll    v0, v0, $03
800BE610	addu   v0, v0, t4
800BE614	sh     a1, $0010(v0)

Lbe618:	; 800BE618
800BE618	sll    v0, t0, $10
800BE61C	sra    a0, v0, $10
800BE620	sll    v0, a0, $02
800BE624	addu   v0, v0, t3
800BE628	lw     v0, $0000(v0)
800BE62C	nop
800BE630	srl    v0, v0, $0c
800BE634	andi   v0, v0, $03ff
800BE638	addu   a1, t5, v0
800BE63C	lh     v0, $001e(t2)
800BE640	nop
800BE644	beq    v0, zero, Lbe6c4 [$800be6c4]
800BE648	addu   a2, a1, zero
800BE64C	sll    v0, a1, $10
800BE650	sra    a0, v0, $10
800BE654	lhu    v1, $0006(t2)
800BE658	addiu  v0, a0, $0010
800BE65C	slt    v0, v0, v1

Lbe660:	; 800BE660
800BE660	bne    v0, zero, Lbe670 [$800be670]
800BE664	slti   v0, a0, $fff1 (=-$f)
800BE668	j      Lbe67c [$800be67c]
800BE66C	subu   a2, a1, v1

Lbe670:	; 800BE670
800BE670	beq    v0, zero, Lbe680 [$800be680]
800BE674	sll    v0, a2, $10
800BE678	addu   a2, a1, v1

Lbe67c:	; 800BE67C
800BE67C	sll    v0, a2, $10

Lbe680:	; 800BE680
800BE680	sra    v1, v0, $10
800BE684	addu   v0, v1, s0
800BE688	slti   v0, v0, $fff1 (=-$f)
800BE68C	bne    v0, zero, Lbe78c [$800be78c]
800BE690	addiu  v0, t0, $0001
800BE694	slt    v0, v1, t1
800BE698	beq    v0, zero, Lbe78c [$800be78c]
800BE69C	addiu  v0, t0, $0001
800BE6A0	sll    v0, t0, $10
800BE6A4	sra    v0, v0, $10
800BE6A8	sll    v1, v0, $01
800BE6AC	addu   v1, v1, v0

Lbe6b0:	; 800BE6B0
800BE6B0	sll    v1, v1, $03
800BE6B4	addu   v1, v1, t4
800BE6B8	addu   v0, a2, t7
800BE6BC	j      Lbe6f8 [$800be6f8]
800BE6C0	sh     v0, $0012(v1)

Lbe6c4:	; 800BE6C4
800BE6C4	sll    v0, a1, $10
800BE6C8	sra    v1, v0, $10
800BE6CC	slti   v0, v1, $fff1 (=-$f)
800BE6D0	bne    v0, zero, Lbe78c [$800be78c]
800BE6D4	addiu  v0, t0, $0001
800BE6D8	slt    v0, v1, s3
800BE6DC	beq    v0, zero, Lbe78c [$800be78c]
800BE6E0	addiu  v0, t0, $0001
800BE6E4	sll    v0, a0, $01
800BE6E8	addu   v0, v0, a0
800BE6EC	sll    v0, v0, $03
800BE6F0	addu   v0, v0, t4
800BE6F4	sh     a1, $0012(v0)

Lbe6f8:	; 800BE6F8
800BE6F8	sll    v0, t0, $10
800BE6FC	sra    v0, v0, $0e
800BE700	addu   v0, v0, t3
800BE704	lhu    v0, $0000(v0)
800BE708	nop
800BE70C	andi   v0, v0, $0fff
800BE710	addu   v0, s4, v0
800BE714	addu   a1, v0, zero
800BE718	addiu  v0, v0, $fff8 (=-$8)
800BE71C	andi   v0, v0, $ffff
800BE720	sltiu  v0, v0, $0ff1
800BE724	beq    v0, zero, Lbe78c [$800be78c]
800BE728	addiu  v0, t0, $0001

Lbe72c:	; 800BE72C
800BE72C	lui    a3, $00ff
800BE730	ori    a3, a3, $ffff
800BE734	sll    v0, t0, $10
800BE738	sra    v0, v0, $10
800BE73C	sll    a0, v0, $01
800BE740	addu   a0, a0, v0
800BE744	sll    a0, a0, $03
800BE748	addu   a0, a0, t4
800BE74C	sll    a1, a1, $10
800BE750	sra    a1, a1, $0e
800BE754	addu   a1, a1, s5
800BE758	lui    a2, $ff00
800BE75C	lw     v1, $0000(a0)
800BE760	lw     v0, $0000(a1)
800BE764	and    v1, v1, a2
800BE768	and    v0, v0, a3

Lbe76c:	; 800BE76C
800BE76C	or     v1, v1, v0
800BE770	sw     v1, $0000(a0)
800BE774	lw     v0, $0000(a1)
800BE778	and    a0, a0, a3
800BE77C	and    v0, v0, a2
800BE780	or     v0, v0, a0

funcbe784:	; 800BE784
800BE784	sw     v0, $0000(a1)
800BE788	addiu  v0, t0, $0001

Lbe78c:	; 800BE78C
800BE78C	addu   t0, v0, zero
800BE790	sll    v0, v0, $10
800BE794	sra    v0, v0, $10
800BE798	sltu   v0, v0, t9
800BE79C	bne    v0, zero, Lbe3d0 [$800be3d0]
800BE7A0	nop
800BE7A4	j      Lbedb8 [$800bedb8]
800BE7A8	sh     t6, $0018(t2)

Lbe7ac:	; 800BE7AC
800BE7AC	andi   v0, v1, $0080
800BE7B0	beq    v0, zero, Lbecbc [$800becbc]
800BE7B4	sltu   v0, v0, t9
800BE7B8	andi   v0, v1, $0001
800BE7BC	beq    v0, zero, Lbe7e8 [$800be7e8]
800BE7C0	lui    v1, $800d
800BE7C4	lw     v0, $0024(t2)
800BE7C8	addiu  v1, v1, $a068 (=-$5f98)
800BE7CC	srl    v0, v0, $07
800BE7D0	andi   v0, v0, $01fc
800BE7D4	addu   v0, v0, v1
800BE7D8	lhu    t8, $00a8(v0)
800BE7DC	lhu    t7, $00aa(v0)
800BE7E0	j      Lbe824 [$800be824]
800BE7E4	lui    v0, $800d

Lbe7e8:	; 800BE7E8
800BE7E8	lui    a0, $800d
800BE7EC	addiu  a0, a0, $a068 (=-$5f98)
800BE7F0	lw     v0, $0024(t2)
800BE7F4	lhu    a1, $0004(a0)
800BE7F8	srl    v0, v0, $07
800BE7FC	andi   v0, v0, $01fc
800BE800	addu   v0, v0, a0
800BE804	lhu    v1, $00a8(v0)

Lbe808:	; 800BE808
800BE808	lhu    v0, $00aa(v0)
800BE80C	addiu  v1, v1, $00a0
800BE810	subu   t8, v1, a1
800BE814	lhu    v1, $0006(a0)
800BE818	addiu  v0, v0, $0070
800BE81C	subu   t7, v0, v1
800BE820	lui    v0, $800d

Lbe824:	; 800BE824
800BE824	lw     a0, $0024(t2)
800BE828	addiu  v0, v0, $a068 (=-$5f98)
800BE82C	srl    v1, a0, $07
800BE830	andi   v1, v1, $01fc
800BE834	addu   v1, v1, v0
800BE838	srl    a0, a0, $08
800BE83C	andi   a0, a0, $0001
800BE840	lhu    a2, $00b8(v1)
800BE844	lhu    a3, $00ba(v1)
800BE848	beq    a0, zero, Lbe924 [$800be924]
800BE84C	sll    v0, t5, $10
800BE850	sra    v0, v0, $10
800BE854	sll    v1, a3, $10
800BE858	lhu    a0, $0006(t2)
800BE85C	sra    v1, v1, $10
800BE860	subu   v1, v1, a0
800BE864	subu   v0, v0, v1
800BE868	div    v0, a0
800BE890	mfhi   v1
800BE894	lh     a1, $001c(t2)
800BE898	subu   v0, a3, a0
800BE89C	addu   v1, v1, v0
800BE8A0	sll    v0, v1, $10
800BE8A4	sra    v0, v0, $10
800BE8A8	mult   v0, a1
800BE8AC	mflo   a1
800BE8B0	nop
800BE8B4	nop
800BE8B8	div    a1, a0
800BE8E0	mflo   a0
800BE8E4	lhu    v0, $0004(t2)
800BE8E8	nop
800BE8EC	div    a0, v0
800BE914	mfhi   v0
800BE918	addu   t5, v1, zero
800BE91C	j      Lbe9f8 [$800be9f8]
800BE920	addu   t6, t6, v0

Lbe924:	; 800BE924
800BE924	sll    v0, t6, $10
800BE928	sra    v0, v0, $10
800BE92C	sll    v1, a2, $10
800BE930	lhu    a0, $0004(t2)
800BE934	sra    v1, v1, $10
800BE938	subu   v1, v1, a0
800BE93C	subu   v0, v0, v1
800BE940	div    v0, a0
800BE968	mfhi   v1

Lbe96c:	; 800BE96C
800BE96C	lh     a1, $001e(t2)
800BE970	subu   v0, a2, a0
800BE974	addu   v1, v1, v0
800BE978	sll    v0, v1, $10
800BE97C	sra    v0, v0, $10
800BE980	mult   v0, a1
800BE984	mflo   a1
800BE988	nop

Lbe98c:	; 800BE98C
800BE98C	nop
800BE990	div    a1, a0
800BE9B8	mflo   a0
800BE9BC	lhu    v0, $0006(t2)
800BE9C0	nop
800BE9C4	div    a0, v0
800BE9EC	mfhi   v0
800BE9F0	addu   t6, v1, zero
800BE9F4	addu   t5, t5, v0

Lbe9f8:	; 800BE9F8
800BE9F8	beq    t9, zero, Lbedb4 [$800bedb4]
800BE9FC	addu   t0, zero, zero
800BEA00	sll    v0, t8, $10
800BEA04	sra    s3, v0, $10
800BEA08	sll    v0, a2, $10
800BEA0C	sra    s2, v0, $10
800BEA10	addu   s7, s3, s2
800BEA14	sw     s7, $0000(sp)
800BEA18	sll    v0, t7, $10
800BEA1C	sra    s1, v0, $10
800BEA20	sll    v0, a3, $10
800BEA24	sra    s0, v0, $10

Lbea28:	; 800BEA28
800BEA28	addu   s6, s1, s0
800BEA2C	lui    t1, $00ff
800BEA30	ori    t1, t1, $ffff

Lbea34:	; 800BEA34
800BEA34	lw     v0, $0024(t2)
800BEA38	nop
800BEA3C	srl    v0, v0, $08
800BEA40	andi   v0, v0, $0001
800BEA44	beq    v0, zero, Lbeb38 [$800beb38]
800BEA48	sll    v0, t0, $10
800BEA4C	sra    v0, v0, $0e
800BEA50	addu   v0, v0, t3
800BEA54	addu   a3, zero, zero
800BEA58	lw     v0, $0000(v0)
800BEA5C	lhu    a0, $0006(t2)
800BEA60	srl    v0, v0, $0c
800BEA64	andi   v0, v0, $03ff
800BEA68	addu   a1, t5, v0
800BEA6C	sll    v0, a1, $10
800BEA70	sra    a2, v0, $10
800BEA74	addiu  v0, a2, $0010
800BEA78	slt    v0, v0, a0
800BEA7C	bne    v0, zero, Lbea94 [$800bea94]
800BEA80	addu   v1, a1, zero
800BEA84	lhu    v0, $001c(t2)
800BEA88	subu   v1, a1, a0
800BEA8C	j      Lbeaa8 [$800beaa8]
800BEA90	subu   a3, zero, v0

Lbea94:	; 800BEA94
800BEA94	slti   v0, a2, $fff1 (=-$f)
800BEA98	beq    v0, zero, Lbeaac [$800beaac]
800BEA9C	sll    v0, v1, $10
800BEAA0	addu   v1, a1, a0
800BEAA4	lhu    a3, $001c(t2)

Lbeaa8:	; 800BEAA8
800BEAA8	sll    v0, v1, $10

Lbeaac:	; 800BEAAC
800BEAAC	sra    a0, v0, $10
800BEAB0	addu   v0, a0, s1
800BEAB4	slti   v0, v0, $fff1 (=-$f)
800BEAB8	bne    v0, zero, Lbec9c [$800bec9c]
800BEABC	addiu  v0, t0, $0001
800BEAC0	slt    v0, a0, s0
800BEAC4	beq    v0, zero, Lbec9c [$800bec9c]
800BEAC8	addiu  v0, t0, $0001
800BEACC	sll    v0, t0, $10
800BEAD0	sra    a1, v0, $10
800BEAD4	sll    v0, a1, $02
800BEAD8	addu   v0, v0, t3
800BEADC	lw     v0, $0000(v0)
800BEAE0	nop
800BEAE4	srl    v0, v0, $16
800BEAE8	addu   v0, t6, v0
800BEAEC	addu   a2, a3, v0
800BEAF0	sll    v0, a2, $10
800BEAF4	sra    a0, v0, $10
800BEAF8	slti   v0, a0, $fff1 (=-$f)
800BEAFC	bne    v0, zero, Lbec9c [$800bec9c]
800BEB00	addiu  v0, t0, $0001
800BEB04	lw     s7, $0000(sp)
800BEB08	nop
800BEB0C	slt    v0, a0, s7
800BEB10	beq    v0, zero, Lbec9c [$800bec9c]
800BEB14	addiu  v0, t0, $0001
800BEB18	sll    v0, a1, $01
800BEB1C	addu   v0, v0, a1

Lbeb20:	; 800BEB20
800BEB20	sll    v0, v0, $03
800BEB24	addu   v0, v0, t4
800BEB28	addu   v1, v1, t7
800BEB2C	sh     a2, $0010(v0)
800BEB30	j      Lbec18 [$800bec18]
800BEB34	sh     v1, $0012(v0)

Lbeb38:	; 800BEB38
800BEB38	sra    v0, v0, $0e
800BEB3C	addu   v0, v0, t3
800BEB40	addu   a3, zero, zero
800BEB44	lw     v0, $0000(v0)
800BEB48	lhu    a0, $0004(t2)
800BEB4C	srl    v0, v0, $16
800BEB50	addu   a1, t6, v0
800BEB54	sll    v0, a1, $10
800BEB58	sra    a2, v0, $10
800BEB5C	addiu  v0, a2, $0010
800BEB60	slt    v0, v0, a0
800BEB64	bne    v0, zero, Lbeb7c [$800beb7c]
800BEB68	addu   v1, a1, zero
800BEB6C	lhu    v0, $001e(t2)
800BEB70	subu   v1, a1, a0
800BEB74	j      Lbeb90 [$800beb90]
800BEB78	subu   a3, zero, v0

Lbeb7c:	; 800BEB7C
800BEB7C	slti   v0, a2, $fff1 (=-$f)
800BEB80	beq    v0, zero, Lbeb94 [$800beb94]
800BEB84	sll    v0, v1, $10
800BEB88	addu   v1, a1, a0
800BEB8C	lhu    a3, $001e(t2)

Lbeb90:	; 800BEB90
800BEB90	sll    v0, v1, $10

Lbeb94:	; 800BEB94
800BEB94	sra    a0, v0, $10
800BEB98	addu   v0, a0, s3
800BEB9C	slti   v0, v0, $fff1 (=-$f)
800BEBA0	bne    v0, zero, Lbec9c [$800bec9c]
800BEBA4	addiu  v0, t0, $0001
800BEBA8	slt    v0, a0, s2

Lbebac:	; 800BEBAC
800BEBAC	beq    v0, zero, Lbec9c [$800bec9c]
800BEBB0	addiu  v0, t0, $0001
800BEBB4	sll    v0, t0, $10
800BEBB8	sra    a1, v0, $10
800BEBBC	sll    v0, a1, $02

Lbebc0:	; 800BEBC0
800BEBC0	addu   v0, v0, t3
800BEBC4	lw     v0, $0000(v0)
800BEBC8	nop
800BEBCC	srl    v0, v0, $0c
800BEBD0	andi   v0, v0, $03ff
800BEBD4	addu   v0, t5, v0
800BEBD8	addu   a2, a3, v0
800BEBDC	sll    v0, a2, $10
800BEBE0	sra    a0, v0, $10
800BEBE4	slti   v0, a0, $fff1 (=-$f)
800BEBE8	bne    v0, zero, Lbec9c [$800bec9c]
800BEBEC	addiu  v0, t0, $0001
800BEBF0	slt    v0, a0, s6
800BEBF4	beq    v0, zero, Lbec9c [$800bec9c]
800BEBF8	addiu  v0, t0, $0001
800BEBFC	sll    v0, a1, $01
800BEC00	addu   v0, v0, a1
800BEC04	sll    v0, v0, $03
800BEC08	addu   v0, v0, t4
800BEC0C	addu   v1, v1, t8
800BEC10	sh     v1, $0010(v0)
800BEC14	sh     a2, $0012(v0)

Lbec18:	; 800BEC18
800BEC18	sll    v0, t0, $10
800BEC1C	sra    v1, v0, $10
800BEC20	sll    v0, v1, $02
800BEC24	addu   v0, v0, t3
800BEC28	lhu    v0, $0000(v0)
800BEC2C	nop
800BEC30	andi   v0, v0, $0fff
800BEC34	addu   a1, s4, v0
800BEC38	addiu  v0, a1, $fff8 (=-$8)
800BEC3C	andi   v0, v0, $ffff
800BEC40	sltiu  v0, v0, $0ff1
800BEC44	beq    v0, zero, Lbec9c [$800bec9c]
800BEC48	addiu  v0, t0, $0001
800BEC4C	sll    a0, v1, $01
800BEC50	addu   a0, a0, v1

Lbec54:	; 800BEC54
800BEC54	sll    a0, a0, $03
800BEC58	addu   a0, a0, t4
800BEC5C	sll    a1, a1, $10
800BEC60	sra    a1, a1, $0e
800BEC64	addu   a1, a1, s5
800BEC68	lui    a2, $ff00
800BEC6C	lw     v1, $0000(a0)
800BEC70	lw     v0, $0000(a1)
800BEC74	and    v1, v1, a2
800BEC78	and    v0, v0, t1
800BEC7C	or     v1, v1, v0
800BEC80	sw     v1, $0000(a0)
800BEC84	lw     v0, $0000(a1)
800BEC88	and    a0, a0, t1
800BEC8C	and    v0, v0, a2
800BEC90	or     v0, v0, a0
800BEC94	sw     v0, $0000(a1)
800BEC98	addiu  v0, t0, $0001

Lbec9c:	; 800BEC9C
800BEC9C	addu   t0, v0, zero
800BECA0	sll    v0, v0, $10
800BECA4	sra    v0, v0, $10
800BECA8	sltu   v0, v0, t9
800BECAC	bne    v0, zero, Lbea34 [$800bea34]
800BECB0	nop
800BECB4	j      Lbedb8 [$800bedb8]
800BECB8	sh     t6, $0018(t2)

Lbecbc:	; 800BECBC
800BECBC	beq    v0, zero, Lbedb4 [$800bedb4]
800BECC0	addu   t0, zero, zero
800BECC4	lui    t1, $00ff
800BECC8	ori    t1, t1, $ffff
800BECCC	lui    t7, $ff00
800BECD0	sll    v0, t0, $10

loopbecd4:	; 800BECD4
800BECD4	sra    a2, v0, $10
800BECD8	sll    v0, a2, $02
800BECDC	addu   a0, v0, t3
800BECE0	lw     v1, $0000(a0)
800BECE4	nop
800BECE8	srl    v0, v1, $16

Lbecec:	; 800BECEC
800BECEC	addu   a3, t6, v0
800BECF0	addiu  v0, a3, $000f
800BECF4	andi   v0, v0, $ffff

Lbecf8:	; 800BECF8
800BECF8	sltiu  v0, v0, $014f
800BECFC	beq    v0, zero, Lbed9c [$800bed9c]
800BED00	addiu  v0, t0, $0001
800BED04	srl    v0, v1, $0c
800BED08	andi   v0, v0, $03ff
800BED0C	addu   v1, t5, v0
800BED10	addiu  v0, v1, $000f
800BED14	andi   v0, v0, $ffff
800BED18	sltiu  v0, v0, $00ef
800BED1C	beq    v0, zero, Lbed9c [$800bed9c]
800BED20	addiu  v0, t0, $0001
800BED24	lhu    v0, $0000(a0)
800BED28	nop
800BED2C	andi   v0, v0, $0fff
800BED30	addu   a1, s4, v0
800BED34	addiu  v0, a1, $fff8 (=-$8)
800BED38	andi   v0, v0, $ffff
800BED3C	sltiu  v0, v0, $0ff1
800BED40	beq    v0, zero, Lbed9c [$800bed9c]
800BED44	addiu  v0, t0, $0001
800BED48	sll    a0, a2, $01
800BED4C	addu   a0, a0, a2
800BED50	sll    a0, a0, $03
800BED54	addu   a0, a0, t4
800BED58	sll    a1, a1, $10
800BED5C	sra    a1, a1, $0e
800BED60	sh     v1, $0012(a0)
800BED64	lw     v1, $0000(a0)
800BED68	addu   a1, a1, s5
800BED6C	sh     a3, $0010(a0)
800BED70	lw     v0, $0000(a1)
800BED74	and    v1, v1, t7
800BED78	and    v0, v0, t1
800BED7C	or     v1, v1, v0
800BED80	sw     v1, $0000(a0)
800BED84	lw     v0, $0000(a1)
800BED88	and    a0, a0, t1
800BED8C	and    v0, v0, t7
800BED90	or     v0, v0, a0
800BED94	sw     v0, $0000(a1)
800BED98	addiu  v0, t0, $0001

Lbed9c:	; 800BED9C
800BED9C	addu   t0, v0, zero
800BEDA0	sll    v0, v0, $10
800BEDA4	sra    v0, v0, $10
800BEDA8	sltu   v0, v0, t9
800BEDAC	bne    v0, zero, loopbecd4 [$800becd4]
800BEDB0	sll    v0, t0, $10

Lbedb4:	; 800BEDB4
800BEDB4	sh     t6, $0018(t2)

Lbedb8:	; 800BEDB8
[T2 + 1a] = h(T5);

return 1;
////////////////////////////////