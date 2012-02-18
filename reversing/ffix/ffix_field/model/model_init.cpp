////////////////////////////////
// funcaba98
A0 = A0;
S5 = A1; // 0x10 0x11 0x12
S6 = A2; // 0x19
S7 = A3; // 0x4 0xd
FP = A4; // 0x0392 0x039b 0x0001

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V1 = w[V0 + c];
V0 = A0 * 4;
V1 = w[V1 + 14];

800ABAF0	addu   v0, v0, a0
800ABAF4	lw     v1, $0054(v1)
800ABAF8	sll    v0, v0, $02
800ABB00	addu   s0, v1, v0

func1e350;
S3 = V0;



switch( S5 )
{
    case 0:

    800ABB30	andi   v1, s6, $00ff
    800ABB34	addiu  v0, zero, $00ff
    800ABB38	bne    v1, v0, Labb50 [$800abb50]
    800ABB3C	lui    v1, $fffe
    800ABB40	lw     v0, $0000(s3)

    Labb44:	; 800ABB44
    800ABB44	ori    v1, v1, $ffff
    800ABB48	j      Labb7c [$800abb7c]
    800ABB4C	and    v0, v0, v1

    Labb50:	; 800ABB50
    800ABB50	lb     v0, $0005(s0)
    800ABB54	nop
    800ABB58	beq    s6, v0, Labb70 [$800abb70]
    800ABB5C	lui    v1, $0004

    funcabb60:	; 800ABB60
    800ABB60	lw     v0, $0000(s3)
    800ABB64	nop
    800ABB68	or     v0, v0, v1
    800ABB6C	sw     v0, $0000(s3)

    Labb70:	; 800ABB70
    800ABB70	lw     v0, $0000(s3)
    800ABB74	lui    v1, $0001
    800ABB78	or     v0, v0, v1

    Labb7c:	; 800ABB7C
    800ABB7C	sw     v0, $0000(s3)
    800ABB80	j      Labff8 [$800abff8]
    800ABB84	sb     s6, $0005(s0)

    case 4: // 88BB0A80
    800ABB88	beq    s6, zero, Labbb0 [$800abbb0]
    800ABB8C	lui    v1, $0010
    800ABB90	lw     v0, $0008(s3)
    800ABB94	nop
    800ABB98	sh     s7, $005a(v0)
    800ABB9C	lw     v0, $0000(s3)
    800ABBA0	nop
    800ABBA4	or     v0, v0, v1
    800ABBA8	j      Labff8 [$800abff8]
    800ABBAC	sw     v0, $0000(s3)

    Labbb0:	; 800ABBB0
    800ABBB0	lui    v1, $ffef
    800ABBB4	lw     v0, $0000(s3)
    800ABBB8	ori    v1, v1, $ffff
    800ABBBC	and    v0, v0, v1
    800ABBC0	j      Labff8 [$800abff8]
    800ABBC4	sw     v0, $0000(s3)

    case 8: // C8BB0A80
    case 9:
    case a:
    case b:
    800ABBC8	lw     s1, $0010(s0)
    800ABBCC	nop
    800ABBD0	bne    s1, zero, Labc84 [$800abc84]
    800ABBD4	lui    v0, $8006
    800ABBD8	lw     a0, $794c(v0)
    800ABBDC	nop
    800ABBE0	lw     v0, $001c(a0)
    800ABBE4	nop
    800ABBE8	lw     v0, $08e4(v0)
    800ABBEC	nop
    800ABBF0	lw     v0, $000c(v0)
    800ABBF4	nop
    800ABBF8	lw     v0, $0014(v0)
    800ABBFC	nop
    800ABC00	lw     v0, $0020(v0)
    800ABC04	nop
    800ABC08	addu   s1, v0, zero
    800ABC0C	sw     s1, $0010(s0)
    800ABC10	sw     zero, $0000(s1)
    800ABC14	lw     v1, $0004(s3)
    800ABC18	addiu  v0, s1, $0014
    800ABC1C	sw     v0, $0008(s1)
    800ABC20	addiu  v0, s1, $00ac
    800ABC24	sw     v0, $000c(s1)
    800ABC28	addiu  v0, zero, $1000
    800ABC2C	sw     zero, $0010(s1)
    800ABC30	sw     s3, $00f8(s1)
    800ABC34	sh     zero, $00fc(s1)
    800ABC38	sh     zero, $00fe(s1)
    800ABC3C	sh     zero, $0100(s1)
    800ABC40	sh     zero, $0104(s1)
    800ABC44	sh     v0, $0106(s1)
    800ABC48	sh     zero, $0108(s1)
    800ABC4C	sw     zero, $010c(s1)
    800ABC50	sw     v1, $0004(s1)
    800ABC54	lw     v0, $001c(a0)
    800ABC58	nop
    800ABC5C	lw     v0, $08e4(v0)
    800ABC60	nop
    800ABC64	lw     v0, $000c(v0)
    800ABC68	nop
    800ABC6C	lw     v1, $0014(v0)
    800ABC70	nop
    800ABC74	lw     v0, $0020(v1)
    800ABC78	nop
    800ABC7C	addiu  v0, v0, $0110
    800ABC80	sw     v0, $0020(v1)

    Labc84:	; 800ABC84
    800ABC84	lw     v0, $0000(s1)
    800ABC88	nop
    800ABC8C	andi   v0, v0, $0001
    S4 = S1;
    if( V0 == 0 )
    {
        800ABC98	lw     v0, $000c(s3)
        800ABC9C	lw     v1, $000c(s1)
        800ABCA0	addiu  a0, v0, $0040

        loopabca4:	; 800ABCA4
        800ABCA4	lw     t0, $0000(v0)
        800ABCA8	lw     t1, $0004(v0)
        800ABCAC	lw     t2, $0008(v0)
        800ABCB0	lw     t3, $000c(v0)
        800ABCB4	sw     t0, $0000(v1)
        800ABCB8	sw     t1, $0004(v1)
        800ABCBC	sw     t2, $0008(v1)
        800ABCC0	sw     t3, $000c(v1)
        800ABCC4	addiu  v0, v0, $0010
        800ABCC8	bne    v0, a0, loopabca4 [$800abca4]
        800ABCCC	addiu  v1, v1, $0010
        800ABCD0	lw     t0, $0000(v0)
        800ABCD4	lw     t1, $0004(v0)
        800ABCD8	lw     t2, $0008(v0)
        800ABCDC	sw     t0, $0000(v1)
        800ABCE0	sw     t1, $0004(v1)
        800ABCE4	sw     t2, $0008(v1)
        800ABCE8	lw     v0, $0008(s3)
        800ABCEC	lw     v1, $0008(s4)
        800ABCF0	lw     v0, $0008(v0)
        800ABCF4	addiu  a1, sp, $0010
        800ABCF8	sw     v0, $0008(v1)
        800ABCFC	lw     v0, $0008(s3)
        800ABD00	lw     v1, $0008(s4)
        800ABD04	lw     v0, $000c(v0)
        800ABD08	addiu  a2, sp, $0014
        800ABD0C	sw     v0, $000c(v1)
        800ABD10	lw     a0, $0004(s4)
        800ABD14	jal    funcaafd4 [$800aafd4]
        800ABD18	addiu  a3, sp, $0018
        800ABD1C	lw     v0, $0008(s4)
        800ABD20	nop
        800ABD24	lw     v0, $0008(v0)
        800ABD28	nop
        800ABD2C	lw     v1, $0010(v0)
        800ABD30	nop
        800ABD34	bltz   v1, Labd40 [$800abd40]
        800ABD38	addu   s2, zero, zero
        800ABD3C	addu   v1, v1, v0

        Labd40:	; 800ABD40
        800ABD40	lbu    a1, $0003(v0)
        800ABD44	nop
        800ABD48	sltu   v0, s2, a1
        800ABD4C	beq    v0, zero, Labd6c [$800abd6c]
        800ABD50	addu   a0, zero, zero

        loopabd54:	; 800ABD54
        800ABD54	lhu    v0, $0000(v1)
        800ABD58	addiu  a0, a0, $0001
        800ABD5C	addu   s2, s2, v0
        800ABD60	sltu   v0, a0, a1
        800ABD64	bne    v0, zero, loopabd54 [$800abd54]
        800ABD68	addiu  v1, v1, $0028

        Labd6c:	; 800ABD6C
        800ABD6C	lui    s0, $8006
        800ABD70	sll    s2, s2, $01
        800ABD74	lw     v0, $794c(s0)
        800ABD78	lw     a0, $0008(s4)
        800ABD7C	lw     v0, $001c(v0)
        800ABD80	lw     a2, $0008(a0)
        800ABD84	lw     v0, $08e4(v0)
        800ABD88	lbu    v1, $0002(a2)
        800ABD8C	lw     v0, $000c(v0)
        800ABD90	lbu    a2, $0003(a2)
        800ABD94	lw     v0, $0014(v0)
        800ABD98	sll    v1, v1, $05
        800ABD9C	lw     a1, $0020(v0)
        800ABDA0	sll    v0, a2, $01
        800ABDA4	addu   v0, v0, a2
        800ABDA8	sll    v0, v0, $02
        800ABDAC	addu   v1, v1, v0
        800ABDB0	jal    funcb6438 [$800b6438]
        800ABDB4	addu   s2, s2, v1
        A0 = w[S4 + 8];
        A1 = w[SP + 10];
        A2 = w[SP + 14];
        funcb6584; // we prepare render packets here

        800ABDCC	lw     v0, $794c(s0)
        800ABDD0	nop

        Labdd4:	; 800ABDD4
        800ABDD4	lw     v0, $001c(v0)
        800ABDD8	nop
        800ABDDC	lw     v0, $08e4(v0)
        800ABDE0	nop
        800ABDE4	lw     v0, $000c(v0)
        800ABDE8	nop
        800ABDEC	lw     v1, $0014(v0)
        800ABDF0	nop
        800ABDF4	lw     v0, $0020(v1)
        800ABDF8	addiu  a0, zero, $0009
        800ABDFC	addu   v0, v0, s2
        800ABE00	sw     v0, $0020(v1)
        800ABE04	lw     a1, $0004(s4)
        800ABE08	jal    func1c7fc [$8001c7fc]
        800ABE0C	lui    a2, $0019
        800ABE10	addu   a1, v0, zero
        800ABE14	addiu  v0, zero, $ffff (=-$1)
        800ABE18	beq    a1, v0, Labe48 [$800abe48]
        800ABE1C	addiu  a0, zero, $0004
        800ABE20	jal    func1c7fc [$8001c7fc]
        800ABE24	addu   a2, zero, zero
        800ABE28	lw     v1, $0008(s4)
        800ABE2C	nop
        800ABE30	sw     v0, $0050(v1)
        800ABE34	lw     v0, $0008(s4)
        800ABE38	lw     a1, $0018(sp)
        800ABE3C	lw     a0, $0050(v0)
        800ABE40	jal    funcbb3c4 [$800bb3c4]
        800ABE44	nop

        Labe48:	; 800ABE48
        800ABE48	jal    funcac620 [$800ac620]
        800ABE4C	nop
        800ABE50	lui    v1, $0200
        800ABE54	lw     v0, $0000(s1)
        800ABE58	ori    v1, v1, $0001
        800ABE5C	or     v0, v0, v1
        800ABE60	sw     v0, $0000(s1)
    }

    800ABE64	addiu  v0, zero, $0009
    800ABE68	beq    s5, v0, Labf24 [$800abf24]
    800ABE6C	slti   v0, s5, $000a
    800ABE70	beq    v0, zero, Labe88 [$800abe88]
    800ABE74	addiu  v0, zero, $0008
    800ABE78	beq    s5, v0, Labea4 [$800abea4]
    800ABE7C	nop
    800ABE80	j      Labff8 [$800abff8]
    800ABE84	nop

    Labe88:	; 800ABE88
    800ABE88	addiu  v0, zero, $000a
    800ABE8C	beq    s5, v0, Labf34 [$800abf34]
    800ABE90	addiu  v0, zero, $000b
    800ABE94	beq    s5, v0, Labf44 [$800abf44]
    800ABE98	addiu  v0, zero, $0002
    800ABE9C	j      Labff8 [$800abff8]
    800ABEA0	nop

    Labea4:	; 800ABEA4
    800ABEA4	beq    s6, zero, Labf10 [$800abf10]
    800ABEA8	lui    v1, $feff
    800ABEAC	lw     v1, $0008(s4)
    800ABEB0	lw     v0, $0008(s3)
    800ABEB4	nop
    800ABEB8	sw     v0, $0060(v1)
    800ABEBC	lw     v1, $0008(s4)
    800ABEC0	lw     v0, $0104(s1)
    800ABEC4	nop
    800ABEC8	sw     v0, $0064(v1)
    800ABECC	lw     v1, $0008(s4)
    800ABED0	lw     v0, $0108(s1)
    800ABED4	nop
    800ABED8	sw     v0, $0068(v1)
    800ABEDC	lw     v1, $0008(s4)
    800ABEE0	lw     v0, $00fc(s1)
    800ABEE4	nop
    800ABEE8	sw     v0, $006c(v1)
    800ABEEC	lw     v1, $0008(s4)
    800ABEF0	lw     v0, $0100(s1)
    800ABEF4	nop
    800ABEF8	sw     v0, $0070(v1)
    800ABEFC	lw     v0, $0000(s1)
    800ABF00	lui    v1, $0100
    800ABF04	or     v0, v0, v1
    800ABF08	j      Labff8 [$800abff8]
    800ABF0C	sw     v0, $0000(s1)

    Labf10:	; 800ABF10
    800ABF10	lw     v0, $0000(s1)
    800ABF14	ori    v1, v1, $ffff
    800ABF18	and    v0, v0, v1
    800ABF1C	j      Labff8 [$800abff8]
    800ABF20	sw     v0, $0000(s1)

    Labf24:	; 800ABF24
    800ABF24	sh     s6, $00fc(s1)
    800ABF28	sh     s7, $00fe(s1)
    800ABF2C	j      Labff8 [$800abff8]
    800ABF30	sh     fp, $0100(s1)

    Labf34:	; 800ABF34
    800ABF34	sh     s6, $0104(s1)
    800ABF38	sh     s7, $0106(s1)
    800ABF3C	j      Labff8 [$800abff8]
    800ABF40	sh     fp, $0108(s1)

    Labf44:	; 800ABF44
    800ABF44	sb     s6, $010c(s1)
    800ABF48	sb     s7, $010d(s1)
    800ABF4C	sb     fp, $010e(s1)
    800ABF50	j      Labff8 [$800abff8]
    800ABF54	sb     v0, $010f(s1)

    case 10: // 58BF0A80
    case 11:
    case 12:
    case 13:
    {
        A0 = S3;
        A1 = S6;
        A2 = S7;
        funcb2100;
        V1 = V0;
        if( V1 == 0 )
        {
            if( S3 != 13 )
            {
                A0 = S3;
                A1 = S6;
                A2 = S7
                800ABF84	jal    funcb21a0 [$800b21a0]
                V1 = V0;
            }
        }

        if( S5 == 10 )
        {
            [V1 + 8] = h(FP);
        }
        else if( S5 == 11 )
        {
            [V1 + a] = h(FP);
        }
        else if( S5 == 12 )
        {
            [V1 + 1] = b(FP > 0);
        }
        else if( S5 == 13 )
        {
            800ABFC4	addu   a0, s3, zero
            800ABFEC	addu   a1, s6, zero
            800ABFF4	addu   a2, s7, zero
            800ABFF0	jal    funcb2218 [$800b2218]
        }
        break;
}
Labff8:	; 800ABFF8
return 0;
////////////////////////////////



////////////////////////////////
// funcaab30
800AAB30	addiu  sp, sp, $ffc0 (=-$40)
800AAB34	sw     s3, $002c(sp)
800AAB38	addu   s3, a0, zero
800AAB3C	sw     s1, $0024(sp)
800AAB40	addu   s1, a1, zero
800AAB44	sw     s5, $0034(sp)
800AAB48	addiu  s5, zero, $ffff (=-$1)
800AAB4C	addu   a0, s1, zero
800AAB50	sw     ra, $0038(sp)
800AAB54	sw     s4, $0030(sp)
800AAB58	sw     s2, $0028(sp)
800AAB5C	jal    func4ab64 [$8004ab64]
800AAB60	sw     s0, $0020(sp)
800AAB64	addu   a0, v0, zero
800AAB68	sltiu  v0, a0, $0009
800AAB6C	beq    v0, zero, Laab84 [$800aab84]
800AAB70	lui    s0, $8006
800AAB74	jal    func1e350 [$8001e350]
800AAB78	addu   s4, a0, zero
800AAB7C	j      Laabc8 [$800aabc8]
800AAB80	addu   s2, v0, zero

Laab84:	; 800AAB84
800AAB84	lw     v0, $794c(s0)
800AAB88	nop
800AAB8C	lw     v0, $001c(v0)
800AAB90	nop
800AAB94	lbu    v0, $0039(v0)
800AAB98	nop
800AAB9C	addiu  s4, v0, $0009

Laaba0:	; 800AABA0
800AABA0	jal    func1e350 [$8001e350]
800AABA4	addu   a0, s4, zero
800AABA8	lw     v1, $794c(s0)
800AABAC	nop
800AABB0	lw     a0, $001c(v1)
800AABB4	nop
800AABB8	lbu    v1, $0039(a0)
S2 = V0;

800AABC0	addiu  v1, v1, $0001
800AABC4	sb     v1, $0039(a0)

Laabc8:	; 800AABC8
800AABC8	jal    funcaaec4 [$800aaec4]
800AABCC	addu   a0, s3, zero
800AABD0	addu   s3, v0, zero
800AABD4	addiu  a0, zero, $0004
800AABD8	addu   a1, s3, zero
800AABDC	addu   a2, zero, zero
800AABE0	sw     s3, $0004(s2)
800AABE4	jal    func1c7fc [$8001c7fc]
800AABE8	sw     s1, $000c(s2)
800AABEC	lw     v1, $0008(s2)
800AABF0	addu   a0, s3, zero
800AABF4	jal    funcaaf5c [$800aaf5c]
800AABF8	sw     v0, $0008(v1)
800AABFC	addiu  a0, zero, $0004
800AAC00	addu   a1, v0, zero
800AAC04	jal    func1c7fc [$8001c7fc]
800AAC08	addu   a2, zero, zero
800AAC0C	lw     v1, $0008(s2)
800AAC10	beq    v0, zero, Laac60 [$800aac60]
800AAC14	sw     v0, $000c(v1)
800AAC18	lw     v0, $0008(s2)
800AAC1C	nop
800AAC20	lw     v1, $000c(v0)
800AAC24	nop
800AAC28	lw     v0, $000c(v1)
800AAC2C	nop
800AAC30	bltz   v0, Laac60 [$800aac60]
800AAC34	addu   v0, v1, v0
800AAC38	lw     a0, $0010(v1)

Laac3c:	; 800AAC3C
800AAC3C	nop

Laac40:	; 800AAC40
800AAC40	beq    a0, zero, Laac60 [$800aac60]
800AAC44	sw     v0, $000c(v1)
800AAC48	lw     v0, $0008(s2)
800AAC4C	nop
800AAC50	lw     v0, $000c(v0)
800AAC54	nop
800AAC58	addu   v0, v0, a0
800AAC5C	sw     v0, $0010(v1)

Laac60:	; 800AAC60
800AAC60	addu   a0, s3, zero
800AAC64	addiu  a1, sp, $0010
800AAC68	addiu  a2, sp, $0014
800AAC6C	jal    funcaafd4 [$800aafd4]
800AAC70	addiu  a3, sp, $0018
800AAC74	lw     v0, $0008(s2)
800AAC78	nop
800AAC7C	lw     v0, $0008(v0)
800AAC80	nop
800AAC84	lw     v1, $0010(v0)
800AAC88	nop
800AAC8C	bltz   v1, Laac98 [$800aac98]
800AAC90	addu   s1, zero, zero
800AAC94	addu   v1, v1, v0

Laac98:	; 800AAC98
800AAC98	lbu    a1, $0003(v0)
800AAC9C	nop
800AACA0	sltu   v0, s1, a1
800AACA4	beq    v0, zero, Laacc4 [$800aacc4]
800AACA8	addu   a0, zero, zero

loopaacac:	; 800AACAC
800AACAC	lhu    v0, $0000(v1)
800AACB0	addiu  a0, a0, $0001
800AACB4	addu   s1, s1, v0
800AACB8	sltu   v0, a0, a1
800AACBC	bne    v0, zero, loopaacac [$800aacac]
800AACC0	addiu  v1, v1, $0028

Laacc4:	; 800AACC4
800AACC4	lui    s0, $8006
800AACC8	sll    s1, s1, $01
800AACCC	lw     v0, $794c(s0)
800AACD0	lw     a0, $0008(s2)
800AACD4	lw     v0, $001c(v0)
800AACD8	lw     a2, $0008(a0)
800AACDC	lw     v0, $08e4(v0)
800AACE0	lbu    v1, $0002(a2)
800AACE4	lw     v0, $000c(v0)
800AACE8	lbu    a2, $0003(a2)
800AACEC	lw     v0, $0014(v0)
800AACF0	sll    v1, v1, $05
800AACF4	lw     a1, $0020(v0)
800AACF8	sll    v0, a2, $01
800AACFC	addu   v0, v0, a2
800AAD00	sll    v0, v0, $02
800AAD04	addu   v1, v1, v0
800AAD08	jal    funcb6438 [$800b6438]
800AAD0C	addu   s1, s1, v1

A0 = w[S2 + 8];
A1 = w[SP + 10];
A2 = w[SP + 14];
funcb6584; // we prepare render packets here

800AAD24	lw     v0, $794c(s0)
800AAD28	nop
800AAD2C	lw     v0, $001c(v0)
800AAD30	nop
800AAD34	lw     v0, $08e4(v0)
800AAD38	nop
800AAD3C	lw     v0, $000c(v0)
800AAD40	nop
800AAD44	lw     v1, $0014(v0)
800AAD48	nop
800AAD4C	lw     v0, $0020(v1)
800AAD50	nop
800AAD54	addu   v0, v0, s1
800AAD58	jal    funcac620 [$800ac620]
800AAD5C	sw     v0, $0020(v1)
800AAD60	addiu  a0, zero, $0008
800AAD64	addu   a1, s3, zero
800AAD68	jal    func1c7fc [$8001c7fc]
800AAD6C	lui    a2, $0012
800AAD70	addu   a0, v0, zero
800AAD74	lbu    v0, $0001(a0)
800AAD78	nop
800AAD7C	addiu  v1, v0, $ffff (=-$1)
800AAD80	bltz   v1, Laadb4 [$800aadb4]
800AAD84	addiu  a2, a0, $0004
800AAD88	lhu    a1, $0004(a0)
800AAD8C	andi   a0, s3, $ffff
800AAD90	lui    a3, $0019

loopaad94:	; 800AAD94
800AAD94	bne    a1, a0, Laada8 [$800aada8]
800AAD98	nop
800AAD9C	lhu    v0, $0008(a2)
800AADA0	nop
800AADA4	or     s5, v0, a3

Laada8:	; 800AADA8
800AADA8	addiu  v1, v1, $ffff (=-$1)
800AADAC	bgez   v1, loopaad94 [$800aad94]
800AADB0	nop

Laadb4:	; 800AADB4
800AADB4	addiu  v0, zero, $ffff (=-$1)
800AADB8	beq    s5, v0, Laadec [$800aadec]
800AADBC	addiu  a0, zero, $0004
800AADC0	addu   a1, s5, zero
800AADC4	jal    func1c7fc [$8001c7fc]
800AADC8	addu   a2, zero, zero
800AADCC	lw     v1, $0008(s2)
800AADD0	nop
800AADD4	sw     v0, $0050(v1)

Laadd8:	; 800AADD8
800AADD8	lw     v0, $0008(s2)
800AADDC	lw     a1, $0018(sp)
800AADE0	lw     a0, $0050(v0)
800AADE4	jal    funcbb3c4 [$800bb3c4]
800AADE8	nop

Laadec:	; 800AADEC
800AADEC	lui    v0, $8006
800AADF0	lw     v0, $794c(v0)
800AADF4	nop
800AADF8	lw     v0, $001c(v0)
800AADFC	nop
800AAE00	lw     v0, $08e4(v0)
800AAE04	nop
800AAE08	lw     v0, $000c(v0)
800AAE0C	nop
800AAE10	lw     v0, $0014(v0)
800AAE14	nop
800AAE18	lw     v0, $0018(v0)
800AAE1C	nop
800AAE20	beq    v0, zero, Laae54 [$800aae54]
800AAE24	slti   v0, s4, $0009
800AAE28	beq    v0, zero, Laae40 [$800aae40]
800AAE2C	addu   a0, s4, zero
800AAE30	jal    funcc74a8 [$800c74a8]
800AAE34	addu   a1, s2, zero
800AAE38	j      Laae4c [$800aae4c]
800AAE3C	addu   a0, s4, zero

Laae40:	; 800AAE40
800AAE40	jal    funcc74f0 [$800c74f0]
800AAE44	addu   a0, s2, zero
800AAE48	addu   a0, s4, zero

Laae4c:	; 800AAE4C
800AAE4C	jal    funcc3e18 [$800c3e18]
800AAE50	addiu  a1, zero, $0001

Laae54:	; 800AAE54
800AAE54	lui    v0, $8006
800AAE58	lw     v0, $794c(v0)
800AAE5C	nop
800AAE60	lw     v0, $001c(v0)
800AAE64	nop
800AAE68	lw     v0, $08e4(v0)
800AAE6C	nop
800AAE70	lw     v0, $000c(v0)
800AAE74	nop
800AAE78	lw     a0, $0014(v0)
800AAE7C	nop
800AAE80	lw     v0, $0000(a0)
800AAE84	lui    v1, $0001
800AAE88	or     v0, v0, v1
800AAE8C	sw     v0, $0000(a0)
800AAE90	lw     v1, $0000(s2)
800AAE94	addu   v0, s4, zero
800AAE98	ori    v1, v1, $0001
800AAE9C	sw     v1, $0000(s2)
800AAEA0	lw     ra, $0038(sp)
800AAEA4	lw     s5, $0034(sp)
800AAEA8	lw     s4, $0030(sp)
800AAEAC	lw     s3, $002c(sp)
800AAEB0	lw     s2, $0028(sp)
800AAEB4	lw     s1, $0024(sp)
800AAEB8	lw     s0, $0020(sp)

Laaebc:	; 800AAEBC
800AAEBC	jr     ra 
800AAEC0	addiu  sp, sp, $0040
////////////////////////////////



////////////////////////////////
// funcb2100
script = w[A0 + c];

V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
field = w[V0 + 14];
V1 = bu[field + 4b];
V0 = w[field + 58] + V1 * c;
V1 = V0 - c;

loopb2150:	; 800B2150
    if( bu[V1 + 0] == bu[script + 3b] )
    {
        if( hu[V1 + 4] == A1 & ffff )
        {
            if( h[V1 + 6] == ((A2 << 10) >> 10) )
            {
                return V1;
            }
        }
    }
    V1 = V1 - c;
    V0 = V1 < field;
800B2188	beq    v0, zero, loopb2150 [$800b2150]

return 0;
////////////////////////////////