////////////////////////////////////////////////////////
// 0xDA AKAO2
clear_akao;

V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];

[8009a000] = h(bu[V0 + V1 + 4]);

A0 = 1;
A1 = 5;
read_memory_block_two_bytes;
[8009a004] = w(V0);

A0 = 2;
A1 = 7;
read_memory_block_two_bytes;
[8009a008] = w(V0);

A0 = 3;
A1 = 9;
read_memory_block_two_bytes;
[8009a00c] = w(V0);

A0 = 4;
A1 = b;
read_memory_block_two_bytes;
[8009a010] = w(V0);

A0 = 6;
A1 = d;
read_memory_block_two_bytes;
[8009a014] = w(V0);

system_execute_AKAO;

// move pointer by F
A0 = bu[800722c4];
[800831fc + A0 * 2] = h(hu[800831fc + A0 * 2] + f);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xF0 MUSIC
clear_akao;

[8009a000] = h(10);

set_and_apply_field_music_params;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xF1 SOUND
clear_akao;

[8009a000] = h(20);

A0 = 2;
A1 = 4;
read_memory_block_one_byte;
[8009a004] = w(V0);

A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
[8009a008] = w(V0);

system_execute_AKAO;

// move pointer by 5
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 5;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xF2 AKAO
clear_akao;

V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];
V0 = bu[V0 + V1 + 4];
[8009a000] = h(V0);

A0 = 1;
A1 = 5;
read_memory_block_one_byte;
[8009a004] = w(V0);

A0 = 2;
A1 = 6;
read_memory_block_two_bytes;
[8009a008] = w(V0);

A0 = 3;
A1 = 8;
read_memory_block_two_bytes;
[8009a00c] = w(V0);

A0 = 4;
A1 = a;
read_memory_block_two_bytes;
[8009a010] = w(V0);

A0 = 6;
A1 = c;
read_memory_block_two_bytes;
[8009a014] = w(V0);

system_execute_AKAO;

// move pointer by E
A0 = bu[800722c4];
[800831fc + A0 * 2] = h(hu[800831fc + A0 * 2] + e);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xF3 MUSVT
clear_akao;

[8009a000] = h(14);

set_and_apply_field_music_params;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xF4 MUSVM
clear_akao;

[8009A000] = h(15);

set_and_apply_field_music_params;

return V0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xF5 MULCK
A0 = bu[800722c4];
V1 = hu[800831fc + A0 * 2];
V0 = w[8009c6dc];
V0 = bu[V0 + V1 + 1];
[800716d4] = b(V0);
[800831fc + A0 * 2] = h(V1 + 2);
return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xF6 BMUSC
V0 = b[800716D4];

if (V0 == 0)
{
    V0 = bu[800722C4];
    V1 = hu[800831FC + V0 * 2];
    V0 = w[8009C6DC];
    S0 = bu[V0 + V1 + 1];

    A0 = S0;
    A1 = S0;
    get_akao_offset_in_field;

    V1 = w[8009C6DC];
    V0 = V0 + V1;

    A0 = w[8009C6E0];
    [A0 + 44] = w(V0);
}
else
{
    A0 = w[8009C6E0];
    [A0 + 44] = w(0);
}

// move pointer by 2
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 2;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////
// 0xF7 CHMPH
A0 = 1;
A1 = 2;
A2 = h[8009a104 + 5e];
store_memory_block_two_bytes;

A0 = 2;
A1 = 3;
A2 = bu[8009a104 + 58];
store_memory_block_one_byte;

// move pointer by 4
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 4;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xFC FMUSC
V0 = b[800716D4];

if (V0 == 0)
{
    V0 = bu[800722C4];
    V1 = hu[800831FC + V0 * 2];
    V0 = w[8009C6DC];
    S0 = bu[V0 + V1 + 1];

    A0 = S0;
    A1 = S0;
    get_akao_offset_in_field;

    V1 = w[8009C6DC];
    V0 = V0 + V1;

    A0 = w[8009C6E0];
    [A0 + 48] = w(V0);
}
else
{
    A0 = w[8009C6E0];
    [A0 + 48] = w(0);
}

// move pointer by 2
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 2;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xFD CMUSC
clear_akao;

V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
V0 = bu[V0 + V1 + 3];
[8009a000] = h(V0);

A0 = 3;
A1 = 4;
read_memory_block_two_bytes;
[8009a008] = w(V0);

A0 = 4;
A1 = 6;
read_memory_block_two_bytes;
[8009a00c] = w(V0);

set_and_apply_field_music_params;

// move pointer by 6
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 6;
[800831FC + A0 * 2] = h(V1);
////////////////////////////////////////////////////////



////////////////////////////////////////////////////
// 0xFE CHMST
V0 = ;
V1 = w[8009a108] > 0;

if (w[80099fcc] != 0)
{
    A2 = V1 | 2;
}
else
{
    A2 = V1;
}

A0 = 2;
A1 = 2;
store_memory_block_one_byte;

// move pointer by 3
A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + 3;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// clear_akao
[8009a000] = h(0);

V0 = 8009a018;
V1 = 5;
loopc46b8:	; 800C46B8
    [V0] = w(0);
    V1 = V1 - 1;
    V0 = V0 - 4;
800C46C0	bgez   v1, loopc46b8 [$800c46b8]

return;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// set_and_apply_field_music_params
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

if (b[800716d4] == 0) // if music not locked
{
    S0 = bu[script + 1];

    A0 = S0;
    A1 = S0;
    get_akao_offset_in_field;

    V0 = w[8009c6dc] + V0;
    [8009a004] = w(V0);
    [struct + 48] = w(V0);

    system_execute_AKAO;
}

// move pointer by 2
[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 2);
return 0;
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// get_akao_offset_in_field
field_file_offset = w[8009C6DC];
number_of_entity = bu[field_file_offset + 2];
music_offset = field_file_offset + number_of_entity * 8 + 20;

x1 = bu[music_offset + A0 * 4 + 0];
x2 = bu[music_offset + A0 * 4 + 1];
x3 = bu[music_offset + A0 * 4 + 2];
x4 = bu[music_offset + A0 * 4 + 3];
V0 = x1 | (x2 << 08) | (x3 << 10) | (x4 << 18);
return V0;
////////////////////////////////////////////////////////