////////////////////////////////
// funcaa0c8
// get unique id of tileset file
A0 = w[A0 + 24];
A1 = 3;
A2 = 000a0000;
A3 = 0;
func1c8b0;
return V0;
////////////////////////////////



////////////////////////////////
// funcc7430
[800c9df0 + 0] = b(0);
[800c9df0 + 2] = h(0);
[800c9df0 + 4] = w(0);
[800c9df0 + 8] = w(0);
return 1;
////////////////////////////////



////////////////////////////////
// funcbd3a0
tileset = w[800c9da4 + 10]; // pointer to tileset
block_numbers = hu[tileset + 6];
[800c9da4 + 24] = b(0);
[800c9da4 + 28] = w(w[800c9da4 + 2c]);
T0 = tileset + w[tileset + c]; // animations
T2 = tileset + w[tileset + 10]; // blocks
if( block_numbers != 0 )
{
    block_id = 0;
    loopbd3dc:	; 800BD3DC
        if( bu[T2 + block_id * 38 + 0] & 40 )
        {
            V0 = w[800c9da4 + 28] + bu[800c9da4 + 24] * c;
            [V0 + 0] = b(10);
            [V0 + 1] = b(block_id);
            [V0 + 4] = w(0);
            [V0 + 8] = w(0);

            [800c9da4 + 24] = b(bu[800c9da4 + 24] + 1);
            [800c9da4 + 34] = w(w[800c9da4 + 34] + c);

            if( bu[T2 + block_id * 38 + 0] & 20 )
            {
                block_id = block_id + w[T0 + 0] >> 8;
                T0 = T0 + 10;
            }
        }

        block_id = block_id + 1;
        V0 = block_id < block_numbers;
    800BD4C4	bne    v0, zero, loopbd3dc [$800bd3dc]
}

return 1;
////////////////////////////////



////////////////////////////////
// funcbd724
[800c9da0] = h(0)

S6 = 0;
loopbd76c:	; 800BD76C
    [800ca140 + S6 * dc + 0] = b(-1);
    [800ca140 + S6 * dc + 1] = b(80);
    [800ca140 + S6 * dc + 2] = b(80);
    [800ca140 + S6 * dc + 3] = b(80);
    [800ca140 + S6 * dc + 4] = h(-1);
    [800ca140 + S6 * dc + 6] = h(0);
    [800ca140 + S6 * dc + 8] = h(0);

    S3 = 0;
    loopbd7c0:	; 800BD7C0
        [800ca14c + S6 * dc + S3 * 18 + 3] = b(5);
        [800ca14c + S6 * dc + S3 * 18 + 4] = b(bu[800ca140 + S6 * dc + 1]);
        [800ca14c + S6 * dc + S3 * 18 + 5] = b(bu[800ca140 + S6 * dc + 2]);
        [800ca14c + S6 * dc + S3 * 18 + 6] = b(bu[800ca140 + S6 * dc + 3]);
        [800ca14c + S6 * dc + S3 * 18 + 7] = b(28);

        [800ca14c + S6 * dc + S3 * 18 + 60 + 3] = b(5);
        [800ca14c + S6 * dc + S3 * 18 + 60 + 4] = b(bu[800ca140 + S6 * dc + 1]);
        [800ca14c + S6 * dc + S3 * 18 + 60 + 5] = b(bu[800ca140 + S6 * dc + 2]);
        [800ca14c + S6 * dc + S3 * 18 + 60 + 6] = b(bu[800ca140 + S6 * dc + 3]);
        [800ca14c + S6 * dc + S3 * 18 + 60 + 7] = b(28);

        S3 = S3 + 1;
        V0 = S3 < 4;
    800BD834	bne    v0, zero, loopbd7c0 [$800bd7c0]

    S6 = S6 + 1;
    V0 = S6 < a;
800BD848	bne    v0, zero, loopbd76c [$800bd76c]

return 1;
////////////////////////////////



////////////////////////////////
// funcbded4
// camera settings?
800BDEDC	addu   s3, a0, zero
S0 = 800ca068;
S2 = 800c9da4;
A0 = bu[S0 + 75];
S1 = w[S2 + 10];
FP = A1;
800BDF1C	jal    funcc0bcc [$800c0bcc]


A0 = w[S1 + 18];
A0 = S1 + A0;

A2 = A0 + bu[S0 + 75] * 34;
[S0 + a4] = h((h[A2 + 28] + h[A2 + 2a]) / 2);
[S0 +  4] = h((h[A2 + 28] + h[A2 + 2a]) / 2);

[S0 + a6] = h((h[A2 + 2c] + h[A2 + 2e]) / 2);
[S0 +  6] = h((h[A2 + 2c] + h[A2 + 2e]) / 2);

[S1 + 30] = h(hu[S1 + 24] - ((h[A2 + 28] + h[A2 + 2a]) / 2) + a0);

number_of_blocks = hu[S1 + 6];
800BDFA4	sll    v0, number_of_blocks, $01
800BDFA8	addu   a1, v0, number_of_blocks

800BDFB0	lhu    v1, $0006(s0)
V0 = hu[S1 + 26];

800BDFB8	addiu  v1, v1, $ff90 (=-$70)
800BDFBC	subu   v0, v0, v1
[S1 + 32] = h(V0);

800BDFC4	srl    v0, a1, $02
800BDFC8	sll    v0, v0, $02
[S2 + 1c] = w(S3);
if (V0 != A1)
{
    800BDFD4	addiu  a1, a1, $0001

    loopbdfd8:	; 800BDFD8
        800BDFD8	srl    v0, a1, $02
        800BDFDC	sll    v0, v0, $02
        800BDFE4	addiu  a1, a1, $0001
    800BDFE0	bne    v0, a1, loopbdfd8 [$800bdfd8]

    800BDFE8	addiu  a1, a1, $ffff (=-$1)
}

800BDFEC	lui    v1, $800d
800BDFF0	addu   v0, s3, a1
800BDFF4	sw     v0, $9dc4(v1)
800BDFF8	addu   a1, a1, number_of_blocks

loopbdffc:	; 800BDFFC
    800BDFFC	srl    v0, a1, $02
    800BE000	sll    v0, v0, $02
    800BE008	addiu  a1, a1, $0001
800BE004	bne    v0, a1, loopbdffc [$800bdffc]

800BE00C	addiu  a1, a1, $ffff (=-$1)
800BE010	addu   v0, s3, a1
[FP] = w(V0);


S0 = 0;
V1 = 800ca068;
A1 = 800ca068;

loopbe02c:	; 800BE02C
    [V1 + a8] = h(0);
    [V1 + aa] = h(0);
    [V1 + b8] = h(hu[A2 + 24]);
    [V1 + ba] = h(hu[A2 + 26]);
    [A1 + c8] = h(0100);
    [A1 + d0] = h(0100);

    A1 = A1 + 2;
    V1 = V1 + 4;
    S0 = S0 + 1;
    V0 = S0 < 4;
800BE05C	bne    v0, zero, loopbe02c [$800be02c]


if (number_of_blocks != 0)
{
    800BE068	addu   s0, zero, zero
    800BE06C	lui    v0, $800d
    800BE070	addiu  s3, v0, $9da4 (=-$625c)
    800BE074	addiu  s4, zero, $0080
    800BE078	addiu  s6, zero, $8000 (=-$8000)
    800BE07C	addiu  s5, zero, $7fff
    S1 = S1 + w[S1 + 10];
    800BE084	addu   s2, s0, zero

    loopbe088:	; 800BE088
        800BE088	lw     v0, $001c(s3)
        800BE08C	nop
        800BE090	addu   v0, s2, v0
        800BE094	sb     s4, $0000(v0)
        800BE098	lw     v0, $001c(s3)
        800BE09C	nop
        800BE0A0	addu   v0, s2, v0
        800BE0A4	sb     s4, $0001(v0)
        800BE0A8	lw     v0, $001c(s3)
        800BE0AC	nop
        800BE0B0	addu   v0, s2, v0
        800BE0B4	sb     s4, $0002(v0)
        800BE0B8	lw     v0, $0020(s3)
        A0 = S1; // tile_block_data
        800BE0C0	addu   v0, v0, s0
        800BE0C4	sb     zero, $0000(v0)
        A1 = w[FP];
        A2 = FP;
        field_init_background_packets;

        if (V0 != 1)
        {
            return 0;
        }

        [S1 + 10] = h(S6);
        [S1 + 12] = h(S5);
        [S1 + 14] = h(S6);
        [S1 + 16] = h(S5);

        S1 = S1 + 38;
        S2 = S2 + 3;
        S0 = S0 + 1;
        V0 = S0 < number_of_blocks;
    800BE0FC	bne    v0, zero, loopbe088 [$800be088]
}

V1 = 800ca068;
800BE110	sb     zero, $0073(v1)
800BE114	sb     zero, $0072(v1)

[800ca068] = w(w[800ca068] & fffff3ff);

return 1;
////////////////////////////////



////////////////////////////////
// funcbfce8
[800ca068] = w(60);
V0 = 800ca068;
[V0 + 74] = b(40);

800BFD0C	addiu  v1, zero, $0144
800BFD10	sh     v1, $0076(v0)
800BFD14	addiu  v1, zero, $0e10
800BFD18	sw     v1, $0078(v0)
S0 = 800c9da4;
800BFD24	sw     zero, $0004(v0)
800BFD28	sw     zero, $0008(v0)
800BFD2C	sw     zero, $000c(v0)
800BFD30	sw     zero, $0010(v0)
800BFD34	sw     zero, $0014(v0)
800BFD38	sw     zero, $0018(v0)
800BFD3C	sw     zero, $0024(v0)
800BFD40	sw     zero, $0028(v0)
800BFD44	sw     zero, $002c(v0)
800BFD48	sb     zero, $0075(v0)
800BFD4C	sh     zero, $009c(v0)
800BFD50	sb     zero, $00a0(v0)

A0 = w[800c9da4 + 14];
A1 = w[800c9da4 + 4];

800BFD5C	addiu  v1, zero, $00ff
800BFD60	sb     v1, $00a1(v0)
800BFD64	sb     v1, $00a2(v0)
800BFD68	sb     v1, $00a3(v0)
800BFD6C	sw     zero, $00a4(v0)
800BFD70	sw     a0, $001c(v0)
800BFD74	sw     a1, $0020(v0)

A0 = w[800c9da4 + 18];
A1 = SP + 18;
funcbded4;

if( V0 != 1 )
{
    return 0;
}



// init 1st frame in animation sequence.
tileset_data = w[800c9da4 + 10]; // pointer to tileset
anim = tileset_data + w[tileset_data + c]; // offset to tileset animations
block = tileset_data + w[tileset_data + 10]; // offset to tileset blocks

number_of_animations = hu[tileset_data + 4];
if( number_of_animations != 0 )
{
    anim_id = 0;
    loopbfdc4:	; 800BFDC4
        [anim + anim_id * 10 + 0] = b(1);
        [anim + anim_id * 10 + 4] = w(bu[anim + anim_id * 10 + 4]);
        [anim + anim_id * 10 + 8] = h(100);
        [anim + anim_id * 10 + a] = h(0);

        V0 = w[anim + anim_id * 10 + c]; // pointer to sequences
        V1 = bu[tileset_data + V0];
        [block + V1 * 38 + 0] = b(bu[block + V1 * 38 + 0] | 02);

        anim_id = anim_id + 1;
        V0 = anim_id < number_of_animations;
    800BFE0C	bne    v0, zero, loopbfdc4 [$800bfdc4]
}

funcbd3a0;

funcbd724;

800BFE24	addiu  t3, zero, $00a0
800BFE28	addiu  t7, zero, $0070
800BFE2C	sh     zero, $0010(sp)
800BFE30	sh     zero, $0012(sp)
800BFE34	sh     zero, $0014(sp)
800BFE38	sll    t4, t3, $10
800BFE3C	sll    t5, t7, $10
800BFE40	ctc2   t4,mac0
800BFE44	ctc2   t5,mac1
800BFE48	lui    a0, $800d
800BFE4C	addiu  a0, a0, $a068 (=-$5f98)
800BFE50	lw     t3, $001c(a0)
800BFE54	nop
800BFE58	lw     t4, $0000(t3)
800BFE5C	lw     t5, $0004(t3)
800BFE60	ctc2   t4,vxy0
800BFE64	ctc2   t5,vz0
800BFE68	lw     t4, $0008(t3)
800BFE6C	lw     t5, $000c(t3)
800BFE70	lw     t6, $0010(t3)
800BFE74	ctc2   t4,vxy1
800BFE78	ctc2   t5,vz1
800BFE7C	ctc2   t6,vxy2
800BFE80	lw     t4, $0014(t3)
800BFE84	lw     t5, $0018(t3)
800BFE88	ctc2   t4,vz2
800BFE8C	lw     t6, $001c(t3)
800BFE90	ctc2   t5,rgb
800BFE94	ctc2   t6,otz
800BFE98	addiu  v0, sp, $0010
800BFE9C	lwc2   zero, $0000(v0)
800BFEA0	lwc2   at, $0004(v0)
800BFEA4	nop
800BFEA8	nop
800BFEAC	gte_func16t8,r11r12
800BFEB0	addiu  v0, sp, $001c
800BFEB4	swc2   t6, $0000(v0)
800BFEB8	lw     v0, $0018(sp)
800BFEBC	lw     v1, $001c(sp)
800BFEC0	lh     a1, $001c(sp)
800BFEC4	sra    v1, v1, $10
800BFEC8	sh     a1, $002c(a0)
800BFECC	sh     v1, $002e(a0)
////////////////////////////////



////////////////////////////////
// funcc3b80
800C3B84	lui    v1, $800d
800C3B88	addiu  v1, v1, $9df0 (=-$6210)
800C3B98	sw     a0, $0008(v1)
800C3B9C	lhu    v0, $003a(a0)
800C3BA0	addu   s0, zero, zero
800C3BA4	addu   v0, a0, v0
800C3BA8	sw     v0, $000c(v1)
800C3BAC	lhu    v0, $0026(a0)
800C3BB0	addu   a1, v1, zero
800C3BB4	addu   v0, a0, v0
800C3BB8	sw     v0, $0010(a1)
800C3BBC	lhu    v0, $0036(a0)
800C3BC0	addiu  a2, zero, $ffff (=-$1)
800C3BC4	addu   v0, a0, v0
800C3BC8	sw     v0, $0014(a1)
800C3BCC	lhu    v0, $002a(a0)
800C3BD0	addiu  t0, zero, $0060
800C3BD4	addu   v0, a0, v0
800C3BD8	sw     v0, $0018(a1)
800C3BDC	lhu    v0, $0032(a0)
800C3BE0	addiu  a3, zero, $2400
800C3BE4	addu   v0, a0, v0
800C3BE8	sw     v0, $001c(a1)
800C3BEC	lhu    v1, $002e(a0)
800C3BF0	addiu  v0, zero, $00ff
800C3BF4	sb     v0, $0001(a1)
800C3BF8	addiu  v0, zero, $0009
800C3BFC	sh     v0, $0002(a1)
800C3C00	lui    v0, $800d
800C3C04	addiu  v0, v0, $aad8 (=-$5528)
800C3C08	sw     v0, $0004(a1)
800C3C0C	addu   a0, a0, v1
800C3C10	sw     a0, $0020(a1)

loopc3c14:	; 800C3C14
800C3C14	andi   v0, s0, $ffff
800C3C18	sll    v1, v0, $02
800C3C1C	addu   v1, v1, v0
800C3C20	lw     v0, $0004(a1)
800C3C24	sll    v1, v1, $03
800C3C28	addu   v0, v1, v0
800C3C2C	sh     zero, $0000(v0)
800C3C30	lw     v0, $0004(a1)
800C3C34	nop
800C3C38	addu   v0, v1, v0
800C3C3C	sh     zero, $0002(v0)
800C3C40	lw     v0, $0004(a1)
800C3C44	nop
800C3C48	addu   v0, v1, v0
800C3C4C	sh     a2, $0004(v0)
800C3C50	lw     v0, $0004(a1)
800C3C54	nop
800C3C58	addu   v0, v1, v0
800C3C5C	sh     a2, $0006(v0)
800C3C60	lw     v0, $0004(a1)
800C3C64	nop
800C3C68	addu   v0, v1, v0
800C3C6C	sh     a2, $0008(v0)
800C3C70	lw     v0, $0004(a1)
800C3C74	nop
800C3C78	addu   v0, v1, v0
800C3C7C	sh     a2, $000a(v0)
800C3C80	lw     v0, $0004(a1)
800C3C84	nop
800C3C88	addu   v0, v1, v0
800C3C8C	sw     t0, $001c(v0)
800C3C90	lw     v0, $0004(a1)
800C3C94	nop
800C3C98	addu   v0, v1, v0
800C3C9C	sw     a3, $0020(v0)
800C3CA0	lw     v0, $0004(a1)
800C3CA4	addiu  s0, s0, $0001
800C3CA8	addu   v1, v1, v0
800C3CAC	andi   v0, s0, $ffff
800C3CB0	sltiu  v0, v0, $0018
800C3CB4	bne    v0, zero, loopc3c14 [$800c3c14]
800C3CB8	sw     zero, $0024(v1)
800C3CBC	lui    v1, $800d
800C3CC0	addiu  a1, v1, $9df0 (=-$6210)

A0 = w[A1 + 8];
800C3CC8	addiu  v0, zero, $0001
800C3CCC	sb     v0, $9df0(v1)

if (hu[A0 + 2c] != 0)
{
    S0 = 0;
    S1 = A1;

    loopc3ce4:	; 800C3CE4
        A0 = S0;
        800C3CE4	jal    funcc79b0 [$800c79b0]

        V0 = w[S1 + 8];
        S0 = S0 + 1;
        V0 = S0 < hu[V0 + 2c];
    800C3D00	bne    v0, zero, loopc3ce4 [$800c3ce4]
}

800C3D08	jal    funcc6e94 [$800c6e94]
////////////////////////////////



////////////////////////////////
// funca9860
S2 = A0;
V1 = w[8006794c];
A1 = w[V1 + 1c];

A0 = A1 + 8;
A4 = A1 + 18;
A2 = w[A1 + 10];
A3 = w[A1 + 14];
A1 = A1 + a;
A5 = w[80067948] + 400;
800A98AC	jal    funcc0d40 [$800c0d40]

A0 = w[80067948];
A1 = 400;
800A98B8	jal    funcc0d8c [$800c0d8c]

A0 = S2;
funcaa0c8; // get file id for tileset
S1 = V0;

A0 = 4;
A1 = S1;
A2 = 0;
func1c7fc; // get pointer to tileset
[S2 + 14] = w(V0);
[800c9db4] = w(V0);


800bdf18 : LW      000a001f (s1), 0010 (800c9da4 (s2)) [800c9db4]
800c0bd0 : LW      0000000d (a3), 9db4 (800d0000 (v0)) [800c9db4]
800bd154 : LW      8011f220 (a0), 9db4 (800d0000 (v0)) [800c9db4]
800bfd90 : LW      0000008e (a2), 0010 (800c9da4 (s0)) [800c9db4]
800bd3a8 : LW      800d0000 (v0), 0010 (800c9da4 (a3)) [800c9db4]
800b19f0 : LW      800b295c (ra), 0054 (801ffe80 (sp)) [801ffed4]
800c1430 : LW      00000001 (v1), 9db4 (800d0000 (v0)) [800c9db4]
800c1430 : LW      00000001 (v1), 9db4 (800d0000 (v0)) [800c9db4]
800bd4e0 : LW      00000000 (s2), 9db4 (800d0000 (v0)) [800c9db4]
800bf710 : LW      00000000 (s5), 9db4 (800d0000 (v0)) [800c9db4]
800bff5c : LW      00000070 (a0), 0010 (800c9da4 (s0)) [800c9db4]
800bdc8c : LW      00000000 (s3), 9db4 (800d0000 (v0)) [800c9db4]
800c0f10 : LW      80077fb0 (a0), 9db4 (800d0000 (v0)) [800c9db4]
800bff78 : LW      8006794c (s1), 0010 (800c9da4 (s0)) [800c9db4]
800be190 : LW      800ca1ac (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      0000000a (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      0000000c (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      0000003e (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      00000008 (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      0000006e (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      00000009 (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      0000004e (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      00000085 (t0), 0010 (800c9da4 (v1)) [800c9db4]
800be190 : LW      00000258 (t0), 0010 (800c9da4 (v1)) [800c9db4]
800c0f10 : LW      8011f808 (a0), 9db4 (800d0000 (v0)) [800c9db4]
800c0f10 : LW      801fff60 (a0), 9db4 (800d0000 (v0)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800c137c : LW      80080000 (t0), 0010 (800c9da4 (t1)) [800c9db4]
800bd4e0 : LW      00000000 (s2), 9db4 (800d0000 (v0)) [800c9db4]
800bf710 : LW      00000000 (s5), 9db4 (800d0000 (v0)) [800c9db4]
800bff5c : LW      00000070 (a0), 0010 (800c9da4 (s0)) [800c9db4]
800bdc8c : LW      00000000 (s3), 9db4 (800d0000 (v0)) [800c9db4]







funcbfce8;
[80067948] = w(V0);

funcc7430;


A0 = 9;
A1 = S1;
A2 = 000b0000;
func1c7fc;

A0 = 4;
A1 = V0;
A2 = 0;
func1c7fc;
[S2 + 18] = w(V0);


A0 = V0 + 4;
800A9920	jal    funcc3b80 [$800c3b80]

A0 = w[80067948];
800A992C	jal    funcafcbc [$800afcbc]

return 0;
////////////////////////////////



////////////////////////////////
// funca89c4
S5 = A0;
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
V1 = w[V0 + 4];
[80067948] = w(V1);

800A8A0C	jal    funca9350 [$800a9350]

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
S4 = w[V0 + 14];
S1 = 1;
800A8A38	jal    funca939c [$800a939c]

800A8A40	jal    func1cfb4 [$8001cfb4]

A0 = -310;

V1 = w[8006794c];
A1 = w[V1 + 1c];
[V1] = w(w[V1] & A0);
[A1] = w(w[A1] | 00000020);
V0 = w[V1 + 1c];
V1 = w[V0 + 8e4];
[V1] = w(w[V1] & 00000004);

A0 = 0;
A1 = 0;
A2 = 0;
800A8A8C	jal    func1ccb4 [$8001ccb4]

[80073998] = w(w[80073998] & ffff0006);


V1 = 800c9ef0;
loopa8ab4:	; 800A8AB4
    A1 = 3;
    V0 = S2 << A1;
    A0 = V0 + 6;

    loopa8ac0:	; 800A8AC0
        V0 = A0 + V1;
        A0 = A0 - 2;
        A1 = A1 - 1;
        [V0 + 0] = h(0);
        [V0 + 10] = h(0);
    800A8AD0	bgez   a1, loopa8ac0 [$800a8ac0]

    S1 = S1 - 1;
800A8ADC	bgez   s1, loopa8ab4 [$800a8ab4]

V0 = w[8006794c];
800A8AEC	lw     v0, $001c(v0)
800A8AF0	nop
800A8AF4	lw     v0, $08e4(v0)
800A8AF8	jal    funcaa4bc [$800aa4bc]
800A8AFC	sb     zero, $0008(v0)

V0 = w[8006794c];

800A8B08	lw     v0, $001c(v0)
800A8B0C	nop
800A8B10	lw     v0, $08e4(v0)
800A8B14	nop
800A8B18	sb     zero, $0009(v0)
V0 = w[8006794c];
8800A8B24	lw     v0, $001c(v0)

A1 = S5;
[V0 + c] = h(S5);
[S4 + a] = h(S5);

A0 = S4;
funca9bdc; // we read db pointers here

800A8B38	addu   a0, s4, zero
800A8B3C	jal    funca97d4 [$800a97d4]
800A8B40	addu   a1, s5, zero
800A8B44	addu   a0, s4, zero
A1 = S5;
800A8B48	jal    funca9814 [$800a9814]

A0 = S4;
funca9860; // we read tileset db pointer here


A0 = S4;
A1 = S5;
funca9954;

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
A1 = w[V0 + 14];
A0 = A1 + 50;
A1 = A1 + 52;
800A8B94	jal    funcaa01c [$800aa01c]

800A8B9C	jal    funcb3a80 [$800b3a80]

800A8BA4	jal    funca9998 [$800a9998]

800A8BAC	addiu  a0, zero, $0900
800A8BB0	addiu  a1, zero, $ffff (=-$1)
800A8BB4	addu   a2, zero, zero
800A8BB8	addu   a3, a2, zero
800A8BBC	jal    funcb0124 [$800b0124]
800A8BC0	sw     zero, $0010(sp)

A0 = w[S4 + c]; // offset to script
func49ed8; // we parse init script here

A0 = w[S4 + c];
system_init_script_system;


La8bdc:	; 800A8BDC
800A8BDC	jal    funcac474 [$800ac474]
800A8BE0	nop
800A8BE4	jal    funca9aac [$800a9aac]
800A8BE8	nop

loopa8bec:	; 800A8BEC
800A8BEC	sw     zero, $0010(sp)
800A8BF0	addiu  a0, zero, $0c00

funca8bf4:	; 800A8BF4
800A8BF4	addiu  a1, zero, $ffff (=-$1)
800A8BF8	addu   a2, zero, zero
800A8BFC	jal    funcb0124 [$800b0124]
800A8C00	addu   a3, a2, zero
800A8C04	bne    v0, zero, loopa8bec [$800a8bec]
800A8C08	nop
800A8C0C	jal    func4bfb0 [$8004bfb0]
800A8C10	addu   s1, zero, zero
800A8C14	jal    func4aaf0 [$8004aaf0]
800A8C18	addu   a0, zero, zero
800A8C1C	lui    a1, $8006
800A8C20	lw     v1, $794c(a1)
800A8C24	nop
800A8C28	lw     v1, $001c(v1)
800A8C2C	lui    a3, $8006
800A8C30	sb     v0, $0038(v1)
800A8C34	lw     a2, $794c(a1)
800A8C38	lw     v0, $7948(a3)
800A8C3C	lw     v1, $001c(a2)
800A8C40	nop
800A8C44	sw     v0, $08dc(v1)
800A8C48	lw     a0, $001c(a2)
800A8C4C	nop
800A8C50	lbu    v1, $0038(a0)
800A8C54	addu   s3, a1, zero
800A8C58	sll    v0, v1, $02
800A8C5C	addu   v0, v0, v1
800A8C60	sll    v0, v0, $02
800A8C64	subu   v0, v0, v1
800A8C68	lw     v1, $08dc(a0)
800A8C6C	sll    v0, v0, $03
800A8C70	addu   v1, v1, v0
800A8C74	sw     v1, $08e0(a0)
800A8C78	lw     a0, $001c(a2)
800A8C7C	addu   s2, s1, zero
800A8C80	lbu    v0, $0038(a0)
800A8C84	addu   s0, s1, zero
800A8C88	sll    v1, v0, $02
800A8C8C	addu   v1, v1, v0
800A8C90	lw     v0, $08e0(a0)
800A8C94	sll    v1, v1, $02
800A8C98	addu   v0, v0, v1
800A8C9C	sw     v0, $7948(a3)
800A8CA0	sb     zero, $0009(a0)

loopa8ca4:	; 800A8CA4
800A8CA4	lw     v0, $794c(s3)
800A8CA8	nop
800A8CAC	lw     v0, $001c(v0)
800A8CB0	nop
800A8CB4	lw     a0, $08d8(v0)
800A8CB8	jal    func1e3a4 [$8001e3a4]
800A8CBC	addu   a0, a0, s0

La8cc0:	; 800A8CC0
800A8CC0	lw     v0, $794c(s3)
800A8CC4	nop
800A8CC8	lw     v0, $001c(v0)
800A8CCC	addiu  s1, s1, $0001
800A8CD0	lw     v1, $08d4(v0)

funca8cd4:	; 800A8CD4
800A8CD4	lw     v0, $08d8(v0)
800A8CD8	addu   v1, v1, s2
800A8CDC	addiu  s2, s2, $0098
800A8CE0	addu   v0, s0, v0
800A8CE4	sw     v1, $0008(v0)
800A8CE8	slti   v0, s1, $0009
800A8CEC	bne    v0, zero, loopa8ca4 [$800a8ca4]
800A8CF0	addiu  s0, s0, $0014
800A8CF4	lui    v1, $8006
800A8CF8	lw     v0, $794c(v1)
800A8CFC	nop
800A8D00	lw     v0, $001c(v0)
800A8D04	nop
800A8D08	sb     zero, $0039(v0)
800A8D0C	lw     v0, $794c(v1)
800A8D10	nop
800A8D14	lw     v0, $001c(v0)
800A8D18	nop
800A8D1C	lbu    v0, $0038(v0)
800A8D20	nop
800A8D24	beq    v0, zero, La8d94 [$800a8d94]
800A8D28	addu   s1, zero, zero
800A8D2C	addu   s3, v1, zero
800A8D30	addu   s2, s1, zero
800A8D34	addu   s0, s1, zero

loopa8d38:	; 800A8D38
800A8D38	lw     v0, $794c(s3)
800A8D3C	nop
800A8D40	lw     v0, $001c(v0)
800A8D44	nop
800A8D48	lw     a0, $08e0(v0)
800A8D4C	jal    func1e3a4 [$8001e3a4]
800A8D50	addu   a0, a0, s0
800A8D54	lw     a0, $794c(s3)
800A8D58	nop
800A8D5C	lw     v0, $001c(a0)
800A8D60	addiu  s1, s1, $0001
800A8D64	lw     v1, $08e0(v0)
800A8D68	lw     v0, $08dc(v0)
800A8D6C	addu   v1, s0, v1
800A8D70	addu   v0, v0, s2
800A8D74	sw     v0, $0008(v1)
800A8D78	lw     v0, $001c(a0)
800A8D7C	addiu  s2, s2, $0098
800A8D80	lbu    v0, $0038(v0)
800A8D84	nop
800A8D88	slt    v0, s1, v0
800A8D8C	bne    v0, zero, loopa8d38 [$800a8d38]
800A8D90	addiu  s0, s0, $0014

La8d94:	; 800A8D94
800A8D94	lui    s0, $8006
800A8D98	lui    s1, $8006
800A8D9C	lw     a0, $7948(s0)
800A8DA0	lw     v0, $794c(s1)
800A8DA4	sw     a0, $002c(s4)
800A8DA8	lw     v1, $001c(v0)
800A8DAC	nop
800A8DB0	lw     v0, $08e4(v1)
800A8DB4	nop
800A8DB8	lw     v0, $000c(v0)
800A8DBC	nop
800A8DC0	lw     v0, $0014(v0)
800A8DC4	lbu    a1, $0038(v1)
800A8DC8	lh     a2, $0050(v0)
800A8DCC	lh     a3, $0052(v0)
800A8DD0	jal    funcad44c [$800ad44c]
800A8DD4	addiu  a1, a1, $0009
800A8DD8	addu   a0, s4, zero
800A8DDC	addu   a1, s5, zero

funca8de0:	; 800A8DE0
800A8DE0	jal    funcb2528 [$800b2528]
800A8DE4	sw     v0, $7948(s0)
800A8DE8	jal    funcb1c98 [$800b1c98]
800A8DEC	nop
800A8DF0	lw     v0, $7948(s0)
800A8DF4	nop
800A8DF8	sw     v0, $0020(s4)
800A8DFC	jal    func4a8a4 [$8004a8a4]
800A8E00	sw     v0, $0004(s4)
800A8E04	lui    a1, $8007
800A8E08	lui    v1, $0004
800A8E0C	lw     v0, $3998(a1)
800A8E10	lw     a0, $794c(s1)
800A8E14	or     v0, v0, v1
800A8E18	sw     v0, $3998(a1)
800A8E1C	lw     a0, $001c(a0)
800A8E20	nop

funca8e24:	; 800A8E24
800A8E24	lw     v0, $0000(a0)
800A8E28	addiu  v1, zero, $ffdf (=-$21)
800A8E2C	and    v0, v0, v1
800A8E30	sw     v0, $0000(a0)
////////////////////////////////



////////////////////////////////
// funca9bdc
S5 = A0;
A2 = A1;
A1 = 801ddf00;
A0 = 10000;

800A9BF8	lui    v0, $8006
800A9BFC	lw     v0, $794c(v0)
800A9C00	ori    a0, a0, $6fff
800A9C1C	lw     v0, $001c(v0)
800A9C20	lui    v1, $8006
800A9C24	lw     v0, $0808(v0)
800A9C28	lw     v1, $7948(v1)
800A9C2C	sll    s0, v0, $0b
800A9C30	addu   v0, v1, s0
800A9C34	subu   a1, a1, v0
800A9C38	slt    a0, a0, a1
800A9C3C	bne    a0, zero, La9c60 [$800a9c60]
800A9C40	lui    v0, $801d
800A9C44	ori    v0, v0, $6f00
800A9C48	subu   s0, v0, v1
800A9C4C	bgez   s0, La9c58 [$800a9c58]
800A9C50	addu   v0, s0, zero
800A9C54	addiu  v0, s0, $07ff

La9c58:	; 800A9C58
800A9C58	sra    v0, v0, $0b
800A9C5C	sll    s0, v0, $0b

La9c60:	; 800A9C60
800A9C60	andi   v1, a2, $ffff
800A9C64	lui    v0, $0005
800A9C68	or     s1, v1, v0
800A9C6C	jal    func220e8 [$800220e8]
800A9C70	addu   a0, s1, zero
800A9C74	beq    v0, zero, La9cf0 [$800a9cf0]
800A9C78	lui    v0, $8006
800A9C7C	jal    func21e5c [$80021e5c]
800A9C80	addu   a0, s1, zero
800A9C84	lui    v1, $8006
800A9C88	lw     a0, $7948(v1)
800A9C8C	lui    v1, $8006
800A9C90	lw     a3, $794c(v1)
800A9C94	lw     v1, $0008(v0)
800A9C98	lw     a1, $000c(v0)
800A9C9C	lw     a2, $001c(a3)
800A9CA0	addu   v1, v1, a1
800A9CA4	sw     v1, $0874(a2)
800A9CA8	lw     a1, $001c(a3)
800A9CAC	lw     v1, $000c(v0)
800A9CB0	nop
800A9CB4	sw     v1, $0864(a1)
800A9CB8	lw     a1, $001c(a3)
800A9CBC	lw     v1, $001c(v0)
800A9CC0	nop
800A9CC4	sw     v1, $0858(a1)
800A9CC8	lw     a1, $0008(v0)
800A9CCC	lw     a2, $000c(v0)
800A9CD0	jal    func1daa4 [$8001daa4]
800A9CD4	addu   a3, zero, zero
800A9CD8	jal    func22390 [$80022390]
800A9CDC	addu   a0, s1, zero
800A9CE0	jal    func130a4 [$800130a4]
800A9CE4	addu   a0, zero, zero
800A9CE8	j      La9d40 [$800a9d40]
800A9CEC	lui    s3, $8006

La9cf0:	; 800A9CF0
800A9CF0	addu   s1, v0, zero
800A9CF4	lw     v0, $794c(s1)
800A9CF8	lui    v1, $8006
800A9CFC	lw     v0, $001c(v0)
800A9D00	lw     a3, $7948(v1)
800A9D04	lw     a2, $0808(v0)
800A9D08	addiu  a0, v0, $0854
800A9D0C	sw     zero, $0010(sp)
800A9D10	sw     s0, $0014(sp)
800A9D14	sw     zero, $0018(sp)
800A9D18	lw     a1, $0800(v0)
800A9D1C	jal    func2177c [$8002177c]
800A9D20	sll    a2, a2, $0b

loopa9d24:	; 800A9D24
    800A9D24	lw     v0, $794c(s1)
    800A9D28	nop
    800A9D2C	lw     a0, $001c(v0)
    800A9D30	jal    func217c4 [$800217c4]
    800A9D34	addiu  a0, a0, $0854
800A9D38	bne    v0, zero, loopa9d24 [$800a9d24]

La9d40:	; 800A9D40
800A9D3C	lui    s3, $8006
800A9D40	lw     v0, $794c(s3)
800A9D44	nop
800A9D48	lw     v0, $001c(v0)
800A9D4C	nop
800A9D50	lw     a0, $0874(v0)
800A9D54	jal    funcac67c [$800ac67c]

S4 = w[80067948];



A0 = S4;
A1 = 4;
A2 = 140000;
A3 = 0;
func1c8b0; // address of file with identificator 0 in resource file type 14
V1 = w[8006794c];
V1 = w[V1 + 1c];
[V1 + 7e4] = w(V0);



A0 = S4;
A1 = 2;
A2 = 1b0000;
A3 = 0;
func1c8b0; // address of file with index 0 in resource file type 1b

S1 = V0;
if (S1 != 0)
{
    A0 = S4;
    A1 = 5;
    A2 = 1b0000;
    A3 = 0;
    func1c8b0;

    T1 = w[8006794c];
    A1 = w[T1 + 1c];
    V1 = w[80067948];
    T0 = w[A1 + 864];

    V0 = S1 + V0;
    A3 = V1 + T0;

    S2 = T0;

    if (A3 < V0)
    {
        800A9DD8	lw     a2, $0808(a1)
        800A9DDC	sw     s2, $0010(sp)
        800A9DE0	lw     v0, $001c(t1)
        800A9DE4	nop
        800A9DE8	lw     v0, $0864(v0)
        800A9DEC	addiu  a0, a1, $0854
        800A9DF0	sw     zero, $0018(sp)
        800A9DF4	subu   v0, s0, v0
        800A9DF8	sw     v0, $0014(sp)
        800A9DFC	lw     a1, $0800(a1)
        800A9E00	jal    func2177c [$8002177c]
        800A9E04	sll    a2, a2, $0b

        loopa9e08:	; 800A9E08
            800A9E08	lw     v0, $794c(s3)
            800A9E0C	nop
            800A9E10	lw     a0, $001c(v0)
            800A9E14	jal    func217c4 [$800217c4]
            800A9E18	addiu  a0, a0, $0854
        800A9E1C	bne    v0, zero, loopa9e08 [$800a9e08]

        800A9E20	lui    v0, $8006
        800A9E24	lw     a0, $794c(v0)
        800A9E28	nop
        800A9E2C	lw     v1, $001c(a0)
        800A9E30	nop
        800A9E34	lw     v0, $0864(v1)
        800A9E38	nop
        800A9E3C	addu   v0, v0, s2
        800A9E40	sw     v0, $0864(v1)
        800A9E44	lw     v0, $001c(a0)
        800A9E48	nop
        800A9E4C	lw     a0, $0874(v0)
        800A9E50	jal    funcac67c [$800ac67c]
        800A9E54	nop
    }

    A0 = S1;
    A1 = 1;
    A2 = 40000;
    A3 = 0;
    func1c8b0;

    S0 = V0 - 1;
    if (S0 >= 0)
    {
        loopa9e80:	; 800A9E80
            A0 = S1;

            A1 = 2;
            A2 = 40000 | (S0 & ffff);
            A3 = 0;
            func1c8b0; // get addresses of tim files

            if (V0 != -1)
            {
                A0 = V0;
                func1d8a8; // load tim files?
            }

            S0 = S0 - 1;
        800A9EA8	bgez   s0, loopa9e80 [$800a9e80]
    }

    A0 = S1;
    A1 = 1;
    A2 = 170000;
    A3 = 0;
    func1c8b0; // get number of files of resource type 17

    S0 = V0 - 1;
    if (S0 >= 0)
    {
        loopa9ed4:	; 800A9ED4
            A0 = S1;
            A1 = 2;
            A2 = 170000 | (S0 & ffff);
            A3 = 0;
            func1c8b0; // get addresses of 17 type files

            if (V0 != -1)
            {
                A0 = V0;
                800A9EF4	jal    funcc9968 [$800c9968]
            }

            S0 = S0 - 1;
        800A9F00	bgez   s0, loopa9ed4 [$800a9ed4]
    }

    A0 = 0;
    800A9F08	jal    func130a4 [$800130a4]
}

A0 = S4;
A1 = 2;
A2 = 1b0001;
A3 = 0;
func1c8b0; // address of file with index 1 in resource file type 1b

A0 = S1;
V1 = w[8006794c];

A1 = V0;
[S5 + 24] = w(A1);
V0 = w[V1 + 1c];
V1 = w[V0 + 864];

S0 = V1 - A1 + S4;
A2 = S0;
A3 = 0;
func1daa4;

800A9F58	jal    func130a4 [$800130a4]
800A9F5C	addu   a0, zero, zero
800A9F2C	lui    s2, $8006
800A9F60	lw     v0, $794c(s2)
800A9F64	sw     s1, $0024(s5)
800A9F68	lw     v1, $001c(v0)
800A9F6C	nop
800A9F70	lw     a1, $0864(v1)
800A9F74	lw     v0, $0858(v1)
800A9F78	nop
800A9F7C	slt    v0, a1, v0
800A9F80	beq    v0, zero, La9fcc [$800a9fcc]
800A9F84	addiu  a0, v1, $0854
800A9F88	addu   a3, s1, s0
800A9F8C	addu   s0, s2, zero
800A9F90	lw     a2, $0808(v1)
800A9F94	addiu  v0, zero, $ffff (=-$1)
800A9F98	sw     a1, $0010(sp)
800A9F9C	sw     v0, $0014(sp)
800A9FA0	sw     zero, $0018(sp)
800A9FA4	lw     a1, $0800(v1)
800A9FA8	jal    func2177c [$8002177c]
800A9FAC	sll    a2, a2, $0b

loopa9fb0:	; 800A9FB0
    800A9FB0	lw     v0, $794c(s0)
    800A9FB4	nop
    800A9FB8	lw     a0, $001c(v0)
    800A9FBC	jal    func217c4 [$800217c4]
    800A9FC0	addiu  a0, a0, $0854
800A9FC4	bne    v0, zero, loopa9fb0 [$800a9fb0]

La9fcc:	; 800A9FCC
800A9FCC	lw     a0, $0024(s5)
800A9FD0	jal    func1c750 [$8001c750]
800A9FD4	addu   a1, zero, zero
800A9FD8	lw     a0, $0024(s5)
800A9FDC	jal    func1ca70 [$8001ca70]
800A9FE0	nop
800A9FE4	lui    a0, $8006
800A9FE8	lw     v1, $0024(s5)
800AA008	addu   v1, v1, v0
800AA00C	addu   v0, zero, zero
800AA010	sw     v1, $7948(a0)
////////////////////////////////