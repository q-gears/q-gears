////////////////////////////////
// funca89c4
// A0 = 46 at start of new game (before movie)
// A0 = 32 after start movie
// A0 = 34 next room - meeting with baku
// A0 = 64 start of alexandria
field_id = A0;
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
[80067948] = w(w[V0 + 4]);

funca9350; // set pointers in field structure

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
S4 = w[V0 + 14];

funca939c; // init field structure

func1cfb4; // unknown system thing. probably clearing or prepair of frame buffer

V1 = w[8006794c];
[V1 + 0] = w(w[V1 + 0] & fffffcf0);

A1 = w[V1 + 1c];
[A1 + 0] = w(w[A1 + 0] | 00000020);

V0 = w[V1 + 1c];
V1 = w[V0 + 8e4];
[V1 + 0] = w(w[V1 + 0] & 00000004);

A0 = 0;
A1 = 0;
A2 = 0;
func1ccb4; // reset 8006794c + 10 data (unknown)



[80073998] = w(w[80073998] & ffff0006);



S1 = 1;
loopa8ab4:	; 800A8AB4
    A1 = 3;
    loopa8ac0:	; 800A8AC0
        [800c9ef0 + S1 * 8 + A1 * 2] = h(0);
        [800c9ef0 + 10 + S1 * 8 + A1 * 2] = h(0);
        A1 = A1 - 1;
    800A8AD0	bgez   a1, loopa8ac0 [$800a8ac0]
    S1 = S1 - 1;
800A8ADC	bgez   s1, loopa8ab4 [$800a8ab4]




V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
[V0 + 8] = b(0);
[V0 + 9] = b(0);



funcaa4bc; // init 800c9f20 array with -1



V0 = w[8006794c];
V0 = w[V0 + 1c];
[V0 + c] = h(field_id);

[S4 + a] = h(field_id);

A0 = S4;
A1 = field_id;
funca9bdc; // we load textures here



A0 = S4;
A1 = field_id;
funca97d4; // maybe get pointer to script



A0 = S4;
A1 = field_id;
funca9814; // init pointer to file 0x1e type



A0 = S4;
funca9860; // we read tileset db pointer here









A0 = S4;
A1 = field_id;
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

A0 = 0900;
A1 = -1;
A2 = 0;
A3 = 0;
A4 = 0;

800A8BBC	jal    funcb0124 [$800b0124]

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
A1 = field_id;
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
800A8E24	lw     v0, $0000(a0)
800A8E28	addiu  v1, zero, $ffdf (=-$21)
800A8E2C	and    v0, v0, v1
800A8E30	sw     v0, $0000(a0)
////////////////////////////////



////////////////////////////////
// funca9350
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
A1 = w[V0 + c];

V1 = w[80067948];
[80067948] = w(V1 + 330);
[A1 + 14] = w(V1);
[V1 + 28] = w(V1 + 6c);
[V1 + 54] = w(V1 + 90);
[V1 + 58] = w(V1 + 270);
////////////////////////////////



////////////////////////////////
// funca939c
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
A0 = w[V0 + 14];

[A0 + 0] = w(0);
[A0 + 4] = w(0);
[A0 + 8] = b(0);
[A0 + 9] = b(0);
[A0 + a] = h(-1);
[A0 + c] = w(0);
[A0 + 10] = w(0);
[A0 + 14] = w(0);
[A0 + 18] = w(0);
[A0 + 1c] = w(0);
[A0 + 20] = w(0);
[A0 + 24] = w(0);
[A0 + 2c] = w(0);
[A0 + 30] = w(0);
[A0 + 34] = w(w[80067944] + 106700);
[A0 + 38] = h(00a0);
[A0 + 3a] = h(0070);
[A0 + 3c] = h(ffff);
[A0 + 3e] = h(ffff);
[A0 + 40] = b(0);
[A0 + 41] = b(0);
[A0 + 42] = b(0);
[A0 + 43] = b(0);
[A0 + 44] = w(0);
[A0 + 48] = b(0);
[A0 + 49] = b(0);
[A0 + 4a] = b(1);
[A0 + 4b] = b(0);
[A0 + 4c] = w(0);
[A0 + 50] = h(0);
[A0 + 52] = h(0);
[A0 + 5c] = b(7f);
[A0 + 5d] = b(7f);
[A0 + 5e] = b(0);
[A0 + 5f] = b(0);
[A0 + 60] = b(0);
[A0 + 61] = b(0);
[A0 + 62] = h(0);
[A0 + 64] = w(0);


A1 = 17;
loopa941c:	; 800A941C
    V0 = w[A0 + 54] + A1 * 14;
    [V0 + 0] = w(0);
    [V0 + 4] = b(-1);
    [V0 + 5] = b(0);
    [V0 + 6] = b(0);
    [V0 + 7] = b(0);
    [V0 + 8] = b(0);
    [V0 + 9] = b(0);
    [V0 + a] = b(0);
    [V0 + b] = b(0);
    [V0 + c] = b(0);
    [V0 + d] = b(0);
    [V0 + e] = b(0);
    [V0 + f] = b(0);
    [V0 + 10] = w(0);
    A1 = A1 - 1;
800A9468	bgez   a1, loopa941c [$800a941c]



A1 = 0;
loopa94b8:	; 800A94B8
    V1 = w[A0 + 28] + A1 * 4;
    [V1] = w(0);
    A1 = A1 + 1;
    V0 = A1 < 9;
800A94CC	bne    v0, zero, loopa94b8 [$800a94b8]



A1 = f;
loopa9500:	; 800A9500
    V0 = w[A0 + 58] + A1 * c;
    [V0 + 0] = b(ff);
    [V0 + 1] = b(0);
    [V0 + 2] = h(ffff);
    [V0 + 4] = h(ffff);
    [V0 + 6] = h(-1)
    [V0 + 8] = h(ffff);
    [V0 + a] = h(ffff);
    A1 = A1 - 1;
800A9528	bgez   a1, loopa9500 [$800a9500]



A1 = 3;
loopa9558:	; 800A9558
    [A0 + 68 + A1] = b(0);
    A1 = A1 - 1;
800A9560	bgez   a1, loopa9558 [$800a9558]
////////////////////////////////



////////////////////////////////
// funcaa4bc
V1 = f;
V0 = ;
V0 = V0 + 3c;

loopaa4d0:	; 800AA4D0
    [800c9f20 + V1 * 4] = w(-1);
    V1 = V1 - 1;
    V0 = V0 - 4;
800AA4D8	bgez   v1, loopaa4d0 [$800aa4d0]
////////////////////////////////



////////////////////////////////
// funca9bdc
field_struct = A0;
field_id = A1;

pointer = w[8006794c];
pointer1c = w[pointer + 1c];
V0 = w[pointer1c + 808];

V1 = w[80067948];
S0 = V0 << b;
V0 = V1 + S0;
if( 801ddf00 - V0 <= 16fff )
{
    S0 = 801d6f00 - V1;
    V0 = S0;

    if( S0 < 0 )
    {
        V0 = S0 + 7ff;
    }

    S0 = (V0 >> b) << b;
}



// a lot of field loading
S1 = 00050000 | field_id;

A0 = S1;
func220e8; // maybe field loading.

if( V0 != 0 )
{
    A0 = S1;
    func21e5c;

    [pointer1c + 854 +  4] = w(w[V0 + 1c]);
    [pointer1c + 854 + 10] = w(w[V0 + c]);
    [pointer1c + 854 + 20] = w(w[V0 + 8] + w[V0 + c]);

    A1 = w[V0 + 8];
    A2 = w[V0 + c];
    A3 = 0;
    func1daa4;

    A0 = S1;
    800A9CD8	jal    func22390 [$80022390]

    A0 = 0;
    800A9CE0	jal    func130a4 [$800130a4]
}
else
{
    [pointer1c + 854 +  0] = w(w[pointer1c + 800]);
    [pointer1c + 854 +  4] = w(w[pointer1c + 808] << b);
    [pointer1c + 854 +  8] = w(w[80067948]);
    [pointer1c + 854 +  c] = w(0);
    [pointer1c + 854 + 10] = w(S0);
    [pointer1c + 854 + 14] = w(0);
    [pointer1c + 854 + 18] = w(w[pointer1c + 808] << b);
    [pointer1c + 854 + 1c] = w(1);
    [pointer1c + 854 + 20] = w(w[80067948]);

    loopa9d24:	; 800A9D24
        A0 = pointer1c + 854;
        800A9D30	jal    func217c4 [$800217c4]
    800A9D38	bne    v0, zero, loopa9d24 [$800a9d24]
}



A0 = w[pointer1c + 874];
funcac67c;



field_file = w[80067948];



A0 = field_file;
A1 = 4;
A2 = 140000;
A3 = 0;
func1c8b0; // address of file with identificator 0 in resource file type 14
[pointer1c + 7e4] = w(V0);



A0 = field_file;
A1 = 2;
A2 = 1b0000;
A3 = 0;
func1c8b0; // address of file with index 0 in resource file type 1b
S1 = V0;



if( S1 != 0 )
{
    A0 = field_file;
    A1 = 5;
    A2 = 1b0000;
    A3 = 0;
    func1c8b0; // size of file with identificator 0 in resource file type 1b

    T0 = w[pointer1c + 854 + 10];

    if( w[80067948] + T0 < S1 + V0 )
    {

        [pointer1c + 854 + 0] = w(w[pointer1c + 800]);
        [pointer1c + 854 + 4] = w(w[pointer1c + 808] << b);
        [pointer1c + 854 + 8] = w(w[80067948] + T0);
        [pointer1c + 854 + c] = w(T0);
        [pointer1c + 854 + 10] = w(S0 - w[pointer1c + 854 + 10]);
        [pointer1c + 854 + 14] = w(0);
        [pointer1c + 854 + 18] = w(w[pointer1c + 808] << b);
        [pointer1c + 854 + 1c] = w(1);
        [pointer1c + 854 + 20] = w(w[80067948] + T0);

        loopa9e08:	; 800A9E08
            A0 = pointer1c + 854;
            800A9E14	jal    func217c4 [$800217c4]
        800A9E1C	bne    v0, zero, loopa9e08 [$800a9e08]

        [pointer1c + 854 + 10] = w(w[pointer1c + 854 + 10] + T0);

        A0 = w[pointer1c + 854 + 20];
        funcac67c;
    }

    A0 = S1;
    A1 = 1;
    A2 = 40000;
    A3 = 0;
    func1c8b0; // get number of texture files.

    S0 = V0 - 1;
    if( S0 >= 0 )
    {
        loopa9e80:	; 800A9E80
            A0 = S1;
            A1 = 2;
            A2 = 40000 | (S0 & ffff);
            A3 = 0;
            func1c8b0; // get addresses of tim files

            if( V0 != -1 )
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
    func1c8b0; // get number of files of resource type 17 (sprites)

    S0 = V0 - 1;
    if( S0 >= 0 )
    {
        loopa9ed4:	; 800A9ED4
            A0 = S1;
            A1 = 2;
            A2 = 170000 | (S0 & ffff);
            A3 = 0;
            func1c8b0; // get addresses of 17 type files

            if( V0 != -1 )
            {
                A0 = V0;
                funcc9968; // load sprites textures data
            }

            S0 = S0 - 1;
        800A9F00	bgez   s0, loopa9ed4 [$800a9ed4]
    }

    A0 = 0;
    800A9F08	jal    func130a4 [$800130a4]
}



A0 = field_file;
A1 = 2;
A2 = 1b0001;
A3 = 0;
func1c8b0; // address of file with index 1 in resource file type 1b

[field_struct + 24] = w(V0);



A0 = S1;
A1 = V0;
S0 = field_file + w[pointer1c + 854 + 10] - A1;
A2 = S0;
A3 = 0;
func1daa4;

A0 = 0;
800A9F58	jal    func130a4 [$800130a4]

[field_struct + 24] = w(S1);



A1 = w[pointer1c + 854 + 10];
V0 = w[pointer1c + 854 + 4];

if( A1 < V0 )
{
    [pointer1c + 854 +  0] = w(w[pointer1c + 800]);
    [pointer1c + 854 +  4] = w(w[pointer1c + 8] << b);
    [pointer1c + 854 +  8] = w(S1 + S0);
    [pointer1c + 854 +  c] = w(A1);
    [pointer1c + 854 + 10] = w(-1);
    [pointer1c + 854 + 14] = w(0);
    [pointer1c + 854 + 18] = w(w[pointer1c + 8] << b);
    [pointer1c + 854 + 1c] = w(1);
    [pointer1c + 854 + 20] = w(S1 + S0);

    loopa9fb0:	; 800A9FB0
        A0 = w[pointer + 1c] + 854;
        800A9FBC	jal    func217c4 [$800217c4]
    800A9FC4	bne    v0, zero, loopa9fb0 [$800a9fb0]
}



A0 = w[field_struct + 24];
A1 = 0;
800A9FD0	jal    func1c750 [$8001c750]



A0 = w[field_struct + 24];
800A9FDC	jal    func1ca70 [$8001ca70]

[80067948] = w(V0 + w[field_struct + 24]);



return 0;
////////////////////////////////



////////////////////////////////
// funcac67c
A1 = 9;
loopac68c:	; 800AC68C
    if( w[800c9ccc + A1 * c + 4] != 0 && w[800c9ccc + A1 * c + 4] <= A0 )
    {
        [800c9ccc + A1 * c + 4] = w(0);
        [800c9ccc + A1 * c + 8] = w(0);
    }
    A1 = A1 - 1;
800AC6B0	bgez   a1, loopac68c [$800ac68c]
////////////////////////////////



////////////////////////////////
// funcc9968
// load sprites textures data
sprites = A0 + w[A0 + 0];
something2 = A0 + w[A0 + 4];
S5 = A0 + w[sprites + 0];

number_of_something2 = w[A0 + 8];
if( number_of_something2 > 0 )
{
    S2 = 0;
    loopc99b4:	; 800C99B4
        [SP + 10] = h(hu[something2 + 0]);
        [SP + 12] = h(hu[something2 + 2]);
        [SP + 14] = h(hu[something2 + 4]);
        [SP + 16] = h(hu[something2 + 6]);

        something2 = something2 + 8;

        A0 = SP + 10;
        A1 = something2;
        func13350;

        something2 = something2 + (h[SP + 14] * h[SP + 16]) * 2;

        S2 = S2 + 1;
        V0 = S2 < number_of_something2;
    800C9A14	bne    v0, zero, loopc99b4 [$800c99b4]
}



number_of_sprites = w[sprites + 4];
S3 = sprites + 8;
if( number_of_sprites > 0 )
{
    S2 = 0;
    loopc9a30:	; 800C9A30
        [SP + 10] = h(hu[S3 + 0]);
        [SP + 12] = h(hu[S3 + 2]);
        [SP + 14] = h(hu[S3 + 4]);
        [SP + 16] = h(hu[S3 + 6]);

        A0 = SP + 10;
        A1 = S5;
        func13350;

        S3 = S3 + 8;
        S5 = S5 + h[SP + 14] * h[SP + 16] * 2;

        S2 = S2 + 1;
        V0 = S2 < number_of_sprites;
    800C9A8C	bne    v0, zero, loopc9a30 [$800c9a30]
}
////////////////////////////////



////////////////////////////////
// funca97d4
S0 = A0;

A0 = 4;
A1 = 00050000 | (A1 & ffff);
A2 = 0;
func1c7fc; // address of file with identificator A2 & ffff in given resource.

[S0 + c] = w(V0);

return 0;
////////////////////////////////



////////////////////////////////
// funca9814
S0 = A0;

A0 = 4;
A1 = 001e0000 | A1 & ffff;
A2 = 0;
func1c7fc;

[S0 + 4c] = w(V0);

if( V0 != 0 )
{
    A0 = V0;
    800A9844	jal    func54a28 [$80054a28]
}

return 0;
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
