////////////////////////////////
// func3e6e4
if (A1 < 18 && w[80061bbc + A1 * 4] == A0)
{
    [80061bbc + A1 * 4] = w(0);
    V0 = 1 << A1; // channel mask

    [80058b98] = w(w[80058b98] & (0 NOR V0)); // remove channel bit from SPU Voice ON mask
    [80058bf0] = w(w[80058bf0] | V0); // add channel bit
}
////////////////////////////////



////////////////////////////////
// func3a0b4
A0 = A0 & fe;
A0 = A0 XOR 8;

S3 = w[80058c74];

S0 = S3 + A0 * 158;

S2 = 2;
loop3a110:	; 8003A110
    if (hu[S0 + 94] & 0001)
    {
        [S0 + 94] = h(0);

        V0 = 1 << bu[S0 + 9a];
        [S3 + 48] = w(w[S3 + 48] & (0 NOR V0)); // remove bit

        A0 = S0 + c4; // stored channel address
        A1 = bu[S0 + 27]; // channel id
        func3e6e4;
    }

    S2 = S2 - 1;
    S0 = S0 + 158;
8003A150	bne    s2, zero, loop3a110 [$8003a110]
////////////////////////////////



////////////////////////////////
// func39e44
sound_id = A0;
if (hu[80058c18] & 0800)
{
    [80058aa0] = w(2);

    A0 = A1 & fe;
    A0 = A0 XOR 8;

    A0 = A0 | 2000;
    A1 = sound_id;
    A2 = A2 << 8;
    A3 = A3 << 8;
    func3b4ec;
}
////////////////////////////////



////////////////////////////////
// func3b4ec
S2 = w[80058adc]; // pointer to 0391.sed file.

FP = A2;
sound_id = A1;
V1 = sound_id >> 10;
[SP + 18] = h(A3);

S4 = w[80058c74];
S0 = A0;

if (hu[S2 + 14] != V1)
{
    loop3b544:	; 8003B544
        S2 = w[S2 + 1c];
        if (S2 == 0)
        {
            return;
        }
        V0 = hu[S2 + 14];
    8003B55C	bne    v0, v1, loop3b544 [$8003b544]
}

A0 = hu[S2 + 16];
8003B568	jal    func38294 [$80038294]

S7 = V0;

if (S7 == 0)
{
    S7 = w[80058bf4];
}

V0 = S2 + hu[S2 + 18] + sound_id;
V0 = FP * bu[V0];

FP = V0 >> 7;

if ((FP >> f) & 1)
{
    FP = 7fff;
}

sound_sequence = S2 + 20 + sound_id * 4;

channel = S4 + S0 * 158;

A0 = w[80058c58];
8003B60C	jal    func4032c [$8004032c]



S6 = w[80058aa0];
loop3b614:	; 8003B614
    [channel + 98] = b(S0 >> 8);
    [channel + 9c] = w(sound_id);
    [channel + a0] = w(w[80058ba0]);

    if (hu[sound_sequence] != 0)
    {
        [S4 + 48] = w(w[S4 + 48] | (1 << bu[channel + 9a]));

        [channel + 94] = ((hu[S2 + 10] & 1)) ? h(40b) : h(409);
        [channel + 96] = h(170);
        [channel + 98] = h(0);
        [channel + a4] = w(S2 + hu[sound_sequence]); // sequence_offset
        [channel + a8] = w(S2 + hu[sound_sequence]); // sequence_offset
        [channel + ac] = w(0);
        [channel + b0] = w(0);
        [channel + b4] = h(0);
        [channel + b6] = b(0);
        [channel + b9] = b(bu[S2 + 16]);
        [channel + c0] = w(S7);
        [channel + d0] = h(0);
        [channel + d2] = h(0);
        [channel + f0] = h(0);
        [channel + f4] = b(0);
        [channel + f6] = h(f);
        [channel + f8] = b(0);
        [channel + fa] = h(3c);
        [channel + 102] = h(0);
        [channel + 104] = h(0);
        [channel + 106] = h(ffff);
        [channel + 108] = h(hu[SP + 18]);
        [channel + 10a] = h(FP); // 10a
        [channel + 10c] = w(7f000000);

        [channel + 158 + a] = h(0);
        [channel + 158 + c] = h(0);
        [channel + 158 + e] = h(0);
        [channel + 158 + 10] = h(0);

        [channel + 158 + 52] = h(0);
        [channel + 158 + 72] = h(0);
        [channel + 158 + 92] = h(0);

        if (S7 != 0)
        {
            A0 = 0;
            A1 = channel + 94;
            func3e464; // init some sounds data
        }

        [channel + c6] = h(0);
        [channel + c8] = h(200);

        A0 = channel + c4;
        A1 = bu[channel + bb];
        8003B73C	jal    func3e5cc [$8003e5cc]
    }
    else
    {
        [S4 + 48] = w(w[S4 + 48] & (0 NOR (1 << bu[channel + 9a])));

        [channel + 94] = h(0);

        A0 = channel + c4;
        A1 = bu[channel + bb];
        8003B76C	jal    func3e6e4 [$8003e6e4]
    }

    sound_sequence = sound_sequence + 2;
    channel = channel + 158;

    S6 = S6 - 1;
8003B784	bne    s6, zero, loop3b614 [$8003b614]

[S4 + 10] = h(hu[S4 + 10] | 8000);

A0 = w[80058c58];
8003B79C	jal    func4031c [$8004031c]
////////////////////////////////