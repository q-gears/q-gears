////////////////////////////////
// funcc2af0
// A0 - entity struct
// A1 - address of current triangle data pointer
// A2 - start position vector
// A3 - new position vector
// A4 = 0; or 1 in case of move
// A5 = 0;
// A6 = 0;
// A7 = 0;
// return 0 if we can move here

walkmesh_header         = w[800c9df8];
walkmesh_triangles_data = w[800c9e00];
walkmesh_normals_data   = w[800c9e04];
walkmesh_groups_data    = w[800c9e0c];

entity_struct = A0;
address_of_current_triangle_pointer = A1;

[SP + 60] = h(-1);
current_triangle_pointer = w[address_of_current_triangle_pointer];
[SP + 68] = h(A4);
[SP + 70] = h(A5);
[SP + 78] = h(-1);

S7 = A2; // start position vector
[SP + 20] = h(hu[S7 + 0]);
[SP + 22] = h(hu[S7 + 2]);
[SP + 24] = h(hu[S7 + 4]);

S2 = A3; // new position vector
[SP + 38] = h(hu[S2 + 0]);
[SP + 3a] = h(hu[S2 + 2]);
[SP + 3c] = h(hu[S2 + 4]);

FP = 0;


S1 = SP + 20;



S4 = 800c9df0;
S5 = hu[entity_struct + 6];
S6 = h[entity_struct + 6] * 28;

Lc2bb4:	; 800C2BB4
    // move vector = new position vector - start position vector
    [SP + 40] = h(hu[S2 + 0] - hu[SP + 20]);
    [SP + 42] = h(hu[S2 + 2] - hu[SP + 22]);
    [SP + 44] = h(hu[S2 + 4] - hu[SP + 24]);

    if (h[current_triangle_pointer + 6] >= 0)
    {
        A0 = walkmesh_normals_data + h[current_triangle_pointer + 6] * 10;
    }
    else
    {
        A0 = 800c9de4;
    }

    A1 = SP + 40; // move vector (modifiable)
    A2 = SP + 20; // start vector
    A3 = SP + 28; // output?
    funcc2390; // move vector acording to triangle normal.

    // new final position
    [S2 + 0] = h(hu[SP + 20] + hu[SP + 40]);
    [S2 + 2] = h(hu[SP + 22] + hu[SP + 42]);
    [S2 + 4] = h(hu[SP + 24] + hu[SP + 44]);



    A0 = walkmesh_header;
    A1 = walkmesh_groups_data + h[current_triangle_pointer + 4] * 20; // current triangle group data
    A2 = current_triangle_pointer;
    A3 = S2; // final position
    funcc4b30; // check in triangle

    if (V0 == 0)
    {
        A0 = walkmesh_header;
        A1 = walkmesh_groups_data + h[current_triangle_pointer + 4] * 20;
        A2 = current_triangle_pointer;
        A3 = S2; // final position pointer
        A4 = S7; // start position pointer
        A5 = SP + 20; // start position pointer
        A6 = SP + 60;
        A7 = h[SP + 60];
        funcc519c;

        A1 = V0 & ff;
        if (A1 != 0)
        {
            A0 = entity_struct;
            A1 = current_triangle_pointer;
            A2 = h[SP + 60];
            field_get_next_walkmesh_triangle_address; // return address of next triangle or 0 if we cant pass this side

            if (V0 == 0)
            {
                [entity_struct + 4] = h(hu[walkmesh_triangles_data + S6 + 4]);
                [entity_struct + 6] = h(S5);
                [address_of_current_triangle_pointer] = w(walkmesh_triangles_data + S6);
                return 1;
            }

            if (h[current_triangle_pointer + 6] >= 0)
            {
                [SP + 48] = h(hu[S2 + 0] - hu[SP + 20]);
                [SP + 4a] = h(hu[S2 + 2] - hu[S1 + 2]);
                [SP + 4c] = h(hu[S2 + 4] - hu[S1 + 4]);


                A0 = w[SP + 28] * w[SP + 28] + w[SP + 30] * w[SP + 30];
                system_square_root;
                S0 = V0;

                if (S0 == 0)
                {
                    [S2 + 2] = h(hu[S1 + 2]);
                }
                else
                {
                    A0 = h[SP + 48] * h[SP + 48];
                    A0 = A0 + h[SP + 4a] * h[SP + 4a];
                    A0 = A0 + h[SP + 4c] * h[SP + 4c];
                    system_square_root;
                    V0 = (V0 << 10) >> 10;

                    [SP + 50] = w((w[SP + 28] * V0) / S0);
                    [SP + 58] = w((w[SP + 30] * V0) / S0);
                    [SP + 54] = w(0);
                    [SP + 4a] = h(0);
                    [SP + 48] = h(hu[SP + 58]);

                    [SP + 4c] = h(0 - hu[SP + 50]);
                    [S2 + 0] = h(hu[SP + 20] + hu[SP + 58]);
                    [S2 + 2] = h(hu[S1 + 2] + hu[SP + 4a]);
                    [S2 + 4] = h(hu[S1 + 4] + hu[SP + 4c]);
                }
            }

            V0 = h[SP + 60];
            T6 = h[SP + 78];
            V1 = current_triangle_pointer + V0 * 2
            A0 = h[V1 + 18];
            A1 = hu[V1 + 18];
            if (A0 == T6)
            {
                [entity_struct + 4] = h(hu[walkmesh_triangles_data + S6 + 4]);
                [entity_struct + 6] = h(S5);
                [address_of_current_triangle_pointer] = w(walkmesh_triangles_data + S6);
                return 1;
            }

            
            T6 = hu[entity_struct + 6];
            [SP + 78] = h(T6);
            [entity_struct + 6] = h(A1);
            A0 = w[S4 + 10] + A0 * 28;
            A1 = hu[A0 + 4];
            V1 = w[S4 + 18] + h[V1 + 12] * 4;
            [entity_struct + 4] = h(A1);
            V1 = h[V1 + 2];

            V0 = -1;
            current_triangle_pointer = A0;
            [SP + 60] = h(V1);

            if (V1 != -1)
            {
                [address_of_current_triangle_pointer] = w(current_triangle_pointer);
                return 0;
            }

            [entity_struct + 6] = h(S5);
            V1 = w[S4 + 10] + S6;
            [entity_struct + 4] = h(hu[V1 + 4]);
            [address_of_current_triangle_pointer] = w(V1);
            return 1;
        }



        // remove visit flags from all triangles
        number_of_triangles = hu[walkmesh_header + 24];
        if (A1 < number_of_triangles)
        {
            A0 = 0;
            loopc2fac:	; 800C2FAC
                [walkmesh_triangles_data + A0 * 28 + 0] = h(hu[walkmesh_triangles_data + A0 * 28 + 0] & ff7f);
                A0 = A0 + 1;
                V0 = A0 < number_of_triangles;
            800C2FC4	bne    v0, zero, loopc2fac [$800c2fac]
        }

        A0 = entity_struct;
        A1 = &current_triangle_pointer;
        A2 = S2; // end position
        A3 = 0;
        funcc2920; // 1 - can move here, 0 - can't

        if (V0 != 0)
        {
            T6 = h[SP + 70];
            if (V0 < 6)
            {
                [S2 + 0] = h(hu[SP + 38]);
                [S2 + 2] = h(hu[SP + 3a]);
                [S2 + 4] = h(h[SP + 3c]);

                A2 = 0;
                A3 = 00010ccc;

                T0 = (((h[SP + 3c] - h[S7 + 4]) << 10) | hu[SP + c4]) >> 10;
                T2 = (((h[SP + 3c] - h[S7 + 4]) << 10) | hu[SP + c4]) >> 8;

                T1 = (((h[S2 + 0] - h[S7 + 0]) << 10) | hu[SP + c0]) >> 10;
                T3 = (((h[S2 + 0] - h[S7 + 0]) << 10) | hu[SP + c0]) >> 8;

                loopc307c:	; 800C307C
                    A1 = T3 * (A3 >> 8);
                    A0 = T2 * (A3 >> 8);

                    if (((A1 >> 10) == T1) && ((A0 >> 10) == T0))
                    {
                        break;
                    }

                    A3 = A3 + ccc;
                    A2 = A2 + 1;
                    V0 = A2 < 32;
                800C30B0	bne    v0, zero, loopc307c [$800c307c]


                Lc30b8:	; 800C30B8
                [S2 + 0] = h(hu[S7 + 0] + (A1 >> 10));
                [S2 + 4] = h(hu[S7 + 4] + (A0 >> 10));
                [A6] = w(A1 & ffff);
                [A7] = w(A0 & ffff);
                V1 = w[entity_struct + 24];
                [V1 + 14] = w(h[S2 + 0]);
                [V1 + 18] = w(h[S2 + 2]);
                [V1 + 1c] = w(h[S2 + 4]);

                [entity_struct + 6] = h(S5);
                V0 = w[S4 + 10] + S6;
                [SP + 64] = w(V0);
                [entity_struct + 4] = h(hu[V0 + 4]);
                [SP + 10] = w(h[SP + 68]);
                [SP + 14] = w(h[SP + 70] + 1);
                [SP + 18] = w(w[SP + c0]);
                [SP + 1c] = w(w[SP + c4]);

                A0 = entity_struct;
                A1 = SP + 64;
                A2 = S7;
                A3 = S2;
                funcc2af0;

                if (V0 == 0)
                {
                    [address_of_current_triangle_pointer] = w(current_triangle_pointer);
                    return 0;
                }
            }

            [entity_struct + 6] = h(S5);
            V1 = w[S4 + 10] + S6;
            [SP + 64] = w(V1);
            [entity_struct + 4] = h(hu[V1 + 4]);
            [address_of_current_triangle_pointer] = w(V1);
            return 1;
        }
    }
    else // if we still in this triangle
    {
        FP = 1;
    }

800C31B0	beq    fp, zero, Lc2bb4 [$800c2bb4]

[address_of_current_triangle_pointer] = w(current_triangle_pointer);
return 0;
////////////////////////////////



////////////////////////////////
// funcc4b30
// return 1 if in triangle, 0 otherwise

walkmesh_header             = A0;
current_triangle_group_data = A1;
current_triangle_pointer    = A2;
final_position              = A3;

walkmesh_vertexes_data      = w[800c9dfc];

A3 = 0;
T9 = 2;

walk_material_id = h[current_triangle_pointer + 6];

if (walk_material_id >= 0)
{
    A0 = w[800c9e04] + walk_material_id * 10;

    if (w[A0 + 4] + 50f4 <= a1e8)
    {
        V0 = w[A0 + 0];
        V1 = w[A0 + 8];

        if (V0 < 0)
        {
            V0 = -V0;
        }

        if (V1 < 0)
        {
            V1 = -V1;
        }

        if (V1 < V0)
        {
            A3 = 1;
            T9 = 2;
        }
        else
        {
            A3 = 0;
            T9 = 1;
        }
    }
}



[SP + 18 + A3 * 2] = h(hu[walkmesh_header + 8 + A3 * 2] + hu[current_triangle_group_data + a + A3 * 2]);
[SP + 18 + T9 * 2] = h(hu[walkmesh_header + 8 + T9 * 2] + hu[current_triangle_group_data + a + T9 * 2]);

x_same = 0;
z_same = 0;

T2 = 0;
loopc4c50:	; 800C4C50
    V1 = h[current_triangle_pointer + c + T2 * 2];

    [SP + 20 + T2 * 6 + A3 * 2] = h(hu[SP + 18 + A3 * 2] + hu[walkmesh_vertexes_data + V1 * 6 + A3 * 2]);
    [SP + 20 + T2 * 6 + T9 * 2] = h(hu[SP + 18 + T9 * 2] + hu[walkmesh_vertexes_data + V1 * 6 + T9 * 2]);

    if (h[final_position + A3 * 2] == h[SP + 20 + T2 * 6 + A3 * 2])
    {
        x_same = x_same + 1;

        if (h[final_position + T9 * 2] >= h[SP + 20 + T2 * 6 + T9 * 2])
        {
            x_same = -x_same;
        }
    }

    if (h[final_position + T9 * 2] == h[SP + 20 + T2 * 6 + T9 * 2])
    {
        z_same = z_same + 1;

        if (h[final_position + A3 * 2] >= h[SP + 20 + T2 * 6 + A3 * 2])
        {
            z_same = -z_same;
        }
    }

    T2 = T2 + 1;
    V0 = T2 < 3;
800C4D70	bne    v0, zero, loopc4c50 [$800c4c50]



if ((x_same == -2) || (z_same == -2))
{
    return 1;
}




[SP + 10] = w(SP + 2c);
T5 = A3 * 2;

[SP + 0] = b(h[final_position + T9 * 2] >= h[SP + 2c + T9 * 2]);

S0 = 0;

T2 = 0;
loopc4de4:	; 800C4DE4
    A3 = SP + 20 + T2 * 6;
    T1 = A3 + T9 * 2;
    [SP + 14] = w(SP + 20 + T2 * 6);

    [SP + 1] = b(h[final_position + T9 * 2] >= h[T1]);
    if (b[SP + 0] != b[SP + 1])
    {
        A3 = A3 + T5;
        A2 = w[SP + 10];


        [SP + 8] = w((h[T1] - h[final_position + T9 * 2]) * (h[A2 + T5] - h[A3]));

        A2 = A2 + T9 * 2;

        [SP + c] = w((h[A3] - h[final_position + T5]) * (h[A2] - h[T1]));

        if (w[SP + 8] == w[SP + c])
        {
            return 1;
        }

        if ((w[SP + c] < w[SP + 8]) == b[SP + 1])
        {
            S0 = !S0;
        }
    }

    [SP + 10] = w(w[SP + 14]);
    [SP + 0] = b(bu[SP + 1]);

    T2 = T2 + 1;
    V0 = T2 < 3;
800C4EA8	bne    v0, zero, loopc4de4 [$800c4de4]



return S0;
////////////////////////////////



////////////////////////////////
// funcc519c
// A0 = walkmesh_header;
// A1 = walkmesh_groups_data + h[current_triangle_pointer + 4] * 20;
// A2 = current_triangle_pointer;
// A3 = S2; // final position pointer
// A4 = S7; // start position pointer
// A5 = SP + 20; // start position pointer
// A6 = SP + 60;
// A7 = h[SP + 60];

current_triangle_pointer = A2;

S5 = A4;
S1 = A5;
S6 = A6;
T0 = A0;
S7 = A3;
S4 = 0;
S3 = 2;
S2 = A7;
T1 = 1;
[SP + 68] = h(S2);

walk_material_id = h[current_triangle_pointer + 6];

if (walk_material_id >= 0)
{
    A0 = w[800c9e04] + walk_material_id * 10;

    if (w[A0 + 4] + 50f4 <= a1e8)
    {
        V0 = w[A0 + 0];
        V1 = w[A0 + 8];

        if (V0 < 0)
        {
            V0 = -V0;
        }

        if (V1 < 0)
        {
            V1 = -V1;
        }

        if (V1 < V0)
        {
            S4 = 1;
            S3 = 2;
            T1 = 0;
        }
        else
        {
            S4 = 0;
            S3 = 1;
            T1 = 2;
        }
    }
}

[SP + 18] = h(hu[T0 + 8] + hu[A1 + a]);
[SP + 1a] = h(hu[T0 + a] + hu[A1 + c]);
[SP + 1c] = h(hu[T0 + c] + hu[A1 + e]);


T2 = SP + 30;
A3 = T0 + hu[T0 + 3a];

T7 = 0;
loopc52b4:	; 800C52B4
    A0 = A2 + T7 * 2; // vertex data
    V1 = h[A0 + c];
    [T2 + T7 * 6 + 0] = h(hu[SP + 18] + hu[A3 + V1 * 6 + 0]);
    [T2 + T7 * 6 + 2] = h(hu[SP + 1a] + hu[A3 + V1 * 6 + 2]);
    [T2 + T7 * 6 + 4] = h(hu[SP + 1c] + hu[A3 + V1 * 6 + 4]);

    T7 = T7 + 1;
    V1 = T7 < 3;
800C5354	bne    v1, zero, loopc52b4 [$800c52b4]

T8 = 0;
T7 = 0;
T5 = S3 * 2;
T6 = S4 * 2;
S2 = T6 + S5;
S0 = SP + 48;
T9 = T1 * 2;
[SP + 20] = w(SP + 3c);
[SP + 70] = w(S2);

Lc5388:	; 800C5388
    V0 = (T7 << 10) >> 10;
    V1 = V0 * 6;
    S2 = hu[SP + 68];
    T4 = SP + 30 + V1;
    V1 = (S2 << 10) >> 10;
    [SP + 24] = w(T4);
    if (V0 != V1)
    {
        A0 = T5 + S7;
        A1 = T5 + S5;
        V0 = h[T4 + T6];
        A3 = h[A0];
        A0 = h[A1];
        V1 = w[SP + 20] + T6;
        T0 = h[V1];
        A3 = A3 - A0;
        T2 = (V0 - T0) * A3;
        S2 = w[SP + 70];
        A2 = w[SP + 20] + T5;
        A1 = h[A2];
        V1 = h[T6 + S7] - h[S2];
        T2 = T2 - (h[T4 + T5] - A1) * V1;
        T3 = (A1 - A0) * V1 - (T0 - h[S2]) * A3;
        V1 = T3;
        if (T3 < 0)
        {
            V1 = 0 - V1;
        }

        800C544C	bltz   t2, Lc5464 [$800c5464]
        800C5450	slt    v0, t2, v1
        800C5454	beq    v0, zero, Lc5474 [$800c5474]

        800C545C	j      Lc5810 [$800c5810]


        Lc5464:	; 800C5464
        800C5464	subu   v0, zero, t2
        800C5468	slt    v0, v0, v1
        800C546C	bne    v0, zero, Lc5810 [$800c580c]


        Lc5474:	; 800C5474
        V1 = w[SP + 20] + T5;
        A2 = w[SP + 24] + T6;
        A0 = w[SP + 20] + T6;
        A2 = (h[V1] - h[T5 + S5]) * (h[A2] - h[A0]);
        S2 = w[SP + 70];
        A1 = w[SP + 24] + T5;
        A2 = A2 - ((h[A0] - h[S2]) * (h[A1] - h[V1]));
        V1 = A2;
        if (A2 < 0)
        {
            V1 = 0 - V1;
        }

        800C54DC	bltz   t2, Lc54f4 [$800c54f4]
        800C54E0	slt    v0, t2, v1
        800C54E4	beq    v0, zero, Lc5504 [$800c5504]

        800C54EC	j      Lc5810 [$800c5810]


        Lc54f4:	; 800C54F4
        800C54F4	subu   v0, zero, t2
        800C54F8	slt    v0, v0, v1
        800C54FC	bne    v0, zero, Lc5810 [$800c580c]


        Lc5504:	; 800C5504
        800C5504	bltz   t3, Lc551c [$800c551c]
        800C5508	nop
        800C550C	bgez   t2, Lc5524 [$800c5524]
        800C5510	nop
        800C5514	bgtz   t3, Lc5810 [$800c580c]


        Lc551c:	; 800C551C
        800C551C	bgez   t2, Lc5810 [$800c580c]


        Lc5524:	; 800C5524
        800C5524	bltz   a2, Lc553c [$800c553c]
        800C5528	nop
        800C552C	bgez   t2, Lc5544 [$800c5544]
        800C5530	nop
        800C5534	bgtz   a2, Lc5810 [$800c580c]


        Lc553c:	; 800C553C
        800C553C	bgez   t2, Lc5810 [$800c580c]


        Lc5544:	; 800C5544
        800C5544	beq    t2, zero, Lc57f4 [$800c57f4]

        if (T3 >= 00080000)
        {
            loopc5558:	; 800C5558
                T3 = T3 >> 1;
                T2 = T2 >> 1;
                V0 = T3 >= 00080000;
            800C5560	bne    v0, zero, loopc5558 [$800c5558]
        }

        A1 = T6 + w[SP + 20];
        V0 = T6 + w[SP + 24];
        V0 = h[V0];
        V1 = h[A1];
        V0 = V0 - V1;
        V1 = T3 * V0;
        A2 = V1 / T2;
        V0 = (T8 << 10) >> 10;
        A0 = V0 * 6;
        V1 = T6 + A0;
        V0 = hu[A1];
        V1 = S0 + V1;
        V0 = V0 + A2;
        [V1] = h(V0);
        A1 = w[SP + 20];
        V0 = w[SP + 24];
        A1 = A1 + T5;
        V0 = V0 + T5;
        V0 = h[V0];
        V1 = h[A1];
        V0 = V0 - V1;
        V1 = T3 * V0;
        V1 = V1 / T2;
        A0 = T5 + A0;
        V0 = hu[A1];
        A0 = S0 + A0;
        V0 = V0 + V1;
        [A0] = h(V0);
        A2 = w[SP + 24];
        A3 = w[SP + 20];
        V0 = A2 + T6;
        V1 = A3 + T6;
        A1 = h[V0];
        V0 = h[V1];
        A0 = A1 - V0;

        if (A0 < 0)
        {
            A0 = V0 - A1;
        }

        800C5688	addu   v0, a2, t5
        800C568C	addu   v1, a3, t5
        800C5690	lh     a1, $0000(v0)
        800C5694	lh     v1, $0000(v1)
        800C5698	nop
        800C569C	subu   v0, a1, v1
        800C56A0	bltz   v0, Lc56b8 [$800c56b8]
        800C56A4	slt    v0, v0, a0
        800C56A8	bne    v0, zero, Lc56c8 [$800c56c8]
        800C56AC	sll    v0, t8, $10
        800C56B0	j      Lc575c [$800c575c]
        800C56B4	sra    v0, v0, $10

        Lc56b8:	; 800C56B8
        800C56B8	subu   v0, v1, a1
        800C56BC	slt    v0, v0, a0
        800C56C0	beq    v0, zero, Lc5758 [$800c5758]
        800C56C4	sll    v0, t8, $10

        Lc56c8:	; 800C56C8
        800C56C8	sra    v0, v0, $10
        800C56CC	sll    a1, v0, $01
        800C56D0	addu   a1, a1, v0
        800C56D4	sll    a1, a1, $01
        800C56D8	addu   v0, t6, a1
        800C56DC	addu   v0, s0, v0
        800C56E0	lw     v1, $0024(sp)
        800C56E4	lw     a2, $0020(sp)
        800C56E8	addu   t0, v1, t9
        800C56EC	addu   v1, v1, t6
        800C56F0	addu   a0, a2, t9
        800C56F4	lh     a3, $0000(v1)
        800C56F8	lh     v1, $0000(v0)
        800C56FC	lh     v0, $0000(a0)
        800C5700	lh     a0, $0000(t0)
        800C5704	subu   v1, a3, v1
        800C5708	subu   v0, v0, a0
        800C570C	mult   v1, v0
        800C5710	addu   a2, a2, t6
        800C5714	lh     v1, $0000(a2)
        800C5718	mflo   t1
        800C571C	subu   v1, v1, a3
        800C5720	nop
        800C5724	div    t1, v1
        800C574C	mflo   v1
        800C5750	j      Lc57e4 [$800c57e4]
        800C5754	addu   a1, t9, a1

        Lc5758:	; 800C5758
        800C5758	sra    v0, v0, $10

        Lc575c:	; 800C575C
        800C575C	sll    a1, v0, $01
        800C5760	addu   a1, a1, v0
        800C5764	sll    a1, a1, $01
        800C5768	addu   v0, t5, a1
        800C576C	addu   v0, s0, v0

        Lc5770:	; 800C5770
        V1 = w[SP + 24];
        A2 = w[SP + 20];
        T0 = V1 + T9;
        V1 = V1 + T5;
        A0 = A2 + T9;
        A3 = h[V1];
        V1 = h[V0];
        V0 = h[A0];
        A0 = w[T0];
        V1 = A3 - V1;
        V0 = V0 - A0;
        T1 = V1 * V0;
        A2 = A2 + T5;
        V1 = h[A2];
        V1 = V1 - A3;
        V1 = T1 / V1;
        A1 = T9 + A1;

        Lc57e4:	; 800C57E4
        A1 = S0 + A1;
        [A1] = h(hu[T0] - V1);

        Lc57f4:	; 800C57F4
        800C57F4	sll    v0, t8, $10
        800C57F8	sra    v0, v0, $0f
        800C57FC	addu   v0, sp, v0
        800C5800	sh     t7, $0060(v0)
        800C5804	addiu  t8, t8, $0001
    }
    Lc5810:	; 800C5810
    V0 = T7 + 1;
    T7 = V0;
    V0 = (V0 << 10) >> 10;
    [SP + 20] = w(w[SP + 24]);

    V0 = V0 < 3;
800C5820	bne    v0, zero, Lc5388 [$800c5388]

A0 = (T8 << 10) >> 10;

if (A0 == 1)
{
    [S6] = h(hu[SP + 60]);
    [S1 + 0] = h(hu[SP + 48]);
    [S1 + 2] = h(hu[SP + 4a]);
    [S1 + 4] = h(hu[SP + 4c]);
    return 1;
}

if (A0 < 2)
{
    [S6] = h(-1);
    return 0;
}

if (A0 == 2)
{
    V1 = h[SP + 60] + h[SP + 62];
    if (V1 == 1)
    {
        [SP + 20] = w(SP + 36);
        [SP + 24] = w(SP + 3c);
        [SP + 28] = w(SP + 30);
    }
    else if (V1 == 2)
    {
        [SP + 20] = w(SP + 36);
        [SP + 24] = w(SP + 30);
        [SP + 28] = w(SP + 3c);
        800C58C8	j      Lc58e8 [$800c58e0]
    }
    else if (V1 == 3)
    {
        [SP + 20] = w(SP + 3c);
        [SP + 24] = w(SP + 30);
        [SP + 28] = w(SP + 36);
    }

    A0 = w[SP + 20];
    A1 = S7;
    A2 = w[SP + 28];
    A3 = w[SP + 24];
    A4 = S4;
    A5 = S3;
    800C58F8	jal    funcc1e14 [$800c1e14]

    if (V0 == 0)
    {
        [S6] = h(hu[SP + 62]);
        [S1 + 0] = h(hu[SP + 4e]);
        [S1 + 2] = h(hu[SP + 50]);
        [S1 + 4] = h(hu[SP + 52]);
        return 1;
    }

    [S6] = h(hu[SP + 60]);
    [S1 + 0] = h(hu[SP + 48]);
    [S1 + 2] = h(hu[SP + 4a]);
    [S1 + 4] = h(hu[SP + 4c]);
    return 1;
}
else if (A0 == 3)
{
    A3 = 0;
    A2 = 7fffffff;

    T7 = 0;
    loopc5980:	; 800C5980
        V1 = SP + 48 + T7 * 6;
        V1 = h[V1 + 0] * h[V1 + 0] + h[V1 + 2] * h[V1 + 2] + h[V1 + 4] * h[V1 + 4];

        if (V1 < A2)
        {
            A3 = T7;
            A2 = V1;
        }

        T7 = T7 + 1;
        V0 = T7 < 3;
    800C59F0	bne    v0, zero, loopc5980 [$800c5980]

    V0 = A3 & ff;
    V1 = A3 & ff;
    [S6] = h(V0);

    [S1 + 0] = h(hu[SP + 48 + V1 * 6 + 0]);
    [S1 + 2] = h(hu[SP + 48 + V1 * 6 + 2]);
    [S1 + 4] = h(hu[SP + 48 + V1 * 6 + 4]);

    return 1;
}
else
{
    [S6] = h(-1);
    return 0;
}
////////////////////////////////



////////////////////////////////
// funcc2920
//        A0 = entity_struct;
//        A1 = &current_triangle_pointer;
//        A2 = S2; // end position
//        A3 = 0;
// 1 - can move here, 0 - can't
S2 = A0;
S6 = A1;
S4 = A2;
S5 = A3;

if (S5 >= 9)
{
    return 0;
}

S1 = 800c9df0;

A0 = w[S1 + 8]; // walkmesh_header
A1 = w[S1 + 1c] + h[A2 + 4] * 20; // current triangle group data
A2 = w[S6 + 0]; // current_triangle_pointer
A3 = S4; // final position
[SP + 10] = w(A2);
funcc4b30; // check in triangle

if (V0 != 0)
{
    return 1;
}

S0 = 0;
S3 = S1;

loopc29d8:	; 800C29D8
    A0 = S2;
    A1 = w[SP + 10];
    A2 = S0;
    field_get_next_walkmesh_triangle_address; // return address of next triangle or 0 if we cant pass this side

    [SP + 14] = w(V0);

    if (V0 != 0)
    {
        A0 = w[S3 + 8];
        A1 = w[S3 + 1c] + h[A2 + 4] * 20;
        A2 = V0;
        A3 = S4;
        funcc4b30; // check in triangle

        if (V0 != 0)
        {
            V0 = w[SP + 10] + S0 * 2;
            V1 = h[V0 + 18];
            [S2 + 6] = h(V1);

            if (V1 >= 0)
            {
                V1 = w[S3 + 10] + V1 * 28;

                [SP + 14] = w(V1);
                [S2 + 4] = h(hu[V1 + 4]);
                [S6 + 0] = w(w[SP + 14]);
                return 1;
            }
        }
    }

    S0 = S0 + 1;
    V0 = S0 < 3;
800C2A50	bne    v0, zero, loopc29d8 [$800c29d8]

S0 = 0;

loopc2a5c:	; 800C2A5C
    A0 = S2;
    A1 = w[SP + 10];
    A2 = S0;
    field_get_next_walkmesh_triangle_address; // return address of next triangle or 0 if we cant pass this side

    [SP + 14] = w(V0);

    if (V0 != 0)
    {
        A0 = hu[V0];
        if ((A0 & 80) == 0)
        {
            [V0] = h(A0 | 80);

            A0 = S2;
            A1 = SP + 14;
            A2 = S4;
            A3 = S5 + 1;
            funcc2920; // 1 - can move here, 0 - can't

            if (V0 == 1)
            {
                [S6 + 0] = w(w[SP + 14]);
                return 1;
            }
        }
    }

    S0 = S0 + 1;
    V0 = S0 < 3;
800C2ABC	bne    v0, zero, loopc2a5c [$800c2a5c]

return 0;
////////////////////////////////



////////////////////////////////
// funcc2390
//    A0 - some data pointer
//    A1 = SP + 40; // move vector
//    A2 = SP + 20; // start vector
//    A3 = SP + 28; // output?

0000 0000 1E00 move up
0000 0000 E2FF move down
E2FF 0000 0000 move left

ECFF EAFF 0000

// expand move vector to s32
moveX = h[A1 + 0] << 10;
moveZ = h[A1 + 4] << 10;

[A3 + 0] = w(-h[A1 + 4]);
[A3 + 4] = w(0);
[A3 + 8] = w(h[A1 + 0]);

if (w[A0 + 4] >= 0)
{
    finalX = (w[A0 + 4] * moveX) >> 10;
    finalY = -(((w[A0 + 8] * moveZ) >> 10) + ((w[A0 + 0] * moveX) >> 10));
    finalZ = (w[A0 + 4] * moveZ) >> 10;
}
else
{
    finalX = -((w[A0 + 4] * moveX) >> 10);
    finalY = ((w[A0 + 0] * moveX) >> 10) + ((w[A0 + 8] * moveZ) >> 10);
    finalZ = -((w[A0 + 4] * moveZ) >> 10);
}

// return move vector to s16
finalX = (finalX + 8000) >> 10;
finalY = (finalY + 8000) >> 10;
finalZ = (finalZ + 8000) >> 10;

[A1 + 0] = h(finalX);
[A1 + 2] = h(finalY);
[A1 + 4] = h(finalZ);

return 1;
////////////////////////////////