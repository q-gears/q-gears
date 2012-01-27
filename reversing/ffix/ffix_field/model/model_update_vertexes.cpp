////////////////////////////////
// field_model_rasterize_3d_vertexes
model_data = A0;
part_id = A1;
model_file = w[model_data + 8];
bone_matrixes = w[model_data + 20];
parts_data = w[model_file + 10];



V1 = w[8006794c];
V0 = w[V1 + 1c];
H = hu[V0 + a]; // Projection plane distance



number_of_bones = bu[model_file + 2];
if( number_of_bones != 0 )
{
    vertex_id = 0;

    bone_id = 0;
    Lb6208:	; 800B6208
        vertex_groups = w[parts_data + part_id * 28 + 14];
        vertex_number = hu[vertex_groups + bone_id * 2];
        if( vertex_number != 0 )
        {
            // set camera matrix
            V0 = w[8006794c];
            V0 = w[V0 + 1c];
            R11R12 = w[V0 + 18];
            R13R21 = w[V0 + 1c];
            R22R23 = w[V0 + 20];
            R31R32 = w[V0 + 24];
            R33 = w[V0 + 28];
            TRX = w[V0 + 2c];
            TRY = w[V0 + 30];
            TRZ = w[V0 + 34];

            IR1 = hu[bone_matrixes + bone_id * 20 + 0];
            IR2 = hu[bone_matrixes + bone_id * 20 + 6];
            IR3 = hu[bone_matrixes + bone_id * 20 + c];
            gte_rtir12; // ir * rotmatrix.
            [SP + 0] = h(IR1);
            [SP + 6] = h(IR2);
            [SP + c] = h(IR3);

            IR1 = hu[bone_matrixes + bone_id * 20 + 2];
            IR2 = hu[bone_matrixes + bone_id * 20 + 8];
            IR3 = hu[bone_matrixes + bone_id * 20 + e];
            gte_rtir12; // ir * rotmatrix.
            [SP + 2] = h(IR1);
            [SP + 8] = h(IR2);
            [SP + e] = h(IR3);

            IR1 = hu[bone_matrixes + bone_id * 20 + 4];
            IR2 = hu[bone_matrixes + bone_id * 20 + a];
            IR3 = hu[bone_matrixes + bone_id * 20 + 10];
            gte_rtir12; // ir * rotmatrix.
            [SP + 4] = h(IR1);
            [SP + a] = h(IR2);
            [SP + 10] = h(IR3);

            VXY0 = (hu[bone_matrixes + bone_id * 20 + 18] << 10) | hu[bone_matrixes + bone_id * 20 + 14];
            VZ0 = w[bone_matrixes + bone_id * 20 + 1c];
            gte_rtv0tr; // v0 * rotmatrix + tr vector.
            [SP + 14] = w(MAC1);
            [SP + 18] = w(MAC2);
            [SP + 1c] = w(MAC3);



            R11R12 = w[SP + 0];
            R13R21 = w[SP + 4];
            R22R23 = w[SP + 8];
            R31R32 = w[SP + c];
            R33 = w[SP + 10];
            TRX = w[SP + 14];
            TRY = w[SP + 18];
            TRZ = w[SP + 1c];

            V1 = w[parts_data + part_id * 28 + 18] + vertex_id * 8; // offset ot vertex block for this abject + offset ot vertex
            T0 = 800711a8 + vertex_id * 4;
            A3 = 80070520 + vertex_id * 4;
            vertex_id = vertex_id + vertex_number;

            loopb63dc:	; 800B63DC
                VXY0 = w[V1 + 0];
                VZ0  = w[V1 + 4];
                VXY1 = w[V1 + 8];
                VZ1  = w[V1 + c];
                VXY2 = w[V1 + 10];
                VZ2  = w[V1 + 14];
                gte_RTPT; // Perspective transform on 3 points.
                [T0 + 0] = w(SXY0);
                [T0 + 4] = w(SXY1);
                [T0 + 8] = w(SXY2);
                [A3 + 0] = w(SZ1);
                [A3 + 4] = w(SZ2);
                [A3 + 8] = w(SZ3);

                V1 = V1 + 18;
                T0 = T0 + c;
                A3 = A3 + c;
                vertex_number = vertex_number - 3;
            800B641C	bgtz   vertex_number, loopb63dc [$800b63dc]
        }

        bone_id = bone_id + 1;
        V0 = bone_id < number_of_bones;
    800B6428	bne    v0, zero, Lb6208 [$800b6208]
}
////////////////////////////////



////////////////////////////////
// funcbb508
model_data = A0;
part_id = A1;

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = hu[V0 + a];
H = V0;

total_vertex = 0;
model_file = w[model_data + 8];
bone_data = w[model_data + 20];
number_of_bones = bu[model_file + 2];
parts_data = w[model_file + 10];
A2 = h[model_data + 5a];
vertex_data = w[parts_data + part_id * 28 + 18];



if( number_of_bones != 0 )
{
    bone_id = 0;
    loopbb57c:	; 800BB57C
        vertex_groups = w[parts_data + part_id * 28 + 14];
        number_of_vertex = hu[vertex_groups + bone_id * 2];

        if( number_of_vertex != 0 )
        {
            T0 = 800711a8 + total_vertex * 4;
            A3 = 80070520 + total_vertex * 4;



            R11R12 = w[bone_data + bone_id * 20 + 0];
            R13R21 = w[bone_data + bone_id * 20 + 4];
            R22R23 = w[bone_data + bone_id * 20 + 8];
            R31R32 = w[bone_data + bone_id * 20 + c];
            R33 = w[bone_data + bone_id * 20 + 10];
            TRX = w[bone_data + bone_id * 20 + 14];
            TRY = w[bone_data + bone_id * 20 + 18];
            TRZ = w[bone_data + bone_id * 20 + 1c];



            V1 = 0;
            loopbb5e8:	; 800BB5E8
                VXY0 = w[vertex_data + 0];
                VZ0 = w[vertex_data + 4];
                gte_rtv0tr; // v0 * rotmatrix + tr vector.
                [T0 + 0] = h(IR1);
                [T0 + 2] = h(IR2);
                [A3 + 0] = w(IR3);

                if( h[T0 + 2] >= A2 )
                {
                    [T0 + 2] = h(A2);
                    [A3 + 2] = h(1000);
                }

                T0 = T0 + 4;
                A3 = A3 + 4;
                vertex_data = vertex_data + 8;

                V1 = V1 + 1;
                V0 = V1 < number_of_vertex;
            800BB638	bne    v0, zero, loopbb5e8 [$800bb5e8]



            // set camera matrix
            V0 = w[8006794c];
            V0 = w[V0 + 1c];
            R11R12 = w[V0 + 18];
            R13R21 = w[V0 + 1c];
            R22R23 = w[V0 + 20];
            R31R32 = w[V0 + 24];
            R33 = w[V0 + 28];
            TRX = w[V0 + 2c];
            TRY = w[V0 + 30];
            TRZ = w[V0 + 34];

            T0 = 800711a8 + total_vertex * 4;
            A3 = 80070520 + total_vertex * 4;



            V1 = 0;
            loopbb6a0:	; 800BB6A0
                VXY0 = w[T0 + 0];
                VZ0 = w[A3 + 0];
                VXY1 = w[T0 + 4];
                VZ1 = w[A3 + 4];
                VXY2 = w[T0 + 8];
                VZ2 = w[A3 + 8];
                gte_RTPT; // Perspective transform on 3 points.
                [T0 + 0] = w(SXY0);
                [T0 + 4] = w(SXY1);
                [T0 + 8] = w(SXY2);
                [A3 + 0] = h(SZ1);
                [A3 + 4] = h(SZ2);
                [A3 + 8] = h(SZ3);

                T0 = T0 + c;
                A3 = A3 + c;

                V1 = V1 + 3;
                V0 = V1 < number_of_vertex;
            800BB6F0	bne    v0, zero, loopbb6a0 [$800bb6a0]



            total_vertex = total_vertex + number_of_vertex;
        }

        bone_id = bone_id + 1;
        V0 = bone_id < number_of_bones;
    800BB700	bne    v0, zero, loopbb57c [$800bb57c]
}
////////////////////////////////



////////////////////////////////
// funcb5958
object_id = A1;
T8 = w[A0 + 44];
A0 = w[A0 + 8]; // pointer to model file
A2 = w[T8 + A1 * c + 4];
T8 = w[A0 + 10] + A1 * 28; // pointer to object
T3 = 800711a8; // screen coords
T4 = 80070520; // depth

800B59C4	lui    v0, $8006
800B59C8	addiu  v0, v0, $794c
800B59CC	lw     v0, $0000(v0)
800B59D0	nop
800B59D4	lw     v0, $001c(v0)
800B59D8	nop
800B59DC	lbu    v1, $0008(v0)
800B59E0	addiu  v0, v0, $0010
800B59E4	sll    v1, v1, $02
800B59E8	addu   v0, v0, v1
800B59EC	lw     s3, $0000(v0)
V0 = hu[T8 + 0];
if (V0 != 0)
{
    A2 = A2 + V0;
}

S3 = S3 + b[T8 + 13] * 4;

A1 = w[T8 + 1c]; // pointer to mesh block

number_of_quads = hu[T8 + 2]; // number of quads
if (number_of_quads != 0)
{
    loopb5a18:	; 800B5A18
        S0 = w[A1 + 0];
        S2 = w[A1 + 4];
        vertex1 = S0 & ffff;
        vertex2 = S0 >> 10;
        vertex3 = S2 & ffff;
        vertex4 = S2 >> 10;

        T5 = w[T3 + vertex1 * 4];
        T6 = w[T3 + vertex2 * 4];
        T7 = w[T3 + vertex3 * 4];

        if ((bu[A1 + 15] & 2) == 0)
        {
            SXY0 = T5;
            SXY1 = T6;
            SXY2 = T7;

            [A2 + 0] = w(09000000);

            gte_NCLIP; // Normal clipping.
            if (MAC0 <= 0)
            {
                continue;
            }
        }

        [A2 + 8] = w(w[T3 + vertex1 * 4]);
        [A2 + 10] = w(w[T3 + vertex2 * 4]);
        [A2 + 18] = w(w[T3 + vertex3 * 4]);
        [A2 + 20] = w(w[T3 + vertex4 * 4]);

        A3 = w[T4 + vertex1 * 4] + w[T4 + vertex2 * 4] + w[T4 + vertex3 * 4] + w[T4 + vertex4 * 4];
        A3 = A3 >> 4;
        A3 = A3 << 2;
        A3 = A3 + S3;

        S4 = w[A3];
        V0 = A2 << 8;
        V0 = V0 >> 8;
        [A2 + 0] = w(09000000 | S4);
        [A3] = w(V0);

        A2 = A2 + 28;
        A1 = A1 + 18;
        number_of_quads = number_of_quads - 1;
    800B5AFC	bgtz   t2, loopb5a18 [$800b5a18]
}



T2 = hu[T8 + 4];
if (T2 != 0)
{
    loopb5b10:	; 800B5B10
        800B5B10	lw     s0, $0000(a1)
        800B5B14	lhu    s1, $0004(a1)
        800B5B18	andi   t9, s0, $ffff
        800B5B1C	srl    s0, s0, $10
        800B5B20	lbu    s5, $0012(a1)
        800B5B24	sll    t9, t9, $02
        800B5B28	addu   v0, t3, t9
        800B5B2C	lw     t5, $0000(v0)
        800B5B30	sll    s0, s0, $02
        800B5B34	addu   v0, t3, s0
        800B5B38	lw     t6, $0000(v0)
        800B5B3C	sll    s1, s1, $02
        800B5B40	addu   v0, t3, s1
        800B5B44	andi   v1, s5, $0002
        800B5B48	bne    v1, zero, Lb5b74 [$800b5b74]
        800B5B4C	lw     t7, $0000(v0)
        800B5B50	mtc2   t5,l33
        800B5B54	mtc2   t6,rbk
        800B5B58	mtc2   t7,gbk
        800B5B5C	lui    s4, $0700
        800B5B60	sw     s4, $0000(a2)
        800B5B64	gte_func26zero,r11r12
        800B5B68	mfc2   v0,ofx
        800B5B6C	nop
        800B5B70	blez   v0, Lb5bd0 [$800b5bd0]

        Lb5b74:	; 800B5B74
        800B5B74	addu   v0, t4, t9
        800B5B78	lw     a3, $0000(v0)
        800B5B7C	addu   v0, t4, s0
        800B5B80	lw     t1, $0000(v0)
        800B5B84	addu   v0, t4, s1
        800B5B88	lw     s6, $0000(v0)
        800B5B8C	mtc2   a3,lr3lg1
        800B5B90	mtc2   t1,lg2lg3
        800B5B94	mtc2   s6,lb1lb2
        800B5B98	sw     t5, $0008(a2)
        800B5B9C	sw     t6, $0010(a2)
        800B5BA0	gte_func26t8,r11r12
        800B5BA4	mfc2   a3,trz
        800B5BA8	sw     t7, $0018(a2)
        800B5BAC	sll    a3, a3, $02
        800B5BB0	addu   a3, a3, s3
        800B5BB4	lw     s4, $0000(a3)
        800B5BB8	sll    v0, a2, $08
        800B5BBC	srl    v0, v0, $08
        800B5BC0	lui    at, $0700
        800B5BC4	or     s4, s4, at
        800B5BC8	sw     s4, $0000(a2)
        800B5BCC	sw     v0, $0000(a3)

        Lb5bd0:	; 800B5BD0
        800B5BD0	addiu  a2, a2, $0020
        800B5BD4	addi   t2, t2, $ffff (=-$1)
        800B5BDC	addi   a1, a1, $0014
    800B5BD8	bgtz   t2, loopb5b10 [$800b5b10]

}



T2 = hu[T8 + 6];
if (T2 != 0)
{
    loopb5bf0:	; 800B5BF0
        800B5BF0	lw     s0, $0000(a1)
        800B5BF4	lw     s2, $0004(a1)
        800B5BF8	andi   t9, s0, $ffff
        800B5BFC	srl    s0, s0, $10
        800B5C00	andi   s1, s2, $ffff
        800B5C04	lbu    s5, $001c(a1)
        800B5C08	sll    t9, t9, $02
        800B5C0C	addu   v0, t3, t9
        800B5C10	lw     t5, $0000(v0)
        800B5C14	sll    s0, s0, $02
        800B5C18	addu   v0, t3, s0
        800B5C1C	lw     t6, $0000(v0)
        800B5C20	sll    s1, s1, $02
        800B5C24	addu   v0, t3, s1
        800B5C28	lw     t7, $0000(v0)
        800B5C2C	andi   v1, s5, $0002
        800B5C30	bne    v1, zero, Lb5c5c [$800b5c5c]
        800B5C34	srl    s2, s2, $10
        800B5C38	mtc2   t5,l33
        800B5C3C	mtc2   t6,rbk
        800B5C40	mtc2   t7,gbk
        800B5C44	lui    s4, $0c00
        800B5C48	sw     s4, $0000(a2)
        800B5C4C	gte_func26zero,r11r12
        800B5C50	mfc2   v0,ofx
        800B5C54	nop
        800B5C58	blez   v0, Lb5ccc [$800b5ccc]

        Lb5c5c:	; 800B5C5C
        800B5C5C	sll    s2, s2, $02
        800B5C60	addu   v0, t3, s2
        800B5C64	lw     v0, $0000(v0)
        800B5C68	sw     t5, $0008(a2)
        800B5C6C	sw     t6, $0014(a2)
        800B5C70	sw     t7, $0020(a2)
        800B5C74	sw     v0, $002c(a2)
        800B5C78	addu   v0, t4, t9
        800B5C7C	lw     a3, $0000(v0)
        800B5C80	addu   v0, t4, s0
        800B5C84	lw     t1, $0000(v0)
        800B5C88	addu   v0, t4, s1
        800B5C8C	lw     s6, $0000(v0)
        800B5C90	addu   v0, t4, s2
        800B5C94	lw     v0, $0000(v0)
        800B5C98	addu   a3, a3, t1
        800B5C9C	addu   a3, a3, s6
        800B5CA0	addu   a3, a3, v0
        800B5CA4	srl    a3, a3, $04
        800B5CA8	sll    a3, a3, $02
        800B5CAC	addu   a3, a3, s3
        800B5CB0	lw     s4, $0000(a3)
        800B5CB4	sll    v0, a2, $08
        800B5CB8	srl    v0, v0, $08
        800B5CBC	lui    at, $0c00
        800B5CC0	or     s4, s4, at
        800B5CC4	sw     s4, $0000(a2)
        800B5CC8	sw     v0, $0000(a3)

        Lb5ccc:	; 800B5CCC
        800B5CCC	addiu  a2, a2, $0034
        800B5CD8	addi   a1, a1, $0020
        800B5CD0	addi   t2, t2, $ffff (=-$1)
    800B5CD4	bgtz   t2, loopb5bf0 [$800b5bf0]
}



T2 = hu[T8 + 8];
if (T2 != 0)
{
    loopb5cec:	; 800B5CEC
        800B5CEC	lw     s0, $0000(a1)
        800B5CF0	lhu    s1, $0004(a1)
        800B5CF4	andi   t9, s0, $ffff
        800B5CF8	srl    s0, s0, $10
        800B5CFC	lbu    s5, $000f(a1)
        800B5D00	sll    t9, t9, $02
        800B5D04	addu   v0, t3, t9
        800B5D08	lw     t5, $0000(v0)
        800B5D0C	sll    s0, s0, $02
        800B5D10	addu   v0, t3, s0
        800B5D14	lw     t6, $0000(v0)
        800B5D18	sll    s1, s1, $02
        800B5D1C	addu   v0, t3, s1
        800B5D20	andi   v1, s5, $0002
        800B5D24	bne    v1, zero, Lb5d50 [$800b5d50]
        800B5D28	lw     t7, $0000(v0)
        800B5D2C	mtc2   t5,l33
        800B5D30	mtc2   t6,rbk
        800B5D34	mtc2   t7,gbk
        800B5D38	lui    s4, $0900
        800B5D3C	sw     s4, $0000(a2)
        800B5D40	gte_func26zero,r11r12
        800B5D44	mfc2   v0,ofx
        800B5D48	nop
        800B5D4C	blez   v0, Lb5dac [$800b5dac]

        Lb5d50:	; 800B5D50
        800B5D50	addu   v0, t4, t9
        800B5D54	lw     a3, $0000(v0)

        Lb5d58:	; 800B5D58
        800B5D58	addu   v0, t4, s0
        800B5D5C	lw     t1, $0000(v0)
        800B5D60	addu   v0, t4, s1
        800B5D64	lw     s6, $0000(v0)
        800B5D68	mtc2   a3,lr3lg1
        800B5D6C	mtc2   t1,lg2lg3
        800B5D70	mtc2   s6,lb1lb2
        800B5D74	sw     t5, $0008(a2)
        800B5D78	sw     t6, $0014(a2)

        Lb5d7c:	; 800B5D7C
        800B5D7C	gte_func26t8,r11r12
        800B5D80	mfc2   a3,trz
        800B5D84	sw     t7, $0020(a2)
        800B5D88	sll    a3, a3, $02
        800B5D8C	addu   a3, a3, s3
        800B5D90	lw     s4, $0000(a3)
        800B5D94	sll    v0, a2, $08
        800B5D98	srl    v0, v0, $08
        800B5D9C	lui    at, $0900
        800B5DA0	or     s4, s4, at
        800B5DA4	sw     s4, $0000(a2)
        800B5DA8	sw     v0, $0000(a3)

        Lb5dac:	; 800B5DAC
        800B5DAC	addiu  a2, a2, $0028
        800B5DB8	addi   a1, a1, $0018
        800B5DB0	addi   t2, t2, $ffff (=-$1)
    800B5DB4	bgtz   t2, loopb5cec [$800b5cec]

}



T2 = hu[T8 + a];
if (T2 != 0)
{
    loopb5dcc:	; 800B5DCC
        800B5DCC	lw     s0, $0000(a1)
        800B5DD0	lw     s2, $0004(a1)
        800B5DD4	lbu    s5, $0014(a1)
        800B5DD8	andi   t9, s0, $ffff
        800B5DDC	srl    s0, s0, $10
        800B5DE0	andi   s1, s2, $ffff
        800B5DE4	sll    t9, t9, $02
        800B5DE8	addu   v0, t3, t9
        800B5DEC	lw     t5, $0000(v0)
        800B5DF0	sll    s0, s0, $02
        800B5DF4	addu   v0, t3, s0
        800B5DF8	lw     t6, $0000(v0)
        800B5DFC	sll    s1, s1, $02
        800B5E00	addu   v0, t3, s1
        800B5E04	lw     t7, $0000(v0)
        800B5E08	andi   v1, s5, $0002
        800B5E0C	bne    v1, zero, Lb5e38 [$800b5e38]
        800B5E10	srl    s2, s2, $10
        800B5E14	mtc2   t5,l33
        800B5E18	mtc2   t6,rbk
        800B5E1C	mtc2   t7,gbk
        800B5E20	lui    s4, $0800
        800B5E24	sw     s4, $0000(a2)
        800B5E28	gte_func26zero,r11r12
        800B5E2C	mfc2   v0,ofx
        800B5E30	nop
        800B5E34	blez   v0, Lb5ea8 [$800b5ea8]

        Lb5e38:	; 800B5E38
        800B5E38	sll    s2, s2, $02
        800B5E3C	addu   v0, t3, s2
        800B5E40	lw     v0, $0000(v0)
        800B5E44	sw     t5, $0008(a2)
        800B5E48	sw     t6, $0010(a2)
        800B5E4C	sw     t7, $0018(a2)
        800B5E50	sw     v0, $0020(a2)
        800B5E54	addu   v0, t4, t9
        800B5E58	lw     a3, $0000(v0)
        800B5E5C	addu   v0, t4, s0
        800B5E60	lw     t1, $0000(v0)
        800B5E64	addu   v0, t4, s1
        800B5E68	lw     s6, $0000(v0)

        Lb5e6c:	; 800B5E6C
        800B5E6C	addu   v0, t4, s2
        800B5E70	lw     v0, $0000(v0)
        800B5E74	addu   a3, a3, t1
        800B5E78	addu   a3, a3, s6
        800B5E7C	addu   a3, a3, v0
        800B5E80	srl    a3, a3, $04
        800B5E84	sll    a3, a3, $02
        800B5E88	addu   a3, a3, s3
        800B5E8C	lw     s4, $0000(a3)
        800B5E90	sll    v0, a2, $08
        800B5E94	srl    v0, v0, $08
        800B5E98	lui    at, $0800
        800B5E9C	or     s4, s4, at
        800B5EA0	sw     s4, $0000(a2)
        800B5EA4	sw     v0, $0000(a3)

        Lb5ea8:	; 800B5EA8
        800B5EA8	addiu  a2, a2, $0024
        800B5EB4	addi   a1, a1, $0018
        800B5EAC	addi   t2, t2, $ffff (=-$1)
    800B5EB0	bgtz   t2, loopb5dcc [$800b5dcc]

}



T2 = hu[T8 + c];
if (T2 != 0)
{
    loopb5ec8:	; 800B5EC8
        800B5EC8	lw     s0, $0000(a1)
        800B5ECC	lhu    s1, $0004(a1)
        800B5ED0	lbu    s5, $0013(a1)
        800B5ED4	andi   t9, s0, $ffff
        800B5ED8	srl    s0, s0, $10
        800B5EDC	sll    t9, t9, $02
        800B5EE0	addu   v0, t3, t9
        800B5EE4	lw     t5, $0000(v0)
        800B5EE8	sll    s0, s0, $02
        800B5EEC	addu   v0, t3, s0
        800B5EF0	lw     t6, $0000(v0)
        800B5EF4	sll    s1, s1, $02
        800B5EF8	addu   v0, t3, s1
        800B5EFC	andi   v1, s5, $0002
        800B5F00	bne    v1, zero, Lb5f2c [$800b5f2c]
        800B5F04	lw     t7, $0000(v0)
        800B5F08	mtc2   t5,l33
        800B5F0C	mtc2   t6,rbk
        800B5F10	mtc2   t7,gbk
        800B5F14	lui    s4, $0600
        800B5F18	sw     s4, $0000(a2)
        800B5F1C	gte_func26zero,r11r12
        800B5F20	mfc2   v0,ofx
        800B5F24	nop
        800B5F28	blez   v0, Lb5f88 [$800b5f88]

        Lb5f2c:	; 800B5F2C
        800B5F2C	addu   v0, t4, t9
        800B5F30	lw     a3, $0000(v0)
        800B5F34	addu   v0, t4, s0
        800B5F38	lw     t1, $0000(v0)
        800B5F3C	addu   v0, t4, s1
        800B5F40	lw     s6, $0000(v0)
        800B5F44	mtc2   a3,lr3lg1
        800B5F48	mtc2   t1,lg2lg3
        800B5F4C	mtc2   s6,lb1lb2
        800B5F50	sw     t5, $0008(a2)
        800B5F54	sw     t6, $0010(a2)
        800B5F58	gte_func26t8,r11r12
        800B5F5C	mfc2   a3,trz
        800B5F60	sw     t7, $0018(a2)

        Lb5f64:	; 800B5F64
        800B5F64	sll    a3, a3, $02
        800B5F68	addu   a3, a3, s3
        800B5F6C	lw     s4, $0000(a3)
        800B5F70	sll    v0, a2, $08
        800B5F74	srl    v0, v0, $08
        800B5F78	lui    at, $0600
        800B5F7C	or     s4, s4, at
        800B5F80	sw     s4, $0000(a2)
        800B5F84	sw     v0, $0000(a3)

        Lb5f88:	; 800B5F88
        800B5F88	addiu  a2, a2, $001c
        800B5F94	addi   a1, a1, $0014
        800B5F8C	addi   t2, t2, $ffff (=-$1)
    800B5F90	bgtz   t2, loopb5ec8 [$800b5ec8]
}



T2 = hu[T8 + e];
if (T2 != 0)
{
    loopb5fa8:	; 800B5FA8
        800B5FA8	lw     s0, $0000(a1)
        800B5FAC	lw     s2, $0004(a1)
        800B5FB0	lbu    s5, $000d(a1)
        800B5FB4	andi   t9, s0, $ffff
        800B5FB8	srl    s0, s0, $10
        800B5FBC	andi   s1, s2, $ffff
        800B5FC0	sll    t9, t9, $02
        800B5FC4	addu   v0, t3, t9
        800B5FC8	lw     t5, $0000(v0)
        800B5FCC	sll    s0, s0, $02
        800B5FD0	addu   v0, t3, s0
        800B5FD4	lw     t6, $0000(v0)
        800B5FD8	sll    s1, s1, $02
        800B5FDC	addu   v0, t3, s1
        800B5FE0	lw     t7, $0000(v0)
        800B5FE4	andi   v1, s5, $0002
        800B5FE8	bne    v1, zero, Lb6014 [$800b6014]
        800B5FEC	srl    s2, s2, $10
        800B5FF0	mtc2   t5,l33
        800B5FF4	mtc2   t6,rbk
        800B5FF8	mtc2   t7,gbk
        800B5FFC	lui    s4, $0500
        800B6000	sw     s4, $0000(a2)
        800B6004	gte_func26zero,r11r12
        800B6008	mfc2   v0,ofx
        800B600C	nop
        800B6010	blez   v0, Lb6084 [$800b6084]

        Lb6014:	; 800B6014
        800B6014	sll    s2, s2, $02
        800B6018	addu   v0, t3, s2
        800B601C	lw     v0, $0000(v0)
        800B6020	sw     t5, $0008(a2)
        800B6024	sw     t6, $000c(a2)
        800B6028	sw     t7, $0010(a2)
        800B602C	sw     v0, $0014(a2)
        800B6030	addu   v0, t4, t9
        800B6034	lw     a3, $0000(v0)
        800B6038	addu   v0, t4, s0
        800B603C	lw     t1, $0000(v0)
        800B6040	addu   v0, t4, s1
        800B6044	lw     s6, $0000(v0)
        800B6048	addu   v0, t4, s2
        800B604C	lw     v0, $0000(v0)
        800B6050	addu   a3, a3, t1
        800B6054	addu   a3, a3, s6
        800B6058	addu   a3, a3, v0
        800B605C	srl    a3, a3, $04
        800B6060	sll    a3, a3, $02
        800B6064	addu   a3, a3, s3
        800B6068	lw     s4, $0000(a3)
        800B606C	sll    v0, a2, $08
        800B6070	srl    v0, v0, $08
        800B6074	lui    at, $0500
        800B6078	or     s4, s4, at
        800B607C	sw     s4, $0000(a2)
        800B6080	sw     v0, $0000(a3)

        Lb6084:	; 800B6084
        800B6084	addiu  a2, a2, $0018
        800B6090	addi   a1, a1, $0010
        800B6088	addi   t2, t2, $ffff (=-$1)
    800B608C	bgtz   t2, loopb5fa8 [$800b5fa8]
}



T2 = hu[T8 + 10];
if (T2 != 0)
{
    loopb60a4:	; 800B60A4
        800B60A4	lw     s0, $0000(a1)
        800B60A8	lhu    s1, $0004(a1)
        800B60AC	lbu    s5, $000b(a1)
        800B60B0	andi   t9, s0, $ffff
        800B60B4	srl    s0, s0, $10
        800B60B8	sll    t9, t9, $02
        800B60BC	addu   v0, t3, t9
        800B60C0	lw     t5, $0000(v0)
        800B60C4	sll    s0, s0, $02
        800B60C8	addu   v0, t3, s0
        800B60CC	lw     t6, $0000(v0)
        800B60D0	sll    s1, s1, $02
        800B60D4	addu   v0, t3, s1
        800B60D8	andi   v1, s5, $0002
        800B60DC	bne    v1, zero, Lb6108 [$800b6108]
        800B60E0	lw     t7, $0000(v0)
        800B60E4	mtc2   t5,l33
        800B60E8	mtc2   t6,rbk
        800B60EC	mtc2   t7,gbk
        800B60F0	lui    s4, $0400
        800B60F4	sw     s4, $0000(a2)
        800B60F8	gte_func26zero,r11r12
        800B60FC	mfc2   v0,ofx
        800B6100	nop
        800B6104	blez   v0, Lb6164 [$800b6164]

        Lb6108:	; 800B6108
        800B6108	addu   v0, t4, t9
        800B610C	lw     a3, $0000(v0)
        800B6110	addu   v0, t4, s0
        800B6114	lw     t1, $0000(v0)
        800B6118	addu   v0, t4, s1
        800B611C	lw     s6, $0000(v0)
        800B6120	mtc2   a3,lr3lg1
        800B6124	mtc2   t1,lg2lg3
        800B6128	mtc2   s6,lb1lb2
        800B612C	sw     t5, $0008(a2)
        800B6130	sw     t6, $000c(a2)
        800B6134	gte_func26t8,r11r12
        800B6138	mfc2   a3,trz
        800B613C	sw     t7, $0010(a2)
        800B6140	sll    a3, a3, $02
        800B6144	addu   a3, a3, s3
        800B6148	lw     s4, $0000(a3)
        800B614C	sll    v0, a2, $08
        800B6150	srl    v0, v0, $08
        800B6154	lui    at, $0400
        800B6158	or     s4, s4, at
        800B615C	sw     s4, $0000(a2)
        800B6160	sw     v0, $0000(a3)

        Lb6164:	; 800B6164
        800B6164	addiu  a2, a2, $0014
        800B6170	addi   a1, a1, $000c
        800B6168	addi   t2, t2, $ffff (=-$1)
    800B616C	bgtz   t2, loopb60a4 [$800b60a4]
}
////////////////////////////////



////////////////////////////////
// funcbb714
800BB718	addu   a3, a0, zero
800BB71C	andi   a2, a1, $00ff
800BB720	sll    a0, a2, $02
800BB724	addu   a0, a0, a2
800BB728	lui    v0, $8006
800BB72C	lw     v0, $794c(v0)
800BB730	sll    a0, a0, $03
800BB754	lw     a1, $0008(a3)
800BB758	lw     v1, $001c(v0)
800BB75C	lw     v0, $0010(a1)
800BB760	lbu    a1, $0008(v1)
800BB764	addu   s6, v0, a0
800BB768	sll    v0, a1, $02
800BB76C	addu   v1, v1, v0
800BB770	lw     s4, $0010(v1)
800BB778	sll    v0, a2, $01
if( A1 != 0 )
{
    800BB77C	addu   v0, v0, a2
    800BB780	lw     v1, $0044(a3)
    800BB784	sll    v0, v0, $02
    800BB788	addu   v0, v0, v1
    800BB78C	lhu    v1, $0000(s6)
    800BB790	lw     v0, $0004(v0)
    800BB798	addu   v0, v0, v1
}
else
{
    800BB79C	addu   v0, v0, a2
    800BB7A0	lw     v1, $0044(a3)
    800BB7A4	sll    v0, v0, $02
    800BB7A8	addu   v0, v0, v1
    800BB7AC	lw     v0, $0004(v0)
}

800BB7B4	addu   t5, v0, zero
800BB7B8	lhu    s0, $0002(s6)
800BB7BC	lw     t9, $001c(s6)

if( S0 != 0 )
{
    800BB7C4	addu   t6, zero, zero
    800BB7C8	lui    v0, $8007
    800BB7CC	addiu  s3, v0, $11a8
    S2 = 80070520;
    800BB7D8	lui    s5, $ff00
    800BB7DC	lui    s1, $00ff
    800BB7E0	ori    s1, s1, $ffff
    800BB7E4	addiu  t7, t5, $0020
    800BB7E8	addiu  t8, t9, $0015

    loopbb7ec:	; 800BB7EC
        800BB7EC	lui    t0, $3fff
        800BB7F0	ori    t0, t0, $ffff
        800BB7F4	lw     v1, $0000(t9)
        800BB7F8	lw     t1, $ffef(t8)
        800BB7FC	srl    a0, v1, $10
        800BB800	srl    t3, t1, $10
        800BB804	andi   v1, v1, $ffff
        800BB808	sll    v1, v1, $02
        800BB80C	addu   v0, v1, s3
        800BB810	sll    a2, a0, $02
        800BB814	lw     t4, $0000(v0)
        800BB818	addu   v0, a2, s3
        800BB81C	andi   a1, t1, $ffff
        800BB820	sll    a1, a1, $02
        800BB824	addu   a3, a1, s3
        800BB828	addu   v1, v1, s2
        800BB82C	addu   a2, a2, s2
        800BB830	addu   a1, a1, s2
        800BB834	lw     t2, $0000(v0)
        800BB838	lw     v0, $0000(a2)
        800BB83C	sll    a2, t3, $02
        A0 = w[V1 + 0];
        800BB844	lw     a3, $0000(a3)
        800BB848	lw     v1, $0000(a1)
        800BB84C	addu   a0, a0, v0
        800BB850	addu   v0, a2, s2
        800BB854	lw     v0, $0000(v0)
        800BB858	addu   a0, a0, v1
        800BB85C	addu   a0, a0, v0
        800BB860	slt    t0, t0, a0
        800BB864	bne    t0, zero, Lbb90c [$800bb90c]
        800BB868	addiu  t6, t6, $0001
        800BB86C	lbu    v0, $0000(t8)
        800BB870	nop
        800BB874	andi   v0, v0, $0002
        800BB878	bne    v0, zero, Lbb8b4 [$800bb8b4]
        800BB87C	lui    v0, $000f
        800BB880	mtc2   t4,l33
        800BB884	mtc2   a3,gbk
        800BB888	mtc2   t2,rbk
        800BB88C	lw     v0, $0000(t5)
        800BB890	nop
        800BB894	and    v0, v0, s5
        800BB898	sw     v0, $0000(t5)
        800BB89C	gte_func26zero,r11r12
        800BB8A0	swc2   t8, $0000(sp)
        800BB8A4	lw     v0, $0000(sp)
        800BB8A8	nop
        800BB8AC	blez   v0, Lbb90c [$800bb90c]
        800BB8B0	lui    v0, $000f

        Lbb8b4:	; 800BB8B4
        800BB8B4	ori    v0, v0, $ffff
        800BB8B8	and    a0, a0, v0
        800BB8BC	addu   v0, a2, s3
        800BB8C0	sra    a0, a0, $04
        800BB8C4	sll    a0, a0, $02
        800BB8C8	sw     t4, $ffe8(t7)
        800BB8CC	sw     t2, $fff0(t7)
        800BB8D0	sw     a3, $fff8(t7)
        800BB8D4	lw     v0, $0000(v0)
        800BB8D8	addu   a0, a0, s4
        800BB8DC	sw     v0, $0000(t7)
        800BB8E0	lw     v1, $0000(t5)
        800BB8E4	lw     v0, $0000(a0)
        800BB8E8	and    v1, v1, s5
        800BB8EC	and    v0, v0, s1
        800BB8F0	or     v1, v1, v0
        800BB8F4	sw     v1, $0000(t5)
        800BB8F8	lw     v0, $0000(a0)
        800BB8FC	and    v1, t5, s1
        800BB900	and    v0, v0, s5
        800BB904	or     v0, v0, v1
        800BB908	sw     v0, $0000(a0)

        Lbb90c:	; 800BB90C
        800BB90C	addiu  t8, t8, $0018
        800BB910	addiu  t9, t9, $0018
        800BB914	addiu  t7, t7, $0028
        800BB920	addiu  t5, t5, $0028
        800BB918	sltu   v0, t6, s0
    800BB91C	bne    v0, zero, loopbb7ec [$800bb7ec]

}

800BB924	lhu    s0, $0004(s6)
800BB928	addu   t7, t9, zero
800BB92C	addu   a2, t5, zero
800BB930	beq    s0, zero, Lbba8c [$800bba8c]
800BB934	addu   t6, zero, zero
800BB938	lui    v0, $8007
800BB93C	addiu  s3, v0, $11a8
800BB940	lui    v0, $8007
800BB944	addiu  s2, v0, $0520
800BB948	lui    s1, $ff00
800BB94C	lui    t5, $00ff
800BB950	ori    t5, t5, $ffff

Lbb954:	; 800BB954
800BB954	addiu  t0, a2, $0018
800BB958	addiu  t3, t7, $0012

loopbb95c:	; 800BB95C
800BB95C	lui    a1, $2fff
800BB960	ori    a1, a1, $ffff
800BB964	lw     v1, $0000(t7)
800BB968	lhu    t1, $fff2(t3)
800BB96C	srl    a0, v1, $10
800BB970	andi   v1, v1, $ffff

funcbb974:	; 800BB974
800BB974	sll    v1, v1, $02
800BB978	addu   v0, v1, s3
800BB97C	sll    a0, a0, $02
800BB980	lw     t4, $0000(v0)
800BB984	addu   v0, a0, s3
800BB988	lw     t2, $0000(v0)
800BB98C	sll    v0, t1, $02
800BB990	addu   v0, v0, s3
800BB994	addu   v1, v1, s2
800BB998	addu   a0, a0, s2
800BB99C	lw     a3, $0000(v0)
800BB9A0	sll    v0, t1, $02
800BB9A4	addu   v0, v0, s2
800BB9A8	lw     v1, $0000(v1)
800BB9AC	lw     a0, $0000(a0)
800BB9B0	lw     v0, $0000(v0)
800BB9B4	addu   v1, v1, a0
800BB9B8	addu   a0, v1, v0
800BB9BC	slt    a1, a1, a0
800BB9C0	bne    a1, zero, Lbba74 [$800bba74]
800BB9C4	addiu  t6, t6, $0001
800BB9C8	lbu    v0, $0000(t3)
800BB9CC	nop
800BB9D0	andi   v0, v0, $0002
800BB9D4	bne    v0, zero, Lbba10 [$800bba10]
800BB9D8	lui    v0, $000f
800BB9DC	mtc2   t4,l33
800BB9E0	mtc2   a3,gbk
800BB9E4	mtc2   t2,rbk
800BB9E8	lw     v0, $0000(a2)
800BB9EC	nop
800BB9F0	and    v0, v0, s1
800BB9F4	sw     v0, $0000(a2)
800BB9F8	gte_func26zero,r11r12
800BB9FC	swc2   t8, $0000(sp)
800BBA00	lw     v0, $0000(sp)
800BBA04	nop
800BBA08	blez   v0, Lbba74 [$800bba74]
800BBA0C	lui    v0, $000f

Lbba10:	; 800BBA10
800BBA10	ori    v0, v0, $ffff
800BBA14	lui    v1, $5555
800BBA18	ori    v1, v1, $5556
800BBA1C	and    v0, a0, v0
800BBA20	mult   v0, v1
800BBA24	sra    v0, v0, $1f
800BBA28	sw     t4, $fff0(t0)
800BBA2C	sw     t2, $fff8(t0)
800BBA30	sw     a3, $0000(t0)
800BBA34	lw     v1, $0000(a2)
800BBA38	mfhi   s7
800BBA3C	subu   a0, s7, v0
800BBA40	sra    a0, a0, $02
800BBA44	sll    a0, a0, $02
800BBA48	addu   a0, a0, s4
800BBA4C	lw     v0, $0000(a0)
800BBA50	and    v1, v1, s1
800BBA54	and    v0, v0, t5
800BBA58	or     v1, v1, v0
800BBA5C	sw     v1, $0000(a2)
800BBA60	lw     v0, $0000(a0)
800BBA64	and    v1, a2, t5
800BBA68	and    v0, v0, s1
800BBA6C	or     v0, v0, v1
800BBA70	sw     v0, $0000(a0)

Lbba74:	; 800BBA74
800BBA74	addiu  t3, t3, $0014
800BBA78	addiu  t7, t7, $0014
800BBA7C	addiu  t0, t0, $0020
800BBA80	sltu   v0, t6, s0
800BBA84	bne    v0, zero, loopbb95c [$800bb95c]
800BBA88	addiu  a2, a2, $0020

Lbba8c:	; 800BBA8C
800BBA8C	lhu    s0, $0006(s6)
800BBA90	addu   t9, t7, zero
800BBA94	addu   t5, a2, zero
800BBA98	beq    s0, zero, Lbbbfc [$800bbbfc]
800BBA9C	addu   t6, zero, zero
800BBAA0	lui    v0, $8007
800BBAA4	addiu  s3, v0, $11a8
800BBAA8	lui    v0, $8007
800BBAAC	addiu  s2, v0, $0520
800BBAB0	lui    s5, $ff00
800BBAB4	lui    s1, $00ff
800BBAB8	ori    s1, s1, $ffff
800BBABC	addiu  t7, t5, $002c
800BBAC0	addiu  t8, t9, $001c

loopbbac4:	; 800BBAC4
800BBAC4	lui    t0, $3fff
800BBAC8	ori    t0, t0, $ffff
800BBACC	lw     v1, $0000(t9)
800BBAD0	lw     t1, $ffe8(t8)
800BBAD4	srl    a0, v1, $10
800BBAD8	srl    t3, t1, $10
800BBADC	andi   v1, v1, $ffff
800BBAE0	sll    v1, v1, $02
800BBAE4	addu   v0, v1, s3
800BBAE8	sll    a2, a0, $02
800BBAEC	lw     t4, $0000(v0)
800BBAF0	addu   v0, a2, s3
800BBAF4	andi   a1, t1, $ffff
800BBAF8	sll    a1, a1, $02
800BBAFC	addu   a3, a1, s3
800BBB00	addu   v1, v1, s2
800BBB04	addu   a2, a2, s2
800BBB08	addu   a1, a1, s2
800BBB0C	lw     t2, $0000(v0)
800BBB10	lw     v0, $0000(a2)
800BBB14	sll    a2, t3, $02
800BBB18	lw     a0, $0000(v1)
800BBB1C	lw     a3, $0000(a3)
800BBB20	lw     v1, $0000(a1)
800BBB24	addu   a0, a0, v0

Lbbb28:	; 800BBB28
800BBB28	addu   v0, a2, s2
800BBB2C	lw     v0, $0000(v0)
800BBB30	addu   a0, a0, v1
800BBB34	addu   a0, a0, v0
800BBB38	slt    t0, t0, a0
800BBB3C	bne    t0, zero, Lbbbe4 [$800bbbe4]
800BBB40	addiu  t6, t6, $0001
800BBB44	lbu    v0, $0000(t8)
800BBB48	nop
800BBB4C	andi   v0, v0, $0002
800BBB50	bne    v0, zero, Lbbb8c [$800bbb8c]
800BBB54	lui    v0, $000f
800BBB58	mtc2   t4,l33
800BBB5C	mtc2   a3,gbk
800BBB60	mtc2   t2,rbk
800BBB64	lw     v0, $0000(t5)
800BBB68	nop
800BBB6C	and    v0, v0, s5
800BBB70	sw     v0, $0000(t5)
800BBB74	gte_func26zero,r11r12

Lbbb78:	; 800BBB78
800BBB78	swc2   t8, $0000(sp)
800BBB7C	lw     v0, $0000(sp)
800BBB80	nop
800BBB84	blez   v0, Lbbbe4 [$800bbbe4]
800BBB88	lui    v0, $000f

Lbbb8c:	; 800BBB8C
800BBB8C	ori    v0, v0, $ffff
800BBB90	and    a0, a0, v0
800BBB94	addu   v0, a2, s3
800BBB98	sra    a0, a0, $04
800BBB9C	sll    a0, a0, $02

Lbbba0:	; 800BBBA0
800BBBA0	sw     t4, $ffdc(t7)
800BBBA4	sw     t2, $ffe8(t7)

funcbbba8:	; 800BBBA8
800BBBA8	sw     a3, $fff4(t7)
800BBBAC	lw     v0, $0000(v0)
800BBBB0	addu   a0, a0, s4
800BBBB4	sw     v0, $0000(t7)
800BBBB8	lw     v1, $0000(t5)
800BBBBC	lw     v0, $0000(a0)
800BBBC0	and    v1, v1, s5
800BBBC4	and    v0, v0, s1
800BBBC8	or     v1, v1, v0
800BBBCC	sw     v1, $0000(t5)
800BBBD0	lw     v0, $0000(a0)
800BBBD4	and    v1, t5, s1
800BBBD8	and    v0, v0, s5

Lbbbdc:	; 800BBBDC
800BBBDC	or     v0, v0, v1
800BBBE0	sw     v0, $0000(a0)

Lbbbe4:	; 800BBBE4
800BBBE4	addiu  t8, t8, $0020
800BBBE8	addiu  t9, t9, $0020
800BBBEC	addiu  t7, t7, $0034
800BBBF0	sltu   v0, t6, s0
800BBBF4	bne    v0, zero, loopbbac4 [$800bbac4]
800BBBF8	addiu  t5, t5, $0034

Lbbbfc:	; 800BBBFC
800BBBFC	lhu    s0, $0008(s6)
800BBC00	addu   t7, t9, zero
800BBC04	addu   a2, t5, zero
800BBC08	beq    s0, zero, Lbbd64 [$800bbd64]
800BBC0C	addu   t6, zero, zero
800BBC10	lui    v0, $8007
800BBC14	addiu  s3, v0, $11a8
800BBC18	lui    v0, $8007
800BBC1C	addiu  s2, v0, $0520
800BBC20	lui    s1, $ff00
800BBC24	lui    t5, $00ff
800BBC28	ori    t5, t5, $ffff
800BBC2C	addiu  t0, a2, $0020
800BBC30	addiu  t3, t7, $000f

loopbbc34:	; 800BBC34
800BBC34	lui    a1, $2fff
800BBC38	ori    a1, a1, $ffff
800BBC3C	lw     v1, $0000(t7)
800BBC40	lhu    t1, $fff5(t3)
800BBC44	srl    a0, v1, $10
800BBC48	andi   v1, v1, $ffff
800BBC4C	sll    v1, v1, $02
800BBC50	addu   v0, v1, s3
800BBC54	sll    a0, a0, $02
800BBC58	lw     t4, $0000(v0)
800BBC5C	addu   v0, a0, s3
800BBC60	lw     t2, $0000(v0)
800BBC64	sll    v0, t1, $02
800BBC68	addu   v0, v0, s3
800BBC6C	addu   v1, v1, s2
800BBC70	addu   a0, a0, s2
800BBC74	lw     a3, $0000(v0)
800BBC78	sll    v0, t1, $02
800BBC7C	addu   v0, v0, s2
800BBC80	lw     v1, $0000(v1)
800BBC84	lw     a0, $0000(a0)
800BBC88	lw     v0, $0000(v0)
800BBC8C	addu   v1, v1, a0

Lbbc90:	; 800BBC90
800BBC90	addu   a0, v1, v0
800BBC94	slt    a1, a1, a0
800BBC98	bne    a1, zero, Lbbd4c [$800bbd4c]
800BBC9C	addiu  t6, t6, $0001
800BBCA0	lbu    v0, $0000(t3)
800BBCA4	nop
800BBCA8	andi   v0, v0, $0002
800BBCAC	bne    v0, zero, Lbbce8 [$800bbce8]
800BBCB0	lui    v0, $000f
800BBCB4	mtc2   t4,l33
800BBCB8	mtc2   a3,gbk
800BBCBC	mtc2   t2,rbk
800BBCC0	lw     v0, $0000(a2)
800BBCC4	nop
800BBCC8	and    v0, v0, s1
800BBCCC	sw     v0, $0000(a2)

Lbbcd0:	; 800BBCD0
800BBCD0	gte_func26zero,r11r12
800BBCD4	swc2   t8, $0000(sp)
800BBCD8	lw     v0, $0000(sp)
800BBCDC	nop
800BBCE0	blez   v0, Lbbd4c [$800bbd4c]
800BBCE4	lui    v0, $000f

Lbbce8:	; 800BBCE8
800BBCE8	ori    v0, v0, $ffff
800BBCEC	lui    v1, $5555
800BBCF0	ori    v1, v1, $5556
800BBCF4	and    v0, a0, v0
800BBCF8	mult   v0, v1
800BBCFC	sra    v0, v0, $1f
800BBD00	sw     t4, $ffe8(t0)
800BBD04	sw     t2, $fff4(t0)
800BBD08	sw     a3, $0000(t0)
800BBD0C	lw     v1, $0000(a2)
800BBD10	mfhi   s7
800BBD14	subu   a0, s7, v0
800BBD18	sra    a0, a0, $02
800BBD1C	sll    a0, a0, $02
800BBD20	addu   a0, a0, s4
800BBD24	lw     v0, $0000(a0)
800BBD28	and    v1, v1, s1
800BBD2C	and    v0, v0, t5
800BBD30	or     v1, v1, v0
800BBD34	sw     v1, $0000(a2)
800BBD38	lw     v0, $0000(a0)

funcbbd3c:	; 800BBD3C
800BBD3C	and    v1, a2, t5
800BBD40	and    v0, v0, s1
800BBD44	or     v0, v0, v1
800BBD48	sw     v0, $0000(a0)

Lbbd4c:	; 800BBD4C
800BBD4C	addiu  t3, t3, $0018
800BBD50	addiu  t7, t7, $0018
800BBD54	addiu  t0, t0, $0028
800BBD58	sltu   v0, t6, s0
800BBD5C	bne    v0, zero, loopbbc34 [$800bbc34]
800BBD60	addiu  a2, a2, $0028

Lbbd64:	; 800BBD64
800BBD64	lhu    s0, $000a(s6)
800BBD68	addu   t9, t7, zero
800BBD6C	addu   t5, a2, zero
800BBD70	beq    s0, zero, Lbbed4 [$800bbed4]
800BBD74	addu   t6, zero, zero
800BBD78	lui    v0, $8007
800BBD7C	addiu  s3, v0, $11a8
800BBD80	lui    v0, $8007
800BBD84	addiu  s2, v0, $0520
800BBD88	lui    s5, $ff00
800BBD8C	lui    s1, $00ff
800BBD90	ori    s1, s1, $ffff
800BBD94	addiu  t7, t5, $0020
800BBD98	addiu  t8, t9, $0014

loopbbd9c:	; 800BBD9C
800BBD9C	lui    t0, $3fff
800BBDA0	ori    t0, t0, $ffff
800BBDA4	lw     v1, $0000(t9)
800BBDA8	lw     t1, $fff0(t8)
800BBDAC	srl    a0, v1, $10
800BBDB0	srl    t3, t1, $10
800BBDB4	andi   v1, v1, $ffff
800BBDB8	sll    v1, v1, $02
800BBDBC	addu   v0, v1, s3
800BBDC0	sll    a2, a0, $02
800BBDC4	lw     t4, $0000(v0)
800BBDC8	addu   v0, a2, s3
800BBDCC	andi   a1, t1, $ffff
800BBDD0	sll    a1, a1, $02
800BBDD4	addu   a3, a1, s3
800BBDD8	addu   v1, v1, s2
800BBDDC	addu   a2, a2, s2
800BBDE0	addu   a1, a1, s2
800BBDE4	lw     t2, $0000(v0)
800BBDE8	lw     v0, $0000(a2)
800BBDEC	sll    a2, t3, $02
800BBDF0	lw     a0, $0000(v1)
800BBDF4	lw     a3, $0000(a3)
800BBDF8	lw     v1, $0000(a1)
800BBDFC	addu   a0, a0, v0
800BBE00	addu   v0, a2, s2
800BBE04	lw     v0, $0000(v0)
800BBE08	addu   a0, a0, v1
800BBE0C	addu   a0, a0, v0
800BBE10	slt    t0, t0, a0
800BBE14	bne    t0, zero, Lbbebc [$800bbebc]
800BBE18	addiu  t6, t6, $0001
800BBE1C	lbu    v0, $0000(t8)
800BBE20	nop
800BBE24	andi   v0, v0, $0002
800BBE28	bne    v0, zero, Lbbe64 [$800bbe64]
800BBE2C	lui    v0, $000f
800BBE30	mtc2   t4,l33
800BBE34	mtc2   a3,gbk
800BBE38	mtc2   t2,rbk
800BBE3C	lw     v0, $0000(t5)
800BBE40	nop
800BBE44	and    v0, v0, s5
800BBE48	sw     v0, $0000(t5)
800BBE4C	gte_func26zero,r11r12
800BBE50	swc2   t8, $0000(sp)
800BBE54	lw     v0, $0000(sp)
800BBE58	nop
800BBE5C	blez   v0, Lbbebc [$800bbebc]
800BBE60	lui    v0, $000f

Lbbe64:	; 800BBE64
800BBE64	ori    v0, v0, $ffff
800BBE68	and    a0, a0, v0
800BBE6C	addu   v0, a2, s3
800BBE70	sra    a0, a0, $04
800BBE74	sll    a0, a0, $02
800BBE78	sw     t4, $ffe8(t7)
800BBE7C	sw     t2, $fff0(t7)
800BBE80	sw     a3, $fff8(t7)
800BBE84	lw     v0, $0000(v0)
800BBE88	addu   a0, a0, s4
800BBE8C	sw     v0, $0000(t7)
800BBE90	lw     v1, $0000(t5)
800BBE94	lw     v0, $0000(a0)
800BBE98	and    v1, v1, s5
800BBE9C	and    v0, v0, s1
800BBEA0	or     v1, v1, v0
800BBEA4	sw     v1, $0000(t5)
800BBEA8	lw     v0, $0000(a0)
800BBEAC	and    v1, t5, s1
800BBEB0	and    v0, v0, s5
800BBEB4	or     v0, v0, v1
800BBEB8	sw     v0, $0000(a0)

Lbbebc:	; 800BBEBC
800BBEBC	addiu  t8, t8, $0018
800BBEC0	addiu  t9, t9, $0018
800BBEC4	addiu  t7, t7, $0024
800BBEC8	sltu   v0, t6, s0
800BBECC	bne    v0, zero, loopbbd9c [$800bbd9c]
800BBED0	addiu  t5, t5, $0024

Lbbed4:	; 800BBED4
800BBED4	lhu    s0, $000c(s6)
800BBED8	addu   t7, t9, zero
800BBEDC	addu   a2, t5, zero
800BBEE0	beq    s0, zero, Lbc03c [$800bc03c]
800BBEE4	addu   t6, zero, zero
800BBEE8	lui    v0, $8007
800BBEEC	addiu  s3, v0, $11a8
800BBEF0	lui    v0, $8007
800BBEF4	addiu  s2, v0, $0520
800BBEF8	lui    s1, $ff00
800BBEFC	lui    t5, $00ff
800BBF00	ori    t5, t5, $ffff
800BBF04	addiu  t0, a2, $0018
800BBF08	addiu  t3, t7, $0013

loopbbf0c:	; 800BBF0C
800BBF0C	lui    a1, $2fff
800BBF10	ori    a1, a1, $ffff
800BBF14	lw     v1, $0000(t7)

Lbbf18:	; 800BBF18
800BBF18	lhu    t1, $fff1(t3)
800BBF1C	srl    a0, v1, $10
800BBF20	andi   v1, v1, $ffff
800BBF24	sll    v1, v1, $02
800BBF28	addu   v0, v1, s3
800BBF2C	sll    a0, a0, $02

funcbbf30:	; 800BBF30
800BBF30	lw     t4, $0000(v0)
800BBF34	addu   v0, a0, s3
800BBF38	lw     t2, $0000(v0)
800BBF3C	sll    v0, t1, $02
800BBF40	addu   v0, v0, s3
800BBF44	addu   v1, v1, s2
800BBF48	addu   a0, a0, s2
800BBF4C	lw     a3, $0000(v0)
800BBF50	sll    v0, t1, $02
800BBF54	addu   v0, v0, s2
800BBF58	lw     v1, $0000(v1)

funcbbf5c:	; 800BBF5C
800BBF5C	lw     a0, $0000(a0)
800BBF60	lw     v0, $0000(v0)
800BBF64	addu   v1, v1, a0
800BBF68	addu   a0, v1, v0
800BBF6C	slt    a1, a1, a0
800BBF70	bne    a1, zero, Lbc024 [$800bc024]
800BBF74	addiu  t6, t6, $0001
800BBF78	lbu    v0, $0000(t3)
800BBF7C	nop
800BBF80	andi   v0, v0, $0002
800BBF84	bne    v0, zero, Lbbfc0 [$800bbfc0]
800BBF88	lui    v0, $000f
800BBF8C	mtc2   t4,l33
800BBF90	mtc2   a3,gbk
800BBF94	mtc2   t2,rbk
800BBF98	lw     v0, $0000(a2)
800BBF9C	nop
800BBFA0	and    v0, v0, s1
800BBFA4	sw     v0, $0000(a2)
800BBFA8	gte_func26zero,r11r12
800BBFAC	swc2   t8, $0000(sp)
800BBFB0	lw     v0, $0000(sp)
800BBFB4	nop
800BBFB8	blez   v0, Lbc024 [$800bc024]
800BBFBC	lui    v0, $000f

Lbbfc0:	; 800BBFC0
800BBFC0	ori    v0, v0, $ffff
800BBFC4	lui    v1, $5555
800BBFC8	ori    v1, v1, $5556
800BBFCC	and    v0, a0, v0
800BBFD0	mult   v0, v1
800BBFD4	sra    v0, v0, $1f
800BBFD8	sw     t4, $fff0(t0)
800BBFDC	sw     t2, $fff8(t0)
800BBFE0	sw     a3, $0000(t0)
800BBFE4	lw     v1, $0000(a2)
800BBFE8	mfhi   s7
800BBFEC	subu   a0, s7, v0
800BBFF0	sra    a0, a0, $02
800BBFF4	sll    a0, a0, $02
800BBFF8	addu   a0, a0, s4
800BBFFC	lw     v0, $0000(a0)
800BC000	and    v1, v1, s1
800BC004	and    v0, v0, t5
800BC008	or     v1, v1, v0
800BC00C	sw     v1, $0000(a2)
800BC010	lw     v0, $0000(a0)
800BC014	and    v1, a2, t5
800BC018	and    v0, v0, s1
800BC01C	or     v0, v0, v1
800BC020	sw     v0, $0000(a0)

Lbc024:	; 800BC024
800BC024	addiu  t3, t3, $0014
800BC028	addiu  t7, t7, $0014
800BC02C	addiu  t0, t0, $001c
800BC030	sltu   v0, t6, s0
800BC034	bne    v0, zero, loopbbf0c [$800bbf0c]
800BC038	addiu  a2, a2, $001c

Lbc03c:	; 800BC03C
800BC03C	lhu    s0, $000e(s6)
800BC040	addu   t9, t7, zero
800BC044	addu   t5, a2, zero
800BC048	beq    s0, zero, Lbc1ac [$800bc1ac]
800BC04C	addu   t6, zero, zero
800BC050	lui    v0, $8007
800BC054	addiu  s3, v0, $11a8
800BC058	lui    v0, $8007
800BC05C	addiu  s2, v0, $0520
800BC060	lui    s5, $ff00
800BC064	lui    s1, $00ff
800BC068	ori    s1, s1, $ffff
800BC06C	addiu  t7, t5, $0014
800BC070	addiu  t8, t9, $000d

loopbc074:	; 800BC074
800BC074	lui    t0, $3fff
800BC078	ori    t0, t0, $ffff
800BC07C	lw     v1, $0000(t9)
800BC080	lw     t1, $fff7(t8)
800BC084	srl    a0, v1, $10
800BC088	srl    t3, t1, $10
800BC08C	andi   v1, v1, $ffff
800BC090	sll    v1, v1, $02

Lbc094:	; 800BC094
800BC094	addu   v0, v1, s3
800BC098	sll    a2, a0, $02
800BC09C	lw     t4, $0000(v0)
800BC0A0	addu   v0, a2, s3
800BC0A4	andi   a1, t1, $ffff
800BC0A8	sll    a1, a1, $02
800BC0AC	addu   a3, a1, s3
800BC0B0	addu   v1, v1, s2
800BC0B4	addu   a2, a2, s2
800BC0B8	addu   a1, a1, s2
800BC0BC	lw     t2, $0000(v0)
800BC0C0	lw     v0, $0000(a2)
800BC0C4	sll    a2, t3, $02
800BC0C8	lw     a0, $0000(v1)
800BC0CC	lw     a3, $0000(a3)

funcbc0d0:	; 800BC0D0
800BC0D0	lw     v1, $0000(a1)
800BC0D4	addu   a0, a0, v0
800BC0D8	addu   v0, a2, s2
800BC0DC	lw     v0, $0000(v0)
800BC0E0	addu   a0, a0, v1
800BC0E4	addu   a0, a0, v0
800BC0E8	slt    t0, t0, a0
800BC0EC	bne    t0, zero, Lbc194 [$800bc194]
800BC0F0	addiu  t6, t6, $0001
800BC0F4	lbu    v0, $0000(t8)
800BC0F8	nop
800BC0FC	andi   v0, v0, $0002
800BC100	bne    v0, zero, Lbc13c [$800bc13c]
800BC104	lui    v0, $000f
800BC108	mtc2   t4,l33
800BC10C	mtc2   a3,gbk
800BC110	mtc2   t2,rbk
800BC114	lw     v0, $0000(t5)
800BC118	nop
800BC11C	and    v0, v0, s5
800BC120	sw     v0, $0000(t5)
800BC124	gte_func26zero,r11r12
800BC128	swc2   t8, $0000(sp)
800BC12C	lw     v0, $0000(sp)
800BC130	nop
800BC134	blez   v0, Lbc194 [$800bc194]
800BC138	lui    v0, $000f

Lbc13c:	; 800BC13C
800BC13C	ori    v0, v0, $ffff
800BC140	and    a0, a0, v0
800BC144	addu   v0, a2, s3
800BC148	sra    a0, a0, $04
800BC14C	sll    a0, a0, $02
800BC150	sw     t4, $fff4(t7)
800BC154	sw     t2, $fff8(t7)
800BC158	sw     a3, $fffc(t7)
800BC15C	lw     v0, $0000(v0)
800BC160	addu   a0, a0, s4
800BC164	sw     v0, $0000(t7)
800BC168	lw     v1, $0000(t5)
800BC16C	lw     v0, $0000(a0)
800BC170	and    v1, v1, s5
800BC174	and    v0, v0, s1
800BC178	or     v1, v1, v0
800BC17C	sw     v1, $0000(t5)
800BC180	lw     v0, $0000(a0)
800BC184	and    v1, t5, s1
800BC188	and    v0, v0, s5
800BC18C	or     v0, v0, v1
800BC190	sw     v0, $0000(a0)

Lbc194:	; 800BC194
800BC194	addiu  t8, t8, $0010
800BC198	addiu  t9, t9, $0010
800BC19C	addiu  t7, t7, $0018
800BC1A0	sltu   v0, t6, s0
800BC1A4	bne    v0, zero, loopbc074 [$800bc074]
800BC1A8	addiu  t5, t5, $0018

Lbc1ac:	; 800BC1AC
800BC1AC	lhu    s0, $0010(s6)
800BC1B0	addu   t7, t9, zero
800BC1B4	addu   a2, t5, zero
800BC1B8	beq    s0, zero, Lbc314 [$800bc314]
800BC1BC	addu   t6, zero, zero
800BC1C0	lui    v0, $8007
800BC1C4	addiu  s3, v0, $11a8
800BC1C8	lui    v0, $8007
800BC1CC	addiu  s2, v0, $0520
800BC1D0	lui    s1, $ff00
800BC1D4	lui    t5, $00ff
800BC1D8	ori    t5, t5, $ffff
800BC1DC	addiu  t0, a2, $0010

funcbc1e0:	; 800BC1E0
800BC1E0	addiu  t3, t7, $000b

loopbc1e4:	; 800BC1E4
800BC1E4	lui    a1, $2fff
800BC1E8	ori    a1, a1, $ffff
800BC1EC	lw     v1, $0000(t7)
800BC1F0	lhu    t1, $fff9(t3)
800BC1F4	srl    a0, v1, $10
800BC1F8	andi   v1, v1, $ffff
800BC1FC	sll    v1, v1, $02
800BC200	addu   v0, v1, s3
800BC204	sll    a0, a0, $02
800BC208	lw     t4, $0000(v0)
800BC20C	addu   v0, a0, s3

Lbc210:	; 800BC210
800BC210	lw     t2, $0000(v0)
800BC214	sll    v0, t1, $02
800BC218	addu   v0, v0, s3

funcbc21c:	; 800BC21C
800BC21C	addu   v1, v1, s2
800BC220	addu   a0, a0, s2
800BC224	lw     a3, $0000(v0)
800BC228	sll    v0, t1, $02
800BC22C	addu   v0, v0, s2
800BC230	lw     v1, $0000(v1)
800BC234	lw     a0, $0000(a0)
800BC238	lw     v0, $0000(v0)
800BC23C	addu   v1, v1, a0
800BC240	addu   a0, v1, v0
800BC244	slt    a1, a1, a0
800BC248	bne    a1, zero, Lbc2fc [$800bc2fc]
800BC24C	addiu  t6, t6, $0001
800BC250	lbu    v0, $0000(t3)
800BC254	nop
800BC258	andi   v0, v0, $0002
800BC25C	bne    v0, zero, Lbc298 [$800bc298]
800BC260	lui    v0, $000f
800BC264	mtc2   t4,l33
800BC268	mtc2   a3,gbk
800BC26C	mtc2   t2,rbk
800BC270	lw     v0, $0000(a2)
800BC274	nop
800BC278	and    v0, v0, s1
800BC27C	sw     v0, $0000(a2)
800BC280	gte_func26zero,r11r12
800BC284	swc2   t8, $0000(sp)
800BC288	lw     v0, $0000(sp)
800BC28C	nop
800BC290	blez   v0, Lbc2fc [$800bc2fc]
800BC294	lui    v0, $000f

Lbc298:	; 800BC298
800BC298	ori    v0, v0, $ffff
800BC29C	lui    v1, $5555
800BC2A0	ori    v1, v1, $5556
800BC2A4	and    v0, a0, v0
800BC2A8	mult   v0, v1
800BC2AC	sra    v0, v0, $1f
800BC2B0	sw     t4, $fff8(t0)
800BC2B4	sw     t2, $fffc(t0)
800BC2B8	sw     a3, $0000(t0)
800BC2BC	lw     v1, $0000(a2)
800BC2C0	mfhi   s7
800BC2C4	subu   a0, s7, v0
800BC2C8	sra    a0, a0, $02
800BC2CC	sll    a0, a0, $02
800BC2D0	addu   a0, a0, s4
800BC2D4	lw     v0, $0000(a0)
800BC2D8	and    v1, v1, s1
800BC2DC	and    v0, v0, t5
800BC2E0	or     v1, v1, v0
800BC2E4	sw     v1, $0000(a2)
800BC2E8	lw     v0, $0000(a0)
800BC2EC	and    v1, a2, t5
800BC2F0	and    v0, v0, s1
800BC2F4	or     v0, v0, v1
800BC2F8	sw     v0, $0000(a0)

Lbc2fc:	; 800BC2FC
800BC2FC	addiu  t3, t3, $000c
800BC300	addiu  t7, t7, $000c
800BC304	addiu  t0, t0, $0014
800BC308	sltu   v0, t6, s0
800BC30C	bne    v0, zero, loopbc1e4 [$800bc1e4]
800BC310	addiu  a2, a2, $0014

Lbc314:	; 800BC314
////////////////////////////////
