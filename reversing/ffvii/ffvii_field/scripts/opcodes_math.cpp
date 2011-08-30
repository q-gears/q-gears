////////////////////////////////
// 0xD4 SIN
A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
A0 = V0;
system_get_sin;
S0 = V0;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;

HI/LO = S0 * V0;
S0 = LO;

A0 = 3;
A1 = 7;
read_memory_block_two_bytes
S0 = S0 + V0;

A0 = 4;
A1 = 9;
A2 = S0 >> 0C;
store_memory_block_two_bytes;

A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + A;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// 0xD5 COS
A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
A0 = V0;
system_get_cos;
S0 = V0;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;

S0 = S0 * V0;

A0 = 3;
A1 = 7;
read_memory_block_two_bytes
S0 = S0 + V0;

A0 = 4;
A1 = 9;
A2 = S0 >> 0C;
store_memory_block_two_bytes;

A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + A;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// system_get_cos
if (A0 < 0)
{
    A0 = 0 - A0;
}

A0 = A0 & 0fff;
if (A0 < 801)
{
    if (A0 < 401)
    {
        V0 = 400;
        V0 = V0 - A0;
        V0 = V0 * 2;
        V0 = h[8004AE54 + V0];
    }
    else
    {
        V0 = A0 * 2;
        V0 = h[8004A654 + V0];
        V0 = 0 - V0;
    }
}
else
{
    if (A0 >= c01)
    {
        V0 = A0 * 2;
        V0 = h[8004A654 + V0];
    }
    else
    {
        V0 = c00;
        V0 = V0 - A0;
        V0 = V0 * 2;
        V0 = h[8004AE54 + V0];
        V0 = 0 - V0;
    }
}

return;
////////////////////////////////