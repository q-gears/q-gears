////////////////////////////////
// func2f848

S4 = 0;

// update reverb
if (w[8009a104 + 38] & 00000080)
{
    reverb_depth = h[8009a104 + 42];
    V1 = hu[80062fb8];

    [8009c564] = w(6);

    if (V1 < 80)
    {
        reverb_depth = reverb_depth + ((reverb_depth * V1) >> 7);
    }
    else
    {
        reverb_depth = (reverb_depth * V1) >> 8;
    }

    V1 = hu[80062f70];
    if (V1 < 40)
    {
        [8009c56c] = h(reverb_depth);
        [8009c56e] = h(reverb_depth - ((reverb_depth * (V1 ^ 3f)) >> 6));
    }
    else
    {
        [8009c56c] = h(reverb_depth - ((reverb_depth * (V1 & 3f)) >> 6));
        [8009c56e] = h(reverb_depth);
    }

    A0 = 8009c564;
    func3884c; // update reverb depth left and right

    [8009a104 + 38] = w(w[8009a104 + 38] ^ 00000080);
}



// update noise clock frequency
if (w[8009a104 + 38] & 00000010)
{
    V0 = w[80099fcc];
    if (V0 != 0)
    {
        A0 = hu[80099ffa];
    }
    else
    {
        A0 = hu[8009a156];
    }

    func37b90;

    [8009a13c] = w(w[8009a13c] ^ 00000010);
}



S2 = w[8009a168];
if (S2 != 0)
{
    S1 = 1;

    S6 = 0;
    S3 = 80097ec8;
    S5 = (0 NOR (w[80099fcc] | w[80062f00])) & w[80062f68];
    S2 = S2 & S5 & w[8009a170];
    S4 = S5 & w[8009a16c];

    loop2fa20:	; 8002FA20
        if (S2 & S1)
        {
            A0 = S3;
            A1 = S1;
            A2 = S6;
            func2ed34; // UpdatePitchAndVolume

            if (w[S3 + e0] != 0)
            {
                A1 = w[S3 + 38]
                if (A1 & 00000100)
                {
                    A0 = S3;
                    A1 = S5;
                    A2 = w[S3 + 24] - 18;
                    func2f738;

                    S2 = S2 ^ S1;
                }
                else if ((A1 & 00000200) == 0)
                {
                    A0 = w[S3 + dc];
                    A1 = S3 + dc;
                    func2e23c; // update params to spu
                }
                else
                {
                    if (S1 & w[8009a16c])
                    {
                        [S3 + 38] = w(A1 ^ 00000400);
                        [S3 + e0] = w(w[S3 + e0] | 0001ff93);
                    }

                    if (w[S3 + 38] & 00000400)
                    {
                        A0 = w[S3 + 28];
                        if (S5 & (1 << A0))
                        {
                            A1 = S3 + dc;
                            func2e23c; // update params to spu

                            if (S4 & S1)
                            {
                                S4 = (S4 | (1 << w[S3 + 28])) & (0 NOR S1);
                            }
                        }
                    }
                    else
                    {
                        A0 = w[S3 + dc];
                        A1 = S3 + dc;
                        func2e23c; // update params to spu
                    }
                }
            }

            S2 = S2 ^ S1;
        }

        S1 = S1 << 1;
        S3 = S2 + 108;
        S6 = S6 + 1;
    8002FB28	bne    s2, zero, loop2fa20 [$8002fa20]

    [8009a16c] = w(0);
}



if (w[8009a108] != 0)
{
    S6 = 0;
    S3 = 80096608;
    S5 = 0 NOR (w[80062f68] | w[80099fcc] | w[80062f00]);
    S2 = w[8009a108] & (S5 & w[8009a110]);
    S4 = S4 | (S5 & w[8009a10c]);

    S1 = 1;
    loop2fba8:	; 8002FBA8
        if (S2 & S1)
        {
            A0 = S3;
            A1 = S1;
            A2 = S6;
            func2ed34; // UpdatePitchAndVolume

            if (w[S3 + e0] != 0)
            {
                if (w[80062fd8] & S1)
                {
                    [S3 + 104] = h(0);
                    [S3 + 106] = h(0);
                }

                if (w[S3 + 38] & 00000100)
                {
                    A0 = S3;
                    A1 = S5;
                    A2 = w[S3 + 24];
                    func2f738;
                }
                else if (w[S3 + 38] & 0200)
                {
                    if (w[8009a10c] & S1)
                    {
                        [S3 + 38] = w(w[S3 + 38] ^ 00000400);
                        [S3 + e0] = w(w[S3 + e0] | 0001ff93);
                    }

                    if (w[S3 + 38] & 00000400)
                    {
                        if (S5 & (1 << w[S3 + 28]))
                        {
                            A0 = w[S3 + 28];
                            A1 = S3 + dc;
                            func2e23c; // update params to spu

                            if (S4 & S1)
                            {
                                S4 = (S4 | (1 << w[S3 + 28])) & (0 NOR S1);
                            }
                        }
                        else
                        {
                            A0 = w[S3 + dc];
                            A1 = S3 + dc;
                            func2e23c; // update params to spu
                        }
                    }
                    else
                    {
                        A0 = w[S3 + dc];
                        A1 = S3 + dc;
                        func2e23c; // update params to spu
                    }
                }
                else
                {
                    A0 = w[S3 + dc];
                    A1 = S3 + dc;
                    func2e23c; // update params to spu
                }
            }

            S2 = S2 ^ S1;
        }

        S1 = S1 << 1;
        S3 = S3 + 108;
        S6 = S6 + 1;
    8002FCCC	bne    s2, zero, loop2fba8 [$8002fba8]

    [8009a10c] = w(0);
}



S2 = w[80099fcc];
if (S2 != 0)
{
    S1 = 00010000;
    S3 = 80099788;
    S4 = S4 | w[80099fd0];
    S2 = S2 & w[80099fd4];

    loop2fd18:	; 8002FD18
        if (S2 & S1)
        {
            A0 = S3;
            A1 = S1;
            func2f24c;

            S2 = S2 XOR S1;
            if (w[S3 + e0] != 0) // if at least one flag to update
            {
                A0 = w[S3 + dc];
                A1 = S3 + dc;
                func2e23c; // update params to spu
            }
        }

        S1 = S1 << 1;
        S3 = S3 + 108;
    8002FD50	bne    s2, zero, loop2fd18 [$8002fd18]

    [80099fd0] = w(0);
}



if (S4 != 0)
{
    A0 = 1;
    A1 = S4;
    func38c6c; // We enable channel here.
}
////////////////////////////////