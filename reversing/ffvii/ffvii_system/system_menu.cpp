////////////////////////////////
// func24a3c
S0 = 1;
[GP + b4] = w(1);

80024A60	sw     zero, $027c(gp)
80024A64	sw     zero, $01c8(gp)
80024A68	sw     zero, $0250(gp)

[GP + 8c] = w(0);
[GP + 90] = w(0);

80024A74	lui    at, $8006
80024A78	sb     zero, $2dfd(at)
80024A7C	bne    a0, zero, L24aa0 [$80024aa0]
80024A80	addu   a1, zero, zero
80024A84	addu   a0, zero, zero
80024A88	jal    func1f6e4 [$8001f6e4]
80024A8C	addu   a2, zero, zero
80024A90	lui    at, $8006
80024A94	sw     zero, $2fa0(at)
80024A98	j      L24ab0 [$80024ab0]
80024A9C	nop

L24aa0:	; 80024AA0
80024AA0	jal    func1c484 [$8001c484]
80024AA4	nop
80024AA8	lui    at, $8006
80024AAC	sw     s0, $2fa0(at)

L24ab0:	; 80024AB0
80024AB0	lui    s0, $800a
80024AB4	lbu    s0, $d2a4(s0)
80024AB8	nop
80024ABC	andi   v0, s0, $0004
80024AC0	beq    v0, zero, L24ad4 [$80024ad4]
80024AC4	ori    v0, zero, $0001
80024AC8	sb     v0, $02e0(gp)
80024ACC	j      L24adc [$80024adc]
80024AD0	addu   s0, zero, zero

L24ad4:	; 80024AD4
80024AD4	sb     zero, $02e0(gp)
80024AD8	addu   s0, zero, zero

L24adc:	; 80024ADC
80024ADC	ori    s1, zero, $00ff

loop24ae0:	; 80024AE0
80024AE0	andi   a0, s0, $ffff
80024AE4	lui    at, $800a
80024AE8	addiu  at, at, $cbdc (=-$3424)
80024AEC	addu   at, at, a0
80024AF0	lbu    v0, $0000(at)
80024AF4	nop
80024AF8	beq    v0, s1, L24b18 [$80024b18]
80024AFC	nop
80024B00	jal    system_init_player_weapon_stat [$80020058]
80024B04	nop
80024B08	jal    system_init_player_materia [$8001786c]
80024B0C	andi   a0, s0, $00ff
80024B10	jal    system_calculate_total_lure_gil_preemptive_value [$80017678]
80024B14	nop

L24b18:	; 80024B18
80024B18	addiu  s0, s0, $0001
80024B1C	andi   v0, s0, $ffff
80024B20	sltiu  v0, v0, $0003
80024B24	bne    v0, zero, loop24ae0 [$80024ae0]
80024B28	nop
80024B2C	lui    a0, $8007
80024B30	addiu  a0, a0, $06a4
80024B34	lui    a1, $8007
80024B38	addiu  a1, a1, $075c
80024B3C	jal    func21044 [$80021044]
80024B40	addu   s0, zero, zero
[GP + 164] = h(64);
[GP + 2b0] = h(-3);

80024B54	jal    func25cd4 [$80025cd4]
80024B58	addiu  a0, sp, $0020
80024B5C	lui    a0, $8007
80024B60	addiu  a0, a0, $56f8
80024B64	jal    func25c94 [$80025c94]
80024B68	addiu  s4, zero, $ffff (=-$1)
80024B6C	sw     zero, $027c(gp)
80024B70	jal    func2368c [$8002368c]
80024B74	nop

80024B80	addiu  s1, sp, $0720
80024B8C	sw     zero, $0214(gp)

L24b90:	; 80024B90
    80024B90	jal    func1cb48 [$8001cb48]
    80024B94	nop
    80024B98	lw     v0, $0214(gp)
    80024B9C	nop
    80024BA0	sll    a0, v0, $01
    80024BA4	addu   a0, a0, v0
    80024BA8	sll    a0, a0, $02
    80024BAC	addu   a0, a0, v0
    80024BB0	sll    a0, a0, $0a
    80024BB4	lui    v0, $8007
    80024BB8	addiu  v0, v0, $7f64
    80024BBC	jal    func269c0 [$800269c0]
    80024BC0	addu   a0, a0, v0
    80024BC4	lw     v0, $0214(gp)
    80024BC8	nop
    80024BCC	sll    a0, v0, $02
    80024BD0	addu   a0, a0, v0
    80024BD4	sll    a0, a0, $04
    80024BD8	lui    v0, $8007
    80024BDC	addiu  v0, v0, $9844 (=-$67bc)
    80024BE0	addu   a0, a0, v0
    80024BE4	sw     a0, $0160(gp)
    80024BE8	jal    func4418c [$8004418c]
    80024BEC	ori    a1, zero, $0014
    80024BF0	lw     a0, $0160(gp)
    80024BF4	jal    func26a00 [$80026a00]
    80024BF8	nop

    if (w[80062fa0] != 0)
    {
        if (w[GP + 27c] != S4)
        {
            if (S0 & 0010)
            {
                A0 = 28;
                A1 = ce;
                A2 = 80049320; // text "Tutorial"
                A3 = 4;
                func26f44; // text

                A0 = 80059320;
                80024C38	jal    func26b70 [$80026b70]

                [S1 + 0] = h(20);
                [S1 + 2] = h(c8);
                [S1 + 4] = h(V0 + 10);
                [S1 + 6] = h(18);

                A0 = S1;
                func1e040;
            }
        }
    }

    80024C64	jal    func1f710 [$8001f710]

    V0 = w[GP + b4];

    if (V0 == 2 || V0 == 4 || V0 == 5)
    {
        V0 = w[GP + 8c] * 4;
    }
    else
    {
        V0 = w[GP + 90] * 4;
    }

    V0 = 800493fc + V0;
    A9 = S0;
    80024CB4	jalr   v0 ra // call menu draw function, at least config here

D43A0280 // 0
800E1D80 // 1 item
90041D80 // 2 magic
2C6C1D80 // 3 materia
D00B1D80
7C161D80
C4001D80
2C041D80
0C081D80 // 8 config
940E1D80
B0061D80
50021D80
C4001D80
800E1D80
800E1D80
D00B1D80
800E1D80
800E1D80
800E1D80
800E1D80
800E1D80


    80024CBC	jal    func43dd8 [$80043dd8]
    80024CC0	addu   a0, zero, zero
    80024CC4	jal    func3cedc [$8003cedc]
    80024CC8	addu   a0, zero, zero
    80024CCC	lw     v0, $0214(gp)
    80024CD0	nop
    80024CD4	sll    a0, v0, $02
    80024CD8	addu   a0, a0, v0
    80024CDC	sll    a0, a0, $02
    80024CE0	lui    v0, $8007
    80024CE4	addiu  v0, v0, $075c
    80024CE8	jal    func444ac [$800444ac]
    80024CEC	addu   a0, a0, v0
    80024CF0	lw     v0, $0214(gp)
    80024CF4	nop
    80024CF8	sll    a0, v0, $01
    80024CFC	addu   a0, a0, v0
    80024D00	sll    a0, a0, $03
    80024D04	subu   a0, a0, v0
    80024D08	sll    a0, a0, $02
    80024D0C	lui    v0, $8007
    80024D10	addiu  v0, v0, $06a4
    80024D14	jal    func443b0 [$800443b0]
    80024D18	addu   a0, a0, v0
    80024D1C	lw     a0, $0160(gp)
    80024D20	jal    func4433c [$8004433c]
    80024D24	addiu  s0, s0, $0001
    80024D28	lw     v0, $0214(gp)
    80024D2C	lw     v1, $027c(gp)
    80024D30	xori   v0, v0, $0001
    80024D34	sw     v0, $0214(gp)
80024D38	bne    v1, s4, L24b90 [$80024b90]



80024D40	jal    func25c94 [$80025c94]
80024D44	addiu  a0, sp, $0020
80024D48	jal    func24a04 [$80024a04]
80024D4C	nop
80024D50	lui    at, $8006
80024D54	sw     zero, $2fa0(at)
80024D58	jal    func3cedc [$8003cedc]
80024D5C	ori    a0, zero, $0004
80024D60	addu   v0, zero, zero
////////////////////////////////



////////////////////////////////
80023AD4	lw     v0, $024c(gp)

80023B04	beq    v0, zero, L23b14 [$80023b14]
80023B08	sw     a0, $0478(sp)
80023B0C	jal    func26090 [$80026090]

L23b14:	; 80023B14
S1 = 8009c6e4 + 0bc0

[GP + 208] = h(hu[8009c6e4 + 0bc0]); // menu visibility mask
A1 = hu[8009c6e4 + 0bc2]; // menu locking mask

[GP + 20c] = h(A1);

if (bu[8009c6e4 + 0e13] & 1) // little cloud event?
{
    [GP + 20c] = h(A1 | 0041);
}

80023B70	jal    func23050 [$80023050]
80023B74	nop
80023B78	addu   v1, v0, zero
80023B7C	ori    v0, zero, $0001
80023B80	bne    v1, v0, L241d8 [$800241d8]
80023B84	nop
80023B88	lw     s0, $027c(gp)
80023B8C	nop
80023B90	bne    s0, v1, L241d8 [$800241d8]
80023B94	nop
80023B98	lw     v0, $0220(gp)
80023B9C	nop
80023BA0	sll    a0, v0, $03
80023BA4	addu   a0, a0, v0
80023BA8	sll    a0, a0, $01
80023BAC	lui    v0, $800a
80023BB0	addiu  v0, v0, $a0c8 (=-$5f38)
80023BB4	jal    func264a8 [$800264a8]
80023BB8	addu   a0, a0, v0
80023BBC	lw     v1, $0220(gp)
80023BC0	nop
80023BC4	beq    v1, s0, L23d50 [$80023d50]
80023BC8	slti   v0, v1, $0002
80023BCC	beq    v0, zero, L23be4 [$80023be4]
80023BD0	nop
80023BD4	beq    v1, zero, L23bf8 [$80023bf8]
80023BD8	nop
80023BDC	j      L241d8 [$800241d8]
80023BE0	nop

L23be4:	; 80023BE4
80023BE4	ori    v0, zero, $0002
80023BE8	beq    v1, v0, L23e20 [$80023e20]
80023BEC	nop
80023BF0	j      L241d8 [$800241d8]
80023BF4	nop

L23bf8:	; 80023BF8
80023BF8	lui    v0, $8006
80023BFC	lhu    v0, $2d7c(v0)
80023C00	nop
80023C04	andi   v0, v0, $0020
80023C08	beq    v0, zero, L23d18 [$80023d18]
80023C0C	nop
80023C10	lhu    v0, $0208(gp)
80023C14	lui    v1, $800a
80023C18	lb     v1, $a0d3(v1)
80023C1C	nop
80023C20	srav   v0, v1, v0
80023C24	andi   v0, v0, $0001
80023C28	beq    v0, zero, L23d18 [$80023d18]
80023C2C	nop
80023C30	lhu    v0, $020c(gp)
80023C34	nop
80023C38	srav   v0, v1, v0
80023C3C	andi   v0, v0, $0001
80023C40	bne    v0, zero, L23d18 [$80023d18]
80023C44	ori    v0, zero, $0005
80023C48	bne    v1, v0, L23c60 [$80023c60]
80023C4C	ori    v0, zero, $0002
80023C50	sw     v0, $0220(gp)
80023C54	sw     zero, $023c(gp)
80023C58	j      L241d8 [$800241d8]
80023C5C	nop

L23c60:	; 80023C60
80023C60	jal    func1fa28 [$8001fa28]
80023C64	ori    a0, zero, $0001
80023C68	lui    v0, $800a
80023C6C	lb     v0, $a0d3(v0)
80023C70	nop
80023C74	lui    at, $8005
80023C78	addiu  at, at, $945c (=-$6ba4)
80023C7C	addu   at, at, v0
80023C80	lbu    v1, $0000(at)
80023C84	nop
80023C88	beq    v1, s0, L23cac [$80023cac]
80023C8C	nop
80023C90	slti   v0, v1, $0002
80023C94	bne    v0, zero, L241d8 [$800241d8]
80023C98	ori    v0, zero, $0002
80023C9C	beq    v1, v0, L23d0c [$80023d0c]
80023CA0	nop
80023CA4	j      L241d8 [$800241d8]
80023CA8	nop

L23cac:	; 80023CAC
80023CAC	lui    at, $8005
80023CB0	addiu  at, at, $9450 (=-$6bb0)
80023CB4	addu   at, at, v0
80023CB8	lbu    a1, $0000(at)
80023CBC	jal    func2305c [$8002305c]
80023CC0	ori    a0, zero, $0002
80023CC4	lui    v0, $800a
80023CC8	lb     v0, $a0d3(v0)
80023CCC	nop
80023CD0	lui    at, $8005
80023CD4	addiu  at, at, $9450 (=-$6bb0)
80023CD8	addu   at, at, v0
80023CDC	lbu    a0, $0000(at)
80023CE0	jal    func2120c [$8002120c]
80023CE4	nop
80023CE8	lui    v1, $800a
80023CEC	lb     v1, $a0d3(v1)
80023CF0	ori    v0, zero, $0008
80023CF4	bne    v1, v0, L241d8 [$800241d8]
80023CF8	nop
80023CFC	jal    func1fa28 [$8001fa28]
80023D00	ori    a0, zero, $01c3
80023D04	j      L241d8 [$800241d8]
80023D08	nop

L23d0c:	; 80023D0C
80023D0C	sw     s0, $0220(gp)
80023D10	j      L241d8 [$800241d8]
80023D14	nop

L23d18:	; 80023D18
80023D18	lui    v0, $8006
80023D1C	lhu    v0, $2d7c(v0)
80023D20	nop
80023D24	andi   v0, v0, $0040
80023D28	beq    v0, zero, L241d8 [$800241d8]
80023D2C	nop
80023D30	jal    func1fa28 [$8001fa28]
80023D34	ori    a0, zero, $0004
[GP + 2b0] = h(3);

80023D40	ori    v0, zero, $0002
80023D44	sw     v0, $027c(gp)
80023D48	j      L241d8 [$800241d8]
80023D4C	nop

L23d50:	; 80023D50
80023D50	lui    v1, $8006
80023D54	lhu    v1, $2d7c(v1)
80023D58	nop
80023D5C	andi   v0, v1, $0020
80023D60	beq    v0, zero, L23e08 [$80023e08]
80023D64	andi   v0, v1, $0040
80023D68	lui    v0, $800a
80023D6C	lb     v0, $a0e5(v0)
80023D70	nop
80023D74	lui    at, $800a
80023D78	addiu  at, at, $cbdc (=-$3424)
80023D7C	addu   at, at, v0
80023D80	lbu    v1, $0000(at)
80023D84	ori    v0, zero, $00ff
80023D88	bne    v1, v0, L23da0 [$80023da0]
80023D8C	nop
80023D90	jal    func1fa28 [$8001fa28]
80023D94	ori    a0, zero, $0003
80023D98	j      L241d8 [$800241d8]
80023D9C	nop

L23da0:	; 80023DA0
80023DA0	jal    func1fa28 [$8001fa28]
80023DA4	ori    a0, zero, $0001
80023DA8	lui    v0, $800a
80023DAC	lb     v0, $a0d3(v0)
80023DB0	nop
80023DB4	lui    at, $8005
80023DB8	addiu  at, at, $9450 (=-$6bb0)
80023DBC	addu   at, at, v0
80023DC0	lbu    a1, $0000(at)
80023DC4	jal    func2305c [$8002305c]
80023DC8	ori    a0, zero, $0002
80023DCC	lui    v0, $800a
80023DD0	lb     v0, $a0d3(v0)
80023DD4	nop
80023DD8	lui    at, $8005
80023DDC	addiu  at, at, $9450 (=-$6bb0)
80023DE0	addu   at, at, v0
80023DE4	lbu    a0, $0000(at)
80023DE8	jal    func2120c [$8002120c]
80023DEC	nop
80023DF0	lui    v0, $800a
80023DF4	lb     v0, $a0e5(v0)
80023DF8	sw     zero, $0220(gp)
80023DFC	sw     v0, $0228(gp)
80023E00	j      L241d8 [$800241d8]
80023E04	nop

L23e08:	; 80023E08
80023E08	beq    v0, zero, L241d8 [$800241d8]
80023E0C	nop
80023E10	jal    func1fa28 [$8001fa28]
80023E14	ori    a0, zero, $0004
80023E18	j      L241d4 [$800241d4]
80023E1C	nop

L23e20:	; 80023E20
80023E20	lui    v1, $8006
80023E24	lhu    v1, $2d7c(v1)
80023E28	nop
80023E2C	andi   v0, v1, $0020
80023E30	beq    v0, zero, L241a8 [$800241a8]
80023E34	andi   v0, v1, $0040
80023E38	lw     v0, $023c(gp)
80023E3C	nop
80023E40	bne    v0, zero, L23e70 [$80023e70]
80023E44	nop
80023E48	jal    func1fa28 [$8001fa28]
80023E4C	ori    a0, zero, $0001
80023E50	lw     v0, $023c(gp)
80023E54	lui    v1, $800a
80023E58	lb     v1, $a0f7(v1)
80023E5C	addiu  v0, v0, $0001
80023E60	sw     v0, $023c(gp)
80023E64	sw     v1, $02d8(gp)
80023E68	j      L241d8 [$800241d8]
80023E6C	nop

L23e70:	; 80023E70
80023E70	lui    v0, $800a
80023E74	lb     v0, $a0f7(v0)
80023E78	lw     v1, $02d8(gp)
80023E7C	sw     zero, $023c(gp)
80023E80	bne    v1, v0, L23ef0 [$80023ef0]
80023E84	addu   v0, s1, v1
80023E88	lbu    v1, $f938(v0)
80023E8C	ori    v0, zero, $00ff
80023E90	beq    v1, v0, L241d8 [$800241d8]
80023E94	sll    v0, v1, $02
80023E98	lui    at, $8005
80023E9C	addiu  at, at, $91d0 (=-$6e30)
80023EA0	addu   at, at, v0
80023EA4	lw     v0, $0000(at)
80023EA8	nop
80023EAC	sll    v1, v0, $05
80023EB0	addu   v1, v1, v0
80023EB4	sll    v1, v1, $02
80023EB8	lui    at, $800a
80023EBC	addiu  at, at, $c758 (=-$38a8)
80023EC0	addu   at, at, v1
80023EC4	lbu    v0, $0000(at)
80023EC8	nop
80023ECC	xori   v0, v0, $0001
80023ED0	lui    at, $800a
80023ED4	addiu  at, at, $c758 (=-$38a8)
80023ED8	addu   at, at, v1
80023EDC	sb     v0, $0000(at)
80023EE0	jal    func1fa28 [$8001fa28]
80023EE4	ori    a0, zero, $0001
80023EE8	j      L241d8 [$800241d8]
80023EEC	nop

L23ef0:	; 80023EF0
80023EF0	jal    func1fa28 [$8001fa28]
80023EF4	ori    a0, zero, $0001
80023EF8	addiu  a0, s1, $f938 (=-$6c8)
80023EFC	lw     v0, $02d8(gp)
80023F00	lui    v1, $800a
80023F04	lb     v1, $a0f7(v1)
80023F08	addu   v0, v0, a0
80023F0C	lui    at, $800a
80023F10	addiu  at, at, $cbdc (=-$3424)
80023F14	addu   at, at, v1
80023F18	lbu    v1, $0000(at)
80023F1C	lbu    a0, $0000(v0)
80023F20	sb     v1, $0000(v0)
80023F24	lui    v0, $800a
80023F28	lb     v0, $a0f7(v0)
80023F2C	addiu  a3, sp, $0038
80023F30	lui    at, $800a
80023F34	addiu  at, at, $cbdc (=-$3424)
80023F38	addu   at, at, v0
80023F3C	sb     a0, $0000(at)
80023F40	lui    v1, $800a
80023F44	lb     v1, $a0f7(v1)
80023F48	lui    a0, $800a
80023F4C	addiu  a0, a0, $d84c (=-$27b4)
80023F50	sll    v0, v1, $04
80023F54	addu   v0, v0, v1
80023F58	sll    v0, v0, $06
80023F5C	addu   a2, v0, a0
80023F60	addiu  t0, a2, $0440

loop23f64:	; 80023F64
80023F64	lw     v0, $0000(a2)
80023F68	lw     v1, $0004(a2)
80023F6C	lw     a0, $0008(a2)
80023F70	lw     a1, $000c(a2)
80023F74	sw     v0, $0000(a3)
80023F78	sw     v1, $0004(a3)
80023F7C	sw     a0, $0008(a3)
80023F80	sw     a1, $000c(a3)
80023F84	addiu  a2, a2, $0010
80023F88	bne    a2, t0, loop23f64 [$80023f64]
80023F8C	addiu  a3, a3, $0010
80023F90	lui    v1, $800a
80023F94	lb     v1, $a0f7(v1)
80023F98	lui    a0, $800a
80023F9C	addiu  a0, a0, $d84c (=-$27b4)
80023FA0	sll    v0, v1, $04
80023FA4	addu   v0, v0, v1
80023FA8	sll    v0, v0, $06
80023FAC	lw     v1, $02d8(gp)
80023FB0	addu   a3, v0, a0
80023FB4	sll    v0, v1, $04
80023FB8	addu   v0, v0, v1
80023FBC	sll    v0, v0, $06
80023FC0	addu   a2, v0, a0
80023FC4	addiu  t0, a2, $0440

loop23fc8:	; 80023FC8
80023FC8	lw     v0, $0000(a2)
80023FCC	lw     v1, $0004(a2)
80023FD0	lw     a0, $0008(a2)
80023FD4	lw     a1, $000c(a2)
80023FD8	sw     v0, $0000(a3)
80023FDC	sw     v1, $0004(a3)
80023FE0	sw     a0, $0008(a3)
80023FE4	sw     a1, $000c(a3)
80023FE8	addiu  a2, a2, $0010
80023FEC	bne    a2, t0, loop23fc8 [$80023fc8]
80023FF0	addiu  a3, a3, $0010
80023FF4	addiu  a3, sp, $0038
80023FF8	addiu  t0, sp, $0478
80023FFC	lw     v0, $02d8(gp)
80024000	lui    a0, $800a
80024004	addiu  a0, a0, $d84c (=-$27b4)
80024008	sll    v1, v0, $04
8002400C	addu   v1, v1, v0
80024010	sll    v1, v1, $06
80024014	addu   a2, v1, a0

loop24018:	; 80024018
80024018	lw     v0, $0000(a3)
8002401C	lw     v1, $0004(a3)
80024020	lw     a0, $0008(a3)
80024024	lw     a1, $000c(a3)
80024028	sw     v0, $0000(a2)
8002402C	sw     v1, $0004(a2)
80024030	sw     a0, $0008(a2)
80024034	sw     a1, $000c(a2)
80024038	addiu  a3, a3, $0010
8002403C	bne    a3, t0, loop24018 [$80024018]
80024040	addiu  a2, a2, $0010
80024044	addiu  s2, sp, $0030
80024048	addu   a0, s2, zero
8002404C	ori    s3, zero, $0100
80024050	lui    s5, $800a
80024054	addiu  s5, s5, $a0f7 (=-$5f09)
80024058	ori    s0, zero, $0001
8002405C	sh     s3, $0030(sp)
80024060	sh     s3, $0034(sp)
80024064	lbu    v0, $0000(s5)
80024068	lw     a1, $02d8(gp)
8002406C	lui    s6, $8007
80024070	addiu  s6, s6, $56f8
80024074	sh     s0, $0036(sp)
80024078	sll    v0, v0, $18
8002407C	sra    v0, v0, $18
80024080	sll    a1, a1, $09
80024084	addu   a1, a1, s6
80024088	addiu  v0, v0, $01ed
8002408C	jal    func44064 [$80044064]
80024090	sh     v0, $0032(sp)
80024094	lb     a1, $0000(s5)
80024098	lw     v0, $02d8(gp)
8002409C	addu   a0, s2, zero
800240A0	sh     s3, $0030(sp)
800240A4	sh     s3, $0034(sp)
800240A8	sh     s0, $0036(sp)
800240AC	sll    a1, a1, $09
800240B0	addu   a1, a1, s6
800240B4	addiu  v0, v0, $01ed
800240B8	jal    func44064 [$80044064]
800240BC	sh     v0, $0032(sp)
800240C0	addu   a0, s2, zero
800240C4	ori    a1, zero, $0340
800240C8	ori    a2, zero, $0100
800240CC	ori    s4, zero, $03c0
800240D0	ori    s1, zero, $0018
800240D4	lw     v1, $02d8(gp)
800240D8	ori    s0, zero, $0030
800240DC	sh     s4, $0030(sp)
800240E0	sh     s1, $0034(sp)
800240E4	sh     s0, $0036(sp)
800240E8	sll    v0, v1, $01
800240EC	addu   v0, v0, v1
800240F0	sll    v0, v0, $04
800240F4	addiu  v0, v0, $0138
800240F8	jal    func440c8 [$800440c8]
800240FC	sh     v0, $0032(sp)
80024100	jal    func43dd8 [$80043dd8]
80024104	addu   a0, zero, zero
80024108	addu   a0, s2, zero
8002410C	lw     v0, $02d8(gp)
80024110	ori    a1, zero, $03c0
80024114	sh     s4, $0030(sp)
80024118	sh     s1, $0034(sp)
8002411C	sh     s0, $0036(sp)
80024120	lb     v1, $0000(s5)
80024124	sll    a2, v0, $01
80024128	addu   a2, a2, v0
8002412C	sll    a2, a2, $04
80024130	addiu  a2, a2, $0138
80024134	sll    v0, v1, $01
80024138	addu   v0, v0, v1
8002413C	sll    v0, v0, $04
80024140	addiu  v0, v0, $0138
80024144	jal    func440c8 [$800440c8]
80024148	sh     v0, $0032(sp)
8002414C	jal    func43dd8 [$80043dd8]
80024150	addu   a0, zero, zero
80024154	addu   a0, s2, zero
80024158	ori    a1, zero, $03c0
8002415C	lb     v1, $0000(s5)
80024160	ori    v0, zero, $0340
80024164	sh     v0, $0030(sp)
80024168	sh     s3, $0032(sp)
8002416C	sh     s1, $0034(sp)
80024170	sh     s0, $0036(sp)
80024174	sll    a2, v1, $01
80024178	addu   a2, a2, v1
8002417C	sll    a2, a2, $04
80024180	jal    func440c8 [$800440c8]
80024184	addiu  a2, a2, $0138
80024188	jal    func43dd8 [$80043dd8]
8002418C	addu   a0, zero, zero
80024190	jal    func25c94 [$80025c94]
80024194	addu   a0, s6, zero
80024198	jal    func43dd8 [$80043dd8]
8002419C	addu   a0, zero, zero
800241A0	j      L241d8 [$800241d8]
800241A4	nop

L241a8:	; 800241A8
800241A8	beq    v0, zero, L241d8 [$800241d8]
800241AC	nop
800241B0	jal    func1fa28 [$8001fa28]
800241B4	ori    a0, zero, $0004
800241B8	lw     v0, $023c(gp)
800241BC	nop
800241C0	beq    v0, zero, L241d4 [$800241d4]
800241C4	addiu  v0, v0, $ffff (=-$1)
800241C8	sw     v0, $023c(gp)
800241CC	j      L241d8 [$800241d8]
800241D0	nop

L241d4:	; 800241D4
800241D4	sw     zero, $0220(gp)

L241d8:	; 800241D8
800241D8	jal    func23050 [$80023050]

V1 = V0;

if (V1 == 1)
{
    if (w[GP + 27c] == 1)
    {
        V1 = w[GP + 220];
        if (V1 == 0)
        {
            A0 = 10b;
            A1 = b[8009a0d3] * c + d;
            func1eb2c; // cursor
        }
        else if (V1 == 1)
        {
            if (w[SP + 478] & 2)
            {
                A0 = 10b;
                A1 = b[8009a0d3] * c + d;
                func1eb2c; // cursor
            }

            V1 = w[GP + 220];
            A0 = 0;
            A1 = b[8009a0d3 + V1 * 24] * 3c + 2f;
            func1eb2c; // cursor
        }
        else if (V1 == 2)
        {
            if (w[SP + 478] & 2)
            {
                if (w[GP + 23c] != 0)
                {
                    A0 = -4;
                    A1 = w[GP + 2d8] * 3c + 2b;
                    func1eb2c; // cursor
                }

                A0 = 10b;
                A1 = b[8009a0d3] * c + d;
                func1eb2c; // cursor
            }

            V1 = w[GP + 220];
            A0 = 0;
            A1 = b[8009a0d3 + V1 * 24] * 3c + 2f;
            func1eb2c; // cursor
        }
    }
}

80024310	addiu  s2, sp, $0030
80024314	addu   a1, s2, zero
80024318	lw     v1, $0214(gp)
8002431C	ori    v0, zero, $0005
80024320	sh     v0, $0032(sp)
80024324	ori    v0, zero, $016c
80024328	sh     v0, $0034(sp)
8002432C	ori    v0, zero, $00db
80024330	sh     v0, $0036(sp)
80024334	lui    v0, $8007
80024338	addiu  v0, v0, $06a4
8002433C	sh     zero, $0030(sp)
80024340	sll    a0, v1, $01
80024344	addu   a0, a0, v1
80024348	sll    a0, a0, $03
8002434C	subu   a0, a0, v1
80024350	sll    a0, a0, $02
80024354	jal    func26a94 [$80026a94]
80024358	addu   a0, a0, v0

A0 = w[GP + 214];
func230c4; // draw menu



// block of fieldname
A0 = c0;
A1 = 11c - h[GP + 164] * 4.2f + 6;
A2 = 8009d5f0; // text field name
A3 = 7;
func26f44;

[SP + 28] = h(b8);
[SP + 2a] = h(11c - h[GP + 164] * 4.2f);
[SP + 2c] = h(b4);
[SP + 2e] = h(18);

A0 = SP + 28;
func1e040;



// block of time/gil
S3 = 1ce - h[GP + 164] * 9.2f;

A0 = S3 + 4;
A1 = aa;
A2 = 800492f0; // text "Time"
A3 = 7;
func26f44;

A0 = S3 + 5;
A1 = b8;
A2 = 800492fc; // text "Gil"
A3 = 7;
func26f44;

A0 = w[8009c6e4 + 0b80];
system_get_hours_from_seconds;

A0 = S3 + 1f;
A1 = ac;
A2 = V0;
A3 = 2;
A4 = 7;
func28e00;

A0 = S3 + 2c;
A1 = ad;
A2 = d5;
if (w[8009c6e4 + 0b88] < 7fff)
{
    A3 = 0;
}
else
{
    A3 = 7;
}
system_draw_single_menu_font_character;

A0 = w[8009d264];
system_get_minutes_from_seconds;

A0 = S3;
A1 = ac;
A2 = V0; // minutes
A3 = 2;
A4 = 7;
func29114;


A0 = S3 + 3e;
A1 = ad;
A2 = d5;
A3 = 7;
system_draw_single_menu_font_character;

A0 = w[8009d264];
system_get_seconds_from_seconds;

A0 = S3 + 43;
A1 = ac;
A2 = V0; // seconds
A3 = 2;
A4 = 7;
func29114;

A0 = S3 + b;
A1 = ba;
A2 = w[8009c6e4 + 0b7c]; // gil
A3 = a;
A4 = 7;
func28e00;

A0 = 0;
A1 = 1;
A2 = 7f;
A3 = SP + 30;
[SP + 30] = h(0);
[SP + 32] = h(0);
[SP + 34] = h(100);
[SP + 36] = h(100);
func26a34;


[SP + 28] = h(S3);
[SP + 2a] = h(a4);
[SP + 2c] = h(56);
[SP + 2e] = h(24);

A0 = SP + 28
func1e040;

80024568	lh     v0, $0164(gp)
8002456C	nop
80024570	sll    v1, v0, $01
80024574	addu   v1, v1, v0
80024578	sll    v1, v1, $03
8002457C	subu   v1, v1, v0
80024580	sll    v1, v1, $03
80024584	mult   v1, 66666667
8002458C	ori    t3, zero, $002e
80024590	ori    s6, zero, $0012
80024594	sw     t3, $0490(sp)
800245A0	sra    v1, v1, $1f
800245A4	mfhi   t3
800245A8	sra    v0, t3, $03
800245AC	subu   v0, v0, v1
800245B0	addiu  s3, v0, $ff48 (=-$b8)
800245B4	addiu  v0, v0, $0013
800245B8	sw     v0, $0488(sp)

FP = 1d;
y_pos = 1f;
S2 = 0;
L245bc:	; 800245BC
    V0 = bu[8009cdbc + S2];

    if (V0 != ff)
    {
        S5 = bu[800491d0 + V0 * 4];
        S1 = S5 * 84;

        A0 = S3 + 66;
        A1 = y_pos;
        A2 = S2;
        func20b68;

        A0 = S3 + ((bu[8009c6e4 + 0054 + S1 + 20] ^ 1) & 1) * 18 + 16; // char order
        A1 = FP;
        A2 = 30;
        A3 = 30;
        A4 = 0;
        A5 = S2 * 30 + 38;
        A6 = 30;
        A7 = 30;
        A8 = S2 + d;
        A9 = 0;
        80024668	jal    func1cf3c [$8001cf3c]


        80024670	addiu  a0, s3, $00cb
        80024674	ori    a3, zero, $0006
        80024678	lw     a1, $0490(sp)
        8002467C	lui    at, $800a
        80024680	addiu  at, at, $c759 (=-$38a7)
        80024684	addu   at, at, s1
        80024688	lbu    a2, $0000(at)
        8002468C	ori    v0, zero, $0080
        80024690	sw     v0, $0010(sp)
        80024694	ori    v0, zero, $0020
        80024698	sw     v0, $0014(sp)
        8002469C	jal    func285ac [$800285ac]
        800246A0	sw     v0, $0018(sp)
        800246A4	lui    at, $800a
        800246A8	addiu  at, at, $c747 (=-$38b9)
        800246AC	addu   at, at, s1
        800246B0	lbu    v0, $0000(at)
        800246B4	ori    t3, zero, $00ff
        800246B8	bne    v0, t3, L24710 [$80024710]
        800246BC	addu   s4, s6, zero
        800246C0	lw     t3, $0478(sp)
        800246C4	nop
        800246C8	sra    v0, t3, $01
        800246CC	andi   v0, v0, $0007
        800246D0	sll    v1, v0, $01
        800246D4	addu   v1, v1, v0
        800246D8	lui    at, $8005
        800246DC	addiu  at, at, $948c (=-$6b74)
        800246E0	addu   at, at, v1
        800246E4	lbu    t2, $0000(at)
        800246E8	lui    at, $8005
        800246EC	addiu  at, at, $948d (=-$6b73)
        800246F0	addu   at, at, v1
        800246F4	lbu    t1, $0000(at)
        800246F8	lui    at, $8005
        800246FC	addiu  at, at, $948e (=-$6b72)
        80024700	addu   at, at, v1
        80024704	lbu    t0, $0000(at)
        80024708	j      L24784 [$80024784]
        8002470C	sll    v0, s5, $05

        L24710:	; 80024710
        80024710	lui    at, $800a
        80024714	addiu  at, at, $c757 (=-$38a9)
        80024718	addu   at, at, s1
        8002471C	lbu    v1, $0000(at)
        80024720	nop
        80024724	andi   v0, v1, $0010
        80024728	beq    v0, zero, L24750 [$80024750]
        8002472C	andi   v0, v1, $0020
        80024730	lui    t2, $8005
        80024734	lbu    t2, $948c(t2)
        80024738	lui    t1, $8005
        8002473C	lbu    t1, $948d(t1)
        80024740	lui    t0, $8005
        80024744	lbu    t0, $948e(t0)
        80024748	j      L24784 [$80024784]
        8002474C	sll    v0, s5, $05

        L24750:	; 80024750
        80024750	beq    v0, zero, L24778 [$80024778]
        80024754	ori    t2, zero, $0080
        80024758	lui    t2, $8005
        8002475C	lbu    t2, $9492(t2)
        80024760	lui    t1, $8005
        80024764	lbu    t1, $9493(t1)
        80024768	lui    t0, $8005
        8002476C	lbu    t0, $9494(t0)
        80024770	j      L24784 [$80024784]
        80024774	sll    v0, s5, $05

        L24778:	; 80024778
        80024778	ori    t1, zero, $0020
        8002477C	ori    t0, zero, $0050
        80024780	sll    v0, s5, $05

        L24784:	; 80024784
        80024784	addu   v0, v0, s5
        80024788	sll    v0, v0, $02
        V1 = bu[8009c747 + V0];

        800247A0	sll    v0, v1, $04
        800247A4	subu   v0, v0, v1
        800247A8	sll    v0, v0, $02
        800247AC	addu   v0, v0, v1
        800247B0	bgez   v0, L247bc [$800247bc]
        800247B4	addiu  a1, s4, $0031
        800247B8	addiu  v0, v0, $00ff

        L247bc:	; 800247BC
        800247BC	sra    a2, v0, $08
        800247C0	lw     a0, $0488(sp)
        800247C4	ori    a3, zero, $0006
        800247C8	sw     t2, $0010(sp)
        800247CC	sw     t1, $0014(sp)
        800247D0	jal    func285ac [$800285ac]
        800247D4	sw     t0, $0018(sp)
        800247D8	addiu  s0, s3, $00ca
        800247E4	addu   a0, s0, zero
        800247E8	addiu  a1, s4, $001b
        800247F4	ori    a2, zero, $0088
        800247F8	ori    a3, zero, $0008
        800247FC	ori    t3, zero, $0040
        80024800	sw     t3, $0010(sp)
        80024804	ori    t3, zero, $0008
        80024808	sw     t3, $0014(sp)
        8002480C	ori    t3, zero, $0007
        80024810	sw     t3, $0018(sp)
        80024814	jal    func28ca0 [$80028ca0]
        80024818	sw     zero, $001c(sp)
        8002481C	addu   a0, s0, zero
        80024820	addiu  a1, s4, $0030
        8002482C	ori    a2, zero, $0088
        80024830	ori    a3, zero, $0008
        80024834	ori    t3, zero, $0040
        80024838	sw     t3, $0010(sp)
        8002483C	ori    t3, zero, $0008
        80024840	sw     t3, $0014(sp)
        80024844	ori    t3, zero, $0007
        80024848	sw     t3, $0018(sp)
        8002484C	jal    func28ca0 [$80028ca0]
        80024850	sw     zero, $001c(sp)
        80024854	addiu  a0, s3, $00fa
        80024858	lui    t3, $8005
        8002485C	addiu  t3, t3, $91d0 (=-$6e30)
        80024860	lui    at, $800a
        80024864	addiu  at, at, $cbdc (=-$3424)
        80024868	addu   at, at, s2
        8002486C	lbu    v0, $0000(at)
        80024870	addiu  a1, s4, $0027
        80024874	sll    v0, v0, $02
        80024878	addu   v0, v0, t3
        8002487C	lw     v1, $0000(v0)

        A2 = bu[8009c6e4 + 0054 + V1 * 84 + e]; // current limit level
        A3 = 1;
        A4 = 7;
        func28e00;




        800248AC	addu   a0, zero, zero
        800248B0	ori    a1, zero, $0001
        800248B4	ori    a2, zero, $003f
        800248B8	addiu  a3, sp, $0030
        800248BC	ori    v0, zero, $0100
        800248C0	sh     zero, $0030(sp)
        800248C4	sh     zero, $0032(sp)
        800248C8	sh     v0, $0034(sp)
        800248D0	sh     v0, $0036(sp)
        800248CC	jal    func26a34 [$80026a34]


        S1 = S3 + ba;
        A0 = S1;
        A1 = S4 + 10;
        A2 = 80049308; // text "next level"
        A3 = 7;
        func26f44;

        A0 = S1;
        A1 = S4 + 25;
        A2 = 80049314; // text "Limit level"
        A3 = 7;
        func26f44;
    }

    80024908	addiu  fp, fp, $003c

    y_pos = y_pos + 3c;

    80024910	addiu  s6, s6, $003c
    80024914	addiu  s2, s2, $0001
    80024918	lw     t3, $0490(sp)
    8002491C	slti   v0, s2, $0003
    80024920	addiu  t3, t3, $003c
    80024928	sw     t3, $0490(sp)
80024924	bne    v0, zero, L245bc [$800245bc]

[SP + 28] = h(S3);
[SP + 2a] = h(11);
[SP + 2c] = h(12c);
[SP + 2e] = h(be);

A0 = SP + 28;
func1e040;

80024950	lw     v0, $027c(gp)
80024954	nop
80024958	beq    v0, zero, L24970 [$80024970]
8002495C	ori    s0, zero, $0002
80024960	beq    v0, s0, L249a4 [$800249a4]
80024964	nop
80024968	j      L249d0 [$800249d0]
8002496C	nop

L24970:	; 80024970
V0 = h[GP + 164];
V1 = h[GP + 2b0];
[GP + 164] = h(V0 + V1);

8002498C	slti   v0, v0, $0014
80024990	beq    v0, zero, L249d0 [$800249d0]
80024994	ori    v0, zero, $0014
80024998	sh     v0, $0164(gp)
8002499C	j      L249cc [$800249cc]
800249A0	ori    v0, zero, $0001

L249a4:	; 800249A4
800249A4	lhu    v0, $0164(gp)
800249A8	lhu    v1, $02b0(gp)
800249AC	nop
800249B0	addu   v0, v0, v1
800249B4	sh     v0, $0164(gp)
800249B8	sll    v0, v0, $10
800249BC	sra    v0, v0, $10
800249C0	slti   v0, v0, $0065
800249C4	bne    v0, zero, L249d0 [$800249d0]
800249C8	addiu  v0, zero, $ffff (=-$1)

L249cc:	; 800249CC
800249CC	sw     v0, $027c(gp)

L249d0:	; 800249D0
////////////////////////////////



////////////////////////////////
// system_get_hours_from_seconds
if (A0 > 57e3f)
{
    A0 = 57e3f;
}

return (A0 / w[80049474]) * a + (A0 % w[80049474]) / w[80049478];
////////////////////////////////



////////////////////////////////
// system_get_minutes_from_seconds
if (A0 > 57e3f)
{
    A0 = 57e3f;
}

A0 = A0 % w[80049474];
A0 = A0 % w[80049478];

return (A0 / w[8004947c]) * a + (A0 % w[8004947c]) / w[80049480];
////////////////////////////////



////////////////////////////////
// system_get_seconds_from_seconds
if (A0 > 57e3f)
{
    A0 = 57e3f;
}

A0 = A0 % w[80049474];
A0 = A0 % w[80049478];
A0 = A0 % w[8004947c];
A0 = A0 % w[80049480];

return (A0 / w[80049484]) * a + (A0 % w[80049484]) / w[80049488];
////////////////////////////////



////////////////////////////////
// func230c4
800230CC	addu   s3, a0, zero
800230E0	jal    func34b44 [$80034b44]

800230E8	sll    a0, s3, $01
800230EC	addu   a0, a0, s3
800230F0	sll    a0, a0, $03
800230F4	subu   a0, a0, s3
800230F8	sll    a0, a0, $02
800230FC	lui    v1, $8007
80023100	addiu  v1, v1, $06a4
80023104	addu   a0, a0, v1
80023108	addiu  a1, sp, $0018
8002310C	ori    v1, zero, $0005
80023110	sh     v1, $001a(sp)
80023114	ori    v1, zero, $016c
80023118	sh     v1, $001c(sp)
8002311C	ori    v1, zero, $00db
80023120	addu   s0, v0, zero
80023124	sh     zero, $0018(sp)
80023128	jal    func26a94 [$80026a94]
8002312C	sh     v1, $001e(sp)
80023130	lw     v1, $00b4(gp)
80023134	nop
80023138	sltiu  v0, v1, $0007
S4 = 0;
8002313C	beq    v0, zero, L234c8 [$800234c8]

80023144	sll    v0, v1, $02
80023148	lui    at, $8001
8002314C	addiu  at, at, $0344
80023150	addu   at, at, v0
80023154	lw     v0, $0000(at)
80023158	nop
8002315C	jr     v0 
80023160	nop

80023164	lw     v0, $01dc(gp)
80023168	nop
8002316C	beq    v0, zero, L23180 [$80023180]
80023170	addiu  v0, v0, $ffff (=-$1)
80023174	sw     v0, $01dc(gp)
80023178	j      L231b8 [$800231b8]
8002317C	nop

L23180:	; 80023180
80023180	bne    s0, zero, L231b8 [$800231b8]
80023184	nop
80023188	lw     v0, $0090(gp)
8002318C	nop
80023190	sll    v0, v0, $02
80023194	lui    at, $8005
80023198	addiu  at, at, $93a8 (=-$6c58)
8002319C	addu   at, at, v0
800231A0	lw     v0, $0000(at)
800231A4	nop
800231A8	jalr   v0 ra
800231AC	addu   a0, zero, zero
800231B0	ori    v0, zero, $0003
800231B4	sw     v0, $00b4(gp)

L231b8:	; 800231B8
800231B8	lw     v1, $01dc(gp)
800231BC	nop
800231C0	sll    v0, v1, $01
800231C4	addu   v0, v0, v1
800231C8	lw     v1, $0250(gp)
800231CC	sll    v0, v0, $02
800231D0	mult   v1, v0
800231D4	mflo   a1
800231D8	bgez   a1, L231e4 [$800231e4]
800231DC	nop
800231E0	addiu  a1, a1, $000f

L231e4:	; 800231E4
800231E4	sra    a1, a1, $04
A0 = 126;
A1 = A1 + b;
A2 = 80049248 + V1 * c; // text "Item"
A3 = 7;
func26f44;

80023210	lw     v1, $01dc(gp)
80023214	nop
80023218	sll    v0, v1, $03
8002321C	subu   v0, v0, v1
80023220	sll    v0, v0, $02
80023224	subu   v0, v0, v1
80023228	sll    v0, v0, $02
8002322C	bgez   v0, L23238 [$80023238]
80023230	nop
80023234	addiu  v0, v0, $000f

L23238:	; 80023238
80023238	sra    v0, v0, $04
8002323C	addiu  v0, v0, $0018
80023240	sw     v0, $00ac(gp)
80023244	j      L234c8 [$800234c8]
80023248	nop
8002324C	lw     v0, $01dc(gp)
80023250	nop
80023254	beq    v0, zero, L23268 [$80023268]
80023258	addiu  v0, v0, $ffff (=-$1)
8002325C	sw     v0, $01dc(gp)
80023260	j      L233d4 [$800233d4]

L23268:	; 80023268
80023268	lw     v0, $0090(gp)
8002326C	nop
80023270	sll    v0, v0, $02
80023274	lui    at, $8005
80023278	addiu  at, at, $93a8 (=-$6c58)
8002327C	addu   at, at, v0
80023280	lw     v1, $0000(at)
80023284	ori    v0, zero, $0003
80023288	sw     v0, $00b4(gp)
8002328C	jalr   v1 ra
80023290	nop
80023294	j      L233d4 [$800233d4]

8002329C	lw     v1, $01dc(gp)
800232A0	nop
800232A4	slti   v0, v1, $000f
800232A8	beq    v0, zero, L232bc [$800232bc]
800232AC	addiu  v0, v1, $0001
800232B0	sw     v0, $01dc(gp)
800232B4	j      L232c4 [$800232c4]
800232B8	ori    a0, zero, $0126

L232bc:	; 800232BC
800232BC	sw     zero, $00b4(gp)
800232C0	ori    a0, zero, $0126

L232c4:	; 800232C4

800232CC	lw     v1, $0250(gp)
800232D0	ori    v0, zero, $0018
800232D4	sw     v0, $00ac(gp)

A1 = b;
A2 = 80049248 + V1 * c; // text "Item"
A3 = 7;
func26f44;

800232F4	j      L234c8 [$800234c8]
800232F8	nop
800232FC	lw     v1, $027c(gp)
80023300	ori    v0, zero, $0084
80023304	sw     v0, $00ac(gp)

if (V1 != 1)
{
    S4 = h[GP + 164] * 5 - 64;
}

S0 = 0;
loop23334:	; 80023334
    if ((hu[GP + 208] >> S0) & 1) // visibility mask
    {
        A0 = 126;
        A1 = S4 + S0 * c + b;
        A2 = 80049248 + S0 * c;
        if ((hu[GP + 20c] >> S0) & 1)
        {
            A3 = 0;
        }
        else
        {
            A3 = 7;
        }
        func26f44;
    }

    S0 = S0 + 1;
    V0 = S0 < a;
8002337C	bne    v0, zero, loop23334 [$80023334]

80023384	j      L234c8 [$800234c8]
80023388	nop
8002338C	lw     v0, $01dc(gp)
80023390	nop
80023394	beq    v0, zero, L233c8 [$800233c8]
80023398	addiu  v0, v0, $ffff (=-$1)
8002339C	sw     v0, $01dc(gp)
800233A0	bne    v0, zero, L233d4 [$800233d4]

800233A8	lw     v1, $027c(gp)
800233AC	ori    v0, zero, $0002
800233B0	bne    v1, v0, L233d8 [$800233d8]

800233B8	addiu  v0, zero, $ffff (=-$1)
800233BC	sw     v0, $027c(gp)
800233C0	j      L233cc [$800233cc]
800233C4	ori    v0, zero, $0001

L233c8:	; 800233C8
800233C8	ori    v0, zero, $0006

L233cc:	; 800233CC
800233CC	sw     v0, $00b4(gp)

L233d4:	; 800233D4
800233D0	ori    a0, zero, $0126

L233d8:	; 800233D8
800233D8	lw     v0, $01c8(gp)

A1 = b;
A2 = 90049248 + V0 * c;
A3 = 7;
func26f44;

800233FC	ori    v0, zero, $0018
80023400	sw     v0, $00ac(gp)
80023404	j      L234c8 [$800234c8]
80023408	nop
8002340C	lw     v1, $01dc(gp)
80023410	nop
80023414	slti   v0, v1, $000f
80023418	beq    v0, zero, L2342c [$8002342c]
8002341C	addiu  v0, v1, $0001
80023420	sw     v0, $01dc(gp)
80023424	j      L23434 [$80023434]
80023428	nop

L2342c:	; 8002342C
8002342C	ori    v0, zero, $0001
80023430	sw     v0, $00b4(gp)

L23434:	; 80023434
80023434	lw     v1, $0188(gp)
80023438	nop
8002343C	sll    v0, v1, $01
80023440	addu   v0, v0, v1
80023444	lw     v1, $01c8(gp)
80023448	sll    v0, v0, $02
8002344C	mult   v1, v0
80023450	mflo   a1
80023454	bgez   a1, L23460 [$80023460]
80023458	nop
8002345C	addiu  a1, a1, $000f

L23460:	; 80023460
80023460	sra    a1, a1, $04
80023464	ori    a0, zero, $0126
80023468	addiu  a1, a1, $000b
8002346C	sll    a2, v1, $01
80023470	addu   a2, a2, v1
80023474	sll    a2, a2, $02
80023478	lui    v0, $8005
8002347C	addiu  v0, v0, $9248 (=-$6db8)
80023480	addu   a2, a2, v0
80023484	jal    func26f44 [$80026f44]
80023488	ori    a3, zero, $0007
8002348C	lw     v1, $0188(gp)
80023490	nop
80023494	sll    v0, v1, $03
80023498	subu   v0, v0, v1
8002349C	sll    v0, v0, $02
800234A0	subu   v0, v0, v1
800234A4	sll    v0, v0, $02
800234A8	bgez   v0, L234b4 [$800234b4]
800234AC	nop
800234B0	addiu  v0, v0, $000f

L234b4:	; 800234B4
800234B4	sra    v0, v0, $04
800234B8	addiu  v0, v0, $0018
800234BC	sw     v0, $00ac(gp)
800234C0	addiu  v0, v1, $0001
800234C4	sw     v0, $0188(gp)

L234c8:	; 800234C8
800234C8	lw     v1, $027c(gp)
800234CC	ori    v0, zero, $0001
800234D0	bne    v1, v0, L23528 [$80023528]
800234D4	addiu  s0, sp, $0020
800234D8	sll    a0, s3, $01
800234DC	addu   a0, a0, s3
800234E0	sll    a0, a0, $03
800234E4	subu   a0, a0, s3
800234E8	sll    a0, a0, $02
800234EC	lui    v0, $8007
800234F0	addiu  v0, v0, $06a4
800234F4	addu   a0, a0, v0
800234F8	addiu  a1, sp, $0018
800234FC	ori    v0, zero, $011a
80023500	sh     v0, $0018(sp)
80023504	addiu  v0, s4, $0008
80023508	sh     v0, $001a(sp)
8002350C	lw     v0, $00ac(gp)
80023510	ori    v1, zero, $0056
80023514	sh     v1, $001c(sp)
80023518	addiu  v0, v0, $fffa (=-$6)
8002351C	jal    func26a94 [$80026a94]
80023520	sh     v0, $001e(sp)
80023524	addiu  s0, sp, $0020

L23528:	; 80023528
[S0 + 0] = h(116);
[S0 + 2] = h(S4 + 5);
[S0 + 4] = h(56);
[S0 + 6] = h(w[GP + ac]);

A0 = S0;
func1e040;

8002354C	lw     v0, $00b4(gp)
80023550	nop
80023554	sltiu  v0, v0, $0002
80023558	bne    v0, zero, L235f8 [$800235f8]
8002355C	ori    s0, zero, $00ff
80023560	lui    s1, $8007
80023564	addiu  s1, s1, $96fc (=-$6904)
80023568	lw     a0, $0214(gp)
8002356C	lw     v0, $01dc(gp)
80023570	sll    a0, a0, $04
80023574	addu   a0, a0, s1
80023578	sll    v0, v0, $04
8002357C	jal    func469b0 [$800469b0]
80023580	subu   s0, s0, v0
80023584	lw     a0, $0214(gp)
80023588	ori    a1, zero, $0001
8002358C	sll    a0, a0, $04
80023590	jal    system_change_semi_transparency_in_packet [$80046848]
80023594	addu   a0, a0, s1
80023598	lw     v0, $0214(gp)
8002359C	ori    v1, zero, $0180
800235A0	sll    v0, v0, $04
800235A4	addu   v0, v0, s1
800235A8	sh     v1, $000c(v0)
800235AC	sb     s0, $0004(v0)
800235B0	lw     v1, $0214(gp)
800235B4	ori    a0, zero, $00e0
800235B8	sh     zero, $0008(v0)
800235BC	sh     zero, $000a(v0)
800235C0	sh     a0, $000e(v0)
800235C4	sll    v1, v1, $04
800235C8	addu   v1, v1, s1
800235CC	sb     s0, $0005(v1)
800235D0	lw     v0, $0214(gp)
800235D4	nop
800235D8	sll    v0, v0, $04
800235DC	addu   v0, v0, s1
800235E0	sb     s0, $0006(v0)
800235E4	lw     a1, $0214(gp)
800235E8	lw     a0, $0160(gp)
800235EC	sll    a1, a1, $04
800235F0	jal    system_add_render_packet_to_queue [$80046794]
800235F4	addu   a1, a1, s1

L235f8:	; 800235F8
800235F8	addu   a0, zero, zero
800235FC	ori    a1, zero, $0001
80023600	ori    a2, zero, $005f
80023604	addiu  a3, sp, $0018
80023608	ori    v0, zero, $00ff
8002360C	sh     zero, $0018(sp)
80023610	sh     zero, $001a(sp)
80023614	sh     v0, $001c(sp)
80023618	jal    func26a34 [$80026a34]
8002361C	sh     v0, $001e(sp)
80023620	addiu  a1, sp, $0018
80023624	lw     v1, $0214(gp)
80023628	ori    v0, zero, $0005
8002362C	sh     v0, $001a(sp)
80023630	ori    v0, zero, $016c
80023634	sh     v0, $001c(sp)
80023638	ori    v0, zero, $00db
8002363C	sh     v0, $001e(sp)
80023640	lui    v0, $8007
80023644	addiu  v0, v0, $06a4
80023648	sh     zero, $0018(sp)
8002364C	sll    a0, v1, $01
80023650	addu   a0, a0, v1
80023654	sll    a0, a0, $03
80023658	subu   a0, a0, v1
8002365C	sll    a0, a0, $02
80023660	jal    func26a94 [$80026a94]
80023664	addu   a0, a0, v0
////////////////////////////////



////////////////////////////////
// func20b68
S7 = A0;
S6 = A1;
FP = A2;

V0 = bu[8009cbdc + FP];
character_data = w[800491d0 + V0 * 4];



[SP + 28] = h(S7 + 12);
[SP + 2a] = h(S6 + 1f);
[SP + 2c] = h(3c);
[SP + 2e] = h(1);
[SP + 30] = h(hu[8009d85c + FP * 440]);
[SP + 32] = h(hu[8009d85e + FP * 440]);
[SP + 34] = h(0);
[SP + 36] = h(hu[8009d85c + FP * 440]);
[SP + 38] = b(0);
[SP + 39] = b(80);
[SP + 3a] = b(ff);

A0 = SP + 28;
80020C54	jal    func27408 [$80027408]



[SP + 28] = h(S7 + 12);
[SP + 2a] = h(S6 + 29);
[SP + 2c] = h(3c);
[SP + 2e] = h(1);
[SP + 30] = h(hu[8009d860 + FP * 440]);
[SP + 32] = h(hu[8009d862 + FP * 440])
[SP + 34] = h(0);
[SP + 36] = h(hu[8009d860 + FP * 440]);
[SP + 38] = b(0);
[SP + 39] = b(ff);
[SP + 3a] = b(80);
A0 = SP + 28;
80020CC8	jal    func27408 [$80027408]



V1 = h[8009d85c + FP * 440];
V0 = h[8009d85e + FP * 440];
80020CF8	sltiu  s2, v1, $0001

80020D00	sra    v0, v0, $02
80020D04	slt    v0, v0, v1
80020D0C	ori    s3, zero, $0006
80020D08	beq    v0, zero, L20d14 [$80020d14]

80020D10	ori    s3, zero, $0007

L20d14:	; 80020D14
V0 = h[8009d862 + FP * 440];
V1 = h[8009d860 + FP * 440];

80020D44	sra    v0, v0, $02
80020D48	slt    v0, v0, v1
80020D50	ori    s4, zero, $0006
if (V0 != 0)
{
    S4 = 7;
}

T0 = character_data;



if (bu[8009c757 + character_data * 84] & 10)
{
    A0 = S7 + 24;
    A1 = S6 + b;
    A2 = 80049350; // text "Sadness"
    A3 = 3;
    func26f44;
}



if (bu[8009c757 + character_data * 84] & 20)
{
    A0 = S7 + 24;
    A1 = S6 + b;
    A2 = 80049344; // text "Fury"
    A3 = 3;
    func26f44;
}



A0 = S7;
A1 = S6;
A2 = 8009c748 + character_data * 84; // name
if (S2 != 0)
{
    A3 = 2;
}
else
{
    A3 = 7;
}
func26f44;



A0 = S7;
S0 = S6 + d;
A1 = S0;
A2 = 800493a0; // LV
A3 = 5;
system_draw_menu_8width_font;



A0 = S7 + 12;
A1 = S0;
A2 = bu[8009c6e4 + 0054 + character_data * 84 + 1]; // level value
A3 = 2;
if (S2 != 0)
{
    A4 = 2;
}
else
{
    A4 = 7;
}
func28e00;



A0 = S7;
A1 = S6 + 18;
A2 = 80049390; // HP
A3 = 5;
system_draw_menu_8width_font;


A0 = S7 + 12;
A1 = S6 + 17;
A2 = h[8009d85c + FP * 440];
if (S2 == 0)
{
    A4 = S3;
}
else
{
    A4 = 2;
}

A3 = 4;
func28e00;

A0 = S7 + 32;
A1 = S6 + 17;
A2 = h[8009d85e + FP * 440];
A3 = 4;
if (S2 != 0)
{
    A4 = 2;
}
else
{
    A4 = 7;
}
func28e00;


A0 = S7;
A1 = S6 + 22;
A2 = 80049398; // MP
A3 = 5;
system_draw_menu_8width_font;



A0 = S7 + 12;
A1 = S6 + 21;
A2 = h[8009d860 + FP * 440];
A3 = 4;
if (S2 == 0)
{
    A4 = S4;
}
else
{
    A4 = 2;
}
func28e00;



A0 = S7 + 32;
A1 = S6 + 21;
A2 = h[8009d862 + FP * 440];
A3 = 4;
if (S2 != 0)
{
    A4 = 2;
}
else
{
    A4 = 7;
}
func28e00;



A0 = S7 + 2e;
A1 = S6 + 21;
A2 = d8;
A3 = 0;
A4 = 4;
A5 = 8;
A6 = 1;
A7 = 0;
80020FB4	jal    func28ca0 [$80028ca0]

A0 = S7 + 2e;
A1 = S6 + 17;
A2 = d8;
A3 = 0;
A4 = 4;
A5 = 8;
A6 = 1;
A7 = 0;
80020FE0	jal    func28ca0 [$80028ca0]



80020FE8	addu   a0, zero, zero
80020FEC	ori    a1, zero, $0001
80020FF0	ori    a2, zero, $007f
80020FF4	addiu  a3, sp, $0020
80020FF8	ori    v0, zero, $0100
80020FFC	sh     zero, $0020(sp)
80021000	sh     zero, $0022(sp)
80021004	sh     v0, $0024(sp)
8002100C	sh     v0, $0026(sp)
80021008	jal    func26a34 [$80026a34]
////////////////////////////////



////////////////////////////////
// func27408
S1 = A0;
// +0 - x
// +2 - y
// +4 - width
// +6 - height
// +8 - current
// +a - max
// +c - 0
// +e - current
// +10 - R
// +11 - G
// +12 - B

A0 = h[S1 + a];
if (A0 == 0)
{
    return;
}

A1 = (h[S1 + 4] * h[S1 + e]) / A0;
width = (h[S1 + 4] * h[S1 + 8]) / A0;

S4 = hu[S1 + 0];
S5 = hu[S1 + 2];
height = hu[S1 + 6];

800274D0	addu   fp, v1, zero
800274D4	lui    a0, $8006
800274D8	lw     a0, $2f24(a0)
S7 = A1;

800274DC	jal    func46910 [$80046910]

packet = w[80062f24];

[packet + 8] = h(S4);
[packet + a] = h(S5);
[packet + 10] = h(S4 + width);
[packet + 12] = h(S5);
[packet + 18] = h(S4);
[packet + 1a] = h(S5 + height);
[packet + 20] = h(S4 + width));
[packet + 22] = h(S5 + height);

80027564	lbu    s0, $0010(s1)
80027570	lbu    s2, $0011(s1)
80027574	lbu    s3, $0012(s1)

[packet + 4] = b(S0);
[packet + 5] = b(S2);
[packet + 6] = b(S3);
[packet + c] = b(c8)
[packet + d] = b(c8);
[packet + e] = b(c8);
[packet + 14] = b(S0);
[packet + 15] = b(S2);
[packet + 16] = b(S3);
[packet + 1c] = b(c8);
[packet + 1d] = b(c8);
[packet + 1e] = b(c8);


8002762C	lui    a1, $8006
80027630	lw     a1, $2f24(a1)
80027634	lw     a0, $0280(gp)
80027638	addiu  v0, a1, $0024
8002763C	lui    at, $8006
80027640	sw     v0, $2f24(at)
80027644	jal    system_add_render_packet_to_queue [$80046794]
80027648	nop

A0 = h(S1 + c);
if (A0 != 0)
{
    if (A0 == 1)
    {
        S0 = 0;
        S2 = c8;
        S3 = 50;
    }
    else
    {
        S0 = c8;
        S2 = 0;
        S3 = 0;
    }

    8002767C	lui    a0, $8006
    80027680	lw     a0, $2f24(a0)
    80027684	jal    func46910 [$80046910]
    80027688	nop
    8002768C	lui    v0, $8006
    80027690	lw     v0, $2f24(v0)
    80027694	nop
    80027698	sh     s4, $0008(v0)
    8002769C	lui    v0, $8006
    800276A0	lw     v0, $2f24(v0)
    800276A4	nop
    800276A8	sh     s5, $000a(v0)
    800276AC	lui    v0, $8006
    800276B0	lw     v0, $2f24(v0)
    800276B4	addu   a0, s4, s7
    800276B8	sh     a0, $0010(v0)
    800276BC	lui    v0, $8006
    800276C0	lw     v0, $2f24(v0)
    800276C4	nop
    800276C8	sh     s5, $0012(v0)
    800276CC	lui    v0, $8006
    800276D0	lw     v0, $2f24(v0)
    800276D4	nop
    800276D8	sh     s4, $0018(v0)
    800276DC	lui    v0, $8006
    800276E0	lw     v0, $2f24(v0)
    800276E4	addu   v1, s5, s6
    800276E8	sh     v1, $001a(v0)
    800276EC	lui    v0, $8006
    800276F0	lw     v0, $2f24(v0)
    800276F4	nop
    800276F8	sh     a0, $0020(v0)
    800276FC	lui    v0, $8006
    80027700	lw     v0, $2f24(v0)
    80027704	nop
    80027708	sh     v1, $0022(v0)

    [packet + 4] = b(S0);
    [packet + 5] = b(S2);
    [packet + 6] = b(S3);
    [packet + c] = b(S0);
    [packet + d] = b(S2);
    [packet + e] = b(S3);

    8002776C	lui    v0, $8006
    80027770	lw     v0, $2f24(v0)
    80027774	nop
    80027778	sb     s0, $0014(v0)
    8002777C	lui    v0, $8006
    80027780	lw     v0, $2f24(v0)
    80027784	nop
    80027788	sb     s2, $0015(v0)
    8002778C	lui    v0, $8006
    80027790	lw     v0, $2f24(v0)
    80027794	nop
    80027798	sb     s3, $0016(v0)
    8002779C	lui    v0, $8006
    800277A0	lw     v0, $2f24(v0)
    800277A4	nop
    800277A8	sb     s0, $001c(v0)
    800277AC	lui    v0, $8006
    800277B0	lw     v0, $2f24(v0)
    800277B4	nop
    800277B8	sb     s2, $001d(v0)
    800277BC	lui    v0, $8006
    800277C0	lw     v0, $2f24(v0)
    800277C4	nop
    800277C8	sb     s3, $001e(v0)
    800277CC	lui    a1, $8006
    800277D0	lw     a1, $2f24(a1)
    800277D4	lw     a0, $0280(gp)
    800277D8	addiu  v0, a1, $0024
    800277DC	lui    at, $8006
    800277E0	sw     v0, $2f24(at)
    800277E4	jal    system_add_render_packet_to_queue [$80046794]
    800277E8	nop
}

800277EC	lui    a0, $8006
800277F0	lw     a0, $2f24(a0)
800277F4	jal    func46910 [$80046910]
800277F8	nop
800277FC	lui    v0, $8006
80027800	lw     v0, $2f24(v0)
80027804	nop
80027808	sh     s4, $0008(v0)
8002780C	lui    v0, $8006
80027810	lw     v0, $2f24(v0)
80027814	nop
80027818	sh     s5, $000a(v0)
8002781C	lui    v0, $8006
80027820	lw     v0, $2f24(v0)
80027824	addu   a0, s4, fp
80027828	sh     a0, $0010(v0)
8002782C	lui    v0, $8006
80027830	lw     v0, $2f24(v0)
80027834	nop
80027838	sh     s5, $0012(v0)
8002783C	lui    v0, $8006
80027840	lw     v0, $2f24(v0)
80027844	addu   v1, s5, s6
80027848	sh     s4, $0018(v0)
8002784C	lui    v0, $8006
80027850	lw     v0, $2f24(v0)
80027854	addiu  v1, v1, $0001
80027858	sh     v1, $001a(v0)
8002785C	lui    v0, $8006
80027860	lw     v0, $2f24(v0)
80027864	nop
80027868	sh     a0, $0020(v0)
8002786C	lui    v0, $8006
80027870	lw     v0, $2f24(v0)
80027874	nop
80027878	sh     v1, $0022(v0)

[packet + 4] = b(50);
[packet + 5] = b(0);
[packet + 6] = b(0);
[packet + c] = b(50);
[packet + d] = b(0);
[packet + e] = b(0);
[packet + 14] = b(0);
[packet + 15] = b(0);
[packet + 16] = b(0);
[packet + 1c] = b(0);
[packet + 1d] = b(0);
[packet + 1e] = b(0);

8002793C	lui    a1, $8006
80027940	lw     a1, $2f24(a1)
80027944	lw     a0, $0280(gp)
80027948	addiu  v0, a1, $0024
8002794C	lui    at, $8006
80027950	sw     v0, $2f24(at)
80027954	jal    system_add_render_packet_to_queue [$80046794]
80027958	nop

L2795c:	; 8002795C
////////////////////////////////