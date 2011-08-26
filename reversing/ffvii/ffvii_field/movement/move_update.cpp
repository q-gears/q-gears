//////////////////////////////////////////////////////////
// handle_update
S4 = A0;

number_of_models = h[8009abf4 + 28];

if (number_of_models > 0)
{
    S2 = 0;
    A3 = FF;
    A1 = 1;
    A2 = 8009ABF4 + 28;

    loopa65f4:	; 800A65F4
        V1 = w[8008357C];
        V0 = bu[V1 + S2 * 8 + 4];
        if (V0 != ff)
        {
            A0 = w[8004A62C];
            A0 = w[A0 + 4];
            V1 = A0 + V0 * 24;

            V0 = bu[80074EA4 + S2 * 84 + 5C]; // model visibility
            if (V0 == 1)
            {
                [V1] = b(1);
            }
            else
            {
                [V1] = b(0);
            }
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_models;
    800A6678	bne    v0, zero, loopa65f4 [$800a65f4]



    /////////////////////////////
    // turn update
    S2 = 0;
    loopa66a4:	; 800A66A4
        S0 = S2 * 84;
        V1 = bu[80074EA4 + S0 + 3B];
        if (V1 == 1)
        {
            A0 = h[80074EA4 + S0 + 3C];
            A1 = h[80074EA4 + S0 + 3E];
            A2 = bu[80074EA4 + S0 + 39];
            A3 = bu[80074EA4 + S0 + 3A];
            calculate_current_value_by_steps;
            [80074EA4 + S0 + 38] = b(V0);

            A0 = bu[80074EA4 + S0 + 3A];
            V1 = bu[80074EA4 + S0 + 39];
            if (A0 == V1)
            {
                [80074EA4 + S0 + 3B] = b(3);
            }
            else
            {
                V1 = A0 + 1;
                [80074EA4 + S0 + 3A] = b(V1);
            }
        }
        else if (V1 == 2)
        {
            A0 = h[80074EA4 + S0 + 3C];
            A1 = h[80074EA4 + S0 + 3E];
            A2 = bu[80074EA4 + S0 + 39];
            A3 = bu[80074EA4 + S0 + 3A];
            calculate_smooth_current_value_by_steps;

            [80074EA4 + S0 + 38] = b(V0);

            A0 = bu[80074EA4 + S0 + 3A];
            V1 = bu[80074EA4 + S0 + 39];

            if (A0 == V1)
            {
                [80074EA4 + S0 + 3B] = b(3);
            }
            else
            {
                V1 = A0 + 1;
                [80074EA4 + S0 + 3A] = b(V1);
            }
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_models;
    800A6830	bne    v0, zero, loopa66a4 [$800a66a4]
    /////////////////////////////



    /////////////////////////////
    // offset update
    S2 = 0;

    La6850:	; 800A6850
        V1 = bu[80074EA4 + S2 * 84 + 56];

        if (V1 == 0)
        {
            continue;
        }
        if (V1 == 1)
        {
            A0 = hu[80074EA4 + S2 * 84 + 42];
            A1 = hu[80074EA4 + S2 * 84 + 44];
            A2 = hu[80074EA4 + S2 * 84 + 52];
            A3 = hu[80074EA4 + S2 * 84 + 54];
            calculate_current_value_by_steps;
            [80074EA4 + S2 * 84 + 40] = h(V0);

            A0 = hu[80074EA4 + S2 * 84 + 48];
            A1 = hu[80074EA4 + S2 * 84 + 4a];
            A2 = hu[80074EA4 + S2 * 84 + 52];
            A3 = hu[80074EA4 + S2 * 84 + 54];
            calculate_current_value_by_steps;
            [80074EA4 + S2 * 84 + 46] = h(V0);

            A0 = hu[80074EA4 + S2 * 84 + 4e];
            A1 = hu[80074EA4 + S2 * 84 + 50];
            A2 = hu[80074EA4 + S2 * 84 + 52];
            A3 = hu[80074EA4 + S2 * 84 + 54];
            calculate_current_value_by_steps;
            [80074EA4 + S2 * 84 + 4c] = h(V0);
        }
        else if (V1 == 2)
        {
            A0 = hu[80074EA4 + S2 * 84 + 42];
            A1 = hu[80074EA4 + S2 * 84 + 44];
            A2 = hu[80074EA4 + S2 * 84 + 52];
            A3 = hu[80074EA4 + S2 * 84 + 54];
            calculate_smooth_current_value_by_steps;
            [80074EA4 + S2 * 84 + 40] = h(V0);

            A0 = hu[80074EA4 + S2 * 84 + 48];
            A1 = hu[80074EA4 + S2 * 84 + 4a];
            A2 = hu[80074EA4 + S2 * 84 + 52];
            A3 = hu[80074EA4 + S2 * 84 + 54];
            calculate_smooth_current_value_by_steps;
            [80074EA4 + S2 * 84 + 46] = h(V0);

            A0 = hu[80074EA4 + S2 * 84 + 4e];
            A1 = hu[80074EA4 + S2 * 84 + 50];
            A2 = hu[80074EA4 + S2 * 84 + 52];
            A3 = hu[80074EA4 + S2 * 84 + 54];
            calculate_smooth_current_value_by_steps;
            [80074EA4 + S2 * 84 + 4c] = h(V0);
        }
        else
        {
            continue;
        }

        A0 = hu[80074EA4 + S2 * 84 + 54];
        V1 = hu[80074EA4 + S2 * 84 + 52];

        if (A0 != V1)
        {
            [80074EA4 + S2 * 84 + 54] = h(A0 + 1);
        }
        else
        {
            [80074EA4 + S2 * 84 + 56] = b(3);
        }

        pc_entity = h[800965E0];
        if (S2 == pc_entity)
        {
            A0 = 8007e7ac;
            line_clear_entity_in_line;
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_models;
    800A6B70	bne    v0, zero, La6850 [$800a6850]
    /////////////////////////////



    /////////////////////////////
    // manual move update
    S2 = 0;
    S1 = 8009abf4 + 32;
    manual_model_id = h[800965e0];

    La6b9c:	; 800A6B9C
        A1 = S2;

        // if model not performing auto action
        if (bu[80074ea4 + A1 * 84 + 5d] == 0)
        {
            if (A1 == manual_model_id && bu[8009abf4 + 32] != 1) // if we can control this entity (manual model and UC == 0)
            {
                A0 = S4;
                move_add_shift_rotate;

                // set idle animation id by default
                [80074EA4 + manual_model_id * 84 + 5e] = b(bu[8009ABF4 + 2C]);

                field_scale = h[8009abf4 + 10];

                if ((S4 & 0040) == 0)
                {
                    if (bu[8009abf4 + 3a] != 0)
                    {
                        V0 = field_scale * 3;
                    }
                    else
                    {
                        V0 = field_scale * 2;
                    }
                }
                else
                {
                    if (bu[8009abf4 + 3A] == 0)
                    {
                        V0 = field_scale * 8;
                    }
                    else
                    {
                        V0 = field_scale * c;
                    }
                }

                [80074EA4 + manual_model_id * 84 + 70] = h(V0); // set speed

                if (S4 & f000)
                {
                    if (S4 & 1000)
                    {
                        [80074ea4 + manual_model_id * 84 + 36] = b(0);

                        if (S4 & 8000)
                        {
                            [80074ea4 + manual_model_id * 84 + 36] = b(20);
                        }

                        if (S4 & 2000)
                        {
                            [80074ea4 + manual_model_id * 84 + 36] = b(e0);
                        }
                    }
                    else
                    {
                        if (S4 & 4000)
                        {
                            [80074ea4 + manual_model_id * 84 + 36] = b(80);

                            if (S4 & 8000)
                            {
                                [80074ea4 + manual_model_id * 84 + 36] = b(60);
                            }

                            if (S4 & 2000)
                            {
                                [80074ea4 + manual_model_id * 84 + 36] = b(a0);
                            }
                        }
                        else
                        {
                            if (S4 & 2000)
                            {
                                [80074ea4 + manual_model_id * 84 + 36] = b(c0);
                            }

                            if (S4 & 8000)
                            {
                                [80074ea4 + manual_model_id * 84 + 36] = b(40);
                            }
                        }
                    }

                    // read field global rotation byte
                    V1 = w[800716c4];
                    V0 = bu[V1 + 9] + bu[80074ea4 + manual_model_id * 84 + 36] + bu[80074ea4 + manual_model_id * 84 + 35];
                    [80074ea4 + manual_model_id * 84 + 36] = b(V0);

                    A0 = S2;
                    main_walkmesh_move;
                    A0 = V0;

                    // if this byte == 0 store move direction as model direction
                    V1 = bu[80074EA4 + manual_model_id * 84 + 37];
                    if (V1 == 0)
                    {
                        80074EA4 + manual_model_id * 84 + 38] = b(bu[80074EA4 + manual_model_id * 84 + 36]);
                    }

                    V0 = bu[8009abf4 + 01];
                    if (V0 != 1 && A0 == 1)
                    {
                        funcaba70;
                    }
                }
            }

            A0 = S2;
            handle_animation_update;
        }

        800A6BC4	addiu  v0, s2, $0001
        800A6EDC	addu   s2, v0, zero
        800A6EE0	sll    v0, v0, $10
        800A6EE4	lui    v1, $800a
        800A6EE8	lh     v1, $ac1c(v1)
        800A6EEC	sra    v0, v0, $10
        800A6EF0	slt    v0, v0, v1
    800A6EF4	bne    v0, zero, La6b9c [$800a6b9c]



    /////////////////////////////
    // auto move update
    S2 = 0;
    loopa6f18:	; 800A6F18
        V0 = bu[80074EA4 + S2 * 84 + 5D];

        if (V0 == 1)
        {
            V0 = bu[8009ABF4 + 33];
            if (V0 != 1)
            {
                [80074EA4 + S2 * 84 + 35] = b(0);

                A0 = 80074EA4 + S2 * 84;
                A1 = h[80074EA4 + S2 * 84 + 68];
                La8858;

                if (V0 == 0)
                {
                    [80074EA4 + S2 * 84 + 6A] = h(2);
                }
                else
                {
                    [80074EA4 + S2 * 84 + 6A] = h(1);

                    A0 = S2;
                    main_walkmesh_move;

                    if (bu[80074EA4 + S2 * 84 + 37] == 0)
                    {
                        [80074ea4 + S2 * 84 + 38] = b(bu[80074ea4 + S2 * 84 + 36]);
                    }
                }

                A0 = S2;
                handle_animation_update;

                pc_entity = h[800965E0];
                if (S2 == pc_entity)
                {
                    A0 = 8007E7AC;
                    line_clear_entity_in_line;
                }
            }
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_models;
    800A7050	bne    v0, zero, loopa6f18 [$800a6f18]
    /////////////////////////////



    /////////////////////////////
    // jump update
    S2 = 0;
    S1 = SP + 20;

    La7070:	; 800A7070
        V1 = bu[80074EA4 + S2 * 84 + 5D];
        // if jump
        if (V1 == 3)
        {
            A0 = S2 * 84 + 10;

            V0 = h[80074EA4 + S2 * 84 + 6A];
            if (V0 == 0)
            {
                V0 = hu[80074EA4 + S2 * 84 + 74]; // triangle id
                V1 = w[80074EA4 + S2 * 84 + 0C]; // x
                A3 = w[80074EA4 + S2 * 84 + 10]; // y
                T0 = w[80074EA4 + S2 * 84 + 14]; // z

                // byte added to rotation byte in triggers and to move direction and stored in move direction.
                [80074EA4 + S2 * 84 + 35] = b(0);

                [80074EA4 + S2 * 84 + 18] = w(V1);
                [80074EA4 + S2 * 84 + 1C] = w(A3);
                [80074EA4 + S2 * 84 + 20] = w(T0);

                id_offset = w[800E4274];
                A1 = id_offset + V0 * 18 + 8;
                A2 = id_offset + V0 * 18;
                walkmesh_vector_sub;

                V0 = hu[80074F18 + S2 * 84];
                A0 = S1;
                A1 = id_offset + V0 * 18 + 10;
                A2 = id_offset + V0 * 18 + 8;
                walkmesh_vector_sub;

                V0 = w[80074F1C + S2 * 84];
                V0 = V0 >> C;
                [SP + 30] = w(V0);

                V0 = w[80074F20 + S2 * 84];
                V0 = V0 >> C;
                [SP + 34] = w(V0);

                V0 = hu[80074EA4 + S2 * 84 + 74];

                A0 = SP + 10;
                A1 = S1;
                A2 = SP + 30;
                A3 = id_offset + V0 * 18;
                walkmesh_calculate_z;
                Z_fin = V0 << C;
                [80074EA4 + S2 * 84 + 80] = w(Z_fin);

                Z_start = w[80074EA4 + S2 * 84 + 20];
                steps = h[80074EA4 + S2 * 84 + 30];
                b_value = (Z_fin - Z_start) / steps - steps * 1740;
                [80074EA4 + S2 * 84 + 2C] = w(b_value);

                [80074EA4 + S2 * 84 + 32] = h(0);
                [80074EA4 + S2 * 84 + 6A] = w(1);
            }
            else
            {
                V1 = h[80074EA4 + S2 * 84 + 32];
                V0 = h[80074EA4 + S2 * 84 + 30];
                A3 = V1;
                // if current substep == number of steps
                if (V0 == V1)
                {
                    V1 = hu[80074EA4 + S2 * 84 + 74];
                    [80074EA4 + S2 * 84 + 72] = h(V1);

                    [80074EA4 + S2 * 84 + 6A] = h(2);
                }
                else
                {
                    V0 = A3 + 1;
                    [80074EA4 + S2 * 84 + 32] = h(V0);

                    A0 = w[80074EA4 + S2 * 84 + 18];
                    A1 = w[80074EA4 + S2 * 84 + 78];
                    A2 = h[80074EA4 + S2 * 84 + 30];
                    A3 = h[80074EA4 + S2 * 84 + 32];
                    calculate_current_value_by_steps;
                    [80074EA4 + S2 * 84 + C] = w(V0); // real X

                    A0 = w[80074EC0 + S2 * 84];
                    A1 = w[80074F20 + S2 * 84];
                    A2 = h[80074EA4 + S2 * 84 + 30];
                    A3 = h[80074EA4 + S2 * 84 + 32];
                    calculate_current_value_by_steps;
                    [80074EA4 + S2 * 84 + 10] = w(V0); // real Y

                    step = h[80074EA4 + S2 * 84 + 32];
                    b_value = h[80074EA4 + S2 * 84 + 2C];
                    Z_start = w[80074EA4 + S2 * 84 + 20];
                    Z_cur = - step^2 * 1740 + step * b_value + Z_start;
                    [80074EA4 + S2 * 84 + 14] = w(Z_cur);
                }
            }

            A0 = S2;
            // we update animation here
            handle_animation_update;

            pc_entity = h[800965E0];
            if (S2 == pc_entity)
            {
                A0 = 8007E7AC;
                line_clear_entity_in_line;
            }
        }

        La74cc:	; 800A74CC
        S2 = S2 + 1;
        V0 = S2 < number_of_models;
    800A74E4	bne    v0, zero, La7070 [$800a7070]
    /////////////////////////////



    /////////////////////////////
    // ladder update
    S2 = 0;
    La7510:	; 800A7510
        V1 = bu[80074EA4 + S2 * 84 + 5D];
        if (V1 == 4 || V1 == 5)
        {
            V0 = w[8008357C];
            A0 = bu[V0 + S2 * 8 + 4];
            if (A0 != FF)
            {
                V1 = w[8004A62C];
                V1 = w[V1 + 4];
                V0 = V1 + A0 * 24;
                A0 = hu[V0 + 1A];
                V0 = w[V0 + 1C];

                V1 = h[80074EA4 + S2 * 84 + 6A];
                S3 = A0 + V0;
                if (V1 == 0)
                {
                    // copy current coords as start coords
                    X_cur = w[80074EA4 + S2 * 84 + 0C];
                    [80074EA4 + S2 * 84 + 18] = w(X_cur);
                    Y_cur = w[80074EA4 + S2 * 84 + 10];
                    [80074EA4 + S2 * 84 + 1C] = w(Y_cur);
                    Z_cur = w[80074EA4 + S2 * 84 + 14];
                    [80074EA4 + S2 * 84 + 20] = w(Z_cur);

                    X_fin = w[80074EA4 + S2 * 84 + 78];
                    A1 = X_fin - X_cur;
                    A1 = A1 >> C;
                    [SP + 10] = w(A1);

                    Y_fin = w[80074EA4 + S2 * 84 + 7C];
                    V1 = Y_fin - Y_cur;
                    A0 = V1 >> C;
                    [SP + 14] = w(A0);

                    Z_fin = w[80074EA4 + S2 * 84 + 80];
                    V0 = Z_fin - Z_cur;
                    V0 = V0 >> C;
                    [SP + 18] = w(V0);

                    A0 = A1 * A1 + A0 * A0 + V0 * V0;
                    system_square_root;
                    V0 = V0 * 4;

                    [80074EA4 + S2 * 84 + 30] = h(V0);
                    [80074EA4 + S2 * 84 + 32] = h(0);
                    [80074EA4 + S2 * 84 + 6A] = h(1);

                    [80074EA4 + S0 + 35] = b(0);

                    V1 = bu[80074EA4 + S2 * 84 + 5E];
                    V0 = hu[S3 + V1 * 10];
                    V0 = V0 - 1;
                    [80074EA4 + S2 * 84 + 64] = h(V0);

                    pc_entity = h[800965E0];
                    if (S2 == pc_entity)
                    {
                        A0 = 8007E7AC;
                        line_clear_entity_in_line;
                    }
                }
                else
                {
                    pc_entity = h[800965E0];
                    uc = bu[8009ABF4 + 32];
                    if (S2 == pc_entity && uc == 0)
                    {
                        V1 = bu[80074EA4 + S2 * 84 + 5D];
                        up_down_switch = h[80074EA4 + S2 * 84 + 68];
                        if (V1 == 5)
                        {
                            if (up_down_switch == 0)
                            {
                                start = 8000;
                                ens = 2000;
                            }
                            else
                            {
                                start = 2000;
                                ens = 8000;
                            }
                        }
                        else
                        {
                            if (up_down_switch == 0)
                            {
                                start = 4000;
                                ens = 1000;
                            }
                            else
                            {
                                start = 1000;
                                ens = 4000;
                            }
                        }

                        if (S4 & start)
                        {
                            step = h[80074EA4 + S2 * 84 + 32];
                            if (step == 0)
                            {
                                [80074EA4 + S2 * 84 + 6A] = h(2);
                            }
                            else
                            {
                                step = step - 1;
                                [80074EA4 + S2 * 84 + 32] = h(step);


                                V0 = hu[80074EA4 + S2 * 84 + 62];
                                animation_speed = hu[80074EA4 + S2 * 84 + 60];
                                V0 = V0 - animation_speed;
                                [80074EA4 + S2 * 84 + 62] = h(V0);
                                V0 = V0 << 10;

                                if (V0 < 0)
                                {
                                    V0 = hu[80074EA4 + S2 * 84 + 64];
                                    V0 = V0 * 10;
                                    [80074EA4 + S2 * 84 + 62] = h(V0);
                                }
                            }
                        }

                        if (S4 & end)
                        {
                            step = h[80074EA4 + S2 * 84 + 32];
                            steps = h[80074EA4 + S2 * 84 + 30];
                            if (step == steps)
                            {
                                move_to_triangle = hu[80074EA4 + S2 * 84 + 74];
                                [80074EA4 + S2 * 84 + 72] = h(move_to_triangle);
                                [80074EA4 + S2 * 84 + 6A] = h(2);
                            }
                            else
                            {
                                step = step + 1;
                                [80074EA4 + S2 * 84 + 32] = h(step);

                                V0 = hu[80074EA4 + S2 * 84 + 62];
                                animation_speed = hu[80074EA4 + S2 * 84 + 60];
                                V0 = V0 + animation_speed;
                                [80074EA4 + S2 * 84 + 62] = h(V0);

                                V1 = hu[80074EA4 + S2 * 84 + 64];
                                V0 = V0 * 10;

                                if (V1 < V0)
                                {
                                    [80074EA4 + S2 * 84 + 62] = h(0);
                                }
                            }
                        }
                    }
                    else
                    {
                        step = h[80074EA4 + S2 * 84 + 32];
                        steps = h[80074EA4 + S2 * 84 + 30];
                        if (step == steps)
                        {
                            move_to_triangle = hu[80074EA4 + S2 * 84 + 74];
                            [80074EA4 + S2 * 84 + 72] = h(move_to_triangle);

                            [80074EA4 + S2 * 84 + 6A] = h(2);
                        }
                        else
                        {
                            step = step + 1;
                            [80074EA4 + S2 * 84 + 32] = h(step);


                            V0 = hu[80074EA4 + S2 * 84 + 62];
                            animation_speed = hu[80074EA4 + S2 * 84 + 60];
                            V0 = V0 + animation_speed;
                            [80074EA4 + S2 * 84 + 62] = h(V0);

                            V1 = hu[80074EA4 + S2 * 84 + 64];
                            V0 = V0 * 10;

                            if (V1 < V0)
                            {
                                [80074EA4 + S2 * 84 + 62] = h(0);
                            }
                        }
                    }

                    A0 = w[80074EA4 + S2 * 84 + 18];
                    A1 = w[80074EA4 + S2 * 84 + 78];
                    A2 = w[80074EA4 + S2 * 84 + 30];
                    A3 = w[80074EA4 + S2 * 84 + 32];
                    calculate_current_value_by_steps;
                    [80074EB0 + S2 * 84] = w(V0);

                    A0 = w[80074EA4 + S2 * 84 + 1C];
                    A1 = w[80074EA4 + S2 * 84 + 7C];
                    A2 = w[80074EA4 + S2 * 84 + 30];
                    A3 = w[80074EA4 + S2 * 84 + 32];
                    calculate_current_value_by_steps;
                    [80074EB4 + S2 * 84] = w(V0);

                    A0 = w[80074EA4 + S2 * 84 + 20];
                    A1 = w[80074EA4 + S2 * 84 + 80];
                    A2 = w[80074EA4 + S2 * 84 + 30];
                    A3 = w[80074EA4 + S2 * 84 + 32];
                    calculate_current_value_by_steps;
                    [80074EB8 + S2 * 84] = w(V0);
                }
            }
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_models;
    800A826C	bne    v0, zero, La7bd4 [$800a7bd4]
    /////////////////////////////
}



La8274:	; 800A8274
return;
//////////////////////////////////////////////////////////



////////////////////////////////////////////////////
// handle_animation_update
A2 = A0;
V0 = w[8008357C];
A0 = bu[V0 + A2 * 8 + 4];
if (A0 != FF)
{
    V1 = w[8004A62C];
    V1 = w[V1 + 4];
    new_structure_data = w[V1 + A0 * 24 + 1C];
    new_structure_animation = hu[V1 + A0 * 24 + 1A];

    // don't automove
    V1 = bu[8009ABF4 + 33];
    if (V1 == 1)
    {
        return;
    }

    current_animation_value = hu[80074EA4 + A2 * 84 + 62];
    animation_speed = hu[80074EA4 + A2 * 84 + 60];
    [80074EA4 + A2 * 84 + 62] = h(current_animation_value + animation_speed);

    // if manual visible entity and UC == 0
    if (A2 == h[800965E0] && bu[8009ABF4 + 32] == 0)
    {
        animation_id = bu[80074EA4 + A2 * 84 + 5E];
        number_of_frame = hu[new_structure_data + new_structure_animation + animation_id * 10];
        [80074EA4 + A2 * 84 + 64] = h(number_of_frame - 1);

        current_animation_value = h[80074EA4 + A2 * 84 + 62];
        if (current_animation_value > (number_of_frame - 1) * 10)
        {
            [80074EA4 + A2 * 84 + 62] = h(0);
        }
    }
    else
    {
        number_of_frame = h[80074EA4 + A2 * 84 + 64];
        current_animation_value = h[80074EA4 + A2 * 84 + 62];

        if (current_animation_value > number_of_frame * 10)
        {
            [80074EA4 + A2 * 84 + 62] = h(number_of_frame * 10);
        }
    }
}

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// calculate_current_value_by_steps
start        = A0;
final        = A1;
steps_number = A2;
step         = A3;
delta = final - start;
V1 = delta + 0007FFFF;
if (V1 <= 000FFFFE)
{
    V0 = (delta * step) / steps_number;
}
else
{
    V0 = (delta / steps_number) * step;
}

return start + V0;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// line_clear_entity_in_line
V0 = 1F;

loopaa330:	; 800AA330
    [A0 + 15] = b(0);
    V0 = V0 - 1;
    A0 = A0 + 18;
800AA338	bgez   v0, loopaa330 [$800aa330]

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////////
La8858
model_data_offset = A0;
model_data_68 = A1;

// x_cur
current_x = w[model_data_offset + C];
current_x = current_x >> C;
[SP + 10] = w(current_x);

// y_cur
current_y = w[model_data_offset + 10];
current_y = current_y >> C;
[SP + 14] = w(current_y);

// x_to
to_x = w[model_data_offset + 78];
to_x = to_x >> C;
[SP + 20] = w(to_x);

// y_to
to_y = w[model_data_offset + 7C];
to_y = to_y >> C;
[SP + 24] = w(to_y);

length_square = (to_x - current_x) * (to_x - current_x) + (to_y - current_y) * (to_y - current_y);
[SP + 30] = w(length_square);

solid_range = hu[model_data_offset + 6C]; // solid
V0 = (solid_range + model_data_68) * (solid_range + model_data_68);

if (model_data_68 != 0)
{
    if (V0 + 1000 >= length_square) // 40 * 40 = 1000
    {
        return 0;
    }
}

V0 = hu[model_data_offset + 70]; // movement speed
V0 = V0 * V0;
V0 = V0 >> 10;
length_square = w[SP + 30];

if (length_square >= V0 && length_square >= 4)
{
    A0 = SP + 10; // current pos
    A1 = SP + 20; // destination pos
    A2 = SP + 30; // length_square
    calculate_direction_by_vectors;

    V1 = b[model_data_offset + 35];
    V1 = V0 - V1;
    [model_data_offset + 36] = b(V1);

    return 1;
}

[model_data_offset + C] = w(w[model_data_offset + 78]);
[model_data_offset + 10] = w(w[model_data_offset + 7C]);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////
// move_add_shift_rotate
// A0 - button
// A1 - model_id

if (bu[8009abf4 + 32] == 0) // UC byte
{
    V1 = w[8009abf4 + 78];
    if (V1 & 0008)
    {
        [80074ea4 + A1 * 84 + 35] = b(e0);
    }
    else if (V1 & 0004)
    {
        [80074ea4 + A1 * 84 + 35] = b(20);
    }
    else
    {
        [80074ea4 + A1 * 84 + 35] = b(0);
    }
}

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaba70

// get encounter table address
V0 = bu[8009ABF4 + 3c];
if (V0 == 0)
{
    S1 = w[80071a54];
}
else
{
    S1 = w[80071a54] + 18;
}



V0 = bu[8009c6d8];
V0 = V0 + 20;
[8009c6d8] = b(V0);

if (V0 == 0)
{
    func262d8;

    V1 = bu[8009d58e];
    V1 = V1 + 1;
    [8009d58e] = b(V1);

    if (bu[8009d58e] == 0 && bu[8009d58f] != ff)
    {
        [8009d58f] = b(bu[8009d58f] + 1);
    }

    A0 = hu[S1];
    if (A0 & 1 && hu[80114488] == 0 && bu[8009ABF4 + 3b] == 0)
    {
        V1 = h[800965e0]; // manual visible entity
        V1 = hu[80074EA4 + V1 * 84 + 70]; // movement speed

        V0 = A0 >> 8; // encounter Value for this battle table
        V1 = V1 / V0;

        V0 = hu[8007173c];
        V0 = V0 + V1;
        [8007173c] = h(V0);

        funcab9c8; // random?

        V1 = bu[80062f1b];
        V1 = V1 & 7f;
        if (V0 < V1)
        {
            [800716d0] = b(4);
        }
        else
        {
            [800716d0] = b(0);
        }

        funcab9c8; // random 0-ff

        A0 = hu[8007173c]; // danger counter

        V1 = bu[80062f19];
        V1 = A0 * V1;
        V1 = V1 >> c;
        if (V0 < V1)
        {
            field_stop_load_background_in_advance;

            [8009abf4 + 01] = b(2);
            [8007ebc8] = b(1);

            funcaba34;

            V0 = V0 & ff;
            V1 = bu[80062f1b];
            A0 = V0 >> 2;
            if ((V1 & 80) == 0) // Ambush Alert
            {
                V0 = hu[S1 + e];
                S0 = V0 >> a; // normal rate
            }
            else
            {
                V0 = hu[S1 + e];
                S0 = V0 >> b; // half rate
            }

            V0 = A0 & ff;
            V1 = S0 & ff;
            if (V0 < V1)
            {
                V0 = hu[S1 + e];
                [800716d0] = b(0);
                V0 = V0 & 3ff;
                800ABCD0	j      Labdd4 [$800abdd4]
            }

            Labcd8:	; 800ABCD8
            800ABCD8	lui    v0, $8006
            800ABCDC	lbu    v0, $2f1b(v0)
            800ABCE0	nop
            800ABCE4	andi   v0, v0, $0080
            800ABCE8	bne    v0, zero, Labd04 [$800abd04]
            800ABCEC	nop
            800ABCF0	lhu    v0, $0010(s1)
            800ABCF4	nop
            800ABCF8	sll    v0, v0, $10
            800ABCFC	j      Labd14 [$800abd14]
            800ABD00	sra    v0, v0, $1a

            Labd04:	; 800ABD04
            800ABD04	lhu    v0, $0010(s1)
            800ABD08	nop
            800ABD0C	sll    v0, v0, $10
            800ABD10	sra    v0, v0, $1b

            Labd14:	; 800ABD14
            800ABD14	addu   s0, s0, v0
            800ABD18	andi   a2, a0, $00ff
            800ABD1C	andi   v0, s0, $00ff
            800ABD20	sltu   v0, a2, v0
            800ABD24	beq    v0, zero, Labd40 [$800abd40]
            800ABD28	nop
            800ABD2C	lhu    v0, $0010(s1)
            800ABD30	lui    at, $8007
            800ABD34	sb     zero, $16d0(at)
            800ABD38	j      Labdd4 [$800abdd4]
            800ABD3C	andi   v0, v0, $03ff

            Labd40:	; 800ABD40
            800ABD40	lhu    a1, $0012(s1)
            800ABD44	nop
            800ABD48	sll    v0, a1, $10
            800ABD4C	sra    v0, v0, $1a
            800ABD50	addu   v1, s0, v0
            800ABD54	andi   v0, v1, $00ff

            if (A2 < V0)
            {
                [8009abf6] = h(A1 & 3ff);
            }
            else
            {
                V0 = bu[80062f1b];
                if ((V0 & 80) == 0)
                {
                    V0 = hu[S1 + 14];
                    V0 = V0 << 10;
                    V0 = V0 >> 1a;
                }
                else
                {
                    V0 = hu[S1 + 14];
                    V0 = V0 << 10;
                    V0 = V0 >> 1b;
                }

                800ABDB0	addu   s0, v1, v0
                800ABDB4	andi   v0, a0, $00ff
                800ABDB8	andi   v1, s0, $00ff
                800ABDBC	sltu   v0, v0, v1
                800ABDC0	beq    v0, zero, Labdf4 [$800abdf4]
                800ABDC4	nop
                800ABDC8	lhu    v0, $0014(s1)
                800ABDCC	nop
                800ABDD0	andi   v0, v0, $03ff

                Labdd4:	; 800ABDD4
                800ABDD4	lui    at, $800a
                800ABDD8	sh     v0, $abf6(at)
                800ABDDC	j      Labef0 [$800abef0]
                800ABDE0	nop

                loopabde4:	; 800ABDE4
                800ABDE4	lui    at, $800a
                800ABDE8	sh     v0, $abf6(at)
                800ABDEC	j      Labe50 [$800abe50]
                800ABDF0	nop

                Labdf4:	; 800ABDF4
                800ABDF4	jal    funcaba34 [$800aba34]
                800ABDF8	addu   s0, zero, zero
                800ABDFC	addu   a0, zero, zero
                800ABE00	andi   v0, v0, $00ff
                800ABE04	srl    a2, v0, $02
                800ABE08	lhu    v0, $000c(s1)
                800ABE0C	addu   a1, s1, zero
                800ABE10	andi   v0, v0, $03ff
                800ABE14	lui    at, $800a
                800ABE18	sh     v0, $abf6(at)

                loopabe1c:	; 800ABE1C
                800ABE1C	lhu    v1, $0002(a1)
                800ABE20	nop
                800ABE24	sll    v0, v1, $10
                800ABE28	sra    v0, v0, $1a
                800ABE2C	addu   s0, s0, v0
                800ABE30	andi   v0, s0, $00ff
                800ABE34	sltu   v0, a2, v0
                800ABE38	bne    v0, zero, loopabde4 [$800abde4]
                800ABE3C	andi   v0, v1, $03ff
                800ABE40	addiu  a0, a0, $0001
                800ABE44	slti   v0, a0, $0005
                800ABE48	bne    v0, zero, loopabe1c [$800abe1c]
                800ABE4C	addiu  a1, a1, $0002

                Labe50:	; 800ABE50
                800ABE50	lui    s2, $800a
                800ABE54	addiu  s2, s2, $abf6 (=-$540a)
                800ABE58	lh     v1, $0000(s2)
                800ABE5C	lui    v0, $8008
                800ABE60	lh     v0, $e774(v0)
                800ABE64	nop
                800ABE68	beq    v1, v0, Labe9c [$800abe9c]
                800ABE6C	addu   a0, v1, zero
                800ABE70	lui    at, $8008
                800ABE74	sh     a0, $e774(at)
                800ABE78	j      Labef0 [$800abef0]
                800ABE7C	nop

                loopabe80:	; 800ABE80
                800ABE80	andi   v0, v1, $03ff
                800ABE84	lui    at, $800a
                800ABE88	sh     v0, $abf6(at)
                800ABE8C	lui    at, $8008
                800ABE90	sh     v0, $e774(at)
                800ABE94	j      Labef0 [$800abef0]
                800ABE98	nop

                Labe9c:	; 800ABE9C
                800ABE9C	jal    funcaba34 [$800aba34]
                800ABEA0	addu   s0, zero, zero
                800ABEA4	addu   a0, zero, zero
                800ABEA8	andi   v0, v0, $00ff
                800ABEAC	srl    a2, v0, $02
                800ABEB0	lhu    v0, $000c(s1)
                800ABEB4	addu   a1, s1, zero
                800ABEB8	andi   v0, v0, $03ff
                800ABEBC	sh     v0, $0000(s2)

                loopabec0:	; 800ABEC0
                800ABEC0	lhu    v1, $0002(a1)
                800ABEC4	nop
                800ABEC8	sll    v0, v1, $10
                800ABECC	sra    v0, v0, $1a
                800ABED0	addu   s0, s0, v0
                800ABED4	andi   v0, s0, $00ff
                800ABED8	sltu   v0, a2, v0
                800ABEDC	bne    v0, zero, loopabe80 [$800abe80]
                800ABEE0	addiu  a0, a0, $0001
                800ABEE4	slti   v0, a0, $0005
                800ABEE8	bne    v0, zero, loopabec0 [$800abec0]
                800ABEEC	addiu  a1, a1, $0002
            }
        }
    }
}

Labef0:	; 800ABEF0
return;
////////////////////////////////////////////////////
