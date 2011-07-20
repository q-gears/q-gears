////////////////////////////////
// func3884c
A1 = w[A0 + 0];
V0 = w[8005aaf4];
if (A1 < 1 || A1 & 2)
{
    [V0 + 184] = h(hu[A0 + 8]); // Reverberation depth left
    [8005a6a8] = h(hu[A0 + 8]);
}

if (A1 < 1 || A1 & 4)
{
    [V0 + 186] = h(hu[A0 + a]); // Reverberation depth right
    [8005a6aa] = h(hu[A0 + a]);
}

return 0;
////////////////////////////////



////////////////////////////////
// func38c6c
// A0 = 1
// A1 - channel mask

A1 = A1 & 00ffffff;
A2 = A1;
A3 = A1 >>> 10;

if (A0 == 1)
{
    if (w[8004aaec] & 00000001)
    {
        80038CAC	lui    v0, $8007
        80038CB0	addiu  v0, v0, $7f28
        80038CB4	sh     a2, $0000(v0)
        80038CB8	lui    at, $8007
        80038CBC	sh     a3, $7f2a(at)
        80038CC0	lui    v0, $8005
        80038CC4	lw     v0, $a6b8(v0)
        80038CC8	nop
        80038CCC	ori    v0, v0, $0001
        80038CD0	lui    at, $8005
        80038CD4	sw     v0, $a6b8(at)
        80038CD8	lui    v0, $8005
        80038CDC	lw     v0, $a6b4(v0)
        80038CE0	nop
        80038CE4	or     v0, a1, v0
        80038CE8	lui    at, $8005
        80038CEC	sw     v0, $a6b4(at)
        80038CF0	lui    v0, $8007
        80038CF4	lhu    v0, $7f2c(v0)
        80038CF8	nop
        80038CFC	and    v0, v0, a1
        80038D00	beq    v0, zero, L38d20 [$80038d20]
        80038D04	nop
        80038D08	lui    v0, $8007
        80038D0C	lhu    v0, $7f2c(v0)
        80038D10	nor    v1, zero, a1
        80038D14	and    v0, v0, v1
        80038D18	lui    at, $8007
        80038D1C	sh     v0, $7f2c(at)

        L38d20:	; 80038D20
        80038D20	lui    v0, $8007
        80038D24	lhu    v0, $7f2e(v0)
        80038D28	nop
        80038D2C	and    v0, v0, a3
        if (V0 != 0)
        {
            80038D38	lui    v0, $8007
            80038D3C	lhu    v0, $7f2e(v0)
            80038D40	nor    v1, zero, a3
            80038D44	and    v0, v0, v1
            80038D48	lui    at, $8007
            80038D4C	sh     v0, $7f2e(at)
        }
    }
    else
    {
        [8004a68c] = w(w[8004a68c] | A1);

        V1 = w[8004aaf4];
        [V1 + 188] = h(A2);
        [V1 + 18a] = h(A3);
    }
}
else if (A0 == 0)
{
    80038D7C	lui    v0, $8005
    80038D80	lw     v0, $aaec(v0)
    80038D84	nop
    80038D88	andi   v0, v0, $0001
    80038D8C	beq    v0, zero, L38e40 [$80038e40]
    80038D90	nop
    80038D94	lui    v0, $8007
    80038D98	addiu  v0, v0, $7f2c
    80038D9C	sh     a2, $0000(v0)
    80038DA0	lui    at, $8007
    80038DA4	sh     a3, $7f2e(at)
    80038DA8	lui    v0, $8005
    80038DAC	lw     v0, $a6b8(v0)
    80038DB0	nop
    80038DB4	ori    v0, v0, $0001
    80038DB8	lui    at, $8005
    80038DBC	sw     v0, $a6b8(at)
    80038DC0	lui    v0, $8005
    80038DC4	lw     v0, $a6b4(v0)
    80038DC8	nor    v1, zero, a1
    80038DCC	and    v0, v1, v0
    80038DD0	lui    at, $8005
    80038DD4	sw     v0, $a6b4(at)
    80038DD8	lui    v0, $8007
    80038DDC	lhu    v0, $7f28(v0)
    80038DE0	nop
    80038DE4	and    v0, v0, a1
    80038DE8	beq    v0, zero, L38e08 [$80038e08]
    80038DEC	nop
    80038DF0	lui    v0, $8007
    80038DF4	lhu    v0, $7f28(v0)
    80038DF8	nop
    80038DFC	and    v0, v0, v1
    80038E00	lui    at, $8007
    80038E04	sh     v0, $7f28(at)

    L38e08:	; 80038E08
    80038E08	lui    v0, $8007
    80038E0C	lhu    v0, $7f2a(v0)
    80038E10	nop
    80038E14	and    v0, v0, a3
    if (V0 == 0)
    {
        return;
    }

    80038E20	lui    v0, $8007
    80038E24	lhu    v0, $7f2a(v0)
    80038E28	nor    v1, zero, a3
    80038E2C	and    v0, v0, v1
    80038E30	lui    at, $8007
    80038E34	sh     v0, $7f2a(at)
    return;

    L38e40:	; 80038E40
    80038E40	lui    v0, $8005
    80038E44	lw     v0, $aaf4(v0)
    80038E48	lui    v1, $8005
    80038E4C	lw     v1, $a68c(v1)
    80038E50	sh     a2, $018c(v0)
    80038E54	sh     a3, $018e(v0)
    80038E58	nor    v0, zero, a1
    80038E5C	and    v0, v0, v1
    [8004a68c] = w(V0);
}
////////////////////////////////



////////////////////////////////
// func2e23c
S1 = A0;
S0 = A1;

if (w[S0 + 4] & 00000010) // +dc
{
    A0 = S1;
    A1 = hu[S0 + 1c]; // f8
    func395c8;

    [S0 + 4] = w(w[S0 + 4] & ffffffef);
    if (w[S0 + 4] == 0)
    {
        return;
    }
}



if (w[S0 + 4] & 00000003) // +dc
{
    A0 = S1;
    A1 = h[S0 + 28]; // 104
    A2 = h[S0 + 2a]; // 106
    func393c8;

    [S0 + 4] = w(w[S0 + 4] & fffffffc);
    if (w[S0 + 4] == 0)
    {
        return;
    }
}



if (w[S0 + 4] & 00000080)
{
    A0 = S1;
    A1 = w[S0 + 8];
    func39644; // we set start address here

    [S0 + 4] = w(w[S0 + 4] & ffffff7f);
    if (w[S0 + 4] == 0)
    {
        return;
    }
}



if (w[S0 + 4] & 00010000)
{
    A0 = S1;
    A1 = w[S0 + c];
    func396c0;

    [S0 + 4] = w(w[S0 + 4] & fffeffff);
    if (w[S0 + 4] == 0)
    {
        return;
    }
}



if (w[S0 + 4] & 00002200) // +dc
{
    A0 = S1;
    A1 = h[S0 + 24]; // 100
    A2 = h[S0 + 14]; // f0
    func398ec;

    [S0 + 4] = w(w[S0 + 4] & ffffddff);
    if (w[S0 + 4] == 0)
    {
        return;
    }

}



if (w[S0 + 4] & 00000900) // +dc
{
    A0 = S1;
    A1 = h[S0 + 1e]; // fa
    A2 = h[S0 + 10]; // ec
    func39850;

    [S0 + 4] = w(w[S0 + 4] & fffff6ff);
    if (w[S0 + 4] == 0)
    {
        return;
    }

}



if (w[S0 + 4] & 00004400) // +dc
{
    A0 = S1;
    A1 = h[S0 + 26]; // 102 // release rate
    A2 = h[S0 + 18]; // f4 // release mode
    func399d0;

    [S0 + 4] = w(w[S0 + 4] & ffffbbff);
    if (w[S0 + 4] == 0)
    {
        return;
    }

}




if (w[S0 + 4] & 00009000) // +dc
{
    A0 = S1;
    A1 = h[S0 + 20]; // fc // decay rate.
    func3973c;

    A0 = S1;
    A1 = h[S0 + 22]; // fe // sustain level.
    func397c8;

    [S0 + 4] = w(w[S0 + 4] & ffff6fff);
}
////////////////////////////////



////////////////////////////////
// func397c8
A0 = w[8004aaf4] + A0 << 4;

[A0 + 8] = h((hu[A0 + 8] & fff0) | A1);

800397EC	ori    v0, zero, $0001
800397F0	sw     v0, $0004(sp)
800397F4	sw     zero, $0000(sp)
800397F8	j      L39830 [$80039830]

loop39800:	; 80039800
80039800	lw     v1, $0004(sp)
80039804	nop
80039808	sll    v0, v1, $01
8003980C	addu   v0, v0, v1
80039810	sll    v0, v0, $02
80039814	addu   v0, v0, v1
80039818	sw     v0, $0004(sp)
8003981C	lw     v0, $0000(sp)
80039820	nop
80039824	addiu  v0, v0, $0001
80039828	sw     v0, $0000(sp)
8003982C	lw     v0, $0000(sp)

L39830:	; 80039830
80039830	lw     v0, $0000(sp)
80039834	nop
80039838	slti   v0, v0, $0002
8003983C	bne    v0, zero, loop39800 [$80039800]
////////////////////////////////



////////////////////////////////
// func3973c
V0 = w[8004aaf4];
A0 = V0 + A0 << 4;

[A0 + 8] = h((hu[A0 + 8] & ff0f) | (A1 << 4));

80039764	ori    v0, zero, $0001
80039768	sw     v0, $0004(sp)
8003976C	sw     zero, $0000(sp)
80039770	j      L397a8 [$800397a8]
80039774	nop

loop39778:	; 80039778
80039778	lw     v1, $0004(sp)
8003977C	nop
80039780	sll    v0, v1, $01
80039784	addu   v0, v0, v1
80039788	sll    v0, v0, $02
8003978C	addu   v0, v0, v1
80039790	sw     v0, $0004(sp)
80039794	lw     v0, $0000(sp)
80039798	nop
8003979C	addiu  v0, v0, $0001
800397A0	sw     v0, $0000(sp)
800397A4	lw     v0, $0000(sp)

L397a8:	; 800397A8
800397A8	lw     v0, $0000(sp)
800397AC	nop
800397B0	slti   v0, v0, $0002
800397B4	bne    v0, zero, loop39778 [$80039778]
////////////////////////////////



////////////////////////////////
// func399d0
A3 = 0;
if (A2 != 3)
{
    V0 = A2 == 7;
    A3 = V0 << 5;
}

V0 = w[8004aaf4];
V1 = A0 << 4;
V1 = V1 + V0;

[V1 + a] = h((hu[V1 + a] & ffc0) | A1 | A3);


80039A0C	ori    v0, zero, $0001
80039A14	sw     v0, $0004(sp)
80039A18	sw     zero, $0000(sp)
80039A1C	j      L39a54 [$80039a54]
80039A20	nop

loop39a24:	; 80039A24
80039A24	lw     v1, $0004(sp)
80039A28	nop
80039A2C	sll    v0, v1, $01
80039A30	addu   v0, v0, v1
80039A34	sll    v0, v0, $02
80039A38	addu   v0, v0, v1
80039A3C	sw     v0, $0004(sp)
80039A40	lw     v0, $0000(sp)
80039A44	nop
80039A48	addiu  v0, v0, $0001
80039A4C	sw     v0, $0000(sp)
80039A50	lw     v0, $0000(sp)

L39a54:	; 80039A54
80039A54	lw     v0, $0000(sp)
80039A58	nop
80039A5C	slti   v0, v0, $0002
80039A60	bne    v0, zero, loop39a24 [$80039a24]
////////////////////////////////



////////////////////////////////
// func39850
A0 = A0 << 4;

A2 = A2 == 5;
A2 = A2 << 7;

V0 = w[8004aaf4];
[V0 + A0 + 8] = h((hu[V0 + A0 + 8] & ff) | ((A1 | A2) << 8));

80039888	ori    v0, zero, $0001
8003988C	sw     v0, $0004(sp)
80039890	sw     zero, $0000(sp)
80039894	j      L398cc [$800398cc]

loop3989c:	; 8003989C
    8003989C	lw     v1, $0004(sp)
    800398A0	nop
    800398A4	sll    v0, v1, $01
    800398A8	addu   v0, v0, v1
    800398AC	sll    v0, v0, $02
    800398B0	addu   v0, v0, v1
    800398B4	sw     v0, $0004(sp)
    800398B8	lw     v0, $0000(sp)
    800398BC	nop
    800398C0	addiu  v0, v0, $0001
    800398C4	sw     v0, $0000(sp)
    800398C8	lw     v0, $0000(sp)

    L398cc:	; 800398CC
    800398CC	lw     v0, $0000(sp)
    800398D0	nop
    800398D4	slti   v0, v0, $0002
800398D8	bne    v0, zero, loop3989c [$8003989c]
////////////////////////////////



////////////////////////////////
// func398ec
V1 = A0 << 3;

if (A2 == 1)
{
    A3 = 0; // sustain linear increase
}
else if (A2 == 5)
{
    A3 = 200; // sustain exponential increase
}
else if (A2 == 7)
{
    A3 = 300; // sustain exponential discrease
}
else
{
    A3 = 100; // sustain linear discrease
}

V0 = w[8004aaf4];
V1 = V0 + V1 * 2;

V0 = A1 | A3;
A0 = [V1 + a];
V0 = V0 << 6;
A0 = (A0 & 3f) | V0; // leave release as is and add sustain
[V1 + a] = h(A0);



80039968	ori    v0, zero, $0001
80039970	sw     v0, $0004(sp)
80039974	sw     zero, $0000(sp)
80039978	j      L399b0 [$800399b0]
8003997C	nop

loop39980:	; 80039980
    80039980	lw     v1, $0004(sp)
    80039984	nop
    80039988	sll    v0, v1, $01
    8003998C	addu   v0, v0, v1
    80039990	sll    v0, v0, $02
    80039994	addu   v0, v0, v1
    80039998	sw     v0, $0004(sp)
    8003999C	lw     v0, $0000(sp)
    800399A0	nop
    800399A4	addiu  v0, v0, $0001
    800399A8	sw     v0, $0000(sp)
    800399AC	lw     v0, $0000(sp)

    L399b0:	; 800399B0
    800399B0	lw     v0, $0000(sp)
    800399B4	nop
    800399B8	slti   v0, v0, $0002
800399BC	bne    v0, zero, loop39980 [$80039980]
////////////////////////////////



////////////////////////////////
// func393c8
800393CC	andi   a1, a1, $7fff
800393D0	andi   a2, a2, $7fff

800393D4	lui    v0, $8005
800393D8	lw     v0, $aaf4(v0)

800393DC	sll    a0, a0, $04
800393E0	addu   a0, a0, v0
800393E4	ori    v0, zero, $0001
800393E8	sh     a1, $0000(a0) // volume left
800393EC	sh     a2, $0002(a0) // volume right

800393F0	sw     v0, $0004(sp)

func393f4:	; 800393F4
800393F4	sw     zero, $0000(sp)
800393F8	j      L39430 [$80039430]
800393FC	nop

loop39400:	; 80039400
80039400	lw     v1, $0004(sp)
80039404	nop
80039408	sll    v0, v1, $01
8003940C	addu   v0, v0, v1
80039410	sll    v0, v0, $02
80039414	addu   v0, v0, v1
80039418	sw     v0, $0004(sp)
8003941C	lw     v0, $0000(sp)
80039420	nop
80039424	addiu  v0, v0, $0001
80039428	sw     v0, $0000(sp)
8003942C	lw     v0, $0000(sp)

L39430:	; 80039430
80039430	lw     v0, $0000(sp)
80039434	nop
80039438	slti   v0, v0, $0002
8003943C	bne    v0, zero, loop39400 [$80039400]
////////////////////////////////



////////////////////////////////
// func395c8
A0 = A0 << 3;
A0 = w[8004aaf4] + A0;

[A0 + 4] = h(A1);

[SP + 0] = w(0);
[SP + 4] = w(1);

800395EC	j      L39624 [$80039624]

loop395f4:	; 800395F4
    800395F4	lw     v1, $0004(sp)
    800395F8	nop
    800395FC	sll    v0, v1, $01
    80039600	addu   v0, v0, v1
    80039604	sll    v0, v0, $02
    80039608	addu   v0, v0, v1
    8003960C	sw     v0, $0004(sp)
    80039610	lw     v0, $0000(sp)
    80039614	nop
    80039618	addiu  v0, v0, $0001
    8003961C	sw     v0, $0000(sp)
    80039620	lw     v0, $0000(sp)

    L39624:	; 80039624
    80039624	lw     v0, $0000(sp)
    80039628	nop
    8003962C	slti   v0, v0, $0002
80039630	bne    v0, zero, loop395f4 [$800395f4]
////////////////////////////////



////////////////////////////////
// func396c0
A0 = A0 << 3;
A0 = A0 | 7; // add loop address
func36de0;

800396D4	ori    v0, zero, $0001
800396D8	sw     v0, $0014(sp)
800396DC	sw     zero, $0010(sp)
800396E0	j      L39718 [$80039718]
800396E4	nop

loop396e8:	; 800396E8
800396E8	lw     v1, $0014(sp)
800396EC	nop
800396F0	sll    v0, v1, $01
800396F4	addu   v0, v0, v1
800396F8	sll    v0, v0, $02
800396FC	addu   v0, v0, v1
80039700	sw     v0, $0014(sp)
80039704	lw     v0, $0010(sp)
80039708	nop
8003970C	addiu  v0, v0, $0001
80039710	sw     v0, $0010(sp)
80039714	lw     v0, $0010(sp)

L39718:	; 80039718
80039718	lw     v0, $0010(sp)
8003971C	nop
80039720	slti   v0, v0, $0002
80039724	bne    v0, zero, loop396e8 [$800396e8]
80039728	nop
////////////////////////////////



////////////////////////////////
// func39010
A2 = c8; // volume left for channel 0x19
A3 = c9; // volume right for channel 0x19
func37988;
////////////////////////////////



////////////////////////////////
// func37964
A2 = ca; // pitch for chanel 0x19
A3 = cb; // start address for chanel 0x19
func37988;
////////////////////////////////



////////////////////////////////
// func388c4
A2 = cc; // attack/decay/sustain level for chanel 0x19
A3 = cd; // sustain rate, release rate for chanel 0x19
func37988;
////////////////////////////////



////////////////////////////////
// func37988
T1 = A0;
T0 = A1;

if (w[8004aaec] & 1)
{
    A0 = 80077da0;
}
else
{
    A0 = w[8004aaf4]; // spu address
}

T2 = hu[A0 + A2 * 2] | (hu[A0 + A3 * 2] & ff) << 10;

if (T1 != 0)
{
    if (T1 != 1)
    {
        return T2 & 00ffffff;
    }

    if (w[8004aaec] & 1)
    {
        [80077da0 + A2 * 2] = h(hu[80077da0 + A2 * 2] | T0);
        [80077da0 + A3 * 2] = h(hu[80077da0 + A3 * 2] | ((T0 >> 10) & ff));
        [8004a6b8] = w(w[8004a6b8] | 1 << ((A2 - c6) / 2));
    }
    else
    {
        A1 = w[8004aaf4]; // spu address
        [A1 + A2 * 2] = h(hu[A1 + A2 * 2] | T0);
        [A1 + A3 * 2] = h(hu[A1 + A3 * 2] | (T0 >> 10) & ff);
    }

    T2 = T2 | (T0 & 00ffffff);
}
else
{
    if (w[8004aaec] & 1)
    {
        [80077da0 + A2 * 2] = h(hu[80077da0 + A2 * 2] & (0 NOR T0));
        [80077da0 + A3 / 2] = h(hu[80077da0 + A3 / 2] & (0 NOR ((T0 >> 10) & ff)));
        [8004a6b8] = w(w[8004a6b8] | (1 << ((A2 - c6) / 2)));
    }
    else
    {
        A1 = w[8004aaf4]; // spu address
        [A1 + A2 * 2] = h(hu[A1 + A2 * 2] & (0 NOR T0));
        [A1 + A3 / 2] = h(hu[A1 + A3 / 2] & (0 NOR ((T0 >> 10) & ff)));
    }

    T2 = T2 & (0 NOR (T0 & 00ffffff));
}

return T2 & 00ffffff;
////////////////////////////////



////////////////////////////////
// func39644
A0 = A0 << 8;
A0 = A0 | 3; // add attack address
func36de0;

[SP + 10] = w(0);
[SP + 14] = w(1);

80039664	j      L3969c [$8003969c]

loop3966c:	; 8003966C
    [SP + 14] = w(w[SP + 14] * d)
    [SP + 10] = w(w[SP + 10] + 1);

    L3969c:	; 8003969C
    V0 = w[SP + 10] < 2;
800396A8	bne    v0, zero, loop3966c [$8003966c]
////////////////////////////////



////////////////////////////////
// func36de0
V0 = w[8004ab18];

A2 = A0;

if (V0 != 0)
{
    80036DF4	lui    a0, $8005
    80036DF8	lw     a0, $ab20(a0)
    80036DFC	nop
    80036E00	divu   a1, a0
    80036E10	mfhi   v0
    if (V0 != 0)
    {
        80036E20	lui    v0, $8005
        80036E24	lw     v0, $ab24(v0)
        80036E28	addu   a1, a1, a0
        80036E2C	nor    v0, zero, v0
        80036E30	and    a1, a1, v0
    }
}

A3 = A1 >> w[8004ab1c]; // divide by 8

80036E44	addiu  v0, zero, $fffe (=-$2)
80036E48	beq    a2, v0, L36e60 [$80036e60]
80036E4C	addiu  v0, zero, $ffff (=-$1)
80036E50	bne    a2, v0, L36e68 [$80036e68]
80036E54	addu   v0, a1, zero
80036E58	j      L36e7c [$80036e7c]
80036E5C	andi   v0, a3, $ffff

L36e60:	; 80036E60
80036E60	j      L36e7c [$80036e7c]
80036E64	addu   v0, a1, zero

L36e68:	; 80036E68
A0 = w[8004aaf4];
[A0 + A2 * 2] = h(A3); // set loop and attack address


L36e7c:	; 80036E7C
////////////////////////////////
