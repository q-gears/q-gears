////////////////////////////////
// func2daac
norm_x = A0;
norm_y = A1;
norm_z = A2;
if (norm_x < 0)
{
    norm_x = -norm_x;
}
if (norm_y < 0)
{
    norm_y = -norm_y;
}
if (norm_z < 0)
{
    norm_z = -norm_z;
}

if (norm_x >= norm_y && norm_x >= norm_z)
{
    return A0;
}

if (norm_y >= norm_x && norm_y >= norm_z)
{
    return A1;
}

if (norm_z >= norm_x && norm_z >= norm_y)
{
    return A2;
}
////////////////////////////////



////////////////////////////////
// system_square_root
LZCS = A0;
V0 = LZCR;
if (V0 != 20) // if data is positive
{
    T0 = V0 & 00000001;
    T2 = V0 & fffffffe;
    T1 = 1f - T2;
    T1 = T1 >> 1;
    T3 = T2 - 18;
    if (T3 < 0 || (A0 << T3) == 0)
    {
        T4 = A0 >> (18 - T2);
    }
    else
    {
        T4 = A0 << T3;
    }

    T5 = h[800560a0 + (T4 - 40) * 2];
    T5 = T5 << T1;
    return T5 >> c;
}
////////////////////////////////
