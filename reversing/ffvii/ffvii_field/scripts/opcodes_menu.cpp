////////////////////////////////
// 0x49 MENU
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

A0 = bu[struct + 1];
if (A0 == 0)
{
    [struct + 1] = b(bu[script + 2]);

    A0 = 2;
    A1 = 3;
    read_memory_block_one_byte;

    [struct + 2] = h(V0);

    [8007ebe0] = b(1);


    [struct + 26] = h(0);

    if ((w[struct + 0] & ffffff00) != 900)
    {
        return 1;
    }

    [800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 4);
    return 1;
}
else
{
    if (A0 == bu[script + 2])
    {
        if (h[struct + 26] != 2)
        {
            return 1;
        }

        [800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 4);
        [struct + 1] = b(0);
        [struct + 26] = h(0);

        funccf60c;

        return 0;
    }

    if (bu[script + 2] == 14)
    {
        if (A0 == 4)
        {
            [struct + 1] = b(bu[A1 + 2]);
            [struct + 26] = h(0);
        }
    }
    return 1;
}
////////////////////////////////



////////////////////////////////
// 0x4A MENU2
800D2E94	lui    v0, $800a
800D2E98	lbu    v0, $d820(v0)
800D2E9C	addiu  sp, sp, $ffe0 (=-$20)
800D2EA0	andi   v0, v0, $0003
800D2EA4	beq    v0, zero, Ld2ebc [$800d2ebc]
800D2EA8	sw     ra, $0018(sp)
800D2EAC	lui    a0, $800a
800D2EB0	addiu  a0, a0, $0f38
800D2EB4	jal    funcbead4 [$800bead4]
800D2EB8	ori    a1, zero, $0001

Ld2ebc:	; 800D2EBC
800D2EBC	lui    v0, $8007
800D2EC0	lbu    v0, $22c4(v0)
800D2EC4	nop
800D2EC8	sll    v0, v0, $01
800D2ECC	lui    at, $8008
800D2ED0	addiu  at, at, $31fc
800D2ED4	addu   at, at, v0
800D2ED8	lhu    v1, $0000(at)
800D2EDC	lui    v0, $800a
800D2EE0	lw     v0, $c6dc(v0)
800D2EE4	nop
800D2EE8	addu   v0, v0, v1
800D2EEC	lui    v1, $800a
800D2EF0	lw     v1, $c6e0(v1)
800D2EF4	lbu    v0, $0001(v0)
800D2EF8	nop
800D2EFC	sb     v0, $0034(v1)
800D2F00	lui    v1, $8007
800D2F04	lbu    v1, $22c4(v1)
800D2F08	lui    v0, $8008
800D2F0C	addiu  v0, v0, $31fc
800D2F10	sll    v1, v1, $01
800D2F14	addu   v1, v1, v0
800D2F18	lhu    v0, $0000(v1)
800D2F1C	nop
800D2F20	addiu  v0, v0, $0002
800D2F24	sh     v0, $0000(v1)
800D2F28	addu   v0, zero, zero
800D2F2C	lw     ra, $0018(sp)
800D2F30	addiu  sp, sp, $0020
800D2F34	jr     ra 
800D2F38	nop
////////////////////////////////



////////////////////////////////
// funccf60c
800CF614	lui    s0, $800a
800CF618	addiu  s0, s0, $d391 (=-$2c6f)
800CF61C	addu   a0, s0, zero
800CF620	addiu  a1, s0, $f84b (=-$7b5)
800CF628	addiu  s1, sp, $0018
800CF62C	addiu  a2, sp, $0010
800CF634	jal    funccf4cc [$800cf4cc]
800CF638	addu   a3, s1, zero
800CF63C	addu   a0, s0, zero
800CF640	jal    funccf66c [$800cf66c]
800CF644	addu   a1, s1, zero
800CF648	addu   a0, s0, zero
800CF650	addiu  a1, sp, $0010
800CF64C	jal    funccf6c0 [$800cf6c0]
////////////////////////////////