////////////////////////////////
// func34cd0
[80059674 + 00] = h(0);
[80059674 + 02] = h(0);
[80059674 + 0c] = h(1);
[80059674 + 1c] = w(A0);
[80059674 + 28] = w(80059704);
[80059674 + 68] = b(1);
[80059674 + 69] = b(64);
[80059674 + 6a] = b(0);
[80059674 + 6c] = b(0);
[80059674 + e8] = h(0);

[800596f8] = h(0);
[80059684] = h(0);


[800596a0] = w(A1);
A2 = A2 | 1;
[80059674 + 0a] = h(A2);
[80059674 + 08] = h((A2 << 10) >> e);
A3 = A2 + 3;
[80059686] = h(A3);
A3 = A3 & 1;
[80059674 + ea] = b(A3);

A0 = 80059674;
func33c14;

V0 = w[8005969c];
return h[V0 + 58] * 4;
////////////////////////////////



////////////////////////////////
// func33c14
S0 = A0;

V1 = h[S0 + 00]; // +18
V0 = h[S0 + 0a]; // +22 - total symbols???
S3 = bu[S0 + 69]; // +81

if (V0 < V1)
{
    V0 = hu[S0 + 2];
    A0 = h[S0 + c];
    [S0 + 0] = h(0);
    80033C60	addiu  v0, v0, $0001
    80033C64	sh     v0, $0002(s0)
    80033C68	lhu    v0, $0018(s0)
    80033C6C	lh     v1, $0002(s0)
    80033C70	addiu  v0, v0, $0001
    80033C74	slt    v1, v1, a0
    80033C78	bne    v1, zero, L33c90 [$80033c90]
    80033C7C	sh     v0, $0018(s0)
    80033C80	lhu    v0, $0010(s0)
    80033C84	sh     zero, $0002(s0)
    80033C88	ori    v0, v0, $0001
    80033C8C	sh     v0, $0010(s0)

    L33c90:	; 80033C90
    80033C90	lhu    v0, $0010(s0)
    80033C94	nop
    80033C98	andi   v0, v0, $0001
    80033C9C	beq    v0, zero, L33cec [$80033cec]
    80033CA0	nop
    80033CA4	lh     v1, $0016(s0)
    80033CA8	nop
    80033CAC	sll    v0, v1, $01
    80033CB0	addu   v0, v0, v1
    80033CB4	lw     v1, $0028(s0)
    80033CB8	sll    v0, v0, $05
    80033CBC	addu   v0, v0, v1
    80033CC0	sh     zero, $0058(v0)
    80033CC4	lhu    v0, $0016(s0)
    80033CC8	lh     v1, $000c(s0)
    80033CCC	addiu  v0, v0, $0001
    80033CD0	sh     v0, $0016(s0)
    80033CD4	sll    v0, v0, $10
    80033CD8	sra    v0, v0, $10
    80033CDC	slt    v0, v0, v1
    80033CE0	bne    v0, zero, L33cec [$80033cec]
    80033CE4	nop
    80033CE8	sh     zero, $0016(s0)

    L33cec:	; 80033CEC
    80033CEC	lh     v0, $000c(s0)
    80033CF0	lh     v1, $0018(s0)
    80033CF4	addiu  v0, v0, $0001
    80033CF8	div    v1, v0
    80033CFC	mfhi   a3
    80033D00	lh     t0, $0002(s0)
    80033D04	lw     a2, $0028(s0)
    80033D08	lbu    a0, $000e(s0)
    80033D0C	sll    a1, t0, $01
    80033D10	addu   a1, a1, t0
    80033D14	sll    a1, a1, $05
    80033D18	addu   a2, a1, a2
    80033D1C	srl    v1, a3, $1f
    80033D20	addu   v1, a3, v1
    80033D24	sra    v1, v1, $01
    80033D28	sll    v0, v1, $01
    80033D2C	addu   v0, v0, v1
    80033D30	sll    v0, v0, $02
    80033D34	addu   v0, v0, v1
    80033D38	addu   v0, v0, a0
    80033D3C	sb     v0, $005c(a2)
    80033D40	lw     v0, $0028(s0)
    80033D44	nop
    80033D48	addu   a1, a1, v0
    80033D4C	andi   v0, a3, $0001

    L33d50:	; 80033D50
    80033D50	beq    v0, zero, L33d68 [$80033d68]
    80033D54	nop
    80033D58	lui    v0, $8006
    80033D5C	lhu    v0, $8ab0(v0)
    80033D60	j      L33d78 [$80033d78]
    80033D64	sh     v0, $005e(a1)

    L33d68:	; 80033D68
    80033D68	lui    v0, $8006
    80033D6C	lhu    v0, $8c70(v0)
    80033D70	nop
    80033D74	sh     v0, $005e(a1)

    L33d78:	; 80033D78
    80033D78	sll    a1, t0, $01
    80033D7C	addu   a1, a1, t0
    80033D80	sll    a1, a1, $05
    80033D84	lw     v0, $0028(s0)
    80033D88	andi   v1, a3, $0001
    80033D8C	addu   v0, a1, v0
    80033D90	sb     v1, $005a(v0)
    80033D94	srl    v1, a3, $1f
    80033D98	addu   v1, a3, v1
    80033D9C	lw     v0, $0028(s0)
    80033DA0	sra    v1, v1, $01
    80033DA4	addu   v0, a1, v0
    80033DA8	sb     a3, $005b(v0)
    80033DAC	lw     v0, $0028(s0)
    80033DB0	lhu    a0, $000e(s0)
    80033DB4	addu   a1, a1, v0
    80033DB8	sll    v0, v1, $01
    80033DBC	addu   v0, v0, v1
    80033DC0	sll    v0, v0, $02
    80033DC4	addu   v0, v0, v1
    80033DC8	addu   a0, a0, v0
    80033DCC	sh     a0, $0052(a1)
}

S3 = S3 - 1;

if (bu[S0 + 6c] != 0) // +84
{
    80033DE0	lhu    v0, $0010(s0)
    80033DE4	sb     zero, $006c(s0)
    80033DE8	andi   v0, v0, $fffb
    80033DF0	sh     v0, $0010(s0)
    return;
}

if (S3 != -1)
{
    L33e48:	; 80033E48
        A1 = w[S0 + 1c]; // +34
        character = bu[A1]; // read text data
        A3 = character;
        V1 = character;

        // close
        if (character == 0)
        {
            A0 = hu[S0 + 10]; // +28
            if (A0 & 0080)
            {
                [S0 + 10] = h(A0 & ff7f);
                [S0 + 1c] = w(w[S0 + 20] + 1); // +38
                80033E88	j      L343cc [$800343c8]
            }

            [S0 + 10] = h(A0 | 0008);
            [S0 + 6b] = b(1); // +83
            [S0 + 6c] = b(1); // +84

            return;
        }

        // wait
        if (character == 3)
        {
            [S0 + 6b] = b(3);

            [S0 + 10] = h(hu[S0 + 10] | 0008);

            [S0 + 1c] = w(w[S0 + 1c] + 1);

            return;
        }

        // special
        if (V1 == 0f)
        {
            V1 = bu[A1 + 1];

            switch (V1)
            {
                case 0: // wait
                {
                    V0 = w[S0 + 1c];
                    [S0 + 1c] = w(V0 + 3);
                    [S0 + 84] = h(bu[V0 + 2]);
                    return;
                }
                break;

                case 1: // accelerate
                {
                    V0 = w[S0 + 1c];
                    A3 = bu[V0 + 2];
                    if (A3 != 0)
                    {
                        [S0 + 6a] = b(bu[S0 + 68]);

                        [S0 + 68] = b(A3); // 80
                        [S0 + 69] = b(A3); // 81
                        S3 = S3 + A3;
                    }
                    else
                    {
                        [S0 + 68] = b(bu[S0 + 6a]);
                        [S0 + 69] = b(bu[S0 + 6a]);
                        [S0 + 6a] = b(0); // 82
                    }

                    [S0 + 1c] = w(w[S0 + 1c] + 3);
                    80033F50	j      L343cc [$800343c8]
                }
                break;

                case 2: // wait and close
                {
                    V0 = w[S0 + 1c];
                    [S0 + 1c] = w(V0 + 3);
                    [S0 + 6c] = b(1);
                    [S0 + 84] = h(bu[V0 + 2]);
                    return;
                }
                break;

                case 3: // not used
                {
                    80033F7C	lw     v0, $001c(s0)
                    80033F80	lui    v1, $8006
                    80033F84	lw     v1, $89fc(v1)
                    80033F88	lbu    a3, $0002(v0)
                    80033F8C	lbu    a1, $0003(v0)
                    80033F90	addiu  v0, v0, $0003
                    80033F94	sw     v0, $001c(s0)
                    80033F98	sll    v0, a3, $02
                    80033F9C	addu   v0, v0, v1
                    80033FA0	lw     a0, $0000(v0)
                    80033FA4	j      L34298 [$80034298]
                    80033FA8	addiu  s3, s3, $0001
                }
                break;

                case 4: // used for item
                {
                    80033FAC	lw     v0, $001c(s0)
                    80033FB0	lh     v1, $0080(s0)
                    80033FB4	addiu  v0, v0, $0001
                    80033FB8	addu   a1, v1, zero
                    80033FBC	andi   v1, v1, $ff00
                    80033FC0	sw     v0, $001c(s0)
                    80033FC4	ori    v0, zero, $0200
                    80033FC8	beq    v1, v0, L3403c [$8003403c]
                    80033FCC	slti   v0, v1, $0201
                    80033FD0	beq    v0, zero, L33ff0 [$80033ff0]
                    80033FD4	nop
                    80033FD8	beq    v1, zero, L3400c [$8003400c]
                    80033FDC	ori    v0, zero, $0100
                    80033FE0	beq    v1, v0, L34024 [$80034024]
                    80033FE4	nop
                    80033FE8	j      L343cc [$800343cc]

                    L33ff0:	; 80033FF0
                    80033FF0	ori    v0, zero, $0300
                    80033FF4	beq    v1, v0, L34054 [$80034054]
                    80033FF8	ori    v0, zero, $0400
                    80033FFC	beq    v1, v0, L3406c [$8003406c]
                    80034000	nop
                    80034004	j      L343cc [$800343cc]

                    L3400c:	; 8003400C
                    8003400C	lui    v0, $8006
                    80034010	lw     v0, $89fc(v0)
                    80034014	nop
                    80034018	lw     a0, $0058(v0)
                    8003401C	j      L34298 [$80034298]
                    80034020	andi   a1, a1, $00ff

                    L34024:	; 80034024
                    80034024	lui    v0, $8006
                    80034028	lw     v0, $89fc(v0)
                    8003402C	nop
                    80034030	lw     a0, $005c(v0)
                    80034034	j      L34298 [$80034298]
                    80034038	andi   a1, a1, $00ff

                    L3403c:	; 8003403C
                    8003403C	lui    v0, $8006
                    80034040	lw     v0, $89fc(v0)
                    80034044	nop
                    80034048	lw     a0, $0044(v0)
                    8003404C	j      L34298 [$80034298]
                    80034050	andi   a1, a1, $00ff

                    L34054:	; 80034054
                    80034054	lui    v0, $8006
                    80034058	lw     v0, $89fc(v0)
                    8003405C	nop
                    80034060	lw     a0, $00cc(v0)
                    80034064	j      L34298 [$80034298]
                    80034068	andi   a1, a1, $00ff

                    L3406c:	; 8003406C
                    8003406C	lui    v0, $8006
                    80034070	lw     v0, $89fc(v0)
                    80034074	nop
                    80034078	lw     a0, $00c8(v0)
                    8003407C	j      L34298 [$80034298]
                    80034080	andi   a1, a1, $00ff
                }
                break;

84400380 5
            80034084	lw     v0, $001c(s0)
            80034088	nop
            8003408C	lbu    a3, $0002(v0)
            80034090	addiu  v0, v0, $0002
            80034094	sw     v0, $001c(s0)
            80034098	andi   v1, a3, $ffff
            8003409C	sltiu  v0, v1, $0080
            800340A0	bne    v0, zero, L340e4 [$800340e4]
            800340A4	addu   a0, s0, zero
            800340A8	lui    at, $8007
            800340AC	addu   at, at, v1
            800340B0	lbu    v1, $e978(at)
            800340B4	ori    v0, zero, $00ff
            800340B8	bne    v1, v0, L340e8 [$800340e8]
            800340BC	sll    a1, v1, $02
            800340C0	lui    v0, $8006
            800340C4	lw     v0, $89fc(v0)
            800340C8	nop
            800340CC	lw     a0, $0068(v0)
            800340D0	jal    func3354c [$8003354c]
            800340D4	addu   a1, zero, zero
            800340D8	addu   a0, s0, zero
            800340DC	j      L340fc [$800340fc]
            800340E0	addu   a1, v0, zero

            L340e4:	; 800340E4
            800340E4	sll    a1, v1, $02

            L340e8:	; 800340E8
            800340E8	addu   a1, a1, v1
            800340EC	sll    a1, a1, $02
            800340F0	lui    v0, $8007
            800340F4	addiu  v0, v0, $ccc4 (=-$333c)
            800340F8	addu   a1, a1, v0

            L340fc:	; 800340FC
            800340FC	jal    func33bf8 [$80033bf8]
            80034100	addiu  s3, s3, $0001
            80034104	j      L343cc [$800343cc]
0C410380 6
            8003410C	addiu  s3, s3, $0001
            80034110	lw     v0, $001c(s0)
            80034114	lui    v1, $8006
            80034118	lw     v1, $89fc(v1)
            8003411C	lbu    a3, $0002(v0)
            80034120	addiu  v0, v0, $0002
            80034124	sw     v0, $001c(s0)
            80034128	lw     a0, $005c(v1)
            8003412C	j      L34298 [$80034298]
            80034130	addu   a1, a3, zero

                case 7:
                {
                    80034134	addiu  s3, s3, $0001
                    80034138	lw     v0, $001c(s0)
                    8003413C	lui    v1, $8006
                    80034140	lw     v1, $89fc(v1)
                    80034144	lbu    a3, $0002(v0)
                    80034148	addiu  v0, v0, $0002
                    8003414C	sw     v0, $001c(s0)
                    80034150	lw     a0, $0060(v1)
                    80034154	j      L34298 [$80034298]
                    80034158	addu   a1, a3, zero
                }
                break;

                case 8:
                {
                    8003415C	addiu  s3, s3, $0001
                    80034160	lw     v0, $001c(s0)
                    80034164	lui    v1, $8006
                    80034168	lw     v1, $89fc(v1)
                    8003416C	lbu    a3, $0002(v0)
                    80034170	addiu  v0, v0, $0002
                    80034174	sw     v0, $001c(s0)
                    80034178	lw     a0, $0064(v1)
                    8003417C	j      L34298 [$80034298]
                    80034180	addu   a1, a3, zero
                }
                break;

                case 9: // use for variable from script
                {
                    A1 = 0;
                    A2 = 0;
                    V0 = w[S0 + 1c];
                    A3 = bu[V0 + 2];
                    [S0 + 1c] = w(V0 + 2);
                    A0 = w[S0 + 70 + A3 * 4]; // +88 +8c +90 +94
                    S3 = S3 + 1;
                    func33b14;

                    A0 = S0;
                    A1 = 80059780;
                    func33bf8;

                    800341FC	j      L343cc [$800343cc]
                }
                break;

                case a: // use for variable from script
                {
                    A1 = 1;
                    A2 = 0;
                    V0 = w[S0 + 1c];
                    A3 = bu[V0 + 2];
                    [S0 + 1c] = w(V0 + 2);
                    A0 = w[S0 + 70 + A3 * 4]; // +88 +8c +90 +94
                    S3 = S3 + 1;
                    func33b14;

                    A0 = S0;
                    A1 = 80059780;
                    func33bf8;

                    800341FC	j      L343cc [$800343cc]
                }
                break;

                case b:
                {
                    800341A4	lw     v0, $001c(s0)
                    800341A8	lw     v1, $001c(s0)
                    800341AC	lbu    v0, $0002(v0)
                    800341B0	addiu  v1, v1, $0002
                    800341B4	sw     v1, $001c(s0)
                    800341B8	j      L343cc [$800343c8]
                    800341BC	sb     v0, $006d(s0)
                }

                case c: // use for variable from script
                {
                    A1 = 1;
                    A2 = 1;
                    V0 = w[S0 + 1c];
                    A3 = bu[V0 + 2];
                    [S0 + 1c] = w(V0 + 2);
                    A0 = w[S0 + 70 + A3 * 4]; // +88 +8c +90 +94
                    S3 = S3 + 1;
                    func33b14;

                    A0 = S0;
                    A1 = 80059780;
                    func33bf8;

                    800341FC	j      L343cc [$800343cc]
                }
                break;

                case d: // wait and close.. and something???
                {
                    V1 = w[S0 + 1c];
                    [S0 + 1c] = w(V1 + 3);

                    [S0 + 10] = h(hu[S0 + 10] | 0200);
                    [S0 + 6c] = b(1);
                    [S0 + 84] = h(bu[V0 + 2]);
                    return;
                }
                break;

                case e:
                {
                    // set normal speed
                    [S0 + 6a] = b(bu[S0 + 68]);
                    [S0 + 68] = b(1);
                    [S0 + 69] = b(1);

                    V1 = w[S0 + 1c];
                    [S0 + 1c] = w(V1 + 3);
                    [S0 + 86] = h(bu[V1 + 2]); // 9e
                    [S0 + 88] = h(bu[V1 + 2]);
                    return;
                }
                break;

68420380 f
            80034268	lw     v0, $001c(s0)
            8003426C	lui    v1, $8006
            80034270	lw     v1, $89fc(v1)
            80034274	lbu    a3, $0002(v0)
            80034278	addiu  v0, v0, $0002
            8003427C	sw     v0, $001c(s0)
            80034280	lw     a0, $00c4(v1)
            80034284	andi   v0, a3, $ffff
            80034288	lui    at, $8005
            8003428C	addu   at, at, v0
            80034290	lbu    a1, $f8d8(at)
            80034294	addiu  s3, s3, $0001

            L34298:	; 80034298
            80034298	jal    func3354c [$8003354c]
            8003429C	addiu  s3, s3, $ffff (=-$1)
            800342A0	addu   a0, s0, zero
            800342A4	jal    func33bf8 [$80033bf8]
            800342A8	addu   a1, v0, zero
            800342B0	addiu  v0, zero, $ffff (=-$1)
            800343D0	bne    s3, v0, L33e48 [$80033e48]
            800343D4	nop
            return;
default:
            8003418C	j      L343cc [$800341cc]
        }

        // new
        if (V1 == 02)
        {
            [S0 + 6b] = b(02); // +83
            [S0 + 10] = h(hu[S0 + 10] | 0048);

            V1 = w[S0 + 1c];
            [S0 + 1c] = w(V1 + 1);

            if ([V1 + 1] == 1) // if there is new row after new window - skip it
            {
                V0 = V1 + 2;
                [S0 + 1c] = V0;
            }

            return;
        }

        // new row
        if (V1 == 1)
        {
            [S0 + 1c] = w(w[S0 + 1c] + 1);
            [S0 + 0] = h(64); // +18

            return;
        }



        // usual letter
        if (V1 < w[800589e8]) // 0xf8 here
        {
            A3 = 0;
            A1 = A0 & ff; // readed byte
            S5 = 1;
        }
        else
        {
            A1 = bu[A1 + 1]; read next byte
            S5 = 2;
        }

        S2 = A3 & ffff;
        S1 = A1 & ffff;

        A0 = S2; // 1st byte
        A1 = S1; // 2nd byte
        func34dbc;
        S4 = V0; // 3 usually, 2 rare

        T0 = h[S0 + 0]; // +18

        // need new row
        if (h[S0 + a] < T0 + V0) // +22
        {
            [S0 + 0] = h(T0 + S4);
            return;
        }

        V1 = h[S0 + 2]; // +1a
        V0 = w[S0 + 28]; // 40
        [SP + 10] = w(bu[V0 + V1 * 60 + 5a]);

        A0 = S2; // 1st byte
        A1 = S1; // 2nd byte
        A2 = w[S0 + 2c] + T0 * 2; // +44
        A3 = h[S0 + 12]; // + 2a
        func34e20;

        [S0 + 1c] = w(w[S0 + 1c] + S5); // increment pointer

        A0 = hu[S0 + 0] + S4;
        [S0 + 0] = h(A0);

        V1 = h[S0 + 2];        
        V0 = w[S0 + 28];
        [V0 + V1 * 60 + 58] = h(A0);

        L343cc:	; 800343CC
        S3 = S3 - 1;
    800343D0	bne    s3, -1, L33e48 [$80033e48]
}
////////////////////////////////



////////////////////////////////
// func34dbc
if (A0 == 0)
{
    if (A1 - w[80058a00] < w[800589f0]) // 10-4f
    {
        return 2;
    }
}
else if (A0 == w[800589e8]) // f8
{
    if (A1 < w[800589f4]) // 15
    {
        return 2;
    }
}

return 3;
////////////////////////////////



////////////////////////////////
// func34e20
T0 = A0;
T1 = w[SP + 10];
if (A0 == 0)
{
    80034E34	lui    v0, $8006
    80034E38	lw     v0, $8a00(v0)
    80034E3C	andi   v1, a1, $ffff
    80034E40	subu   v1, v1, v0
    80034E44	sll    v0, v1, $01
    80034E48	addu   v0, v0, v1
    80034E4C	sll    v0, v0, $02
    80034E50	subu   v0, v0, v1
    80034E54	lui    v1, $8006
    80034E58	lw     v1, $89f8(v1)
    80034E5C	sll    v0, v0, $01
    80034E64	addu   a0, v1, v0
}
else
{
    V0 = FF;
    80034E68	bne    a0, v0, L34e8c [$80034e8c]
    80034E6C	andi   v1, a1, $ffff
    80034E70	andi   v0, a1, $ffff
    80034E74	bne    v0, a0, L34e90 [$80034e90]
    80034E78	sll    v0, v1, $01
    80034E7C	lui    a0, $8005
    80034E80	addiu  a0, a0, $f874 (=-$78c)
    80034E84	j      L34ee0 [$80034ee0]
    80034E88	nop

    L34e8c:	; 80034E8C
    80034E8C	sll    v0, v1, $01

    L34e90:	; 80034E90
    80034E90	addu   v0, v0, v1
    80034E94	sll    v0, v0, $02
    80034E98	subu   v0, v0, v1
    80034E9C	sll    v0, v0, $01
    80034EA0	lui    a0, $8006
    80034EA4	lw     a0, $89f8(a0)
    80034EA8	lui    v1, $8006
    80034EAC	lw     v1, $89ec(v1)
    80034EB0	addu   a0, a0, v0
    80034EB4	addu   a0, a0, v1
    80034EB8	lui    v0, $8006
    80034EBC	lw     v0, $89e8(v0)
    80034EC0	andi   v1, t0, $ffff
    80034EC4	subu   v1, v1, v0
    80034EC8	sll    v0, v1, $01
    80034ECC	addu   v0, v0, v1
    80034ED0	sll    v0, v0, $02
    80034ED4	subu   v0, v0, v1
    80034ED8	sll    v0, v0, $09
    80034EDC	addu   a0, a0, v0
}

L34ee0:	; 80034EE0
80034EE0	bne    t1, zero, L351d0 [$800351d0]
80034EE4	addu   t5, zero, zero
80034EE8	lhu    v0, $0000(a2)
80034EEC	lhu    v1, $0004(a2)
80034EF0	andi   v0, v0, $cccc
80034EF4	andi   v1, v1, $cccc
80034EF8	sh     v1, $0004(a2)
80034EFC	sll    v1, a3, $10
80034F00	sh     v0, $0000(a2)
80034F04	lhu    v0, $0002(a2)
80034F08	sra    v1, v1, $10
80034F0C	andi   v0, v0, $cccc
80034F10	sh     v0, $0002(a2)
80034F14	sll    v0, v1, $01
80034F18	addu   a2, a2, v0
80034F1C	addiu  t3, a2, $0004
80034F20	addu   t4, v0, zero
80034F24	addu   t1, a2, t4
80034F28	sll    v1, v1, $01
80034F2C	subu   t2, a2, v1
80034F30	lhu    v0, $0000(a2)
80034F34	lhu    v1, $0004(a2)
80034F38	andi   v0, v0, $cccc
80034F3C	sh     v0, $0000(a2)
80034F40	lhu    v0, $0002(a2)
80034F44	andi   v1, v1, $cccc
80034F48	sh     v1, $0004(a2)
80034F4C	andi   v0, v0, $cccc
80034F50	sh     v0, $0002(a2)

L34f54:	; 80034F54
80034F54	lhu    v0, $0000(t1)
80034F58	lhu    v1, $0004(t1)
80034F5C	andi   v0, v0, $cccc
80034F60	sh     v0, $0000(t1)
80034F64	lhu    v0, $0002(t1)
80034F68	andi   v1, v1, $cccc
80034F6C	sh     v1, $0004(t1)
80034F70	andi   v0, v0, $cccc
80034F74	sh     v0, $0002(t1)
80034F78	lhu    t0, $0000(a0)
80034F7C	nop
80034F80	andi   v0, t0, $0080
80034F84	sltu   v0, zero, v0
80034F88	subu   v0, zero, v0
80034F8C	andi   v1, v0, $0222
80034F90	andi   v0, t0, $0040
80034F94	beq    v0, zero, L34fa0 [$80034fa0]
80034F98	addiu  a0, a0, $0002
80034F9C	ori    v1, v1, $2220

L34fa0:	; 80034FA0
80034FA0	andi   v0, t0, $0020
80034FA4	beq    v0, zero, L34fb0 [$80034fb0]
80034FA8	andi   v0, t0, $0010
80034FAC	ori    v1, v1, $2200

L34fb0:	; 80034FB0
80034FB0	bne    v0, zero, L34fbc [$80034fbc]
80034FB4	ori    a1, v1, $2000
80034FB8	addu   a1, v1, zero

L34fbc:	; 80034FBC
80034FBC	lhu    v0, $0000(t2)
80034FC0	nop
80034FC4	or     v0, v0, a1
80034FC8	sh     v0, $0000(t2)
80034FCC	andi   v0, t0, $0080
80034FD0	sltu   v0, zero, v0
80034FD4	subu   v0, zero, v0
80034FD8	andi   a3, v0, $0212
80034FDC	lhu    v1, $0000(t1)
80034FE0	andi   v0, t0, $0040
80034FE4	or     v1, v1, a1
80034FE8	beq    v0, zero, L34ff4 [$80034ff4]
80034FEC	sh     v1, $0000(t1)
80034FF0	ori    a3, a3, $2120

L34ff4:	; 80034FF4
80034FF4	andi   v0, t0, $0020
80034FF8	beq    v0, zero, L35004 [$80035004]
80034FFC	addu   v1, a3, zero
80035000	ori    v1, v1, $1200

L35004:	; 80035004
80035004	lhu    a1, $0000(a2)
80035008	andi   v0, t0, $0010
8003500C	beq    v0, zero, L3501c [$8003501c]
80035010	ori    v0, a1, $2000
80035014	j      L35020 [$80035020]
80035018	or     v0, v0, v1

L3501c:	; 8003501C
8003501C	or     v0, a1, v1

L35020:	; 80035020
80035020	sh     v0, $0000(a2)
80035024	andi   v0, t0, $0008
80035028	bne    v0, zero, L35048 [$80035048]
8003502C	ori    v0, zero, $0222
80035030	andi   v0, t0, $0010
80035034	bne    v0, zero, L35044 [$80035044]
80035038	srl    v0, t0, $04
8003503C	j      L35048 [$80035048]
80035040	andi   v0, v0, $0002

L35044:	; 80035044
80035044	ori    v0, zero, $0022

L35048:	; 80035048
80035048	addu   v1, v0, zero
8003504C	andi   v0, t0, $0004
80035050	beq    v0, zero, L3505c [$8003505c]
80035054	andi   v0, t0, $0002
80035058	ori    v1, v1, $2220

L3505c:	; 8003505C
8003505C	beq    v0, zero, L35068 [$80035068]
80035060	andi   v0, t0, $0001
80035064	ori    v1, v1, $2200

L35068:	; 80035068
80035068	bne    v0, zero, L35074 [$80035074]
8003506C	ori    a1, v1, $2000
80035070	addu   a1, v1, zero

L35074:	; 80035074
80035074	lhu    v0, $0002(t2)
80035078	srl    v1, t0, $04
8003507C	or     v0, v0, a1
80035080	sh     v0, $0002(t2)
80035084	lhu    v0, $0002(t1)
80035088	nop
8003508C	or     v0, v0, a1
80035090	sh     v0, $0002(t1)
80035094	andi   v0, t0, $0010
80035098	beq    v0, zero, L350a4 [$800350a4]
8003509C	andi   v1, v1, $0002
800350A0	ori    v1, v1, $0021

L350a4:	; 800350A4
800350A4	andi   v0, t0, $0008
800350A8	beq    v0, zero, L350b4 [$800350b4]
800350AC	andi   v0, t0, $0004
800350B0	ori    v1, v1, $0212

L350b4:	; 800350B4
800350B4	beq    v0, zero, L350c0 [$800350c0]
800350B8	andi   v0, t0, $0002
800350BC	ori    v1, v1, $2120

L350c0:	; 800350C0
800350C0	beq    v0, zero, L350cc [$800350cc]
800350C4	nop
800350C8	ori    v1, v1, $1200

L350cc:	; 800350CC
800350CC	lhu    a1, $fffe(t3)
800350D0	andi   v0, t0, $0001
800350D4	beq    v0, zero, L350e4 [$800350e4]
800350D8	ori    v0, a1, $2000
800350DC	j      L350e8 [$800350e8]
800350E0	or     v0, v0, v1

L350e4:	; 800350E4
800350E4	or     v0, a1, v1

L350e8:	; 800350E8
800350E8	sh     v0, $fffe(t3)
800350EC	andi   v0, t0, $8000
800350F0	bne    v0, zero, L35108 [$80035108]
800350F4	ori    v0, zero, $0222
800350F8	andi   v0, t0, $0001
800350FC	bne    v0, zero, L35108 [$80035108]
80035100	ori    v0, zero, $0022
80035104	andi   v0, t0, $0002

L35108:	; 80035108
80035108	addu   v1, v0, zero
8003510C	andi   v0, t0, $4000
80035110	beq    v0, zero, L3511c [$8003511c]
80035114	andi   v0, t0, $2000
80035118	ori    v1, v1, $2220

L3511c:	; 8003511C
8003511C	beq    v0, zero, L35128 [$80035128]
80035120	andi   v0, t0, $1000
80035124	ori    v1, v1, $2200

L35128:	; 80035128
80035128	bne    v0, zero, L35134 [$80035134]
8003512C	ori    a1, v1, $2000
80035130	addu   a1, v1, zero

L35134:	; 80035134
80035134	lhu    v0, $0004(t2)
80035138	nop
8003513C	or     v0, v0, a1
80035140	sh     v0, $0004(t2)
80035144	lhu    v0, $0004(t1)
80035148	nop
8003514C	or     v0, v0, a1
80035150	sh     v0, $0004(t1)
80035154	andi   v0, t0, $0001
80035158	beq    v0, zero, L35164 [$80035164]
8003515C	andi   v1, t0, $0002
80035160	ori    v1, v1, $0021

L35164:	; 80035164
80035164	andi   v0, t0, $8000
80035168	beq    v0, zero, L35174 [$80035174]
8003516C	andi   v0, t0, $4000
80035170	ori    v1, v1, $0212

L35174:	; 80035174
80035174	beq    v0, zero, L35180 [$80035180]
80035178	andi   v0, t0, $2000
8003517C	ori    v1, v1, $2120

L35180:	; 80035180
80035180	beq    v0, zero, L3518c [$8003518c]
80035184	nop
80035188	ori    v1, v1, $1200

L3518c:	; 8003518C
8003518C	lhu    a1, $0000(t3)
80035190	andi   v0, t0, $1000
80035194	beq    v0, zero, L351a4 [$800351a4]
80035198	ori    v0, a1, $2000
8003519C	j      L351a8 [$800351a8]
800351A0	or     v0, v0, v1

L351a4:	; 800351A4
800351A4	or     v0, a1, v1

L351a8:	; 800351A8
800351A8	sh     v0, $0000(t3)
800351AC	addu   t3, t3, t4
800351B0	addu   t1, t1, t4
800351B4	addu   t2, t2, t4
800351B8	addiu  t5, t5, $0001
800351BC	slti   v0, t5, $000b
800351C0	bne    v0, zero, L34f54 [$80034f54]
800351C4	addu   a2, a2, t4
800351C8	j      L354b8 [$800354b8]
800351CC	nop

L351d0:	; 800351D0
800351D0	lhu    v0, $0000(a2)
800351D4	lhu    v1, $0004(a2)
800351D8	andi   v0, v0, $3333
800351DC	andi   v1, v1, $3333
800351E0	sh     v1, $0004(a2)
800351E4	sll    v1, a3, $10
800351E8	sh     v0, $0000(a2)
800351EC	lhu    v0, $0002(a2)
800351F0	sra    v1, v1, $10
800351F4	andi   v0, v0, $3333
800351F8	sh     v0, $0002(a2)
800351FC	sll    v0, v1, $01
80035200	addu   a2, a2, v0
80035204	addiu  t3, a2, $0004
80035208	addu   t4, v0, zero
8003520C	addu   t1, a2, t4
80035210	sll    v1, v1, $01
80035214	subu   t2, a2, v1
80035218	lhu    v0, $0000(a2)
8003521C	lhu    v1, $0004(a2)
80035220	andi   v0, v0, $3333
80035224	sh     v0, $0000(a2)
80035228	lhu    v0, $0002(a2)
8003522C	andi   v1, v1, $3333
80035230	sh     v1, $0004(a2)
80035234	andi   v0, v0, $3333
80035238	sh     v0, $0002(a2)

L3523c:	; 8003523C
8003523C	lhu    v0, $0000(t1)
80035240	lhu    v1, $0004(t1)
80035244	andi   v0, v0, $3333
80035248	sh     v0, $0000(t1)
8003524C	lhu    v0, $0002(t1)
80035250	andi   v1, v1, $3333
80035254	sh     v1, $0004(t1)
80035258	andi   v0, v0, $3333
8003525C	sh     v0, $0002(t1)
80035260	lhu    t0, $0000(a0)
80035264	nop
80035268	andi   v0, t0, $0080
8003526C	sltu   v0, zero, v0
80035270	subu   v0, zero, v0
80035274	andi   v1, v0, $0888
80035278	andi   v0, t0, $0040
8003527C	beq    v0, zero, L35288 [$80035288]
80035280	addiu  a0, a0, $0002
80035284	ori    v1, v1, $8880

L35288:	; 80035288
80035288	andi   v0, t0, $0020
8003528C	beq    v0, zero, L35298 [$80035298]
80035290	andi   v0, t0, $0010
80035294	ori    v1, v1, $8800

L35298:	; 80035298
80035298	bne    v0, zero, L352a4 [$800352a4]
8003529C	ori    a1, v1, $8000
800352A0	addu   a1, v1, zero

L352a4:	; 800352A4
800352A4	lhu    v0, $0000(t2)
800352A8	nop
800352AC	or     v0, v0, a1
800352B0	sh     v0, $0000(t2)
800352B4	andi   v0, t0, $0080
800352B8	sltu   v0, zero, v0
800352BC	subu   v0, zero, v0
800352C0	andi   a3, v0, $0848
800352C4	lhu    v1, $0000(t1)
800352C8	andi   v0, t0, $0040
800352CC	or     v1, v1, a1
800352D0	beq    v0, zero, L352dc [$800352dc]
800352D4	sh     v1, $0000(t1)
800352D8	ori    a3, a3, $8480

L352dc:	; 800352DC
800352DC	andi   v0, t0, $0020
800352E0	beq    v0, zero, L352ec [$800352ec]
800352E4	addu   v1, a3, zero
800352E8	ori    v1, v1, $4800

L352ec:	; 800352EC
800352EC	lhu    a1, $0000(a2)
800352F0	andi   v0, t0, $0010
800352F4	beq    v0, zero, L35304 [$80035304]
800352F8	ori    v0, a1, $8000
800352FC	j      L35308 [$80035308]
80035300	or     v0, v0, v1

L35304:	; 80035304
80035304	or     v0, a1, v1

L35308:	; 80035308
80035308	sh     v0, $0000(a2)
8003530C	andi   v0, t0, $0008
80035310	bne    v0, zero, L35330 [$80035330]
80035314	ori    v0, zero, $0888
80035318	andi   v0, t0, $0010
8003531C	bne    v0, zero, L3532c [$8003532c]
80035320	srl    v0, t0, $02
80035324	j      L35330 [$80035330]
80035328	andi   v0, v0, $0008

L3532c:	; 8003532C
8003532C	ori    v0, zero, $0088

L35330:	; 80035330
80035330	addu   v1, v0, zero
80035334	andi   v0, t0, $0004
80035338	beq    v0, zero, L35344 [$80035344]
8003533C	andi   v0, t0, $0002
80035340	ori    v1, v1, $8880

L35344:	; 80035344
80035344	beq    v0, zero, L35350 [$80035350]
80035348	andi   v0, t0, $0001
8003534C	ori    v1, v1, $8800

L35350:	; 80035350
80035350	bne    v0, zero, L3535c [$8003535c]
80035354	ori    a1, v1, $8000
80035358	addu   a1, v1, zero

L3535c:	; 8003535C
8003535C	lhu    v0, $0002(t2)
80035360	srl    v1, t0, $02
80035364	or     v0, v0, a1
80035368	sh     v0, $0002(t2)
8003536C	lhu    v0, $0002(t1)
80035370	nop
80035374	or     v0, v0, a1
80035378	sh     v0, $0002(t1)
8003537C	andi   v0, t0, $0010
80035380	beq    v0, zero, L3538c [$8003538c]
80035384	andi   v1, v1, $0008
80035388	ori    v1, v1, $0084

L3538c:	; 8003538C
8003538C	andi   v0, t0, $0008
80035390	beq    v0, zero, L3539c [$8003539c]
80035394	andi   v0, t0, $0004
80035398	ori    v1, v1, $0848

L3539c:	; 8003539C
8003539C	beq    v0, zero, L353a8 [$800353a8]
800353A0	andi   v0, t0, $0002
800353A4	ori    v1, v1, $8480

L353a8:	; 800353A8
800353A8	beq    v0, zero, L353b4 [$800353b4]
800353AC	nop
800353B0	ori    v1, v1, $4800

L353b4:	; 800353B4
800353B4	lhu    a1, $fffe(t3)
800353B8	andi   v0, t0, $0001
800353BC	beq    v0, zero, L353cc [$800353cc]
800353C0	ori    v0, a1, $8000
800353C4	j      L353d0 [$800353d0]
800353C8	or     v0, v0, v1

L353cc:	; 800353CC
800353CC	or     v0, a1, v1

L353d0:	; 800353D0
800353D0	sh     v0, $fffe(t3)
800353D4	andi   v0, t0, $8000
800353D8	bne    v0, zero, L353f8 [$800353f8]
800353DC	ori    v0, zero, $0888
800353E0	andi   v0, t0, $0001

L353e4:	; 800353E4
800353E4	bne    v0, zero, L353f4 [$800353f4]
800353E8	sll    v0, t0, $02
800353EC	j      L353f8 [$800353f8]
800353F0	andi   v0, v0, $0008

L353f4:	; 800353F4
800353F4	ori    v0, zero, $0088

L353f8:	; 800353F8
800353F8	addu   v1, v0, zero
800353FC	andi   v0, t0, $4000
80035400	beq    v0, zero, L3540c [$8003540c]
80035404	andi   v0, t0, $2000
80035408	ori    v1, v1, $8880

L3540c:	; 8003540C
8003540C	beq    v0, zero, L35418 [$80035418]
80035410	andi   v0, t0, $1000
80035414	ori    v1, v1, $8800

L35418:	; 80035418
80035418	bne    v0, zero, L35424 [$80035424]
8003541C	ori    a1, v1, $8000
80035420	addu   a1, v1, zero

L35424:	; 80035424
80035424	lhu    v0, $0004(t2)
80035428	sll    v1, t0, $02
8003542C	or     v0, v0, a1

L35430:	; 80035430
80035430	sh     v0, $0004(t2)
80035434	lhu    v0, $0004(t1)
80035438	nop
8003543C	or     v0, v0, a1
80035440	sh     v0, $0004(t1)
80035444	andi   v0, t0, $0001
80035448	beq    v0, zero, L35454 [$80035454]
8003544C	andi   v1, v1, $0008
80035450	ori    v1, v1, $0084

L35454:	; 80035454
80035454	andi   v0, t0, $8000
80035458	beq    v0, zero, L35464 [$80035464]
8003545C	andi   v0, t0, $4000
80035460	ori    v1, v1, $0848

L35464:	; 80035464
80035464	beq    v0, zero, L35470 [$80035470]
80035468	andi   v0, t0, $2000
8003546C	ori    v1, v1, $8480

L35470:	; 80035470
80035470	beq    v0, zero, L3547c [$8003547c]
80035474	nop
80035478	ori    v1, v1, $4800

L3547c:	; 8003547C
8003547C	lhu    a1, $0000(t3)
80035480	andi   v0, t0, $1000
80035484	beq    v0, zero, L35494 [$80035494]
80035488	ori    v0, a1, $8000
8003548C	j      L35498 [$80035498]
80035490	or     v0, v0, v1

L35494:	; 80035494
80035494	or     v0, a1, v1

L35498:	; 80035498
80035498	sh     v0, $0000(t3)
8003549C	addu   t3, t3, t4
800354A0	addu   t1, t1, t4
800354A4	addu   t2, t2, t4
800354A8	addiu  t5, t5, $0001
800354AC	slti   v0, t5, $000b
800354B0	bne    v0, zero, L3523c [$8003523c]
800354B4	addu   a2, a2, t4

L354b8:	; 800354B8
800354B8	jr     ra 
800354BC	nop
////////////////////////////////



////////////////////////////////
// func33b14
V1 = A0; // value

A1 = A1 << 4;

if (A2 != 0)
{
    if (V1 < 0)
    {
        V1 = -V1;
        A2 = a;
    }
    else
    {
        A2 = b;
    }
}

T0 = 0;
A3 = 3b9aca00; // 1 000 000 000
loop33b54:	; 80033B54
    V0 = V1 / A3;
    V1 = V1 % A3;

    A3 = A3 / a;

    [80059766 + T0 * 2] = h(V0 + A1);

    T0 = T0 + 1;
    V0 = T0 < a;
80033B84	bne    v0, zero, loop33b54 [$80033b54]




[8005977a] = h(ffff);
[80059764] = h(A1);

A0 = 80059764;
V0 = A1 & fff0;
if (V0 == A1)
{
    loop33bb4:	; 80033BB4
        if (A0 == 80059778)
        {
            break;
        }

        A0 = A0 + 2;
        V0 = hu[A0];
    80033BC8	beq    v0, a1, loop33bb4 [$80033bb4]
}

if (A2 != 0)
{
    A0 = A0 - 2;
    [A0] = h(A1 + A2);
}

func338e0;
////////////////////////////////



////////////////////////////////
// func33af4
V0 = hu[A0 + 10];
V0 = V0 & 0008;
if (V0 != 0)
{
    V0 = bu[A0 + 6b]; // 83
}

return 0;
////////////////////////////////