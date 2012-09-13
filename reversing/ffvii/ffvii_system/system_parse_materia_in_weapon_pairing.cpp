//////////////////////////////////////////////////////////////////
// system_add_pair_materia_with_slot_check
// A0 - weapon left slot value
// A1 - weapon right slot value
materia1_data = A2;
materia2_data = A3;
// [SP + 10] = w(0);
// [SP + 14] = w(0);
// [SP + 18] = w(0);

S3 = bu[SP + 10];
S4 = bu[SP + 14];
S1 = bu[SP + 18];

if ((A0 == 2 && A1 == 3) || (A0 == 6 && A1 == 7)) // if linked
{
    [SP + 10] = w(S1);
    A0 = materia1_data;
    A1 = materia2_data;
    A2 = S3;
    A3 = S4;
    system_add_pair_materia_unordered;
}

return;
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_materia_unordered
// [SP + 10] = w(S1);
materia1_data = A0
materia2_data = A1;
// A2 = S3;
// A3 = S4;

materia1_id = materia1_data & 000000ff;
materia2_id = materia2_data & 000000ff;

V0 = bu[800730dd + materia1_id * 14];
V1 = bu[800730dd + materia2_id * 14];
materia1_type = V0 & 0f;
materia2_type = V1 & 0f;

if (materia1_id != ff && materia2_id != ff)
{
    if (materia1_type != 5)
    {
        if (materia2_type == 5)
        {
            A0 = materia2_data;
            A1 = materia1_data;
            A2 = A2 & ff;
            A3 = bu[SP + 10];
            system_add_pair_materia_ordered;
        }

        return;
    }
    else
    {
        if (materia2_type != 5)
        {
            A0 = materia1_data;
            A1 = materia2_data;
            A2 = A3;
            A3 = bu[SP + 10];
            system_add_pair_materia_ordered;
        }
    }
}

return;
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_materia_ordered
materia_5type_data = A0;
materia_pair_data = A1;
// A2 - ?
// A3 - ?

materia_5type_id = materia_5type_data & 000000ff;
materia_5type_exp = materia_5type_data >> 8;

S2 = materia_pair_data;
S1 = materia_5type_data;
S0 = materia_5type_id;
S3 = A3;

A0 = materia_5type_id;
A1 = materia_5type_exp;
system_get_materia_activated_stars;
number_of_5type_stars = V0;

V1 = 0;
loop18080:	; 80018080
    V0 = bu[800730d0 + S0 * 14 + f + V1];
    [GP + 110 + V1] = b(V0);

    V1 = V1 + 1;
    V0 = V1 < 5;
800180A4	bne    v0, zero, loop18080 [$80018080]

V1 = S1 & ff;
V0 = bu[800730d0 + V1 * 14 + e];
switch (V0)
{
    case 51: // all
    {
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_all;
    }
    break;

    case 54: // counter
    {
        [GP + 140] = w(8);
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_counter;
    }
    break;

    case 55: // magic counter
    {
        [GP + 140] = w(7);
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_magic_counter;
    }
    break;

    case 56: // sneak attack
    {
        [GP + 140] = w(4);
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_sneak_final_attack;
    }
    break;

    case 57: // final attack
    {
        [GP + 140] = w(1);
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_sneak_final_attack;
    }
    break;

    case 58: // mp turbo
    {
        A0 = number_of_5type_stars;
        A1 = materia_pair_data;
        system_add_pair_with_mp_turbo;
    }
    break;

    case 59: // mp absorb
    {
        [GP + 134] = b(1);
        A0 = materia_pair_data;
        system_add_pair_with_mp_absorb;
    }
    break;

    case 5a: // hp absorb
    {
        [GP + 134] = b(2);
        A0 = materia_pair_data;
        system_add_pair_with_mp_absorb;
    }
    break;

    case 5c: // added cut
    {
        [GP + 134] = b(10);
        A0 = materia_pair_data;
        system_add_pair_with_mp_absorb;
    }
    break;

    case 5d: // steal as well
    {
        [GP + 134] = b(8);
        A0 = materia_pair_data;
        system_add_pair_with_mp_absorb;
    }
    break;

    case 5e: // elemental
    {
        A0 = number_of_5type_stars;
        A1 = materia_pair_data;
        A2 = S3 & ff;
        system_add_pair_with_elemental;
    }
    break;

    case 5f: // added effect
    {
        A0 = number_of_5type_stars;
        A1 = materia_pair_data;
        A2 = S3 & ff;
        system_add_pair_with_added_effect;
    }
    break;

    case 63: // quadra magic
    {
        A0 = materia_5type_id;
        A1 = number_of_5type_stars;
        A2 = materia_pair_data;
        system_add_pair_with_quadra_magic;
    }
    break;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_all
// pair with 51
materia_5type_id = A0;
number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = A2 & 000000ff
materia_pair_exp = A2 >> 8;
V0 = bu[800730d0 + materia_pair_id * 14 + 0d];
V1 = V0 & 0f;

if (V1 == 9)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    A2 = materia_pair_exp;
    system_add_pair_magic_with_all;
}
else if (V1 == a)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    A2 = materia_pair_exp;
    system_add_pair_master_magic_with_all;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_magic_with_all
// 09 with 51
// magic with all
number_of_5type_stars = A0;
materia_pair_id = A1;
materia_pair_exp = A2;

A0 = materia_pair_id;
A1 = materia_pair_exp;
system_get_materia_activated_stars;
S0 = V0;

if (S0 > 0)
{
    loop19590:	; 80019590
        A0 = bu[800730d0 + materia_pair_id * 14 + d + S0];

        system_search_existed_magic;
        A0 = V0;

        if (A0 != -1)
        {
            [80069554 + A0 * 5 + 1] = b(bu[80069554 + A0 * 5 + 1] + number_of_5type_stars);
        }

        S0 = S0 - 1;
    800195E0	bgtz   s0, loop19590 [$80019590]
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_magic_with_all
// 0a with 51
S1 = A0;
S0 = 0;
S2 = -1;

loop194dc:	; 800194DC
    A0 = S0 & ff;
    system_search_existed_magic;

    if (V0 != -1)
    {
        V1 = bu[80069555 + V0 * 5];
        V1 = S1 + V1;
        [80069555 + V0 * 5] = b(V1);
    }

    S0 = S0 + 1;
    V0 = S0 < 38;
80019520	bne    v0, zero, loop194dc [$800194dc]

return;
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_counter
// pair with 54

materia_5type_id = A0;
number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = A2 & 000000ff
materia_pair_exp = A2 >> 8;

V0 = bu[800730d0 + materia_pair_id * 14 + 0d] & 0f;

[GP + 144] = h(0);

if (V0 == 6)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    system_add_pair_command_with_counter;
}
else if (V0 == 8)
{
    A0 = number_of_5type_stars;
    A1 = fd;
    system_add_pair_master_materia_with_counter;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_command_with_counter
number_of_5type_stars = A0;
materia_pair_id = A1;
unit_structure = w[GP + 11c];

A0 = bu[800730d0 + materia_pair_id * 14 + e];
if (A0 == 5 || A0 == 6 || A0 == 8 || A0 == 9 || A0 == a || A0 == b || A0 == c)
{
    system_search_existed_command;

    if (V0 != -1)
    {
        counter_slot = w[GP + 13c];
        if (counter_slot != 8)
        {
            [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
            [unit_structure + counter_slot * 3 + 25] = b(bu[800730d0 + materia_pair_id * 14 + e]);
            [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

            [GP + 13c] = w(counter_slot + 1);
        }
    }
}



A0 = bu[800730d0 + materia_pair_id * 14 + f]
if (A0 == 7 || A0 == 11)
{
    system_search_existed_command;

    if (V0 != -1)
    {
        counter_slot = w[GP + 13c];
        if (counter_slot != 8)
        {
            [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
            [unit_structure + counter_slot * 3 + 25] = b(bu[800730d0 + materia_pair_id * 14 + f]);
            [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

            [GP + 13c] = w(counter_slot + 1);
        }
    }
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_materia_with_counter
number_of_5type_stars = A0;

A0 = w[GP + 13c];
if (A0 != 0)
{
    unit_structure = w[GP + 11c];
    [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
    [unit_structure + counter_slot * 3 + 25] = b(A1);
    [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

    [GP + 13c] = w(counter_slot + 1);
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_magic_counter
materia_5type_id = A0;
number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = A2 & 000000ff
materia_pair_exp = A2 >> 8;

[GP + 144] = h(0);

V0 = bu[800730d0 + materia_pair_id * 14 + d];
V1 = V0 & 0f;

if (V1 == 9)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    system_add_pair_magic_with_magic_counter;
}
else if (V1 == a)
{
    A0 = number_of_5type_stars;
    A1 = fe;
    system_add_pair_master_materia_with_counter;
}
else if (V1 == b)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    system_add_pair_summon_with_magic_counter;
}
else if (V1 == c)
{
    A0 = number_of_5type_stars;
    A1 = ff;
    system_add_pair_master_materia_with_counter;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_magic_with_magic_counter
number_of_5type_stars = A0;
materia_pair_id = A1;

A0 = materia_pair_id;
A1 = A2;
system_get_materia_activated_stars;
A0 = V0;

if (A0 > 0)
{
    loop18878:	; 80018878
        V1 = bu[800730d0 + materia_pair_id * 14 + d + A0];

        if (V1 != ff)
        {
            counter_slot = w[GP + 13c];
            if (counter_slot == 8)
            {
                return;
            }

            unit_structure = w[GP + 11c];
            [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
            [unit_structure + counter_slot * 3 + 25] = b(V1);
            [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

            [GP + 13c] = w(counter_slot + 1);
            return;
        }

        A0 = A0 - 1;
    80018914	bgtz   a0, loop18878 [$80018878]
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_summon_with_magic_counter
number_of_5type_stars = A0;
materia_pair_id = A1;

counter_slot = w[GP + 13c];
if (counter_slot != 8)
{
    unit_structure = w[GP + 11c];
    [unit_structure + counter_slot * 3 + 24] = b(bu[GP + 140] + bu[GP + 144]);
    [unit_structure + counter_slot * 3 + 25] = b(bu[800730d0 + materia_pair_id * 14 + e]);
    [unit_structure + counter_slot * 3 + 26] = b(bu[GP + 10f + number_of_5type_stars]);

    [GP + 13c] = w(counter_slot + 1);
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_sneak_final_attack
materia_5type_id = A0;
number_of_5type_stars = A1;
materia_pair_data = A2;

materia_pair_id = A2 & 000000ff
materia_pair_exp = A2 >> 8;

V0 = bu[800730d0 + materia_pair_id * 14 + d];
V0 = V0 & 0f;
switch (V1)
{
    case 6:
    {
        [GP + 144] = h(1);
        A0 = number_of_5type_stars;
        A1 = materia_pair_id;
        system_add_pair_command_with_counter;
    }
    break;

    case 8:
    {
        [GP + 144] = h(1);
        A0 = number_of_5type_stars;
        A1 = fd;
        system_add_pair_master_materia_with_counter;
    }
    break;

    case 9:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = materia_pair_id;
        system_add_pair_magic_with_magic_counter;
    }
    break;

    case a:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = fe;
        system_add_pair_master_materia_with_counter;
    }
    break;

    case b:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = materia_pair_id;
        system_add_pair_summon_with_magic_counter;
    }
    break;

    case c:
    {
        [GP + 144] = h(0);
        A0 = number_of_5type_stars;
        A1 = ff;
        system_add_pair_master_materia_with_counter;
    }
    break;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_mp_turbo
number_of_5type_stars = A0;
materia_pair_data = A1;

materia_pair_id = materia_pair_data & ff;
materia_pair_exp = materia_pair_data >> 8;

V0 = bu[800730d0 + materia_pair_id * 14 + d];
V1 = V0 & 0f;
if (V1 == 9)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    A2 = materia_pair_exp;
    system_add_pair_magic_with_mp_turbo;
}
else if (V1 == a)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_magic_with_mp_turbo;
}
else if (V1 == b)
{
    A0 = number_of_5type_stars;
    A1 = materia_pair_id;
    A2 = materia_pair_exp;
    system_add_pair_summon_with_mp_turbo;
}
else if (V1 == c)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_summon_with_mp_turbo;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_magic_with_mp_turbo
number_of_5type_stars = A0;
materia_pair_id = A1;
materia_pair_exp = A2;

A0 = materia_pair_id;
A1 = materia_pair_exp;
system_get_materia_activated_stars;
S0 = V0;

if (S0 > 0)
{
    loop18bf8:	; 80018BF8
        A0 = bu[800730d0 + materia_pair_id * 14 + d + S0];
        system_search_existed_magic;
        magic_slot = V0;

        if (magic_slot != -1)
        {
            A1 = bu[80069554 + magic_slot * 5 + 4];
            V1 = A1 >> 5;
            A0 = V1 + number_of_5type_stars;
            if (A0 >= 6)
            {
                A0 = 5;
            }
            V0 = A0 & 7;
            V0 = V0 << 5;

            V1 = A1 & 1f;
            V1 = V1 | V0;
            [80069554 + magic_slot * 5 + 4] = b(V1);
        }

        S0 = S0 - 1;
    80018C70	bgtz   s0, loop18bf8 [$80018bf8]
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_magic_with_mp_turbo
number_of_5type_stars = A0;

S0 = 0;
loop18b2c:	; 80018B2C
    A0 = S0;
    system_search_existed_magic;
    magic_slot = V0;

    if (magic_slot != -1)
    {
        A1 = bu[80069554 + magic_slot * 5 + 4];
        V1 = A1 >> 5;
        A0 = V1 + number_of_5type_stars;
        if (A0 >= 6)
        {
            A0 = 5;
        }
        V0 = A0 & 7;
        V0 = V0 << 5;

        V1 = A1 & 1f;
        V1 = V1 | V0;
        [80069554 + magic_slot * 5 + 4] = b(V1);
    }

    S0 = S0 + 1;
    V0 = S0 < 38;
80018B98	bne    v0, zero, loop18b2c [$80018b2c]
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_summon_with_mp_turbo
number_of_5type_stars = A0;

T0 = 0;
loop18abc:	; 80018ABC
    unit_structure = w[GP + 11c];
    A1 = bu[unit_structure + 108 + 38 * 8 + T0 * 8 + 7];
    V0 = A1 >> 5;
    V1 = V0 + number_of_5type_stars;

    if (V1 >= 6)
    {
        V1 = 5;
    }

    V0 = A1 & 1f;
    V1 = V1 & 7;
    V1 = V1 << 5;
    V0 = V0 | V1;
    [unit_structure + 108 + 38 * 8 + T0 * 8 + 7] = b(V0);

    T0 = T0 + 1;
    V0 = T0 < 10;
80018B04	bne    v0, zero, loop18abc [$80018abc]
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_summon_with_mp_turbo
// there is bug here. Bost will get first 4 initializing magic as well. but maybe this data is rewritten.
number_of_5type_stars = A0;
materia_pair_id = A1;
materia_pair_exp = A2;

A0 = materia_pair_id;
A1 = materia_pair_exp;
system_get_materia_activated_stars;
A2 = V0;
if (A2 > 0)
{
    loop18a48:	; 80018A48
        V0 = bu[800730d0 + materia_pair_id * 14 + d + A2];

        V1 = w[GP + 11c];
        A3 = V1 + V0 * 8;
        V1 = bu[A3 + 108 + 7];
        V0 = V1 >> 5;
        A1 = V0 + number_of_5type_stars;
        if (A1 >= 6)
        {
            A1 = 5;
        }

        V0 = A1 & 7;
        V0 = V0 << 5;
        V1 = V1 | V0;
        [A3 + 10f] = b(V1);

        A2 = A2 - 1;
    80018A90	bgtz   a2, loop18a48 [$80018a48]
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_mp_absorb
materia_pair_data = A0;
A2 = A0;
materia_pair_id = materia_pair_data & ff;
materia_pair_exp = A1 = A0 >> 8;

V0 = bu[800730d0 + materia_pair_id * 14 + d];
V0 = V0 & 0f;
switch (V0)
{
    case 6:
    {
        A0 = materia_pair_data;
        system_add_pair_command_with_mp_absorb;
    }
    break;

    case 8:
    {
        system_add_pair_master_command_with_mp_absorb;
    }
    break;

    case 9:
    {
        A0 = materia_pair_data;
        A1 = materia_pair_exp;
        system_add_pair_magic_with_mp_absorb;
    }
    break;

    case a:
    {
        system_add_pair_master_magic_with_mp_absorb;
    }
    break;

    case b:
    {
        A0 = materia_pair_data;
        A1 = materia_pair_exp;
        system_add_pair_summon_with_mp_absorb;
    }
    break;

    case c:
    {
        system_add_pair_master_summon_with_mp_absorb;
    }
    break;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_command_with_mp_absorb
materia_pair_id = A0 & ff;

A0 = bu[800730d0 + materia_pair_id * 14 + e];
system_search_existed_command;
V1 = V0;

if (V1 != -1)
{
    V1 = bu[80069508 + V0 * 3 + 2];
    A0 = bu[GP + 134];
    V1 = V1 | A0;
    [80069508 + V0 * 3 + 2] = b(V1);
}

A0 = bu[800730d0 + materia_pair_id * 14 + f];
if (A0 == 7 || A0 == 11)
{
    system_search_existed_command;
    V1 = V0;
    if (V1 != -1)
    {
        V1 = bu[80069508 + V0 * 3 + 2];
        A0 = bu[GP + 134];
        V1 = V1 | A0;
        [80069508 + V0 * 3 + 2] = b(V1);
    }
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_command_with_mp_absorb
S0 = 0;
loop18fe0:	; 80018FE0
    A0 = bu[80069508 + S0 * 3];
    system_search_existed_command;
    if (V0 != -1)
    {
        V1 = bu[80069508 + V0 * 3 + 2];
        A0 = bu[GP + 134];
        V1 = V1 | A0;
        [80069508 + V0 * 3 + 2] = b(V1);
    }

    S0 = S0 + 1;
    V0 = S0 < 10;
80019040	bne    v0, zero, loop18fe0 [$80018fe0]
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_magic_with_mp_absorb
S1 = A0 & ff;
A0 = S1;
A1 = A1;
system_get_materia_activated_stars;
S0 = V0;
if (S0 > 0)
{
    S1 = S1 * 14;
    S2 = 800730dd;

    loop19128:	; 80019128
        V0 = S1 + S0;
        V0 = V0 + S2;
        A0 = bu[V0];
        system_search_existed_magic;
        if (V0 != -1)
        {
            V1 = bu[80069554 + V0 * 5 + 4];
            A0 = bu[GP + 134];
            V1 = V1 | A0;
            [80069554 + V0 * 5 + 4] = b(V1);
        }

        S0 = S0 - 1;
    8001917C	bgtz   s0, loop19128 [$80019128]
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_magic_with_mp_absorb
S0 = 0;
S1 = -1;

loop1907c:	; 8001907C
    A0 = S0 & ff;
    system_search_existed_magic;
    V1 = V0;
    if (V1 != -1)
    {
        80019090	sll    v0, v1, $02
        80019094	addu   v0, v0, v1
        80019098	lui    at, $8007
        8001909C	addiu  at, at, $9558 (=-$6aa8)
        800190A0	addu   at, at, v0
        800190A4	lbu    v1, $0000(at)
        800190A8	lbu    a0, $0134(gp)
        800190AC	nop
        800190B0	or     v1, v1, a0
        800190B4	lui    at, $8007
        800190B8	addiu  at, at, $9558 (=-$6aa8)
        800190BC	addu   at, at, v0
        800190C0	sb     v1, $0000(at)
    }

    S0 = S0 + 1;
    V0 = S0 < 38;
800190C8	bne    v0, zero, loop1907c [$8001907c]
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_summon_with_mp_absorb
S0 = A0 & ff;
A0 = S0;
system_get_materia_activated_stars;
A1 = V0;
if (A1 > 0)
{
    80018E38	sll    v0, s0, $02
    80018E3C	addu   v0, v0, s0
    80018E40	sll    a2, v0, $02
    80018E44	lui    a3, $8007
    80018E48	addiu  a3, a3, $30dd

    loop18e4c:	; 80018E4C
        80018E4C	addu   v0, a2, a1
        80018E50	addu   v0, v0, a3
        80018E54	lbu    v0, $0000(v0)
        80018E58	lw     v1, $011c(gp)
        80018E5C	lbu    a0, $0134(gp)
        80018E60	sll    v0, v0, $03
        80018E64	addu   v1, v1, v0
        80018E68	lbu    v0, $010f(v1)
        80018E6C	addiu  a1, a1, $ffff (=-$1)
        80018E70	or     v0, v0, a0
        80018E78	sb     v0, $010f(v1)
    80018E74	bgtz   a1, loop18e4c [$80018e4c]
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_summon_with_mp_absorb
A2 = 0;
A1 = 1c0;

loop18e98:	; 80018E98
    80018E98	addiu  a2, a2, $0001
    80018E9C	lw     v1, $011c(gp)
    80018EA0	lbu    a0, $0134(gp)
    80018EA4	addu   v1, v1, a1
    80018EA8	lbu    v0, $010f(v1)
    80018EAC	nop
    80018EB0	or     v0, v0, a0
    80018EB4	sb     v0, $010f(v1)
    80018EC0	addiu  a1, a1, $0008
    80018EB8	slti   v0, a2, $0010
80018EBC	bne    v0, zero, loop18e98 [$80018e98]
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_quadra_magic
number_of_5type_stars = A1;
A1 = A2 & ff;
V0 = bu[800730d0 + A1 * 14 + d];
A2 = A2 >> 8;
V1 = V0 & 0f;
if (V1 == 9)
{
    A0 = number_of_5type_stars;
    A1 = A1;
    A2 = A2;
    system_add_pair_magic_with_quadra_magic;
}
else if (V1 == a)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_magic_with_quadra_magic;
}
else if (V1 == b)
{
    A0 = number_of_5type_stars;
    system_add_pair_summon_with_quadra_magic;
}
else if (V1 == c)
{
    A0 = number_of_5type_stars;
    system_add_pair_master_summon_with_quadra_magic;
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_magic_with_quadra_magic
S2 = A0;
S1 = A1 & ff;
A0 = S1;
A1 = A2;
system_get_materia_activated_stars;
S0 = V0;
if (S0 > 0)
{
    loop192a0:	; 800192A0
        A0 = bu[800730d0 + S1 * 14 + d + S0];
        system_search_existed_magic;
        magic_slot = V0;

        if (magic_slot != -1)
        {
            V1 = bu[80069554 + magic_slot * 5 + 2];
            V1 = bu[80069554 + magic_slot * 5 + 3];
            V1 = V1 + 1;
            A0 = A0 + S2;
            [80069554 + magic_slot * 5 + 2] = b(V1);
            [80069554 + magic_slot * 5 + 3] = b(A0);
        }

        S0 = S0 - 1;
    80019310	bgtz   s0, loop192a0 [$800192a0]
}
L19318:	; 80019318
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_magic_with_quadra_magic
A2 = 0;
loop19348:	; 80019348
    [80069554 + A2 * 5 + 2] = b(bu[80069554 + A2 * 5 + 2] + 1);
    [80069554 + A2 * 5 + 3] = b(bu[80069554 + A2 * 5 + 2] + A0);
    A2 = A2 + 1;
    V0 = A2 < 38;
8001936C	bne    v0, zero, loop19348 [$80019348]
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_summon_with_quadra_magic
A1 = A1 & ff;
V1 = bu[800730de + A1 * 14];
V1 = V1 - 38;
[800694c4 + V1] = b(bu[800694c4 + V1] + 1);
[800694d4 + V1] = b(bu[800694d4 + V1] + A0);
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_master_summon_with_quadra_magic
V1 = 800694d4;
A1 = 800694c4;
A2 = V1 + 10;

loop19408:	; 80019408
    [A1] = b(bu[A1] + 1);
    [V1] = b(bu[V1] + A0);

    V1 = V1 + 1;
    A1 = A1 + 1;
    V0 = V1 < A2;
80019430	bne    v0, zero, loop19408 [$80019408]
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_elemental
number_of_5type_stars = A0;
materia_pair_data = A1;
equipment_type = A2; // 0 - weapon, 1 - armor

materia_pair_id = materia_pair_data & ff;
V1 = bu[800730d0 + materia_pair_id * 14 + c];
if (V1 < 20)
{
    A1 = hu[800491b0 + V1 * 2];
    A0 = A0 & ff;
    V0 = A2 & ff;
    if (V0 == 0)
    {
        V1 = w[GP + 11c];
        V0 = hu[V1 + 3c];
        V0 = A1 | V0;
        [V1 + 3c] = h[V0];
    }
    else
    {
        if (A0 == 1)
        {
            V1 = w[GP + 11c];
            V0 = hu[V1 + 3e];
            V0 = A1 | V0;
            [V1 + 3e] = h[V0];
        }
        else if (A0 == 2)
        {
            V1 = w[GP + 11c];
            V0 = hu[V1 + 40];
            V0 = A1 | V0;
            [V1 + 40] = h[V0];
        }
        else if (A0 >= 3)
        {
            V1 = w[GP + 11c];
            V0 = hu[V1 + 42];
            V0 = A1 | V0;
            [V1 + 42] = h[V0];
        }
    }
}
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// system_add_pair_with_added_effect
A1 = A1 & ff;
V0 = A1 * 14;
A2 = A2 & ff;
V1 = bu[800730d0 + V0 + a];
A0 = bu[800730d0 + V0 + 9];
V0 = bu[800730d0 + V0 + b];
V1 = V1 << 8;
A0 = A0 + V1;
V0 = V0 << 10;
A0 = A0 + V0;
if (A2 == 0)
{
    V1 = w[GP + 11c];
    V0 = w[V1 + 44];
    V0 = A1 | V0;
    [V1 + 44] = w[V0];
}
else
{
    V1 = w[GP + 11c];
    V0 = w[V1 + 48];
    V0 = A1 | V0;
    [V1 + 48] = w[V0];
}
//////////////////////////////////////////////////////////////////