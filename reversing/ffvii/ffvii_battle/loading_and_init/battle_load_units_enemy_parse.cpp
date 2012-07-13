////////////////////////////////
// funcb5138
S0 = 4;
if (S0 < bu[800f7e04] + 4)
{
    loopb5168:	; 800B5168
        [80151200 + S0 * 74 + 32] = b(0);
        S0 = S0 + 1;
        V0 = S0 < bu[800f7e04] + 4;
    800B5188	bne    v0, zero, loopb5168 [$800b5168]
}



// set global offsets to all animation script files in model files
S0 = 3;
if (S0 < bu[800f7df4] + 3) // number of enemies
{
    loopb51b8:	; 800B51B8
        model_file = w[800f8390 + (S0 - 3) * 4]; // offset to model file
        [model_file + 8] = w(model_file + w[model_file + 8]);

        S0 = S0 + 1;
        V0 = S0 < bu[800f7df4] + 3;
    800B51E0	bne    v0, zero, loopb51b8 [$800b51b8]
}



// set some offsets to global in animation script file in model file
S0 = 3;
if (S0 < bu[800f7df4] + 3) // number of enemies
{
    loopb5214:	; 800B5214
        model_file = w[800f8390 + (S0 - 3) * 4]; // offset to model file
        script_file = w[model_file + 8]; // offset to file with animation scripts

        A1 = 0;
        loopb5224:	; 800B5224
            [A0 + 24 + A1 * 4] = w(script_file + w[A0 + 24 + A1 * 4]);
            A1 = A1 + 1;
            V0 = A1 < 8;
        800B5240	bne    v0, zero, loopb5224 [$800b5224]

        S0 = S0 + 1;
        V0 = S0 < bu[800f7df4] + 3;
    800B52CC	bne    v0, zero, loopb5288 [$800b5288]
}



// set global offsets to all animation scripts for enemies
S0 = 3;
if (S0 < bu[800f7df4] + 3) // number of enemies
{
    loopb5288:	; 800B5288
        model_file = w[800f8390 + (S0 - 3) * 4]; // offset to model file
        script_file = w[model_file + 8]; // offset to file with animation scripts

        A1 = 0;
        loopb5298:	; 800B5298
            [A0 + 68 + A1 * 4] = w(script_file + w[A0 + 68 + A1 * 4]);
            A1 = A1 + 1;
            V0 = A1 < 20;
        800B52B4	bne    v0, zero, loopb5298 [$800b5298]

        S0 = S0 + 1;
        V0 = S0 < bu[800f7df4] + 3;
    800B52CC	bne    v0, zero, loopb5288 [$800b5288]
}



V0 = bu[800f7e04] + 4;
S0 = 4;
800B52DC	j      Lb52f8 [$800b52f8]

loopb52e4:	; 800B52E4
    A0 = S0;
    funcb54b8; // parse loaded model file here (init some values and create skeletons)

    V0 = bu[800f7e04] + 4;
    S0 = S0 + 1;

    Lb52f8:	; 800B52F8
    V0 = S0 < V0;
800B5300	bne    v0, zero, loopb52e4 [$800b52e4]



S0 = 4;
if( S0 < bu[800f7e04] + 4 )
{
    loopb5350:	; 800B5350
        [80163784 + S4] = b(bu[801636b8 + S0 * 10 + 1]); // idle action id

        [80163c80 + S0 * 6 + 0] = h(hu[800f7e08 + (S0 - 4) * c + 2]); // x default position from formation
        [80163c80 + S0 * 6 + 2] = h(hu[800f7e08 + (S0 - 4) * c + 4]); // y default position from formation
        [80163c80 + S0 * 6 + 4] = h(hu[800f7e08 + (S0 - 4) * c + 6]); // z default position from formation

        [801518e4 + S0 * b9c + 160] = h(0); // root x rotation
        [801518e4 + S0 * b9c + 164] = h(0); // root z rotation

        switch( bu[800fa6d0] ) // formation type
        {
            case 1: // enemy look from left to left initial, left to right normal
            {
                [801518e4 + S0 * b9c + 18] = h(0800); // default
                [801518e4 + S0 * b9c + 162] = h(0); // root y rotation
            }
            break;

            case 0 2 4 8: // enemy look from sides to center
            {
                V0 = h[80163c80 + S0 * 6 + 4];
                if (V0 < 0)
                {
                    [801518e4 + S0 * b9c + 18] = h(0800);
                    [801518e4 + S0 * b9c + 162] = h(0800);
                }
                else
                {
                    [801518e4 + S0 * b9c + 18] = h(0);
                    [801518e4 + S0 * b9c + 162] = h(0);
                }
            }

            case 3 5 6 7: // enemy looks from center to sides
            {
                V0 = h[80163c80 + S0 * 6 + 4];
                if (V0 >= 0)
                {
                    [801518e4 + S0 * b9c + 18] = h(0800);
                    [801518e4 + S0 * b9c + 162] = h(0800);
                }
                else
                {
                    [801518e4 + S0 * b9c + 18] = h(0);
                    [801518e4 + S0 * b9c + 162] = h(0);
                }
            }
            break;
        }

        S0 = S0 + 1;
        V0 = S0 < bu[800f7e04] + 4;
    800B549C	bne    v0, zero, loopb5350 [$800b5350]
}
////////////////////////////////



////////////////////////////////
// funcb54b8
unit_id = A0;

V1 = bu[80151200 + unit_id * 74 + 32];
if (V1 == 6)
{
    enemy_id = 6;
}
else
{
    enemy_id = h[800f7e08 + (unit_id - 4) * c + 0]; // enemy id
}

V0 = w[800f8384 + enemy_id * 4]; // loaded file offset
A0 = unit_id;
A1 = V0 + w[V0 + 4]; // offset to 1st file (model data)
A2 = 1;
funcbb538;



V1 = w[800f8384 + enemy_id * 4]; // loaded file offset
S3 = w[V1 + 8];

[801518e4 + unit_id * b9c + 0] = h(hu[800f7dec + enemy_id * 4]);
[801518e4 + unit_id * b9c + 8] = h(hu[S3 + 6]);
[801518e4 + unit_id * b9c + a] = h(hu[S3 + 8]);
[801518e4 + unit_id * b9c + c] = h(hu[S3 + a]);
[801518e4 + unit_id * b9c + 12] = h(hu[S3 + 4]);
[801518e4 + unit_id * b9c + 27] = b(bu[S3 + 2]);
[801518e4 + unit_id * b9c + 28] = b(0); // additional R
[801518e4 + unit_id * b9c + 29] = b(0); // additional G
[801518e4 + unit_id * b9c + 2a] = b(0); // additional B
if (h[S3 + 0] != 0)
{
    [801518e4 + unit_id * b9c + 27] = b(bu[801518e4 + unit_id * b9c + 27] | 40);
}



[80151200 + unit_id * 78 + 26] = h(hu[S3 + c]);
[80151200 + unit_id * 78 + 28] = h(hu[S3 + e]);
[80151200 + unit_id * 78 + 2a] = h(hu[S3 + c] - 384);
[80151200 + unit_id * 78 + 2e] = h(0);
[80151200 + unit_id * 78 + 30] = h(hu[S3 + 64]);



A2 = 0;
loopb5704:	; 800B5704
    [80151200 + unit_id * 78 + 4 + A2 * 2] = h(hu[S3 + 44 + A2 * 2]);
    A2 = A2 + 1;
    V0 = A2 < 4;
800B5718	bne    v0, zero, loopb5704 [$800b5704]



A2 = 0;
loopb5754:	; 800B5754
    [80151200 + unit_id * 78 + e + A2 * 2] = h(hu[S3 + 4c + A2 * 2]);
    [80151200 + unit_id * 78 + 1a + A2 * 2] = h(hu[S3 + 58 + A2 * 2]);
    A2 = A2 + 1;
    V0 = A2 < 6;
800B5774	bne    v0, zero, loopb5754 [$800b5754]



[801636b8 + unit_id * 10 + 4] = b(bu[801518e4 + unit_id * b9c + 27] & 3f);



if (bu[801518e4 + unit_id * b9c + 27] & 80) // if secondary animation
{
    [800fa6d8 + unit_id * 40 + 38] = w(801518e4 + unit_id * b9c + 140);

    A1 = w[800f8384 + enemy_id * 4]; // loaded file offset
    A0 = 800fa6d8 + unit_id * 40 + 3c;
    V0 = w[A1] - 1;
    A1 = A1 + w[A1 + V0 * 4]; // offset to last file - 1 in model file
    A2 = unit_id;
    funcc7924;
}



// copy joints
S5 = 0;
loopb5848:	; 800B5848
    [8015190f + unit_id * b9c + S5] = b(bu[S3 + S5 + 12]);
    S5 = S5 + 1;
    V0 = S5 < 10;
800B585C	bne    v0, zero, loopb5848 [$800b5848]
////////////////////////////////



////////////////////////////////
// funcc7924
S5 = A0;
offset_to_subfile = A1;
unit_id = A2;

[800fa6d8 + unit_id * 40 + 30] = h(0);
[800fa6d8 + unit_id * 40 + 32] = h(0);
[800fa6d8 + unit_id * 40 + 34] = h(0);

[S5] = h(hu[offset_to_subfile] + 1); // store number of bones

bone = 0;

offset_to_subfile = offset_to_subfile + 4;

if (h[S5] > 0)
{
    loopc79c8:	; 800C79C8
        [800fa6d8 + unit_id * 40 + 3e + bone] = b(0);

        data = w[offset_to_subfile + bone * 8 + 4]
        if (data == 0)
        {
            [800fa6d8 + unit_id * 40 + bone * 4 + 4] = w(0);
        }
        else if (data < 0)
        {
            [800fa6d8 + unit_id * 40 + 3e + bone] = b(1);
            [800fa6d8 + unit_id * 40 + bone * 4 + 4] = w(offset_to_subfile + (data & 7fffffff) - 4);
        }
        else
        {
            [800fa6d8 + unit_id * 40 + bone * 4 + 4] = w(offset_to_subfile + data - 4);
        }

        if (bone != 0)
        {
            V0 = h[offset_to_subfile + bone * 8 + 0];
            [800fa6d8 + unit_id * 40 + bone * 34 + 30] = h(0); // translation X
            [800fa6d8 + unit_id * 40 + bone * 34 + 32] = h(0); // translation Y
            [800fa6d8 + unit_id * 40 + bone * 34 + 34] = h(hu[offset_to_subfile + V0 * 8 + 2]); // translation Z
            [800fa6d8 + unit_id * 40 + bone * 34 + 38] = w(800fa6d8 + 8 + unit_id * 40 + V0 * 34);
        }

        bone = bone + 1;
        V0 = bone < h[S5];
    800C7B28	bne    v0, zero, loopc79c8 [$800c79c8]
}
////////////////////////////////



////////////////////////////////
// funcbb538
unit_id = A0;
model_data = A1;

V1 = w[801590e8];
V1 = bu[801590e8 + V1 - 4];
if (V1 == 2)
{
    if (A2 == 0)
    {
        A0 = 800f8158; // struct with field background rotation and translation
    }
    else
    {
        A0 = 800f818c;
    }

    A1 = 801518e4 + unit_id * b9c + 140;
}
else if (unit_id == 3)
{
    A0 = 800fa63c; // camera matrix
    A1 = 80153cf8;
}
else
{
    A0 = 800f8158; // struct with field background rotation and translation
    A1 = 801518e4 + unit_id * b9c + 140;
}

[A1 + 30] = w(A0);


[801518e4 + 34 + unit_id * b9c + 170] = w(801518e4 + 140 + unit_id * b9c);

A0 = 801518e4 + unit_id * b9c + 10; // number of bones
A1 = model_data;
A2 = unit_id;
funcc76c8;
////////////////////////////////



////////////////////////////////
// funcc76c8
S4 = A0;
offset_to_subfile = A1;
unit_id = A2;

[801518e4 + unit_id * b9c + 174 + 28] = h(0);
[801518e4 + unit_id * b9c + 174 + 2a] = h(0);
[801518e4 + unit_id * b9c + 174 + 2c] = h(0);

[S4] = h(hu[offset_to_subfile] + 1); // number of bone

offset_to_subfile = offset_to_subfile + 4;

bone = 0;
if (w[S4] > 0)
{
    Lc7760:	; 800C7760
        [801518e4 + unit_id * b9c + 3f + bone] = b(0);

        data = w[offset_to_subfile + bone * 8 + 4];
        if (data == 0)
        {
            [801518e4 + unit_id * b9c + 78 + bone * 4] = w(0);
        }
        else if (data < 0)
        {
            [801518e4 + unit_id * b9c + 3f + bone] = b(1);
            [801518e4 + unit_id * b9c + 78 + bone * 4] = w(offset_to_subfile + (data & 7fffffff) - 4);
        }
        else
        {
            [801518e4 + unit_id * b9c + 78 + bone * 4] = w(offset_to_subfile + data - 4);
        }

        if (bone != 0)
        {
            V0 = h[offset_to_subfile + bone * 8 + 0];
            [801518e4 + unit_id * b9c + bone * 34 + 174 + 28] = h(0); // translation X
            [801518e4 + unit_id * b9c + bone * 34 + 174 + 2a] = h(0); // translation Y
            [801518e4 + unit_id * b9c + bone * 34 + 174 + 2c] = h(hu[offset_to_subfile + V0 * 8 + 2]); // translation Z
            [801518e4 + unit_id * b9c + bone * 34 + 174 + 30] = w(801518e4 + unit_id * b9c + 174 + V0 * 34);
        }

        bone = bone + 1;
        V0 = bone < h[S4];
    800C78F8	bne    v0, zero, Lc7760 [$800c7760]
}
////////////////////////////////