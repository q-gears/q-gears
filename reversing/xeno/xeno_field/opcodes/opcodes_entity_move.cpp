////////////////////////////////
// 0x4A SpriteGoToPosition

entity = w[800af54c];

V1 = bu[entity + ce];
[entity + 8c + V1 * 8 + 4] = w((w[entity + 8c + V1 * 8 + 4] & fe7fffff) | 0000ffff);

A0 = ffff;
func99094;

if (V0 == 0)
{
    [entity + cc] = h(hu[entity + cc] + 6);
}
////////////////////////////////



////////////////////////////////////////////////////////
// func99094
current_entity_data = w[800af54c];
entity_id           = w[800af1f0]; // current entity id

S6 = A0; // ffff
S2 = 0;
S1 = 0;
S0 = 0;

V0 = w[800aefe4];
V1 = w[V0 + entity_id * 5c + 4c];
V1 = w[V1 + 4];
A0 = w[V0 + entity_id * 5c + 4];
if (V1 & 00002000)
{
    [A0 + 18] = w(08000000 / hu[current_entity_data + 76]);
}
else if (w[A0 + 18] == 0)
{
    [A0 + 18] = w(04000000 / hu[current_entity_data + 76]);
}

A0 = w[A0 + 18];
A0 = A0 >> f;
length_of_vector_by_x;
S5 = V0 + 1;

S3 = h[current_entity_data + 22];
S4 = h[current_entity_data + 2a];



V1 = bu[current_entity_data + ce];
V1 = (w[current_entity_data + 8c + V1 * 8 + 4] >>> 17) & 3;

switch (V1)
{
    case 0:
    {
        V1 = w[800ad0d8];
        V0 = hu[current_entity_data + cc];

        A0 = 1;
        A1 = bu[V1 + V0 + 5];
        read_two_bytes_based_on_flag_80;
        S1 = V0;

        A0 = 3;
        A1 = bu[V1 + V0 + 5];
        read_two_bytes_based_on_flag_40;
        S0 = V0;
    }
    break;

    case 1:
    {
        V1 = w[800ad0d8];
        V0 = hu[current_entity_data + cc];

        A0 = 1;
        A1 = bu[V1 + V0 + 5];
        read_two_bytes_based_on_flag_80;
        S1 = V0 + w[current_entity_data + d0];

        A0 = 3;
        A1 = bu[V1 + V0 + 5];
        read_two_bytes_based_on_flag_40;
        S0 = V0 + w[current_entity_data + d8];
    }
    break;

    case 2:
    {
        A0 = 1;
        get_entity_id_from_opcode;
        if (V0 == ff)
        {
            return 0;
        }

        A0 = w[800aefe4];
        S0 = w[A0 + V0 * 5c + 4c];

        A0 = hu[current_entity_data + 1e] + hu[S0 + 1e]; // solid range?
        length_of_vector_by_x;
        S2 = V0;

        S1 = h[S0 + 22];
        S0 = h[S0 + 2a];

        V1 = w[800ad0d8];
        V0 = hu[current_entity_data + cc];
        V1 = bu[V0 + V1 + 1]; // byte in opcode

        V0 = w[800b1740]; // party leader
        if (V1 == V0)
        {
            [current_entity_data + 0] = w(w[current_entity_data + 0] | 00200000);
        }
    }
    break;

    case 3:
    {
        A0 = 1;
        read_two_bytes_with_80;
        S0 = V0;

        A0 = S0;
        func3f774;

        V0 = V0 << c;
        V1 = w[current_entity_data + d0];
        V0 = V0 >> c;
        S1 = V1 + V0;

        A0 = S0;
        func3f758;
        V0 = V0 << c;
        V0 = 0 - V0;
        V1 = w[current_entity_data + d8];
        V0 = V0 >> c;
        S0 = V1 + V0;
    }
    break;
}

A0 = S1 - S3;
A1 = S0 - S4;
[SP + 10] = w(A0);
[SP + 14] = w(0);
[SP + 18] = w(A1);

length_of_vector_by_x_y; // calculate how much we need to go

A0 = w[current_entity_data + 00] | 00400000;
[current_entity_data + 00] = w(A0);

V1 = bu[current_entity_data + ce]
A1 = h[current_entity_data + 8c + V1 * 8 + 4];

if (A1 == 0 || S5 + S2 >= V0) // we finished
{
    if (S6 != 0)
    {
        if ((A0 & 00008000) == 0)
        {
            V0 = hu[current_entity_data + 106];
        }
        else
        {
            V0 = hu[current_entity_data + 11c];
        }

        V0 = V0 | 8000;
        [current_entity_data + 104] = h(V0);
        [current_entity_data + 106] = h(V0);
    }
    else
    {
        A0 = SP + 10;
        func7aca8;

        [current_entity_data + 104] = h(V0);
        [current_entity_data + 106] = h(V0);
    }

    V1 = bu[current_entity_data + ce];
    [current_entity_data + 8c + V1 * 8 + 4] = h(ffff);
    [current_entity_data + 8c + V1 * 8 + 4] = w(w[current_entity_data + 8c + V1 * 8 + 4] & fe7fffff);

    [current_entity_data + 00] = w(w[current_entity_data + 00] & f7fffddf);

    return 0;
}
else
{
    [current_entity_data + 8c + V1 * 8 + 4] = h(A1 - 1);

    A0 = SP + 10;
    func7aca8;
    [current_entity_data + 104] = h(V0);
    [current_entity_data + 106] = h(V0);

    [800af594] = w(1); // set wait

    return -1;
}
////////////////////////////////////////////////////////