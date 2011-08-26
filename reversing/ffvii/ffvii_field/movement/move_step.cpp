////////////////////////////////
// main_walkmesh_move
triggers_block_offset = w[800716C4];
id_block_offset       = w[800E4274];

visible_entity_id    = A0;
current_model_offset = 80074ea4 + visible_entity_id * 84
[SP + 18] = visible_entity_id;

current_triangle = h[80074EA4 + 72];
[current_triangle_address] = current_triangle;
Ax = h[id_block_offset + current_triangle * 18 + 00];
Ay = h[id_block_offset + current_triangle * 18 + 02];
Az = h[id_block_offset + current_triangle * 18 + 04];
Bx = h[id_block_offset + current_triangle * 18 + 08];
By = h[id_block_offset + current_triangle * 18 + 0A];
Bz = h[id_block_offset + current_triangle * 18 + 0C];
Cx = h[id_block_offset + current_triangle * 18 + 10];
Cy = h[id_block_offset + current_triangle * 18 + 12];
Cz = h[id_block_offset + current_triangle * 18 + 14];

[1F800040] = w(Bx - Ax);
[1F800044] = w(By - Ay);
[1F800048] = w(Bz - Az);
[1F800050] = w(Cx - Bx);
[1F800054] = w(Cy - By);
[1F800058] = w(Cz - Bz);

A0 = 1F800040;
A1 = 1F800050;
A2 = 1F800060;
OuterProduct0;

[1f800060] = w(w[1f800060] >> 8);

V1 = [1F800064];
V1 >> 8;
[1F800064] = w(V1);

A2 = [1F800068];
A2 >> 8;
[1F800068] = w(A2);

A0 = 1f800060;
A1 = 1f800060;
system_normalize_vector_A0_to_A1;



V0 = w[1F800060];
HI/LO = V0 * V0;
V1 = LO;
V0 = w[1F800068];
HI/LO = V0 * V0;
A0 = LO;
V0 = V1 >> 0C;
A0 = A0 >> 0C;
A0 = V0 + A0;
func3a59c;
A0 = w[1F800068];
V1 = A0 << 0C;
HI/LO = V1 / V0;
V1 = LO;
[1F800060] = w(V1);



V0 = w[1F800064];
HI/LO = V0 * V0;
V0 = LO;
A0 = w[1F800068];
HI/LO = A0 * A0;
A0 = LO;
V0 = V0 >> 0C;
A0 = A0 >> 0C;
A0 = V0 + A0;
func3a59c;
V1 = w[1F800068]
V1 = V1 << 0C;
HI/LO = V1 / V0;
V1 = LO;
[1F800064] = w(V1);



V0 = w[1F800060];
[1F800060] = (V0 >= 1001) ? w(1000) : w(V0);
[1F800060] = (V0 < -1000) ? w(-1000) : w(V0);

V0 = w[1F800064];
[1F800064] = (V0 >= 1001) ? w(1000) : w(V0);
[1F800064] = (V0 < -1000) ? w(-1000) : w(V0);

V0 = w[1F800068];
[1F800068] = (V0 >= 1001) ? w(1000) : w(V0);
[1F800068] = (V0 < -1000) ? w(-1000) : w(V0);


T3 = w[1F800060];
[SP + 38] = (T3 < 0) ? w(-T3) : w(T3);

T3 = w[1F800064];
[SP + 40] = (T3 < 0) ? w(-T3) : w(T3);



S7 = 0;

// loop
La92f4:	; 800A92F4
S7 = S7 + 1;

if (visible_entity_id == h[800965E0] && bu[80071C0C] == 1 && S7 >= 3)
{
    [80071C0C] = b(0);
}
else if (((visible_entity_id != h[800965E0]) ||
          (visible_entity_id == h[800965E0] && bu[80071C0C] == 1 && S7 < 3) ||
          (visible_entity_id == h[800965E0] && bu[80071C0C] != 1 && S7 < 11))
{
    {
        A0 = bu[current_model_offset + 36];
        get_direction_vector_x;
        T3 = w[SP + 38];
        HI/LO = V0 * T3;
        V0 = LO;
        V0 = V0 >> 0C;
        [1F800070] = w(V0);



        A0 = bu[current_model_offset + 36];
        get_direction_vector_y;
        T3 = w[SP + 40];
        HI/LO = V0 * T3;
        V0 = LO;
        V0 = 0 - V0;
        V0 = V0 >> C;
        [1F800074] = w(V0);



        // multiply move vector x by speed
        V1 = hu[current_model_offset + 70];
        V0 = w[1F800070];
        HI/LO = V1 * V0;
        V0 = LO;
        V0 = V0 >> 8;
        [1F800070] = w(V0);

        // multiply move vector y by speed
        V1 = hu[current_model_offset + 70];
        V0 = w[1F800074];
        HI/LO = V1 * V0;
        V0 = LO;
        V0 = V0 >> 8;
        [1F800074] = w(V0);

        // x with move vector
        V0 = w[current_model_offset + 0C];
        V1 = w[1F800070];
        V0 = V0 + V1;
        [1F800070] = w(V0);

        // y with move vector
        V0 = w[current_model_offset + 10];
        V1 = w[1F800074];
        V0 = V0 + V1;
        [1F800074] = w(V0);

        // store z as is
        V0 = w[current_model_offset + 14];
        [1F800078] = w(V0);

        // with solid range x
        A0 = bu[current_model_offset + 36];
        A0 = A0 + 20;
        A0 = A0 & FF;
        get_direction_vector_x;
        V1 = hu[current_model_offset + 6C];
        HI/LO = V1 * V0;
        V0 = LO;
        [1F800090] = w(V0);

        // with solid range y
        A0 = bu[current_model_offset + 36];
        A0 = A0 + 20;
        A0 = A0 & FF;
        get_direction_vector_y;
        V0 = 0 - V0;
        V1 = hu[current_model_offset + 6C];
        HI/LO = V1 * V0;
        V0 = LO;
        [1F800094] = w(V0);



        T0 = w[1F800078];
        [1F800088] = w(T0);



        // x with solid addition
        T1 = w[1F800090];
        V0 = w[1F800070];
        V0 = V0 + T1;
        [1F800080] = w(V0);

        // y with solid addition
        T2 = w[1F800094];
        V1 = w[1F800074];
        V1 = V1 + T2;
        [1F800084] = w(V1);



        // check if we cross border of triangle
        A0 = current_triangle_address;
        A1 = 1F800080;
        A2 = 1F800090;
        A3 = 1F800060;
        walkmesh_border_cross;
        first_border_cross = V0;



        A0 = visible_entity_id;
        A1 = 1F800080;
        entity_collision_check;
        first_entity_collision = V0;



        V1 = hu[current_model_offset + 72];
        [current_triangle_address] = h(V1);
    }



    {
        A0 = bu[current_model_offset + 36];
        A0 = A0 - 20;
        A0 = A0 & FF;
        get_direction_vector_x;
        V1 = hu[current_model_offset + 6C];
        HI/LO = V1 * V0;
        V0 = LO;
        [1F800090] = w(V0);



        A0 = bu[current_model_offset + 36];
        A0 = A0 - 20;
        A0 = A0 & FF;
        get_direction_vector_y;
        V1 = bu[current_model_offset + 6C];
        HI/LO = V1 * (0 - V0);
        V0 = LO;
        [1F800094] = w(V0);



        T0 = w[1F800078];
        [1F800088] = w(T0);

        T1 = w[1F800090];
        V0 = w[1F800070];
        V0 = V0 + T1;
        [1F800080] = w(V0);

        T2 = w[1F800094];
        V1 = w[1F800074];
        V1 = V1 + T2;
        [1F800084] = w(V1);



        A0 = current_triangle_address;
        A1 = 1F800080;
        A2 = 1F800090;
        A3 = 1F800060;
        walkmesh_border_cross;
        second_border_cross = V0;



        A0 = visible_entity_id;
        A1 = 1F800080;
        entity_collision_check;
        second_entity_collision = V0;


        V1 = hu[current_model_offset + 72];
        [current_triangle_address] = h(V1);
    }



    {
        A0 = bu[current_model_offset + 36];
        get_direction_vector_x;
        V1 = hu[current_model_offset + 6C];
        HI/LO = V1 * V0;
        V0 = LO;
        [1F800090] = w(V0);

        A0 = bu[current_model_offset + 36];
        get_direction_vector_y;
        V1 = hu[current_model_offset + 6C];
        V0 = 0 - V0;
        HI/LO = V1 * V0;
        V0 = LO;
        [1F800094] = w(V0);

        T0 = w[1F800078];
        [1F800088] = w(T0);

        T1 = w[1F800090];
        V0 = w[1F800070];
        V0 = V0 + T1;
        [1F800080] = w(V0);

        T2 = w[1F800094];
        V1 = w[1F800074];
        V1 = V1 + T2;
        [1F800084] = w(V1);

        A0 = current_triangle_address;
        A1 = 1F800080;
        A2 = 1F800090;
        A3 = 1F800040;
        walkmesh_border_cross;
        third_border_cross = V0;



        A0 = visible_entity_id;
        A1 = 1F800080;
        entity_collision_check;



        S4 = 0;
        // if we collide with entity
        if (V0 != 0)
        {
            // 0 and -8 => S4 = 8 else 0;
            V0 = third_border_cross < 1;
            S4 = V0 * 8;
        }
    }



    if (third_border_cross != 0 || first_border_cross != 0 || second_border_cross != 0 || S4 != 0 || first_entity_collision != 0 || second_entity_collision != 0)
    {
        // NPC
        if (visible_entity_id != h[800965E0] || bu[8009ABF4 + 32] != 0)
        {
            // if we collide only directly into triangle border
            if (third_border_cross != 0 && first_border_cross == 0 && second_border_cross == 0)
            {
                V0 = bu[current_model_offset + 36];
                V0 = V0 - 5;
                [current_model_offset + 36] = b(V0);
            }
            // or if we only collide into others entity directly
            else if (S4 != 0 && first_entity_collision == 0 && second_entity_collision == 0)
            {
                V0 = bu[current_model_offset + 36];
                V0 = V0 - S4;
                [current_model_offset + 36] = b(V0);
            }

            // if not both left and right check was fail
            if (first_border_cross == 0 || second_border_cross == 0)
            {
                if ((first_border_cross == 0 && first_entity_collision != 0) ||
                    (first_border_cross != 0 && second_border_cross == 0))
                {
                    V0 = bu[current_model_offset + 36];
                    V0 = V0 - 8;
                    [current_model_offset + 36] = b(V0);
                }
                if (first_border_cross == 0 &&
                    first_entity_collision == 0 &&
                    (second_border_cross != 0 || second_entity_collision != 0))
                {
                    V0 = bu[current_model_offset + 36];
                    V0 = V0 + 8;
                    [current_model_offset + 36] = b(V0);
                }

                800A98E8	j      La92f4 [$800a92f4]
            }
        }
        // PC and we not collide to others visible entitys.
        else if (S4 == 0 && first_entity_collision == 0 && second_entity_collision == 0)
        {
            // if not both left and right check was fail
            if (first_border_cross == 0 || second_border_cross == 0)
            {
                if ((first_border_cross == 0 && first_entity_collision != 0) ||
                    (first_border_cross != 0 && second_border_cross == 0))
                {
                    V0 = bu[current_model_offset + 36];
                    V0 = V0 - 8;
                    [current_model_offset + 36] = b(V0);
                }
                if (first_border_cross == 0 &&
                    first_entity_collision == 0 &&
                    (second_border_cross != 0 || second_entity_collision != 0))
                {
                    V0 = bu[current_model_offset + 36];
                    V0 = V0 + 8;
                    [current_model_offset + 36] = b(V0);
                }

                800A98E8	j      La92f4 [$800a92f4]
            }
        }
    }
}

A0 = 80074EA4 + visible_entity_id * 84 + 72;
A1 = 1F800070;
A2 = 1F800090;
A3 = 1F800040;
walkmesh_border_cross;
last_border_cross  = w(V0);

// if entity we moving is PC entity and we are moving it ourself
if (visible_entity_id == h[800965E0] && bu[8009ABF4 + 32] == 0)
{
    A0 = 80074EA4 + visible_entity_id * 84;
    A1 = 8007E7AC;
    A2 = 1F800070;
    move_line_check;
    [80071C0C] = b(V0);

    // gateways check
    V1 = bu[8009ABF4 + 36];
    if (V1 == 0)
    {
        A0 = 80074EA4 + visible_entity_id * 84;
        A1 = triggers_block_offset + 38;
        A2 = 1F800070;
        move_gateway_check;
    }

    // triggers check
    A0 = 80074EA4 + visible_entity_id * 84;
    A1 = triggers_block_offset + 158;
    A2 = 1F800070;
    move_trigger_check;
}

if (third_border_cross != 0 || first_border_cross != 0 || second_border_cross != 0 || S4 != 0 || first_entity_collision != 0 || second_entity_collision != 0 || last_border_cross != 0)
{
    return 0;
}

V1 = w[1F800070];
[current_model_offset + 0C] = w(V1); // X
V0 = w[1F800074];
[current_model_offset + 10] = w(V0); // Y
V0 = w[1F800078];
V0 = V0 << C;
[current_model_offset + 14] = w(V0); // Z

V1 = bu[current_model_offset + 5D];
if (V1 != 0 || visible_entity_id != h[800965E0])
{
    return 1;
}

// set animation if this is manual movement
[current_model_offset + 60] = h(10);

V0 = w[80114454];
if (V0 & 0040) // if run button pressed
{
    A2 = 8009ABF4 + 30; // run
}
else
{
    A2 = 8009ABF4 + 2E; // walk
}

V1 = w[8008357C];
V0 = bu[V1 + visible_entity_id * 8 + 4];
A0 = w[8004A62C];
V1 = w[A0 + 4];
V1 = bu[V1 + V0 * 24];

A0 = 0;
V0 = h[A2]; // load animation id
if (V0 < V1)
{
    A0 = bu[A2];
}

[current_model_offset + 5E] = b(A0);
return 1;
////////////////////////////////



////////////////////////////////
// walkmesh_border_cross
triangle_info_offset      = A0;
triangle_id               = hu[triangle_info_offset];
offset_to_id_block        = w[800E4274];
offset_to_id_access_block = w[80114458];
offset_to_triangle        = offset_to_id_block + triangle_id * 18
offset_to_triangle_access = offset_to_id_access_block + triangle_id * 6
position                  = A1;
S4 = A2; // we multiply board vector with this vector and return +8 or -8 according to it
S1 = A3; // we store collision board here
S3 = 0;

V0 = w[position + 0];
V0 = V0 >> 0C;
[1F800030] = w(V0);

V0 = w[position + 4];
V0 = V0 >> 0C;
[1F800034] = w(V0);

[1F800038] = w(0);

[80113F28] = h(FFFF);



// jump here if we can cross side of previous triangle
La89f0:	; 800A89F0
A0 = 1F800000;
A1 = offset_to_triangle + 8;
A2 = offset_to_triangle;
walkmesh_vector_sub;

A0 = 1F800010;
A1 = offset_to_triangle + 10;
A2 = offset_to_triangle + 8;
walkmesh_vector_sub;

A0 = 1F800020;
A1 = offset_to_triangle;
A2 = offset_to_triangle + 10;
walkmesh_vector_sub;



A3 = (w[1F800030] - h[offset_to_triangle + 00]) * w[1F800004];
T2 = (w[1F800034] - h[offset_to_triangle + 02]) * w[1F800000];
T1 = (w[1F800030] - h[offset_to_triangle + 08]) * w[1F800014];
T0 = (w[1F800034] - h[offset_to_triangle + 0a]) * w[1F800010];
A0 = (w[1F800030] + h[offset_to_triangle + 10]) * w[1F800024];
V0 = (w[1F800034] - h[offset_to_triangle + 12]) * w[1F800020];

A3 = A3 - T2;
T1 = T1 - T0;
A0 = A0 - V0;

// if we cross AB
if (A3 < 0)
{
    A0 = hu[offset_to_triangle_access + 0];
    if (A0 >= 0)
    {
        V1 = bu[8009ABF4 + V0 / 8 + B2];
        V0 = A0 & 7;
        V1 = V0 >> V1;
        V1 = V1 & 1;
        if (V1 == 0)
        {
            [triangle_info_offset] = h(A0);
            800A8D1C	j      La89f0 [$800a89f0]
        }
    }

    V0 = w[1F800000];
    [S1] = w(V0);
    V0 = w[1F800004];
    [S1] = w(V0 + 4);
    V0 = w[1F800008];
    [S1] = w(V0 + 8);

    V1 = w[1F800000];
    V0 = w[S4];
    HI/LO = V1 * V0;
    V1 = LO;

    A0 = w[1F800004];
    V0 = w[S4 + 4];
    HI/LO = A0 * V0;
    V0 = LO;

    V1 = V1 + V0;
    if (V1 >= 0)
    {
        S3 = 8;
    }
    else
    {
        S3 = -8;
    }

    [801144CC] = h(0);
    [80113F28] = h(triangle_id);
}
// if we cross BC
else if (T1 < 0)
{
    // if we can cross this side
    A0 = hu[offset_to_triangle_access + 2];

    if (A0 >= 0)
    {
        V1 = bu[8009ABF4 + V0 / 8 + B2];
        V0 = A0 & 7;
        V1 = V0 >> V1;
        V1 = V1 & 1;
        if (V1 == 0)
        {
            [triangle_info_offset] = h(A0);
            800A8D1C	j      La89f0 [$800a89f0]
        }
    }

    V0 = w[1F800010];
    [S1] = w(V0);
    V0 = w[1F800014];
    [S1] = w(V0 + 4);
    V0 = w[1F800018];
    [S1] = w(V0 + 8);

    V1 = w[1F800010];
    V0 = w[S4];
    HI/LO = V1 * V0;
    V1 = LO;

    A0 = w[1F800014];
    V0 = w[S4 + 4];
    HI/LO = A0 * V0;
    V0 = LO;

    V1 = V1 + V0;
    if (V1 >= 0)
    {
        S3 = 8;
    }
    else
    {
        S3 = -8;
    }

    [801144CC] = h(1);
    [80113F28] = h(triangle_id);
}
// if we cross CA
else if (A0 < 0)
{
    A0 = hu[offset_to_triangle_access + 4];

    if (A0 >= 0)
    {
        V1 = bu[8009ABF4 + V0 / 8 + B2];
        V0 = A0 & 7;
        V1 = V0 >> V1;
        V1 = V1 & 1;
        if (V1 == 0)
        {
            [triangle_info_offset] = h(A0);
            800A8D1C	j      La89f0 [$800a89f0]
        }
    }

    V0 = w[1F800020];
    [S1] = w(V0);
    V0 = w[1F800024];
    [S1] = w(V0 + 4);
    V0 = w[1F800028];
    [S1] = w(V0 + 8);

    V1 = w[1F800020];
    V0 = w[S4];
    HI/LO = V1 * V0;
    V1 = LO;

    A0 = w[1F800024];
    V0 = w[S4 + 4];
    HI/LO = A0 * V0;
    V0 = LO;

    V1 = V1 + V0;
    if (V1 >= 0)
    {
        S3 = 8;
    }
    else
    {
        S3 = -8;
    }

    [801144CC] = h(2);
    [80113F28] = h(triangle_id);
}

A0 = 1F800000;
A1 = 1F800010;
A2 = 1F800030;
A3 = offset_to_triangle;
walkmesh_calculate_z;
[position + 8] = w(V0);

return S3;
////////////////////////////////



////////////////////////////////
// walkmesh_vector_sub
A0 - address to save point1 - point2
A1 - point1
A2 - point2

V0 = h[A1 + 0];
V1 = h[A2 + 0];
V0 = V0 - V1;
[A0 + 0] = w(V0);

V0 = h[A1 + 2];
V1 = h[A2 + 2];
V0 = V0 - V1;
[A0 + 4] = w(V0);

V0 = h[A1 + 4];
V1 = h[A2 + 4];
V0 = V0 - V1;
[A0 + 8] = w(V0);
////////////////////////////////



////////////////////////////////
// get_direction_vector_x
V0 = h[800DF120 + A0 * 4];
////////////////////////////////



////////////////////////////////
// get_direction_vector_y
V0 = [800DF122 + A0 * 4];
////////////////////////////////



////////////////////////////////
entity_collision_check
given_visible_entity     = A0;
number_of_visible_entity = h[8009AC1C]
given_position           = A1;
visible_entity_to_check  = 0;
solid_range              = hu[80074EA4 + given_visible_entity * 84 + 6C];
T2 = 0;

if (number_of_visible_entity > 0)
{
    loopa9bb4:	; 800A9BB4

    if (visible_entity_to_check != given_visible_entity)
    {
        // if entity solid
        V0 = bu[80074EA4 + visible_entity_to_check * 84 + 59];
        if (V0 == 0)
        {
            // if Z value not very different
            V0 = bu[80074EA4 + visible_entity_to_check * 84 + 14];
            V0 = V0 >> 0C;
            V0 = V0 - w[given_position + 8] + 7E;
            if (V0 < FE)
            {
                // sum of solid range
                A0 = solid_range + hu[80074EA4 + visible_entity_to_check * 84 + 6C];
                A0 = A0 >> 1;
                HI/LO = A0 * A0;
                A0 = LO;

                V0 = w[80074EA4 + visible_entity_to_check * 84 + 0C] - w[given_position + 0];
                V0 = V0 >> 0C
                HI/LO = V0 * V0;
                V1 = LO;

                V0 = w[80074EA4 + visible_entity_to_check * 84 + 10] - w[given_position + 4];
                V0 = V0 >> 0C;
                HI/LO = V0 * V0;
                V0 = LO;

                // if we collide
                V1 = V1 + V0;
                if (V1 < A0)
                {
                    T2 = 1;

                    V0 = h[800965E0];
                    if (given_visible_entity == V0)
                    {
                        [80074EA4 + visible_entity_to_check * 84 + 58] = b(1);
                    }
                }
            }
        }
    }

    visible_entity_to_check = visible_entity_to_check + 1;
    V0 = visible_entity_to_check < number_of_visible_entity;
    800A9CD0	bne    v0, zero, loopa9bb4 [$800a9bb4]
}

return T2;
////////////////////////////////



////////////////////////////////
// walkmesh_calculate_z
vec1 = A0;
vec2 = A1;
pos  = A2;
offset_to_triangle = A3;

SP = SP - 10;

[SP + 0] = w((w[vec2 + 4] * w[vec1 + 8]) - (w[vec1 + 4] * w[vec2 + 8]));
[SP + 4] = w((w[vec1 + 0] * w[vec2 + 8]) - (w[vec1 + 8] * w[vec2 + 0]));
[SP + 8] = w((w[vec2 + 0] * w[vec1 + 4]) - (w[vec1 + 0] * w[vec2 + 4]));

[vec1 + 0] = w(h[offset_to_triangle + 0]);
[vec1 + 4] = w(h[offset_to_triangle + 2]);
[vec1 + 8] = w(h[offset_to_triangle + 4]);

V0 = w[SP + 0] * w[vec1 + 0];
T2 = w[SP + 4] * w[vec1 + 4];
A3 = w[SP + 8] * h[offset_to_triangle + 4];
A1 = w[SP + 0] * w[pos + 0];
V1 = w[SP + 4] * w[pos + 4];

V0 = (V0 + T2 + A3 - A1 - V1) / (vec1 + 0);
return V0;
////////////////////////////////



////////////////////////////////
// move_line_check
entity_data_offset = A0;
line_offset        = A1;
S6 = 0;
FP = 0;



//old position x
V0 = w[entity_data_offset + C];
V0 = V0 >> C;
[1F800000] = w(V0);
//old position y
V0 = w[entity_data_offset + 10];
V0 = V0 >> C;
[1F800004] = w(V0);
//old position z
V0 = w[entity_data_offset + 14];
V0 = V0 >> C;
[1F800008] = w(V0);

//new position x
V0 = w[A2 + 0];
V0 = V0 >> C;
[1F800010] = w(V0);
//new position y
V0 = w[A2 + 4];
V0 = V0 >> C;
[1F800014] = w(V0);
//old position z
V0 = w[entity_data_offset + 14];
V0 = V0 >> C;
[1F800018] = w(V0);



La9f9c:	; 800A9F9C
V0 = bu[line_offset + 0C];
if (V0 == 1)
{
    [line_offset + 15] = b(0);

    A0 = line_offset;
    A1 = 1F800000;
    A2 = 1F800020;
    move_distance_to_line;

    V1 = V0;
    [SP + 10] = w(V1);

    V0 = hu[entity_data_offset + 6C]; // solid range
    V0 = V0 * V0;

    // if we closer to line than solid range
    if (V1 != -1 && V1 < V0)
    {
        V0 = bu[line_offset + 16];
        if (V0 == 1)
        {
            FP = 1;
        }

        V0 = bu[line_offset + 0E];
        if (V0 == 0)
        {
            [line_offset + 12] = b(1);
        }
        [line_offset + 0E] = b(1);

        x1 = h[line_offset + 00]; // x1
        y1 = h[line_offset + 02]; // y1
        x2 = h[line_offset + 06]; // x2
        y2 = h[line_offset + 08]; // y2
        old_x = w[1F800000];
        old_y = w[1F800004];
        new_x = w[1F800010];
        new_y = w[1F800014];

        T0 = ((x2 - x1) * (old_y - y1)) - ((old_x - x1) * (y2 - y1));
        A0 = ((x2 - x1) * (new_y - y1)) - ((new_x - x1) * (y2 - y1));

        // if we cross the line
        if ((A0 > 0 && T0 <= 0) || (T0 > 0 && A0 <= 0) || (A0 >= 0 && T0 < 0) || (T0 >= 0 && A0 < 0))
        {
            [line_offset + 0F] = b(1);
        }

        // if we not move in line
        if (w[1F800000] == w[1F800020] && w[1F800004] == w[1F800024])
        {
            [line_offset + 10] = b(1);
            [line_offset + 15] = b(1);
        }
        else
        {
            A0 = 1F800000;
            A1 = 1F800020;
            A2 = SP + 10;
            calculate_direction_by_vectors;

            [line_offset + 14] = b(V0);

            V0 = bu[line_offset + 14];
            V1 = bu[entity_data_offset + 36];
            V0 = V0 - V1 + 40;
            V0 = V0 & FF;
            if (V0 < 80)
            {
                [line_offset + 10] = b(1);
                [line_offset + 15] = b(1);
            }
        }
    }
    else
    {
        V0 = bu[line_offset + 0E];
        if (V0 == 1)
        {
            [line_offset + 13] = b(1);
        }

        [line_offset + 0E] = b(0);
    }
}

S6 = S6 + 1;
line_offset = line_offset + 18;
V0 = S6 < 20;
800AA140	bne    v0, zero, La9f9c [$800a9f9c]

return FP;
////////////////////////////////



////////////////////////////////
// move_distance_to_line
A0 = line_offset;
x1 = h[A0 + 0];
y1 = h[A0 + 2];
z1 = h[A0 + 4];
x2 = h[A0 + 6];
y2 = h[A0 + 8];
z2 = h[A0 + A];
x3 = h[A1 + 0];
y3 = h[A1 + 4];
z3 = h[A1 + 8];

V1 = (x1 - x3) * (x2 - x1);
T1 = (y1 - y3) * (y2 - y1);
A2 = (z1 - z3) * (z2 - z1);
V0 = (x2 - x1) * (x2 - x1);
A1 = (y2 - y1) * (y2 - y1);
A0 = (z2 - z1) * (z2 - z1);

A0 = -(V1 + T1 + A2) / (V0 + A1 + A0);

[A2 + 0] = x = A0 * (x2 - x1) + x1;
[A2 + 4] = y = A0 * (y2 - y1) + y1;
[A2 + 8] = z = A0 * (z2 - z1) + z1;

if (((x1 >= x && x2 <= x) || (x1 < x && x2 >= x)) &&
    ((y1 >= y && y2 <= y) || (y1 < y && y2 >= y)))
{
    A0 = (x - x3) * (x - x3) + (y - y3) * (y - y3) + (z - z3) * (z - z3);
    return A0;
}

return -1;
////////////////////////////////



////////////////////////////////
// move_talk_to_line
model_data = A0;
line_data = A1;

V0 = w[model_data + C];
V0 = V0 >> C;
[1F800000] = w(V0);
V0 = w[model_data + 10];
V0 = V0 >> C;
[1F800004] = w(V0);
V0 = w[model_data + 14];
V0 = V0 >> C;
[1F800008] = w(V0);

S4 = 0;

loopaa1fc:	; 800AA1FC
V0 = bu[line_data + 0C]
if (V0 == 1)
{
    V0 = bu[model_data + 5D];

    if (V0 == 0)
    {
        A0 = line_data;
        A1 = 1F800000;
        A2 = 1F800010;
        move_distance_to_line;
        V1 = V0;

        V0 = hu[model_data + 6C];
        V0 = V0 * V0;

        // if we closer to line than solid range
        if (V1 != -1 && V1 < V0)
        {
            V0 = bu[line_data + 0E];
            if (V0 == 0)
            {
                [line_data + 12] = b(1);
            }
            [line_data + 0E] = b(1);
        }
        else
        {
            V0 = bu[line_data + 0E];
            if (V0 == 1)
            {
                [line_data + 13] = b(1);
            }
            [line_data + 0E] = b(0);
        }

        // check if we talk to line
        V0 = bu[line_data + 15];
        if (V0 == 1)
        {
            V0 = bu[line_data + 14];
            V1 = bu[model_data + 36];
            V0 = V0 - V1 + 20;
            V0 = V0 & FF;

            if (V0 < 40)
            {
                if (((w[8009ABF4 + 78] & 20) != 0) && (w[8009ABF4 + 7C] & 20 == 0))
                {
                    [line_data + 11] = b(1);
                }
            }
        }
    }
}

line_data = line_data + 18;
S4 = S4 + 1;
V0 = S4 < 20;
800AA2F4	bne    v0, zero, loopaa1fc [$800aa1fc]
////////////////////////////////



////////////////////////////////
// move_gateway_check
entity_data_offset = S3 = A0;
S1 = A1;

old position x
V0 = w[entity_data_offset + C];
V0 = V0 >> C;
[1F800000] = w(V0);
old position y
V0 = w[entity_data_offset + 10];
V0 = V0 >> C;
[1F800004] = w(V0);
old position z
V0 = w[entity_data_offset + 14];
V0 = V0 >> C;
[1F800008] = w(V0);

new position x
V0 = w[A2 + 0];
V0 = V0 >> C;
[1F800010] = w(V0);
new position y
V0 = w[A2 + 4];
V0 = V0 >> C;
[1F800014] = w(V0);
old position z
V0 = w[entity_data_offset + 14];
V0 = V0 >> C;
[1F800018] = w(V0);

S2 = 0;

loopaa3e8:	; 800AA3E8
V1 = hu[S0 + A];
if (V1 != 7FFF)
{
    A0 = S1;
    A1 = S4 = 1F800000;
    A2 = S6 = 1F800020;
    move_distance_to_line;

    V1 = V0;
    if (V1 != -1)
    {
        V0 = hu[S3 + 6C];
        V0 = V0 * V0;
        if (V1 < V0)
        {
            x1 = h[S1 + 0]; // x1
            y1 = h[S1 + 2]; // y1
            x2 = h[S1 + 6]; // x2
            y2 = h[S1 + 8]; // y2
            old_x = w[1F800000];
            old_y = w[1F800004];
            new_x = w[1F800010];
            new_y = w[1F800014];

            T0 = ((x2 - x1) * (old_y - y1)) - ((old_x - x1) * (y2 - y1));
            A0 = ((x2 - x1) * (new_y - y1)) - ((new_x - x1) * (y2 - y1));

            if ((A0 > 0 && T0 <= 0) || (T0 > 0 && A0 <= 0) || (A0 >= 0 && T0 < 0) || (T0 >= 0 && A0 < 0)
            {
                A0 = S1;
                set_gateway_to_map_load;
            }
        }
    }
}

Laa4d4:	; 800AA4D4
S2 = S2 + 1;
S1 = S1 + 18;
V0 = S2 < C;
800AA4E0	bne    v0, zero, loopaa3e8 [$800aa3e8]
////////////////////////////////



////////////////////////////////
// set_gateway_to_map_load
[8009ABF4 + 01] = b(1);
[8009ABF4 + 02] = h(hu[A0 + 12]); // map id
[8009ABF4 + 04] = h(hu[A0 + 0C]); // x
[8009ABF4 + 06] = h(hu[A0 + 0E]); // y
[8009ABF4 + 22] = h(hu[A0 + 10]); // z
[8009ABF4 + 24] = h(bu[A0 + 14]); // rotation
////////////////////////////////



////////////////////////////////
// move_trigger_check
S4 = A0;
S1 = A1;
S3 = 1F800020;
A1 = 800A00BC;
800AA624	lwl    v0, $0003(a1)
800AA628	lwr    v0, $0000(a1)
800AA62C	lwl    v1, $0007(a1)
800AA630	lwr    v1, $0004(a1)
800AA634	swl    v0, $0013(sp)
800AA638	swr    v0, $0010(sp)
800AA63C	swl    v1, $0017(sp)
800AA640	swr    v1, $0014(sp)
S6 = 0;
V0 = w[S4 + C];
S5 = 1F800000;
V0 = V0 >> C;
[S5] = w(V0);
V0 = w[S4 + 10];
S2 = SP + 10;
V0 = V0 >> C;
[1F800004] = w(V0);
V0 = w[S4 + 14];
V0 = V0 >> C;
[1F800008] = w(V0);

Laa684:	; 800AA684
V1 = bu[S1 + C]; // enterstate
if (V1 != FF)
{
    A0 = S1;
    A1 = S5;
    A2 = S3;
    move_distance_to_line;

    V1 = V0;
    [SP + 18] = w(V1);

    // if we closer to line than solid range
    if (V1 != -1 && V1 < (hu[S4 + 6C] * hu[S4 + 6C]))
    {
        // if coords change
        if (w[S5 + 0] != w[S3 + 0] || w[S5 + 4] != w[S3 + 4])
        {
            A0 = S5;
            A1 = S3;
            A2 = SP + 18;
            calculate_direction_by_vectors;

            V1 = bu[S4 + 36];
            V0 = V0 & FF;
            V0 = V0 - V1 + 40;
            V0 = V0 & FF;
            if (V0 >= 80)
            {
                S6 = S6 + 1;
                V0 = S6 < C;
                S1 = S1 + 10;
                800AA838	bne    v0, zero, Laa684 [$800aa684]

                return;
            }
        }

        A0 = S1;
        A1 = bu[S1 + E];
        trigger_background_manipulate;

        if (V0 == 1)
        {
            V0 = bu[S1 + F];
            A0 = hu[S2 + V0 * 2];

            func1117c;
        }
    }
    else
    {
        A3 = bu[S1 + E]; // default state

        if (A3 >= 4)
        {
            x1 = h[S1 + 0];
            y1 = h[S1 + 2];
            x2 = h[S1 + 6];
            y2 = h[S1 + 8];
            x3 = w[S5 + 0];
            y3 = w[S5 + 4];

            if we are in plus side of trigger
            A0 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
            if (A0 > 0)
            {
                S6 = S6 + 1;
                V0 = S6 < C;
                S1 = S1 + 10;
                800AA838	bne    v0, zero, Laa684 [$800aa684]

                return;
            }
        }

        if (A3 == 2 || A3 == 4)
        {
            A0 = S1;
            A1 = 1;
            trigger_background_manipulate;

            if (V0 == 1)
            {
                V0 = bu[S1 + F];
                A0 = hu[S2 + V0 * 2];
                func1117c;
            }
        }

        if (A3 == 3 || A3 == 5)
        {
            A0 = S1;
            A1 = 0;
            trigger_background_manipulate;

            if (V0 == 1)
            {
                V0 = bu[S1 + F];
                A0 = hu[S2 + V0 * 2];

                func1117c;
            }
        }
    }
}

S6 = S6 + 1;
V0 = S6 < C;
S1 = S1 + 10;
800AA838	bne    v0, zero, Laa684 [$800aa684]

return;
////////////////////////////////
