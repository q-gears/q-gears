////////////////////////////////
// funcc44f4
T0 = A0;

A0 = 800c9df0;

if (V1 == 0)
{
    return 8000;
}

if (T0 >= hu[800c9df2])
{
    return 4000;
}

A0 = w[800c9df4] + T0 * 28;

if ((hu[A0 + 0] & 0001) == 0)
{
    return 0;
}

if (h[A0 + 4] == -1 || h[A0 + 6] == -1)
{
    V0 = w[A0 + 24];

    A0 = T0; // unit id?
    A1 = h[V0 + 14]; // place here X
    A2 = h[V0 + 18]; // place here Y
    A3 = h[V0 + 1c]; // place here Z
    funcc3ec0;

    V0 = 0 < V0;
    V0 = V0 << 1;
    return V0;
}
else
{
    funcc3608;

    return V0;
}
////////////////////////////////



////////////////////////////////
// funcc3ec0
// place character on walkmesh
height = 7fff;

FP = 0;

[SP + 48] = h(-1);
[SP + 4a] = h(-1);

// our position
[SP + 10] = h(A1);
[SP + 12] = h(A2);
[SP + 14] = h(A3);
// our position
[SP + 30] = h(A1);
[SP + 38] = h(A2);
[SP + 40] = h(A3);

S3 = w[800c9df4] + A0 * 28;

walkmesh                        = w[800c9df8]; // pointer to walkmesh file after 4 bytes header.
walkmesh_vertex_data            = w[800c9dfc];
walkmesh_triangle_data          = w[800c9e00];
walkmesh_triangle_group_data    = w[800c9e0c];

number_of_triangles = hu[walkmesh + 24];

if (number_of_triangles != 0)
{
    triangle_id = 0;

    Lc3f5c:	; 800C3F5C
        [SP + 2c] = w(walkmesh_triangle_data + triangle_id * 28);

        S0 = 0;

        A0 = walkmesh;
        A2 = walkmesh_triangle_data + triangle_id * 28;
        A1 = walkmesh_triangle_group_data + h[A2 + 4] * 20;
        A3 = SP + 10;
        field_check_in_walkmesh_triangle;



        if (V0 != 0) // if we in triangle
        {
            A0 = 0;
            loopc3fa0:	; 800C3FA0
                [walkmesh_triangle_data + A0 * 28 + 0] = h(hu[walkmesh_triangle_data + A0 * 28 + 0] & ff7f);
                A0 = A0 + 1;
                V0 = A0 < number_of_triangles;
            800C3FB8	bne    v0, zero, loopc3fa0 [$800c3fa0]



            [800c9ddc] = h(0); // for use in next function

            A0 = S3; // entity struct pointer
            A1 = SP + 10; // our position
            A2 = walkmesh_triangle_data + triangle_id * 28;
            A3 = SP + 28;
            field_walkmesh_check_collide_with_triangle_unaccessable;

            if (V0 == 0) // collided
            {
                A0 = S3; // entity struct pointer
                A1 = SP + 10; // our position
                A2 = SP + 2c; // address where we store current triangle data pointer
                A3 = SP + 28; // side of triangle which we can't pass
                funcc31f8;

                if (V0 != 0)
                {
                    S0 = 1;
                }
            }
            else
            {
                S0 = 1;
            }
            
            // if we not collide
            if (S0 != 0)
            {
                A0 = h[walkmesh_triangle_data + triangle_id * 28 + 6];
                if (A0 >= 0)
                {
                    [SP + 18] = w(h[SP + 10]);
                    [SP + 1c] = w(h[SP + 12]);
                    [SP + 20] = w(h[SP + 14]);

                    S0 = w[800c9e04] + A0 * 10;

                    S1 = (w[S0 + 0] * (h[SP + 10] << 10)) >> 10;
                    V0 = (w[S0 + 8] * (w[SP + 20] << 10)) >> 10;
                    V0 = (w[S0 + c] * (w[walkmesh_triangle_data + triangle_id * 28 + 24] - S1 - V0)) >> 10;

                    group_id = h[walkmesh_triangle_data + triangle_id * 28 + 4];

                    [SP + 1c] = w((V0 >> 10) + h[walkmesh_triangle_group_data + group_id * 20 + c] - h[walkmesh_triangle_group_data + group_id * 20 + 6]);
                    // set height
                    [SP + 12] = h(hu[SP + 1c]);
                }
                else
                {
                    group_id    = h[walkmesh_triangle_data + triangle_id * 28 + 4];
                    vertex1_id  = h[walkmesh_triangle_data + triangle_id * 28 + c];
                    // calculate height
                    [SP + 12] = h(hu[walkmesh_vertex_data + vertex1_id * 6 + 2] + hu[walkmesh + a] + hu[walkmesh_triangle_group_data + group_id * 20 + c]);
                }



                if (h[SP + 12] >= h[SP + 38]) // if new Y pos >= than initial Y pos
                {
                    if (h[SP + 12] < height) // if new Y pos < than previous height
                    {
                        FP = 1;
                        height = hu[SP + 12];

                        [SP + 48] = h(triangle_id);
                        [SP + 4a] = h(hu[walkmesh_triangle_data + triangle_id * 28 + 4]); // triangle group
                    }
                }
            }
        }

        triangle_id = triangle_id + 1;
        V0 = triangle_id < number_of_triangles;
    800C4170	bne    v0, zero, Lc3f5c [$800c3f5c]
}



if (FP == 0)
{
    return 0;
}

[S3 + 4] = h(hu[SP + 4a]);
[S3 + 6] = h(hu[SP + 48]);

A0 = w[S3 + 24];

[A0 + 14] = w(h[SP + 30]);
[A0 + 18] = w(height);
[A0 + 1c] = w(h[SP + 40]);

return 1;
////////////////////////////////



////////////////////////////////
// funcc3608

// return
// 0x0002 - default
// | 0x0001 - if we can't move where we want
// | 0x0004 - if destination and start are the same
// | 0x0009 - if we collide but can move away from that side (slide?)
// | 0x0010 - if position changed

entity_data = A0; // pointer to entity struct at 800caad8.
entity_pos = w[entity_data + 24];

S4 = 0002;

walkmesh_header         = w[800c9df8];
walkmesh_vertexes_data  = w[800c9dfc];
walkmesh_triangles_data = w[800c9e00];
walkmesh_normals_data   = w[800c9e04];
walkmesh_groups_data    = w[800c9e0c];



// reset something 1
[800c9dde] = h(0);

V1 = 9;
V0 = 800caa98 + 12;
loopc364c:	; 800C364C
    [V0] = h(-1);
    V0 = V0 - 2;
    V1 = V1 - 1;
800C3654	bgez   v1, loopc364c [$800c364c]



// reset something 2
[800c9de0] = h(0);

V1 = 9;
V0 = 800caab8 + 12;
loopc3678:	; 800C3678
    [V0] = h(-1);
    V0 = V0 - 2;
    V1 = V1 - 1;
800C3680	bgez   v1, loopc3678 [$800c3678]



// store positions
[SP + 20] = h(hu[entity_pos + 14]); // destination x
[SP + 22] = h(hu[entity_pos + 18]); // destination y
[SP + 24] = h(hu[entity_pos + 1c]); // destination z
[SP + 28] = h(hu[entity_pos + 40]); // start x
[SP + 2a] = h(hu[entity_pos + 44]); // start y
[SP + 2c] = h(hu[entity_pos + 48]); // start z



// if destination and start are the same
if ((hu[SP + 20] == hu[SP + 28]) && (hu[SP + 22] == hu[SP + 2a]) && (hu[SP + 24] == hu[SP + 2c]))
{
    [entity_data + 8] = h(hu[entity_data + 4]);
    [entity_data + a] = h(hu[entity_data + 6]);
    return S4 | 0004;
}



triangle_id = h[entity_data + 6];
[SP + 30] = w(walkmesh_triangles_data + triangle_id * 28);

A0 = entity_data;
A1 = SP + 30;
A2 = SP + 28;
A3 = SP + 20;
[SP + 10] = w(1);
[SP + 14] = w(0);
[SP + 18] = w(0);
[SP + 1c] = w(0);
funcc2af0; // move
move_to_triangle = V0;



if (move_to_triangle != 0) // we can't move here
{
    [entity_data + 6] = h(triangle_id);

    if (triangle_id >= 0)
    {
        [entity_data + 4] = h(hu[walkmesh_triangles_data + triangle_id * 28 + 4]);
    }
    else
    {
        [entity_data + 4] = h(-1);
    }

    [entity_pos + 14] = w(w[entity_pos + 40]);
    [entity_pos + 18] = w(w[entity_pos + 44]);
    [entity_pos + 1c] = w(w[entity_pos + 48]);

    S4 = S4 | 0001;

    if ((h[entity_data + a] >= 0) && (h[entity_data + 8] >= 0))
    {
        A0 = walkmesh_header;
        A1 = walkmesh_groups_data + h[entity_data + 8] * 20;
        A2 = walkmesh_triangles_data + h[entity_data + a] * 28;
        A3 = SP + 28;
        funcc4b30;

        if (!V0)
        {
            [entity_data + 8] = h(hu[entity_data + 4]);
            [entity_data + a] = h(hu[entity_data + 6]);
        }
    }
}
else
{
    A0 = 0;
    number_of_triangles = hu[walkmesh_header + 24];

    if (move_to_triangle < number_of_triangles)
    {
        loopc3864:	; 800C3864
            [walkmesh_triangles_data + A0 * 28 + 0] = h(hu[walkmesh_triangles_data + A0 * 28 + 0] & ff7f);
            A0 = A0 + 1;
            V0 = A0 < number_of_triangles;
        800C387C	bne    v0, zero, loopc3864 [$800c3864]
    }

    [800c9ddc] = h(0);

    A0 = entity_data;
    A1 = SP + 20;
    A2 = w[SP + 30];
    A3 = SP + 34;
    field_walkmesh_check_collide_with_triangle_unaccessable;

    if (V0 == 0) // collided
    {
        A0 = entity_data;
        A1 = SP + 20; // our position
        A2 = SP + 30; // address where we store current triangle data pointer
        A3 = SP + 34; // side of triangle which we can't pass
        funcc31f8; // try move away from side of triangle

        if (V0 == 0)
        {
            [entity_data + 6] = h(triangle_id);

            if (triangle_id >= 0)
            {
                [entity_data + 4] = h(hu[walkmesh_triangles_data + triangle_id * 28 + 4]);
            }
            else
            {
                [entity_data + 4] = h(-1);
            }

            [entity_pos + 14] = w(w[entity_pos + 40]);
            [entity_pos + 18] = w(w[entity_pos + 44]);
            [entity_pos + 1c] = w(w[entity_pos + 48]);

            S4 = S4 | 0001;

            if ((h[entity_data + a] >= 0) && (h[entity_data + 8] >= 0))
            {
                A0 = walkmesh_header;
                A1 = walkmesh_groups_data + h[entity_data + 8] * 20;
                A2 = walkmesh_triangles_data + h[entity_data + a] * 28;
                A3 = SP + 28;
                funcc4b30;

                if (!V0)
                {
                    [entity_data + 8] = h(hu[entity_data + 4]);
                    [entity_data + a] = h(hu[entity_data + 6]);
                }
            }
            return S4;
        }

        S4 = S4 | 9;
    }



    // set X andZ pos
    if ((h[SP + 20] != w[entity_pos + 14]) || (h[SP + 24] != w[entity_pos + 1c]))
    {
        S4 = S4 | 0010;
        [entity_pos + 14] = w(h[SP + 20]);
        [entity_pos + 1c] = w(h[SP + 24]);
    }



    // set Y coord for our position
    current_triangle = w[SP + 30];
    normal_id = h[current_triangle + 6];
    if (normal_id >= 0)
    {
        if (w[walkmesh_normals_data + normal_id * 10 + 4] + 50f4 > a1e8)
        {
            S0 = (w[walkmesh_normals_data + normal_id * 10 + 0] * (w[entity_pos + 14] << 10)) >> 10;
            V0 = (w[walkmesh_normals_data + normal_id * 10 + 8] * (w[entity_pos + 1c] << 10)) >> 10;

            [entity_pos + 18] = w(((w[current_triangle + 24] - S0 - V0) * w[walkmesh_normals_data + normal_id * 10 + c]) >> 10);

            V0 = walkmesh_groups_data + h[current_triangle + 4] * 20;

            [entity_pos + 18] = w(w[entity_pos + 18] + h[V0 + c] - h[V0 + 6]);
        }
        else
        {
            [entity_pos + 18] = w(h[SP + 22]);
        }
    }
    else
    {
        group_id = h[current_triangle + 4];
        vertex1_id = h[current_triangle + c];
        [entity_pos + 18] = w(h[walkmesh_vertexes_data + vertex1_id * 6 + 2] + h[walkmesh_header + a] + h[walkmesh_groups_data + group_id * 20 + c])
    }



    [entity_data + a] = h(triangle_id);



    if (triangle_id >= 0)
    {
        [entity_data + 8] = h(hu[walkmesh_triangles_data + triangle_id * 28 + 4]);
    }
    else
    {
        [entity_data + 8] = h(-1);
    }
}

return S4;
////////////////////////////////