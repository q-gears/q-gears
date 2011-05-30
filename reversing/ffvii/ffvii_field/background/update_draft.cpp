////////////////////////////////
// funca364c
A3 = A0;
T5 = 124dc;
T0 = 00ffffff;
T2 = ff000000;
V0 = w[8009d848];
V0 = w[V0];
T7 = V0 + 10;
T1 = V0 + 14;


La3698:	; 800A3698
V1 = h[T7];
800A369C	ori    v0, zero, $7fff
800A36A0	bne    v1, v0, La36b0 [$800a36b0]
800A36A4	ori    v0, zero, $7ffe
800A36A8	j      La37d4 [$800a37d4]
800A36AC	addiu  t7, t7, $0002

La36b0:	; 800A36B0
800A36B0	bne    v1, v0, La371c [$800a371c]
800A36B4	nop
800A36B8	lh     v1, $fffe(t1)
800A36BC	nop
800A36C0	sll    v0, v1, $01
800A36C4	addu   v0, v0, v1
800A36C8	sll    v0, v0, $02
800A36CC	addu   v0, v0, a3
800A36D0	addu   v0, v0, t5
800A36D4	lw     a0, $0000(v0)
800A36D8	lw     v1, $3ffc(a3)
800A36DC	and    a0, a0, t2
800A36E0	and    v1, v1, t0
800A36E4	or     a0, a0, v1
800A36E8	sw     a0, $0000(v0)
800A36EC	lw     a0, $3ffc(a3)
800A36F0	lh     v1, $fffe(t1)
800A36F4	and    a0, a0, t2
800A36F8	sll    v0, v1, $01
800A36FC	addu   v0, v0, v1
800A3700	sll    v0, v0, $02
800A3704	addu   v0, v0, t5
800A3708	addu   v0, a3, v0
800A370C	and    v0, v0, t0
800A3710	or     a0, a0, v0
800A3714	j      La37c8 [$800a37c8]
800A3718	sw     a0, $3ffc(a3)

La371c:	; 800A371C
800A371C	lui    a0, $8007
800A3720	lh     a0, $1a4a(a0)
800A3724	nop
800A3728	addiu  v0, a0, $ff00 (=-$100)
800A372C	slt    v0, v0, v1
800A3730	beq    v0, zero, La37c8 [$800a37c8]
800A3734	slt    v0, v1, a0
800A3738	beq    v0, zero, La37c8 [$800a37c8]
800A373C	nop

// 1st layer draft clip by x screen
T3 = hu[T1 - 2];
T4 = h[T1 + 0];
if (T4 != 0)
{
    loopa3754:	; 800A3754
        V1 = h[A3 + T3 * 10 + 4914 + 8]; // dest x

        if (((h[80071a48] - 150) < V1) && (V1 < h[80071a48]))
        {
            [A3 + 4914 + T3 * 10] = w((w[A3 + 4914 + T3 * 10] & ff000000) | (w[A3 + 3ffc] & 00ffffff));
            [A3 + 3ffc] = w(((w[A3 + 3ffc]) & ff000000) | ((A3 + 4914 + T3 * 10) & 00ffffff));
        }

        T3 = T3 + 1;
        T4 = T4 - 1;
    800A37C0	bne    t4, zero, loopa3754 [$800a3754]
}

La37c8:	; 800A37C8
800A37C8	addiu  t1, t1, $0006
800A37CC	j      La3698 [$800a3698]
800A37D0	addiu  t7, t7, $0006

La37d4:	; 800A37D4
T0 = 00ffffff;
T5 = ff000000;
T8 = h[8011448c];

La37e8:	; 800A37E8
800A37E8	lh     v1, $0000(t7)
800A37EC	ori    v0, zero, $7fff
800A37F0	bne    v1, v0, La3800 [$800a3800]
800A37F4	nop
800A37F8	j      La396c [$800a396c]
800A37FC	addiu  t7, t7, $0002

La3800:	; 800A3800
800A3800	lui    a0, $8007
800A3804	lh     a0, $1a4a(a0)
800A3808	nop
800A380C	addiu  v0, a0, $ff00 (=-$100)
800A3810	slt    v0, v0, v1
800A3814	beq    v0, zero, La3964 [$800a3964]
800A3818	slt    v0, v1, a0
800A381C	beq    v0, zero, La3964 [$800a3964]
800A3820	nop
800A3824	lh     v0, $0004(t7)
800A3828	lh    t3, $0002(t7)
800A382C	beq    v0, zero, La3964 [$800a3964]
800A3830	addu   t4, v0, zero
800A3834	lui    t6, $0001
800A3838	ori    t6, t6, $24dc

loopa383c:	; 800A383C
    T1 = T3;
    A1 = 
    V1 = h[A1 + 4914 + 8]; // dest x

    if ((h[80071a48] - 150 < V1) && (V1 < h[80071a48]) && (((bu[A3 + T1 * 2 + 10d54] & 3f) == 0) || ((bu[8009ace6 + V0] & bu[A3 + T1 * 2 + 10d55]) != 0)))
    {
        V1 = (bu[A3 + T1 * 10 + 4914 + 5] << 8) + (bu[A3 + T1 * 10 + 4914 + 4]);
        A2 = V1 * 4;
        A2 = A2 + A3;
        V0 = w[A3 + T1 * 10 + 4914];

        V1 = w[A2];
        V1 = V1 & 00ffffff;

        [A3 + T1 * 10 + 4914] = w((V0 & ff000000) | V1);

        V0 = A3 + T1 * 10 + 4914;
        A1 = w[A2];
        V0 = V0 & 00ffffff;
        A1 = (A1 & ff000000) | V0;
        V0 = T1 - T8;

        800A3908	sll    v1, v0, $01
        800A390C	addu   v1, v1, v0
        800A3910	sll    v1, v1, $02
        800A3914	addu   a0, v1, a3
        800A3918	addu   a0, a0, t6
        800A391C	sw     a1, $0000(a2)
        A1 = A1 & 00ffffff;
        800A3924	addu   v1, v1, t6
        800A3928	lw     v0, $0000(a0)
        800A392C	addu   v1, a3, v1
        V0 = V0 & ff000000;
        800A3934	or     v0, v0, a1
        800A3938	sw     v0, $0000(a0)
        800A393C	lw     v0, $0000(a2)
        V1 = V1 & 00ffffff;
        V0 = V0 & ff000000;
        800A3948	or     v0, v0, v1
        800A394C	sw     v0, $0000(a2)
    }

    T3 = T3 + 1;
    T4 = T4 - 1;
800A395C	bne    t4, zero, loopa383c [$800a383c]


La3964:	; 800A3964
800A3964	j      La37e8 [$800a37e8]
800A3968	addiu  t7, t7, $0006

La396c:	; 800A396C
800A396C	lui    a1, $00ff
800A3970	ori    a1, a1, $ffff
800A3974	lui    v0, $800a
800A3978	addiu  v0, v0, $aca4 (=-$535c)
800A397C	addu   t1, v0, zero
800A3980	lui    t0, $00ff
800A3984	ori    t0, t0, $ffff
800A3988	lui    t6, $ff00
800A398C	addiu  v0, a3, $4214
800A3990	and    s2, v0, t0
800A3994	lui    s0, $0001
800A3998	ori    s0, s0, $24dc
800A399C	addiu  t5, t7, $0004
800A39A0	lui    a2, $ff00
800A39A4	lhu    v0, $0000(t1)
800A39A8	lw     v1, $4294(a3)
800A39AC	lui    t2, $8007
800A39B0	lw     t2, $16c4(t2)
800A39B4	lui    s1, $8011
800A39B8	lh     s1, $44c8(s1)
800A39BC	sll    v0, v0, $02
800A39C0	addu   v0, v0, a3
800A39C4	lw     v0, $0000(v0)
800A39C8	and    v1, v1, a2
800A39CC	and    v0, v0, a1
800A39D0	or     v1, v1, v0
800A39D4	sw     v1, $4294(a3)
800A39D8	lhu    a0, $0000(t1)
800A39DC	addiu  v0, a3, $4294
800A39E0	sll    a0, a0, $02
800A39E4	addu   a0, a0, a3
800A39E8	lw     v1, $0000(a0)
800A39EC	and    v0, v0, a1
800A39F0	and    v1, v1, a2
800A39F4	or     v1, v1, v0
800A39F8	sw     v1, $0000(a0)

La39fc:	; 800A39FC
800A39FC	lh     v1, $0000(t7)
800A3A00	ori    v0, zero, $7fff
800A3A04	bne    v1, v0, La3a58 [$800a3a58]
800A3A08	ori    v0, zero, $7ffe
800A3A0C	lhu    v0, $0000(t1)
800A3A10	lw     v1, $4214(a3)
800A3A14	sll    v0, v0, $02
800A3A18	addu   v0, v0, a3
800A3A1C	lw     v0, $0000(v0)
800A3A20	and    v1, v1, t6
800A3A24	and    v0, v0, t0
800A3A28	or     v1, v1, v0
800A3A2C	sw     v1, $4214(a3)
800A3A30	lhu    v1, $0000(t1)
800A3A34	nop
800A3A38	sll    v1, v1, $02
800A3A3C	addu   v1, v1, a3
800A3A40	lw     v0, $0000(v1)
800A3A44	addiu  t7, t7, $0002
800A3A48	and    v0, v0, t6
800A3A4C	or     v0, v0, s2
800A3A50	j      La3cd8 [$800a3cd8]
800A3A54	sw     v0, $0000(v1)

La3a58:	; 800A3A58
800A3A58	bne    v1, v0, La3aec [$800a3aec]
800A3A5C	nop
800A3A60	lh     v0, $fffe(t5)
800A3A64	lui    a2, $8011
800A3A68	lh     a2, $44d0(a2)
800A3A6C	nop
800A3A70	addu   v0, v0, a2
800A3A74	sll    a0, v0, $01
800A3A78	addu   a0, a0, v0
800A3A7C	sll    a0, a0, $02
800A3A80	addu   a0, a0, a3
800A3A84	addu   a0, a0, s0
800A3A88	lhu    v0, $0000(t1)
800A3A8C	lw     v1, $0000(a0)
800A3A90	sll    v0, v0, $02
800A3A94	addu   v0, v0, a3
800A3A98	lw     v0, $0000(v0)
800A3A9C	and    v1, v1, t6
800A3AA0	and    v0, v0, t0
800A3AA4	or     v1, v1, v0
800A3AA8	sw     v1, $0000(a0)
800A3AAC	lhu    a1, $0000(t1)
800A3AB0	lh     v1, $fffe(t5)
800A3AB4	sll    a1, a1, $02
800A3AB8	addu   a1, a1, a3
800A3ABC	addu   v1, v1, a2
800A3AC0	sll    v0, v1, $01
800A3AC4	addu   v0, v0, v1
800A3AC8	sll    v0, v0, $02

La3acc:	; 800A3ACC
800A3ACC	addu   v0, v0, s0
800A3AD0	addu   v0, a3, v0
800A3AD4	lw     a0, $0000(a1)
800A3AD8	and    v0, v0, t0
800A3ADC	and    a0, a0, t6
800A3AE0	or     a0, a0, v0
800A3AE4	j      La3ccc [$800a3ccc]
800A3AE8	sw     a0, $0000(a1)

La3aec:	; 800A3AEC
800A3AEC	lh     v0, $0000(t5)
800A3AF0	lhu    t3, $fffe(t5)
800A3AF4	beq    v0, zero, La3ccc [$800a3ccc]
800A3AF8	addu   t4, v0, zero
800A3AFC	ori    t8, zero, $e554

La3b00:	; 800A3B00
800A3B00	sll    v0, t3, $10
800A3B04	sra    v0, v0, $10
800A3B08	sll    v1, v0, $02
800A3B0C	addu   v1, v1, v0
800A3B10	sll    v1, v1, $02
800A3B14	addu   a2, a3, v1
800A3B18	lui    at, $0001
800A3B1C	addu   at, a2, at
800A3B20	lh     a0, $e55c(at)
800A3B24	lui    v1, $8007
800A3B28	lh     v1, $1a4c(v1)
800A3B2C	nop
800A3B30	addiu  v0, v1, $fea0 (=-$160)
800A3B34	slt    v0, v0, a0
800A3B38	beq    v0, zero, La3b4c [$800a3b4c]
800A3B3C	addu   a1, a0, zero
800A3B40	slt    v0, a0, v1
800A3B44	bne    v0, zero, La3b84 [$800a3b84]
800A3B48	sll    v0, t3, $10

La3b4c:	; 800A3B4C
800A3B4C	addiu  v0, v1, $ff60 (=-$a0)
800A3B50	slt    v0, a0, v0
800A3B54	beq    v0, zero, La3b68 [$800a3b68]
800A3B58	nop
800A3B5C	lhu    v0, $0018(t2)
800A3B60	j      La3b74 [$800a3b74]
800A3B64	addu   v0, a1, v0

La3b68:	; 800A3B68
800A3B68	lhu    v0, $0018(t2)
800A3B6C	nop
800A3B70	subu   v0, a1, v0

La3b74:	; 800A3B74
800A3B74	lui    at, $0001
800A3B78	addu   at, a2, at
800A3B7C	sh     v0, $e55c(at)
800A3B80	sll    v0, t3, $10

La3b84:	; 800A3B84
800A3B84	sra    v0, v0, $10
800A3B88	sll    v1, v0, $02
800A3B8C	addu   v1, v1, v0
800A3B90	sll    v1, v1, $02
800A3B94	addu   a2, a3, v1
800A3B98	lui    at, $0001
800A3B9C	addu   at, a2, at
800A3BA0	lh     a0, $e55e(at)
800A3BA4	lui    v1, $8007
800A3BA8	lh     v1, $1a4e(v1)
800A3BAC	nop
800A3BB0	addiu  v0, v1, $ff00 (=-$100)
800A3BB4	slt    v0, v0, a0
800A3BB8	beq    v0, zero, La3bcc [$800a3bcc]
800A3BBC	addu   a1, a0, zero
800A3BC0	slt    v0, a0, v1
800A3BC4	bne    v0, zero, La3c04 [$800a3c04]
800A3BC8	sll    v0, t3, $10

La3bcc:	; 800A3BCC
800A3BCC	addiu  v0, v1, $ff90 (=-$70)
800A3BD0	slt    v0, a0, v0
800A3BD4	beq    v0, zero, La3be8 [$800a3be8]
800A3BD8	nop
800A3BDC	lhu    v0, $001a(t2)
800A3BE0	j      La3bf4 [$800a3bf4]
800A3BE4	addu   v0, a1, v0

La3be8:	; 800A3BE8
800A3BE8	lhu    v0, $001a(t2)
800A3BEC	nop
800A3BF0	subu   v0, a1, v0

La3bf4:	; 800A3BF4
800A3BF4	lui    at, $0001
800A3BF8	addu   at, a2, at
800A3BFC	sh     v0, $e55e(at)
800A3C00	sll    v0, t3, $10

La3c04:	; 800A3C04
800A3C04	sra    a1, v0, $10
800A3C08	addu   v0, a1, s1
800A3C0C	sll    v0, v0, $01
800A3C10	addu   v1, a3, v0
800A3C14	lui    at, $0001
800A3C18	addu   at, v1, at
800A3C1C	lbu    v0, $0d54(at)
800A3C20	nop
800A3C24	andi   v0, v0, $003f
800A3C28	beq    v0, zero, La3c5c [$800a3c5c]
800A3C2C	sll    a0, a1, $02
800A3C30	lui    at, $0001
800A3C34	addu   at, v1, at
800A3C38	lbu    v1, $0d55(at)
800A3C3C	lui    at, $800a
800A3C40	addiu  at, at, $ace6 (=-$531a)
800A3C44	addu   at, at, v0
800A3C48	lbu    v0, $0000(at)
800A3C4C	nop
800A3C50	and    v0, v0, v1
800A3C54	beq    v0, zero, La3cbc [$800a3cbc]
800A3C58	addiu  v0, t4, $ffff (=-$1)

La3c5c:	; 800A3C5C
800A3C5C	addu   a0, a0, a1
800A3C60	sll    a0, a0, $02
800A3C64	addu   a1, a0, a3
800A3C68	addu   a1, a1, t8
800A3C6C	addu   a0, a0, t8
800A3C70	lhu    v0, $0000(t1)
800A3C74	lw     v1, $0000(a1)
800A3C78	sll    v0, v0, $02
800A3C7C	addu   v0, v0, a3
800A3C80	lw     v0, $0000(v0)
800A3C84	and    v1, v1, t6
800A3C88	and    v0, v0, t0
800A3C8C	or     v1, v1, v0
800A3C90	sw     v1, $0000(a1)
800A3C94	lhu    v1, $0000(t1)
800A3C98	addu   a0, a3, a0
800A3C9C	sll    v1, v1, $02
800A3CA0	addu   v1, v1, a3
800A3CA4	lw     v0, $0000(v1)
800A3CA8	and    a0, a0, t0
800A3CAC	and    v0, v0, t6
800A3CB0	or     v0, v0, a0
800A3CB4	sw     v0, $0000(v1)
800A3CB8	addiu  v0, t4, $ffff (=-$1)

La3cbc:	; 800A3CBC
800A3CBC	addu   t4, v0, zero
800A3CC0	sll    v0, v0, $10
800A3CC4	bne    v0, zero, La3b00 [$800a3b00]
800A3CC8	addiu  t3, t3, $0001

La3ccc:	; 800A3CCC
800A3CCC	addiu  t5, t5, $0006
800A3CD0	j      La39fc [$800a39fc]
800A3CD4	addiu  t7, t7, $0006

La3cd8:	; 800A3CD8
800A3CD8	lui    a1, $00ff
800A3CDC	ori    a1, a1, $ffff
800A3CE0	lui    v0, $800a
800A3CE4	addiu  v0, v0, $aca2 (=-$535e)
800A3CE8	addu   t2, v0, zero
800A3CEC	lui    t1, $00ff
800A3CF0	ori    t1, t1, $ffff
800A3CF4	lui    t8, $ff00
800A3CF8	addiu  v0, a3, $4254
800A3CFC	and    s4, v0, t1
800A3D00	lui    s1, $0001
800A3D04	ori    s1, s1, $24dc
800A3D08	lui    s2, $8007
800A3D0C	addiu  s2, s2, $1a50
800A3D10	addiu  t6, t7, $0004
800A3D14	lui    a2, $ff00
800A3D18	lhu    v0, $0000(t2)
800A3D1C	lw     v1, $42d4(a3)
800A3D20	lui    t5, $8007
800A3D24	lw     t5, $16c4(t5)
800A3D28	sll    v0, v0, $02
800A3D2C	addu   v0, v0, a3
800A3D30	lw     v0, $0000(v0)
800A3D34	and    v1, v1, a2
800A3D38	and    v0, v0, a1
800A3D3C	or     v1, v1, v0
800A3D40	sw     v1, $42d4(a3)
800A3D44	lhu    a0, $0000(t2)
800A3D48	lui    v0, $8011
800A3D4C	lhu    v0, $44c8(v0)
800A3D50	sll    a0, a0, $02
800A3D54	addu   a0, a0, a3
800A3D58	sll    s3, v0, $10
800A3D5C	addiu  v0, a3, $42d4
800A3D60	lw     v1, $0000(a0)
800A3D64	and    v0, v0, a1
800A3D68	and    v1, v1, a2
800A3D6C	or     v1, v1, v0
800A3D70	sw     v1, $0000(a0)

La3d74:	; 800A3D74
800A3D74	lh     v1, $0000(t7)
800A3D78	ori    v0, zero, $7fff
800A3D7C	bne    v1, v0, La3dd0 [$800a3dd0]
800A3D80	ori    v0, zero, $7ffe
800A3D84	lhu    v0, $0000(t2)
800A3D88	lw     v1, $4254(a3)
800A3D8C	sll    v0, v0, $02
800A3D90	addu   v0, v0, a3
800A3D94	lw     v0, $0000(v0)
800A3D98	and    v1, v1, t8
800A3D9C	and    v0, v0, t1
800A3DA0	or     v1, v1, v0
800A3DA4	sw     v1, $4254(a3)
800A3DA8	lhu    v1, $0000(t2)
800A3DAC	nop
800A3DB0	sll    v1, v1, $02
800A3DB4	addu   v1, v1, a3
800A3DB8	lw     v0, $0000(v1)
800A3DBC	nop
800A3DC0	and    v0, v0, t8
800A3DC4	or     v0, v0, s4
800A3DCC	sw     v0, $0000(v1)
return;

La3dd0:	; 800A3DD0
800A3DD0	bne    v1, v0, La3e64 [$800a3e64]
800A3DD4	nop
800A3DD8	lh     v0, $fffe(t6)
800A3DDC	lui    a2, $8011
800A3DE0	lh     a2, $44d0(a2)
800A3DE4	nop
800A3DE8	addu   v0, v0, a2
800A3DEC	sll    a0, v0, $01
800A3DF0	addu   a0, a0, v0
800A3DF4	sll    a0, a0, $02
800A3DF8	addu   a0, a0, a3
800A3DFC	addu   a0, a0, s1
800A3E00	lhu    v0, $0000(t2)
800A3E04	lw     v1, $0000(a0)
800A3E08	sll    v0, v0, $02
800A3E0C	addu   v0, v0, a3
800A3E10	lw     v0, $0000(v0)
800A3E14	and    v1, v1, t8
800A3E18	and    v0, v0, t1
800A3E1C	or     v1, v1, v0
800A3E20	sw     v1, $0000(a0)
800A3E24	lhu    a1, $0000(t2)
800A3E28	lh     v1, $fffe(t6)
800A3E2C	sll    a1, a1, $02
800A3E30	addu   a1, a1, a3
800A3E34	addu   v1, v1, a2
800A3E38	sll    v0, v1, $01
800A3E3C	addu   v0, v0, v1
800A3E40	sll    v0, v0, $02
800A3E44	addu   v0, v0, s1
800A3E48	addu   v0, a3, v0
800A3E4C	lw     a0, $0000(a1)
800A3E50	and    v0, v0, t1
800A3E54	and    a0, a0, t8
800A3E58	or     a0, a0, v0
800A3E5C	j      La4068 [$800a4068]
800A3E60	sw     a0, $0000(a1)

La3e64:	; 800A3E64
800A3E64	lh     v0, $0000(t6)
800A3E68	lhu    t3, $fffe(t6)
800A3E6C	beq    v0, zero, La4068 [$800a4068]
800A3E70	addu   t4, v0, zero
800A3E74	sra    s0, s3, $10
800A3E78	ori    t9, zero, $e554

La3e7c:	; 800A3E7C
800A3E7C	sll    v0, t3, $10
800A3E80	sra    v0, v0, $10
800A3E84	sll    v1, v0, $02
800A3E88	addu   v1, v1, v0
800A3E8C	sll    v1, v1, $02
800A3E90	addu   a2, a3, v1
800A3E94	lui    at, $0001
800A3E98	addu   at, a2, at
800A3E9C	lh     a0, $e55c(at)
800A3EA0	lh     v1, $0000(s2)
800A3EA4	nop
800A3EA8	addiu  v0, v1, $fea0 (=-$160)
800A3EAC	slt    v0, v0, a0
800A3EB0	beq    v0, zero, La3ec4 [$800a3ec4]
800A3EB4	addu   a1, a0, zero
800A3EB8	slt    v0, a0, v1
800A3EBC	bne    v0, zero, La3efc [$800a3efc]
800A3EC0	sll    v0, t3, $10

La3ec4:	; 800A3EC4
800A3EC4	addiu  v0, v1, $ff60 (=-$a0)
800A3EC8	slt    v0, a0, v0
800A3ECC	beq    v0, zero, La3ee0 [$800a3ee0]
800A3ED0	nop
800A3ED4	lhu    v0, $001c(t5)
800A3ED8	j      La3eec [$800a3eec]
800A3EDC	addu   v0, a1, v0

La3ee0:	; 800A3EE0
800A3EE0	lhu    v0, $001c(t5)
800A3EE4	nop
800A3EE8	subu   v0, a1, v0

La3eec:	; 800A3EEC
800A3EEC	lui    at, $0001
800A3EF0	addu   at, a2, at
800A3EF4	sh     v0, $e55c(at)
800A3EF8	sll    v0, t3, $10

La3efc:	; 800A3EFC
800A3EFC	sra    v0, v0, $10
800A3F00	sll    v1, v0, $02
800A3F04	addu   v1, v1, v0
800A3F08	sll    v1, v1, $02
800A3F0C	addu   a2, a3, v1
800A3F10	lui    at, $0001
800A3F14	addu   at, a2, at
800A3F18	lh     a0, $e55e(at)
800A3F1C	lui    v1, $8007
800A3F20	lh     v1, $1a52(v1)
800A3F24	nop
800A3F28	addiu  v0, v1, $ff00 (=-$100)
800A3F2C	slt    v0, v0, a0
800A3F30	beq    v0, zero, La3f44 [$800a3f44]
800A3F34	addu   a1, a0, zero
800A3F38	slt    v0, a0, v1
800A3F3C	bne    v0, zero, La3f7c [$800a3f7c]
800A3F40	sll    v0, t3, $10

La3f44:	; 800A3F44
800A3F44	addiu  v0, v1, $ff90 (=-$70)
800A3F48	slt    v0, a0, v0
800A3F4C	beq    v0, zero, La3f60 [$800a3f60]
800A3F50	nop
800A3F54	lhu    v0, $001e(t5)
800A3F58	j      La3f6c [$800a3f6c]
800A3F5C	addu   v0, a1, v0

La3f60:	; 800A3F60
800A3F60	lhu    v0, $001e(t5)
800A3F64	nop
800A3F68	subu   v0, a1, v0

La3f6c:	; 800A3F6C
800A3F6C	lui    at, $0001
800A3F70	addu   at, a2, at
800A3F74	sh     v0, $e55e(at)
800A3F78	sll    v0, t3, $10

La3f7c:	; 800A3F7C
800A3F7C	sra    a2, v0, $10
800A3F80	sll    v0, a2, $02
800A3F84	addu   v0, v0, a2
800A3F88	sll    t0, v0, $02
800A3F8C	addu   a0, a3, t0
800A3F90	lh     a1, $0000(s2)
800A3F94	lui    at, $0001
800A3F98	addu   at, a0, at
800A3F9C	lh     v1, $e55c(at)
800A3FA0	addiu  v0, a1, $fea0 (=-$160)
800A3FA4	slt    v0, v0, v1
800A3FA8	beq    v0, zero, La4054 [$800a4054]
800A3FAC	slt    v0, v1, a1
800A3FB0	beq    v0, zero, La4054 [$800a4054]
800A3FB4	addu   v0, a2, s0
800A3FB8	sll    v0, v0, $01
800A3FBC	addu   v1, a3, v0
800A3FC0	lui    at, $0001
800A3FC4	addu   at, v1, at
800A3FC8	lbu    v0, $0d54(at)
800A3FCC	nop
800A3FD0	andi   v0, v0, $003f
800A3FD4	beq    v0, zero, La4008 [$800a4008]
800A3FD8	addu   a0, a0, t9
800A3FDC	lui    at, $0001
800A3FE0	addu   at, v1, at
800A3FE4	lbu    v1, $0d55(at)
800A3FE8	lui    at, $800a
800A3FEC	addiu  at, at, $ace6 (=-$531a)
800A3FF0	addu   at, at, v0
800A3FF4	lbu    v0, $0000(at)
800A3FF8	nop
800A3FFC	and    v0, v0, v1
800A4000	beq    v0, zero, La4058 [$800a4058]
800A4004	addiu  v0, t4, $ffff (=-$1)

La4008:	; 800A4008
800A4008	lhu    v0, $0000(t2)
800A400C	lw     v1, $0000(a0)
800A4010	sll    v0, v0, $02
800A4014	addu   v0, v0, a3
800A4018	lw     v0, $0000(v0)
800A401C	and    v1, v1, t8
800A4020	and    v0, v0, t1
800A4024	or     v1, v1, v0
800A4028	addu   v0, t0, t9
800A402C	sw     v1, $0000(a0)
800A4030	lhu    a0, $0000(t2)
800A4034	addu   v0, a3, v0
800A4038	sll    a0, a0, $02
800A403C	addu   a0, a0, a3
800A4040	lw     v1, $0000(a0)
800A4044	and    v0, v0, t1
800A4048	and    v1, v1, t8
800A404C	or     v1, v1, v0
800A4050	sw     v1, $0000(a0)

La4054:	; 800A4054
800A4054	addiu  v0, t4, $ffff (=-$1)

La4058:	; 800A4058
800A4058	addu   t4, v0, zero
800A405C	sll    v0, v0, $10
800A4060	bne    v0, zero, La3e7c [$800a3e7c]
800A4064	addiu  t3, t3, $0001

La4068:	; 800A4068
800A4068	addiu  t6, t6, $0006
800A406C	j      La3d74 [$800a3d74]
800A4070	addiu  t7, t7, $0006
////////////////////////////////
