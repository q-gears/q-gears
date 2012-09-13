////////////////////////////////
// 0x0E DSKCG
800C523C	lui    v0, $800a
800C5240	lbu    v0, $d820(v0)
800C5244	addiu  sp, sp, $ffe8 (=-$18)
800C5248	andi   v0, v0, $0003
800C524C	beq    v0, zero, Lc5264 [$800c5264]
800C5250	sw     ra, $0010(sp)
800C5254	lui    a0, $800a
800C5258	addiu  a0, a0, $08f4
800C525C	jal    funcbead4 [$800bead4]
800C5260	ori    a1, zero, $0001

Lc5264:	; 800C5264
800C5264	lui    a0, $800a
800C5268	lw     a0, $c6e0(a0)
800C526C	nop
800C5270	lbu    v1, $0001(a0)
800C5274	nop
800C5278	beq    v1, zero, Lc5294 [$800c5294]
800C527C	ori    v0, zero, $000d
800C5280	ori    v0, zero, $000d
800C5284	beq    v1, v0, Lc52e0 [$800c52e0]
800C5288	ori    v0, zero, $0002
800C528C	j      Lc531c [$800c531c]
800C5290	ori    v0, zero, $0001

Lc5294:	; 800C5294
800C5294	sb     v0, $0001(a0)
800C5298	lui    v0, $8007
800C529C	lbu    v0, $22c4(v0)
800C52A0	nop
800C52A4	sll    v0, v0, $01
800C52A8	lui    at, $8008
800C52AC	addiu  at, at, $31fc
800C52B0	addu   at, at, v0
800C52B4	lhu    v1, $0000(at)
800C52B8	lui    v0, $800a
800C52BC	lw     v0, $c6dc(v0)
800C52C0	nop
800C52C4	addu   v0, v0, v1
800C52C8	lbu    v1, $0001(v0)
800C52CC	nop
800C52D0	lui    at, $800a
800C52D4	sb     v1, $d588(at)
800C52D8	j      Lc531c [$800c531c]
800C52DC	ori    v0, zero, $0001

Lc52e0:	; 800C52E0
800C52E0	lh     v1, $0026(a0)
800C52E4	nop
800C52E8	bne    v1, v0, Lc531c [$800c531c]
800C52EC	ori    v0, zero, $0001
800C52F0	sb     zero, $0001(a0)
800C52F4	lui    v1, $8007
800C52F8	lbu    v1, $22c4(v1)
800C52FC	lui    v0, $8008
800C5300	addiu  v0, v0, $31fc
800C5304	sll    v1, v1, $01
800C5308	addu   v1, v1, v0
800C530C	lhu    a0, $0000(v1)
800C5310	addu   v0, zero, zero
800C5314	addiu  a0, a0, $0002
800C5318	sh     a0, $0000(v1)

Lc531c:	; 800C531C
800C531C	lw     ra, $0010(sp)
800C5320	addiu  sp, sp, $0018
800C5324	jr     ra 
800C5328	nop
////////////////////////////////



////////////////////////////////
// 0x20 MINIGAME
800C43EC	lui    a1, $800a
800C43F0	lw     a1, $c6e0(a1)
800C43F4	nop
800C43F8	lbu    v1, $0001(a1)
800C43FC	nop
800C4400	beq    v1, zero, Lc4418 [$800c4418]
800C4404	ori    v0, zero, $000c
800C4408	beq    v1, v0, Lc4560 [$800c4560]
800C440C	ori    v0, zero, $0002
800C4410	j      Lc459c [$800c459c]
800C4414	ori    v0, zero, $0001

Lc4418:	; 800C4418
800C4418	ori    v0, zero, $000c
800C441C	sb     v0, $0001(a1)
800C4420	lui    v0, $8008
800C4424	addiu  v0, v0, $31fc
800C4428	lui    a2, $800a
800C442C	lw     a2, $c6e0(a2)
800C4430	lui    a0, $8007
800C4434	lbu    a0, $22c4(a0)
800C4438	lui    a1, $800a
800C443C	lw     a1, $c6dc(a1)
800C4440	sll    a0, a0, $01
800C4444	addu   a0, a0, v0
800C4448	sh     zero, $0026(a2)
800C444C	lhu    v0, $0000(a0)
800C4450	nop
800C4454	addu   v0, a1, v0
800C4458	lbu    v1, $0001(v0)
800C445C	nop
800C4460	sh     v1, $0002(a2)
800C4464	lhu    v0, $0000(a0)
800C4468	nop
800C446C	addu   v0, a1, v0
800C4470	lbu    v0, $0002(v0)
800C4474	nop
800C4478	sll    v0, v0, $08
800C447C	or     v1, v1, v0
800C4480	sh     v1, $0002(a2)
800C4484	lhu    v0, $0000(a0)
800C4488	nop
800C448C	addu   v0, a1, v0
800C4490	lbu    v1, $0003(v0)
800C4494	nop
800C4498	sh     v1, $0004(a2)
800C449C	lhu    v0, $0000(a0)
800C44A0	nop
800C44A4	addu   v0, a1, v0
800C44A8	lbu    v0, $0004(v0)
800C44AC	nop
800C44B0	sll    v0, v0, $08
800C44B4	or     v1, v1, v0
800C44B8	sh     v1, $0004(a2)
800C44BC	lhu    v0, $0000(a0)
800C44C0	nop
800C44C4	addu   v0, a1, v0
800C44C8	lbu    v1, $0005(v0)
800C44CC	nop
800C44D0	sh     v1, $0006(a2)
800C44D4	lhu    v0, $0000(a0)
800C44D8	nop
800C44DC	addu   v0, a1, v0
800C44E0	lbu    v0, $0006(v0)
800C44E4	nop
800C44E8	sll    v0, v0, $08
800C44EC	or     v1, v1, v0
800C44F0	sh     v1, $0006(a2)
800C44F4	lhu    v0, $0000(a0)
800C44F8	nop
800C44FC	addu   v0, a1, v0
800C4500	lbu    v1, $0007(v0)
800C4504	nop
800C4508	sh     v1, $0022(a2)
800C450C	lhu    v0, $0000(a0)
800C4510	nop
800C4514	addu   v0, a1, v0
800C4518	lbu    v0, $0008(v0)
800C451C	nop
800C4520	sll    v0, v0, $08
800C4524	or     v1, v1, v0
800C4528	sh     v1, $0022(a2)
800C452C	lhu    v0, $0000(a0)
800C4530	nop
800C4534	addu   v0, a1, v0
800C4538	lbu    v0, $0009(v0)
800C453C	nop
800C4540	sh     v0, $0024(a2)
800C4544	lhu    v0, $0000(a0)
800C4548	nop
800C454C	addu   a1, a1, v0
800C4550	lbu    v1, $000a(a1)
800C4554	ori    v0, zero, $0001
800C4558	j      Lc459c [$800c459c]
800C455C	sb     v1, $00f2(a2)

Lc4560:	; 800C4560
800C4560	lh     v1, $0026(a1)
800C4564	nop
800C4568	bne    v1, v0, Lc459c [$800c459c]
800C456C	ori    v0, zero, $0001
800C4570	lui    v1, $8007
800C4574	lbu    v1, $22c4(v1)
800C4578	lui    v0, $8008
800C457C	addiu  v0, v0, $31fc
800C4580	sll    v1, v1, $01
800C4584	addu   v1, v1, v0
800C4588	lhu    a0, $0000(v1)
800C458C	addu   v0, zero, zero
800C4590	addiu  a0, a0, $000b
800C4594	sh     a0, $0000(v1)
800C4598	sb     zero, $0001(a1)

Lc459c:	; 800C459C
800C459C	lw     ra, $0010(sp)
800C45A0	addiu  sp, sp, $0018
800C45A4	jr     ra 
800C45A8	nop
////////////////////////////////



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
// 0x60 MAPJUMP
800C40A4	lui    v0, $800a
800C40A8	lbu    v0, $d820(v0)
800C40AC	addiu  sp, sp, $ffe8 (=-$18)
800C40B0	andi   v0, v0, $0003
800C40B4	beq    v0, zero, Lc40cc [$800c40cc]
800C40B8	sw     ra, $0010(sp)
800C40BC	lui    a0, $800a
800C40C0	addiu  a0, a0, $0840
800C40C4	jal    funcbead4 [$800bead4]
800C40C8	ori    a1, zero, $0008

Lc40cc:	; 800C40CC
800C40CC	lui    a1, $800a
800C40D0	lw     a1, $c6e0(a1)
800C40D4	nop
800C40D8	lbu    v1, $0001(a1)
800C40DC	nop
800C40E0	beq    v1, zero, Lc40f8 [$800c40f8]
800C40E4	ori    v0, zero, $0001
800C40E8	beq    v1, v0, Lc4228 [$800c4228]
800C40EC	ori    v0, zero, $0002
800C40F0	j      Lc4268 [$800c4268]
800C40F4	nop

Lc40f8:	; 800C40F8
800C40F8	ori    v0, zero, $0001
800C40FC	sb     v0, $0001(a1)
800C4100	lui    v0, $8008
800C4104	addiu  v0, v0, $31fc
800C4108	lui    a2, $800a
800C410C	lw     a2, $c6e0(a2)
800C4110	lui    a0, $8007
800C4114	lbu    a0, $22c4(a0)
800C4118	lui    a1, $800a
800C411C	lw     a1, $c6dc(a1)
800C4120	sll    a0, a0, $01
800C4124	addu   a0, a0, v0
800C4128	sh     zero, $0026(a2)
800C412C	lhu    v0, $0000(a0)
800C4130	nop
800C4134	addu   v0, a1, v0
800C4138	lbu    v1, $0001(v0)
800C413C	nop
800C4140	sh     v1, $0002(a2)
800C4144	lhu    v0, $0000(a0)
800C4148	nop
800C414C	addu   v0, a1, v0
800C4150	lbu    v0, $0002(v0)
800C4154	nop
800C4158	sll    v0, v0, $08
800C415C	or     v1, v1, v0
800C4160	sh     v1, $0002(a2)
800C4164	lhu    v0, $0000(a0)
800C4168	nop
800C416C	addu   v0, a1, v0
800C4170	lbu    v1, $0003(v0)
800C4174	nop
800C4178	sh     v1, $0004(a2)
800C417C	lhu    v0, $0000(a0)
800C4180	nop
800C4184	addu   v0, a1, v0
800C4188	lbu    v0, $0004(v0)
800C418C	nop
800C4190	sll    v0, v0, $08
800C4194	or     v1, v1, v0
800C4198	sh     v1, $0004(a2)
800C419C	lhu    v0, $0000(a0)
800C41A0	nop
800C41A4	addu   v0, a1, v0
800C41A8	lbu    v1, $0005(v0)
800C41AC	nop
800C41B0	sh     v1, $0006(a2)
800C41B4	lhu    v0, $0000(a0)
800C41B8	nop
800C41BC	addu   v0, a1, v0
800C41C0	lbu    v0, $0006(v0)
800C41C4	nop
800C41C8	sll    v0, v0, $08
800C41CC	or     v1, v1, v0
800C41D0	sh     v1, $0006(a2)
800C41D4	lhu    v0, $0000(a0)
800C41D8	nop
800C41DC	addu   v0, a1, v0
800C41E0	lbu    v1, $0007(v0)
800C41E4	nop
800C41E8	sh     v1, $0022(a2)
800C41EC	lhu    v0, $0000(a0)
800C41F0	nop
800C41F4	addu   v0, a1, v0
800C41F8	lbu    v0, $0008(v0)
800C41FC	nop
800C4200	sll    v0, v0, $08
800C4204	or     v1, v1, v0
800C4208	sh     v1, $0022(a2)
800C420C	lhu    v0, $0000(a0)
800C4210	nop
800C4214	addu   a1, a1, v0
800C4218	lbu    v1, $0009(a1)
800C421C	ori    v0, zero, $0001
800C4220	j      Lc42a0 [$800c42a0]
800C4224	sh     v1, $0024(a2)

Lc4228:	; 800C4228
800C4228	lh     v1, $0026(a1)
800C422C	nop
800C4230	bne    v1, v0, Lc4268 [$800c4268]
800C4234	nop
800C4238	lui    v1, $8007
800C423C	lbu    v1, $22c4(v1)
800C4240	lui    v0, $8008
800C4244	addiu  v0, v0, $31fc
800C4248	sll    v1, v1, $01
800C424C	addu   v1, v1, v0
800C4250	lhu    a0, $0000(v1)
800C4254	addu   v0, zero, zero
800C4258	addiu  a0, a0, $000a
800C425C	sh     a0, $0000(v1)
800C4260	j      Lc42a0 [$800c42a0]
800C4264	sb     zero, $0001(a1)

Lc4268:	; 800C4268
800C4268	lui    v0, $800a
800C426C	lbu    v0, $d820(v0)
800C4270	nop
800C4274	andi   v0, v0, $0003
800C4278	beq    v0, zero, Lc42a0 [$800c42a0]
800C427C	ori    v0, zero, $0001
800C4280	lui    v0, $800a
800C4284	lw     v0, $c6e0(v0)
800C4288	lui    a0, $800a
800C428C	addiu  a0, a0, $0848
800C4290	lbu    a1, $0001(v0)
800C4294	jal    funcbeca4 [$800beca4]
800C4298	ori    a2, zero, $0002
800C429C	ori    v0, zero, $0001

Lc42a0:	; 800C42A0
800C42A0	lw     ra, $0010(sp)
800C42A4	addiu  sp, sp, $0018
800C42A8	jr     ra 
800C42AC	nop
////////////////////////////////



////////////////////////////////
// 0x6E LSTMP
800D1D3C	lui    v0, $800a
800D1D40	lbu    v0, $d820(v0)
800D1D44	addiu  sp, sp, $ffe8 (=-$18)
800D1D48	andi   v0, v0, $0003
800D1D4C	beq    v0, zero, Ld1d64 [$800d1d64]
800D1D50	sw     ra, $0010(sp)
800D1D54	lui    a0, $800a
800D1D58	addiu  a0, a0, $0e38
800D1D5C	jal    funcbead4 [$800bead4]
800D1D60	ori    a1, zero, $0002

Ld1d64:	; 800D1D64
800D1D64	lui    v0, $800a
800D1D68	lw     v0, $c6e0(v0)
800D1D6C	ori    a0, zero, $0002
800D1D70	lh     a2, $0064(v0)
800D1D74	jal    store_memory_block_two_bytes [$800c0248]
800D1D78	ori    a1, zero, $0002
800D1D7C	lui    v1, $8007
800D1D80	lbu    v1, $22c4(v1)
800D1D84	lui    v0, $8008
800D1D88	addiu  v0, v0, $31fc
800D1D8C	sll    v1, v1, $01
800D1D90	addu   v1, v1, v0
800D1D94	lhu    v0, $0000(v1)
800D1D98	nop
800D1D9C	addiu  v0, v0, $0003
800D1DA0	sh     v0, $0000(v1)
800D1DA4	addu   v0, zero, zero
800D1DA8	lw     ra, $0010(sp)
800D1DAC	addiu  sp, sp, $0018
800D1DB0	jr     ra 
800D1DB4	nop
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
// 0xD2 MPJPO
800CD0C4	lui    v0, $800a
800CD0C8	lbu    v0, $d820(v0)
800CD0CC	addiu  sp, sp, $ffe0 (=-$20)
800CD0D0	andi   v0, v0, $0003
800CD0D4	beq    v0, zero, Lcd0ec [$800cd0ec]
800CD0D8	sw     ra, $0018(sp)
800CD0DC	lui    a0, $800a
800CD0E0	addiu  a0, a0, $0c00
800CD0E4	jal    funcbead4 [$800bead4]
800CD0E8	addu   a1, zero, zero

Lcd0ec:	; 800CD0EC
800CD0EC	lui    v0, $8007
800CD0F0	lbu    v0, $22c4(v0)
800CD0F4	nop
800CD0F8	sll    v0, v0, $01
800CD0FC	lui    at, $8008
800CD100	addiu  at, at, $31fc
800CD104	addu   at, at, v0
800CD108	lhu    v1, $0000(at)
800CD10C	lui    v0, $800a
800CD110	lw     v0, $c6dc(v0)
800CD114	nop
800CD118	addu   v0, v0, v1
800CD11C	lui    v1, $800a
800CD120	lw     v1, $c6e0(v1)
800CD124	lbu    v0, $0001(v0)
800CD128	nop
800CD12C	sb     v0, $0036(v1)
800CD130	lui    v1, $8007
800CD134	lbu    v1, $22c4(v1)
800CD138	lui    v0, $8008
800CD13C	addiu  v0, v0, $31fc
800CD140	sll    v1, v1, $01
800CD144	addu   v1, v1, v0
800CD148	lhu    v0, $0000(v1)
800CD14C	nop
800CD150	addiu  v0, v0, $0002
800CD154	sh     v0, $0000(v1)
800CD158	addu   v0, zero, zero
800CD15C	lw     ra, $0018(sp)
800CD160	addiu  sp, sp, $0020
800CD164	jr     ra 
800CD168	nop
////////////////////////////////



////////////////////////////////
// 0xD8 PMJMP
800C42B0	lui    v0, $800a
800C42B4	lbu    v0, $d820(v0)
800C42B8	addiu  sp, sp, $ffe8 (=-$18)
800C42BC	andi   v0, v0, $0003
800C42C0	beq    v0, zero, Lc42d8 [$800c42d8]
800C42C4	sw     ra, $0010(sp)
800C42C8	lui    a0, $800a
800C42CC	addiu  a0, a0, $0854
800C42D0	jal    funcbead4 [$800bead4]
800C42D4	ori    a1, zero, $0008

Lc42d8:	; 800C42D8
800C42D8	lui    v0, $8008
800C42DC	addiu  v0, v0, $31fc
800C42E0	lui    a0, $8007
800C42E4	lbu    a0, $22c4(a0)
800C42E8	lui    v1, $800a
800C42EC	lw     v1, $c6dc(v1)
800C42F0	sll    a0, a0, $01
800C42F4	addu   a0, a0, v0
800C42F8	lhu    v0, $0000(a0)
800C42FC	nop
800C4300	addu   v0, v1, v0
800C4304	lbu    a1, $0001(v0)
800C4308	lhu    v0, $0000(a0)
800C430C	nop
800C4310	addu   v1, v1, v0
800C4314	lhu    v0, $0000(a0)
800C4318	lui    at, $8009
800C431C	sh     a1, $5dd0(at)
800C4320	lbu    v1, $0002(v1)
800C4324	addiu  v0, v0, $0003
800C4328	sll    v1, v1, $08
800C432C	or     a1, a1, v1
800C4330	sh     v0, $0000(a0)
800C4334	addu   v0, zero, zero
800C4338	lui    at, $8009
800C433C	sh     a1, $5dd0(at)
800C4340	lw     ra, $0010(sp)
800C4344	addiu  sp, sp, $0018
800C4348	jr     ra 
800C434C	nop
////////////////////////////////



////////////////////////////////
// 0xD9 PMJMP2
800C4350	lui    v0, $800a
800C4354	lbu    v0, $d820(v0)
800C4358	addiu  sp, sp, $ffe8 (=-$18)
800C435C	andi   v0, v0, $0003
800C4360	beq    v0, zero, Lc4378 [$800c4378]
800C4364	sw     ra, $0010(sp)
800C4368	lui    a0, $800a
800C436C	addiu  a0, a0, $0854
800C4370	jal    funcbead4 [$800bead4]
800C4374	ori    a1, zero, $0008

Lc4378:	; 800C4378
800C4378	lui    v1, $8009
800C437C	lh     v1, $65e8(v1)
800C4380	ori    v0, zero, $0002
800C4384	bne    v1, v0, Lc43b4 [$800c43b4]
800C4388	ori    v0, zero, $0001
800C438C	lui    v1, $8007
800C4390	lbu    v1, $22c4(v1)
800C4394	lui    v0, $8008
800C4398	addiu  v0, v0, $31fc
800C439C	sll    v1, v1, $01
800C43A0	addu   v1, v1, v0
800C43A4	lhu    a0, $0000(v1)
800C43A8	addu   v0, zero, zero
800C43AC	addiu  a0, a0, $0001
800C43B0	sh     a0, $0000(v1)

Lc43b4:	; 800C43B4
800C43B4	lw     ra, $0010(sp)
800C43B8	addiu  sp, sp, $0018
800C43BC	jr     ra 
800C43C0	nop
////////////////////////////////



////////////////////////////////
// 0xFF GAMEOVER
V0 = w[8009c6e0];
[V0 +  1] = b(1a);
[V0 + 26] = h(0);
return 1;
////////////////////////////////
