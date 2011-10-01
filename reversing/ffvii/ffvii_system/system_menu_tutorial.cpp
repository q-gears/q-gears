////////////////////////////////
// func1c788
if( w[GP + 150] != 0 )
{
    [GP + 150] = w(w[GP + 150] - 1);
}
else
{
    if( w[GP + b4] != 1 )
    {
        func34b44;
        if( V0 == 0 )
        {
            func1c5bc; // rerurn pressed button

            return V0;
        }
    }
}
return 0;
////////////////////////////////



////////////////////////////////
// func1f6e4
[GP + a0] = b(A0);
A0 = A0 << 10;
if( A0 != 0 )
{
    [GP + a2] = h(A1);
    [GP + a4] = h(A2);
}
else
{
    [GP + 97] = b(0);
}
////////////////////////////////



////////////////////////////////
// func1f6c0
[GP + 97] = b(1);
[GP + 98] = b(A1);
[GP + 9c] = w(28);
[GP + a1] = b(1);
[GP + 174] = w(A0);
////////////////////////////////



////////////////////////////////
// func1c4e8
S0 = A0;

A0 = 1;
A1 = h[GP + 2e];
A2 = h[GP + 30];
[GP + 2d] = b(1);
func1f6e4;

[GP + 97] = b(1);
[GP + 98] = b(7);
[GP + 9c] = w(28);
[GP + a1] = b(1);
[GP + 174] = w(S0);

A0 = 0;
A1 = ff;

loop1c524:	; 8001C524
    V1 = bu[S0 + 0];
    if( V1 < ff || V1 >= fa )
    {
        S0 = S0 + 2;
    }
    else
    {
        S0 = S0 + 1;
    }

    if( bu[S0 + 0] == ff )
    {
        S0 = S0 + 1;
        break;
    }

    A0 = A0 + 1;
    V0 = A0 < 100;
8001C56C	bne    v0, zero, loop1c524 [$8001c524]

return S0;
////////////////////////////////



////////////////////////////////
// func1c58c
if( bu[GP + 97] == 0 )
{
    [GP + 2d] = b(0);
}
////////////////////////////////



////////////////////////////////
// func1c5bc
if( bu[GP + 2d] != 0 )
{
    if( bu[GP + 97] == 0 )
    {
        [GP + 2d] = b(0);
    }

    return 0000;
}

V0 = w[GP + 158]; // pointer to tutorial data
V1 = bu[V0];
[GP + 158] = w(V0 + 1);

switch( V1 )
{
    case 0: // 24C60180
    {
        V0 = w[GP + 158];
        [GP + 150] = w(hu[V0]);
        [GP + 158] = w(V0 + 2);
        return 0000;
    }

    case 02: // 60C60180
    {
        [GP + 150] = w(14);
        return 1000; // up
    }

    case 03: // 68C60180
    {
        [GP + 150] = w(14);
        return 4000; // down
    }

    case 04: // 70C60180
    {
        [GP + 150] = w(14);
        return 8000; // left
    }

    case 05: // 78C60180
    {
        [GP + 150] = w(14);
        return 2000; // right
    }

    case 06: // 90C60180
    {
        [GP + 150] = w(14);
        return 0010; // triangle
    }

    case 07: // 98C60180
    {
        [GP + 150] = w(14);
        return 0040; // cross
    }

    case 08: // 80C60180
    {
        [GP + 150] = w(14);
        return 0080; // square
    }

    case 09 // 88C60180
    {
        [GP + 150] = w(14);
        return 0020; // circle
    }

    case 0a // A0C60180
    {
        [GP + 150] = w(14);
        return 0008; // r1
    }

    case 0b // A8C60180
    {
        [GP + 150] = w(14);
        return 0002; // r2
    }

    case 0c // B0C60180
    {
        [GP + 150] = w(14);
        return 0004; // l1
    }

    case 0d // B8C60180
    {
        [GP + 150] = w(14);
        return 0001; // l2
    }

    case 10: // CCC60180 10
    {
        A0 = w[GP + 158];
        func1c4e8;

        [GP + 150] = w(50);
        [GP + 158] = w(V0);
        return 0000;
    }

    case 11: // 54C70180
    {
        A0 = 0;
        A1 = 0;
        A2 = 0;
        func1f6e4;

        [80062fa0] = w(0);
        [GP + 150] = w(0);
        return 0000;
    }

    case 12: // ECC60180 12
    {
        V0 = w[GP + 158];
        [GP + 2e] = h(hu[V0 + 0]);
        [GP + 30] = h(hu[V0 + 2]);
        [GP + 150] = w(3c);
        [GP + 158] = w(V0 + 4);
        return 0000;
    }
}

return 0000;
////////////////////////////////



////////////////////////////////
// func1c808
if( w[80062fa0] == 0 )
{
    if( bu[800696ac] != ff )
    {
        if( bu[800696ad] == 41 )
        {
            V0 = bu[800696ae] << 8;
            V1 = bu[800696af];

            A0 = V1 NOR V0;
        }
        else
        {
            A0 = 0;
        }
    }
    else
    {
        A0 = 0;
    }
}
else // tutorial
{
    func1c788; // return pressed burron

    A0 = V0;
}

if( bu[800696ce] != ff )
{
    if( bu[800696cf] == 41 )
    {
        V0 = bu[800696d1] NOR (bu[800696d0] << 8);
    }
    else
    {
        V0 = 0;
    }
}
else
{
    V0 = 0;
}

return (V0 << 10) | (A0 & ffff);
////////////////////////////////



////////////////////////////////
// func1cb48
func1c808; // lower two bytes of return is input mask

A1 = V0;
[80062d80] = h(A1 >> 10);

if( ( ( hu[8009d7be] >> 2 ) & 3 == 0 ) || ( w[80062fa0] == 0 ) )
{
    [80062d78] = h(0);
    A0 = 0;
    loop1cba4:	; 8001CBA4
        if( A1 & (1 << A0) )
        {
            [80062d78] = h(hu[80062d78] | 1 << bu[8009d7c0 + A0]);
        }

        A0 = A0 + 1;
        V0 = A0 < 10;
    8001CBE0	bne    v0, zero, loop1cba4 [$8001cba4]
}
else
{
    [80062d78] = h(A1);
}

[80062d7e] = h(0);
[80062d7c] = h((hu[80062d78] ^ hu[80062d7a]) & hu[80062d78]);

if( hu[80062d78] != hu[80062d7a] )
{
    [GP + 20] = h(0);
    [GP + 1c] = h(0);
}
else
{
    if( h[GP + 1c] != 0 )
    {
        V1 = h[GP + 20];
        if( V1 == 3 )
        {
            [80062d7e] = h(hu[80062d78]);
            [GP + 20] = h(0);
        }
        else
        {
            [GP + 20] = h(V1 + 1);
        }
    }
    else
    {
        V1 = h[GP + 20];
        if( V1 == f )
        {
            [GP + 1c] = h(1);
            [GP + 20] = h(0);
        }
        else
        {
            [GP + 20] = h(V1 + 1);
        }
    }
}



[80062d84] = h((hu[80062d80] ^ hu[80062d82]) & hu[80062d80]);

if( hu[80062d80] != hu[80062d82] )
{
    [GP + 1e] = h(0);
    [GP + 22] = h(0);
}
else
{
    if( h[GP + 1e] != 0 )
    {
        if( h[GP + 22] == 3 )
        {
            [80062d86] = h(hu[80062d80]);
            [GP + 22] = h(0);
        }
        else
        {
            [GP + 22] = h(h[GP + 22] + 1);
        }
    }
    else
    {
        if( h[GP + 22] == f )
        {
            [GP + 1e] = h(1);
            [GP + 22] = h(0);
        }
        else
        {
            [GP + 22] = h(h[GP + 22] + 1);
        }

        [80062d86] = h(0);
    }
}

[80062d7e] = h(hu[80062d7e] | hu[80062d7c]);
[80062d7a] = h(hu[80062d78]);
[80062d82] = h(hu[80062d80]);
[80062d86] = h(hu[80062d86] | hu[80062d84]);
////////////////////////////////



////////////////////////////////
// func1f710
if( bu[GP + 97] == 0 )
{
    return 0;
}

A0 = w[GP + 174];
system_get_single_string_width;

S2 = V0;
V1 = bu[GP + 97];
if( V1 == 1 )
{
    8001F758	lui    v0, $5555
    8001F778	ori    v0, v0, $5556
    8001F77C	mult   s2, v0
    8001F780	sra    v0, s2, $1f
    8001F784	mfhi   t0
    8001F788	lbu    a0, $00a1(gp)
    8001F78C	subu   v0, t0, v0
    8001F790	mult   v0, a0
    8001F794	lbu    v1, $00a0(gp)
    8001F798	mflo   a3
    if( V1 != 0 )
    {
        8001F7A0	sll    a2, a0, $03
        8001F7CC	addiu  a0, sp, $0018
        8001F7D0	addiu  a1, s2, $0010
        8001F7D4	srl    v0, a1, $1f
        8001F7D8	addu   a1, a1, v0
        8001F7DC	sra    a1, a1, $01
        8001F7E0	srl    v0, a3, $1f
        8001F7E4	addu   v0, a3, v0
        8001F7E8	sra    v0, v0, $01
        8001F7EC	sw     a2, $0010(sp)
        8001F7F0	srl    a2, a2, $01
        8001F7F4	addiu  a2, a2, $fff4 (=-$c)
        8001F7F8	lh     s1, $00a2(gp)
        8001F7FC	lh     s0, $00a4(gp)
        8001F800	addu   a1, s1, a1
        8001F804	subu   a1, a1, v0
    }
    else
    {
        8001F7A0	sll    a2, a0, $03
        8001F7A4	ori    s1, zero, $00b4
        8001F7A8	ori    s0, zero, $0068
        8001F7AC	sw     a2, $0010(sp)
        8001F7B0	addiu  a0, sp, $0018
        8001F7B4	srl    a1, a3, $1f
        8001F7B8	addu   a1, a3, a1
        8001F7BC	sra    a1, a1, $01
        8001F7C0	subu   a1, s1, a1
        8001F7C8	srl    a2, a2, $01
    }

    A2 = S0 - A2;
    [A0 + 0] = h(A1);
    [A0 + 2] = h(A2);
    [A0 + 4] = h(A3);
    [A0 + 6] = h(A4);

    [GP + a1] = b(bu[GP + a1] + 1);

    if( bu[GP + a1] == 3 )
    {
        [GP + 97] = b(2);
        [GP + a1] = b(2);
    }
    8001F834	j      L1f9e4 [$8001f9e4]
}
else if( V1 == 2 )
{
    if( bu[GP + a0] != 0 )
    {
        A0 = h[GP + a2] + 8; // x
        A1 = h[GP + a4] + 6; // y
        A2 = w[GP + 174]; // text pointer
        A3 = bu[GP + 98]; // colour
        func26f44;

        [SP + 18] = h(h[GP + a2]);
        [SP + 1a] = h(h[GP + a4]);
    }
    else
    {
        S0 = b4 - S2 / 2;
        A0 = S0;
        A1 = 5c + 6;
        A2 = w[GP + 174]; // text pointer
        A3 = bu[GP + 98]; // colour
        func26f44;

        [SP + 18] = h(S0 - 8);
        [SP + 1a] = h(5c);
    }

    [SP + 1c] = h(S2 + 10);
    [SP + 1e] = h(18);

    if( w[GP + 9c] != 0 )
    {
        [GP + 9c] = w(w[GP + 9c] - 1);
    }

    if( w[GP + 9c] < 14 )
    {
        8001F8E0	jal    func34b44 [$80034b44]

        if( V0 == 0 )
        {
            if( bu[GP + a0] == 0 && w[GP + 9c] == 0 )
            {
                [GP + 97] = b(3);
            }
            else
            {
                8001F910	jal    func1c498 [$8001c498]

                if( V0 != 0)
                {
                    [GP + 97] = b(3);
                }
            }
        }
    }
}
else if( V1 == 3 )
{
    8001F76C	lui    v0, $5555
    8001F92C	ori    v0, v0, $5556
    8001F930	mult   s2, v0
    8001F934	sra    v0, s2, $1f
    8001F938	mfhi   t0
    8001F93C	lbu    a0, $00a1(gp)
    8001F940	subu   v0, t0, v0
    8001F944	mult   v0, a0
    8001F948	lbu    v1, $00a0(gp)
    8001F94C	mflo   a3
    if( V1 == 0 )
    {
        8001F954	sll    a2, a0, $03
        8001F958	ori    s1, zero, $00b4
        8001F95C	ori    s0, zero, $0068
        8001F960	sw     a2, $0010(sp)
        8001F964	addiu  a0, sp, $0018
        8001F968	srl    a1, a3, $1f
        8001F96C	addu   a1, a3, a1
        8001F970	sra    a1, a1, $01
        8001F974	subu   a1, s1, a1
        8001F97C	srl    a2, a2, $01
    }
    else
    {
        8001F954	sll    a2, a0, $03
        A0 = SP + 18;
        8001F984	addiu  a1, s2, $0010
        8001F988	srl    v0, a1, $1f
        8001F98C	addu   a1, a1, v0
        8001F990	sra    a1, a1, $01
        8001F994	srl    v0, a3, $1f
        8001F998	addu   v0, a3, v0
        8001F99C	sra    v0, v0, $01
        8001F9A0	sw     a2, $0010(sp)
        8001F9A4	srl    a2, a2, $01
        8001F9A8	addiu  a2, a2, $fff4 (=-$c)
        8001F9AC	lh     s1, $00a2(gp)
        8001F9B0	lh     s0, $00a4(gp)
        8001F9B4	addu   a1, s1, a1
        8001F9B8	subu   a1, a1, v0
    }

    8001F9C0	subu   a2, s0, a2
    [A0 + 0] = h(A1);
    [A0 + 2] = h(A2);
    [A0 + 4] = h(A3);
    [A0 + 6] = h(A4);

    [GP + a1] = b(bu[GP + a1] - 1);

    if( bu[GP + a1] == 0 )
    {
        [GP + 97] = b(0);
    }
}

8001F878	j      L1f9e4



L1f9e4:	; 8001F9E4
8001F9E4	jal    func1de70 [$8001de70]

A0 = 80049384;
8001F9F4	jal    func1def0 [$8001def0]

A0 = SP + 18;
func1e040; // draw window

8001FA04	jal    func1deb0 [$8001deb0]
////////////////////////////////



////////////////////////////////
// system_get_single_string_width
A2 = 0;

if( bu[GP + b8] <= 0 )
{
    return 0;
}

A1 = 0;

loop26ba0:	; 80026BA0
    if( A0 == 0 )
    {
        return A1;
    }

    V0 = bu[A0];

    if( V0 == A2 )
    {
        return A1;
    }

    V1 = V0 - fa;

    if( V1 == 0 )
    {
        A0 = A0 + 1;
        V1 = e7;
    }
    else if( V1 == 1 )
    {
        A0 = A0 + 1;
        V1 = 1b9;
    }
    else if( V1 == 2 )
    {
        A0 = A0 + 1;
        V1 = 2a0;
    }
    else if( V1 == 3 )
    {
        A0 = A0 + 1;
        V1 = 372;
    }
    else if( V1 == 4 )
    {
        A0 = A0 + 1;
        V1 = 444;
    }
    else
    {
        V1 = 0;
    }

    A0 = A0 + 1;
    T0 = w[800707c0] + bu[A0] + V1;
    V1 = bu[T0];


    A1 = A1 + V1 >> 5 + V1 & 1f;

    A2 = A2 + 1;
    V0 = A2 < bu[GP + b8];
80026C44	bne    v0, zero, loop26ba0 [$80026ba0]

return A1;
////////////////////////////////
