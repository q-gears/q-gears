////////////////////////////////
// system_draw_single_menu_font_character
pos_x = A0;
pos_y = A1;
colour = S4 = A3;
character = A2;

if (character < 29) // dakuten characters
{
    packet = w[80062f24];
    [packet + 3] = b(3);
    [packet + 7] = b(74);

    A0 = packet;
    A1 = 1;
    system_change_brightness_calculation_in_packet;

    [packet + 8] = h(pos_x);
    [packet + a] = h(pos_y - 8);
    [packet + c] = b(88);
    [packet + d] = b(98);

    A0 = 100;
    A1 = S4 & ff;
    A1 = A1 + 1e0;
    func46634; // clut

    [packet + e] = h(V0);

    [80062f24] = w(packet + 10);

    A0 = w[GP + 280];
    A1 = packet;
    system_add_render_packet_to_queue;

    character = character + 40;
}
else if ((((character + 4c) & ff) >= 1a) && (((character - 29) & ff) < a)) // handakuten characters
{
    packet = w[80062f24];
    [packet + 3] = b(3);
    [packet + 7] = b(74);

    A0 = packet;
    A1 = 1;
    system_change_brightness_calculation_in_packet;

    [packet + 8] = h(pos_x);
    [packet + a] = h(pos_y - 8);
    [packet + c] = b(90);
    [packet + d] = b(98);

    A0 = 100;
    A1 = S4 & ff;
    A1 = A1 + 1e0;
    func46634; // clut

    [packet + e] = h(V0);

    [80062f24] = w(packet + 10);

    A0 = w[GP + 280];
    A1 = packet;
    system_add_render_packet_to_queue;

    character = character + 17;
}

tex_x = ((character & f) * 8) | 80;
tex_y = ((character >> 4) * 8) | 80;

packet = w[80062f24];
[packet + 3] = b(3);
[packet + 7] = b(74);

A0 = packet;
A1 = 1;
system_change_brightness_calculation_in_packet;

[packet + 8] = h(pos_x);
[packet + a] = h(pos_y);
[packet + c] = b(tex_x);
[packet + d] = b(tex_y);

A0 = 100;
A1 = S4 & ff;
A1 = A1 + 1e0;
func46634;

[packet + e] = h(V0);

[80062f24] = w(packet + 10);

A0 = w[GP + 280];
A1 = packet;
system_add_render_packet_to_queue;
////////////////////////////////



////////////////////////////////
// func28e00
// draw digits
S0 = 1;
S5 = 1;
S2 = 1;
x_pos = A0; // X
y_pos = A1; // Y
number_of_digits = A3; // number of digits
A0 = number_of_digits;
colour = A4;

80028E40	slt    v0, s0, a0
80028E4C	beq    v0, zero, L28e7c [$80028e7c]

loop28e58:	; 80028E58
    80028E54	sll    v0, s0, $02
    80028E58	addu   v0, v0, s0
    80028E5C	sll    s0, v0, $01
    80028E60	addiu  v0, s2, $0001
    80028E64	addu   s2, v0, zero
    80028E68	sll    v0, v0, $10
    80028E6C	sra    v0, v0, $10
    80028E70	slt    v0, v0, a0
80028E74	bne    v0, zero, loop28e58 [$80028e58]


L28e7c:	; 80028E7C
V1 = number_of_digits;
S1 = A2;
if (V1 == 3)
{
    if (S1 >= 3e8)
    {
        S1 = 3e7;
    }
}

S2 = 1;
V0 = 1;
80028EA0	j      L28ff0 [$80028ff0]


loop28ea8:	; 80028EA8
    V1 = packet = w[80062f24];
    [packet + 3] = b(4);
    [packet + 7] = b(64);

    A0 = packet;
    A1 = 1;
    system_change_brightness_calculation_in_packet;

    S3 = S1 / S0;

    [packet + 8] = h(x_pos + (S2 - 1) * 7);
    [packet + a] = h(y_pos);
    [packet + c] = b(88 + S3 * 8);
    [packet + d] = b(0);
    [packet + 10] = h(7);
    [packet + 12] = h(8);

    A0 = 100;
    A1 = colour + 1e0;
    func46634;

    [packet + e] = h(V0);

    if (S5 == 0 || S3 != 0)
    {
        S5 = 0;
        80028F8C	lw     a0, $0280(gp)
        80028F90	lui    a1, $8006
        80028F94	lw     a1, $2f24(a1)
        80028F98	jal    system_add_render_packet_to_queue [$80046794]

        80028FA0	lui    v0, $8006
        80028FA4	lw     v0, $2f24(v0)
        80028FA8	nop
        80028FAC	addiu  v0, v0, $0014
        80028FB0	lui    at, $8006
        80028FB4	sw     v0, $2f24(at)
    }

    80028FB8	lui    v0, $cccc
    80028FBC	ori    v0, v0, $cccd
    80028FC0	multu  s0, v0
    S2 = S2 + 1;
    80028FCC	mfhi   a0
    80028FD8	divu   s1, s0
    80028FE8	mfhi   s1
    80028FEC	srl    s0, a0, $03

    L28ff0:	; 80028FF0
    V0 = S2 < number_of_digits;
80028FF8	bne    v0, zero, loop28ea8 [$80028ea8]

80028FFC	ori    v0, zero, $0004
80029000	lui    v1, $8006
80029004	lw     v1, $2f24(v1)
80029008	nop
8002900C	sb     v0, $0003(v1)
80029010	lui    v1, $8006
80029014	lw     v1, $2f24(v1)
80029018	ori    v0, zero, $0064
8002901C	sb     v0, $0007(v1)
80029020	lui    a0, $8006
80029024	lw     a0, $2f24(a0)
80029028	jal    system_change_brightness_calculation_in_packet [$80046870]
8002902C	ori    a1, zero, $0001

[packet + 8] = h(x_pos + (number_of_digits - 1) * 7);
[packet + a] = h(y_pos);

[packet + c] = b(S1 * 8 + 88);
[packet + d] = b(0);

A0 = 100;
A1 = colour + 1e0;

80029084	lui    v1, $8006
80029088	lw     v1, $2f24(v1)
8002908C	ori    v0, zero, $0007
80029090	sh     v0, $0010(v1)
80029094	lui    v1, $8006
80029098	lw     v1, $2f24(v1)
8002909C	ori    v0, zero, $0008
800290A0	jal    func46634 [$80046634]
800290A4	sh     v0, $0012(v1)
800290A8	lui    v1, $8006
800290AC	lw     v1, $2f24(v1)
800290B0	lw     a0, $0280(gp)
800290B4	sh     v0, $000e(v1)
800290B8	lui    a1, $8006
800290BC	lw     a1, $2f24(a1)
800290C0	jal    system_add_render_packet_to_queue [$80046794]
800290C4	nop
800290C8	lui    v0, $8006
800290CC	lw     v0, $2f24(v0)
800290D0	nop
800290D4	addiu  v0, v0, $0014
800290D8	lui    at, $8006
800290DC	sw     v0, $2f24(at)
////////////////////////////////



////////////////////////////////
// system_draw_menu_8width_font
pointer = A2;
pos_y = A1;
pos_x = A0;
colour = A3;

if (pointer != 0)
{
    if (bu[GP + b8] != 0)
    {
        S2 = 0;
        loop2739c:	; 8002739C
            A2 = bu[pointer];
            if (A2 == ff)
            {
                break;
            }

            A0 = pos_x + S2 * 8;
            A1 = pos_y;
            A3 = colour;
            system_draw_single_menu_font_character;

            pointer = pointer + 1;
            S2 = S2 + 1;
            V0 = S2 < bu[GP + b8];
        800273D8	bne    v0, zero, loop2739c [$8002739c]
    }
}
////////////////////////////////