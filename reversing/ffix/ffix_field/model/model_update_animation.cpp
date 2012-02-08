////////////////////////////////
// field_update_animation_without_fixed_bones
// this function not uses fixed bones that stay in same direction despite all rotations of parent
model_data = A0;
frame_id = A1;
animation_file = w[model_data + c];

if( animation_file == 0 )
{
    main_data = w[model_data + 1c];
    root_matrix = w[model_data + 20];

    if( main_data != 0 ) // is this attached model
    {
        V0 = w[main_data + 20] + bu[model_data + 4] * 20;

        // rotation
        [root_matrix + 0] = w(w[V0 + 0]);
        [root_matrix + 4] = w(w[V0 + 4]);
        [root_matrix + 8] = w(w[V0 + 8]);
        [root_matrix + c] = w(w[V0 + c]);
        [root_matrix + 10] = w(w[V0 + 10]);
        // translation
        [root_matrix + 14] = w(w[V0 + 14]);
        [root_matrix + 18] = w(w[V0 + 18]);
        [root_matrix + 1c] = w(w[V0 + 1c]);

        R11R12 = w[root_matrix + 0];
        R13R21 = w[root_matrix + 4];
        R22R23 = w[root_matrix + 8];
        R31R32 = w[root_matrix + c];
        R33 = w(root_matrix + 10);

        VXY0 = w[model_data + 74];
        VZ0 = w[model_data + 78];
        gte_rtv0; // v0 * rotmatrix.

        [root_matrix + 14] = w(w[root_matrix + 14] + IR1);
        [root_matrix + 18] = w(w[root_matrix + 18] + IR2);
        [root_matrix + 1c] = w(w[root_matrix + 1c] + IR3);
    }
    else
    {
        // rotation
        [root_matrix + 0] = h(hu[model_data + 24]);
        [root_matrix + 2] = h(-hu[model_data + 26]);
        [root_matrix + 4] = h(-hu[model_data + 28]);
        [root_matrix + 6] = h(hu[model_data + 2a]);
        [root_matrix + 8] = h(-hu[model_data + 2c]);
        [root_matrix + a] = h(-hu[model_data + 2e]);
        [root_matrix + c] = h(hu[model_data + 30]);
        [root_matrix + e] = h(-hu[model_data + 32]);
        [root_matrix + 10] = h(-hu[model_data + 34]);
        // translation
        [root_matrix + 14] = w(w[model_data + 38]);
        [root_matrix + 18] = w(w[model_data + 3c]);
        [root_matrix + 1c] = w(w[model_data + 40]);
    }
}
else
{
    model_file = w[model_data + 8]; // pointer to model file
    number_of_bones = bu[model_file + 2];

    // place where we store bone matrixes. If number of bones less then 0x1f then we store to temp wlse store to final place
    S2 = 1f800018;
    if( number_of_bones >= 1f )
    {
        S2 = w[model_data + 20]; // offset to bone matrixes
    }



    // create root translation
    if( hu[animation_file + a] & 1 )
    {
        [S2 + 14] = w(h[animation_file + 4]);
    }
    else
    {
        V1 = hu[animation_file + 4];
        [S2 + 14] = w(h[animation_file + V1 + frame_id * 2]);
    }

    if( hu[animation_file + a] & 2 )
    {
        [S2 + 18] = w(h[animation_file + 6]);
    }
    else
    {
        V1 = hu[animation_file + 6];
        [S2 + 18] = w(h[animation_file + V1 + frame_id * 2]);
    }

    if( hu[animation_file + a] & 4 )
    {
        [S2 + 1c] = w(h[animation_file + 8]);
    }
    else
    {
        V1 = hu[animation_file + 6];
        [S2 + 1c] = w(h[animation_file + V1 + frame_id * 2]);
    }



    high_angle_offset = w[animation_file + c];
    low_angle_offset = w[animation_file + 10];



    // create matrixes from animation angle data
    S1 = 0;
    loopb8280:	; 800B8280
        flag = hu[high_angle_offset + 6];

        T1 = h[high_angle_offset + 0];
        if( ( flag & 1 ) == 0 )
        {
            T1 = b[animation_file + T1 + frame_id];
        }
        T1 = T1 << 4;

        T2 = h[high_angle_offset + 2];
        if( ( flag & 2 ) == 0 )
        {
            T2 = b[animation_file + T2 + frame_id];
        }
        T2 = T2 << 4;

        T3 = h[high_angle_offset + 4];
        if( ( flag & 4 ) == 0 )
        {
            T3 = b[animation_file + T3 + frame_id];
        }
        T3 = T3 << 4;

        // store it
        [1f800000] = w((T2 << 10) | (T1 & ffff));
        [1f800004] = w(T3);

        // if there is low range angles
        if( low_angle_offset != 0 )
        {
            flag = hu[low_angle_offset + 6];

            T1 = hu[low_angle_offset + 0];
            if( ( flag & 1 ) == 0 )
            {
                T1 = b[animation_file + T1 + frame_id / 2];
                if( frame_id & 1 )
                {
                    T1 = T1 >> 4;
                }
            }
            T1 = T1 & f;

            T2 = hu[low_angle_offset + 2];
            if( ( flag & 2 ) == 0 )
            {
                T2 = b[animation_file + T2 + frame_id / 2];
                if( frame_id & 1 )
                {
                    T2 = T2 >> 4;
                }
            }
            T2 = T2 & f;

            T3 = hu[low_angle_offset + 4];
            if( ( flag & 4 ) == 0 )
            {
                T3 = b[animation_file + T3 + frame_id / 2];
                if( frame_id & 1 )
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
        A1 = S2 + S1 * 20; // place for matrix
        system_create_matrix_from_angle_with_gte;

        high_angle_offset = high_angle_offset + 8;

        S1 = S1 + 1;
        V0 = S1 < number_of_bones;
    800B83CC	bne    v0, zero, loopb8280 [$800b8280]



    // root matrix
    main_data = w[model_data + 1c];
    if( main_data != 0 )
    {
        V0 = w[main_data + 20] + bu[model_data + 4] * 20;

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

        VXY0 = w[model_data + 74];
        VZ0 = w[model_data + 78];
        gte_rtv0; // v0 * rotmatrix
        [S2 + 14] = w(w[S2 + 14] + IR1);
        [S2 + 18] = w(w[S2 + 18] + IR2);
        [S2 + 1c] = w(w[S2 + 1c] + IR3);
    }
    else
    {
        R11R12 = w[model_data + 24];
        R13R21 = w[model_data + 28];
        R22R23 = w[model_data + 2c];
        R31R32 = w[model_data + 30];
        R33 = w[model_data + 34];
        TRX = w[model_data + 38];
        TRY = w[model_data + 3c];
        TRZ = w[model_data + 40];

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
    S1 = 1;
    loopb862c:	; 800B862C
        bone_data = w[model_file + c]; // pointer to bones
        parent_bone_id = bu[bone_data + S1 * 4 + 3];

        // set root bone matrix
        R11R12 = w(S2 + parent_bone_id * 20 + 0);
        R13R21 = w[S2 + parent_bone_id * 20 + 4];
        R22R23 = w(S2 + parent_bone_id * 20 + 8);
        R31R32 = w(S2 + parent_bone_id * 20 + c);
        R33 = w(S2 + parent_bone_id * 20 + 10);

        IR1 = hu[S2 + S1 * 20 + 0];
        IR2 = hu[S2 + S1 * 20 + 6];
        IR3 = hu[S2 + S1 * 20 + c];
        gte_rtir12; // ir * rotmatrix
        [S2 + S1 * 20 + 0] = h(IR1);
        [S2 + S1 * 20 + 6] = h(IR2);
        [S2 + S1 * 20 + c] = h(IR3);

        IR1 = hu[S2 + S1 * 20 + 2];
        IR2 = hu[S2 + S1 * 20 + 8];
        IR3 = hu[S2 + S1 * 20 + e];
        gte_rtir12; // ir * rotmatrix
        [S2 + S1 * 20 + 2] = h(IR1);
        [S2 + S1 * 20 + 8] = h(IR2);
        [S2 + S1 * 20 + e] = h(IR3);

        IR1 = hu[S2 + S1 * 20 + 4];
        IR2 = hu[S2 + S1 * 20 + a];
        IR3 = hu[S2 + S1 * 20 + 10];
        gte_rtir12; // ir * rotmatrix
        [S2 + S1 * 20 + 4] = h(IR1);
        [S2 + S1 * 20 + a] = h(IR2);
        [S2 + S1 * 20 + 10] = h(IR3);

        VXY0 = 0;
        VZ0 = h[bone_data + S1 * 4 + 0];
        TRX = w(S2 + parent_bone_id * 20 + 14);
        TRY = w(S2 + parent_bone_id * 20 + 18);
        TRZ = w(S2 + parent_bone_id * 20 + 1c);
        gte_rtv0tr; // v0 * rotmatrix + tr vector.
        [S2 + S1 * 20 + 14] = w(MAC1);
        [S2 + S1 * 20 + 18] = w(MAC2);
        [S2 + S1 * 20 + 1c] = w(MAC3);

        S1 = S1 + 1;
        V0 = S1 < number_of_bones;
    800B8784	bne    v0, zero, loopb862c [$800b862c]



    // copy from temp to normal place
    if( number_of_bones < 1f )
    {
        bone_data = w[model_data + 20];

        S0 = 0;
        loopb87ac:	; 800B87AC
            [bone_data + S0 * 20 + 0] = w(w[S2 + S0 * 20 + 0]);
            [bone_data + S0 * 20 + 4] = w(w[S2 + S0 * 20 + 4]);
            [bone_data + S0 * 20 + 8] = w(w[S2 + S0 * 20 + 8]);
            [bone_data + S0 * 20 + c] = w(w[S2 + S0 * 20 + c]);
            [bone_data + S0 * 20 + 10] = w(w[S2 + S0 * 20 + 10]);
            [bone_data + S0 * 20 + 14] = w(w[S2 + S0 * 20 + 14]);
            [bone_data + S0 * 20 + 18] = w(w[S2 + S0 * 20 + 18]);
            [bone_data + S0 * 20 + 1c] = w(w[S2 + S0 * 20 + 1c]);
            S0 = S0 + 1;
            V0 = S0 < number_of_bones;
        800B87FC	bne    v0, zero, loopb87ac [$800b87ac]
    }
}
////////////////////////////////



////////////////////////////////
// field_update_animation_with_fixed_bones
// this function uses fixed bones that stay in same direction despite all rotations of parent
model_data = A0;
frame_id = A1;
animation_file = w[model_data + c];

if( animation_file == 0 )
{
    main_data = w[model_data + 1c];
    root_matrix = w[model_data + 20];

    if( main_data != 0 ) // is this attached model
    {
        V0 = w[main_data + 20] + bu[model_data + 4] * 20;

        // rotation
        [root_matrix + 0] = w(w[V0 + 0]);
        [root_matrix + 4] = w(w[V0 + 4]);
        [root_matrix + 8] = w(w[V0 + 8]);
        [root_matrix + c] = w(w[V0 + c]);
        [root_matrix + 10] = w(w[V0 + 10]);
        // translation
        [root_matrix + 14] = w(w[V0 + 14] + h[model_data + 74]);
        [root_matrix + 18] = w(w[V0 + 18] + h[model_data + 76]);
        [root_matrix + 1c] = w(w[V0 + 1c] + h[model_data + 78]);
    }
    else
    {
        // rotation
        [root_matrix + 0] = h(hu[model_data + 24]);
        [root_matrix + 2] = h(-hu[model_data + 26]);
        [root_matrix + 4] = h(-hu[model_data + 28]);
        [root_matrix + 6] = h(hu[model_data + 2a]);
        [root_matrix + 8] = h(-hu[model_data + 2c]);
        [root_matrix + a] = h(-hu[model_data + 2e]);
        [root_matrix + c] = h(hu[model_data + 30]);
        [root_matrix + e] = h(-hu[model_data + 32]);
        [root_matrix + 10] = h(-hu[model_data + 34]);
        // translation
        [root_matrix + 14] = w(w[model_data + 38]);
        [root_matrix + 18] = w(w[model_data + 3c]);
        [root_matrix + 1c] = w(w[model_data + 40]);
    }
}
else
{
    model_file = w[model_data + 8];
    number_of_bones = bu[model_file + 2];

    // place where we store bone matrixes. If number of bones less then 0x1f then we store to temp wlse store to final place
    S2 = 1f800018;
    if( number_of_bones >= 1f )
    {
        S2 = w[model_data + 20];
    }



    // create root translation
    if( hu[animation_file + a] & 1 )
    {
        [S2 + 14] = w(h[animation_file + 4]);
    }
    else
    {
        V1 = hu[animation_file + 4];
        [S2 + 14] = w(h[animation_file + V1 + frame_id * 2]);
    }

    if( hu[animation_file + a] & 2 )
    {
        [S2 + 18] = w(h[animation_file + 6]);
    }
    else
    {
        V1 = hu[animation_file + 6];
        [S2 + 18] = w(h[animation_file + V1 + frame_id * 2]);
    }

    if( hu[animation_file + a] & 4 )
    {
        [S2 + 1c] = w(h[animation_file + 8]);
    }
    else
    {
        V1 = hu[animation_file + 6];
        [S2 + 1c] = w(h[animation_file + V1 + frame_id * 2]);
    }



    high_angle_offset = w[animation_file + c];
    low_angle_offset = w[animation_file + 10];



    // create matrixes from animation angle data
    S1 = 0;
    loopba870:	; 800BA870
        flag = hu[high_angle_offset + 6];

        T1 = hu[high_angle_offset + 0];
        if( ( flag & 1 ) == 0 )
        {
            T1 = b[animation_file + T1 + frame_id];
        }
        T1 = T1 << 4;

        T2 = hu[high_angle_offset + 2];
        if( ( flag & 2 ) == 0 )
        {
            T2 = b[animation_file + T2 + frame_id];
        }
        T2 = T2 << 4;

        T3 = hu[high_angle_offset + 4];
        if( ( T4 & 4 ) == 0 )
        {
            T3 = b[animation_file + T3 + frame_id];
        }
        T3 = T3 << 4;

        [1f800000] = w((T2 << 10) | (T1 & ffff));
        [1f800004] = w(T3);

        if( low_angle_offset != 0 )
        {
            flag = hu[low_angle_offset + 6];

            T1 = hu[low_angle_offset + 0];
            if( ( flag & 1 ) == 0 )
            {
                T1 = b[animation_file + T1 + frame_id / 2];
                if( frame_id & 1 )
                {
                    T1 = T1 >> 4;
                }
            }
            T1 = T1 & f;

            T2 = hu[low_angle_offset + 2];
            if( ( flag & 2 ) == 0 )
            {
                T2 = b[animation_file + T2 + frame_id / 2];
                if( frame_id & 1 )
                {
                    T2 = T2 >> 4;
                }
            }
            T2 = T2 & f;

            T3 = hu[low_angle_offset + 4];
            if( ( flag & 4 ) == 0 )
            {
                T3 = b[animation_file + T3 + frame_id / 2];
                if( frame_id & 1 )
                {
                    T3 = T3 >> 4;
                }
            }
            T3 = T3 & f;

            [1f800000] = w(w[1f800000] | (T2 << 10) | T1);
            [1f800004] = w(w[1f800004] | (T3));

            low_angle_offset = low_angle_offset + 8;
        }

        A0 = 1f800000; // angles
        A1 = S2 + S1 * 20; // place for matrix
        system_create_matrix_from_angle_with_gte;

        high_angle_offset = high_angle_offset + 8;

        S1 = S1 + 1;
        V0 = S1 < number_of_bones;
    800BA9B8	bne    v0, zero, loopba870 [$800ba870]



    // root matrix
    main_data = w[model_data + 1c];
    if( main_data != 0 )
    {
        V0 = w[main_data + 20] + bu[model_data + 4] * 20;

        [S2 + 0] = w(w[V0 + 0]);
        [S2 + 4] = w(w[V0 + 4]);
        [S2 + 8] = w(w[V0 + 8]);
        [S2 + c] = w(w[V0 + c]);
        [S2 + 10] = w(w[V0 + 10]);
        [S2 + 14] = w(w[V0 + 14]);
        [S2 + 18] = w(w[V0 + 18]);
        [S2 + 1c] = w(w[V0 + 1c]);

        [S2 + 14] = w(w[S2 + 14] + h[model_data + 74]);
        [S2 + 18] = w(w[S2 + 18] + h[model_data + 76]);
        [S2 + 1c] = w(w[S2 + 1c] + h[model_data + 78]);
    }
    else
    {
        R11R12 = w[model_data + 24];
        R13R21 = w[model_data + 28];
        R22R23 = w[model_data + 2c];
        R31R32 = w[model_data + 30];
        R33 = w[model_data + 34];
        TRX = w[model_data + 38];
        TRY = w[model_data + 3c];
        TRZ = w[model_data + 40];

        IR1 = hu[S2 + 0];
        IR2 = hu[S2 + 6];
        IR3 = hu[S2 + c];
        gte_rtir12; // ir * rotmatrix.
        [S2 + 0] = h(IR1);
        [S2 + 6] = h(IR2);
        [S2 + c] = h(IR3);

        IR1 = hu[S2 + 2];
        IR2 = hu[S2 + 8];
        IR3 = hu[S2 + e];
        gte_rtir12; // ir * rotmatrix.
        [S2 + 2] = h(IR1);
        [S2 + 8] = h(IR2);
        [S2 + e] = h(IR3);

        IR1 = hu[S2 + 4];
        IR2 = hu[S2 + a];
        IR3 = hu[S2 + 10];
        gte_rtir12; // ir * rotmatrix.
        [S2 + 4] = h(IR1);
        [S2 + a] = h(IR2);
        [S2 + 10] = h(IR3);

        VXY0 = (hu[S2 + 18] << 10) | hu[S2 + 14 + 0];
        VZ0 = w[S2 + 1c];
        gte_rtv0tr; // v0 * rotmatrix + tr vector.
        [S2 + 14] = w(MAC1);
        [S2 + 18] = w(MAC2);
        [S2 + 1c] = w(MAC3);
    }



    // add parent bone matrix transformation to bone matrixes
    S1 = 1;
    Lbabc8:	; 800BABC8
        bone_data = w[model_file + c]; // pointer to bones
        parent_bone_id = bu[bone_data + S1 * 4 + 3];

        R11R12 = w[S2 + parent_bone_id * 20 + 0];
        R13R21 = w[S2 + parent_bone_id * 20 + 4];
        R22R23 = w[S2 + parent_bone_id * 20 + 8];
        R31R32 = w[S2 + parent_bone_id * 20 + c];
        R33 = w[S2 + parent_bone_id * 20 + 10];

        IR1 = hu[S2 + S1 * 20 + 0];
        IR2 = hu[S2 + S1 * 20 + 6];
        IR3 = hu[S2 + S1 * 20 + c];
        gte_rtir12; // ir * rotmatrix.
        [S2 + S1 * 20 + 0] = h(IR1);
        [S2 + S1 * 20 + 6] = h(IR2);
        [S2 + S1 * 20 + c] = h(IR3);

        IR1 = hu[S2 + S1 * 20 + 2];
        IR2 = hu[S2 + S1 * 20 + 8];
        IR3 = hu[S2 + S1 * 20 + e];
        gte_rtir12; // ir * rotmatrix.
        [S2 + S1 * 20 + 2] = h(IR1);
        [S2 + S1 * 20 + 8] = h(IR2);
        [S2 + S1 * 20 + e] = h(IR3);

        IR1 = hu[S2 + S1 * 20 + 4];
        IR2 = hu[S2 + S1 * 20 + a];
        IR3 = hu[S2 + S1 * 20 + 10];
        gte_rtir12; // ir * rotmatrix.
        [S2 + S1 * 20 + 4] = h(IR1);
        [S2 + S1 * 20 + a] = h(IR2);
        [S2 + S1 * 20 + 10] = h(IR3);

        VXY0 = 0;
        VZ0 = h[bone_data + S1 * 4 + 0];
        TRX = w[S2 + parent_bone_id * 20 + 14];
        TRY = w[S2 + parent_bone_id * 20 + 18];
        TRZ = w[S2 + parent_bone_id * 20 + 1c];
        gte_rtv0tr; // v0 * rotmatrix + tr vector.
        [S2 + S1 * 20 + 14] = w(MAC1);
        [S2 + S1 * 20 + 18] = w(MAC2);
        [S2 + S1 * 20 + 1c] = w(MAC3);



        if( S1 == bu[model_file + 6] )
        {
            // reset all previous rotation
            [SP + 10] = w(w[S2 + S1 * 20 + 14] - h[model_data + 48]);
            [SP + 14] = w(w[S2 + S1 * 20 + 18] - h[model_data + 4a]);
            [SP + 18] = w(w[S2 + S1 * 20 + 1c] - h[model_data + 4c]);

            A0 = SP + 10;
            A1 = SP + 40;
            system_normalize_vector_A0_to_A1;

            R11R12 = 0;
            R22R23 = 1000;
            R33 = 0;
            IR1 = w[SP + 40];
            IR2 = w[SP + 44];
            IR3 = w[SP + 48];
            gte_op12; // Outer product.
            [SP + 10] = w(MAC1);
            [SP + 14] = w(MAC2);
            [SP + 18] = w(MAC3);

            A0 = SP + 10;
            A1 = SP + 30;
            system_normalize_vector_A0_to_A1;

            R11R12 = w[SP + 30];
            R22R23 = w[SP + 34];
            R33 = w[SP + 38];
            IR1 = w[SP + 40];
            IR2 = w[SP + 44];
            IR3 = w[SP + 48];
            gte_op12; // Outer product.
            [SP + 10] = w(MAC1);
            [SP + 14] = w(MAC2);
            [SP + 18] = w(MAC3);

            A0 = SP + 10;
            A1 = SP + 50;
            system_normalize_vector_A0_to_A1;

            [S2 + S1 * 20 + 0] = h(hu[SP + 30]);
            [S2 + S1 * 20 + 2] = h(hu[SP + 40]);
            [S2 + S1 * 20 + 4] = h(hu[SP + 50]);
            [S2 + S1 * 20 + 6] = h(hu[SP + 34]);
            [S2 + S1 * 20 + 8] = h(hu[SP + 44]);
            [S2 + S1 * 20 + a] = h(hu[SP + 54]);
            [S2 + S1 * 20 + c] = h(hu[SP + 38]);
            [S2 + S1 * 20 + e] = h(hu[SP + 48]);
            [S2 + S1 * 20 + 10] = h(hu[SP + 58]);

            // restore scaling if model was scaled
            if( hu[model_data + 0] & 2 )
            {
                R11R12 = w[S2 + S1 * 20 + 0];
                R13R21 = w[S2 + S1 * 20 + 4];
                R22R23 = w[S2 + S1 * 20 + 8];
                R31R32 = w[S2 + S1 * 20 + c];
                R33 = w[S2 + S1 * 20 + 10];

                IR1 = hu[model_data + 54];
                IR2 = 0;
                IR3 = 0;
                gte_rtir12; // ir * rotmatrix.
                [S2 + S1 * 20 + 0] = h(IR1);
                [S2 + S1 * 20 + 6] = h(IR2);
                [S2 + S1 * 20 + c] = h(IR3);

                IR1 = 0;
                IR2 = hu[model_data + 56];
                IR3 = 0;
                gte_rtir12; // ir * rotmatrix.
                [S2 + S1 * 20 + 2] = h(IR1);
                [S2 + S1 * 20 + 8] = h(IR2);
                [S2 + S1 * 20 + e] = h(IR3);

                IR1 = 0;
                IR2 = 0;
                IR3 = hu[model_data + 58];
                gte_rtir12; // ir * rotmatrix.
                [S2 + S1 * 20 + 4] = h(IR1);
                [S2 + S1 * 20 + a] = h(IR2);
                [S2 + S1 * 20 + 10] = h(IR3);
            }
        }

        S1 = S1 + 1;
        V0 = S1 < number_of_bones;
    800BAFD8	bne    v0, zero, Lbabc8 [$800babc8]



    // copy from temp to normal place
    if( number_of_bones < 1f )
    {
        bone_data = w[model_data + 20];

        S0 = 0;
        loopbb000:	; 800BB000
            [bone_data + S0 * 20 + 0] = w(w[S2 + S0 * 20 + 0]);
            [bone_data + S0 * 20 + 4] = w(w[S2 + S0 * 20 + 4]);
            [bone_data + S0 * 20 + 8] = w(w[S2 + S0 * 20 + 8]);
            [bone_data + S0 * 20 + c] = w(w[S2 + S0 * 20 + c]);
            [bone_data + S0 * 20 + 10] = w(w[S2 + S0 * 20 + 10]);
            [bone_data + S0 * 20 + 14] = w(w[S2 + S0 * 20 + 14]);
            [bone_data + S0 * 20 + 18] = w(w[S2 + S0 * 20 + 18]);
            [bone_data + S0 * 20 + 1c] = w(w[S2 + S0 * 20 + 1c]);
            S0 = S0 + 1;
            V0 = S0 < number_of_bones;
        800BB058	bne    v0, zero, loopbb000 [$800bb000]
    }
}
////////////////////////////////
