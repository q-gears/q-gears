////////////////////////////////
// funcb3934
A0 = 2;
funcb5d38;

A0 = 2;
funcb5cd4;

[80166f64] = b(3);
////////////////////////////////



////////////////////////////////
// funcb3968
A0 = 1;
funcb5d38;

A0 = 1;
funcb5cd4;

[80166f64] = b(2);

[800f8398] = w(w[800f8394] + V0);

if (bu[800f7df4] >= 3) // number of inited enemy
{
    V0 = w[800f7e00];
    A0 = w[800e8050 + V0 * 8 + 0];
    A1 = w[800e8050 + V0 * 8 + 4];
    A2 = 801b0000;
    A3 = 800b3934;
    func33e74;

    funcb7fb4;
}
////////////////////////////////



////////////////////////////////
// funcb3a04
[800f8390] = w(80130200);

A0 = 0;
funcb5d38;

A0 = 0;
funcb5cd4;

[80166f64] = b(1);

[800f8394] = w(w[800f8390] + V0);

if (bu[800f7df4] >= 2) // number of inited enemy
{
    V0 = w[800f7dfc];
    A0 = w[800e8050 + V0 * 8 + 0];
    A1 = w[800e8050 + V0 * 8 + 4];
    A2 = 801b0000;
    A3 = 800b3968;
    func33e74;

    funcb7fb4;
}
////////////////////////////////



////////////////////////////////
// funcb5d38
S1 = A0;

V1 = hu[80163614];
if (V1 == 4e) // if final battle with sephiroth field
{
    A1 = S1 + 13;
    A2 = 0;
    A3 = 0;
}
else
{
    A1 = S1 + 12;
    A2 = 0;
    A3 = (S1 + 3) * 3;
}

// load texture
A0 = 801b0000 + w[801b0000 + w[801b0000] * 4]; // offset to last block in battle model file
funcd2980;



S3 = S1 + 3;
S0 = 4;

if (bu[800f7e04] + 4 >= S0)
{
    S1 = 0;

    loopb5dec:	; 800B5DEC
        if (h[800f7e08 + S1] == S3) // enemy id
        {
            A0 = 801b0000 + w[801b0000 + w[801b0000] * 4]; // offset to last block in battle model file
            A1 = S0;
            funcc614c;
        }

        S1 = S1 + c;
        S0 = S0 + 1;
        V0 = bu[800f7e04] + 4 >= S0;
    800B5E3C	bne    v0, zero, loopb5dec [$800b5dec]
}
////////////////////////////////



////////////////////////////////
// funcb5cd4
// copy battle field

A0 = w[800f8390 + A0 * 4]; // 80130200 address where we copy model data
A1 = 8001b0000; // from where
A2 = w[S0 + w[S0] * 4]; // how much
func1c3cc;

return w[S0 + w[S0] * 4];
////////////////////////////////
