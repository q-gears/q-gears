////////////////////////////////
// func475d8
// make move vector
S4 = A0;
S3 = 0;
S5 = 1e; // default speed of movement

S2 = 8000;

S7 = S3;


A0 = SP + 10; // address
A1 = 0; // memset with this
A2 = 8; // length
system_memory_allocate_and_set;

func4e8d4;
S6 = V0;

8004762C	lui    v1, $8007

80047634	lw     v1, $3940(v1)
80047638	addiu  v0, zero, $0007
8004763C	srl    v1, v1, $0c
80047640	andi   v1, v1, $000f
80047644	bne    v1, v0, L47704 [$80047704]

S1 = bu[80073938 + 2];
S0 = bu[80073938 + 3];

80047658	jal    func19750 [$80019750]
8004765C	addiu  a0, sp, $0018
80047660	lbu    v0, $001a(sp)
80047664	nop
80047668	slt    v0, s1, v0
8004766C	bne    v0, zero, L476b0 [$800476b0]
80047670	nop
80047674	lbu    v0, $001b(sp)
80047678	nop
8004767C	slt    v0, v0, s1
80047680	bne    v0, zero, L476b0 [$800476b0]
80047684	nop
80047688	lbu    v0, $0018(sp)
8004768C	nop
80047690	slt    v0, s0, v0
80047694	bne    v0, zero, L476b0 [$800476b0]
80047698	nop
8004769C	lbu    v0, $0019(sp)
800476A0	nop
800476A4	slt    v0, v0, s0
800476A8	beq    v0, zero, L476b4 [$800476b4]
800476AC	nop

L476b0:	; 800476B0
800476B0	addiu  s7, zero, $0001

L476b4:	; 800476B4
800476B4	beq    s7, zero, L4770c [$8004770c]

S1 = S1 - 80;
A0 = S1;
S0 = 80 - S0;
S1 = S1 * S1;
A1 = S0;
system_get_rotation_by_vector_x_y; // rotation related

S2 = V0; // rotation

A1 = S0 * S0;

if (A1 < S1)
{
    A1 = S1;
}

V0 = A1 * 3c;
S5 = V0 >> e;

L47704:	; 80047704
if (S7 == 0)
{
    L4770c:	; 8004770C
    V0 = w[8006794c];

    V0 = (w[V0 + 24] >> 6) & 1
    V1 = S6 & 10000;

    if (V1 != 0 && V0 == 0) || (V1 == 0 && V0 != 0))
    {
        S5 = 3c;
    }

    if (S6 & 0080)
    {
        S2 = 400;
    }
    if (S6 & 0020)
    {
        S2 = -400;
    }

    if (S6 & 0040)
    {
        if (S2 == 8000)
        {
            S2 = 0;
        }
        else
        {
            S2 = S2 - S2 / 2;
        }
    }

    8004778C	andi   v0, s6, $0010
    80047790	beq    v0, zero, L477ac [$800477ac]
    80047794	ori    v0, zero, $8000
    80047798	bne    s2, v0, L477a8 [$800477a8]
    8004779C	sra    v0, s2, $01
    800477A0	j      L477ac [$800477ac]
    800477A4	addiu  s2, zero, $0800

    L477a8:	; 800477A8
    800477A8	addu   s2, s2, v0

    L477ac:	; 800477AC
}

800477AC	lui    v0, $8008
800477B0	xori   v1, s2, $8000
800477B4	sltu   v1, zero, v1
800477B8	sw     v1, $aeac(v0)

if (S2 != 8000)
{
    V0 = w[8007aecc];

    if (S7 != 0)
    {
        V0 = h[V0 + 16e8];
    }
    else
    {
        V0 = h[V0 + 16ea];
    }

    S2 = S2 + V0;
    800477F8	lhu    v0, $0022(s4)
    800477FC	andi   s2, s2, $0fff
    80047800	andi   v1, v0, $0fff
    80047804	subu   a0, s2, v1
    80047808	slti   v0, a0, $f801 (=-$7ff)
    8004780C	beq    v0, zero, L4781c [$8004781c]
    80047810	slti   v0, a0, $0800
    80047814	j      L47828 [$80047828]
    80047818	addiu  v1, v1, $f000 (=-$1000)

    L4781c:	; 8004781C
    8004781C	bne    v0, zero, L4782c [$8004782c]
    80047820	addu   v0, v1, s2
    80047824	addiu  v1, v1, $1000

    L47828:	; 80047828
    80047828	addu   v0, v1, s2

    L4782c:	; 8004782C
    8004782C	sra    v0, v0, $01
    80047830	lui    v1, $8008
    80047834	lw     v1, $aecc(v1)
    80047838	andi   v0, v0, $0fff
    8004783C	sh     v0, $0022(s4)
    80047840	lbu    v0, $16f8(v1)

    if (S5 >= 1f)
    {
        [8007aec4] = w(w[8007aec4] + 2);
    }
    else
    {
        S5 = 1e;
        [8007aec4] = w(w[8007aec4] + 1);
    }

    [S4 + 5c] = b(S5);
    [SP + 14] = h(-S5); // move length

    A0 = SP + 10
    A1 = 0; // x rotation
    A2 = S2; // y rotation
    system_rotate_vector_by_x_y_axis;

    [S4 + 14] = w(w[S4 + 14] + h[SP + 10]);
    [S4 + 1c] = w(w[S4 + 1c] + h[SP + 14]);

    A0 = S4;
    A1 = 0;
    A2 = SP + 20;
    system_check_entity_collisions;

    S3 = V0; // pointer to collided entity data?

    V0 = bu[S3 + f];

    V0 = V0 >> 4;
    V0 = V0 XOR 1;
    V0 = V0 & 1;

    [8007aeb4] = w(V0);


    if (V0 == 0)
    {
        [8007aeb0] = w(0);
    }

    if (S3 != 0)
    {
        if (w[SP + 20] <= 0 && w[8007aeb0] >= 0)
        {
            A0 = S4;
            A1 = S3;
            A2 = S2;
            [S4 + 98] = w(S3);
            [S4 + 9c] = w(w[SP + 20]);
            system_get_how_much_we_need_rotate_to_face_entity;

            if (V0 + 400 < 801)
            {
                [S4 + 14] = w(w[S4 + 14] - h[SP + 10]); // change
                [S4 + 1c] = w(w[S4 + 1c] - h[SP + 14]);

                A0 = V0;
                system_get_sin_by_rotation;

                [SP + 10] = h[(h[SP + 10] * V0) >> d];
                [SP + 14] = h[(h[SP + 14] * V0) >> d];

                A0 = SP + 10;
                A1 = 0;
                A2 = 400;
                system_rotate_vector_by_x_y_axis;

                [S4 + 14] = w(w[S4 + 14] + h[SP + 10]);
                [S4 + 1c] = w(w[S4 + 1c] + h[SP + 14]);

                A0 = S4;
                A1 = 0;
                A2 = SP + 20;
                system_check_entity_collisions;

                if (V0 != 0 && w[SP + 20] <= 0)
                {
                    [S4 + 14] = w(w[S4 + 14] - h[SP + 10]);
                    [S4 + 1c] = w(w[S4 + 1c] - h[SP + 14]);
                }

                [8007aea8] = w(2);
            }
        }
    }
}



if (w[8007aea8] != 0)
{
    if (w[8007aeb0] >= 19)
    {
        [8007aeb0] = w(-19);
    }
    else
    {
        [8007aeb0] = w(w[8007aeb0] + w[8007aeb4]);
    }
}
else
{
    if (w[8007aeb0] < 0)
    {
        [8007aeb0] = w(w[8007aeb0] + 1);
    }
    else
    {
        [8007aeb0] = w(0);
    }
}
////////////////////////////////
