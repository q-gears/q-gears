////////////////////////////////
// field_add_model_data_pointers
start_pointer = A0;

S1 = 0;



// add main models
system_get_pointer_to_first_element_in_script_list;
S0 = V0;
if( S0 == 0 )
{
    pointer = start_pointer;

    loopab154:	; 800AB154
        A0 = w[S0 + 4]; // pointer to allocated script memory
        if( bu[A0 + e] == 1 )
        {
            if( bu[A0 + f] & 01 )
            {
                if( bu[A0 + 5] == 4 ) // model entity type
                {
                    A0 = bu[A0 + 3b];
                    func1e350;

                    A0 = V0;
                    V0 = w[A0 + 8];
                    if( w[V0 + 1c] == 0 )
                    {
                        [pointer] = w(A0);
                        pointer = pointer + 4;
                        S1 = S1 + 1;
                    }
                }
            }
        }

        S0 = w[S0 + 0];
    800AB1CC	bne    s0, zero, loopab154 [$800ab154]
}



// add attached models after main models
// because we need to update attached model matrixes after main models
system_get_pointer_to_first_element_in_script_list;
S0 = V0;
if( S0 != 0 )
{
    loopab1e8:	; 800AB1E8
        A0 = w[S0 + 4]; // pointer to allocated script memory
        if( bu[A0 + e] == 1 )
        {
            if( bu[A0 + f] & 1 )
            {
                if( bu[A0 + 5] == 4 ) // model entity type
                {
                    A0 = bu[A0 + 3b];
                    func1e350;

                    A0 = V0;
                    V0 = w[A0 + 8];
                    A3 = w[V0 + 1c];
                    if( A3 != 0 )
                    {
                        if( S1 > 0 )
                        {
                            A2 = 0;
                            loopab260:	; 800AB260
                                V0 = w[start_pointer + A2 * 4];
                                if( w[V0 + 8] == A3 )
                                {
                                    [start_pointer + S1 * 4] = w(A0);
                                    S1 = S1 + 1;
                                    break;
                                }

                                A2 = A2 + 1;
                                V0 = A2 < S1;
                            800AB28C	bne    v0, zero, loopab260 [$800ab260]
                        }
                    }
                }
            }
        }

        S0 = w[S0 + 0];
    800AB29C	bne    s0, zero, loopab1e8 [$800ab1e8]
}



// remove pointer if it exceed memory limit
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + c];
V0 = w[V0 + 14];
if( b[V0 + 42] != 0 )
{
    if( S1 > 0 )
    {
        A2 = 0;
        loopab2fc:	; 800AB2FC
            V0 = w[start_pointer + A2 * 4];
            model_data = w[V0 + 8];
            model_file = w[model_data + 8];
            model_file_parts = w[model_file + 10];
            if( model_file_parts >= 0 ) // if this is not direct address get pointer to model data
            {
                model_file_parts = model_file + model_file_parts;
            }

            A1 = 0;
            number_of_model = bu[model_file + 3];
            if( number_of_model > 0 )
            {
                A0 = 0;
                loopab33c:	; 800AB33C
                    A1 = A1 + hu[model_file_parts + A0 * 28 + 0];
                    A0 = A0 + 1;
                    V0 = A0 < number_of_model;
                800AB34C	bne    v0, zero, loopab33c [$800ab33c]
            }

            if( ( w[model_data + 10] + bu[model_file + 2] * 20 + bu[model_file + 3] * c + A1 * 2 ) >= ( w[80067944] + f1700 ) )
            {
                [start_pointer + A2 * 4] = w(0);
            }

            A2 = A2 + 1;
            V0 = A2 < S1;
        800AB39C	bne    v0, zero, loopab2fc [$800ab2fc]
    }
}

return S1;
////////////////////////////////



////////////////////////////////
// field_get_x_y_rotation_from_walkmesh_for_model
V1 = w[800c9df4];
V1 = h[V1 + A0 * 28 + 6];
V1 = w[800c9e00] + V1 * 28;
[A1] = h(-hu[V1 + a]);
[A2] = h(hu[V1 + 8]);
return 1;
////////////////////////////////



////////////////////////////////
// funcb7cec
if( hu[A0 + 0] & 0002 )
{
    R11R12 = w[A0 + 24];
    R13R21 = w[A0 + 28];
    R22R23 = w[A0 + 2c];
    R31R32 = w[A0 + 30];
    R33 = w[A0 + 34];

    IR1 = hu[A0 + 54];
    IR2 = 0;
    IR3 = 0;
    gte_rtir12; // ir * rotmatrix.
    [A0 + 24] = h(IR1);
    [A0 + 2a] = h(IR2);
    [A0 + 30] = h(IR3);


    IR1 = 0;
    IR2 = hu[A0 + 56];
    IR3 = 0;
    gte_rtir12; // ir * rotmatrix.
    [A0 + 26] = h(IR1);
    [A0 + 2c] = h(IR2);
    [A0 + 32] = h(IR3);

    IR1 = 0;
    IR2 = 0;
    IR3 = hu[A0 + 58];
    gte_rtir12; // ir * rotmatrix.
    [A0 + 28] = h(IR1);
    [A0 + 2e] = h(IR2);
    [A0 + 34] = h(IR3);
}
////////////////////////////////
