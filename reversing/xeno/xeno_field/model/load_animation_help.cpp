////////////////////////////////
// func1e6d94
model_data = A0;
given_bone_address = A1;
S3 = A2;
[given_bone_address + 7] = b(S3 & 01);

if( S3 & 80 )
{
    bone_struct = w[model_data + 4];

    S1 = 1;
    if( S1 < hu[bone_struct + a] )
    {
        loop1e6de8:	; 801E6DE8
            if( w[bone_struct + S1 * 7c + 0] == given_bone_address )
            {
                A0 = model_data;
                A1 = bone_struct + S1 * 7c;
                A2 = S3;
                func1e6d94;
            }

            S1 = S1 + 1;
            V0 = S1 < hu[bone_struct + a];
        801E6E1C	bne    v0, zero, loop1e6de8 [$801e6de8]
    }
}
////////////////////////////////



////////////////////////////////
// func1def10
// read initial bone rotation
// A0 - pointer to bone struct 0x7c
// A1 - pointer to animation file animation_0_0_0 - animation_0_0_X

bone_struct = A0;
init_file = A1;

max_rot_num = hu[init_file + c];
max_trans_num = hu[init_file + e];

rot_flag   = hu[init_file + 4] & 1;
trans_flag = hu[init_file + 4] & 2;

if( h[init_file + 6] == 0 )
{
    init_file = init_file + (max_rot_num + 1) * 6;
}

init_file = init_file + 18;

number_of_bone = hu[bone_struct + a];
if( number_of_bone > 0 )
{
    bone_id = 1;
    rot_num = 0;
    trans_num = 0;

    loop1def74:	; 801DEF74
        if( ( rot_flag == 0 ) && ( rot_num < max_rot_num ) )
        {
            rot_x = h[init_file + 0];
            rot_y = h[init_file + 2];
            rot_z = h[init_file + 4];
            init_file = init_file + 6;
            rot_num = rot_num + 1;

            V0 = w[bone_struct + bone_id * 7c + 70];
            if( ( h[bone_struct + bone_id * 7c + 54] != rot_x ||
                  h[bone_struct + bone_id * 7c + 56] != rot_y ||
                  h[bone_struct + bone_id * 7c + 58] != rot_z ) &&
                ( V0 == 0 || bu[V0 + 3] != ff ) )
            {
                [bone_struct + bone_id * 7c + 4] = b(1);
                [bone_struct + bone_id * 7c + 5] = b(1);
                [bone_struct + bone_id * 7c + 54] = h(rot_x);
                [bone_struct + bone_id * 7c + 56] = h(rot_y);
                [bone_struct + bone_id * 7c + 58] = h(rot_z);
            }
        }

        if( ( trans_flag == 0 ) && ( trans_num < max_trans_num ) )
        {
            trans_x = h[init_file + 0];
            trans_y = h[init_file + 2];
            trans_z = h[init_file + 4];
            init_file = init_file + 6;
            trans_num = trans_num + 1;

            V0 = w[bone_struct + bone_id * 7c + 74];
            if( ( h[bone_struct + bone_id * 7c + 5c] != trans_x ||
                  h[bone_struct + bone_id * 7c + 60] != trans_y ||
                  h[bone_struct + bone_id * 7c + 64] != trans_z ) &&
                ( V0 == 0 || bu[V0 + 3] != ff ) )
            {
                [bone_struct + bone_id * 7c + 4] = b(1);
                [bone_struct + bone_id * 7c + 5c] = w(trans_x);
                [bone_struct + bone_id * 7c + 60] = w(trans_y);
                [bone_struct + bone_id * 7c + 64] = w(trans_z);
            }
        }

        bone_id = bone_id + 1;
        V0 = bone_id < number_of_bone;
    801DF0A0	bne    v0, zero, loop1def74 [$801def74]
}
////////////////////////////////



////////////////////////////////
// func1df0b4
// A1 - pointer to bone struct 0x7c
// A2 - pointer to skeleton animation file animation_0_0_0 - animation_0_0_X
// A3 - arg4
// A4 - arg0
// A5 - arg3
// A6 - arg2

bone_struct = A1;
init_file = A2;

max_rot_num = hu[init_file + c];
max_trans_num = hu[init_file + e];

S5 = A4;
S7 = A0;
[SP + 10] = w(A3);
if( A3 == 0 )
{
    [SP + 10] = w(1);
}

A5 = A5 & 1;

S5 = S5 & 1;

rot_flag   = hu[init_file + 4] & 1;
trans_flag = hu[init_file + 4] & 2;


if (h[init_file + 6] == 0)
{
    init_file = init_file + (max_rot_num + 1) * 6;
}

init_file = init_file + 18;

number_of_bone = hu[bone_struct + a];
if( number_of_bone > 0 )
{
    bone_id = 1;
    rot_num = 0;
    trans_num = 0;

    L1df17c:	; 801DF17C
        if( ( rot_flag == 0 ) && ( rot_num < max_rot_num ) )
        {
            rot_x = h[init_file + 0];
            rot_y = h[init_file + 2];
            rot_z = h[init_file + 4];
            init_file = init_file + 6;
            rot_num = rot_num + 1;

            if( ( h[bone_struct + bone_id * 7c + 54] != rot_x ) ||
                ( h[bone_struct + bone_id * 7c + 56] != rot_y ) ||
                ( h[bone_struct + bone_id * 7c + 58] != rot_z ) )
            {
                A0 = w[bone_struct + bone_id * 7c + 70];
                if( ( A0 != 0 ) && ( bu[A0 + 3] == ff ) )
                {
                    801DF4AC	j      L1df364 [$801DF364]
                }

                A0 = S7;
                func1df6f0;

                A0 = V0;
                if( A0 != 0 )
                {
                    [A0 + 0] = b(1);
                    [A0 + 1] = b(A5);
                    [A0 + 2] = b(S5 + 3);
                    [A0 + 3] = b(A6);
                    [A0 + 4] = h(hu[bone_struct + bone_id * 7c + 54]);
                    [A0 + 6] = h(hu[bone_struct + bone_id * 7c + 56]);
                    [A0 + 8] = h(hu[bone_struct + bone_id * 7c + 58]);

                    rot_x = (rot_x - h[bone_struct + bone_id * 7c + 54]) & fff;
                    if( rot_x >= 800 )
                    {
                        rot_x = rot_x - 1000;
                    }
                    [A0 + a] = h(rot_x);

                    rot_y = (rot_y - h[bone_struct + bone_id * 7c + 56]) & fff;
                    if( rot_y >= 0 )
                    {
                        rot_y = rot_y - 1000;
                    }
                    [A0 + c] = h(rot_y);

                    rot_z = (rot_z - h[bone_struct + bone_id * 7c + 58]) & fff;
                    if( rot_z >= 800 )
                    {
                        rot_z = rot_z - 1000;
                    }
                    [A0 + e] = h(rot_z);

                    if( S5 != 0 )
                    {
                        [A0 + a] = h(hu[A0 + a] + hu[bone_struct + bone_id * 7c + 54])
                        [A0 + c] = h(hu[A0 + c] + hu[bone_struct + bone_id * 7c + 56])
                        [A0 + e] = h(hu[A0 + e] + hu[bone_struct + bone_id * 7c + 58])
                    }
                    [A0 + 10] = h(0);
                    [A0 + 12] = h(hu[SP + 10]);

                    [bone_struct + bone_id * 7c + 70] = w(A0);
                    801DF4AC	j      L1df364 [$801DF364]
                }
            }
        }

        A1 = w[bone_struct + bone_id * 7c + 70];
        if( ( A1 != 0 ) && ( bu[A1 + 3] != ff ) )
        {
            A0 = S7;
            func1df7a8;

            [bone_struct + bone_id * 7c + 70] = w(0);
        }

        L1df364:	; 801DF364
        if( ( trans_flag == 0 ) && ( trans_num < max_trans_num ) )
        {
            trans_x = h[init_file + 0];
            trans_y = h[init_file + 2];
            trans_z = h[init_file + 4];
            init_file = init_file + 6;
            trans_num = trans_num + 1;

            if( ( w[bone_struct + bone_id * 7c + 5c] != trans_x ) ||
                ( w[bone_struct + bone_id * 7c + 60] != trans_y ) ||
                ( w[bone_struct + bone_id * 7c + 64] != trans_z ) )
            {
                A0 = w[bone_struct + bone_id * 7c + 74];
                if( ( V0 != 0 ) && ( bu[A0 + 3] == ff ) )
                {
                    801DF4AC	j      L1df4e0 [$801df4e0]
                }

                A0 = S7;
                func1df6f0;

                A0 = V0;
                if( A0 != 0 )
                {
                    [A0 + 0] = b(1);
                    [A0 + 1] = b(A5);
                    [A0 + 2] = b(S5 + 3);
                    [A0 + 3] = b(A6);
                    [A0 + 4] = h(hu[bone_struct + bone_id * 7c + 5c]);
                    [A0 + 6] = h(hu[bone_struct + bone_id * 7c + 60]);
                    [A0 + 8] = h(hu[bone_struct + bone_id * 7c + 64]);

                    if( S5 != 0 )
                    {
                        [A0 + a] = h(trans_x);
                        [A0 + c] = h(trans_y);
                        [A0 + e] = h(trans_z);
                    }
                    else
                    {
                        [A0 + a] = h(trans_x - hu[bone_struct + bone_id * 7c + 5c]);
                        [A0 + c] = h(trans_y - hu[bone_struct + bone_id * 7c + 60]);
                        [A0 + e] = h(trans_z - hu[bone_struct + bone_id * 7c + 64]);
                    }

                    [A0 + 10] = h(0);
                    [A0 + 12] = h(hu[SP + 10]);
                    [bone_struct + bone_id * 7c + 74] = w(A0);
                    801DF4AC	j      L1df4e0 [$801df4e0]
                }
            }
        }

        A1 = w[bone_struct + bone_id * 7c + 74];
        if( ( A1 != 0 ) && ( bu[A1 + 3] != ff ) )
        {
            A0 = S7;
            func1df7a8;

            [bone_struct + bone_id * 7c + 74] = w(0);
        }

        L1df4e0:	; 801DF4E0
        bone_id = bone_id + 1;
        V0 = bone_id < number_of_bone;
    801DF4EC	bne    v0, zero, L1df17c [$801df17c]
}
////////////////////////////////



////////////////////////////////
// func1e6910
// get pointer to animation file 2202_0_0_0 - 2202_0_0_X
param = A1 & ff;
[A2 + 0] = w(0);
if (param >= fe)
{
    V0 = bu[A0 + 2a];
    param = V0 & 7f;
    [A2] = w(V0 & 80);
}

param = param & ff;
if (param >= 40)
{
    V1 = w[A0 + 18];
    V0 = w[V1 - fc + param * 4];
}
else
{
    V1 = w[A0 + 14];
    V0 = w[V1 + 4 + param * 4];
}
////////////////////////////////



////////////////////////////////
// func1e632c
[A0 + 98] = h(-1);
////////////////////////////////



////////////////////////////////
// func1dfe8c
S2 = A0;
bone_struct = A1;
number_of_bones = hu[bone_struct + a];

if( number_of_bones != 0 )
{
    S1 = 0;
    loop1dfec4:	; 801DFEC4
        A1 = w[bone_struct + S1 * 7c + 70];
        if( A1 != 0 && b[A1 + 3] != -1 )
        {
            A0 = S2;
            func1df7a8;
            [bone_struct + S1 * 7c + 70] = w(0);
        }

        A1 = w[bone_struct + S1 * 7c + 74];
        if( A1 != 0 && b[A1 + 3] != -1 )
        {
            A0 = S2;
            func1df7a8;
            [bone_struct + S1 * 7c + 74] = w(0);
        }

        A1 = w[bone_struct + S1 * 7c + 78];
        if( A1 != 0 && b[A1 + 3] != -1 )
        {
            A0 = S2;
            func1df7a8;
            [bone_struct + S1 * 7c + 70] = w(0);
        }

        S1 = S1 + 1;
        V0 = S1 < number_of_bones;
    801DFF4C	bne    v0, zero, loop1dfec4 [$801dfec4]
}
////////////////////////////////



////////////////////////////////
// func1df52c
//            A0 = w[SP + c8]; // 801e86a8

S2 = A0;
bone_struct = A1;
bone_id = A2;
flags = A3;

if( bone_id < hu[bone_struct + a] )
{
    bone_pointer = bone_struct + bone_id * 7c;
    A1 = w[bone_pointer + 70];
    if( A1 != 0 && flags & 1 )
    {
        A0 = S2;
        func1df7a8;
        [bone_pointer + 70] = w(0);
    }

    A1 = w[bone_pointer + 74];
    if( A1 != 0 && flags & 2 )
    {
        A0 = S2;
        func1df7a8;
        [bone_pointer + 74] = w(0);
    }

    A1 = w[bone_pointer + 78];
    if( A1 != 0 && flags & 4 )
    {
        A0 = S2;
        func1df7a8;
        [bone_pointer + 78] = w(0);
    }
}
////////////////////////////////



////////////////////////////////
// func1df7a8
if( A1 == 0 )
{
    return -1;
}

V1 = (A1 - w[A0 + 0]) / 14;

if( V1 < hu[A0 + 4] )
{
    [A0 + 4] = h(V1);
}

[A1 + 0] = b(0);

return V1;
////////////////////////////////



////////////////////////////////
// func1df6f0
if( hu[A0 + 4] >= hu[A0 + 6] )
{
    return 0;
}

A3 = w[A0 + 0] + hu[A0 + 4] * 14;

if( bu[A3 + 0] != 0 )
{
    return 0;
}

[A0 + 4] = h(hu[A0 + 4] + 1);

if( hu[A0 + 4] < hu[A0 + 6] )
{
    loop1df754:	; 801DF754
        A2 = w[A0 + 0] + hu[A0 + 4] * 14;
        if( bu[A2 + 0] == 0 )
        {
            break;
        }

        [A0 + 4] = h(hu[A0 + 4] + 1);
        V0 = hu[A0 + 4] < hu[A0 + 6];
    801DF78C	bne    v0, zero, loop1df754 [$801df754]
}
return A3;
////////////////////////////////