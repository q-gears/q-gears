////////////////////////////////
// func44a68
S0 = A0;
A0 = A1;
[S0 + 3] = b(2);
A1 = A2;
S1 = A4;
A2 = A3; // tex page settings

80044A90	jal    func44d64 [$80044d64]

[S0 + 4] = w(V0);
A0 = S1;
80044A9C	jal    func44fa0 [$80044fa0]

[S0 + 8] = w(V0);
////////////////////////////////



////////////////////////////////
// func436c0
address = A0;
tp = A1;
abr = A2;
vram_x = A3;
vram_y = A4;
width = A5;
height = A6;

[SP + 10] = h(vram_x);
[SP + 12] = h(vram_y);
[SP + 16] = h(height);

if (tp == 0)
{
    [SP + 14] = h(ceil(width / 4));
}
else if (tp == 1)
{
    [SP + 14] = h(ceil(width / 2));
}
else if (tp == 2)
{
    [SP + 14] = h(width);
}

A0 = SP + 10;
A1 = address;
func44000;

A0 = tp;
A1 = abr;
A2 = vram_x;
A3 = vram_y;
system_create_texture_page_settings_for_packet;

return V0;
////////////////////////////////



////////////////////////////////
// system_create_texture_page_settings_for_packet
tp = A0;
abr = A1;
vram_x = A2;
vram_y = A3;

if (bu[80062c00] == 1 || bu[80062c00] == 2)
{
    return ((tp & 3) << 9) | ((abr & 3) << 7) | ((vram_y & 300) >> 3) | ((vram_x & 3c0) >> 6);
}
else
{
    return ((vram_y & 200) << 2) | ((tp & 3) << 7) | ((abr & 3) << 5) | (((vram_y & 100) >> 4)) | ((vram_x & 3c0) >> 6);
}
////////////////////////////////



////////////////////////////////
// func44ac0
S0 = A1;
S1 = A0;
A0 = h[S0 + 0];
A1 = h[S0 + 2]
func44dc0;

[S1 + 4] = w(V0);

A0 = h[S0 + 4];
V0 = h[S0 + 0];
A1 = h[S0 + 2];
A0 = A0 + V0 - 1;
V0 = hu[S0 + 6];
A1 = A1 + V0 - 1;
80044B18	jal    func44e8c [$80044e8c]

80044B20	sw     v0, $0008(s1)
80044B24	lh     a0, $0008(s0)
80044B28	lh     a1, $000a(s0)
80044B2C	jal    func44f58 [$80044f58]
80044B30	nop
80044B34	sw     v0, $000c(s1)
80044B38	lbu    a0, $0017(s0)
80044B3C	lbu    a1, $0016(s0)
80044B40	lhu    a2, $0014(s0)
80044B44	jal    func44d64 [$80044d64]
80044B48	nop
80044B4C	addiu  a0, s0, $000c
80044B50	jal    func44fa0 [$80044fa0]
80044B54	sw     v0, $0010(s1)
80044B58	sw     v0, $0014(s1)
80044B5C	lui    v0, $e600
80044B60	sw     v0, $0018(s1)
80044B64	lbu    v0, $0018(s0)
80044B68	nop
80044B6C	beq    v0, zero, L44d44 [$80044d44]
80044B70	ori    t0, zero, $0007
80044B74	lhu    v0, $0000(s0)
80044B78	nop
80044B7C	sh     v0, $0010(sp)
80044B80	lhu    v0, $0002(s0)
80044B84	nop
80044B88	sh     v0, $0012(sp)
80044B8C	lhu    v0, $0004(s0)
80044B90	nop
80044B94	sh     v0, $0014(sp)
80044B98	lhu    v1, $0006(s0)
80044B9C	sll    v0, v0, $10
80044BA0	sh     v1, $0016(sp)
80044BA4	sra    v1, v0, $10
80044BA8	bltz   v1, L44be0 [$80044be0]
80044BAC	addu   v0, zero, zero
80044BB0	lui    v0, $8006
80044BB4	addiu  v0, v0, $2c04
80044BB8	lhu    v0, $0000(v0)
80044BBC	nop
80044BC0	sll    v0, v0, $10
80044BC4	sra    v0, v0, $10
80044BC8	addiu  a0, v0, $ffff (=-$1)
80044BCC	slt    v0, a0, v1
80044BD0	beq    v0, zero, L44be0 [$80044be0]
80044BD4	addu   v0, v1, zero
80044BD8	addu   v1, a0, zero
80044BDC	addu   v0, v1, zero

L44be0:	; 80044BE0
80044BE0	lh     v1, $0016(sp)
80044BE4	nop
80044BE8	bltz   v1, L44c24 [$80044c24]
80044BEC	sh     v0, $0014(sp)
80044BF0	lui    v0, $8006
80044BF4	addiu  v0, v0, $2c06
80044BF8	lhu    v0, $0000(v0)
80044BFC	nop
80044C00	sll    v0, v0, $10

L44c04:	; 80044C04
80044C04	sra    v0, v0, $10
80044C08	addiu  a0, v0, $ffff (=-$1)
80044C0C	slt    v0, a0, v1
80044C10	beq    v0, zero, L44c28 [$80044c28]
80044C14	addu   v0, v1, zero
80044C18	addu   v1, a0, zero
80044C1C	j      L44c28 [$80044c28]
80044C20	addu   v0, v1, zero

L44c24:	; 80044C24
80044C24	addu   v0, zero, zero

L44c28:	; 80044C28
80044C28	lhu    v1, $0010(sp)
80044C2C	sh     v0, $0016(sp)
80044C30	andi   v0, v1, $003f
80044C34	bne    v0, zero, L44c50 [$80044c50]
80044C38	sll    a2, t0, $02
80044C3C	lhu    v0, $0014(sp)
80044C40	nop
80044C44	andi   v0, v0, $003f
80044C48	beq    v0, zero, L44cec [$80044cec]

L44c4c:	; 80044C4C
80044C4C	sll    a1, t0, $02

L44c50:	; 80044C50
80044C50	addiu  t0, t0, $0001
80044C54	sll    a1, t0, $02
80044C58	addiu  t0, t0, $0001
80044C5C	lhu    v0, $0008(s0)
80044C60	addu   a2, a2, s1
80044C64	subu   v0, v1, v0
80044C68	sh     v0, $0010(sp)
80044C6C	lhu    v0, $0012(sp)
80044C70	lhu    v1, $000a(s0)
80044C74	lui    a0, $6000
80044C78	subu   v0, v0, v1
80044C7C	sh     v0, $0012(sp)
80044C80	lbu    v0, $001b(s0)
80044C84	lbu    v1, $001a(s0)
80044C88	sll    v0, v0, $10
80044C8C	sll    v1, v1, $08
80044C90	or     v1, v1, a0
80044C94	lbu    a0, $0019(s0)
80044C98	or     v0, v0, v1
80044C9C	or     v0, v0, a0
80044CA0	sw     v0, $0000(a2)
80044CA4	lw     v0, $0010(sp)
80044CA8	addu   a1, a1, s1
80044CAC	sw     v0, $0000(a1)
80044CB0	sll    v0, t0, $02
80044CB4	lw     v1, $0014(sp)
80044CB8	addu   v0, v0, s1
80044CBC	sw     v1, $0000(v0)
80044CC0	lhu    v0, $0010(sp)
80044CC4	lhu    v1, $0008(s0)
80044CC8	nop
80044CCC	addu   v0, v0, v1
80044CD0	sh     v0, $0010(sp)
80044CD4	lhu    v0, $0012(sp)
80044CD8	lhu    v1, $000a(s0)
80044CDC	addiu  t0, t0, $0001
80044CE0	addu   v0, v0, v1
80044CE4	j      L44d44 [$80044d44]
80044CE8	sh     v0, $0012(sp)

L44cec:	; 80044CEC
80044CEC	addiu  t0, t0, $0001
80044CF0	sll    a2, t0, $02
80044CF4	addiu  t0, t0, $0001
80044CF8	sll    a3, t0, $02
80044CFC	addiu  t0, t0, $0001
80044D00	addu   a1, a1, s1
80044D04	lui    a0, $0200
80044D08	lbu    v0, $001b(s0)
80044D0C	lbu    v1, $001a(s0)
80044D10	sll    v0, v0, $10
80044D14	sll    v1, v1, $08
80044D18	or     v1, v1, a0
80044D1C	lbu    a0, $0019(s0)
80044D20	or     v0, v0, v1
80044D24	or     v0, v0, a0
80044D28	sw     v0, $0000(a1)
80044D2C	lw     v0, $0010(sp)
80044D30	addu   a2, a2, s1
80044D34	sw     v0, $0000(a2)
80044D38	lw     v0, $0014(sp)
80044D3C	addu   a3, a3, s1
80044D40	sw     v0, $0000(a3)

L44d44:	; 80044D44
V0 = T0 - 1;
[S1 + 3] = b(V0);

return;
////////////////////////////////



////////////////////////////////
// func44dc0
V0 = 0;
if (A0 >= 0)
{
    A2 = hu[80062c04] - 1;
    V0 = (A2 < A0) ? A2 : A0;
}

A0 = V0;
V1 = A1;

A1 = 0;
if (V1 >= 0)
{
    A1 = hu[80062c06] - 1;
    A1 = (A1 < V1) ? A1 : V1;
}

if ((bu[80062c00] - 1) >= 2)
{
    V1 = A1 & 03FF;
    V1 = V1 << a;
    V0 = A0 & 03ff;
}
else
{
    V1 = A1 & 0fff;
    V1 = V1 << C;
    V0 = A0 & 0fff;
}

return e3000000 | V1 | V0;
////////////////////////////////



////////////////////////////////
// func46848
if (A1 != 0)
{
    [A0 + 7] = b(bu[A0 + 7] | 2);
}
else
{
    [A0 + 7] = b(bu[A0 + 7] & fd);
}
////////////////////////////////



////////////////////////////////
// func46870
if (A1 != 0)
{
    [A0 + 7] = b(bu[A0 + 7] | 1);
}
else
{
    [A0 + 7] = b(bu[A0 + 7] & fe);
}
////////////////////////////////



////////////////////////////////
// func46634
V0 = A1 << 06;
A0 = A0 >> 04;
A0 = A0 & 3f;
V0 = V0 | A0;
V0 = V0 & ffff
////////////////////////////////



////////////////////////////////
// system_add_render_packet_to_queue
[A1] = w((w[A1] & ff000000) | (w[A0] & 00ffffff));
[A0] = w((w[A0] & ff000000) | (A1 & 00ffffff));
////////////////////////////////



////////////////////////////////
// func26a34
80026A34	addiu  sp, sp, $ffe0 (=-$20)
80026A38	addu   v0, a0, zero
80026A3C	addu   v1, a1, zero
80026A40	addu   t0, a2, zero
80026A44	addu   a1, v0, zero
80026A48	lui    a0, $8006
80026A4C	lw     a0, $2f24(a0)
80026A50	addu   a2, v1, zero
80026A54	sw     a3, $0010(sp)
80026A58	sw     ra, $0018(sp)
80026A5C	jal    func44a68 [$80044a68]
80026A60	addu   a3, t0, zero
80026A64	lui    a1, $8006
80026A68	lw     a1, $2f24(a1)
80026A6C	lw     a0, $0280(gp)
80026A70	addiu  v0, a1, $000c
80026A74	lui    at, $8006
80026A78	sw     v0, $2f24(at)
80026A7C	jal    system_add_render_packet_to_queue [$80046794]
80026A80	nop
80026A84	lw     ra, $0018(sp)
80026A88	addiu  sp, sp, $0020
80026A8C	jr     ra 
80026A90	nop
////////////////////////////////



////////////////////////////////
// system_get_character_name_offset
V1 = w[800491D0 + A0 * 4]
V0 = 8009C748 + V1 * 84;
////////////////////////////////



////////////////////////////////
// func155a4
[GP + 1d0] = w(A0);
////////////////////////////////



////////////////////////////////
// func34b44
V0 = w[80071a60];
80034B54	sltiu  v0, v0, $0015
80034B58	bne    v0, zero, L34b68 [$80034b68]

L34b60:	; 80034B60
80034B60	j      L34b60 [$80034b60]
80034B64	nop

L34b68:	; 80034B68
80034B68	lui    s0, $8007
80034B6C	addiu  s0, s0, $1a60
80034B70	lw     v0, $0000(s0)
80034B74	nop
80034B78	sll    v0, v0, $02
80034B7C	lui    at, $8005
80034B80	addiu  at, at, $a634 (=-$59cc)
80034B84	addu   at, at, v0
80034B88	lw     v0, $0000(at)
80034B8C	nop
80034B90	jalr   v0 ra
80034B94	nop
80034B98	lw     v0, $0000(s0)
////////////////////////////////