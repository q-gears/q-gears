////////////////////////////////
// system_execute_AKAO
S3 = 0;
V1 = hu[8009a000];

[80062f8c] = w(1);

if (V1 == 10 || V1 == 14 || V1 == 15 || V1 == 18 || V1 = 19)
{
    akao_offset = w[8009a004];
    if (bu[akao_offset + 0] != 41 && bu[akao_offset + 1] != 4b && bu[akao_offset + 2] != 41 && bu[akao_offset + 3] != 4f)
    {
        S3 = -1;
    }
    else
    {
        S1 = hu[akao_offset + 4]; // id
        S2 = hu[akao_offset + 6]; // length

        if (hu[8009a14e] == S1)
        {
            S3 = 1;
        }
        else
        {
            A0 = hu[akao_offset + 8]; // reverb_mode
            func29af0;

            A0 = SP + 10;
            func2da30;

            V0 = w[SP + 10];
            [V0 + 0] = w(w[8009a000]);
            [V0 + 4] = w(akao_offset + 16);
            [V0 + 8] = w(S2);
            [V0 + c] = w(S1);
            [V0 + 10] = w(w[8009a008]);
        }
    }
}
else if (V1 == 24)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(20);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
}
else if (V1 == 25)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(21);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
    [V1 + c] = w(w[8009a008] + 1);
}
else if (V1 == 26)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(22);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
    [V1 + c] = w(w[8009a008] + 1);
    [V1 + 10] = w(w[8009a008] + 2);
}
else if (V1 == 27)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(23);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
    [V1 + c] = w(w[8009a008] + 1);
    [V1 + 10] = w(w[8009a008] + 2);
    [V1 + 14] = w(w[8009a008] + 3);
}
else if (V1 == 98)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(9a);

    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(9c);
}
else if (V1 == 99)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(9b);

    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(9d);
}
else if (V1 == d8)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(d0);
    [V1 + 4] = w(w[8009a004]);

    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(d4);
    [V1 + 4] = w(w[8009a004]);
}
if (V1 == d9)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(d1);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);

    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(d5);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
}
else if (V1 == da)
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(d2);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
    [V1 + c] = w(w[8009a00c]);

    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = h(d6);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
    [V1 + c] = w(w[8009a00c]);
}
else
{
    A0 = SP + 10;
    func2da30;

    V1 = w[SP + 10];
    [V1 + 0] = w(w[8009a000]);
    [V1 + 4] = w(w[8009a004]);
    [V1 + 8] = w(w[8009a008]);
    [V1 + c] = w(w[8009a00c]);
    [V1 + 10] = w(w[8009a010]);
    [V1 + 14] = w(w[8009a014]);
}

[80062f8c] = w(0);
return S3;
////////////////////////////////



////////////////////////////////
// func2da30
[A0] = w(80081dc8 + w[80063010] * 24);
[80063010] = w(w[80063010] + 1);
////////////////////////////////



////////////////////////////////
// func29af0
S0 = A0;
80029B00	jal    func29a50 [$80029a50]

S1 = 8009c564;

A0 = S1;
80029B10	jal    func387fc [$800387fc]

V0 = w[8009c568];
if (V0 != S0)
{
    80029B2C	lui    at, $800a
    80029B30	sw     s0, $a140(at)
    80029B34	jal    func37c40 [$80037c40]
    80029B38	addu   a0, zero, zero
    80029B3C	addu   a0, s1, zero
    80029B40	ori    v0, s0, $0100
    80029B44	lui    at, $800a
    80029B48	sw     v0, $c568(at)
    80029B4C	ori    v0, zero, $0001
    80029B50	jal    func37e1c [$80037e1c]
    80029B54	sw     v0, $0000(a0)
    80029B58	jal    func37c40 [$80037c40]
    80029B5C	ori    a0, zero, $0001
}
////////////////////////////////


////////////////////////////////
// func29a50
80029A58	jal    func38fec [$80038fec]
80029A5C	addu   a0, zero, zero
80029A60	jal    func38a84 [$80038a84]
80029A64	addu   a0, zero, zero
80029A68	jal    func38c04 [$80038c04]
80029A6C	addu   a0, zero, zero
80029A70	lui    a1, $8006
80029A74	lw     a1, $2f00(a1)
80029A78	jal    func38c6c [$80038c6c]
80029A7C	addu   a0, zero, zero
80029A80	lui    v1, $8006
80029A84	lw     v1, $2f00(v1)
80029A88	lui    v0, $0001
80029A8C	and    v0, v1, v0
80029A90	beq    v0, zero, L29aa4 [$80029aa4]
80029A94	lui    v0, $0001
80029A98	ori    v0, v0, $ff93
80029A9C	lui    at, $8009
80029AA0	sw     v0, $7768(at)

L29aa4:	; 80029AA4
80029AA4	lui    v0, $0002
80029AA8	and    v0, v1, v0
80029AAC	beq    v0, zero, L29ac0 [$80029ac0]
80029AB0	lui    v0, $0001
80029AB4	ori    v0, v0, $ff93
80029AB8	lui    at, $8009
80029ABC	sw     v0, $7870(at)

L29ac0:	; 80029AC0
80029AC0	lui    at, $8006
80029AC4	sw     zero, $2f00(at)
80029AC8	jal    func30038 [$80030038]
80029ACC	nop
80029AD0	jal    func30148 [$80030148]
80029AD4	nop
80029AD8	jal    func2ff4c [$8002ff4c]

////////////////////////////////