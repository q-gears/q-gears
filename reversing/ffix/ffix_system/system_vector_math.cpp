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
// func30ea4
A2 = 0;
func30ee4;
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
if ((400 - rot_x) & 800)
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



////////////////////////////////
// func30ee4
T2 = A1;
T5 = A2;

rot_x = h[A0 + 0];
rot_y = h[A0 + 2];
rot_z = h[A0 + 4];

T0 = rot_x & fff;
A3 = rot_y & fff;
T1 = rot_z & fff;
if( rot_x & 400 )
{
    sin_x = T3 = hu[8006c1c4 + (400 - (rot_x & 3ff)) * 2];
}
else
{
    sin_x = T3 = hu[8006c1c4 + (rot_x & 3ff) * 2];
}

A1 = 400;
if( T0 & 800 )
{
    T3 = -T3;
}

A0 = A1 - T0;
V0 = A0 & A1;
T0 = A0 & fff;
if( V0 != 0 )
{
    V0 = A1 - (A0 & 3ff);
}
else
{
    V0 = A0 & 3ff;
}

V1 = 8006c1c4;
V0 = V0 * 2;
V0 = V0 + V1;
T6 = hu[V0];
V0 = T0 & 800;

80030FA8	beq    v0, zero, L30fb4 [$80030fb4]
80030FAC	andi   v0, a3, $0400
80030FB0	subu   t6, zero, t6

L30fb4:	; 80030FB4
80030FB4	beq    v0, zero, L30fe0 [$80030fe0]
80030FB8	lui    v0, $8007
80030FBC	addiu  v0, v0, $c1c4 (=-$3e3c)
80030FC0	andi   a0, a3, $03ff
80030FC4	addiu  v1, zero, $0400
80030FC8	subu   v1, v1, a0
80030FCC	sll    v1, v1, $01
80030FD0	addu   v1, v1, v0
80030FD4	lhu    t4, $0000(v1)
80030FD8	j      L30ffc [$80030ffc]
80030FDC	andi   v0, a3, $0800

L30fe0:	; 80030FE0
80030FE0	lui    v1, $8007
80030FE4	addiu  v1, v1, $c1c4 (=-$3e3c)
80030FE8	andi   v0, a3, $03ff
80030FEC	sll    v0, v0, $01
80030FF0	addu   v0, v0, v1
80030FF4	lhu    t4, $0000(v0)
80030FF8	andi   v0, a3, $0800

L30ffc:	; 80030FFC
80030FFC	beq    v0, zero, L31008 [$80031008]
80031000	addiu  a1, zero, $0400
80031004	subu   t4, zero, t4

L31008:	; 80031008
80031008	subu   a0, a1, a3
8003100C	and    v0, a0, a1
80031010	beq    v0, zero, L3102c [$8003102c]
80031014	andi   a3, a0, $0fff
80031018	lui    v1, $8007
8003101C	addiu  v1, v1, $c1c4 (=-$3e3c)
80031020	andi   v0, a0, $03ff
80031024	j      L31038 [$80031038]
80031028	subu   v0, a1, v0

L3102c:	; 8003102C
8003102C	lui    v1, $8007
80031030	addiu  v1, v1, $c1c4 (=-$3e3c)
80031034	andi   v0, a0, $03ff

L31038:	; 80031038
80031038	sll    v0, v0, $01
8003103C	addu   v0, v0, v1
80031040	lhu    a1, $0000(v0)
80031044	andi   v0, a3, $0800
80031048	beq    v0, zero, L31054 [$80031054]
8003104C	andi   v0, t1, $0400
80031050	subu   a1, zero, a1

L31054:	; 80031054
80031054	beq    v0, zero, L31080 [$80031080]
80031058	lui    v0, $8007
8003105C	addiu  v0, v0, $c1c4 (=-$3e3c)
80031060	andi   a0, t1, $03ff
80031064	addiu  v1, zero, $0400
80031068	subu   v1, v1, a0
8003106C	sll    v1, v1, $01
80031070	addu   v1, v1, v0
80031074	lhu    a3, $0000(v1)
80031078	j      L3109c [$8003109c]
8003107C	andi   v0, t1, $0800

L31080:	; 80031080
80031080	lui    v1, $8007
80031084	addiu  v1, v1, $c1c4 (=-$3e3c)
80031088	andi   v0, t1, $03ff
8003108C	sll    v0, v0, $01
80031090	addu   v0, v0, v1
80031094	lhu    a3, $0000(v0)
80031098	andi   v0, t1, $0800

L3109c:	; 8003109C
8003109C	beq    v0, zero, L310a8 [$800310a8]
800310A0	addiu  t0, zero, $0400
800310A4	subu   a3, zero, a3

L310a8:	; 800310A8
800310A8	subu   a0, t0, t1
800310AC	and    v0, a0, t0
800310B0	beq    v0, zero, L310cc [$800310cc]
800310B4	andi   t1, a0, $0fff
800310B8	lui    v1, $8007
800310BC	addiu  v1, v1, $c1c4 (=-$3e3c)
800310C0	andi   v0, a0, $03ff
800310C4	j      L310d8 [$800310d8]
800310C8	subu   v0, t0, v0

L310cc:	; 800310CC
800310CC	lui    v1, $8007
800310D0	addiu  v1, v1, $c1c4 (=-$3e3c)
800310D4	andi   v0, a0, $03ff

L310d8:	; 800310D8
800310D8	sll    v0, v0, $01
800310DC	addu   v0, v0, v1
800310E0	lhu    a2, $0000(v0)
800310E4	andi   v0, t1, $0800
800310E8	beq    v0, zero, L310f4 [$800310f4]
800310EC	sll    v0, t3, $10
800310F0	subu   a2, zero, a2

L310f4:	; 800310F4
800310F4	sra    v0, v0, $10
800310F8	sll    a3, a3, $10
800310FC	sra    a3, a3, $10
80031100	mult   v0, a3
80031104	mflo   v1
80031108	sll    a2, a2, $10
8003110C	sra    a2, a2, $10
80031110	mult   v0, a2
80031114	mflo   t5
80031118	sll    a1, a1, $10
8003111C	sra    a1, a1, $10
80031120	mult   a2, a1
80031124	sll    v1, v1, $04
80031128	sra    v1, v1, $10
8003112C	mflo   s0
80031130	sll    v0, t4, $10
80031134	sra    v0, v0, $10
80031138	mult   v1, v0
8003113C	sll    a0, t6, $10
80031140	mflo   t9
80031144	sra    a0, a0, $10
80031148	subu   t0, zero, a0
8003114C	mult   t0, a3
80031150	mflo   t1
80031154	nop
80031158	nop
8003115C	mult   a2, v0
80031160	mflo   t7
80031164	nop
80031168	nop
8003116C	mult   v1, a1
80031170	mflo   t6
80031174	nop
80031178	nop
8003117C	mult   a3, a1
80031180	mflo   t8
80031184	sll    v1, t5, $04
80031188	sra    v1, v1, $10
8003118C	mult   v1, v0
80031190	mflo   t4
80031194	nop
80031198	nop
8003119C	mult   a0, a2
800311A0	mflo   t5
800311A4	nop
800311A8	nop
800311AC	mult   a3, v0
800311B0	mflo   a3
800311B4	nop
800311B8	nop
800311BC	mult   t0, v0
800311C0	mflo   a2
800311C4	nop
800311C8	nop
800311CC	mult   a0, a1
800311D0	sh     t3, $000e(t2)
800311D4	sra    v0, t1, $0c
800311D8	sh     v0, $0002(t2)
800311DC	sra    v0, t5, $0c
800311E0	sh     v0, $0008(t2)
800311E4	mflo   a0
800311E8	sra    v0, a2, $0c
800311EC	sh     v0, $000c(t2)
800311F0	mult   v1, a1
800311F4	sra    v0, a0, $0c
800311F8	sh     v0, $0010(t2)
800311FC	subu   v0, s0, t9
80031200	sra    v0, v0, $0c
80031204	sh     v0, $0000(t2)
80031208	addu   v0, t7, t6
8003120C	sra    v0, v0, $0c
80031210	sh     v0, $0004(t2)
80031214	addu   v0, t8, t4
80031218	sra    v0, v0, $0c
8003121C	sh     v0, $0006(t2)
80031220	mflo   v1
80031224	subu   v0, a3, v1
80031228	sra    v0, v0, $0c
8003122C	sh     v0, $000a(t2)
80031238	addu   v0, t2, zero
////////////////////////////////