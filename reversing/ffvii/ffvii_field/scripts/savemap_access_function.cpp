////////////////////////////////////////////////////////
// store_memory_block_one_byte
800BF3AC	addiu  sp, sp, $ffe8 (=-$18)
800BF3B0	sw     s0, $0010(sp)
800BF3B4	addu   s0, a2, zero
800BF3B8	addiu  a0, a0, $ffff (=-$1)
800BF3BC	sll    a0, a0, $10
800BF3C0	sra    a0, a0, $10
800BF3C4	sltiu  v0, a0, $0006
800BF3C8	beq    v0, zero, Lbf558 [$800bf558]
800BF3CC	sw     ra, $0014(sp)
800BF3D0	sll    v0, a0, $02
800BF3D4	lui    at, $800a
800BF3D8	addiu  at, at, $03bc
800BF3DC	addu   at, at, v0
800BF3E0	lw     v0, $0000(at)
800BF3E4	nop
800BF3E8	jr     v0 
800BF3EC	nop

800BF3F0	lui    v0, $8007
800BF3F4	lbu    v0, $22c4(v0)
800BF3F8	nop
800BF3FC	sll    v0, v0, $01
800BF400	lui    at, $8008
800BF404	addiu  at, at, $31fc
800BF408	addu   at, at, v0
800BF40C	lhu    v1, $0000(at)
800BF410	lui    v0, $800a
800BF414	lw     v0, $c6dc(v0)
800BF418	nop
800BF41C	addu   v0, v0, v1
800BF420	lbu    v0, $0001(v0)
800BF424	j      Lbf558 [$800bf558]
800BF428	srl    v1, v0, $04
800BF42C	lui    v0, $8007
800BF430	lbu    v0, $22c4(v0)
800BF434	nop
800BF438	sll    v0, v0, $01
800BF43C	lui    at, $8008
800BF440	addiu  at, at, $31fc
800BF444	addu   at, at, v0
800BF448	lhu    v1, $0000(at)
800BF44C	lui    v0, $800a
800BF450	lw     v0, $c6dc(v0)
800BF454	nop
800BF458	addu   v0, v0, v1
800BF45C	lbu    v0, $0001(v0)
800BF460	j      Lbf558 [$800bf558]
800BF464	andi   v1, v0, $000f
800BF468	lui    v0, $8007
800BF46C	lbu    v0, $22c4(v0)
800BF470	nop
800BF474	sll    v0, v0, $01
800BF478	lui    at, $8008
800BF47C	addiu  at, at, $31fc
800BF480	addu   at, at, v0
800BF484	lhu    v1, $0000(at)
800BF488	lui    v0, $800a
800BF48C	lw     v0, $c6dc(v0)
800BF490	nop
800BF494	addu   v0, v0, v1
800BF498	lbu    v0, $0002(v0)
800BF49C	j      Lbf558 [$800bf558]
800BF4A0	srl    v1, v0, $04
800BF4A4	lui    v0, $8007
800BF4A8	lbu    v0, $22c4(v0)
800BF4AC	nop
800BF4B0	sll    v0, v0, $01
800BF4B4	lui    at, $8008
800BF4B8	addiu  at, at, $31fc
800BF4BC	addu   at, at, v0
800BF4C0	lhu    v1, $0000(at)
800BF4C4	lui    v0, $800a
800BF4C8	lw     v0, $c6dc(v0)
800BF4CC	nop
800BF4D0	addu   v0, v0, v1
800BF4D4	lbu    v0, $0002(v0)
800BF4D8	j      Lbf558 [$800bf558]
800BF4DC	andi   v1, v0, $000f
800BF4E0	lui    v0, $8007
800BF4E4	lbu    v0, $22c4(v0)
800BF4E8	nop
800BF4EC	sll    v0, v0, $01
800BF4F0	lui    at, $8008
800BF4F4	addiu  at, at, $31fc
800BF4F8	addu   at, at, v0
800BF4FC	lhu    v1, $0000(at)
800BF500	lui    v0, $800a
800BF504	lw     v0, $c6dc(v0)
800BF508	nop
800BF50C	addu   v0, v0, v1
800BF510	lbu    v0, $0003(v0)
800BF514	j      Lbf558 [$800bf558]
800BF518	srl    v1, v0, $04
800BF51C	lui    v0, $8007
800BF520	lbu    v0, $22c4(v0)
800BF524	nop
800BF528	sll    v0, v0, $01
800BF52C	lui    at, $8008
800BF530	addiu  at, at, $31fc
800BF534	addu   at, at, v0
800BF538	lhu    v1, $0000(at)
800BF53C	lui    v0, $800a
800BF540	lw     v0, $c6dc(v0)
800BF544	nop
800BF548	addu   v0, v0, v1
800BF54C	lbu    v0, $0003(v0)
800BF550	nop
800BF554	andi   v1, v0, $000f

Lbf558:	; 800BF558
800BF558	andi   v0, v1, $00ff
800BF55C	addiu  a0, v0, $ffff (=-$1)
800BF560	sltiu  v0, a0, $000f
800BF564	beq    v0, zero, Lbf8bc [$800bf8bc]
800BF568	sll    v0, a0, $02
800BF56C	lui    at, $800a
800BF570	addiu  at, at, $03d4
800BF574	addu   at, at, v0
800BF578	lw     v0, $0000(at)
800BF57C	nop
800BF580	jr     v0 
800BF584	nop

800BF588	lui    v0, $8007
800BF58C	lbu    v0, $22c4(v0)
800BF590	sll    v1, a1, $10
800BF594	sll    v0, v0, $01
800BF598	lui    at, $8008
800BF59C	addiu  at, at, $31fc
800BF5A0	addu   at, at, v0
800BF5A4	lhu    a0, $0000(at)
800BF5A8	lui    v0, $800a
800BF5AC	lw     v0, $c6dc(v0)
800BF5B0	sra    v1, v1, $10
800BF5B4	addu   v0, v0, a0
800BF5B8	addu   v0, v0, v1
800BF5BC	lbu    a1, $0000(v0)
800BF5C0	nop
800BF5C4	lui    at, $800a
800BF5C8	addiu  at, at, $d288 (=-$2d78)
800BF5CC	addu   at, at, a1
800BF5D0	sb     s0, $0000(at)
800BF5D4	lui    v0, $800a
800BF5D8	lbu    v0, $d820(v0)
800BF5DC	nop
800BF5E0	andi   v0, v0, $0003
800BF5E4	beq    v0, zero, Lbf8f4 [$800bf8f4]
800BF5E8	nop
800BF5EC	lui    a0, $800a
800BF5F0	addiu  a0, a0, $0394
800BF5F4	jal    funcbeca4 [$800beca4]
800BF5F8	ori    a2, zero, $0004
800BF5FC	lui    a0, $800a
800BF600	addiu  a0, a0, $039c
800BF604	j      Lbf8ac [$800bf8ac]
800BF608	andi   a1, s0, $00ff
800BF60C	lui    v0, $8007
800BF610	lbu    v0, $22c4(v0)
800BF614	sll    v1, a1, $10
800BF618	sll    v0, v0, $01
800BF61C	lui    at, $8008
800BF620	addiu  at, at, $31fc
800BF624	addu   at, at, v0
800BF628	lhu    a0, $0000(at)
800BF62C	lui    v0, $800a
800BF630	lw     v0, $c6dc(v0)
800BF634	sra    v1, v1, $10
800BF638	addu   v0, v0, a0
800BF63C	addu   v0, v0, v1
800BF640	lbu    v0, $0000(v0)
800BF644	nop
800BF648	ori    a1, v0, $0100
800BF64C	lui    at, $800a
800BF650	addiu  at, at, $d288 (=-$2d78)
800BF654	addu   at, at, a1
800BF658	sb     s0, $0000(at)
800BF65C	lui    v0, $800a
800BF660	lbu    v0, $d820(v0)
800BF664	nop
800BF668	andi   v0, v0, $0003
800BF66C	beq    v0, zero, Lbf8f4 [$800bf8f4]
800BF670	nop
800BF674	lui    a0, $800a
800BF678	addiu  a0, a0, $0394
800BF67C	jal    funcbeca4 [$800beca4]
800BF680	ori    a2, zero, $0004
800BF684	lui    a0, $800a
800BF688	addiu  a0, a0, $039c
800BF68C	j      Lbf8ac [$800bf8ac]
800BF690	andi   a1, s0, $00ff
800BF694	lui    v0, $8007
800BF698	lbu    v0, $22c4(v0)
800BF69C	sll    v1, a1, $10
800BF6A0	sll    v0, v0, $01
800BF6A4	lui    at, $8008
800BF6A8	addiu  at, at, $31fc
800BF6AC	addu   at, at, v0
800BF6B0	lhu    a0, $0000(at)
800BF6B4	lui    v0, $800a
800BF6B8	lw     v0, $c6dc(v0)
800BF6BC	sra    v1, v1, $10
800BF6C0	addu   v0, v0, a0
800BF6C4	addu   v0, v0, v1
800BF6C8	lbu    v0, $0000(v0)
800BF6CC	nop
800BF6D0	ori    a1, v0, $0200
800BF6D4	lui    at, $800a
800BF6D8	addiu  at, at, $d288 (=-$2d78)
800BF6DC	addu   at, at, a1
800BF6E0	sb     s0, $0000(at)
800BF6E4	lui    v0, $800a
800BF6E8	lbu    v0, $d820(v0)
800BF6EC	nop
800BF6F0	andi   v0, v0, $0003
800BF6F4	beq    v0, zero, Lbf8f4 [$800bf8f4]
800BF6F8	nop
800BF6FC	lui    a0, $800a
800BF700	addiu  a0, a0, $0394
800BF704	jal    funcbeca4 [$800beca4]
800BF708	ori    a2, zero, $0004
800BF70C	lui    a0, $800a
800BF710	addiu  a0, a0, $039c
800BF714	j      Lbf8ac [$800bf8ac]
800BF718	andi   a1, s0, $00ff
800BF71C	lui    v0, $8007
800BF720	lbu    v0, $22c4(v0)
800BF724	sll    v1, a1, $10
800BF728	sll    v0, v0, $01
800BF72C	lui    at, $8008
800BF730	addiu  at, at, $31fc
800BF734	addu   at, at, v0
800BF738	lhu    a0, $0000(at)
800BF73C	lui    v0, $800a
800BF740	lw     v0, $c6dc(v0)
800BF744	sra    v1, v1, $10
800BF748	addu   v0, v0, a0
800BF74C	addu   v0, v0, v1
800BF750	lbu    v0, $0000(v0)
800BF754	nop
800BF758	ori    a1, v0, $0300
800BF75C	lui    at, $800a
800BF760	addiu  at, at, $d288 (=-$2d78)
800BF764	addu   at, at, a1
800BF768	sb     s0, $0000(at)
800BF76C	lui    v0, $800a
800BF770	lbu    v0, $d820(v0)
800BF774	nop
800BF778	andi   v0, v0, $0003
800BF77C	beq    v0, zero, Lbf8f4 [$800bf8f4]
800BF780	nop
800BF784	lui    a0, $800a
800BF788	addiu  a0, a0, $0394
800BF78C	jal    funcbeca4 [$800beca4]
800BF790	ori    a2, zero, $0004
800BF794	lui    a0, $800a
800BF798	addiu  a0, a0, $039c
800BF79C	j      Lbf8ac [$800bf8ac]
800BF7A0	andi   a1, s0, $00ff
800BF7A4	lui    v0, $8007
800BF7A8	lbu    v0, $22c4(v0)
800BF7AC	sll    v1, a1, $10
800BF7B0	sll    v0, v0, $01
800BF7B4	lui    at, $8008
800BF7B8	addiu  at, at, $31fc
800BF7BC	addu   at, at, v0
800BF7C0	lhu    a0, $0000(at)

Lbf7c4:	; 800BF7C4
800BF7C4	lui    v0, $800a
800BF7C8	lw     v0, $c6dc(v0)
800BF7CC	sra    v1, v1, $10
800BF7D0	addu   v0, v0, a0
800BF7D4	addu   v0, v0, v1
800BF7D8	lbu    v0, $0000(v0)
800BF7DC	nop
800BF7E0	ori    a1, v0, $0400
800BF7E4	lui    at, $800a
800BF7E8	addiu  at, at, $d288 (=-$2d78)
800BF7EC	addu   at, at, a1
800BF7F0	sb     s0, $0000(at)
800BF7F4	lui    v0, $800a
800BF7F8	lbu    v0, $d820(v0)
800BF7FC	nop
800BF800	andi   v0, v0, $0003
800BF804	beq    v0, zero, Lbf8f4 [$800bf8f4]
800BF808	nop
800BF80C	lui    a0, $800a
800BF810	addiu  a0, a0, $0394
800BF814	jal    funcbeca4 [$800beca4]
800BF818	ori    a2, zero, $0004
800BF81C	lui    a0, $800a
800BF820	addiu  a0, a0, $039c
800BF824	j      Lbf8ac [$800bf8ac]
800BF828	andi   a1, s0, $00ff
800BF82C	lui    v0, $8007
800BF830	lbu    v0, $22c4(v0)
800BF834	sll    v1, a1, $10
800BF838	sll    v0, v0, $01
800BF83C	lui    at, $8008
800BF840	addiu  at, at, $31fc
800BF844	addu   at, at, v0
800BF848	lhu    a0, $0000(at)
800BF84C	lui    v0, $800a
800BF850	lw     v0, $c6dc(v0)
800BF854	sra    v1, v1, $10
800BF858	addu   v0, v0, a0
800BF85C	addu   v0, v0, v1
800BF860	lbu    a1, $0000(v0)
800BF864	nop
800BF868	lui    at, $8007
800BF86C	addiu  at, at, $5e24
800BF870	addu   at, at, a1
800BF874	sb     s0, $0000(at)
800BF878	lui    v0, $800a
800BF87C	lbu    v0, $d820(v0)
800BF880	nop
800BF884	andi   v0, v0, $0003
800BF888	beq    v0, zero, Lbf8f4 [$800bf8f4]
800BF88C	nop
800BF890	lui    a0, $800a
800BF894	addiu  a0, a0, $0394
800BF898	jal    funcbeca4 [$800beca4]
800BF89C	ori    a2, zero, $0004
800BF8A0	lui    a0, $800a
800BF8A4	addiu  a0, a0, $03a4
800BF8A8	andi   a1, s0, $00ff

Lbf8ac:	; 800BF8AC
800BF8AC	jal    funcbeca4 [$800beca4]
800BF8B0	ori    a2, zero, $0002
800BF8B4	j      Lbf8f4 [$800bf8f4]
800BF8B8	nop

Lbf8bc:	; 800BF8BC
800BF8BC	lui    v0, $800a
800BF8C0	lbu    v0, $d820(v0)
800BF8C4	nop
800BF8C8	andi   v0, v0, $0003
800BF8CC	beq    v0, zero, Lbf8e4 [$800bf8e4]
800BF8D0	andi   a1, v1, $00ff
800BF8D4	lui    a0, $800a
800BF8D8	addiu  a0, a0, $03ac
800BF8DC	jal    funcbeca4 [$800beca4]
800BF8E0	ori    a2, zero, $0002

Lbf8e4:	; 800BF8E4
800BF8E4	lui    a0, $800a
800BF8E8	addiu  a0, a0, $032c
800BF8EC	jal    funcd4848 [$800d4848]
800BF8F0	nop

Lbf8f4:	; 800BF8F4
800BF8F4	lw     ra, $0014(sp)
800BF8F8	lw     s0, $0010(sp)
800BF8FC	addiu  sp, sp, $0018
800BF900	jr     ra 
800BF904	nop
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// store_memory_block_two_bytes
800C0248	addiu  sp, sp, $ffe8 (=-$18)
800C024C	sw     s0, $0010(sp)
800C0250	addu   s0, a2, zero
800C0254	addiu  a0, a0, $ffff (=-$1)
800C0258	sll    a0, a0, $10
800C025C	sra    a0, a0, $10
800C0260	sltiu  v0, a0, $0006
800C0264	beq    v0, zero, Lc03f4 [$800c03f4]
800C0268	sw     ra, $0014(sp)
800C026C	sll    v0, a0, $02
800C0270	lui    at, $800a
800C0274	addiu  at, at, $046c
800C0278	addu   at, at, v0
800C027C	lw     v0, $0000(at)
800C0280	nop
800C0284	jr     v0 
800C0288	nop

800C028C	lui    v0, $8007
800C0290	lbu    v0, $22c4(v0)
800C0294	nop
800C0298	sll    v0, v0, $01
800C029C	lui    at, $8008
800C02A0	addiu  at, at, $31fc
800C02A4	addu   at, at, v0
800C02A8	lhu    v1, $0000(at)
800C02AC	lui    v0, $800a
800C02B0	lw     v0, $c6dc(v0)
800C02B4	nop
800C02B8	addu   v0, v0, v1
800C02BC	lbu    v0, $0001(v0)
800C02C0	j      Lc03f4 [$800c03f4]
800C02C4	srl    v1, v0, $04
800C02C8	lui    v0, $8007
800C02CC	lbu    v0, $22c4(v0)
800C02D0	nop
800C02D4	sll    v0, v0, $01
800C02D8	lui    at, $8008
800C02DC	addiu  at, at, $31fc
800C02E0	addu   at, at, v0
800C02E4	lhu    v1, $0000(at)
800C02E8	lui    v0, $800a
800C02EC	lw     v0, $c6dc(v0)
800C02F0	nop
800C02F4	addu   v0, v0, v1
800C02F8	lbu    v0, $0001(v0)
800C02FC	j      Lc03f4 [$800c03f4]
800C0300	andi   v1, v0, $000f
800C0304	lui    v0, $8007
800C0308	lbu    v0, $22c4(v0)
800C030C	nop
800C0310	sll    v0, v0, $01
800C0314	lui    at, $8008
800C0318	addiu  at, at, $31fc
800C031C	addu   at, at, v0
800C0320	lhu    v1, $0000(at)
800C0324	lui    v0, $800a
800C0328	lw     v0, $c6dc(v0)
800C032C	nop
800C0330	addu   v0, v0, v1
800C0334	lbu    v0, $0002(v0)
800C0338	j      Lc03f4 [$800c03f4]
800C033C	srl    v1, v0, $04
800C0340	lui    v0, $8007
800C0344	lbu    v0, $22c4(v0)
800C0348	nop
800C034C	sll    v0, v0, $01
800C0350	lui    at, $8008
800C0354	addiu  at, at, $31fc
800C0358	addu   at, at, v0
800C035C	lhu    v1, $0000(at)
800C0360	lui    v0, $800a
800C0364	lw     v0, $c6dc(v0)
800C0368	nop
800C036C	addu   v0, v0, v1
800C0370	lbu    v0, $0002(v0)
800C0374	j      Lc03f4 [$800c03f4]
800C0378	andi   v1, v0, $000f
800C037C	lui    v0, $8007
800C0380	lbu    v0, $22c4(v0)
800C0384	nop
800C0388	sll    v0, v0, $01
800C038C	lui    at, $8008
800C0390	addiu  at, at, $31fc
800C0394	addu   at, at, v0
800C0398	lhu    v1, $0000(at)
800C039C	lui    v0, $800a
800C03A0	lw     v0, $c6dc(v0)
800C03A4	nop
800C03A8	addu   v0, v0, v1
800C03AC	lbu    v0, $0003(v0)
800C03B0	j      Lc03f4 [$800c03f4]
800C03B4	srl    v1, v0, $04
800C03B8	lui    v0, $8007
800C03BC	lbu    v0, $22c4(v0)
800C03C0	nop
800C03C4	sll    v0, v0, $01
800C03C8	lui    at, $8008
800C03CC	addiu  at, at, $31fc
800C03D0	addu   at, at, v0
800C03D4	lhu    v1, $0000(at)
800C03D8	lui    v0, $800a
800C03DC	lw     v0, $c6dc(v0)
800C03E0	nop
800C03E4	addu   v0, v0, v1
800C03E8	lbu    v0, $0003(v0)
800C03EC	nop
800C03F0	andi   v1, v0, $000f

Lc03f4:	; 800C03F4
800C03F4	andi   v0, v1, $00ff
800C03F8	addiu  a0, v0, $ffff (=-$1)
800C03FC	sltiu  v0, a0, $000f
800C0400	beq    v0, zero, Lc0b08 [$800c0b08]
800C0404	sll    v0, a0, $02
800C0408	lui    at, $800a

Lc040c:	; 800C040C
800C040C	addiu  at, at, $0484
800C0410	addu   at, at, v0
800C0414	lw     v0, $0000(at)
800C0418	nop
800C041C	jr     v0 
800C0420	nop

800C0424	lui    v0, $8007
800C0428	lbu    v0, $22c4(v0)
800C042C	sll    v1, a1, $10
800C0430	sll    v0, v0, $01
800C0434	lui    at, $8008
800C0438	addiu  at, at, $31fc
800C043C	addu   at, at, v0
800C0440	lhu    a0, $0000(at)
800C0444	lui    v0, $800a
800C0448	lw     v0, $c6dc(v0)
800C044C	sra    v1, v1, $10
800C0450	addu   v0, v0, a0
800C0454	addu   v0, v0, v1
800C0458	lbu    a1, $0000(v0)
800C045C	nop
800C0460	lui    at, $800a
800C0464	addiu  at, at, $d288 (=-$2d78)
800C0468	addu   at, at, a1
800C046C	sb     s0, $0000(at)
800C0470	lui    v0, $800a
800C0474	lbu    v0, $d820(v0)
800C0478	nop
800C047C	andi   v0, v0, $0003
800C0480	beq    v0, zero, Lc0b40 [$800c0b40]
800C0484	nop
800C0488	lui    a0, $800a
800C048C	addiu  a0, a0, $0394
800C0490	jal    funcbeca4 [$800beca4]
800C0494	ori    a2, zero, $0004
800C0498	lui    a0, $800a
800C049C	addiu  a0, a0, $039c
800C04A0	j      Lc0a50 [$800c0a50]
800C04A4	sll    a1, s0, $10
800C04A8	lui    v0, $8007
800C04AC	lbu    v0, $22c4(v0)
800C04B0	sll    v1, a1, $10
800C04B4	sll    v0, v0, $01
800C04B8	lui    at, $8008
800C04BC	addiu  at, at, $31fc
800C04C0	addu   at, at, v0
800C04C4	lhu    a0, $0000(at)
800C04C8	lui    v0, $800a
800C04CC	lw     v0, $c6dc(v0)
800C04D0	sra    v1, v1, $10
800C04D4	addu   v0, v0, a0
800C04D8	addu   v0, v0, v1
800C04DC	sll    v1, s0, $10
800C04E0	lbu    a1, $0000(v0)
800C04E4	srl    v0, v1, $18
800C04E8	lui    at, $800a
800C04EC	addiu  at, at, $d288 (=-$2d78)
800C04F0	addu   at, at, a1
800C04F4	sb     s0, $0000(at)
800C04F8	lui    at, $800a
800C04FC	addiu  at, at, $d289 (=-$2d77)
800C0500	addu   at, at, a1
800C0504	sb     v0, $0000(at)
800C0508	lui    v0, $800a
800C050C	lbu    v0, $d820(v0)

Lc0510:	; 800C0510
800C0510	nop
800C0514	andi   v0, v0, $0003
800C0518	beq    v0, zero, Lc0b40 [$800c0b40]
800C051C	sra    s0, v1, $10
800C0520	lui    a0, $800a
800C0524	addiu  a0, a0, $0394
800C0528	jal    funcbeca4 [$800beca4]
800C052C	ori    a2, zero, $0004
800C0530	lui    a0, $800a
800C0534	addiu  a0, a0, $039c
800C0538	j      Lc0af8 [$800c0af8]
800C053C	addu   a1, s0, zero
800C0540	lui    v0, $8007
800C0544	lbu    v0, $22c4(v0)
800C0548	sll    v1, a1, $10
800C054C	sll    v0, v0, $01
800C0550	lui    at, $8008
800C0554	addiu  at, at, $31fc
800C0558	addu   at, at, v0
800C055C	lhu    a0, $0000(at)
800C0560	lui    v0, $800a
800C0564	lw     v0, $c6dc(v0)
800C0568	sra    v1, v1, $10
800C056C	addu   v0, v0, a0
800C0570	addu   v0, v0, v1
800C0574	lbu    v0, $0000(v0)
800C0578	nop
800C057C	ori    a1, v0, $0100
800C0580	lui    at, $800a
800C0584	addiu  at, at, $d288 (=-$2d78)
800C0588	addu   at, at, a1
800C058C	sb     s0, $0000(at)
800C0590	lui    v0, $800a
800C0594	lbu    v0, $d820(v0)
800C0598	nop
800C059C	andi   v0, v0, $0003
800C05A0	beq    v0, zero, Lc0b40 [$800c0b40]
800C05A4	nop
800C05A8	lui    a0, $800a
800C05AC	addiu  a0, a0, $0394
800C05B0	jal    funcbeca4 [$800beca4]
800C05B4	ori    a2, zero, $0004
800C05B8	lui    a0, $800a
800C05BC	addiu  a0, a0, $039c
800C05C0	j      Lc0a50 [$800c0a50]
800C05C4	sll    a1, s0, $10
800C05C8	lui    v0, $8007
800C05CC	lbu    v0, $22c4(v0)
800C05D0	sll    v1, a1, $10
800C05D4	sll    v0, v0, $01
800C05D8	lui    at, $8008
800C05DC	addiu  at, at, $31fc
800C05E0	addu   at, at, v0
800C05E4	lhu    a0, $0000(at)
800C05E8	lui    v0, $800a
800C05EC	lw     v0, $c6dc(v0)
800C05F0	sra    v1, v1, $10
800C05F4	addu   v0, v0, a0
800C05F8	addu   v0, v0, v1
800C05FC	sll    a0, s0, $10
800C0600	lbu    v0, $0000(v0)
800C0604	srl    v1, a0, $18
800C0608	ori    a1, v0, $0100
800C060C	lui    at, $800a
800C0610	addiu  at, at, $d288 (=-$2d78)
800C0614	addu   at, at, a1
800C0618	sb     s0, $0000(at)
800C061C	lui    at, $800a
800C0620	addiu  at, at, $d289 (=-$2d77)
800C0624	addu   at, at, a1
800C0628	sb     v1, $0000(at)
800C062C	lui    v0, $800a
800C0630	lbu    v0, $d820(v0)
800C0634	nop
800C0638	andi   v0, v0, $0003
800C063C	beq    v0, zero, Lc0b40 [$800c0b40]
800C0640	sra    s0, a0, $10
800C0644	lui    a0, $800a
800C0648	addiu  a0, a0, $0394
800C064C	jal    funcbeca4 [$800beca4]
800C0650	ori    a2, zero, $0004
800C0654	lui    a0, $800a
800C0658	addiu  a0, a0, $039c
800C065C	j      Lc0af8 [$800c0af8]
800C0660	addu   a1, s0, zero
800C0664	lui    v0, $8007
800C0668	lbu    v0, $22c4(v0)
800C066C	sll    v1, a1, $10
800C0670	sll    v0, v0, $01
800C0674	lui    at, $8008
800C0678	addiu  at, at, $31fc
800C067C	addu   at, at, v0
800C0680	lhu    a0, $0000(at)
800C0684	lui    v0, $800a
800C0688	lw     v0, $c6dc(v0)
800C068C	sra    v1, v1, $10
800C0690	addu   v0, v0, a0
800C0694	addu   v0, v0, v1
800C0698	lbu    v0, $0000(v0)
800C069C	nop
800C06A0	ori    a1, v0, $0200
800C06A4	lui    at, $800a
800C06A8	addiu  at, at, $d288 (=-$2d78)
800C06AC	addu   at, at, a1
800C06B0	sb     s0, $0000(at)
800C06B4	lui    v0, $800a
800C06B8	lbu    v0, $d820(v0)
800C06BC	nop
800C06C0	andi   v0, v0, $0003
800C06C4	beq    v0, zero, Lc0b40 [$800c0b40]
800C06C8	nop
800C06CC	lui    a0, $800a
800C06D0	addiu  a0, a0, $0394
800C06D4	jal    funcbeca4 [$800beca4]
800C06D8	ori    a2, zero, $0004
800C06DC	lui    a0, $800a
800C06E0	addiu  a0, a0, $039c
800C06E4	j      Lc0a50 [$800c0a50]
800C06E8	sll    a1, s0, $10
800C06EC	lui    v0, $8007
800C06F0	lbu    v0, $22c4(v0)
800C06F4	sll    v1, a1, $10
800C06F8	sll    v0, v0, $01
800C06FC	lui    at, $8008
800C0700	addiu  at, at, $31fc
800C0704	addu   at, at, v0
800C0708	lhu    a0, $0000(at)
800C070C	lui    v0, $800a
800C0710	lw     v0, $c6dc(v0)
800C0714	sra    v1, v1, $10
800C0718	addu   v0, v0, a0
800C071C	addu   v0, v0, v1
800C0720	sll    a0, s0, $10
800C0724	lbu    v0, $0000(v0)
800C0728	srl    v1, a0, $18
800C072C	ori    a1, v0, $0200
800C0730	lui    at, $800a
800C0734	addiu  at, at, $d288 (=-$2d78)
800C0738	addu   at, at, a1
800C073C	sb     s0, $0000(at)
800C0740	lui    at, $800a
800C0744	addiu  at, at, $d289 (=-$2d77)
800C0748	addu   at, at, a1
800C074C	sb     v1, $0000(at)
800C0750	lui    v0, $800a
800C0754	lbu    v0, $d820(v0)
800C0758	nop
800C075C	andi   v0, v0, $0003
800C0760	beq    v0, zero, Lc0b40 [$800c0b40]
800C0764	sra    s0, a0, $10
800C0768	lui    a0, $800a
800C076C	addiu  a0, a0, $0394
800C0770	jal    funcbeca4 [$800beca4]

funcc0774:	; 800C0774
800C0774	ori    a2, zero, $0004
800C0778	lui    a0, $800a
800C077C	addiu  a0, a0, $039c
800C0780	j      Lc0af8 [$800c0af8]
800C0784	addu   a1, s0, zero
800C0788	lui    v0, $8007
800C078C	lbu    v0, $22c4(v0)
800C0790	sll    v1, a1, $10
800C0794	sll    v0, v0, $01
800C0798	lui    at, $8008
800C079C	addiu  at, at, $31fc
800C07A0	addu   at, at, v0
800C07A4	lhu    a0, $0000(at)
800C07A8	lui    v0, $800a
800C07AC	lw     v0, $c6dc(v0)
800C07B0	sra    v1, v1, $10
800C07B4	addu   v0, v0, a0
800C07B8	addu   v0, v0, v1
800C07BC	lbu    v0, $0000(v0)
800C07C0	nop
800C07C4	ori    a1, v0, $0300
800C07C8	lui    at, $800a
800C07CC	addiu  at, at, $d288 (=-$2d78)
800C07D0	addu   at, at, a1
800C07D4	sb     s0, $0000(at)
800C07D8	lui    v0, $800a
800C07DC	lbu    v0, $d820(v0)
800C07E0	nop
800C07E4	andi   v0, v0, $0003
800C07E8	beq    v0, zero, Lc0b40 [$800c0b40]
800C07EC	nop
800C07F0	lui    a0, $800a
800C07F4	addiu  a0, a0, $0394
800C07F8	jal    funcbeca4 [$800beca4]
800C07FC	ori    a2, zero, $0004
800C0800	lui    a0, $800a
800C0804	addiu  a0, a0, $039c
800C0808	j      Lc0a50 [$800c0a50]
800C080C	sll    a1, s0, $10
800C0810	lui    v0, $8007
800C0814	lbu    v0, $22c4(v0)
800C0818	sll    v1, a1, $10
800C081C	sll    v0, v0, $01
800C0820	lui    at, $8008
800C0824	addiu  at, at, $31fc
800C0828	addu   at, at, v0
800C082C	lhu    a0, $0000(at)
800C0830	lui    v0, $800a
800C0834	lw     v0, $c6dc(v0)
800C0838	sra    v1, v1, $10
800C083C	addu   v0, v0, a0
800C0840	addu   v0, v0, v1
800C0844	sll    a0, s0, $10
800C0848	lbu    v0, $0000(v0)
800C084C	srl    v1, a0, $18

Lc0850:	; 800C0850
800C0850	ori    a1, v0, $0300
800C0854	lui    at, $800a
800C0858	addiu  at, at, $d288 (=-$2d78)
800C085C	addu   at, at, a1
800C0860	sb     s0, $0000(at)
800C0864	lui    at, $800a
800C0868	addiu  at, at, $d289 (=-$2d77)
800C086C	addu   at, at, a1
800C0870	sb     v1, $0000(at)
800C0874	lui    v0, $800a
800C0878	lbu    v0, $d820(v0)
800C087C	nop
800C0880	andi   v0, v0, $0003
800C0884	beq    v0, zero, Lc0b40 [$800c0b40]
800C0888	sra    s0, a0, $10
800C088C	lui    a0, $800a
800C0890	addiu  a0, a0, $0394
800C0894	jal    funcbeca4 [$800beca4]
800C0898	ori    a2, zero, $0004
800C089C	lui    a0, $800a
800C08A0	addiu  a0, a0, $039c
800C08A4	j      Lc0af8 [$800c0af8]
800C08A8	addu   a1, s0, zero
800C08AC	lui    v0, $8007
800C08B0	lbu    v0, $22c4(v0)
800C08B4	sll    v1, a1, $10
800C08B8	sll    v0, v0, $01
800C08BC	lui    at, $8008
800C08C0	addiu  at, at, $31fc
800C08C4	addu   at, at, v0
800C08C8	lhu    a0, $0000(at)
800C08CC	lui    v0, $800a
800C08D0	lw     v0, $c6dc(v0)
800C08D4	sra    v1, v1, $10
800C08D8	addu   v0, v0, a0
800C08DC	addu   v0, v0, v1
800C08E0	lbu    v0, $0000(v0)
800C08E4	nop
800C08E8	ori    a1, v0, $0400
800C08EC	lui    at, $800a
800C08F0	addiu  at, at, $d288 (=-$2d78)
800C08F4	addu   at, at, a1
800C08F8	sb     s0, $0000(at)
800C08FC	lui    v0, $800a
800C0900	lbu    v0, $d820(v0)
800C0904	nop
800C0908	andi   v0, v0, $0003
800C090C	beq    v0, zero, Lc0b40 [$800c0b40]
800C0910	nop
800C0914	lui    a0, $800a
800C0918	addiu  a0, a0, $0394
800C091C	jal    funcbeca4 [$800beca4]
800C0920	ori    a2, zero, $0004
800C0924	lui    a0, $800a
800C0928	addiu  a0, a0, $039c
800C092C	j      Lc0a50 [$800c0a50]
800C0930	sll    a1, s0, $10
800C0934	lui    v0, $8007
800C0938	lbu    v0, $22c4(v0)
800C093C	sll    v1, a1, $10
800C0940	sll    v0, v0, $01
800C0944	lui    at, $8008
800C0948	addiu  at, at, $31fc
800C094C	addu   at, at, v0
800C0950	lhu    a0, $0000(at)
800C0954	lui    v0, $800a
800C0958	lw     v0, $c6dc(v0)
800C095C	sra    v1, v1, $10
800C0960	addu   v0, v0, a0
800C0964	addu   v0, v0, v1
800C0968	sll    a0, s0, $10
800C096C	lbu    v0, $0000(v0)
800C0970	srl    v1, a0, $18
800C0974	ori    a1, v0, $0400
800C0978	lui    at, $800a
800C097C	addiu  at, at, $d288 (=-$2d78)
800C0980	addu   at, at, a1
800C0984	sb     s0, $0000(at)
800C0988	lui    at, $800a
800C098C	addiu  at, at, $d289 (=-$2d77)
800C0990	addu   at, at, a1
800C0994	sb     v1, $0000(at)
800C0998	lui    v0, $800a
800C099C	lbu    v0, $d820(v0)
800C09A0	nop
800C09A4	andi   v0, v0, $0003
800C09A8	beq    v0, zero, Lc0b40 [$800c0b40]
800C09AC	sra    s0, a0, $10
800C09B0	lui    a0, $800a
800C09B4	addiu  a0, a0, $0394
800C09B8	jal    funcbeca4 [$800beca4]
800C09BC	ori    a2, zero, $0004
800C09C0	lui    a0, $800a
800C09C4	addiu  a0, a0, $039c
800C09C8	j      Lc0af8 [$800c0af8]
800C09CC	addu   a1, s0, zero
800C09D0	lui    v0, $8007
800C09D4	lbu    v0, $22c4(v0)
800C09D8	sll    v1, a1, $10
800C09DC	sll    v0, v0, $01
800C09E0	lui    at, $8008
800C09E4	addiu  at, at, $31fc
800C09E8	addu   at, at, v0
800C09EC	lhu    a0, $0000(at)
800C09F0	lui    v0, $800a
800C09F4	lw     v0, $c6dc(v0)
800C09F8	sra    v1, v1, $10
800C09FC	addu   v0, v0, a0
800C0A00	addu   v0, v0, v1
800C0A04	lbu    a1, $0000(v0)
800C0A08	nop
800C0A0C	lui    at, $8007
800C0A10	addiu  at, at, $5e24
800C0A14	addu   at, at, a1
800C0A18	sb     s0, $0000(at)
800C0A1C	lui    v0, $800a
800C0A20	lbu    v0, $d820(v0)
800C0A24	nop
800C0A28	andi   v0, v0, $0003
800C0A2C	beq    v0, zero, Lc0b40 [$800c0b40]
800C0A30	nop
800C0A34	lui    a0, $800a
800C0A38	addiu  a0, a0, $0394
800C0A3C	jal    funcbeca4 [$800beca4]
800C0A40	ori    a2, zero, $0004
800C0A44	lui    a0, $800a
800C0A48	addiu  a0, a0, $03a4
800C0A4C	sll    a1, s0, $10

Lc0a50:	; 800C0A50
800C0A50	sra    a1, a1, $10
800C0A54	jal    funcbeca4 [$800beca4]
800C0A58	ori    a2, zero, $0002
800C0A5C	j      Lc0b40 [$800c0b40]
800C0A60	nop
800C0A64	lui    v0, $8007
800C0A68	lbu    v0, $22c4(v0)
800C0A6C	sll    v1, a1, $10
800C0A70	sll    v0, v0, $01
800C0A74	lui    at, $8008
800C0A78	addiu  at, at, $31fc
800C0A7C	addu   at, at, v0
800C0A80	lhu    a0, $0000(at)
800C0A84	lui    v0, $800a
800C0A88	lw     v0, $c6dc(v0)
800C0A8C	sra    v1, v1, $10
800C0A90	addu   v0, v0, a0
800C0A94	addu   v0, v0, v1
800C0A98	sll    v1, s0, $10
800C0A9C	lbu    a1, $0000(v0)
800C0AA0	srl    v0, v1, $18
800C0AA4	lui    at, $8007
800C0AA8	addiu  at, at, $5e24
800C0AAC	addu   at, at, a1
800C0AB0	sb     s0, $0000(at)
800C0AB4	lui    at, $8007
800C0AB8	addiu  at, at, $5e25
800C0ABC	addu   at, at, a1
800C0AC0	sb     v0, $0000(at)
800C0AC4	lui    v0, $800a
800C0AC8	lbu    v0, $d820(v0)
800C0ACC	nop
800C0AD0	andi   v0, v0, $0003
800C0AD4	beq    v0, zero, Lc0b40 [$800c0b40]
800C0AD8	sra    s0, v1, $10
800C0ADC	lui    a0, $800a
800C0AE0	addiu  a0, a0, $0394
800C0AE4	jal    funcbeca4 [$800beca4]
800C0AE8	ori    a2, zero, $0004
800C0AEC	lui    a0, $800a
800C0AF0	addiu  a0, a0, $03a4
800C0AF4	addu   a1, s0, zero

Lc0af8:	; 800C0AF8
800C0AF8	jal    funcbeca4 [$800beca4]
800C0AFC	ori    a2, zero, $0004
800C0B00	j      Lc0b40 [$800c0b40]
800C0B04	nop

Lc0b08:	; 800C0B08
800C0B08	lui    v0, $800a
800C0B0C	lbu    v0, $d820(v0)
800C0B10	nop
800C0B14	andi   v0, v0, $0003
800C0B18	beq    v0, zero, Lc0b30 [$800c0b30]
800C0B1C	andi   a1, v1, $00ff
800C0B20	lui    a0, $800a
800C0B24	addiu  a0, a0, $03ac
800C0B28	jal    funcbeca4 [$800beca4]
800C0B2C	ori    a2, zero, $0002

Lc0b30:	; 800C0B30
800C0B30	lui    a0, $800a
800C0B34	addiu  a0, a0, $032c
800C0B38	jal    funcd4848 [$800d4848]
800C0B3C	nop

Lc0b40:	; 800C0B40
800C0B40	lw     ra, $0014(sp)
800C0B44	lw     s0, $0010(sp)
800C0B48	addiu  sp, sp, $0018
800C0B4C	jr     ra 
800C0B50	nop
////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// read_memory_block_two_bytes
//A0 - memory bank halfbyte 0x0F (always start after opcode itself)
//A1 - offset to byte offset in opcode
800BF908	addiu  sp, sp, $ffe8 (=-$18)
800BF90C	addiu  a0, a0, $ffff (=-$1)
800BF910	sll    a0, a0, $10
800BF914	sra    a0, a0, $10
800BF918	sltiu  v0, a0, $0006
800BF91C	sw     ra, $0014(sp)
800BF920	beq    v0, zero, Lbfab0 [$800bfab0]  // skip halfbyte reading if halfbyte number >6
800BF924	sw     s0, $0010(sp)
800BF928	sll    v0, a0, $02
800BF92C	lui    at, $800a
800BF930	addiu  at, at, $0414
800BF934	addu   at, at, v0
800BF938	lw     v0, $0000(at)
800BF93C	nop
800BF940	jr     v0 
800BF944	nop

// halfbyte 1
800BF948	lui    v0, $8007
800BF94C	lbu    v0, $22c4(v0)
800BF950	nop
800BF954	sll    v0, v0, $01
800BF958	lui    at, $8008
800BF95C	addiu  at, at, $31fc
800BF960	addu   at, at, v0
800BF964	lhu    v1, $0000(at)
800BF968	lui    v0, $800a
800BF96C	lw     v0, $c6dc(v0)
800BF970	nop
800BF974	addu   v0, v0, v1
800BF978	lbu    v0, $0001(v0)
800BF97C	j      Lbfab0 [$800bfab0]
800BF980	srl    v1, v0, $04

// halfbyte 2
800BF984	lui    v0, $8007
800BF988	lbu    v0, $22c4(v0)
800BF98C	nop
800BF990	sll    v0, v0, $01
800BF994	lui    at, $8008
800BF998	addiu  at, at, $31fc
800BF99C	addu   at, at, v0
800BF9A0	lhu    v1, $0000(at)
800BF9A4	lui    v0, $800a
800BF9A8	lw     v0, $c6dc(v0)
800BF9AC	nop
800BF9B0	addu   v0, v0, v1
800BF9B4	lbu    v0, $0001(v0)
800BF9B8	j      Lbfab0 [$800bfab0]
800BF9BC	andi   v1, v0, $000f

// halfbyte 3
800BF9C0	lui    v0, $8007
800BF9C4	lbu    v0, $22c4(v0)
800BF9C8	nop
800BF9CC	sll    v0, v0, $01
800BF9D0	lui    at, $8008
800BF9D4	addiu  at, at, $31fc
800BF9D8	addu   at, at, v0
800BF9DC	lhu    v1, $0000(at)
800BF9E0	lui    v0, $800a
800BF9E4	lw     v0, $c6dc(v0)
800BF9E8	nop
800BF9EC	addu   v0, v0, v1
800BF9F0	lbu    v0, $0002(v0)
800BF9F4	j      Lbfab0 [$800bfab0]
800BF9F8	srl    v1, v0, $04

// halfbyte 4
800BF9FC	lui    v0, $8007
800BFA00	lbu    v0, $22c4(v0)
800BFA04	nop
800BFA08	sll    v0, v0, $01
800BFA0C	lui    at, $8008
800BFA10	addiu  at, at, $31fc
800BFA14	addu   at, at, v0
800BFA18	lhu    v1, $0000(at)
800BFA1C	lui    v0, $800a
800BFA20	lw     v0, $c6dc(v0)
800BFA24	nop
800BFA28	addu   v0, v0, v1
800BFA2C	lbu    v0, $0002(v0)
800BFA30	j      Lbfab0 [$800bfab0]
800BFA34	andi   v1, v0, $000f

// halfbyte 5
800BFA38	lui    v0, $8007
800BFA3C	lbu    v0, $22c4(v0)
800BFA40	nop
800BFA44	sll    v0, v0, $01
800BFA48	lui    at, $8008
800BFA4C	addiu  at, at, $31fc
800BFA50	addu   at, at, v0
800BFA54	lhu    v1, $0000(at)
800BFA58	lui    v0, $800a
800BFA5C	lw     v0, $c6dc(v0)
800BFA60	nop
800BFA64	addu   v0, v0, v1
800BFA68	lbu    v0, $0003(v0)
800BFA6C	j      Lbfab0 [$800bfab0]
800BFA70	srl    v1, v0, $04

// halfbyte 6
800BFA74	lui    v0, $8007
800BFA78	lbu    v0, $22c4(v0)
800BFA7C	nop
800BFA80	sll    v0, v0, $01
800BFA84	lui    at, $8008
800BFA88	addiu  at, at, $31fc
800BFA8C	addu   at, at, v0
800BFA90	lhu    v1, $0000(at)
800BFA94	lui    v0, $800a
800BFA98	lw     v0, $c6dc(v0)
800BFA9C	nop
800BFAA0	addu   v0, v0, v1
800BFAA4	lbu    v0, $0003(v0)
800BFAA8	nop
800BFAAC	andi   v1, v0, $000f

// select memory bank access function
Lbfab0:	; 800BFAB0
800BFAB0	andi   a0, v1, $00ff
800BFAB4	sltiu  v0, a0, $0010
800BFAB8	beq    v0, zero, Lc01f8 [$800c01f8]  // if memory block > 0xF skip memory bank reading
800BFABC	sll    v0, a0, $02
800BFAC0	lui    at, $800a
800BFAC4	addiu  at, at, $042c
800BFAC8	addu   at, at, v0
800BFACC	lw     v0, $0000(at)
800BFAD0	nop
800BFAD4	jr     v0 
800BFAD8	nop

// memory bank 0
800BFADC	lui    v0, $8007
800BFAE0	lbu    v0, $22c4(v0)
800BFAE4	sll    v1, a1, $10
800BFAE8	sll    v0, v0, $01
800BFAEC	lui    at, $8008
800BFAF0	addiu  at, at, $31fc
800BFAF4	addu   at, at, v0
800BFAF8	lhu    a0, $0000(at)
800BFAFC	lui    v0, $800a
800BFB00	lw     v0, $c6dc(v0)
800BFB04	sra    v1, v1, $10
800BFB08	addu   v0, v0, a0
800BFB0C	addu   v0, v0, v1
800BFB10	lbu    v1, $0001(v0)
800BFB14	lbu    s0, $0000(v0)
800BFB18	lui    v0, $800a
800BFB1C	lbu    v0, $d820(v0)
800BFB20	sll    v1, v1, $08
800BFB24	andi   v0, v0, $0003
800BFB28	beq    v0, zero, Lc01ec [$800c01ec]
800BFB2C	or     s0, s0, v1
800BFB30	lui    a0, $800a
800BFB34	addiu  a0, a0, $0300
800BFB38	j      Lc01e0 [$800c01e0]
800BFB3C	sll    a1, s0, $10

// memory bank 1
800BFB40	lui    v0, $8007
800BFB44	lbu    v0, $22c4(v0)
800BFB48	sll    v1, a1, $10
800BFB4C	sll    v0, v0, $01
800BFB50	lui    at, $8008
800BFB54	addiu  at, at, $31fc
800BFB58	addu   at, at, v0
800BFB5C	lhu    a0, $0000(at)
800BFB60	lui    v0, $800a
800BFB64	lw     v0, $c6dc(v0)
800BFB68	sra    v1, v1, $10
800BFB6C	addu   v0, v0, a0
800BFB70	addu   v0, v0, v1
800BFB74	lbu    a1, $0000(v0)
800BFB78	lui    v0, $800a
800BFB7C	lbu    v0, $d820(v0)
800BFB80	nop
800BFB84	andi   v0, v0, $0003
800BFB88	lui    at, $800a
800BFB8C	addiu  at, at, $d288 (=-$2d78)
800BFB90	addu   at, at, a1
800BFB94	lbu    s0, $0000(at)
800BFB98	beq    v0, zero, Lc0234 [$800c0234]
800BFB9C	addu   v0, s0, zero
800BFBA0	lui    a0, $800a
800BFBA4	addiu  a0, a0, $0308
800BFBA8	jal    funcbeca4 [$800beca4]
800BFBAC	ori    a2, zero, $0004
800BFBB0	lui    a0, $800a
800BFBB4	addiu  a0, a0, $0310
800BFBB8	j      Lc0140 [$800c0140]
800BFBBC	addu   a1, s0, zero

// memory bank 2
800BFBC0	lui    v0, $8007
800BFBC4	lbu    v0, $22c4(v0)
800BFBC8	sll    v1, a1, $10
800BFBCC	sll    v0, v0, $01
800BFBD0	lui    at, $8008
800BFBD4	addiu  at, at, $31fc
800BFBD8	addu   at, at, v0
800BFBDC	lhu    a0, $0000(at)
800BFBE0	lui    v0, $800a
800BFBE4	lw     v0, $c6dc(v0)
800BFBE8	sra    v1, v1, $10
800BFBEC	addu   v0, v0, a0
800BFBF0	addu   v0, v0, v1
800BFBF4	lbu    a1, $0000(v0)
800BFBF8	lui    v0, $800a
800BFBFC	lbu    v0, $d820(v0)
800BFC00	nop
800BFC04	andi   v0, v0, $0003
800BFC08	lui    at, $800a
800BFC0C	addiu  at, at, $d289 (=-$2d77)
800BFC10	addu   at, at, a1
800BFC14	lbu    v1, $0000(at)
800BFC18	lui    at, $800a
800BFC1C	addiu  at, at, $d288 (=-$2d78)
800BFC20	addu   at, at, a1
800BFC24	lbu    s0, $0000(at)
800BFC28	sll    v1, v1, $08
800BFC2C	beq    v0, zero, Lc01ec [$800c01ec]
800BFC30	or     s0, s0, v1
800BFC34	lui    a0, $800a
800BFC38	addiu  a0, a0, $0308
800BFC3C	jal    funcbeca4 [$800beca4]
800BFC40	ori    a2, zero, $0004
800BFC44	lui    a0, $800a
800BFC48	addiu  a0, a0, $0310
800BFC4C	j      Lc01e0 [$800c01e0]
800BFC50	sll    a1, s0, $10

// memory bank 3
800BFC54	lui    v0, $8007
800BFC58	lbu    v0, $22c4(v0)
800BFC5C	sll    v1, a1, $10
800BFC60	sll    v0, v0, $01
800BFC64	lui    at, $8008
800BFC68	addiu  at, at, $31fc
800BFC6C	addu   at, at, v0
800BFC70	lhu    a0, $0000(at)
800BFC74	lui    v0, $800a
800BFC78	lw     v0, $c6dc(v0)
800BFC7C	sra    v1, v1, $10
800BFC80	addu   v0, v0, a0
800BFC84	addu   v0, v0, v1
800BFC88	lbu    v0, $0000(v0)
800BFC8C	nop
800BFC90	ori    a1, v0, $0100
800BFC94	lui    v0, $800a
800BFC98	lbu    v0, $d820(v0)
800BFC9C	lui    at, $800a
800BFCA0	addiu  at, at, $d288 (=-$2d78)
800BFCA4	addu   at, at, a1
800BFCA8	lbu    s0, $0000(at)
800BFCAC	andi   v0, v0, $0003
800BFCB0	beq    v0, zero, Lc0234 [$800c0234]
800BFCB4	addu   v0, s0, zero
800BFCB8	lui    a0, $800a
800BFCBC	addiu  a0, a0, $0308
800BFCC0	jal    funcbeca4 [$800beca4]
800BFCC4	ori    a2, zero, $0004
800BFCC8	lui    a0, $800a
800BFCCC	addiu  a0, a0, $0310
800BFCD0	j      Lc0140 [$800c0140]
800BFCD4	addu   a1, s0, zero

// memory bank 4
800BFCD8	lui    v0, $8007
800BFCDC	lbu    v0, $22c4(v0)
800BFCE0	sll    v1, a1, $10
800BFCE4	sll    v0, v0, $01
800BFCE8	lui    at, $8008
800BFCEC	addiu  at, at, $31fc
800BFCF0	addu   at, at, v0
800BFCF4	lhu    a0, $0000(at)
800BFCF8	lui    v0, $800a
800BFCFC	lw     v0, $c6dc(v0)
800BFD00	sra    v1, v1, $10
800BFD04	addu   v0, v0, a0
800BFD08	addu   v0, v0, v1
800BFD0C	lbu    v0, $0000(v0)
800BFD10	nop
800BFD14	ori    a1, v0, $0100
800BFD18	lui    at, $800a
800BFD1C	addiu  at, at, $d289 (=-$2d77)
800BFD20	addu   at, at, a1
800BFD24	lbu    v1, $0000(at)
800BFD28	lui    at, $800a
800BFD2C	addiu  at, at, $d288 (=-$2d78)
800BFD30	addu   at, at, a1
800BFD34	lbu    s0, $0000(at)
800BFD38	lui    v0, $800a
800BFD3C	lbu    v0, $d820(v0)
800BFD40	sll    v1, v1, $08
800BFD44	andi   v0, v0, $0003
800BFD48	beq    v0, zero, Lc01ec [$800c01ec]
800BFD4C	or     s0, s0, v1
800BFD50	lui    a0, $800a
800BFD54	addiu  a0, a0, $0308
800BFD58	jal    funcbeca4 [$800beca4]
800BFD5C	ori    a2, zero, $0004
800BFD60	lui    a0, $800a
800BFD64	addiu  a0, a0, $0310
800BFD68	j      Lc01e0 [$800c01e0]
800BFD6C	sll    a1, s0, $10

// memory bank B
800BFD70	lui    v0, $8007
800BFD74	lbu    v0, $22c4(v0)
800BFD78	sll    v1, a1, $10
800BFD7C	sll    v0, v0, $01
800BFD80	lui    at, $8008
800BFD84	addiu  at, at, $31fc
800BFD88	addu   at, at, v0
800BFD8C	lhu    a0, $0000(at)
800BFD90	lui    v0, $800a
800BFD94	lw     v0, $c6dc(v0)
800BFD98	sra    v1, v1, $10
800BFD9C	addu   v0, v0, a0
800BFDA0	addu   v0, v0, v1
800BFDA4	lbu    v0, $0000(v0)
800BFDA8	nop
800BFDAC	ori    a1, v0, $0200
800BFDB0	lui    v0, $800a
800BFDB4	lbu    v0, $d820(v0)
800BFDB8	lui    at, $800a
800BFDBC	addiu  at, at, $d288 (=-$2d78)
800BFDC0	addu   at, at, a1
800BFDC4	lbu    s0, $0000(at)
800BFDC8	andi   v0, v0, $0003
800BFDCC	beq    v0, zero, Lc0234 [$800c0234]
800BFDD0	addu   v0, s0, zero
800BFDD4	lui    a0, $800a
800BFDD8	addiu  a0, a0, $0308
800BFDDC	jal    funcbeca4 [$800beca4]
800BFDE0	ori    a2, zero, $0004
800BFDE4	lui    a0, $800a
800BFDE8	addiu  a0, a0, $0310
800BFDEC	j      Lc0140 [$800c0140]
800BFDF0	addu   a1, s0, zero

// memory bank C
800BFDF4	lui    v0, $8007
800BFDF8	lbu    v0, $22c4(v0)
800BFDFC	sll    v1, a1, $10
800BFE00	sll    v0, v0, $01
800BFE04	lui    at, $8008
800BFE08	addiu  at, at, $31fc
800BFE0C	addu   at, at, v0
800BFE10	lhu    a0, $0000(at)
800BFE14	lui    v0, $800a
800BFE18	lw     v0, $c6dc(v0)
800BFE1C	sra    v1, v1, $10
800BFE20	addu   v0, v0, a0
800BFE24	addu   v0, v0, v1
800BFE28	lbu    v0, $0000(v0)
800BFE2C	nop
800BFE30	ori    a1, v0, $0200
800BFE34	lui    at, $800a
800BFE38	addiu  at, at, $d289 (=-$2d77)
800BFE3C	addu   at, at, a1
800BFE40	lbu    v1, $0000(at)
800BFE44	lui    at, $800a
800BFE48	addiu  at, at, $d288 (=-$2d78)
800BFE4C	addu   at, at, a1
800BFE50	lbu    s0, $0000(at)
800BFE54	lui    v0, $800a
800BFE58	lbu    v0, $d820(v0)
800BFE5C	sll    v1, v1, $08
800BFE60	andi   v0, v0, $0003
800BFE64	beq    v0, zero, Lc01ec [$800c01ec]
800BFE68	or     s0, s0, v1
800BFE6C	lui    a0, $800a
800BFE70	addiu  a0, a0, $0308
800BFE74	jal    funcbeca4 [$800beca4]
800BFE78	ori    a2, zero, $0004
800BFE7C	lui    a0, $800a
800BFE80	addiu  a0, a0, $0310
800BFE84	j      Lc01e0 [$800c01e0]
800BFE88	sll    a1, s0, $10

// memory bank D
800BFE8C	lui    v0, $8007
800BFE90	lbu    v0, $22c4(v0)
800BFE94	sll    v1, a1, $10
800BFE98	sll    v0, v0, $01
800BFE9C	lui    at, $8008
800BFEA0	addiu  at, at, $31fc
800BFEA4	addu   at, at, v0
800BFEA8	lhu    a0, $0000(at)
800BFEAC	lui    v0, $800a
800BFEB0	lw     v0, $c6dc(v0)
800BFEB4	sra    v1, v1, $10
800BFEB8	addu   v0, v0, a0
800BFEBC	addu   v0, v0, v1
800BFEC0	lbu    v0, $0000(v0)
800BFEC4	nop
800BFEC8	ori    a1, v0, $0300
800BFECC	lui    v0, $800a
800BFED0	lbu    v0, $d820(v0)
800BFED4	lui    at, $800a
800BFED8	addiu  at, at, $d288 (=-$2d78)
800BFEDC	addu   at, at, a1

funcbfee0:	; 800BFEE0
800BFEE0	lbu    s0, $0000(at)
800BFEE4	andi   v0, v0, $0003
800BFEE8	beq    v0, zero, Lc0234 [$800c0234]
800BFEEC	addu   v0, s0, zero
800BFEF0	lui    a0, $800a
800BFEF4	addiu  a0, a0, $0308
800BFEF8	jal    funcbeca4 [$800beca4]
800BFEFC	ori    a2, zero, $0004
800BFF00	lui    a0, $800a
800BFF04	addiu  a0, a0, $0310
800BFF08	j      Lc0140 [$800c0140]
800BFF0C	addu   a1, s0, zero

// memory bank E
800BFF10	lui    v0, $8007
800BFF14	lbu    v0, $22c4(v0)
800BFF18	sll    v1, a1, $10
800BFF1C	sll    v0, v0, $01
800BFF20	lui    at, $8008
800BFF24	addiu  at, at, $31fc
800BFF28	addu   at, at, v0
800BFF2C	lhu    a0, $0000(at)
800BFF30	lui    v0, $800a
800BFF34	lw     v0, $c6dc(v0)
800BFF38	sra    v1, v1, $10
800BFF3C	addu   v0, v0, a0
800BFF40	addu   v0, v0, v1
800BFF44	lbu    v0, $0000(v0)
800BFF48	nop
800BFF4C	ori    a1, v0, $0300
800BFF50	lui    at, $800a
800BFF54	addiu  at, at, $d289 (=-$2d77)
800BFF58	addu   at, at, a1
800BFF5C	lbu    v1, $0000(at)
800BFF60	lui    at, $800a
800BFF64	addiu  at, at, $d288 (=-$2d78)
800BFF68	addu   at, at, a1
800BFF6C	lbu    s0, $0000(at)
800BFF70	lui    v0, $800a
800BFF74	lbu    v0, $d820(v0)
800BFF78	sll    v1, v1, $08
800BFF7C	andi   v0, v0, $0003
800BFF80	beq    v0, zero, Lc01ec [$800c01ec]
800BFF84	or     s0, s0, v1
800BFF88	lui    a0, $800a
800BFF8C	addiu  a0, a0, $0308
800BFF90	jal    funcbeca4 [$800beca4]
800BFF94	ori    a2, zero, $0004
800BFF98	lui    a0, $800a
800BFF9C	addiu  a0, a0, $0310
800BFFA0	j      Lc01e0 [$800c01e0]
800BFFA4	sll    a1, s0, $10

// memory bank F
800BFFA8	lui    v0, $8007
800BFFAC	lbu    v0, $22c4(v0)
800BFFB0	sll    v1, a1, $10
800BFFB4	sll    v0, v0, $01
800BFFB8	lui    at, $8008
800BFFBC	addiu  at, at, $31fc
800BFFC0	addu   at, at, v0
800BFFC4	lhu    a0, $0000(at)
800BFFC8	lui    v0, $800a
800BFFCC	lw     v0, $c6dc(v0)
800BFFD0	sra    v1, v1, $10
800BFFD4	addu   v0, v0, a0
800BFFD8	addu   v0, v0, v1
800BFFDC	lbu    v0, $0000(v0)
800BFFE0	nop
800BFFE4	ori    a1, v0, $0400
800BFFE8	lui    v0, $800a
800BFFEC	lbu    v0, $d820(v0)
800BFFF0	lui    at, $800a
800BFFF4	addiu  at, at, $d288 (=-$2d78)
800BFFF8	addu   at, at, a1
800BFFFC	lbu    s0, $0000(at)
800C0000	andi   v0, v0, $0003
800C0004	beq    v0, zero, Lc0234 [$800c0234]
800C0008	addu   v0, s0, zero
800C000C	lui    a0, $800a
800C0010	addiu  a0, a0, $0308
800C0014	jal    funcbeca4 [$800beca4]
800C0018	ori    a2, zero, $0004
800C001C	lui    a0, $800a
800C0020	addiu  a0, a0, $0310
800C0024	j      Lc0140 [$800c0140]

Lc0028:	; 800C0028
800C0028	addu   a1, s0, zero

// memory bank 7
Lc002c:	; 800C002C
800C002C	lui    v0, $8007
800C0030	lbu    v0, $22c4(v0)

funcc0034:	; 800C0034
800C0034	sll    v1, a1, $10
800C0038	sll    v0, v0, $01
800C003C	lui    at, $8008
800C0040	addiu  at, at, $31fc
800C0044	addu   at, at, v0

Lc0048:	; 800C0048
800C0048	lhu    a0, $0000(at)
800C004C	lui    v0, $800a
800C0050	lw     v0, $c6dc(v0)
800C0054	sra    v1, v1, $10
800C0058	addu   v0, v0, a0
800C005C	addu   v0, v0, v1
800C0060	lbu    v0, $0000(v0)
800C0064	nop
800C0068	ori    a1, v0, $0400
800C006C	lui    at, $800a
800C0070	addiu  at, at, $d289 (=-$2d77)
800C0074	addu   at, at, a1
800C0078	lbu    v1, $0000(at)
800C007C	lui    at, $800a
800C0080	addiu  at, at, $d288 (=-$2d78)
800C0084	addu   at, at, a1
800C0088	lbu    s0, $0000(at)
800C008C	lui    v0, $800a
800C0090	lbu    v0, $d820(v0)
800C0094	sll    v1, v1, $08
800C0098	andi   v0, v0, $0003
800C009C	beq    v0, zero, Lc01ec [$800c01ec]
800C00A0	or     s0, s0, v1
800C00A4	lui    a0, $800a
800C00A8	addiu  a0, a0, $0308
800C00AC	jal    funcbeca4 [$800beca4]
800C00B0	ori    a2, zero, $0004
800C00B4	lui    a0, $800a
800C00B8	addiu  a0, a0, $0310
800C00BC	j      Lc01e0 [$800c01e0]
800C00C0	sll    a1, s0, $10

// memory bank 5
800C00C4	lui    v0, $8007
800C00C8	lbu    v0, $22c4(v0)
800C00CC	sll    v1, a1, $10
800C00D0	sll    v0, v0, $01
800C00D4	lui    at, $8008
800C00D8	addiu  at, at, $31fc
800C00DC	addu   at, at, v0
800C00E0	lhu    a0, $0000(at)
800C00E4	lui    v0, $800a
800C00E8	lw     v0, $c6dc(v0)
800C00EC	sra    v1, v1, $10
800C00F0	addu   v0, v0, a0
800C00F4	addu   v0, v0, v1
800C00F8	lbu    a1, $0000(v0)
800C00FC	lui    v0, $800a
800C0100	lbu    v0, $d820(v0)
800C0104	nop
800C0108	andi   v0, v0, $0003
800C010C	lui    at, $8007
800C0110	addiu  at, at, $5e24
800C0114	addu   at, at, a1
800C0118	lbu    s0, $0000(at)
800C011C	beq    v0, zero, Lc0234 [$800c0234]
800C0120	addu   v0, s0, zero
800C0124	lui    a0, $800a
800C0128	addiu  a0, a0, $0308
800C012C	jal    funcbeca4 [$800beca4]
800C0130	ori    a2, zero, $0004
800C0134	lui    a0, $800a
800C0138	addiu  a0, a0, $0318
800C013C	addu   a1, s0, zero

Lc0140:	; 800C0140
800C0140	jal    funcbeca4 [$800beca4]
800C0144	ori    a2, zero, $0004
800C0148	j      Lc0234 [$800c0234]
800C014C	addu   v0, s0, zero

// memory bank 6
800C0150	lui    v0, $8007
800C0154	lbu    v0, $22c4(v0)
800C0158	sll    v1, a1, $10
800C015C	sll    v0, v0, $01
800C0160	lui    at, $8008
800C0164	addiu  at, at, $31fc
800C0168	addu   at, at, v0

Lc016c:	; 800C016C
800C016C	lhu    a0, $0000(at)
800C0170	lui    v0, $800a
800C0174	lw     v0, $c6dc(v0)
800C0178	sra    v1, v1, $10
800C017C	addu   v0, v0, a0
800C0180	addu   v0, v0, v1
800C0184	lbu    a1, $0000(v0)
800C0188	lui    v0, $800a
800C018C	lbu    v0, $d820(v0)
800C0190	nop
800C0194	andi   v0, v0, $0003
800C0198	lui    at, $8007
800C019C	addiu  at, at, $5e25
800C01A0	addu   at, at, a1
800C01A4	lbu    v1, $0000(at)
800C01A8	lui    at, $8007
800C01AC	addiu  at, at, $5e24
800C01B0	addu   at, at, a1
800C01B4	lbu    s0, $0000(at)
800C01B8	sll    v1, v1, $08
800C01BC	beq    v0, zero, Lc01ec [$800c01ec]
800C01C0	or     s0, s0, v1
800C01C4	lui    a0, $800a
800C01C8	addiu  a0, a0, $0308
800C01CC	jal    funcbeca4 [$800beca4]
800C01D0	ori    a2, zero, $0004
800C01D4	lui    a0, $800a
800C01D8	addiu  a0, a0, $0318
800C01DC	sll    a1, s0, $10

Lc01e0:	; 800C01E0
800C01E0	sra    a1, a1, $10
800C01E4	jal    funcbeca4 [$800beca4]
800C01E8	ori    a2, zero, $0004

Lc01ec:	; 800C01EC
800C01EC	sll    v0, s0, $10
800C01F0	j      Lc0234 [$800c0234]
800C01F4	sra    v0, v0, $10

// memory bank 8, 9, A, >F
Lc01f8:	; 800C01F8
800C01F8	lui    v0, $800a
800C01FC	lbu    v0, $d820(v0)
800C0200	nop
800C0204	andi   v0, v0, $0003
800C0208	beq    v0, zero, Lc0220 [$800c0220]
800C020C	andi   a1, v1, $00ff
800C0210	lui    a0, $800a
800C0214	addiu  a0, a0, $0320
800C0218	jal    funcbeca4 [$800beca4]
800C021C	ori    a2, zero, $0002

Lc0220:	; 800C0220
800C0220	lui    a0, $800a
800C0224	addiu  a0, a0, $032c
800C0228	jal    funcd4848 [$800d4848]
800C022C	nop
800C0230	addu   v0, zero, zero

Lc0234:	; 800C0234
800C0234	lw     ra, $0014(sp)
800C0238	lw     s0, $0010(sp)
800C023C	addiu  sp, sp, $0018
800C0240	jr     ra 
800C0244	nop
//////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////
// read_memory_block_one_byte
//A0 - memory bank halfbyte 0x0F (always start after opcode itself)
//A1 - offset to byte offset in opcode
800BEE10	addiu  sp, sp, $ffe8 (=-$18)
800BEE14	addiu  a0, a0, $ffff (=-$1)
800BEE18	sll    a0, a0, $10
800BEE1C	sra    a0, a0, $10
800BEE20	sltiu  v0, a0, $0006
800BEE24	sw     ra, $0014(sp)
800BEE28	beq    v0, zero, Lbefb8 [$800befb8]  // skip halfbyte reading if halfbyte number > 6
800BEE2C	sw     s0, $0010(sp)
800BEE30	sll    v0, a0, $02
800BEE34	lui    at, $800a
800BEE38	addiu  at, at, $033c
800BEE3C	addu   at, at, v0
800BEE40	lw     v0, $0000(at)
800BEE44	nop
800BEE48	jr     v0 
800BEE4C	nop

// 1 halfbyte
800BEE50	lui    v0, $8007
800BEE54	lbu    v0, $22c4(v0)
800BEE58	nop
800BEE5C	sll    v0, v0, $01
800BEE60	lui    at, $8008
800BEE64	addiu  at, at, $31fc
800BEE68	addu   at, at, v0
800BEE6C	lhu    v1, $0000(at)
800BEE70	lui    v0, $800a
800BEE74	lw     v0, $c6dc(v0)
800BEE78	nop
800BEE7C	addu   v0, v0, v1
800BEE80	lbu    v0, $0001(v0)
800BEE84	j      Lbefb8 [$800befb8]
800BEE88	srl    v1, v0, $04

// 2 halfbyte
800BEE8C	lui    v0, $8007
800BEE90	lbu    v0, $22c4(v0)
800BEE94	nop
800BEE98	sll    v0, v0, $01
800BEE9C	lui    at, $8008
800BEEA0	addiu  at, at, $31fc
800BEEA4	addu   at, at, v0
800BEEA8	lhu    v1, $0000(at)
800BEEAC	lui    v0, $800a
800BEEB0	lw     v0, $c6dc(v0)
800BEEB4	nop
800BEEB8	addu   v0, v0, v1
800BEEBC	lbu    v0, $0001(v0)
800BEEC0	j      Lbefb8 [$800befb8]
800BEEC4	andi   v1, v0, $000f

// 3 halfbyte
800BEEC8	lui    v0, $8007
800BEECC	lbu    v0, $22c4(v0)
800BEED0	nop
800BEED4	sll    v0, v0, $01
800BEED8	lui    at, $8008
800BEEDC	addiu  at, at, $31fc
800BEEE0	addu   at, at, v0
800BEEE4	lhu    v1, $0000(at)
800BEEE8	lui    v0, $800a
800BEEEC	lw     v0, $c6dc(v0)
800BEEF0	nop
800BEEF4	addu   v0, v0, v1
800BEEF8	lbu    v0, $0002(v0)
800BEEFC	j      Lbefb8 [$800befb8]
800BEF00	srl    v1, v0, $04

// 4 halfbyte
800BEF04	lui    v0, $8007
800BEF08	lbu    v0, $22c4(v0)
800BEF0C	nop
800BEF10	sll    v0, v0, $01
800BEF14	lui    at, $8008
800BEF18	addiu  at, at, $31fc
800BEF1C	addu   at, at, v0
800BEF20	lhu    v1, $0000(at)
800BEF24	lui    v0, $800a
800BEF28	lw     v0, $c6dc(v0)
800BEF2C	nop
800BEF30	addu   v0, v0, v1
800BEF34	lbu    v0, $0002(v0)
800BEF38	j      Lbefb8 [$800befb8]
800BEF3C	andi   v1, v0, $000f

// 5 halfbyte
800BEF40	lui    v0, $8007
800BEF44	lbu    v0, $22c4(v0)
800BEF48	nop
800BEF4C	sll    v0, v0, $01
800BEF50	lui    at, $8008
800BEF54	addiu  at, at, $31fc
800BEF58	addu   at, at, v0
800BEF5C	lhu    v1, $0000(at)
800BEF60	lui    v0, $800a
800BEF64	lw     v0, $c6dc(v0)
800BEF68	nop
800BEF6C	addu   v0, v0, v1
800BEF70	lbu    v0, $0003(v0)
800BEF74	j      Lbefb8 [$800befb8]
800BEF78	srl    v1, v0, $04

// 6 halfbyte
800BEF7C	lui    v0, $8007
800BEF80	lbu    v0, $22c4(v0)
800BEF84	nop
800BEF88	sll    v0, v0, $01
800BEF8C	lui    at, $8008
800BEF90	addiu  at, at, $31fc
800BEF94	addu   at, at, v0
800BEF98	lhu    v1, $0000(at)
800BEF9C	lui    v0, $800a
800BEFA0	lw     v0, $c6dc(v0)
800BEFA4	nop
800BEFA8	addu   v0, v0, v1
800BEFAC	lbu    v0, $0003(v0)
800BEFB0	nop
800BEFB4	andi   v1, v0, $000f

Lbefb8:	; 800BEFB8
800BEFB8	andi   a0, v1, $00ff
800BEFBC	sltiu  v0, a0, $0010
800BEFC0	beq    v0, zero, Lbf35c [$800bf35c]
800BEFC4	sll    v0, a0, $02
800BEFC8	lui    at, $800a
800BEFCC	addiu  at, at, $0354
800BEFD0	addu   at, at, v0
800BEFD4	lw     v0, $0000(at)
800BEFD8	nop
800BEFDC	jr     v0 
800BEFE0	nop

// memory bank 0
800BEFE4	sll    a0, a1, $10
800BEFE8	lui    v0, $8007
800BEFEC	lbu    v0, $22c4(v0)
800BEFF0	lui    v1, $800a
800BEFF4	lw     v1, $c6dc(v1)
800BEFF8	sll    v0, v0, $01
800BEFFC	lui    at, $8008
800BF000	addiu  at, at, $31fc
800BF004	addu   at, at, v0
800BF008	lhu    v0, $0000(at)
800BF00C	sra    a0, a0, $10
800BF010	addu   v1, v1, v0
800BF014	addu   v1, v1, a0
800BF018	lui    v0, $800a
800BF01C	lbu    v0, $d820(v0)
800BF020	lbu    s0, $0000(v1)
800BF024	andi   v0, v0, $0003
800BF028	beq    v0, zero, Lbf398 [$800bf398]
800BF02C	addu   v0, s0, zero
800BF030	lui    a0, $800a
800BF034	addiu  a0, a0, $0300
800BF038	j      Lbf34c [$800bf34c]
800BF03C	addu   a1, s0, zero

// memory bank 1, 2
800BF040	lui    v0, $8007
800BF044	lbu    v0, $22c4(v0)
800BF048	sll    v1, a1, $10
800BF04C	sll    v0, v0, $01
800BF050	lui    at, $8008
800BF054	addiu  at, at, $31fc
800BF058	addu   at, at, v0
800BF05C	lhu    a0, $0000(at)
800BF060	lui    v0, $800a
800BF064	lw     v0, $c6dc(v0)
800BF068	sra    v1, v1, $10
800BF06C	addu   v0, v0, a0
800BF070	addu   v0, v0, v1
800BF074	lbu    a1, $0000(v0)
800BF078	lui    v0, $800a
800BF07C	lbu    v0, $d820(v0)
800BF080	nop
800BF084	andi   v0, v0, $0003
800BF088	lui    at, $800a
800BF08C	addiu  at, at, $d288 (=-$2d78)
800BF090	addu   at, at, a1
800BF094	lbu    s0, $0000(at)
800BF098	beq    v0, zero, Lbf398 [$800bf398]
800BF09C	addu   v0, s0, zero
800BF0A0	lui    a0, $800a
800BF0A4	addiu  a0, a0, $0308
800BF0A8	jal    funcbeca4 [$800beca4]
800BF0AC	ori    a2, zero, $0004
800BF0B0	lui    a0, $800a
800BF0B4	addiu  a0, a0, $0310
800BF0B8	j      Lbf34c [$800bf34c]
800BF0BC	addu   a1, s0, zero

// memory bank 3, 4
800BF0C0	lui    v0, $8007
800BF0C4	lbu    v0, $22c4(v0)
800BF0C8	sll    v1, a1, $10
800BF0CC	sll    v0, v0, $01
800BF0D0	lui    at, $8008
800BF0D4	addiu  at, at, $31fc
800BF0D8	addu   at, at, v0
800BF0DC	lhu    a0, $0000(at)
800BF0E0	lui    v0, $800a
800BF0E4	lw     v0, $c6dc(v0)
800BF0E8	sra    v1, v1, $10
800BF0EC	addu   v0, v0, a0
800BF0F0	addu   v0, v0, v1
800BF0F4	lbu    v0, $0000(v0)
800BF0F8	nop
800BF0FC	ori    a1, v0, $0100
800BF100	lui    v0, $800a
800BF104	lbu    v0, $d820(v0)
800BF108	lui    at, $800a
800BF10C	addiu  at, at, $d288 (=-$2d78)
800BF110	addu   at, at, a1
800BF114	lbu    s0, $0000(at)
800BF118	andi   v0, v0, $0003
800BF11C	beq    v0, zero, Lbf398 [$800bf398]
800BF120	addu   v0, s0, zero
800BF124	lui    a0, $800a
800BF128	addiu  a0, a0, $0308
800BF12C	jal    funcbeca4 [$800beca4]
800BF130	ori    a2, zero, $0004
800BF134	lui    a0, $800a
800BF138	addiu  a0, a0, $0310
800BF13C	j      Lbf34c [$800bf34c]
800BF140	addu   a1, s0, zero

// memory bank B, C
800BF144	lui    v0, $8007
800BF148	lbu    v0, $22c4(v0)
800BF14C	sll    v1, a1, $10
800BF150	sll    v0, v0, $01
800BF154	lui    at, $8008
800BF158	addiu  at, at, $31fc
800BF15C	addu   at, at, v0
800BF160	lhu    a0, $0000(at)
800BF164	lui    v0, $800a
800BF168	lw     v0, $c6dc(v0)
800BF16C	sra    v1, v1, $10
800BF170	addu   v0, v0, a0
800BF174	addu   v0, v0, v1
800BF178	lbu    v0, $0000(v0)
800BF17C	nop
800BF180	ori    a1, v0, $0200
800BF184	lui    v0, $800a
800BF188	lbu    v0, $d820(v0)
800BF18C	lui    at, $800a
800BF190	addiu  at, at, $d288 (=-$2d78)
800BF194	addu   at, at, a1
800BF198	lbu    s0, $0000(at)
800BF19C	andi   v0, v0, $0003
800BF1A0	beq    v0, zero, Lbf398 [$800bf398]
800BF1A4	addu   v0, s0, zero
800BF1A8	lui    a0, $800a
800BF1AC	addiu  a0, a0, $0308
800BF1B0	jal    funcbeca4 [$800beca4]
800BF1B4	ori    a2, zero, $0004
800BF1B8	lui    a0, $800a
800BF1BC	addiu  a0, a0, $0310
800BF1C0	j      Lbf34c [$800bf34c]
800BF1C4	addu   a1, s0, zero

// memory bank D, E
800BF1C8	lui    v0, $8007
800BF1CC	lbu    v0, $22c4(v0)
800BF1D0	sll    v1, a1, $10
800BF1D4	sll    v0, v0, $01
800BF1D8	lui    at, $8008
800BF1DC	addiu  at, at, $31fc
800BF1E0	addu   at, at, v0
800BF1E4	lhu    a0, $0000(at)
800BF1E8	lui    v0, $800a
800BF1EC	lw     v0, $c6dc(v0)
800BF1F0	sra    v1, v1, $10
800BF1F4	addu   v0, v0, a0
800BF1F8	addu   v0, v0, v1
800BF1FC	lbu    v0, $0000(v0)
800BF200	nop
800BF204	ori    a1, v0, $0300
800BF208	lui    v0, $800a
800BF20C	lbu    v0, $d820(v0)
800BF210	lui    at, $800a
800BF214	addiu  at, at, $d288 (=-$2d78)
800BF218	addu   at, at, a1
800BF21C	lbu    s0, $0000(at)
800BF220	andi   v0, v0, $0003
800BF224	beq    v0, zero, Lbf398 [$800bf398]
800BF228	addu   v0, s0, zero
800BF22C	lui    a0, $800a
800BF230	addiu  a0, a0, $0308
800BF234	jal    funcbeca4 [$800beca4]
800BF238	ori    a2, zero, $0004
800BF23C	lui    a0, $800a
800BF240	addiu  a0, a0, $0310
800BF244	j      Lbf34c [$800bf34c]
800BF248	addu   a1, s0, zero

// memory bank 7, F
800BF24C	lui    v0, $8007
800BF250	lbu    v0, $22c4(v0)
800BF254	sll    v1, a1, $10
800BF258	sll    v0, v0, $01
800BF25C	lui    at, $8008
800BF260	addiu  at, at, $31fc
800BF264	addu   at, at, v0
800BF268	lhu    a0, $0000(at)
800BF26C	lui    v0, $800a
800BF270	lw     v0, $c6dc(v0)
800BF274	sra    v1, v1, $10
800BF278	addu   v0, v0, a0
800BF27C	addu   v0, v0, v1
800BF280	lbu    v0, $0000(v0)
800BF284	nop
800BF288	ori    a1, v0, $0400
800BF28C	lui    v0, $800a
800BF290	lbu    v0, $d820(v0)
800BF294	lui    at, $800a
800BF298	addiu  at, at, $d288 (=-$2d78)
800BF29C	addu   at, at, a1
800BF2A0	lbu    s0, $0000(at)
800BF2A4	andi   v0, v0, $0003
800BF2A8	beq    v0, zero, Lbf398 [$800bf398]
800BF2AC	addu   v0, s0, zero
800BF2B0	lui    a0, $800a
800BF2B4	addiu  a0, a0, $0308
800BF2B8	jal    funcbeca4 [$800beca4]
800BF2BC	ori    a2, zero, $0004
800BF2C0	lui    a0, $800a
800BF2C4	addiu  a0, a0, $0310
800BF2C8	j      Lbf34c [$800bf34c]
800BF2CC	addu   a1, s0, zero

// memory bank 5, 6
800BF2D0	lui    v0, $8007
800BF2D4	lbu    v0, $22c4(v0)
800BF2D8	sll    v1, a1, $10
800BF2DC	sll    v0, v0, $01
800BF2E0	lui    at, $8008
800BF2E4	addiu  at, at, $31fc
800BF2E8	addu   at, at, v0
800BF2EC	lhu    a0, $0000(at)
800BF2F0	lui    v0, $800a
800BF2F4	lw     v0, $c6dc(v0)
800BF2F8	sra    v1, v1, $10
800BF2FC	addu   v0, v0, a0
800BF300	addu   v0, v0, v1
800BF304	lbu    a1, $0000(v0)
800BF308	lui    v0, $800a
800BF30C	lbu    v0, $d820(v0)
800BF310	nop
800BF314	andi   v0, v0, $0003
800BF318	lui    at, $8007
800BF31C	addiu  at, at, $5e24
800BF320	addu   at, at, a1
800BF324	lbu    s0, $0000(at)
800BF328	beq    v0, zero, Lbf398 [$800bf398]
800BF32C	addu   v0, s0, zero
800BF330	lui    a0, $800a
800BF334	addiu  a0, a0, $0308
800BF338	jal    funcbeca4 [$800beca4]
800BF33C	ori    a2, zero, $0004
800BF340	lui    a0, $800a
800BF344	addiu  a0, a0, $0318
800BF348	addu   a1, s0, zero

Lbf34c:	; 800BF34C
800BF34C	jal    funcbeca4 [$800beca4]
800BF350	ori    a2, zero, $0002
800BF354	j      Lbf398 [$800bf398]
800BF358	addu   v0, s0, zero

// memory bank 8, 9, A, >F
Lbf35c:	; 800BF35C
800BF35C	lui    v0, $800a
800BF360	lbu    v0, $d820(v0)
800BF364	nop
800BF368	andi   v0, v0, $0003
800BF36C	beq    v0, zero, Lbf384 [$800bf384]
800BF370	andi   a1, v1, $00ff
800BF374	lui    a0, $800a
800BF378	addiu  a0, a0, $0320
800BF37C	jal    funcbeca4 [$800beca4]
800BF380	ori    a2, zero, $0002

Lbf384:	; 800BF384
800BF384	lui    a0, $800a
800BF388	addiu  a0, a0, $032c
800BF38C	jal    funcd4848 [$800d4848]
800BF390	nop
800BF394	addu   v0, zero, zero

Lbf398:	; 800BF398
800BF398	lw     ra, $0014(sp)
800BF39C	lw     s0, $0010(sp)
800BF3A0	addiu  sp, sp, $0018
800BF3A4	jr     ra 
800BF3A8	nop
////////////////////////////////////////////////////////////