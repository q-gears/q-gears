////////////////////////////////
// func39c38
S4 = w[8007b704];
A1 = w[8007b70c];
V0 = w[A1];
A0 = V0;
[8007aea0] = w(A0);
A3 = bu[V0]; // read byte from opcode stream
V0 = V0 + 1;
[A1] = w(V0);
V1 = bu[V0]; // read byte from opcode stream
V0 = V0 + 1;
[A1] = w(V0);

[8007b6f8] = w(0);
[8007b6f4] = w(V1);
S0 = S4;

289F0380 12
A0A00380 16
80A10380 18
7CA30380 1a
00FB0380 1b
0C1F0480 1e
80C60380 24
B45A0480 28
78B00380 37
CCF70380 38
802D0480 39
D4AB0380 3b
88DD0380 3c
2CF10380 3e
48F00380 3f
9CF50380 42
CCF60380 44
58F70380 45
A89E0380 46
5C430480 49
0CFA0380 4a
C4E30380 4c
D8E40380 4d
1CEB0380 4e
90EB0380 4f
80B90380 53
00DD0380 57
C8000480 58
B8080480 5a
940B0480 5c
6C0D0480 5d
440F0480 5e
94140480 5f
6C150480 60
38170480 63
74180480 64
34560480 69
8CFF0380 6b
48040480 70
20050480 71
5C060480 72
F4060480 73
04070480 74
58D60380 76
70D70380 77
A0D80380 78
A89E0380 79
8CB80380 7c
40570480 7d
1C390480 89
6C3B0480 8a
6CDB0380 8c
C8560480 8d
BCB20380 91
ECBD0380 96
30C00380 96
74A50380 97
5CC40380 98
38B30380 99
18B50380 9b
2CD50380 9e
D4C60380 a0
1CC70380 a2
ECA90380 a3
ACD30380 a4
70C50380 a5
28CB0380 a6
9CB40380 a7
38410480 ac
28DA0380 ae
28550480 b0
14560480 b1
984B0480 b2
ACF50380 b5
90D90380 b6
0C5C0480 b7
585C0480 b8
D82F0480 b9
E0300480 ba
E0E60380 c0
E4E70380 c1
E8E80380 c2
98210480 c3
A45C0480 c4
70220480 c9
C8E90380 cc
70EA0380 cd
44450480 cf
90C30380 d0
985D0480 d1
A89E0380 d2
A89E0380 d3
E8E10380 d4
80A60380 d5
ECA60380 d6
84FD0380 db
60AB0380 df
F8540480 e0
B4FB0380 e1
70260480 e4
80F90380 e5
BC130480 e6
601B0480 e7
8CC80380 e8
E84D0480 e9
24290480 ea
E0C20380 eb
FC240480 ed
C42F0480 ee
6CA60380 f0
04510480 f3
EC510480 f4
C0DA0380 f5
A85D0480 f6
CC5F0480 f9
08610480 fa
A0610480 fb
14620480 fc
F4630480 ff




case 00 01 02 03 04 05 06 0a 0b 0c 0d 0e 0f 11 13 15 17 19 1c 22 30 31 32 6c 6d 6e 7f 80 81 82 83 84 85 af d8: // 38750480
{
    A0 = S4;
    A1 = A3; // opcode

    V1 = w[8007b708]; // runned module

    if (V1 == 1)
    {
        80047578	jal    func500a8 [$800500a8]
        return V0;
    }
    if (V1 == 2)
    {
        func50410;
        return V0;
    }
    if (V1 == 3)
    {
        800475A0	jal    func50744 [$80050744]
        return V0;
    }

    return 1;
}
break;

case 07: // D49C0380
{
    T0 = w[8007b70c];
    V0 = w[T0];
    A1 = bu[V0];
    [T0] = w(V0 + 1);

    A0 = w[8007b6f4];
    A2 = 14;
    A3 = 10;
    func367d0;
    [V0 + 5] = w(2);

    [8007b6f8] = w(1);

    return 0;
}
break;

case 08: // 109D0380
{

    T0 = w[8007b70c];
    V0 = w[T0];
    A1 = bu[V0];
    [T0] = w(V0 + 1);

    A0 = w[8007b6f4];
    A2 = 38;
    A3 = 10;
    func367d0;
    [V0 + 5] = b(3);
    [V0 + f] = b(1);

    [8007b6f8] = w(1);

    return 0;
}
break;

case 09: // 649D0380
{
    A0 = w[8007b70c];
    S2 = w[8007b6f4];
    V0 = w[A0 + 0];
    S3 = bu[V0]; // read script
    [A0] = w(V0 + 1);

    if (S2 - fb < 4)
    {
        V0 = w[8007aecc];
        S2 = bu[V0 + S2 - fb + 16e4];
    }

    A0 = S2;
    A1 = S3;
    A2 = ac;
    A3 = 10;
    func367d0;

    T0 = V0;
    [T0 + 5] = b(04);
    [T0 + f] = b(bu(T0 + f) | 04);
    [T0 + 2f] = b(40);
    [T0 + 34] = h(ffff);
    [T0 + 3c] = b(10);
    [T0 + 3d] = b(10);
    [T0 + 3e] = b(ff);
    [T0 + 5c] = b(1e);
    [T0 + 5d] = b(10);
    [T0 + 5e] = b(1f);
    [T0 + 5f] = b(10);
    [T0 + 61] = b(ff);
    [T0 + 69] = b(10);
    [T0 + 6e] = h(0004);
    [T0 + 71] = b(50);
    [T0 + 72] = b(04);
    [T0 + 73] = b(10);
    [T0 + 7c] = w(10101010);
    [T0 + 93] = b(ff);

    V1 = w[8007b708];
    if (V1 == 1)
    {
        A0 = S2;
        funcaa3f4;
    }
    else if (V1 == 2)
    {
        A0 = w[8007ae04];
        [8007aed0 + A0 * 4] = w(T0);
        [8007ae04] = w(A0 * 4 + 1);
    }

    [8007b6f8] = w(1);

    return 0;
}
break;

case 10: // B09E0380
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    system_get_entity_script_data_pointer_from_script; // get entity scruct
    A0 = V0; // entity_struct

    V1 = w[8007b70c];
    V0 = w[V1];
    A2 = bu[V0]; // script to start
    [V1] = w(V0 + 1);

    A1 = S2; // priority
    A3 = 0; // not pause current
    func384d0; // run script

    return 0;
}
break;

case 14: // E09F0380
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    system_get_entity_script_data_pointer_from_script;
    S1 = V0;

    A0 = w[8007b70c];
    V1 = w[A0];
    S5 = bu[V1];
    [A0] = w(V1 + 1);

    if ((S1 != 0) && (S2 < bu[S1 + 4]))
    {
        A0 = S1;
        A1 = S2; // priority
        A2 = S5; // script to start
        A3 = 1; // pause current
        func384d0;
    }
    else
    {
        A1 = w[8007b70c];
        [A1] = w(w[8007aea0]);
    }

    return 1;
}
break;

case bf: // 50AC0380
{
    system_get_entity_script_data_pointer_from_script;
    S4 = V0;
case 1d: // 5CAC0380
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    S5 = 0;

    if (w[8007b708] == 1) // if this is field
    {
        S5 = (hu[S4 + 34] XOR ffff) != 0;
    }

    if (S5 != 0)
    {
        A0 = bu[S4 + 3b];
        A1 = 0;
        funcc3e18;
    }

    [S4 + 40] = w(S2);    [S4 + 14] = w(S2);    // X
    [S4 + 44] = w(-8000); [S4 + 18] = w(-8000); // Y
    [S4 + 48] = w(S3);    [S4 + 1c] = w(S3);    // Z

    if (S5 != 0)
    {
        A0 = bu[S4 + 3b];
        A1 = 1;
        funcc3e18;
    }

    if (bu[S4 + 5] == 4)
    {
        [S4 + 30] = h(0);
        [S4 + 50] = h(hu[S4 + 50] & ffcf);
        [S4 + 78] = w(7fffffff);
    }

    [8007aea4] = w(1);

    return 0;
}
break;

case 1f: // 90B90380
{
    [8007b6f8] = w(1);

    current_script_data = w[8007b704];

    get8byte;
    [current_script_data + 10] = b(V0);

    get8byte;
    S5 = V0;

    A2 = bu[current_script_data + 10];
    if( ( S5 & a0 == 80 ) && ( bu[current_script_data + 5] == 4 ) )
    {
        V0 = w[8007aecc];
        A0 = w[V0 + 16d8];
        if (A0 != 0)
        {
            loop3babc:	; 8003BABC
                V1 = w[A0 + 4];
                if (bu[V1 + 5] == 4 && bu[V1 + 3e] == A2)
                {
                    [V1 + 3e] = b(ff);
                }

                A0 = w[A0];
            8003BAF0	bne    a0, zero, loop3babc [$8003babc]
        }

        [current_script_data + 3e] = b(A2);
        [8007ae68] = w(current_script_data);
        [8007ae6c] = w(0);
    }

    get16byte;
    S3 = V0;

    A0 = current_script_data;
    A1 = S3;
    A2 = S5;
    func39660;

    A0 = S3;
    A1 = bu[current_script_data + 10];
    A2 = V0;
    A3 = S5;
    func4dcec;

    [current_script_data + d] = b(fe);

    return 1;
}
break;

case 20: // CCBB0380
{
    [8007b6f8] = w(1);

    current_script_data = w[8007b704];

    get8byte;
    [current_script_data + 10] = b(V0);

    get8byte;
    S5 = V0;

    A2 = bu[current_script_data + 10];
    if( ( S5 & a0 == 80 ) && ( bu[current_script_data + 5] == 4 ) ) // if normal model dialog
    {
        V0 = w[8007aecc];
        A0 = w[V0 + 16d8];
        if (A0 != 0)
        {
            loop3bcf8:	; 8003BCF8
                V1 = w[A0 + 4];
                if (bu[V1 + 5] == 4 && bu[V1 + 3e] == A2)
                {
                    [V1 + 3e] = b(ff);
                }

                A0 = w[A0];
            8003BD2C	bne    a0, zero, loop3bcf8 [$8003bcf8]
        }

        [current_script_data + 3e] = b(A2);
        [8007ae68] = w(current_script_data);
        [8007ae6c] = w(0);
    }

    get16byte;
    S3 = V0;

    A0 = current_script_data;
    A1 = S3;
    A2 = S5;
    func39660;

    A0 = S3;
    A1 = bu[current_script_data + 10];
    A2 = V0;
    A3 = S5;
    func4dcec;

    return 0;
}
break;

case 21: // 6CC20380
{
    [8007b6f8] = w(1);

    get8byte;
    A0 = V0;

    func4ea4c;

    return 0;
}
break;

case 23: // 7CC40380
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;
    A2 = V0;

    A0 = S2;
    A1 = 0;
    A3 = 0;
    func38990;

    if (V0 != 0)
    {
        A0 = w[8007b70c];
        [A0] = w(w[8007aea0]); // restore script position before this opcode
    }
    return 1;
}
break;

case 25: // 30C40380
{
    [S4 + 30] = h(0);
    [S4 + 50] = h(hu[S4 + 50] & ffcf);
    [S4 + 63] = b(ff);
    [S4 + 78] = w[7fffffff];

    return 0;
}
break;

case 26: // B4CA0380
{
    [8007b6f8] = w(1);

    get8byte;
    [S4 + 5c] = b(V0);

    return 0;
}
break;

case 27: // 941E0480
{
    [8007b6f8] = w(1);

    get8byte;
    A0 = V0;

    funcc7464;

    return 0;
}
break;

case 29: // 14D20380
{
    [8007b6f8] = w(1);

    current_script_data = w[8007b704];
    S1 = current_script_data + 18;

    get8byte;
    A0 = V0;

    S0 = A0 - 1;

    [current_script_data + 14] = w(A0);

    if (A0 != 0)
    {
        loop3d2ac:	; 8003D2AC

            get16byte;
            A1 = V0;
            [S1 + 0] = h(A1);

            get16byte;
            A1 = V0;
            [S1 + 2] = h(A1);

            S0 = S0 - 1;
            V0 = -1;
            S1 = S1 + 4;
        8003D39C	bne    s0, v0, loop3d2ac [$8003d2ac]
    }

    return 0;
}
break;

case 2a: // C8DA0380
{
    [8007b6f8] = w(1);

    get8byte;
    [8007bd2c] = b(V0);

    get16byte;
    S2 = V0;

    V1 = w[8006794c];
    V1 = w[V1 + 1c];
    [V1 + 848] = b(-1);
    [V1 + 571] = b((S2 >> f) & 1);

    A0 = S2 & 7fff;
    func1e2ac;

    return 3;
}
break;

case 2b: // F8D80380
{
    [8007b6f8] = w(1);

    get16byte;
    A0 = V0;

    func1e2ac;

    return 0;
}
break;

case 2c: // 00E00380
{
    A0 = w[8007aecc];
    V0 = w[8007b70c];
    [A0 + 16ed] = b(bu[V0 + 7]);

    return 0;
}
break;

case 2d: // 20E00380
{
    V0 = w[8007aecc];
    [V0 + 16ec] = b(0);

    A0 = 0;
    func4ff98;

    [8007b710] = w(0);
    [8007bbc8] = w(0);

    return 0;
}
break;

case 2e: // 4CE00380
{
    V1 = w[8007aecc];
    [V1 + 16ec] = b(1);

    A0 = 1;
    func4ff98;

    S1 = w[8007aecc];
    if (h[S1 + 1700] >= 0)
    {
        if (w[8007b720] >= 8007b92d)
        {
            system_reset_random;
        }

        V0 = w[8007b720];
        V1 = bu[V0];
        [8007b720] = w(V0 + 1);
        [S1 + 1700] = h((V1 + c8) * 4);
    }

    return 0;
}
break;

case 2f: // C0E00380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 34] = h(V0);

    A0 = w[8007b70c];
    func21698;
    [S4 + 3b] = b(V0);

    V1 = w[8007b70c];
    [V1 + f] = b(bu[V1 + f] | 1);

    get8byte;
    A2 = V0;

    [S3 + 32] = h(-(A2 * 4));

    return 0;
}
break;

case 33: // B8EB0380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 54] = h(V0);

    return 0;
}
break;

case 34: // 40EC0380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 56] = h(V0);

    return 0;
}
break;

case 35: // C8EC0380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 58] = h(V0);

    return 0;
}
break;

case 87: // FCAF0380
{
    system_get_entity_script_data_pointer_from_script;
    S4 = V0;
case 36: // 08B00380
{
    [8007b6f8] = w(1);

    get8byte;
    [S4 + 22] = h(V0 << 4);

    return 0;
}
break;

case 3a: // B42C0480
{
    system_get_entity_script_data_pointer_from_script;
    A0 = V0;

    S0 = 0;

    if ((A0 != 0) && (hu[A0 + 34] != ffff))
    {
        A0 = bu[A0 + 3b];
        func1e350;

        if (V0 != 0)
        {
            S0 = w[V0 + 8];
        }
    }

    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    if (S0 != 0)
    {
        [S0 + 14] = w(w[S0 + 14] | (1 << S2));
    }

    return 0;
}
break;

case 3d: // 4CF30380
{
    [8007b6f8] = w(1);

    get8byte;
    [S0 + 60] = b(V0);

    get8byte;
    [S0 + 61] = b(V0);

    return 0;
}
break;

case bd: //28F40380
{
    system_get_entity_script_data_pointer_from_script;
    S0 = V0;
case 40: // 34F40380
{
    [8007b6f8] = w(1);

    get16byte;
    S1 = V0;


    if ((bu[S0 + 62] & 80) && (bu[S0 + f] & 80))
    {
        A0 = S0;
        func4b9b8;
    }

    [S0 + 36] = h(S1);
    [S0 + 3a] = b(bu[S0 + 60]);

    [S0 + 62] = b(bu[S0 + 62] & b9);

    if (bu[S0 + 61] <  bu[S0 + 60])
    {
        [S0 + 62] = b(bu[S0 + 62] | c0);
    }
    else
    {
        [S0 + 62] = b(bu[S0 + 62] | 80);
    }

    [S0 + 64] = b(0);


    A0 = hu[S0 + 34];
    A1 = S1;
    system_get_number_of_frames_in_animation;
    [S0 + 38] = b(V0);

    [S0 + 5d] = b(bu[S0 + 69]);

    V0 = w[8007aecc];
    if (bu[S0 + 7] == bu[V0 + 16ed])
    {
        [8007b710] = w(w[8007b710] + 1);
    }

    return 0;
}
break;

case be: // 74F50380
{
    system_get_entity_script_data_pointer_from_script;
    S0 = V0;
case 41: // 80F50380
{
    if (bu[S0 + 62] & 80)
    {
        [8007b6f8] = w(1);

        A2 = w[8007b70c];
        [A2] = w(w[8007aea0]);

        return 1;
    }

    return 0;
}
break;

case 43: // E0F50380
{
    V0 = w[8007b70c]; // current entity
    S2 = bu[V0 + 7] + 40;

    // search in script list
    V1 = w[8007aecc];
    V1 = w[V1 + 16d8];
    if (V1 != 0)
    {
        loop3f604:	; 8003F604
            V0 = w[V1 + 4];
            V0 = bu[V0 + 7];
            if (V0 == S2)
            {
                break;
            }

            V1 = w[V1 + 0];
        8003F624	bne    v1, zero, loop3f604 [$8003f604]
    }

    A0 = 0;
    if (V1 != 0)
    {
        A0 = w[V1 + 4];
    }

    if (A0 != 0)
    {
        func36978;
    }

    [8007b6f8] = w(1);

    get8byte;
    A0 = V0;
    A1 = S2;
    A2 = 14;
    A3 = 0;
    func367d0; // init entity

    [V0 + 5] = b(1);

    return 0;
}
break;

case 47: // 34B20380
{
    [8007b6f8] = w(1);

    get8byte;

    [S4 + 50] = h(hu[S4 + 50] & fff8);
    [S4 + 50] = h(hu[S4 + 50] | (V0 & 0007));

    return 0;
}
break;

case 48: // 14420480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    if (S2 < 100)
    {
        A0 = S2;
        A1 = S2;
        func27d84;
    }
    else if (S2 < 200)
    {
        A0 = S2 - 100;
        func28074;
    }
    else
    {
        S3 = S3 - 1;
        if (S3 != -1)
        {
            S0 = V0;

            loop44340:	; 80044340
                A0 = S2 - 200;
                func6238c;

                S3 = S3 - 1;
            8004434C	bne    s3, s0, loop44340 [$80044340]
        }
    }
    return 0;
}
break;

case 4b: // 54A70380
{
    [8007b6f8] = w(1);

    V0 = w[8007b704];

    if (bu[V0 + 5] == 4)
    {
        get8byte;
        S2 = V0;

        if (w[8007b708] == 1) // if field
        {
            A1 = S2 << 2;
            if (hu[S4 + 34] != ffff)
            {
                A0 = bu[S4 + 3b];
                A1 = A1 & fffc;
                funcc7570;
            }
        }

        get8byte;
        [S4 + 3c] = b(V0);

        get8byte;
        [S4 + 3d] = b(V0);
    }
    else
    {
        get8byte;
        get8byte;
        get8byte;
    }
    return 0;
}
break;

case bc: // 10B70380
{
    system_get_entity_script_data_pointer_from_script;
    S0 = V0;
case 50: // 1CB70380
{
    if (bu[S0 + f] & 80)
    {
        [8007b6f8] = w(1);

        A1 = w[8007b70c];
        [A1 + 0] = w(w[8007aea0]);
    }

    return 1;
}
break;

case 51: // 58B60380
{
    system_get_entity_script_data_pointer_from_script; // pointer to entity data
    S1 = V0;

    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    if (S1 != 0)
    {
        A0 = w[S1 + 14] - w[S0 + 14];
        A1 = w[S1 + 1c] - w[S0 + 1c];
        system_get_rotation_by_vector_x_y;

        A0 = S0;
        A1 = V0;
        A2 = 1;
        A3 = S2;
        func398d0;
    }

    return 0;
}
break;

case 52: // 60EE0380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 74] = h(V0);

    return 0;
}
break;

case 54: // F8C20380
{
    [8007b6f8] = w(1);

    get8byte;
    A3 = V0;

    A0 = w[8007b704];
    [A0 + 10] = b(A3);
    [A0 + d] = b(fe);

    rerurn 1;
}
break;

case 55: // 38CA0380
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    if (S2 == 0)
    {
        S2 = ff;
    }

    [S0 + 5f] = b(S2);
    return 0;
}
break;

case bb: // B8B30380
{
    system_get_entity_script_data_pointer_from_script;
    S0 = V0;
case 56: // C4B30380
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0 * 10;

    get8byte;
    A3 = V0;

    A0 = S0;
    A1 = S2;
    A2 = 1;
    A3 = V0;
    func398d0;

    return 0;
}
break;

case 59: // 14070480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    get8byte;
    A2 = V0;

    get8byte;
    A3 = V0;

    A0 = S2;
    A1 = S3 & ff;
    A2 = S5 & ff;
    A3 = A3 & ff;
    funcc1368;

    return 0;
}
break;

case 5b: // BC0A0480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    A1 = V0;

    A0 = S2;
    funcc142c;

    return 0;
}
break;

case 61: // 44160480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get16byte;
    A1 = V0;

    A0 = S2;
    funcc17f0;

    return 0;
}
break;

case 62: // DC530480
{
    [8007b6f8] = w(1);

    get8byte;
    A3 = V0;

    if (A3 >= 9)
    {
        A3 = A3 - 4;
    }

    S2 = A3;
    if (S2 < 9)
    {
        get8byte;
        A2 = V0;

        V1 = w[8006794c];
        A0 = w[V1 + 1c];
        [A0 + 3c + S2 * 90 + 34] = w((w[A0 + 3c + S2 * 90 + 34] & fffffdff) | ((A2 & 1) << 9));
    }
    return 0;
}
break;

case 65: // 4C190480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    get8byte;
    A2 = V0;

    A0 = S2;
    A1 = S3;
    funcc18d4;

    return 0;
}
break;

case 66: // 28B70380
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get16byte;
    A1 = V0;

    A0 = S2;
    func4ec74;

    return 0;
}
break;

case 67: // A0FE0380
{
    [8007b6f8] = w(1);

    get8byte;
    A0 = w[8007aecc];
    [A0 + 16e8] = h(V0 * 10);

    get8byte;
    A0 = w[8007aecc];
    [A0 + 16ea] = h(V0 * 10);

    return 0;
}
break;

case 68: // 502E0480
{
    [8007b6f8] = w(1);

    get8byte;

    [8007bbec] = w(1);
    [8007bbf4] = w(V0);

    return 0;
}
break;

case 6a: // 54A60380
{
    A0 = w[8007aecc];
    [A0 + 16f8] = b(1);
    return 0;
}
break;

case 6f: // 68020480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    get8byte;
    A2 = V0;

    get8byte;
    A3 = V0;

    A0 = (S2 << 10) >> 10;
    A1 = (S3 << 10) >> 10;
    A2 = S5 & ffff;
    [8007b6f4] = w(w[8007b6f4] >> 1)

    funcc0df4;

    return 0;
}
break;

case 75: // 58400480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    A1 = V0;

    A0 = S2;

    func32140;

    80044128	jal    func4a9e8 [$8004a9e8]

    return 1;
}
break;

case 7a: // 50ED0380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 4c] = h(V0);

    return 0;
}
break;

case 7b: // D8ED0380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 4e] = h(V0);

    return 0;
}
break;

case 7e: // B0280480
{
    [8007b6f8] = w(1);

    get8byte;
    A0 = V0;

    funcc0bcc;

    return 0;
}
break;

case 86: // A0F10380
{
    [8007b6f8] = w(1);

    get8byte;
    [S4 + 7c] = b(V0);

    get8byte;
    [S4 + 7d] = b(V0);

    get8byte;
    [S4 + 7e] = b(V0);

    get8byte;
    [S4 + 7f] = b(V0);

    return 0;
}
break;

case 88: // B82A0480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    get16byte;
    S5 = V0;

    get16byte;
    T0 = V0;

    A0 = bu[S4 + 3b];
    A1 = S2;
    A2 = S3;
    A3 = S5;
    A4 = T0;
    funcaba98; // we prepare packets deep in this function

    return 0;
}

case 8b: // 4CB10380
{
    [8007b6f8] = w(1);

    get8byte;
    [S4 + 6a] = b(V0);

    get8byte;
    [S4 + 6b] = b(V0);

    [S4 + 50] = h(hu[S4 + 50] | 0003);

    return 0;
}
break;

case 8e: // 80C30380
{
    func4ed3c;

    return 0;
}
break;

case 8f: // 50290480
{
    system_get_entity_script_data_pointer_from_script;
    S1 = V0;

    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    get8byte;

    A0 = bu[S1 + 3b];
    A1 = S2;
    A2 = S3;
    A3 = V0;
    funcb2cc0;

    if (V0 != 0)
    {
        A0 = w[8007b70c];
        [A0 + 0] = w(w[8007aea0]);
        return 1;
    }

    return 0;
}
break;

case 90: // AC2F0480
{
    A0 = w[8007aecc];
    [A0 + 1700] = h(-1);
    return 0;
}
break;

case 92: // B8100480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    get8byte;
    S5 = V0;

    get8byte;
    S4 = V0;

    get8byte;
    S1 = V0;

    get8byte;
    S0 = V0;

    get8byte;
    T1 = V0;

    A0 = S2;
    A1 = (S3 << 10) >> 10;
    A2 = (S5 << 10) >> 10;
    A3 = (S4 << 18) >> 18;
    A4 = S1;
    A5 = S0;
    A6 = T1;
    funcc02d0;

    return 0;
}
break;

case 93: // B0A50380
{
    [8007b6f8] = w(1);

    get8byte;

    V1 = w[8007b704];
    [V1 + f] = b(bu[V1 + f] & c0);
    [V1 + f] = b(bu[V1 + f] | (V0 & 3f));

    return 0;
}
break;

case 94: // F0EE0380
{
    [8007b6f8] = w(1);

    get16byte;
    [S4 + 76] = h(V0);

    get8byte;
    [S4 + 90] = b(V0);

    get8byte;
    [S4 + 91] = b(V0);

    return 0;
}
break;

case 9a: // 381C0480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get8byte;
    A1 = V0;

    A0 = S2;
    funcc778c;

    return 0;
}
break;

case 9c: // 9CCB0380
{
    [S0 + 62] = b(08);
    [S0 + 60] = b(00);

    S1 = hu[S0 + 76];

    V0 = bu[S0 + 90];
    V0 = V0 - 1;
    [S0 + 61] = b(V0);

    [S0 + 36] = h(S1);
    [S0 + 3a] = b(bu[S0 + 60]);

    V0 = bu[S0 + 62] & b9;

    if (bu[S0 + 61] < bu[S0 + 60])
    {
        V0 = V0 | c0;
    }
    else
    {
        V0 = V0 | 80;
    }
    [S0 + 62] = b(V0);

    [S0 + 64] = b(0);

    A0 = hu[S0 + 34];
    A1 = S1;
    system_get_number_of_frames_in_animation;
    [S0 + 38] = b(V0);

    [S0 + 5d] = b(bu[S0 + 69]);

    V0 = w[8007aecc];
    if (bu[S0 + 7] == bu[V0 + 16ed])
    {
        [8007b710] = w(w[8007b710] + 1);
    }

    return 0;
}
break;

case 9d: // 6CCC0380
{
    A0 = hu[S0 + 3b];
    func1e350;
    [V0] = w(w[V0] & ffffffef);

    [S0 + 61] = b(ff);
    [S0 + 62] = b(0);

    S1 = ;

    V0 = bu[S0 + 91];
    V0 = V0 + 1;
    [S0 + 60] = b(V0);

    V1 = bu[S0 + 62];
    if (V1 & 80)
    {
        V0 = bu[S0 + f];
        if (V0 & 80)
        {
            A0 = S0;
            func4b9b8;
        }
    }

    [S0 + 36] = h(hu[S0 + 76]);
    [S0 + 3a] = b(bu[S0 + 60]);

    V0 = bu[S0 + 62] & b9;

    if (bu[S0 + 61] < bu[S0 + 60])
    {
        V0 = V0 | c0;
    }
    else
    {
        V0 = V0 | 80;
    }
    [S0 + 62] = b(V0);

    [S0 + 64] = b(0);

    A0 = hu[S0 + 34];
    A1 = hu[S0 + 76];
    system_get_number_of_frames_in_animation;
    [S0 + 38] = b(V0);

    [S0 + 5d] = b(bu[S0 + 69]);

    V0 = w[8007aecc];
    if (bu[S0 + 7] == bu[V0 + 16ed])
    {
        [8007b710] = w(w[8007b710] + 1);
    }

    return 0;
}
break;

case 9f: // 30E50380
{
    system_get_entity_script_data_pointer_from_script;
    S4 = V0;

    S0 = 0;

    if ((S4 != 0) && (hu[S4 + 34] != ff))
    {
        A0 = bu[S4 + 3b];
        func1e350;

        if (V0 != 0)
        {
            S0 = w[V0 + 8];
        }
    }

    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    get8byte;
    S5 = V0;

    if (S0 != 0)
    {
        [S0 + 54] = h((S2 << 18) >> 12);
        [S0 + 56] = h((S3 << 18) >> 12);
        [S0 + 58] = h((S5 << 18) >> 12);
        [S0 + 0] = h(hu[S0 + 0] | 0002);
    }

    [S4 + 2f] = b(S3);

    return 0;
}
break;

case ad: // F8AD0380
{
    system_get_entity_script_data_pointer_from_script;
    S4 = V0;
case a1: // 04AE0380
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    get16byte;
    S5 = V0;

    S1 = 0;

    if (w[8007b708] == 1) // if this is field
    {
        S1 = (hu[S4 + 34] XOR ffff) != 0;
    }

    if (S1 != 0)
    {
        A0 = bu[S4 + 3b];
        A1 = 0;
        funcc3e18;
    }

    [S4 + 40] = w(S2); [S4 + 14] = w(S2); // X
    [S4 + 44] = w(S3); [S4 + 18] = w(S3); // Y
    [S4 + 48] = w(S5); [S4 + 1c] = w(S5); // Z

    if (bu[S4 + 5] == 4)
    {
        [S4 + 30] = h(0);
        [S4 + 50] = h(hu[S4 + 50] & ffcf);
        [S4 + 78] = w(7fffffff);
    }

    return 0;
}
break;

case a8: // 041E0480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    if (hu[S4 + 34] != ffff)
    {
        A0 = bu[S4 + 3b];
        A1 = S2;
        funcc3e18;
    }

    return 0;
}
break;

case a9: // 6C5A0480
{
    system_get_entity_script_data_pointer_from_script;
    if (V0 != 0)
    {
        [SP + 20] = h(hu[V0 + 14]); // X
        [SP + 22] = h(hu[V0 + 18]); // Y
        [SP + 24] = h(hu[V0 + 1c]); // Z

        A0 = SP + 20;
        A1 = 8007ae2c; // store screen X here
        A2 = 8007ae30; // store screen Y here
        system_get_screen_coords_by_vector;
    }

    return 0;
}
break;

case aa: // D8410480
{
    [80073998] = w(w[80073998] & fffbffff);

    return 0;
}
break;

case ab: // F8410480
{
    [80073998] = w(w[80073998] | 00040000);

    return 1;
}
break;

case b3: // 443C0480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    get16byte;
    S5 = V0;

    get16byte;
    S1 = V0;

    get16byte;
    T2 = V0;

    A0 = S2;
    A1 = S3;
    A2 = S5;
    A3 = S1;
    A4 = T2;
    funcafac0;

    return V0;
}
break;

case b4: // 08460480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    S2 = S2 | ((S2 >> 4) & e0);

    S0 = 0;
    loop446a0:	; 800446A0
        A0 = S0;
        800446A0	jal    func33c0c [$80033c0c]

        S0 = S0 + 1;
        V0 = S0 < 9;
    800446B0	bne    v0, zero, loop446a0 [$800446a0]

    S0 = 0;
    loop446bc:	; 800446BC
        if (S2 & 1)
        {
            A0 = S0;
            800446C8	jal    func33bd0 [$80033bd0]
        }

        S0 = S0 + 1;
        V0 = S0 < 9;
        S2 = S2 >> 1;
    800446D8	bne    v0, zero, loop446bc [$800446bc]

    return 0;
}
break;

case c5: // EC310480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;

    A0 = S2;
    A1 = V0;
    A2 = 0;
    A3 = 0;
    A4 = 0;

    V0 = w[8006794c];
    T1 = w[V0 + 1c];
    V0 = w[T1 + 83c];
    8004390C	jalr   v0 ra

    return 0;
}
break;

case c6: // 04330480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    get24byte;
    A2 = V0;

    A0 = S2;
    A1 = S3;
    A3 = 0;
    A4 = 0;

    V0 = w[8006794c];
    T1 = w[V0 + 1c];
    V0 = w[T1 + 83c];
    8004390C	jalr   v0 ra

    return 0;
}
break;

case c7: // A4340480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    get24byte;
    S5 = V0;

    get8byte;
    A3 = V0;

    A0 = S2;
    A1 = S3;
    A2 = S5;
    A4 = 0;

    V0 = w[8006794c];
    T1 = w[V0 + 1c];
    V0 = w[T1 + 83c];
    8004390C	jalr   v0 ra

    return 0;
}
break;

case c8: // A4360480
{
    [8007b6f8] = w(1);

    get16byte;
    S2 = V0;

    get16byte;
    S3 = V0;

    get24byte;
    S5 = V0;

    get8byte;
    S1 = V0;

    get8byte;
    T0 = V0;

    A0 = S2;
    A1 = S3;
    A2 = S5;
    A3 = S1;
    A4 = T0;

    V0 = w[8006794c];
    T1 = w[V0 + 1c];
    V0 = w[T1 + 83c];
    8004390C	jalr   v0 ra

    return 0;
}
break;

case ca: // 881A0480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    A1 = V0;

    A0 = S2;
    funcc196c;

    return 0;
}
break;

case cb: // 2C1D0480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    A1 = V0;

    A0 = S2;
    funcc47e4;

    return 0;
}
break;

case ce: // 7C440480
{
    [8007b6f8] = w(1);

    get24byte;
    A2 = V0;

    A3 = w[8006794c];
    A1 = w[A3 + 1c];
    [A1 + 560] = w(w[A1 + 560] + A2);

    if (w[A1 + 560] > 0098967f)
    {
        [A1 + 560] = w(0098967f);
    }

    retunr 0;
}
break;

case d7: // C42E0480
{
    [8007b6f8] = w(1);

    get8byte;

    if (w[8007bc10] != V0)
    {
        [8007bc10] = w(V0);
        [8007bc14] = w(2c);
    }

    return 0;
}
break;

case d9: // D4520480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    if (S2 >= 9)
    {
        S2 = S2 - 4;
    }

    get8byte;
    A1 = V0;

    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    A0 = V0 + 3c + S2 * 90;
    func53960;

    return 0;
}
break;

case da: // 183E0480 
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    get8byte;
    A2 = V0;

    get16byte;
    A3 = V0;

    get16byte;

    A0 = S2;
    A1 = S3;
    A2 = S5;
    A3 = S1;
    A4 = V0;
    funcafac0;

    return V0;
}
break;

case dc: // C0D00380
{
    // increment total jump steps
    A2 = bu[S0 + 68];
    A2 = A2 + 1;
    A2 = A2 & ff;
    [S0 + 68] = b(A2);

    step    = A2;
    steps   = bu[S0 + 92];
    start_x = h[S0 + a4];
    start_y = h[S0 + a6];
    start_z = h[S0 + a8];
    dest_x  = h[S0 + 94];
    dest_z  = h[S0 + 96];

    [S0 + 14] = w(start_x + (step / steps) * (dest_x - start_x));
    [S0 + 18] = w(start_y + step * step * 8 + ((step * (h[S0 + aa] - start_y)) / steps) - step * steps * 8);
    [S0 + 1c] = w(start_z + (step / steps) * (dest_z - start_z));

    if (step < steps)
    {
        [8007b6f8] = w(1);

        A2 = w[8007b70c];
        [A2] = w(w[8007aea0]);

        return 1;
    }

    return 0;
}
break;

case dd: // 184A0480
{
    V0 = w[8006794c];
    pointer = w[V0 + 1c];
    script = w[8007aecc];

    [8007b6f8] = w(1);

    get8byte;
    A3 = V0;

    if (A3 >= 9)
    {
        A3 = A3 - 4;
    }

    S0 = 0;
    loop44aa8:	; 80044AA8
        V0 = w[pointer + 54c + S0 * 4];
        if (V0 != 0)
        {
            if ((w[V0 + 34] & f) == A3)
            {
                break;
            }
        }
        S0 = S0 + 1;
        V0 = S0 < 4;
    80044AD8	bne    v0, zero, loop44aa8 [$80044aa8]

    if (S0 < 4)
    {
        A0 = S0; // party slot
        A1 = -1; // character id
        func33af4;

        [script + 16e4] = w(-1); // remove all party members

        S1 = 0;
        S0 = 0;
        loop44b1c:	; 80044B1C
            V0 = w[pointer + 54c + S0 * 4];
            if (V0 != 0)
            {
                V0 = w[V0 + 34] & f;
                S1 = S1 | (1 << bu[8006e63c + V0]);
            }

            S0 = S0 + 1;
            V0 = S0 < 4;
        80044B44	bne    v0, zero, loop44b1c [$80044b1c]

        if (S1 != 0)
        {
            S0 = 0;
            S2 = 0;
            loop44b60:	; 80044B60
                if (S1 & 1)
                {
                    [script + 16e4 + S2] = b(bu[8006e630 + S0] + bu[8007adfc] - 9);
                    S2 = S2 + 1;
                }
                S1 = S1 >> 1;
                S0 = S0 + 1;
            80044B88	bne    s1, zero, loop44b60 [$80044b60]
        }
    }

    return 0;
}
break;

case de: // CCFB0380
{
    [8007b6f8] = w(1);

    get8byte;
    character_id = V0;

    if (character_id >= 9)
    {
        character_id = character_id - 4;
    }

    if (character_id < 9)
    {
        get16byte;
        A0 = V0;

        func4f058; // get pointer to character name
        A1 = V0;

        V1 = w[8006794c];
        V1 = w[V1 + 1c];
        data = V1 + 3c + character_id * 90;
        V1 = 0;
        loop3fd04:	; 8003FD04
            [data + V1] = b(bu[A1 + V1]);
            V1 = V1 + 1;
            V0 = V1 < 9;
        8003FD18	bne    v0, zero, loop3fd04 [$8003fd04]

        [data + 9] = b(ff);
    }
    else
    {
        get16byte;
    }

    return 0;
}
break;

case e2: // 58CD0380
{
    [8007b6f8] = w(1);

    // read X value
    get16byte;
    [S0 + 94] = h(V0);

    // read Y value
    get16byte;
    [S0 + aa] = h(V0);

    // read Z value
    get16byte;
    [S0 + 96] = h(V0);

    // read steps value
    get8byte;
    S2 = V0;
    if (S2 == 0)
    {
        S2 = 8;
    }

    [S0 + 50] = h(hu[S0 + 50] | 8);

    A0 = bu[S0 + 3b];
    func1e350;
    V1 = w[V0];
    V1 = V1 | 10;
    [V0] = w(V1);



    [S0 + 60] = b(bu[S0 + 90]);
    [S0 + 61] = b(bu[S0 + 91]);



    V0 = bu[S0 + 62];
    if (V0 & 80)
    {
        V0 = bu[S0 + f];
        if (V0 & 80)
        {
            A0 = S0;
            func4b9b8;
        }
    }

    [S0 + 36] = h(hu[S0 + 76]);
    [S0 + 3a] = b(bu[S0 + 60]);

    V0 = bu[S0 + 62] & b9;
    if (bu[S0 + 61] < bu[S0 + 60])
    {
        V0 = V0 | c0;
    }
    else
    {
        V0 = V0 | 80;
    }
    [S0 + 62] = b(V0);

    [S0 + 64] = b(0);

    A0 = hu[S0 + 34];
    A1 = hu[S0 + 76];
    system_get_number_of_frames_in_animation;
    [S0 + 38] = b(V0);

    [S0 + 5d] = b(bu[S0 + 69]);

    V0 = w[8007aecc];
    if (bu[S0 + 7] == bu[V0 + 16ed])
    {
        [8007b710] = w(w[8007b710] + 1);
    }

    [S0 + 68] = b(0); // current step
    [S0 + 92] = b(S2); // total steps

    // start values of position
    [S0 + a4] = h(hu[S0 + 14]);
    [S0 + a6] = h(hu[S0 + 18]);
    [S0 + a8] = h(hu[S0 + 1c]);

    [S0 + 5d] = b(((bu[S0 + 61] - bu[S0 + 60]) * 10) / S2);

    if (w[8007b708] == 1 && hu[S4 + 34] != ffff)
    {
        A0 = bu[S4 + 3b];
        A1 = 0;
        funcc3e18;
    }

    return 0;
}

case e3: // 1CB80380
{
    [8007b6f8] = w(1);

    get8byte;
    [8007bbd8] = w(V0);

    return 0;
}
break;

case ec: // B8570480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    A0 = S2 & 1;
    func2f8bc;

    get8byte;
    [80077c82] = h(((80 - V0) << 4) & fff0);

    get8byte;
    S5 = V0;

    get8byte;
    S1 = V0;

    A0 = 1;
    func2f8e4;

    get8byte;
    T0 = V0;

    A0 = S2 >> 2;
    A0 = A0 & 1;
    A0 = A0 + 1;
    A1 = S2 >> 1;
    A1 = A1 & 1;
    A2 = S3;
    A3 = S5 | (S1 << 8) | (T0 << 10);
    func320b8;

    return 0;
}
break;

case ef: // 382F0480
{
    [8007b6f8] = w(1);

    get8byte;
    A0 = V0;

    func4ff98;

    return 0;
}
break;

case f1: // 8C4E0480
{
    [8007b6f8] = w(1);

    get8byte;
    character_id = V0;

    if (character_id >= 9)
    {
        character_id = character_id - 4;
    }

    if (character_id < 9)
    {
        get16byte;
        hp = V0;

        V1 = w[8006794c];
        V1 = w[V1 + 1c];
        max_hp = hu[V1 + 3c + character_id * 90 + 18];

        if (hp > max_hp)
        {
            hp = max_hp;
        }

        [V1 + 3c + character_id * 90 + 10] = h(hp);
    }
    return 0;
}
break;

case f2: // C84F0480
{
    [8007b6f8] = w(1);

    get8byte;
    character_id = V0;

    if (character_id >= 9)
    {
        character_id = character_id - 4;
    }

    if (character_id < 9)
    {
        get16byte;
        mp = V0;


        V1 = w[8006794c];
        V1 = w[V1 + 1c];
        max_mp = hu[V1 + 3c + character_id * 90 + 1a];


        if (mp > max_mp)
        {
            mp = max_mp;
        }

        [V1 + 3c + character_id * 90 + 12] = h(mp);
    }

    return 0;
}
break;

case f7: // 1C5E0480
{
    [8007b6f8] = w(1);

    get8byte;
    A0 = V0;

    func54fe0;

    return 0;
}
break;

case f8: // 905E0480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get8byte;
    S3 = V0;

    get8byte;
    A2 = V0;

    A0 = S2;
    A1 = S3;
    func54e88;

    return 0;
}
break;

case fd: // EC620480
{
    [8007b6f8] = w(1);

    get8byte;
    S2 = V0;

    get16byte;
    A1 = V0;

    A0 = S2 & ff;

    V0 = w[8006794c];
    T1 = w[V0 + 1c];
    V0 = w[T1 + 8bc];
    800463E4	jalr   v0 ra

    return 0;
}
break;

case fe: // E8460480
{
    [8007b6f8] = w(1);

    get8byte;
    A3 = V0;

    if (A3 >= 9)
    {
        A3 = A3 - 4;
    }

    S2 = A3;

    get8byte;
    S3 = V0;

    get8byte;
    S5 = V0;

    if (S2 < 9)
    {
        V1 = w[8006794c];
        V1 = w[V1 + 1c];
        S0 = V1 + 3c + S2 * 90;

        get8byte;
        if (V0 != ff)
        {
            [S0 + a] = b(V0);
        }

        get8byte;
        S1 = V0;

        if (S1 != ff)
        {
            [S0 + 34] = w((w[S0 + 34] & fffe0fff) | ((S1 & 1f) << c));
        }

        A0 = S2;
        A1 = S3;
        A2 = S5;
        func333b0; // set initial stats and equip for character
    }
    else
    {
        get8byte;
        get8byte;
    }

    return 0;
}
break;


L39ea8:	; 80039EA8
80039EA8	j      L475b4 [$800475b4]
80039EAC	addu   v0, zero, zero

80039F28	lui    v0, $8008
80039F2C	lw     v0, $b6f4(v0)
80039F30	nop
80039F34	andi   v0, v0, $0001
80039F38	beq    v0, zero, L39f58 [$80039f58]
80039F3C	lui    v0, $8008
80039F40	jal    func52da0 [$80052da0]
80039F44	nop
80039F48	jal    system_read_from_stack_command_not_from_script [$80052d40]
80039F4C	nop
80039F50	j      L39f74 [$80039f74]
80039F54	addu   a0, v0, zero

L39f58:	; 80039F58
80039F58	lw     v1, $b70c(v0)
80039F5C	nop
80039F60	lw     v0, $0000(v1)
80039F64	nop
80039F68	lbu    a0, $0000(v0)
80039F6C	addiu  v0, v0, $0001
80039F70	sw     v0, $0000(v1)

L39f74:	; 80039F74
80039F74	addu   s2, a0, zero
80039F78	lui    a1, $8008
80039F7C	lui    a0, $8008
80039F80	lw     v0, $b6f4(a1)
80039F84	addiu  v1, zero, $0001
80039F88	sw     v1, $b6f8(a0)
80039F8C	srav   v0, v1, v0
80039F90	jal    system_get_entity_script_data_pointer_from_script [$80038150]
80039F94	sw     v0, $b6f4(a1)
80039F98	lui    v1, $8008
80039F9C	lw     a0, $b70c(v1)
80039FA0	nop
80039FA4	lw     v1, $0000(a0)
80039FA8	addu   s1, v0, zero
80039FAC	lbu    s5, $0000(v1)
80039FB0	addiu  v1, v1, $0001
80039FB4	beq    s1, zero, L3f730 [$8003f730]
80039FB8	sw     v1, $0000(a0)
80039FBC	lbu    v0, $0004(s1)
80039FC0	nop
80039FC4	slt    v0, s2, v0
80039FC8	beq    v0, zero, L3f730 [$8003f730]
80039FCC	addu   a0, s1, zero
80039FD0	addu   a1, s2, zero
80039FD4	addu   a2, s5, zero
80039FD8	j      L3a36c [$8003a36c]
80039FDC	addu   a3, zero, zero

8003A0A0	lui    v0, $8008
8003A0A4	lw     v0, $b6f4(v0)
8003A0A8	nop
8003A0AC	andi   v0, v0, $0001
8003A0B0	beq    v0, zero, L3a0d0 [$8003a0d0]
8003A0B4	lui    v0, $8008
8003A0B8	jal    func52da0 [$80052da0]
8003A0BC	nop
8003A0C0	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003A0C4	nop
8003A0C8	j      L3a0ec [$8003a0ec]
8003A0CC	addu   a0, v0, zero

L3a0d0:	; 8003A0D0
8003A0D0	lw     v1, $b70c(v0)
8003A0D4	nop
8003A0D8	lw     v0, $0000(v1)
8003A0DC	nop
8003A0E0	lbu    a0, $0000(v0)
8003A0E4	addiu  v0, v0, $0001
8003A0E8	sw     v0, $0000(v1)

L3a0ec:	; 8003A0EC
8003A0EC	addu   s2, a0, zero
8003A0F0	lui    a0, $8008
8003A0F4	lui    v0, $8008
8003A0F8	lw     v1, $aecc(v0)
8003A0FC	addiu  v0, zero, $0001
8003A100	lui    a1, $8008
8003A104	sw     v0, $b6f8(a0)
8003A108	lw     v0, $b6f4(a1)
8003A10C	lw     a2, $16d8(v1)
8003A110	lui    v1, $8008
8003A114	lw     a0, $b70c(v1)
8003A118	sra    v0, v0, $01
8003A11C	sw     v0, $b6f4(a1)
8003A120	lbu    v1, $000a(a0)
8003A124	lbu    v0, $0009(a0)
8003A128	sll    v1, v1, $02
8003A12C	sll    v0, v0, $02
8003A130	addu   v0, v0, a0
8003A134	addu   v1, v1, v0
8003A138	lbu    v1, $ffff(v1)
8003A13C	beq    a2, zero, L3a16c [$8003a16c]
8003A140	nop

loop3a144:	; 8003A144
8003A144	lw     v0, $0004(a2)
8003A148	nop
8003A14C	lbu    v0, $0007(v0)
8003A150	nop
8003A154	beq    v0, v1, L3a16c [$8003a16c]
8003A158	nop
8003A15C	lw     a2, $0000(a2)
8003A160	nop
8003A164	bne    a2, zero, loop3a144 [$8003a144]
8003A168	nop

L3a16c:	; 8003A16C
8003A16C	beq    a2, zero, L3a34c [$8003a34c]
8003A170	addu   a0, zero, zero
8003A174	lw     a0, $0004(a2)
8003A178	j      L3a350 [$8003a350]
8003A17C	lui    v0, $8008
8003A180	lui    v0, $8008
8003A184	lw     v0, $b6f4(v0)
8003A188	nop
8003A18C	andi   v0, v0, $0001
8003A190	beq    v0, zero, L3a1b0 [$8003a1b0]
8003A194	lui    v0, $8008
8003A198	jal    func52da0 [$80052da0]
8003A19C	nop
8003A1A0	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003A1A4	nop
8003A1A8	j      L3a1cc [$8003a1cc]
8003A1AC	addu   a0, v0, zero

L3a1b0:	; 8003A1B0
8003A1B0	lw     v1, $b70c(v0)
8003A1B4	nop
8003A1B8	lw     v0, $0000(v1)
8003A1BC	nop
8003A1C0	lbu    a0, $0000(v0)
8003A1C4	addiu  v0, v0, $0001
8003A1C8	sw     v0, $0000(v1)

L3a1cc:	; 8003A1CC
8003A1CC	addu   s2, a0, zero
8003A1D0	lui    a0, $8008
8003A1D4	lui    v0, $8008
8003A1D8	lw     v1, $aecc(v0)
8003A1DC	addiu  v0, zero, $0001
8003A1E0	lui    a1, $8008
8003A1E4	sw     v0, $b6f8(a0)
8003A1E8	lw     v0, $b6f4(a1)
8003A1EC	lw     a2, $16d8(v1)
8003A1F0	lui    v1, $8008
8003A1F4	lw     a0, $b70c(v1)
8003A1F8	sra    v0, v0, $01
8003A1FC	sw     v0, $b6f4(a1)
8003A200	lbu    v1, $000a(a0)
8003A204	lbu    v0, $0009(a0)
8003A208	sll    v1, v1, $02
8003A20C	sll    v0, v0, $02
8003A210	addu   v0, v0, a0
8003A214	addu   v1, v1, v0
8003A218	lbu    v1, $ffff(v1)
8003A21C	beq    a2, zero, L3a24c [$8003a24c]
8003A220	nop

loop3a224:	; 8003A224
8003A224	lw     v0, $0004(a2)
8003A228	nop
8003A22C	lbu    v0, $0007(v0)
8003A230	nop
8003A234	beq    v0, v1, L3a24c [$8003a24c]
8003A238	nop
8003A23C	lw     a2, $0000(a2)
8003A240	nop
8003A244	bne    a2, zero, loop3a224 [$8003a224]
8003A248	nop

L3a24c:	; 8003A24C
8003A24C	beq    a2, zero, L3a258 [$8003a258]
8003A250	addu   v0, zero, zero
8003A254	lw     v0, $0004(a2)

L3a258:	; 8003A258
8003A258	nop
8003A25C	beq    v0, zero, L3f730 [$8003f730]
8003A260	lui    v1, $8008
8003A264	lui    v0, $8008
8003A268	lw     v0, $aecc(v0)
8003A26C	lw     a0, $b70c(v1)
8003A270	lw     a1, $16d8(v0)
8003A274	lbu    v1, $000a(a0)
8003A278	lbu    v0, $0009(a0)
8003A27C	sll    v1, v1, $02
8003A280	sll    v0, v0, $02
8003A284	addu   v0, v0, a0
8003A288	addu   v1, v1, v0
8003A28C	lbu    v1, $ffff(v1)
8003A290	beq    a1, zero, L3a2c0 [$8003a2c0]
8003A294	nop

loop3a298:	; 8003A298
8003A298	lw     v0, $0004(a1)
8003A29C	nop
8003A2A0	lbu    v0, $0007(v0)
8003A2A4	nop
8003A2A8	beq    v0, v1, L3a2c0 [$8003a2c0]
8003A2AC	nop
8003A2B0	lw     a1, $0000(a1)
8003A2B4	nop
8003A2B8	bne    a1, zero, loop3a298 [$8003a298]
8003A2BC	nop

L3a2c0:	; 8003A2C0
8003A2C0	beq    a1, zero, L3a2cc [$8003a2cc]
8003A2C4	addu   v0, zero, zero
8003A2C8	lw     v0, $0004(a1)

L3a2cc:	; 8003A2CC
8003A2CC	nop
8003A2D0	lbu    v0, $0004(v0)
8003A2D4	nop
8003A2D8	slt    v0, s2, v0
8003A2DC	beq    v0, zero, L3f730 [$8003f730]
8003A2E0	lui    v1, $8008
8003A2E4	lui    v0, $8008
8003A2E8	lw     v0, $aecc(v0)
8003A2EC	lw     a0, $b70c(v1)
8003A2F0	lw     a1, $16d8(v0)
8003A2F4	lbu    v1, $000a(a0)
8003A2F8	lbu    v0, $0009(a0)
8003A2FC	sll    v1, v1, $02
8003A300	sll    v0, v0, $02
8003A304	addu   v0, v0, a0
8003A308	addu   v1, v1, v0
8003A30C	lbu    v1, $ffff(v1)
8003A310	beq    a1, zero, L3a340 [$8003a340]
8003A314	nop

loop3a318:	; 8003A318
8003A318	lw     v0, $0004(a1)
8003A31C	nop
8003A320	lbu    v0, $0007(v0)
8003A324	nop
8003A328	beq    v0, v1, L3a340 [$8003a340]
8003A32C	nop
8003A330	lw     a1, $0000(a1)
8003A334	nop
8003A338	bne    a1, zero, loop3a318 [$8003a318]
8003A33C	nop

L3a340:	; 8003A340
8003A340	beq    a1, zero, L3a34c [$8003a34c]
8003A344	addu   a0, zero, zero
8003A348	lw     a0, $0004(a1)

L3a34c:	; 8003A34C
8003A34C	lui    v0, $8008

L3a350:	; 8003A350
8003A350	lw     v1, $b70c(v0)
8003A354	addu   a1, s2, zero
8003A358	lw     v0, $0000(v1)
8003A35C	addu   a3, zero, zero
8003A360	lbu    a2, $0000(v0)
8003A364	addiu  v0, v0, $0001
8003A368	sw     v0, $0000(v1)

L3a36c:	; 8003A36C
8003A36C	jal    func384d0 [$800384d0]
8003A370	nop
8003A374	j      L475b4 [$800475b4]
8003A378	addu   v0, zero, zero
8003A37C	lui    v0, $8008
8003A380	lw     v0, $b6f4(v0)
8003A384	nop
8003A388	andi   v0, v0, $0001
8003A38C	beq    v0, zero, L3a3ac [$8003a3ac]
8003A390	lui    v0, $8008
8003A394	jal    func52da0 [$80052da0]
8003A398	nop
8003A39C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003A3A0	nop
8003A3A4	j      L3a3c8 [$8003a3c8]
8003A3A8	addu   a0, v0, zero

L3a3ac:	; 8003A3AC
8003A3AC	lw     v1, $b70c(v0)
8003A3B0	nop
8003A3B4	lw     v0, $0000(v1)
8003A3B8	nop
8003A3BC	lbu    a0, $0000(v0)
8003A3C0	addiu  v0, v0, $0001
8003A3C4	sw     v0, $0000(v1)

L3a3c8:	; 8003A3C8
8003A3C8	addu   s2, a0, zero
8003A3CC	lui    a0, $8008
8003A3D0	lui    v0, $8008
8003A3D4	lw     v1, $aecc(v0)
8003A3D8	addiu  v0, zero, $0001
8003A3DC	lui    a1, $8008
8003A3E0	sw     v0, $b6f8(a0)
8003A3E4	lw     v0, $b6f4(a1)
8003A3E8	lw     a2, $16d8(v1)
8003A3EC	lui    v1, $8008
8003A3F0	lw     a0, $b70c(v1)
8003A3F4	sra    v0, v0, $01
8003A3F8	sw     v0, $b6f4(a1)
8003A3FC	lbu    v1, $000a(a0)
8003A400	lbu    v0, $0009(a0)
8003A404	sll    v1, v1, $02
8003A408	sll    v0, v0, $02
8003A40C	addu   v0, v0, a0
8003A410	addu   v1, v1, v0
8003A414	lbu    v1, $ffff(v1)
8003A418	beq    a2, zero, L3a448 [$8003a448]
8003A41C	nop

loop3a420:	; 8003A420
8003A420	lw     v0, $0004(a2)
8003A424	nop
8003A428	lbu    v0, $0007(v0)
8003A42C	nop
8003A430	beq    v0, v1, L3a448 [$8003a448]
8003A434	nop
8003A438	lw     a2, $0000(a2)
8003A43C	nop
8003A440	bne    a2, zero, loop3a420 [$8003a420]
8003A444	nop

L3a448:	; 8003A448
8003A448	beq    a2, zero, L3a454 [$8003a454]
8003A44C	addu   v0, zero, zero
8003A450	lw     v0, $0004(a2)

L3a454:	; 8003A454
8003A454	nop
8003A458	beq    v0, zero, L3c6f8 [$8003c6f8]
8003A45C	lui    v1, $8008
8003A460	lui    v0, $8008
8003A464	lw     v0, $aecc(v0)
8003A468	lw     a0, $b70c(v1)
8003A46C	lw     a1, $16d8(v0)
8003A470	lbu    v1, $000a(a0)
8003A474	lbu    v0, $0009(a0)
8003A478	sll    v1, v1, $02
8003A47C	sll    v0, v0, $02
8003A480	addu   v0, v0, a0
8003A484	addu   v1, v1, v0
8003A488	lbu    v1, $ffff(v1)
8003A48C	beq    a1, zero, L3a4bc [$8003a4bc]
8003A490	nop

loop3a494:	; 8003A494
8003A494	lw     v0, $0004(a1)
8003A498	nop
8003A49C	lbu    v0, $0007(v0)
8003A4A0	nop
8003A4A4	beq    v0, v1, L3a4bc [$8003a4bc]
8003A4A8	nop
8003A4AC	lw     a1, $0000(a1)
8003A4B0	nop
8003A4B4	bne    a1, zero, loop3a494 [$8003a494]
8003A4B8	nop

L3a4bc:	; 8003A4BC
8003A4BC	beq    a1, zero, L3a4c8 [$8003a4c8]
8003A4C0	addu   v0, zero, zero
8003A4C4	lw     v0, $0004(a1)

L3a4c8:	; 8003A4C8
8003A4C8	nop
8003A4CC	lbu    v0, $0004(v0)
8003A4D0	nop
8003A4D4	slt    v0, s2, v0
8003A4D8	beq    v0, zero, L3c6f8 [$8003c6f8]
8003A4DC	lui    v1, $8008
8003A4E0	lui    v0, $8008
8003A4E4	lw     v0, $aecc(v0)
8003A4E8	lw     a0, $b70c(v1)
8003A4EC	lw     a1, $16d8(v0)
8003A4F0	lbu    v1, $000a(a0)
8003A4F4	lbu    v0, $0009(a0)
8003A4F8	sll    v1, v1, $02
8003A4FC	sll    v0, v0, $02
8003A500	addu   v0, v0, a0
8003A504	addu   v1, v1, v0
8003A508	lbu    v1, $ffff(v1)
8003A50C	beq    a1, zero, L3a53c [$8003a53c]
8003A510	nop

loop3a514:	; 8003A514
8003A514	lw     v0, $0004(a1)
8003A518	nop
8003A51C	lbu    v0, $0007(v0)
8003A520	nop
8003A524	beq    v0, v1, L3a53c [$8003a53c]
8003A528	nop
8003A52C	lw     a1, $0000(a1)
8003A530	nop
8003A534	bne    a1, zero, loop3a514 [$8003a514]
8003A538	nop

L3a53c:	; 8003A53C
8003A53C	beq    a1, zero, L3a548 [$8003a548]
8003A540	addu   a0, zero, zero
8003A544	lw     a0, $0004(a1)

L3a548:	; 8003A548
8003A548	lui    v0, $8008
8003A54C	lw     v1, $b70c(v0)
8003A550	addu   a1, s2, zero
8003A554	lw     v0, $0000(v1)
8003A558	addiu  a3, zero, $0001
8003A55C	lbu    a2, $0000(v0)
8003A560	addu   v0, v0, a3
8003A564	jal    func384d0 [$800384d0]
8003A568	sw     v0, $0000(v1)
8003A56C	j      L475b4 [$800475b4]
8003A570	addiu  v0, zero, $0001
8003A574	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003A578	nop
8003A57C	addu   s1, v0, zero
8003A580	beq    s1, zero, L3a598 [$8003a598]
8003A584	addu   a0, s1, zero
8003A588	addiu  v0, zero, $0002
8003A58C	sb     zero, $000a(s1)
8003A590	jal    func38278 [$80038278]
8003A594	sb     v0, $000e(s1)

L3a598:	; 8003A598
8003A598	lui    v0, $8008
8003A59C	lw     v0, $b70c(v0)
8003A5A0	nop
8003A5A4	xor    v0, s1, v0
8003A5A8	j      L475b4 [$800475b4]
8003A5AC	sltiu  v0, v0, $0001

8003A66C	lui    v0, $8008
8003A670	lw     v1, $aecc(v0)
8003A674	addu   v0, zero, zero
8003A678	j      L475b4 [$800475b4]
8003A67C	sb     zero, $16f8(v1)
8003A680	lui    v0, $8008
8003A684	lw     v0, $aecc(v0)
8003A688	nop
8003A68C	lw     a1, $16d8(v0)
8003A690	nop
8003A694	beq    a1, zero, L39ea8 [$80039ea8]
8003A698	addiu  a2, zero, $0004

loop3a69c:	; 8003A69C
8003A69C	lw     v1, $0004(a1)
8003A6A0	nop
8003A6A4	lbu    v0, $0005(v1)
8003A6A8	nop
8003A6AC	bne    v0, a2, L3a6d4 [$8003a6d4]
8003A6B0	nop
8003A6B4	lbu    v0, $000f(v1)
8003A6B8	nop
8003A6BC	addu   a0, v0, zero
8003A6C0	sb     v0, $002c(v1)
8003A6C4	andi   v0, a0, $0020
8003A6C8	bne    v0, zero, L3a6d4 [$8003a6d4]
8003A6CC	andi   v0, a0, $00fe
8003A6D0	sb     v0, $000f(v1)

L3a6d4:	; 8003A6D4
8003A6D4	lw     a1, $0000(a1)
8003A6D8	nop
8003A6DC	bne    a1, zero, loop3a69c [$8003a69c]
8003A6E0	addu   v0, zero, zero
8003A6E4	j      L475b4 [$800475b4]
8003A6E8	nop
8003A6EC	lui    v0, $8008
8003A6F0	lw     v0, $aecc(v0)
8003A6F4	nop
8003A6F8	lw     a1, $16d8(v0)
8003A6FC	nop
8003A700	beq    a1, zero, L39ea8 [$80039ea8]
8003A704	addiu  a2, zero, $0004

loop3a708:	; 8003A708
8003A708	lw     a0, $0004(a1)
8003A70C	nop
8003A710	lbu    v0, $0005(a0)
8003A714	nop
8003A718	bne    v0, a2, L3a73c [$8003a73c]
8003A71C	nop
8003A720	lbu    v0, $000f(a0)
8003A724	lbu    v1, $002c(a0)
8003A728	andi   v0, v0, $00fe
8003A72C	andi   v1, v1, $0001
8003A730	sb     v0, $000f(a0)
8003A734	or     v0, v0, v1
8003A738	sb     v0, $000f(a0)

L3a73c:	; 8003A73C
8003A73C	lw     a1, $0000(a1)
8003A740	nop
8003A744	bne    a1, zero, loop3a708 [$8003a708]
8003A748	addu   v0, zero, zero
8003A74C	j      L475b4 [$800475b4]
8003A750	nop

8003A9EC	lui    v0, $8008
8003A9F0	lw     v0, $b6f4(v0)
8003A9F4	nop
8003A9F8	andi   v0, v0, $0001
8003A9FC	beq    v0, zero, L3aa1c [$8003aa1c]
8003AA00	lui    v0, $8008
8003AA04	jal    func52da0 [$80052da0]
8003AA08	nop
8003AA0C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003AA10	nop
8003AA14	j      L3aa38 [$8003aa38]
8003AA18	lui    a1, $8008

L3aa1c:	; 8003AA1C
8003AA1C	lw     v1, $b70c(v0)
8003AA20	nop
8003AA24	lw     v0, $0000(v1)
8003AA28	nop
8003AA2C	addiu  v0, v0, $0001
8003AA30	sw     v0, $0000(v1)
8003AA34	lui    a1, $8008

L3aa38:	; 8003AA38
8003AA38	lui    a0, $8008
8003AA3C	lw     v0, $b6f4(a1)
8003AA40	addiu  v1, zero, $0001
8003AA44	sw     v1, $b6f8(a0)
8003AA48	srav   v0, v1, v0
8003AA4C	sw     v0, $b6f4(a1)
8003AA50	and    v0, v0, v1
8003AA54	beq    v0, zero, L3aa74 [$8003aa74]
8003AA58	lui    v0, $8008
8003AA5C	jal    func52da0 [$80052da0]
8003AA60	nop
8003AA64	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003AA68	nop
8003AA6C	j      L3aa90 [$8003aa90]
8003AA70	lui    a1, $8008

L3aa74:	; 8003AA74
8003AA74	lw     v1, $b70c(v0)
8003AA78	nop
8003AA7C	lw     v0, $0000(v1)
8003AA80	nop
8003AA84	addiu  v0, v0, $0001
8003AA88	sw     v0, $0000(v1)
8003AA8C	lui    a1, $8008

L3aa90:	; 8003AA90
8003AA90	lui    a0, $8008
8003AA94	lw     v0, $b6f4(a1)
8003AA98	addiu  v1, zero, $0001
8003AA9C	sw     v1, $b6f8(a0)
8003AAA0	srav   v0, v1, v0
8003AAA4	sw     v0, $b6f4(a1)
8003AAA8	and    v0, v0, v1
8003AAAC	beq    v0, zero, L3aacc [$8003aacc]
8003AAB0	lui    v0, $8008
8003AAB4	jal    func52da0 [$80052da0]
8003AAB8	nop
8003AABC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003AAC0	nop
8003AAC4	j      L3aae8 [$8003aae8]
8003AAC8	lui    a1, $8008

L3aacc:	; 8003AACC
8003AACC	lw     v1, $b70c(v0)
8003AAD0	nop
8003AAD4	lw     v0, $0000(v1)
8003AAD8	nop
8003AADC	addiu  v0, v0, $0001
8003AAE0	sw     v0, $0000(v1)
8003AAE4	lui    a1, $8008

L3aae8:	; 8003AAE8
8003AAE8	lui    a0, $8008
8003AAEC	lw     v0, $b6f4(a1)
8003AAF0	addiu  v1, zero, $0001
8003AAF4	sw     v1, $b6f8(a0)
8003AAF8	srav   v0, v1, v0
8003AAFC	sw     v0, $b6f4(a1)
8003AB00	and    v0, v0, v1
8003AB04	beq    v0, zero, L3ab24 [$8003ab24]
8003AB08	lui    v0, $8008
8003AB0C	jal    func52da0 [$80052da0]
8003AB10	nop
8003AB14	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003AB18	nop
8003AB1C	j      L3ab40 [$8003ab40]
8003AB20	addu   v0, zero, zero

L3ab24:	; 8003AB24
8003AB24	lw     v1, $b70c(v0)
8003AB28	nop
8003AB2C	lw     v0, $0000(v1)
8003AB30	nop
8003AB34	addiu  v0, v0, $0001
8003AB38	sw     v0, $0000(v1)
8003AB3C	addu   v0, zero, zero

L3ab40:	; 8003AB40
8003AB40	lui    a2, $8008
8003AB44	lui    a1, $8008
8003AB48	lw     v1, $b6f4(a2)
8003AB4C	addiu  a0, zero, $0001
8003AB50	sw     a0, $b6f8(a1)
8003AB54	srav   v1, a0, v1
8003AB58	j      L475b4 [$800475b4]
8003AB5C	sw     v1, $b6f4(a2)
8003AB60	lui    v0, $8008
8003AB64	lw     v0, $b6f4(v0)
8003AB68	nop
8003AB6C	andi   v0, v0, $0001
8003AB70	beq    v0, zero, L3ab90 [$8003ab90]
8003AB74	lui    v0, $8008
8003AB78	jal    func52da0 [$80052da0]
8003AB7C	nop
8003AB80	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003AB84	nop
8003AB88	j      L3abac [$8003abac]
8003AB8C	addu   a3, v0, zero

L3ab90:	; 8003AB90
8003AB90	lw     v1, $b70c(v0)
8003AB94	nop
8003AB98	lw     v0, $0000(v1)
8003AB9C	nop
8003ABA0	lbu    a3, $0000(v0)
8003ABA4	addiu  v0, v0, $0001
8003ABA8	sw     v0, $0000(v1)

L3abac:	; 8003ABAC
8003ABAC	addu   v0, zero, zero
8003ABB0	lui    a2, $8008
8003ABB4	lui    a1, $8008
8003ABB8	lw     v1, $b6f4(a2)
8003ABBC	addiu  a0, zero, $0001
8003ABC0	sw     a0, $b6f8(a1)
8003ABC4	srav   v1, a0, v1
8003ABC8	sw     v1, $b6f4(a2)
8003ABCC	j      L475b4 [$800475b4]
8003ABD0	sb     a3, $002d(s4)
8003ABD4	lui    v0, $8008
8003ABD8	lw     v0, $b6f4(v0)
8003ABDC	nop
8003ABE0	andi   v0, v0, $0001
8003ABE4	beq    v0, zero, L3ac04 [$8003ac04]
8003ABE8	lui    v0, $8008
8003ABEC	jal    func52da0 [$80052da0]
8003ABF0	nop
8003ABF4	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003ABF8	nop
8003ABFC	j      L3ac20 [$8003ac20]
8003AC00	addu   a2, v0, zero

L3ac04:	; 8003AC04
8003AC04	lw     v1, $b70c(v0)
8003AC08	nop
8003AC0C	lw     v0, $0000(v1)
8003AC10	nop
8003AC14	lbu    a2, $0000(v0)
8003AC18	addiu  v0, v0, $0001
8003AC1C	sw     v0, $0000(v1)

L3ac20:	; 8003AC20
8003AC20	addu   v0, zero, zero
8003AC24	lui    a0, $8008
8003AC28	addiu  v1, zero, $0001
8003AC2C	lui    a1, $8008
8003AC30	sw     v1, $b6f8(a0)
8003AC34	lui    a0, $8008
8003AC38	lw     v1, $b6f4(a1)
8003AC3C	lw     a0, $b70c(a0)
8003AC40	sra    v1, v1, $01
8003AC44	sw     v1, $b6f4(a1)
8003AC48	j      L475b4 [$800475b4]
8003AC4C	sb     a2, $0011(a0)

8003B078	lui    v0, $8008
8003B07C	lw     v0, $b6f4(v0)
8003B080	nop
8003B084	andi   v0, v0, $0001
8003B088	beq    v0, zero, L3b0a8 [$8003b0a8]
8003B08C	lui    v0, $8008
8003B090	jal    func52da0 [$80052da0]
8003B094	nop
8003B098	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B09C	nop
8003B0A0	j      L3b0c4 [$8003b0c4]
8003B0A4	addu   a1, v0, zero

L3b0a8:	; 8003B0A8
8003B0A8	lw     v1, $b70c(v0)
8003B0AC	nop
8003B0B0	lw     v0, $0000(v1)
8003B0B4	nop
8003B0B8	lbu    a1, $0000(v0)
8003B0BC	addiu  v0, v0, $0001
8003B0C0	sw     v0, $0000(v1)

L3b0c4:	; 8003B0C4
8003B0C4	lui    v1, $8008
8003B0C8	addiu  v0, zero, $0001
8003B0CC	lui    a0, $8008
8003B0D0	sw     v0, $b6f8(v1)
8003B0D4	lw     v0, $b6f4(a0)
8003B0D8	sll    v1, a1, $04
8003B0DC	sh     v1, $0020(s4)
8003B0E0	sra    v0, v0, $01
8003B0E4	sw     v0, $b6f4(a0)
8003B0E8	andi   v0, v0, $0001
8003B0EC	beq    v0, zero, L3b10c [$8003b10c]
8003B0F0	lui    v0, $8008
8003B0F4	jal    func52da0 [$80052da0]
8003B0F8	nop
8003B0FC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B100	nop
8003B104	j      L3b128 [$8003b128]
8003B108	addu   a2, v0, zero

L3b10c:	; 8003B10C
8003B10C	lw     v1, $b70c(v0)
8003B110	nop
8003B114	lw     v0, $0000(v1)
8003B118	nop
8003B11C	lbu    a2, $0000(v0)
8003B120	addiu  v0, v0, $0001
8003B124	sw     v0, $0000(v1)

L3b128:	; 8003B128
8003B128	addu   v0, zero, zero
8003B12C	lui    a0, $8008
8003B130	addiu  v1, zero, $0001
8003B134	lui    a1, $8008
8003B138	sw     v1, $b6f8(a0)
8003B13C	lw     v1, $b6f4(a1)
8003B140	sll    a0, a2, $04
8003B144	j      L3dff4 [$8003dff4]
8003B148	sh     a0, $0024(s4)

8003B2BC	lui    v0, $8008
8003B2C0	lw     v0, $b6f4(v0)
8003B2C4	nop
8003B2C8	andi   v0, v0, $0001
8003B2CC	beq    v0, zero, L3b2ec [$8003b2ec]
8003B2D0	lui    v0, $8008
8003B2D4	jal    func52da0 [$80052da0]
8003B2D8	nop
8003B2DC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B2E0	nop
8003B2E4	j      L3b308 [$8003b308]
8003B2E8	addu   a3, v0, zero

L3b2ec:	; 8003B2EC
8003B2EC	lw     v1, $b70c(v0)
8003B2F0	nop
8003B2F4	lw     v0, $0000(v1)
8003B2F8	nop
8003B2FC	lbu    a3, $0000(v0)
8003B300	addiu  v0, v0, $0001
8003B304	sw     v0, $0000(v1)

L3b308:	; 8003B308
8003B308	addiu  a2, zero, $0004
8003B30C	lui    a1, $8008
8003B310	lui    a0, $8008
8003B314	lw     v0, $b6f4(a1)
8003B318	addiu  v1, zero, $0001
8003B31C	sw     v1, $b6f8(a0)
8003B320	srav   v0, v1, v0
8003B324	beq    a3, zero, L3b330 [$8003b330]
8003B328	sw     v0, $b6f4(a1)
8003B32C	addiu  a2, zero, $00a7

L3b330:	; 8003B330
8003B330	j      L39ea8 [$80039ea8]
8003B334	sh     a2, $006e(s0)
8003B338	lui    v0, $8008
8003B33C	lw     v0, $b6f4(v0)
8003B340	nop
8003B344	andi   v0, v0, $0001
8003B348	beq    v0, zero, L3b368 [$8003b368]
8003B34C	lui    v0, $8008
8003B350	jal    func52da0 [$80052da0]
8003B354	nop
8003B358	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B35C	nop
8003B360	j      L3b384 [$8003b384]
8003B364	addu   a2, v0, zero

L3b368:	; 8003B368
8003B368	lw     v1, $b70c(v0)
8003B36C	nop
8003B370	lw     v0, $0000(v1)
8003B374	nop
8003B378	lbu    a2, $0000(v0)
8003B37C	addiu  v0, v0, $0001
8003B380	sw     v0, $0000(v1)

L3b384:	; 8003B384
8003B384	lui    a1, $8008
8003B388	lui    a0, $8008
8003B38C	lw     v0, $b6f4(a1)
8003B390	addiu  v1, zero, $0001
8003B394	sw     v1, $b6f8(a0)
8003B398	srav   v0, v1, v0
8003B39C	sw     v0, $b6f4(a1)
8003B3A0	andi   v0, a2, $00ff
8003B3A4	bne    v0, zero, L39ea8 [$80039ea8]
8003B3A8	sb     a2, $0073(s0)
8003B3AC	addiu  v0, zero, $0010
8003B3B0	j      L39ea8 [$80039ea8]
8003B3B4	sb     v0, $0073(s0)

8003B49C	lui    v0, $8008
8003B4A0	lw     v0, $b6f4(v0)
8003B4A4	nop
8003B4A8	andi   v0, v0, $0001
8003B4AC	beq    v0, zero, L3b4cc [$8003b4cc]
8003B4B0	lui    v0, $8008
8003B4B4	jal    func52da0 [$80052da0]
8003B4B8	nop
8003B4BC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B4C0	nop
8003B4C4	j      L3b4e8 [$8003b4e8]
8003B4C8	addu   a1, v0, zero

L3b4cc:	; 8003B4CC
8003B4CC	lw     v1, $b70c(v0)
8003B4D0	nop
8003B4D4	lw     v0, $0000(v1)
8003B4D8	nop
8003B4DC	lbu    a1, $0000(v0)
8003B4E0	addiu  v0, v0, $0001
8003B4E4	sw     v0, $0000(v1)

L3b4e8:	; 8003B4E8
8003B4E8	addu   a0, s0, zero
8003B4EC	sll    a1, a1, $04
8003B4F0	lui    a3, $8008
8003B4F4	lui    a2, $8008
8003B4F8	lw     v0, $b6f4(a3)
8003B4FC	addiu  v1, zero, $0001
8003B500	sw     v1, $b6f8(a2)
8003B504	srav   v0, v1, v0
8003B508	sw     v0, $b6f4(a3)
8003B50C	lbu    a3, $0073(a0)
8003B510	j      L3b700 [$8003b700]
8003B514	addu   a2, v1, zero
8003B518	lui    v0, $8008
8003B51C	lw     v0, $b6f4(v0)
8003B520	nop
8003B524	andi   v0, v0, $0001
8003B528	beq    v0, zero, L3b548 [$8003b548]
8003B52C	lui    v0, $8008
8003B530	jal    func52da0 [$80052da0]
8003B534	nop
8003B538	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B53C	nop
8003B540	j      L3b580 [$8003b580]
8003B544	addu   a1, v0, zero

L3b548:	; 8003B548
8003B548	lw     a0, $b70c(v0)
8003B54C	nop
8003B550	lw     v0, $0000(a0)
8003B554	nop
8003B558	lbu    a1, $0000(v0)
8003B55C	addiu  v0, v0, $0001
8003B560	sw     v0, $0000(a0)
8003B564	lbu    v1, $0000(v0)
8003B568	addiu  v0, v0, $0001
8003B56C	sw     v0, $0000(a0)
8003B570	sll    v1, v1, $08
8003B574	or     a1, a1, v1
8003B578	sll    v0, a1, $10
8003B57C	sra    a1, v0, $10

L3b580:	; 8003B580
8003B580	lui    v1, $8008
8003B584	addiu  v0, zero, $0001
8003B588	lui    a0, $8008
8003B58C	sw     v0, $b6f8(v1)
8003B590	lw     v1, $0014(s0)
8003B594	lw     v0, $b6f4(a0)
8003B598	nop
8003B59C	sra    v0, v0, $01
8003B5A0	sw     v0, $b6f4(a0)
8003B5A4	andi   v0, v0, $0001
8003B5A8	beq    v0, zero, L3b5c8 [$8003b5c8]
8003B5AC	subu   s2, a1, v1
8003B5B0	jal    func52da0 [$80052da0]
8003B5B4	nop
8003B5B8	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B5BC	nop
8003B5C0	j      L3b604 [$8003b604]
8003B5C4	addu   a1, v0, zero

L3b5c8:	; 8003B5C8
8003B5C8	lui    v0, $8008
8003B5CC	lw     a0, $b70c(v0)
8003B5D0	nop
8003B5D4	lw     v0, $0000(a0)
8003B5D8	nop
8003B5DC	lbu    a1, $0000(v0)
8003B5E0	addiu  v0, v0, $0001
8003B5E4	sw     v0, $0000(a0)
8003B5E8	lbu    v1, $0000(v0)
8003B5EC	addiu  v0, v0, $0001
8003B5F0	sw     v0, $0000(a0)
8003B5F4	sll    v1, v1, $08
8003B5F8	or     a1, a1, v1
8003B5FC	sll    v0, a1, $10
8003B600	sra    a1, v0, $10

L3b604:	; 8003B604
8003B604	lui    v1, $8008
8003B608	addiu  v0, zero, $0001
8003B60C	lui    a0, $8008
8003B610	sw     v0, $b6f8(v1)
8003B614	lw     v1, $001c(s0)
8003B618	lw     v0, $b6f4(a0)
8003B61C	subu   s3, a1, v1
8003B620	sra    v0, v0, $01
8003B624	sw     v0, $b6f4(a0)
8003B628	or     v0, s2, s3
8003B62C	beq    v0, zero, L39ea8 [$80039ea8]
8003B630	addu   a0, s2, zero
8003B634	jal    system_get_rotation_by_vector_x_y [$80052f24]
8003B638	addu   a1, s3, zero
8003B63C	addu   a0, s0, zero
8003B640	addu   a1, v0, zero
8003B644	lbu    a3, $0073(a0)
8003B648	jal    func398d0 [$800398d0]
8003B64C	addiu  a2, zero, $0001
8003B650	j      L475b4 [$800475b4]
8003B654	addu   v0, zero, zero

L3b700:	; 8003B700
8003B700	jal    func398d0 [$800398d0]
8003B704	nop
8003B708	j      L475b4 [$800475b4]
8003B70C	addu   v0, zero, zero

8003B88C	lui    v0, $8008
8003B890	lw     v0, $b6f4(v0)
8003B894	nop
8003B898	andi   v0, v0, $0001
8003B89C	beq    v0, zero, L3b8bc [$8003b8bc]
8003B8A0	lui    v0, $8008
8003B8A4	jal    func52da0 [$80052da0]
8003B8A8	nop
8003B8AC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B8B0	nop
8003B8B4	j      L3b8f4 [$8003b8f4]
8003B8B8	addu   a1, v0, zero

L3b8bc:	; 8003B8BC
8003B8BC	lw     a0, $b70c(v0)
8003B8C0	nop
8003B8C4	lw     v0, $0000(a0)
8003B8C8	nop
8003B8CC	lbu    a1, $0000(v0)
8003B8D0	addiu  v0, v0, $0001
8003B8D4	sw     v0, $0000(a0)
8003B8D8	lbu    v1, $0000(v0)
8003B8DC	addiu  v0, v0, $0001
8003B8E0	sw     v0, $0000(a0)
8003B8E4	sll    v1, v1, $08
8003B8E8	or     a1, a1, v1
8003B8EC	sll    v0, a1, $10
8003B8F0	sra    a1, v0, $10

L3b8f4:	; 8003B8F4
8003B8F4	addu   s2, a1, zero
8003B8F8	lui    a1, $8008
8003B8FC	lui    a0, $8008
8003B900	lw     v0, $b6f4(a1)
8003B904	addiu  v1, zero, $0001
8003B908	sw     v1, $b6f8(a0)
8003B90C	srav   v0, v1, v0
8003B910	sw     v0, $b6f4(a1)
8003B914	and    v0, v0, v1
8003B918	beq    v0, zero, L3b938 [$8003b938]
8003B91C	lui    v0, $8008
8003B920	jal    func52da0 [$80052da0]
8003B924	nop
8003B928	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003B92C	nop
8003B930	j      L3b954 [$8003b954]
8003B934	addu   a1, v0, zero

L3b938:	; 8003B938
8003B938	lw     v1, $b70c(v0)
8003B93C	nop
8003B940	lw     v0, $0000(v1)
8003B944	nop
8003B948	lbu    a1, $0000(v0)
8003B94C	addiu  v0, v0, $0001
8003B950	sw     v0, $0000(v1)

L3b954:	; 8003B954
8003B954	addu   a0, s2, zero
8003B958	lui    a3, $8008
8003B95C	lui    a2, $8008
8003B960	lw     v0, $b6f4(a3)
8003B964	addiu  v1, zero, $0001
8003B968	sw     v1, $b6f8(a2)
8003B96C	srav   v0, v1, v0
8003B970	jal    func4ed00 [$8004ed00]
8003B974	sw     v0, $b6f4(a3)
8003B978	j      L475b4 [$800475b4]
8003B97C	addu   v0, zero, zero
8003B980	jal    func4efa0 [$8004efa0]
8003B984	nop
8003B988	j      L475b4 [$800475b4]
8003B98C	addu   v0, zero, zero

8003BDEC	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003BDF0	nop
8003BDF4	lui    v1, $8008
8003BDF8	lw     v1, $b6f4(v1)
8003BDFC	nop
8003BE00	andi   v1, v1, $0001
8003BE04	beq    v1, zero, L3be24 [$8003be24]
8003BE08	addu   s4, v0, zero
8003BE0C	jal    func52da0 [$80052da0]
8003BE10	nop
8003BE14	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003BE18	nop
8003BE1C	j      L3be44 [$8003be44]
8003BE20	addu   a1, v0, zero

L3be24:	; 8003BE24
8003BE24	lui    v0, $8008
8003BE28	lw     v1, $b70c(v0)
8003BE2C	nop
8003BE30	lw     v0, $0000(v1)
8003BE34	nop
8003BE38	lbu    a1, $0000(v0)
8003BE3C	addiu  v0, v0, $0001
8003BE40	sw     v0, $0000(v1)

L3be44:	; 8003BE44
8003BE44	lui    v1, $8008
8003BE48	addiu  v0, zero, $0001
8003BE4C	sw     v0, $b6f8(v1)
8003BE50	lui    v1, $8008
8003BE54	lui    a0, $8008
8003BE58	lw     v0, $b6f4(v1)
8003BE5C	lw     a0, $b704(a0)
8003BE60	sra    v0, v0, $01
8003BE64	sw     v0, $b6f4(v1)
8003BE68	sb     a1, $0010(a0)
8003BE6C	lw     v0, $b6f4(v1)
8003BE70	nop
8003BE74	andi   v0, v0, $0001
8003BE78	beq    v0, zero, L3be98 [$8003be98]
8003BE7C	lui    v0, $8008
8003BE80	jal    func52da0 [$80052da0]
8003BE84	nop
8003BE88	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003BE8C	nop
8003BE90	j      L3beb4 [$8003beb4]
8003BE94	addu   a2, v0, zero

L3be98:	; 8003BE98
8003BE98	lw     v1, $b70c(v0)
8003BE9C	nop
8003BEA0	lw     v0, $0000(v1)
8003BEA4	nop
8003BEA8	lbu    a2, $0000(v0)
8003BEAC	addiu  v0, v0, $0001
8003BEB0	sw     v0, $0000(v1)

L3beb4:	; 8003BEB4
8003BEB4	addu   s5, a2, zero
8003BEB8	lui    a1, $8008
8003BEBC	lui    a0, $8008
8003BEC0	lw     v0, $b6f4(a1)
8003BEC4	addiu  v1, zero, $0001
8003BEC8	sw     v1, $b6f8(a0)
8003BECC	andi   a0, s5, $00a0
8003BED0	srav   v0, v1, v0
8003BED4	sw     v0, $b6f4(a1)
8003BED8	lui    v0, $8008
8003BEDC	lw     v0, $b704(v0)
8003BEE0	addiu  v1, zero, $0080
8003BEE4	lbu    a1, $0010(v0)
8003BEE8	bne    a0, v1, L3bf74 [$8003bf74]
8003BEEC	lui    v0, $8008
8003BEF0	lbu    v1, $0005(s4)
8003BEF4	addiu  v0, zero, $0004
8003BEF8	bne    v1, v0, L3bf74 [$8003bf74]
8003BEFC	lui    v0, $8008
8003BF00	lui    v0, $8008
8003BF04	lw     v0, $aecc(v0)
8003BF08	nop
8003BF0C	lw     a0, $16d8(v0)
8003BF10	nop
8003BF14	beq    a0, zero, L3bf5c [$8003bf5c]
8003BF18	addiu  a2, zero, $00ff
8003BF1C	addiu  a3, zero, $0004

loop3bf20:	; 8003BF20
8003BF20	lw     v1, $0004(a0)
8003BF24	nop
8003BF28	lbu    v0, $0005(v1)
8003BF2C	nop
8003BF30	bne    v0, a3, L3bf4c [$8003bf4c]
8003BF34	nop
8003BF38	lbu    v0, $003e(v1)
8003BF3C	nop
8003BF40	bne    v0, a1, L3bf4c [$8003bf4c]
8003BF44	nop
8003BF48	sb     a2, $003e(v1)

L3bf4c:	; 8003BF4C
8003BF4C	lw     a0, $0000(a0)
8003BF50	nop
8003BF54	bne    a0, zero, loop3bf20 [$8003bf20]
8003BF58	nop

L3bf5c:	; 8003BF5C
8003BF5C	lui    v0, $8008
8003BF60	sb     a1, $003e(s4)
8003BF64	sw     s4, $ae68(v0)
8003BF68	lui    v0, $8008
8003BF6C	sw     zero, $ae6c(v0)
8003BF70	lui    v0, $8008

L3bf74:	; 8003BF74
8003BF74	lw     v0, $b6f4(v0)
8003BF78	nop
8003BF7C	andi   v0, v0, $0001
8003BF80	beq    v0, zero, L3bfa0 [$8003bfa0]
8003BF84	nop
8003BF88	jal    func52da0 [$80052da0]
8003BF8C	nop
8003BF90	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003BF94	nop
8003BF98	j      L3bfdc [$8003bfdc]
8003BF9C	addu   a1, v0, zero

L3bfa0:	; 8003BFA0
8003BFA0	lui    v0, $8008
8003BFA4	lw     a0, $b70c(v0)
8003BFA8	nop
8003BFAC	lw     v0, $0000(a0)
8003BFB0	nop
8003BFB4	lbu    a1, $0000(v0)
8003BFB8	addiu  v0, v0, $0001
8003BFBC	sw     v0, $0000(a0)
8003BFC0	lbu    v1, $0000(v0)
8003BFC4	addiu  v0, v0, $0001
8003BFC8	sw     v0, $0000(a0)
8003BFCC	sll    v1, v1, $08
8003BFD0	or     a1, a1, v1
8003BFD4	sll    v0, a1, $10
8003BFD8	sra    a1, v0, $10

L3bfdc:	; 8003BFDC
8003BFDC	addu   s3, a1, zero
8003BFE0	addu   a0, s4, zero
8003BFE4	addu   a2, s5, zero
8003BFE8	lui    t0, $8008
8003BFEC	lui    a3, $8008
8003BFF0	lw     v0, $b6f4(t0)
8003BFF4	addiu  v1, zero, $0001
8003BFF8	sw     v1, $b6f8(a3)
8003BFFC	srav   v0, v1, v0
8003C000	jal    func39660 [$80039660]
8003C004	sw     v0, $b6f4(t0)
8003C008	addu   a0, s3, zero
8003C00C	lui    s0, $8008
8003C010	lw     v1, $b704(s0)
8003C014	addu   a2, v0, zero
8003C018	lbu    a1, $0010(v1)
8003C01C	jal    func4dcec [$8004dcec]
8003C020	addu   a3, s5, zero
8003C024	lw     a0, $b704(s0)
8003C02C	addiu  v0, zero, $0001
8003C374	addiu  v1, zero, $00fe
8003C378	j      L475b4 [$800475b4]
8003C37C	sb     v1, $000d(a0)

8003C030	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003C034	nop
8003C038	lui    v1, $8008
8003C03C	lw     v1, $b6f4(v1)
8003C040	nop
8003C044	andi   v1, v1, $0001
8003C048	beq    v1, zero, L3c068 [$8003c068]
8003C04C	addu   s4, v0, zero
8003C050	jal    func52da0 [$80052da0]
8003C054	nop
8003C058	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C05C	nop
8003C060	j      L3c088 [$8003c088]
8003C064	addu   a1, v0, zero

L3c068:	; 8003C068
8003C068	lui    v0, $8008
8003C06C	lw     v1, $b70c(v0)
8003C070	nop
8003C074	lw     v0, $0000(v1)
8003C078	nop
8003C07C	lbu    a1, $0000(v0)
8003C080	addiu  v0, v0, $0001
8003C084	sw     v0, $0000(v1)

L3c088:	; 8003C088
8003C088	lui    v1, $8008
8003C08C	addiu  v0, zero, $0001
8003C090	sw     v0, $b6f8(v1)
8003C094	lui    v1, $8008
8003C098	lui    a0, $8008
8003C09C	lw     v0, $b6f4(v1)
8003C0A0	lw     a0, $b704(a0)
8003C0A4	sra    v0, v0, $01
8003C0A8	sw     v0, $b6f4(v1)
8003C0AC	sb     a1, $0010(a0)
8003C0B0	lw     v0, $b6f4(v1)
8003C0B4	nop
8003C0B8	andi   v0, v0, $0001
8003C0BC	beq    v0, zero, L3c0dc [$8003c0dc]
8003C0C0	lui    v0, $8008
8003C0C4	jal    func52da0 [$80052da0]
8003C0C8	nop
8003C0CC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C0D0	nop
8003C0D4	j      L3c0f8 [$8003c0f8]
8003C0D8	addu   a2, v0, zero

L3c0dc:	; 8003C0DC
8003C0DC	lw     v1, $b70c(v0)
8003C0E0	nop
8003C0E4	lw     v0, $0000(v1)
8003C0E8	nop
8003C0EC	lbu    a2, $0000(v0)
8003C0F0	addiu  v0, v0, $0001
8003C0F4	sw     v0, $0000(v1)

L3c0f8:	; 8003C0F8
8003C0F8	addu   s5, a2, zero
8003C0FC	lui    a1, $8008
8003C100	lui    a0, $8008
8003C104	lw     v0, $b6f4(a1)
8003C108	addiu  v1, zero, $0001
8003C10C	sw     v1, $b6f8(a0)
8003C110	andi   a0, s5, $00a0
8003C114	srav   v0, v1, v0
8003C118	sw     v0, $b6f4(a1)
8003C11C	lui    v0, $8008
8003C120	lw     v0, $b704(v0)
8003C124	addiu  v1, zero, $0080
8003C128	lbu    a1, $0010(v0)
8003C12C	bne    a0, v1, L3c1b8 [$8003c1b8]
8003C130	lui    v0, $8008
8003C134	lbu    v1, $0005(s4)
8003C138	addiu  v0, zero, $0004
8003C13C	bne    v1, v0, L3c1b8 [$8003c1b8]
8003C140	lui    v0, $8008
8003C144	lui    v0, $8008
8003C148	lw     v0, $aecc(v0)
8003C14C	nop
8003C150	lw     a0, $16d8(v0)
8003C154	nop
8003C158	beq    a0, zero, L3c1a0 [$8003c1a0]
8003C15C	addiu  a2, zero, $00ff
8003C160	addiu  a3, zero, $0004

loop3c164:	; 8003C164
8003C164	lw     v1, $0004(a0)
8003C168	nop
8003C16C	lbu    v0, $0005(v1)
8003C170	nop
8003C174	bne    v0, a3, L3c190 [$8003c190]
8003C178	nop
8003C17C	lbu    v0, $003e(v1)
8003C180	nop
8003C184	bne    v0, a1, L3c190 [$8003c190]
8003C188	nop
8003C18C	sb     a2, $003e(v1)

L3c190:	; 8003C190
8003C190	lw     a0, $0000(a0)
8003C194	nop
8003C198	bne    a0, zero, loop3c164 [$8003c164]
8003C19C	nop

L3c1a0:	; 8003C1A0
8003C1A0	lui    v0, $8008
8003C1A4	sb     a1, $003e(s4)
8003C1A8	sw     s4, $ae68(v0)
8003C1AC	lui    v0, $8008
8003C1B0	sw     zero, $ae6c(v0)
8003C1B4	lui    v0, $8008

L3c1b8:	; 8003C1B8
8003C1B8	lw     v0, $b6f4(v0)
8003C1BC	nop
8003C1C0	andi   v0, v0, $0001
8003C1C4	beq    v0, zero, L3c1e4 [$8003c1e4]
8003C1C8	lui    v0, $8008
8003C1CC	jal    func52da0 [$80052da0]
8003C1D0	nop
8003C1D4	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C1D8	nop
8003C1DC	j      L3c21c [$8003c21c]
8003C1E0	addu   a1, v0, zero

L3c1e4:	; 8003C1E4
8003C1E4	lw     a0, $b70c(v0)
8003C1E8	nop
8003C1EC	lw     v0, $0000(a0)
8003C1F0	nop
8003C1F4	lbu    a1, $0000(v0)
8003C1F8	addiu  v0, v0, $0001
8003C1FC	sw     v0, $0000(a0)
8003C200	lbu    v1, $0000(v0)
8003C204	addiu  v0, v0, $0001
8003C208	sw     v0, $0000(a0)
8003C20C	sll    v1, v1, $08
8003C210	or     a1, a1, v1
8003C214	sll    v0, a1, $10
8003C218	sra    a1, v0, $10

L3c21c:	; 8003C21C
8003C21C	addu   s3, a1, zero
8003C220	addu   a0, s4, zero
8003C224	addu   a2, s5, zero
8003C228	lui    t0, $8008
8003C22C	lui    a3, $8008
8003C230	lw     v0, $b6f4(t0)
8003C234	addiu  v1, zero, $0001
8003C238	sw     v1, $b6f8(a3)
8003C23C	srav   v0, v1, v0
8003C240	jal    func39660 [$80039660]
8003C244	sw     v0, $b6f4(t0)
8003C248	addu   a0, s3, zero
8003C24C	lui    v1, $8008
8003C250	lw     v1, $b704(v1)
8003C254	addu   a2, v0, zero
8003C258	lbu    a1, $0010(v1)
8003C25C	jal    func4dcec [$8004dcec]
8003C260	addu   a3, s5, zero
8003C264	j      L475b4 [$800475b4]
8003C268	addu   v0, zero, zero

8003C2E0	jal    func4e924 [$8004e924]
8003C2E4	nop
8003C2E8	jal    func2dd54 [$8002dd54]
8003C2EC	nop
8003C2F0	j      L475b4 [$800475b4]
8003C2F4	addu   v0, zero, zero




8003C390	lui    v0, $8008
8003C394	lw     v0, $b6f4(v0)
8003C398	nop
8003C39C	andi   v0, v0, $0001
8003C3A0	beq    v0, zero, L3c3c0 [$8003c3c0]
8003C3A4	lui    v0, $8008
8003C3A8	jal    func52da0 [$80052da0]
8003C3AC	nop
8003C3B0	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C3B4	nop
8003C3B8	j      L3c3f8 [$8003c3f8]
8003C3BC	addu   a1, v0, zero

L3c3c0:	; 8003C3C0
8003C3C0	lw     a0, $b70c(v0)
8003C3C4	nop
8003C3C8	lw     v0, $0000(a0)
8003C3CC	nop
8003C3D0	lbu    a1, $0000(v0)
8003C3D4	addiu  v0, v0, $0001
8003C3D8	sw     v0, $0000(a0)
8003C3DC	lbu    v1, $0000(v0)
8003C3E0	addiu  v0, v0, $0001
8003C3E4	sw     v0, $0000(a0)
8003C3E8	sll    v1, v1, $08
8003C3EC	or     a1, a1, v1
8003C3F0	sll    v0, a1, $10
8003C3F4	sra    a1, v0, $10

L3c3f8:	; 8003C3F8
8003C3F8	addu   a0, a1, zero
8003C3FC	lui    a2, $8008
8003C400	lui    a1, $8008
8003C404	lw     v0, $b6f4(a2)
8003C408	addiu  v1, zero, $0001
8003C40C	sw     v1, $b6f8(a1)
8003C410	srav   v0, v1, v0
8003C414	jal    func4f058 [$8004f058]
8003C418	sw     v0, $b6f4(a2)
8003C41C	addu   a0, v0, zero
8003C420	jal    funcf4f04 [$800f4f04]
8003C424	addiu  a1, zero, $0003
8003C428	j      L475b4 [$800475b4]
8003C42C	addu   v0, zero, zero

8003C45C	lui    v0, $8008
8003C460	lw     v0, $b6f4(v0)
8003C464	nop
8003C468	andi   v0, v0, $0001
8003C46C	bne    v0, zero, L3f0d0 [$8003f0d0]
8003C470	lui    v0, $8008
8003C474	j      L3f0e8 [$8003f0e8]
8003C478	nop

8003C570	lui    v0, $8008
8003C574	lw     v0, $b6f4(v0)
8003C578	nop
8003C57C	andi   v0, v0, $0001
8003C580	beq    v0, zero, L3c5a0 [$8003c5a0]
8003C584	lui    v0, $8008
8003C588	jal    func52da0 [$80052da0]
8003C58C	nop
8003C590	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C594	nop
8003C598	j      L3c5d8 [$8003c5d8]
8003C59C	addu   a1, v0, zero

L3c5a0:	; 8003C5A0
8003C5A0	lw     a0, $b70c(v0)
8003C5A4	nop
8003C5A8	lw     v0, $0000(a0)
8003C5AC	nop
8003C5B0	lbu    a1, $0000(v0)
8003C5B4	addiu  v0, v0, $0001
8003C5B8	sw     v0, $0000(a0)
8003C5BC	lbu    v1, $0000(v0)
8003C5C0	addiu  v0, v0, $0001
8003C5C4	sw     v0, $0000(a0)
8003C5C8	sll    v1, v1, $08
8003C5CC	or     a1, a1, v1
8003C5D0	sll    v0, a1, $10
8003C5D4	sra    a1, v0, $10

L3c5d8:	; 8003C5D8
8003C5D8	addu   s2, a1, zero
8003C5DC	lui    a1, $8008
8003C5E0	lui    a0, $8008
8003C5E4	lw     v0, $b6f4(a1)
8003C5E8	addiu  v1, zero, $0001
8003C5EC	sw     v1, $b6f8(a0)
8003C5F0	srav   v0, v1, v0
8003C5F4	sw     v0, $b6f4(a1)
8003C5F8	and    v0, v0, v1
8003C5FC	beq    v0, zero, L3c61c [$8003c61c]
8003C600	nop
8003C604	jal    func52da0 [$80052da0]
8003C608	nop
8003C60C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C610	nop
8003C614	j      L3c658 [$8003c658]
8003C618	addu   a2, v0, zero

L3c61c:	; 8003C61C
8003C61C	lui    v0, $8008
8003C620	lw     a0, $b70c(v0)
8003C624	nop
8003C628	lw     v0, $0000(a0)
8003C62C	nop
8003C630	lbu    a2, $0000(v0)
8003C634	addiu  v0, v0, $0001
8003C638	sw     v0, $0000(a0)
8003C63C	lbu    v1, $0000(v0)
8003C640	addiu  v0, v0, $0001
8003C644	sw     v0, $0000(a0)
8003C648	sll    v1, v1, $08
8003C64C	or     a2, a2, v1
8003C650	sll    v0, a2, $10
8003C654	sra    a2, v0, $10

L3c658:	; 8003C658
8003C658	addu   a0, s2, zero
8003C65C	addu   a1, zero, zero
8003C660	addiu  a3, zero, $0001
8003C664	lui    v1, $8008
8003C668	lui    s1, $8008
8003C66C	lw     v0, $b6f4(v1)
8003C670	addu   s0, a3, zero
8003C674	sw     s0, $b6f8(s1)
8003C678	j      L3ca10 [$8003ca10]
8003C67C	srav   v0, a3, v0
8003C680	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003C684	nop
8003C688	addu   s4, v0, zero
8003C68C	lw     a0, $0014(s4)
8003C690	lw     a1, $0018(s4)
8003C694	lw     a2, $001c(s4)
8003C698	jal    func38990 [$80038990]
8003C69C	addu   a3, s4, zero
8003C6A0	beq    v0, zero, L3c6c4 [$8003c6c4]
8003C6A4	lui    v0, $8008
8003C6A8	lui    v1, $8008
8003C6AC	lui    a0, $8008
8003C6B0	lw     a1, $b70c(v0)
8003C6B4	lw     v1, $aea0(v1)
8003C6B8	addiu  v0, zero, $0001
8003C6BC	sw     v0, $b6f8(a0)
8003C6C0	sw     v1, $0000(a1)

L3c6c4:	; 8003C6C4
8003C6C4	lui    v1, $8008
8003C6C8	addiu  v0, zero, $0001
8003C6CC	j      L475b4 [$800475b4]
8003C6D0	sw     v0, $b6f8(v1)
8003C6D4	addu   a1, zero, zero
8003C6D8	lui    v0, $8008
8003C6DC	lw     a0, $ae24(v0)
8003C6E0	lui    v0, $8008
8003C6E4	lw     a2, $ae28(v0)
8003C6E8	jal    func38990 [$80038990]
8003C6EC	addu   a3, a1, zero
8003C6F0	beq    v0, zero, L475b4 [$800475b4]
8003C6F4	addiu  v0, zero, $0001

L3c6f8:	; 8003C6F8
8003C6F8	lui    v0, $8008
8003C6FC	lui    v1, $8008
8003C700	lui    a0, $8008
8003C704	lw     a1, $b70c(v0)
8003C708	lw     v1, $aea0(v1)
8003C70C	addiu  v0, zero, $0001
8003C710	sw     v0, $b6f8(a0)
8003C714	j      L475b4 [$800475b4]
8003C718	sw     v1, $0000(a1)
8003C71C	lui    v0, $8008
8003C720	lw     v0, $b6f4(v0)
8003C724	nop
8003C728	andi   v0, v0, $0001
8003C72C	beq    v0, zero, L3c74c [$8003c74c]
8003C730	lui    v0, $8008
8003C734	jal    func52da0 [$80052da0]
8003C738	nop
8003C73C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C740	nop
8003C744	j      L3c784 [$8003c784]
8003C748	addu   a1, v0, zero

L3c74c:	; 8003C74C
8003C74C	lw     a0, $b70c(v0)
8003C750	nop
8003C754	lw     v0, $0000(a0)
8003C758	nop
8003C75C	lbu    a1, $0000(v0)
8003C760	addiu  v0, v0, $0001
8003C764	sw     v0, $0000(a0)
8003C768	lbu    v1, $0000(v0)
8003C76C	addiu  v0, v0, $0001
8003C770	sw     v0, $0000(a0)
8003C774	sll    v1, v1, $08
8003C778	or     a1, a1, v1
8003C77C	sll    v0, a1, $10
8003C780	sra    a1, v0, $10

L3c784:	; 8003C784
8003C784	addu   s2, a1, zero
8003C788	lui    a1, $8008
8003C78C	lui    a0, $8008
8003C790	lw     v0, $b6f4(a1)
8003C794	addiu  v1, zero, $0001
8003C798	sw     v1, $b6f8(a0)
8003C79C	srav   v0, v1, v0
8003C7A0	sw     v0, $b6f4(a1)
8003C7A4	and    v0, v0, v1
8003C7A8	beq    v0, zero, L3c7c8 [$8003c7c8]
8003C7AC	lui    v0, $8008
8003C7B0	jal    func52da0 [$80052da0]
8003C7B4	nop
8003C7B8	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C7BC	nop
8003C7C0	j      L3c800 [$8003c800]
8003C7C4	addu   a1, v0, zero

L3c7c8:	; 8003C7C8
8003C7C8	lw     a0, $b70c(v0)
8003C7CC	nop
8003C7D0	lw     v0, $0000(a0)
8003C7D4	nop
8003C7D8	lbu    a1, $0000(v0)
8003C7DC	addiu  v0, v0, $0001
8003C7E0	sw     v0, $0000(a0)
8003C7E4	lbu    v1, $0000(v0)
8003C7E8	addiu  v0, v0, $0001
8003C7EC	sw     v0, $0000(a0)
8003C7F0	sll    v1, v1, $08
8003C7F4	or     a1, a1, v1
8003C7F8	sll    v0, a1, $10
8003C7FC	sra    a1, v0, $10

L3c800:	; 8003C800
8003C800	addu   s3, a1, zero
8003C804	lui    a1, $8008
8003C808	lui    a0, $8008
8003C80C	lw     v0, $b6f4(a1)
8003C810	addiu  v1, zero, $0001
8003C814	sw     v1, $b6f8(a0)
8003C818	srav   v0, v1, v0
8003C81C	sw     v0, $b6f4(a1)
8003C820	and    v0, v0, v1
8003C824	beq    v0, zero, L3c844 [$8003c844]
8003C828	lui    v0, $8008
8003C82C	jal    func52da0 [$80052da0]
8003C830	nop
8003C834	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C838	nop
8003C83C	j      L3c87c [$8003c87c]
8003C840	addu   a2, v0, zero

L3c844:	; 8003C844
8003C844	lw     a0, $b70c(v0)
8003C848	nop
8003C84C	lw     v0, $0000(a0)
8003C850	nop
8003C854	lbu    a2, $0000(v0)
8003C858	addiu  v0, v0, $0001
8003C85C	sw     v0, $0000(a0)
8003C860	lbu    v1, $0000(v0)
8003C864	addiu  v0, v0, $0001
8003C868	sw     v0, $0000(a0)
8003C86C	sll    v1, v1, $08
8003C870	or     a2, a2, v1
8003C874	sll    v0, a2, $10
8003C878	sra    a2, v0, $10

L3c87c:	; 8003C87C
8003C87C	addu   a0, s2, zero
8003C880	addu   a1, s3, zero
8003C884	j      L3c9f8 [$8003c9f8]
8003C888	addiu  a3, zero, $0002
8003C88C	lui    v0, $8008
8003C890	lw     v0, $b6f4(v0)
8003C894	nop
8003C898	andi   v0, v0, $0001
8003C89C	beq    v0, zero, L3c8bc [$8003c8bc]
8003C8A0	lui    v0, $8008
8003C8A4	jal    func52da0 [$80052da0]
8003C8A8	nop
8003C8AC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C8B0	nop
8003C8B4	j      L3c8f4 [$8003c8f4]
8003C8B8	addu   a1, v0, zero

L3c8bc:	; 8003C8BC
8003C8BC	lw     a0, $b70c(v0)
8003C8C0	nop
8003C8C4	lw     v0, $0000(a0)
8003C8C8	nop
8003C8CC	lbu    a1, $0000(v0)
8003C8D0	addiu  v0, v0, $0001
8003C8D4	sw     v0, $0000(a0)
8003C8D8	lbu    v1, $0000(v0)
8003C8DC	addiu  v0, v0, $0001
8003C8E0	sw     v0, $0000(a0)
8003C8E4	sll    v1, v1, $08
8003C8E8	or     a1, a1, v1
8003C8EC	sll    v0, a1, $10
8003C8F0	sra    a1, v0, $10

L3c8f4:	; 8003C8F4
8003C8F4	addu   s2, a1, zero
8003C8F8	lui    a1, $8008
8003C8FC	lui    a0, $8008
8003C900	lw     v0, $b6f4(a1)
8003C904	addiu  v1, zero, $0001
8003C908	sw     v1, $b6f8(a0)
8003C90C	srav   v0, v1, v0
8003C910	sw     v0, $b6f4(a1)
8003C914	and    v0, v0, v1
8003C918	beq    v0, zero, L3c938 [$8003c938]
8003C91C	lui    v0, $8008
8003C920	jal    func52da0 [$80052da0]
8003C924	nop
8003C928	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C92C	nop
8003C930	j      L3c970 [$8003c970]
8003C934	addu   a1, v0, zero

L3c938:	; 8003C938
8003C938	lw     a0, $b70c(v0)
8003C93C	nop
8003C940	lw     v0, $0000(a0)
8003C944	nop
8003C948	lbu    a1, $0000(v0)
8003C94C	addiu  v0, v0, $0001
8003C950	sw     v0, $0000(a0)
8003C954	lbu    v1, $0000(v0)
8003C958	addiu  v0, v0, $0001
8003C95C	sw     v0, $0000(a0)
8003C960	sll    v1, v1, $08
8003C964	or     a1, a1, v1
8003C968	sll    v0, a1, $10
8003C96C	sra    a1, v0, $10

L3c970:	; 8003C970
8003C970	addu   s3, a1, zero
8003C974	lui    a1, $8008
8003C978	lui    a0, $8008
8003C97C	lw     v0, $b6f4(a1)
8003C980	addiu  v1, zero, $0001
8003C984	sw     v1, $b6f8(a0)
8003C988	srav   v0, v1, v0
8003C98C	sw     v0, $b6f4(a1)
8003C990	and    v0, v0, v1
8003C994	beq    v0, zero, L3c9b4 [$8003c9b4]
8003C998	lui    v0, $8008
8003C99C	jal    func52da0 [$80052da0]
8003C9A0	nop
8003C9A4	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003C9A8	nop
8003C9AC	j      L3c9ec [$8003c9ec]
8003C9B0	addu   a2, v0, zero

L3c9b4:	; 8003C9B4
8003C9B4	lw     a0, $b70c(v0)
8003C9B8	nop
8003C9BC	lw     v0, $0000(a0)
8003C9C0	nop
8003C9C4	lbu    a2, $0000(v0)
8003C9C8	addiu  v0, v0, $0001
8003C9CC	sw     v0, $0000(a0)
8003C9D0	lbu    v1, $0000(v0)
8003C9D4	addiu  v0, v0, $0001
8003C9D8	sw     v0, $0000(a0)
8003C9DC	sll    v1, v1, $08
8003C9E0	or     a2, a2, v1
8003C9E4	sll    v0, a2, $10
8003C9E8	sra    a2, v0, $10

L3c9ec:	; 8003C9EC
8003C9EC	addu   a0, s2, zero
8003C9F0	addu   a1, s3, zero
8003C9F4	addiu  a3, zero, $0003

L3c9f8:	; 8003C9F8
8003C9F8	lui    v1, $8008
8003C9FC	lui    s1, $8008
8003CA00	lw     v0, $b6f4(v1)
8003CA04	addiu  s0, zero, $0001
8003CA08	sw     s0, $b6f8(s1)
8003CA0C	srav   v0, s0, v0

L3ca10:	; 8003CA10
8003CA10	jal    func38990 [$80038990]
8003CA14	sw     v0, $b6f4(v1)
if (V0 != 0)
{
    8003CA1C	lui    v0, $8008
    8003CA20	lui    v1, $8008
    8003CA24	lw     a0, $b70c(v0)
    8003CA28	lw     v0, $aea0(v1)
    8003CA2C	sw     s0, $b6f8(s1)
    8003CA34	sw     v0, $0000(a0)
}
return 1;

8003CB28	lui    v0, $8008
8003CB2C	lw     v0, $b6f4(v0)
8003CB30	nop
8003CB34	andi   v0, v0, $0001
8003CB38	beq    v0, zero, L3cb58 [$8003cb58]
8003CB3C	lui    v0, $8008
8003CB40	jal    func52da0 [$80052da0]
8003CB44	nop
8003CB48	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003CB4C	nop
8003CB50	j      L3cb74 [$8003cb74]
8003CB54	addu   a3, v0, zero

L3cb58:	; 8003CB58
8003CB58	lw     v1, $b70c(v0)
8003CB5C	nop
8003CB60	lw     v0, $0000(v1)
8003CB64	nop
8003CB68	lbu    a3, $0000(v0)
8003CB6C	addiu  v0, v0, $0001
8003CB70	sw     v0, $0000(v1)

L3cb74:	; 8003CB74
8003CB74	addu   v0, zero, zero
8003CB78	lui    a2, $8008
8003CB7C	lui    a1, $8008
8003CB80	lw     v1, $b6f4(a2)
8003CB84	addiu  a0, zero, $0001
8003CB88	sw     a0, $b6f8(a1)
8003CB8C	srav   v1, a0, v1
8003CB90	sw     v1, $b6f4(a2)
8003CB94	j      L475b4 [$800475b4]
8003CB98	sb     a3, $005e(s0)

8003D3AC	lui    v0, $8008
8003D3B0	lw     v0, $aecc(v0)
8003D3B4	nop
8003D3B8	lw     v1, $16d8(v0)
8003D3BC	lbu    a0, $16ed(v0)
8003D3C0	beq    v1, zero, L3d3f0 [$8003d3f0]
8003D3C4	nop

loop3d3c8:	; 8003D3C8
8003D3C8	lw     v0, $0004(v1)
8003D3CC	nop
8003D3D0	lbu    v0, $0007(v0)
8003D3D4	nop
8003D3D8	beq    v0, a0, L3d3f0 [$8003d3f0]
8003D3DC	nop
8003D3E0	lw     v1, $0000(v1)
8003D3E4	nop
8003D3E8	bne    v1, zero, loop3d3c8 [$8003d3c8]
8003D3EC	nop

L3d3f0:	; 8003D3F0
8003D3F0	beq    v1, zero, L3d3fc [$8003d3fc]
8003D3F4	addu   v0, zero, zero
8003D3F8	lw     v0, $0004(v1)

L3d3fc:	; 8003D3FC
8003D3FC	nop
8003D400	addu   s4, v0, zero
8003D404	beq    s4, zero, L3d518 [$8003d518]
8003D408	lui    v0, $8008
8003D40C	lw     v0, $b704(v0)
8003D410	nop
8003D414	addiu  a3, v0, $0018
8003D418	lh     v1, $0004(a3)
8003D41C	lh     a2, $0018(v0)
8003D420	nop
8003D424	subu   v1, v1, a2
8003D428	mult   v1, v1
8003D42C	lh     v0, $0006(a3)
8003D430	lh     t0, $0002(a3)
8003D434	mflo   a0
8003D438	subu   a1, v0, t0
8003D43C	nop
8003D440	mult   a1, a1
8003D444	mflo   t1
8003D448	addu   v0, a0, t1
8003D44C	sra    a0, v0, $08
8003D450	beq    a0, zero, L3d4d8 [$8003d4d8]
8003D454	mult   a0, v1
8003D458	lw     v0, $0014(s4)
8003D45C	nop
8003D460	subu   v0, v0, a2
8003D464	mult   v1, v0
8003D468	lw     v0, $001c(s4)
8003D46C	mflo   a2
8003D470	subu   v0, v0, t0
8003D474	nop
8003D478	mult   a1, v0
8003D47C	mflo   t0
8003D480	addu   v0, a2, t0
8003D484	nop
8003D488	div    v0, a0
8003D4B0	mflo   a0
8003D4B4	nop
8003D4B8	bgez   a0, L3d4c8 [$8003d4c8]
8003D4BC	slti   v0, a0, $0101
8003D4C0	j      L3d4d4 [$8003d4d4]
8003D4C4	addu   a0, zero, zero

L3d4c8:	; 8003D4C8
8003D4C8	bne    v0, zero, L3d4d8 [$8003d4d8]
8003D4CC	mult   a0, v1
8003D4D0	addiu  a0, zero, $0100

L3d4d4:	; 8003D4D4
8003D4D4	mult   a0, v1

L3d4d8:	; 8003D4D8
8003D4D8	mflo   t0
8003D4DC	nop
8003D4E0	nop
8003D4E4	mult   a0, a1
8003D4E8	lh     v1, $0000(a3)
8003D4EC	lui    a0, $8008
8003D4F0	sra    v0, t0, $08
8003D4F4	addu   v0, v0, v1
8003D4F8	sw     v0, $ae24(a0)
8003D4FC	lui    a0, $8008
8003D500	lh     v1, $0002(a3)
8003D504	mflo   a1
8003D508	sra    v0, a1, $08
8003D50C	addu   v0, v0, v1
8003D510	j      L39ea8 [$80039ea8]
8003D514	sw     v0, $ae28(a0)

L3d518:	; 8003D518
8003D518	lui    v0, $8008
8003D51C	sw     zero, $ae28(v0)
8003D520	lui    v0, $8008
8003D524	j      L39ea8 [$80039ea8]
8003D528	sw     zero, $ae24(v0)
8003D52C	lui    v0, $8008
8003D530	lw     v0, $aecc(v0)
8003D534	nop
8003D538	lw     v1, $16d8(v0)
8003D53C	lbu    a0, $16ed(v0)
8003D540	beq    v1, zero, L3d570 [$8003d570]
8003D544	nop

loop3d548:	; 8003D548
8003D548	lw     v0, $0004(v1)
8003D54C	nop
8003D550	lbu    v0, $0007(v0)
8003D554	nop
8003D558	beq    v0, a0, L3d570 [$8003d570]
8003D55C	nop
8003D560	lw     v1, $0000(v1)
8003D564	nop
8003D568	bne    v1, zero, loop3d548 [$8003d548]
8003D56C	nop

L3d570:	; 8003D570
8003D570	beq    v1, zero, L3d57c [$8003d57c]
8003D574	addu   v0, zero, zero
8003D578	lw     v0, $0004(v1)

L3d57c:	; 8003D57C
8003D57C	nop
8003D580	addu   s4, v0, zero
8003D584	beq    s4, zero, L39ea8 [$80039ea8]
8003D588	lui    a2, $8008
8003D58C	lbu    a1, $0009(s4)
8003D590	lbu    v1, $000a(s4)
8003D594	lw     a0, $aecc(a2)
8003D598	lw     v0, $0000(s4)
8003D59C	sll    a1, a1, $02
8003D5A0	addu   a1, s4, a1
8003D5A4	sll    v1, v1, $02
8003D5A8	lw     a0, $16f0(a0)
8003D5AC	addu   a1, a1, v1
8003D5B0	subu   v0, v0, a0
8003D5B4	sw     v0, $0000(a1)
8003D5B8	lui    v0, $8008
8003D5BC	lbu    v1, $0004(s4)
8003D5C0	lw     v0, $b70c(v0)
8003D5C4	lbu    a0, $000d(s4)
8003D5C8	sll    v1, v1, $08
8003D5CC	or     a0, a0, v1
8003D5D0	lbu    v0, $0007(v0)
8003D5D4	lui    v1, $00ff
8003D5D8	sll    v0, v0, $18
8003D5DC	or     v0, v0, v1
8003D5E0	or     a0, a0, v0
8003D5E4	sw     a0, $0004(a1)
8003D5E8	lbu    v0, $000a(s4)
8003D5EC	sb     zero, $0004(s4)
8003D5F0	sb     zero, $000d(s4)
8003D5F4	addiu  v0, v0, $0002
8003D5F8	sb     v0, $000a(s4)
8003D5FC	lui    v0, $8007
8003D600	lw     v1, $aecc(a2)
8003D604	addiu  v0, v0, $e658 (=-$19a8)
8003D608	sw     v0, $0000(s4)
8003D60C	sb     zero, $16ec(v1)
8003D610	lw     v0, $aecc(a2)
8003D614	nop
8003D618	lw     a0, $16d8(v0)
8003D61C	nop
8003D620	beq    a0, zero, L475b4 [$800475b4]
8003D624	addu   v0, zero, zero

loop3d628:	; 8003D628
8003D628	lw     v1, $0004(a0)
8003D62C	nop
8003D630	lbu    v0, $000f(v1)
8003D634	nop
8003D638	ori    v0, v0, $0006
8003D63C	sb     v0, $000f(v1)
8003D640	lw     a0, $0000(a0)
8003D644	nop
8003D648	bne    a0, zero, loop3d628 [$8003d628]
8003D64C	addu   v0, zero, zero
8003D650	j      L475b4 [$800475b4]
8003D654	nop
8003D658	lui    v0, $8008
8003D65C	lui    v1, $8008
8003D660	lw     s0, $b704(v0)
8003D664	lw     v0, $b6f4(v1)
8003D668	addiu  v1, zero, $0002
8003D66C	andi   v0, v0, $0001
8003D670	beq    v0, zero, L3d690 [$8003d690]
8003D674	sw     v1, $0014(s0)
8003D678	jal    func52da0 [$80052da0]
8003D67C	nop
8003D680	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003D684	nop
8003D688	j      L3d6cc [$8003d6cc]
8003D68C	addu   a2, v0, zero

L3d690:	; 8003D690
8003D690	lui    v0, $8008
8003D694	lw     a0, $b70c(v0)
8003D698	nop
8003D69C	lw     v0, $0000(a0)
8003D6A0	nop
8003D6A4	lbu    a2, $0000(v0)
8003D6A8	addiu  v0, v0, $0001
8003D6AC	sw     v0, $0000(a0)
8003D6B0	lbu    v1, $0000(v0)
8003D6B4	addiu  v0, v0, $0001
8003D6B8	sw     v0, $0000(a0)
8003D6BC	sll    v1, v1, $08
8003D6C0	or     a2, a2, v1
8003D6C4	sll    v0, a2, $10
8003D6C8	sra    a2, v0, $10

L3d6cc:	; 8003D6CC
8003D6CC	lui    a1, $8008
8003D6D0	lui    a0, $8008
8003D6D4	lw     v1, $b6f4(a1)
8003D6D8	addiu  v0, zero, $0001
8003D6DC	sw     v0, $b6f8(a0)
8003D6E0	sh     a2, $001c(s0)
8003D6E4	sh     a2, $0018(s0)
8003D6E8	srav   v1, v0, v1
8003D6EC	sw     v1, $b6f4(a1)
8003D6F0	and    v1, v1, v0
8003D6F4	beq    v1, zero, L3d714 [$8003d714]
8003D6F8	lui    v0, $8008
8003D6FC	jal    func52da0 [$80052da0]
8003D700	nop
8003D704	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003D708	nop
8003D70C	j      L3d74c [$8003d74c]
8003D710	addu   a3, v0, zero

L3d714:	; 8003D714
8003D714	lw     a0, $b70c(v0)
8003D718	nop
8003D71C	lw     v0, $0000(a0)
8003D720	nop
8003D724	lbu    a3, $0000(v0)
8003D728	addiu  v0, v0, $0001
8003D72C	sw     v0, $0000(a0)
8003D730	lbu    v1, $0000(v0)
8003D734	addiu  v0, v0, $0001
8003D738	sw     v0, $0000(a0)
8003D73C	sll    v1, v1, $08
8003D740	or     a3, a3, v1
8003D744	sll    v0, a3, $10
8003D748	sra    a3, v0, $10

L3d74c:	; 8003D74C
8003D74C	addu   v0, zero, zero
8003D750	lui    a2, $8008
8003D754	lui    a1, $8008
8003D758	lw     a0, $b6f4(a2)
8003D75C	addiu  v1, zero, $0001
8003D760	sw     v1, $b6f8(a1)
8003D764	sh     a3, $001e(s0)
8003D76C	sh     a3, $001a(s0)
8003EEE4	srav   a0, v1, a0
8003EEE8	j      L475b4 [$800475b4]
8003EEEC	sw     a0, $b6f4(a2)
8003D770	lui    v0, $8008
8003D774	lw     a0, $b704(v0)
8003D778	nop
8003D77C	lw     s2, $0014(a0)
8003D780	nop
8003D784	bgtz   s2, L3d790 [$8003d790]
8003D788	addu   v0, s2, zero
8003D78C	addiu  v0, zero, $0001

L3d790:	; 8003D790
8003D790	sll    v0, v0, $02
8003D794	addiu  v0, v0, $0014
8003D798	lui    v1, $8008
8003D79C	lw     v1, $b6f4(v1)
8003D7A0	nop
8003D7A4	andi   v1, v1, $0001
8003D7A8	beq    v1, zero, L3d7c8 [$8003d7c8]
8003D7AC	addu   s0, a0, v0
8003D7B0	jal    func52da0 [$80052da0]
8003D7B4	nop
8003D7B8	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003D7BC	nop
8003D7C0	j      L3d804 [$8003d804]
8003D7C4	addu   a2, v0, zero

L3d7c8:	; 8003D7C8
8003D7C8	lui    v0, $8008
8003D7CC	lw     a0, $b70c(v0)
8003D7D0	nop
8003D7D4	lw     v0, $0000(a0)
8003D7D8	nop
8003D7DC	lbu    a2, $0000(v0)
8003D7E0	addiu  v0, v0, $0001
8003D7E4	sw     v0, $0000(a0)
8003D7E8	lbu    v1, $0000(v0)
8003D7EC	addiu  v0, v0, $0001
8003D7F0	sw     v0, $0000(a0)
8003D7F4	sll    v1, v1, $08
8003D7F8	or     a2, a2, v1
8003D7FC	sll    v0, a2, $10
8003D800	sra    a2, v0, $10

L3d804:	; 8003D804
8003D804	lui    a1, $8008
8003D808	lui    a0, $8008
8003D80C	lw     v0, $b6f4(a1)
8003D810	addiu  v1, zero, $0001
8003D814	sw     v1, $b6f8(a0)
8003D818	sh     a2, $0000(s0)
8003D81C	srav   v0, v1, v0
8003D820	sw     v0, $b6f4(a1)
8003D824	and    v0, v0, v1
8003D828	beq    v0, zero, L3d848 [$8003d848]
8003D82C	lui    v0, $8008
8003D830	jal    func52da0 [$80052da0]
8003D834	nop
8003D838	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003D83C	nop
8003D840	j      L3d880 [$8003d880]
8003D844	addu   a3, v0, zero

L3d848:	; 8003D848
8003D848	lw     a0, $b70c(v0)
8003D84C	nop
8003D850	lw     v0, $0000(a0)
8003D854	nop
8003D858	lbu    a3, $0000(v0)
8003D85C	addiu  v0, v0, $0001
8003D860	sw     v0, $0000(a0)
8003D864	lbu    v1, $0000(v0)
8003D868	addiu  v0, v0, $0001
8003D86C	sw     v0, $0000(a0)
8003D870	sll    v1, v1, $08
8003D874	or     a3, a3, v1
8003D878	sll    v0, a3, $10
8003D87C	sra    a3, v0, $10

L3d880:	; 8003D880
8003D880	addu   v0, zero, zero
8003D884	lui    a2, $8008
8003D888	lui    a1, $8008
8003D88C	lw     a0, $b6f4(a2)
8003D890	addiu  v1, zero, $0001
8003D894	sw     v1, $b6f8(a1)
8003D89C	sh     a3, $0002(s0)
8003EEE4	srav   a0, v1, a0
8003EEE8	j      L475b4 [$800475b4]
8003EEEC	sw     a0, $b6f4(a2)
8003D8A0	lui    v0, $8008
8003D8A4	lw     a0, $b704(v0)
8003D8A8	nop
8003D8AC	lw     v1, $0014(a0)
8003D8B0	nop
8003D8B4	addiu  a1, v1, $ffff (=-$1)
8003D8B8	sltiu  v0, a1, $0007
8003D8BC	beq    v0, zero, L39ea8 [$80039ea8]
8003D8C0	sll    v1, v1, $02
8003D8C4	addu   v1, a0, v1
8003D8C8	sll    v0, a1, $02
8003D8CC	addu   v0, a0, v0
8003D8D0	lwl    t3, $001b(v0)
8003D8D4	lwr    t3, $0018(v0)
8003D8D8	nop
8003D8DC	swl    t3, $001b(v1)
8003D8E0	swr    t3, $0018(v1)
8003D8E4	lw     v0, $0014(a0)
8003D8E8	nop
8003D8EC	addiu  v0, v0, $0001
8003D8F0	j      L39ea8 [$80039ea8]
8003D8F4	sw     v0, $0014(a0)

8003D990	lui    v0, $8008
8003D994	lw     v0, $b6f4(v0)
8003D998	nop
8003D99C	andi   v0, v0, $0001
8003D9A0	beq    v0, zero, L3d9c0 [$8003d9c0]
8003D9A4	nop
8003D9A8	jal    func52da0 [$80052da0]
8003D9AC	nop
8003D9B0	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003D9B4	nop
8003D9B8	j      L3d9fc [$8003d9fc]
8003D9BC	addu   a1, v0, zero

L3d9c0:	; 8003D9C0
8003D9C0	lui    v0, $8008
8003D9C4	lw     a0, $b70c(v0)
8003D9C8	nop
8003D9CC	lw     v0, $0000(a0)
8003D9D0	nop
8003D9D4	lbu    a1, $0000(v0)
8003D9D8	addiu  v0, v0, $0001
8003D9DC	sw     v0, $0000(a0)
8003D9E0	lbu    v1, $0000(v0)
8003D9E4	addiu  v0, v0, $0001
8003D9E8	sw     v0, $0000(a0)
8003D9EC	sll    v1, v1, $08
8003D9F0	or     a1, a1, v1
8003D9F4	sll    v0, a1, $10
8003D9F8	sra    a1, v0, $10

L3d9fc:	; 8003D9FC
8003D9FC	addu   a0, a1, zero
8003DA00	lui    a2, $8008
8003DA04	lui    a1, $8008
8003DA08	lw     v0, $b6f4(a2)
8003DA0C	addiu  v1, zero, $0001
8003DA10	sw     v1, $b6f8(a1)
8003DA14	srav   v0, v1, v0
8003DA18	jal    func21640 [$80021640]
8003DA1C	sw     v0, $b6f4(a2)
8003DA20	j      L475b4 [$800475b4]
8003DA24	addiu  v0, zero, $0005
8003DA28	lui    v0, $8008
8003DA2C	lw     v0, $b6f4(v0)
8003DA30	nop
8003DA34	andi   v0, v0, $0001
8003DA38	beq    v0, zero, L3da58 [$8003da58]
8003DA3C	nop
8003DA40	jal    func52da0 [$80052da0]
8003DA44	nop
8003DA48	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DA4C	nop
8003DA50	j      L3da94 [$8003da94]
8003DA54	addu   a1, v0, zero

L3da58:	; 8003DA58
8003DA58	lui    v0, $8008
8003DA5C	lw     a0, $b70c(v0)
8003DA60	nop
8003DA64	lw     v0, $0000(a0)
8003DA68	nop
8003DA6C	lbu    a1, $0000(v0)
8003DA70	addiu  v0, v0, $0001
8003DA74	sw     v0, $0000(a0)
8003DA78	lbu    v1, $0000(v0)
8003DA7C	addiu  v0, v0, $0001
8003DA80	sw     v0, $0000(a0)
8003DA84	sll    v1, v1, $08
8003DA88	or     a1, a1, v1
8003DA8C	sll    v0, a1, $10
8003DA90	sra    a1, v0, $10

L3da94:	; 8003DA94
8003DA94	andi   a0, a1, $ffff
8003DA98	lui    a2, $8008
8003DA9C	lui    a1, $8008
8003DAA0	lw     v0, $b6f4(a2)
8003DAA4	addiu  v1, zero, $0001
8003DAA8	sw     v1, $b6f8(a1)
8003DAAC	srav   v0, v1, v0
8003DAB0	jal    func21680 [$80021680]
8003DAB4	sw     v0, $b6f4(a2)
8003DAB8	j      L475b4 [$800475b4]
8003DABC	addiu  v0, zero, $0007
8003DAC0	j      L475b4 [$800475b4]
8003DAC4	addiu  v0, zero, $0008

8003DB6C	lui    v1, $8008
8003DB70	lui    v0, $8008
8003DB74	lw     v0, $b6f4(v0)
8003DB78	nop
8003DB7C	andi   v0, v0, $0001
8003DB80	beq    v0, zero, L3dba0 [$8003dba0]
8003DB84	addiu  s0, v1, $bd2c (=-$42d4)
8003DB88	jal    func52da0 [$80052da0]
8003DB8C	nop
8003DB90	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DB94	nop
8003DB98	j      L3dbc0 [$8003dbc0]
8003DB9C	addu   a1, v0, zero

L3dba0:	; 8003DBA0
8003DBA0	lui    v0, $8008
8003DBA4	lw     v1, $b70c(v0)
8003DBA8	nop
8003DBAC	lw     v0, $0000(v1)
8003DBB0	nop
8003DBB4	lbu    a1, $0000(v0)
8003DBB8	addiu  v0, v0, $0001
8003DBBC	sw     v0, $0000(v1)

L3dbc0:	; 8003DBC0
8003DBC0	lui    v1, $8008
8003DBC4	lw     v0, $b6f4(v1)
8003DBC8	lui    a0, $8008
8003DBCC	sra    v0, v0, $01
8003DBD0	sw     v0, $b6f4(v1)
8003DBD4	addu   v1, v0, zero
8003DBD8	addiu  v0, zero, $0001
8003DBDC	and    v1, v1, v0
8003DBE0	sw     v0, $b6f8(a0)
8003DBE4	beq    v1, zero, L3dc04 [$8003dc04]
8003DBE8	sb     a1, $0000(s0)
8003DBEC	jal    func52da0 [$80052da0]
8003DBF0	nop
8003DBF4	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DBF8	nop
8003DBFC	j      L3dc24 [$8003dc24]
8003DC00	addu   a1, v0, zero

L3dc04:	; 8003DC04
8003DC04	lui    v0, $8008
8003DC08	lw     v1, $b70c(v0)
8003DC0C	nop
8003DC10	lw     v0, $0000(v1)
8003DC14	nop
8003DC18	lbu    a1, $0000(v0)
8003DC1C	addiu  v0, v0, $0001
8003DC20	sw     v0, $0000(v1)

L3dc24:	; 8003DC24
8003DC24	lui    v1, $8008
8003DC28	addiu  v0, zero, $0001
8003DC2C	sw     v0, $b6f8(v1)
8003DC30	lui    v1, $8008
8003DC34	lui    v0, $8006
8003DC38	lw     a0, $794c(v0)
8003DC3C	lw     v0, $b6f4(v1)
8003DC40	lw     a0, $001c(a0)
8003DC44	sra    v0, v0, $01
8003DC48	sw     v0, $b6f4(v1)
8003DC4C	sb     a1, $0848(a0)
8003DC50	lw     v0, $b6f4(v1)
8003DC54	nop
8003DC58	andi   v0, v0, $0001
8003DC5C	beq    v0, zero, L3dc7c [$8003dc7c]
8003DC60	nop
8003DC64	jal    func52da0 [$80052da0]
8003DC68	nop
8003DC6C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DC70	nop
8003DC74	j      L3dcb8 [$8003dcb8]
8003DC78	addu   a1, v0, zero

L3dc7c:	; 8003DC7C
8003DC7C	lui    v0, $8008
8003DC80	lw     a0, $b70c(v0)
8003DC84	nop
8003DC88	lw     v0, $0000(a0)
8003DC8C	nop
8003DC90	lbu    a1, $0000(v0)
8003DC94	addiu  v0, v0, $0001
8003DC98	sw     v0, $0000(a0)
8003DC9C	lbu    v1, $0000(v0)
8003DCA0	addiu  v0, v0, $0001
8003DCA4	sw     v0, $0000(a0)
8003DCA8	sll    v1, v1, $08
8003DCAC	or     a1, a1, v1
8003DCB0	sll    v0, a1, $10
8003DCB4	sra    a1, v0, $10

L3dcb8:	; 8003DCB8
8003DCB8	addu   s2, a1, zero
8003DCBC	andi   a0, s2, $7fff
8003DCC0	lui    a2, $8008
8003DCC4	lui    a1, $8008
8003DCC8	lw     v0, $b6f4(a2)
8003DCCC	addiu  v1, zero, $0001
8003DCD0	sw     v1, $b6f8(a1)
8003DCD4	srav   v0, v1, v0
8003DCD8	sw     v0, $b6f4(a2)
8003DCDC	lui    v0, $8006
8003DCE0	lw     v1, $794c(v0)
8003DCE4	sra    v0, s2, $0f
8003DCE8	lw     v1, $001c(v1)
8003DCEC	andi   v0, v0, $0001
8003DCF0	jal    func21660 [$80021660]
8003DCF4	sb     v0, $0571(v1)
8003DCF8	j      L475b4 [$800475b4]
8003DCFC	addiu  v0, zero, $0003
8003DD00	lui    v0, $8008
8003DD04	lw     v0, $b6f4(v0)
8003DD08	nop
8003DD0C	andi   v0, v0, $0001
8003DD10	beq    v0, zero, L3dd30 [$8003dd30]
8003DD14	lui    v0, $8008
8003DD18	jal    func52da0 [$80052da0]
8003DD1C	nop
8003DD20	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DD24	nop
8003DD28	j      L3dd4c [$8003dd4c]
8003DD2C	addu   a1, v0, zero

L3dd30:	; 8003DD30
8003DD30	lw     v1, $b70c(v0)
8003DD34	nop
8003DD38	lw     v0, $0000(v1)
8003DD3C	nop
8003DD40	lbu    a1, $0000(v0)
8003DD44	addiu  v0, v0, $0001
8003DD48	sw     v0, $0000(v1)

L3dd4c:	; 8003DD4C
8003DD4C	lui    v1, $8008
8003DD50	addiu  v0, zero, $0001
8003DD54	lui    a0, $8008
8003DD58	sw     v0, $b6f8(v1)
8003DD5C	lui    v1, $8008
8003DD60	lw     v0, $b6f4(a0)
8003DD64	lw     v1, $aecc(v1)
8003DD68	sra    v0, v0, $01
8003DD6C	sw     v0, $b6f4(a0)
8003DD70	andi   v0, a1, $00ff
8003DD74	bne    v0, zero, L39ea8 [$80039ea8]
8003DD78	sb     a1, $16ef(v1)
8003DD7C	lui    v0, $8008
8003DD80	j      L39ea8 [$80039ea8]
8003DD84	sw     zero, $ae50(v0)
8003DD88	lui    v0, $8008
8003DD8C	lw     v0, $b6f4(v0)
8003DD90	nop
8003DD94	andi   v0, v0, $0001
8003DD98	beq    v0, zero, L3ddb8 [$8003ddb8]
8003DD9C	lui    v0, $8008
8003DDA0	jal    func52da0 [$80052da0]
8003DDA4	nop
8003DDA8	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DDAC	nop
8003DDB0	j      L3ddd4 [$8003ddd4]
8003DDB4	addu   a1, v0, zero

L3ddb8:	; 8003DDB8
8003DDB8	lw     v1, $b70c(v0)
8003DDBC	nop
8003DDC0	lw     v0, $0000(v1)
8003DDC4	nop
8003DDC8	lbu    a1, $0000(v0)
8003DDCC	addiu  v0, v0, $0001
8003DDD0	sw     v0, $0000(v1)

L3ddd4:	; 8003DDD4
8003DDD4	lui    v1, $8008
8003DDD8	addiu  v0, zero, $0001
8003DDDC	lui    a0, $8008
8003DDE0	sw     v0, $b6f8(v1)
8003DDE4	lw     v0, $b6f4(a0)
8003DDE8	lui    v1, $8008
8003DDEC	sb     a1, $ae48(v1)
8003DDF0	sra    v0, v0, $01
8003DDF4	sw     v0, $b6f4(a0)
8003DDF8	andi   v0, v0, $0001
8003DDFC	beq    v0, zero, L3de1c [$8003de1c]
8003DE00	lui    v0, $8008
8003DE04	jal    func52da0 [$80052da0]
8003DE08	nop
8003DE0C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DE10	nop
8003DE14	j      L3de54 [$8003de54]
8003DE18	addu   a1, v0, zero

L3de1c:	; 8003DE1C
8003DE1C	lw     a0, $b70c(v0)
8003DE20	nop
8003DE24	lw     v0, $0000(a0)
8003DE28	nop
8003DE2C	lbu    a1, $0000(v0)
8003DE30	addiu  v0, v0, $0001
8003DE34	sw     v0, $0000(a0)
8003DE38	lbu    v1, $0000(v0)
8003DE3C	addiu  v0, v0, $0001
8003DE40	sw     v0, $0000(a0)
8003DE44	sll    v1, v1, $08
8003DE48	or     a1, a1, v1
8003DE4C	sll    v0, a1, $10
8003DE50	sra    a1, v0, $10

L3de54:	; 8003DE54
8003DE54	lui    v1, $8008
8003DE58	addiu  v0, zero, $0001
8003DE5C	lui    a0, $8008
8003DE60	sw     v0, $b6f8(v1)
8003DE64	lw     v0, $b6f4(a0)
8003DE68	lui    v1, $8008
8003DE6C	sh     a1, $ae40(v1)
8003DE70	sra    v0, v0, $01
8003DE74	sw     v0, $b6f4(a0)
8003DE78	andi   v0, v0, $0001
8003DE7C	beq    v0, zero, L3de9c [$8003de9c]
8003DE80	lui    v0, $8008
8003DE84	jal    func52da0 [$80052da0]
8003DE88	nop
8003DE8C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DE90	nop
8003DE94	j      L3ded4 [$8003ded4]
8003DE98	addu   a1, v0, zero

L3de9c:	; 8003DE9C
8003DE9C	lw     a0, $b70c(v0)
8003DEA0	nop
8003DEA4	lw     v0, $0000(a0)
8003DEA8	nop
8003DEAC	lbu    a1, $0000(v0)
8003DEB0	addiu  v0, v0, $0001
8003DEB4	sw     v0, $0000(a0)
8003DEB8	lbu    v1, $0000(v0)
8003DEBC	addiu  v0, v0, $0001
8003DEC0	sw     v0, $0000(a0)
8003DEC4	sll    v1, v1, $08
8003DEC8	or     a1, a1, v1
8003DECC	sll    v0, a1, $10
8003DED0	sra    a1, v0, $10

L3ded4:	; 8003DED4
8003DED4	lui    v1, $8008
8003DED8	addiu  v0, zero, $0001
8003DEDC	lui    a0, $8008
8003DEE0	sw     v0, $b6f8(v1)
8003DEE4	lw     v0, $b6f4(a0)
8003DEE8	lui    v1, $8008
8003DEEC	sh     a1, $ae42(v1)
8003DEF0	sra    v0, v0, $01
8003DEF4	sw     v0, $b6f4(a0)
8003DEF8	andi   v0, v0, $0001
8003DEFC	beq    v0, zero, L3df1c [$8003df1c]
8003DF00	lui    v0, $8008
8003DF04	jal    func52da0 [$80052da0]
8003DF08	nop
8003DF0C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DF10	nop
8003DF14	j      L3df54 [$8003df54]
8003DF18	addu   a1, v0, zero

L3df1c:	; 8003DF1C
8003DF1C	lw     a0, $b70c(v0)
8003DF20	nop
8003DF24	lw     v0, $0000(a0)
8003DF28	nop
8003DF2C	lbu    a1, $0000(v0)
8003DF30	addiu  v0, v0, $0001
8003DF34	sw     v0, $0000(a0)
8003DF38	lbu    v1, $0000(v0)
8003DF3C	addiu  v0, v0, $0001
8003DF40	sw     v0, $0000(a0)
8003DF44	sll    v1, v1, $08
8003DF48	or     a1, a1, v1
8003DF4C	sll    v0, a1, $10
8003DF50	sra    a1, v0, $10

L3df54:	; 8003DF54
8003DF54	lui    v1, $8008
8003DF58	addiu  v0, zero, $0001
8003DF5C	lui    a0, $8008
8003DF60	sw     v0, $b6f8(v1)
8003DF64	lw     v0, $b6f4(a0)
8003DF68	lui    v1, $8008
8003DF6C	sh     a1, $ae44(v1)
8003DF70	sra    v0, v0, $01
8003DF74	sw     v0, $b6f4(a0)
8003DF78	andi   v0, v0, $0001
8003DF7C	beq    v0, zero, L3df9c [$8003df9c]
8003DF80	lui    v0, $8008
8003DF84	jal    func52da0 [$80052da0]
8003DF88	nop
8003DF8C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003DF90	nop
8003DF94	j      L3dfd4 [$8003dfd4]
8003DF98	addu   a2, v0, zero

L3df9c:	; 8003DF9C
8003DF9C	lw     a0, $b70c(v0)
8003DFA0	nop
8003DFA4	lw     v0, $0000(a0)
8003DFA8	nop
8003DFAC	lbu    a2, $0000(v0)
8003DFB0	addiu  v0, v0, $0001
8003DFB4	sw     v0, $0000(a0)
8003DFB8	lbu    v1, $0000(v0)
8003DFBC	addiu  v0, v0, $0001
8003DFC0	sw     v0, $0000(a0)
8003DFC4	sll    v1, v1, $08
8003DFC8	or     a2, a2, v1
8003DFCC	sll    v0, a2, $10
8003DFD0	sra    a2, v0, $10

L3dfd4:	; 8003DFD4
8003DFD4	addu   v0, zero, zero
8003DFD8	lui    a0, $8008
8003DFDC	addiu  v1, zero, $0001
8003DFE0	lui    a1, $8008
8003DFE4	sw     v1, $b6f8(a0)
8003DFE8	lw     v1, $b6f4(a1)
8003DFEC	lui    a0, $8008
8003DFF0	sh     a2, $ae46(a0)

L3dff4:	; 8003DFF4
8003DFF4	sra    v1, v1, $01
8003DFF8	j      L475b4 [$800475b4]
8003DFFC	sw     v1, $b6f4(a1)

8003E1E8	lui    v0, $8008
8003E1EC	lw     a0, $b704(v0)
8003E1F0	nop
8003E1F4	beq    a0, zero, L3e22c [$8003e22c]
8003E1F8	ori    v0, zero, $ffff
8003E1FC	lhu    v1, $0034(a0)
8003E200	nop
8003E204	beq    v1, v0, L3e230 [$8003e230]
8003E208	addu   s0, zero, zero
8003E20C	lbu    a0, $003b(a0)
8003E210	jal    func1e350 [$8001e350]
8003E214	nop
8003E218	beq    v0, zero, L3e230 [$8003e230]
8003E21C	nop
8003E220	lw     s0, $0008(v0)
8003E224	j      L3e234 [$8003e234]
8003E228	lui    v0, $8008

L3e22c:	; 8003E22C
8003E22C	addu   s0, zero, zero

L3e230:	; 8003E230
8003E230	lui    v0, $8008

L3e234:	; 8003E234
8003E234	lw     v0, $b6f4(v0)
8003E238	nop
8003E23C	andi   v0, v0, $0001
8003E240	beq    v0, zero, L3e260 [$8003e260]
8003E244	lui    v0, $8008
8003E248	jal    func52da0 [$80052da0]
8003E24C	nop
8003E250	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E254	nop
8003E258	j      L3e298 [$8003e298]
8003E25C	addu   a1, v0, zero

L3e260:	; 8003E260
8003E260	lw     a0, $b70c(v0)
8003E264	nop
8003E268	lw     v0, $0000(a0)
8003E26C	nop
8003E270	lbu    a1, $0000(v0)
8003E274	addiu  v0, v0, $0001
8003E278	sw     v0, $0000(a0)
8003E27C	lbu    v1, $0000(v0)
8003E280	addiu  v0, v0, $0001
8003E284	sw     v0, $0000(a0)
8003E288	sll    v1, v1, $08
8003E28C	or     a1, a1, v1
8003E290	sll    v0, a1, $10
8003E294	sra    a1, v0, $10

L3e298:	; 8003E298
8003E298	addu   s2, a1, zero
8003E29C	lui    a1, $8008
8003E2A0	lui    a0, $8008
8003E2A4	lw     v0, $b6f4(a1)
8003E2A8	addiu  v1, zero, $0001
8003E2AC	sw     v1, $b6f8(a0)
8003E2B0	srav   v0, v1, v0
8003E2B4	sw     v0, $b6f4(a1)
8003E2B8	and    v0, v0, v1
8003E2BC	beq    v0, zero, L3e2dc [$8003e2dc]
8003E2C0	lui    v0, $8008
8003E2C4	jal    func52da0 [$80052da0]
8003E2C8	nop
8003E2CC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E2D0	nop
8003E2D4	j      L3e314 [$8003e314]
8003E2D8	addu   a1, v0, zero

L3e2dc:	; 8003E2DC
8003E2DC	lw     a0, $b70c(v0)
8003E2E0	nop
8003E2E4	lw     v0, $0000(a0)
8003E2E8	nop
8003E2EC	lbu    a1, $0000(v0)
8003E2F0	addiu  v0, v0, $0001
8003E2F4	sw     v0, $0000(a0)
8003E2F8	lbu    v1, $0000(v0)
8003E2FC	addiu  v0, v0, $0001
8003E300	sw     v0, $0000(a0)
8003E304	sll    v1, v1, $08
8003E308	or     a1, a1, v1
8003E30C	sll    v0, a1, $10
8003E310	sra    a1, v0, $10

L3e314:	; 8003E314
8003E314	addu   s3, a1, zero
8003E318	lui    a1, $8008
8003E31C	lui    a0, $8008
8003E320	lw     v0, $b6f4(a1)
8003E324	addiu  v1, zero, $0001
8003E328	sw     v1, $b6f8(a0)
8003E32C	srav   v0, v1, v0
8003E330	sw     v0, $b6f4(a1)
8003E334	and    v0, v0, v1
8003E338	beq    v0, zero, L3e358 [$8003e358]
8003E33C	lui    v0, $8008
8003E340	jal    func52da0 [$80052da0]
8003E344	nop
8003E348	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E34C	nop
8003E350	j      L3e390 [$8003e390]
8003E354	addu   a2, v0, zero

L3e358:	; 8003E358
8003E358	lw     a0, $b70c(v0)
8003E35C	nop
8003E360	lw     v0, $0000(a0)
8003E364	nop
8003E368	lbu    a2, $0000(v0)
8003E36C	addiu  v0, v0, $0001
8003E370	sw     v0, $0000(a0)
8003E374	lbu    v1, $0000(v0)
8003E378	addiu  v0, v0, $0001
8003E37C	sw     v0, $0000(a0)
8003E380	sll    v1, v1, $08
8003E384	or     a2, a2, v1
8003E388	sll    v0, a2, $10
8003E38C	sra    a2, v0, $10

L3e390:	; 8003E390
8003E390	addu   s5, a2, zero
8003E394	lui    a1, $8008
8003E398	lui    a0, $8008
8003E39C	lw     v0, $b6f4(a1)
8003E3A0	addiu  v1, zero, $0001
8003E3A4	sw     v1, $b6f8(a0)
8003E3A8	srav   v0, v1, v0
8003E3AC	beq    s0, zero, L39ea8 [$80039ea8]
8003E3B0	sw     v0, $b6f4(a1)
8003E3B4	sh     s2, $0074(s0)
8003E3B8	sh     s3, $0076(s0)
8003E3BC	j      L39ea8 [$80039ea8]
8003E3C0	sh     s5, $0078(s0)
8003E3C4	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003E3C8	nop
8003E3CC	addu   a0, v0, zero
8003E3D0	beq    a0, zero, L3e408 [$8003e408]
8003E3D4	ori    v0, zero, $ffff
8003E3D8	lhu    v1, $0034(a0)
8003E3DC	nop
8003E3E0	beq    v1, v0, L3e40c [$8003e40c]
8003E3E4	addu   s0, zero, zero
8003E3E8	lbu    a0, $003b(a0)
8003E3EC	jal    func1e350 [$8001e350]
8003E3F0	nop
8003E3F4	beq    v0, zero, L3e40c [$8003e40c]
8003E3F8	nop
8003E3FC	lw     s0, $0008(v0)
8003E400	j      L3e40c [$8003e40c]
8003E404	nop

L3e408:	; 8003E408
8003E408	addu   s0, zero, zero

L3e40c:	; 8003E40C
8003E40C	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003E410	nop
8003E414	addu   a0, v0, zero
8003E418	beq    a0, zero, L3e450 [$8003e450]
8003E41C	ori    v0, zero, $ffff
8003E420	lhu    v1, $0034(a0)
8003E424	nop
8003E428	beq    v1, v0, L3e454 [$8003e454]
8003E42C	addu   s1, zero, zero
8003E430	lbu    a0, $003b(a0)
8003E434	jal    func1e350 [$8001e350]
8003E438	nop
8003E43C	beq    v0, zero, L3e454 [$8003e454]
8003E440	nop
8003E444	lw     s1, $0008(v0)
8003E448	j      L3e458 [$8003e458]
8003E44C	lui    v0, $8008

L3e450:	; 8003E450
8003E450	addu   s1, zero, zero

L3e454:	; 8003E454
8003E454	lui    v0, $8008

L3e458:	; 8003E458
8003E458	lw     v0, $b6f4(v0)
8003E45C	nop
8003E460	andi   v0, v0, $0001
8003E464	beq    v0, zero, L3e484 [$8003e484]
8003E468	lui    v0, $8008
8003E46C	jal    func52da0 [$80052da0]
8003E470	nop
8003E474	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E478	nop
8003E47C	j      L3e4a0 [$8003e4a0]
8003E480	addu   a0, v0, zero

L3e484:	; 8003E484
8003E484	lw     v1, $b70c(v0)
8003E488	nop
8003E48C	lw     v0, $0000(v1)
8003E490	nop
8003E494	lbu    a0, $0000(v0)
8003E498	addiu  v0, v0, $0001
8003E49C	sw     v0, $0000(v1)

L3e4a0:	; 8003E4A0
8003E4A0	addu   s2, a0, zero
8003E4A4	lui    a1, $8008
8003E4A8	lui    a0, $8008
8003E4AC	lw     v0, $b6f4(a1)
8003E4B0	addiu  v1, zero, $0001
8003E4B4	sw     v1, $b6f8(a0)
8003E4B8	srav   v0, v1, v0
8003E4BC	beq    s0, zero, L39ea8 [$80039ea8]
8003E4C0	sw     v0, $b6f4(a1)
8003E4C4	beq    s1, zero, L475b4 [$800475b4]
8003E4C8	addu   v0, zero, zero
8003E4CC	sw     s1, $001c(s0)
8003E4D0	j      L475b4 [$800475b4]
8003E4D4	sb     s2, $0004(s0)
8003E4D8	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003E4DC	nop
8003E4E0	addu   a0, v0, zero
8003E4E4	beq    a0, zero, L3e51c [$8003e51c]
8003E4E8	ori    v0, zero, $ffff
8003E4EC	lhu    v1, $0034(a0)
8003E4F0	nop
8003E4F4	beq    v1, v0, L3e520 [$8003e520]
8003E4F8	addu   s0, zero, zero
8003E4FC	lbu    a0, $003b(a0)
8003E500	jal    func1e350 [$8001e350]
8003E504	nop
8003E508	beq    v0, zero, L3e520 [$8003e520]
8003E50C	nop
8003E510	lw     s0, $0008(v0)
8003E514	j      L3e520 [$8003e520]
8003E518	nop

L3e51c:	; 8003E51C
8003E51C	addu   s0, zero, zero

L3e520:	; 8003E520
8003E520	beq    s0, zero, L475b4 [$800475b4]
8003E524	addu   v0, zero, zero
8003E528	j      L475b4 [$800475b4]
8003E52C	sw     zero, $001c(s0)

8003E6E0	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003E6E4	nop
8003E6E8	addu   a0, v0, zero
8003E6EC	beq    a0, zero, L3e724 [$8003e724]
8003E6F0	ori    v0, zero, $ffff
8003E6F4	lhu    v1, $0034(a0)
8003E6F8	nop
8003E6FC	beq    v1, v0, L3e728 [$8003e728]
8003E700	addu   s0, zero, zero
8003E704	lbu    a0, $003b(a0)
8003E708	jal    func1e350 [$8001e350]
8003E70C	nop
8003E710	beq    v0, zero, L3e728 [$8003e728]
8003E714	nop
8003E718	lw     s0, $0008(v0)
8003E71C	j      L3e72c [$8003e72c]
8003E720	lui    v0, $8008

L3e724:	; 8003E724
8003E724	addu   s0, zero, zero

L3e728:	; 8003E728
8003E728	lui    v0, $8008

L3e72c:	; 8003E72C
8003E72C	lw     v0, $b6f4(v0)
8003E730	nop
8003E734	andi   v0, v0, $0001
8003E738	beq    v0, zero, L3e758 [$8003e758]
8003E73C	lui    v0, $8008
8003E740	jal    func52da0 [$80052da0]
8003E744	nop
8003E748	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E74C	nop
8003E750	j      L3e774 [$8003e774]
8003E754	addu   a0, v0, zero

L3e758:	; 8003E758
8003E758	lw     v1, $b70c(v0)
8003E75C	nop
8003E760	lw     v0, $0000(v1)
8003E764	nop
8003E768	lbu    a0, $0000(v0)
8003E76C	addiu  v0, v0, $0001
8003E770	sw     v0, $0000(v1)

L3e774:	; 8003E774
8003E774	addu   s3, a0, zero
8003E778	lui    a1, $8008
8003E77C	lui    a0, $8008
8003E780	lw     v0, $b6f4(a1)
8003E784	addiu  v1, zero, $0001
8003E788	sw     v1, $b6f8(a0)
8003E78C	srav   v0, v1, v0
8003E790	beq    s0, zero, L39ea8 [$80039ea8]
8003E794	sw     v0, $b6f4(a1)
8003E798	sll    v1, s3, $02
8003E79C	addu   v1, v1, s3
8003E7A0	lw     a0, $0050(s0)
8003E7A4	sll    v1, v1, $02
8003E7A8	addu   a0, a0, v1
8003E7AC	lbu    v0, $0004(a0)
8003E7B0	nop
8003E7B4	ori    v0, v0, $0001
8003E7B8	sb     v0, $0004(a0)
8003E7BC	lw     v0, $0050(s0)
8003E7C0	nop
8003E7C4	addu   v0, v0, v1
8003E7C8	sw     zero, $000c(v0)
8003E7CC	lw     v0, $0050(s0)
8003E7D0	nop
8003E7D4	addu   v0, v0, v1
8003E7D8	addiu  v1, zero, $1000
8003E7DC	j      L39ea8 [$80039ea8]
8003E7E0	sh     v1, $0012(v0)
8003E7E4	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003E7E8	nop
8003E7EC	addu   a0, v0, zero
8003E7F0	beq    a0, zero, L3e828 [$8003e828]
8003E7F4	ori    v0, zero, $ffff
8003E7F8	lhu    v1, $0034(a0)
8003E7FC	nop
8003E800	beq    v1, v0, L3e82c [$8003e82c]
8003E804	addu   s0, zero, zero
8003E808	lbu    a0, $003b(a0)
8003E80C	jal    func1e350 [$8001e350]
8003E810	nop
8003E814	beq    v0, zero, L3e82c [$8003e82c]
8003E818	nop
8003E81C	lw     s0, $0008(v0)
8003E820	j      L3e830 [$8003e830]
8003E824	lui    v0, $8008

L3e828:	; 8003E828
8003E828	addu   s0, zero, zero

L3e82c:	; 8003E82C
8003E82C	lui    v0, $8008

L3e830:	; 8003E830
8003E830	lw     v0, $b6f4(v0)
8003E834	nop
8003E838	andi   v0, v0, $0001
8003E83C	beq    v0, zero, L3e85c [$8003e85c]
8003E840	lui    v0, $8008
8003E844	jal    func52da0 [$80052da0]
8003E848	nop
8003E84C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E850	nop
8003E854	j      L3e878 [$8003e878]
8003E858	addu   a0, v0, zero

L3e85c:	; 8003E85C
8003E85C	lw     v1, $b70c(v0)
8003E860	nop
8003E864	lw     v0, $0000(v1)
8003E868	nop
8003E86C	lbu    a0, $0000(v0)
8003E870	addiu  v0, v0, $0001
8003E874	sw     v0, $0000(v1)

L3e878:	; 8003E878
8003E878	addu   s3, a0, zero
8003E87C	lui    a1, $8008
8003E880	lui    a0, $8008
8003E884	lw     v0, $b6f4(a1)
8003E888	addiu  v1, zero, $0001
8003E88C	sw     v1, $b6f8(a0)
8003E890	srav   v0, v1, v0
8003E894	beq    s0, zero, L39ea8 [$80039ea8]
8003E898	sw     v0, $b6f4(a1)
8003E89C	sll    v1, s3, $02
8003E8A0	addu   v1, v1, s3
8003E8A4	lw     a0, $0050(s0)
8003E8A8	sll    v1, v1, $02
8003E8AC	addu   a0, a0, v1
8003E8B0	lbu    v0, $0004(a0)
8003E8B4	nop
8003E8B8	ori    v0, v0, $0003
8003E8BC	sb     v0, $0004(a0)
8003E8C0	lw     v0, $0050(s0)
8003E8C4	nop
8003E8C8	addu   v0, v0, v1
8003E8CC	sw     zero, $000c(v0)
8003E8D0	lw     v0, $0050(s0)
8003E8D4	nop
8003E8D8	addu   v0, v0, v1
8003E8DC	addiu  v1, zero, $1000
8003E8E0	j      L39ea8 [$80039ea8]
8003E8E4	sh     v1, $0012(v0)
8003E8E8	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003E8EC	nop
8003E8F0	addu   a0, v0, zero
8003E8F4	beq    a0, zero, L3e92c [$8003e92c]
8003E8F8	ori    v0, zero, $ffff
8003E8FC	lhu    v1, $0034(a0)
8003E900	nop
8003E904	beq    v1, v0, L3e930 [$8003e930]
8003E908	addu   s0, zero, zero
8003E90C	lbu    a0, $003b(a0)
8003E910	jal    func1e350 [$8001e350]
8003E914	nop
8003E918	beq    v0, zero, L3e930 [$8003e930]
8003E91C	nop
8003E920	lw     s0, $0008(v0)
8003E924	j      L3e934 [$8003e934]
8003E928	lui    v0, $8008

L3e92c:	; 8003E92C
8003E92C	addu   s0, zero, zero

L3e930:	; 8003E930
8003E930	lui    v0, $8008

L3e934:	; 8003E934
8003E934	lw     v0, $b6f4(v0)
8003E938	nop
8003E93C	andi   v0, v0, $0001
8003E940	beq    v0, zero, L3e960 [$8003e960]
8003E944	lui    v0, $8008
8003E948	jal    func52da0 [$80052da0]
8003E94C	nop
8003E950	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E954	nop
8003E958	j      L3e97c [$8003e97c]
8003E95C	addu   a0, v0, zero

L3e960:	; 8003E960
8003E960	lw     v1, $b70c(v0)
8003E964	nop
8003E968	lw     v0, $0000(v1)
8003E96C	nop
8003E970	lbu    a0, $0000(v0)
8003E974	addiu  v0, v0, $0001
8003E978	sw     v0, $0000(v1)

L3e97c:	; 8003E97C
8003E97C	addu   s3, a0, zero
8003E980	lui    a1, $8008
8003E984	lui    a0, $8008
8003E988	lw     v0, $b6f4(a1)
8003E98C	addiu  v1, zero, $0001
8003E990	sw     v1, $b6f8(a0)
8003E994	srav   v0, v1, v0
8003E998	beq    s0, zero, L39ea8 [$80039ea8]
8003E99C	sw     v0, $b6f4(a1)
8003E9A0	sll    v0, s3, $02
8003E9A4	addu   v0, v0, s3
8003E9A8	lw     v1, $0050(s0)
8003E9AC	sll    v0, v0, $02
8003E9B0	addu   v1, v1, v0
8003E9B4	lbu    v0, $0004(v1)
8003E9B8	nop
8003E9BC	andi   v0, v0, $00fc
8003E9C0	j      L39ea8 [$80039ea8]
8003E9C4	sb     v0, $0004(v1)
8003E9C8	lbu    a0, $003b(s4)
8003E9CC	jal    func1e350 [$8001e350]
8003E9D0	nop
8003E9D4	lui    v1, $8008
8003E9D8	lw     v1, $b6f4(v1)
8003E9DC	nop
8003E9E0	andi   v1, v1, $0001
8003E9E4	beq    v1, zero, L3ea04 [$8003ea04]
8003E9E8	addu   s0, v0, zero
8003E9EC	jal    func52da0 [$80052da0]
8003E9F0	nop
8003E9F4	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003E9F8	nop
8003E9FC	j      L3ea40 [$8003ea40]
8003EA00	addu   a2, v0, zero

L3ea04:	; 8003EA04
8003EA04	lui    v0, $8008
8003EA08	lw     a0, $b70c(v0)
8003EA0C	nop
8003EA10	lw     v0, $0000(a0)
8003EA14	nop
8003EA18	lbu    a2, $0000(v0)
8003EA1C	addiu  v0, v0, $0001
8003EA20	sw     v0, $0000(a0)
8003EA24	lbu    v1, $0000(v0)
8003EA28	addiu  v0, v0, $0001
8003EA2C	sw     v0, $0000(a0)
8003EA30	sll    v1, v1, $08
8003EA34	or     a2, a2, v1
8003EA38	sll    v0, a2, $10
8003EA3C	sra    a2, v0, $10

L3ea40:	; 8003EA40
8003EA40	addu   v0, zero, zero
8003EA44	lui    a0, $8008
8003EA48	addiu  v1, zero, $0001
8003EA4C	lui    a1, $8008
8003EA50	sw     v1, $b6f8(a0)
8003EA54	lw     v1, $b6f4(a1)
8003EA58	lw     a0, $0000(s0)
8003EA5C	sra    v1, v1, $01
8003EA60	or     a0, a0, a2
8003EA64	sw     v1, $b6f4(a1)
8003EA68	j      L475b4 [$800475b4]
8003EA6C	sw     a0, $0000(s0)
8003EA70	lbu    a0, $003b(s4)
8003EA74	jal    func1e350 [$8001e350]
8003EA78	nop
8003EA7C	lui    v1, $8008
8003EA80	lw     v1, $b6f4(v1)
8003EA84	nop
8003EA88	andi   v1, v1, $0001
8003EA8C	beq    v1, zero, L3eaac [$8003eaac]
8003EA90	addu   s0, v0, zero
8003EA94	jal    func52da0 [$80052da0]
8003EA98	nop
8003EA9C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003EAA0	nop
8003EAA4	j      L3eae8 [$8003eae8]
8003EAA8	addu   a3, v0, zero

L3eaac:	; 8003EAAC
8003EAAC	lui    v0, $8008
8003EAB0	lw     a0, $b70c(v0)
8003EAB4	nop
8003EAB8	lw     v0, $0000(a0)
8003EABC	nop
8003EAC0	lbu    a3, $0000(v0)
8003EAC4	addiu  v0, v0, $0001
8003EAC8	sw     v0, $0000(a0)
8003EACC	lbu    v1, $0000(v0)
8003EAD0	addiu  v0, v0, $0001
8003EAD4	sw     v0, $0000(a0)
8003EAD8	sll    v1, v1, $08
8003EADC	or     a3, a3, v1
8003EAE0	sll    v0, a3, $10
8003EAE4	sra    a3, v0, $10

L3eae8:	; 8003EAE8
8003EAE8	addu   v0, zero, zero
8003EAEC	lui    a2, $8008
8003EAF0	lui    a1, $8008
8003EAF4	lw     v1, $b6f4(a2)
8003EAF8	addiu  a0, zero, $0001
8003EAFC	sw     a0, $b6f8(a1)
8003EB00	srav   v1, a0, v1
8003EB04	sw     v1, $b6f4(a2)
8003EB08	lw     v1, $0000(s0)
8003EB0C	nor    a0, zero, a3
8003EB10	and    v1, v1, a0
8003EB14	j      L475b4 [$800475b4]
8003EB18	sw     v1, $0000(s0)
8003EB1C	lui    v0, $8008
8003EB20	lw     v0, $b70c(v0)
8003EB24	nop
8003EB28	lw     v0, $0000(v0)
8003EB2C	nop
8003EB30	addiu  v1, v0, $ffff (=-$1)
8003EB34	sw     v1, $0028(sp)
8003EB38	lbu    v1, $ffff(v0)
8003EB3C	nop
8003EB40	beq    v1, zero, L3eb60 [$8003eb60]
8003EB44	sw     v0, $0028(sp)

loop3eb48:	; 8003EB48
8003EB48	lw     v0, $0028(sp)
8003EB4C	nop
8003EB50	lbu    v1, $0000(v0)
8003EB54	addiu  v0, v0, $0001
8003EB58	bne    v1, zero, loop3eb48 [$8003eb48]
8003EB5C	sw     v0, $0028(sp)

L3eb60:	; 8003EB60
8003EB60	jal    func52d0c [$80052d0c]
8003EB64	addiu  a0, sp, $0028
8003EB68	addu   v0, zero, zero
8003EB6C	lui    a0, $8008
8003EB70	addiu  v1, zero, $0001
8003EB74	sw     v1, $b6f8(a0)
8003EB78	lui    a0, $8008
8003EB7C	lw     v1, $0028(sp)
8003EB80	lw     a0, $b70c(a0)
8003EB84	addiu  v1, v1, $0001
8003EB88	j      L475b4 [$800475b4]
8003EB8C	sw     v1, $0000(a0)
8003EB90	addiu  v0, zero, $0006
8003EB94	lui    v1, $8008
8003EB98	lw     a2, $b70c(v1)
8003EB9C	lui    a1, $8008
8003EBA0	lw     v1, $0000(a2)
8003EBA4	addiu  a0, zero, $0001
8003EBA8	sw     a0, $b6f8(a1)
8003EBAC	addu   v1, v1, a0
8003EBB0	j      L475b4 [$800475b4]
8003EBB4	sw     v1, $0000(a2)

8003F048	lui    v0, $8008
8003F04C	lw     v0, $b6f4(v0)
8003F050	nop
8003F054	andi   v0, v0, $0001
8003F058	beq    v0, zero, L3f078 [$8003f078]
8003F05C	lui    v0, $8008
8003F060	jal    func52da0 [$80052da0]
8003F064	nop
8003F068	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003F06C	nop
8003F070	j      L3f094 [$8003f094]
8003F074	addu   a2, v0, zero

L3f078:	; 8003F078
8003F078	lw     v1, $b70c(v0)
8003F07C	nop
8003F080	lw     v0, $0000(v1)
8003F084	nop
8003F088	lbu    a2, $0000(v0)
8003F08C	addiu  v0, v0, $0001
8003F090	sw     v0, $0000(v1)

L3f094:	; 8003F094
8003F094	lui    a0, $8008
8003F098	lui    a1, $8008
8003F09C	lw     v0, $b6f4(a0)
8003F0A0	addiu  v1, zero, $0001
8003F0A4	sw     v1, $b6f8(a1)
8003F0A8	srav   v0, v1, v0
8003F0AC	sw     v0, $b6f4(a0)
8003F0B0	sll    v0, a2, $03
8003F0B4	andi   v0, v0, $0038
8003F0B8	sb     v0, $0062(s0)
8003F0BC	lw     v0, $b6f4(a0)
8003F0C0	nop
8003F0C4	and    v0, v0, v1
8003F0C8	beq    v0, zero, L3f0e8 [$8003f0e8]
8003F0CC	lui    v0, $8008

L3f0d0:	; 8003F0D0
8003F0D0	jal    func52da0 [$80052da0]
8003F0D4	nop
8003F0D8	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003F0DC	nop
8003F0E0	j      L3f104 [$8003f104]
8003F0E4	addu   a3, v0, zero

L3f0e8:	; 8003F0E8
8003F0E8	lw     v1, $b70c(v0)
8003F0EC	nop
8003F0F0	lw     v0, $0000(v1)
8003F0F4	nop
8003F0F8	lbu    a3, $0000(v0)
8003F0FC	addiu  v0, v0, $0001
8003F100	sw     v0, $0000(v1)

L3f104:	; 8003F104
8003F104	addu   v0, zero, zero
8003F108	lui    a2, $8008
8003F10C	lui    a1, $8008
8003F110	lw     v1, $b6f4(a2)
8003F114	addiu  a0, zero, $0001
8003F118	sw     a0, $b6f8(a1)
8003F11C	srav   v1, a0, v1
8003F120	sw     v1, $b6f4(a2)
8003F124	j      L475b4 [$800475b4]
8003F128	sb     a3, $0063(s0)
8003F12C	lui    v0, $8008
8003F130	lw     v0, $b6f4(v0)
8003F134	nop
8003F138	andi   v0, v0, $0001
8003F13C	beq    v0, zero, L3f15c [$8003f15c]
8003F140	lui    v0, $8008
8003F144	jal    func52da0 [$80052da0]
8003F148	nop
8003F14C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003F150	nop
8003F154	j      L3f178 [$8003f178]
8003F158	addu   a3, v0, zero

L3f15c:	; 8003F15C
8003F15C	lw     v1, $b70c(v0)
8003F160	nop
8003F164	lw     v0, $0000(v1)
8003F168	nop
8003F16C	lbu    a3, $0000(v0)
8003F170	addiu  v0, v0, $0001
8003F174	sw     v0, $0000(v1)

L3f178:	; 8003F178
8003F178	addu   v0, zero, zero
8003F17C	lui    a2, $8008
8003F180	lui    a1, $8008
8003F184	lw     v1, $b6f4(a2)
8003F188	addiu  a0, zero, $0001
8003F18C	sw     a0, $b6f8(a1)
8003F190	srav   v1, a0, v1
8003F194	sw     v1, $b6f4(a2)
8003F198	j      L475b4 [$800475b4]
8003F19C	sb     a3, $0069(s0)

8003F59C	jal    func499d8 [$800499d8]
8003F5A0	addu   a0, s0, zero
8003F5A4	j      L475b4 [$800475b4]
8003F5A8	addu   v0, zero, zero
8003F5AC	jal    system_get_entity_script_data_pointer_from_script [$80038150]
8003F5B0	nop
8003F5B4	addu   s1, v0, zero
8003F5B8	beq    s1, zero, L39ea8 [$80039ea8]
8003F5BC	nop
8003F5C0	beq    s1, s4, L3f5d4 [$8003f5d4]
8003F5C4	addiu  v0, zero, $0080
8003F5C8	sw     s1, $00a0(s0)
8003F5CC	j      L39ea8 [$80039ea8]
8003F5D0	sb     v0, $0062(s0)

L3f5d4:	; 8003F5D4
8003F5D4	sw     zero, $00a0(s0)
8003F5D8	j      L39ea8 [$80039ea8]
8003F5DC	sb     zero, $0062(s0)

8003F6CC	lui    v0, $8008
8003F6D0	lui    v1, $8008
8003F6D4	lw     v0, $b70c(v0)
8003F6D8	lw     v1, $aecc(v1)
8003F6DC	lbu    v0, $0007(v0)
8003F6E0	lw     v1, $16d8(v1)
8003F6E4	nop
8003F6E8	beq    v1, zero, L3f718 [$8003f718]
8003F6EC	addiu  a0, v0, $0040

loop3f6f0:	; 8003F6F0
8003F6F0	lw     v0, $0004(v1)
8003F6F4	nop
8003F6F8	lbu    v0, $0007(v0)
8003F6FC	nop
8003F700	beq    v0, a0, L3f718 [$8003f718]
8003F704	nop
8003F708	lw     v1, $0000(v1)
8003F70C	nop
8003F710	bne    v1, zero, loop3f6f0 [$8003f6f0]
8003F714	nop

L3f718:	; 8003F718
8003F718	beq    v1, zero, L3f724 [$8003f724]
8003F71C	addu   v0, zero, zero
8003F720	lw     v0, $0004(v1)

L3f724:	; 8003F724
8003F724	nop
8003F728	beq    v0, zero, L475b4 [$800475b4]
8003F72C	addu   v0, zero, zero

L3f730:	; 8003F730
8003F730	addiu  v0, zero, $0001
8003F734	lui    v1, $8008
8003F738	lui    a0, $8008
8003F73C	lui    a1, $8008
8003F740	lw     a2, $b70c(v1)
8003F744	lw     a0, $aea0(a0)
8003F748	addu   v1, v0, zero
8003F74C	sw     v1, $b6f8(a1)
8003F750	j      L475b4 [$800475b4]
8003F754	sw     a0, $0000(a2)
8003F758	lui    v0, $8008
8003F75C	lui    v1, $8008
8003F760	lw     v0, $b70c(v0)
8003F764	lw     v1, $aecc(v1)
8003F768	lbu    v0, $0007(v0)
8003F76C	lw     v1, $16d8(v1)
8003F770	nop
8003F774	beq    v1, zero, L3f7a4 [$8003f7a4]
8003F778	addiu  a0, v0, $0040

loop3f77c:	; 8003F77C
8003F77C	lw     v0, $0004(v1)
8003F780	nop
8003F784	lbu    v0, $0007(v0)
8003F788	nop
8003F78C	beq    v0, a0, L3f7a4 [$8003f7a4]
8003F790	nop
8003F794	lw     v1, $0000(v1)
8003F798	nop
8003F79C	bne    v1, zero, loop3f77c [$8003f77c]
8003F7A0	nop

L3f7a4:	; 8003F7A4
8003F7A4	beq    v1, zero, L3f7b0 [$8003f7b0]
8003F7A8	addu   a0, zero, zero
8003F7AC	lw     a0, $0004(v1)

L3f7b0:	; 8003F7B0
8003F7B0	nop
8003F7B4	beq    a0, zero, L475b4 [$800475b4]
8003F7B8	addu   v0, zero, zero
8003F7BC	jal    func36978 [$80036978]
8003F7C0	nop
8003F7C4	j      L475b4 [$800475b4]
8003F7C8	addu   v0, zero, zero
8003F7CC	lui    v0, $8008
8003F7D0	lw     a1, $b70c(v0)
8003F7D4	nop
8003F7D8	lbu    v1, $0004(a1)
8003F7DC	addiu  v0, zero, $0001
8003F7E0	beq    v1, v0, L3f870 [$8003f870]
8003F7E4	slti   v0, v1, $0002
8003F7E8	beq    v0, zero, L3f800 [$8003f800]
8003F7EC	addiu  v0, zero, $0003
8003F7F0	beq    v1, zero, L3f810 [$8003f810]
8003F7F4	addu   v0, zero, zero
8003F7F8	j      L475b4 [$800475b4]
8003F7FC	nop

L3f800:	; 8003F800
8003F800	beq    v1, v0, L3f8f4 [$8003f8f4]
8003F804	addu   v0, zero, zero
8003F808	j      L475b4 [$800475b4]
8003F80C	nop

L3f810:	; 8003F810
8003F810	lui    a0, $8008
8003F814	lui    v0, $8008
8003F818	addiu  v1, a0, $ae10 (=-$51f0)
8003F81C	lw     v0, $b6f4(v0)
8003F820	lhu    s0, $0002(v1)
8003F824	lhu    s1, $ae10(a0)

func3f828:	; 8003F828
8003F828	andi   v0, v0, $0001
8003F82C	beq    v0, zero, L3f84c [$8003f84c]
8003F830	nop
8003F834	jal    func52da0 [$80052da0]
8003F838	nop
8003F83C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003F840	nop
8003F844	j      L3f860 [$8003f860]
8003F848	addu   a3, v0, zero

L3f84c:	; 8003F84C
8003F84C	lw     v0, $0000(a1)
8003F850	nop
8003F854	lbu    a3, $0000(v0)
8003F858	addiu  v0, v0, $0001
8003F85C	sw     v0, $0000(a1)

L3f860:	; 8003F860
8003F860	addu   a0, s0, zero
8003F864	addu   a1, s1, zero
8003F868	j      L3f8cc [$8003f8cc]
8003F86C	addiu  a2, zero, $0036

L3f870:	; 8003F870
8003F870	lui    a0, $8008
8003F874	lui    v0, $8008
8003F878	addiu  v1, a0, $ae10 (=-$51f0)
8003F87C	lw     v0, $b6f4(v0)
8003F880	lhu    s0, $0002(v1)
8003F884	lhu    s1, $ae10(a0)
8003F888	andi   v0, v0, $0001
8003F88C	beq    v0, zero, L3f8ac [$8003f8ac]
8003F890	nop
8003F894	jal    func52da0 [$80052da0]
8003F898	nop
8003F89C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003F8A0	nop
8003F8A4	j      L3f8c0 [$8003f8c0]
8003F8A8	addu   a3, v0, zero

L3f8ac:	; 8003F8AC
8003F8AC	lw     v0, $0000(a1)
8003F8B0	nop
8003F8B4	lbu    a3, $0000(v0)
8003F8B8	addiu  v0, v0, $0001
8003F8BC	sw     v0, $0000(a1)

L3f8c0:	; 8003F8C0
8003F8C0	addu   a0, s0, zero
8003F8C4	addu   a1, s1, zero
8003F8C8	addiu  a2, zero, $0035

L3f8cc:	; 8003F8CC
8003F8CC	lui    t1, $8008
8003F8D0	lui    t0, $8008
8003F8D4	lw     v0, $b6f4(t1)
8003F8D8	addiu  v1, zero, $0001
8003F8DC	sw     v1, $b6f8(t0)
8003F8E0	srav   v0, v1, v0
8003F8E4	jal    funcb1520 [$800b1520]
8003F8E8	sw     v0, $b6f4(t1)
8003F8EC	j      L475b4 [$800475b4]
8003F8F0	addu   v0, zero, zero

L3f8f4:	; 8003F8F4
8003F8F4	lui    a0, $8008
8003F8F8	lui    v0, $8008
8003F8FC	addiu  v1, a0, $ae10 (=-$51f0)
8003F900	lw     v0, $b6f4(v0)
8003F904	lhu    s0, $0002(v1)
8003F908	lhu    s1, $ae10(a0)
8003F90C	andi   v0, v0, $0001
8003F910	beq    v0, zero, L3f930 [$8003f930]
8003F914	nop
8003F918	jal    func52da0 [$80052da0]
8003F91C	nop
8003F920	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003F924	nop
8003F928	j      L3f944 [$8003f944]
8003F92C	addu   a3, v0, zero

L3f930:	; 8003F930
8003F930	lw     v0, $0000(a1)
8003F934	nop
8003F938	lbu    a3, $0000(v0)
8003F93C	addiu  v0, v0, $0001
8003F940	sw     v0, $0000(a1)

L3f944:	; 8003F944
8003F944	addu   a0, s0, zero
8003F948	addu   a1, s1, zero
8003F94C	addiu  a2, zero, $002f
8003F950	lui    t1, $8008
8003F954	lui    t0, $8008
8003F958	lw     v0, $b6f4(t1)
8003F95C	addiu  v1, zero, $0001
8003F960	sw     v1, $b6f8(t0)
8003F964	srav   v0, v1, v0
8003F968	jal    funcb1520 [$800b1520]
8003F96C	sw     v0, $b6f4(t1)
8003F970	lui    v0, $8008
8003F974	lw     v0, $b70c(v0)
8003F978	j      L39ea8 [$80039ea8]
8003F97C	sb     zero, $000b(v0)
8003F980	lui    a0, $8008
8003F984	lui    v0, $8008
8003F988	addiu  v1, a0, $ae10 (=-$51f0)
8003F98C	lw     v0, $b6f4(v0)
8003F990	lhu    s0, $0002(v1)
8003F994	lhu    s1, $ae10(a0)
8003F998	andi   v0, v0, $0001
8003F99C	beq    v0, zero, L3f9bc [$8003f9bc]
8003F9A0	lui    v0, $8008
8003F9A4	jal    func52da0 [$80052da0]
8003F9A8	nop
8003F9AC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003F9B0	nop
8003F9B4	j      L3f9d8 [$8003f9d8]
8003F9B8	addu   a2, v0, zero

L3f9bc:	; 8003F9BC
8003F9BC	lw     v1, $b70c(v0)
8003F9C0	nop
8003F9C4	lw     v0, $0000(v1)
8003F9C8	nop
8003F9CC	lbu    a2, $0000(v0)
8003F9D0	addiu  v0, v0, $0001
8003F9D4	sw     v0, $0000(v1)

L3f9d8:	; 8003F9D8
8003F9D8	addu   a0, s0, zero
8003F9DC	addu   a1, s1, zero
8003F9E0	andi   a2, a2, $ffff
8003F9E4	lui    t0, $8008
8003F9E8	lui    a3, $8008
8003F9EC	lw     v0, $b6f4(t0)
8003F9F0	addiu  v1, zero, $0001
8003F9F4	sw     v1, $b6f8(a3)
8003F9F8	srav   v0, v1, v0
8003F9FC	jal    funcca694 [$800ca694]
8003FA00	sw     v0, $b6f4(t0)
8003FA04	j      L475b4 [$800475b4]
8003FA08	addu   v0, zero, zero
8003FA0C	lui    v0, $8008
8003FA10	lw     v0, $b6f4(v0)
8003FA14	nop
8003FA18	andi   v0, v0, $0001
8003FA1C	beq    v0, zero, L3fa3c [$8003fa3c]
8003FA20	lui    v0, $8008
8003FA24	jal    func52da0 [$80052da0]
8003FA28	nop
8003FA2C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003FA30	nop
8003FA34	j      L3fa58 [$8003fa58]
8003FA38	addu   a0, v0, zero

L3fa3c:	; 8003FA3C
8003FA3C	lw     v1, $b70c(v0)
8003FA40	nop
8003FA44	lw     v0, $0000(v1)
8003FA48	nop
8003FA4C	lbu    a0, $0000(v0)
8003FA50	addiu  v0, v0, $0001
8003FA54	sw     v0, $0000(v1)

L3fa58:	; 8003FA58
8003FA58	addu   s2, a0, zero
8003FA5C	lui    a1, $8008
8003FA60	lui    a0, $8008
8003FA64	lw     v0, $b6f4(a1)
8003FA68	addiu  v1, zero, $0001
8003FA6C	sw     v1, $b6f8(a0)
8003FA70	srav   v0, v1, v0
8003FA74	sw     v0, $b6f4(a1)
8003FA78	and    v0, v0, v1
8003FA7C	beq    v0, zero, L3fa9c [$8003fa9c]
8003FA80	lui    v0, $8008
8003FA84	jal    func52da0 [$80052da0]
8003FA88	nop
8003FA8C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003FA90	nop
8003FA94	j      L3fad4 [$8003fad4]
8003FA98	addu   a1, v0, zero

L3fa9c:	; 8003FA9C
8003FA9C	lw     a0, $b70c(v0)
8003FAA0	nop
8003FAA4	lw     v0, $0000(a0)
8003FAA8	nop
8003FAAC	lbu    a1, $0000(v0)
8003FAB0	addiu  v0, v0, $0001
8003FAB4	sw     v0, $0000(a0)
8003FAB8	lbu    v1, $0000(v0)
8003FABC	addiu  v0, v0, $0001
8003FAC0	sw     v0, $0000(a0)
8003FAC4	sll    v1, v1, $08
8003FAC8	or     a1, a1, v1
8003FACC	sll    v0, a1, $10
8003FAD0	sra    a1, v0, $10

L3fad4:	; 8003FAD4
8003FAD4	addu   a0, s2, zero
8003FAD8	lui    a3, $8008
8003FADC	lui    a2, $8008
8003FAE0	lw     v0, $b6f4(a3)
8003FAE4	addiu  v1, zero, $0001
8003FAE8	sw     v1, $b6f8(a2)
8003FAEC	srav   v0, v1, v0
8003FAF0	jal    funcbe99c [$800be99c]
8003FAF4	sw     v0, $b6f4(a3)
8003FAF8	j      L475b4 [$800475b4]
8003FAFC	addu   v0, zero, zero
8003FB00	lui    v0, $8008
8003FB04	lw     v0, $b6f4(v0)
8003FB08	nop
8003FB0C	andi   v0, v0, $0001
8003FB10	beq    v0, zero, L3fb30 [$8003fb30]
8003FB14	lui    v0, $8008
8003FB18	jal    func52da0 [$80052da0]
8003FB1C	nop
8003FB20	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003FB24	nop
8003FB28	j      L3fb4c [$8003fb4c]
8003FB2C	addu   a2, v0, zero

L3fb30:	; 8003FB30
8003FB30	lw     v1, $b70c(v0)
8003FB34	nop
8003FB38	lw     v0, $0000(v1)
8003FB3C	nop
8003FB40	lbu    a2, $0000(v0)
8003FB44	addiu  v0, v0, $0001
8003FB48	sw     v0, $0000(v1)

L3fb4c:	; 8003FB4C
8003FB4C	lui    a1, $8008
8003FB50	lui    a0, $8008
8003FB54	lw     v0, $b6f4(a1)
8003FB58	addiu  v1, zero, $0001
8003FB5C	sw     v1, $b6f8(a0)
8003FB60	srav   v0, v1, v0
8003FB64	beq    a2, zero, L3fb8c [$8003fb8c]
8003FB68	sw     v0, $b6f4(a1)
8003FB6C	lui    v0, $8006
8003FB70	lw     v0, $794c(v0)
8003FB74	nop
8003FB78	lw     v1, $001c(v0)
8003FB7C	nop
8003FB80	lbu    v0, $056f(v1)
8003FB84	j      L3fbac [$8003fbac]
8003FB88	ori    v0, v0, $0008

L3fb8c:	; 8003FB8C
8003FB8C	lui    v0, $8006
8003FB90	lw     v0, $794c(v0)
8003FB94	nop
8003FB98	lw     v1, $001c(v0)
8003FB9C	nop
8003FBA0	lbu    v0, $056f(v1)
8003FBA4	nop
8003FBA8	andi   v0, v0, $00f7

L3fbac:	; 8003FBAC
8003FBAC	j      L39ea8 [$80039ea8]
8003FBB0	sb     v0, $056f(v1)
8003FBB4	jal    func1f0ff4 [$801f0ff4]
8003FBB8	nop
8003FBBC	lui    v1, $8008
8003FBC0	addiu  v0, zero, $0001
8003FBC4	j      L39ea8 [$80039ea8]
8003FBC8	sw     v0, $b718(v1)

8003FD84	lui    v0, $8008
8003FD88	lw     v0, $b6f4(v0)
8003FD8C	nop
8003FD90	andi   v0, v0, $0001
8003FD94	beq    v0, zero, L3fdb4 [$8003fdb4]
8003FD98	lui    v0, $8008
8003FD9C	jal    func52da0 [$80052da0]
8003FDA0	nop
8003FDA4	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003FDA8	nop
8003FDAC	j      L3fdd0 [$8003fdd0]
8003FDB0	addu   a0, v0, zero

L3fdb4:	; 8003FDB4
8003FDB4	lw     v1, $b70c(v0)
8003FDB8	nop
8003FDBC	lw     v0, $0000(v1)
8003FDC0	nop
8003FDC4	lbu    a0, $0000(v0)
8003FDC8	addiu  v0, v0, $0001
8003FDCC	sw     v0, $0000(v1)

L3fdd0:	; 8003FDD0
8003FDD0	addu   a3, a0, zero
8003FDD4	lui    a1, $8008
8003FDD8	lui    v1, $8008
8003FDDC	lw     a0, $b6f4(a1)
8003FDE0	addiu  v0, zero, $0001
8003FDE4	sw     v0, $b6f8(v1)
8003FDE8	srav   a0, v0, a0
8003FDEC	slti   v0, a3, $0009
8003FDF0	bne    v0, zero, L3fdfc [$8003fdfc]
8003FDF4	sw     a0, $b6f4(a1)
8003FDF8	addiu  a3, a3, $fffc (=-$4)

L3fdfc:	; 8003FDFC
8003FDFC	addu   s2, a3, zero
8003FE00	sltiu  v0, s2, $0009
8003FE04	beq    v0, zero, L39ea8 [$80039ea8]
8003FE08	andi   v0, a0, $0001
8003FE0C	beq    v0, zero, L3fe2c [$8003fe2c]
8003FE10	lui    v0, $8008
8003FE14	jal    func52da0 [$80052da0]
8003FE18	nop
8003FE1C	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003FE20	nop
8003FE24	j      L3fe48 [$8003fe48]
8003FE28	addu   a2, v0, zero

L3fe2c:	; 8003FE2C
8003FE2C	lw     v1, $b70c(v0)
8003FE30	nop
8003FE34	lw     v0, $0000(v1)
8003FE38	nop
8003FE3C	lbu    a2, $0000(v0)
8003FE40	addiu  v0, v0, $0001
8003FE44	sw     v0, $0000(v1)

L3fe48:	; 8003FE48
8003FE48	lui    a1, $8008
8003FE4C	lui    a0, $8008
8003FE50	lw     v0, $b6f4(a1)
8003FE54	addiu  v1, zero, $0001
8003FE58	sw     v1, $b6f8(a0)
8003FE5C	srav   v0, v1, v0
8003FE60	lui    v1, $8006
8003FE64	sw     v0, $b6f4(a1)
8003FE68	sll    v0, s2, $03
8003FE6C	lw     v1, $794c(v1)
8003FE70	addu   v0, v0, s2
8003FE74	lw     a0, $001c(v1)
8003FE78	sll    v0, v0, $04
8003FE7C	addu   a0, a0, v0
8003FE80	lw     v1, $0070(a0)
8003FE84	addiu  v0, zero, $fbff (=-$401)
8003FE88	and    v1, v1, v0
8003FE8C	andi   v0, a2, $0001
8003FE90	sll    v0, v0, $0a
8003FE94	or     v1, v1, v0
8003FE98	j      L39ea8 [$80039ea8]
8003FE9C	sw     v1, $0070(a0)



8003FF8C	lui    v0, $8008
8003FF90	lw     v0, $b6f4(v0)
8003FF94	nop
8003FF98	andi   v0, v0, $0001
8003FF9C	beq    v0, zero, L3ffbc [$8003ffbc]
8003FFA0	lui    v0, $8008
8003FFA4	jal    func52da0 [$80052da0]
8003FFA8	nop
8003FFAC	jal    system_read_from_stack_command_not_from_script [$80052d40]
8003FFB0	nop
8003FFB4	j      L3ffd8 [$8003ffd8]
8003FFB8	addu   a0, v0, zero

L3ffbc:	; 8003FFBC
8003FFBC	lw     v1, $b70c(v0)
8003FFC0	nop
8003FFC4	lw     v0, $0000(v1)
8003FFC8	nop
8003FFCC	lbu    a0, $0000(v0)
8003FFD0	addiu  v0, v0, $0001
8003FFD4	sw     v0, $0000(v1)

L3ffd8:	; 8003FFD8
8003FFD8	addu   s2, a0, zero
8003FFDC	lui    a1, $8008
8003FFE0	lui    a0, $8008
8003FFE4	lw     v0, $b6f4(a1)
8003FFE8	addiu  v1, zero, $0001
8003FFEC	sw     v1, $b6f8(a0)
8003FFF0	srav   v0, v1, v0
8003FFF4	sw     v0, $b6f4(a1)
8003FFF8	and    v0, v0, v1
8003FFFC	beq    v0, zero, L4001c [$8004001c]

L40000:	; 80040000
80040000	lui    v0, $8008

L40004:	; 80040004
80040004	jal    func52da0 [$80052da0]

L40008:	; 80040008
80040008	nop
8004000C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040010	nop
80040014	j      L40038 [$80040038]
80040018	addu   a0, v0, zero

L4001c:	; 8004001C
8004001C	lw     v1, $b70c(v0)
80040020	nop

func40024:	; 80040024
80040024	lw     v0, $0000(v1)

L40028:	; 80040028
80040028	nop
8004002C	lbu    a0, $0000(v0)

func40030:	; 80040030
80040030	addiu  v0, v0, $0001

L40034:	; 80040034
80040034	sw     v0, $0000(v1)

L40038:	; 80040038
80040038	addu   s3, a0, zero
8004003C	lui    a1, $8008
80040040	lui    a0, $8008

L40044:	; 80040044
80040044	lw     v0, $b6f4(a1)
80040048	addiu  v1, zero, $0001

L4004c:	; 8004004C
8004004C	sw     v1, $b6f8(a0)
80040050	srav   v0, v1, v0
80040054	sw     v0, $b6f4(a1)
80040058	and    v0, v0, v1

L4005c:	; 8004005C
8004005C	beq    v0, zero, L4007c [$8004007c]
80040060	lui    v0, $8008
80040064	jal    func52da0 [$80052da0]
80040068	nop
8004006C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040070	nop
80040074	j      L40098 [$80040098]
80040078	addu   a2, v0, zero

L4007c:	; 8004007C
8004007C	lw     v1, $b70c(v0)
80040080	nop
80040084	lw     v0, $0000(v1)
80040088	nop
8004008C	lbu    a2, $0000(v0)
80040090	addiu  v0, v0, $0001
80040094	sw     v0, $0000(v1)

L40098:	; 80040098
80040098	addu   a0, s2, zero
8004009C	addu   a1, s3, zero
800400A0	lui    t0, $8008
800400A4	lui    a3, $8008
800400A8	lw     v0, $b6f4(t0)
800400AC	addiu  v1, zero, $0001
800400B0	sw     v1, $b6f8(a3)
800400B4	srav   v0, v1, v0
800400B8	jal    func1ccb4 [$8001ccb4]
800400BC	sw     v0, $b6f4(t0)
800400C0	j      L475b4 [$800475b4]
800400C4	addu   v0, zero, zero
800400C8	lui    v0, $8008
800400CC	lw     v0, $b6f4(v0)
800400D0	nop
800400D4	andi   v0, v0, $0001
800400D8	beq    v0, zero, L400f8 [$800400f8]
800400DC	lui    v0, $8008
800400E0	jal    func52da0 [$80052da0]
800400E4	nop
800400E8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800400EC	nop
800400F0	j      L40130 [$80040130]
800400F4	addu   a1, v0, zero

L400f8:	; 800400F8
800400F8	lw     a0, $b70c(v0)
800400FC	nop
80040100	lw     v0, $0000(a0)
80040104	nop
80040108	lbu    a1, $0000(v0)
8004010C	addiu  v0, v0, $0001
80040110	sw     v0, $0000(a0)
80040114	lbu    v1, $0000(v0)
80040118	addiu  v0, v0, $0001
8004011C	sw     v0, $0000(a0)
80040120	sll    v1, v1, $08
80040124	or     a1, a1, v1
80040128	sll    v0, a1, $10
8004012C	sra    a1, v0, $10

L40130:	; 80040130
80040130	addu   s2, a1, zero
80040134	lui    a1, $8008
80040138	lui    a0, $8008
8004013C	lw     v0, $b6f4(a1)
80040140	addiu  v1, zero, $0001
80040144	sw     v1, $b6f8(a0)
80040148	srav   v0, v1, v0
8004014C	sw     v0, $b6f4(a1)
80040150	and    v0, v0, v1
80040154	beq    v0, zero, L40174 [$80040174]
80040158	lui    v0, $8008
8004015C	jal    func52da0 [$80052da0]
80040160	nop
80040164	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040168	nop
8004016C	j      L401ac [$800401ac]
80040170	addu   a1, v0, zero

L40174:	; 80040174
80040174	lw     a0, $b70c(v0)
80040178	nop
8004017C	lw     v0, $0000(a0)
80040180	nop
80040184	lbu    a1, $0000(v0)
80040188	addiu  v0, v0, $0001
8004018C	sw     v0, $0000(a0)
80040190	lbu    v1, $0000(v0)
80040194	addiu  v0, v0, $0001

L40198:	; 80040198
80040198	sw     v0, $0000(a0)
8004019C	sll    v1, v1, $08
800401A0	or     a1, a1, v1
800401A4	sll    v0, a1, $10
800401A8	sra    a1, v0, $10

L401ac:	; 800401AC
800401AC	addu   s3, a1, zero
800401B0	lui    a1, $8008
800401B4	lui    a0, $8008
800401B8	lw     v0, $b6f4(a1)
800401BC	addiu  v1, zero, $0001
800401C0	sw     v1, $b6f8(a0)
800401C4	srav   v0, v1, v0
800401C8	sw     v0, $b6f4(a1)
800401CC	and    v0, v0, v1
800401D0	beq    v0, zero, L401f0 [$800401f0]
800401D4	lui    v0, $8008
800401D8	jal    func52da0 [$80052da0]
800401DC	nop
800401E0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800401E4	nop
800401E8	j      L40228 [$80040228]
800401EC	addu   a2, v0, zero

L401f0:	; 800401F0
800401F0	lw     a0, $b70c(v0)
800401F4	nop
800401F8	lw     v0, $0000(a0)
800401FC	nop
80040200	lbu    a2, $0000(v0)
80040204	addiu  v0, v0, $0001
80040208	sw     v0, $0000(a0)
8004020C	lbu    v1, $0000(v0)
80040210	addiu  v0, v0, $0001
80040214	sw     v0, $0000(a0)
80040218	sll    v1, v1, $08
8004021C	or     a2, a2, v1
80040220	sll    v0, a2, $10
80040224	sra    a2, v0, $10

L40228:	; 80040228
80040228	sll    a0, s2, $10
8004022C	sra    a0, a0, $10
80040230	sll    a1, s3, $10
80040234	sra    a1, a1, $10
80040238	sll    a2, a2, $10
8004023C	sra    a2, a2, $10
80040240	lui    t0, $8008
80040244	lui    a3, $8008
80040248	lw     v0, $b6f4(t0)
8004024C	addiu  v1, zero, $0001
80040250	sw     v1, $b6f8(a3)
80040254	srav   v0, v1, v0
80040258	jal    funcc0db0 [$800c0db0]
8004025C	sw     v0, $b6f4(t0)
80040260	j      L475b4 [$800475b4]
80040264	addu   v0, zero, zero

80040448	lui    v0, $8008
8004044C	lw     v0, $b6f4(v0)
80040450	nop
80040454	andi   v0, v0, $0001
80040458	beq    v0, zero, L40478 [$80040478]
8004045C	lui    v0, $8008
80040460	jal    func52da0 [$80052da0]
80040464	nop
80040468	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004046C	nop
80040470	j      L40494 [$80040494]
80040474	addu   a0, v0, zero

L40478:	; 80040478
80040478	lw     v1, $b70c(v0)
8004047C	nop
80040480	lw     v0, $0000(v1)
80040484	nop
80040488	lbu    a0, $0000(v0)
8004048C	addiu  v0, v0, $0001
80040490	sw     v0, $0000(v1)

L40494:	; 80040494
80040494	addu   s2, a0, zero
80040498	lui    a1, $8008
8004049C	lui    a0, $8008
800404A0	lw     v0, $b6f4(a1)
800404A4	addiu  v1, zero, $0001
800404A8	sw     v1, $b6f8(a0)
800404AC	srav   v0, v1, v0
800404B0	sw     v0, $b6f4(a1)
800404B4	and    v0, v0, v1
800404B8	beq    v0, zero, L404d8 [$800404d8]
800404BC	lui    v0, $8008
800404C0	jal    func52da0 [$80052da0]
800404C4	nop
800404C8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800404CC	nop
800404D0	j      L404f4 [$800404f4]
800404D4	addu   a1, v0, zero

L404d8:	; 800404D8
800404D8	lw     v1, $b70c(v0)
800404DC	nop
800404E0	lw     v0, $0000(v1)
800404E4	nop
800404E8	lbu    a1, $0000(v0)
800404EC	addiu  v0, v0, $0001
800404F0	sw     v0, $0000(v1)

L404f4:	; 800404F4
800404F4	addu   a0, s2, zero
800404F8	lui    a3, $8008
800404FC	lui    a2, $8008
80040500	lw     v0, $b6f4(a3)
80040504	addiu  v1, zero, $0001

func40508:	; 80040508
80040508	sw     v1, $b6f8(a2)
8004050C	srav   v0, v1, v0
80040510	jal    funcc0038 [$800c0038]
80040514	sw     v0, $b6f4(a3)
80040518	j      L475b4 [$800475b4]
8004051C	addu   v0, zero, zero
80040520	lui    v0, $8008
80040524	lw     v0, $b6f4(v0)
80040528	nop
8004052C	andi   v0, v0, $0001
80040530	beq    v0, zero, L40550 [$80040550]
80040534	lui    v0, $8008
80040538	jal    func52da0 [$80052da0]
8004053C	nop
80040540	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040544	nop
80040548	j      L4056c [$8004056c]
8004054C	addu   a0, v0, zero

L40550:	; 80040550
80040550	lw     v1, $b70c(v0)
80040554	nop
80040558	lw     v0, $0000(v1)
8004055C	nop
80040560	lbu    a0, $0000(v0)
80040564	addiu  v0, v0, $0001
80040568	sw     v0, $0000(v1)

L4056c:	; 8004056C
8004056C	addu   s2, a0, zero
80040570	lui    a1, $8008
80040574	lui    a0, $8008
80040578	lw     v0, $b6f4(a1)
8004057C	addiu  v1, zero, $0001
80040580	sw     v1, $b6f8(a0)
80040584	srav   v0, v1, v0
80040588	sw     v0, $b6f4(a1)
8004058C	and    v0, v0, v1
80040590	beq    v0, zero, L405b0 [$800405b0]
80040594	lui    v0, $8008
80040598	jal    func52da0 [$80052da0]
8004059C	nop
800405A0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800405A4	nop
800405A8	j      L405cc [$800405cc]
800405AC	addu   a0, v0, zero

L405b0:	; 800405B0
800405B0	lw     v1, $b70c(v0)
800405B4	nop
800405B8	lw     v0, $0000(v1)
800405BC	nop
800405C0	lbu    a0, $0000(v0)
800405C4	addiu  v0, v0, $0001
800405C8	sw     v0, $0000(v1)

L405cc:	; 800405CC
800405CC	addu   s3, a0, zero
800405D0	lui    a1, $8008
800405D4	lui    a0, $8008
800405D8	lw     v0, $b6f4(a1)
800405DC	addiu  v1, zero, $0001
800405E0	sw     v1, $b6f8(a0)
800405E4	srav   v0, v1, v0
800405E8	sw     v0, $b6f4(a1)
800405EC	and    v0, v0, v1
800405F0	beq    v0, zero, L40610 [$80040610]
800405F4	lui    v0, $8008
800405F8	jal    func52da0 [$80052da0]
800405FC	nop
80040600	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040604	nop
80040608	j      L4062c [$8004062c]
8004060C	addu   a2, v0, zero

L40610:	; 80040610
80040610	lw     v1, $b70c(v0)
80040614	nop
80040618	lw     v0, $0000(v1)
8004061C	nop
80040620	lbu    a2, $0000(v0)
80040624	addiu  v0, v0, $0001
80040628	sw     v0, $0000(v1)

L4062c:	; 8004062C
8004062C	addu   a0, s2, zero
80040630	addu   a1, s3, zero
80040634	lui    t0, $8008
80040638	lui    a3, $8008
8004063C	lw     v0, $b6f4(t0)
80040640	addiu  v1, zero, $0001
80040644	sw     v1, $b6f8(a3)
80040648	srav   v0, v1, v0
8004064C	jal    funcc0e94 [$800c0e94]
80040650	sw     v0, $b6f4(t0)
80040654	j      L475b4 [$800475b4]
80040658	addu   v0, zero, zero
8004065C	lui    v0, $8008
80040660	lw     v0, $b6f4(v0)
80040664	nop
80040668	andi   v0, v0, $0001
8004066C	beq    v0, zero, L4068c [$8004068c]
80040670	lui    v0, $8008
80040674	jal    func52da0 [$80052da0]
80040678	nop
8004067C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040680	nop
80040684	j      L406c4 [$800406c4]
80040688	addu   a1, v0, zero

L4068c:	; 8004068C
8004068C	lw     a0, $b70c(v0)
80040690	nop
80040694	lw     v0, $0000(a0)
80040698	nop
8004069C	lbu    a1, $0000(v0)
800406A0	addiu  v0, v0, $0001
800406A4	sw     v0, $0000(a0)
800406A8	lbu    v1, $0000(v0)
800406AC	addiu  v0, v0, $0001
800406B0	sw     v0, $0000(a0)
800406B4	sll    v1, v1, $08
800406B8	or     a1, a1, v1
800406BC	sll    v0, a1, $10
800406C0	sra    a1, v0, $10

L406c4:	; 800406C4
800406C4	sll    a0, a1, $10
800406C8	sra    a0, a0, $10
800406CC	lui    a2, $8008
800406D0	lui    a1, $8008
800406D4	lw     v0, $b6f4(a2)
800406D8	addiu  v1, zero, $0001
800406DC	sw     v1, $b6f8(a1)
800406E0	srav   v0, v1, v0
800406E4	jal    funcc1024 [$800c1024]
800406E8	sw     v0, $b6f4(a2)
800406EC	j      L475b4 [$800475b4]
800406F0	addu   v0, zero, zero
800406F4	jal    funcc1100 [$800c1100]
800406F8	nop
800406FC	j      L475b4 [$800475b4]
80040700	addu   v0, zero, zero
80040704	jal    funcc104c [$800c104c]
80040708	nop
8004070C	j      L475b4 [$800475b4]
80040710	addu   v0, zero, zero

800408B8	lui    v0, $8008
800408BC	lw     v0, $b6f4(v0)
800408C0	nop
800408C4	andi   v0, v0, $0001
800408C8	beq    v0, zero, L408e8 [$800408e8]
800408CC	lui    v0, $8008
800408D0	jal    func52da0 [$80052da0]
800408D4	nop
800408D8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800408DC	nop
800408E0	j      L40904 [$80040904]
800408E4	addu   a0, v0, zero

L408e8:	; 800408E8
800408E8	lw     v1, $b70c(v0)
800408EC	nop
800408F0	lw     v0, $0000(v1)
800408F4	nop
800408F8	lbu    a0, $0000(v0)
800408FC	addiu  v0, v0, $0001
80040900	sw     v0, $0000(v1)

L40904:	; 80040904
80040904	addu   s2, a0, zero
80040908	lui    a1, $8008

func4090c:	; 8004090C
8004090C	lui    a0, $8008

func40910:	; 80040910
80040910	lw     v0, $b6f4(a1)
80040914	addiu  v1, zero, $0001
80040918	sw     v1, $b6f8(a0)
8004091C	srav   v0, v1, v0
80040920	sw     v0, $b6f4(a1)
80040924	and    v0, v0, v1
80040928	beq    v0, zero, L40948 [$80040948]
8004092C	lui    v0, $8008
80040930	jal    func52da0 [$80052da0]
80040934	nop
80040938	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004093C	nop
80040940	j      L40980 [$80040980]
80040944	addu   a1, v0, zero

L40948:	; 80040948
80040948	lw     a0, $b70c(v0)
8004094C	nop
80040950	lw     v0, $0000(a0)
80040954	nop
80040958	lbu    a1, $0000(v0)
8004095C	addiu  v0, v0, $0001
80040960	sw     v0, $0000(a0)
80040964	lbu    v1, $0000(v0)
80040968	addiu  v0, v0, $0001
8004096C	sw     v0, $0000(a0)
80040970	sll    v1, v1, $08
80040974	or     a1, a1, v1
80040978	sll    v0, a1, $10
8004097C	sra    a1, v0, $10

L40980:	; 80040980
80040980	addu   s3, a1, zero
80040984	lui    a1, $8008
80040988	lui    a0, $8008
8004098C	lw     v0, $b6f4(a1)
80040990	addiu  v1, zero, $0001
80040994	sw     v1, $b6f8(a0)
80040998	srav   v0, v1, v0
8004099C	sw     v0, $b6f4(a1)
800409A0	and    v0, v0, v1
800409A4	beq    v0, zero, L409c4 [$800409c4]
800409A8	lui    v0, $8008
800409AC	jal    func52da0 [$80052da0]
800409B0	nop
800409B4	jal    system_read_from_stack_command_not_from_script [$80052d40]
800409B8	nop
800409BC	j      L409fc [$800409fc]
800409C0	addu   a2, v0, zero

L409c4:	; 800409C4
800409C4	lw     a0, $b70c(v0)
800409C8	nop
800409CC	lw     v0, $0000(a0)
800409D0	nop
800409D4	lbu    a2, $0000(v0)
800409D8	addiu  v0, v0, $0001
800409DC	sw     v0, $0000(a0)
800409E0	lbu    v1, $0000(v0)
800409E4	addiu  v0, v0, $0001
800409E8	sw     v0, $0000(a0)
800409EC	sll    v1, v1, $08
800409F0	or     a2, a2, v1
800409F4	sll    v0, a2, $10
800409F8	sra    a2, v0, $10

L409fc:	; 800409FC
800409FC	lui    a1, $8008
80040A00	lui    a0, $8008
80040A04	lw     v0, $b6f4(a1)
80040A08	addiu  v1, zero, $0001
80040A0C	sw     v1, $b6f8(a0)
80040A10	srav   v0, v1, v0
80040A14	sw     v0, $b6f4(a1)
80040A18	and    v0, v0, v1
80040A1C	beq    v0, zero, L40a3c [$80040a3c]
80040A20	addu   s5, a2, zero
80040A24	jal    func52da0 [$80052da0]
80040A28	nop
80040A2C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040A30	nop
80040A34	j      L40a78 [$80040a78]
80040A38	addu   a3, v0, zero

L40a3c:	; 80040A3C
80040A3C	lui    v0, $8008
80040A40	lw     a0, $b70c(v0)
80040A44	nop
80040A48	lw     v0, $0000(a0)
80040A4C	nop
80040A50	lbu    a3, $0000(v0)
80040A54	addiu  v0, v0, $0001
80040A58	sw     v0, $0000(a0)
80040A5C	lbu    v1, $0000(v0)
80040A60	addiu  v0, v0, $0001
80040A64	sw     v0, $0000(a0)
80040A68	sll    v1, v1, $08
80040A6C	or     a3, a3, v1
80040A70	sll    v0, a3, $10
80040A74	sra    a3, v0, $10

L40a78:	; 80040A78
80040A78	addu   a0, s2, zero
80040A7C	sll    a1, s3, $10
80040A80	sra    a1, a1, $10
80040A84	sll    a2, s5, $10
80040A88	sra    a2, a2, $10
80040A8C	sll    a3, a3, $10
80040A90	sra    a3, a3, $10
80040A94	lui    t1, $8008
80040A98	lui    t0, $8008
80040A9C	lw     v0, $b6f4(t1)
80040AA0	addiu  v1, zero, $0001
80040AA4	sw     v1, $b6f8(t0)
80040AA8	srav   v0, v1, v0
80040AAC	jal    funcc11e8 [$800c11e8]
80040AB0	sw     v0, $b6f4(t1)
80040AB4	j      L475b4 [$800475b4]
80040AB8	addu   v0, zero, zero

80040B94	lui    v0, $8008
80040B98	lw     v0, $b6f4(v0)
80040B9C	nop
80040BA0	andi   v0, v0, $0001
80040BA4	beq    v0, zero, L40bc4 [$80040bc4]
80040BA8	lui    v0, $8008
80040BAC	jal    func52da0 [$80052da0]
80040BB0	nop
80040BB4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040BB8	nop
80040BBC	j      L40be0 [$80040be0]
80040BC0	addu   a0, v0, zero

L40bc4:	; 80040BC4
80040BC4	lw     v1, $b70c(v0)
80040BC8	nop
80040BCC	lw     v0, $0000(v1)
80040BD0	nop
80040BD4	lbu    a0, $0000(v0)
80040BD8	addiu  v0, v0, $0001
80040BDC	sw     v0, $0000(v1)

L40be0:	; 80040BE0
80040BE0	addu   s2, a0, zero
80040BE4	lui    a1, $8008
80040BE8	lui    a0, $8008
80040BEC	lw     v0, $b6f4(a1)
80040BF0	addiu  v1, zero, $0001
80040BF4	sw     v1, $b6f8(a0)
80040BF8	srav   v0, v1, v0
80040BFC	sw     v0, $b6f4(a1)
80040C00	and    v0, v0, v1
80040C04	beq    v0, zero, L40c24 [$80040c24]
80040C08	lui    v0, $8008
80040C0C	jal    func52da0 [$80052da0]

L40c10:	; 80040C10
80040C10	nop
80040C14	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040C18	nop
80040C1C	j      L40c40 [$80040c40]
80040C20	addu   a0, v0, zero

L40c24:	; 80040C24
80040C24	lw     v1, $b70c(v0)
80040C28	nop
80040C2C	lw     v0, $0000(v1)
80040C30	nop
80040C34	lbu    a0, $0000(v0)
80040C38	addiu  v0, v0, $0001
80040C3C	sw     v0, $0000(v1)

L40c40:	; 80040C40
80040C40	addu   s3, a0, zero
80040C44	lui    a1, $8008
80040C48	lui    a0, $8008

L40c4c:	; 80040C4C
80040C4C	lw     v0, $b6f4(a1)
80040C50	addiu  v1, zero, $0001
80040C54	sw     v1, $b6f8(a0)
80040C58	srav   v0, v1, v0
80040C5C	sw     v0, $b6f4(a1)
80040C60	and    v0, v0, v1
80040C64	beq    v0, zero, L40c84 [$80040c84]
80040C68	lui    v0, $8008
80040C6C	jal    func52da0 [$80052da0]
80040C70	nop
80040C74	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040C78	nop
80040C7C	j      L40cbc [$80040cbc]
80040C80	addu   a2, v0, zero

L40c84:	; 80040C84
80040C84	lw     a0, $b70c(v0)
80040C88	nop
80040C8C	lw     v0, $0000(a0)
80040C90	nop
80040C94	lbu    a2, $0000(v0)
80040C98	addiu  v0, v0, $0001
80040C9C	sw     v0, $0000(a0)
80040CA0	lbu    v1, $0000(v0)
80040CA4	addiu  v0, v0, $0001
80040CA8	sw     v0, $0000(a0)
80040CAC	sll    v1, v1, $08
80040CB0	or     a2, a2, v1
80040CB4	sll    v0, a2, $10
80040CB8	sra    a2, v0, $10

L40cbc:	; 80040CBC
80040CBC	lui    a1, $8008
80040CC0	lui    a0, $8008
80040CC4	lw     v0, $b6f4(a1)
80040CC8	addiu  v1, zero, $0001
80040CCC	sw     v1, $b6f8(a0)
80040CD0	srav   v0, v1, v0
80040CD4	sw     v0, $b6f4(a1)
80040CD8	and    v0, v0, v1
80040CDC	beq    v0, zero, L40cfc [$80040cfc]
80040CE0	addu   s5, a2, zero
80040CE4	jal    func52da0 [$80052da0]
80040CE8	nop
80040CEC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040CF0	nop
80040CF4	j      L40d38 [$80040d38]
80040CF8	addu   a3, v0, zero

L40cfc:	; 80040CFC
80040CFC	lui    v0, $8008
80040D00	lw     a0, $b70c(v0)
80040D04	nop
80040D08	lw     v0, $0000(a0)
80040D0C	nop
80040D10	lbu    a3, $0000(v0)
80040D14	addiu  v0, v0, $0001
80040D18	sw     v0, $0000(a0)
80040D1C	lbu    v1, $0000(v0)
80040D20	addiu  v0, v0, $0001
80040D24	sw     v0, $0000(a0)
80040D28	sll    v1, v1, $08
80040D2C	or     a3, a3, v1
80040D30	sll    v0, a3, $10
80040D34	sra    a3, v0, $10

L40d38:	; 80040D38
80040D38	addu   a0, s2, zero
80040D3C	addu   a1, s3, zero
80040D40	addu   a2, s5, zero
80040D44	lui    t1, $8008
80040D48	lui    t0, $8008
80040D4C	lw     v0, $b6f4(t1)
80040D50	addiu  v1, zero, $0001
80040D54	sw     v1, $b6f8(t0)
80040D58	srav   v0, v1, v0
80040D5C	jal    funcc147c [$800c147c]
80040D60	sw     v0, $b6f4(t1)
80040D64	j      L475b4 [$800475b4]
80040D68	addu   v0, zero, zero
80040D6C	lui    v0, $8008
80040D70	lw     v0, $b6f4(v0)
80040D74	nop
80040D78	andi   v0, v0, $0001
80040D7C	beq    v0, zero, L40d9c [$80040d9c]
80040D80	lui    v0, $8008
80040D84	jal    func52da0 [$80052da0]
80040D88	nop
80040D8C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040D90	nop
80040D94	j      L40db8 [$80040db8]
80040D98	addu   a0, v0, zero

L40d9c:	; 80040D9C
80040D9C	lw     v1, $b70c(v0)
80040DA0	nop
80040DA4	lw     v0, $0000(v1)
80040DA8	nop
80040DAC	lbu    a0, $0000(v0)
80040DB0	addiu  v0, v0, $0001
80040DB4	sw     v0, $0000(v1)

L40db8:	; 80040DB8
80040DB8	addu   s2, a0, zero
80040DBC	lui    a1, $8008
80040DC0	lui    a0, $8008
80040DC4	lw     v0, $b6f4(a1)
80040DC8	addiu  v1, zero, $0001
80040DCC	sw     v1, $b6f8(a0)
80040DD0	srav   v0, v1, v0
80040DD4	sw     v0, $b6f4(a1)
80040DD8	and    v0, v0, v1
80040DDC	beq    v0, zero, L40dfc [$80040dfc]
80040DE0	lui    v0, $8008
80040DE4	jal    func52da0 [$80052da0]
80040DE8	nop
80040DEC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040DF0	nop
80040DF4	j      L40e18 [$80040e18]
80040DF8	addu   a0, v0, zero

L40dfc:	; 80040DFC
80040DFC	lw     v1, $b70c(v0)
80040E00	nop
80040E04	lw     v0, $0000(v1)
80040E08	nop
80040E0C	lbu    a0, $0000(v0)
80040E10	addiu  v0, v0, $0001
80040E14	sw     v0, $0000(v1)

L40e18:	; 80040E18
80040E18	addu   s3, a0, zero
80040E1C	lui    a1, $8008
80040E20	lui    a0, $8008
80040E24	lw     v0, $b6f4(a1)
80040E28	addiu  v1, zero, $0001
80040E2C	sw     v1, $b6f8(a0)
80040E30	srav   v0, v1, v0
80040E34	sw     v0, $b6f4(a1)
80040E38	and    v0, v0, v1
80040E3C	beq    v0, zero, L40e5c [$80040e5c]
80040E40	lui    v0, $8008
80040E44	jal    func52da0 [$80052da0]
80040E48	nop
80040E4C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040E50	nop
80040E54	j      L40e94 [$80040e94]
80040E58	addu   a2, v0, zero

L40e5c:	; 80040E5C
80040E5C	lw     a0, $b70c(v0)
80040E60	nop
80040E64	lw     v0, $0000(a0)
80040E68	nop
80040E6C	lbu    a2, $0000(v0)
80040E70	addiu  v0, v0, $0001
80040E74	sw     v0, $0000(a0)
80040E78	lbu    v1, $0000(v0)
80040E7C	addiu  v0, v0, $0001
80040E80	sw     v0, $0000(a0)
80040E84	sll    v1, v1, $08
80040E88	or     a2, a2, v1
80040E8C	sll    v0, a2, $10
80040E90	sra    a2, v0, $10

L40e94:	; 80040E94
80040E94	lui    a1, $8008
80040E98	lui    a0, $8008
80040E9C	lw     v0, $b6f4(a1)
80040EA0	addiu  v1, zero, $0001
80040EA4	sw     v1, $b6f8(a0)
80040EA8	srav   v0, v1, v0
80040EAC	sw     v0, $b6f4(a1)
80040EB0	and    v0, v0, v1
80040EB4	beq    v0, zero, L40ed4 [$80040ed4]
80040EB8	addu   s5, a2, zero
80040EBC	jal    func52da0 [$80052da0]
80040EC0	nop
80040EC4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040EC8	nop
80040ECC	j      L40f10 [$80040f10]
80040ED0	addu   a3, v0, zero

L40ed4:	; 80040ED4
80040ED4	lui    v0, $8008
80040ED8	lw     a0, $b70c(v0)
80040EDC	nop
80040EE0	lw     v0, $0000(a0)
80040EE4	nop
80040EE8	lbu    a3, $0000(v0)
80040EEC	addiu  v0, v0, $0001
80040EF0	sw     v0, $0000(a0)
80040EF4	lbu    v1, $0000(v0)
80040EF8	addiu  v0, v0, $0001
80040EFC	sw     v0, $0000(a0)
80040F00	sll    v1, v1, $08
80040F04	or     a3, a3, v1
80040F08	sll    v0, a3, $10
80040F0C	sra    a3, v0, $10

L40f10:	; 80040F10
80040F10	addu   a0, s2, zero
80040F14	addu   a1, s3, zero
80040F18	addu   a2, s5, zero
80040F1C	lui    t1, $8008
80040F20	lui    t0, $8008
80040F24	lw     v0, $b6f4(t1)
80040F28	addiu  v1, zero, $0001
80040F2C	sw     v1, $b6f8(t0)
80040F30	srav   v0, v1, v0
80040F34	jal    funcc15bc [$800c15bc]
80040F38	sw     v0, $b6f4(t1)
80040F3C	j      L475b4 [$800475b4]
80040F40	addu   v0, zero, zero
80040F44	lui    v0, $8008
80040F48	lw     v0, $b6f4(v0)
80040F4C	nop
80040F50	andi   v0, v0, $0001
80040F54	beq    v0, zero, L40f74 [$80040f74]
80040F58	lui    v0, $8008
80040F5C	jal    func52da0 [$80052da0]
80040F60	nop
80040F64	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040F68	nop
80040F6C	j      L40f90 [$80040f90]
80040F70	addu   a0, v0, zero

L40f74:	; 80040F74
80040F74	lw     v1, $b70c(v0)
80040F78	nop
80040F7C	lw     v0, $0000(v1)
80040F80	nop
80040F84	lbu    a0, $0000(v0)
80040F88	addiu  v0, v0, $0001
80040F8C	sw     v0, $0000(v1)

L40f90:	; 80040F90
80040F90	addu   s2, a0, zero
80040F94	lui    a1, $8008
80040F98	lui    a0, $8008
80040F9C	lw     v0, $b6f4(a1)
80040FA0	addiu  v1, zero, $0001
80040FA4	sw     v1, $b6f8(a0)
80040FA8	srav   v0, v1, v0
80040FAC	sw     v0, $b6f4(a1)
80040FB0	and    v0, v0, v1
80040FB4	beq    v0, zero, L40fd4 [$80040fd4]
80040FB8	lui    v0, $8008
80040FBC	jal    func52da0 [$80052da0]
80040FC0	nop
80040FC4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80040FC8	nop
80040FCC	j      L4100c [$8004100c]
80040FD0	addu   a1, v0, zero

L40fd4:	; 80040FD4
80040FD4	lw     a0, $b70c(v0)
80040FD8	nop
80040FDC	lw     v0, $0000(a0)
80040FE0	nop
80040FE4	lbu    a1, $0000(v0)
80040FE8	addiu  v0, v0, $0001
80040FEC	sw     v0, $0000(a0)
80040FF0	lbu    v1, $0000(v0)
80040FF4	addiu  v0, v0, $0001
80040FF8	sw     v0, $0000(a0)
80040FFC	sll    v1, v1, $08
80041000	or     a1, a1, v1
80041004	sll    v0, a1, $10
80041008	sra    a1, v0, $10

L4100c:	; 8004100C
8004100C	addu   s3, a1, zero
80041010	lui    a1, $8008
80041014	lui    a0, $8008
80041018	lw     v0, $b6f4(a1)
8004101C	addiu  v1, zero, $0001
80041020	sw     v1, $b6f8(a0)
80041024	srav   v0, v1, v0
80041028	sw     v0, $b6f4(a1)
8004102C	and    v0, v0, v1
80041030	beq    v0, zero, L41050 [$80041050]
80041034	lui    v0, $8008
80041038	jal    func52da0 [$80052da0]
8004103C	nop
80041040	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041044	nop
80041048	j      L41088 [$80041088]
8004104C	addu   a2, v0, zero

L41050:	; 80041050
80041050	lw     a0, $b70c(v0)
80041054	nop
80041058	lw     v0, $0000(a0)
8004105C	nop
80041060	lbu    a2, $0000(v0)
80041064	addiu  v0, v0, $0001
80041068	sw     v0, $0000(a0)
8004106C	lbu    v1, $0000(v0)
80041070	addiu  v0, v0, $0001
80041074	sw     v0, $0000(a0)
80041078	sll    v1, v1, $08
8004107C	or     a2, a2, v1
80041080	sll    v0, a2, $10
80041084	sra    a2, v0, $10

L41088:	; 80041088
80041088	addu   a0, s2, zero
8004108C	addu   a1, s3, zero
80041090	lui    t0, $8008
80041094	lui    a3, $8008
80041098	lw     v0, $b6f4(t0)
8004109C	addiu  v1, zero, $0001
800410A0	sw     v1, $b6f8(a3)
800410A4	srav   v0, v1, v0
800410A8	jal    funcc1614 [$800c1614]
800410AC	sw     v0, $b6f4(t0)
800410B0	j      L475b4 [$800475b4]
800410B4	addu   v0, zero, zero

800413BC	lui    v0, $8008
800413C0	lw     v0, $b6f4(v0)
800413C4	nop
800413C8	andi   v0, v0, $0001
800413CC	beq    v0, zero, L413ec [$800413ec]
800413D0	lui    v0, $8008
800413D4	jal    func52da0 [$80052da0]
800413D8	nop
800413DC	jal    system_read_from_stack_command_not_from_script [$80052d40]
800413E0	nop
800413E4	j      L41408 [$80041408]
800413E8	addu   a0, v0, zero

L413ec:	; 800413EC
800413EC	lw     v1, $b70c(v0)
800413F0	nop
800413F4	lw     v0, $0000(v1)
800413F8	nop
800413FC	lbu    a0, $0000(v0)
80041400	addiu  v0, v0, $0001
80041404	sw     v0, $0000(v1)

L41408:	; 80041408
80041408	addu   s2, a0, zero
8004140C	lui    a1, $8008
80041410	lui    a0, $8008
80041414	lw     v0, $b6f4(a1)
80041418	addiu  v1, zero, $0001
8004141C	sw     v1, $b6f8(a0)
80041420	srav   v0, v1, v0
80041424	sw     v0, $b6f4(a1)
80041428	and    v0, v0, v1
8004142C	beq    v0, zero, L4144c [$8004144c]
80041430	lui    v0, $8008
80041434	jal    func52da0 [$80052da0]
80041438	nop
8004143C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041440	nop
80041444	j      L41468 [$80041468]
80041448	addu   a1, v0, zero

L4144c:	; 8004144C
8004144C	lw     v1, $b70c(v0)
80041450	nop
80041454	lw     v0, $0000(v1)
80041458	nop
8004145C	lbu    a1, $0000(v0)
80041460	addiu  v0, v0, $0001
80041464	sw     v0, $0000(v1)

L41468:	; 80041468
80041468	addu   a0, s2, zero
8004146C	lui    a3, $8008
80041470	lui    a2, $8008
80041474	lw     v0, $b6f4(a3)
80041478	addiu  v1, zero, $0001
8004147C	sw     v1, $b6f8(a2)
80041480	srav   v0, v1, v0
80041484	jal    funcc14dc [$800c14dc]
80041488	sw     v0, $b6f4(a3)
8004148C	j      L475b4 [$800475b4]
80041490	addu   v0, zero, zero
80041494	lui    v0, $8008
80041498	lw     v0, $b6f4(v0)
8004149C	nop
800414A0	andi   v0, v0, $0001
800414A4	beq    v0, zero, L414c4 [$800414c4]
800414A8	lui    v0, $8008
800414AC	jal    func52da0 [$80052da0]
800414B0	nop
800414B4	jal    system_read_from_stack_command_not_from_script [$80052d40]
800414B8	nop
800414BC	j      L414e0 [$800414e0]
800414C0	addu   a0, v0, zero

L414c4:	; 800414C4
800414C4	lw     v1, $b70c(v0)
800414C8	nop
800414CC	lw     v0, $0000(v1)
800414D0	nop
800414D4	lbu    a0, $0000(v0)
800414D8	addiu  v0, v0, $0001
800414DC	sw     v0, $0000(v1)

L414e0:	; 800414E0
800414E0	addu   s2, a0, zero
800414E4	lui    a1, $8008
800414E8	lui    a0, $8008
800414EC	lw     v0, $b6f4(a1)
800414F0	addiu  v1, zero, $0001
800414F4	sw     v1, $b6f8(a0)
800414F8	srav   v0, v1, v0
800414FC	sw     v0, $b6f4(a1)
80041500	and    v0, v0, v1
80041504	beq    v0, zero, L41524 [$80041524]
80041508	lui    v0, $8008
8004150C	jal    func52da0 [$80052da0]
80041510	nop
80041514	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041518	nop
8004151C	j      L41540 [$80041540]
80041520	addu   a1, v0, zero

L41524:	; 80041524
80041524	lw     v1, $b70c(v0)
80041528	nop
8004152C	lw     v0, $0000(v1)
80041530	nop
80041534	lbu    a1, $0000(v0)
80041538	addiu  v0, v0, $0001
8004153C	sw     v0, $0000(v1)

L41540:	; 80041540
80041540	addu   a0, s2, zero
80041544	lui    a3, $8008
80041548	lui    a2, $8008
8004154C	lw     v0, $b6f4(a3)
80041550	addiu  v1, zero, $0001
80041554	sw     v1, $b6f8(a2)
80041558	srav   v0, v1, v0
8004155C	jal    funcc16b0 [$800c16b0]
80041560	sw     v0, $b6f4(a3)
80041564	j      L475b4 [$800475b4]
80041568	addu   v0, zero, zero
8004156C	lui    v0, $8008
80041570	lw     v0, $b6f4(v0)
80041574	nop
80041578	andi   v0, v0, $0001
8004157C	beq    v0, zero, L4159c [$8004159c]
80041580	lui    v0, $8008
80041584	jal    func52da0 [$80052da0]
80041588	nop
8004158C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041590	nop
80041594	j      L415b8 [$800415b8]
80041598	addu   a0, v0, zero

L4159c:	; 8004159C
8004159C	lw     v1, $b70c(v0)
800415A0	nop
800415A4	lw     v0, $0000(v1)
800415A8	nop
800415AC	lbu    a0, $0000(v0)
800415B0	addiu  v0, v0, $0001
800415B4	sw     v0, $0000(v1)

L415b8:	; 800415B8
800415B8	addu   s2, a0, zero
800415BC	lui    a1, $8008
800415C0	lui    a0, $8008
800415C4	lw     v0, $b6f4(a1)
800415C8	addiu  v1, zero, $0001
800415CC	sw     v1, $b6f8(a0)
800415D0	srav   v0, v1, v0
800415D4	sw     v0, $b6f4(a1)
800415D8	and    v0, v0, v1
800415DC	beq    v0, zero, L415fc [$800415fc]
800415E0	lui    v0, $8008
800415E4	jal    func52da0 [$80052da0]
800415E8	nop
800415EC	jal    system_read_from_stack_command_not_from_script [$80052d40]
800415F0	nop
800415F4	j      L41618 [$80041618]
800415F8	addu   a1, v0, zero

L415fc:	; 800415FC
800415FC	lw     v1, $b70c(v0)
80041600	nop
80041604	lw     v0, $0000(v1)
80041608	nop
8004160C	lbu    a1, $0000(v0)
80041610	addiu  v0, v0, $0001
80041614	sw     v0, $0000(v1)

L41618:	; 80041618
80041618	addu   a0, s2, zero
8004161C	lui    a3, $8008
80041620	lui    a2, $8008
80041624	lw     v0, $b6f4(a3)
80041628	addiu  v1, zero, $0001
8004162C	sw     v1, $b6f8(a2)
80041630	srav   v0, v1, v0
80041634	jal    funcc17ac [$800c17ac]
80041638	sw     v0, $b6f4(a3)
8004163C	j      L475b4 [$800475b4]
80041640	addu   v0, zero, zero

80041738	lui    v0, $8008
8004173C	lw     v0, $b6f4(v0)
80041740	nop
80041744	andi   v0, v0, $0001
80041748	beq    v0, zero, L41768 [$80041768]
8004174C	lui    v0, $8008
80041750	jal    func52da0 [$80052da0]
80041754	nop
80041758	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004175C	nop
80041760	j      L41784 [$80041784]
80041764	addu   a0, v0, zero

L41768:	; 80041768
80041768	lw     v1, $b70c(v0)
8004176C	nop
80041770	lw     v0, $0000(v1)
80041774	nop
80041778	lbu    a0, $0000(v0)
8004177C	addiu  v0, v0, $0001
80041780	sw     v0, $0000(v1)

L41784:	; 80041784
80041784	addu   s2, a0, zero
80041788	lui    a1, $8008
8004178C	lui    a0, $8008
80041790	lw     v0, $b6f4(a1)
80041794	addiu  v1, zero, $0001
80041798	sw     v1, $b6f8(a0)
8004179C	srav   v0, v1, v0
800417A0	sw     v0, $b6f4(a1)
800417A4	and    v0, v0, v1
800417A8	beq    v0, zero, L417c8 [$800417c8]
800417AC	lui    v0, $8008
800417B0	jal    func52da0 [$80052da0]
800417B4	nop
800417B8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800417BC	nop
800417C0	j      L417e4 [$800417e4]
800417C4	addu   a0, v0, zero

L417c8:	; 800417C8
800417C8	lw     v1, $b70c(v0)
800417CC	nop
800417D0	lw     v0, $0000(v1)
800417D4	nop
800417D8	lbu    a0, $0000(v0)
800417DC	addiu  v0, v0, $0001
800417E0	sw     v0, $0000(v1)

L417e4:	; 800417E4
800417E4	addu   s3, a0, zero
800417E8	lui    a1, $8008
800417EC	lui    a0, $8008
800417F0	lw     v0, $b6f4(a1)
800417F4	addiu  v1, zero, $0001
800417F8	sw     v1, $b6f8(a0)
800417FC	srav   v0, v1, v0
80041800	sw     v0, $b6f4(a1)
80041804	and    v0, v0, v1
80041808	beq    v0, zero, L41828 [$80041828]
8004180C	lui    v0, $8008
80041810	jal    func52da0 [$80052da0]
80041814	nop
80041818	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004181C	nop
80041820	j      L41844 [$80041844]
80041824	addu   a2, v0, zero

L41828:	; 80041828
80041828	lw     v1, $b70c(v0)
8004182C	nop
80041830	lw     v0, $0000(v1)
80041834	nop
80041838	lbu    a2, $0000(v0)
8004183C	addiu  v0, v0, $0001
80041840	sw     v0, $0000(v1)

L41844:	; 80041844
80041844	addu   a0, s2, zero
80041848	addu   a1, s3, zero
8004184C	lui    t0, $8008
80041850	lui    a3, $8008
80041854	lw     v0, $b6f4(t0)
80041858	addiu  v1, zero, $0001
8004185C	sw     v1, $b6f8(a3)
80041860	srav   v0, v1, v0
80041864	jal    funcc1868 [$800c1868]
80041868	sw     v0, $b6f4(t0)
8004186C	j      L475b4 [$800475b4]
80041870	addu   v0, zero, zero
80041874	lui    v0, $8008
80041878	lw     v0, $b6f4(v0)
8004187C	nop
80041880	andi   v0, v0, $0001
80041884	beq    v0, zero, L418a4 [$800418a4]
80041888	lui    v0, $8008
8004188C	jal    func52da0 [$80052da0]
80041890	nop
80041894	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041898	nop
8004189C	j      L418c0 [$800418c0]
800418A0	addu   a0, v0, zero

L418a4:	; 800418A4
800418A4	lw     v1, $b70c(v0)
800418A8	nop
800418AC	lw     v0, $0000(v1)
800418B0	nop
800418B4	lbu    a0, $0000(v0)
800418B8	addiu  v0, v0, $0001
800418BC	sw     v0, $0000(v1)

L418c0:	; 800418C0
800418C0	addu   s2, a0, zero
800418C4	lui    a1, $8008
800418C8	lui    a0, $8008
800418CC	lw     v0, $b6f4(a1)
800418D0	addiu  v1, zero, $0001
800418D4	sw     v1, $b6f8(a0)
800418D8	srav   v0, v1, v0
800418DC	sw     v0, $b6f4(a1)
800418E0	and    v0, v0, v1
800418E4	beq    v0, zero, L41904 [$80041904]
800418E8	lui    v0, $8008
800418EC	jal    func52da0 [$80052da0]
800418F0	nop
800418F4	jal    system_read_from_stack_command_not_from_script [$80052d40]
800418F8	nop
800418FC	j      L41920 [$80041920]
80041900	addu   a1, v0, zero

L41904:	; 80041904
80041904	lw     v1, $b70c(v0)
80041908	nop
8004190C	lw     v0, $0000(v1)
80041910	nop
80041914	lbu    a1, $0000(v0)
80041918	addiu  v0, v0, $0001
8004191C	sw     v0, $0000(v1)

L41920:	; 80041920
80041920	addu   a0, s2, zero
80041924	lui    a3, $8008
80041928	lui    a2, $8008
8004192C	lw     v0, $b6f4(a3)
80041930	addiu  v1, zero, $0001
80041934	sw     v1, $b6f8(a2)
80041938	srav   v0, v1, v0
8004193C	jal    funcc18a0 [$800c18a0]
80041940	sw     v0, $b6f4(a3)
80041944	j      L475b4 [$800475b4]
80041948	addu   v0, zero, zero

80041B60	lui    v0, $8008
80041B64	lw     v0, $b6f4(v0)
80041B68	nop
80041B6C	andi   v0, v0, $0001
80041B70	beq    v0, zero, L41b90 [$80041b90]
80041B74	lui    v0, $8008
80041B78	jal    func52da0 [$80052da0]
80041B7C	nop
80041B80	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041B84	nop
80041B88	j      L41bac [$80041bac]
80041B8C	addu   a0, v0, zero

L41b90:	; 80041B90
80041B90	lw     v1, $b70c(v0)
80041B94	nop
80041B98	lw     v0, $0000(v1)
80041B9C	nop
80041BA0	lbu    a0, $0000(v0)
80041BA4	addiu  v0, v0, $0001
80041BA8	sw     v0, $0000(v1)

L41bac:	; 80041BAC
80041BAC	addu   s2, a0, zero
80041BB0	lui    a1, $8008
80041BB4	lui    a0, $8008
80041BB8	lw     v0, $b6f4(a1)
80041BBC	addiu  v1, zero, $0001
80041BC0	sw     v1, $b6f8(a0)
80041BC4	srav   v0, v1, v0
80041BC8	sw     v0, $b6f4(a1)
80041BCC	and    v0, v0, v1
80041BD0	beq    v0, zero, L41bf0 [$80041bf0]
80041BD4	lui    v0, $8008
80041BD8	jal    func52da0 [$80052da0]
80041BDC	nop
80041BE0	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041BE4	nop
80041BE8	j      L41c0c [$80041c0c]
80041BEC	addu   a1, v0, zero

L41bf0:	; 80041BF0
80041BF0	lw     v1, $b70c(v0)
80041BF4	nop
80041BF8	lw     v0, $0000(v1)
80041BFC	nop
80041C00	lbu    a1, $0000(v0)
80041C04	addiu  v0, v0, $0001
80041C08	sw     v0, $0000(v1)

L41c0c:	; 80041C0C
80041C0C	addu   a0, s2, zero
80041C10	lui    a3, $8008
80041C14	lui    a2, $8008
80041C18	lw     v0, $b6f4(a3)
80041C1C	addiu  v1, zero, $0001
80041C20	sw     v1, $b6f8(a2)
80041C24	srav   v0, v1, v0
80041C28	jal    funcc16f4 [$800c16f4]
80041C2C	sw     v0, $b6f4(a3)
80041C30	j      L475b4 [$800475b4]
80041C34	addu   v0, zero, zero

80041F0C	lui    v0, $8008
80041F10	lw     v0, $b6f4(v0)
80041F14	nop
80041F18	andi   v0, v0, $0001
80041F1C	beq    v0, zero, L41f3c [$80041f3c]
80041F20	lui    v0, $8008
80041F24	jal    func52da0 [$80052da0]
80041F28	nop
80041F2C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041F30	nop
80041F34	j      L41f58 [$80041f58]
80041F38	addu   a0, v0, zero

L41f3c:	; 80041F3C
80041F3C	lw     v1, $b70c(v0)
80041F40	nop
80041F44	lw     v0, $0000(v1)
80041F48	nop
80041F4C	lbu    a0, $0000(v0)
80041F50	addiu  v0, v0, $0001
80041F54	sw     v0, $0000(v1)

L41f58:	; 80041F58
80041F58	addu   s2, a0, zero
80041F5C	lui    a1, $8008
80041F60	lui    a0, $8008
80041F64	lw     v0, $b6f4(a1)
80041F68	addiu  v1, zero, $0001
80041F6C	sw     v1, $b6f8(a0)
80041F70	srav   v0, v1, v0
80041F74	sw     v0, $b6f4(a1)
80041F78	and    v0, v0, v1
80041F7C	beq    v0, zero, L41f9c [$80041f9c]
80041F80	lui    v0, $8008
80041F84	jal    func52da0 [$80052da0]
80041F88	nop
80041F8C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80041F90	nop
80041F94	j      L41fd4 [$80041fd4]
80041F98	addu   a1, v0, zero

L41f9c:	; 80041F9C
80041F9C	lw     a0, $b70c(v0)
80041FA0	nop
80041FA4	lw     v0, $0000(a0)
80041FA8	nop
80041FAC	lbu    a1, $0000(v0)
80041FB0	addiu  v0, v0, $0001
80041FB4	sw     v0, $0000(a0)
80041FB8	lbu    v1, $0000(v0)
80041FBC	addiu  v0, v0, $0001
80041FC0	sw     v0, $0000(a0)
80041FC4	sll    v1, v1, $08

L41fc8:	; 80041FC8
80041FC8	or     a1, a1, v1
80041FCC	sll    v0, a1, $10
80041FD0	sra    a1, v0, $10

L41fd4:	; 80041FD4
80041FD4	addu   s3, a1, zero
80041FD8	lui    a1, $8008
80041FDC	lui    a0, $8008
80041FE0	lw     v0, $b6f4(a1)
80041FE4	addiu  v1, zero, $0001
80041FE8	sw     v1, $b6f8(a0)
80041FEC	srav   v0, v1, v0
80041FF0	sw     v0, $b6f4(a1)
80041FF4	and    v0, v0, v1
80041FF8	beq    v0, zero, L42018 [$80042018]
80041FFC	lui    v0, $8008
80042000	jal    func52da0 [$80052da0]
80042004	nop
80042008	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004200C	nop
80042010	j      L42050 [$80042050]
80042014	addu   a2, v0, zero

L42018:	; 80042018
80042018	lw     a0, $b70c(v0)
8004201C	nop
80042020	lw     v0, $0000(a0)
80042024	nop
80042028	lbu    a2, $0000(v0)
8004202C	addiu  v0, v0, $0001
80042030	sw     v0, $0000(a0)
80042034	lbu    v1, $0000(v0)
80042038	addiu  v0, v0, $0001
8004203C	sw     v0, $0000(a0)
80042040	sll    v1, v1, $08
80042044	or     a2, a2, v1
80042048	sll    v0, a2, $10
8004204C	sra    a2, v0, $10

L42050:	; 80042050
80042050	lui    a1, $8008
80042054	lui    a0, $8008
80042058	lw     v0, $b6f4(a1)
8004205C	addiu  v1, zero, $0001
80042060	sw     v1, $b6f8(a0)
80042064	srav   v0, v1, v0
80042068	sw     v0, $b6f4(a1)
8004206C	and    v0, v0, v1
80042070	beq    v0, zero, L42090 [$80042090]
80042074	addu   s5, a2, zero
80042078	jal    func52da0 [$80052da0]
8004207C	nop
80042080	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042084	nop
80042088	j      L420cc [$800420cc]
8004208C	addu   a3, v0, zero

L42090:	; 80042090
80042090	lui    v0, $8008
80042094	lw     a0, $b70c(v0)
80042098	nop
8004209C	lw     v0, $0000(a0)
800420A0	nop
800420A4	lbu    a3, $0000(v0)
800420A8	addiu  v0, v0, $0001
800420AC	sw     v0, $0000(a0)
800420B0	lbu    v1, $0000(v0)
800420B4	addiu  v0, v0, $0001
800420B8	sw     v0, $0000(a0)
800420BC	sll    v1, v1, $08
800420C0	or     a3, a3, v1
800420C4	sll    v0, a3, $10
800420C8	sra    a3, v0, $10

L420cc:	; 800420CC
800420CC	lui    a1, $8008
800420D0	lui    a0, $8008
800420D4	lw     v0, $b6f4(a1)
800420D8	addiu  v1, zero, $0001
800420DC	sw     v1, $b6f8(a0)
800420E0	srav   v0, v1, v0
800420E4	sw     v0, $b6f4(a1)
800420E8	and    v0, v0, v1
800420EC	beq    v0, zero, L4210c [$8004210c]
800420F0	addu   s1, a3, zero
800420F4	jal    func52da0 [$80052da0]
800420F8	nop
800420FC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042100	nop
80042104	j      L42148 [$80042148]
80042108	addu   t1, v0, zero

L4210c:	; 8004210C
8004210C	lui    v0, $8008
80042110	lw     a0, $b70c(v0)
80042114	nop
80042118	lw     v0, $0000(a0)
8004211C	nop
80042120	lbu    t1, $0000(v0)
80042124	addiu  v0, v0, $0001
80042128	sw     v0, $0000(a0)
8004212C	lbu    v1, $0000(v0)
80042130	addiu  v0, v0, $0001
80042134	sw     v0, $0000(a0)
80042138	sll    v1, v1, $08
8004213C	or     t1, t1, v1
80042140	sll    v0, t1, $10
80042144	sra    t1, v0, $10

L42148:	; 80042148
80042148	addu   a0, s2, zero
8004214C	sll    a1, s3, $10
80042150	sra    a1, a1, $10
80042154	sll    a2, s5, $10
80042158	sra    a2, a2, $10
8004215C	sll    a3, s1, $10
80042160	sra    a3, a3, $10
80042164	lui    v1, $8008
80042168	addiu  v0, zero, $0001
8004216C	lui    t0, $8008
80042170	sw     v0, $b6f8(v1)
80042174	sll    v0, t1, $10
80042178	lw     v1, $b6f4(t0)
8004217C	sra    v0, v0, $10
80042180	sw     v0, $0010(sp)
80042184	sra    v1, v1, $01
80042188	jal    funcc1a8c [$800c1a8c]
8004218C	sw     v1, $b6f4(t0)
80042190	j      L475b4 [$800475b4]
80042194	addu   v0, zero, zero
80042198	lui    v0, $8008
8004219C	lw     v0, $b6f4(v0)
800421A0	nop
800421A4	andi   v0, v0, $0001
800421A8	beq    v0, zero, L421c8 [$800421c8]
800421AC	lui    v0, $8008
800421B0	jal    func52da0 [$80052da0]
800421B4	nop
800421B8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800421BC	nop
800421C0	j      L421e4 [$800421e4]
800421C4	addu   a0, v0, zero

L421c8:	; 800421C8
800421C8	lw     v1, $b70c(v0)
800421CC	nop
800421D0	lw     v0, $0000(v1)
800421D4	nop
800421D8	lbu    a0, $0000(v0)
800421DC	addiu  v0, v0, $0001
800421E0	sw     v0, $0000(v1)

L421e4:	; 800421E4
800421E4	addu   s2, a0, zero
800421E8	lui    a1, $8008
800421EC	lui    a0, $8008
800421F0	lw     v0, $b6f4(a1)
800421F4	addiu  v1, zero, $0001
800421F8	sw     v1, $b6f8(a0)
800421FC	srav   v0, v1, v0
80042200	sw     v0, $b6f4(a1)
80042204	and    v0, v0, v1
80042208	beq    v0, zero, L42228 [$80042228]
8004220C	lui    v0, $8008
80042210	jal    func52da0 [$80052da0]
80042214	nop
80042218	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004221C	nop
80042220	j      L42244 [$80042244]
80042224	addu   a1, v0, zero

L42228:	; 80042228
80042228	lw     v1, $b70c(v0)
8004222C	nop
80042230	lw     v0, $0000(v1)
80042234	nop
80042238	lbu    a1, $0000(v0)
8004223C	addiu  v0, v0, $0001
80042240	sw     v0, $0000(v1)

L42244:	; 80042244
80042244	addu   a0, s2, zero
80042248	lui    a3, $8008
8004224C	lui    a2, $8008
80042250	lw     v0, $b6f4(a3)
80042254	addiu  v1, zero, $0001
80042258	sw     v1, $b6f8(a2)
8004225C	srav   v0, v1, v0
80042260	jal    funcc1668 [$800c1668]
80042264	sw     v0, $b6f4(a3)
80042268	j      L475b4 [$800475b4]
8004226C	addu   v0, zero, zero
80042270	lui    v0, $8008
80042274	lw     v0, $b6f4(v0)
80042278	nop
8004227C	andi   v0, v0, $0001
80042280	beq    v0, zero, L422a0 [$800422a0]
80042284	lui    v0, $8008
80042288	jal    func52da0 [$80052da0]
8004228C	nop
80042290	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042294	nop
80042298	j      L422bc [$800422bc]
8004229C	addu   a0, v0, zero

L422a0:	; 800422A0
800422A0	lw     v1, $b70c(v0)
800422A4	nop
800422A8	lw     v0, $0000(v1)
800422AC	nop
800422B0	lbu    a0, $0000(v0)
800422B4	addiu  v0, v0, $0001
800422B8	sw     v0, $0000(v1)

L422bc:	; 800422BC
800422BC	addu   s2, a0, zero
800422C0	lui    a1, $8008
800422C4	lui    a0, $8008
800422C8	lw     v0, $b6f4(a1)
800422CC	addiu  v1, zero, $0001
800422D0	sw     v1, $b6f8(a0)
800422D4	srav   v0, v1, v0
800422D8	sw     v0, $b6f4(a1)
800422DC	and    v0, v0, v1
800422E0	beq    v0, zero, L42300 [$80042300]
800422E4	lui    v0, $8008
800422E8	jal    func52da0 [$80052da0]
800422EC	nop
800422F0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800422F4	nop
800422F8	j      L42338 [$80042338]
800422FC	addu   a1, v0, zero

L42300:	; 80042300
80042300	lw     a0, $b70c(v0)
80042304	nop
80042308	lw     v0, $0000(a0)
8004230C	nop
80042310	lbu    a1, $0000(v0)
80042314	addiu  v0, v0, $0001
80042318	sw     v0, $0000(a0)
8004231C	lbu    v1, $0000(v0)
80042320	addiu  v0, v0, $0001
80042324	sw     v0, $0000(a0)
80042328	sll    v1, v1, $08
8004232C	or     a1, a1, v1
80042330	sll    v0, a1, $10
80042334	sra    a1, v0, $10

L42338:	; 80042338
80042338	addu   s3, a1, zero
8004233C	lui    a1, $8008
80042340	lui    a0, $8008
80042344	lw     v0, $b6f4(a1)
80042348	addiu  v1, zero, $0001
8004234C	sw     v1, $b6f8(a0)
80042350	srav   v0, v1, v0
80042354	sw     v0, $b6f4(a1)
80042358	and    v0, v0, v1
8004235C	beq    v0, zero, L4237c [$8004237c]
80042360	lui    v0, $8008
80042364	jal    func52da0 [$80052da0]
80042368	nop
8004236C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042370	nop
80042374	j      L423b4 [$800423b4]
80042378	addu   a2, v0, zero

L4237c:	; 8004237C
8004237C	lw     a0, $b70c(v0)
80042380	nop
80042384	lw     v0, $0000(a0)
80042388	nop
8004238C	lbu    a2, $0000(v0)
80042390	addiu  v0, v0, $0001
80042394	sw     v0, $0000(a0)
80042398	lbu    v1, $0000(v0)
8004239C	addiu  v0, v0, $0001
800423A0	sw     v0, $0000(a0)
800423A4	sll    v1, v1, $08
800423A8	or     a2, a2, v1
800423AC	sll    v0, a2, $10
800423B0	sra    a2, v0, $10

L423b4:	; 800423B4
800423B4	lui    a1, $8008
800423B8	lui    a0, $8008
800423BC	lw     v0, $b6f4(a1)
800423C0	addiu  v1, zero, $0001
800423C4	sw     v1, $b6f8(a0)
800423C8	srav   v0, v1, v0
800423CC	sw     v0, $b6f4(a1)
800423D0	and    v0, v0, v1
800423D4	beq    v0, zero, L423f4 [$800423f4]
800423D8	addu   s5, a2, zero
800423DC	jal    func52da0 [$80052da0]
800423E0	nop
800423E4	jal    system_read_from_stack_command_not_from_script [$80052d40]
800423E8	nop
800423EC	j      L42430 [$80042430]
800423F0	addu   a3, v0, zero

L423f4:	; 800423F4
800423F4	lui    v0, $8008
800423F8	lw     a0, $b70c(v0)
800423FC	nop
80042400	lw     v0, $0000(a0)
80042404	nop
80042408	lbu    a3, $0000(v0)
8004240C	addiu  v0, v0, $0001
80042410	sw     v0, $0000(a0)
80042414	lbu    v1, $0000(v0)
80042418	addiu  v0, v0, $0001
8004241C	sw     v0, $0000(a0)
80042420	sll    v1, v1, $08
80042424	or     a3, a3, v1
80042428	sll    v0, a3, $10
8004242C	sra    a3, v0, $10

L42430:	; 80042430
80042430	lui    a1, $8008
80042434	lui    a0, $8008
80042438	lw     v0, $b6f4(a1)
8004243C	addiu  v1, zero, $0001
80042440	sw     v1, $b6f8(a0)
80042444	srav   v0, v1, v0
80042448	sw     v0, $b6f4(a1)
8004244C	and    v0, v0, v1
80042450	beq    v0, zero, L42470 [$80042470]
80042454	addu   s1, a3, zero
80042458	jal    func52da0 [$80052da0]
8004245C	nop
80042460	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042464	nop
80042468	j      L424ac [$800424ac]
8004246C	addu   t1, v0, zero

L42470:	; 80042470
80042470	lui    v0, $8008
80042474	lw     a0, $b70c(v0)
80042478	nop
8004247C	lw     v0, $0000(a0)
80042480	nop
80042484	lbu    t1, $0000(v0)
80042488	addiu  v0, v0, $0001
8004248C	sw     v0, $0000(a0)
80042490	lbu    v1, $0000(v0)
80042494	addiu  v0, v0, $0001
80042498	sw     v0, $0000(a0)
8004249C	sll    v1, v1, $08
800424A0	or     t1, t1, v1
800424A4	sll    v0, t1, $10
800424A8	sra    t1, v0, $10

L424ac:	; 800424AC
800424AC	addu   a0, s2, zero
800424B0	sll    a1, s3, $10
800424B4	sra    a1, a1, $10
800424B8	sll    a2, s5, $10
800424BC	sra    a2, a2, $10
800424C0	sll    a3, s1, $10
800424C4	sra    a3, a3, $10
800424C8	lui    v1, $8008
800424CC	addiu  v0, zero, $0001
800424D0	lui    t0, $8008
800424D4	sw     v0, $b6f8(v1)
800424D8	sll    v0, t1, $10
800424DC	lw     v1, $b6f4(t0)
800424E0	sra    v0, v0, $10
800424E4	sw     v0, $0010(sp)
800424E8	sra    v1, v1, $01
800424EC	jal    funcc119c [$800c119c]
800424F0	sw     v1, $b6f4(t0)
800424F4	j      L475b4 [$800475b4]
800424F8	addu   v0, zero, zero
800424FC	lui    v0, $8008
80042500	lw     v0, $b6f4(v0)
80042504	nop
80042508	andi   v0, v0, $0001
8004250C	beq    v0, zero, L4252c [$8004252c]
80042510	lui    v0, $8008
80042514	jal    func52da0 [$80052da0]
80042518	nop
8004251C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042520	nop
80042524	j      L42548 [$80042548]
80042528	addu   a0, v0, zero

L4252c:	; 8004252C
8004252C	lw     v1, $b70c(v0)
80042530	nop
80042534	lw     v0, $0000(v1)
80042538	nop
8004253C	lbu    a0, $0000(v0)
80042540	addiu  v0, v0, $0001
80042544	sw     v0, $0000(v1)

L42548:	; 80042548
80042548	addu   s2, a0, zero
8004254C	lui    a1, $8008
80042550	lui    a0, $8008
80042554	lw     v0, $b6f4(a1)
80042558	addiu  v1, zero, $0001
8004255C	sw     v1, $b6f8(a0)
80042560	srav   v0, v1, v0
80042564	sw     v0, $b6f4(a1)
80042568	and    v0, v0, v1
8004256C	beq    v0, zero, L4258c [$8004258c]
80042570	lui    v0, $8008
80042574	jal    func52da0 [$80052da0]
80042578	nop
8004257C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042580	nop
80042584	j      L425c4 [$800425c4]
80042588	addu   a1, v0, zero

L4258c:	; 8004258C
8004258C	lw     a0, $b70c(v0)
80042590	nop
80042594	lw     v0, $0000(a0)
80042598	nop
8004259C	lbu    a1, $0000(v0)
800425A0	addiu  v0, v0, $0001
800425A4	sw     v0, $0000(a0)
800425A8	lbu    v1, $0000(v0)
800425AC	addiu  v0, v0, $0001
800425B0	sw     v0, $0000(a0)
800425B4	sll    v1, v1, $08
800425B8	or     a1, a1, v1
800425BC	sll    v0, a1, $10
800425C0	sra    a1, v0, $10

L425c4:	; 800425C4
800425C4	addu   s3, a1, zero
800425C8	lui    a1, $8008
800425CC	lui    a0, $8008
800425D0	lw     v0, $b6f4(a1)
800425D4	addiu  v1, zero, $0001
800425D8	sw     v1, $b6f8(a0)
800425DC	srav   v0, v1, v0
800425E0	sw     v0, $b6f4(a1)
800425E4	and    v0, v0, v1
800425E8	beq    v0, zero, L42608 [$80042608]
800425EC	lui    v0, $8008
800425F0	jal    func52da0 [$80052da0]
800425F4	nop
800425F8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800425FC	nop
80042600	j      L42640 [$80042640]
80042604	addu   a2, v0, zero

L42608:	; 80042608
80042608	lw     a0, $b70c(v0)
8004260C	nop
80042610	lw     v0, $0000(a0)
80042614	nop
80042618	lbu    a2, $0000(v0)
8004261C	addiu  v0, v0, $0001
80042620	sw     v0, $0000(a0)
80042624	lbu    v1, $0000(v0)
80042628	addiu  v0, v0, $0001
8004262C	sw     v0, $0000(a0)
80042630	sll    v1, v1, $08
80042634	or     a2, a2, v1
80042638	sll    v0, a2, $10
8004263C	sra    a2, v0, $10

L42640:	; 80042640
80042640	addu   a0, s2, zero
80042644	addu   a1, s3, zero
80042648	lui    t0, $8008
8004264C	lui    a3, $8008
80042650	lw     v0, $b6f4(t0)
80042654	addiu  v1, zero, $0001
80042658	sw     v1, $b6f8(a3)
8004265C	srav   v0, v1, v0
80042660	jal    funcc11c8 [$800c11c8]
80042664	sw     v0, $b6f4(t0)
80042668	j      L475b4 [$800475b4]
8004266C	addu   v0, zero, zero
80042670	lui    v0, $8008
80042674	lw     v0, $b6f4(v0)
80042678	nop
8004267C	andi   v0, v0, $0001
80042680	beq    v0, zero, L426a0 [$800426a0]
80042684	lui    v0, $8008
80042688	jal    func52da0 [$80052da0]
8004268C	nop
80042690	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042694	nop
80042698	j      L426bc [$800426bc]
8004269C	addu   a0, v0, zero

L426a0:	; 800426A0
800426A0	lw     v1, $b70c(v0)
800426A4	nop
800426A8	lw     v0, $0000(v1)
800426AC	nop
800426B0	lbu    a0, $0000(v0)
800426B4	addiu  v0, v0, $0001
800426B8	sw     v0, $0000(v1)

L426bc:	; 800426BC
800426BC	addu   s2, a0, zero
800426C0	lui    a1, $8008
800426C4	lui    a0, $8008
800426C8	lw     v0, $b6f4(a1)
800426CC	addiu  v1, zero, $0001
800426D0	sw     v1, $b6f8(a0)
800426D4	srav   v0, v1, v0
800426D8	sw     v0, $b6f4(a1)
800426DC	and    v0, v0, v1
800426E0	beq    v0, zero, L42700 [$80042700]
800426E4	lui    v0, $8008
800426E8	jal    func52da0 [$80052da0]
800426EC	nop
800426F0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800426F4	nop
800426F8	j      L4271c [$8004271c]
800426FC	addu   a0, v0, zero

L42700:	; 80042700
80042700	lw     v1, $b70c(v0)
80042704	nop
80042708	lw     v0, $0000(v1)
8004270C	nop
80042710	lbu    a0, $0000(v0)
80042714	addiu  v0, v0, $0001
80042718	sw     v0, $0000(v1)

L4271c:	; 8004271C
8004271C	addu   s3, a0, zero
80042720	lui    a1, $8008
80042724	lui    a0, $8008
80042728	lw     v0, $b6f4(a1)
8004272C	addiu  v1, zero, $0001
80042730	sw     v1, $b6f8(a0)
80042734	srav   v0, v1, v0
80042738	sw     v0, $b6f4(a1)
8004273C	and    v0, v0, v1
80042740	beq    v0, zero, L42760 [$80042760]
80042744	lui    v0, $8008
80042748	jal    func52da0 [$80052da0]
8004274C	nop
80042750	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042754	nop
80042758	j      L42798 [$80042798]
8004275C	addu   a2, v0, zero

L42760:	; 80042760
80042760	lw     a0, $b70c(v0)
80042764	nop
80042768	lw     v0, $0000(a0)
8004276C	nop
80042770	lbu    a2, $0000(v0)
80042774	addiu  v0, v0, $0001
80042778	sw     v0, $0000(a0)
8004277C	lbu    v1, $0000(v0)
80042780	addiu  v0, v0, $0001
80042784	sw     v0, $0000(a0)
80042788	sll    v1, v1, $08
8004278C	or     a2, a2, v1
80042790	sll    v0, a2, $10
80042794	sra    a2, v0, $10

L42798:	; 80042798
80042798	lui    a1, $8008
8004279C	lui    a0, $8008
800427A0	lw     v0, $b6f4(a1)
800427A4	addiu  v1, zero, $0001
800427A8	sw     v1, $b6f8(a0)
800427AC	srav   v0, v1, v0
800427B0	sw     v0, $b6f4(a1)
800427B4	and    v0, v0, v1
800427B8	beq    v0, zero, L427d8 [$800427d8]
800427BC	addu   s5, a2, zero
800427C0	jal    func52da0 [$80052da0]
800427C4	nop
800427C8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800427CC	nop
800427D0	j      L42814 [$80042814]
800427D4	addu   a3, v0, zero

L427d8:	; 800427D8
800427D8	lui    v0, $8008
800427DC	lw     a0, $b70c(v0)
800427E0	nop
800427E4	lw     v0, $0000(a0)
800427E8	nop
800427EC	lbu    a3, $0000(v0)
800427F0	addiu  v0, v0, $0001
800427F4	sw     v0, $0000(a0)
800427F8	lbu    v1, $0000(v0)
800427FC	addiu  v0, v0, $0001
80042800	sw     v0, $0000(a0)
80042804	sll    v1, v1, $08
80042808	or     a3, a3, v1
8004280C	sll    v0, a3, $10
80042810	sra    a3, v0, $10

L42814:	; 80042814
80042814	lui    a1, $8008
80042818	lui    a0, $8008
8004281C	lw     v0, $b6f4(a1)
80042820	addiu  v1, zero, $0001

L42824:	; 80042824
80042824	sw     v1, $b6f8(a0)
80042828	srav   v0, v1, v0
8004282C	sw     v0, $b6f4(a1)
80042830	and    v0, v0, v1
80042834	beq    v0, zero, L42854 [$80042854]
80042838	addu   s1, a3, zero
8004283C	jal    func52da0 [$80052da0]
80042840	nop
80042844	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042848	nop
8004284C	j      L42874 [$80042874]
80042850	addu   t2, v0, zero

L42854:	; 80042854
80042854	lui    v0, $8008
80042858	lw     v1, $b70c(v0)
8004285C	nop
80042860	lw     v0, $0000(v1)
80042864	nop
80042868	lbu    t2, $0000(v0)
8004286C	addiu  v0, v0, $0001
80042870	sw     v0, $0000(v1)

L42874:	; 80042874
80042874	addu   a0, s2, zero
80042878	addu   a1, s3, zero
8004287C	addu   a2, s5, zero
80042880	addu   a3, s1, zero
80042884	lui    t1, $8008
80042888	lui    t0, $8008
8004288C	lw     v1, $b6f4(t1)
80042890	addiu  v0, zero, $0001
80042894	sw     v0, $b6f8(t0)
80042898	sw     t2, $0010(sp)
8004289C	srav   v1, v0, v1
800428A0	jal    funcc152c [$800c152c]
800428A4	sw     v1, $b6f4(t1)
800428A8	j      L475b4 [$800475b4]
800428AC	addu   v0, zero, zero

80042924	addiu  a0, sp, $002c
80042928	jal    funcc0e6c [$800c0e6c]
8004292C	addiu  a1, sp, $002e
80042930	addu   v0, zero, zero
80042934	lh     a0, $002c(sp)
80042938	lui    v1, $8008
8004293C	sw     a0, $ae2c(v1)
80042940	lh     a0, $002e(sp)
80042944	lui    v1, $8008
80042948	j      L475b4 [$800475b4]
8004294C	sw     a0, $ae30(v1)

80042D80	jal    system_get_entity_script_data_pointer_from_script [$80038150]
80042D84	nop
80042D88	addu   a0, v0, zero
80042D8C	beq    a0, zero, L42dc4 [$80042dc4]
80042D90	ori    v0, zero, $ffff
80042D94	lhu    v1, $0034(a0)
80042D98	nop
80042D9C	beq    v1, v0, L42dc8 [$80042dc8]
80042DA0	addu   s0, zero, zero
80042DA4	lbu    a0, $003b(a0)
80042DA8	jal    func1e350 [$8001e350]
80042DAC	nop
80042DB0	beq    v0, zero, L42dc8 [$80042dc8]
80042DB4	nop
80042DB8	lw     s0, $0008(v0)
80042DBC	j      L42dcc [$80042dcc]
80042DC0	lui    v0, $8008

L42dc4:	; 80042DC4
80042DC4	addu   s0, zero, zero

L42dc8:	; 80042DC8
80042DC8	lui    v0, $8008

L42dcc:	; 80042DCC
80042DCC	lw     v0, $b6f4(v0)
80042DD0	nop
80042DD4	andi   v0, v0, $0001
80042DD8	beq    v0, zero, L42df8 [$80042df8]
80042DDC	lui    v0, $8008
80042DE0	jal    func52da0 [$80052da0]
80042DE4	nop
80042DE8	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042DEC	nop
80042DF0	j      L42e14 [$80042e14]
80042DF4	addu   a0, v0, zero

L42df8:	; 80042DF8
80042DF8	lw     v1, $b70c(v0)
80042DFC	nop
80042E00	lw     v0, $0000(v1)
80042E04	nop
80042E08	lbu    a0, $0000(v0)
80042E0C	addiu  v0, v0, $0001
80042E10	sw     v0, $0000(v1)

L42e14:	; 80042E14
80042E14	addu   s2, a0, zero
80042E18	lui    a0, $8008
80042E1C	lui    v1, $8008
80042E20	lw     v0, $b6f4(a0)
80042E24	addiu  a1, zero, $0001
80042E28	sw     a1, $b6f8(v1)
80042E2C	srav   v0, a1, v0
80042E30	beq    s0, zero, L39ea8 [$80039ea8]
80042E34	sw     v0, $b6f4(a0)
80042E38	sllv   v0, s2, a1
80042E3C	lw     v1, $0014(s0)
80042E40	nor    v0, zero, v0
80042E44	and    v1, v1, v0
80042E48	j      L39ea8 [$80039ea8]
80042E4C	sw     v1, $0014(s0)

80042FC4	lui    v0, $8008
80042FC8	lw     v1, $aecc(v0)
80042FCC	addu   v0, zero, zero
80042FD0	j      L475b4 [$800475b4]
80042FD4	sh     zero, $1700(v1)
80042FD8	lui    v0, $8008
80042FDC	lw     v0, $b6f4(v0)
80042FE0	nop
80042FE4	andi   v0, v0, $0001
80042FE8	beq    v0, zero, L43008 [$80043008]
80042FEC	lui    v0, $8008
80042FF0	jal    func52da0 [$80052da0]
80042FF4	nop
80042FF8	jal    system_read_from_stack_command_not_from_script [$80052d40]
80042FFC	nop
80043000	j      L43024 [$80043024]
80043004	addu   a0, v0, zero

L43008:	; 80043008
80043008	lw     v1, $b70c(v0)
8004300C	nop
80043010	lw     v0, $0000(v1)
80043014	nop
80043018	lbu    a0, $0000(v0)
8004301C	addiu  v0, v0, $0001
80043020	sw     v0, $0000(v1)

L43024:	; 80043024
80043024	addu   s2, a0, zero
80043028	lui    a1, $8008
8004302C	lui    a0, $8008
80043030	lw     v0, $b6f4(a1)
80043034	addiu  v1, zero, $0001
80043038	sw     v1, $b6f8(a0)
8004303C	srav   v0, v1, v0
80043040	sw     v0, $b6f4(a1)
80043044	and    v0, v0, v1
80043048	beq    v0, zero, L43068 [$80043068]
8004304C	lui    v0, $8008
80043050	jal    func52da0 [$80052da0]
80043054	nop
80043058	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004305C	nop
80043060	j      L430a0 [$800430a0]
80043064	addu   a3, v0, zero

L43068:	; 80043068
80043068	lw     a0, $b70c(v0)
8004306C	nop
80043070	lw     v0, $0000(a0)
80043074	nop
80043078	lbu    a3, $0000(v0)
8004307C	addiu  v0, v0, $0001
80043080	sw     v0, $0000(a0)
80043084	lbu    v1, $0000(v0)
80043088	addiu  v0, v0, $0001
8004308C	sw     v0, $0000(a0)
80043090	sll    v1, v1, $08
80043094	or     a3, a3, v1
80043098	sll    v0, a3, $10
8004309C	sra    a3, v0, $10

L430a0:	; 800430A0
800430A0	addu   v0, zero, zero
800430A4	lui    a0, $8008
800430A8	addiu  v1, zero, $0001
800430AC	lui    a2, $8008
800430B0	sw     v1, $b6f8(a0)
800430B4	lui    v1, $8007
800430B8	addiu  v1, v1, $3998
800430BC	sll    a1, s2, $02
800430C0	addu   a1, a1, v1
800430C4	lw     v1, $b6f4(a2)
800430C8	lw     a0, $0000(a1)
800430CC	sra    v1, v1, $01
800430D0	or     a0, a0, a3
800430D4	sw     v1, $b6f4(a2)
800430D8	j      L475b4 [$800475b4]
800430DC	sw     a0, $0000(a1)

800430E0	lui    v0, $8008
800430E4	lw     v0, $b6f4(v0)
800430E8	nop
800430EC	andi   v0, v0, $0001
800430F0	beq    v0, zero, L43110 [$80043110]
800430F4	lui    v0, $8008
800430F8	jal    func52da0 [$80052da0]
800430FC	nop
80043100	jal    system_read_from_stack_command_not_from_script [$80052d40]
80043104	nop
80043108	j      L4312c [$8004312c]
8004310C	addu   a0, v0, zero

L43110:	; 80043110
80043110	lw     v1, $b70c(v0)
80043114	nop
80043118	lw     v0, $0000(v1)
8004311C	nop
80043120	lbu    a0, $0000(v0)
80043124	addiu  v0, v0, $0001
80043128	sw     v0, $0000(v1)

L4312c:	; 8004312C
8004312C	addu   s2, a0, zero
80043130	lui    a1, $8008
80043134	lui    a0, $8008
80043138	lw     v0, $b6f4(a1)
8004313C	addiu  v1, zero, $0001
80043140	sw     v1, $b6f8(a0)
80043144	srav   v0, v1, v0
80043148	sw     v0, $b6f4(a1)
8004314C	and    v0, v0, v1
80043150	beq    v0, zero, L43170 [$80043170]
80043154	lui    v0, $8008
80043158	jal    func52da0 [$80052da0]
8004315C	nop
80043160	jal    system_read_from_stack_command_not_from_script [$80052d40]
80043164	nop
80043168	j      L431a8 [$800431a8]
8004316C	addu   a3, v0, zero

L43170:	; 80043170
80043170	lw     a0, $b70c(v0)
80043174	nop
80043178	lw     v0, $0000(a0)
8004317C	nop
80043180	lbu    a3, $0000(v0)
80043184	addiu  v0, v0, $0001
80043188	sw     v0, $0000(a0)
8004318C	lbu    v1, $0000(v0)
80043190	addiu  v0, v0, $0001
80043194	sw     v0, $0000(a0)
80043198	sll    v1, v1, $08
8004319C	or     a3, a3, v1
800431A0	sll    v0, a3, $10
800431A4	sra    a3, v0, $10

L431a8:	; 800431A8
800431A8	addu   v0, zero, zero
800431AC	lui    a2, $8008
800431B0	lui    a1, $8008
800431B4	lw     v1, $b6f4(a2)
800431B8	addiu  a0, zero, $0001
800431BC	sw     a0, $b6f8(a1)
800431C0	srav   v1, a0, v1
800431C4	sw     v1, $b6f4(a2)
800431C8	lui    v1, $8007
800431CC	addiu  v1, v1, $3998
800431D0	sll    a0, s2, $02
800431D4	addu   a0, a0, v1
800431D8	lw     v1, $0000(a0)
800431DC	nor    a1, zero, a3
800431E0	and    v1, v1, a1
800431E4	j      L475b4 [$800475b4]
800431E8	sw     v1, $0000(a0)

8004391C	lui    v0, $8008
80043920	lw     v0, $b6f4(v0)
80043924	nop
80043928	andi   v0, v0, $0001
8004392C	beq    v0, zero, L4394c [$8004394c]
80043930	lui    v0, $8008
80043934	jal    func52da0 [$80052da0]
80043938	nop
8004393C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80043940	nop
80043944	j      L43984 [$80043984]
80043948	addu   a1, v0, zero

L4394c:	; 8004394C
8004394C	lw     a0, $b70c(v0)
80043950	nop
80043954	lw     v0, $0000(a0)
80043958	nop
8004395C	lbu    a1, $0000(v0)
80043960	addiu  v0, v0, $0001
80043964	sw     v0, $0000(a0)
80043968	lbu    v1, $0000(v0)
8004396C	addiu  v0, v0, $0001
80043970	sw     v0, $0000(a0)
80043974	sll    v1, v1, $08
80043978	or     a1, a1, v1
8004397C	sll    v0, a1, $10
80043980	sra    a1, v0, $10

L43984:	; 80043984
80043984	addu   s2, a1, zero
80043988	lui    a1, $8008
8004398C	lui    a0, $8008
80043990	lw     v0, $b6f4(a1)
80043994	addiu  v1, zero, $0001
80043998	sw     v1, $b6f8(a0)
8004399C	srav   v0, v1, v0
800439A0	sw     v0, $b6f4(a1)
800439A4	and    v0, v0, v1
800439A8	beq    v0, zero, L439c8 [$800439c8]
800439AC	lui    v0, $8008
800439B0	jal    func52da0 [$80052da0]
800439B4	nop
800439B8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800439BC	nop
800439C0	j      L43a00 [$80043a00]
800439C4	addu   a1, v0, zero

L439c8:	; 800439C8
800439C8	lw     a0, $b70c(v0)
800439CC	nop
800439D0	lw     v0, $0000(a0)
800439D4	nop
800439D8	lbu    a1, $0000(v0)
800439DC	addiu  v0, v0, $0001
800439E0	sw     v0, $0000(a0)
800439E4	lbu    v1, $0000(v0)
800439E8	addiu  v0, v0, $0001
800439EC	sw     v0, $0000(a0)
800439F0	sll    v1, v1, $08
800439F4	or     a1, a1, v1
800439F8	sll    v0, a1, $10
800439FC	sra    a1, v0, $10

L43a00:	; 80043A00
80043A00	addu   s3, a1, zero
80043A04	lui    a1, $8008
80043A08	lui    a0, $8008
80043A0C	lw     v0, $b6f4(a1)
80043A10	addiu  v1, zero, $0001
80043A14	sw     v1, $b6f8(a0)
80043A18	srav   v0, v1, v0
80043A1C	sw     v0, $b6f4(a1)
80043A20	and    v0, v0, v1
80043A24	beq    v0, zero, L43a44 [$80043a44]
80043A28	lui    v0, $8008
80043A2C	jal    func52da0 [$80052da0]
80043A30	nop
80043A34	jal    system_read_from_stack_command_not_from_script [$80052d40]
80043A38	nop
80043A3C	j      L43a7c [$80043a7c]
80043A40	addu   a2, v0, zero

L43a44:	; 80043A44
80043A44	lw     a0, $b70c(v0)
80043A48	nop
80043A4C	lw     v0, $0000(a0)
80043A50	nop
80043A54	lbu    a2, $0000(v0)
80043A58	addiu  v0, v0, $0001
80043A5C	sw     v0, $0000(a0)
80043A60	lbu    v1, $0000(v0)
80043A64	addiu  v0, v0, $0001
80043A68	sw     v0, $0000(a0)
80043A6C	sll    v1, v1, $08
80043A70	or     a2, a2, v1
80043A74	sll    v0, a2, $10
80043A78	sra    a2, v0, $10

L43a7c:	; 80043A7C
80043A7C	sll    a0, s2, $10
80043A80	sra    a0, a0, $10
80043A84	sll    a1, s3, $10
80043A88	sra    a1, a1, $10
80043A8C	sll    a2, a2, $10
80043A90	sra    a2, a2, $10
80043A94	addiu  a3, sp, $0030
80043A98	lui    v1, $8008
80043A9C	addiu  v0, zero, $0001
80043AA0	lui    s0, $8008
80043AA4	sw     v0, $b6f8(v1)
80043AA8	lw     v0, $b6f4(s0)
80043AAC	addiu  v1, sp, $0031
80043AB0	sw     v1, $0010(sp)
80043AB4	sra    v0, v0, $01
80043AB8	jal    funcb1a20 [$800b1a20]
80043ABC	sw     v0, $b6f4(s0)
80043AC0	lbu    v1, $0030(sp)
80043AC4	lui    v0, $8008
80043AC8	sw     v1, $ae38(v0)
80043ACC	lui    v1, $8008
80043AD0	lw     v0, $b6f4(s0)
80043AD4	nop
80043AD8	andi   v0, v0, $0001
80043ADC	beq    v0, zero, L43afc [$80043afc]
80043AE0	addiu  s0, v1, $ae3c (=-$51c4)
80043AE4	jal    func52da0 [$80052da0]
80043AE8	nop
80043AEC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80043AF0	nop
80043AF4	j      L43b1c [$80043b1c]
80043AF8	addu   a0, v0, zero

L43afc:	; 80043AFC
80043AFC	lui    v0, $8008
80043B00	lw     v1, $b70c(v0)
80043B04	nop
80043B08	lw     v0, $0000(v1)
80043B0C	nop
80043B10	lbu    a0, $0000(v0)
80043B14	addiu  v0, v0, $0001
80043B18	sw     v0, $0000(v1)

L43b1c:	; 80043B1C
80043B1C	lbu    v0, $0031(sp)
80043B20	nop
80043B24	mult   v0, a0
80043B28	lui    v1, $8008
80043B2C	lui    a1, $8008
80043B30	addiu  v0, zero, $0001
80043B34	lui    a0, $8008
80043B38	sw     v0, $b6f8(v1)
80043B3C	mflo   t3
80043B40	sra    v0, t3, $07
80043B44	sw     v0, $0000(s0)
80043B48	lw     v0, $b6f4(a0)
80043B4C	lw     v1, $ae3c(a1)
80043B50	sra    v0, v0, $01
80043B54	slti   v1, v1, $0080
80043B58	bne    v1, zero, L39ea8 [$80039ea8]
80043B5C	sw     v0, $b6f4(a0)
80043B60	addiu  v0, zero, $007f
80043B64	j      L39ea8 [$80039ea8]
80043B68	sw     v0, $ae3c(a1)
80043B6C	jal    system_get_entity_script_data_pointer_from_script [$80038150]
80043B70	nop
80043B74	addu   s4, v0, zero
80043B78	addiu  a3, sp, $0032
80043B7C	lh     a0, $0014(s4)
80043B80	lh     a1, $0018(s4)
80043B84	lh     a2, $001c(s4)
80043B88	addiu  v0, sp, $0033
80043B8C	jal    funcb1a20 [$800b1a20]
80043B90	sw     v0, $0010(sp)
80043B94	lbu    v1, $0032(sp)
80043B98	lui    v0, $8008
80043B9C	sw     v1, $ae38(v0)
80043BA0	lui    v1, $8008
80043BA4	lui    v0, $8008
80043BA8	lw     v0, $b6f4(v0)
80043BAC	nop
80043BB0	andi   v0, v0, $0001
80043BB4	beq    v0, zero, L43bd4 [$80043bd4]
80043BB8	addiu  s0, v1, $ae3c (=-$51c4)
80043BBC	jal    func52da0 [$80052da0]
80043BC0	nop
80043BC4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80043BC8	nop
80043BCC	j      L43bf4 [$80043bf4]
80043BD0	addu   a0, v0, zero

L43bd4:	; 80043BD4
80043BD4	lui    v0, $8008
80043BD8	lw     v1, $b70c(v0)
80043BDC	nop
80043BE0	lw     v0, $0000(v1)
80043BE4	nop
80043BE8	lbu    a0, $0000(v0)
80043BEC	addiu  v0, v0, $0001
80043BF0	sw     v0, $0000(v1)

L43bf4:	; 80043BF4
80043BF4	lbu    v0, $0033(sp)
80043BF8	nop
80043BFC	mult   v0, a0
80043C00	lui    v1, $8008
80043C04	lui    a1, $8008

func43c08:	; 80043C08
80043C08	addiu  v0, zero, $0001
80043C0C	lui    a0, $8008
80043C10	sw     v0, $b6f8(v1)
80043C14	mflo   t3
80043C18	sra    v0, t3, $07
80043C1C	sw     v0, $0000(s0)
80043C20	lw     v0, $b6f4(a0)
80043C24	lw     v1, $ae3c(a1)
80043C28	sra    v0, v0, $01
80043C2C	slti   v1, v1, $0080
80043C30	bne    v1, zero, L39ea8 [$80039ea8]
80043C34	sw     v0, $b6f4(a0)
80043C38	addiu  v0, zero, $007f
80043C3C	j      L39ea8 [$80039ea8]
80043C40	sw     v0, $ae3c(a1)

80044138	lui    v0, $8008
8004413C	lw     v0, $b6f4(v0)
80044140	nop
80044144	andi   v0, v0, $0001
80044148	beq    v0, zero, L44168 [$80044168]
8004414C	lui    v0, $8008
80044150	jal    func52da0 [$80052da0]
80044154	nop
80044158	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004415C	nop
80044160	j      L441a0 [$800441a0]
80044164	addu   a1, v0, zero

L44168:	; 80044168
80044168	lw     a0, $b70c(v0)
8004416C	nop
80044170	lw     v0, $0000(a0)
80044174	nop
80044178	lbu    a1, $0000(v0)
8004417C	addiu  v0, v0, $0001
80044180	sw     v0, $0000(a0)
80044184	lbu    v1, $0000(v0)
80044188	addiu  v0, v0, $0001
8004418C	sw     v0, $0000(a0)
80044190	sll    v1, v1, $08
80044194	or     a1, a1, v1
80044198	sll    v0, a1, $10
8004419C	sra    a1, v0, $10

L441a0:	; 800441A0
800441A0	addu   s2, a1, zero
800441A4	sra    a0, s2, $0e
800441A8	andi   a0, a0, $0003
800441AC	andi   a1, s2, $3fff
800441B0	lui    a3, $8008
800441B4	lui    a2, $8008
800441B8	lw     v0, $b6f4(a3)
800441BC	addiu  v1, zero, $0001
800441C0	sw     v1, $b6f8(a2)
800441C4	srav   v0, v1, v0
800441C8	jal    funcb5004 [$800b5004]
800441CC	sw     v0, $b6f4(a3)
800441D0	j      L475b4 [$800475b4]
800441D4	addiu  v0, zero, $0001

8004435C	lui    v0, $8008
80044360	lw     v0, $b6f4(v0)
80044364	nop
80044368	andi   v0, v0, $0001
8004436C	beq    v0, zero, L4438c [$8004438c]
80044370	lui    v0, $8008
80044374	jal    func52da0 [$80052da0]
80044378	nop
8004437C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80044380	nop
80044384	j      L443c4 [$800443c4]
80044388	addu   a1, v0, zero

L4438c:	; 8004438C
8004438C	lw     a0, $b70c(v0)
80044390	nop
80044394	lw     v0, $0000(a0)
80044398	nop
8004439C	lbu    a1, $0000(v0)
800443A0	addiu  v0, v0, $0001
800443A4	sw     v0, $0000(a0)
800443A8	lbu    v1, $0000(v0)
800443AC	addiu  v0, v0, $0001
800443B0	sw     v0, $0000(a0)
800443B4	sll    v1, v1, $08
800443B8	or     a1, a1, v1
800443BC	sll    v0, a1, $10
800443C0	sra    a1, v0, $10

L443c4:	; 800443C4
800443C4	addu   s2, a1, zero
800443C8	lui    a1, $8008
800443CC	lui    a0, $8008
800443D0	lw     v0, $b6f4(a1)
800443D4	addiu  v1, zero, $0001
800443D8	sw     v1, $b6f8(a0)
800443DC	srav   v0, v1, v0
800443E0	sw     v0, $b6f4(a1)
800443E4	and    v0, v0, v1
800443E8	beq    v0, zero, L44408 [$80044408]
800443EC	lui    v0, $8008
800443F0	jal    func52da0 [$80052da0]
800443F4	nop
800443F8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800443FC	nop
80044400	j      L44424 [$80044424]
80044404	addu   a0, v0, zero

L44408:	; 80044408
80044408	lw     v1, $b70c(v0)
8004440C	nop
80044410	lw     v0, $0000(v1)
80044414	nop
80044418	lbu    a0, $0000(v0)
8004441C	addiu  v0, v0, $0001
80044420	sw     v0, $0000(v1)

L44424:	; 80044424
80044424	addu   s3, a0, zero
80044428	lui    a1, $8008
8004442C	lui    a0, $8008
80044430	lw     v0, $b6f4(a1)
80044434	addiu  v1, zero, $0001
80044438	sw     v1, $b6f8(a0)
8004443C	srav   v0, v1, v0
80044440	sw     v0, $b6f4(a1)
80044444	slti   v0, s2, $0100
80044448	beq    v0, zero, L44460 [$80044460]
8004444C	addu   a0, s2, zero
80044450	jal    func27e5c [$80027e5c]
80044454	addu   a1, s3, zero
80044458	j      L475b4 [$800475b4]
8004445C	addu   v0, zero, zero

L44460:	; 80044460
80044460	slti   v0, s2, $0200
80044464	beq    v0, zero, L475b4 [$800475b4]
80044468	addu   v0, zero, zero
8004446C	jal    func280cc [$800280cc]
80044470	addiu  a0, s2, $ff00 (=-$100)
80044474	j      L475b4 [$800475b4]
80044478	addu   v0, zero, zero

80044544	lui    v0, $8008
80044548	lw     v0, $b6f4(v0)
8004454C	nop
80044550	andi   v0, v0, $0001
80044554	beq    v0, zero, L44574 [$80044574]
80044558	lui    v0, $8008
8004455C	jal    func52da0 [$80052da0]
80044560	nop
80044564	jal    system_read_from_stack_command_not_from_script [$80052d40]
80044568	nop
8004456C	j      L445b8 [$800445b8]
80044570	addu   a3, v0, zero

L44574:	; 80044574
80044574	lw     a1, $b70c(v0)
80044578	nop
8004457C	lw     v0, $0000(a1)
80044580	nop
80044584	lbu    a3, $0000(v0)
80044588	addiu  v0, v0, $0001
8004458C	sw     v0, $0000(a1)
80044590	lbu    a0, $0000(v0)
80044594	addiu  v1, v0, $0001
80044598	sw     v1, $0000(a1)
8004459C	lbu    v1, $0001(v0)
800445A0	addiu  v0, v0, $0002
800445A4	sw     v0, $0000(a1)
800445A8	sll    a0, a0, $08
800445AC	or     a3, a3, a0
800445B0	sll    v1, v1, $10
800445B4	or     a3, a3, v1

L445b8:	; 800445B8
800445B8	lui    a1, $0098
800445BC	ori    a1, a1, $967f
800445C0	lui    v1, $8008
800445C4	addiu  v0, zero, $0001
800445C8	sw     v0, $b6f8(v1)
800445CC	lui    v0, $8006
800445D0	lw     t0, $794c(v0)
800445D4	lui    a0, $8008
800445D8	lw     a2, $001c(t0)
800445DC	lw     v0, $b6f4(a0)
800445E0	lw     v1, $0560(a2)
800445E4	sra    v0, v0, $01
800445E8	sw     v0, $b6f4(a0)
800445EC	subu   v1, v1, a3
800445F0	sltu   a1, a1, v1
800445F4	beq    a1, zero, L39ea8 [$80039ea8]
800445F8	sw     v1, $0560(a2)
800445FC	lw     v0, $001c(t0)
80044600	j      L39ea8 [$80039ea8]
80044604	sw     zero, $0560(v0)

80044B98	lui    v0, $8008
80044B9C	lw     v0, $b6f4(v0)
80044BA0	nop
80044BA4	andi   v0, v0, $0001
80044BA8	beq    v0, zero, L44bc8 [$80044bc8]
80044BAC	lui    v0, $8008
80044BB0	jal    func52da0 [$80052da0]
80044BB4	addu   s2, zero, zero
80044BB8	jal    system_read_from_stack_command_not_from_script [$80052d40]
80044BBC	addiu  s0, zero, $0008
80044BC0	j      L44bec [$80044bec]
80044BC4	addu   a0, v0, zero

L44bc8:	; 80044BC8
80044BC8	lw     v1, $b70c(v0)
80044BCC	nop
80044BD0	lw     v0, $0000(v1)
80044BD4	nop
80044BD8	lbu    a0, $0000(v0)
80044BDC	addiu  v0, v0, $0001
80044BE0	sw     v0, $0000(v1)
80044BE4	addu   s2, zero, zero
80044BE8	addiu  s0, zero, $0008

L44bec:	; 80044BEC
80044BEC	lui    v1, $8008
80044BF0	addiu  v0, zero, $0001
80044BF4	sw     v0, $b6f8(v1)
80044BF8	lui    v0, $8008
80044BFC	sw     a0, $ae70(v0)
80044C00	lui    a0, $8008
80044C04	lui    v0, $8006
80044C08	lw     v1, $794c(v0)
80044C0C	lw     v0, $b6f4(a0)
80044C10	lw     v1, $001c(v1)
80044C14	sra    v0, v0, $01
80044C18	sw     v0, $b6f4(a0)
80044C1C	addiu  v1, v1, $0480

loop44c20:	; 80044C20
80044C20	sll    s2, s2, $01
80044C24	lw     v0, $0070(v1)
80044C28	addiu  v1, v1, $ff70 (=-$90)
80044C2C	addiu  s0, s0, $ffff (=-$1)
80044C30	srl    v0, v0, $0b
80044C34	andi   v0, v0, $0001
80044C38	bgez   s0, loop44c20 [$80044c20]
80044C3C	or     s2, s2, v0
80044C40	lui    v0, $8008
80044C44	lw     v0, $b6f4(v0)
80044C48	nop
80044C4C	andi   v0, v0, $0001
80044C50	beq    v0, zero, L44c70 [$80044c70]
80044C54	lui    v0, $8008
80044C58	jal    func52da0 [$80052da0]
80044C5C	nop
80044C60	jal    system_read_from_stack_command_not_from_script [$80052d40]
80044C64	nop
80044C68	j      L44ca8 [$80044ca8]
80044C6C	addu   a1, v0, zero

L44c70:	; 80044C70
80044C70	lw     a0, $b70c(v0)
80044C74	nop
80044C78	lw     v0, $0000(a0)
80044C7C	nop
80044C80	lbu    a1, $0000(v0)
80044C84	addiu  v0, v0, $0001
80044C88	sw     v0, $0000(a0)
80044C8C	lbu    v1, $0000(v0)
80044C90	addiu  v0, v0, $0001
80044C94	sw     v0, $0000(a0)
80044C98	sll    v1, v1, $08
80044C9C	or     a1, a1, v1
80044CA0	sll    v0, a1, $10
80044CA4	sra    a1, v0, $10

L44ca8:	; 80044CA8
80044CA8	addu   s3, a1, zero
80044CAC	addu   s0, zero, zero
80044CB0	lui    v0, $8008
80044CB4	addiu  a2, v0, $ae70 (=-$5190)
80044CB8	lui    a1, $8008
80044CBC	lui    a0, $8008
80044CC0	lw     v0, $b6f4(a1)
80044CC4	addiu  v1, zero, $0001
80044CC8	sw     v1, $b6f8(a0)
80044CCC	srav   v0, v1, v0
80044CD0	sw     v0, $b6f4(a1)

loop44cd4:	; 80044CD4
80044CD4	addu   v0, s0, a2
80044CD8	andi   v1, s3, $0001
80044CDC	sb     v1, $0010(v0)
80044CE0	addiu  s0, s0, $0001
80044CE4	slti   v0, s0, $0009
80044CE8	bne    v0, zero, loop44cd4 [$80044cd4]
80044CEC	sra    s3, s3, $01
80044CF0	addu   s0, zero, zero
80044CF4	lui    a3, $8006
80044CF8	addiu  a2, zero, $0001
80044CFC	addiu  a1, zero, $00ff
80044D00	lui    v0, $8008
80044D04	addiu  a0, v0, $ae70 (=-$5190)

loop44d08:	; 80044D08
80044D08	lw     v0, $794c(a3)
80044D0C	nop
80044D10	lw     v0, $001c(v0)
80044D14	sll    v1, s0, $02
80044D18	addu   v0, v0, v1
80044D1C	lw     v0, $054c(v0)
80044D20	nop
80044D24	beq    v0, zero, L44d4c [$80044d4c]
80044D28	nop
80044D2C	lw     v0, $0034(v0)
80044D30	nop
80044D34	andi   s3, v0, $000f
80044D38	sllv   v0, s3, a2
80044D3C	nor    v0, zero, v0
80044D40	and    s2, s2, v0
80044D44	j      L44d50 [$80044d50]
80044D48	sb     s3, $0004(a0)

L44d4c:	; 80044D4C
80044D4C	sb     a1, $0004(a0)

L44d50:	; 80044D50
80044D50	addiu  s0, s0, $0001
80044D54	slti   v0, s0, $0004
80044D58	bne    v0, zero, loop44d08 [$80044d08]
80044D5C	addiu  a0, a0, $0001
80044D60	addu   s3, zero, zero
80044D64	addu   s0, s3, zero
80044D68	lui    v0, $8008
80044D6C	addiu  v1, v0, $ae70 (=-$5190)

loop44d70:	; 80044D70
80044D70	beq    s2, zero, L44da4 [$80044da4]
80044D74	andi   v0, s2, $0001
80044D78	beq    v0, zero, L44d88 [$80044d88]
80044D7C	addu   v0, s3, v1
80044D80	sb     s0, $0008(v0)
80044D84	addiu  s3, s3, $0001

L44d88:	; 80044D88
80044D88	addiu  s0, s0, $0001
80044D8C	slti   v0, s0, $0009
80044D90	beq    v0, zero, L44da4 [$80044da4]
80044D94	sra    s2, s2, $01
80044D98	slti   v0, s3, $0008
80044D9C	bne    v0, zero, loop44d70 [$80044d70]
80044DA0	nop

L44da4:	; 80044DA4
80044DA4	slti   v0, s3, $0008
80044DA8	beq    v0, zero, L44dd0 [$80044dd0]
80044DAC	lui    v0, $8008
80044DB0	addiu  a0, v0, $ae70 (=-$5190)
80044DB4	addiu  v1, zero, $00ff
80044DB8	addu   v0, s3, a0

loop44dbc:	; 80044DBC
80044DBC	sb     v1, $0008(v0)
80044DC0	addiu  s3, s3, $0001
80044DC4	slti   v0, s3, $0008
80044DC8	bne    v0, zero, loop44dbc [$80044dbc]
80044DCC	addu   v0, s3, a0

L44dd0:	; 80044DD0
80044DD0	addiu  a0, zero, $0003
80044DD4	lui    a1, $8008
80044DD8	jal    func32120 [$80032120]
80044DDC	addiu  a1, a1, $ae70 (=-$5190)
80044DE0	j      L475b4 [$800475b4]
80044DE4	addiu  v0, zero, $0001
80044DE8	addu   s1, zero, zero
80044DEC	addu   s0, s1, zero
80044DF0	lui    v0, $8007
80044DF4	addiu  s4, v0, $e63c (=-$19c4)
80044DF8	lui    v0, $8008
80044DFC	addiu  s3, zero, $0001
80044E00	lw     v1, $aecc(v0)
80044E04	addiu  v0, zero, $ffff (=-$1)
80044E08	addiu  s2, v1, $16e4
80044E0C	sw     v0, $16e4(v1)

loop44e10:	; 80044E10
80044E10	jal    func4e7a4 [$8004e7a4]
80044E14	addu   a0, s0, zero
80044E18	bltz   v0, L44e30 [$80044e30]
80044E1C	addu   v0, v0, s4
80044E20	lbu    v0, $0000(v0)
80044E24	nop
80044E28	sllv   v0, v0, s3
80044E2C	or     s1, s1, v0

L44e30:	; 80044E30
80044E30	addiu  s0, s0, $0001
80044E34	slti   v0, s0, $0004
80044E38	bne    v0, zero, loop44e10 [$80044e10]
80044E3C	nop
80044E40	beq    s1, zero, L39ea8 [$80039ea8]
80044E44	addu   s0, zero, zero
80044E48	lui    a1, $8008
80044E4C	lui    v0, $8007
80044E50	addiu  a0, v0, $e630 (=-$19d0)

loop44e54:	; 80044E54
80044E54	andi   v0, s1, $0001
80044E58	beq    v0, zero, L44e78 [$80044e78]
80044E5C	addu   v0, s0, a0
80044E60	lbu    v1, $adfc(a1)
80044E64	lbu    v0, $0000(v0)
80044E68	addiu  v1, v1, $fff7 (=-$9)
80044E6C	addu   v0, v0, v1
80044E70	sb     v0, $0000(s2)
80044E74	addiu  s2, s2, $0001

L44e78:	; 80044E78
80044E78	sra    s1, s1, $01
80044E7C	bne    s1, zero, loop44e54 [$80044e54]
80044E80	addiu  s0, s0, $0001
80044E84	j      L475b4 [$800475b4]
80044E88	addu   v0, zero, zero

80045104	lui    v0, $8008
80045108	lw     v0, $b6f4(v0)
8004510C	nop
80045110	andi   v0, v0, $0001
80045114	beq    v0, zero, L45134 [$80045134]
80045118	lui    v0, $8008
8004511C	jal    func52da0 [$80052da0]
80045120	nop
80045124	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045128	nop
8004512C	j      L45150 [$80045150]
80045130	addu   a0, v0, zero

L45134:	; 80045134
80045134	lw     v1, $b70c(v0)
80045138	nop
8004513C	lw     v0, $0000(v1)
80045140	nop
80045144	lbu    a0, $0000(v0)
80045148	addiu  v0, v0, $0001
8004514C	sw     v0, $0000(v1)

L45150:	; 80045150
80045150	addu   a3, a0, zero
80045154	lui    a1, $8008
80045158	lui    v1, $8008
8004515C	lw     a0, $b6f4(a1)
80045160	addiu  v0, zero, $0001
80045164	sw     v0, $b6f8(v1)
80045168	srav   a0, v0, a0
8004516C	slti   v0, a3, $0009
80045170	bne    v0, zero, L4517c [$8004517c]
80045174	sw     a0, $b6f4(a1)
80045178	addiu  a3, a3, $fffc (=-$4)

L4517c:	; 8004517C
8004517C	andi   v0, a0, $0001
80045180	beq    v0, zero, L451a0 [$800451a0]
80045184	addu   s2, a3, zero
80045188	jal    func52da0 [$80052da0]
8004518C	nop
80045190	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045194	nop
80045198	j      L451c0 [$800451c0]
8004519C	addu   a1, v0, zero

L451a0:	; 800451A0
800451A0	lui    v0, $8008
800451A4	lw     v1, $b70c(v0)
800451A8	nop
800451AC	lw     v0, $0000(v1)
800451B0	nop
800451B4	lbu    a1, $0000(v0)
800451B8	addiu  v0, v0, $0001
800451BC	sw     v0, $0000(v1)

L451c0:	; 800451C0
800451C0	addu   a0, s2, zero
800451C4	lui    a3, $8008
800451C8	lui    a2, $8008
800451CC	lw     v0, $b6f4(a3)
800451D0	addiu  v1, zero, $0001
800451D4	sw     v1, $b6f8(a2)
800451D8	srav   v0, v1, v0
800451DC	jal    func3470c [$8003470c]
800451E0	sw     v0, $b6f4(a3)
800451E4	j      L475b4 [$800475b4]
800451E8	addu   v0, zero, zero
800451EC	lui    v0, $8008
800451F0	lw     v0, $b6f4(v0)
800451F4	nop
800451F8	andi   v0, v0, $0001
800451FC	beq    v0, zero, L4521c [$8004521c]
80045200	lui    v0, $8008
80045204	jal    func52da0 [$80052da0]
80045208	nop
8004520C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045210	nop
80045214	j      L45238 [$80045238]
80045218	addu   a0, v0, zero

L4521c:	; 8004521C
8004521C	lw     v1, $b70c(v0)
80045220	nop
80045224	lw     v0, $0000(v1)
80045228	nop
8004522C	lbu    a0, $0000(v0)
80045230	addiu  v0, v0, $0001
80045234	sw     v0, $0000(v1)

L45238:	; 80045238
80045238	addu   a3, a0, zero
8004523C	lui    a1, $8008
80045240	lui    v1, $8008
80045244	lw     a0, $b6f4(a1)
80045248	addiu  v0, zero, $0001
8004524C	sw     v0, $b6f8(v1)
80045250	srav   a0, v0, a0
80045254	slti   v0, a3, $0009
80045258	bne    v0, zero, L45264 [$80045264]
8004525C	sw     a0, $b6f4(a1)
80045260	addiu  a3, a3, $fffc (=-$4)

L45264:	; 80045264
80045264	andi   v0, a0, $0001
80045268	beq    v0, zero, L45288 [$80045288]
8004526C	addu   s2, a3, zero
80045270	jal    func52da0 [$80052da0]
80045274	nop
80045278	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004527C	nop
80045280	j      L452a8 [$800452a8]
80045284	addu   a1, v0, zero

L45288:	; 80045288
80045288	lui    v0, $8008
8004528C	lw     v1, $b70c(v0)
80045290	nop
80045294	lw     v0, $0000(v1)
80045298	nop
8004529C	lbu    a1, $0000(v0)
800452A0	addiu  v0, v0, $0001
800452A4	sw     v0, $0000(v1)

L452a8:	; 800452A8
800452A8	addu   a0, s2, zero
800452AC	lui    a3, $8008
800452B0	lui    a2, $8008
800452B4	lw     v0, $b6f4(a3)
800452B8	addiu  v1, zero, $0001
800452BC	sw     v1, $b6f8(a2)
800452C0	srav   v0, v1, v0
800452C4	jal    func34220 [$80034220]
800452C8	sw     v0, $b6f4(a3)
800452CC	j      L475b4 [$800475b4]
800452D0	addu   v0, zero, zero

800454F8	lui    v0, $8006
800454FC	lw     v0, $794c(v0)
80045500	nop
80045504	lw     a0, $001c(v0)
80045508	nop
8004550C	lh     v0, $0568(a0)
80045510	lhu    v1, $0568(a0)
80045514	slti   v0, v0, $7fff
80045518	beq    v0, zero, L39ea8 [$80039ea8]
8004551C	addiu  v0, v1, $0001
80045520	j      L39ea8 [$80039ea8]
80045524	sh     v0, $0568(a0)
80045528	lui    v0, $8008
8004552C	lw     v0, $b6f4(v0)
80045530	nop
80045534	andi   v0, v0, $0001
80045538	beq    v0, zero, L45558 [$80045558]
8004553C	lui    v0, $8008
80045540	jal    func52da0 [$80052da0]
80045544	nop
80045548	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004554C	nop
80045550	j      L45590 [$80045590]
80045554	addu   a1, v0, zero

L45558:	; 80045558
80045558	lw     a0, $b70c(v0)
8004555C	nop
80045560	lw     v0, $0000(a0)
80045564	nop
80045568	lbu    a1, $0000(v0)
8004556C	addiu  v0, v0, $0001
80045570	sw     v0, $0000(a0)
80045574	lbu    v1, $0000(v0)
80045578	addiu  v0, v0, $0001
8004557C	sw     v0, $0000(a0)
80045580	sll    v1, v1, $08
80045584	or     a1, a1, v1
80045588	sll    v0, a1, $10
8004558C	sra    a1, v0, $10

L45590:	; 80045590
80045590	addu   a0, a1, zero
80045594	lui    a2, $8008
80045598	lui    a1, $8008
8004559C	lw     v0, $b6f4(a2)
800455A0	addiu  v1, zero, $0001
800455A4	sw     v1, $b6f8(a1)
800455A8	srav   v0, v1, v0
800455AC	jal    func4f058 [$8004f058]
800455B0	sw     v0, $b6f4(a2)
800455B4	addu   v1, v0, zero
800455B8	lui    v0, $8008
800455BC	addiu  a0, v0, $ae90 (=-$5170)
800455C0	addiu  a1, a0, $000f
800455C4	sltu   v0, a0, a1
800455C8	beq    v0, zero, L455f0 [$800455f0]
800455CC	addu   v0, zero, zero

loop455d0:	; 800455D0
800455D0	lbu    v0, $0000(v1)
800455D4	nop
800455D8	sb     v0, $0000(a0)
800455DC	addiu  a0, a0, $0001
800455E0	sltu   v0, a0, a1
800455E4	bne    v0, zero, loop455d0 [$800455d0]
800455E8	addiu  v1, v1, $0001
800455EC	addu   v0, zero, zero

L455f0:	; 800455F0
800455F0	addiu  v1, zero, $00ff
800455F4	sb     v1, $0000(a0)
800455F8	lui    v1, $8006
800455FC	lw     a0, $794c(v1)
80045600	lui    v1, $8008
80045604	lw     a0, $001c(a0)
80045608	addiu  v1, v1, $ae90 (=-$5170)
8004560C	j      L475b4 [$800475b4]
80045610	sw     v1, $080c(a0)
80045614	lui    v0, $8006
80045618	lui    v1, $8008
8004561C	lw     v0, $794c(v0)
80045620	lw     v1, $ae8c(v1)
80045624	lw     a0, $001c(v0)
80045628	addu   v0, zero, zero
8004562C	j      L475b4 [$800475b4]
80045630	sw     v1, $080c(a0)
80045634	lui    v0, $8008
80045638	lw     v0, $b6f4(v0)
8004563C	nop
80045640	andi   v0, v0, $0001
80045644	beq    v0, zero, L45664 [$80045664]
80045648	lui    v0, $8008
8004564C	jal    func52da0 [$80052da0]
80045650	nop
80045654	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045658	nop
8004565C	j      L4569c [$8004569c]
80045660	addu   a1, v0, zero

L45664:	; 80045664
80045664	lw     a0, $b70c(v0)
80045668	nop
8004566C	lw     v0, $0000(a0)
80045670	nop
80045674	lbu    a1, $0000(v0)
80045678	addiu  v0, v0, $0001
8004567C	sw     v0, $0000(a0)
80045680	lbu    v1, $0000(v0)
80045684	addiu  v0, v0, $0001
80045688	sw     v0, $0000(a0)
8004568C	sll    v1, v1, $08
80045690	or     a1, a1, v1
80045694	sll    v0, a1, $10
80045698	sra    a1, v0, $10

L4569c:	; 8004569C
8004569C	addu   a0, a1, zero
800456A0	lui    a2, $8008
800456A4	lui    a1, $8008
800456A8	lw     v0, $b6f4(a2)
800456AC	addiu  v1, zero, $0001
800456B0	sw     v1, $b6f8(a1)
800456B4	srav   v0, v1, v0
800456B8	jal    func2412c [$8002412c]
800456BC	sw     v0, $b6f4(a2)
800456C0	j      L475b4 [$800475b4]
800456C4	addu   v0, zero, zero
800456C8	lui    v0, $8008
800456CC	lw     v0, $b6f4(v0)
800456D0	nop
800456D4	andi   v0, v0, $0001
800456D8	beq    v0, zero, L456f8 [$800456f8]
800456DC	lui    v0, $8008
800456E0	jal    func52da0 [$80052da0]
800456E4	nop
800456E8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800456EC	nop
800456F0	j      L45714 [$80045714]
800456F4	addu   a0, v0, zero

L456f8:	; 800456F8
800456F8	lw     v1, $b70c(v0)
800456FC	nop
80045700	lw     v0, $0000(v1)
80045704	nop
80045708	lbu    a0, $0000(v0)
8004570C	addiu  v0, v0, $0001
80045710	sw     v0, $0000(v1)

L45714:	; 80045714
80045714	andi   a0, a0, $00ff
80045718	lui    a2, $8008
8004571C	lui    a1, $8008
80045720	lw     v0, $b6f4(a2)
80045724	addiu  v1, zero, $0001
80045728	sw     v1, $b6f8(a1)
8004572C	srav   v0, v1, v0
80045730	jal    func240b0 [$800240b0]
80045734	sw     v0, $b6f4(a2)
80045738	j      L475b4 [$800475b4]
8004573C	addu   v0, zero, zero
80045740	lui    v0, $8008
80045744	lw     v0, $b6f4(v0)
80045748	nop
8004574C	andi   v0, v0, $0001
80045750	beq    v0, zero, L45770 [$80045770]
80045754	lui    v0, $8008
80045758	jal    func52da0 [$80052da0]
8004575C	nop
80045760	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045764	nop
80045768	j      L4578c [$8004578c]
8004576C	addu   a0, v0, zero

L45770:	; 80045770
80045770	lw     v1, $b70c(v0)
80045774	nop
80045778	lw     v0, $0000(v1)
8004577C	nop
80045780	lbu    a0, $0000(v0)
80045784	addiu  v0, v0, $0001
80045788	sw     v0, $0000(v1)

L4578c:	; 8004578C
8004578C	andi   a0, a0, $00ff
80045790	lui    a2, $8008
80045794	lui    a1, $8008
80045798	lw     v0, $b6f4(a2)
8004579C	addiu  v1, zero, $0001
800457A0	sw     v1, $b6f8(a1)
800457A4	srav   v0, v1, v0
800457A8	jal    func240f8 [$800240f8]
800457AC	sw     v0, $b6f4(a2)
800457B0	j      L475b4 [$800475b4]
800457B4	addu   v0, zero, zero

80045AB4	lui    v0, $8008
80045AB8	lw     v0, $b6f4(v0)
80045ABC	nop
80045AC0	andi   v0, v0, $0001
80045AC4	beq    v0, zero, L45ae4 [$80045ae4]
80045AC8	lui    v0, $8008
80045ACC	jal    func52da0 [$80052da0]
80045AD0	nop
80045AD4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045AD8	nop
80045ADC	j      L45b00 [$80045b00]
80045AE0	addu   a0, v0, zero

L45ae4:	; 80045AE4
80045AE4	lw     v1, $b70c(v0)
80045AE8	nop
80045AEC	lw     v0, $0000(v1)
80045AF0	nop
80045AF4	lbu    a0, $0000(v0)
80045AF8	addiu  v0, v0, $0001
80045AFC	sw     v0, $0000(v1)

L45b00:	; 80045B00
80045B00	addu   s2, a0, zero
80045B04	lui    a1, $8008
80045B08	lui    a0, $8008
80045B0C	lw     v0, $b6f4(a1)
80045B10	addiu  v1, zero, $0001
80045B14	sw     v1, $b6f8(a0)
80045B18	srav   v0, v1, v0
80045B1C	sw     v0, $b6f4(a1)
80045B20	and    v0, v0, v1
80045B24	beq    v0, zero, L45b44 [$80045b44]
80045B28	lui    v0, $8008
80045B2C	jal    func52da0 [$80052da0]
80045B30	nop
80045B34	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045B38	nop
80045B3C	j      L45b7c [$80045b7c]
80045B40	addu   a1, v0, zero

L45b44:	; 80045B44
80045B44	lw     a0, $b70c(v0)
80045B48	nop
80045B4C	lw     v0, $0000(a0)
80045B50	nop
80045B54	lbu    a1, $0000(v0)
80045B58	addiu  v0, v0, $0001
80045B5C	sw     v0, $0000(a0)
80045B60	lbu    v1, $0000(v0)
80045B64	addiu  v0, v0, $0001
80045B68	sw     v0, $0000(a0)
80045B6C	sll    v1, v1, $08
80045B70	or     a1, a1, v1
80045B74	sll    v0, a1, $10
80045B78	sra    a1, v0, $10

L45b7c:	; 80045B7C
80045B7C	addu   s3, a1, zero
80045B80	lui    a1, $8008
80045B84	lui    a0, $8008
80045B88	lw     v0, $b6f4(a1)
80045B8C	addiu  v1, zero, $0001
80045B90	sw     v1, $b6f8(a0)
80045B94	srav   v0, v1, v0
80045B98	sw     v0, $b6f4(a1)
80045B9C	and    v0, v0, v1
80045BA0	beq    v0, zero, L45bc0 [$80045bc0]
80045BA4	lui    v0, $8008
80045BA8	jal    func52da0 [$80052da0]
80045BAC	nop
80045BB0	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045BB4	nop
80045BB8	j      L45bdc [$80045bdc]
80045BBC	addu   a2, v0, zero

L45bc0:	; 80045BC0
80045BC0	lw     v1, $b70c(v0)
80045BC4	nop
80045BC8	lw     v0, $0000(v1)
80045BCC	nop
80045BD0	lbu    a2, $0000(v0)
80045BD4	addiu  v0, v0, $0001
80045BD8	sw     v0, $0000(v1)

L45bdc:	; 80045BDC
80045BDC	addu   a0, s2, zero
80045BE0	addu   a1, s3, zero
80045BE4	lui    t0, $8008
80045BE8	lui    a3, $8008
80045BEC	lw     v0, $b6f4(t0)
80045BF0	addiu  v1, zero, $0001
80045BF4	sw     v1, $b6f8(a3)
80045BF8	srav   v0, v1, v0
80045BFC	jal    funcad944 [$800ad944]
80045C00	sw     v0, $b6f4(t0)
80045C04	j      L475b4 [$800475b4]
80045C08	addu   v0, zero, zero
80045C0C	lui    v0, $8008
80045C10	lw     v1, $b708(v0)
80045C14	addiu  v0, zero, $0003
80045C18	bne    v1, v0, L475b4 [$800475b4]
80045C1C	addu   v0, zero, zero
80045C20	jal    funcae750 [$800ae750]
80045C24	nop
80045C28	lw     v1, $0000(v0)
80045C2C	nop
80045C30	sw     v1, $0014(s0)
80045C34	lw     v1, $0004(v0)
80045C38	nop
80045C3C	sw     v1, $0018(s0)
80045C40	lhu    v1, $0050(s0)
80045C44	lw     v0, $0008(v0)
80045C48	ori    v1, v1, $0040
80045C4C	sh     v1, $0050(s0)
80045C50	j      L39ea8 [$80039ea8]
80045C54	sw     v0, $001c(s0)
80045C58	lui    v0, $8008
80045C5C	lw     v1, $b708(v0)
80045C60	addiu  v0, zero, $0003
80045C64	bne    v1, v0, L475b4 [$800475b4]
80045C68	addu   v0, zero, zero
80045C6C	jal    funcae744 [$800ae744]
80045C70	nop
80045C74	lw     v1, $0000(v0)
80045C78	nop
80045C7C	sw     v1, $0014(s0)
80045C80	lw     v1, $0004(v0)
80045C84	nop
80045C88	sw     v1, $0018(s0)
80045C8C	lhu    v1, $0050(s0)
80045C90	lw     v0, $0008(v0)
80045C94	ori    v1, v1, $0080
80045C98	sh     v1, $0050(s0)
80045C9C	j      L39ea8 [$80039ea8]
80045CA0	sw     v0, $001c(s0)
80045CA4	lui    v0, $8008
80045CA8	lw     v0, $b6f4(v0)
80045CAC	nop
80045CB0	andi   v0, v0, $0001
80045CB4	beq    v0, zero, L45cd4 [$80045cd4]
80045CB8	lui    v0, $8008
80045CBC	jal    func52da0 [$80052da0]
80045CC0	nop
80045CC4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045CC8	nop
80045CCC	j      L45cf0 [$80045cf0]
80045CD0	addu   a0, v0, zero

L45cd4:	; 80045CD4
80045CD4	lw     v1, $b70c(v0)
80045CD8	nop
80045CDC	lw     v0, $0000(v1)
80045CE0	nop
80045CE4	lbu    a0, $0000(v0)
80045CE8	addiu  v0, v0, $0001
80045CEC	sw     v0, $0000(v1)

L45cf0:	; 80045CF0
80045CF0	addu   s2, a0, zero
80045CF4	lui    a1, $8008
80045CF8	lui    a0, $8008
80045CFC	lw     v0, $b6f4(a1)
80045D00	addiu  v1, zero, $0001
80045D04	sw     v1, $b6f8(a0)
80045D08	srav   v0, v1, v0
80045D0C	sw     v0, $b6f4(a1)
80045D10	and    v0, v0, v1
80045D14	beq    v0, zero, L45d34 [$80045d34]
80045D18	lui    v0, $8008
80045D1C	jal    func52da0 [$80052da0]
80045D20	nop
80045D24	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045D28	nop
80045D2C	j      L45d6c [$80045d6c]
80045D30	addu   a1, v0, zero

L45d34:	; 80045D34
80045D34	lw     a0, $b70c(v0)
80045D38	nop
80045D3C	lw     v0, $0000(a0)
80045D40	nop
80045D44	lbu    a1, $0000(v0)
80045D48	addiu  v0, v0, $0001
80045D4C	sw     v0, $0000(a0)
80045D50	lbu    v1, $0000(v0)
80045D54	addiu  v0, v0, $0001
80045D58	sw     v0, $0000(a0)
80045D5C	sll    v1, v1, $08
80045D60	or     a1, a1, v1
80045D64	sll    v0, a1, $10
80045D68	sra    a1, v0, $10

L45d6c:	; 80045D6C
80045D6C	addu   a0, s2, zero
80045D70	lui    a3, $8008
80045D74	lui    a2, $8008
80045D78	lw     v0, $b6f4(a3)
80045D7C	addiu  v1, zero, $0001
80045D80	sw     v1, $b6f8(a2)
80045D84	srav   v0, v1, v0
80045D88	jal    funcb73f8 [$800b73f8]
80045D8C	sw     v0, $b6f4(a3)
80045D90	j      L475b4 [$800475b4]
80045D94	addu   v0, zero, zero
80045D98	jal    func50a84 [$80050a84]
80045D9C	nop
80045DA0	j      L475b4 [$800475b4]
80045DA4	addu   v0, zero, zero
80045DA8	lui    v0, $8008
80045DAC	lw     v0, $b6f4(v0)
80045DB0	nop
80045DB4	andi   v0, v0, $0001
80045DB8	beq    v0, zero, L45dd8 [$80045dd8]
80045DBC	lui    v0, $8008
80045DC0	jal    func52da0 [$80052da0]
80045DC4	nop
80045DC8	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045DCC	nop
80045DD0	j      L45df4 [$80045df4]
80045DD4	addu   a0, v0, zero

L45dd8:	; 80045DD8
80045DD8	lw     v1, $b70c(v0)
80045DDC	nop
80045DE0	lw     v0, $0000(v1)
80045DE4	nop
80045DE8	lbu    a0, $0000(v0)
80045DEC	addiu  v0, v0, $0001
80045DF0	sw     v0, $0000(v1)

L45df4:	; 80045DF4
80045DF4	lui    a2, $8008
80045DF8	lui    a1, $8008
80045DFC	lw     v0, $b6f4(a2)
80045E00	addiu  v1, zero, $0001
80045E04	sw     v1, $b6f8(a1)
80045E08	srav   v0, v1, v0
80045E0C	jal    func54fb8 [$80054fb8]
80045E10	sw     v0, $b6f4(a2)
80045E14	j      L475b4 [$800475b4]
80045E18	addu   v0, zero, zero

80045FCC	lui    v0, $8008
80045FD0	lw     v0, $b6f4(v0)
80045FD4	nop
80045FD8	andi   v0, v0, $0001
80045FDC	beq    v0, zero, L45ffc [$80045ffc]
80045FE0	lui    v0, $8008
80045FE4	jal    func52da0 [$80052da0]
80045FE8	nop
80045FEC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80045FF0	nop
80045FF4	j      L46018 [$80046018]
80045FF8	addu   a0, v0, zero

L45ffc:	; 80045FFC
80045FFC	lw     v1, $b70c(v0)
80046000	nop
80046004	lw     v0, $0000(v1)
80046008	nop
8004600C	lbu    a0, $0000(v0)
80046010	addiu  v0, v0, $0001
80046014	sw     v0, $0000(v1)

L46018:	; 80046018
80046018	addu   s2, a0, zero
8004601C	lui    a1, $8008
80046020	lui    a0, $8008
80046024	lw     v0, $b6f4(a1)
80046028	addiu  v1, zero, $0001
8004602C	sw     v1, $b6f8(a0)
80046030	srav   v0, v1, v0
80046034	sw     v0, $b6f4(a1)
80046038	and    v0, v0, v1
8004603C	beq    v0, zero, L4605c [$8004605c]
80046040	lui    v0, $8008
80046044	jal    func52da0 [$80052da0]
80046048	nop
8004604C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046050	nop
80046054	j      L46078 [$80046078]
80046058	addu   a0, v0, zero

L4605c:	; 8004605C
8004605C	lw     v1, $b70c(v0)
80046060	nop
80046064	lw     v0, $0000(v1)
80046068	nop
8004606C	lbu    a0, $0000(v0)
80046070	addiu  v0, v0, $0001
80046074	sw     v0, $0000(v1)

L46078:	; 80046078
80046078	addu   s3, a0, zero
8004607C	lui    a1, $8008
80046080	lui    a0, $8008
80046084	lw     v0, $b6f4(a1)
80046088	addiu  v1, zero, $0001
8004608C	sw     v1, $b6f8(a0)
80046090	srav   v0, v1, v0
80046094	sw     v0, $b6f4(a1)
80046098	and    v0, v0, v1
8004609C	beq    v0, zero, L460bc [$800460bc]
800460A0	lui    v0, $8008
800460A4	jal    func52da0 [$80052da0]
800460A8	nop
800460AC	jal    system_read_from_stack_command_not_from_script [$80052d40]
800460B0	nop
800460B4	j      L460d8 [$800460d8]
800460B8	addu   a2, v0, zero

L460bc:	; 800460BC
800460BC	lw     v1, $b70c(v0)
800460C0	nop
800460C4	lw     v0, $0000(v1)
800460C8	nop
800460CC	lbu    a2, $0000(v0)
800460D0	addiu  v0, v0, $0001
800460D4	sw     v0, $0000(v1)

L460d8:	; 800460D8
800460D8	addu   a0, s2, zero
800460DC	addu   a1, s3, zero
800460E0	lui    t0, $8008
800460E4	lui    a3, $8008
800460E8	lw     v0, $b6f4(t0)
800460EC	addiu  v1, zero, $0001
800460F0	sw     v1, $b6f8(a3)
800460F4	srav   v0, v1, v0
800460F8	jal    func55060 [$80055060]
800460FC	sw     v0, $b6f4(t0)
80046100	j      L475b4 [$800475b4]
80046104	addu   v0, zero, zero
80046108	lui    v0, $8008
8004610C	lw     v0, $b6f4(v0)
80046110	nop
80046114	andi   v0, v0, $0001
80046118	beq    v0, zero, L46138 [$80046138]
8004611C	lui    v0, $8008
80046120	jal    func52da0 [$80052da0]
80046124	nop
80046128	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004612C	nop
80046130	j      L46170 [$80046170]
80046134	addu   a1, v0, zero

L46138:	; 80046138
80046138	lw     a0, $b70c(v0)
8004613C	nop
80046140	lw     v0, $0000(a0)
80046144	nop
80046148	lbu    a1, $0000(v0)
8004614C	addiu  v0, v0, $0001
80046150	sw     v0, $0000(a0)
80046154	lbu    v1, $0000(v0)
80046158	addiu  v0, v0, $0001
8004615C	sw     v0, $0000(a0)
80046160	sll    v1, v1, $08
80046164	or     a1, a1, v1
80046168	sll    v0, a1, $10
8004616C	sra    a1, v0, $10

L46170:	; 80046170
80046170	sll    a0, a1, $10
80046174	sra    a0, a0, $10
80046178	lui    a2, $8008
8004617C	lui    a1, $8008
80046180	lw     v0, $b6f4(a2)
80046184	addiu  v1, zero, $0001
80046188	sw     v1, $b6f8(a1)
8004618C	srav   v0, v1, v0
80046190	jal    func550c0 [$800550c0]
80046194	sw     v0, $b6f4(a2)
80046198	j      L475b4 [$800475b4]
8004619C	addu   v0, zero, zero
800461A0	lui    v0, $8008
800461A4	lw     v0, $b6f4(v0)
800461A8	nop
800461AC	andi   v0, v0, $0001
800461B0	beq    v0, zero, L461d0 [$800461d0]
800461B4	lui    v0, $8008
800461B8	jal    func52da0 [$80052da0]
800461BC	nop
800461C0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800461C4	nop
800461C8	j      L461ec [$800461ec]
800461CC	addu   a0, v0, zero

L461d0:	; 800461D0
800461D0	lw     v1, $b70c(v0)
800461D4	nop
800461D8	lw     v0, $0000(v1)
800461DC	nop
800461E0	lbu    a0, $0000(v0)
800461E4	addiu  v0, v0, $0001
800461E8	sw     v0, $0000(v1)

L461ec:	; 800461EC
800461EC	lui    a2, $8008
800461F0	lui    a1, $8008
800461F4	lw     v0, $b6f4(a2)
800461F8	addiu  v1, zero, $0001
800461FC	sw     v1, $b6f8(a1)
80046200	srav   v0, v1, v0
80046204	jal    func550d0 [$800550d0]
80046208	sw     v0, $b6f4(a2)
8004620C	j      L475b4 [$800475b4]
80046210	addu   v0, zero, zero
80046214	lui    v0, $8008
80046218	lw     v0, $b6f4(v0)
8004621C	nop
80046220	andi   v0, v0, $0001
80046224	beq    v0, zero, L46244 [$80046244]
80046228	lui    v0, $8008
8004622C	jal    func52da0 [$80052da0]
80046230	nop
80046234	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046238	nop
8004623C	j      L46260 [$80046260]
80046240	addu   a0, v0, zero

L46244:	; 80046244
80046244	lw     v1, $b70c(v0)
80046248	nop
8004624C	lw     v0, $0000(v1)
80046250	nop
80046254	lbu    a0, $0000(v0)
80046258	addiu  v0, v0, $0001
8004625C	sw     v0, $0000(v1)

L46260:	; 80046260
80046260	addu   s2, a0, zero
80046264	lui    a1, $8008
80046268	lui    a0, $8008
8004626C	lw     v0, $b6f4(a1)
80046270	addiu  v1, zero, $0001
80046274	sw     v1, $b6f8(a0)
80046278	srav   v0, v1, v0
8004627C	sw     v0, $b6f4(a1)
80046280	and    v0, v0, v1
80046284	beq    v0, zero, L462a4 [$800462a4]
80046288	lui    v0, $8008
8004628C	jal    func52da0 [$80052da0]
80046290	nop
80046294	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046298	nop
8004629C	j      L462c0 [$800462c0]
800462A0	addu   a1, v0, zero

L462a4:	; 800462A4
800462A4	lw     v1, $b70c(v0)
800462A8	nop
800462AC	lw     v0, $0000(v1)
800462B0	nop
800462B4	lbu    a1, $0000(v0)
800462B8	addiu  v0, v0, $0001
800462BC	sw     v0, $0000(v1)

L462c0:	; 800462C0
800462C0	addu   a0, s2, zero
800462C4	lui    a3, $8008
800462C8	lui    a2, $8008
800462CC	lw     v0, $b6f4(a3)
800462D0	addiu  v1, zero, $0001
800462D4	sw     v1, $b6f8(a2)
800462D8	srav   v0, v1, v0
800462DC	jal    func550f0 [$800550f0]
800462E0	sw     v0, $b6f4(a3)
800462E4	j      L475b4 [$800475b4]
800462E8	addu   v0, zero, zero

800463F4	lui    a2, $ffff
800463F8	ori    a2, a2, $0100
800463FC	lui    a1, $8008
80046400	lui    v0, $8008
80046404	lw     a0, $b70c(v0)
80046408	lw     v1, $b6f4(a1)
8004640C	lw     v0, $0000(a0)
80046410	ori    a3, v1, $ff00
80046414	lbu    v1, $0000(v0)
80046418	addiu  v0, v0, $0001
8004641C	sw     v0, $0000(a0)
80046420	sw     v1, $b6f4(a1)
80046424	addu   v1, a3, a2
80046428	sltiu  v0, v1, $0012
8004642C	beq    v0, zero, L39ea8 [$80039ea8]
80046430	lui    v0, $8001
80046434	addiu  v0, v0, $19fc
80046438	sll    v1, v1, $02
8004643C	addu   v1, v1, v0
80046440	lw     v0, $0000(v1)
80046444	nop
80046448	jr     v0 
8004644C	nop

80046450	lui    v0, $8008
80046454	lw     v0, $b6f4(v0)
80046458	nop
8004645C	andi   v0, v0, $0001
80046460	beq    v0, zero, L46480 [$80046480]
80046464	lui    v0, $8008
80046468	jal    func52da0 [$80052da0]
8004646C	nop
80046470	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046474	nop
80046478	j      L4649c [$8004649c]
8004647C	addu   a0, v0, zero

L46480:	; 80046480
80046480	lw     v1, $b70c(v0)
80046484	nop
80046488	lw     v0, $0000(v1)
8004648C	nop
80046490	lbu    a0, $0000(v0)
80046494	addiu  v0, v0, $0001
80046498	sw     v0, $0000(v1)

L4649c:	; 8004649C
8004649C	addu   s2, a0, zero
800464A0	lui    a1, $8008
800464A4	lui    a0, $8008
800464A8	lw     v0, $b6f4(a1)
800464AC	addiu  v1, zero, $0001
800464B0	sw     v1, $b6f8(a0)
800464B4	srav   v0, v1, v0
800464B8	sw     v0, $b6f4(a1)
800464BC	and    v0, v0, v1
800464C0	beq    v0, zero, L464e0 [$800464e0]
800464C4	lui    v0, $8008
800464C8	jal    func52da0 [$80052da0]
800464CC	nop
800464D0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800464D4	nop
800464D8	j      L464fc [$800464fc]
800464DC	addu   a1, v0, zero

L464e0:	; 800464E0
800464E0	lw     v1, $b70c(v0)
800464E4	nop
800464E8	lw     v0, $0000(v1)
800464EC	nop
800464F0	lbu    a1, $0000(v0)
800464F4	addiu  v0, v0, $0001
800464F8	sw     v0, $0000(v1)

L464fc:	; 800464FC
800464FC	addu   a0, s2, zero
80046500	lui    a3, $8008
80046504	lui    a2, $8008
80046508	lw     v0, $b6f4(a3)
8004650C	addiu  v1, zero, $0001
80046510	sw     v1, $b6f8(a2)
80046514	srav   v0, v1, v0
80046518	jal    funcc7f34 [$800c7f34]
8004651C	sw     v0, $b6f4(a3)
80046520	j      L475b4 [$800475b4]
80046524	addu   v0, zero, zero
80046528	lui    v0, $8008
8004652C	lw     v0, $b6f4(v0)
80046530	nop
80046534	andi   v0, v0, $0001
80046538	beq    v0, zero, L46558 [$80046558]
8004653C	lui    v0, $8008
80046540	jal    func52da0 [$80052da0]
80046544	nop
80046548	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004654C	nop
80046550	j      L46574 [$80046574]
80046554	addu   a0, v0, zero

L46558:	; 80046558
80046558	lw     v1, $b70c(v0)
8004655C	nop
80046560	lw     v0, $0000(v1)
80046564	nop
80046568	lbu    a0, $0000(v0)
8004656C	addiu  v0, v0, $0001
80046570	sw     v0, $0000(v1)

L46574:	; 80046574
80046574	addu   s2, a0, zero
80046578	lui    a1, $8008
8004657C	lui    a0, $8008
80046580	lw     v0, $b6f4(a1)
80046584	addiu  v1, zero, $0001
80046588	sw     v1, $b6f8(a0)
8004658C	srav   v0, v1, v0
80046590	sw     v0, $b6f4(a1)
80046594	and    v0, v0, v1
80046598	beq    v0, zero, L465b8 [$800465b8]
8004659C	lui    v0, $8008
800465A0	jal    func52da0 [$80052da0]
800465A4	nop
800465A8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800465AC	nop
800465B0	j      L465d4 [$800465d4]
800465B4	addu   a1, v0, zero

L465b8:	; 800465B8
800465B8	lw     v1, $b70c(v0)
800465BC	nop
800465C0	lw     v0, $0000(v1)
800465C4	nop
800465C8	lbu    a1, $0000(v0)
800465CC	addiu  v0, v0, $0001
800465D0	sw     v0, $0000(v1)

L465d4:	; 800465D4
800465D4	addu   a0, s2, zero
800465D8	lui    a3, $8008
800465DC	lui    a2, $8008
800465E0	lw     v0, $b6f4(a3)
800465E4	addiu  v1, zero, $0001
800465E8	sw     v1, $b6f8(a2)
800465EC	srav   v0, v1, v0
800465F0	jal    funcc7f7c [$800c7f7c]
800465F4	sw     v0, $b6f4(a3)
800465F8	j      L475b4 [$800475b4]
800465FC	addu   v0, zero, zero
80046600	lui    v0, $8008
80046604	lw     v0, $b6f4(v0)
80046608	nop
8004660C	andi   v0, v0, $0001
80046610	beq    v0, zero, L46630 [$80046630]
80046614	lui    v0, $8008
80046618	jal    func52da0 [$80052da0]
8004661C	nop
80046620	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046624	nop
80046628	j      L4664c [$8004664c]
8004662C	addu   a0, v0, zero

L46630:	; 80046630
80046630	lw     v1, $b70c(v0)
80046634	nop
80046638	lw     v0, $0000(v1)
8004663C	nop
80046640	lbu    a0, $0000(v0)
80046644	addiu  v0, v0, $0001
80046648	sw     v0, $0000(v1)

L4664c:	; 8004664C
8004664C	addu   s2, a0, zero
80046650	lui    a1, $8008
80046654	lui    a0, $8008
80046658	lw     v0, $b6f4(a1)
8004665C	addiu  v1, zero, $0001
80046660	sw     v1, $b6f8(a0)
80046664	srav   v0, v1, v0
80046668	sw     v0, $b6f4(a1)
8004666C	and    v0, v0, v1
80046670	beq    v0, zero, L46690 [$80046690]
80046674	lui    v0, $8008
80046678	jal    func52da0 [$80052da0]
8004667C	nop
80046680	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046684	nop
80046688	j      L466ac [$800466ac]
8004668C	addu   a1, v0, zero

L46690:	; 80046690
80046690	lw     v1, $b70c(v0)
80046694	nop
80046698	lw     v0, $0000(v1)
8004669C	nop
800466A0	lbu    a1, $0000(v0)
800466A4	addiu  v0, v0, $0001
800466A8	sw     v0, $0000(v1)

L466ac:	; 800466AC
800466AC	addu   a0, s2, zero
800466B0	lui    a3, $8008
800466B4	lui    a2, $8008
800466B8	lw     v0, $b6f4(a3)
800466BC	addiu  v1, zero, $0001
800466C0	sw     v1, $b6f8(a2)
800466C4	srav   v0, v1, v0
800466C8	jal    funcc7fbc [$800c7fbc]
800466CC	sw     v0, $b6f4(a3)
800466D0	j      L475b4 [$800475b4]
800466D4	addu   v0, zero, zero
800466D8	lui    v0, $8008
800466DC	lw     v0, $b6f4(v0)
800466E0	nop
800466E4	andi   v0, v0, $0001
800466E8	beq    v0, zero, L46708 [$80046708]
800466EC	lui    v0, $8008
800466F0	jal    func52da0 [$80052da0]
800466F4	nop
800466F8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800466FC	nop
80046700	j      L46724 [$80046724]
80046704	addu   a0, v0, zero

L46708:	; 80046708
80046708	lw     v1, $b70c(v0)
8004670C	nop
80046710	lw     v0, $0000(v1)
80046714	nop
80046718	lbu    a0, $0000(v0)
8004671C	addiu  v0, v0, $0001
80046720	sw     v0, $0000(v1)

L46724:	; 80046724
80046724	addu   s2, a0, zero
80046728	lui    a1, $8008
8004672C	lui    a0, $8008
80046730	lw     v0, $b6f4(a1)
80046734	addiu  v1, zero, $0001
80046738	sw     v1, $b6f8(a0)
8004673C	srav   v0, v1, v0
80046740	sw     v0, $b6f4(a1)
80046744	and    v0, v0, v1
80046748	beq    v0, zero, L46768 [$80046768]
8004674C	lui    v0, $8008
80046750	jal    func52da0 [$80052da0]
80046754	nop
80046758	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004675C	nop
80046760	j      L46784 [$80046784]
80046764	addu   a1, v0, zero

L46768:	; 80046768
80046768	lw     v1, $b70c(v0)
8004676C	nop
80046770	lw     v0, $0000(v1)
80046774	nop
80046778	lbu    a1, $0000(v0)
8004677C	addiu  v0, v0, $0001
80046780	sw     v0, $0000(v1)

L46784:	; 80046784
80046784	addu   a0, s2, zero
80046788	lui    a3, $8008
8004678C	lui    a2, $8008
80046790	lw     v0, $b6f4(a3)
80046794	addiu  v1, zero, $0001
80046798	sw     v1, $b6f8(a2)
8004679C	srav   v0, v1, v0
800467A0	jal    funcc8010 [$800c8010]
800467A4	sw     v0, $b6f4(a3)
800467A8	j      L475b4 [$800475b4]
800467AC	addu   v0, zero, zero
800467B0	lui    v0, $8008
800467B4	lw     v0, $b6f4(v0)
800467B8	nop
800467BC	andi   v0, v0, $0001
800467C0	beq    v0, zero, L467e0 [$800467e0]
800467C4	lui    v0, $8008
800467C8	jal    func52da0 [$80052da0]
800467CC	nop
800467D0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800467D4	nop
800467D8	j      L467fc [$800467fc]
800467DC	addu   a0, v0, zero

L467e0:	; 800467E0
800467E0	lw     v1, $b70c(v0)
800467E4	nop
800467E8	lw     v0, $0000(v1)
800467EC	nop
800467F0	lbu    a0, $0000(v0)
800467F4	addiu  v0, v0, $0001
800467F8	sw     v0, $0000(v1)

L467fc:	; 800467FC
800467FC	addu   s2, a0, zero
80046800	lui    a1, $8008
80046804	lui    a0, $8008
80046808	lw     v0, $b6f4(a1)
8004680C	addiu  v1, zero, $0001
80046810	sw     v1, $b6f8(a0)
80046814	srav   v0, v1, v0
80046818	sw     v0, $b6f4(a1)
8004681C	and    v0, v0, v1
80046820	beq    v0, zero, L46840 [$80046840]
80046824	lui    v0, $8008
80046828	jal    func52da0 [$80052da0]
8004682C	nop
80046830	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046834	nop
80046838	j      L4685c [$8004685c]
8004683C	addu   a1, v0, zero

L46840:	; 80046840
80046840	lw     v1, $b70c(v0)
80046844	nop
80046848	lw     v0, $0000(v1)
8004684C	nop
80046850	lbu    a1, $0000(v0)
80046854	addiu  v0, v0, $0001
80046858	sw     v0, $0000(v1)

L4685c:	; 8004685C
8004685C	addu   a0, s2, zero
80046860	lui    a3, $8008
80046864	lui    a2, $8008
80046868	lw     v0, $b6f4(a3)
8004686C	addiu  v1, zero, $0001
80046870	sw     v1, $b6f8(a2)
80046874	srav   v0, v1, v0
80046878	jal    funcc8044 [$800c8044]
8004687C	sw     v0, $b6f4(a3)
80046880	j      L475b4 [$800475b4]
80046884	addu   v0, zero, zero
80046888	lui    v0, $8008
8004688C	lw     v0, $b6f4(v0)
80046890	nop
80046894	andi   v0, v0, $0001
80046898	beq    v0, zero, L468b8 [$800468b8]
8004689C	lui    v0, $8008
800468A0	jal    func52da0 [$80052da0]
800468A4	nop
800468A8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800468AC	nop
800468B0	j      L468d4 [$800468d4]
800468B4	addu   a0, v0, zero

L468b8:	; 800468B8
800468B8	lw     v1, $b70c(v0)
800468BC	nop
800468C0	lw     v0, $0000(v1)
800468C4	nop
800468C8	lbu    a0, $0000(v0)
800468CC	addiu  v0, v0, $0001
800468D0	sw     v0, $0000(v1)

L468d4:	; 800468D4
800468D4	addu   s2, a0, zero
800468D8	lui    a1, $8008
800468DC	lui    a0, $8008
800468E0	lw     v0, $b6f4(a1)
800468E4	addiu  v1, zero, $0001
800468E8	sw     v1, $b6f8(a0)
800468EC	srav   v0, v1, v0
800468F0	sw     v0, $b6f4(a1)
800468F4	and    v0, v0, v1
800468F8	beq    v0, zero, L46918 [$80046918]
800468FC	lui    v0, $8008
80046900	jal    func52da0 [$80052da0]
80046904	nop
80046908	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004690C	nop
80046910	j      L46950 [$80046950]
80046914	addu   a1, v0, zero

L46918:	; 80046918
80046918	lw     a0, $b70c(v0)
8004691C	nop
80046920	lw     v0, $0000(a0)
80046924	nop
80046928	lbu    a1, $0000(v0)
8004692C	addiu  v0, v0, $0001
80046930	sw     v0, $0000(a0)
80046934	lbu    v1, $0000(v0)
80046938	addiu  v0, v0, $0001
8004693C	sw     v0, $0000(a0)
80046940	sll    v1, v1, $08
80046944	or     a1, a1, v1
80046948	sll    v0, a1, $10
8004694C	sra    a1, v0, $10

L46950:	; 80046950
80046950	addu   a0, s2, zero
80046954	sll    a1, a1, $10
80046958	sra    a1, a1, $10
8004695C	lui    a3, $8008
80046960	lui    a2, $8008
80046964	lw     v0, $b6f4(a3)
80046968	addiu  v1, zero, $0001
8004696C	sw     v1, $b6f8(a2)
80046970	srav   v0, v1, v0
80046974	jal    funcc8068 [$800c8068]
80046978	sw     v0, $b6f4(a3)
8004697C	j      L475b4 [$800475b4]
80046980	addu   v0, zero, zero
80046984	lui    v0, $8008
80046988	lw     v0, $b6f4(v0)
8004698C	nop
80046990	andi   v0, v0, $0001
80046994	beq    v0, zero, L469b4 [$800469b4]
80046998	lui    v0, $8008
8004699C	jal    func52da0 [$80052da0]
800469A0	nop
800469A4	jal    system_read_from_stack_command_not_from_script [$80052d40]
800469A8	nop
800469AC	j      L469d0 [$800469d0]
800469B0	addu   a0, v0, zero

L469b4:	; 800469B4
800469B4	lw     v1, $b70c(v0)
800469B8	nop
800469BC	lw     v0, $0000(v1)
800469C0	nop
800469C4	lbu    a0, $0000(v0)
800469C8	addiu  v0, v0, $0001
800469CC	sw     v0, $0000(v1)

L469d0:	; 800469D0
800469D0	addu   s2, a0, zero
800469D4	lui    a1, $8008
800469D8	lui    a0, $8008
800469DC	lw     v0, $b6f4(a1)
800469E0	addiu  v1, zero, $0001
800469E4	sw     v1, $b6f8(a0)
800469E8	srav   v0, v1, v0
800469EC	sw     v0, $b6f4(a1)
800469F0	and    v0, v0, v1
800469F4	beq    v0, zero, L46a14 [$80046a14]
800469F8	lui    v0, $8008
800469FC	jal    func52da0 [$80052da0]
80046A00	nop
80046A04	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046A08	nop
80046A0C	j      L46a30 [$80046a30]
80046A10	addu   a1, v0, zero

L46a14:	; 80046A14
80046A14	lw     v1, $b70c(v0)
80046A18	nop
80046A1C	lw     v0, $0000(v1)
80046A20	nop
80046A24	lbu    a1, $0000(v0)
80046A28	addiu  v0, v0, $0001
80046A2C	sw     v0, $0000(v1)

L46a30:	; 80046A30
80046A30	addu   a0, s2, zero
80046A34	lui    a3, $8008
80046A38	lui    a2, $8008
80046A3C	lw     v0, $b6f4(a3)
80046A40	addiu  v1, zero, $0001
80046A44	sw     v1, $b6f8(a2)
80046A48	srav   v0, v1, v0
80046A4C	jal    funcc808c [$800c808c]
80046A50	sw     v0, $b6f4(a3)
80046A54	j      L475b4 [$800475b4]
80046A58	addu   v0, zero, zero
80046A5C	lui    v0, $8008
80046A60	lw     v0, $b6f4(v0)
80046A64	nop
80046A68	andi   v0, v0, $0001
80046A6C	beq    v0, zero, L46a8c [$80046a8c]
80046A70	lui    v0, $8008
80046A74	jal    func52da0 [$80052da0]
80046A78	nop
80046A7C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046A80	nop
80046A84	j      L46aa8 [$80046aa8]
80046A88	addu   a0, v0, zero

L46a8c:	; 80046A8C
80046A8C	lw     v1, $b70c(v0)
80046A90	nop
80046A94	lw     v0, $0000(v1)
80046A98	nop
80046A9C	lbu    a0, $0000(v0)
80046AA0	addiu  v0, v0, $0001
80046AA4	sw     v0, $0000(v1)

L46aa8:	; 80046AA8
80046AA8	addu   s2, a0, zero
80046AAC	lui    a1, $8008
80046AB0	lui    a0, $8008
80046AB4	lw     v0, $b6f4(a1)
80046AB8	addiu  v1, zero, $0001
80046ABC	sw     v1, $b6f8(a0)
80046AC0	srav   v0, v1, v0
80046AC4	sw     v0, $b6f4(a1)
80046AC8	and    v0, v0, v1
80046ACC	beq    v0, zero, L46aec [$80046aec]
80046AD0	lui    v0, $8008
80046AD4	jal    func52da0 [$80052da0]
80046AD8	nop
80046ADC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046AE0	nop
80046AE4	j      L46b24 [$80046b24]
80046AE8	addu   a1, v0, zero

L46aec:	; 80046AEC
80046AEC	lw     a0, $b70c(v0)
80046AF0	nop
80046AF4	lw     v0, $0000(a0)
80046AF8	nop
80046AFC	lbu    a1, $0000(v0)
80046B00	addiu  v0, v0, $0001
80046B04	sw     v0, $0000(a0)
80046B08	lbu    v1, $0000(v0)
80046B0C	addiu  v0, v0, $0001
80046B10	sw     v0, $0000(a0)
80046B14	sll    v1, v1, $08
80046B18	or     a1, a1, v1
80046B1C	sll    v0, a1, $10
80046B20	sra    a1, v0, $10

L46b24:	; 80046B24
80046B24	addu   s3, a1, zero
80046B28	lui    a1, $8008
80046B2C	lui    a0, $8008
80046B30	lw     v0, $b6f4(a1)
80046B34	addiu  v1, zero, $0001
80046B38	sw     v1, $b6f8(a0)
80046B3C	srav   v0, v1, v0
80046B40	sw     v0, $b6f4(a1)
80046B44	and    v0, v0, v1
80046B48	beq    v0, zero, L46b68 [$80046b68]
80046B4C	lui    v0, $8008
80046B50	jal    func52da0 [$80052da0]
80046B54	nop
80046B58	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046B5C	nop
80046B60	j      L46ba0 [$80046ba0]
80046B64	addu   a2, v0, zero

L46b68:	; 80046B68
80046B68	lw     a0, $b70c(v0)
80046B6C	nop
80046B70	lw     v0, $0000(a0)
80046B74	nop
80046B78	lbu    a2, $0000(v0)
80046B7C	addiu  v0, v0, $0001
80046B80	sw     v0, $0000(a0)
80046B84	lbu    v1, $0000(v0)
80046B88	addiu  v0, v0, $0001
80046B8C	sw     v0, $0000(a0)
80046B90	sll    v1, v1, $08
80046B94	or     a2, a2, v1
80046B98	sll    v0, a2, $10
80046B9C	sra    a2, v0, $10

L46ba0:	; 80046BA0
80046BA0	addu   a0, s2, zero
80046BA4	sll    a1, s3, $10
80046BA8	sra    a1, a1, $10
80046BAC	sll    a2, a2, $10
80046BB0	sra    a2, a2, $10
80046BB4	lui    t0, $8008
80046BB8	lui    a3, $8008
80046BBC	lw     v0, $b6f4(t0)
80046BC0	addiu  v1, zero, $0001
80046BC4	sw     v1, $b6f8(a3)
80046BC8	srav   v0, v1, v0
80046BCC	jal    funcc80b0 [$800c80b0]
80046BD0	sw     v0, $b6f4(t0)
80046BD4	j      L475b4 [$800475b4]
80046BD8	addu   v0, zero, zero
80046BDC	lui    v0, $8008
80046BE0	lw     v0, $b6f4(v0)
80046BE4	nop
80046BE8	andi   v0, v0, $0001
80046BEC	beq    v0, zero, L46c0c [$80046c0c]
80046BF0	lui    v0, $8008
80046BF4	jal    func52da0 [$80052da0]
80046BF8	nop
80046BFC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046C00	nop
80046C04	j      L46c28 [$80046c28]
80046C08	addu   a0, v0, zero

L46c0c:	; 80046C0C
80046C0C	lw     v1, $b70c(v0)
80046C10	nop
80046C14	lw     v0, $0000(v1)
80046C18	nop
80046C1C	lbu    a0, $0000(v0)
80046C20	addiu  v0, v0, $0001
80046C24	sw     v0, $0000(v1)

L46c28:	; 80046C28
80046C28	addu   s2, a0, zero
80046C2C	lui    a1, $8008
80046C30	lui    a0, $8008
80046C34	lw     v0, $b6f4(a1)
80046C38	addiu  v1, zero, $0001
80046C3C	sw     v1, $b6f8(a0)
80046C40	srav   v0, v1, v0
80046C44	sw     v0, $b6f4(a1)
80046C48	and    v0, v0, v1
80046C4C	beq    v0, zero, L46c6c [$80046c6c]
80046C50	lui    v0, $8008
80046C54	jal    func52da0 [$80052da0]
80046C58	nop
80046C5C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046C60	nop
80046C64	j      L46c88 [$80046c88]
80046C68	addu   a1, v0, zero

L46c6c:	; 80046C6C
80046C6C	lw     v1, $b70c(v0)
80046C70	nop
80046C74	lw     v0, $0000(v1)
80046C78	nop
80046C7C	lbu    a1, $0000(v0)
80046C80	addiu  v0, v0, $0001
80046C84	sw     v0, $0000(v1)

L46c88:	; 80046C88
80046C88	addu   a0, s2, zero
80046C8C	lui    a3, $8008
80046C90	lui    a2, $8008
80046C94	lw     v0, $b6f4(a3)
80046C98	addiu  v1, zero, $0001
80046C9C	sw     v1, $b6f8(a2)
80046CA0	srav   v0, v1, v0
80046CA4	jal    funcc80e4 [$800c80e4]
80046CA8	sw     v0, $b6f4(a3)
80046CAC	j      L475b4 [$800475b4]
80046CB0	addu   v0, zero, zero
80046CB4	lui    v0, $8008
80046CB8	lw     v0, $b6f4(v0)
80046CBC	nop
80046CC0	andi   v0, v0, $0001
80046CC4	beq    v0, zero, L46ce4 [$80046ce4]
80046CC8	lui    v0, $8008
80046CCC	jal    func52da0 [$80052da0]
80046CD0	nop
80046CD4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046CD8	nop
80046CDC	j      L46d00 [$80046d00]
80046CE0	addu   a0, v0, zero

L46ce4:	; 80046CE4
80046CE4	lw     v1, $b70c(v0)
80046CE8	nop
80046CEC	lw     v0, $0000(v1)
80046CF0	nop
80046CF4	lbu    a0, $0000(v0)
80046CF8	addiu  v0, v0, $0001
80046CFC	sw     v0, $0000(v1)

L46d00:	; 80046D00
80046D00	addu   s2, a0, zero
80046D04	lui    a1, $8008
80046D08	lui    a0, $8008
80046D0C	lw     v0, $b6f4(a1)
80046D10	addiu  v1, zero, $0001
80046D14	sw     v1, $b6f8(a0)
80046D18	srav   v0, v1, v0
80046D1C	sw     v0, $b6f4(a1)
80046D20	and    v0, v0, v1
80046D24	beq    v0, zero, L46d44 [$80046d44]
80046D28	lui    v0, $8008
80046D2C	jal    func52da0 [$80052da0]
80046D30	nop
80046D34	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046D38	nop
80046D3C	j      L46d60 [$80046d60]
80046D40	addu   a1, v0, zero

L46d44:	; 80046D44
80046D44	lw     v1, $b70c(v0)
80046D48	nop
80046D4C	lw     v0, $0000(v1)
80046D50	nop
80046D54	lbu    a1, $0000(v0)
80046D58	addiu  v0, v0, $0001
80046D5C	sw     v0, $0000(v1)

L46d60:	; 80046D60
80046D60	addu   a0, s2, zero
80046D64	lui    a3, $8008
80046D68	lui    a2, $8008
80046D6C	lw     v0, $b6f4(a3)
80046D70	addiu  v1, zero, $0001
80046D74	sw     v1, $b6f8(a2)
80046D78	srav   v0, v1, v0
80046D7C	jal    funcc7af8 [$800c7af8]
80046D80	sw     v0, $b6f4(a3)
80046D84	j      L475b4 [$800475b4]
80046D88	addu   v0, zero, zero
80046D8C	lui    v0, $8008
80046D90	lw     v0, $b6f4(v0)
80046D94	nop
80046D98	andi   v0, v0, $0001
80046D9C	beq    v0, zero, L46dbc [$80046dbc]
80046DA0	lui    v0, $8008
80046DA4	jal    func52da0 [$80052da0]
80046DA8	nop
80046DAC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046DB0	nop
80046DB4	j      L46dd8 [$80046dd8]
80046DB8	addu   a0, v0, zero

L46dbc:	; 80046DBC
80046DBC	lw     v1, $b70c(v0)
80046DC0	nop
80046DC4	lw     v0, $0000(v1)
80046DC8	nop
80046DCC	lbu    a0, $0000(v0)
80046DD0	addiu  v0, v0, $0001
80046DD4	sw     v0, $0000(v1)

L46dd8:	; 80046DD8
80046DD8	addu   s2, a0, zero
80046DDC	lui    a1, $8008
80046DE0	lui    a0, $8008
80046DE4	lw     v0, $b6f4(a1)
80046DE8	addiu  v1, zero, $0001
80046DEC	sw     v1, $b6f8(a0)
80046DF0	srav   v0, v1, v0
80046DF4	sw     v0, $b6f4(a1)
80046DF8	and    v0, v0, v1
80046DFC	beq    v0, zero, L46e1c [$80046e1c]
80046E00	lui    v0, $8008
80046E04	jal    func52da0 [$80052da0]
80046E08	nop
80046E0C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046E10	nop
80046E14	j      L46e38 [$80046e38]
80046E18	addu   a1, v0, zero

L46e1c:	; 80046E1C
80046E1C	lw     v1, $b70c(v0)
80046E20	nop
80046E24	lw     v0, $0000(v1)
80046E28	nop
80046E2C	lbu    a1, $0000(v0)
80046E30	addiu  v0, v0, $0001
80046E34	sw     v0, $0000(v1)

L46e38:	; 80046E38
80046E38	addu   a0, s2, zero
80046E3C	lui    a3, $8008
80046E40	lui    a2, $8008
80046E44	lw     v0, $b6f4(a3)
80046E48	addiu  v1, zero, $0001
80046E4C	sw     v1, $b6f8(a2)
80046E50	srav   v0, v1, v0
80046E54	jal    funcc6408 [$800c6408]
80046E58	sw     v0, $b6f4(a3)
80046E5C	j      L475b4 [$800475b4]
80046E60	addu   v0, zero, zero
80046E64	lui    v0, $8008
80046E68	lw     v0, $b6f4(v0)
80046E6C	nop
80046E70	andi   v0, v0, $0001
80046E74	beq    v0, zero, L46e94 [$80046e94]
80046E78	lui    v0, $8008
80046E7C	jal    func52da0 [$80052da0]
80046E80	nop
80046E84	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046E88	nop
80046E8C	j      L46eb0 [$80046eb0]
80046E90	addu   a0, v0, zero

L46e94:	; 80046E94
80046E94	lw     v1, $b70c(v0)
80046E98	nop
80046E9C	lw     v0, $0000(v1)
80046EA0	nop
80046EA4	lbu    a0, $0000(v0)
80046EA8	addiu  v0, v0, $0001
80046EAC	sw     v0, $0000(v1)

L46eb0:	; 80046EB0
80046EB0	addu   s2, a0, zero
80046EB4	lui    a1, $8008
80046EB8	lui    a0, $8008
80046EBC	lw     v0, $b6f4(a1)
80046EC0	addiu  v1, zero, $0001
80046EC4	sw     v1, $b6f8(a0)
80046EC8	srav   v0, v1, v0
80046ECC	sw     v0, $b6f4(a1)
80046ED0	and    v0, v0, v1
80046ED4	beq    v0, zero, L46ef4 [$80046ef4]
80046ED8	lui    v0, $8008
80046EDC	jal    func52da0 [$80052da0]
80046EE0	nop
80046EE4	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046EE8	nop
80046EEC	j      L46f10 [$80046f10]
80046EF0	addu   a1, v0, zero

L46ef4:	; 80046EF4
80046EF4	lw     v1, $b70c(v0)
80046EF8	nop
80046EFC	lw     v0, $0000(v1)
80046F00	nop
80046F04	lbu    a1, $0000(v0)
80046F08	addiu  v0, v0, $0001
80046F0C	sw     v0, $0000(v1)

L46f10:	; 80046F10
80046F10	addu   a0, s2, zero
80046F14	lui    a3, $8008
80046F18	lui    a2, $8008
80046F1C	lw     v0, $b6f4(a3)
80046F20	addiu  v1, zero, $0001
80046F24	sw     v1, $b6f8(a2)
80046F28	srav   v0, v1, v0
80046F2C	jal    funcc7b68 [$800c7b68]
80046F30	sw     v0, $b6f4(a3)
80046F34	j      L475b4 [$800475b4]
80046F38	addu   v0, zero, zero
80046F3C	lui    v0, $8008
80046F40	lw     v0, $b6f4(v0)
80046F44	nop
80046F48	andi   v0, v0, $0001
80046F4C	beq    v0, zero, L46f6c [$80046f6c]
80046F50	lui    v0, $8008
80046F54	jal    func52da0 [$80052da0]
80046F58	nop
80046F5C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046F60	nop
80046F64	j      L46f88 [$80046f88]
80046F68	addu   a0, v0, zero

L46f6c:	; 80046F6C
80046F6C	lw     v1, $b70c(v0)
80046F70	nop
80046F74	lw     v0, $0000(v1)
80046F78	nop
80046F7C	lbu    a0, $0000(v0)
80046F80	addiu  v0, v0, $0001
80046F84	sw     v0, $0000(v1)

L46f88:	; 80046F88
80046F88	addu   s2, a0, zero
80046F8C	lui    a1, $8008
80046F90	lui    a0, $8008
80046F94	lw     v0, $b6f4(a1)
80046F98	addiu  v1, zero, $0001
80046F9C	sw     v1, $b6f8(a0)
80046FA0	srav   v0, v1, v0
80046FA4	sw     v0, $b6f4(a1)
80046FA8	and    v0, v0, v1
80046FAC	beq    v0, zero, L46fcc [$80046fcc]
80046FB0	lui    v0, $8008
80046FB4	jal    func52da0 [$80052da0]
80046FB8	nop
80046FBC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80046FC0	nop
80046FC4	j      L46fe8 [$80046fe8]
80046FC8	addu   a1, v0, zero

L46fcc:	; 80046FCC
80046FCC	lw     v1, $b70c(v0)
80046FD0	nop
80046FD4	lw     v0, $0000(v1)
80046FD8	nop
80046FDC	lbu    a1, $0000(v0)
80046FE0	addiu  v0, v0, $0001
80046FE4	sw     v0, $0000(v1)

L46fe8:	; 80046FE8
80046FE8	addu   a0, s2, zero
80046FEC	lui    a3, $8008
80046FF0	lui    a2, $8008
80046FF4	lw     v0, $b6f4(a3)
80046FF8	addiu  v1, zero, $0001
80046FFC	sw     v1, $b6f8(a2)

func47000:	; 80047000
80047000	srav   v0, v1, v0
80047004	jal    funcc7cdc [$800c7cdc]
80047008	sw     v0, $b6f4(a3)
8004700C	j      L475b4 [$800475b4]
80047010	addu   v0, zero, zero
80047014	lui    v0, $8008
80047018	lw     v0, $b6f4(v0)
8004701C	nop
80047020	andi   v0, v0, $0001
80047024	beq    v0, zero, L47044 [$80047044]
80047028	lui    v0, $8008
8004702C	jal    func52da0 [$80052da0]
80047030	nop
80047034	jal    system_read_from_stack_command_not_from_script [$80052d40]
80047038	nop
8004703C	j      L47060 [$80047060]
80047040	addu   a0, v0, zero

L47044:	; 80047044
80047044	lw     v1, $b70c(v0)
80047048	nop
8004704C	lw     v0, $0000(v1)
80047050	nop
80047054	lbu    a0, $0000(v0)
80047058	addiu  v0, v0, $0001
8004705C	sw     v0, $0000(v1)

L47060:	; 80047060
80047060	addu   s2, a0, zero
80047064	lui    a1, $8008
80047068	lui    a0, $8008
8004706C	lw     v0, $b6f4(a1)
80047070	addiu  v1, zero, $0001
80047074	sw     v1, $b6f8(a0)
80047078	srav   v0, v1, v0
8004707C	sw     v0, $b6f4(a1)
80047080	and    v0, v0, v1
80047084	beq    v0, zero, L470a4 [$800470a4]
80047088	lui    v0, $8008
8004708C	jal    func52da0 [$80052da0]
80047090	nop
80047094	jal    system_read_from_stack_command_not_from_script [$80052d40]
80047098	nop
8004709C	j      L470dc [$800470dc]
800470A0	addu   a1, v0, zero

L470a4:	; 800470A4
800470A4	lw     a0, $b70c(v0)
800470A8	nop
800470AC	lw     v0, $0000(a0)
800470B0	nop
800470B4	lbu    a1, $0000(v0)
800470B8	addiu  v0, v0, $0001
800470BC	sw     v0, $0000(a0)
800470C0	lbu    v1, $0000(v0)
800470C4	addiu  v0, v0, $0001
800470C8	sw     v0, $0000(a0)
800470CC	sll    v1, v1, $08
800470D0	or     a1, a1, v1
800470D4	sll    v0, a1, $10
800470D8	sra    a1, v0, $10

L470dc:	; 800470DC
800470DC	addu   a0, s2, zero
800470E0	sll    a1, a1, $10
800470E4	sra    a1, a1, $10
800470E8	lui    a3, $8008
800470EC	lui    a2, $8008
800470F0	lw     v0, $b6f4(a3)
800470F4	addiu  v1, zero, $0001
800470F8	sw     v1, $b6f8(a2)
800470FC	srav   v0, v1, v0
80047100	jal    funcc7bc4 [$800c7bc4]
80047104	sw     v0, $b6f4(a3)
80047108	j      L475b4 [$800475b4]
8004710C	addu   v0, zero, zero
80047110	lui    v0, $8008
80047114	lw     v0, $b6f4(v0)
80047118	nop
8004711C	andi   v0, v0, $0001
80047120	beq    v0, zero, L47140 [$80047140]
80047124	lui    v0, $8008
80047128	jal    func52da0 [$80052da0]
8004712C	nop
80047130	jal    system_read_from_stack_command_not_from_script [$80052d40]
80047134	nop
80047138	j      L4715c [$8004715c]
8004713C	addu   a0, v0, zero

L47140:	; 80047140
80047140	lw     v1, $b70c(v0)
80047144	nop
80047148	lw     v0, $0000(v1)
8004714C	nop
80047150	lbu    a0, $0000(v0)
80047154	addiu  v0, v0, $0001
80047158	sw     v0, $0000(v1)

L4715c:	; 8004715C
8004715C	addu   s2, a0, zero
80047160	lui    a1, $8008
80047164	lui    a0, $8008
80047168	lw     v0, $b6f4(a1)
8004716C	addiu  v1, zero, $0001
80047170	sw     v1, $b6f8(a0)
80047174	srav   v0, v1, v0
80047178	sw     v0, $b6f4(a1)
8004717C	and    v0, v0, v1
80047180	beq    v0, zero, L471a0 [$800471a0]
80047184	lui    v0, $8008
80047188	jal    func52da0 [$80052da0]
8004718C	nop
80047190	jal    system_read_from_stack_command_not_from_script [$80052d40]
80047194	nop
80047198	j      L471bc [$800471bc]
8004719C	addu   a1, v0, zero

L471a0:	; 800471A0
800471A0	lw     v1, $b70c(v0)
800471A4	nop
800471A8	lw     v0, $0000(v1)
800471AC	nop
800471B0	lbu    a1, $0000(v0)
800471B4	addiu  v0, v0, $0001
800471B8	sw     v0, $0000(v1)

L471bc:	; 800471BC
800471BC	addu   a0, s2, zero
800471C0	lui    a3, $8008
800471C4	lui    a2, $8008
800471C8	lw     v0, $b6f4(a3)
800471CC	addiu  v1, zero, $0001
800471D0	sw     v1, $b6f8(a2)
800471D4	srav   v0, v1, v0
800471D8	jal    funcc7c04 [$800c7c04]
800471DC	sw     v0, $b6f4(a3)
800471E0	j      L475b4 [$800475b4]
800471E4	addu   v0, zero, zero
800471E8	lui    v0, $8008
800471EC	lw     v0, $b6f4(v0)
800471F0	nop
800471F4	andi   v0, v0, $0001
800471F8	beq    v0, zero, L47218 [$80047218]
800471FC	lui    v0, $8008
80047200	jal    func52da0 [$80052da0]
80047204	nop
80047208	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004720C	nop
80047210	j      L47234 [$80047234]
80047214	addu   a0, v0, zero

L47218:	; 80047218
80047218	lw     v1, $b70c(v0)
8004721C	nop
80047220	lw     v0, $0000(v1)
80047224	nop
80047228	lbu    a0, $0000(v0)
8004722C	addiu  v0, v0, $0001
80047230	sw     v0, $0000(v1)

L47234:	; 80047234
80047234	addu   s2, a0, zero
80047238	lui    a1, $8008
8004723C	lui    a0, $8008
80047240	lw     v0, $b6f4(a1)
80047244	addiu  v1, zero, $0001
80047248	sw     v1, $b6f8(a0)
8004724C	srav   v0, v1, v0
80047250	sw     v0, $b6f4(a1)
80047254	and    v0, v0, v1
80047258	beq    v0, zero, L47278 [$80047278]
8004725C	lui    v0, $8008
80047260	jal    func52da0 [$80052da0]
80047264	nop
80047268	jal    system_read_from_stack_command_not_from_script [$80052d40]
8004726C	nop
80047270	j      L47294 [$80047294]
80047274	addu   a0, v0, zero

L47278:	; 80047278
80047278	lw     v1, $b70c(v0)
8004727C	nop
80047280	lw     v0, $0000(v1)
80047284	nop
80047288	lbu    a0, $0000(v0)
8004728C	addiu  v0, v0, $0001
80047290	sw     v0, $0000(v1)

L47294:	; 80047294
80047294	addu   s3, a0, zero
80047298	lui    a1, $8008
8004729C	lui    a0, $8008
800472A0	lw     v0, $b6f4(a1)
800472A4	addiu  v1, zero, $0001
800472A8	sw     v1, $b6f8(a0)
800472AC	srav   v0, v1, v0
800472B0	sw     v0, $b6f4(a1)
800472B4	and    v0, v0, v1
800472B8	beq    v0, zero, L472d8 [$800472d8]
800472BC	lui    v0, $8008
800472C0	jal    func52da0 [$80052da0]
800472C4	nop
800472C8	jal    system_read_from_stack_command_not_from_script [$80052d40]
800472CC	nop
800472D0	j      L472f4 [$800472f4]
800472D4	addu   a2, v0, zero

L472d8:	; 800472D8
800472D8	lw     v1, $b70c(v0)
800472DC	nop
800472E0	lw     v0, $0000(v1)
800472E4	nop
800472E8	lbu    a2, $0000(v0)
800472EC	addiu  v0, v0, $0001
800472F0	sw     v0, $0000(v1)

L472f4:	; 800472F4
800472F4	addu   a0, s2, zero
800472F8	addu   a1, s3, zero
800472FC	lui    t0, $8008
80047300	lui    a3, $8008
80047304	lw     v0, $b6f4(t0)
80047308	addiu  v1, zero, $0001
8004730C	sw     v1, $b6f8(a3)
80047310	srav   v0, v1, v0
80047314	jal    funcc7c70 [$800c7c70]
80047318	sw     v0, $b6f4(t0)
8004731C	j      L475b4 [$800475b4]
80047320	addu   v0, zero, zero
80047324	lui    v0, $8008
80047328	lw     v0, $b6f4(v0)
8004732C	nop
80047330	andi   v0, v0, $0001
80047334	beq    v0, zero, L47354 [$80047354]
80047338	lui    v0, $8008
8004733C	jal    func52da0 [$80052da0]
80047340	nop
80047344	jal    system_read_from_stack_command_not_from_script [$80052d40]
80047348	nop
8004734C	j      L47370 [$80047370]
80047350	addu   a0, v0, zero

L47354:	; 80047354
80047354	lw     v1, $b70c(v0)
80047358	nop
8004735C	lw     v0, $0000(v1)
80047360	nop
80047364	lbu    a0, $0000(v0)
80047368	addiu  v0, v0, $0001
8004736C	sw     v0, $0000(v1)

L47370:	; 80047370
80047370	addu   s2, a0, zero
80047374	lui    a1, $8008
80047378	lui    a0, $8008
8004737C	lw     v0, $b6f4(a1)
80047380	addiu  v1, zero, $0001
80047384	sw     v1, $b6f8(a0)
80047388	srav   v0, v1, v0
8004738C	sw     v0, $b6f4(a1)
80047390	and    v0, v0, v1
80047394	beq    v0, zero, L473b4 [$800473b4]
80047398	lui    v0, $8008
8004739C	jal    func52da0 [$80052da0]
800473A0	nop
800473A4	jal    system_read_from_stack_command_not_from_script [$80052d40]
800473A8	nop
800473AC	j      L473d0 [$800473d0]
800473B0	addu   a0, v0, zero

L473b4:	; 800473B4
800473B4	lw     v1, $b70c(v0)
800473B8	nop
800473BC	lw     v0, $0000(v1)
800473C0	nop
800473C4	lbu    a0, $0000(v0)
800473C8	addiu  v0, v0, $0001
800473CC	sw     v0, $0000(v1)

L473d0:	; 800473D0
800473D0	addu   s3, a0, zero
800473D4	lui    a1, $8008
800473D8	lui    a0, $8008
800473DC	lw     v0, $b6f4(a1)
800473E0	addiu  v1, zero, $0001
800473E4	sw     v1, $b6f8(a0)
800473E8	srav   v0, v1, v0
800473EC	sw     v0, $b6f4(a1)
800473F0	and    v0, v0, v1
800473F4	beq    v0, zero, L47414 [$80047414]
800473F8	lui    v0, $8008
800473FC	jal    func52da0 [$80052da0]
80047400	nop
80047404	jal    system_read_from_stack_command_not_from_script [$80052d40]
80047408	nop
8004740C	j      L47430 [$80047430]
80047410	addu   a2, v0, zero

L47414:	; 80047414
80047414	lw     v1, $b70c(v0)
80047418	nop
8004741C	lw     v0, $0000(v1)
80047420	nop
80047424	lbu    a2, $0000(v0)
80047428	addiu  v0, v0, $0001
8004742C	sw     v0, $0000(v1)

L47430:	; 80047430
80047430	addu   a0, s2, zero
80047434	addu   a1, s3, zero
80047438	lui    t0, $8008
8004743C	lui    a3, $8008
80047440	lw     v0, $b6f4(t0)
80047444	addiu  v1, zero, $0001
80047448	sw     v1, $b6f8(a3)
8004744C	srav   v0, v1, v0
80047450	jal    funcc7d30 [$800c7d30]
80047454	sw     v0, $b6f4(t0)
80047458	j      L475b4 [$800475b4]
8004745C	addu   v0, zero, zero
80047460	lui    v0, $8008
80047464	lw     v0, $b6f4(v0)
80047468	nop
8004746C	andi   v0, v0, $0001
80047470	beq    v0, zero, L47490 [$80047490]
80047474	lui    v0, $8008
80047478	jal    func52da0 [$80052da0]
8004747C	nop
80047480	jal    system_read_from_stack_command_not_from_script [$80052d40]
80047484	nop
80047488	j      L474ac [$800474ac]
8004748C	addu   a0, v0, zero

L47490:	; 80047490
80047490	lw     v1, $b70c(v0)
80047494	nop
80047498	lw     v0, $0000(v1)
8004749C	nop
800474A0	lbu    a0, $0000(v0)
800474A4	addiu  v0, v0, $0001
800474A8	sw     v0, $0000(v1)

L474ac:	; 800474AC
800474AC	addu   s2, a0, zero
800474B0	lui    a1, $8008
800474B4	lui    a0, $8008
800474B8	lw     v0, $b6f4(a1)
800474BC	addiu  v1, zero, $0001
800474C0	sw     v1, $b6f8(a0)
800474C4	srav   v0, v1, v0
800474C8	sw     v0, $b6f4(a1)
800474CC	and    v0, v0, v1
800474D0	beq    v0, zero, L474f0 [$800474f0]
800474D4	lui    v0, $8008
800474D8	jal    func52da0 [$80052da0]
800474DC	nop
800474E0	jal    system_read_from_stack_command_not_from_script [$80052d40]
800474E4	nop
800474E8	j      L4750c [$8004750c]
800474EC	addu   a1, v0, zero

L474f0:	; 800474F0
800474F0	lw     v1, $b70c(v0)
800474F4	nop
800474F8	lw     v0, $0000(v1)
800474FC	nop
80047500	lbu    a1, $0000(v0)
80047504	addiu  v0, v0, $0001
80047508	sw     v0, $0000(v1)

L4750c:	; 8004750C
8004750C	addu   a0, s2, zero
80047510	lui    a3, $8008
80047514	lui    a2, $8008
80047518	lw     v0, $b6f4(a3)
8004751C	addiu  v1, zero, $0001
80047520	sw     v1, $b6f8(a2)
80047524	srav   v0, v1, v0
80047528	jal    funcc7df0 [$800c7df0]
8004752C	sw     v0, $b6f4(a3)
80047530	j      L475b4 [$800475b4]
80047534	addu   v0, zero, zero

L475b4:	; 800475B4
return
////////////////////////////////



////////////////////////////////
// get8byte

V0 = w[8007b6f4];
if (V0 & 1)
{
    func52da0;
    system_read_from_stack_command_not_from_script;
    A2 = V0;
}
else
{
    V1 = w[8007b70c];
    V0 = w[V1];
    A2 = bu[V0];
    [V1] = w(V0 + 1);
}

[8007b6f4] = w(w[8007b6f4] >> 1);

return A2;
////////////////////////////////



////////////////////////////////
// get16byte

V0 = w[8007b6f4];
if (V0 & 1)
{
    func52da0;
    system_read_from_stack_command_not_from_script;
    A2 = V0;
}
else
{
    A0 = w[8007b70c];
    V0 = w[A0];
    A2 = bu[V0 + 0];
    V1 = bu[V0 + 1];
    [A0] = w(V0 + 2);
    A2 = A2 | (V1 << 8);
    A2 = (A2 << 10) >> 10;
}

[8007b6f4] = w(w[8007b6f4] >> 1);

return A2;
////////////////////////////////



////////////////////////////////
// get24byte

V0 = w[8007b6f4];
if (V0 & 1)
{
    func52da0;
    system_read_from_stack_command_not_from_script;
    A2 = V0;
}
else
{
    A1 = w[8007b70c];
    V0 = w[A1];
    A2 = bu[V0 + 0];
    A0 = bu[V0 + 1];
    V1 = bu[V0 + 2];
    [A1] = w(V0 + 3);
    A2 = A2 | (A0 << 8) | (V1 << 10);
}

[8007b6f4] = w(w[8007b6f4] >> 1);

return A2;
////////////////////////////////



////////////////////////////////
// func50410
// A0 = S4;
// A1 = A3; // opcode

S1 = A0;

if (A1 == 7f)
{
    A0 = bu[S1 + 3b];
    func1e350;
    [V0] = w(w[V0] & ffffffef);
    return 0;
}
else if (A1 == 80)
{
    A0 = bu[S1 + 3b];
    func1e350;
    [V0] = w(w[V0] | 00000010);
    return 0;
}
else if (A1 == 81)
{
    800504CC	jal    func4aedc [$8004aedc]
    800504D0	nop
    800504D4	jal    func4aedc [$8004aedc]
    800504D8	addu   s0, v0, zero
    800504DC	lui    a3, $fff0
    800504E0	ori    a3, a3, $00ff
    800504E4	lui    v1, $8006
    800504E8	lui    t0, $000f
    800504EC	lw     a2, $794c(v1)
    800504F0	ori    t0, t0, $ffff
    800504F4	lw     v1, $001c(a2)
    800504F8	lbu    a1, $003b(s1)
    800504FC	lw     v1, $08e4(v1)
    80050500	sll    a0, a1, $02
    80050504	lw     v1, $11c0(v1)
    80050508	addu   a0, a0, a1
    8005050C	lw     v1, $0028(v1)
    80050510	sll    a0, a0, $03
    80050514	addu   a0, a0, v1
    80050518	sll    v1, s0, $03
    8005051C	subu   v1, v1, s0
    80050520	sll    v1, v1, $01
    80050524	andi   v1, v1, $0fff
    80050528	lw     a1, $0000(a0)
    8005052C	sll    v1, v1, $08
    80050530	and    a1, a1, a3
    80050534	or     a1, a1, v1
    80050538	sw     a1, $0000(a0)
    8005053C	lbu    a1, $003b(s1)
    80050540	lw     v1, $001c(a2)
    80050544	sll    a0, a1, $02
    80050548	addu   a0, a0, a1
    8005054C	sll    a0, a0, $03
    80050550	lw     v1, $08e4(v1)
    80050554	sll    a1, v0, $01
    80050558	lw     v1, $11c0(v1)
    8005055C	addu   a1, a1, v0
    80050560	lw     v1, $0028(v1)
    80050568	addu   a0, a0, v1
    8005056C	lw     v1, $0000(a0)
    80050570	sll    a1, a1, $16
    80050574	and    v1, v1, t0
    80050578	or     v1, v1, a1
    80050580	sw     v1, $0000(a0)
    return 0;
}
else if (A1 == 82)
{
    80050584	jal    func4af58 [$8004af58]
    80050588	nop
    8005058C	jal    func4af58 [$8004af58]
    80050590	addu   s0, v0, zero
    80050594	lui    a3, $ffc0
    80050598	ori    a3, a3, $0fff
    8005059C	lui    v1, $8006
    800505A0	lui    t0, $003f
    800505A4	lw     a2, $794c(v1)
    800505A8	ori    t0, t0, $ffff
    800505AC	lw     v1, $001c(a2)
    800505B0	lbu    a1, $003b(s1)
    800505B4	lw     v1, $08e4(v1)
    800505B8	sll    a0, a1, $02
    800505BC	lw     v1, $11c0(v1)
    800505C0	addu   a0, a0, a1
    800505C4	lw     v1, $0028(v1)
    800505C8	sll    a0, a0, $03
    800505CC	addu   a0, a0, v1
    800505D0	andi   v1, s0, $03ff
    800505D4	lw     a1, $0004(a0)
    800505D8	sll    v1, v1, $0c
    800505DC	and    a1, a1, a3
    800505E0	or     a1, a1, v1
    800505E4	sw     a1, $0004(a0)
    800505E8	lbu    a1, $003b(s1)
    800505EC	lw     v1, $001c(a2)
    800505F0	sll    a0, a1, $02
    800505F4	lw     v1, $08e4(v1)
    800505F8	addu   a0, a0, a1
    800505FC	lw     v1, $11c0(v1)
    80050600	sll    a0, a0, $03
    80050604	lw     v1, $0028(v1)
    80050608	sll    a1, v0, $16
    8005060C	addu   a0, a0, v1
    80050610	lw     v1, $0004(a0)
    80050618	and    v1, v1, t0
    8005061C	or     v1, v1, a1
    80050624	sw     v1, $0004(a0)
    return 0;
}
else if (A1 == 83)
{
    80050628	jal    func4aedc [$8004aedc]
    8005062C	nop
    80050630	lbu    a0, $003b(s1)
    80050634	jal    func1e350 [$8001e350]
    80050638	addu   s0, v0, zero
    8005063C	addu   a1, v0, zero
    80050644	lui    a0, $8006
    80050648	lw     v1, $0000(a1)
    8005064C	lw     a0, $794c(a0)
    80050650	ori    v1, v1, $0020
    80050654	sw     v1, $0000(a1)
    80050658	lw     v1, $001c(a0)
    8005065C	lbu    a1, $003b(s1)
    80050660	lw     v1, $08e4(v1)
    80050664	sll    a0, a1, $02
    80050668	lw     v1, $11c0(v1)
    8005066C	addu   a0, a0, a1
    80050670	lw     v1, $0028(v1)
    80050674	sll    a0, a0, $03
    80050678	addu   a0, a0, v1
    8005067C	lw     a1, $0004(a0)
    80050680	addiu  v1, zero, $f000 (=-$1000)
    80050684	and    a1, a1, v1
    80050688	sll    v1, s0, $04
    8005068C	andi   v1, v1, $0fff
    80050690	or     a1, a1, v1
    80050698	sw     a1, $0004(a0)
    return 0;
}
else if (A1 == 84)
{
    8005069C	lbu    a0, $003b(s1)
    800506A0	jal    func1e350 [$8001e350]
    800506A4	nop
    800506A8	addu   v1, v0, zero
    800506B0	lw     a0, $0000(v1)
    800506B4	addiu  a1, zero, $ffdf (=-$21)
    800506B8	and    a0, a0, a1
    800506C0	sw     a0, $0000(v1)
    return 0;
}
else if (A1 == 85)
{
    800506C4	jal    func4aedc [$8004aedc]
    800506C8	nop
    800506CC	lui    v1, $8006
    800506D0	lw     v1, $794c(v1)
    800506D4	nop
    800506D8	lw     v1, $001c(v1)
    800506DC	lbu    a1, $003b(s1)
    800506E0	lw     a0, $08e4(v1)
    800506E4	sll    v1, a1, $02
    800506E8	lw     a0, $11c0(a0)
    800506EC	addu   v1, v1, a1
    800506F0	lw     a0, $0028(a0)
    800506F4	sll    v1, v1, $03
    800506F8	addu   v1, v1, a0
    800506FC	sb     v0, $0000(v1)
    return 0;
}
else if (A1 == d8)
{
    80050708	jal    func4aedc [$8004aedc]
    8005070C	nop
    80050710	jal    func4aedc [$8004aedc]
    80050714	addu   s0, v0, zero
    80050718	lui    v0, $8006
    8005071C	lw     v0, $794c(v0)
    80050720	nop
    80050724	lw     v1, $001c(v0)
    8005072C	sb     s0, $0570(v1)
    return 0;
}

return 1;
////////////////////////////////