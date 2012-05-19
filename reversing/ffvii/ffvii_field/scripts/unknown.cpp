////////////////////////////////
// funcda214
if( bu[800e08c0 + A0 * 17a] == 0 )
{
    [800e0750 + A0 * 17a] = b(A1);
    [800e0751 + A0 * 17a] = b(A2);
    [800e0752 + A0 * 17a] = b(A3);
    [8009d824] = b(1);
}
////////////////////////////////



////////////////////////////////
// funcda334
V0 = bu[A1];
if( V0 != 0 )
{
    loopda344:	; 800DA344
        V0 = bu[A1];
        A1 = A1 + 1;
        [A0] = b(V0);
        V0 = bu[A1];
        A1 = A1 + 1;
    800DA358	bne    v0, zero, loopda344 [$800da344]
}

[A0] = b(0);
////////////////////////////////



////////////////////////////////
// funcbc9fc
S4 = A0;
S6 = A1;

if( A0 == 4 )
{
    if( bu[80071e24] & 4 )
    {
        if( bu[80114498 + A1] == 0 )
        {
            return;
        }
    }

    [800716c8] = b(S6);

    if( bu[80114498 + A1] != 0 )
    {
        A1 = 7f;
        A2 = 1;
        A3 = 7f;
    }
    else
    {
        A1 = 7;
        A2 = f;
        A3 = 1f;
    }

    A0 = 4;
    funcda214;

    A1 = 800e0628;
}
else
{
    A1 = 800a01d4;
}

A0 = 800e4254;
funcda334;

800BCAF4	lui    s1, $800e
800BCAF8	addiu  s1, s1, $4254
800BCAFC	addu   a0, s1, zero
800BCB00	sll    v0, s6, $10
800BCB04	sra    s2, v0, $10
800BCB08	sll    s3, s2, $03
800BCB0C	lui    v0, $800a
800BCB10	lw     v0, $c6dc(v0)
800BCB14	addiu  a1, s3, $0020
800BCB18	jal    funcda368 [$800da368]
800BCB1C	addu   a1, a1, v0
800BCB20	lui    v0, $8007
800BCB24	lbu    v0, $1e24(v0)
800BCB28	lui    v1, $800a
800BCB2C	lbu    v1, $fe8c(v1)
800BCB30	andi   v0, v0, $0001
800BCB34	or     v1, v1, v0
800BCB38	beq    v1, zero, Lbcb50 [$800bcb50]
800BCB3C	sll    a0, s4, $10
800BCB40	sra    a0, a0, $10
800BCB44	addu   a1, zero, zero
800BCB48	jal    funcda124 [$800da124]
800BCB4C	addu   a2, s1, zero

Lbcb50:	; 800BCB50
800BCB70	lui    a1, $800a
800BCB74	addiu  a1, a1, $01dc
800BCB7C	addu   a0, s1, zero
funcda334;

800BCB80	lui    s0, $800e
800BCB84	addiu  s0, s0, $4288
800BCB88	lui    at, $800a
800BCB8C	addiu  at, at, $a1c4 (=-$5e3c)
800BCB90	addu   at, at, s2
800BCB94	lbu    a0, $0000(at)
800BCB98	jal    funcda424 [$800da424]
800BCB9C	addu   a1, s0, zero
800BCBA0	addu   a0, s1, zero
800BCBA4	jal    funcda368 [$800da368]
800BCBA8	addu   a1, s0, zero
800BCBAC	lui    a1, $800a
800BCBB0	addiu  a1, a1, $01e4
800BCBB4	jal    funcda368 [$800da368]
800BCBB8	addu   a0, s1, zero
800BCBBC	lui    v0, $8011
800BCBC0	addiu  v0, v0, $42d4
800BCBC4	lui    at, $800a
800BCBC8	addiu  at, at, $a1c4 (=-$5e3c)
800BCBCC	addu   at, at, s2
800BCBD0	lbu    v1, $0000(at)
800BCBD4	addu   v0, s3, v0
800BCBD8	addu   v0, v0, v1
800BCBDC	lbu    v1, $0000(v0)
800BCBE0	ori    v0, zero, $0001
800BCBE4	beq    v1, v0, Lbcc28 [$800bcc28]
800BCBE8	slti   v0, v1, $0002
800BCBEC	beq    v0, zero, Lbcc04 [$800bcc04]
800BCBF0	nop
800BCBF4	beq    v1, zero, Lbcc18 [$800bcc18]
800BCBF8	sll    v1, s6, $10
800BCBFC	j      Lbcc48 [$800bcc48]
800BCC00	nop

Lbcc04:	; 800BCC04
800BCC04	ori    v0, zero, $0002
800BCC08	beq    v1, v0, Lbcc38 [$800bcc38]
800BCC0C	sll    v1, s6, $10
800BCC10	j      Lbcc48 [$800bcc48]
800BCC14	nop

Lbcc18:	; 800BCC18
800BCC18	lui    a1, $800a
800BCC1C	addiu  a1, a1, $01ec
800BCC20	j      Lbcc90 [$800bcc90]
800BCC24	addu   a0, s1, zero

Lbcc28:	; 800BCC28
800BCC28	lui    a1, $800a
800BCC2C	addiu  a1, a1, $01f0
800BCC30	j      Lbcc90 [$800bcc90]
800BCC34	addu   a0, s1, zero

Lbcc38:	; 800BCC38
800BCC38	lui    a1, $800a
800BCC3C	addiu  a1, a1, $01f4
800BCC40	j      Lbcc90 [$800bcc90]
800BCC44	addu   a0, s1, zero

Lbcc48:	; 800BCC48
800BCC48	sra    v1, v1, $10
800BCC4C	lui    a0, $8011
800BCC50	addiu  a0, a0, $42d4
800BCC54	sll    v0, v1, $03
800BCC58	addu   v0, v0, a0
800BCC5C	lui    at, $800a
800BCC60	addiu  at, at, $a1c4 (=-$5e3c)
800BCC64	addu   at, at, v1
800BCC68	lbu    v1, $0000(at)
800BCC6C	lui    s0, $800e
800BCC70	addiu  s0, s0, $4288
800BCC74	addu   v0, v0, v1
800BCC78	lbu    a0, $0000(v0)
800BCC7C	jal    funcda444 [$800da444]
800BCC80	addu   a1, s0, zero
800BCC84	lui    a0, $800e
800BCC88	addiu  a0, a0, $4254
800BCC8C	addu   a1, s0, zero

Lbcc90:	; 800BCC90
800BCC90	jal    funcda368 [$800da368]
800BCC94	nop
800BCC98	lui    v0, $8007
800BCC9C	lbu    v0, $1e24(v0)
800BCCA0	lui    v1, $800a
800BCCA4	lbu    v1, $fe8c(v1)
800BCCA8	andi   v0, v0, $0001
800BCCAC	or     v1, v1, v0
800BCCB0	beq    v1, zero, Lbcccc [$800bcccc]
800BCCB4	sll    a0, s4, $10
800BCCB8	sra    a0, a0, $10
800BCCBC	lui    a2, $800e
800BCCC0	addiu  a2, a2, $4254
800BCCC4	jal    funcda124 [$800da124]
800BCCC8	ori    a1, zero, $0001

Lbcccc:	; 800BCCCC
800BCCF4	sll    v0, s6, $10
800BCCF8	sra    s2, v0, $10
800BCCFC	lui    at, $8008
800BCD00	addiu  at, at, $eb98 (=-$1468)
800BCD04	addu   at, at, s2
800BCD08	lbu    v1, $0000(at)
800BCD0C	ori    v0, zero, $00ff
800BCD10	bne    v1, v0, Lbce4c [$800bce4c]
800BCD14	nop
800BCD18	lui    at, $8007
800BCD1C	addiu  at, at, $078c
800BCD20	addu   at, at, s2
800BCD24	lbu    v0, $0000(at)
800BCD28	nop
800BCD2C	bne    v0, v1, Lbcd7c [$800bcd7c]
800BCD30	nop
800BCD34	lui    a0, $800e
800BCD38	addiu  a0, a0, $4254
800BCD3C	lui    a1, $800a
800BCD40	addiu  a1, a1, $01f8
funcda334;

800BCD4C	lui    v0, $8007
800BCD50	lbu    v0, $1e24(v0)
800BCD54	lui    v1, $800a
800BCD58	lbu    v1, $fe8c(v1)
800BCD5C	andi   v0, v0, $0001
800BCD60	or     v1, v1, v0
800BCD64	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCD68	sll    a0, s4, $10
800BCD6C	sra    a0, a0, $10
800BCD70	ori    a1, zero, $0002
800BCD74	j      Lbcf10 [$800bcf10]
800BCD78	ori    a2, zero, $0006

Lbcd7c:	; 800BCD7C
800BCD7C	lui    s1, $800e
800BCD80	addiu  s1, s1, $4254
800BCD84	lui    a1, $800a
800BCD88	addiu  a1, a1, $0200
800BCD90	addu   a0, s1, zero
funcda334;

800BCD94	lui    s0, $800e
800BCD98	addiu  s0, s0, $4288
800BCD9C	lui    at, $8007
800BCDA0	addiu  at, at, $078c
800BCDA4	addu   at, at, s2
800BCDA8	lbu    a0, $0000(at)
800BCDAC	jal    funcda444 [$800da444]
800BCDB0	addu   a1, s0, zero
800BCDB4	addu   a0, s1, zero
800BCDB8	jal    funcda368 [$800da368]
800BCDBC	addu   a1, s0, zero
800BCDC0	lui    at, $8007
800BCDC4	addiu  at, at, $078c
800BCDC8	addu   at, at, s2
800BCDCC	lbu    v1, $0000(at)
800BCDD0	nop
800BCDD4	sll    v0, v1, $01
800BCDD8	addu   v0, v0, v1
800BCDDC	sll    v0, v0, $03
800BCDE0	lui    at, $8008
800BCDE4	addiu  at, at, $e7b8 (=-$1848)
800BCDE8	addu   at, at, v0
800BCDEC	lbu    v0, $0000(at)
800BCDF0	nop
800BCDF4	beq    v0, zero, Lbce0c [$800bce0c]
800BCDF8	addu   a0, s1, zero
800BCDFC	lui    a1, $800a
800BCE00	addiu  a1, a1, $0208
800BCE04	j      Lbce14 [$800bce14]
800BCE08	nop

Lbce0c:	; 800BCE0C
800BCE0C	lui    a1, $800a
800BCE10	addiu  a1, a1, $020c

Lbce14:	; 800BCE14
800BCE14	jal    funcda368 [$800da368]
800BCE18	nop
800BCE1C	lui    v0, $8007
800BCE20	lbu    v0, $1e24(v0)
800BCE24	lui    v1, $800a
800BCE28	lbu    v1, $fe8c(v1)
800BCE2C	andi   v0, v0, $0001
800BCE30	or     v1, v1, v0
800BCE34	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCE38	sll    a0, s4, $10
800BCE3C	sra    a0, a0, $10
800BCE40	ori    a1, zero, $0002
800BCE44	j      Lbcf10 [$800bcf10]
800BCE48	ori    a2, zero, $0003

Lbce4c:	; 800BCE4C
800BCE4C	lui    s1, $800e
800BCE50	addiu  s1, s1, $4254
800BCE54	lui    a1, $800a
800BCE58	addiu  a1, a1, $0214
800BCE60	addu   a0, s1, zero
funcda334;

800BCE64	lui    s0, $800e
800BCE68	addiu  s0, s0, $4288
800BCE6C	lui    at, $8008
800BCE70	addiu  at, at, $eb98 (=-$1468)
800BCE74	addu   at, at, s2
800BCE78	lbu    a0, $0000(at)
800BCE7C	jal    funcda444 [$800da444]
800BCE80	addu   a1, s0, zero
800BCE84	addu   a0, s1, zero
800BCE88	jal    funcda368 [$800da368]
800BCE8C	addu   a1, s0, zero
800BCE90	lui    a1, $800a
800BCE94	addiu  a1, a1, $021c
800BCE98	jal    funcda368 [$800da368]
800BCE9C	addu   a0, s1, zero
800BCEA0	lui    at, $8008
800BCEA4	addiu  at, at, $eb98 (=-$1468)
800BCEA8	addu   at, at, s2
800BCEAC	lbu    v1, $0000(at)
800BCEB0	nop
800BCEB4	sll    v0, v1, $05
800BCEB8	addu   v0, v0, v1
800BCEBC	lui    v1, $800a
800BCEC0	lw     v1, $c544(v1)
800BCEC4	sll    v0, v0, $02
800BCEC8	addu   v0, v0, v1
800BCECC	lbu    a0, $0038(v0)
800BCED0	jal    funcda444 [$800da444]
800BCED4	addu   a1, s0, zero
800BCED8	addu   a0, s1, zero
800BCEDC	jal    funcda368 [$800da368]
800BCEE0	addu   a1, s0, zero
800BCEE4	lui    v0, $8007
800BCEE8	lbu    v0, $1e24(v0)
800BCEEC	lui    v1, $800a
800BCEF0	lbu    v1, $fe8c(v1)
800BCEF4	andi   v0, v0, $0001
800BCEF8	or     v1, v1, v0
800BCEFC	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCF00	sll    a0, s4, $10
800BCF04	sra    a0, a0, $10
800BCF08	ori    a1, zero, $0002
800BCF0C	ori    a2, zero, $0002

Lbcf10:	; 800BCF10
800BCF10	jal    funcda194 [$800da194]
800BCF14	nop
800BCF18	lui    v0, $8007
800BCF1C	lbu    v0, $1e24(v0)
800BCF20	lui    v1, $800a
800BCF24	lbu    v1, $fe8c(v1)
800BCF28	andi   v0, v0, $0001
800BCF2C	or     v1, v1, v0
800BCF30	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCF34	sll    a0, s4, $10
800BCF38	sra    a0, a0, $10
800BCF3C	lui    a2, $800e
800BCF40	addiu  a2, a2, $4254
800BCF44	jal    funcda124 [$800da124]
800BCF48	ori    a1, zero, $0002

Lbcf4c:	; 800BCF4C
800BCF74	sll    v0, s6, $10
800BCF78	sra    s2, v0, $10
800BCF7C	lui    at, $8008
800BCF80	addiu  at, at, $eb98 (=-$1468)
800BCF84	addu   at, at, s2
800BCF88	lbu    v1, $0000(at)
800BCF8C	ori    v0, zero, $00ff
800BCF90	beq    v1, v0, Lbd6a0 [$800bd6a0]
800BCF94	nop
800BCF98	lui    s1, $800e
800BCF9C	addiu  s1, s1, $4254
800BCFA0	lui    a1, $800a
800BCFA4	addiu  a1, a1, $0224
800BCFAC	addu   a0, s1, zero
funcda334;

800BCFB0	lui    at, $8008
800BCFB4	addiu  at, at, $eb98 (=-$1468)
800BCFB8	addu   at, at, s2
800BCFBC	lbu    v1, $0000(at)
800BCFC0	lui    s3, $800e
800BCFC4	addiu  s3, s3, $4288
800BCFC8	sll    v0, v1, $05
800BCFCC	addu   v0, v0, v1
800BCFD0	lui    v1, $800a
800BCFD4	lw     v1, $c544(v1)
800BCFD8	sll    v0, v0, $02
800BCFDC	addu   v0, v0, v1
800BCFE0	lw     a0, $000c(v0)
800BCFE4	addu   a1, s3, zero
800BCFE8	jal    funcda480 [$800da480]
800BCFEC	sra    a0, a0, $0c
800BCFF0	addu   a0, s1, zero
800BCFF4	jal    funcda368 [$800da368]
800BCFF8	addu   a1, s3, zero
800BCFFC	lui    a1, $800a
800BD000	addiu  a1, a1, $0228
800BD004	jal    funcda368 [$800da368]
800BD008	addu   a0, s1, zero
800BD00C	lui    at, $8008
800BD010	addiu  at, at, $eb98 (=-$1468)
800BD014	addu   at, at, s2
800BD018	lbu    v1, $0000(at)
800BD01C	nop
800BD020	sll    v0, v1, $05
800BD024	addu   v0, v0, v1
800BD028	lui    v1, $800a
800BD02C	lw     v1, $c544(v1)
800BD030	sll    v0, v0, $02
800BD034	addu   v0, v0, v1
800BD038	lw     a0, $0010(v0)
800BD03C	addu   a1, s3, zero
800BD040	jal    funcda480 [$800da480]
800BD044	sra    a0, a0, $0c
800BD048	addu   a0, s1, zero
800BD04C	jal    funcda368 [$800da368]
800BD050	addu   a1, s3, zero
800BD054	lui    v0, $8007
800BD058	lbu    v0, $1e24(v0)
800BD05C	lui    v1, $800a
800BD060	lbu    v1, $fe8c(v1)
800BD064	andi   v0, v0, $0001
800BD068	or     v1, v1, v0
800BD06C	beq    v1, zero, Lbd098 [$800bd098]
800BD070	sll    s0, s4, $10
800BD074	sra    s0, s0, $10
800BD078	addu   a0, s0, zero
800BD07C	ori    a1, zero, $0003
800BD080	jal    funcda124 [$800da124]
800BD084	addu   a2, s1, zero
800BD088	addu   a0, s0, zero
800BD08C	ori    a1, zero, $0003
800BD090	jal    funcda194 [$800da194]
800BD094	ori    a2, zero, $0001

Lbd098:	; 800BD098
800BD0B8	lui    a1, $800a
800BD0BC	addiu  a1, a1, $022c
800BD0C0	jal    funcda334 [$800da334]
800BD0C4	addu   a0, s1, zero
800BD0C8	lui    at, $8008
800BD0CC	addiu  at, at, $eb98 (=-$1468)
800BD0D0	addu   at, at, s2
800BD0D4	lbu    v1, $0000(at)
800BD0D8	nop
800BD0DC	sll    v0, v1, $05
800BD0E0	addu   v0, v0, v1
800BD0E4	lui    v1, $800a
800BD0E8	lw     v1, $c544(v1)
800BD0EC	sll    v0, v0, $02
800BD0F0	addu   v0, v0, v1
800BD0F4	lw     a0, $0014(v0)
800BD0F8	addu   a1, s3, zero
800BD0FC	jal    funcda480 [$800da480]
800BD100	sra    a0, a0, $0c
800BD104	addu   a0, s1, zero
800BD108	jal    funcda368 [$800da368]
800BD10C	addu   a1, s3, zero
800BD110	lui    a1, $800a
800BD114	addiu  a1, a1, $0230
800BD118	jal    funcda368 [$800da368]
800BD11C	addu   a0, s1, zero
800BD120	lui    at, $8008
800BD124	addiu  at, at, $eb98 (=-$1468)
800BD128	addu   at, at, s2
800BD12C	lbu    v1, $0000(at)
800BD130	nop
800BD134	sll    v0, v1, $05
800BD138	addu   v0, v0, v1
800BD13C	lui    v1, $800a
800BD140	lw     v1, $c544(v1)
800BD144	sll    v0, v0, $02
800BD148	addu   v0, v0, v1
800BD14C	lhu    a0, $0072(v0)
800BD150	jal    funcda480 [$800da480]
800BD154	addu   a1, s3, zero
800BD158	addu   a0, s1, zero
800BD15C	jal    funcda368 [$800da368]
800BD160	addu   a1, s3, zero
800BD164	lui    v0, $8007
800BD168	lbu    v0, $1e24(v0)
800BD16C	lui    v1, $800a
800BD170	lbu    v1, $fe8c(v1)
800BD174	andi   v0, v0, $0001
800BD178	or     v1, v1, v0
800BD17C	beq    v1, zero, Lbd194 [$800bd194]
800BD180	sll    a0, s4, $10
800BD184	sra    a0, a0, $10
800BD188	ori    a1, zero, $0004
800BD18C	jal    funcda124 [$800da124]
800BD190	addu   a2, s1, zero

Lbd194:	; 800BD194
800BD1B4	lui    at, $8008
800BD1B8	addiu  at, at, $eb98 (=-$1468)
800BD1BC	addu   at, at, s2
800BD1C0	lbu    v0, $0000(at)
800BD1C4	nop
800BD1C8	lui    at, $8007
800BD1CC	addiu  at, at, $56e8
800BD1D0	addu   at, at, v0
800BD1D4	lbu    a0, $0000(at)
800BD1D8	jal    funcda424 [$800da424]
800BD1DC	addu   a1, s1, zero
800BD1E0	lui    a1, $800a
800BD1E4	addiu  a1, a1, $0234
800BD1E8	jal    funcda368 [$800da368]
800BD1EC	addu   a0, s1, zero
800BD1F0	lui    at, $8008
800BD1F4	addiu  at, at, $eb98 (=-$1468)
800BD1F8	addu   at, at, s2
800BD1FC	lbu    v1, $0000(at)
800BD200	nop
800BD204	sll    v0, v1, $05
800BD208	addu   v0, v0, v1
800BD20C	lui    v1, $800a
800BD210	lw     v1, $c544(v1)
800BD214	sll    v0, v0, $02
800BD218	addu   v0, v0, v1
800BD21C	lbu    a0, $005e(v0)
800BD220	jal    funcda444 [$800da444]
800BD224	addu   a1, s3, zero
800BD228	addu   a0, s1, zero
800BD22C	jal    funcda368 [$800da368]
800BD230	addu   a1, s3, zero
800BD234	addu   a0, s1, zero
800BD238	lui    s5, $800a
800BD23C	addiu  s5, s5, $0238
800BD240	jal    funcda368 [$800da368]
800BD244	addu   a1, s5, zero
800BD248	lui    at, $8008
800BD24C	addiu  at, at, $eb98 (=-$1468)
800BD250	addu   at, at, s2
800BD254	lbu    v1, $0000(at)
800BD258	nop
800BD25C	sll    v0, v1, $05
800BD260	addu   v0, v0, v1
800BD264	lui    v1, $800a
800BD268	lw     v1, $c544(v1)
800BD26C	sll    v0, v0, $02
800BD270	addu   v0, v0, v1
800BD274	lh     a0, $0062(v0)
800BD278	jal    funcda480 [$800da480]
800BD27C	addu   a1, s3, zero
800BD280	addu   a0, s1, zero
800BD284	jal    funcda368 [$800da368]
800BD288	addu   a1, s3, zero
800BD28C	addu   a0, s1, zero
800BD290	jal    funcda368 [$800da368]
800BD294	addu   a1, s5, zero
800BD298	lui    at, $8008
800BD29C	addiu  at, at, $eb98 (=-$1468)
800BD2A0	addu   at, at, s2
800BD2A4	lbu    v1, $0000(at)
800BD2A8	nop
800BD2AC	sll    v0, v1, $05
800BD2B0	addu   v0, v0, v1
800BD2B4	lui    v1, $800a
800BD2B8	lw     v1, $c544(v1)
800BD2BC	sll    v0, v0, $02
800BD2C0	addu   v0, v0, v1
800BD2C4	lh     a0, $0064(v0)
800BD2C8	jal    funcda444 [$800da444]
800BD2CC	addu   a1, s3, zero
800BD2D0	addu   a0, s1, zero
800BD2D4	jal    funcda368 [$800da368]
800BD2D8	addu   a1, s3, zero
800BD2DC	lui    v0, $8007
800BD2E0	lbu    v0, $1e24(v0)
800BD2E4	lui    v1, $800a
800BD2E8	lbu    v1, $fe8c(v1)
800BD2EC	andi   v0, v0, $0001
800BD2F0	or     v1, v1, v0
800BD2F4	beq    v1, zero, Lbd320 [$800bd320]
800BD2F8	sll    s0, s4, $10
800BD2FC	sra    s0, s0, $10
800BD300	addu   a0, s0, zero
800BD304	ori    a1, zero, $0005
800BD308	jal    funcda124 [$800da124]
800BD30C	addu   a2, s1, zero
800BD310	addu   a0, s0, zero
800BD314	ori    a1, zero, $0005
800BD318	jal    funcda194 [$800da194]
800BD31C	ori    a2, zero, $0007

Lbd320:	; 800BD320
800BD340	lui    at, $8008
800BD344	addiu  at, at, $eb98 (=-$1468)
800BD348	addu   at, at, s2
800BD34C	lbu    v1, $0000(at)
800BD350	nop
800BD354	sll    v0, v1, $05
800BD358	addu   v0, v0, v1
800BD35C	lui    v1, $800a
800BD360	lw     v1, $c544(v1)
800BD364	sll    v0, v0, $02
800BD368	addu   v0, v0, v1
800BD36C	lbu    v0, $005c(v0)
800BD370	nop
800BD374	beq    v0, zero, Lbd38c [$800bd38c]
800BD378	addu   a0, s1, zero
800BD37C	lui    a1, $800a
800BD380	addiu  a1, a1, $023c
800BD384	j      Lbd390 [$800bd390]
800BD388	nop

Lbd38c:	; 800BD38C
800BD38C	addu   a1, s5, zero

Lbd390:	; 800BD390
800BD390	jal    funcda334 [$800da334]
800BD394	nop
800BD398	sll    v0, s6, $10
800BD39C	sra    v0, v0, $10
800BD3A0	lui    at, $8008
800BD3A4	addiu  at, at, $eb98 (=-$1468)
800BD3A8	addu   at, at, v0
800BD3AC	lbu    v1, $0000(at)
800BD3B0	nop
800BD3B4	sll    v0, v1, $05
800BD3B8	addu   v0, v0, v1
800BD3BC	lui    v1, $800a
800BD3C0	lw     v1, $c544(v1)
800BD3C4	sll    v0, v0, $02
800BD3C8	addu   v0, v0, v1
800BD3CC	lbu    v0, $005b(v0)
800BD3D0	nop
800BD3D4	beq    v0, zero, Lbd3f4 [$800bd3f4]
800BD3D8	nop
800BD3DC	lui    a0, $800e
800BD3E0	addiu  a0, a0, $4254
800BD3E4	lui    a1, $800a
800BD3E8	addiu  a1, a1, $0238
800BD3EC	j      Lbd404 [$800bd404]
800BD3F0	nop

Lbd3f4:	; 800BD3F4
800BD3F4	lui    a0, $800e
800BD3F8	addiu  a0, a0, $4254
800BD3FC	lui    a1, $800a
800BD400	addiu  a1, a1, $0240

Lbd404:	; 800BD404
800BD404	jal    funcda368 [$800da368]
800BD408	nop
800BD40C	sll    v0, s6, $10
800BD410	sra    v0, v0, $10
800BD414	lui    at, $8008
800BD418	addiu  at, at, $eb98 (=-$1468)
800BD41C	addu   at, at, v0
800BD420	lbu    v1, $0000(at)
800BD424	nop
800BD428	sll    v0, v1, $05
800BD42C	addu   v0, v0, v1
800BD430	lui    v1, $800a
800BD434	lw     v1, $c544(v1)
800BD438	sll    v0, v0, $02
800BD43C	addu   v0, v0, v1
800BD440	lbu    v0, $0059(v0)
800BD444	nop
800BD448	beq    v0, zero, Lbd468 [$800bd468]
800BD44C	nop
800BD450	lui    a0, $800e
800BD454	addiu  a0, a0, $4254
800BD458	lui    a1, $800a
800BD45C	addiu  a1, a1, $0238
800BD460	j      Lbd478 [$800bd478]
800BD464	nop

Lbd468:	; 800BD468
800BD468	lui    a0, $800e
800BD46C	addiu  a0, a0, $4254
800BD470	lui    a1, $800a
800BD474	addiu  a1, a1, $0244

Lbd478:	; 800BD478
800BD478	jal    funcda368 [$800da368]
800BD47C	nop
800BD480	lui    s1, $800e
800BD484	addiu  s1, s1, $4254
800BD488	lui    a1, $800a
800BD48C	addiu  a1, a1, $0248
800BD490	jal    funcda368 [$800da368]
800BD494	addu   a0, s1, zero
800BD498	sll    v0, s6, $10
800BD49C	sra    s2, v0, $10
800BD4A0	lui    at, $8008
800BD4A4	addiu  at, at, $eb98 (=-$1468)
800BD4A8	addu   at, at, s2
800BD4AC	lbu    v1, $0000(at)
800BD4B0	lui    s0, $800e
800BD4B4	addiu  s0, s0, $4288
800BD4B8	sll    v0, v1, $05
800BD4BC	addu   v0, v0, v1
800BD4C0	lui    v1, $800a
800BD4C4	lw     v1, $c544(v1)
800BD4C8	sll    v0, v0, $02
800BD4CC	addu   v0, v0, v1
800BD4D0	lhu    a0, $006e(v0)
800BD4D4	jal    funcda444 [$800da444]
800BD4D8	addu   a1, s0, zero
800BD4DC	addu   a0, s1, zero
800BD4E0	jal    funcda368 [$800da368]
800BD4E4	addu   a1, s0, zero
800BD4E8	lui    a1, $800a
800BD4EC	addiu  a1, a1, $024c
800BD4F0	jal    funcda368 [$800da368]
800BD4F4	addu   a0, s1, zero
800BD4F8	lui    at, $8008
800BD4FC	addiu  at, at, $eb98 (=-$1468)
800BD500	addu   at, at, s2
800BD504	lbu    v1, $0000(at)
800BD508	nop
800BD50C	sll    v0, v1, $05
800BD510	addu   v0, v0, v1
800BD514	lui    v1, $800a
800BD518	lw     v1, $c544(v1)
800BD51C	sll    v0, v0, $02
800BD520	addu   v0, v0, v1
800BD524	lhu    a0, $006c(v0)
800BD528	jal    funcda444 [$800da444]
800BD52C	addu   a1, s0, zero
800BD530	addu   a0, s1, zero
800BD534	jal    funcda368 [$800da368]
800BD538	addu   a1, s0, zero
800BD53C	lui    v0, $8007
800BD540	lbu    v0, $1e24(v0)
800BD544	lui    v1, $800a
800BD548	lbu    v1, $fe8c(v1)
800BD54C	andi   v0, v0, $0001
800BD550	or     v1, v1, v0
800BD554	beq    v1, zero, Lbd56c [$800bd56c]
800BD558	sll    a0, s4, $10
800BD55C	sra    a0, a0, $10
800BD560	ori    a1, zero, $0006
800BD564	jal    funcda124 [$800da124]
800BD568	addu   a2, s1, zero

Lbd56c:	; 800BD56C
800BD58C	lui    a1, $800a
800BD590	addiu  a1, a1, $0250
800BD594	jal    funcda334 [$800da334]
800BD598	addu   a0, s1, zero
800BD59C	lui    at, $8008
800BD5A0	addiu  at, at, $eb98 (=-$1468)
800BD5A4	addu   at, at, s2
800BD5A8	lbu    v1, $0000(at)
800BD5AC	nop
800BD5B0	sll    v0, v1, $05
800BD5B4	addu   v0, v0, v1
800BD5B8	lui    v1, $800a
800BD5BC	lw     v1, $c544(v1)
800BD5C0	sll    v0, v0, $02
800BD5C4	addu   v0, v0, v1
800BD5C8	lhu    a0, $0070(v0)
800BD5CC	jal    funcda480 [$800da480]
800BD5D0	addu   a1, s0, zero
800BD5D4	addu   a0, s1, zero
800BD5D8	jal    funcda368 [$800da368]
800BD5DC	addu   a1, s0, zero
800BD5E0	lui    a1, $800a
800BD5E4	addiu  a1, a1, $0254
800BD5E8	jal    funcda368 [$800da368]
800BD5EC	addu   a0, s1, zero
800BD5F0	lui    at, $8008
800BD5F4	addiu  at, at, $eb98 (=-$1468)
800BD5F8	addu   at, at, s2
800BD5FC	lbu    v1, $0000(at)
800BD600	nop
800BD604	sll    v0, v1, $05
800BD608	addu   v0, v0, v1
800BD60C	lui    v1, $800a
800BD610	lw     v1, $c544(v1)
800BD614	sll    v0, v0, $02
800BD618	addu   v0, v0, v1
800BD61C	lh     a0, $0060(v0)
800BD620	jal    funcda480 [$800da480]
800BD624	addu   a1, s0, zero
800BD628	addu   a0, s1, zero
800BD62C	jal    funcda368 [$800da368]
800BD630	addu   a1, s0, zero
800BD634	lui    v0, $8007
800BD638	lbu    v0, $1e24(v0)
800BD63C	lui    v1, $800a
800BD640	lbu    v1, $fe8c(v1)
800BD644	andi   v0, v0, $0001
800BD648	or     v1, v1, v0
800BD64C	beq    v1, zero, Lbd678 [$800bd678]
800BD650	sll    s0, s4, $10
800BD654	sra    s0, s0, $10
800BD658	addu   a0, s0, zero
800BD65C	ori    a1, zero, $0007
800BD660	jal    funcda124 [$800da124]
800BD664	addu   a2, s1, zero
800BD668	addu   a0, s0, zero
800BD66C	ori    a1, zero, $0007
800BD670	jal    funcda194 [$800da194]
800BD674	ori    a2, zero, $0007

Lbd678:	; 800BD678
800BD698	j      Lbda90 [$800bda90]
800BD69C	sll    v0, s4, $10

Lbd6a0:	; 800BD6A0
800BD6A0	lui    at, $8007
800BD6A4	addiu  at, at, $078c
800BD6A8	addu   at, at, s2
800BD6AC	lbu    v0, $0000(at)
800BD6B0	nop
800BD6B4	beq    v0, v1, Lbda0c [$800bda0c]
800BD6B8	nop
800BD6BC	lui    s0, $800e
800BD6C0	addiu  s0, s0, $4254
800BD6C4	lui    a1, $800a
800BD6C8	addiu  a1, a1, $0258
800BD6CC	jal    funcda334 [$800da334]
800BD6D0	addu   a0, s0, zero
800BD6D4	lui    at, $8007
800BD6D8	addiu  at, at, $078c
800BD6DC	addu   at, at, s2
800BD6E0	lbu    v1, $0000(at)
800BD6E4	lui    s1, $800e
800BD6E8	addiu  s1, s1, $4288
800BD6EC	sll    v0, v1, $01
800BD6F0	addu   v0, v0, v1
800BD6F4	sll    v0, v0, $03
800BD6F8	lui    at, $8008
800BD6FC	addiu  at, at, $e7ac (=-$1854)
800BD700	addu   at, at, v0
800BD704	lh     a0, $0000(at)
800BD708	jal    funcda480 [$800da480]
800BD70C	addu   a1, s1, zero
800BD710	addu   a0, s0, zero
800BD714	jal    funcda368 [$800da368]
800BD718	addu   a1, s1, zero
800BD71C	lui    a1, $800a
800BD720	addiu  a1, a1, $025c
800BD724	jal    funcda368 [$800da368]
800BD728	addu   a0, s0, zero
800BD72C	lui    at, $8007
800BD730	addiu  at, at, $078c
800BD734	addu   at, at, s2
800BD738	lbu    v1, $0000(at)
800BD73C	nop
800BD740	sll    v0, v1, $01
800BD744	addu   v0, v0, v1
800BD748	sll    v0, v0, $03
800BD74C	lui    at, $8008
800BD750	addiu  at, at, $e7ae (=-$1852)
800BD754	addu   at, at, v0
800BD758	lh     a0, $0000(at)
800BD75C	jal    funcda480 [$800da480]
800BD760	addu   a1, s1, zero
800BD764	addu   a0, s0, zero
800BD768	jal    funcda368 [$800da368]
800BD76C	addu   a1, s1, zero
800BD770	lui    v0, $8007
800BD774	lbu    v0, $1e24(v0)
800BD778	lui    v1, $800a
800BD77C	lbu    v1, $fe8c(v1)
800BD780	andi   v0, v0, $0001
800BD784	or     v1, v1, v0
800BD788	beq    v1, zero, Lbd7a0 [$800bd7a0]
800BD78C	sll    a0, s4, $10
800BD790	sra    a0, a0, $10
800BD794	ori    a1, zero, $0003
800BD798	jal    funcda124 [$800da124]
800BD79C	addu   a2, s0, zero

Lbd7a0:	; 800BD7A0
800BD7C0	lui    a1, $800a
800BD7C4	addiu  a1, a1, $0260
800BD7C8	jal    funcda334 [$800da334]
800BD7CC	addu   a0, s0, zero
800BD7D0	lui    at, $8007
800BD7D4	addiu  at, at, $078c
800BD7D8	addu   at, at, s2
800BD7DC	lbu    v1, $0000(at)
800BD7E0	nop
800BD7E4	sll    v0, v1, $01
800BD7E8	addu   v0, v0, v1
800BD7EC	sll    v0, v0, $03
800BD7F0	lui    at, $8008
800BD7F4	addiu  at, at, $e7b0 (=-$1850)
800BD7F8	addu   at, at, v0
800BD7FC	lh     a0, $0000(at)
800BD800	jal    funcda480 [$800da480]
800BD804	addu   a1, s1, zero
800BD808	addu   a0, s0, zero
800BD80C	jal    funcda368 [$800da368]
800BD810	addu   a1, s1, zero
800BD814	lui    v0, $8007
800BD818	lbu    v0, $1e24(v0)
800BD81C	lui    v1, $800a
800BD820	lbu    v1, $fe8c(v1)
800BD824	andi   v0, v0, $0001
800BD828	or     v1, v1, v0
800BD82C	beq    v1, zero, Lbd844 [$800bd844]
800BD830	sll    a0, s4, $10
800BD834	sra    a0, a0, $10
800BD838	ori    a1, zero, $0004
800BD83C	jal    funcda124 [$800da124]
800BD840	addu   a2, s0, zero

Lbd844:	; 800BD844
800BD864	lui    a1, $800a
800BD868	addiu  a1, a1, $0264
800BD86C	jal    funcda334 [$800da334]
800BD870	addu   a0, s0, zero
800BD874	lui    at, $8007
800BD878	addiu  at, at, $078c
800BD87C	addu   at, at, s2
800BD880	lbu    v1, $0000(at)
800BD884	nop
800BD888	sll    v0, v1, $01
800BD88C	addu   v0, v0, v1
800BD890	sll    v0, v0, $03
800BD894	lui    at, $8008
800BD898	addiu  at, at, $e7b2 (=-$184e)
800BD89C	addu   at, at, v0
800BD8A0	lh     a0, $0000(at)
800BD8A4	jal    funcda480 [$800da480]
800BD8A8	addu   a1, s1, zero
800BD8AC	addu   a0, s0, zero
800BD8B0	jal    funcda368 [$800da368]
800BD8B4	addu   a1, s1, zero
800BD8B8	lui    a1, $800a
800BD8BC	addiu  a1, a1, $0268
800BD8C0	jal    funcda368 [$800da368]
800BD8C4	addu   a0, s0, zero
800BD8C8	lui    at, $8007
800BD8CC	addiu  at, at, $078c
800BD8D0	addu   at, at, s2
800BD8D4	lbu    v1, $0000(at)
800BD8D8	nop
800BD8DC	sll    v0, v1, $01
800BD8E0	addu   v0, v0, v1
800BD8E4	sll    v0, v0, $03
800BD8E8	lui    at, $8008
800BD8EC	addiu  at, at, $e7b4 (=-$184c)
800BD8F0	addu   at, at, v0
800BD8F4	lh     a0, $0000(at)
800BD8F8	jal    funcda480 [$800da480]
800BD8FC	addu   a1, s1, zero
800BD900	addu   a0, s0, zero
800BD904	jal    funcda368 [$800da368]
800BD908	addu   a1, s1, zero
800BD90C	lui    v0, $8007
800BD910	lbu    v0, $1e24(v0)
800BD914	lui    v1, $800a
800BD918	lbu    v1, $fe8c(v1)
800BD91C	andi   v0, v0, $0001
800BD920	or     v1, v1, v0
800BD924	beq    v1, zero, Lbd93c [$800bd93c]
800BD928	sll    a0, s4, $10
800BD92C	sra    a0, a0, $10
800BD930	ori    a1, zero, $0005
800BD934	jal    funcda124 [$800da124]
800BD938	addu   a2, s0, zero

Lbd93c:	; 800BD93C
800BD95C	lui    a1, $800a
800BD960	addiu  a1, a1, $026c
800BD964	jal    funcda334 [$800da334]
800BD968	addu   a0, s0, zero
800BD96C	lui    at, $8007
800BD970	addiu  at, at, $078c
800BD974	addu   at, at, s2
800BD978	lbu    v1, $0000(at)
800BD97C	nop
800BD980	sll    v0, v1, $01
800BD984	addu   v0, v0, v1
800BD988	sll    v0, v0, $03
800BD98C	lui    at, $8008
800BD990	addiu  at, at, $e7b6 (=-$184a)
800BD994	addu   at, at, v0
800BD998	lh     a0, $0000(at)
800BD99C	jal    funcda480 [$800da480]
800BD9A0	addu   a1, s1, zero
800BD9A4	addu   a0, s0, zero
800BD9A8	jal    funcda368 [$800da368]
800BD9AC	addu   a1, s1, zero
800BD9B0	lui    v0, $8007
800BD9B4	lbu    v0, $1e24(v0)
800BD9B8	lui    v1, $800a
800BD9BC	lbu    v1, $fe8c(v1)
800BD9C0	andi   v0, v0, $0001
800BD9C4	or     v1, v1, v0
800BD9C8	beq    v1, zero, Lbd9e0 [$800bd9e0]
800BD9CC	sll    a0, s4, $10
800BD9D0	sra    a0, a0, $10
800BD9D4	ori    a1, zero, $0006
800BD9D8	jal    funcda124 [$800da124]
800BD9DC	addu   a2, s0, zero

Lbd9e0:	; 800BD9E0
800BDA00	sll    a0, s4, $10
800BDA04	j      Lbda7c [$800bda7c]
800BDA08	sra    a0, a0, $10

Lbda0c:	; 800BDA0C
800BDA0C	lui    v0, $8007
800BDA10	lbu    v0, $1e24(v0)
800BDA14	lui    v1, $800a
800BDA18	lbu    v1, $fe8c(v1)
800BDA1C	andi   v0, v0, $0001
800BDA20	or     v1, v1, v0
800BDA24	beq    v1, zero, Lbda8c [$800bda8c]
800BDA28	sll    s0, s4, $10
800BDA2C	sra    s0, s0, $10
800BDA30	addu   a0, s0, zero
800BDA34	ori    a1, zero, $0003
800BDA38	lui    s1, $800a
800BDA3C	addiu  s1, s1, $0270
800BDA40	jal    funcda124 [$800da124]
800BDA44	addu   a2, s1, zero
800BDA48	addu   a0, s0, zero
800BDA4C	ori    a1, zero, $0004
800BDA50	jal    funcda124 [$800da124]
800BDA54	addu   a2, s1, zero
800BDA58	addu   a0, s0, zero
800BDA5C	ori    a1, zero, $0005
800BDA60	jal    funcda124 [$800da124]
800BDA64	addu   a2, s1, zero
800BDA68	addu   a0, s0, zero
800BDA6C	ori    a1, zero, $0006
800BDA70	jal    funcda124 [$800da124]
800BDA74	addu   a2, s1, zero
800BDA78	addu   a0, s0, zero

Lbda7c:	; 800BDA7C
800BDA7C	lui    a2, $800a
800BDA80	addiu  a2, a2, $0270
800BDA84	jal    funcda124 [$800da124]
800BDA88	ori    a1, zero, $0007

Lbda8c:	; 800BDA8C
800BDA8C	sll    v0, s4, $10

Lbda90:	; 800BDA90
800BDA90	sra    s0, v0, $10
800BDA94	ori    v0, zero, $0004
if( S0 == V0 )
{
    return;
}

800BDAA0	lui    s1, $800e
800BDAA4	addiu  s1, s1, $4254
800BDAA8	lui    a1, $800a
800BDAAC	addiu  a1, a1, $0274
800BDAB0	jal    funcda334 [$800da334]
800BDAB4	addu   a0, s1, zero
800BDAB8	lui    s2, $800e
800BDABC	addiu  s2, s2, $4288
800BDAC0	lui    a0, $8007
800BDAC4	lh     a0, $1e38(a0)
800BDAC8	jal    funcda480 [$800da480]
800BDACC	addu   a1, s2, zero
800BDAD0	addu   a0, s1, zero
800BDAD4	jal    funcda368 [$800da368]
800BDAD8	addu   a1, s2, zero
800BDADC	lui    a1, $800a
800BDAE0	addiu  a1, a1, $0278
800BDAE4	jal    funcda368 [$800da368]
800BDAE8	addu   a0, s1, zero
800BDAEC	lui    a0, $8007
800BDAF0	lh     a0, $1e3c(a0)
800BDAF4	jal    funcda480 [$800da480]
800BDAF8	addu   a1, s2, zero
800BDAFC	addu   a0, s1, zero
800BDB00	jal    funcda368 [$800da368]
800BDB04	addu   a1, s2, zero

V1 = bu[8009fe8c] | (bu[80071e24] & 01);

800BDB20	beq    v1, zero, Lbdb44 [$800bdb44]
800BDB24	addu   a0, s0, zero
800BDB28	ori    a1, zero, $0008
800BDB2C	jal    funcda124 [$800da124]
800BDB30	addu   a2, s1, zero
800BDB34	addu   a0, s0, zero
800BDB38	ori    a1, zero, $0008
800BDB3C	jal    funcda194 [$800da194]
800BDB40	ori    a2, zero, $0003

Lbdb44:	; 800BDB44
800BDB64	lui    a1, $800a
800BDB68	addiu  a1, a1, $027c
800BDB6C	jal    funcda334 [$800da334]
800BDB70	addu   a0, s1, zero
800BDB74	lui    s3, $800a
800BDB78	addiu  s3, s3, $ac1e (=-$53e2)
800BDB7C	lh     v1, $0000(s3)
800BDB80	nop
800BDB84	sll    v0, v1, $05
800BDB88	addu   v0, v0, v1
800BDB8C	sll    v0, v0, $02
800BDB90	lui    at, $8007
800BDB94	addiu  at, at, $4f16
800BDB98	addu   at, at, v0
800BDB9C	lhu    v1, $0000(at)
800BDBA0	nop
800BDBA4	sll    v0, v1, $01
800BDBA8	addu   v0, v0, v1
800BDBAC	lui    v1, $800e
800BDBB0	lw     v1, $4274(v1)
800BDBB4	sll    v0, v0, $03
800BDBB8	addu   v0, v0, v1
800BDBBC	lh     a0, $0000(v0)
800BDBC0	jal    funcda480 [$800da480]
800BDBC4	addu   a1, s2, zero
800BDBC8	addu   a0, s1, zero
800BDBCC	jal    funcda368 [$800da368]
800BDBD0	addu   a1, s2, zero
800BDBD4	lui    v0, $8007
800BDBD8	lbu    v0, $1e24(v0)
800BDBDC	lui    v1, $800a
800BDBE0	lbu    v1, $fe8c(v1)
800BDBE4	andi   v0, v0, $0001
800BDBE8	or     v1, v1, v0
800BDBEC	beq    v1, zero, Lbdc10 [$800bdc10]
800BDBF0	addu   a0, s0, zero
800BDBF4	ori    a1, zero, $0009
800BDBF8	jal    funcda124 [$800da124]
800BDBFC	addu   a2, s1, zero
800BDC00	addu   a0, s0, zero
800BDC04	ori    a1, zero, $0009
800BDC08	jal    funcda194 [$800da194]
800BDC0C	ori    a2, zero, $0002

Lbdc10:	; 800BDC10
800BDC30	addu   a0, s1, zero
800BDC34	lui    s7, $800a
800BDC38	addiu  s7, s7, $0288
800BDC3C	jal    funcda334 [$800da334]
800BDC40	addu   a1, s7, zero
800BDC44	lh     v1, $0000(s3)
800BDC48	nop
800BDC4C	sll    v0, v1, $05
800BDC50	addu   v0, v0, v1
800BDC54	sll    v0, v0, $02
800BDC58	lui    at, $8007
800BDC5C	addiu  at, at, $4f16
800BDC60	addu   at, at, v0
800BDC64	lhu    v1, $0000(at)
800BDC68	nop
800BDC6C	sll    v0, v1, $01
800BDC70	addu   v0, v0, v1
800BDC74	lui    v1, $800e
800BDC78	lw     v1, $4274(v1)
800BDC7C	sll    v0, v0, $03
800BDC80	addu   v0, v0, v1
800BDC84	lh     a0, $0002(v0)
800BDC88	jal    funcda480 [$800da480]
800BDC8C	addu   a1, s2, zero
800BDC90	addu   a0, s1, zero
800BDC94	jal    funcda368 [$800da368]
800BDC98	addu   a1, s2, zero
800BDC9C	addu   a0, s1, zero
800BDCA0	lui    s5, $800a
800BDCA4	addiu  s5, s5, $028c
800BDCA8	jal    funcda368 [$800da368]
800BDCAC	addu   a1, s5, zero
800BDCB0	lh     v1, $0000(s3)
800BDCB4	nop
800BDCB8	sll    v0, v1, $05
800BDCBC	addu   v0, v0, v1
800BDCC0	sll    v0, v0, $02
800BDCC4	lui    at, $8007
800BDCC8	addiu  at, at, $4f16
800BDCCC	addu   at, at, v0
800BDCD0	lhu    v1, $0000(at)
800BDCD4	nop
800BDCD8	sll    v0, v1, $01
800BDCDC	addu   v0, v0, v1
800BDCE0	lui    v1, $800e
800BDCE4	lw     v1, $4274(v1)
800BDCE8	sll    v0, v0, $03
800BDCEC	addu   v0, v0, v1
800BDCF0	lh     a0, $0004(v0)
800BDCF4	jal    funcda480 [$800da480]
800BDCF8	addu   a1, s2, zero
800BDCFC	addu   a0, s1, zero
800BDD00	jal    funcda368 [$800da368]
800BDD04	addu   a1, s2, zero
800BDD08	lui    v0, $8007
800BDD0C	lbu    v0, $1e24(v0)
800BDD10	lui    v1, $800a
800BDD14	lbu    v1, $fe8c(v1)
800BDD18	andi   v0, v0, $0001
800BDD1C	or     v1, v1, v0
800BDD20	beq    v1, zero, Lbdd34 [$800bdd34]
800BDD24	addu   a0, s0, zero
800BDD28	ori    a1, zero, $000a
800BDD2C	jal    funcda124 [$800da124]
800BDD30	addu   a2, s1, zero

Lbdd34:	; 800BDD34
800BDD54	lui    a1, $800a
800BDD58	addiu  a1, a1, $0290
800BDD5C	jal    funcda334 [$800da334]
800BDD60	addu   a0, s1, zero
800BDD64	lh     v1, $0000(s3)
800BDD68	nop
800BDD6C	sll    v0, v1, $05
800BDD70	addu   v0, v0, v1
800BDD74	sll    v0, v0, $02
800BDD78	lui    at, $8007
800BDD7C	addiu  at, at, $4f16
800BDD80	addu   at, at, v0
800BDD84	lhu    v1, $0000(at)
800BDD88	nop
800BDD8C	sll    v0, v1, $01
800BDD90	addu   v0, v0, v1
800BDD94	lui    v1, $800e
800BDD98	lw     v1, $4274(v1)
800BDD9C	sll    v0, v0, $03
800BDDA0	addu   v0, v0, v1
800BDDA4	lh     a0, $0008(v0)
800BDDA8	jal    funcda480 [$800da480]
800BDDAC	addu   a1, s2, zero
800BDDB0	addu   a0, s1, zero
800BDDB4	jal    funcda368 [$800da368]
800BDDB8	addu   a1, s2, zero
800BDDBC	lui    v0, $8007
800BDDC0	lbu    v0, $1e24(v0)
800BDDC4	lui    v1, $800a
800BDDC8	lbu    v1, $fe8c(v1)
800BDDCC	andi   v0, v0, $0001
800BDDD0	or     v1, v1, v0
800BDDD4	beq    v1, zero, Lbddf8 [$800bddf8]
800BDDD8	addu   a0, s0, zero
800BDDDC	ori    a1, zero, $000b
800BDDE0	jal    funcda124 [$800da124]
800BDDE4	addu   a2, s1, zero
800BDDE8	addu   a0, s0, zero
800BDDEC	ori    a1, zero, $000b
800BDDF0	jal    funcda194 [$800da194]
800BDDF4	ori    a2, zero, $0004

Lbddf8:	; 800BDDF8
800BDE18	addu   a0, s1, zero
800BDE1C	jal    funcda334 [$800da334]
800BDE20	addu   a1, s7, zero
800BDE24	lh     v1, $0000(s3)
800BDE28	nop
800BDE2C	sll    v0, v1, $05
800BDE30	addu   v0, v0, v1
800BDE34	sll    v0, v0, $02
800BDE38	lui    at, $8007
800BDE3C	addiu  at, at, $4f16
800BDE40	addu   at, at, v0
800BDE44	lhu    v1, $0000(at)
800BDE48	nop
800BDE4C	sll    v0, v1, $01
800BDE50	addu   v0, v0, v1
800BDE54	lui    v1, $800e
800BDE58	lw     v1, $4274(v1)
800BDE5C	sll    v0, v0, $03
800BDE60	addu   v0, v0, v1
800BDE64	lh     a0, $000a(v0)
800BDE68	jal    funcda480 [$800da480]
800BDE6C	addu   a1, s2, zero
800BDE70	addu   a0, s1, zero
800BDE74	jal    funcda368 [$800da368]
800BDE78	addu   a1, s2, zero
800BDE7C	addu   a0, s1, zero
800BDE80	jal    funcda368 [$800da368]
800BDE84	addu   a1, s5, zero
800BDE88	lh     v1, $0000(s3)
800BDE8C	nop
800BDE90	sll    v0, v1, $05
800BDE94	addu   v0, v0, v1
800BDE98	sll    v0, v0, $02
800BDE9C	lui    at, $8007
800BDEA0	addiu  at, at, $4f16
800BDEA4	addu   at, at, v0
800BDEA8	lhu    v1, $0000(at)
800BDEAC	nop
800BDEB0	sll    v0, v1, $01
800BDEB4	addu   v0, v0, v1
800BDEB8	lui    v1, $800e
800BDEBC	lw     v1, $4274(v1)
800BDEC0	sll    v0, v0, $03
800BDEC4	addu   v0, v0, v1
800BDEC8	lh     a0, $000c(v0)
800BDECC	jal    funcda480 [$800da480]
800BDED0	addu   a1, s2, zero
800BDED4	addu   a0, s1, zero
800BDED8	jal    funcda368 [$800da368]
800BDEDC	addu   a1, s2, zero
800BDEE0	lui    v0, $8007
800BDEE4	lbu    v0, $1e24(v0)
800BDEE8	lui    v1, $800a
800BDEEC	lbu    v1, $fe8c(v1)
800BDEF0	andi   v0, v0, $0001
800BDEF4	or     v1, v1, v0
800BDEF8	beq    v1, zero, Lbdf0c [$800bdf0c]
800BDEFC	addu   a0, s0, zero
800BDF00	ori    a1, zero, $000c
800BDF04	jal    funcda124 [$800da124]
800BDF08	addu   a2, s1, zero

Lbdf0c:	; 800BDF0C
800BDF2C	lui    a1, $800a
800BDF30	addiu  a1, a1, $029c
800BDF34	jal    funcda334 [$800da334]
800BDF38	addu   a0, s1, zero
800BDF3C	lh     v1, $0000(s3)
800BDF40	nop
800BDF44	sll    v0, v1, $05
800BDF48	addu   v0, v0, v1
800BDF4C	sll    v0, v0, $02
800BDF50	lui    at, $8007
800BDF54	addiu  at, at, $4f16
800BDF58	addu   at, at, v0
800BDF5C	lhu    v1, $0000(at)
800BDF60	nop
800BDF64	sll    v0, v1, $01
800BDF68	addu   v0, v0, v1
800BDF6C	lui    v1, $800e
800BDF70	lw     v1, $4274(v1)
800BDF74	sll    v0, v0, $03
800BDF78	addu   v0, v0, v1
800BDF7C	lh     a0, $0010(v0)
800BDF80	jal    funcda480 [$800da480]
800BDF84	addu   a1, s2, zero
800BDF88	addu   a0, s1, zero
800BDF8C	jal    funcda368 [$800da368]
800BDF90	addu   a1, s2, zero
800BDF94	lui    v0, $8007
800BDF98	lbu    v0, $1e24(v0)
800BDF9C	lui    v1, $800a
800BDFA0	lbu    v1, $fe8c(v1)
800BDFA4	andi   v0, v0, $0001
800BDFA8	or     v1, v1, v0
800BDFAC	beq    v1, zero, Lbdfd8 [$800bdfd8]
800BDFB0	sll    s0, s4, $10
800BDFB4	sra    s0, s0, $10
800BDFB8	addu   a0, s0, zero
800BDFBC	ori    a1, zero, $000d
800BDFC0	jal    funcda124 [$800da124]
800BDFC4	addu   a2, s1, zero
800BDFC8	addu   a0, s0, zero
800BDFCC	ori    a1, zero, $000d
800BDFD0	jal    funcda194 [$800da194]
800BDFD4	ori    a2, zero, $0003

Lbdfd8:	; 800BDFD8
800BDFF8	addu   a0, s1, zero
800BDFFC	jal    funcda334 [$800da334]
800BE000	addu   a1, s7, zero
800BE004	lh     v1, $0000(s3)
800BE008	nop
800BE00C	sll    v0, v1, $05
800BE010	addu   v0, v0, v1
800BE014	sll    v0, v0, $02
800BE018	lui    at, $8007
800BE01C	addiu  at, at, $4f16
800BE020	addu   at, at, v0
800BE024	lhu    v1, $0000(at)
800BE028	nop
800BE02C	sll    v0, v1, $01
800BE030	addu   v0, v0, v1
800BE034	lui    v1, $800e
800BE038	lw     v1, $4274(v1)
800BE03C	sll    v0, v0, $03
800BE040	addu   v0, v0, v1
800BE044	lh     a0, $0012(v0)
800BE048	jal    funcda480 [$800da480]
800BE04C	addu   a1, s2, zero
800BE050	addu   a0, s1, zero
800BE054	jal    funcda368 [$800da368]
800BE058	addu   a1, s2, zero
800BE05C	addu   a0, s1, zero
800BE060	jal    funcda368 [$800da368]
800BE064	addu   a1, s5, zero
800BE068	lh     v1, $0000(s3)
800BE06C	nop
800BE070	sll    v0, v1, $05
800BE074	addu   v0, v0, v1
800BE078	sll    v0, v0, $02
800BE07C	lui    at, $8007
800BE080	addiu  at, at, $4f16
800BE084	addu   at, at, v0
800BE088	lhu    v1, $0000(at)
800BE08C	nop
800BE090	sll    v0, v1, $01
800BE094	addu   v0, v0, v1
800BE098	lui    v1, $800e
800BE09C	lw     v1, $4274(v1)
800BE0A0	sll    v0, v0, $03
800BE0A4	addu   v0, v0, v1
800BE0A8	lh     a0, $0014(v0)
800BE0AC	jal    funcda480 [$800da480]
800BE0B0	addu   a1, s2, zero
800BE0B4	addu   a0, s1, zero
800BE0B8	jal    funcda368 [$800da368]
800BE0BC	addu   a1, s2, zero
800BE0C0	lui    v0, $8007
800BE0C4	lbu    v0, $1e24(v0)
800BE0C8	lui    v1, $800a
800BE0CC	lbu    v1, $fe8c(v1)
800BE0D0	andi   v0, v0, $0001
800BE0D4	or     v1, v1, v0
800BE0D8	beq    v1, zero, Lbe0f0 [$800be0f0]
800BE0DC	sll    a0, s4, $10
800BE0E0	sra    a0, a0, $10
800BE0E4	ori    a1, zero, $000e
800BE0E8	jal    funcda124 [$800da124]
800BE0EC	addu   a2, s1, zero

Lbe0f0:	; 800BE0F0
800BE110	lui    a1, $800a
800BE114	addiu  a1, a1, $02a8
800BE118	jal    funcda334 [$800da334]
800BE11C	addu   a0, s1, zero
800BE120	sll    v0, s6, $10
800BE124	sra    s3, v0, $10
800BE128	lui    at, $8008
800BE12C	addiu  at, at, $eb98 (=-$1468)
800BE130	addu   at, at, s3
800BE134	lbu    v1, $0000(at)
800BE138	nop
800BE13C	sll    v0, v1, $05
800BE140	addu   v0, v0, v1
800BE144	lui    v1, $800a
800BE148	lw     v1, $c544(v1)
800BE14C	sll    v0, v0, $02
800BE150	addu   v0, v0, v1
800BE154	lh     a0, $0040(v0)
800BE158	jal    funcda480 [$800da480]
800BE15C	addu   a1, s2, zero
800BE160	addu   a0, s1, zero
800BE164	jal    funcda368 [$800da368]
800BE168	addu   a1, s2, zero
800BE16C	lui    v0, $8007
800BE170	lbu    v0, $1e24(v0)
800BE174	lui    v1, $800a
800BE178	lbu    v1, $fe8c(v1)
800BE17C	andi   v0, v0, $0001
800BE180	or     v1, v1, v0
800BE184	beq    v1, zero, Lbe1b0 [$800be1b0]
800BE188	sll    s0, s4, $10
800BE18C	sra    s0, s0, $10
800BE190	addu   a0, s0, zero
800BE194	ori    a1, zero, $000f
800BE198	jal    funcda124 [$800da124]
800BE19C	addu   a2, s1, zero
800BE1A0	addu   a0, s0, zero
800BE1A4	ori    a1, zero, $000f
800BE1A8	jal    funcda194 [$800da194]
800BE1AC	ori    a2, zero, $0002

Lbe1b0:	; 800BE1B0
800BE1D0	addu   a0, s1, zero
800BE1D4	jal    funcda334 [$800da334]
800BE1D8	addu   a1, s7, zero
800BE1DC	lui    at, $8008
800BE1E0	addiu  at, at, $eb98 (=-$1468)
800BE1E4	addu   at, at, s3
800BE1E8	lbu    v1, $0000(at)
800BE1EC	nop
800BE1F0	sll    v0, v1, $05
800BE1F4	addu   v0, v0, v1
800BE1F8	lui    v1, $800a
800BE1FC	lw     v1, $c544(v1)
800BE200	sll    v0, v0, $02
800BE204	addu   v0, v0, v1
800BE208	lh     a0, $0046(v0)
800BE20C	jal    funcda480 [$800da480]
800BE210	addu   a1, s2, zero
800BE214	addu   a0, s1, zero
800BE218	jal    funcda368 [$800da368]
800BE21C	addu   a1, s2, zero
800BE220	addu   a0, s1, zero
800BE224	jal    funcda368 [$800da368]
800BE228	addu   a1, s5, zero
800BE22C	lui    at, $8008
800BE230	addiu  at, at, $eb98 (=-$1468)
800BE234	addu   at, at, s3
800BE238	lbu    v1, $0000(at)
800BE23C	nop
800BE240	sll    v0, v1, $05
800BE244	addu   v0, v0, v1
800BE248	lui    v1, $800a
800BE24C	lw     v1, $c544(v1)
800BE250	sll    v0, v0, $02
800BE254	addu   v0, v0, v1
800BE258	lh     a0, $004c(v0)
800BE25C	jal    funcda480 [$800da480]
800BE260	addu   a1, s2, zero
800BE264	addu   a0, s1, zero
800BE268	jal    funcda368 [$800da368]
800BE26C	addu   a1, s2, zero
800BE270	lui    v0, $8007
800BE274	lbu    v0, $1e24(v0)
800BE278	lui    v1, $800a
800BE27C	lbu    v1, $fe8c(v1)
800BE280	andi   v0, v0, $0001
800BE284	or     v1, v1, v0
800BE288	beq    v1, zero, Lbe2a0 [$800be2a0]
800BE28C	sll    a0, s4, $10
800BE290	sra    a0, a0, $10
800BE294	ori    a1, zero, $0010
800BE298	jal    funcda124 [$800da124]
800BE29C	addu   a2, s1, zero

Lbe2a0:	; 800BE2A0
800BE2C0	lui    a1, $800a
800BE2C4	addiu  a1, a1, $02b4
800BE2C8	jal    funcda334 [$800da334]
800BE2CC	addu   a0, s1, zero
800BE2D0	addu   a1, s2, zero
800BE2D4	lui    a0, $800a
800BE2D8	lbu    a0, $d289(a0)
800BE2DC	lui    v0, $800a
800BE2E0	lbu    v0, $d288(v0)
800BE2E4	sll    a0, a0, $08
800BE2E8	jal    funcda480 [$800da480]
800BE2EC	or     a0, v0, a0
800BE2F0	addu   a0, s1, zero
800BE2F4	jal    funcda368 [$800da368]
800BE2F8	addu   a1, s2, zero
800BE2FC	lui    v0, $800a
800BE300	lw     v0, $c6e0(v0)
800BE304	nop
800BE308	lbu    v0, $0032(v0)
800BE30C	nop
800BE310	beq    v0, zero, Lbe34c [$800be34c]
800BE314	nop
800BE318	lui    v0, $8008
800BE31C	lbu    v0, $1dc4(v0)
800BE320	nop
800BE324	beq    v0, zero, Lbe33c [$800be33c]
800BE328	nop
800BE32C	lui    a1, $800a
800BE330	addiu  a1, a1, $0238
800BE334	j      Lbe37c [$800be37c]
800BE338	addu   a0, s1, zero

Lbe33c:	; 800BE33C
800BE33C	lui    a1, $800a
800BE340	addiu  a1, a1, $02b8
800BE344	j      Lbe37c [$800be37c]
800BE348	addu   a0, s1, zero

Lbe34c:	; 800BE34C
800BE34C	lui    v0, $8008
800BE350	lbu    v0, $1dc4(v0)
800BE354	nop
800BE358	beq    v0, zero, Lbe370 [$800be370]
800BE35C	nop
800BE360	lui    a1, $800a
800BE364	addiu  a1, a1, $02bc
800BE368	j      Lbe37c [$800be37c]
800BE36C	addu   a0, s1, zero

Lbe370:	; 800BE370
800BE370	addu   a0, s1, zero
800BE374	lui    a1, $800a
800BE378	addiu  a1, a1, $02c0

Lbe37c:	; 800BE37C
800BE37C	jal    funcda368 [$800da368]
800BE380	nop
800BE384	lui    s1, $800e
800BE388	addiu  s1, s1, $4254
800BE38C	lui    a1, $800a
800BE390	addiu  a1, a1, $02c4
800BE394	jal    funcda368 [$800da368]
800BE398	addu   a0, s1, zero
800BE39C	lui    s0, $800e
800BE3A0	addiu  s0, s0, $4288
800BE3A4	lui    a0, $800a
800BE3A8	lbu    a0, $cbdc(a0)
800BE3AC	jal    funcda424 [$800da424]
800BE3B0	addu   a1, s0, zero
800BE3B4	addu   a0, s1, zero
800BE3B8	jal    funcda368 [$800da368]
800BE3BC	addu   a1, s0, zero
800BE3C0	lui    a0, $800a
800BE3C4	lbu    a0, $cbdd(a0)
800BE3C8	jal    funcda424 [$800da424]
800BE3CC	addu   a1, s0, zero
800BE3D0	addu   a0, s1, zero
800BE3D4	jal    funcda368 [$800da368]
800BE3D8	addu   a1, s0, zero
800BE3DC	lui    a0, $800a
800BE3E0	lbu    a0, $cbde(a0)
800BE3E4	jal    funcda424 [$800da424]
800BE3E8	addu   a1, s0, zero
800BE3EC	addu   a0, s1, zero
800BE3F0	jal    funcda368 [$800da368]
800BE3F4	addu   a1, s0, zero
800BE3F8	lui    v0, $800a
800BE3FC	lw     v0, $c6e0(v0)
800BE400	nop
800BE404	lbu    v0, $003b(v0)
800BE408	nop
800BE40C	beq    v0, zero, Lbe424 [$800be424]
800BE410	addu   a0, s1, zero
800BE414	lui    a1, $800a
800BE418	addiu  a1, a1, $02c8
800BE41C	j      Lbe42c [$800be42c]
800BE420	nop

Lbe424:	; 800BE424
800BE424	lui    a1, $800a
800BE428	addiu  a1, a1, $02c0

Lbe42c:	; 800BE42C
800BE42C	jal    funcda368 [$800da368]
800BE430	nop
800BE434	lui    v0, $8007
800BE438	lbu    v0, $1e24(v0)
800BE43C	lui    v1, $800a
800BE440	lbu    v1, $fe8c(v1)
800BE444	andi   v0, v0, $0001
800BE448	or     v1, v1, v0
800BE44C	beq    v1, zero, Lbe47c [$800be47c]
800BE450	sll    s0, s4, $10
800BE454	sra    s0, s0, $10
800BE458	addu   a0, s0, zero
800BE45C	lui    a2, $800e
800BE460	addiu  a2, a2, $4254
800BE464	jal    funcda124 [$800da124]
800BE468	ori    a1, zero, $0011
800BE46C	addu   a0, s0, zero
800BE470	ori    a1, zero, $0011
800BE474	jal    funcda194 [$800da194]
800BE478	ori    a2, zero, $0006

Lbe47c:	; 800BE47C
800BE4A4	lui    s1, $800e
800BE4A8	addiu  s1, s1, $4254
800BE4AC	lui    a1, $800a
800BE4B0	addiu  a1, a1, $02cc
800BE4B4	jal    funcda334 [$800da334]
800BE4B8	addu   a0, s1, zero
800BE4BC	lui    s0, $800e
800BE4C0	addiu  s0, s0, $4288
800BE4C4	lui    a0, $8007
800BE4C8	lhu    a0, $5e12(a0)
800BE4CC	jal    funcda480 [$800da480]
800BE4D0	addu   a1, s0, zero
800BE4D4	addu   a0, s1, zero
800BE4D8	jal    funcda368 [$800da368]
800BE4DC	addu   a1, s0, zero
800BE4E0	lui    a1, $800a
800BE4E4	addiu  a1, a1, $02d0
800BE4E8	jal    funcda368 [$800da368]
800BE4EC	addu   a0, s1, zero
800BE4F0	lui    a0, $8007
800BE4F4	lhu    a0, $5e10(a0)
800BE4F8	jal    funcda480 [$800da480]
800BE4FC	addu   a1, s0, zero
800BE500	addu   a0, s1, zero
800BE504	jal    funcda368 [$800da368]
800BE508	addu   a1, s0, zero
800BE50C	lui    v0, $8007
800BE510	lbu    v0, $16d4(v0)
800BE514	nop
800BE518	beq    v0, zero, Lbe530 [$800be530]
800BE51C	nop
800BE520	lui    a1, $800a
800BE524	addiu  a1, a1, $02d4
800BE528	jal    funcda368 [$800da368]
800BE52C	addu   a0, s1, zero

Lbe530:	; 800BE530
800BE530	lui    v0, $8007
800BE534	lbu    v0, $1e24(v0)
800BE538	lui    v1, $800a
800BE53C	lbu    v1, $fe8c(v1)
800BE540	andi   v0, v0, $0001
800BE544	or     v1, v1, v0
800BE548	beq    v1, zero, Lbe6a0 [$800be6a0]
800BE54C	sll    v0, s4, $10
800BE550	sra    s0, v0, $10
800BE554	addu   a0, s0, zero
800BE558	ori    a1, zero, $0012
800BE55C	jal    funcda124 [$800da124]
800BE560	addu   a2, s1, zero
800BE564	lui    v0, $801a
800BE568	lui    v1, $8007
800BE56C	lw     v1, $5e10(v1)
800BE570	ori    v0, v0, $ffff
800BE574	sltu   v0, v0, v1
800BE578	beq    v0, zero, Lbe5c0 [$800be5c0]
800BE57C	lui    v0, $801a
800BE580	lui    v0, $800a
800BE584	lbu    v0, $d29b(v0)
800BE588	nop
800BE58C	andi   v0, v0, $0010
800BE590	beq    v0, zero, Lbe5a4 [$800be5a4]
800BE594	addu   a0, s0, zero
800BE598	ori    a1, zero, $0012
800BE59C	j      Lbe5ac [$800be5ac]
800BE5A0	ori    a2, zero, $0005

Lbe5a4:	; 800BE5A4
800BE5A4	ori    a1, zero, $0012
800BE5A8	ori    a2, zero, $0003

Lbe5ac:	; 800BE5AC
800BE5AC	jal    funcda194 [$800da194]
800BE5B0	nop
800BE5B4	lui    v0, $801a
800BE5B8	lui    v1, $8007
800BE5BC	lw     v1, $5e10(v1)

Lbe5c0:	; 800BE5C0
800BE5C0	ori    v0, v0, $dfff
800BE5C4	sltu   v0, v0, v1
800BE5C8	beq    v0, zero, Lbe5e0 [$800be5e0]
800BE5CC	sll    a0, s4, $10
800BE5D0	sra    a0, a0, $10
800BE5D4	ori    a1, zero, $0012
800BE5D8	j      Lbe698 [$800be698]
800BE5DC	ori    a2, zero, $0005

Lbe5e0:	; 800BE5E0
800BE5E0	lui    v0, $801a
800BE5E4	ori    v0, v0, $afff
800BE5E8	sltu   v0, v0, v1
800BE5EC	beq    v0, zero, Lbe600 [$800be600]
800BE5F0	sra    a0, a0, $10
800BE5F4	ori    a1, zero, $0012
800BE5F8	j      Lbe698 [$800be698]
800BE5FC	ori    a2, zero, $0004

Lbe600:	; 800BE600
800BE600	lui    v0, $801a
800BE604	ori    v0, v0, $7fff
800BE608	sltu   v0, v0, v1
800BE60C	beq    v0, zero, Lbe624 [$800be624]
800BE610	sll    a0, s4, $10
800BE614	sra    a0, a0, $10
800BE618	ori    a1, zero, $0012
800BE61C	j      Lbe698 [$800be698]
800BE620	ori    a2, zero, $0001

Lbe624:	; 800BE624
800BE624	lui    v0, $801a
800BE628	ori    v0, v0, $3fff
800BE62C	sltu   v0, v0, v1
800BE630	beq    v0, zero, Lbe644 [$800be644]
800BE634	sra    a0, a0, $10
800BE638	ori    a1, zero, $0012
800BE63C	j      Lbe698 [$800be698]
800BE640	ori    a2, zero, $0003

Lbe644:	; 800BE644
800BE644	lui    v0, $8019
800BE648	ori    v0, v0, $ffff
800BE64C	sltu   v0, v0, v1
800BE650	beq    v0, zero, Lbe668 [$800be668]
800BE654	sll    a0, s4, $10
800BE658	sra    a0, a0, $10
800BE65C	ori    a1, zero, $0012
800BE660	j      Lbe698 [$800be698]
800BE664	ori    a2, zero, $0002

Lbe668:	; 800BE668
800BE668	lui    v0, $8019
800BE66C	ori    v0, v0, $7fff
800BE670	sltu   v0, v0, v1
800BE674	beq    v0, zero, Lbe688 [$800be688]
800BE678	sra    a0, a0, $10
800BE67C	ori    a1, zero, $0012
800BE680	j      Lbe698 [$800be698]
800BE684	addu   a2, zero, zero

Lbe688:	; 800BE688
800BE688	sll    a0, s4, $10
800BE68C	sra    a0, a0, $10
800BE690	ori    a1, zero, $0012
800BE694	ori    a2, zero, $0007

Lbe698:	; 800BE698
800BE698	jal    funcda194 [$800da194]
800BE69C	nop

Lbe6a0:	; 800BE6A0
800BE6C8	lui    s0, $800e
800BE6CC	addiu  s0, s0, $4288
800BE6D0	lui    a0, $800a
800BE6D4	lbu    a0, $d391(a0)
800BE6D8	jal    funcda424 [$800da424]
800BE6DC	addu   a1, s0, zero
800BE6E0	lui    s1, $800e
800BE6E4	addiu  s1, s1, $4254
800BE6E8	addu   a0, s1, zero
800BE6EC	jal    funcda334 [$800da334]
800BE6F0	addu   a1, s0, zero
800BE6F4	lui    a0, $800a
800BE6F8	lbu    a0, $d392(a0)
800BE6FC	jal    funcda424 [$800da424]
800BE700	addu   a1, s0, zero
800BE704	addu   a0, s1, zero
800BE708	jal    funcda368 [$800da368]
800BE70C	addu   a1, s0, zero
800BE710	lui    a0, $800a
800BE714	lbu    a0, $d393(a0)
800BE718	jal    funcda424 [$800da424]
800BE71C	addu   a1, s0, zero
800BE720	addu   a0, s1, zero
800BE724	jal    funcda368 [$800da368]
800BE728	addu   a1, s0, zero
800BE72C	lui    v0, $800a
800BE730	lhu    v0, $d78a(v0)
800BE734	nop
800BE738	andi   v0, v0, $0001
800BE73C	beq    v0, zero, Lbe754 [$800be754]
800BE740	addu   a0, s1, zero
800BE744	lui    a1, $800a
800BE748	addiu  a1, a1, $02d8
800BE74C	j      Lbe75c [$800be75c]
800BE750	nop

Lbe754:	; 800BE754
800BE754	lui    a1, $800a
800BE758	addiu  a1, a1, $0238

Lbe75c:	; 800BE75C
800BE75C	jal    funcda368 [$800da368]
800BE760	nop
800BE764	lui    v0, $800a
800BE768	lhu    v0, $d78a(v0)
800BE76C	nop
800BE770	andi   v0, v0, $0002
800BE774	beq    v0, zero, Lbe794 [$800be794]
800BE778	nop
800BE77C	lui    a0, $800e
800BE780	addiu  a0, a0, $4254
800BE784	lui    a1, $800a
800BE788	addiu  a1, a1, $02c4
800BE78C	j      Lbe7a4 [$800be7a4]
800BE790	nop

Lbe794:	; 800BE794
800BE794	lui    a0, $800e
800BE798	addiu  a0, a0, $4254
800BE79C	lui    a1, $800a
800BE7A0	addiu  a1, a1, $0238

Lbe7a4:	; 800BE7A4
800BE7A4	jal    funcda368 [$800da368]
800BE7A8	nop
800BE7AC	lui    v0, $800a
800BE7B0	lhu    v0, $d78a(v0)
800BE7B4	nop
800BE7B8	andi   v0, v0, $0004
800BE7BC	beq    v0, zero, Lbe7dc [$800be7dc]
800BE7C0	nop
800BE7C4	lui    a0, $800e
800BE7C8	addiu  a0, a0, $4254
800BE7CC	lui    a1, $800a
800BE7D0	addiu  a1, a1, $0240
800BE7D4	j      Lbe7ec [$800be7ec]
800BE7D8	nop

Lbe7dc:	; 800BE7DC
800BE7DC	lui    a0, $800e
800BE7E0	addiu  a0, a0, $4254
800BE7E4	lui    a1, $800a
800BE7E8	addiu  a1, a1, $0238

Lbe7ec:	; 800BE7EC
800BE7EC	jal    funcda368 [$800da368]
800BE7F0	nop
800BE7F4	lui    v0, $800a
800BE7F8	lhu    v0, $d78a(v0)
800BE7FC	nop
800BE800	andi   v0, v0, $0008
800BE804	beq    v0, zero, Lbe824 [$800be824]
800BE808	nop
800BE80C	lui    a0, $800e
800BE810	addiu  a0, a0, $4254
800BE814	lui    a1, $800a
800BE818	addiu  a1, a1, $02dc
800BE81C	j      Lbe834 [$800be834]
800BE820	nop

Lbe824:	; 800BE824
800BE824	lui    a0, $800e
800BE828	addiu  a0, a0, $4254
800BE82C	lui    a1, $800a
800BE830	addiu  a1, a1, $0238

Lbe834:	; 800BE834
800BE834	jal    funcda368 [$800da368]
800BE838	nop
800BE83C	lui    v0, $800a
800BE840	lhu    v0, $d78a(v0)
800BE844	nop
800BE848	andi   v0, v0, $0010
800BE84C	beq    v0, zero, Lbe86c [$800be86c]
800BE850	nop
800BE854	lui    a0, $800e
800BE858	addiu  a0, a0, $4254
800BE85C	lui    a1, $800a
800BE860	addiu  a1, a1, $02e0
800BE864	j      Lbe87c [$800be87c]
800BE868	nop

Lbe86c:	; 800BE86C
800BE86C	lui    a0, $800e
800BE870	addiu  a0, a0, $4254
800BE874	lui    a1, $800a
800BE878	addiu  a1, a1, $0238

Lbe87c:	; 800BE87C
800BE87C	jal    funcda368 [$800da368]
800BE880	nop
800BE884	lui    v0, $800a
800BE888	lhu    v0, $d78a(v0)
800BE88C	nop
800BE890	andi   v0, v0, $0020
800BE894	beq    v0, zero, Lbe8b4 [$800be8b4]
800BE898	nop
800BE89C	lui    a0, $800e
800BE8A0	addiu  a0, a0, $4254
800BE8A4	lui    a1, $800a
800BE8A8	addiu  a1, a1, $02e4
800BE8AC	j      Lbe8c4 [$800be8c4]
800BE8B0	nop

Lbe8b4:	; 800BE8B4
800BE8B4	lui    a0, $800e
800BE8B8	addiu  a0, a0, $4254
800BE8BC	lui    a1, $800a
800BE8C0	addiu  a1, a1, $0238

Lbe8c4:	; 800BE8C4
800BE8C4	jal    funcda368 [$800da368]
800BE8C8	nop
800BE8CC	lui    v0, $800a
800BE8D0	lhu    v0, $d78a(v0)
800BE8D4	nop
800BE8D8	andi   v0, v0, $0040
800BE8DC	beq    v0, zero, Lbe8fc [$800be8fc]
800BE8E0	nop
800BE8E4	lui    a0, $800e
800BE8E8	addiu  a0, a0, $4254
800BE8EC	lui    a1, $800a
800BE8F0	addiu  a1, a1, $02e8
800BE8F4	j      Lbe90c [$800be90c]
800BE8F8	nop

Lbe8fc:	; 800BE8FC
800BE8FC	lui    a0, $800e
800BE900	addiu  a0, a0, $4254
800BE904	lui    a1, $800a
800BE908	addiu  a1, a1, $0238

Lbe90c:	; 800BE90C
800BE90C	jal    funcda368 [$800da368]
800BE910	nop
800BE914	lui    v0, $800a
800BE918	lhu    v0, $d78a(v0)
800BE91C	nop
800BE920	andi   v0, v0, $0080
800BE924	beq    v0, zero, Lbe944 [$800be944]
800BE928	nop
800BE92C	lui    a0, $800e
800BE930	addiu  a0, a0, $4254
800BE934	lui    a1, $800a
800BE938	addiu  a1, a1, $023c
800BE93C	j      Lbe954 [$800be954]
800BE940	nop

Lbe944:	; 800BE944
800BE944	lui    a0, $800e
800BE948	addiu  a0, a0, $4254
800BE94C	lui    a1, $800a
800BE950	addiu  a1, a1, $0238

Lbe954:	; 800BE954
800BE954	jal    funcda368 [$800da368]
800BE958	nop
800BE95C	lui    v0, $800a
800BE960	lhu    v0, $d78a(v0)
800BE964	nop
800BE968	andi   v0, v0, $0100
800BE96C	beq    v0, zero, Lbe98c [$800be98c]
800BE970	nop
800BE974	lui    a0, $800e
800BE978	addiu  a0, a0, $4254
800BE97C	lui    a1, $800a
800BE980	addiu  a1, a1, $02ec
800BE984	j      Lbe99c [$800be99c]
800BE988	nop

Lbe98c:	; 800BE98C
800BE98C	lui    a0, $800e
800BE990	addiu  a0, a0, $4254
800BE994	lui    a1, $800a
800BE998	addiu  a1, a1, $0238

Lbe99c:	; 800BE99C
800BE99C	jal    funcda368 [$800da368]
800BE9A0	nop
800BE9A4	lui    v0, $800a
800BE9A8	lhu    v0, $d78a(v0)
800BE9AC	nop
800BE9B0	andi   v0, v0, $0200
800BE9B4	beq    v0, zero, Lbe9d4 [$800be9d4]
800BE9B8	nop
800BE9BC	lui    a0, $800e
800BE9C0	addiu  a0, a0, $4254
800BE9C4	lui    a1, $800a
800BE9C8	addiu  a1, a1, $02f0
800BE9CC	j      Lbe9e4 [$800be9e4]
800BE9D0	nop

Lbe9d4:	; 800BE9D4
800BE9D4	lui    a0, $800e
800BE9D8	addiu  a0, a0, $4254
800BE9DC	lui    a1, $800a
800BE9E0	addiu  a1, a1, $0238

Lbe9e4:	; 800BE9E4
800BE9E4	jal    funcda368 [$800da368]
800BE9E8	nop
800BE9EC	lui    v0, $800a
800BE9F0	lhu    v0, $d78a(v0)
800BE9F4	nop
800BE9F8	andi   v0, v0, $0400
800BE9FC	beq    v0, zero, Lbea1c [$800bea1c]
800BEA00	nop
800BEA04	lui    a0, $800e
800BEA08	addiu  a0, a0, $4254
800BEA0C	lui    a1, $800a
800BEA10	addiu  a1, a1, $02f4
800BEA14	j      Lbea2c [$800bea2c]
800BEA18	nop

Lbea1c:	; 800BEA1C
800BEA1C	lui    a0, $800e
800BEA20	addiu  a0, a0, $4254
800BEA24	lui    a1, $800a
800BEA28	addiu  a1, a1, $0238

Lbea2c:	; 800BEA2C
800BEA2C	jal    funcda368 [$800da368]
800BEA30	nop
800BEA34	lui    v0, $8007
800BEA38	lbu    v0, $1e24(v0)
800BEA3C	lui    v1, $800a
800BEA40	lbu    v1, $fe8c(v1)
800BEA44	andi   v0, v0, $0001
800BEA48	or     v1, v1, v0
800BEA4C	beq    v1, zero, Lbea7c [$800bea7c]
800BEA50	sll    s0, s4, $10
800BEA54	sra    s0, s0, $10
800BEA58	addu   a0, s0, zero
800BEA5C	lui    a2, $800e
800BEA60	addiu  a2, a2, $4254
800BEA64	jal    funcda124 [$800da124]
800BEA68	ori    a1, zero, $0013
800BEA6C	addu   a0, s0, zero
800BEA70	ori    a1, zero, $0013
800BEA74	jal    funcda194 [$800da194]
800BEA78	addu   a2, zero, zero

Lbea7c:	; 800BEA7C
////////////////////////////////