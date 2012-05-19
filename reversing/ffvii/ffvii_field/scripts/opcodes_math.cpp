////////////////////////////////
// 0x9F SEARCHX
field_file_offset     = w[8009c6dc];
current_entity        = bu[800722c4];
script_pointer_offset = 800831fc + current_entity * 2;
script = field_file_offset + hu[script_pointer_offset];

S0 = bu[script + 1] >> 4;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
S2 = bu[script + 4] + V0; // diapason start

A0 = 3;
A1 = 7;
read_memory_block_two_bytes;
S1 = bu[script + 4] + V0; // diapason end

A0 = 4;
A1 = 9;
read_memory_block_one_byte;
search_x = V0;

switch( S0 )
{
    case f: // D4140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case d: // DC140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case b: // E4140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case 3: // EC140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case 1: // F4140C80
    {
        if( S2 >= 500 )
        {
            S2 = 4ff;
        }

        if( S1 >= 500 )
        {
            S1 = 4ff;
        }

        if( S1 >= S2 )
        {
            loopc1540:	; 800C1540
                if( bu[8009c6e4 + ba4 + S2] == search_x )
                {
                    A0 = 6;
                    A1 = a;
                    A2 = S2;
                    store_memory_block_two_bytes;

                    [script_pointer_offset] = h(hu[script_pointer_offset] + b);
                    return;
                }

                S2 = S2 + 1;
                V0 = S1 < S2;
            800C1570	beq    v0, zero, loopc1540 [$800c1540]
        }
    }
    break;

    case 5: // 98150C80
    {
        if( S2 >= 100 )
        {
            S2 = ff;
        }

        if( S1 >= 100 )
        {
            S1 = ff;
        }

        if( S1 >= S2 )
        {
            loopc15e4:	; 800C15E4
                if( bu[80075e24 + S2] == search_x )
                {
                    A0 = 6;
                    A1 = a;
                    A2 = S2;
                    store_memory_block_two_bytes;

                    [script_pointer_offset] = h(hu[script_pointer_offset] + b);
                    return;
                }

                S2 = S2 + 1;
                V0 = S1 < S2;
            800C1614	beq    v0, zero, loopc15e4 [$800c15e4]
        }
    }
    break
}

A0 = 6;
A1 = a;
A2 = -1;
store_memory_block_two_bytes;

[script_pointer_offset] = h(hu[script_pointer_offset] + b);
////////////////////////////////



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