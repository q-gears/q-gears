triggers
[         level name          ]     [mo]       [range] [range]
[6D 64   31 73   74 69   6E 00]  00 [7C] 00 00 [00 FF] [00 FF]

[range] [range]                 [0x18 ]
[00 01] [00 01]  00 00   00 00  [00 04] [00 04] [00 04] [00 04]

[0x20 ]
[00 00] [00 00] [00 00] [00 00] [00 00] [00 00] [00 00] [00 00]

 00 00   00 00   00 00   00 00

camera
[          vx         ] [          vy         ] [          vz
[E2 0F   11 FE   00 00] [CB FF   52 FE   16 F0] [EB 01   CB 0F

       [align] [  ox ] [  oy ] [  oz ]         [dista]
4F FE] [4F FE] [93 FE] [FF FF] [CF 0C] [00 00] [69 96] FF FF

            [0x24 ]
00 00 00 00 [82 01] 44 80



////////////////////////////////
// funca4bec
S2 = A0;

offset_to_triggers = w[800716c4];
offset_to_camera = w[80071e40];

[offset_to_triggers + 20] = h((hu[offset_to_triggers + 20] + hu[8009abf4 + a6]) % (h[offset_to_triggers + 18] * 10)); // add x scroll for 2nd background
[offset_to_triggers + 22] = h((hu[offset_to_triggers + 22] + hu[8009abf4 + a8]) % (h[offset_to_triggers + 1a] * 10)); // add y scroll for 2nd background

[offset_to_triggers + 24] = h((hu[offset_to_triggers + 24] + hu[8009abf4 + aa]) % (h[offset_to_triggers + 1c] * 10)); // add x scroll for 3nd background
[offset_to_triggers + 26] = h((hu[offset_to_triggers + 26] + hu[8009abf4 + ac]) % (h[offset_to_triggers + 1e] * 10)); // add y scroll for 3nd background

A0 = h[offset_to_camera + 24];
system_set_gte_mac2;

if ((hu[80114488] != 0) && (bu[8009abf4 + 3a] == 0))
{
    V1 = bu[8009ac2d];
    if (V1 != 1)
    {
        A0 = S2 + 41d4;
        if( S2 == 800e4df0 )
        {
            A2 = w[80071e40];
            [80113f34] = h(hu[8007eb90] - hu[A2 + 20]);
            [80113f36] = h(hu[8007eb94] + hu[A2 + 22]);
            A1 = 80113f34 - 8;
            func44ac0;
        }
        else
        {
            offset_to_camera = w[80071E40];
            V0 = hu[8007EB90];
            V1 = hu[offset_to_camera + 20];
            V0 = V0 - V1;
            [80113F90] = h(V0);

            V0 = hu[8007EB94];
            V1 = hu[offset_to_camera + 22];
            V0 = V0 + V1 + e8;

            A0 = 80100860;
            A1 = 80113F88;

            [80113F92] = h(V0);
            func44ac0;
        }
    }
    else
    {
        if( S2 != 800e4df0 )
        {
            A0 = 80100860;
            T0 = 80113f90;
            A1 = T0 - 8;
            V1 = hu[8007eb90];
            A2 = hu[80071e38];
            V0 = hu[8007eb94];
            A3 = hu[80071e3c];
            V1 = V1 + A2;
            [T0] = h(V1);
            [80113F92] = h(V0 + A3 + e8);
            func44ac0;
        }
        else
        {
            A0 = S2 + 41d4;
            T0 = 80113f34;
            A2 = hu[80071e38];
            A3 = hu[80071e3c];
            V0 = hu[8007eb90] + A2;
            V1 = hu[8007eb94] + A3;
            [T0] = h(V0);
            [80113f36] = h(V1);
            A1 = T0 - 8;
            func44ac0;
        }
    }
}
else
{
    if (h[8009a100] == 0) // auto scroll
    {
        A0 = h[8009abf4 + 18];
        A1 = h[8009abf4 + 1a];
        A2 = bu[8009abf4 + 12];
        A3 = bu[8009abf4 + 13];

        V1 = bu[8009abf4 + 14];
        if( V1 == 1 )
        {
            calculate_current_value_by_steps;
        }
        else if( V1 == 2 )
        {
            calculate_smooth_current_value_by_steps;
        }

        [8009abf4 + 16] = h(V0 & ff);

        A0 = bu[8009abf4 + 13];
        if( A0 == bu[8009abf4 + 12] )
        {
            [8009abf4 + 14] = b(3);
        }
        else
        {
            [8009abf4 + 13] = b(A0 + 1);
        }

        800A4EB0	addiu  a0, sp, $0010
        800A4EB4	lui    v0, $8009
        800A4EB8	lh     v0, $65e0(v0)
        800A4EBC	addiu  s0, sp, $0018
        800A4EC0	sll    v1, v0, $05
        800A4EC4	addu   v1, v1, v0
        800A4EC8	sll    v1, v1, $02
        800A4ECC	lui    at, $8007
        800A4ED0	addiu  at, at, $4eb0
        800A4ED4	addu   at, at, v1
        800A4ED8	lw     v0, $0000(at)
        800A4EDC	lui    at, $8007
        800A4EE0	addiu  at, at, $4ee4
        800A4EE4	addu   at, at, v1
        800A4EE8	lhu    a1, $0000(at)
        800A4EEC	sra    v0, v0, $0c
        800A4EF0	addu   v0, v0, a1
        800A4EF4	sh     v0, $0010(sp)
        800A4EF8	lui    at, $8007
        800A4EFC	addiu  at, at, $4eb4
        800A4F00	addu   at, at, v1
        800A4F04	lw     v0, $0000(at)
        800A4F08	lui    at, $8007
        800A4F0C	addiu  at, at, $4eea
        800A4F10	addu   at, at, v1
        800A4F14	lhu    a1, $0000(at)
        800A4F18	sra    v0, v0, $0c
        800A4F1C	addu   v0, v0, a1
        800A4F20	addu   a1, s0, zero
        800A4F24	sh     v0, $0012(sp)
        800A4F28	lui    at, $8007
        800A4F2C	addiu  at, at, $4eb8
        800A4F30	addu   at, at, v1
        800A4F34	lw     v0, $0000(at)
        800A4F38	lui    at, $8007
        800A4F3C	addiu  at, at, $4ef0
        800A4F40	addu   at, at, v1
        800A4F44	lhu    a2, $0000(at)
        800A4F48	lui    v1, $800a
        800A4F4C	lh     v1, $ac04(v1)
        800A4F50	sra    v0, v0, $0c
        800A4F54	addu   v0, v0, a2
        800A4F58	sra    v1, v1, $02
        800A4F5C	addu   v0, v0, v1
        800A4F64	sh     v0, $0014(sp)
        800A4F60	jal    field_calculate_distance_to_screen [$800a41cc]

        800A4F68	addiu  a0, sp, $0010
        800A4F6C	addu   a1, s0, zero
        800A4F70	lui    s3, $8008
        800A4F74	addiu  s3, s3, $eb90 (=-$1470)
        800A4F78	lui    s1, $8008
        800A4F7C	addiu  s1, s1, $eb94 (=-$146c)
        800A4F80	lui    v0, $8009
        800A4F84	lh     v0, $65e0(v0)
        800A4F88	lhu    a3, $0000(s3)
        800A4F8C	sll    a2, v0, $05
        800A4F90	addu   a2, a2, v0
        800A4F94	sll    a2, a2, $02
        800A4F98	lhu    v0, $0018(sp)

        [80114464] = h(V0 + A3);

        A3 = hu[S1];

        [80114468] = h(hu[SP + 1a] + A3);

        [SP + 10] = h(w[80074ea4 + A2 + 0c] >> c);
        [SP + 12] = h(w[80074ea4 + A2 + 10] >> c);
        [SP + 14] = h(w[80074ea4 + A2 + 14] + hu[8009abf4 + 16] >> c);

        field_calculate_distance_to_screen;

        [800e48ec] = w(V0);

        800A5014	lhu    v1, $0018(sp)
        800A5018	lhu    a1, $001a(sp)

        800A5024	lui    at, $800e
        800A5028	sh     v1, $48e4(at)
        800A502C	lui    at, $800e
        800A5030	sh     a1, $48e6(at)
        800A5034	jal    funca47f8 [$800a47f8]
        800A5038	addu   a0, s0, zero
        800A503C	lui    a0, $8007
        800A5040	lw     a0, $16c4(a0)
        800A5044	jal    funca45d4 [$800a45d4]
        800A5048	addu   a1, s0, zero
        800A504C	lhu    t1, $0018(sp)
        800A5050	lui    a1, $8007
        800A5054	lw     a1, $16c4(a1)
        800A5058	sll    a3, t1, $10
        800A505C	lh     v0, $0028(a1)
        800A5060	sra    a3, a3, $10
        800A5064	mult   a3, v0
        800A5068	lhu    t2, $001a(sp)
        800A506C	nop
        800A5070	sll    a2, t2, $10
        800A5074	mflo   a0
        800A5078	lh     v0, $002a(a1)
        800A507C	sra    a2, a2, $10
        800A5080	mult   a2, v0
        800A5084	lhu    v0, $0020(a1)
        800A5088	sra    a0, a0, $08
        800A508C	sll    v0, v0, $10
        800A5090	sra    v0, v0, $14
        800A5094	addu   a0, a0, v0
        800A5098	sll    a0, a0, $10
        800A509C	mflo   v1
        800A50A0	lh     v0, $0018(a1)
        800A50A4	sra    a0, a0, $10
        800A50A8	div    a0, v0
        800A50D0	mfhi   s5
        800A50D4	lhu    v0, $0022(a1)
        800A50D8	sra    v1, v1, $08
        800A50DC	sll    v0, v0, $10
        800A50E0	sra    v0, v0, $14
        800A50E4	addu   v1, v1, v0
        800A50E8	sll    v1, v1, $10
        800A50EC	lh     v0, $001a(a1)
        800A50F0	sra    v1, v1, $10
        800A50F4	div    v1, v0
        800A511C	mfhi   s4
        800A5120	lh     v0, $002c(a1)
        800A5124	nop
        800A5128	mult   a3, v0
        800A512C	mflo   v1
        800A5130	lh     v0, $002e(a1)
        800A5134	nop
        800A5138	mult   a2, v0
        800A513C	lhu    v0, $0024(a1)
        800A5140	sra    v1, v1, $08
        800A5144	sll    v0, v0, $10
        800A5148	sra    v0, v0, $14
        800A514C	addu   v1, v1, v0
        800A5150	sll    v1, v1, $10
        800A5154	mflo   a0
        800A5158	lh     v0, $001c(a1)
        800A515C	sra    v1, v1, $10
        800A5160	div    v1, v0
        800A5188	mfhi   s7
        800A518C	lhu    v0, $0026(a1)
        800A5190	sra    a0, a0, $08
        800A5194	sll    v0, v0, $10
        800A5198	sra    v0, v0, $14
        800A519C	addu   a0, a0, v0
        800A51A0	sll    a0, a0, $10
        800A51A4	lh     v0, $001e(a1)
        800A51A8	sra    a0, a0, $10
        800A51AC	div    a0, v0
        800A51D4	mfhi   s6
        800A51D8	lui    v1, $8011
        800A51DC	lhu    v1, $4468(v1)
        800A51E0	lui    v0, $8011
        800A51E4	lhu    v0, $4464(v0)
        800A51E8	subu   v1, v1, t2
        800A51EC	lui    at, $8011
        800A51F0	sh     v1, $4468(at)
        800A51F4	subu   v0, v0, t1
        800A51F8	lui    at, $8011
        800A51FC	sh     v0, $4464(at)

        FP = S5;
        [SP + 20] = h(S4);
        [SP + 28] = h(S7);
        [SP + 30] = h(S6);

        if( S2 == 800e4df0 )
        {
            800A521C	addiu  a0, s2, $41d4
            T0 = 80113f34;
            V0 = b[8009ac81];
            V1 = b[8009ac8f];
            A2 = hu[S3];
            A3 = hu[S1];

            800A5250	subu   a2, a2, t1
            800A5254	addu   v0, v0, a2
            800A5258	subu   a3, a3, t2
            800A525C	addu   v1, v1, a3
            800A5260	sh     v0, $0000(t0)
            800A5264	lui    at, $8011
            800A5268	sh     v1, $3f36(at)
            800A5270	addiu  a1, t0, $fff8 (=-$8)
            800A526C	jal    func44ac0 [$80044ac0]

            800A5274	addiu  a0, s2, $4294
            T1 = 8011415c;
            V0 = b[8009ac81];
            V1 = b[8009ac8f];
            800A5290	lhu    a3, $0000(s3)
            800A5294	lhu    a2, $0018(sp)
            800A5298	lhu    t0, $001a(sp)
            800A52AC	subu   a3, a3, a2
            800A52B0	lhu    a2, $0000(s1)
            800A52B4	addu   v0, v0, a3
            800A52B8	sh     v0, $0000(t1)
            800A52BC	subu   a2, a2, t0
            800A52C0	addu   v1, v1, a2
            800A52C4	lui    at, $8011
            800A52C8	sh     v1, $415e(at)
            800A52D0	addiu  a1, t1, $fff8 (=-$8)
            800A52CC	jal    func44ac0 [$80044ac0]

            800A52D4	addiu  a0, s2, $42d4
            T1 = 80114214;
            V0 = b[8009ac81];
            V1 = b[8009ac8f];
            A3 = hu[S3];
            800A52F4	lhu    a2, $0018(sp)
            800A52F8	lhu    t0, $001a(sp)
            800A530C	subu   a3, a3, a2
            800A5310	lhu    a2, $0000(s1)
            800A5314	addu   v0, v0, a3
            800A5318	sh     v0, $0000(t1)
            800A531C	subu   a2, a2, t0
            800A5320	addu   v1, v1, a2
            800A5324	lui    at, $8011
            800A5328	sh     v1, $4216(at)
            800A5330	addiu  a1, t1, $fff8 (=-$8)
            800A532C	jal    func44ac0 [$80044ac0]

            800A5334	addiu  a0, s2, $4214
            T0 = 80113fec;
            V0 = b[8009ac81];
            V1 = b[8009ac8f];
            A2 = hu[S3] - S5;
            A3 = hu[S1];

            800A536C	addu   v0, v0, a2
            800A5370	subu   a3, a3, s4
            800A5374	addu   v1, v1, a3
            800A5378	sh     v0, $0000(t0)
            800A537C	lui    at, $8011
            800A5380	sh     v1, $3fee(at)
            800A5388	addiu  a1, t0, $fff8 (=-$8)
            800A5384	jal    func44ac0 [$80044ac0]

            800A538C	addiu  a0, s2, $4254
            T0 = 801140a4;
            V0 = b[8009ac81];
            V1 = b[8009ac8f];
            800A53A8	lhu    a2, $0000(s3)
            800A53AC	lhu    a3, $0000(s1)
            800A53C0	subu   a2, a2, s7
            800A53C4	addu   v0, v0, a2
            800A53C8	subu   a3, a3, s6
            800A53CC	addu   v1, v1, a3
            800A53D0	sh     v0, $0000(t0)
            800A53D4	lui    at, $8011
            800A53D8	sh     v1, $40a6(at)
            800A53E0	addiu  a1, t0, $fff8 (=-$8)
        }
        else
        {
            800A53E4	lui    s0, $8010
            800A53E8	addiu  s0, s0, $0860
            800A53EC	addu   a0, s0, zero
            800A53F0	lui    t0, $8011
            800A53F4	addiu  t0, t0, $3f90
            V1 = b[8009ac81];
            V0 = b[8009ac8f];
            800A5408	lhu    a2, $0000(s3)
            800A540C	lhu    a3, $0000(s1)
            800A5420	subu   a2, a2, t1
            800A5424	addu   v1, v1, a2
            800A5428	subu   a3, a3, t2
            800A542C	addu   v0, v0, a3
            800A5430	addiu  v0, v0, $00e8
            800A5434	sh     v1, $0000(t0)
            800A5438	lui    at, $8011
            800A543C	sh     v0, $3f92(at)
            800A5444	addiu  a1, t0, $fff8 (=-$8)
            800A5440	jal    func44ac0 [$80044ac0]

            800A5448	addiu  a0, s0, $00c0
            T1 = 801141b8;
            V1 = b[8009ac81];
            V0 = b[8009ac8f];
            800A5464	lhu    a3, $0000(s3)
            800A5468	lhu    a2, $0018(sp)
            800A546C	lhu    t0, $001a(sp)
            800A5480	subu   a3, a3, a2
            800A5484	lhu    a2, $0000(s1)
            800A5488	addu   v1, v1, a3
            800A548C	sh     v1, $0000(t1)
            800A5490	subu   a2, a2, t0
            800A5494	addu   v0, v0, a2
            800A5498	addiu  v0, v0, $00e8
            800A549C	lui    at, $8011
            800A54A0	sh     v0, $41ba(at)
            800A54A8	addiu  a1, t1, $fff8 (=-$8)
            800A54A4	jal    func44ac0 [$80044ac0]

            800A54AC	addiu  a0, s0, $0100
            T1 = 80114270;
            V1 = b[8009ac81];
            V0 = b[8009ac8f];
            800A54C8	lhu    a3, $0000(s3)
            800A54CC	lhu    a2, $0018(sp)
            800A54D0	lhu    t0, $001a(sp)
            800A54E4	subu   a3, a3, a2
            800A54E8	lhu    a2, $0000(s1)
            800A54EC	addu   v1, v1, a3
            800A54F0	sh     v1, $0000(t1)
            800A54F4	subu   a2, a2, t0
            800A54F8	addu   v0, v0, a2
            800A54FC	addiu  v0, v0, $00e8
            800A5500	lui    at, $8011
            800A5504	sh     v0, $4272(at)
            800A550C	addiu  a1, t1, $fff8 (=-$8)
            800A5508	jal    func44ac0 [$80044ac0]

            800A5510	addiu  a0, s0, $0040
            T0 = 80114048;
            V1 = b[8009ac81];
            V0 = b[8009ac8f];
            800A552C	lhu    a2, $0000(s3)
            800A5530	lhu    a3, $0000(s1)
            800A5544	subu   a2, a2, s5
            800A5548	addu   v1, v1, a2
            800A554C	subu   a3, a3, s4
            800A5550	addu   v0, v0, a3
            800A5554	addiu  v0, v0, $00e8
            800A5558	sh     v1, $0000(t0)
            800A555C	lui    at, $8011
            800A5560	sh     v0, $404a(at)
            800A5568	addiu  a1, t0, $fff8 (=-$8)
            800A5564	jal    func44ac0 [$80044ac0]

            800A556C	addiu  a0, s0, $0080
            T0 = 80114100;
            800A5578	addiu  a1, t0, $fff8 (=-$8)
            V1 = b[8009ac81];
            V0 = b[8009ac8f];
            800A558C	lhu    a2, $0000(s3)
            800A5590	lhu    a3, $0000(s1)
            800A55A4	subu   a2, a2, s7
            800A55A8	addu   v1, v1, a2
            800A55AC	subu   a3, a3, s6
            800A55B0	addu   v0, v0, a3
            800A55B4	addiu  v0, v0, $00e8
            800A55B8	sh     v1, $0000(t0)
            [80114102] = h(V0);
        }

        800A55C4	jal    func44ac0 [$80044ac0]

        [80071e38] = h(0 - hu[SP + 18]);
        [80071e3c] = h(0 - hu[SP + 1a]);
        [80071a48] = h(hu[SP + 18] + 140 - hu[8007eb90] - b[8009ac81]);
        [80071a4a] = h(hu[SP + 1a] + e8 - hu[8007eb94] - b[8009ac8f]);
        [80071a4c] = h(FP          + 140 - hu[8007eb90] - b[8009ac81]);
        [80071a4e] = h(hu[SP + 20] + e8 - hu[8007eb94] - b[8009ac8f]);
        [80071a50] = h(hu[SP + 28] + 140 - hu[8007eb90] - b[8009ac81]);
        [80071a52] = h(hu[SP + 30] + e8 - hu[8007eb94] - b[8009ac8f]);
    }
    else
    {
        S3 = ((h[offset_to_triggers + 20] >> 04) - ((h[80071e38] * h[offset_to_triggers + 28]) >> 08)) / h[offset_to_triggers + 18];
        S4 = ((h[offset_to_triggers + 22] >> 04) - ((h[80071e3c] * h[offset_to_triggers + 2a]) >> 08)) / h[offset_to_triggers + 1a];
        S5 = ((h[offset_to_triggers + 24] >> 04) - ((h[80071e38] * h[offset_to_triggers + 2c]) >> 08)) / h[offset_to_triggers + 1c];
        S6 = ((h[offset_to_triggers + 26] >> 04) - ((h[80071e3c] * h[offset_to_triggers + 2e]) >> 08)) / h[offset_to_triggers + 1e];

        if (S2 == 800e4df0) // if 1st buffer
        {
            val1 = b[8009abf4 + 8d] + hu[8007eb90] - hu[offset_to_camera + 20] + h[80071e38];
            val2 = b[8009abf4 + 9b] + hu[8007eb94] + hu[offset_to_camera + 22] + w[80071e3c];

            [80113f34] = h(val1);
            [80113f36] = h(val2);

            A0 = 800e8fc4;
            A1 = 80113f2c;
            func44ac0;

            [8011415c] = h(val1);
            [8011415e] = h(val2);

            A0 = 800e9084;
            A1 = 80114154;
            func44ac0;

            [80114214] = h(val1);
            [80114216] = h(val2);

            A0 = 800e90c4;
            A1 = 8011420c;
            func44ac0;

            [80113fec] = h(b[8009abf4 + 8d] + hu[8007eb90] - hu[offset_to_camera + 20] - S3);
            [80113fee] = h(b[8009abf4 + 9b] + hu[8007eb94] + hu[offset_to_camera + 22] - S4);

            A0 = 800e9004;
            A1 = 80113fe4;
            func44ac0;

            [801140a4] = h(b[8009abf4 + 8d] + hu[8007eb90] - hu[offset_to_camera + 20] - S5);
            [801140a6] = h(b[8009abf4 + 9b] + hu[8007eb94] + hu[offset_to_camera + 22] - S6);

            A0 = 800e9044;
            A1 = 8011409c;
            func44ac0;
        }
        else
        {
            S1 = 80100830;
            A0 = S1;
            A3 = 80113f90;
            S2 = 8007eb90;
            S0 = 8007eb94;
            V0 = b[8009ac81];
            T0 = w[80071e40];
            V1 = hu[S2];
            A2 = hu[T0 + 20];
            V1 = V1 - A2;
            V1 = V1 + h[80071e38];
            V0 = V0 + V1;
            [A3] = h(V0);
            V0 = b[8009ac8f];
            800A5B1C	lhu    v1, $0000(s0)
            800A5B20	lhu    a2, $0022(t0)
            800A5B2C	addu   v1, v1, a2
            V1 = V1 + h[80071e3c];
            800A5B34	addu   v0, v0, v1
            800A5B38	addiu  v0, v0, $00e8
            800A5B3C	lui    at, $8011
            800A5B40	sh     v0, $3f92(at)
            800A5B44	jal    func44ac0 [$80044ac0]
            800A5B48	addiu  a1, a3, $fff8 (=-$8)
            800A5B4C	addiu  a0, s1, $00c0
            800A5B50	lui    t2, $8011
            800A5B54	addiu  t2, t2, $41b8
            800A5B58	lui    v1, $800a
            800A5B5C	lbu    v1, $ac81(v1)
            800A5B60	lui    a2, $800a
            800A5B64	lbu    a2, $ac8f(a2)
            800A5B68	lui    t1, $8007
            800A5B6C	lw     t1, $1e40(t1)
            800A5B70	lhu    v0, $0000(s2)
            800A5B74	lui    t0, $8007
            800A5B78	lhu    t0, $1e38(t0)
            800A5B7C	sll    v1, v1, $18
            800A5B80	sra    v1, v1, $18
            800A5B84	sll    a2, a2, $18
            800A5B88	lhu    a3, $0020(t1)
            800A5B8C	sra    a2, a2, $18
            800A5B90	subu   v0, v0, a3
            800A5B94	addu   v0, v0, t0
            800A5B98	addu   v1, v1, v0
            800A5B9C	sh     v1, $0000(t2)
            800A5BA0	lhu    v0, $0000(s0)
            800A5BA4	lhu    v1, $0022(t1)
            800A5BA8	lui    a3, $8007
            800A5BAC	lhu    a3, $1e3c(a3)
            800A5BB0	addu   v0, v0, v1
            800A5BB4	addu   v0, v0, a3
            800A5BB8	addu   a2, a2, v0
            800A5BBC	addiu  a2, a2, $00e8
            800A5BC0	lui    at, $8011
            800A5BC4	sh     a2, $41ba(at)
            800A5BC8	jal    func44ac0 [$80044ac0]
            800A5BCC	addiu  a1, t2, $fff8 (=-$8)
            800A5BD0	addiu  a0, s1, $0100
            800A5BD4	lui    t2, $8011
            800A5BD8	addiu  t2, t2, $4270
            800A5BDC	lui    v1, $800a
            800A5BE0	lbu    v1, $ac81(v1)
            800A5BE4	lui    a2, $800a
            800A5BE8	lbu    a2, $ac8f(a2)
            800A5BEC	lui    t1, $8007
            800A5BF0	lw     t1, $1e40(t1)
            800A5BF4	lhu    v0, $0000(s2)
            800A5BF8	lui    t0, $8007
            800A5BFC	lhu    t0, $1e38(t0)
            800A5C00	sll    v1, v1, $18
            800A5C04	sra    v1, v1, $18
            800A5C08	sll    a2, a2, $18
            800A5C0C	lhu    a3, $0020(t1)
            800A5C10	sra    a2, a2, $18
            800A5C14	subu   v0, v0, a3
            800A5C18	addu   v0, v0, t0
            800A5C1C	addu   v1, v1, v0
            800A5C20	sh     v1, $0000(t2)
            800A5C24	lhu    v0, $0000(s0)
            800A5C28	lhu    v1, $0022(t1)
            800A5C2C	lui    a3, $8007
            800A5C30	lhu    a3, $1e3c(a3)
            800A5C34	addu   v0, v0, v1
            800A5C38	addu   v0, v0, a3
            800A5C3C	addu   a2, a2, v0
            800A5C40	addiu  a2, a2, $00e8
            800A5C44	lui    at, $8011
            800A5C48	sh     a2, $4272(at)
            800A5C4C	jal    func44ac0 [$80044ac0]
            800A5C50	addiu  a1, t2, $fff8 (=-$8)
            800A5C54	addiu  a0, s1, $0040
            800A5C58	lui    t0, $8011
            800A5C5C	addiu  t0, t0, $4048
            800A5C60	lui    v1, $800a
            800A5C64	lbu    v1, $ac81(v1)
            800A5C68	lui    a3, $8007
            800A5C6C	lw     a3, $1e40(a3)
            800A5C70	lhu    a2, $0000(s2)
            800A5C74	sll    v1, v1, $18
            800A5C78	lhu    v0, $0020(a3)
            800A5C7C	sra    v1, v1, $18
            800A5C80	subu   a2, a2, v0
            800A5C84	subu   a2, a2, s3
            800A5C88	lui    v0, $800a
            800A5C8C	lbu    v0, $ac8f(v0)
            800A5C90	addu   v1, v1, a2
            800A5C94	sh     v1, $0000(t0)
            800A5C98	lhu    v1, $0000(s0)
            800A5C9C	lhu    a2, $0022(a3)
            800A5CA0	sll    v0, v0, $18
            800A5CA4	sra    v0, v0, $18
            800A5CA8	addu   v1, v1, a2
            800A5CAC	subu   v1, v1, s4
            800A5CB0	addu   v0, v0, v1
            800A5CB4	addiu  v0, v0, $00e8
            800A5CB8	lui    at, $8011
            800A5CBC	sh     v0, $404a(at)
            800A5CC0	jal    func44ac0 [$80044ac0]
            800A5CC4	addiu  a1, t0, $fff8 (=-$8)
            800A5CC8	addiu  a0, s1, $0080
            800A5CCC	lui    t0, $8011
            800A5CD0	addiu  t0, t0, $4100
            800A5CD4	addiu  a1, t0, $fff8 (=-$8)
            800A5CD8	lui    v1, $800a
            800A5CDC	lbu    v1, $ac81(v1)
            800A5CE0	lui    a3, $8007
            800A5CE4	lw     a3, $1e40(a3)
            800A5CE8	lhu    a2, $0000(s2)
            800A5CEC	sll    v1, v1, $18
            800A5CF0	lhu    v0, $0020(a3)
            800A5CF4	sra    v1, v1, $18
            800A5CF8	subu   a2, a2, v0
            800A5CFC	subu   a2, a2, s5
            V0 = b[8009ac8f];
            800A5D08	addu   v1, v1, a2
            800A5D0C	sh     v1, $0000(t0)
            800A5D10	lhu    v1, $0000(s0)
            800A5D14	lhu    a2, $0022(a3)
            800A5D20	addu   v1, v1, a2
            800A5D24	subu   v1, v1, s6
            800A5D28	addu   v0, v0, v1
            800A5D2C	addiu  v0, v0, $00e8
            800A5D30	lui    at, $8011
            800A5D34	sh     v0, $4102(at)
            800A5D38	jal    func44ac0 [$80044ac0]
        }

        [80071a48] = h(140 - hu[80071e38] - hu[8007eb90] - b[8009abf4 + 8d]); // background X centered
        [80071a4a] = h(e8 - hu[80071e3c] - hu[8007eb94] - b[8009abf4 + 9b]); // background Y centered

        [80071a4c] = h(S3 + 140 - hu[8007eb90] - b[8009abf4 + 8d]);
        [80071a4e] = h(S4 + e8 - hu[8007eb94] - b[8009abf4 + 9b]);

        [80071a50] = h(S5 + 140 - hu[8007eb90] - b[8009abf4 + 8d]);
        [80071a52] = h(S6 + e8 - hu[8007eb94] - b[8009abf4 + 9b]);
    }
}
////////////////////////////////



////////////////////////////////
// funca2f78
800A2F80	jal    func1c808 [$8001c808]
800A2F84	nop
800A2F88	lui    v1, $800a
800A2F8C	lw     v1, $ac5c(v1)
800A2F90	lui    at, $8011
800A2F94	sw     v0, $4454(at)
800A2F98	lui    at, $800a
800A2F9C	sw     v0, $ac5c(at)
800A2FA0	lui    at, $800a
800A2FA4	sw     v1, $ac60(at)
800A2FA8	xor    v1, v0, v1
800A2FAC	and    a0, v1, v0
800A2FB0	nor    v0, zero, v0
800A2FB4	and    v1, v1, v0
800A2FB8	lui    at, $800a
800A2FBC	sw     a0, $ac64(at)
800A2FC0	lui    at, $800a
800A2FC4	sw     v1, $ac68(at)
800A2FC8	jal    func1c8d4 [$8001c8d4]
800A2FCC	nop
800A2FD0	lui    v1, $800a
800A2FD4	lw     v1, $ac6c(v1)
800A2FD8	lui    at, $8011
800A2FDC	sw     v0, $4454(at)
800A2FE0	lui    at, $800a
800A2FE4	sw     v0, $ac6c(at)
800A2FE8	lui    at, $800a
800A2FEC	sw     v1, $ac70(at)
800A2FF0	xor    v1, v0, v1
800A2FF4	and    a0, v1, v0
800A2FF8	lui    at, $800a
800A2FFC	sw     a0, $ac74(at)
800A3000	nor    a0, zero, v0
800A3004	and    v1, v1, a0
800A3008	lui    at, $800a
800A300C	sw     v1, $ac78(at)
////////////////////////////////