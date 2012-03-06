0x73 PGTDR 800ca254
0x74 GETPC 800d2f3c
0x75 PXYZI 800ca77c
0xC1 AXYZI 800ca5d4
0x08 JOIN 800cfe78
0x2A PMOVA 800c7c3c
0x34 PDIRA 800c81c0
0x35 PTURA 800c8588
0x26 BLINK 800d4420



////////////////////////////////////////////////////////
// 0x09 SPLIT
V0 = bu[800722C4];
[800E48F0] = b(V0);

S2 = bu[8009D392]; // second party member
if (S2 != FF)
{
    A0 = 1;
    A1 = 4;
    read_memory_block_two_bytes;
    x1 = V0;

    A0 = 2;
    A1 = 6;
    read_memory_block_two_bytes;
    y1 = V0;

    A0 = 3;
    A1 = 8;
    read_memory_block_one_byte;
    dir1 = V0;

    V1 = bu[800722C4];
    A0 = hu[800831FC + V1 * 2];
    field_file_offset = w[8009C6DC];
    speed = bu[field_file_offset + A0 + E];

    A0 = bu[8009AD30 + S2];
    A1 = x1;
    A2 = y1;
    A3 = dir1;
    [SP + 10] = w(speed);
    funcd0938;
    S2 = V0;
}
else
{
    S2 = 1;
}

S3 = bu[8009D393]; // third party member
if (S3 != FF)
{
    A0 = 4;
    A1 = 9;
    read_memory_block_two_bytes;
    x2 = V0;

    A0 = 5;
    A1 = B;
    read_memory_block_two_bytes;
    y2 = V0;

    A0 = 6;
    A1 = D;
    read_memory_block_one_byte;
    dir2 = V0;

    V1 = w[800722C4];
    A0 = hu[800831FC + V1 * 2];
    field_file_offset = w[8009C6DC];
    speed = bu[field_file_offset + A0 + E];

    A0 = bu[8009AD30 + S3];
    A1 = x2
    A2 = y2;
    A3 = dir2;
    [SP + 10] = w(speed);
    funcd0938;
    V1 = V0;
}
else
{
    V1 = 1;
}



// if all characters finish moving
if (S2 != 0 && V1 != 0)
{
    // set solid on for all characters
    party_id = 0;
    loopd0324:	; 800D0324
        character_id = bu[8009D391 + A1];
        if (character_id != FF)
        {
            entity_id = bu[8009AD30 + character_id];
            [80081D90 + entity_id] = b(0);
            if (A1 == 0 && entity_id != FF)
            {
                // set solid on
                model_id = bu[8007EB98 + entity_id];
                V1 = w[8009C544];
                [V1 + model_id * 84 + 59] = b(0);
            }
        }

        party_id = party_id + 1;
        V0 = party_id < 3;
    800D03D0	bne    v0, zero, loopd0324 [$800d0324]

    A0 = w[8009C6E0];
    previous_uc = bu[80081DC4];
    [A0 + 32] = b(previous_uc); // set UC

    [800E48F0] = b(FF);

    // move csript pointer by F
    A1 = bu[800722C4];
    V1 = hu[800831FC + A1 * 2];
    V1 = V1 + F;
    [800831FC + A1 * 2] = h(V1);

    return 0;
}
else
{
    V0 = w[8009C6E0];
    [V0 + 32] = b(1); // set UC

    character_id = bu[8009D391]; // character in slot 1
    if (character_id != FF)
    {
        entity_id = bu[8009AD30 + character_id];
        if (entity_id != FF)
        {
            [80081D90 + entity_id] = b(1);

            A0 = w[8009C544];
            model_id = bu[8007EB98 + entity_id];
            [A0 + model_id * 84 + 5D] = b(0);
            [A0 + model_id * 84 + 6A] = h(0);
            [A0 + model_id * 84 + 59] = b(1); // solid off
        }
    }
}

return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x33 UC
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
V0 = bu[V0 + V1 + 1];

V1 = w[8009C6E0];
[V1 + 32] = b(V0);
[80081DC4] = b(V0);

V0 = bu[80081DC4];
if (V0 == 0)
{
    V0 = w[8009C6E0];
    V0 = [V0 + 2A];
    [800756E8 + V0] = b(00);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x6D IDLCK
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A2 = V0 + V1;
V1 = bu[A2 + 2];
V0 = bu[A2 + 1];
V1 = V1 << 8;
V0 = V0 | V1; // xxxxxxxx triangle id
A0 = V0;
A1 = V0 >> 3; // 000xxxxx
V0 = A1 << 3; // xxxxx000
V1 = bu[A2 + 3];

A2 = A0 - V0; // 00000xxx

if (V1 != 0)
{
    V0 = w[8009C6E0];
    V0 = V0 + A1;
    V1 = 1 << A2;
    A0 = [V0 + B2];
    A0 = A0 | V1;
}
else
{
    V0 = w[8009C6E0];
    V1 = 1 << A2;
    V0 = V0 + A1;
    A0 = [V0 + B2];
    V1 = 0 NOR V1;
    A0 = A0 & V1;
}

[V0 + B2] = b(A0);

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x7E TLKON
V1 = bu[800722C4];
A0 = bu[8007EB98 + V1];

if (A0 != FF)
{
    A0 = hu[800831FC + V1 * 2];
    V1 = w[8009C6DC];
    V1 = bu[V1 + A0 + 1];
    V0 = w[8009C544];
    [V0 + A0 * 84 + 5B] = b(V1);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xA0 PC
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V0 = w[8009C6DC];
A2 = bu[V0 + V1 + 1];

[8009AD30 + A2] = b(A0); // assign entity to pc

V0 = bu[8009D391]; // party info (1st character)

if (V0 == A2)
{
    V0 = bu[800722C4];
    V0 = [8007EB98 + V0];

    V1 = w[8009C6E0];
    [V1 + 2A] = h(V0);
}
else
{
    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = w[8009C544];
    [V0 + V1 * 84 + 59] = b(01);
    [V0 + V1 * 84 + 5B] = b(01);
    [V0 + V1 * 84 + 5C] = b(00);
}

// move pointer by 2
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 2;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xA1 CHAR
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model_offset  = model_data_offset + current_model * 84;

V1 = bu[8009C6C4];
V0 = V1 + 1;
[8009C6C4] = b(V0);
[8007EB98 + current_entity] = b(V1);

A0 = hu[800831FC + current_entity * 2]; // get current entity script pointer
V1 = bu[8007EB98 + current_entity];     // get current entity model id

V1 = w[8009C6DC];           // current field file offset
V1 = V1 + A0;               // current entity script pointer in global offset

V1 = bu[V1 + 1];            // read second byte
[current_model_offset + 66] = h(V1);

V1 = bu[8007EB98 + A1];
[current_model_offset + 5C] = b(01);

V1 = bu[8007EB98 + current_entity];
[current_model_offset + 57] = b(current_entity);

// move pointer by 2
V0 = hu[800831FC + current_entity * 2];
V0 = V0 + 2;
[800831FC + current_entity * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xA4 VISI
V1 = bu[800722C4];
A0 = bu[8007EB98 + V1];

if (A0 != FF)
{
    V0 = A0 * 84;
    A0 = hu[800831FC + V1 * 2];
    V1 = w[8009C6DC];
    V1 = V1 + A0;
    V1 = bu[V1 + 1];
    A0 = w[8009C544];
    V0 = V0 + A0;
    [V0 + 5C] = b(V1);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xA5 XYZI
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;

if (current_model != FF)
{
    A0 = 1;
    A1 = 3;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 0C] = w(V0);

    A0 = 2;
    A1 = 5;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 10] = w(V0);

    A0 = 3;
    A1 = 7;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 14] = w(V0);

    A0 = 4;
    A1 = 9;
    read_memory_block_two_bytes;
    [current_model_offset + 72] = h(V0);
}

// move pointer by B
V0 = hu[800831FC + current_entity * 2];
V0 = V0 + B;
[800831FC + current_entity * 2] = h(V0);

return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xA6 XYI
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;

if (current_model != FF)
{
    A0 = 1;
    A1 = 3;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 0C] = w(V0);

    A0 = 2;
    A1 = 5;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 10] = w(V0);

    A0 = 3;
    A1 = 7;
    read_memory_block_two_bytes;
    [current_model_offset + 72] = w(V0);
}

// move pointer by 9
V0 = hu[800831FC + current_entity * 2];
V0 = V0 + 9;
[800831FC + current_entity * 2] = h(V0);

return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xA7 XYZ
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;

if (current_model != FF)
{
    A0 = 1;
    A1 = 3;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 0C] = w(V0);

    A0 = 2;
    A1 = 5;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 10] = w(V0);

    A0 = 3;
    A1 = 7;
    read_memory_block_two_bytes;
    V0 = V0 << C;
    [current_model_offset + 14] = w(V0);
}

// move pointer by 9
V0 = hu[800831FC + current_entity  * 2];
V0 = V0 + 9;
[800831FC + current_entity  * 2] = h(V0);

return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
0xA8 MOVE
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831FC + current_entity * 2;
game_data_offset      = w[8009C6E0];
movement_speed        = hu[current_model_offset + 70]



if (current_model == FF) // if not visible entity
{
    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);

    return 0;
}

// init some value
[current_model_offset + 68] = h(0);
// not lock rotation
[current_model_offset + 37] = b(0);

// set destination X
A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 78] = w(V0);

// set destination Y
A0 = 2;
A1 = 4;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 7C] = w(V0);



A0 = hu[game_data_offset + 10];
if (A0 * 3 < movement_speed)
{
    V1 = bu[current_model_offset + 5E];

    if (V1 == 2)
    {
        [800756E8 + current_model] = b(01);

        A1 = bu[current_model_offset + 5D];

        if (A0 != 1)
        {
            [current_model_offset + 5D] = b(01);
            [current_model_offset + 6A] = h(00);

            return 1;
        }

        A0 = h[current_model_offset + 6A];

        if (A0 == 1)
        {
            return 1;
        }
        elseif (A0 == 2)
        {
            [current_model_offset + 5D] = b(00);
            [current_model_offset + 6A] = b(00);

            [800756E8 + current_model] = b(00);

            V0 = hu[script_pointer_offset];
            V0 = V0 + 6;
            [script_pointer_offset] = h(V0);
            return 0;
        }

        [current_model_offset + 5D] = b(01);
        [current_model_offset + 6A] = b(00);

        return 1;
    }

    [current_model_offset + 5E] = b(02);
}
else
{
    V1 = bu[current_model_offset + 5E];

    if (V1 == 1)
    {
        [800756E8 + current_model] = b(01);

        A1 = bu[current_model_offset + 5D];

        if (A1 != 1)
        {
            [current_model_offset + 5D] = b(01);
            [current_model_offset + 6A] = b(00);

            return 1;
        }

        A0 = h[current_model_offset + 6A];

        if (A0 == 1)
        {
            return 1;
        }
        elseif (A0 == 2)
        {
            [current_model_offset + 5D] = b(00);
            [current_model_offset + 6A] = b(00);

            [800756E8 + current_model] = b(00);

            V0 = hu[script_pointer_offset];
            V0 = V0 + 6;
            [script_pointer_offset] = h(V0);
            return 0;
        }

        [current_model_offset + 5D] = b(01);
        [current_model_offset + 6A] = b(00);

        return 1;
    }

    [current_model_offset + 5E] = b(01);
}



[current_model_offset + 60] = h(10);
[current_model_offset + 62] = h(00);

V1 = w[8008357C];
A1 = bu[V1 + current_model * 8 + 04];
V1 = w[8004A62C];
V1 = w[V1 + 04];

A0 = w[V1 + A1 * 24 + 1C];
A1 = hu[V1 + A1 * 24 + 1A];

V0 = bu[80074F02 + current_model * 84];
V0 = hu[A0 + A1 + V0 * 10];
V0 = V0 - 1;
[current_model_offset + 64] = h(V0)

[800756E8 + current_model] = b(01);

A1 = bu[current_model_offset + 5D];

if (A1 != 1)
{
    [current_model_offset + 5D] = b(01);
    [current_model_offset + 6A] = b(00);

    return 1;
}

A0 = h[current_model_offset + 6A];

if (A0 == A1)
{
    return 1;
}

if (A0 == 2)
{
    [current_model_offset + 5D] = b(00);
    [current_model_offset + 6A] = b(00);

    [800756E8 + current_model] = b(00);

    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);

    return 0;
}

[current_model_offset + 5D] = b(01);
[current_model_offset + 6A] = b(00);
return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xA9 CMOVE
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831FC + current_entity * 2;

if (current_model == FF) // if not visible entity
{
    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);

    return 0;
}

// init some value
[current_model_offset + 68] = h(0);
// lock rotation
[current_model_offset + 37] = b(1);

// set destination X
A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 78] = w(V0);

// set destination Y
A0 = 2;
A1 = 4;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 7C] = w(V0);

A1 = [current_model_offset + 5D];

if (A1 != 1)
{
    [current_model_offset + 5D] = b(1);
    [current_model_offset + 6A] = h(0);
    return 1;
}

A0 = h[current_model_offset + 6A];
if (A0 == 1)
{
    return 1;
}

if (A0 == 2)
{
    // unlock rotation
    [current_model_offset + 37] = b(0);
    [current_model_offset + 5D] = b(0);
    [current_model_offset + 6A] = b(0);

    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);
    return 0;
}

[current_model_offset + 5D] = b(1);
[current_model_offset + 6A] = h(0);
return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xAA MOVA
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A0 = bu[V0 + V1 + 1];
funcc7d5c;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xAB TURA
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = bu[V0 + V1 + 1];
funcc8634;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xAD FMOVE
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831FC + current_entity * 2;

if (current_model == FF) // if not visible entity
{
    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);

    return 0;
}

[current_model_offset + 68] = h(0);
[current_model_offset + 37] = b(0);

// set destination X
A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 78] = w(V0);

// set destination Y
A0 = 2;
A1 = 4;
read_memory_block_two_bytes;
V0 = V0 << 0C;
[current_model_offset + 7C] = w(V0);

A1 = [current_model_offset + 5D];
if (A1 != 1)
{
    [current_model_offset + 5D] = b(1);
    [current_model_offset + 6A] = h(0);
    return 1;
}

A0 = h[current_model_offset + 6A];
if (A0 == 1)
{
    return 1;
}

if (A0 == 2)
{
    [current_model_offset + 5D] = b(0);
    [current_model_offset + 6A] = b(0);

    V0 = hu[script_pointer_offset];
    V0 = V0 + 6;
    [script_pointer_offset] = h(V0);
    return 0;
}

[current_model_offset + 5D] = b(1);
[current_model_offset + 6A] = h(0);
return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB2 MSPED
current_entity        = bu[800722C4];
model_data_offset     = w[8009C544];
current_model         = bu[8007EB98 + current_entity];
current_model_offset  = model_data_offset + current_model * 84;
script_pointer_offset = 800831FC + current_entity * 2;
game_data_offset      = w[8009C6E0];

if (current_model != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;

    V1 = h[game_data_offset + 10];
    HI/LO = V0 * V1;
    A0 = LO;
    V0 = A0 >> 09;
    [current_model_offset + 70] = h(V0);
}

// move pointer by 4
V0 = hu[script_pointer_offset];
V0 = V0 + 4;
[script_pointer_offset] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB3 DIR
A0 = bu[800722C4];
V1 = bu[8007EB98 + A0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_one_byte;
    V1 = bu[800722C4];
    V1 = bu[8007EB98 + V1];
    A2 = [8009C544];
    [A2 + V1 * 84 + 38] = b(V0);

    V0 = bu[800722C4];
    V0 = bu[8007EB98 + V0];
    V1 = [8009C544];
    [V1 + V0 * 84 + 3B] = b(00);

    V0 = bu[800722C4];
    V0 = bu[8007EB98 + V0];
    V1 = [8009C544];
    [V1 + V0 * 84 + 3A] = b(00);

    V0 = 1;
}
else
{
    V0 = 0;
}

// move pointer by 3
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 3;
[800831FC + V1 * 2] = h(V0);

return V0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB4 TURNGEN
field_file_offset    = w[8009C6DC];
current_entity       = bu[800722C4];
model_id             = bu[8007EB98 + current_entity];
offset_to_model_data = w[8009C544];
model_data           = offset_to_model_data + model_id * 84;
script_pointer       = hu[800831FC + current_entity * 2]

V1 = bu[8007EB98 + current_entity];
if (V1 != FF)
{
    A2 = bu[model_data + 3B];
    if (A2 == 3)
    {
        [model_data + 39] = b(0);
        [model_data + 3A] = b(0);
        [model_data + 3B] = b(0);
    }
    else
    {
        if (bu[model_data + 39] != bu[script_pointer + 4] ||
            bu[model_data + 3A] == 0 ||
            bu[model_data + 3B] != bu[script_pointer + 5])
        {
            V1 = bu[model_data + 38]
            [model_data + 3C] = h(V1);

            V1 = bu[script_pointer + 5];
            [model_data + 3B] = b(V1);

            V1 = bu[script_pointer + 4];
            [model_data + 39] = b(V1);

            A0 = 2;
            A1 = 2;
            read_memory_block_one_byte;
            [model_data + 3E] = h(V0);

            // rotate clockwise/anti-clockwise/closest
            V1 = bu[script_pointer + 3];

            if (V1 == 1)
            {
                if (h[model_data + 3E] >= bu[model_data + 38])
                {
                    V0 = h[model_data + 3E] - 100;
                    [model_data + 3E] = h(V0);
                }
            }
            else if (V1 == 2)
            {
                A1 = h[model_data + 3E];
                A3 = h[model_data + 3C];
                V0 = A1 - A3;

                if (V0 < 0)
                {
                    V0 = 0 NOR V1;
                    A0 = V0 + 1;
                }
                else
                {
                    A0 = V1;
                }

                if (A0 >= 81)
                {
                    if (A3 < A1)
                    {
                        V0 = A1 - 100;
                        [model_data + 3E] = h(V0);
                    }
                    else
                    {
                        V0 = A1 + 100;
                        [model_data + 3E] = h(V0);
                    }
                }
            }
            else if (V1 == 0)
            {
                if (h[model_data + 3E] >= bu[model_data + 38])
                {
                    V0 = h[model_data + 3E] + 100;
                    [model_data + 3E] = h(V0);
                }
            }
        }

        return 1;
    }
}

script_pointer = script_pointer + 6;
[800831FC + current_entity * 2] = hu(script_pointer);
return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB5 TURN
field_file_offset    = w[8009C6DC];
current_entity       = bu[800722C4];
model_id             = bu[8007EB98 + current_entity];
offset_to_model_data = w[8009C544];
model_data           = offset_to_model_data + model_id * 84;
script_pointer       = hu[800831FC + current_entity * 2]

if (model_id != FF)
{
    V1 = bu[model_data + 3B];

    if (V1 == 3)
    {
        [model_data + 39] = b(0);
        [model_data + 3A] = b(0);
        [model_data + 3B] = b(0);
    }
    else
    {
        A0 = 2;
        A1 = 2;
        read_memory_block_two_bytes;
        A2 = V0;

        if (bu[model_data + 3A] == 0 ||
            A2 != h[model_data + 3E] ||
            bu[model_data + 3B] != bu[field_file_offset + script_pointer + 5] ||
            bu[model_data + 39] != bu[field_file_offset + script_pointer + 4])
        {
            V1 = bu[model_data + 38];
            [model_data + 3C] = h[V1];

            V1 = bu[field_file_offset + script_pointer + 5];
            [model_data + 3B] = b(V1);

            V1 = bu[field_file_offset + script_pointer + 4];
            [model_data + 39] = b(V1);

            [model_data + 3E] = h(A2);
        }

        return 1;
    }
}

// move pointer by 6
script_pointer = script_pointer + 6;
[800831FC + current_entity * 2] = h(script_pointer);
return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB6 DIRA
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A0 = bu[V0 + V1 + 1]; // entity id

set_direction_to_current_entity_by_entity_id

return V0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB7 GETDIR
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
S0 = bu[V0 + V1 + 2]; // entity id

V1 = bu[8007EB98 + S0];

if (V1 != FF)
{
    V0 = w[8009C544];
    A2 = bu[V0 + V1 * 84 + 38];

    A0 = 2;
    A1 = 3;
    store_memory_block_one_byte;
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB8 GETAXY
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
S0 = bu[V0 + V1 + 2]; // entity id

V1 = bu[8007EB98 + S0];

if (V1 != FF)
{
    V0 = V1 * 84;
    V1 = w[8009C544];
    V0 = V0 + V1;
    A2 = w[V0 + 0C];

    A0 = 1;
    A1 = 3;
    A2 = A2 << 4;
    A2 = A2 >> 10;
    store_memory_block_two_bytes;

    A0 = 2;
    A1 = 4;
    A2 = w[V0 + 10];
    A2 = A2 << 4;
    A2 = A2 >> 10;
    store_memory_block_two_bytes;
}

// move pointer by 5
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 5;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xB9 GETAI
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
S0 = bu[V0 + V1 + 2]; // entity id

V1 = bu[8007EB98 + S0];

if (V1 != FF)
{
    V0 = V1 * 84;
    V1 = w[8009C544];
    V0 = V0 + V1;
    A2 = h[V0 + 72];

    A0 = 2;
    A1 = 3;
    store_memory_block_two_bytes;
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xBF CC
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
A0 = bu[V0 + V1 + 1]; // entity id

V1 = bu[8007EB98 + A0];

if (V1 != FF)
{
    V1 = w[8009C6E0];
    V0 = bu[8007EB98 + A0];
    [V1 + 2A] = V0;
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xC0 JUMP
A0 = current_entity    = bu[800722C4];
V1 = model_id          = bu[8007EB98 + current_entity];
model_data_offset = w[8009C544] + model_id * 84;

if (model_id == FF)
{
    // move pointer by B
    V0 = hu[800831FC + current_entity * 2];
    V0 = V0 + F;
    [800831FC + V1 * 2] = h(V0);
    return 0;
}

V1 = bu[model_data_offset + 5D];

if (V1 == 3)
{
    V1 = h[model_data_offset + 6A];
    if (V1 == 1)
    {
        return 1;
    }

    if (V1 == 2)
    {
        [model_data_offset + 5D] = b(0);
        [model_data_offset + 6A] = h(0);

        // move pointer by B
        V0 = hu[800831FC + current_entity * 2];
        V0 = V0 + F;
        [800831FC + V1 * 2] = h(V0);
        return 0;
    }
}

[model_data_offset + 5D] = b(3);
[model_data_offset + 6A] = h(0);

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 78] = w(V0);

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 7С] = w(V0);

A0 = 3;
A1 = 7;
read_memory_block_two_bytes;
[model_data_offset + 74] = h(V0);

A0 = 4
A1 = 9;
read_memory_block_two_bytes;
[model_data_offset + 30] = h(V0);

return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xC2 LADER
current_entity    = bu[800722C4];
model_id          = bu[8007EB98 + current_entity];
model_data_offset = w[8009C544] + model_id * 84;

if (model_id == FF)
{
    // move pointer by 15
    V0 = hu[800831FC + current_entity * 2];
    V0 = V0 + F;
    [800831FC + V1 * 2] = h(V0);
    return 0;
}

V1 = bu[model_data_offset + 5D];

if (V1 == 4 || V1 == 5)
{
    V1 = h[model_data_offset + 6A];
    if (V1 == 1)
    {
        return 1;
    }
    else if (V1 == 2)
    {
        [model_data_offset + 5D] = b(0);
        [model_data_offset + 6A] = h(0);

        // move pointer by 15
        V0 = hu[800831FC + current_entity * 2];
        V0 = V0 + F;
        [800831FC + current_entity * 2] = h(V0);
        return 0;
    }
}



// init
V1 = hu[800831FC + current_entity * 2];
V0 = w[8009C6DC];
V0 = V0 + V1;
V1 = bu[V0 + B];

if (V1 == 0 || V1 == 1)
{
    [model_data_offset + 5D] = bu(4);
}
else if (V1 == 2 || V1 == 3)
{
    [model_data_offset + 5D] = bu(5);
}

if (V1 == 0 || V1 == 2)
{
    [model_data_offset + 68] = h(0);
}
else if (V1 == 1 || V1 == 3)
{
    [model_data_offset + 68] = h(1);
}

[model_data_offset + 6A] = h(0);

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 78] = w(V0);

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 7C] = w(V0);

A0 = 3;
A1 = 7;
read_memory_block_two_bytes;
V0 = V0 << C;
[model_data_offset + 80] = w(V0);

A0 = 4;
A1 = 9;
read_memory_block_two_bytes;
[model_data_offset + 74] = h(V0);



// animation id
V1 = hu[800831FC + current_entity * 2];
V0 = w[8009C6DC];
V1 = bu[V0 + V1 + c];
[model_data_offset + 5E] = b(V1);



// speed of movement
A1 = hu[800831FC + current_entity * 2];
V0 = w[8009C6DC];
V1 = h[8009d828 + model_id * 2] / bu[V0 + A1 + e];
[model_data_offset + 60] = h(V1);



[model_data_offset + 62] = h(0);



// animation related
V1 = w[8008357C];
V1 = bu[V1 + model_id * 8 + 4];
animation_id = bu[80074EA4 + model_id * 84 + 5E];
A0 = w[8004A62C];
V0 = w[A0 + 4];
A1 = w[V0 + V1 * 24 + 1C];
A0 = hu[V0 + V1 * 24 + 1A];
V0 = hu[A1 + A0 + animation_id * 10];
V0 = V0 - 1;
[model_data_offset + 64] = h(V0);



// animation state array
[800756E8 + model_id] = b(0);



// set direction for model
A1 = hu[800831FC + current_entity * 2];
A0 = w[8009C6DC];
A0 = bu[A0 + A1 + D];
// set direction
[model_data_offset + 38] = b(A0);
return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xC3 OFST
entity_id = bu[800722c4];
model_id = bu[8007eb98 + entity_id];
if (model_id != ff)
{
    model_data = w[8009c544];

    [model_data + model_id * 84 + 54] = h(0);

    A0 = 4;
    A1 = a;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 52] = h(V0);

    A0 = 1;
    A1 = 4;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 44] = h(V0);

    A0 = 2;
    A1 = 6;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 4a] = h(V0);

    A0 = 3;
    A1 = 8;
    read_memory_block_two_bytes;
    [model_data + model_id * 84 + 50] = h(V0);

    A1 = entity_id * 2;
    A0 = hu[800831fc + entity_id * 2];
    V0 = w[8009c6dc];
    V1 = bu[V0 + A0 + 3]; // read type
    [model_data + model_id * 84 + 56] = b(V1);

    if (V1 != 0)
    {
        [model_data + model_id * 84 + 42] = h[hu[model_data + model_id * 84 + 40]];
        [model_data + model_id * 84 + 48] = h[hu[model_data + model_id * 84 + 46]];
        [model_data + model_id * 84 + 4e] = h[hu[model_data + model_id * 84 + 4c]];
    }
    else
    {
        [model_data + model_id * 84 + 40] = h[hu[model_data + model_id * 84 + 44]];
        [model_data + model_id * 84 + 46] = h[hu[model_data + model_id * 84 + 4a]];
        [model_data + model_id * 84 + 4c] = h[hu[model_data + model_id * 84 + 50]];
    }
}

V0 = hu[800831FC + entity_id * 2];
V0 = V0 + c;
[800831FC + entity_id * 2] = h(V0);
return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xC4 OFSTW
entity_id = bu[800722c4];
model_id = bu[8007eb98 + entity_id];
model_data = w[8009c544];

if (model_id != ff)
{
    V1 = bu[model_data + model_id * 84 + 56];

    if (V1 != 3)
    {
        return 1;
    }

    [model_data + model_id * 84 + 52] = h(0);
    [model_data + model_id * 84 + 54] = h(0);
    [model_data + model_id * 84 + 56] = b(0);
}

V0 = hu[800831FC + entity_id * 2];
V0 = V0 + 1;
[800831FC + entity_id * 2] = h(V0);
return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xC5 TALKR
V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_one_byte;

    V1 = w[8009C6E0];
    V1 = h[V1 + 10];
    V0 = V0 & FF;
    HI/LO = V0 * V1;
    A0 = LO;

    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = V1 * 84;
    V1 = w[8009C544];
    V1 = V0 + V1;

    if (A0 < 0)
    {
        A0 = A0 + 01FF;
    }

    V0 = A0 >> 09;
    [V1 + 6E] = h(V0);
}

// move pointer by 3
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 3;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xC6 SLIDR
V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_one_byte;

    V1 = w[8009C6E0];
    V1 = h[V1 + 10];
    V0 = V0 & FF;
    HI/LO = V0 * V1;
    A0 = LO;

    V0 = bu[800722C4];
    V0 = bu[8007EB98 + V0];
    V1 = w[8009C544];
    V1 = V1 + V0 * 84;

    if (A0 < 0)
    {
        A0 = A0 + 01FF;
    }

    V0 = A0 >> 09;
    [V1 + 6C] = h(V0);
}

// move pointer by 3
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 3;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xC7 SOLID
V1 = bu[800722C4];
model_id = bu[8007EB98 + V1];

if (A0 != FF)
{
    A0 = hu[800831FC + V1 * 2];
    V1 = w[8009C6DC];
    V1 = bu[V1 + A0 + 1];
    A0 = w[8009C544];
    [A0 + model_id * 84 + 59] = b(V1);
}

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xD6 TLKR2
V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;

    V1 = w[8009C6E0];
    V1 = h[V1 + 10];
    HI/LO = V0 * V1;
    A0 = LO;

    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = V1 * 84;
    V1 = w[8009C544];
    V1 = V0 + V1;
    V0 = A0 >> 09;
    [V1 + 6E] = h(V0);
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xD7 SLDR2
V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];

if (V1 != FF)
{
    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;

    V1 = w[8009C6E0];
    V1 = h[V1 + 10];
    HI/LO = V0 * V1;
    A0 = LO;

    V0 = bu[800722C4];
    V1 = bu[8007EB98 + V0];
    V0 = V1 * 84;
    V1 = w[8009C544];
    V1 = V0 + V1;

    V0 = A0 >> 09;
    [V1 + 6C] = h(V0);
}

// move pointer by 4
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 4;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xDB FCFIX
V1 = entity_id = bu[800722C4];
A0 = bu[8007EB98 + entity_id];
if (A0 != FF)
{
    V0 = A0 * 84;
    A0 = hu[800831FC + entity_id * 2];

    V1 = V1 + A0;
    V1 = bu[V1 + 1];

    A0 = w[8009C544];
    V0 = V0 + A0;
    [V0 + 37] = b(V1);
}

V1 = hu[800831FC + entity_id * 2];
V1 = V1 + 2;
[800831FC + A0 * 2] = hu[V1];

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xDE TURNW
entity_id = bu[800722C4];
model_id = bu[8007EB98 + entity_id];
if (model_id != FF)
{
    V0 = w[8009C544];
    V1 = V0 + model_id * 84;
    A1 = bu[V1 + 3B];
    if (A1 != 0)
    {
        if (A1 != 3)
        {
            return 1;
        }

        [V1 + 3B] = b(0);
        [V1 + 3A] = b(0)
        [V1 + 39] = b(0)
    }
}

V1 = hu[800831FC + entity_id * 2];
V1 = V1 + 1;
[800831FC + A0 * 2] = hu[V1]
return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// funcc8634
rotate_entity = A0;
current_entity         = bu[800722C4];
current_model          = bu[8007EB98 + current_entity];
rotate_model          = bu[8007EB98 + rotate_entity];
current_script_pointer = hu[800831FC + current_entity * 2];
field_file_offset      = w[8009C6DC];
models_offset          = w[8009C544];

//[models_offset + current_model * 84 + 60] = h(V1);

if (current_model == FF || rotate_entity == FF)
{
    // move pointer by 4
    current_script_pointer = current_script_pointer + 4;
    [800831FC + current_entity * 2] = h(current_script_pointer);
    return 0;
}

V1 = bu[models_offset + current_model * 84 + 3B];
if (V1 == 3)
{
    [models_offset + current_model * 84 + 3B] = b(0)
    [models_offset + current_model * 84 + 3A] = b(0)
    [models_offset + current_model * 84 + 39] = b(0)
    // move pointer by 4
    current_script_pointer = current_script_pointer + 4;
    [800831FC + current_entity * 2] = h(current_script_pointer);
    return 0;
}

if (bu[models_offset + current_model * 84 + 3A] != 0 &&
    bu[models_offset + current_model * 84 + 3B] == 2 &&
    bu[models_offset + current_model * 84 + 39] == bu[field_file_offset + current_script_pointer + 2])
{
    V1 = bu[models_offset + current_model * 84 + 38];
    [models_offset + current_model * 84 + 3C] = h(V1);
    [models_offset + current_model * 84 + 3B] = h(2);

    V1 = bu[field_file_offset + current_script_pointer + 2]
    [models_offset + current_model * 84 + 39] = b(V1);

    V0 = w[models_offset + current_model * 84 + C];
    T0 = V0 >> C;
    [SP + 10] = w(T0);
    V0 = w[models_offset + current_model * 84 + 10];
    T1 = V0 >> C;
    [SP + 14] = w(T1);
    V0 = w[models_offset + current_model * 84 + 14];
    V0 = V0 >> C;
    [SP + 18] = w(V0);

    V0 = w[models_offset + rotate_model * 84 + C];
    A1 = V0 >> C;
    [SP + 20] = w(A1);
    V0 = w[models_offset + rotate_model * 84 + 10];
    A3 = V0 >> C;
    [SP + 24] = w(A3);
    V0 = w[models_offset + rotate_model * 84 + 14];
    V0 = V0 >> C;
    [SP + 28] = w(V0);

    if (T0 == A1 && T1 == A3)
    {
        V0 = T0 + 1;
        [SP + 10] = w(V0);
    }

    A0 = SP + 10;
    A1 = SP + 20;
    A2 = SP + 30;
    calculate_direction_by_vectors;

    [models_offset + current_model * 84 + 3E] = h(V0);

    V1 = bu[field_file_offset + current_script_pointer + 3]

    if (V1 == 0)
    {
        V0 = h[models_offset + current_model * 84 + 3E];
        V1 = bu[models_offset + current_model * 84 + 38];
        if (V0 < V1)
        {
            V0 = V0 + 100;
            [models_offset + current_model * 84 + 3E] = h(V0);
        }
    }
    else if (V1 == 1)
    {
        V1 = h[models_offset + current_model * 84 + 3E];
        V0 = bu[models_offset + current_model * 84 + 38];
        if (V0 < V1)
        {
            V0 = V1 - 100;
            [models_offset + current_model * 84 + 3E] = h(V0);
        }
    }
    if (V1 == 2)
    {
        A1 = hu[models_offset + current_model * 84 + 3E];
        A3 = hu[models_offset + current_model * 84 + 3C];
        V0 = A1 - A3;

        if (V0 < 0)
        {
            V0 = 0 NOR V1;
            A0 = V0 + 1;
        }
        else
        {
            A0 = V1;
        }

        if (A0 >= 81)
        {
            V1 = A1;
            V0 = A3;
            if (V0 < V1)
            {
                V0 = A1 - 100;
                [models_offset + current_model * 84 + 3E] = h(V0);
            }
            else
            {
                V0 = A1 + 100;
                [models_offset + current_model * 84 + 3E] = h(V0);
            }
        }
    }
}

return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// set_direction_to_current_entity_by_entity_id
A0 - entity to get

// if current entity not visible entity
A2 = bu[800722C4];
V1 = bu[8007EB98 + A2];
if (V1 == FF)
{
    V1 = hu[800831FC + A2 * 2];
    V1 = V1 + 2;
    [800831FC + A2 * 2] = h(V1);

    return 0;
}

// if entity to which we want set direction not visible entity
A3 = A0;
V0 = bu[8007EB98 + A3];
if (V0 == FF)
{
    V1 = hu[800831FC + A2 * 2];
    V1 = V1 + 2;
    [800831FC + A2 * 2] = h(V1);

    return 0;
}

A1 = w[8009C544];

V1 = bu[8007EB98 + A2];
V0 = w[A1 + V1 * 84 + 0C];
T0 = V0 >> 0C;
[SP + 10] = w(T0);

V1 = bu[8007EB98 + A2];
V0 = w[A1 + V1 * 84 + 10];
T1 = V0 >> 0C;
[SP + 14] = w(T1);

V1 = bu[8007EB98 + A2];
V0 = w[A1 + V1 * 84 + 14];
V0 = V0 >> 0C;
[SP + 18] = w(V0);



V1 = bu[8007EB98 + A3];
V0 = V1 * 84;
A0 = w[A1 + V0 + 0C];
A0 = A0 >> 0C;
[SP + 20] = w(A0);

V1 = bu[8007EB98 + A3];
V0 = V1 * 84;
V0 = w[A1 + V0 + 10];
A2 = V0 >> 0C;
[SP + 24] = w(A2);

V1 = bu[8007EB98 + A3];
V0 = V1 * 84;
V0 = w[A1 + V0 + 14];
V0 = V0 >> 0C;
[SP + 28] = w(V0);

if (T0 == A0 && T1 == A2) // if X1 == X2 && Y1 = Y2
{
    V0 = T0 + 1;
    [SP + 10] = V0;
}

A0 = SP + 10;
A1 = SP + 20;
A2 = SP + 30;

calculate_direction_by_vectors;

V1 = bu[800722C4];
A0 = bu[8007EB98 + V1];
V1 = A0 * 84;
A0 = w[8009C544];
[V1 + A0 + 38] = b(V0);

V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];
V0 = V1 * 84;
V1 = w[8009C544];
[V1 + A0 + 3B] = b(0);

V0 = bu[800722C4];
V1 = bu[8007EB98 + V0];
V0 = V1 * 84;
V1 = w[8009C544];
[V1 + A0 + 3A] = b(0);

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
calculate_direction_by_vectors
A0 - address of rotated entity pos
A1 - address of entity pos to which we want rotate to
A2 - output address

V1 = w[A1 + 00];
V0 = w[A0 + 00];
S2 = V1 - V0;
HI/LO = S2 * S2;
A0 = LO;

V1 = w[A1 + 04];
V0 = w[A0 + 04];
S1 = V1 - V0;
HI/LO = S1 * S1;
V0 = LO;

S0 = A2;
A0 = A0 + V0;
[S0 + 00] = w(A0);

system_square_root;

A0 = V0;
V0 = S2 << 0C;
HI/LO = V0 / A0;
V1 = LO;
[S0 + 00] = w(A0);

if (V1 < 0)
{
    V1 = V1 + 1F;
}

V0 = S1 << 0C;
HI/LO = V0 / A0;
A0 = LO;

if (A0 < 0)
{
    A0 = A0 + 1F;
}

S2 = V1 >> 5;
HI/LO = S2 * S2;
V1 = LO;

S1 = A0 >> 5;
HI/LO = S1 * S1;
V0 = LO;

if (V0 < V1)
{
    if (S2 > 0)
    {
        if (S1 > 0)
        {
            V0 = bu[800DEF88 + S1 * 2];
            V0 = V0 + 40;
        }
        else
        {
            V0 = bu[800DEF88 - S1 * 2];
            V0 = 40 - V0;
        }
    }
    else
    {
        if (S1 > 0)
        {
            V1 = bu[800DEF88 + S1 * 2];
            V0 = - 40 - V1;
        }
        else
        {
            V0 = bu[800DEF88 - S1 * 2];
            V0 = V0 - 40;
        }
    }
}
else
{
    if (S1 > 0)
    {
        if (S2 > 0)
        {
            V1 = bu[800DEF88 + S1 * 2];
            V0 = 80 - V1;
        }
        else
        {
            V0 = bu[800DEF88 - S1 * 2];
            V0 = V0 + 80;
        }
    }
    else
    {
        if (S2 > 0)
        {
            V0 = bu[800DEF88 + S1 * 2];
        }
        else
        {
            V1 = bu[800DEF88 - S1 * 2];
            V0 = - V1;
        }
    }
}

return V0;
////////////////////////////////////////////////////////




////////////////////////////////////////////////////////
// funcd0938
speed = [SP + 40];
entity_id = A0;
end_x = A1;
end_y = A2;
direction = A3;
if (entity_id == FF)
{
    return 1;
}

V1 = bu[80081D90 + entity_id];
if (V1 == 0)
{
    A0 = entity_id;
    A1 = end_x;
    A2 = end_y;
    [SP + 10] = w(1);
    A3 = speed;
    funcd0b4c;

    [80081D90 + entity_id] = b(1);
    return 0;
}
else if (V1 == 1)
{
    A0 = entity_id;
    funcd1200;

    if (V0 == 0)
    {
        return 0;
    }

    model_id = bu[8007EB98 + entity_id];
    V0 = w[8009C544];
    [V0 + model_id * 84 + 59] = b(0);
    [V0 + model_id * 84 + 5B] = b(0);

    A0 = entity_id;
    A1 = bu[V0 + model_id * 84 + 38]; // direction
    A2 = direction;
    funcd1350;

    [80081D90 + entity_id] = b(2);
    return 0;
}
else if (V1 == 2)
{
    A0 = entity_id;
    funcd152c;

    if (V0 != 0)
    {
        [80081D90 + entity_id] = b(3);
        return 1;
    }

    return 0;
}
else if (V1 == 3)
{
    return 1;
}
else
{
    return 0;
}
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// funcc7d5c
A1 = bu[800722C4];
V0 = bu[8007EB98 + A1];
A3 = A0;
A0 = bu[8007EB98 + A3];

if (V0 == FF || A0 == FF)
{
    V1 = hu[800831FC + A1 * 2];
    V1 = V1 + 2;
    [800831FC + A1 * 2] = h(V1);
    return 0;
}

V1 = V0 * 84;
V0 = A0 * 84;
A0 = w[8009C544];
V0 = V0 + A0;
V0 = hu[V0 + 6C]; // solid
[V1 + 68] = h(V0);
V1 = V1 + A0;
V1 = bu[8007EB98 + A1];
V0 = V1 * 84;
V0 = V0 + A0;
[V0 + 37] = b(0);

A2 = bu[800722c4];
A1 = w[8009c544];

A0 = bu[8007eb98 + A3];
V0 = bu[8007eb98 + A2];
[A1 + V0 * 84 + 78] = w(w[A1 + A0 * 84 + c]);
[A1 + V0 * 84 + 7c] = w(w[A1 + A0 * 84 + 10]);

V1 = bu[A1 + V0 * 84 + 5d];
if (V1 == 1)
{
    A2 = [A1 + V0 * 84 + 6a];
    if (A2 == 1)
    {
        V0 = w[8009c6e0];
        V1 = h[V0 + 10];
        A0 = hu[A1 + 70];
        V0 = V1 * 3;
        V0 = V0 < A0;

        800C7F18	beq    v0, zero, Lc7f38 [$800c7f38]
        800C7F1C	ori    v0, zero, $0002
        800C7F20	lbu    v1, $005e(a1)
        800C7F24	nop
        800C7F28	beq    v1, v0, Lc8030 [$800c8030]
        800C7F2C	ori    v0, zero, $0002
        800C7F30	j      Lc7f4c [$800c7f4c]
        800C7F34	sb     v0, $005e(a1)
    }
    else if (A2 == 2)
    {
        [A1 + V0 * 84 + 5d] = b(0);
        V0 = bu[800722c4];
        V0 = bu[8007eb98 + V0];
        [800756e8 + V0] = b(0);

        A0 = bu[800722c4];
        [800831fc + A0 * 2] = h(hu[800831fc + A0 * 2] + 2);
        return 0;
    }

    800C7EF0	j      Lc80c8 [$800c80c8]

    Lc7f38:	; 800C7F38
    800C7F38	lbu    v0, $005e(a1)
    800C7F3C	nop
    if (V0 != A2)
    {
        800C7F40	beq    v0, a2, Lc8030 [$800c8030]
        800C7F44	ori    v0, zero, $0001
        800C7F48	sb     v0, $005e(a1)

        Lc7f4c:	; 800C7F4C
        A0 = bu[800722c4];
        V1 = bu[8007eb98 + A0];
        A2 = w[8009c544];
        V0 = A2 + V1 * 84;
        [V0 + 60] = h(10);
        [V0 + 62] = h(0);

        A0 = V1;

        V1 = w[8008357c];
        V0 = V1 + A0 * 8;
        A1 = bu[V0 + 4];


        800C7FD4	lui    v1, $8005
        800C7FD8	lw     v1, $a62c(v1)
        800C7FDC	sll    v0, a1, $03
        800C7FE0	addu   v0, v0, a1
        800C7FE4	lw     v1, $0004(v1)
        800C7FE8	sll    v0, v0, $02
        800C7FEC	addu   v0, v0, v1
        800C7FF0	sll    v1, a0, $05
        800C7FF4	addu   v1, v1, a0
        800C7FF8	sll    v1, v1, $02
        800C7FFC	lhu    a1, $001a(v0)
        800C8000	lw     a0, $001c(v0)
        800C8004	lui    at, $8007
        800C8008	addiu  at, at, $4f02
        800C800C	addu   at, at, v1
        800C8010	lbu    v0, $0000(at)
        800C8014	addu   a1, a1, a0
        800C8018	sll    v0, v0, $04
        800C801C	addu   v0, v0, a1
        800C8020	lhu    v0, $0000(v0)
        800C8024	addu   v1, v1, a2
        800C8028	addiu  v0, v0, $ffff (=-$1)
        800C802C	sh     v0, $0064(v1)
    }

    Lc8030:	; 800C8030
    V1 = bu[800722c4];
    A0 = bu[8007eb98 + V1];
    [800756e8 + A0] = b(1);
    return 1;
}

Lc80c8:	; 800C80C8
V0 = bu[800722c4];
V1 = bu[8007eb98 + V0];
V0 = w[8009c544];
V0 = V0 + V1 * 84;
[V0 + 5d] = b(1);
[V0 + 6a] = b(0);
return 1;
////////////////////////////////////////////////////////