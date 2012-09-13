////////////////////////////////
// 0x69 MPDSP
struct = w[8009c6e0];
current_entity            = bu[800722c4];
current_script_pointer    = 800831fc + current_entity * 2;
field_file_offset         = w[8009c6dc];

argument1 = hu[current_script_pointer + 0];

[struct + 38] = b(bu[current_entity + argument1 + 1]);

// move pointer by 9
[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 2);
////////////////////////////////



////////////////////////////////
// 0x6B FADE

v0 = [param + 07];
[gamedata + 4C] = v0;

switch (v0)
{
    case 1, 5, 7, 9:
    {
        v0 = [param + 08];
        v0 = v0 + 1;
        [gamedata + 4E] = v0;
    }
    break;

    case 2, 6, 8, A:
    {
        v0 = [param + 08];
        [gamedata + 4E] = v0;
    }
    break;
}

[gamedata + 50] = [param + 06];

a0 = 1;
a1 = 3;
read_memory_block_one_byte
[gamedata + 52] = v0 & FF;

a0 = 2;
a1 = 4;
read_memory_block_one_byte
[gamedata + 54] = v0 & FF;

a0 = 4;
a1 = 5;
read_memory_block_one_byte
[gamedata + 56] = v0 & FF;

move script pointer by 0x9
////////////////////////////////



////////////////////////////////
// 0x25 NFADE

v0 = [param + 03];
[gamedata + 4C] = v0;

a0 = 1;
a1 = 4;
read_memory_block_one_byte
v0 = v0 & FF;
[gamedata + 5E] = v0;

a0 = 2;
a1 = 5;
read_memory_block_one_byte
v0 = v0 & FF;
[gamedata + 60] = v0;

a0 = 3;
a1 = 6;
read_memory_block_one_byte
v0 = v0 & FF;
[gamedata + 62] = v0;

a0 = 4;
a1 = 7;
read_memory_block_one_byte
[gamedata + 50] = v0 & FF;

[gamedata + 4E] = 0;

v0 = 0;

move script pointer by 0x9
////////////////////////////////



////////////////////////////////
// 0x6C FADEW
struct = w[8009c6e0];
V0 = hu[struct + 4c];

if (V0 == 1 || V0 == 5 || V0 == 7 || V0 == 9)
{
    800D19C8	lui    v0, $800a
    800D19CC	lw     v0, $c6e0(v0)
    800D19D0	nop
    800D19D4	lhu    v0, $004e(v0)
    800D19D8	nop
    800D19DC	beq    v0, zero, Ld1a48 [$800d1a48]

    return 1;
}
else if (V0 == 2 || V0 == 6 || V0 == 8 || V0 == a)
{
    800D19EC	lui    v0, $800a
    800D19F0	lw     v0, $c6e0(v0)
    800D19F4	nop
    800D19F8	lhu    v0, $004e(v0)
    800D19FC	nop
    800D1A08	slti   v0, v0, $00ff
    800D1A0C	beq    v0, zero, Ld1a48 [$800d1a48]

    return 1;
}
else if (V0 == 0 || V0 == 4)
{
    Ld1a48:	; 800D1A48
    800D1A48	lui    v1, $8007
    800D1A4C	lbu    v1, $22c4(v1)
    800D1A50	lui    v0, $8008
    800D1A54	addiu  v0, v0, $31fc
    800D1A58	sll    v1, v1, $01
    800D1A5C	addu   v1, v1, v0
    800D1A60	lhu    a0, $0000(v1)
    800D1A64	addu   v0, zero, zero
    800D1A68	addiu  a0, a0, $0001
    800D1A6C	sh     a0, $0000(v1)
}

Ld1a70:	; 800D1A70
return;
////////////////////////////////