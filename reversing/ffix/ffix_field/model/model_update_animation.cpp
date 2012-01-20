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
////////////////////////////////



////////////////////////////////
// funcba560
model_data = S3 = A0;
frame_id = S5 = A1;
animation_file = S0 = w[model_data + c];

if( animation_file == 0 )
{
    original_data = w[model_data + 1c];
    if( original_data != 0 ) // is this instanced model
    {
        V1 = w[model_data + 20]
        V0 = w[original_data + 20] + bu[model_data + 4] * 20;

        [V1 + 0] = w(w[V0 + 0]);
        [V1 + 4] = w(w[V0 + 4]);
        [V1 + 8] = w(w[V0 + 8]);
        [V1 + c] = w(w[V0 + c]);
        [V1 + 10] = w(w[V0 + 10]);
        [V1 + 14] = w(w[V0 + 14]);
        [V1 + 18] = w(w[V0 + 18]);
        [V1 + 1c] = w(w[V0 + 1c]);

        A0 = w[model_data + 20];
        [A0 + 14] = w(w[A0 + 14] + h[model_data + 74]);
        [A0 + 18] = w(w[A0 + 18] + h[model_data + 76]);
        [A0 + 1c] = w(w[A0 + 1c] + h[model_data + 78]);
    }
    else
    {
        800BA6A0	lw     v1, $0020(s3)
        800BA6A4	lhu    v0, $0024(s3)
        800BA6A8	nop
        800BA6AC	sh     v0, $0000(v1)
        800BA6B0	lhu    v0, $0026(s3)
        800BA6B4	lw     v1, $0020(s3)
        800BA6B8	subu   v0, zero, v0
        800BA6BC	sh     v0, $0002(v1)
        800BA6C0	lhu    v0, $0028(s3)
        800BA6C4	lw     v1, $0020(s3)
        800BA6C8	subu   v0, zero, v0
        800BA6CC	sh     v0, $0004(v1)
        800BA6D0	lw     v1, $0020(s3)
        800BA6D4	lhu    v0, $002a(s3)
        800BA6D8	nop
        800BA6DC	sh     v0, $0006(v1)
        800BA6E0	lhu    v0, $002c(s3)
        800BA6E4	lw     v1, $0020(s3)
        800BA6E8	subu   v0, zero, v0
        800BA6EC	sh     v0, $0008(v1)
        800BA6F0	lhu    v0, $002e(s3)
        800BA6F4	lw     v1, $0020(s3)
        800BA6F8	subu   v0, zero, v0
        800BA6FC	sh     v0, $000a(v1)
        800BA700	lw     v1, $0020(s3)
        800BA704	lhu    v0, $0030(s3)
        800BA708	nop
        800BA70C	sh     v0, $000c(v1)
        800BA710	lhu    v0, $0032(s3)
        800BA714	lw     v1, $0020(s3)
        800BA718	subu   v0, zero, v0
        800BA71C	sh     v0, $000e(v1)
        800BA720	lhu    v0, $0034(s3)
        800BA724	lw     v1, $0020(s3)
        800BA728	subu   v0, zero, v0
        800BA72C	sh     v0, $0010(v1)
        800BA730	lw     v1, $0020(s3)
        800BA734	lw     v0, $0038(s3)
        800BA738	nop
        800BA73C	sw     v0, $0014(v1)
        800BA740	lw     v1, $0020(s3)
        800BA744	lw     v0, $003c(s3)
        800BA748	nop
        800BA74C	sw     v0, $0018(v1)
        800BA750	lw     v1, $0020(s3)
        800BA754	lw     v0, $0040(s3)
        800BA75C	sw     v0, $001c(v1)
    }
}
else
{
    800BA760	lw     v0, $0008(s3)
    800BA764	lui    s2, $1f80
    800BA768	lbu    v0, $0002(v0)
    800BA76C	nop
    800BA770	sh     v0, $0090(sp)
    800BA774	sltiu  v0, v0, $001f
    800BA778	bne    v0, zero, Lba784 [$800ba784]
    800BA77C	ori    s2, s2, $0018
    800BA780	lw     s2, $0020(s3)

    Lba784:	; 800BA784
    800BA784	nop
    800BA788	addu   s1, s2, zero
    800BA78C	lui    t7, $1f80
    800BA790	ori    t7, t7, $0008
    800BA794	sw     t7, $0098(sp)
    800BA798	sw     zero, $0000(t7)
    800BA79C	sw     zero, $0004(t7)
    800BA7A0	lw     s6, $000c(s0)
    800BA7A4	lhu    v0, $000a(s0)
    800BA7A8	lw     s4, $0010(s0)
    800BA7AC	andi   v0, v0, $0001
    800BA7B0	beq    v0, zero, Lba7c4 [$800ba7c4]
    800BA7B4	lui    s7, $1f80
    800BA7B8	lh     v0, $0004(s0)

    Lba7bc:	; 800BA7BC
    800BA7BC	j      Lba7e4 [$800ba7e4]
    800BA7C0	sw     v0, $0014(s2)

    Lba7c4:	; 800BA7C4
    800BA7C4	andi   v0, s5, $ffff
    800BA7C8	lhu    v1, $0004(s0)
    800BA7CC	sll    v0, v0, $01

    funcba7d0:	; 800BA7D0
    800BA7D0	addu   v1, s0, v1
    800BA7D4	addu   v0, v0, v1
    800BA7D8	lh     v0, $0000(v0)
    800BA7DC	nop
    800BA7E0	sw     v0, $0014(s2)

    Lba7e4:	; 800BA7E4
    800BA7E4	lhu    v0, $000a(s0)
    800BA7E8	nop
    800BA7EC	andi   v0, v0, $0002
    800BA7F0	beq    v0, zero, Lba804 [$800ba804]
    800BA7F4	andi   v0, s5, $ffff
    800BA7F8	lh     v0, $0006(s0)
    800BA7FC	j      Lba820 [$800ba820]
    800BA800	sw     v0, $0018(s1)

    Lba804:	; 800BA804
    800BA804	lhu    v1, $0006(s0)
    800BA808	sll    v0, v0, $01
    800BA80C	addu   v1, s0, v1
    800BA810	addu   v0, v0, v1
    800BA814	lh     v0, $0000(v0)
    800BA818	nop
    800BA81C	sw     v0, $0018(s1)

    Lba820:	; 800BA820
    800BA820	lhu    v0, $000a(s0)
    800BA824	nop
    800BA828	andi   v0, v0, $0004
    800BA82C	beq    v0, zero, Lba840 [$800ba840]
    800BA830	andi   v0, s5, $ffff
    800BA834	lh     v0, $0008(s0)
    800BA838	j      Lba85c [$800ba85c]
    800BA83C	sw     v0, $001c(s1)

    Lba840:	; 800BA840
    800BA840	lhu    v1, $0008(s0)
    800BA844	sll    v0, v0, $01

    Lba848:	; 800BA848
    800BA848	addu   v1, s0, v1
    800BA84C	addu   v0, v0, v1
    800BA850	lh     v0, $0000(v0)
    800BA854	nop

    funcba858:	; 800BA858
    800BA858	sw     v0, $001c(s1)

    Lba85c:	; 800BA85C
    800BA85C	lhu    t8, $0090(sp)
    800BA860	nop
    800BA864	sll    v0, t8, $05
    800BA868	addu   v0, s2, v0
    800BA86C	sw     v0, $0088(sp)

    loopba870:	; 800BA870
    800BA870	lw     t3, $0004(s6)
    800BA874	lw     t2, $0000(s6)
    800BA878	srl    t4, t3, $10
    800BA87C	andi   t5, t4, $0001
    800BA880	bne    t5, zero, Lba894 [$800ba894]
    800BA884	andi   t1, t2, $ffff
    800BA888	addu   t1, t1, s0
    800BA88C	addu   t1, t1, s5
    800BA890	lb     t1, $0000(t1)

    Lba894:	; 800BA894
    800BA894	andi   t5, t4, $0002
    800BA898	sll    t1, t1, $04
    800BA89C	bne    t5, zero, Lba8b0 [$800ba8b0]
    800BA8A0	srl    t2, t2, $10
    800BA8A4	addu   t2, t2, s0
    800BA8A8	addu   t2, t2, s5
    800BA8AC	lb     t2, $0000(t2)

    Lba8b0:	; 800BA8B0
    800BA8B0	andi   t5, t4, $0004
    800BA8B4	sll    t2, t2, $14
    800BA8B8	bne    t5, zero, Lba8cc [$800ba8cc]
    800BA8BC	andi   t3, t3, $ffff
    800BA8C0	addu   t3, t3, s0
    800BA8C4	addu   t3, t3, s5
    800BA8C8	lb     t3, $0000(t3)

    Lba8cc:	; 800BA8CC
    800BA8CC	andi   t1, t1, $ffff
    800BA8D0	or     t5, t2, t1
    800BA8D4	sll    t3, t3, $04
    800BA8D8	sw     t5, $0000(s7)
    800BA8DC	sw     t3, $0004(s7)
    800BA8E0	beq    s4, zero, Lba99c [$800ba99c]
    800BA8E4	nop
    800BA8E8	srl    t0, s5, $01
    800BA8EC	andi   t6, s5, $0001

    funcba8f0:	; 800BA8F0
    800BA8F0	lw     t3, $0004(s4)
    800BA8F4	lw     t2, $0000(s4)
    800BA8F8	srl    t4, t3, $10
    800BA8FC	andi   t5, t4, $0001
    800BA900	bne    t5, zero, Lba920 [$800ba920]
    800BA904	andi   t1, t2, $ffff
    800BA908	addu   t1, t1, s0
    800BA90C	addu   t1, t1, t0
    800BA910	lb     t1, $0000(t1)
    800BA914	beq    t6, zero, Lba920 [$800ba920]
    800BA918	nop
    800BA91C	srl    t1, t1, $04

    Lba920:	; 800BA920
    800BA920	andi   t5, t4, $0002
    800BA924	andi   t1, t1, $000f
    800BA928	bne    t5, zero, Lba948 [$800ba948]
    800BA92C	srl    t2, t2, $10
    800BA930	addu   t2, t2, s0
    800BA934	addu   t2, t2, t0

    funcba938:	; 800BA938
    800BA938	lb     t2, $0000(t2)
    800BA93C	beq    t6, zero, Lba948 [$800ba948]
    800BA940	nop
    800BA944	srl    t2, t2, $04

    Lba948:	; 800BA948
    800BA948	andi   t5, t4, $0004
    800BA94C	andi   t2, t2, $000f
    800BA950	bne    t5, zero, Lba970 [$800ba970]
    800BA954	andi   t3, t3, $ffff
    800BA958	addu   t3, t3, s0
    800BA95C	addu   t3, t3, t0
    800BA960	lb     t3, $0000(t3)
    800BA964	beq    t6, zero, Lba970 [$800ba970]
    800BA968	nop
    800BA96C	srl    t3, t3, $04

    Lba970:	; 800BA970
    800BA970	andi   t5, t4, $0004
    800BA974	andi   t3, t3, $000f
    800BA978	lw     t4, $0000(s7)
    800BA97C	lw     t5, $0004(s7)
    800BA980	or     t4, t4, t1
    800BA984	sll    t2, t2, $10
    800BA988	or     t4, t4, t2
    800BA98C	or     t5, t5, t3
    800BA990	sw     t4, $0000(s7)

    funcba994:	; 800BA994
    800BA994	sw     t5, $0004(s7)
    800BA998	addiu  s4, s4, $0008

    Lba99c:	; 800BA99C
    800BA99C	addiu  s6, s6, $0008
    800BA9A0	addu   a0, s7, zero
    800BA9A4	jal    system_create_matrix_from_angle_with_gte [$80031264]
    800BA9A8	addu   a1, s1, zero
    800BA9AC	lw     t7, $0088(sp)
    800BA9B0	addiu  s1, s1, $0020
    800BA9B4	sltu   v0, s1, t7
    800BA9B8	bne    v0, zero, loopba870 [$800ba870]
    800BA9BC	nop
    800BA9C0	lw     v1, $001c(s3)
    800BA9C4	nop
    800BA9C8	beq    v1, zero, Lbaa6c [$800baa6c]
    800BA9CC	addiu  v0, s3, $0024
    800BA9D0	lbu    v0, $0004(s3)
    800BA9D4	lw     v1, $0020(v1)
    800BA9D8	sll    v0, v0, $05
    800BA9DC	addu   v0, v0, v1
    800BA9E0	lw     v1, $0000(v0)
    800BA9E4	lw     a0, $0004(v0)
    800BA9E8	lw     a1, $0008(v0)
    800BA9EC	lw     v0, $000c(v0)
    800BA9F0	sw     v1, $0000(s2)
    800BA9F4	sw     a0, $0004(s2)
    800BA9F8	sw     a1, $0008(s2)
    800BA9FC	sw     v0, $000c(s2)
    800BAA00	lw     v1, $001c(s3)
    800BAA04	lbu    v0, $0004(s3)
    800BAA08	lw     v1, $0020(v1)
    800BAA0C	sll    v0, v0, $05
    800BAA10	addu   v0, v0, v1
    800BAA14	lw     v1, $0010(v0)
    800BAA18	lw     a0, $0014(v0)
    800BAA1C	lw     a1, $0018(v0)
    800BAA20	lw     v0, $001c(v0)
    800BAA24	sw     v1, $0010(s2)

    funcbaa28:	; 800BAA28
    800BAA28	sw     a0, $0014(s2)
    800BAA2C	sw     a1, $0018(s2)
    800BAA30	sw     v0, $001c(s2)
    800BAA34	lh     v1, $0074(s3)
    800BAA38	addu   v0, a0, zero
    800BAA3C	addu   v0, v0, v1
    800BAA40	sw     v0, $0014(s2)
    800BAA44	lh     v1, $0076(s3)
    800BAA48	addu   v0, a1, zero
    800BAA4C	addu   v0, v0, v1
    800BAA50	sw     v0, $0018(s2)
    800BAA54	lh     v1, $0078(s3)
    800BAA58	lw     v0, $001c(s2)
    800BAA5C	nop
    800BAA60	addu   v0, v0, v1
    800BAA64	j      Lbab90 [$800bab90]
    800BAA68	sw     v0, $001c(s2)

    Lbaa6c:	; 800BAA6C
    800BAA6C	lw     t4, $0000(v0)
    800BAA70	lw     t5, $0004(v0)
    800BAA74	ctc2   t4,vxy0
    800BAA78	ctc2   t5,vz0
    800BAA7C	lw     t4, $0008(v0)
    800BAA80	lw     t5, $000c(v0)
    800BAA84	lw     t6, $0010(v0)
    800BAA88	ctc2   t4,vxy1
    800BAA8C	ctc2   t5,vz1
    800BAA90	ctc2   t6,vxy2
    800BAA94	lw     t4, $0014(v0)
    800BAA98	lw     t5, $0018(v0)
    800BAA9C	ctc2   t4,vz2
    800BAAA0	lw     t6, $001c(v0)
    800BAAA4	ctc2   t5,rgb
    800BAAA8	ctc2   t6,otz
    800BAAAC	lhu    t4, $0000(s2)
    800BAAB0	lhu    t5, $0006(s2)
    800BAAB4	lhu    t6, $000c(s2)
    800BAAB8	mtc2   t4,l13l21
    800BAABC	mtc2   t5,l22l23
    800BAAC0	mtc2   t6,l31l32
    800BAAC4	addiu  v1, s2, $0002
    800BAAC8	addiu  v0, s2, $0004
    800BAACC	gte_func18t1,dqb
    800BAAD0	mfc2   t4,l13l21
    800BAAD4	mfc2   t5,l22l23
    800BAAD8	mfc2   t6,l31l32
    800BAADC	sh     t4, $0000(s2)
    800BAAE0	sh     t5, $0006(s2)

    funcbaae4:	; 800BAAE4
    800BAAE4	sh     t6, $000c(s2)
    800BAAE8	lhu    t4, $0000(v1)
    800BAAEC	lhu    t5, $0006(v1)
    800BAAF0	lhu    t6, $000c(v1)
    800BAAF4	mtc2   t4,l13l21
    800BAAF8	mtc2   t5,l22l23
    800BAAFC	mtc2   t6,l31l32
    800BAB00	nop
    800BAB04	nop
    800BAB08	gte_func18t1,dqb
    800BAB0C	mfc2   t4,l13l21
    800BAB10	mfc2   t5,l22l23
    800BAB14	mfc2   t6,l31l32
    800BAB18	sh     t4, $0000(v1)
    800BAB1C	sh     t5, $0006(v1)
    800BAB20	sh     t6, $000c(v1)
    800BAB24	lhu    t4, $0000(v0)
    800BAB28	lhu    t5, $0006(v0)
    800BAB2C	lhu    t6, $000c(v0)
    800BAB30	mtc2   t4,l13l21
    800BAB34	mtc2   t5,l22l23
    800BAB38	mtc2   t6,l31l32
    800BAB3C	addiu  v1, s2, $0014
    800BAB40	nop
    800BAB44	gte_func18t1,dqb
    800BAB48	mfc2   t4,l13l21
    800BAB4C	mfc2   t5,l22l23
    800BAB50	mfc2   t6,l31l32
    800BAB54	sh     t4, $0000(v0)
    800BAB58	sh     t5, $0006(v0)
    800BAB5C	sh     t6, $000c(v0)
    800BAB60	lhu    t5, $0004(v1)
    800BAB64	lhu    t4, $0000(v1)
    800BAB68	sll    t5, t5, $10
    800BAB6C	or     t4, t4, t5
    800BAB70	mtc2   t4,r11r12
    800BAB74	lwc2   at, $0008(v1)
    800BAB78	nop
    800BAB7C	nop
    800BAB80	gte_func18t0,r11r12
    800BAB84	swc2   t9, $0000(v1)
    800BAB88	swc2   k0, $0004(v1)
    800BAB8C	swc2   k1, $0008(v1)

    Lbab90:	; 800BAB90
    800BAB90	addiu  s1, s2, $0020
    800BAB94	addiu  t8, zero, $0001
    800BAB98	sw     t8, $0080(sp)
    800BAB9C	lw     v1, $0008(s3)
    800BABA0	addiu  t7, sp, $0040
    800BABA4	sw     t7, $009c(sp)
    800BABA8	lw     v0, $000c(v1)

    funcbabac:	; 800BABAC
    800BABAC	lbu    v1, $0006(v1)
    800BABB0	addiu  s4, v0, $0004
    800BABB4	lbu    v0, $0003(s4)
    800BABB8	addiu  s7, sp, $0010
    800BABBC	sw     v1, $0084(sp)
    800BABC0	sll    v0, v0, $05
    800BABC4	addu   fp, s2, v0

    Lbabc8:	; 800BABC8
    800BABC8	lw     t4, $0000(fp)
    800BABCC	lw     t5, $0004(fp)
    800BABD0	ctc2   t4,vxy0
    800BABD4	ctc2   t5,vz0
    800BABD8	lw     t4, $0008(fp)
    800BABDC	lw     t5, $000c(fp)
    800BABE0	lw     t6, $0010(fp)
    800BABE4	ctc2   t4,vxy1
    800BABE8	ctc2   t5,vz1
    800BABEC	ctc2   t6,vxy2
    800BABF0	lhu    t4, $0000(s1)
    800BABF4	lhu    t5, $0006(s1)
    800BABF8	lhu    t6, $000c(s1)
    800BABFC	mtc2   t4,l13l21
    800BAC00	mtc2   t5,l22l23
    800BAC04	mtc2   t6,l31l32
    800BAC08	nop
    800BAC0C	nop
    800BAC10	gte_func18t1,dqb
    800BAC14	lw     t4, $0014(fp)
    800BAC18	lw     t5, $0018(fp)
    800BAC1C	ctc2   t4,vz2
    800BAC20	lw     t6, $001c(fp)
    800BAC24	ctc2   t5,rgb
    800BAC28	ctc2   t6,otz
    800BAC2C	mfc2   t4,l13l21
    800BAC30	mfc2   t5,l22l23
    800BAC34	mfc2   t6,l31l32
    800BAC38	sh     t4, $0000(s1)
    800BAC3C	sh     t5, $0006(s1)
    800BAC40	sh     t6, $000c(s1)
    800BAC44	addiu  s6, s1, $0002
    800BAC48	lhu    t4, $0000(s6)
    800BAC4C	lhu    t5, $0006(s6)
    800BAC50	lhu    t6, $000c(s6)
    800BAC54	mtc2   t4,l13l21
    800BAC58	mtc2   t5,l22l23
    800BAC5C	mtc2   t6,l31l32
    800BAC60	nop
    800BAC64	nop
    800BAC68	gte_func18t1,dqb
    800BAC6C	lh     v0, $0000(s4)
    800BAC70	lw     t8, $0098(sp)
    800BAC74	nop
    800BAC78	sw     v0, $0008(t8)
    800BAC7C	mfc2   t4,l13l21
    800BAC80	mfc2   t5,l22l23
    800BAC84	mfc2   t6,l31l32
    800BAC88	sh     t4, $0000(s6)
    800BAC8C	sh     t5, $0006(s6)
    800BAC90	sh     t6, $000c(s6)
    800BAC94	addiu  s5, s1, $0004
    800BAC98	lhu    t4, $0000(s5)
    800BAC9C	lhu    t5, $0006(s5)
    800BACA0	lhu    t6, $000c(s5)
    800BACA4	mtc2   t4,l13l21
    800BACA8	mtc2   t5,l22l23
    800BACAC	mtc2   t6,l31l32
    800BACB0	nop

    funcbacb4:	; 800BACB4
    800BACB4	nop
    800BACB8	gte_func18t1,dqb
    800BACBC	addiu  s4, s4, $0004
    800BACC0	mfc2   t4,l13l21
    800BACC4	mfc2   t5,l22l23
    800BACC8	mfc2   t6,l31l32
    800BACCC	sh     t4, $0000(s5)
    800BACD0	sh     t5, $0006(s5)
    800BACD4	sh     t6, $000c(s5)
    800BACD8	lhu    t5, $0004(t8)
    800BACDC	lhu    t4, $0000(t8)
    800BACE0	sll    t5, t5, $10
    800BACE4	or     t4, t4, t5
    800BACE8	mtc2   t4,r11r12
    800BACEC	lwc2   at, $0008(t8)
    800BACF0	nop
    800BACF4	nop
    800BACF8	gte_func18t0,r11r12
    800BACFC	lbu    v0, $0003(s4)
    800BAD00	nop
    800BAD04	sll    v0, v0, $05
    800BAD08	addu   fp, s2, v0
    800BAD0C	addiu  v0, s1, $0014
    800BAD10	swc2   t9, $0000(v0)
    800BAD14	swc2   k0, $0004(v0)
    800BAD18	swc2   k1, $0008(v0)
    800BAD1C	lw     t7, $0084(sp)
    800BAD20	lw     t8, $0080(sp)
    800BAD24	nop
    800BAD28	bne    t7, t8, Lbafc4 [$800bafc4]
    800BAD2C	addiu  t7, zero, $1000
    800BAD30	sw     zero, $0020(sp)
    800BAD34	sw     t7, $0024(sp)
    800BAD38	sw     zero, $0028(sp)
    800BAD3C	lh     v1, $0048(s3)

    Lbad40:	; 800BAD40
    800BAD40	lw     v0, $0014(s1)
    800BAD44	nop
    800BAD48	subu   v0, v0, v1
    800BAD4C	sw     v0, $0010(sp)

    Lbad50:	; 800BAD50
    800BAD50	lh     v1, $004a(s3)
    800BAD54	lw     v0, $0018(s1)
    800BAD58	addiu  a0, sp, $0010
    800BAD5C	subu   v0, v0, v1
    800BAD60	sw     v0, $0014(sp)

    funcbad64:	; 800BAD64
    800BAD64	lh     v1, $004c(s3)
    800BAD68	lw     v0, $001c(s1)
    800BAD6C	lw     a1, $009c(sp)
    800BAD70	subu   v0, v0, v1
    800BAD74	jal    func62c2c [$80062c2c]
    800BAD78	sw     v0, $0018(sp)
    800BAD7C	addiu  v0, sp, $0020
    800BAD80	lw     t4, $0000(v0)
    800BAD84	lw     t5, $0004(v0)
    800BAD88	ctc2   t4,vxy0
    800BAD8C	lw     t6, $0008(v0)
    800BAD90	ctc2   t5,vxy1
    800BAD94	ctc2   t6,vxy2
    800BAD98	lw     t8, $009c(sp)
    800BAD9C	nop
    800BADA0	lwc2   t3, $0008(t8)
    800BADA4	lwc2   t1, $0000(t8)
    800BADA8	lwc2   t2, $0004(t8)
    800BADAC	nop
    800BADB0	nop
    800BADB4	gte_func27t8,r11r12
    800BADB8	swc2   t9, $0000(s7)
    800BADBC	swc2   k0, $0004(s7)
    800BADC0	swc2   k1, $0008(s7)
    800BADC4	addu   a0, s7, zero
    800BADC8	addiu  s0, sp, $0030
    800BADCC	jal    func62c2c [$80062c2c]
    800BADD0	addu   a1, s0, zero

    funcbadd4:	; 800BADD4
    800BADD4	lw     t4, $0000(s0)
    800BADD8	lw     t5, $0004(s0)
    800BADDC	ctc2   t4,vxy0
    800BADE0	lw     t6, $0008(s0)
    800BADE4	ctc2   t5,vxy1
    800BADE8	ctc2   t6,vxy2
    800BADEC	lw     t7, $009c(sp)
    800BADF0	nop
    800BADF4	lwc2   t3, $0008(t7)
    800BADF8	lwc2   t1, $0000(t7)
    800BADFC	lwc2   t2, $0004(t7)
    800BAE00	nop
    800BAE04	nop
    800BAE08	gte_func27t8,r11r12
    800BAE0C	swc2   t9, $0000(s7)

    Lbae10:	; 800BAE10
    800BAE10	swc2   k0, $0004(s7)
    800BAE14	swc2   k1, $0008(s7)
    800BAE18	addu   a0, s7, zero
    800BAE1C	jal    func62c2c [$80062c2c]
    800BAE20	addiu  a1, sp, $0050
    800BAE24	lhu    v0, $0030(sp)
    800BAE28	nop
    800BAE2C	sh     v0, $0000(s1)
    800BAE30	lhu    v0, $0040(sp)
    800BAE34	nop
    800BAE38	sh     v0, $0002(s1)
    800BAE3C	lhu    v0, $0050(sp)
    800BAE40	nop

    funcbae44:	; 800BAE44
    800BAE44	sh     v0, $0004(s1)
    800BAE48	lhu    v0, $0034(sp)
    800BAE4C	nop
    800BAE50	sh     v0, $0006(s1)
    800BAE54	lhu    v0, $0044(sp)
    800BAE58	nop
    800BAE5C	sh     v0, $0008(s1)
    800BAE60	lhu    v0, $0054(sp)
    800BAE64	nop
    800BAE68	sh     v0, $000a(s1)
    800BAE6C	lhu    v0, $0038(sp)
    800BAE70	nop
    800BAE74	sh     v0, $000c(s1)
    800BAE78	lhu    v0, $0048(sp)
    800BAE7C	nop
    800BAE80	sh     v0, $000e(s1)
    800BAE84	lhu    v0, $0058(sp)
    800BAE88	nop
    800BAE8C	sh     v0, $0010(s1)
    800BAE90	lhu    v0, $0000(s3)

    Lbae94:	; 800BAE94
    800BAE94	nop
    800BAE98	andi   v0, v0, $0002
    800BAE9C	beq    v0, zero, Lbafc4 [$800bafc4]
    800BAEA0	addiu  t8, zero, $1000
    800BAEA4	lhu    v0, $0054(s3)

    Lbaea8:	; 800BAEA8
    800BAEA8	addu   t7, t8, zero
    800BAEAC	sw     t8, $0060(sp)
    800BAEB0	sw     zero, $0064(sp)
    800BAEB4	sw     t7, $0068(sp)
    800BAEB8	sw     zero, $006c(sp)
    800BAEBC	sw     t8, $0070(sp)
    800BAEC0	sh     v0, $0060(sp)
    800BAEC4	lw     t4, $0000(s1)
    800BAEC8	lw     t5, $0004(s1)
    800BAECC	ctc2   t4,vxy0

    Lbaed0:	; 800BAED0
    800BAED0	ctc2   t5,vz0
    800BAED4	lw     t4, $0008(s1)
    800BAED8	lw     t5, $000c(s1)
    800BAEDC	lw     t6, $0010(s1)
    800BAEE0	ctc2   t4,vxy1
    800BAEE4	ctc2   t5,vz1
    800BAEE8	ctc2   t6,vxy2
    800BAEEC	addiu  v0, sp, $0060
    800BAEF0	lhu    t4, $0000(v0)
    800BAEF4	lhu    t5, $0006(v0)
    800BAEF8	lhu    t6, $000c(v0)
    800BAEFC	mtc2   t4,l13l21
    800BAF00	mtc2   t5,l22l23
    800BAF04	mtc2   t6,l31l32
    800BAF08	nop
    800BAF0C	nop
    800BAF10	gte_func18t1,dqb
    800BAF14	lhu    v0, $0056(s3)
    800BAF18	nop
    800BAF1C	sh     v0, $0068(sp)
    800BAF20	mfc2   t4,l13l21
    800BAF24	mfc2   t5,l22l23
    800BAF28	mfc2   t6,l31l32
    800BAF2C	sh     t4, $0000(s1)
    800BAF30	sh     t5, $0006(s1)
    800BAF34	sh     t6, $000c(s1)
    800BAF38	addiu  v0, sp, $0062

    funcbaf3c:	; 800BAF3C
    800BAF3C	lhu    t4, $0000(v0)
    800BAF40	lhu    t5, $0006(v0)
    800BAF44	lhu    t6, $000c(v0)
    800BAF48	mtc2   t4,l13l21
    800BAF4C	mtc2   t5,l22l23
    800BAF50	mtc2   t6,l31l32
    800BAF54	nop
    800BAF58	nop
    800BAF5C	gte_func18t1,dqb
    800BAF60	lhu    v0, $0058(s3)
    800BAF64	nop
    800BAF68	sh     v0, $0070(sp)
    800BAF6C	mfc2   t4,l13l21

    Lbaf70:	; 800BAF70
    800BAF70	mfc2   t5,l22l23
    800BAF74	mfc2   t6,l31l32
    800BAF78	sh     t4, $0000(s6)
    800BAF7C	sh     t5, $0006(s6)
    800BAF80	sh     t6, $000c(s6)
    800BAF84	addiu  v0, sp, $0064
    800BAF88	lhu    t4, $0000(v0)
    800BAF8C	lhu    t5, $0006(v0)
    800BAF90	lhu    t6, $000c(v0)
    800BAF94	mtc2   t4,l13l21
    800BAF98	mtc2   t5,l22l23
    800BAF9C	mtc2   t6,l31l32
    800BAFA0	nop
    800BAFA4	nop
    800BAFA8	gte_func18t1,dqb
    800BAFAC	mfc2   t4,l13l21
    800BAFB0	mfc2   t5,l22l23
    800BAFB4	mfc2   t6,l31l32
    800BAFB8	sh     t4, $0000(s5)
    800BAFBC	sh     t5, $0006(s5)
    800BAFC0	sh     t6, $000c(s5)

    Lbafc4:	; 800BAFC4
    800BAFC4	addiu  s1, s1, $0020
    800BAFC8	lw     t7, $0080(sp)
    800BAFCC	lw     t8, $0088(sp)
    800BAFD0	addiu  t7, t7, $0001
    800BAFD4	sltu   v0, s1, t8

    Lbafd8:	; 800BAFD8
    800BAFD8	bne    v0, zero, Lbabc8 [$800babc8]
    800BAFDC	sw     t7, $0080(sp)
    800BAFE0	lhu    t7, $0090(sp)
    800BAFE4	nop
    800BAFE8	sltiu  v0, t7, $001f

    funcbafec:	; 800BAFEC
    800BAFEC	beq    v0, zero, Lbb060 [$800bb060]
    800BAFF0	nop
    800BAFF4	lw     s1, $0020(s3)
    800BAFF8	addiu  a0, s2, $001c
    800BAFFC	addiu  v1, s1, $001c

    loopbb000:	; 800BB000
    800BB000	lw     v0, $0000(s2)
    800BB004	lw     a1, $ffe8(a0)
    800BB008	lw     a2, $ffec(a0)
    800BB00C	lw     a3, $fff0(a0)
    800BB010	addiu  s2, s2, $0020
    800BB014	sw     v0, $0000(s1)
    800BB018	addiu  s1, s1, $0020
    800BB01C	sw     a1, $ffe8(v1)
    800BB020	sw     a2, $ffec(v1)

    Lbb024:	; 800BB024
    800BB024	sw     a3, $fff0(v1)
    800BB028	lw     v0, $fff4(a0)
    800BB02C	lw     a1, $fff8(a0)
    800BB030	lw     a2, $fffc(a0)
    800BB034	lw     a3, $0000(a0)
    800BB038	addiu  a0, a0, $0020
    800BB03C	sw     v0, $fff4(v1)
    800BB040	sw     a1, $fff8(v1)
    800BB044	sw     a2, $fffc(v1)
    800BB048	sw     a3, $0000(v1)
    800BB04C	lw     t8, $0088(sp)
    800BB050	nop
    800BB054	sltu   v0, s2, t8
    800BB058	bne    v0, zero, loopbb000 [$800bb000]
    800BB05C	addiu  v1, v1, $0020
}
Lbb060:	; 800BB060
////////////////////////////////