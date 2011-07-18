////////////////////////////////
// func2f738
8002F738	addiu  sp, sp, $ffe0 (=-$20)
8002F73C	addu   a3, a0, zero
8002F740	sw     s0, $0010(sp)
8002F744	addu   s0, a1, zero
8002F748	ori    a1, zero, $007f
8002F74C	sw     ra, $001c(sp)
8002F750	sw     s2, $0018(sp)
8002F754	sw     s1, $0014(sp)
8002F758	lhu    v0, $00c6(a3)
8002F75C	lh     a0, $0104(a3)
8002F760	sll    v0, v0, $10
8002F764	sra    v0, v0, $18
8002F768	subu   a1, a1, v0
8002F76C	andi   a1, a1, $ffff
8002F770	mult   a0, a1
8002F774	mflo   v1
8002F778	lh     v0, $00c6(a3)
8002F77C	nop
8002F780	mult   a0, v0
8002F784	lw     a0, $0024(a3)
8002F788	sra    v1, v1, $08
8002F78C	sh     v1, $0104(a3)
8002F790	lui    v1, $8009
8002F794	addiu  v1, v1, $6608
8002F798	sll    v0, a0, $05
8002F79C	addu   v0, v0, a0
8002F7A0	sll    v0, v0, $03
8002F7A4	addu   s1, v0, v1
8002F7A8	mflo   v0
8002F7AC	sra    v0, v0, $10
8002F7B0	sh     v0, $0104(s1)
8002F7B4	lh     a0, $0106(a3)
8002F7B8	nop
8002F7BC	mult   a0, a1
8002F7C0	mflo   v0
8002F7C4	lh     v1, $00c6(a3)
8002F7C8	nop
8002F7CC	mult   a0, v1
8002F7D0	sra    v0, v0, $08
8002F7D4	sh     v0, $0106(a3)
8002F7D8	mflo   v0
8002F7DC	sra    v0, v0, $10
8002F7E0	sh     v0, $0106(s1)
8002F7E4	lhu    v0, $00f8(a3)
8002F7E8	nop
8002F7EC	sh     v0, $00f8(s1)
8002F7F0	lw     v0, $00e0(s1)
8002F7F4	lw     v1, $00e0(a3)
8002F7F8	addu   s2, a2, zero
8002F7FC	or     v0, v0, v1
8002F800	sw     v0, $00e0(s1)
8002F804	lw     a0, $00dc(a3)
8002F808	jal    func2e23c [$8002e23c]
8002F80C	addiu  a1, a3, $00dc
8002F810	ori    v0, zero, $0001
8002F814	sllv   v0, s2, v0
8002F818	and    s0, s0, v0
8002F81C	beq    s0, zero, L2f82c [$8002f82c]
8002F820	addu   a0, s2, zero
8002F824	jal    func2e23c [$8002e23c]
8002F828	addiu  a1, s1, $00dc

L2f82c:	; 8002F82C
8002F82C	lw     ra, $001c(sp)
8002F830	lw     s2, $0018(sp)
8002F834	lw     s1, $0014(sp)
8002F838	lw     s0, $0010(sp)
8002F83C	addiu  sp, sp, $0020
8002F840	jr     ra 
8002F844	nop
////////////////////////////////



////////////////////////////////
// func2ed34
T0 = A0;



A0 = (h[T0 + 46] * w[T0 + 2c]) >> 7;



if ((w[T0 + 38] & 00000001) && (hu[T0 + 74] == 0))
{
    V0 = hu[T0 + 78] - 1;
    [T0 + 78] = h(V0);
    if (V0 == 0)
    {
        [T0 + 78] = h(hu[T0 + 76]);

        V1 = w[T0 + 18];
        if ((h[V1 + 0] == 0) && (h[V1 + 2] == 0))
        {
            [T0 + 18] = w(V1 + h[V1 + 4] * 2);
        }

        V1 = w[T0 + 18];
        [T0 + 18] = w(V1 + 2);

        A3 = (hu[T0 + 7c] * h[V1 + 0]) >> 10;
        if (A3 != h[T0 + d6])
        {
            [T0 + e0] = w(w[T0 + e0] | 00000010); // update pitch to SPU

            [T0 + d6] = h(A3);

            if (A3 >= 0)
            {
                [T0 + d6] = h(A3 * 2);
            }
        }
    }
}



if ((w[T0 + 38] & 00000002) && (hu[T0 + 88] == 0))
{
    V0 = hu[T0 + 8c] - 1;
    [T0 + 8c] = h(V0);
    if (V0 == 0)
    {
        [T0 + 8c] = h(hu[T0 + 8a]);

        V1 = w[T0 + 1c];
        if (h[V1 + 0] == 0 && h[V1 + 2] == 0)
        {
            [T0 + 1c] = w(V1 + h[V1 + 4] * 2);
        }

        V1 = w[T0 + 1c];
        [T0 + 1c] = w(V1 + 2);

        A3 = ((((A0 * (hu[T0 + 90] << 8)) << 9) >> 10) * h[V1 + 0]) >> f;
        if (A3 != h[T0 + d8])
        {
            [T0 + e0] = w(w[T0 + e0] | 00000003);
            [T0 + d8] = h(A3);
        }
    }
}



if (w[T0 + 38] & 00000004)
{
    V0 = hu[T0 + 9a] - 1;
    [T0 + 9a] = h(V0);
    if (V0 == 0)
    {
        [T0 + 9a] = h(hu[T0 + 98]);

        V1 = w[T0 + 20];
        if (h[V1 + 0] == 0 && h[V1 + 2] == 0)
        {
            [T0 + 20] = w(V1 + h[V1 + 4] * 2);
        }

        V1 = w[T0 + 20];
        [T0 + 20] = w(V1 + 2);

        A3 = ((hu[T0 + 9e] >> 8) * h[V1 + 0]) >> f;
        if (A3 != h[T0 + da])
        {
            [T0 + e0] = w(w[T0 + e0] | 00000003);
            [T0 + da] = h(A3);
        }
    }
}



if (w[T0 + 38] & 00000020)
{
    [T0 + e0] = w(w[T0 + e0] | 00000003);

    A0 = (((hu[T0 - 10] << 11) >> 10) * w[T0 + 2c]) >> 7;
}



if (w[T0 + e0] & 00000003)
{
    A0 = ((A0 + h[T0 + d8]) * (hu[80062f5e] & 7f)) >> 7;

    if (hu[8009c5a8] != 0)
    {
        A0 = (A0 * h[8009c5a2 + A2 * c]) >> 7;
    }

    A3 = (h[T0 + da] + hu[T0 + 60] >> 8) & ff;

    V1 = w[8009a104];
    if (V1 == 1)
    {
        [T0 + 104] = h((A0 * h[80049c44 + A3 * 2]) >> f);
        [T0 + 106] = h((A0 * h[80049e44 + A3 * 2]) >> f);
    }
    else if (V1 == 4)
    {
        [T0 + 104] = h((A0 * h[80049c44 + A3 * 2]) >> f);
        [T0 + 106] = h((A0 * h[80049e44 + A3 * 2]) >> f);

        if (A1 & 00aaaaaa == 0)
        {
            [T0 + 104] = h(0 NOR hu[T0 + 104]);
        }
        else
        {
            [T0 + 106] = h(0 NOR hu[T0 + 106]);
        }
    }
    else
    {
        [T0 + 104] = h((A0 * h[80049cc4]) >> f);
        [T0 + 106] = h((A0 * h[80049cc4]) >> f);
    }
}



if (w[T0 + 38] & 00000010)
{
    V1 = h[T0 + d6] + h[T0 + 36] + w[T0 - 10]; // uses pitch from previous channel
}
else if (w[T0 + e0] & 00000010)
{
    V1 = h[T0 + d6] + h[T0 + 36] + w[T0 + 30];
}



if ((w[T0 + 38] & 00000010) || (w[T0 + e0] & 00000010))
{
    if (bu[80062fe6] != 0)
    {
        if (bu[80062fe6] < 80)
        {
            V1 = V1 + ((V1 * bu[80062fe6]) >> 7);
        }
        else
        {
            V1 = (V1 * bu[80062fe6]) >> 8;
        }
    }

    [T0 + e0] = w(w[T0 + e0] | 00000010);
    [T0 + f8] = h(V1 & 3fff);
}
////////////////////////////////



////////////////////////////////
// func2f24c
// A0 - address of struct for this channel
// A1 - bit for this channel
A2 = A0;

T0 = (h[A2 + 46] * w[A2 + 2c]) >> 7;



if (w[A2 + 38] & 00000001)
{
    V0 = hu[A2 + 78] - 1;
    [A2 + 78] = h(V0);
    if (V0 == 0)
    {
        [A2 + 78] = h(hu[A2 + 76]);

        V1 = w[A2 + 18];

        if ((h[V1 + 0] == 0) && (h[V1 + 2] == 0))
        {
            [A2 + 18] = w(V1 + h[V1 + 4] * 2);
        }

        V1 = w[A2 + 18];
        [A2 + 18] = w(V1 + 2);

        A0 = (hu[A2 + 7c] * h[V1 + 0]) >> 10;
        if (A0 != h[A2 + d6])
        {
            [A2 + e0] = w(w[A2 + e0] | 00000010); // update pitch to SPU

            [A2 + d6] = h(A0);

            if (A0 >= 0)
            {
                [A2 + d6] = h(A0 * 2);
            }
        }
    }
}



if (w[A2 + 38] & 00000002)
{
    V0 = hu[A2 + 8c];
    V0 = V0 - 1;
    [A2 + 8c] = h(V0);
    V0 = V0 & ffff;
    if (V0 == 0)
    {
        8002F354	lhu    v0, $008a(a2)
        8002F358	lw     v1, $001c(a2)
        8002F35C	sh     v0, $008c(a2)
        8002F360	lh     v0, $0000(v1)
        8002F364	nop
        8002F368	bne    v0, zero, L2f394 [$8002f394]
        8002F36C	nop
        8002F370	lh     v0, $0002(v1)
        8002F374	nop
        8002F378	bne    v0, zero, L2f394 [$8002f394]
        8002F37C	nop
        8002F380	lh     v0, $0004(v1)
        8002F384	nop
        8002F388	sll    v0, v0, $01
        8002F38C	addu   v0, v0, v1
        8002F390	sw     v0, $001c(a2)

        L2f394:	; 8002F394
        8002F394	lhu    v0, $0090(a2)
        8002F398	nop
        8002F39C	srl    v0, v0, $08
        8002F3A0	mult   t0, v0
        8002F3A4	lw     v1, $001c(a2)
        8002F3A8	nop
        8002F3AC	addiu  v0, v1, $0002
        8002F3B0	sw     v0, $001c(a2)
        8002F3B4	lh     a3, $0000(v1)
        8002F3B8	mflo   v0
        8002F3BC	sll    v0, v0, $09
        8002F3C0	sra    a0, v0, $10
        8002F3C4	mult   a0, a3
        8002F3C8	lh     v1, $00d8(a2)
        8002F3CC	mflo   v0
        8002F3D0	sra    a0, v0, $0f
        if (A0 != V1)
        {
            [A2 + e0] = w(w[A2 + e0] | 00000003);
            [A2 + d8] = h(A0);
        }
    }
}



if (w[A2 + 38] & 00000004)
{
    8002F400	lhu    v0, $009a(a2)
    8002F404	nop
    8002F408	addiu  v0, v0, $ffff (=-$1)
    8002F40C	sh     v0, $009a(a2)
    8002F410	andi   v0, v0, $ffff
    if (V0 == 0)
    {
        8002F41C	lhu    v0, $0098(a2)
        8002F420	lw     v1, $0020(a2)
        8002F424	sh     v0, $009a(a2)
        8002F428	lh     v0, $0000(v1)
        8002F42C	nop
        8002F430	bne    v0, zero, L2f45c [$8002f45c]
        8002F434	nop
        8002F438	lh     v0, $0002(v1)
        8002F43C	nop
        8002F440	bne    v0, zero, L2f45c [$8002f45c]
        8002F444	nop
        8002F448	lh     v0, $0004(v1)
        8002F44C	nop
        8002F450	sll    v0, v0, $01
        8002F454	addu   v0, v0, v1
        8002F458	sw     v0, $0020(a2)

        L2f45c:	; 8002F45C
        V1 = w[A2 + 20];
        [A2 + 20] = w(V1 + 2);

        8002F46C	lhu    v0, $009e(a2)

        8002F470	lh     a3, $0000(v1)
        8002F474	srl    v0, v0, $08
        8002F478	mult   v0, a3
        8002F47C	lh     v1, $00da(a2)
        8002F480	mflo   v0
        8002F484	sra    a0, v0, $0f
        if (A0 != V1)
        {
            [A2 + e0] = w(w[A2 + e0] | 00000003);
            [A2 + da] = h(A0);
        }
    }
}



if (w[A2 + 38] & 00000020)
{
    V0 = hu[A2 - 10];

    8002F4B8	lw     v1, $002c(a2)
    8002F4BC	sll    v0, v0, $11
    8002F4C0	sra    v0, v0, $10
    [A2 + e0] = w(w[A2 + e0] | 00000003);
    V0 = V0 * V1;
    8002F4DC	srl    t0, v0, $07
}



if (w[A2 + e0] & 00000003)
{
    8002F4F4	lh     v0, $00d8(a2)
    8002F4F8	lhu    v1, $0054(a2)
    8002F4FC	addu   t0, t0, v0
    8002F500	ori    v0, zero, $0002
    A0 = 40;
    if (V1 != V0)
    {
        8002F50C	lhu    v0, $00c6(a2)
        8002F510	nop
        8002F514	sll    v0, v0, $10
        8002F518	sra    v0, v0, $18
        8002F51C	mult   t0, v0

        V0 = hu[A2 + 60];
        V1 = h[A2 + da];
        V0 = V0 >> 8;
        V0 = V0 + V1;
        A0 = V0 & ff;

        8002F534	mflo   v0
        T0 = V0 >> 7;
    }

    V1 = w[8009a104];
    if (V1 == 1)
    {
        [A2 + 104] = h((T0 * h[80049c44 + A0 * 2]) >> f);
        [A2 + 106] = h((T0 * h[80049e44 + A0 * 2]) >> f);
    }
    else if (V1 == 4)
    {
        [A2 + 104] = h((T0 * h[80049c44 + A0 * 2]) >> f);
        [A2 + 106] = h((T0 * h[80049e44 + A0 * 2]) >> f);

        if (A1 & 00aaaaaa)
        {
            [A2 + 106] = h(0 NOR hu[A2 + 106]);
        }
        else
        {
            [A2 + 104] = h(0 NOR hu[A2 + 104]);
        }
    }
    else
    {
        [A2 + 104] = h((T0 * h[80049cc4]) >> f);
        [A2 + 106] = h((T0 * h[80049cc4]) >> f);
    }
}



// update pitch
if (w[A2 + 38] & 00000010)
{
    A3 = h[A2 + d6] + h[A2 + 36] + w[A2 - 10]; // uses pitch from previous channel
}
else if (w[A2 + e0] & 00000010)
{
    A3 = h[A2 + d6] + h[A2 + 36] + w[A2 + 30];
}

if ((w[A2 + 38] & 00000010) || (w[A2 + e0] & 00000010))
{
    if ((hu[A2 + 54] != 2) && (bu[A2 + 3d] != 0)
    {
        if (bu[A2 + 3d] < 80)
        {
            A3 = A3 + ((A3 * bu[A2 + 3d]) >> 7);
        }
        else
        {
            A3 = (A3 * bu[A2 + 3d]) >> 8;
        }
    }

    [A2 + e0] = w(w[A2 + e0] | 00000010);
    [A2 + f8] = h(A3 & 3fff);
}
////////////////////////////////
