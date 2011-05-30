////////////////////////////////
// func83f40
if( ( w[A0 + 14] & 00420000 ) == 0 && 
    w[800ad070] == 0 &&
    w[A0 + 30] == 0 && // X
    w[A0 + 34] == 0 && // Y
    w[A0 + 38] == 0 && // Z
    w[800ad0e4] == 1 &&
    bu[A0 + 74] == ff &&
    (w[A0 + 0] & 00401800) == 0 &&
    ((w[A0 + 4] & 00000001) == 0 || h[A0 + 10] != 0) &&
    ((w[A0 + 4] & 00000002) == 0 || h[A0 + 10] != 1))
{
    if ((w[A0 + 4] & 00000004) == 0)
    {
        return 0;
    }

    return (h[A0 + 10] ^ 0002) < 1; // -1 if but 0x0002 set, 0 otherwise
}

return -1;
////////////////////////////////



////////////////////////////////
// func821cc
S5 = A0; // entity id
S6 = A1; // 80114f2c 5c structure
S0 = A2; // total entity data
S2 = h[S0 + 104];
S3 = w[S6 + 4];
[80065198] = w(S5);

if( ( w[S0 + 0] & 01000000) == 0 )
{
    animation_id = 1;

    if( ( w[S0 + 0] & 00004000 ) && ( hu[800af370] & 0040 ) && ( w[800ad040] == 1 ) )
    {
        animation_id = 2;
    }

    V1 = h[S0 + e8]
    if( ( w[S0 + 0] & 00001800 ) && ( V1 != animation_id ) )
    {
        if( V1 == 1 || V1 == 2 )
        {
            animation_id = V1;
        }
    }

    if( bu[S0 + e3] >= 9 )
    {
        [S0 + e3] = b(bu[S0 + e3] - 1);
    }

    S1 = w[S0 + 40] | w[S0 + 44] | w[S0 + 48];

    A0 = S0;
    func83f40;

    if( V0 == -1 )
    {
        S1 = 1;
    }

    if( ( S2 & 8000 ) == 0 || S1 != 0 || ( w[S0 + 0] & 00040800 ) != 0 )
    {
        if( ( S2 & 8000 ) == 0 )
        {
            A0 = S3;
            A1 = S2 & ffff;
            A2 = S6;
            func81594;

            [SP + 10] = w(w[S3 + c] + w[S0 + 40]);
            [SP + 14] = w(w[S3 + 10] + w[S0 + 44]);
            [SP + 18] = w(w[S3 + 14] + w[S0 + 48]);

            [S0 + 106] = h(S2);
        }
        else
        {
            [SP + 10] = w(w[S0 + 40]);
            [SP + 14] = w(w[S0 + 44]);
            [SP + 18] = w(w[S0 + 48]);

            S2 = hu[S0 + 106] & 0fff;
        }

        A0 = SP + 10;
        A1 = S0;
        func81aa8; // check if we in some triangle

        if (V0 == 0) 
        {
            if (w[SP + 10] != 0 || w[SP + 18] != 0)
            {
                A0 = w[SP + 18];
                A1 = w[SP + 10];
                system_get_rotation_based_on_vector_x_y;

                V0 = 0 - V0;
                S2 = V0 & 0fff;
            }

            A0 = -1;

            V0 = h[S0 + 10]; // walkmesh_id
            if( h[S0 + 8 + V0 * 2] != -1 ) // if triangle id exist
            {
                S1 = w[S0 + 0];
                if( S5 == w[800b1740] ) // if current entity - party leader
                {
                    if( w[80059ad8] != ff || w[80059adc] != ff )
                    {
                        V1 = w[800aefe4];
                        V0 = w[V1 + V0 * 5c + 4c];
                        [S0 + 0] = w(w[S0 + 0] | (w[V0 + 0] & 00000600));
                    }
                }

                A0 = SP + 10; // move vector
                A1 = S0; // entity structure
                A2 = SP + 20; // address to store line that we can't intersect
                A3 = S2 & ffff;

                if ((w[S0 + 0] & 00041800) == 0 && bu[S0 + 74] == ff && w[800ad070] == 0)
                {
                    // we move here
                    func7b0d4;
                }
                else
                {
                    func7ae28;
                }

                A0 = V0;
                [S0 + 0] = w((w[S0 + 0] & fffff9ff) | (S1 & 00000600));
            }

            if (A0 == -1) // if we can't move
            {
                [S0 + f0] = w(00010000);
                [S0 + 40] = w(0);
                [S0 + 44] = w(0);
                [S0 + 48] = w(0);
                [SP + 10] = w(0);
                [SP + 14] = w(0);
                [SP + 18] = w(0);
                [S3 + c] = w(0);
                [S3 + 14] = w(0);
                [S0 + 106] = h(hu[S0 + 106] | 8000);
            }
        }
        else
        {
            [S0 + f0] = w(00010000);
            [S0 + 40] = w(0);
            [S0 + 44] = w(0);
            [S0 + 48] = w(0);
            [SP + 10] = w(0);
            [SP + 14] = w(0);
            [SP + 18] = w(0);
            [S3 + c] = w(0);
            [S3 + 14] = w(0);
            [S0 + 106] = h(hu[S0 + 106] | 8000);
        }
    }
    else
    {
        animation_id = hu[S0 + e6];

        [S0 + 40] = w(0);
        [S0 + 44] = w(0);
        [S0 + 48] = w(0);
        [S0 + f0] = w(00010000);
        [S0 + 104] = h(hu[S0 + 104] | 8000);
        [S0 + 106] = h(hu[S0 + 106] | 8000);

        [SP + 10] = w(0);
        [SP + 14] = w(0);
        [SP + 18] = w(0);

        [S3 + c] = w(0);
        [S3 + 14] = w(0);
    }

    [S0 + 4] = w(w[S0 + 4] & ffffefff);

    if (w[S0 + 0] & 00000800)
    {
        if (h[800b1818] == 0)
        {
            if (h[S3 + 6] != h[S3 + 84])
            {
                if (animation_id == 2)
                {
                    [S3 + 18] = w(h[S3 + 82] * 60);
                }
                else
                {
                    [S3 + 18] = w(h[S3 + 82] * 30);
                }
            }
            else
            {
                [S3 + 18] = w(0);
            }
        }

        animation_id = hu[800b181a];
    }
    else
    {
        if (h[S0 + 104] & 8000)
        {
            [S0 + e6] = hu(animation_id);
        }

        A0 = S0;
        func7ff7c;

        if (V0 & 00200000)
        {
            V0 = h[S0 + 104];
            if (V0 & 8000)
            {
                V1 = h[S0 + e8];
                if (V1 == 6)
                {
                    [S0 + 4] = w(w[S0 + 4] | 00001000)
                }
            }

            animation_id = 6;
        }
    }

    V1 = h[S0 + ea]; // animation related
    if (V1 != ff)
    {
        animation_id = V1;
    }

    if (h[S0 + e8] != animation_id)
    {
        if ((w[S0 + 0] & 02000000) == 0)
        {
            [S0 + e8] = h(animation_id);
            A0 = S3;
            A1 = animation_id;
            A2 = S6;
            func81808;
        }
    }

    if (w[S0 + 14] & 00000100)
    {
        [SP + 10] = w(w[SP + 10] / 2);
        [SP + 18] = w(w[SP + 18] / 2);
    }

    [S0 + 30] = w(w[SP + 10]);
    [S0 + 34] = w(w[SP + 14]);
    [S0 + 38] = w(w[SP + 18]);

    [S0 + 40] = w(0);
    [S0 + 44] = w(0);
    [S0 + 48] = w(0);
}
////////////////////////////////



////////////////////////////////
// func84054
80084054	addiu  sp, sp, $ff00 (=-$100)
80084058	sw     s6, $00f0(sp)
8008405C	addu   s6, a0, zero
80084060	sw     s7, $00f4(sp)
80084064	addu   s7, a1, zero
80084068	sw     s1, $00dc(sp)
8008406C	sll    v0, s6, $01
80084070	addu   v0, v0, s6
80084074	sll    v0, v0, $03
80084078	subu   v0, v0, s6
8008407C	lui    v1, $800b
80084080	lw     v1, $efe4(v1)
80084084	lui    a1, $800b
80084088	lw     a1, $1740(a1)
8008408C	sll    v0, v0, $02
80084090	sw     ra, $00fc(sp)
80084094	sw     fp, $00f8(sp)
80084098	sw     s5, $00ec(sp)
8008409C	sw     s4, $00e8(sp)
800840A0	sw     s3, $00e4(sp)
800840A4	sw     s2, $00e0(sp)
800840A8	sw     s0, $00d8(sp)
800840AC	addu   v0, v0, v1
800840B0	lw     s5, $0004(v0)
800840B4	bne    s6, a1, L840c8 [$800840c8]
800840B8	addu   s1, a3, zero
800840BC	ori    v0, zero, $ffff
800840C0	lui    at, $800b
800840C4	sh     v0, $cfd8(at)

L840c8:	; 800840C8
800840C8	lw     a0, $0000(s1)
800840CC	lui    v0, $0100
800840D0	and    v0, a0, v0
800840D4	bne    v0, zero, L84ab0 [$80084ab0]
800840D8	addiu  v0, zero, $ffff (=-$1)
800840DC	lw     v0, $0004(s1)
800840E0	lui    v1, $0020
800840E4	and    v0, v0, v1
800840E8	bne    v0, zero, L84ab0 [$80084ab0]
800840EC	addiu  v0, zero, $ffff (=-$1)
800840F0	lui    v0, $0001
800840F4	and    v0, a0, v0
800840F8	bne    v0, zero, L84150 [$80084150]
800840FC	nop
80084100	bne    s6, a1, L8411c [$8008411c]
80084104	ori    v0, zero, $0001
80084108	lui    v1, $800b
8008410C	lbu    v1, $16a3(v1)
80084110	nop
80084114	beq    v1, v0, L84158 [$80084158]
80084118	nop

L8411c:	; 8008411C
8008411C	lw     v0, $0010(s5)
80084120	nop
80084124	bne    v0, zero, L84158 [$80084158]
80084128	nop
8008412C	jal    func83f40 [$80083f40]
80084130	addu   a0, s1, zero
80084134	bne    v0, zero, L84158 [$80084158]
80084138	nop
8008413C	lh     v1, $0084(s5)
80084140	lh     v0, $0026(s1)
80084144	nop
80084148	bne    v1, v0, L84158 [$80084158]
8008414C	nop

L84150:	; 80084150
80084150	j      L84ab0 [$80084ab0]
80084154	addiu  v0, zero, $ffff (=-$1)

L84158:	; 80084158
80084158	lw     v0, $0020(s1)
8008415C	addu   s0, zero, zero
80084160	sw     v0, $0090(sp)
80084164	lw     v0, $0024(s1)
80084168	addu   a0, s1, zero
8008416C	sw     v0, $0094(sp)
80084170	lw     v0, $0028(s1)
80084174	addiu  v1, sp, $0018
80084178	sw     v0, $0098(sp)
8008417C	lhu    fp, $0010(s1)

loop84180:	; 80084180
80084180	lhu    v0, $0008(a0)
80084184	addiu  a0, a0, $0002
80084188	addiu  s0, s0, $0001
8008418C	sh     v0, $0088(v1)
80084190	slti   v0, s0, $0004
80084194	bne    v0, zero, loop84180 [$80084180]
80084198	addiu  v1, v1, $0002
8008419C	addu   s0, zero, zero
800841A0	lui    a0, $7fff
800841A4	ori    a0, a0, $ffff
800841A8	addiu  v1, sp, $0018

loop841ac:	; 800841AC
800841AC	sw     s0, $0020(v1)
800841B0	sw     a0, $0000(v1)
800841B4	sw     a0, $0010(v1)
800841B8	addiu  s0, s0, $0001
800841BC	slti   v0, s0, $0004
800841C0	bne    v0, zero, loop841ac [$800841ac]
800841C4	addiu  v1, v1, $0004
800841C8	lui    v0, $800b
800841CC	lh     v0, $f028(v0)
800841D0	nop
800841D4	addiu  v0, v0, $ffff (=-$1)
800841D8	blez   v0, L84240 [$80084240]
800841DC	addu   s4, zero, zero
800841E0	addiu  s3, sp, $0048
800841E4	addiu  s2, sp, $0050
800841E8	addiu  s0, sp, $0018

loop841ec:	; 800841EC
800841EC	addu   a0, s1, zero
800841F0	addu   a1, s4, zero
800841F4	sll    v1, s4, $02
800841F8	addiu  v0, sp, $0028
800841FC	addu   v0, v0, v1
80084200	addu   a2, s0, zero
80084204	addu   a3, s2, zero
80084208	sw     s3, $0010(sp)
8008420C	jal    func7c9e8 [$8007c9e8]
80084210	sw     v0, $0014(sp)
80084214	bne    v0, zero, L84240 [$80084240]
80084218	nop
8008421C	addiu  s3, s3, $0002
80084220	addiu  s2, s2, $0010
80084224	lui    v0, $800b
80084228	lh     v0, $f028(v0)
8008422C	addiu  s4, s4, $0001
80084230	addiu  v0, v0, $ffff (=-$1)
80084234	slt    v0, s4, v0
80084238	bne    v0, zero, loop841ec [$800841ec]
8008423C	addiu  s0, s0, $0004

L84240:	; 80084240
80084240	lw     v0, $0004(s1)
80084244	nop
80084248	andi   v0, v0, $0001
8008424C	beq    v0, zero, L84260 [$80084260]
80084250	lui    v0, $7fff
80084254	ori    v0, v0, $ffff
80084258	sw     v0, $0018(sp)
8008425C	sw     v0, $0028(sp)

L84260:	; 80084260
80084260	lw     v0, $0004(s1)
80084264	nop
80084268	andi   v0, v0, $0002
8008426C	beq    v0, zero, L84280 [$80084280]
80084270	lui    v0, $7fff
80084274	ori    v0, v0, $ffff
80084278	sw     v0, $001c(sp)
8008427C	sw     v0, $002c(sp)

L84280:	; 80084280
80084280	lw     v0, $0004(s1)
80084284	nop
80084288	andi   v0, v0, $0004
8008428C	beq    v0, zero, L842a0 [$800842a0]
80084290	lui    v0, $7fff
80084294	ori    v0, v0, $ffff
80084298	sw     v0, $0020(sp)
8008429C	sw     v0, $0030(sp)

L842a0:	; 800842A0
800842A0	addu   s0, zero, zero
800842A4	addiu  v0, sp, $0018
800842A8	addu   t1, v0, zero
800842AC	addiu  t3, sp, $002c
800842B0	lh     v0, $0010(s1)
800842B4	addiu  t2, sp, $003c
800842B8	sll    v0, v0, $02
800842BC	addu   v0, v0, t1
800842C0	lw     t4, $0000(v0)

loop842c4:	; 800842C4
800842C4	addu   t0, zero, zero
800842C8	addu   a3, t2, zero
800842CC	addu   a2, t3, zero
800842D0	addu   v1, t1, zero

loop842d4:	; 800842D4
800842D4	lw     a0, $0000(v1)
800842D8	lw     a1, $0004(v1)
800842DC	nop
800842E0	slt    v0, a1, a0
800842E4	beq    v0, zero, L84314 [$80084314]
800842E8	nop
800842EC	lw     v0, $0010(v1)
800842F0	sw     a0, $0004(v1)
800842F4	sw     a1, $0000(v1)
800842F8	lw     a0, $0000(a2)
800842FC	sw     v0, $0000(a2)
80084300	lw     v0, $0020(v1)
80084304	sw     a0, $0010(v1)
80084308	lw     a0, $0000(a3)
8008430C	sw     v0, $0000(a3)
80084310	sw     a0, $0020(v1)

L84314:	; 80084314
80084314	addiu  a3, a3, $0004
80084318	addiu  a2, a2, $0004
8008431C	addiu  t0, t0, $0001
80084320	slti   v0, t0, $0002
80084324	bne    v0, zero, loop842d4 [$800842d4]
80084328	addiu  v1, v1, $0004
8008432C	addiu  s0, s0, $0001
80084330	slti   v0, s0, $0002
80084334	bne    v0, zero, loop842c4 [$800842c4]
80084338	nop

A1 = 800af028;
V0 = h[A1];
V0 = V0 - 1;

80084350	bne    s4, v0, L845e0 [$800845e0]
80084354	nop
if (S4 > 0)
{
    S0 = 0;
    A0 = SP + 18;
    V1 = S1;

    loop84368:	; 80084368
        V0 = hu[A0 + 30];
        A0 = A0 + 2;
        S0 = S0 + 1;
        [V1 + 8] = h(V0);

        V1 = V1 + 2;

        V0 = h[A1 + 0];
        V0 = V0 - 1;
        V0 = S0 < V0;
    80084388	bne    v0, zero, loop84368 [$80084368]
}

80084390	lh     a0, $0026(s1)
80084394	nop
80084398	slt    v0, a0, t4
8008439C	bne    v0, zero, L843b8 [$800843b8]
800843A0	nop
800843A4	lw     v0, $0000(s1)
800843A8	nop
800843AC	andi   v0, v0, $1800
800843B0	beq    v0, zero, L84414 [$80084414]
800843B4	nop

L843b8:	; 800843B8
800843B8	lui    v0, $800b
800843BC	lh     v0, $f028(v0)
800843C0	nop
800843C4	addiu  v0, v0, $ffff (=-$1)
800843C8	blez   v0, L84458 [$80084458]
800843CC	addu   s0, zero, zero
800843D0	addu   a2, v0, zero
800843D4	addiu  a1, sp, $0018

loop843d8:	; 800843D8
800843D8	addu   v1, a1, zero
800843DC	lw     v0, $0000(v1)
800843E0	nop
800843E4	slt    v0, v0, a0
800843E8	beq    v0, zero, L84408 [$80084408]
800843EC	nop
800843F0	addiu  s0, s0, $0001
800843F4	slt    v0, s0, a2
800843F8	bne    v0, zero, loop843d8 [$800843d8]
800843FC	addiu  a1, v1, $0004
80084400	j      L84458 [$80084458]
80084404	nop

L84408:	; 80084408
80084408	lw     v0, $0020(a1)
8008440C	j      L84458 [$80084458]
80084410	sh     v0, $0010(s1)

L84414:	; 80084414
80084414	lui    v0, $800b
80084418	lh     v0, $f028(v0)
8008441C	nop
80084420	addiu  v0, v0, $ffff (=-$1)
80084424	blez   v0, L84458 [$80084458]
80084428	addu   s0, zero, zero
8008442C	lh     a1, $0010(s1)
80084430	addu   a0, v0, zero
80084434	addiu  v1, sp, $0018

loop84438:	; 80084438
80084438	lw     v0, $0020(v1)
8008443C	nop
80084440	beq    a1, v0, L84458 [$80084458]
80084444	nop
80084448	addiu  s0, s0, $0001
8008444C	slt    v0, s0, a0
80084450	bne    v0, zero, loop84438 [$80084438]
80084454	addiu  v1, v1, $0004

L84458:	; 80084458
80084458	jal    func7ff7c [$8007ff7c]
8008445C	addu   a0, s1, zero
80084460	andi   v0, v0, $0004
80084464	beq    v0, zero, L844a4 [$800844a4]
80084468	nop
8008446C	beq    s0, zero, L844a4 [$800844a4]
80084470	nop
80084474	lui    v0, $800b
80084478	lh     v0, $f028(v0)
8008447C	lh     v1, $0010(s1)
80084480	addiu  v0, v0, $ffff (=-$1)
80084484	slt    v0, v0, v1
80084488	bne    v0, zero, L844a4 [$800844a4]
8008448C	addiu  s0, s0, $ffff (=-$1)
80084490	sll    v0, s0, $02
80084494	addu   v0, sp, v0
80084498	lw     v0, $0038(v0)
8008449C	nop
800844A0	sh     v0, $0010(s1)

L844a4:	; 800844A4
800844A4	jal    func7ff7c [$8007ff7c]
800844A8	addu   a0, s1, zero
800844AC	lw     v1, $0000(s1)
800844B0	addu   a1, v0, zero
800844B4	srl    v0, a1, $05
800844B8	srl    v1, v1, $08
800844BC	andi   v1, v1, $0007
800844C0	and    v1, v1, v0
800844C4	beq    v1, zero, L844f0 [$800844f0]
800844C8	lui    v0, $0080
800844CC	lui    v0, $800c
800844D0	lw     v0, $1b60(v0)
800844D4	nop
800844D8	bne    v0, zero, L84520 [$80084520]
800844DC	nop
800844E0	lui    a0, $8007
800844E4	addiu  a0, a0, $f2f0 (=-$d10)
800844E8	j      L84518 [$80084518]
800844EC	nop

L844f0:	; 800844F0
800844F0	and    v0, a1, v0
800844F4	beq    v0, zero, L84560 [$80084560]
800844F8	nop
800844FC	lui    v0, $800c
80084500	lw     v0, $1b60(v0)
80084504	nop
80084508	bne    v0, zero, L84520 [$80084520]
8008450C	nop
80084510	lui    a0, $8007
80084514	addiu  a0, a0, $f304 (=-$cfc)

L84518:	; 80084518
80084518	jal    func37870 [$80037870]
8008451C	addu   a1, s6, zero

L84520:	; 80084520
80084520	lui    v0, $800b
80084524	lw     v0, $1740(v0)
80084528	nop
8008452C	bne    s6, v0, L8453c [$8008453c]
80084530	ori    v0, zero, $0fff
80084534	lui    at, $800b
80084538	sh     v0, $cfd8(at)

L8453c:	; 8008453C
8008453C	lw     v0, $0024(s1)
80084540	lw     v1, $0010(s5)
80084544	nop
80084548	addu   v0, v0, v1
8008454C	j      L849ac [$800849ac]
80084550	sw     v0, $0024(s1)

loop84554:	; 80084554
80084554	lw     v0, $0000(v1)
80084558	j      L845c0 [$800845c0]
8008455C	sh     v0, $0084(s5)

L84560:	; 80084560
80084560	lw     v0, $0020(s1)
80084564	lw     a0, $0030(s1)
80084568	lw     v1, $0028(s1)
8008456C	lw     a1, $0038(s1)
80084570	addu   v0, v0, a0
80084574	addu   v1, v1, a1
80084578	sw     v0, $0020(s1)
8008457C	sw     v1, $0028(s1)
80084580	lui    v0, $800b
80084584	lh     v0, $f028(v0)
80084588	nop
8008458C	addiu  v0, v0, $ffff (=-$1)
80084590	blez   v0, L845c0 [$800845c0]
80084594	addu   s0, zero, zero
80084598	lh     a1, $0010(s1)
8008459C	addu   a0, v0, zero
800845A0	addiu  v1, sp, $0018

loop845a4:	; 800845A4
800845A4	lw     v0, $0020(v1)
800845A8	nop
800845AC	beq    a1, v0, loop84554 [$80084554]
800845B0	addiu  s0, s0, $0001
800845B4	slt    v0, s0, a0
800845B8	bne    v0, zero, loop845a4 [$800845a4]
800845BC	addiu  v1, v1, $0004

L845c0:	; 800845C0
800845C0	addiu  a1, s1, $0050
800845C4	lh     a0, $0010(s1)
800845C8	addiu  v0, sp, $0050
800845CC	sll    a0, a0, $04
800845D0	jal    system_normalize_word_vector_T0_T1_T2_to_word [$80048c24]
800845D4	addu   a0, v0, a0
800845D8	j      L845e4 [$800845e4]
800845DC	nop

L845e0:	; 800845E0
800845E0	sw     zero, $00f0(s1)

L845e4:	; 800845E4
800845E4	lui    v0, $800b
800845E8	lw     v0, $d070(v0)
800845EC	nop
800845F0	beq    v0, zero, L84614 [$80084614]
800845F4	nop
800845F8	lw     t5, $0110(sp)
800845FC	nop
80084600	sltiu  v0, t5, $0002
80084604	beq    v0, zero, L84648 [$80084648]
80084608	nop
8008460C	j      L84648 [$80084648]
80084610	sh     s7, $0084(s5)

L84614:	; 80084614
80084614	lw     t5, $0110(sp)
80084618	nop
8008461C	beq    t5, zero, L84648 [$80084648]
80084620	addiu  v1, s7, $000a
80084624	lh     v0, $0084(s5)
80084628	nop
8008462C	slt    v0, v0, v1
80084630	beq    v0, zero, L8463c [$8008463c]
80084634	ori    v0, zero, $00ff
80084638	sb     v0, $0074(s1)

L8463c:	; 8008463C
8008463C	sll    v0, s7, $10
80084640	sh     s7, $0084(s5)
80084644	sw     v0, $0024(s1)

L84648:	; 80084648
80084648	lw     v0, $0000(s1)
8008464C	lui    v1, $0004
80084650	and    v0, v0, v1
80084654	beq    v0, zero, L84670 [$80084670]
80084658	nop
8008465C	lh     v0, $00ec(s1)
80084660	nop
80084664	sll    v0, v0, $10
80084668	sw     v0, $0024(s1)
8008466C	sw     zero, $0010(s5)

L84670:	; 80084670
80084670	lw     v0, $0024(s1)
80084674	lw     v1, $0010(s5)
80084678	addu   a0, s1, zero
8008467C	addu   v0, v0, v1
80084680	jal    func7ff7c [$8007ff7c]
80084684	sw     v0, $0024(s1)
80084688	addu   a1, v0, zero
8008468C	sll    v0, fp, $10
80084690	lh     v1, $0010(s1)
80084694	sra    v0, v0, $10
80084698	beq    v1, v0, L846b0 [$800846b0]
8008469C	lui    v1, $fbff
800846A0	lw     v0, $0000(s1)
800846A4	ori    v1, v1, $ffff
800846A8	and    v0, v0, v1
800846AC	sw     v0, $0000(s1)

L846b0:	; 800846B0
800846B0	lw     v0, $0000(s1)
800846B4	lui    v1, $0400
800846B8	and    v0, v0, v1
800846BC	bne    v0, zero, L84718 [$80084718]
800846C0	lui    v0, $0042
800846C4	lh     a0, $0084(s5)
800846C8	lh     v1, $0026(s1)
800846CC	nop
800846D0	slt    v0, v1, a0
if (V0 != 0)
{
    if (A0 != V1)
    {
        800846E4	lw     v0, $0010(s5)
        800846E8	lw     v1, $001c(s5)
        800846EC	nop
        800846F0	addu   v0, v0, v1
        800846F4	sw     v0, $0010(s5)
    }

    800846F8	lw     v0, $0000(s1)
    800846FC	nop
    80084700	ori    v0, v0, $1000
    80084704	sw     v0, $0000(s1)
    80084708	lw     v0, $0010(s5)
    80084710	sw     v0, $00f0(s1)
}
else
{
    80084714	lui    v0, $0042

    L84718:	; 80084718
    80084718	and    v0, a1, v0
    8008471C	bne    v0, zero, L84728 [$80084728]
    80084720	nop
    80084724	sw     zero, $00f0(s1)

    L84728:	; 80084728
    80084728	lw     v0, $0010(s5)
    8008472C	nop
    if (V0 > 0)
    {
        [S5 + 10] = w(0);
    }

    [S1 + 0] = w(w[S1 + 0] & ffbfefff); // remove automove flag

    8008474C	lh     v0, $0084(s5)
    80084750	nop
    80084754	sll    v0, v0, $10
    80084758	sw     v0, $0024(s1)
}

[S1 + 0] = w(w[S1 + 0] & fbffffff);

80084770	lui    v0, $800b
80084774	lh     v0, $f028(v0)
80084778	nop
8008477C	addiu  v0, v0, $ffff (=-$1)
80084780	blez   v0, L847d8 [$800847d8]
80084784	addu   s0, zero, zero
80084788	lh     a2, $0026(s1)
8008478C	addu   a3, v0, zero
80084790	addiu  a0, sp, $0018

loop84794:	; 80084794
80084794	lw     a1, $0000(a0)
80084798	nop
8008479C	slt    v0, a1, a2
800847A0	beq    v0, zero, L847c8 [$800847c8]
800847A4	nop
800847A8	lhu    v0, $001a(s1)
800847AC	lw     v1, $0010(a0)
800847B0	subu   v0, a2, v0
800847B4	slt    v0, v0, v1
800847B8	beq    v0, zero, L847c8 [$800847c8]
800847BC	nop
800847C0	bne    a1, v1, L847d8 [$800847d8]
800847C4	nop

L847c8:	; 800847C8
800847C8	addiu  s0, s0, $0001
800847CC	slt    v0, s0, a3
800847D0	bne    v0, zero, loop84794 [$80084794]
800847D4	addiu  a0, a0, $0004

L847d8:	; 800847D8
800847D8	lui    a1, $800b
800847DC	addiu  a1, a1, $f028 (=-$fd8)
800847E0	lh     v0, $0000(a1)
800847E4	nop
800847E8	addiu  v0, v0, $ffff (=-$1)
800847EC	bne    s0, v0, L848d0 [$800848d0]
800847F0	nop
800847F4	lh     v0, $0010(s1)
800847F8	nop
800847FC	sll    v1, v0, $02
80084800	sll    v0, v0, $01
80084804	addu   v0, v0, s1
80084808	addu   v1, a1, v1
8008480C	lh     a0, $0008(v0)
80084810	lw     v1, $ffd0(v1)
80084814	sll    v0, a0, $03
80084818	subu   v0, v0, a0
8008481C	sll    v0, v0, $01
80084820	addu   v0, v0, v1
80084824	lb     v0, $000d(v0)
80084828	nop
8008482C	sll    a1, v0, $02
80084830	bgez   a1, L8485c [$8008485c]
80084834	addu   a0, s1, zero
80084838	lh     v0, $0026(s1)
8008483C	lhu    a0, $001a(s1)
80084840	lh     v1, $0084(s5)
80084844	subu   v0, v0, a0
80084848	addu   v1, a1, v1
8008484C	slt    v0, v0, v1
80084850	bne    v0, zero, L848d4 [$800848d4]
80084854	addu   s0, zero, zero
80084858	addu   a0, s1, zero

L8485c:	; 8008485C
8008485C	sll    v1, s6, $01
80084860	addu   v1, v1, s6
80084864	lw     v0, $0020(s1)
80084868	sll    v1, v1, $03
8008486C	sw     v0, $0000(s5)
80084870	lw     v0, $0024(s1)
80084874	subu   v1, v1, s6
80084878	sw     v0, $0004(s5)
8008487C	lw     v0, $0028(s1)
80084880	sll    v1, v1, $02
80084884	sw     v0, $0008(s5)
80084888	lui    v0, $800b
8008488C	lw     v0, $efe4(v0)
80084890	lh     a1, $0022(s1)
80084894	addu   v0, v1, v0
80084898	sw     a1, $0020(v0)
8008489C	lui    v0, $800b
800848A0	lw     v0, $efe4(v0)
800848A4	lh     a1, $0026(s1)
800848A8	addu   v0, v1, v0
800848AC	sw     a1, $0024(v0)
800848B0	lui    v0, $800b
800848B4	lw     v0, $efe4(v0)
800848B8	lh     a1, $002a(s1)
800848BC	addu   v1, v1, v0
800848C0	jal    func7ff7c [$8007ff7c]
800848C4	sw     a1, $0028(v1)
800848C8	j      L849a4 [$800849a4]
800848CC	sw     v0, $0014(s1)

L848d0:	; 800848D0
800848D0	addu   s0, zero, zero

L848d4:	; 800848D4
800848D4	lw     v0, $0090(sp)
800848D8	addiu  a0, sp, $0018
800848DC	sw     v0, $0020(s1)
800848E0	lw     v0, $0098(sp)
800848E4	addu   v1, s1, zero
800848E8	sh     fp, $0010(s1)
800848EC	sw     zero, $00f0(s1)
800848F0	sw     v0, $0028(s1)

loop848f4:	; 800848F4
800848F4	lhu    v0, $0088(a0)

L848f8:	; 800848F8
800848F8	addiu  a0, a0, $0002
800848FC	addiu  s0, s0, $0001
80084900	sh     v0, $0008(v1)
80084904	slti   v0, s0, $0004
80084908	bne    v0, zero, loop848f4 [$800848f4]
8008490C	addiu  v1, v1, $0002
80084910	lh     v1, $0084(s5)
80084914	lh     v0, $0026(s1)
80084918	nop
8008491C	beq    v1, v0, L84938 [$80084938]
80084920	nop
80084924	lw     v0, $0010(s5)
80084928	lw     v1, $001c(s5)
8008492C	nop
80084930	addu   v0, v0, v1
80084934	sw     v0, $0010(s5)

L84938:	; 80084938
80084938	lw     v0, $0010(s5)
8008493C	nop
80084940	bgez   v0, L84958 [$80084958]
80084944	nop
80084948	sw     zero, $0010(s5)
8008494C	lw     v0, $0094(sp)
80084950	nop
80084954	sw     v0, $0024(s1)

L84958:	; 80084958
80084958	lw     v0, $0020(s1)
8008495C	nop
80084960	sw     v0, $0000(s5)
80084964	lw     v0, $0024(s1)
80084968	nop
8008496C	sw     v0, $0004(s5)
80084970	lw     v0, $0028(s1)
80084974	nop
80084978	sw     v0, $0008(s5)
8008497C	sll    v0, s6, $01
80084980	addu   v0, v0, s6
80084984	sll    v0, v0, $03
80084988	subu   v0, v0, s6
8008498C	sll    v0, v0, $02
80084990	lui    v1, $800b
80084994	lw     v1, $efe4(v1)
80084998	lh     a0, $0026(s1)
8008499C	addu   v0, v0, v1
800849A0	sw     a0, $0024(v0)

L849a4:	; 800849A4
800849A4	j      L84aa4 [$80084aa4]
800849A8	addu   a0, s6, zero

L849ac:	; 800849AC
800849AC	addu   s0, zero, zero
800849B0	lw     v0, $0090(sp)
800849B4	addiu  a0, sp, $0018
800849B8	sw     v0, $0020(s1)
800849BC	lw     v0, $0098(sp)
800849C0	addu   v1, s1, zero
800849C4	sh     fp, $0010(s1)
800849C8	sw     zero, $00f0(s1)
800849CC	sw     v0, $0028(s1)

loop849d0:	; 800849D0
800849D0	lhu    v0, $0088(a0)
800849D4	addiu  a0, a0, $0002
800849D8	addiu  s0, s0, $0001
800849DC	sh     v0, $0008(v1)
800849E0	slti   v0, s0, $0004
800849E4	bne    v0, zero, loop849d0 [$800849d0]
800849E8	addiu  v1, v1, $0002
800849EC	lh     a0, $0084(s5)
800849F0	lh     v1, $0026(s1)
800849F4	nop
800849F8	slt    v0, v1, a0
800849FC	beq    v0, zero, L84a24 [$80084a24]
80084A00	nop
80084A04	beq    a0, v1, L84a58 [$80084a58]
80084A08	nop
80084A0C	lw     v0, $0010(s5)
80084A10	lw     v1, $001c(s5)
80084A14	nop
80084A18	addu   v0, v0, v1
80084A1C	j      L84a58 [$80084a58]
80084A20	sw     v0, $0010(s5)

L84a24:	; 80084A24
80084A24	lw     v0, $0010(s5)
80084A28	nop
80084A2C	blez   v0, L84a38 [$80084a38]
80084A30	lui    v1, $ffbf
80084A34	sw     zero, $0010(s5)

L84a38:	; 80084A38
80084A38	lw     v0, $0000(s1)
80084A3C	ori    v1, v1, $efff
80084A40	and    v0, v0, v1
80084A44	sw     v0, $0000(s1)
80084A48	lh     v0, $0084(s5)
80084A4C	nop
80084A50	sll    v0, v0, $10
80084A54	sw     v0, $0024(s1)

L84a58:	; 80084A58
80084A58	lw     v0, $0020(s1)
80084A5C	nop
80084A60	sw     v0, $0000(s5)
80084A64	lw     v0, $0024(s1)
80084A68	nop
80084A6C	sw     v0, $0004(s5)
80084A70	lw     v0, $0028(s1)
80084A74	addu   a0, s6, zero
80084A78	sw     v0, $0008(s5)
80084A7C	sll    v0, a0, $01
80084A80	addu   v0, v0, a0
80084A84	sll    v0, v0, $03
80084A88	subu   v0, v0, a0
80084A8C	sll    v0, v0, $02
80084A90	lui    v1, $800b
80084A94	lw     v1, $efe4(v1)
80084A98	lh     a1, $0026(s1)
80084A9C	addu   v0, v0, v1
80084AA0	sw     a1, $0024(v0)

L84aa4:	; 80084AA4
80084AA4	jal    func81268 [$80081268]
80084AA8	nop
80084AAC	addu   v0, zero, zero

L84ab0:	; 80084AB0
80084AB0	lw     ra, $00fc(sp)
80084AB4	lw     fp, $00f8(sp)
80084AB8	lw     s7, $00f4(sp)
80084ABC	lw     s6, $00f0(sp)
80084AC0	lw     s5, $00ec(sp)
80084AC4	lw     s4, $00e8(sp)
80084AC8	lw     s3, $00e4(sp)
80084ACC	lw     s2, $00e0(sp)
80084AD0	lw     s1, $00dc(sp)
80084AD4	lw     s0, $00d8(sp)
80084AD8	addiu  sp, sp, $0100
80084ADC	jr     ra 
80084AE0	nop
////////////////////////////////



////////////////////////////////
// func81aa8
V0 = w[A1 + 12c] & 00001000;
if( V0 == 0 )
{
    return 0;
}

V0 = w[A1 + 20];
V1 = w[A0 + 0];
A0 = w[A0 + 8];

V0 = V0 + V1;
V0 = V0 >> 10;

V1 = w[A1 + 28];

V0 = V0 << 10;

80081AF4	addu   v1, v1, a0
80081AF8	sra    v1, v1, $10
80081AFC	addu   s0, v0, v1

V1 = w[A1 + 114];

80081B10	lh     a1, $0006(v1)
80081B14	lh     a3, $000a(v1)

S4 = (h[V1 + 0] << 10) + h[V1 + 2];

80081B20	lh     v0, $0004(v1)
80081B28	sll    v0, v0, $10
80081B2C	addu   s1, v0, a1
80081B30	lh     v0, $0008(v1)
80081B38	sll    v0, v0, $10
80081B3C	addu   s2, v0, a3
80081B40	lh     v0, $000c(v1)
80081B44	lh     v1, $000e(v1)
80081B48	sll    v0, v0, $10
S3 = V0 + V1;

A0 = S4;
A1 = S1;
A2 = S0;
system_side_of_vector;
if (V0 < 0)
{
    return -1;
}

A0 = S1;
A1 = S2;
A2 = S0;
system_side_of_vector;
if (V0 < 0)
{
    return -1;
}

A0 = S2;
A1 = S3;
A2 = S0;
system_side_of_vector;
if (V0 < 0)
{
    return -1;
}

A0 = S3;
A1 = S4;
A2 = S0;
system_side_of_vector;

V0 = V0 >> 1f;
////////////////////////////////



////////////////////////////////
// func81594
80081594	addiu  sp, sp, $ffd8 (=-$28)
80081598	sw     s3, $001c(sp)
8008159C	addu   s3, a2, zero
800815A0	sw     ra, $0020(sp)
800815A4	sw     s2, $0018(sp)
800815A8	sw     s1, $0014(sp)
800815AC	sw     s0, $0010(sp)
800815B0	lhu    v0, $0058(s3)
800815B4	nop
800815B8	andi   v0, v0, $0040
800815BC	bne    v0, zero, L815fc [$800815fc]
800815C0	addu   s2, a0, zero
800815C4	lw     v0, $004c(s3)
800815C8	nop
800815CC	lhu    v1, $0076(v0)
800815D0	lui    v0, $0004
800815D4	div    v0, v1
800815D8	mflo   v0
800815DC	nop
800815E0	sra    v0, v0, $08
800815E4	sll    s1, v0, $05
800815E8	andi   v0, a1, $8000
800815EC	bne    v0, zero, L817c4 [$800817c4]
800815F0	andi   s0, a1, $0fff
800815F4	j      L81710 [$80081710]
800815F8	addu   a0, s0, zero

L815fc:	; 800815FC
800815FC	sll    v0, a1, $10
80081600	sra    a2, v0, $10
80081604	andi   v0, a2, $8000
80081608	bne    v0, zero, L817c4 [$800817c4]
8008160C	nop
80081610	lw     a0, $004c(s3)
80081614	nop
80081618	lw     v1, $0004(a0)
8008161C	nop
80081620	andi   v0, v1, $2000
80081624	bne    v0, zero, L816e4 [$800816e4]
80081628	lui    v0, $0002
8008162C	lui    v0, $0008
80081630	and    v0, v1, v0
80081634	bne    v0, zero, L81650 [$80081650]
80081638	lui    v0, $0004
8008163C	addu   a0, s2, zero
80081640	jal    func21e40 [$80021e40]
80081644	addu   a1, a2, zero
80081648	j      L817d0 [$800817d0]
8008164C	addiu  v0, zero, $f000 (=-$1000)

L81650:	; 80081650
80081650	lhu    v1, $0076(a0)
80081654	nop
80081658	div    v0, v1
8008165C	mflo   v0
80081660	andi   s0, a1, $0fff
80081664	addu   a0, s0, zero
80081668	sra    v0, v0, $08
8008166C	jal    func3f774 [$8003f774]
80081670	sll    s1, v0, $05
80081674	mult   v0, s1
80081678	lw     v0, $004c(s3)
8008167C	mflo   a3
80081680	lh     v1, $00f4(v0)
80081684	sra    v0, a3, $0c
80081688	mult   v0, v1
8008168C	addu   a0, s0, zero
80081690	mflo   a3
80081694	jal    func3f758 [$8003f758]
80081698	sw     a3, $000c(s2)
8008169C	mult   v0, s1
800816A0	lw     v1, $004c(s3)
800816A4	nop
800816A8	lh     v1, $00f8(v1)
800816AC	mflo   a3
800816B0	subu   v0, zero, a3
800816B4	sra    v0, v0, $0c
800816B8	mult   v0, v1
800816BC	mflo   a3
800816C0	sw     a3, $0014(s2)
800816C4	lw     v0, $004c(s3)
800816C8	nop
800816CC	lhu    v1, $0076(v0)
800816D0	lui    v0, $0400
800816D4	div    v0, v1
800816D8	mflo   v0
800816DC	j      L817cc [$800817cc]
800816E0	sw     v0, $0018(s2)

L816e4:	; 800816E4
800816E4	and    v0, v1, v0
800816E8	bne    v0, zero, L8176c [$8008176c]
800816EC	lui    v0, $0008
800816F0	lhu    v1, $0076(a0)
800816F4	nop
800816F8	div    v0, v1
800816FC	mflo   v0
80081700	andi   s0, a1, $0fff
80081704	addu   a0, s0, zero
80081708	sra    v0, v0, $08
8008170C	sll    s1, v0, $05

L81710:	; 80081710
80081710	jal    func3f774 [$8003f774]
80081714	nop
80081718	mult   v0, s1
8008171C	lw     v0, $004c(s3)
80081720	mflo   a3
80081724	lh     v1, $00f4(v0)
80081728	sra    v0, a3, $0c
8008172C	mult   v0, v1
80081730	addu   a0, s0, zero
80081734	mflo   a3
80081738	jal    func3f758 [$8003f758]
8008173C	sw     a3, $000c(s2)
80081740	mult   v0, s1
80081744	lw     v1, $004c(s3)
80081748	nop
8008174C	lh     v1, $00f8(v1)
80081750	mflo   a3
80081754	subu   v0, zero, a3
80081758	sra    v0, v0, $0c
8008175C	mult   v0, v1
80081760	mflo   a3
80081764	j      L817cc [$800817cc]
80081768	sw     a3, $0014(s2)

L8176c:	; 8008176C
8008176C	lw     v0, $012c(a0)
80081770	nop
80081774	srl    v1, v0, $0b
80081778	lui    v0, $801f
8008177C	addiu  v0, v0, $8670 (=-$7990)
80081780	andi   v1, v1, $001c
80081784	addu   v1, v1, v0
80081788	lw     v0, $0000(v1)
8008178C	nop
80081790	lw     v0, $0128(v0)
80081794	nop
80081798	subu   v0, zero, v0
8008179C	sll    v0, v0, $10
800817A0	sw     v0, $000c(s2)
800817A4	lw     v0, $0000(v1)
800817A8	nop
800817AC	lw     v0, $0130(v0)
800817B0	nop
800817B4	subu   v0, zero, v0
800817B8	sll    v0, v0, $10
800817BC	j      L817cc [$800817cc]
800817C0	sw     v0, $0014(s2)

L817c4:	; 800817C4
800817C4	sw     zero, $000c(s2)
800817C8	sw     zero, $0014(s2)

L817cc:	; 800817CC
800817CC	addiu  v0, zero, $f000 (=-$1000)

L817d0:	; 800817D0
800817D0	lw     v1, $000c(s2)
800817D4	lw     a0, $0014(s2)
800817D8	and    v1, v1, v0
800817DC	and    a0, a0, v0
800817E0	sw     v1, $000c(s2)
800817E4	sw     a0, $0014(s2)
800817E8	lw     ra, $0020(sp)
800817EC	lw     s3, $001c(sp)
800817F0	lw     s2, $0018(sp)
800817F4	lw     s1, $0014(sp)
800817F8	lw     s0, $0010(sp)
800817FC	addiu  sp, sp, $0028
80081800	jr     ra 
80081804	nop
////////////////////////////////