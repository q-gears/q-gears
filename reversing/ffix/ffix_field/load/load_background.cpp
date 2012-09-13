////////////////////////////////
// funca9860
field_struct = A0;
V1 = w[8006794c];
A1 = w[V1 + 1c];

A0 = A1 + 8; // frame buffer index.
A4 = A1 + 18; // main transformation matrix.
A2 = w[A1 + 10]; // 1st frame buffer depth stack
A3 = w[A1 + 14]; // 2nd frame buffer depth stack
A1 = A1 + a; // Projection plane distance for rasterisation.
A5 = w[80067948] + 400;
funcc0d40; // init data for tile struct.



A0 = w[80067948];
A1 = 400;
funcc0d8c;



A0 = field_struct;
funcaa0c8; // get file id for tileset
S1 = V0;

A0 = 4;
A1 = S1;
A2 = 0;
func1c7fc; // get pointer to tileset
[field_struct + 14] = w(V0);
[800c9da4 + 10] = w(V0);









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
[field_struct + 18] = w(V0);


A0 = V0 + 4;
800A9920	jal    funcc3b80 [$800c3b80]

A0 = w[80067948];
800A992C	jal    funcafcbc [$800afcbc]

return 0;
////////////////////////////////



////////////////////////////////
// funcc0d40
[800c9da4 +  0] = w(A0);
[800c9da4 +  4] = w(A1);
[800c9da4 +  8] = w(A2);
[800c9da4 +  c] = w(A3);
[800c9da4 + 10] = w(0);
[800c9da4 + 14] = w(A4);
[800c9da4 + 18] = w(A5);
[800c9da4 + 1c] = w(A5);
[800c9da4 + 20] = w(A5);
[800c9da4 + 24] = w(0);
[800c9da4 + 28] = w(0);
[800c9da4 + 2c] = w(0);
[800c9da4 + 30] = w(0);
[800c9da4 + 34] = w(0);
////////////////////////////////



////////////////////////////////
// funcc0d8c
[800c9da4 + 2c] = w(A0);
[800c9da4 + 30] = w(A1);
[800c9da4 + 34] = w(0);
////////////////////////////////



////////////////////////////////
// funcaa0c8
// get unique id of tileset file
A0 = w[A0 + 24];
A1 = 3;
A2 = 000a0000; // field tiles and camera
A3 = 0;
func1c8b0;
return V0;
////////////////////////////////



////////////////////////////////
// funcbfce8
[800ca068 + 0] = w(60);
[800ca068 + 4] = w(0);
[800ca068 + 8] = w(0);
[800ca068 + c] = w(0);
[800ca068 + 10] = w(0);
[800ca068 + 14] = w(0);
[800ca068 + 18] = w(0);
[800ca068 + 1c] = w(w[800c9da4 + 14]);
[800ca068 + 20] = w(w[800c9da4 + 4]);
[800ca068 + 24] = w(0);
[800ca068 + 28] = w(0);
[800ca068 + 2c] = w(0);
[800ca068 + 74] = b(40);
[800ca068 + 75] = b(0);
[800ca068 + 76] = h(144);
[800ca068 + 78] = w(e10);
[800ca068 + 9c] = h(0);
[800ca068 + a0] = b(0);
[800ca068 + a1] = b(ff);
[800ca068 + a2] = b(ff);
[800ca068 + a3] = b(ff);
[800ca068 + a4] = w(0);








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
// funcbded4
S3 = A0;
tileset_file = w[800c9da4 + 10];
FP = A1;

A0 = bu[800ca068 + 75]; // camera id
funcc0bcc;





[800c9da4 + 1c] = w(S3);

camera_offset = A2 = tileset_file + w[tileset_file + 18] + bu[800ca068 + 75] * 34;
[800ca068 + a4] = h((h[A2 + 28] + h[A2 + 2a]) / 2);
[800ca068 +  4] = h((h[A2 + 28] + h[A2 + 2a]) / 2);

[800ca068 + a6] = h((h[A2 + 2c] + h[A2 + 2e]) / 2);
[800ca068 +  6] = h((h[A2 + 2c] + h[A2 + 2e]) / 2);

[tileset_file + 30] = h(hu[tileset_file + 24] - ((h[A2 + 28] + h[A2 + 2a]) / 2) + a0);

number_of_blocks = hu[tileset_file + 6];


V1 = hu[800ca068 + 6] - 70;
[tileset_file + 32] = h(hu[tileset_file + 26] - V1);


A1 = number_of_blocks * 3;

V0 = A1 >> 2;
V0 = V0 << 2;

// if not четное
if( V0 != A1 )
{
    loopbdfd8:	; 800BDFD8
        A1 = A1 + 1;
        V0 = A1 >> 2;
        V0 = V0 << 2;
    800BDFE0	bne    v0, a1, loopbdfd8 [$800bdfd8]
}

[800c9da4 + 20] = w(S3 + A1);

A1 = A1 + number_of_blocks;

loopbdffc:	; 800BDFFC
    V0 = A1 << 2;
    V0 = V0 >> 2;
    A1 = A1 + 1;
800BE004	bne    v0, a1, loopbdffc [$800bdffc]

A1 = A1 - 1;
[FP] = w(S3 + A1); // start of background packets


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



if( number_of_blocks != 0 )
{
    S0 = 0;
    tile_block = tileset_file + w[tileset_file + 10];

    loopbe088:	; 800BE088
        V0 = w[800c9da4 + 1c];
        [V0 + S0 * 3 + 0] = b(80);
        [V0 + S0 * 3 + 1] = b(80);
        [V0 + S0 * 3 + 2] = b(80);

        A0 = tile_block + S0 * 38; // tile_block_data
        V0 = w[800c9da4 + 20] + S0;
        [V0] = b(0);
        A1 = w[FP]; // packets
        A2 = FP; // end_of_packets
        field_init_background_packets;

        if( V0 != 1 )
        {
            return 0;
        }

        [tile_block + S0 * 38 + 10] = h(-8000);
        [tile_block + S0 * 38 + 12] = h(7fff);
        [tile_block + S0 * 38 + 14] = h(-8000);
        [tile_block + S0 * 38 + 16] = h(7fff);

        S0 = S0 + 1;
        V0 = S0 < number_of_blocks;
    800BE0FC	bne    v0, zero, loopbe088 [$800be088]
}

[800ca068 + 72] = b(0);
[800ca068 + 73] = b(0);
[800ca068 + 0] = w(w[800ca068 + 0] & fffff3ff);

return 1;
////////////////////////////////



////////////////////////////////
// funcc0bcc
camera_id = A0;
tileset_file = w[800c9da4 + 10];
camera_offset = w[tileset_file + 18];
A2 = w[800ca068 + 20];
[A2 + 0] = h(hu[tileset_file + camera_offset + camera_id * 34 + 0]);

H = hu[tileset_file + camera_offset + camera_id * 34 + 0]; // Projection plane distance

A2 = w[800ca068 + 1c];
[A2 + 0] = h(hu[tileset_file + camera_offset + camera_id * 34 + 2]); // R11
[A2 + 2] = h(hu[tileset_file + camera_offset + camera_id * 34 + 4]); // R12
[A2 + 4] = h(hu[tileset_file + camera_offset + camera_id * 34 + 6]); // R13
[A2 + 6] = h(hu[tileset_file + camera_offset + camera_id * 34 + 8]); // R21
[A2 + 8] = h(hu[tileset_file + camera_offset + camera_id * 34 + a]); // R22
[A2 + a] = h(hu[tileset_file + camera_offset + camera_id * 34 + c]); // R23
[A2 + c] = h(hu[tileset_file + camera_offset + camera_id * 34 + e]); // R31
[A2 + e] = h(hu[tileset_file + camera_offset + camera_id * 34 + 10]); // R32
[A2 + 10] = h(hu[tileset_file + camera_offset + camera_id * 34 + 12]); // R33
[A2 + 14] = w(w[tileset_file + camera_offset + camera_id * 34 + 14]); // TX
[A2 + 18] = w(w[tileset_file + camera_offset + camera_id * 34 + 18]); // TY
[A2 + 1c] = w(w[tileset_file + camera_offset + camera_id * 34 + 1c]); // TZ
[tileset_file + 2a] = h(hu[tileset_file + camera_offset + camera_id * 34 + 2a]);
[tileset_file + 2e] = h(hu[tileset_file + camera_offset + camera_id * 34 + 2e]);
[800ca068 + 75] = b(camera_id);

[800ca068 + 0] = w(w[800ca068 + 0] | 00000080);

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
V0 = w[V0 + 14];
[V0 + 30] = h(hu[tileset_file + camera_offset + camera_id * 34 + 30]);

return 1;
////////////////////////////////
