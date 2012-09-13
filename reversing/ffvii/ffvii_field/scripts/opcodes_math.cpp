////////////////////////////////
// 0x76 PLUS!
800CBBF4	lui    v0, $800a
800CBBF8	lbu    v0, $d820(v0)
800CBBFC	addiu  sp, sp, $ffe8 (=-$18)
800CBC00	sw     ra, $0014(sp)
800CBC04	andi   v0, v0, $0003
800CBC08	beq    v0, zero, Lcbc20 [$800cbc20]
800CBC0C	sw     s0, $0010(sp)
800CBC10	lui    a0, $800a
800CBC14	addiu  a0, a0, $0b20
800CBC18	jal    funcbead4 [$800bead4]
800CBC1C	ori    a1, zero, $0003

Lcbc20:	; 800CBC20
800CBC20	ori    a0, zero, $0001
800CBC24	jal    read_memory_block_one_byte [$800bee10]
800CBC28	ori    a1, zero, $0002
800CBC2C	ori    a0, zero, $0002
800CBC30	ori    a1, zero, $0003
800CBC34	jal    read_memory_block_one_byte [$800bee10]
800CBC38	addu   s0, v0, zero
800CBC3C	andi   s0, s0, $00ff
800CBC40	andi   v0, v0, $00ff
800CBC44	addu   s0, s0, v0
800CBC48	addu   a2, s0, zero
800CBC4C	slti   s0, s0, $0100
800CBC50	bne    s0, zero, Lcbc5c [$800cbc5c]
800CBC54	ori    a0, zero, $0001
800CBC58	ori    a2, zero, $00ff

Lcbc5c:	; 800CBC5C
800CBC5C	ori    a1, zero, $0002
800CBC60	jal    store_memory_block_one_byte [$800bf3ac]
800CBC64	andi   a2, a2, $00ff
800CBC68	lui    v1, $8007
800CBC6C	lbu    v1, $22c4(v1)
800CBC70	lui    v0, $8008
800CBC74	addiu  v0, v0, $31fc
800CBC78	sll    v1, v1, $01
800CBC7C	addu   v1, v1, v0
800CBC80	lhu    a0, $0000(v1)
800CBC84	addu   v0, zero, zero
800CBC88	addiu  a0, a0, $0004
800CBC8C	sh     a0, $0000(v1)
800CBC90	lw     ra, $0014(sp)
800CBC94	lw     s0, $0010(sp)
800CBC98	addiu  sp, sp, $0018
800CBC9C	jr     ra 
800CBCA0	nop
////////////////////////////////



////////////////////////////////
// 0x77 PLUS2!
800CBD40	lui    v0, $800a
800CBD44	lbu    v0, $d820(v0)
800CBD48	addiu  sp, sp, $ffe8 (=-$18)
800CBD4C	sw     ra, $0014(sp)
800CBD50	andi   v0, v0, $0003
800CBD54	beq    v0, zero, Lcbd6c [$800cbd6c]
800CBD58	sw     s0, $0010(sp)
800CBD5C	lui    a0, $800a
800CBD60	addiu  a0, a0, $0b30
800CBD64	jal    funcbead4 [$800bead4]
800CBD68	ori    a1, zero, $0003

Lcbd6c:	; 800CBD6C
800CBD6C	ori    a0, zero, $0001
800CBD70	jal    read_memory_block_two_bytes [$800bf908]
800CBD74	ori    a1, zero, $0002
800CBD78	ori    a0, zero, $0002
800CBD7C	ori    a1, zero, $0003
800CBD80	jal    read_memory_block_two_bytes [$800bf908]
800CBD84	addu   s0, v0, zero
800CBD88	sll    s0, s0, $10
800CBD8C	sra    s0, s0, $10
800CBD90	sll    v0, v0, $10
800CBD94	sra    v0, v0, $10
800CBD98	addu   a2, s0, v0
800CBD9C	ori    v0, zero, $7fff
800CBDA0	slt    v0, v0, a2
800CBDA4	beq    v0, zero, Lcbdb0 [$800cbdb0]
800CBDA8	ori    a0, zero, $0001
800CBDAC	ori    a2, zero, $7fff

Lcbdb0:	; 800CBDB0
800CBDB0	ori    a1, zero, $0002
800CBDB4	sll    a2, a2, $10
800CBDB8	jal    store_memory_block_two_bytes [$800c0248]
800CBDBC	sra    a2, a2, $10
800CBDC0	lui    a0, $8007
800CBDC4	lbu    a0, $22c4(a0)
800CBDC8	lui    v0, $8008
800CBDCC	addiu  v0, v0, $31fc
800CBDD0	sll    a0, a0, $01
800CBDD4	addu   a0, a0, v0
800CBDD8	lhu    v1, $0000(a0)
800CBDDC	addu   v0, zero, zero
800CBDE0	addiu  v1, v1, $0005
800CBDE4	sh     v1, $0000(a0)
800CBDE8	lw     ra, $0014(sp)
800CBDEC	lw     s0, $0010(sp)
800CBDF0	addiu  sp, sp, $0018
800CBDF4	jr     ra 
800CBDF8	nop
////////////////////////////////



////////////////////////////////
// 0x78 MINUS!
800CBE94	lui    v0, $800a
800CBE98	lbu    v0, $d820(v0)
800CBE9C	addiu  sp, sp, $ffe8 (=-$18)
800CBEA0	sw     ra, $0014(sp)
800CBEA4	andi   v0, v0, $0003
800CBEA8	beq    v0, zero, Lcbec0 [$800cbec0]
800CBEAC	sw     s0, $0010(sp)
800CBEB0	lui    a0, $800a
800CBEB4	addiu  a0, a0, $0b40
800CBEB8	jal    funcbead4 [$800bead4]
800CBEBC	ori    a1, zero, $0003

Lcbec0:	; 800CBEC0
800CBEC0	ori    a0, zero, $0001
800CBEC4	jal    read_memory_block_one_byte [$800bee10]
800CBEC8	ori    a1, zero, $0002
800CBECC	ori    a0, zero, $0002
800CBED0	ori    a1, zero, $0003
800CBED4	jal    read_memory_block_one_byte [$800bee10]
800CBED8	addu   s0, v0, zero
800CBEDC	andi   s0, s0, $00ff
800CBEE0	andi   v0, v0, $00ff
800CBEE4	subu   s0, s0, v0
800CBEE8	bgez   s0, Lcbef4 [$800cbef4]
800CBEEC	addu   a2, s0, zero
800CBEF0	addu   a2, zero, zero

Lcbef4:	; 800CBEF4
800CBEF4	ori    a0, zero, $0001
800CBEF8	ori    a1, zero, $0002
800CBEFC	jal    store_memory_block_one_byte [$800bf3ac]
800CBF00	andi   a2, a2, $00ff
800CBF04	lui    v1, $8007
800CBF08	lbu    v1, $22c4(v1)
800CBF0C	lui    v0, $8008
800CBF10	addiu  v0, v0, $31fc
800CBF14	sll    v1, v1, $01
800CBF18	addu   v1, v1, v0
800CBF1C	lhu    a0, $0000(v1)
800CBF20	addu   v0, zero, zero
800CBF24	addiu  a0, a0, $0004
800CBF28	sh     a0, $0000(v1)
800CBF2C	lw     ra, $0014(sp)
800CBF30	lw     s0, $0010(sp)
800CBF34	addiu  sp, sp, $0018
800CBF38	jr     ra 
800CBF3C	nop
////////////////////////////////



////////////////////////////////
// 0x79 MINUS2!
800CBFDC	lui    v0, $800a
800CBFE0	lbu    v0, $d820(v0)
800CBFE4	addiu  sp, sp, $ffe8 (=-$18)
800CBFE8	sw     ra, $0014(sp)
800CBFEC	andi   v0, v0, $0003
800CBFF0	beq    v0, zero, Lcc008 [$800cc008]
800CBFF4	sw     s0, $0010(sp)
800CBFF8	lui    a0, $800a
800CBFFC	addiu  a0, a0, $0b50
800CC000	jal    funcbead4 [$800bead4]
800CC004	ori    a1, zero, $0003

Lcc008:	; 800CC008
800CC008	ori    a0, zero, $0001
800CC00C	jal    read_memory_block_two_bytes [$800bf908]
800CC010	ori    a1, zero, $0002
800CC014	ori    a0, zero, $0002
800CC018	ori    a1, zero, $0003
800CC01C	jal    read_memory_block_two_bytes [$800bf908]
800CC020	addu   s0, v0, zero
800CC024	sll    s0, s0, $10
800CC028	sra    s0, s0, $10
800CC02C	sll    v0, v0, $10
800CC030	sra    v0, v0, $10
800CC034	subu   a2, s0, v0
800CC038	ori    v0, zero, $7fff
800CC03C	slt    v0, v0, a2
800CC040	bne    v0, zero, Lcc04c [$800cc04c]
800CC044	ori    a0, zero, $0001
800CC048	ori    a2, zero, $8000

Lcc04c:	; 800CC04C
800CC04C	ori    a1, zero, $0002
800CC050	sll    a2, a2, $10
800CC054	jal    store_memory_block_two_bytes [$800c0248]
800CC058	sra    a2, a2, $10
800CC05C	lui    a0, $8007
800CC060	lbu    a0, $22c4(a0)
800CC064	lui    v0, $8008
800CC068	addiu  v0, v0, $31fc
800CC06C	sll    a0, a0, $01
800CC070	addu   a0, a0, v0
800CC074	lhu    v1, $0000(a0)
800CC078	addu   v0, zero, zero
800CC07C	addiu  v1, v1, $0005
800CC080	sh     v1, $0000(a0)
800CC084	lw     ra, $0014(sp)
800CC088	lw     s0, $0010(sp)
800CC08C	addiu  sp, sp, $0018
800CC090	jr     ra 
800CC094	nop
////////////////////////////////



////////////////////////////////
// 0x7A INC!
800CC558	lui    v0, $800a
800CC55C	lbu    v0, $d820(v0)
800CC560	addiu  sp, sp, $ffe8 (=-$18)
800CC564	andi   v0, v0, $0003
800CC568	beq    v0, zero, Lcc580 [$800cc580]
800CC56C	sw     ra, $0010(sp)
800CC570	lui    a0, $800a
800CC574	addiu  a0, a0, $0b84
800CC578	jal    funcbead4 [$800bead4]
800CC57C	ori    a1, zero, $0002

Lcc580:	; 800CC580
800CC580	ori    a0, zero, $0002
800CC584	jal    read_memory_block_one_byte [$800bee10]
800CC588	ori    a1, zero, $0002
800CC58C	andi   v0, v0, $00ff
800CC590	addiu  v0, v0, $0001
800CC594	addu   a2, v0, zero
800CC598	slti   v0, v0, $0100
800CC59C	bne    v0, zero, Lcc5a8 [$800cc5a8]
800CC5A0	ori    a0, zero, $0002
800CC5A4	ori    a2, zero, $00ff

Lcc5a8:	; 800CC5A8
800CC5A8	ori    a1, zero, $0002
800CC5AC	jal    store_memory_block_one_byte [$800bf3ac]
800CC5B0	andi   a2, a2, $00ff
800CC5B4	lui    v1, $8007
800CC5B8	lbu    v1, $22c4(v1)
800CC5BC	lui    v0, $8008
800CC5C0	addiu  v0, v0, $31fc
800CC5C4	sll    v1, v1, $01
800CC5C8	addu   v1, v1, v0
800CC5CC	lhu    a0, $0000(v1)
800CC5D0	addu   v0, zero, zero
800CC5D4	addiu  a0, a0, $0003
800CC5D8	sh     a0, $0000(v1)
800CC5DC	lw     ra, $0010(sp)
800CC5E0	addiu  sp, sp, $0018
800CC5E4	jr     ra 
800CC5E8	nop
////////////////////////////////



////////////////////////////////
// 0x7B INC2!
800CC670	lui    v0, $800a
800CC674	lbu    v0, $d820(v0)
800CC678	addiu  sp, sp, $ffe8 (=-$18)
800CC67C	andi   v0, v0, $0003
800CC680	beq    v0, zero, Lcc698 [$800cc698]
800CC684	sw     ra, $0010(sp)
800CC688	lui    a0, $800a
800CC68C	addiu  a0, a0, $0b94
800CC690	jal    funcbead4 [$800bead4]
800CC694	ori    a1, zero, $0003

Lcc698:	; 800CC698
800CC698	ori    a0, zero, $0002
800CC69C	jal    read_memory_block_two_bytes [$800bf908]
800CC6A0	ori    a1, zero, $0002
800CC6A4	sll    v0, v0, $10
800CC6A8	sra    v0, v0, $10
800CC6AC	addiu  a2, v0, $0001
800CC6B0	ori    v0, zero, $7fff
800CC6B4	slt    v0, v0, a2
800CC6B8	beq    v0, zero, Lcc6c4 [$800cc6c4]
800CC6BC	ori    a0, zero, $0002
800CC6C0	ori    a2, zero, $7fff

Lcc6c4:	; 800CC6C4
800CC6C4	ori    a1, zero, $0002
800CC6C8	sll    a2, a2, $10
800CC6CC	jal    store_memory_block_two_bytes [$800c0248]
800CC6D0	sra    a2, a2, $10
800CC6D4	lui    a0, $8007
800CC6D8	lbu    a0, $22c4(a0)
800CC6DC	lui    v0, $8008
800CC6E0	addiu  v0, v0, $31fc
800CC6E4	sll    a0, a0, $01
800CC6E8	addu   a0, a0, v0
800CC6EC	lhu    v1, $0000(a0)
800CC6F0	addu   v0, zero, zero
800CC6F4	addiu  v1, v1, $0003
800CC6F8	sh     v1, $0000(a0)
800CC6FC	lw     ra, $0010(sp)
800CC700	addiu  sp, sp, $0018
800CC704	jr     ra 
800CC708	nop
////////////////////////////////



////////////////////////////////
// 0x7C DEC!
800CC78C	lui    v0, $800a
800CC790	lbu    v0, $d820(v0)
800CC794	addiu  sp, sp, $ffe8 (=-$18)
800CC798	andi   v0, v0, $0003
800CC79C	beq    v0, zero, Lcc7b4 [$800cc7b4]
800CC7A0	sw     ra, $0010(sp)
800CC7A4	lui    a0, $800a
800CC7A8	addiu  a0, a0, $0ba0
800CC7AC	jal    funcbead4 [$800bead4]
800CC7B0	ori    a1, zero, $0002

Lcc7b4:	; 800CC7B4
800CC7B4	ori    a0, zero, $0002
800CC7B8	jal    read_memory_block_one_byte [$800bee10]
800CC7BC	ori    a1, zero, $0002
800CC7C0	andi   v0, v0, $00ff
800CC7C4	ori    v1, zero, $ffff
800CC7C8	addu   v0, v0, v1
800CC7CC	addu   a2, v0, zero
800CC7D0	sll    v0, v0, $10
800CC7D4	bgez   v0, Lcc7e0 [$800cc7e0]
800CC7D8	ori    a0, zero, $0002
800CC7DC	addu   a2, zero, zero

Lcc7e0:	; 800CC7E0
800CC7E0	ori    a1, zero, $0002
800CC7E4	jal    store_memory_block_one_byte [$800bf3ac]
800CC7E8	andi   a2, a2, $00ff
800CC7EC	lui    v1, $8007
800CC7F0	lbu    v1, $22c4(v1)
800CC7F4	lui    v0, $8008
800CC7F8	addiu  v0, v0, $31fc
800CC7FC	sll    v1, v1, $01
800CC800	addu   v1, v1, v0
800CC804	lhu    a0, $0000(v1)
800CC808	addu   v0, zero, zero
800CC80C	addiu  a0, a0, $0003
800CC810	sh     a0, $0000(v1)
800CC814	lw     ra, $0010(sp)
800CC818	addiu  sp, sp, $0018
800CC81C	jr     ra 
800CC820	nop
////////////////////////////////



////////////////////////////////
// 0x7D DEC2!
800CC8A8	lui    v0, $800a
800CC8AC	lbu    v0, $d820(v0)
800CC8B0	addiu  sp, sp, $ffe8 (=-$18)
800CC8B4	andi   v0, v0, $0003
800CC8B8	beq    v0, zero, Lcc8d0 [$800cc8d0]
800CC8BC	sw     ra, $0010(sp)
800CC8C0	lui    a0, $800a
800CC8C4	addiu  a0, a0, $0bb0
800CC8C8	jal    funcbead4 [$800bead4]
800CC8CC	ori    a1, zero, $0003

Lcc8d0:	; 800CC8D0
800CC8D0	ori    a0, zero, $0002
800CC8D4	jal    read_memory_block_two_bytes [$800bf908]
800CC8D8	ori    a1, zero, $0002
800CC8DC	sll    v0, v0, $10
800CC8E0	sra    v0, v0, $10
800CC8E4	addiu  a2, v0, $ffff (=-$1)
800CC8E8	ori    v0, zero, $7fff
800CC8EC	slt    v0, v0, a2
800CC8F0	bne    v0, zero, Lcc8fc [$800cc8fc]
800CC8F4	ori    a0, zero, $0002
800CC8F8	ori    a2, zero, $8000

Lcc8fc:	; 800CC8FC
800CC8FC	ori    a1, zero, $0002
800CC900	sll    a2, a2, $10
800CC904	jal    store_memory_block_two_bytes [$800c0248]
800CC908	sra    a2, a2, $10
800CC90C	lui    a0, $8007
800CC910	lbu    a0, $22c4(a0)
800CC914	lui    v0, $8008
800CC918	addiu  v0, v0, $31fc
800CC91C	sll    a0, a0, $01
800CC920	addu   a0, a0, v0
800CC924	lhu    v1, $0000(a0)
800CC928	addu   v0, zero, zero
800CC92C	addiu  v1, v1, $0003
800CC930	sh     v1, $0000(a0)
800CC934	lw     ra, $0010(sp)
800CC938	addiu  sp, sp, $0018
800CC93C	jr     ra 
800CC940	nop
////////////////////////////////



////////////////////////////////
// 0x7F RDMSD
800CCA14	ori    a0, zero, $0002
800CCA18	jal    read_memory_block_one_byte [$800bee10]
800CCA1C	ori    a1, zero, $0002
800CCA20	sll    a1, v0, $04
800CCA24	addu   v0, zero, zero
800CCA28	lui    a0, $8007
800CCA2C	lbu    a0, $22c4(a0)
800CCA30	lui    v1, $8008
800CCA34	addiu  v1, v1, $31fc
800CCA38	sll    a0, a0, $01
800CCA3C	addu   a0, a0, v1
800CCA40	lhu    v1, $0000(a0)
800CCA44	addiu  a1, a1, $0001
800CCA48	lui    at, $8005
800CCA4C	sb     a1, $a630(at)
800CCA50	addiu  v1, v1, $0003
800CCA54	sh     v1, $0000(a0)
800CCA58	lw     ra, $0010(sp)
800CCA5C	addiu  sp, sp, $0018
800CCA60	jr     ra 
800CCA64	nop
////////////////////////////////



////////////////////////////////
// 0x80 SETBYTE
800C0DE0	lui    v0, $800a
800C0DE4	lbu    v0, $d820(v0)
800C0DE8	addiu  sp, sp, $ffe8 (=-$18)
800C0DEC	andi   v0, v0, $0003
800C0DF0	beq    v0, zero, Lc0e08 [$800c0e08]
800C0DF4	sw     ra, $0010(sp)
800C0DF8	lui    a0, $800a
800C0DFC	addiu  a0, a0, $04fc
800C0E00	jal    funcbead4 [$800bead4]
800C0E04	ori    a1, zero, $0003

Lc0e08:	; 800C0E08
800C0E08	ori    a0, zero, $0002
800C0E0C	jal    read_memory_block_one_byte [$800bee10]
800C0E10	ori    a1, zero, $0003
800C0E14	ori    a0, zero, $0001
800C0E18	ori    a1, zero, $0002
800C0E1C	jal    store_memory_block_one_byte [$800bf3ac]
800C0E20	andi   a2, v0, $00ff
800C0E24	lui    v1, $8007
800C0E28	lbu    v1, $22c4(v1)
800C0E2C	lui    v0, $8008
800C0E30	addiu  v0, v0, $31fc
800C0E34	sll    v1, v1, $01
800C0E38	addu   v1, v1, v0
800C0E3C	lhu    a0, $0000(v1)
800C0E40	addu   v0, zero, zero
800C0E44	addiu  a0, a0, $0004

funcc0e48:	; 800C0E48
800C0E48	sh     a0, $0000(v1)
800C0E4C	lw     ra, $0010(sp)
800C0E50	addiu  sp, sp, $0018
800C0E54	jr     ra 
800C0E58	nop
////////////////////////////////



////////////////////////////////
// 0x81 SETWORD
800C0E5C	lui    v0, $800a
800C0E60	lbu    v0, $d820(v0)
800C0E64	addiu  sp, sp, $ffe8 (=-$18)
800C0E68	andi   v0, v0, $0003
800C0E6C	beq    v0, zero, Lc0e84 [$800c0e84]
800C0E70	sw     ra, $0010(sp)
800C0E74	lui    a0, $800a
800C0E78	addiu  a0, a0, $0500
800C0E7C	jal    funcbead4 [$800bead4]
800C0E80	ori    a1, zero, $0004

Lc0e84:	; 800C0E84
800C0E84	ori    a0, zero, $0002
800C0E88	jal    read_memory_block_two_bytes [$800bf908]
800C0E8C	ori    a1, zero, $0003
800C0E90	ori    a0, zero, $0001
800C0E94	ori    a1, zero, $0002
800C0E98	sll    v0, v0, $10
800C0E9C	jal    store_memory_block_two_bytes [$800c0248]
800C0EA0	sra    a2, v0, $10
800C0EA4	lui    a0, $8007
800C0EA8	lbu    a0, $22c4(a0)
800C0EAC	lui    v0, $8008
800C0EB0	addiu  v0, v0, $31fc
800C0EB4	sll    a0, a0, $01
800C0EB8	addu   a0, a0, v0
800C0EBC	lhu    v1, $0000(a0)
800C0EC0	addu   v0, zero, zero
800C0EC4	addiu  v1, v1, $0005
800C0EC8	sh     v1, $0000(a0)
800C0ECC	lw     ra, $0010(sp)
800C0ED0	addiu  sp, sp, $0018
800C0ED4	jr     ra 
800C0ED8	nop
////////////////////////////////



////////////////////////////////
// 0x82 BITON
800C16A0	ori    a0, zero, $0001
800C16A4	jal    read_memory_block_one_byte [$800bee10]
800C16A8	ori    a1, zero, $0002
800C16AC	ori    a0, zero, $0002
800C16B0	ori    a1, zero, $0003
800C16B4	jal    read_memory_block_one_byte [$800bee10]
800C16B8	addu   s0, v0, zero
800C16BC	ori    v1, zero, $0001
800C16C0	sllv   v1, v0, v1
800C16C4	or     s0, s0, v1
800C16C8	ori    a0, zero, $0001
800C16CC	ori    a1, zero, $0002
800C16D0	jal    store_memory_block_one_byte [$800bf3ac]
800C16D4	andi   a2, s0, $00ff
800C16D8	lui    a0, $8007
800C16DC	lbu    a0, $22c4(a0)
800C16E0	lui    v0, $8008
800C16E4	addiu  v0, v0, $31fc
800C16E8	sll    a0, a0, $01
800C16EC	addu   a0, a0, v0
800C16F0	lhu    v1, $0000(a0)
800C16F4	addu   v0, zero, zero
800C16F8	addiu  v1, v1, $0004
800C16FC	sh     v1, $0000(a0)
800C1700	lw     ra, $0014(sp)
800C1704	lw     s0, $0010(sp)
800C1708	addiu  sp, sp, $0018
800C170C	jr     ra 
800C1710	nop
////////////////////////////////



////////////////////////////////
// 0x83 BITOFF
800C1714	lui    v0, $800a
800C1718	lbu    v0, $d820(v0)
800C171C	addiu  sp, sp, $ffe8 (=-$18)
800C1720	sw     ra, $0014(sp)
800C1724	andi   v0, v0, $0003
800C1728	beq    v0, zero, Lc1740 [$800c1740]
800C172C	sw     s0, $0010(sp)
800C1730	lui    a0, $800a
800C1734	addiu  a0, a0, $0600
800C1738	jal    funcbead4 [$800bead4]
800C173C	ori    a1, zero, $0003

Lc1740:	; 800C1740
800C1740	ori    a0, zero, $0001
800C1744	jal    read_memory_block_one_byte [$800bee10]
800C1748	ori    a1, zero, $0002
800C174C	ori    a0, zero, $0002
800C1750	ori    a1, zero, $0003
800C1754	jal    read_memory_block_one_byte [$800bee10]
800C1758	addu   s0, v0, zero
800C175C	ori    v1, zero, $0001
800C1760	sllv   v1, v0, v1
800C1764	nor    v1, zero, v1
800C1768	and    s0, s0, v1
800C176C	ori    a0, zero, $0001
800C1770	ori    a1, zero, $0002
800C1774	jal    store_memory_block_one_byte [$800bf3ac]
800C1778	andi   a2, s0, $00ff
800C177C	lui    a0, $8007
800C1780	lbu    a0, $22c4(a0)
800C1784	lui    v0, $8008
800C1788	addiu  v0, v0, $31fc
800C178C	sll    a0, a0, $01
800C1790	addu   a0, a0, v0
800C1794	lhu    v1, $0000(a0)
800C1798	addu   v0, zero, zero
800C179C	addiu  v1, v1, $0004
800C17A0	sh     v1, $0000(a0)
800C17A4	lw     ra, $0014(sp)
800C17A8	lw     s0, $0010(sp)
800C17AC	addiu  sp, sp, $0018
800C17B0	jr     ra 
800C17B4	nop
////////////////////////////////



////////////////////////////////
// 0x84 BITXOR
800C17B8	lui    v0, $800a
800C17BC	lbu    v0, $d820(v0)
800C17C0	addiu  sp, sp, $ffe8 (=-$18)
800C17C4	sw     ra, $0014(sp)
800C17C8	andi   v0, v0, $0003
800C17CC	beq    v0, zero, Lc17e4 [$800c17e4]
800C17D0	sw     s0, $0010(sp)
800C17D4	lui    a0, $800a
800C17D8	addiu  a0, a0, $0608
800C17DC	jal    funcbead4 [$800bead4]
800C17E0	ori    a1, zero, $0003

Lc17e4:	; 800C17E4
800C17E4	ori    a0, zero, $0001
800C17E8	jal    read_memory_block_one_byte [$800bee10]
800C17EC	ori    a1, zero, $0002
800C17F0	ori    a0, zero, $0002
800C17F4	ori    a1, zero, $0003
800C17F8	jal    read_memory_block_one_byte [$800bee10]
800C17FC	addu   s0, v0, zero
800C1800	ori    v1, zero, $0001
800C1804	sllv   v1, v0, v1
800C1808	xor    s0, s0, v1
800C180C	ori    a0, zero, $0001
800C1810	ori    a1, zero, $0002
800C1814	jal    store_memory_block_one_byte [$800bf3ac]
800C1818	andi   a2, s0, $00ff
800C181C	lui    a0, $8007
800C1820	lbu    a0, $22c4(a0)
800C1824	lui    v0, $8008
800C1828	addiu  v0, v0, $31fc
800C182C	sll    a0, a0, $01
800C1830	addu   a0, a0, v0
800C1834	lhu    v1, $0000(a0)
800C1838	addu   v0, zero, zero
800C183C	addiu  v1, v1, $0004
800C1840	sh     v1, $0000(a0)
800C1844	lw     ra, $0014(sp)
800C1848	lw     s0, $0010(sp)
800C184C	addiu  sp, sp, $0018
800C1850	jr     ra 
800C1854	nop
////////////////////////////////



////////////////////////////////
// 0x85 PLUS
800CBB5C	lui    v0, $800a
800CBB60	lbu    v0, $d820(v0)
800CBB64	addiu  sp, sp, $ffe8 (=-$18)
800CBB68	sw     ra, $0014(sp)
800CBB6C	andi   v0, v0, $0003
800CBB70	beq    v0, zero, Lcbb88 [$800cbb88]
800CBB74	sw     s0, $0010(sp)
800CBB78	lui    a0, $800a
800CBB7C	addiu  a0, a0, $0b18
800CBB80	jal    funcbead4 [$800bead4]
800CBB84	ori    a1, zero, $0003

Lcbb88:	; 800CBB88
800CBB88	ori    a0, zero, $0001
800CBB8C	jal    read_memory_block_one_byte [$800bee10]
800CBB90	ori    a1, zero, $0002
800CBB94	ori    a0, zero, $0002
800CBB98	ori    a1, zero, $0003
800CBB9C	jal    read_memory_block_one_byte [$800bee10]
800CBBA0	addu   s0, v0, zero
800CBBA4	addu   s0, s0, v0
800CBBA8	ori    a0, zero, $0001
800CBBAC	ori    a1, zero, $0002
800CBBB0	jal    store_memory_block_one_byte [$800bf3ac]
800CBBB4	andi   a2, s0, $00ff
800CBBB8	lui    a0, $8007
800CBBBC	lbu    a0, $22c4(a0)
800CBBC0	lui    v0, $8008
800CBBC4	addiu  v0, v0, $31fc
800CBBC8	sll    a0, a0, $01
800CBBCC	addu   a0, a0, v0
800CBBD0	lhu    v1, $0000(a0)
800CBBD4	addu   v0, zero, zero
800CBBD8	addiu  v1, v1, $0004
800CBBDC	sh     v1, $0000(a0)
800CBBE0	lw     ra, $0014(sp)
800CBBE4	lw     s0, $0010(sp)
800CBBE8	addiu  sp, sp, $0018
800CBBEC	jr     ra 
800CBBF0	nop
////////////////////////////////



////////////////////////////////
// 0x86 PLUS2
800CBCA4	lui    v0, $800a
800CBCA8	lbu    v0, $d820(v0)
800CBCAC	addiu  sp, sp, $ffe8 (=-$18)
800CBCB0	sw     ra, $0014(sp)
800CBCB4	andi   v0, v0, $0003
800CBCB8	beq    v0, zero, Lcbcd0 [$800cbcd0]
800CBCBC	sw     s0, $0010(sp)
800CBCC0	lui    a0, $800a
800CBCC4	addiu  a0, a0, $0b28
800CBCC8	jal    funcbead4 [$800bead4]
800CBCCC	ori    a1, zero, $0003

Lcbcd0:	; 800CBCD0
800CBCD0	ori    a0, zero, $0001
800CBCD4	jal    read_memory_block_two_bytes [$800bf908]
800CBCD8	ori    a1, zero, $0002
800CBCDC	ori    a0, zero, $0002
800CBCE0	ori    a1, zero, $0003
800CBCE4	jal    read_memory_block_two_bytes [$800bf908]
800CBCE8	addu   s0, v0, zero
800CBCEC	ori    a0, zero, $0001
800CBCF0	ori    a1, zero, $0002
800CBCF4	addu   s0, s0, v0
800CBCF8	sll    s0, s0, $10
800CBCFC	jal    store_memory_block_two_bytes [$800c0248]
800CBD00	sra    a2, s0, $10
800CBD04	lui    a0, $8007
800CBD08	lbu    a0, $22c4(a0)
800CBD0C	lui    v0, $8008
800CBD10	addiu  v0, v0, $31fc
800CBD14	sll    a0, a0, $01
800CBD18	addu   a0, a0, v0
800CBD1C	lhu    v1, $0000(a0)
800CBD20	addu   v0, zero, zero
800CBD24	addiu  v1, v1, $0005
800CBD28	sh     v1, $0000(a0)
800CBD2C	lw     ra, $0014(sp)
800CBD30	lw     s0, $0010(sp)
800CBD34	addiu  sp, sp, $0018
800CBD38	jr     ra 
800CBD3C	nop
////////////////////////////////



////////////////////////////////
// 0x87 MINUS
800CBDFC	lui    v0, $800a
800CBE00	lbu    v0, $d820(v0)
800CBE04	addiu  sp, sp, $ffe8 (=-$18)
800CBE08	sw     ra, $0014(sp)
800CBE0C	andi   v0, v0, $0003
800CBE10	beq    v0, zero, Lcbe28 [$800cbe28]
800CBE14	sw     s0, $0010(sp)
800CBE18	lui    a0, $800a
800CBE1C	addiu  a0, a0, $0b38
800CBE20	jal    funcbead4 [$800bead4]
800CBE24	ori    a1, zero, $0003

Lcbe28:	; 800CBE28
800CBE28	ori    a0, zero, $0001
800CBE2C	jal    read_memory_block_one_byte [$800bee10]
800CBE30	ori    a1, zero, $0002
800CBE34	ori    a0, zero, $0002
800CBE38	ori    a1, zero, $0003
800CBE3C	jal    read_memory_block_one_byte [$800bee10]
800CBE40	addu   s0, v0, zero
800CBE44	subu   s0, s0, v0
800CBE48	ori    a0, zero, $0001
800CBE4C	ori    a1, zero, $0002
800CBE50	jal    store_memory_block_one_byte [$800bf3ac]
800CBE54	andi   a2, s0, $00ff
800CBE58	lui    a0, $8007
800CBE5C	lbu    a0, $22c4(a0)
800CBE60	lui    v0, $8008
800CBE64	addiu  v0, v0, $31fc
800CBE68	sll    a0, a0, $01
800CBE6C	addu   a0, a0, v0
800CBE70	lhu    v1, $0000(a0)
800CBE74	addu   v0, zero, zero
800CBE78	addiu  v1, v1, $0004
800CBE7C	sh     v1, $0000(a0)
800CBE80	lw     ra, $0014(sp)
800CBE84	lw     s0, $0010(sp)
800CBE88	addiu  sp, sp, $0018
800CBE8C	jr     ra 
800CBE90	nop
////////////////////////////////



////////////////////////////////
// 0x88 MINUS2
800CBF40	lui    v0, $800a
800CBF44	lbu    v0, $d820(v0)
800CBF48	addiu  sp, sp, $ffe8 (=-$18)
800CBF4C	sw     ra, $0014(sp)
800CBF50	andi   v0, v0, $0003
800CBF54	beq    v0, zero, Lcbf6c [$800cbf6c]
800CBF58	sw     s0, $0010(sp)
800CBF5C	lui    a0, $800a
800CBF60	addiu  a0, a0, $0b48
800CBF64	jal    funcbead4 [$800bead4]
800CBF68	ori    a1, zero, $0003

Lcbf6c:	; 800CBF6C
800CBF6C	ori    a0, zero, $0001
800CBF70	jal    read_memory_block_two_bytes [$800bf908]
800CBF74	ori    a1, zero, $0002
800CBF78	ori    a0, zero, $0002
800CBF7C	ori    a1, zero, $0003
800CBF80	jal    read_memory_block_two_bytes [$800bf908]
800CBF84	addu   s0, v0, zero
800CBF88	ori    a0, zero, $0001
800CBF8C	ori    a1, zero, $0002
800CBF90	subu   s0, s0, v0
800CBF94	sll    s0, s0, $10
800CBF98	jal    store_memory_block_two_bytes [$800c0248]
800CBF9C	sra    a2, s0, $10
800CBFA0	lui    a0, $8007
800CBFA4	lbu    a0, $22c4(a0)
800CBFA8	lui    v0, $8008
800CBFAC	addiu  v0, v0, $31fc
800CBFB0	sll    a0, a0, $01
800CBFB4	addu   a0, a0, v0
800CBFB8	lhu    v1, $0000(a0)
800CBFBC	addu   v0, zero, zero
800CBFC0	addiu  v1, v1, $0005
800CBFC4	sh     v1, $0000(a0)
800CBFC8	lw     ra, $0014(sp)
800CBFCC	lw     s0, $0010(sp)
800CBFD0	addiu  sp, sp, $0018
800CBFD4	jr     ra 
800CBFD8	nop
////////////////////////////////



////////////////////////////////
// 0x89 MUL
800CC098	lui    v0, $800a
800CC09C	lbu    v0, $d820(v0)
800CC0A0	addiu  sp, sp, $ffe8 (=-$18)
800CC0A4	sw     ra, $0014(sp)
800CC0A8	andi   v0, v0, $0003
800CC0AC	beq    v0, zero, Lcc0c4 [$800cc0c4]
800CC0B0	sw     s0, $0010(sp)
800CC0B4	lui    a0, $800a
800CC0B8	addiu  a0, a0, $0b58
800CC0BC	jal    funcbead4 [$800bead4]
800CC0C0	ori    a1, zero, $0003

Lcc0c4:	; 800CC0C4
800CC0C4	ori    a0, zero, $0001
800CC0C8	jal    read_memory_block_one_byte [$800bee10]
800CC0CC	ori    a1, zero, $0002
800CC0D0	ori    a0, zero, $0002
800CC0D4	ori    a1, zero, $0003
800CC0D8	jal    read_memory_block_one_byte [$800bee10]
800CC0DC	addu   s0, v0, zero
800CC0E0	mult   s0, v0
800CC0E4	ori    a0, zero, $0001
800CC0E8	ori    a1, zero, $0002
800CC0EC	mflo   a2
800CC0F0	jal    store_memory_block_one_byte [$800bf3ac]
800CC0F4	andi   a2, a2, $00ff
800CC0F8	lui    a0, $8007
800CC0FC	lbu    a0, $22c4(a0)
800CC100	lui    v0, $8008
800CC104	addiu  v0, v0, $31fc
800CC108	sll    a0, a0, $01
800CC10C	addu   a0, a0, v0
800CC110	lhu    v1, $0000(a0)
800CC114	addu   v0, zero, zero
800CC118	addiu  v1, v1, $0004
800CC11C	sh     v1, $0000(a0)
800CC120	lw     ra, $0014(sp)
800CC124	lw     s0, $0010(sp)
800CC128	addiu  sp, sp, $0018
800CC12C	jr     ra 
800CC130	nop
////////////////////////////////



////////////////////////////////
// 0x8A MUL2
800CC134	lui    v0, $800a
800CC138	lbu    v0, $d820(v0)
800CC13C	addiu  sp, sp, $ffe8 (=-$18)
800CC140	sw     ra, $0014(sp)
800CC144	andi   v0, v0, $0003
800CC148	beq    v0, zero, Lcc160 [$800cc160]
800CC14C	sw     s0, $0010(sp)
800CC150	lui    a0, $800a
800CC154	addiu  a0, a0, $0b5c
800CC158	jal    funcbead4 [$800bead4]
800CC15C	ori    a1, zero, $0003

Lcc160:	; 800CC160
800CC160	ori    a0, zero, $0001
800CC164	jal    read_memory_block_two_bytes [$800bf908]
800CC168	ori    a1, zero, $0002
800CC16C	ori    a0, zero, $0002
800CC170	ori    a1, zero, $0003
800CC174	jal    read_memory_block_two_bytes [$800bf908]
800CC178	addu   s0, v0, zero
800CC17C	mult   s0, v0
800CC180	ori    a0, zero, $0001
800CC184	ori    a1, zero, $0002
800CC188	mflo   a2
800CC18C	sll    a2, a2, $10
800CC190	jal    store_memory_block_two_bytes [$800c0248]
800CC194	sra    a2, a2, $10
800CC198	lui    a0, $8007
800CC19C	lbu    a0, $22c4(a0)
800CC1A0	lui    v0, $8008
800CC1A4	addiu  v0, v0, $31fc
800CC1A8	sll    a0, a0, $01
800CC1AC	addu   a0, a0, v0
800CC1B0	lhu    v1, $0000(a0)
800CC1B4	addu   v0, zero, zero
800CC1B8	addiu  v1, v1, $0005
800CC1BC	sh     v1, $0000(a0)
800CC1C0	lw     ra, $0014(sp)
800CC1C4	lw     s0, $0010(sp)
800CC1C8	addiu  sp, sp, $0018
800CC1CC	jr     ra 
800CC1D0	nop
////////////////////////////////



////////////////////////////////
// 0x8B DIV
800CC1D4	lui    v0, $800a
800CC1D8	lbu    v0, $d820(v0)
800CC1DC	addiu  sp, sp, $ffe8 (=-$18)
800CC1E0	sw     ra, $0014(sp)
800CC1E4	andi   v0, v0, $0003
800CC1E8	beq    v0, zero, Lcc200 [$800cc200]
800CC1EC	sw     s0, $0010(sp)
800CC1F0	lui    a0, $800a
800CC1F4	addiu  a0, a0, $0b64
800CC1F8	jal    funcbead4 [$800bead4]
800CC1FC	ori    a1, zero, $0003

Lcc200:	; 800CC200
800CC200	ori    a0, zero, $0001
800CC204	jal    read_memory_block_one_byte [$800bee10]
800CC208	ori    a1, zero, $0002
800CC20C	ori    a0, zero, $0002
800CC210	ori    a1, zero, $0003
800CC214	jal    read_memory_block_one_byte [$800bee10]
800CC218	addu   s0, v0, zero
800CC21C	andi   s0, s0, $00ff
800CC220	andi   v0, v0, $00ff
800CC224	divu   s0, v0
800CC228	bne    v0, zero, Lcc234 [$800cc234]
800CC22C	nop
800CC230	break   $01c00

Lcc234:	; 800CC234
800CC234	mflo   s0
800CC238	ori    a0, zero, $0001
800CC23C	ori    a1, zero, $0002
800CC240	jal    store_memory_block_one_byte [$800bf3ac]
800CC244	addu   a2, s0, zero
800CC248	lui    a0, $8007
800CC24C	lbu    a0, $22c4(a0)
800CC250	lui    v0, $8008
800CC254	addiu  v0, v0, $31fc
800CC258	sll    a0, a0, $01
800CC25C	addu   a0, a0, v0
800CC260	lhu    v1, $0000(a0)
800CC264	addu   v0, zero, zero
800CC268	addiu  v1, v1, $0004
800CC26C	sh     v1, $0000(a0)
800CC270	lw     ra, $0014(sp)
800CC274	lw     s0, $0010(sp)
800CC278	addiu  sp, sp, $0018
800CC27C	jr     ra 
800CC280	nop
////////////////////////////////



////////////////////////////////
// 0x8C DIV2
800CC284	lui    v0, $800a
800CC288	lbu    v0, $d820(v0)
800CC28C	addiu  sp, sp, $ffe8 (=-$18)
800CC290	sw     ra, $0014(sp)
800CC294	andi   v0, v0, $0003
800CC298	beq    v0, zero, Lcc2b0 [$800cc2b0]
800CC29C	sw     s0, $0010(sp)
800CC2A0	lui    a0, $800a
800CC2A4	addiu  a0, a0, $0b68
800CC2A8	jal    funcbead4 [$800bead4]
800CC2AC	ori    a1, zero, $0003

Lcc2b0:	; 800CC2B0
800CC2B0	ori    a0, zero, $0001
800CC2B4	jal    read_memory_block_two_bytes [$800bf908]
800CC2B8	ori    a1, zero, $0002
800CC2BC	ori    a0, zero, $0002
800CC2C0	ori    a1, zero, $0003

Lcc2c4:	; 800CC2C4
800CC2C4	jal    read_memory_block_two_bytes [$800bf908]
800CC2C8	addu   s0, v0, zero
800CC2CC	sll    s0, s0, $10
800CC2D0	sra    s0, s0, $10
800CC2D4	sll    v0, v0, $10
800CC2D8	sra    v0, v0, $10
800CC2DC	div    s0, v0
800CC2E0	bne    v0, zero, Lcc2ec [$800cc2ec]
800CC2E4	nop
800CC2E8	break   $01c00

Lcc2ec:	; 800CC2EC
800CC2EC	addiu  at, zero, $ffff (=-$1)
800CC2F0	bne    v0, at, Lcc304 [$800cc304]
800CC2F4	lui    at, $8000
800CC2F8	bne    s0, at, Lcc304 [$800cc304]
800CC2FC	nop
800CC300	break   $01800

Lcc304:	; 800CC304
800CC304	mflo   s0
800CC308	ori    a0, zero, $0001
800CC30C	ori    a1, zero, $0002
800CC310	sll    s0, s0, $10
800CC314	jal    store_memory_block_two_bytes [$800c0248]
800CC318	sra    a2, s0, $10
800CC31C	lui    a0, $8007
800CC320	lbu    a0, $22c4(a0)
800CC324	lui    v0, $8008
800CC328	addiu  v0, v0, $31fc
800CC32C	sll    a0, a0, $01
800CC330	addu   a0, a0, v0
800CC334	lhu    v1, $0000(a0)
800CC338	addu   v0, zero, zero
800CC33C	addiu  v1, v1, $0005
800CC340	sh     v1, $0000(a0)
800CC344	lw     ra, $0014(sp)
800CC348	lw     s0, $0010(sp)
800CC34C	addiu  sp, sp, $0018
800CC350	jr     ra 
800CC354	nop
////////////////////////////////



////////////////////////////////
// 0x8D MOD
800CC358	lui    v0, $800a
800CC35C	lbu    v0, $d820(v0)
800CC360	addiu  sp, sp, $ffe8 (=-$18)
800CC364	sw     ra, $0014(sp)
800CC368	andi   v0, v0, $0003
800CC36C	beq    v0, zero, Lcc384 [$800cc384]
800CC370	sw     s0, $0010(sp)
800CC374	lui    a0, $800a
800CC378	addiu  a0, a0, $0b70
800CC37C	jal    funcbead4 [$800bead4]
800CC380	ori    a1, zero, $0003

Lcc384:	; 800CC384
800CC384	ori    a0, zero, $0001
800CC388	jal    read_memory_block_one_byte [$800bee10]
800CC38C	ori    a1, zero, $0002
800CC390	ori    a0, zero, $0002
800CC394	ori    a1, zero, $0003
800CC398	jal    read_memory_block_one_byte [$800bee10]
800CC39C	addu   s0, v0, zero
800CC3A0	andi   s0, s0, $00ff
800CC3A4	andi   v0, v0, $00ff
800CC3A8	divu   s0, v0
800CC3AC	bne    v0, zero, Lcc3b8 [$800cc3b8]
800CC3B0	nop
800CC3B4	break   $01c00

Lcc3b8:	; 800CC3B8
800CC3B8	mfhi   a2
800CC3BC	ori    a0, zero, $0001
800CC3C0	jal    store_memory_block_one_byte [$800bf3ac]
800CC3C4	ori    a1, zero, $0002
800CC3C8	lui    a0, $8007
800CC3CC	lbu    a0, $22c4(a0)
800CC3D0	lui    v0, $8008
800CC3D4	addiu  v0, v0, $31fc
800CC3D8	sll    a0, a0, $01
800CC3DC	addu   a0, a0, v0
800CC3E0	lhu    v1, $0000(a0)
800CC3E4	addu   v0, zero, zero
800CC3E8	addiu  v1, v1, $0004
800CC3EC	sh     v1, $0000(a0)
800CC3F0	lw     ra, $0014(sp)
800CC3F4	lw     s0, $0010(sp)
800CC3F8	addiu  sp, sp, $0018
800CC3FC	jr     ra 
800CC400	nop
////////////////////////////////



////////////////////////////////
// 0x8E MOD2
800CC404	lui    v0, $800a
800CC408	lbu    v0, $d820(v0)
800CC40C	addiu  sp, sp, $ffe8 (=-$18)
800CC410	sw     ra, $0014(sp)
800CC414	andi   v0, v0, $0003
800CC418	beq    v0, zero, Lcc430 [$800cc430]
800CC41C	sw     s0, $0010(sp)
800CC420	lui    a0, $800a
800CC424	addiu  a0, a0, $0b78
800CC428	jal    funcbead4 [$800bead4]
800CC42C	ori    a1, zero, $0003

Lcc430:	; 800CC430
800CC430	ori    a0, zero, $0001
800CC434	jal    read_memory_block_two_bytes [$800bf908]
800CC438	ori    a1, zero, $0002
800CC43C	ori    a0, zero, $0002
800CC440	ori    a1, zero, $0003
800CC444	jal    read_memory_block_two_bytes [$800bf908]
800CC448	addu   s0, v0, zero
800CC44C	sll    s0, s0, $10
800CC450	sra    s0, s0, $10
800CC454	sll    v0, v0, $10
800CC458	sra    v0, v0, $10
800CC45C	div    s0, v0
800CC460	bne    v0, zero, Lcc46c [$800cc46c]
800CC464	nop
800CC468	break   $01c00

Lcc46c:	; 800CC46C
800CC46C	addiu  at, zero, $ffff (=-$1)
800CC470	bne    v0, at, Lcc484 [$800cc484]
800CC474	lui    at, $8000
800CC478	bne    s0, at, Lcc484 [$800cc484]
800CC47C	nop
800CC480	break   $01800

Lcc484:	; 800CC484
800CC484	mfhi   a2
800CC488	ori    a0, zero, $0001
800CC48C	ori    a1, zero, $0002
800CC490	sll    a2, a2, $10
800CC494	jal    store_memory_block_two_bytes [$800c0248]
800CC498	sra    a2, a2, $10
800CC49C	lui    a0, $8007
800CC4A0	lbu    a0, $22c4(a0)
800CC4A4	lui    v0, $8008
800CC4A8	addiu  v0, v0, $31fc
800CC4AC	sll    a0, a0, $01
800CC4B0	addu   a0, a0, v0
800CC4B4	lhu    v1, $0000(a0)
800CC4B8	addu   v0, zero, zero
800CC4BC	addiu  v1, v1, $0005
800CC4C0	sh     v1, $0000(a0)
800CC4C4	lw     ra, $0014(sp)
800CC4C8	lw     s0, $0010(sp)
800CC4CC	addiu  sp, sp, $0018
800CC4D0	jr     ra 
800CC4D4	nop
////////////////////////////////



////////////////////////////////
// 0x8F AND
800CB7C0	lui    v0, $800a
800CB7C4	lbu    v0, $d820(v0)
800CB7C8	addiu  sp, sp, $ffe8 (=-$18)
800CB7CC	sw     ra, $0014(sp)
800CB7D0	andi   v0, v0, $0003
800CB7D4	beq    v0, zero, Lcb7ec [$800cb7ec]
800CB7D8	sw     s0, $0010(sp)
800CB7DC	lui    a0, $800a
800CB7E0	addiu  a0, a0, $0af8
800CB7E4	jal    funcbead4 [$800bead4]
800CB7E8	ori    a1, zero, $0003

Lcb7ec:	; 800CB7EC
800CB7EC	ori    a0, zero, $0001
800CB7F0	jal    read_memory_block_one_byte [$800bee10]
800CB7F4	ori    a1, zero, $0002
800CB7F8	ori    a0, zero, $0002
800CB7FC	ori    a1, zero, $0003
800CB800	jal    read_memory_block_one_byte [$800bee10]
800CB804	addu   s0, v0, zero
800CB808	and    s0, s0, v0
800CB80C	ori    a0, zero, $0001
800CB810	ori    a1, zero, $0002
800CB814	jal    store_memory_block_one_byte [$800bf3ac]
800CB818	andi   a2, s0, $00ff
800CB81C	lui    a0, $8007
800CB820	lbu    a0, $22c4(a0)
800CB824	lui    v0, $8008
800CB828	addiu  v0, v0, $31fc
800CB82C	sll    a0, a0, $01
800CB830	addu   a0, a0, v0
800CB834	lhu    v1, $0000(a0)
800CB838	addu   v0, zero, zero
800CB83C	addiu  v1, v1, $0004
800CB840	sh     v1, $0000(a0)
800CB844	lw     ra, $0014(sp)
800CB848	lw     s0, $0010(sp)
800CB84C	addiu  sp, sp, $0018
800CB850	jr     ra 
800CB854	nop
////////////////////////////////



////////////////////////////////
// 0x90 AND2
800CB858	lui    v0, $800a
800CB85C	lbu    v0, $d820(v0)
800CB860	addiu  sp, sp, $ffe8 (=-$18)
800CB864	sw     ra, $0014(sp)
800CB868	andi   v0, v0, $0003
800CB86C	beq    v0, zero, Lcb884 [$800cb884]
800CB870	sw     s0, $0010(sp)
800CB874	lui    a0, $800a
800CB878	addiu  a0, a0, $0afc
800CB87C	jal    funcbead4 [$800bead4]
800CB880	ori    a1, zero, $0003

Lcb884:	; 800CB884
800CB884	ori    a0, zero, $0001
800CB888	jal    read_memory_block_two_bytes [$800bf908]
800CB88C	ori    a1, zero, $0002
800CB890	ori    a0, zero, $0002
800CB894	ori    a1, zero, $0003
800CB898	jal    read_memory_block_two_bytes [$800bf908]
800CB89C	addu   s0, v0, zero
800CB8A0	ori    a0, zero, $0001
800CB8A4	ori    a1, zero, $0002
800CB8A8	and    s0, s0, v0
800CB8AC	sll    s0, s0, $10
800CB8B0	jal    store_memory_block_two_bytes [$800c0248]
800CB8B4	sra    a2, s0, $10
800CB8B8	lui    a0, $8007
800CB8BC	lbu    a0, $22c4(a0)
800CB8C0	lui    v0, $8008
800CB8C4	addiu  v0, v0, $31fc
800CB8C8	sll    a0, a0, $01
800CB8CC	addu   a0, a0, v0
800CB8D0	lhu    v1, $0000(a0)
800CB8D4	addu   v0, zero, zero
800CB8D8	addiu  v1, v1, $0005
800CB8DC	sh     v1, $0000(a0)
800CB8E0	lw     ra, $0014(sp)
800CB8E4	lw     s0, $0010(sp)
800CB8E8	addiu  sp, sp, $0018
800CB8EC	jr     ra 
800CB8F0	nop
////////////////////////////////



////////////////////////////////
// 0x91 OR
800CB8F4	lui    v0, $800a
800CB8F8	lbu    v0, $d820(v0)
800CB8FC	addiu  sp, sp, $ffe8 (=-$18)
800CB900	sw     ra, $0014(sp)
800CB904	andi   v0, v0, $0003
800CB908	beq    v0, zero, Lcb920 [$800cb920]
800CB90C	sw     s0, $0010(sp)
800CB910	lui    a0, $800a
800CB914	addiu  a0, a0, $0b04
800CB918	jal    funcbead4 [$800bead4]
800CB91C	ori    a1, zero, $0003

Lcb920:	; 800CB920
800CB920	ori    a0, zero, $0001
800CB924	jal    read_memory_block_one_byte [$800bee10]
800CB928	ori    a1, zero, $0002
800CB92C	ori    a0, zero, $0002
800CB930	ori    a1, zero, $0003
800CB934	jal    read_memory_block_one_byte [$800bee10]
800CB938	addu   s0, v0, zero
800CB93C	or     s0, s0, v0
800CB940	ori    a0, zero, $0001
800CB944	ori    a1, zero, $0002
800CB948	jal    store_memory_block_one_byte [$800bf3ac]
800CB94C	andi   a2, s0, $00ff
800CB950	lui    a0, $8007
800CB954	lbu    a0, $22c4(a0)
800CB958	lui    v0, $8008
800CB95C	addiu  v0, v0, $31fc
800CB960	sll    a0, a0, $01
800CB964	addu   a0, a0, v0
800CB968	lhu    v1, $0000(a0)
800CB96C	addu   v0, zero, zero
800CB970	addiu  v1, v1, $0004
800CB974	sh     v1, $0000(a0)
800CB978	lw     ra, $0014(sp)
800CB97C	lw     s0, $0010(sp)
800CB980	addiu  sp, sp, $0018
800CB984	jr     ra 
800CB988	nop
////////////////////////////////



////////////////////////////////
// 0x92 OR2
800CB98C	lui    v0, $800a
800CB990	lbu    v0, $d820(v0)
800CB994	addiu  sp, sp, $ffe8 (=-$18)
800CB998	sw     ra, $0014(sp)
800CB99C	andi   v0, v0, $0003
800CB9A0	beq    v0, zero, Lcb9b8 [$800cb9b8]
800CB9A4	sw     s0, $0010(sp)
800CB9A8	lui    a0, $800a
800CB9AC	addiu  a0, a0, $0b08
800CB9B0	jal    funcbead4 [$800bead4]
800CB9B4	ori    a1, zero, $0003

Lcb9b8:	; 800CB9B8
800CB9B8	ori    a0, zero, $0001
800CB9BC	jal    read_memory_block_two_bytes [$800bf908]
800CB9C0	ori    a1, zero, $0002
800CB9C4	ori    a0, zero, $0002
800CB9C8	ori    a1, zero, $0003
800CB9CC	jal    read_memory_block_two_bytes [$800bf908]
800CB9D0	addu   s0, v0, zero
800CB9D4	ori    a0, zero, $0001
800CB9D8	ori    a1, zero, $0002
800CB9DC	or     s0, s0, v0
800CB9E0	sll    s0, s0, $10
800CB9E4	jal    store_memory_block_two_bytes [$800c0248]
800CB9E8	sra    a2, s0, $10
800CB9EC	lui    a0, $8007
800CB9F0	lbu    a0, $22c4(a0)
800CB9F4	lui    v0, $8008
800CB9F8	addiu  v0, v0, $31fc
800CB9FC	sll    a0, a0, $01
800CBA00	addu   a0, a0, v0
800CBA04	lhu    v1, $0000(a0)
800CBA08	addu   v0, zero, zero
800CBA0C	addiu  v1, v1, $0005
800CBA10	sh     v1, $0000(a0)
800CBA14	lw     ra, $0014(sp)
800CBA18	lw     s0, $0010(sp)
800CBA1C	addiu  sp, sp, $0018
800CBA20	jr     ra 
800CBA24	nop
////////////////////////////////



////////////////////////////////
// 0x93 XOR
800CBA28	lui    v0, $800a
800CBA2C	lbu    v0, $d820(v0)
800CBA30	addiu  sp, sp, $ffe8 (=-$18)
800CBA34	sw     ra, $0014(sp)
800CBA38	andi   v0, v0, $0003
800CBA3C	beq    v0, zero, Lcba54 [$800cba54]
800CBA40	sw     s0, $0010(sp)
800CBA44	lui    a0, $800a
800CBA48	addiu  a0, a0, $0b0c
800CBA4C	jal    funcbead4 [$800bead4]
800CBA50	ori    a1, zero, $0003

Lcba54:	; 800CBA54
800CBA54	ori    a0, zero, $0001
800CBA58	jal    read_memory_block_one_byte [$800bee10]
800CBA5C	ori    a1, zero, $0002
800CBA60	ori    a0, zero, $0002
800CBA64	ori    a1, zero, $0003
800CBA68	jal    read_memory_block_one_byte [$800bee10]
800CBA6C	addu   s0, v0, zero
800CBA70	xor    s0, s0, v0
800CBA74	ori    a0, zero, $0001
800CBA78	ori    a1, zero, $0002
800CBA7C	jal    store_memory_block_one_byte [$800bf3ac]
800CBA80	andi   a2, s0, $00ff
800CBA84	lui    a0, $8007
800CBA88	lbu    a0, $22c4(a0)
800CBA8C	lui    v0, $8008
800CBA90	addiu  v0, v0, $31fc
800CBA94	sll    a0, a0, $01
800CBA98	addu   a0, a0, v0
800CBA9C	lhu    v1, $0000(a0)
800CBAA0	addu   v0, zero, zero
800CBAA4	addiu  v1, v1, $0004
800CBAA8	sh     v1, $0000(a0)
800CBAAC	lw     ra, $0014(sp)
800CBAB0	lw     s0, $0010(sp)
800CBAB4	addiu  sp, sp, $0018
800CBAB8	jr     ra 
800CBABC	nop
////////////////////////////////



////////////////////////////////
// 0x94 XOR2
800CBAC0	lui    v0, $800a
800CBAC4	lbu    v0, $d820(v0)
800CBAC8	addiu  sp, sp, $ffe8 (=-$18)
800CBACC	sw     ra, $0014(sp)
800CBAD0	andi   v0, v0, $0003
800CBAD4	beq    v0, zero, Lcbaec [$800cbaec]
800CBAD8	sw     s0, $0010(sp)
800CBADC	lui    a0, $800a
800CBAE0	addiu  a0, a0, $0b10
800CBAE4	jal    funcbead4 [$800bead4]
800CBAE8	ori    a1, zero, $0003

Lcbaec:	; 800CBAEC
800CBAEC	ori    a0, zero, $0001
800CBAF0	jal    read_memory_block_two_bytes [$800bf908]
800CBAF4	ori    a1, zero, $0002
800CBAF8	ori    a0, zero, $0002
800CBAFC	ori    a1, zero, $0003
800CBB00	jal    read_memory_block_two_bytes [$800bf908]
800CBB04	addu   s0, v0, zero
800CBB08	ori    a0, zero, $0001
800CBB0C	ori    a1, zero, $0002
800CBB10	xor    s0, s0, v0
800CBB14	sll    s0, s0, $10
800CBB18	jal    store_memory_block_two_bytes [$800c0248]
800CBB1C	sra    a2, s0, $10
800CBB20	lui    a0, $8007
800CBB24	lbu    a0, $22c4(a0)
800CBB28	lui    v0, $8008
800CBB2C	addiu  v0, v0, $31fc
800CBB30	sll    a0, a0, $01
800CBB34	addu   a0, a0, v0
800CBB38	lhu    v1, $0000(a0)
800CBB3C	addu   v0, zero, zero
800CBB40	addiu  v1, v1, $0005
800CBB44	sh     v1, $0000(a0)
800CBB48	lw     ra, $0014(sp)
800CBB4C	lw     s0, $0010(sp)
800CBB50	addiu  sp, sp, $0018
800CBB54	jr     ra 
800CBB58	nop
////////////////////////////////



////////////////////////////////
// 0x95 INC
800CC4D8	lui    v0, $800a
800CC4DC	lbu    v0, $d820(v0)
800CC4E0	addiu  sp, sp, $ffe8 (=-$18)
800CC4E4	andi   v0, v0, $0003
800CC4E8	beq    v0, zero, Lcc500 [$800cc500]
800CC4EC	sw     ra, $0010(sp)
800CC4F0	lui    a0, $800a
800CC4F4	addiu  a0, a0, $0b80
800CC4F8	jal    funcbead4 [$800bead4]
800CC4FC	ori    a1, zero, $0002

Lcc500:	; 800CC500
800CC500	ori    a0, zero, $0002
800CC504	jal    read_memory_block_one_byte [$800bee10]
800CC508	ori    a1, zero, $0002
800CC50C	addiu  v0, v0, $0001
800CC510	ori    a0, zero, $0002
800CC514	ori    a1, zero, $0002
800CC518	jal    store_memory_block_one_byte [$800bf3ac]
800CC51C	andi   a2, v0, $00ff
800CC520	lui    a0, $8007
800CC524	lbu    a0, $22c4(a0)
800CC528	lui    v0, $8008
800CC52C	addiu  v0, v0, $31fc
800CC530	sll    a0, a0, $01
800CC534	addu   a0, a0, v0
800CC538	lhu    v1, $0000(a0)
800CC53C	addu   v0, zero, zero
800CC540	addiu  v1, v1, $0003
800CC544	sh     v1, $0000(a0)
800CC548	lw     ra, $0010(sp)
800CC54C	addiu  sp, sp, $0018
800CC550	jr     ra 
800CC554	nop
////////////////////////////////



////////////////////////////////
// 0x96 INC2
800CC5EC	lui    v0, $800a
800CC5F0	lbu    v0, $d820(v0)
800CC5F4	addiu  sp, sp, $ffe8 (=-$18)
800CC5F8	andi   v0, v0, $0003
800CC5FC	beq    v0, zero, Lcc614 [$800cc614]
800CC600	sw     ra, $0010(sp)
800CC604	lui    a0, $800a
800CC608	addiu  a0, a0, $0b8c
800CC60C	jal    funcbead4 [$800bead4]
800CC610	ori    a1, zero, $0003

Lcc614:	; 800CC614
800CC614	ori    a0, zero, $0002
800CC618	jal    read_memory_block_two_bytes [$800bf908]
800CC61C	ori    a1, zero, $0002
800CC620	ori    a0, zero, $0002
800CC624	ori    a1, zero, $0002
800CC628	addiu  v0, v0, $0001
800CC62C	sll    v0, v0, $10
800CC630	jal    store_memory_block_two_bytes [$800c0248]
800CC634	sra    a2, v0, $10
800CC638	lui    a0, $8007
800CC63C	lbu    a0, $22c4(a0)
800CC640	lui    v0, $8008
800CC644	addiu  v0, v0, $31fc
800CC648	sll    a0, a0, $01
800CC64C	addu   a0, a0, v0
800CC650	lhu    v1, $0000(a0)
800CC654	addu   v0, zero, zero
800CC658	addiu  v1, v1, $0003
800CC65C	sh     v1, $0000(a0)
800CC660	lw     ra, $0010(sp)
800CC664	addiu  sp, sp, $0018
800CC668	jr     ra 
800CC66C	nop
////////////////////////////////



////////////////////////////////
// 0x97 DEC
800CC70C	lui    v0, $800a
800CC710	lbu    v0, $d820(v0)
800CC714	addiu  sp, sp, $ffe8 (=-$18)
800CC718	andi   v0, v0, $0003
800CC71C	beq    v0, zero, Lcc734 [$800cc734]
800CC720	sw     ra, $0010(sp)
800CC724	lui    a0, $800a
800CC728	addiu  a0, a0, $0b9c
800CC72C	jal    funcbead4 [$800bead4]
800CC730	ori    a1, zero, $0002

Lcc734:	; 800CC734
800CC734	ori    a0, zero, $0002
800CC738	jal    read_memory_block_one_byte [$800bee10]
800CC73C	ori    a1, zero, $0002
800CC740	addiu  v0, v0, $ffff (=-$1)
800CC744	ori    a0, zero, $0002
800CC748	ori    a1, zero, $0002
800CC74C	jal    store_memory_block_one_byte [$800bf3ac]
800CC750	andi   a2, v0, $00ff
800CC754	lui    a0, $8007
800CC758	lbu    a0, $22c4(a0)
800CC75C	lui    v0, $8008
800CC760	addiu  v0, v0, $31fc
800CC764	sll    a0, a0, $01
800CC768	addu   a0, a0, v0
800CC76C	lhu    v1, $0000(a0)
800CC770	addu   v0, zero, zero
800CC774	addiu  v1, v1, $0003
800CC778	sh     v1, $0000(a0)
800CC77C	lw     ra, $0010(sp)
800CC780	addiu  sp, sp, $0018
800CC784	jr     ra 
800CC788	nop
////////////////////////////////



////////////////////////////////
// 0x98 DEC2
800CC824	lui    v0, $800a
800CC828	lbu    v0, $d820(v0)
800CC82C	addiu  sp, sp, $ffe8 (=-$18)
800CC830	andi   v0, v0, $0003
800CC834	beq    v0, zero, Lcc84c [$800cc84c]
800CC838	sw     ra, $0010(sp)
800CC83C	lui    a0, $800a
800CC840	addiu  a0, a0, $0ba8
800CC844	jal    funcbead4 [$800bead4]
800CC848	ori    a1, zero, $0003

Lcc84c:	; 800CC84C
800CC84C	ori    a0, zero, $0002
800CC850	jal    read_memory_block_two_bytes [$800bf908]
800CC854	ori    a1, zero, $0002
800CC858	ori    a0, zero, $0002
800CC85C	ori    a1, zero, $0002
800CC860	addiu  v0, v0, $ffff (=-$1)
800CC864	sll    v0, v0, $10
800CC868	jal    store_memory_block_two_bytes [$800c0248]
800CC86C	sra    a2, v0, $10
800CC870	lui    a0, $8007
800CC874	lbu    a0, $22c4(a0)
800CC878	lui    v0, $8008
800CC87C	addiu  v0, v0, $31fc
800CC880	sll    a0, a0, $01
800CC884	addu   a0, a0, v0
800CC888	lhu    v1, $0000(a0)
800CC88C	addu   v0, zero, zero
800CC890	addiu  v1, v1, $0003
800CC894	sh     v1, $0000(a0)
800CC898	lw     ra, $0010(sp)
800CC89C	addiu  sp, sp, $0018
800CC8A0	jr     ra 
800CC8A4	nop
////////////////////////////////



////////////////////////////////
// 0x99 RANDOM
800CC944	lui    v0, $800a
800CC948	lbu    v0, $d820(v0)
800CC94C	addiu  sp, sp, $ffe8 (=-$18)
800CC950	andi   v0, v0, $0003
800CC954	beq    v0, zero, Lcc96c [$800cc96c]
800CC958	sw     ra, $0010(sp)
800CC95C	lui    a0, $800a
800CC960	addiu  a0, a0, $0bb8
800CC964	jal    funcbead4 [$800bead4]
800CC968	ori    a1, zero, $0002

Lcc96c:	; 800CC96C
800CC96C	lui    v0, $8009
800CC970	lbu    v0, $5dc8(v0)
800CC974	lui    v1, $8005
800CC978	lbu    v1, $a630(v1)
800CC97C	nop
800CC980	addu   v0, v0, v1
800CC984	lui    at, $8009
800CC988	sb     v0, $5dc8(at)
800CC98C	lui    v0, $8009
800CC990	lbu    v0, $5dc8(v0)
800CC994	ori    a0, zero, $0002
800CC998	lui    at, $800e
800CC99C	addiu  at, at, $0638
800CC9A0	addu   at, at, v0
800CC9A4	lbu    a2, $0000(at)
800CC9A8	jal    store_memory_block_one_byte [$800bf3ac]
800CC9AC	ori    a1, zero, $0002
800CC9B0	lui    v1, $8007
800CC9B4	lbu    v1, $22c4(v1)
800CC9B8	lui    v0, $8008
800CC9BC	addiu  v0, v0, $31fc
800CC9C0	sll    v1, v1, $01
800CC9C4	addu   v1, v1, v0
800CC9C8	lhu    v0, $0000(v1)
800CC9CC	nop
800CC9D0	addiu  v0, v0, $0003
800CC9D4	sh     v0, $0000(v1)
800CC9D8	addu   v0, zero, zero
800CC9DC	lw     ra, $0010(sp)
800CC9E0	addiu  sp, sp, $0018
800CC9E4	jr     ra 
800CC9E8	nop
////////////////////////////////



////////////////////////////////
// 0x9A LBYTE
800C0EDC	lui    v0, $800a
800C0EE0	lbu    v0, $d820(v0)
800C0EE4	addiu  sp, sp, $ffe8 (=-$18)
800C0EE8	andi   v0, v0, $0003
800C0EEC	beq    v0, zero, Lc0f04 [$800c0f04]
800C0EF0	sw     ra, $0010(sp)
800C0EF4	lui    a0, $800a
800C0EF8	addiu  a0, a0, $0508
800C0EFC	jal    funcbead4 [$800bead4]
800C0F00	ori    a1, zero, $0003

Lc0f04:	; 800C0F04
800C0F04	ori    a0, zero, $0002
800C0F08	jal    read_memory_block_one_byte [$800bee10]
800C0F0C	ori    a1, zero, $0003
800C0F10	ori    a0, zero, $0001
800C0F14	ori    a1, zero, $0002
800C0F18	jal    store_memory_block_one_byte [$800bf3ac]
800C0F1C	andi   a2, v0, $00ff
800C0F20	lui    v1, $8007
800C0F24	lbu    v1, $22c4(v1)
800C0F28	lui    v0, $8008
800C0F2C	addiu  v0, v0, $31fc
800C0F30	sll    v1, v1, $01
800C0F34	addu   v1, v1, v0
800C0F38	lhu    a0, $0000(v1)
800C0F3C	addu   v0, zero, zero
800C0F40	addiu  a0, a0, $0004
800C0F44	sh     a0, $0000(v1)
800C0F48	lw     ra, $0010(sp)
800C0F4C	addiu  sp, sp, $0018
800C0F50	jr     ra 
800C0F54	nop
////////////////////////////////



////////////////////////////////
// 0x9B HBYTE
800C0F58	lui    v0, $800a
800C0F5C	lbu    v0, $d820(v0)
800C0F60	addiu  sp, sp, $ffe8 (=-$18)
800C0F64	andi   v0, v0, $0003
800C0F68	beq    v0, zero, Lc0f80 [$800c0f80]
800C0F6C	sw     ra, $0010(sp)
800C0F70	lui    a0, $800a
800C0F74	addiu  a0, a0, $0510
800C0F78	jal    funcbead4 [$800bead4]
800C0F7C	ori    a1, zero, $0004

Lc0f80:	; 800C0F80
800C0F80	ori    a0, zero, $0002
800C0F84	jal    read_memory_block_two_bytes [$800bf908]
800C0F88	ori    a1, zero, $0003
800C0F8C	srl    v0, v0, $08
800C0F90	ori    a0, zero, $0001
800C0F94	ori    a1, zero, $0002
800C0F98	jal    store_memory_block_one_byte [$800bf3ac]
800C0F9C	andi   a2, v0, $00ff
800C0FA0	lui    a0, $8007
800C0FA4	lbu    a0, $22c4(a0)
800C0FA8	lui    v0, $8008
800C0FAC	addiu  v0, v0, $31fc
800C0FB0	sll    a0, a0, $01
800C0FB4	addu   a0, a0, v0
800C0FB8	lhu    v1, $0000(a0)
800C0FBC	addu   v0, zero, zero
800C0FC0	addiu  v1, v1, $0005
800C0FC4	sh     v1, $0000(a0)
800C0FC8	lw     ra, $0010(sp)
800C0FCC	addiu  sp, sp, $0018
800C0FD0	jr     ra 
800C0FD4	nop
////////////////////////////////



////////////////////////////////
// 0x9C 2BYTE
800C0FD8	lui    v0, $800a
800C0FDC	lbu    v0, $d820(v0)
800C0FE0	addiu  sp, sp, $ffe8 (=-$18)
800C0FE4	sw     ra, $0014(sp)
800C0FE8	andi   v0, v0, $0003

Lc0fec:	; 800C0FEC
800C0FEC	beq    v0, zero, Lc1004 [$800c1004]
800C0FF0	sw     s0, $0010(sp)
800C0FF4	lui    a0, $800a

funcc0ff8:	; 800C0FF8
800C0FF8	addiu  a0, a0, $0518

Lc0ffc:	; 800C0FFC
800C0FFC	jal    funcbead4 [$800bead4]

Lc1000:	; 800C1000
800C1000	ori    a1, zero, $0005

Lc1004:	; 800C1004
800C1004	ori    a0, zero, $0002
800C1008	jal    read_memory_block_one_byte [$800bee10]

Lc100c:	; 800C100C
800C100C	ori    a1, zero, $0004

Lc1010:	; 800C1010
800C1010	ori    a0, zero, $0004
800C1014	ori    a1, zero, $0005
800C1018	jal    read_memory_block_one_byte [$800bee10]
800C101C	andi   s0, v0, $00ff
800C1020	ori    a0, zero, $0001
800C1024	ori    a1, zero, $0003
800C1028	andi   v0, v0, $00ff
800C102C	sll    v0, v0, $08
800C1030	or     s0, s0, v0
800C1034	sll    s0, s0, $10
800C1038	jal    store_memory_block_two_bytes [$800c0248]
800C103C	sra    a2, s0, $10
800C1040	lui    a0, $8007
800C1044	lbu    a0, $22c4(a0)
800C1048	lui    v0, $8008
800C104C	addiu  v0, v0, $31fc
800C1050	sll    a0, a0, $01
800C1054	addu   a0, a0, v0
800C1058	lhu    v1, $0000(a0)
800C105C	addu   v0, zero, zero
800C1060	addiu  v1, v1, $0006
800C1064	sh     v1, $0000(a0)
800C1068	lw     ra, $0014(sp)
800C106C	lw     s0, $0010(sp)
800C1070	addiu  sp, sp, $0018
800C1074	jr     ra 
800C1078	nop
////////////////////////////////



////////////////////////////////
// 0x9D SETX
800C107C	lui    v0, $800a
800C1080	lbu    v0, $d820(v0)
800C1084	addiu  sp, sp, $ffd8 (=-$28)
800C1088	sw     ra, $0020(sp)
800C108C	sw     s1, $001c(sp)
800C1090	andi   v0, v0, $0003
800C1094	beq    v0, zero, Lc10ac [$800c10ac]
800C1098	sw     s0, $0018(sp)
800C109C	lui    a0, $800a
800C10A0	addiu  a0, a0, $0520
800C10A4	jal    funcbead4 [$800bead4]
800C10A8	ori    a1, zero, $0006

Lc10ac:	; 800C10AC
800C10AC	lui    v0, $8007
800C10B0	lbu    v0, $22c4(v0)
800C10B4	nop
800C10B8	sll    v0, v0, $01
800C10BC	lui    at, $8008
800C10C0	addiu  at, at, $31fc
800C10C4	addu   at, at, v0
800C10C8	lhu    v1, $0000(at)
800C10CC	lui    v0, $800a
800C10D0	lw     v0, $c6dc(v0)
800C10D4	ori    a0, zero, $0002
800C10D8	addu   v0, v0, v1
800C10DC	lbu    s0, $0001(v0)
800C10E0	ori    a1, zero, $0003
800C10E4	jal    read_memory_block_two_bytes [$800bf908]
800C10E8	srl    s0, s0, $04
800C10EC	lui    v1, $8007
800C10F0	lbu    v1, $22c4(v1)
800C10F4	nop
800C10F8	sll    v1, v1, $01
800C10FC	lui    at, $8008
800C1100	addiu  at, at, $31fc
800C1104	addu   at, at, v1
800C1108	lhu    a1, $0000(at)
800C110C	lui    v1, $800a
800C1110	lw     v1, $c6dc(v1)
800C1114	ori    a0, zero, $0004
800C1118	addu   v1, v1, a1
800C111C	lbu    v1, $0003(v1)
800C1120	ori    a1, zero, $0005
800C1124	jal    read_memory_block_one_byte [$800bee10]
800C1128	addu   s1, v1, v0
800C112C	addu   v1, v0, zero
800C1130	addiu  s0, s0, $ffff (=-$1)
800C1134	sltiu  v0, s0, $000f
800C1138	beq    v0, zero, Lc11d4 [$800c11d4]
800C113C	sll    v0, s0, $02
800C1140	lui    at, $800a
800C1144	addiu  at, at, $052c
800C1148	addu   at, at, v0
800C114C	lw     v0, $0000(at)
800C1150	nop
800C1154	jr     v0 
800C1158	nop

800C115C	addiu  s1, s1, $0100
800C1160	addiu  s1, s1, $0100
800C1164	addiu  s1, s1, $0100
800C1168	addiu  s1, s1, $0100
800C116C	sll    v0, s1, $10
800C1170	sra    v0, v0, $10
800C1174	slti   v0, v0, $0500
800C1178	bne    v0, zero, Lc1188 [$800c1188]
800C117C	sll    v0, s1, $10
800C1180	ori    s1, zero, $04ff
800C1184	sll    v0, s1, $10

Lc1188:	; 800C1188
800C1188	sra    v0, v0, $10
800C118C	lui    at, $800a
800C1190	addiu  at, at, $d288 (=-$2d78)
800C1194	addu   at, at, v0
800C1198	sb     v1, $0000(at)
800C119C	j      Lc11d4 [$800c11d4]
800C11A0	nop
800C11A4	sll    v0, s1, $10
800C11A8	sra    v0, v0, $10
800C11AC	slti   v0, v0, $0100
800C11B0	bne    v0, zero, Lc11c0 [$800c11c0]
800C11B4	sll    v0, s1, $10
800C11B8	ori    s1, zero, $00ff
800C11BC	sll    v0, s1, $10

Lc11c0:	; 800C11C0
800C11C0	sra    v0, v0, $10
800C11C4	lui    at, $8007
800C11C8	addiu  at, at, $5e24
800C11CC	addu   at, at, v0
800C11D0	sb     v1, $0000(at)

Lc11d4:	; 800C11D4
800C11D4	lui    v1, $8007
800C11D8	lbu    v1, $22c4(v1)
800C11DC	lui    v0, $8008
800C11E0	addiu  v0, v0, $31fc
800C11E4	sll    v1, v1, $01
800C11E8	addu   v1, v1, v0
800C11EC	lhu    a0, $0000(v1)
800C11F0	addu   v0, zero, zero
800C11F4	addiu  a0, a0, $0007
800C11F8	sh     a0, $0000(v1)
800C11FC	lw     ra, $0020(sp)
800C1200	lw     s1, $001c(sp)
800C1204	lw     s0, $0018(sp)
800C1208	addiu  sp, sp, $0028
800C120C	jr     ra 
800C1210	nop
////////////////////////////////



////////////////////////////////
// 0x9E GETX
800C1214	lui    v0, $800a
800C1218	lbu    v0, $d820(v0)
800C121C	addiu  sp, sp, $ffd8 (=-$28)
800C1220	sw     ra, $0020(sp)
800C1224	sw     s1, $001c(sp)
800C1228	andi   v0, v0, $0003
800C122C	beq    v0, zero, Lc1244 [$800c1244]
800C1230	sw     s0, $0018(sp)
800C1234	lui    a0, $800a
800C1238	addiu  a0, a0, $0568
800C123C	jal    funcbead4 [$800bead4]
800C1240	ori    a1, zero, $0006

Lc1244:	; 800C1244
800C1244	lui    v0, $8007
800C1248	lbu    v0, $22c4(v0)
800C124C	nop
800C1250	sll    v0, v0, $01
800C1254	lui    at, $8008
800C1258	addiu  at, at, $31fc
800C125C	addu   at, at, v0
800C1260	lhu    v1, $0000(at)
800C1264	lui    v0, $800a
800C1268	lw     v0, $c6dc(v0)
800C126C	ori    a0, zero, $0002
800C1270	addu   v0, v0, v1
800C1274	lbu    s0, $0001(v0)
800C1278	ori    a1, zero, $0003
800C127C	jal    read_memory_block_two_bytes [$800bf908]
800C1280	srl    s0, s0, $04
800C1284	lui    v1, $8007
800C1288	lbu    v1, $22c4(v1)
800C128C	nop
800C1290	sll    v1, v1, $01
800C1294	lui    at, $8008
800C1298	addiu  at, at, $31fc
800C129C	addu   at, at, v1
800C12A0	lhu    a0, $0000(at)
800C12A4	lui    v1, $800a
800C12A8	lw     v1, $c6dc(v1)
800C12AC	nop
800C12B0	addu   v1, v1, a0
800C12B4	lbu    v1, $0003(v1)
800C12B8	addiu  s0, s0, $ffff (=-$1)
800C12BC	addu   v1, v1, v0
800C12C0	sltiu  v0, s0, $000f
800C12C4	beq    v0, zero, Lc1360 [$800c1360]
800C12C8	sll    v0, s0, $02
800C12CC	lui    at, $800a
800C12D0	addiu  at, at, $0574
800C12D4	addu   at, at, v0
800C12D8	lw     v0, $0000(at)
800C12DC	nop
800C12E0	jr     v0 
800C12E4	nop

800C12E8	addiu  v1, v1, $0100
800C12EC	addiu  v1, v1, $0100
800C12F0	addiu  v1, v1, $0100
800C12F4	addiu  v1, v1, $0100
800C12F8	sll    v0, v1, $10
800C12FC	sra    v0, v0, $10
800C1300	slti   v0, v0, $0500
800C1304	bne    v0, zero, Lc1310 [$800c1310]
800C1308	ori    a0, zero, $0004
800C130C	ori    v1, zero, $04ff

Lc1310:	; 800C1310
800C1310	sll    v0, v1, $10
800C1314	sra    v0, v0, $10
800C1318	lui    at, $800a
800C131C	addiu  at, at, $d288 (=-$2d78)
800C1320	addu   at, at, v0
800C1324	lbu    s1, $0000(at)
800C1328	j      Lc1368 [$800c1368]
800C132C	ori    a1, zero, $0005
800C1330	sll    v0, v1, $10
800C1334	sra    v0, v0, $10
800C1338	slti   v0, v0, $0100
800C133C	bne    v0, zero, Lc134c [$800c134c]
800C1340	sll    v0, v1, $10
800C1344	ori    v1, zero, $00ff
800C1348	sll    v0, v1, $10

Lc134c:	; 800C134C
800C134C	sra    v0, v0, $10
800C1350	lui    at, $8007
800C1354	addiu  at, at, $5e24
800C1358	addu   at, at, v0
800C135C	lbu    s1, $0000(at)

Lc1360:	; 800C1360
800C1360	ori    a0, zero, $0004
800C1364	ori    a1, zero, $0005

Lc1368:	; 800C1368
800C1368	jal    store_memory_block_one_byte [$800bf3ac]
800C136C	andi   a2, s1, $00ff
800C1370	lui    v1, $8007
800C1374	lbu    v1, $22c4(v1)
800C1378	lui    v0, $8008
800C137C	addiu  v0, v0, $31fc
800C1380	sll    v1, v1, $01
800C1384	addu   v1, v1, v0
800C1388	lhu    a0, $0000(v1)
800C138C	addu   v0, zero, zero
800C1390	addiu  a0, a0, $0007
800C1394	sh     a0, $0000(v1)
800C1398	lw     ra, $0020(sp)
800C139C	lw     s1, $001c(sp)
800C13A0	lw     s0, $0018(sp)
800C13A4	addiu  sp, sp, $0028
800C13A8	jr     ra 
800C13AC	nop
////////////////////////////////



////////////////////////////////
// 0x9F SEARCHX
field_file_offset     = w[8009c6dc];
current_entity        = bu[800722c4];
script_pointer_offset = 800831fc + current_entity * 2;
script = field_file_offset + hu[script_pointer_offset];

S0 = bu[script + 1] >> 4;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;
S2 = bu[script + 4] + V0; // diapason start

A0 = 3;
A1 = 7;
read_memory_block_two_bytes;
S1 = bu[script + 4] + V0; // diapason end

A0 = 4;
A1 = 9;
read_memory_block_one_byte;
search_x = V0;

switch( S0 )
{
    case f: // D4140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case d: // DC140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case b: // E4140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case 3: // EC140C80
    {
        S2 = S2 + 100;
        S1 = S1 + 100;
    }

    case 1: // F4140C80
    {
        if( S2 >= 500 )
        {
            S2 = 4ff;
        }

        if( S1 >= 500 )
        {
            S1 = 4ff;
        }

        if( S1 >= S2 )
        {
            loopc1540:	; 800C1540
                if( bu[8009c6e4 + ba4 + S2] == search_x )
                {
                    A0 = 6;
                    A1 = a;
                    A2 = S2;
                    store_memory_block_two_bytes;

                    [script_pointer_offset] = h(hu[script_pointer_offset] + b);
                    return;
                }

                S2 = S2 + 1;
                V0 = S1 < S2;
            800C1570	beq    v0, zero, loopc1540 [$800c1540]
        }
    }
    break;

    case 5: // 98150C80
    {
        if( S2 >= 100 )
        {
            S2 = ff;
        }

        if( S1 >= 100 )
        {
            S1 = ff;
        }

        if( S1 >= S2 )
        {
            loopc15e4:	; 800C15E4
                if( bu[80075e24 + S2] == search_x )
                {
                    A0 = 6;
                    A1 = a;
                    A2 = S2;
                    store_memory_block_two_bytes;

                    [script_pointer_offset] = h(hu[script_pointer_offset] + b);
                    return;
                }

                S2 = S2 + 1;
                V0 = S1 < S2;
            800C1614	beq    v0, zero, loopc15e4 [$800c15e4]
        }
    }
    break
}

A0 = 6;
A1 = a;
A2 = -1;
store_memory_block_two_bytes;

[script_pointer_offset] = h(hu[script_pointer_offset] + b);
////////////////////////////////



////////////////////////////////
// 0xD4 SIN
A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
A0 = V0;
system_get_sin;
S0 = V0;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;

HI/LO = S0 * V0;
S0 = LO;

A0 = 3;
A1 = 7;
read_memory_block_two_bytes
S0 = S0 + V0;

A0 = 4;
A1 = 9;
A2 = S0 >> 0C;
store_memory_block_two_bytes;

A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + A;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// 0xD5 COS
A0 = 1;
A1 = 3;
read_memory_block_two_bytes;
A0 = V0;
system_get_cos;
S0 = V0;

A0 = 2;
A1 = 5;
read_memory_block_two_bytes;

S0 = S0 * V0;

A0 = 3;
A1 = 7;
read_memory_block_two_bytes
S0 = S0 + V0;

A0 = 4;
A1 = 9;
A2 = S0 >> 0C;
store_memory_block_two_bytes;

A0 = bu[800722C4];
V1 = hu[800831FC + A0 * 2];
V1 = V1 + A;
[800831FC + A0 * 2] = h(V1);

return 0;
////////////////////////////////



////////////////////////////////
// system_get_cos
if (A0 < 0)
{
    A0 = 0 - A0;
}

A0 = A0 & 0fff;
if (A0 < 801)
{
    if (A0 < 401)
    {
        V0 = 400;
        V0 = V0 - A0;
        V0 = V0 * 2;
        V0 = h[8004AE54 + V0];
    }
    else
    {
        V0 = A0 * 2;
        V0 = h[8004A654 + V0];
        V0 = 0 - V0;
    }
}
else
{
    if (A0 >= c01)
    {
        V0 = A0 * 2;
        V0 = h[8004A654 + V0];
    }
    else
    {
        V0 = c00;
        V0 = V0 - A0;
        V0 = V0 * 2;
        V0 = h[8004AE54 + V0];
        V0 = 0 - V0;
    }
}

return;
////////////////////////////////