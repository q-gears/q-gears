////////////////////////////////
// funcab4ac
S4 = A0;

S1 = 0;
loopab4e0:	; 800AB4E0
    [800e42ee + S1 * 18] = h(0);
    [800e42ea + S1 * 18] = h(S1 << 2);
    [800e42e8 + S1 * 18] = h(S1 % 8);

    [S4 + S1 * 10 + 1749c + 3] = b(3);
    [S4 + S1 * 10 + 1749c + 4] = b(10);
    [S4 + S1 * 10 + 1749c + 5] = b(10);
    [S4 + S1 * 10 + 1749c + 6] = b(10);
    [S4 + S1 * 10 + 1749c + 7] = b(42);

    S1 = S1 + 1;
    V0 = S1 < 40;
800AB584	bne    v0, zero, loopab4e0 [$800ab4e0]

A0 = 0; // tp
A1 = 1; // abr
A2 = 0; // vram_x
A3 = 0; // vram_y
system_create_texture_page_settings_for_packet;

A0 = S4 + 17490;
A1 = 0;
A2 = 0;
A3 = V0;
A4 = 0;
func44a68;
////////////////////////////////



////////////////////////////////
// funca3020
// init packets for background
V0 = w[8009d848];
background = w[V0];

draft1 = A0;
draft2 = A1;
S5 = A2;
[SP + 20] = h(0);
[SP + 28] = h(0);
[8011448c] = h(0);
[801144d0] = h(0);

FP = A3;

block1 = background + 10;
block2 = background + w[background + 0];
block3 = background + w[background + 4];
block4 = background + w[background + 8];
block5 = background + w[background + c];

La3098:	; 800A3098
    V1 = h[block1];

    if (V1 == 7fff)
    {
        block1 = block1 + 2;
        800A30A8	j      La31a0 [$800a31a0]
    }

    A0 = FP;
    if (V1 == 7ffe)
    {
        A1 = 0;
        A2 = 1;
        A3 = hu[block3];
        block3 = block3 + 2;
        A4 = 0;
        800A30D0	jal    func44a68 [$80044a68]

        [8011448c] = h(hu[8011448c] + 1);

        FP = FP + c;
    }
    else
    {
        S3 = h[block1 + 4];
        if (S3 != 0)
        {
            loopa3110:	; 800A3110
                [draft1 + 3] = b(3);
                [draft1 + 4] = b(80);
                [draft1 + 5] = b(80);
                [draft1 + 6] = b(80);
                [draft1 + 7] = b(7d);
                [draft1 + 8] = h(hu[block2 + 0]);
                [draft1 + a] = h(hu[block2 + 2]);
                [draft1 + c] = b(bu[block2 + 4]);
                [draft1 + d] = b(bu[block2 + 5]);
                [draft1 + e] = h(hu[block2 + 6]);

                [SP + 20] = h(hu[SP + 20] + 1);
                draft1 = draft1 + 10;
                block2 = block2 + 8;
                S5 = S5 + 2;
                S3 = S3 - 1;
            800A3190	bne    s3, zero, loopa3110 [$800a3110]
        }
    }

    block1 = block1 + 6;
800A3198	j      La3098 [$800a3098]

La31a0:	; 800A31A0

[8011448c] = h(hu[SP + 20] - hu[8011448c]);

La31d4:	; 800A31D4
    if (h[block1] == 7fff)
    {
        block1 = block1 + 2;
        800A30A8	j      La3304 [$800a31a0]
    }

    S3 = h[block1 + 4];
    if (S3 != 0)
    {
        loopa3204:	; 800A3204
            A0 = FP;
            A1 = 0;
            A2 = 1;
            A3 = hu[block4 + 8]; // texture page settings
            A4 = 0;
            800A3214	jal    func44a68 [$80044a68]

            [801144d0] = h(hu[801144d0] + 1);

            [draft1 + 3] = b(3);
            [draft1 + 7] = b(7d);

            if (hu[block4 + c] & 80)
            {
                [draft1 + 7] = b(7f);
            }

            [draft1 + 4] = h(hu[block4 + a]); // distance
            [draft1 + 6] = b(80);
            [draft1 + 8] = h(hu[block4 + 0]); // dest x
            [draft1 + a] = h(hu[block4 + 2]); // dest y
            [draft1 + c] = b(bu[block4 + 4]); // src x
            [draft1 + d] = b(bu[block4 + 5]); // src y
            [draft1 + e] = h(hu[block4 + 6]); // clut

            [S5 + 0] = b(bu[block4 + c]); // animation
            [S5 + 1] = b(bu[block4 + d]); // index

            [SP + 20] = h(hu[SP + 20] + 1);
            draft1 = draft1 + 10;
            block4 = block4 + e;
            FP = FP + c;
            S5 = S5 + 2;
            S3 = S3 - 1;
        800A32F4	bne    s3, zero, loopa3204 [$800a3204]
    }

    block1 = block1 + 6;
800A32FC	j      La31d4 [$800a31d4]

La3304:	; 800A3304

[801144c8] = h(hu[SP + 20]);

La3334:	; 800A3334
    V1 = h[block1];
    if (V1 == 7fff)
    {
        block1 = block1 + 2;
        800A3344	j      La34a8 [$800a34a8]
    }

    if (V1 == 7ffe)
    {
        A0 = FP;
        A1 = 0;
        A2 = 1;
        FP = FP + c;
        A3 = hu[block3];
        block3 = block3 + 2;
        A4 = 0;
        800A3370	jal    func44a68 [$80044a68]
    }
    else
    {
        S3 = h[block1 + 4];

        [block1 + 2] = h(hu[SP + 28]);

        if (S3 != 0)
        {
            loopa3398:	; 800A3398
                [draft2 + 3] = b(4);
                [draft2 + 7] = b(65);

                A0 = draft2;
                if (bu[block5 + 8] & 80)
                {
                    [draft2 + 7] = b(67);
                }

                [draft2 + 4] = b(80);
                [draft2 + 5] = b(80);
                [draft2 + 6] = b(80);
                [draft2 + 8] = h(hu[block5 + 0]);
                [draft2 + a] = h(hu[block5 + 2]);
                [draft2 + c] = b(bu[block5 + 4]);
                [draft2 + d] = b(bu[block5 + 5]);
                [draft2 + e] = h(hu[block5 + 6]);
                [draft2 + 10] = h(20);
                [draft2 + 12] = h(20);

                [S5 + 0] = b(bu[block5 + 8]);
                [S5 + 1] = b(bu[block5 + 9]);

                [SP + 28] = h(hu[SP + 28] + 1);
                draft2 = draft2 + 14;
                block5 = block5 + a;
                S5 = S5 + 2;
                S3 = S3 - 1;
            800A3498	bne    s3, zero, loopa3398 [$800a3398]
        }
    }

    block1 = block1 + 6;
800A34A0	j      La3334 [$800a3334]

La34a8:	; 800A34A8

La34ac:	; 800A34AC
    V1 = h[block1];
    if (V1 == 7fff)
    {
        return;
    }

    if (V1 == 7ffe)
    {
        A0 = FP;
        A1 = 0;
        A2 = 1;
        FP = FP + c;
        A3 = hu[block3];
        block3 = block3 + 2;
        A4 = 0;
        800A34E0	jal    func44a68 [$80044a68]
    }
    else
    {
        S3 = h[block1 + 4];

        [block1 + 2] = h(hu[SP + 28]);
        if (S3 != 0)
        {
            loopa3508:	; 800A3508
                [draft2 + 3] = b(4);
                [draft2 + 7] = b(65);

                A0 = draft2;
                V1 = w[8007ebd4];
                if (bu[V1 + 8] & 80)
                {
                    [draft2 + 7] = b(67);
                }

                [draft2 + 4] = b(80);
                [draft2 + 5] = b(80);
                [draft2 + 6] = b(80);
                [draft2 + 8] = h(hu[V1 + 0]);
                [draft2 + a] = h(hu[V1 + 2]);
                [draft2 + c] = b(bu[V1 + 4]);
                [draft2 + d] = b(bu[V1 + 5]);
                [draft2 + e] = h(hu[V1 + 6]);
                [draft2 + 10] = h(20);
                [draft2 + 12] = h(20);

                [S5 + 0] = b(bu[V1 + 8]);
                [S5 + 1] = b(bu[V1 + 9]);

                [SP + 28] = h(hu[SP + 28] + 1);
                [8007ebd4] = w(w[8007ebd4] + a);
                draft2 = draft2 + 14;
                S5 = S5 + 2;
                S3 = S3 - 1;
            800A3608	bne    s3, zero, loopa3508 [$800a3508]
        }
    }

    block1 = block1 + 6;
800A3610	j      La34ac [$800a34ac]
////////////////////////////////
