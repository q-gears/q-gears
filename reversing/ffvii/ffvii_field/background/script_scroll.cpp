////////////////////////////////
// funca4430
if (bu[8009abf4 + 1f] == 0)
{
    switch (bu[8009abf4 + 1d])
    {
        case 0: // auto scroll to pc
        {
            [8009a100] = h(0);
            [8009abf4 + 1f] = b(2);
            [80071e38] = h(0);
            [80071e3c] = h(0);
        }
        break;

        case 1:
        {
            [8009a100] = h(1);
            [8009abf4 + 1f] = b(1);
        }
        break;

        case 2: // scroll from current to party member (linear)
        case 3: // scroll from current to party member (smooth)
        {
            [8009a100] = h(1);
            [8009abf4 + 1f] = b(1);
            [80075cf8] = h(0);
            [8009c558] = h(hu[8009abf4 + 20]);
            [80075e14] = h(hu[80071e38]); // start
            [80075e1c] = h(hu[80071e3c]); // start
        }
        break;

        case 4: // scroll to coordinates (type instant)
        {
            [8009a100] = h(1);
            [8009abf4 + 1f] = b(2);
            [80071e38] = h(hu[8009abf4 + a]);
            [80071e3c] = h(hu[8009abf4 + c]);
        }
        break;

        case 5: // scroll to coordinates (type linear)
        case 6: // scroll to coordinates (type smooth)
        {
            [8009a100] = h(1);
            [8009abf4 + 1f] = b(1);
            [80075cf8] = h(0); // current step
            [8009c558] = h(hu[8009abf4 + 20]); // steps
            [80075e14] = h(hu[80071e38]); // start
            [80075e18] = h(hu[8009abf4 + a]); // end
            [80075e1c] = h(hu[80071e3c]); // start
            [80075e20] = h(hu[8009abf4 + c]); // end
        }
        break;
    }
}
////////////////////////////////



////////////////////////////////
// funca496c
if (bu[8009abf4 + 1f] == 1)
{
    switch (bu[8009abf4 + 1d])
    {
        case 1:
        {
            A0 = SP + 10;
            800A49B8	jal    funca48b8 [$800a48b8]

            A0 = SP + 10;
            800A49C0	jal    funca47f8 [$800a47f8]

            [80071e38] = h(-hu[SP + 10]);
            [80071e3c] = h(-hu[SP + 12]);
        }
        break;

        case 2:
        {
            800A49F0	jal    funca48b8 [$800a48b8]
            800A49F4	addiu  a0, sp, $0010
            800A49F8	jal    funca47f8 [$800a47f8]
            800A49FC	addiu  a0, sp, $0010
            800A4A00	lui    a0, $8007
            800A4A04	lh     a0, $5e14(a0)
            800A4A08	lui    a2, $800a
            800A4A0C	lh     a2, $c558(a2)
            800A4A10	lh     a1, $0010(sp)
            800A4A14	lui    a3, $8007
            800A4A18	lh     a3, $5cf8(a3)
            800A4A1C	jal    calculate_current_value_by_steps [$800a4094]
            800A4A20	subu   a1, zero, a1
            800A4A24	lui    a0, $8007
            800A4A28	lh     a0, $5e1c(a0)
            800A4A2C	lui    a2, $800a
            800A4A30	lh     a2, $c558(a2)
            800A4A34	lui    a3, $8007
            800A4A38	lh     a3, $5cf8(a3)
            800A4A3C	lh     a1, $0012(sp)
            800A4A40	lui    at, $8007
            800A4A44	sh     v0, $1e38(at)
            800A4A48	subu   a1, zero, a1

            calculate_current_value_by_steps;
            [80071e3c] = h(V0);

            if (h[8009c558] == h[80075cf8])
            {
                [8009abf4 + 1f] = b(2);
            }
            else
            {
                [80075cf8] = h(V1 + 1);
            }
        }
        break;

        case 3:
        {
            800A4A80	jal    funca48b8 [$800a48b8]
            800A4A84	addiu  a0, sp, $0010
            800A4A88	jal    funca47f8 [$800a47f8]
            800A4A8C	addiu  a0, sp, $0010
            800A4A90	lui    a0, $8007
            800A4A94	lh     a0, $5e14(a0)
            800A4A98	lui    a2, $800a
            800A4A9C	lh     a2, $c558(a2)
            800A4AA0	lh     a1, $0010(sp)
            800A4AA4	lui    a3, $8007
            800A4AA8	lh     a3, $5cf8(a3)
            800A4AAC	jal    calculate_smooth_current_value_by_steps [$800a4134]
            800A4AB0	subu   a1, zero, a1
            800A4AB4	lui    a0, $8007
            800A4AB8	lh     a0, $5e1c(a0)
            800A4ABC	lui    a2, $800a
            800A4AC0	lh     a2, $c558(a2)
            800A4AC4	lui    a3, $8007
            800A4AC8	lh     a3, $5cf8(a3)
            800A4ACC	lh     a1, $0012(sp)
            800A4AD0	lui    at, $8007
            800A4AD4	sh     v0, $1e38(at)
            800A4AD8	jal    calculate_smooth_current_value_by_steps [$800a4134]
            800A4ADC	subu   a1, zero, a1
            [80071e3c] = h(V0);

            if (h[8009c558] == h[80075cf8])
            {
                [8009abf4 + 1f] = b(2);
            }
            else
            {
                [80075cf8] = h(V1 + 1);
            }
        }
        break;

        case 5:
        {
            A0 = h[80075e14];
            A1 = h[80075e18];
            A2 = h[8009c558];
            A3 = h[80075cf8];
            calculate_current_value_by_steps;
            [80071e38] = h(V0);

            A0 = h[80075e1c];
            A1 = h[80075e20];
            A2 = h[8009c558];
            A3 = h[80075cf8];
            calculate_current_value_by_steps;
            [80071e3c] = h(V0);

            if (h[8009c558] == h[80075cf8])
            {
                [8009abf4 + 1f] = b(2);
            }
            else
            {
                [80075cf8] = h(V1 + 1);
            }
        }
        break;

        case 6: // scroll to coordinates (type smooth)
        {
            A0 = h[80075e14];
            A1 = h[80075e18];
            A2 = h[8009c558];
            A3 = h[80075cf8];
            calculate_smooth_current_value_by_steps;
            [80071e38] = h(V0);

            A0 = h[80075e1c];
            A1 = h[80075e20];
            A2 = h[8009c558];
            A3 = h[80075cf8];
            calculate_smooth_current_value_by_steps;
            [80071e3c] = h(V0);

            if (h[8009c558] == h[80075cf8])
            {
                [8009abf4 + 1f] = b(2);
            }
            else
            {
                [80075cf8] = h(V1 + 1);
            }
        }
        break;
    }
}
////////////////////////////////



////////////////////////////////
// field_update_shaking
S0 = A0;

if (bu[S0 + 0] == 1)
{
    if (bu[S0 + 1] == 0)
    {
        [S0 + c] = h(0);
        [S0 + 6] = h(0);

        V0 = bu[S0 + 2];
        V0 = ((bu[800e0638 + V0] * h[S0 + 4]) << 10) >> 10;
        if (V0 < 0)
        {
            V0 = V0 + ff;
        }
        [S0 + 8]= h(V0 >> 8);
        [S0 + 1] = b(1);
        [S0 + 2] = b(bu[S0 + 2] + 1);
    }
    else
    {
        if (h[S0 + a] >= h[S0 + c])
        {
            [S0 + c] = h(h[S0 + c] + 1);

            A0 = h[S0 + 6]; // start
            A1 = h[S0 + 8]; // end
            A2 = h[S0 + a]; // steps
            A3 = h[S0 + c]; // cur step
            calculate_smooth_current_value_by_steps;

            [S0 + 3] = b(V0);
            return;
        }

        [S0 + c] = h(0);
        [S0 + 6] = h(h[S0 + 8]);

        V0 = bu[S0 + 2];
        V0 = ((bu[800e0638 + V0] * h[S0 + 4]) << 10) >> 10;

        if (h[S0 + 8] >= 0)
        {
            V0 = -V0;
        }

        if (V0 < 0)
        {
            V0 = V0 + ff;
        }

        [S0 + 8]= h(V0 >> 8);
        [S0 + 2] = b(bu[S0 + 2] + 1);
    }
}
else
{
    if (bu[S0 + 1] == 1)
    {
        if (h[S0 + a] < h[S0 + c])
        {
            [S0 + 6] = h(hu[S0 + 8]);
            [S0 + c] = h(0);
            [S0 + 8] = h(0);
            [S0 + 1] = b(0);

            [S0 + 2] = b(bu[S0 + 2] + 1);
            return;
        }
    }
    else
    {
        if (h[S0 + a] == h[S0 + c])
        {
            [S0 + 3] = b(0);
            return;
        }
    }

    [S0 + c] = h(h[S0 + c] + 1);

    A0 = hu[S0 + 6];
    A1 = hu[S0 + 8];
    A2 = hu[S0 + a];
    A3 = h[S0 + c];
    calculate_smooth_current_value_by_steps;

    [S0 + 3] = b(V0);
}
////////////////////////////////