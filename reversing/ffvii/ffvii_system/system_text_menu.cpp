////////////////////////////////
// func28e00
// draw digits
S0 = 1;
S5 = 1;
S2 = 1;
x_pos = A0; // X
y_pos = A1; // Y
S4 = A3; // number of digits
A0 = S4;
FP = A4;

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
V1 = S4;
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
    80028ED0	jal    func46870 [$80046870]

    S3 = S1 / S0;

    [packet + 8] = h(x_pos + (S2 - 1) * 7);
    [packet + a] = h(y_pos);
    [packet + c] = b(88 + S3 * 8);

    80028F18	ori    a0, zero, $0100
    80028F34	lui    v0, $8006
    80028F38	lw     v0, $2f24(v0)
    80028F3C	addiu  a1, fp, $01e0
    80028F40	sb     zero, $000d(v0)
    80028F44	lui    v1, $8006
    80028F48	lw     v1, $2f24(v1)
    80028F4C	ori    v0, zero, $0007
    80028F50	sh     v0, $0010(v1)
    80028F54	lui    v1, $8006
    80028F58	lw     v1, $2f24(v1)
    80028F5C	ori    v0, zero, $0008
    80028F60	jal    func46634 [$80046634]
    80028F64	sh     v0, $0012(v1)
    80028F68	lui    v1, $8006
    80028F6C	lw     v1, $2f24(v1)
    80028F70	nop
    80028F74	sh     v0, $000e(v1)
    80028F78	addu   v0, s5, zero

    if (V0 == 0 || S3 != 0)
    {
        80028F8C	lw     a0, $0280(gp)
        80028F90	lui    a1, $8006
        80028F94	lw     a1, $2f24(a1)
        80028F98	jal    system_add_render_packet_to_queue [$80046794]
        80028F9C	addu   s5, zero, zero
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
    80028FC4	addiu  v0, s2, $0001
    80028FC8	addu   s2, v0, zero
    80028FCC	mfhi   a0
    80028FD8	divu   s1, s0
    80028FE8	mfhi   s1
    80028FEC	srl    s0, a0, $03

    L28ff0:	; 80028FF0
    V0 = V0 < S4;
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
80029028	jal    func46870 [$80046870]
8002902C	ori    a1, zero, $0001

[packet + 8] = h(x_pos + (S4 - 1) * 7);
[packet + a] = h(y_pos);

80029058	ori    a0, zero, $0100
80029060	sll    v0, s1, $03
80029064	lui    v1, $8006
80029068	lw     v1, $2f24(v1)
8002906C	addiu  v0, v0, $0088
80029070	sb     v0, $000c(v1)
80029074	lui    v0, $8006
80029078	lw     v0, $2f24(v0)
8002907C	addiu  a1, fp, $01e0
80029080	sb     zero, $000d(v0)
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
