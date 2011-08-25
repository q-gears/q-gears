////////////////////////////////
// func1def10
// A0 - pointer to bone struct 0x74
// A1 - pointer to animation file animation_0_0_0 - animation_0_0_X

max_rot_num = hu[A1 + c];
max_trans_num = hu[A1 + e];

A2 = hu[A1 + 4];

if (h[A1 + 6] == 0)
{
    A1 = A1 + (max_rot_num + 1) * 6;
}

A1 = A1 + 18;

T8 = A2 & 1;
T7 = A2 & 2;

number_of_bone = hu[A0 + a];
if (number_of_bone > 0)
{
    T0 = 1;
    rot_num = 0;
    trans_num = 0;
    loop1def74:	; 801DEF74
        if (T8 == 0 && rot_num < max_rot_num)
        {
            A3 = h[A1];
            A1 = A1 + 2;
            A2 = h[A1];
            A1 = A1 + 2;
            V1 = h[A1];
            A1 = A1 + 2;

            V0 = w[A0 + T0 * 7c + 70];
            if ((h[A0 + T0 * 7c + 54] != A3 || h[A0 + T0 * 7c + 56] != A2 || h[A0 + T0 * 7c + 58] != V1) && (V0 == 0 || bu[V0 + 3] != ff))
            {
                [A0 + T0 * 7c + 54] = h(A3);
                [A0 + T0 * 7c + 56] = h(A2);
                [A0 + T0 * 7c + 58] = h(V1);

                [A0 + T0 * 7c + 4] = b(1);
                [A0 + T0 * 7c + 5] = b(1);
            }

            rot_num = rot_num + 1;
        }

        if (T7 == 0 && trans_num < max_trans_num)
        {
            A3 = h[A1];
            A1 = A1 + 2;
            A2 = h[A1];
            A1 = A1 + 2;
            V1 = h[A1];
            A1 = A1 + 2;

            V0 = w[A0 + T0 * 7c + 74];
            if ((w[A0 + T0 * 7c + 5c] != A3 || h[A0 + T0 * 7c + 60] != A2 || h[A0 + T0 * 7c + 64] != V1) && (V0 == 0 || bu[V0 + 3] != ff))
            {
                [A0 + T0 * 7c + 5c] = w(A3);
                [A0 + T0 * 7c + 60] = w(A2);
                [A0 + T0 * 7c + 64] = w(V1);

                [A0 + T0 * 7c + 4] = b(1);
            }

            trans_num = trans_num + 1;
        }

        T0 = T0 + 1;
        V0 = T0 < number_of_bone;
    801DF0A0	bne    v0, zero, loop1def74 [$801def74]
}
////////////////////////////////



////////////////////////////////
// func1df0b4
// A1 - pointer to bone struct 0x74
// A2 - pointer to initial skeleton animation file animation_0_0_0 - animation_0_0_X
// A3 - arg4
// A4 - arg0
// A5 - arg3
// A6 - id of animation (arg2)

bone_struct = A1;
S5 = A4;
S7 = A0;
S1 = A2;
[SP + 10] = w(A3);
if (A3 == 0)
{
    [SP + 10] = w(1);
}

A5 = A5 & 1;

current_rotation = 0;
current_translation = 0;

max_rot_num = hu[S1 + c];
max_trans_num = hu[S1 + e];

S6 = h[S1 + 6];
S5 = S5 & 1;
T0 = hu[S1 + 4];
S1 = S1 + 18;

if (S6 == 0)
{
    S1 = S1 + (max_rot_num + 1) * 6;
}

number_of_bone = hu[bone_struct + a] - 1;

if( number_of_bone > 0 )
{
    S6 = 0;
    S0 = bone_struct + 7c;

    L1df17c:	; 801DF17C
        if( ( T0 & 1 ) == 0 )
        {
            if( current_rotation < max_rot_num )
            {
                S2 = h[S1];
                S1 = S1 + 2;
                S3 = h[S1];
                S1 = S1 + 2;
                S4 = h[S1];
                S1 = S1 + 2;

                current_rotation = current_rotation + 1;

                if( (h[S0 + 54] != S2 ) || ( h[S0 + 56] != S3 ) || ( h[S0 + 58] != S4 ) )
                {
                    A0 = w[S0 + 70];
                    if( ( A0 != 0 ) && ( bu[A0 + 3] == ff ) )
                    {
                        801DF4AC	j      L1df364 [$801DF364]
                    }

                    A0 = S7;
                    func1df6f0;

                    A0 = V0;
                    if (A0 != 0)
                    {
                        [A0 + 0] = b(1);
                        [A0 + 1] = b(A5);
                        [A0 + 2] = b(S5 + 3);
                        [A0 + 3] = b(A6);
                        [A0 + 4] = h(hu[S0 + 54]);
                        [A0 + 6] = h(hu[S0 + 56]);
                        [A0 + 8] = h(hu[S0 + 58]);

                        S2 = (S2 - h[S0 + 54]) & fff;
                        if (S2 >= 800)
                        {
                            S2 = S2 - 1000;
                        }
                        [A0 + a] = h(S2);

                        S3 = (S3 - h[S0 + 56]) & fff;
                        if (S3 >= 0)
                        {
                            S3 = S3 - 1000;
                        }
                        [A0 + c] = h(S3);

                        S4 = (S4 - h[S0 + 58]) & fff;
                        if (S4 >= 800)
                        {
                            S4 = S4 - 1000;
                        }
                        [A0 + e] = h(S4);

                        if (S5 != 0)
                        {
                            [A0 + a] = h(hu[A0 + a] + hu[S0 + 54])
                            [A0 + c] = h(hu[A0 + c] + hu[S0 + 56])
                            [A0 + e] = h(hu[A0 + e] + hu[S0 + 58])
                        }
                        [A0 + 10] = h(0);
                        [A0 + 12] = h(hu[SP + 10]);

                        [S0 + 70] = w(A0);
                        801DF4AC	j      L1df364 [$801DF364]
                    }
                }
            }
        }

        L1df338:	; 801DF338
        A1 = w[S0 + 70];
        if( ( A1 != 0 ) && ( bu[A1 + 3] != ff ) )
        {
            A0 = S7;
            func1df7a8;

            [S0 + 70] = w(0);
        }

        L1df364:	; 801DF364
        if( ( T0 & 0002 ) == 0 )
        {
            if( current_translation < max_trans_num )
            {
                S2 = h[S1];
                S1 = S1 + 2;
                S3 = h[S1];
                S1 = S1 + 2;
                S4 = h[S1];
                S1 = S1 + 2;

                current_translation = current_translation + 1;

                if( ( w[S0 + 5c] != S2 ) || ( w[S0 + 60] != S3 ) || ( w[S0 + 64] != S4 ) )
                {
                    A0 = w[S0 + 74];
                    if( ( V0 != 0 ) && ( bu[A0 + 3] == ff ) )
                    {
                        801DF4AC	j      L1df4e0 [$801df4e0]
                    }

                    A0 = S7;
                    func1df6f0;

                    A0 = V0;
                    if (A0 != 0)
                    {
                        [A0 + 0] = b(1);
                        [A0 + 1] = b(A5);
                        [A0 + 2] = b(S5 + 3);
                        [A0 + 3] = b(A6);
                        [A0 + 4] = h(hu[S0 + 5c]);
                        [A0 + 6] = h(hu[S0 + 60]);
                        [A0 + 8] = h(hu[S0 + 64]);

                        if (S5 != 0)
                        {
                            [A0 + a] = h(S2);
                            [A0 + c] = h(S3);
                            [A0 + e] = h(S4);
                        }
                        else
                        {
                            [A0 + a] = h(S2 - hu[S0 + 5c]);
                            [A0 + c] = h(S3 - hu[S0 + 60]);
                            [A0 + e] = h(S4 - hu[S0 + 64]);
                        }

                        [A0 + 10] = h(0);
                        [A0 + 12] = h(hu[SP + 10]);
                        [S0 + 74] = w(A0);
                        801DF4AC	j      L1df4e0 [$801df4e0]
                    }
                }
            }
        }

        A1 = w[S0 + 74];
        if( ( A1 != 0 ) && ( bu[A1 + 3] != ff ) )
        {
            A0 = S7;
            func1df7a8;

            [S0 + 74] = w(0);
        }

        L1df4e0:	; 801DF4E0
        S0 = S0 + 7c;
        S6 = S6 + 1;
        V0 = S6 < number_of_bone;
    801DF4EC	bne    v0, zero, L1df17c [$801df17c]
}
////////////////////////////////



////////////////////////////////
// func1df6f0
801DF6F0	lhu    v1, $0004(a0)
801DF6F4	lhu    v0, $0006(a0)
801DF6F8	nop
801DF6FC	sltu   v0, v1, v0
801DF700	beq    v0, zero, L1df79c [$801df79c]
801DF704	sll    v0, v1, $02
801DF708	addu   v0, v0, v1
801DF70C	lw     v1, $0000(a0)
801DF710	sll    v0, v0, $02
801DF714	addu   a3, v0, v1
801DF718	lbu    v0, $0000(a3)
801DF71C	nop
801DF720	bne    v0, zero, L1df7a0 [$801df7a0]
801DF724	addu   v0, zero, zero
801DF728	lhu    v0, $0004(a0)
801DF72C	lhu    a1, $0006(a0)
801DF730	addiu  v0, v0, $0001
801DF734	sh     v0, $0004(a0)
801DF738	lhu    v1, $0004(a0)
801DF73C	nop
801DF740	sltu   v0, v1, a1
801DF744	beq    v0, zero, L1df7a0 [$801df7a0]
801DF748	addu   v0, a3, zero
801DF74C	lw     a2, $0000(a0)
801DF750	sll    v0, v1, $02

loop1df754:	; 801DF754
801DF754	addu   v0, v0, v1
801DF758	sll    v0, v0, $02
801DF75C	addu   v0, v0, a2
801DF760	lbu    v0, $0000(v0)
801DF764	nop
801DF768	beq    v0, zero, L1df7a0 [$801df7a0]
801DF76C	addu   v0, a3, zero
801DF770	lhu    v0, $0004(a0)
801DF774	nop
801DF778	addiu  v0, v0, $0001
801DF77C	sh     v0, $0004(a0)
801DF780	lhu    v1, $0004(a0)
801DF784	nop
801DF788	sltu   v0, v1, a1
801DF78C	bne    v0, zero, loop1df754 [$801df754]
801DF790	sll    v0, v1, $02
801DF794	j      L1df7a0 [$801df7a0]
801DF798	addu   v0, a3, zero

L1df79c:	; 801DF79C
801DF79C	addu   v0, zero, zero

L1df7a0:	; 801DF7A0
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
if (number_of_bones == 0)
{
    return;
}

S1 = 0;
loop1dfec4:	; 801DFEC4
    A1 = w[bone_struct + S1 * 7c + 70];
    if (A1 != 0 && b[A1 + 3] != -1)
    {
        A0 = S2;
        func1df7a8;

        [bone_struct + S1 * 7c + 70] = w(0);
    }

    A1 = w[bone_struct + S1 * 7c + 74];
    if (A1 != 0 && b[A1 + 3] != -1)
    {
        A0 = S2;
        func1df7a8;

        [bone_struct + S1 * 7c + 74] = w(0);
    }

    A1 = w[bone_struct + S1 * 7c + 78];
    if (A1 != 0 && b[A1 + 3] != -1)
    {
        A0 = S2;
        func1df7a8;

        [bone_struct + S1 * 7c + 70] = w(0);
    }

    S1 = S1 + 1;
    V0 = S1 < number_of_bones;
801DFF4C	bne    v0, zero, loop1dfec4 [$801dfec4]
////////////////////////////////



////////////////////////////////
// func1df52c
//            A0 = w[SP + c8]; // 801e86a8
//            A1 = w[S4 + 4]; // pointer to allocated place for skeleton 0x7c
//            A3 = 7;

S2 = A0;
skelepon_pointer = A1;
bone_id = A2;
flags = A3;

if (bone_id < hu[skelepon_pointer + a])
{
    bone_pointer = skelepon_pointer + bone_id * 7c;
    A1 = w[bone_pointer + 70];
    if (A1 != 0 && flags & 1)
    {
        A0 = S2;
        func1df7a8;
        [bone_pointer + 70] = w(0);
    }

    A1 = w[bone_pointer + 74];
    if (A1 != 0 && flags & 2)
    {
        A0 = S2;
        func1df7a8;
        [bone_pointer + 74] = w(0);
    }

    A1 = w[bone_pointer + 78];
    if (A1 != 0 && flags & 4)
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