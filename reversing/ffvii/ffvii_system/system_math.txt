////////////////////////////////
// system_normalize_vector_A0_to_A1
t0 = [a0 + 0];
t1 = [a0 + 4];
t2 = [a0 + 8];

system_normalize_vector_T0_T1_T2;

[a1 + 0] = t0;
[a1 + 4] = t1;
[a1 + 8] = t2;
////////////////////////////////



////////////////////////////////
// system_transponate_matrix
[A1 + 0] = h(h[A0 + 0]); [A1 + 2] = h(h[A0 + 6]); [A1 + 4] = h(h[A0 + c]);
[A1 + 6] = h(h[A0 + 2]); [A1 + 8] = h(h[A0 + 8]); [A1 + a] = h(h[A0 + e]);
[A1 + c] = h(h[A0 + 4]); [A1 + e] = h(h[A0 + a]); [A1 + 10] = h(h[A0 + 10]);
return A1;
////////////////////////////////



////////////////////////////////
// system_scale_matrix_by_vector
R11 = ((w[A0 + 0] & ffff) << 10) >> 10;
R12 = (w[A0 + 0] >> 10);
R13 = ((w[A0 + 4] & ffff) << 10) >> 10;
R21 = (w[A0 + 4] >> 10);
R22 = ((w[A0 + 8] & ffff) << 10) >> 10;
R23 = (w[A0 + 8] >> 10);
R31 = ((w[A0 + c] & ffff) << 10) >> 10;
R32 = (w[A0 + c] >> 10);
R33 = ((w[A0 + 10] & ffff) << 10) >> 10;

vector1 = w[A1 + 0];
vector2 = w[A1 + 4];
vector3 = w[A1 + 8];

[A0 + 0] = w((((R11 * vector1) >> c) & ffff) | (((R12 * vector2) >> c) << 10));
[A0 + 4] = w((((R13 * vector3) >> c) & ffff) | (((R21 * vector1) >> c) << 10));
[A0 + 8] = w((((R22 * vector2) >> c) & ffff) | (((R23 * vector3) >> c) << 10));
[A0 + c] = w((((R31 * vector1) >> c) & ffff) | (((R32 * vector2) >> c) << 10));
[A0 + 10] = w((R33 * vector3) >> c);

return A0;
////////////////////////////////



////////////////////////////////
// system_copy_vector_to_matrix_translation
[A0 + 14] = w(w[A1 + 0]);
[A0 + 18] = w(w[A1 + 4]);
[A0 + 1c] = w(w[A1 + 8]);
return A0;
////////////////////////////////



////////////////////////////////
// system_create_rotation_matrix_from_euler_angle
// create rotation matrix in A1 from XYZ rotation (A0 + 0 + 2 + 4)
//                A0 = 800f8158 + 34 + 20;
//                S0 = 800f8158 + 34;
//                A1 = S0;
T7 = h[A0 + 0];
if (T7 < 0)
{
    T7 = -T7;
    T7 = T7 & 0fff;
    T9 = w[8004bc98 + T7 * 4];
    T6 = (T9 << 10) >> 10; // sin
    T3 = -T6;
}
else
{
    T7 = T7 & 0fff;
    T9 = w[8004bc98 + T7 * 4];
    T3 = (T9 << 10) >> 10;
    T6 = -T3;
}
cosX = T9 >> 10;



T7 = h[A0 + 2];
if (T7 < 0)
{
    T7 = -T7;
    T7 = T7 & 0fff;
    T9 = w[8004bc98 + T7 * 4];
    T4 = -((T9 << 10) >> 10);
}
else
{
    T7 = T7 & 0fff;
    T9 = w[8004bc98 + T7 * 4];
    T4 = (T9 << 10) >> 10;
}
cosY = T9 >> 10;



T7 = h[A0 + 4];
if (T7 < 0)
{
    T7 = -T7;
    T7 = T7 & 0fff;
    T9 = w[8004bc98 + T7 * 4];
    T5 = -((T9 << 10) >> 10);
}
else
{
    T7 = T7 & 0fff;
    T9 = w[8004bc98 + T7 * 4];
    T5 = (T9 << 10) >> 10;
}
cosZ = T9 >> 10;



[A1 + 0] = h(((cosY * cosZ) >> c) + ((((T4 * T3) >> c) * T5) >> c));
[A1 + 2] = h(((((T4 * T3) >> c) * cosZ) >> c) -((cosY * T5) >> c));
[A1 + 4] = h((T4 * cosX) >> c);
[A1 + 6] = h((T5 * cosX) >> c);
[A1 + 8] = h((cosZ * cosX) >> c);
[A1 + a] = h(T6);
[A1 + c] = h(((((cosY * T3) >> c) * T5) >> c) -((T4 * cosZ) >> c));
[A1 + e] = h(((T4 * T5) >> c) + ((((cosY * T3) >> c) * cosZ) >> c));
[A1 + 10] = h((cosY * cosX) >> c);

return A1;
////////////////////////////////



////////////////////////////////
// add_sub_with_max_min_bound
cur = A0;
dam = A1;
max = A2;

if (A3 != 0)
{
    if (cur + dam < cur)
    {
        A0 = max;
    }

    if (cur + dam > dam)
    {
        A0 = max;
    }
}
else
{
    if (cur - dam > cur)
    {
        A0 = 0;
    }
}

return A0;
////////////////////////////////



////////////////////////////////
// count_active_bits
V1 = 0;
if (A0 != 0)
{
    loop14a60:	; 80014A60
        if (A0 & 1)
        {
            V1 = V1 + 1;
        }

        A0 = A0 >> 1;
    80014A74	bne    a0, zero, loop14a60 [$80014a60]
}

return V1;
////////////////////////////////



////////////////////////////////
// select_random_bit
S2 = A0;
S1 = 0;
count_active_bits;
S0 = V0;

if (S0 != 0)
{
    S1 = 1;

    get_random_byte_from_table;

    V1 = V0 * S0;
    S0 = V1 >> 8;
    V0 = S2 & S1;

    loop14ac8:	; 80014AC8
        if (V0 != 0)
        {
            S0 = S0 - 1;

            if (S0 < 0)
            {
                return;
            }
        }

        S1 = S1 << 1;
        V0 = S2 & S1;
    80014AE0	bne    s1, zero, loop14ac8 [$80014ac8]
}

return S1;
////////////////////////////////



////////////////////////////////
// get_last_significant_bit_number
V0 = 0;

A0 = A0 >> 1;

L14a3c:	; 80014A3C
A0 = A0 >> 1;
if (A0 != 0)
{
    V0 = V0 + 1;
    80014A48	j      L14a3c [$80014a3c]
}

return V0;
////////////////////////////////



////////////////////////////////
// increment_seed_for_random
V0 = w[GP + D4];
V0 = V0 + 1;
V0 = V0 & 7;
[GP + D4] = w(V0);
////////////////////////////////



////////////////////////////////
// get_random_byte_from_table
V1 = w[GP + D4];
V0 = bu[80062E10 + V1];
A0 = V0 + 1;
[80062E10 + V1] = b(A0);

V0 = bu[80083084 + V0];
return V0;
////////////////////////////////



////////////////////////////////
// system_random_two_bytes
get_random_byte_from_table;
S0 = V0;

V1 = w[GP + 8];
A0 = V1 + 1;
V1 = V1 & 7;
[GP + 8] = w(A0);

if (V1 != 0)
{
    increment_seed_for_random;
}

get_random_byte_from_table;
V0 = V0 & ff;
V0 = V0 << 8;
V1 = S0 & ff;
return V1 | V0;
////////////////////////////////



////////////////////////////////
// system_get_sin
if (A0 >= 0)
{
    A0 = A0 & 0fff;
    func39ab0;
    return V0;
}
else
{
    A0 = 0 - A0;
    A0 = 0 - A0;
    func39ab0;
    return -V0;
}
////////////////////////////////



////////////////////////////////
// func39ab0
if (A0 >= 801)
{
    if (A0 < c01)
    {
        return -h[80049e54 + A0 * 2];
    }
    else
    {
        return -h[8004ae54 + (1000 - A0) * 2];
    }
}
else if (A0 >= 401)
{
    return h[8004ae54 + (800 - A0) * 2];
}
else
{
    return h[8004ae54 + A0 * 2];
}
////////////////////////////////
