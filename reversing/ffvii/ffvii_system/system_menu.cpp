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
                80024C5C	jal    func1e040 [$8001e040]
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
80023B10	nop

L23b14:	; 80023B14
80023B14	lui    s1, $800a
80023B18	addiu  s1, s1, $d2a4 (=-$2d5c)
80023B1C	lbu    v1, $0000(s1)
80023B20	lui    v0, $800a
80023B24	lbu    v0, $d2a5(v0)
80023B28	lui    a1, $800a
80023B2C	lbu    a1, $d2a6(a1)
80023B30	lui    a0, $800a
80023B34	lbu    a0, $d2a7(a0)
80023B38	sll    v0, v0, $08
80023B3C	sh     v1, $0208(gp)
80023B40	or     v1, v1, v0
80023B44	lui    v0, $800a
80023B48	lbu    v0, $d4f7(v0)
80023B4C	sll    a0, a0, $08
80023B50	sh     a1, $020c(gp)
80023B54	or     a1, a1, a0
80023B58	sh     v1, $0208(gp)
80023B5C	sh     a1, $020c(gp)
80023B60	andi   v0, v0, $0001
80023B64	beq    v0, zero, L23b70 [$80023b70]
80023B68	ori    v0, a1, $0041
80023B6C	sh     v0, $020c(gp)

L23b70:	; 80023B70
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
800241DC	nop
800241E0	addu   v1, v0, zero
800241E4	ori    v0, zero, $0001
800241E8	bne    v1, v0, L24314 [$80024314]
800241EC	addiu  s2, sp, $0030
800241F0	lw     v0, $027c(gp)
800241F4	nop
800241F8	bne    v0, v1, L24318 [$80024318]
800241FC	addu   a1, s2, zero
80024200	lw     v1, $0220(gp)
80024204	nop
80024208	beq    v1, v0, L2429c [$8002429c]
8002420C	slti   v0, v1, $0002
80024210	beq    v0, zero, L24228 [$80024228]
80024214	nop
80024218	beq    v1, zero, L2423c [$8002423c]
8002421C	nop
80024220	j      L24310 [$80024310]
80024224	nop

L24228:	; 80024228
80024228	ori    v0, zero, $0002
8002422C	beq    v1, v0, L2425c [$8002425c]
80024230	addiu  s2, sp, $0030
80024234	j      L24314 [$80024314]
80024238	nop

L2423c:	; 8002423C
8002423C	lui    v0, $800a
80024240	lb     v0, $a0d3(v0)
80024244	ori    a0, zero, $010b
80024248	sll    a1, v0, $01
8002424C	addu   a1, a1, v0
80024250	sll    a1, a1, $02
80024254	j      L24308 [$80024308]
80024258	addiu  a1, a1, $000d

L2425c:	; 8002425C
8002425C	lw     t3, $0478(sp)
80024260	nop
80024264	andi   v0, t3, $0002
80024268	beq    v0, zero, L242d0 [$800242d0]
8002426C	nop
80024270	lw     v0, $023c(gp)
80024274	nop
80024278	beq    v0, zero, L242a0 [$800242a0]
8002427C	addiu  a0, zero, $fffc (=-$4)
80024280	lw     v0, $02d8(gp)
80024284	nop
80024288	sll    a1, v0, $04
8002428C	subu   a1, a1, v0
80024290	sll    a1, a1, $02
80024294	jal    func1eb2c [$8001eb2c]
80024298	addiu  a1, a1, $002b

L2429c:	; 8002429C
8002429C	lw     t3, $0478(sp)

L242a0:	; 800242A0
800242A0	nop
800242A4	andi   v0, t3, $0002
800242A8	beq    v0, zero, L242d0 [$800242d0]
800242AC	nop
800242B0	lui    v0, $800a
800242B4	lb     v0, $a0d3(v0)
800242B8	ori    a0, zero, $010b
800242BC	sll    a1, v0, $01
800242C0	addu   a1, a1, v0
800242C4	sll    a1, a1, $02
800242C8	jal    func1eb2c [$8001eb2c]
800242CC	addiu  a1, a1, $000d

L242d0:	; 800242D0
800242D0	lw     v1, $0220(gp)
800242D4	nop
800242D8	sll    v0, v1, $03
800242DC	addu   v0, v0, v1
800242E0	sll    v0, v0, $01
800242E4	lui    at, $800a
800242E8	addiu  at, at, $a0d3 (=-$5f2d)
800242EC	addu   at, at, v0
800242F0	lb     v0, $0000(at)
800242F4	addu   a0, zero, zero
800242F8	sll    a1, v0, $04
800242FC	subu   a1, a1, v0
80024300	sll    a1, a1, $02
80024304	addiu  a1, a1, $002f

L24308:	; 80024308
80024308	jal    func1eb2c [$8001eb2c]
8002430C	nop

L24310:	; 80024310
80024310	addiu  s2, sp, $0030

L24314:	; 80024314
80024314	addu   a1, s2, zero

L24318:	; 80024318
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
8002435C	lw     a0, $0214(gp)
80024360	jal    func230c4 [$800230c4]



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
80024468	jal    func28e00 [$80028e00]





80024470	addiu  a0, s3, $002c
80024474	ori    a1, zero, $00ad
80024478	ori    a2, zero, $00d5
8002447C	lui    v0, $800a
80024480	lw     v0, $d26c(v0)
80024484	ori    a3, zero, $7fff
80024488	sltu   a3, a3, v0
8002448C	xori   a3, a3, $0001
80024490	subu   a3, zero, a3
80024494	jal    func2708c [$8002708c]
80024498	andi   a3, a3, $0007
8002449C	lui    a0, $800a
800244A0	lw     a0, $d264(a0)
800244A4	jal    func2382c [$8002382c]
800244A8	ori    fp, zero, $001d
800244AC	addiu  a0, s3, $0032
800244B0	ori    a1, zero, $00ac
800244B4	addu   a2, v0, zero
800244B8	ori    a3, zero, $0002
A4 = 7;
800244BC	jal    func29114 [$80029114]

800244C4	addiu  a0, s3, $003e
800244C8	ori    a1, zero, $00ad
800244CC	ori    a2, zero, $00d5
800244D0	jal    func2708c [$8002708c]
800244D4	ori    a3, zero, $0007
800244D8	lui    a0, $800a
800244DC	lw     a0, $d264(a0)
800244E0	jal    func23940 [$80023940]
800244E4	ori    s7, zero, $001f
800244E8	addiu  a0, s3, $0043
800244EC	ori    a1, zero, $00ac
800244F0	addu   a2, v0, zero
800244F4	ori    a3, zero, $0002
A4 = 7;
800244F8	jal    func29114 [$80029114]

A0 = S3 + b;
A1 = ba;
A2 = w[8009c6e4 + 0b7c];
A3 = a;
A4 = 7;
80024514	jal    func28e00 [$80028e00]

8002451C	addu   a0, zero, zero
80024520	ori    a1, zero, $0001
80024524	ori    a2, zero, $007f
80024528	addu   a3, s2, zero
8002452C	ori    v0, zero, $0100
80024530	sh     zero, $0030(sp)
80024534	sh     zero, $0032(sp)
80024538	sh     v0, $0034(sp)
8002453C	jal    func26a34 [$80026a34]
80024540	sh     v0, $0036(sp)

[SP + 28] = h(S3);
[SP + 2a] = h(a4);
[SP + 2c] = h(56);
[SP + 2e] = h(24);

A0 = SP + 28
80024560	jal    func1e040 [$8001e040]

80024568	lh     v0, $0164(gp)
8002456C	nop
80024570	sll    v1, v0, $01
80024574	addu   v1, v1, v0
80024578	sll    v1, v1, $03
8002457C	subu   v1, v1, v0
80024580	sll    v1, v1, $03
80024584	mult   v1, s1
80024588	addu   s2, zero, zero
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

L245bc:	; 800245BC
    800245BC	lui    at, $800a
    800245C0	addiu  at, at, $cbdc (=-$3424)
    800245C4	addu   at, at, s2
    800245C8	lbu    v0, $0000(at)
    800245CC	ori    t3, zero, $00ff
    800245D0	beq    v0, t3, L24908 [$80024908]
    800245D4	addiu  a0, s3, $0066
    800245D8	sll    v0, v0, $02
    800245DC	lui    t3, $8005
    800245E0	addiu  t3, t3, $91d0 (=-$6e30)
    800245E4	addu   v0, v0, t3
    800245E8	lbu    s5, $0000(v0)
    800245EC	addu   a1, s7, zero
    800245F0	sll    v0, s5, $05
    800245F4	addu   v0, v0, s5
    800245F8	sll    s1, v0, $02
    800245FC	lui    at, $800a
    80024600	addiu  at, at, $c758 (=-$38a8)
    80024604	addu   at, at, s1
    80024608	lbu    v0, $0000(at)
    8002460C	addu   a2, s2, zero
    80024610	xori   v0, v0, $0001
    80024614	andi   v0, v0, $0001
    80024618	sll    s0, v0, $01
    8002461C	addu   s0, s0, v0
    80024620	jal    func20b68 [$80020b68]
    80024624	sll    s0, s0, $03
    80024628	addu   s0, s3, s0
    8002462C	addiu  a0, s0, $0016
    80024630	addu   a1, fp, zero
    80024634	ori    a2, zero, $0030
    80024638	ori    a3, zero, $0030
    8002463C	sll    v0, s2, $01
    80024640	addu   v0, v0, s2
    80024644	sll    v0, v0, $04
    80024648	addiu  v0, v0, $0038
    8002464C	sw     v0, $0014(sp)
    80024650	ori    v0, zero, $0030
    80024654	sw     v0, $0018(sp)
    80024658	sw     v0, $001c(sp)
    8002465C	addiu  v0, s2, $000d
    80024660	sw     zero, $0010(sp)
    80024664	sw     v0, $0020(sp)
    80024668	jal    func1cf3c [$8001cf3c]
    8002466C	sw     zero, $0024(sp)
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
    8002478C	lui    at, $800a
    80024790	addiu  at, at, $c747 (=-$38b9)
    80024794	addu   at, at, v0
    80024798	lbu    v1, $0000(at)
    8002479C	nop
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
    800247DC	sll    s0, s0, $10
    800247E0	sra    s0, s0, $10
    800247E4	addu   a0, s0, zero
    800247E8	addiu  a1, s4, $001b
    800247EC	sll    a1, a1, $10
    800247F0	sra    a1, a1, $10
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
    80024824	sll    a1, a1, $10
    80024828	sra    a1, a1, $10
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
    80024880	ori    a3, zero, $0001
    80024884	sll    v0, v1, $05
    80024888	addu   v0, v0, v1
    8002488C	sll    v0, v0, $02
    80024890	lui    at, $800a
    80024894	addiu  at, at, $c746 (=-$38ba)
    80024898	addu   at, at, v0
    8002489C	lbu    a2, $0000(at)
    800248A0	ori    t3, zero, $0007
    800248A4	jal    func28e00 [$80028e00]
    800248A8	sw     t3, $0010(sp)
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

    L24908:	; 80024908
    80024908	addiu  fp, fp, $003c
    8002490C	addiu  s7, s7, $003c
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
80024948	jal    func1e040 [$8001e040]

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
V1 = w[80049474]; // 36000
V0 = w[80049478]; // 3600
return (A0 / V1) * a + (A0 % V1) / V0;
////////////////////////////////