////////////////////////////////
// contain move and button update, animation handler and many others
// model new structure initing also here
// funca2314

[SP + 10] = w(800a0024);
[SP + 14] = w(800a0028);
[SP + 18] = w(800a002c);
[SP + 1c] = w(800a0030);
[SP + 20] = w(800a0034);
[SP + 24] = w(800a0038);
[SP + 28] = w(800a003c);
[SP + 2c] = w(800a0040);
[SP + 30] = w(800a0044);
[SP + 34] = w(800a0048);
[SP + 38] = w(800a004c);
[SP + 3c] = w(800a0050);

[8007eb90] = w(a0);
[8007eb94] = w(78);

if (h[800965ec] != 5 && h[800965ec] != d)
{
    funcaa930; // init models and their textures
}



V0 = w[8009a044];
A0 = w[V0] + 4;
[800e4274] = w(A0); // offset to walkmesh block
V0 = w[V0];
[80114458] = w(A0 + hu[V0] * 18); // walkmesh triangle access block

if (h[800965ec] != 5 && h[800965ec] != 2 && h[800965ec] != d)
{
    funca5fb4; // walkmesh related
}



A0 = 800e9704; // draft 1st and 2nd layer
A1 = 800f3344; // draft 3rd and 4th layer
A2 = 800f5b44; // animation packets data
A3 = 800f72cc;
funca3020; // we read dat background data here

A0 = 80100fa0;
A1 = 8010abe0;
A2 = 8010d3e0;
A3 = 8010eb68;
funca3020; // we read dat background data here

A0 = 800e4df0;
funcab4ac; // init some bebug lines buffer 1

A0 = 800fc68c;
funcab4ac; // init some bebug lines buffer 2

S3 = 1;
S2 = 8009abf4;
[80114488] = h(0);
[801142c8] = h(0);
[800e4d44] = h(0);
[80071c0c] = b(0);
[800965e8] = h(0);

La25bc:	; 800A25BC
    V0 = S3 << 10;
    if (V0 == 0)
    {
        [80075dec] = h(hu[80075dec] + 1);
    }

    [80075dec] = h(hu[80075dec] + 1);

    A2 = hu[80075dec];
    V1 = h[80075dec];
    A1 = 1000;
    S1 = 800e4df0 + V1 * 1789c;
    A0 = S1;
    [S2] = b(A2);
    800A2658	jal    func44244 [$80044244]

    800A2660	lui    s0, $0001
    800A2664	ori    s0, s0, $748c
    800A2668	addu   s0, s1, s0
    800A266C	addu   a0, s0, zero
    800A2670	jal    func44244 [$80044244]
    800A2674	ori    a1, zero, $0001
    800A2678	jal    funcab2b4 [$800ab2b4]
    800A267C	nop

    A0 = 80071e38; // screen scroll X
    A1 = 80071e3c; // screen scroll Y
    funca2f78;

    800A2698	lui    v1, $8007
    800A269C	lw     v1, $5d00(v1)
    800A26A0	nop
    800A26A4	lhu    v1, $0008(v1)
    800A26A8	addu   a0, s0, zero
    800A26AC	lui    at, $8011
    800A26B0	sw     v0, $4454(at)
    800A26B8	sh     v1, $0088(s2)
    funcba65c; // script update here

    [800965e0] = h(hu[S2 + 2a]);

    funca4430; // init screen movement
    funca496c; // make screen movement

    A0 = 8009abf4 + 8a;
    field_update_shaking;

    A0 = 8009abf4 + 98;
    field_update_shaking;


    A0 = S1;
    funca4bec;

    A0 = 80074ea4 + h[800965e0] * 84; // PC data
    A1 = w[800716c4] + 38; // sector 5 triggers + 38 (triggers itself)
    field_check_and_set_load_background_in_advance;

    if ((w[8009abf4 + 68] & 0000090f) == 0000090f) // reset game if all shifts and start + select pressed
    {
        [8009abf4 + 1] = b(a);
        800A273C	jal    func35658 [$80035658]

        field_stop_load_background_in_advance;
        return;
    }

    if (bu[8009abf4 + 1] == 1)
    {
        return;
    }

    if (bu[8009abf4 + 1] == c)
    {
        field_stop_load_background_in_advance;
        return;
    }

    if (bu[8009abf4 + 1] == d)
    {
        [8009c560] = h(c);
        field_stop_load_background_in_advance;
        return;
    }

    if( bu[8009abf4 + 1] == 19 )
    {
        [8009c560] = h(10);
        field_stop_load_background_in_advance;
        return;
    }

    V1 = bu[8009abf4 + 1];

    if( V1 == f || V1 == 10 || V1 == 11 || V1 == 15 || V1 == 16 || V1 == 17 || V1 == 18 )
    {
        [8009c560] = h(d);
        field_stop_load_background_in_advance;
        return;
    }

    if( V1 == 6 || V1 == 7 || V1 == 8 || V1 == 9 || V1 == e || V1 == 12 || V1 == 13 )
    {
        [8009c560] = h(5);
        field_stop_load_background_in_advance;
        return;
    }

    if( ( w[80114454] & 10 ) && ( bu[S2 + 34] == 0 ) && ( hu[800e4d44] == 0 ) && ( hu[80114488] == 0 ) )
    {
        [8009c560] = h(5);
        [S2 + 1] = b(9);
        [S2 + 2] = h(0);
        field_stop_load_background_in_advance;
        return;
    }

    if (bu[8009abf4 + 1] == 5 || bu[8009abf4 + 1] == 1a)
    {
        field_stop_load_background_in_advance;
        return;
    }

    if( bu[8009abf4 + 1] == 2 )
    {
        V1 = h[800965e0]; // manual move entity

        V0 = w[80074ea4 + V1 * 84 + c];
        if (V0 < 0)
        {
            V0 = V0 & fff;
        }
        [8009abf4 + 4] = h(V0 >> c);

        V0 = w[80074ea4 + V1 * 84 + 10];
        if (V0 < 0)
        {
            V0 = V0 & fff;
        }
        [8009abf4 + 6] = h(V0 >> c);

        [8009c560] = h(2);
        [8009abf4 + 22] = h(hu[80074ea4 + V1 * 84 + 72]);

        field_stop_load_background_in_advance;
        return;
    }

    A0 = w[80114454];
    handle_update; // update move/turns/scroll

    V0 = h[800965e0]; // manual move entity
    A0 = 80074ea4 + V0 * 84 + 0;
    A1 = 8007e7ac;
    move_talk_to_line;

    // check talk
    funca8304;

    if ((hu[80114488] == 0) || (w[8009a060] == 1))
    {
        A0 = S1;
        funca364c; // update background drafts
    }

    A0 = S1;
    funcaab24; // update models (animations drafts and kawai)

    funcab728;

    A0 = S1;
    A1 = S1 + 1749c;
    A2 = w[80071e40];
    A3 = S1 + 17490;
    800A29E4	jal    funcab5e8 [$800ab5e8]

    800A29EC	addu   a0, s1, zero
    800A29F0	lui    a2, $8007
    800A29F4	lw     a2, $16c4(a2)
    800A29F8	lui    a1, $8007
    800A29FC	lw     a1, $1e40(a1)
    800A2A00	jal    funcabfe8 [$800abfe8]
    800A2A04	addiu  a2, a2, $0038
    800A2A08	jal    func138ec [$800138ec]
    800A2A0C	nop
    800A2A10	jal    func3cedc [$8003cedc]
    800A2A14	ori    a0, zero, $0001
    800A2A18	lui    at, $8011
    800A2A1C	sw     v0, $4478(at)

    loopa2a20:	; 800A2A20
        A0 = 1;
        800A2A20	jal    func43dd8 [$80043dd8]
    800A2A28	bne    v0, zero, loopa2a20 [$800a2a20]

    A0 = 1;
    800A2A30	jal    func3cedc [$8003cedc]

    800A2A38	lui    v1, $8011
    800A2A3C	lhu    v1, $4488(v1)
    800A2A40	lui    at, $8011
    800A2A44	sw     v0, $447c(at)
    800A2A48	beq    v1, zero, La2a68 [$800a2a68]
    800A2A4C	ori    a0, zero, $0002
    800A2A50	lui    v1, $8009
    800A2A54	lw     v1, $65e4(v1)
    800A2A58	ori    v0, zero, $0001
    800A2A5C	beq    v1, v0, La2a68 [$800a2a68]
    800A2A60	nop
    800A2A64	ori    a0, zero, $0003

    La2a68:	; 800A2A68
    800A2A68	jal    func3cedc [$8003cedc]
    800A2A6C	nop
    800A2A70	sll    v0, s3, $10
    800A2A74	beq    v0, zero, La2a94 [$800a2a94]
    800A2A78	addiu  v0, s3, $ffff (=-$1)
    800A2A7C	addu   s3, v0, zero
    800A2A80	sll    v0, v0, $10
    800A2A84	bne    v0, zero, La2a94 [$800a2a94]
    800A2A88	nop
    800A2A8C	jal    func43d3c [$80043d3c]
    800A2A90	ori    a0, zero, $0001

    La2a94:	; 800A2A94
    A0 = 1;
    800A2A94	jal    func43938 [$80043938]

    if( hu[80114488] == 0 )
    {
        if( h[801142c8] == 0 )
        {
            [8007eb79 + h[80075dec] * 14] = b(0);
        }
        else
        {
            [801142c8] = h(0);
        }
    }

    V0 = h[80075dec];
    800A2B18	sll    a0, v0, $02
    800A2B1C	addu   a0, a0, v0
    800A2B20	sll    a0, a0, $02
    800A2B24	lui    v0, $8008
    800A2B28	addiu  v0, v0, $eb68 (=-$1498)
    800A2B2C	jal    func444ac [$800444ac]
    800A2B30	addu   a0, a0, v0
    800A2B34	lui    v0, $8007
    800A2B38	lhu    v0, $5dec(v0)
    800A2B3C	lui    s0, $8008
    800A2B40	addiu  s0, s0, $eaac (=-$1554)
    800A2B44	sll    v0, v0, $10
    800A2B48	sra    v0, v0, $10
    800A2B4C	sll    a0, v0, $01
    800A2B50	addu   a0, a0, v0
    800A2B54	sll    a0, a0, $03
    800A2B58	subu   a0, a0, v0
    800A2B5C	sll    a0, a0, $02
    800A2B60	jal    func443b0 [$800443b0]
    800A2B64	addu   a0, a0, s0
    800A2B68	lui    v0, $8011
    800A2B6C	lhu    v0, $4488(v0)
    800A2B70	nop
    800A2B74	bne    v0, zero, La2bb0 [$800a2bb0]
    800A2B78	addu   a1, zero, zero
    800A2B7C	addu   a2, zero, zero
    800A2B80	lui    v0, $8007
    800A2B84	lhu    v0, $5dec(v0)
    800A2B88	addu   a3, zero, zero
    800A2B8C	sll    v0, v0, $10
    800A2B90	sra    v0, v0, $10
    800A2B94	sll    a0, v0, $01
    800A2B98	addu   a0, a0, v0
    800A2B9C	sll    a0, a0, $03
    800A2BA0	subu   a0, a0, v0
    800A2BA4	sll    a0, a0, $02
    800A2BA8	j      La2c48 [$800a2c48]
    800A2BAC	addu   a0, a0, s0

    La2bb0:	; 800A2BB0
    800A2BB0	lui    v0, $8007
    800A2BB4	lhu    v0, $5dec(v0)
    800A2BB8	nop
    800A2BBC	sll    v0, v0, $10
    800A2BC0	sra    v0, v0, $10
    800A2BC4	sll    v1, v0, $02
    800A2BC8	addu   v1, v1, v0
    800A2BCC	sll    v1, v1, $02
    800A2BD0	lui    at, $8008
    800A2BD4	addiu  at, at, $eb79 (=-$1487)
    800A2BD8	addu   at, at, v1
    800A2BDC	lbu    v0, $0000(at)
    800A2BE0	nop
    800A2BE4	bne    v0, zero, La2c18 [$800a2c18]
    800A2BE8	addu   a2, zero, zero
    800A2BEC	addiu  a0, sp, $0028
    800A2BF0	addu   a1, zero, zero
    800A2BF4	jal    func43f6c [$80043f6c]
    800A2BF8	addu   a3, zero, zero
    800A2BFC	addiu  a0, sp, $0030
    800A2C00	addu   a1, zero, zero
    800A2C04	addu   a2, zero, zero
    800A2C08	jal    func43f6c [$80043f6c]
    800A2C0C	addu   a3, zero, zero
    800A2C10	j      La2c3c [$800a2c3c]
    800A2C14	addiu  a0, sp, $0038

    La2c18:	; 800A2C18
    800A2C18	addiu  a0, sp, $0010
    800A2C1C	jal    func43f6c [$80043f6c]
    800A2C20	addu   a3, zero, zero
    800A2C24	addiu  a0, sp, $0018
    800A2C28	addu   a1, zero, zero
    800A2C2C	addu   a2, zero, zero
    800A2C30	jal    func43f6c [$80043f6c]
    800A2C34	addu   a3, zero, zero
    800A2C38	addiu  a0, sp, $0020

    La2c3c:	; 800A2C3C
    800A2C3C	addu   a1, zero, zero
    800A2C40	addu   a2, zero, zero
    800A2C44	addu   a3, zero, zero

    La2c48:	; 800A2C48
    800A2C48	jal    func43f6c [$80043f6c]

    [8007ebd8] = w(8007eb68 + h[80075dec] * 14); // 80075dec - screen buffer index
    [8007ebd0] = w(80113f2c + h[80075dec] * 5c); // 80075dec - screen buffer index

    800A2CB8	jal    funcab310 [$800ab310]

    V0 = bu[8009abf4 + 38];
    if (V0 == 0)
    {
        800A2CD8	addiu  a0, s1, $4190
        800A2CD4	jal    func4433c [$8004433c]

        800A2CE0	addiu  a0, s1, $3ffc
        800A2CDC	jal    func4433c [$8004433c]

        800A2CE8	addiu  a0, s1, $418c
        800A2CE4	jal    func4433c [$8004433c]

        V0 = hu[8009abf4 + 4c]; // read fade type
        if (V0 != 0)
        {
            800A2D00	lui    a0, $8007
            800A2D04	lhu    a0, $5dec(a0)
            800A2D08	lui    v0, $8008
            800A2D0C	addiu  v0, v0, $e7a0 (=-$1860)
            800A2D10	sll    a0, a0, $10
            800A2D14	sra    a0, a0, $0e
            800A2D18	jal    func4433c [$8004433c]
            800A2D1C	addu   a0, a0, v0
            800A2D20	lui    a0, $0001
        }
    }

    800A2CFC	lui    a0, $0001
    800A2D24	ori    a0, a0, $748c
    800A2D28	jal    func4433c [$8004433c]
    800A2D2C	addu   a0, s1, a0
800A2D30	j      La25bc [$800a25bc]
////////////////////////////////



////////////////////////////////
// funca16cc
800A16CC	addiu  sp, sp, $ffb8 (=-$48)
800A16D0	sw     ra, $0044(sp)
800A16D4	sw     fp, $0040(sp)
800A16D8	sw     s7, $003c(sp)
800A16DC	sw     s6, $0038(sp)
800A16E0	sw     s5, $0034(sp)
800A16E4	sw     s4, $0030(sp)
800A16E8	sw     s3, $002c(sp)
800A16EC	sw     s2, $0028(sp)
800A16F0	sw     s1, $0024(sp)
800A16F4	sw     s0, $0020(sp)
800A16F8	lui    a1, $800a
800A16FC	addiu  a1, a1, $0000
800A1700	lwl    v0, $0003(a1)
800A1704	lwr    v0, $0000(a1)
800A1708	lwl    v1, $0007(a1)
800A170C	lwr    v1, $0004(a1)
800A1710	swl    v0, $001b(sp)
800A1714	swr    v0, $0018(sp)
800A1718	swl    v1, $001f(sp)
800A171C	swr    v1, $001c(sp)
800A1720	lui    s4, $800f
800A1724	addiu  s4, s4, $8f7c (=-$7084)
800A1728	addu   a0, s4, zero
800A172C	jal    func44244 [$80044244]
800A1730	ori    a1, zero, $0001
800A1734	lui    s7, $8010
800A1738	addiu  s7, s7, $0818
800A173C	addu   a0, s7, zero
800A1740	jal    func44244 [$80044244]
800A1744	ori    a1, zero, $0001
800A1748	addiu  s1, s4, $0008
800A174C	addu   a0, s1, zero
800A1750	lui    s0, $8008
800A1754	addiu  s0, s0, $eaac (=-$1554)
800A1758	jal    func44ac0 [$80044ac0]
800A175C	addu   a1, s0, zero
800A1760	lui    s3, $8010
800A1764	addiu  s3, s3, $0820
800A1768	addu   a0, s3, zero
800A176C	jal    func44ac0 [$80044ac0]
800A1770	addiu  a1, s0, $005c
800A1774	lui    s2, $00ff
800A1778	ori    s2, s2, $ffff
800A177C	lui    fp, $8011
800A1780	addiu  fp, fp, $3f2c
800A1784	addu   a0, fp, zero
800A1788	addu   a1, zero, zero
800A178C	ori    a2, zero, $0008
800A1790	ori    a3, zero, $0140
800A1794	ori    s6, zero, $00e0
800A1798	lui    s5, $ff00
800A179C	and    s1, s1, s2
800A17A0	sw     s6, $0010(sp)
800A17A4	lw     t2, $0008(s4)
800A17A8	lw     t1, $0000(s4)
800A17AC	lw     t0, $0000(s3)
800A17B0	lw     v1, $0000(s7)
800A17B4	and    t2, t2, s5
800A17B8	and    v0, t1, s2
800A17BC	or     t2, t2, v0
800A17C0	and    t1, t1, s5
800A17C4	or     t1, t1, s1
800A17C8	and    t0, t0, s5
800A17CC	and    v0, v1, s2
800A17D0	or     t0, t0, v0
800A17D4	and    v1, v1, s5
800A17D8	and    v0, s3, s2
800A17DC	or     v1, v1, v0
800A17E0	sw     t2, $0008(s4)
800A17E4	sw     t1, $0000(s4)
800A17E8	sw     t0, $0000(s3)
800A17EC	jal    func43814 [$80043814]
800A17F0	sw     v1, $0000(s7)
800A17F4	lui    a0, $8011
800A17F8	addiu  a0, a0, $3f88
800A17FC	addu   a1, zero, zero
800A1800	ori    a2, zero, $00f0
800A1804	ori    a3, zero, $0140
800A1808	jal    func43814 [$80043814]
800A180C	sw     s6, $0010(sp)
800A1810	lui    s0, $8011
800A1814	addiu  s0, s0, $4154
800A1818	addu   a0, s0, zero
800A181C	addu   a1, zero, zero
800A1820	ori    a2, zero, $0008
800A1824	ori    a3, zero, $0140
800A1828	jal    func43814 [$80043814]
800A182C	sw     s6, $0010(sp)
800A1830	addiu  a0, s0, $005c
800A1834	addu   a1, zero, zero
800A1838	ori    a2, zero, $00f0
800A183C	ori    a3, zero, $0140
800A1840	jal    func43814 [$80043814]
800A1844	sw     s6, $0010(sp)
800A1848	lui    s0, $8011
800A184C	addiu  s0, s0, $420c
800A1850	addu   a0, s0, zero
800A1854	addu   a1, zero, zero
800A1858	ori    a2, zero, $0008
800A185C	ori    a3, zero, $0140
800A1860	jal    func43814 [$80043814]
800A1864	sw     s6, $0010(sp)
800A1868	addiu  a0, s0, $005c
800A186C	addu   a1, zero, zero
800A1870	ori    a2, zero, $00f0
800A1874	ori    a3, zero, $0140
800A1878	jal    func43814 [$80043814]
800A187C	sw     s6, $0010(sp)
800A1880	addiu  a0, s4, $0004
800A1884	ori    s1, zero, $0001
800A1888	lui    at, $8011
800A188C	sb     s1, $3f42(at)
800A1890	lui    at, $8011
800A1894	sb     s1, $3f9e(at)
800A1898	lui    at, $8011
800A189C	sb     s1, $416a(at)
800A18A0	lui    at, $8011
800A18A4	sb     s1, $41c6(at)
800A18A8	lui    at, $8011
800A18AC	sb     s1, $4222(at)
800A18B0	lui    at, $8011
800A18B4	sb     s1, $427e(at)
800A18B8	lui    at, $8011
800A18BC	sb     zero, $3f44(at)
800A18C0	lui    at, $8011
800A18C4	sb     zero, $3fa0(at)
800A18C8	lui    at, $8011
800A18CC	sb     zero, $416c(at)
800A18D0	lui    at, $8011
800A18D4	sb     zero, $41c8(at)
800A18D8	lui    at, $8011
800A18DC	sb     zero, $4224(at)
800A18E0	lui    at, $8011
800A18E4	sb     zero, $4280(at)
800A18E8	jal    func44244 [$80044244]
800A18EC	ori    a1, zero, $0001
800A18F0	lui    s7, $8010
800A18F4	addiu  s7, s7, $081c
800A18F8	addu   a0, s7, zero
800A18FC	jal    func44244 [$80044244]
800A1900	ori    a1, zero, $0001
800A1904	addiu  s0, s4, $0048
800A1908	addu   a0, s0, zero
800A190C	jal    func44ac0 [$80044ac0]
800A1910	addu   a1, fp, zero
800A1914	lui    s3, $8010
800A1918	addiu  s3, s3, $0860
800A191C	lui    a1, $8011
800A1920	addiu  a1, a1, $3f88
800A1924	jal    func44ac0 [$80044ac0]
800A1928	addu   a0, s3, zero
800A192C	lui    fp, $8011
800A1930	addiu  fp, fp, $3fe4
800A1934	addu   a0, fp, zero
800A1938	addu   a1, zero, zero
800A193C	ori    a2, zero, $0008
800A1940	ori    a3, zero, $0140
800A1944	and    s0, s0, s2
800A1948	sw     s6, $0010(sp)
800A194C	lw     t2, $0048(s4)
800A1950	lw     t1, $0004(s4)
800A1954	lw     t0, $0000(s3)
800A1958	lw     v1, $0000(s7)
800A195C	and    t2, t2, s5
800A1960	and    v0, t1, s2
800A1964	or     t2, t2, v0
800A1968	and    t1, t1, s5
800A196C	or     t1, t1, s0
800A1970	and    t0, t0, s5
800A1974	and    v0, v1, s2
800A1978	or     t0, t0, v0
800A197C	and    v1, v1, s5
800A1980	and    s2, s3, s2
800A1984	or     v1, v1, s2
800A1988	sw     t2, $0048(s4)
800A198C	sw     t1, $0004(s4)
800A1990	sw     t0, $0000(s3)
800A1994	jal    func43814 [$80043814]
800A1998	sw     v1, $0000(s7)
800A199C	addiu  a0, fp, $005c
800A19A0	addu   a1, zero, zero
800A19A4	ori    a2, zero, $00f0
800A19A8	ori    a3, zero, $0140
800A19AC	jal    func43814 [$80043814]
800A19B0	sw     s6, $0010(sp)
800A19B4	lui    s0, $8011
800A19B8	addiu  s0, s0, $409c
800A19BC	addu   a0, s0, zero
800A19C0	addu   a1, zero, zero
800A19C4	ori    a2, zero, $0008
800A19C8	ori    a3, zero, $0140
800A19CC	lui    at, $8011
800A19D0	sb     zero, $3ffc(at)
800A19D4	lui    at, $8011
800A19D8	sb     zero, $4058(at)
800A19DC	lui    at, $8011
800A19E0	sb     s1, $3ffa(at)
800A19E4	lui    at, $8011
800A19E8	sb     s1, $4056(at)
800A19EC	jal    func43814 [$80043814]
800A19F0	sw     s6, $0010(sp)
800A19F4	addiu  a0, s0, $005c
800A19F8	addu   a1, zero, zero
800A19FC	ori    a2, zero, $00f0
800A1A00	ori    a3, zero, $0140
800A1A04	jal    func43814 [$80043814]
800A1A08	sw     s6, $0010(sp)
800A1A0C	lui    at, $8011
800A1A10	sb     zero, $40b4(at)
800A1A14	lui    at, $8011
800A1A18	sb     zero, $4110(at)
800A1A1C	lui    at, $8011
800A1A20	sb     s1, $40b2(at)
800A1A24	lui    at, $8011
800A1A28	sb     s1, $410e(at)
800A1A2C	jal    func128b8 [$800128b8]
800A1A30	nop
800A1A34	lui    v0, $800a
800A1A38	addiu  v0, v0, $ac40 (=-$53c0)
800A1A3C	addiu  s0, sp, $0018
800A1A40	sh     zero, $0000(v0)
800A1A44	lui    v0, $8009
800A1A48	lhu    v0, $65ec(v0)
800A1A4C	ori    v1, zero, $0001
800A1A50	sll    v0, v0, $10
800A1A54	sra    v0, v0, $10
800A1A58	beq    v0, v1, La1ae0 [$800a1ae0]
800A1A5C	nop
800A1A60	lui    v0, $8009
800A1A64	lhu    v0, $65ec(v0)
800A1A68	ori    v1, zero, $0002
800A1A6C	sll    v0, v0, $10
800A1A70	sra    v0, v0, $10
800A1A74	beq    v0, v1, La1ae0 [$800a1ae0]
800A1A78	nop
800A1A7C	lui    v0, $8009
800A1A80	lhu    v0, $65ec(v0)
800A1A84	ori    v1, zero, $0003
800A1A88	sll    v0, v0, $10
800A1A8C	sra    v0, v0, $10
800A1A90	beq    v0, v1, La1ae0 [$800a1ae0]
800A1A94	nop
800A1A98	lui    v0, $8009
800A1A9C	lhu    v0, $65ec(v0)
800A1AA0	ori    v1, zero, $0005
800A1AA4	sll    v0, v0, $10
800A1AA8	sra    v0, v0, $10
800A1AAC	beq    v0, v1, La1ae0 [$800a1ae0]
800A1AB0	nop
800A1AB4	lui    v0, $8009
800A1AB8	lhu    v0, $65ec(v0)
800A1ABC	ori    v1, zero, $000d
800A1AC0	sll    v0, v0, $10
800A1AC4	sra    v0, v0, $10
800A1AC8	beq    v0, v1, La1ae0 [$800a1ae0]
800A1ACC	addu   a0, s0, zero
800A1AD0	addu   a1, zero, zero
800A1AD4	addu   a2, zero, zero
800A1AD8	jal    func43f6c [$80043f6c]
800A1ADC	addu   a3, zero, zero

La1ae0:	; 800A1AE0
800A1AE0	ori    s2, zero, $0001
800A1AE4	ori    s5, zero, $0003
800A1AE8	ori    s4, zero, $000d
800A1AEC	lui    s3, $800a
800A1AF0	addiu  s3, s3, $ac40 (=-$53c0)
800A1AF4	addiu  s1, s3, $ffb5 (=-$4b)

La1af8:	; 800A1AF8
800A1AF8	jal    funcab2ac [$800ab2ac]
800A1AFC	nop
800A1B08	lui    at, $8007
800A1B0C	sh     zero, $1a5c(at)
800A1B10	lui    at, $8009
800A1B14	sh     zero, $5dd0(at)

if (h[800965ec] == 1 || h[800965ec] == 3)
{
    800A1B44	lhu    v0, $0000(s3)
    800A1B48	nop
    800A1B4C	bne    v0, zero, La1b7c [$800a1b7c]
    800A1B50	nop
    800A1B54	jal    func129d0 [$800129d0]
    800A1B58	nop
    800A1B5C	sh     s5, $0000(s3)
    800A1B60	lui    at, $8007
    800A1B64	sb     s5, $1a58(at)
    800A1B68	sh     zero, $0002(s3)
    800A1B6C	lui    at, $8008
    800A1B70	sh     zero, $e768(at)
    800A1B74	lui    at, $8009
    800A1B78	sh     s2, $5dd4(at)
}

La1b7c:	; 800A1B7C
if (h[800965ec] != 5 && h[800965ec] != d)
{
    800A1BB0	lui    t0, $8011
    800A1BB4	ori    t0, t0, $4fe4
    800A1BB8	lui    a3, $8011
    800A1BBC	ori    a3, a3, $4fe8
    800A1BC0	lui    a2, $8011
    800A1BC4	ori    a2, a2, $4fec
    800A1BC8	lui    a1, $8011
    800A1BCC	ori    a1, a1, $4ff0
    800A1BD0	lui    a0, $8011
    800A1BD4	ori    a0, a0, $4ff4
    800A1BD8	lui    v1, $8011
    800A1BDC	ori    v1, v1, $4ff8
    800A1BE0	lui    v0, $8011
    800A1BE4	ori    v0, v0, $4ffc
    800A1BE8	lui    at, $8008
    800A1BEC	sw     t0, $eb64(at)
    800A1BF0	lui    at, $800a
    800A1BF4	sw     a3, $a044(at)
    800A1BF8	lui    at, $800a
    800A1BFC	sw     a2, $d848(at)
    800A1C00	lui    at, $8008
    800A1C04	sw     a1, $3578(at)
    800A1C08	lui    at, $800a
    800A1C0C	sw     a0, $ad28(at)
    800A1C10	lui    at, $800a
    800A1C14	sw     v1, $c55c(at)
    800A1C18	lui    at, $8007
    800A1C1C	sw     v0, $0784(at)
    // load mim and dat here
    funca1368;
}

if (h[800965ec] == 2 && h[800965ec] != d)
{
    800A1C44	lui    v0, $8008
    800A1C48	lbu    v0, $ebc8(v0)
    800A1C4C	lui    at, $8008
    800A1C50	sb     s2, $ebe0(at)
    800A1C54	bne    v0, s2, La1c78 [$800a1c78]
    800A1C58	nop
    800A1C5C	lui    at, $8008
    800A1C60	sb     zero, $ebc8(at)
    800A1C64	lui    at, $800a
    800A1C68	sb     zero, $c6d8(at)
    800A1C6C	lui    at, $8007
    800A1C70	sh     zero, $173c(at)
    800A1C74	sb     zero, $0000(s1)
}

La1c78:	; 800A1C78
    800A1C78	lui    v0, $8009
    800A1C7C	lhu    v0, $5dd4(v0)
800A1C84	bne    v0, zero, La1c78 [$800a1c78]

loopa1c8c:	; 800A1C8C
    A0 = 1;
    800A1C8C	jal    func43dd8 [$80043dd8]
800A1C94	bne    v0, zero, loopa1c8c [$800a1c8c]



800A1C9C	lui    v0, $8009
800A1CA0	lhu    v0, $65ec(v0)
800A1CA4	nop
800A1CA8	sll    v0, v0, $10
800A1CAC	sra    v0, v0, $10
800A1CB0	beq    v0, s4, La1cd4 [$800a1cd4]
800A1CB4	ori    v0, zero, $0010
800A1CB8	sh     s2, $0000(s3)
800A1CBC	sh     v0, $0004(s3)
800A1CC0	ori    v0, zero, $0100
800A1CC4	sh     v0, $0002(s3)
800A1CC8	sh     zero, $0006(s3)
800A1CCC	sh     zero, $0008(s3)
800A1CD0	sh     zero, $000a(s3)

La1cd4:	; 800A1CD4
800A1CD4	lui    v0, $8009
800A1CD8	lhu    v0, $65ec(v0)
800A1CDC	nop
800A1CE0	beq    v0, zero, La1dc8 [$800a1dc8]
800A1CE4	nop
800A1CE8	lui    v0, $8009
800A1CEC	lhu    v0, $65ec(v0)
800A1CF0	nop
800A1CF4	sll    v0, v0, $10
800A1CF8	sra    v0, v0, $10
800A1CFC	beq    v0, s2, La1dc8 [$800a1dc8]
800A1D00	nop
800A1D04	lui    v0, $8009
800A1D08	lhu    v0, $65ec(v0)
800A1D0C	nop
800A1D10	sll    v0, v0, $10
800A1D14	sra    v0, v0, $10
800A1D18	beq    v0, s5, La1dc8 [$800a1dc8]
800A1D1C	nop
800A1D20	lui    v0, $8009
800A1D24	lhu    v0, $65ec(v0)
800A1D28	ori    v1, zero, $0006
800A1D2C	sll    v0, v0, $10
800A1D30	sra    v0, v0, $10
800A1D34	beq    v0, v1, La1dc8 [$800a1dc8]
800A1D38	nop
800A1D3C	lui    v0, $8009
800A1D40	lhu    v0, $65ec(v0)
800A1D44	ori    v1, zero, $0008
800A1D48	sll    v0, v0, $10
800A1D4C	sra    v0, v0, $10
800A1D50	beq    v0, v1, La1dc8 [$800a1dc8]
800A1D54	nop
800A1D58	lui    v0, $8009
800A1D5C	lhu    v0, $65ec(v0)
800A1D60	ori    v1, zero, $0007
800A1D64	sll    v0, v0, $10
800A1D68	sra    v0, v0, $10
800A1D6C	beq    v0, v1, La1dc8 [$800a1dc8]
800A1D70	nop
800A1D74	lui    v0, $8009
800A1D78	lhu    v0, $65ec(v0)
800A1D7C	ori    v1, zero, $0009
800A1D80	sll    v0, v0, $10
800A1D84	sra    v0, v0, $10
800A1D88	beq    v0, v1, La1dc8 [$800a1dc8]
800A1D8C	nop
800A1D90	lui    v0, $8009
800A1D94	lhu    v0, $65ec(v0)
800A1D98	ori    v1, zero, $000b
800A1D9C	sll    v0, v0, $10
800A1DA0	sra    v0, v0, $10
800A1DA4	beq    v0, v1, La1dc8 [$800a1dc8]
800A1DA8	nop
800A1DAC	lui    v0, $8009
800A1DB0	lhu    v0, $65ec(v0)
800A1DB4	ori    v1, zero, $000a
800A1DB8	sll    v0, v0, $10
800A1DBC	sra    v0, v0, $10
800A1DC0	bne    v0, v1, La1ee8 [$800a1ee8]
800A1DC4	ori    v0, zero, $0002

La1dc8:	; 800A1DC8
800A1DC8	lui    a0, $800a
800A1DCC	addiu  a0, a0, $ac9a (=-$5366)
800A1DD0	lui    v1, $8007
800A1DD4	lw     v1, $16c4(v1)
800A1DD8	ori    v0, zero, $0fff
800A1DDC	sh     zero, $0000(a0)
800A1DE0	lui    at, $800a
800A1DE4	sh     zero, $ac9c(at)
800A1DE8	lui    at, $800a
800A1DEC	sh     zero, $ac9e(at)
800A1DF0	lui    at, $800a
800A1DF4	sh     zero, $aca0(at)
800A1DF8	lui    at, $800a
800A1DFC	sh     s2, $aca2(at)
800A1E00	lui    at, $800a
800A1E04	sh     v0, $aca4(at)
800A1E08	lhu    v0, $000a(v1)
800A1E0C	lui    v1, $8008
800A1E10	lw     v1, $eb64(v1)
[8009a100] = h(0);
[80071e38] = h(0);
[80071e3c] = h(0);

800A1E2C	lui    at, $800a
800A1E30	sh     v0, $ac0a(at)
// we read here something from extracted dat
800A1E34	lw     a2, $0000(v1)
800A1E38	lui    a1, $8007
800A1E3C	addiu  a1, a1, $4ea4
800A1E40	jal    funcba534 [$800ba534]
800A1E44	addiu  a0, a0, $ff5a (=-$a6)
800A1E48	lui    v0, $800a
800A1E4C	lhu    v0, $ac1e(v0)
800A1E50	nop
800A1E54	sll    v0, v0, $10
800A1E58	sra    v0, v0, $10
800A1E5C	sll    v1, v0, $05
800A1E60	addu   v1, v1, v0
800A1E64	lui    v0, $800a
800A1E68	lhu    v0, $ac18(v0)
800A1E6C	sll    v1, v1, $02
800A1E70	lui    at, $8007
800A1E74	addiu  at, at, $4edc
800A1E78	addu   at, at, v1
800A1E7C	sb     v0, $0000(at)
800A1E80	lui    v0, $800a
800A1E84	lbu    v0, $d70b(v0)
800A1E88	nop
800A1E8C	andi   v0, v0, $0080
800A1E90	bne    v0, zero, La1ea8 [$800a1ea8]
800A1E94	addiu  a0, zero, $ffff (=-$1)
800A1E98	lui    at, $800e
800A1E9C	sb     zero, $48d8(at)
800A1EA0	j      La1eb4 [$800a1eb4]
800A1EA4	nop

La1ea8:	; 800A1EA8
800A1EA8	ori    v0, zero, $00ff
800A1EAC	lui    at, $800e
800A1EB0	sb     v0, $48d8(at)

La1eb4:	; 800A1EB4
800A1EB4	ori    v1, zero, $000f
800A1EB8	lui    v0, $800a
800A1EBC	addiu  v0, v0, $a057 (=-$5fa9)

loopa1ec0:	; 800A1EC0
800A1EC0	sb     a0, $0000(v0)
800A1EC4	addiu  v1, v1, $ffff (=-$1)
800A1EC8	bgez   v1, loopa1ec0 [$800a1ec0]
800A1ECC	addiu  v0, v0, $ffff (=-$1)

A0 = w[800716c4] + 158; // offset to sector 5 triggers
field_init_triggered_background_state;

800A1EE0	j      La1ef4 [$800a1ef4]
800A1EE4	nop

La1ee8:	; 800A1EE8
800A1EE8	lui    v1, $800a
800A1EEC	addiu  v1, v1, $ac1a (=-$53e6)
800A1EF0	sh     v0, $0000(v1)

La1ef4:	; 800A1EF4
800A1EF4	jal    funcbb1b4 [$800bb1b4]

A0 = 8007e7ac;
line_clear_entity_in_line;

800A1F0C	lui    a0, $800f
800A1F10	addiu  a0, a0, $8df0 (=-$7210)
800A1F14	lui    at, $8007
800A1F18	sb     zero, $16d0(at)
800A1F1C	jal    funcabf0c [$800abf0c]
800A1F20	addiu  a1, a0, $0180
800A1F24	lui    a0, $8010
800A1F28	addiu  a0, a0, $068c
800A1F2C	lui    a1, $8010
800A1F30	addiu  a1, a1, $080c
800A1F34	jal    funcabf0c [$800abf0c]
800A1F38	nop

if (h[800965ec] != 5 && h[800965ec] != d)
{
    A0 = 0;
    A1 = 80128000;
    funca2d5c; // load mim to vram and init struct about it.
}

if (h[800965ec] == 2)
{
    [8009a000] = h(f5);
    system_execute_AKAO;

    [8009a000] = h(18);
    [8009a004] = w(w[8009ac3c]);
    [8009a008] = w(4);
    system_execute_AKAO;
}



funca2314; // main game



loopa1fe4:	; 800A1FE4
    A0 = 1;
    800A1FE4	jal    func43dd8 [$80043dd8]
800A1FEC	bne    v0, zero, loopa1fe4 [$800a1fe4]



800A1FF4	jal    func3cedc [$8003cedc]
800A1FF8	ori    a0, zero, $0001
800A1FFC	lui    v0, $8007
800A2000	lhu    v0, $5dec(v0)
800A2004	lui    v1, $8008
800A2008	addiu  v1, v1, $eb79 (=-$1487)
800A200C	sb     zero, $0000(v1)
800A2010	addiu  v1, v1, $ffef (=-$11)
800A2014	lui    at, $8008
800A2018	sb     zero, $eb8d(at)
800A201C	sll    v0, v0, $10
800A2020	sra    v0, v0, $10
800A2024	sll    a0, v0, $02
800A2028	addu   a0, a0, v0
800A202C	sll    a0, a0, $02
800A2030	jal    func444ac [$800444ac]
800A2034	addu   a0, a0, v1
800A2038	lui    v0, $8007
800A203C	lhu    v0, $5dec(v0)
800A2040	nop
800A2044	sll    v0, v0, $10
800A2048	sra    v0, v0, $10
800A204C	sll    a0, v0, $01
800A2050	addu   a0, a0, v0
800A2054	sll    a0, a0, $03
800A2058	subu   a0, a0, v0
800A205C	sll    a0, a0, $02
800A2060	lui    v0, $8008
800A2064	addiu  v0, v0, $eaac (=-$1554)
800A2068	jal    func443b0 [$800443b0]
800A206C	addu   a0, a0, v0

[800965ec] = h(S2);

800A2078	lbu    v0, $0000(s1)
800A207C	ori    v1, zero, $000a
800A2080	andi   v0, v0, $00ff
800A2084	beq    v0, v1, La22d8 [$800a22d8]
800A2088	nop
800A208C	lbu    v0, $0000(s1)
800A2090	ori    v1, zero, $001a
800A2094	andi   v0, v0, $00ff
800A2098	beq    v0, v1, La22d8 [$800a22d8]
800A209C	nop
800A20A0	lbu    v0, $0000(s1)
800A20A4	ori    v1, zero, $0005
800A20A8	andi   v0, v0, $00ff
800A20AC	beq    v0, v1, La22d8 [$800a22d8]
800A20B0	nop
800A20B4	lbu    v0, $0000(s1)
800A20B8	nop
800A20BC	bne    v0, s2, La2140 [$800a2140]
800A20C0	nop
800A20C4	lui    v0, $800a
800A20C8	lhu    v0, $a05c(v0)
800A20CC	lui    v1, $8007
800A20D0	lh     v1, $1a5c(v1)
800A20D4	sh     v0, $0063(s1)
800A20D8	lhu    v0, $0001(s1)
800A20DC	nop
800A20E0	lui    at, $800a
800A20E4	sh     v0, $a05c(at)
800A20E8	sll    v0, v0, $10
800A20EC	sra    v0, v0, $10
if (V0 != V1)
{
    field_stop_load_background_in_advance;
}

800A2100	lui    v0, $800a
800A2104	lhu    v0, $a05c(v0)
800A2108	nop
800A210C	addiu  v0, v0, $ffff (=-$1)
800A2110	sltiu  v0, v0, $0040
800A2114	beq    v0, zero, La2140 [$800a2140]
800A2118	nop
800A211C	lui    at, $800a
800A2120	sh     s5, $c560(at)
800A2124	jal    func129d0 [$800129d0]
800A2128	nop
800A212C	sh     s5, $004b(s1)
800A2130	lui    at, $8007
800A2134	sb     s5, $1a58(at)
800A2138	j      La2284 [$800a2284]
800A213C	nop

La2140:	; 800A2140
800A2140	lbu    v0, $0000(s1)
800A2144	ori    v1, zero, $000c
800A2148	andi   v0, v0, $00ff
800A214C	bne    v0, v1, La2230 [$800a2230]
800A2150	nop
800A2154	lui    v0, $800a
800A2158	lhu    v0, $a05c(v0)
800A215C	nop
800A2160	sh     v0, $0063(s1)
800A2164	lhu    v0, $0001(s1)
800A2168	lbu    v1, $00f1(s1)
800A216C	nop
800A2170	andi   v1, v1, $00ff
800A2174	lui    at, $800a
800A2178	sh     v0, $a05c(at)
800A217C	sltiu  v0, v1, $0007
800A2180	beq    v0, zero, La22d8 [$800a22d8]
800A2184	sll    v0, v1, $02
800A2188	lui    at, $800a
800A218C	addiu  at, at, $0008
800A2190	addu   at, at, v0
800A2194	lw     v0, $0000(at)
800A2198	nop
800A219C	jr     v0 
800A21A0	nop

800A21A4	ori    v0, zero, $0006
800A21A8	lui    at, $800a
800A21AC	sh     v0, $c560(at)
800A21B0	j      La22d8 [$800a22d8]
800A21B4	nop
800A21B8	ori    v0, zero, $0007
800A21BC	lui    at, $800a
800A21C0	sh     v0, $c560(at)
800A21C4	j      La22d8 [$800a22d8]
800A21C8	nop
800A21CC	ori    v0, zero, $0008
800A21D0	lui    at, $800a
800A21D4	sh     v0, $c560(at)
800A21D8	j      La22d8 [$800a22d8]
800A21DC	nop
800A21E0	ori    v0, zero, $0009
800A21E4	lui    at, $800a
800A21E8	sh     v0, $c560(at)
800A21EC	j      La22d8 [$800a22d8]
800A21F0	nop
800A21F4	ori    v0, zero, $000a
800A21F8	lui    at, $800a
800A21FC	sh     v0, $c560(at)
800A2200	j      La22d8 [$800a22d8]
800A2204	nop
800A2208	ori    v0, zero, $000b
800A220C	lui    at, $800a
800A2210	sh     v0, $c560(at)
800A2214	j      La22d8 [$800a22d8]
800A2218	nop
800A221C	ori    v0, zero, $000e
800A2220	lui    at, $800a
800A2224	sh     v0, $c560(at)
800A2228	j      La22d8 [$800a22d8]
800A222C	nop

La2230:	; 800A2230
800A2230	lbu    v0, $0000(s1)
800A2234	ori    v1, zero, $0002
800A2238	andi   v0, v0, $00ff
800A223C	beq    v0, v1, La22d8 [$800a22d8]
800A2240	nop
800A2244	lbu    v0, $0000(s1)
800A2248	nop
800A224C	beq    v0, s4, La22d8 [$800a22d8]
800A2250	nop
800A2254	lui    v0, $800a
800A2258	lhu    v0, $c560(v0)
800A225C	ori    v1, zero, $0005
800A2260	sll    v0, v0, $10
800A2264	sra    v0, v0, $10
800A2268	bne    v0, v1, La22a0 [$800a22a0]
800A226C	nop
800A2270	jal    func129d0 [$800129d0]
800A2274	nop
800A2278	sh     s4, $004b(s1)
800A227C	lui    at, $8007
800A2280	sb     s4, $1a58(at)

La2284:	; 800A2284
800A2284	sh     zero, $004d(s1)
800A2288	lui    at, $8008
800A228C	sh     zero, $e768(at)
800A2290	lui    at, $8009
800A2294	sh     s2, $5dd4(at)
800A2298	j      La22d8 [$800a22d8]
800A229C	nop

La22a0:	; 800A22A0
800A22A0	lui    v0, $800a
800A22A4	lhu    v0, $c560(v0)
800A22A8	nop
800A22AC	sll    v0, v0, $10
800A22B0	sra    v0, v0, $10
800A22B4	beq    v0, s4, La22d8 [$800a22d8]
800A22B8	nop
800A22BC	lui    v0, $800a
800A22C0	lhu    v0, $c560(v0)
800A22C4	ori    v1, zero, $0010
800A22C8	sll    v0, v0, $10
800A22CC	sra    v0, v0, $10
800A22D0	bne    v0, v1, La1af8 [$800a1af8]
800A22D4	nop

La22d8:	; 800A22D8
A0 = 0;
800A22D8	jal    func3cedc [$8003cedc]
////////////////////////////////
