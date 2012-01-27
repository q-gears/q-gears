//////////////////////////////////////////////////////////
system_set_gte_mac2
a0 - value to be set in GTE mac2 register
//////////////////////////////////////////////////////////



////////////////////////////////
// system_perspective_transformation_on_4_points
VXY0 = w[A0 + 0];
VZ0 = w[A0 + 4]
VXY1 = w[A1 + 0];
VZ1 = w[A1 + 4]
VXY2 = w[A2 + 0];
VZ2 = w[A2 + 4]
gte_RTPT; // Perspective transform on 3 points.
[w[SP + 10]] = w(SXY0);
[w[SP + 14]] = w(SXY1);
[w[SP + 18]] = w(SXY2);
V1 = FLAG;

VXY0 = w[A3 + 0];
VZ0 = w[A3 + 4]
gte_RTPS; // Perspective transform
[w[SP + 1c]] = w(SXY2);
T0 = FLAG;

[w[SP + 20]] = w(T0);
[w[SP + 24]] = w(T0 | V1);

AVSZ4; // Average of four Z values

return OTZ;
////////////////////////////////



////////////////////////////////
// system_matrix_vector_multiply
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];

VXY0 = w[A1 + 0];
VZ0 = w[A1 + 4];
gte_rtv0;
[A2 + 0] = IR1;
[A2 + 2] = IR2;
[A2 + 4] = IR3;
return A2;
////////////////////////////////



////////////////////////////////
// system_set_far_color_to_GTE
RFC = w(A0 << 4);
GFC = w(A1 << 4);
BFC = w(A2 << 4);
////////////////////////////////



////////////////////////////////
// system_call_rtv0tr_from_GTE
VXY0 = w[A0 + 0];
VZ0 = w[A0 + 4];
gte_rtv0tr; // v0 * rotmatrix + tr vector.

[A1 + 0] = w(MAC1);
[A1 + 4] = w(MAC2);
[A1 + 8] = w(MAC3);
[A2 + 0] = w(FLAG);

return FLAG;
////////////////////////////////



////////////////////////////////
// system_set_translation_vector_to_GTE
TRX = w[A0 + 14];
TRY = w[A0 + 18];
TRZ = w[A0 + 1c];
////////////////////////////////



////////////////////////////////
// system_set_rotation_matrix_to_GTE
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];
////////////////////////////////



////////////////////////////////
// system_matrixes_multiply
// multiply matrixes A0 and A1 and store result to A1

// set rotation matrix
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33 = w[A0 + 10];

VXY0 = (w[A1 + 6] << 10) | hu[A1 + 0];
VZ0 = w[A1 + c];
gte_rtv0; // v0 * rotmatrix.
T3 = IR1;
T4 = IR2;
T5 = IR3;

VXY0 = (w[A1 + 8] << 10) | hu[A1 + 2];
VZ0 = h[A1 + e];
gte_rtv0; // v0 * rotmatrix.
T6 = IR1;
T7 = IR2;
T8 = IR3;


VXY0 = (w[A1 + a] << 10) | hu[A1 + 4];
VZ0 = h[A1 + 10];
gte_rtv0; // v0 * rotmatrix.

[A1 + 0] = w((T6 << 10) | (T3 & ffff));
[A1 + 4] = w((T4 << 10) | IR1);
[A1 + 8] = w((IR2 << 10) | (T7 & ffff));
[A1 + c] = w((T8 << 10) | (T5 & ffff));
[A1 + 10] = w(IR3);

return A1;
////////////////////////////////



////////////////////////////////
// system_transformation_data_multiply
// multiply matrixes and vector A0 and A1 and store result to A2

// set rotation matrix
R11R12 = w[A0 + 0];
R13R21 = w[A0 + 4];
R22R23 = w[A0 + 8];
R31R32 = w[A0 + c];
R33    = w[A0 + 10];

VXY0 = (hu[A1 + 6] << 10) | hu[A1 + 0];
VZ0 = w[A1 + c];
gte_rtv0; // v0 * rotmatrix.
T3 = IR1;
T4 = IR2;
T5 = IR3;

VXY0 = (w[A1 + 8] << 10) | hu[A1 + 2];
VZ0 = h[A1 + e];
gte_rtv0; // v0 * rotmatrix.
T6 = IR1;
T7 = IR2;
T8 = IR3;

VXY0 = (hu[A1 + a] << 10) | hu[A1 + 4];
VZ0 = w[A1 + 10];
gte_rtv0; // v0 * rotmatrix.
T0 = IR1
T1 = IR2
[A2 + 10] = w(IR3);

[A2 + 0] = w((T6 << 10) | (T3 & ffff));
[A2 + c] = w((T8 << 10) | (T5 & ffff));

VXY0 = (w[A1 + 18] << 10) | hu[A1 + 14];
VZ0 = w[A1 + 1c];
gte_rtv0; // v0 * rotmatrix.

[A2 + 4] = w((T4 << 10) | (T0 & ffff));
[A2 + 8] = w((T1 << 10) | (T7 & ffff));

[A2 + 14] = w(MAC1 + w[A0 + 14]);
[A2 + 18] = w(MAC2 + w[A0 + 18]);
[A2 + 1c] = w(MAC3 + w[A0 + 1c]);

return A2;
////////////////////////////////



////////////////////////////////////////////////////////
// system_square_root
8003A59C	mtc2   a0,zsf4
8003A5A8	mfc2   v0,flag

if (V0 != 20)
{
    T0 = V0 & 1;
    T2 = V0 & FFFFFFFD
    T1 = 13;
    T1 = T1 - T2;
    T1 = T1 >> 1;
    T3 = T2 + FFE8 (-18);

    if (T3 > 0)
    {
        T4 = T3 << A0;
    }
    else
    {
        T3 = 18 - T2;
        T4 = T3 >> A0;
    }

    8003A5F0	addi   t4, t4, $ffc0 (=-$40)
    8003A5F4	sll    t4, t4, $01
    8003A5F8	lui    t5, $8005
    8003A5FC	addu   t5, t5, t4
    8003A600	lh     t5, $b668(t5)

    if (T1 >= 0)
    {
        V0 = T1 << T5;
        return V0;
    }

    T1 = 0 - T1;
    V0 = T1 >> T5;
    return V0;
}

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// system_normalize_vector_T0_T1_T2
IR1 = T0;
IR2 = T1;
IR3 = T2;

gte_SQR;

T3 = MAC1;
T4 = MAC2;
T5 = MAC3;

V0 = T3 + T4 + T5;

LZCS = V0;
V1 = LZCR & fffffffe;


T3 = V1 - 18;
T6 = (1f - V1) / 2;
if (T3 >= 0)
{
    T4 = V0 << T3;

}
else
{
    T3 = 18 - V1;
    T4 = V0 >> T3;
}

T5 = [8004b7fc + (T4 - 40) * 2];

IR0 = T5;
IR1 = T0;
IR2 = T1;
IR3 = T2;

gte_GPF; // General Purpose Interpolation. IR0 - scale

T0 = MAC1 >> T6;
T1 = MAC2 >> T6;
T2 = MAC3 >> T6;
////////////////////////////////////////////////////////



///////////////////////////////////////////////////////
// OuterProduct0
A0 - first vector address
A1 - second vector address
A2 - outer product address

VXY0 = [A0 + 0]
VXY1 = [A0 + 4]
VXY2 = [A0 + 8]
T1 = [A1 + 0]
T2 = [A1 + 4]
T3 = [A1 + 8]

[R11R12,R22R23,R33] vector 1
[IR1,IR2,IR3]       vector 2
MAC1 = R22R23*IR3 - R33   *IR2
MAC2 = R33   *IR1 - R11R12*IR3
MAC3 = R11R12*IR2 - R22R23*IR1
[MAC1,MAC2,MAC3] outer product

[A2 + 0] = T9;
[A2 + 4] = K0;
[A2 + 8] = K1;
///////////////////////////////////////////////////////