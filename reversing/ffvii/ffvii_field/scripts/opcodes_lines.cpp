////////////////////////////////
// 0x2B SLIP
V0 = bu[800722C4];
A1 = bu[8007078C + V0];
A0 = hu[800831FC + V0 * 2];
V0 = w[8009C6DC];
V0 = bu[V0 + A0 + 1];

[8007E7AC + A1 * 18 + 16] = b[V0];

// move pointer by 2
V1 = bu[800722C4];
V0 = hu[800831FC + V1 * 2];
V0 = V0 + 2;
[800831FC + V1 * 2] = h(V0);

return 0;
////////////////////////////////



////////////////////////////////
// 0xD0 LINE
V0 = h[80095D84];
if (V0 < 20)
{
    current_entity = bu[800722C4];
    V0 = bu[80095D84];
    A3 = 800831FC;
    [8007078C + current_entity] = b(V0);
    A2 = w[8009C6DC];
    A1 = 800831FC + current_entity * 2;

    // x1
    V0 = hu[A1];
    V0 = A2 + V0;
    V1 = bu[V0 + 2];
    T0 = bu[V0 + 1];
    V0 = h[80095D84];
    V1 = V1 << 8;
    T0 = T0 | V1;
    A0 = V0 * 18;
    [8007E7AC + V0 * 18] = h(T0);

    // y1
    V0 = hu[A1];
    V0 = A2 + V0;
    V1 = bu[V0 + 4];
    T0 = bu[V0 + 3];
    V1 = V1 << 8;
    T0 = T0 | V1;
    [8007E7AC + A0 + 2] = h(T0);

    // z1
    V0 = hu[A1];
    V0 = A2 + V0;
    V1 = bu[V0 + 6];
    T0 = bu[V0 + 5];
    V1 = V1 << 8;
    T0 = T0 | V1;
    [8007E7AC + A0 + 4] = h(T0);

    // x2
    V0 = hu[A1];
    V0 = A2 + V0;
    V1 = bu[V0 + 8];
    T0 = bu[V0 + 7];
    V1 = V1 << 8;
    T0 = T0 | V1;
    [8007E7AC + A0 + 6] = h(T0);

    // y2
    V0 = hu[A1];
    V0 = A2 + V0;
    V1 = bu[V0 + A];
    T0 = bu[V0 + 9];
    V1 = V1 << 8;
    T0 = T0 | V1;
    [8007E7AC + A0 + 8] = h(T0);

    // z2
    V0 = hu[A1];
    V0 = A2 + V0;
    V1 = bu[V0 + C];
    T0 = bu[V0 + B];
    V1 = V1 << 8;
    T0 = T0 | V1;
    [8007E7AC + A0 + A] = h(T0);

    [8007E7AC + A0 + C] = b(1);
    A1 = h[80095D84];
    V1 = bu[800722C4];
    [8007E7AC + A1 * 18 + D] = b(V1);

    A1 = bu[800722C4];
    A0 = hu[A1 * 2 + A3];
    A0 = A0 + D;
    [A1 * 2 + A3] = h(A0);

    V1 = hu[80095D84];
    V1 = V1 + 1;
    [80095D84] = h(V1);
}
else
{
    A0 = 800A0618;
    funcd4848;

    800C1A84	lui    v0, $8008
    800C1A88	addiu  v0, v0, $31fc
    800C1A8C	sll    v1, current_entity, $01
    800C1A90	addu   v1, v1, v0
    800C1A94	lhu    a0, $0000(v1)
    800C1A9C	addiu  a0, a0, $000d
    800C1AA0	sh     a0, $0000(v1)
}
Lc1aa4:	; 800C1AA4
return 0;
////////////////////////////////



////////////////////////////////
// 0xD1 LINON
current_entity = bu[800722C4];

A1 = bu[8007078C + current_entity];
A0 = hu[800831FC + current_entity * 2];
V0 = w[8009C6DC];
line_on = bu[V0 + A0 + 1];
[8007E7AC + A1 * 18 + C] = b(line_on);

if (line_on == 0)
{
    V1 = bu[8007078C + A1];
    [8007E7AC + V1 * 18 + E] = b(0);
}

move script pointer by 2;

return 0;
////////////////////////////////



////////////////////////////////
// 0xD3 SLINE
800C1AE4	ori    a0, zero, $0001
800C1AE8	lui    v0, $8007
800C1AEC	lbu    v0, $22c4(v0)
800C1AF0	nop
800C1AF4	lui    at, $8007
800C1AF8	addiu  at, at, $078c
800C1AFC	addu   at, at, v0
800C1B00	lbu    s1, $0000(at)
800C1B04	jal    read_memory_block_two_bytes [$800bf908]
800C1B08	ori    a1, zero, $0004
800C1B0C	ori    a0, zero, $0002
800C1B10	sll    s0, s1, $01
800C1B14	addu   s0, s0, s1
800C1B18	sll    s0, s0, $03
800C1B1C	lui    at, $8008
800C1B20	addiu  at, at, $e7ac (=-$1854)
800C1B24	addu   at, at, s0
800C1B28	sh     v0, $0000(at)
800C1B2C	jal    read_memory_block_two_bytes [$800bf908]
800C1B30	ori    a1, zero, $0006
800C1B34	ori    a0, zero, $0003
800C1B38	lui    at, $8008
800C1B3C	addiu  at, at, $e7ae (=-$1852)
800C1B40	addu   at, at, s0
800C1B44	sh     v0, $0000(at)
800C1B48	jal    read_memory_block_two_bytes [$800bf908]
800C1B4C	ori    a1, zero, $0008
800C1B50	ori    a0, zero, $0004
800C1B54	lui    at, $8008
800C1B58	addiu  at, at, $e7b0 (=-$1850)
800C1B5C	addu   at, at, s0
800C1B60	sh     v0, $0000(at)
800C1B64	jal    read_memory_block_two_bytes [$800bf908]
800C1B68	ori    a1, zero, $000a
800C1B6C	ori    a0, zero, $0005
800C1B70	lui    at, $8008
800C1B74	addiu  at, at, $e7b2 (=-$184e)
800C1B78	addu   at, at, s0
800C1B7C	sh     v0, $0000(at)
800C1B80	jal    read_memory_block_two_bytes [$800bf908]
800C1B84	ori    a1, zero, $000c
800C1B88	ori    a0, zero, $0006
800C1B8C	lui    at, $8008
800C1B90	addiu  at, at, $e7b4 (=-$184c)
800C1B94	addu   at, at, s0
800C1B98	sh     v0, $0000(at)
800C1B9C	jal    read_memory_block_two_bytes [$800bf908]
800C1BA0	ori    a1, zero, $000e
800C1BA4	lui    a0, $8007
800C1BA8	lbu    a0, $22c4(a0)
800C1BAC	lui    at, $8008
800C1BB0	addiu  at, at, $e7b6 (=-$184a)
800C1BB4	addu   at, at, s0
800C1BB8	sh     v0, $0000(at)
800C1BBC	lui    v0, $8008
800C1BC0	addiu  v0, v0, $31fc
800C1BC4	sll    a0, a0, $01
800C1BC8	addu   a0, a0, v0
800C1BCC	lhu    v1, $0000(a0)
800C1BD0	addu   v0, zero, zero
800C1BD4	addiu  v1, v1, $0010
800C1BD8	sh     v1, $0000(a0)
////////////////////////////////