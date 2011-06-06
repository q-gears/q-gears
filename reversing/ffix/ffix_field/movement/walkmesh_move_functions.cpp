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

T7 = 0;
T2 = SP + 30;
A3 = T0 + hu[T0 + 3a];


loopc52b4:	; 800C52B4
    800C52B4	sll    a1, t7, $10
    800C52B8	sra    a1, a1, $10
    800C52BC	sll    a0, a1, $01
    800C52C0	addu   a1, a0, a1
    800C52C4	addu   a0, a2, a0
    800C52C8	lh     v1, $000c(a0)
    800C52CC	sll    a1, a1, $01
    800C52D0	sll    v0, v1, $01
    800C52D4	addu   v0, v0, v1
    800C52D8	sll    v0, v0, $01
    800C52DC	addu   v0, v0, a3
    800C52E0	lhu    v1, $0018(sp)
    800C52E4	lhu    v0, $0000(v0)
    800C52E8	addu   a1, t2, a1
    800C52EC	addu   v1, v1, v0
    800C52F0	sh     v1, $0000(a1)
    800C52F4	lh     v1, $000c(a0)
    800C52F8	nop
    800C52FC	sll    v0, v1, $01
    800C5300	addu   v0, v0, v1
    800C5304	sll    v0, v0, $01
    800C5308	addu   v0, v0, a3
    800C530C	lhu    v1, $001a(sp)
    800C5310	lhu    v0, $0002(v0)
    800C5314	nop
    800C5318	addu   v1, v1, v0
    800C531C	sh     v1, $0002(a1)
    800C5320	lh     v1, $000c(a0)
    800C5324	lhu    a0, $001c(sp)
    800C5328	sll    v0, v1, $01
    800C532C	addu   v0, v0, v1
    800C5330	sll    v0, v0, $01
    800C5334	addu   v0, v0, a3
    800C5338	addiu  v1, t7, $0001
    800C533C	addu   t7, v1, zero
    800C5340	sll    v1, v1, $10
    800C5344	sra    v1, v1, $10
    800C5348	lhu    v0, $0004(v0)
    800C5350	addu   a0, a0, v0
    800C5358	sh     a0, $0004(a1)

    V1 = V1 < 3;
800C5354	bne    v1, zero, loopc52b4 [$800c52b4]

800C535C	addiu  v0, sp, $003c
800C5360	addu   t8, zero, zero
800C5364	addu   t7, t8, zero
800C5368	addiu  fp, sp, $0030
800C536C	sll    t5, s3, $01
800C5370	sll    t6, s4, $01
800C5374	addu   s2, t6, s5
800C5378	addiu  s0, sp, $0048
800C537C	sll    t9, t1, $01
800C5380	sw     v0, $0020(sp)
800C5384	sw     s2, $0070(sp)

Lc5388:	; 800C5388
800C5388	sll    v0, t7, $10
800C538C	sra    v0, v0, $10
800C5390	sll    v1, v0, $01
800C5394	addu   v1, v1, v0
800C5398	sll    v1, v1, $01
800C539C	lhu    s2, $0068(sp)
800C53A0	addu   t4, fp, v1
800C53A4	sll    v1, s2, $10
800C53A8	sra    v1, v1, $10
800C53AC	beq    v0, v1, Lc5808 [$800c5808]
800C53B0	sw     t4, $0024(sp)
800C53B4	addu   v0, t4, t6
800C53B8	addu   a0, t5, s7
800C53BC	addu   a1, t5, s5
800C53C0	lw     a2, $0020(sp)
800C53C4	lh     v0, $0000(v0)
800C53C8	lh     a3, $0000(a0)
800C53CC	lh     a0, $0000(a1)
800C53D0	addu   v1, a2, t6
800C53D4	lh     t0, $0000(v1)
800C53D8	subu   a3, a3, a0
800C53DC	subu   v0, v0, t0
800C53E0	mult   v0, a3
800C53E4	lw     s2, $0070(sp)
800C53E8	addu   a2, a2, t5
800C53EC	lh     t1, $0000(s2)
800C53F0	lh     a1, $0000(a2)
800C53F4	addu   v0, t6, s7
800C53F8	lh     v1, $0000(v0)
800C53FC	mflo   t2
800C5400	subu   a0, a1, a0
800C5404	subu   v1, v1, t1
800C5408	mult   a0, v1
800C540C	addu   v0, t4, t5
800C5410	lh     v0, $0000(v0)
800C5414	mflo   t3
800C5418	subu   v0, v0, a1
800C541C	nop
800C5420	mult   v0, v1
800C5424	mflo   v0
800C5428	subu   t0, t0, t1
800C542C	nop
800C5430	mult   t0, a3
800C5434	subu   t2, t2, v0
800C5438	mflo   v1
800C543C	subu   t3, t3, v1
800C5440	bgez   t3, Lc544c [$800c544c]
800C5444	addu   v1, t3, zero
800C5448	subu   v1, zero, v1

Lc544c:	; 800C544C
800C544C	bltz   t2, Lc5464 [$800c5464]
800C5450	slt    v0, t2, v1
800C5454	beq    v0, zero, Lc5474 [$800c5474]
800C5458	addiu  v0, t7, $0001
800C545C	j      Lc5810 [$800c5810]
800C5460	addu   t7, v0, zero

Lc5464:	; 800C5464
800C5464	subu   v0, zero, t2
800C5468	slt    v0, v0, v1
800C546C	bne    v0, zero, Lc580c [$800c580c]
800C5470	addiu  v0, t7, $0001

Lc5474:	; 800C5474
800C5474	addu   v0, t5, s5
800C5478	lw     a0, $0020(sp)
800C547C	lw     a1, $0024(sp)
800C5480	addu   v1, a0, t5
800C5484	addu   a2, a1, t6
800C5488	addu   a0, a0, t6
800C548C	lh     a3, $0000(v1)
800C5490	lh     v1, $0000(v0)
800C5494	lh     v0, $0000(a2)
800C5498	lh     a0, $0000(a0)
800C549C	subu   v1, a3, v1
800C54A0	subu   v0, v0, a0
800C54A4	mult   v1, v0
800C54A8	lw     s2, $0070(sp)
800C54AC	addu   a1, a1, t5
800C54B0	lh     v1, $0000(s2)
800C54B4	lh     v0, $0000(a1)
800C54B8	mflo   a2
800C54BC	subu   a0, a0, v1
800C54C0	subu   v0, v0, a3
800C54C4	mult   a0, v0
800C54C8	mflo   v1
800C54CC	subu   a2, a2, v1
800C54D0	bgez   a2, Lc54dc [$800c54dc]
800C54D4	addu   v1, a2, zero
800C54D8	subu   v1, zero, v1

Lc54dc:	; 800C54DC
800C54DC	bltz   t2, Lc54f4 [$800c54f4]
800C54E0	slt    v0, t2, v1
800C54E4	beq    v0, zero, Lc5504 [$800c5504]
800C54E8	addiu  v0, t7, $0001
800C54EC	j      Lc5810 [$800c5810]
800C54F0	addu   t7, v0, zero

Lc54f4:	; 800C54F4
800C54F4	subu   v0, zero, t2
800C54F8	slt    v0, v0, v1
800C54FC	bne    v0, zero, Lc580c [$800c580c]
800C5500	addiu  v0, t7, $0001

Lc5504:	; 800C5504
800C5504	bltz   t3, Lc551c [$800c551c]
800C5508	nop
800C550C	bgez   t2, Lc5524 [$800c5524]
800C5510	nop
800C5514	bgtz   t3, Lc580c [$800c580c]
800C5518	addiu  v0, t7, $0001

Lc551c:	; 800C551C
800C551C	bgez   t2, Lc580c [$800c580c]
800C5520	addiu  v0, t7, $0001

Lc5524:	; 800C5524
800C5524	bltz   a2, Lc553c [$800c553c]
800C5528	nop
800C552C	bgez   t2, Lc5544 [$800c5544]

funcc5530:	; 800C5530
800C5530	nop
800C5534	bgtz   a2, Lc580c [$800c580c]
800C5538	addiu  v0, t7, $0001

Lc553c:	; 800C553C
800C553C	bgez   t2, Lc580c [$800c580c]
800C5540	addiu  v0, t7, $0001

Lc5544:	; 800C5544
800C5544	beq    t2, zero, Lc57f4 [$800c57f4]
800C5548	lui    v0, $0008
800C554C	slt    v0, v0, t3
800C5550	beq    v0, zero, Lc5568 [$800c5568]
800C5554	lui    v1, $0008

loopc5558:	; 800C5558
800C5558	sra    t3, t3, $01
800C555C	slt    v0, v1, t3
800C5560	bne    v0, zero, loopc5558 [$800c5558]
800C5564	sra    t2, t2, $01

Lc5568:	; 800C5568
800C5568	lw     a1, $0020(sp)
800C556C	lw     v0, $0024(sp)
800C5570	addu   a1, a1, t6
800C5574	addu   v0, v0, t6

Lc5578:	; 800C5578
800C5578	lh     v0, $0000(v0)
800C557C	lh     v1, $0000(a1)
800C5580	nop
800C5584	subu   v0, v0, v1
800C5588	mult   t3, v0
800C558C	mflo   v1
800C5590	nop
800C5594	nop
800C5598	div    v1, t2
800C55C0	mflo   a2
800C55C4	sll    v0, t8, $10
800C55C8	sra    v0, v0, $10
800C55CC	sll    a0, v0, $01
800C55D0	addu   a0, a0, v0
800C55D4	sll    a0, a0, $01
800C55D8	addu   v1, t6, a0
800C55DC	lhu    v0, $0000(a1)
800C55E0	addu   v1, s0, v1
800C55E4	addu   v0, v0, a2
800C55E8	sh     v0, $0000(v1)
800C55EC	lw     a1, $0020(sp)
800C55F0	lw     v0, $0024(sp)
800C55F4	addu   a1, a1, t5
800C55F8	addu   v0, v0, t5
800C55FC	lh     v0, $0000(v0)
800C5600	lh     v1, $0000(a1)
800C5604	nop
800C5608	subu   v0, v0, v1
800C560C	mult   t3, v0
800C5610	mflo   v1
800C5614	nop
800C5618	nop
800C561C	div    v1, t2
800C5644	mflo   v1
800C5648	addu   a0, t5, a0
800C564C	lhu    v0, $0000(a1)
800C5650	addu   a0, s0, a0
800C5654	addu   v0, v0, v1
800C5658	sh     v0, $0000(a0)
800C565C	lw     a2, $0024(sp)
800C5660	lw     a3, $0020(sp)
800C5664	addu   v0, a2, t6
800C5668	addu   v1, a3, t6
800C566C	lh     a1, $0000(v0)
800C5670	lh     v0, $0000(v1)
800C5674	nop
800C5678	subu   a0, a1, v0
800C567C	bgez   a0, Lc5688 [$800c5688]
800C5680	nop
800C5684	subu   a0, v0, a1

Lc5688:	; 800C5688
800C5688	addu   v0, a2, t5
800C568C	addu   v1, a3, t5
800C5690	lh     a1, $0000(v0)
800C5694	lh     v1, $0000(v1)
800C5698	nop
800C569C	subu   v0, a1, v1
800C56A0	bltz   v0, Lc56b8 [$800c56b8]
800C56A4	slt    v0, v0, a0
800C56A8	bne    v0, zero, Lc56c8 [$800c56c8]

Lc56ac:	; 800C56AC
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
800C5770	lw     v1, $0024(sp)
800C5774	lw     a2, $0020(sp)
800C5778	addu   t0, v1, t9
800C577C	addu   v1, v1, t5
800C5780	addu   a0, a2, t9
800C5784	lh     a3, $0000(v1)
800C5788	lh     v1, $0000(v0)
800C578C	lh     v0, $0000(a0)
800C5790	lh     a0, $0000(t0)
800C5794	subu   v1, a3, v1
800C5798	subu   v0, v0, a0
800C579C	mult   v1, v0
800C57A0	addu   a2, a2, t5

funcc57a4:	; 800C57A4
800C57A4	lh     v1, $0000(a2)
800C57A8	mflo   t1
800C57AC	subu   v1, v1, a3
800C57B0	nop
800C57B4	div    t1, v1
800C57DC	mflo   v1
800C57E0	addu   a1, t9, a1

Lc57e4:	; 800C57E4
800C57E4	lhu    v0, $0000(t0)
800C57E8	addu   a1, s0, a1
800C57EC	subu   v0, v0, v1
800C57F0	sh     v0, $0000(a1)

Lc57f4:	; 800C57F4
800C57F4	sll    v0, t8, $10
800C57F8	sra    v0, v0, $0f
800C57FC	addu   v0, sp, v0
800C5800	sh     t7, $0060(v0)
800C5804	addiu  t8, t8, $0001

Lc5808:	; 800C5808
800C5808	addiu  v0, t7, $0001

Lc580c:	; 800C580C
800C580C	addu   t7, v0, zero

Lc5810:	; 800C5810
800C5810	sll    v0, v0, $10
800C5814	sra    v0, v0, $10
800C5818	lw     v1, $0024(sp)
800C581C	slti   v0, v0, $0003
800C5820	bne    v0, zero, Lc5388 [$800c5388]
800C5824	sw     v1, $0020(sp)
800C5828	sll    v0, t8, $10
800C582C	sra    a0, v0, $10
800C5830	addiu  a1, zero, $0001
800C5834	beq    a0, a1, Lc5908 [$800c5908]
800C5838	slti   v0, a0, $0002
800C583C	bne    v0, zero, Lc5a3c [$800c5a3c]
800C5840	addiu  v0, zero, $ffff (=-$1)
800C5844	addiu  v0, zero, $0002
800C5848	beq    a0, v0, Lc5860 [$800c5860]
800C584C	addiu  v0, zero, $0003
800C5850	beq    a0, v0, Lc5968 [$800c5968]
800C5854	addiu  v0, zero, $ffff (=-$1)
800C5858	j      Lc5a40 [$800c5a40]
800C585C	sh     v0, $0000(s6)

Lc5860:	; 800C5860
800C5860	lh     v1, $0060(sp)
800C5864	lh     v0, $0062(sp)
800C5868	nop
800C586C	addu   v1, v1, v0
800C5870	beq    v1, a0, Lc58bc [$800c58bc]
800C5874	addiu  v0, sp, $0036

Lc5878:	; 800C5878
800C5878	slti   v0, v1, $0003
800C587C	beq    v0, zero, Lc5894 [$800c5894]
800C5880	nop
800C5884	beq    v1, a1, Lc58a8 [$800c58a8]
800C5888	addiu  v0, sp, $0036
800C588C	j      Lc58e8 [$800c58e8]

funcc5890:	; 800C5890
800C5890	sw     s4, $0010(sp)

Lc5894:	; 800C5894
800C5894	addiu  v0, zero, $0003
800C5898	beq    v1, v0, Lc58d0 [$800c58d0]
800C589C	addiu  v0, sp, $003c
800C58A0	j      Lc58e8 [$800c58e8]
800C58A4	sw     s4, $0010(sp)

Lc58a8:	; 800C58A8
800C58A8	sw     v0, $0020(sp)
800C58AC	addiu  v0, sp, $003c
800C58B0	sw     v0, $0024(sp)
800C58B4	j      Lc58e0 [$800c58e0]
800C58B8	addiu  v0, sp, $0030

Lc58bc:	; 800C58BC
800C58BC	sw     v0, $0020(sp)
800C58C0	addiu  v0, sp, $0030
800C58C4	sw     v0, $0024(sp)
800C58C8	j      Lc58e0 [$800c58e0]

Lc58cc:	; 800C58CC
800C58CC	addiu  v0, sp, $003c

Lc58d0:	; 800C58D0
800C58D0	sw     v0, $0020(sp)
800C58D4	addiu  v0, sp, $0030
800C58D8	sw     v0, $0024(sp)
800C58DC	addiu  v0, sp, $0036

Lc58e0:	; 800C58E0
800C58E0	sw     v0, $0028(sp)

funcc58e4:	; 800C58E4
800C58E4	sw     s4, $0010(sp)

Lc58e8:	; 800C58E8
800C58E8	sw     s3, $0014(sp)
800C58EC	lw     a0, $0020(sp)
800C58F0	lw     a2, $0028(sp)
800C58F4	lw     a3, $0024(sp)
800C58F8	jal    funcc1e14 [$800c1e14]
800C58FC	addu   a1, s7, zero
800C5900	beq    v0, zero, Lc5938 [$800c5938]
800C5904	nop

Lc5908:	; 800C5908
800C5908	lhu    v0, $0060(sp)
800C590C	nop
800C5910	sh     v0, $0000(s6)
800C5914	lhu    v0, $0048(sp)
800C5918	nop
800C591C	sh     v0, $0000(s1)
800C5920	lhu    v0, $004a(sp)
800C5924	nop
800C5928	sh     v0, $0002(s1)
800C592C	lhu    v0, $004c(sp)
800C5930	j      Lc5a48 [$800c5a48]
800C5934	sh     v0, $0004(s1)

Lc5938:	; 800C5938
800C5938	lhu    v0, $0062(sp)
800C593C	nop
800C5940	sh     v0, $0000(s6)
800C5944	lhu    v0, $004e(sp)
800C5948	nop
800C594C	sh     v0, $0000(s1)
800C5950	lhu    v0, $0050(sp)
800C5954	nop
800C5958	sh     v0, $0002(s1)
800C595C	lhu    v0, $0052(sp)
800C5960	j      Lc5a48 [$800c5a48]
800C5964	sh     v0, $0004(s1)

Lc5968:	; 800C5968
800C5968	addu   a3, zero, zero
800C596C	lui    a2, $7fff
800C5970	ori    a2, a2, $ffff
800C5974	addu   t7, zero, zero
800C5978	addiu  t0, sp, $0048
800C597C	sll    v0, t7, $10

loopc5980:	; 800C5980
800C5980	sra    v0, v0, $10
800C5984	sll    v1, v0, $01
800C5988	addu   v1, v1, v0
800C598C	sll    v1, v1, $01
800C5990	addu   v1, t0, v1
800C5994	lh     v0, $0000(v1)
800C5998	nop
800C599C	mult   v0, v0
800C59A0	mflo   a1
800C59A4	lh     v0, $0002(v1)
800C59A8	nop
800C59AC	mult   v0, v0
800C59B0	mflo   a0
800C59B4	lh     v0, $0004(v1)
800C59B8	nop
800C59BC	mult   v0, v0
800C59C0	addu   v0, a1, a0
800C59C4	mflo   v1
800C59C8	addu   v1, v0, v1
800C59CC	slt    v0, v1, a2
800C59D0	beq    v0, zero, Lc59e0 [$800c59e0]
800C59D4	addiu  v0, t7, $0001
800C59D8	addu   a3, t7, zero
800C59DC	addu   a2, v1, zero

Lc59e0:	; 800C59E0
800C59E0	addu   t7, v0, zero
800C59E4	sll    v0, v0, $10
800C59E8	sra    v0, v0, $10
800C59EC	slti   v0, v0, $0003
800C59F0	bne    v0, zero, loopc5980 [$800c5980]
800C59F4	sll    v0, t7, $10
800C59F8	andi   v0, a3, $00ff
800C59FC	andi   v1, a3, $00ff
800C5A00	sh     v0, $0000(s6)
800C5A04	sll    v0, v1, $01
800C5A08	addu   v0, v0, v1
800C5A0C	sll    v0, v0, $01
800C5A10	addiu  v1, sp, $0048
800C5A14	addu   v1, v1, v0
800C5A18	lhu    v0, $0000(v1)
800C5A1C	nop
800C5A20	sh     v0, $0000(s1)
800C5A24	lhu    v0, $0002(v1)
800C5A28	nop
800C5A2C	sh     v0, $0002(s1)
800C5A30	lhu    v0, $0004(v1)
800C5A34	j      Lc5a48 [$800c5a48]
800C5A38	sh     v0, $0004(s1)

Lc5a3c:	; 800C5A3C
800C5A3C	sh     v0, $0000(s6)

Lc5a40:	; 800C5A40
800C5A40	j      Lc5a4c [$800c5a4c]
800C5A44	addu   v0, zero, zero

Lc5a48:	; 800C5A48
800C5A48	addiu  v0, zero, $0001

Lc5a4c:	; 800C5A4C
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