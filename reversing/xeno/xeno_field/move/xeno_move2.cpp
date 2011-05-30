////////////////////////////////
// func82fb0
// seems like this function run scripts based on entity conditions
FP = A2;
S7 = 0;
script_priority = 7;
80082FE8	sw     a0, $0050(sp)
80082FEC	sw     a1, $0058(sp)

[SP + 60] = w(hu[FP + 1e] + 8);
[SP + 68] = w(hu[FP + 1e] + 20);
[SP + 70] = w(h[FP + 26]); // Y
[SP + 78] = w(h[FP + 26] - hu[FP + 1a]);


S6 = h[FP + 22]; // X
V0 = w[800ad0d4]; // number of entity
S5 = h[FP + 2a]; // Z

if (V0 >= 0)
{
    return;
}

S3 = 0;
[SP + 90] = w(SP + 10);
[SP + 80] = w(hu[FP + 106] & fff);
[SP + 88] = w(SP + 20);

L83054:	; 80083054
    script_to_call = ff;

    V1 = w[800aefe4];
    S1 = w[V1 + S3 * 5c + 4c];
    A1 = w[S1 + 0];

    if (((A1 & 1) == 0) || (bu[FP + 74] == S3))
    {
        8008309C	lh     v1, $0026(s1)
        800830A0	lh     v0, $0062(s1)
        800830A4	lw     a0, $0004(s1)
        800830A8	addu   s0, v1, v0
        800830AC	andi   v0, a0, $0180
        800830B0	beq    v0, zero, L83214 [$80083214]
        800830B4	andi   v0, a0, $0100
        800830B8	beq    v0, zero, L8320c [$8008320c]
        800830BC	nop
        V0 = hu[800c1b68] & 0020; // if we want to talk

        800830D0	beq    v0, zero, L83164 [$80083164]
        800830D4	nop
        800830D8	bne    s7, zero, L83164 [$80083164]
        800830DC	lui    v0, $0400
        800830E0	and    v0, a0, v0
        800830E4	bne    v0, zero, L83164 [$80083164]
        800830E8	lui    v0, $0022
        800830EC	and    v0, a1, v0
        800830F0	bne    v0, zero, L83214 [$80083214]
        800830F4	nop
        800830F8	lui    v0, $800b
        800830FC	lh     v0, $1648(v0)
        80083100	nop
        80083104	bne    v0, zero, L83214 [$80083214]
        80083108	nop
        8008310C	ori    s7, zero, $0001
        script_to_call = 2;
        script_priority = 3;
        80083118	lh     a1, $0022(s1)
        8008311C	lh     v0, $0060(s1)
        80083120	subu   a1, a1, s6
        80083124	addu   a1, a1, v0
        80083128	sw     a1, $0010(sp)
        8008312C	lh     a0, $002a(s1)
        80083130	lh     v0, $0064(s1)
        80083134	subu   a0, a0, s5
        80083138	addu   a0, a0, v0
        8008313C	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        80083140	sw     a0, $0018(sp)
        80083144	subu   a0, zero, v0
        80083148	addiu  t0, zero, $f1ff (=-$e01)
        8008314C	lw     v1, $012c(s1)
        80083150	andi   v0, a0, $0e00
        80083154	and    v1, v1, t0
        80083158	or     v1, v1, v0
        8008315C	j      L83214 [$80083214]
        80083160	sw     v1, $012c(s1)

        L83164:	; 80083164
        80083164	lw     v0, $0000(s1)
        80083168	lui    v1, $00a2
        8008316C	and    v0, v0, v1
        80083170	bne    v0, zero, L83214 [$80083214]
        80083174	nop
        script_to_call = 3;
        script_priority = 4;
        80083180	lh     a1, $0022(s1)
        80083184	lh     v0, $0060(s1)
        80083188	subu   a1, a1, s6
        8008318C	addu   a1, a1, v0
        80083190	sw     a1, $0010(sp)
        80083194	lh     a0, $002a(s1)
        80083198	lh     v0, $0064(s1)
        8008319C	subu   a0, a0, s5
        800831A0	addu   a0, a0, v0
        800831A4	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        800831A8	sw     a0, $0018(sp)
        800831AC	sra    v0, v0, $09
        800831B0	subu   v0, zero, v0
        800831B4	andi   a1, v0, $0007
        800831B8	addiu  t0, zero, $f1ff (=-$e01)
        800831BC	sll    v0, a1, $09
        800831C0	lw     v1, $012c(s1)
        800831C4	lui    a0, $800b
        800831C8	lw     a0, $d43c(a0)
        800831CC	and    v1, v1, t0
        800831D0	or     v1, v1, v0
        800831D4	bne    a0, zero, L83214 [$80083214]
        800831D8	sw     v1, $012c(s1)
        800831DC	lw     v0, $0000(s1)
        800831E0	lui    v1, $0800
        800831E4	and    v0, v0, v1
        800831E8	beq    v0, zero, L83214 [$80083214]
        800831EC	ori    v0, zero, $0001
        800831F0	lw     t0, $0058(sp)
        800831F4	nop
        800831F8	lw     v1, $0004(t0)
        800831FC	lui    at, $800b
        80083200	sw     v0, $d43c(at)
        80083204	j      L83214 [$80083214]
        80083208	sw     zero, $0010(v1)

        L8320c:	; 8008320C
        [800ad43c] = w(0);

        L83214:	; 80083214
        80083214	lw     v0, $0000(s1)
        80083218	nop
        8008321C	andi   v0, v0, $2000
        80083220	beq    v0, zero, L8340c [$8008340c]
        80083224	nop
        80083228	lw     t0, $0078(sp)
        8008322C	nop
        80083230	slt    v0, s0, t0
        80083234	bne    v0, zero, L836a4 [$800836a4]
        80083238	ori    v0, zero, $00ff
        8008323C	lhu    v0, $001a(s1)
        80083240	lw     t0, $0070(sp)
        80083244	subu   v0, s0, v0
        80083248	slt    v0, t0, v0
        8008324C	bne    v0, zero, L836a0 [$800836a0]
        80083250	nop
        80083254	lw     t0, $0050(sp)
        80083258	nop
        8008325C	beq    s3, t0, L836a0 [$800836a0]
        80083260	addu   a0, s6, zero
        80083264	addu   a1, s5, zero
        80083268	addu   a2, s1, zero
        8008326C	jal    func81990 [$80081990]
        80083270	ori    a3, zero, $0010
        80083274	bne    v0, zero, L836a4 [$800836a4]
        80083278	ori    v0, zero, $00ff
        8008327C	lui    v0, $800c
        80083280	lhu    v0, $1b68(v0)
        80083284	nop
        80083288	andi   v0, v0, $0020
        8008328C	beq    v0, zero, L83380 [$80083380]
        80083290	nop
        80083294	bne    s7, zero, L83380 [$80083380]
        80083298	lui    v1, $0400
        8008329C	lw     v0, $0004(s1)
        800832A0	nop
        800832A4	and    v0, v0, v1
        800832A8	bne    v0, zero, L83380 [$80083380]
        800832AC	lui    v1, $0022
        800832B0	lw     v0, $0000(s1)
        800832B4	nop
        800832B8	and    v0, v0, v1
        800832BC	bne    v0, zero, L836a4 [$800836a4]
        800832C0	ori    v0, zero, $00ff
        800832C4	lui    v0, $800b
        800832C8	lh     v0, $1648(v0)
        800832CC	nop
        800832D0	bne    v0, zero, L836a4 [$800836a4]
        800832D4	ori    v0, zero, $00ff
        800832D8	lh     a1, $0022(s1)
        800832DC	lh     v0, $0060(s1)
        800832E0	subu   a1, a1, s6
        800832E4	addu   a1, a1, v0
        800832E8	sw     a1, $0010(sp)
        800832EC	lh     a0, $002a(s1)
        800832F0	lh     v0, $0064(s1)
        800832F4	subu   a0, a0, s5
        800832F8	addu   a0, a0, v0
        800832FC	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        80083300	sw     a0, $0018(sp)
        80083304	subu   a0, zero, v0
        80083308	sra    v0, a0, $09
        8008330C	andi   a1, v0, $0007
        80083310	lw     t0, $0080(sp)
        80083314	andi   v0, a0, $0fff
        80083318	subu   v0, t0, v0
        8008331C	andi   a0, v0, $0fff
        80083320	lw     v0, $0004(s1)
        80083324	lui    v1, $0004
        80083328	and    v0, v0, v1
        8008332C	beq    v0, zero, L83340 [$80083340]
        80083330	addiu  v0, a0, $fd44 (=-$2bc)
        80083334	sltiu  v0, v0, $0a89
        80083338	bne    v0, zero, L836a4 [$800836a4]
        8008333C	ori    v0, zero, $00ff

        L83340:	; 80083340
        80083340	ori    s7, zero, $0001
        script_to_call = 2;
        script_priority = 3;
        8008334C	addiu  t0, zero, $f1ff (=-$e01)
        80083350	sll    v1, a1, $09
        80083354	lw     v0, $012c(s1)
        80083358	lui    a0, $800c
        8008335C	lw     a0, $1b60(a0)
        80083360	and    v0, v0, t0
        80083364	or     v0, v0, v1
        80083368	bne    a0, zero, L836a0 [$800836a0]
        8008336C	sw     v0, $012c(s1)
        80083370	lui    at, $8028
        80083374	sw     s7, $59dc(at)
        80083378	j      L836a4 [$800836a4]
        8008337C	ori    v0, zero, $00ff

        L83380:	; 80083380
        80083380	lw     v0, $0000(s1)
        80083384	lui    v1, $00a2
        80083388	and    v0, v0, v1
        8008338C	bne    v0, zero, L836a4 [$800836a4]
        80083390	ori    v0, zero, $00ff
        script_to_call = 3;
        script_priority = 4;
        8008339C	lh     a1, $0022(s1)
        800833A0	lh     v0, $0060(s1)
        800833A4	subu   a1, a1, s6
        800833A8	addu   a1, a1, v0
        800833AC	sw     a1, $0010(sp)
        800833B0	lh     a0, $002a(s1)
        800833B4	lh     v0, $0064(s1)
        800833B8	subu   a0, a0, s5
        800833BC	addu   a0, a0, v0
        800833C0	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
        800833C4	sw     a0, $0018(sp)
        800833C8	sra    v0, v0, $09
        800833CC	subu   v0, zero, v0
        800833D0	andi   a1, v0, $0007
        800833D4	addiu  t0, zero, $f1ff (=-$e01)
        800833D8	sll    v0, a1, $09
        800833DC	lw     v1, $012c(s1)
        800833E0	lui    a0, $800c
        800833E4	lw     a0, $1b60(a0)
        800833E8	and    v1, v1, t0
        800833EC	or     v1, v1, v0
        800833F0	bne    a0, zero, L836a0 [$800836a0]
        800833F4	sw     v1, $012c(s1)
        800833F8	ori    v0, zero, $0001
        800833FC	lui    at, $8028
        80083400	sw     v0, $59dc(at)
        80083404	j      L836a4 [$800836a4]
        80083408	ori    v0, zero, $00ff

        L8340c:	; 8008340C
        [SP + 10] = w(h[S1 + 22] + h[S1 + 60] - S6);
        [SP + 14] = w(hu[S1 + 1e] + w[SP + 68]); // solid
        [SP + 18] = w(h[S1 + 2a] + h[S1 + 64] - S5);

        IR1 = w[SP + 10];
        IR2 = w[SP + 14];
        IR3 = w[SP + 18];
        gte_SQR; // Square of vector.

        [SP + 20] = w(MAC1);
        [SP + 24] = w(MAC2);
        [SP + 28] = w(MAC3);

        V0 = w[SP + 20];
        A0 = w[SP + 24];
        V1 = w[SP + 28];
        V0 = V0 + V1;
        V0 = V0 < A0;

        8008348C	beq    v0, zero, L836a4 [$800836a4]

        80083494	lw     t0, $0078(sp)
        80083498	nop
        8008349C	slt    v0, s0, t0
        800834A0	bne    v0, zero, L836a4 [$800836a4]

        800834A8	lhu    v0, $001a(s1)
        800834AC	lw     t0, $0070(sp)
        800834B0	subu   v0, s0, v0
        800834B4	slt    v0, t0, v0
        800834B8	bne    v0, zero, L836a0 [$800836a0]
        800834BC	nop
        800834C0	lw     t0, $0050(sp)
        800834C4	nop
        800834C8	beq    s3, t0, L836a4 [$800836a4]

        800834D0	lw     a0, $0090(sp)
        800834D4	lw     a1, $0088(sp)
        800834D8	lh     v0, $0022(s1)
        800834DC	lh     v1, $0060(s1)
        800834E0	subu   v0, v0, s6
        800834E4	addu   v0, v0, v1
        800834E8	sw     v0, $0010(sp)
        800834EC	lh     v0, $002a(s1)
        800834F0	lh     v1, $0064(s1)
        800834F4	subu   v0, v0, s5
        800834F8	addu   v0, v0, v1
        800834FC	jal    system_gte_square_of_vector [$8004a2bc]
        80083500	sw     v0, $0018(sp)
        80083504	addiu  a0, sp, $0030
        80083508	addiu  a1, sp, $0040
        8008350C	lhu    v0, $001e(s1)
        80083510	lw     t0, $0060(sp)
        80083514	lw     a2, $0020(sp)
        80083518	lw     v1, $0028(sp)
        8008351C	addu   v0, t0, v0
        80083520	sw     v0, $0030(sp)
        80083524	lhu    v0, $001e(s1)
        80083528	lw     t0, $0068(sp)
        8008352C	addu   s0, a2, v1
        80083530	addu   v0, t0, v0
        80083534	jal    system_gte_square_of_vector [$8004a2bc]
        80083538	sw     v0, $0038(sp)
        8008353C	lw     v0, $0048(sp)

        if ((S0 < V0) && (hu[800c1b68] & 0020) && (S7 == 0) && ((w[S1 + 4] & 04000000) == 0))
        {
            80083580	lui    v1, $0022
            80083584	lw     v0, $0000(s1)
            80083588	nop
            8008358C	and    v0, v0, v1
            if (V0 == 0)
            {
                80083598	lw     a0, $0018(sp)
                8008359C	lw     a1, $0010(sp)
                800835A0	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]
                800835A4	nop
                800835A8	subu   a0, zero, v0
                800835AC	sra    v0, a0, $09
                800835B0	andi   a1, v0, $0007
                800835B4	lw     t0, $0080(sp)
                800835B8	andi   v0, a0, $0fff
                800835BC	subu   v0, t0, v0
                800835C0	andi   a0, v0, $0fff
                800835C4	addiu  v0, a0, $fd44 (=-$2bc)
                800835C8	sltiu  v0, v0, $0a89
                if (V0 == 0)
                {
                    800835D4	lui    v0, $800b
                    800835D8	lh     v0, $1648(v0)
                    800835DC	nop
                    if (V0 == 0)
                    {
                        800835E8	ori    s7, zero, $0001
                        script_to_call = 2;
                        script_priority = 3;
                        80083688	addiu  t0, zero, $f1ff (=-$e01)
                        8008368C	lw     v1, $012c(s1)
                        80083690	sll    v0, a1, $09
                        80083694	and    v1, v1, t0
                        80083698	or     v1, v1, v0
                        8008369C	sw     v1, $012c(s1)
                    }
                }
            }
        }
        else
        {
            80083640	lw     v0, $0000(s1)
            80083644	lui    v1, $00a2
            80083648	and    v0, v0, v1
            8008364C	bne    v0, zero, L836a4 [$800836a4]

            80083654	lw     v0, $0040(sp)
            80083658	nop
            8008365C	slt    v0, s0, v0
            80083660	beq    v0, zero, L836a4 [$800836a4]

            8008366C	lw     a0, $0018(sp)
            80083670	lw     a1, $0010(sp)
            script_to_call = 3;
            script_priority = 4;
            80083674	jal    system_get_rotation_based_on_vector_x_y [$8004b1d4]

            8008367C	sra    v0, v0, $09
            80083680	subu   v0, zero, v0
            80083684	andi   a1, v0, $0007
            80083688	addiu  t0, zero, $f1ff (=-$e01)
            8008368C	lw     v1, $012c(s1)
            80083690	sll    v0, a1, $09
            80083694	and    v1, v1, t0
            80083698	or     v1, v1, v0
            8008369C	sw     v1, $012c(s1)
        }
    }

    L836a0:	; 800836A0
    L836a4:	; 800836A4
    if (script_to_call != ff)
    {
        A0 = 0;
        loop836b4:	; 800836B4
            if( bu[S1 + 8c + A0 * 8 + 3] == script_to_call ) // script id
            {
                break;
            }
            A0 = A0 + 1;
            V0 = A0 < 8;
        800836CC	bne    v0, zero, loop836b4 [$800836b4]

        if (A0 == 8)
        {
            A0 = 0;
            loop836ec:	; 800836EC
                V1 = w[S1 + 8c + A0 * 8 + 4];
                if (((V1 >> 12) & f) == f)
                {
                    if (((V1 >> 16) & 1) == 0)
                    {
                        A0 = S3;
                        A1 = script_to_call;
                        get_script_offset;
                        [S1 + 8c + A0 * 8 + 0] = h(V0);
                        [S1 + 8c + A0 * 8 + 3] = b(script_to_call);
                        [S1 + 8c + A0 * 8 + 4] = w((w[S1 + 8c + A0 * 8 + 4] & ffc3ffff) | (script_priority << 12));

                        [S1 + 104] = h(hu[S1 + 106] | 8000);
                        [S1 + 106] = h(hu[S1 + 106] | 8000);

                        break;
                    }
                }

                A0 = A0 + 1;
                V0 = A0 < 8;
            80083718	bne    v0, zero, loop836ec [$800836ec]
        }
    }

    V0 = w[800ad0d4];
    S3 = S3 + 1;
    V0 = S3 < V0;
80083730	bne    v0, zero, L83054 [$80083054]

L83738:	; 80083738
////////////////////////////////



////////////////////////////////
// func8376c
80083774	addu   fp, a0, zero
S1 = A2;

80083780	ori    a0, zero, $0020
800837A8	sw     a1, $0048(sp)
800837A4	jal    func7c350 [$8007c350]

800837AC	lw     a2, $0020(s1)
800837B0	nop
800837B4	sw     a2, $0018(sp)
800837B8	lw     a3, $0024(s1)
800837BC	nop
800837C0	sw     a3, $001c(sp)
800837C4	lw     t0, $0028(s1)
800837C8	nop
800837CC	sw     t0, $0020(sp)
800837D0	lw     v1, $0030(s1)
800837D4	addiu  a0, sp, $0028
800837D8	addu   a2, a2, v1
800837DC	sw     a2, $0018(sp)
800837E0	lw     v1, $0034(s1)
800837E4	addiu  a1, sp, $0018
800837E8	sw     zero, $0070(sp)
800837EC	addu   a3, a3, v1
800837F0	sw     a3, $001c(sp)
800837F4	lw     v1, $0038(s1)
800837F8	addu   s3, v0, zero
800837FC	addu   t0, t0, v1
80083800	jal    func827e4 [$800827e4]
80083804	sw     t0, $0020(sp)
80083808	lh     t1, $0028(sp)
8008380C	lh     s6, $0026(s1)
80083810	lhu    v0, $001a(s1)
80083814	sw     t1, $0050(sp)
80083818	lh     t1, $002c(sp)
8008381C	subu   v0, s6, v0
80083820	sw     v0, $0060(sp)
80083824	lui    v0, $800b
80083828	lw     v0, $d0d4(v0)
8008382C	lui    s7, $7fff
80083830	sw     zero, $0078(sp)
80083834	sw     t1, $0058(sp)
80083838	lw     t1, $0000(s1)
8008383C	ori    s7, s7, $ffff
80083840	sw     t1, $0068(sp)
80083844	lbu    t1, $0074(s1)
80083850	sw     t1, $0080(sp)
S2 = 0;
if (V0 > 0)
{
    80083854	lui    t1, $ff3f
    80083858	ori    t1, t1, $ffff
    8008385C	lui    v0, $0004
    80083860	ori    v0, v0, $0800
    80083864	sw     t1, $0088(sp)
    80083868	lw     t1, $0068(sp)
    8008386C	addu   s5, zero, zero
    80083870	and    v0, t1, v0
    80083874	sw     v0, $0090(sp)

    L83878:	; 80083878
        80083878	beq    s2, fp, L83ccc [$80083ccc]
        8008387C	nop
        80083880	lui    v0, $800b
        80083884	lw     v0, $efe4(v0)
        80083888	nop
        8008388C	addu   v0, s5, v0
        A2 = w[V0 + 4c];
        A0 = w[A2 + 0];
        800838A0	andi   v0, a0, $0001
        800838A4	bne    v0, zero, L83ccc [$80083ccc]
        800838A8	lui    v1, $ffff
        S0 = A2;

        800838B0	ori    v1, v1, $3eff
        800838B4	lw     v0, $0004(s0)
        S4 = A0;
        800838BC	and    v1, v0, v1
        800838C0	andi   v0, v0, $0080
        800838C4	beq    v0, zero, L83998 [$80083998]
        800838C8	sw     v1, $0004(s0)
        800838CC	lui    v0, $800b
        800838D0	lw     v0, $efe4(v0)
        800838D4	lw     a2, $0050(sp)
        800838D8	lw     a3, $0058(sp)
        800838DC	addu   v0, s5, v0
        800838E0	lw     v1, $0000(v0)
        800838E4	addiu  v0, sp, $0040
        800838E8	sw     v0, $0010(sp)
        800838EC	addiu  v0, sp, $0030
        800838F0	sw     v0, $0014(sp)
        800838F4	lw     a1, $0004(v1)
        800838F8	jal    func8289c [$8008289c]
        800838FC	addu   a0, s2, zero
        80083900	beq    v0, zero, L83918 [$80083918]
        80083904	nop
        80083908	lw     v0, $0004(s0)
        8008390C	lw     t1, $0088(sp)
        80083910	j      L83cc8 [$80083cc8]
        80083914	and    v0, v0, t1

        L83918:	; 80083918
        80083918	lui    v0, $800c
        8008391C	lw     v0, $1b60(v0)
        80083920	nop
        80083924	bne    v0, zero, L8393c [$8008393c]
        80083928	nop
        8008392C	lui    a0, $8007
        80083930	addiu  a0, a0, $f2d8 (=-$d28)
        80083934	jal    func37870 [$80037870]
        80083938	addu   a1, s2, zero

        L8393c:	; 8008393C
        8008393C	lw     v0, $0004(s0)
        80083940	lhu    a0, $001a(s0)
        80083944	ori    v0, v0, $0100
        80083948	sw     v0, $0004(s0)
        8008394C	lw     v0, $0040(sp)
        80083950	lbu    v1, $0074(s1)
        80083954	nop
        80083958	bne    v1, s2, L83aec [$80083aec]
        8008395C	addu   a0, v0, a0
        80083960	lw     v0, $0030(sp)
        80083964	nop
        80083968	sw     v0, $0050(s1)
        8008396C	lw     v0, $0034(sp)
        80083970	nop
        80083974	sw     v0, $0054(s1)
        80083978	lw     v0, $0038(sp)
        8008397C	nop
        80083980	sw     v0, $0058(s1)
        80083984	lw     v0, $0004(s0)
        80083988	nop
        8008398C	ori    v0, v0, $4000
        80083990	j      L83acc [$80083acc]
        80083994	sw     v0, $0004(s0)

        L83998:	; 80083998
        if ((S4 & 00002000) == 0)
        {
            [S3 + 0] = w(((w[S0 + 20] + w[S0 + 30]) >> 10) - w[SP + 50]);
            [S3 + 4] = w(hu[S1 + 1e] + hu[S0 + 1e]); // solid range
            [S3 + 8] = w(((w[S0 + 28] + w[S0 + 38]) >> 10) - w[SP + 58]);

            A0 = S3 + 0;
            A1 = S3 + 10;
            system_gte_square_of_vector;

            V0 = (w[S3 + 10] + w[S3 + 18]) < w[S3 + 14];
        }
        else
        {
            A0 = w[SP + 50];
            A1 = w[SP + 58];
            A2 = S0;
            A3 = 0;
            800839AC	jal    func81990 [$80081990]
        }

        if (V0 != 0)
        {
            [S0 + 4] = w(w[S0 + 4] & w[SP + 88]);
        }
        else
        {
            if (w[S1 + 14] & 00400000)
            {
                if (w[800c1b60] == 0)
                {
                    A0 = 8006f2e8;
                    80083A7C	jal    func37870 [$80037870]
                }
            }
            else
            {
                T1 = w[SP + 68];
                80083A94	or     v0, s4, t1
                80083A98	andi   v0, v0, $0080
                80083A9C	bne    v0, zero, L83ccc [$80083ccc]
                80083AA0	nop
                80083AA4	lui    v0, $800b
                80083AA8	lbu    v0, $16a0(v0)
                80083AAC	nop
                80083AB0	bne    v0, zero, L83ccc [$80083ccc]
                80083AB4	nop
                80083AB8	lh     a0, $0026(s0)
                80083ABC	lhu    v0, $001a(s0)
                80083AC0	nop
                80083AC4	subu   v0, a0, v0
                80083AC8	sw     v0, $0040(sp)

                L83acc:	; 80083ACC
                80083ACC	lbu    v0, $0074(s1)
                80083AD0	nop
                80083AD4	bne    v0, s2, L83aec [$80083aec]
                80083AD8	nop
                80083ADC	lw     t1, $0090(sp)
                80083AE0	nop
                80083AE4	beq    t1, zero, L83b34 [$80083b34]
                80083AE8	lui    v1, $0080

                L83aec:	; 80083AEC
                80083AEC	lw     t1, $0060(sp)
                80083AF0	nop
                80083AF4	slt    v0, a0, t1
                80083AF8	bne    v0, zero, L83c74 [$80083c74]
                80083AFC	addiu  v1, zero, $feff (=-$101)
                80083B00	lw     v1, $0040(sp)
                80083B04	nop
                80083B08	slt    v0, s6, v1
                80083B0C	bne    v0, zero, L83c70 [$80083c70]
                80083B10	addiu  v0, v1, $0010
                80083B14	slt    v0, s6, v0
                80083B18	bne    v0, zero, L83b34 [$80083b34]
                80083B1C	lui    v1, $0080
                80083B20	lw     v0, $0004(s0)
                80083B24	nop
                80083B28	and    v0, v0, v1
                80083B2C	beq    v0, zero, L83b84 [$80083b84]
                80083B30	andi   v0, s4, $0010

                L83b34:	; 80083B34
                80083B34	lw     s7, $0040(sp)
                80083B38	lw     v0, $0004(s0)
                80083B3C	lw     a0, $0030(s0)
                80083B40	or     v0, v0, v1
                80083B44	sw     v0, $0004(s0)
                80083B48	sw     a0, $0040(s1)
                80083B4C	lw     v0, $0034(s0)
                80083B50	nop
                80083B54	sw     v0, $0044(s1)
                80083B58	lw     v0, $0038(s0)
                80083B5C	ori    t1, zero, $0002
                80083B60	sw     t1, $0078(sp)
                80083B64	sw     v0, $0048(s1)
                80083B68	lw     t1, $0090(sp)
                80083B6C	nop
                80083B70	bne    t1, zero, L83cbc [$80083cbc]
                80083B74	ori    t1, zero, $0001
                80083B78	sb     s2, $0074(s1)
                80083B7C	j      L83cbc [$80083cbc]
                80083B80	sw     t1, $0070(sp)

                L83b84:	; 80083B84
                80083B84	bne    v0, zero, L83c3c [$80083c3c]
                80083B88	nop
                80083B8C	lbu    v1, $00e3(s0)
                80083B90	nop
                80083B94	sltiu  v0, v1, $0030
                80083B98	beq    v0, zero, L83ba4 [$80083ba4]
                80083B9C	addiu  v0, v1, $0002
                80083BA0	sb     v0, $00e3(s0)

                L83ba4:	; 80083BA4
                80083BA4	lbu    v0, $00e3(s0)
                80083BA8	nop
                80083BAC	sltiu  v0, v0, $0021
                80083BB0	bne    v0, zero, L83c3c [$80083c3c]
                80083BB4	nop
                80083BB8	lw     v1, $0030(s1)
                80083BBC	nop
                80083BC0	bgez   v1, L83bcc [$80083bcc]
                80083BC4	nop
                80083BC8	addiu  v1, v1, $0003

                L83bcc:	; 80083BCC
                80083BCC	lw     v0, $0040(s0)
                80083BD0	sra    v1, v1, $02
                80083BD4	addu   v0, v0, v1
                80083BD8	sw     v0, $0040(s0)
                80083BDC	lw     v1, $0038(s1)
                80083BE0	nop
                80083BE4	bgez   v1, L83bf0 [$80083bf0]
                80083BE8	nop
                80083BEC	addiu  v1, v1, $0003

                L83bf0:	; 80083BF0
                80083BF0	lw     v0, $0048(s0)
                80083BF4	sra    v1, v1, $02
                80083BF8	addu   v0, v0, v1
                80083BFC	sw     v0, $0048(s0)
                80083C00	sw     zero, $0030(s1)
                80083C04	lw     v0, $0030(s1)
                80083C08	sw     zero, $0034(s1)
                80083C0C	bgez   v0, L83c18 [$80083c18]
                80083C10	sw     zero, $0038(s1)
                80083C14	addiu  v0, v0, $0003

                L83c18:	; 80083C18
                80083C18	lw     v1, $0038(s1)
                80083C1C	sra    v0, v0, $02
                80083C20	sw     v0, $0040(s1)
                80083C24	bgez   v1, L83c30 [$80083c30]
                80083C28	sw     zero, $0044(s1)
                80083C2C	addiu  v1, v1, $0003

                L83c30:	; 80083C30
                80083C30	sra    v0, v1, $02
                80083C34	j      L83cbc [$80083cbc]
                80083C38	sw     v0, $0048(s1)

                L83c3c:	; 80083C3C
                80083C3C	sw     zero, $0040(s0)
                80083C40	sw     zero, $0044(s0)
                80083C44	sw     zero, $0048(s0)
                80083C48	sw     zero, $0030(s0)
                80083C4C	sw     zero, $0034(s0)
                80083C50	sw     zero, $0038(s0)
                80083C54	sw     zero, $0030(s1)
                80083C58	sw     zero, $0034(s1)
                80083C5C	sw     zero, $0038(s1)
                80083C60	sw     zero, $0040(s1)
                80083C64	sw     zero, $0044(s1)
                80083C68	j      L83cbc [$80083cbc]
                80083C6C	sw     zero, $0048(s1)

                L83c70:	; 80083C70
                80083C70	addiu  v1, zero, $feff (=-$101)

                L83c74:	; 80083C74
                80083C74	lw     v0, $0004(s0)
                80083C78	lw     a0, $0040(sp)
                80083C7C	and    v1, v0, v1
                80083C80	slt    v0, s6, a0
                80083C84	beq    v0, zero, L83cac [$80083cac]
                80083C88	sw     v1, $0004(s0)
                80083C8C	lui    v0, $0080
                80083C90	or     v0, v1, v0
                80083C94	sw     v0, $0004(s0)
                80083C98	slt    v0, a0, s7
                80083C9C	beq    v0, zero, L83cbc [$80083cbc]
                80083CA0	nop
                80083CA4	j      L83cbc [$80083cbc]
                80083CA8	addu   s7, a0, zero

                L83cac:	; 80083CAC
                80083CAC	lui    v0, $ff7f
                80083CB0	ori    v0, v0, $ffff
                80083CB4	and    v0, v1, v0
                80083CB8	sw     v0, $0004(s0)

                L83cbc:	; 80083CBC
                80083CBC	lw     v0, $0004(s0)
                80083CC0	lui    v1, $0040
                80083CC4	or     v0, v0, v1
                [S0 + 4] = w(V0);
            }
        }

        L83ccc:	; 80083CCC
        S5 = S5 + 5c;
        S2 = S2 + 1;
        V0 = S2 < w[800ad0d4];
    80083CE0	bne    v0, zero, L83878 [$80083878]
}

80083CE8	lui    v0, $800b
80083CEC	lw     v0, $d070(v0)
80083CF0	nop
80083CF4	beq    v0, zero, L83d14 [$80083d14]
80083CF8	nop
80083CFC	lui    s7, $800b
80083D00	lw     s7, $d06c(s7)
80083D04	lw     t1, $0078(sp)
80083D08	sw     zero, $0070(sp)
80083D0C	addiu  t1, t1, $0001
80083D10	sw     t1, $0078(sp)

L83d14:	; 80083D14
80083D14	lw     t1, $0070(sp)
80083D18	nop
80083D1C	bne    t1, zero, L83d2c [$80083d2c]
80083D20	ori    v0, zero, $00ff
80083D24	j      L83e68 [$80083e68]
80083D28	sb     v0, $0074(s1)

L83d2c:	; 80083D2C
80083D2C	lbu    v1, $0074(s1)
80083D30	nop
80083D34	sll    v0, v1, $01
80083D38	addu   v0, v0, v1
80083D3C	sll    v0, v0, $03
80083D40	subu   v0, v0, v1
80083D44	lui    v1, $800b
80083D48	lw     v1, $efe4(v1)
80083D4C	sll    v0, v0, $02
80083D50	addu   v0, v0, v1
80083D54	lw     v1, $004c(v0)
80083D58	nop
80083D5C	lw     v0, $0004(v1)
80083D60	nop
80083D64	ori    v0, v0, $8000
80083D68	sw     v0, $0004(v1)
80083D6C	lw     t1, $0080(sp)
80083D70	ori    v0, zero, $00ff
80083D74	bne    t1, v0, L83e68 [$80083e68]
80083D78	nop
80083D7C	lw     v0, $0134(s1)
80083D80	nop
80083D84	andi   v0, v0, $0080
80083D88	bne    v0, zero, L83da8 [$80083da8]
80083D8C	ori    a0, zero, $000c
80083D90	jal    system_memory_allocate [$800319ec]
80083D94	addu   a1, zero, zero
80083D98	lw     v1, $0134(s1)
80083D9C	sw     v0, $0110(s1)
80083DA0	ori    v1, v1, $0080
80083DA4	sw     v1, $0134(s1)

L83da8:	; 80083DA8
80083DA8	lbu    v1, $0074(s1)
80083DAC	nop
80083DB0	sll    v0, v1, $01
80083DB4	addu   v0, v0, v1
80083DB8	sll    v0, v0, $03
80083DBC	subu   v0, v0, v1
80083DC0	lui    v1, $800b
80083DC4	lw     v1, $efe4(v1)
80083DC8	sll    v0, v0, $02
80083DCC	addu   v0, v0, v1
80083DD0	lw     v1, $0110(s1)
80083DD4	lhu    v0, $0050(v0)
80083DD8	nop
80083DDC	sh     v0, $0000(v1)
80083DE0	lbu    v1, $0074(s1)
80083DE4	nop
80083DE8	sll    v0, v1, $01
80083DEC	addu   v0, v0, v1
80083DF0	sll    v0, v0, $03
80083DF4	subu   v0, v0, v1
80083DF8	lui    v1, $800b
80083DFC	lw     v1, $efe4(v1)
80083E00	sll    v0, v0, $02
80083E04	addu   v0, v0, v1
80083E08	lw     v1, $0110(s1)
80083E0C	lhu    v0, $0052(v0)
80083E10	nop
80083E14	sh     v0, $0002(v1)
80083E18	lbu    v1, $0074(s1)
80083E1C	nop
80083E20	sll    v0, v1, $01
80083E24	addu   v0, v0, v1
80083E28	sll    v0, v0, $03
80083E2C	subu   v0, v0, v1
80083E30	lui    v1, $800b
80083E34	lw     v1, $efe4(v1)
80083E38	sll    v0, v0, $02
80083E3C	addu   v0, v0, v1
80083E40	lw     v1, $0110(s1)
80083E44	lhu    v0, $0054(v0)
80083E48	nop
80083E4C	sh     v0, $0004(v1)
80083E50	lbu    a1, $0074(s1)
80083E54	jal    func81bc0 [$80081bc0]
80083E58	addu   a0, fp, zero
80083E5C	lw     v1, $0110(s1)
80083E60	nop
80083E64	sh     v0, $0008(v1)

L83e68:	; 80083E68
80083E68	lw     v0, $0000(s1)
80083E6C	lui    v1, $0001
80083E70	and    v0, v0, v1
80083E74	bne    v0, zero, L83eb0 [$80083eb0]
80083E78	sll    v0, fp, $01
80083E7C	lw     v0, $0004(s1)
80083E80	lui    v1, $0020
80083E84	and    v0, v0, v1
80083E88	bne    v0, zero, L83eb0 [$80083eb0]
80083E8C	sll    v0, fp, $01
80083E90	lw     t1, $0078(sp)
80083E94	addu   a0, fp, zero
80083E98	addu   a1, s7, zero
80083E9C	lw     a2, $0048(sp)
80083EA0	addu   a3, s1, zero
80083EA4	jal    func84054 [$80084054]
80083EA8	sw     t1, $0010(sp)
80083EAC	sll    v0, fp, $01

L83eb0:	; 80083EB0
80083EB0	addu   v0, v0, fp
80083EB4	sll    v0, v0, $03
80083EB8	subu   v0, v0, fp
80083EBC	lui    v1, $800b
80083EC0	lw     v1, $efe4(v1)
80083EC4	sll    v0, v0, $02
80083EC8	addu   v0, v0, v1
80083ECC	lw     v0, $0004(v0)
80083ED0	nop
80083ED4	lw     v0, $007c(v0)
80083ED8	nop
80083EDC	lhu    v1, $000c(v0)
80083EE0	ori    v0, zero, $0001
80083EE4	bne    v1, v0, L83f04 [$80083f04]
80083EE8	nop
80083EEC	jal    func35c84 [$80035c84]
80083EF0	nop
80083EF4	lw     v0, $0000(s1)
80083EF8	addiu  v1, zero, $f7ff (=-$801)
80083EFC	and    v0, v0, v1
80083F00	sw     v0, $0000(s1)

L83f04:	; 80083F04
80083F04	jal    func7c374 [$8007c374]
80083F08	ori    a0, zero, $0020
////////////////////////////////
