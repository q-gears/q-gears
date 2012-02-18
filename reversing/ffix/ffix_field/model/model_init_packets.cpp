////////////////////////////////
// funcb6584
model_data = A0;

T4 = w[model_data + 10];
model_file = S0 = w[model_data + 8];

[model_data + 18] = w(A1); // first data from 0x12 file
V0 = bu[model_file + 3];
V1 = w[model_data + 44];
if( V0 == 0 )
{
    return;
}

T9 = V1;
T7 = 0;
S1 = 8;
S2 = 38;
Lb65bc:	; 800B65BC
    V0 = T7 * 28;
    V1 = w[model_file + 10];
    T2 = V1 + V0;
    T6 = w[T2 + 24];
    T8 = 0;
    [T9 + 4] = w(T4);
    [T9 + 0] = h(0);
    [T9 + 8] = w(0);

    Lb65e4:	; 800B65E4
        T5 = w[T2 + 1c];

        V0 = hu[T2 + 2];
        if( V0 != 0 )
        {
            T3 = 0;
            Lb65fc:	; 800B65FC
                [T4 + T3 * 28 + 3] = b(9);
                [T4 + T3 * 28 + 4] = b(bu[T5 + T3 * 18 + 10]); // r
                [T4 + T3 * 28 + 5] = b(bu[T5 + T3 * 18 + 11]); // g
                [T4 + T3 * 28 + 6] = b(bu[T5 + T3 * 18 + 12]); // b
                [T4 + T3 * 28 + 7] = b(2c);

                V0 = hu[T5 + T3 * 18 + 8];
                V1 = w[T2 + 20];
                [T4 + T3 * 28 + c] = h(hu[V1 + V0 * 2]);
                V0 = hu[T5 + T3 * 18 + a];
                [T4 + T3 * 28 + 14] = h(hu[V1 + V0 * 2]);
                V0 = hu[T5 + T3 * 18 + c];
                [T4 + T3 * 28 + 1c] = h(hu[V1 + V0 * 2]);
                V0 = hu[T5 + T3 * 18 + e];
                [T4 + T3 * 28 + 24] = h(hu[V1 + V0 * 2]);


                V0 = w[model_data + 18] + bu[T5 + T3 * 18 + 13] * 4;
                [T4 + T3 * 28 + e] = h(hu[V0 + 2]); // CLUT
                A3 = hu[V0 + 0] & ffdf; // reset blending by default
                [T4 + T3 * 28 + 16] = h(A3);

                if( bu[T5 + T3 * 18 + 15] & 1 )
                {
                    [T4 + T3 * 28 + 16] = h(A3 | (bu[T5 + T3 * 18 + 15] & e0));
                    [T4 + T3 * 28 + 7] = b(bu[T4 + T3 * 28 + 7] | 2); // semi transparency on
                }

                V0 = bu[T5 + T3 * 18 + 13];

                A3 = h[A2 + V0 * 4 + 0];
                T0 = h[A2 + V0 * 4 + 2];

                [T4 + T3 * 28 + c] = b(bu[T4 + T3 * 28 + c] + A3);
                [T4 + T3 * 28 + d] = b(bu[T4 + T3 * 28 + d] + T0);
                [T4 + T3 * 28 + 14] = b(bu[T4 + T3 * 28 + 14] + A3);
                [T4 + T3 * 28 + 15] = b(bu[T4 + T3 * 28 + 15] + T0);
                [T4 + T3 * 28 + 1d] = b(bu[T4 + T3 * 28 + 1d] + A3);
                [T4 + T3 * 28 + 1c] = b(bu[T4 + T3 * 28 + 1c] + T0);
                [T4 + T3 * 28 + 24] = b(bu[T4 + T3 * 28 + 24] + A3);
                [T4 + T3 * 28 + 25] = b(bu[T4 + T3 * 28 + 25] + T0);

                T3 = T3 + 1;
                V0 = T3 < hu[T2 + 2];
            800B6804	bne    v0, zero, Lb65fc [$800b65fc]
        }



        V0 = hu[T2 + 4];
        if( V0 != 0 )
        {
            T3 = 0;
            T1 = T5 + 6;
            A1 = T4 + 1d;

            Lb6824:	; 800B6824
                [A1 - 1a] = b(7);
                [A1 - 16] = b(24);
                [A1 - 19] = b(bu[T1 + 2]);
                [A1 - 18] = b(bu[T1 + 3]);
                [A1 - 17] = b(bu[T1 + 4]);
                V0 = hu[T1 + 6];
                800B685C	lw     v1, $0020(t2)
                800B6860	sll    v0, v0, $01
                800B6864	addu   v0, v0, v1
                800B6868	lbu    v0, $0000(v0)
                800B686C	nop
                800B6870	sb     v0, $ffef(a1)
                800B6874	lhu    v0, $0006(t1)
                800B6878	lw     v1, $0020(t2)
                800B687C	sll    v0, v0, $01
                800B6880	addu   v0, v0, v1
                800B6884	lbu    v0, $0001(v0)
                800B6888	nop
                800B688C	sb     v0, $fff0(a1)
                800B6890	lhu    v0, $0008(t1)
                800B6894	lw     v1, $0020(t2)
                800B6898	sll    v0, v0, $01
                800B689C	addu   v0, v0, v1
                800B68A0	lbu    v0, $0000(v0)
                800B68A4	nop
                800B68A8	sb     v0, $fff7(a1)
                800B68AC	lhu    v0, $0008(t1)
                800B68B0	lw     v1, $0020(t2)
                800B68B4	sll    v0, v0, $01
                800B68B8	addu   v0, v0, v1
                800B68BC	lbu    v0, $0001(v0)
                800B68C0	nop
                800B68C4	sb     v0, $fff8(a1)
                800B68C8	lhu    v0, $000a(t1)
                800B68CC	lw     v1, $0020(t2)
                800B68D0	sll    v0, v0, $01
                800B68D4	addu   v0, v0, v1
                800B68D8	lbu    v0, $0000(v0)
                800B68DC	nop
                800B68E0	sb     v0, $ffff(a1)
                800B68E4	lhu    v0, $000a(t1)
                800B68E8	lw     v1, $0020(t2)
                800B68EC	sll    v0, v0, $01
                800B68F0	addu   v0, v0, v1
                800B68F4	lbu    v0, $0001(v0)
                800B68F8	nop
                800B68FC	sb     v0, $0000(a1)
                800B6900	lbu    v0, $0000(t1)
                800B6904	lw     v1, $0018(a0)
                800B6908	sll    v0, v0, $02
                800B690C	addu   v0, v0, v1
                800B6910	lhu    v0, $0002(v0)
                800B6914	nop
                800B6918	sh     v0, $fff1(a1)
                800B691C	lbu    v0, $0000(t1)
                800B6920	lw     v1, $0018(a0)
                800B6924	sll    v0, v0, $02
                800B6928	addu   v0, v0, v1
                800B692C	lhu    v0, $0000(v0)
                800B6930	nop
                800B6934	andi   a3, v0, $ffdf
                800B6938	sh     a3, $fff9(a1)
                800B693C	lbu    v1, $000c(t1)
                800B6940	nop
                800B6944	andi   v0, v1, $0001
                if( V0 != 0 )
                {
                    800B694C	andi   v0, v1, $00e0
                    800B6950	lbu    v1, $ffea(a1)
                    800B6954	or     v0, a3, v0
                    800B6958	sh     v0, $fff9(a1)
                    800B695C	ori    v1, v1, $0002
                    800B6960	sb     v1, $ffea(a1)
                }

                800B6964	addiu  t4, t4, $0020
                800B6968	lbu    v0, $0000(t1)
                800B696C	addiu  t1, t1, $0014
                800B6970	addiu  t5, t5, $0014
                800B6974	addiu  t3, t3, $0001
                800B6978	sll    v0, v0, $02
                800B697C	addu   v0, v0, a2
                800B6980	lh     a3, $0000(v0)
                800B6984	lh     t0, $0002(v0)
                800B6988	lbu    v0, $ffef(a1)
                800B698C	lbu    v1, $fff0(a1)
                800B6990	addu   v0, v0, a3
                800B6994	sb     v0, $ffef(a1)
                800B6998	lbu    v0, $fff7(a1)
                800B699C	addu   v1, v1, t0
                800B69A0	sb     v1, $fff0(a1)
                800B69A4	lbu    v1, $fff8(a1)
                800B69A8	addu   v0, v0, a3
                800B69AC	sb     v0, $fff7(a1)
                800B69B0	lbu    v0, $ffff(a1)
                800B69B4	addu   v1, v1, t0
                800B69B8	sb     v1, $fff8(a1)
                800B69BC	lbu    v1, $0000(a1)
                800B69C0	addu   v0, v0, a3
                800B69C4	addu   v1, v1, t0
                800B69C8	sb     v0, $ffff(a1)
                800B69CC	sb     v1, $0000(a1)
                800B69D0	lhu    v0, $0004(t2)
                800B69E0	addiu  a1, a1, $0020
                800B69D8	sltu   v0, t3, v0
            800B69DC	bne    v0, zero, Lb6824 [$800b6824]
        }



        800B69E4	lhu    v0, $0006(t2)
        800B69E8	nop
        if( V0 != 0 )
        {
            800B69F0	addu   t3, zero, zero
            800B69F4	addiu  t1, t5, $001d
            800B69F8	addiu  a1, t4, $0031

            Lb69fc:	; 800B69FC
                800B69FC	addiu  v0, zero, $000c
                800B6A00	sb     v0, $ffd2(a1)
                800B6A04	addiu  v0, zero, $003c
                800B6A08	sb     v0, $ffd6(a1)
                800B6A0C	lhu    v0, $fff3(t1)
                800B6A10	nop
                800B6A14	sll    v0, v0, $02
                800B6A18	addu   v1, t6, v0
                800B6A1C	lbu    v0, $0000(v1)
                800B6A20	nop
                800B6A24	sb     v0, $ffd3(a1)
                800B6A28	lbu    v0, $0001(v1)
                800B6A2C	nop
                800B6A30	sb     v0, $ffd4(a1)
                800B6A34	lbu    v0, $0002(v1)
                800B6A38	nop
                800B6A3C	sb     v0, $ffd5(a1)
                800B6A40	lhu    v0, $fff5(t1)
                800B6A44	nop
                800B6A48	sll    v0, v0, $02
                800B6A4C	addu   v1, t6, v0
                800B6A50	lbu    v0, $0000(v1)
                800B6A54	nop
                800B6A58	sb     v0, $ffdf(a1)
                800B6A5C	lbu    v0, $0001(v1)
                800B6A60	nop
                800B6A64	sb     v0, $ffe0(a1)
                800B6A68	lbu    v0, $0002(v1)
                800B6A6C	nop
                800B6A70	sb     v0, $ffe1(a1)
                800B6A74	lhu    v0, $fff7(t1)
                800B6A78	nop
                800B6A7C	sll    v0, v0, $02
                800B6A80	addu   v1, t6, v0
                800B6A84	lbu    v0, $0000(v1)
                800B6A88	nop
                800B6A8C	sb     v0, $ffeb(a1)
                800B6A90	lbu    v0, $0001(v1)
                800B6A94	nop
                800B6A98	sb     v0, $ffec(a1)
                800B6A9C	lbu    v0, $0002(v1)
                800B6AA0	nop
                800B6AA4	sb     v0, $ffed(a1)
                800B6AA8	lhu    v0, $fff9(t1)
                800B6AAC	nop
                800B6AB0	sll    v0, v0, $02
                800B6AB4	addu   v1, t6, v0
                800B6AB8	lbu    v0, $0000(v1)
                800B6ABC	nop
                800B6AC0	sb     v0, $fff7(a1)
                800B6AC4	lbu    v0, $0001(v1)
                800B6AC8	nop
                800B6ACC	sb     v0, $fff8(a1)
                800B6AD0	lbu    v0, $0002(v1)
                800B6AD4	nop
                800B6AD8	sb     v0, $fff9(a1)
                800B6ADC	lhu    v0, $ffeb(t1)
                800B6AE0	lw     v1, $0020(t2)
                800B6AE4	sll    v0, v0, $01
                800B6AE8	addu   v0, v0, v1
                800B6AEC	lbu    v0, $0000(v0)
                800B6AF0	nop
                800B6AF4	sb     v0, $ffdb(a1)
                800B6AF8	lhu    v0, $ffeb(t1)
                800B6AFC	lw     v1, $0020(t2)
                800B6B00	sll    v0, v0, $01
                800B6B04	addu   v0, v0, v1
                800B6B08	lbu    v0, $0001(v0)
                800B6B0C	nop
                800B6B10	sb     v0, $ffdc(a1)
                800B6B14	lhu    v0, $ffed(t1)
                800B6B18	lw     v1, $0020(t2)
                800B6B1C	sll    v0, v0, $01
                800B6B20	addu   v0, v0, v1
                800B6B24	lbu    v0, $0000(v0)
                800B6B28	nop
                800B6B2C	sb     v0, $ffe7(a1)
                800B6B30	lhu    v0, $ffed(t1)
                800B6B34	lw     v1, $0020(t2)
                800B6B38	sll    v0, v0, $01
                800B6B3C	addu   v0, v0, v1
                800B6B40	lbu    v0, $0001(v0)
                800B6B44	nop
                800B6B48	sb     v0, $ffe8(a1)
                800B6B4C	lhu    v0, $ffef(t1)
                800B6B50	lw     v1, $0020(t2)
                800B6B54	sll    v0, v0, $01
                800B6B58	addu   v0, v0, v1
                800B6B5C	lbu    v0, $0000(v0)
                800B6B60	nop
                800B6B64	sb     v0, $fff3(a1)
                800B6B68	lhu    v0, $ffef(t1)
                800B6B6C	lw     v1, $0020(t2)
                800B6B70	sll    v0, v0, $01
                800B6B74	addu   v0, v0, v1
                800B6B78	lbu    v0, $0001(v0)
                800B6B7C	nop
                800B6B80	sb     v0, $fff4(a1)
                800B6B84	lhu    v0, $fff1(t1)
                800B6B88	lw     v1, $0020(t2)
                800B6B8C	sll    v0, v0, $01
                800B6B90	addu   v0, v0, v1
                800B6B94	lbu    v0, $0000(v0)
                800B6B98	nop
                800B6B9C	sb     v0, $ffff(a1)
                800B6BA0	lhu    v0, $fff1(t1)
                800B6BA4	lw     v1, $0020(t2)
                800B6BA8	sll    v0, v0, $01
                800B6BAC	addu   v0, v0, v1
                800B6BB0	lbu    v0, $0001(v0)
                800B6BB8	sb     v0, $0000(a1)
                800B6BBC	lbu    v0, $0000(t1)
                800B6BC0	lw     v1, $0018(a0)
                800B6BC4	sll    v0, v0, $02
                800B6BC8	addu   v0, v0, v1
                800B6BCC	lhu    v0, $0002(v0)
                800B6BD0	nop
                800B6BD4	sh     v0, $ffdd(a1)
                800B6BD8	lbu    v0, $0000(t1)
                800B6BDC	lw     v1, $0018(a0)
                800B6BE0	sll    v0, v0, $02
                800B6BE4	addu   v0, v0, v1
                800B6BE8	lhu    v0, $0000(v0)
                800B6BEC	nop
                800B6BF0	andi   a3, v0, $ffdf
                800B6BF4	sh     a3, $ffe9(a1)
                800B6BF8	lbu    v1, $ffff(t1)
                800B6BFC	nop
                800B6C00	andi   v0, v1, $0001
                if( V0 != 0 )
                {
                    800B6C08	andi   v0, v1, $00e0
                    800B6C0C	lbu    v1, $ffd6(a1)
                    800B6C10	or     v0, a3, v0
                    800B6C14	sh     v0, $ffe9(a1)
                    800B6C18	ori    v1, v1, $0002
                    800B6C1C	sb     v1, $ffd6(a1)
                }

                800B6C20	addiu  t4, t4, $0034
                800B6C24	lbu    v0, $0000(t1)
                800B6C28	addiu  t1, t1, $0020
                800B6C2C	addiu  t5, t5, $0020
                800B6C30	addiu  t3, t3, $0001
                800B6C34	sll    v0, v0, $02
                800B6C38	addu   v0, v0, a2
                800B6C3C	lh     a3, $0000(v0)
                800B6C40	lh     t0, $0002(v0)
                800B6C44	lbu    v0, $ffdb(a1)
                800B6C48	lbu    v1, $ffdc(a1)
                800B6C4C	addu   v0, v0, a3
                800B6C50	sb     v0, $ffdb(a1)
                800B6C54	lbu    v0, $ffe7(a1)
                800B6C58	addu   v1, v1, t0
                800B6C5C	sb     v1, $ffdc(a1)
                800B6C60	lbu    v1, $ffe8(a1)
                800B6C64	addu   v0, v0, a3
                800B6C68	sb     v0, $ffe7(a1)
                800B6C6C	lbu    v0, $fff3(a1)
                800B6C70	addu   v1, v1, t0
                800B6C74	sb     v1, $ffe8(a1)
                800B6C78	lbu    v1, $fff4(a1)
                800B6C7C	addu   v0, v0, a3
                800B6C80	sb     v0, $fff3(a1)
                800B6C84	lbu    v0, $ffff(a1)
                800B6C88	addu   v1, v1, t0
                800B6C8C	sb     v1, $fff4(a1)
                800B6C90	lbu    v1, $0000(a1)
                800B6C94	addu   v0, v0, a3
                800B6C98	addu   v1, v1, t0
                800B6C9C	sb     v0, $ffff(a1)
                800B6CA0	sb     v1, $0000(a1)
                800B6CA4	lhu    v0, $0006(t2)
                800B6CA8	nop
                800B6CB4	addiu  a1, a1, $0034
                800B6CAC	sltu   v0, t3, v0
            800B6CB0	bne    v0, zero, Lb69fc [$800b69fc]
        }



        800B6CB8	lhu    v0, $0008(t2)
        800B6CBC	nop
        if( V0 != 0 )
        {
            800B6CC4	addu   t3, zero, zero
            800B6CC8	addiu  t1, t5, $0016
            800B6CCC	addiu  a1, t4, $0025

            Lb6cd0:	; 800B6CD0
                800B6CD0	addiu  v0, zero, $0009
                800B6CD4	sb     v0, $ffde(a1)
                800B6CD8	addiu  v0, zero, $0034
                800B6CDC	sb     v0, $ffe2(a1)
                800B6CE0	lhu    v0, $fffa(t1)
                800B6CE4	nop
                800B6CE8	sll    v0, v0, $02
                800B6CEC	addu   v1, t6, v0
                800B6CF0	lbu    v0, $0000(v1)
                800B6CF4	nop
                800B6CF8	sb     v0, $ffdf(a1)
                800B6CFC	lbu    v0, $0001(v1)
                800B6D00	nop
                800B6D04	sb     v0, $ffe0(a1)
                800B6D08	lbu    v0, $0002(v1)
                800B6D0C	nop
                800B6D10	sb     v0, $ffe1(a1)
                800B6D14	lhu    v0, $fffc(t1)
                800B6D18	nop
                800B6D1C	sll    v0, v0, $02
                800B6D20	addu   v1, t6, v0
                800B6D24	lbu    v0, $0000(v1)
                800B6D28	nop
                800B6D2C	sb     v0, $ffeb(a1)
                800B6D30	lbu    v0, $0001(v1)
                800B6D34	nop
                800B6D38	sb     v0, $ffec(a1)
                800B6D3C	lbu    v0, $0002(v1)
                800B6D40	nop
                800B6D44	sb     v0, $ffed(a1)
                800B6D48	lhu    v0, $fffe(t1)
                800B6D4C	nop
                800B6D50	sll    v0, v0, $02
                800B6D54	addu   v1, t6, v0
                800B6D58	lbu    v0, $0000(v1)
                800B6D5C	nop
                800B6D60	sb     v0, $fff7(a1)
                800B6D64	lbu    v0, $0001(v1)
                800B6D68	nop
                800B6D6C	sb     v0, $fff8(a1)
                800B6D70	lbu    v0, $0002(v1)
                800B6D74	nop
                800B6D78	sb     v0, $fff9(a1)
                800B6D7C	lhu    v0, $fff0(t1)
                800B6D80	lw     v1, $0020(t2)
                800B6D84	sll    v0, v0, $01
                800B6D88	addu   v0, v0, v1
                800B6D8C	lbu    v0, $0000(v0)
                800B6D90	nop
                800B6D94	sb     v0, $ffe7(a1)
                800B6D98	lhu    v0, $fff0(t1)
                800B6D9C	lw     v1, $0020(t2)
                800B6DA0	sll    v0, v0, $01
                800B6DA4	addu   v0, v0, v1
                800B6DA8	lbu    v0, $0001(v0)
                800B6DAC	nop
                800B6DB0	sb     v0, $ffe8(a1)
                800B6DB4	lhu    v0, $fff2(t1)
                800B6DB8	lw     v1, $0020(t2)
                800B6DBC	sll    v0, v0, $01
                800B6DC0	addu   v0, v0, v1
                800B6DC4	lbu    v0, $0000(v0)
                800B6DC8	nop
                800B6DCC	sb     v0, $fff3(a1)
                800B6DD0	lhu    v0, $fff2(t1)
                800B6DD4	lw     v1, $0020(t2)
                800B6DD8	sll    v0, v0, $01
                800B6DDC	addu   v0, v0, v1
                800B6DE0	lbu    v0, $0001(v0)
                800B6DE4	nop
                800B6DE8	sb     v0, $fff4(a1)
                800B6DEC	lhu    v0, $fff4(t1)
                800B6DF0	lw     v1, $0020(t2)
                800B6DF4	sll    v0, v0, $01
                800B6DF8	addu   v0, v0, v1
                800B6DFC	lbu    v0, $0000(v0)
                800B6E00	nop
                800B6E04	sb     v0, $ffff(a1)
                800B6E08	lhu    v0, $fff4(t1)
                800B6E0C	lw     v1, $0020(t2)
                800B6E10	sll    v0, v0, $01
                800B6E14	addu   v0, v0, v1
                800B6E18	lbu    v0, $0001(v0)
                800B6E1C	nop
                800B6E20	sb     v0, $0000(a1)
                800B6E24	lbu    v0, $0000(t1)
                800B6E28	lw     v1, $0018(a0)
                800B6E2C	sll    v0, v0, $02
                800B6E30	addu   v0, v0, v1
                800B6E34	lhu    v0, $0002(v0)
                800B6E38	nop
                800B6E3C	sh     v0, $ffe9(a1)
                800B6E40	lbu    v0, $0000(t1)
                800B6E44	lw     v1, $0018(a0)
                800B6E48	sll    v0, v0, $02
                800B6E4C	addu   v0, v0, v1
                800B6E50	lhu    v0, $0000(v0)
                800B6E54	nop
                800B6E58	andi   a3, v0, $ffdf
                800B6E5C	sh     a3, $fff5(a1)
                800B6E60	lbu    v1, $fff9(t1)
                800B6E64	nop
                800B6E68	andi   v0, v1, $0001
                if( V0 != 0 )
                {
                    800B6E70	andi   v0, v1, $00e0
                    800B6E74	lbu    v1, $ffe2(a1)
                    800B6E78	or     v0, a3, v0
                    800B6E7C	sh     v0, $fff5(a1)
                    800B6E80	ori    v1, v1, $0002
                    800B6E84	sb     v1, $ffe2(a1)
                }

                800B6E88	addiu  t4, t4, $0028
                800B6E8C	lbu    v0, $0000(t1)
                800B6E90	addiu  t1, t1, $0018
                800B6E94	addiu  t5, t5, $0018
                800B6E98	addiu  t3, t3, $0001
                800B6E9C	sll    v0, v0, $02
                800B6EA0	addu   v0, v0, a2
                800B6EA4	lh     a3, $0000(v0)
                800B6EA8	lh     t0, $0002(v0)
                800B6EAC	lbu    v0, $ffe7(a1)
                800B6EB0	lbu    v1, $ffe8(a1)
                800B6EB4	addu   v0, v0, a3
                800B6EB8	sb     v0, $ffe7(a1)
                800B6EBC	lbu    v0, $fff3(a1)
                800B6EC0	addu   v1, v1, t0
                800B6EC4	sb     v1, $ffe8(a1)
                800B6EC8	lbu    v1, $fff4(a1)
                800B6ECC	addu   v0, v0, a3
                800B6ED0	sb     v0, $fff3(a1)
                800B6ED4	lbu    v0, $ffff(a1)
                800B6ED8	addu   v1, v1, t0
                800B6EDC	sb     v1, $fff4(a1)
                800B6EE0	lbu    v1, $0000(a1)
                800B6EE4	addu   v0, v0, a3
                800B6EE8	addu   v1, v1, t0
                800B6EEC	sb     v0, $ffff(a1)
                800B6EF0	sb     v1, $0000(a1)
                800B6EF4	lhu    v0, $0008(t2)
                800B6F04	addiu  a1, a1, $0028
                800B6EFC	sltu   v0, t3, v0
            800B6F00	bne    v0, zero, Lb6cd0 [$800b6cd0]
        }



        800B6F08	lhu    v0, $000a(t2)
        800B6F0C	nop
        if( V0 != 0 )
        {
            800B6F14	addu   t3, zero, zero
            800B6F18	addiu  a3, t5, $000e
            800B6F1C	addiu  a1, t4, $001e

            loopb6f20:	; 800B6F20
                800B6F20	sb     s1, $ffe5(a1)
                800B6F24	sb     s2, $ffe9(a1)
                800B6F28	lhu    v0, $fffa(a3)
                800B6F2C	nop
                800B6F30	sll    v0, v0, $02
                800B6F34	addu   v1, t6, v0
                800B6F38	lbu    v0, $0000(v1)
                800B6F3C	nop
                800B6F40	sb     v0, $ffe6(a1)
                800B6F44	lbu    v0, $0001(v1)
                800B6F48	nop
                800B6F4C	sb     v0, $ffe7(a1)
                800B6F50	lbu    v0, $0002(v1)
                800B6F54	nop
                800B6F58	sb     v0, $ffe8(a1)
                800B6F5C	lhu    v0, $fffc(a3)
                800B6F60	nop
                800B6F64	sll    v0, v0, $02
                800B6F68	addu   v1, t6, v0
                800B6F6C	lbu    v0, $0000(v1)
                800B6F70	nop
                800B6F74	sb     v0, $ffee(a1)
                800B6F78	lbu    v0, $0001(v1)
                800B6F7C	nop
                800B6F80	sb     v0, $ffef(a1)
                800B6F84	lbu    v0, $0002(v1)
                800B6F88	nop
                800B6F8C	sb     v0, $fff0(a1)
                800B6F90	lhu    v0, $fffe(a3)
                800B6F94	nop
                800B6F98	sll    v0, v0, $02
                800B6F9C	addu   v1, t6, v0
                800B6FA0	lbu    v0, $0000(v1)
                800B6FA4	nop
                800B6FA8	sb     v0, $fff6(a1)
                800B6FAC	lbu    v0, $0001(v1)
                800B6FB0	nop
                800B6FB4	sb     v0, $fff7(a1)
                800B6FB8	lbu    v0, $0002(v1)
                800B6FBC	nop
                800B6FC0	sb     v0, $fff8(a1)
                800B6FC4	lhu    v0, $0000(a3)
                800B6FC8	addiu  t4, t4, $0024
                800B6FCC	sll    v0, v0, $02
                800B6FD0	addu   v1, t6, v0
                800B6FD4	lbu    v0, $0000(v1)
                800B6FD8	addiu  t5, t5, $0018
                800B6FDC	sb     v0, $fffe(a1)
                800B6FE0	lbu    v0, $0001(v1)
                800B6FE4	addiu  t3, t3, $0001
                800B6FE8	sb     v0, $ffff(a1)
                800B6FEC	lbu    v0, $0002(v1)
                800B6FF0	addiu  a3, a3, $0018
                800B6FF4	sb     v0, $0000(a1)
                800B6FF8	lhu    v0, $000a(t2)
                800B7008	addiu  a1, a1, $0024
                800B7000	sltu   v0, t3, v0
            800B7004	bne    v0, zero, loopb6f20 [$800b6f20]
        }



        800B700C	lhu    v0, $000c(t2)
        800B7010	nop
        if( V0 != 0 )
        {
            800B7018	addu   t3, zero, zero
            800B701C	addiu  t1, zero, $0006
            800B7020	addiu  t0, zero, $0030
            800B7024	addiu  a3, t5, $000c
            800B7028	addiu  a1, t4, $0016

            loopb702c:	; 800B702C
                800B702C	sb     t1, $ffed(a1)
                800B7030	sb     t0, $fff1(a1)
                800B7034	lhu    v0, $fffc(a3)
                800B7038	nop
                800B703C	sll    v0, v0, $02
                800B7040	addu   v1, t6, v0
                800B7044	lbu    v0, $0000(v1)
                800B7048	nop
                800B704C	sb     v0, $ffee(a1)
                800B7050	lbu    v0, $0001(v1)
                800B7054	nop
                800B7058	sb     v0, $ffef(a1)
                800B705C	lbu    v0, $0002(v1)
                800B7060	nop
                800B7064	sb     v0, $fff0(a1)
                800B7068	lhu    v0, $fffe(a3)
                800B706C	nop
                800B7070	sll    v0, v0, $02
                800B7074	addu   v1, t6, v0
                800B7078	lbu    v0, $0000(v1)
                800B707C	nop
                800B7080	sb     v0, $fff6(a1)
                800B7084	lbu    v0, $0001(v1)
                800B7088	nop
                800B708C	sb     v0, $fff7(a1)
                800B7090	lbu    v0, $0002(v1)
                800B7094	nop
                800B7098	sb     v0, $fff8(a1)
                800B709C	lhu    v0, $0000(a3)
                800B70A0	addiu  t4, t4, $001c
                800B70A4	sll    v0, v0, $02
                800B70A8	addu   v1, t6, v0
                800B70AC	lbu    v0, $0000(v1)
                800B70B0	addiu  t5, t5, $0014
                800B70B4	sb     v0, $fffe(a1)
                800B70B8	lbu    v0, $0001(v1)
                800B70BC	addiu  t3, t3, $0001
                800B70C0	sb     v0, $ffff(a1)
                800B70C4	lbu    v0, $0002(v1)
                800B70C8	addiu  a3, a3, $0014
                800B70CC	sb     v0, $0000(a1)
                800B70D0	lhu    v0, $000c(t2)
                800B70D4	nop
                800B70E0	addiu  a1, a1, $001c
                800B70D8	sltu   v0, t3, v0
            800B70DC	bne    v0, zero, loopb702c [$800b702c]
        }



        800B70E4	lhu    v0, $000e(t2)
        800B70E8	nop
        if( V0 != 0 )
        {
            800B70F0	addu   t3, zero, zero
            800B70F4	addiu  t0, zero, $0005
            800B70F8	addiu  a3, zero, $0028
            800B70FC	addiu  a1, t5, $000a
            800B7100	addiu  v1, t4, $0006

            loopb7104:	; 800B7104
                800B7104	addiu  t4, t4, $0018
                800B7108	sb     t0, $fffd(v1)
                800B710C	sb     a3, $0001(v1)
                800B7110	lbu    v0, $fffe(a1)
                800B7114	addiu  t5, t5, $0010
                800B7118	sb     v0, $fffe(v1)
                800B711C	lbu    v0, $ffff(a1)
                800B7120	addiu  t3, t3, $0001
                800B7124	sb     v0, $ffff(v1)
                800B7128	lbu    v0, $0000(a1)
                800B712C	addiu  a1, a1, $0010
                800B7130	sb     v0, $0000(v1)
                800B7134	lhu    v0, $000e(t2)
                800B7144	addiu  v1, v1, $0018
                800B713C	sltu   v0, t3, v0
            800B7140	bne    v0, zero, loopb7104 [$800b7104]
        }



        800B7148	lhu    v0, $0010(t2)
        800B714C	nop
        if( V0 != 0 )
        {
            800B7154	addu   t3, zero, zero
            800B7158	addiu  t0, zero, $0004
            800B715C	addiu  a3, zero, $0020
            800B7160	addiu  a1, t5, $000a
            800B7164	addiu  v1, t4, $0006

            loopb7168:	; 800B7168
                800B7168	sb     t0, $fffd(v1)
                800B716C	sb     a3, $0001(v1)
                800B7170	lbu    v0, $fffe(a1)
                800B7174	addiu  t4, t4, $0014
                800B7178	sb     v0, $fffe(v1)
                800B717C	lbu    v0, $ffff(a1)
                800B7180	addiu  t3, t3, $0001
                800B7184	sb     v0, $ffff(v1)
                800B7188	lbu    v0, $0000(a1)
                800B718C	addiu  a1, a1, $000c
                800B7190	sb     v0, $0000(v1)
                800B7194	lhu    v0, $0010(t2)
                800B71A4	addiu  v1, v1, $0014
                800B719C	sltu   v0, t3, v0
            800B71A0	bne    v0, zero, loopb7168 [$800b7168]
        }

        800B71A8	addiu  t8, t8, $0001
        800B71AC	sltiu  v0, t8, $0002
    800B71B0	bne    v0, zero, Lb65e4 [$800b65e4]

    T7 = T7 + 1;
    T9 = T9 + c;
    V0 = T7 < bu[S0 + 3];
800B71C4	bne    v0, zero, Lb65bc [$800b65bc]
////////////////////////////////