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
                    V1 = A0 - fa;

                    if (A0 == fa || A0 == fb || A0 == fc || A0 == fd || A0 == fe) // FA FB FC FD FE
                    {
                        8001D74C	addu   s3, zero, zero
                        8001D750	sll    v0, v1, $02
                        8001D754	lui    at, $8001
                        8001D758	addiu  at, at, $0300
                        8001D75C	addu   at, at, v0
                        8001D760	lw     v0, $0000(at)
                        8001D764	nop
                        8001D768	jr     v0 
                        8001D76C	nop

                        message = message + 1;
                        8001D774	ori    s4, zero, $0084
                        8001D778	lw     v0, $02ac(gp)
                        8001D77C	j      L1d7c4 [$8001d7c4]
                        8001D780	ori    s7, zero, $00e7
                        message = message + 1;
                        8001D788	addu   s4, zero, zero
                        8001D78C	ori    s3, zero, $0010
                        8001D790	lw     v0, $02ac(gp)
                        8001D794	j      L1d7c4 [$8001d7c4]
                        8001D798	ori    s7, zero, $01b9
                        message = message + 1;
                        8001D7A0	ori    s4, zero, $0084
                        8001D7A4	ori    s3, zero, $0010
                        8001D7A8	lw     v0, $02ac(gp)
                        8001D7AC	j      L1d7c4 [$8001d7c4]
                        8001D7B0	ori    s7, zero, $02a0
                        message = message + 1;
                        8001D7B8	ori    s4, zero, $0084
                        8001D7BC	lw     v0, $02ac(gp)
                        8001D7C0	ori    s7, zero, $0372

                        L1d7c4:	; 8001D7C4
                        8001D7C4	addiu  v0, v0, $0001
                        8001D7C8	sw     v0, $02ac(gp)
                        8001D7CC	j      L1dab0 [$8001dab0]
                        8001D7D0	nop
                        8001D7D4	lw     v1, $02ac(gp)
                        message = message + 1;
                        8001D7DC	addiu  v0, v1, $0001
                        8001D7E0	sw     v0, $02ac(gp)
                        V0 = bu[message];

                        8001D7EC	sltiu  v0, v0, $00d2
                        8001D7F0	beq    v0, zero, L1d808 [$8001d808]
                        8001D7F4	addiu  v0, v1, $0002
                        8001D7F8	ori    s4, zero, $0084
                        8001D7FC	ori    s3, zero, $0010
                        8001D800	j      L1dab0 [$8001dab0]
                        8001D804	ori    s7, zero, $0444

                        L1d808:	; 8001D808
                        8001D808	sw     v0, $02ac(gp)
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
                            8001D908	jal    func46870 [$80046870]
                            8001D90C	ori    a1, zero, $0001
                            8001D910	lw     v0, $007c(gp)
                            8001D914	nop
                            8001D918	beq    v0, zero, L1d930 [$8001d930]
                            8001D91C	nop
                            8001D920	lui    a0, $8006
                            8001D924	lw     a0, $2f24(a0)
                            8001D928	jal    func46848 [$80046848]
                            8001D92C	ori    a1, zero, $0001

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
                            8001DA38	lui    at, $8006
                            8001DA3C	sw     v0, $2f24(at)
                            message = message + 1;
                            system_add_render_packet_to_queue;

                            8001DA48	addu   a0, zero, zero
                            8001DA4C	ori    a1, zero, $0001
                            8001DA50	ori    a2, zero, $03c0
                            8001DA58	ori    v0, zero, $0100
                            8001DA5C	sh     zero, $0010(sp)
                            8001DA60	sh     zero, $0012(sp)
                            8001DA64	sh     v0, $0014(sp)
                            8001DA68	sh     v0, $0016(sp)

                            [GP + 78] = h(h[GP + 78] - 1);

                            A3 = 100;
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
                            S6 = 0;
                            S4 = S4 + (letter / 15) * 0d; // letter row in texture * 0xd
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
                            [V1 + 07] = b(64);

                            A0 = w[80062f24];
                            A1 = 1;
                            func46870;

                            V0 = [GP + 7c];

                            if (V0 != 0)
                            {
                                A0 = w[80062f24];
                                A1 = 0;
                                8001DC74	jal    func46848 [$80046848]
                            }

                            V0 = w[80062f24];
                            [V0 + 08] = pos_x;
                            [V0 + 0a] = pos_y;
                            [V0 + 0c] = S6;
                            [V0 + 0d] = S4;
                            [V0 + 10] = h(0c);
                            [V0 + 12] = h(0c);

                            A0 = S3 | 0100;
                            A1 = S1;
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
// system_copy_text_from_kernel
800150E4	addiu  sp, sp, $fff8 (=-$8)
800150E8	addu   t2, zero, zero
800150EC	addu   t3, zero, zero
800150F0	lui    a3, $8006
800150F4	addiu  a3, a3, $3560
800150F8	addu   t5, a3, zero

loop150fc:	; 800150FC
T1 = [A0]; // opcode
A0 = A0 + 1; // address
T3 = T3 + 1; // readed size

if (T1 = F9)
{
    80015114	lbu    t1, $0000(a0)
    80015118	addiu  a0, a0, $0001
    8001511C	addiu  t3, t3, $0001
    80015120	addiu  v1, t3, $fffd (=-$3)
    80015124	andi   v0, t1, $003f
    80015128	subu   v1, v1, v0
    8001512C	srl    v0, t1, $06
    80015130	sll    v0, v0, $01
    80015134	addiu  t4, v0, $0004
    80015138	beq    t4, zero, L151c8 [$800151c8]
    8001513C	addu   t0, zero, zero
    80015140	addu   a2, t2, t5
    80015144	addu   v1, v1, a1

    loop15148:	; 80015148
    80015148	lbu    t1, $0000(v1)
    8001514C	addiu  v1, v1, $0001
    80015150	addiu  a3, a3, $0001
    80015154	addiu  t2, t2, $0001
    80015158	addiu  t0, t0, $0001
    8001515C	slt    v0, t0, t4
    80015160	sb     t1, $0000(a2)
    80015164	bne    v0, zero, loop15148 [$80015148]
    80015168	addiu  a2, a2, $0001
    80015170	andi   v1, t1, $00ff
}
else
{
    if ((T1 + 16) & FF < 08) // EA EB EC ED EE EF F0 F1 // character's names
    {
        [A3] = T1;
        A3 = A3 + 1; // store address
        V0 = [A0]
        A0 = A0 + 1; // address
        [A3] = V0;
        A3 = A3 + 1; // store address
        V0 = [A0];
        A0 = A0 + 1; // address
        [A3] = V0;
        A3 = A3 + 1; // store address

        T3 = T3 + 2; // readed size
        T2 = T2 + 3; // stored size
    }
    else
    {
        [A3] = [80063560] = T1;
        A3 = A3 + 1;
        T2 = T2 + 1; // stored size
    }

    800151C8	andi   v1, t1, $00ff
}

800151CC	ori    v0, zero, $00ff
800151D0	beq    v1, v0, L151e0 [$800151e0]
800151D4	sltiu  v0, t2, $0100
800151D8	bne    v0, zero, loop150fc [$800150fc]
800151DC	nop

L151e0:	; 800151E0
800151E0	lui    v0, $8006
800151E4	addiu  v0, v0, $3560
////////////////////////////////