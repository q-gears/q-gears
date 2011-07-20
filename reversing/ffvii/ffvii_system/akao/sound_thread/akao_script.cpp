////////////////////////////////
// func30e7c
channel_data = A0; // channel struct
channels_config = A1; // spu config
mask = A2; // current channel mask

loop30eb8:	; 80030EB8
    V0 = w[channel_data];
    [channel_data] = w(V0 + 1);

    opcode = bu[V0];

    if (opcode < a0)
    {
        break;
    }

a0 94380380
a2 5C340380
a4 2C250380
ab F01F0380
ac 6C2D0380
ad 082E0380
ae 6C2E0380
af D02E0380
b0 D8350380
b1 342F0380
b2 982F0380
b3 CC230380
b6 E0270380
b7 FC2F038004280380D428038068290380603003808C290380042A0380982A0380C4300380
c0 D8240380
c1 00250380
c3 E82C0380
c4 BC2A0380
c5 302B0380
c6 B42B0380
c7 202C0380
cb 08370380
cc 442D0380
cd 502D0380
ce 28360380
cf 6C360380
d0 582D0380642D038098360380DC360380883703809C370380B0370380C4370380C0250380E82503807C250380B82503808834038070270380F8280380282A0380
e0 e1 e2 e3 e4 e5 e6 e7 703A0380
e9 FC1A0380
eb E41B0380
ec EC340380
ed 34350380
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

    A0 = A0; // pointer to channel struct 0x108
    A1 = channels_config;
    A2 = mask;
    80030EF0	jalr   v0 ra
80030EF8	bne    opcode, 0xa0, loop30eb8 [$80030eb8]



if (opcode != a0)
{
    A0 = channel_data;
    func318bc;

    A0 = V0 & ff;

    if (h[channel_data + c4] != 0)
    {
        [channel_data + 56] = h(h[channel_data + c4] * 101);
    }

    if ((hu[channel_data + 56] & ff) == 0)
    {
        [channel_data + 56] = h(hu[80049c28 + (opcode % b) * 2]);
    }

    if (((A0 - 84) >= b) && (hu[channel_data + 6e] & 5) == 0))
    {
        [channel_data + 56] = h(hu[channel_data + 56] - 200);
    }

    [channel_data + c2] = h(bu[channel_data + 56]);

    if (opcode >= 8f)
    {
        [channel_data + 6c] = h(0);
        [channel_data + d6] = h(0);
        [channel_data + d8] = h(0);
        [channel_data + 6e] = h(hu[channel_data + 6e] & fffd);
    }
    else if (opcode < 84)
    {
        A0 = opcode / b;
        S2 = A0;

        if (w[channel_data + 38] & 00000008)
        {
            if (hu[channel_data + 54] == 0)
            {
                [channels_config + 8] = w(w[channels_config + 8] | mask);
            }
            else
            {
                [80099fd0] = w(w[80099fd0] | mask);
            }

            V1 = (S2 & ff) / c;
            A0 = (S2 & ff) % c
            A2 = w[channel_data + 14];
            A0 = A0 & ff;

            V0 = A0 * 5;
            A2 = A2 + V0;
            if (bu[A2] != hu[channel_data + 58])
            {
                [channel_data + 58] = h(bu[A2]);
                V0 = bu[A2] * 40;
                [channel_data + e4] = w(w[80075f28 + V0]);
                [channel_data + e8] = w(w[80075f2c + V0]);
                [channel_data + fa] = h(bu[80075f30 + V0]);
                [channel_data + fc] = h(bu[80075f31 + V0]);
                [channel_data + fe] = h(bu[80075f32 + V0]);
                [channel_data + 100] = h(bu[80075f33 + V0]);
                [channel_data + ec] = w(bu[80075f35 + V0]);
                [channel_data + f0] = w(bu[80075f36 + V0]);

                if ((w[channel_data + 38] & 200) == 0)
                {
                    V0 = bu[A2] * 40;
                    [channel_data + 102] = h(bu[80075f34 + V0]);
                    [channel_data + f4] = w(bu[80075f37 + V0]);
                    [channel_data + e0] = w(w[channel_data + e0] | 1ff80);
                }
                else
                {
                    [channel_data + e0] = w(w[channel_data + e0] | 1bb80);
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

            [channel_data + 44] = w((bu[A2 + 2] + (bu[A2 + 3] << 8)) << 10);
            [channel_data + 60] = h(bu[A2 + 4] << 8);
        }
        else
        {
            S2 = A0 + hu[channel_data + 66] * c;

            if ((hu[channel_data + 6c] != 0) && (hu[channel_data + 6a] != 0))
            {
                [channel_data + 68] = h(hu[channel_data + 6c]);
                [channel_data + d2] = h((S2 & ff) + hu[channel_data + cc] - hu[channel_data + 6a] - hu[channel_data + d4]);
                [channel_data + d0] = h(hu[channel_data + 6a] - hu[channel_data + cc] - hu[channel_data + d4]);
                S2 = bu[channel_data + 6a] + bu[channel_data + d4];
            }
            else
            {
                [channel_data + d0] = h(S2 & ff);
                S2 = S2 + bu[channel_data + cc];
            }

            if ((hu[channel_data + 6e] & 0002) == 0)
            {
                if (hu[channel_data + 54] == 0)
                {
                    [channels_config + 8] = w(w[channels_config + 8] | mask);

                    if (w[channel_data + 38] & 00000100)
                    {
                        V1 = hu[channel_data + 24];
                        if (w[channel_data + 24] >= 18)
                        {
                            V1 = V1 - 18;
                        }

                        [channels_config + 8] = w(w[[channels_config + 8]] | (1 << V1));
                    }
                }
                else
                {
                    [80099fd0] = w(w[80099fd0] | mask);
                }
                [channel_data + 64] = h(0);
            }

            V1 = S2 / c;

            A0 = w[80075f28 + hu[channel_data + 58] * 40 + 10 + ((S2 & ff) % c) * 4 ];
            if (V1 >= 7)
            {
                A0 = A0 << (V1 - 6);
            }
            else if (V1 < 6)
            {
                A0 = A0 >> (6 - V1);
            }
        }

        if (hu[channel_data + 54] == 0)
        {
            [channels_config + c] = w(w[channels_config + c] | mask);
        }
        else
        {
            [80099fd4] = w(w[80099fd4] | mask);
        }

        [channel_data + e0] = w(w[channel_data + e0] | 00000013);

        V1 = h[channel_data + ce];
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
        [channel_data + 30] = w(A0);

        if (w[channel_data + 38] & 00000001)
        {
            V1 = (hu[channel_data + 7e] & 7f00) >> 8;
            if (hu[channel_data + 7e] & 8000)
            {
                V0 = V1 * A0;
            }
            else
            {
                V0 = V1 * (A0 * f) >> 8;
            }

            [channel_data + 7c] = h(V0 >> 7);
            [channel_data + 18] = w(w[8004a5cc + hu[channel_data + 7a] * 4]);
            [channel_data + 74] = h(hu[channel_data + 72]);
            [channel_data + 78] = h(1);
        }

        if (w[channel_data + 38] & 00000002)
        {
            [channel_data + 1c] = w(w[8004a5cc + hu[channel_data + 8e] * 4]);
            [channel_data + 88] = h(hu[channel_data + 86]);
            [channel_data + 8c] = h(1);
        }

        if (w[channel_data + 38] & 00000004)
        {
            V0 = hu[channel_data + 9c];
            [channel_data + 9a] = h(1);
            [channel_data + 20] = w(w[8004a5cc + V0 * 4]);
        }

        [channel_data + d6] = h(0);
        [channel_data + d8] = h(0);
        [channel_data + 34] = w(0);
    }

    A0 = h[channel_data + d2];

    [channel_data + 6e] = h((hu[channel_data + 6e] & fffd) | ((hu[channel_data + 6e] & 0001) << 1));
    V1 = A0;

    if (A0 != 0)
    {
        [channel_data + d0] = h(hu[channel_data + d0] + V1);

        S2 = bu[channel_data + d0] + bu[channel_data + cc];

        if (hu[channel_data + 54] == 0)
        {
            A0 = w[80075f38 + hu[channel_data + 58] * 40 + ((S2 & ff) % c) * 4];

            V0 = h[channel_data + ce];
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
            A0 = (w[80075f38 + hu[channel_data + 58] * 40 + ((S2 & ff) % c) * 4]) << 10; // get pitch
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

        [channel_data + 64] = h(hu[channel_data + 68]);
        [channel_data + d2] = h(0);
        [channel_data + 4c] = w((A0 + w[channel_data + 34] - (w[channel_data + 30] << 10)) / hu[channel_data + 64]);
    }

    [channel_data + d4] = h(hu[channel_data + cc]);
    [channel_data + 6a] = h(hu[channel_data + d0]);
}
////////////////////////////////



////////////////////////////////
// func318bc
// next opcode
pointer = w[A0 + 0];
A3 = hu[A0 + b8];

while (true)
{
    V1 = bu[pointer];

    if (V1 < 9a)
    {
        if (V1 >= 8f)
        {
            [A0 + 6c] = h(0);
            [A0 + 6e] = h([A0 + 6e] & fffa);
        }

        return bu[pointer];
    }

    if (V1 < a0)
    {
        return a0;
    }

    V0 = bu[800498a8 + V1]; // size of opcodes
    if (V0 == 0)
    {
        switch(V1)
        {
            case c9:
            {
                pointer = pointer + 1;
                A2 = A3 & ffff;

                if ((bu[pointer] + 1) == hu[A0 + A2 * 2 + ba])
                {
                    pointer = pointer + 1;
                    A3 = (A3 + ffff) & 3;
                }
                else
                {
                    pointer = w[A0 + A3 * 4 + 4] ;
                }
                continue;
            }
            break;

            case ca:
            {
                pointer = w[A0 + A3 * 4 + 4] ;
                continue;
            }
            break;

            case cb cd d1 db:
            {
                pointer = pointer + 1;
                [A0 + 6c] = h(0);
                [A0 + 6e] = h(hu[A0 + 6e] & fffa);
                continue;
            }
            break;

            case ee:
            {
                pointer = pointer + 1;
                A2 = h[pointer];
                pointer = pointer + A2 + 2;
                continue;
            }
            break;

            case ef:
            {
                pointer = pointer + 1;
                A2 = bu[pointer];
                pointer = pointer + 1;
                if (hu[8009a152] >= A2)
                {
                    A2 = h[pointer];
                    pointer = pointer + A2 + 2;
                }
                else
                {
                    pointer = pointer + 2;
                }

                continue;
            }
            break;

            case f0 f1:
            {
                pointer = pointer + 1;
                if (bu[pointer] == (hu[A0 + A3 * 2 + ba] + 1))
                {
                    V1 = A3 + ffff;
                    pointer = pointer + 1;
                    A2 = h[A1];
                    A3 = V1 & 3;
                    pointer = pointer + A2 + 2;
                }
                else
                {
                    pointer = pointer + 3;
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

    pointer = pointer + V0;
}
////////////////////////////////