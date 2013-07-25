////////////////////////////////
// battle_opcodes_cycle
unit_id             = A0;
offset_to_ai_script = A1;
S5 = A2;
S6 = 0; // flag that indicates end of reading
S4 = 1;
address = w[80063014];
[800F4AC0] = w(offset_to_ai_script);
[800F4AC4] = w(address);
[V1 + 0] = w(unit_id);
[V1 + 4] = w(0); // offset in reading
[V1 + 8] = w(0200);

Lb1da0:	; 800B1DA0
    V1 = w[800f4ac0];
    A0 = w[800f4ac4];

    A1 = w[A0 + 4];
    V0 = A1 + 1;
    [A0 + 4] = w(V0);

    V0 = bu[V1 + A1]; // read opcode

    [A0 + c] = w(V0);
    V1 = w[A0 + c];

    V0 = V0 & F;
    [A0 + 10] = w(V0);

    V1 = V1 >> 4;
    [A0 + 14] = w(V1);

    if (V1 < B)
    {
        switch (V1)
        {
            case 0:
            {
                battle_opcodes_get_two_bytes;

                S1 = V0 & ffff;
                if (S1 >= 4000)
                {
                    S0 = 0;
                    loopb1e20:	; 800B1E20
                        V0 = w[800f4ac4];
                        A0 = S0;
                        A1 = w[V0 + c];
                        A2 = S1;
                        battle_opcodes_read_values;

                        A1 = w[800f4ac4];
                        [A1 + S0 * 4 + 2c] = w(V0);

                        S0 = S0 + 1;
                        V0 = S0 < a;
                    800B1E54	bne    v0, zero, loopb1e20 [$800b1e20]

                    [A1 + 28] = h(03ff);
                    A0 = w[A1 + 10];
                    A0 = A0 | 20;

                    battle_opcodes_store_values;
                }
                else
                {
                    V0 = w[800f4ac4];
                    A0 = w[V0 + 0];
                    A1 = w[V0 + c];
                    A2 = S1;
                    battle_opcodes_read_values;

                    V1 = w[800f4ac4];
                    A0 = w[V1 + c];
                    [V1 + 2c] = w(V0);
                    battle_opcodes_store_values;
                }
            }
            break;

            case 1:
            {
                V1 = w[800f4ac4];

                battle_opcodes_get_two_bytes;
                [V1 + 2c] = w(V0);

                A0 = w[V1 + c];
                battle_opcodes_store_values;
            }
            break;

            case 3:
            {
                V1 = w[800f4ac4];
                // set default for slot 2 cause we not always load it
                [V1 + 24] = w(0);
                [V1 + 1C] = w(0);
                [V1 + 2A] = h(03ff);

                V1 = w[V1 + 10];
                if (V1 != 7)
                {
                    A0 = 1;
                    battle_opcodes_load_values;
                }

                A0 = 0;
                battle_opcodes_load_values;

                S0 = 0;

                loopb1f08:	; 800B1F08
                    V0 = w[800f4ac4];
                    V1 = hu[V0 + 28];
                    V0 = hu[V0 + 2a];
                    V0 = V0 & V1;
                    V0 = V0 >> S0;
                    if (V0 & 1)
                    {
                        A0 = S0;
                        A1 = S0;
                        battle_opcodes_make_math;

                        A0 = w[800f4ac4];
                        [A0 + 2c + S0 * 4] = w(V0);
                    }

                    S0 = S0 + 1;
                    V0 = S0 < A;
                800B1F58	bne    v0, zero, loopb1f08 [$800b1f08]

                A1 = w[800F4AC4];
                A0 = w[A1 + 20];
                V1 = w[A1 + 24];
                if (A0 < V1)
                {
                    A0 = V1;
                }

                if (w[A1 + 18] != 0 || w[A1 + 1C] != 0)
                {
                    V0 = hu[A1 + 28];
                    V1 = hu[A1 + 2A];
                    A0 = A0 | 20;
                    V0 = V0 & V1;
                    [A1 + 28] = h(V0);
                }

                battle_opcodes_store_values;
            }
            break;

            case 4:
            {
                A0 = 1;
                battle_opcodes_load_values;

                A0 = 0;
                battle_opcodes_load_values;

                S0 = 0;
                S1 = 0

                loopb1fd8:	; 800B1FD8
                    V0 = w[800F4AC4];
                    V1 = hu[V0 + 28];
                    V0 = hu[V0 + 2A];
                    V0 = V0 & V1;
                    V0 = V0 >> S0;
                    V0 = V0 & 1;
                    if (V0 != 0)
                    {
                        A0 = S0;
                        A1 = S0;
                        battle_opcodes_make_comparsion;

                        if (V0 != 0)
                        {
                            V0 = 1 << S0;
                            S1 = S1 | V0;
                        }
                    }

                    S0 = S0 + 1;
                    V0 = S0 < A;
                800B2020	bne    v0, zero, loopb1fd8 [$800b1fd8]

                V1 = w[800F4AC4];
                if (w[V1 + 18] == 0 && w[V1 + 1C] == 0)
                {
                    V0 = S1 > 0;
                    [V1 + 2C] = w(V0);
                    A0 = 0;
                }
                else
                {
                    [V1 + 2C] = w(S1);
                    A0 = 02;
                }

                battle_opcodes_store_values;
            }
            break;

            case 5:
            {
                V0 = w[800F4AC4];
                V1 = w[V0 + 10];

                if (V1 == 0)
                {
                    A0 = 1;
                    battle_opcodes_load_values;

                    A0 = 0;
                    battle_opcodes_load_values;

                    A0 = 1;
                    battle_opcodes_value_convert_to_bool;
                    S0 = V0;

                    A0 = 0;
                    battle_opcodes_value_convert_to_bool;


                    V1 = w[800f4ac4];
                    S0 = S0 & V0;
                    [V1 + 2c] = w(S0);

                    A0 = 0;
                    battle_opcodes_store_values;
                }
                else if (V1 == 1)
                {
                    A0 = 1;
                    battle_opcodes_load_values;

                    A0 = 0;
                    battle_opcodes_load_values;

                    A0 = 1;
                    battle_opcodes_value_convert_to_bool;
                    S0 = V0;

                    A0 = 0;
                    battle_opcodes_value_convert_to_bool;


                    V1 = w[800f4ac4];
                    S0 = S0 | V0;
                    [V1 + 2c] = w(S0);

                    A0 = 0;
                    battle_opcodes_store_values;
                }
                else if (V1 == 2)
                {
                    A0 = 0;
                    battle_opcodes_load_values;

                    A0 = 0;
                    battle_opcodes_value_convert_to_bool;

                    V1 = w[800f4ac4];
                    [V1 + 2c] = w(V0 < 1);

                    A0 = 0;
                    battle_opcodes_store_values;
                }
            }
            break;

            case 6:
            {
                address = w[800f4ac4];
                type    = w[address + 10];
                [address + 2c] = w(0);

                A2 = 0;
                V0 = w[address + 4];
                if (type == 2)
                {
                    A2 = A2 + 1;
                    V1 = bu[offset_to_ai_script + V0 + 2];
                    [address + 2c] = w(V1 << 10);
                }
                if (type == 2 || type == 1)
                {
                    A2 = A2 + 1;
                    V1 = bu[offset_to_ai_script + V0 + 1];
                    [address + 2c] = w(w[address + 2c] | (V0 << 8));
                }
                if (type == 2 || type == 1 || type == 0)
                {
                    A2 = A2 + 1;
                    V1 = bu[offset_to_ai_script + V0 + 1];
                    [address + 2C] = w(w[address + 2c] | V1);
                }

                [address + 4] = w(V0 + A2);

                A0 = A2;
                battle_opcodes_store_values;
            }
            break;

            case 7:
            {
                V0 = w[800F4AC4];
                V1 = w[V0 + 10];

                switch (V1)
                {
                    case 0:
                    {
                        battle_opcodes_get_two_bytes
                        S0 = V0;

                        A0 = 0;
                        battle_opcodes_load_values;

                        A0 = 0;
                        battle_opcodes_expand_copy_2_data_type;

                        V1 = w[800F4AC4];
                        V0 = w[V1 + 2C];
                        if (V0 == 0)
                        {
                            [V1 + 4] = w(S0);
                        }
                    }
                    break;

                    case 1:
                    {
                        battle_opcodes_get_two_bytes;
                        S0 = V0;

                        A0 = 1;
                        battle_opcodes_load_values;

                        A0 = 1;
                        battle_opcodes_expand_copy_2_data_type;

                        A0 = 0
                        battle_opcodes_load_values_without_pop;

                        A0 = 0;
                        battle_opcodes_expand_copy_2_data_type;

                        A0 = w[800F4AC4];
                        V1 = w[A0 + 2C];
                        V0 = w[A0 + 54];

                        if (V1 != V0)
                        {
                            [A0 + 4] = w(S0);
                        }
                    }
                    break;

                    case 2:
                    {
                        battle_opcodes_get_two_bytes;

                        V1 = w[800F4AC4];
                        [V1 + 4] = w(V0);
                    }
                    break;

                    case 3:
                    {
                        S6 = 1;
                    }
                    break;

    F0290B80 // 4
                    800B29F0	jal    battle_opcodes_load_values [$800b18a8]
                    800B29F4	addu   a0, zero, zero
                    800B2324	j      Lb29f8 [$800b29f8]

                    case 5:
                    {
                        A0 = 0;
                        battle_opcodes_load_values;

                        if (S5 >= 0)
                        {
                            V0 = w[800f4ac4];
                            A1 = w[V0 + 2c];
                            A0 = S5;

                            [800e7a58 + A0] = b(A1);
                        }
                    }
                    break;
                }
            }
            break;

            case 8:
            {
                V0 = w[800f4ac4];
                V1 = w[V0 + 10];
                if (V1 < 8)
                {
                    switch (V1)
                    {
                        case 0:
                        {
                            A0 = 0;
                            battle_opcodes_load_values_without_pop;

                            V0 = w[800f4ac4];
                            V0 = w[V0 + 18];
                            if (V0 != 1) // if not address
                            {
                                // load value
                                A0 = 0;
                                battle_opcodes_load_values;
                                S0 = V0;

                                // load mask
                                A0 = 1;
                                battle_opcodes_load_values;

                                V1 = w[800f4ac4];
                                mask = w[V1 + 54];
                                V0 = hu[V1 + 28];
                                V0 = V0 & mask;
                                [V1 + 28] = h(V0);

                                A0 = S0; // type
                                battle_opcodes_store_values;
                            }
                        }
                        break;

                        case 1:
                        {
                            battle_opcodes_get_random;

                            V1 = w[800F4AC4];
                            [V1 + 2C] = w(V0);
                            A0 = 02;
                            battle_opcodes_store_values;
                        }
                        break;

                        case 2:
                        {
                            A0 = 0;
                            battle_opcodes_load_values;

                            V1 = w[800F4AC4];
                            A0 = hu[V0 + 2C];
                            battle_opcodes_get_random_bit;
                            V0 = V0 & FFFF;
                            [V1 + 2C] = w(V0);

                            A0 = 02;
                            battle_opcodes_store_values;
                        }
                        break;

                        case 3:
                        {
                            S0 = 1;

                            A0 = 0;
                            battle_opcodes_load_values;

                            A0 = 0;
                            battle_opcodes_expand_copy_2_data_type;

                            if (V0 != 0)
                            {
                                V0 = w[800f4ac4];
                                S0 = w[V0 + 20];
                            }
                            else
                            {
                                V0 = w[800f4ac4];
                                A0 = w[V0 + 2c];

                                A0 = A0 & 3ff;
                                battle_opcodes_count_active_bits;

                                V1 = w[800f4ac4];
                                [V1 + 2c] = w(V0);
                            }

                            A0 = S0;
                            battle_opcodes_store_values;
                        }
                        break;

                        case 4:
                        {
                            A0 = 0;
                            battle_opcodes_load_values;

                            A1 = w[800f4ac4];
                            mask = hu[A1 + 28];

                            S1 = 0;
                            new_mask = 0000;

                            A0 = 0;
                            loopb2554:	; 800B2554
                                V0 = mask >> A0;
                                if (V0 & 1)
                                {
                                    V1 = w[A1 + 2c + A0 * 4];
                                    if (V1 == S1)
                                    {
                                        V0 = 1 << A0;
                                        new_mask = new_mask | V0;
                                    }
                                    else if (V1 > S1)
                                    {
                                        S1 = V1;
                                        new_mask = 1 << A0;
                                    }
                                }

                                A0 = A0 + 1;
                                V0 = A0 < a;
                            800B259C	bne    v0, zero, loopb2554 [$800b2554]

                            V1 = w[800f4ac4];
                            [V1 + 2c] = w(S0 & ffff);

                            A0 = 2;
                            battle_opcodes_store_values;
                        }
                        break;

                        case 5:
                        {
                            A0 = 0;
                            battle_opcodes_load_values;

                            A1 = w[800f4ac4];
                            mask = hu[A1 + 28];

                            S1 = 00ffffff;
                            new_mask = 0000;

                            A0 = 0;
                            loopb2554:	; 800B2554
                                V0 = mask >> A0;
                                if (V0 & 1)
                                {
                                    V1 = w[A1 + 2c + A0 * 4];
                                    if (V1 == S1)
                                    {
                                        V0 = 1 << A0;
                                        new_mask = new_mask | V0;
                                    }
                                    else if (V1 < S1)
                                    {
                                        S1 = V1;
                                        new_mask = 1 << A0;
                                    }
                                }

                                A0 = A0 + 1;
                                V0 = A0 < a;
                            800B259C	bne    v0, zero, loopb2554 [$800b2554]

                            V1 = w[800f4ac4];
                            [V1 + 2c] = w(S0 & ffff);

                            A0 = 2;
                            battle_opcodes_store_values;
                        }
                        break;

                        case 6:
                        {
                            A0 = 0;
                            battle_opcodes_load_values;

                            V1 = w[800f4ac4];
                            A0 = w[V1 + 2c];
                            funcb2c60;
                            [V1 + 2c] = w(V0);

                            A0 = 2;
                            battle_opcodes_store_values;
                        }
                        break;

                        case 7:
                        {
                            A0 = 0
                            battle_opcodes_load_values;

                            V1 = w[800f4ac4];
                            V0 = w[V1 + 2c];
                            V0 = 1 << V0;
                            [V1 + 2c] = w(V0);

                            A0 = 2;
                            battle_opcodes_store_values;
                        }
                        break;
                    }
                }
            }
            break;

            case 9:
            {
                V0 = w[800F4AC4];
                V1 = w[V0 + 10];
                if (V1 < 7)
                {
                    switch (V1)
                    {
                        case 0:
                        {
                            // load value
                            A0 = 0;
                            battle_opcodes_load_values;
                            A0 = 0;
                            battle_opcodes_expand_copy_2_data_type;

                            // load address
                            A0 = 1;
                            battle_opcodes_load_values;

                            V1 = w[800f4ac4];
                            address = w[V1 + 54];
                            value_variable_type = w[V1 + 24];
                            if (address >= 4000)
                            {
                                A0 = 1;
                                battle_opcodes_load_values;

                                V0 = w[800f4ac4];
                                A0 = w[V0 + 0];
                                A1 = w[V0 + 24];
                                A2 = w[V0 + 54];
                                battle_opcodes_read_values;
                                S1 = V0;

                                S0 = 0;

                                loopb26b0:	; 800B26B0
                                    V0 = 1 << S0;
                                    if (S1 & V0)
                                    {
                                        A0 = S0;
                                        A1 = value_variable_type;
                                        A2 = address;
                                        V0 = w[800F4AC4];
                                        A3 = w[V0 + 2C];
                                        battle_opcodes_write_values;
                                    }

                                    S0 = S0 + 1;
                                    V0 = S0 < a;
                                800B26DC	bne    v0, zero, loopb26b0 [$800b26b0]
                            }
                            else
                            {
                                A0 = w[V1 + 0];
                                A1 = value_variable_type;
                                A2 = address;
                                A3 = w[V1 + 2c];
                                battle_opcodes_write_values;
                            }
                        }
                        break;

                        case 1:
                        {
                            A0 = 0;
                            battle_opcodes_load_values;
                        }
                        break;

                        case 2:
                        {
                            A0 = 1;
                            battle_opcodes_load_values;

                            A0 = 0;
                            battle_opcodes_load_values;

                            A0 = hu[800F83A4 + 0C]; // self unit mask
                            get_last_significant_bit_number;

                            V1 = w[800F4AC4];
                            A0 = V0;
                            A1 = h[V1 + 2C];
                            A2 = h[V1 + 54];
                            funcb2b5c;
                        }
                        break;

                        case 3:
                        {
                            offset = w[800f4ac4];
                            script = w[800f4ac0];
                            A0 = w[offset + 4]; // reading_offset

                            A0 = script + A0;
                            A1 = 800f83d8;
                            funca5eb0;

                            V0 = V0 + 0100;

                            A0 = h[offset + 0];
                            A1 = 21;
                            A2 = V0 & ffff;
                            funcb2b5c;

                            V1 = w[offset + 4];
                            V0 = V1 + 1;
                            [offset + 4] = w(V0);

                            A0 = bu[script + V1];
                            if (A0 != ff)
                            {
                                loopb27c8:	; 800B27C8
                                    V0 = A0 + 16;
                                    V0 = V0 & ff;
                                    if (V0 < 8)
                                    {
                                        V0 = w[offset + 4];
                                        V0 = V0 + 2;
                                        [offset + 4] = w(V0);
                                    }

                                    V1 = w[offset + 4];
                                    V0 = V1 + 1;
                                    [offset + 4] = w(V0);

                                    A0 = bu[script + V1];
                                800B2804	bne    a0, ff, loopb27c8 [$800b27c8]
                            }
                        }
                        break;

                        case 4:
                        {
                            A0 = 1;
                            battle_opcodes_load_values;

                            A0 = 0;
                            battle_opcodes_load_values;

                            S1 = 0;

                            loopb2828:	; 800B2828
                                V0 = w[800f4ac4];
                                V0 = w[V0 + 54];
                                V1 = 1 << S1;
                                if (V0 & V1)
                                {
                                    S0 = 0;
                                    loopb2848:	; 800B2848
                                        V0 = w[800f4ac4];
                                        V1 = w[V0 + 2c];
                                        V0 = 1 << S0;
                                        if (V1 & V0)
                                        {
                                            A0 = S0;
                                            A1 = S1;
                                            funcb2cfc;
                                        }

                                        S0 = S0 + 1;
                                        V0 = S0 < a;
                                    800B2878	bne    v0, zero, loopb2848 [$800b2848]
 
                                    break;
                                }

                                S1 = S1 + 1;
                                V0 = S1 < a;
                            800B2890	bne    v0, zero, loopb2828 [$800b2828]
                        }
                        break;

                        case 5:
                        {
                            A0 = 1;
                            battle_opcodes_load_values;

                            A0 = 0;
                            battle_opcodes_load_values;

                            V0 = w[800f4ac4];
                            A0 = w[V0 + 2c];
                            A1 = w[V0 + 54];
                            funcb2cac;
                        }
                        break;

                        case 6:
                        {
                            A0 = 1;
                            battle_opcodes_load_values;

                            A0 = 0;
                            battle_opcodes_load_values;

                            V0 = w[800f4ac4];
                            A0 = w[V0 + 2c];
                            A1 = w[V0 + 54];
                            A2 = 0;
                            funcae764;
                        }
                        break;
                    }
                }
            }
            break;

            case a:
            {
                A0 = w[800f4ac4];
                V0 = w[A0 + 10];
                if (V0 == 0)
                {
                    V0 = w[A0 + 4];
                    A1 = w[800f4ac0];
                    V1 = V0 + 1;
                    V0 = A1 + V0;
                    [A0 + 4] = w(V1);
                    S2 = bu[V0];
                    V1 = A1 + V1;
                    [SP + 10] = w(V1);
                    V1 = w[A0 + 4];
                    V0 = V1 + 1;
                    V1 = A1 + V1;
                    [A0 + 4] = w(V0);
                    V0 = bu[V1];
                    if (V0 != 0)
                    {
                        loopb297c:	; 800B297C
                            V0 = w[A0 + 4];
                            V1 = V0 + 1;
                            V0 = A1 + V0;
                            [A0 + 4] = w(V1);
                            V0 = bu[V0];
                        800B2998	bne    v0, zero, loopb297c [$800b297c]
                    }

                    if (S2 != 0)
                    {
                        S0 = 0;
                        loopb29ac:	; 800B29AC
                            A0 = 0;
                            battle_opcodes_load_values;

                            A0 = 0;
                            battle_opcodes_expand_copy_2_data_type;

                            V0 = w[800f4ac4];
                            V0 = w[V0 + 2c];
                            S0 = S0 + 1;
                            [SP + 10 + S0 * 4 + 4] = w(V0);
                            V0 = S0 < S2;
                        800B29D8	bne    v0, zero, loopb29ac [$800b29ac]
                    }
                }
                else if (V0 == 1)
                {
                    800B29E8	jal    battle_opcodes_load_values [$800b18a8]
                    800B29EC	ori    a0, zero, $0001
                    800B29F0	jal    battle_opcodes_load_values [$800b18a8]
                    800B29F4	addu   a0, zero, zero
                }
            }
            break;
        }
    }

    F8290B80 // 2
    Lb29f8:	; 800B29F8
800B29F8	beq    s6, zero, Lb1da0 [$800b1da0]

return;
////////////////////////////////



////////////////////////////////
// battle_opcodes_get_two_bytes
script_offset = w[800f4ac0];

A2 = w[800f4ac4];
offset = w[A2 + 4];
[A2 + 4] = w(offset + 2);

A0 = bu[script_offset + offset + 0];
V0 = bu[script_offset + offset + 1];
V0 = V0 << 8;
V0 = A0 | V0;
return V0;
////////////////////////////////



////////////////////////////////
// battle_opcodes_values_offset
unit_id = A0;

if (A1 < 2000)
{
    [A2] = w(800f87f0 + unit_id * 80);
}
else if (A1 < 4000)
{
    [A2] = w(800f83a4);
    A1 = A1 - 2000;
}
else
{
    [A2] = w(800f83e0 + unit_id * 68);
    A1 = A1 - 4000;
}

return A1;
////////////////////////////////



////////////////////////////////
// battle_opcodes_read_values
unit_id     = A0;
opcode      = S0 = A1; // opcode
opcode_data = A1 = A2; // result
A2 = SP + 10;
battle_opcodes_values_offset;
V1 = V0;

if (S0 == 0)
{
    A1 = w[SP + 10];
    V0 = V1 >> 3;
    V0 = bu[A1 + V0];
    V1 = V1 & 7;
    V0 = V1 >> V0;
    S1 = V0 & 1;
}
else if (S0 == 1)
{
    A1 = w[SP + 10];
    V0 = V1 >> 3;
    S1 = bu[A1 + V0];
}
else if (S0 == 02)
{
    A1 = w[SP + 10];
    V0 = V1 >> 4;
    V0 = V0 << 1;
    S1 = hu[A1 + V0];
}
else if (V0 == 03)
{
    A1 = w[SP + 10];
    V0 = V1 >> 5;
    V0 = V0 << 2;
    S1 = w[A1 + V0];
}

return S1;
////////////////////////////////



////////////////////////////////
// battle_opcodes_write_values
unit_id     = A0;
variable_type = A1;
address     = A2;
value       = S1 = A3;

A0 = unit_id;
A1 = address;
A2 = SP + 10;
battle_opcodes_values_offset;

if (variable_type == 0)
{
    A0 = w[SP + 10];
    A2 = V0 >> 3;
    V0 = V0 & 7;
    A1 = 1 << V0;
    V1 = bu[A0 + A2];
    V0 = 0 NOR A1;
    V0 = V1 & V0;
    if (S1 != 0)
    {
        V0 = V0 | A1;
    }
    [A0 + A2] = b(V0);
}
else if (variable_type == 1)
{
    A0 = w[SP + 10]; // address to write
    V1 = V1 >> 3;
    [A0 + V1] = b(S1);
}
else if (variable_type == 2)
{
    A0 = w[SP + 10];
    V1 = V1 >> 4;
    V1 = V1 << 1;
    [A0 + V1] = h(S1);
}
else if (variable_type == 3)
{
    A0 = w[SP + 10];
    V1 = V1 >> 5;
    V1 = V1 << 2;
    [A0 + V1] = w(S1);
}

return;
////////////////////////////////



////////////////////////////////
// battle_opcodes_push_to_stack
V1 = w[800f4ac4];

if (A0 == 3)
{
    V0 = w[V1 + 8];
    V0 = V0 - 1;
    [V1 + 8] = w(V0);
    [V1 + V0 + 7c] = b(A1);
    A1 = A1 >> 8;
}

if (A0 == 2 || A0 == 3)
{
    V0 = w[V1 + 8];
    V0 = V0 - 1;
    [V1 + 8] = w(V0);
    [V1 + V0 + 7c] = b(A1);
    A1 = A1 >> 8;
}

if (A0 == 0 || A0 == 1 || A0 == 2 || A0 == 3)
{
    V0 = w[V1 + 8];
    V0 = V0 - 1;
    [V1 + 8] = w(V0);
    [V1 + V0 + 7c] = b(A1);
}
////////////////////////////////



////////////////////////////////
// battle_opcodes_pop_from_stack
A1 = 0;

if (A0 == 3)
{
    V0 = w[800F4AC4];
    A0 = w[V0 + 8];
    V1 = A0 + 1;
    [V0 + 8] = w(V1);
    A1 = bu[V0 + A0 + 7C];
}

if (A0 == 3 || A0 == 2)
{
    V0 = w[800F4AC4];
    A0 = w[V0 + 8];
    V1 = A0 + 1;
    [V0 + 8] = w(V1);
    V0 = bu[V0 + A0 + 7C];
    A1 = A1 << 8;
    A1 = A1 | V0;
}

if (A0 == 3 || A0 == 2 || A0 == 1 || A0 == 0)
{
    V0 = w[800F4AC4];
    A0 = w[V0 + 8];
    V1 = A0 + 1;
    [V0 + 8] = w(V1);
    V0 = bu[V0 + A0 + 7C];
    A1 = A1 << 8;
    A1 = A1 | V0;
}

return A1;
////////////////////////////////



////////////////////////////////
// battle_opcodes_store_values
S2 = A0; // opcode
V1 = S2 >> 4;
S1 = S2 & F;

if (V1 == 0)
{
    V0 = w[800f4ac4];
    A0 = S1;
    A1 = w[V0 + 2c];
    battle_opcodes_push_to_stack;
}
else if (V1 == 1)
{
    V0 = w[800f4ac4];
    A0 = 2;
    A1 = w[V0 + 2c];
    battle_opcodes_push_to_stack;
}
else if (V1 == 2)
{
    V1 = A;

    Lb1758:	; 800B1758
        V1 = V1 - 1;
        A0 = w[800F4AC4];
        V0 = hu[A0 + 28];
        V0 = V0 >> V1;
        V0 = V0 & 1;
        if (V0 != 0)
        {
            A1 = w[A0 + V1 * 4 + 2C];
            A0 = S1;
            battle_opcodes_push_to_stack;
        }
    800B1790	bgtz   v1, Lb1758 [$800b1758]

    V0 = w[800F4AC4];
    A0 = 2;
    A1 = hu[V0 + 28];
    battle_opcodes_push_to_stack;
}

// push opcode to stack
V1 = w[800f4ac4];
V0 = w[V1 + 8];
V0 = V0 - 1;
[V1 + 8] = w(V0);
[V1 + V0 + 7c] = b(S2);

return;
////////////////////////////////



////////////////////////////////
// battle_opcodes_load_values
slot = A0; // slot to store

// pop variable type from stack
A1 = w[800F4AC4];
V0 = w[A1 + 8];
V1 = V0 + 1;
[A1 + 8] = w(V1);

S5 = bu[A1 + V0 + 7c]; // stored variable type
data_type = S5 >> 4;
S4 = S5 & F;
[A1 + slot * 4 + 18] = w(data_type); // upper
[A1 + slot * 4 + 20] = w(S4); // lower

if (data_type == 0)
{
    [A1 + slot * 2 + 28] = h(03ff);

    A0 = S4;
    battle_opcodes_pop_from_stack;
    A0 = V0;

    S0 = 9;
    V1 = w[800f4ac4];
    V0 = V1 + slot * 28 + 50;

    loopb196c:	; 800B196C
        [V0] = w(A0);
        S0 = S0 - 1;
        V0 = V0 - 4;
    800B1974	bgez   s0, loopb196c [$800b196c]
}
else if (data_type == 1)
{
    A0 = 2;
    battle_opcodes_pop_from_stack;

    A0 = w[800f4ac4];
    [A0 + slot * 28 + 2C] = w(V0);
}
else if (data_type == 2)
{
    // pop mask
    A0 = 2;
    battle_opcodes_pop_from_stack;
    // store mask to slot
    V1 = w[800f4ac4];
    [V1 + slot * 2 + 28] = h(V0);

    S0 = 0;
    loopb19d4:	; 800B19D4
        V0 = w[800f4ac4];
        V0 = hu[V0 + slot * 2 + 28];
        V0 = V0 >> S0;
        if (V0 & 1)
        {
            A0 = S4;
            battle_opcodes_pop_from_stack;

            A0 = w[800f4ac4];
            [A0 + slot * 28 + S0 * 4 + 2c] = w(V0);
        }

        S0 = S0 + 1;
        V0 = S0 < a;
    800B1A28	bne    v0, zero, loopb19d4 [$800b19d4]
}

return S5;
////////////////////////////////



////////////////////////////////
// battle_opcodes_expand_copy_2_data_type
slot = A0;

A1 = 0;
A2 = w[800f4ac4];
data_type = w[A2 + slot * 4 + 18];
if (data_type == 2)
{
    mask = hu[A2 + slot * 2 + 28];
    A3 = 0;
    loopb1cd4:	; 800B1CD4
        V0 = mask >> A1;
        if (V0 & 1)
        {
            A3 = w[A2 + slot * 28 + 2c + A1 * 4];
            break;
        }

        A1 = A1 + 1;
        V0 = A1 < a;
    800B1CF4	bne    v0, zero, loopb1cd4 [$800b1cd4]

    V1 = w[800f4ac4];
    [V1 + slot * 2 + 28] = h(3ff);

    A1 = 9;
    A2 = V1 + slot * 28 + 50;
    loopb1d2c:	; 800B1D2C
        [A2] = w(A3);
        A1 = A1 - 1;
        A2 = A2 - 4;
    800B1D34	bgez   a1, loopb1d2c [$800b1d2c]

    A1 = 1;
}

return A1;
////////////////////////////////



////////////////////////////////
// battle_opcodes_load_values_without_pop
V0 = w[800F4AC4];
S0 = w[V0 + 8];
battle_opcodes_load_values

V1 = w[800F4AC4];
[V1 + 8] = w(S0);

return V0;
////////////////////////////////



////////////////////////////////
// battle_opcodes_make_comparsion
V0 = w[800f4ac4];
A0 = V0 + A0 * 4;
A1 = V0 + A1 * 4;

V1 = w[V0 + c];

A2 = w[A0 + 2c];
A0 = w[A1 + 54];
switch (V1)
{
    case 40: return (A2 == A0) ? 1 : 0;
    case 41: return (A2 != A0) ? 1 : 0;
    case 42: return (A2 >= A0) ? 1 : 0;
    case 43: return (A2 <= A0) ? 1 : 0;
    case 44: return (A2 >  A0) ? 1 : 0;
    case 45: return (A2 <  A0) ? 1 : 0;
}

return 0;
////////////////////////////////



////////////////////////////////
// battle_opcodes_make_math
V0 = w[800f4ac4];
A0 = V0 + A0 * 4;
A1 = V0 + A1 * 4;

V1 = w[V0 + c];

A2 = w[A0 + 2c];
A0 = w[A1 + 54];

switch (V1)
{
    case 30: return A2  +  A0;
    case 31: return A2  -  A0;
    case 32: return A2  *  A0;
    case 33: return A2  /  A0;
    case 34: return A2 mod A0;
    case 35: return A2  &  A0;
    case 36: return A2  |  A0;
    case 37: return 0  nor A2;
}

return 0;
////////////////////////////////



////////////////////////////////
// battle_opcodes_value_convert_to_bool
V1 = w[800f4ac4];
mask = hu[V1 + 28 + A0 * 2];

A3 = 0;
A1 = 0;

loopb1c50:	; 800B1C50
    V0 = mask >> A1;
    if (V0 & 1)
    {
        V0 = w[V1 + 2c + A0 * 28 + A1 * 4];
        if (V0 != 0)
        {
            V0 = 1 << A1;
            A3 = A3 | V0;
        }
    }

    A1 = A1 + 1;
    V0 = A1 < a;
800B1C80	bne    v0, zero, loopb1c50 [$800b1c50]

return A3 > 0;
////////////////////////////////



////////////////////////////////
// battle_opcodes_get_random
system_random_two_bytes;

V0 = V0 & FFFF;
return V0
////////////////////////////////



////////////////////////////////
// battle_opcodes_get_random_bit
800B3030	addiu  sp, sp, $ffe0 (=-$20)
800B3034	sw     s2, $0018(sp)
800B3038	addu   s2, a0, zero
800B303C	sw     s1, $0014(sp)
800B3040	addu   s1, zero, zero
800B3044	andi   a0, s2, $ffff
800B3048	sw     ra, $001c(sp)
800B304C	jal    battle_opcodes_count_active_bits [$800b3000]
800B3050	sw     s0, $0010(sp)
800B3054	addu   s0, v0, zero
800B3058	beq    s0, zero, Lb30c8 [$800b30c8]
800B305C	andi   v0, s1, $ffff
800B3060	jal    funcb2f30 [$800b2f30]
800B3064	ori    s1, zero, $0001
800B3068	andi   v0, v0, $00ff
800B306C	div    v0, s0
800B3070	bne    s0, zero, Lb307c [$800b307c]
800B3074	nop
800B3078	break   $01c00

Lb307c:	; 800B307C
800B307C	addiu  at, zero, $ffff (=-$1)
800B3080	bne    s0, at, Lb3094 [$800b3094]
800B3084	lui    at, $8000
800B3088	bne    v0, at, Lb3094 [$800b3094]
800B308C	nop
800B3090	break   $01800

Lb3094:	; 800B3094
800B3094	mfhi   s0
800B3098	and    v0, s2, s1

loopb309c:	; 800B309C
800B309C	andi   v0, v0, $ffff
800B30A0	beq    v0, zero, Lb30b4 [$800b30b4]
800B30A4	nop
800B30A8	addiu  s0, s0, $ffff (=-$1)
800B30AC	bltz   s0, Lb30c8 [$800b30c8]
800B30B0	andi   v0, s1, $ffff

Lb30b4:	; 800B30B4
800B30B4	sll    s1, s1, $01
800B30B8	andi   v0, s1, $ffff
800B30BC	bne    v0, zero, loopb309c [$800b309c]
800B30C0	and    v0, s2, s1
800B30C4	andi   v0, s1, $ffff

Lb30c8:	; 800B30C8
800B30C8	lw     ra, $001c(sp)
800B30CC	lw     s2, $0018(sp)
800B30D0	lw     s1, $0014(sp)
800B30D4	lw     s0, $0010(sp)
800B30D8	addiu  sp, sp, $0020
800B30DC	jr     ra 
800B30E0	nop
////////////////////////////////



////////////////////////////////
// set attack
// funcb2b5c
S0 = A0; // self unit_id
S1 = A1; // 0x20

if( S1 == 3 )
{
    A2 = A2 - 38;
}
else if( S1 == d )
{
    A2 = A2 - 48;
}
else if( S1 == 20 )
{
    A0 = A2;
    battle_get_attack_index_by_attack_id;
    A2 = V0;
}

A0 = SP + 10;
A1 = hu[800f83a4 + 0e]; // attack mask
[800f83e0 + S0 * 68 + 18] = h(A1);

[SP + 10] = b(w[800f4ac8]);
[SP + 12] = b(S0);
[SP + 13] = b(S1);
[SP + 14] = h(A2);
[SP + 16] = h(A1);
funca3d4c;
////////////////////////////////



////////////////////////////////
// funca3d4c
T0 = A0;

priority = bu[T0 + 0];
A3 = 800f692c + 8;

V1 = 0;
loopa3d6c:	; 800A3D6C
    if( bu[800f692c + 8 + V1] == ff )
    {
        [T0 + 1] = b(bu[800f6b9b + priority]);

        [A3 + 0] = w(w[T0 + 0]);
        [A3 + 4] = w(w[T0 + 4]);


        [800f6b9b + priority] = b(bu[800f6b9b + priority] + 1);
        [800f7dde] = h(priority);

        if( bu[T0 + 0] < 2 )
        {
            return;
        }

        V0 = b[T0 + 2];

        [800f83e0 + V0 * 68 + 4] = w(w[800f83e0 + V0 * 68 + 4] & ffffffdf)

        if( ( bu[T0 + 3] & 3f ) != 13 )
        {
            return;
        }

        [800f83e0 + V0 * 68 + 4] = w(w[800f83e0 + V0 * 68 + 4] | 00000020)

        return;
    }

    V1 = V1 + 8;
    A3 = A3 + 8;
    V0 = V1 < 200;
800A3E88	bne    v0, zero, loopa3d6c [$800a3d6c]
////////////////////////////////



////////////////////////////////
// battle_get_attack_index_by_attack_id
S0 = 0;
V1 = 800F64EC; // attack id data in scene file.

loopb11cc:	; 800B11CC
    V0 = hu[V1];
    if (V0 == A0)
    {
        break;
    }
    S0 = S0 + 1;
    V0 = S0 < 20;
    V1 = V1 + 2;
800B11E4	bne    v0, zero, loopb11cc [$800b11cc]

if (S0 == 20)
{
    A0 = 20;
    func155a4;
}

return S0;
////////////////////////////////



////////////////////////////////
// funcb2c60
S0 = 0;
if (A0 <= fffe)
{
    funcb2ebc;
    if (V0 != 0)
    {
        S0 = hu[V0 + 4];
    }
}

return S0;
////////////////////////////////



////////////////////////////////
// funcb2ebc
if (A0 < 100)
{
    return 800708c4 + A0 * 1c;
}

A2 = 0
loopb2f08:	; 800B2F08
    V0 = hu[800f64ec + A2 * 2];
    if (V0 == A0)
    {
        return 800f616c + A2 * 1c;
    }

    A2 = A2 + 1;
    V0 = A2 < 20;
800B2F20	bne    v0, zero, loopb2f08 [$800b2f08]

return 0;
////////////////////////////////



////////////////////////////////
// funcb2cac
if (A0 == 0)
{
    [800f83a6] = b(bu[8009d288 + A1]);
}
else if (A0 == 1)
{
    [8009d288 + A1] = b(bu[800f83a6]);
}

return;
////////////////////////////////



////////////////////////////////
// funcae764
S4 = A0;
S5 = A1;
S6 = A2;

mask = 0;

S0 = 0;
loopae7b0:	; 800AE7B0
    [800f83e0 + S0 * 68 + b] = b(3);

    V0 = S4 >> S0;
    if (V0 & 1)
    {
        A0 = S0;
        A1 = S5;
        A2 = S6;
        funcae6c0;

        if (V0 != 3)
        {
            [800f83e0 + S0 * 68 + b] = b(V0);
            V0 = 1 << S0;
            mask = mask | V0;
        }
    }

    S0 = S0 + 1;
    V0 = S0 < a;
800AE7EC	bne    v0, zero, loopae7b0 [$800ae7b0]

[800f83a4 + e] = h(mask); // store attack mask
////////////////////////////////


////////////////////////////////
// funcae6c0
unit_id = A0;
S0 = A1; // 8
S1 = A2; // 0
A0 = S0;
A1 = S1;
A2 = unit_id;
A3 = SP + 18;
[SP + 10] = w(0);
[SP + 14] = w(0);
funcae42c;

A0 = 0;
loopae700:	; 800AE700
    V0 = w[SP + 18 + A0 * 4];
    V1 = w[SP + 38 + A0 * 4];
    if ((V0 & S0) == 0 && (V1 & S1) == 0)
    {
        break;
    }

    A0 = A0 + 1;
    V0 = A0 < 8;
800AE730	bne    v0, zero, loopae700 [$800ae700]

if (A0 == 8)
{
    A0 = 3;
}

return A0;
////////////////////////////////



////////////////////////////////
// funcae42c
S3 = A0;
S2 = A1;
unit_id = S1 = A2;
S0 = A3;

A1 = 0;
loopae464:	; 800AE464
    [S0 + A1 * 4] = w(0);
    [S0 + 20 + A1 * 4] = w(0);
    A1 = A1 + 1;
    V0 = A1 < 8;
800AE474	bne    v0, zero, loopae464 [$800ae464]

// if player
if (unit_id < 3)
{
    [S0 + 10] = w(hu[8009d84c + unit_id * 440 + 3e]); // half
    [S0 + 14] = w(hu[8009d84c + unit_id * 440 + 40]); // no damage
    [S0 + 18] = w(hu[8009d84c + unit_id * 440 + 42]); // absorb
}
else if (unit_id >= 4)
{
    index = h[80163658 + (unit_id - 4) * 10];
    A1 = 0;
    loopae510:	; 800AE510
        V0 = 800f5f44 + index * b8 + A1;
        element_index = bu[V0 + 28];
        A2 = bu[V0 + 30];
        if (element_index != ff)
        {
            V0 = element_index >> 5;
            V1 = S0 + V0 * 20 + A2 * 4;
            V0 = V0 << 5;
            V0 = element_index - V0;
            A0 = w[V1];
            V0 = 1 << V0;
            A0 = A0 | V0;
            [V1] = w(A0);
        }

        A1 = A1 + 1;
        V0 = A1 < 8;
    800AE560	bne    v0, zero, loopae510 [$800ae510]
}

A0 = unit_id;
A1 = w[SP + 10];
A2 = w[SP + 14];
funcaf874; // get immunities
[S0 + 34] = w(w[S0 + 34] | V0);

if (w[SP + 10] != 0)
{
    if (w[800f83e0 + unit_id * 68 + 0] & 00100000) // shield
    {
        [S0 + 18] = w(w[S0 + 18] | 01ff);
        [S0 + 14] = w(w[S0 + 14] | 7e00);
    }
}

[S0 + 14] = w(w[S0 + 14] | hu[800f83e0 + unit_id * 68 + 54]); // no damage
[S0 + 18] = w(w[S0 + 18] | hu[800f83e0 + unit_id * 68 + 26]); // absorb

if (w[S0 + 14] & 0010 || w[S0 + 34] & 00000008) // no damage from poison element or poison status
{
    [S0 + 14] = w(V1 | 0010);
    [S0 + 34] = w(w[S0 + 34] | 00000008);
}



A1 = 0;
loopae65c:	; 800AE65C
    V0 = w[S0 + A1 * 4];
    V1 = w[S0 + 20 + A1 * 4];
    V0 = V0 & S3;
    V1 = V1 & S2;
    [S0 + A1 * 4] = w(V0);
    [S0 + 20 + A1 * 4] = w(V1);
    if (A1 == 5)
    {
        V0 = w[S0 + 34];
        if (V0 != S2)
        {
            [S0 + 34] = w(0);
        }
    }

    A1 = A1 + 1;
    V0 = A1 < 8;
800AE694	bne    v0, zero, loopae65c [$800ae65c]
////////////////////////////////



////////////////////////////////
// battle_opcodes_count_active_bits
V0 = A0 & ffff;
V1 = 0;
if (V0 != 0)
{
    loopb300c:	; 800B300C
        if (A0 & 1)
        {
            V1 = V1 + 1;
        }

        A0 = A0 >> 1;
    800B3020	bne    a0, zero, loopb300c [$800b300c]
}

return V1;
////////////////////////////////



////////////////////////////////
// funcb2cfc
S0 = A0;
A3 = A1;

[800f5bc4 + A3 * 44] = b(S0);
[800f5bec + A3 * 44] = w(w[800f5bec + A3 * 44] + 1);

[800f83e0 + S0 * 68 + 2c] = w(w[800f83e0 + A3 * 68 + 2c]); // current hp
[800f83e0 + S0 * 68 + 28] = h(hu[800f83e0 + A3 * 68 + 28]); // current mp
[800f83e0 + S0 * 68 + 0] = w(w[800f83e0 + A3 * 68 + 0]); // statuses
[800f83e0 + S0 * 68 + 44] = w(w[800f83e0 + A3 * 68 + 44]); // some more statuses
[800f5bb8 + S0 * 44 + 6] = h(hu[800f5bb8 + A3 * 44 + 6]);
[800f5bb8 + S0 * 44 + 28] = b(bu[800f5bb8 + A3 * 44 + 28]);
[800f5bb8 + S0 * 44 + 29] = b(bu[800f5bb8 + A3 * 44 + 29]);

A0 = 800f5bb8 + A3 * 44 + 10;
A1 = 800f5bb8 + S0 * 44 + 20;
A2 = 800f5bb8 + S0 * 44 + 10;

loopb2e34:	; 800B2E34
    [A2] = b(bu[A0]);
    A2 = A2 + 1;
    A0 = A0 + 1;
    V0 = A2 < A1;
800B2E48	bne    v0, zero, loopb2e34 [$800b2e34]

A0 = 800f5bb8 + S0 * 44 + 20;
V1 = 800f5bb8 + A3 * 44 + 20;
A1 = 800f5bb8 + S0 * 44 + 28;

loopb2e7c:	; 800B2E7C
    [A0] = b(bu[V1]);
    A0 = A0 + 1;
    V1 = V1 + 1;
    V0 = A0 < A1;
800B2E90	bne    v0, zero, loopb2e7c [$800b2e7c]

A0 = S0;
funcae954;

A0 = S0;
funcb108c;
////////////////////////////////
