/////////////////////////////////////////////////////////////
// system_parse_materia_equip
// A0 - materia data [[[AP]]][materia id]

materia = A0;
materia_exp = A0 >> 8;
materia_id = A0 & 000000ff;

V0 = bu[GP + 2dc]
// for menu
if (V0 != 0)
{
    A3 = w[GP + 238];
    V1 = 0;
    loop197e0:	; 800197E0
        [A3 + V1 * 2 + a] = h(0);
        V1 = V1 + 1;
        V0 = V1 < 8;
    800197F8	bne    v0, zero, loop197e0 [$800197e0]
}



// if materia id exist
if (materia_id != ff)
{
    A0 = materia_id; // materia id
    system_add_materia_equip_stat_bonus;

    V0 = bu[800730d0 + materia_id * 14 + d];
    A0 = V0 >> 4;
    V1 = V0 & f;

    switch (V1)
    {
        case 00:
        {
            A1 = materia_id;
            A2 = materia_exp;
            system_add_materia_00;
        }
        break;

        case 01:
        {
            A1 = materia_id;
            A2 = materia_exp;
            system_add_materia_01;
        }
        break;

        case 02:
        {
            A1 = materia_id;
            A2 = materia_exp;
            system_add_materia_02;
        }
        break;

        case 03:
        {
            A1 = materia_id;
            A2 = materia_exp;
            system_add_materia_03;
        }
        break;

        case 04:
        {
            A0 = materia_id;
            A1 = materia_exp;
            system_add_materia_04;
        }
        break;

        case 05:
        {
            A1 = materia_id;
            A2 = materia_exp;
            system_add_materia_05;
        }
        break;

        case 06: // command
        {
            A0 = materia_id;
            A1 = materia_exp;
            system_add_materia_06;
        }
        break;

        case 07: // enemy skill
        {
            A1 = materia_id;
            A2 = materia_exp;
            system_add_materia_07;
        }
        break;

        case 08: // master command
        {
            system_add_materia_08;
        }
        break;

        case 09: // magic
        {
            A0 = materia_id;
            A1 = materia_exp;
            system_add_materia_09;
        }
        break;

        case 0A: // master magic
        {
            system_add_materia_0a;
        }
        break;

        case 0B: // summon
        {
            A0 = materia_id;
            A1 = materia_exp;
            system_add_materia_0b;
        }
        break;

        case 0C: // master summon
        {
            system_add_materia_0c;
        }
        break;
    }
}

return;
/////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////
// system_add_materia_equip_stat_bonus
materia_id = A0;

V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    V1 = bu[800730d0 + materia_id * 14 + 8];
    if (V1 != ff)
    {
        [800694fc] = h(hu[800694fc] + hu[80049060 + V1 * 10 + 0]);
        [800694fe] = h(hu[800694fe] + hu[80049060 + V1 * 10 + 2]);
        [80069500] = h(hu[80069500] + hu[80049060 + V1 * 10 + 4]);
        [80069502] = h(hu[80069502] + hu[80049060 + V1 * 10 + 6]);
        [80069504] = h(hu[80069504] + hu[80049060 + V1 * 10 + 8]);
        [80069506] = h(hu[80069506] + hu[80049060 + V1 * 10 + a]);
        [800694f4] = h(hu[800694f4] + hu[80049060 + V1 * 10 + c]);
        [800694f6] = h(hu[800694f6] + hu[80049060 + V1 * 10 + e]);
    }
}
// menu
else
{
    V0 = A0 & ff;
    V1 = bu[800730d0 + A0 * 14 + 8];
    if (V1 != ff)
    {
        V0 = w[GP + 238];
        [V0 + 0a] = h(hu[80049060 + V1 * 10 + 0]);
        [V0 + 0c] = h(hu[80049060 + V1 * 10 + 2]);
        [V0 + 0e] = h(hu[80049060 + V1 * 10 + 4]);
        [V0 + 10] = h(hu[80049060 + V1 * 10 + 6]);
        [V0 + 12] = h(hu[80049060 + V1 * 10 + 8]);
        [V0 + 14] = h(hu[80049060 + V1 * 10 + a]);
        [V0 + 16] = h(hu[80049060 + V1 * 10 + c]);
        [V0 + 18] = h(hu[80049060 + V1 * 10 + e]);
}

return;
//////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_00
// 00
materia_type = A0;
materia_id = A1;
materia_exp = A2;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars;
A0 = V0;

if (materia_type == 0)
{
    A0 = materia_id;
    A1 = materia_exp;
    func1a684;
}
else if (materia_type == 2)
{
    A0 = materia_id;
    A1 = materia_exp;
    func1a780;
}
else if (materia_type == 3)
{
    A0 = A0;
    A1 = materia_id;
    func19d74;
}
else if (materia_type == 4)
{
    A0 = materia_id;
    A1 = materia_exp;
    func1a874;
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1a684
// 0_0
materia_id = A0;
materia_exp = A1;

V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    V1 = bu[800730d0 + materia_id * 14 + e];
    if (V1 == c) // underwater
    {
        V1 = w[GP + 11c];
        [V1 + 23] = b(bu[V1 + 23] | 1);
    }
    else if (V1 == 62) // hp<->mp
    {
        V1 = w[GP + 11c];
        [V1 + 23] = b(bu[V1 + 23] | 8);
    }
}
else
{
    V1 = bu[800730d0 + materia_id * 14 + e];
    if (V1 == c || V1 == 62)
    {
        [GP + 2b8] = b(11);
    }
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1a780
// 2_0
materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars;
A1 = V0;

if (materia_id == d) // counter attack
{
    A0 = A1 & ff;
    A1 = d;
    func19da0;
}
else
{
    V0 = bu[GP + 2dc];
    // battle
    if (V0 == 0)
    {
        type = bu[800730d0 + materia_id * 14 + e];

        V0 = bu[800730d0 + materia_id * 14 + e + A1];
        [800694e4 + A0 * 2] = h(hu[800694e4 + type * 2] + V0);
    }
    // menu
    else
    {
        A0 = w[GP + 238];
        [A0 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
        [A0 + 1b] = b(bu[800730d0 + materia_id * 14 + e + A1]);

        [GP + 2b8] = b(4);
    }
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func19da0
// 2_0/d/counter attack
number_of_star = A0;
materia_id = A1;

V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    A0 = w[GP + 13c];
    if (A0 != 8)
    {
        V1 = w[GP + 11c];
        [V1 + A0 * 3 + 24] = b(9);
        [V1 + A0 * 3 + 25] = b(9);

        counter_value = bu[800730d0 + materia_id * 14 + e + number_of_star];
        V1 = w[GP + 11c];
        [V1 + A0 * 3 + 26] = b(counter_value);

        V0 = w[GP + 13c];
        V0 = V0 + 1;
        [GP + 13c] = w(V0);
    }
}
else
{
    [GP + 2b8] = b(12);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func19d74
// 30
materia_id = A1;
if (materia_id == b)
{
    func19e4c;
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func19e4c
// 30/b/long range
V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    V1 = bu[GP + 11c];
    V0 = bu[V1 + 23];
    V0 = V0 | 4;
    [V1 + 23] = b(V0);
}
else
{
    [GP + 2b8] = b(12);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1a874
// 40
materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars;
A0 = V0;

if (A0 > 0)
{
    V1 = 800730d0 + materia_id * 14 + e + A0;

    loop1ab6c:	; 8001AB6C
        V0 = bu[V1];
        if (V0 != ff)
        {
            S2 = V0;
            break;
        }

        V1 = V1 - 1;
        A0 = A0 - 1;
    8001AB7C	bgtz   a0, loop1ab6c [$8001ab6c]
}

V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    V1 = bu[800730d0 + materia_id * 14 + e];
    V0 = hu[800694e4 + V1 * 2];
    V0 = V0 + S2;
    [800694e4 + V1 * 2] = h(V0);
}
else
{
    V0 = bu[800730d0 + materia_id * 14 + e];

    V1 = w[GP + 238];
    [V1 + 1a] = b(V0);
    [V1 + 1b] = b(S2);

    [GP + 2b8] = b(d);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_01
// 1
materia_type = A0;
materia_id = A1;
materia_exp = A2;

if (materia_type == 2)
{
    A0 = materia_id;
    A1 = materia_exp;
    func1a9cc;

}
else if (materia_type == 4)
{
    A0 = materia_id;
    A1 = materia_exp;
    func1ab1c;
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1a9cc
// 21
materia_id = A0;
materia_exp = A1;

A0 = materia_id;
system_get_materia_activated_stars;
A1 = V0;

if (A1 > 0)
{
    A0 = A1;

    loop1aa1c:	; 8001AA1C
        V0 = bu[800730d0 + materia_id * 14 + e + A0];
        if (V0 != ff)
        {
            S2 = V0;
            break;
        }

        A0 = A0 - 1;
    8001AA2C	bgtz   a0, loop1aa1c [$8001aa1c]
}

V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    A0 = materia_id;
    V1 = bu[800730d0 + A0 * 14 + e];
    [GP + 128 + V1 * 2] = h(hu[GP + 128 + V1 * 2] + S2);

    if (A0 == a)
    {
        V0 = h[GP + 12e];
        if (V0 >= 56)
        {
            [GP + 12e] = h(55);
        }

        if (A1 == 5)
        {
            [GP + 118] = b(1);
        }
    }
}
else
{
    V1 = w[GP + 238];
    [V1 + 1a] = b(bu[800730de + materia_id * 14]);
    [V1 + 1b] = (A1);
    [GP + 2b8] = b(a);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1ab1c
// 41
materia_id = A0;
materia_exp = A1;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars;
V1 = V0;

A0 = V0;
if (A0 > 0)
{
    V1 = 800730d0 + materia_id * 14 + e + A0;

    loop1ab6c:	; 8001AB6C
        V0 = bu[V1];
        if (V0 != ff)
        {
            S2 = V0;
            break;
        }

        V1 = V1 - 1;
        A0 = A0 - 1;
    8001AB7C	bgtz   a0, loop1ab6c [$8001ab6c]
}

V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    if (V1 == 7)
    {
        [GP + 130] = h(hu[GP + 130] + S2);
    }
    else
    {
        V1 = bu[800730d0 + materia_id * 14 + e];
        [GP + 128 + V1 * 2] = h(hu[GP + 128 + V1 * 2] + S2);
    }
}
else
{
    V0 = bu[800730d0 + materia_id * 14 + e];

    V1 = w[GP + 238];
    [V1 + 1a] = b(V0);
    [V1 + 1b] = b(S2);

    [GP + 2b8] = b(9);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_02
// 2
// replace attack with command
materia_type = A0;
materia_id = A1;
materia_exp = A2;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars;
A0 = V0;

if (materia_type == 1)
{
    A0 = A0 & ff;
    A1 = materia_id;
    func19e84;
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func19e84
number_of_star = A0;
materia_id = A1;

V0 = bu[GP + 2dc];
// battle
if (V0 == 0)
{
    A2 = number_of_star - 1;
    if (A2 > 0)
    {
        V1 = 800730d0 + materia_id * 14 + e + A2;

        loop19ec4:	; 80019EC4
            V0 = bu[V1];
            if (V0 != ff)
            {
                break;
            }

            A2 = A2 - 1;
            V1 = V1 - 1;
        80019ED8	bgtz   a2, loop19ec4 [$80019ec4]
    }

    [80069508] = b(bu[800730d0 + materia_id * 14 + e + A2]);
}
else
{
    A2 = 0;
    A3 = w[GP + 238];
    V1 = 800730d0 + materia_id * 14 + e;
    A1 = A3;

    loop19f3c:	; 80019F3C
        V0 = bu[V1];
        V1 = V1 + 1;
        A2 = A2 + 1;
        [A1 + 1b] = b(0);
        [A1 + 1a] = b(V0);
        A1 = A1 + 2;
        V0 = A2 < 5;
    80019F54	bne    v0, zero, loop19f3c [$80019f3c]

    V0 = bu[A3 + 1];
    if (V0 == number_of_star)
    {
        V0 = number_of_star - 2;
    }
    else
    {
        V0 = number_of_star - 1;
    }

    [A3 + V0 * 2 + 1b] = b(1);
    [GP + 2b8] = b(13);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_03
// 3
// add W command or replace existed command with W analog
materia_type = A0;
materia_id = A1;
materia_exp = A2;

A0 = materia_id;
A1 = materia_exp;
system_get_materia_activated_stars;
number_of_star = V0;

V1 = bu[GP + 2dc];
// battle
if (V1 == 0)
{
    V1 = bu[800730d0 + materia_id * 14 + e];

    if (V1 == 15) // w-magic
    {
        [GP + 148] = b(2);

        A0 = 2;
        system_search_existed_command;
        V1 = V0;

        if (V1 == -1)
        {
            A0 = 2;
            system_add_command;
            [80069508 + V0 * 3 + 1] = b(number_of_star);
        }
        else
        {
            [80069508 + V1 * 3] = b(2);
            [80069509 + V1 * 3] = b(number_of_star);
        }
    }
    else if (V1 == 16) // w-summon
    {
        [GP + 14c] = b(2);

        A0 = 3;
        system_search_existed_command;
        V1 = V0;

        if (V1 == -1)
        {
            A0 = 3;
            system_add_command;
            [80069509 + V0 * 3] = b(number_of_star);
        }
        else
        {
            [80069508 + V1 * 3] = b(3)
            [80069509 + V1 * 3] = b(number_of_star);
        }
    }
    else if (V1 == 17) w-item
    {
        A0 = 4;
        system_search_existed_command;

        [80069508 + V0 * 3] = b(17);
        [80069509 + V0 * 3] = b(number_of_star);
    }
}
else
{
    [GP + 2b8] = b(e);

    V1 = w[GP + 238];
    [V1 + 1a] = b(bu[800730d0 + materia_id * 14 + e]);
    [V1 + 1b] = b(number_of_star);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_04
// 4
// mega all
A0 = A0 & ff;
system_get_materia_activated_stars;

V0 = bu[GP + 2dc];
if (V0 != 0)
{
    [GP + 2b8] = b(b);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_05
// 05
A0 = A0 & ff;
if (A0 == 2)
{
    A0 = A1 & ff;
    A1 = A2;
    func1a280;
}
else if (A0 == 3)
{
    A0 = A1 & ff;
    A1 = A2;
    func1a1c8;
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1a280
// 25
S0 = A0 & ff;

A0 = S0;
system_get_materia_activated_stars;

V1 = bu[GP + 2dc];
if (V1 != 0)
{
    A0 = w[GP + 238];
    [A0 + 1a] = b(bu[800730d0 + S0 * 14 + e]);
    [A0 + 1b] = b(V0 * a);

    V0 = bu[800730d0 + S0 * 14 + e];
    switch (V0)
    {
        case 54 55:                      [GP + 2b8] = b(0f); break;
        case 56 58 59 5a 5c 5d 5e 5f 64: [GP + 2b8] = b(10); break;
    }
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1a1c8
// 35
S0 = A0 & ff;
A0 = S0;
system_get_materia_activated_stars;
A1 = V0;

V1 = bu[GP + 2dc];
if (V1 != 0)
{
    A0 = w[GP + 238];

    V1 = bu[800730d0 + S0 * 14 + e];
    [A0 + 1a] = b(V1);
    [A0 + 1b] = b(A1);

    V1 = bu[800730d0 + S0 * 14 + e];
    if (V1 == 51)
    {
        [GP + 2b8] = b(f);
    }
    else if (V1 == 57)
    {
        [GP + 2b8] = b(10);
    }
    else if (V1 == 63)
    {
        [GP + 2b8] = b(f);
    }
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_06
// 6
// add command

S1 = A0;
S0 = S1 & ff;
A0 = S0;
system_get_materia_activated_stars;
A2 = V0;

V1 = bu[GP + 2dc];
if (V1 == 0)
{
    A0 = A2 - 1;
    if (A0 >= 0)
    {
        V1 = 800730d0 + S0 * 14 + e + A0;

        loop1b75c:	; 8001B75C
            V0 = bu[V1];
            if (V0 != ff)
            {
                break;
            }

            A0 = A0 - 1;
            V1 = V1 - 1;
        8001B770	bgez   a0, loop1b75c [$8001b75c]
    }

    A0 = bu[800730d0 + S1 * 14 + e + A0];
    system_add_command;
}
else
{
    A0 = 0;
    A3 = w[GP + 238];
    A1 = 800730d0 + S0 * 14 + e;
    V1 = A3;

    loop1b7d0:	; 8001B7D0
        V0 = bu[A1];
        A1 = A1 + 1;
        A0 = A0 + 1;
        [V1 + 1b] = b(0);
        [V1 + 1a] = b(V0);
        V1 = V1 + 2;
        V0 = A0 < 5;
    8001B7E8	bne    v0, zero, loop1b7d0 [$8001b7d0]

    V0 = bu[A3 + 1];
    if (V0 == A2)
    {
        V0 = A2 - 2;
    }
    else
    {
        V0 = A2 - 1;
    }

    V0 = A3 + V0 * 2;
    [V0 + 1b] = b(1);
    [GP + 2b8] = b(3);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_07
// 07
// enemy skill

V0 = bu[GP + 2dc];
if (V0 == 0)
{
    S1 = A2 & 00ffffff;
    S0 = 0;

    loop1a3e4:	; 8001A3E4
        V0 = S1 & 0001;
        S1 = S1 >> 1;
        if (V0 != 0)
        {
            A1 = S0 + 48;
            A0 = S0 & ff;
            A1 = A1 & ff;
            A2 = A1;
            system_add_magic_summon_skill_to_unit_structure;
        }

        S0 = S0 + 1;
        V0 = S0 < 18;
    8001A408	bne    v0, zero, loop1a3e4 [$8001a3e4]

    A0 = d;
    system_add_command;
}
else
{
    [GP + 2b8] = b(8);
}

return;
/////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////
// system_add_materia_08
// 08
// master command
V0 = bu[GP + 2dc];
if (V0 == 0)
{
    A0 = 5;
    system_add_command;
    A0 = 6;
    system_add_command;
    A0 = 7;
    system_add_command;
    A0 = 9;
    system_add_command;
    A0 = a;
    system_add_command;
    A0 = b;
    system_add_command;
    A0 = c;
    system_add_command;
}
else
{
    [GP + 2b8] = b(5);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_09
// 09
// magic
materia_id = A0;
materia_ap = A1;


A0 = materia_id;
A1 = materia_ap;
system_get_materia_activated_stars;
A1 = V0; // how much stars we have now

V1 = bu[GP + 2dc];
if (V1 == 0)
{
    S0 = A1 - 1;
    if (S0 >= 0) // if we has at least 1 star
    {
        V0 = 800730d0 + materia_id * 14 + 0e;
        S1 = S0 + V0;

        loop1b634:	; 8001B634
            A0 = bu[S1];
            if (A0 != ff)
            {
                func1bce8;
            }

            S1 = S1 - 1;
            S0 = S0 - 1;
        8001B650	bgez   s0, loop1b634 [$8001b634]
    }

    A0 = 2;
    system_add_command;

    if (bu[GP + 148] == 0)
    {
        [GP + 148] = b(1);
    }
}
else
{
    S0 = 0;
    A2 = w[GP + 238];

    loop1b6a0:	; 8001B6A0
        [A2 + 1b + S0 * 2] = b(0);
        [A2 + 1a + S0 * 2] = b(bu[800730d0 + materia_id * 14 + e + S0]);

        S0 = S0 + 1;
        V0 = S0 < 5;
    8001B6B8	bne    v0, zero, loop1b6a0 [$8001b6a0]

    if (A1 > 0) // if we have at least 1 star
    {
        S0 = 0;

        loop1b6d0:	; 8001B6D0
            [A2 + 1b + S0 * 2] = b(1);
            S0 = S0 + 1;
            V0 = S0 < A1;
        8001B6DC	bne    v0, zero, loop1b6d0 [$8001b6d0]
    }

    [GP + 2b8] = b(1);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_0a
// 0A
// master magic
V0 = bu[GP + 2dc];
if (V0 == 0)
{
    S0 = 0;
    loop1a4c0:	; 8001A4C0
        A0 = S0 & ff;
        func1bce8;

        S0 = S0 + 1;
        V0 = S0 < 38;
    8001A4D0	bne    v0, zero, loop1a4c0 [$8001a4c0]

    A0 = 2;
    system_add_command;

    if (bu[GP + 148] == 0)
    {
        [GP + 148] = b(1);
    }
}
else
{
    [GP + 2b8] = b(6);
}
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_0b
// 0b
// summon

S0 = A0;
A0 = S0;
system_get_materia_activated_stars;
A0 = V0;

A1 = bu[800730d0 + S0 * 14 + e];

V1 = bu[GP + 2dc];
if (V1 == 0)
{
    V1 = bu[8006947c + A1];
    if (V1 != ff)
    {
        [8006947c + A1] = b(V1 + A0);
    }

    A0 = A1 - 38;
    A0 = A0 & ff;
    A2 = A1;
    system_add_magic_summon_skill_to_unit_structure;

    A0 = 3;
    system_add_command;

    V0 = bu[GP + 14c];
    if (V0 == 0)
    {
        [GP + 14c] = b(1);
    }
}
else
{
    V0 = w[GP + 238];
    [V0 + 1a] = b(A1 - 38);
    [V0 + 1b] = b(A0);
    [GP + 2b8] = b(2);
}

returnl
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_materia_0c
// 0C
// master summon
V0 = bu[GP + 2dc];
if (V0 == 0)
{
    V0 = 800694c3;
    S0 = f;
    loop1a53c:	; 8001A53C
        [V0] = b(ff);

        V0 = V0 - 1;
        S0 = S0 - 1;
    8001A544	bgez   s0, loop1a53c [$8001a53c]

    S0 = 38;
    A0 = S0 - 38;

    loop1a554:	; 8001A554
        A1 = S0;
        A2 = A1;
        system_add_magic_summon_skill_to_unit_structure;

        S0 = S0 + 1;
        A0 = S0 - 38;
        V0 = S0 < 48;
    8001A56C	bne    v0, zero, loop1a554 [$8001a554]

    A0 = 3;
    system_add_command;

    if (bu[GP + 14c] == 0)
    {
        [GP + 14c] = b(1);
    }
}
else
{
    [GP + 2b8] = b(7);
}

return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_get_materia_activated_stars
// A0 - materia id
// A1 = materia exp
// this looks how much exp this materia has
T0 = 1; // how much stars activated (1 - at start)

// search how much stars activated in this materia
A3 = 3;
loop1acc4:	; 8001ACC4
    A2 = hu[800730D0 + A0 * 14 + A3 * 2];
    if (A2 != FFFF && A1 >= A2 * 64)
    {
        T0 = A3 + 2;
        break;
    }

    A3 = A3 - 1;
8001ACF8	bgez   a3, loop1acc4 [$8001acc4]



[GP + 278] = w(1); // how much stars this materia has
A3 = 0;
loop1ad2c:	; 8001AD2C
    if (hu[800730D0 + A0 * 14 + A3 * 2] != FFFF)
    {
        V0 = w[GP + 278];
        V0 = V0 + 1;
        [GP + 278] = w(V0);
    }

    A3 = A3 + 1;
    V0 = A3 < 4;
8001AD54	bne    v0, zero, loop1ad2c [$8001ad2c]

// for menu
if (bu[GP + 2dc] != 0)
{
    V1 = hu[800730D0 + (T0 - 1) * 2 + A0 * 14];

    if (V1 == FFFF || T0 == w[GP + 278])
    {
        [GP + 1cc] = w(0); // AP to next level
    }
    else
    {
        V0 = V1 * 64 - A1;
        [GP + 1cc] = w(V0); // AP to next level
    }

    V0 = w[GP + 238];
    [V0 + 0] = b(T0);
    [V0 + 1] = b(bu[GP + 278]);
    [V0 + 4] = w(w[GP + 1cc]);
}

return T0;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// func1bce8
// this adds spells
// A0 - spell to add

A1 = 0;
A2 = A0 & FF;
V1 = 0;

loop1bcf4:	; 8001BCF4
    V0 = bu[80069554 + V1];
    if (V0 == A2)
    {
        return;
    }

    A1 = A1 + 1;
    V1 = V1 + 5;
    V0 = A1 < 38;
8001BD18	bne    v0, zero, loop1bcf4 [$8001bcf4]

V1 = bu[GP + 124];
V0 = V1 + 1;
[GP + 124] = b(V0);

[80069554 + V1 * 5] = b(A0);
return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_magic_summon_skill_to_unit_structure
// this add summon and enemy skill attacks
offset = w[GP + 11c];
[offset + 108 + A1 * 8 + 0] = b(A0);
[offset + 108 + A1 * 8 + 1] = b(bu[800708c4 + A2 * 1C + 4]); // magic cost
[offset + 108 + A1 * 8 + 5] = b(bu[800708c4 + A2 * 1C + c]); // animation id?
return;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_add_command
// A0 - command id
V1 = 0;
loop1b840:	; 8001B840
    V0 = bu[80069508 + V1 * 3];
    if (V0 == A0)
    {
        return V1;
    }

    V1 = V1 + 1;
    V0 = V1 < 10;
8001B864	bne    v0, zero, loop1b840 [$8001b840]

V1 = bu[GP + 120];
V0 = V1 + 1;
[GP + 120] = b(V0);

[80069508 + V1 * 3] = b(A0);

V0 = bu[GP + 120];
return V0 - 1;
/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////
// system_search_existed_command

A0 = A0 & ff;

V1 = 0;
A1 = 0;
loop19614:	; 80019614
    V0 = bu[80069508 + A1];
    if (V0 == A0)
    {
        return V1;
    }

    V1 = V1 + 1;
    A1 = A1 + 3;
    V0 = V1 < 10;
80019638	bne    v0, zero, loop19614 [$80019614]

return -1;
/////////////////////////////////////////////////////////////