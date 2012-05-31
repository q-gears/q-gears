////////////////////////////////////////////////////
// funcaab24
// here we handle KAWAI byte in new model structure

[800df114] = b(hu[80075dec]);

[800df118] = w(A0);


S5 = 1f800000;
block7_data = w[8007e770] + 4;
model_struct = w[8004a62c];

number_of_model = h[8009abf4 + 28]; // number of model



// update bone matrixes
if (number_of_model > 0)
{
    S2 = 0;
    Laab8c:	; 800AAB8C
        if (bu[S1 + 4] != ff)
        {
            [SP + 10] = h((w[80074ea4 + S2 * 84 +  c] >> c) + hu[80074ea4 + S2 * 84 + 40]);     // model position X + model offset X
            [SP + 12] = h((w[80074ea4 + S2 * 84 + 10] >> c) + hu[80074ea4 + S2 * 84 + 46]);     // model position Y + model offset Y
            [SP + 14] = h((w[80074ea4 + S2 * 84 + 14] >> c) + hu[80074ea4 + S2 * 84 + 4c] - a); // model position Z + model offset Z

            [w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24 +  8] = w(h(SP + 10));
            [w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24 +  c] = w(h(SP + 12));
            [w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24 + 10] = w(h[SP + 14]);

            A0 = SP + 10;
            A1 = SP + 18;
            field_calculate_distance_to_screen; // calculate distance to screen

            if( V0 < 0f00 )
            {
                V0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24; // new_structures_header
                [V0 + 7] = b(bu[80074ea4 + S2 * 84 + 38]); // model direction

                V1 = b[V0 + 1]; // +1[] KAWAI byte in new structure
                if( V1 == 4 || V1 == 8 || V1 == 9 || V1 == b || V1 == c )
                {
                    // identity matrix
                    [SP + 20] = h(1000); [SP + 22] = h(0); [SP + 24] = h(0);
                    [SP + 26] = h(0); [SP + 28] = h(1000); [SP + 2a] = h(0);
                    [SP + 2c] = h(0); [SP + 2e] = h(0); [SP + 30] = h(1000);
                    [SP + 34] = w(0); [SP + 38] = w(0); [SP + 3c] = w(0);

                    [1f800000] = w(3);
                    A0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24;
                    A1 = SP + 20;
                    A2 = bu[80074ea4 + S2 * 84 + 5e];
                    A3 = h[80074ea4 + S2 * 84 + 62] / 10;
                    animation_prepare_bones_matrixes;

                    // set camera matrix as root bone transformation
                    V0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24;
                    V1 = w[80071e40]; // camera data
                    A0 = w[V0 + 20];
                    [A0 +  0] = w(w[V1 +  0]);
                    [A0 +  4] = w(w[V1 +  4]);
                    [A0 +  8] = w(w[V1 +  8]);
                    [A0 +  c] = w(w[V1 +  c]);
                    [A0 + 10] = w(w[V1 + 10]);
                    [A0 + 14] = w(w[V1 + 14]);
                    [A0 + 18] = w(w[V1 + 18]);
                    [A0 + 1c] = w(w[V1 + 1c]);
                }
                else
                {
                    [1f800000] = w(3);
                    A0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24;
                    A1 = w[80071e40]; // offset to camera section
                    A2 = bu[80074ea4 + S2 * 84 + 5e]; // animation id
                    A3 = hu[80074ea4 + S2 * 84 + 62] / 10; // current frame
                    animation_prepare_bones_matrixes;
                }
            }
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_model;
    800AAEB4	bne    v0, zero, Laab8c [$800aab8c]
}



// update vervexes in drafts
if (number_of_model > 0)
{
    S2 = 0;
    loopaaed8:	; 800AAED8
        if (bu[block7_data + S2 * 8 + 4] != ff) // model enabled
        {
            [SP + 10] = h(w[80074ea4 + S2 * 84 + c] >> c);
            [SP + 12] = h(w[80074ea4 + S2 * 84 + 10] >> c);
            [SP + 14] = h((w[80074ea4 + S2 * 84 + 14] >> c) - a);
            A0 = SP + 10;
            A1 = SP + 18;
            field_calculate_distance_to_screen; // calculate distance to screen

            if (V0 < 0f00)
            {
                A0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24;
                S0 = b[A0 + 1]; // +1[] KAWAI byte in new structure
                if (S0 == 4 || S0 == 8 || S0 == 9 || S0 == b || S0 == c)
                {
                    A0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24;
                    funcae23c;
                }
                else
                {
                    [A0 + 1] = b(ff);

                    A0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24;
                    funcae23c;

                     A0 = w[model_struct + 4] + bu[block7_data + S2 * 8 + 4] * 24;
                    [A0 + 1] = b(S0);
                }
            }
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_model;
    800AB028	bne    v0, zero, loopaaed8 [$800aaed8]
}



// update model kawai
if (number_of_model > 0)
{
    S2 = 0;
    loopab04c:	; 800AB04C
        if (bu[block7_data + S2 * 8 + 4] != ff) // model enabled
        {
            S3 = h[80074EA4 + S2 * 84 + 00];
            if (S3 == 1)
            {
                [SP + 10] = h(w[80074ea4 + S3 + c] >> c);
                [SP + 12] = h(w[80074ea4 + S3 + 10] >> c);
                [SP + 14] = h((w[80074ea4 + S3 + 14] >> c) - a);
                A0 = SP + 10;
                A1 = SP + 18;
                field_calculate_distance_to_screen; // calculate distance to screen

                if (V0 < 0f00)
                {
                    V1 = w[8004a62c];
                    A2 = bu[block7_data + S2 * 8 + 4]; // model id
                    A0 = w[V1 + 4] + A2 * 24;
                    A1 = w[80074ea4 + S2 * 84 + 04]; // offset to kawai data
                    A3 = w[80071e40]; // offset to camera section
                    run_kawai;

                    if (V0 == 1)
                    {
                        [80074ea4 + S2 * 84 + 00] = h(2);
                    }
                }
            }
        }

        S2 = S2 + 1;
        V0 = S2 < number_of_model;
    800AB148	bne    v0, zero, loopab04c [$800ab04c]
}



V0 = h[8009ac1c];
if (V0 > 0)
{
    S3 = 0;
    S0 = 0;
    S1 = block7_data;

    S2 = 0;
    loopab178:	; 800AB178
        V1 = bu[S1 + 4];
        if (V1 != ff)
        {
            V0 = bu[80074ea4 + S0 + 8];
            if (V0 != 1)
            {
                if (bu[80074ea4 + S0 + 9] == 0)
                {
                    [S5 + 0] = b(2);
                    [S5 + 1] = b(2);
                    [S5 + 2] = b(0);
                    [S5 + 3] = b(S2);
                    V1 = bu[801144d8];
                    V0 = V1 + 1;
                    V1 = V1 & ff;
                    [801144d8] = b(V0);

                    V0 = bu[800e0638 + V1];
                    V0 = V0 & 1f;
                    [80074ea4 + S0 + 9] = b(V0 + 40);
                }
                else
                {
                    [S5 + 0] = b(1);
                    [S5 + 1] = b(1);
                    [S5 + 2] = b(0);
                    [S5 + 3] = b(S2);
                    [80074ea4 + S0 + 9] = b(bu[80074ea4 + S0 + 9] - 1);
                }

                V0 = w[8004a62c];
                A0 = w[V0 + 4] + S3;
                A1 = S5;
                funcb1c7c;
            }
        }

        S3 = S3 + 24;
        S0 = S0 + 84;
        V0 = h[8009ac1c];
        S1 = S1 + 8;
        S2 = S2 + 1;
        V0 = S2 < V0;
    800AB274	bne    v0, zero, loopab178 [$800ab178]
}

return;
////////////////////////////////////////////////////
