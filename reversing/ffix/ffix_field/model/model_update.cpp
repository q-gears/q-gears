////////////////////////////////
// funcab3cc

if( hu[800c9d44] & 0040 )
{
    A0 = SP + 60;
    A1 = SP + 64;
    800AB410	jal    func19ae0c [$8019ae0c]

    OFX = w[SP + 60] << 10;
    OFY = w[SP + 64] << 10;
}
else
{
    funcc0f08; // set OFX and OFY
}



V1 = w[8006794c];
V1 = w[V1 + 1c];
V0 = bu[V1 + 8];
A1 = w[V1 + 8e4];
A1 = w[A1 + c];
A1 = w[A1 + 14];
S7 = w[V1 + 10 + V0 * 4];
[V1 + 10 + V0 * 4] = w(S7 + h[A1 + 30] * 4);



A0 = SP + 10;
field_add_model_data_pointers;
number_of_models = V0;



// update rotation and translation data with data from scripts
if( number_of_models < 0 )
{
    S3 = 0;
    loopab488:	; 800AB488
        V1 = w[SP + 10 + S3 * 4];
        if( V1 != 0 )
        {
            model_data = w[V1 + 8];
            script = w[V1 + c];
            if( w[V1 + 0] & 00000002 )
            {
                A0 = bu[script + 3b];
                A1 = SP + 68;
                A2 = SP + 6a;
                field_get_x_y_rotation_from_walkmesh_for_model;

                [SP + 50] = h(hu[SP + 68]);
                [SP + 52] = h(hu[script + 22]); // Y rotation
                [SP + 54] = h(hu[SP + 6a]);

                A0 = SP + 50;
                A1 = model_data + 24;
                func30ea4; // create rotation matrix
            }
            else
            {
                [SP + 50] = h(hu[script + 20]);
                [SP + 52] = h(hu[script + 22]);
                [SP + 54] = h(hu[script + 24]);

                A0 = SP + 50;
                A1 = model_data + 24;
                system_create_matrix_from_angle_with_cpu;
            }

            [model_data + 38] = w(w[script + 14]); // X
            [model_data + 3c] = w(w[script + 18]); // Y
            [model_data + 40] = w(w[script + 1c]); // Z

            A0 = model_data;
            funcb7cec; // apply scaling to rotation matrix
        }

        S3 = S3 + 1;
        V0 = S3 < number_of_models;
    800AB554	bne    v0, zero, loopab488 [$800ab488]
}



// set up animation file
// and update local animation offsets to global one
if( number_of_models > 0 )
{
    S3 = 0;
    loopab568:	; 800AB568
        V1 = w[SP + 10 + S3 * 4];
        if( V1 != 0 )
        {
            model_data = w[V1 + 8];
            script = w[V1 + c];

            A0 = 4;
            A1 = 00030000 | hu[script + 36]; // currently played animation id
            A2 = 0;
            func1c7fc; // get address of animation file
            animation_file = V0;

            [model_data + c] = w(animation_file);

            // if animation file exist update local offsets to global one
            if( animation_file != 0 )
            {
                if( w[animation_file + c] >= 0 )
                {
                    [animation_file + c] = w(animation_file + w[animation_file + c]);

                    if( w[animation_file + 10] >= 0 )
                    {
                        [animation_file + 10] = w(animation_file + w[animation_file + 10]);
                    }
                }
            }
        }

        S3 = S3 + 1;
        V0 = S3 < number_of_models;
    800AB5D8	bne    v0, zero, loopab568 [$800ab568]
}



// and bone rotation matrixes and translation vectors depending on current frame in animation
if( number_of_models > 0 )
{
    S3 = 0;
    loopab5ec:	; 800AB5EC
        V1 = w[SP + 10 + S3 * 4];
        if( V1 != 0 )
        {
            model_data = w[V1 + 8];
            script = w[V1 + c];

            if( hu[model_data + 0] & 0001 )
            {
                A0 = model_data;
                A1 = bu[script + 3a]; // frame id
                field_update_animation_with_fixed_bones;

            }
            else
            {
                A0 = model_data;
                A1 = bu[script + 3a]; // frame id
                field_update_animation_without_fixed_bones;
            }
        }

        S3 = S3 + 1;
        V0 = S3 < number_of_models;
    800AB644	bne    v0, zero, loopab5ec [$800ab5ec]
}



// set main transformation matrix
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



// don't render model that too far or too close to camera (0x64 - 0x1000-0x64)
if( number_of_models > 0 )
{
    S3 = 0;
    loopab6c4:	; 800AB6C4
        V1 = w[SP + 10 + S3 * 4];
        if( V1 != 0 )
        {
            model_data = w[V1 + 8];
            bone_data = w[model_data + 20];
            // model root
            [SP + 50] = h(hu[bone_data + 14]);
            [SP + 52] = h(hu[bone_data + 18]);
            [SP + 54] = h(hu[bone_data + 1c]);

            VXY0 = w[SP + 50];
            VZ0 = w[SP + 54];
            gte_RTPS; // Perspective transform
            [SP + 58] = w(SXY2);
            [SP + 6c] = w(SZ3);

            V0 = w[8006794c];
            V0 = w[V0 + 1c];
            V0 = w[V0 + 8e4];
            V0 = w[V0 + c];
            V0 = w[V0 + 14];
            V1 = w[SP + 6c] / 4 + h[V0 + 30];
            [SP + 6c] = w(V1);
            if( V1 < 64 || V1 > ( 1000 - 64 ) )
            {
                [SP + 10 + S3 * 4] = w(0);
            }
        }

        S3 = S3 + 1;
        V0 = S3 < number_of_models;
    800AB7A0	bne    v0, zero, loopab6c4 [$800ab6c4]
}




if( number_of_models > 0 )
{
    S3 = 0;
    loopab7b8:	; 800AB7B8
        V1 = w[SP + 10 + S3 * 4];
        if( V1 != 0 )
        {
            model_data = w[V1 + 8];
            model_file = w[model_data + 8];
            number_of_parts = bu[model_file + 3];
            [1f8003fc] = w(SP);
            SP = 1f8003f0;

            if( number_of_parts != 0 )
            {
                if( ( w[V1 + 0] & 00100000 ) == 0 )
                {
                    S1 = 0;
                    loopab854:	; 800AB854
                        if( ( w[model_data + 14] & ( 1 << S1 ) ) == 0 )
                        {
                            A0 = model_data; // struct with settings
                            A1 = S1; // model id
                            field_model_rasterize_3d_vertexes;

                            A0 = model_data;
                            A1 = S1;
                            funcb5958; // insert data in packets
                        }

                        S1 = S1 + 1;
                        V0 = S1 < number_of_parts;
                    800AB888	bne    v0, zero, loopab854 [$800ab854]
                }
                else
                {
                    S1 = 0;
                    Lab808:	; 800AB808
                        if( ( w[model_data + 14] & ( 1 << S1 ) ) == 0 )
                        {
                            A0 = model_data;
                            A1 = S1;
                            funcbb508;

                            A0 = model_data;
                            A1 = S1;
                            800AB82C	jal    funcbb714 [$800bb714]
                        }

                        S1 = S1 + 1;
                        V0 = S1 < number_of_parts;
                    800AB888	bne    v0, zero, Lab808 [$800ab854]
                }
            }

            SP = w[1f8003fc];
        }

        S3 = S3 + 1;
        V0 = S3 < number_of_models;
    800AB8A0	bne    v0, zero, loopab7b8 [$800ab7b8]
}



if( number_of_models > 0 )
{
    800AB8AC	addu   s3, zero, zero
    800AB8B0	lui    s1, $8006
    800AB8B4	addiu  s0, sp, $0010

    loopab8b8:	; 800AB8B8
        800AB8B8	lw     v1, $0000(s0)
        800AB8BC	nop
        800AB8C0	beq    v1, zero, Lab8fc [$800ab8fc]
        800AB8C4	nop
        800AB8C8	lw     v0, $794c(s1)
        800AB8CC	nop
        800AB8D0	lw     v0, $001c(v0)
        800AB8D4	nop
        800AB8D8	lw     v0, $08e4(v0)
        800AB8DC	nop
        800AB8E0	lw     v0, $000c(v0)
        800AB8E4	lw     v1, $000c(v1)
        800AB8E8	lw     v0, $0014(v0)
        800AB8EC	lbu    a1, $003b(v1)
        800AB8F0	lw     a0, $002c(v0)
        800AB8F4	jal    funcac6c0 [$800ac6c0]
        800AB8F8	nop

        Lab8fc:	; 800AB8FC
        800AB8FC	addiu  s3, s3, $0001
        800AB908	addiu  s0, s0, $0004
        V0 = S3 < number_of_models;
    800AB904	bne    v0, zero, loopab8b8 [$800ab8b8]
}



if( number_of_models > 0 )
{
    800AB910	addu   s3, zero, zero

    loopab918:	; 800AB918
        800AB914	sll    v0, s3, $02
        800AB918	addu   v0, sp, v0
        800AB91C	lw     v1, $0010(v0)
        800AB920	nop
        800AB924	beq    v1, zero, Lab9a4 [$800ab9a4]
        800AB928	nop
        800AB92C	lw     v0, $0000(v1)
        800AB930	nop
        800AB934	andi   v0, v0, $1000
        800AB938	bne    v0, zero, Lab9a4 [$800ab9a4]
        800AB93C	nop
        800AB940	lw     s2, $0008(v1)
        800AB944	nop
        800AB948	lw     v0, $0050(s2)
        800AB94C	nop
        800AB950	lhu    v0, $0000(v0)
        800AB954	nop
        800AB958	sltiu  v0, v0, $0002
        800AB95C	bne    v0, zero, Lab9a4 [$800ab9a4]
        800AB960	nop
        800AB964	jal    funcab0b0 [$800ab0b0]
        800AB968	addu   a0, s2, zero
        800AB96C	bne    v0, zero, Lab9a4 [$800ab9a4]
        800AB970	nop
        800AB974	lw     v1, $0050(s2)
        800AB978	nop
        800AB97C	lbu    v0, $002c(v1)
        800AB980	nop
        800AB984	ori    v0, v0, $0001
        800AB988	sb     v0, $002c(v1)
        800AB98C	lw     v0, $0050(s2)
        800AB990	nop
        800AB994	sw     zero, $0034(v0)
        800AB998	lw     v1, $0050(s2)
        800AB99C	addiu  v0, zero, $1000
        800AB9A0	sh     v0, $003a(v1)

        Lab9a4:	; 800AB9A4
        800AB9A4	addiu  s3, s3, $0001
        800AB9B0	sll    v0, s3, $02
        V0 = S3 < number_of_models;
    800AB9AC	bne    v0, zero, loopab918 [$800ab918]
}



if( number_of_models > 0 )
{
    800AB9B8	addu   s3, zero, zero
    800AB9BC	addiu  s0, sp, $0010

    loopab9c0:	; 800AB9C0
        800AB9C0	lw     v1, $0000(s0)
        800AB9C4	nop
        if( V1 != 0 )
        {
            800AB9D0	lw     v0, $0008(v1)
            800AB9D4	nop
            800AB9D8	lw     a0, $0050(v0)
            800AB9DC	jal    funcbb090 [$800bb090]
        }

        800AB9E4	addiu  s3, s3, $0001
        800AB9F0	addiu  s0, s0, $0004
        V0 = S3 < number_of_models;
    800AB9EC	bne    v0, zero, loopab9c0 [$800ab9c0]
}



A0 = SP + 10;
A1 = number_of_models;
800AB9F8	jal    funcb2d10 [$800b2d10]

800ABA00	lui    s0, $8006
800ABA04	lw     v0, $794c(s0)
800ABA08	nop
800ABA0C	lw     v0, $001c(v0)
800ABA14	lw     v0, $0000(v0)
800ABA18	nop
800ABA1C	andi   v0, v0, $0002
if( V0 == 0 )
{
    A0 = SP + 10;
    A1 = number_of_models;
    800ABA28	jal    funcb1e8c [$800b1e8c]
}

A0 = SP + 10;
A1 = number_of_models;
800ABA34	jal    funcac02c [$800ac02c]

800ABA3C	lw     v0, $794c(s0)
800ABA40	lui    v1, $800d
800ABA44	lw     a0, $001c(v0)
800ABA48	lhu    v1, $9d44(v1)
800ABA4C	lbu    v0, $0008(a0)
800ABA50	andi   v1, v1, $0040
800ABA54	sll    v0, v0, $02
800ABA58	addu   a0, a0, v0
800ABA60	sw     s7, $0010(a0)
if( V1 == 0 )
{
    800ABA64	jal    funcc0fb0 [$800c0fb0]
}
////////////////////////////////



////////////////////////////////
// funcac02c
800AC034	sw     a1, $0044(sp)
800AC038	addiu  s5, a1, $ffff (=-$1)
800AC064	sw     a0, $0040(sp)
800AC060	bltz   s5, Lac1b8 [$800ac1b8]

800AC068	lui    fp, $0001
800AC06C	lui    s7, $0002
800AC070	sll    v0, s5, $02
800AC074	addu   s6, v0, a0

loopac078:	; 800AC078
800AC078	lw     s0, $0000(s6)
800AC07C	nop
800AC080	beq    s0, zero, Lac1ac [$800ac1ac]
800AC084	lui    v0, $8006
800AC088	lw     v0, $794c(v0)
800AC08C	addu   a1, zero, zero
800AC090	lw     v0, $001c(v0)
800AC094	lw     v1, $000c(s0)
800AC098	lw     v0, $08e4(v0)
800AC09C	lbu    a0, $003b(v1)
800AC0A0	lw     v1, $000c(v0)
800AC0A4	sll    v0, a0, $02
800AC0A8	lw     v1, $0014(v1)
800AC0AC	addu   v0, v0, a0
800AC0B0	lw     v1, $0054(v1)
800AC0B4	sll    v0, v0, $02
800AC0B8	addu   s1, v1, v0
800AC0BC	lw     v1, $0000(s0)
800AC0C0	lw     v0, $0000(s1)
800AC0C4	and    s2, v1, fp
800AC0C8	and    v0, v0, fp
800AC0CC	xor    s4, v0, s2
800AC0D0	lui    v0, $0004
800AC0D4	and    s3, v1, v0
800AC0D8	bne    s4, zero, Lac0f0 [$800ac0f0]
800AC0DC	and    v1, v1, s7
800AC0E0	bne    s3, zero, Lac0f0 [$800ac0f0]
800AC0E4	nop
800AC0E8	beq    v1, zero, Lac0f4 [$800ac0f4]
800AC0EC	nop

Lac0f0:	; 800AC0F0
800AC0F0	addiu  a1, zero, $0001

Lac0f4:	; 800AC0F4
800AC0F4	beq    a1, zero, Lac1ac [$800ac1ac]
800AC0F8	nop
800AC0FC	lw     v0, $0000(s0)
800AC100	nop
800AC104	and    v0, v0, fp
800AC108	beq    v0, zero, Lac11c [$800ac11c]
800AC10C	addiu  a1, zero, $0001
800AC110	lw     a0, $0008(s0)
800AC114	j      Lac124 [$800ac124]
800AC118	nop

Lac11c:	; 800AC11C
800AC11C	lw     a0, $0008(s0)
800AC120	addu   a1, zero, zero

Lac124:	; 800AC124
800AC124	jal    funcba190 [$800ba190]
800AC128	nop
800AC12C	beq    s2, zero, Lac14c [$800ac14c]
800AC130	nop
800AC134	lbu    a1, $0005(s1)
800AC138	lw     a0, $0008(s0)
800AC13C	sll    a1, a1, $18
800AC140	sra    a1, a1, $13
800AC144	jal    funcba3cc [$800ba3cc]
800AC148	andi   a1, a1, $ffe0

Lac14c:	; 800AC14C
800AC14C	lw     v1, $0000(s0)
800AC150	nop
800AC154	and    v0, v1, s7
800AC158	beq    v0, zero, Lac16c [$800ac16c]
800AC15C	lui    v0, $fffd
800AC160	ori    v0, v0, $ffff
800AC164	and    v0, v1, v0
800AC168	sw     v0, $0000(s0)

Lac16c:	; 800AC16C
800AC16C	lui    v1, $fffb
800AC170	lw     v0, $0000(s0)
800AC174	ori    v1, v1, $ffff
800AC178	and    v0, v0, v1
800AC17C	bne    s4, zero, Lac18c [$800ac18c]
800AC180	sw     v0, $0000(s0)
800AC184	beq    s3, zero, Lac198 [$800ac198]
800AC188	lui    v1, $fffe

Lac18c:	; 800AC18C
800AC18C	or     v0, v0, s7
800AC190	sw     v0, $0000(s0)
800AC194	lui    v1, $fffe

Lac198:	; 800AC198
800AC198	lw     v0, $0000(s1)
800AC19C	ori    v1, v1, $ffff
800AC1A0	and    v0, v0, v1
800AC1A4	or     v0, v0, s2
800AC1A8	sw     v0, $0000(s1)

Lac1ac:	; 800AC1AC
800AC1AC	addiu  s5, s5, $ffff (=-$1)
800AC1B0	bgez   s5, loopac078 [$800ac078]
800AC1B4	addiu  s6, s6, $fffc (=-$4)

Lac1b8:	; 800AC1B8
800AC1B8	lw     t0, $0044(sp)
800AC1BC	nop
800AC1C0	addiu  s5, t0, $ffff (=-$1)
800AC1C4	bltz   s5, Lac314 [$800ac314]
800AC1C8	sll    v0, s5, $02
800AC1CC	lw     t0, $0040(sp)
800AC1D0	nop
800AC1D4	addu   s6, v0, t0

loopac1d8:	; 800AC1D8
800AC1D8	lw     s0, $0000(s6)
800AC1DC	nop
800AC1E0	beq    s0, zero, Lac308 [$800ac308]

Lac1e4:	; 800AC1E4
800AC1E4	lui    v0, $8006
800AC1E8	lw     v0, $794c(v0)
800AC1EC	nop
800AC1F0	lw     v0, $001c(v0)
800AC1F4	lw     v1, $000c(s0)
800AC1F8	lw     v0, $08e4(v0)
800AC1FC	lbu    a0, $003b(v1)
800AC200	lw     v1, $000c(v0)
800AC204	sll    v0, a0, $02
800AC208	lw     v1, $0014(v1)

Lac20c:	; 800AC20C
800AC20C	addu   v0, v0, a0
800AC210	lw     v1, $0054(v1)
800AC214	sll    v0, v0, $02
800AC218	addu   s1, v1, v0
800AC21C	lw     s2, $0010(s1)
800AC220	nop
800AC224	beq    s2, zero, Lac308 [$800ac308]
800AC228	lui    v1, $0100
800AC22C	lw     v0, $0000(s2)
800AC230	nop
800AC234	and    v0, v0, v1
800AC238	beq    v0, zero, Lac308 [$800ac308]
800AC23C	nop
800AC240	lw     a0, $0008(s2)
800AC244	jal    funcbc33c [$800bc33c]
800AC248	addu   s1, zero, zero
800AC24C	lw     v0, $00f8(s2)
800AC250	nop
800AC254	lw     v0, $000c(v0)
800AC258	lw     a0, $0008(s2)
800AC25C	lbu    a1, $003a(v0)
field_update_animation_without_fixed_bones; // we build animation bone matrixes here
800AC264	addu   s4, s2, zero
800AC268	lw     v0, $0008(s2)
800AC26C	nop

Lac270:	; 800AC270
800AC270	lw     v0, $0008(v0)
800AC274	nop
800AC278	lbu    s3, $0003(v0)
800AC27C	nop
800AC280	beq    s3, zero, Lac2b4 [$800ac2b4]
800AC284	nop

loopac288:	; 800AC288
800AC288	andi   s0, s1, $00ff
800AC28C	addu   a1, s0, zero
800AC290	lw     a0, $0008(s4)
800AC294	jal    field_model_rasterize_3d_vertexes [$800b61a4]
800AC298	addiu  s1, s1, $0001
800AC29C	lw     a0, $0008(s4)
800AC2A0	jal    funcbc600 [$800bc600]
800AC2A4	addu   a1, s0, zero
800AC2A8	slt    v0, s1, s3
800AC2AC	bne    v0, zero, loopac288 [$800ac288]
800AC2B0	nop

Lac2b4:	; 800AC2B4
800AC2B4	lbu    v0, $010f(s2)
800AC2B8	nop
800AC2BC	beq    v0, zero, Lac308 [$800ac308]
800AC2C0	nop
800AC2C4	addiu  s1, s3, $ffff (=-$1)
800AC2C8	bltz   s1, Lac2f8 [$800ac2f8]
800AC2CC	nop

loopac2d0:	; 800AC2D0
800AC2D0	lbu    a2, $010c(s2)
800AC2D4	lbu    a3, $010d(s2)
800AC2D8	lbu    v0, $010e(s2)
800AC2DC	andi   a1, s1, $00ff
800AC2E0	sw     v0, $0010(sp)
800AC2E4	lw     a0, $0008(s4)
800AC2E8	jal    funcb9e4c [$800b9e4c]
800AC2EC	addiu  s1, s1, $ffff (=-$1)
800AC2F0	bgez   s1, loopac2d0 [$800ac2d0]
800AC2F4	nop

Lac2f8:	; 800AC2F8
800AC2F8	lbu    v0, $010f(s2)
800AC2FC	nop
800AC300	addiu  v0, v0, $ffff (=-$1)
800AC304	sb     v0, $010f(s2)

Lac308:	; 800AC308
800AC308	addiu  s5, s5, $ffff (=-$1)
800AC30C	bgez   s5, loopac1d8 [$800ac1d8]
800AC310	addiu  s6, s6, $fffc (=-$4)

Lac314:	; 800AC314
////////////////////////////////