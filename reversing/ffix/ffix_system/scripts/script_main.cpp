////////////////////////////////
// func52870
// main script function
S0 = A0; // pointer to first element in script list

while (S0 != 0)
{
    S1 = w[S0 + 4]; // pointer to allocated memory

    A1 = bu[S1 + e];
    if (A1 == 0)
    {
        [S1 + e] = b(2);
    }
    else if (A1 != 3)
    {
        S6 = w[S1 + 0];

        if (S6 != 0)
        {
            A0 = bu[S1 + d];
            if (A0 == 0)
            {
                // start of main script loop

                [8007b70c] = w(S1);
                [8007bcf8] = w(S1 + bu[S1 + 8] * 4);

                if (bu[S1 + 5] == 1)
                {
                    A0 = bu[S1 + 7] - 40;
                    func4b040; // get allocated memory for this script
                }
                else
                {
                    V0 = S1;
                }
                [8007b704] = w(V0);

                if (w[8007b708] == 2) // if this is battle
                {
                    A0 = S1;
                    func4bb30;
                }

                S2 = 0;
                while (S2 == 0)
                {
                    A0 = bu[S6];
                    S6 = S6 + 1;

                    switch (A0)
                    {
                        642B0580 30
                        842B0580 31
                        A42B0580 32
                        742B0580 6c
                        942B0580 6d

                        case 01: // 9C290580
                        {
                            S6 = S6 + h[S6] + 2;
                            800529B0	j      L52bcc [$80052bcc]
                        }
                        break;

                        case 02: // 68290580
                        {
                            S6 = S6 + 2;

                            system_read_from_stack_command_from_script;
                            if (V0 == 0)
                            {
                                S6 = S6 + h[S6 - 2];
                            }

                            80052988	j      L52bcc [$80052bcc]
                        }
                        break;

                        case 03: // 90290580
                        {
                            S6 = S6 + 2;

                            system_read_from_stack_command_from_script;
                            if (V0 != 0)
                            {
                                S6 = S6 + h[S6 - 2];
                            }

                            800529B0	j      L52bcc [$80052bcc]
                        }
                        break;

                        case 04: // B8290580
                        {
                            A0 = S1;
                            func38278;

                            800529C0	j      L52bd8 [$80052bd8]
                        }
                        break;

                        case 5:
                        {
                            system_script_parse_stack;

                            80052ABC	j      L52bcc [$80052bcc]
                        }
                        break;

                        case 6: // C8290580
                        {
                            T2 = bu[S6 + 0];

                            system_read_from_stack_command_from_script;
                            V0 = V0 & ffff;

                            A0 = 0;
                            if (T2 > 0)
                            {
                                loop529e0:	; 800529E0
                                    if (hu[S6 + 3 + A0 + 0] == V0)
                                    {
                                        S6 = S6 + hu[S6 + 3 + A0 + 2] + 3;
                                        80052A34	j      L52bcc [$80052bcc]
                                    }

                                    A0 = A0 + 4;
                                    T2 = T2 - 1;
                                800529FC	bgtz   t2, loop529e0 [$800529e0]
                            }

                            S6 = S6 + hu[S6 + 1] + 3;
                            80052A18	j      L52bcc [$80052bcc]
                        }
                        break;

                        case b: // 542A0580
                        {
                            T2 = bu[S6 + 0];
                            T3 = h[S6 + 1];
                            system_read_from_stack_command_from_script;

                            if (V0 >= T3 && V0 < T3 + T2)
                            {
                                A0 = S6 + (V0 - T3) * 2;
                                S6 = S6 + hu[A0 + 5];
                            }
                            else
                            {
                                S6 = S6 + hu[S6 + 3];
                            }

                            80052AAC	j      L52bcc [$80052bcc]
                        }
                        break;

                        case d: // 3C2A0580
                        {
                            T2 = hu[S6 + 0];
                            T3 = h[S6 + 2];
                            system_read_from_stack_command_from_script;

                            if (V0 >= T3 && V0 < T3 + T2)
                            {
                                A0 = S6 + (V0 - T3) * 2;
                                S6 = S6 + hu[A0 + 6] + 1;
                            }
                            else
                            {
                                S6 = S6 + hu[S6 + 4] + 1;
                            }

                            80052AAC	j      L52bcc [$80052bcc]
                        }
                        break;

                        case 1c: // C42A0580
                        {
                            A0 = bu[S6 + 1];
                            S6 = S6 + 2;

                            system_get_entity_script_data_pointer; // get entity memory
                            if (S1 == V0)
                            {
                                A0 = S1;
                                func36978;

                                S0 = V0;
                                S2 = 2;
                            }
                            else
                            {
                                A0 = V0;
                                func36978;
                            }

                            80052B00	j      L52bcc [$80052bcc]
                        }
                        break;

                        case 22: // 382B0580
                        {
                            S5 = bu[S6];
                            S6 = S6 + 1;
                            func52834;

                            if (V0 != 0)
                            {
                                A0 = V0 - fe;
                                if (A0 > 0)
                                {
                                    V0 = fd;
                                }
                                else
                                {
                                    V0 = V0 - 1;
                                }

                                [S1 + d] = b(V0);
                                S2 = 1;
                            }

                            80052B5C	j      L52bcc [$80052bcc]
                        }
                        break;



                        default: // 00, 07 - 0a, 0c, 0e - 1b, 1d - 21, 23 - 2f, 33 - 6b, 6e - ff: // 082B0580
                        {
                            S6 = S6 - 1;
                            [S1] = w(S6);

                            func39c38; // parse usual opcode
                            S2 = V0;

                            A0 = w[8007b6f8];
                            S6 = w[S1];
                            A0 = 0 < A0;
                            A0 = A0 XOR 1;
                            S6 = S6 - A0;
                            80052B30	j      L52bcc [$80052bcc]
                        }
                        break;
                    }

                    80052B64	jal    func51878 [$80051878]
                    80052B68	addiu  a0, zero, $0000
                    80052B6C	j      L52bcc [$80052bcc]
                    80052B70	nop
                    80052B74	jal    func51878 [$80051878]
                    80052B78	addiu  a0, zero, $0001
                    80052B7C	j      L52bcc [$80052bcc]
                    80052B80	nop
                    80052B84	jal    func51920 [$80051920]
                    80052B88	addiu  a0, zero, $0000
                    80052B8C	j      L52bcc [$80052bcc]
                    80052B90	nop
                    80052B94	jal    func51920 [$80051920]
                    80052B98	addiu  a0, zero, $0001
                    80052B9C	j      L52bcc [$80052bcc]
                    80052BA0	nop
                    80052BA4	lbu    s5, $0000(s6)
                    80052BA8	jal    func52834 [$80052834]
                    80052BAC	addiu  s6, s6, $0001
                    80052BB0	jal    func52834 [$80052834]
                    80052BB4	addu   t2, v0, zero
                    80052BB8	addu   a0, t2, zero
                    80052BBC	jal    func5127c [$8005127c]
                    80052BC0	addu   a1, v0, zero
                    80052BC4	j      L52bcc [$80052bcc]
                    80052BC8	nop

                    L52bcc:	; 80052BCC
                }

                [S1 + 0] = w(S6);

                L52bd8:	; 80052BD8
                if (S2 == 3 || S2 == 4 || S2 == 5 || S2 == 7 || S2 == 8)
                {
                    return S2;
                }
                if (S2 == 6)
                {
                    [8007b6fc] = w(S0);
                    return S2;
                }

                if (S2 == 2)
                {
                    continue; // continue global function cycle
                }
            }
            else if (A0 == fe)
            {
                A0 = bu[S1 + 10];
                if (A0 != ff)
                {
                    if (h[8007b9c0 + A0 * 2c + 8] == 0)
                    {
                        [S1 + 10] = b(ff);
                        [S1 + d] = b(0);
                    }
                }
                else
                {
                    [S1 + d] = b(0);
                }
            }
            else if (A0 != ff)
            {
                [S1 + d] = b(b[S1 + d] - 1);
            }
        }
    }

    S0 = w[S0 + 0];
}

return 0;
////////////////////////////////
