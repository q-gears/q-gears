////////////////////////////////
// 801B0000-801B001C
// main
func1b031c;
////////////////////////////////



////////////////////////////////
// 801B0020-801B0208
V0 = h[8015169c];
S1 = 80162978 + V0 * 20;

A0 = 801bd7b8;
A1 = 801bd7c8;
system_create_rotation_matrix_from_euler_angle;

[SP + 40] = w(h[S1 + c]); // scale
[SP + 44] = w(h[S1 + c]);
[SP + 48] = w(h[S1 + c]);

A0 = 801bd7c8;
A1 = SP + 40;
system_scale_matrix_by_vector;

[801bd7dc] = w(h[S1 + 4]); // X
[801bd7e0] = w(h[S1 + 6]); // Y (0)
[801bd7e4] = w(h[S1 + 8]); // Z

A0 = 800fa63c; // camera matrix
A1 = 801bd7c8;
A2 = SP + 10;
system_transformation_data_multiply;

A0 = SP + 10;
system_set_rotation_matrix_to_GTE;

A0 = SP + 10;
system_set_translation_vector_to_GTE;




[1f800000] = w(801bd3e4);
[1f800004] = w(8);

V0 = hu[S1 + 2] & 3;
[1f800008] = h(hu[801bd7c0 + V0 * 2]);

V1 = h[S1 + 2];
if (V1 < 8)
{
    [1f80000a] = h((V1 + 1) * c);
}
else if (V1 < 10)
{
    [1f80000a] = h(80);
}
else if (V1 < 18)
{
    [1f80000a] = h(80 - ((V1 - f) * c));
}
else
{
    [S1 + 0] = h(-1);
    return;
}

[1f80000e] = h(0);
[1f80000c] = h(((hu[S1 + 2] >> 3) & 1) | 20);
[1f800000] = 800f197c; // offset to effect 3d data



// load effect geometry
A0 = 1f800000;
A1 = w[801517c0];
A1 = A1 + 70;
A2 = c;
A3 = w[801dd7e8]
funcd29d4;
[801dd7e8] = w(V0);


if (bu[80062d98] == 0)
{
    [S1 + 2] = h(hu[S1 + 2] + 1);
}
////////////////////////////////



////////////////////////////////
// 801B020C-801B02B8
S0 = A0;

A0 = 801b0020;
funcbbeac;

S1 = 80162978 + V0 * 20;

A0 = S0;
A1 = bu[801518e4 + S0 * b9c + 2b];
A2 = S1 + 4;
battle_get_point_by_model_bone;
[S1 + 6] = h(0); // set y coord to ground

A0 = S0;
funcd55a4;
V1 = V0;
if (V1 > 7fff)
{
    V1 = 7fff;
}
[S1 + c] = h(V1);

A0 = S0;
funcd5774; // add hurt action to target
////////////////////////////////



////////////////////////////////
// 801B02BC-801B0318
V0 = h[8015169c];
A0 = 80162978 + V0 * 20;

[801dd7e8] = w(801bd7e8 + h[A0 + 2] * 10000);

[A0 + 2] = h(hu[A0 + 2] XOR 1);

if (h[80162080] < 2)
{
    [A0 + 0] = h(-1);
}
////////////////////////////////



////////////////////////////////
// 801B031C-801B03A0
S1 = A0; // target mask
S0 = A1; // attacker id

// load texture
A0 = 801b03a4;
A1 = 0;
A2 = 0;
A3 = 0;
funcd2980;

A0 = 801b02bc;
funcbbeac;

A0 = S1;
A1 = S0;
A2 = 0;
A3 = 801b020c;
funcd5444;

// play sound calculation
A0 = S1;
funcd574c;
A0 = 20;
A1 = V0;
A2 = a;
funcd55f4; // we play sound here
////////////////////////////////