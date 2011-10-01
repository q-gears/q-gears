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

if( ( hu[80114488] != 0 ) && ( bu[8009abf4 + 3a] == 0 ) )
{
    if( bu[8009ac2d] != 1 )
    {
        if( S2 == 800e4df0 )
        {
            [80113f34] = h(hu[8007eb90] - hu[offset_to_camera + 20]);
            [80113f36] = h(hu[8007eb94] + hu[offset_to_camera + 22]);

            A0 = S2 + 41d4;
            A1 = 80113f34 - 8;
            A2 = offset_to_camera;
            func44ac0;
        }
        else
        {
            [80113f90] = h(hu[8007eb90] - hu[offset_to_camera + 20]);
            [80113f92] = h(hu[8007eb94] + hu[offset_to_camera + 22] + e8);

            A0 = 80100860;
            A1 = 80113f88;
            A2 = offset_to_camera;
            func44ac0;
        }
    }
    else
    {
        if( S2 != 800e4df0 )
        {
            [80113f90] = h(hu[8007eb90] + hu[80071e38]);
            [80113f92] = h(hu[8007eb94] + hu[80071e3c] + e8);

            A0 = 80100860;
            A1 = 80113f90 - 8;
            A2 = hu[80071e38];
            func44ac0;
        }
        else
        {
            [80113f34] = h(hu[8007eb90] + hu[80071e38]);
            [80113f36] = h(hu[8007eb94] + hu[80071e3c]);

            A0 = S2 + 41d4;
            A1 = 80113f34 - 8;
            A2 = hu[80071e38];
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



        V0 = h[800965e0];
        [SP + 10] = h((w[80074ea4 + V0 * 84 +  c] >> c) + hu[80074ea4 + V0 * 84 + 40]);
        [SP + 12] = h((w[80074ea4 + V0 * 84 + 10] >> c) + hu[80074ea4 + V0 * 84 + 46]);
        [SP + 14] = h((w[80074ea4 + V0 * 84 + 14] >> c) + hu[80074ea4 + V0 * 84 + 4c] + (h[8009abf4] >> 2)); // with field scale

        A0 = SP + 10;
        A1 = SP + 18;
        field_calculate_distance_to_screen;

        [80114464] = h(hu[SP + 18] + hu[8007eb90]);
        [80114468] = h(hu[SP + 1a] + hu[8007eb94]);

        V0 = h[800965e0];
        [SP + 10] = h(w[80074ea4 + V0 * 84 + 0c] >> c);
        [SP + 12] = h(w[80074ea4 + V0 * 84 + 10] >> c);
        [SP + 14] = h(w[80074ea4 + V0 * 84 + 14] + hu[8009abf4 + 16] >> c);

        A0 = SP + 10;
        A1 = SP + 18;
        field_calculate_distance_to_screen;

        [800e48ec] = w(V0);
        [800e48e4] = h(hu[SP + 18]);
        [800e48e6] = h(hu[SP + 1a]);
        A0 = SP + 18;
        800A5034	jal    funca47f8 [$800a47f8]

        A0 = offset_to_triggers;
        A1 = SP + 18;
        800A5044	jal    funca45d4 [$800a45d4]

        S5 = (((((h[SP + 18] * h[offset_to_triggers + 28]) >> 8) + (h[offset_to_triggers + 20] >> 4)) << 10) >> 10) % h[offset_to_triggers + 18];
        S4 = (((((h[SP + 1a] * h[offset_to_triggers + 2a]) >> 8) + (h[offset_to_triggers + 22] >> 4)) << 10) >> 10) % h[offset_to_triggers + 1a];
        S7 = (((((h[SP + 18] * h[offset_to_triggers + 2c]) >> 8) + (h[offset_to_triggers + 24] >> 4)) << 10) >> 10) % h[offset_to_triggers + 1c];
        S6 = (((((h[SP + 1a] * h[offset_to_triggers + 2e]) >> 8) + (h[offset_to_triggers + 26] >> 4)) << 10) >> 10) % h[offset_to_triggers + 1e];

        [80114468] = h(hu[80114468] - h[SP + 1a]);
        [80114464] = h(hu[80114464] - h[SP + 18]);

        [SP + 20] = h(S4);
        [SP + 28] = h(S7);
        [SP + 30] = h(S6);

        if( S2 == 800e4df0 )
        {
            [80113f34] = h(b[8009ac81] + hu[8007eb90] - h[SP + 18]);
            [80113f36] = h(b[8009ac8f] + hu[8007eb94] - h[SP + 1a]);

            A0 = 800e4df0 + 41d4;
            A1 = 80113f34 - 8;
            A2 = hu[8007eb90] - h[SP + 18];
            func44ac0;

            [8011415e] = h(b[8009ac8f] + hu[8007eb94] - hu[SP + 1a]);
            [8011415c] = h(b[8009ac81] + hu[8007eb90] - hu[SP + 18]);

            A0 = 800e4df0 + 4294;
            A1 = 8011415c - 8;
            A2 = hu[8007eb94] - hu[SP + 1a];
            func44ac0;

            [80114216] = h(b[8009ac8f] + hu[8007eb94] - hu[SP + 1a]);
            [80114214] = h(b[8009ac81] + hu[8007eb90] - hu[SP + 18]);

            A0 = 800e4df0 + 42d4;
            A1 = 80114214 - 8;
            A2 = hu[8007eb94] - hu[SP + 1a];
            func44ac0;

            [80113fec] = h(b[8009ac81] - hu[8007eb90] - S5);
            [80113fee] = h(b[8009ac8f] + hu[8007eb94] - S4);

            A0 = 800e4df0 + 4214;
            A1 = 80113fec - 8;
            A2 = hu[8007eb90] - S5;
            func44ac0;

            [801140a4] = h(b[8009ac81] + hu[8007eb90] - S7);
            [801140a6] = h(b[8009ac8f] + hu[8007eb94] - S6);

            A0 = 800e4df0 + 4254;
            A1 = 801140a4 - 8;
            A2 = hu[8007eb90] - S7;
            func44ac0;
        }
        else
        {
            [80113f90] = h(b[8009ac81] + hu[8007eb90] - h[SP + 18]);
            [80113f92] = h(b[8009ac8f] + hu[8007eb94] - h[SP + 1a] + e8);

            A0 = 80100860;
            A1 = 80113f90 - 8;
            A2 = hu[8007eb90] - h[SP + 18];
            func44ac0;

            [801141ba] = h(b[8009ac8f] + hu[8007eb94] - hu[SP + 1a] + e8);
            [801141b8] = h(b[8009ac81] + hu[8007eb90] - hu[SP + 18]);

            A0 = 80100860 + c0;
            A1 = 801141b8 - 8;
            A2 = hu[8007eb94] - hu[SP + 1a];
            func44ac0;

            [80114272] = h(b[8009ac8f] + hu[8007eb94] - hu[SP + 1a] + e8);
            [80114270] = h(b[8009ac81] + hu[8007eb90] - hu[SP + 18]);

            A0 = 80100860 + 100;
            A1 = 80114270 - 8;
            A2 = hu[8007eb94] - hu[SP + 1a];
            func44ac0;

            [80114048] = h(b[8009ac81] + hu[8007eb90] - S5);
            [8011404a] = h(b[8009ac8f] + hu[8007eb94] - S4 + e8);

            A0 = 80100860 + 40;
            A1 = 80114048 - 8;
            A2 = hu[8007eb90] - S5;
            func44ac0;

            [80114100] = h(b[8009ac81] + hu[8007eb90] - S7);
            [80114102] = h(b[8009ac8f] + hu[8007eb94] - S6 + e8);

            A0 = 80100860 + 80;
            A1 = 80114100 - 8;
            A2 = hu[8007eb90] - S7;
            func44ac0;
        }

        [80071e38] = h(0 - hu[SP + 18]);
        [80071e3c] = h(0 - hu[SP + 1a]);
        [80071a48] = h(hu[SP + 18] + 140 - hu[8007eb90] - b[8009ac81]);
        [80071a4a] = h(hu[SP + 1a] + e8 - hu[8007eb94] - b[8009ac8f]);
        [80071a4c] = h(S5          + 140 - hu[8007eb90] - b[8009ac81]);
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
            A2 = hu[offset_to_camera + 22];
            func44ac0;

            [8011415c] = h(val1);
            [8011415e] = h(val2);

            A0 = 800e9084;
            A1 = 80114154;
            A2 = val2;
            func44ac0;

            [80114214] = h(val1);
            [80114216] = h(val2);

            A0 = 800e90c4;
            A1 = 8011420c;
            A2 = val2;
            func44ac0;

            [80113fec] = h(b[8009abf4 + 8d] + hu[8007eb90] - hu[offset_to_camera + 20] - S3);
            [80113fee] = h(b[8009abf4 + 9b] + hu[8007eb94] + hu[offset_to_camera + 22] - S4);

            A0 = 800e9004;
            A1 = 80113fe4;
            A2 = hu[offset_to_camera + 22];
            func44ac0;

            [801140a4] = h(b[8009abf4 + 8d] + hu[8007eb90] - hu[offset_to_camera + 20] - S5);
            [801140a6] = h(b[8009abf4 + 9b] + hu[8007eb94] + hu[offset_to_camera + 22] - S6);

            A0 = 800e9044;
            A1 = 8011409c;
            A2 = hu[offset_to_camera + 22];
            func44ac0;
        }
        else
        {
            val1 = b[8009abf4 + 8d] + hu[8007eb90] - hu[offset_to_camera + 20] + h[80071e38];
            val2 = b[8009abf4 + 9b] + hu[8007eb94] + hu[offset_to_camera + 22] + w[80071e3c];

            [80113f90] = h(val1);
            [80113f92] = h(val2 + e8);

            A0 = 80100830;
            A1 = 80113f90 - 8;
            A2 = hu[offset_to_camera + 22];
            func44ac0;

            [801141b8] = h(val1);
            [801141ba] = h(val2 + e8);

            A0 = 80100830 + c0;
            A1 = 801141b8 - 8;
            A2 = val2 + e8;
            func44ac0;

            [80114270] = h(val1);
            [80114272] = h(val2 + e8);

            A0 = 80100830 + 100;
            A1 = 80114270 - 8;
            A2 = val2 + e8;
            func44ac0;

            [80114048] = h(b[8009ac81] + hu[8007eb90] - hu[offset_to_camera + 20] - S3);
            [8011404a] = h(b[8009ac8f] + hu[8007eb94] + hu[offset_to_camera + 22] - S4 + e8);

            A0 = 80100830 + 40;
            A1 = 80114048 - 8;
            A2 = hu[offset_to_camera + 22];
            func44ac0;

            [80114100] = h(b[8009ac81] + hu[8007eb90] - hu[offset_to_camera + 20] - S5);
            [80114102] = h(b[8009ac8f] + hu[8007eb94] + hu[offset_to_camera + 22] - S6 + e8);

            A0 = 80100830 + 80;
            A1 = 80114100 - 8;
            A2 = hu[offset_to_camera + 22];
            func44ac0;
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