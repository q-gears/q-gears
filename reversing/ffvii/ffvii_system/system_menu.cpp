////////////////////////////////
// func24a3c
// A0 - pointer to tutorial settings
[GP + b4] = w(1);

80024A60	sw     zero, $027c(gp)
80024A64	sw     zero, $01c8(gp)
80024A68	sw     zero, $0250(gp)

[GP + 8c] = w(0);
[GP + 90] = w(0);

80024A74	lui    at, $8006
80024A78	sb     zero, $2dfd(at)
if( A0 == 0 )
{
    80024A80	addu   a1, zero, zero
    80024A84	addu   a0, zero, zero
    80024A88	jal    func1f6e4 [$8001f6e4]
    80024A8C	addu   a2, zero, zero
    80024A90	lui    at, $8006
    80024A94	sw     zero, $2fa0(at)
}
else
{
    [GP + 150] = w(14);
    [GP + 158] = w(A0);
    [80062fa0] = w(1); // tutorial ON
}

80024AB0	lui    s0, $800a
80024AB4	lbu    s0, $d2a4(s0)
80024AB8	nop
80024ABC	andi   v0, s0, $0004
80024AC0	beq    v0, zero, L24ad4 [$80024ad4]
80024AC4	ori    v0, zero, $0001
80024AC8	sb     v0, $02e0(gp)
80024ACC	j      L24adc [$80024adc]
80024AD0	addu   s0, zero, zero

L24ad4:	; 80024AD4
80024AD4	sb     zero, $02e0(gp)
80024AD8	addu   s0, zero, zero

L24adc:	; 80024ADC
80024ADC	ori    s1, zero, $00ff

loop24ae0:	; 80024AE0
80024AE0	andi   a0, s0, $ffff
80024AE4	lui    at, $800a
80024AE8	addiu  at, at, $cbdc (=-$3424)
80024AEC	addu   at, at, a0
80024AF0	lbu    v0, $0000(at)
80024AF4	nop
80024AF8	beq    v0, s1, L24b18 [$80024b18]
80024AFC	nop
80024B00	jal    system_init_player_weapon_stat [$80020058]
80024B04	nop
80024B08	jal    system_init_player_materia [$8001786c]
80024B0C	andi   a0, s0, $00ff
80024B10	jal    system_calculate_total_lure_gil_preemptive_value [$80017678]
80024B14	nop

L24b18:	; 80024B18
80024B18	addiu  s0, s0, $0001
80024B1C	andi   v0, s0, $ffff
80024B20	sltiu  v0, v0, $0003
80024B24	bne    v0, zero, loop24ae0 [$80024ae0]
80024B28	nop
80024B2C	lui    a0, $8007
80024B30	addiu  a0, a0, $06a4
80024B34	lui    a1, $8007
80024B38	addiu  a1, a1, $075c
80024B3C	jal    func21044 [$80021044]
80024B40	addu   s0, zero, zero
[GP + 164] = h(64);
[GP + 2b0] = h(-3);

80024B54	jal    func25cd4 [$80025cd4]
80024B58	addiu  a0, sp, $0020
80024B5C	lui    a0, $8007
80024B60	addiu  a0, a0, $56f8
80024B64	jal    func25c94 [$80025c94]
80024B68	addiu  s4, zero, $ffff (=-$1)
80024B6C	sw     zero, $027c(gp)
80024B70	jal    func2368c [$8002368c]
80024B74	nop

80024B80	addiu  s1, sp, $0720
80024B8C	sw     zero, $0214(gp)

L24b90:	; 80024B90
    func1cb48; // tutorial check here

    [80062f24] = w(80077f64 + w[GP + 214] * 3400);

    A0 = 80069844 + w[GP + 214] * 50;
    [GP + 160] = w(A0);
    A1 = 14;
    80024BE8	jal    func4418c [$8004418c]

    [GP + 280] = w(w[GP + 160]);

    if (w[80062fa0] != 0)
    {
        if (w[GP + 27c] != S4)
        {
            if( S0 & 0010 )
            {
                A0 = 28;
                A1 = ce;
                A2 = 80049320; // text "Tutorial"
                A3 = 4;
                func26f44; // text

                A0 = 80049320;
                system_get_single_string_width;

                [S1 + 0] = h(20); // x
                [S1 + 2] = h(c8); // y
                [S1 + 4] = h(V0 + 10); // width
                [S1 + 6] = h(18); // height

                A0 = S1;
                func1e040;
            }
        }
    }

    func1f710; // draw tutorial text

    V0 = w[GP + b4];

    if (V0 == 2 || V0 == 4 || V0 == 5)
    {
        V0 = w[GP + 8c] * 4;
    }
    else
    {
        V0 = w[GP + 90] * 4;
    }

    V0 = 800493fc + V0;
    A9 = S0;
    80024CB4	jalr   v0 ra // call menu draw function, at least config here

D43A0280 // 0
800E1D80 // 1 item
90041D80 // 2 magic
2C6C1D80 // 3 materia
D00B1D80
7C161D80
C4001D80
2C041D80
0C081D80 // 8 config
940E1D80
B0061D80
50021D80
C4001D80
800E1D80
800E1D80
D00B1D80
800E1D80
800E1D80
800E1D80
800E1D80
800E1D80

    A0 = 0;
    80024CBC	jal    func43dd8 [$80043dd8]

    A0 = 0;
    80024CC4	jal    func3cedc [$8003cedc]

    80024CCC	lw     v0, $0214(gp)
    80024CD0	nop
    80024CD4	sll    a0, v0, $02
    80024CD8	addu   a0, a0, v0
    80024CDC	sll    a0, a0, $02
    80024CE0	lui    v0, $8007
    80024CE4	addiu  v0, v0, $075c
    80024CE8	jal    func444ac [$800444ac]
    80024CEC	addu   a0, a0, v0
    80024CF0	lw     v0, $0214(gp)
    80024CF4	nop
    80024CF8	sll    a0, v0, $01
    80024CFC	addu   a0, a0, v0
    80024D00	sll    a0, a0, $03
    80024D04	subu   a0, a0, v0
    80024D08	sll    a0, a0, $02
    80024D0C	lui    v0, $8007
    80024D10	addiu  v0, v0, $06a4
    80024D14	jal    func443b0 [$800443b0]
    80024D18	addu   a0, a0, v0
    80024D1C	lw     a0, $0160(gp)
    80024D20	jal    func4433c [$8004433c]
    80024D24	addiu  s0, s0, $0001
    80024D28	lw     v0, $0214(gp)
    80024D2C	lw     v1, $027c(gp)
    80024D30	xori   v0, v0, $0001
    80024D34	sw     v0, $0214(gp)
80024D38	bne    v1, s4, L24b90 [$80024b90]



80024D40	jal    func25c94 [$80025c94]
80024D44	addiu  a0, sp, $0020
80024D48	jal    func24a04 [$80024a04]
80024D4C	nop
80024D50	lui    at, $8006
80024D54	sw     zero, $2fa0(at)
80024D58	jal    func3cedc [$8003cedc]
80024D5C	ori    a0, zero, $0004
return 0;
////////////////////////////////



////////////////////////////////
// system_menu_sound
[8009a000] = w(30);
[8009a004] = w(A0 & ffff);
[8009a008] = w(A0 & ffff);
system_execute_AKAO;
////////////////////////////////



////////////////////////////////
// func26408
[8009a000] = w(30);
[8009a004] = w(A0 & ffff);
[8009a008] = w(A0 & ffff);
system_execute_AKAO;
////////////////////////////////



////////////////////////////////
// func211c4
A0 = w[80048f60 + A0 * 8 + 0];
A1 = w[80048f60 + A0 * 8 + 4];
A2 = w[GP + a8];
A3 = 0;
800211EC	jal    func33e34 [$80033e34]

800211F4	jal    func34b44 [$80034b44]
////////////////////////////////



////////////////////////////////
// func2120c
V0 = w[GP + 90];
[GP + 8c] = w(V0);
[GP + 90] = w(A0);

if( A0 != 0 )
{
    if( ( V0 - 3 >= 2 ) || ( A0 - 3 >= 2 ) )
    {
        80021240	jal    func211c4 [$800211c4]
    }
}
////////////////////////////////



////////////////////////////////
// func2305c
V1 = w[GP + 250];
[GP + b4] = w(A0);
[GP + 250] = w(A1 - 1);
[GP + 1c8] = w(V1);

if( A0 == 2 )
{
    [GP + 1dc] = w(10);
}
else if( A0 == 4 )
{
    [GP + 1dc] = w(10);
}
else if( A0 == 5 )
{
    [8009a0d3] = b(V1);
    [GP + 188] = w(0);
    [GP + 1dc] = w(10);
}
////////////////////////////////



////////////////////////////////
// func26090
loop26098:	; 80026098
    80026098	jal    func34b44 [$80034b44]
800260A0	bne    v0, zero, loop26098 [$80026098]

A0 = 7;
800260A8	jal    func211c4 [$800211c4]

loop260b0:	; 800260B0
    800260B0	jal    func34b44 [$80034b44]
800260B8	bne    v0, zero, loop260b0 [$800260b0]

800260C0	jal    func1d11a8 [$801d11a8]

[GP + 24c] = w(0);
////////////////////////////////



////////////////////////////////
// func264a8
A1 = A0;

if( h[A1 + 8] != 0 )
{
    if( h[A1 + 8] == 1 )
    {
        [A1 + f] = b(bu[A1 + f] + 1);

        if( ( bu[A1 + f] << 18 ) == 0 )
        {
            [A1 + 8] = h(0);
            [A1 + f] = b(0);
        }
    }
    else if( h[A1 + 8] == 2 )
    {
        [A1 + f] = b(b[A1 + f] - 1);
        if( b[A1 + f] == -4 )
        {
            [A1 + 2] = h(hu[A1 + 2] + 1);
            [A1 + 8] = h(0);
            [A1 + f] = b(0);
        }
    }
}



V1 = hu[80062d7e];

if( V1 & 1000 ) // up
{
    [A1 + b] = b(bu[A1 + b] - 1);

    if( b[A1 + 11] != 0 )
    {
        if( b[A1 + 11] >= 0 && b[A1 + 11] < 3 )
        {
            if( b[A1 + b] < 0 )
            {
                [A1 + b] = b(bu[A1 + d] - 1);
            }

            A0 = 1;
            system_menu_sound;
        }
    }
    else
    {
        if( b[A1 + b] < 0 )
        {
            [A1 + b] = b(0);

            if( h[A1 + 2] > 0 )
            {
                [A1 + 2] = h(h[A1 + 2] - 1);
                [A1 + f] = b(-3);
                [A1 + 8] = h(1);
                A0 = 1;
                system_menu_sound;
            }
        }
        else
        {
            A0 = 1;
            system_menu_sound;
        }
    }
}
else if( V1 & 4000 ) // down
{
    [A1 + b] = b(bu[A1 + b] + 1);

    if( b[A1 + 11] != 0 )
    {
        if( b[A1 + 11] >= 0 && b[A1 + 11] < 3 )
        {
            if( b[A1 + b] >= b[A1 + d] )
            {
                [A1 + b] = b(0);
            }

            A0 = 1;
            system_menu_sound;
        }
    }
    else
    {
        if( b[A1 + b] >= b[A1 + d] )
        {
            [A1 + b] = b(b[A1 + d] - 1);

            if( h[A1 + 2] < h[A1 + 6] - b[A1 + d] )
            {
                [A1 + f] = b(-1)
                [A1 + 8] = h(2);

                A0 = 1;
                system_menu_sound;
            }
        }
        else
        {
            A0 = 1;
            system_menu_sound;
        }
    }
}
else if( V1 & 8000 == 0 ) // left
{
    if( b[A1 + 10] == 0 )
    {
        [A1 + a] = b(bu[A1 + a] - 1);

        if( b[A1 + a] < 0 )
        {
            [A1 + a] = b(0);
        }

        A0 = 1;
        system_menu_sound;
    }
    else if( b[A1 + 10] == 1 )
    {
        [A1 + a] = b(bu[A1 + a] - 1);
        if( bu[A1 + a] < 0 )
        {
            [A1 + a] = b(bu[A1 + c] - 1);
        }

        A0 = 1;
        system_menu_sound;
    }
    else if( b[A1 + 10] == 2 )
    {
        if( ( hu[A1 + a] != 0 ) || ( h[A1 + 2] != 0 ) )
        {
            [A1 + a] = b(bu[A1 + a] - 1);
            if( bu[A1 + a] < 0 )
            {
                [A1 + b] = b(bu[A1 + b] - 1);
                [A1 + a] = b(bu[A1 + c] - 1);

                if( bu[A1 + b] < 0 )
                {
                    [A1 + b] = b(0);
                    V0 = h[A1 + 2];
                    if( V0 > 0 )
                    {
                        [A1 + 2] = h(V0 - 1);
                        [A1 + f] = b(-3);
                        [A1 + 8] = h(1);
                    }
                }
            }

            A0 = 1;
            system_menu_sound;
        }
    }
}
else if( V1 & 2000 ) // right
{
    if( b[A1 + 10] == 0 )
    {
        [A1 + a] = b(b[A1 + a] + 1);

        if( b[A1 + a] >= b[A1 + c] )
        {
            [A1 + a] = b(b[A1 + c] - 1);
        }
        else
        {
            A0 = 1;
            system_menu_sound;
        }
    }
    else if( b[A1 + 10] == 1 )
    {
        [A1 + a] = b(b[A1 + a] + 1);

        if( b[A1 + a] >= b[A1 + c] )
        {
            [A1 + a] = b(0);
        }

        A0 = 1;
        system_menu_sound;
    }
    else if( b[A1 + 10] == 2 )
    {
        if( ( b[A1 + a] != b[A1 + c] - 1 ) || ( b[A1 + b] != b[A1 + d] - 1 ) || ( h[A1 + 2] != h[A1 + 6] - b[A1 + d] ) )
        {
            [A1 + a] = b(b[A1 + a] + 1);

            if( b[A1 + a] >= b[A1 + c] )
            {
                [A1 + a] = b(0);
                [A1 + b] = b(b[A1 + b] + 1);

                if( b[A1 + b] >= b[A1 + d] )
                {
                    [A1 + b] = b(b[A1 + d] - 1);

                    if( h[A1 + 2] < h[A1 + 6] - b[A1 + d] )
                    {
                        [A1 + f] = b(-1);
                        [A1 + 8] = h(2);
                    }
                }
            }
            A0 = 1;
            system_menu_sound;
        }
    }
}
else if( V1 & 0008 ) // R1
{
    [A1 + 2] = h(h[A1 + 2] + b[A1 + d]);

    if( h[A1 + 6] - b[A1 + d] < h[A1 + 2] )
    {
        [A1 + 2] = h(h[A1 + 6] - b[A1 + d]);
    }
    else
    {
        A0 = 1;
        system_menu_sound;
    }
}
else if( V1 & 0004 ) // L1
{
    [A1 + 2] = h(hu[A1 + 2] - b[A1 + d]);

    if( hu[A1 + 2] < 0 )
    {
        [A1 + 2] = h(0);
    }
    else
    {
        A0 = 1;
        system_menu_sound;
    }
}
////////////////////////////////



////////////////////////////////
// func23ad4
[SP + 478] = w(A0);

if( w[GP + 24c] != 0 )
{
    func26090;
}



[GP + 208] = h(hu[8009c6e4 + 0bc0]); // menu visibility mask
A1 = hu[8009c6e4 + 0bc2]; // menu locking mask

[GP + 20c] = h(A1);

if( bu[8009c6e4 + 0e13] & 1 ) // little cloud event?
{
    [GP + 20c] = h(A1 | 0041);
}



if( w[GP + b4] == 1 && w[GP + 27c] == 1 )
{
    A0 = 8009a0c8 + w[GP + 220] * 12;
    func264a8;



    if( w[GP + 220] == 0 )
    {
        if( ( hu[80062d7c] & 0020 ) && ( ( hu[GP + 208] >> b[8009a0c8 + b] ) & 1 ) && ( ( ( hu[GP + 208] >> hu[GP + 20c] ) & 1 ) == 0 ) ) // confirm and allowed to do it
        {
            if( b[8009a0c8 + b] != 5 )
            {
                A0 = 1;
                system_menu_sound;

                V0 = b[8009a0c8 + b];
                if( V0 == 0 || V0 == 7 || V0 == 8 || V0 == 9 ) // item config phs save menu
                {
                    A0 = 2;
                    V0 = b[8009a0c8 + b];
                    A1 = bu[80049450 + V0];
                    func2305c;

                    V0 = b[8009a0c8 + b];
                    A0 = bu[80049450 + V0];
                    func2120c;

                    if( b[8009a0c8 + b] == 8 ) // phs menu
                    {
                        A0 = 1c3;
                        system_menu_sound;
                    }
                }
                else if( V0 == 1 || V0 == 2 || V0 == 3 || V0 == 4 || V0 == 6 ) // magic materia equip status limit menu
                {
                    [GP + 220] = w(1);
                }
            }
            else // order menu
            {
                [GP + 220] = w(2);
                [GP + 23c] = w(0);
            }
        }
        else
        {
            if( hu[80062d7c] & 0040 ) // cancel
            {
                A0 = 4;
                system_menu_sound;

                [GP + 2b0] = h(3);
                [GP + 27c] = w(2);
            }
        }
    }
    else if( w[GP + 220] == 1 )
    {
        if( hu[80062d7c] & 0020 == 0 )
        {
            if( hu[80062d7c] & 0040 != 0 ) // cancel
            {
                A0 = 4;
                system_menu_sound;

                [GP + 220] = w(0);
            }
        }
        else // confirm
        {
            V0 = b[8009a0c8 + 12 + b];

            if(  bu[8009c6e4 + 4f8 + V0] == ff ) // party member slot
            {
                A0 = 3;
                system_menu_sound;
            }
            else
            {
                A0 = 1;
                system_menu_sound;

                V0 = b[8009a0c8 + b];
                A1 = bu[80049450 + V0];
                A0 = 2;
                func2305c;

                V0 = b[8009a0c8 + b];
                A0 = bu[80049450 + V0];
                80023DE8	jal    func2120c [$8002120c]

                [GP + 220] = w(0);
                [GP + 228] = w(b[8009a0e5]);
            }
        }
    }
    else if( w[GP + 220] == 2 )
    {
        if( hu[80062d7c] & 0020 == 0 )
        {
            if( hu[80062d7c] & 0040 != 0 ) // cancel
            A0 = 4;
            system_menu_sound;

            if( w[GP + 23c] != 0 )
            {
                [GP + 23c] = w(w[GP + 23c] - 1);
            }
            else
            {
                [GP + 220] = w(0);
            }
        }
        else // confirm
        {
            if( w[GP + 23c] == 0 )
            {
                A0 = 1;
                system_menu_sound;

                [GP + 23c] = w(1);
                [GP + 2d8] = w(b[8009a0c8 + 2 * 12 + b]);
            }
            else
            {
                [GP + 23c] = w(0);

                if( w[GP + 2d8] == b[8009a0c8 + 2 * 12 + b] )
                {
                    V1 = w[GP + 2d8];
                    V1 = bu[8009c6e4 + 04f8 + V1 ];
                    if( V1 != ff )
                    {
                        V0 = w[800491d0 + V1 * 4];
                        [8009c6e4 + 54 + V0 * 84 + 20] = b(bu[8009c6e4 + 54 + V0 * 84 + 20] ^ 1); // char order

                        A0 = 1;
                        system_menu_sound;
                    }
                }
                else
                {
                    A0 = 1;
                    system_menu_sound;

                    V1 = b[8009a0c8 + 2 * 12 + b];
                    V0 = 8009c6e4 + 04f8 + w[GP + 2d8];
                    [V0] = b(bu[8009cbdc + V1]);
                    A0 = bu[V0];
                    V0 = b[8009a0c8 + 2 * 12 + b];
                    [8009cbdc + V0] = b(A0);

                    A3 = SP + 38;
                    A2 = 8009d84c + b[8009a0c8 + 2 * 12 + b] * 440;
                    T0 = A2 + 440;

                    loop23f64:	; 80023F64
                        [A3 + 0] = w(w[A2 + 0]);
                        [A3 + 4] = w(w[A2 + 4]);
                        [A3 + 8] = w(w[A2 + 8]);
                        [A3 + c] = w(w[A2 + c]);
                        A2 = A2 + 10;
                        A3 = A3 + 10;
                    80023F88	bne    a2, t0, loop23f64 [$80023f64]

                    V1 = b[8009a0c8 + 2 * 12 + b];
                    A0 = 8009d84c;
                    V0 = V1 * 440;
                    V1 = w[GP + 2d8];
                    A3 = V0 + A0;
                    V0 = V1 * 440;
                    A2 = V0 + A0;
                    T0 = A2 + 440;

                    loop23fc8:	; 80023FC8
                        [A3 + 0] = w(w[A2 + 0]);
                        [A3 + 4] = w(w[A2 + 4]);
                        [A3 + 8] = w(w[A2 + 8]);
                        [A3 + c] = w(w[A2 + c]);
                        A2 = A2 + 10;
                        A3 = A3 + 10;
                    80023FEC	bne    a2, t0, loop23fc8 [$80023fc8]

                    A3 = SP + 38;
                    T0 = SP + 478;
                    V0 = w[GP + 2d8];
                    A0 = 8009d84c;
                    V1 = V0 * 440;
                    A2 = V1 + A0;

                    loop24018:	; 80024018
                        [A2 + 0] = w(w[A3 + 0]);
                        [A2 + 4] = w(w[A3 + 4]);
                        [A2 + 8] = w(w[A3 + 8]);
                        [A2 + c] = w(w[A3 + c]);
                        A2 = A2 + 10;
                        A3 = A3 + 10;
                    8002403C	bne    a3, t0, loop24018 [$80024018]

                    S2 = SP + 30;
                    A0 = SP + 30;
                    S3 = 100;
                    S5 = 8009a0c8 + 2 * 12 + b;
                    S0 = 1;
                    [SP + 30] = h(S3);
                    [SP + 34] = h(S3);
                    [SP + 32] = h(b[S5] + 1ed);
                    A1 = w[GP + 2d8];
                    S6 = 800756f8;
                    [SP + 36] = h(S0);
                    A1 = S6 + A1 * 200;
                    func44064;

                    A1 = b[S5];
                    V0 = w[GP + 2d8];
                    A0 = SP + 30;
                    [SP + 30] = h(S3);
                    [SP + 34] = h(S3);
                    [SP + 36] = h(S0);
                    A1 = S6 + A1 * 200;
                    V0 = V0 + 1ed;
                    [SP + 32] = h(V0);
                    func44064

                    800240C0	addu   a0, s2, zero
                    800240C4	ori    a1, zero, $0340
                    800240C8	ori    a2, zero, $0100
                    800240CC	ori    s4, zero, $03c0
                    800240D0	ori    s1, zero, $0018
                    800240D4	lw     v1, $02d8(gp)
                    800240D8	ori    s0, zero, $0030
                    800240DC	sh     s4, $0030(sp)
                    800240E0	sh     s1, $0034(sp)
                    800240E4	sh     s0, $0036(sp)
                    800240E8	sll    v0, v1, $01
                    800240EC	addu   v0, v0, v1
                    800240F0	sll    v0, v0, $04
                    800240F4	addiu  v0, v0, $0138
                    800240FC	sh     v0, $0032(sp)
                    800240F8	jal    func440c8 [$800440c8]

                    A0 = 0;
                    80024100	jal    func43dd8 [$80043dd8]

                    A0 = S2;
                    A1 = 3c0;
                    [SP + 30] = h(S4);
                    [SP + 34] = h(S1);
                    [SP + 36] = h(S0);
                    A2 = w[GP + 2d8] * 30 + 138;
                    [SP + 32] = h(b[S5] * 30 + 138);
                    80024144	jal    func440c8 [$800440c8]

                    A0 = 0;
                    8002414C	jal    func43dd8 [$80043dd8]

                    A0 = S2;
                    A1 = 3c0;
                    V1 = b[S5];
                    [SP + 30] = h(340);
                    [SP + 32] = h(S3);
                    [SP + 34] = h(S1);
                    [SP + 36] = h(S0);
                    A2 = V1 * 30 + 138;
                    80024180	jal    func440c8 [$800440c8]

                    A0 = 0;
                    80024188	jal    func43dd8 [$80043dd8]

                    A0 = S6;
                    80024190	jal    func25c94 [$80025c94]

                    A0 = 0;
                    80024198	jal    func43dd8 [$80043dd8]
                }
            }
        }
    }
}



if( w[GP + b4] == 1 )
{
    if (w[GP + 27c] == 1)
    {
        if( w[GP + 220] == 0 )
        {
            A0 = 10b;
            A1 = b[8009a0c8 + b] * c + d;
            func1eb2c; // cursor
        }
        else if( w[GP + 220] == 1 )
        {
            if( w[SP + 478] & 2 )
            {
                A0 = 10b;
                A1 = b[8009a0c8 + b] * c + d;
                func1eb2c; // cursor
            }

            V1 = w[GP + 220];
            A0 = 0;
            A1 = b[8009a0c8 + V1 * 24 + b] * 3c + 2f;
            func1eb2c; // cursor
        }
        else if( w[GP + 220] == 2 )
        {
            if( w[SP + 478] & 2 )
            {
                if( w[GP + 23c] != 0 )
                {
                    A0 = -4;
                    A1 = w[GP + 2d8] * 3c + 2b;
                    func1eb2c; // cursor
                }

                A0 = 10b;
                A1 = b[8009a0c8 + b] * c + d;
                func1eb2c; // cursor
            }

            V1 = w[GP + 220];
            A0 = 0;
            A1 = b[8009a0d3 + V1 * 24] * 3c + 2f;
            func1eb2c; // cursor
        }
    }
}



80024310	addiu  s2, sp, $0030
80024314	addu   a1, s2, zero
80024318	lw     v1, $0214(gp)
8002431C	ori    v0, zero, $0005
80024320	sh     v0, $0032(sp)
80024324	ori    v0, zero, $016c
80024328	sh     v0, $0034(sp)
8002432C	ori    v0, zero, $00db
80024330	sh     v0, $0036(sp)
80024334	lui    v0, $8007
80024338	addiu  v0, v0, $06a4
8002433C	sh     zero, $0030(sp)
80024340	sll    a0, v1, $01
80024344	addu   a0, a0, v1
80024348	sll    a0, a0, $03
8002434C	subu   a0, a0, v1
80024350	sll    a0, a0, $02
80024354	jal    func26a94 [$80026a94]
80024358	addu   a0, a0, v0

A0 = w[GP + 214];
func230c4; // draw menu



// block of fieldname
A0 = c0;
A1 = 11c - h[GP + 164] * 4.2f + 6;
A2 = 8009d5f0; // text field name
A3 = 7;
func26f44;

[SP + 28] = h(b8);
[SP + 2a] = h(11c - h[GP + 164] * 4.2f);
[SP + 2c] = h(b4);
[SP + 2e] = h(18);

A0 = SP + 28;
func1e040;



// block of time/gil
S3 = 1ce - h[GP + 164] * 9.2f;

A0 = S3 + 4;
A1 = aa;
A2 = 800492f0; // text "Time"
A3 = 7;
func26f44;

A0 = S3 + 5;
A1 = b8;
A2 = 800492fc; // text "Gil"
A3 = 7;
func26f44;

A0 = w[8009c6e4 + 0b80];
system_get_hours_from_seconds;

A0 = S3 + 1f;
A1 = ac;
A2 = V0;
A3 = 2;
A4 = 7;
func28e00;

A0 = S3 + 2c;
A1 = ad;
A2 = d5;
if (w[8009c6e4 + 0b88] < 7fff)
{
    A3 = 0;
}
else
{
    A3 = 7;
}
system_draw_single_menu_font_character;

A0 = w[8009d264];
system_get_minutes_from_seconds;

A0 = S3 + 32;
A1 = ac;
A2 = V0; // minutes
A3 = 2;
A4 = 7;
func29114;


A0 = S3 + 3e;
A1 = ad;
A2 = d5;
A3 = 7;
system_draw_single_menu_font_character;

A0 = w[8009d264];
system_get_seconds_from_seconds;

A0 = S3 + 43;
A1 = ac;
A2 = V0; // seconds
A3 = 2;
A4 = 7;
func29114;

A0 = S3 + b;
A1 = ba;
A2 = w[8009c6e4 + 0b7c]; // gil
A3 = a;
A4 = 7;
func28e00;

A0 = 0;
A1 = 1;
A2 = 7f;
A3 = SP + 30;
[SP + 30] = h(0);
[SP + 32] = h(0);
[SP + 34] = h(100);
[SP + 36] = h(100);
func26a34;


[SP + 28] = h(S3);
[SP + 2a] = h(a4);
[SP + 2c] = h(56);
[SP + 2e] = h(24);

A0 = SP + 28
func1e040;



S3 = h[GP + 164] * 9.2 - b8;

y_pos = 11;
S2 = 0;
L245bc:	; 800245BC
    V0 = bu[8009cdbc + S2];

    if (V0 != ff)
    {
        S5 = bu[800491d0 + V0 * 4];
        S1 = S5 * 84;

        A0 = S3 + 66;
        A1 = y_pos + e;
        A2 = S2;
        func20b68;

        A0 = S3 + ((bu[8009c6e4 + 0054 + S1 + 20] ^ 1) & 1) * 18 + 16; // char order
        A1 = y_pos + c;
        A2 = 30;
        A3 = 30;
        A4 = 0;
        A5 = S2 * 30 + 38;
        A6 = 30;
        A7 = 30;
        A8 = S2 + d;
        A9 = 0;
        80024668	jal    func1cf3c [$8001cf3c]



        A0 = S3 + cb;
        A1 = y_pos + 1d;
        A2 = bu[8009c6e4 + 0054 + S1 + 21]; // level progress bar
        A3 = 6;
        A4 = 80;
        A5 = 20;
        A6 = 20;
        func285ac;

        V0 = bu[8009c6e4 + 0054 + S1 + f]; // limit progress bar
        if (V0 == ff)
        {
            800246C0	lw     t3, $0478(sp)
            800246C4	nop
            800246C8	sra    v0, t3, $01
            800246CC	andi   v0, v0, $0007
            800246D0	sll    v1, v0, $01
            800246D4	addu   v1, v1, v0
            T2 = bu[8004948c + V1];
            800246E8	lui    at, $8005
            800246EC	addiu  at, at, $948d (=-$6b73)
            800246F0	addu   at, at, v1
            800246F4	lbu    t1, $0000(at)
            800246F8	lui    at, $8005
            800246FC	addiu  at, at, $948e (=-$6b72)
            80024700	addu   at, at, v1
            80024704	lbu    t0, $0000(at)
        }
        else
        {
            V1 = b[8009c757 + S1];
            if (V1 & 10)
            {
                80024730	lui    t2, $8005
                80024734	lbu    t2, $948c(t2)
                80024738	lui    t1, $8005
                8002473C	lbu    t1, $948d(t1)
                80024740	lui    t0, $8005
                80024744	lbu    t0, $948e(t0)
            }
            else if (V1 & 20)
            {
                80024758	lui    t2, $8005
                8002475C	lbu    t2, $9492(t2)
                80024760	lui    t1, $8005
                80024764	lbu    t1, $9493(t1)
                80024768	lui    t0, $8005
                8002476C	lbu    t0, $9494(t0)
            }
            else
            {
                T2 = 80;
                T1 = 20;
                T0 = 50;
            }
        }

        80024780	sll    v0, s5, $05
        80024784	addu   v0, v0, s5
        80024788	sll    v0, v0, $02
        V0 = b[8009c747 + V0] * 3d;
        A1 = y_pos + 32;
        A2 = V0 >> 8;
        A0 = S3 + cb;
        A3 = 6;
        A4 = T2;
        A5 = T1;
        A6 = T0;
        func285ac;

        S0 = S3 + ca;
        A0 = S0; // x
        A1 = y_pos + 1c; // y
        A2 = 88; // tex x
        A3 = 8; // tex y
        A4 = 40; // width
        A5 = 8; // height
        A6 = 7; // colour
        A7 = 0;
        80024814	jal    func28ca0 [$80028ca0]

        8002481C	addu   a0, s0, zero
        A1 = y_pos + 31;
        8002482C	ori    a2, zero, $0088
        80024830	ori    a3, zero, $0008
        80024834	ori    t3, zero, $0040
        80024838	sw     t3, $0010(sp)
        8002483C	ori    t3, zero, $0008
        80024840	sw     t3, $0014(sp)
        80024844	ori    t3, zero, $0007
        80024848	sw     t3, $0018(sp)
        8002484C	jal    func28ca0 [$80028ca0]
        80024850	sw     zero, $001c(sp)

        A0 = S3 + fa;
        80024858	lui    t3, $8005
        8002485C	addiu  t3, t3, $91d0 (=-$6e30)
        80024860	lui    at, $800a
        80024864	addiu  at, at, $cbdc (=-$3424)
        80024868	addu   at, at, s2
        8002486C	lbu    v0, $0000(at)
        A1 = y_pos + 28;
        80024874	sll    v0, v0, $02
        80024878	addu   v0, v0, t3
        8002487C	lw     v1, $0000(v0)

        A2 = bu[8009c6e4 + 0054 + V1 * 84 + e]; // current limit level
        A3 = 1;
        A4 = 7;
        func28e00;




        800248AC	addu   a0, zero, zero
        800248B0	ori    a1, zero, $0001
        800248B4	ori    a2, zero, $003f
        800248B8	addiu  a3, sp, $0030
        800248BC	ori    v0, zero, $0100
        800248C0	sh     zero, $0030(sp)
        800248C4	sh     zero, $0032(sp)
        800248C8	sh     v0, $0034(sp)
        800248D0	sh     v0, $0036(sp)
        800248CC	jal    func26a34 [$80026a34]


        A0 = S3 + ba;
        A1 = y_pos + 11;
        A2 = 80049308; // text "next level"
        A3 = 7;
        func26f44;

        A0 = S3 + ba;
        A1 = y_pos + 26;
        A2 = 80049314; // text "Limit level"
        A3 = 7;
        func26f44;
    }

    y_pos = y_pos + 3c;

    80024914	addiu  s2, s2, $0001
    8002491C	slti   v0, s2, $0003
80024924	bne    v0, zero, L245bc [$800245bc]

[SP + 28] = h(S3);
[SP + 2a] = h(11);
[SP + 2c] = h(12c);
[SP + 2e] = h(be);

A0 = SP + 28;
func1e040;

80024950	lw     v0, $027c(gp)
80024954	nop
80024958	beq    v0, zero, L24970 [$80024970]
8002495C	ori    s0, zero, $0002
80024960	beq    v0, s0, L249a4 [$800249a4]
80024964	nop
80024968	j      L249d0 [$800249d0]
8002496C	nop

L24970:	; 80024970
V0 = h[GP + 164];
V1 = h[GP + 2b0];
[GP + 164] = h(V0 + V1);

8002498C	slti   v0, v0, $0014
80024990	beq    v0, zero, L249d0 [$800249d0]
80024994	ori    v0, zero, $0014
80024998	sh     v0, $0164(gp)
8002499C	j      L249cc [$800249cc]
800249A0	ori    v0, zero, $0001

L249a4:	; 800249A4
800249A4	lhu    v0, $0164(gp)
800249A8	lhu    v1, $02b0(gp)
800249AC	nop
800249B0	addu   v0, v0, v1
800249B4	sh     v0, $0164(gp)
800249B8	sll    v0, v0, $10
800249BC	sra    v0, v0, $10
800249C0	slti   v0, v0, $0065
800249C4	bne    v0, zero, L249d0 [$800249d0]
800249C8	addiu  v0, zero, $ffff (=-$1)

L249cc:	; 800249CC
800249CC	sw     v0, $027c(gp)

L249d0:	; 800249D0
////////////////////////////////



////////////////////////////////
// system_get_hours_from_seconds
if (A0 > 57e3f)
{
    A0 = 57e3f;
}

return (A0 / w[80049474]) * a + (A0 % w[80049474]) / w[80049478];
////////////////////////////////



////////////////////////////////
// system_get_minutes_from_seconds
if (A0 > 57e3f)
{
    A0 = 57e3f;
}

A0 = A0 % w[80049474];
A0 = A0 % w[80049478];

return (A0 / w[8004947c]) * a + (A0 % w[8004947c]) / w[80049480];
////////////////////////////////



////////////////////////////////
// system_get_seconds_from_seconds
if (A0 > 57e3f)
{
    A0 = 57e3f;
}

A0 = A0 % w[80049474];
A0 = A0 % w[80049478];
A0 = A0 % w[8004947c];
A0 = A0 % w[80049480];

return (A0 / w[80049484]) * a + (A0 % w[80049484]) / w[80049488];
////////////////////////////////



////////////////////////////////
// func230c4
800230CC	addu   s3, a0, zero
800230E0	jal    func34b44 [$80034b44]

800230E8	sll    a0, s3, $01
800230EC	addu   a0, a0, s3
800230F0	sll    a0, a0, $03
800230F4	subu   a0, a0, s3
800230F8	sll    a0, a0, $02
800230FC	lui    v1, $8007
80023100	addiu  v1, v1, $06a4
80023104	addu   a0, a0, v1
80023108	addiu  a1, sp, $0018
8002310C	ori    v1, zero, $0005
80023110	sh     v1, $001a(sp)
80023114	ori    v1, zero, $016c
80023118	sh     v1, $001c(sp)
8002311C	ori    v1, zero, $00db
80023120	addu   s0, v0, zero
80023124	sh     zero, $0018(sp)
80023128	jal    func26a94 [$80026a94]
8002312C	sh     v1, $001e(sp)
V1 = w[GP + b4];

80023138	sltiu  v0, v1, $0007
S4 = 0;
8002313C	beq    v0, zero, L234c8 [$800234c8]

80023144	sll    v0, v1, $02
80023148	lui    at, $8001
8002314C	addiu  at, at, $0344
80023150	addu   at, at, v0
80023154	lw     v0, $0000(at)
80023158	nop
8002315C	jr     v0 
80023160	nop

80023164	lw     v0, $01dc(gp)
80023168	nop
8002316C	beq    v0, zero, L23180 [$80023180]
80023170	addiu  v0, v0, $ffff (=-$1)
80023174	sw     v0, $01dc(gp)
80023178	j      L231b8 [$800231b8]
8002317C	nop

L23180:	; 80023180
80023180	bne    s0, zero, L231b8 [$800231b8]
80023184	nop
80023188	lw     v0, $0090(gp)
8002318C	nop
80023190	sll    v0, v0, $02
80023194	lui    at, $8005
80023198	addiu  at, at, $93a8 (=-$6c58)
8002319C	addu   at, at, v0
800231A0	lw     v0, $0000(at)
800231A4	nop
800231A8	jalr   v0 ra
800231AC	addu   a0, zero, zero
[GP + b4] = w(3);

L231b8:	; 800231B8
800231B8	lw     v1, $01dc(gp)
800231BC	nop
800231C0	sll    v0, v1, $01
800231C4	addu   v0, v0, v1
800231C8	lw     v1, $0250(gp)
800231CC	sll    v0, v0, $02
800231D0	mult   v1, v0
800231D4	mflo   a1
800231D8	bgez   a1, L231e4 [$800231e4]
800231DC	nop
800231E0	addiu  a1, a1, $000f

L231e4:	; 800231E4
800231E4	sra    a1, a1, $04
A0 = 126;
A1 = A1 + b;
A2 = 80049248 + V1 * c; // text "Item"
A3 = 7;
func26f44;

80023210	lw     v1, $01dc(gp)
80023214	nop
80023218	sll    v0, v1, $03
8002321C	subu   v0, v0, v1
80023220	sll    v0, v0, $02
80023224	subu   v0, v0, v1
80023228	sll    v0, v0, $02
8002322C	bgez   v0, L23238 [$80023238]
80023230	nop
80023234	addiu  v0, v0, $000f

L23238:	; 80023238
80023238	sra    v0, v0, $04
8002323C	addiu  v0, v0, $0018
80023240	sw     v0, $00ac(gp)
80023244	j      L234c8 [$800234c8]
80023248	nop
8002324C	lw     v0, $01dc(gp)
80023250	nop
80023254	beq    v0, zero, L23268 [$80023268]
80023258	addiu  v0, v0, $ffff (=-$1)
8002325C	sw     v0, $01dc(gp)
80023260	j      L233d4 [$800233d4]

L23268:	; 80023268
80023268	lw     v0, $0090(gp)
8002326C	nop
80023270	sll    v0, v0, $02
80023274	lui    at, $8005
80023278	addiu  at, at, $93a8 (=-$6c58)
8002327C	addu   at, at, v0
80023280	lw     v1, $0000(at)
80023284	ori    v0, zero, $0003
80023288	sw     v0, $00b4(gp)
8002328C	jalr   v1 ra
80023290	nop
80023294	j      L233d4 [$800233d4]

8002329C	lw     v1, $01dc(gp)
800232A0	nop
800232A4	slti   v0, v1, $000f
800232A8	beq    v0, zero, L232bc [$800232bc]
800232AC	addiu  v0, v1, $0001
800232B0	sw     v0, $01dc(gp)
800232B4	j      L232c4 [$800232c4]
800232B8	ori    a0, zero, $0126

L232bc:	; 800232BC
800232BC	sw     zero, $00b4(gp)
800232C0	ori    a0, zero, $0126

L232c4:	; 800232C4

800232CC	lw     v1, $0250(gp)
[GP + ac] = w(18);

A1 = b;
A2 = 80049248 + V1 * c; // text "Item"
A3 = 7;
func26f44;

800232F4	j      L234c8 [$800234c8]
800232F8	nop
800232FC	lw     v1, $027c(gp)
[GP + ac] = w(84);

if (V1 != 1)
{
    S4 = h[GP + 164] * 5 - 64;
}

S0 = 0;
loop23334:	; 80023334
    if ((hu[GP + 208] >> S0) & 1) // visibility mask
    {
        A0 = 126;
        A1 = S4 + S0 * c + b;
        A2 = 80049248 + S0 * c;
        if ((hu[GP + 20c] >> S0) & 1)
        {
            A3 = 0;
        }
        else
        {
            A3 = 7;
        }
        func26f44;
    }

    S0 = S0 + 1;
    V0 = S0 < a;
8002337C	bne    v0, zero, loop23334 [$80023334]

80023384	j      L234c8 [$800234c8]
80023388	nop
8002338C	lw     v0, $01dc(gp)
80023390	nop
80023394	beq    v0, zero, L233c8 [$800233c8]
80023398	addiu  v0, v0, $ffff (=-$1)
8002339C	sw     v0, $01dc(gp)
800233A0	bne    v0, zero, L233d4 [$800233d4]

800233A8	lw     v1, $027c(gp)
800233AC	ori    v0, zero, $0002
800233B0	bne    v1, v0, L233d8 [$800233d8]

800233B8	addiu  v0, zero, $ffff (=-$1)
800233BC	sw     v0, $027c(gp)
800233C0	j      L233cc [$800233cc]
800233C4	ori    v0, zero, $0001

L233c8:	; 800233C8
800233C8	ori    v0, zero, $0006

L233cc:	; 800233CC
800233CC	sw     v0, $00b4(gp)

L233d4:	; 800233D4
800233D0	ori    a0, zero, $0126

L233d8:	; 800233D8
800233D8	lw     v0, $01c8(gp)

A1 = b;
A2 = 90049248 + V0 * c;
A3 = 7;
func26f44;

800233FC	ori    v0, zero, $0018
80023400	sw     v0, $00ac(gp)
80023404	j      L234c8 [$800234c8]
80023408	nop
8002340C	lw     v1, $01dc(gp)
80023410	nop
80023414	slti   v0, v1, $000f
80023418	beq    v0, zero, L2342c [$8002342c]
8002341C	addiu  v0, v1, $0001
80023420	sw     v0, $01dc(gp)
80023424	j      L23434 [$80023434]
80023428	nop

L2342c:	; 8002342C
8002342C	ori    v0, zero, $0001
80023430	sw     v0, $00b4(gp)

L23434:	; 80023434
80023434	lw     v1, $0188(gp)
80023438	nop
8002343C	sll    v0, v1, $01
80023440	addu   v0, v0, v1
80023444	lw     v1, $01c8(gp)
80023448	sll    v0, v0, $02
8002344C	mult   v1, v0
80023450	mflo   a1
80023454	bgez   a1, L23460 [$80023460]
80023458	nop
8002345C	addiu  a1, a1, $000f

L23460:	; 80023460
80023460	sra    a1, a1, $04
80023464	ori    a0, zero, $0126
80023468	addiu  a1, a1, $000b
8002346C	sll    a2, v1, $01
80023470	addu   a2, a2, v1
80023474	sll    a2, a2, $02
80023478	lui    v0, $8005
8002347C	addiu  v0, v0, $9248 (=-$6db8)
80023480	addu   a2, a2, v0
80023484	jal    func26f44 [$80026f44]
80023488	ori    a3, zero, $0007
8002348C	lw     v1, $0188(gp)
80023490	nop
80023494	sll    v0, v1, $03
80023498	subu   v0, v0, v1
8002349C	sll    v0, v0, $02
800234A0	subu   v0, v0, v1
800234A4	sll    v0, v0, $02
800234A8	bgez   v0, L234b4 [$800234b4]
800234AC	nop
800234B0	addiu  v0, v0, $000f

L234b4:	; 800234B4
800234B4	sra    v0, v0, $04
800234B8	addiu  v0, v0, $0018
800234BC	sw     v0, $00ac(gp)
800234C0	addiu  v0, v1, $0001
800234C4	sw     v0, $0188(gp)

L234c8:	; 800234C8
800234C8	lw     v1, $027c(gp)
800234CC	ori    v0, zero, $0001
800234D0	bne    v1, v0, L23528 [$80023528]
800234D4	addiu  s0, sp, $0020
800234D8	sll    a0, s3, $01
800234DC	addu   a0, a0, s3
800234E0	sll    a0, a0, $03
800234E4	subu   a0, a0, s3
800234E8	sll    a0, a0, $02
800234EC	lui    v0, $8007
800234F0	addiu  v0, v0, $06a4
800234F4	addu   a0, a0, v0
800234F8	addiu  a1, sp, $0018
800234FC	ori    v0, zero, $011a
80023500	sh     v0, $0018(sp)
80023504	addiu  v0, s4, $0008
80023508	sh     v0, $001a(sp)
8002350C	lw     v0, $00ac(gp)
80023510	ori    v1, zero, $0056
80023514	sh     v1, $001c(sp)
80023518	addiu  v0, v0, $fffa (=-$6)
8002351C	jal    func26a94 [$80026a94]
80023520	sh     v0, $001e(sp)
80023524	addiu  s0, sp, $0020

L23528:	; 80023528
[S0 + 0] = h(116);
[S0 + 2] = h(S4 + 5);
[S0 + 4] = h(56);
[S0 + 6] = h(w[GP + ac]);

A0 = S0;
func1e040;

8002354C	lw     v0, $00b4(gp)
80023550	nop
80023554	sltiu  v0, v0, $0002
80023558	bne    v0, zero, L235f8 [$800235f8]
8002355C	ori    s0, zero, $00ff
80023560	lui    s1, $8007
80023564	addiu  s1, s1, $96fc (=-$6904)
80023568	lw     a0, $0214(gp)
8002356C	lw     v0, $01dc(gp)
80023570	sll    a0, a0, $04
80023574	addu   a0, a0, s1
80023578	sll    v0, v0, $04
8002357C	jal    func469b0 [$800469b0]
80023580	subu   s0, s0, v0
80023584	lw     a0, $0214(gp)
80023588	ori    a1, zero, $0001
8002358C	sll    a0, a0, $04
80023590	jal    system_change_semi_transparency_in_packet [$80046848]
80023594	addu   a0, a0, s1
80023598	lw     v0, $0214(gp)
8002359C	ori    v1, zero, $0180
800235A0	sll    v0, v0, $04
800235A4	addu   v0, v0, s1
800235A8	sh     v1, $000c(v0)
800235AC	sb     s0, $0004(v0)
800235B0	lw     v1, $0214(gp)
800235B4	ori    a0, zero, $00e0
800235B8	sh     zero, $0008(v0)
800235BC	sh     zero, $000a(v0)
800235C0	sh     a0, $000e(v0)
800235C4	sll    v1, v1, $04
800235C8	addu   v1, v1, s1
800235CC	sb     s0, $0005(v1)
800235D0	lw     v0, $0214(gp)
800235D4	nop
800235D8	sll    v0, v0, $04
800235DC	addu   v0, v0, s1
800235E0	sb     s0, $0006(v0)
800235E4	lw     a1, $0214(gp)
800235E8	lw     a0, $0160(gp)
800235EC	sll    a1, a1, $04
800235F0	jal    system_add_render_packet_to_queue [$80046794]
800235F4	addu   a1, a1, s1

L235f8:	; 800235F8
800235F8	addu   a0, zero, zero
800235FC	ori    a1, zero, $0001
80023600	ori    a2, zero, $005f
80023604	addiu  a3, sp, $0018
80023608	ori    v0, zero, $00ff
8002360C	sh     zero, $0018(sp)
80023610	sh     zero, $001a(sp)
80023614	sh     v0, $001c(sp)
80023618	jal    func26a34 [$80026a34]
8002361C	sh     v0, $001e(sp)
80023620	addiu  a1, sp, $0018
80023624	lw     v1, $0214(gp)
80023628	ori    v0, zero, $0005
8002362C	sh     v0, $001a(sp)
80023630	ori    v0, zero, $016c
80023634	sh     v0, $001c(sp)
80023638	ori    v0, zero, $00db
8002363C	sh     v0, $001e(sp)
80023640	lui    v0, $8007
80023644	addiu  v0, v0, $06a4
80023648	sh     zero, $0018(sp)
8002364C	sll    a0, v1, $01
80023650	addu   a0, a0, v1
80023654	sll    a0, a0, $03
80023658	subu   a0, a0, v1
8002365C	sll    a0, a0, $02
80023660	jal    func26a94 [$80026a94]
80023664	addu   a0, a0, v0
////////////////////////////////



////////////////////////////////
// func20b68
S7 = A0;
S6 = A1;
FP = A2;

V0 = bu[8009cbdc + FP];
character_data = w[800491d0 + V0 * 4];



[SP + 28] = h(S7 + 12);
[SP + 2a] = h(S6 + 1f);
[SP + 2c] = h(3c);
[SP + 2e] = h(1);
[SP + 30] = h(hu[8009d85c + FP * 440]);
[SP + 32] = h(hu[8009d85e + FP * 440]);
[SP + 34] = h(0);
[SP + 36] = h(hu[8009d85c + FP * 440]);
[SP + 38] = b(0);
[SP + 39] = b(80);
[SP + 3a] = b(ff);

A0 = SP + 28;
80020C54	jal    func27408 [$80027408]



[SP + 28] = h(S7 + 12);
[SP + 2a] = h(S6 + 29);
[SP + 2c] = h(3c);
[SP + 2e] = h(1);
[SP + 30] = h(hu[8009d860 + FP * 440]);
[SP + 32] = h(hu[8009d862 + FP * 440])
[SP + 34] = h(0);
[SP + 36] = h(hu[8009d860 + FP * 440]);
[SP + 38] = b(0);
[SP + 39] = b(ff);
[SP + 3a] = b(80);
A0 = SP + 28;
80020CC8	jal    func27408 [$80027408]



V1 = h[8009d85c + FP * 440];
V0 = h[8009d85e + FP * 440];
80020CF8	sltiu  s2, v1, $0001

80020D00	sra    v0, v0, $02
80020D04	slt    v0, v0, v1
80020D0C	ori    s3, zero, $0006
80020D08	beq    v0, zero, L20d14 [$80020d14]

80020D10	ori    s3, zero, $0007

L20d14:	; 80020D14
V0 = h[8009d862 + FP * 440];
V1 = h[8009d860 + FP * 440];

80020D44	sra    v0, v0, $02
80020D48	slt    v0, v0, v1
80020D50	ori    s4, zero, $0006
if (V0 != 0)
{
    S4 = 7;
}

T0 = character_data;



if (bu[8009c757 + character_data * 84] & 10)
{
    A0 = S7 + 24;
    A1 = S6 + b;
    A2 = 80049350; // text "Sadness"
    A3 = 3;
    func26f44;
}



if (bu[8009c757 + character_data * 84] & 20)
{
    A0 = S7 + 24;
    A1 = S6 + b;
    A2 = 80049344; // text "Fury"
    A3 = 3;
    func26f44;
}



A0 = S7;
A1 = S6;
A2 = 8009c748 + character_data * 84; // name
if (S2 != 0)
{
    A3 = 2;
}
else
{
    A3 = 7;
}
func26f44;



A0 = S7;
S0 = S6 + d;
A1 = S0;
A2 = 800493a0; // LV
A3 = 5;
system_draw_menu_8width_font;



A0 = S7 + 12;
A1 = S0;
A2 = bu[8009c6e4 + 0054 + character_data * 84 + 1]; // level value
A3 = 2;
if (S2 != 0)
{
    A4 = 2;
}
else
{
    A4 = 7;
}
func28e00;



A0 = S7;
A1 = S6 + 18;
A2 = 80049390; // HP
A3 = 5;
system_draw_menu_8width_font;


A0 = S7 + 12;
A1 = S6 + 17;
A2 = h[8009d85c + FP * 440];
if (S2 == 0)
{
    A4 = S3;
}
else
{
    A4 = 2;
}

A3 = 4;
func28e00;

A0 = S7 + 32;
A1 = S6 + 17;
A2 = h[8009d85e + FP * 440];
A3 = 4;
if (S2 != 0)
{
    A4 = 2;
}
else
{
    A4 = 7;
}
func28e00;


A0 = S7;
A1 = S6 + 22;
A2 = 80049398; // MP
A3 = 5;
system_draw_menu_8width_font;



A0 = S7 + 12;
A1 = S6 + 21;
A2 = h[8009d860 + FP * 440];
A3 = 4;
if (S2 == 0)
{
    A4 = S4;
}
else
{
    A4 = 2;
}
func28e00;



A0 = S7 + 32;
A1 = S6 + 21;
A2 = h[8009d862 + FP * 440];
A3 = 4;
if (S2 != 0)
{
    A4 = 2;
}
else
{
    A4 = 7;
}
func28e00;



A0 = S7 + 2e;
A1 = S6 + 21;
A2 = d8;
A3 = 0;
A4 = 4;
A5 = 8;
A6 = 1;
A7 = 0;
80020FB4	jal    func28ca0 [$80028ca0]

A0 = S7 + 2e;
A1 = S6 + 17;
A2 = d8;
A3 = 0;
A4 = 4;
A5 = 8;
A6 = 1;
A7 = 0;
80020FE0	jal    func28ca0 [$80028ca0]



80020FE8	addu   a0, zero, zero
80020FEC	ori    a1, zero, $0001
80020FF0	ori    a2, zero, $007f
80020FF4	addiu  a3, sp, $0020
80020FF8	ori    v0, zero, $0100
80020FFC	sh     zero, $0020(sp)
80021000	sh     zero, $0022(sp)
80021004	sh     v0, $0024(sp)
8002100C	sh     v0, $0026(sp)
80021008	jal    func26a34 [$80026a34]
////////////////////////////////



////////////////////////////////
// func27408
S1 = A0;
// +0 - x
// +2 - y
// +4 - width
// +6 - height
// +8 - current
// +a - max
// +c - 0
// +e - current
// +10 - R
// +11 - G
// +12 - B

A0 = h[S1 + a];
if (A0 == 0)
{
    return;
}

A1 = (h[S1 + 4] * h[S1 + e]) / A0;
width = (h[S1 + 4] * h[S1 + 8]) / A0;

S4 = hu[S1 + 0];
S5 = hu[S1 + 2];
height = hu[S1 + 6];

800274D0	addu   fp, v1, zero
800274D4	lui    a0, $8006
800274D8	lw     a0, $2f24(a0)
S7 = A1;

800274DC	jal    func46910 [$80046910]

packet = w[80062f24];

[packet + 8] = h(S4);
[packet + a] = h(S5);
[packet + 10] = h(S4 + width);
[packet + 12] = h(S5);
[packet + 18] = h(S4);
[packet + 1a] = h(S5 + height);
[packet + 20] = h(S4 + width));
[packet + 22] = h(S5 + height);

80027564	lbu    s0, $0010(s1)
80027570	lbu    s2, $0011(s1)
80027574	lbu    s3, $0012(s1)

[packet + 4] = b(S0);
[packet + 5] = b(S2);
[packet + 6] = b(S3);
[packet + c] = b(c8)
[packet + d] = b(c8);
[packet + e] = b(c8);
[packet + 14] = b(S0);
[packet + 15] = b(S2);
[packet + 16] = b(S3);
[packet + 1c] = b(c8);
[packet + 1d] = b(c8);
[packet + 1e] = b(c8);


8002762C	lui    a1, $8006
80027630	lw     a1, $2f24(a1)
80027634	lw     a0, $0280(gp)
80027638	addiu  v0, a1, $0024
8002763C	lui    at, $8006
80027640	sw     v0, $2f24(at)
80027644	jal    system_add_render_packet_to_queue [$80046794]
80027648	nop

A0 = h(S1 + c);
if (A0 != 0)
{
    if (A0 == 1)
    {
        S0 = 0;
        S2 = c8;
        S3 = 50;
    }
    else
    {
        S0 = c8;
        S2 = 0;
        S3 = 0;
    }

    8002767C	lui    a0, $8006
    80027680	lw     a0, $2f24(a0)
    80027684	jal    func46910 [$80046910]
    80027688	nop
    8002768C	lui    v0, $8006
    80027690	lw     v0, $2f24(v0)
    80027694	nop
    80027698	sh     s4, $0008(v0)
    8002769C	lui    v0, $8006
    800276A0	lw     v0, $2f24(v0)
    800276A4	nop
    800276A8	sh     s5, $000a(v0)
    800276AC	lui    v0, $8006
    800276B0	lw     v0, $2f24(v0)
    800276B4	addu   a0, s4, s7
    800276B8	sh     a0, $0010(v0)
    800276BC	lui    v0, $8006
    800276C0	lw     v0, $2f24(v0)
    800276C4	nop
    800276C8	sh     s5, $0012(v0)
    800276CC	lui    v0, $8006
    800276D0	lw     v0, $2f24(v0)
    800276D4	nop
    800276D8	sh     s4, $0018(v0)
    800276DC	lui    v0, $8006
    800276E0	lw     v0, $2f24(v0)
    800276E4	addu   v1, s5, s6
    800276E8	sh     v1, $001a(v0)
    800276EC	lui    v0, $8006
    800276F0	lw     v0, $2f24(v0)
    800276F4	nop
    800276F8	sh     a0, $0020(v0)
    800276FC	lui    v0, $8006
    80027700	lw     v0, $2f24(v0)
    80027704	nop
    80027708	sh     v1, $0022(v0)

    [packet + 4] = b(S0);
    [packet + 5] = b(S2);
    [packet + 6] = b(S3);
    [packet + c] = b(S0);
    [packet + d] = b(S2);
    [packet + e] = b(S3);

    8002776C	lui    v0, $8006
    80027770	lw     v0, $2f24(v0)
    80027774	nop
    80027778	sb     s0, $0014(v0)
    8002777C	lui    v0, $8006
    80027780	lw     v0, $2f24(v0)
    80027784	nop
    80027788	sb     s2, $0015(v0)
    8002778C	lui    v0, $8006
    80027790	lw     v0, $2f24(v0)
    80027794	nop
    80027798	sb     s3, $0016(v0)
    8002779C	lui    v0, $8006
    800277A0	lw     v0, $2f24(v0)
    800277A4	nop
    800277A8	sb     s0, $001c(v0)
    800277AC	lui    v0, $8006
    800277B0	lw     v0, $2f24(v0)
    800277B4	nop
    800277B8	sb     s2, $001d(v0)
    800277BC	lui    v0, $8006
    800277C0	lw     v0, $2f24(v0)
    800277C4	nop
    800277C8	sb     s3, $001e(v0)
    800277CC	lui    a1, $8006
    800277D0	lw     a1, $2f24(a1)
    800277D4	lw     a0, $0280(gp)
    800277D8	addiu  v0, a1, $0024
    800277DC	lui    at, $8006
    800277E0	sw     v0, $2f24(at)
    800277E4	jal    system_add_render_packet_to_queue [$80046794]
    800277E8	nop
}

800277EC	lui    a0, $8006
800277F0	lw     a0, $2f24(a0)
800277F4	jal    func46910 [$80046910]
800277F8	nop
800277FC	lui    v0, $8006
80027800	lw     v0, $2f24(v0)
80027804	nop
80027808	sh     s4, $0008(v0)
8002780C	lui    v0, $8006
80027810	lw     v0, $2f24(v0)
80027814	nop
80027818	sh     s5, $000a(v0)
8002781C	lui    v0, $8006
80027820	lw     v0, $2f24(v0)
80027824	addu   a0, s4, fp
80027828	sh     a0, $0010(v0)
8002782C	lui    v0, $8006
80027830	lw     v0, $2f24(v0)
80027834	nop
80027838	sh     s5, $0012(v0)
8002783C	lui    v0, $8006
80027840	lw     v0, $2f24(v0)
80027844	addu   v1, s5, s6
80027848	sh     s4, $0018(v0)
8002784C	lui    v0, $8006
80027850	lw     v0, $2f24(v0)
80027854	addiu  v1, v1, $0001
80027858	sh     v1, $001a(v0)
8002785C	lui    v0, $8006
80027860	lw     v0, $2f24(v0)
80027864	nop
80027868	sh     a0, $0020(v0)
8002786C	lui    v0, $8006
80027870	lw     v0, $2f24(v0)
80027874	nop
80027878	sh     v1, $0022(v0)

[packet + 4] = b(50);
[packet + 5] = b(0);
[packet + 6] = b(0);
[packet + c] = b(50);
[packet + d] = b(0);
[packet + e] = b(0);
[packet + 14] = b(0);
[packet + 15] = b(0);
[packet + 16] = b(0);
[packet + 1c] = b(0);
[packet + 1d] = b(0);
[packet + 1e] = b(0);

8002793C	lui    a1, $8006
80027940	lw     a1, $2f24(a1)
80027944	lw     a0, $0280(gp)
80027948	addiu  v0, a1, $0024
8002794C	lui    at, $8006
80027950	sw     v0, $2f24(at)
80027954	jal    system_add_render_packet_to_queue [$80046794]
80027958	nop

L2795c:	; 8002795C
////////////////////////////////



////////////////////////////////
// func285ac
pos_x = A0;
packet = w[80062f24];
col_r = A4;
col_g = A5;
col_b = A6;
pos_y = A1;
width = A2;
height = A3;

A0 = packet;
func46910;

A0 = packet;
A1 = 1;
system_change_semi_transparency_in_packet;

[packet + 8] = h(pos_x);
[packet + a] = h(pos_y);
[packet + 10] = h(pos_x + width);
[packet + 12] = h(pos_y);
[packet + 18] = h(pos_x);
[packet + 1a] = h(pos_y + height / 2);
[packet + 20] = h(pos_x + width);
[packet + 22] = h(pos_y + height / 2);
[packet + 4] = b(col_r);
[packet + 5] = b(col_g);
[packet + 6] = b(col_b);
[packet + c] = b(col_r);
[packet + d] = b(col_g);
[packet + e] = b(col_b);
[packet + 14] = b(80);
[packet + 15] = b(80);
[packet + 16] = b(80);
[packet + 1c] = b(80);
[packet + 1d] = b(80);
[packet + 1e] = b(80);

[80062f24] = w(packet + 24);

A0 = w[GP + 280];
A1 = packet;
system_add_render_packet_to_queue;

A0 = w[80062f24];
80028788	jal    func46910 [$80046910]

A0 = w[80062f24];
A1 = 1;
system_change_semi_transparency_in_packet;

[packet + 8] = h(pos_x);
[packet + a] = h(pos_y + height / 2);
[packet + 10] = h(pos_x + width);
[packet + 12] = h(pos_y + height / 2);
[packet + 18] = h(pos_x);
[packet + 1a] = h(pos_y + height);
[packet + 20] = h(pos_x + width);
[packet + 22] = h(pos_y + height);
[packet + 4] = b(col_r);
[packet + 5] = b(col_g);
[packet + 6] = b(col_b);
[packet + c] = b(col_r);
[packet + d] = b(col_g);
[packet + e] = b(col_b);
[packet + 14] = b(0);
[packet + 15] = b(0);
[packet + 16] = b(0);
[packet + 1c] = b(0);
[packet + 1d] = b(0);
[packet + 1e] = b(0);

A0 = w[GP + 280];
A1 = w[80062f24];
[80062f24] = w(A1 + 24);
system_add_render_packet_to_queue;
////////////////////////////////