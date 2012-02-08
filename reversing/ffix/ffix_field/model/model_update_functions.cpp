////////////////////////////////
// funcb3294
if( bu[A0 + 9] != 0 )
{
    start = A0 + bu[A0 + 6] * c + c;
    pointer = start + bu[A0 + 9] * 8 - 8;

    loopb32d0:	; 800B32D0
        if( hu[pointer] == A1 )
        {
            return pointer;
        }

        pointer = pointer - 8;
        V0 = pointer < start;
    800B32E8	beq    v0, zero, loopb32d0 [$800b32d0]
}

return 0;
////////////////////////////////



////////////////////////////////
// funcad488
S2 = A0;
data = A1;
S1 = A2;

if( w[data + 0] & 00000020 )
{
    A0 = w[S2 + 4] & 0fff;
    system_get_cos_by_rotation;
    S0 = V0;

    S0 = w[S2 + 4] & 0fff;
    system_get_sin_by_rotation;

    V1 = w[S2] >> 8;
    V1 = V1 & 0fff;
    V1 = S0 * V1;
    [S1 + 6] = h(0);
    V1 = V1 >> c;
    800AD4F8	sh     v1, $0000(s1)
    800AD4FC	lw     v1, $0000(s2)
    800AD500	subu   a1, zero, v0
    800AD504	srl    v1, v1, $08
    800AD508	andi   v1, v1, $0fff
    800AD50C	mult   a1, v1
    800AD510	sh     zero, $0002(s1)
    800AD514	sh     zero, $000e(s1)
    800AD518	addiu  v1, zero, $1000
    800AD51C	sh     v1, $0008(s1)
    800AD520	mflo   t0
    800AD524	sra    v1, t0, $0c
    800AD528	sh     v1, $000c(s1)
    800AD52C	lw     v1, $0000(s2)
    800AD530	nop
    800AD534	srl    v1, v1, $14
    800AD538	mult   v0, v1
    800AD53C	sh     zero, $000a(s1)
    800AD540	mflo   v1
    800AD544	sra    v1, v1, $0c
    800AD548	sh     v1, $0004(s1)
    800AD54C	lw     v1, $0000(s2)
    800AD550	nop
    800AD554	srl    v1, v1, $14
    800AD558	mult   s0, v1
    800AD55C	mflo   v1
    800AD560	sra    v1, v1, $0c
    800AD564	sh     v1, $0010(s1)
    800AD568	lw     a0, $0004(s2)
    800AD56C	nop
    800AD570	sll    v1, a0, $0a
    800AD574	sra    v1, v1, $16
    800AD578	mult   s0, v1
    800AD57C	mflo   a2
    800AD580	sra    a0, a0, $16
    800AD584	nop
    800AD588	mult   v0, a0
    V1 = w[data + c];
    800AD594	lw     v1, $0014(v1)
    800AD598	mflo   t0
    800AD59C	addu   v0, a2, t0
    800AD5A0	sra    v0, v0, $0c
    800AD5A4	addu   v0, v0, v1
    800AD5A8	sw     v0, $0014(s1)
    V0 = w[data + c];
    800AD5B4	lw     v0, $0018(v0)
    800AD5B8	nop
    800AD5BC	sw     v0, $0018(s1)
    800AD5C0	lw     v1, $0004(s2)
    800AD5C4	nop
    800AD5C8	sll    v0, v1, $0a
    800AD5CC	sra    v0, v0, $16
    800AD5D0	mult   a1, v0
    800AD5D4	mflo   v0
    800AD5D8	sra    v1, v1, $16
    800AD5DC	nop
    800AD5E0	mult   s0, v1
    V1 = w[data + c];
    800AD5EC	lw     v1, $001c(v1)
    800AD5F0	mflo   t0
    800AD5F8	addu   v0, v0, t0
}
else
{
    V0 = w[data + 8];
    V0 = w[V0 + 20];

    800AD60C	addiu  v1, v0, $0020
    800AD610	lw     a1, $0020(v0)
    800AD614	lw     v0, $0004(v1)
    800AD618	addiu  a0, sp, $0010
    800AD61C	sw     v0, $0004(a0)
    800AD620	lw     v0, $0008(v1)
    800AD624	nop
    800AD628	sw     v0, $0008(a0)
    800AD62C	lw     v0, $000c(v1)
    800AD630	nop
    800AD634	sw     v0, $000c(a0)
    800AD638	lw     v0, $0010(v1)
    800AD63C	nop
    800AD640	sw     v0, $0010(a0)
    800AD644	lw     v0, $0014(v1)
    800AD648	nop
    800AD64C	sw     v0, $0014(a0)
    800AD650	lw     v0, $0018(v1)
    800AD654	nop
    800AD658	sw     v0, $0018(a0)
    800AD65C	lw     v0, $001c(v1)
    800AD660	sw     a1, $0010(sp)
    800AD664	sw     v0, $001c(a0)
    800AD668	addiu  v0, zero, $f000 (=-$1000)
    800AD66C	sw     zero, $002c(sp)
    800AD670	sw     zero, $0028(sp)
    800AD674	sw     zero, $0024(sp)
    800AD678	sh     zero, $0030(sp)
    800AD67C	sh     v0, $0032(sp)
    800AD680	sh     zero, $0034(sp)
    800AD684	lw     t4, $0000(a0)
    800AD688	lw     t5, $0004(a0)
    800AD68C	ctc2   t4,vxy0
    800AD690	ctc2   t5,vz0
    800AD694	lw     t4, $0008(a0)
    800AD698	lw     t5, $000c(a0)
    800AD69C	lw     t6, $0010(a0)
    800AD6A0	ctc2   t4,vxy1
    800AD6A4	ctc2   t5,vz1
    800AD6A8	ctc2   t6,vxy2
    800AD6AC	lw     t4, $0014(a0)
    800AD6B0	lw     t5, $0018(a0)
    800AD6B4	ctc2   t4,vz2
    800AD6B8	lw     t6, $001c(a0)
    800AD6BC	ctc2   t5,rgb
    800AD6C0	ctc2   t6,otz
    800AD6C4	addiu  v0, sp, $0030
    800AD6C8	lwc2   zero, $0000(v0)
    800AD6CC	lwc2   at, $0004(v0)
    800AD6D0	nop
    800AD6D4	nop
    800AD6D8	gte_func18t0,r11r12
    800AD6DC	addiu  a0, sp, $0038
    800AD6E0	swc2   t9, $0000(a0)
    800AD6E4	swc2   k0, $0004(a0)
    800AD6E8	swc2   k1, $0008(a0)
    800AD6EC	addiu  s0, sp, $0068
    800AD6F0	addu   a1, s0, zero
    800AD6F4	jal    system_normalize_vector_A0_to_A1 [$80062c2c]
    800AD6F8	sw     zero, $003c(sp)
    800AD6FC	lw     v1, $0068(sp)
    800AD700	addiu  v0, zero, $1000
    800AD704	sw     v0, $005c(sp)
    800AD708	lw     v0, $006c(sp)
    800AD70C	sw     zero, $0058(sp)
    800AD710	sw     zero, $0060(sp)
    800AD714	subu   v1, zero, v1
    800AD718	sw     v1, $0068(sp)
    800AD71C	lw     v1, $0070(sp)
    800AD720	subu   v0, zero, v0
    800AD724	sw     v0, $006c(sp)
    800AD728	addiu  v0, sp, $0058
    800AD72C	subu   v1, zero, v1
    800AD730	sw     v1, $0070(sp)
    800AD734	lw     t4, $0000(v0)
    800AD738	lw     t5, $0004(v0)
    800AD73C	ctc2   t4,vxy0
    800AD740	lw     t6, $0008(v0)
    800AD744	ctc2   t5,vxy1
    800AD748	ctc2   t6,vxy2
    800AD74C	lwc2   t3, $0008(s0)
    800AD750	lwc2   t1, $0000(s0)
    800AD754	lwc2   t2, $0004(s0)
    800AD758	nop
    800AD75C	nop
    800AD760	gte_func27t8,r11r12
    800AD764	addiu  v0, sp, $0048
    800AD768	swc2   t9, $0000(v0)
    800AD76C	swc2   k0, $0004(v0)
    800AD770	swc2   k1, $0008(v0)
    800AD774	lw     v0, $0000(s2)
    800AD778	lw     v1, $0048(sp)
    800AD77C	srl    v0, v0, $08
    800AD780	andi   v0, v0, $0fff
    800AD784	mult   v1, v0
    800AD788	mflo   v1
    800AD78C	sra    v0, v1, $0c
    800AD790	sh     v0, $0000(s1)
    800AD794	lw     v0, $0000(s2)
    800AD798	lw     v1, $004c(sp)
    800AD79C	srl    v0, v0, $08
    800AD7A0	andi   v0, v0, $0fff
    800AD7A4	mult   v1, v0
    800AD7A8	mflo   v1
    800AD7AC	sra    v0, v1, $0c
    800AD7B0	sh     v0, $0006(s1)
    800AD7B4	lw     v0, $0000(s2)
    800AD7B8	lw     v1, $0050(sp)
    800AD7BC	srl    v0, v0, $08
    800AD7C0	andi   v0, v0, $0fff
    800AD7C4	mult   v1, v0
    800AD7C8	mflo   v1
    800AD7CC	sra    v0, v1, $0c
    800AD7D0	sh     v0, $000c(s1)
    800AD7D4	lhu    v0, $0058(sp)
    800AD7D8	nop
    800AD7DC	sh     v0, $0002(s1)
    800AD7E0	lhu    v0, $005c(sp)
    800AD7E4	nop
    800AD7E8	sh     v0, $0008(s1)
    800AD7EC	lhu    v0, $0060(sp)
    800AD7F0	nop
    800AD7F4	sh     v0, $000e(s1)
    800AD7F8	lw     v0, $0000(s2)
    800AD7FC	lw     v1, $0068(sp)
    800AD800	srl    v0, v0, $14
    800AD804	mult   v1, v0
    800AD808	mflo   v1
    800AD80C	sra    v0, v1, $0c
    800AD810	sh     v0, $0004(s1)
    800AD814	lw     v0, $0000(s2)
    800AD818	lw     v1, $006c(sp)
    800AD81C	srl    v0, v0, $14
    800AD820	mult   v1, v0
    800AD824	mflo   v1
    800AD828	sra    v0, v1, $0c
    800AD82C	sh     v0, $000a(s1)
    800AD830	lw     v0, $0000(s2)
    800AD834	lw     v1, $0070(sp)
    800AD838	srl    v0, v0, $14
    800AD83C	mult   v1, v0
    800AD840	mflo   v1
    800AD844	sra    v0, v1, $0c
    800AD848	sh     v0, $0010(s1)
    800AD84C	lw     v1, $0004(s2)
    800AD850	lw     a0, $0048(sp)
    800AD854	sll    v0, v1, $0a
    800AD858	sra    v0, v0, $16
    800AD85C	mult   a0, v0
    800AD860	mflo   a0
    800AD864	lw     v0, $0068(sp)
    800AD868	sra    v1, v1, $16
    800AD86C	mult   v0, v1
    V0 = w[data + 8];
    800AD878	lw     v1, $0020(v0)
    800AD87C	nop
    800AD880	lw     v1, $0034(v1)
    800AD884	mflo   t0
    800AD888	addu   v0, a0, t0
    800AD88C	sra    v0, v0, $0c
    800AD890	addu   v0, v0, v1
    800AD894	sw     v0, $0014(s1)
    800AD898	lw     v1, $0004(s2)
    800AD89C	lw     a0, $004c(sp)
    800AD8A0	sll    v0, v1, $0a
    800AD8A4	sra    v0, v0, $16
    800AD8A8	mult   a0, v0
    800AD8AC	mflo   a0
    800AD8B0	lw     v0, $006c(sp)
    800AD8B4	sra    v1, v1, $16
    800AD8B8	mult   v0, v1
    V1 = w[data + c];
    800AD8C4	lw     v1, $0018(v1)
    800AD8C8	mflo   t0
    800AD8CC	addu   v0, a0, t0
    800AD8D0	sra    v0, v0, $0c
    800AD8D4	addu   v0, v0, v1
    800AD8D8	sw     v0, $0018(s1)
    800AD8DC	lw     v1, $0004(s2)
    800AD8E0	lw     a0, $0050(sp)
    800AD8E4	sll    v0, v1, $0a
    800AD8E8	sra    v0, v0, $16
    800AD8EC	mult   a0, v0
    800AD8F0	mflo   a0
    800AD8F4	lw     v0, $0070(sp)
    800AD8F8	sra    v1, v1, $16
    T0 = V0 * V1;
    model_data = w[data + 8];
    V1 = w[model_data + 20];
    V1 = w[V1 + 3c];
    V0 = A0 + T0;
}

[S1 + 1c] = w(V1 + V0 >> c);
////////////////////////////////



////////////////////////////////
// funcac6c0
FP = A0 + A1 * 28;

A0 = A1;
func1e350; // get +8e0 or +8d8 model struct
S1 = V0;

[SP + 70] = w(0);

if( ( w[S1 + 0] & 00000010 ) == 0 )
{
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    V0 = w[V0 + 8e4];
    V0 = w[V0 + c];
    V0 = w[V0 + 14];
    S0 = w[V0 + 1c];

    if( S0 != 0 )
    {
        A0 = S0;
        A1 = w[S1 + 4];
        funcb3294;

        if( V0 == 0 )
        {
            A0 = S0;
            A1 = -1;
            funcb3294;
        }

        [SP + 70] = w(b[V0 + 7]);
    }



    A0 = FP;
    A1 = S1;
    A2 = SP + 10;
    funcad488;

    800AC790	lui    a3, $8006
    800AC794	lw     v0, $794c(a3)
    800AC798	nop
    800AC79C	lw     v0, $001c(v0)
    800AC7A0	nop
    800AC7A4	lw     v0, $08e4(v0)
    800AC7A8	nop
    800AC7AC	lw     v0, $000c(v0)
    800AC7B0	nop
    800AC7B4	lw     v0, $0014(v0)
    800AC7B8	nop
    800AC7BC	lh     v1, $0050(v0)
    800AC7C0	nop
    800AC7C4	bgez   v1, Lac7d0 [$800ac7d0]
    800AC7C8	addu   a1, v1, zero
    800AC7CC	addiu  a1, v1, $003f

    Lac7d0:	; 800AC7D0
    800AC7D0	lh     a0, $0052(v0)
    800AC7D4	sra    v0, a1, $06
    800AC7D8	sll    v0, v0, $06
    800AC7DC	subu   v0, v1, v0
    800AC7E0	sll    v0, v0, $10
    800AC7E4	sra    s3, v0, $0f
    800AC7E8	bgez   a0, Lac7f4 [$800ac7f4]
    800AC7EC	addu   a2, a0, zero
    800AC7F0	addiu  a2, a0, $00ff

    Lac7f4:	; 800AC7F4
    800AC7F4	addu   s5, zero, zero
    800AC7F8	addiu  s4, s3, $001f
    800AC7FC	sra    v0, a2, $08
    800AC800	sll    v0, v0, $08
    800AC804	subu   v0, a0, v0
    800AC808	sll    v0, v0, $10
    800AC80C	sra    s1, v0, $10
    800AC810	addiu  s2, s1, $001f
    800AC818	addu   s7, s5, zero

    S0 = SP + 30;
    Lac81c:	; 800AC81C
        V0 = w[8006794c];
        A0 = w[V0 + 1c];
        V0 = w[A0 + 8e4];
        V0 = w[V0 + 0] & 00000200;

        S6 = 0;
        if( V0 != 0 )
        {
            V1 = e6000002;
            V0 = FP + S7 + bu[A0 + 8] * 10;
            S6 = w[V0 + 8];
            [S6 + 3] = b(2);
            V0 = S6 + c;
            [S6 = 4] = w(V1);
            [S6 + 8] = w(0);
        }
        else
        {
            V0 = FP + S7 + bu[A0 + 8] * 10;
            V0 = w[V0 + 8];
        }

        [S0] = w(V0);
        800AC8A0	lw     v1, $0000(s0)
        800AC8A4	addiu  v0, zero, $0009
        800AC8A8	sb     v0, $0003(v1)
        800AC8AC	lw     v1, $0000(s0)
        800AC8B0	addiu  v0, zero, $002c
        800AC8B4	sb     v0, $0007(v1)
        800AC8B8	lw     v1, $0000(s0)
        800AC8BC	nop
        800AC8C0	lbu    v0, $0007(v1)
        800AC8C4	nop
        800AC8C8	ori    v0, v0, $0002
        800AC8CC	sb     v0, $0007(v1)
        800AC8D0	lw     v1, $0000(s0)
        800AC8D4	lbu    v0, $0000(fp)
        800AC8D8	nop
        800AC8DC	sb     v0, $0004(v1)
        800AC8E0	lw     v1, $0000(s0)
        800AC8E4	lbu    v0, $0000(fp)
        800AC8E8	nop
        800AC8EC	sb     v0, $0005(v1)
        800AC8F0	lw     v1, $0000(s0)
        800AC8F4	lbu    v0, $0000(fp)
        800AC8F8	lui    t1, $8006
        800AC8FC	sb     v0, $0006(v1)
        800AC900	lw     v0, $794c(t1)
        800AC904	nop
        800AC908	lw     v0, $001c(v0)
        800AC90C	nop
        800AC910	lw     v0, $08e4(v0)
        800AC914	nop
        800AC918	lw     v0, $000c(v0)
        800AC91C	nop
        800AC920	lw     v0, $0014(v0)
        800AC924	nop
        800AC928	lhu    a0, $0052(v0)
        800AC92C	lhu    v0, $0050(v0)
        800AC930	andi   v1, a0, $0100
        800AC934	sll    v1, v1, $10
        800AC938	sra    v1, v1, $14
        800AC93C	andi   v0, v0, $03ff
        800AC940	srl    v0, v0, $06
        800AC944	ori    v0, v0, $00c0
        800AC948	or     v1, v1, v0
        800AC94C	andi   a0, a0, $0200
        800AC950	sll    a0, a0, $02
        800AC954	lw     v0, $0000(s0)
        800AC958	or     v1, v1, a0
        800AC95C	sh     v1, $0016(v0)
        800AC960	lw     v1, $0000(s0)
        800AC964	addiu  v0, zero, $3fd0
        800AC968	sh     v0, $000e(v1)
        800AC96C	addiu  v0, zero, $0001
        800AC970	beq    s5, v0, Laca08 [$800aca08]
        800AC974	slti   v0, s5, $0002
        800AC978	beq    v0, zero, Lac990 [$800ac990]
        800AC97C	addiu  v0, zero, $0002
        800AC980	beq    s5, zero, Lac9a8 [$800ac9a8]
        800AC984	nop
        800AC988	j      Lacb28 [$800acb28]
        800AC98C	nop

        Lac990:	; 800AC990
        800AC990	beq    s5, v0, Laca68 [$800aca68]
        800AC994	addiu  v0, zero, $0003
        800AC998	beq    s5, v0, Lacac8 [$800acac8]
        800AC99C	lui    t1, $8006
        800AC9A0	j      Lacb2c [$800acb2c]
        800AC9A4	nop

        Lac9a8:	; 800AC9A8
        V0 = w[SP + 30];
        [V0 + c] = b(S3);
        [V0 + d] = b(S1);
        [V0 + 14] = b(S4);
        [V0 + 15] = b(S1);
        [V0 + 1c] = b(S3);
        [V0 + 1d] = b(S2);
        [V0 + 24] = b(S4);
        [V0 + 25] = b(S2);
        800ACA00	j      Lacb28 [$800acb28]

        Laca08:	; 800ACA08
        V0 = w[SP + 34];
        [V0 + c] = b(S4);
        [V0 + d] = b(S1);
        [V0 + 14] = b(S3);
        [V0 + 15] = b(S1);
        [V0 + 1c] = b(S4);
        [V0 + 1d] = b(S2);
        [V0 + 24] = b(S3);
        [V0 + 25] = b(S2);
        800ACA60	j      Lacb28 [$800acb28]

        Laca68:	; 800ACA68
        V0 = w[SP + 38];
        [V0 + c] = b(S3);
        [V0 + d] = b(S2);
        [V0 + 14] = b(S4);
        [V0 + 15] = b(S2);
        [V0 + 1c] = b(S3);
        [V0 + 1d] = b(S1);
        [V0 + 24] = b(S4);
        [V0 + 25] = b(S1);
        800ACAC0	j      Lacb28 [$800acb28]

        Lacac8:	; 800ACAC8
        V0 = w[SP + 3c];
        [V0 + c] = b(S4);
        [V0 + d] = b(S2);
        [V0 + 14] = b(S3);
        [V0 + 15] = b(S2);
        [V0 + 1c] = b(S4);
        [V0 + 1d] = b(S1);
        [V0 + 24] = b(S3);
        [V0 + 25] = b(S1);

        Lacb28:	; 800ACB28
        800ACB28	lui    t1, $8006

        Lacb2c:	; 800ACB2C
        800ACB2C	lw     v0, $794c(t1)
        800ACB30	nop
        800ACB34	lw     v0, $001c(v0)
        800ACB38	nop
        800ACB3C	lw     v0, $08e4(v0)
        800ACB40	nop
        800ACB44	lw     v0, $0000(v0)
        800ACB48	nop
        800ACB4C	andi   v0, v0, $0200
        if( V0 != 0 )
        {
            V1 = e6000002;
            800ACB5C	lw     a1, $0000(s0)
            800ACB60	addiu  v0, zero, $0002
            800ACB64	addiu  a1, a1, $0028
            800ACB68	sb     v0, $0003(a1)
            800ACB6C	sw     v1, $0004(a1)
            800ACB70	sw     zero, $0008(a1)
            A0 = w[S0];
            800ACB78	jal    func62b4c [$80062b4c]
            800ACB7C	nop

            A0 = S6;
            A1 = w[S0];
            800ACB84	jal    func62b4c [$80062b4c]
        }

        S7 = S7 + 4;
        S0 = S0 + 4;
        S5 = S5 + 1;
        V0 = S5 < 4;
    800ACB98	bne    v0, zero, Lac81c [$800ac81c]

    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    R11R12 = w[V0 + 18];
    R13R21 = w[V0 + 1c];
    R22R23 = w[V0 + 20];
    R31R32 = w[V0 + 24];
    R33 = w[V0 + 28];

    V1 = SP + 10;
    IR1 = hu[V1 + 0];
    IR2 = hu[V1 + 6];
    IR3 = hu[V1 + c];
    gte_rtir12; // ir * rotmatrix.

    800ACC08	mfc2   t4,l13l21
    800ACC0C	mfc2   t5,l22l23
    800ACC10	mfc2   t6,l31l32
    800ACC14	sh     t4, $0000(v1)
    800ACC18	sh     t5, $0006(v1)
    800ACC1C	sh     t6, $000c(v1)


    800ACC20	addiu  v0, sp, $0012
    800ACC24	lhu    t4, $0000(v0)
    800ACC28	lhu    t5, $0006(v0)
    800ACC2C	lhu    t6, $000c(v0)
    800ACC30	mtc2   t4,l13l21
    800ACC34	mtc2   t5,l22l23
    800ACC38	mtc2   t6,l31l32
    800ACC3C	nop
    800ACC40	nop
    800ACC44	gte_func18t1,dqb
    800ACC48	mfc2   t4,l13l21
    800ACC4C	mfc2   t5,l22l23
    800ACC50	mfc2   t6,l31l32
    800ACC54	sh     t4, $0000(v0)
    800ACC58	sh     t5, $0006(v0)
    800ACC5C	sh     t6, $000c(v0)
    800ACC60	addiu  v0, sp, $0014
    800ACC64	lhu    t4, $0000(v0)
    800ACC68	lhu    t5, $0006(v0)
    800ACC6C	lhu    t6, $000c(v0)
    800ACC70	mtc2   t4,l13l21
    800ACC74	mtc2   t5,l22l23
    800ACC78	mtc2   t6,l31l32
    800ACC7C	nop
    800ACC80	nop
    800ACC84	gte_func18t1,dqb
    800ACC88	mfc2   t4,l13l21
    800ACC8C	mfc2   t5,l22l23
    800ACC90	mfc2   t6,l31l32
    800ACC94	sh     t4, $0000(v0)
    800ACC98	sh     t5, $0006(v0)
    800ACC9C	sh     t6, $000c(v0)
    V0 = w[8006794c];
    V0 = w[V0 + 1c] + 18;

    800ACCB4	lw     t4, $0014(v0)
    800ACCB8	lw     t5, $0018(v0)
    800ACCBC	ctc2   t4,vz2
    800ACCC0	lw     t6, $001c(v0)
    800ACCC4	ctc2   t5,rgb
    800ACCC8	ctc2   t6,otz

    V0 = SP + 24;

    800ACCD0	lhu    t5, $0004(v0)
    800ACCD4	lhu    t4, $0000(v0)
    800ACCD8	sll    t5, t5, $10
    800ACCDC	or     t4, t4, t5
    800ACCE0	mtc2   t4,r11r12
    800ACCE4	lwc2   at, $0008(v0)
    800ACCE8	nop
    800ACCEC	nop
    800ACCF0	gte_func18t0,r11r12
    800ACCF4	swc2   t1, $0000(v0)
    800ACCF8	swc2   t2, $0004(v0)
    800ACCFC	swc2   t3, $0008(v0)
    800ACD00	lw     t4, $0000(v1)
    800ACD04	lw     t5, $0004(v1)
    800ACD08	ctc2   t4,vxy0
    800ACD0C	ctc2   t5,vz0
    800ACD10	lw     t4, $0008(v1)
    800ACD14	lw     t5, $000c(v1)
    800ACD18	lw     t6, $0010(v1)
    800ACD1C	ctc2   t4,vxy1
    800ACD20	ctc2   t5,vz1
    800ACD24	ctc2   t6,vxy2
    800ACD28	lw     t4, $0014(v1)
    800ACD2C	lw     t5, $0018(v1)
    800ACD30	ctc2   t4,vz2
    800ACD34	lw     t6, $001c(v1)
    800ACD38	ctc2   t5,rgb
    800ACD3C	ctc2   t6,otz
    800ACD40	addiu  a1, zero, $f000 (=-$1000)
    800ACD44	addiu  a0, zero, $1000
    800ACD48	addiu  v1, sp, $0040
    800ACD4C	sh     a1, $0040(sp)
    800ACD50	sh     zero, $0042(sp)
    800ACD54	sh     a0, $0044(sp)
    800ACD58	lwc2   zero, $0000(v1)
    800ACD5C	lwc2   at, $0004(v1)
    800ACD60	nop
    800ACD64	nop
    800ACD68	gte_func16t8,r11r12
    800ACD6C	lw     v0, $0030(sp)
    800ACD70	nop
    800ACD74	addiu  v0, v0, $0008
    800ACD78	swc2   t6, $0000(v0)
    800ACD7C	addiu  v0, sp, $0048
    800ACD80	swc2   s3, $0000(v0)
    800ACD84	sh     zero, $0040(sp)
    800ACD88	sh     zero, $0042(sp)
    800ACD8C	sh     a0, $0044(sp)
    800ACD90	lwc2   zero, $0000(v1)
    800ACD94	lwc2   at, $0004(v1)
    800ACD98	nop
    800ACD9C	nop
    800ACDA0	gte_func16t8,r11r12
    800ACDA4	lw     v0, $0030(sp)
    800ACDA8	nop
    800ACDAC	addiu  v0, v0, $0010
    800ACDB0	swc2   t6, $0000(v0)
    800ACDB4	lw     v0, $0034(sp)
    800ACDB8	nop
    800ACDBC	addiu  v0, v0, $0008
    800ACDC0	swc2   t6, $0000(v0)
    800ACDC4	addiu  v0, sp, $004c
    800ACDC8	swc2   s3, $0000(v0)
    800ACDCC	sh     a0, $0040(sp)
    800ACDD0	sh     zero, $0042(sp)
    800ACDD4	sh     a0, $0044(sp)
    800ACDD8	lwc2   zero, $0000(v1)
    800ACDDC	lwc2   at, $0004(v1)
    800ACDE0	nop
    800ACDE4	nop
    800ACDE8	gte_func16t8,r11r12
    800ACDEC	lw     v0, $0034(sp)
    800ACDF0	nop
    800ACDF4	addiu  v0, v0, $0010
    800ACDF8	swc2   t6, $0000(v0)
    800ACDFC	addiu  v0, sp, $0050
    800ACE00	swc2   s3, $0000(v0)
    800ACE04	sh     a1, $0040(sp)
    800ACE08	sh     zero, $0042(sp)
    800ACE0C	sh     zero, $0044(sp)
    800ACE10	lwc2   zero, $0000(v1)
    800ACE14	lwc2   at, $0004(v1)
    800ACE18	nop
    800ACE1C	nop
    800ACE20	gte_func16t8,r11r12
    800ACE24	lw     v0, $0030(sp)
    800ACE28	nop
    800ACE2C	addiu  v0, v0, $0018
    800ACE30	swc2   t6, $0000(v0)
    800ACE34	lw     v0, $0038(sp)
    800ACE38	nop
    800ACE3C	addiu  v0, v0, $0008
    800ACE40	swc2   t6, $0000(v0)
    800ACE44	addiu  v0, sp, $0054
    800ACE48	swc2   s3, $0000(v0)
    800ACE4C	sh     zero, $0040(sp)
    800ACE50	sh     zero, $0042(sp)
    800ACE54	sh     zero, $0044(sp)
    800ACE58	lwc2   zero, $0000(v1)
    800ACE5C	lwc2   at, $0004(v1)
    800ACE60	nop
    800ACE64	nop
    800ACE68	gte_func16t8,r11r12
    800ACE6C	lw     v0, $0030(sp)
    800ACE70	nop
    800ACE74	addiu  v0, v0, $0020
    800ACE78	swc2   t6, $0000(v0)
    800ACE7C	lw     v0, $0034(sp)
    800ACE80	nop
    800ACE84	addiu  v0, v0, $0018
    800ACE88	swc2   t6, $0000(v0)
    800ACE8C	lw     v0, $0038(sp)
    800ACE90	nop
    800ACE94	addiu  v0, v0, $0010
    800ACE98	swc2   t6, $0000(v0)
    800ACE9C	lw     v0, $003c(sp)
    800ACEA0	nop
    800ACEA4	addiu  v0, v0, $0008
    800ACEA8	swc2   t6, $0000(v0)
    800ACEAC	addiu  v0, sp, $0058
    800ACEB0	swc2   s3, $0000(v0)
    800ACEB4	sh     a0, $0040(sp)
    800ACEB8	sh     zero, $0042(sp)
    800ACEBC	sh     zero, $0044(sp)
    800ACEC0	lwc2   zero, $0000(v1)
    800ACEC4	lwc2   at, $0004(v1)
    800ACEC8	nop
    800ACECC	nop
    800ACED0	gte_func16t8,r11r12

    V0 = w[SP + 34] + 20;
    800ACEE0	swc2   t6, $0000(v0)

    V0 = w[SP + 3c] + 10;
    800ACEF0	swc2   t6, $0000(v0)

    V0 = SP + 5c;
    800ACEF8	swc2   s3, $0000(v0)

    [SP + 40] = h(A1);
    [SP + 42] = h(0);
    [SP + 44] = h(A1);
    800ACF08	lwc2   zero, $0000(v1)
    800ACF0C	lwc2   at, $0004(v1)
    800ACF18	gte_func16t8,r11r12

    V0 = w[SP + 38] + 18;
    800ACF28	swc2   t6, $0000(v0)

    V0 = SP + 60;
    800ACF30	swc2   s3, $0000(v0)

    [SP + 40] = h(0);
    [SP + 42] = h(0);
    [SP + 44] = h(A1);
    800ACF40	lwc2   zero, $0000(v1)
    800ACF44	lwc2   at, $0004(v1)
    800ACF50	gte_func16t8,r11r12

    V0 = w[SP + 38] + 20;
    800ACF60	swc2   t6, $0000(v0)

    V0 = w[SP + 3c] + 18;
    800ACF70	swc2   t6, $0000(v0)

    [SP + 64] = w(SZ3);

    [SP + 40] = h(A0);
    [SP + 42] = h(0);
    [SP + 44] = h(A1);

    VXY0 = w[V1 + 0];
    VZ0 = w[V1 + 4];
    gte_RTPS; // Perspective transform

    V0 = w[SP + 3c] + 20;

    [V0 + 0] = w(SXY2);
    [SP + 68] = w(SZ3);

    A1 = w[SP + 48];

    V1 = w[SP + 4c];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 54];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 58];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    T0 = w[8006794c];

    A3 = w[T0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];

    800AD01C	sra    v1, a1, $02
    800AD020	lw     v0, $0014(v0)
    800AD024	lw     t1, $0070(sp)
    800AD028	lh     a0, $0030(v0)
    800AD02C	addu   a1, v1, t1
    800AD030	subu   v0, zero, a0
    800AD034	slt    v0, v0, a1
    if( V0 != 0 )
    {
        800AD03C	addiu  v0, zero, $1000
        800AD040	subu   v0, v0, a0
        800AD044	slt    v0, a1, v0
        if( V0 != 0 )
        {
            A2 = 00ffffff;
            800AD054	lbu    v0, $0008(a3)
            800AD058	sll    a1, a1, $02
            800AD05C	sll    v1, v0, $04
            800AD060	addu   v1, fp, v1
            800AD064	sll    v0, v0, $02
            800AD068	addu   v0, a3, v0
            800AD06C	lui    a3, $ff00
            800AD070	lw     v0, $0010(v0)
            800AD074	lw     a0, $0008(v1)
            800AD078	addu   v0, a1, v0
            800AD07C	lw     v1, $0000(a0)
            800AD080	lw     v0, $0000(v0)
            800AD084	and    v1, v1, a3
            800AD088	and    v0, v0, a2
            800AD08C	or     v1, v1, v0
            800AD090	sw     v1, $0000(a0)
            800AD094	lw     v0, $001c(t0)
            800AD098	nop
            800AD09C	lbu    a0, $0008(v0)
            800AD0A0	nop
            800AD0A4	sll    v1, a0, $02
            800AD0A8	addu   v0, v0, v1
            800AD0AC	sll    a0, a0, $04
            800AD0B0	lw     v0, $0010(v0)
            800AD0B4	addu   a0, fp, a0
            800AD0B8	addu   a1, a1, v0
            800AD0BC	lw     v1, $0000(a1)
            800AD0C0	lw     v0, $0008(a0)
            800AD0C4	and    v1, v1, a3
            800AD0C8	and    v0, v0, a2
            800AD0CC	or     v1, v1, v0
            800AD0D0	sw     v1, $0000(a1)
        }
    }

    A1 = w[SP + 4c];

    V1 = w[SP + 50];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 58];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 5c];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    T0 = w[8006794c];
    A3 = w[T0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];
    V1 = A1 >> 2;
    V0 = w[V0 + 14];
    T1 = w[SP + 70];
    A0 = h[V0 + 30];
    A1 = V1 + T1;
    V0 = 0 - A0;
    800AD154	slt    v0, v0, a1
    if( V0 != 0 )
    {
        800AD15C	addiu  v0, zero, $1000
        800AD160	subu   v0, v0, a0
        800AD164	slt    v0, a1, v0
        if( V0 != 0 )
        {
            A2 = 00ffffff;
            800AD174	lbu    v0, $0008(a3)
            800AD178	sll    a1, a1, $02
            800AD17C	sll    v1, v0, $04
            800AD180	addu   v1, fp, v1
            800AD184	sll    v0, v0, $02
            800AD188	addu   v0, a3, v0
            800AD18C	lui    a3, $ff00
            800AD190	lw     v0, $0010(v0)
            800AD194	lw     a0, $000c(v1)
            800AD198	addu   v0, a1, v0
            800AD19C	lw     v1, $0000(a0)
            800AD1A0	lw     v0, $0000(v0)
            800AD1A4	and    v1, v1, a3
            800AD1A8	and    v0, v0, a2
            800AD1AC	or     v1, v1, v0
            800AD1B0	sw     v1, $0000(a0)
            800AD1B4	lw     v0, $001c(t0)
            800AD1B8	nop
            800AD1BC	lbu    a0, $0008(v0)
            800AD1C0	nop
            800AD1C4	sll    v1, a0, $02
            800AD1C8	addu   v0, v0, v1
            800AD1CC	sll    a0, a0, $04
            800AD1D0	lw     v0, $0010(v0)
            800AD1D4	addu   a0, fp, a0
            800AD1D8	addu   a1, a1, v0
            800AD1DC	lw     v1, $0000(a1)
            800AD1E0	lw     v0, $000c(a0)
            800AD1E4	and    v1, v1, a3
            800AD1E8	and    v0, v0, a2
            800AD1EC	or     v1, v1, v0
            800AD1F0	sw     v1, $0000(a1)
        }
    }

    A1 = w[SP + 54];

    V1 = w[SP + 60];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 64];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    T0 = w[8006794c];
    A3 = w[T0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];
    V1 = A1 >> 2;
    V0 = w[V0 + 14];
    T1 = w[SP + 70];
    A0 = h[V0 + 30];
    A1 = V1 + T1;
    V0 = 0 - A0;
    V0 = V0 < A1;
    if( V0 != 0 )
    {
        V0 = 1000 - A0;
        V0 = A1 < V0;
        if( V0 != 0 )
        {
            A2 = 00ffffff;
            800AD27C	lbu    v0, $0008(a3)
            800AD280	sll    a1, a1, $02
            800AD284	sll    v1, v0, $04
            800AD288	addu   v1, fp, v1
            800AD28C	sll    v0, v0, $02
            800AD290	addu   v0, a3, v0
            800AD294	lui    a3, $ff00
            800AD298	lw     v0, $0010(v0)
            800AD29C	lw     a0, $0010(v1)
            800AD2A0	addu   v0, a1, v0
            800AD2A4	lw     v1, $0000(a0)
            800AD2A8	lw     v0, $0000(v0)
            800AD2AC	and    v1, v1, a3
            800AD2B0	and    v0, v0, a2
            800AD2B4	or     v1, v1, v0
            800AD2B8	sw     v1, $0000(a0)
            800AD2BC	lw     v0, $001c(t0)
            800AD2C0	nop
            800AD2C4	lbu    a0, $0008(v0)
            800AD2C8	nop
            800AD2CC	sll    v1, a0, $02
            800AD2D0	addu   v0, v0, v1
            800AD2D4	sll    a0, a0, $04
            800AD2D8	lw     v0, $0010(v0)
            800AD2DC	addu   a0, fp, a0
            800AD2E0	addu   a1, a1, v0
            800AD2E4	lw     v1, $0000(a1)
            800AD2E8	lw     v0, $0010(a0)
            800AD2EC	and    v1, v1, a3
            800AD2F0	and    v0, v0, a2
            800AD2F4	or     v1, v1, v0
            800AD2F8	sw     v1, $0000(a1)
        }
    }


    A1 = w[SP + 58];

    V1 = w[SP + 5c];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 64];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 68];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V0 = w[8006794c];
    A3 = w[V0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];
    V0 = w[V0 + 14];
    A0 = h[V0 + 30];
    A1 = w[SP + 70] + A1 >> 2;
    if( ( -A0 < A1 ) && ( A1 < ( 1000 - A0 ) ) )
    {
        A1 = A1 << 2;
        frame_id = bu[A3 + 8];
        V0 = w[A3 + 10 + frame_id * 4];
        A0 = w[FP + 14 + frame_id * 10];
        [A0] = w((w[A0] & ff000000) | (w[V0 + A1] & 00ffffff);
        [V0 + A1] = w((w[V0 + A1] & ff000000) | (w[FP + 14 + frame_id * 10] & 00ffffff);
    }
}
////////////////////////////////



////////////////////////////////
// field_add_model_data_pointers
start_pointer = A0;

S1 = 0;



// add main models
system_get_pointer_to_first_element_in_script_list;
S0 = V0;
if( S0 == 0 )
{
    pointer = start_pointer;

    loopab154:	; 800AB154
        A0 = w[S0 + 4]; // pointer to allocated script memory
        if( bu[A0 + e] == 1 )
        {
            if( bu[A0 + f] & 01 )
            {
                if( bu[A0 + 5] == 4 ) // model entity type
                {
                    A0 = bu[A0 + 3b];
                    func1e350;

                    A0 = V0;
                    V0 = w[A0 + 8];
                    if( w[V0 + 1c] == 0 )
                    {
                        [pointer] = w(A0);
                        pointer = pointer + 4;
                        S1 = S1 + 1;
                    }
                }
            }
        }

        S0 = w[S0 + 0];
    800AB1CC	bne    s0, zero, loopab154 [$800ab154]
}



// add attached models after main models
// because we need to update attached model matrixes after main models
system_get_pointer_to_first_element_in_script_list;
S0 = V0;
if( S0 != 0 )
{
    loopab1e8:	; 800AB1E8
        A0 = w[S0 + 4]; // pointer to allocated script memory
        if( bu[A0 + e] == 1 )
        {
            if( bu[A0 + f] & 1 )
            {
                if( bu[A0 + 5] == 4 ) // model entity type
                {
                    A0 = bu[A0 + 3b];
                    func1e350;

                    A0 = V0;
                    V0 = w[A0 + 8];
                    A3 = w[V0 + 1c];
                    if( A3 != 0 )
                    {
                        if( S1 > 0 )
                        {
                            A2 = 0;
                            loopab260:	; 800AB260
                                V0 = w[start_pointer + A2 * 4];
                                if( w[V0 + 8] == A3 )
                                {
                                    [start_pointer + S1 * 4] = w(A0);
                                    S1 = S1 + 1;
                                    break;
                                }

                                A2 = A2 + 1;
                                V0 = A2 < S1;
                            800AB28C	bne    v0, zero, loopab260 [$800ab260]
                        }
                    }
                }
            }
        }

        S0 = w[S0 + 0];
    800AB29C	bne    s0, zero, loopab1e8 [$800ab1e8]
}



// remove pointer if it exceed memory limit
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
V0 = w[V0 + 14];
if( b[V0 + 42] != 0 )
{
    if( S1 > 0 )
    {
        A2 = 0;
        loopab2fc:	; 800AB2FC
            V0 = w[start_pointer + A2 * 4];
            model_data = w[V0 + 8];
            model_file = w[model_data + 8];
            model_file_parts = w[model_file + 10];
            if( model_file_parts >= 0 ) // if this is not direct address get pointer to model data
            {
                model_file_parts = model_file + model_file_parts;
            }

            A1 = 0;
            number_of_model = bu[model_file + 3];
            if( number_of_model > 0 )
            {
                A0 = 0;
                loopab33c:	; 800AB33C
                    A1 = A1 + hu[model_file_parts + A0 * 28 + 0];
                    A0 = A0 + 1;
                    V0 = A0 < number_of_model;
                800AB34C	bne    v0, zero, loopab33c [$800ab33c]
            }

            if( ( w[model_data + 10] + bu[model_file + 2] * 20 + bu[model_file + 3] * c + A1 * 2 ) >= ( w[80067944] + f1700 ) )
            {
                [start_pointer + A2 * 4] = w(0);
            }

            A2 = A2 + 1;
            V0 = A2 < S1;
        800AB39C	bne    v0, zero, loopab2fc [$800ab2fc]
    }
}

return S1;
////////////////////////////////



////////////////////////////////
// field_get_x_y_rotation_from_walkmesh_for_model
V1 = w[800c9df4];
V1 = h[V1 + A0 * 28 + 6];
V1 = w[800c9e00] + V1 * 28;
[A1] = h(-hu[V1 + a]);
[A2] = h(hu[V1 + 8]);
return 1;
////////////////////////////////



////////////////////////////////
// funcb7cec
if( hu[A0 + 0] & 0002 )
{
    R11R12 = w[A0 + 24];
    R13R21 = w[A0 + 28];
    R22R23 = w[A0 + 2c];
    R31R32 = w[A0 + 30];
    R33 = w[A0 + 34];

    IR1 = hu[A0 + 54];
    IR2 = 0;
    IR3 = 0;
    gte_rtir12; // ir * rotmatrix.
    [A0 + 24] = h(IR1);
    [A0 + 2a] = h(IR2);
    [A0 + 30] = h(IR3);


    IR1 = 0;
    IR2 = hu[A0 + 56];
    IR3 = 0;
    gte_rtir12; // ir * rotmatrix.
    [A0 + 26] = h(IR1);
    [A0 + 2c] = h(IR2);
    [A0 + 32] = h(IR3);

    IR1 = 0;
    IR2 = 0;
    IR3 = hu[A0 + 58];
    gte_rtir12; // ir * rotmatrix.
    [A0 + 28] = h(IR1);
    [A0 + 2e] = h(IR2);
    [A0 + 34] = h(IR3);
}
////////////////////////////////
