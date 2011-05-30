////////////////////////////////
// funcb7f14
S3 = A0; // pointer to data.
frame = A1; // frame id
S1 = w[S3 + c]; // animation file pointer
if (S1 == 0)
{
    V1 = w[S3 + 1c];
    if (V1 != 0)
    {
        V1 = w[V1 + 20] + bu[S3 + 4] * 20;
        V0 = w[S3 + 20];
        [V0 + 0] = w(w[V1 + 0]);
        [V0 + 4] = w(w[V1 + 4]);
        [V0 + 8] = w(w[V1 + 8]);
        [V0 + c] = w(w[V1 + c]);
        [V0 + 10] = w(w[V1 + 10]);
        [V0 + 14] = w(w[V1 + 14]);
        [V0 + 18] = w(w[V1 + 18]);
        [V0 + 1c] = w(w[V1 + 1c]);

        T7 = w[S3 + 20];
        R11R12 = w(T7 + 0);
        R13R21 = w[T7 + 4];
        R22R23 = w(T7 + 8);
        R31R32 = w(T7 + c);
        R33 = w(T7 + 10);

        VXY0 = w[S3 + 74];
        VZ0 = w[S3 + 78];
        gte_rtv0; // v0 * rotmatrix.

        A0 = w[S3 + 20];
        [A0 + 14] = w(w[A0 + 14] + IR1);
        [A0 + 18] = w(w[A0 + 18] + IR2);
        [A0 + 1c] = w(w[A0 + 1c] + IR3);
    }
    else
    {
        V1 = w[S3 + 20];
        [V1 + 0] = h(hu[S3 + 24]);
        [V1 + 2] = h(-hu[S3 + 26]);
        [V1 + 4] = h(-hu[S3 + 28]);
        [V1 + 6] = h(hu[S3 + 2a]);
        [V1 + 8] = h(-hu[S3 + 2c]);
        [V1 + a] = h(-hu[S3 + 2e]);
        [V1 + c] = h(hu[S3 + 30]);
        [V1 + e] = h(-hu[S3 + 32]);
        [V1 + 10] = h(-hu[S3 + 34]);

        [V1 + 14] = w(w[S3 + 38]);
        [V1 + 18] = w(w[S3 + 3c]);
        [V1 + 1c] = w(w[S3 + 40]);
    }
}
else
{
    V0 = w[S3 + 8]; // pointer to model file
    number_of_bones = bu[V0 + 2];

    // select where bone matrix stored
    S2 = 1f800018;
    if (number_of_bones >= 1f)
    {
        S2 = w[S3 + 20]; // offset to bone matrixes
    }



    // create root translation
    if (hu[S1 + a] & 1)
    {
        [S2 + 14] = w(h[S1 + 4]);
    }
    else
    {
        [S2 + 14] = w(h[S1 + hu[S1 + 4] + frame * 2]);
    }

    if (hu[S1 + a] & 2)
    {
        [S2 + 18] = w(h[S1 + 6]);
    }
    else
    {
        [S2 + 18] = w(h[S1 + hu[S1 + 6] + frame * 2]);
    }

    if (hu[S1 + a] & 4)
    {
        [S2 + 1c] = w(h[S1 + 8]);
    }
    else
    {
        [S2 + 1c] = w(h[S1 + hu[S1 + 8] + frame * 2]);
    }



    // create matrixes from animation angle data
    high_angle_offset = w[S1 + c];
    low_angle_offset = w[S1 + 10];
    S0 = S2;
    FP = S2 + number_of_bones * 20;
    loopb8280:	; 800B8280
        flag = hu[high_angle_offset + 6];

        T1 = h[high_angle_offset + 0];
        if ((flag & 1) == 0)
        {
            T1 = b[S1 + T1 + frame];
        }
        T1 = T1 << 4;

        T2 = h[high_angle_offset + 2];
        if ((flag & 2) == 0)
        {
            T2 = b[S1 + T2 + frame];
        }
        T2 = T2 << 4;

        T3 = h[high_angle_offset + 4];
        if ((flag & 4) == 0)
        {
            T3 = b[S1 + T3 + frame];
        }
        T3 = T3 << 4;

        // store it
        [1f800000] = w((T2 << 10) | T1);
        [1f800004] = w(T3);

        // if there is low range angles
        if (low_angle_offset != 0)
        {
            flag = hu[low_angle_offset + 6];

            T1 = hu[low_angle_offset + 0];
            if ((flag & 1) == 0)
            {
                T1 = b[S1 + T1 + frame / 2];
                if (frame & 1)
                {
                    T1 = T1 >> 4;
                }
            }
            T1 = T1 & f;

            T2 = hu[low_angle_offset + 2];
            if ((flag & 2) == 0)
            {
                T2 = b[S1 + T2 + frame / 2];
                if (frame & 1)
                {
                    T2 = T2 >> 4;
                }
            }
            T2 = T2 & f;

            T3 = hu[low_angle_offset + 4];
            if ((flag & 4) == 0)
            {
                T3 = b[S1 + T3 + frame / 2];
                if (frame & 1)
                {
                    T3 = T3 >> 4;
                }
            }
            T3 = T3 & f;

            [1f800000] = w(w[1f800000] | (T2 << 10) | T1);
            [1f800004] = w(w[1f800004] | T3);

            low_angle_offset = low_angle_offset + 8;
        }

        A0 = 1f800000; // angles
        A1 = S0; // place for matrix
        system_create_matrix_from_angle_with_gte;

        high_angle_offset = high_angle_offset + 8;
        S0 = S0 + 20;
        V0 = S0 < FP;
    800B83CC	bne    v0, zero, loopb8280 [$800b8280]



    // root matrix
    V1 = w[S3 + 1c];
    if (V1 != 0)
    {
        V0 = w[V1 + 20] + bu[S3 + 4] * 20;

        [S2 + 0] = w(w[V0 + 0]);
        [S2 + 4] = w(w[V0 + 4]);
        [S2 + 8] = w(w[V0 + 8]);
        [S2 + c] = w(w[V0 + c]);
        [S2 + 10] = w(w[V0 + 10]);
        [S2 + 14] = w(w[V0 + 14]);
        [S2 + 18] = w(w[V0 + 18]);
        [S2 + 1c] = w(w[V0 + 1c]);

        R11R12 = w[S2 + 0];
        R13R21 = w[S2 + 4];
        R22R23 = w[S2 + 8];
        R31R32 = w[S2 + c];
        R33 = w[S2 + 10];

        VXY0 = w[S3 + 74];
        VZ0 = w[S3 + 78];
        gte_rtv0; // v0 * rotmatrix
        [S2 + 14] = w(w[S2 + 14] + IR1);
        [S2 + 18] = w(w[S2 + 18] + IR2);
        [S2 + 1c] = w(w[S2 + 1c] + IR3);
    }
    else
    {
        R11R12 = w[S3 + 24];
        R13R21 = w[S3 + 28];
        R22R23 = w[S3 + 2c];
        R31R32 = w[S3 + 30];
        R33 = w[S3 + 34];
        TRX = w[S3 + 38];
        TRY = w[S3 + 3c];
        TRZ = w[S3 + 40];

        IR1 = hu[S2 + 0];
        IR2 = hu[S2 + 6];
        IR3 = hu[S2 + c];
        gte_rtir12; // ir * rotmatrix
        [S2 + 0] = h(IR1);
        [S2 + 6] = h(IR2);
        [S2 + c] = h(IR3);

        IR1 = hu[S2 + 2];
        IR2 = hu[S2 + 8];
        IR3 = hu[S2 + e];
        gte_rtir12; // ir * rotmatrix
        [S2 + 2] = h(IR1);
        [S2 + 8] = h(IR2);
        [S2 + e] = h(IR3);

        IR1 = hu[S2 + 4];
        IR2 = hu[S2 + a];
        IR3 = hu[S2 + 10];
        gte_rtir12; // ir * rotmatrix
        [S2 + 4] = h(IR1);
        [S2 + a] = h(IR2);
        [S2 + 10] = h(IR3);

        VXY0 = (hu[S2 + 18] << 10) | hu[S2 + 14];
        VZ0 = w[S2 + 1c];
        gte_rtv0tr; // v0 * rotmatrix + tr vector.
        [S2 + 14] = MAC1;
        [S2 + 18] = MAC2;
        [S2 + 1c] = MAC3;
    }



    // add parent bone matrix transformation to bone matrixes
    V0 = w[S3 + 8]; // pointer to model file
    V0 = w[V0 + c]; // pointer to bones

    A0 = V0 + 4; // skip root bone
    S0 = S2 + 20; // skip root bone

    loopb862c:	; 800B862C
        [1f800010] = w(h[A0 + 0]);
        V1 = S2 + bu[A0 + 3] * 20; // parent bone matrix

        // set root bone matrix
        R11R12 = w(V1 + 0);
        R13R21 = w[V1 + 4];
        R22R23 = w(V1 + 8);
        R31R32 = w(V1 + c);
        R33 = w(V1 + 10);
        TRX = w(V1 + 14);
        TRY = w(V1 + 18);
        TRZ = w(V1 + 1c);

        IR1 = hu[S0 + 0];
        IR2 = hu[S0 + 6];
        IR3 = hu[S0 + c];
        gte_rtir12; // ir * rotmatrix
        [S0 + 0] = h(IR1);
        [S0 + 6] = h(IR2);
        [S0 + c] = h(IR3);

        IR1 = hu[S0 + 2];
        IR2 = hu[S0 + 8];
        IR3 = hu[S0 + e];
        gte_rtir12; // ir * rotmatrix
        [S0 + 2] = h(IR1);
        [S0 + 8] = h(IR2);
        [S0 + e] = h(IR3);

        IR1 = hu[S0 + 4];
        IR2 = hu[S0 + a];
        IR3 = hu[S0 + 10];
        gte_rtir12; // ir * rotmatrix
        [S0 + 4] = h(IR1);
        [S0 + a] = h(IR2);
        [S0 + 10] = h(IR3);

        VXY0 = 0;
        VZ0 = w(1f800010);
        gte_rtv0tr; // v0 * rotmatrix + tr vector.
        [S0 + 14] = w(MAC1);
        [S0 + 18] = w(MAC2);
        [S0 + 1c] = w(MAC3);

        A0 = A0 + 4;
        S0 = S0 + 20;
        V0 = S0 < FP;
    800B8784	bne    v0, zero, loopb862c [$800b862c]



    // copy from temp to normal place
    if (number_of_bones < 1f)
    {
        S0 = w[S3 + 20];

        loopb87ac:	; 800B87AC
            [S0 + 0] = w(w[S2 + 0]);
            [S0 + 4] = w(w[S2 + 4]);
            [S0 + 8] = w(w[S2 + 8]);
            [S0 + c] = w(w[S2 + c]);
            [S0 + 10] = w(w[S2 + 10]);
            [S0 + 14] = w(w[S2 + 14]);
            [S0 + 18] = w(w[S2 + 18]);
            [S0 + 1c] = w(w[S2 + 1c]);

            S2 = S2 + 20;
            S0 = S0 + 20;
            V0 = S2 < FP;
        800B87FC	bne    v0, zero, loopb87ac [$800b87ac]
    }
}

Lb8804:	; 800B8804
////////////////////////////////