////////////////////////////////
// func1e742c
// A0 = model index
// A1 = loading flags (0 in most cases)
// A2 = loaded animation offset
// A3 = loaded model offset
// a0=00000000 a1=00000000 a2=80190F44 a3=801C9038 

// enemy robot
a0=00000000 a1=00000000 a2=80190F44 a3=801C9038 
v0=00000240 v1=00000000 at=800B00FC ra=80077274 sp=801FFE70
t0=001FFFFF t1=03FFFFFF t2=FE1FFFFF t3=FDFFFFFF t4=80191934
t5=8019193C t6=00001000 t7=801FFE20 t8=00000000 t9=00000000
s0=80059AE0 s1=00000000 s2=800B16C8 s3=00000000 s4=000000fd
s5=00FC0000 s6=80059AB4 s7=800B16C0 s8=80200000 
gp=80058810 k0=80040364 k1=00006418 lo=66666685 hi=00000014
pc=801E742C code=27BDFF30 cycle=A8F0FCA2 interrupt=00000000

// weltall
a0=00000000 a1=00000000 a2=80192180 a3=801CFD48 
v0=00000240 v1=00000000 at=80060000 ra=800A0800 sp=801FFE58
t0=00000000 t1=00283028 t2=0000183A t3=0C6FDD41 t4=00001eb4
t5=00000000 t6=FFAF0000 t7=00000165 t8=DBA8F994 t9=fffff03a
s0=00000000 s1=80059AE0 s2=00000023 s3=800B16C0 s4=80059ad4
s5=00000000 s6=800B1829 s7=00000000 s8=80200000 
gp=80058810 k0=800A131C k1=00006418 lo=00000064 hi=00000000
pc=801E742C code=27BDFF30 cycle=B89F0F8A interrupt=00000000


801E742C	addiu  sp, sp, $ff30 (=-$d0)

S7 = w[SP + f0];
S0 = A1;
model_file_pointer = A3;
animation_file_pointer = A2;

[SP + 50] = w(A0);

[SP + 68] = h(hu[SP + e0]);
[SP + 70] = h(hu[SP + e4]);
[SP + 78] = h(hu[SP + e8]);
[SP + 80] = h(hu[SP + ec]);

A0 = 4;
A1 = 0;
func322bc;

T0 = w[SP + 50];
if (T0 < a)
{
    [SP + 58] = h(S0);

    V0 = w[801e8670 + T0 * 4];
    if (V0 == 0)
    {
        A0 = 134;
        A1 = 0;
        system_memory_allocate; // allocate 134 bytes of memory
        S3 = V0;

        [S3 + 62] = b(0);
        [S3 + 63] = b(0);

        if ((S0 & 1) == 0)
        {
            // update global offsets for files in model pack
            A0 = model_file_pointer;
            system_set_pack_global_pointers;

            // update global offsets for file 3
            A0 = w[model_file_pointer + 10];
            system_set_pack_global_pointers;
        }

        if ((S0 & 4) == 0)
        {
            A0 = animation_file_pointer;
            system_set_pack_global_pointers; // update global offsets for files in animations

            A0 = w[animation_file_pointer + 8];
            system_set_pack_global_pointers; // update global offsets for files in animation_1

            S1 = w[animation_file_pointer + 4];
            A0 = S1;
            system_set_pack_global_pointers; // update global offsets for files in animation_0

            A0 = w[S1 + 4];
            system_set_pack_global_pointers; // update global offsets for files in animation_0_0

            S0 = w[animation_file_pointer + 8];
            if (w[S0 + c] != w[S0 + 8])
            {
                A0 = w[S0 + 8];
                A1 = 0;
                func384f4;

                if (V0 == 0)
                {
                    A0 = w[S0 + 8];
                    func382d0;

                    [S3 + 62] = b(1);
                }
            }
        }

        T0 = w[model_file_pointer + 10]; // offset to 3rd file in model
        [SP + 88] = w(T0);
        model_3_0_pointer = S2 = w[T0 + 4]; // 1st file in 3rd file in model
        [S3 + 24] = h(hu[model_3_0_pointer + 2]);
        [S3 + 26] = h(hu[model_3_0_pointer + 4]);
        [S3 + 28] = h(hu[model_3_0_pointer + 6]);
        [S3 + 2a] = b(bu[model_3_0_pointer + a]);
        [S3 + 4a] = h(hu[model_3_0_pointer + c]);

        [801e8670 + w[SP + 50] * 4] = w(S3); // store pointer to model data.



        if (hu[model_3_0_pointer + c] & 0200)
        {
            A0 = 2;
            A1 = 2;
            A2 = 40;
            A3 = 40;
            func30798;
        }

        T0 = hu[SP + 58];
        if ((T0 & 1) == 0)
        {
            S4 = 0;
            if ((T0 & 40) == 0)
            {
                S4 = (hu[S3 + 4a] & 4) == 0;
            }

            A0 = w[model_file_pointer + 4]; // textures pointer
            A1 = S4;
            A2 = h[SP + 68];
            A3 = h[SP + 70];
            [SP + 10] = w(A1);
            [SP + 14] = w(h[SP + 78]);
            [SP + 18] = w(h[SP + 80]);
            func2dbf4; // load textures?



            size_of_model = w[model_file_pointer + c] - w[model_file_pointer + 8]; // model 3d data size

            // allocate memory
            A0 = size_of_model;
            A1 = 1;
            system_memory_allocate;

            // copy to allocated memory
            A0 = V0;
            A1 = w[model_file_pointer + 8]; // model pointer
            [801e8638] = w(A0);
            A2 = size_of_model;
            system_copy_memory;

            [801e8634] = w(0);
            loop1e76bc:	; 801E76BC
                V0 = w[801e85f4 + w[801e8634] * 8];
                if (V0 == 0)
                {
                    break;
                }

                [801e8634] = w(w[801e8634] + 1);
                V0 = w[801e8634] < 8;
            801E76F0	bne    v0, zero, loop1e76bc [$801e76bc]

            A0 = w[801e8638];
            A1 = 801e85f4 + w[801e8634] * 8;
            func1dc22c; // set pointers to model parts
        }



        [S3 + 0] = w(801e85f4 + w[801e8634] * 8); // store pointer to part data



        if ((hu[SP + 58] & 40) == 0)
        {
            if (hu[S3 + 4a] & 0004)
            {
                A2 = 2; // calculate and store lighing for the first time and then use stored data
                A3 = 0; // not use default TX TY clutX and clutY
                [SP + 10] = w(0);
                [SP + 14] = w(0);
                [SP + 18] = w(0);
                [SP + 1c] = w(0);
            }
            else
            {
                A2 = 2; // calculate and store lighing for the first time and then use stored data
                A3 = 1; // use default TX TY clutX and clutY
                [SP + 10] = w(h[SP + 68]); // TX
                [SP + 14] = w(h[SP + 70]); // TY
                [SP + 18] = w(h[SP + 78]); // clutX
                [SP + 1c] = w(h[SP + 80]); // clutY
            }
        }
        else
        {
            A2 = 0; // not calculate lighting
            A3 = 0; // not use default TX TY clutX and clutY
            [SP + 10] = w(0);
            [SP + 14] = w(0);
            [SP + 18] = w(0);
            [SP + 1c] = w(0);
        }

        A0 = w[S3 + 0];
        A1 = w[model_file_pointer + c]; // hierarchy pointer
        load_init_skeleton_data_create_packets;
        [S3 + 4] = w(V0);

        // set some initial root translation for model
        if (S7 != 0)
        {
            V1 = w[S3 + 4];
            [V1 + 5c] = w(h[S7 + 0]);
            [V1 + 60] = w(h[S7 + 2]);
            [V1 + 64] = w(h[S7 + 4]);
        }

        T0 = hu[SP + 58];
        if ((T0 & 0001) == 0)
        {
            [S3 + 90] = h(hu[SP + 68]);
            [S3 + 92] = h(hu[SP + 70]);
            [S3 + 94] = h(hu[SP + 78]);
            [S3 + 96] = h(hu[SP + 80]);
        }
        else
        {
            [S3 + 90] = h(-1);
        }

        if ((T0 & 0004) == 0 && (T0 & 0080) == 0)
        {
            [S3 + ac] = w(animation_file_pointer);
        }
        else
        {
            [S3 + ac] = w(0);
        }



        // init 2 monochrome quads
        S4 = 0;
        loop1e78a0:	; 801E78A0
            A0 = S3 + b8 + S4 * 28;
            func43b28;

            A0 = S3 + b8 + S4 * 28;
            A1 = 1;
            system_set_draw_packet_transparency; // add some flag

            [S3 + b8 + S4 * 28 + 4] = b(40); // R
            [S3 + b8 + S4 * 28 + 5] = b(40); // G
            [S3 + b8 + S4 * 28 + 6] = b(40); // B

            A0 = 100;
            A1 = f3;
            func438d0; // pack clut data
            [S3 + b8 + S4 * 28 + 0e] = h(V0);

            A0 = 0;
            A1 = 2;
            A2 = 280;
            A3 = 100;
            func43894; // pack tex page settings
            [S3 + b8 + S4 * 28 + 16] = b(V0);

            [S3 + b8 + S4 * 28 + 0c] = b(0);
            [S3 + b8 + S4 * 28 + 0d] = b(e0);

            [S3 + b8 + S4 * 28 + 14] = b(0f);
            [S3 + b8 + S4 * 28 + 15] = b(e0);

            [S3 + b8 + S4 * 28 + 1c] = b(0);
            [S3 + b8 + S4 * 28 + 1d] = b(ef);

            [S3 + b8 + S4 * 28 + 24] = b(0f);
            [S3 + b8 + S4 * 28 + 25] = b(ef);

            S4 = S4 + 1;
            V0 = S4 < 2;
        801E791C	bne    v0, zero, loop1e78a0 [$801e78a0]



        [S3 + 1c] = h(hu[model_3_0_pointer + 8]);
        [S3 + 10c] = b(bu[model_3_0_pointer + e]);

        A0 = S3;
        func1e8510; // init struct array for something in [S3 + 10c]



        V0 = bu[model_3_0_pointer + 10];
        [S3 + 10e] = b(V0);
        if (V0 != 0)
        {
            A0 = V0 * 30;
            A1 = 0;
            system_memory_allocate;
            [S3 + 118] = w(V0);

            V1 = bu[S3 + 10e];
            if (V1 > 0)
            {
                S4 = 0;
                loop1e7980:	; 801E7980
                    V0 = w[S3 + 118] + S4 * 30;

                    [V0 + 4] = w(0);
                    [V0 + 8] = w(0);
                    [V0 + c] = w(0);
                    [V0 + 1a] = h(0);

                    S4 = S4 + 1;
                    V0 = S4 < bu[S3 + 10e];
                801E79CC	bne    v0, zero, loop1e7980 [$801e7980]
            }
        }



        // unknown
        V0 = bu[model_3_0_pointer + 12];
        [S3 + 10d] = b(V0);
        if (V0 != 0)
        {
            S2 = model_3_0_pointer + 14;
            A0 = V0 * 24;
            A1 = 0;
            system_memory_allocate;
            S1 = V0;
            [S3 + 114] = w(S1);

            V0 = bu[S3 + 10d];
            if (V0 > 0)
            {
                S4 = 0;
                S0 = S1 + 18;
                S6 = w[SP + 88];

                L1e7a24:	; 801E7A24
                    S5 = h[S2 + 22];

                    [S1 + 0] = h(hu[S2 + 0]);
                    S2 = S2 + 2;
                    A2 = h[S2 + 0];
                    S2 = S2 + 2;
                    A3 = h[S2 + 0];
                    S2 = S2 + 2;
                    [SP + 10] = w(h[S2 + 0]);
                    S2 = S2 + 2;

                    [SP + 14] = w(h[S2 + 0]);
                    S2 = S2 + 2;

                    [SP + 18] = w(h[S2 + 0]);
                    S2 = S2 + 2;

                    [SP + 1c] = w(S5);

                    [SP + 20] = w(h[S2 + 0] + h[SP + 68]);
                    S2 = S2 + 2;

                    [SP + 24] = w(h[S2 + 0] + h[SP + 70]);
                    S2 = S2 + 2;

                    V0 = h[S2 + 0];
                    T0 = hu[SP + 80];
                    S2 = S2 + 2;
                    [SP + 28] = w(V0);

                    [SP + 2c] = w(h[S2 + 0]);
                    S2 = S2 + 2;

                    V1 = hu[S2];
                    S2 = S2 + 2;
                    V0 = (T0 << 10) >> 10;
                    [SP + 34] = w(V0);

                    [SP + 24] = w(h[S2 + 0] + h[SP + 78]);
                    S2 = S2 + 2;

                    V1 = T0 + V1;
                    V1 = (T1 << 10) >> 10;
                    [SP + 30] = w(V1);

                    [SP + 38] = w(bu[S2 + 0]);
                    S2 = S2 + 2;

                    [SP + 3c] = w(bu[S2 + 0]);
                    S2 = S2 + 2;

                    [SP + 40] = w(bu[S2 + 0]);
                    S2 = S2 + 2;

                    [SP + 44] = w(bu[S2 + 0]);
                    S2 = S2 + 2;

                    [SP + 48] = w(bu[S2 + 0]);
                    S2 = S2 + 2;

                    V0 = bu[S2];
                    A0 = S1;
                    [SP + 4c] = w(V0);
                    A1 = w[S6 + 8];
                    S2 = S2 + 4;
                    801E7B34	jal    func1e1a14 [$801e1a14]

                    if (S5 > 0)
                    {
                        A1 = 0;

                        loop1e7b44:	; 801E7B44
                            801E7B44	lhu    a0, $0000(s2)
                            801E7B48	addiu  s2, s2, $0002
                            801E7B4C	sll    v1, a1, $04
                            801E7B50	lw     v0, $0000(s0)
                            801E7B54	addiu  a1, a1, $0001
                            801E7B58	addu   v0, v1, v0
                            801E7B5C	sh     a0, $0006(v0)
                            801E7B60	lw     v0, $0000(s0)
                            801E7B64	lhu    a0, $0000(s2)
                            801E7B68	addiu  s2, s2, $0002
                            801E7B6C	addu   v0, v1, v0
                            801E7B70	sh     a0, $000e(v0)
                            801E7B74	lw     v0, $0000(s0)
                            801E7B78	lhu    a0, $0000(s2)
                            801E7B7C	addiu  s2, s2, $0002
                            801E7B80	addu   v0, v1, v0
                            801E7B84	sh     a0, $0000(v0)
                            801E7B88	lw     v0, $0000(s0)
                            801E7B8C	lhu    a0, $0000(s2)
                            801E7B90	addiu  s2, s2, $0002
                            801E7B94	addu   v0, v1, v0
                            801E7B98	sh     a0, $0002(v0)
                            801E7B9C	lw     v0, $0000(s0)
                            801E7BA0	lhu    a0, $0000(s2)
                            801E7BA4	addiu  s2, s2, $0002
                            801E7BA8	addu   v1, v1, v0
                            801E7BB4	sh     a0, $0004(v1)
                            V0 = A1 < S5;
                        801E7BB0	bne    v0, zero, loop1e7b44 [$801e7b44]
                    }

                    801E7BB8	addiu  s6, s6, $0004
                    801E7BBC	addiu  s4, s4, $0001
                    801E7BC0	addiu  s0, s0, $0024
                    801E7BC4	lbu    v0, $010d(s3)
                    801E7BC8	nop
                    801E7BCC	slt    v0, s4, v0
                    801E7BD4	addiu  s1, s1, $0024
                801E7BD0	bne    v0, zero, L1e7a24 [$801e7a24]
            }
        }



        [S3 + 20] = b(bu[SP + 50]);
        [S3 + 22] = b(0);
        [S3 + 34] = b(1);

        T0 = hu[SP + 58];
        if ((T0 & 40) == 0)
        {
            [S3 + b0] = w(w[animation_file_pointer + 8]); // animation_1

            A0 = S3;
            S1 = w[animation_file_pointer + 4]; // animation_0
            A1 = 801e86a8; // not used
            A2 = S1 + 8;
            A3 = w[S1 + 4]; // animation_0_0
            func1e3534;

            A0 = S3;
            A1 = S3;
            A2 = 801e86a8;
            A3 = 0; // animation to execute
            func1e35d0;
        }



        T0 = hu[SP + 58];
        if ((T0 & 2) == 0)
        {
            A0 = w[801e8638]; // pointer to model parts
            func2c454;

            A0 = w[801e8638]; // pointer to model parts
            801E7C6C	jal    func2c2cc [$8002c2cc]

            A0 = w[801e8638]; // pointer to model parts
            801E7C7C	jal    func316a4 [$800316a4]

            S1 = V0;

            A0 = V0;
            A1 = 0;
            system_memory_allocate;
            S0 = V0;

            A0 = S0;
            A1 = w[801e8638];
            A2 = S1;
            system_copy_memory;

            801E7CAC	lui    a0, $801f
            801E7CB0	lw     a0, $8638(a0)
            801E7CB4	jal    func31f0c [$80031f0c]
            801E7CB8	nop
            801E7CBC	lw     a0, $0000(s3)
            801E7CC0	jal    func1dce18 [$801dce18]
            801E7CC4	addu   a1, zero, zero

            A0 = S0;
            801E7CC8	lw     a1, $0000(s3)
            801E7CCC	jal    func1dc22c [$801dc22c]

            801E7CD8	sw     s0, $00a8(s3)
        }
        else
        {
            801E7CDC	sw     zero, $00a8(s3)
        }
    }
}
////////////////////////////////



////////////////////////////////
// func1dc22c
S2 = A0; // model 3d data file
S1 = A1;

A0 = 4;
A1 = 0;
func322bc;

A0 = S2;
func2c1f8; // sets global offsets for model file and return number of parts
number_of_parts = V0;

A0 = number_of_parts * 4;
A1 = 0;
system_memory_allocate;

[S1 + 0] = w(V0);
[S1 + 4] = w(number_of_parts);

if (V0 != 0 && number_of_parts != 0)
{
    A1 = 0;
    loop1dc28c:	; 801DC28C
        V1 = w[S1 + 0];
        [V1 + A1 * 4] = w(S2 + 10 + A1 * 38); // pointer to parts header data

        A1 = A1 + 1;
        V0 = A1 < number_of_parts;
    801DC2A8	bne    v0, zero, loop1dc28c [$801dc28c]
}

return S1;
////////////////////////////////



////////////////////////////////
// load_init_skeleton_data_create_packets

lighting_settings = A2;
use_default_settings = A3;

S4 = A0;
skeleton_pointer = A1;
T0 = h[SP + 10]; // TX as 0x3c0
FP = h[SP + 14]; // TY as 0x100
S7 = h[SP + 18]; // clut X
S6 = h[SP + 1c]; // clut Y



A0 = 4;
A1 = 0;
func322bc;



number_of_bones = 0;
while ((hu[skeleton_pointer + number_of_bones * 4 + 0] < w[S4 + 4]) || (hu[skeleton_pointer + number_of_bones * 4 + 0] == ffff))
{
    number_of_bones = number_of_bones + 1;
}



if (number_of_bones == 0)
{
    return 0;
}



number_of_bones = number_of_bones + 1;
A0 = number_of_bones * 7c;
A1 = 0;
system_memory_allocate;
if (V0 == 0)
{
    return 0;
}
S1 = V0;

// init root bone
[S1 + 0] = h(0);
[S1 + 4] = b(1);
[S1 + 5] = b(1);
[S1 + 6] = b(1);
[S1 + 7] = b(0);
[S1 + 8] = h(ffff);
[S1 + a] = h(number_of_bones);
[S1 + 4c] = h(1000);
[S1 + 4e] = h(1000);
[S1 + 50] = h(1000);
[S1 + 54] = h(0);
[S1 + 56] = h(0);
[S1 + 58] = h(0);
[S1 + 5c] = w(0);
[S1 + 60] = w(0);
[S1 + 64] = w(0);
[S1 + 68] = w(0);
[S1 + 6c] = w(0);
[S1 + 70] = w(0);
[S1 + 74] = w(0);
[S1 + 78] = w(0);



S5 = 1;
S0 = S1 + 7c;

while ((hu[skeleton_pointer + 0] < w[S4 + 4]) || (hu[skeleton_pointer + 0] == ffff))
{
    part_id = hu[skeleton_pointer + 0];
    parent_id = hu[skeleton_pointer + 2];

    // set link to parent
    if (parent_id == ffff)
    {
        [S0 + 0] = w(0)
    }
    else
    {
        [S0 + 0] = w(S1 + parent_id * 7c + 7c);
    }

    [S0 + 4] = b(1);
    [S0 + 5] = b(1);
    [S0 + 6] = b(0);
    [S0 + 7] = b(1);
    [S0 + 8] = h(part_id);
    [S0 + a] = h(S5);
    [S0 + 4c] = h(1000);
    [S0 + 4e] = h(1000);
    [S0 + 50] = h(1000);
    [S0 + 52] = h(0);

    if (part_id != ffff)
    {
        pointer_to_part = w[w[S4 + 0] + part_id * 4];

        A0 = pointer_to_part;
        A1 = S0 + 68;
        A2 = S0 + 6c;
        system_allocate_memory_for_packets;

        if (w[S0 + 68] == 0) // we don't have enough memory
        {
            A0 = S1;
            func1dcd8c;

            return 0;
        }

        // set some variables
        if (use_default_settings != 0)
        {
            A0 = T0; // TX as 0x3c0
            A1 = FP; // TY as 0x100
            system_set_default_tex_page_settings;

            A0 = S7; // clut X
            A1 = S6; // clut Y
            system_set_default_clut_settings;
        }

        A0 = pointer_to_part;
        A1 = w[S0 + 68];
        A2 = lighting_settings;
        system_fill_packets_drafts_for_model_part; // prepare packets

        A0 = w[S0 + 6c]; // destination
        A1 = w[S0 + 68]; // source
        A2 = w[pointer_to_part + 34]; // size
        system_copy_memory;
    }
    else
    {
        [S0 + 68] = w(0);
        [S0 + 6c] = w(0);
    }

    [S0 + 54] = h(0);
    [S0 + 56] = h(0);
    [S0 + 58] = h(0);
    [S0 + 5c] = w(0);
    [S0 + 60] = w(0);
    [S0 + 64] = w(0);
    [S0 + 70] = w(0);
    [S0 + 74] = w(0);
    [S0 + 78] = w(0);

    S0 = S0 + 7c;
    S5 = S5 + 1;
    skeleton_pointer = skeleton_pointer + 4;
}

return S1;
////////////////////////////////



////////////////////////////////
// func1e3534
[A0 + 8] = w(A2);
[A0 + c] = w(0);
[A0 + 10] = w(0);
[A0 + 14] = w(A3);
[A0 + 18] = w(0);
[A0 + 1e] = h(-1);
[A0 + 2b] = b(0);
[A0 + 35] = b(0);
[A0 + 36] = b(0);
[A0 + 37] = b(0);
[A0 + 38] = b(0);
[A0 + 39] = b(6b);
[A0 + 3a] = h(-1);
[A0 + 3c] = h(-1);
[A0 + 58] = h(0);
[A0 + 5c] = b(-1);
[A0 + 70] = h(0);
[A0 + 72] = h(0);
[A0 + 74] = h(0);
[A0 + 76] = h(0);
[A0 + 78] = h(0);
[A0 + 7a] = h(0);
[A0 + 7c] = h(0);
[A0 + 7e] = h(0);
[A0 + 80] = h(0);
[A0 + 82] = h(0);
[A0 + 84] = h(0);
[A0 + 86] = h(0);
[A0 + 88] = h(0);
[A0 + 8a] = h(0);
[A0 + 8c] = h(0);
[A0 + 8e] = h(1);
[A0 + 98] = h(-1);
////////////////////////////////



////////////////////////////////
// func1e35d0
if (A0 == 0 || A1 == 0)
{
    return;
}

if (bu[A0 + 2b] != 0)
{
    if (bu[A0 + 2b] < 5)
    {
        [A0 + 2b] = b(bu[A0 + 2b] + 1);
    }

    V0 = bu[A0 + 2b];
    [A0 + V0 + 2a] = b(bu[A1 + 20]);
    [A0 + V0 + 2e] = b(A3);
}
else
{
    if (A3 < 50)
    {
        V0 = w[A1 + 8] + A3 * 4;
        [A0 + 10] = w(w[V0]);
    }
    else
    {
        V0 = w[A1 + c];
        V0 = w[V0 + 4] + A3 * 4 - 138;
        [A0 + 10] = w(w[V0]);
    }

    [A0 + 23] = b(0);
    [A0 + 40] = h(0);
    [A0 + 42] = h(0);
    [A0 + 4c] = w(0);
    [A0 + 50] = w(0);
    [A0 + 54] = w(0);
    [A0 + 10a] = h(hu[801e863c]);

    A1 = A2;
    A2 = -1;
    A3 = 1;
    [SP + 10] = w(0);
    func1e39f0;
}
////////////////////////////////



////////////////////////////////
// func1e8510
S0 = A0;
V0 = bu[S0 + 10c];

if (V0 == 0)
{
    return;
}

A0 = V0 * 70;
A1 = 0;
system_memory_allocate;
A1 = V0;

if (bu[S0 + 10c] > 0)
{
    A0 = 0;

    loop1e855c:	; 801E855C
        [A1 + A0 * 70 + 0] = h(-1);
        [A1 + A0 * 70 + 8] = w(0);

        A0 = A0 + 1;
        V0 = A0 < bu[S0 + 10c];
    801E8570	bne    v0, zero, loop1e855c [$801e855c]
}

[S0 + 110] = w(A1);
////////////////////////////////



////////////////////////////////
// func1e1a14
801E1A14	addiu  sp, sp, $fed0 (=-$130)
801E1A18	sw     s1, $010c(sp)
801E1A1C	addu   s1, a1, zero
801E1A20	sw     ra, $012c(sp)
801E1A24	sw     fp, $0128(sp)
801E1A28	sw     s7, $0124(sp)
801E1A2C	sw     s6, $0120(sp)
801E1A30	sw     s5, $011c(sp)
801E1A34	sw     s4, $0118(sp)
801E1A38	sw     s3, $0114(sp)
801E1A3C	sw     s2, $0110(sp)
801E1A40	sw     s0, $0108(sp)
801E1A44	sw     a0, $0010(sp)
801E1A48	lhu    v0, $0000(s1)
801E1A4C	lw     t6, $0010(sp)
801E1A50	addiu  s1, s1, $0002
801E1A54	sh     v0, $0004(t6)
801E1A58	lhu    v0, $0000(s1)
801E1A5C	nop
801E1A60	sll    v0, v0, $01
801E1A64	sh     v0, $0006(t6)
801E1A68	lw     t5, $014c(sp)
801E1A6C	lw     s0, $0140(sp)
801E1A70	lw     s2, $0144(sp)
801E1A74	lw     s3, $0148(sp)
801E1A78	lhu    t6, $0150(sp)
801E1A7C	sw     t5, $0018(sp)
801E1A80	lhu    t5, $0154(sp)
801E1A84	sh     t6, $0020(sp)
801E1A88	lhu    t6, $0158(sp)
801E1A8C	sh     t5, $0028(sp)
801E1A90	lhu    t5, $015c(sp)
801E1A94	sh     t6, $0030(sp)
801E1A98	lhu    t6, $0160(sp)
801E1A9C	sh     t5, $0038(sp)
801E1AA0	lhu    t5, $0164(sp)
801E1AA4	sh     t6, $0040(sp)
801E1AA8	lbu    t6, $0168(sp)
801E1AAC	sh     t5, $0048(sp)
801E1AB0	sb     t6, $0050(sp)
801E1AB4	lbu    t5, $016c(sp)
801E1AB8	lbu    t6, $0170(sp)
801E1ABC	addu   s6, a2, zero
801E1AC0	sb     t5, $0058(sp)
801E1AC4	lbu    t5, $0174(sp)
801E1AC8	addu   s5, a3, zero
801E1ACC	sb     t6, $0060(sp)
801E1AD0	lbu    t6, $0178(sp)
801E1AD4	ori    a0, zero, $0004
801E1AD8	sb     t5, $0068(sp)
801E1ADC	lbu    t5, $017c(sp)
801E1AE0	addu   a1, zero, zero
801E1AE4	sb     t6, $0070(sp)
801E1AE8	jal    func322bc [$800322bc]
801E1AEC	sb     t5, $0078(sp)
801E1AF0	lw     t6, $0010(sp)
801E1AF4	addiu  s1, s1, $0002
801E1AF8	lh     a0, $0004(t6)
801E1AFC	addu   a1, zero, zero
801E1B00	jal    system_memory_allocate [$800319ec]
801E1B04	sll    a0, a0, $03
801E1B08	addu   a3, v0, zero
801E1B0C	bne    a3, zero, L1e1b20 [$801e1b20]
801E1B10	addu   t0, zero, zero
801E1B14	lw     t5, $0010(sp)
801E1B18	j      L1e22c4 [$801e22c4]
801E1B1C	sw     zero, $0014(t5)

L1e1b20:	; 801E1B20
801E1B20	lw     t6, $0010(sp)
801E1B24	nop
801E1B28	lh     v0, $0004(t6)
801E1B2C	nop
801E1B30	blez   v0, L1e1bec [$801e1bec]
801E1B34	sw     a3, $0014(t6)
801E1B38	sll    v0, s0, $10
801E1B3C	sra    a2, v0, $10
801E1B40	sll    v0, s2, $10
801E1B44	sra    a1, v0, $10
801E1B48	sll    v0, s3, $10
801E1B4C	sra    a0, v0, $10
801E1B50	addiu  v1, a3, $0004

L1e1b54:	; 801E1B54
801E1B54	lhu    v0, $0000(s1)
801E1B58	nop
801E1B5C	addu   v0, v0, a2
801E1B60	mult   v0, s5
801E1B64	mflo   v0
801E1B68	bgez   v0, L1e1b74 [$801e1b74]
801E1B6C	addiu  s1, s1, $0002
801E1B70	addiu  v0, v0, $0fff

L1e1b74:	; 801E1B74
801E1B74	sra    v0, v0, $0c
801E1B78	sh     v0, $0000(a3)
801E1B7C	lhu    v0, $0000(s1)
801E1B80	nop
801E1B84	addu   v0, v0, a1
801E1B88	mult   v0, s5
801E1B8C	mflo   v0
801E1B90	bgez   v0, L1e1b9c [$801e1b9c]
801E1B94	addiu  s1, s1, $0002
801E1B98	addiu  v0, v0, $0fff

L1e1b9c:	; 801E1B9C
801E1B9C	sra    v0, v0, $0c
801E1BA0	sh     v0, $fffe(v1)
801E1BA4	lhu    v0, $0000(s1)
801E1BA8	nop
801E1BAC	addu   v0, v0, a0
801E1BB0	mult   v0, s5
801E1BB4	mflo   v0
801E1BB8	bgez   v0, L1e1bc4 [$801e1bc4]
801E1BBC	addiu  s1, s1, $0002
801E1BC0	addiu  v0, v0, $0fff

L1e1bc4:	; 801E1BC4
801E1BC4	sra    v0, v0, $0c
801E1BC8	sh     v0, $0000(v1)
801E1BCC	addiu  v1, v1, $0008
801E1BD0	lw     t5, $0010(sp)
801E1BD4	nop
801E1BD8	lh     v0, $0004(t5)
801E1BDC	addiu  t0, t0, $0001
801E1BE0	slt    v0, t0, v0
801E1BE4	bne    v0, zero, L1e1b54 [$801e1b54]
801E1BE8	addiu  a3, a3, $0008

L1e1bec:	; 801E1BEC
801E1BEC	lw     t6, $0010(sp)
801E1BF0	addu   a1, zero, zero
801E1BF4	lh     v0, $0004(t6)
801E1BF8	lh     a0, $0004(t6)
801E1BFC	sll    v1, v0, $01
801E1C00	addu   v1, v1, s1
801E1C04	lhu    s0, $0000(v1)
801E1C08	sll    a0, a0, $02
801E1C0C	addu   v0, s0, v0
801E1C10	jal    system_memory_allocate [$800319ec]
801E1C14	sh     v0, $0008(t6)

L1e1c18:	; 801E1C18
801E1C18	addu   s4, v0, zero
801E1C1C	bne    s4, zero, L1e1c40 [$801e1c40]
801E1C20	addu   t1, s1, zero
801E1C24	lw     t5, $0010(sp)

L1e1c28:	; 801E1C28
801E1C28	nop
801E1C2C	sw     zero, $0014(t5)
801E1C30	jal    func31f0c [$80031f0c]
801E1C34	addu   a0, zero, zero
801E1C38	j      L1e22c4 [$801e22c4]
801E1C3C	nop

L1e1c40:	; 801E1C40
801E1C40	lw     t6, $0010(sp)
801E1C44	nop
801E1C48	lh     a0, $0004(t6)
801E1C4C	addu   a1, zero, zero
801E1C50	sw     s4, $001c(t6)
801E1C54	sw     t1, $00f8(sp)

L1e1c58:	; 801E1C58
801E1C58	sll    v0, a0, $01
801E1C5C	addu   v0, t1, v0
801E1C60	addiu  s2, v0, $0002
801E1C64	andi   v0, s0, $ffff
801E1C68	sll    v1, v0, $01
801E1C6C	addu   s3, s2, v1
801E1C70	addu   v0, v0, a0
801E1C74	sll    a0, v0, $01
801E1C78	addu   a0, a0, v0
801E1C7C	jal    system_memory_allocate [$800319ec]
801E1C80	sll    a0, a0, $03
801E1C84	addu   a1, v0, zero
801E1C88	lw     t1, $00f8(sp)
801E1C8C	bne    a1, zero, L1e1cc0 [$801e1cc0]
801E1C90	addu   t0, zero, zero
801E1C94	lw     t5, $0010(sp)
801E1C98	addu   a0, zero, zero
801E1C9C	jal    func31f0c [$80031f0c]
801E1CA0	sw     zero, $0014(t5)
801E1CA4	lw     t6, $0010(sp)

L1e1ca8:	; 801E1CA8
801E1CA8	nop
801E1CAC	lw     a0, $001c(t6)
801E1CB0	jal    func31f0c [$80031f0c]
801E1CB4	nop
801E1CB8	j      L1e22c4 [$801e22c4]
801E1CBC	nop

L1e1cc0:	; 801E1CC0
801E1CC0	lw     t5, $0010(sp)
801E1CC4	nop
801E1CC8	lh     v0, $0004(t5)
801E1CCC	lw     a3, $0014(t5)
801E1CD0	blez   v0, L1e1db8 [$801e1db8]
801E1CD4	addu   fp, a1, zero
801E1CD8	addiu  a2, a3, $0004
801E1CDC	addiu  a0, fp, $0008

loop1e1ce0:	; 801E1CE0
801E1CE0	sw     a1, $0000(s4)
801E1CE4	lhu    v0, $0000(t1)
801E1CE8	nop
801E1CEC	blez   v0, L1e1d64 [$801e1d64]
801E1CF0	addu   s0, zero, zero
801E1CF4	addiu  v1, a1, $0008

loop1e1cf8:	; 801E1CF8
801E1CF8	lhu    v0, $0000(s2)
801E1CFC	nop
801E1D00	mult   v0, s5
801E1D04	mflo   v0
801E1D08	bgez   v0, L1e1d14 [$801e1d14]
801E1D0C	addiu  s2, s2, $0002
801E1D10	addiu  v0, v0, $0fff

L1e1d14:	; 801E1D14
801E1D14	sra    v0, v0, $0c
801E1D18	sh     v0, $0000(a1)
801E1D1C	lbu    v0, $0000(s3)
801E1D20	addiu  s3, s3, $0001
801E1D24	addu   v0, v0, s6
801E1D28	sh     v0, $fffa(v1)
801E1D2C	lhu    v0, $0000(a3)

L1e1d30:	; 801E1D30
801E1D30	addiu  a0, a0, $0018
801E1D34	sh     v0, $fffc(v1)
801E1D38	lhu    v0, $fffe(a2)
801E1D3C	addiu  a1, a1, $0018
801E1D40	sh     v0, $fffe(v1)
801E1D44	lhu    v0, $0000(a2)
801E1D48	addiu  s0, s0, $0001
801E1D4C	sh     v0, $0000(v1)
801E1D50	lhu    v0, $0000(t1)
801E1D54	nop

L1e1d58:	; 801E1D58
801E1D58	slt    v0, s0, v0

L1e1d5c:	; 801E1D5C
801E1D5C	bne    v0, zero, loop1e1cf8 [$801e1cf8]
801E1D60	addiu  v1, v1, $0018

L1e1d64:	; 801E1D64
801E1D64	sh     zero, $0000(a1)
801E1D68	addiu  a1, a1, $0018
801E1D6C	addiu  s4, s4, $0004
801E1D70	sh     zero, $fffa(a0)
801E1D74	lhu    v0, $0000(a3)
801E1D78	addiu  t1, t1, $0002
801E1D7C	sh     v0, $fffc(a0)
801E1D80	lhu    v0, $fffe(a2)
801E1D84	addiu  a3, a3, $0008
801E1D88	sh     v0, $fffe(a0)
801E1D8C	lhu    v0, $0000(a2)
801E1D90	addiu  t0, t0, $0001
801E1D94	sh     v0, $0000(a0)
801E1D98	lw     t6, $0010(sp)
801E1D9C	addiu  a2, a2, $0008
801E1DA0	lh     v0, $0004(t6)
801E1DA4	nop
801E1DA8	slt    v0, t0, v0
801E1DAC	bne    v0, zero, loop1e1ce0 [$801e1ce0]
801E1DB0	addiu  a0, a0, $0018
801E1DB4	lw     t5, $0010(sp)

L1e1db8:	; 801E1DB8
801E1DB8	addu   t1, s1, zero
801E1DBC	lh     v0, $0006(t5)
801E1DC0	addu   a1, zero, zero
801E1DC4	sw     t1, $00f8(sp)
801E1DC8	sll    a0, v0, $01
801E1DCC	addu   a0, a0, v0
801E1DD0	sll    a0, a0, $02
801E1DD4	subu   a0, a0, v0
801E1DD8	jal    system_memory_allocate [$800319ec]
801E1DDC	sll    a0, a0, $03
801E1DE0	addu   s7, v0, zero
801E1DE4	lw     t1, $00f8(sp)
801E1DE8	bne    s7, zero, L1e1e20 [$801e1e20]
801E1DEC	addu   a0, zero, zero
801E1DF0	lw     t6, $0010(sp)
801E1DF4	jal    func31f0c [$80031f0c]
801E1DF8	sw     zero, $0014(t6)
801E1DFC	lw     t5, $0010(sp)

L1e1e00:	; 801E1E00
801E1E00	nop
801E1E04	lw     a0, $001c(t5)
801E1E08	jal    func31f0c [$80031f0c]
801E1E0C	nop
801E1E10	jal    func31f0c [$80031f0c]
801E1E14	addu   a0, fp, zero
801E1E18	j      L1e22c4 [$801e22c4]
801E1E1C	nop

L1e1e20:	; 801E1E20
801E1E20	lw     t6, $0010(sp)
801E1E24	nop
801E1E28	sw     s7, $0020(t6)
801E1E2C	lhu    t5, $0020(sp)
801E1E30	nop
801E1E34	sll    v0, t5, $10
801E1E38	sra    s2, v0, $10
801E1E3C	bgez   s2, L1e1e48 [$801e1e48]
801E1E40	addu   s0, s2, zero
801E1E44	addiu  s0, s2, $003f

L1e1e48:	; 801E1E48
801E1E48	lhu    t6, $0028(sp)
801E1E4C	nop
801E1E50	sll    v0, t6, $10
801E1E54	sra    v0, v0, $10
801E1E58	bgez   v0, L1e1e64 [$801e1e64]
801E1E5C	sra    s0, s0, $06
801E1E60	addiu  v0, v0, $00ff

L1e1e64:	; 801E1E64
801E1E64	addu   a0, zero, zero
801E1E68	ori    a1, zero, $0001
801E1E6C	sra    a3, v0, $08
801E1E70	sll    s1, a3, $08
801E1E74	sll    s0, s0, $16
801E1E78	sra    s0, s0, $10
801E1E7C	sll    a3, a3, $18
801E1E80	addu   a2, s0, zero
801E1E84	sra    a3, a3, $10
801E1E88	jal    func43894 [$80043894]

L1e1e8c:	; 801E1E8C
801E1E8C	sw     t1, $00f8(sp)
801E1E90	lhu    t5, $0040(sp)
801E1E94	lhu    t6, $0048(sp)
801E1E98	sh     v0, $0088(sp)
801E1E9C	sll    a0, t5, $10
801E1EA0	sra    a0, a0, $10
801E1EA4	sll    a1, t6, $10
801E1EA8	jal    func438d0 [$800438d0]
801E1EAC	sra    a1, a1, $10
801E1EB0	subu   s0, s2, s0
801E1EB4	sll    s0, s0, $02
801E1EB8	lhu    t5, $0028(sp)
801E1EBC	lhu    t6, $0030(sp)
801E1EC0	lw     t1, $00f8(sp)
801E1EC4	addu   t4, v0, zero
801E1EC8	sw     zero, $0080(sp)
801E1ECC	subu   a1, t5, s1
801E1ED0	lw     t5, $0010(sp)
801E1ED4	sll    v1, t6, $10
801E1ED8	lh     v0, $0004(t5)
801E1EDC	sra    v1, v1, $10
801E1EE0	addiu  v0, v0, $ffff (=-$1)
801E1EE4	div    v1, v0
801E1EE8	bne    v0, zero, L1e1ef4 [$801e1ef4]
801E1EEC	nop
801E1EF0	break   $01c00

L1e1ef4:	; 801E1EF4
801E1EF4	addiu  at, zero, $ffff (=-$1)
801E1EF8	bne    v0, at, L1e1f0c [$801e1f0c]
801E1EFC	lui    at, $8000
801E1F00	bne    v1, at, L1e1f0c [$801e1f0c]
801E1F04	nop
801E1F08	break   $01800

L1e1f0c:	; 801E1F0C
801E1F0C	mflo   a0
801E1F10	blez   v0, L1e21c4 [$801e21c4]
801E1F14	addu   t0, zero, zero
801E1F18	addu   t2, s0, zero
801E1F1C	sll    v0, a0, $10
801E1F20	sra    v0, v0, $10
801E1F24	sw     v0, $00a0(sp)
801E1F28	lw     t3, $00a0(sp)
801E1F2C	addu   a2, a1, zero
801E1F30	sw     zero, $00e0(sp)

L1e1f34:	; 801E1F34
801E1F34	lhu    v0, $0002(t1)
801E1F38	lhu    v1, $0000(t1)

L1e1f3c:	; 801E1F3C
801E1F3C	addu   a3, v0, zero
801E1F40	sltu   v0, v1, a3
801E1F44	beq    v0, zero, L1e1f50 [$801e1f50]
801E1F48	addu   s0, zero, zero
801E1F4C	addu   a3, v1, zero

L1e1f50:	; 801E1F50
801E1F50	lhu    t6, $0038(sp)
801E1F54	nop
801E1F58	sll    v0, t6, $10
801E1F5C	sra    v0, v0, $10
801E1F60	div    v0, a3
801E1F64	bne    a3, zero, L1e1f70 [$801e1f70]
801E1F68	nop
801E1F6C	break   $01c00

L1e1f70:	; 801E1F70
801E1F70	addiu  at, zero, $ffff (=-$1)
801E1F74	bne    a3, at, L1e1f88 [$801e1f88]
801E1F78	lui    at, $8000
801E1F7C	bne    v0, at, L1e1f88 [$801e1f88]
801E1F80	nop
801E1F84	break   $01800

L1e1f88:	; 801E1F88
801E1F88	mflo   v0
801E1F8C	beq    a3, zero, L1e2180 [$801e2180]
801E1F90	sh     v0, $0090(sp)
801E1F94	lw     t5, $00e0(sp)
801E1F98	lw     s6, $0080(sp)
801E1F9C	addiu  s5, s7, $0004
801E1FA0	sw     t5, $00a8(sp)

L1e1fa4:	; 801E1FA4
801E1FA4	lhu    t6, $0090(sp)
801E1FA8	addu   s2, zero, zero
801E1FAC	addu   a1, t6, zero
801E1FB0	mult   a1, s0
801E1FB4	addu   s1, s7, zero
801E1FB8	lw     t5, $00a8(sp)
801E1FBC	ori    s4, zero, $0008
801E1FC0	sh     s6, $0000(s7)
801E1FC4	lhu    v0, $0000(t1)
801E1FC8	addiu  v1, s6, $0001
801E1FCC	sh     v1, $0000(s5)
801E1FD0	addu   fp, t2, t5
801E1FD4	addu   v0, s6, v0
801E1FD8	addiu  v0, v0, $0001
801E1FDC	sh     v0, $fffe(s5)
801E1FE0	mflo   v0
801E1FE4	addu   s3, a2, v0

loop1e1fe8:	; 801E1FE8
801E1FE8	addu   a0, s7, s4
801E1FEC	sw     a1, $00e8(sp)
801E1FF0	sw     a2, $00ec(sp)
801E1FF4	sw     a3, $00f0(sp)
801E1FF8	sw     t0, $00f4(sp)
801E1FFC	sw     t1, $00f8(sp)
801E2000	sw     t2, $00fc(sp)
801E2004	sw     t3, $0100(sp)
801E2008	jal    func43b00 [$80043b00]
801E200C	sw     t4, $0104(sp)
801E2010	addiu  v0, s0, $0001
801E2014	lw     a1, $00e8(sp)
801E2018	lhu    t6, $0088(sp)
801E201C	addiu  s4, s4, $0028
801E2020	sh     t6, $0022(s1)
801E2024	lw     t4, $0104(sp)

L1e2028:	; 801E2028
801E2028	mult   a1, v0

L1e202c:	; 801E202C
801E202C	sb     fp, $0014(s1)
801E2030	sb     s3, $0015(s1)
801E2034	sh     t4, $0016(s1)
801E2038	lw     t3, $0100(sp)
801E203C	lw     t2, $00fc(sp)
801E2040	addiu  s2, s2, $0001
801E2044	sb     s3, $0021(s1)
801E2048	sb     fp, $002c(s1)
801E204C	addu   v1, t2, t3
801E2050	sb     v1, $0020(s1)
801E2054	lw     a2, $00ec(sp)
801E2058	mflo   v0
801E205C	addu   v0, a2, v0
801E2060	sb     v0, $002d(s1)
801E2064	slti   v0, s2, $0002
801E2068	lw     a3, $00f0(sp)
801E206C	lw     t0, $00f4(sp)
801E2070	lw     t1, $00f8(sp)
801E2074	bne    v0, zero, loop1e1fe8 [$801e1fe8]
801E2078	addiu  s1, s1, $0028
801E207C	addiu  s5, s5, $0058
801E2080	addiu  s7, s7, $0058
801E2084	addu   s2, zero, zero
801E2088	addu   fp, v1, zero
801E208C	addu   s1, s7, zero
801E2090	ori    s3, zero, $0008
801E2094	addiu  v1, s6, $0001
801E2098	lhu    t5, $0090(sp)
801E209C	lw     t6, $00a8(sp)
801E20A0	lhu    v0, $0000(t1)
801E20A4	addu   s4, t5, zero
801E20A8	addu   v0, s6, v0

L1e20ac:	; 801E20AC
801E20AC	addiu  v0, v0, $0001
801E20B0	sh     v0, $0000(s7)
801E20B4	lhu    v0, $0000(t1)
801E20B8	addu   a1, t2, t6
801E20BC	sh     v1, $0000(s5)

L1e20c0:	; 801E20C0
801E20C0	addu   v0, s6, v0
801E20C4	addiu  v0, v0, $0002
801E20C8	sh     v0, $fffe(s5)

loop1e20cc:	; 801E20CC
801E20CC	addu   a0, s7, s3

L1e20d0:	; 801E20D0
801E20D0	sw     a1, $00e8(sp)
801E20D4	sw     a2, $00ec(sp)
801E20D8	sw     a3, $00f0(sp)
801E20DC	sw     t0, $00f4(sp)
801E20E0	sw     t1, $00f8(sp)
801E20E4	sw     t2, $00fc(sp)
801E20E8	sw     t3, $0100(sp)
801E20EC	jal    func43b00 [$80043b00]
801E20F0	sw     t4, $0104(sp)

L1e20f4:	; 801E20F4
801E20F4	mult   s4, s0
801E20F8	addiu  v1, s0, $0001
801E20FC	lhu    t5, $0088(sp)
801E2100	mflo   v0
801E2104	sh     t5, $0022(s1)
801E2108	lw     t4, $0104(sp)
801E210C	mult   s4, v1
801E2110	sb     fp, $0014(s1)
801E2114	sb     fp, $0020(s1)
801E2118	sh     t4, $0016(s1)
801E211C	lw     a1, $00e8(sp)
801E2120	addiu  s3, s3, $0028
801E2124	sb     a1, $002c(s1)
801E2128	lw     a2, $00ec(sp)

L1e212c:	; 801E212C
801E212C	addiu  s2, s2, $0001
801E2130	addu   v0, a2, v0
801E2134	sb     v0, $0015(s1)

L1e2138:	; 801E2138
801E2138	mflo   v0
801E213C	addu   v0, a2, v0
801E2140	sb     v0, $0021(s1)
801E2144	sb     v0, $002d(s1)
801E2148	slti   v0, s2, $0002

L1e214c:	; 801E214C
801E214C	lw     a3, $00f0(sp)
801E2150	lw     t0, $00f4(sp)
801E2154	lw     t1, $00f8(sp)

L1e2158:	; 801E2158
801E2158	lw     t2, $00fc(sp)
801E215C	lw     t3, $0100(sp)
801E2160	bne    v0, zero, loop1e20cc [$801e20cc]
801E2164	addiu  s1, s1, $0028
801E2168	addiu  s5, s5, $0058
801E216C	addiu  s7, s7, $0058
801E2170	addu   s0, v1, zero
801E2174	slt    v0, s0, a3
801E2178	bne    v0, zero, L1e1fa4 [$801e1fa4]
801E217C	addiu  s6, s6, $0001

L1e2180:	; 801E2180
801E2180	lhu    a0, $0000(t1)
801E2184	addiu  t1, t1, $0002
801E2188	lw     t6, $00a0(sp)
801E218C	lw     t5, $00e0(sp)
801E2190	addu   t3, t3, t6
801E2194	addu   t5, t5, t6
801E2198	lw     t6, $0080(sp)
801E219C	addiu  t0, t0, $0001
801E21A0	sw     t5, $00e0(sp)
801E21A4	lw     t5, $0010(sp)
801E21A8	addiu  v1, t6, $0001
801E21AC	lh     v0, $0004(t5)
801E21B0	addu   v1, v1, a0
801E21B4	addiu  v0, v0, $ffff (=-$1)
801E21B8	slt    v0, t0, v0
801E21BC	bne    v0, zero, L1e1f34 [$801e1f34]
801E21C0	sw     v1, $0080(sp)

L1e21c4:	; 801E21C4
801E21C4	lbu    t5, $0050(sp)
801E21C8	lw     t6, $0010(sp)
801E21CC	nop
801E21D0	sb     t5, $000c(t6)
801E21D4	lbu    t5, $0058(sp)
801E21D8	nop
801E21DC	sb     t5, $000d(t6)
801E21E0	lbu    t5, $0060(sp)
801E21E4	nop
801E21E8	sb     t5, $000e(t6)
801E21EC	lbu    t5, $0068(sp)
801E21F0	nop
801E21F4	sb     t5, $000f(t6)
801E21F8	lbu    t5, $0070(sp)
801E21FC	nop
801E2200	sb     t5, $0010(t6)
801E2204	lbu    t5, $0078(sp)
801E2208	nop
801E220C	sb     t5, $0011(t6)
801E2210	lhu    t5, $0018(sp)
801E2214	nop
801E2218	sh     t5, $000a(t6)
801E221C	lw     t6, $0018(sp)
801E2220	nop
801E2224	sll    v0, t6, $10
801E2228	sra    v0, v0, $10
801E222C	blez   v0, L1e22b8 [$801e22b8]
801E2230	sll    a0, v0, $04
801E2234	jal    system_memory_allocate [$800319ec]
801E2238	addu   a1, zero, zero
801E223C	addu   a0, v0, zero
801E2240	bne    a0, zero, L1e2254 [$801e2254]
801E2244	addu   t0, zero, zero
801E2248	lw     t5, $0010(sp)

L1e224c:	; 801E224C
801E224C	nop
801E2250	sh     zero, $000a(t5)

L1e2254:	; 801E2254
801E2254	lw     t6, $0010(sp)
801E2258	nop
801E225C	lh     v0, $000a(t6)
801E2260	nop
801E2264	blez   v0, L1e22c4 [$801e22c4]
801E2268	sw     a0, $0018(t6)
801E226C	addiu  v1, a0, $000e

loop1e2270:	; 801E2270
801E2270	sh     zero, $0000(a0)
801E2274	sh     zero, $fff4(v1)
801E2278	sh     zero, $fff6(v1)
801E227C	sh     zero, $fff8(v1)
801E2280	sh     zero, $fffa(v1)
801E2284	sh     zero, $fffc(v1)

L1e2288:	; 801E2288
801E2288	sh     zero, $fffe(v1)
801E228C	sh     zero, $0000(v1)
801E2290	addiu  v1, v1, $0010
801E2294	lw     t5, $0010(sp)
801E2298	nop
801E229C	lh     v0, $000a(t5)
801E22A0	addiu  t0, t0, $0001
801E22A4	slt    v0, t0, v0
801E22A8	bne    v0, zero, loop1e2270 [$801e2270]
801E22AC	addiu  a0, a0, $0010
801E22B0	j      L1e22c4 [$801e22c4]
801E22B4	nop

L1e22b8:	; 801E22B8
801E22B8	lw     t6, $0010(sp)
801E22BC	nop
801E22C0	sw     zero, $0018(t6)

L1e22c4:	; 801E22C4
801E22C4	lw     ra, $012c(sp)
801E22C8	lw     fp, $0128(sp)
801E22CC	lw     s7, $0124(sp)
801E22D0	lw     s6, $0120(sp)
801E22D4	lw     s5, $011c(sp)
801E22D8	lw     s4, $0118(sp)
801E22DC	lw     s3, $0114(sp)
801E22E0	lw     s2, $0110(sp)
801E22E4	lw     s1, $010c(sp)
801E22E8	lw     s0, $0108(sp)
801E22EC	addiu  sp, sp, $0130
801E22F0	jr     ra 
801E22F4	nop
////////////////////////////////