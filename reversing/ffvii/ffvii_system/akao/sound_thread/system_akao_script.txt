////////////////////////////////
// func30e7c
S0 = A0; // channel struct
S3 = A1; // spu config
S5 = A2; // current channel mask

S6 = 80049828;

loop30eb8:	; 80030EB8
    V0 = w[S0];
    [S0] = w(V0 + 1);

    S2 = bu[V0];
    S1 = S2;

    if (S1 < a0)
    {
        break;
    }

a0 94380380
a2 5C340380
a4 2C250380
a6 94200380
a7 AC200380
ab F01F0380
ac 6C2D0380
ad 082E0380
ae 6C2E0380
af D02E0380
b0 D8350380
b1 342F0380
b2 982F0380
b3 CC230380
b5 18270380
b6 E0270380FC2F038004280380D428038068290380603003808C290380042A0380982A0380C4300380
c0 D8240380
c1 00250380
c3 E82C0380
c4 BC2A0380302B0380B42B0380202C038024320380643203802034038008370380442D0380502D0380283603806C360380
d0 582D0380642D038098360380DC360380883703809C370380B0370380C4370380C0250380E82503807C250380B82503808834038070270380F8280380282A0380
e0 e1 e2 e3 e4 e5 e6 e7 703A0380
e9 FC1A0380
eb E41B0380EC34038034350380D837038018380380
f0 EC320380
f1 7C330380
f2 74220380
f3 CC350380
f4 6C1D0380
f5 981E0380
f6 EC1E0380
f7 301F0380
f8 28310380
f9 CC310380
fa 703A0380
fb 703A0380
fc 703A0380
ff 703A0380

    80030EE0	sll    v0, s1, $02
    80030EE4	addu   v0, v0, s6
    80030EE8	lw     v0, $0000(v0)

    A0 = A0; // pointer to channel struct 0x108
    A1 = S3;
    A2 = S5;
    80030EF0	jalr   v0 ra

80030EF8	bne    s1, 0xa0, loop30eb8 [$80030eb8]



if (S1 != a0)
{
    A0 = S0;
    func318bc;

    A0 = V0 & ff;

    if (h[S0 + c4] != 0)
    {
        [S0 + 56] = h(h[S0 + c4] * 101);
    }

    if ((hu[S0 + 56] & ff) == 0)
    {
        [S0 + 56] = h(hu[80049c28 + (S1 % b) * 2]);
    }

    if (((A0 - 84) >= b) && (hu[S0 + 6e] & 5) == 0))
    {
        [S0 + 56] = h(hu[S0 + 56] - 200);
    }

    [S0 + c2] = h(bu[S0 + 56]);

    if (S2 >= 8f)
    {
        [S0 + 6c] = h(0);
        [S0 + d6] = h(0);
        [S0 + d8] = h(0);
        [S0 + 6e] = h(hu[S0 + 6e] & fffd);
    }
    else if (S2 < 84)
    {
        A0 = S2 / b;
        S2 = A0;

        if (w[S0 + 38] & 00000008)
        {
            if (hu[S0 + 54] == 0)
            {
                80031050	lw     v0, $0008(s3)
                80031058	or     v0, s5, v0
                80031060	sw     v0, $0008(s3)
            }
            else
            {
                80031064	lui    v0, $800a
                80031068	lw     v0, $9fd0(v0)
                8003106C	nop
                80031070	or     v0, s5, v0
                80031074	lui    at, $800a
                80031078	sw     v0, $9fd0(at)
            }

            V1 = (S2 & ff) / c;
            A0 = (S2 & ff) % c
            8003108C	lw     a2, $0014(s0)

            800310A8	andi   a0, a0, $00ff
            800310AC	sll    v0, a0, $02
            800310B0	addu   v0, v0, a0
            800310B4	addu   a2, a2, v0
            800310B8	lbu    v1, $0000(a2)
            800310BC	lhu    v0, $0058(s0)
            800310C0	nop
            if (V1 != V0)
            {
                800310CC	sh     v1, $0058(s0)
                800310D0	lbu    v0, $0000(a2)
                800310D4	nop
                800310D8	sll    v0, v0, $06
                800310DC	lui    at, $8007
                800310E0	addiu  at, at, $5f28
                800310E4	addu   at, at, v0
                800310E8	lw     v0, $0000(at)
                800310EC	nop
                800310F0	sw     v0, $00e4(s0)
                800310F4	lbu    v0, $0000(a2)
                800310F8	nop
                800310FC	sll    v0, v0, $06
                80031100	lui    at, $8007
                80031104	addiu  at, at, $5f2c
                80031108	addu   at, at, v0
                8003110C	lw     v0, $0000(at)
                80031110	nop
                80031114	sw     v0, $00e8(s0)
                80031118	lbu    v0, $0000(a2)
                8003111C	nop
                80031120	sll    v0, v0, $06
                80031124	lui    at, $8007
                80031128	addiu  at, at, $5f30
                8003112C	addu   at, at, v0
                80031130	lbu    v0, $0000(at)
                80031134	nop
                80031138	sh     v0, $00fa(s0)
                8003113C	lbu    v0, $0000(a2)
                80031140	nop
                80031144	sll    v0, v0, $06
                80031148	lui    at, $8007
                8003114C	addiu  at, at, $5f31
                80031150	addu   at, at, v0
                80031154	lbu    v0, $0000(at)
                80031158	nop
                8003115C	sh     v0, $00fc(s0)
                80031160	lbu    v0, $0000(a2)
                80031164	nop
                80031168	sll    v0, v0, $06
                8003116C	lui    at, $8007
                80031170	addiu  at, at, $5f32
                80031174	addu   at, at, v0
                80031178	lbu    v0, $0000(at)
                8003117C	nop
                80031180	sh     v0, $00fe(s0)
                80031184	lbu    v0, $0000(a2)
                80031188	nop
                8003118C	sll    v0, v0, $06
                80031190	lui    at, $8007
                80031194	addiu  at, at, $5f33
                80031198	addu   at, at, v0
                8003119C	lbu    v0, $0000(at)
                800311A0	nop
                800311A4	sh     v0, $0100(s0)
                800311A8	lbu    v0, $0000(a2)
                800311AC	nop
                800311B0	sll    v0, v0, $06
                800311B4	lui    at, $8007
                800311B8	addiu  at, at, $5f35
                800311BC	addu   at, at, v0
                800311C0	lbu    v0, $0000(at)
                800311C4	nop
                800311C8	sw     v0, $00ec(s0)
                800311CC	lbu    v0, $0000(a2)
                800311D0	nop
                800311D4	sll    v0, v0, $06
                800311D8	lui    at, $8007
                800311DC	addiu  at, at, $5f36
                800311E0	addu   at, at, v0
                800311E4	lbu    v1, $0000(at)
                800311E8	lw     v0, $0038(s0)
                800311EC	nop
                800311F0	andi   v0, v0, $0200
                800311F8	sw     v1, $00f0(s0)
                if (V0 == 0)
                {
                    800311FC	lbu    v0, $0000(a2)
                    80031200	lui    a0, $0001
                    80031204	sll    v0, v0, $06
                    80031208	lui    at, $8007
                    8003120C	addiu  at, at, $5f34
                    80031210	addu   at, at, v0
                    80031214	lbu    v0, $0000(at)
                    80031218	ori    a0, a0, $ff80
                    8003121C	sh     v0, $0102(s0)
                    80031220	lbu    v1, $0000(a2)
                    80031224	lw     v0, $00e0(s0)
                    80031228	sll    v1, v1, $06
                    8003122C	lui    at, $8007
                    80031230	addiu  at, at, $5f37
                    80031234	addu   at, at, v1
                    80031238	lbu    v1, $0000(at)
                    8003123C	or     v0, v0, a0
                    80031240	sw     v0, $00e0(s0)
                    80031248	sw     v1, $00f4(s0)
                }
                else
                {
                    8003124C	lui    v1, $0001
                    80031250	lw     v0, $00e0(s0)
                    80031254	ori    v1, v1, $bb80
                    80031258	or     v0, v0, v1
                    8003125C	sw     v0, $00e0(s0)
                }
            }

            V1 = bu[A2 + 1];

            A1 = (S2 & ff) / c;
            V1 = (S2 & ff) % c;

            A1 = A1 & ff;
            A0 = w[80075f38 + bu[A2 + 0] * 40 + V1 * 4];

            if (A1 >= 7)
            {
                V0 = A1 - 6;
                A0 = V0 << A0;
            }
            else if (A1 < 6)
            {
                V0 = 6 - A1;
                A0 = A0 >> V0;
            }

            [S0 + 44] = w((bu[A2 + 2] + (bu[A2 + 3] << 8)) << 10);
            [S0 + 60] = h(bu[A2 + 4] << 8);
        }
        else
        {
            S2 = A0 + hu[S0 + 66] * c;

            if ((hu[S0 + 6c] != 0) && (hu[S0 + 6a] != 0))
            {
                [S0 + 68] = h(hu[S0 + 6c]);
                [S0 + d2] = h((S2 & ff) + hu[S0 + cc] - hu[S0 + 6a] - hu[S0 + d4]);
                [S0 + d0] = h(hu[S0 + 6a] - hu[S0 + cc] - hu[S0 + d4]);
                S2 = bu[S0 + 6a] + bu[S0 + d4];
            }
            else
            {
                [S0 + d0] = h(S2 & ff);
                S2 = S2 + bu[S0 + cc];
            }

            if ((hu[S0 + 6e] & 0002) == 0)
            {
                if (hu[S0 + 54] == 0)
                {
                    [S3 + 8] = w(S5 | w[S3 + 8]);

                    if (w[S0 + 38] & 00000100)
                    {
                        V1 = hu[S0 + 24];
                        if (w[S0 + 24] >= 18)
                        {
                            V1 = V1 - 18;
                        }

                        [S3 + 8] = w(w[[S3 + 8]] | (1 << V1));
                    }
                }
                else
                {
                    [80099fd0] = w(w[80099fd0] | S5);
                }
                [S0 + 64] = h(0);
            }

            V1 = S2 / c;

            A0 = w[80075f28 + hu[S0 + 58] * 40 + 10 + ((S2 & ff) % c) * 4 ];
            if (V1 >= 7)
            {
                A0 = A0 << (V1 - 6);
            }
            else if (V1 < 6)
            {
                A0 = A0 >> (6 - V1);
            }
        }

        if (hu[S0 + 54] == 0)
        {
            [S3 + c] = w(w[S3 + c] | S5);
        }
        else
        {
            [80099fd4] = w(w[80099fd4] | S5);
        }

        [S0 + e0] = w(w[S0 + e0] | 00000013);

        V1 = h[S0 + ce];
        if (V1 != 0)
        {
            if (V1 > 0)
            {
                V0 = (A0 * V1) >> 7;
            }
            else
            {
                V0 = (A0 * V1) >> 8;
            }

            A0 = (A0 + V0) & ffff;
        }
        [S0 + 30] = w(A0);

        if (w[S0 + 38] & 00000001)
        {
            8003152C	lhu    v0, $007e(s0)
            80031534	andi   v1, v0, $7f00
            80031538	andi   v0, v0, $8000
            80031540	srl    v1, v1, $08
            if (V0 != 0)
            {
                80031548	mult   v1, a0
            }
            else
            {
                8003154C	sll    v0, a0, $04
                80031550	subu   v0, v0, a0
                80031554	srl    v0, v0, $08
                80031558	mult   v1, v0
            }

            8003155C	mflo   v0
            80031560	srl    v1, v0, $07
            80031568	sh     v1, $007c(s0)

            [S0 + 18] = w(w[8004a5cc + hu[S0 + 7a] * 4]);
            [S0 + 74] = h(hu[S0 + 72]);
            [S0 + 78] = h(1);
        }

        if (w[S0 + 38] & 00000002)
        {
            [S0 + 1c] = w(w[8004a5cc + hu[S0 + 8e] * 4]);
            [S0 + 88] = h(hu[S0 + 86]);
            [S0 + 8c] = h(1);
        }

        if (w[S0 + 38] & 00000004)
        {
            800315E8	lhu    v0, $009c(s0)
            800315EC	nop
            800315F0	sll    v0, v0, $02
            800315F4	lui    at, $8005
            800315F8	addiu  at, at, $a5cc (=-$5a34)
            800315FC	addu   at, at, v0
            80031600	lw     v1, $0000(at)
            80031604	ori    v0, zero, $0001
            80031608	sh     v0, $009a(s0)
            8003160C	sw     v1, $0020(s0)
        }

        [S0 + d6] = h(0);
        [S0 + d8] = h(0);
        [S0 + 34] = w(0);
    }

    A0 = h[S0 + d2];

    [S0 + 6e] = h((hu[S0 + 6e] & fffd) | ((hu[S0 + 6e] & 0001) << 1));
    V1 = A0;

    if (A0 != 0)
    {
        [S0 + d0] = h(hu[S0 + d0] + V1);

        S2 = bu[S0 + d0] + bu[S0 + cc];

        if (hu[S0 + 54] == 0)
        {
            A0 = w[80075f38 + hu[S0 + 58] * 40 + ((S2 & ff) % c) * 4];

            V0 = h[S0 + ce];
            if (V0 != 0)
            {
                if (V0 > 0)
                {
                    V0 = (A0 * V0) >> 7;
                }
                else
                {
                    V0 = (A0 * V0) >> 8;
                }
                A0 = (A0 + V0) & ffff;
            }

            A0 = A0 << 10;
        }
        else
        {
            A0 = (w[80075f38 + hu[S0 + 58] * 40 + ((S2 & ff) % c) * 4]) << 10; // get pitch
        }

        S2 = (S2 & ff) / c;
        V1 = S2 & ff;

        if (V1 >= 7)
        {
            A0 = A0 << (V1 - 6);
        }
        else if (V1 < 6)
        {
            A0 = A0 >> (6 - V1);
        }

        [S0 + 64] = h(hu[S0 + 68]);
        [S0 + d2] = h(0);
        [S0 + 4c] = w((A0 + w[S0 + 34] - (w[S0 + 30] << 10)) / hu[S0 + 64]);
    }

    [S0 + d4] = h(hu[S0 + cc]);
    [S0 + 6a] = h(hu[S0 + d0]);
}
////////////////////////////////



////////////////////////////////
// func318bc
// next opcode
T0 = ffff;
A1 = w[A0 + 0];
A3 = hu[A0 + b8];

while (true)
{
    V1 = bu[A1];

    if (V1 < 9a)
    {
        if (V1 >= 8f)
        {
            [A0 + 6c] = h(0);
            [A0 + 6e] = h([A0 + 6e] & fffa);
        }

        return bu[A1];
    }

    if (V1 < a0)
    {
        return a0;
    }

    V0 = bu[800498a8 + V1];
    if (V0 == 0)
    {
        switch(V1)
        {
            case c9:
            {
                80031958	addiu  a1, a1, $0001
                8003195C	andi   a2, a3, $ffff
                80031960	sll    v0, a2, $01
                80031964	addu   v0, v0, a0
                80031968	lhu    v0, $00ba(v0)
                8003196C	lbu    v1, $0000(a1)
                80031970	addiu  v0, v0, $0001
                if (V1 == V0)
                {
                    A1 = A1 + 1;
                    A3 = (T0 + A3) & 3;

                }
                else
                {
                    A1 = w[A0 + A3 * 4 + 4] ;
                }
                continue;
            }
            break;

            case ca:
            {
                A1 = w[A0 + A3 * 4 + 4] ;
                continue;
            }
            break;

            case cb cd d1 db:
            {
                A1 = A1 + 1;
                [A0 + 6c] = h(0);
                [A0 + 6e] = h(hu[A0 + 6e] & fffa);
                continue;
            }
            break;

            case ee:
            {
                A1 = A1 + 1;
                80031A24	lbu    a2, $0000(a1)
                80031A28	addiu  a1, a1, $0001
                80031A2C	lbu    v0, $0000(a1)
                80031A30	addiu  a1, a1, $0001
                80031A34	sll    v0, v0, $08
                80031A38	addu   v0, a2, v0
                80031A3C	sll    v0, v0, $10
                80031A40	sra    v0, v0, $10
                80031A48	addu   a1, a1, v0
                continue;
            }
            break;

            case ef:
            {
                80031A04	addiu  a1, a1, $0001
                80031A08	lbu    a2, $0000(a1)
                80031A0C	lui    v0, $800a
                80031A10	lhu    v0, $a152(v0)
                80031A14	nop
                80031A18	sltu   v0, v0, a2
                A1 = A1 + 1;
                if (V0 == 0)
                {
                    80031A24	lbu    a2, $0000(a1)
                    80031A28	addiu  a1, a1, $0001
                    80031A2C	lbu    v0, $0000(a1)
                    80031A30	addiu  a1, a1, $0001
                    80031A34	sll    v0, v0, $08
                    80031A38	addu   v0, a2, v0
                    80031A3C	sll    v0, v0, $10
                    80031A40	sra    v0, v0, $10
                    80031A48	addu   a1, a1, v0
                }
                else
                {
                    A1 = A1 + 2;
                }

                continue;
            }
            break;

            case f0 f1:
            {
                800319A0	addiu  a1, a1, $0001
                800319A4	sll    v0, a3, $01
                800319A8	addu   v0, v0, a0
                800319AC	lhu    v0, $00ba(v0)
                800319B0	lbu    v1, $0000(a1)
                800319B4	addiu  v0, v0, $0001
                if (V1 == V0)
                {
                    800319BC	addu   v1, a3, t0
                    800319C0	addiu  a1, a1, $0001
                    800319C4	lbu    a2, $0000(a1)
                    800319C8	addiu  a1, a1, $0001
                    800319CC	lbu    v0, $0000(a1)
                    800319D0	addiu  a1, a1, $0001
                    800319D8	andi   a3, v1, $0003
                    80031A34	sll    v0, v0, $08
                    80031A38	addu   v0, a2, v0
                    80031A3C	sll    v0, v0, $10
                    80031A40	sra    v0, v0, $10
                    80031A48	addu   a1, a1, v0
                }
                else
                {
                    A1 = A1 + 3;
                }

                continue;
            }
            break;

            default:
            {
                [A0 + 6c] = h(0);
                [A0 + 6e] = h(hu[A0 + 6e] & fffa);
                return a0;
            }
        }
    }

    A1 = A1 + V0;
}

////////////////////////////////