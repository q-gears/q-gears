////////////////////////////////
// animation_prepare_bones_matrixes
//            A0 = w[model_data + 4] + model_id * 24;
//            A1 = SP + 10;
// A0 - offset to specific new structure header structure
// A1 - offset to camera section
// A2 - animation id (during initialization we init with 0)
// A3 - current frame (during initialization we init with 0)

model_data_struct = A0;
matrix = A1;
animation_id = A2;
frame_id = A3;

if (bu[model_data_struct + 00] != 0) // if inited
{
    // set transformation matrix and vector
    T5 = w[matrix + 00];
    T6 = w[matrix + 04];
    800AEE74	ctc2   t5,vxy0
    800AEE78	ctc2   t6,vz0
    T5 = w[matrix + 08];
    T6 = w[matrix + 0c];
    T7 = w[matrix + 10];
    800AEE88	ctc2   t5,vxy1
    800AEE8C	ctc2   t6,vz1
    800AEE90	ctc2   t7,vxy2
    T5 = w[matrix + 14];
    T6 = w[matrix + 18];
    800AEEA0	ctc2   t5,vz2
    T7 = w[matrix + 1c];
    800AEEA8	ctc2   t6,rgb
    800AEEAC	ctc2   t7,otz

    if (w[1f800000] & 2)
    {
        // calculate new translation vector base on toot translation
        T5 = (hu[model_data_struct + c] << 10) | hu[model_data_struct + 8]; // root translation X and Y
        800AEEDC	mtc2   t5,r11r12
        800AEEE0	lwc2   at, $0010(model_data_struct)
        gte_func18 t0,r11r12 // v0 * rotmatrix + tr vector
        800AEF00	swc2   t1, [1f800034]
        800AEF04	swc2   t2, [1f800038]
        800AEF08	swc2   t3, [1f80003c]



        sin_x = h[800df120 + bu[model_data_struct + 5] * 4 + 0];
        cos_x = h[800df120 + bu[model_data_struct + 5] * 4 + 2];
        sin_y = w[800df120 + bu[model_data_struct + 6] * 4 + 0];
        cos_y = w[800df120 + bu[model_data_struct + 6] * 4 + 2];
        sin_z = w[800df120 + bu[model_data_struct + 7] * 4 + 0];
        cos_z = w[800df120 + bu[model_data_struct + 7] * 4 + 2];



        800AEF60	mtc2   sin_x,l11l12
        800AEF68	mtc2   cos_y,l13l21
        800AEF70	mtc2   sin_y,l22l23
        gte_func28 t8,r11r12 // general purpose interpolation
        800AEF80	mfc2   t5,ofy
        800AEF98	mfc2   t7,h
        800AEF8C	mtc2   t5,l13l21
        800AEFA4	mtc2   t7,l31l32
        800AEF94	mtc2   cos_x,l22l23
        gte_func18 t1,dqb //  // v0 * rotmatrix + tr vector
        800AEFB4	mfc2   t5,l13l21
        800AEFB8	mfc2   t6,l22l23
        800AEFBC	mfc2   t7,l31l32
        [1f800022] = h(T5);
        [1f800028] = h(T6);
        [1f80002e] = h(T7);



        800AEFC0	mtc2   cos_x,l11l12
        800AEFC4	mtc2   cos_y,l13l21
        800AEFC8	mtc2   sin_y,l22l23
        gte_func28t8,r11r12 // general purpose interpolation
        800AEFDC	mfc2   t1,ofy
        800AEFE8	mfc2   t2,h
        800AEFF4	mtc2   sin_z,l11l12
        800AEFF8	mtc2   t1,l13l21
        800AEFFC	mtc2   sin_x,l22l23
        800AF000	mtc2   t2,l31l32
        800AF00C	general_purpose_interpolation_f
        800AF010	mtc2   siz_z,l11l12
        800AF014	mtc2   sin_y,l13l21
        800AF018	mtc2   zero,l22l23
        800AF01C	mtc2   -cos_y,l31l32
        gte_func29zero,r11r12 // general purpose interpolation
        800AF02C	mfc2   t5,ofy
        800AF030	mfc2   t6,h
        800AF034	mfc2   t7,dqa
        800AF038	sra    t5, t5, $0c
        800AF03C	andi   t5, t5, $ffff
        800AF040	mtc2   t5,l13l21
        800AF044	sra    t6, t6, $0c
        800AF048	andi   t6, t6, $ffff
        800AF04C	mtc2   t6,l22l23
        800AF050	sra    t7, t7, $0c
        800AF054	andi   t7, t7, $ffff
        800AF058	mtc2   t7,l31l32
        gte_func18 t1,dqb // v0 * rotmatrix + tr vector
        800AF068	mfc2   t5,l13l21
        800AF06C	mfc2   t6,l22l23
        800AF070	mfc2   t7,l31l32
        [1f800020] = h(T5);
        [1f800026] = h(T6);
        [1f80002c] = h(T7);        



        800AF074	mtc2   siz_z,l11l12
        800AF078	mtc2   t1,l13l21
        800AF07C	mtc2   sin_x,l22l23
        800AF080	mtc2   t2,l31l32
        800AF08C	general_purpose_interpolation_f
        800AF0A0	mtc2   -sin_z,l11l12
        800AF0A4	mtc2   sin_y,l13l21
        800AF0A8	mtc2   zero,l22l23
        800AF0B0	mtc2   -cos_y,l31l32
        gte_func29zero,r11r12 // general purpose interpolation
        800AF0C0	mfc2   t5,ofy
        800AF0C4	mfc2   t6,h
        800AF0C8	mfc2   t7,dqa
        800AF0CC	sra    t5, t5, $0c
        800AF0D0	andi   t5, t5, $ffff
        800AF0D4	mtc2   t5,l13l21
        800AF0D8	sra    t6, t6, $0c
        800AF0DC	andi   t6, t6, $ffff
        800AF0E0	mtc2   t6,l22l23
        800AF0E4	sra    t7, t7, $0c
        800AF0E8	andi   t7, t7, $ffff
        800AF0EC	mtc2   t7,l31l32
        gte_func18 t1,dqb // ir * rotmatrix
        800AF0FC	mfc2   t5,l13l21
        800AF100	mfc2   t6,l22l23
        800AF104	mfc2   t7,l31l32
        [1f800024] = h(T5);
        [1f80002a] = h(T6);
        [1f800030] = h(T7);  
    }
    else
    {
        // copy transformation matrix here
        [1f800020] = w(w[matrix + 0]);
        [1f800024] = w(w[matrix + 4]);
        [1f800028] = w(w[matrix + 8]);
        [1f80002c] = w(w[matrix + c]);
        [1f800030] = w(w[matrix + 10]);
        [1f800034] = w(w[matrix + 14]);
        [1f800038] = w(w[matrix + 18]);
        [1f80003c] = w(w[matrix + 1c]);
    }



    animation_data          = w[model_data_struct + 1c] + hu[model_data_struct + 1a] + animation_id * 10;

    bones_preferenses_data  = w[animation_data + c] + 4;
    frames_translation_data = w[animation_data + c] + hu[animation_data + 6] + frame_id * 2;
    static_translation_data = w[animation_data + c] + hu[animation_data + 8];
    frames_rotation_data    = w[animation_data + c] + hu[animation_data + a] + frame_id; // offset to animation angle

    number_of_frames = hu[animation_data + 0];
    number_of_bones  = bu[model_data_struct + 2];

    bone_id = 0;
    if (number_of_bones != 0)
    {
        Laf1c0:	; 800AF1C0
            bone_data = w[model_data_struct + 1c] + bone_id * 4;
            T4 = w[bone_data];
            parent_bone_id = (T4 << 8) >> 18; // get parent of this bone

            if ((T4 >> 18) != 0) // bone has part
            {
                bone_matrix_storage = w[model_data_struct + 20] + bone_id * 20;
            }
            else // joint
            {
                bone_matrix_storage = 0;
            }

            // default translation vector
            [1f800040 + bone_id * 20 + 14] = w(0);
            [1f800040 + bone_id * 20 + 18] = w(0);
            [1f800040 + bone_id * 20 + 1c] = w((T4 << 10) >> 10); // set length of bone

            T5 = w[1f800040 + parent_bone_id * 20 + 00];
            T6 = w[1f800040 + parent_bone_id * 20 + 04];
            800AF21C	ctc2   t5,vxy0
            800AF220	ctc2   t6,vz0
            T5 = w[1f800040 + parent_bone_id * 20 + 08];
            T6 = w[1f800040 + parent_bone_id * 20 + 0c];
            T7 = w[1f800040 + parent_bone_id * 20 + 10];
            800AF230	ctc2   t5,vxy1
            800AF234	ctc2   t6,vz1
            800AF238	ctc2   t7,vxy2
            T5 = w[1f800040 + parent_bone_id * 20 + 14];
            T6 = w[1f800040 + parent_bone_id * 20 + 18];
            800AF244	ctc2   t5,vz2
            T7 = w[1f800040 + parent_bone_id * 20 + 1c];
            800AF24C	ctc2   t6,rgb
            800AF250	ctc2   t7,otz

            A0 = w[bones_preferenses_data + 0];    // 4321 // flags for bone
            flags = bu[bones_preferenses_data + 0];    // 4321 // flags for bone
            rot_x = bu[bones_preferenses_data + 1];
            rot_y = bu[bones_preferenses_data + 2];
            rot_z = bu[bones_preferenses_data + 3];

            800AF274	mtc2   number_of_frames,l11l12
            800AF278	mtc2   rot_x,l13l21
            800AF27C	mtc2   rot_y,l22l23
            800AF280	mtc2   rot_z,l31l32
            general_purpose_interpolation_f;

            if (flags & 1)
            {
                800AF29C	mfc2   v0,ofy
                rot_x = bu[frames_rotation_data + V0];
            }

            if (flags & 2)
            {
                800AF2B8	mfc2   v0,h
                rot_y = bu[frames_rotation_data + V0];
            }

            if (flags & 4)
            {
                800AF2D4	mfc2   v0,dqa
                rot_z = bu[frames_rotation_data + V0];
            }

            T1 = w[800df120 + rot_x * 4]; // get X rotation vector
            A2 = w[800df120 + rot_y * 4]; // get Y rotation vector
            A1 = w[800df120 + rot_z * 4]; // get Z rotation vector

            S0 = T1 >> 10; // X-Y
            800AF31C	mtc2   s0,l11l12
            T2 = T1;
            A3 = A2 >> 10; // Y-Y
            800AF328	mtc2   a3,l22l23
            V1 = A2;
            T5 = V1 & FFFF; // Y-X
            800AF324	mtc2   t5,l13l21

            gte_func28t8,r11r12 // general purpose interpolation

            S2 = A1 >> 10;  // Z-Y
            S1 = A1;
            V0 = -T1;

            800AF338	mfc2   t5,ofy
            T5 = T5 & FFFF;
            800AF344	mtc2   t5,l13l21

            T6 = V0 & FFFF;
            800AF34C	mtc2   t6,l22l23

            800AF350	mfc2   t7,h
            T7 = T7 & FFFF;
            800AF35C	mtc2   t7,l31l32

            gte_func18 t1,dqb // ir * rotmatrix

            800AF374	mfc2   t5,l13l21
            800AF378	mfc2   t6,l22l23
            800AF37C	mfc2   t7,l31l32

            800AF380	mtc2   t2,l11l12

            T4 = V1 & FFFF;

            800AF388	mtc2   t4,l13l21
            800AF38C	mtc2   a3,l22l23

            [1f800040 + bone_id * 20 + 4] = h(T5);
            [1f800040 + bone_id * 20 + a] = h(T6);
            [1f800040 + bone_id * 20 + 10] = h(T7);

            gte_func28t8,r11r12 // general purpose interpolation

            if (bone_matrix_storage != 0)
            {
                [bone_matrix_storage + 4] = h(T5);
            }

            800AF3A8	mfc2   t1,ofy
            T1 = T1 & FFFF;

            800AF3B4	mfc2   t2,h
            T2 = T2 & FFFF;

            800AF3C0	mtc2   s1,l11l12
            800AF3C4	mtc2   t1,l13l21
            800AF3C8	mtc2   s0,l22l23
            800AF3CC	mtc2   t2,l31l32

            general_purpose_interpolation_f;

            if (bone_matrix_storage != 0)
            {
                [bone_matrix_storage + a] = h(T6);
            }

            800AF3EC	mtc2   s2,l11l12
            800AF3F0	mtc2   a3,l13l21
            800AF3F4	mtc2   zero,l22l23
            V0 = - A2;
            V0 = V0 & FFFF;
            800AF400	mtc2   v0,l31l32

            gte_func29zero,r11r12 // general purpose interpolation

            if (bone_matrix_storage != 0)
            {
                [bone_matrix_storage + 10] = h(T7);
            }

            800AF420	mfc2   t5,ofy
            800AF428	sra    t5, t5, $0c
            800AF42C	andi   t5, t5, $ffff
            800AF430	mtc2   t5,l13l21
            800AF434	mfc2   t6,h
            800AF43C	sra    t6, t6, $0c
            800AF440	andi   t6, t6, $ffff
            800AF444	mtc2   t6,l22l23
            800AF448	mfc2   t7,dqa
            800AF450	sra    t7, t7, $0c
            800AF454	andi   t7, t7, $ffff
            800AF458	mtc2   t7,l31l32
            gte_func18 t1,dqb // ir * rotmatrix
            800AF468	mfc2   t5,l13l21
            800AF46C	mfc2   t6,l22l23
            800AF470	mfc2   t7,l31l32
            800AF474	mtc2   s2,l11l12
            800AF478	mtc2   t1,l13l21
            800AF47C	mtc2   s0,l22l23
            800AF480	mtc2   t2,l31l32

            [1f800040 + bone_id * 20 + 0] = h(T5);
            [1f800040 + bone_id * 20 + 6] = h(T6);
            [1f800040 + bone_id * 20 + c] = h(T7);

            if (bone_matrix_storage != 0)
            {
                [bone_matrix_storage + 0] = h(T5);
            }

            general_purpose_interpolation_f;

            800AF4A4	mtc2   s1,l11l12
            800AF4A8	sll    a3, a3, $10
            800AF4AC	sra    a3, a3, $10
            800AF4B0	sub    v0, zero, a3
            800AF4B4	andi   v0, v0, $ffff
            800AF4B8	mtc2   v0,l13l21
            800AF4BC	mtc2   zero,l22l23
            800AF4C0	andi   t4, v1, $ffff
            800AF4C4	mtc2   t4,l31l32
            800AF4C8	nop
            800AF4CC	nop
            gte_func29zero,r11r12 // general purpose interpolation

            if (bone_matrix_storage != 0)
            {
                [bone_matrix_storage + 6] = h(T6);
            }

            800AF4E0	mfc2   t5,ofy
            800AF4E8	sra    t5, t5, $0c
            800AF4EC	andi   t5, t5, $ffff
            800AF4F0	mtc2   t5,l13l21
            800AF4F4	mfc2   t6,h
            800AF4FC	sra    t6, t6, $0c
            800AF500	andi   t6, t6, $ffff
            800AF504	mtc2   t6,l22l23
            800AF508	mfc2   t4,dqa
            800AF510	sra    t4, t4, $0c
            800AF514	andi   t4, t4, $ffff
            800AF518	mtc2   t4,l31l32
            gte_func18 t1,dqb // ir * rotmatrix

            if (bone_matrix_storage != 0)
            {
                [bone_matrix_storage + c] = h(T7);
            }

            800AF538	mfc2   t5,l13l21
            800AF53C	mfc2   t6,l22l23
            800AF540	mfc2   t7,l31l32

            if (w[1f800000] & 1)
            {
                800AF558	mtc2   number_of_frames,l11l12
                A2 = w[bones_preferenses_data + 4];

                V1 = A2 & 00FF0000;
                if (flags & 40)
                {
                    800AF570	mtc2   v0,l13l21
                    800AF57C	general_purpose_interpolation_f
                    800AF584	mfc2   v0,ofy

                    [1f800040 + bone_id * 20 + 1c] = w(w[1f800040 + bone_id * 20 + 1c] + h[frames_translation_data + V0 * 2]);
                }
                else if (V1 != 00FF0000)
                {
                    V0 = V1 >> 10;
                    [1f800040 + bone_id * 20 + 1c] = w(w[1f800040 + bone_id * 20 + 1c] + h[static_translation_data + V0 * 2]);
                }

                V1 = A2 & 000000FF;
                if (flags & 10)
                {
                    800AF5C0	mtc2   v1,l13l21
                    general_purpose_interpolation_f
                    800AF5D0	mfc2   v0,ofy

                    [1f800040 + bone_id * 20 + 14] = w(h[frames_translation_data + V0 * 2]);
                }
                else if (V1 != 000000FF)
                {
                    [1f800040 + bone_id * 20 + 14] = w(h[static_translation_data + V1 * 2]);
                }

                V1 = A2 & 0000FF00;
                if (flags & 20)
                {
                    V0 = V1 >> 8;
                    800AF610	mtc2   v0,l13l21
                    general_purpose_interpolation_f;
                    800AF620	mfc2   v0,ofy

                    [1f800040 + bone_id * 20 + 18] = w(h[frames_translation_data + V0 * 2]);
                }
                else if (V1 != 0000FF00)
                {
                    V0 = V1 >> 8;
                    [1f800040 + bone_id * 20 + 18] = w(h[static_translation_data + V0 * 2]);
                }
            }

            T4 = hu[1f800040 + bone_id * 20 + 18];
            V1 = hu[1f800040 + bone_id * 20 + 14];
            T4 = T4 << 10;
            V1 = V1 | T4;
            800AF660	mtc2   v1,r11r12

            800AF664	lwc2   at, $001c(1f800040 + bone_id * 20)

            [1f800040 + bone_id * 20 + 2] = h(T5);
            [1f800040 + bone_id * 20 + 8] = h(T6);
            [1f800040 + bone_id * 20 + e] = h(T7);
            gte_func18 t0,r11r12 // v0 * rotmatrix + tr vector

            if (bone_matrix_storage != 0)
            {
                [bone_matrix_storage + 2] = h(T5);
                [bone_matrix_storage + 8] = h(T6);
                [bone_matrix_storage + e] = h(T7);
            }

            800AF690	swc2   t1, $0014(1f800040 + bone_id * 20)
            800AF694	swc2   t2, $0018(1f800040 + bone_id * 20)
            800AF698	swc2   t3, $001c(1f800040 + bone_id * 20)

            if (bone_matrix_storage != 0)
            {
                800AF6A4	swc2   t1, $0014(bone_matrix_storage)
                800AF6A8	swc2   t2, $0018(bone_matrix_storage)
                800AF6AC	swc2   t3, $001c(bone_matrix_storage)
            }

            bone_id = bone_id + 1;
            V0 = bone_id < number_of_bones;
            S5 = S5 + 8;
        800AF6B4	bne    v0, zero, Laf1c0 [$800af1c0]
    }
}

return;
////////////////////////////////
