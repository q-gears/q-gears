////////////////////////////////
// system_init_script_system
//a0=8010E030 a1=8008B000 a2=00000062 a3=00000007 ra=800A9A5C // start of battle
//a0=8010E030 a1=80073C44 a2=80073C40 a3=8012FA60 ra=801EF4DC // end of battle
//a0=8010A7B8 a1=8010D5A8 a2=8008B000 a3=00090084 ra=800A8BDC // start of field

pointer_to_script_file = A0; // pointer to event file

[80068158] = w(w[80011a44]);
[8007adf8] = w(pointer_to_script_file + 80); // pointer to entity scripts data
[8007adfc] = w(bu[pointer_to_script_file + 3]); // number of entity
[8007ae8c] = w(pointer_to_script_file + 2c);

A0 = w[8006794c];
V1 = w[A0 + 1c];
[V1 + 810] = w(pointer_to_script_file + 4);
[V1 + 80c] = w(pointer_to_script_file + 2c);



V1 = bu[A0 + 8];
if (V1 == 1 || V1 == 2 || V1 == 3)
{
    [8007b708] = w(V1);
}
else if (V1 == 8)
{
    [8007b708] = w(4);
}



// store previous script state
V1 = bu[80077e60 + 16ee];
if ((V1 == 1 || V1 == 3) && (w[8007b708] == 2))
{
    V1 = 80079630;
    V0 = 80077e60; // current script data

    while (V0 != 80079620)
    {
        [V1 + 0] = w(w[V0 + 0]);
        V0 = V0 + 4;
        V1 = V1 + 4;
    }

    [V1 + 0] = w(w[V0 + 0]);
    [V1 + 4] = w(w[V0 + 4]);
}

// store here pointer to current script state
[8007aecc] = w(80077e60);



// init memory allocated list
A0 = 80077e60 + 1450;
while (A0 < 80077e60 + 15c4)
{
    [A0 + 8] = w(A0 + c);
    A0 = A0 + c;
}
[A0 + 8] = w(0);

// set first and last pointers
[80077e60 + 15d0] = w(0);
[80077e60 + 15d4] = w(80077e60 + 1450);



// init script list
A0 = 80077e60 + 15d8;
while (A0 < 80077e60 + 16d0)
{
    [A0 + 0] = w(A0 + 8);
    A0 = A0 + 8;
}
[A0 + 0] = w(0);

// set first, current and last elements in script list
[80077e60 + 16d8] = w(0);
[80077e60 + 16dc] = w(0);
[80077e60 + 16e0] = w(80077e60 + 15d8);



func50044; // reset something



A0 = 0;
func50080;



// init first 50 byte
S1 = 0;
loop4a284:	; 8004A284
    [80077e60 + S1] = b(0);
    S1 = S1 + 1;
    V0 = S1 < 50;
8004A29C	bne    v0, zero, loop4a284 [$8004a284]



[80077e60 + 16ec] = b(0);
[80077e60 + 16ed] = b(0);
[80077e60 + 1700] = h(0);



A0 = 0;
func4ff98;



[80077e60 + 16e8] = h(0);
[80077e60 + 16ea] = h(0);
[80077e60 + 16ef] = b(0);
[80077e60 + 16f8] = b(0);

[8007ae4c] = w(fffffa60); // -5a0
[8007ae50] = w(0);
[8007ae58] = w(0);
[8007ae68] = w(0);
[8007aec0] = w(0);
[8007aec8] = w(0);
[8007b6fc] = w(0);
[8007b710] = w(a);
[8007b718] = w(0);
[8007bbc8] = w(a);
[8007bbd4] = w(0);
[8007bd2c] = b(0);



// start first script
A0 = 0;
A1 = 0;
A2 = 14;
A3 = 10;
func367d0;
[V0 + 5] = b(2);
[V0 + e] = b(2); // run



// clear script party data
V1 = w[8007aecc];
[V1 + 16e4] = w(ffffffff);



// get party data and store it as mask
S1 = 0;
S2 = 0;
loop4a3a0:	; 8004A3A0
    A0 = S1;
    func4e7a4;

    if (V0 >= 0)
    {
        S2 = S2 | (1 << bu[8006e63c + V0]);
    }

    S1 = S1 + 1;
    V0 = S1 < 4;
8004A3C8	bne    v0, zero, loop4a3a0 [$8004a3a0]



// convert mask to script id and store it to script variables
if (S2 != 0)
{
    V1 = w[8007aecc];
    S0 = V1 + 16e4;

    S1 = 0;
    loop4a3e4:	; 8004A3E4
        if (S2 & 1)
        {
            [S0] = b(bu[8007adfc] + bu[8006e630 + S1] - 9);
            S0 = S0 + 1;
        }

        S1 = S1 + 1;
        S2 = S2 >> 1;
    8004A40C	bne    s2, zero, loop4a3e4 [$8004a3e4]
}



S1 = 7;
V0 = 8007aed0 + 1c;
loop4a424:	; 8004A424
    [V0] = w(0);

    V0 = V0 - 4;
    S1 = S1 - 1;
8004A42C	bgez   s1, loop4a424 [$8004a424]



[8007ae04] = w(0);



V1 = w[8007b708];
if (V1 == 2) // if battle
{
    S5 = 4;
    S1 = 0;
    loop4a468:	; 8004A468
        A0 = S1;
        func4e7a4;

        A0 = V0;
        if (A0 >= 0) // if in party
        {
            S0 = w[8007adfc] + A0 - 9;

            A0 = S0;
            A1 = 0;
            A2 = ac;
            A3 = 10;
            func367d0;

            A1 = V0;

            [A1 + 5] = b(4);
            [A1 + f] = b(bu[A1 + f] | 4);
            [A1 + 2f] = b(40);
            [A1 + 34] = h(ffff);
            [A1 + 3c] = b(10);
            [A1 + 3d] = b(10);
            [A1 + 3e] = b(ff);
            [A1 + 5c] = b(1e);
            [A1 + 5d] = b(10);
            [A1 + 5e] = b(1f);
            [A1 + 5f] = b(10);
            [A1 + 61] = b(ff);
            [A1 + 69] = b(10);
            [A1 + 6e] = h(4);
            [A1 + 71] = b(50);
            [A1 + 72] = b(4);
            [A1 + 73] = b(10);
            [A1 + 7c] = w(10101010);
            [A1 + 93] = b(ff);


            V1 = w[8007ae04];
            [8007aed0 + V1 * 4] = w(A1);
            [8007ae04] = w(V1 + 1);
        }

        S1 = S1 + 1;
        V0 = S1 < 4;
    8004A56C	bne    v0, zero, loop4a468 [$8004a468]

    V1 = w[8007aecc];
    [V1 + 16fc] = w(w[V1 + 16dc]);
}
else
{
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    [V0 + 570] = b(0);
}

[8007ae04] = w(4);




some1 = bu[80079630 + 16ee]; // old script state
some2 = hu[80079630 + 16f4]; // old script state
V1 = w[8006794c];
V0 = w[V1 + 1c];

if ((w[8007b708] == 1 && some1 == 1 && some2 == h[V0 + c]) || (w[8007b708] == 3 && some1 == 3 && some2 == h[V0 + 7dc]) || (bu[V1 + a] == 9 && bu[8007ad1e] != 0))
{
    // restore script state
    A0 = 80077e60;
    V1 = 80079630; // old script state

    while (V1 != 80079630 + 17c0)
    {
        [A0] = w(w[V1]);
        V1 = V1 + 4;
        A0 = A0 + 4;
    }

    [A0 + 0] = w(w[V1 + 0]);
    [A0 + 4] = w(w[V1 + 4]);



    V0 = w[8007aecc];
    S0 = w[V0 + 16d8];
    if (S0 != 0)
    {
        loop4a6ec:	; 8004A6EC
            V1 = w[S0 + 4];

            if (w[V1 + 0] != 0)
            {
                [V1 + 0] = w(w[V1 + 0] + pointer_to_script_file - w[80079630 + 16f0]);
            }

            if (bu[V1 + 5] == 4 && w[8007b708] == 1) // model entity and this is field
            {
                A0 = bu[V1 + 6];
                8004A72C	jal    funcaa3f4 [$800aa3f4]
            }

            S0 = w[S0 + 0];
        8004A73C	bne    s0, zero, loop4a6ec [$8004a6ec]
    }



    V0 = w[8007aecc];
    V1 = w[V0 + 16d8];
    if (V1 != 0)
    {
        loop4a75c:	; 8004A75C
            V0 = w[V1 + 4];
            V0 = bu[V0 + 7];
            if (V0 == 0)
            {
                break;
            }
            V1 = w[V1 + 0];
        8004A77C	bne    v1, zero, loop4a75c [$8004a75c]
    }

    if (V1 != 0)
    {
        A0 = w[V1 + 4];
    }
    else
    {
        A0 = 0;
    }

    A1 = 0; // priority
    A2 = a; // script
    A3 = 0;
    func384d0; // run script



    V0 = w[8007aecc];
    A0 = w[V0 + 16d8];
    if (A0 != 0)
    {
        loop4a7bc:	; 8004A7BC
            V1 = w[A0 + 4];
            V0 = bu[V1 + 7];
            if (V0 != 0)
            {
                [V1 + 12] = b(bu[V1 + e]);
                [V1 + e] = b(3);
            }
            A0 = w[A0];
        8004A7E8	bne    a0, zero, loop4a7bc [$8004a7bc]
    }
}
else
{
    func48f54; // we run script execute here
}



A0 = w[8007aecc];

[A0 + 16f0] = w(pointer_to_script_file);
[A0 + 16ee] = b(bu[8007b708]);

if (w[8007b708] == 1)
{
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    [A0 + 16f4] = h(hu[V0 + c]);

}
else if (w[8007b708] == 3)
{
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    [A0 + 16f4] = h(hu[V0 + 7dc]);
}
else
{
    [A0 + 16f4] = h(0);
}
////////////////////////////////



////////////////////////////////
// func49ed8
S2 = A0;

S4 = 0;

S0 = 0;
loop49f08:	; 80049F08
    A0 = S0;
    func4e7a4;

    if (V0 >= 0)
    {
        S4 = S4 | (1 << V0);
    }

    S0 = S0 + 1;
    V0 = S0 < 4;
80049F24	bne    v0, zero, loop49f08 [$80049f08]

V1 = bu[S2 + 3]; // read number of something
A0 = S2 + 80;

[8007adf8] = w(A0);
[8007adfc] = w(V1);

if (V1 >= a)
{
    S2 = A0 + hu[A0 - 48 + V1 * 8];
}
else
{
    S2 = A0 + V1 * 8;
}

A0 = w[8007adfc];
V0 = w[8007adf8];

S0 = V0 + A0 * 8 - 48;

S3 = 1;
S1 = S0 + 2;

loop49f94:	; 80049F94
    V0 = bu[S1 + 3];
    if ((V0 & 1) == 0)
    {
        S4 = S4 | S3;
    }

    if (S4 & S3)
    {
        V0 = hu[S0];
        if (V0 != 0)
        {
            A1 = w[8007adf8] + V0;
            if (A1 != S2)
            {
                V0 = hu[S1];
                if (V0 != 0)
                {
                    A0 = S2;
                    A2 = V0;
                    func1d0f8;

                    V0 = S2 - hu[8007adf8];
                    [S0] = h(V0);
                }
            }
            else
            {
                V0 = hu[S1];
            }

            V0 = V0 & fffc;
            S2 = S2 + V0;
        }
    }

    S3 = S3 << 1;
    S1 = S1 + 8;

    S0 = S0 + 8;
    V0 = S0 < w[8007adf8] + w[8007adfc] * 8;
8004A034	bne    v0, zero, loop49f94 [$80049f94]

[8007ae00] = w(S4);

return S2;
////////////////////////////////



////////////////////////////////
// func50044
[8007bc0c] = w(0);
[8007bc08] = w(0);
[8007bbf0] = w(0);
[8007bbec] = w(0);
////////////////////////////////



////////////////////////////////
// func50080
if (w[8007bc10] != A0)
{
    [8007bc10] = w(A0);
    [8007bc14] = w(2c);
}
////////////////////////////////



////////////////////////////////
// func4ff98
if (A0 == 0)
{
    [8007bbe0] = w(0);
    [8007bbe8] = w(0);
}
else
{
    V0 = w[8006794c];
    V0 = w[V0 + 24];
    V0 = V0 >> 11;
    V0 = V0 & 1;
    V1 = (V0 & 1) == 0;

    if (A0 >= 3)
    {
        [8007bbe8] = w(3c);
        return;
    }

    V0 = w[8007aecc];
    if (bu[V0 + 16ec] != 0)
    {
        if (V1 == 1)
        {
            if (A0 == 2 || w[8007bbc8] >= 3 || w[8007b710] != 0)
            {
                [8007bbe8] = w(3c);
            }
        }
    }
}
////////////////////////////////



////////////////////////////////
// func4e7a4
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 54c + A0 * 4];
if (V0 != 0)
{
    return w[V0 + 34] & f;
}
else
{
    return -1;
}
////////////////////////////////



////////////////////////////////
// func19774
[80068158] = w(w[A0]);
////////////////////////////////