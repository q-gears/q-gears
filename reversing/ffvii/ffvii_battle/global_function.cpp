////////////////////////////////
// funca5e0c
// replace ea eb ec ed ee ef f0 f1 f9 part of string with given id's
where = A0;
from = A1;
number = 0;

La5e18:	; 800A5E18
    opcode = bu[from]; from = from + 1;
    number = number + 1;
    [where] = b(opcode); where = where + 1

    if( opcode == ff )
    {
        return number;
    }

    if( opcode == f9 )
    {
        opcode1 = bu[from]; from = from + 1;
        number = number + 1;
        [where] = b(opcode1); where = where + 1;
    }
    else
    {
        if( opcode == ea || opcode == eb || opcode == ec || opcode == ed || opcode == ee || opcode == ef || opcode == f0 || opcode == f1 )
        {
            opcode1 = bu[from]; from = from + 1;
            opcode2 = bu[from]; from = from + 1;

            if( opcode1 == ff || opcode1 == opcode2 )
            {
                V0 = hu[A2];
                A2 = A2 + 2;
                opcode1 = V0 >> 8;
            }

            [where] = b(opcode1); where = where + 1;
            [where] = b(opcode2); where = where + 1;
            number = number + 2;
        }
    }
800A5EA0	j      La5e18 [$800a5e18]
////////////////////////////////



////////////////////////////////
// funca5eb0
A2 = A1;         // address of id's of items
A1 = A0;        // real address where string was copied
A0 = SP + 10;   // copy here
funca5e0c; // replace ea eb ec ed ee ef f0 f1 f9 part of string with given id's

string_size = V0;

if( (w[800f4300] + string_size) >= 801 )
{
    [800f4300] = w(0);
}

A3 = w[800f4304];
[800f4280 + A3 * 2] = h(w[800f4300]);
[800f4304] = w((w[800f4304] + 1) & 3f);

if( string_size > 0 )
{
    A1 = 0;
    loopa5f40:	; 800A5F40
        V0 = 800f3a80 + w[800f4300] + A1;
        [V0] = b(bu[SP + 10 + A1]);

        A1 = A1 + 1;
        V0 = A1 < string_size;
    800A5F60	bne    v0, zero, loopa5f40 [$800a5f40]
}

[800f4300] = w(w[800f4300] + string_size);
return A3;
////////////////////////////////



////////////////////////////////
// battle_add_string_to_display
unit_id = A0;
A0 = A1;
S2 = A2;
S1 = A3; // address where id stored
func1521c; // we copy kernel couldn't sense here

A0 = V0; // address of string
A1 = S1;
funca5eb0;

A0 = unit_id;
A1 = 2;
A2 = S2;
A3 = V0 + 100; // string index
funca31a0;
////////////////////////////////



////////////////////////////////
// funca7254
unit_id = A1; // attacker_id
// A0 = 2;
// A2 = 15;
// A3 = 1;

T0 = w[800f4914 + A0 * 4];

if( bu[800f4308 + A0 * 200 + T0 * 4] == ff )
{
    [800f4308 + A0 * 200 + T0 * 4 + 2] = h(A3);
    [800f4308 + A0 * 200 + T0 * 4 + 1] = b(A2);
    [800f4308 + A0 * 200 + T0 * 4 + 0] = b(A1);
    A0 = T0;
    battle_increment_around_128;

    [800f4914 + A0 * 4] = w(V0);
}
////////////////////////////////



////////////////////////////////
// battle_increment_around_128
return (A0 + 1) & 7f;
////////////////////////////////



////////////////////////////////
// battle_get_point_by_model_bone
S0 = A2;
[S0 + 0] = h(hu[801518e4 + A0 * b9c + 174 + A1 * 34 + 14] - hu[800fa63c + 14]);
[S0 + 2] = h(hu[801518e4 + A0 * b9c + 174 + A1 * 34 + 18] - hu[800fa63c + 18]);
[S0 + 4] = h(hu[801518e4 + A0 * b9c + 174 + A1 * 34 + 1c] - hu[800fa63c + 1c]);

A0 = 800fa63c;
A1 = SP + 10;
system_transponate_matrix;

A0 = SP + 10;
A1 = S0;
A2 = A1;
system_matrix_vector_multiply;
////////////////////////////////



////////////////////////////////
// battle_calculate_middle_point_from_target_mask_units_position
min_x = 7fff;
max_x = -8000;
min_z = 7fff;
max_z = -8000;

A3 = 0;
loopd5508:	; 800D5508
    V0 = A0 >> A3;
    if (V0 & 1)
    {
        V1 = h[801518e4 + A3 * b9c + 168]; // X
        if (V1 < min_x)
        {
            min_x = V1;
        }
        if (max_x < V1)
        {
            max_x = V1;
        }

        V1 = h[801518e4 + A3 * b9c + 16c]; // Z
        if (V1 < min_z)
        {
            min_z = V1;
        }

        if (max_z < V1)
        {
            max_z = V1;
        }
    }

    A3 = A3 + 1;
    V0 = A3 < a;
800D5568	bne    v0, zero, loopd5508 [$800d5508]

[A1 + 0] = h((min_x + max_x) / 2);
[A1 + 2] = h(0);
[A1 + 4] = h((min_z + max_z) / 2);

return A1;
////////////////////////////////



////////////////////////////////
// funca2f4c
pos1 = w[800f3944];
pos2 = w[800f3948];

[80163798 + pos1 * c + 2] = b(0);
[80163798 + pos1 * c + 3] = b(0);
[80163798 + pos1 * c + a] = h(pos2);

if (pos2 < 40)
{
    [800f3944] = w(pos1 + 1);
}
else
{
    A0 = 28;
    func155a4;
}

return 80163798 + pos1 * c;
////////////////////////////////



////////////////////////////////
// funcb1218
modifier = b[800f5bb8 + A0 * 44 + 20 + A2];

return A1 + (A1 * modifier) / 64;
////////////////////////////////



////////////////////////////////
// funca31a0
S0 = A0; // unit id
S1 = A1; // 2
S2 = A2;
S3 = A3; // string index + 100
funca2f4c; // get next position in some action queue

[V0 + 0] = b(S0);
[V0 + 1] = b(S1);
[V0 + 5] = b(S2);
[V0 + 6] = h(S3);
[V0 + 8] = h(ffff);
[V0 + a] = h(ffff);
////////////////////////////////



////////////////////////////////
// battle_add_action_to_battle_queue
[SP + 10] = b(A1); // priority
[SP + 12] = b(A0); // unit id
[SP + 13] = b(A2); // action id
[SP + 14] = h(A3); // attack id
[SP + 16] = h(A4); // target mask
A0 = SP + 10;
funca3d4c;
////////////////////////////////



////////////////////////////////
// funca3d4c
priority = bu[A0 + 0];
A3 = 0;

loopa3d6c:	; 800A3D6C
    if( bu[800f6934 + A3] == ff ) // if slot empty
    {
        V0 = bu[800f6b9b + priority];
        [A0 + 1] = b(V0);
        [800f6b9b + priority] = b(V0 + 1);

        [800f6934 + A3 + 0] = h(h[A0 + 0]);
        [800f6934 + A3 + 2] = h(h[A0 + 2]);
        [800f6934 + A3 + 4] = h(h[A0 + 4]);
        [800f6934 + A3 + 6] = h(h[A0 + 6]);

        [800f7dde] = h(priority);

        if (priority >= 2)
        {
            unit_id = b[A0 + 2];
            [800f83e0 + unit_id * 68 + 4] = w(w[800f83e0 + unit_id * 68 + 4] & ffffffdf);

            if( bu[A0 + 3] & 003f == 13 ) // if action id == defend
            {
                [800f83e0 + unit_id * 68 + 4] = w(w[800f83e0 + unit_id * 68 + 4] | 00000020);
            }
        }

        return;
    }

    A3 = A3 + 8;
    V0 = A3 < 200;
800A3E88	bne    v0, zero, loopa3d6c [$800a3d6c]
////////////////////////////////
