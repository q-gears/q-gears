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



if (w[8009a104 + 38] & 00000010)
{
    8002F968	lui    v0, $800a
    8002F96C	lw     v0, $9fcc(v0)

    if (V0 != 0)
    {
        A0 = hu[80099ffa];
    }
    else
    {
        A0 = hu[8009a156];
    }

    8002F994	jal    func37b90 [$80037b90]

    8002F99C	lui    v0, $800a
    8002F9A0	lw     v0, $a13c(v0)
    8002F9A4	nop
    8002F9A8	xori   v0, v0, $0010
    8002F9AC	lui    at, $800a
    8002F9B0	sw     v0, $a13c(at)
}



S2 = w[8009a168];
if (S2 != 0)
{
    8002F9C8	ori    s1, zero, $0001
    8002F9CC	addu   s6, zero, zero
    S3 = 80097ec8;
    8002F9D8	ori    s7, zero, $0001
    S0 = S3 + dc;
    8002F9E0	lui    v1, $800a
    8002F9E4	lw     v1, $9fcc(v1)
    8002F9E8	lui    v0, $8006
    8002F9EC	lw     v0, $2f00(v0)
    8002F9F0	lui    a0, $8006
    8002F9F4	lw     a0, $2f68(a0)
    8002F9F8	or     v1, v1, v0
    8002F9FC	nor    v1, zero, v1
    8002FA00	and    s5, v1, a0
    8002FA04	lui    v0, $800a
    8002FA08	lw     v0, $a170(v0)
    8002FA0C	lui    v1, $800a
    8002FA10	lw     v1, $a16c(v1)
    8002FA14	and    v0, s5, v0
    8002FA18	and    s2, s2, v0
    8002FA1C	and    s4, s5, v1

    loop2fa20:	; 8002FA20
        8002FA20	and    v0, s2, s1
        if (V0 != 0)
        {
            8002FA28	addu   a0, s3, zero
            8002FA2C	addu   a1, s1, zero
            8002FA30	jal    func2ed34 [$8002ed34]
            8002FA34	andi   a2, s6, $ffff
            8002FA38	lw     v0, $0004(s0)
            if (V0 != 0)
            {
                A1 = w[S0 - a4]
                if (A1 & 0100)
                {
                    8002FA58	addu   a0, s3, zero
                    8002FA5C	lw     a2, $ff48(s0)
                    8002FA60	addu   a1, s5, zero
                    8002FA64	jal    func2f738 [$8002f738]
                    8002FA68	addiu  a2, a2, $ffe8 (=-$18)
                    8002FA70	xor    s2, s2, s1
                }
                else if ((A1 & 0200) == 0)
                {
                    A0 = w[S0];
                    A1 = S0;
                    func2e23c; // update params to spu
                }
                else
                {
                    8002FA80	lui    v0, $800a
                    8002FA84	lw     v0, $a16c(v0)
                    8002FA88	nop
                    8002FA8C	and    v0, s1, v0
                    if (V0 != 0)
                    {
                        8002FA94	lui    a0, $0001
                        8002FA98	ori    a0, a0, $ff93
                        8002FA9C	lw     v1, $0004(s0)
                        8002FAA0	xori   v0, a1, $0400
                        8002FAA4	sw     v0, $ff5c(s0)
                        8002FAA8	or     v1, v1, a0
                        8002FAAC	sw     v1, $0004(s0)
                    }

                    8002FAB0	lw     v0, $ff5c(s0)
                    8002FAB4	nop
                    8002FAB8	andi   v0, v0, $0400
                    if (V0 != 0)
                    {
                        8002FAC4	lw     a0, $ff4c(s0)
                        8002FAC8	nop
                        8002FACC	sllv   v0, a0, s7
                        8002FAD0	and    v0, s5, v0
                        if (V0 != 0)
                        {
                            A1 = S0;
                            func2e23c; // update params to spu

                            8002FAE4	and    v0, s4, s1
                            if (V0 != 0)
                            {
                                8002FAF0	lw     v0, $ff4c(s0)
                                8002FAF4	nop
                                8002FAF8	sllv   v0, v0, s7
                                8002FAFC	or     s4, s4, v0
                                8002FB00	nor    v0, zero, s1
                                8002FB08	and    s4, s4, v0
                            }
                        }
                    }
                    else
                    {
                        8002FB0C	lw     a0, $0000(s0)
                        8002FB14	addu   a1, s0, zero
                        func2e23c; // update params to spu
                    }
                }
            }

            8002FB18	xor    s2, s2, s1
        }

        8002FB1C	sll    s1, s1, $01
        8002FB20	addiu  s0, s0, $0108
        8002FB24	addiu  s3, s3, $0108
        8002FB2C	addiu  s6, s6, $0001
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
                        [S3 + 38] = w(w[S3 + 38] XOR 00000400);
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

            S2 = S2 XOR S1;
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