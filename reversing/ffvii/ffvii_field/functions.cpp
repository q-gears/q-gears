////////////////////////////////
// funcba65c
800BA65C	lui    v0, $8008
800BA660	lbu    v0, $ebe0(v0)
800BA66C	addu   s0, a0, zero
800BA670	beq    v0, zero, Lba738 [$800ba738]

800BA678	jal    funcd4bfc [$800d4bfc]
800BA67C	nop
800BA680	jal    funcbc338 [$800bc338]
800BA684	nop
800BA688	jal    funcd7d6c [$800d7d6c]
800BA68C	nop
800BA690	jal    funcd7f9c [$800d7f9c]
800BA694	nop
800BA698	lui    v0, $800a
800BA69C	lw     v0, $c6dc(v0)
800BA6A0	lui    at, $8009
800BA6A4	sb     zero, $5dcc(at)
800BA6A8	lui    at, $800a
800BA6AC	sb     zero, $fe8c(at)
800BA6B0	lui    at, $8008
800BA6B4	sb     zero, $ebe0(at)
800BA6B8	lbu    v0, $0001(v0)
800BA6BC	nop
800BA6C0	sltiu  v0, v0, $0005
800BA6C4	beq    v0, zero, Lba6d4 [$800ba6d4]
800BA6C8	ori    a0, zero, $004b
800BA6CC	jal    func429e0 [$800429e0]
800BA6D0	ori    a1, zero, $000b

Lba6d4:	; 800BA6D4
800BA6D4	lui    v0, $800a
800BA6D8	lw     v0, $c6dc(v0)
800BA6DC	nop
800BA6E0	lbu    v0, $0000(v0)
800BA6E4	nop
800BA6E8	sltiu  v0, v0, $0002
800BA6EC	beq    v0, zero, Lba6fc [$800ba6fc]
800BA6F0	ori    a0, zero, $004b
800BA6F4	jal    func429e0 [$800429e0]
800BA6F8	ori    a1, zero, $000a

Lba6fc:	; 800BA6FC
800BA6FC	lui    v1, $800a
800BA700	lw     v1, $c6dc(v1)
800BA704	nop
800BA708	lbu    v0, $0000(v1)
800BA70C	nop
800BA710	sltiu  v0, v0, $0003
800BA714	beq    v0, zero, Lba730 [$800ba730]
800BA718	ori    a0, zero, $004b
800BA71C	lbu    v0, $0001(v1)
800BA720	nop
800BA724	sltiu  v0, v0, $0006
800BA728	bne    v0, zero, Lba738 [$800ba738]
800BA72C	nop

Lba730:	; 800BA730
800BA730	jal    func429e0 [$800429e0]
800BA734	ori    a1, zero, $000c

Lba738:	; 800BA738
if (bu[80099ffc] != 4 || bu[80099ffc] != 5 || bu[80070788] != 0)
{
    opcode_cycle;
}

800BA770	lui    v0, $8007
800BA774	lbu    v0, $1e2c(v0)
800BA778	nop
800BA77C	beq    v0, zero, Lba7a8 [$800ba7a8]
800BA780	ori    a1, zero, $0004
800BA784	lui    a0, $8008
800BA788	addiu  a0, a0, $3274
800BA78C	lui    v0, $800a
800BA790	lw     v0, $c6e0(v0)
800BA794	nop
800BA798	lbu    a3, $0000(v0)
800BA79C	addu   a2, s0, zero
800BA7A0	jal    func1f1bc [$8001f1bc]
800BA7A4	xori   a3, a3, $0001

Lba7a8:	; 800BA7A8
800BA7A8	jal    funcbc438 [$800bc438]
800BA7AC	addu   a0, s0, zero
////////////////////////////////



////////////////////////////////
// funcbc438
// enable disable pointer and triangles?

struct = w[8009c6e0];
if (w[struct + 80] & 100) // key pressed
{
    [8009d5a6] = b(bu[8009d5a6] ^ 1);
}

if (( bu[8009d5a6] == 1 && bu[struct + 32] == 0 ) || ( bu[8009d5a6] & 2) )
{
    A0 = A0;
    funcbc4d4;
}
////////////////////////////////


////////////////////////////////
// funcbc4d4
if (bu[80071c1c] != 0)
{
    return;
}
T0 = A0;

A2 = h[80114464];
A3 = h[80114468];

if (A2 == 7fff && A3 == 7fff)
{
    return;
}

if (A2 >= 141)
{
    A2 = 140;
}
if (A2 < 0)
{
    A2 = 0;
}

if (A3 >= e1)
{
    A3 = e0;
}
if (A3 < 0)
{
    A3 = 0;
}

[80114490] = b(bu[80114490] ^ 1);
V1 = bu[80114490];
if (A2 >= 123)
{
    [800e4900 + V1 * 28] = b(8f);
    [800e4908 + V1 * 28] = b(7f);
    [800e4910 + V1 * 28] = b(8f);
    [800e4918 + V1 * 28] = b(7f);
    [800e48fc + V1 * 28] = h(A2 - 10);
    [800e4904 + V1 * 28] = h(A2);
    [800e490c + V1 * 28] = h(A2 - 10);
    [800e4914 + V1 * 28] = h(A2);
}
else
{
    [800e4900 + V1 * 28] = b(80);
    [800e4908 + V1 * 28] = b(90);
    [800e4910 + V1 * 28] = b(80);
    [800e4918 + V1 * 28] = b(90);
    [800e48fc + V1 * 28] = h(A2);
    [800e4904 + V1 * 28] = h(A2 + 10);
    [800e490c + V1 * 28] = h(A2);
    [800e4914 + V1 * 28] = h(A2 + 10);
}

if (A3 < 11)
{
    [800e4901 + V1 * 28] = b(6f);
    [800e4909 + V1 * 28] = b(6f);
    [800e4911 + V1 * 28] = b(5f);
    [800e4919 + V1 * 28] = b(5f);
    [800e48fe + V1 * 28] = h(A3);
    [800e4906 + V1 * 28] = h(A3);
    [800e490e + V1 * 28] = h(A3 + 10);
    [800e4916 + V1 * 28] = h(A3 + 10);
}
else
{
    [800e4901 + V1 * 28] = b(60);
    [800e4909 + V1 * 28] = b(60);
    [800e4911 + V1 * 28] = b(70);
    [800e4919 + V1 * 28] = b(70);
    [800e48fe + V1 * 28] = h(A3 - 10);
    [800e4906 + V1 * 28] = h(A3 - 10);
    [800e490e + V1 * 28] = h(A3);
    [800e4916 + V1 * 28] = h(A3);
}

V0 = bu[80114490];
V1 = 800e48f4 + V0 * 28;

[V1] = w((w[V1] & ff000000) | (w[T0] & 00ffffff));
[T0] = w((w[T0] & ff000000) | (V1 & 00ffffff));
////////////////////////////////



////////////////////////////////
// calculate_smooth_current_value_by_steps
start = A0;
end = A1;
steps = A2;
step = A3;

step = step << C;
A0 = step / steps;
A0 = A0 >> 5;
A0 = A0 - 80;
A0 = A0 & FF;
get_direction_vector_y;
V0 = V0 + 1000;
V0 = V0 * (end - start);
V0 = V0 >> C;
V0 = V0 / 2
V0 = start + V0;
return V0;
////////////////////////////////



////////////////////////////////
// field_calculate_distance_to_screen
S0 = A0;
S1 = A1;

func3ae38;

A0 = w[80071e40];
PsyQSetRotMatrix;

A0 = w[80071e40];
PsyQSetTransMatrix;

A0 = 0;
A1 = 0;
PsyQSetGeomOffset;

A0 = S0;
A1 = S1;
A2 = SP + 10;
A3 = SP + 14;
PsyQRotTransPers;

func3aed8;

return V0;
////////////////////////////////
