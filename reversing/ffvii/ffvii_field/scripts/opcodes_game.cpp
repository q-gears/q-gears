////////////////////////////////
// 0x22 BTMD2
A0 = bu[800722C4];
V1 = w[8009C6DC];
V0 = hu[800831fc + A0 * 2];
A1 = w[8009c6e0];
[A1 + 3e] = h(hu[V1 + V0 + 1]);
[A1 + 3d] = b(bu[V1 + V0 + 3]);

move script pointer by 5;
return 0;
////////////////////////////////



////////////////////////////////
// 0x23 BTRLD
A0 = 2;
A1 = 2;
A2 = h[800707be];
store_memory_block_two_bytes;

move script pointer by 3;

return 0;
////////////////////////////////



////////////////////////////////
// 0x4B BTLTB
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
V0 = bu[V0 + V1 + 1];

V1 = w[8009c6e0];
[V1 + 3c] = b(V0);

move script pointer by 2;

return 0;
////////////////////////////////



////////////////////////////////
// 0x70 BATTLE
A0 = w[8009c6e0];
V1 = bu[A0 + 1];

if (V1 == 0)
{
    funcd4bfc

    [A0 + 01] = b(2);
    [A0 + 26] = h(0);

    A0 = 2;
    A1 = 2;
    read_memory_block_two_bytes
    [A0 + 02] = h(V0)
}
else if (V1 == 2)
{
    V0 = h[A0 + 26];
    if (V0 == 2)
    {
        [A0 + 01] = b(0);
        [A0 + 26] = h(0);

        move script pointer by 4;
        return 0;
    }
}

return 1;
////////////////////////////////



////////////////////////////////
// 0x71 BTLON
V0 = bu[800722C4];
V1 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
V0 = bu[V0 + V1 + 1];

V1 = w[8009c6e0];
[V1 + 3b] = b(V0);

move script pointer by 2;

return 0;
////////////////////////////////



////////////////////////////////
// 0x72 BTLMD
A0 = bu[800722c4];
V1 = w[8009c6dc];
V0 = hu[800831fc + A0 * 2];
A1 = w[8009c6e0];
[A1 + 3e] = h(bu[V1 + V0 + 1]);
[A1 + 3d] = b(bu[V1 + V0 + 2]);

move script pointer by 3;
return 0;
////////////////////////////////



////////////////////////////////
// 0xFF GAMEOVER
V0 = w[8009c6e0];
[V0 +  1] = b(1a);
[V0 + 26] = h(0);
return 1;
////////////////////////////////
