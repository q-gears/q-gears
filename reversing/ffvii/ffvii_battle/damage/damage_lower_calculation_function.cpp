////////////////////////////////////////////////////
// lower_function_00
address = w[80063014];
[address + 218] = w(w[address + 218] | 0002);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_01
address = w[80063014];

Attack        = w[address + 4c];
Level         = w[address + 4];
Status        = w[address + c8];
DefNum        = w[address + 210];
PowerModifier = w[address + 48];

V0 = w[address + 6с];
if ((V0 & 2000) == 0)
{
    [address + 220] = w(w[address + 220] | 0002);
}


Damage = (Attack + ((Level + Attack) / 20) * ((Level * Attack) / 20)) * ((200 - DefNum) / 200) * (PowerModifier / 10);



// if critical
if (w[address + 220] & 0002)
{
    Damage = Damage * 2;
}



// if attacker is in berserk
if (Status & 00800000)
{
    Damage = Damage * 6;
}



// back row modificator
V1 = w[address + 208];
V0 = w[800f83e0 + V1 * 68 + 4];
V0 = V0 & 00000040; // back row
A2 = 0 < V0;
V1 = w[address + 50];
V0 = w[address + 28];
if (V1 & 0020 || V0 == 20)
{
    V0 = w[address + 0];
    V0 = w[800f83e0 + V0 * 68 + 4];
    if (V0 & 00000040) // back row
    {
        A2 = 1;
    }
}
else
{
    A2 = 0;
}

if (A2 != 0)
{
    Damage = Damage / 2;
}



target_id = w[address + 208];
V1 = w[800f83e0 + target_id * 68 + 4];
if (V1 & 00000020)
{
    Damage = Damage / 2;
}



V0 = w[address + 234];
if (V0 & 0001)
{
    V0 = bu[800f83e0 + target_id * 68 + 12];
    Damage = Damage * V0 / 8;
}



// if caster is frog
if (Status & 00000800)
{
    Damage = Damage / 4;
}

A0 = Damage;
battle_add_sadness_modifier;
A0 = V0;

A1 = 0;
battle_add_split_quater_modifier;
A0 = V0;

battle_add_barriers_modifier;
A0 = V0;



// if attacker is small
if (Status & 00001000)
{
    A0 = 0;
}

battle_add_random_modifier_and_zero_check;

[address + 214] = w(V0);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_02
address = w[80063014];

Attack        = w[address + 4c];
Level         = w[address + 4];
DefNum        = w[address + 210];
PowerModifier = w[address + 48];
TargetType    = w[address + 50];

Damage = ((Attack + Level) * 6) * ((200 - DefNum) / 200) * (PowerModifier / 10);

A0 = Damage;
battle_add_sadness_modifier;
A0 = V0;

S0 = TargetType & 0c;
S0 = S0 XOR 04;
S0 = S0 < 1;
A1 = S0;
battle_add_split_quater_modifier;
A0 = V0;
battle_add_barriers_modifier;
A0 = V0;
battle_add_random_modifier_and_zero_check;
[address + 214] = w(V0);

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_03
address = w[80063014];
V0 = w[address + 6C];
if (V0 & 1) // if attack hp
{
    V1 = w[address + 208];
    A0 = w[800f83e0 + V1 * 68 + 2c];
}
else // else attack mp
{
    V1 = w[address + 208];
    A0 = hu[800f83e0 + V1 * 68 + 28];
}

PowerModifier = w[address + 48];
V1 = A0 * PowerModifier;

V0 = w[address + ac];
if (V0 == 0)
{
    A0 = V1 >> 5;
}
else
{
    A0 = V1 >> 6;
}

[address + 214] = w(A0);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_04
address = w[80063014];
V0 = w[address + 6C];
if (V0 & 1) // if attack hp
{
    V1 = w[address + 208];
    A0 = w[800f83e0 + V1 * 68 + 30];
}
else // else attack mp
{
    V1 = w[address + 208];
    A0 = hu[800f83e0 + V1 * 68 + 2a];
}

PowerModifier = w[address + 48];
V1 = A0 * PowerModifier;

V0 = w[address + ac];
if (V0 == 0)
{
    A0 = V1 >> 5;
}
else
{
    A0 = V1 >> 6;
}

[address + 214] = w(A0);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_05
address = w[80063014];
power_modifier = w[address + 48];
base_damage = w[address + 4c];
attacker_level = w[address + 4];

A0 = (base_damage + attacker_level) * 6 + power_modifier * 16;
A1 = 0;
battle_add_split_quater_modifier;

A0 = V0;
battle_add_barriers_modifier;

A0 = V0;
battle_add_random_modifier_and_zero_check;

[address + 214] = w(V0);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_06
address = w[80063014];
[address + 214] = w(w[address + 48] * 14);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_07
address = w[80063014];

defense = w[address + 210];
power_modifier = w[address + 48];
A0 = (power_modifier * (200 - defense)) / 200;
battle_add_random_modifier_and_zero_check;

[address + 214] = w(V0);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_08
address = w[80063014];
if (w[address + 230] & 40)
{
    [address + 230] = w(01);
}
else
{
    [address + 230] = w(80);
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_09
address = w[80063014];

[address + 4c] = w(w[address + d8] * 2);
lower_function_01;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_0a
address = w[80063014];
A0 = w[address + 18]; // target mask
count_active_bits;

A0 = 0;
if (V0 != 0)
{
    power_modifier = w[address + 48];
    A0 = (power_modifier - 1 + V0) / V0;
}

[address + 214] = w(A0);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_10
address = w[80063014];
V1 = w[address + 0];
[address + 214] = w(hu[800f5bb8 + V1 * 44 + 3c]);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_11
address = w[80063014];
A0 = w[address + 0];
[address + 214] = w(w[800f83e0 + A0 * 68 + 30] - hu[800f5bb8 + A0 * 44 + 3c]);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// lower_function_18
address = w[80063014];
V0 = w[address + 4];
V1 = 66666667;
T0 = hi(V0 * V1);
V0 = V0 >> 1f;
V1 = T0 >> 2;
S1 = V1 - V0;
if (S1 < 2)
{
    S1 = 2;
}
else if (S1 >= 7)
{
    S1 = 6;
}
else
{
    V1 = ff;
}

800AE0DC	ori    s0, zero, $0003
800AE0E0	lui    v0, $8016
800AE0E4	addiu  v0, v0, $3777

loopae0e8:	; 800AE0E8
800AE0E8	sb     v1, $0000(v0)
800AE0EC	addiu  s0, s0, $ffff (=-$1)
800AE0F0	bgez   s0, loopae0e8 [$800ae0e8]
800AE0F4	addiu  v0, v0, $ffff (=-$1)
800AE0F8	addu   s0, zero, zero
800AE0FC	blez   s1, Lae194 [$800ae194]
800AE100	addu   s2, zero, zero

loopae104:	; 800AE104
    800AE104	jal    func14ba8 [$80014ba8]
    800AE108	ori    a0, zero, $0006
    800AE10C	addu   a0, v0, zero
    800AE110	sll    v0, s0, $02
    800AE114	addiu  v1, sp, $0010
    800AE118	addu   v0, v0, v1
    800AE11C	sw     a0, $0000(v0)
    800AE120	addiu  v0, s2, $0001
    800AE124	addu   s2, v0, a0
    800AE128	andi   v0, s0, $0001
    800AE12C	beq    v0, zero, Lae168 [$800ae168]
    800AE130	srl    v0, s0, $1f
    800AE134	addu   v0, s0, v0
    800AE138	sra    v0, v0, $01
    800AE13C	lui    at, $8016
    800AE140	addu   at, at, v0
    800AE144	lbu    v1, $3774(at)
    800AE148	sll    a0, a0, $04
    800AE14C	andi   v1, v1, $000f
    800AE150	or     a0, a0, v1
    800AE154	lui    at, $8016
    800AE158	addu   at, at, v0
    800AE15C	sb     a0, $3774(at)
    800AE160	j      Lae180 [$800ae180]
    800AE164	nop

    Lae168:	; 800AE168
    800AE168	addu   v0, s0, v0
    800AE16C	sra    v0, v0, $01
    800AE170	ori    v1, a0, $00f0
    800AE174	lui    at, $8016
    800AE178	addu   at, at, v0
    800AE17C	sb     v1, $3774(at)

    Lae180:	; 800AE180
    800AE180	jal    increment_seed_for_random [$80014b54]
    800AE184	addiu  s0, s0, $0001
    800AE188	slt    v0, s0, s1
800AE18C	bne    v0, zero, loopae104 [$800ae104]

Lae194:	; 800AE194
A2 = 0;
S0 = 0;
A3 = SP + 10;

loopae1a0:	; 800AE1A0
    A1 = 0;
    A0 = 0;
    if (S1 > 0)
    {
        V1 = A3;

        loopae1b0:	; 800AE1B0
            V0 = w[V1];
            if (V0 == S0)
            {
                A0 = A0 + 1;
            }

            A1 = A1 + 1;
            V1 = V1 + 4;
            V0 = A1 < S1;
        800AE1CC	bne    v0, zero, loopae1b0 [$800ae1b0]
    }

    if (A2 < A0)
    {
        A2 = A0;
    }

    S0 = S0 + 1;
    V0 = S0 < 6;
800AE1EC	bne    v0, zero, loopae1a0 [$800ae1a0]

[address + 214] = w(S2 * A2 * 64);
////////////////////////////////////////////////////