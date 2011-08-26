////////////////////////////////
// funcab728
V0 = bu[8009d70b] & 80;

800AB738	bne    v0, zero, Lab75c [$800ab75c]
800AB73C	ori    v0, zero, $00ff
800AB740	lui    v0, $800e
800AB744	lbu    v0, $48d8(v0)
800AB748	nop
800AB74C	beq    v0, zero, Lab778 [$800ab778]
800AB750	addiu  v0, v0, $ffff (=-$1)
800AB754	j      Lab770 [$800ab770]
800AB758	nop

Lab75c:	; 800AB75C
800AB75C	lui    v1, $800e
800AB760	lbu    v1, $48d8(v1)
800AB764	nop
800AB768	beq    v1, v0, Lab778 [$800ab778]
800AB76C	addiu  v0, v1, $0001

Lab770:	; 800AB770
800AB770	lui    at, $800e
800AB774	sb     v0, $48d8(at)

Lab778:	; 800AB778
800AB778	ori    t4, zero, $0001
V0 = 800e42d8;
800AB784	addiu  a3, v0, $0010
800AB788	addu   t1, v0, zero
800AB78C	addiu  t0, t1, $0014
800AB790	addu   a2, zero, zero
V0 = bu[800e48d8];
V1 = h[800965e0]; // manual visible entity
T3 = V0 >> 2;
T2 = V1 * 84;

Lab7b4:	; 800AB7B4
    800AB7B4	lh     v0, $0000(a3)
    800AB7B8	nop
    800AB7BC	bne    v0, zero, Lab948 [$800ab948]
    800AB7C0	sll    v0, t3, $01
    800AB7C4	addu   v0, v0, t3
    800AB7C8	sll    v0, v0, $03
    800AB7CC	lui    v1, $800e
    800AB7D0	addiu  v1, v1, $42e8
    800AB7D4	addu   v0, v0, v1
    800AB7D8	slt    v0, a3, v0
    800AB7DC	beq    v0, zero, Lab934 [$800ab934]
    800AB7E0	nop
    800AB7E4	lui    at, $800e
    800AB7E8	addiu  at, at, $42ea
    800AB7EC	addu   at, at, a2
    800AB7F0	lhu    v0, $0000(at)
    800AB7F4	lui    at, $800e
    800AB7F8	addiu  at, at, $42ee
    800AB7FC	addu   at, at, a2
    800AB800	sh     t4, $0000(at)
    800AB804	addiu  v0, v0, $0001
    800AB808	sh     v0, $0012(t1)
    800AB80C	ori    v0, zero, $0007
    800AB810	sh     v0, $0000(a3)
    800AB814	lui    at, $800e
    800AB818	addiu  at, at, $42ea
    800AB81C	addu   at, at, a2
    800AB820	lh     v0, $0000(at)
    V1 = w[80074ea4 + T2 + c] >> c; // X
    800AB834	sll    a1, v0, $01
    800AB838	addu   a1, a1, v0
    V0 = bu[800e42ea + A2];
    A0 = bu[800e0638 + V0];
    800AB860	andi   a1, a1, $00ff
    800AB864	sll    v0, a0, $01
    800AB868	addu   v0, v0, a0
    800AB86C	sll    v0, v0, $02
    800AB870	addu   v1, v1, v0
    800AB874	addiu  v1, v1, $fa00 (=-$600)
    800AB878	lui    at, $800e
    800AB87C	addiu  at, at, $42e0
    800AB880	addu   at, at, a2
    800AB884	sh     v1, $0000(at)
    800AB888	lui    at, $8007
    800AB88C	addiu  at, at, $4eb4
    800AB890	addu   at, at, t2
    800AB894	lw     v1, $0000(at)
    800AB898	lui    at, $800e
    800AB89C	addiu  at, at, $0638
    800AB8A0	addu   at, at, a1
    800AB8A4	lbu    a0, $0000(at)
    800AB8A8	sra    v1, v1, $0c
    800AB8AC	sll    v0, a0, $01
    800AB8B0	addu   v0, v0, a0
    800AB8B4	sll    v0, v0, $02
    800AB8B8	addu   v1, v1, v0
    800AB8BC	lui    at, $800e
    800AB8C0	addiu  at, at, $42e0
    800AB8C4	addu   at, at, a2
    800AB8C8	lhu    v0, $0000(at)
    800AB8CC	addiu  v1, v1, $fa00 (=-$600)
    800AB8D0	lui    at, $800e
    800AB8D4	addiu  at, at, $42e2
    800AB8D8	addu   at, at, a2
    800AB8DC	sh     v1, $0000(at)
    800AB8E0	lui    at, $800e
    800AB8E4	addiu  at, at, $42e2
    800AB8E8	addu   at, at, a2
    800AB8EC	lhu    v1, $0000(at)
    800AB8F0	lui    at, $800e
    800AB8F4	addiu  at, at, $42d8
    800AB8F8	addu   at, at, a2
    800AB8FC	sh     v0, $0000(at)
    800AB900	lui    at, $800e
    800AB904	addiu  at, at, $42da
    800AB908	addu   at, at, a2
    800AB90C	sh     v1, $0000(at)
    800AB910	lui    at, $8007
    800AB914	addiu  at, at, $4eb8
    800AB918	addu   at, at, t2
    800AB91C	lw     v0, $0000(at)
    800AB920	nop
    800AB924	sra    v0, v0, $0c
    800AB928	addiu  v0, v0, $fd00 (=-$300)
    800AB92C	j      Lab948 [$800ab948]
    800AB930	sh     v0, $0000(t0)

    Lab934:	; 800AB934
    800AB934	sh     t4, $0000(a3)
    800AB938	lui    at, $800e
    800AB93C	addiu  at, at, $42ee
    800AB940	addu   at, at, a2
    800AB944	sh     zero, $0000(at)

    Lab948:	; 800AB948
    800AB948	lhu    v0, $0000(a3)
    800AB94C	lhu    v1, $0000(t0)
    800AB950	andi   v0, v0, $0007
    800AB954	sll    v0, v0, $07
    800AB958	addu   v1, v1, v0
    800AB95C	lui    at, $800e
    800AB960	addiu  at, at, $42e4
    800AB964	addu   at, at, a2
    800AB968	sh     v1, $0000(at)
    800AB96C	lhu    v0, $0000(a3)
    800AB970	lhu    v1, $0000(t0)
    800AB974	addiu  t0, t0, $0018
    800AB978	andi   v0, v0, $0007
    800AB97C	sll    v0, v0, $07
    800AB980	addiu  v0, v0, $0100
    800AB984	addu   v1, v1, v0
    800AB988	lui    at, $800e
    800AB98C	addiu  at, at, $42dc
    800AB990	addu   at, at, a2
    800AB994	sh     v1, $0000(at)
    800AB998	lhu    v0, $0000(a3)
    800AB99C	addiu  a3, a3, $0018
    800AB9A0	addiu  a2, a2, $0018
    800AB9A4	addiu  v0, v0, $ffff (=-$1)
    800AB9A8	sh     v0, $0010(t1)
    800AB9AC	lui    v0, $800e
    800AB9B0	addiu  v0, v0, $48e8
    800AB9BC	addiu  t1, t1, $0018
    800AB9B4	slt    v0, a3, v0
800AB9B8	bne    v0, zero, Lab7b4 [$800ab7b4]
////////////////////////////////



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
