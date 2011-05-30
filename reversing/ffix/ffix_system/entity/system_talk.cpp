////////////////////////////////
// func48a5c
S2 = A0;

if (w[8007b708] == 1) // if field
{
    S3 = w[8007b97c] & a0000;
}
else
{
    S3 = w[8007b97c] & 20000;
}

80048AAC	beq    s3, zero, L48b48 [$80048b48]


A0 = S2;
A1 = 4;
A2 = 0;
system_check_entity_collisions;
S0 = V0;

if (S0 != 0)
{
    A0 = S2;
    A1 = S0;
    A2 = h[S2 + 22];
    system_get_how_much_we_need_rotate_to_face_entity;

    [8007ae20] = w(V0);

    if (V0 + 3ff < 7ff)
    {
        [S2 + 93] = b(bu[S0 + 7]);

        if (S3 == 80000)
        {
            A0 = S0;
            A1 = 1; // priority
            A2 = 8;
            A3 = 0;
            func384d0;

            if (V0 != 0)
            {
                return V0;
            }
        }

        A0 = S0;
        A1 = 1; // priority
        A2 = 3;
        A3 = 0;
        func384d0;

        if (V0 != 0)
        {
            return V0;
        }
    }

    S0 = 0;
    80048B38	j      L48b5c [$80048b5c]
}

L48b48:	; 80048B48
A0 = S2;
A1 = 2;
A2 = 0;
system_check_entity_collisions;
S0 = V0;

L48b5c:	; 80048B5C
if (S0 != 0)
{
    80048B60	addu   a0, s0, zero
    A1 = 1; // priority
    80048B68	addiu  a2, zero, $0002
    80048B6C	jal    func384d0 [$800384d0]
    80048B70	addu   a3, zero, zero
}

80048B74	beq    s3, zero, L48d6c [$80048d6c]
80048B78	lui    v0, $8008
80048B7C	addu   s7, zero, zero
80048B80	lw     v0, $aecc(v0)
80048B84	lw     s6, $0014(s2)
80048B88	lw     s1, $16d8(v0)
80048B8C	lw     s5, $001c(s2)
80048B90	beq    s1, zero, L48c48 [$80048c48]
80048B94	addiu  s4, zero, $0003

loop48b98:	; 80048B98
80048B98	lw     s0, $0004(s1)
80048B9C	nop
80048BA0	lbu    v1, $0005(s0)
80048BA4	addiu  v0, zero, $0003
80048BA8	bne    v1, v0, L48c38 [$80048c38]
80048BAC	lui    v1, $8008
80048BB0	lbu    v0, $0006(s0)
80048BB4	lw     v1, $adf8(v1)
80048BB8	sll    v0, v0, $03
80048BBC	addu   v0, v0, v1
80048BC0	lhu    v0, $0000(v0)
80048BC4	nop
80048BC8	addu   v1, v1, v0
80048BCC	lhu    v0, $0000(v1)
80048BD0	nop
80048BD4	srl    a1, v0, $08
80048BD8	beq    a1, zero, L48c18 [$80048c18]
80048BDC	addiu  a0, v1, $0002

loop48be0:	; 80048BE0
80048BE0	lhu    v0, $0000(a0)
80048BE4	nop
80048BE8	beq    v0, s4, L48bfc [$80048bfc]
80048BEC	addiu  a0, a0, $0002
80048BF0	addiu  a1, a1, $ffff (=-$1)
80048BF4	bne    a1, zero, loop48be0 [$80048be0]
80048BF8	addiu  a0, a0, $0002

L48bfc:	; 80048BFC
80048BFC	beq    a1, zero, L48c18 [$80048c18]
80048C00	nop
80048C04	lhu    v0, $0000(a0)
80048C08	nop
80048C0C	addiu  v0, v0, $0002
80048C10	j      L48c1c [$80048c1c]
80048C14	addu   v1, v1, v0

L48c18:	; 80048C18
80048C18	addu   v1, zero, zero

L48c1c:	; 80048C1C
80048C1C	beq    v1, zero, L48c38 [$80048c38]
80048C20	addu   a0, s0, zero
80048C24	addu   a1, s6, zero
80048C28	jal    func53124 [$80053124]
80048C2C	addu   a2, s5, zero
if (V0 != 0)
{
    S7 = S0;
    80048B40	j      L48c48 [$80048c48]
}

L48c38:	; 80048C38
80048C38	lw     s1, $0000(s1)
80048C3C	nop
80048C40	bne    s1, zero, loop48b98 [$80048b98]
80048C44	nop

L48c48:	; 80048C48
80048C48	addu   s0, s7, zero
80048C4C	beq    s0, zero, L48c8c [$80048c8c]
80048C50	lui    v0, $0008
80048C54	bne    s3, v0, L48c74 [$80048c74]
80048C58	addu   a0, s0, zero
A1 = 1; // priority
80048C60	addiu  a2, zero, $0008
80048C64	jal    func384d0 [$800384d0]
80048C68	addu   a3, zero, zero
if (V0 != 0)
{
    return V0;
}
80048C70	addu   a0, s0, zero

L48c74:	; 80048C74
A1 = 1; // priority
80048C78	addiu  a2, zero, $0003
80048C7C	jal    func384d0 [$800384d0]
80048C80	addu   a3, zero, zero
80048C84	j      L48e3c [$80048e3c]
80048C88	addu   s0, zero, zero

L48c8c:	; 80048C8C
80048C8C	lui    v0, $8008
80048C90	addu   s5, zero, zero
80048C94	lw     v0, $aecc(v0)
80048C98	lw     s4, $0014(s2)
80048C9C	lw     s1, $16d8(v0)
80048CA0	lw     s2, $001c(s2)
80048CA4	beq    s1, zero, L48e38 [$80048e38]
80048CA8	addiu  s3, zero, $0002

loop48cac:	; 80048CAC
80048CAC	lw     s0, $0004(s1)
80048CB0	nop
80048CB4	lbu    v1, $0005(s0)
80048CB8	addiu  v0, zero, $0003
80048CBC	bne    v1, v0, L48d4c [$80048d4c]
80048CC0	lui    v1, $8008
80048CC4	lbu    v0, $0006(s0)
80048CC8	lw     v1, $adf8(v1)
80048CCC	sll    v0, v0, $03
80048CD0	addu   v0, v0, v1
80048CD4	lhu    v0, $0000(v0)
80048CD8	nop
80048CDC	addu   v1, v1, v0
80048CE0	lhu    v0, $0000(v1)
80048CE4	nop
80048CE8	srl    a1, v0, $08
80048CEC	beq    a1, zero, L48d2c [$80048d2c]
80048CF0	addiu  a0, v1, $0002

loop48cf4:	; 80048CF4
80048CF4	lhu    v0, $0000(a0)
80048CF8	nop
80048CFC	beq    v0, s3, L48d10 [$80048d10]
80048D00	addiu  a0, a0, $0002
80048D04	addiu  a1, a1, $ffff (=-$1)
80048D08	bne    a1, zero, loop48cf4 [$80048cf4]
80048D0C	addiu  a0, a0, $0002

L48d10:	; 80048D10
80048D10	beq    a1, zero, L48d2c [$80048d2c]
80048D14	nop
80048D18	lhu    v0, $0000(a0)
80048D1C	nop
80048D20	addiu  v0, v0, $0002
80048D24	j      L48d30 [$80048d30]
80048D28	addu   v1, v1, v0

L48d2c:	; 80048D2C
80048D2C	addu   v1, zero, zero

L48d30:	; 80048D30
80048D30	beq    v1, zero, L48d4c [$80048d4c]
80048D34	addu   a0, s0, zero
80048D38	addu   a1, s4, zero
80048D3C	jal    func53124 [$80053124]
80048D40	addu   a2, s2, zero
80048D44	bne    v0, zero, L48d64 [$80048d64]
80048D48	nop

L48d4c:	; 80048D4C
80048D4C	lw     s1, $0000(s1)
80048D50	nop
80048D54	bne    s1, zero, loop48cac [$80048cac]
80048D58	addu   s0, s5, zero
80048D5C	j      L48e3c [$80048e3c]
80048D60	nop

L48d64:	; 80048D64
80048D64	j      L48e38 [$80048e38]
80048D68	addu   s5, s0, zero

L48d6c:	; 80048D6C
80048D6C	addu   s5, zero, zero
80048D70	lw     v0, $aecc(v0)
80048D74	lw     s4, $0014(s2)
80048D78	lw     s1, $16d8(v0)
80048D7C	lw     s2, $001c(s2)
80048D80	beq    s1, zero, L48e38 [$80048e38]
80048D84	addiu  s3, zero, $0002

loop48d88:	; 80048D88
80048D88	lw     s0, $0004(s1)
80048D8C	nop
80048D90	lbu    v1, $0005(s0)
80048D94	addiu  v0, zero, $0003
80048D98	bne    v1, v0, L48e28 [$80048e28]
80048D9C	lui    v1, $8008
80048DA0	lbu    v0, $0006(s0)
80048DA4	lw     v1, $adf8(v1)
80048DA8	sll    v0, v0, $03
80048DAC	addu   v0, v0, v1
80048DB0	lhu    v0, $0000(v0)
80048DB4	nop
80048DB8	addu   v1, v1, v0
80048DBC	lhu    v0, $0000(v1)
80048DC0	nop
80048DC4	srl    a1, v0, $08
80048DC8	beq    a1, zero, L48e08 [$80048e08]
80048DCC	addiu  a0, v1, $0002

loop48dd0:	; 80048DD0
80048DD0	lhu    v0, $0000(a0)
80048DD4	nop
80048DD8	beq    v0, s3, L48dec [$80048dec]
80048DDC	addiu  a0, a0, $0002
80048DE0	addiu  a1, a1, $ffff (=-$1)
80048DE4	bne    a1, zero, loop48dd0 [$80048dd0]
80048DE8	addiu  a0, a0, $0002

L48dec:	; 80048DEC
80048DEC	beq    a1, zero, L48e08 [$80048e08]
80048DF0	nop
80048DF4	lhu    v0, $0000(a0)
80048DF8	nop
80048DFC	addiu  v0, v0, $0002
80048E00	j      L48e0c [$80048e0c]
80048E04	addu   v1, v1, v0

L48e08:	; 80048E08
80048E08	addu   v1, zero, zero

L48e0c:	; 80048E0C
80048E0C	beq    v1, zero, L48e28 [$80048e28]
80048E10	addu   a0, s0, zero
80048E14	addu   a1, s4, zero
80048E18	jal    func53124 [$80053124]
80048E1C	addu   a2, s2, zero
80048E20	bne    v0, zero, L48d64 [$80048d64]
80048E24	nop

L48e28:	; 80048E28
80048E28	lw     s1, $0000(s1)
80048E2C	nop
80048E30	bne    s1, zero, loop48d88 [$80048d88]
80048E34	nop

L48e38:	; 80048E38
80048E38	addu   s0, s5, zero

L48e3c:	; 80048E3C
if (S0 != 0)
{
    80048E40	addu   a0, s0, zero
    A1 = 1; // priority
    80048E48	addiu  a2, zero, $0002
    80048E4C	jal    func384d0 [$800384d0]
    80048E50	addu   a3, zero, zero
}
return V0;
////////////////////////////////



////////////////////////////////
// func4e8ec
return w[8007b97c] & 03ffffff;
////////////////////////////////
