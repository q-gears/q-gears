////////////////////////////////
// 0x27 BGMOVIE
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

[struct + 3a] = b(bu[script + 1]);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 2);

return 0;
////////////////////////////////



////////////////////////////////
// 0x2C BGPDH
// set depth to layers 2 and 3
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];
V1 = bu[script + 2];

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;

if (V1 == 2)
{
    [struct + b0] = h(V0);
}
else if (V1 == 3)
{
    [struct + ae] = h(V0);
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 5);

return 0
////////////////////////////////



////////////////////////////////
// 0x2D BGSCR
// set position for layers 2 and 3
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];
V1 = bu[script + 2];

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
param1 = V0;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
param2 = V0;

if (V1 == 2)
{
    [struct + a6] = h(param1);
    [struct + a8] = h(param2);
}
else if (V1 == 3)
{
    [struct + aa] = h(param1);
    [struct + ac] = h(param2);
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 7);

return 0;
////////////////////////////////



////////////////////////////////
// 0x5E SHAKE
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];
S0 = bu[script + 3];

if (S0 & 1)
{
    [struct + 8a] = b(1);

    A0 = 1;
    A1 = 4;
    read_memory_block_one_byte;
    [struct + 8e] = h(V0);

    A0 = 2;
    A1 = 5;
    read_memory_block_one_byte;
    [struct + 94] = h(V0);
}
else
{
    [struct + 8a] = b(0);
}

if (S0 & 2)
{
    [struct + 98] = b(1);

    A0 = 3;
    A1 = 6;
    read_memory_block_one_byte;
    [struct + 9c] = h(V0);

    A0 = 4;
    A1 = 7;
    read_memory_block_one_byte;
    [struct + a2] = h(V0);
}
else
{
    [struct + 98] = b(0);
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 8);

return 0;
////////////////////////////////



////////////////////////////////
// 0x61 SCRLO
// scroll lock
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

[struct + 37] = b(bu[script + 1]);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 2);

return 0;
////////////////////////////////



////////////////////////////////
// 0x62 SCRLC
// scroll to playable character with specified type.
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

[struct + 1d] = b(bu[script + 4]);
[struct + 1f] = b(0);
[struct + 1e] = b(bu[struct + 2a]); // manual entity id

A0 = 2;
A1 = 2;
read_memory_block_two_bytes;
[struct + 20] = b(V0);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 5);

return 0;
////////////////////////////////



////////////////////////////////
// 0x63 SCRLA
// scroll to entity with specified type.
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

A1 = bu[script + 4];
A1 = bu[8007eb98 + A1];

if (A1 != ff)
{
    [struct + 1d] = b(bu[script + 5]);
    [struct + 1e] = b(A1);
    [struct + 1f] = b(0);

    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;
    [struct + 20] = h(V0);
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 6);

return 0;
////////////////////////////////



////////////////////////////////
// 0x64 SCR2D
// scroll to coordinates (type instant)
struct = w[8009c6e0];
current_entity = bu[800722c4];

[struct + 1d] = b(4);
[struct + 1f] = b(0);

A0 = 1;
A1 = 2;
read_memory_block_two_bytes;
[struct + 0a] = h(V0);

A0 = 2;
A1 = 4;
read_memory_block_two_bytes;
[struct + 0c] = h(V0);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 6);

return 0;
////////////////////////////////



////////////////////////////////
// 0x65 SCRCC
// auto scroll to pc.
struct = w[8009c6e0];
current_entity = bu[800722c4];

[struct + 1d] = b(0);
[struct + 1e] = b(bu[struct + 2a]); // manual model id
[struct + 1f] = b(0);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 1);

return 0;
////////////////////////////////



////////////////////////////////
// 0x66 SCR2DC
// scroll to coordinates (type smooth).
struct = w[8009c6e0];
current_entity = bu[800722c4];

[struct + 1d] = b(6);
[struct + 1f] = b(0);

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
[struct + 0a] = h(V0);

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
[struct + 0c] = h(V0);

A0 = 4;
A1 = 7;
read_memory_block_two_bytes;
[struct + 20] = h(V0);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 9);

return 0;
////////////////////////////////



////////////////////////////////
// 0x67 SCRLW
// wait for scroll
struct = w[8009c6e0];
current_entity = bu[800722c4];

if (bu[struct + 1f] != 2)
{
    return 1;
}

V1 = bu[struct + 1d];
if (V1 == 1 || V1 == 2 || V1 == 3)
{
    [struct + 1d] = b(1);
}
else if (V1 == 5 || V1 == 6)
{
    [struct + 1d] = b(4);
}

[struct + 1f] = b(0);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 1);

return 0;
////////////////////////////////



////////////////////////////////
// 0x68 SCR2DL
// scroll to coordinates (type linear)
struct = w[8009c6e0];
current_entity = bu[800722c4];

[struct + 1d] = b(5);
[struct + 1f] = b(0);

A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
[struct + 0a] = h(V0);

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
[struct + 0c] = h(V0);

A0 = 4;
A1 = 7;
read_memory_block_two_bytes;
[struct + 20] = h(V0);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 9);

return 0;
////////////////////////////////



////////////////////////////////
// 0x6A VWOFT
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

byte6 = bu[script + 6];

if (byte6 != 0)
{
    A0 = 1;
    A1 = 2;
    read_memory_block_two_bytes;
    [struct + 1a] = h(V0);

    [struct + 18] = h(h[struct + 16]);

    A0 = 2;
    A1 = 4;
    read_memory_block_two_bytes;
    [struct + 12] = b(V0);

    [struct + 13] = b(0);
    [struct + 14] = b(byte6);
}
else
{
    A0 = 1;
    A1 = 2;
    read_memory_block_two_bytes;

    [struct + 12] = b(0);
    [struct + 13] = b(0);
    [struct + 14] = b(0);
    [struct + 16] = h(V0);
    [struct + 18] = h(0);
    [struct + 1a] = h(0);
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 7);

return 0;
////////////////////////////////



////////////////////////////////
// 0x6F SCRLP
// scroll to party member with specified type
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

V0 = bu[script + 4];
V1 = bu[8009d391 + V0];

if (V1 != ff)
{
    V0 = bu[8009ad30 + V1];
}
else
{
    V0 = ff;
}

A1 = bu[8007eb98 + V0];
if (A1 != ff)
{
    [struct + 1d] = b(bu[script + 5]);
    [struct + 1e] = b(A1);
    [struct + 1f] = b(0);

    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes;
    [struct + 20] = h(V0);
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 6);

return 0;
////////////////////////////////



////////////////////////////////
// E0 BGON
struct = w[8009c6e0];
current_entity = bu[800722c4];

A0 = 1;
A1 = 2;
read_memory_block_one_byte;
group_id = V0;

A0 = 2;
A1 = 3;
read_memory_block_one_byte;
index_id = V0;

[struct + f2 + group_id] = b(bu[struct + f2 + group_id] | (1 << index_id));

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 4);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE1 BGOFF
struct = w[8009c6e0];
current_entity = bu[800722c4];

A0 = 1;
A1 = 2;
read_memory_block_one_byte;
group_id = V0;

A0 = 2;
A1 = 3;
read_memory_block_one_byte;
index_id = V0;

[struct + f2 + group_id] = b(bu[struct + f2 + group_id] | (0 NOR (1 << index_id)));

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 4);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE2 BGROL
struct = w[8009c6e0];
current_entity = bu[800722c4];

A0 = 2;
A1 = 2;
read_memory_block_one_byte

[struct + f2 + group_id] = b(bu[struct + f2 + group_id] << 1);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 3);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE3 BGROL2
struct = w[8009c6e0];
current_entity = bu[800722c4];

A0 = 2;
A1 = 2;
read_memory_block_one_byte;

[struct + f2 + group_id] = b(bu[struct + f2 + group_id] >> 1);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 3);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE4 BGCLR
struct = w[8009c6e0];
current_entity = bu[800722c4];

A0 = 2;
A1 = 2;
read_memory_block_one_byte
group_id = V0;

[struct + f2 + group_id] = b(0);

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 3);

return 0;
////////////////////////////////