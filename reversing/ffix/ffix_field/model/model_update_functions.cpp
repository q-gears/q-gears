////////////////////////////////
// funcb3294
if( bu[A0 + 9] != 0 )
{
    start = A0 + bu[A0 + 6] * c + c;
    pointer = start + bu[A0 + 9] * 8 - 8;

    loopb32d0:	; 800B32D0
        if( hu[pointer] == A1 )
        {
            return pointer;
        }

        pointer = pointer - 8;
        V0 = pointer < start;
    800B32E8	beq    v0, zero, loopb32d0 [$800b32d0]
}

return 0;
////////////////////////////////



////////////////////////////////
// funcad488
S2 = A0;
data = A1;
result = A2;
script = w[data + c];

scale_x = (w[S2 + 0] >> 8) & 0fff;
scale_z = w[S2 + 0] >> 14;

if( w[data + 0] & 00000020 )
{
    A0 = w[S2 + 4] & 0fff;
    system_get_cos_by_rotation;
    cos = V0;

    A0 = w[S2 + 4] & 0fff;
    system_get_sin_by_rotation;
    sin = V0;



    // create scale X 1 Z matrix multiplied by rotation around Y axis matrix
    [result + 0] = h((cos * scale_x) >> c);
    [result + 2] = h(0);
    [result + 4] = h((sin * scale_z) >> c);
    [result + 6] = h(0);
    [result + 8] = h(1000);
    [result + a] = h(0);
    [result + c] = h((-sin * scale_x) >> c);
    [result + e] = h(0);
    [result + 10] = h(((cos * scale_z) >> c));
    [result + 14] = w(w[script + 14] + (((cos * ((w[S2 + 4] << a) >> 16)) + (sin * (w[S2 + 4] >> 16))) >> c));
    [result + 18] = w(w[script + 18]);
    [result + 1c] = w(w[script + 1c] + ((-sin * ((w[S2 + 4] << a) >> 16)) + (cos * (w[S2 + 4] >> 16))) >> c);
}
else
{
    model_data = w[data + 8];
    bone_data = w[model_data + 20];

    R11R12 = w[bone_data + 20];
    R13R21 = w[bone_data + 24];
    R22R23 = w[bone_data + 28];
    R31R32 = w[bone_data + 2c];
    R33 = w[bone_data + 30];
    TRX = 0;
    TRY = 0;
    TRZ = 0;

    [SP + 30] = h(0);
    [SP + 32] = h(-1000);
    VXY0 = w[SP + 30]; // x = 0, y = -1000
    VZ0 = 0;

    gte_rtv0tr; // v0 * rotmatrix + tr vector.

    [SP + 38] = w(MAC1);
    [SP + 3c] = w(0);
    [SP + 40] = w(MAC3);

    A0 = SP + 38;
    A1 = SP + 68;
    system_normalize_vector_A0_to_A1;

    [SP + 68] = w(0 - w[SP + 68]);
    [SP + 6c] = w(0 - w[SP + 6c]);
    [SP + 70] = w(0 - w[SP + 70]);

    R11R12 = 0;
    R13R21 = 1000;
    R22R23 = 0;
    IR1 = w[SP + 68];
    IR2 = w[SP + 6c];
    IR3 = w[SP + 70];

    gte_op12; // Outer product.

    [SP + 48] = w(MAC1);
    [SP + 4c] = w(MAC2);
    [SP + 50] = w(MAC3);

    [result + 0] = h((w[SP + 48] * scale_x) >> c);
    [result + 2] = h(0);
    [result + 4] = h((w[SP + 68] * scale_z) >> c);
    [result + 6] = h((w[SP + 4c] * scale_x) >> c);
    [result + 8] = h(1000);
    [result + a] = h((w[SP + 6c] * scale_z) >> c);
    [result + c] = h((w[SP + 50] * scale_x) >> c);
    [result + e] = h(0);
    [result + 10] = h((w[SP + 70] * scale_z) >> c);
    [result + 14] = w(w[bone_data + 34] + (((w[SP + 48] * ((w[S2 + 4] << a) >> 16)) + (w[SP + 68] * (w[S2 + 4] >> 16))) >> c));
    [result + 18] = w(w[script + 18] +    (((w[SP + 4c] * ((w[S2 + 4] << a) >> 16)) + (w[SP + 6c] * (w[S2 + 4] >> 16))) >> c));
    [result + 1c] = w(w[bone_data + 3c] + (((w[SP + 50] * ((w[S2 + 4] << a) >> 16)) + (w[SP + 70] * (w[S2 + 4] >> 16))) >> c));
}
////////////////////////////////



////////////////////////////////
// funcac6c0
FP = A0 + A1 * 28;

A0 = A1;
func1e350; // get +8e0 or +8d8 model struct
S1 = V0;

[SP + 70] = w(0);

if( ( w[S1 + 0] & 00000010 ) == 0 )
{
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    V0 = w[V0 + 8e4];
    V0 = w[V0 + c];
    V0 = w[V0 + 14];
    S0 = w[V0 + 1c];

    if( S0 != 0 )
    {
        A0 = S0;
        A1 = w[S1 + 4];
        funcb3294;

        if( V0 == 0 )
        {
            A0 = S0;
            A1 = -1;
            funcb3294;
        }

        [SP + 70] = w(b[V0 + 7]);
    }



    A0 = FP;
    A1 = S1;
    A2 = SP + 10;
    funcad488;

    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    V0 = w[V0 + 8e4];
    V0 = w[V0 + c];
    V0 = w[V0 + 14];
    V1 = h[V0 + 50];
    A1 = V1;
    if( V1 < 0 )
    {
        A1 = V1 & 3f;
    }

    A0 = h[V0 + 52];

    800AC7D4	sra    v0, a1, $06
    800AC7D8	sll    v0, v0, $06
    800AC7DC	subu   v0, v1, v0
    800AC7E0	sll    v0, v0, $10
    800AC7E4	sra    s3, v0, $0f
    800AC7E8	bgez   a0, Lac7f4 [$800ac7f4]
    800AC7EC	addu   a2, a0, zero
    800AC7F0	addiu  a2, a0, $00ff

    Lac7f4:	; 800AC7F4
    800AC7F4	addu   s5, zero, zero
    800AC7F8	addiu  s4, s3, $001f
    800AC7FC	sra    v0, a2, $08
    800AC800	sll    v0, v0, $08
    800AC804	subu   v0, a0, v0
    V0 = V0 << 10;
    S1 = V0 >> 10;
    800AC810	addiu  s2, s1, $001f
    800AC818	addu   s7, s5, zero

    S0 = SP + 30;
    Lac81c:	; 800AC81C
        V0 = w[8006794c];
        A0 = w[V0 + 1c];
        V0 = w[A0 + 8e4];
        V0 = w[V0 + 0] & 00000200;

        S6 = 0;
        if( V0 != 0 )
        {
            V1 = e6000002;
            V0 = FP + S7 + bu[A0 + 8] * 10;
            S6 = w[V0 + 8];
            [S6 + 3] = b(2);
            V0 = S6 + c;
            [S6 = 4] = w(V1);
            [S6 + 8] = w(0);
        }
        else
        {
            V0 = FP + S7 + bu[A0 + 8] * 10;
            V0 = w[V0 + 8];
        }

        [S0] = w(V0);
        800AC8A0	lw     v1, $0000(s0)
        800AC8A4	addiu  v0, zero, $0009
        800AC8A8	sb     v0, $0003(v1)
        800AC8AC	lw     v1, $0000(s0)
        800AC8B0	addiu  v0, zero, $002c
        800AC8B4	sb     v0, $0007(v1)
        800AC8B8	lw     v1, $0000(s0)
        800AC8BC	nop
        800AC8C0	lbu    v0, $0007(v1)
        800AC8C4	nop
        800AC8C8	ori    v0, v0, $0002
        800AC8CC	sb     v0, $0007(v1)
        800AC8D0	lw     v1, $0000(s0)
        800AC8D4	lbu    v0, $0000(fp)
        800AC8D8	nop
        800AC8DC	sb     v0, $0004(v1)
        800AC8E0	lw     v1, $0000(s0)
        800AC8E4	lbu    v0, $0000(fp)
        800AC8E8	nop
        800AC8EC	sb     v0, $0005(v1)
        800AC8F0	lw     v1, $0000(s0)
        800AC8F4	lbu    v0, $0000(fp)
        800AC8F8	lui    t1, $8006
        800AC8FC	sb     v0, $0006(v1)
        800AC900	lw     v0, $794c(t1)
        800AC904	nop
        800AC908	lw     v0, $001c(v0)
        800AC90C	nop
        800AC910	lw     v0, $08e4(v0)
        800AC914	nop
        800AC918	lw     v0, $000c(v0)
        800AC91C	nop
        800AC920	lw     v0, $0014(v0)
        800AC924	nop
        800AC928	lhu    a0, $0052(v0)
        800AC92C	lhu    v0, $0050(v0)
        800AC930	andi   v1, a0, $0100
        800AC934	sll    v1, v1, $10
        800AC938	sra    v1, v1, $14
        800AC93C	andi   v0, v0, $03ff
        800AC940	srl    v0, v0, $06
        800AC944	ori    v0, v0, $00c0
        800AC948	or     v1, v1, v0
        800AC94C	andi   a0, a0, $0200
        800AC950	sll    a0, a0, $02
        800AC954	lw     v0, $0000(s0)
        800AC958	or     v1, v1, a0
        800AC95C	sh     v1, $0016(v0)
        800AC960	lw     v1, $0000(s0)
        800AC964	addiu  v0, zero, $3fd0
        800AC968	sh     v0, $000e(v1)

        if( S5 == 0 )
        {
            V0 = w[SP + 30];
            [V0 + c] = b(S3);
            [V0 + d] = b(S1);
            [V0 + 14] = b(S4);
            [V0 + 15] = b(S1);
            [V0 + 1c] = b(S3);
            [V0 + 1d] = b(S2);
            [V0 + 24] = b(S4);
            [V0 + 25] = b(S2);
        }
        else if( S5 == 1 )
        {
            V0 = w[SP + 34];
            [V0 + c] = b(S4);
            [V0 + d] = b(S1);
            [V0 + 14] = b(S3);
            [V0 + 15] = b(S1);
            [V0 + 1c] = b(S4);
            [V0 + 1d] = b(S2);
            [V0 + 24] = b(S3);
            [V0 + 25] = b(S2);
        }
        else if( S5 == 2 )
        {
            V0 = w[SP + 38];
            [V0 + c] = b(S3);
            [V0 + d] = b(S2);
            [V0 + 14] = b(S4);
            [V0 + 15] = b(S2);
            [V0 + 1c] = b(S3);
            [V0 + 1d] = b(S1);
            [V0 + 24] = b(S4);
            [V0 + 25] = b(S1);
        }
        else if( S5 == 3 )
        {
            V0 = w[SP + 3c];
            [V0 + c] = b(S4);
            [V0 + d] = b(S2);
            [V0 + 14] = b(S3);
            [V0 + 15] = b(S2);
            [V0 + 1c] = b(S4);
            [V0 + 1d] = b(S1);
            [V0 + 24] = b(S3);
            [V0 + 25] = b(S1);
        }

        V0 = w[8006794c];
        V0 = w[V0 + 1c];
        V0 = w[V0 + 8e4];
        V0 = w[V0 + 0] & 00000200;

        if( V0 != 0 )
        {
            V1 = e6000002;
            800ACB5C	lw     a1, $0000(s0)
            800ACB60	addiu  v0, zero, $0002
            800ACB64	addiu  a1, a1, $0028
            800ACB68	sb     v0, $0003(a1)
            800ACB6C	sw     v1, $0004(a1)
            800ACB70	sw     zero, $0008(a1)
            A0 = w[S0];
            800ACB78	jal    func62b4c [$80062b4c]
            800ACB7C	nop

            A0 = S6;
            A1 = w[S0];
            800ACB84	jal    func62b4c [$80062b4c]
        }

        S7 = S7 + 4;
        S0 = S0 + 4;
        S5 = S5 + 1;
        V0 = S5 < 4;
    800ACB98	bne    v0, zero, Lac81c [$800ac81c]

    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    R11R12 = w[V0 + 18];
    R13R21 = w[V0 + 1c];
    R22R23 = w[V0 + 20];
    R31R32 = w[V0 + 24];
    R33 = w[V0 + 28];

    V1 = SP + 10;
    IR1 = hu[V1 + 0];
    IR2 = hu[V1 + 6];
    IR3 = hu[V1 + c];
    gte_rtir12; // ir * rotmatrix.

    800ACC08	mfc2   t4,l13l21
    800ACC0C	mfc2   t5,l22l23
    800ACC10	mfc2   t6,l31l32
    800ACC14	sh     t4, $0000(v1)
    800ACC18	sh     t5, $0006(v1)
    800ACC1C	sh     t6, $000c(v1)


    800ACC20	addiu  v0, sp, $0012
    800ACC24	lhu    t4, $0000(v0)
    800ACC28	lhu    t5, $0006(v0)
    800ACC2C	lhu    t6, $000c(v0)
    800ACC30	mtc2   t4,l13l21
    800ACC34	mtc2   t5,l22l23
    800ACC38	mtc2   t6,l31l32
    800ACC3C	nop
    800ACC40	nop
    800ACC44	gte_func18t1,dqb
    800ACC48	mfc2   t4,l13l21
    800ACC4C	mfc2   t5,l22l23
    800ACC50	mfc2   t6,l31l32
    800ACC54	sh     t4, $0000(v0)
    800ACC58	sh     t5, $0006(v0)
    800ACC5C	sh     t6, $000c(v0)
    800ACC60	addiu  v0, sp, $0014
    800ACC64	lhu    t4, $0000(v0)
    800ACC68	lhu    t5, $0006(v0)
    800ACC6C	lhu    t6, $000c(v0)
    800ACC70	mtc2   t4,l13l21
    800ACC74	mtc2   t5,l22l23
    800ACC78	mtc2   t6,l31l32
    800ACC7C	nop
    800ACC80	nop
    800ACC84	gte_func18t1,dqb
    800ACC88	mfc2   t4,l13l21
    800ACC8C	mfc2   t5,l22l23
    800ACC90	mfc2   t6,l31l32
    800ACC94	sh     t4, $0000(v0)
    800ACC98	sh     t5, $0006(v0)
    800ACC9C	sh     t6, $000c(v0)
    V0 = w[8006794c];
    V0 = w[V0 + 1c] + 18;

    800ACCB4	lw     t4, $0014(v0)
    800ACCB8	lw     t5, $0018(v0)
    800ACCBC	ctc2   t4,vz2
    800ACCC0	lw     t6, $001c(v0)
    800ACCC4	ctc2   t5,rgb
    800ACCC8	ctc2   t6,otz

    V0 = SP + 24;

    800ACCD0	lhu    t5, $0004(v0)
    800ACCD4	lhu    t4, $0000(v0)
    800ACCD8	sll    t5, t5, $10
    800ACCDC	or     t4, t4, t5
    800ACCE0	mtc2   t4,r11r12
    800ACCE4	lwc2   at, $0008(v0)

    gte_rtv0tr; // v0 * rotmatrix + tr vector.
    [V0 + 0] = w(IR1);
    [V0 + 4] = w(IR2);
    [V0 + 8] = w(IR3);



    R11R12 = w[V1 + 0];
    R13R21 = w[V1 + 4];
    R22R23 = w[V1 + 8];
    R31R32 = w[V1 + c];
    R33 = w[V1 + 10];
    TRX = w[V1 + 14];
    TRY = w[V1 + 18];
    TRZ = w[V1 + 1c];



    [SP + 40] = h(-1000);
    [SP + 42] = h(0);
    VXY0 = w[SP + 40];
    VZ0 = 1000;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 30] + 8;
    [V0 + 0] = w(SXY2);
    [SP + 48] = w(SZ3);



    VXY0 = 0;
    VZ0 = 1000;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 30] + 10;
    [V0 + 0] = w(SXY2);
    V0 = w[SP + 34] + 8;
    [V0 + 0] = w(SXY2);
    [SP + 4c] = w(SZ3);



    [SP + 40] = h(1000);
    [SP + 42] = h(0);
    VXY0 = w[SP + 40];
    VZ0 = 1000;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 34] + 10;
    [V0 + 0] = w(SXY2);
    [SP + 50] = w(SZ3);



    [SP + 40] = h(-1000);
    [SP + 42] = h(0);
    VXY0 = w[SP + 40];
    VZ0 = 0;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 30] + 18;
    [V0 + 0] = w(SXY2);
    V0 = w[SP + 38] + 8;
    [V0 + 0] = w(SXY2);
    [SP + 54] = w(SZ3);

    VXY0 = 0;
    VZ0 = 0;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 30] + 20;
    [V0 + 0] = w(SXY2);
    V0 = w[SP + 34] + 18;
    [V0 + 0] = w(SXY2);
    V0 = w[SP + 38] + 10;
    [V0 + 0] = w(SXY2);
    V0 = w[SP + 3c] + 8;
    [V0 + 0] = w(SXY2);
    [SP + 58] = w(SZ3);



    [SP + 40] = h(1000);
    [SP + 42] = h(0);
    VXY0 = w[SP + 40];
    VZ0 = 0;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 34] + 20;
    [V0 + 0] = w(SXY2);
    V0 = w[SP + 3c] + 10;
    [V0 + 0] = w(SXY2);
    [SP + 5c] = w(SZ3);



    [SP + 40] = h(-1000);
    [SP + 42] = h(0);
    VXY0 = w[SP + 40];
    VZ0 = -1000;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 38] + 18;
    [V0 + 0] = w(SXY2);
    [SP + 60] = w(SZ3);



    VXY0 = 0;
    VZ0 = -1000;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 38] + 20;
    [V0 + 0] = w(SXY2);
    V0 = w[SP + 3c] + 18;
    [V0 + 0] = w(SXY2);
    [SP + 64] = w(SZ3);



    [SP + 40] = h(1000);
    [SP + 42] = h(0);
    VXY0 = w[SP + 40];
    VZ0 = -1000;
    gte_RTPS; // Perspective transform
    V0 = w[SP + 3c] + 20;
    [V0 + 0] = w(SXY2);
    [SP + 68] = w(SZ3);



    A1 = w[SP + 48];

    V1 = w[SP + 4c];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 54];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 58];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    T0 = w[8006794c];

    A3 = w[T0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];

    800AD01C	sra    v1, a1, $02
    800AD020	lw     v0, $0014(v0)
    800AD024	lw     t1, $0070(sp)
    800AD028	lh     a0, $0030(v0)
    800AD02C	addu   a1, v1, t1
    800AD030	subu   v0, zero, a0
    800AD034	slt    v0, v0, a1
    if( V0 != 0 )
    {
        800AD03C	addiu  v0, zero, $1000
        800AD040	subu   v0, v0, a0
        800AD044	slt    v0, a1, v0
        if( V0 != 0 )
        {
            A2 = 00ffffff;
            800AD054	lbu    v0, $0008(a3)
            800AD058	sll    a1, a1, $02
            800AD05C	sll    v1, v0, $04
            800AD060	addu   v1, fp, v1
            800AD064	sll    v0, v0, $02
            800AD068	addu   v0, a3, v0
            800AD06C	lui    a3, $ff00
            800AD070	lw     v0, $0010(v0)
            800AD074	lw     a0, $0008(v1)
            800AD078	addu   v0, a1, v0
            800AD07C	lw     v1, $0000(a0)
            800AD080	lw     v0, $0000(v0)
            800AD084	and    v1, v1, a3
            800AD088	and    v0, v0, a2
            800AD08C	or     v1, v1, v0
            800AD090	sw     v1, $0000(a0)
            800AD094	lw     v0, $001c(t0)
            800AD098	nop
            800AD09C	lbu    a0, $0008(v0)
            800AD0A0	nop
            800AD0A4	sll    v1, a0, $02
            800AD0A8	addu   v0, v0, v1
            800AD0AC	sll    a0, a0, $04
            800AD0B0	lw     v0, $0010(v0)
            800AD0B4	addu   a0, fp, a0
            800AD0B8	addu   a1, a1, v0
            800AD0BC	lw     v1, $0000(a1)
            800AD0C0	lw     v0, $0008(a0)
            800AD0C4	and    v1, v1, a3
            800AD0C8	and    v0, v0, a2
            800AD0CC	or     v1, v1, v0
            800AD0D0	sw     v1, $0000(a1)
        }
    }

    A1 = w[SP + 4c];

    V1 = w[SP + 50];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 58];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 5c];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    T0 = w[8006794c];
    A3 = w[T0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];
    V1 = A1 >> 2;
    V0 = w[V0 + 14];
    T1 = w[SP + 70];
    A0 = h[V0 + 30];
    A1 = V1 + T1;
    V0 = 0 - A0;
    800AD154	slt    v0, v0, a1
    if( V0 != 0 )
    {
        800AD15C	addiu  v0, zero, $1000
        800AD160	subu   v0, v0, a0
        800AD164	slt    v0, a1, v0
        if( V0 != 0 )
        {
            A2 = 00ffffff;
            800AD174	lbu    v0, $0008(a3)
            800AD178	sll    a1, a1, $02
            800AD17C	sll    v1, v0, $04
            800AD180	addu   v1, fp, v1
            800AD184	sll    v0, v0, $02
            800AD188	addu   v0, a3, v0
            800AD18C	lui    a3, $ff00
            800AD190	lw     v0, $0010(v0)
            800AD194	lw     a0, $000c(v1)
            800AD198	addu   v0, a1, v0
            800AD19C	lw     v1, $0000(a0)
            800AD1A0	lw     v0, $0000(v0)
            800AD1A4	and    v1, v1, a3
            800AD1A8	and    v0, v0, a2
            800AD1AC	or     v1, v1, v0
            800AD1B0	sw     v1, $0000(a0)
            800AD1B4	lw     v0, $001c(t0)
            800AD1B8	nop
            800AD1BC	lbu    a0, $0008(v0)
            800AD1C0	nop
            800AD1C4	sll    v1, a0, $02
            800AD1C8	addu   v0, v0, v1
            800AD1CC	sll    a0, a0, $04
            800AD1D0	lw     v0, $0010(v0)
            800AD1D4	addu   a0, fp, a0
            800AD1D8	addu   a1, a1, v0
            800AD1DC	lw     v1, $0000(a1)
            800AD1E0	lw     v0, $000c(a0)
            800AD1E4	and    v1, v1, a3
            800AD1E8	and    v0, v0, a2
            800AD1EC	or     v1, v1, v0
            800AD1F0	sw     v1, $0000(a1)
        }
    }

    A1 = w[SP + 54];

    V1 = w[SP + 60];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 64];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    T0 = w[8006794c];
    A3 = w[T0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];
    V1 = A1 >> 2;
    V0 = w[V0 + 14];
    T1 = w[SP + 70];
    A0 = h[V0 + 30];
    A1 = V1 + T1;
    V0 = 0 - A0;
    V0 = V0 < A1;
    if( V0 != 0 )
    {
        V0 = 1000 - A0;
        V0 = A1 < V0;
        if( V0 != 0 )
        {
            A2 = 00ffffff;
            800AD27C	lbu    v0, $0008(a3)
            800AD280	sll    a1, a1, $02
            800AD284	sll    v1, v0, $04
            800AD288	addu   v1, fp, v1
            800AD28C	sll    v0, v0, $02
            800AD290	addu   v0, a3, v0
            800AD294	lui    a3, $ff00
            800AD298	lw     v0, $0010(v0)
            800AD29C	lw     a0, $0010(v1)
            800AD2A0	addu   v0, a1, v0
            800AD2A4	lw     v1, $0000(a0)
            800AD2A8	lw     v0, $0000(v0)
            800AD2AC	and    v1, v1, a3
            800AD2B0	and    v0, v0, a2
            800AD2B4	or     v1, v1, v0
            800AD2B8	sw     v1, $0000(a0)
            800AD2BC	lw     v0, $001c(t0)
            800AD2C0	nop
            800AD2C4	lbu    a0, $0008(v0)
            800AD2C8	nop
            800AD2CC	sll    v1, a0, $02
            800AD2D0	addu   v0, v0, v1
            800AD2D4	sll    a0, a0, $04
            800AD2D8	lw     v0, $0010(v0)
            800AD2DC	addu   a0, fp, a0
            800AD2E0	addu   a1, a1, v0
            800AD2E4	lw     v1, $0000(a1)
            800AD2E8	lw     v0, $0010(a0)
            800AD2EC	and    v1, v1, a3
            800AD2F0	and    v0, v0, a2
            800AD2F4	or     v1, v1, v0
            800AD2F8	sw     v1, $0000(a1)
        }
    }


    A1 = w[SP + 58];

    V1 = w[SP + 5c];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 64];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V1 = w[SP + 68];
    if( A1 < V1 )
    {
        A1 = V1;
    }

    V0 = w[8006794c];
    A3 = w[V0 + 1c];
    V0 = w[A3 + 8e4];
    V0 = w[V0 + c];
    V0 = w[V0 + 14];
    A0 = h[V0 + 30];
    A1 = w[SP + 70] + A1 >> 2;
    if( ( -A0 < A1 ) && ( A1 < ( 1000 - A0 ) ) )
    {
        A1 = A1 << 2;
        frame_id = bu[A3 + 8];
        V0 = w[A3 + 10 + frame_id * 4];
        A0 = w[FP + 14 + frame_id * 10];
        [A0] = w((w[A0] & ff000000) | (w[V0 + A1] & 00ffffff);
        [V0 + A1] = w((w[V0 + A1] & ff000000) | (w[FP + 14 + frame_id * 10] & 00ffffff);
    }
}
////////////////////////////////



////////////////////////////////
// field_add_model_data_pointers
start_pointer = A0;

S1 = 0;



// add main models
system_get_pointer_to_first_element_in_script_list;
S0 = V0;
if( S0 == 0 )
{
    pointer = start_pointer;

    loopab154:	; 800AB154
        A0 = w[S0 + 4]; // pointer to allocated script memory
        if( bu[A0 + e] == 1 )
        {
            if( bu[A0 + f] & 01 )
            {
                if( bu[A0 + 5] == 4 ) // model entity type
                {
                    A0 = bu[A0 + 3b];
                    func1e350;

                    A0 = V0;
                    V0 = w[A0 + 8];
                    if( w[V0 + 1c] == 0 )
                    {
                        [pointer] = w(A0);
                        pointer = pointer + 4;
                        S1 = S1 + 1;
                    }
                }
            }
        }

        S0 = w[S0 + 0];
    800AB1CC	bne    s0, zero, loopab154 [$800ab154]
}



// add attached models after main models
// because we need to update attached model matrixes after main models
system_get_pointer_to_first_element_in_script_list;
S0 = V0;
if( S0 != 0 )
{
    loopab1e8:	; 800AB1E8
        A0 = w[S0 + 4]; // pointer to allocated script memory
        if( bu[A0 + e] == 1 )
        {
            if( bu[A0 + f] & 1 )
            {
                if( bu[A0 + 5] == 4 ) // model entity type
                {
                    A0 = bu[A0 + 3b];
                    func1e350;

                    A0 = V0;
                    V0 = w[A0 + 8];
                    A3 = w[V0 + 1c];
                    if( A3 != 0 )
                    {
                        if( S1 > 0 )
                        {
                            A2 = 0;
                            loopab260:	; 800AB260
                                V0 = w[start_pointer + A2 * 4];
                                if( w[V0 + 8] == A3 )
                                {
                                    [start_pointer + S1 * 4] = w(A0);
                                    S1 = S1 + 1;
                                    break;
                                }

                                A2 = A2 + 1;
                                V0 = A2 < S1;
                            800AB28C	bne    v0, zero, loopab260 [$800ab260]
                        }
                    }
                }
            }
        }

        S0 = w[S0 + 0];
    800AB29C	bne    s0, zero, loopab1e8 [$800ab1e8]
}



// remove pointer if it exceed memory limit
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
V0 = w[V0 + 14];
if( b[V0 + 42] != 0 )
{
    if( S1 > 0 )
    {
        A2 = 0;
        loopab2fc:	; 800AB2FC
            V0 = w[start_pointer + A2 * 4];
            model_data = w[V0 + 8];
            model_file = w[model_data + 8];
            model_file_parts = w[model_file + 10];
            if( model_file_parts >= 0 ) // if this is not direct address get pointer to model data
            {
                model_file_parts = model_file + model_file_parts;
            }

            A1 = 0;
            number_of_model = bu[model_file + 3];
            if( number_of_model > 0 )
            {
                A0 = 0;
                loopab33c:	; 800AB33C
                    A1 = A1 + hu[model_file_parts + A0 * 28 + 0];
                    A0 = A0 + 1;
                    V0 = A0 < number_of_model;
                800AB34C	bne    v0, zero, loopab33c [$800ab33c]
            }

            if( ( w[model_data + 10] + bu[model_file + 2] * 20 + bu[model_file + 3] * c + A1 * 2 ) >= ( w[80067944] + f1700 ) )
            {
                [start_pointer + A2 * 4] = w(0);
            }

            A2 = A2 + 1;
            V0 = A2 < S1;
        800AB39C	bne    v0, zero, loopab2fc [$800ab2fc]
    }
}

return S1;
////////////////////////////////



////////////////////////////////
// field_get_x_y_rotation_from_walkmesh_for_model
V1 = w[800c9df4];
V1 = h[V1 + A0 * 28 + 6];
V1 = w[800c9e00] + V1 * 28;
[A1] = h(-hu[V1 + a]);
[A2] = h(hu[V1 + 8]);
return 1;
////////////////////////////////



////////////////////////////////
// funcb7cec
if( hu[A0 + 0] & 0002 )
{
    R11R12 = w[A0 + 24];
    R13R21 = w[A0 + 28];
    R22R23 = w[A0 + 2c];
    R31R32 = w[A0 + 30];
    R33 = w[A0 + 34];

    IR1 = hu[A0 + 54];
    IR2 = 0;
    IR3 = 0;
    gte_rtir12; // ir * rotmatrix.
    [A0 + 24] = h(IR1);
    [A0 + 2a] = h(IR2);
    [A0 + 30] = h(IR3);


    IR1 = 0;
    IR2 = hu[A0 + 56];
    IR3 = 0;
    gte_rtir12; // ir * rotmatrix.
    [A0 + 26] = h(IR1);
    [A0 + 2c] = h(IR2);
    [A0 + 32] = h(IR3);

    IR1 = 0;
    IR2 = 0;
    IR3 = hu[A0 + 58];
    gte_rtir12; // ir * rotmatrix.
    [A0 + 28] = h(IR1);
    [A0 + 2e] = h(IR2);
    [A0 + 34] = h(IR3);
}
////////////////////////////////
