////////////////////////////////
// field_check_and_set_load_background_in_advance
A1; // offset to triggers data

x = w[A0 + c] >> c;
y = w[A0 + 10] >> c;

V1 = bu[8009abf4 + 32]; // 0 if PC can move. 1 - otherwise.
if (V1 == 0)
{
    T0 = 7fffffff;
    A2 = 0;
    loopa153c:	; 800A153C
        map_id = hu[A1 + 12]; // map id

        if (map_id != 7fff)
        {
            A0 = (h[A1 + 0] - x) * (h[A1 + 0] - x) + (h[A1 + 2] - y) * (h[A1 + 2] - y);

            if (A0 < T0)
            {
                [80095dd0] = h(map_id);
                T0 = A0;
            }
        }

        A1 = A1 + 18;
        A2 = A2 + 1;
        V0 = A2 < c;
    800A15A0	bne    v0, zero, loopa153c [$800a153c]
}


if ( (bu[8009abf5] == 3) || (hu[800e4d44] == 1) || (bu[8009abf5] == 2) )
{
    field_stop_load_background_in_advance;

    return;
}

if (h[80071a5c] == h[80095dd0]) // if we already load data for that map
{
    return;
}

A0 = h[80095dd0];

if (w[800da5c4 + A0 * 18] > 0004dfff)
{
    return;
}

field_stop_load_background_in_advance;

V0 = h[80095dd0];
[80071a5c] = h(V0);

if (V0 >= 41) // if not world map id's
{
    A0 = w[800da5c0 + V1 * 18 + 0];
    A1 = w[800da5c0 + V1 * 18 + 4];
}
else
{
    A0 = w[800def80];
    A1 = w[800def84];
}

A2 = 801b0000;
A3 = 0;
func33e34; // set data to load in background

[800965e8] = h(1); // field background already loading
////////////////////////////////



////////////////////////////////
// field_stop_load_background_in_advance
if (h[800965e8] == 1)
{
    func3408c; // stop background loading
}

[80071a5c] = h(0);
[800965e8] = h(0);
////////////////////////////////