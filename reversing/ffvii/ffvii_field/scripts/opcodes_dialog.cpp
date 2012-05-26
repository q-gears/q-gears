////////////////////////////////
// 0x2E WCLS
S0 = window_id;

if ([8008326C + S0] != FF)
{
    A0 = S0;

    set_state_to_close;

    A0 = S0;
    A1 = 0;

    manage_window_states;

    V0 = 1;
}
else
{
    V0 = 0;

    move script pointer by 2
}
////////////////////////////////



////////////////////////////////
// 0x2F WSIZE
A1 = bu[800722C4];
V1 = hu[800831FC + A1 * 2];
V0 = w[8009C6DC];
S0 = bu[V0 + V1 + 1];
V1 = bu[8008326C + S0]; // parent entity

if (V1 == FF) // if window not opened yet
{
    window;
    return V0;
}
else
{
    if (V1 == A1) // if parent entity and current entity are the same
    {
        set_state_to_close;

        A0 = S0;
        A1 = 0;
        manage_window_states;
    }
}
return 1;
////////////////////////////////



////////////////////////////////
// 0x36 WSPCL
writes data to window structure.

move script pointer by 5

return 0;
////////////////////////////////////////////////////////



////////////////////////////////
// 0x37 WNUMB
V0 = bu[800722C4];
V1 = hu[800832FC + V0 * 2];
V0 = w[8009C6DC];
S1 = bu[V0 + V1 + 2]; // window id

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
S0 = V0;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
S0 = S0 + V0 << 10;

V0 = bu[800722C4];
V1 = S1 * 30;
[80083294 + S1 * 30] = w(S0);
A0 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
V0 = [V0 + A0 + 7]; // number of digits
[80083291 + S1 * 30] = b(V0);

// move pointer by 8
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 8;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// 0x38 STTIM
A0 = 1;
A1 = 3;
read_memory_block_one_byte;
S0 = V0 * E10; // * 3600 (hours to seconds)

A0 = 2;
A1 = 4;
read_memory_block_one_byte;
V1 = V0 * 3C; // * 60 (minutes to seconds)
S0 = S0 + V1;

A0 = 4;
A1 = 5;
read_memory_block_one_byte;
S0 = S0 + V0;
[8009D268] = w(S0);


// move pointer by 8
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 6;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// 0x40 MESSAGE
V0 = bu[800722C4];          // current entity
V1 = hu[800831FC + V0 * 2]; // script pointer
V0 = w[8009c6dc];           // current field file offset.

A0 = [V0 + V1 + 1];         // window_id
A1 = [V0 + V1 + 2];         // dialog_id

manage_window_states

if (v == 0)
{
    v0 = 1;
}
else
{
    v0 = 0;
    move script pointer by 3
}
////////////////////////////////



////////////////////////////////
// 0x41 MPARA
V0 = bu[800722C4];          // current entity
V1 = hu[800831FC + V0 * 2]; // script pointer
V0 = w[8009C6DC];           // current field file offset.
S0 = [V0 + V1 + 2];         // window_id

A0 = 1;
A1 = 3;
read_memory_block_one_byte;

V1 = bu[800722C4];
A1 = hu[800831FC + V1 * 2];
V1 = w[8009C6DC];
V1 = bu[V1 + A1 + 1];

V1 = V1 & 0F;
[800E4214 + S0 * 8 + V0] = b(V1);

A0 = bu[800722C4];
A1 = hu[800831FC + A0 * 2];
V1 = w[8009C6DC];
V1 = bu[V1 + A1 + 4];

[800E4D48 + S0 * 10 + V0 * 2] = h(V1);

// move pointer to 5
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 5;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// 0x42 MPRA2
V0 = bu[800722C4];          // current entity
V1 = hu[800831FC + V0 * 2]; // script pointer
V0 = w[8009C6DC];           // current field file offset.
S0 = [V0 + V1 + 2];         // window_id

A0 = 1;
A1 = 3;
read_memory_block_one_byte;

V1 = bu[800722C4];
A1 = hu[800831FC + V1 * 2];
V1 = w[8009C6DC];
V1 = bu[V1 + A1 + 1];

V1 = V1 & 0F;
[800E4214 + S0 * 8 + V0] = b(V1);

A0 = bu[800722C4];
A1 = hu[800831FC + A0 * 2];
V1 = w[8009C6DC];
V1 = bu[V1 + A1 + 4];
S1 = bu[V1 + A1 + 5];

S1 = S1 << 8;
V1 = V1 | S1;
[800E4D48 + S0 * 10 + V0 * 2] = h(V1);

// move pointer to 6
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 6;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////


////////////////////////////////
// 0x48 ASK
A0 = 2;
A1 = 6;
read_memory_block_one_byte

[SP + 18] = b(V0);

get curent script offset and store result in v1;

a0 = [v1 + 02]; // window_id
a1 = [v1 + 03]; // dialog_id
a2 = [v1 + 04]; // first
a3 = [v1 + 05]; // last
v0 = SP + 18;
[SP + 10] = V0;

manage_ask_window_states

A0 = 2;
A1 = 6;
A2 = bu[SP + 18];
store_memory_block_one_byte;

if (v0 == 0)
{
    V1 = w[8009C6E0];
    [V1 + 32] = b(1);
    return 1;
}
else
{
    V1 = w[8009C6E0];
    V0 = bu[80081DC4];
    [V1 + 32] = b(V0);

    // move pointer by 7
    V1 = bu[800722C4];
    V0 = hu[800831FC + V1 * 2];
    V0 = V0 + 7;
    [800831FC + V1 * 2] = h(V0);

    return 0;
}
////////////////////////////////



////////////////////////////////
// 0x50 WINDOW
window

get curent script offset and store result in t0;

a0 = [t0 + 1] = 3;    // window id
a1 = [t0 + 2] = 0028; // x
a2 = [t0 + 4] = 0014; // y
a3 = [t0 + 6] = 0085; // w
v1 = [t0 + 8] = 0029; // h
[sp + 10] = v1;

set_window_x_y_width_height

move script pointer by 0xA

return 0;
////////////////////////////////



////////////////////////////////
// 0x51 WMOVE
V0 = bu[800722C4];          // current entity
V1 = w[8009C6DC];           // current field file offset.
V0 = hu[800831FC + V0 * 2]; // script pointer
V1 = V1 + V0;
A0 = bu[V1 + 1];
V0 = bu[V1 + 2];
A1 = bu[V1 + 3];
A2 = bu[V1 + 4];

A1 = (V0 << 8) | V0;

V0 = bu[V1 + 5];

A2 = (V0 << 8) | A2;

add_x_y_to_window_position;

V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 6;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0x52 WMODE
get curent script offset and store result in v0;

a0 = [v0 + 1];
a1 = [v0 + 2];
a2 = [v0 + 3];

set_window_style_cbc

move script pointer by 4

v0 = 0;
////////////////////////////////



////////////////////////////////
// 0x53 WREST
V0 = bu[800722C4];          // current entity
V1 = hu[800831FC + V0 * 2]; // script pointer
V0 = w[8009C6DC];           // current field file offset.
A0 = bu[V1 + V0 + 1];

reset_window

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0x54 WCLSE
a0 = param1;

set_state_to_close;

if (v0 == 0)
{
    v0 = 1;
}
else
{
    v0 = 0;
    move script pointer by 2
}
////////////////////////////////



////////////////////////////////
// 0x55 WROW
V0 = bu[800722C4];          // current entity
V1 = hu[800831FC + V0 * 2]; // script pointer
V0 = w[8009C6DC];           // current field file offset.
A0 = bu[V1 + V0 + 1];
A1 = bu[V1 + V0 + 2];

A1 = A1 * 10 + 9;
set_window_height;

// move pointer by 3
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 3;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0x56 GWCOL
A0 = 1;
A1 = 3;
read_memory_block_one_byte;

A0 = 2;
A1 = 4;
A2 = bu[80049208 + V0 * 3];
store_memory_block_one_byte;

A0 = 3;
A1 = 5;
A2 = bu[80049209 + V0 * 3];
store_memory_block_one_byte;

A0 = 4;
A1 = 6;
A2 = bu[8004920A + V0 * 3];
store_memory_block_one_byte;

// move pointer by 7
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 7;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0x57 SWCOL
A0 = 1;
A1 = 3;
read_memory_block_one_byte;
S0 = V0 * 3;

A0 = 2;
A1 = 4;
read_memory_block_one_byte;
[80049208 + S0] = b(V0);

A0 = 3;
A1 = 5;
read_memory_block_one_byte;
[80049209 + S0] = b(V0);

A0 = 4;
A1 = 6;
read_memory_block_one_byte;
[8004920A + S0] = b(V0);

// move pointer by 7
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 7;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



/////////////////////////////////////////////////////////
// manage_window_states
A0 - window ID
A1 - message ID

v0 = a0 & FF = 3;
v1 = [800832A0 + v0 * 30] = 0;

if (v0 < F)
{
    switch (v0)
    {
        case 0:
        {
            dialog_window_init;

            if (v0 == 0)
            {
                return 0;
            }

            return 1;
        }
        break;

        case 1:
        {
            dialog_window_growth;

            return 0;
        }
        break;

        case 2:
        {
            dialog_copy_text_from_field;

            return 0;
        }
        break;

        case 8:
        {
            dialog_scroll_text;

            return 0;
        }
        break;

        case C:
        {
            dialog_scroll_text_during_ok;

            return 0;
        }
        break;

        case D:
        {
            V0 = w[8009C6E0];
            V0 = w[V0 + 80];
            V0 = V0 & 0020;

            if (V0 != 0)
            {
                // set state to 2
                [800832A0 + A0 * 30] = h(2);

                return 0;
            }
        }
        break;

        case 3:
        {
            V0 = h[8011445C + A0 * 2];

            if (V0 == 0)
            {
                // set state to 2
                [800832A0 + A0 * 30] = h(2);
                return 0;
            }

            V0 = V0 - 1;
            [8011445C + A0 * 2] = V0;
            return 0;
        }
        break;

        case 4:
        {
            V0 = w[8009C6E0];
            V0 = w[V0 + 80];

            if (V0 & 0020)
            {
                V0 = h[8008327E + A0 * 30];
                V1 = V0 - 9;
                V0 = h[801142CC + A0 * 2];
                V1 = V1 / 10 + V0 - 1;

                A2 = h[8008328A + A0 * 30];

                if (A2 == V1)
                {
                    return 0;
                }

                [800832A0 + A0 * 30] = h(08); // set state to 8

                V0 = h[80083284 + A0 * 30];
                V0 = V0 - 2;
                [80083284 + A0 * 30] = h(V0);

                V0 = hu[801142CC + A0 * 2];
                V0 = V0 + 1;
                [801142CC + A0 * 2] = h(V0);
            }

            return 0;
        }
        break;

        case 6:
        {
            V0 = [800832A2 + A0 * 30];

            // if window can't be clicked
            if (V0 & 01)
            {
                return 0;
            }

            V0 = [8009C6E0];
            V0 = [V0 + 80];

            if (V0 & 0020)
            {
                // set state to 7
                [800832A0 + A0 * 30] = h(07);

                dialog_window_discrease;

                return 0;
            }
        }

        case E:
        {
            V0 = w[8009C6E0];
            V0 = w[V0 + 80];
            V0 = V0 & 0020;

            if (V0 != 0)
            {
                dialog_init_next_window;

                return 0;
            }
        }
        break;

        case B:
        {
            V0 = w[8009C6E0];
            V0 = w[V0 + 80];
            V0 = V0 & 0020;

            if (V0 == 0)
            {
                return 0;
            }

            [800832A0 + A0 * 30] = h(0C) // set state to C

            V0 = h[8008328A + A0 * 30];
            V0 = V0 * 10 + 11;
            [800E424C + A0 * 30] = h(V0);

            V0 = hu[80083284 + A0 * 30];
            V0 = V0 - 2;
            [80083284 + A0 * 30] = h(V0);

            return 0;
        }
        break;

        case 9:
        {
            dialog_init_next_window;

            return 0;
        }
        break;

        case 5 7:
        {
            dialog_window_discrease;

            if (V0 != 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        break;
    }
}

// type A, >= F
return 0;
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// manage_ask_window_states
a0 = window id
a1 = dialog id
a2 = first
a3 = last

S0 = A0;
S2 = A2;
v1 = state from window structure;
s1 = [sp + 40]; // sp + 18 from ASK opcode where we stored data from mb/offset
s3 = a3;

if (v1 < F)
{
    switch (v1)
    {
        case 0x0:
        {
            dialog_window_init;

            if (v0 == 0)
            {
                return 0;
            }

            return 1;
        }
        break;

        case 1:
        {
            dialog_window_growth;

            return 0;
        }
        break;

        case 2:
        {
            dialog_copy_text_from_field;

            return 0;
        }
        break;

        case 8:
        {
            dialog_scroll_text;

            return 0;
        }
        break;

        case C:
        {
            dialog_scroll_text_during_ok;

            return 0;
        }
        break;

        case 0xD:
        {
            V0 = w[8009c6e0];
            V0 = w[V0 + 80];
            if (V0 & 0020)
            {
                // set state to 2
                [800832a0 + A0 * 30] = h(2);
                return 0;
            }
        }
        break;

        case 0x3:
        {
            V0 = h[8011445C + A0 * 2];

            if (V0 == 0)
            {
                // set state to 2
                [800832A0 + A0 * 30] = h(2);
                return 0;
            }

            V0 = V0 - 1;
            [8011445C + A0 * 2] = V0;
            return 0;
        }
        break;

        case 0x4:
        {

            V0 = w[8009C6E0];
            V0 = w[V0 + 80];

            if (V0 & 0020)
            {
                V0 = h[8008327E + A0 * 30];
                V1 = V0 - 9;
                V0 = h[801142CC + A0 * 2];
                V1 = V1 / 10 + V0 - 1;

                A2 = h[8008328A + A0 * 30];

                if (A2 == V1)
                {
                    return 0;
                }

                [800832A0 + A0 * 30] = h(08); // set state to 8

                V0 = h[80083284 + A0 * 30];
                V0 = V0 - 2;
                [80083284 + A0 * 30] = h(V0);

                V0 = hu[801142CC + A0 * 2];
                V0 = V0 + 1;
                [801142CC + A0 * 2] = h(V0);
            }

            return 0;
        }
        break;

        case 0x6:
        {
            V0 = hu[800832A2 + A0 * 30];

            if (V0 & 01)
            {
                return 0;
            }

            [8008328E + A0 * 30] = b(1);

            V0 = w[8008C6E0];
            V0 = w[V0 + 70];
            if (V0 & 1000)
            {
                V0 = S2;
                V1 = h[S1];

                if (V0 < V1) // if first less than current
                {
                    play_window_pointer_click_sound;
                }

                V0 = hu[S1];
                V0 = V0 - 1;
                [S1] = h(V0);
            }

            V0 = w[8008C6E0];
            V0 = w[V0 + 70];
            if (V0 & 4000)
            {
                V1 = S3;
                V0 = h[S1];

                if (V0 < V1) // if current less than last
                {
                    play_window_pointer_click_sound;
                }

                V0 = hu[S1];
                V0 = V0 + 1;
                [S1] = h(V0);
            }

            V0 = [S1];
            V1 = S2;
            if (V0 < V1)
            {
                [S1] = h(S2);
            }

            V1 = [S1];
            V0 = S3;
            if (V0 < V1)
            {
                [S1] = h(S3);
            }

            [80083298 + A0 * 30] = h(5);
            V0 = h[S1];
            [8008329A + A0 * 30] = h(V0 * 10 + 6);

            V1 = w[8009c6e0];
            if (w[V1 + 80] & 0020)
            {
                play_window_pointer_click_sound;

                [800832a0 + A0 * 30] = h(7);

                dialog_window_discrease;
            }

            return 0;
        }
        break;

        case 0xE:
        {
            V0 = w[8009C6E0];
            V0 = w[V0 + 80];
            V0 = V0 & 0020;

            if (V0 != 0)
            {
                dialog_init_next_window;

                return 0;
            }
        }
        break;

        case 0xB:
        {
            V0 = w[8009C6E0];
            V0 = w[V0 + 80];
            V0 = V0 & 0020;

            if (V0 == 0)
            {
                return 0;
            }

            [800832A0 + A0 * 30] = h(0C) // set state to C

            V0 = h[8008328A + A0 * 30];
            V0 = V0 * 10 + 11;
            [800E424C + A0 * 30] = h(V0);

            V0 = hu[80083284 + A0 * 30];
            V0 = V0 - 2;
            [80083284 + A0 * 30] = h(V0);

            return 0;
        }
        break;

        case 9:
        {
            dialog_init_next_window;

            return 0;
        }
        break;

        case 0x5 0x7:
        {
            dialog_window_discrease;

            if (V0 != 0)
            {
                [8008328E + A0 * 30] = b(0);

                return 1;
            }
            else
            {
                V0 = bu[8008328E + A0 * 30];
                V0 = V0 xor 1;
                [8008328E + A0 * 30] = b(V0);

                return 0;
            }
        }
        break;
}

// 0xA
v0 = 0;
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// dialog_scroll_text_during_ok
V1 = bu[8008326C + A1];
V0 = bu[800722C4];
if (V1 != V0)
{
    return;
}

V0 = h[80083284 + A0 * 30];
A2 = V0;
V1 = [800E424C + A0 * 2];
V0 = V0 + V1;
if (V0 <= 0)
{
    // set state 9
    [800832A0 + A0 * 30] = h(9);
    return;
}

V0 = hu[80114480 + A0 * 2];
V0 = A2 - V0 / 4;
[80083284 + A0 * 30] = h(V0);

V1 = w[8009C6E0];
V0 = w[V1 + 78];
if (V0 & 0020)
{
    V0 = hu[80114480 + A0 * 2];
    V0 = V0 + 1;
    [80114480 + A0 * 2] = h(V0);

    if (V0 >= 81)
    {
        [80114480 + A0 * 2] = h(80);
    }
}
else
{
    V0 = hu[80114480 + A0 * 2];
    V0 = V0 - 1;
    [80114480 + A0 * 2] = h(V0);

    if (V0 < 2)
    {
        [80114480 + A0 * 2] = h(1);
    }
}

return;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// dialog_scroll_text
V1 = bu[8008326C + A0];
V0 = bu[800722C4];

if (V1 != V0)
{
    return;
}


A1 = hu[80083284 + A0 * 30];

if (A1 & 0F)
{
    V0 = A1 - 2;
    [80083284 + A0 * 30]= h(V0);
}
else
{
    [800832A0 + A0 * 30] = h(2); // set state to 2
}

return;
////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// dialog_init_next_window

A1 = A0;

V1 = bu[8008326C + A0];
V0 = bu[800722C4];

if (V1 != V0)
{
    return;
}

[800832A0 + A0 * 30] = h(02);
[80083288 + A0 * 30] = h(00);
[80083286 + A0 * 30] = h(00);
[80083284 + A0 * 30] = h(00);
[8008328A + A0 * 30] = h(00);
[800E4944 + A0 * 100] = b(FF);
[801142CC + A0 * 2] = h(00);
[80114480 + A0 * 2] = h(01);
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// dialog_window_init
A0 - window ID
A1 - message ID

V0 = w[8007E7A8];
T1 = A1;

if (V0 == 0)
{
    A0 = 800A10DC;

    funcd4848

    return 1;
}
else
{
    V0 = A0 << 10;
    A1 = V0 >> 10
    V1 = bu[8008326C]; // parent entity

    if (V1 != FF) // if window has function attached to it
    {
        return 0;
    }

    // set parent entity
    V0 = bu[800722C4];
    [8008326C + A1] = b(V0);


    V0 = h[8008327C + A1 * 30]; // width
    if (V0 < 0)
    {
        V0 = V0 + 3;
    }
    V0 = V0 >> 2;
    [80083280 + A1 * 30] = h(V0);

    V1 = h[8008327E + A1 * 30]; // height
    if (V1 < 0)
    {
        V1 = V1 >> 3
    }
    V0 = V1 >> 2;
    [80083282 + A1 * 30] = h(V0);

    if (V0 < 8)
    {
        [80083282 + A1 * 30] = h(08);
    }

    V0 = h[80083280 + A1 * 30];
    if (V0 < 8)
    {
        [80083280 + A1 * 30] = h(08);
    }

    V1 = A1 << 8;
    V0 = 800E4944 + V1;
    [80083274 + A1 * 30] = w(V0);
    [80083284 + A1 * 30] = h(0);
    [80083286 + A1 * 30] = h(0);
    [80083288 + A1 * 30] = h(0);
    [8008328A + A1 * 30] = h(0);
    [8008328E + A1 * 30] = b(0);
    [800E4944 + V1] = b(FF);

    // write field dialog pointer to read
    A2 = 800E4234 + A1 * 4;
    V1 = w[8007E7A8];
    [A2] = w(V1);
    A1 = bu[V1 + T1 * 2 + 2];
    A1 = A1 + V1;
    [A2] = w(A1);
    A0 = bu[V1 + T1 * 2 + 3];
    A0 = A0 << 8;
    A0 = A0 + A1;
    [A2] = w(A0);

    V1 = bu[80071E2C];
    V1 = V1 + 1;
    [80071E2C] = b(V1);

    [80114480 + T0] = h(1);
    [80114470 + T0] = h(0);
    [801142CC + T0] = h(0);
    [80114278 + T0] = h(0);
    [800E4280 + T0] = h(0);
    [8011451C + T0] = h(-1);
    // set window state to 1;
    [800832A0 + A1 * 30] = h(1);

    return 0;
}
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// dialog_window_growth

V1 = bu[8008326C + A0];
V0 = bu[800722C4];

if (V1 != V0)
{
    800D5A94	lui    v0, $800a
    800D5A98	lbu    v0, $d820(v0)
    800D5A9C	nop
    800D5AA0	andi   v0, v0, $0003
    800D5AA4	beq    v0, zero, Ld5c8c [$800d5c8c]
    800D5AA8	nop
    800D5AAC	lui    a0, $800a
    800D5AB0	addiu  a0, a0, $10ec
    800D5AB4	jal    funcbeca4 [$800beca4]
    800D5AB8	ori    a2, zero, $0001
    800D5ABC	j      Ld5c8c [$800d5c8c]
    800D5AC0	nop
}

V1 = h[8008327C + A0 * 30]; // width
V0 = hu[80083280 + A0 * 30];
V1 = V1 >> 2;
V0 = V0 + V1;
[80083280 + A0 * 30]= h(V0);

if (V0 < 8)
{
    [80083280 + A0 * 30] = h(08);
}

V0 = h[8008327C + A0 * 30];
V1 = h[80083280 + A0 * 30];

if (V0 < V1)
{
    [80083280 + A0 * 30] = h(V0);
}



V1 = h[8008327E + A0 * 30];
V0 = hu[80083282 + A0 * 30];
V1 = V1 >> 2;
V0 = V0 + V1;
[80083282 + A0 * 30]= h(V0);

if (V0 < 8)
{
    [80083282 + A0 * 30] = h(08);
}

V0 = h[8008327E + A0 * 30];
V1 = h[80083282 + A0 * 30];

if (V0 < V1)
{
    [80083282 + A0 * 30] = h(V0);
}



V1 = h[80083280 + A0 * 30];
V0 = h[8008327Ñ + A0 * 30];

if (V1 == V0)
{
    V1 = h[80083282 + A0 * 30];
    V0 = h[8008327E + A0 * 30];

    if (V1 == V0)
    {
        // set state to 2
        [800832A0 + A0 * 30] = h(02);
    }
}
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// dialog_copy_text_from_field

S3 = A0;

V1 = bu[8008326C + S3]; // get windows parent entity
V0 = bu[800722C2];
if (V1 != V0)
{
    return;
}

V0 = hu[800832A2 + S3 * 30];
if (V0 & 2)
{
    A1 = 0100;
    S5 = 1;
}
else
{
    V0 = w[8009C6E0];
    V0 = w[V0 + 78];

    if (V0 & 0020)
    {
        V0 = hu[80114480 + S3 * 2];
        V0 = V0 + 1;

        if (V0 >= 81)
        {
            [80114480 + S3 * 2] = h(80);
        }
        else
        {
            [80114480 + S3 * 2] = h(V0);
        }
    }
    else
    {
        V0 = hu[80114480 + S3 * 2];
        V0 = V0 - 1;

        if (V0 < 2)
        {
            [80114480 + S3 * 2] = h(01);
        }
        else
        {
            [80114480 + S3 * 2] = h(V0);
        }
    }



    V1 = bu[8009D7D0]; // message speed
    if (V1 < 80)
    {
        A1 = ((80 - V1) / 20) + 2;
        S5 = 1;
    }
    else
    {
        A1 = 2;
        S5 = ((V1 - 80) / 20) + 1;
    }
}

V0 = hu[80114480 + S3 * 2];
V0 = V0 / 10;
HI/LO = S5 * V0;
V0 = LO;

V1 = hu[80114470 + T3 * 2];
V1 = A1 + V1 + V0;
[80114470 + S3 * 2] = h(V1)

if (S5 >= V1)
{
    // write FF to end of string;
    V0 = h[80083288 + S3 * 30];
    [800E4944 + S3 * 100 + V0] = FF;

    return;
}

// loop
Ld5f04:	; 800D5F04
V0 = w[800E4234 + S3 * 4];
V0 = [V0];  // read letter
V1 = V0 - E0;

if (V1 < 20) // E0 - FF
{
    switch (V1)
    {
        case 0xFF:
        {
            [800832A0 + S3 * 30] = 6; // set window state to 6
            [80114470 + S3 * 2] = 0;

            V0 = h[80083288 + S3 * 30];
            [800E4944 + S3 * 100 + V0] = FF;

            return;
        }
        break;

        case 0xE7:
        {
            V0 = h[8008327E + S3 * 30]; // read window height
            A0 = h[8008328A + S3 * 30];
            V1 = V0 - 08;
            V0 = h[801142CC + S3 * 2];
            V1 = V1 / 10 + V0 - 1;

            if (A0 == V1)
            {
                [800832A0 + S3 * 30] = h(04); // set window state
                [80114480 + S3 * 2] = h(01);
                [80114470 + S3 * 2] = h(00);

                V0 = h[80083288 + S3 * 30];
                [800E4944 + S3 * 100 + V0] = FF;

                return;
            }

            V1 = w[800E4234 + S3 * 4];
            V1 = [V1];
            V0 = h[80083288 + S3 * 30];
            [800E4944 + S3 * 100 + V0] = b(V1);

            // reading offset + 1
            V0 = w[800E4234 + S3 * 4];
            V0 = V0 + 1;
            [800E4234 + S3 * 4] = w(V0);

            // number of byte + 1
            V0 = hu[80083288 + S3 * 30];
            V0 = V0 + 1;
            [80083288 + S3 * 30] = h(V0)

            // current row + 1
            V0 = hu[8008328A + S3 * 30];
            V0 = V0 + 1;
            [8008328A + S3 * 30] = h(V0);

            800D6028	j      Ld6ca0 [$800d6ca0]
        }
        break;

        case 0xE8 0xE9:
        {
            V0 = [800E4234 + S3 * 4];
            V0 = V0 + 1;
            [800E4234 + S3 * 4] = V0;

            [800832A0 + S3 * 30] = 0E; // set window state to E

            [80114480 + S3 * 2] = h(1);
            [80114470 + S3 * 2] = h(0);

            V0 = h[80083288 + S3 * 30];
            [800E4944 + S3 * 100 + V0] = FF;

            return;
        }
        break;

        case 0xE0 0xE1:
        {
            V0 = [800E4234 + S3 * 4]
            V0 = V0 + 1;
            [800E4234 + S3 * 4] = V0;

            if (0xE0)
            {
                x = 0A;
            }
            if (0xE1)
            {
                x = 04;
            }

            for (A2 = 0; A2 < x; A2 = A2 + 1)
            {
                // writes zeros to string data
                V0 = hu[80083288 + S3 * 30];
                [800E4944 + S3 * 100 + V0] = b(0)

                V0 = hu[80083288 + S3 * 30];
                V0 = V0 + 1;
                [80083288 + S3 * 30] = h(V0);

                V1 = hu[80083286 + S3 * 30];
                V1 = V1 + 1;
                [80083286 + S3 * 30] = h(V1);
            }

            800D618C	j      Ld6ca0 [$800d6ca0]
        }
        break;

        case 0xE2 0xE3 0xE4:
        {
            V0 = [800E4234 + S3 * 4]
            V0 = V0 + 1;
            [800E4234 + S3 * 4] = V0;

            if (0xE2)
            {
                V0 = h[80083288 + S3 * 30];
                [800E4944 + S3 * 100 + V0] = b(0C);
            }
            if (0xE3)
            {
                V0 = h[80083288 + S3 * 30];
                [800E4944 + S3 * 100 + V0] = b(0E);
            }
            if (0xE4)
            {
                V0 = h[80083288 + S3 * 30];
                [800E4944 + S3 * 100 + V0] = b(A9);
            }

            V0 = hu[80083288 + S3 * 30];
            V0 = V0 + 1;
            [80083288 + S3 * 30] = h(V0);



            if (0xE2)
            {
                V0 = h[80083288 + S3 * 30];
                [800E4944 + S3 * 100 + V0] = b(0);
            }
            if (0xE3 0xE4)
            {
                V0 = h[80083288 + S3 * 30];
                [800E4944 + S3 * 100 + V0] = b(2);
            }

            V0 = h[80083288 + S3 * 30];
            V0 = V0 + 1;
            [80083288 + S3 * 30] = h(V0);

            V0 = hu[80083286 + S3 * 30];
            V0 = V0 + 2;
            [80083286 + S3 * 30] = h(V0);

            800D62F8	j      Ld6ca0 [$800d6ca0]
        }
        break;

        case 0xEA 0xEB 0xEC 0xED 0xEE 0xEF 0xF0 0xF1 0xF2 0xF3 0xF4 0xF5:
        {
            V1 = w[800E4234 + S3 * 4];
            V0 = bu[V1];

            if (0xEA 0xEB 0xEC 0xED 0xEE 0xEF 0xF0 0xF1 0xF2)
            {
                S0 = V0 - EA;
                A0 = S0 & FFFF;
            }
            if (0xF3 0xF4 0xF5)
            {
                A0 = bu[8009D29E + V0] = 8009D391;

                if (A0 == FF)
                {
                    V0 = h[800E4278 + S3 * 2]

                    if (V0 >= 9)
                    {
                        V0 = V1 + 1;
                        [800E4234 + S3 * 4] = w(V0);
                        [800E4278 + S3 * 2] = h(0);

                        800D64F8	j      Ld6ca0 [$800d6ca0]
                    }

                    V0 = h[80083288 + S3 * 30]
                    [800E4944 + S3 * 100 + V0] = b(A9);

                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 + 1;
                    [80083288 + S3 * 30] = h(V0);

                    V0 = hu[800E4278 + S3 * 2];
                    V0 = V0 + 1;
                    [800E4278 + S3 * 2] = h(V0)

                    V0 = hu[80083286 + S3 * 30];
                    V0 = V0 + 1;
                    [80083286 + S3 * 30] = h(V0);

                    V0 = hu[80114470 + S3 * 2];
                    V0 = V0 - S5;
                    [80114470 + S3 * 2] = h(V0);

                    800D6A60	j      Ld6ca0 [$800d6ca0]
                }
            }

            system_get_character_name_offset;

            A0 = h[800E4278 + S3 * 2];
            A1 = V0 + A0;
            V1 = bu[A1];

            if (V1 == FF || A0 > 09)
            {
                V0 = w[800E4234 + S3 * 4];
                V0 = V0 + 1;
                [800E4234 + S3 * 4] = w(V0);

                [800E4278 + S3 * 2] = h(0);

                800D6360	j      Ld6ca0 [$800d6ca0]
            }

            V0 = h[80083288 + S3 * 30];
            V1 = bu[A1];
            [800E4944 + S3 * 100 + V0] = b(V1);

            V0 = hu[80083288 + S3 * 30];
            V0 = V0 + 1;
            [80083288 + S3 * 30] = h(V0);

            V0 = hu[800E4278 + S3 * 2];
            V0 = V0 + 1;
            [800E4278 + S3 * 2] = h(V0);

            V0 = hu[80083286 + S3 * 30];
            V0 = V0 + 1;
            [80083286 + S3 * 30] = h(V0);

            V0 = hu[80114470 + S3 * 2];
            V0 = V0 - S5;
            [80114470 + S3 * 2] = h(V0);

            800D6A60	j      Ld6ca0 [$800d6ca0]
        }
        break;

        case 0xFE:
        {
            A0 = w[800E4234 + S3 * 4];
            A0 = bu[A0];

            V0 = hu[80083288 + S3 * 30];
            [800E4944 + S3 * 100 + V0] = b(A0);

            V0 = w[800E4234 + S3 * 4];
            V0 = V0 + 1;
            [800E4234 + S3 * 4] = w(V0);

            V0 = hu[80083288 + S3 * 30];
            V0 = V0 + 1;
            [80083288 + S3 * 30] = h(V0);

            V0 = w[800E4234 + S3 * 4];
            V0 = bu[V0];

            if (V0 < D2 || 0xE3 0xE4 0xE5 0xE6 0xE7 0xE8)
            {
                800D665C	j      Ld6c18 [$800d6c18]
            }

            switch (V1)
            {
                case 0xDC 0xFF:
                {
                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 - 1;
                    [80083288 + S3 * 30] = h(V0);

                    V0 = w[800E4234 + S3 * 4];
                    V0 = V0 + 1;
                    [800E4234 + S3 * 4] = w(V0);

                    [800832A0 + S3 * 30] = 0D; // set window state

                    [80114480 + S3 * 2] = h(1);
                    [80114470 + S3 * 2] = h(0);

                    V0 = h[80083288 + S3 * 30];
                    [800E4944 + S3 * 100 + V0] = FF;

                    return;
                }
                break;

                case 0xE0: // scrolling while you hold button
                {
                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 - 1;
                    [80083288 + S3 * 30] = h(V0);

                    V0 = w[800E4234 + S3 * 4];
                    V0 = V0 + 1;
                    [800E4234 + S3 * 4] = w(V0);

                    [800832A0 + S3 * 30] = 0B; // set window state

                    [80114480 + S3 * 2] = h(1);
                    [80114470 + S3 * 2] = h(0);

                    V0 = h[80083288 + S3 * 30];
                    [800E4944 + S3 * 100 + V0] = FF;

                    return;
                }
                break;

                case 0xE1 0xDE 0xDF: // variable?
                {
                    // move back one byte cause we don't need FE in string.
                    V1 = hu[80083288 + S3 * 30];
                    V1 = V1 - 1;
                    [80083288 + S3 * 30] = V1;

                    // move to reading of previous byte
                    T2 = w[800E4234 + S3 * 4];
                    V0 = T2 - 1;
                    [800E4234 + S3 * 4] = w(V0);

                    // read number of copied byte
                    A0 = h[8011451C + S3 * 2];

                    // if we not reading yet
                    if (A0 == -1)
                    {
                        A0 = S3;

                        // get 2bytes value for current variable (memory bank and offset used)
                        get_variable_for_window_from_memory_bank

                        S0 = V0;

                        // read current byte (DE DF E1)
                        V0 = w[800E4234 + S3 * 4];
                        V1 = bu[V0 + 1];

                        // data for variable
                        A0 = S0 & FFFF;
                        // address to write
                        A1 = 8001144DC + S3 * 10;

                        if (V1 == DE)
                        {
                            convert_digit_to_string
                        }
                        else if (V1 == DF)
                        {
                            convert_hex_to_string
                        }
                        else if (V1 == E1)
                        {
                            convert_digit_to_string_with_space
                        }

                        // increment current reading offset so we start read on next rotation
                        V0 = hu[8011451C + S3 * 2];
                        V0 = V0 + 1;
                        [8011451C + S3 * 2] = h(V0)

                        800D69B8	j      Ld6ca0 [$800d6ca0]
                    }
                    else
                    {
                        // read current byte
                        V1 = bu[801144DC + S3 * 10 + A0];

                        // if not end of string and number of copied byte less than 10
                        if (V1 != FF && A0 < 10)
                        {
                            V0 = h[80083288 + S3 * 30];
                            [800E4944 + S3 * 100 + V0] = b(V1);

                            V0 = hu[80083288 + S3 * 30];
                            V0 = V0 + 1;
                            [80083288 + S3 * 30] = h(V0);

                            V0 = hu[8011451C + S3 * 2];
                            V0 = V0 + 1;
                            [8011451C + S3 * 2] = h(V0);

                            V0 = hu[80083286 + S3 * 30];
                            V0 = V0 + 1;
                            [80083286 + S3 * 30] = h(V0);

                            V0 = hu[80114470 + S3 * 2];
                            V0 = V0 - S5;
                            [80114470 + S3 * 2] = h(V0);

                            800D6A60	j      Ld6ca0 [$800d6ca0]
                        }

                        undo previous move and go to next byte (end of this opcode)
                        V0 = T2 + 1;
                        [800E4234 + S3 * 4] = w(V0);

                        // write -1 to number of readed byte
                        [8011451C + S3 * 2] = h(-1);
                    }

                    // increase number of readed variable (next time we read next one)
                    V0 = hu[800E4280 + S3 * 2];
                    V0 = V0 + 1;
                    [800E4280 + S3 * 2] = h(V0)

                    800D69B8	j      Ld6ca0 [$800d6ca0]
                }
                break;

                case 0xE2:
                {
                    V1 = hu[80083288 + S3 * 30];
                    V1 = V1 - 1;
                    [80083288 + S3 * 30] = h(V1);

                    A0 = w[800E4234 + S3 * 4];
                    V0 = A0 - 1;
                    [800E4234 + S3 * 4] = w(V0);

                    A1 = h[8011451C + S3 * 2];

                    if (A1 == -1)
                    {
                        S0 = bu[A0 + 1];
                        V0 = bu[A0 + 2];
                        S1 = bu[A0 + 3];
                        V1 = bu[A0 + 4];

                        V0 = V0 << 8;
                        S0 = S0 | V0;
                        V1 = V1 << 8;
                        S1 = S1 | V1;

                        A1 = S1;
                        A2 = 0;

                        if (A1 != 0)
                        {
                            A3 = S0;

                            loopd6944:	; 800D6944
                            {
                                V0 = bu[8009D288 + A3 + A2]; // reading from memory bank 1/2
                                [801144DC + S3 * 10 + A2] = b(V0);

                                A2 = A2 + 1;
                                A0 = A2 < A1;

                                800D6970	bne    a0, zero, loopd6944 [$800d6944]
                        }

                        Ld6978:	; 800D6978
                        [801144DC + S3 * 10 + A2] = b(FF);

                        V0 = hu[8011451C + S3 * 2];
                        V0 = V0 + 1;
                        [8011451C + S3 * 2] = h(V0)

                        800D69B8	j      Ld6ca0 [$800d6ca0]
                    }

                    V1 = bu[801144DC + S3 * 10 + A1];

                    if (V1 == FF)
                    {
                        V0 = A0 + 5;
                        [800E4234 + S3 * 4] = w(V0);
                        [8011451C + S3 * 2] = h(-1);
                        800D69E8	j      Ld6ca0 [$800d6ca0]
                    }

                    V0 = h[80083288 + S3 * 30];
                    V1 = bu[A1];
                    [800E4944 + S3 * 100 + V0] = b(V1);

                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 + 1;
                    [80083288 + S3 * 30] = V0;

                    V0 = hu[8011451C + S3 * 2];
                    V0 = V0 + 1;
                    [800E4234 + S3 * 4] = h(V0);

                    V0 = hu[80083286 + S3 * 30];
                    V0 = V0 + 1;
                    [80083286 + S3 * 30] = V0;

                    V0 = hu[80114470 + S3 * 2];
                    V0 = V0 - S5;
                    [80114470 + S3 * 2] = h(V0);

                    800D6A60	j      Ld6ca0 [$800d6ca0]
                {
                break;

                case 0xE9 0xD2 0xD3 0xD4 0xD5 0xD6 0xD7 0xD8 0xD9 0xDA 0xDB:
                {
                    A0 = w[800E4234 + S3 * 4];
                    A0 = bu[A0];

                    V0 = hu[80083288 + S3 * 30];
                    [800E4944 + S3 * 100 + V0] = b(A0);

                    V0 = w[800E4234 + S3 * 4];
                    V0 = V0 + 1;
                    [800E4234 + S3 * 4] = w(V0);

                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 + 1;
                    [80083288 + S3 * 30] = h(V0);

                    800D6ACC	j      Ld6ca0 [$800d6ca0]
                {
                break;

                case 0xDD:
                {
                    [800832A0 + S3 * 30] = 03; // set window state

                    V0 = w[800E4234 + S3 * 4];
                    V0 = V0 + 1;
                    [800E4234 + S3 * 4] = w(V0);

                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 + 1;
                    [80083288 + S3 * 30] = h(V0);

                    V0 = w[800E4234 + S3 * 4];
                    V0 = bu[V0];
                    [8011445C + S3 * 2] = h(V0)

                    V0 = w[800E4234 + S3 * 4];
                    V0 = V0 + 1;
                    [800E4234 + S3 * 4] = w(V0);

                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 + 1;
                    [80083288 + S3 * 30] = h(V0);

                    V0 = w[800E4234 + S3 * 4];
                    V0 = bu[V0];
                    V1 = hu[8011445C + S3 * 2];
                    V0 = V0 << 8;
                    V1 = V1 | V0
                    [8011445C + S3 * 2] = h(V1)

                    V0 = w[800E4234 + S3 * 4];
                    V0 = V0 + 1;
                    [800E4234 + S3 * 4] = w(V0);

                    V0 = hu[80083288 + S3 * 30];
                    V0 = V0 + 1;
                    [80083288 + S3 * 30] = h(V0);

                    V0 = h[80083288 + S3 * 30];
                    [800E4944 + S3 * 100 + V0] = FF;

                    return;
                }
                break;
            }
        }
        break;

        case 0xFA 0xFB 0xFC 0xFD:
        {
            A0 = [800E4234 + S3 * 4];
            A0 = [A0];
            [800E4944 + S3 * 100 + V0] = A0;
            V0 = [800E4234 + S3 * 4]
            V0 = V0 + 1;
            [800E4234 + S3 * 4] = V0;

            V0 = [80083288 + S3 * 30];
            V0 = V0 + 1;
            [80083288 + S3 * 30] = V0;
        }
    }
}

Ld6c18:	; 800D6C18
//0xE5 0xE6 0xF6 0xF7 0xF8 0xF9 and all others:
V1 = w[800E4234 + S3 * 4];
V0 = h[80083288 + S3 * 30];
V1 = b[V1]; // read letter
[800E4944 + S3 * 100 + V0] = b(V1); // write letter 800D6C40

V0 = w[800E4234 + S3 * 4];
V0 = V0 + 1;
[800E4234 + S3 * 4] = w(V0);

V0 = hu[80083288 + S3 * 30];
V0 = V0 + 1;
[80083288 + S3 * 30] = h(V0);

V0 = hu[80083286 + S3 * 30];
V0 = V0 + 1;
[80083286 + S3 * 30] = h(V0);

V0 = hu[80114470 + S3 * 2];
V0 = V0 - S5;
[80114470 + S3 * 2] = h(V0);

Ld6ca0:	; 800D6CA0
V1 = h[80114470 + S3 * 2];
V0 = S5 < V1;

800D6CC4	bne    v0, zero, Ld5f04 [$800d5f04]

// write FF to end of string;
V0 = h[80083288 + S3 * 30];
[800E4944 + S3 * 100 + V0] = FF;
////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// dialog_window_discrease

V1 = bu[8008326C + A1];
V0 = bu[800722C4];

if (V1 != V0)
{
    return;
}

V0 = [80083280 + A0 * 30];
A1 = V0;
if (V0 >= 8)
{
    V0 = [8008327C + A0 * 30];
    V0 = V0 >> 2;
    V0 = A1 - V0;
}
else
{
    V0 = 8;
}

[80083280 + A0 * 30] = h(V0);



V0 = h[80083282 + A0 * 30];
A1 = V0;
if (V0 >= 8)
{
    V0 = [8008327E + A0 * 30];
    V0 = V0 >> 2;
    V0 = A1 - V0;
}
else
{
    V0 = 8;
}

[80083282 + A0 * 30] = h(V0);



V1 = A0 * 30;
V0 = h[80083280 + A0 * 30];

if (V0 >= 9)
{
    return 0;
}

V0 = h[80083282 + A0 * 30];

if (V0 >= 9)
{
    return 0;
}

[80083286 + A0 * 30] = h(0);
[800832A0 + A0 * 30] = h(0); // set state to 0
[8008326C + A0] = b(FF);

V1 = bu[80071E2C];
V1 = V1 - 1;
[80071E2C] = b(V1);

return 1;
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// get_variable_for_window_from_memory_bank
A0 - window id

// current variable;
V0 = h[800E4280 + A0 * 2];
V1 = bu[800E4214 + A0 * 8 + V0];

if (V1 < 10)
{
    switch (V1)
    {
        case 0x0:
        {
            V0 = h[800E4280 + A0 * 2];
            V1 = hu[800E4D48 + V0 * 2 + A0 * 10];

            800D7308	j      Ld7754 [$800d7754]
        }
        break;

        case 0x1:
        {
            V0 = h[800E4280 + A0 * 2]

            // get offset
            V0 = hu[800E4D48 + V0 * 2 + A0 * 10];

            // get data byte
            V1 = bu[8009D288 + V0];

            800D735C	j      Ld7754 [$800d7754]
        }
        break;

        case 0x02:
        {
            V0 = h[800E4280 + A0 * 2]
            V1 = hu[800E4D48 + V0 * 2 + A0 * 10];

            V0 = bu[8009D289 + V1];
            V1 = bu[8009D288 + V1];
            V0 = V0 << 8;
            V1 = V1 | V0;

            800D7748	j      Ld7754 [$800d7754]
        }
        break;

        case 0x3:
        {
            800D73C8	sll    v0, a0, $10
            800D73CC	sra    v0, v0, $10
            800D73D0	lui    a0, $800e
            800D73D4	addiu  a0, a0, $4d48
            800D73D8	sll    v1, v0, $04
            800D73DC	sll    v0, v0, $01
            800D73E0	lui    at, $800e
            800D73E4	addiu  at, at, $4280
            800D73E8	addu   at, at, v0
            800D73EC	lh     v0, $0000(at)
            800D73F0	addu   v1, v1, a0
            800D73F4	sll    v0, v0, $01
            800D73F8	addu   v0, v0, v1
            800D73FC	lhu    v0, $0000(v0)
            800D7400	j      Ld75a0 [$800d75a0]
            800D7404	addiu  v0, v0, $0100
        }
        break;

        case 0x4:
        {
            800D7408	sll    v0, a0, $10
            800D740C	sra    v0, v0, $10
            800D7410	lui    a0, $800e
            800D7414	addiu  a0, a0, $4d48
            800D7418	sll    v1, v0, $04
            800D741C	sll    v0, v0, $01
            800D7420	lui    at, $800e
            800D7424	addiu  at, at, $4280
            800D7428	addu   at, at, v0
            800D742C	lh     v0, $0000(at)
            800D7430	addu   v1, v1, a0
            800D7434	sll    v0, v0, $01
            800D7438	addu   v0, v0, v1
            800D743C	lhu    v0, $0000(v0)
            800D7440	nop
            800D7444	addiu  v0, v0, $0100
            800D7448	andi   v1, v0, $ffff
            800D744C	lui    at, $800a
            800D7450	addiu  at, at, $d289 (=-$2d77)
            800D7454	addu   at, at, v1
            800D7458	lbu    v0, $0000(at)
            800D745C	lui    at, $800a
            800D7460	addiu  at, at, $d288 (=-$2d78)
            800D7464	addu   at, at, v1
            800D7468	lbu    v1, $0000(at)
            800D746C	j      Ld7748 [$800d7748]
            800D7470	sll    v0, v0, $08
        }
        break;

        case 0xB:
        {
            800D7474	sll    v0, a0, $10
            800D7478	sra    v0, v0, $10
            800D747C	lui    a0, $800e
            800D7480	addiu  a0, a0, $4d48
            800D7484	sll    v1, v0, $04
            800D7488	sll    v0, v0, $01
            800D748C	lui    at, $800e
            800D7490	addiu  at, at, $4280
            800D7494	addu   at, at, v0
            800D7498	lh     v0, $0000(at)
            800D749C	addu   v1, v1, a0
            800D74A0	sll    v0, v0, $01
            800D74A4	addu   v0, v0, v1
            800D74A8	lhu    v0, $0000(v0)
            800D74AC	j      Ld75a0 [$800d75a0]
            800D74B0	addiu  v0, v0, $0200
        }
        break;

        case 0xC:
        {
            800D74B4	sll    v0, a0, $10
            800D74B8	sra    v0, v0, $10
            800D74BC	lui    a0, $800e
            800D74C0	addiu  a0, a0, $4d48
            800D74C4	sll    v1, v0, $04
            800D74C8	sll    v0, v0, $01
            800D74CC	lui    at, $800e
            800D74D0	addiu  at, at, $4280
            800D74D4	addu   at, at, v0
            800D74D8	lh     v0, $0000(at)
            800D74DC	addu   v1, v1, a0
            800D74E0	sll    v0, v0, $01
            800D74E4	addu   v0, v0, v1
            800D74E8	lhu    v0, $0000(v0)
            800D74EC	nop
            800D74F0	addiu  v0, v0, $0200
            800D74F4	andi   v1, v0, $ffff
            800D74F8	lui    at, $800a
            800D74FC	addiu  at, at, $d289 (=-$2d77)
            800D7500	addu   at, at, v1
            800D7504	lbu    v0, $0000(at)
            800D7508	lui    at, $800a
            800D750C	addiu  at, at, $d288 (=-$2d78)
            800D7510	addu   at, at, v1
            800D7514	lbu    v1, $0000(at)
            800D7518	j      Ld7748 [$800d7748]
            800D751C	sll    v0, v0, $08
        }
        break;

        case 0xD:
        {
            800D7520	sll    v0, a0, $10
            800D7524	sra    v0, v0, $10
            800D7528	lui    a0, $800e
            800D752C	addiu  a0, a0, $4d48
            800D7530	sll    v1, v0, $04
            800D7534	sll    v0, v0, $01
            800D7538	lui    at, $800e
            800D753C	addiu  at, at, $4280
            800D7540	addu   at, at, v0
            800D7544	lh     v0, $0000(at)
            800D7548	addu   v1, v1, a0
            800D754C	sll    v0, v0, $01
            800D7550	addu   v0, v0, v1
            800D7554	lhu    v0, $0000(v0)
            800D7558	j      Ld75a0 [$800d75a0]
            800D755C	addiu  v0, v0, $0300
        }
        break;

        case 0xF:
        {
            800D7560	sll    v0, a0, $10
            800D7564	sra    v0, v0, $10
            800D7568	lui    a0, $800e
            800D756C	addiu  a0, a0, $4d48
            800D7570	sll    v1, v0, $04
            800D7574	sll    v0, v0, $01
            800D7578	lui    at, $800e
            800D757C	addiu  at, at, $4280
            800D7580	addu   at, at, v0
            800D7584	lh     v0, $0000(at)
            800D7588	addu   v1, v1, a0
            800D758C	sll    v0, v0, $01
            800D7590	addu   v0, v0, v1
            800D7594	lhu    v0, $0000(v0)
            800D7598	nop
            800D759C	addiu  v0, v0, $0400

            Ld75a0:	; 800D75A0
            800D75A0	andi   v0, v0, $ffff
            800D75A4	lui    at, $800a
            800D75A8	addiu  at, at, $d288 (=-$2d78)
            800D75AC	addu   at, at, v0
            800D75B0	lbu    v1, $0000(at)
            800D75B4	j      Ld7754 [$800d7754]
            800D75B8	nop
        }
        break;

        case 0xE:
        {
            800D75BC	sll    v0, a0, $10
            800D75C0	sra    v0, v0, $10
            800D75C4	lui    a0, $800e
            800D75C8	addiu  a0, a0, $4d48
            800D75CC	sll    v1, v0, $04
            800D75D0	sll    v0, v0, $01
            800D75D4	lui    at, $800e
            800D75D8	addiu  at, at, $4280
            800D75DC	addu   at, at, v0
            800D75E0	lh     v0, $0000(at)
            800D75E4	addu   v1, v1, a0
            800D75E8	sll    v0, v0, $01
            800D75EC	addu   v0, v0, v1
            800D75F0	lhu    v0, $0000(v0)
            800D75F4	nop
            800D75F8	addiu  v0, v0, $0300
            800D75FC	andi   v1, v0, $ffff
            800D7600	lui    at, $800a
            800D7604	addiu  at, at, $d289 (=-$2d77)
            800D7608	addu   at, at, v1
            800D760C	lbu    v0, $0000(at)
            800D7610	lui    at, $800a
            800D7614	addiu  at, at, $d288 (=-$2d78)
            800D7618	addu   at, at, v1
            800D761C	lbu    v1, $0000(at)
            800D7620	j      Ld7748 [$800d7748]
            800D7624	sll    v0, v0, $08
        }
        break;

        case 0x7:
        {
            800D7628	sll    v0, a0, $10
            800D762C	sra    v0, v0, $10
            800D7630	lui    a0, $800e
            800D7634	addiu  a0, a0, $4d48
            800D7638	sll    v1, v0, $04
            800D763C	sll    v0, v0, $01
            800D7640	lui    at, $800e
            800D7644	addiu  at, at, $4280
            800D7648	addu   at, at, v0
            800D764C	lh     v0, $0000(at)
            800D7650	addu   v1, v1, a0
            800D7654	sll    v0, v0, $01
            800D7658	addu   v0, v0, v1
            800D765C	lhu    v0, $0000(v0)
            800D7660	nop
            800D7664	addiu  v0, v0, $0400
            800D7668	andi   v1, v0, $ffff
            800D766C	lui    at, $800a
            800D7670	addiu  at, at, $d289 (=-$2d77)
            800D7674	addu   at, at, v1
            800D7678	lbu    v0, $0000(at)
            800D767C	lui    at, $800a
            800D7680	addiu  at, at, $d288 (=-$2d78)
            800D7684	addu   at, at, v1
            800D7688	lbu    v1, $0000(at)
            800D768C	j      Ld7748 [$800d7748]
            800D7690	sll    v0, v0, $08
        }
        break;

        case 0x5:
        {
            800D7694	sll    v0, a0, $10
            800D7698	sra    v0, v0, $10
            800D769C	lui    a0, $800e
            800D76A0	addiu  a0, a0, $4d48
            800D76A4	sll    v1, v0, $04
            800D76A8	sll    v0, v0, $01
            800D76AC	lui    at, $800e
            800D76B0	addiu  at, at, $4280
            800D76B4	addu   at, at, v0
            800D76B8	lh     v0, $0000(at)
            800D76BC	addu   v1, v1, a0
            800D76C0	sll    v0, v0, $01
            800D76C4	addu   v0, v0, v1
            800D76C8	lhu    v0, $0000(v0)
            800D76CC	nop
            800D76D0	lui    at, $8007
            800D76D4	addiu  at, at, $5e24
            800D76D8	addu   at, at, v0
            800D76DC	lbu    v1, $0000(at)
            800D76E0	j      Ld7754 [$800d7754]
            800D76E4	nop
        }
        break;

        case 0x6:
        {
            800D76E8	sll    v0, a0, $10
            800D76EC	sra    v0, v0, $10
            800D76F0	lui    a0, $800e
            800D76F4	addiu  a0, a0, $4d48
            800D76F8	sll    v1, v0, $04
            800D76FC	sll    v0, v0, $01
            800D7700	lui    at, $800e
            800D7704	addiu  at, at, $4280
            800D7708	addu   at, at, v0
            800D770C	lh     v0, $0000(at)
            800D7710	addu   v1, v1, a0
            800D7714	sll    v0, v0, $01
            800D7718	addu   v0, v0, v1
            800D771C	lhu    v1, $0000(v0)
            800D7720	nop
            800D7724	lui    at, $8007
            800D7728	addiu  at, at, $5e25
            800D772C	addu   at, at, v1
            800D7730	lbu    v0, $0000(at)
            800D7734	lui    at, $8007
            800D7738	addiu  at, at, $5e24
            800D773C	addu   at, at, v1
            800D7740	lbu    v1, $0000(at)
            800D7744	sll    v0, v0, $08

            Ld7748:	; 800D7748
            800D7748	j      Ld7754 [$800d7754]
            800D774C	or     v1, v1, v0
        }
        break;
    }
}

// 0x8 0x9 0xA
Ld7750:	; 800D7750
V1 = 0;

Ld7754:	; 800D7754
V0 = V1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// convert_digit_to_string
A0 - data for variable
A1 - address to write

T0 = A0;
T1 = 0;
A2 = 2710; (10000)
A3 = 0;
T2 = 66666667;

loopd7774:	; 800D7774
{
    V0 = T0;
    V1 = A2;
    HI/LO = V0 / V1;
    V1 = LO;

    A0 = V1;

    if (T1 == 0)
    {
        800D77B8	beq    v0, zero, Ld77f4 [$800d77f4]
    }

    Ld77c0:	; 800D77C0
    T1 = 1;

    // write byte
    V1 = bu[800E0738 + V1];
    [A1 + A3] = b(V1);
    A3 = A3 + 1;

    Ld77f4:	; 800D77F4
    HI/LO = A0 * A2;
    A0 = LO;
    V0 = A2;
    HI/LO = V0 * T2;
    V1 = A2 >> 0F;
    V0 = HI >> 2 - V1;
    A2 = V0;
    V0 = V0 < 2;
    T0 = T0 - A0;
    800D7824	beq    v0, zero, loopd7774 [$800d7774]
}

V0 = A3 + A1;
V1 = T0; // data for variable

A0 = bu[800E0738 + V1];

[V0 + 1] = b(FF);
[V0] = b(A0);
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// convert_hex_to_string
A0 - data for variable
A1 - address to write

T1 = 0;
A2 = 1000;
A3 = 0;
V0 = A0;

loopd7980:	; 800D7980
{
    V1 = A2;
    HI/LO = V0 / V1;
    V1 = LO;
    T0 = V1;

    if (T1 == 0)
    {
        800D79C0	beq    v0, zero, Ld79fc [$800d79fc]
    }

    Ld79c8:	; 800D79C8
    T1 = 1;

    V1 = bu[800E0738 + V1];
    [A1 + A3] = b(V1);
    A3 = A3 + 1;

    Ld79fc:	; 800D79FC
    HI/LO = T0 * A2;
    V1 = A2;
    V0 = LO;
    A0 = A0 - V0;

    if (V1 < 0)
    {
        V1 = V1 + 0F;
    }

    V0 = V1 >> 4;
    A2 = V0;
    V0 = V0 < 2;
    V0 = A0 & FFFF;

    800D7A20	beq    v0, zero, loopd7980 [$800d7980]
}

V0 = A1 + A3;
V1 = A0;

A0 = bu[800E0738 + V1];

[V0 + 1] = b(FF);
[V0] = b(A0);
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// convert_digit_to_string_with_space
A0 - data for variable
A1 - address to write

T0 = A0;
T1 = 0;
A3 = 2710;
A2 = 0;
T2 = 66666667;

loopd7874:	; 800D7874
{
    V0 = T0;
    V1 = A3;
    HI/LO = V0 / V1;
    V1 = LO;
    A0 = V1;

    if (T1 == 0)
    {
        if (V0 == 0)
        {
            [A1 + A2] = b(00);
            A2 = A2 + 1;
            800D78EC	j      Ld7904 [$800d7904]
        }
    }

    Ld78c0:	; 800D78C0
    T1 = 1;
    V0 = A2;
    A2 = A2 + 1;
    V1 = bu[800E0738 + V1];
    [A1 + V0] = b(V1);

    Ld7904:	; 800D7904
    800D7904	mult   a0, a3
    800D7908	mflo   a0
    800D790C	sll    v1, a3, $10
    800D7910	sra    v0, v1, $10
    800D7914	mult   v0, t2
    800D7918	sra    v1, v1, $1f
    800D791C	mfhi   v0
    800D7920	sra    v0, v0, $02
    800D7924	subu   v0, v0, v1
    800D7928	addu   a3, v0, zero
    800D792C	sll    v0, v0, $10
    800D7930	sra    v0, v0, $10
    800D7934	slti   v0, v0, $0002
    800D7938	beq    v0, zero, loopd7874 [$800d7874]
    800D793C	subu   t0, t0, a0
}

800D7940	sll    v0, a2, $10
800D7944	sra    v0, v0, $10
800D7948	addu   v0, a1, v0
800D794C	andi   v1, t0, $ffff
800D7950	lui    at, $800e
800D7954	addiu  at, at, $0738
800D7958	addu   at, at, v1
800D795C	lbu    a0, $0000(at)
800D7960	ori    v1, zero, $00ff
800D7964	sb     v1, $0001(v0)
800D7968	jr     ra 
800D796C	sb     a0, $0000(v0)
////////////////////////////////////////////////////////













/////////////////////////////////////////////////////////
// set_window_x_y_width_height
A0 - window ID
A1 - x pos
A2 - y pos
A3 - width
height stored

s1 = A1; // x
S0 = a2; // y
S2 = a3; // width
S3 = height;

if (a1 < 8) // x position < 8
{
    S1 = 8;
}

if (S1 + S2 >= 0139) // if window end x position < 0x139
{
    S1 = 0138 - S2;
}

a1 = s0;

if (a1 < 8) // if window y position < 8
{
    S0 = 8;
}

if (S0 + S3 >= E1) // if window end y position < 0xE1
{
    S0 = E0 - S3;
}

[80083278 + A0 * 30] = s1; // x
[8008327A + A0 * 30] = s0; // y
[8008327C + A0 * 30] = s2; // width
[8008327E + A0 * 30] = s3; // height
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// set_window_style_cbc
writes data to window structure
a0 = window id
a1 = style
a2 = cbc
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// set_state_to_close
a0 = window id

V0 = hu[800832A0 + A0 * 30]; // window state

if (V0 == 1)
{
    return 0;
}

if (V0 = {2 4 6 8 B D})
{
    [800832A0 + A0 * 30] = h(07);
}

// 0 3 5 7 9 A C E
return 1;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x43 MPNAM
V0 = bu[800722C4];          // current entity
V1 = hu[800831FC + V0 * 2]; // script pointer
V0 = w[8009C6DC];           // current field file offset.
A0 = [V0 + V1 + 1];         // dialog_id

copy_dialog_to_map_name;

A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 2;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////////




////////////////////////////////////////////////////////
copy_dialog_to_map_name
V1 = w[8007E7A8];
if (V1 == 0)
{
    return 0;
}

S1 = V1;
S2 = 0;
S0 = 0;
S3 = 2;
V0 = A0 * 2;
V1 = V0 + S1;
V0 = V0 + S1;
V1 = bu[V1 + 2];
V0 = bu[V0 + 3];
S1 = S1 + V1;
V0 = V0 << 8;
S1 = S1 + V0;

loopd7ac8:	; 800D7AC8
V0 = bu[S1];
V1 = V0 - E2;
V0 = V1 < 1E;
if (V0 != 0)
{
    V0 = [800A1230 + V1 * 4];
    800D7AF4	jr     v0

    // E2
    {
        [8009D5F0 + S0] = b[0C];
        [8009D5F0 + S0 + 1] = b[00];
        S0 = S0 + 2;
        S1 = S1 + 1;
        800D7C44	sll    v0, s0, $10
        800D7BE4	j      Ld7c48 [$800d7c48]
    }

    // E3
    {
        [8009D5F0 + S0] = b[0E];
        [8009D5F0 + S0 + 1] = b[02];
        S0 = S0 + 2;
        S1 = S1 + 1;
        800D7B9C	j      Ld7c48 [$800d7c48]
        800D7BA0	sll    v0, s0, $10
    }

    // E4
    {
        [8009D5F0 + S0] = b[09];
        [8009D5F0 + S0 + 1] = b[02];
        S0 = S0 + 2;
        S1 = S1 + 1;
        800D7B9C	j      Ld7c48 [$800d7c48]
        800D7BA0	sll    v0, s0, $10
    }

    // EA EB EC ED EE EF F0 F1 F2
    {
        A1 = bu[S1];
        A0 = A0 - EA;
        system_get_character_name_offset;

        V1 = S2 << 10;
        A0 = V1 >> 10;
        A1 = V0 + A0;
        V1 = bu[A1];
        V0 = FF;

        800D7BD0	beq    v1, v0, Ld7be0 [$800d7be0]
        800D7BD4	slti   v0, a0, $0009
        800D7BD8	bne    v0, zero, Ld7bec [$800d7bec]
        800D7BDC	addiu  s2, s2, $0001

        Ld7be0:	; 800D7BE0
        800D7BE0	addiu  s1, s1, $0001
        800D7BE8	addu   s2, zero, zero
        800D7C44	sll    v0, s0, $10
        800D7BE4	j      Ld7c48 [$800d7c48]

        Ld7bec:	; 800D7BEC
        800D7BEC	sll    v0, s0, $10
        800D7BF0	lbu    v1, $0000(a1)
        800D7BF8	addiu  s0, s0, $0001
        800D7C30	sra    v0, v0, $10
        800D7C34	lui    at, $800a
        800D7C38	addiu  at, at, $d5f0 (=-$2a10)
        800D7C3C	addu   at, at, v0
        800D7C40	sb     v1, $0000(at)
        800D7C44	sll    v0, s0, $10
        800D7BF4	j      Ld7c48 [$800d7c48]
    }

    // FA FB FC FD FE
    {
        V1 = bu[S1];
        [8009D5F0 + S0] = b(V1);
        S0 = S0 + 1;
        S1 = S1 + 1;
    }
}

// E5 E6 E7 E8 E9 F3 F4 F5 F6 F7 F8 F9 and all others
Ld7c20:	; 800D7C20
V1 = bu[S1];
[8009D5F0 + S0] = b(V1);
S0 = S0 + 1;
S1 = S1 + 1;
V0 = S0 << 10;

Ld7c48:	; 800D7C48
800D7C48	sra    v0, v0, $10
800D7C4C	slti   v0, v0, $0017
800D7C50	bne    v0, zero, loopd7ac8 [$800d7ac8]
800D7C54	nop

// FF
800D7C58	sll    v0, s0, $10
800D7C5C	sra    v0, v0, $10
800D7C60	ori    v1, zero, $00ff
800D7C64	lui    at, $800a
800D7C68	addiu  at, at, $d5f0 (=-$2a10)
800D7C6C	addu   at, at, v0
800D7C70	sb     v1, $0000(at)
800D7C74	ori    v0, zero, $0001

Ld7c78:	; 800D7C78
////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
add_x_y_to_window_position
V1 = hu[80083278 + A0 * 30];
S0 = hu[8008327A + A0 * 30];
V1 = V1 + A1;
S0 = S0 + A2;
[80083278 + A0 * 30] = h(V1);
[8008327A + A0 * 30] = h(S0);
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
reset_window
if (A0 == 1)
{
    [8008327A + A0 * 30] = h(08); // WINDOW y.
}
else
{
    [8008327A + A0 * 30] = h(95); // WINDOW y.
}

[80083278 + A0 * 30] = h(08);  // WINDOW x.
[8008327C + A0 * 30] = h(130); // WINDOW width.
[8008327E + A0 * 30] = h(49);  // WINDOW height.
[80083280 + A0 * 30] = h(1);   // WINDOW current width.
[80083282 + A0 * 30] = h(1);   // WINDOW current height.
[800832A0 + A0 * 30] = h(0);   // window state.
[8008328D + A0 * 30] = b(0);   // WMODE style.
[8008328F + A0 * 30] = b(0);   // WSPCL type.
[80083290 + A0 * 30] = b(0);   // ???????????????????????????????
[80083291 + A0 * 30] = b(6);   // WNUMB number of digits in number.
[8008329C + A0 * 30] = h(0);   // WSPCL x.
[8008329E + A0 * 30] = h(0);   // WSPCL y.
[800832A2 + A0 * 30] = h(0);   // WMODE cbc.
[8008326C + A0] = b(FF);       // windows parent entity.

A1 = 800E4214 + A0 * 8;        // memory bank array for getting variable for windows.
A2 = 800E4D48 + A0 * 10;       // offsets for getting variable from memory block for windows.
A3 = 0;

loopd4abc:	; 800D4ABC
{
    [A1] = b(0);
    [A2] = h(0);
    A2 = A2 + 2;
    A3 = A3 + 1;
    A1 = A1 + 1;

    V0 = A3 < 8;

    800D4AD0	bne    v0, zero, loopd4abc [$800d4abc]

}

[8011445C + A0 * 2] = h(0); // time to wait for windows.
////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// set_window_height

[8008327e + A0 * 30] = h(A1);
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
//play_window_pointer_click_sound
clear_akao;

[8009a000] = h(0030);
[8009a004] = h(0001);
[8009a008] = h(0040);

system_execute_AKAO;
/////////////////////////////////////////////////////////