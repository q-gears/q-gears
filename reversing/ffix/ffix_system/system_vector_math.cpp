////////////////////////////////
// system_fully_calulated_square_root
T1 = 0;
T2 = 1e;

loop52ef8:	; 80052EF8
    V1 = (T1 + 1) << T2;
    T1 = T1 << 1;
    if (A0 >= V1)
    {
        A0 = A0 - V1;
        T1 = T1 | 4;
    }

    T2 = T2 - 2;
80052F14	bgez   t2, loop52ef8 [$80052ef8]

return T1 >> 2;
////////////////////////////////



////////////////////////////////
// system_square_root
LZCS = A0;
V0 = LZCR;

if (V0 == 20)
{
    return 0;
}

T0 = V0 & 1;

T2 = V0 & fffffffe;

T1 = 1f - T2;

T1 = T1 >> 1;
T3 = T2 - 18;

if (T3 < 0)
{
    T3 = 18 - T2
}

T4 = A0 << T3;
T4 = T4 & ffc0;

return (h[8006bd34 + T4 * 2] << T1) >> c
////////////////////////////////



////////////////////////////////
// system_get_rotation_by_vector_x_y
if (A0 | A1)
{
    if (A1 < 0)
    {
        if (A0 < 0)
        {
            if (A0 < A1)
            {
                A0 = (A1 / A0) * 400;
                V0 = 400 - hu[8006ead0 + A0 * 2];
            }
            else
            {
                A0 = (A0 / A1) * 400;
                V0 = hu[8006ead0 + A0 * 2];
            }
        }
        else
        {
            if (A0 < -A1)
            {
                A0 = (A0 / A1) * 400;
                V0 = - hu[8006ead0 + A0 * 2];
            }
            else
            {
                A0 = (A1 / A0) * 400;
                V0 = - 400 - hu[8006ead0 + A0 * 2];
            }
        }
    }
    else
    {
        if (A0 >= 0)
        {
            if (A0 >= A1)
            {
                A0 = (A1 / A0) * 400;
                V0 = - 400 - hu[8006ead0 + A0 * 2];
            }
            else
            {
                A0 = (A0 / A1) * 400;
                V0 = hu[8006ead0 + A0 * 2] - 800;
            }
        }
        else
        {
            if (-A0 < A1)
            {
                A0 = (A0 / A1) * 400;
                V0 = 800 - hu[8006ead0 + A0 * 2];
            }
            else
            {
                A0 = (A1 / A0) * 400;
                V0 = 400 + hu[8006ead0 + A0 * 2];
            }
        }
    }
}
else
{
    V0 = 0;
}

return V0; // return rotation
////////////////////////////////



////////////////////////////////
// system_get_sin_by_rotation
V0 = (A0 >> a) & 3;
A0 = A0 & 3ff;

if (V0 == 1)
{
    return h[8006c1c4 + 800 - A0 * 2];
}
elseif (V0 == 2)
{
    return -h[8006c1c4 + A0 * 2];
}
elseif(V0 == 3)
{
    return -h[8006c1c4 + 800 - A0 * 2];
}
else
{
    return h[8006c1c4 + A0 * 2];
}
////////////////////////////////



////////////////////////////////
// system_rotate_vector_by_x_y_axis
if (A0 != 0)
{
    S0 = A0;

    [SP + 0] = h(A1);
    [SP + 2] = h(A2);
    [SP + 4] = w(0);

    A0 = SP + 0;
    A1 = SP + 8;
    system_create_matrix_from_angle_with_cpu;

    A0 = SP + 8;
    system_set_rotation_matrix_to_gpu;

    TRX = 0;
    TRY = 0;
    TRZ = 0;
    VXY0 = w[S0 + 0];
    VZ0 = w[S0 + 4];

    gte_rtv0tr; // v0 * rotmatrix + tr vector.

    [S0 + 0] = h(MAC1);
    [S0 + 2] = h(MAC2);
    [S0 + 4] = h(MAC3);
}
////////////////////////////////



////////////////////////////////
// system_create_matrix_from_angle_with_cpu
A2 = 0;
system_create_matrix_from_angle_two_type;
////////////////////////////////



////////////////////////////////
// system_create_matrix_from_angle_with_gte
A2 = 1;
system_create_matrix_from_angle_two_type;
////////////////////////////////



////////////////////////////////
// system_create_matrix_from_angle_two_type
T5 = A1;
T6 = A2;



rot_x = h[A0 + 0];
rot_y = h[A0 + 2];
rot_z = h[A0 + 4];



if (rot_x & 400)
{
    sin_x = h[8006c1c4 + (400 - (rot_x & 3ff)) * 2];
}
else
{
    sin_x = h[8006c1c4 + (rot_x & 3ff) * 2];
}
if (rot_x & 800)
{
    sin_x = -sin_x;
}

if ((400 - rot_x) & 400)
{
    cos_x = h[8006c1c4 + (400 - ((400 - rot_x) & 3ff)) * 2];
}
else
{
    cos_x = h[8006c1c4 + ((400 - rot_x) & 3ff) * 2];
}
If ((400 - rot_x) & 800)
{
    cos_x = -cos_x;
}



if (rot_y & 400)
{
    sin_y = h[8006c1c4 + (400 - (rot_y & 3ff)) * 2];
}
else
{
    sin_y = h[8006c1c4 + (rot_y & 3ff) * 2];
}
if (rot_y & 800)
{
    sin_y = -sin_y;
}

if ((400 - rot_y) & 400)
{
    cos_y = h[8006c1c4 + (400 - ((400 - rot_y) & 3ff)) * 2];
}
else
{
    cos_y = h[8006c1c4 + ((400 - rot_y) & 3ff) * 2];
}
if ((400 - rot_y) & 800)
{
    cos_y = -cos_y;
}



if (rot_z & 400)
{
    sin_z = h[8006c1c4 + (400 - (rot_z & 3ff)) * 2];
}
else
{
    sin_z = h[8006c1c4 + (rot_z & 3ff) * 2];
}
if (rot_z & 800)
{
    sin_z = -sin_z;
}

if ((400 - rot_z) & 400)
{
    cos_z = h[8006c1c4 + (400 - ((400 - rot_z) & 3ff)) * 2];
}
else
{
    cos_z = h[8006c1c4 + ((400 - rot_z) & 3ff) * 2];
}
if ((400 - rot_z) & 800)
{
    cos_z = -cos_z;
}



if (T6 == 0)
{
    [T5 + 0] = h((cos_y * cos_z) >> c);
    [T5 + 2] = h(-sin_z * cos_x + ((((sin_y * cos_z) << 4) >> 10) * sin_x) >> c);
    [T5 + 4] = h((sin_z * sin_x + cos_x * (((sin_y * cos_z) << 4) >> 10)) >> c);

    [T5 + 6] = h((sin_z * cos_y) >> c);
    [T5 + 8] = h((cos_z * cos_x + (((sin_y * sin_z) << 4) >> 10) * sin_x) >> c);
    [T5 + a] = h((-cos_z * sin_x + (((sin_y * sin_z) << 4) >> 10) * cos_x) >> c);

    [T5 + c] = h(-sin_y);
    [T5 + e] = h((cos_y * sin_x) >> c);
    [T5 + 10] = h((cos_y * cos_x) >> c);
}
else
{
    [T5 + c] = h(-sin_y); 

    IR0 = cos_y;
    IR1 = cos_z;
    IR2 = sin_z;
    IR3 = sin_x;
    gte_gpf12; // General purpose interpolation.
    [T5 + 0] = h(MAC1);
    [T5 + 6] = h(MAC2);
    [T5 + e] = h(MAC3);

    IR0 = cos_x;
    IR1 = cos_y;
    IR2 = sin_z;
    IR3 = cos_z;
    gte_gpf12; // General purpose interpolation.
    [T5 + 10] = h(MAC1);
    A1 = MAC2;
    V1 = MAC3;

    IR0 = sin_y;
    IR1 = (sin_x * cos_z) >> c;
    IR2 = (sin_z * sin_x) >> c;
    IR3 = V1;
    gte_gpf12; // General purpose interpolation.
    [T5 + 2] = h(MAC1 - A1);
    [T5 + 8] = h(MAC2 + V1);

    IR1 = V1;
    IR2 = A1;
    gte_gpf12; // General purpose interpolation.
    [T5 + 4] = h(MAC1 + ((sin_z * sin_x) >> c));
    [T5 + a] = h(MAC2 - ((sin_x * cos_z) >> c));
}
////////////////////////////////