////////////////////////////////
// 801B0000-801B00B4
V0 = h[8015169c];
S0 = 80162978 + V0 * 20;

A0 = S0 + 8;
A1 = 00001000; // scale
A2 = h[S0 + 12];
funcd4368;

[801c0600] = h(hu[S0 + 2]);

A0 = 801c05f8;
A1 = w[801517c0] + 70;
A2 = c;
A3 = w[801c8604];
funcd4d90;
[801c8604] = w(V0);

if (bu[80062d98] == 0)
{
    V0 = h[S0 + 2] + 1;
    [S0 + 2] = h(V0);

    if (V0 >= e)
    {
        [S0 + 0] = h(-1);
    }
}
////////////////////////////////



////////////////////////////////
// 801B00B8-801B020C
// at atart add hurt action and then 3 times add fire effect
V0 = h[8015169c];
S1 = 80162978 + V0 * 20;

V1 = bu[80062d98];
if (V1 == 0)
{
    if (h[S1 + 2] == 0)
    {
        A0 = h[S1 + 4];
        funcd5774; // add hurt action to target
    }

    if ((hu[S1 + 2] & 1) == 0)
    {
        A0 = 801b0000;
        funcbbeac; // fire effect
        S0 = 80162978 + V0 * 20;

        func42da8; // random
        rand = V0 & f;

        [S1 + 6] = h((h[S1 + 6] + rand + 1) % h[801518e4 + h[S1 + 4] * b9c + 10]); // % by number of bones in target model

        A0 = h[S1 + 4]; // unit id
        A1 = h[S1 + 6]; // bone id
        A2 = S0 + 8; // store here position
        battle_get_point_by_model_bone;

        [S0 + 12] = h(hu[S1 + 12]);
    }

    [S1 + 2] = h(h[S1 + 2] + 1);

    if (h[S1 + 2] >= 5)
    {
        [S1 + 0] = h(-1);
    }
}
////////////////////////////////



////////////////////////////////
// 801B0210-801B0290
// function callback to add effect for all units in target mask
target_id = A0;

A0 = 801b00b8;
funcbbeac;

[80162978 + V0 * 20 +  4] = h(target_id);
[80162978 + V0 * 20 +  6] = h(0);
[80162978 + V0 * 20 + 12] = h(-hu[801518e4 + target_id * b9c + 12]); // collision radius
////////////////////////////////



////////////////////////////////
// 801B0294-801B02E8
if (w[800f8368] != 0)
{
    [801c8604] = w(801c0604);
}
else
{
    [801c8604] = w(801c4604);
}

if (h[80162080] < 2)
{
    V0 = h[8015169c];
    [80162978 + V0 * 20 + 0] = h(-1);
}
////////////////////////////////



////////////////////////////////
// 801B02EC-801B0378
// main
S0 = A0; // target mask
S1 = A1; // attacker id

// load texture
A0 = 801b039c;
A1 = 0;
A2 = 0;
A3 = 0;
funcd2980;

A0 = S0;
A1 = S1;
A2 = 0;
A3 = 801b0210;
funcd5444; // call function for all units in target mask

A0 = 801b0294;
funcbbeac;

// play sound calculation
A0 = h[80151774]; // target_mask
funcd574c; // calculate some sound param (volume maybe)
A0 = 20;
A1 = V0;
A2 = 9;
funcd55f4; // we play sound here
////////////////////////////////



8000037C	addiu  sp, sp, $ffe8 (=-$18)
80000380	sw     ra, $0010(sp)
80000384	jal    $8001c3c4
80000388	nop
8000038C	lw     ra, $0010(sp)
80000390	addiu  sp, sp, $0018
80000394	jr     ra 
80000398	nop
