////////////////////////////////
// func1e4160
801E4160	addiu  sp, sp, $ffd8 (=-$28)
801E4164	sw     s1, $0014(sp)
801E4168	addu   s1, zero, zero
801E416C	ori    a2, zero, $007f
801E4170	ori    a1, zero, $0001
801E4174	addu   v1, zero, zero
801E4178	lui    v0, $8006
801E417C	lw     v0, $8b38(v0)
801E4180	lui    a0, $800d
801E4184	addiu  a0, a0, $24ec
801E4188	sw     ra, $0024(sp)
801E418C	sw     s4, $0020(sp)
801E4190	sw     s3, $001c(sp)
801E4194	sw     s2, $0018(sp)
801E4198	sw     s0, $0010(sp)
801E419C	lui    at, $800d
801E41A0	sb     zero, $29a0(at)
801E41A4	lui    at, $800d
801E41A8	sw     v0, $2a84(at)
801E41AC	lui    at, $800c
801E41B0	sw     v0, $35d0(at)

loop1e41b4:	; 801E41B4
801E41B4	lui    at, $800c
801E41B8	addu   at, at, v1
801E41BC	lbu    v0, $35d6(at)
801E41C0	nop
801E41C4	andi   v0, v0, $007f
801E41C8	beq    v0, a2, L1e41f4 [$801e41f4]
801E41CC	nop
801E41D0	sb     a1, $0000(a0)
801E41D4	lui    v0, $800d
801E41D8	lbu    v0, $29a0(v0)
801E41DC	nop
801E41E0	addiu  v0, v0, $0001
801E41E4	lui    at, $800d
801E41E8	sb     v0, $29a0(at)
801E41EC	j      L1e41f8 [$801e41f8]
801E41F0	nop

L1e41f4:	; 801E41F4
801E41F4	sb     zero, $0000(a0)

L1e41f8:	; 801E41F8
801E41F8	lui    at, $800c
801E41FC	addu   at, at, v1
801E4200	lbu    v0, $35d8(at)
801E4204	nop
801E4208	bne    v0, zero, L1e4238 [$801e4238]
801E420C	nop
801E4210	lui    at, $8007
801E4214	addu   at, at, s1
801E4218	lbu    v0, $f070(at)
801E421C	nop
801E4220	andi   v0, v0, $007f
801E4224	lui    at, $800c
801E4228	addu   at, at, v1
801E422C	sb     v0, $35d4(at)
801E4230	j      L1e4248 [$801e4248]
801E4234	addiu  v1, v1, $001c

L1e4238:	; 801E4238
801E4238	lui    at, $800c
801E423C	addu   at, at, v1
801E4240	sb     s1, $35d4(at)
801E4244	addiu  v1, v1, $001c

L1e4248:	; 801E4248
801E4248	addiu  s1, s1, $0001
801E424C	slti   v0, s1, $0003
801E4250	bne    v0, zero, loop1e41b4 [$801e41b4]
801E4254	addiu  a0, a0, $0001
801E4258	ori    t0, zero, $007f

L1e425c:	; 801E425C
801E425C	lui    a2, $800c

L1e4260:	; 801E4260
801E4260	addiu  a2, a2, $362a
801E4264	ori    a1, zero, $0054
801E426C	ori    a3, zero, $0450
801E4270	lui    v0, $800d
801E4274	lbu    v0, $29a0(v0)

T1 = A2 + e0;
801E427C	addiu  v0, v0, $00ff
801E4280	lui    at, $800d
801E4284	sb     v0, $29a0(at)

A0 = 3;
loop1e4288:	; 801E4288
    V0 = bu[8006f071 + A0];
    if ((V0 & 7f) != 7f)
    {
        [A2] = b(V0); // store id of enemy in battle here

        801E42A8	lui    at, $8007
        801E42AC	addu   at, at, a0
        801E42B0	lbu    v0, $f079(at)
        801E42B4	nop
        801E42B8	andi   v0, v0, $0080
        801E42BC	lui    at, $800c
        801E42C0	addu   at, at, a1
        801E42C4	sb     v0, $35d7(at)
        801E42C8	lui    at, $8007
        801E42CC	addu   at, at, a0
        801E42D0	lbu    v0, $f071(at)
        801E42D4	nop
        801E42D8	andi   v0, v0, $0080
        801E42DC	lui    at, $800c
        801E42E0	addu   at, at, a1
        801E42E4	sb     v0, $35d8(at)
        801E42E8	lui    at, $8007
        801E42EC	addu   at, at, a0
        801E42F0	lbu    v0, $f079(at)
        801E42F4	nop
        801E42F8	andi   v0, v0, $0001
        801E42FC	lui    at, $800c
        801E4300	addu   at, at, a1
        801E4304	sb     v0, $35d9(at)
        801E4308	lui    at, $8007
        801E430C	addu   at, at, a0
        801E4310	lbu    v1, $f081(at)
        801E4314	ori    v0, zero, $0001
        801E4318	lui    at, $800d
        801E431C	addu   at, at, a0
        801E4320	sb     v0, $24ec(at)
        801E4324	andi   v1, v1, $007f
        801E4328	lui    at, $800c
        801E432C	addu   at, at, a1
        801E4330	sb     v1, $35d4(at)
    }
    else
    {
        801E433C	lui    at, $800d
        801E4340	addu   at, at, a3
        801E4344	sh     zero, $c456(at)
        801E4348	lui    at, $800d
        801E434C	addu   at, at, a3
        801E4350	sh     zero, $c454(at)
        801E4354	sb     t0, $0000(a2)
        801E4358	lui    at, $800c
        801E435C	addu   at, at, a1
        801E4360	sb     zero, $35d7(at)
        801E4364	lui    at, $800c
        801E4368	addu   at, at, a1
        801E436C	sb     zero, $35d8(at)
        801E4370	lui    at, $800d
        801E4374	addu   at, at, a0
        801E4378	sb     zero, $24ec(at)
    }

    801E437C	lbu    v0, $0000(a2)
    801E4384	addiu  a1, a1, $001c
    801E4388	addiu  a3, a3, $0170
    801E438C	addiu  v0, v0, $0001
    801E4390	lui    at, $800c
    801E4394	addu   at, at, a0
    801E4398	sb     v0, $355d(at)

    A0 = A0 + 1;
    A2 = A2 + 1c;
    V0 = A2 < T1;
801E43A0	bne    v0, zero, loop1e4288 [$801e4288]



V1 = 0;

loop1e43ac:	; 801E43AC
801E43AC	lui    at, $800d
801E43B0	addu   at, at, v1
801E43B4	sb     zero, $273c(at)
801E43B8	lui    at, $800d
801E43BC	addu   at, at, v1
801E43C0	sb     zero, $273d(at)
801E43C4	addiu  v1, v1, $0004
801E43C8	slti   v0, v1, $0080
801E43CC	bne    v0, zero, loop1e43ac [$801e43ac]
801E43D0	addu   s1, zero, zero
801E43D4	ori    s4, zero, $0001
801E43D8	lui    s0, $800c
801E43DC	addiu  s0, s0, $35d4
801E43E0	addiu  s2, s0, $0001
801E43E4	addu   s3, zero, zero

loop1e43e8:	; 801E43E8
801E43E8	lui    at, $800c
801E43EC	addu   at, at, s3
801E43F0	lbu    v1, $35d6(at)
801E43F4	ori    v0, zero, $007f
801E43F8	beq    v1, v0, L1e44e0 [$801e44e0]
801E43FC	nop
801E4400	lui    at, $800c
801E4404	addu   at, at, s3

L1e4408:	; 801E4408
801E4408	lbu    v0, $35d8(at)
801E440C	nop
801E4410	bne    v0, zero, L1e44a4 [$801e44a4]
801E4414	nop
801E4418	lbu    v0, $0000(s0)
801E441C	nop
801E4420	sll    v0, v0, $02
801E4424	lui    at, $800d
801E4428	addu   at, at, v0
801E442C	lbu    v0, $273c(at)
801E4430	nop
801E4434	sb     v0, $0000(s2)
801E4438	lbu    a0, $0000(s2)
801E443C	jal    battle_unit_id_to_bit_mask [$80072010]

L1e4440:	; 801E4440
801E4440	nop
801E4444	lbu    a0, $0000(s0)
801E4448	nop

L1e444c:	; 801E444C
801E444C	sll    a0, a0, $02
801E4450	lui    at, $800d
801E4454	addu   at, at, a0
801E4458	lbu    v1, $273d(at)
801E445C	nop
801E4460	or     v1, v1, v0
801E4464	lui    at, $800d
801E4468	addu   at, at, a0
801E446C	sb     v1, $273d(at)
801E4470	lbu    v1, $0000(s0)
801E4474	nop
801E4478	sll    v1, v1, $02
801E447C	lui    at, $800d
801E4480	addu   at, at, v1
801E4484	lbu    v0, $273c(at)
801E4488	nop
801E448C	addiu  v0, v0, $0001
801E4490	lui    at, $800d
801E4494	addu   at, at, v1
801E4498	sb     v0, $273c(at)
801E449C	j      L1e44e4 [$801e44e4]
801E44A0	addiu  s0, s0, $001c

L1e44a4:	; 801E44A4
801E44A4	sb     zero, $0000(s2)
801E44A8	lbu    v0, $0000(s0)
801E44AC	nop
801E44B0	addiu  v0, v0, $0010
801E44B4	sll    v0, v0, $02
801E44B8	lui    at, $800d
801E44BC	addu   at, at, v0
801E44C0	sb     s4, $273d(at)
801E44C4	lbu    v0, $0000(s0)
801E44C8	nop
801E44CC	addiu  v0, v0, $0010
801E44D0	sll    v0, v0, $02
801E44D4	lui    at, $800d

L1e44d8:	; 801E44D8
801E44D8	addu   at, at, v0
801E44DC	sb     s4, $273c(at)

L1e44e0:	; 801E44E0
801E44E0	addiu  s0, s0, $001c

L1e44e4:	; 801E44E4
801E44E4	addiu  s2, s2, $001c
801E44E8	addiu  s1, s1, $0001
801E44EC	slti   v0, s1, $0003
801E44F0	bne    v0, zero, loop1e43e8 [$801e43e8]
801E44F4	addiu  s3, s3, $001c
801E44F8	ori    s1, zero, $0003
801E44FC	ori    s4, zero, $0001
801E4500	lui    v0, $800c
801E4504	addiu  v0, v0, $35d4

L1e4508:	; 801E4508
801E4508	addiu  s0, v0, $0054
801E450C	addiu  s2, v0, $0055
801E4510	ori    s3, zero, $0054

loop1e4514:	; 801E4514
801E4514	lui    at, $800c
801E4518	addu   at, at, s3
801E451C	lbu    v1, $35d6(at)
801E4520	ori    v0, zero, $007f

L1e4524:	; 801E4524
801E4524	beq    v1, v0, L1e4618 [$801e4618]
801E4528	nop
801E452C	lui    at, $800c
801E4530	addu   at, at, s3
801E4534	lbu    v0, $35d8(at)
801E4538	nop
801E453C	bne    v0, zero, L1e45dc [$801e45dc]
801E4540	nop
801E4544	lbu    v0, $0000(s0)
801E4548	nop
801E454C	addiu  v0, v0, $0008
801E4550	sll    v0, v0, $02
801E4554	lui    at, $800d
801E4558	addu   at, at, v0
801E455C	lbu    v0, $273c(at)
801E4560	nop
801E4564	sb     v0, $0000(s2)
801E4568	lbu    a0, $0000(s2)
801E456C	jal    battle_unit_id_to_bit_mask [$80072010]
801E4570	nop
801E4574	lbu    a0, $0000(s0)
801E4578	nop
801E457C	addiu  a0, a0, $0008
801E4580	sll    a0, a0, $02
801E4584	lui    at, $800d
801E4588	addu   at, at, a0
801E458C	lbu    v1, $273d(at)
801E4590	nop
801E4594	or     v1, v1, v0
801E4598	lui    at, $800d
801E459C	addu   at, at, a0
801E45A0	sb     v1, $273d(at)
801E45A4	lbu    v1, $0000(s0)
801E45A8	nop
801E45AC	addiu  v1, v1, $0008
801E45B0	sll    v1, v1, $02
801E45B4	lui    at, $800d
801E45B8	addu   at, at, v1
801E45BC	lbu    v0, $273c(at)
801E45C0	nop
801E45C4	addiu  v0, v0, $0001
801E45C8	lui    at, $800d
801E45CC	addu   at, at, v1
801E45D0	sb     v0, $273c(at)
801E45D4	j      L1e461c [$801e461c]
801E45D8	addiu  s0, s0, $001c

L1e45dc:	; 801E45DC
801E45DC	sb     zero, $0000(s2)
801E45E0	lbu    v0, $0000(s0)
801E45E4	nop
801E45E8	addiu  v0, v0, $0018
801E45EC	sll    v0, v0, $02
801E45F0	lui    at, $800d
801E45F4	addu   at, at, v0
801E45F8	sb     s4, $273d(at)
801E45FC	lbu    v0, $0000(s0)
801E4600	nop
801E4604	addiu  v0, v0, $0018
801E4608	sll    v0, v0, $02
801E460C	lui    at, $800d
801E4610	addu   at, at, v0
801E4614	sb     s4, $273c(at)

L1e4618:	; 801E4618
801E4618	addiu  s0, s0, $001c

L1e461c:	; 801E461C
801E461C	addiu  s2, s2, $001c
801E4620	addiu  s1, s1, $0001
801E4624	slti   v0, s1, $000b
801E4628	bne    v0, zero, loop1e4514 [$801e4514]
801E462C	addiu  s3, s3, $001c
801E4630	addu   s1, zero, zero
801E4634	ori    t2, zero, $007f
801E4638	lui    t1, $800d
801E463C	lw     t1, $2a84(t1)
801E4640	lui    a1, $800c
801E4644	addiu  a1, a1, $35e0
801E4648	addiu  a0, a1, $fff4 (=-$c)
801E464C	addiu  t0, a1, $fffe (=-$2)
801E4650	addiu  a3, a1, $fff5 (=-$b)
801E4654	addu   a2, zero, zero

loop1e4658:	; 801E4658
801E4658	lui    at, $800c
801E465C	addu   at, at, a2
801E4660	lbu    v0, $35d6(at)
801E4664	nop
801E4668	beq    v0, t2, L1e4708 [$801e4708]
801E466C	nop
801E4670	lui    at, $800c

L1e4674:	; 801E4674
801E4674	addu   at, at, a2
801E4678	lbu    v0, $35d8(at)
801E467C	nop
801E4680	bne    v0, zero, L1e46d0 [$801e46d0]
801E4684	nop
801E4688	lbu    v0, $0000(a3)
801E468C	lbu    v1, $0000(a0)

L1e4690:	; 801E4690
801E4690	sll    v0, v0, $02
801E4694	sll    v1, v1, $05
801E4698	addu   v0, v0, v1
801E469C	addu   v0, t1, v0
801E46A0	lhu    v0, $0004(v0)
801E46A4	nop
801E46A8	sh     v0, $0000(t0)
801E46AC	lbu    v0, $0000(a3)

L1e46b0:	; 801E46B0
801E46B0	lbu    v1, $0000(a0)
801E46B4	sll    v0, v0, $02
801E46B8	sll    v1, v1, $05
801E46BC	addu   v0, v0, v1

L1e46c0:	; 801E46C0
801E46C0	addu   v0, t1, v0
801E46C4	lhu    v0, $0006(v0)
801E46C8	j      L1e4708 [$801e4708]
801E46CC	sh     v0, $0000(a1)

L1e46d0:	; 801E46D0
801E46D0	lbu    v0, $0000(a0)
801E46D4	nop
801E46D8	sll    v0, v0, $03
801E46DC	addu   v0, t1, v0
801E46E0	lhu    v0, $0100(v0)
801E46E4	nop
801E46E8	sh     v0, $0000(t0)
801E46EC	lbu    v0, $0000(a0)
801E46F0	nop
801E46F4	sll    v0, v0, $03
801E46F8	addu   v0, t1, v0
801E46FC	lhu    v0, $0102(v0)
801E4700	nop
801E4704	sh     v0, $0000(a1)

L1e4708:	; 801E4708
801E4708	addiu  a1, a1, $001c
801E470C	addiu  a0, a0, $001c
801E4710	addiu  t0, t0, $001c
801E4714	addiu  a3, a3, $001c
801E4718	addiu  s1, s1, $0001
801E471C	slti   v0, s1, $0003
801E4720	bne    v0, zero, loop1e4658 [$801e4658]
801E4724	addiu  a2, a2, $001c
801E4728	ori    s1, zero, $0003
801E472C	ori    t4, zero, $007f
801E4730	lui    v0, $800c

L1e4734:	; 801E4734
801E4734	addiu  v0, v0, $35da
801E4738	addiu  t3, v0, $0054
801E473C	lui    t2, $8007
801E4740	addiu  t2, t2, $f087 (=-$f79)
801E4744	addiu  t1, v0, $005a
801E4748	addiu  a1, v0, $004e
801E474C	addiu  t0, v0, $0058
801E4750	addiu  a3, v0, $004f

L1e4754:	; 801E4754
801E4754	ori    a2, zero, $0054

loop1e4758:	; 801E4758
801E4758	lui    at, $800c
801E475C	addu   at, at, a2
801E4760	lbu    v0, $35d6(at)
801E4764	nop
801E4768	beq    v0, t4, L1e4824 [$801e4824]
801E476C	nop
801E4770	lui    at, $800c
801E4774	addu   at, at, a2
801E4778	lbu    v0, $35d8(at)
801E477C	nop
801E4780	bne    v0, zero, L1e47d8 [$801e47d8]
801E4784	nop
801E4788	lbu    v0, $0000(a3)
801E478C	lbu    v1, $0000(a1)
801E4790	lui    a0, $800d
801E4794	lw     a0, $2a84(a0)
801E4798	sll    v0, v0, $02
801E479C	sll    v1, v1, $05
801E47A0	addu   v0, v0, v1
801E47A4	addu   v0, a0, v0
801E47A8	lhu    v0, $0010(v0)
801E47AC	nop
801E47B0	sh     v0, $0000(t0)
801E47B4	lbu    v1, $0000(a3)
801E47B8	lbu    v0, $0000(a1)
801E47BC	sll    v1, v1, $02
801E47C0	sll    v0, v0, $05
801E47C4	addu   v1, v1, v0
801E47C8	addu   a0, a0, v1
801E47CC	lhu    v0, $0012(a0)
801E47D0	j      L1e4814 [$801e4814]
801E47D4	sh     v0, $0000(t1)

L1e47d8:	; 801E47D8
801E47D8	lbu    v0, $0000(a1)
801E47DC	lui    v1, $800d
801E47E0	lw     v1, $2a84(v1)
801E47E4	sll    v0, v0, $03
801E47E8	addu   v0, v1, v0
801E47EC	lhu    v0, $0104(v0)
801E47F0	nop
801E47F4	sh     v0, $0000(t0)
801E47F8	lbu    v0, $0000(a1)
801E47FC	nop
801E4800	sll    v0, v0, $03
801E4804	addu   v1, v1, v0
801E4808	lhu    v0, $0106(v1)
801E480C	nop
801E4810	sh     v0, $0000(t1)

L1e4814:	; 801E4814
801E4814	lbu    v0, $0000(t2)
801E4818	nop
801E481C	andi   v0, v0, $0080
801E4820	sb     v0, $0000(t3)

L1e4824:	; 801E4824
801E4824	addiu  t3, t3, $001c
801E4828	addiu  t2, t2, $0001
801E482C	addiu  t1, t1, $001c

L1e4830:	; 801E4830
801E4830	addiu  a1, a1, $001c
801E4834	addiu  t0, t0, $001c
801E4838	addiu  a3, a3, $001c
801E483C	addiu  s1, s1, $0001
801E4840	slti   v0, s1, $000b
801E4844	bne    v0, zero, loop1e4758 [$801e4758]
801E4848	addiu  a2, a2, $001c
801E484C	lw     ra, $0024(sp)
801E4850	lw     s4, $0020(sp)
801E4854	lw     s3, $001c(sp)
801E4858	lw     s2, $0018(sp)
801E485C	lw     s1, $0014(sp)
801E4860	lw     s0, $0010(sp)
801E4864	addiu  sp, sp, $0028
801E4868	jr     ra 
801E486C	nop
////////////////////////////////



////////////////////////////////
// func1e4870
801E4880	lui    fp, $800d
801E4884	addiu  fp, fp, $2b30
801E4888	lui    v0, $800c
801E488C	addiu  v0, v0, $3435
801E4894	addiu  s2, v0, $000c
801E489C	addiu  s1, v0, $000b
801E48AC	addu   s0, zero, zero
801E48B4	addu   s5, zero, zero
801E48B8	lui    v1, $800c
801E48BC	lw     v1, $34f8(v1)

V0 = 800c4008;
S3 = 800c362a;

801E48D8	sh     zero, $0000(v0)
801E48DC	lui    at, $800d
801E48E0	sh     zero, $3100(at)
V0 = hu[V1 + 30];
801E48E8	addiu  s7, v1, $0032
V0 = V0 + V1;
801E48F0	lui    at, $800c
801E48F4	sw     v0, $3504(at)

S6 = 3;
loop1e48f8:	; 801E48F8
    801E48F8	lui    at, $800c
    801E48FC	addu   at, at, s5
    801E4900	sb     zero, $3443(at)

    V1 = bu[S3];
    if (V1 != 7f)
    {
        A0 = 800cc408 + S6 * 170;
        A1 = S7 + V1 * 170;
        A2 = 170;
        func3f844;

        V0 = bu[S3];
        801E4940	lui    v1, $800c
        801E4944	lw     v1, $34f8(v1)
        801E4948	sll    v0, v0, $01
        801E494C	addu   v0, v0, v1
        801E4950	lhu    v0, $0000(v0)
        801E4954	nop
        801E4958	addu   v1, v0, v1
        801E495C	lhu    v0, $0000(v1)
        801E4960	nop
        801E4964	addu   v0, v1, v0
        801E4968	lui    at, $800d
        801E496C	addu   at, at, s0
        801E4970	sw     v0, $2b20(at)
        801E4974	lhu    v0, $0002(v1)
        801E4978	nop
        801E497C	addu   v0, v1, v0
        801E4980	lui    at, $800d
        801E4984	addu   at, at, s0
        801E4988	sw     v0, $2b24(at)
        801E498C	lhu    a0, $0004(v1)
        801E4990	ori    v0, zero, $ffff
        801E4994	beq    a0, v0, L1e49b4 [$801e49b4]
        801E4998	addu   v0, v1, a0
        801E499C	lui    at, $800d
        801E49A0	addu   at, at, s0
        801E49A4	sw     v0, $2b28(at)
        801E49A8	ori    v0, zero, $0001
        801E49AC	j      L1e49b8 [$801e49b8]
        801E49B0	sb     v0, $0000(s1)

        L1e49b4:	; 801E49B4
        801E49B4	sb     zero, $0000(s1)

        L1e49b8:	; 801E49B8
        801E49B8	lhu    a0, $0006(v1)
        801E49BC	ori    v0, zero, $ffff
        801E49C0	beq    a0, v0, L1e49e4 [$801e49e4]
        801E49C4	nop
        801E49C8	addu   v0, v1, a0
        801E49CC	lui    at, $800d
        801E49D0	addu   at, at, s0
        801E49D4	sw     v0, $2b2c(at)
        801E49D8	ori    v0, zero, $0001
        801E49DC	j      L1e49e8 [$801e49e8]
        801E49E0	sb     v0, $0000(s2)

        L1e49e4:	; 801E49E4
        801E49E4	sb     zero, $0000(s2)

        L1e49e8:	; 801E49E8
        801E49E8	ori    v1, zero, $0003
        801E49EC	addu   v0, s0, fp
        801E49F0	addiu  v0, v0, $000c

        loop1e49f4:	; 801E49F4
        801E49F4	sw     zero, $0000(v0)
        801E49F8	addiu  v1, v1, $ffff (=-$1)

        L1e49fc:	; 801E49FC
        801E49FC	bgez   v1, loop1e49f4 [$801e49f4]
        801E4A00	addiu  v0, v0, $fffc (=-$4)
        801E4A04	ori    v1, zero, $0007
        801E4A08	lui    v0, $800d
        801E4A0C	addiu  v0, v0, $2b4e
        801E4A10	addu   v0, s0, v0

        L1e4a14:	; 801E4A14
        801E4A14	sh     zero, $0000(v0)
        801E4A18	addiu  v1, v1, $ffff (=-$1)
        801E4A1C	bgez   v1, L1e4a14 [$801e4a14]
        801E4A20	addiu  v0, v0, $fffe (=-$2)
        801E4A24	ori    v1, zero, $000f
        801E4A28	lui    v0, $800d
        801E4A2C	addiu  v0, v0, $2b5f
        801E4A30	addu   v0, s0, v0

        loop1e4a34:	; 801E4A34
        801E4A34	sb     zero, $0000(v0)
        801E4A38	addiu  v1, v1, $ffff (=-$1)
        801E4A3C	bgez   v1, loop1e4a34 [$801e4a34]
        801E4A40	addiu  v0, v0, $ffff (=-$1)
        801E4A48	addiu  s2, s2, $0004
    }
    else
    {
        A0 = 800cc408 + S6 * 170;
        A1 = 170;
        func3f790;

        801E4A60	sb     zero, $0000(s1)
        801E4A64	sb     zero, $0000(s2)
        801E4A68	addiu  s2, s2, $0004
    }

    801E4A6C	addiu  s1, s1, $0004
    801E4A74	addiu  s0, s0, $0040
    801E4A78	addiu  s5, s5, $0004
    S3 = S3 + 1c;

    S6 = S6 + 1;
    V0 = S6 < b;
801E4A84	bne    v0, zero, loop1e48f8 [$801e48f8]
////////////////////////////////