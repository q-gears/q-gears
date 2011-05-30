////////////////////////////////////////////////////
// funcba360
// A0 = part
// A1 = 800faff4 + 70 by part or by 4070;
// A2 = c or 0;
// A3 = 0;

V1 = w[801590e8 + A0 * 4]; // offset to part
T0 = 801590e4 + V1 & 7fffffff; // global offset to part
if (V1 & 80000000)
{
    V1 = 0008;
}
else
{
    V1 = 0000;
}
V1 = V1 | A3 | 0180;

[1f800320] = w(T0); // global offset to part
[1f800324] = w(V1);
[1f800328] = h(0000);
[1f80032a] = h(hu[800f5b74]);
[1f80032c] = h(0020); // blending for this part 0.5xB + 0.5xF
[1f80032e] = h(0000);

A0 = 1f800320;
A2 = A2;
A3 = w[80153c74];
funcd29d4;
[80163c74] = w(V0);

return;
////////////////////////////////////////////////////



/////////////////////////////////////////////
// funcd29d4
// A3 - offset to packets
// A2 - 00 or 0c (in effect machingun fire loading - 0c)
A2 = e - A2;

S7 = hu[800d3544 + 0];
FP = hu[800d3544 + 2];

S0 = w[A0 + 4]; // flags 0x0100 - use +7[] as vertex specific packet addition (only without 0x0040).
                //       0x0080 - use +6[] as color in vertex, if not set use function argument as color.
                //       0x0040 - use +7[] as vertex texture page settings instead of global part.
                //       0x0020 - render triangles.
                //       0x0010 - use color interpolation.
                //       0x0008 - render packets with transparensy on.
S1 = hu[A0 + 8];
S2 = hu[A0 + a]; // color for polygons
S3 = hu[A0 + c]; // blending option
S4 = hu[A0 + e];
A0 = w[A0 + 0]; // global offset to part



if ((S0 & 0080) == 0)
{
    S2 = (S2 << 10) | (S2 << 8) | S2;
}



800D2A44	sll    s4, s4, $10


V0 = w[A0 + 00]; // offset to triangle
S5 = A0 + 4;
A0 = S5 + V0; // real offset to triangle data



// add transparency bit to polygon header
V0 = S0 & 0008;
V0 = V0 << 16;
S2 = S2 | V0;



S6 = 0;
if (S0 & 0001)
{
    S6 = S6 XOR ffffffff;
    funcd3418;
}
if (S0 & 0002)
{
    S6 = S6 XOR ffffffff;
    funcd3474;
}
if (S0 & 0004)
{
    S6 = S6 XOR ffffffff;
    funcd34c8;
}



if ((S0 & 0040) == 0)
{
    S3 = (h[A0 + 2] & 19f) + S3; // add blend
}



T8 = h[A0 + 0]; // number of triangle
A0 = A0 + 4;
S7 = S7 + T8;
if (T8 != 0)
{
    T8 = T8 - 1;

    Ld2afc:	; 800D2AFC
        T4 = S5 + h[A0 + 0];
        T5 = S5 + h[A0 + 2];
        T6 = S5 + h[A0 + 4];

        VXY0 = w[T4 + 0]; VZ0  = w[T4 + 4];
        VXY1 = w[T5 + 0]; VZ1  = w[T5 + 4];
        VXY2 = w[T6 + 0]; VZ2  = w[T6 + 4];
        gte_RTPT; // Perspective transform on 3 points.
        V0 = FLAG;

        gte_NCLIP; // Normal clipping.

        V0 = V0 & 00060000;
        // Limiter C out of range (less than 0, or 2^16 or more)
        // Divide overflow generated (quotient of 2.0 or more)
        if (V0 == 0)
        {
            V0 = MAC0; // result of normal clipping
            if (S0 & 20 || (V0 != 0 && (V0 XOR S6) >= 0))
            {
                T0 = SXY0;
                T1 = SXY1;
                T2 = SXY2;

                // if at least 1 point is on screen
                if (((T0 << 10) >= 0 || (T1 << 10) >= 0 || (T2 << 10) >= 0) &&
                    ((T0 << 10) < 140 || (T1 << 10) < 140 || (T2 << 10) < 140) &&
                    (((T0 >= 0) && (T0 < a6 || T1 < a6 || T2 < a6)) || (T1 >= 0 || T2 >= 0))
                {
                    // set vertex pos
                    [A3 + 8] = w(T0);
                    [A3 + 10] = w(T1);
                    [A3 + 18] = w(T2);



                    // do depth sort
                    gte_AVSZ3; // Average of four Z values
                    T0 = OTZ;
                    T0 = T0 >> A2;
                    T1 = w[A1 + T0 * 4];
                    T1 = T1 & 00ffffff;
                    T1 = T1 | 07000000;
                    [A3 + 0] = w(T1);
                    [A1 + T0 * 4] = w(A3 & 00ffffff);



                    // set clut and uv
                    [A3 + c] = w(w[A0 + 8] + S4 + S1);
                    [A3 + 14] = h(h[A0 + c] + S1);
                    [A3 + 1c] = h(h[A0 + e] + S1);



                    T0 = h[A0 + 6];
                    T1 = 0;
                    if ((S0 & 0040) == 0)
                    {
                        [A3 + 16] = h(S3);

                        if (S0 & 0100)
                        {
                            T1 = T0 & ff00;
                            T1 = T1 << 10;
                        }
                    }
                    else
                    {
                        [A3 + 16] = h((T0 >> 8) & 19f + S3); // add texpage settings from vertex
                    }

                    if (S0 & 0080)
                    {
                        V0 = S2 & ff000000; // BGR only
                        V0 = 24000000 | (T0 & ff << 10) | (T0 & ff << 8) | (T0 & ff);

                        if ((S0 & 0010) == 0)
                        {
                            V1 = S2 & ffff;
                            if (V1 != 0)
                            {
                                IR0 = V1;
                                RGB = V0;
                                gte_DPCS;
                                V0 = RGB2;
                                V0 = V0 | (S2 >> 10) << 10;
                            }
                        }
                    }
                    else
                    {
                        V0 = 24000000 | S2;
                    }

                    V0 = V0 | T1;
                    [A3 + 4] = w(V0);

                    A3 = A3 + 20;
                    FP = FP + 1;
                }
            }
        }

        A0 = A0 + 10;
        T8 = T8 - 1;
    800D2CD0	bne    t8, zero, Ld2afc [$800d2afc]

}



AT = 800d2f0c;
T8 = w[A0];
A0 = A0 + 4;
S7 = S7 + T8;
if (T8 != 0)
{
    S7 = S7 + T8;
    T8 = T8 - 1;

    T4 = S5 + h[A0 + 0];
    T5 = S5 + h[A0 + 2];
    T6 = S5 + h[A0 + 4];

    Ld2d10:	; 800D2D10
        VXY0 = w[T4 + 0]; VZ0  = w[T4 + 4];
        VXY1 = w[T5 + 0]; VZ1  = w[T5 + 4];
        VXY2 = w[T6 + 0]; VZ2  = w[T6 + 4];
        A0 = A0 + 14;
        gte_RTPT; // Perspective transform on 3 points.
        V0 = FLAG;

        T4 = S5 + h[A0 + 0];
        T5 = S5 + h[A0 + 2];
        T6 = S5 + h[A0 + 4];

        gte_NCLIP; // Normal clipping.

        V1 = 00060000;
        V0 = V0 & V1;
        800D2D58	bne    v0, zero, Ld2f0c [$800d2f0c]
        800D2D5C	nop
        800D2D60	andi   v0, s0, $0020
        800D2D64	bne    v0, zero, Ld2d84 [$800d2d84]
        800D2D68	nop
        800D2D6C	mfc2   v0,ofx
        800D2D70	nop
        800D2D74	beq    v0, zero, Ld2d84 [$800d2d84]
        800D2D78	xor    v0, v0, s6
        800D2D7C	bltz   v0, Ld2f0c [$800d2f0c]
        800D2D80	nop

        Ld2d84:	; 800D2D84
        800D2D84	lh     t7, $fff2(a0)
        800D2D88	mfc2   t0,l33
        800D2D8C	addu   t7, s5, t7
        800D2D90	mfc2   t1,rbk
        800D2D94	lwc2   zero, $0000(t7)
        800D2D98	lwc2   at, $0004(t7)
        800D2D9C	mfc2   t2,gbk
        800D2DA0	gte_func16t8,r11r12
        800D2DA4	mfc2   t3,gbk
        800D2DA8	jal    funcd3354 [$800d3354]
        800D2DAC	nop
        800D2DB0	sw     t0, $0008(a3)
        800D2DB4	sw     t1, $0010(a3)
        800D2DB8	sw     t2, $0018(a3)
        800D2DBC	sw     t3, $0020(a3)
        800D2DC0	gte_func27t0,r11r12
        800D2DC4	mfc2   t0,trz
        800D2DC8	nop
        800D2DCC	srav   t0, a2, t0
        800D2DD0	sll    t0, t0, $02
        800D2DD4	addu   t0, t0, a1
        800D2DD8	lw     t1, $0000(t0)
        800D2DDC	lui    v0, $00ff
        800D2DE0	ori    v0, v0, $ffff
        800D2DE4	lui    v1, $0900
        800D2DE8	and    t1, t1, v0
        800D2DEC	or     t1, t1, v1
        800D2DF0	sw     t1, $0000(a3)
        800D2DF4	and    v0, a3, v0
        800D2DF8	sw     v0, $0000(t0)
        800D2DFC	lw     t0, $fff4(a0)
        800D2E00	lh     t1, $fff8(a0)
        800D2E04	lh     t2, $fffa(a0)
        800D2E08	lh     t3, $fffc(a0)
        800D2E0C	add    t0, t0, s4
        800D2E10	add    t0, t0, s1
        800D2E14	add    t1, t1, s1
        800D2E18	add    t2, t2, s1
        800D2E1C	add    t3, t3, s1
        800D2E20	sw     t0, $000c(a3)
        800D2E24	sh     t1, $0014(a3)
        800D2E28	sh     t2, $001c(a3)
        800D2E2C	sh     t3, $0024(a3)
        800D2E30	lh     t0, $fffe(a0)
        800D2E34	andi   v0, s0, $0040
        800D2E38	beq    v0, zero, Ld2e58 [$800d2e58]
        800D2E3C	nop
        800D2E40	srl    v0, t0, $08
        800D2E44	andi   v0, v0, $019f
        800D2E48	add    v0, v0, s3
        800D2E4C	sh     v0, $0016(a3)
        800D2E50	j      Ld2e70 [$800d2e70]
        800D2E54	addu   t1, zero, zero

        Ld2e58:	; 800D2E58
        800D2E58	sh     s3, $0016(a3)
        800D2E5C	andi   v0, s0, $0100
        800D2E60	beq    v0, zero, Ld2e70 [$800d2e70]
        800D2E64	addu   t1, zero, zero
        800D2E68	andi   t1, t0, $ff00
        800D2E6C	sll    t1, t1, $10

        Ld2e70:	; 800D2E70
        800D2E70	andi   v0, s0, $0080
        800D2E74	beq    v0, zero, Ld2ef4 [$800d2ef4]
        800D2E78	nop
        800D2E7C	lui    v0, $ff00
        800D2E80	and    v0, s2, v0
        800D2E84	lui    v1, $2c00
        800D2E88	or     v0, v0, v1
        800D2E8C	andi   v1, t0, $00ff
        800D2E90	or     v0, v0, v1
        800D2E94	sll    v1, v1, $08
        800D2E98	or     v0, v0, v1
        800D2E9C	sll    v1, v1, $08
        800D2EA0	or     v0, v0, v1
        800D2EA4	andi   v1, s0, $0010
        800D2EA8	bne    v1, zero, Ld2efc [$800d2efc]
        800D2EAC	andi   v1, s2, $ffff
        800D2EB0	beq    v1, zero, Ld2efc [$800d2efc]
        800D2EB4	nop
        800D2EB8	mtc2   v1,l11l12
        800D2EBC	mtc2   v0,try
        800D2EC0	nop
        800D2EC4	nop
        800D2EC8	gte_func19t8,r11r12
        800D2ECC	nop
        800D2ED0	nop
        800D2ED4	mfc2   v0,gfc
        800D2ED8	srl    v1, s1, $10
        800D2EDC	sll    v1, v1, $10
        800D2EE0	or     v0, v0, v1
        800D2EE4	or     v0, v0, t1
        800D2EE8	sw     v0, $0004(a3)
        800D2EEC	j      Ld2f04 [$800d2f04]
        800D2EF0	nop

        Ld2ef4:	; 800D2EF4
        800D2EF4	lui    v0, $2c00
        800D2EF8	or     v0, v0, s2

        Ld2efc:	; 800D2EFC
        800D2EFC	or     v0, v0, t1
        800D2F00	sw     v0, $0004(a3)

        Ld2f04:	; 800D2F04
        800D2F04	addiu  a3, a3, $0028
        800D2F08	addiu  fp, fp, $0002

        Ld2f0c:	; 800D2F0C
        T8 = T8 - 1;
    800D2F0C	bne    t8, zero, Ld2d10 [$800d2d10]
}



800D2F14	lui    at, $800d
800D2F18	ori    at, at, $3098
800D2F1C	lh     t8, $0000(a0)
800D2F20	addiu  a0, a0, $0004
800D2F24	beq    t8, zero, Ld30a0 [$800d30a0]
800D2F28	addu   s7, s7, t8
800D2F2C	addiu  t8, t8, $ffff (=-$1)
800D2F30	lh     t4, $0000(a0)
800D2F34	lh     t5, $0002(a0)
800D2F38	lh     t6, $0004(a0)
800D2F3C	addu   t4, s5, t4
800D2F40	addu   t5, s5, t5
800D2F44	addu   t6, s5, t6

loopd2f48:	; 800D2F48
800D2F48	lwc2   zero, $0000(t4)
800D2F4C	lwc2   at, $0004(t4)
800D2F50	lwc2   v0, $0000(t5)
800D2F54	lwc2   v1, $0004(t5)
800D2F58	lwc2   a0, $0000(t6)
800D2F5C	lwc2   a1, $0004(t6)
800D2F60	addiu  a0, a0, $0014
800D2F64	gte_func17t0,r11r12
800D2F68	lh     t4, $0000(a0)
800D2F6C	lh     t5, $0002(a0)
800D2F70	lh     t6, $0004(a0)
800D2F74	addu   t4, s5, t4
800D2F78	addu   t5, s5, t5
800D2F7C	addu   t6, s5, t6
800D2F80	cfc2   v0,lzcr
800D2F84	gte_func26zero,r11r12
800D2F88	lui    v1, $0006
800D2F8C	and    v0, v0, v1
800D2F90	bne    v0, zero, Ld3098 [$800d3098]
800D2F94	nop
800D2F98	andi   v0, s0, $0020
800D2F9C	bne    v0, zero, Ld2fbc [$800d2fbc]
800D2FA0	nop
800D2FA4	mfc2   v0,ofx
800D2FA8	nop
800D2FAC	beq    v0, zero, Ld3098 [$800d3098]
800D2FB0	xor    v0, v0, s6
800D2FB4	bltz   v0, Ld3098 [$800d3098]
800D2FB8	nop

Ld2fbc:	; 800D2FBC
800D2FBC	mfc2   t0,l33
800D2FC0	mfc2   t1,rbk
800D2FC4	mfc2   t2,gbk
800D2FC8	jal    funcd32b4 [$800d32b4]
800D2FCC	nop
800D2FD0	sw     t0, $0008(a3)
800D2FD4	sw     t1, $0010(a3)
800D2FD8	sw     t2, $0018(a3)
800D2FDC	gte_func26t8,r11r12
800D2FE0	mfc2   t0,trz
800D2FE4	nop
800D2FE8	srav   t0, a2, t0
800D2FEC	sll    t0, t0, $02
800D2FF0	addu   t0, t0, a1
800D2FF4	lw     t1, $0000(t0)
800D2FF8	lui    v0, $00ff
800D2FFC	ori    v0, v0, $ffff
800D3000	lui    v1, $0600
800D3004	and    t1, t1, v0
800D3008	or     t1, t1, v1
800D300C	sw     t1, $0000(a3)
800D3010	and    v0, a3, v0
800D3014	sw     v0, $0000(t0)
800D3018	andi   v1, s2, $ffff
800D301C	beq    v1, zero, Ld3074 [$800d3074]
800D3020	nop
V0 = w[A0 - c];
RGB1 = w[A0 - 8];
RGB0 = w[A0 - 4];
RGB2 = V0;
RGB = V0;
IR0 = V1;
DPCT; // Depth cue color RGB0,RGB1,RGB2.

800D3050	mfc2   v0,gfc
800D3054	swc2   s4, $0014(a3)
800D3058	swc2   s5, $000c(a3)
800D305C	srl    v1, s2, $10
800D3060	sll    v1, v1, $10
800D3064	or     v0, v0, v1
800D3068	sw     v0, $0004(a3)
800D306C	j      Ld3090 [$800d3090]
800D3070	nop

Ld3074:	; 800D3074
800D3074	lw     t0, $fff4(a0)
800D3078	lw     t1, $fff8(a0)
800D307C	lw     t2, $fffc(a0)
800D3080	or     t0, t0, s2
800D3084	sw     t0, $0004(a3)
800D3088	sw     t1, $000c(a3)
800D308C	sw     t2, $0014(a3)

Ld3090:	; 800D3090
800D3090	addiu  a3, a3, $001c
800D3094	addiu  fp, fp, $0001

Ld3098:	; 800D3098
800D3098	bne    t8, zero, loopd2f48 [$800d2f48]
800D309C	addi   t8, t8, $ffff (=-$1)

Ld30a0:	; 800D30A0
800D30A0	lui    at, $800d
800D30A4	ori    at, at, $326c
800D30A8	lw     t8, $0000(a0)
800D30AC	addiu  a0, a0, $0004
800D30B0	beq    t8, zero, Ld3274 [$800d3274]
800D30B4	addu   s7, s7, t8
800D30B8	addu   s7, s7, t8
800D30BC	addiu  t8, t8, $ffff (=-$1)
800D30C0	lh     t4, $0000(a0)
800D30C4	lh     t5, $0002(a0)
800D30C8	lh     t6, $0004(a0)
800D30CC	addu   t4, s5, t4
800D30D0	addu   t5, s5, t5
800D30D4	addu   t6, s5, t6

Ld30d8:	; 800D30D8
800D30D8	lwc2   zero, $0000(t4)
800D30DC	lwc2   at, $0004(t4)
800D30E0	lwc2   v0, $0000(t5)
800D30E4	lwc2   v1, $0004(t5)
800D30E8	lwc2   a0, $0000(t6)
800D30EC	lwc2   a1, $0004(t6)
800D30F0	addiu  a0, a0, $0018
800D30F4	gte_func17t0,r11r12

T4 = h[A0 + 0];
T5 = h[A0 + 2];
T6 = h[A0 + 4];

800D3104	addu   t4, s5, t4
800D3108	addu   t5, s5, t5
800D310C	addu   t6, s5, t6
800D3110	cfc2   v0,lzcr
800D3114	gte_func26zero,r11r12
800D3118	lui    v1, $0006
800D311C	and    v0, v0, v1
800D3120	bne    v0, zero, Ld326c [$800d326c]
800D3124	nop
800D3128	andi   v0, s0, $0020
800D312C	bne    v0, zero, Ld314c [$800d314c]
800D3130	nop
800D3134	mfc2   v0,ofx
800D3138	nop
800D313C	beq    v0, zero, Ld314c [$800d314c]
800D3140	xor    v0, v0, s6
800D3144	bltz   v0, Ld326c [$800d326c]
800D3148	nop

Ld314c:	; 800D314C
800D314C	lh     t7, $ffee(a0)
800D3150	mfc2   t0,l33
800D3154	addu   t7, s5, t7
800D3158	mfc2   t1,rbk
800D315C	lwc2   zero, $0000(t7)
800D3160	lwc2   at, $0004(t7)
800D3164	mfc2   t2,gbk
800D3168	gte_func16t8,r11r12
800D316C	mfc2   t3,gbk
800D3170	jal    funcd3354 [$800d3354]
800D3174	nop
800D3178	sw     t0, $0008(a3)
800D317C	sw     t1, $0010(a3)
800D3180	sw     t2, $0018(a3)
800D3184	sw     t3, $0020(a3)
800D3188	gte_func27t0,r11r12
800D318C	mfc2   t0,trz
800D3190	nop
800D3194	srav   t0, a2, t0
800D3198	sll    t0, t0, $02
800D319C	addu   t0, t0, a1
800D31A0	lw     t1, $0000(t0)
800D31A4	lui    v0, $00ff
800D31A8	ori    v0, v0, $ffff
800D31AC	lui    v1, $0800
800D31B0	and    t1, t1, v0
800D31B4	or     t1, t1, v1
800D31B8	sw     t1, $0000(a3)
800D31BC	and    v0, a3, v0
800D31C0	sw     v0, $0000(t0)
800D31C4	andi   v1, s2, $ffff
800D31C8	beq    v1, zero, Ld3240 [$800d3240]
800D31CC	nop
800D31D0	lw     v0, $fff0(a0)
800D31D4	lwc2   s5, $fff4(a0)
800D31D8	lwc2   s4, $fff8(a0)
800D31DC	mtc2   v0,gfc
800D31E0	mtc2   v0,try
800D31E4	mtc2   v1,l11l12
800D31E8	nop
800D31EC	nop
800D31F0	gte_func23t8,r11r12
800D31F4	nop
800D31F8	nop
800D31FC	mfc2   v0,gfc
800D3200	swc2   s4, $0014(a3)
800D3204	swc2   s5, $000c(a3)
800D3208	srl    t0, s2, $10
800D320C	sll    t0, t0, $10
800D3210	or     v0, v0, t0
800D3214	sw     v0, $0004(a3)
800D3218	lwc2   a2, $fffc(a0)
800D321C	mtc2   v1,l11l12
800D3220	nop
800D3224	nop
800D3228	gte_func19t8,r11r12
800D322C	nop
800D3230	nop
800D3234	swc2   s6, $001c(a3)
800D3238	j      Ld3264 [$800d3264]
800D323C	nop

Ld3240:	; 800D3240
800D3240	lw     v0, $fff0(a0)
800D3244	lw     v1, $fff4(a0)
800D3248	lw     t0, $fff8(a0)
800D324C	lw     t1, $fffc(a0)
800D3250	or     v0, v0, s2
800D3254	sw     v0, $0004(a3)
800D3258	sw     v1, $000c(a3)
800D325C	sw     t0, $0014(a3)
800D3260	sw     t1, $001c(a3)

Ld3264:	; 800D3264
800D3264	addiu  a3, a3, $0024
800D3268	addiu  fp, fp, $0002

Ld326c:	; 800D326C
800D326C	bne    t8, zero, Ld30d8 [$800d30d8]
800D3270	addi   t8, t8, $ffff (=-$1)

Ld3274:	; 800D3274
800D3274	lui    v0, $800d
800D3278	ori    v0, v0, $3544
800D327C	sh     s7, $0000(v0)
800D3280	sh     fp, $0002(v0)

return A3;
/////////////////////////////////////////////



/////////////////////////////////////////////
// funcd32b4
if ((T0 << 10) >= 0 || (T1 << 10) >= 0 || (T2 << 10) >= 0)
{
    if ((T0 << 10) < 140 || (T1 << 10) < 140 || (T2 << 10) < 140)
    {
        if (((T0 >= 0) && (T0 < a6 || T1 < a6 || T2 < a6)) || (T1 >= 0 || T2 >= 0))
        {
            return;
        }
    }
}

800D3344	jr     at 
/////////////////////////////////////////////