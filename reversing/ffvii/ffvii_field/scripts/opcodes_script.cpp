////////////////////////////////
// 0x00 RET
current_entity = bu[800722C4];
current_priority = bu[8009A1C4 + current_entity];

if (current_priority >= 7)
{
    return 1;
}

// if script set to REQEW then te this script as finished
V1 = bu[800833F8 + current_entity * 8 + current_priority];
if (V1 == 1)
{
    [800833F8 + current_entity * 8 + current_priority] = b(02);
}

current_priority = current_priority + 1;
[8009A1C4 + current_entity] = b(current_priority);

V1 = hu[80071748 + current_entity * 10 + current_priority * 2]; // get current script pointer for next script
[800831FC + current_entity * 2] = h(V1);                      // set new script pointer

if (V1 == 0)
{
    for (;;)
    {
        loopc3b28:	; 800C3B28
        if (current_priority >= 7)
        {
            break;
        }

        // go to next script
        current_priority = current_priority + 1;
        [8009A1C4 + current_entity] = b(current_priority);

        V0 = hu[80071748 + current_entity * 10 + current_priority * 2]; // get new script pointer for next script
        [800831FC + current_entity * 2] = h(V0);                      // set new script pointer

        800C3BB4	beq    v0, zero, loopc3b28 [$800c3b28]
    }
}

[80071748 + current_entity * 10 + current_priority * 2] = h(00); // set current script pointer for this script to 0
return 0;
////////////////////////////////



////////////////////////////////
// 0x01 REQ
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 1;
A1 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;
funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x02 REQSW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 2;
A1 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;
funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x03 REQEW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 3;
A1 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;
funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x04 PREQ
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 1;
V0 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;

A1 = bu[8009D391 + V0];

if (A1 != FF)
{
    A1 = bu[8009AD30 + A1];
}
else
{
    A1 = FF;
}

funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x05 PRQSW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 2;
V0 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;

A1 = bu[8009D391 + V0];

if (A1 != FF)
{
    A1 = bu[8009AD30 + A1];
}
else
{
    A1 = FF;
}

funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x06 PRQEW
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];

A0 = 3;
V0 = bu[V0 + V1 + 1];
A2 = bu[V0 + V1 + 2];
A3 = bu[V0 + V1 + 2];
A2 = A2 >> 5;
A3 = A3 & 1F;

A1 = bu[8009D391 + V0];

if (A1 != FF)
{
    A1 = bu[8009AD30 + A1];
}
else
{
    A1 = FF;
}

funcc33b4;
////////////////////////////////



////////////////////////////////
// 0x07 RETTO
current_entity            = bu[800722C4];
current_script_pointer    = 800831FC + current_entity * 2;
field_file_offset         = w[8009C6DC];
entity_current_slot       = 8009A1C4 + current_entity;

V1 = hu[current_script_pointer];
V1 = bu[field_file_offset + V1 + 1];
V0 = bu[field_file_offset + V1 + 1];
priority_id               = V1 >> 5;
script_id                 = V0 & 1F;
V0 = bu[entity_current_slot];
priority_id = priority_id - 1;

if (V0 < priority_id)
{
    loopc3cd8:	; 800C3CD8
        V1 = [entity_current_slot];

        if (V1 < 7)
        {
            break;
        }

        V0 = bu[800833F8 + current_entity * 8 + V1];
        if (V0 == 1)
        {
            [800833F8 + current_entity * 8 + V1] = b(2);
        }

        V0 = bu[entity_current_slot];
        V0 = V0 + 1;
        [entity_current_slot] = b(V0);

        V0 = bu[entity_current_slot];
        [80071748 + current_entity * 10 + V0 * 2] = h(0);
        V0 = bu[entity_current_slot];
        V0 = V0 < priority_id;

    800C3D90	bne    v0, zero, loopc3cd8 [$800c3cd8]
}

[801142D4 + current_entity * 8 + priority_id] = b(script_id);
A2 = hu[field_file_offset + 6];
V0 = bu[field_file_offset + 2];
A0 = hu[field_file_offset + current_entity * 40 + V0 * 8 + A2 * 4 + script_id * 2 + 20];
[current_script_pointer] = h(A0);
[entity_current_slot] = b(priority_id);

return 0;
////////////////////////////////



////////////////////////////////
// 0x12 JMPB
current_entity            = bu[800722c4];
current_script_pointer    = 800831fc + current_entity * 2;
field_file_offset         = w[8009c6dc];
A0 = hu[current_script_pointer + 0];

[current_script_pointer] = h(hu[current_script_pointer] - bu[field_file_offset + A0 + 1]);

return 1;
////////////////////////////////



////////////////////////////////
// funcc33b4
current_entity            = bu[800722c4];
current_script_pointer    = 800831fc + current_entity * 2;
target_script_pointer     = 800831fc + target_id * 2;
target_current_slot       = 8009a1c4 + target_id;
request_id                = A0; // 3 - reqEW
target_id                 = A1;
priority_id               = A2;
script_id                 = A3;
script_state              = 800833f8 + target_id * 8 + priority_id;
field_file_offset         = w[8009c6dc];
field_extra_offset_number = hu[field_file_offset + 6]
field_entity_number       = bu[field_file_offset + 2];

if (target_id == FF)
{
    A0 = hu[current_script_pointer];
    A0 = A0 + 3;
    [current_script_pointer] = h(A0);
    return 0;
}

if (request_id == 3)
{
    V1 = bu[80071A88 + target_id * 8 + priority_id];

    if (V1 == current_entity)
    {
        V1 = bu[script_state];

        if (V1 == 1)
        {
            return 1;
        }

        if (V1 == 2)
        {
            [script_state] = b(0);
            [80071A88 + target_id * 8 + priority_id] = b(FF);

            V1 = hu[current_script_pointer];
            V1 = V1 + 3;
            [current_script_pointer] = h(V1);
            return 0;
        }
    }
}

V0 = bu[target_current_slot];

if (V0 != priority_id)
{
    if (V0 > priority_id)
    {
        V0 = bu[script_state];

        if (V0 == 0)
        {
            return 1;
        }

        [801142D4 + target_id * 8 + priority_id] = b(script_id);

        // store script pointer
        V0 = bu[target_current_slot];
        A0 = hu[target_script_pointer];
        [80071748 + target_id * 10 + V0 * 2] = h(A0);

        // get requested script offset and store it to target entity script start point
        A1 = hu[field_file_offset + target_id * 40 + field_entity_number * 8 + field_extra_offset_number * 4 + script_id * 2 + 20];
        [target_script_pointer] = h(A1);

        [target_current_slot] = b(priority_id);

        V1 = bu[8007EB98 + target_id];
        if (V1 != FF)
        {
            V0 = w[8009C544];
            [V0 + V1 * 84 + 5D] = b(0);
        }

        [800716DC + target_id * 2] = h(0);

        if (request_id < 3)
        {
            V1 = hu[current_script_pointer];
            V1 = V1 + 3;
            [current_script_pointer] = h(V1);
            return 0;
        }

        if (request_id == 3)
        {
            [80071A88 + target_id * 8 + priority_id] = b(current_entity);
            [script_state] = b(1);
        }
        return 1;
    }
    else
    {
        V0 = hu[80071748 + target_id * 10 + priority_id * 2];

        if (V0 == 0)
        {
            // get requested script offset and store it to target entity script start point
            A1 = hu[field_file_offset + target_id * 40 + field_entity_number * 8 + field_extra_offset_number * 4 + script_id * 2 + 20];
            [80071748 + target_id * 10 + priority_id * 2] = h(A1);

            if (request_id < 3)
            {
                A0 = hu[current_script_pointer];
                A0 = A0 + 3;
                [current_script_pointer] = h(A0);
                return 0;
            }

            if (request_id == 3)
            {
                [80071A88 + target_id * 8 + priority_id] = b(current_entity);
                [script_state] = b(1);
            }

            return 1;
        }
    }
}

if (request_id == 1)
{
    [current_script_pointer] = h(hu[current_script_pointer] + 3);
    return 0;
}

return 1;
////////////////////////////////