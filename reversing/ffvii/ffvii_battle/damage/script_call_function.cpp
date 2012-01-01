////////////////////////////////
// funca6000
unit_id       = A0; // unit_id
script_to_run = A1;
argument2     = S4 = A2;
S1 = 0;
S3 = FFFF (-1);
V1 = hu[800f7dbc];
V0 = 1 << script_to_run;
V1 = V1 | V0;
[800f7dbc] = h(V1);

// enemy
if (unit_id >= 4)
{
    A0 = 800F6DA4;
    A1 = h[80163658 + (unit_id - 4) * 10]; // enemy_ai_id
}
// party
else if (unit_id < 3)
{
    S3 = b[801636b8 + unit_id * 10];
    if (S3 != -1)
    {
        V1 = bu[800e7a58 + S3];
        if (V1 != ff)
        {
            S3 = V1;
        }
    }

    A0 = 80082884;
    A1 = S3;
}
else
{
    return;
}

A0 = A0;
A1 = A1;
A2 = script_to_run;
get_enemy_ai_script_offset;
S1 = V0;

if (S1 != 0)
{
    S0 = 0;
    A0 = SP + 10;

    loopa60d8:	; 800A60D8
        V0 = bu[800F83E0 + S0 * 68 + 13];
        [A0 + 0] = b(V0);

        V0 = bu[800F83E0 + S0 * 68 + 10];
        [A0 + 1] = b(V0);

        V0 = bu[800F83E0 + S0 * 68 + 11];
        [A0 + 2] = b(V0);

        S0 = S0 + 1;
        A0 = A0 + 5;
        V0 = S0 < A;
    800A6118	bne    v0, zero, loopa60d8 [$800a60d8]

    A0 = unit_id;
    A1 = argument2;
    A2 = A2;
    funcb2a2c;

    A0 = unit_id;
    A1 = S1;
    A2 = S3;
    battle_opcodes_cycle;

    S0 = 0;
    S2 = 0;
    S3 = 0;

    loopa6148:	; 800A6148
        S1 = SP + 10 + S3;
        V0 = bu[S1];
        A2 = bu[800F83F3 + S2];
        if (V0 != A2)
        {
            A0 = S0;
            A1 = 4;
            A3 = 10;
            funca31a0;
        }

        A1 = bu[S1 + 2];
        A2 = bu[800F83F1 + S2];
        if (A1 != A2)
        {
            A0 = S0;
            A3 = 0;
            funca34cc;
        }

        S2 = S2 + 68;
        S0 = S0 + 1;
        S3 = S3 + 5;
        V0 = S0 < A;
    800A61A8	bne    v0, zero, loopa6148 [$800a6148]
}

return;
////////////////////////////////



////////////////////////////////
// funcb2a2c
S4 = A0;
[800f4ac8] = w(A1); // some priority
[800f4acc] = w(A2);
if (S4 >= 0)
{
    800B2A64	lui    v0, $8010
    800B2A68	lhu    v0, $83bc(v0)
    800B2A6C	lui    v1, $8016
    800B2A70	lhu    v1, $375e(v1)
    800B2A74	lui    a0, $8016
    800B2A78	lhu    a0, $3766(a0)
    800B2A7C	lui    a1, $8010
    800B2A80	lhu    a1, $83be(a1)
    800B2A84	and    v0, v1, v0
    800B2A88	nor    a2, zero, a0
    800B2A8C	and    s0, v0, a2
    800B2A90	and    s3, v0, a0
    800B2A94	and    v1, v1, a1
    800B2A98	and    s1, v1, a2
    800B2A9C	and    s2, v1, a0
    800B2AA0	jal    funcb0eb4 [$800b0eb4]
    800B2AA4	addu   a0, s4, zero
    if (V0 != 0)
    {
        800B2AAC	addu   v0, s0, zero
        800B2AB0	addu   s0, s1, zero
        800B2AB4	addu   s1, v0, zero
        800B2AB8	addu   v0, s3, zero
        800B2ABC	addu   s3, s2, zero
        800B2AC0	addu   s2, v0, zero
    }

    800B2AC4	ori    v0, zero, $0001
    800B2AC8	lui    v1, $800f
    800B2ACC	lhu    v1, $7dce(v1)
    800B2AD0	sllv   v0, s4, v0
    800B2AD4	lui    at, $8010
    800B2AD8	sh     v0, $83b0(at)
    800B2ADC	lui    v0, $8016
    800B2AE0	lhu    v0, $375a(v0)
    800B2AE4	lui    a0, $800a
    800B2AE8	lw     a0, $d260(a0)
    800B2AEC	nor    v1, zero, v1
    800B2AF0	and    s0, s0, v1
    800B2AF4	lui    v1, $8010
    800B2AF8	lhu    v1, $83ae(v1)
    800B2AFC	lui    at, $8010
    800B2B00	sh     s1, $83b4(at)
    800B2B04	lui    at, $8010
    800B2B08	sh     s2, $83b6(at)
    800B2B0C	lui    at, $8010
    800B2B10	sh     s3, $83ba(at)
    800B2B14	lui    at, $8010
    800B2B18	sh     s0, $83b8(at)
    800B2B1C	lui    at, $8010
    800B2B20	sh     s0, $83b2(at)
    [800f83a4 + 38] = w(A0);
    V0 = V0 & V1;
    [800f83a4 + 1c] = h(V0);
}
////////////////////////////////



////////////////////////////////
// get_enemy_ai_script_offset
offset_to_ai  = A0;
enemy_ai_id   = A1;
script_to_run = A2;
V1 = 0;

if (enemy_ai_id != -1)
{
    offset_to_enemy_ai = hu[offset_to_ai + enemy_ai_id * 2];

    if (offset_to_enemy_ai != FFFF)
    {
        offset_to_enemy_ai = offset_to_enemy_ai & FFFE;

        offset_to_script = [offset_to_ai + offset_to_enemy_ai + script_to_run * 2];
        if (offset_to_script != FFFF)
        {
            V1 = offset_to_ai + offset_to_enemy_ai + offset_to_script;
        }
    }
}

return V1;
////////////////////////////////
