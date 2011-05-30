/////////////////////////////////////////////////////
// funcce05c
address = A0;
S2 = A1;

[800fe514] = w(address);
[800fe504] = w(address + 10);

[800fe50c] = w(h[address + 0]); // some id from battle location structure

A0 = 0;
funccf58c;

[800fe4f8] = w(0);

if (h[address + 6] != 0)
{
    [800fe4f0] = w(1);
}

V0 = h[address + 4];
[800fe510] = w(V0);
V0 = h[address + 2];
[800fe4f4] = w(S2);
[800fe508] = w(V0);
if (V0 != 0)
{
    A0 = S2;
    A1 = 0;
    funcc9374;

    V0 = w[800fe508];
    if (V0 > 0)
    {
        A1 = 0;
        loopce110:	; 800CE110
            V1 = w[800fe4f4] + A1 * 14;
            V0 = bu[V1 + 4];
            [V1 + 04] = b(V0 | 0001);
            [V1 + 0c] = w(0);
            [V1 + 12] = h(1000);

            V1 = w[800fe508];
            A1 = A1 + 1;
            V1 = A1 < V1;
        800CE144	bne    v1, zero, loopce110 [$800ce110]
    }
}

[800fe518] = w(h[address + a]);

A0 = f;
funcceec8;

[800fe4f0] = w(0);

V0 = w[8006794c];
V1 = w[V0 + 1c];
V0 = bu[V1 + 570];

[800f7274] = w(V0);
if (V0 >= 1f)
{
    [800f7274] = w(1f);
}
/////////////////////////////////////////////////////
