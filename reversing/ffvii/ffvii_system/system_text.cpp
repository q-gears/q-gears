////////////////////////////////
//func1d6a8
dialog_width = h(A2);
[SP + 28] = h(0);
index = 0;

message = A3; // message address
pos_x = A0;
pos_y = A1;

L1d6ec:	; 8001D6EC
    A0 = bu[message];

    if (h[GP + 78] != 0) // if number of letter != 0
    {
        if (A0 != ff) // if not end of string
        {
            if (A0 != e8 && A0 != e9) // if E8 or E9 - finish execution
            {
                if (A0 == e7) // new line
                {
                    pos_x = 8;
                    pos_y = pos_y + 10;
                    message = message + 1;
                    [GP + 0258] = w(w[GP + 0258] + 1);
                    [GP + 02ac] = w(w[GP + 02ac] + 1);
                }
                else
                {
                    if (A0 == fa || A0 == fb || A0 == fc || A0 == fd || A0 == fe) // FA FB FC FD FE
                    {
                        S3 = 0;

                        switch( A0 )
                        {
                            case fa:
                            {
                                message = message + 1;
                                [GP + 2ac] = w(w[GP + 2ac] + 1);
                                S4 = 84;
                                S7 = e7;
                                8001D7CC	j      L1dab0 [$8001dab0]
                            }
                            break;

                            case fb:
                            {
                                message = message + 1;
                                [GP + 2ac] = w(w[GP + 2ac] + 1);
                                S4 = 0;
                                S7 = 1b9;
                                S3 = 10
                                8001D7CC	j      L1dab0 [$8001dab0]
                            }
                            break;

                            case fc:
                            {
                                message = message + 1;
                                [GP + 2ac] = w(w[GP + 2ac] + 1);
                                S4 = 84;
                                S7 = 2a0;
                                S3 = 10
                                8001D7CC	j      L1dab0 [$8001dab0]
                            }
                            break;

                            case fd:
                            {
                                message = message + 1;
                                [GP + 2ac] = w(w[GP + 2ac] + 1);
                                S4 = 84;
                                S7 = 372;
                                8001D7CC	j      L1dab0 [$8001dab0]
                            }
                            break;

                            case fe:
                            {
                                message = message + 1;
                                [GP + 2ac] = w(w[GP + 2ac] + 1);

                                V0 = bu[message];
                                if (V0 >= d2)
                                {
                                    [GP + 2ac] = w(w[GP + 2ac] + 1);

                                    A0 = bu[message];
                                    V1 = A0 & ff;
                                    if (V1 < da)
                                    {
                                        [GP + 70] = h(A0 - d2);
                                        message = message + 1;
                                        8001D828	j      L1dd68 [$8001dd68]
                                    }
                                    if (V1 == da)
                                    {
                                        [GP + 72] = hu(hu[GP + 72] ^ 1);
                                        message = message + 1;
                                        8001D86C	j      L1dd68 [$8001dd68]
                                    }
                                    else if (V1 == db)
                                    {
                                        [GP + 74] = hu(hu[GP + 74] ^ 1);
                                        message = message + 1;
                                        8001D86C	j      L1dd68 [$8001dd68]
                                    }
                                    else if (V1 == e9)
                                    {
                                        [GP + 80] = w(w[GP + 80] ^ 1);
                                        message = message + 1;
                                    }
                                }
                                else
                                {
                                    S4 = 84;
                                    S3 = 10;
                                    S7 = 444;
                                    8001D800	j      L1dab0 [$8001dab0]
                                }
                            }
                            break;
                        }
                    }
                    else
                    {
                        S3 = 0;

                        if (A0 == f6 || A0 == f7 || A0 == f8 || A0 == f9) // F6 F7 F8 F9
                        {
                            A0 = 0;
                            8001D8A4	addu   a0, zero, zero
                            8001D8A8	ori    a1, zero, $0001
                            8001D8AC	ori    a2, zero, $0380
                            8001D8B0	ori    a3, zero, $0100
                            8001D8B4	ori    v0, zero, $0100
                            8001D8B8	sh     zero, $0010(sp)
                            8001D8BC	sh     zero, $0012(sp)
                            8001D8C0	sh     v0, $0014(sp)
                            8001D8C4	jal    system_create_texture_page_settings_for_packet [$8004656c]
                            8001D8C8	sh     v0, $0016(sp)
                            8001D8CC	addu   a0, zero, zero
                            8001D8D0	ori    a1, zero, $0001
                            8001D8D4	andi   a2, v0, $ffff
                            8001D8D8	jal    func26a34 [$80026a34]
                            8001D8DC	addiu  a3, sp, $0010
                            8001D8E0	lui    v1, $8006
                            8001D8E4	lw     v1, $2f24(v1)
                            8001D8E8	ori    v0, zero, $0004
                            8001D8EC	sb     v0, $0003(v1)
                            8001D8F0	lui    v1, $8006
                            8001D8F4	lw     v1, $2f24(v1)
                            8001D8F8	ori    v0, zero, $0064
                            8001D8FC	sb     v0, $0007(v1)
                            8001D900	lui    a0, $8006
                            8001D904	lw     a0, $2f24(a0)
                            8001D908	jal    system_change_brightness_calculation_in_packet [$80046870]
                            8001D90C	ori    a1, zero, $0001
                            8001D910	lw     v0, $007c(gp)
                            8001D914	nop
                            8001D918	beq    v0, zero, L1d930 [$8001d930]
                            8001D91C	nop
                            8001D920	lui    a0, $8006
                            8001D924	lw     a0, $2f24(a0)
                            A1 = 1;
                            system_change_semi_transparency_in_packet;


                            L1d930:	; 8001D930
                            8001D930	lui    v0, $8006
                            8001D934	lw     v0, $2f24(v0)
                            8001D938	nop
                            [V0 + 8] = h(pos_x);
                            8001D940	lui    v1, $8006
                            8001D944	lw     v1, $2f24(v1)
                            V0 = pos_y - 2
                            8001D94C	sh     v0, $000a(v1)
                            V0 = bu[message];
                            8001D958	addiu  v1, v0, $ff0a (=-$f6)
                            8001D95C	ori    v0, zero, $0001
                            8001D960	beq    v1, v0, L1d9ac [$8001d9ac]
                            8001D964	slti   v0, v1, $0002
                            8001D968	beq    v0, zero, L1d980 [$8001d980]
                            8001D96C	nop
                            8001D970	beq    v1, zero, L1d99c [$8001d99c]
                            8001D974	ori    a0, zero, $0100
                            8001D978	j      L1d9f0 [$8001d9f0]
                            8001D97C	nop

                            L1d980:	; 8001D980
                            8001D980	ori    v0, zero, $0002
                            8001D984	beq    v1, v0, L1d9bc [$8001d9bc]
                            8001D988	ori    v0, zero, $0003
                            8001D98C	beq    v1, v0, L1d9cc [$8001d9cc]
                            8001D990	ori    v1, zero, $0070
                            8001D994	j      L1d9f0 [$8001d9f0]
                            8001D998	ori    a0, zero, $0100

                            L1d99c:	; 8001D99C
                            8001D99C	lui    v0, $8006
                            8001D9A0	lw     v0, $2f24(v0)
                            8001D9A4	j      L1d9d4 [$8001d9d4]
                            8001D9A8	ori    v1, zero, $0060

                            L1d9ac:	; 8001D9AC
                            8001D9AC	lui    v0, $8006
                            8001D9B0	lw     v0, $2f24(v0)
                            8001D9B4	j      L1d9d4 [$8001d9d4]
                            8001D9B8	ori    v1, zero, $0090

                            L1d9bc:	; 8001D9BC
                            8001D9BC	lui    v0, $8006
                            8001D9C0	lw     v0, $2f24(v0)
                            8001D9C4	j      L1d9d4 [$8001d9d4]
                            8001D9C8	ori    v1, zero, $0080

                            L1d9cc:	; 8001D9CC
                            8001D9CC	lui    v0, $8006
                            8001D9D0	lw     v0, $2f24(v0)

                            L1d9d4:	; 8001D9D4
                            8001D9D4	nop
                            8001D9D8	sb     v1, $000c(v0)
                            8001D9DC	lui    v0, $8006
                            8001D9E0	lw     v0, $2f24(v0)
                            8001D9E4	ori    t0, zero, $0040
                            8001D9E8	sb     t0, $000d(v0)
                            8001D9EC	ori    a0, zero, $0100

                            L1d9f0:	; 8001D9F0
                            8001D9F0	lui    v0, $8006
                            8001D9F4	lw     v0, $2f24(v0)
                            8001D9F8	ori    v1, zero, $0010
                            8001D9FC	sh     v1, $0010(v0)
                            8001DA00	lui    v0, $8006
                            8001DA04	lw     v0, $2f24(v0)
                            8001DA08	ori    a1, zero, $01ea
                            8001DA0C	jal    func46634 [$80046634]
                            8001DA10	sh     v1, $0012(v0)
                            8001DA14	lui    v1, $8006
                            8001DA18	lw     v1, $2f24(v1)
                            8001DA1C	nop
                            8001DA20	sh     v0, $000e(v1)
                            8001DA24	lui    a1, $8006
                            8001DA28	lw     a1, $2f24(a1)
                            8001DA2C	lui    a0, $8006
                            8001DA30	lw     a0, $2fc4(a0)
                            8001DA34	addiu  v0, a1, $0014
                            [80062f24] = w(V0);

                            message = message + 1;
                            system_add_render_packet_to_queue;

                            A0 = 0;
                            A1 = 1;
                            A2 = 3c0;
                            A3 = 100;
                            [SP + 10] = h(0);
                            [SP + 12] = h(0);
                            [SP + 14] = h(100);
                            [SP + 16] = h(100);

                            [GP + 78] = h(h[GP + 78] - 1);
                            system_create_texture_page_settings_for_packet;

                            8001DA7C	addu   a0, zero, zero
                            8001DA80	ori    a1, zero, $0001
                            8001DA84	andi   a2, v0, $ffff
                            8001DA88	jal    func26a34 [$80026a34]
                            8001DA8C	addiu  a3, sp, $0010

                            [GP + 2ac] = w(w[GP + 2ac] + 1);
                            pos_x = pos_x + 10;
                        }
                        else
                        {
                            A0 = 0;
                            S7 = 0;
                            S4 = 0;

                            L1dab0:	; 8001DAB0
                            if h[GP + 74] == 0 && h[GP + 72] == 0)
                            {
                                S1 = h[GP + 70] + 01f0;
                            }
                            else if (h[GP + 72] == 0 && hu[GP + 74] == 0)
                            {
                                if ((hu[GP + 76] >> 2) & 1)
                                {
                                    S1 = h[GP + 70] + 01f0;
                                }
                                else if (h[GP + 70] != 0)
                                {
                                    S1 = 01f0;
                                }
                                else
                                {
                                    pos_x = pos_x + S3;
                                    8001DB3C	j      L1dd68 [$8001dd68]
                                }
                            }
                            else
                            {
                                S1 = ((h[GP + 76] / 4 - hu[SP + 28]) & 7) | 1f0;
                            }

                            letter = bu[message];
                            S6 = (letter % 15) * 0c; // x in texture
                            S4 = S4 + (letter / 15) * 0c; // y in texture
                            S5 = letter + S7; // opcode + offset in table if extended opcode used
                            A1 = w[800707c0] + S5; // offset to font padding

                            if (dialog_width < pos_x + (bu[A1] >> 5) + (bu[A1] & 1f)) // if this letter is on next row
                            {
                                pos_x = 8;
                                pos_y = pos_y + 10;
                                [GP + 258] = w(w[GP + 258] + 1);
                            }

                            if (w[GP + 80] == 0) // if not monowidth
                            {
                                pos_x = pos_x + (bu[A1] >> 5);
                            }

                            V1 = w[80062f24];
                            [V1 + 03] = b(4);
                            [V1 + 07] = b(64); // draw sprite

                            A0 = w[80062f24];
                            A1 = 1;
                            system_change_brightness_calculation_in_packet;

                            V0 = [GP + 7c];

                            if (V0 != 0)
                            {
                                A0 = w[80062f24];
                                A1 = 0;
                                system_change_semi_transparency_in_packet;
                            }

                            V0 = w[80062f24];
                            [V0 + 08] = pos_x;
                            [V0 + 0a] = pos_y;
                            [V0 + 0c] = S6;
                            [V0 + 0d] = S4;
                            [V0 + 10] = h(0c);
                            [V0 + 12] = h(0c);

                            A0 = S3 | 0100; // clut X
                            A1 = S1; // clut Y
                            func46634;

                            V1 = w[80062f24];
                            [V1 + 0e] = h(V0);

                            A0 = [80062fc4];
                            A1 = w[80062f24];
                            [80062f24] = w(w[80062f24] + 14);
                            system_add_render_packet_to_queue;

                            if ([GP + 80] == 0) // if not monowidth
                            {
                                V0 = [800707c0];
                                pos_x = pos_x + (bu[V0 + S5] & 1f);
                            }
                            else
                            {
                                pos_x = pos_x + d;
                            }

                            message = message + 1;
                            [GP + 78] = h([GP + 78] - 1); // numbers of letter
                            [GP + 02ac] = [GP + 02ac] + 1;
                        }
                    }
                }

                L1dd68:	; 8001DD68
                [SP + 28] = h(h[SP + 28] + 1);

                index = index + 1;
                V0 = index < 400;
                8001DD8C	bne    v0, zero, L1d6ec [$8001d6ec]
            }
        }
    }
}

8001DD94	addu   a0, zero, zero
8001DD98	ori    a1, zero, $0001
8001DD9C	ori    a2, zero, $0380
8001DDA0	ori    a3, zero, $0100
8001DDA4	ori    v0, zero, $0100
8001DDA8	sh     zero, $0010(sp)
8001DDAC	sh     zero, $0012(sp)
8001DDB0	sh     v0, $0014(sp)
8001DDB4	jal    system_create_texture_page_settings_for_packet [$8004656c]
8001DDB8	sh     v0, $0016(sp)
8001DDBC	addu   a0, zero, zero
8001DDC0	ori    a1, zero, $0001
8001DDC4	andi   a2, v0, $ffff
8001DDC8	jal    func26a34 [$80026a34]
8001DDCC	addiu  a3, sp, $0010

return pos_y;
////////////////////////////////



////////////////////////////////
// func1521c
A0 = A0;
system_get_pointer_to_battle_text_in_kernel_with_id;
A0 = V0;
A1 = A0;
system_copy_text_from_kernel;
////////////////////////////////



////////////////////////////////
// system_get_pointer_to_battle_text_in_kernel_with_id
A1 = A0;
A0 = 10;
A2 = 0;
system_get_pointer_to_text_in_kernel_with_block_and_text_id;

return V0;
////////////////////////////////



////////////////////////////////
// system_get_pointer_to_text_in_kernel_with_block_and_text_id
A0 = A0 + A2;
V1 = hu[80069490 + A0 * 2]; // 0x52ae
V0 = hu[80063690 + V1 + A1 * 2]; // kernel begin
return 80063690 + V1 + V0;
////////////////////////////////



////////////////////////////////
// system_copy_text_from_kernel
from = A0;
where = 80063560;

T2 = 0;
T3 = 0;
T5 = 80063560;

loop150fc:	; 800150FC
    opcode = bu[from];
    from = from + 1;

    T3 = T3 + 1; // readed size

    if( opcode = f9 )
    {
        opcode = bu[from];
        from = from + 1;
        8001511C	addiu  t3, t3, $0001
        80015120	addiu  v1, t3, $fffd (=-$3)
        V0 = opcode & 3f;
        80015128	subu   v1, v1, v0
        V0 = opcode >> 6;
        80015130	sll    v0, v0, $01
        T4 = V0 + 4;
        if( T4 != 0 )
        {
            80015140	addu   a2, t2, t5
            V1 = V1 + A1;
            T0 = 0;
            loop15148:	; 80015148
                opcode = bu[V1];
                V1 = V1 + 1;
                where = where + 1;
                80015154	addiu  t2, t2, $0001
                [A2] = b(opcode);
                80015168	addiu  a2, a2, $0001
                T0 = T0 + 1;
                V0 = T0 < T4;
            80015164	bne    v0, zero, loop15148 [$80015148]
        }
    }
    else
    {
        if( ( opcode + 16 ) & ff < 08 ) // EA EB EC ED EE EF F0 F1
        {
            [where] = b(opcode);
            where = where + 1; // store address

            [where] = b(bu[from]);
            from = from + 1;
            where = where + 1;
            [where] = b(bu[from]);
            from = from + 1;
            where = where + 1;

            T3 = T3 + 2; // readed size
            T2 = T2 + 3; // stored size
        }
        else
        {
            [where] = b(opcode);
            where = where + 1;
            T2 = T2 + 1; // stored size
        }
    }

    if( opcode == ff )
    {
        break;
    }

    V0 = T2 < 100;
800151D8	bne    v0, zero, loop150fc [$800150fc]

return 80063560;
////////////////////////////////



////////////////////////////////
// func26f44
S0 = A2;
80026F54	addu   s3, a3, zero
80026F60	beq    s0, zero, L2706c [$8002706c]

80026F68	lbu    v0, $00b8(gp)
80026F6C	nop
80026F70	beq    v0, zero, L2700c [$8002700c]
80026F74	addu   s2, zero, zero
80026F78	sll    s1, a1, $10

loop26f7c:	; 80026F7C
opcode = [S0];
if (opcode != FF)
{
    V0 = (opcode == FA) || (opcode == FB) || (opcode == FC) || (opcode == FD) || (opcode == FE);

    if ((opcode == FA) || (opcode == FB) || (opcode == FC) || (opcode == FD) || (opcode == FE) || (opcode == F8))
    {
        A3 = [S0 + 01] = 2;
        S0 = S0 + 02;

        A1 = S1 >> 10
        A2 = S3 & FF;
        A3 = A3 << 08 = 200;
        A3 = opcode & A3 = 2F8;
    }
    else
    {
        S0 = S0 + 01;

        A1 = S1 >> 10;
        A2 = S3 & FF;
        A3 = opcode;
    }

    80026FE0	jal    func26c5c [$80026c5c]
    80026FE4	nop
    80026FE8	addu   a0, v0, zero
    80026FEC	addiu  v0, s2, $0001
    80026FF0	addu   s2, v0, zero
    80026FF4	sll    v0, v0, $10
    80026FF8	lbu    v1, $00b8(gp)
    80026FFC	sra    v0, v0, $10
    80027000	slt    v0, v0, v1
    80027004	bne    v0, zero, loop26f7c [$80026f7c]
    80027008	nop
}

8002700C	lbu    v0, $00b9(gp)
80027010	nop
80027014	beq    v0, zero, L2706c [$8002706c]
80027018	addu   a1, zero, zero
8002701C	ori    a2, zero, $0001
80027020	ori    a3, zero, $003e
80027024	lui    a0, $8006
80027028	lw     a0, $2f24(a0)
8002702C	ori    v0, zero, $00ff
80027030	sh     v0, $001c(sp)
80027034	sh     v0, $001e(sp)
80027038	addiu  v0, sp, $0018
8002703C	sh     zero, $0018(sp)
80027040	sh     zero, $001a(sp)
80027044	jal    func44a68 [$80044a68]
80027048	sw     v0, $0010(sp)
8002704C	lui    a1, $8006
80027050	lw     a1, $2f24(a1)
80027054	lw     a0, $0280(gp)
80027058	addiu  v0, a1, $000c
8002705C	lui    at, $8006
80027060	sw     v0, $2f24(at)
80027064	jal    system_add_render_packet_to_queue [$80046794]
80027068	nop

L2706c:	; 8002706C
////////////////////////////////



////////////////////////////////
func26c5c
S3 = A0
S6 = A1;
S7 = A2;

[SP + 20] = A3 = 2F8;
V0 = [SP + 20] = F8;
V1 = SP + 20;
A0 = V0 - F8;
V0 = A0 < 07;
[SP + 28] = S0;

if (V0 != 0)
{
    V0 = A0 << 2 = 0;
    AT = 80010378;
    AT = AT + V0
    V0 = [AT] = [80010378] = 80026F10;
    V1 = V1 + 01;

    case: F8
    {
        return;
    }
    break;

    case: FA
    {
        S1 = E7;
        S2 = 84;
        S4 = 0;
        S5 = 0;
    }
    break;

    case: FB
    {
        S1 = 01B9;
        S2 = 0
        S4 = 10;
        S5 = 0;
    }
    break;

    case: FC
    {
        S1 = 02A0;
        S2 = 84
        S4 = 10;
        S5 = 0;
    }
    break;

    case: FD
    {
        S1 = 0372
        S2 = 84;
        S4 = 0;
        S5 = -40 (FFC0);
    }
    break;

    case: FE
    {
        S1 = 0444;
        S2 = 84;
        S4 = 10;
        S5 = -10 (FFC0);
    }
    break;
}
else
{
    S1 = 0;
    S2 = 0;
    S4 = 0;
    S5 = 0;
}

80026D3C	ori    a1, zero, $0001
80026D40	lui    a2, $8618
80026D44	ori    a2, a2, $6187
80026D48	lbu    a3, $0000(v1)
80026D4C	lui    v0, $8007
80026D50	lw     v0, $07c0(v0)
80026D54	lui    a0, $8006
80026D58	lw     a0, $2f24(a0)
80026D5C	sh     a3, $0020(sp)
80026D60	andi   a3, a3, $ffff
80026D64	multu  a3, a2
80026D68	addu   v1, a3, s1
80026D6C	addu   v0, v0, v1
80026D70	lbu    v1, $0000(v0)
80026D74	ori    v0, zero, $0004
80026D78	sb     v0, $0003(a0)
80026D7C	srl    v1, v1, $05
80026D80	addu   s3, s3, v1
80026D84	lui    v1, $8006
80026D88	lw     v1, $2f24(v1)
80026D8C	ori    v0, zero, $0064
80026D90	sb     v0, $0007(v1)
80026D94	lui    a0, $8006
80026D98	lw     a0, $2f24(a0)
80026D9C	mfhi   a2
80026DA0	subu   v0, a3, a2
80026DA4	srl    v0, v0, $01
80026DA8	addu   a2, a2, v0
80026DAC	srl    a2, a2, $04
80026DB0	sll    v0, a2, $02
80026DB4	addu   v0, v0, a2
80026DB8	sll    v0, v0, $02
80026DBC	addu   v0, v0, a2
80026DC0	subu   a3, a3, v0
80026DC4	andi   a3, a3, $ffff
80026DC8	sll    s0, a3, $01
80026DCC	addu   s0, s0, a3
80026DD0	sll    s0, s0, $02
80026DD4	andi   a2, a2, $ffff
80026DD8	sll    v0, a2, $01
80026DDC	addu   v0, v0, a2
80026DE0	sll    v0, v0, $02
80026DE4	jal    system_change_brightness_calculation_in_packet [$80046870]
80026DE8	addu   s2, s2, v0
80026DEC	lui    v0, $8006
80026DF0	lw     v0, $2f24(v0)
80026DF4	nop
80026DF8	sh     s3, $0008(v0)
80026DFC	lui    v0, $8006
80026E00	lw     v0, $2f24(v0)
80026E04	sll    a0, s4, $10
80026E08	sh     s6, $000a(v0)
80026E0C	lui    v0, $8006
80026E10	lw     v0, $2f24(v0)
80026E14	sra    a0, a0, $10
80026E18	sb     s0, $000c(v0)
80026E1C	lui    v0, $8006
80026E20	lw     v0, $2f24(v0)
80026E24	ori    a0, a0, $0100
80026E28	sb     s2, $000d(v0)
80026E2C	lui    v0, $8006
80026E30	lw     v0, $2f24(v0)
80026E34	ori    v1, zero, $000c
80026E38	sh     v1, $0010(v0)
80026E3C	lui    v0, $8006
80026E40	lw     v0, $2f24(v0)
80026E44	addiu  a1, s7, $01f0
80026E48	jal    func46634 [$80046634]
80026E4C	sh     v1, $0012(v0)
80026E50	lui    v1, $8006
80026E54	lw     v1, $2f24(v1)
80026E58	nop
80026E5C	sh     v0, $000e(v1)
80026E60	lui    a1, $8006
80026E64	lw     a1, $2f24(a1)
80026E68	lw     a0, $0280(gp)
80026E6C	addiu  v0, a1, $0014
80026E70	lui    at, $8006
80026E74	sw     v0, $2f24(at)
80026E78	jal    system_add_render_packet_to_queue [$80046794]
80026E7C	nop
80026E80	lhu    v0, $0020(sp)
80026E84	lui    v1, $8007
80026E88	lw     v1, $07c0(v1)
80026E8C	addu   v0, v0, s1
80026E90	addu   v1, v1, v0
80026E94	lbu    v0, $0000(v1)
80026E98	lbu    v1, $00b9(gp)
80026E9C	andi   v0, v0, $001f
80026EA0	bne    v1, zero, L26f10 [$80026f10]
80026EA4	addu   s3, s3, v0
80026EA8	addu   a1, zero, zero
80026EAC	ori    v0, zero, $00ff
80026EB0	sh     v0, $001c(sp)
80026EB4	sh     v0, $001e(sp)
80026EB8	addiu  v0, sp, $0018
80026EBC	sll    a3, s5, $10
80026EC0	sra    a3, a3, $10
80026EC4	addiu  a3, a3, $0380
80026EC8	andi   a3, a3, $03ff
80026ECC	sra    a3, a3, $06
80026ED0	ori    a2, zero, $0001
80026ED4	lui    a0, $8006
80026ED8	lw     a0, $2f24(a0)
80026EDC	ori    a3, a3, $0030
80026EE0	sh     zero, $0018(sp)
80026EE4	sh     zero, $001a(sp)
80026EE8	jal    func44a68 [$80044a68]
80026EEC	sw     v0, $0010(sp)
80026EF0	lui    a1, $8006
80026EF4	lw     a1, $2f24(a1)
80026EF8	lw     a0, $0280(gp)
80026EFC	addiu  v0, a1, $000c
80026F00	lui    at, $8006
80026F04	sw     v0, $2f24(at)
80026F08	jal    system_add_render_packet_to_queue [$80046794]
80026F0C	nop

L26f10:	; 80026F10
80026F10	addu   v0, s3, zero
80026F14	lw     ra, $0048(sp)
80026F18	lw     s7, $0044(sp)
80026F1C	lw     s6, $0040(sp)
80026F20	lw     s5, $003c(sp)
80026F24	lw     s4, $0038(sp)
80026F28	lw     s3, $0034(sp)
80026F2C	lw     s2, $0030(sp)
80026F30	lw     s1, $002c(sp)
80026F34	lw     s0, $0028(sp)
80026F38	addiu  sp, sp, $0050
80026F3C	jr     ra 
80026F40	nop
////////////////////////////////