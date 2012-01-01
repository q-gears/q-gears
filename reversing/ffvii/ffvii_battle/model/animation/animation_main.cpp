////////////////////////////////////////////////////////
// funcc7c4c
// A0 = A0; // unit id
// A1 = w[A3 + 8] + 68; offset to first animation
// A2 = w[800f8384 + V0 * 4] + c;
// A3 = w[800f8384 + V0 * 4];
[SP + 18] = w(A1);
[SP + 20] = w(A2);
[SP + 28] = w(A3);

S3 = 1f800020;
A1 = A0;
FP = A0;
[1f800020] = b(1);
V0 = h[801518e6 + A1 * b9c];
T2 = w[SP + 18];
V0 = w[T2 + V0 * 4];
[1f800024] = w(V0);
V0 = hu[801518e6 + A1 * b9c];
switch (V0)
{
    case 2e: [1f800024] = w(800eeaa0); break;
    case 2f: [1f800024] = w(800eeab0); break;
    case 30: [1f800024] = w(800eeab8); break;
    case 31: [1f800024] = w(800eeae0); break;
    case 32: [1f800024] = w(800eeaec); break;
    case 34: [1f800024] = w(800eead8); break;
    case 35: [1f800024] = w(800eeb1c); break;
    case 36: [1f800024] = w(800eeb10); break;
    case 37: [1f800024] = w(800eeb04); break;
    case 38: [1f800024] = w(800eeaf8); break;
    case 3a: [1f800024] = w(800eeac8); break;
    case 3b: [1f800024] = w(800eeacc); break;
    case 39:
    {
        [80151909 + FP * b9c] = b(bu[80151909 + FP * b9c] | 80);
        [1f800024] = w(800eead0);
    }
    break;
}

S1 = FP << 10;
S4 = FP;
S2 = S4 * b9c;

if (bu[80151922 + FP * b9c] & 01)
{
    A0 = S4;
    funccdd44;

    [80151922 + FP * b9c] = b(bu[80151922 + FP * b9c] & fe);
}

if (bu[8015191f + S2] != 0)
{
    V0 = bu[1f800020];
    if (V0 != 0)
    {
        800C7EE4	lui    t2, $1f80
        800C7EE8	addu   s5, s1, zero
        800C7EEC	lui    s6, $1f80
        S7 = 1f800004;
        800C7EF8	ori    t2, t2, $0008
        800C7EFC	sw     t2, $0030(sp)
        800C7F00	sw     s4, $0038(sp)
        800C7F04	sw     s0, $0040(sp)

        Lc7f08:	; 800C7F08
            800C7F08	lw     t2, $0040(sp)
            800C7F0C	nop
            800C7F10	sll    v0, t2, $05
            800C7F14	subu   v0, v0, t2
            800C7F18	lw     t2, $0038(sp)
            800C7F1C	sll    v0, v0, $03
            800C7F20	subu   v0, v0, t2
            800C7F24	sll    v0, v0, $02

            A0 = bu[80151920 + V0];
            [80151920 + V0] = b(A0 + 1);

            V0 = bu[w[1f800024] + A0];
            [1f800021] = b(V0);

            V1 = V0 - 8e;
            if (V1 < 72)
            {
B0840C80A0840C805CC60C80C0800C80DC840C80F0840C8084860C80EC880C80ECBE0C801CCD0C80D0CD0C8060970C80B4930C80A4C70C8050810C80FCBC0C80
14B60C80 10
B8C70C80 11
ACB80C80 12
24AD0C80 13
74CA0C80 14
70A20C80 15
50C50C80 16
94C50C80 17
609E0C80 18
50CF0C80 19
BC950C80 1a
FC9E0C80 1d
E4C80C80 1e
A4BB0C80 20
30BA0C80 21
88B30C80 22
50B30C80 23
08D20C80 24
B4AF0C80 25
58880C80 26
70C40C80 27
989B0C80 29
449B0C80 2a
E0870C80 2c
88D10C80 2d
9C850C80 2e
049E0C80 2f
54B00C80 31
88D10C80 32
989A0C80 35
A09B0C80 36
908B0C80 39
90990C80 3a
F4A20C80 3d
B4A10C80 3e
88D10C80 3f
3CAF0C80 40
D4A50C80 41
88D10C80 44
88D10C80 45
248F0C80 46
24A50C80 47
08CC0C80 48
44B40C80 49
88D10C80 4b
68BE0C80 4c
6CC30C80 4d
00C00C80 4e
64C10C80 4f
A8C00C80 50
34900C80 51
18C60C80 52
AC8E0C80 55
C0B20C80 56
08890C80 57
D8C50C80 58
20A70C80 59
70960C80 5b
D8CE0C80 5d
38B20C80 5f
88D10C80 61
F0B70C80 63
08D20C80 64
ECA70C80 67
60810C80 6a
608E0C80 6b
08860C80 6f
9C7F0C80ECB60C80348B0C804C8B0C80448A0C8040890C80448A0C80448A0C80009D0C80009D0C801C9D0C80C49C0C803C9D0C80C49C0C80C49C0C80C49C0C80
009D0C800000000088BD0C80A8BD0C80C8BD0C80E8BD0C8008BE0C8028BE0C8048BE0C800000000024E10C8044E10C8098E10C80A8E10C8000E20C8000E20C80
00E20C80C8E10C8034E10C8000E20C8044E10C8000E20C8000E20C8000E20C8000E20C8000E20C8000E20C80B8E10C80B8E10C80000000008CE20C80ACE20C80


                800C7F7C	sll    v0, v1, $02
                800C7F80	lui    at, $800a
                800C7F84	addiu  at, at, $08c0
                800C7F88	addu   at, at, v0
                800C7F8C	lw     v0, $0000(at)
                800C7F90	nop
                800C7F94	jr     v0 
                800C7F98	nop

                800C7F9C	sra    a0, s5, $10
                800C7FA0	sll    v0, a0, $01
                800C7FA4	addu   v0, v0, a0
                800C7FA8	sll    v1, v0, $05
                800C7FAC	subu   v1, v1, v0
                800C7FB0	sll    v1, v1, $03
                800C7FB4	subu   v1, v1, a0
                800C7FB8	sll    a1, v1, $02
                800C7FBC	lui    at, $8015
                800C7FC0	addiu  at, at, $1921
                800C7FC4	addu   at, at, a1
                800C7FC8	lbu    v0, $0000(at)
                800C7FCC	nop
                800C7FD0	bne    v0, zero, Lcd208 [$800cd208]
                800C7FD4	nop
                800C7FD8	lui    at, $8015
                800C7FDC	addiu  at, at, $1920
                800C7FE0	addu   at, at, a1
                800C7FE4	lbu    v1, $0000(at)
                800C7FE8	lw     v0, $0004(s3)
                800C7FEC	nop
                800C7FF0	addu   v0, v0, v1
                800C7FF4	lbu    v0, $0000(v0)
                800C7FF8	nop
                800C7FFC	sb     v0, $0001(s3)
                800C8000	lbu    v1, $0001(s3)
                800C8004	ori    v0, zero, $00c0
                800C8008	bne    v1, v0, Lcd208 [$800cd208]
                800C800C	sll    v0, a0, $06
                800C8010	lui    at, $8015
                800C8014	addiu  at, at, $1920
                800C8018	addu   at, at, a1
                800C801C	sb     zero, $0000(at)
                800C8020	lui    at, $8010
                800C8024	addiu  at, at, $a6d8 (=-$5928)
                800C8028	addu   at, at, v0
                800C802C	sw     zero, $0000(at)
                800C8030	sll    v0, a0, $03
                800C8034	subu   v0, v0, a0
                800C8038	sll    v0, v0, $02
                800C803C	addu   v0, v0, a0
                800C8040	sll    v0, v0, $02
                800C8044	lui    t2, $8015
                800C8048	addiu  t2, t2, $18e4
                800C804C	lui    at, $8015
                800C8050	addiu  at, at, $1236
                800C8054	addu   at, at, v0
                800C8058	sb     zero, $0000(at)
                800C805C	addu   v0, a1, t2
                800C8060	sw     zero, $0074(v0)
                800C8064	lui    at, $8015
                800C8068	addiu  at, at, $1921
                800C806C	addu   at, at, a1
                800C8070	sb     zero, $0000(at)

                V0 = w[S3 + 4];
                V0 = bu[V0];
                [801518f2 + A1] = h(V0);
                800C8094	lui    at, $8016
                800C8098	addiu  at, at, $3784
                800C809C	addu   at, at, a0
                800C80A0	lbu    v0, $0000(at)
                800C80A4	nop
                800C80A8	lui    at, $8015
                800C80AC	addiu  at, at, $18e6
                800C80B0	addu   at, at, a1
                800C80B4	sh     v0, $0000(at)
                T2 = w[SP + 18];
                [1f800024] = w(w[T2 + V0 * 4]);

                funccdd44;

                800CB7E8	j      Lcd208 [$800cd208]
                800CB7EC	nop

                800C80C0	sra    a0, s5, $10
                800C80C4	sll    v1, a0, $01
                800C80C8	addu   v1, v1, a0
                800C80CC	sll    v0, v1, $05
                800C80D0	subu   v0, v0, v1
                800C80D4	sll    v0, v0, $03
                800C80D8	subu   v0, v0, a0
                800C80DC	sll    v0, v0, $02
                800C80E0	lui    at, $8015
                800C80E4	addiu  at, at, $1920
                800C80E8	addu   at, at, v0
                800C80EC	lbu    a0, $0000(at)
                800C80F0	nop
                800C80F4	addiu  v1, a0, $0001
                800C80F8	lui    at, $8015
                800C80FC	addiu  at, at, $1920
                800C8100	addu   at, at, v0
                800C8104	sb     v1, $0000(at)
                800C8108	lw     v0, $0004(s3)
                800C810C	nop
                800C8110	addu   a0, a0, v0
                800C8114	lbu    v0, $0000(a0)
                800C8118	lui    a0, $800d
                800C811C	addiu  a0, a0, $dfc4 (=-$203c)
                800C8120	jal    funcbc04c [$800bc04c]
                800C8124	sw     v0, $0000(s6)
                800C8128	sb     v0, $0014(s3)
                800C812C	lbu    v0, $0014(s3)
                800C8130	lhu    v1, $0000(s6)
                800C8134	sll    v0, v0, $05
                800C8138	lui    at, $8016
                800C813C	addiu  at, at, $21f4
                800C8140	addu   at, at, v0
                800C8144	sh     v1, $0000(at)
                800C8148	j      Lcd208 [$800cd208]
                800C814C	nop
                800C8150	jal    funcbb90c [$800bb90c]
                800C8154	nop
                800C8158	j      Lcd208 [$800cd208]
                800C815C	nop
                800C8160	sra    s0, s5, $10
                800C8164	sll    v1, s0, $01
                800C8168	addu   v1, v1, s0
                800C816C	sll    v0, v1, $05
                800C8170	subu   v0, v0, v1
                800C8174	sll    v0, v0, $03
                800C8178	subu   v0, v0, s0
                800C817C	sll    v0, v0, $02
                800C8180	lui    at, $8015
                800C8184	addiu  at, at, $1920
                800C8188	addu   at, at, v0
                800C818C	lbu    a0, $0000(at)
                800C8190	nop
                800C8194	addiu  v1, a0, $0001
                800C8198	lui    at, $8015
                800C819C	addiu  at, at, $1920
                800C81A0	addu   at, at, v0
                800C81A4	sb     v1, $0000(at)
                800C81A8	lw     v0, $0004(s3)
                800C81AC	nop
                800C81B0	addu   a0, a0, v0
                800C81B4	lbu    v0, $0000(a0)
                800C81B8	lui    a0, $800d
                800C81BC	addiu  a0, a0, $e384 (=-$1c7c)
                800C81C0	lui    at, $1f80
                800C81C4	sw     v0, $0000(at)
                800C81C8	jal    funcbc04c [$800bc04c]
                800C81CC	nop
                800C81D0	sh     v0, $000a(s3)
                800C81D4	slti   v0, s0, $0004
                800C81D8	beq    v0, zero, Lc8200 [$800c8200]
                800C81DC	sll    v0, s0, $02
                800C81E0	lui    at, $8010
                800C81E4	addiu  at, at, $8384 (=-$7c7c)
                800C81E8	addu   at, at, v0
                800C81EC	lw     v0, $0000(at)
                800C81F0	lui    at, $1f80
                800C81F4	sw     s0, $0008(at)
                800C81F8	j      Lc8240 [$800c8240]
                800C81FC	nop

                Lc8200:	; 800C8200
                800C8200	addiu  v1, s0, $fffc (=-$4)
                800C8204	sll    v0, v1, $01
                800C8208	addu   v0, v0, v1
                800C820C	sll    v0, v0, $02
                800C8210	lui    at, $800f
                800C8214	addiu  at, at, $7e08
                800C8218	addu   at, at, v0
                800C821C	lh     v1, $0000(at)
                800C8220	nop
                800C8224	sll    v0, v1, $02
                800C8228	lui    at, $8010
                800C822C	addiu  at, at, $8384 (=-$7c7c)
                800C8230	addu   at, at, v0
                800C8234	lw     v0, $0000(at)
                800C8238	lui    at, $1f80
                800C823C	sw     v1, $0008(at)

                Lc8240:	; 800C8240
                800C8240	lw     a0, $0008(v0)
                800C8244	lhu    v1, $000a(s3)
                800C8248	lui    v0, $1f80
                800C824C	lw     v0, $0000(v0)
                800C8250	sll    v1, v1, $10
                800C8254	sll    v0, v0, $02
                800C8258	addu   v0, v0, a0
                800C825C	lw     v0, $0024(v0)
                800C8260	sra    v1, v1, $0b
                800C8264	lui    at, $8016
                800C8268	addiu  at, at, $2200
                800C826C	addu   at, at, v1
                800C8270	sw     v0, $0000(at)
                800C8274	lhu    v0, $000a(s3)
                800C8278	nop
                800C827C	sll    v0, v0, $10
                800C8280	sra    v0, v0, $0b
                800C8284	lui    at, $8016
                800C8288	addiu  at, at, $21f6
                800C828C	addu   at, at, v0
                800C8290	sh     fp, $0000(at)
                800C8294	lhu    v0, $000a(s3)
                800C8298	nop
                800C829C	sll    v0, v0, $10
                800C82A0	sra    v0, v0, $0b
                800C82A4	lui    at, $8016
                800C82A8	addiu  at, at, $2208
                800C82AC	addu   at, at, v0
                800C82B0	sb     zero, $0000(at)
                800C82B4	lhu    v0, $000a(s3)
                800C82B8	nop
                800C82BC	sll    v0, v0, $10
                800C82C0	sra    v0, v0, $0b
                800C82C4	lui    at, $8016
                800C82C8	addiu  at, at, $21f4
                800C82CC	addu   at, at, v0
                800C82D0	sh     zero, $0000(at)
                800C82D4	sra    v0, s5, $10
                800C82D8	sll    v1, v0, $03
                800C82DC	subu   v1, v1, v0
                800C82E0	sll    v1, v1, $02
                800C82E4	addu   v1, v1, v0
                800C82E8	sll    v1, v1, $02
                800C82EC	lui    at, $8015
                800C82F0	addiu  at, at, $1234
                800C82F4	addu   at, at, v1
                800C82F8	lbu    v0, $0000(at)
                800C82FC	nop
                800C8300	addiu  v0, v0, $0001
                800C8304	lui    at, $8015
                800C8308	addiu  at, at, $1234
                800C830C	addu   at, at, v1
                800C8310	sb     v0, $0000(at)
                800C8314	lhu    v0, $000a(s3)
                800C8318	lui    at, $8015
                800C831C	addiu  at, at, $1234
                800C8320	addu   at, at, v1
                800C8324	lbu    v1, $0000(at)
                800C8328	sll    v0, v0, $10
                800C832C	sra    v0, v0, $0b
                800C8330	lui    at, $8016
                800C8334	addiu  at, at, $21f2
                800C8338	addu   at, at, v0
                800C833C	sh     v1, $0000(at)
                800C8340	j      Lcd208 [$800cd208]
                800C8344	nop



                case a9: // (1b)
                {
                    A1 = S5 >> 10;

                    V1 = bu[80151920 + A1 * b9c];
                    [80151920 + A1 * b9c] = b(V1 + 2);

                    V0 = bu[w[1f800024] + V1 + 1];
                    [80151958 + A1 * b9c] = w(0); // animation start
                    [801518f2 + A1 * b9c] = h(V0); // animation to play
                    [80151236 + A1 * 74] = b(0);
                    [800fa6d8 + A1 * 40] = w(0); // animation start

                    V0 = bu[800fafd8] + 3;
                    [800fafd8] = b(V0);

                    V0 = V0 & f;
                    [1f800000] = w(V0);

                    if (V0 != 0)
                    {
                        S2 = 0;
                        loopc845c:	; 800C845C
                            [80151236 + A1 * 74] = b(bu[80151236 + A1 * 74] + 1);

                            A0 = A1;
                            A1 = [SP + 20];
                            A2 = w[SP + 28];
                            funccd400;

                            S2 = S2 + 1;
                            V0 = S2 < w[1f800000];
                        800C8490	bne    v0, zero, loopc845c [$800c845c]
                    }

                    [1f800020] = b(0);
                }
                break;



                800C84A0	lui    at, $8016
                800C84A4	sb     zero, $20a4(at)
                800C84A8	j      Lcd208 [$800cd208]
                800C84AC	nop
                800C84B0	lui    v0, $8015
                800C84B4	lbu    v0, $17c4(v0)
                800C84B8	nop
                800C84BC	bne    v0, zero, Lcd208 [$800cd208]
                800C84C0	ori    v0, zero, $0001
                800C84C4	lui    at, $8016
                800C84C8	sb     v0, $20a4(at)
                800C84CC	lui    at, $8015
                800C84D0	sb     v0, $17c4(at)
                800C84D4	j      Lcd208 [$800cd208]
                800C84D8	nop
                800C84DC	ori    v0, zero, $0001
                800C84E0	lui    at, $8010
                800C84E4	sb     v0, $afdc(at)
                800C84E8	j      Lcd208 [$800cd208]
                800C84EC	nop
                800C84F0	lui    a0, $800c
                800C84F4	addiu  a0, a0, $494c
                800C84F8	jal    funcbc04c [$800bc04c]
                800C84FC	nop
                800C8500	j      Lcd208 [$800cd208]
                800C8504	nop



                case b9: // (2b)
                {
                    A0 = S5 >> 10;
                    A1 = bu[801518e4 + A0 * b9c + 3c];
                    [801518e4 + A0 * b9c + 3c] = b(A1 + 1);

                    A0 = bu[801590e0];
                    [80163798 + A0 * c + 8] = h(-2); // camera movement id set to init camera
                    [80163f30] = b(bu[w[1f800024] + A1]); // set init camera

                    funcbb684; // reset camera
                }
                break;



                800C859C	sra    a0, s5, $10
                800C85A0	sll    v1, a0, $01
                800C85A4	addu   v1, v1, a0
                800C85A8	sll    v0, v1, $05
                800C85AC	subu   v0, v0, v1
                800C85B0	sll    v0, v0, $03
                800C85B4	subu   v0, v0, a0
                800C85B8	sll    v0, v0, $02
                800C85BC	lui    at, $8015
                800C85C0	addiu  at, at, $1920
                800C85C4	addu   at, at, v0
                800C85C8	lbu    a0, $0000(at)
                800C85CC	nop
                800C85D0	addiu  v1, a0, $0001
                800C85D4	lui    at, $8015
                800C85D8	addiu  at, at, $1920
                800C85DC	addu   at, at, v0
                800C85E0	sb     v1, $0000(at)
                800C85E4	lw     v0, $0004(s3)
                800C85E8	nop
                800C85EC	addu   a0, a0, v0
                800C85F0	lbu    v0, $0000(a0)
                800C85F4	nop
                800C85F8	lui    at, $8016
                800C85FC	sb     v0, $3b3c(at)
                800C8600	j      Lcd208 [$800cd208]
                800C8604	nop
                800C8608	sra    s0, s5, $10
                800C860C	lw     a1, $0004(s3)
                800C8610	jal    funccd558 [$800cd558]
                800C8614	addu   a0, s0, zero
                800C8618	sll    v1, s0, $01
                800C861C	addu   v1, v1, s0
                800C8620	sll    s1, v1, $05
                800C8624	subu   s1, s1, v1
                800C8628	sll    s1, s1, $03
                800C862C	subu   s1, s1, s0
                800C8630	sll    s1, s1, $02
                800C8634	lui    at, $8015
                800C8638	addiu  at, at, $1a4c
                800C863C	addu   at, at, s1
                800C8640	sh     v0, $0000(at)
                800C8644	lw     a1, $0004(s3)
                800C8648	jal    funccd558 [$800cd558]
                800C864C	addu   a0, s0, zero
                800C8650	lui    at, $8015
                800C8654	addiu  at, at, $1a4e
                800C8658	addu   at, at, s1
                800C865C	sh     v0, $0000(at)
                800C8660	lw     a1, $0004(s3)
                800C8664	jal    funccd558 [$800cd558]
                800C8668	addu   a0, s0, zero
                800C866C	lui    at, $8015
                800C8670	addiu  at, at, $1a50
                800C8674	addu   at, at, s1
                800C8678	sh     v0, $0000(at)
                800C867C	j      Lcd208 [$800cd208]
                800C8680	nop
                800C8684	sra    s0, s5, $10
                800C8688	lw     a1, $0004(s3)
                800C868C	jal    funccd558 [$800cd558]
                800C8690	addu   a0, s0, zero
                800C8694	addu   a0, s0, zero
                800C8698	sll    v0, v0, $10
                800C869C	lw     a1, $0004(s3)
                800C86A0	sra    v0, v0, $10
                800C86A4	jal    funccd558 [$800cd558]
                800C86A8	sw     v0, $0000(s6)
                800C86AC	sll    v0, v0, $10
                800C86B0	sra    v0, v0, $10
                800C86B4	sll    v1, s0, $01
                800C86B8	addu   v1, v1, s0
                800C86BC	sw     v0, $0000(s7)
                800C86C0	sll    v0, v1, $05
                800C86C4	subu   v0, v0, v1
                800C86C8	sll    v0, v0, $03
                800C86CC	subu   v0, v0, s0
                800C86D0	sll    v0, v0, $02
                800C86D4	lui    at, $8015
                800C86D8	addiu  at, at, $1920
                800C86DC	addu   at, at, v0
                800C86E0	lbu    a0, $0000(at)
                800C86E4	nop
                800C86E8	addiu  v1, a0, $0001
                800C86EC	lui    at, $8015
                800C86F0	addiu  at, at, $1920
                800C86F4	addu   at, at, v0
                800C86F8	sb     v1, $0000(at)
                800C86FC	lw     v0, $0004(s3)
                800C8700	lw     t2, $0030(sp)
                800C8704	addu   a0, a0, v0
                800C8708	lbu    v0, $0000(a0)
                800C870C	lui    a0, $800d
                800C8710	addiu  a0, a0, $f3cc (=-$c34)
                800C8714	jal    funcbbf7c [$800bbf7c]
                800C8718	sw     v0, $0000(t2)
                800C871C	sb     v0, $0014(s3)
                800C8720	lbu    v0, $0014(s3)
                800C8724	nop
                800C8728	sll    v0, v0, $05
                800C872C	lui    at, $8016
                800C8730	addiu  at, at, $20b4
                800C8734	addu   at, at, v0
                800C8738	sh     fp, $0000(at)
                800C873C	lbu    v0, $0014(s3)
                800C8740	lhu    v1, $0000(s6)
                800C8744	sll    v0, v0, $05
                800C8748	lui    at, $8016
                800C874C	addiu  at, at, $20b6
                800C8750	addu   at, at, v0
                800C8754	sh     v1, $0000(at)
                800C8758	lbu    v0, $0014(s3)
                800C875C	lhu    v1, $0000(s7)
                800C8760	sll    v0, v0, $05
                800C8764	lui    at, $8016
                800C8768	addiu  at, at, $20b8
                800C876C	addu   at, at, v0
                800C8770	sh     v1, $0000(at)
                800C8774	lw     v1, $0000(s7)
                800C8778	lw     t2, $0030(sp)
                800C877C	lw     a0, $0000(s6)
                800C8780	lw     v0, $0000(t2)
                800C8784	subu   v1, v1, a0
                800C8788	div    v1, v0
                800C878C	bne    v0, zero, Lc8798 [$800c8798]
                800C8790	nop
                800C8794	break   $01c00

                Lc8798:	; 800C8798
                800C8798	addiu  at, zero, $ffff (=-$1)
                800C879C	bne    v0, at, Lc87b0 [$800c87b0]
                800C87A0	lui    at, $8000
                800C87A4	bne    v1, at, Lc87b0 [$800c87b0]
                800C87A8	nop
                800C87AC	break   $01800

                Lc87b0:	; 800C87B0
                800C87B0	mflo   v1
                800C87B4	lbu    v0, $0014(s3)
                800C87B8	nop
                800C87BC	sll    v0, v0, $05
                800C87C0	lui    at, $8016
                800C87C4	addiu  at, at, $20ba
                800C87C8	addu   at, at, v0
                800C87CC	sh     v1, $0000(at)
                800C87D0	lbu    v0, $0014(s3)
                800C87D4	lhu    v1, $0000(t2)
                800C87D8	j      Lc901c [$800c901c]
                800C87DC	sll    v0, v0, $05
                800C87E0	sra    a0, s5, $10
                800C87E4	sll    v0, a0, $01
                800C87E8	addu   v0, v0, a0
                800C87EC	sll    s0, v0, $05
                800C87F0	subu   s0, s0, v0
                800C87F4	sll    s0, s0, $03
                800C87F8	subu   s0, s0, a0
                800C87FC	sll    s0, s0, $02
                800C8800	lui    at, $8015
                800C8804	addiu  at, at, $18fc
                800C8808	addu   at, at, s0
                800C880C	lhu    v0, $0000(at)
                800C8810	nop
                800C8814	lui    at, $8015
                800C8818	addiu  at, at, $1a46
                800C881C	addu   at, at, s0
                800C8820	sh     v0, $0000(at)
                800C8824	lw     a1, $0004(s3)
                800C8828	jal    funccd558 [$800cd558]
                800C882C	nop
                800C8830	lui    at, $8015
                800C8834	addiu  at, at, $1a46
                800C8838	addu   at, at, s0
                800C883C	lhu    v1, $0000(at)
                800C8840	nop
                800C8844	addu   v1, v1, v0
                800C8848	lui    at, $8015
                800C884C	addiu  at, at, $1a46
                800C8850	addu   at, at, s0
                800C8854	sh     v1, $0000(at)
                800C8858	lui    v1, $8010
                800C885C	lbu    v1, $a6d0(v1)
                800C8860	ori    v0, zero, $0002
                800C8864	beq    v1, v0, Lc887c [$800c887c]
                800C8868	ori    v0, zero, $0004
                800C886C	beq    v1, v0, Lc88b8 [$800c88b8]
                800C8870	sra    a0, s5, $10
                800C8874	j      Lc8e68 [$800c8e68]
                800C8878	sll    v1, a0, $01

                Lc887c:	; 800C887C
                800C887C	sra    a0, s5, $10
                800C8880	sll    v1, a0, $01
                800C8884	addu   v1, v1, a0
                800C8888	sll    v0, v1, $05
                800C888C	subu   v0, v0, v1
                800C8890	sll    v0, v0, $03
                800C8894	subu   v0, v0, a0
                800C8898	sll    v0, v0, $02
                800C889C	ori    v1, zero, $0800
                800C88A0	lui    at, $8015
                800C88A4	addiu  at, at, $18fc
                800C88A8	addu   at, at, v0
                800C88AC	sh     v1, $0000(at)
                800C88B0	j      Lc8e68 [$800c8e68]
                800C88B4	sll    v1, a0, $01

                Lc88b8:	; 800C88B8
                800C88B8	sll    v1, a0, $01
                800C88BC	addu   v1, v1, a0
                800C88C0	sll    v0, v1, $05
                800C88C4	subu   v0, v0, v1
                800C88C8	sll    v0, v0, $03
                800C88CC	subu   v0, v0, a0

                Lc88d0:	; 800C88D0
                800C88D0	sll    v0, v0, $02
                800C88D4	lui    at, $8015
                800C88D8	addiu  at, at, $18fc
                800C88DC	addu   at, at, v0
                800C88E0	sh     zero, $0000(at)
                800C88E4	j      Lc8e64 [$800c8e64]
                800C88E8	sra    a0, s5, $10
                800C88EC	lui    v1, $8010
                800C88F0	lbu    v1, $a6d0(v1)
                800C88F4	ori    v0, zero, $0002
                800C88F8	bne    v1, v0, Lc8e64 [$800c8e64]
                800C88FC	sra    a0, s5, $10
                800C8904	slti   v0, a0, $0004
                if (V0 != 0)
                {
                    [801518fc + A0 * b9c] = h(0800);
                }

                A0 = S5 >> 10;
                [80151a46 + A0 * b9c] = h(hu[801518fc + A0 * b9c]);
                800C8EA4	j      Lcd208 [$800cd208]



                case e5: // (57)
                {
                    unit_id = S5 >> 10;

                    formation_id = bu[800fa6d0];
                    if (formation_id == 1) // pre emptive attack
                    {
                        if (unit_id >= 4)
                        {
                            [801518e4 + unit_id * b9c + 18] = h(0800);
                        }

                        [80151a46 + unit_id * b9c] = h(hu[801518e4 + unit_id * b9c + 18]);
                    }
                    else if (formation_id == 2) // back attack
                    {
                        if (unit_id < 4)
                        {
                            [801518e4 + unit_id * b9c + 18] = h(0800);
                        }

                        [80151a46 + unit_id * b9c] = h(hu[801518e4 + unit_id * b9c + 18]);
                    }
                    else if (formation_id == 3 || formation_id == 5 || formation_id == 6)
                    {
                        // if enemy
                        if (unit_id >= 4)
                        {
                            attacker_id = bu[801590cc];
                            target_id = bu[800fa6d4];
                            if (unit_id == attacker_id)
                            {
                                V0 = h[801518e4 + target_id * b9c + 18];
                            }
                            else
                            {
                                V0 = h[801518e4 + attacker_id * b9c + 18];
                            }

                            if (V0 != 0)
                            {
                                [801518e4 + unit_id * b9c + 18] = h(0);
                            }
                            else
                            {
                                [801518e4 + unit_id * b9c + 18] = h(0800);
                            }
                        }

                        [80151a46 + unit_id * b9c] = h(hu[801518e4 + unit_id * b9c + 18]);
                    }
                    else if (formation_id == 4) // if pincer attack
                    {
                        // player
                        if (unit_id < 4)
                        {
                            attacker_id = bu[801590cc];
                            target_id = bu[800fa6d4];

                            if (unit_id != target_id || unit_id != attacker_id)
                            {
                                if (bu[801031f0] == 0)
                                {
                                    if (unit_id == attacker_id)
                                    {
                                        V0 = h[801518e4 + target_id * b9c + 18]
                                    }
                                    else
                                    {
                                        V0 = h[801518e4 + attacker_id * b9c + 18]
                                    }

                                    if (V0 != 0)
                                    {
                                        [801518e4 + unit_id * b9c + 18] = h(0);
                                    }
                                    else
                                    {
                                        [801518e4 + unit_id * b9c + 18] = h(0800);
                                    }
                                }
                            }
                        }

                        [801518e4 + unit_id * b9c + 162] = h(hu[801518e4 + unit_id * b9c + 18]);
                    }
                    else
                    {
                        [80151a46 + unit_id * b9c] = h(hu[801518e4 + unit_id * b9c + 18]);
                    }
                }
                break;



                        800C8B90	sra    s0, s5, $10
                        800C8B94	lw     a1, $0004(s3)
                        800C8B98	jal    funccd558 [$800cd558]
                        800C8B9C	addu   a0, s0, zero
                        800C8BA0	addu   v0, fp, v0
                        800C8BAC	sh     v0, $000e(s3)
                        A1 = S0 * b9c;
                        800C8BC4	lui    at, $8015
                        800C8BC8	addiu  at, at, $1920
                        800C8BCC	addu   at, at, a1
                        800C8BD0	lbu    v1, $0000(at)
                        800C8BD4	nop
                        800C8BD8	addiu  v0, v1, $0001
                        800C8BDC	lui    at, $8015
                        800C8BE0	addiu  at, at, $1920
                        800C8BE4	addu   at, at, a1
                        800C8BE8	sb     v0, $0000(at)
                        800C8BEC	lw     v0, $0004(s3)
                        800C8BF0	lhu    a0, $000e(s3)
                        800C8BF4	addu   v1, v1, v0
                        800C8BF8	addiu  v0, a0, $fffc (=-$4)
                        800C8BFC	lbu    a2, $0000(v1)
                        800C8C00	sltiu  v0, v0, $0006
                        800C8C04	beq    v0, zero, Lcd208 [$800cd208]
                        800C8C08	sh     a2, $0010(s3)
                        800C8C0C	sll    v0, s0, $03
                        800C8C10	subu   v0, v0, s0
                        800C8C14	sll    v0, v0, $02
                        800C8C18	addu   v0, v0, s0
                        800C8C1C	sll    v0, v0, $02
                        800C8C20	lui    at, $8015
                        800C8C24	addiu  at, at, $120c
                        800C8C28	addu   at, at, v0
                        800C8C2C	lhu    v1, $0000(at)
                        800C8C30	nop
                        800C8C34	andi   v0, v1, $0004
                        if (V0 == 0)
                        {
                            A0 = A0 * b9c;
                            800C8C64	lui    at, $8015
                            800C8C68	addiu  at, at, $1909
                            800C8C6C	addu   at, at, a0
                            800C8C70	lbu    v0, $0000(at)
                            800C8C74	nop
                            800C8C78	andi   v0, v0, $0080
                            800C8C7C	beq    v0, zero, Lcd208 [$800cd208]
                            800C8C80	nop
                            800C8C84	lui    t2, $8015
                            800C8C88	addiu  t2, t2, $18e4
                            800C8C8C	lui    at, $8015
                            800C8C90	addiu  at, at, $18fc
                            800C8C94	addu   at, at, a1
                            800C8C98	lhu    v1, $0000(at)
                            800C8C9C	addu   v0, a0, t2
                            800C8CA0	sh     v1, $0018(v0)
                            800C8CA4	lui    at, $8015
                            800C8CA8	addiu  at, at, $1a46
                            800C8CAC	addu   at, at, a0
                            800C8CB0	sh     v1, $0000(at)
                            800C8CB4	lhu    a0, $000e(s3)
                            800C8CB8	nop
                            800C8CDC	lhu    v1, $0010(s3)
                            V0 = A0 * b9c;
                            800C8CE4	lui    at, $8015
                            800C8CE8	addiu  at, at, $18e6
                            800C8CEC	addu   at, at, v0
                            800C8CF0	sh     v1, $0000(at)
                        }
                        else
                        {
                            800C8C3C	andi   v0, v1, $0008
                            800C8CFC	beq    v0, zero, Lcd208 [$800cd208]
                            800C8D00	nop
                            V0 = bu[801031f0];
                            if (V0 != 0)
                            {
                                V0 = bu[800fa9c0];
                                800C8D24	bne    v0, s0, Lcd208 [$800cd208]
                            }

                            V1 = A0 * b9c;
                            V0 = bu[80151909 + V1];
                            800C8D60	andi   v0, v0, $0080
                            800C8D64	beq    v0, zero, Lcd208 [$800cd208]
                            800C8D68	nop
                            [801519e6 + V1] = h(A2);
                        }

                        A0 = hu[S3 + e];
                        [80151922 + A0 * b9c] = b(bu[80151922 + A0 * b9c] + 1);
                        [8015190a + A0 * b9c] = b(0);
                        [8015120c + A0 * 74] = h(hu[8015120c + A0 * 74] + 4);
                        800C8E58	j      Lcd208 [$800cd208]


                Lc8e60:	; 800C8E60
                Lc8e64:	; 800C8E64
                Lc8e68:	; 800C8E68
                A0 = S5 >> 10;
                [80151a46 + A0 * b9c] = h(hu[801518fc + A0 * b9c]);
                800C8EA4	j      Lcd208 [$800cd208]
                800C8EA8	nop
                800C8EAC	lui    a0, $8016
                800C8EB0	lbu    a0, $90cc(a0)
                800C8EB4	nop
                800C8EB8	sll    v1, a0, $01
                800C8EBC	addu   v1, v1, a0
                800C8EC0	sll    v0, v1, $05
                800C8EC4	subu   v0, v0, v1
                800C8EC8	sll    v0, v0, $03
                800C8ECC	subu   v0, v0, a0
                800C8ED0	sll    v0, v0, $02
                800C8ED4	lui    at, $8015
                800C8ED8	addiu  at, at, $1a4c
                800C8EDC	addu   at, at, v0
                800C8EE0	lhu    a0, $0000(at)
                800C8EE4	sll    v1, v1, $01
                800C8EE8	lui    at, $8016
                800C8EEC	addiu  at, at, $3c80
                800C8EF0	addu   at, at, v1
                800C8EF4	sh     a0, $0000(at)
                800C8EF8	lui    at, $8015
                800C8EFC	addiu  at, at, $1a50
                800C8F00	addu   at, at, v0
                800C8F04	lhu    v0, $0000(at)
                800C8F08	nop
                800C8F0C	lui    at, $8016
                800C8F10	addiu  at, at, $3c84
                800C8F14	addu   at, at, v1
                800C8F18	sh     v0, $0000(at)
                800C8F1C	j      Lcd208 [$800cd208]
                800C8F20	nop
                800C8F24	sra    s0, s5, $10
                800C8F28	lw     a1, $0004(s3)
                800C8F2C	jal    funccd558 [$800cd558]
                800C8F30	addu   a0, s0, zero
                800C8F34	sll    v1, s0, $01
                800C8F38	addu   v1, v1, s0
                800C8F3C	sh     v0, $0012(s3)
                800C8F40	sll    v0, v1, $05
                800C8F44	subu   v0, v0, v1
                800C8F48	sll    v0, v0, $03
                800C8F4C	subu   v0, v0, s0
                800C8F50	sll    v0, v0, $02
                800C8F54	lui    at, $8015
                800C8F58	addiu  at, at, $1920
                800C8F5C	addu   at, at, v0
                800C8F60	lbu    a0, $0000(at)
                800C8F64	nop
                800C8F68	addiu  v1, a0, $0001
                800C8F6C	lui    at, $8015
                800C8F70	addiu  at, at, $1920
                800C8F74	addu   at, at, v0
                800C8F78	sb     v1, $0000(at)
                800C8F7C	lw     v1, $0004(s3)
                800C8F80	lhu    v0, $0012(s3)
                800C8F84	addu   a0, a0, v1
                800C8F88	sll    v0, v0, $10
                800C8F8C	lbu    a1, $0000(a0)
                800C8F90	sra    v0, v0, $10
                800C8F94	div    v0, a1
                800C8F98	bne    a1, zero, Lc8fa4 [$800c8fa4]
                800C8F9C	nop
                800C8FA0	break   $01c00

                Lc8fa4:	; 800C8FA4
                800C8FA4	addiu  at, zero, $ffff (=-$1)
                800C8FA8	bne    a1, at, Lc8fbc [$800c8fbc]
                800C8FAC	lui    at, $8000
                800C8FB0	bne    v0, at, Lc8fbc [$800c8fbc]
                800C8FB4	nop
                800C8FB8	break   $01800

                Lc8fbc:	; 800C8FBC
                800C8FBC	mflo   v0
                800C8FC0	lui    a0, $800d
                800C8FC4	addiu  a0, a0, $f2f0 (=-$d10)
                800C8FC8	sh     a1, $0010(s3)
                800C8FCC	jal    funcbbf7c [$800bbf7c]
                800C8FD0	sw     v0, $0000(s6)
                800C8FD4	sb     v0, $0014(s3)
                800C8FD8	lbu    v0, $0014(s3)
                800C8FDC	nop
                800C8FE0	sll    v0, v0, $05
                800C8FE4	lui    at, $8016
                800C8FE8	addiu  at, at, $20b4
                800C8FEC	addu   at, at, v0
                800C8FF0	sh     fp, $0000(at)
                800C8FF4	lbu    v0, $0014(s3)
                800C8FF8	lhu    v1, $0000(s6)
                800C8FFC	sll    v0, v0, $05
                800C9000	lui    at, $8016
                800C9004	addiu  at, at, $20b6
                800C9008	addu   at, at, v0
                800C900C	sh     v1, $0000(at)
                800C9010	lbu    v0, $0014(s3)
                800C9014	lhu    v1, $0010(s3)
                800C9018	sll    v0, v0, $05

                Lc901c:	; 800C901C
                800C901C	lui    at, $8016
                800C9020	addiu  at, at, $20b0
                800C9024	addu   at, at, v0
                800C9028	sh     v1, $0000(at)
                800C902C	j      Lcd208 [$800cd208]
                800C9030	nop
                800C9034	lui    a0, $8015
                800C9038	lh     a0, $1774(a0)
                800C903C	jal    battle_calculate_middle_point_from_target_mask_units_position [$800d54ec]
                800C9040	addiu  a1, s3, $0016
                800C9044	sra    v1, s5, $10
                800C9048	sll    v0, v1, $01
                800C904C	addu   v0, v0, v1
                800C9050	sll    s0, v0, $05
                800C9054	subu   s0, s0, v0
                800C9058	sll    s0, s0, $03
                800C905C	subu   s0, s0, v1
                800C9060	sll    s0, s0, $02
                800C9064	lhu    a2, $0016(s3)
                800C9068	lui    at, $8015
                800C906C	addiu  at, at, $1a4c
                800C9070	addu   at, at, s0
                800C9074	lh     a0, $0000(at)
                800C9078	lhu    a1, $001a(s3)
                800C907C	lui    at, $8015
                800C9080	addiu  at, at, $1a50
                800C9084	addu   at, at, s0
                800C9088	lh     v0, $0000(at)
                800C908C	sll    a2, a2, $10
                800C9090	sra    a2, a2, $10
                800C9094	subu   a0, a2, a0
                800C9098	sll    a1, a1, $10
                800C909C	sra    a1, a1, $10
                800C90A0	jal    func3cc1c [$8003cc1c]
                800C90A4	subu   a1, a1, v0
                800C90A8	addiu  v0, v0, $0800
                800C90AC	lui    at, $8015
                800C90B0	addiu  at, at, $1a46
                800C90B4	addu   at, at, s0
                800C90B8	sh     v0, $0000(at)
                800C90BC	j      Lcd208 [$800cd208]
                800C90C0	nop



                case fc: // 6e
                {
                    model_id = S5 >> 10;

                    if (bu[801031f0] != 0) // in case of multiple targets
                    {
                        formation_id = bu[800fa6d0];
                        // in case of pincer attacks
                        if (formation_id == 4)
                        {
                            if (hu[8016376e] & h[80151774])
                            {
                                [801518e4 + model_id * b9c + 162] = h(0000);
                            }
                            if (hu[80163772] & h[80151774])
                            {
                                [801518e4 + model_id * b9c + 162] = h(0800);
                            }
                        }
                        // in case of different side attacks
                        else if (formation_id == 3 || formation_id == 5 || formation_id == 6 || formation_id == 7)
                        {
                            [801518e4 + model_id * b9c + 162] = h(0800);

                            V1 = 4;
                            loopc913c:	; 800C913C
                                V0 = h[801518e4 + model_id * b9c + 18];
                                if (V0 == 0)
                                {
                                    [801518e4 + V1 * b9c + 18] = h(0800);
                                }
                                else
                                {
                                    [801518e4 + V1 * b9c + 18] = h(0000);
                                }

                                V0 = V1 < a;
                            800C916C	bne    v0, zero, loopc913c [$800c913c]
                        }
                    }
                    else
                    {
                        if (bu[801518e4 + model_id * b9c + 22] != 15 || bu[801518e4 + model_id * b9c + 23] != d)
                        {
                            attacker_id = bu[801590cc];
                            target_id = bu[800f99e8];
                            if (attacker_id != target_id)
                            {
                                A0 = h[801518e4 + target_id * b9c + 168] - h[801518e4 + model_id * b9c + 168];
                                A1 = h[801518e4 + target_id * b9c + 16c] - h[801518e4 + model_id * b9c + 16c];
                                func3cc1c;
                                [801518e4 + model_id * b9c + 162] = h(V0 + 0800);

                                A0 = h[801518e4 + target_id * b9c + 168] - h[801518e4 + model_id * b9c + 168];
                                A1 = h[801518e4 + target_id * b9c + 16c] - h[801518e4 + model_id * b9c + 16c];
                                func3cc1c;
                                [8015122c + target_id * 74] = h(V0);
                            }
                        }
                    }

                    800C93AC	j      Lcd208 [$800cd208]
                }
                break;



                case fb: // 6d;
                {
                    S1 = S5 >> 10;
                    target_id = bu[800f99e8];

                    A0 = S1;
                    A1 = w[S3 + 4];
                    funccd558; // read two bytes
                    [S3 + 12] = h(V0);

                    A0 = S1;
                    A1 = w[S3 + 4];
                    funccd558;
                    [S3 + c] = h(V0);

                    [S3 + 8] = h(0800 - hu[8015122c + target_id * 74]);

                    V1 = hu[S3 + 12] * h[801518ea + S1 * b9c];
                    V1 = V1 >> c;
                    V0 = hu[801518f6 + target_id * b9c] * h[801519ea + target_id * b9c];
                    V0 = V0 >> c;
                    V1 = V1 + V0;
                    [S3 + a] = h(V1);

                    A0 = hu[S3 + 8];
                    system_get_sin;

                    V0 = V0 * hu[S3 + a];
                    V0 = V0 >> c;
                    [80151a4c + S1 * b9c] = h(hu[80151a4c + target_id * b9c] - V0); // translation x

                    A0 = h[S3 + 8];
                    system_get_cos;

                    V0 = V0 * hu[S3 + a];
                    V0 = V0 >> c;
                    [80151a50 + S1 * b9c] = h(hu[80151a50 + target_id * b9c] + V0); // translation z
                    [80151a4e + S1 * b9c] = h(hu[S3 + c]); // translation y
                }
                break;

                800C95BC	sra    a0, s5, $10
                800C95C0	sll    v0, a0, $01
                800C95C4	addu   v0, v0, a0
                800C95C8	sll    v1, v0, $05
                800C95CC	subu   v1, v1, v0
                800C95D0	sll    v1, v1, $03
                800C95D4	subu   v1, v1, a0
                800C95D8	sll    v1, v1, $02
                800C95DC	lui    at, $8015
                800C95E0	addiu  at, at, $1920
                800C95E4	addu   at, at, v1
                800C95E8	lbu    a1, $0000(at)
                800C95EC	nop
                800C95F0	addiu  v0, a1, $0001
                800C95F4	lui    at, $8015
                800C95F8	addiu  at, at, $1920
                800C95FC	addu   at, at, v1
                800C9600	sb     v0, $0000(at)
                800C9604	lw     v0, $0004(s3)
                800C9608	nop
                800C960C	addu   a1, a1, v0
                800C9610	lbu    v0, $0000(a1)
                800C9614	nop
                800C9618	sw     v0, $0000(s6)
                800C961C	lui    at, $8015
                800C9620	addiu  at, at, $1920
                800C9624	addu   at, at, v1
                800C9628	lbu    a1, $0000(at)
                800C962C	nop
                800C9630	addiu  v0, a1, $0001
                800C9634	lui    at, $8015
                800C9638	addiu  at, at, $1920
                800C963C	addu   at, at, v1
                800C9640	sb     v0, $0000(at)
                800C9644	lw     v0, $0004(s3)
                800C9648	lh     a2, $0000(s6)
                800C964C	addu   a1, a1, v0
                800C9650	lbu    v0, $0000(a1)
                800C9654	nop
                800C9658	sw     v0, $0000(s7)
                800C965C	lh     a1, $0000(s7)
                800C9660	jal    funccf8c0 [$800cf8c0]
                800C9664	nop
                800C9668	j      Lcd208 [$800cd208]
                800C966C	nop
                800C9670	sra    s0, s5, $10
                800C9674	lw     a1, $0004(s3)
                800C9678	jal    funccd558 [$800cd558]
                800C967C	addu   a0, s0, zero
                800C9680	addu   a0, s0, zero
                800C9684	sll    v1, a0, $01
                800C9688	addu   v1, v1, a0
                800C968C	sh     v0, $0012(s3)
                800C9690	sll    v0, v1, $05
                800C9694	subu   v0, v0, v1
                800C9698	sll    v0, v0, $03
                800C969C	subu   v0, v0, a0
                800C96A0	sll    v0, v0, $02
                800C96A4	lui    at, $8015
                800C96A8	addiu  at, at, $1920
                800C96AC	addu   at, at, v0
                800C96B0	lbu    t0, $0000(at)
                800C96B4	lui    a3, $800d
                800C96B8	addiu  a3, a3, $f5bc (=-$a44)
                800C96BC	addiu  v1, t0, $0001
                800C96C0	lui    at, $8015
                800C96C4	addiu  at, at, $1920
                800C96C8	addu   at, at, v0
                800C96CC	sb     v1, $0000(at)
                800C96D0	lw     a1, $0004(s3)
                800C96D4	lw     v0, $0004(s3)
                800C96D8	lhu    a2, $0012(s3)
                800C96DC	lui    t1, $8010
                800C96E0	lbu    t1, $99e8(t1)
                800C96E4	addu   t0, t0, v0
                800C96E8	sll    a2, a2, $10
                800C96EC	sra    a2, a2, $10
                800C96F0	lbu    v0, $0000(t0)
                800C96F4	sll    t0, a0, $03
                800C96F8	subu   t0, t0, a0
                800C96FC	sll    t0, t0, $02
                800C9700	addu   t0, t0, a0
                800C9704	sll    t0, t0, $02
                800C9708	sll    v1, t1, $01
                800C970C	addu   v1, v1, t1
                800C9710	sh     v0, $0010(s3)
                800C9714	sll    v0, v1, $05
                800C9718	subu   v0, v0, v1
                800C971C	sll    v0, v0, $03
                800C9720	subu   v0, v0, t1
                800C9724	sll    v0, v0, $02
                800C9728	lui    t1, $8015
                800C972C	addiu  t1, t1, $1a4c
                800C9730	lui    at, $8015
                800C9734	addiu  at, at, $1228
                800C9738	addu   at, at, t0
                800C973C	lh     t0, $0000(at)
                800C9740	lhu    v1, $0010(s3)
                800C9744	addu   v0, v0, t1
                800C9748	sw     v0, $0014(sp)
                800C974C	sll    v1, v1, $10
                800C9750	lui    at, $1f80
                800C9754	sw     t0, $0000(at)
                800C9758	j      Lca710 [$800ca710]
                800C975C	sra    v1, v1, $10
                800C9760	sra    s1, s5, $10
                800C9764	sll    v0, s1, $01
                800C9768	addu   v0, v0, s1
                800C976C	sll    s0, v0, $05
                800C9770	subu   s0, s0, v0
                800C9774	sll    s0, s0, $03
                800C9778	subu   s0, s0, s1
                800C977C	sll    s0, s0, $02
                800C9780	lui    at, $8015
                800C9784	addiu  at, at, $1920
                800C9788	addu   at, at, s0
                800C978C	lbu    v1, $0000(at)
                800C9790	nop
                800C9794	addiu  v0, v1, $0001
                800C9798	lui    at, $8015
                800C979C	addiu  at, at, $1920
                800C97A0	addu   at, at, s0
                800C97A4	sb     v0, $0000(at)
                800C97A8	lw     v0, $0004(s3)
                800C97AC	lw     a1, $0004(s3)
                800C97B0	addu   v1, v1, v0
                800C97B4	lbu    v0, $0000(v1)
                800C97B8	nop
                800C97BC	lui    at, $8016
                800C97C0	sb     v0, $6f58(at)
                800C97C4	jal    funccd558 [$800cd558]
                800C97C8	addu   a0, s1, zero
                800C97CC	lw     a1, $0004(s3)
                800C97D0	addu   a0, s1, zero
                800C97D4	jal    funccd558 [$800cd558]
                800C97D8	sh     v0, $0012(s3)
                800C97DC	sll    v0, v0, $10
                800C97E0	sra    v0, v0, $10
                800C97E4	lui    at, $1f80
                800C97E8	sw     v0, $0000(at)
                800C97EC	lui    at, $8015
                800C97F0	addiu  at, at, $1920
                800C97F4	addu   at, at, s0
                800C97F8	lbu    v1, $0000(at)
                800C97FC	nop
                800C9800	addiu  v0, v1, $0001
                800C9804	lui    at, $8015
                800C9808	addiu  at, at, $1920
                800C980C	addu   at, at, s0
                800C9810	sb     v0, $0000(at)
                800C9814	lw     v0, $0004(s3)
                800C9818	nop
                800C981C	addu   v1, v1, v0
                800C9820	lbu    v1, $0000(v1)
                800C9824	lui    v0, $8010
                800C9828	lbu    v0, $31f0(v0)
                800C982C	nop
                800C9830	bne    v0, zero, Lc986c [$800c986c]
                800C9834	sh     v1, $0010(s3)
                800C9838	addu   a0, s1, zero
                800C983C	lw     a1, $0004(s3)
                800C9840	lhu    a2, $0012(s3)
                800C9844	lui    t0, $8010
                800C9848	lbu    t0, $99e8(t0)
                800C984C	lui    a3, $800d
                800C9850	addiu  a3, a3, $f5bc (=-$a44)
                800C9854	sw     v1, $0010(sp)
                [SP + 14] = w(80151a4c + T0 * b9c);
                funccd860;
                800CA9B8	j      Lcd208 [$800cd208]

                Lc986c:	; 800C986C
                800C986C	addiu  s0, s3, $0016
                800C9870	lui    a0, $8015
                800C9874	lh     a0, $1774(a0)
                800C9878	jal    battle_calculate_middle_point_from_target_mask_units_position [$800d54ec]
                800C987C	addu   a1, s0, zero
                800C9880	lw     a1, $0004(s3)
                800C9884	lhu    a2, $0012(s3)
                800C9888	lui    a3, $800d
                800C988C	addiu  a3, a3, $f5bc (=-$a44)
                800C9894	addu   a0, s1, zero
                [SP + 14] = w(S0);
                [SP + 10] = w(hu[S3 + 10]);
                funccd860;
                800CAA04	j      Lcd208 [$800cd208]



                case d1: // 43
                {
                    unit_id = S5 >> 10;
                    A0 = unit_id;
                    A1 = w[1f800024]; // script pointer
                    funccd558; // read two bytes
                    [1f800032] = h(V0); // 1st value

                    A0 = unit_id;
                    A1 = w[1f800024];;
                    funccd558; // read two bytes
                    [1f800000] = w(V0); // 2nd value

                    A0 = bu[80151920 + unit_id * b9c];
                    [80151920 + unit_id * b9c] = b(A0 + 1);
                    V0 = w[1f800024];
                    V1 = bu[A0 + V0];
                    [1f800030] = h(V1); // 3rd value

                    if (bu[801031f0] == 0) // if single attack
                    {
                        A0 = unit_id;
                        A2 = hu[1f800032];
                        A3 = 800cf5bc;
                        [SP + 10] = w(hu[1f800030]);
                        T0 = bu[800f99e8];
                        [SP + 14] = w(801518e4 + T0 * b9c + 168); // X position of unit
                        funccd860;
                    }
                    else
                    {
                        A0 = h[80151774];
                        A1 = 1f800036;
                        battle_calculate_middle_point_from_target_mask_units_position;

                        A0 = unit_id;
                        A2 = hu[1f800032];
                        A3 = 800cf5bc;
                        [SP + 10] = w(hu[1f800030]);
                        [SP + 14] = w(1f800036);
                        funccd860;
                    }
                }
                break;



                800C9990	sra    s0, s5, $10
                800C9994	lw     a1, $0004(s3)
                800C9998	jal    funccd558 [$800cd558]
                800C999C	addu   a0, s0, zero
                800C99A0	addu   a0, s0, zero
                800C99A4	sll    v0, v0, $10
                800C99A8	lw     a1, $0004(s3)
                800C99AC	sra    v0, v0, $10
                800C99B0	jal    funccd558 [$800cd558]
                800C99B4	sw     v0, $0000(s6)
                800C99B8	sll    v0, v0, $10
                800C99BC	sra    v0, v0, $10
                800C99C0	sll    v1, s0, $01
                800C99C4	addu   v1, v1, s0
                800C99C8	sw     v0, $0000(s7)
                800C99CC	sll    v0, v1, $05
                800C99D0	subu   v0, v0, v1
                800C99D4	sll    v0, v0, $03
                800C99D8	subu   v0, v0, s0
                800C99DC	sll    v0, v0, $02
                800C99E0	lui    at, $8015
                800C99E4	addiu  at, at, $1920
                800C99E8	addu   at, at, v0
                800C99EC	lbu    a0, $0000(at)
                800C99F0	nop
                800C99F4	addiu  v1, a0, $0001
                800C99F8	lui    at, $8015
                800C99FC	addiu  at, at, $1920
                800C9A00	addu   at, at, v0
                800C9A04	sb     v1, $0000(at)
                800C9A08	lw     v0, $0004(s3)
                800C9A0C	lw     t2, $0030(sp)
                800C9A10	addu   a0, a0, v0
                800C9A14	lbu    v0, $0000(a0)
                800C9A18	lui    a0, $800d
                800C9A1C	addiu  a0, a0, $f4a8 (=-$b58)
                800C9A20	jal    funcbbf7c [$800bbf7c]
                800C9A24	sw     v0, $0000(t2)
                800C9A28	sll    a0, v0, $05
                800C9A2C	lui    at, $8016
                800C9A30	addiu  at, at, $20b4
                800C9A34	addu   at, at, a0
                800C9A38	sh     fp, $0000(at)
                800C9A3C	lhu    v1, $0000(s6)
                800C9A40	nop
                800C9A44	lui    at, $8016
                800C9A48	addiu  at, at, $20b6
                800C9A4C	addu   at, at, a0
                800C9A50	sh     v1, $0000(at)
                800C9A54	lhu    v1, $0000(s7)
                800C9A58	nop
                800C9A5C	lui    at, $8016
                800C9A60	addiu  at, at, $20b8
                800C9A64	addu   at, at, a0
                800C9A68	sh     v1, $0000(at)
                800C9A6C	lw     t2, $0030(sp)
                800C9A70	nop
                800C9A74	lhu    v1, $0000(t2)
                800C9A78	lui    at, $1f80
                800C9A7C	sw     v0, $000c(at)
                800C9A80	lui    at, $8016
                800C9A84	addiu  at, at, $20b0
                800C9A88	addu   at, at, a0
                800C9A8C	sh     v1, $0000(at)
                800C9A90	j      Lcd208 [$800cd208]
                800C9A94	nop
                800C9A98	sra    a0, s5, $10
                800C9A9C	sll    v1, a0, $01
                800C9AA0	addu   v1, v1, a0
                800C9AA4	sll    v0, v1, $05
                800C9AA8	subu   v0, v0, v1
                800C9AAC	sll    v0, v0, $03
                800C9AB0	subu   v0, v0, a0
                800C9AB4	sll    v0, v0, $02
                800C9AB8	ori    v1, zero, $0001
                800C9ABC	lui    at, $8015
                800C9AC0	addiu  at, at, $190a
                800C9AC4	addu   at, at, v0
                800C9AC8	sb     v1, $0000(at)
                800C9ACC	jal    funcce058 [$800ce058]
                800C9AD0	nop
                800C9AD4	lui    a0, $800c
                800C9AD8	addiu  a0, a0, $3950
                800C9ADC	jal    funcbbf7c [$800bbf7c]
                800C9AE0	nop
                800C9AE4	sb     v0, $0014(s3)
                800C9AE8	lbu    v0, $0014(s3)
                800C9AEC	nop
                800C9AF0	sll    v0, v0, $05
                800C9AF4	lui    at, $8016
                800C9AF8	addiu  at, at, $20b4
                800C9AFC	addu   at, at, v0
                800C9B00	sh     fp, $0000(at)
                800C9B04	lbu    v0, $0014(s3)
                800C9B08	nop
                800C9B0C	sll    v0, v0, $05
                800C9B10	lui    at, $8016
                800C9B14	addiu  at, at, $20b6
                800C9B18	addu   at, at, v0
                800C9B1C	sh     zero, $0000(at)
                800C9B20	lbu    v0, $0014(s3)
                800C9B24	ori    v1, zero, $0001
                800C9B28	sll    v0, v0, $05
                800C9B2C	lui    at, $8016
                800C9B30	addiu  at, at, $20b2
                800C9B34	addu   at, at, v0
                800C9B38	sh     v1, $0000(at)
                800C9B3C	j      Lcd208 [$800cd208]
                800C9B40	nop
                800C9B44	sra    a0, s5, $10
                800C9B48	sll    v0, a0, $01
                800C9B4C	addu   v0, v0, a0
                800C9B50	sll    v1, v0, $05
                800C9B54	subu   v1, v1, v0
                800C9B58	sll    v1, v1, $03
                800C9B5C	subu   v1, v1, a0
                800C9B60	sll    v1, v1, $02
                800C9B64	lui    at, $8015
                800C9B68	addiu  at, at, $1909
                800C9B6C	addu   at, at, v1
                800C9B70	lbu    v0, $0000(at)
                800C9B74	nop
                800C9B78	andi   v0, v0, $007f
                800C9B7C	ori    v0, v0, $0004
                800C9B80	lui    at, $8015
                800C9B84	addiu  at, at, $1909
                800C9B88	addu   at, at, v1
                800C9B8C	sb     v0, $0000(at)
                800C9B90	j      Lcd208 [$800cd208]
                800C9B94	nop
                800CAF2C	jal    funcce21c [$800ce21c]
                800CAF30	ori    a1, zero, $0001
                800CAF34	j      Lcd208 [$800cd208]
                800CAF38	nop
                800C9B9C	sra    a0, s5, $10
                800C9BA0	lui    v0, $800f
                800C9BA4	lbu    v0, $eb24(v0)
                800C9BA8	nop
                800C9BAC	bne    v0, zero, Lc9bd0 [$800c9bd0]
                800C9BB0	sra    s0, s5, $10
                800C9BB4	ori    a0, zero, $0185
                800C9BB8	addiu  a1, zero, $ffff (=-$1)
                800C9BBC	jal    funcbba84 [$800bba84]
                800C9BC0	ori    a2, zero, $0040
                800C9BC4	ori    v0, zero, $0001
                800C9BC8	lui    at, $800f
                800C9BCC	sb     v0, $eb24(at)

                Lc9bd0:	; 800C9BD0
                800C9BD0	lw     a1, $0004(s3)
                800C9BD4	jal    funccd558 [$800cd558]
                800C9BD8	addu   a0, s0, zero
                800C9BDC	sll    v0, v0, $10
                800C9BE0	sra    v0, v0, $10
                800C9BE4	sll    v1, s0, $01
                800C9BE8	addu   v1, v1, s0
                800C9BEC	lui    at, $1f80
                800C9BF0	sw     v0, $0004(at)
                800C9BF4	sll    v0, v1, $05
                800C9BF8	subu   v0, v0, v1
                800C9BFC	sll    v0, v0, $03
                800C9C00	subu   v0, v0, s0
                800C9C04	sll    v0, v0, $02
                800C9C08	lui    at, $8015
                800C9C0C	addiu  at, at, $1920
                800C9C10	addu   at, at, v0
                800C9C14	lbu    a0, $0000(at)
                800C9C18	nop
                800C9C1C	addiu  v1, a0, $0001
                800C9C20	lui    at, $8015
                800C9C24	addiu  at, at, $1920
                800C9C28	addu   at, at, v0
                800C9C2C	sb     v1, $0000(at)
                800C9C30	lw     v0, $0004(s3)
                800C9C34	lw     t2, $0030(sp)
                800C9C38	addu   a0, a0, v0
                800C9C3C	lbu    v0, $0000(a0)
                800C9C40	lui    a0, $800d
                800C9C44	addiu  a0, a0, $f4a8 (=-$b58)
                800C9C48	jal    funcbbf7c [$800bbf7c]
                800C9C4C	sw     v0, $0000(t2)
                800C9C50	sll    v1, v0, $05
                800C9C54	lui    at, $8016
                800C9C58	addiu  at, at, $20b4
                800C9C5C	addu   at, at, v1
                800C9C60	sh     fp, $0000(at)
                800C9C64	lui    at, $8016
                800C9C68	addiu  at, at, $20b6
                800C9C6C	addu   at, at, v1
                800C9C70	sh     zero, $0000(at)
                800C9C74	lw     t2, $0030(sp)
                800C9C78	lui    a1, $8010
                800C9C7C	lbu    a1, $a6d0(a1)
                800C9C80	lhu    a0, $0000(t2)
                800C9C84	lui    at, $1f80
                800C9C88	sw     v0, $000c(at)
                800C9C8C	sltiu  v0, a1, $0009
                800C9C90	lui    at, $8016
                800C9C94	addiu  at, at, $20b0
                800C9C98	addu   at, at, v1
                800C9C9C	sh     a0, $0000(at)
                800C9CA0	beq    v0, zero, Lc9dd8 [$800c9dd8]
                800C9CA4	sll    v0, a1, $02
                800C9CA8	lui    at, $800a
                800C9CAC	addiu  at, at, $0aa0
                800C9CB0	addu   at, at, v0
                800C9CB4	lw     v0, $0000(at)
                800C9CB8	nop
                800C9CBC	jr     v0 
                800C9CC0	nop

                800C9CC4	sra    a0, s5, $10
                800C9CC8	sll    v1, a0, $01
                800C9CCC	addu   v1, v1, a0
                800C9CD0	sll    v0, v1, $05
                800C9CD4	subu   v0, v0, v1
                800C9CD8	sll    v0, v0, $03
                800C9CDC	subu   v0, v0, a0
                800C9CE0	sll    v0, v0, $02
                800C9CE4	lui    at, $8015
                800C9CE8	addiu  at, at, $18fc
                800C9CEC	addu   at, at, v0
                800C9CF0	lh     v0, $0000(at)
                800C9CF4	nop
                800C9CF8	bne    v0, zero, Lc9d1c [$800c9d1c]
                800C9CFC	nop
                800C9D00	lui    v0, $1f80
                800C9D04	lw     v0, $0004(v0)
                800C9D08	nop
                800C9D0C	lui    at, $1f80
                800C9D10	sw     v0, $0010(at)
                800C9D14	j      Lc9dd8 [$800c9dd8]
                800C9D18	nop

                Lc9d1c:	; 800C9D1C
                800C9D1C	lui    v0, $1f80
                800C9D20	lw     v0, $0004(v0)
                800C9D24	nop
                800C9D28	subu   v0, zero, v0
                800C9D2C	lui    at, $1f80
                800C9D30	sw     v0, $0010(at)
                800C9D34	j      Lc9dd8 [$800c9dd8]
                800C9D38	nop
                800C9D3C	lui    v0, $8016
                800C9D40	lhu    v0, $3780(v0)
                800C9D44	nop
                800C9D48	beq    v0, zero, Lc9d94 [$800c9d94]
                800C9D4C	sra    a0, s5, $10
                800C9D50	sll    v1, a0, $01
                800C9D54	addu   v1, v1, a0
                800C9D58	sll    v0, v1, $05
                800C9D5C	subu   v0, v0, v1
                800C9D60	sll    v0, v0, $03
                800C9D64	subu   v0, v0, a0
                800C9D68	lui    v1, $1f80
                800C9D6C	lw     v1, $0004(v1)
                800C9D70	sll    v0, v0, $02
                800C9D74	lui    at, $8015
                800C9D78	addiu  at, at, $1a46
                800C9D7C	addu   at, at, v0
                800C9D80	sh     zero, $0000(at)
                800C9D84	lui    at, $1f80
                800C9D88	sw     v1, $0010(at)
                800C9D8C	j      Lc9dd8 [$800c9dd8]
                800C9D90	nop

                Lc9d94:	; 800C9D94
                800C9D94	sll    v1, a0, $01
                800C9D98	addu   v1, v1, a0
                800C9D9C	sll    v0, v1, $05
                800C9DA0	subu   v0, v0, v1
                800C9DA4	sll    v0, v0, $03
                800C9DA8	subu   v0, v0, a0
                800C9DAC	sll    v0, v0, $02
                800C9DB0	lui    a0, $1f80
                800C9DB4	lw     a0, $0004(a0)
                800C9DB8	ori    v1, zero, $0800
                800C9DBC	lui    at, $8015
                800C9DC0	addiu  at, at, $1a46
                800C9DC4	addu   at, at, v0
                800C9DC8	sh     v1, $0000(at)
                800C9DCC	subu   a0, zero, a0
                800C9DD0	lui    at, $1f80
                800C9DD4	sw     a0, $0010(at)

                Lc9dd8:	; 800C9DD8
                800C9DD8	lui    v0, $1f80
                800C9DDC	lw     v0, $000c(v0)
                800C9DE0	lui    v1, $1f80
                800C9DE4	lhu    v1, $0010(v1)
                800C9DE8	sll    v0, v0, $05
                800C9DEC	lui    at, $8016
                800C9DF0	addiu  at, at, $20b8
                800C9DF4	addu   at, at, v0
                800C9DF8	sh     v1, $0000(at)
                800C9DFC	j      Lcd208 [$800cd208]
                800C9E00	nop
                800C9E04	sra    s0, s5, $10
                800C9E08	lw     a1, $0004(s3)
                800C9E0C	ori    v0, zero, $0001
                800C9E10	lui    at, $8016
                800C9E14	sb     v0, $2090(at)
                800C9E18	jal    funccd558 [$800cd558]
                800C9E1C	addu   a0, s0, zero
                800C9E20	lw     a1, $0004(s3)
                800C9E24	addu   a0, s0, zero
                800C9E28	jal    funccd558 [$800cd558]
                800C9E2C	sh     v0, $0012(s3)
                800C9E30	andi   a0, fp, $00ff
                800C9E34	sll    a3, v0, $10
                800C9E38	lui    a1, $8010
                800C9E3C	lbu    a1, $99e8(a1)
                800C9E40	lhu    a2, $0012(s3)
                800C9E44	sra    a3, a3, $10
                800C9E48	sh     v0, $000c(s3)
                800C9E4C	sll    a2, a2, $10
                800C9E50	jal    funccd5e4 [$800cd5e4]
                800C9E54	sra    a2, a2, $10
                800C9E58	j      Lcd208 [$800cd208]
                800C9E5C	nop
                800C9E60	lui    v1, $8010
                800C9E64	lbu    v1, $afe0(v1)
                800C9E68	nop
                800C9E6C	sll    a0, v1, $01
                800C9E70	addu   a0, a0, v1
                800C9E74	sll    v0, a0, $05
                800C9E78	subu   v0, v0, a0
                800C9E7C	sll    v0, v0, $03
                800C9E80	subu   v0, v0, v1
                800C9E84	sll    a0, a0, $01
                800C9E88	lui    at, $8016
                800C9E8C	addiu  at, at, $3c80
                800C9E90	addu   at, at, a0
                800C9E94	lhu    v1, $0000(at)
                800C9E98	sll    v0, v0, $02
                800C9E9C	lui    at, $8015
                800C9EA0	addiu  at, at, $1a4c
                800C9EA4	addu   at, at, v0
                800C9EA8	sh     v1, $0000(at)
                800C9EAC	lui    at, $8016
                800C9EB0	addiu  at, at, $3c82
                800C9EB4	addu   at, at, a0
                800C9EB8	lhu    v1, $0000(at)
                800C9EBC	nop
                800C9EC0	lui    at, $8015
                800C9EC4	addiu  at, at, $1a4e
                800C9EC8	addu   at, at, v0
                800C9ECC	sh     v1, $0000(at)
                800C9ED0	lui    at, $8016
                800C9ED4	addiu  at, at, $3c84
                800C9ED8	addu   at, at, a0
                800C9EDC	lhu    v1, $0000(at)
                800C9EE0	nop
                800C9EE4	lui    at, $8015
                800C9EE8	addiu  at, at, $1a50
                800C9EEC	addu   at, at, v0
                800C9EF0	sh     v1, $0000(at)
                800C9EF4	j      Lcd208 [$800cd208]
                800C9EF8	nop
                800C9EFC	sra    s0, s5, $10
                800C9F00	lw     a1, $0004(s3)
                800C9F04	jal    funccd558 [$800cd558]
                800C9F08	addu   a0, s0, zero
                800C9F0C	addu   a0, s0, zero
                800C9F10	sll    v0, v0, $10
                800C9F14	lw     a1, $0004(s3)
                800C9F18	sra    v0, v0, $10
                800C9F1C	sw     v0, $0000(s6)
                800C9F20	jal    funccd558 [$800cd558]
                800C9F24	sh     zero, $0012(s3)
                800C9F28	sh     v0, $000c(s3)
                800C9F2C	sll    v0, s0, $01
                800C9F30	addu   v0, v0, s0
                800C9F34	sll    s1, v0, $05
                800C9F38	subu   s1, s1, v0
                800C9F3C	sll    s1, s1, $03
                800C9F40	subu   s1, s1, s0
                800C9F44	lui    a2, $8010
                800C9F48	lbu    a2, $afe0(a2)
                800C9F4C	sll    s1, s1, $02
                800C9F50	sll    a0, a2, $01
                800C9F54	addu   a0, a0, a2
                800C9F58	sll    v1, a0, $01
                800C9F5C	sll    a1, a0, $05
                800C9F60	subu   a1, a1, a0
                800C9F64	lui    at, $8016
                800C9F68	addiu  at, at, $3c80
                800C9F6C	addu   at, at, v1
                800C9F70	lhu    v0, $0000(at)
                800C9F74	lui    a0, $8016
                800C9F78	lbu    a0, $90cc(a0)
                800C9F7C	sll    a1, a1, $03
                800C9F80	lui    at, $8015
                800C9F84	addiu  at, at, $1a4c
                800C9F88	addu   at, at, s1
                800C9F8C	sh     v0, $0000(at)
                800C9F90	lui    at, $8016
                800C9F94	addiu  at, at, $3c82
                800C9F98	addu   at, at, v1
                800C9F9C	lhu    v0, $0000(at)
                800C9FA0	subu   a1, a1, a2
                800C9FA4	lui    at, $8015
                800C9FA8	addiu  at, at, $1a4e
                800C9FAC	addu   at, at, s1
                800C9FB0	sh     v0, $0000(at)
                800C9FB4	lui    at, $8016
                800C9FB8	addiu  at, at, $3c84
                800C9FBC	addu   at, at, v1
                800C9FC0	lhu    v0, $0000(at)
                800C9FC4	sll    a1, a1, $02
                800C9FC8	lui    at, $8015
                800C9FCC	addiu  at, at, $1a50
                800C9FD0	addu   at, at, s1
                800C9FD4	sh     v0, $0000(at)
                800C9FD8	lui    at, $8015
                800C9FDC	addiu  at, at, $18fc
                800C9FE0	addu   at, at, a1
                800C9FE4	lhu    v0, $0000(at)
                800C9FE8	sll    v1, a0, $01
                800C9FEC	lui    at, $8015
                800C9FF0	addiu  at, at, $1a46
                800C9FF4	addu   at, at, s1
                800C9FF8	sh     v0, $0000(at)
                800C9FFC	lhu    v0, $0000(s6)
                800CA000	addu   v1, v1, a0
                800CA004	sh     zero, $000c(s3)
                800CA008	sh     v0, $0012(s3)
                800CA00C	sll    v0, v1, $05
                800CA010	subu   v0, v0, v1
                800CA014	sll    v0, v0, $03
                800CA018	subu   v0, v0, a0
                800CA01C	sll    v0, v0, $02
                800CA020	ori    v1, zero, $0800
                800CA024	lui    at, $8015
                800CA028	addiu  at, at, $1a46
                800CA02C	addu   at, at, v0
                800CA030	lhu    a0, $0000(at)
                800CA034	lhu    v0, $0012(s3)
                800CA038	subu   v1, v1, a0
                800CA03C	sll    v0, v0, $10
                800CA040	sh     v1, $0008(s3)
                800CA044	lui    at, $8015
                800CA048	addiu  at, at, $18ea
                800CA04C	addu   at, at, a1
                800CA050	lh     v1, $0000(at)
                800CA054	sra    v0, v0, $10
                800CA058	mult   v0, v1
                800CA05C	lui    at, $8015
                800CA060	addiu  at, at, $18f6
                800CA064	addu   at, at, s1
                800CA068	lh     v1, $0000(at)
                800CA06C	mflo   a1
                800CA070	lui    at, $8015
                800CA074	addiu  at, at, $18ea
                800CA078	addu   at, at, s1
                800CA07C	lh     v0, $0000(at)
                800CA080	nop
                800CA084	mult   v1, v0
                800CA088	lhu    a0, $0008(s3)
                800CA08C	nop
                800CA090	sll    a0, a0, $10
                800CA094	sra    a0, a0, $10
                800CA098	sra    a1, a1, $0c
                800CA09C	mflo   v0
                800CA0A0	sra    v0, v0, $0c
                800CA0A4	addu   a1, a1, v0
                800CA0A8	jal    system_get_sin [$80039a74]
                800CA0AC	sh     a1, $000a(s3)
                800CA0B0	lhu    v1, $000a(s3)
                800CA0B4	nop
                800CA0B8	sll    v1, v1, $10
                800CA0BC	sra    v1, v1, $10
                800CA0C0	mult   v0, v1
                800CA0C4	lui    a0, $8010
                800CA0C8	lbu    a0, $afe0(a0)
                800CA0CC	nop
                800CA0D0	sll    v0, a0, $01
                800CA0D4	addu   v0, v0, a0
                800CA0D8	sll    v1, v0, $05
                800CA0DC	subu   v1, v1, v0
                800CA0E0	sll    v1, v1, $03
                800CA0E4	subu   v1, v1, a0
                800CA0E8	sll    v1, v1, $02
                800CA0EC	lui    at, $8015
                800CA0F0	addiu  at, at, $1a4c
                800CA0F4	addu   at, at, s1
                800CA0F8	lhu    a0, $0000(at)
                800CA0FC	mflo   v0
                800CA100	sra    v0, v0, $0c
                800CA104	subu   a0, a0, v0
                800CA108	lui    at, $8015
                800CA10C	addiu  at, at, $1a4c
                800CA110	addu   at, at, v1
                800CA114	sh     a0, $0000(at)
                800CA118	lhu    a0, $0008(s3)
                800CA11C	nop
                800CA120	sll    a0, a0, $10
                800CA124	jal    system_get_cos [$80039b40]
                800CA128	sra    a0, a0, $10
                800CA12C	lhu    v1, $000a(s3)
                800CA130	nop
                800CA134	sll    v1, v1, $10
                800CA138	sra    v1, v1, $10
                800CA13C	mult   v0, v1
                800CA140	lui    a0, $8010
                800CA144	lbu    a0, $afe0(a0)
                800CA148	nop
                800CA14C	sll    v0, a0, $01
                800CA150	addu   v0, v0, a0
                800CA154	sll    v1, v0, $05
                800CA158	subu   v1, v1, v0
                800CA15C	sll    v1, v1, $03
                800CA160	subu   v1, v1, a0
                800CA164	sll    v1, v1, $02
                800CA168	lui    at, $8015
                800CA16C	addiu  at, at, $1a50
                800CA170	addu   at, at, s1
                800CA174	lhu    a0, $0000(at)
                800CA178	mflo   v0
                800CA17C	sra    v0, v0, $0c
                800CA180	addu   a0, a0, v0
                800CA184	lui    at, $8015
                800CA188	addiu  at, at, $1a50
                800CA18C	addu   at, at, v1
                800CA190	sh     a0, $0000(at)
                800CA194	lhu    v0, $000c(s3)
                800CA198	nop
                800CA19C	lui    at, $8015
                800CA1A0	addiu  at, at, $1a4e
                800CA1A4	addu   at, at, v1
                800CA1A8	sh     v0, $0000(at)
                800CA1AC	j      Lcd208 [$800cd208]
                800CA1B0	nop
                800CA1B4	sra    s0, s5, $10
                800CA1B8	sll    v1, s0, $01
                800CA1BC	addu   v1, v1, s0
                800CA1C0	sll    v0, v1, $05
                800CA1C4	subu   v0, v0, v1
                800CA1C8	sll    v0, v0, $03
                800CA1CC	subu   v0, v0, s0
                800CA1D0	sll    v0, v0, $02
                800CA1D4	sh     zero, $0012(s3)
                800CA1D8	lui    at, $1f80
                800CA1DC	sw     zero, $0000(at)
                800CA1E0	lui    at, $8015
                800CA1E4	addiu  at, at, $1920
                800CA1E8	addu   at, at, v0
                800CA1EC	lbu    a1, $0000(at)
                800CA1F0	addiu  s1, s3, $0016
                800CA1F4	addiu  v1, a1, $0001
                800CA1F8	lui    at, $8015
                800CA1FC	addiu  at, at, $1920
                800CA200	addu   at, at, v0
                800CA204	sb     v1, $0000(at)
                800CA208	lw     v0, $0004(s3)
                800CA20C	lui    a0, $8015
                800CA210	lh     a0, $1774(a0)
                800CA214	addu   a1, a1, v0
                800CA218	lbu    v0, $0000(a1)
                800CA21C	addu   a1, s1, zero
                800CA220	jal    battle_calculate_middle_point_from_target_mask_units_position [$800d54ec]
                800CA224	sh     v0, $0010(s3)
                800CA228	addu   a0, s0, zero
                800CA22C	lw     a1, $0004(s3)
                800CA230	lhu    a2, $0012(s3)
                800CA234	lui    a3, $800d
                800CA238	addiu  a3, a3, $f5bc (=-$a44)
                800CA23C	sw     s1, $0014(sp)
                800CA240	lhu    v0, $0016(s3)
                800CA244	lhu    v1, $001a(s3)
                800CA248	sll    a2, a2, $10
                800CA24C	sra    a2, a2, $10
                800CA250	sll    v0, v0, $10
                800CA254	sra    v0, v0, $0f
                800CA258	sll    v1, v1, $10
                800CA25C	sh     v0, $0016(s3)
                800CA260	lhu    v0, $0010(s3)
                800CA264	sra    v1, v1, $0f
                800CA26C	sh     v1, $001a(s3)
                [SP + 10] = w(V0);
                funccd860;
                800CAA04	j      Lcd208 [$800cd208]

                800CA270	sra    a0, s5, $10
                800CA274	sll    v1, a0, $01
                800CA278	addu   v1, v1, a0
                800CA27C	sll    v0, v1, $05
                800CA280	subu   v0, v0, v1
                800CA284	sll    v0, v0, $03
                800CA288	subu   v0, v0, a0
                800CA28C	sll    v0, v0, $02
                800CA290	lui    at, $8015
                800CA294	addiu  at, at, $1920
                800CA298	addu   at, at, v0
                800CA29C	lbu    a0, $0000(at)
                800CA2A0	nop
                800CA2A4	addiu  v1, a0, $0001
                800CA2A8	lui    at, $8015
                800CA2AC	addiu  at, at, $1920
                800CA2B0	addu   at, at, v0
                800CA2B4	sb     v1, $0000(at)
                800CA2B8	lw     v0, $0004(s3)
                800CA2BC	nop
                800CA2C0	addu   a0, a0, v0
                800CA2C4	lbu    v1, $0000(a0)
                800CA2C8	ori    v0, zero, $00a4
                800CA2CC	lui    at, $800a
                800CA2D0	sh     v0, $a000(at)
                800CA2D4	lui    at, $800a
                800CA2D8	sw     zero, $a008(at)
                800CA2DC	lui    at, $800a
                800CA2E0	sw     v1, $a004(at)
                800CA2E4	jal    system_execute_AKAO [$8002da7c]
                800CA2E8	nop
                800CA2EC	j      Lcd208 [$800cd208]
                800CA2F0	nop
                800CA2F4	sra    a0, s5, $10
                800CA2F8	sll    v1, a0, $01
                800CA2FC	addu   v1, v1, a0
                800CA300	sll    v0, v1, $05
                800CA304	subu   v0, v0, v1
                800CA308	sll    v0, v0, $03
                800CA30C	subu   v0, v0, a0
                800CA310	sll    s0, v0, $02
                800CA314	lui    at, $8015
                800CA318	addiu  at, at, $1920
                800CA31C	addu   at, at, s0
                800CA320	lbu    v1, $0000(at)
                800CA324	nop
                800CA328	addiu  v0, v1, $0001
                800CA32C	lui    at, $8015
                800CA330	addiu  at, at, $1920
                800CA334	addu   at, at, s0
                800CA338	sb     v0, $0000(at)
                800CA33C	lw     v0, $0004(s3)
                800CA340	lw     a1, $0004(s3)
                800CA344	addu   v1, v1, v0
                800CA348	lbu    v0, $0000(v1)
                800CA34C	jal    funccd558 [$800cd558]
                800CA350	sw     v0, $0000(s6)
                800CA354	sll    v0, v0, $10
                800CA358	sra    v0, v0, $10
                800CA35C	sw     v0, $0000(s7)
                800CA360	lui    at, $8015
                800CA364	addiu  at, at, $1920
                800CA368	addu   at, at, s0
                800CA36C	lbu    v1, $0000(at)
                800CA370	nop
                800CA374	addiu  v0, v1, $0001
                800CA378	lui    at, $8015
                800CA37C	addiu  at, at, $1920
                800CA380	addu   at, at, s0
                800CA384	sb     v0, $0000(at)
                800CA388	lw     v0, $0004(s3)
                800CA38C	lw     t2, $0030(sp)
                800CA390	addu   v1, v1, v0
                800CA394	lbu    v0, $0000(v1)
                800CA398	nop
                800CA39C	sw     v0, $0000(t2)
                800CA3A0	lui    at, $8015
                800CA3A4	addiu  at, at, $1920
                800CA3A8	addu   at, at, s0
                800CA3AC	lbu    v1, $0000(at)
                800CA3B0	nop
                800CA3B4	addiu  v0, v1, $0001
                800CA3B8	lui    at, $8015
                800CA3BC	addiu  at, at, $1920
                800CA3C0	addu   at, at, s0
                800CA3C4	sb     v0, $0000(at)
                800CA3C8	lw     v0, $0004(s3)
                800CA3CC	lui    a2, $1f80
                800CA3D0	addu   v1, v1, v0
                800CA3D4	lbu    v0, $0000(v1)
                800CA3D8	ori    a2, a2, $0018
                800CA3DC	sw     v0, $0000(a2)
                800CA3E0	lui    at, $8015
                800CA3E4	addiu  at, at, $1920
                800CA3E8	addu   at, at, s0
                800CA3EC	lbu    v1, $0000(at)
                800CA3F0	nop
                800CA3F4	addiu  v0, v1, $0001
                800CA3F8	lui    at, $8015
                800CA3FC	addiu  at, at, $1920
                800CA400	addu   at, at, s0
                800CA404	sb     v0, $0000(at)
                800CA408	lw     v0, $0004(s3)
                800CA40C	lui    a1, $1f80
                800CA410	addu   v1, v1, v0
                800CA414	lbu    v0, $0000(v1)
                800CA418	ori    a1, a1, $001c
                800CA41C	sw     v0, $0000(a1)
                800CA420	lui    at, $8015
                800CA424	addiu  at, at, $1920
                800CA428	addu   at, at, s0
                800CA42C	lbu    v1, $0000(at)
                800CA430	nop
                800CA434	addiu  v0, v1, $0001
                800CA438	lui    at, $8015
                800CA43C	addiu  at, at, $1920
                800CA440	addu   at, at, s0
                800CA444	sb     v0, $0000(at)
                800CA448	lw     v0, $0004(s3)
                800CA44C	lui    a3, $1f80
                800CA450	addu   v1, v1, v0
                800CA454	lbu    v0, $0000(v1)
                800CA458	ori    a3, a3, $000c
                800CA45C	sw     v0, $0000(a3)
                800CA460	lui    at, $8015
                800CA464	addiu  at, at, $1920
                800CA468	addu   at, at, s0
                800CA46C	lbu    a0, $0000(at)
                800CA470	nop
                800CA474	addiu  v0, a0, $0001
                800CA478	lui    at, $8015
                800CA47C	addiu  at, at, $1920
                800CA480	addu   at, at, s0
                800CA484	sb     v0, $0000(at)
                800CA488	lw     v0, $0004(s3)
                800CA48C	lbu    v1, $0000(t2)
                800CA490	addu   a0, a0, v0
                800CA494	sll    v1, v1, $0a
                800CA498	lbu    v0, $0000(a2)
                800CA49C	lbu    t0, $0000(a0)
                800CA4A0	sll    v0, v0, $05
                800CA4A4	or     v1, v1, v0
                800CA4A8	lbu    v0, $0000(a1)
                800CA4AC	lui    at, $1f80
                800CA4B0	sw     t0, $0010(at)
                800CA4B4	or     a2, v1, v0
                800CA4B8	lui    at, $1f80
                800CA4BC	sw     a2, $0014(at)
                800CA4C0	lw     a1, $0000(s6)
                800CA4C4	ori    v0, zero, $00ff
                800CA4C8	bne    a1, v0, Lca4e8 [$800ca4e8]
                800CA4CC	nop
                800CA4D0	lui    a0, $8015
                800CA4D4	addiu  a0, a0, $1a24
                800CA4D8	lw     a1, $0000(s7)
                800CA4DC	lw     a3, $0000(a3)
                800CA4E0	j      Lca514 [$800ca514]
                800CA4E4	addu   a0, s0, a0

                Lca4e8:	; 800CA4E8
                800CA4E8	lui    t2, $8015
                800CA4EC	addiu  t2, t2, $1a58
                800CA4F0	addu   v0, s0, t2
                800CA4F4	sll    a0, a1, $01
                800CA4F8	addu   a0, a0, a1
                800CA4FC	sll    a0, a0, $02
                800CA500	addu   a0, a0, a1
                800CA504	sll    a0, a0, $02
                800CA508	lw     a1, $0000(s7)
                800CA50C	lw     a3, $0000(a3)
                800CA510	addu   a0, v0, a0

                Lca514:	; 800CA514
                800CA514	jal    funcd61ac [$800d61ac]
                800CA518	sw     t0, $0010(sp)
                800CA51C	j      Lcd208 [$800cd208]
                800CA520	nop
                800CA524	sra    s0, s5, $10
                800CA528	lw     a1, $0004(s3)
                800CA52C	jal    funccd558 [$800cd558]
                800CA530	addu   a0, s0, zero
                800CA534	lw     a1, $0004(s3)
                800CA538	addu   a0, s0, zero
                800CA53C	jal    funccd558 [$800cd558]
                800CA540	sh     v0, $0012(s3)
                800CA544	sll    v0, v0, $10
                800CA548	lw     a1, $0004(s3)
                800CA54C	sra    v0, v0, $10
                800CA550	lui    at, $1f80
                800CA554	sw     v0, $0004(at)
                800CA558	jal    funccd558 [$800cd558]
                800CA55C	addu   a0, s0, zero
                800CA560	sll    v0, v0, $10
                800CA564	sra    v0, v0, $10
                800CA568	lui    at, $1f80
                800CA56C	sw     v0, $0000(at)
                800CA570	sll    v0, s0, $01
                800CA574	addu   v0, v0, s0
                800CA578	sll    v1, v0, $05
                800CA57C	subu   v1, v1, v0
                800CA580	sll    v1, v1, $03
                800CA584	subu   v1, v1, s0
                800CA588	sll    v1, v1, $02
                800CA58C	lui    at, $8015
                800CA590	addiu  at, at, $1920
                800CA594	addu   at, at, v1
                800CA598	lbu    a0, $0000(at)
                800CA59C	lui    t1, $1f80
                800CA5A0	addiu  v0, a0, $0001
                800CA5A4	lui    at, $8015
                800CA5A8	addiu  at, at, $1920
                800CA5AC	addu   at, at, v1
                800CA5B0	sb     v0, $0000(at)
                800CA5B4	lw     v0, $0004(s3)
                800CA5B8	nop
                800CA5BC	addu   a0, a0, v0
                800CA5C0	lbu    v0, $0000(a0)
                800CA5C4	lui    a3, $800d
                800CA5C8	addiu  a3, a3, $fe60 (=-$1a0)
                800CA5CC	j      Lca67c [$800ca67c]
                800CA5D0	ori    t1, t1, $000c
                800CA5D4	sra    s0, s5, $10
                800CA5D8	lw     a1, $0004(s3)
                800CA5DC	jal    funccd558 [$800cd558]
                800CA5E0	addu   a0, s0, zero
                800CA5E4	lw     a1, $0004(s3)
                800CA5E8	addu   a0, s0, zero
                800CA5EC	jal    funccd558 [$800cd558]
                800CA5F0	sh     v0, $0012(s3)
                800CA5F4	sll    v0, v0, $10
                800CA5F8	lw     a1, $0004(s3)
                800CA5FC	sra    v0, v0, $10
                800CA600	lui    at, $1f80
                800CA604	sw     v0, $0004(at)
                800CA608	jal    funccd558 [$800cd558]
                800CA60C	addu   a0, s0, zero
                800CA610	sll    v0, v0, $10
                800CA614	sra    v0, v0, $10
                800CA618	lui    at, $1f80
                800CA61C	sw     v0, $0000(at)
                800CA620	sll    v0, s0, $01
                800CA624	addu   v0, v0, s0
                800CA628	sll    v1, v0, $05
                800CA62C	subu   v1, v1, v0
                800CA630	sll    v1, v1, $03
                800CA634	subu   v1, v1, s0
                800CA638	sll    v1, v1, $02
                800CA63C	lui    at, $8015
                800CA640	addiu  at, at, $1920
                800CA644	addu   at, at, v1
                800CA648	lbu    a0, $0000(at)
                800CA64C	lui    t1, $1f80
                800CA650	addiu  v0, a0, $0001
                800CA654	lui    at, $8015
                800CA658	addiu  at, at, $1920
                800CA65C	addu   at, at, v1
                800CA660	sb     v0, $0000(at)
                800CA664	lw     v0, $0004(s3)
                800CA668	ori    t1, t1, $000c
                800CA66C	addu   a0, a0, v0
                800CA670	lbu    v0, $0000(a0)
                800CA674	lui    a3, $800d
                800CA678	addiu  a3, a3, $01c0

                Lca67c:	; 800CA67C
                800CA67C	lui    at, $1f80
                800CA680	sw     v0, $0008(at)
                800CA684	lui    at, $8015
                800CA688	addiu  at, at, $1920
                800CA68C	addu   at, at, v1
                800CA690	lbu    t0, $0000(at)
                800CA694	addu   a0, s0, zero
                800CA698	addiu  v0, t0, $0001
                800CA69C	lui    at, $8015
                800CA6A0	addiu  at, at, $1920
                800CA6A4	addu   at, at, v1
                800CA6A8	sb     v0, $0000(at)
                800CA6AC	lw     a1, $0004(s3)
                800CA6B0	lw     v0, $0004(s3)
                800CA6B4	lhu    a2, $0012(s3)
                800CA6B8	addu   t0, t0, v0
                800CA6BC	sll    a2, a2, $10
                800CA6C0	lbu    v0, $0000(t0)
                800CA6C4	lui    t0, $8010
                800CA6C8	lbu    t0, $99e8(t0)
                800CA6CC	sra    a2, a2, $10
                800CA6D0	sll    v1, t0, $01
                800CA6D4	addu   v1, v1, t0
                800CA6D8	sw     v0, $0000(t1)
                800CA6DC	sll    v0, v1, $05
                800CA6E0	subu   v0, v0, v1
                800CA6E4	sll    v0, v0, $03
                800CA6E8	subu   v0, v0, t0
                800CA6EC	sll    v0, v0, $02
                800CA6F0	lui    t0, $8015
                800CA6F4	addiu  t0, t0, $1a4c
                800CA6F8	lhu    v1, $0000(t1)
                800CA6FC	addu   v0, v0, t0
                800CA700	sw     v0, $0014(sp)
                800CA704	sh     v1, $0010(s3)
                800CA708	sll    v1, v1, $10
                800CA70C	sra    v1, v1, $10

                Lca710:	; 800CA710
                800CA710	jal    funccd860 [$800cd860]
                800CA714	sw     v1, $0010(sp)
                800CA718	j      Lcd208 [$800cd208]
                800CA71C	nop
                800CA720	sra    a0, s5, $10
                800CA724	sll    v1, a0, $01
                800CA728	addu   v1, v1, a0
                800CA72C	sll    v0, v1, $05
                800CA730	subu   v0, v0, v1
                800CA734	sll    v0, v0, $03
                800CA738	subu   v0, v0, a0
                800CA73C	sll    a0, v0, $02
                800CA740	lui    at, $8015
                800CA744	addiu  at, at, $1920
                800CA748	addu   at, at, a0
                800CA74C	lbu    v1, $0000(at)
                800CA750	nop
                800CA754	addiu  v0, v1, $0001
                800CA758	lui    at, $8015
                800CA75C	addiu  at, at, $1920
                800CA760	addu   at, at, a0
                800CA764	sb     v0, $0000(at)
                800CA768	lw     v0, $0004(s3)
                800CA76C	nop
                800CA770	addu   v1, v1, v0
                800CA774	lbu    v0, $0000(v1)
                800CA778	nop
                800CA77C	lui    at, $1f80
                800CA780	sw     v0, $0008(at)
                800CA784	bne    v0, zero, Lca7bc [$800ca7bc]
                800CA788	nop
                800CA78C	lui    at, $8015
                800CA790	addiu  at, at, $1909
                800CA794	addu   at, at, a0
                800CA798	lbu    v0, $0000(at)
                800CA79C	nop
                800CA7A0	ori    v0, v0, $0004
                800CA7A4	lui    at, $8015
                800CA7A8	addiu  at, at, $1909
                800CA7AC	addu   at, at, a0
                800CA7B0	sb     v0, $0000(at)
                800CA7B4	j      Lcd208 [$800cd208]
                800CA7B8	nop

                Lca7bc:	; 800CA7BC
                800CA7BC	lui    at, $8015
                800CA7C0	addiu  at, at, $1909
                800CA7C4	addu   at, at, a0
                800CA7C8	lbu    v0, $0000(at)
                800CA7CC	nop
                800CA7D0	andi   v0, v0, $00fb
                800CA7D4	lui    at, $8015
                800CA7D8	addiu  at, at, $1909
                800CA7DC	addu   at, at, a0
                800CA7E0	sb     v0, $0000(at)
                800CA7E4	j      Lcd208 [$800cd208]
                800CA7E8	nop
                800CA7EC	sra    a0, s5, $10
                800CA7F0	sll    v0, a0, $01
                800CA7F4	addu   v0, v0, a0
                800CA7F8	sll    s0, v0, $05
                800CA7FC	subu   s0, s0, v0
                800CA800	sll    s0, s0, $03
                800CA804	subu   s0, s0, a0
                800CA808	sll    s0, s0, $02
                800CA80C	lui    at, $8015
                800CA810	addiu  at, at, $1920
                800CA814	addu   at, at, s0
                800CA818	lbu    v1, $0000(at)
                800CA81C	nop
                800CA820	addiu  v0, v1, $0001
                800CA824	lui    at, $8015
                800CA828	addiu  at, at, $1920
                800CA82C	addu   at, at, s0
                800CA830	sb     v0, $0000(at)
                800CA834	lw     v0, $0004(s3)
                800CA838	lui    a1, $1f80
                800CA83C	addu   v1, v1, v0
                800CA840	lbu    v0, $0000(v1)
                800CA844	ori    a1, a1, $000c
                800CA848	sw     v0, $0000(a1)
                800CA84C	addiu  v0, a0, $fffc (=-$4)
                800CA850	sll    v1, v0, $01
                800CA854	addu   v1, v1, v0
                800CA858	lhu    v0, $0000(a1)
                800CA85C	sll    v1, v1, $02
                800CA860	addiu  v0, v0, $0003
                800CA864	lui    at, $800f
                800CA868	addiu  at, at, $7e08
                800CA86C	addu   at, at, v1
                800CA870	sh     v0, $0000(at)
                800CA874	jal    funcb54b8 [$800b54b8]
                800CA878	nop
                800CA87C	lui    at, $8015
                800CA880	addiu  at, at, $1922
                800CA884	addu   at, at, s0
                800CA888	lbu    v0, $0000(at)
                800CA88C	nop
                800CA890	ori    v0, v0, $0001
                800CA894	lui    at, $8015
                800CA898	addiu  at, at, $1922
                800CA89C	addu   at, at, s0
                800CA8A0	sb     v0, $0000(at)
                800CA8A4	j      Lcd208 [$800cd208]
                800CA8A8	nop



                case d0: // 42
                {
                    S0 = S5 >> 10;
                    A0 = S0;
                    A1 = w[S3 + 4];
                    funccd558; // read two bytes
                    [1f800032] = h(V0);

                    V0 = S0 * b9c;
                    A0 = bu[80151920 + V0];
                    [80151920 + V0] = h(A0 + 1);
                    V0 = w[S3 + 4];
                    V1 = bu[A0 + V0];
                    [1f800000] = w(V1);

                    if (V1 >= 0)
                    {
                        if (V1 < 4)
                        {
                            [S3 + 10] = h(5);
                        }
                        if (V1 < 8)
                        {
                            [S3 + 10] = h(8);
                        }
                    }

                    V0 = bu[801031f0];
                    if (V0 == 0)
                    {
                        T0 = bu[800f99e8];
                        [SP + 14] = w(80151a4c + T0 * b9c);
                    }
                    else
                    {
                        A0 = h[80151774];
                        A1 = S3 + 16;
                        battle_calculate_middle_point_from_target_mask_units_position;

                        [SP + 14] = w(S3 + 16);
                    }

                    A0 = S5 >> 10;
                    A2 = hu[1f800032];
                    A3 = 800cfcb0;
                    [SP + 10] = w(hu[S3 + 10]);
                    funccd860;
                }
                break;



                case f3: // 65
                {
                    A0 = S5 >> 10;
                    V0 = bu[801518e4 + A0 * b9c + 3d];
                    if (V0 != 0)
                    {
                        [801518e4 + A0 * b9c + 3d] = b(V0 - 1);

                        // scroll back to this opcode
                        [801518e4 + A0 * b9c + 3c] = b(bu[801518e4 + A0 * b9c + 3c] - 1);
                        [1f800020] = b(0);

                        return;
                    }
                }
                break;



                case f4: // 66
                {
                    A0 = S5 >> 10;
                    V0 = bu[801518e4 + A0 * b9c + 3c];
                    [801518e4 + A0 * b9c + 3c] = b(V0 + 1);
                    [801518e4 + A0 * b9c + 3d] = b(bu[w[1f800024] + V0]);
                }
                break;



                case c5: // 37
                {
                    A0 = S5 >> 10;
                    [801518e4 + A0 * b9c + 3d] = b(bu[800f8374]);
                }
                break;



                case fa: // 6c
                {
                    A0 = FP & ff;
                    funccd798;
                }
                break;



                case c2: // 34
                {
                    unit_id = S5 >> 10;

                    A0 = bu[80151920 + unit_id * b9c];
                    [80151920 + unit_id * b9c] = b(A0 + 1);
                    V0 = bu[w[1f800024] + A0];
                    [S6] = w(V0);

                    A0 = 800ce7e0;
                    funcbbeac;
                    struct_id = V0;

                    [80162978 + struct_id * 20 + 8] = h(bu[800fa6d4]);

                    A0 = bu[800fa6d4]; // target id
                    funcb888c;
                    S2 = V0;

                    [80162978 + struct_id * 20 + 4] = h(hu[S6]);
                    [80162978 + struct_id * 20 + 6] = h(hu[800f99f4 + S2 * c]);
                    [80162978 + struct_id * 20 + a] = h(hu[800f99ec + S2 * c]);
                    [80162978 + struct_id * 20 + e] = h(hu[800f99ee + S2 * c]);
                    [80162978 + struct_id * 20 + 19] = b(bu[800f99f6 + S2 * c]);
 
                    800CAC9C	j      Lcd208 [$800cd208]
                }
                break;



                case f7: // (69)
                {
                    unit_id = S0 >> 10;
                    [800f8cf0] = b(0);

                    A0 = bu[80151920 + unit_id * b9c];
                    [80151920 + unit_id * b9c] = b(A0 + 1);
                    A1 = bu[w[1f800024] + A0];
                    A0 = h[80151774];
                    [1f800000] = w(A1);
                    A2 = 1;
                    funcd58d0;
                }
                break;



                800CAD24	sra    a0, s5, $10
                800CAD28	sll    v0, a0, $01
                800CAD2C	addu   v0, v0, a0
                800CAD30	sll    v1, v0, $05
                800CAD34	subu   v1, v1, v0
                800CAD38	sll    v1, v1, $03
                800CAD3C	subu   v1, v1, a0
                800CAD40	sll    v1, v1, $02
                800CAD44	lui    at, $8010
                800CAD48	sb     zero, $8cf0(at)
                800CAD4C	lui    at, $8015
                800CAD50	addiu  at, at, $1920
                800CAD54	addu   at, at, v1
                800CAD58	lbu    a0, $0000(at)
                800CAD5C	nop
                800CAD60	addiu  v0, a0, $0001
                800CAD64	lui    at, $8015
                800CAD68	addiu  at, at, $1920
                800CAD6C	addu   at, at, v1
                800CAD70	sb     v0, $0000(at)
                800CAD74	lw     v0, $0004(s3)
                800CAD78	nop
                800CAD7C	addu   a0, a0, v0
                800CAD80	lbu    v0, $0000(a0)
                800CAD84	nop
                800CAD88	sw     v0, $0000(s6)
                800CAD8C	lui    at, $8015
                800CAD90	addiu  at, at, $1920
                800CAD94	addu   at, at, v1
                800CAD98	lbu    a0, $0000(at)
                800CAD9C	nop
                800CADA0	addiu  v0, a0, $0001
                800CADA4	lui    at, $8015
                800CADA8	addiu  at, at, $1920
                800CADAC	addu   at, at, v1
                800CADB0	sb     v0, $0000(at)
                800CADB4	lw     v0, $0004(s3)
                800CADB8	nop
                800CADBC	addu   a0, a0, v0
                800CADC0	lbu    a1, $0000(a0)
                800CADC4	lw     a0, $0000(s6)
                800CADC8	lui    at, $1f80
                800CADCC	sw     a1, $0004(at)
                800CADD0	jal    funcd5a68 [$800d5a68]
                800CADD4	nop
                800CADD8	j      Lcd208 [$800cd208]
                800CADDC	nop

                case be: // (30)
                {
                    unit_id = S5 >> 10;
                    [800f8cf0] = b(1);

                    A0 = bu[80151920 + unit_id * b9c];
                    [80151920 + unit_id * b9c] = b(A0 + 1);
                    A1 = bu[w[1f800024] + A0];
                    [1f800000] = w(A1);


                    if (b[801636b8 + bu[801590cc] * 10 + 0] != 2 || A1 != 8 || (w[801636b8 + bu[800fa6d4] * 10 + 8] & 00000800) == 0)
                    {
                        A0 = h[80151774]; // target mask
                        A1 = w[1f800000];
                        A2 = 1;
                        funcd58d0;
                    }

                    800CAEC4	j      Lcd208 [$800cd208]
                }
                break;



                case f6: // 68
                {
                    A0 = S5 >> 10;
                    if (bu[800f8378] == 0)
                    {
                        V0 = h[80161de8]; // dead units mask?
                        V0 = V0 >> A0;
                        V0 = V0 & 1;
                    }
                    else
                    {
                        V0 = hu[8015120c + A0 * 74];
                        V0 = V0 & 10;
                    }

                    if (V0 != 0)
                    {
                        A1 = 1;
                        funcce21c; // play die effect
                    }
                }
                break;

                800CAF3C	sra    a0, s5, $10
                800CAF40	slti   v0, a0, $0004
                800CAF44	bne    v0, zero, Lcd208 [$800cd208]
                800CAF48	sll    v1, a0, $01
                800CAF4C	addu   v1, v1, a0
                800CAF50	sll    v0, v1, $05
                800CAF54	subu   v0, v0, v1
                800CAF58	sll    v0, v0, $03
                800CAF5C	subu   v0, v0, a0
                800CAF60	sll    a0, v0, $02
                800CAF64	ori    a1, zero, $00cd

                loopcaf68:	; 800CAF68
                800CAF68	lui    at, $8015
                800CAF6C	addiu  at, at, $1920
                800CAF70	addu   at, at, a0
                800CAF74	lbu    v1, $0000(at)
                800CAF78	nop
                800CAF7C	addiu  v0, v1, $0001
                800CAF80	lui    at, $8015
                800CAF84	addiu  at, at, $1920
                800CAF88	addu   at, at, a0
                800CAF8C	sb     v0, $0000(at)
                800CAF90	lw     v0, $0004(s3)
                800CAF94	nop
                800CAF98	addu   v1, v1, v0
                800CAF9C	lbu    v0, $0000(v1)
                800CAFA0	nop
                800CAFA4	bne    v0, a1, loopcaf68 [$800caf68]
                800CAFA8	nop
                800CAFAC	j      Lcd208 [$800cd208]
                800CAFB0	nop
                800CAFB4	sra    a0, s5, $10
                800CAFB8	sll    v0, a0, $03
                800CAFBC	subu   v0, v0, a0
                800CAFC0	sll    v0, v0, $02
                800CAFC4	addu   v0, v0, a0
                800CAFC8	sll    v0, v0, $02
                800CAFCC	lui    at, $8015
                800CAFD0	addiu  at, at, $1200
                800CAFD4	addu   at, at, v0
                800CAFD8	lw     v0, $0000(at)
                800CAFDC	nop
                800CAFE0	andi   v0, v0, $1000
                800CAFE4	beq    v0, zero, Lcd208 [$800cd208]
                800CAFE8	sll    v1, a0, $01
                800CAFEC	addu   v1, v1, a0
                800CAFF0	sll    v0, v1, $05
                800CAFF4	subu   v0, v0, v1
                800CAFF8	sll    v0, v0, $03
                800CAFFC	subu   v0, v0, a0
                800CB000	sll    a0, v0, $02
                800CB004	ori    a1, zero, $00b2

                loopcb008:	; 800CB008
                800CB008	lui    at, $8015
                800CB00C	addiu  at, at, $1920
                800CB010	addu   at, at, a0
                800CB014	lbu    v1, $0000(at)
                800CB018	nop
                800CB01C	addiu  v0, v1, $0001
                800CB020	lui    at, $8015
                800CB024	addiu  at, at, $1920
                800CB028	addu   at, at, a0
                800CB02C	sb     v0, $0000(at)
                800CB030	lw     v0, $0004(s3)
                800CB034	nop
                800CB038	addu   v1, v1, v0
                800CB03C	lbu    v0, $0000(v1)
                800CB040	nop
                800CB044	bne    v0, a1, loopcb008 [$800cb008]
                800CB048	nop
                800CB04C	j      Lcd208 [$800cd208]
                800CB050	nop
                800CB054	sra    a0, s5, $10
                800CB058	sll    v0, a0, $01
                800CB05C	addu   v0, v0, a0
                800CB060	sll    v1, v0, $05
                800CB064	subu   v1, v1, v0
                800CB068	sll    v1, v1, $03
                800CB06C	subu   v1, v1, a0
                800CB070	sll    v1, v1, $02
                800CB074	lui    at, $8015
                800CB078	addiu  at, at, $1920
                800CB07C	addu   at, at, v1
                800CB080	lbu    a0, $0000(at)
                800CB084	nop
                800CB088	addiu  v0, a0, $0001
                800CB08C	lui    at, $8015
                800CB090	addiu  at, at, $1920
                800CB094	addu   at, at, v1
                800CB098	sb     v0, $0000(at)
                800CB09C	lw     v0, $0004(s3)
                800CB0A0	nop
                800CB0A4	addu   a0, a0, v0
                800CB0A8	lbu    v0, $0000(a0)
                800CB0AC	nop
                800CB0B0	sw     v0, $0000(s6)
                800CB0B4	lui    at, $8015
                800CB0B8	addiu  at, at, $1920
                800CB0BC	addu   at, at, v1
                800CB0C0	lbu    a0, $0000(at)
                800CB0C4	nop
                800CB0C8	addiu  v0, a0, $0001
                800CB0CC	lui    at, $8015
                800CB0D0	addiu  at, at, $1920
                800CB0D4	addu   at, at, v1
                800CB0D8	sb     v0, $0000(at)
                800CB0DC	lw     v0, $0004(s3)
                800CB0E0	nop
                800CB0E4	addu   a0, a0, v0
                800CB0E8	lbu    v0, $0000(a0)
                800CB0EC	nop
                800CB0F0	sw     v0, $0000(s7)
                800CB0F4	lw     v1, $0000(s6)
                800CB0F8	lbu    v0, $0000(s7)
                800CB0FC	nop
                800CB100	lui    at, $8016
                800CB104	addiu  at, at, $6f68
                800CB108	addu   at, at, v1
                800CB10C	sb     v0, $0000(at)
                800CB110	jal    funccdda4 [$800cdda4]
                800CB114	nop
                800CB118	j      Lcd208 [$800cd208]
                800CB11C	nop

                case c1: (33)
                {
                    A0 = S5 >> 10;
                    [80151920 + A0 * b9c] = b(0);

                    A1 = c9;
                    loopcb158:	; 800CB158
                        V1 = bu[80151920 + A0 * b9c];
                        [80151920 + A0 * b9c] = b(V1 + 1);
                        V0 = bu[w[1f800024] + V1];
                    800CB194	bne    v0, a1, loopcb158 [$800cb158]
                }
                break;



                case ca: // 3c
                {
                    if (bu[801518dc] != 0)
                    {
                        A0 = S5 >> 10;
                        [80151920 + A0 * b9c] = b(0);

                        A1 = c9;
                        loopcb1ec:	; 800CB1EC
                            V1 = bu[80151920 + A0 * b9c];
                            [80151920 + A0 * b9c] = b(V1 + 1);
                            V0 = bu[w[1f800024] + V0];
                        800CB228	bne    v0, a1, loopcb1ec [$800cb1ec]
                    }
                }
                break;



                800CB238	sra    v1, s5, $10
                800CB23C	sll    v0, v1, $01
                800CB240	addu   v0, v0, v1
                800CB244	sll    s0, v0, $05
                800CB248	subu   s0, s0, v0
                800CB24C	sll    s0, s0, $03
                800CB250	subu   s0, s0, v1
                800CB254	sll    s0, s0, $02
                800CB258	lui    at, $8015
                800CB25C	addiu  at, at, $1a46
                800CB260	addu   at, at, s0
                800CB264	lh     a0, $0000(at)
                800CB268	jal    system_get_sin [$80039a74]
                800CB26C	sw     a0, $0000(s6)
                800CB270	sll    v1, v0, $07
                800CB274	addu   v1, v1, v0
                800CB278	sll    v1, v1, $02
                800CB27C	lui    at, $8015
                800CB280	addiu  at, at, $1a4c
                800CB284	addu   at, at, s0
                800CB288	lhu    v0, $0000(at)
                800CB28C	sra    v1, v1, $0c
                800CB290	subu   v0, v0, v1
                800CB294	lui    at, $8015
                800CB298	addiu  at, at, $1a4c
                800CB29C	addu   at, at, s0
                800CB2A0	sh     v0, $0000(at)
                800CB2A4	lw     a0, $0000(s6)
                800CB2A8	jal    system_get_cos [$80039b40]
                800CB2AC	nop
                800CB2B0	sll    v1, v0, $07
                800CB2B4	addu   v1, v1, v0
                800CB2B8	j      Lcb414 [$800cb414]
                800CB2BC	sll    v1, v1, $02
                800CB2C0	sra    v1, s5, $10
                800CB2C4	sll    v0, v1, $01
                800CB2C8	addu   v0, v0, v1
                800CB2CC	sll    s0, v0, $05
                800CB2D0	subu   s0, s0, v0
                800CB2D4	sll    s0, s0, $03
                800CB2D8	subu   s0, s0, v1
                800CB2DC	sll    s0, s0, $02
                800CB2E0	lui    at, $8015
                800CB2E4	addiu  at, at, $1a46
                800CB2E8	addu   at, at, s0
                800CB2EC	lh     a0, $0000(at)
                800CB2F0	nop
                800CB2F4	addiu  a0, a0, $0800
                800CB2F8	jal    system_get_sin [$80039a74]
                800CB2FC	sw     a0, $0000(s6)
                800CB300	sll    v1, v0, $07
                800CB304	addu   v1, v1, v0
                800CB308	sll    v1, v1, $02
                800CB30C	lui    at, $8015
                800CB310	addiu  at, at, $1a4c
                800CB314	addu   at, at, s0
                800CB318	lhu    v0, $0000(at)
                800CB31C	sra    v1, v1, $0c
                800CB320	subu   v0, v0, v1
                800CB324	lui    at, $8015
                800CB328	addiu  at, at, $1a4c
                800CB32C	addu   at, at, s0
                800CB330	sh     v0, $0000(at)
                800CB334	lw     a0, $0000(s6)
                800CB338	jal    system_get_cos [$80039b40]
                800CB33C	nop
                800CB340	sll    v1, v0, $07
                800CB344	addu   v1, v1, v0
                800CB348	j      Lcb414 [$800cb414]
                800CB34C	sll    v1, v1, $02
                800CB350	sra    v1, s5, $10
                800CB354	sll    v0, v1, $01
                800CB358	addu   v0, v0, v1
                800CB35C	sll    s0, v0, $05
                800CB360	subu   s0, s0, v0
                800CB364	sll    s0, s0, $03
                800CB368	subu   s0, s0, v1
                800CB36C	sll    s0, s0, $02
                800CB370	lui    at, $8015
                800CB374	addiu  at, at, $1a46
                800CB378	addu   at, at, s0
                800CB37C	lh     a0, $0000(at)
                800CB380	j      Lcb3c0 [$800cb3c0]
                800CB384	nop
                800CB388	sra    v1, s5, $10
                800CB38C	sll    v0, v1, $01
                800CB390	addu   v0, v0, v1
                800CB394	sll    s0, v0, $05
                800CB398	subu   s0, s0, v0
                800CB39C	sll    s0, s0, $03
                800CB3A0	subu   s0, s0, v1
                800CB3A4	sll    s0, s0, $02
                800CB3A8	lui    at, $8015
                800CB3AC	addiu  at, at, $1a46
                800CB3B0	addu   at, at, s0
                800CB3B4	lh     a0, $0000(at)
                800CB3B8	nop
                800CB3BC	addiu  a0, a0, $0800

                Lcb3c0:	; 800CB3C0
                800CB3C0	jal    system_get_sin [$80039a74]
                800CB3C4	sw     a0, $0000(s6)
                800CB3C8	sll    v1, v0, $07
                800CB3CC	addu   v1, v1, v0
                800CB3D0	sll    v1, v1, $01
                800CB3D4	lui    at, $8015
                800CB3D8	addiu  at, at, $1a4c
                800CB3DC	addu   at, at, s0
                800CB3E0	lhu    v0, $0000(at)
                800CB3E4	sra    v1, v1, $0c
                800CB3E8	subu   v0, v0, v1
                800CB3EC	lui    at, $8015
                800CB3F0	addiu  at, at, $1a4c
                800CB3F4	addu   at, at, s0
                800CB3F8	sh     v0, $0000(at)
                800CB3FC	lw     a0, $0000(s6)
                800CB400	jal    system_get_cos [$80039b40]
                800CB404	nop
                800CB408	sll    v1, v0, $07
                800CB40C	addu   v1, v1, v0
                800CB410	sll    v1, v1, $01

                Lcb414:	; 800CB414
                800CB414	lui    at, $8015
                800CB418	addiu  at, at, $1a50
                800CB41C	addu   at, at, s0
                800CB420	lhu    v0, $0000(at)
                800CB424	sra    v1, v1, $0c
                800CB428	subu   v0, v0, v1
                800CB42C	lui    at, $8015
                800CB430	addiu  at, at, $1a50
                800CB434	addu   at, at, s0
                800CB438	sh     v0, $0000(at)
                800CB43C	j      Lcd208 [$800cd208]
                800CB440	nop
                800CB444	sra    a0, s5, $10
                800CB448	sll    v0, a0, $01
                800CB44C	addu   v0, v0, a0
                800CB450	sll    v1, v0, $05
                800CB454	subu   v1, v1, v0
                800CB458	sll    v1, v1, $03
                800CB45C	subu   v1, v1, a0
                800CB460	sll    v1, v1, $02
                800CB464	lui    at, $8015
                800CB468	addiu  at, at, $1920
                800CB46C	addu   at, at, v1
                800CB470	lbu    a0, $0000(at)
                800CB474	nop
                800CB478	addiu  v0, a0, $0001
                800CB47C	lui    at, $8015
                800CB480	addiu  at, at, $1920
                800CB484	addu   at, at, v1
                800CB488	sb     v0, $0000(at)
                800CB48C	lw     v0, $0004(s3)
                800CB490	nop
                800CB494	addu   a0, a0, v0
                800CB498	lbu    v0, $0000(a0)
                800CB49C	nop
                800CB4A0	sw     v0, $0000(s6)
                800CB4A4	lui    at, $8015
                800CB4A8	addiu  at, at, $1920
                800CB4AC	addu   at, at, v1
                800CB4B0	lbu    a0, $0000(at)
                800CB4B4	nop
                800CB4B8	addiu  v0, a0, $0001
                800CB4BC	lui    at, $8015
                800CB4C0	addiu  at, at, $1920
                800CB4C4	addu   at, at, v1
                800CB4C8	sb     v0, $0000(at)
                800CB4CC	lw     v0, $0004(s3)
                800CB4D0	nop
                800CB4D4	addu   a0, a0, v0
                800CB4D8	lbu    v0, $0000(a0)
                800CB4DC	lui    a0, $800d
                800CB4E0	addiu  a0, a0, $0578
                800CB4E4	jal    funcbc04c [$800bc04c]
                800CB4E8	sw     v0, $0000(s7)
                800CB4EC	sh     v0, $000a(s3)
                800CB4F0	sll    v0, v0, $10
                800CB4F4	lhu    v1, $0000(s6)
                800CB4F8	sra    v0, v0, $0b
                800CB4FC	lui    at, $8016
                800CB500	addiu  at, at, $21f4
                800CB504	addu   at, at, v0
                800CB508	sh     v1, $0000(at)
                800CB50C	lhu    v0, $000a(s3)
                800CB510	lhu    v1, $0000(s7)
                800CB514	sll    v0, v0, $10
                800CB518	sra    v0, v0, $0b
                800CB51C	lui    at, $8016
                800CB520	addiu  at, at, $21f6
                800CB524	addu   at, at, v0
                800CB528	sh     v1, $0000(at)
                800CB52C	lhu    v0, $000a(s3)
                800CB530	nop
                800CB534	sll    v0, v0, $10
                800CB538	sra    v0, v0, $0b
                800CB53C	lui    at, $8016
                800CB540	addiu  at, at, $21f8
                800CB544	addu   at, at, v0
                800CB548	sh     fp, $0000(at)
                800CB54C	j      Lcd208 [$800cd208]
                800CB550	nop



                case d8: // 4a
                {
                    A0 = S5 >> 10;
                    A2 = bu[80151920 + A0 * b9c];
                    [80151920 + A0 * b9c] = b(A2 + 1);
                    V0 = w[1f800024];
                    [1f800000] = w(bu[A2 + V0]);

                    A1 = w[1f800024];
                    funccd558; // read two bytes
                    [1f800004] = w(V0);

                    A0 = 800d061c;
                    funcbc04c;
                    [1f80002a] = h(V0);

                    [801621f0 + V0 * 20 + 4] = h(hu[1f800000]);
                    [801621f0 + V0 * 20 + 6] = h(hu[1f800004]);
                }
                break;



                800CB614	lui    a0, $8010
                800CB618	lbu    a0, $a6d4(a0)
                800CB61C	lw     t2, $0038(sp)
                800CB620	nop
                800CB624	bne    t2, a0, Lcb660 [$800cb660]
                800CB628	sll    v1, a0, $01
                800CB62C	lui    v0, $8016
                800CB630	lh     v0, $2080(v0)
                800CB634	nop
                if (V0 == 0)
                {
                    [8015190a + T2 * b9c] = b(1);
                    return;
                }

                800CB640	lw     t2, $0040(sp)
                800CB644	nop
                800CB648	sll    v0, t2, $05
                800CB64C	subu   v0, v0, t2
                800CB650	lw     t2, $0038(sp)
                800CB654	sll    v0, v0, $03
                800CB658	j      Lcb6c0 [$800cb6c0]
                800CB65C	subu   v0, v0, t2

                Lcb660:	; 800CB660
                800CB660	addu   v1, v1, a0
                800CB664	sll    v0, v1, $05
                800CB668	subu   v0, v0, v1
                800CB66C	sll    v0, v0, $03
                800CB670	subu   v0, v0, a0
                800CB674	sll    v0, v0, $02
                800CB678	lui    at, $8015
                800CB67C	addiu  at, at, $190a
                800CB680	addu   at, at, v0
                800CB684	lbu    v1, $0000(at)
                800CB688	ori    v0, zero, $0001
                800CB68C	bne    v1, v0, Lcb6a8 [$800cb6a8]
                800CB690	sra    a0, s5, $10
                800CB694	lui    v0, $8016
                800CB698	lh     v0, $2080(v0)
                800CB69C	nop
                if (V0 == 0)
                {
                    T2 = w[SP + 38];
                    [8015190a + T2 * b9c] = b(1);

                    return;
                }

                Lcb6a8:	; 800CB6A8
                800CB6A8	sll    v1, a0, $01
                800CB6AC	addu   v1, v1, a0
                800CB6B0	sll    v0, v1, $05
                800CB6B4	subu   v0, v0, v1
                800CB6B8	sll    v0, v0, $03
                800CB6BC	subu   v0, v0, a0

                Lcb6c0:	; 800CB6C0
                800CB6C0	sll    v0, v0, $02
                800CB6C4	lui    t2, $8015
                800CB6C8	addiu  t2, t2, $18e4
                800CB6CC	lui    at, $8015
                800CB6D0	addiu  at, at, $1920
                800CB6D4	addu   at, at, v0
                800CB6D8	lbu    v1, $0000(at)
                800CB6DC	addu   v0, v0, t2
                800CB6E0	addiu  v1, v1, $ffff (=-$1)
                800CB6E8	sb     v1, $003c(v0)
                return;



                case ee: // 60
                {
                    unit_id = S5 >> 10;
                    [80151200 + unit_id * 74 + c] = h(hu[80151200 + unit_id * 74 + c] & fff3);

                    [801518e4 + unit_id * b9c + 26] = b(1);

                    idle_action_id = bu[801636b8 + unit_id * 10 + 1];

                    [80163784 + unit_id] = b(idle_action_id);
                    [801518e4 + unit_id * b9c + 2] = h(idle_action_id); // action id

                    [1f800024] = w(w[w[SP + 18] + idle_action_id * 4]);

                    funccdd44; // reset script

                    800CB7E8	j      Lcd208 [$800cd208]
                }
                break;



                800CB7F0	sra    a1, s5, $10
                800CB7F4	sll    a0, a1, $03
                800CB7F8	subu   a0, a0, a1
                800CB7FC	sll    a0, a0, $02
                800CB800	addu   a0, a0, a1
                800CB804	sll    a0, a0, $02
                800CB808	lui    at, $8015
                800CB80C	addiu  at, at, $120c
                800CB810	addu   at, at, a0
                800CB814	lhu    v0, $0000(at)
                800CB818	nop
                800CB81C	andi   v0, v0, $fffb
                800CB820	lui    at, $8015
                800CB824	addiu  at, at, $120c
                800CB828	addu   at, at, a0
                800CB82C	sh     v0, $0000(at)
                800CB830	sll    v0, a1, $01
                800CB834	addu   v0, v0, a1
                800CB838	sll    v1, v0, $05
                800CB83C	subu   v1, v1, v0
                800CB840	sll    v1, v1, $03
                800CB844	subu   v1, v1, a1
                800CB848	sll    v1, v1, $02
                800CB84C	ori    v0, zero, $0001
                800CB850	lui    at, $8015
                800CB854	addiu  at, at, $190a
                800CB858	addu   at, at, v1
                800CB85C	sb     v0, $0000(at)
                800CB860	lui    at, $8015
                800CB864	addiu  at, at, $120c
                800CB868	addu   at, at, a0
                800CB86C	lhu    v0, $0000(at)
                800CB870	lui    t2, $8015
                800CB874	addiu  t2, t2, $18e4
                800CB878	andi   v0, v0, $fff7
                800CB87C	lui    at, $8015
                800CB880	addiu  at, at, $120c
                800CB884	addu   at, at, a0
                800CB888	sh     v0, $0000(at)
                800CB88C	lui    at, $8015
                800CB890	addiu  at, at, $1920
                800CB894	addu   at, at, v1
                800CB898	lbu    v0, $0000(at)
                800CB89C	addu   v1, v1, t2
                800CB8A0	addiu  v0, v0, $ffff (=-$1)
                800CB8A8	sb     v0, $003c(v1)
                return;

                800CB8AC	lui    v1, $8010
                800CB8B0	lbu    v1, $99e8(v1)
                800CB8B4	nop
                800CB8B8	sll    v0, v1, $03
                800CB8BC	subu   v0, v0, v1
                800CB8C0	sll    v0, v0, $02
                800CB8C4	addu   v0, v0, v1
                800CB8C8	sll    v0, v0, $02
                800CB8CC	lui    at, $8015
                800CB8D0	addiu  at, at, $120c
                800CB8D4	addu   at, at, v0
                800CB8D8	lhu    v1, $0000(at)
                800CB8DC	sra    a0, s5, $10
                800CB8E0	ori    v1, v1, $0001
                800CB8E4	lui    at, $8015
                800CB8E8	addiu  at, at, $120c
                800CB8EC	addu   at, at, v0
                800CB8F0	sh     v1, $0000(at)
                800CB8F4	sll    v0, a0, $01
                800CB8F8	addu   v0, v0, a0
                800CB8FC	sll    v1, v0, $05
                800CB900	subu   v1, v1, v0
                800CB904	sll    v1, v1, $03
                800CB908	subu   v1, v1, a0
                800CB90C	sll    v1, v1, $02
                800CB910	lui    at, $8015
                800CB914	addiu  at, at, $1920
                800CB918	addu   at, at, v1
                800CB91C	lbu    a2, $0000(at)
                800CB920	nop
                800CB924	addiu  v0, a2, $0001
                800CB928	lui    at, $8015
                800CB92C	addiu  at, at, $1920
                800CB930	addu   at, at, v1

                Lcb934:	; 800CB934
                800CB934	sb     v0, $0000(at)
                800CB938	lui    a0, $8010
                800CB93C	lbu    a0, $99e8(a0)
                800CB940	lui    t2, $8015
                800CB944	addiu  t2, t2, $1a58
                800CB948	sll    v0, a0, $01
                800CB94C	addu   v0, v0, a0
                800CB950	sll    a1, v0, $05
                800CB954	subu   a1, a1, v0
                800CB958	sll    a1, a1, $03
                800CB95C	subu   a1, a1, a0
                800CB960	sll    a1, a1, $02
                800CB964	addiu  v0, t2, $ffcc (=-$34)
                800CB968	lw     a0, $0004(s3)
                800CB96C	addu   a1, a1, v0
                800CB970	addu   a2, a2, a0
                800CB974	lbu    v0, $0000(a2)
                800CB978	addu   v1, v1, t2
                800CB97C	sll    a0, v0, $01
                800CB980	addu   a0, a0, v0
                800CB984	sll    a0, a0, $02
                800CB988	addu   a0, a0, v0
                800CB98C	sll    a0, a0, $02
                800CB990	lui    at, $1f80
                800CB994	sw     v0, $0000(at)
                800CB998	jal    funcbb67c [$800bb67c]
                800CB99C	addu   a0, v1, a0
                800CB9A0	lui    a0, $8010
                800CB9A4	lbu    a0, $99e8(a0)
                800CB9A8	lui    t2, $8015
                800CB9AC	addiu  t2, t2, $18e4
                800CB9B0	sll    v0, a0, $01
                800CB9B4	addu   v0, v0, a0
                800CB9B8	sll    v1, v0, $05
                800CB9BC	subu   v1, v1, v0
                800CB9C0	sll    v1, v1, $03
                800CB9C4	subu   v1, v1, a0
                800CB9C8	sll    v1, v1, $02
                800CB9CC	addu   v0, t2, v1
                800CB9D0	sh     zero, $0162(v0)
                800CB9D4	sh     zero, $0160(v0)
                800CB9D8	sh     zero, $016c(v0)
                800CB9DC	sh     zero, $016a(v0)
                800CB9E0	lui    at, $8015
                800CB9E4	addiu  at, at, $1909
                800CB9E8	addu   at, at, v1
                800CB9EC	lbu    a0, $0000(at)
                800CB9F0	ori    v0, zero, $0800
                800CB9F4	lui    at, $8015
                800CB9F8	addiu  at, at, $1a4c
                800CB9FC	addu   at, at, v1
                800CBA00	sh     zero, $0000(at)
                800CBA04	lui    at, $8015
                800CBA08	addiu  at, at, $1a48
                800CBA0C	addu   at, at, v1
                800CBA10	sh     v0, $0000(at)
                800CBA14	ori    a0, a0, $0010
                800CBA18	lui    at, $8015
                800CBA1C	addiu  at, at, $1909
                800CBA20	addu   at, at, v1
                800CBA24	sb     a0, $0000(at)
                800CBA28	j      Lcd208 [$800cd208]
                800CBA2C	nop
                800CBA30	lui    v1, $8010
                800CBA34	lbu    v1, $99e8(v1)
                800CBA38	nop
                800CBA3C	sll    v0, v1, $03
                800CBA40	subu   v0, v0, v1
                800CBA44	sll    v0, v0, $02
                800CBA48	addu   v0, v0, v1
                800CBA4C	sll    v0, v0, $02
                800CBA50	lui    at, $8015
                800CBA54	addiu  at, at, $120c
                800CBA58	addu   at, at, v0
                800CBA5C	lhu    v1, $0000(at)
                800CBA60	sra    a0, s5, $10
                800CBA64	ori    v1, v1, $0001
                800CBA68	lui    at, $8015
                800CBA6C	addiu  at, at, $120c
                800CBA70	addu   at, at, v0
                800CBA74	sh     v1, $0000(at)
                800CBA78	sll    v0, a0, $01
                800CBA7C	addu   v0, v0, a0
                800CBA80	sll    v1, v0, $05
                800CBA84	subu   v1, v1, v0
                800CBA88	sll    v1, v1, $03
                800CBA8C	subu   v1, v1, a0
                800CBA90	sll    v1, v1, $02
                800CBA94	lui    at, $8015
                800CBA98	addiu  at, at, $1920
                800CBA9C	addu   at, at, v1
                800CBAA0	lbu    a2, $0000(at)
                800CBAA4	nop
                800CBAA8	addiu  v0, a2, $0001
                800CBAAC	lui    at, $8015
                800CBAB0	addiu  at, at, $1920
                800CBAB4	addu   at, at, v1
                800CBAB8	sb     v0, $0000(at)
                800CBABC	lui    a0, $8010
                800CBAC0	lbu    a0, $99e8(a0)
                800CBAC4	lui    t2, $8015
                800CBAC8	addiu  t2, t2, $1a58
                800CBACC	sll    v0, a0, $01
                800CBAD0	addu   v0, v0, a0
                800CBAD4	sll    a1, v0, $05
                800CBAD8	subu   a1, a1, v0
                800CBADC	sll    a1, a1, $03
                800CBAE0	subu   a1, a1, a0
                800CBAE4	sll    a1, a1, $02
                800CBAE8	addiu  v0, t2, $ffcc (=-$34)
                800CBAEC	lw     a0, $0004(s3)
                800CBAF0	addu   a1, a1, v0
                800CBAF4	addu   a2, a2, a0
                800CBAF8	lbu    v0, $0000(a2)
                800CBAFC	addu   v1, v1, t2
                800CBB00	sll    a0, v0, $01
                800CBB04	addu   a0, a0, v0
                800CBB08	sll    a0, a0, $02
                800CBB0C	addu   a0, a0, v0
                800CBB10	sll    a0, a0, $02
                800CBB14	lui    at, $1f80
                800CBB18	sw     v0, $0000(at)
                800CBB1C	jal    funcbb67c [$800bb67c]
                800CBB20	addu   a0, v1, a0
                800CBB24	lui    a0, $8010
                800CBB28	lbu    a0, $99e8(a0)
                800CBB2C	lui    t2, $8015
                800CBB30	addiu  t2, t2, $18e4
                800CBB34	sll    v0, a0, $01
                800CBB38	addu   v0, v0, a0
                800CBB3C	sll    v1, v0, $05
                800CBB40	subu   v1, v1, v0
                800CBB44	sll    v1, v1, $03
                800CBB48	subu   v1, v1, a0
                800CBB4C	sll    v1, v1, $02
                800CBB50	addu   v0, t2, v1
                800CBB54	sh     zero, $0164(v0)
                800CBB58	sh     zero, $0162(v0)
                800CBB5C	sh     zero, $0160(v0)
                800CBB60	sh     zero, $016c(v0)
                800CBB64	sh     zero, $016a(v0)
                800CBB68	lui    at, $8015
                800CBB6C	addiu  at, at, $1909
                800CBB70	addu   at, at, v1
                800CBB74	lbu    v0, $0000(at)
                800CBB78	lui    at, $8015
                800CBB7C	addiu  at, at, $1a4c
                800CBB80	addu   at, at, v1
                800CBB84	sh     zero, $0000(at)
                800CBB88	ori    v0, v0, $0010
                800CBB8C	lui    at, $8015
                800CBB90	addiu  at, at, $1909
                800CBB94	addu   at, at, v1
                800CBB98	sb     v0, $0000(at)
                800CBB9C	j      Lcd208 [$800cd208]
                800CBBA0	nop
                800CBBA4	lui    a2, $8010
                800CBBA8	lbu    a2, $99e8(a2)
                800CBBAC	lui    a0, $8010
                800CBBB0	addiu  a0, a0, $8158 (=-$7ea8)
                800CBBB4	sll    v1, a2, $03
                800CBBB8	subu   v1, v1, a2
                800CBBBC	sll    v1, v1, $02
                800CBBC0	addu   v1, v1, a2
                800CBBC4	sll    v1, v1, $02
                800CBBC8	sll    v0, a2, $01
                800CBBCC	addu   v0, v0, a2
                800CBBD0	sll    a1, v0, $05
                800CBBD4	subu   a1, a1, v0
                800CBBD8	sll    a1, a1, $03
                800CBBDC	subu   a1, a1, a2
                800CBBE0	sll    a1, a1, $02
                800CBBE4	lui    a2, $8015
                800CBBE8	addiu  a2, a2, $1a24
                800CBBEC	lui    at, $8015
                800CBBF0	addiu  at, at, $120c
                800CBBF4	addu   at, at, v1
                800CBBF8	lhu    v0, $0000(at)
                800CBBFC	nop
                800CBC00	andi   v0, v0, $fffe
                800CBC04	lui    at, $8015
                800CBC08	addiu  at, at, $120c
                800CBC0C	addu   at, at, v1
                800CBC10	sh     v0, $0000(at)
                800CBC14	jal    funcbb67c [$800bb67c]
                800CBC18	addu   a1, a1, a2
                800CBC1C	lui    v1, $8010
                800CBC20	lbu    v1, $99e8(v1)
                800CBC24	nop
                800CBC28	sll    a0, v1, $01
                800CBC2C	addu   a0, a0, v1
                800CBC30	sll    v0, a0, $05
                800CBC34	subu   v0, v0, a0
                800CBC38	sll    v0, v0, $03
                800CBC3C	subu   v0, v0, v1
                800CBC40	sll    a0, a0, $01
                800CBC44	lui    at, $8016
                800CBC48	addiu  at, at, $3c80
                800CBC4C	addu   at, at, a0
                800CBC50	lhu    v1, $0000(at)
                800CBC54	sll    v0, v0, $02
                800CBC58	lui    at, $8015
                800CBC5C	addiu  at, at, $1a4c
                800CBC60	addu   at, at, v0
                800CBC64	sh     v1, $0000(at)
                800CBC68	lui    at, $8016
                800CBC6C	addiu  at, at, $3c82
                800CBC70	addu   at, at, a0
                800CBC74	lhu    v1, $0000(at)
                800CBC78	nop
                800CBC7C	lui    at, $8015
                800CBC80	addiu  at, at, $1a4e
                800CBC84	addu   at, at, v0
                800CBC88	sh     v1, $0000(at)
                800CBC8C	lui    at, $8016
                800CBC90	addiu  at, at, $3c84
                800CBC94	addu   at, at, a0
                800CBC98	lhu    v1, $0000(at)
                800CBC9C	lui    t2, $8015
                800CBCA0	addiu  t2, t2, $18e4
                800CBCA4	lui    at, $8015
                800CBCA8	addiu  at, at, $1a50
                800CBCAC	addu   at, at, v0
                800CBCB0	sh     v1, $0000(at)
                800CBCB4	addu   v1, t2, v0
                800CBCB8	sh     zero, $0164(v1)
                800CBCBC	sh     zero, $0162(v1)
                800CBCC0	lui    at, $8015
                800CBCC4	addiu  at, at, $1909
                800CBCC8	addu   at, at, v0
                800CBCCC	lbu    v1, $0000(at)
                800CBCD0	lui    at, $8015
                800CBCD4	addiu  at, at, $1a44
                800CBCD8	addu   at, at, v0
                800CBCDC	sh     zero, $0000(at)
                800CBCE0	andi   v1, v1, $00ef
                800CBCE4	lui    at, $8015
                800CBCE8	addiu  at, at, $1909
                800CBCEC	addu   at, at, v0
                800CBCF0	sb     v1, $0000(at)
                800CBCF4	j      Lcd208 [$800cd208]
                800CBCF8	nop
                800CBCFC	sra    a0, s5, $10
                800CBD00	sll    v1, a0, $01
                800CBD04	addu   v1, v1, a0
                800CBD08	sll    v0, v1, $05
                800CBD0C	subu   v0, v0, v1
                800CBD10	sll    v0, v0, $03
                800CBD14	subu   v0, v0, a0
                800CBD18	sll    v0, v0, $02
                A0 = bu[80151920 + V0];
                800CBD30	addiu  v1, a0, $0001
                800CBD34	lui    at, $8015
                800CBD38	addiu  at, at, $1920
                800CBD3C	addu   at, at, v0
                800CBD40	sb     v1, $0000(at)
                V0 = w[S3 + 4];
                A0 = A0 + V0;
                V1 = bu[A0];
                800CBD58	sltiu  v0, v1, $0007
                800CBD5C	lui    at, $1f80
                800CBD60	sw     v1, $0000(at)
                800CBD64	beq    v0, zero, Lcd208 [$800cd208]
                800CBD68	sll    v0, v1, $02
                800CBD6C	lui    at, $800a
                800CBD70	addiu  at, at, $0ac8
                800CBD74	addu   at, at, v0
                800CBD78	lw     v0, $0000(at)
                800CBD7C	nop
                800CBD80	jr     v0 
                800CBD84	nop

                800CBD88	lui    a0, $8015
                800CBD8C	lh     a0, $1774(a0)
                800CBD90	lui    a1, $8016
                800CBD94	lbu    a1, $90cc(a1)
                800CBD98	jal    func1b00b0 [$801b00b0]
                800CBD9C	nop
                800CBDA0	j      Lcd208 [$800cd208]
                800CBDA4	nop
                800CBDA8	lui    a0, $8015
                800CBDAC	lh     a0, $1774(a0)
                800CBDB0	lui    a1, $8016
                800CBDB4	lbu    a1, $90cc(a1)
                800CBDB8	jal    func1b00d0 [$801b00d0]
                800CBDBC	nop
                800CBDC0	j      Lcd208 [$800cd208]
                800CBDC4	nop
                800CBDC8	lui    a0, $8015
                800CBDCC	lh     a0, $1774(a0)
                800CBDD0	lui    a1, $8016
                800CBDD4	lbu    a1, $90cc(a1)
                800CBDD8	jal    func1b00f0 [$801b00f0]
                800CBDDC	nop
                800CBDE0	j      Lcd208 [$800cd208]
                800CBDE4	nop
                800CBDE8	lui    a0, $8015
                800CBDEC	lh     a0, $1774(a0)
                800CBDF0	lui    a1, $8016
                800CBDF4	lbu    a1, $90cc(a1)
                800CBDF8	jal    func1b0110 [$801b0110]
                800CBDFC	nop
                800CBE00	j      Lcd208 [$800cd208]
                800CBE04	nop
                800CBE08	lui    a0, $8015
                800CBE0C	lh     a0, $1774(a0)
                800CBE10	lui    a1, $8016
                800CBE14	lbu    a1, $90cc(a1)
                800CBE18	jal    func1b0130 [$801b0130]
                800CBE1C	nop
                800CBE20	j      Lcd208 [$800cd208]
                800CBE24	nop
                800CBE28	lui    a0, $8015
                800CBE2C	lh     a0, $1774(a0)
                800CBE30	lui    a1, $8016
                800CBE34	lbu    a1, $90cc(a1)
                800CBE38	jal    func1b0150 [$801b0150]
                800CBE3C	nop
                800CBE40	j      Lcd208 [$800cd208]
                800CBE44	nop
                800CBE48	lui    a0, $8015
                800CBE4C	lh     a0, $1774(a0)
                800CBE50	lui    a1, $8016
                800CBE54	lbu    a1, $90cc(a1)
                800CBE58	jal    func1b0170 [$801b0170]
                800CBE5C	nop
                800CBE60	j      Lcd208 [$800cd208]
                800CBE64	nop
                800CBE68	sra    a0, s5, $10
                800CBE6C	sll    v0, a0, $01
                800CBE70	addu   v0, v0, a0
                800CBE74	sll    v1, v0, $05
                800CBE78	subu   v1, v1, v0
                800CBE7C	sll    v1, v1, $03
                800CBE80	subu   v1, v1, a0
                800CBE84	sll    v1, v1, $02
                800CBE88	lui    at, $8015
                800CBE8C	addiu  at, at, $1920
                800CBE90	addu   at, at, v1
                800CBE94	lbu    a0, $0000(at)
                800CBE98	nop
                800CBE9C	addiu  v0, a0, $0001
                800CBEA0	lui    at, $8015
                800CBEA4	addiu  at, at, $1920
                800CBEA8	addu   at, at, v1
                800CBEAC	sb     v0, $0000(at)
                800CBEB0	lw     v0, $0004(s3)
                800CBEB4	nop
                800CBEB8	addu   a0, a0, v0
                800CBEBC	lbu    a0, $0000(a0)
                800CBEC0	ori    v0, zero, $0002
                800CBEC4	lui    at, $8015
                800CBEC8	addiu  at, at, $1907
                800CBECC	addu   at, at, v1
                800CBED0	sb     v0, $0000(at)
                800CBED4	lui    at, $8015
                800CBED8	addiu  at, at, $1906
                800CBEDC	addu   at, at, v1
                800CBEE0	sb     a0, $0000(at)
                800CBEE4	j      Lcd208 [$800cd208]
                800CBEE8	nop
                800CBEEC	sra    s0, s5, $10
                800CBEF0	sll    v0, s0, $01
                800CBEF4	addu   v0, v0, s0
                800CBEF8	sll    v1, v0, $05
                800CBEFC	subu   v1, v1, v0
                800CBF00	sll    v1, v1, $03
                800CBF04	subu   v1, v1, s0
                800CBF08	sll    v1, v1, $02
                800CBF0C	lui    at, $8015
                800CBF10	addiu  at, at, $1920
                800CBF14	addu   at, at, v1
                800CBF18	lbu    a0, $0000(at)
                800CBF1C	nop
                800CBF20	addiu  v0, a0, $0001
                800CBF24	lui    at, $8015
                800CBF28	addiu  at, at, $1920
                800CBF2C	addu   at, at, v1
                800CBF30	sb     v0, $0000(at)
                800CBF34	lw     v0, $0004(s3)
                800CBF38	nop
                800CBF3C	addu   a0, a0, v0
                800CBF40	lbu    v0, $0000(a0)
                800CBF44	nop
                800CBF48	sh     v0, $000a(s3)
                800CBF4C	lui    at, $8015
                800CBF50	addiu  at, at, $1920
                800CBF54	addu   at, at, v1
                800CBF58	lbu    a0, $0000(at)
                800CBF5C	nop
                800CBF60	addiu  v0, a0, $0001
                800CBF64	lui    at, $8015
                800CBF68	addiu  at, at, $1920
                800CBF6C	addu   at, at, v1
                800CBF70	sb     v0, $0000(at)
                800CBF74	lw     v0, $0004(s3)
                800CBF78	nop
                800CBF7C	addu   a0, a0, v0
                [S3 + c] = h(bu[A0]);

                A0 = S0;
                system_get_party_player_structure_address_by_party_id;
                V0 = bu[V0 + 411];
                V0 = V0 & 0f;
                T0 = hu[800eea80 + V0 * 2];
                [S3 + e] = h(T0);

                A1 = S0;
                A0 = bu[800fa6d4];
                A2 = 800fa6e0 + A1 * 40;
                A3 = T0;
                [SP + 10] = w(hu[S3 + a]);
                [SP + 14] = w(hu[S3 + c]);
                funcd7a88;

                800CBFF8	j      Lcd208 [$800cd208]

                800CC000	sra    a0, s5, $10
                800CC004	sll    v0, a0, $01
                800CC008	addu   v0, v0, a0
                800CC00C	sll    s0, v0, $05
                800CC010	subu   s0, s0, v0
                800CC014	sll    s0, s0, $03
                800CC018	subu   s0, s0, a0
                800CC01C	sll    s0, s0, $02
                800CC020	lui    at, $8015
                800CC024	addiu  at, at, $1920
                800CC028	addu   at, at, s0
                800CC02C	lbu    v1, $0000(at)
                800CC030	nop
                800CC034	addiu  v0, v1, $0001
                800CC038	lui    at, $8015
                800CC03C	addiu  at, at, $1920
                800CC040	addu   at, at, s0
                800CC044	sb     v0, $0000(at)
                800CC048	lw     v0, $0004(s3)
                800CC04C	lw     a1, $0004(s3)
                800CC050	addu   v1, v1, v0
                800CC054	lbu    v0, $0000(v1)
                800CC058	jal    funccd558 [$800cd558]
                800CC05C	sh     v0, $000a(s3)
                800CC060	sll    v0, v0, $10
                800CC064	lui    at, $8015
                800CC068	addiu  at, at, $18ea
                800CC06C	addu   at, at, s0
                800CC070	lh     v1, $0000(at)
                800CC074	sra    v0, v0, $10
                800CC078	mult   v0, v1
                800CC07C	lui    v0, $8015
                800CC080	addiu  v0, v0, $18fe
                800CC084	lhu    v1, $000a(s3)
                800CC088	addu   s0, s0, v0
                800CC08C	sll    v1, v1, $10
                800CC090	sra    v1, v1, $0f
                800CC094	addu   v1, v1, s0
                800CC098	mflo   v0
                800CC09C	sra    v0, v0, $0c
                800CC0A0	j      Lcd208 [$800cd208]
                800CC0A4	sh     v0, $0000(v1)
                800CC0A8	sra    a1, s5, $10
                800CC0AC	sll    v0, a1, $01
                800CC0B0	addu   v0, v0, a1
                800CC0B4	sll    v1, v0, $05
                800CC0B8	subu   v1, v1, v0
                800CC0BC	sll    v1, v1, $03
                800CC0C0	subu   v1, v1, a1
                800CC0C4	sll    v1, v1, $02
                800CC0C8	lui    at, $8015
                800CC0CC	addiu  at, at, $1920
                800CC0D0	addu   at, at, v1
                800CC0D4	lbu    a0, $0000(at)
                800CC0D8	nop
                800CC0DC	addiu  v0, a0, $0001
                800CC0E0	lui    at, $8015
                800CC0E4	addiu  at, at, $1920
                800CC0E8	addu   at, at, v1
                800CC0EC	sb     v0, $0000(at)
                800CC0F0	lw     v0, $0004(s3)
                800CC0F4	nop
                800CC0F8	addu   a0, a0, v0
                800CC0FC	lbu    v0, $0000(a0)
                800CC100	nop
                800CC104	sh     v0, $000a(s3)
                800CC108	lui    at, $8015
                800CC10C	addiu  at, at, $1920
                800CC110	addu   at, at, v1
                800CC114	lbu    a3, $0000(at)
                800CC118	nop
                800CC11C	addiu  v0, a3, $0001
                800CC120	lui    at, $8015
                800CC124	addiu  at, at, $1920
                800CC128	addu   at, at, v1
                800CC12C	sb     v0, $0000(at)
                800CC130	lui    a0, $8010
                800CC134	lbu    a0, $a6d4(a0)
                800CC138	lw     v0, $0004(s3)
                800CC13C	lhu    a2, $000a(s3)
                800CC140	addu   a3, a3, v0
                800CC144	sll    a2, a2, $10
                800CC148	lbu    v0, $0000(a3)
                800CC14C	sra    a2, a2, $10
                800CC150	addu   a3, v0, zero
                800CC154	jal    funcd7b1c [$800d7b1c]
                800CC158	sh     v0, $000c(s3)
                800CC15C	j      Lcd208 [$800cd208]
                800CC160	nop
                800CC164	sra    a1, s5, $10
                800CC168	sll    v0, a1, $01
                800CC16C	addu   v0, v0, a1
                800CC170	sll    v1, v0, $05
                800CC174	subu   v1, v1, v0
                800CC178	sll    v1, v1, $03
                800CC17C	subu   v1, v1, a1
                800CC180	sll    v1, v1, $02
                800CC184	lui    at, $8015
                800CC188	addiu  at, at, $1920
                800CC18C	addu   at, at, v1
                800CC190	lbu    a0, $0000(at)
                800CC194	nop
                800CC198	addiu  v0, a0, $0001
                800CC19C	lui    at, $8015
                800CC1A0	addiu  at, at, $1920
                800CC1A4	addu   at, at, v1
                800CC1A8	sb     v0, $0000(at)
                800CC1AC	lw     v0, $0004(s3)
                800CC1B0	nop
                800CC1B4	addu   a0, a0, v0
                800CC1B8	lbu    v0, $0000(a0)
                800CC1BC	nop
                800CC1C0	sh     v0, $000a(s3)
                800CC1C4	lui    at, $8015
                800CC1C8	addiu  at, at, $1920
                800CC1CC	addu   at, at, v1
                800CC1D0	lbu    a3, $0000(at)
                800CC1D4	nop
                800CC1D8	addiu  v0, a3, $0001
                800CC1DC	lui    at, $8015
                800CC1E0	addiu  at, at, $1920
                800CC1E4	addu   at, at, v1
                800CC1E8	sb     v0, $0000(at)
                800CC1EC	lui    a0, $8010
                800CC1F0	lbu    a0, $a6d4(a0)
                800CC1F4	lw     v0, $0004(s3)
                800CC1F8	lhu    a2, $000a(s3)
                800CC1FC	addu   a3, a3, v0
                800CC200	sll    a2, a2, $10
                800CC204	lbu    v0, $0000(a3)
                800CC208	sra    a2, a2, $10
                800CC20C	addu   a3, v0, zero
                800CC210	jal    funcd7ba4 [$800d7ba4]
                800CC214	sh     v0, $000c(s3)
                800CC218	j      Lcd208 [$800cd208]
                800CC21C	nop



                case ad: // 1f
                {
                    unit_id = S5 >> 10;
                    V1 = bu[80151920 + unit_id * b9c];
                    [80151920 + unit_id * b9c] = b(V1 + 1);
                    V0 = w[S3 + 4];
                    [S3 + 10] = h(bu[V0 + V1]);

                    A0 = unit_id;
                    A1 = w[S3 + 4];
                    funccd558; // read two bytes
                    [S3 + e] = h(V0);

                    V1 = bu[80151920 + unit_id * b9c];
                    [80151820 + unit_id * b9c] = b(V1 + 1);
                    V0 = w[S3 + 4];
                    [S3 + a] = h(bu[V0 + V1]);

                    V1 = bu[80151920 + unit_id * b9c];
                    [80151820 + unit_id * b9c] = b(V1 + 1);
                    V0 = w[S3 + 4];
                    [S3 + c] = h(bu[V0 + V1]);

                    A0 = bu[800fa6d4];
                    A1 = unit_id;
                    V1 = bu[8015190f + unit_id * b9c + hu[S3 + 10]];
                    A2 = 80151a58 + unit_id * b9c + V1 * 34;
                    A3 = hu[S3 + e];
                    [SP + 10] = w(hu[S3 + a]);
                    [SP + 14] = w(hu[S3 + c]);
                    funcd7a88;
                }
                break;



                800CC36C	sra    s0, s5, $10
                800CC370	lw     a1, $0004(s3)
                800CC374	jal    funccd558 [$800cd558]
                800CC378	addu   a0, s0, zero
                800CC37C	sh     v0, $000e(s3)
                800CC380	sll    v0, s0, $01
                800CC384	addu   v0, v0, s0
                800CC388	sll    v1, v0, $05
                800CC38C	subu   v1, v1, v0
                800CC390	sll    v1, v1, $03
                800CC394	subu   v1, v1, s0
                800CC398	sll    v1, v1, $02
                800CC39C	lui    at, $8015
                800CC3A0	addiu  at, at, $1920
                800CC3A4	addu   at, at, v1
                800CC3A8	lbu    a0, $0000(at)
                800CC3AC	nop
                800CC3B0	addiu  v0, a0, $0001
                800CC3B4	lui    at, $8015
                800CC3B8	addiu  at, at, $1920
                800CC3BC	addu   at, at, v1
                800CC3C0	sb     v0, $0000(at)
                800CC3C4	lw     v0, $0004(s3)
                800CC3C8	nop
                800CC3CC	addu   a0, a0, v0
                800CC3D0	lbu    v0, $0000(a0)
                800CC3D4	addu   a1, s0, zero
                800CC3D8	sh     v0, $000a(s3)
                800CC3DC	lui    at, $8015
                800CC3E0	addiu  at, at, $1920
                800CC3E4	addu   at, at, v1
                800CC3E8	lbu    t0, $0000(at)
                800CC3EC	lui    a2, $8010
                800CC3F0	addiu  a2, a2, $a6e0 (=-$5920)
                800CC3F4	addiu  v0, t0, $0001
                800CC3F8	lui    at, $8015
                800CC3FC	addiu  at, at, $1920
                800CC400	addu   at, at, v1
                800CC404	sb     v0, $0000(at)
                800CC408	sll    v0, a1, $06
                800CC40C	addu   a2, v0, a2
                800CC410	lui    a0, $8010
                800CC414	lbu    a0, $a6d4(a0)
                800CC418	lw     v0, $0004(s3)
                800CC41C	lhu    a3, $000e(s3)
                800CC420	lhu    v1, $000a(s3)
                800CC424	addu   t0, t0, v0
                800CC428	sll    a3, a3, $10
                800CC42C	sra    a3, a3, $10
                800CC430	lbu    v0, $0000(t0)
                800CC434	sll    v1, v1, $10
                800CC438	sh     v0, $000c(s3)
                800CC43C	lhu    v0, $000c(s3)
                800CC440	sra    v1, v1, $10
                800CC444	sw     v1, $0010(sp)
                800CC448	sll    v0, v0, $10
                800CC44C	sra    v0, v0, $10
                800CC450	jal    funcd7a88 [$800d7a88]
                800CC454	sw     v0, $0014(sp)
                800CC458	j      Lcd208 [$800cd208]
                800CC45C	nop



                case f0: // (62)
                {
                    A0 = S5 >> 10;
                    funcd3e8c;
                }
                break;



                800CC470	sra    s0, s5, $10
                800CC474	lw     a1, $0004(s3)
                800CC478	jal    funccd558 [$800cd558]
                800CC47C	addu   a0, s0, zero
                800CC480	lw     a1, $0004(s3)
                800CC484	addu   a0, s0, zero
                800CC488	jal    funccd558 [$800cd558]
                800CC48C	sh     v0, $0016(s3)
                800CC490	lw     a1, $0004(s3)
                800CC494	addu   a0, s0, zero
                800CC498	jal    funccd558 [$800cd558]
                800CC49C	sh     v0, $0018(s3)
                800CC4A0	sll    v1, s0, $01
                800CC4A4	addu   v1, v1, s0
                800CC4A8	sh     v0, $001a(s3)
                800CC4AC	sll    v0, v1, $05
                800CC4B0	subu   v0, v0, v1
                800CC4B4	sll    v0, v0, $03
                800CC4B8	subu   v0, v0, s0
                800CC4BC	sll    v0, v0, $02
                800CC4C0	lui    at, $8015
                800CC4C4	addiu  at, at, $1920
                800CC4C8	addu   at, at, v0
                800CC4CC	lbu    a0, $0000(at)
                800CC4D0	nop
                800CC4D4	addiu  v1, a0, $0001
                800CC4D8	lui    at, $8015
                800CC4DC	addiu  at, at, $1920
                800CC4E0	addu   at, at, v0
                800CC4E4	sb     v1, $0000(at)
                800CC4E8	lw     v0, $0004(s3)
                800CC4EC	lw     a1, $0004(s3)
                800CC4F0	addu   a0, a0, v0
                800CC4F4	lbu    v0, $0000(a0)
                800CC4F8	addu   a0, s0, zero
                800CC4FC	jal    funccd558 [$800cd558]
                800CC500	sh     v0, $000a(s3)
                800CC504	lw     a1, $0004(s3)
                800CC508	addu   a0, s0, zero
                800CC50C	jal    funccd558 [$800cd558]
                800CC510	sh     v0, $000c(s3)
                800CC514	addu   a0, s0, zero
                800CC518	addiu  a1, s3, $0016
                800CC51C	sh     v0, $000e(s3)
                800CC520	sll    v0, v0, $10
                800CC524	lhu    a2, $000a(s3)
                800CC528	sra    v0, v0, $10
                800CC52C	sw     v0, $0010(sp)
                800CC530	lhu    a3, $000c(s3)
                800CC534	sll    a2, a2, $10
                800CC538	sra    a2, a2, $10
                800CC53C	sll    a3, a3, $10
                800CC540	jal    funcd415c [$800d415c]
                800CC544	sra    a3, a3, $10
                800CC548	j      Lcd208 [$800cd208]
                800CC54C	nop
                800CC550	lui    a0, $800d
                800CC554	addiu  a0, a0, $dde8 (=-$2218)
                800CC558	jal    funcbc04c [$800bc04c]
                800CC55C	nop
                800CC560	sll    v0, v0, $05
                800CC564	ori    v1, zero, $0002
                800CC568	lui    at, $8016
                800CC56C	addiu  at, at, $21f2
                800CC570	addu   at, at, v0
                800CC574	sh     v1, $0000(at)
                800CC578	ori    v1, zero, $01f0
                800CC57C	lui    at, $8016
                800CC580	addiu  at, at, $21f4
                800CC584	addu   at, at, v0
                800CC588	sh     v1, $0000(at)
                800CC58C	j      Lcd208 [$800cd208]
                800CC590	nop
                800CC594	lui    a0, $800d
                800CC598	addiu  a0, a0, $dde8 (=-$2218)
                800CC59C	jal    funcbc04c [$800bc04c]
                800CC5A0	nop
                800CC5A4	sll    v0, v0, $05
                800CC5A8	ori    v1, zero, $0003
                800CC5AC	lui    at, $8016
                800CC5B0	addiu  at, at, $21f2
                800CC5B4	addu   at, at, v0
                800CC5B8	sh     v1, $0000(at)
                800CC5BC	ori    v1, zero, $01e9
                800CC5C0	lui    at, $8016
                800CC5C4	addiu  at, at, $21f4
                800CC5C8	addu   at, at, v0
                800CC5CC	sh     v1, $0000(at)
                800CC5D0	j      Lcd208 [$800cd208]
                800CC5D4	nop
                800CC5D8	lui    a0, $800d
                800CC5DC	addiu  a0, a0, $dde8 (=-$2218)
                800CC5E0	jal    funcbc04c [$800bc04c]
                800CC5E4	nop
                800CC5E8	sll    v0, v0, $05
                800CC5EC	ori    v1, zero, $000d
                800CC5F0	lui    at, $8016
                800CC5F4	addiu  at, at, $21f2
                800CC5F8	addu   at, at, v0
                800CC5FC	sh     zero, $0000(at)
                800CC600	lui    at, $8016
                800CC604	addiu  at, at, $21f4
                800CC608	addu   at, at, v0
                800CC60C	sh     v1, $0000(at)
                800CC610	j      Lcd208 [$800cd208]
                800CC614	nop
                800CC618	lui    a0, $800d
                800CC61C	addiu  a0, a0, $dde8 (=-$2218)
                800CC620	jal    funcbc04c [$800bc04c]
                800CC624	nop
                800CC628	sll    v0, v0, $05
                800CC62C	ori    v1, zero, $0001
                800CC630	lui    at, $8016
                800CC634	addiu  at, at, $21f2
                800CC638	addu   at, at, v0
                800CC63C	sh     v1, $0000(at)
                800CC640	ori    v1, zero, $0024
                800CC644	lui    at, $8016
                800CC648	addiu  at, at, $21f4
                800CC64C	addu   at, at, v0
                800CC650	sh     v1, $0000(at)
                800CC654	j      Lcd208 [$800cd208]
                800CC658	nop
                800CC65C	sra    a1, s5, $10
                800CC660	sll    v1, a1, $01
                800CC664	addu   v1, v1, a1
                800CC668	sll    v0, v1, $05
                800CC66C	subu   v0, v0, v1
                800CC670	sll    v0, v0, $03
                800CC674	subu   v0, v0, a1
                800CC678	sll    v0, v0, $02
                800CC67C	lui    at, $8015
                800CC680	addiu  at, at, $1920
                800CC684	addu   at, at, v0
                800CC688	lbu    a0, $0000(at)
                800CC68C	nop
                800CC690	addiu  v1, a0, $0001
                800CC694	lui    at, $8015
                800CC698	addiu  at, at, $1920
                800CC69C	addu   at, at, v0
                800CC6A0	sb     v1, $0000(at)
                800CC6A4	lw     v0, $0004(s3)
                800CC6A8	nop
                800CC6AC	addu   a0, a0, v0
                800CC6B0	lbu    v0, $0000(a0)
                800CC6B4	nop
                800CC6B8	sb     v0, $0015(s3)
                800CC6BC	ori    v0, zero, $0007
                800CC6C0	beq    a1, v0, Lcc718 [$800cc718]
                800CC6C4	slti   v0, a1, $0008
                800CC6C8	beq    v0, zero, Lcc6e0 [$800cc6e0]
                800CC6CC	ori    v0, zero, $0006
                800CC6D0	beq    a1, v0, Lcc6fc [$800cc6fc]
                800CC6D4	nop
                800CC6D8	j      Lcc768 [$800cc768]
                800CC6DC	nop

                Lcc6e0:	; 800CC6E0
                800CC6E0	ori    v0, zero, $0008
                800CC6E4	beq    a1, v0, Lcc738 [$800cc738]
                800CC6E8	ori    v0, zero, $0009
                800CC6EC	beq    a1, v0, Lcc750 [$800cc750]
                800CC6F0	ori    v0, zero, $0001
                800CC6F4	j      Lcc768 [$800cc768]
                800CC6F8	nop

                Lcc6fc:	; 800CC6FC
                800CC6FC	lbu    v0, $0015(s3)
                800CC700	lui    at, $1f80
                800CC704	sw     zero, $0000(at)
                800CC708	lui    at, $1f80
                800CC70C	sw     v0, $0004(at)
                800CC710	j      Lcc768 [$800cc768]
                800CC714	nop

                Lcc718:	; 800CC718
                800CC718	lbu    v0, $0015(s3)
                800CC71C	lui    at, $1f80
                800CC720	sw     zero, $0000(at)
                800CC724	addiu  v0, v0, $0008
                800CC728	lui    at, $1f80
                800CC72C	sw     v0, $0004(at)
                800CC730	j      Lcc768 [$800cc768]
                800CC734	nop

                Lcc738:	; 800CC738
                800CC738	lbu    v1, $0015(s3)
                800CC73C	ori    v0, zero, $0001
                800CC740	lui    at, $1f80
                800CC744	sw     v0, $0000(at)
                800CC748	j      Lcc760 [$800cc760]
                800CC74C	nop

                Lcc750:	; 800CC750
                800CC750	lbu    v1, $0015(s3)
                800CC754	lui    at, $1f80
                800CC758	sw     v0, $0000(at)
                800CC75C	addiu  v1, v1, $0008

                Lcc760:	; 800CC760
                800CC760	lui    at, $1f80
                800CC764	sw     v1, $0004(at)

                Lcc768:	; 800CC768
                800CC768	lw     a1, $0004(s3)
                800CC76C	jal    funccd558 [$800cd558]
                800CC770	sra    a0, s5, $10
                800CC774	lui    a1, $8010
                800CC778	addiu  a1, a1, $8e74 (=-$718c)
                800CC77C	lui    v1, $1f80
                800CC780	lw     v1, $0000(v1)
                800CC784	lui    a0, $1f80
                800CC788	lw     a0, $0004(a0)
                800CC78C	sll    v1, v1, $05
                800CC790	addu   v1, v1, a1
                800CC794	sll    a0, a0, $01
                800CC798	addu   a0, a0, v1
                800CC79C	j      Lcd208 [$800cd208]
                800CC7A0	sh     v0, $0000(a0)
                800CC7A4	ori    v0, zero, $0001
                800CC7A8	lui    at, $8016
                800CC7AC	sb     v0, $2090(at)
                800CC7B0	j      Lcd208 [$800cd208]
                800CC7B4	nop
                800CC7B8	lui    at, $8016
                800CC7BC	sb     zero, $2090(at)
                800CC7C0	j      Lcd208 [$800cd208]
                800CC7C4	nop



                case c6: // 38
                {
                    unit_id = S5 >> 10;
                    A0 = bu[80151920 + unit_id * b9c];
                    [80151920 + unit_id * b9c] = b(A0 + 1);

                    [800f8374] = b(bu[w[1f800024] + A0]);
                }
                break;



                case e2: // 54
                {
                    A0 = S5 >> 10;
                    [801518e4 + A0 * b9c + 3e] = b(bu[801518e4 + A0 * b9c + 3e] | 2);
                }
                break;



                case e1: // 53
                {
                    A0 = S5 >> 10;
                    [801518e4 + A0 * b9c + 3e] = b(bu[801518e4 + A0 * b9c + 3e] | 4);
                }
                break;



                case e8: // 5a
                {
                    A0 = FP & ff;
                    funcd1110;
                }
                break;



                800CC8E4	sra    a1, s5, $10
                A0 = A1 * b9c;
                800CC904	lui    at, $8015
                800CC908	addiu  at, at, $1922
                800CC90C	addu   at, at, a0
                800CC910	lbu    v0, $0000(at)
                800CC914	sll    v1, a1, $04
                800CC918	ori    v0, v0, $0020
                800CC91C	lui    at, $8015
                800CC920	addiu  at, at, $1922
                800CC924	addu   at, at, a0
                800CC928	sb     v0, $0000(at)
                800CC92C	sll    v0, a1, $03
                800CC930	subu   v0, v0, a1
                800CC934	sll    v0, v0, $02
                800CC938	addu   v0, v0, a1
                800CC93C	lui    at, $8016
                800CC940	addiu  at, at, $36c0
                800CC944	addu   at, at, v1
                800CC948	lw     v1, $0000(at)
                800CC94C	sll    v0, v0, $02
                800CC950	lui    at, $8015
                800CC954	addiu  at, at, $1200
                800CC958	addu   at, at, v0
                800CC95C	sw     v1, $0000(at)
                800CC960	lui    at, $8015
                800CC964	addiu  at, at, $18fc
                800CC968	addu   at, at, a0
                800CC96C	lhu    v0, $0000(at)
                V1 = bu[80151920 + A0];
                800CC980	lui    at, $8015
                800CC984	addiu  at, at, $1a46
                800CC988	addu   at, at, a0
                800CC98C	sh     v0, $0000(at)
                800CC990	addiu  v0, v1, $0001
                800CC994	lui    at, $8015
                800CC998	addiu  at, at, $1920
                800CC99C	addu   at, at, a0
                800CC9A0	sb     v0, $0000(at)
                V0 = w[S3 + 4];
                V0 = bu[V0 + V1];

                800CC9B8	addu   v1, v0, zero
                800CC9BC	sh     v0, $000a(s3)

                if (V1 == a)
                {
                    A0 = A1;
                    system_get_party_player_structure_address_by_party_id;
                    V0 = bu[V0 + 411];
                    V0 = V0 & f0;
                    [1f80002c] = h(V0);

                    if (V0 == 10)
                    {
                        //5 - VINSENT2.LZS
                        V0 = 5;
                    }
                    else if (V0 == 20)
                    {
                        //6 - VINSENT3.LZS
                        V0 = 6;
                    }
                    else
                    {
                        //4 - VINSENT.LZS
                        V0 = 4;
                    }

                    [1f80002e] = h(V0);

                    A0 = w[800eea48 + V0 * 8 + 0];
                    A1 = w[800eea48 + V0 * 8 + 4];
                    A2 = 801b0000;
                    A3 = 0;
                    func33e74;
                }
                else
                {
                    //0 - GALL.LZS
                    //1 - DEATHGIG.LZS
                    //2 - HELLMASK.LZS
                    //3 - CHAOS.LZS
                    A0 = w[800eea48 + V1 * 8 + 0];
                    A1 = w[800eea48 + V1 * 8 + 4];
                    // we load something here
                    A2 = 801b0000;
                    A3 = 0;
                    func33e74;
                }

                800CCA6C	j      Lcd208 [$800cd208]


                800CCA74	sra    s0, s5, $10
                800CCA78	sll    v1, s0, $01
                800CCA7C	addu   v1, v1, s0
                800CCA80	sll    v0, v1, $05
                800CCA84	subu   v0, v0, v1
                800CCA88	sll    v0, v0, $03
                800CCA8C	subu   v0, v0, s0
                800CCA90	sll    v0, v0, $02
                800CCA94	lui    at, $8015
                800CCA98	addiu  at, at, $1920
                800CCA9C	addu   at, at, v0
                800CCAA0	lbu    a0, $0000(at)
                800CCAA4	sll    s1, s0, $02
                800CCAA8	addiu  v1, a0, $0001
                800CCAAC	lui    at, $8015
                800CCAB0	addiu  at, at, $1920
                800CCAB4	addu   at, at, v0
                800CCAB8	sb     v1, $0000(at)
                800CCABC	lw     v0, $0004(s3)
                800CCAC0	lui    v1, $8010
                800CCAC4	addiu  v1, v1, $3200
                800CCAC8	addu   a0, a0, v0
                800CCACC	lbu    v0, $0000(a0)
                800CCAD0	addu   a0, s0, zero
                800CCAD4	sh     v0, $000e(s3)
                800CCAD8	lui    v0, $8010
                800CCADC	addiu  v0, v0, $8384 (=-$7c7c)
                800CCAE0	addu   s1, s1, v0
                800CCAE4	sll    v0, s0, $04
                800CCAE8	subu   v0, v0, s0
                800CCAEC	sll    v0, v0, $0c
                800CCAF0	addu   v0, v0, v1
                800CCAF4	jal    funcb5e64 [$800b5e64]
                800CCAF8	sw     v0, $0000(s1)
                800CCAFC	jal    funcb5c1c [$800b5c1c]
                800CCB00	addu   a0, s0, zero
                800CCB04	lw     v1, $0000(s1)
                800CCB08	nop
                800CCB0C	lw     v0, $0008(v1)
                800CCB10	nop
                800CCB14	addu   v0, v0, v1
                800CCB18	sw     v0, $0008(v1)
                800CCB1C	lw     v0, $0000(s1)
                800CCB20	addu   s2, zero, zero
                800CCB24	lw     a0, $0008(v0)

                loopccb28:	; 800CCB28
                800CCB28	lw     v1, $0000(s1)
                800CCB2C	lw     v0, $0068(a0)
                800CCB30	lw     v1, $0008(v1)
                800CCB34	addiu  s2, s2, $0001
                800CCB38	addu   v0, v0, v1
                800CCB3C	sw     v0, $0068(a0)
                800CCB40	slti   v0, s2, $004a
                800CCB44	bne    v0, zero, loopccb28 [$800ccb28]
                800CCB48	addiu  a0, a0, $0004
                800CCB4C	jal    funcb4e30 [$800b4e30]
                800CCB50	andi   a0, fp, $00ff
                800CCB54	ori    a0, zero, $02d9
                800CCB58	sra    a1, s5, $10
                800CCB5C	sll    v0, a1, $01
                800CCB60	addu   v0, v0, a1
                800CCB64	sll    v1, v0, $05
                800CCB68	subu   v1, v1, v0
                800CCB6C	sll    v1, v1, $03
                800CCB70	subu   v1, v1, a1
                800CCB74	sll    v1, v1, $02
                800CCB78	lui    t2, $8015
                800CCB7C	addiu  t2, t2, $18e4
                800CCB80	lhu    a3, $000e(s3)
                800CCB84	addu   v0, v1, t2
                800CCB88	sh     a3, $0002(v0)
                800CCB8C	sll    v0, a1, $04
                800CCB90	lui    at, $8016
                800CCB94	addiu  at, at, $36b9
                800CCB98	addu   at, at, v0
                800CCB9C	sb     a3, $0000(at)
                800CCBA0	lui    at, $8016
                800CCBA4	addiu  at, at, $3784
                800CCBA8	addu   at, at, a1
                800CCBAC	sb     a3, $0000(at)
                800CCBB0	lui    at, $8015
                800CCBB4	addiu  at, at, $1922
                800CCBB8	addu   at, at, v1
                800CCBBC	lbu    v0, $0000(at)
                800CCBC0	lui    at, $8015
                800CCBC4	addiu  at, at, $1909
                800CCBC8	addu   at, at, v1
                800CCBCC	lbu    a3, $0000(at)
                800CCBD0	ori    v0, v0, $0005
                800CCBD4	andi   a3, a3, $00fd
                800CCBD8	lui    at, $8015
                800CCBDC	addiu  at, at, $1922
                800CCBE0	addu   at, at, v1
                800CCBE4	sb     v0, $0000(at)
                800CCBE8	lui    at, $8015
                800CCBEC	addiu  at, at, $1909
                800CCBF0	addu   at, at, v1
                800CCBF4	sb     a3, $0000(at)
                800CCBF8	jal    funcbba84 [$800bba84]
                800CCBFC	addu   a2, zero, zero
                return;

                800CCC08	sra    a0, s5, $10
                800CCC0C	sll    v1, a0, $01
                800CCC10	addu   v1, v1, a0
                800CCC14	sll    v0, v1, $05
                800CCC18	subu   v0, v0, v1
                800CCC1C	sll    v0, v0, $03
                800CCC20	subu   v0, v0, a0
                800CCC24	sll    v0, v0, $02
                800CCC28	lui    at, $8015
                800CCC2C	addiu  at, at, $1920
                800CCC30	addu   at, at, v0
                800CCC34	lbu    a0, $0000(at)
                800CCC38	nop
                800CCC3C	addiu  v1, a0, $0001
                800CCC40	lui    at, $8015
                800CCC44	addiu  at, at, $1920
                800CCC48	addu   at, at, v0
                800CCC4C	sb     v1, $0000(at)
                800CCC50	lw     v0, $0004(s3)
                800CCC54	nop
                800CCC58	addu   a0, a0, v0
                800CCC5C	lbu    v0, $0000(a0)
                800CCC60	lui    a0, $800d
                800CCC64	addiu  a0, a0, $06b8
                800CCC68	jal    funcbc04c [$800bc04c]
                800CCC6C	sh     v0, $000a(s3)
                800CCC70	sh     v0, $000c(s3)
                800CCC74	sll    v0, v0, $10
                800CCC78	sra    v0, v0, $0b
                800CCC7C	lui    at, $8016
                800CCC80	addiu  at, at, $21f6
                800CCC84	addu   at, at, v0
                800CCC88	sh     fp, $0000(at)
                800CCC8C	lhu    v0, $000c(s3)
                800CCC90	lhu    v1, $000a(s3)
                800CCC94	sll    v0, v0, $10
                800CCC98	sra    v0, v0, $0b
                800CCC9C	lui    at, $8016
                800CCCA0	addiu  at, at, $21f4
                800CCCA4	addu   at, at, v0
                800CCCA8	sh     v1, $0000(at)
                800CCCAC	j      Lcd208 [$800cd208]
                800CCCB0	nop

                case ec: // 5e
                {
                    A0 = S5 >> 10;
                    if (bu[801518dc] == 0)
                    {
                        A0 = FP & ff;
                        funcd0c80;
                    }
                    else
                    {
                        V1 = bu[80151920 + A0 * b9c];
                        [80151920 + A0 * b9c] = b(V1 - 1);

                        [1f800020] = b(0);
                    }
                }
                break;

                800CCD1C	sra    a0, s5, $10
                800CCD20	sll    v0, a0, $01
                800CCD24	addu   v0, v0, a0
                800CCD28	sll    v1, v0, $05
                800CCD2C	subu   v1, v1, v0
                800CCD30	sll    v1, v1, $03
                800CCD34	subu   v1, v1, a0
                800CCD38	sll    v1, v1, $02
                800CCD3C	lui    at, $8015
                800CCD40	addiu  at, at, $1920
                800CCD44	addu   at, at, v1
                800CCD48	lbu    a1, $0000(at)
                800CCD4C	nop
                800CCD50	addiu  v0, a1, $0001
                800CCD54	lui    at, $8015
                800CCD58	addiu  at, at, $1920
                800CCD5C	addu   at, at, v1
                800CCD60	sb     v0, $0000(at)
                800CCD64	lw     v0, $0004(s3)
                800CCD68	nop
                800CCD6C	addu   a1, a1, v0
                800CCD70	lbu    v0, $0000(a1)
                800CCD74	nop
                800CCD78	sw     v0, $0000(s6)
                800CCD7C	lui    at, $8015
                800CCD80	addiu  at, at, $1920
                800CCD84	addu   at, at, v1
                800CCD88	lbu    a2, $0000(at)
                800CCD8C	nop
                800CCD90	addiu  v0, a2, $0001
                800CCD94	lui    at, $8015
                800CCD98	addiu  at, at, $1920
                800CCD9C	addu   at, at, v1
                800CCDA0	sb     v0, $0000(at)
                800CCDA4	lw     v0, $0004(s3)
                800CCDA8	lbu    a1, $0000(s6)
                800CCDAC	addu   a2, a2, v0
                800CCDB0	lbu    v0, $0000(a2)
                800CCDB4	nop
                800CCDB8	sw     v0, $0000(s7)
                800CCDBC	lbu    a2, $0000(s7)
                800CCDC0	jal    funcce0c8 [$800ce0c8]
                800CCDC4	nop
                800CCDC8	j      Lcd208 [$800cd208]
                800CCDCC	nop
                800CCDD0	sra    a0, s5, $10
                800CCDD4	sll    v1, a0, $01
                800CCDD8	addu   v1, v1, a0
                800CCDDC	sll    v0, v1, $05
                800CCDE0	subu   v0, v0, v1
                800CCDE4	sll    v0, v0, $03
                800CCDE8	subu   v0, v0, a0
                800CCDEC	sll    v0, v0, $02
                800CCDF0	lui    at, $8015
                800CCDF4	addiu  at, at, $1920
                800CCDF8	addu   at, at, v0
                800CCDFC	lbu    a0, $0000(at)
                800CCE00	nop
                800CCE04	addiu  v1, a0, $0001
                800CCE08	lui    at, $8015
                800CCE0C	addiu  at, at, $1920
                800CCE10	addu   at, at, v0
                800CCE14	sb     v1, $0000(at)
                800CCE18	lw     v0, $0004(s3)
                800CCE1C	nop
                800CCE20	addu   a0, a0, v0
                800CCE24	lbu    v0, $0000(a0)
                800CCE28	lui    a0, $800d
                800CCE2C	addiu  a0, a0, $0760
                800CCE30	jal    funcbbeac [$800bbeac]
                800CCE34	sw     v0, $0000(s6)
                800CCE38	jal    funcc60f4 [$800c60f4]
                800CCE3C	sb     v0, $0014(s3)
                800CCE40	lbu    v1, $0014(s3)
                800CCE44	nop
                800CCE48	sll    v1, v1, $05
                800CCE4C	lui    at, $8016
                800CCE50	addiu  at, at, $297c
                800CCE54	addu   at, at, v1
                800CCE58	sh     v0, $0000(at)
                800CCE5C	lbu    v0, $0014(s3)
                800CCE60	lhu    v1, $0000(s6)
                800CCE64	sll    v0, v0, $05
                800CCE68	lui    at, $8016
                800CCE6C	addiu  at, at, $297e
                800CCE70	addu   at, at, v0
                800CCE74	sh     v1, $0000(at)
                800CCE78	j      Lcd208 [$800cd208]
                800CCE7C	nop

                case ea: // (5c)
                {
                    A0 = 800d0760;
                    funcbbeac;
                    [1f800034] = b(V0);
                    [80162978 + V0 * 20 + 4] = h(bu[8009d7bd] >> 2 + 4);
                    [80162978 + V0 * 20 + 6] = h(0);
                }
                break;

                800CCED8	lui    v0, $8015
                800CCEDC	lbu    v0, $18dc(v0)
                800CCEE0	nop
                800CCEE4	bne    v0, zero, Lccefc [$800ccefc]
                800CCEE8	sra    a0, s5, $10
                800CCEEC	jal    funcd0b4c [$800d0b4c]
                800CCEF0	andi   a0, fp, $00ff
                800CCEF4	j      Lcd208 [$800cd208]
                800CCEF8	nop

                Lccefc:	; 800CCEFC
                800CCEFC	sll    v1, a0, $01
                800CCF00	addu   v1, v1, a0
                800CCF04	sll    v0, v1, $05
                800CCF08	subu   v0, v0, v1
                800CCF0C	sll    v0, v0, $03
                800CCF10	subu   v0, v0, a0
                800CCF14	sll    v0, v0, $02
                800CCF18	lui    t2, $8015
                800CCF1C	addiu  t2, t2, $18e4
                800CCF20	lui    at, $8015
                800CCF24	addiu  at, at, $1920
                800CCF28	addu   at, at, v0
                800CCF2C	lbu    v1, $0000(at)
                800CCF30	addu   v0, v0, t2
                800CCF34	addiu  v1, v1, $ffff (=-$1)
                800CCF38	j      Lcd204 [$800cd204]
                800CCF3C	sb     v1, $003c(v0)



                case aa: // 1c
                {
                    [801590dc] = b(0);
                }
                break;



                800CCF50	sra    a1, s5, $10
                800CCF54	sll    v0, a1, $01
                800CCF58	addu   v0, v0, a1
                800CCF5C	sll    v1, v0, $05
                800CCF60	subu   v1, v1, v0
                800CCF64	sll    v1, v1, $03
                800CCF68	subu   v1, v1, a1
                800CCF6C	sll    v1, v1, $02
                800CCF70	lui    at, $8015
                800CCF74	addiu  at, at, $1920
                800CCF78	addu   at, at, v1
                800CCF7C	lbu    a0, $0000(at)
                800CCF80	nop
                800CCF84	addiu  v0, a0, $0001
                800CCF88	lui    at, $8015
                800CCF8C	addiu  at, at, $1920
                800CCF90	addu   at, at, v1
                800CCF94	sb     v0, $0000(at)
                800CCF98	lw     v0, $0004(s3)
                800CCF9C	nop
                800CCFA0	addu   a0, a0, v0
                800CCFA4	lbu    v0, $0000(a0)
                800CCFA8	lui    at, $8015
                800CCFAC	addiu  at, at, $1958
                800CCFB0	addu   at, at, v1
                800CCFB4	sw     zero, $0000(at)
                [801518f2 + V1] = h(V0);
                800CCFC8	sll    v0, a1, $06
                800CCFCC	lui    at, $8010
                800CCFD0	addiu  at, at, $a6d8 (=-$5928)
                800CCFD4	addu   at, at, v0
                800CCFD8	sw     zero, $0000(at)
                800CCFDC	sll    v0, a1, $03
                800CCFE0	subu   v0, v0, a1
                800CCFE4	sll    v0, v0, $02
                800CCFE8	addu   v0, v0, a1
                800CCFEC	sll    v0, v0, $02
                800CCFF0	lui    at, $8015
                800CCFF4	addiu  at, at, $1236
                800CCFF8	addu   at, at, v0
                800CCFFC	lbu    v0, $0000(at)
                800CD000	nop
                800CD004	beq    v0, zero, Lcd204 [$800cd204]
                800CD008	addu   s1, s5, zero
                800CD00C	beq    v0, zero, Lcd204 [$800cd204]
                800CD010	addu   s2, zero, zero
                800CD014	sra    s0, s1, $10

                loopcd018:	; 800CD018
                800CD018	lw     a1, $0020(sp)
                800CD01C	lw     a2, $0028(sp)
                800CD020	jal    funccd400 [$800cd400]
                800CD024	addu   a0, s0, zero
                800CD028	sll    v0, s0, $03
                800CD02C	subu   v0, v0, s0
                800CD030	sll    v0, v0, $02
                800CD034	addu   v0, v0, s0
                800CD038	sll    v0, v0, $02
                800CD03C	lui    at, $8015
                800CD040	addiu  at, at, $1236
                800CD044	addu   at, at, v0
                800CD048	lbu    v0, $0000(at)
                800CD04C	addiu  s2, s2, $0001
                800CD050	slt    v0, s2, v0
                800CD054	bne    v0, zero, loopcd018 [$800cd018]
                800CD058	sra    s0, s1, $10
                800CD05C	j      Lcd208 [$800cd208]
                800CD060	sb     zero, $0000(s3)



                case b6: // 28
                {
                    S1 = S5;

                    A0 = 800cd82c;
                    funcbc04c;

                    unit_id = S5 >> 10;
                    A0 = bu[80151920 + unit_id * b9c];
                    [80151920 + unit_id * b9c] = b(A0 + 1);
                    V0 = bu[w[1f800024] + A0]; // read byte from script

                    [801518e4 + unit_id * b9c + 74] = w(0); // read animation from start
                    [801518e4 + unit_id * b9c + e] = h(V0); // animation to play
                    [800fa6d8 + unit_id * 40] = w(0); // read animation from start

                    V0 = bu[80151236 + unit_id * 74];
                    if (V0 != 0)
                    {
                        S2 = 0;
                        loopcd13c:	; 800CD13C
                            S0 = S1 >> 10;
                            A0 = S0;
                            A1 = w[SP + 20];
                            A2 = w[SP + 28];
                            funccd400;

                            S2 = S2 + 1;
                            V0 = S2 < bu[80151236 + S0 * 74];
                        800CD178	bne    v0, zero, loopcd13c [$800cd13c]
                    }

                    [1f800020] = b(0);
                }
            }
            break;



            800CD188	sra    a0, s5, $10
            V0 = A0 * b9c;
            [80151958 + V0] = w(0); // animation from start
            [801518f2 + V0] = h(bu[1f800021]); // here we set all animations fo MP
            800CD1CC	sll    v0, a0, $03
            800CD1D0	subu   v0, v0, a0
            800CD1D4	sll    v0, v0, $02
            800CD1D8	addu   v0, v0, a0
            800CD1DC	sll    v0, v0, $02
            800CD1E0	sll    a0, a0, $06
            800CD1E4	lui    at, $8015
            800CD1E8	addiu  at, at, $1236
            800CD1EC	addu   at, at, v0
            800CD1F0	sb     zero, $0000(at)
            800CD1F4	lui    at, $8010
            800CD1F8	addiu  at, at, $a6d8 (=-$5928)
            800CD1FC	addu   at, at, a0
            800CD200	sw     zero, $0000(at)

            Lcd204:	; 800CD204
            [1f800020] = b(0);

            Lcd208:	; 800CD208
            V0 = bu[1f800020];
        800CD210	bne    v0, zero, Lc7f08 [$800c7f08]
    }
}

S0 = FP;
A0 = S0 * 74;
V0 = hu[8015120c + A0];
if (V0 & 0002)
{
    return;
}

[80151236 + A0] = b(bu[80151236 + A0] + 1);

if (h[801518e6 + S0 * b9c] == bu[80163784 + S0])
{
    V1 = bu[80151233 + A0];
    if (V1 == 1)
    {
        A0 = S0;
        A1 = w[SP + 20];
        A2 = w[SP + 28];
        funccd400;
    }
    else if (V1 == 2)
    {
        V0 = bu[801516f4];
        if ((V0 & 01) == 0)
        {
            return;
        }
    }
    else if (V1 == 3)
    {
        // we start animation from beginning
        [80151958 + S0 * b9c] = w(0);
        [800fa6d8 + S0 * 40] = w(0);
    }
}

A0 = S0;
A1 = w[SP + 20];
A2 = w[SP + 28];
funccd400;

return;
////////////////////////////////



////////////////////////////////
// funccdd44
// reset script
[801518e4 + A0 * b9c + 3b] = b(1);
[801518e4 + A0 * b9c + 3c] = b(0);
[801518e4 + A0 * b9c + 3d] = b(0);
////////////////////////////////



////////////////////////////////
// funcc60f4
V0 = bu[8009d7bd];
return V0 >> 2 + 4;
////////////////////////////////



////////////////////////////////
// funcbbeac

A2 = 0;
loopbbed0:	; 800BBED0
    if (w[80161ef0 + A2 * 4] == 0 && A2 >= h[8015169c])
    {
        [80161ef0 + A2 * 4] = w(A0);

        [80162978 + A2 * 20] = h(h[8015169c]);

        [80162080] = h(hu[80162080] + 1);
        return;
    }


    A2 = A2 + 1;
    V0 = A2 < 64;
800BBF40	bne    v0, zero, loopbbed0 [$800bbed0]

func3cebc;

A0 = 1;
func43938;

func3d1b4;

A0 = 61;
A1 = 1;
func429e0;
////////////////////////////////



////////////////////////////////
// funcd3e8c
// add dusty effect to feet
unit_id = A0;

A0 = 800d3d88;
funcbc04c;

[801621f0 + V0 * 20 + 00] = h(unit_id);
[801621f0 + V0 * 20 + 0e] = h(hu[801518e4 + unit_id * b9c + 6]);
[801621f0 + V0 * 20 + 10] = h(hu[801518e4 + unit_id * b9c + 6]);
////////////////////////////////



////////////////////////////////
// funcd58d0
S1 = A0;
S2 = A1;
S0 = A2;

A0 = 800d57c0;
funcbbeac;

[80162978 + V0 * 20 + 0] = h(0);
[80162978 + V0 * 20 + 4] = h(S2);
[80162978 + V0 * 20 + 6] = h(S0);
[80162978 + V0 * 20 + 8] = h(S1);
////////////////////////////////



////////////////////////////////
// funccd558
V0 = bu[80151920 + A0 * b9c];
S0 = bu[A1 + V0 + 0];
S1 = bu[A1 + V0 + 1];

[80151920 + A0 * b9c] = b(V0 + 2);

return (S1 << 8) + S0;
////////////////////////////////



////////////////////////////////
// funcd7a88
S2 = A0;
unit_id = A1;
bone_address = A2; // bone address to which we want to attach
distance = A3;

A0 = 800d7888;
funcbc04c;

[801621f0 + V0 * 20 + 04] = h(S2);
[801621f0 + V0 * 20 + 06] = h(unit_id);
[801621f0 + V0 * 20 + 08] = h(w[SP + 10]); // start
[801621f0 + V0 * 20 + 0a] = h(w[SP + 14]); // end
[801621f0 + V0 * 20 + 1a] = h(distance);
[801621f0 + V0 * 20 + 1c] = w(bone_address);
////////////////////////////////



////////////////////////////////
// funcbc04c
T0 = h[801590d4];

A2 = 0;
loopbc070:	; 800BC070
    V0 = w[80163b84 + A2 * 4];
    if (V0 == 0 && A2 >= T0)
    {
        [80163b84 + A2 * 4] = w(A0);
        [801621f0 + A2 * 20 + 0] = h(T0);
        [80163c78] = h(hu[80163c78] + 1);

        return A2;
    }

    A2 = A2 + 1;
    V0 = A2 < 3c;
800BC0E0	bne    v0, zero, loopbc070 [$800bc070]

func3cebc;

A0 = 1;
func43938;

func3d1b4;

A0 = 61;
A1 = 4;
func429e0;

return V0;
////////////////////////////////



////////////////////////////////
// funccd860
// A1 not used
// A2 first value from script
unit_id = A0;
position_address = w[SP + 14];

function = A3;
steps = hu[SP + 10];
attack_distance = A2;

if (bu[801031f0] == 0) // single attack
{
    target_id = bu[800f99e8];
    S0 = 0800 - hu[8015122c + target_id * 74];
    S1 = ((attack_distance * h[801518e4 + unit_id * b9c + 6];) >> c) + ((h[801518e4 + target_id * b9c + 12] * h[801518e4 + target_id * b9c + 6]) >> c);
}
else
{
    sum_rotation = 0;
    num = 0;
    sum_scale = 0;
    sum_collision_radius = 0;
    target_mask = h[80151774];

    T0 = 0;
    loopcd994:	; 800CD994
        if ((target_mask >> T0) & 1)
        {
            num = num + 1;
            sum_rotation = sum_rotation + h[801518e4 + T0 * b9c + 18];
            sum_collision_radius = sum_collision_radius + hu[801518e4 + T0 * b9c + 12]; // collision radius
            sum_scale = sum_scale + hu[801518e4 + T0 * b9c + 6]; // scale
        }

        T0 = T0 + 1;
        V0 = T0 < a;
    800CD9F0	bne    v0, zero, loopcd994 [$800cd994]

    rotation = sum_rotation / num;
    collision_radius = sum_collision_radius / num;
    scale = sum_scale / num;

    S0 = 0800 - rotation;
    S1 = ((attack_distance * h[801518e4 + unit_id * b9c + 6]) >> c) + ((collision_radius * scale) >> c);
}

A0 = S0;
system_get_sin;

A0 = S0;
S0 = hu[position_address + 0] - ((V0 * S1) >> c); // final X of unit

system_get_cos;
S1 = hu[position_address + 4] + ((V0 * S1) >> c); // final Z of unit



A0 = function;
funcbbf7c;
T2 = V0;

[801620ac + T2 * 20 + 8] = h(unit_id);
[801620ac + T2 * 20 + a] = h(bu[800f99e8]);

if (bu[800f99e8] == unit_id)
{
    [801620ac + T2 * 20 + c] = h(0);
    [801620ac + T2 * 20 + e] = h(0);
}
else
{
    [801620ac + T2 * 20 + c] = h((S0 - h[801518e4 + unit_id * b9c + 168]) / steps);
    [801620ac + T2 * 20 + e] = h((S1 - h[801518e4 + unit_id * b9c + 16c]) / steps);
}

[801620ac + T2 * 20 + 4] = h(steps);

[801620ac + T2 * 20 + 19] = b(bu[1f800008]);
[801620ac + T2 * 20 + 1a] = b(bu[1f80000c]);

[801620ac + T2 * 20 + 10] = w(w[1f800000]); // 2nd argument
[801620ac + T2 * 20 + 14] = w(w[1f800004]);
[801620ac + T2 * 20 + 18] = b(bu[80166f58]);
////////////////////////////////



////////////////////////////////
// funcbbf7c
A2 = 0;
T0 = 801590d0;
A3 = T0;

loopbbfa0:	; 800BBFA0
    V1 = A2;
    A1 = 80163b48 + V1 * 4;
    V0 = w[A1];
    if (V0 == 0 && V1 >= T0)
    {
        [A1 + 0] = w(A0);

        [801620ac + V1 * 20] = h(A3);
        [80163b7c] = h(hu[80163b7c] + 1);

        return;
    }

    800BBFB8	addiu  v0, a2, $0001
    800BC000	addu   a2, v0, zero
    800BC004	sll    v0, v0, $10
    800BC008	sra    v0, v0, $10

    800BC00C	slti   v0, v0, $000a
800BC010	bne    v0, zero, loopbbfa0 [$800bbfa0]

800BC018	jal    func3cebc [$8003cebc]
800BC01C	nop
800BC020	jal    func43938 [$80043938]
800BC024	ori    a0, zero, $0001
800BC028	jal    func3d1b4 [$8003d1b4]
800BC02C	nop
800BC030	ori    a0, zero, $0061
800BC034	jal    func429e0 [$800429e0]
800BC038	ori    a1, zero, $0002
////////////////////////////////



////////////////////////////////
// funccd798
unit_id = A0;
[801518e4 + unit_id * b9c + 168] = h(hu[80163c80 + unit_id * 6 + 0]);
[801518e4 + unit_id * b9c + 16a] = h(hu[80163c80 + unit_id * 6 + 2]);
[801518e4 + unit_id * b9c + 16c] = h(hu[80163c80 + unit_id * 6 + 4]);
////////////////////////////////



////////////////////////////////
// funcce21c
unit_id = A0; // unit_id
S2 = A1; // this is 1 in all cases

A0 = unit_id;
funcce058;

V1 = bu[801636b8 + unit_id * 10 + 4];
if (V1 < 13)
{
    switch (V1)
    {
        case 0: // simple disapear in red alpha (flesh)
        {
            A0 = 800c3578;
            funcbbeac;
            [80162978 + V0 * 20 + 8] = h(unit_id);
            [80162978 + V0 * 20 + 6] = h(S2 & ff);
        }
        break;

        case 1 a: // break down to polygons and disapear in red alpha (mechanical)
        {
            A0 = 800c3950;
            funcbbf7c;
            [801620ac + V0 * 20 + 6] = h(S2 & 00ff);
            [801620ac + V0 * 20 + 8] = h(unit_id);
            [801620ac + V0 * 20 + a] = h(f8);
        }
        break;

        case 2: // pressed to floor and disapear in red alpha
        {
            A0 = 800c3ca8;
            funcbbeac;
            [80162978 + V0 * 20 + 8] = h(unit_id);
            [80162978 + V0 * 20 + 6] = h(S2 & ff);
        }
        break;

        case 3: // screwed and disapear in red alpha
        {
            A0 = 800c328c;
            funcbbeac;
            [80162978 + V0 * 20 + 8] = h(unit_id);
            [80162978 + V0 * 20 + 6] = h(S2 & ff);
        }
        break;

        case 7: // like a list of paper and disapear to alpha
        {
            A0 = 800c44b4;
            funcbbeac;
            [80162978 + V0 * 20 + 8] = h(unit_id);
            [80162978 + V0 * 20 + 6] = h(S2 & ff);
        }
        break;

        case 8: // fly up and disapear to alpha
        {
            A0 = 800c4814;
            funcbbeac;
            [80162978 + V0 * 20 + 8] = h(unit_id);
            [80162978 + V0 * 20 + 6] = h(S2 & ff);
        }
        break;

        case 11 12: // slow disapear with flashes like bosses
        {
            A0 = 800c40f4;
            funcbbeac;
            [80162978 + V0 * 20 + 8] = h(unit_id);
            [80162978 + V0 * 20 + 6] = h(S2 & ff);
        }
        break;
    }
}
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// funcd1110
A1 = A0;
unit_id = A1 & ff;
effect_id = bu[801518e4 + unit_id * b9c + 22];
V0 = bu[801518e4 + unit_id * b9c + 23];

switch (V0)
{
    case 2: // magic
    {
        V0 = bu[801031f0];
        if (V0 == 0) // if single attack
        {
            V0 = h[800ef63c + effect_id * 2];
        }
        else
        {
            switch (effect_id)
            {
                case 1d: // fire3
                {
                    A0 = w[800eee20 + 0];
                    A1 = w[800eee20 + 4];
                    funcd088c;
                    return;
                }
                break;

                case 29: // bio3
                {
                    A0 = w[800eecb8 + 0];
                    A1 = w[800eecb8 + 4];
                    funcd088c;
                    return;
                }
                break;

                case 2c: // demi3
                {
                    A0 = w[800eec88 + 0];
                    A1 = w[800eec88 + 4];
                    funcd088c;
                    return;
                }
                break;

                case 20: // ice3
                {
                    A0 = w[800ef3b0 + 0];
                    A1 = w[800ef3b0 + 4];
                    funcd088c;
                    return;
                }
                break;

                case 23: // bolt3
                {
                    A0 = w[800eebe8 + 0];
                    A1 = w[800eebe8 + 4];
                    funcd088c;
                    return;
                }
                break;
            }

            V0 = h[800ef63c + effect_id * 2];
        }
    }
    break;

    // summon
    case  3: V0 = h[800ef6d8 + effect_id * 2]; break;

    // item
    case  4: V0 = h[800ef5b0 + effect_id * 2]; break;

    // coin
    case  7: V0 = dd;                          break;

    // throw
    case  8: V0 = h[800ef8d8 + effect_id * 2]; break;

    // enemy skill
    case  d: V0 = h[800ef6a8 + effect_id * 2]; break;

    // limit
    case 14: V0 = h[800ef838 + effect_id * 2]; break;

    // enemy attack
    case 20: V0 = h[800ef6fc + effect_id * 2]; break;
}

A0 = w[800eebb8 + V0 * 8 + 0];
A1 = w[800eebb8 + V0 * 8 + 4];
funcd088c;
return;
////////////////////////////////



////////////////////////////////
// funcd088c
A2 = 801b0000;
A3 = 0;
func33e34;

funcb7fb4;
////////////////////////////////



////////////////////////////////
// funcd0c80
[800f8cf0] = b(0);
unit_id = S1 = A0;

funcd1530;

A0 = S1;

V0 = bu[801518e4 + unit_id * b9c + 23];
switch (V0)
{
    case 2: // magic
    {
        V0 = bu[801031f0];
        if (V0 == 0)
        {
            V1 = bu[801518e4 + unit_id * b9c + 22];
            if (V1 == 19)
            {
                [801518e4 + 0 * b9c + 26] = b(1);
                [801518e4 + 1 * b9c + 26] = b(1);
                [801518e4 + 2 * b9c + 26] = b(1);
            }

            A0 = h[80151774];
            V0 = bu[801518e4 + unit_id * b9c + 22];
        }
        else
        {
            V0 = bu[801518e4 + unit_id * b9c + 22];

            A0 = h[80151774];
            A1 = bu[801590cc];

            switch (V0)
            {
                case 1d: // fire3
                {
                    func1b0084;
                    return;
                }

                case 20: // ice3
                {
                    func1b0054;
                    return;
                }

                case 23: // bolt3
                {
                    func1b000c;
                    return;
                }

                case 29 2c: // bio3 demi3
                {
                    func1b0000;
                    return;
                }
            }

            V0 = bu[801518e4 + unit_id * b9c + 22];
        }

        A1 = bu[801590cc]; // attacker_id

        800D0EC0	sll    v0, v0, $02
        800D0EC4	lui    at, $800f
        800D0EC8	addiu  at, at, $faf0 (=-$510)
        800D0ECC	addu   at, at, v0
        800D0ED0	lw     v0, $0000(at)

D4081B80B8091B808C0A1B80440C1B80600B1B8000001B8064051B80B86C0C80B86C0C8054001B8054001B8054001B80B86C0C8054001B80D0071B8000001B80
00001B80 10
00001B80 11
00001B80 12
54001B80 13
00001B80 14
54001B80 15
4C0D1B80 16
54001B80 17
B86C0C80 18
00001B80 19
00001B80 1a
84001B80 1d
7C031B80 1e
14071B80 1f
54001B8000001B8000001B800C001B8054001B8074001B8054001B8040061B8000001B8000001B8030071B80100C1B8064141B8000001B8000001B8000001B80
54081B8000001B8054001B8000001B8054001B8054001B8054001B8070001B8054001B80C0041B8054001B80B86C0C8054001B8054001B8000001B8088001B80
70001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B80B86C0C8054001B80B86C0C80B86C0C8054001B806C001B8030001B8010001B80
00001B8034061B80F4061B8010001B8000001B80D0081B80140F1B80C4081B8000001B8000001B80DC0C1B8000001B8048091B8000001B8098061B80B4081B80
00001B8000001B8000001B80380B1B8000001B8028101B8000001B8000001B8000001B8000001B8038031B8000001B80EC021B80C40F1B8000001B8000001B80
10001B8000001B8020001B8000001B8000001B8000001B8078191B80EC021B8000001B8000001B8000001B80EC021B8054001B8054001B8054001B8054001B80B86C0C8054001B8054001B8054001B8054001B8054001B80D4091B8030001B8000001B8020001B8000001B8000001B80180F1B8000001B8064031B8028101B8000001B8000001B8000001B8000001B8000001B80B4011B8000001B8020001B8000001B80940C1B8000001B8054001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B807C001B80

        800D0ED8	jalr   v0 ra
    }
    break;



    case d: // enemy skill
    {
        effect_id = bu[801518e4 + unit_id * b9c + 22];

        A0 = h[80151774];
        A1 = bu[801590cc];
        V0 = effect_id * 4;

    800D0F2C	lui    at, $800f
    800D0F30	addiu  at, at, $fbc8 (=-$438)
    800D0F34	addu   at, at, v0
    800D0F38	lw     v0, $0000(at)

54001B80
70001B80
54001B80
C0041B80
54001B80
B86C0C80
54001B80
54001B80
00001B8088001B8070001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B80B86C0C8054001B80B86C0C80B86C0C8054001B806C001B8030001B8010001B8000001B8034061B80F4061B8010001B8000001B80D0081B80140F1B80C4081B8000001B8000001B80DC0C1B8000001B8048091B8000001B8098061B80B4081B8000001B8000001B8000001B80380B1B8000001B8028101B8000001B8000001B8000001B8000001B8038031B8000001B80EC021B80C40F1B8000001B8000001B8010001B8000001B8020001B8000001B8000001B8000001B8078191B80EC021B8000001B8000001B8000001B80EC021B8054001B8054001B8054001B8054001B80B86C0C8054001B8054001B8054001B8054001B8054001B80D4091B8030001B8000001B8020001B8000001B8000001B80180F1B8000001B8064031B8028101B8000001B8000001B8000001B8000001B8000001B80B4011B8000001B8020001B8000001B80940C1B8000001B8054001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B807C001B8054001B8008001B8000001B8000001B8000001B8000001B8000001B8054001B80CC0F1B8000001B8048001B8064011B8000001B8000001B8000001B8000001B8054001B8000001B8000001B8000001B8000001B8000001B8010001B8000001B8000001B8000001B8000001B8000001B8000001B80980E1B8054001B8000001B8000001B8000001B8054001B8054001B806C091B80940F1B8000001B8000001B8008001B8048001B8010001B8048001B8010001B809C001B8000001B8054001B8074001B8054001B8000001B8000001B8000001B80F0001B8000001B8000001B8040001B8040001B80B86C0C8000001B8000001B804C0A0D808C0A1B8040001B8040001B8060001B8054001B8054001B8054001B8000001B807C001B8000001B8000001B809C061B8010001B8000001B8054001B8060001B8008001B8000001B8000001B8000001B8000001B8000001B8000001B8058001B8000001B8000001B8000001B8020001B8000001B8000001B8048001B8088001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8054001B8054001B807C001B8054001B8054001B8054001B8000001B8054001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B807C001B80B86C0C80

    800D0F40	jalr   v0 ra
    800D0F44	nop
    800D0F48	j      Ld10f8 [$800d10f8]
    800D0F4C	nop

    case 14: // limit
    800D0F50	andi   a0, s1, $00ff
    800D0F54	sll    v1, a0, $01
    800D0F58	addu   v1, v1, a0
    800D0F5C	sll    v0, v1, $05
    800D0F60	subu   v0, v0, v1
    800D0F64	sll    v0, v0, $03
    800D0F68	subu   v0, v0, a0
    800D0F6C	sll    v0, v0, $02
    800D0F70	lui    at, $8015
    800D0F74	addiu  at, at, $1906
    800D0F78	addu   at, at, v0
    800D0F7C	lbu    v1, $0000(at)
    800D0F80	ori    v0, zero, $0002
    800D0F84	bne    v1, v0, Ld0fc4 [$800d0fc4]
    800D0F88	andi   v1, s1, $00ff
    800D0F8C	lui    v1, $8016
    800D0F90	lbu    v1, $90cc(v1)
    800D0F94	lui    v0, $8010
    800D0F98	lb     v0, $a9e8(v0)
    800D0F9C	nop
    800D0FA0	bne    v1, v0, Ld0fb8 [$800d0fb8]
    800D0FA4	ori    v0, zero, $0001
    800D0FA8	lui    at, $8016
    800D0FAC	sb     zero, $3a98(at)
    800D0FB0	j      Ld0fc4 [$800d0fc4]
    800D0FB4	andi   v1, s1, $00ff

    Ld0fb8:	; 800D0FB8
    800D0FB8	lui    at, $8016
    800D0FBC	sb     v0, $3a98(at)
    800D0FC0	andi   v1, s1, $00ff

    Ld0fc4:	; 800D0FC4
    800D0FC4	sll    v0, v1, $01
    800D0FC8	addu   v0, v0, v1
    800D0FCC	sll    s0, v0, $05
    800D0FD0	subu   s0, s0, v0
    800D0FD4	sll    s0, s0, $03
    800D0FD8	subu   s0, s0, v1
    800D0FDC	sll    s0, s0, $02
    800D0FE0	lui    a0, $8015
    800D0FE4	lh     a0, $1774(a0)
    800D0FE8	lui    at, $8015
    800D0FEC	addiu  at, at, $1906
    800D0FF0	addu   at, at, s0
    800D0FF4	lbu    v0, $0000(at)
    800D0FF8	lui    a1, $8016
    800D0FFC	lbu    a1, $90cc(a1)
    800D1000	sll    v0, v0, $02
    800D1004	lui    at, $800f
    800D1008	addiu  at, at, $fea0 (=-$160)
    800D100C	addu   at, at, v0
    800D1010	lw     v0, $0000(at)
    800D1014	nop
    800D1018	jalr   v0 ra
    800D101C	nop
    800D1020	lui    at, $1f80
    800D1024	sw     v0, $0000(at)
    800D1028	lui    at, $8015
    800D102C	addiu  at, at, $1906
    800D1030	addu   at, at, s0
    800D1034	lbu    v0, $0000(at)
    800D1038	nop
    800D103C	addiu  v1, v0, $ffd3 (=-$2d)
    800D1040	sltiu  v0, v1, $0023
    800D1044	beq    v0, zero, Ld1070 [$800d1070]
    800D1048	sll    v0, v1, $02
    800D104C	lui    at, $800a
    800D1050	addiu  at, at, $0c48
    800D1054	addu   at, at, v0
    800D1058	lw     v0, $0000(at)
    800D105C	nop
    800D1060	jr     v0 
    800D1064	nop

    800D1068	lui    at, $1f80
    800D106C	sw     zero, $0000(at)

    Ld1070:	; 800D1070
    800D1070	lui    a1, $1f80
    800D1074	lw     a1, $0000(a1)
    800D1078	jal    funcd08b8 [$800d08b8]
    800D107C	andi   a0, s1, $00ff
    800D1080	j      Ld10f8 [$800d10f8]
    800D1084	nop

    case 20: // enemy attack
    {
        V0 = bu[801518e4 + unit_id * b9c + 22];
        V0 = w[800efc28 + V0 * 4];

        A0 = h[80151774];
        A1 = bu[801590cc];

30001B80 0
10001B80 1
00001B80 2
34061B80 3
10001B80 5
00001B80
D0081B80
140F1B80C4081B8000001B8000001B80DC0C1B8000001B8048091B8000001B80
98061B80B4081B8000001B8000001B8000001B80380B1B8000001B8028101B8000001B8000001B8000001B8000001B8038031B8000001B80EC021B80C40F1B80
00001B8000001B8010001B8000001B8020001B8000001B8000001B8000001B8078191B80EC021B8000001B8000001B8000001B80EC021B8054001B8054001B80
54001B8054001B80B86C0C8054001B8054001B8054001B8054001B8054001B80D4091B8030001B8000001B8020001B8000001B8000001B80180F1B8000001B80
64031B8028101B8000001B8000001B8000001B8000001B8000001B80B4011B8000001B8020001B8000001B80940C1B8000001B8054001B8000001B8000001B80
00001B8000001B8000001B8000001B8000001B807C001B8054001B8008001B8000001B8000001B8000001B8000001B8000001B8054001B80CC0F1B8000001B80
48001B8064011B8000001B8000001B8000001B8000001B8054001B8000001B8000001B8000001B8000001B8000001B8010001B8000001B8000001B8000001B80
00001B8000001B8000001B80980E1B8054001B8000001B8000001B8000001B8054001B8054001B806C091B80940F1B8000001B8000001B8008001B8048001B80
10001B8048001B8010001B809C001B8000001B8054001B8074001B8054001B8000001B8000001B8000001B80F0001B8000001B8000001B8040001B8040001B80
B86C0C8000001B8000001B804C0A0D808C0A1B8040001B8040001B8060001B8054001B8054001B8054001B8000001B807C001B8000001B8000001B809C061B80
10001B8000001B8054001B8060001B8008001B8000001B8000001B8000001B8000001B8000001B8000001B8058001B8000001B8000001B8000001B8020001B80
00001B8000001B8048001B8088001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B80
00001B8054001B8054001B807C001B8054001B8054001B8054001B8000001B8054001B8000001B8000001B8000001B8000001B8000001B8000001B8000001B80
00001B8000001B8000001B8000001B8000001B8000001B807C001B80B86C0C80B86C0C8054001B8054001B80B86C0C8054001B8054001B8054001B8054001B80
54001B8054001B8054001B80E0001B8020001B8000001B8074001B8054001B8094001B80B4001B8000001B8088001B8004011B8038001B8054001B8054001B808C001B80C4001B80FC001B8034011B806C011B80A4011B80DC011B8014021B804C021B8084021B80BC021B80F4021B802C031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8064031B8054001B808C001B8054001B80C8001B8000011B803C011B8074011B80B0011B80EC011B8028021B8060021B809C021B80D4021B8010031B8048031B8084031B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B8054001B80C0001B802C011B8098011B8004021B8070021B80DC021B8048031B80B4031B8020041B808C041B8054001B808C001B80C4001B80FC001B8038011B8070011B80AC011B80

        800D10E0	jalr   v0 ra
    }
    break;



    case 3: // summon
    800D10F0	jal    funcc64ac [$800c64ac]
    800D10F4	nop
}
Ld10f8:	; 800D10F8
////////////////////////////////