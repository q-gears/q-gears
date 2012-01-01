////////////////////////////////
// funca23e0
S4 = A0;
S7 = -1;
S5 = 800f692e;
S3 = S5 - 2;

La241c:	; 800A241C
    S6 = 0;
    S2 = 0;
    800A2420	blez   s4, La27ec [$800a27ec]

    T1 = 800f6b94;

    La2430:	; 800A2430
    [800f7dba] = h(S2);
    V1 = bu[T1];
    V0 = bu[800f6b9b + S2];
    T0 = 0;
    800A244C	beq    v1, v0, La27dc [$800a27dc]

    A3 = 0;
    loopa2458:	; 800A2458
        A0 = A3;
        V0 = bu[800f6934 + A0];
        if (V0 == S2)
        {
            V1 = bu[800f6935 + A0];
            V0 = bu[T1];
            if (V1 == V0)
            {
                V0 = A3 + S3 + 8;
                [S3 + 0] = w(w[V0 + 0]);
                [S3 + 4] = h(h[V0 + 4]);
                [800f6934 + A3] = b(ff);
                break;
            }
        }

        A3 = A0 + 8;
        T0 = T0 + 1;
        V0 = T0 < 40;
    800A2498	bne    v0, zero, loopa2458 [$800a2458]

    V0 = bu[T1];
    V0 = V0 + 1;
    [T1] = b(V0);

    if (T0 != 40)
    {
        S1 = b[S5];

        800A24C4	beq    s1, s7, La27ec [$800a27ec]
        800A24C8	ori    v0, zero, $0003
        800A24CC	beq    s1, v0, La25bc [$800a25bc]

        V1 = S1 * 68;
        V0 = b[800f83e8 + V1];
        800A24F4	beq    v0, s7, La27ec [$800a27ec]
        800A24F8	nop
        800A24FC	blez   s2, La2520 [$800a2520]
        800A2500	slti   v0, s2, $0005
        V0 = w[800f83e0 + V1];
        800A2514	andi   v0, v0, $0001
        800A2518	bne    v0, zero, La27ec [$800a27ec]
        800A251C	slti   v0, s2, $0005

        La2520:	; 800A2520
        if( V0 == 0 )
        {
            if( hu[800f5bba + S1 * 44] == 0 )
            {
                [S5 + 206 + S1 * 8 + 0] = w(w[S5 + 0]);
                [S5 + 206 + S1 * 8 + 4] = h(h[S5 + 4]);
                800A2570	j      La27ec [$800a27ec]
            }

            A0 = S1;
            funca22c0;
        }

        V0 = b[800f692f];
        A3 = 0;
        if( V0 == S7 )
        {
            A0 = 0;
            if( S1 >= 4 )
            {
                A1 = w[800f83e0 + S1 * 68 + 0];
                A2 = w[800f5bf0 + S1 * 44];

                if( A1 & 00000080 )
                {
                    V0 = hu[A2 + 9a] & 0001;
                    A3 = V0 < 1;
                }

                if( A1 & 00800000 )
                {
                    A1 = 1;
                }

                if( A3 != 0 )
                {
                    A0 = hu[A2 + 94];
                }
            }

            V0 = w[800f83e0 + S1 * 68] & 00400000;
            800A2678	bne    v0, zero, La27ec [$800a27ec]

            if( A3 != 0 )
            {
                battle_get_attack_index_by_attack_id;

                A0 = S1; // unit id
                A1 = 2;  // priority
                A2 = 20; // action_id
                A3 = V0; // attack id
                A4 = 0;  // target mask
                battle_add_action_to_battle_queue;
            }
            else
            {
                if( w[800f83e0 + S1 * 68 + 4] & 00000010 )
                {
                    A0 = 1;
                    800A26CC	jal    funca32c0 [$800a32c0]

                    A0 = S1;
                    A1 = 1;
                    A2 = 2;
                    funca6000;

                    V1 = bu[800f6b96];
                    V0 = bu[800f6b9d];

                    if( V1 == V0 )
                    {
                        A0 = S1;
                        funca22c0;
                    }
                    S6 = 1;
                }
            }
            800A2708	j      La27cc [$800a27cc]
        }

        800A2710	lui    v0, $8010
        800A2714	lhu    v0, $83d0(v0)
        800A2718	nop
        800A271C	andi   v0, v0, $0008
        800A2720	beq    v0, zero, La2754 [$800a2754]
        800A2724	slti   v0, s1, $0003
        800A2728	addu   s0, zero, zero
        800A272C	addu   a0, zero, zero

        loopa2730:	; 800A2730
        800A2730	addu   a1, s0, zero
        800A2734	ori    a2, zero, $0004
        800A2738	jal    funca7254 [$800a7254]
        800A273C	addu   a3, zero, zero
        800A2740	addiu  s0, s0, $0001
        800A2744	slti   v0, s0, $0003
        800A2748	bne    v0, zero, loopa2730 [$800a2730]
        800A274C	addu   a0, zero, zero
        800A2750	slti   v0, s1, $0003

        La2754:	; 800A2754
        800A2754	beq    v0, zero, La27bc [$800a27bc]
        800A2758	nop
        800A275C	lbu    v0, $0000(s3)
        800A2760	nop
        800A2764	sltiu  v0, v0, $0005
        800A2768	bne    v0, zero, La27bc [$800a27bc]
        800A276C	sll    v0, s1, $01
        800A2770	addu   v0, v0, s1
        800A2774	sll    v0, v0, $02
        800A2778	addu   v0, v0, s1
        800A277C	sll    v0, v0, $03
        800A2780	lui    at, $8010
        800A2784	addu   at, at, v0
        800A2788	lw     v0, $83e0(at)
        800A278C	lui    v1, $0080
        800A2790	and    v0, v0, v1
        800A2794	beq    v0, zero, La27bc [$800a27bc]
        800A2798	nop
        800A279C	jal    funca4ca8 [$800a4ca8]
        800A27A0	addu   a0, s1, zero
        800A27A4	addu   a0, s1, zero
        800A27A8	ori    a1, zero, $0006
        800A27AC	sb     v0, $0003(s3)
        800A27B0	sh     zero, $0004(s3)
        800A27B4	jal    funcb1304 [$800b1304]
        800A27B8	sh     zero, $0006(s3)

        La27bc:	; 800A27BC
        A0 = 800f692c;
        funca1798; // main action execution

        La27cc:	; 800A27CC
        800A27CC	jal    funca61d4 [$800a61d4]
        800A27D0	nop
        800A27D4	j      La27ec [$800a27ec]
        800A27D8	nop

    La27dc:	; 800A27DC
    800A27DC	addiu  s2, s2, $0001
    800A27E0	slt    v0, s2, s4
    800A27E4	bne    v0, zero, La2430 [$800a2430]
    800A27E8	addiu  t1, t1, $0001

    La27ec:	; 800A27EC
800A27EC	bne    s6, zero, La241c [$800a241c]

if( S2 == S4 )
{
    A0 = -1;
    funca22c0;
}

return (S2 ^ S4) < 1;
























S4 = A0;

La241c:	; 800A241C
    S6 = 0;
    priority = 0; // priority

    if (S4 > 0)
    {
        // cycle trough all priority
        La2430:	; 800A2430
            [800f7dba] = h(priority);
            if (bu[800f6b94 + priority] != bu[800f6b9b + priority])
            {
                A3 = 0;
                loopa2458:	; 800A2458
                    // waiting attack queue
                    if (bu[800f692c + 8 + A3] == priority) // search for current priority
                    {
                        if (bu[800f692c + 8 + A3 + 1] == bu[800f6b94 + priority]) //search for next execute order within priority
                        {
                            [800f692c + 0] = h(h[800f692c + 8 + A3 + 0]);
                            [800f692c + 2] = h(h[800f692c + 8 + A3 + 2]);
                            [800f692c + 4] = h(h[800f692c + 8 + A3 + 4]);
                            [800f692c + 6] = h(h[800f692c + 8 + A3 + 6]);

                            [800f692c + 8 + A3] = b(ff);
                            break;
                        }
                    }
                    A3 = A3 + 8;
                    V0 = A3 < 200;
                800A2498	bne    v0, zero, loopa2458 [$800a2458]

                // move to next priority number to execute
                V1 = bu[800f6b94 + priority];
                V0 = V0 + 1;
                [800f6b94 + priority] = b(V0);

                // if we found attack to execute
                if (A3 != 200)
                {
                    // if unit_id is set
                    S1 = b[800f692C + 2];
                    if (S1 != -1)
                    {
                        if (S1 != 3)
                        {
                            if (b[800f83e0 + S1 * 68 + 08] == -1) // if enemy index doesn't exist - skip it
                            {
                                800A2570	j      La27ec [$800a27ec]
                            }

                            if (priority > 0 && w[800f83e0 + S1 * 68 + 0] & 00000001) // if unit is dead and this is not top priority - skip it
                            {
                                800A2570	j      La27ec [$800a27ec]
                            }

                            if (priority >= 5)
                            {
                                if (hu[800f5bb8 + S1 * 44 + 2] == 0)
                                {
                                    [800F692C + 208 + S1 * 8 + 0] = h(h[800F692C + 0]);
                                    [800F692C + 208 + S1 * 8 + 2] = h(h[800F692C + 2]);
                                    [800F692C + 208 + S1 * 8 + 4] = h(h[800F692C + 4]);
                                    [800F692C + 208 + S1 * 8 + 6] = h(h[800F692C + 6]);

                                    800A2570	j      La27ec [$800a27ec]
                                }

                                A0 = S1;
                                funca22c0;
                            }
                        }

                        A3 = 0;

                        if (bu[800F692C + 03] == ff) // if action type not defined
                        {
                            A0 = 0;

                            if (S1 >= 4)
                            {
                                A1 = w[800F83E0 + S1 * 68 + 00];
                                A2 = w[800F5BF0 + S1 * 44];

                                // if in silence
                                if (A1 & 00000080)
                                {
                                    V0 = hu[A2 + 9A];
                                    V0 = V0 & 1;
                                    A3 = V0 < 1;
                                }

                                // if in berserk
                                if (A1 & 00800000)
                                {
                                    A3 = 1;
                                }

                                if (A3 != 0)
                                {
                                    A0 = hu[A2 + 94];
                                }
                            }

                            // if unit manipulated
                            V0 = w[800F83E0 + S1 * 68];
                            if (V0 & 00400000)
                            {
                                800A2570	j      La27ec [$800a27ec]
                            }

                            if (A3 != 0)
                            {
                                battle_get_attack_index_by_attack_id;

                                [SP + 10] = w(0);

                                A0 = S1;
                                A1 = 2;
                                A2 = 20;
                                A3 = V0;
                                battle_add_action_to_battle_queue;
                            }
                            else
                            {
                                V0 = w[800F83E0 + S1 * 68 + 04];
                                if (V0 & 00000010)
                                {
                                    A0 = 1;
                                    funca32c0;

                                    A0 = S1;
                                    A1 = 1;
                                    A2 = 2;
                                    funca6000; // run script 1

                                    V1 = bu[800F6B96];
                                    V0 = bu[800F6B9D];
                                    if (V1 == V0)
                                    {
                                        A0 = S1;
                                        funca22c0;
                                    }

                                    S6 = 1;
                                }
                            }
                        }
                        else
                        {
                            if (hu[800f83a4 + 2C] & 0008)
                            {
                                S0 = 0;

                                loopa2730:	; 800A2730
                                    A0 = 0;
                                    A1 = S0;
                                    A2 = 4;
                                    A3 = 0;
                                    funca7254;

                                    S0 = S0 + 1;
                                    V0 = S0 < 3;
                                800A2748	bne    v0, zero, loopa2730 [$800a2730]
                            }

                            if (S1 < 3) // if player
                            {
                                if (bu[800F692C + 0] >= 5) // if priority 5 or 6
                                {
                                    if (w[800F83E0 + S1 * 68] & 00800000) // if in berserk status
                                    {
                                        A0 = S1;
                                        battle_get_berserk_toad_attack_type_id;

                                        [800F692C + 3] = b(V0);
                                        [800F692C + 4] = h(0);
                                        [800F692C + 6] = h(0);

                                        // remove actions with priority 6
                                        A0 = S1;
                                        A1 = 6;
                                        battle_remove_action_from_attack_queue;
                                    }
                                }
                            }

                            A0 = 800f692c;
                            funca1798;
                        }

                        funca61d4;
                    }
                }
            }

            priority = priority + 1; // increment priority
            V0 = priority < S4;
        800A27E4	bne    v0, zero, La2430 [$800a2430]
    }

La27ec:	; 800A27EC
800A27EC	bne    s6, zero, La241c [$800a241c]

if (priority == S4)
{
    A0 = -1;
    funca22c0;

    return 1;
}

return 0;
////////////////////////////////



////////////////////////////////
// battle_get_berserk_toad_action_id_for_player
// used for player
return bu[800f39f0 + A0 * 6];
////////////////////////////////



////////////////////////////////
battle_remove_action_from_attack_queue
unit_id = A0;
A2 = 0;

loopb131c:	; 800B131C
    if (b[800F692C + 8 + A2 + 2] == unit_id && bu[800F692C + 8 + A2 + 0] != FF && bu[800F692C + 8 + A2 + 0] >= A1)
    {
        [800F692C + 8 + A2 + 2] = b(FF);
    }

    A2 = A2 + 8;
    V0 = A2 < 200;
800B1358	bne    v0, zero, loopb131c [$800b131c]

return;
////////////////////////////////



////////////////////////////////
// funca22c0
S0 = A0;
unit_id = w[800e7a38];

if( unit_id != -1 )
{
    if( unit_id == S0 )
    {
        return;
    }

    A0 = 0;
    loopa22f4:	; 800A22F4
        if( bu[800f6934 + A0 * 8 + 0] == 6 && b[800f6934 + A0 * 8 + 2] != unit_id ) // if priority == 6 and attacker id != unit id
        {
            break;
        }

        A0 = A0 + 1;
        V0 = A0 < 40;
    800A232C	bne    v0, zero, loopa22f4 [$800a22f4]

    if( A0 == 40 )
    {
        [800f5bb8 + unit_id * 44 + 2a] = b(bu[800f5bb8 + unit_id * 44 + 2a] + 1);

        A0 = unit_id;
        funca56b0;

        A0 = 0;
        A1 = unit_id;
        A2 = 0;
        A3 = 0;
        funca7254;
    }
}

[800e7a38] = w(S0);
////////////////////////////////



////////////////////////////////
// funca56b0
unit_id = A0;

T0 = 0;
loopa56d8:	; 800A56D8
    A3 = h[800f3a40 + T0 * 4 + 2];
    if( A3 != -1 )
    {
        if( h[800f3a40 + T0 * 4 + 0] == unit_id )
        {
            V0 = w[800f3a1c];
            [800f3a20 + V0 * 2] = h(A3);
            [800f3a1c] = w((V0 + 1) & f);
            [800f3a40 + T0 * 4 + 0] = h(-1);
            [800f3a40 + T0 * 4 + 2] = h(-1)
        }
    }

    T0 = T0 + 1;
    V0 = T0 < 10;
800A573C	bne    v0, zero, loopa56d8 [$800a56d8]
////////////////////////////////
