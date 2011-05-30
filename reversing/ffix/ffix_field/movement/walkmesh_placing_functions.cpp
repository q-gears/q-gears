////////////////////////////////
// funcc1dc4
V0 = (A0 * A1) >> 10;
////////////////////////////////




////////////////////////////////
// field_check_in_walkmesh_triangle
// A0 - pointer to start of walkmesh data (after 4 bytes)
// A1 - pointer to current triangle groups data
// A2 - pointer to current triangle data
// A3 - position
// return 1 if in triangle, 0 otherwise

T7 = 0;

Xworld = h(hu[A0 + 8] + hu[A1 + a]);
Zworld = h(hu[A0 + c] + hu[A1 + e]);
Xpoint = h[A3 + 0];
Zpoint = h[A3 + 4];

x_same = 0;
z_same = 0;

walkmesh_vertexes = w[800c9dfc];

T2 = 0;
loopc4f28:	; 800C4F28
    vertex_id = h[A2 + c + T2 * 2];
    [SP + 20 + T2 * 6 + 0] = h(Xworld + hu[walkmesh_vertexes + vertex_id * 6 + 0]);
    [SP + 20 + T2 * 6 + 4] = h(Zworld + hu[walkmesh_vertexes + vertex_id * 6 + 4]);

    if (h[SP + 20 + T2 * 6 + 0] == Xpoint)
    {
        x_same = x_same + 1;

        if (Zpoint >= h[SP + 20 + T2 * 6 + 4])
        {
            x_same = -x_same;
        }
    }

    if (h[SP + 20 + T2 * 6 + 4] == Zpoint)
    {
        z_same = z_same + 1;

        if (Xpoint >= h[SP + 20 + T2 * 6 + 0])
        {
            z_same = -z_same;
        }
    }

    T2 = T2 + 1;
    V0 = T2 < 3;
800C5048	bne    v0, zero, loopc4f28 [$800c4f28]

if ((x_same == -2) || (z_same == -2))
{
    return 1;
}



A2 = SP + 20 + 2 * 6;
XA = h[A2 + 0];
ZA = h[A2 + 4];

p1_less = Zpoint >= ZA;

T2 = 0;
loopc50c0:	; 800C50C0
    XA = h[A2 + 0];
    ZA = h[A2 + 4];
    XB = h[SP + 20 + T2 * 6 + 0];
    ZB = h[SP + 20 + T2 * 6 + 4];

    p2_less = Zpoint >= ZB;

    if (p1_less != p2_less)
    {
        T0 = (XA - XB) * (ZB - Zpoint);
        V0 = (ZA - ZB) * (XB - Xpoint);

        if (T0 == V0)
        {
            return 1;
        }

        if ((V0 >= T0) != p2_less)
        {
            T7 = !T7;
        }
    }

    p1_less = p2_less;

    A2 = SP + 20 + T2 * 6;

    T2 = T2 + 1;
    V0 = T2 < 3;
800C5184	bne    v0, zero, loopc50c0 [$800c50c0]

return T7;
////////////////////////////////



////////////////////////////////
// field_walkmesh_check_collide_with_triangle_unaccessable
// A3 = SP + 28;
// return 0 if we collided and 1 if we not

is_collided = 0;

entity_struct = A0;
current_pos = A1;
walkmesh_triangle_data = A2;
FP = A3;

// store world position
[SP + 20] = h(hu[w[800c9df8] + 8] + hu[w[800c9e0c] + h[walkmesh_triangle_data + 4] * 20 + a]);
[SP + 22] = h(hu[w[800c9df8] + a] + hu[w[800c9e0c] + h[walkmesh_triangle_data + 4] * 20 + c]);
[SP + 24] = h(hu[w[800c9df8] + c] + hu[w[800c9e0c] + h[walkmesh_triangle_data + 4] * 20 + e]);

// store vertexes in world coords
S3 = 0;
loopc25b8:	; 800C25B8
    V0 = w[800c9dfc] + h[walkmesh_triangle_data + c + S3 * 2] * 6;
    [SP + 28 + S3 * 6 + 0] = h(hu[SP + 20] + hu[V0 + 0]);
    [SP + 28 + S3 * 6 + 2] = h(hu[SP + 22] + hu[V0 + 2]);
    [SP + 28 + S3 * 6 + 4] = h(hu[SP + 24] + hu[V0 + 4]);

    S3 = S3 + 1;
    V1 = S3 < 3;
800C2658	bne    v1, zero, loopc25b8 [$800c25b8]




S3 = 0;
[SP + 18] = w(SP + 34);
[SP + 54] = w(SP + 28);

Lc267c:	; 800C267C
    [SP + 1c] = w(w[SP + 54] + S3 * 6); // stored vertexes

    A0 = current_pos;
    A1 = w[SP + 18]; // stored vertexes C
    A2 = w[SP + 54] + S3 * 6; // stored vertexes A
    A3 = SP + 20;  // address for point on line
    [SP + 10] = w(SP + 50); // address to store is this perpendecular line or not
    field_calculate_square_distance_point_to_line;

    distance = V0; // return squared length of distance to side of triangle

    if (distance <= w[entity_struct + 20]) // collision check
    {
        A0 = entity_struct;
        A1 = walkmesh_triangle_data;
        A2 = S3; // current side
        field_get_next_walkmesh_triangle_address;

        next_triangle_data = V0;
        if (next_triangle_data != 0)
        {
            V1 = hu[next_triangle_data + 0];
            if ((V1 & 0080) == 0)
            {
                [next_triangle_data + 0] = h(V1 | 0080);

                A0 = entity_struct;
                A1 = current_pos;
                A2 = next_triangle_data;
                A3 = FP;
                field_walkmesh_check_collide_with_triangle_unaccessable;

                if (V0 == 0)
                {
                    [FP] = h(S3);
                    is_collided = 1;
                }
            }
        }
        else // if we cant go to next triangle
        {
            is_collided = 1;

            if (distance != 0)
            {
                A0 = distance;
                system_square_root;

                distance = (V0 << 10) >> 10;

                // if point on line X == pos X
                if (h[SP + 20] == h[current_pos + 0])
                {
                    [SP + 40] = w(0);
                }
                else
                {
                    [SP + 40] = w(((((h[current_pos + 0] - h[SP + 20]) * w[entity_struct + 1c]) / distance) << 10) >> 10);
                }

                // if point on line Z == pos Z
                if (h[SP + 24] == h[current_pos + 4])
                {
                    [SP + 48] = w(0);
                }
                else
                {
                    [SP + 48] = w(((((h[current_pos + 4] - h[SP + 24]) * w[entity_struct + 1c]) / distance) << 10) >> 10);
                }



                A2 = h[800c9ddc];

                if ((A2 + 1) < 10)
                {
                    // calculate vector we need apply to our  position so we don't collide with side.
                    [SP + 40] = w(w[SP + 40] + h[SP + 20] - h[current_pos + 0]);
                    [SP + 48] = w(w[SP + 48] + h[SP + 24] - h[current_pos + 4]);

                    [800ca9d8 + A2 * 6 + 0] = h(hu[SP + 40]);
                    [800ca9d8 + A2 * 6 + 4] = h(hu[SP + 48]);
                    [800caa38 + A2 * 2] = h(hu[SP + 50]);
                    [800caa58 + A2 * 4] = w(distance);

                    [800c9ddc] = h(hu[800c9ddc] + 1);
                }

                is_collided = 1;
                [walkmesh_triangle_data + 0] = h(hu[walkmesh_triangle_data + 0] | 0080);
                [FP] = h(S3);
            }
        }
    }

    [SP + 18] = w(w[SP + 1c]);

    S3 = S3 + 1;
    V0 = S3 < 3;
800C28E4	bne    v0, zero, Lc267c [$800c267c]



return (is_collided != 1);
////////////////////////////////



////////////////////////////////
// field_calculate_square_distance_point_to_line
//    A0 - our position
//    A1 - stored vertexes C
//    A2 - stored vertexes A
//    A3 - address for point on line
//    [SP + 10] - store here is this is shortest path or short path is not perpendecular

Xpos = h[A0 + 0]; Ypos = h[A0 + 2]; Zpos = h[A0 + 4];
XC   = h[A1 + 0]; YC   = h[A1 + 2]; ZC   = h[A1 + 4];
XA   = h[A2 + 0]; YA   = h[A2 + 2]; ZA   = h[A2 + 4];

cos_angle_CP_CA = (Xpos - XC) * (XA - XC) + (Ypos - YC) * (YA - YC) + (Zpos - ZC) * (ZA - ZC);
if (cos_angle_CP_CA <= 0)
{
    Xtemp = h(XC);
    Ytemp = h(YC);
    Ztemp = h(ZC);

    if (cos_angle_CP_CA == 0) // if lines are perpendecular
    {
        [w[SP + 10]] = h(1);
    }
    else
    {
        [w[SP + 10]] = h(0);
    }
}
else
{
    cos_angle_AP_AC = (Xpos - XA) * (XC - XA) + (Ypos - YA) * (YC - YA) + (Zpos - ZA) * (ZC - ZA);
    if (cos_angle_AP_AC <= 0)
    {
        Xtemp = h(XA);
        Ytemp = h(YA);
        Ztemp = h(ZA);

        if (cos_angle_AP_AC == 0) // if lines are perpendecular
        {
            [w[SP + 10]] = h(1);
        }
        else
        {
            [w[SP + 10]] = h(0);
        }
    }
    else
    {
        // find projection on line
        Xtemp = h(XC + ((XA - XC) * cos_angle_CP_CA) / (cos_angle_CP_CA + cos_angle_AP_AC));
        Ytemp = h(YC + ((YA - YC) * cos_angle_CP_CA) / (cos_angle_CP_CA + cos_angle_AP_AC));
        Ztemp = h(ZC + ((ZA - ZC) * cos_angle_CP_CA) / (cos_angle_CP_CA + cos_angle_AP_AC));

        [w[SP + 10]] = h(1);
    }
}

[A3 + 0] = h(Xtemp);
[A3 + 2] = h(Ytemp);
[A3 + 4] = h(Ztemp);

return (Xtemp - Xpos) * (Xtemp - Xpos) + (Ytemp - Ypos) * (Ytemp - Ypos) + (Ztemp - Zpos) * (Ztemp - Zpos);
////////////////////////////////



////////////////////////////////
// field_get_next_walkmesh_triangle_address
// A0 - entity_struct;
// A1 - walkmesh_triangle_data;
// A2 - current side
// return address of next triangle or 0 if we cant pass this side

V1 = h[A1 + 18 + A2 * 2];
if (V1 == -1)
{
    return 0;
}

S2 = A0;
walkmesh_triangles_data = w[800c9e00];
S0 = walkmesh_triangles_data + V1 * 28;
A0 = hu[S0];
if ((A0 & 0001) == 0)
{
    return 0;
}

V0 = bu[800c9df1] & (A0 >> 8);
S1 = V0;
if ((V0 & c0) == 0)
{
    return S0;
}

V1 = w[8006794c];
A0 = bu[V1 + 8];
if (A0 == 5)
{
    A0 = w[V1 + 1c];
    V0 = w[A0 + 8e4];
    V0 = w[A0 + 8e0] + b[V0 + 8] * 14;
    V1 = w[V0 + c];
}
else if (A0 == 1)
{
    func4ae00;
    V1 = V0;
}
else
{
    V1 == 0;
}

V0 = w[S2 + 24];
if ((V0 == V1 && S1 & 80) || (V0 != V1 && S1 & 40))
{
    return 0;
}
else
{
    return S0;
}
////////////////////////////////



////////////////////////////////
// funcc31f8
// A0 - entity struct pointer
// A1 - our position
// A2 - address where we store current triangle data pointer
// A3 - address of side of triangle which we can't pass
// if we return !0 when we can move away from sides

T7 = A0;
A3 = A1;
A1 = A2;

number_of_collisions = h[800c9ddc]
if (number_of_collisions == 0)
{
    return 1;
}

[SP + 30] = h(hu[A3 + 0]);
[SP + 32] = h(hu[A3 + 2]);
[SP + 34] = h(hu[A3 + 4]);



if (number_of_collisions == 1)
{
    // set new position so we don't collide with side of triangle.
    [A3 + 0] = h(hu[A3 + 0] + hu[800ca9d8 + 0]);
    [A3 + 4] = h(hu[A3 + 4] + hu[800ca9d8 + 4]);
}
else
{
    T6 = 0;
    T4 = 0;

    [SP + 20] = w(0);
    [SP + 28] = w(0);

    if (number_of_collisions > 0)
    {
        T2 = 0;
        loopc32a0:	; 800C32A0
            if (h[800caa38 + T2 * 2] != 0) // if perpendecular
            {
                // search if this vector already exist
                T3 = 0;
                if (T2 != 0)
                {
                    T1 = 0;
                    loopc32c4:	; 800C32C4
                        if ((h[800ca9d8 + T1 * 6 + 0] == h[800ca9d8 + T2 * 6 + 0]) && (h[800ca9d8 + T1 * 6 + 4] == h[800ca9d8 + T2 * 6 + 4]))
                        {
                            T3 = 1;
                        }

                        T1 = T1 + 1;
                        V0 = T1 < T2;
                    800C3320	bne    v0, zero, loopc32c4 [$800c32c4]
                }

                // if this is new vector
                if (T3 == 0)
                {
                    [SP + 20] = w(w[SP + 20] + h[800ca9d8 + T2 * 6 + 0]);
                    [SP + 28] = w(w[SP + 28] + h[800ca9d8 + T2 * 6 + 4]);

                    T6 = 1;
                    T4 = T4 + 1;
                }
            }
            T2 = T2 + 1;
            V0 = T2 < number_of_collisions;
        800C3380	bne    v0, zero, loopc32a0 [$800c32a0]
    }

    if (T6 != 0)
    {
        if (T4 >= 2)
        {
            [SP + 20] = w(w[SP + 20] / T4);
            [SP + 28] = w(w[SP + 28] / T4);
        }
    }
    else
    {
        if (number_of_collisions > 0)
        {
            T4 = 0;
            T2 = 0;
            loopc3438:	; 800C3438
                T3 = 0;
                if (T2 > 0)
                {
                    T1 = 0;
                    loopc344c:	; 800C344C
                        if ((h[800ca9d8 + T1 * 6 + 0] == h[800ca9d8 + T2 * 6 + 0]) && (h[800ca9d8 + T1 * 6 + 4] == h[800ca9d8 + T2 * 6 + 4]))
                        {
                            T3 = 1;
                        }

                        T1 = T1 + 1;
                        V0 = T1 < T2;
                    800C34A8	bne    v0, zero, loopc344c [$800c344c]
                }

                if (T3 == 0)
                {
                    [SP + 20] = w(w[SP + 20] + h[800ca9d8 + T2 * 6 + 0]);
                    [SP + 28] = w(w[SP + 28] + h[800ca9d8 + T2 * 6 + 4]);
                    T4 = T4 + 1;
                }

                T2 = T2 + 1;
                V0 = T2 < number_of_collisions;
            800C3508	bne    v0, zero, loopc3438 [$800c3438]
        }

        if (T4 > 0)
        {
            [SP + 20] = w(w[SP + 20] / T4);
            [SP + 24] = w(w[SP + 24] / T4);
        }
    }

    [A3 + 0] = h(hu[A3 + 0] + hu[SP + 20]);
    [A3 + 4] = h(hu[A3 + 4] + hu[SP + 28]);
}

[800c9ddc] = h(0);

V1 = w[T7 + 24];
[V1 + 14] = w(h[A3 + 0]);
[V1 + 1c] = w(h[A3 + 4]);

A0 = T7;
A1 = A1; // address of current triangle data pointer
A2 = SP + 30;
[SP + 10] = w(0);
[SP + 14] = w(0);
[SP + 18] = w(0);
[SP + 1c] = w(0);
funcc2af0;

return V0 < 1;
////////////////////////////////