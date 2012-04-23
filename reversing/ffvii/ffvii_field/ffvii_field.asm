////////////////////////////////
// funca1368
800A1368-800A1494
////////////////////////////////



////////////////////////////////
// field_stop_load_background_in_advance
800A1498-800A14D4
////////////////////////////////



////////////////////////////////
// field_check_and_set_load_background_in_advance
800A14D8-800A16C8
////////////////////////////////



////////////////////////////////
// funca16cc
800A16CC-800A2310
////////////////////////////////



////////////////////////////////
// contain move and button update, animation handler and many others
// model new structure initing also here
// funca2314
800A2314-800A2D58
////////////////////////////////



////////////////////////////////
// funca2d5c
800A2D5C-800A2F74
////////////////////////////////



////////////////////////////////
// funca2f78
800A2F78-800A301C
////////////////////////////////



////////////////////////////////
// funca3020
800A3020-800A3648
////////////////////////////////



////////////////////////////////
// funca364c
800A364C-800A4090
////////////////////////////////



////////////////////////////////
// calculate_current_value_by_steps
800A4094-800A4130
////////////////////////////////



////////////////////////////////
// calculate_smooth_current_value_by_steps
800A4134-800A41C8
////////////////////////////////



////////////////////////////////
// field_calculate_distance_to_screen
800A41CC-800A4248
////////////////////////////////



////////////////////////////////
// field_update_shaking
800A424C-800A442C
////////////////////////////////



////////////////////////////////
// funca4430
800A4430-800A45D0
////////////////////////////////



funca45d4:	; 800A45D4
800A45D4	addiu  sp, sp, $fff0 (=-$10)
800A45D8	addu   t3, a0, zero
800A45DC	lbu    v1, $0014(t3)
800A45E0	ori    v0, zero, $0001
800A45E4	bne    v1, v0, La46e4 [$800a46e4]
800A45E8	addu   t4, a1, zero
800A45EC	lh     v1, $0000(t4)
800A45F0	lh     t0, $000c(t3)
800A45F4	lh     a2, $0010(t3)
800A45F8	addiu  v1, v1, $ff60 (=-$a0)
800A45FC	subu   v1, t0, v1
800A4600	addiu  v0, t0, $0140
800A4604	subu   a2, a2, v0
800A4608	mult   v1, a2
800A460C	lh     a0, $0012(t3)
800A4610	lh     v1, $0002(t4)
800A4614	lh     v0, $000e(t3)
800A4618	addiu  v1, v1, $ff88 (=-$78)
800A461C	subu   v1, v0, v1
800A4620	mflo   a1
800A4624	addiu  v0, v0, $00f0
800A4628	subu   a0, a0, v0
800A462C	mult   v1, a0
800A4630	mflo   v0
800A4634	mult   a2, a2
800A4638	mflo   v1
800A463C	mult   a0, a0
800A4640	mflo   a3
800A4644	addu   a1, a1, v0
800A4648	subu   t2, zero, a1
800A464C	mult   t2, a2
800A4650	mflo   v0
800A4654	addu   v1, v1, a3
800A4658	sra    a2, v1, $08
800A465C	div    v0, a2
800A4684	mflo   v0
800A4688	mult   t2, a0
800A468C	mflo   v1
800A4690	div    v1, a2
800A46B8	mflo   v1
800A46BC	sra    v0, v0, $08
800A46C0	addiu  v0, v0, $00a0
800A46C4	addu   v0, v0, t0
800A46C8	sh     v0, $0000(t4)
800A46CC	lhu    v0, $000e(t3)
800A46D0	sra    v1, v1, $08
800A46D4	addiu  v1, v1, $0078
800A46D8	addu   v1, v1, v0
800A46DC	sh     v1, $0002(t4)
800A46E0	lbu    v1, $0014(t3)

La46e4:	; 800A46E4
800A46E4	ori    v0, zero, $0002
800A46E8	bne    v1, v0, La47ec [$800a47ec]
800A46EC	nop
800A46F0	lh     v1, $0000(t4)
800A46F4	lh     t1, $000c(t3)
800A46F8	lh     t0, $0010(t3)
800A46FC	addiu  v1, v1, $ff60 (=-$a0)
800A4700	subu   v1, t1, v1
800A4704	addiu  v0, t1, $0140
800A4708	subu   t0, t0, v0
800A470C	mult   v1, t0
800A4710	lh     a2, $0012(t3)
800A4714	nop
800A4718	addiu  a1, a2, $ff10 (=-$f0)
800A471C	lh     v0, $0002(t4)
800A4720	lh     v1, $000e(t3)
800A4724	addiu  v0, v0, $0078
800A4728	mflo   a3
800A472C	subu   v0, a2, v0
800A4730	subu   a1, v1, a1
800A4734	mult   v0, a1
800A4738	mflo   v0
800A473C	mult   t0, t0
800A4740	mflo   a0
800A4744	subu   v1, v1, a2
800A4748	mult   v1, a1
800A474C	mflo   v1
800A4750	addu   a3, a3, v0
800A4754	subu   t2, zero, a3
800A4758	mult   t2, t0
800A475C	mflo   v0
800A4760	addu   a0, a0, v1
800A4764	sra    a2, a0, $08
800A4768	div    v0, a2
800A4790	mflo   v0
800A4794	mult   t2, a1
800A4798	mflo   v1
800A479C	div    v1, a2
800A47C4	mflo   v1
800A47C8	sra    v0, v0, $08
800A47CC	addiu  v0, v0, $00a0
800A47D0	addu   v0, v0, t1
800A47D4	sh     v0, $0000(t4)
800A47D8	lhu    v0, $0012(t3)
800A47DC	sra    v1, v1, $08
800A47E0	addiu  v1, v1, $ff88 (=-$78)
800A47E4	addu   v1, v1, v0

La47e8:	; 800A47E8
800A47E8	sh     v1, $0002(t4)

La47ec:	; 800A47EC
800A47EC	addiu  sp, sp, $0010
800A47F0	jr     ra 
800A47F4	nop


funca47f8:	; 800A47F8
800A47F8	lui    v0, $8007
800A47FC	lw     v0, $16c4(v0)
800A4800	nop
800A4804	lh     v0, $0010(v0)
800A4808	lh     v1, $0000(a0)
800A480C	addu   a1, v0, zero
800A4810	addiu  v0, v0, $ff60 (=-$a0)
800A4814	slt    v0, v0, v1
800A4818	beq    v0, zero, La4828 [$800a4828]
800A481C	addiu  sp, sp, $ffe0 (=-$20)
800A4820	addiu  v0, a1, $ff60 (=-$a0)
800A4824	sh     v0, $0000(a0)

La4828:	; 800A4828
800A4828	lui    v0, $8007
800A482C	lw     v0, $16c4(v0)
800A4830	nop
800A4834	lh     v1, $000c(v0)
800A4838	lh     v0, $0000(a0)
800A483C	addu   a1, v1, zero
800A4840	addiu  v1, v1, $00a0
800A4844	slt    v0, v0, v1
800A4848	beq    v0, zero, La4854 [$800a4854]
800A484C	addiu  v0, a1, $00a0
800A4850	sh     v0, $0000(a0)

La4854:	; 800A4854
800A4854	lui    v0, $8007
800A4858	lw     v0, $16c4(v0)
800A485C	nop
800A4860	lh     v0, $0012(v0)
800A4864	lh     v1, $0002(a0)
800A4868	addu   a1, v0, zero
800A486C	addiu  v0, v0, $ff88 (=-$78)
800A4870	slt    v0, v0, v1
800A4874	beq    v0, zero, La4880 [$800a4880]
800A4878	addiu  v0, a1, $ff88 (=-$78)
800A487C	sh     v0, $0002(a0)

La4880:	; 800A4880
800A4880	lui    v0, $8007
800A4884	lw     v0, $16c4(v0)
800A4888	nop
800A488C	lh     v1, $000e(v0)
800A4890	lh     v0, $0002(a0)
800A4894	addu   a1, v1, zero
800A4898	addiu  v1, v1, $0078
800A489C	slt    v0, v0, v1
800A48A0	beq    v0, zero, La48ac [$800a48ac]
800A48A4	addiu  v0, a1, $0078
800A48A8	sh     v0, $0002(a0)

La48ac:	; 800A48AC
800A48AC	addiu  sp, sp, $0020
800A48B0	jr     ra 
800A48B4	nop


funca48b8:	; 800A48B8
800A48B8	addiu  sp, sp, $ffe0 (=-$20)
800A48BC	addu   a1, a0, zero
800A48C0	lui    a0, $800a
800A48C4	addiu  a0, a0, $ac12 (=-$53ee)
800A48C8	sw     ra, $0018(sp)
800A48CC	lbu    v1, $0000(a0)
800A48D0	nop
800A48D4	sll    v0, v1, $05
800A48D8	addu   v0, v0, v1
800A48DC	sll    v0, v0, $02
800A48E0	lui    at, $8007
800A48E4	addiu  at, at, $4eb0
800A48E8	addu   at, at, v0
800A48EC	lw     v0, $0000(at)
800A48F0	lbu    v1, $0000(a0)
800A48F4	sra    v0, v0, $0c
800A48F8	sh     v0, $0010(sp)
800A48FC	sll    v0, v1, $05
800A4900	addu   v0, v0, v1
800A4904	sll    v0, v0, $02
800A4908	lui    at, $8007
800A490C	addiu  at, at, $4eb4
800A4910	addu   at, at, v0
800A4914	lw     v0, $0000(at)
800A4918	lbu    v1, $0000(a0)
800A491C	addiu  a0, sp, $0010
800A4920	sra    v0, v0, $0c
800A4924	sh     v0, $0012(sp)
800A4928	sll    v0, v1, $05
800A492C	addu   v0, v0, v1
800A4930	sll    v0, v0, $02
800A4934	lui    at, $8007

La4938:	; 800A4938
800A4938	addiu  at, at, $4eb8
800A493C	addu   at, at, v0
800A4940	lw     v0, $0000(at)
800A4944	lui    v1, $800a
800A4948	lhu    v1, $ac0a(v1)
800A494C	sra    v0, v0, $0c
800A4950	addu   v0, v0, v1
800A4954	jal    field_calculate_distance_to_screen [$800a41cc]
800A4958	sh     v0, $0014(sp)
800A495C	lw     ra, $0018(sp)
800A4960	addiu  sp, sp, $0020
800A4964	jr     ra 
800A4968	nop



////////////////////////////////
// funca496c
800A496C-800A4BE8
////////////////////////////////



////////////////////////////////
// funca4bec
800A4BEC-800A5FB0
////////////////////////////////



////////////////////////////////
// funca5fb4
800A5FB4-800A6358
////////////////////////////////



////////////////////////////////
// move_add_shift_rotate
800A635C-800A6414
////////////////////////////////



////////////////////////////////
// handle_animation_update
800A6418-800A65A0
////////////////////////////////



////////////////////////////////
// handle_update
800A65A4-800A829C
////////////////////////////////



////////////////////////////////
// set_gateway_to_map_load
800A82A0-800A8300
////////////////////////////////



////////////////////////////////
// we check talk here
// funca8304
800A8304-800A85FC
////////////////////////////////



////////////////////////////////
// get_direction_vector_x
800A8600-800A861C
////////////////////////////////



////////////////////////////////
// get_direction_vector_y
800A8620-800A863C
////////////////////////////////



////////////////////////////////
// calculate_direction_by_vectors
800A8640-800A8854
////////////////////////////////



////////////////////////////////
// La8858
800A8858-800A8964
////////////////////////////////



////////////////////////////////
// walkmesh_border_cross
800A8968-800A8DF0
////////////////////////////////



////////////////////////////////
// walkmesh_vector_sub
800A8DF4-800A8E30
////////////////////////////////



////////////////////////////////
// walkmesh_calculate_z
800A8E34-800A8F84
////////////////////////////////



////////////////////////////////
// main_walkmesh_move
800A8F88-800A9B60
////////////////////////////////



////////////////////////////////
// entity_collision_check
800A9B64-800A9CE4
////////////////////////////////



////////////////////////////////
// move_distance_to_line
800A9CE8-800A9EE8
////////////////////////////////



////////////////////////////////
// move_line_check
800A9EEC-800AA17C
////////////////////////////////



////////////////////////////////
// move_talk_to_line
800AA180-800AA328
////////////////////////////////



////////////////////////////////
// line_clear_entity_in_line
800AA32C-800AA344
////////////////////////////////



////////////////////////////////
// move_gateway_check
800AA348-800AA510
////////////////////////////////



////////////////////////////////
// trigger_background_manipulate
800AA514-800AA5E0
////////////////////////////////



////////////////////////////////
// move_trigger_check
800AA5E4-800AA86C
////////////////////////////////



////////////////////////////////
// field_init_triggered_background_state
800AA870-800AA92C
////////////////////////////////



////////////////////////////////
// we call function that init 0x24 model data structure here
// funcaa930
800AA930-800AAB20
////////////////////////////////



////////////////////////////////
// funcaab24
800AAB24-800AB2A8
////////////////////////////////



funcab2ac:	; 800AB2AC
800AB2AC	jr     ra 
800AB2B0	nop


funcab2b4:	; 800AB2B4
800AB2B4	lui    v0, $8011
800AB2B8	lhu    v0, $4488(v0)
800AB2BC	nop
800AB2C0	beq    v0, zero, Lab2dc [$800ab2dc]
800AB2C4	ori    v0, zero, $0001
800AB2C8	lui    v1, $800a
800AB2CC	lbu    v1, $ac2d(v1)
800AB2D0	nop
800AB2D4	bne    v1, v0, Lab2f4 [$800ab2f4]
800AB2D8	nop

Lab2dc:	; 800AB2DC
800AB2DC	lui    v0, $8008
800AB2E0	lw     v0, $3578(v0)
800AB2E4	nop
800AB2E8	lw     v0, $0000(v0)
800AB2EC	j      Lab2fc [$800ab2fc]
800AB2F0	nop

Lab2f4:	; 800AB2F4
800AB2F4	lui    v0, $8008
800AB2F8	lw     v0, $3270(v0)

Lab2fc:	; 800AB2FC
800AB2FC	nop
800AB300	lui    at, $8007
800AB304	sw     v0, $1e40(at)
800AB308	jr     ra 
800AB30C	nop


funcab310:	; 800AB310
800AB310	addiu  sp, sp, $ffe8 (=-$18)
800AB314	lui    v1, $8009
800AB318	lh     v1, $65e8(v1)
800AB31C	ori    v0, zero, $0001
800AB320	sw     ra, $0014(sp)
800AB324	bne    v1, v0, Lab34c [$800ab34c]
800AB328	sw     s0, $0010(sp)
800AB32C	jal    func34b44 [$80034b44]
800AB330	nop
800AB334	bne    v0, zero, Lab498 [$800ab498]
800AB338	ori    v0, zero, $0002
800AB33C	lui    at, $8009
800AB340	sh     v0, $65e8(at)
800AB344	j      Lab498 [$800ab498]
800AB348	nop

Lab34c:	; 800AB34C
800AB34C	lui    s0, $800a
800AB350	addiu  s0, s0, $abf5 (=-$540b)
800AB354	lbu    v1, $0000(s0)
800AB358	ori    v0, zero, $0014
800AB35C	bne    v1, v0, Lab374 [$800ab374]
800AB360	nop
800AB364	jal    func35658 [$80035658]
800AB368	nop
800AB36C	j      Lab434 [$800ab434]
800AB370	ori    v0, zero, $0002

Lab374:	; 800AB374
800AB374	jal    func34b44 [$80034b44]
800AB378	nop
800AB37C	addu   v1, v0, zero
800AB380	beq    v1, zero, Lab398 [$800ab398]
800AB384	ori    v0, zero, $000a
800AB388	beq    v1, v0, Lab454 [$800ab454]
800AB38C	ori    v0, zero, $0003
800AB390	j      Lab498 [$800ab498]
800AB394	nop

Lab398:	; 800AB398
800AB398	lbu    v1, $0000(s0)
800AB39C	ori    v0, zero, $0003
800AB3A0	bne    v1, v0, Lab40c [$800ab40c]
800AB3A4	nop
800AB3A8	lui    v0, $800a
800AB3AC	lh     v0, $ac1a(v0)
800AB3B0	nop
800AB3B4	bne    v0, zero, Lab40c [$800ab40c]
800AB3B8	lui    v0, $801a
800AB3BC	lui    a0, $8007
800AB3C0	lw     a0, $5e10(a0)
800AB3C4	ori    v0, v0, $ffff
800AB3C8	sltu   v0, v0, a0
800AB3CC	bne    v0, zero, Lab3e4 [$800ab3e4]
800AB3D0	nop
800AB3D4	lui    a1, $800a
800AB3D8	lh     a1, $abf6(a1)
800AB3DC	j      Lab3f0 [$800ab3f0]
800AB3E0	nop

Lab3e4:	; 800AB3E4
800AB3E4	lui    a1, $800a
800AB3E8	lh     a1, $abf6(a1)
800AB3EC	lui    a0, $801b

Lab3f0:	; 800AB3F0
800AB3F0	jal    func34fc8 [$80034fc8]
800AB3F4	nop
800AB3F8	ori    v0, zero, $0001
800AB3FC	lui    at, $800a
800AB400	sh     v0, $ac1a(at)
800AB404	lui    at, $800e
800AB408	sh     v0, $4d44(at)

Lab40c:	; 800AB40C
800AB40C	lui    v0, $8011
800AB410	lhu    v0, $4488(v0)
800AB414	ori    v1, zero, $0001
800AB418	sll    v0, v0, $10
800AB41C	sra    v0, v0, $10
800AB420	bne    v0, v1, Lab498 [$800ab498]
800AB424	ori    v0, zero, $0001
800AB428	lui    at, $8011
800AB42C	sh     v0, $42c8(at)
800AB430	ori    v0, zero, $0002

Lab434:	; 800AB434
800AB434	lui    at, $8011
800AB438	sh     zero, $4488(at)
800AB43C	lui    at, $800e
800AB440	sh     zero, $4d44(at)
800AB444	lui    at, $800a
800AB448	sh     v0, $ac1a(at)
800AB44C	j      Lab498 [$800ab498]
800AB450	nop

Lab454:	; 800AB454
800AB454	lbu    v1, $0000(s0)
800AB458	nop
800AB45C	bne    v1, v0, Lab478 [$800ab478]
800AB460	ori    v0, zero, $0004
800AB464	ori    v0, zero, $0002
800AB468	lui    at, $800a
800AB46C	sh     v0, $ac1a(at)
800AB470	lbu    v1, $0000(s0)
800AB474	ori    v0, zero, $0004

Lab478:	; 800AB478
800AB478	bne    v1, v0, Lab498 [$800ab498]
800AB47C	ori    s0, zero, $0001
800AB480	lui    at, $800a
800AB484	sh     s0, $ac1a(at)
800AB488	jal    func354cc [$800354cc]
800AB48C	nop
800AB490	lui    at, $8011
800AB494	sh     s0, $4488(at)

Lab498:	; 800AB498
800AB498	lw     ra, $0014(sp)
800AB49C	lw     s0, $0010(sp)
800AB4A0	addiu  sp, sp, $0018
800AB4A4	jr     ra 
800AB4A8	nop



////////////////////////////////
// funcab4ac
800AB4AC-800AB5E4
////////////////////////////////



funcab5e8:	; 800AB5E8
800AB5E8	addiu  sp, sp, $ffc0 (=-$40)
800AB5EC	sw     s6, $0030(sp)
800AB5F0	addu   s6, a0, zero
800AB5F4	sw     s1, $001c(sp)
800AB5F8	addu   s1, a1, zero
800AB5FC	sw     s0, $0018(sp)
800AB600	addu   s0, a2, zero
800AB604	sw     s7, $0034(sp)
800AB608	addu   s7, a3, zero
800AB60C	sw     ra, $0038(sp)
800AB610	sw     s5, $002c(sp)
800AB614	sw     s4, $0028(sp)
800AB618	sw     s3, $0024(sp)
800AB61C	jal    func3ae38 [$8003ae38]
800AB620	sw     s2, $0020(sp)
800AB624	jal    PsyQSetRotMatrix [$8003b48c]
800AB628	addu   a0, s0, zero
800AB62C	jal    PsyQSetTransMatrix [$8003b51c]
800AB630	addu   a0, s0, zero
800AB634	addu   s4, zero, zero
800AB638	addiu  s5, sp, $0014
800AB63C	lui    v0, $800e
800AB640	addiu  v0, v0, $42d8
800AB644	addiu  s3, v0, $0008
800AB648	addu   s2, v0, zero
800AB64C	addu   s0, zero, zero

loopab650:	; 800AB650
800AB650	lui    at, $800e
800AB654	addiu  at, at, $42ee
800AB658	addu   at, at, s0
800AB65C	lh     v1, $0000(at)
800AB660	ori    v0, zero, $0001
800AB664	bne    v1, v0, Lab6a0 [$800ab6a0]
800AB668	addiu  s0, s0, $0018
800AB66C	addu   a0, s2, zero
800AB670	addiu  a1, s1, $0008
800AB674	addiu  a2, sp, $0010
800AB678	jal    PsyQRotTransPers [$8003bbdc]
800AB67C	addu   a3, s5, zero
800AB680	addu   a0, s3, zero
800AB684	addiu  a1, s1, $000c
800AB688	addiu  a2, sp, $0010
800AB68C	jal    PsyQRotTransPers [$8003bbdc]
800AB690	addu   a3, s5, zero
800AB694	addu   a0, s6, zero
800AB698	jal    system_add_render_packet_to_queue [$80046794]
800AB69C	addu   a1, s1, zero

Lab6a0:	; 800AB6A0
800AB6A0	addiu  s1, s1, $0010
800AB6A4	addiu  s3, s3, $0018
800AB6A8	addiu  s4, s4, $0001
800AB6AC	slti   v0, s4, $0040
800AB6B0	bne    v0, zero, loopab650 [$800ab650]
800AB6B4	addiu  s2, s2, $0018
800AB6B8	jal    func3aed8 [$8003aed8]
800AB6BC	nop
800AB6C0	lui    a0, $00ff
800AB6C4	ori    a0, a0, $ffff
800AB6C8	lui    a1, $ff00
800AB6CC	lw     v1, $0000(s7)
800AB6D0	lw     v0, $0000(s6)
800AB6D4	and    v1, v1, a1
800AB6D8	and    v0, v0, a0
800AB6DC	or     v1, v1, v0
800AB6E0	sw     v1, $0000(s7)
800AB6E4	lw     v0, $0000(s6)
800AB6E8	and    a0, s7, a0

Lab6ec:	; 800AB6EC
800AB6EC	and    v0, v0, a1
800AB6F0	or     v0, v0, a0
800AB6F4	sw     v0, $0000(s6)
800AB6F8	lw     ra, $0038(sp)
800AB6FC	lw     s7, $0034(sp)
800AB700	lw     s6, $0030(sp)
800AB704	lw     s5, $002c(sp)
800AB708	lw     s4, $0028(sp)
800AB70C	lw     s3, $0024(sp)
800AB710	lw     s2, $0020(sp)
800AB714	lw     s1, $001c(sp)
800AB718	lw     s0, $0018(sp)
800AB71C	addiu  sp, sp, $0040
800AB720	jr     ra 
800AB724	nop



////////////////////////////////
// funcab728
800AB728-800AB9C4
////////////////////////////////



funcab9c8:	; 800AB9C8
800AB9C8	lui    v0, $800a
800AB9CC	lbu    v0, $c540(v0)
800AB9D0	nop
800AB9D4	addiu  v0, v0, $0001
800AB9D8	lui    at, $800a
800AB9DC	sb     v0, $c540(at)
800AB9E0	lui    v1, $800a
800AB9E4	lbu    v1, $c540(v1)
800AB9E8	nop
800AB9EC	bne    v1, zero, Laba0c [$800aba0c]
800AB9F0	nop
800AB9F4	lui    v0, $800a
800AB9F8	lbu    v0, $ad2c(v0)
800AB9FC	nop
800ABA00	addiu  v0, v0, $000d
800ABA04	lui    at, $800a
800ABA08	sb     v0, $ad2c(at)

Laba0c:	; 800ABA0C
800ABA0C	lui    at, $800e
800ABA10	addiu  at, at, $0638
800ABA14	addu   at, at, v1
800ABA18	lbu    v0, $0000(at)
800ABA1C	lui    v1, $800a
800ABA20	lbu    v1, $ad2c(v1)
800ABA24	nop
800ABA28	subu   v0, v0, v1
800ABA2C	jr     ra 
800ABA30	andi   v0, v0, $00ff


funcaba34:	; 800ABA34
800ABA34	lui    v0, $8007
800ABA38	lbu    v0, $1c20(v0)
800ABA3C	nop
800ABA40	addiu  v0, v0, $0001
800ABA44	lui    at, $8007
800ABA48	sb     v0, $1c20(at)
800ABA4C	lui    v0, $8007

Laba50:	; 800ABA50
800ABA50	lbu    v0, $1c20(v0)
800ABA54	nop
800ABA58	lui    at, $800e
800ABA5C	addiu  at, at, $0638
800ABA60	addu   at, at, v0
800ABA64	lbu    v0, $0000(at)
800ABA68	jr     ra 
800ABA6C	nop



////////////////////////////////
// funcaba70
800ABA70-800ABF08
////////////////////////////////



funcabf0c:	; 800ABF0C
800ABF0C	addiu  sp, sp, $ffd0 (=-$30)
800ABF10	sw     s1, $001c(sp)
800ABF14	addu   s1, a0, zero
800ABF18	sw     s4, $0028(sp)
800ABF1C	addu   s4, a1, zero
800ABF20	sw     s2, $0020(sp)
800ABF24	addu   s2, zero, zero
800ABF28	sw     s3, $0024(sp)
800ABF2C	ori    s3, zero, $0080
800ABF30	sw     s0, $0018(sp)
800ABF34	addiu  s0, s1, $000e
800ABF38	sw     ra, $002c(sp)

loopabf3c:	; 800ABF3C
800ABF3C	jal    func4694c [$8004694c]
800ABF40	addu   a0, s1, zero
800ABF44	addu   a0, s1, zero
800ABF48	jal    system_change_brightness_calculation_in_packet [$80046870]
800ABF4C	ori    a1, zero, $0001
800ABF50	addu   a0, s1, zero
800ABF54	jal    system_change_semi_transparency_in_packet [$80046848]
800ABF58	addu   a1, zero, zero
800ABF5C	ori    a0, zero, $0100
800ABF60	ori    a1, zero, $01e9
800ABF64	sb     s3, $fff6(s0)
800ABF68	sb     s3, $fff7(s0)
800ABF6C	jal    func46634 [$80046634]
800ABF70	sb     s3, $fff8(s0)
800ABF74	addiu  v1, s2, $0001
800ABF78	addu   s2, v1, zero
800ABF7C	sh     v0, $0000(s0)
800ABF80	addiu  s0, s0, $0010
800ABF84	sll    v1, v1, $10
800ABF88	sra    v1, v1, $10
800ABF8C	slti   v1, v1, $0018
800ABF90	bne    v1, zero, loopabf3c [$800abf3c]
800ABF94	addiu  s1, s1, $0010
800ABF98	addu   a0, zero, zero
800ABF9C	addu   a1, zero, zero
800ABFA0	ori    a2, zero, $03c0
800ABFA4	jal    system_create_texture_page_settings_for_packet [$8004656c]
800ABFA8	ori    a3, zero, $0100
800ABFAC	sw     zero, $0010(sp)
800ABFB0	addu   a0, s4, zero
800ABFB4	addu   a1, zero, zero
800ABFB8	ori    a2, zero, $0001
800ABFBC	jal    func44a68 [$80044a68]
800ABFC0	andi   a3, v0, $ffff
800ABFC4	lw     ra, $002c(sp)
800ABFC8	lw     s4, $0028(sp)
800ABFCC	lw     s3, $0024(sp)
800ABFD0	lw     s2, $0020(sp)
800ABFD4	lw     s1, $001c(sp)
800ABFD8	lw     s0, $0018(sp)
800ABFDC	addiu  sp, sp, $0030
800ABFE0	jr     ra 
800ABFE4	nop


funcabfe8:	; 800ABFE8
800ABFE8	addiu  sp, sp, $ffc0 (=-$40)
800ABFEC	sw     s2, $0028(sp)
800ABFF0	addu   s2, a0, zero
800ABFF4	sw     s0, $0020(sp)
800ABFF8	addu   s0, a1, zero
800ABFFC	sw     s5, $0034(sp)
800AC000	addu   s5, a2, zero
800AC004	lui    v1, $800a
800AC008	lbu    v1, $d5a6(v1)
800AC00C	ori    v0, zero, $0001
800AC010	sw     ra, $003c(sp)
800AC014	sw     s6, $0038(sp)
800AC018	sw     s4, $0030(sp)
800AC01C	sw     s3, $002c(sp)
800AC020	bne    v1, v0, Lac03c [$800ac03c]
800AC024	sw     s1, $0024(sp)
800AC028	lui    v0, $800a
800AC02C	lbu    v0, $ac26(v0)
800AC030	nop
800AC034	beq    v0, zero, Lac048 [$800ac048]
800AC038	nop

Lac03c:	; 800AC03C
800AC03C	ori    v0, zero, $0002
800AC040	bne    v1, v0, Lac330 [$800ac330]
800AC044	nop

Lac048:	; 800AC048
800AC048	jal    func3ae38 [$8003ae38]
800AC04C	addu   s4, zero, zero
800AC050	jal    PsyQSetRotMatrix [$8003b48c]
800AC054	addu   a0, s0, zero
800AC058	jal    PsyQSetTransMatrix [$8003b51c]
800AC05C	addu   a0, s0, zero
800AC060	lui    s1, $00ff
800AC064	ori    s1, s1, $ffff
800AC068	lui    s3, $ff00
800AC06C	sll    v1, s4, $10

loopac070:	; 800AC070
800AC070	lui    v0, $8007
800AC074	lw     v0, $16c4(v0)
800AC078	sra    s0, v1, $10
800AC07C	addu   v0, v0, s0
800AC080	lbu    v1, $0218(v0)
800AC084	ori    v0, zero, $0001
800AC088	bne    v1, v0, Lac19c [$800ac19c]
800AC08C	addiu  v0, s4, $0001
800AC090	sll    a0, s0, $01
800AC094	addu   a0, a0, s0
800AC098	sll    a0, a0, $03
800AC09C	addu   a0, a0, s5
800AC0A0	lh     a1, $0000(a0)
800AC0A4	lh     v0, $0006(a0)
800AC0A8	nop
800AC0AC	addu   a1, a1, v0
800AC0B0	srl    v0, a1, $1f
800AC0B4	addu   a1, a1, v0
800AC0B8	sra    a1, a1, $01
800AC0BC	sh     a1, $0010(sp)
800AC0C0	lh     v0, $0002(a0)
800AC0C4	lh     v1, $0008(a0)
800AC0C8	nop
800AC0CC	addu   v0, v0, v1
800AC0D0	srl    v1, v0, $1f
800AC0D4	addu   v0, v0, v1
800AC0D8	sra    a2, v0, $01
800AC0DC	sh     a2, $0012(sp)
800AC0E0	lh     v0, $0004(a0)
800AC0E4	lh     v1, $000a(a0)
800AC0E8	sll    a1, a1, $10
800AC0EC	addu   v0, v0, v1
800AC0F0	srl    v1, v0, $1f
800AC0F4	addu   v0, v0, v1
800AC0F8	sra    v0, v0, $01
800AC0FC	bne    a1, zero, Lac110 [$800ac110]
800AC100	sh     v0, $0014(sp)
800AC104	sll    v0, a2, $10
800AC108	beq    v0, zero, Lac19c [$800ac19c]
800AC10C	addiu  v0, s4, $0001

Lac110:	; 800AC110
800AC110	addiu  a0, sp, $0010
800AC114	addu   a1, a0, zero
800AC118	addiu  a2, sp, $0018
800AC11C	jal    PsyQRotTransPers [$8003bbdc]
800AC120	addiu  a3, sp, $001c
800AC124	sll    a0, s0, $04
800AC128	addu   a1, a0, s2
800AC12C	ori    v1, zero, $00d0
800AC130	lui    v0, $8011
800AC134	lhu    v0, $446c(v0)
800AC138	addiu  a0, a0, $4000
800AC13C	sb     v1, $400d(a1)
800AC140	sll    v0, v0, $02
800AC144	andi   v0, v0, $0030
800AC148	addiu  v0, v0, $0030
800AC14C	sb     v0, $400c(a1)
800AC150	lhu    v0, $0010(sp)
800AC154	addu   a0, s2, a0
800AC158	addiu  v0, v0, $fff9 (=-$7)
800AC15C	sh     v0, $4008(a1)
800AC160	lhu    v0, $0012(sp)
800AC164	lw     v1, $4000(a1)
800AC168	addiu  v0, v0, $fff8 (=-$8)
800AC16C	sh     v0, $400a(a1)
800AC170	lw     v0, $0000(s2)
800AC174	and    v1, v1, s3
800AC178	and    v0, v0, s1
800AC17C	or     v1, v1, v0
800AC180	sw     v1, $4000(a1)
800AC184	lw     v0, $0000(s2)
800AC188	and    a0, a0, s1
800AC18C	and    v0, v0, s3
800AC190	or     v0, v0, a0
800AC194	sw     v0, $0000(s2)
800AC198	addiu  v0, s4, $0001

Lac19c:	; 800AC19C
800AC19C	addu   s4, v0, zero
800AC1A0	sll    v0, v0, $10
800AC1A4	sra    v0, v0, $10
800AC1A8	slti   v0, v0, $000c
800AC1AC	bne    v0, zero, loopac070 [$800ac070]
800AC1B0	sll    v1, s4, $10
800AC1B4	addu   s4, zero, zero
800AC1B8	lui    s5, $00ff
800AC1BC	ori    s5, s5, $ffff
800AC1C0	lui    s6, $ff00
800AC1C4	sll    v0, s4, $10

loopac1c8:	; 800AC1C8
800AC1C8	sra    s0, v0, $10
800AC1CC	lui    v0, $8007
800AC1D0	lw     v0, $16c4(v0)
800AC1D4	sll    s3, s0, $04

Lac1d8:	; 800AC1D8
800AC1D8	addu   v1, v0, s3
800AC1DC	lw     v0, $0230(v1)
800AC1E0	nop
800AC1E4	beq    v0, zero, Lac2c0 [$800ac2c0]
800AC1E8	addiu  v0, s4, $0001
800AC1EC	addiu  a0, sp, $0010
800AC1F0	lhu    v0, $0224(v1)
800AC1F4	addu   a1, a0, zero
800AC1F8	sh     v0, $0010(sp)
800AC1FC	lhu    v0, $0228(v1)
800AC200	addiu  a2, sp, $0018
800AC204	sh     v0, $0012(sp)
800AC208	lhu    v0, $022c(v1)
800AC20C	addiu  a3, sp, $001c
800AC210	jal    PsyQRotTransPers [$8003bbdc]
800AC214	sh     v0, $0014(sp)
800AC218	addu   s1, s3, s2
800AC21C	lui    v0, $8011
800AC220	lhu    v0, $446c(v0)
800AC224	ori    v1, zero, $00d0
800AC228	sb     v1, $40cd(s1)
800AC22C	sll    v0, v0, $02
800AC230	andi   v0, v0, $0030
800AC234	addiu  v0, v0, $0030
800AC238	sb     v0, $40cc(s1)
800AC23C	addiu  v0, s0, $000c
800AC240	sll    v0, v0, $04
800AC244	lhu    v1, $0010(sp)
800AC248	addu   s0, s2, v0
800AC24C	addiu  v1, v1, $fff9 (=-$7)
800AC250	sh     v1, $4008(s0)
800AC254	lhu    v0, $0012(sp)
800AC258	lui    v1, $8007
800AC25C	lw     v1, $16c4(v1)
800AC260	addiu  v0, v0, $fff8 (=-$8)
800AC264	addu   v1, v1, s3
800AC268	sh     v0, $400a(s0)
800AC26C	lw     v1, $0230(v1)
800AC270	ori    v0, zero, $0002
800AC274	bne    v1, v0, Lac288 [$800ac288]
800AC278	ori    a0, zero, $0100
800AC27C	jal    func46634 [$80046634]
800AC280	ori    a1, zero, $01e8
800AC284	sh     v0, $400e(s0)

Lac288:	; 800AC288
800AC288	lw     v1, $40c0(s1)
800AC28C	lw     v0, $0000(s2)
800AC290	and    v1, v1, s6
800AC294	and    v0, v0, s5
800AC298	or     v1, v1, v0
800AC29C	addiu  v0, s3, $40c0
800AC2A0	addu   v0, s2, v0
800AC2A4	sw     v1, $40c0(s1)
800AC2A8	lw     v1, $0000(s2)
800AC2AC	and    v0, v0, s5
800AC2B0	and    v1, v1, s6
800AC2B4	or     v1, v1, v0
800AC2B8	sw     v1, $0000(s2)
800AC2BC	addiu  v0, s4, $0001

Lac2c0:	; 800AC2C0
800AC2C0	addu   s4, v0, zero
800AC2C4	sll    v0, v0, $10
800AC2C8	sra    v0, v0, $10
800AC2CC	slti   v0, v0, $000c
800AC2D0	bne    v0, zero, loopac1c8 [$800ac1c8]
800AC2D4	sll    v0, s4, $10
800AC2D8	jal    func3aed8 [$8003aed8]
800AC2DC	nop
800AC2E0	lui    v1, $00ff
800AC2E4	ori    v1, v1, $ffff
800AC2E8	lui    a2, $ff00
800AC2EC	lw     a1, $4180(s2)
800AC2F0	lw     v0, $0000(s2)
800AC2F4	lw     a0, $0000(s2)
800AC2F8	and    a1, a1, a2
800AC2FC	and    v0, v0, v1
800AC300	or     a1, a1, v0
800AC304	and    a0, a0, a2
800AC308	addiu  v0, s2, $4180
800AC30C	and    v0, v0, v1
800AC310	lui    v1, $8011
800AC314	lhu    v1, $446c(v1)
800AC318	or     a0, a0, v0
800AC31C	sw     a1, $4180(s2)
800AC320	sw     a0, $0000(s2)
800AC324	addiu  v1, v1, $0001
800AC328	lui    at, $8011
800AC32C	sh     v1, $446c(at)

Lac330:	; 800AC330
800AC330	lw     ra, $003c(sp)
800AC334	lw     s6, $0038(sp)
800AC338	lw     s5, $0034(sp)
800AC33C	lw     s4, $0030(sp)
800AC340	lw     s3, $002c(sp)
800AC344	lw     s2, $0028(sp)
800AC348	lw     s1, $0024(sp)
800AC34C	lw     s0, $0020(sp)
800AC350	addiu  sp, sp, $0040
800AC354	jr     ra 
800AC358	nop



////////////////////////////////
// funcac35c
800AC35C-800ACB9C
////////////////////////////////



////////////////////////////////
// funcacba0
800ACBA0-800ACC58
////////////////////////////////



////////////////////////////////
// model_packet_draft_prepare
800ACC5C-800AD7B4
////////////////////////////////



////////////////////////////////
// bsx_texture_loading_to_vram
800AD7B8-800AD854
////////////////////////////////



////////////////////////////////
// funcad858
800AD858-800ADAA0
////////////////////////////////



////////////////////////////////
// model_new_structure_initing
800ADAA8-800ADC8C
////////////////////////////////



////////////////////////////////
// load_and_global_models_and_textures
800ADC90-800ADD6C
////////////////////////////////



////////////////////////////////
// load_and_init_global_models
800ADD70-800AE238
////////////////////////////////



////////////////////////////////
// funcae23c
800AE23C-800AE4D8
////////////////////////////////



////////////////////////////////
// funcae4dc
800AE4DC-800AEE20
////////////////////////////////



////////////////////////////////
// animation_prepare_bones_matrixes
800AEE24-800AF6E8
////////////////////////////////



////////////////////////////////
// funcaf6ec
800AF6EC-800AF968
////////////////////////////////



////////////////////////////////
// funcaf96c
800AF96C-800AFAC0
////////////////////////////////



////////////////////////////////
// funcafac4
800AFAC4-800AFE18
////////////////////////////////



////////////////////////////////
// funcafde4
800AFDE4-800AFE18
////////////////////////////////



////////////////////////////////
// run_kawai
// we read KAWAI sequence here
800AFE1C-800B0614
////////////////////////////////



////////////////////////////////
// funcb0618
// kawai_action_3
800B0618-800B0A44
////////////////////////////////



funcb0a48:	; 800B0A48
800B0A48	addu   t8, a0, zero
800B0A4C	lhu    v0, $000e(t8)
800B0A50	lw     v1, $0018(t8)
800B0A54	lui    t6, $800e
800B0A58	addiu  t6, t6, $f520 (=-$ae0)
800B0A5C	addu   t1, v0, v1
800B0A60	lui    v0, $800e
800B0A64	lbu    v0, $f114(v0)
800B0A68	lw     a3, $001c(t8)
800B0A6C	beq    v0, zero, Lb0a80 [$800b0a80]
800B0A70	addiu  sp, sp, $ffc0 (=-$40)
800B0A74	lhu    v0, $0016(t8)
800B0A78	nop
800B0A7C	addu   a3, a3, v0

Lb0a80:	; 800B0A80
800B0A80	lw     t7, $0004(t8)
800B0A84	nop
800B0A88	andi   t3, t7, $00ff
800B0A8C	beq    t3, zero, Lb0b24 [$800b0b24]
800B0A90	addu   t0, zero, zero
800B0A94	addiu  t2, a3, $0007

loopb0a98:	; 800B0A98
800B0A98	lw     v0, $0000(a3)
800B0A9C	nop
800B0AA0	beq    v0, zero, Lb0b0c [$800b0b0c]
800B0AA4	nop
800B0AA8	addu   t4, t1, zero
800B0AAC	lbu    t5, $0000(t2)
800B0AB0	addu   v1, zero, zero
800B0AB4	addiu  a2, a3, $0004
800B0AB8	ori    a1, zero, $0004
800B0ABC	addu   a0, t1, zero

loopb0ac0:	; 800B0AC0
800B0AC0	lbu    v0, $0007(a0)
800B0AC4	nop
800B0AC8	sll    v0, v0, $03
800B0ACC	addu   v0, t6, v0
800B0AD0	lwc2   zero, $0000(v0)
800B0AD4	lwc2   at, $0004(v0)
800B0AD8	addu   v0, t4, a1
800B0ADC	lwc2   a2, $0000(v0)
800B0AE0	nop
800B0AE4	nop
800B0AE8	gte_func24t0,r11r12
800B0AEC	swc2   s6, $0000(a2)
800B0AF0	addiu  a2, a2, $000c
800B0AF4	addiu  a1, a1, $0004
800B0AF8	addiu  v1, v1, $0001
800B0AFC	sltiu  v0, v1, $0004
800B0B00	bne    v0, zero, loopb0ac0 [$800b0ac0]
800B0B04	addiu  a0, a0, $0004
800B0B08	sb     t5, $0000(t2)

Lb0b0c:	; 800B0B0C
800B0B0C	addiu  t0, t0, $0001
800B0B10	addiu  t2, t2, $0034
800B0B14	addiu  a3, a3, $0034
800B0B18	sltu   v0, t0, t3
800B0B1C	bne    v0, zero, loopb0a98 [$800b0a98]
800B0B20	addiu  t1, t1, $0018

Lb0b24:	; 800B0B24
800B0B24	andi   v0, t7, $ff00
800B0B28	srl    t3, v0, $08
800B0B2C	beq    t3, zero, Lb0bc4 [$800b0bc4]
800B0B30	addu   t0, zero, zero
800B0B34	addiu  t2, a3, $0007

loopb0b38:	; 800B0B38
800B0B38	lw     v0, $0000(a3)
800B0B3C	nop
800B0B40	beq    v0, zero, Lb0bac [$800b0bac]
800B0B44	nop
800B0B48	addu   t4, t1, zero
800B0B4C	lbu    t5, $0000(t2)
800B0B50	addu   v1, zero, zero
800B0B54	addiu  a2, a3, $0004
800B0B58	ori    a1, zero, $0004
800B0B5C	addu   a0, t1, zero

loopb0b60:	; 800B0B60
800B0B60	lbu    v0, $0007(a0)
800B0B64	nop
800B0B68	sll    v0, v0, $03
800B0B6C	addu   v0, t6, v0
800B0B70	lwc2   zero, $0000(v0)
800B0B74	lwc2   at, $0004(v0)
800B0B78	addu   v0, t4, a1
800B0B7C	lwc2   a2, $0000(v0)
800B0B80	nop
800B0B84	nop
800B0B88	gte_func24t0,r11r12
800B0B8C	swc2   s6, $0000(a2)
800B0B90	addiu  a2, a2, $000c
800B0B94	addiu  a1, a1, $0004
800B0B98	addiu  v1, v1, $0001
800B0B9C	sltiu  v0, v1, $0003
800B0BA0	bne    v0, zero, loopb0b60 [$800b0b60]
800B0BA4	addiu  a0, a0, $0004
800B0BA8	sb     t5, $0000(t2)

Lb0bac:	; 800B0BAC
800B0BAC	addiu  t0, t0, $0001
800B0BB0	addiu  t2, t2, $0028
800B0BB4	addiu  a3, a3, $0028
800B0BB8	sltu   v0, t0, t3
800B0BBC	bne    v0, zero, loopb0b38 [$800b0b38]
800B0BC0	addiu  t1, t1, $0014

Lb0bc4:	; 800B0BC4
800B0BC4	srl    v0, t7, $10
800B0BC8	andi   t3, v0, $00ff
800B0BCC	beq    t3, zero, Lb0c38 [$800b0c38]
800B0BD0	addu   t0, zero, zero
800B0BD4	addiu  a2, t1, $0004
800B0BD8	addiu  a1, a3, $0007

loopb0bdc:	; 800B0BDC
800B0BDC	lw     v0, $0000(a3)
800B0BE0	nop
800B0BE4	beq    v0, zero, Lb0c1c [$800b0c1c]
800B0BE8	addiu  a0, a3, $0004
800B0BEC	lbu    v0, $0003(a2)
800B0BF0	lbu    v1, $0000(a1)
800B0BF4	sll    v0, v0, $03
800B0BF8	addu   v0, t6, v0
800B0BFC	lwc2   zero, $0000(v0)
800B0C00	lwc2   at, $0004(v0)
800B0C04	lwc2   a2, $0000(a2)
800B0C08	nop
800B0C0C	nop
800B0C10	gte_func24t0,r11r12
800B0C14	swc2   s6, $0000(a0)
800B0C18	sb     v1, $0000(a1)

Lb0c1c:	; 800B0C1C
800B0C1C	addiu  t0, t0, $0001
800B0C20	addiu  a1, a1, $0028
800B0C24	addiu  a3, a3, $0028
800B0C28	addiu  a2, a2, $000c
800B0C2C	sltu   v0, t0, t3
800B0C30	bne    v0, zero, loopb0bdc [$800b0bdc]
800B0C34	addiu  t1, t1, $000c

Lb0c38:	; 800B0C38
800B0C38	srl    t3, t7, $18
800B0C3C	beq    t3, zero, Lb0ca8 [$800b0ca8]
800B0C40	addu   t0, zero, zero
800B0C44	addiu  a2, t1, $0004
800B0C48	addiu  a1, a3, $0007

loopb0c4c:	; 800B0C4C
800B0C4C	lw     v0, $0000(a3)
800B0C50	nop
800B0C54	beq    v0, zero, Lb0c8c [$800b0c8c]
800B0C58	addiu  a0, a3, $0004
800B0C5C	lbu    v0, $0003(a2)
800B0C60	lbu    v1, $0000(a1)
800B0C64	sll    v0, v0, $03
800B0C68	addu   v0, t6, v0
800B0C6C	lwc2   zero, $0000(v0)
800B0C70	lwc2   at, $0004(v0)
800B0C74	lwc2   a2, $0000(a2)
800B0C78	nop
800B0C7C	nop
800B0C80	gte_func24t0,r11r12
800B0C84	swc2   s6, $0000(a0)
800B0C88	sb     v1, $0000(a1)

Lb0c8c:	; 800B0C8C
800B0C8C	addiu  t0, t0, $0001
800B0C90	addiu  a1, a1, $0020
800B0C94	addiu  a3, a3, $0020
800B0C98	addiu  a2, a2, $000c
800B0C9C	sltu   v0, t0, t3
800B0CA0	bne    v0, zero, loopb0c4c [$800b0c4c]
800B0CA4	addiu  t1, t1, $000c

Lb0ca8:	; 800B0CA8
800B0CA8	lw     t7, $0008(t8)
800B0CAC	nop
800B0CB0	andi   t3, t7, $00ff
800B0CB4	beq    t3, zero, Lb0d20 [$800b0d20]
800B0CB8	addu   t0, zero, zero
800B0CBC	addiu  a2, t1, $0004
800B0CC0	addiu  a1, a3, $0007

loopb0cc4:	; 800B0CC4
800B0CC4	lw     v0, $0000(a3)
800B0CC8	nop
800B0CCC	beq    v0, zero, Lb0d04 [$800b0d04]
800B0CD0	addiu  a0, a3, $0004
800B0CD4	lbu    v0, $0003(a2)
800B0CD8	lbu    v1, $0000(a1)
800B0CDC	sll    v0, v0, $03
800B0CE0	addu   v0, t6, v0
800B0CE4	lwc2   zero, $0000(v0)
800B0CE8	lwc2   at, $0004(v0)
800B0CEC	lwc2   a2, $0000(a2)
800B0CF0	nop
800B0CF4	nop
800B0CF8	gte_func24t0,r11r12
800B0CFC	swc2   s6, $0000(a0)
800B0D00	sb     v1, $0000(a1)

Lb0d04:	; 800B0D04
800B0D04	addiu  t0, t0, $0001
800B0D08	addiu  a1, a1, $0014
800B0D0C	addiu  a3, a3, $0014
800B0D10	addiu  a2, a2, $0008
800B0D14	sltu   v0, t0, t3
800B0D18	bne    v0, zero, loopb0cc4 [$800b0cc4]
800B0D1C	addiu  t1, t1, $0008

Lb0d20:	; 800B0D20
800B0D20	andi   v0, t7, $ff00
800B0D24	srl    t3, v0, $08
800B0D28	beq    t3, zero, Lb0d94 [$800b0d94]
800B0D2C	addu   t0, zero, zero
800B0D30	addiu  a2, t1, $0004
800B0D34	addiu  a1, a3, $0007

loopb0d38:	; 800B0D38
800B0D38	lw     v0, $0000(a3)
800B0D3C	nop
800B0D40	beq    v0, zero, Lb0d78 [$800b0d78]
800B0D44	addiu  a0, a3, $0004
800B0D48	lbu    v0, $0003(a2)
800B0D4C	lbu    v1, $0000(a1)
800B0D50	sll    v0, v0, $03
800B0D54	addu   v0, t6, v0
800B0D58	lwc2   zero, $0000(v0)
800B0D5C	lwc2   at, $0004(v0)
800B0D60	lwc2   a2, $0000(a2)
800B0D64	nop
800B0D68	nop
800B0D6C	gte_func24t0,r11r12
800B0D70	swc2   s6, $0000(a0)
800B0D74	sb     v1, $0000(a1)

Lb0d78:	; 800B0D78
800B0D78	addiu  t0, t0, $0001
800B0D7C	addiu  a1, a1, $0018
800B0D80	addiu  a3, a3, $0018
800B0D84	addiu  a2, a2, $0008
800B0D88	sltu   v0, t0, t3
800B0D8C	bne    v0, zero, loopb0d38 [$800b0d38]
800B0D90	addiu  t1, t1, $0008

Lb0d94:	; 800B0D94
800B0D94	srl    v0, t7, $10
800B0D98	andi   t3, v0, $00ff
800B0D9C	beq    t3, zero, Lb0e34 [$800b0e34]
800B0DA0	addu   t0, zero, zero
800B0DA4	addiu  t2, a3, $0007

loopb0da8:	; 800B0DA8
800B0DA8	lw     v0, $0000(a3)
800B0DAC	nop
800B0DB0	beq    v0, zero, Lb0e1c [$800b0e1c]
800B0DB4	nop
800B0DB8	addu   t4, t1, zero
800B0DBC	lbu    t5, $0000(t2)
800B0DC0	addu   v1, zero, zero
800B0DC4	addiu  a2, a3, $0004
800B0DC8	ori    a1, zero, $0004
800B0DCC	addu   a0, t1, zero

loopb0dd0:	; 800B0DD0
800B0DD0	lbu    v0, $0007(a0)
800B0DD4	nop
800B0DD8	sll    v0, v0, $03
800B0DDC	addu   v0, t6, v0
800B0DE0	lwc2   zero, $0000(v0)
800B0DE4	lwc2   at, $0004(v0)
800B0DE8	addu   v0, t4, a1
800B0DEC	lwc2   a2, $0000(v0)
800B0DF0	nop
800B0DF4	nop
800B0DF8	gte_func24t0,r11r12
800B0DFC	swc2   s6, $0000(a2)
800B0E00	addiu  a2, a2, $0008
800B0E04	addiu  a1, a1, $0004
800B0E08	addiu  v1, v1, $0001
800B0E0C	sltiu  v0, v1, $0003
800B0E10	bne    v0, zero, loopb0dd0 [$800b0dd0]
800B0E14	addiu  a0, a0, $0004
800B0E18	sb     t5, $0000(t2)

Lb0e1c:	; 800B0E1C
800B0E1C	addiu  t0, t0, $0001
800B0E20	addiu  t2, t2, $001c
800B0E24	addiu  a3, a3, $001c
800B0E28	sltu   v0, t0, t3
800B0E2C	bne    v0, zero, loopb0da8 [$800b0da8]
800B0E30	addiu  t1, t1, $0010

Lb0e34:	; 800B0E34
800B0E34	srl    t3, t7, $18
800B0E38	beq    t3, zero, Lb0ed0 [$800b0ed0]
800B0E3C	addu   t0, zero, zero
800B0E40	addiu  t2, a3, $0007

loopb0e44:	; 800B0E44
800B0E44	lw     v0, $0000(a3)
800B0E48	nop
800B0E4C	beq    v0, zero, Lb0eb8 [$800b0eb8]
800B0E50	nop
800B0E54	addu   t4, t1, zero
800B0E58	lbu    t5, $0000(t2)
800B0E5C	addu   v1, zero, zero
800B0E60	addiu  a2, a3, $0004
800B0E64	ori    a1, zero, $0004
800B0E68	addu   a0, t1, zero

loopb0e6c:	; 800B0E6C
800B0E6C	lbu    v0, $0007(a0)
800B0E70	nop
800B0E74	sll    v0, v0, $03
800B0E78	addu   v0, t6, v0
800B0E7C	lwc2   zero, $0000(v0)
800B0E80	lwc2   at, $0004(v0)
800B0E84	addu   v0, t4, a1
800B0E88	lwc2   a2, $0000(v0)
800B0E8C	nop
800B0E90	nop
800B0E94	gte_func24t0,r11r12
800B0E98	swc2   s6, $0000(a2)
800B0E9C	addiu  a2, a2, $0008
800B0EA0	addiu  a1, a1, $0004
800B0EA4	addiu  v1, v1, $0001
800B0EA8	sltiu  v0, v1, $0004
800B0EAC	bne    v0, zero, loopb0e6c [$800b0e6c]
800B0EB0	addiu  a0, a0, $0004
800B0EB4	sb     t5, $0000(t2)

Lb0eb8:	; 800B0EB8
800B0EB8	addiu  t0, t0, $0001
800B0EBC	addiu  t2, t2, $0024
800B0EC0	addiu  a3, a3, $0024
800B0EC4	sltu   v0, t0, t3
800B0EC8	bne    v0, zero, loopb0e44 [$800b0e44]
800B0ECC	addiu  t1, t1, $0014

Lb0ed0:	; 800B0ED0
800B0ED0	addiu  sp, sp, $0040
800B0ED4	jr     ra 
800B0ED8	nop



////////////////////////////////////////////////////////
// funcb0edc
// kawai_action_2
800B0EDC-800B0FAC
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// funcb0fb0
800B0FB0-800B1C78
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// funcb1c7c
// kawai_action_0
800B1C7C-800B1E3C
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// funcb1e40
800B1E40-800B2594
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// funcb2598
800B2598-800B29FC
////////////////////////////////////////////////////////



////////////////////////////////////////////////////
// kawai_action_1
800B2A00-800B2DD0
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// kawai_action_4
// funcb2dd4
800B2DD4-800B2F3C
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb2f40
800B2F40-800B4808
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// kawai_action_6
800B480C-800B4B00
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// kawai_action_7
800B4B04-800B4EA8
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// kawai_action_8
800B4EAC-800B525C
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb5260
// kawai_action_5
800B5260-800B5500
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb5504
800B5504-800B62C0
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// kawai_action_9
800B62C4-800B69BC
////////////////////////////////////////////////////



funcb69c0:	; 800B69C0
800B69C0	addiu  sp, sp, $ffe0 (=-$20)
800B69C4	sw     s2, $0018(sp)
800B69C8	addu   s2, a0, zero
800B69CC	sll    v0, a1, $01
800B69D0	addu   v0, v0, a1
800B69D4	sll    v0, v0, $03
800B69D8	subu   v0, v0, a1
800B69DC	sll    v1, v0, $04
800B69E0	subu   v1, v1, v0
800B69E4	lui    v0, $800e
800B69E8	lw     v0, $0200(v0)
800B69EC	sll    v1, v1, $03
800B69F0	sw     ra, $001c(sp)
800B69F4	sw     s1, $0014(sp)
800B69F8	sw     s0, $0010(sp)
800B69FC	jal    func43cc0 [$80043cc0]
800B6A00	addu   s0, v1, v0
800B6A04	ori    v1, zero, $0001
800B6A08	beq    v0, v1, Lb6a24 [$800b6a24]
800B6A0C	ori    s1, zero, $6c2c
800B6A10	jal    func43cc0 [$80043cc0]
800B6A14	nop
800B6A18	ori    v1, zero, $0002
800B6A1C	bne    v0, v1, Lb6a28 [$800b6a28]
800B6A20	ori    t0, zero, $009b

Lb6a24:	; 800B6A24
800B6A24	ori    t0, zero, $022b

Lb6a28:	; 800B6A28
800B6A28	ori    t3, zero, $001f
800B6A2C	ori    a3, zero, $0001
800B6A30	ori    t2, zero, $0009
800B6A34	ori    t1, zero, $002c
800B6A38	ori    a1, zero, $0080
800B6A3C	lw     v0, $001c(s2)
800B6A40	addiu  a0, s0, $005c
800B6A44	addiu  a2, v0, $0004

loopb6a48:	; 800B6A48
800B6A48	sb     t1, $0007(a0)
800B6A4C	lbu    v0, $0007(a0)
800B6A50	sb     t1, $002f(a0)
800B6A54	lbu    v1, $002f(a0)
800B6A58	addiu  a3, a3, $0001
800B6A5C	sb     t2, $0003(a0)
800B6A60	sb     t2, $002b(a0)
800B6A64	sb     a1, $002e(a0)
800B6A68	sb     a1, $0006(a0)
800B6A6C	sb     a1, $002d(a0)
800B6A70	sb     a1, $0005(a0)
800B6A74	sb     a1, $002c(a0)
800B6A78	sb     a1, $0004(a0)
800B6A7C	sh     s1, $0036(a0)
800B6A80	sh     s1, $000e(a0)
800B6A84	sh     t0, $003e(a0)
800B6A88	sh     t0, $0016(a0)
800B6A8C	sh     zero, $0050(a0)
800B6A90	sh     zero, $0052(a0)
800B6A94	sh     zero, $0054(a0)
800B6A98	ori    v0, v0, $0002
800B6A9C	ori    v1, v1, $0002
800B6AA0	sb     v0, $0007(a0)
800B6AA4	sb     v1, $002f(a0)
800B6AA8	lhu    v0, $0000(a2)
800B6AAC	addiu  a2, a2, $0004
800B6AB0	sh     zero, $005a(a0)
800B6AB4	subu   v0, zero, v0
800B6AB8	sh     v0, $0058(a0)
800B6ABC	slt    v0, a3, t3
800B6AC0	bne    v0, zero, loopb6a48 [$800b6a48]
800B6AC4	addiu  a0, a0, $005c
800B6AC8	lw     ra, $001c(sp)
800B6ACC	lw     s2, $0018(sp)
800B6AD0	lw     s1, $0014(sp)
800B6AD4	lw     s0, $0010(sp)
800B6AD8	addiu  sp, sp, $0020
800B6ADC	jr     ra 
800B6AE0	nop



////////////////////////////////////////////////////
// kawai_action_a
800B6AE4-800B6B48
////////////////////////////////////////////////////



800B6B4C	addiu  sp, sp, $ff68 (=-$98)
800B6B50	sw     ra, $0094(sp)
800B6B54	sw     fp, $0090(sp)

funcb6b58:	; 800B6B58
800B6B58	sw     s7, $008c(sp)
800B6B5C	sw     s6, $0088(sp)
800B6B60	sw     s5, $0084(sp)
800B6B64	sw     s4, $0080(sp)
800B6B68	sw     s3, $007c(sp)
800B6B6C	sw     s2, $0078(sp)
800B6B70	sw     s1, $0074(sp)
800B6B74	sw     s0, $0070(sp)
800B6B78	sw     a0, $0010(sp)
800B6B7C	lbu    v0, $0001(a1)
800B6B80	lbu    a0, $0000(a1)
800B6B84	sll    v1, v0, $04
800B6B88	subu   v1, v1, v0
800B6B8C	sll    v1, v1, $02
800B6B90	lui    v0, $800e
800B6B94	addiu  v0, v0, $fe3c (=-$1c4)
800B6B98	beq    a0, zero, Lb6bb4 [$800b6bb4]
800B6B9C	addu   s0, v1, v0
800B6BA0	ori    v0, zero, $0001
800B6BA4	beq    a0, v0, Lb71e8 [$800b71e8]
800B6BA8	lui    t7, $1f80
800B6BAC	j      Lb7984 [$800b7984]
800B6BB0	nop

Lb6bb4:	; 800B6BB4
800B6BB4	lui    s2, $1f80
800B6BB8	ori    s2, s2, $0208
800B6BBC	lui    s3, $1f80
800B6BC0	ori    s3, s3, $0210
800B6BC4	lui    s1, $1f80
800B6BC8	ori    s1, s1, $0218
800B6BCC	lui    a0, $1f80
800B6BD0	ori    a0, a0, $0200
800B6BD4	lbu    v0, $0003(a1)
800B6BD8	lbu    v1, $0002(a1)
800B6BDC	sll    v0, v0, $08
800B6BE0	or     v1, v1, v0
800B6BE4	sh     v1, $0000(s0)
800B6BE8	lbu    v0, $0005(a1)
800B6BEC	lbu    v1, $0004(a1)
800B6BF0	sll    v0, v0, $08
800B6BF4	or     v1, v1, v0
800B6BF8	sh     v1, $0002(s0)
800B6BFC	lbu    v0, $0007(a1)
800B6C00	lbu    v1, $0006(a1)
800B6C04	sll    v0, v0, $08
800B6C08	or     v1, v1, v0
800B6C0C	sh     v1, $0004(s0)
800B6C10	lbu    v1, $0009(a1)
800B6C14	lbu    v0, $0008(a1)
800B6C18	lhu    a1, $0000(s0)
800B6C1C	sll    v1, v1, $08
800B6C20	or     v0, v0, v1
800B6C24	sh     v0, $0006(s0)
800B6C28	lui    at, $1f80
800B6C2C	sh     a1, $0200(at)
800B6C30	lhu    v0, $0002(s0)
800B6C34	lui    a1, $1f80
800B6C38	lui    at, $1f80
800B6C3C	sh     v0, $0202(at)
800B6C40	lhu    v0, $0004(s0)
800B6C44	lui    at, $1f80
800B6C48	sh     zero, $0206(at)
800B6C4C	lui    at, $1f80
800B6C50	sh     v0, $0204(at)
800B6C54	jal    func3a0b8 [$8003a0b8]
800B6C58	ori    a1, a1, $0208
800B6C5C	lhu    v0, $0000(s2)
800B6C60	lui    s5, $1f80
800B6C64	sh     v0, $0008(s0)
800B6C68	lui    v0, $1f80
800B6C6C	lhu    v0, $020a(v0)
800B6C70	ori    s5, s5, $0220
800B6C74	sh     v0, $000a(s0)
800B6C78	lui    v0, $1f80
800B6C7C	lhu    v0, $020c(v0)
800B6C80	lui    s4, $1f80
800B6C84	sh     v0, $000c(s0)
800B6C88	lui    v1, $1f80
800B6C8C	lh     v1, $020c(v1)
800B6C90	nop
800B6C94	beq    v1, zero, Lb6cf4 [$800b6cf4]
800B6C98	ori    s4, s4, $0228
800B6C9C	lui    at, $1f80
800B6CA0	sh     zero, $0212(at)
800B6CA4	sh     zero, $0000(s3)
800B6CA8	lh     v0, $0006(s0)
800B6CAC	nop
800B6CB0	sll    v0, v0, $0c
800B6CB4	div    v0, v1
800B6CB8	bne    v1, zero, Lb6cc4 [$800b6cc4]
800B6CBC	nop
800B6CC0	break   $01c00

Lb6cc4:	; 800B6CC4
800B6CC4	addiu  at, zero, $ffff (=-$1)
800B6CC8	bne    v1, at, Lb6cdc [$800b6cdc]
800B6CCC	lui    at, $8000
800B6CD0	bne    v0, at, Lb6cdc [$800b6cdc]
800B6CD4	nop
800B6CD8	break   $01800

Lb6cdc:	; 800B6CDC
800B6CDC	mflo   v0
800B6CE0	nop
800B6CE4	lui    at, $1f80
800B6CE8	sh     v0, $0214(at)
800B6CEC	j      Lb6dc0 [$800b6dc0]
800B6CF0	nop

Lb6cf4:	; 800B6CF4
800B6CF4	lui    v1, $1f80
800B6CF8	lh     v1, $020a(v1)
800B6CFC	nop
800B6D00	beq    v1, zero, Lb6d60 [$800b6d60]
800B6D04	nop
800B6D08	lui    at, $1f80
800B6D0C	sh     zero, $0214(at)
800B6D10	sh     zero, $0000(s3)
800B6D14	lh     v0, $0006(s0)
800B6D18	nop
800B6D1C	sll    v0, v0, $0c
800B6D20	div    v0, v1
800B6D24	bne    v1, zero, Lb6d30 [$800b6d30]
800B6D28	nop
800B6D2C	break   $01c00

Lb6d30:	; 800B6D30
800B6D30	addiu  at, zero, $ffff (=-$1)
800B6D34	bne    v1, at, Lb6d48 [$800b6d48]
800B6D38	lui    at, $8000
800B6D3C	bne    v0, at, Lb6d48 [$800b6d48]
800B6D40	nop
800B6D44	break   $01800

Lb6d48:	; 800B6D48
800B6D48	mflo   v0
800B6D4C	nop
800B6D50	lui    at, $1f80
800B6D54	sh     v0, $0212(at)
800B6D58	j      Lb6dc0 [$800b6dc0]
800B6D5C	nop

Lb6d60:	; 800B6D60
800B6D60	lh     v1, $0000(s2)
800B6D64	nop
800B6D68	beq    v1, zero, Lb7984 [$800b7984]

funcb6d6c:	; 800B6D6C
800B6D6C	ori    v0, zero, $0001
800B6D70	lui    at, $1f80
800B6D74	sh     zero, $0214(at)
800B6D78	lui    at, $1f80
800B6D7C	sh     zero, $0212(at)
800B6D80	lh     v0, $0006(s0)
800B6D84	nop
800B6D88	sll    v0, v0, $0c
800B6D8C	div    v0, v1
800B6D90	bne    v1, zero, Lb6d9c [$800b6d9c]
800B6D94	nop
800B6D98	break   $01c00

Lb6d9c:	; 800B6D9C
800B6D9C	addiu  at, zero, $ffff (=-$1)
800B6DA0	bne    v1, at, Lb6db4 [$800b6db4]
800B6DA4	lui    at, $8000
800B6DA8	bne    v0, at, Lb6db4 [$800b6db4]
800B6DAC	nop
800B6DB0	break   $01800

Lb6db4:	; 800B6DB4
800B6DB4	mflo   v0
800B6DB8	nop
800B6DBC	sh     v0, $0000(s3)

Lb6dc0:	; 800B6DC0
800B6DC0	lhu    v0, $0000(s3)
800B6DC4	nop
800B6DC8	sh     v0, $000e(s0)
800B6DCC	lhu    v0, $0002(s3)
800B6DD0	nop
800B6DD4	sh     v0, $0010(s0)
800B6DD8	lhu    v0, $0004(s3)
800B6DDC	nop
800B6DE0	sh     v0, $0012(s0)
800B6DE4	sh     zero, $0000(s1)
800B6DE8	lh     v1, $0000(s2)
800B6DEC	lh     v0, $0000(s1)
800B6DF0	nop
800B6DF4	mult   v1, v0
800B6DF8	lhu    v0, $0002(s2)
800B6DFC	sh     zero, $0002(s1)
800B6E00	sll    v0, v0, $10
800B6E04	sra    a2, v0, $10
800B6E08	lhu    v0, $0002(s1)
800B6E0C	mflo   a0
800B6E10	sll    v0, v0, $10
800B6E14	sra    a1, v0, $10
800B6E18	mult   a2, a1
800B6E1C	ori    s3, zero, $1000
800B6E20	sh     s3, $0004(s1)
800B6E24	lhu    v0, $0004(s2)
800B6E28	nop
800B6E2C	sll    v0, v0, $10
800B6E30	mflo   v1
800B6E34	addu   a0, a0, v1
800B6E38	sra    v1, v0, $10
800B6E3C	sll    v0, v1, $0c
800B6E40	addu   a0, a0, v0
800B6E44	bgez   a0, Lb6e50 [$800b6e50]
800B6E48	mult   a1, v1
800B6E4C	addiu  a0, a0, $0fff

Lb6e50:	; 800B6E50
800B6E50	sll    v1, a2, $0c
800B6E54	mflo   v0
800B6E58	subu   a1, v1, v0
800B6E5C	bgez   a1, Lb6e68 [$800b6e68]
800B6E60	srl    s6, a0, $0c
800B6E64	addiu  a1, a1, $0fff

Lb6e68:	; 800B6E68
800B6E68	lhu    v0, $0004(s2)
800B6E6C	lh     v1, $0000(s1)
800B6E70	sll    v0, v0, $10
800B6E74	sra    v0, v0, $10
800B6E78	mult   v1, v0
800B6E7C	lhu    v0, $0004(s1)
800B6E80	lh     v1, $0000(s2)
800B6E84	mflo   a0
800B6E88	sll    v0, v0, $10
800B6E8C	sra    v0, v0, $10
800B6E90	mult   v1, v0
800B6E94	sra    v0, a1, $0c
800B6E98	sh     v0, $0000(s5)
800B6E9C	mflo   v0
800B6EA0	subu   a1, a0, v0
800B6EA4	bgez   a1, Lb6eb0 [$800b6eb0]
800B6EA8	nop
800B6EAC	addiu  a1, a1, $0fff

Lb6eb0:	; 800B6EB0
800B6EB0	lhu    v0, $0002(s1)
800B6EB4	lh     v1, $0000(s2)
800B6EB8	sll    v0, v0, $10
800B6EBC	sra    v0, v0, $10
800B6EC0	mult   v1, v0
800B6EC4	lhu    v0, $0002(s2)
800B6EC8	lh     v1, $0000(s1)
800B6ECC	mflo   a0
800B6ED0	sll    v0, v0, $10
800B6ED4	sra    v0, v0, $10
800B6ED8	mult   v1, v0
800B6EDC	sra    v0, a1, $0c
800B6EE0	sh     v0, $0002(s5)
800B6EE4	mflo   v0
800B6EE8	subu   a0, a0, v0
800B6EEC	bgez   a0, Lb6ef8 [$800b6ef8]
800B6EF0	nop
800B6EF4	addiu  a0, a0, $0fff

Lb6ef8:	; 800B6EF8
800B6EF8	lh     v0, $0000(s5)
800B6EFC	nop
800B6F00	mult   v0, v0
800B6F04	lhu    v0, $0002(s5)
800B6F08	mflo   v1
800B6F0C	sll    v0, v0, $10
800B6F10	sra    v0, v0, $10
800B6F14	mult   v0, v0
800B6F18	sra    a0, a0, $0c
800B6F1C	mflo   a1
800B6F20	sll    v0, a0, $10
800B6F24	sra    v0, v0, $10
800B6F28	mult   v0, v0
800B6F2C	sh     a0, $0004(s5)
800B6F30	addu   v1, v1, a1
800B6F34	mflo   a0
800B6F38	jal    system_square_root [$80039f5c]
800B6F3C	addu   a0, v1, a0
800B6F40	addu   a0, s5, zero
800B6F44	addu   a1, s4, zero
800B6F48	jal    func3a0b8 [$8003a0b8]
800B6F4C	addu   s1, v0, zero
800B6F50	lh     v0, $0000(s4)
800B6F54	nop
800B6F58	bne    v0, zero, Lb6fa8 [$800b6fa8]
800B6F5C	nop
800B6F60	lhu    v0, $0002(s4)
800B6F64	nop
800B6F68	bne    v0, zero, Lb6fa8 [$800b6fa8]
800B6F6C	nop
800B6F70	lhu    v0, $0004(s4)
800B6F74	nop
800B6F78	bne    v0, zero, Lb6fa8 [$800b6fa8]
800B6F7C	nop
800B6F80	sh     s3, $0014(s0)
800B6F84	sh     zero, $0016(s0)
800B6F88	sh     zero, $0018(s0)
800B6F8C	sh     zero, $001a(s0)
800B6F90	sh     s3, $001c(s0)
800B6F94	sh     zero, $001e(s0)
800B6F98	sh     zero, $0020(s0)
800B6F9C	sh     zero, $0022(s0)
800B6FA0	j      Lb719c [$800b719c]
800B6FA4	sh     s3, $0024(s0)

Lb6fa8:	; 800B6FA8
800B6FA8	lh     a1, $0000(s4)
800B6FAC	nop
800B6FB0	mult   a1, a1
800B6FB4	lhu    a0, $0002(s4)
800B6FB8	mflo   t2
800B6FBC	sll    a0, a0, $10
800B6FC0	sra    a0, a0, $10
800B6FC4	mult   a0, a0
800B6FC8	lhu    v1, $0004(s4)
800B6FCC	mflo   t3
800B6FD0	sll    v1, v1, $10
800B6FD4	sra    v1, v1, $10
800B6FD8	mult   v1, v1
800B6FDC	mflo   t6
800B6FE0	mult   a1, a0
800B6FE4	mflo   a2
800B6FE8	mult   a1, v1
800B6FEC	mflo   a3
800B6FF0	mult   a0, v1
800B6FF4	mflo   t0
800B6FF8	sll    v0, s1, $10
800B6FFC	sra    v0, v0, $10
800B7000	mult   a1, v0
800B7004	mflo   t5
800B7008	mult   a0, v0
800B700C	mflo   t4
800B7010	mult   v1, v0
800B7014	lui    v0, $0100
800B7018	subu   v1, v0, t2
800B701C	sll    v0, s6, $10
800B7020	sra    a1, v0, $10
800B7024	ori    v0, zero, $1000
800B7028	mflo   t1
800B702C	bgez   v1, Lb7038 [$800b7038]
800B7030	subu   a0, v0, a1
800B7034	addiu  v1, v1, $0fff

Lb7038:	; 800B7038
800B7038	sra    v0, v1, $0c
800B703C	mult   a1, v0
800B7040	mflo   v0
800B7044	addu   v0, t2, v0
800B7048	bgez   v0, Lb7054 [$800b7054]
800B704C	nop
800B7050	addiu  v0, v0, $0fff

Lb7054:	; 800B7054
800B7054	sra    v0, v0, $0c
800B7058	sh     v0, $0014(s0)
800B705C	bgez   a2, Lb7068 [$800b7068]
800B7060	addu   v0, a2, zero
800B7064	addiu  v0, a2, $0fff

Lb7068:	; 800B7068
800B7068	sra    v0, v0, $0c
800B706C	mult   v0, a0
800B7070	mflo   v1
800B7074	subu   v0, v1, t1
800B7078	bgez   v0, Lb7084 [$800b7084]
800B707C	nop
800B7080	addiu  v0, v0, $0fff

Lb7084:	; 800B7084
800B7084	sra    v0, v0, $0c
800B7088	sh     v0, $0016(s0)
800B708C	bgez   a3, Lb7098 [$800b7098]
800B7090	addu   v0, a3, zero
800B7094	addiu  v0, a3, $0fff

Lb7098:	; 800B7098
800B7098	sra    v0, v0, $0c
800B709C	mult   v0, a0
800B70A0	mflo   t2
800B70A4	addu   v0, t2, t4
800B70A8	bgez   v0, Lb70b4 [$800b70b4]
800B70AC	nop
800B70B0	addiu  v0, v0, $0fff

Lb70b4:	; 800B70B4
800B70B4	sra    v0, v0, $0c
800B70B8	sh     v0, $0018(s0)
800B70BC	addu   v0, v1, t1
800B70C0	bgez   v0, Lb70cc [$800b70cc]
800B70C4	lui    a2, $0100
800B70C8	addiu  v0, v0, $0fff

Lb70cc:	; 800B70CC
800B70CC	sra    v0, v0, $0c
800B70D0	sh     v0, $001a(s0)
800B70D4	subu   v0, a2, t3
800B70D8	bgez   v0, Lb70e4 [$800b70e4]
800B70DC	nop
800B70E0	addiu  v0, v0, $0fff

Lb70e4:	; 800B70E4
800B70E4	sra    v0, v0, $0c
800B70E8	mult   a1, v0
800B70EC	mflo   v0
800B70F0	addu   v0, t3, v0
800B70F4	bgez   v0, Lb7100 [$800b7100]
800B70F8	nop
800B70FC	addiu  v0, v0, $0fff

Lb7100:	; 800B7100
800B7100	sra    v0, v0, $0c
800B7104	sh     v0, $001c(s0)
800B7108	bgez   t0, Lb7114 [$800b7114]
800B710C	addu   v0, t0, zero
800B7110	addiu  v0, t0, $0fff

Lb7114:	; 800B7114
800B7114	sra    v0, v0, $0c
800B7118	mult   v0, a0
800B711C	mflo   v1
800B7120	subu   v0, v1, t5
800B7124	bgez   v0, Lb7130 [$800b7130]
800B7128	nop
800B712C	addiu  v0, v0, $0fff

Lb7130:	; 800B7130
800B7130	sra    v0, v0, $0c
800B7134	sh     v0, $001e(s0)
800B7138	subu   v0, t2, t4
800B713C	bgez   v0, Lb7148 [$800b7148]
800B7140	nop
800B7144	addiu  v0, v0, $0fff

Lb7148:	; 800B7148
800B7148	sra    v0, v0, $0c
800B714C	sh     v0, $0020(s0)
800B7150	addu   v0, v1, t5
800B7154	bgez   v0, Lb7160 [$800b7160]
800B7158	nop
800B715C	addiu  v0, v0, $0fff

Lb7160:	; 800B7160
800B7160	sra    v0, v0, $0c
800B7164	sh     v0, $0022(s0)
800B7168	subu   v0, a2, t6
800B716C	bgez   v0, Lb7178 [$800b7178]
800B7170	nop
800B7174	addiu  v0, v0, $0fff

Lb7178:	; 800B7178
800B7178	sra    v0, v0, $0c
800B717C	mult   a1, v0
800B7180	mflo   v0
800B7184	addu   v0, t6, v0
800B7188	bgez   v0, Lb7194 [$800b7194]
800B718C	nop
800B7190	addiu  v0, v0, $0fff

Lb7194:	; 800B7194
800B7194	sra    v0, v0, $0c
800B7198	sh     v0, $0024(s0)

Lb719c:	; 800B719C
800B719C	lw     t7, $0010(sp)
800B71A0	addu   a1, zero, zero
800B71A4	lhu    v0, $0018(t7)
800B71A8	lw     v1, $001c(t7)
800B71AC	lbu    a0, $0003(t7)
800B71B0	nop
800B71B4	beq    a0, zero, Lb7980 [$800b7980]
800B71B8	addu   v0, v0, v1
800B71BC	addu   v1, v0, zero

loopb71c0:	; 800B71C0
800B71C0	sb     zero, $0000(v1)
800B71C4	lw     t7, $0010(sp)
800B71C8	nop
800B71CC	lbu    v0, $0003(t7)
800B71D0	addiu  a1, a1, $0001
800B71D4	sltu   v0, a1, v0
800B71D8	bne    v0, zero, loopb71c0 [$800b71c0]
800B71DC	addiu  v1, v1, $0020
800B71E0	j      Lb7984 [$800b7984]
800B71E4	ori    v0, zero, $0001

Lb71e8:	; 800B71E8
800B71E8	ori    t7, t7, $0200
800B71EC	lui    s1, $1f80
800B71F0	ori    s1, s1, $0208
800B71F4	lui    s2, $1f80
800B71F8	ori    s2, s2, $0228
800B71FC	lui    s6, $1f80
800B7200	ori    s6, s6, $0248
800B7204	lui    fp, $1f80
800B7208	sw     t7, $0028(sp)
800B720C	lw     t7, $0010(sp)
800B7210	ori    fp, fp, $0268
800B7214	lhu    a0, $0018(t7)
800B7218	lw     v1, $001c(t7)
800B721C	lw     s4, $0020(t7)
800B7220	ori    v0, zero, $1000
800B7224	lui    at, $1f80
800B7228	sh     v0, $0218(at)
800B722C	lui    at, $1f80
800B7230	sh     v0, $0210(at)
800B7234	sh     v0, $0000(s1)
800B7238	lui    at, $1f80
800B723C	sw     zero, $0224(at)
800B7240	lui    at, $1f80
800B7244	sw     zero, $0220(at)
800B7248	lui    at, $1f80
800B724C	sw     zero, $021c(at)
800B7250	lui    at, $1f80
800B7254	sh     zero, $0216(at)
800B7258	lui    at, $1f80
800B725C	sh     zero, $0214(at)
800B7260	lui    at, $1f80
800B7264	sh     zero, $0212(at)
800B7268	lui    at, $1f80
800B726C	sh     zero, $020e(at)
800B7270	lui    at, $1f80
800B7274	sh     zero, $020c(at)
800B7278	lui    at, $1f80
800B727C	sh     zero, $020a(at)
800B7280	lui    at, $1f80
800B7284	sw     zero, $0244(at)
800B7288	lui    at, $1f80
800B728C	sw     zero, $0240(at)
800B7290	lui    at, $1f80
800B7294	sw     zero, $023c(at)
800B7298	lui    at, $1f80
800B729C	sw     zero, $0264(at)
800B72A0	lui    at, $1f80
800B72A4	sw     zero, $0260(at)
800B72A8	lui    at, $1f80
800B72AC	sw     zero, $025c(at)
800B72B0	lhu    v0, $0008(s0)
800B72B4	lw     t7, $0028(sp)
800B72B8	lui    s5, $1f80
800B72BC	sh     v0, $0000(t7)
800B72C0	lhu    v0, $000a(s0)
800B72C4	lw     t7, $0010(sp)
800B72C8	ori    s5, s5, $0288
800B72CC	lui    at, $1f80
800B72D0	sh     v0, $0202(at)
800B72D4	lhu    v0, $000c(s0)
800B72D8	addu   s7, zero, zero
800B72DC	lui    at, $1f80
800B72E0	sh     zero, $0206(at)
800B72E4	lui    at, $1f80
800B72E8	sh     v0, $0204(at)
800B72EC	lbu    v0, $0003(t7)
800B72F0	nop
800B72F4	beq    v0, zero, Lb7978 [$800b7978]
800B72F8	addu   a0, a0, v1
800B72FC	lui    t7, $1f80
800B7300	ori    t7, t7, $026a
800B7304	sw     t7, $0030(sp)
800B7308	lui    t7, $1f80
800B730C	ori    t7, t7, $026c
800B7310	sw     t7, $0038(sp)
800B7314	lui    t7, $1f80
800B7318	ori    t7, t7, $027c
800B731C	sw     t7, $0040(sp)
800B7320	lui    t7, $1f80
800B7324	ori    t7, t7, $028a
800B7328	sw     t7, $0048(sp)
800B732C	lui    t7, $1f80
800B7330	ori    t7, t7, $028c
800B7334	sw     t7, $0050(sp)
800B7338	lui    t7, $1f80
800B733C	ori    t7, t7, $029c
800B7340	addu   s3, a0, zero
800B7344	sw     t7, $0058(sp)

Lb7348:	; 800B7348
800B7348	lh     v0, $000e(s0)
800B734C	nop
800B7350	subu   v0, zero, v0
800B7354	sw     v0, $0014(s1)
800B7358	lh     v0, $0010(s0)
800B735C	nop
800B7360	subu   v0, zero, v0
800B7364	sw     v0, $0018(s1)
800B7368	lh     v0, $0012(s0)
800B736C	nop
800B7370	subu   v0, zero, v0
800B7374	sw     v0, $001c(s1)
800B7378	lhu    v0, $0014(s0)
800B737C	nop
800B7380	sh     v0, $0000(s2)
800B7384	lhu    v0, $0016(s0)
800B7388	nop
800B738C	sh     v0, $0002(s2)
800B7390	lhu    v0, $0018(s0)
800B7394	nop
800B7398	sh     v0, $0004(s2)
800B739C	lhu    v0, $001a(s0)
800B73A0	nop
800B73A4	sh     v0, $0006(s2)
800B73A8	lhu    v0, $001c(s0)
800B73AC	nop
800B73B0	sh     v0, $0008(s2)
800B73B4	lhu    v0, $001e(s0)
800B73B8	nop
800B73BC	sh     v0, $000a(s2)
800B73C0	lhu    v0, $0020(s0)
800B73C4	nop
800B73C8	sh     v0, $000c(s2)
800B73CC	lhu    v0, $0022(s0)
800B73D0	nop
800B73D4	sh     v0, $000e(s2)
800B73D8	lhu    v0, $0024(s0)
800B73DC	nop
800B73E0	sh     v0, $0010(s2)
800B73E4	lw     t4, $0000(s1)
800B73E8	lw     t5, $0004(s1)
800B73EC	ctc2   t4,vxy0
800B73F0	ctc2   t5,vz0
800B73F4	lw     t4, $0008(s1)
800B73F8	lw     t5, $000c(s1)
800B73FC	lw     t6, $0010(s1)
800B7400	ctc2   t4,vxy1
800B7404	ctc2   t5,vz1
800B7408	ctc2   t6,vxy2
800B740C	lbu    v0, $0001(s3)
800B7410	nop
800B7414	sll    v0, v0, $05
800B7418	addu   v0, s4, v0
800B741C	lhu    t4, $0000(v0)
800B7420	lhu    t5, $0006(v0)
800B7424	lhu    t6, $000c(v0)
800B7428	mtc2   t4,l13l21
800B742C	mtc2   t5,l22l23
800B7430	mtc2   t6,l31l32
800B7434	nop
800B7438	nop
800B743C	gte_func18t1,dqb
800B7440	mfc2   t4,l13l21
800B7444	mfc2   t5,l22l23
800B7448	mfc2   t6,l31l32
800B744C	sh     t4, $0000(fp)
800B7450	sh     t5, $0006(fp)
800B7454	sh     t6, $000c(fp)
800B7458	lbu    v0, $0001(s3)
800B745C	nop
800B7460	sll    v0, v0, $05
800B7464	addu   v0, s4, v0
800B7468	addiu  v0, v0, $0002
800B746C	lhu    t4, $0000(v0)
800B7470	lhu    t5, $0006(v0)
800B7474	lhu    t6, $000c(v0)
800B7478	mtc2   t4,l13l21
800B747C	mtc2   t5,l22l23
800B7480	mtc2   t6,l31l32
800B7484	nop
800B7488	nop
800B748C	gte_func18t1,dqb
800B7490	lw     t7, $0030(sp)
800B7494	mfc2   t4,l13l21
800B7498	mfc2   t5,l22l23
800B749C	mfc2   t6,l31l32
800B74A0	sh     t4, $0000(t7)
800B74A4	sh     t5, $0006(t7)
800B74A8	sh     t6, $000c(t7)
800B74AC	lbu    v0, $0001(s3)
800B74B0	nop
800B74B4	sll    v0, v0, $05
800B74B8	addu   v0, s4, v0
800B74BC	addiu  v0, v0, $0004
800B74C0	lhu    t4, $0000(v0)
800B74C4	lhu    t5, $0006(v0)
800B74C8	lhu    t6, $000c(v0)
800B74CC	mtc2   t4,l13l21
800B74D0	mtc2   t5,l22l23
800B74D4	mtc2   t6,l31l32
800B74D8	nop
800B74DC	nop
800B74E0	gte_func18t1,dqb
800B74E4	lw     t7, $0038(sp)
800B74E8	mfc2   t4,l13l21
800B74EC	mfc2   t5,l22l23
800B74F0	mfc2   t6,l31l32
800B74F4	sh     t4, $0000(t7)
800B74F8	sh     t5, $0006(t7)
800B74FC	sh     t6, $000c(t7)
800B7500	lw     t4, $0014(s1)
800B7504	lw     t5, $0018(s1)
800B7508	ctc2   t4,vz2
800B750C	lw     t6, $001c(s1)
800B7510	ctc2   t5,rgb
800B7514	ctc2   t6,otz
800B7518	lbu    v0, $0001(s3)
800B751C	nop
800B7520	sll    v0, v0, $05
800B7524	addu   v0, s4, v0
800B7528	addiu  v0, v0, $0014
800B752C	lhu    t5, $0004(v0)
800B7530	lhu    t4, $0000(v0)
800B7534	sll    t5, t5, $10
800B7538	or     t4, t4, t5
800B753C	mtc2   t4,r11r12
800B7540	lwc2   at, $0008(v0)
800B7544	nop
800B7548	nop
800B754C	gte_func18t0,r11r12
800B7550	lw     t7, $0040(sp)
800B7554	nop
800B7558	swc2   t1, $0000(t7)
800B755C	swc2   t2, $0004(t7)
800B7560	swc2   t3, $0008(t7)
800B7564	lw     t4, $0000(s2)
800B7568	lw     t5, $0004(s2)
800B756C	ctc2   t4,vxy0
800B7570	ctc2   t5,vz0
800B7574	lw     t4, $0008(s2)
800B7578	lw     t5, $000c(s2)
800B757C	lw     t6, $0010(s2)
800B7580	ctc2   t4,vxy1
800B7584	ctc2   t5,vz1
800B7588	ctc2   t6,vxy2
800B758C	lhu    t4, $0000(fp)
800B7590	lhu    t5, $0006(fp)
800B7594	lhu    t6, $000c(fp)
800B7598	mtc2   t4,l13l21
800B759C	mtc2   t5,l22l23
800B75A0	mtc2   t6,l31l32
800B75A4	nop
800B75A8	nop
800B75AC	gte_func18t1,dqb
800B75B0	mfc2   t4,l13l21
800B75B4	mfc2   t5,l22l23
800B75B8	mfc2   t6,l31l32
800B75BC	sh     t4, $0000(fp)
800B75C0	sh     t5, $0006(fp)
800B75C4	sh     t6, $000c(fp)
800B75C8	lw     t7, $0030(sp)
800B75CC	nop
800B75D0	lhu    t4, $0000(t7)
800B75D4	lhu    t5, $0006(t7)
800B75D8	lhu    t6, $000c(t7)
800B75DC	mtc2   t4,l13l21
800B75E0	mtc2   t5,l22l23
800B75E4	mtc2   t6,l31l32
800B75E8	nop
800B75EC	nop
800B75F0	gte_func18t1,dqb
800B75F4	mfc2   t4,l13l21
800B75F8	mfc2   t5,l22l23
800B75FC	mfc2   t6,l31l32
800B7600	sh     t4, $0000(t7)
800B7604	sh     t5, $0006(t7)
800B7608	sh     t6, $000c(t7)
800B760C	lw     t7, $0038(sp)
800B7610	nop
800B7614	lhu    t4, $0000(t7)
800B7618	lhu    t5, $0006(t7)
800B761C	lhu    t6, $000c(t7)
800B7620	mtc2   t4,l13l21
800B7624	mtc2   t5,l22l23
800B7628	mtc2   t6,l31l32
800B762C	nop
800B7630	nop
800B7634	gte_func18t1,dqb
800B7638	mfc2   t4,l13l21
800B763C	mfc2   t5,l22l23
800B7640	mfc2   t6,l31l32
800B7644	sh     t4, $0000(t7)
800B7648	sh     t5, $0006(t7)
800B764C	sh     t6, $000c(t7)
800B7650	lw     t4, $0014(s2)
800B7654	lw     t5, $0018(s2)
800B7658	ctc2   t4,vz2
800B765C	lw     t6, $001c(s2)
800B7660	ctc2   t5,rgb
800B7664	ctc2   t6,otz
800B7668	lw     t7, $0040(sp)
800B766C	nop
800B7670	lhu    t5, $0004(t7)
800B7674	lhu    t4, $0000(t7)
800B7678	sll    t5, t5, $10
800B767C	or     t4, t4, t5
800B7680	mtc2   t4,r11r12
800B7684	lwc2   at, $0008(t7)
800B7688	nop
800B768C	nop
800B7690	gte_func18t0,r11r12
800B7694	swc2   t1, $0000(t7)
800B7698	swc2   t2, $0004(t7)
800B769C	swc2   t3, $0008(t7)
800B76A0	lh     v0, $000e(s0)
800B76A4	nop
800B76A8	sw     v0, $0014(s1)
800B76AC	lh     v0, $0010(s0)
800B76B0	addu   a0, s2, zero
800B76B4	sw     v0, $0018(s1)
800B76B8	lh     v0, $0012(s0)
800B76BC	addu   a1, s6, zero
800B76C0	jal    system_transponate_matrix [$8003bf3c]
800B76C4	sw     v0, $001c(s1)
800B76C8	lw     t4, $0000(s4)
800B76CC	lw     t5, $0004(s4)
800B76D0	ctc2   t4,vxy0
800B76D4	ctc2   t5,vz0
800B76D8	lw     t4, $0008(s4)
800B76DC	lw     t5, $000c(s4)
800B76E0	lw     t6, $0010(s4)
800B76E4	ctc2   t4,vxy1
800B76E8	ctc2   t5,vz1
800B76EC	ctc2   t6,vxy2
800B76F0	lhu    t4, $0000(s1)
800B76F4	lhu    t5, $0006(s1)
800B76F8	lhu    t6, $000c(s1)
800B76FC	mtc2   t4,l13l21
800B7700	mtc2   t5,l22l23
800B7704	mtc2   t6,l31l32
800B7708	nop
800B770C	nop
800B7710	gte_func18t1,dqb
800B7714	mfc2   t4,l13l21
800B7718	mfc2   t5,l22l23
800B771C	mfc2   t6,l31l32
800B7720	sh     t4, $0000(s5)
800B7724	sh     t5, $0006(s5)
800B7728	sh     t6, $000c(s5)
800B772C	addiu  v0, s1, $0002
800B7730	lhu    t4, $0000(v0)
800B7734	lhu    t5, $0006(v0)
800B7738	lhu    t6, $000c(v0)
800B773C	mtc2   t4,l13l21
800B7740	mtc2   t5,l22l23
800B7744	mtc2   t6,l31l32
800B7748	nop
800B774C	nop
800B7750	gte_func18t1,dqb
800B7754	lw     t7, $0048(sp)
800B7758	mfc2   t4,l13l21
800B775C	mfc2   t5,l22l23
800B7760	mfc2   t6,l31l32
800B7764	sh     t4, $0000(t7)
800B7768	sh     t5, $0006(t7)
800B776C	sh     t6, $000c(t7)
800B7770	addiu  v0, s1, $0004
800B7774	lhu    t4, $0000(v0)
800B7778	lhu    t5, $0006(v0)
800B777C	lhu    t6, $000c(v0)
800B7780	mtc2   t4,l13l21
800B7784	mtc2   t5,l22l23
800B7788	mtc2   t6,l31l32
800B778C	nop
800B7790	nop
800B7794	gte_func18t1,dqb
800B7798	lw     t7, $0050(sp)
800B779C	mfc2   t4,l13l21
800B77A0	mfc2   t5,l22l23
800B77A4	mfc2   t6,l31l32
800B77A8	sh     t4, $0000(t7)
800B77AC	sh     t5, $0006(t7)
800B77B0	sh     t6, $000c(t7)
800B77B4	lw     t4, $0014(s4)
800B77B8	lw     t5, $0018(s4)
800B77BC	ctc2   t4,vz2
800B77C0	lw     t6, $001c(s4)
800B77C4	ctc2   t5,rgb
800B77C8	ctc2   t6,otz
800B77CC	addiu  v0, s1, $0014
800B77D0	lhu    t5, $0004(v0)
800B77D4	lhu    t4, $0000(v0)
800B77D8	sll    t5, t5, $10
800B77DC	or     t4, t4, t5
800B77E0	mtc2   t4,r11r12
800B77E4	lwc2   at, $0008(v0)
800B77E8	nop
800B77EC	nop
800B77F0	gte_func18t0,r11r12
800B77F4	lw     t7, $0058(sp)
800B77F8	nop
800B77FC	swc2   t1, $0000(t7)
800B7800	swc2   t2, $0004(t7)
800B7804	swc2   t3, $0008(t7)
800B7808	lw     t4, $0000(s5)
800B780C	lw     t5, $0004(s5)
800B7810	ctc2   t4,vxy0
800B7814	ctc2   t5,vz0
800B7818	lw     t4, $0008(s5)
800B781C	lw     t5, $000c(s5)
800B7820	lw     t6, $0010(s5)
800B7824	ctc2   t4,vxy1
800B7828	ctc2   t5,vz1
800B782C	ctc2   t6,vxy2
800B7830	lhu    t4, $0000(s6)
800B7834	lhu    t5, $0006(s6)
800B7838	lhu    t6, $000c(s6)
800B783C	mtc2   t4,l13l21
800B7840	mtc2   t5,l22l23
800B7844	mtc2   t6,l31l32
800B7848	nop
800B784C	nop
800B7850	gte_func18t1,dqb
800B7854	mfc2   t4,l13l21
800B7858	mfc2   t5,l22l23
800B785C	mfc2   t6,l31l32
800B7860	sh     t4, $0000(s5)
800B7864	sh     t5, $0006(s5)
800B7868	sh     t6, $000c(s5)
800B786C	addiu  v0, s6, $0002
800B7870	lhu    t4, $0000(v0)
800B7874	lhu    t5, $0006(v0)
800B7878	lhu    t6, $000c(v0)
800B787C	mtc2   t4,l13l21
800B7880	mtc2   t5,l22l23
800B7884	mtc2   t6,l31l32
800B7888	nop
800B788C	nop
800B7890	gte_func18t1,dqb
800B7894	lw     t7, $0048(sp)
800B7898	mfc2   t4,l13l21
800B789C	mfc2   t5,l22l23
800B78A0	mfc2   t6,l31l32
800B78A4	sh     t4, $0000(t7)
800B78A8	sh     t5, $0006(t7)
800B78AC	sh     t6, $000c(t7)
800B78B0	addiu  v0, s6, $0004
800B78B4	lhu    t4, $0000(v0)
800B78B8	lhu    t5, $0006(v0)
800B78BC	lhu    t6, $000c(v0)
800B78C0	mtc2   t4,l13l21
800B78C4	mtc2   t5,l22l23
800B78C8	mtc2   t6,l31l32
800B78CC	nop
800B78D0	nop
800B78D4	gte_func18t1,dqb
800B78D8	lw     t7, $0050(sp)
800B78DC	mfc2   t4,l13l21
800B78E0	mfc2   t5,l22l23
800B78E4	mfc2   t6,l31l32
800B78E8	sh     t4, $0000(t7)
800B78EC	sh     t5, $0006(t7)
800B78F0	sh     t6, $000c(t7)
800B78F4	lw     t4, $0014(s5)
800B78F8	lw     t5, $0018(s5)
800B78FC	ctc2   t4,vz2
800B7900	lw     t6, $001c(s5)
800B7904	ctc2   t5,rgb
800B7908	ctc2   t6,otz
800B790C	addiu  v0, s6, $0014
800B7910	lhu    t5, $0004(v0)
800B7914	lhu    t4, $0000(v0)
800B7918	sll    t5, t5, $10
800B791C	or     t4, t4, t5
800B7920	mtc2   t4,r11r12
800B7924	lwc2   at, $0008(v0)
800B7928	nop
800B792C	nop
800B7930	gte_func18t0,r11r12
800B7934	lw     t7, $0058(sp)
800B7938	nop
800B793C	swc2   t1, $0000(t7)
800B7940	swc2   t2, $0004(t7)
800B7944	swc2   t3, $0008(t7)
800B7948	addu   a0, s3, zero
800B794C	addu   a2, fp, zero
800B7950	lw     a1, $0028(sp)
800B7954	jal    funcb79b8 [$800b79b8]
800B7958	addu   a3, s5, zero
800B795C	lw     t7, $0010(sp)
800B7960	nop
800B7964	lbu    v0, $0003(t7)
800B7968	addiu  s7, s7, $0001
800B796C	sltu   v0, s7, v0
800B7970	bne    v0, zero, Lb7348 [$800b7348]
800B7974	addiu  s3, s3, $0020

Lb7978:	; 800B7978
800B7978	j      Lb7984 [$800b7984]
800B797C	addu   v0, zero, zero

Lb7980:	; 800B7980
800B7980	ori    v0, zero, $0001

Lb7984:	; 800B7984
800B7984	lw     ra, $0094(sp)
800B7988	lw     fp, $0090(sp)
800B798C	lw     s7, $008c(sp)
800B7990	lw     s6, $0088(sp)
800B7994	lw     s5, $0084(sp)
800B7998	lw     s4, $0080(sp)
800B799C	lw     s3, $007c(sp)
800B79A0	lw     s2, $0078(sp)
800B79A4	lw     s1, $0074(sp)
800B79A8	lw     s0, $0070(sp)
800B79AC	addiu  sp, sp, $0098
800B79B0	jr     ra 
800B79B4	nop


funcb79b8:	; 800B79B8
800B79B8	addiu  sp, sp, $ffa0 (=-$60)
800B79BC	sw     s0, $0050(sp)
800B79C0	lui    s0, $800e
800B79C4	lw     s0, $f118(s0)
800B79C8	sw     s3, $005c(sp)
800B79CC	addu   s3, a0, zero
800B79D0	sw     s2, $0058(sp)
800B79D4	sw     s1, $0054(sp)
800B79D8	lw     t4, $0000(a2)
800B79DC	lw     t5, $0004(a2)
800B79E0	ctc2   t4,vxy0
800B79E4	ctc2   t5,vz0
800B79E8	lw     t4, $0008(a2)
800B79EC	lw     t5, $000c(a2)
800B79F0	lw     t6, $0010(a2)
800B79F4	ctc2   t4,vxy1
800B79F8	ctc2   t5,vz1
800B79FC	ctc2   t6,vxy2
800B7A00	lw     t4, $0014(a2)
800B7A04	lw     t5, $0018(a2)
800B7A08	ctc2   t4,vz2
800B7A0C	lw     t6, $001c(a2)
800B7A10	ctc2   t5,rgb
800B7A14	ctc2   t6,otz
800B7A18	lw     v0, $0018(s3)
800B7A1C	lbu    t9, $0002(s3)
800B7A20	addiu  t8, v0, $0004
800B7A24	lh     v0, $0000(a1)
800B7A28	lui    t7, $800e
800B7A2C	lw     t7, $01fc(t7)
800B7A30	bne    v0, zero, Lb7a58 [$800b7a58]
800B7A34	addu   a0, zero, zero
800B7A38	lh     v0, $0002(a1)
800B7A3C	nop
800B7A40	bne    v0, zero, Lb7a58 [$800b7a58]
800B7A44	addiu  v1, zero, $f000 (=-$1000)
800B7A48	lh     v0, $0004(a1)
800B7A4C	nop
800B7A50	xor    v0, v0, v1
800B7A54	sltiu  a0, v0, $0001

Lb7a58:	; 800B7A58
800B7A58	beq    t9, zero, Lb7adc [$800b7adc]
800B7A5C	addu   t1, zero, zero
800B7A60	addu   v1, t7, zero

loopb7a64:	; 800B7A64
800B7A64	lwc2   zero, $0000(t8)
800B7A68	lwc2   at, $0004(t8)
800B7A6C	nop
800B7A70	nop
800B7A74	gte_func18t0,r11r12
800B7A78	addiu  t8, t8, $0008
800B7A7C	addiu  v0, v1, $0008
800B7A80	mfc2   t4,l13l21
800B7A84	mfc2   t5,l22l23
800B7A88	mfc2   t6,l31l32
800B7A8C	sh     t4, $0000(v0)
800B7A90	sh     t5, $0002(v0)
800B7A94	sh     t6, $0004(v0)
800B7A98	beq    a0, zero, Lb7ab8 [$800b7ab8]
800B7A9C	nop
800B7AA0	lh     v0, $000c(v1)
800B7AA4	nop
800B7AA8	blez   v0, Lb7acc [$800b7acc]
800B7AAC	nop
800B7AB0	j      Lb7acc [$800b7acc]
800B7AB4	sh     zero, $000c(v1)

Lb7ab8:	; 800B7AB8
800B7AB8	lh     v0, $000c(v1)
800B7ABC	nop
800B7AC0	bgez   v0, Lb7acc [$800b7acc]
800B7AC4	nop
800B7AC8	sh     zero, $000c(v1)

Lb7acc:	; 800B7ACC
800B7ACC	addiu  t1, t1, $0001
800B7AD0	sltu   v0, t1, t9
800B7AD4	bne    v0, zero, loopb7a64 [$800b7a64]
800B7AD8	addiu  v1, v1, $0010

Lb7adc:	; 800B7ADC
800B7ADC	lw     t4, $0000(a3)
800B7AE0	lw     t5, $0004(a3)
800B7AE4	ctc2   t4,vxy0
800B7AE8	ctc2   t5,vz0
800B7AEC	lw     t4, $0008(a3)
800B7AF0	lw     t5, $000c(a3)
800B7AF4	lw     t6, $0010(a3)
800B7AF8	ctc2   t4,vxy1
800B7AFC	ctc2   t5,vz1
800B7B00	ctc2   t6,vxy2
800B7B04	lw     t4, $0014(a3)
800B7B08	lw     t5, $0018(a3)
800B7B0C	ctc2   t4,vz2
800B7B10	lw     t6, $001c(a3)
800B7B14	ctc2   t5,rgb
800B7B18	ctc2   t6,otz
800B7B1C	beq    t9, zero, Lb7b5c [$800b7b5c]
800B7B20	addu   t1, zero, zero
800B7B24	addu   v1, t7, zero

loopb7b28:	; 800B7B28
800B7B28	addiu  v0, v1, $0008
800B7B2C	lwc2   zero, $0000(v0)
800B7B30	lwc2   at, $0004(v0)
800B7B34	nop
800B7B38	nop
800B7B3C	gte_func16t8,r11r12
800B7B40	swc2   t6, $0000(v1)
800B7B44	addiu  v0, v1, $0004
800B7B48	swc2   s3, $0000(v0)
800B7B4C	addiu  t1, t1, $0001
800B7B50	sltu   v0, t1, t9
800B7B54	bne    v0, zero, loopb7b28 [$800b7b28]
800B7B58	addiu  v1, v1, $0010

Lb7b5c:	; 800B7B5C
800B7B5C	lui    v0, $800e
800B7B60	lbu    v0, $f114(v0)
800B7B64	lw     t0, $001c(s3)
800B7B68	beq    v0, zero, Lb7b7c [$800b7b7c]
800B7B6C	addu   t1, zero, zero
800B7B70	lhu    v0, $0016(s3)
800B7B74	nop
800B7B78	addu   t0, t0, v0

Lb7b7c:	; 800B7B7C
800B7B7C	lw     s2, $0004(s3)
800B7B80	nop
800B7B84	andi   t9, s2, $00ff
800B7B88	beq    t9, zero, Lb7d14 [$800b7d14]
800B7B8C	andi   v0, s2, $ff00
800B7B90	lui    s1, $ff00
800B7B94	lui    t6, $00ff
800B7B98	ori    t6, t6, $ffff
800B7B9C	addiu  t4, t0, $002c

loopb7ba0:	; 800B7BA0
800B7BA0	lw     v1, $0000(t8)
800B7BA4	addu   t5, t0, zero
800B7BA8	andi   v0, v1, $00ff
800B7BAC	sll    v0, v0, $04
800B7BB0	addu   t3, t7, v0
800B7BB4	andi   v0, v1, $ff00
800B7BB8	srl    v0, v0, $04
800B7BBC	addu   t2, t7, v0
800B7BC0	srl    v0, v1, $0c
800B7BC4	andi   v0, v0, $0ff0
800B7BC8	addu   a3, t7, v0
800B7BCC	srl    v1, v1, $18
800B7BD0	sll    v1, v1, $04
800B7BD4	addu   a2, t7, v1
800B7BD8	lw     v0, $0000(t3)
800B7BDC	lw     v1, $0000(t2)
800B7BE0	lw     a0, $0000(a3)
800B7BE4	lw     a1, $0000(a2)
800B7BE8	mtc2   v0,l33
800B7BEC	mtc2   a0,gbk
800B7BF0	mtc2   v1,rbk
800B7BF4	nop
800B7BF8	nop
800B7BFC	gte_func26zero,r11r12
800B7C00	sw     v0, $ffdc(t4)
800B7C04	sw     v1, $ffe8(t4)
800B7C08	sw     a0, $fff4(t4)
800B7C0C	sw     a1, $0000(t4)
800B7C10	mfc2   v0,ofx
800B7C14	nop
800B7C18	blez   v0, Lb7c60 [$800b7c60]
800B7C1C	nop
800B7C20	lh     v0, $000c(t3)
800B7C24	nop
800B7C28	bne    v0, zero, Lb7c74 [$800b7c74]
800B7C2C	nop
800B7C30	lh     v0, $000c(t2)
800B7C34	nop
800B7C38	bne    v0, zero, Lb7c74 [$800b7c74]
800B7C3C	nop
800B7C40	lh     v0, $000c(a3)
800B7C44	nop
800B7C48	bne    v0, zero, Lb7c74 [$800b7c74]
800B7C4C	nop
800B7C50	lh     v0, $000c(a2)
800B7C54	nop
800B7C58	bne    v0, zero, Lb7c74 [$800b7c74]
800B7C5C	nop

Lb7c60:	; 800B7C60
800B7C60	lw     v0, $0000(t0)
800B7C64	nop
800B7C68	and    v0, v0, s1
800B7C6C	j      Lb7cf8 [$800b7cf8]
800B7C70	sw     v0, $0000(t0)

Lb7c74:	; 800B7C74
800B7C74	lw     v0, $0004(t3)
800B7C78	lw     v1, $0004(t2)
800B7C7C	nop
800B7C80	addu   v0, v0, v1
800B7C84	lw     v1, $0004(a3)
800B7C88	lw     a0, $0004(a2)
800B7C8C	addu   v0, v0, v1
800B7C90	addu   v0, v0, a0
800B7C94	srl    v0, v0, $04
800B7C98	sll    v0, v0, $02
800B7C9C	addu   v0, v0, s0
800B7CA0	lw     v1, $0000(t5)
800B7CA4	lw     v0, $0000(v0)
800B7CA8	and    v1, v1, s1
800B7CAC	and    v0, v0, t6
800B7CB0	or     v1, v1, v0
800B7CB4	sw     v1, $0000(t5)
800B7CB8	lw     v1, $0004(t3)
800B7CBC	lw     v0, $0004(t2)
800B7CC0	nop
800B7CC4	addu   v1, v1, v0
800B7CC8	lw     v0, $0004(a3)
800B7CCC	lw     a0, $0004(a2)
800B7CD0	addu   v1, v1, v0
800B7CD4	addu   v1, v1, a0
800B7CD8	srl    v1, v1, $04
800B7CDC	sll    v1, v1, $02
800B7CE0	addu   v1, v1, s0
800B7CE4	lw     v0, $0000(v1)
800B7CE8	and    a0, t5, t6
800B7CEC	and    v0, v0, s1
800B7CF0	or     v0, v0, a0
800B7CF4	sw     v0, $0000(v1)

Lb7cf8:	; 800B7CF8
800B7CF8	addiu  t1, t1, $0001
800B7CFC	addiu  t4, t4, $0034
800B7D00	addiu  t0, t0, $0034
800B7D04	sltu   v0, t1, t9
800B7D08	bne    v0, zero, loopb7ba0 [$800b7ba0]
800B7D0C	addiu  t8, t8, $0018
800B7D10	andi   v0, s2, $ff00

Lb7d14:	; 800B7D14
800B7D14	srl    t9, v0, $08
800B7D18	beq    t9, zero, Lb7e58 [$800b7e58]
800B7D1C	addu   t1, zero, zero
800B7D20	lui    t5, $ff00
800B7D24	lui    t4, $00ff
800B7D28	ori    t4, t4, $ffff
800B7D2C	addiu  t2, t0, $0020

loopb7d30:	; 800B7D30
800B7D30	lw     v1, $0000(t8)
800B7D34	addu   t3, t0, zero
800B7D38	andi   v0, v1, $00ff
800B7D3C	sll    v0, v0, $04
800B7D40	addu   a3, t7, v0
800B7D44	andi   v0, v1, $ff00
800B7D48	srl    v0, v0, $04
800B7D4C	addu   a2, t7, v0
800B7D50	srl    v1, v1, $0c
800B7D54	andi   v1, v1, $0ff0
800B7D58	addu   a1, t7, v1
800B7D5C	lw     v0, $0000(a3)
800B7D60	lw     v1, $0000(a2)
800B7D64	lw     a0, $0000(a1)
800B7D68	mtc2   v0,l33
800B7D6C	mtc2   a0,gbk
800B7D70	mtc2   v1,rbk
800B7D74	nop
800B7D78	nop
800B7D7C	gte_func26zero,r11r12
800B7D80	sw     v0, $ffe8(t2)
800B7D84	sw     v1, $fff4(t2)
800B7D88	sw     a0, $0000(t2)
800B7D8C	mfc2   v0,ofx
800B7D90	nop
800B7D94	blez   v0, Lb7dcc [$800b7dcc]
800B7D98	nop
800B7D9C	lh     v0, $000c(a3)
800B7DA0	nop
800B7DA4	bne    v0, zero, Lb7de0 [$800b7de0]
800B7DA8	nop
800B7DAC	lh     v0, $000c(a2)
800B7DB0	nop
800B7DB4	bne    v0, zero, Lb7de0 [$800b7de0]
800B7DB8	nop
800B7DBC	lh     v0, $000c(a1)
800B7DC0	nop
800B7DC4	bne    v0, zero, Lb7de0 [$800b7de0]
800B7DC8	nop

Lb7dcc:	; 800B7DCC
800B7DCC	lw     v0, $0000(t0)
800B7DD0	nop
800B7DD4	and    v0, v0, t5
800B7DD8	j      Lb7e40 [$800b7e40]
800B7DDC	sw     v0, $0000(t0)

Lb7de0:	; 800B7DE0
800B7DE0	lw     a3, $0004(a3)
800B7DE4	lw     a2, $0004(a2)
800B7DE8	lw     a1, $0004(a1)
800B7DEC	mtc2   a3,lr3lg1
800B7DF0	mtc2   a2,lg2lg3
800B7DF4	mtc2   a1,lb1lb2
800B7DF8	nop
800B7DFC	nop
800B7E00	gte_func26t8,r11r12
800B7E04	mfc2   a0,trz
800B7E08	nop
800B7E0C	sll    a0, a0, $02
800B7E10	addu   a0, a0, s0
800B7E14	lw     v1, $0000(t3)
800B7E18	lw     v0, $0000(a0)
800B7E1C	and    v1, v1, t5
800B7E20	and    v0, v0, t4
800B7E24	or     v1, v1, v0
800B7E28	sw     v1, $0000(t3)
800B7E2C	lw     v0, $0000(a0)
800B7E30	and    v1, t3, t4
800B7E34	and    v0, v0, t5
800B7E38	or     v0, v0, v1
800B7E3C	sw     v0, $0000(a0)

Lb7e40:	; 800B7E40
800B7E40	addiu  t1, t1, $0001
800B7E44	addiu  t2, t2, $0028
800B7E48	addiu  t0, t0, $0028
800B7E4C	sltu   v0, t1, t9
800B7E50	bne    v0, zero, loopb7d30 [$800b7d30]
800B7E54	addiu  t8, t8, $0014

Lb7e58:	; 800B7E58
800B7E58	srl    v0, s2, $10
800B7E5C	andi   t9, v0, $00ff
800B7E60	beq    t9, zero, Lb7fe8 [$800b7fe8]
800B7E64	addu   t1, zero, zero
800B7E68	lui    s1, $ff00
800B7E6C	lui    t6, $00ff
800B7E70	ori    t6, t6, $ffff
800B7E74	addiu  t4, t0, $0020

loopb7e78:	; 800B7E78
800B7E78	lw     v1, $0000(t8)
800B7E7C	addu   t5, t0, zero
800B7E80	andi   v0, v1, $00ff
800B7E84	sll    v0, v0, $04
800B7E88	addu   t3, t7, v0
800B7E8C	andi   v0, v1, $ff00
800B7E90	srl    v0, v0, $04
800B7E94	addu   t2, t7, v0
800B7E98	srl    v0, v1, $0c
800B7E9C	andi   v0, v0, $0ff0
800B7EA0	addu   a3, t7, v0
800B7EA4	srl    v1, v1, $18
800B7EA8	sll    v1, v1, $04
800B7EAC	addu   a2, t7, v1
800B7EB0	lw     v0, $0000(t3)
800B7EB4	lw     v1, $0000(t2)
800B7EB8	lw     a0, $0000(a3)
800B7EBC	lw     a1, $0000(a2)
800B7EC0	mtc2   v0,l33
800B7EC4	mtc2   a0,gbk
800B7EC8	mtc2   v1,rbk
800B7ECC	nop
800B7ED0	nop
800B7ED4	gte_func26zero,r11r12
800B7ED8	sw     v0, $ffe8(t4)
800B7EDC	sw     v1, $fff0(t4)
800B7EE0	sw     a0, $fff8(t4)
800B7EE4	sw     a1, $0000(t4)
800B7EE8	mfc2   v0,ofx
800B7EEC	nop
800B7EF0	blez   v0, Lb7f38 [$800b7f38]
800B7EF4	nop
800B7EF8	lh     v0, $000c(t3)
800B7EFC	nop
800B7F00	bne    v0, zero, Lb7f4c [$800b7f4c]
800B7F04	nop
800B7F08	lh     v0, $000c(t2)
800B7F0C	nop
800B7F10	bne    v0, zero, Lb7f4c [$800b7f4c]
800B7F14	nop
800B7F18	lh     v0, $000c(a3)
800B7F1C	nop
800B7F20	bne    v0, zero, Lb7f4c [$800b7f4c]
800B7F24	nop
800B7F28	lh     v0, $000c(a2)
800B7F2C	nop
800B7F30	bne    v0, zero, Lb7f4c [$800b7f4c]
800B7F34	nop

Lb7f38:	; 800B7F38
800B7F38	lw     v0, $0000(t0)
800B7F3C	nop
800B7F40	and    v0, v0, s1
800B7F44	j      Lb7fd0 [$800b7fd0]
800B7F48	sw     v0, $0000(t0)

Lb7f4c:	; 800B7F4C
800B7F4C	lw     v0, $0004(t3)
800B7F50	lw     v1, $0004(t2)
800B7F54	nop
800B7F58	addu   v0, v0, v1
800B7F5C	lw     v1, $0004(a3)
800B7F60	lw     a0, $0004(a2)
800B7F64	addu   v0, v0, v1
800B7F68	addu   v0, v0, a0
800B7F6C	srl    v0, v0, $04
800B7F70	sll    v0, v0, $02
800B7F74	addu   v0, v0, s0
800B7F78	lw     v1, $0000(t5)
800B7F7C	lw     v0, $0000(v0)
800B7F80	and    v1, v1, s1
800B7F84	and    v0, v0, t6
800B7F88	or     v1, v1, v0
800B7F8C	sw     v1, $0000(t5)
800B7F90	lw     v1, $0004(t3)
800B7F94	lw     v0, $0004(t2)
800B7F98	nop
800B7F9C	addu   v1, v1, v0
800B7FA0	lw     v0, $0004(a3)
800B7FA4	lw     a0, $0004(a2)
800B7FA8	addu   v1, v1, v0
800B7FAC	addu   v1, v1, a0
800B7FB0	srl    v1, v1, $04
800B7FB4	sll    v1, v1, $02
800B7FB8	addu   v1, v1, s0
800B7FBC	lw     v0, $0000(v1)
800B7FC0	and    a0, t5, t6
800B7FC4	and    v0, v0, s1
800B7FC8	or     v0, v0, a0
800B7FCC	sw     v0, $0000(v1)

Lb7fd0:	; 800B7FD0
800B7FD0	addiu  t1, t1, $0001
800B7FD4	addiu  t4, t4, $0028
800B7FD8	addiu  t0, t0, $0028
800B7FDC	sltu   v0, t1, t9
800B7FE0	bne    v0, zero, loopb7e78 [$800b7e78]
800B7FE4	addiu  t8, t8, $000c

Lb7fe8:	; 800B7FE8
800B7FE8	srl    t9, s2, $18
800B7FEC	beq    t9, zero, Lb812c [$800b812c]
800B7FF0	addu   t1, zero, zero
800B7FF4	lui    t5, $ff00
800B7FF8	lui    t4, $00ff
800B7FFC	ori    t4, t4, $ffff
800B8000	addiu  t2, t0, $0018

loopb8004:	; 800B8004
800B8004	lw     v1, $0000(t8)
800B8008	addu   t3, t0, zero
800B800C	andi   v0, v1, $00ff
800B8010	sll    v0, v0, $04
800B8014	addu   a3, t7, v0
800B8018	andi   v0, v1, $ff00
800B801C	srl    v0, v0, $04
800B8020	addu   a2, t7, v0
800B8024	srl    v1, v1, $0c
800B8028	andi   v1, v1, $0ff0
800B802C	addu   a1, t7, v1
800B8030	lw     v0, $0000(a3)
800B8034	lw     v1, $0000(a2)
800B8038	lw     a0, $0000(a1)
800B803C	mtc2   v0,l33
800B8040	mtc2   a0,gbk
800B8044	mtc2   v1,rbk
800B8048	nop
800B804C	nop
800B8050	gte_func26zero,r11r12
800B8054	sw     v0, $fff0(t2)
800B8058	sw     v1, $fff8(t2)
800B805C	sw     a0, $0000(t2)
800B8060	mfc2   v0,ofx
800B8064	nop
800B8068	blez   v0, Lb80a0 [$800b80a0]
800B806C	nop
800B8070	lh     v0, $000c(a3)
800B8074	nop
800B8078	bne    v0, zero, Lb80b4 [$800b80b4]
800B807C	nop
800B8080	lh     v0, $000c(a2)
800B8084	nop
800B8088	bne    v0, zero, Lb80b4 [$800b80b4]
800B808C	nop
800B8090	lh     v0, $000c(a1)
800B8094	nop
800B8098	bne    v0, zero, Lb80b4 [$800b80b4]
800B809C	nop

Lb80a0:	; 800B80A0
800B80A0	lw     v0, $0000(t0)
800B80A4	nop
800B80A8	and    v0, v0, t5
800B80AC	j      Lb8114 [$800b8114]
800B80B0	sw     v0, $0000(t0)

Lb80b4:	; 800B80B4
800B80B4	lw     a3, $0004(a3)
800B80B8	lw     a2, $0004(a2)
800B80BC	lw     a1, $0004(a1)
800B80C0	mtc2   a3,lr3lg1
800B80C4	mtc2   a2,lg2lg3
800B80C8	mtc2   a1,lb1lb2
800B80CC	nop
800B80D0	nop
800B80D4	gte_func26t8,r11r12
800B80D8	mfc2   a0,trz
800B80DC	nop
800B80E0	sll    a0, a0, $02
800B80E4	addu   a0, a0, s0
800B80E8	lw     v1, $0000(t3)
800B80EC	lw     v0, $0000(a0)
800B80F0	and    v1, v1, t5
800B80F4	and    v0, v0, t4
800B80F8	or     v1, v1, v0
800B80FC	sw     v1, $0000(t3)
800B8100	lw     v0, $0000(a0)
800B8104	and    v1, t3, t4
800B8108	and    v0, v0, t5
800B810C	or     v0, v0, v1
800B8110	sw     v0, $0000(a0)

Lb8114:	; 800B8114
800B8114	addiu  t1, t1, $0001
800B8118	addiu  t2, t2, $0020
800B811C	addiu  t0, t0, $0020
800B8120	sltu   v0, t1, t9
800B8124	bne    v0, zero, loopb8004 [$800b8004]
800B8128	addiu  t8, t8, $000c

Lb812c:	; 800B812C
800B812C	lw     s2, $0008(s3)
800B8130	nop
800B8134	andi   t9, s2, $00ff
800B8138	beq    t9, zero, Lb8278 [$800b8278]
800B813C	addu   t1, zero, zero
800B8140	lui    t5, $ff00
800B8144	lui    t4, $00ff
800B8148	ori    t4, t4, $ffff
800B814C	addiu  t2, t0, $0010

loopb8150:	; 800B8150
800B8150	lw     v1, $0000(t8)
800B8154	addu   t3, t0, zero
800B8158	andi   v0, v1, $00ff
800B815C	sll    v0, v0, $04
800B8160	addu   a3, t7, v0
800B8164	andi   v0, v1, $ff00
800B8168	srl    v0, v0, $04
800B816C	addu   a2, t7, v0
800B8170	srl    v1, v1, $0c
800B8174	andi   v1, v1, $0ff0
800B8178	addu   a1, t7, v1
800B817C	lw     v0, $0000(a3)
800B8180	lw     v1, $0000(a2)
800B8184	lw     a0, $0000(a1)
800B8188	mtc2   v0,l33
800B818C	mtc2   a0,gbk
800B8190	mtc2   v1,rbk
800B8194	nop
800B8198	nop
800B819C	gte_func26zero,r11r12
800B81A0	sw     v0, $fff8(t2)
800B81A4	sw     v1, $fffc(t2)
800B81A8	sw     a0, $0000(t2)
800B81AC	mfc2   v0,ofx
800B81B0	nop
800B81B4	blez   v0, Lb81ec [$800b81ec]
800B81B8	nop
800B81BC	lh     v0, $000c(a3)
800B81C0	nop
800B81C4	bne    v0, zero, Lb8200 [$800b8200]
800B81C8	nop
800B81CC	lh     v0, $000c(a2)
800B81D0	nop
800B81D4	bne    v0, zero, Lb8200 [$800b8200]
800B81D8	nop
800B81DC	lh     v0, $000c(a1)
800B81E0	nop
800B81E4	bne    v0, zero, Lb8200 [$800b8200]
800B81E8	nop

Lb81ec:	; 800B81EC
800B81EC	lw     v0, $0000(t0)
800B81F0	nop
800B81F4	and    v0, v0, t5
800B81F8	j      Lb8260 [$800b8260]
800B81FC	sw     v0, $0000(t0)

Lb8200:	; 800B8200
800B8200	lw     a3, $0004(a3)
800B8204	lw     a2, $0004(a2)
800B8208	lw     a1, $0004(a1)
800B820C	mtc2   a3,lr3lg1
800B8210	mtc2   a2,lg2lg3
800B8214	mtc2   a1,lb1lb2
800B8218	nop
800B821C	nop
800B8220	gte_func26t8,r11r12
800B8224	mfc2   a0,trz
800B8228	nop
800B822C	sll    a0, a0, $02
800B8230	addu   a0, a0, s0
800B8234	lw     v1, $0000(t3)
800B8238	lw     v0, $0000(a0)
800B823C	and    v1, v1, t5
800B8240	and    v0, v0, t4
800B8244	or     v1, v1, v0
800B8248	sw     v1, $0000(t3)
800B824C	lw     v0, $0000(a0)
800B8250	and    v1, t3, t4
800B8254	and    v0, v0, t5
800B8258	or     v0, v0, v1
800B825C	sw     v0, $0000(a0)

Lb8260:	; 800B8260
800B8260	addiu  t1, t1, $0001
800B8264	addiu  t2, t2, $0014
800B8268	addiu  t0, t0, $0014
800B826C	sltu   v0, t1, t9
800B8270	bne    v0, zero, loopb8150 [$800b8150]
800B8274	addiu  t8, t8, $0008

Lb8278:	; 800B8278
800B8278	andi   v0, s2, $ff00
800B827C	srl    t9, v0, $08
800B8280	beq    t9, zero, Lb83f8 [$800b83f8]
800B8284	addu   t1, zero, zero
800B8288	lui    s1, $ff00
800B828C	lui    t6, $00ff
800B8290	ori    t6, t6, $ffff
800B8294	addiu  t4, t0, $0014

loopb8298:	; 800B8298
800B8298	lw     v1, $0000(t8)
800B829C	addu   t5, t0, zero
800B82A0	andi   v0, v1, $00ff
800B82A4	sll    v0, v0, $04
800B82A8	addu   t2, t7, v0
800B82AC	andi   v0, v1, $ff00
800B82B0	srl    v0, v0, $04
800B82B4	addu   a3, t7, v0
800B82B8	srl    v0, v1, $0c
800B82BC	andi   v0, v0, $0ff0
800B82C0	addu   a2, t7, v0
800B82C4	srl    v1, v1, $18
800B82C8	sll    v1, v1, $04
800B82CC	addu   t3, t7, v1
800B82D0	lw     v0, $0000(t2)
800B82D4	lw     v1, $0000(a3)
800B82D8	lw     a0, $0000(a2)
800B82DC	lw     a1, $0000(t3)
800B82E0	mtc2   v0,l33
800B82E4	mtc2   a0,gbk
800B82E8	mtc2   v1,rbk
800B82EC	nop
800B82F0	nop
800B82F4	gte_func26zero,r11r12
800B82F8	sw     v0, $fff4(t4)
800B82FC	sw     v1, $fff8(t4)
800B8300	sw     a0, $fffc(t4)
800B8304	sw     a1, $0000(t4)
800B8308	mfc2   v0,ofx
800B830C	nop
800B8310	blez   v0, Lb8348 [$800b8348]
800B8314	nop
800B8318	lh     v0, $000c(t2)
800B831C	nop
800B8320	bne    v0, zero, Lb835c [$800b835c]
800B8324	nop
800B8328	lh     v0, $000c(a3)
800B832C	nop
800B8330	bne    v0, zero, Lb835c [$800b835c]
800B8334	nop
800B8338	lh     v0, $000c(a2)
800B833C	nop
800B8340	bne    v0, zero, Lb835c [$800b835c]
800B8344	nop

Lb8348:	; 800B8348
800B8348	lw     v0, $0000(t0)
800B834C	nop
800B8350	and    v0, v0, s1
800B8354	j      Lb83e0 [$800b83e0]
800B8358	sw     v0, $0000(t0)

Lb835c:	; 800B835C
800B835C	lw     v0, $0004(t2)
800B8360	lw     v1, $0004(a3)
800B8364	nop
800B8368	addu   v0, v0, v1
800B836C	lw     v1, $0004(a2)
800B8370	lw     a0, $0004(t3)
800B8374	addu   v0, v0, v1
800B8378	addu   v0, v0, a0
800B837C	srl    v0, v0, $04
800B8380	sll    v0, v0, $02
800B8384	addu   v0, v0, s0
800B8388	lw     v1, $0000(t5)
800B838C	lw     v0, $0000(v0)
800B8390	and    v1, v1, s1
800B8394	and    v0, v0, t6
800B8398	or     v1, v1, v0
800B839C	sw     v1, $0000(t5)
800B83A0	lw     v1, $0004(t2)
800B83A4	lw     v0, $0004(a3)
800B83A8	nop
800B83AC	addu   v1, v1, v0
800B83B0	lw     v0, $0004(a2)
800B83B4	lw     a0, $0004(t3)
800B83B8	addu   v1, v1, v0
800B83BC	addu   v1, v1, a0
800B83C0	srl    v1, v1, $04
800B83C4	sll    v1, v1, $02
800B83C8	addu   v1, v1, s0
800B83CC	lw     v0, $0000(v1)
800B83D0	and    a0, t5, t6
800B83D4	and    v0, v0, s1
800B83D8	or     v0, v0, a0
800B83DC	sw     v0, $0000(v1)

Lb83e0:	; 800B83E0
800B83E0	addiu  t1, t1, $0001
800B83E4	addiu  t4, t4, $0018
800B83E8	addiu  t0, t0, $0018
800B83EC	sltu   v0, t1, t9
800B83F0	bne    v0, zero, loopb8298 [$800b8298]
800B83F4	addiu  t8, t8, $0008

Lb83f8:	; 800B83F8
800B83F8	srl    v0, s2, $10
800B83FC	andi   t9, v0, $00ff
800B8400	beq    t9, zero, Lb8540 [$800b8540]
800B8404	addu   t1, zero, zero
800B8408	lui    t5, $ff00
800B840C	lui    t4, $00ff
800B8410	ori    t4, t4, $ffff
800B8414	addiu  t2, t0, $0018

loopb8418:	; 800B8418
800B8418	lw     v1, $0000(t8)
800B841C	addu   t3, t0, zero
800B8420	andi   v0, v1, $00ff
800B8424	sll    v0, v0, $04
800B8428	addu   a3, t7, v0
800B842C	andi   v0, v1, $ff00
800B8430	srl    v0, v0, $04
800B8434	addu   a2, t7, v0
800B8438	srl    v1, v1, $0c
800B843C	andi   v1, v1, $0ff0
800B8440	addu   a1, t7, v1
800B8444	lw     v0, $0000(a3)
800B8448	lw     v1, $0000(a2)
800B844C	lw     a0, $0000(a1)
800B8450	mtc2   v0,l33
800B8454	mtc2   a0,gbk
800B8458	mtc2   v1,rbk
800B845C	nop
800B8460	nop
800B8464	gte_func26zero,r11r12
800B8468	sw     v0, $fff0(t2)
800B846C	sw     v1, $fff8(t2)
800B8470	sw     a0, $0000(t2)
800B8474	mfc2   v0,ofx
800B8478	nop
800B847C	blez   v0, Lb84b4 [$800b84b4]
800B8480	nop
800B8484	lh     v0, $000c(a3)
800B8488	nop
800B848C	bne    v0, zero, Lb84c8 [$800b84c8]
800B8490	nop
800B8494	lh     v0, $000c(a2)
800B8498	nop
800B849C	bne    v0, zero, Lb84c8 [$800b84c8]
800B84A0	nop
800B84A4	lh     v0, $000c(a1)
800B84A8	nop
800B84AC	bne    v0, zero, Lb84c8 [$800b84c8]
800B84B0	nop

Lb84b4:	; 800B84B4
800B84B4	lw     v0, $0000(t0)
800B84B8	nop
800B84BC	and    v0, v0, t5
800B84C0	j      Lb8528 [$800b8528]
800B84C4	sw     v0, $0000(t0)

Lb84c8:	; 800B84C8
800B84C8	lw     a3, $0004(a3)
800B84CC	lw     a2, $0004(a2)
800B84D0	lw     a1, $0004(a1)
800B84D4	mtc2   a3,lr3lg1
800B84D8	mtc2   a2,lg2lg3
800B84DC	mtc2   a1,lb1lb2
800B84E0	nop
800B84E4	nop
800B84E8	gte_func26t8,r11r12
800B84EC	mfc2   a0,trz
800B84F0	nop
800B84F4	sll    a0, a0, $02
800B84F8	addu   a0, a0, s0
800B84FC	lw     v1, $0000(t3)
800B8500	lw     v0, $0000(a0)
800B8504	and    v1, v1, t5
800B8508	and    v0, v0, t4
800B850C	or     v1, v1, v0
800B8510	sw     v1, $0000(t3)
800B8514	lw     v0, $0000(a0)
800B8518	and    v1, t3, t4
800B851C	and    v0, v0, t5
800B8520	or     v0, v0, v1
800B8524	sw     v0, $0000(a0)

Lb8528:	; 800B8528
800B8528	addiu  t1, t1, $0001
800B852C	addiu  t2, t2, $001c
800B8530	addiu  t0, t0, $001c
800B8534	sltu   v0, t1, t9
800B8538	bne    v0, zero, loopb8418 [$800b8418]
800B853C	addiu  t8, t8, $0010

Lb8540:	; 800B8540
800B8540	srl    t9, s2, $18
800B8544	beq    t9, zero, Lb86bc [$800b86bc]
800B8548	addu   t1, zero, zero
800B854C	lui    s1, $ff00
800B8550	lui    t6, $00ff
800B8554	ori    t6, t6, $ffff
800B8558	addiu  t4, t0, $0020

loopb855c:	; 800B855C
800B855C	lw     v1, $0000(t8)
800B8560	addu   t5, t0, zero
800B8564	andi   v0, v1, $00ff
800B8568	sll    v0, v0, $04
800B856C	addu   t2, t7, v0
800B8570	andi   v0, v1, $ff00
800B8574	srl    v0, v0, $04
800B8578	addu   a3, t7, v0
800B857C	srl    v0, v1, $0c
800B8580	andi   v0, v0, $0ff0
800B8584	addu   a2, t7, v0
800B8588	srl    v1, v1, $18
800B858C	sll    v1, v1, $04
800B8590	addu   t3, t7, v1
800B8594	lw     v0, $0000(t2)
800B8598	lw     v1, $0000(a3)
800B859C	lw     a0, $0000(a2)
800B85A0	lw     a1, $0000(t3)
800B85A4	mtc2   v0,l33
800B85A8	mtc2   a0,gbk
800B85AC	mtc2   v1,rbk
800B85B0	nop
800B85B4	nop
800B85B8	gte_func26zero,r11r12
800B85BC	sw     v0, $ffe8(t4)
800B85C0	sw     v1, $fff0(t4)
800B85C4	sw     a0, $fff8(t4)
800B85C8	sw     a1, $0000(t4)
800B85CC	mfc2   v0,ofx
800B85D0	nop
800B85D4	blez   v0, Lb860c [$800b860c]
800B85D8	nop
800B85DC	lh     v0, $000c(t2)
800B85E0	nop
800B85E4	bne    v0, zero, Lb8620 [$800b8620]
800B85E8	nop
800B85EC	lh     v0, $000c(a3)
800B85F0	nop
800B85F4	bne    v0, zero, Lb8620 [$800b8620]
800B85F8	nop
800B85FC	lh     v0, $000c(a2)
800B8600	nop
800B8604	bne    v0, zero, Lb8620 [$800b8620]
800B8608	nop

Lb860c:	; 800B860C
800B860C	lw     v0, $0000(t0)
800B8610	nop
800B8614	and    v0, v0, s1
800B8618	j      Lb86a4 [$800b86a4]
800B861C	sw     v0, $0000(t0)

Lb8620:	; 800B8620
800B8620	lw     v0, $0004(t2)
800B8624	lw     v1, $0004(a3)
800B8628	nop
800B862C	addu   v0, v0, v1
800B8630	lw     v1, $0004(a2)
800B8634	lw     a0, $0004(t3)
800B8638	addu   v0, v0, v1
800B863C	addu   v0, v0, a0
800B8640	srl    v0, v0, $04
800B8644	sll    v0, v0, $02
800B8648	addu   v0, v0, s0
800B864C	lw     v1, $0000(t5)
800B8650	lw     v0, $0000(v0)
800B8654	and    v1, v1, s1
800B8658	and    v0, v0, t6
800B865C	or     v1, v1, v0
800B8660	sw     v1, $0000(t5)
800B8664	lw     v1, $0004(t2)
800B8668	lw     v0, $0004(a3)
800B866C	nop
800B8670	addu   v1, v1, v0
800B8674	lw     v0, $0004(a2)
800B8678	lw     a0, $0004(t3)
800B867C	addu   v1, v1, v0
800B8680	addu   v1, v1, a0
800B8684	srl    v1, v1, $04
800B8688	sll    v1, v1, $02
800B868C	addu   v1, v1, s0
800B8690	lw     v0, $0000(v1)
800B8694	and    a0, t5, t6
800B8698	and    v0, v0, s1
800B869C	or     v0, v0, a0
800B86A0	sw     v0, $0000(v1)

Lb86a4:	; 800B86A4
800B86A4	addiu  t1, t1, $0001
800B86A8	addiu  t4, t4, $0024
800B86AC	addiu  t0, t0, $0024
800B86B0	sltu   v0, t1, t9
800B86B4	bne    v0, zero, loopb855c [$800b855c]
800B86B8	addiu  t8, t8, $0014

Lb86bc:	; 800B86BC
800B86BC	lw     s3, $005c(sp)
800B86C0	lw     s2, $0058(sp)
800B86C4	lw     s1, $0054(sp)
800B86C8	lw     s0, $0050(sp)
800B86CC	addiu  sp, sp, $0060
800B86D0	jr     ra 
800B86D4	nop



////////////////////////////////
// kawai_action_b
800B86D8-800B8CEC
////////////////////////////////



////////////////////////////////
// funcb8cf0
800B8CF0-800B9B08
////////////////////////////////



////////////////////////////////
// kawai_action_d
800B9B0C-800BA530
////////////////////////////////



funcba534:	; 800BA534
800BA534	addiu  sp, sp, $ffe8 (=-$18)
800BA538	sw     s0, $0010(sp)
800BA53C	addu   s0, a2, zero
800BA540	sw     ra, $0014(sp)
800BA544	lh     v0, $006a(a0)
800BA548	ori    v1, zero, $0001
800BA54C	lui    at, $800a
800BA550	sw     a0, $c6e0(at)
800BA554	lui    at, $800a
800BA558	sw     a1, $c544(at)
800BA55C	lui    at, $800a
800BA560	sw     s0, $c6dc(at)
800BA564	lui    at, $8009
800BA568	sb     zero, $5dcc(at)
800BA56C	lui    at, $8008
800BA570	sb     v1, $ebe0(at)
800BA574	lui    at, $800a
800BA578	sb     zero, $fe8c(at)
800BA57C	andi   v0, v0, $0100
800BA580	beq    v0, zero, Lba598 [$800ba598]
800BA584	ori    v0, zero, $0004
800BA588	lui    at, $8009
800BA58C	sb     v1, $5dcc(at)
800BA590	lui    at, $800a
800BA594	sb     v0, $9ffc(at)

Lba598:	; 800BA598
800BA598	lbu    v0, $0000(s0)
800BA59C	nop
800BA5A0	sltiu  v0, v0, $0002
800BA5A4	beq    v0, zero, Lba5b4 [$800ba5b4]
800BA5A8	ori    a0, zero, $004b
800BA5AC	jal    func429e0 [$800429e0]
800BA5B0	ori    a1, zero, $000a

Lba5b4:	; 800BA5B4
800BA5B4	lbu    v0, $0000(s0)
800BA5B8	nop
800BA5BC	sltiu  v0, v0, $0003
800BA5C0	beq    v0, zero, Lba5dc [$800ba5dc]
800BA5C4	ori    a0, zero, $004b
800BA5C8	lbu    v0, $0001(s0)
800BA5CC	nop
800BA5D0	sltiu  v0, v0, $0006
800BA5D4	bne    v0, zero, Lba5e4 [$800ba5e4]
800BA5D8	nop

Lba5dc:	; 800BA5DC
800BA5DC	jal    func429e0 [$800429e0]
800BA5E0	ori    a1, zero, $000c

Lba5e4:	; 800BA5E4
800BA5E4	lbu    v0, $0001(s0)
800BA5E8	nop
800BA5EC	sltiu  v0, v0, $0005
800BA5F0	beq    v0, zero, Lba600 [$800ba600]
800BA5F4	ori    a0, zero, $004b
800BA5F8	jal    func429e0 [$800429e0]
800BA5FC	ori    a1, zero, $000b

Lba600:	; 800BA600
800BA600	jal    funcd48c0 [$800d48c0]
800BA604	nop
800BA608	jal    funcba7c4 [$800ba7c4]
800BA60C	nop
800BA610	jal    funcbaf54 [$800baf54]
800BA614	nop
800BA618	lui    v0, $8007
800BA61C	lbu    v0, $16d4(v0)
800BA620	nop
800BA624	bne    v0, zero, Lba648 [$800ba648]
800BA628	nop
800BA62C	jal    clear_akao [$800c46a4]
800BA630	nop
800BA634	ori    v0, zero, $00f2
800BA638	lui    at, $800a
800BA63C	sh     v0, $a000(at)
800BA640	jal    system_execute_AKAO [$8002da7c]
800BA644	nop

Lba648:	; 800BA648
800BA648	lw     ra, $0014(sp)
800BA64C	lw     s0, $0010(sp)
800BA650	addiu  sp, sp, $0018
800BA654	jr     ra 
800BA658	nop



////////////////////////////////
// funcba65c
800BA65C-800BA7C0
////////////////////////////////



funcba7c4:	; 800BA7C4
800BA7C4	lui    v0, $800a
800BA7C8	lw     v0, $c6e0(v0)
800BA7CC	nop
800BA7D0	sb     zero, $0001(v0)
800BA7D4	lui    v1, $800a
800BA7D8	lw     v1, $c6e0(v1)
800BA7DC	lui    v0, $800a
800BA7E0	lw     v0, $c6dc(v0)
800BA7E4	sh     zero, $0002(v1)
800BA7E8	sh     zero, $0026(v1)
800BA7EC	lbu    a1, $0003(v0)
800BA7F0	sb     zero, $0032(v1)
800BA7F4	lui    a0, $800a
800BA7F8	lw     a0, $c6e0(a0)
800BA7FC	ori    v0, zero, $0001
800BA800	sh     v0, $002e(v1)
800BA804	ori    v0, zero, $0002
800BA808	sh     zero, $002a(v1)
800BA80C	sh     zero, $002c(v1)
800BA810	sh     v0, $0030(v1)
800BA814	lui    at, $8008
800BA818	sb     zero, $1dc4(at)
800BA81C	sh     a1, $0028(v1)
800BA820	sb     zero, $0033(a0)
800BA824	lui    v0, $800a
800BA828	lw     v0, $c6e0(v0)
800BA82C	nop
800BA830	sb     zero, $0034(v0)
800BA834	lui    v0, $800a
800BA838	lw     v0, $c6e0(v0)
800BA83C	nop
800BA840	sb     zero, $0035(v0)
800BA844	lui    v0, $800a
800BA848	lw     v0, $c6e0(v0)
800BA84C	nop
800BA850	sb     zero, $003b(v0)
800BA854	lui    v0, $800a
800BA858	lw     v0, $c6e0(v0)
800BA85C	nop
800BA860	sb     zero, $0036(v0)
800BA864	lui    v0, $800a
800BA868	lw     v0, $c6e0(v0)
800BA86C	nop
800BA870	sb     zero, $0037(v0)
800BA874	lui    v0, $800a
800BA878	lw     v0, $c6e0(v0)
800BA87C	nop
800BA880	sb     zero, $003d(v0)
800BA884	lui    v1, $800a
800BA888	lw     v1, $c6e0(v1)
800BA88C	sw     zero, $0048(v0)
800BA890	sw     zero, $0044(v0)
800BA894	sh     zero, $0040(v0)
800BA898	sh     zero, $003e(v0)
800BA89C	sb     zero, $003c(v1)
800BA8A0	lui    v0, $800a
800BA8A4	lw     v0, $c6e0(v0)
800BA8A8	nop
800BA8AC	sb     zero, $0012(v0)
800BA8B0	lui    v0, $800a
800BA8B4	lw     v0, $c6e0(v0)
800BA8B8	nop
800BA8BC	sb     zero, $0013(v0)
800BA8C0	lui    v0, $800a
800BA8C4	lw     v0, $c6e0(v0)
800BA8C8	nop
800BA8CC	sb     zero, $0014(v0)
800BA8D0	lui    v0, $800a
800BA8D4	lw     v0, $c6e0(v0)
800BA8D8	nop
800BA8DC	sb     zero, $008a(v0)
800BA8E0	lui    v1, $800a
800BA8E4	lw     v1, $c6e0(v1)
800BA8E8	sh     zero, $0018(v0)
800BA8EC	sh     zero, $001a(v0)
800BA8F0	sb     zero, $0098(v1)
800BA8F4	lui    v0, $800a
800BA8F8	lw     v0, $c6e0(v0)
800BA8FC	nop
800BA900	sb     zero, $008b(v0)
800BA904	lui    v0, $800a
800BA908	lw     v0, $c6e0(v0)
800BA90C	nop
800BA910	sb     zero, $0099(v0)
800BA914	lui    v0, $800a
800BA918	lw     v0, $c6e0(v0)
800BA91C	addiu  sp, sp, $ffe8 (=-$18)
800BA920	sb     zero, $003a(v0)
800BA924	lui    v1, $800a
800BA928	lw     v1, $c6e0(v1)
800BA92C	ori    a3, zero, $00ff
800BA930	sh     zero, $008e(v0)
800BA934	sh     zero, $009c(v0)
800BA938	sh     zero, $0094(v0)
800BA93C	sh     zero, $00a2(v0)
800BA940	sh     zero, $0096(v0)
800BA944	sh     zero, $00a4(v0)
800BA948	sb     zero, $001d(v1)
800BA94C	lui    v0, $800a
800BA950	lw     v0, $c6dc(v0)
800BA954	lui    v1, $800a
800BA958	lw     v1, $c6e0(v1)
800BA95C	lhu    v0, $0008(v0)
800BA960	lui    a0, $8007
800BA964	addiu  a0, a0, $5f23
800BA968	sh     v0, $0010(v1)

loopba96c:	; 800BA96C
800BA96C	sb     zero, $0000(a0)
800BA970	addiu  a3, a3, $ffff (=-$1)
800BA974	bgez   a3, loopba96c [$800ba96c]
800BA978	addiu  a0, a0, $ffff (=-$1)
800BA97C	addu   a3, zero, zero
800BA980	lui    t8, $8007
800BA984	addiu  t8, t8, $1748
800BA988	lui    t7, $8008
800BA98C	addiu  t7, t7, $33f8
800BA990	lui    t6, $8007
800BA994	addiu  t6, t6, $1a88
800BA998	ori    t5, zero, $00ff

loopba99c:	; 800BA99C
800BA99C	lui    v0, $800a
800BA9A0	lw     v0, $c6dc(v0)
800BA9A4	nop
800BA9A8	lbu    v0, $0002(v0)
800BA9AC	nop
800BA9B0	blez   v0, Lbaa1c [$800baa1c]
800BA9B4	addu   a2, zero, zero
800BA9B8	sll    t4, a3, $01
800BA9BC	lui    t3, $8011
800BA9C0	addiu  t3, t3, $42d4
800BA9C4	addu   t2, t6, zero
800BA9C8	addu   t1, t7, zero
800BA9CC	addu   t0, t8, zero

loopba9d0:	; 800BA9D0
800BA9D0	addu   a1, t3, a3
800BA9D4	addiu  t3, t3, $0008
800BA9D8	addu   a0, t2, a3
800BA9DC	addiu  t2, t2, $0008
800BA9E0	addu   v1, t1, a3
800BA9E4	addiu  t1, t1, $0008
800BA9E8	addu   v0, t4, t0
800BA9EC	sh     zero, $0000(v0)
800BA9F0	sb     zero, $0000(v1)
800BA9F4	sb     t5, $0000(a0)
800BA9F8	sb     zero, $0000(a1)
800BA9FC	lui    v0, $800a
800BAA00	lw     v0, $c6dc(v0)
800BAA04	nop
800BAA08	lbu    v0, $0002(v0)
800BAA0C	addiu  a2, a2, $0001
800BAA10	slt    v0, a2, v0
800BAA14	bne    v0, zero, loopba9d0 [$800ba9d0]
800BAA18	addiu  t0, t0, $0010

Lbaa1c:	; 800BAA1C
800BAA1C	addiu  a3, a3, $0001
800BAA20	slti   v0, a3, $0008
800BAA24	bne    v0, zero, loopba99c [$800ba99c]
800BAA28	nop
800BAA2C	lui    v0, $800a
800BAA30	lw     v0, $c6dc(v0)
800BAA34	nop
800BAA38	lbu    v0, $0002(v0)
800BAA3C	nop
800BAA40	blez   v0, Lbaacc [$800baacc]
800BAA44	addu   a3, zero, zero
800BAA48	ori    a1, zero, $0007
800BAA4C	ori    a0, zero, $00ff
800BAA50	lui    v1, $8007
800BAA54	addiu  v1, v1, $16dc

loopbaa58:	; 800BAA58
800BAA58	lui    at, $800a
800BAA5C	addiu  at, at, $a1c4 (=-$5e3c)
800BAA60	addu   at, at, a3
800BAA64	sb     a1, $0000(at)
800BAA68	lui    at, $8008
800BAA6C	addiu  at, at, $eb98 (=-$1468)
800BAA70	addu   at, at, a3
800BAA74	sb     a0, $0000(at)
800BAA78	sh     zero, $0000(v1)
800BAA7C	lui    at, $8008
800BAA80	addiu  at, at, $1d90
800BAA84	addu   at, at, a3
800BAA88	sb     zero, $0000(at)
800BAA8C	lui    at, $8007
800BAA90	addiu  at, at, $078c
800BAA94	addu   at, at, a3
800BAA98	sb     a0, $0000(at)
800BAA9C	lui    at, $8011
800BAAA0	addiu  at, at, $4498
800BAAA4	addu   at, at, a3
800BAAA8	sb     zero, $0000(at)
800BAAAC	lui    v0, $800a
800BAAB0	lw     v0, $c6dc(v0)
800BAAB4	nop
800BAAB8	lbu    v0, $0002(v0)
800BAABC	addiu  a3, a3, $0001
800BAAC0	slt    v0, a3, v0
800BAAC4	bne    v0, zero, loopbaa58 [$800baa58]
800BAAC8	addiu  v1, v1, $0002

Lbaacc:	; 800BAACC
800BAACC	lui    v0, $800a
800BAAD0	lw     v0, $c6dc(v0)
800BAAD4	nop
800BAAD8	lbu    v0, $0003(v0)
800BAADC	nop
800BAAE0	blez   v0, Lbad6c [$800bad6c]
800BAAE4	addu   a3, zero, zero
800BAAE8	ori    t0, zero, $0010
800BAAEC	addu   a1, zero, zero

Lbaaf0:	; 800BAAF0
800BAAF0	lui    v0, $800a
800BAAF4	lw     v0, $c544(v0)
800BAAF8	nop
800BAAFC	addu   v0, a1, v0
800BAB00	sb     zero, $0036(v0)
800BAB04	lui    v1, $800a
800BAB08	lw     v1, $c544(v1)
800BAB0C	sh     zero, $0066(v0)
800BAB10	sw     zero, $000c(v0)
800BAB14	sw     zero, $0010(v0)
800BAB18	sw     zero, $0014(v0)
800BAB1C	sh     zero, $0072(v0)
800BAB20	sh     zero, $0074(v0)
800BAB24	addu   v1, a1, v1
800BAB28	sb     zero, $0038(v1)
800BAB2C	lui    v0, $800a
800BAB30	lw     v0, $c544(v0)
800BAB34	nop
800BAB38	addu   v0, a1, v0
800BAB3C	sb     zero, $003b(v0)
800BAB40	lui    v0, $800a
800BAB44	lw     v0, $c544(v0)
800BAB48	nop
800BAB4C	addu   v0, a1, v0
800BAB50	sb     zero, $0039(v0)
800BAB54	lui    v0, $800a
800BAB58	lw     v0, $c544(v0)
800BAB5C	nop
800BAB60	addu   v0, a1, v0
800BAB64	sb     zero, $003a(v0)
800BAB68	lui    v0, $800a
800BAB6C	lw     v0, $c544(v0)
800BAB70	nop
800BAB74	addu   v0, a1, v0
800BAB78	sb     zero, $0056(v0)
800BAB7C	lui    v1, $800a
800BAB80	lw     v1, $c544(v1)
800BAB84	sh     zero, $003c(v0)
800BAB88	sh     zero, $003e(v0)
800BAB8C	sh     zero, $0040(v0)
800BAB90	sh     zero, $0046(v0)
800BAB94	sh     zero, $004c(v0)
800BAB98	sh     zero, $0042(v0)
800BAB9C	sh     zero, $0048(v0)
800BABA0	sh     zero, $004e(v0)
800BABA4	sh     zero, $0044(v0)
800BABA8	sh     zero, $004a(v0)
800BABAC	sh     zero, $0050(v0)
800BABB0	sh     zero, $0052(v0)
800BABB4	sh     zero, $0054(v0)
800BABB8	addu   v1, a1, v1
800BABBC	sb     zero, $005e(v1)
800BABC0	lui    v0, $800a
800BABC4	lw     v0, $c544(v0)
800BABC8	nop
800BABCC	addu   v0, a1, v0
800BABD0	sh     t0, $0060(v0)
800BABD4	sb     zero, $005c(v0)
800BABD8	lui    v1, $800a
800BABDC	lw     v1, $c6e0(v1)
800BABE0	sw     zero, $0078(v0)
800BABE4	sw     zero, $007c(v0)
800BABE8	sw     zero, $0080(v0)
800BABEC	sh     zero, $0062(v0)
800BABF0	sh     zero, $0064(v0)
800BABF4	lui    v0, $800a
800BABF8	lw     v0, $c544(v0)
800BABFC	lh     a0, $0010(v1)
800BAC00	addu   v0, a1, v0
800BAC04	sb     zero, $005d(v0)
800BAC08	lui    v1, $800a
800BAC0C	lw     v1, $c544(v1)
800BAC10	sll    a0, a0, $01
800BAC14	addu   v1, a1, v1
800BAC18	sh     a0, $0070(v0)
800BAC1C	sb     zero, $005a(v1)
800BAC20	lui    v0, $800a
800BAC24	lw     v0, $c544(v0)
800BAC28	sh     zero, $0068(v1)
800BAC2C	sh     zero, $006a(v1)
800BAC30	addu   v0, a1, v0
800BAC34	sb     zero, $0058(v0)
800BAC38	lui    v0, $800a
800BAC3C	lw     v0, $c544(v0)
800BAC40	nop
800BAC44	addu   v0, a1, v0
800BAC48	sb     zero, $0059(v0)
800BAC4C	lui    v0, $800a
800BAC50	lw     v0, $c544(v0)
800BAC54	nop
800BAC58	addu   v0, a1, v0
800BAC5C	sb     zero, $005b(v0)
800BAC60	lui    v0, $800a
800BAC64	lw     v0, $c544(v0)
800BAC68	nop
800BAC6C	addu   v0, a1, v0
800BAC70	sb     zero, $0037(v0)
800BAC74	lui    a0, $800a
800BAC78	lw     a0, $c6e0(a0)
800BAC7C	nop
800BAC80	lh     v1, $0010(a0)
800BAC84	nop
800BAC88	sll    v0, v1, $04
800BAC8C	subu   v0, v0, v1
800BAC90	lui    v1, $800a
800BAC94	lw     v1, $c544(v1)
800BAC98	sll    v0, v0, $01
800BAC9C	addu   v1, a1, v1
800BACA0	bgez   v0, Lbacac [$800bacac]
800BACA4	addu   a2, v1, zero
800BACA8	addiu  v0, v0, $01ff

Lbacac:	; 800BACAC
800BACAC	sra    v0, v0, $09
800BACB0	sh     v0, $006c(v1)
800BACB4	lh     v1, $0010(a0)
800BACB8	nop
800BACBC	sll    v0, v1, $02
800BACC0	addu   v0, v0, v1
800BACC4	sll    v0, v0, $04
800BACC8	bgez   v0, Lbacd4 [$800bacd4]
800BACCC	nop
800BACD0	addiu  v0, v0, $01ff

Lbacd4:	; 800BACD4
800BACD4	sra    v0, v0, $09
800BACD8	sh     v0, $006e(a2)
800BACDC	lui    at, $8008
800BACE0	addiu  at, at, $325c
800BACE4	addu   at, at, a3
800BACE8	sb     zero, $0000(at)
800BACEC	lui    at, $8007
800BACF0	addiu  at, at, $56e8
800BACF4	addu   at, at, a3
800BACF8	sb     zero, $0000(at)
800BACFC	lui    v1, $800a
800BAD00	lw     v1, $c544(v1)
800BAD04	sll    v0, a3, $01
800BAD08	lui    at, $800a
800BAD0C	addiu  at, at, $d828 (=-$27d8)
800BAD10	addu   at, at, v0
800BAD14	sh     t0, $0000(at)
800BAD18	lui    at, $8008
800BAD1C	addiu  at, at, $2248
800BAD20	addu   at, at, v0
800BAD24	sh     t0, $0000(at)
800BAD28	addu   v1, a1, v1
800BAD2C	sb     zero, $0008(v1)
800BAD30	lui    v0, $800a
800BAD34	lw     v0, $c544(v0)
800BAD38	sh     zero, $0000(v1)
800BAD3C	sh     zero, $0002(v1)
800BAD40	sw     zero, $0004(v1)
800BAD44	addu   v0, a1, v0
800BAD48	sb     zero, $0009(v0)
800BAD4C	lui    v0, $800a
800BAD50	lw     v0, $c6dc(v0)
800BAD54	addiu  a3, a3, $0001
800BAD58	lbu    v0, $0003(v0)
800BAD5C	nop
800BAD60	slt    v0, a3, v0
800BAD64	bne    v0, zero, Lbaaf0 [$800baaf0]
800BAD68	addiu  a1, a1, $0084

Lbad6c:	; 800BAD6C
800BAD6C	addu   a3, zero, zero

loopbad70:	; 800BAD70
800BAD70	lui    v0, $800a
800BAD74	lw     v0, $c6e0(v0)
800BAD78	nop
800BAD7C	addu   v0, v0, a3
800BAD80	addiu  a3, a3, $0001
800BAD84	sb     zero, $00f2(v0)
800BAD88	slti   v0, a3, $0040
800BAD8C	bne    v0, zero, loopbad70 [$800bad70]
800BAD90	nop
800BAD94	addu   a3, zero, zero

loopbad98:	; 800BAD98
800BAD98	lui    v0, $800a
800BAD9C	lw     v0, $c6e0(v0)
800BADA0	nop
800BADA4	addu   v0, v0, a3
800BADA8	addiu  a3, a3, $0001
800BADAC	sb     zero, $00b2(v0)
800BADB0	slti   v0, a3, $0040
800BADB4	bne    v0, zero, loopbad98 [$800bad98]

A3 = 0;
loopbadc8:	; 800BADC8
    A2 = f;
    V0 = 80095de0 + A3 * 20 + 1e;

    loopbadd0:	; 800BADD0
        [V0] = h(0); // reset clut store array
        V0 = V0 - 2;
        A2 = A2 - 1;
    800BADD8	bgez   a2, loopbadd0 [$800badd0]

    A3 = A3 + 1;
    V0 = A3 < 40;
800BADE8	bne    v0, zero, loopbadc8 [$800badc8]

800BADF0	addu   a3, zero, zero
800BADF4	addu   v1, zero, zero

loopbadf8:	; 800BADF8
800BADF8	lui    at, $8008
800BADFC	addiu  at, at, $e7bd (=-$1843)
800BAE00	addu   at, at, v1
800BAE04	sb     zero, $0000(at)
800BAE08	lui    at, $8008
800BAE0C	addiu  at, at, $e7bc (=-$1844)
800BAE10	addu   at, at, v1
800BAE14	sb     zero, $0000(at)
800BAE18	lui    at, $8008
800BAE1C	addiu  at, at, $e7bb (=-$1845)
800BAE20	addu   at, at, v1
800BAE24	sb     zero, $0000(at)
800BAE28	lui    at, $8008
800BAE2C	addiu  at, at, $e7ba (=-$1846)
800BAE30	addu   at, at, v1
800BAE34	sb     zero, $0000(at)
800BAE38	lui    at, $8008
800BAE3C	addiu  at, at, $e7be (=-$1842)
800BAE40	addu   at, at, v1
800BAE44	sb     zero, $0000(at)
800BAE48	lui    at, $8008
800BAE4C	addiu  at, at, $e7bf (=-$1841)
800BAE50	addu   at, at, v1
800BAE54	sb     zero, $0000(at)
800BAE58	lui    at, $8008
800BAE5C	addiu  at, at, $e7b8 (=-$1848)
800BAE60	addu   at, at, v1
800BAE64	sb     zero, $0000(at)
800BAE68	lui    at, $8008
800BAE6C	addiu  at, at, $e7b9 (=-$1847)
800BAE70	addu   at, at, v1
800BAE74	sb     zero, $0000(at)
800BAE78	lui    at, $8008
800BAE7C	addiu  at, at, $e7c2 (=-$183e)
800BAE80	addu   at, at, v1
800BAE84	sb     zero, $0000(at)
800BAE88	lui    at, $8008
800BAE8C	addiu  at, at, $e7ac (=-$1854)
800BAE90	addu   at, at, v1
800BAE94	sh     zero, $0000(at)
800BAE98	lui    at, $8008
800BAE9C	addiu  at, at, $e7ae (=-$1852)
800BAEA0	addu   at, at, v1
800BAEA4	sh     zero, $0000(at)
800BAEA8	lui    at, $8008
800BAEAC	addiu  at, at, $e7b0 (=-$1850)
800BAEB0	addu   at, at, v1
800BAEB4	sh     zero, $0000(at)
800BAEB8	lui    at, $8008
800BAEBC	addiu  at, at, $e7b2 (=-$184e)
800BAEC0	addu   at, at, v1
800BAEC4	sh     zero, $0000(at)
800BAEC8	lui    at, $8008
800BAECC	addiu  at, at, $e7b4 (=-$184c)
800BAED0	addu   at, at, v1
800BAED4	sh     zero, $0000(at)
800BAED8	lui    at, $8008
800BAEDC	addiu  at, at, $e7b6 (=-$184a)
800BAEE0	addu   at, at, v1
800BAEE4	sh     zero, $0000(at)
800BAEE8	addiu  a3, a3, $0001
800BAEEC	slti   v0, a3, $0020
800BAEF0	bne    v0, zero, loopbadf8 [$800badf8]
800BAEF4	addiu  v1, v1, $0018
800BAEF8	lui    at, $8009
800BAEFC	sh     zero, $5d84(at)
800BAF00	ori    v1, zero, $00ff
800BAF04	ori    a3, zero, $0008
800BAF08	lui    v0, $800a
800BAF0C	addiu  v0, v0, $ad38 (=-$52c8)

loopbaf10:	; 800BAF10
800BAF10	sb     v1, $0000(v0)
800BAF14	addiu  a3, a3, $ffff (=-$1)
800BAF18	bgez   a3, loopbaf10 [$800baf10]
800BAF1C	addiu  v0, v0, $ffff (=-$1)
800BAF20	lui    a0, $800a
800BAF24	addiu  a0, a0, $d2a7 (=-$2d59)
800BAF28	lbu    v1, $0000(a0)
800BAF2C	ori    v0, zero, $00ff
800BAF30	lui    at, $800e
800BAF34	sb     v0, $48f0(at)
800BAF38	lui    at, $8007
800BAF3C	sb     zero, $1c1c(at)
800BAF40	ori    v1, v1, $0003
800BAF44	sb     v1, $0000(a0)
800BAF48	addiu  sp, sp, $0018
800BAF4C	jr     ra 
800BAF50	nop


funcbaf54:	; 800BAF54
800BAF54	lui    v0, $800a
800BAF58	lw     v0, $c6dc(v0)
800BAF5C	addiu  sp, sp, $ffd8 (=-$28)
800BAF60	sw     ra, $0020(sp)
800BAF64	sw     s3, $001c(sp)
800BAF68	sw     s2, $0018(sp)
800BAF6C	sw     s1, $0014(sp)
800BAF70	sw     s0, $0010(sp)
800BAF74	lui    at, $800a
800BAF78	sb     zero, $c6c4(at)
800BAF7C	lui    at, $8007
800BAF80	sb     zero, $22c4(at)
800BAF84	lbu    v0, $0002(v0)
800BAF88	nop
800BAF8C	beq    v0, zero, Lbb194 [$800bb194]
800BAF90	nop
800BAF94	lui    s1, $800e
800BAF98	addiu  s1, s1, $4254
800BAF9C	lui    s2, $8008
800BAFA0	addiu  s2, s2, $31fc
800BAFA4	lui    s3, $800e
800BAFA8	addiu  s3, s3, $0228

Lbafac:	; 800BAFAC
800BAFAC	lui    v0, $8007
800BAFB0	lbu    v0, $1e24(v0)
800BAFB4	nop
800BAFB8	andi   v0, v0, $0003
800BAFBC	beq    v0, zero, Lbb03c [$800bb03c]
800BAFC0	nop
800BAFC4	lui    a1, $800e
800BAFC8	addiu  a1, a1, $0628
800BAFCC	jal    funcda334 [$800da334]
800BAFD0	addu   a0, s1, zero
800BAFD4	addu   a0, s1, zero
800BAFD8	lui    a1, $8007
800BAFDC	lbu    a1, $22c4(a1)
800BAFE0	lui    v0, $800a
800BAFE4	lw     v0, $c6dc(v0)
800BAFE8	sll    a1, a1, $03
800BAFEC	addiu  a1, a1, $0020
800BAFF0	jal    funcda368 [$800da368]
800BAFF4	addu   a1, a1, v0
800BAFF8	lui    v0, $8007
800BAFFC	lbu    v0, $1e24(v0)
800BB000	nop
800BB004	andi   v0, v0, $0001
800BB008	beq    v0, zero, Lbb01c [$800bb01c]
800BB00C	ori    a0, zero, $0004
800BB010	addu   a1, zero, zero
800BB014	jal    funcda124 [$800da124]
800BB018	addu   a2, s1, zero

Lbb01c:	; 800BB01C
800BB01C	lui    v0, $8007
800BB020	lbu    v0, $1e24(v0)
800BB024	nop
800BB028	andi   v0, v0, $0002
800BB02C	beq    v0, zero, Lbb03c [$800bb03c]
800BB030	nop
800BB034	jal    funcd4840 [$800d4840]
800BB038	addu   a0, s1, zero

Lbb03c:	; 800BB03C
800BB03C	lui    v1, $8007
800BB040	lbu    v1, $22c4(v1)
800BB044	lui    a0, $800a
800BB048	lw     a0, $c6dc(a0)
800BB04C	sll    a3, v1, $01
800BB050	sll    v1, v1, $06
800BB054	lhu    a2, $0006(a0)
800BB058	lbu    v0, $0002(a0)
800BB05C	sll    a2, a2, $12
800BB060	sra    a2, a2, $10
800BB064	sll    v0, v0, $03
800BB068	addu   v0, v1, v0
800BB06C	addu   v0, v0, a2
800BB070	addu   v0, v0, a0
800BB074	lbu    a1, $0020(v0)
800BB078	addu   a3, a3, s2
800BB07C	sh     a1, $0000(a3)
800BB080	lbu    v0, $0002(a0)
800BB084	nop
800BB088	sll    v0, v0, $03
800BB08C	addu   v1, v1, v0
800BB090	addu   v1, v1, a0
800BB094	addu   v1, v1, a2
800BB098	lbu    v0, $0021(v1)
800BB09C	nop
800BB0A0	sll    v0, v0, $08
800BB0A4	or     a1, a1, v0
800BB0A8	sh     a1, $0000(a3)
800BB0AC	lhu    v0, $0000(a3)
800BB0B0	nop
800BB0B4	addu   a0, a0, v0
800BB0B8	lbu    v0, $0000(a0)
800BB0BC	nop
800BB0C0	lui    at, $800a
800BB0C4	sb     v0, $a058(at)
800BB0C8	beq    v0, zero, Lbb13c [$800bb13c]
800BB0CC	nop
800BB0D0	lui    s0, $8008
800BB0D4	addiu  s0, s0, $31fc

loopbb0d8:	; 800BB0D8
800BB0D8	lui    v0, $800a
800BB0DC	lbu    v0, $a058(v0)
800BB0E0	nop
800BB0E4	sll    v0, v0, $02
800BB0E8	addu   v0, v0, s3
800BB0EC	lw     v0, $0000(v0)
800BB0F0	nop
800BB0F4	jalr   v0 ra
800BB0F8	nop
800BB0FC	lui    v0, $8007
800BB100	lbu    v0, $22c4(v0)
800BB104	nop
800BB108	sll    v0, v0, $01
800BB10C	addu   v0, v0, s0
800BB110	lhu    v1, $0000(v0)
800BB114	lui    v0, $800a
800BB118	lw     v0, $c6dc(v0)
800BB11C	nop
800BB120	addu   v0, v0, v1
800BB124	lbu    v0, $0000(v0)
800BB128	nop
800BB12C	lui    at, $800a
800BB130	sb     v0, $a058(at)
800BB134	bne    v0, zero, loopbb0d8 [$800bb0d8]
800BB138	nop

Lbb13c:	; 800BB13C
800BB13C	lui    v0, $8007
800BB140	lbu    v0, $22c4(v0)
800BB144	nop
800BB148	sll    a0, v0, $01
800BB14C	addu   a0, a0, s2
800BB150	lhu    v1, $0000(a0)
800BB154	addiu  v0, v0, $0001
800BB158	lui    at, $8007
800BB15C	sb     v0, $22c4(at)
800BB160	addiu  v1, v1, $0001
800BB164	sh     v1, $0000(a0)
800BB168	lui    v1, $800a
800BB16C	lw     v1, $c6dc(v1)
800BB170	lui    v0, $8007
800BB174	lbu    v0, $22c4(v0)
800BB178	lbu    v1, $0002(v1)
800BB17C	nop
800BB180	sltu   v0, v0, v1
800BB184	bne    v0, zero, Lbafac [$800bafac]
800BB188	nop
800BB18C	lui    at, $8007
800BB190	sb     zero, $22c4(at)

Lbb194:	; 800BB194
800BB194	lw     ra, $0020(sp)
800BB198	lw     s3, $001c(sp)
800BB19C	lw     s2, $0018(sp)
800BB1A0	lw     s1, $0014(sp)
800BB1A4	lw     s0, $0010(sp)
800BB1A8	addiu  sp, sp, $0028
800BB1AC	jr     ra 
800BB1B0	nop



////////////////////////////////////////////////////////
funcbb1b4:	; 800BB1B4
800BB1B4	addu   a2, zero, zero
800BB1B8	ori    a1, zero, $00ff
800BB1BC	ori    a3, zero, $0001
800BB1C0	sll    v0, a2, $10

loopbb1c4:	; 800BB1C4
800BB1C4	sra    v0, v0, $10
800BB1C8	lui    at, $800a
800BB1CC	addiu  at, at, $d391 (=-$2c6f)
800BB1D0	addu   at, at, v0
800BB1D4	lbu    v0, $0000(at)
800BB1D8	nop
800BB1DC	beq    v0, a1, Lbb250 [$800bb250]
800BB1E0	nop
800BB1E4	lui    at, $800a
800BB1E8	addiu  at, at, $ad30 (=-$52d0)
800BB1EC	addu   at, at, v0
800BB1F0	lbu    v0, $0000(at)
800BB1F4	nop
800BB1F8	beq    v0, a1, Lbb250 [$800bb250]
800BB1FC	nop
800BB200	lui    at, $8008
800BB204	addiu  at, at, $eb98 (=-$1468)
800BB208	addu   at, at, v0
800BB20C	lbu    a0, $0000(at)
800BB210	nop
800BB214	beq    a0, a1, Lbb254 [$800bb254]
800BB218	addiu  v0, a2, $0001
800BB21C	lui    v0, $8008
800BB220	lw     v0, $e770(v0)
800BB224	nop
800BB228	lhu    v0, $0002(v0)
800BB22C	nop
800BB230	slt    v0, a0, v0
800BB234	beq    v0, zero, Lbb254 [$800bb254]
800BB238	addiu  v0, a2, $0001
800BB23C	lui    v1, $8008
800BB240	lw     v1, $357c(v1)
800BB244	sll    v0, a0, $03
800BB248	addu   v0, v0, v1
800BB24C	sb     a3, $0005(v0)

Lbb250:	; 800BB250
800BB250	addiu  v0, a2, $0001

Lbb254:	; 800BB254
800BB254	addu   a2, v0, zero
800BB258	sll    v0, v0, $10
800BB25C	sra    v0, v0, $10
800BB260	slti   v0, v0, $0003
800BB264	bne    v0, zero, loopbb1c4 [$800bb1c4]
800BB268	sll    v0, a2, $10
800BB26C	lui    v0, $8008
800BB270	lw     v0, $e770(v0)
800BB274	nop
800BB278	lhu    v0, $0002(v0)
800BB27C	nop
800BB280	beq    v0, zero, Lbb3a0 [$800bb3a0]
800BB284	addu   a2, zero, zero
800BB288	ori    t1, zero, $00ff
800BB28C	ori    t0, zero, $0001
800BB290	sll    v0, a2, $10

loopbb294:	; 800BB294
A0 = V0 >> 10;
V1 = w[8008357C];
V0 = A0 * 8;
V0 = V0 + V1;
V1 = bu[V0 + 5];
if (V1 == 0)
{
    V0 = w[8009C6DC]; // field file offset
    V0 = bu[V0 + 2];
    if (V1 < V0)
    {
        A1 = 0;
        A3 = A0;
        800BB2DC	sll    v0, a1, $10

        loopbb2e0:	; 800BB2E0
        800BB2E0	sra    v0, v0, $10
        A0 = bu[8007EB98 + V0];
        if (A0 == A3)
        {
            V1 = A0 * 84;
            [8007EB98 + V0] = b(T1);
            V0 = w[8009C544];
            [V1 + V0 + 5C] = b(0);
            [V1 + V0 + 59] = b(T0);
            [V1 + V0 + 5B] = b(T0);
        }
        Lbb350:	; 800BB350
        800BB350	addiu  v0, a1, $0001
        800BB354	addu   a1, v0, zero
        800BB358	lui    v1, $800a
        800BB35C	lw     v1, $c6dc(v1)
        800BB360	sll    v0, v0, $10
        800BB364	lbu    v1, $0002(v1)
        800BB368	sra    v0, v0, $10
        800BB36C	slt    v0, v0, v1
        800BB370	bne    v0, zero, loopbb2e0 [$800bb2e0]
        800BB374	sll    v0, a1, $10
    }
}

Lbb37c:	; 800BB37C
V0 = A2 + 1
A2 = V0;
V1 = w[8007E770];
V1 = hu[V1 + 2];
V0 = V0 < V1;

800BB398	bne    v0, zero, loopbb294 [$800bb294]
800BB39C	sll    v0, a2, $10

Lbb3a0:	; 800BB3A0
800BB3A0	jr     ra 
800BB3A4	nop
////////////////////////////////



////////////////////////////////
// opcode_cycle
800BB3A8-800BB994-800BBBC8
////////////////////////////////



////////////////////////////////
// handle_animation_state
800BBBCC-800BBF70
////////////////////////////////



////////////////////////////////
// script_request_run
800BBF74-800BC334
////////////////////////////////



funcbc338:	; 800BC338
800BC338	addiu  sp, sp, $ffe8 (=-$18)
800BC33C	ori    v0, zero, $7fff
800BC340	ori    v1, zero, $0009
800BC344	lui    at, $8011
800BC348	sh     v0, $4464(at)
800BC34C	lui    at, $8011
800BC350	sh     v0, $4468(at)
800BC354	ori    v0, zero, $002c
800BC358	lui    at, $800e
800BC35C	sb     v0, $48fb(at)
800BC360	lui    at, $800e
800BC364	sb     v0, $4923(at)
800BC368	lui    at, $800e
800BC36C	sb     v0, $48fb(at)
800BC370	lui    at, $800e
800BC374	sb     v0, $4923(at)
800BC378	ori    v0, zero, $002d
800BC37C	sw     ra, $0010(sp)
800BC380	lui    at, $8011
800BC384	sb     zero, $4490(at)
800BC388	lui    at, $800e
800BC38C	sb     v1, $48f7(at)
800BC390	lui    at, $800e
800BC394	sb     v1, $491f(at)
800BC398	lui    at, $800e
800BC39C	sb     v0, $48fb(at)
800BC3A0	lui    at, $800e
800BC3A4	sb     v0, $4923(at)
800BC3A8	jal    func43cc0 [$80043cc0]
800BC3AC	nop
800BC3B0	ori    v1, zero, $0001
800BC3B4	beq    v0, v1, Lbc3d4 [$800bc3d4]
800BC3B8	ori    v0, zero, $002f
800BC3BC	jal    func43cc0 [$80043cc0]
800BC3C0	nop
800BC3C4	ori    v1, zero, $0002
800BC3C8	bne    v0, v1, Lbc3d4 [$800bc3d4]
800BC3CC	ori    v0, zero, $001f
800BC3D0	ori    v0, zero, $002f

Lbc3d4:	; 800BC3D4
800BC3D4	lui    at, $800e
800BC3D8	sh     v0, $4932(at)
800BC3DC	lui    at, $800e
800BC3E0	sh     v0, $490a(at)
800BC3E4	ori    v0, zero, $7850
800BC3E8	lui    at, $800e
800BC3EC	sh     v0, $492a(at)
800BC3F0	lui    at, $800e
800BC3F4	sh     v0, $4902(at)
800BC3F8	lui    at, $800e
800BC3FC	sb     zero, $48f8(at)
800BC400	lui    at, $800e
800BC404	sb     zero, $4920(at)
800BC408	lui    at, $800e
800BC40C	sb     zero, $48f9(at)
800BC410	lui    at, $800e
800BC414	sb     zero, $4921(at)
800BC418	lui    at, $800e
800BC41C	sb     zero, $48fa(at)
800BC420	lui    at, $800e
800BC424	sb     zero, $4922(at)
800BC428	lw     ra, $0010(sp)
800BC42C	addiu  sp, sp, $0018
800BC430	jr     ra 
800BC434	nop



////////////////////////////////
// funcbc438
800BC438-800BC4D0
////////////////////////////////


////////////////////////////////
// funcbc4d4
800BC4D4-800BC9F8
////////////////////////////////



funcbc9fc:	; 800BC9FC
800BC9FC	addiu  sp, sp, $ffc8 (=-$38)
800BCA00	sw     s4, $0020(sp)
800BCA04	addu   s4, a0, zero
800BCA08	sw     s6, $0028(sp)
800BCA0C	addu   s6, a1, zero
800BCA10	sll    a0, a0, $10
800BCA14	sra    a0, a0, $10
800BCA18	ori    v0, zero, $0004
800BCA1C	sw     ra, $0030(sp)
800BCA20	sw     s7, $002c(sp)
800BCA24	sw     s5, $0024(sp)
800BCA28	sw     s3, $001c(sp)
800BCA2C	sw     s2, $0018(sp)
800BCA30	sw     s1, $0014(sp)
800BCA34	bne    a0, v0, Lbcadc [$800bcadc]
800BCA38	sw     s0, $0010(sp)
800BCA3C	lui    v0, $8007
800BCA40	lbu    v0, $1e24(v0)
800BCA44	nop
800BCA48	andi   v0, v0, $0004
800BCA4C	beq    v0, zero, Lbca74 [$800bca74]
800BCA50	sll    v0, a1, $10
800BCA54	sra    v0, v0, $10
800BCA58	lui    at, $8011
800BCA5C	addiu  at, at, $4498
800BCA60	addu   at, at, v0
800BCA64	lbu    v0, $0000(at)
800BCA68	nop
800BCA6C	beq    v0, zero, Lbeaa4 [$800beaa4]
800BCA70	nop

Lbca74:	; 800BCA74
800BCA74	sll    v0, a1, $10
800BCA78	sra    v0, v0, $10
800BCA7C	lui    at, $8007
800BCA80	sb     s6, $16c8(at)
800BCA84	lui    at, $8011
800BCA88	addiu  at, at, $4498
800BCA8C	addu   at, at, v0
800BCA90	lbu    v0, $0000(at)
800BCA94	nop
800BCA98	beq    v0, zero, Lbcab0 [$800bcab0]
800BCA9C	ori    a0, zero, $0004
800BCAA0	ori    a1, zero, $007f
800BCAA4	ori    a2, zero, $0001
800BCAA8	j      Lbcabc [$800bcabc]
800BCAAC	ori    a3, zero, $007f

Lbcab0:	; 800BCAB0
800BCAB0	ori    a1, zero, $0007
800BCAB4	ori    a2, zero, $000f
800BCAB8	ori    a3, zero, $001f

Lbcabc:	; 800BCABC
800BCABC	jal    funcda214 [$800da214]
800BCAC0	nop
800BCAC4	lui    a0, $800e
800BCAC8	addiu  a0, a0, $4254
800BCACC	lui    a1, $800e
800BCAD0	addiu  a1, a1, $0628
800BCAD4	j      Lbcaec [$800bcaec]
800BCAD8	nop

Lbcadc:	; 800BCADC
800BCADC	lui    a0, $800e
800BCAE0	addiu  a0, a0, $4254
800BCAE4	lui    a1, $800a
800BCAE8	addiu  a1, a1, $01d4

Lbcaec:	; 800BCAEC
800BCAEC	jal    funcda334 [$800da334]
800BCAF0	nop
800BCAF4	lui    s1, $800e
800BCAF8	addiu  s1, s1, $4254
800BCAFC	addu   a0, s1, zero
800BCB00	sll    v0, s6, $10
800BCB04	sra    s2, v0, $10
800BCB08	sll    s3, s2, $03
800BCB0C	lui    v0, $800a
800BCB10	lw     v0, $c6dc(v0)
800BCB14	addiu  a1, s3, $0020
800BCB18	jal    funcda368 [$800da368]
800BCB1C	addu   a1, a1, v0
800BCB20	lui    v0, $8007
800BCB24	lbu    v0, $1e24(v0)
800BCB28	lui    v1, $800a
800BCB2C	lbu    v1, $fe8c(v1)
800BCB30	andi   v0, v0, $0001
800BCB34	or     v1, v1, v0
800BCB38	beq    v1, zero, Lbcb50 [$800bcb50]
800BCB3C	sll    a0, s4, $10
800BCB40	sra    a0, a0, $10
800BCB44	addu   a1, zero, zero
800BCB48	jal    funcda124 [$800da124]
800BCB4C	addu   a2, s1, zero

Lbcb50:	; 800BCB50
800BCB50	lui    v0, $8007
800BCB54	lbu    v0, $1e24(v0)
800BCB58	nop
800BCB5C	andi   v0, v0, $0002
800BCB60	beq    v0, zero, Lbcb70 [$800bcb70]
800BCB64	nop
800BCB68	jal    funcd4840 [$800d4840]
800BCB6C	addu   a0, s1, zero

Lbcb70:	; 800BCB70
800BCB70	lui    a1, $800a
800BCB74	addiu  a1, a1, $01dc
800BCB78	jal    funcda334 [$800da334]
800BCB7C	addu   a0, s1, zero
800BCB80	lui    s0, $800e
800BCB84	addiu  s0, s0, $4288
800BCB88	lui    at, $800a
800BCB8C	addiu  at, at, $a1c4 (=-$5e3c)
800BCB90	addu   at, at, s2
800BCB94	lbu    a0, $0000(at)
800BCB98	jal    funcda424 [$800da424]
800BCB9C	addu   a1, s0, zero
800BCBA0	addu   a0, s1, zero
800BCBA4	jal    funcda368 [$800da368]
800BCBA8	addu   a1, s0, zero
800BCBAC	lui    a1, $800a
800BCBB0	addiu  a1, a1, $01e4
800BCBB4	jal    funcda368 [$800da368]
800BCBB8	addu   a0, s1, zero
800BCBBC	lui    v0, $8011
800BCBC0	addiu  v0, v0, $42d4
800BCBC4	lui    at, $800a
800BCBC8	addiu  at, at, $a1c4 (=-$5e3c)
800BCBCC	addu   at, at, s2
800BCBD0	lbu    v1, $0000(at)
800BCBD4	addu   v0, s3, v0
800BCBD8	addu   v0, v0, v1
800BCBDC	lbu    v1, $0000(v0)
800BCBE0	ori    v0, zero, $0001
800BCBE4	beq    v1, v0, Lbcc28 [$800bcc28]
800BCBE8	slti   v0, v1, $0002
800BCBEC	beq    v0, zero, Lbcc04 [$800bcc04]
800BCBF0	nop
800BCBF4	beq    v1, zero, Lbcc18 [$800bcc18]
800BCBF8	sll    v1, s6, $10
800BCBFC	j      Lbcc48 [$800bcc48]
800BCC00	nop

Lbcc04:	; 800BCC04
800BCC04	ori    v0, zero, $0002
800BCC08	beq    v1, v0, Lbcc38 [$800bcc38]
800BCC0C	sll    v1, s6, $10
800BCC10	j      Lbcc48 [$800bcc48]
800BCC14	nop

Lbcc18:	; 800BCC18
800BCC18	lui    a1, $800a
800BCC1C	addiu  a1, a1, $01ec
800BCC20	j      Lbcc90 [$800bcc90]
800BCC24	addu   a0, s1, zero

Lbcc28:	; 800BCC28
800BCC28	lui    a1, $800a
800BCC2C	addiu  a1, a1, $01f0
800BCC30	j      Lbcc90 [$800bcc90]
800BCC34	addu   a0, s1, zero

Lbcc38:	; 800BCC38
800BCC38	lui    a1, $800a
800BCC3C	addiu  a1, a1, $01f4
800BCC40	j      Lbcc90 [$800bcc90]
800BCC44	addu   a0, s1, zero

Lbcc48:	; 800BCC48
800BCC48	sra    v1, v1, $10
800BCC4C	lui    a0, $8011
800BCC50	addiu  a0, a0, $42d4
800BCC54	sll    v0, v1, $03
800BCC58	addu   v0, v0, a0
800BCC5C	lui    at, $800a
800BCC60	addiu  at, at, $a1c4 (=-$5e3c)
800BCC64	addu   at, at, v1
800BCC68	lbu    v1, $0000(at)
800BCC6C	lui    s0, $800e
800BCC70	addiu  s0, s0, $4288
800BCC74	addu   v0, v0, v1
800BCC78	lbu    a0, $0000(v0)
800BCC7C	jal    funcda444 [$800da444]
800BCC80	addu   a1, s0, zero
800BCC84	lui    a0, $800e
800BCC88	addiu  a0, a0, $4254
800BCC8C	addu   a1, s0, zero

Lbcc90:	; 800BCC90
800BCC90	jal    funcda368 [$800da368]
800BCC94	nop
800BCC98	lui    v0, $8007
800BCC9C	lbu    v0, $1e24(v0)
800BCCA0	lui    v1, $800a
800BCCA4	lbu    v1, $fe8c(v1)
800BCCA8	andi   v0, v0, $0001
800BCCAC	or     v1, v1, v0
800BCCB0	beq    v1, zero, Lbcccc [$800bcccc]
800BCCB4	sll    a0, s4, $10
800BCCB8	sra    a0, a0, $10
800BCCBC	lui    a2, $800e
800BCCC0	addiu  a2, a2, $4254
800BCCC4	jal    funcda124 [$800da124]
800BCCC8	ori    a1, zero, $0001

Lbcccc:	; 800BCCCC
800BCCCC	lui    v0, $8007
800BCCD0	lbu    v0, $1e24(v0)
800BCCD4	nop
800BCCD8	andi   v0, v0, $0002
800BCCDC	beq    v0, zero, Lbccf8 [$800bccf8]
800BCCE0	sll    v0, s6, $10
800BCCE4	lui    a0, $800e
800BCCE8	addiu  a0, a0, $4254
800BCCEC	jal    funcd4840 [$800d4840]
800BCCF0	nop
800BCCF4	sll    v0, s6, $10

Lbccf8:	; 800BCCF8
800BCCF8	sra    s2, v0, $10
800BCCFC	lui    at, $8008
800BCD00	addiu  at, at, $eb98 (=-$1468)
800BCD04	addu   at, at, s2
800BCD08	lbu    v1, $0000(at)
800BCD0C	ori    v0, zero, $00ff
800BCD10	bne    v1, v0, Lbce4c [$800bce4c]
800BCD14	nop
800BCD18	lui    at, $8007
800BCD1C	addiu  at, at, $078c
800BCD20	addu   at, at, s2
800BCD24	lbu    v0, $0000(at)
800BCD28	nop
800BCD2C	bne    v0, v1, Lbcd7c [$800bcd7c]
800BCD30	nop
800BCD34	lui    a0, $800e
800BCD38	addiu  a0, a0, $4254
800BCD3C	lui    a1, $800a
800BCD40	addiu  a1, a1, $01f8
800BCD44	jal    funcda334 [$800da334]
800BCD48	nop
800BCD4C	lui    v0, $8007
800BCD50	lbu    v0, $1e24(v0)
800BCD54	lui    v1, $800a
800BCD58	lbu    v1, $fe8c(v1)
800BCD5C	andi   v0, v0, $0001
800BCD60	or     v1, v1, v0
800BCD64	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCD68	sll    a0, s4, $10
800BCD6C	sra    a0, a0, $10
800BCD70	ori    a1, zero, $0002
800BCD74	j      Lbcf10 [$800bcf10]
800BCD78	ori    a2, zero, $0006

Lbcd7c:	; 800BCD7C
800BCD7C	lui    s1, $800e
800BCD80	addiu  s1, s1, $4254
800BCD84	lui    a1, $800a
800BCD88	addiu  a1, a1, $0200
800BCD8C	jal    funcda334 [$800da334]
800BCD90	addu   a0, s1, zero
800BCD94	lui    s0, $800e
800BCD98	addiu  s0, s0, $4288
800BCD9C	lui    at, $8007
800BCDA0	addiu  at, at, $078c
800BCDA4	addu   at, at, s2
800BCDA8	lbu    a0, $0000(at)
800BCDAC	jal    funcda444 [$800da444]
800BCDB0	addu   a1, s0, zero
800BCDB4	addu   a0, s1, zero
800BCDB8	jal    funcda368 [$800da368]
800BCDBC	addu   a1, s0, zero
800BCDC0	lui    at, $8007
800BCDC4	addiu  at, at, $078c
800BCDC8	addu   at, at, s2
800BCDCC	lbu    v1, $0000(at)
800BCDD0	nop
800BCDD4	sll    v0, v1, $01
800BCDD8	addu   v0, v0, v1
800BCDDC	sll    v0, v0, $03
800BCDE0	lui    at, $8008
800BCDE4	addiu  at, at, $e7b8 (=-$1848)
800BCDE8	addu   at, at, v0
800BCDEC	lbu    v0, $0000(at)
800BCDF0	nop
800BCDF4	beq    v0, zero, Lbce0c [$800bce0c]
800BCDF8	addu   a0, s1, zero
800BCDFC	lui    a1, $800a
800BCE00	addiu  a1, a1, $0208
800BCE04	j      Lbce14 [$800bce14]
800BCE08	nop

Lbce0c:	; 800BCE0C
800BCE0C	lui    a1, $800a
800BCE10	addiu  a1, a1, $020c

Lbce14:	; 800BCE14
800BCE14	jal    funcda368 [$800da368]
800BCE18	nop
800BCE1C	lui    v0, $8007
800BCE20	lbu    v0, $1e24(v0)
800BCE24	lui    v1, $800a
800BCE28	lbu    v1, $fe8c(v1)
800BCE2C	andi   v0, v0, $0001
800BCE30	or     v1, v1, v0
800BCE34	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCE38	sll    a0, s4, $10
800BCE3C	sra    a0, a0, $10
800BCE40	ori    a1, zero, $0002
800BCE44	j      Lbcf10 [$800bcf10]
800BCE48	ori    a2, zero, $0003

Lbce4c:	; 800BCE4C
800BCE4C	lui    s1, $800e
800BCE50	addiu  s1, s1, $4254
800BCE54	lui    a1, $800a
800BCE58	addiu  a1, a1, $0214
800BCE5C	jal    funcda334 [$800da334]
800BCE60	addu   a0, s1, zero
800BCE64	lui    s0, $800e
800BCE68	addiu  s0, s0, $4288
800BCE6C	lui    at, $8008
800BCE70	addiu  at, at, $eb98 (=-$1468)
800BCE74	addu   at, at, s2
800BCE78	lbu    a0, $0000(at)
800BCE7C	jal    funcda444 [$800da444]
800BCE80	addu   a1, s0, zero
800BCE84	addu   a0, s1, zero
800BCE88	jal    funcda368 [$800da368]
800BCE8C	addu   a1, s0, zero
800BCE90	lui    a1, $800a
800BCE94	addiu  a1, a1, $021c
800BCE98	jal    funcda368 [$800da368]
800BCE9C	addu   a0, s1, zero
800BCEA0	lui    at, $8008
800BCEA4	addiu  at, at, $eb98 (=-$1468)
800BCEA8	addu   at, at, s2
800BCEAC	lbu    v1, $0000(at)
800BCEB0	nop
800BCEB4	sll    v0, v1, $05
800BCEB8	addu   v0, v0, v1
800BCEBC	lui    v1, $800a
800BCEC0	lw     v1, $c544(v1)
800BCEC4	sll    v0, v0, $02
800BCEC8	addu   v0, v0, v1
800BCECC	lbu    a0, $0038(v0)
800BCED0	jal    funcda444 [$800da444]
800BCED4	addu   a1, s0, zero
800BCED8	addu   a0, s1, zero
800BCEDC	jal    funcda368 [$800da368]
800BCEE0	addu   a1, s0, zero
800BCEE4	lui    v0, $8007
800BCEE8	lbu    v0, $1e24(v0)
800BCEEC	lui    v1, $800a
800BCEF0	lbu    v1, $fe8c(v1)
800BCEF4	andi   v0, v0, $0001
800BCEF8	or     v1, v1, v0
800BCEFC	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCF00	sll    a0, s4, $10
800BCF04	sra    a0, a0, $10
800BCF08	ori    a1, zero, $0002
800BCF0C	ori    a2, zero, $0002

Lbcf10:	; 800BCF10
800BCF10	jal    funcda194 [$800da194]
800BCF14	nop
800BCF18	lui    v0, $8007
800BCF1C	lbu    v0, $1e24(v0)
800BCF20	lui    v1, $800a
800BCF24	lbu    v1, $fe8c(v1)
800BCF28	andi   v0, v0, $0001
800BCF2C	or     v1, v1, v0
800BCF30	beq    v1, zero, Lbcf4c [$800bcf4c]
800BCF34	sll    a0, s4, $10
800BCF38	sra    a0, a0, $10
800BCF3C	lui    a2, $800e
800BCF40	addiu  a2, a2, $4254
800BCF44	jal    funcda124 [$800da124]
800BCF48	ori    a1, zero, $0002

Lbcf4c:	; 800BCF4C
800BCF4C	lui    v0, $8007
800BCF50	lbu    v0, $1e24(v0)
800BCF54	nop
800BCF58	andi   v0, v0, $0002
800BCF5C	beq    v0, zero, Lbcf78 [$800bcf78]
800BCF60	sll    v0, s6, $10
800BCF64	lui    a0, $800e
800BCF68	addiu  a0, a0, $4254
800BCF6C	jal    funcd4840 [$800d4840]
800BCF70	nop
800BCF74	sll    v0, s6, $10

Lbcf78:	; 800BCF78
800BCF78	sra    s2, v0, $10
800BCF7C	lui    at, $8008
800BCF80	addiu  at, at, $eb98 (=-$1468)
800BCF84	addu   at, at, s2
800BCF88	lbu    v1, $0000(at)
800BCF8C	ori    v0, zero, $00ff
800BCF90	beq    v1, v0, Lbd6a0 [$800bd6a0]
800BCF94	nop
800BCF98	lui    s1, $800e
800BCF9C	addiu  s1, s1, $4254
800BCFA0	lui    a1, $800a
800BCFA4	addiu  a1, a1, $0224
800BCFA8	jal    funcda334 [$800da334]
800BCFAC	addu   a0, s1, zero
800BCFB0	lui    at, $8008
800BCFB4	addiu  at, at, $eb98 (=-$1468)
800BCFB8	addu   at, at, s2
800BCFBC	lbu    v1, $0000(at)
800BCFC0	lui    s3, $800e
800BCFC4	addiu  s3, s3, $4288
800BCFC8	sll    v0, v1, $05
800BCFCC	addu   v0, v0, v1
800BCFD0	lui    v1, $800a
800BCFD4	lw     v1, $c544(v1)
800BCFD8	sll    v0, v0, $02
800BCFDC	addu   v0, v0, v1
800BCFE0	lw     a0, $000c(v0)
800BCFE4	addu   a1, s3, zero
800BCFE8	jal    funcda480 [$800da480]
800BCFEC	sra    a0, a0, $0c
800BCFF0	addu   a0, s1, zero
800BCFF4	jal    funcda368 [$800da368]
800BCFF8	addu   a1, s3, zero
800BCFFC	lui    a1, $800a
800BD000	addiu  a1, a1, $0228
800BD004	jal    funcda368 [$800da368]
800BD008	addu   a0, s1, zero
800BD00C	lui    at, $8008
800BD010	addiu  at, at, $eb98 (=-$1468)
800BD014	addu   at, at, s2
800BD018	lbu    v1, $0000(at)
800BD01C	nop
800BD020	sll    v0, v1, $05
800BD024	addu   v0, v0, v1
800BD028	lui    v1, $800a
800BD02C	lw     v1, $c544(v1)
800BD030	sll    v0, v0, $02
800BD034	addu   v0, v0, v1
800BD038	lw     a0, $0010(v0)
800BD03C	addu   a1, s3, zero
800BD040	jal    funcda480 [$800da480]
800BD044	sra    a0, a0, $0c
800BD048	addu   a0, s1, zero
800BD04C	jal    funcda368 [$800da368]
800BD050	addu   a1, s3, zero
800BD054	lui    v0, $8007
800BD058	lbu    v0, $1e24(v0)
800BD05C	lui    v1, $800a
800BD060	lbu    v1, $fe8c(v1)
800BD064	andi   v0, v0, $0001
800BD068	or     v1, v1, v0
800BD06C	beq    v1, zero, Lbd098 [$800bd098]
800BD070	sll    s0, s4, $10
800BD074	sra    s0, s0, $10
800BD078	addu   a0, s0, zero
800BD07C	ori    a1, zero, $0003
800BD080	jal    funcda124 [$800da124]
800BD084	addu   a2, s1, zero
800BD088	addu   a0, s0, zero
800BD08C	ori    a1, zero, $0003
800BD090	jal    funcda194 [$800da194]
800BD094	ori    a2, zero, $0001

Lbd098:	; 800BD098
800BD098	lui    v0, $8007
800BD09C	lbu    v0, $1e24(v0)
800BD0A0	nop
800BD0A4	andi   v0, v0, $0002
800BD0A8	beq    v0, zero, Lbd0b8 [$800bd0b8]
800BD0AC	nop
800BD0B0	jal    funcd4840 [$800d4840]
800BD0B4	addu   a0, s1, zero

Lbd0b8:	; 800BD0B8
800BD0B8	lui    a1, $800a
800BD0BC	addiu  a1, a1, $022c
800BD0C0	jal    funcda334 [$800da334]
800BD0C4	addu   a0, s1, zero
800BD0C8	lui    at, $8008
800BD0CC	addiu  at, at, $eb98 (=-$1468)
800BD0D0	addu   at, at, s2
800BD0D4	lbu    v1, $0000(at)
800BD0D8	nop
800BD0DC	sll    v0, v1, $05
800BD0E0	addu   v0, v0, v1
800BD0E4	lui    v1, $800a
800BD0E8	lw     v1, $c544(v1)
800BD0EC	sll    v0, v0, $02
800BD0F0	addu   v0, v0, v1
800BD0F4	lw     a0, $0014(v0)
800BD0F8	addu   a1, s3, zero
800BD0FC	jal    funcda480 [$800da480]
800BD100	sra    a0, a0, $0c
800BD104	addu   a0, s1, zero
800BD108	jal    funcda368 [$800da368]
800BD10C	addu   a1, s3, zero
800BD110	lui    a1, $800a
800BD114	addiu  a1, a1, $0230
800BD118	jal    funcda368 [$800da368]
800BD11C	addu   a0, s1, zero
800BD120	lui    at, $8008
800BD124	addiu  at, at, $eb98 (=-$1468)
800BD128	addu   at, at, s2
800BD12C	lbu    v1, $0000(at)
800BD130	nop
800BD134	sll    v0, v1, $05
800BD138	addu   v0, v0, v1
800BD13C	lui    v1, $800a
800BD140	lw     v1, $c544(v1)
800BD144	sll    v0, v0, $02
800BD148	addu   v0, v0, v1
800BD14C	lhu    a0, $0072(v0)
800BD150	jal    funcda480 [$800da480]
800BD154	addu   a1, s3, zero
800BD158	addu   a0, s1, zero
800BD15C	jal    funcda368 [$800da368]
800BD160	addu   a1, s3, zero
800BD164	lui    v0, $8007
800BD168	lbu    v0, $1e24(v0)
800BD16C	lui    v1, $800a
800BD170	lbu    v1, $fe8c(v1)
800BD174	andi   v0, v0, $0001
800BD178	or     v1, v1, v0
800BD17C	beq    v1, zero, Lbd194 [$800bd194]
800BD180	sll    a0, s4, $10
800BD184	sra    a0, a0, $10
800BD188	ori    a1, zero, $0004
800BD18C	jal    funcda124 [$800da124]
800BD190	addu   a2, s1, zero

Lbd194:	; 800BD194
800BD194	lui    v0, $8007
800BD198	lbu    v0, $1e24(v0)
800BD19C	nop
800BD1A0	andi   v0, v0, $0002
800BD1A4	beq    v0, zero, Lbd1b4 [$800bd1b4]
800BD1A8	nop
800BD1AC	jal    funcd4840 [$800d4840]
800BD1B0	addu   a0, s1, zero

Lbd1b4:	; 800BD1B4
800BD1B4	lui    at, $8008
800BD1B8	addiu  at, at, $eb98 (=-$1468)
800BD1BC	addu   at, at, s2
800BD1C0	lbu    v0, $0000(at)
800BD1C4	nop
800BD1C8	lui    at, $8007
800BD1CC	addiu  at, at, $56e8
800BD1D0	addu   at, at, v0
800BD1D4	lbu    a0, $0000(at)
800BD1D8	jal    funcda424 [$800da424]
800BD1DC	addu   a1, s1, zero
800BD1E0	lui    a1, $800a
800BD1E4	addiu  a1, a1, $0234
800BD1E8	jal    funcda368 [$800da368]
800BD1EC	addu   a0, s1, zero
800BD1F0	lui    at, $8008
800BD1F4	addiu  at, at, $eb98 (=-$1468)
800BD1F8	addu   at, at, s2
800BD1FC	lbu    v1, $0000(at)
800BD200	nop
800BD204	sll    v0, v1, $05
800BD208	addu   v0, v0, v1
800BD20C	lui    v1, $800a
800BD210	lw     v1, $c544(v1)
800BD214	sll    v0, v0, $02
800BD218	addu   v0, v0, v1
800BD21C	lbu    a0, $005e(v0)
800BD220	jal    funcda444 [$800da444]
800BD224	addu   a1, s3, zero
800BD228	addu   a0, s1, zero
800BD22C	jal    funcda368 [$800da368]
800BD230	addu   a1, s3, zero
800BD234	addu   a0, s1, zero
800BD238	lui    s5, $800a
800BD23C	addiu  s5, s5, $0238
800BD240	jal    funcda368 [$800da368]
800BD244	addu   a1, s5, zero
800BD248	lui    at, $8008
800BD24C	addiu  at, at, $eb98 (=-$1468)
800BD250	addu   at, at, s2
800BD254	lbu    v1, $0000(at)
800BD258	nop
800BD25C	sll    v0, v1, $05
800BD260	addu   v0, v0, v1
800BD264	lui    v1, $800a
800BD268	lw     v1, $c544(v1)
800BD26C	sll    v0, v0, $02
800BD270	addu   v0, v0, v1
800BD274	lh     a0, $0062(v0)
800BD278	jal    funcda480 [$800da480]
800BD27C	addu   a1, s3, zero
800BD280	addu   a0, s1, zero
800BD284	jal    funcda368 [$800da368]
800BD288	addu   a1, s3, zero
800BD28C	addu   a0, s1, zero
800BD290	jal    funcda368 [$800da368]
800BD294	addu   a1, s5, zero
800BD298	lui    at, $8008
800BD29C	addiu  at, at, $eb98 (=-$1468)
800BD2A0	addu   at, at, s2
800BD2A4	lbu    v1, $0000(at)
800BD2A8	nop
800BD2AC	sll    v0, v1, $05
800BD2B0	addu   v0, v0, v1
800BD2B4	lui    v1, $800a
800BD2B8	lw     v1, $c544(v1)
800BD2BC	sll    v0, v0, $02
800BD2C0	addu   v0, v0, v1
800BD2C4	lh     a0, $0064(v0)
800BD2C8	jal    funcda444 [$800da444]
800BD2CC	addu   a1, s3, zero
800BD2D0	addu   a0, s1, zero
800BD2D4	jal    funcda368 [$800da368]
800BD2D8	addu   a1, s3, zero
800BD2DC	lui    v0, $8007
800BD2E0	lbu    v0, $1e24(v0)
800BD2E4	lui    v1, $800a
800BD2E8	lbu    v1, $fe8c(v1)
800BD2EC	andi   v0, v0, $0001
800BD2F0	or     v1, v1, v0
800BD2F4	beq    v1, zero, Lbd320 [$800bd320]
800BD2F8	sll    s0, s4, $10
800BD2FC	sra    s0, s0, $10
800BD300	addu   a0, s0, zero
800BD304	ori    a1, zero, $0005
800BD308	jal    funcda124 [$800da124]
800BD30C	addu   a2, s1, zero
800BD310	addu   a0, s0, zero
800BD314	ori    a1, zero, $0005
800BD318	jal    funcda194 [$800da194]
800BD31C	ori    a2, zero, $0007

Lbd320:	; 800BD320
800BD320	lui    v0, $8007
800BD324	lbu    v0, $1e24(v0)
800BD328	nop
800BD32C	andi   v0, v0, $0002
800BD330	beq    v0, zero, Lbd340 [$800bd340]
800BD334	nop
800BD338	jal    funcd4840 [$800d4840]
800BD33C	addu   a0, s1, zero

Lbd340:	; 800BD340
800BD340	lui    at, $8008
800BD344	addiu  at, at, $eb98 (=-$1468)
800BD348	addu   at, at, s2
800BD34C	lbu    v1, $0000(at)
800BD350	nop
800BD354	sll    v0, v1, $05
800BD358	addu   v0, v0, v1
800BD35C	lui    v1, $800a
800BD360	lw     v1, $c544(v1)
800BD364	sll    v0, v0, $02
800BD368	addu   v0, v0, v1
800BD36C	lbu    v0, $005c(v0)
800BD370	nop
800BD374	beq    v0, zero, Lbd38c [$800bd38c]
800BD378	addu   a0, s1, zero
800BD37C	lui    a1, $800a
800BD380	addiu  a1, a1, $023c
800BD384	j      Lbd390 [$800bd390]
800BD388	nop

Lbd38c:	; 800BD38C
800BD38C	addu   a1, s5, zero

Lbd390:	; 800BD390
800BD390	jal    funcda334 [$800da334]
800BD394	nop
800BD398	sll    v0, s6, $10
800BD39C	sra    v0, v0, $10
800BD3A0	lui    at, $8008
800BD3A4	addiu  at, at, $eb98 (=-$1468)
800BD3A8	addu   at, at, v0
800BD3AC	lbu    v1, $0000(at)
800BD3B0	nop
800BD3B4	sll    v0, v1, $05
800BD3B8	addu   v0, v0, v1
800BD3BC	lui    v1, $800a
800BD3C0	lw     v1, $c544(v1)
800BD3C4	sll    v0, v0, $02
800BD3C8	addu   v0, v0, v1
800BD3CC	lbu    v0, $005b(v0)
800BD3D0	nop
800BD3D4	beq    v0, zero, Lbd3f4 [$800bd3f4]
800BD3D8	nop
800BD3DC	lui    a0, $800e
800BD3E0	addiu  a0, a0, $4254
800BD3E4	lui    a1, $800a
800BD3E8	addiu  a1, a1, $0238
800BD3EC	j      Lbd404 [$800bd404]
800BD3F0	nop

Lbd3f4:	; 800BD3F4
800BD3F4	lui    a0, $800e
800BD3F8	addiu  a0, a0, $4254
800BD3FC	lui    a1, $800a
800BD400	addiu  a1, a1, $0240

Lbd404:	; 800BD404
800BD404	jal    funcda368 [$800da368]
800BD408	nop
800BD40C	sll    v0, s6, $10
800BD410	sra    v0, v0, $10
800BD414	lui    at, $8008
800BD418	addiu  at, at, $eb98 (=-$1468)
800BD41C	addu   at, at, v0
800BD420	lbu    v1, $0000(at)
800BD424	nop
800BD428	sll    v0, v1, $05
800BD42C	addu   v0, v0, v1
800BD430	lui    v1, $800a
800BD434	lw     v1, $c544(v1)
800BD438	sll    v0, v0, $02
800BD43C	addu   v0, v0, v1
800BD440	lbu    v0, $0059(v0)
800BD444	nop
800BD448	beq    v0, zero, Lbd468 [$800bd468]
800BD44C	nop
800BD450	lui    a0, $800e
800BD454	addiu  a0, a0, $4254
800BD458	lui    a1, $800a
800BD45C	addiu  a1, a1, $0238
800BD460	j      Lbd478 [$800bd478]
800BD464	nop

Lbd468:	; 800BD468
800BD468	lui    a0, $800e
800BD46C	addiu  a0, a0, $4254
800BD470	lui    a1, $800a
800BD474	addiu  a1, a1, $0244

Lbd478:	; 800BD478
800BD478	jal    funcda368 [$800da368]
800BD47C	nop
800BD480	lui    s1, $800e
800BD484	addiu  s1, s1, $4254
800BD488	lui    a1, $800a
800BD48C	addiu  a1, a1, $0248
800BD490	jal    funcda368 [$800da368]
800BD494	addu   a0, s1, zero
800BD498	sll    v0, s6, $10
800BD49C	sra    s2, v0, $10
800BD4A0	lui    at, $8008
800BD4A4	addiu  at, at, $eb98 (=-$1468)
800BD4A8	addu   at, at, s2
800BD4AC	lbu    v1, $0000(at)
800BD4B0	lui    s0, $800e
800BD4B4	addiu  s0, s0, $4288
800BD4B8	sll    v0, v1, $05
800BD4BC	addu   v0, v0, v1
800BD4C0	lui    v1, $800a
800BD4C4	lw     v1, $c544(v1)
800BD4C8	sll    v0, v0, $02
800BD4CC	addu   v0, v0, v1
800BD4D0	lhu    a0, $006e(v0)
800BD4D4	jal    funcda444 [$800da444]
800BD4D8	addu   a1, s0, zero
800BD4DC	addu   a0, s1, zero
800BD4E0	jal    funcda368 [$800da368]
800BD4E4	addu   a1, s0, zero
800BD4E8	lui    a1, $800a
800BD4EC	addiu  a1, a1, $024c
800BD4F0	jal    funcda368 [$800da368]
800BD4F4	addu   a0, s1, zero
800BD4F8	lui    at, $8008
800BD4FC	addiu  at, at, $eb98 (=-$1468)
800BD500	addu   at, at, s2
800BD504	lbu    v1, $0000(at)
800BD508	nop
800BD50C	sll    v0, v1, $05
800BD510	addu   v0, v0, v1
800BD514	lui    v1, $800a
800BD518	lw     v1, $c544(v1)
800BD51C	sll    v0, v0, $02
800BD520	addu   v0, v0, v1
800BD524	lhu    a0, $006c(v0)
800BD528	jal    funcda444 [$800da444]
800BD52C	addu   a1, s0, zero
800BD530	addu   a0, s1, zero
800BD534	jal    funcda368 [$800da368]
800BD538	addu   a1, s0, zero
800BD53C	lui    v0, $8007
800BD540	lbu    v0, $1e24(v0)
800BD544	lui    v1, $800a
800BD548	lbu    v1, $fe8c(v1)
800BD54C	andi   v0, v0, $0001
800BD550	or     v1, v1, v0
800BD554	beq    v1, zero, Lbd56c [$800bd56c]
800BD558	sll    a0, s4, $10
800BD55C	sra    a0, a0, $10
800BD560	ori    a1, zero, $0006
800BD564	jal    funcda124 [$800da124]
800BD568	addu   a2, s1, zero

Lbd56c:	; 800BD56C
800BD56C	lui    v0, $8007
800BD570	lbu    v0, $1e24(v0)
800BD574	nop
800BD578	andi   v0, v0, $0002
800BD57C	beq    v0, zero, Lbd58c [$800bd58c]
800BD580	nop
800BD584	jal    funcd4840 [$800d4840]
800BD588	addu   a0, s1, zero

Lbd58c:	; 800BD58C
800BD58C	lui    a1, $800a
800BD590	addiu  a1, a1, $0250
800BD594	jal    funcda334 [$800da334]
800BD598	addu   a0, s1, zero
800BD59C	lui    at, $8008
800BD5A0	addiu  at, at, $eb98 (=-$1468)
800BD5A4	addu   at, at, s2
800BD5A8	lbu    v1, $0000(at)
800BD5AC	nop
800BD5B0	sll    v0, v1, $05
800BD5B4	addu   v0, v0, v1
800BD5B8	lui    v1, $800a
800BD5BC	lw     v1, $c544(v1)
800BD5C0	sll    v0, v0, $02
800BD5C4	addu   v0, v0, v1
800BD5C8	lhu    a0, $0070(v0)
800BD5CC	jal    funcda480 [$800da480]
800BD5D0	addu   a1, s0, zero
800BD5D4	addu   a0, s1, zero
800BD5D8	jal    funcda368 [$800da368]
800BD5DC	addu   a1, s0, zero
800BD5E0	lui    a1, $800a
800BD5E4	addiu  a1, a1, $0254
800BD5E8	jal    funcda368 [$800da368]
800BD5EC	addu   a0, s1, zero
800BD5F0	lui    at, $8008
800BD5F4	addiu  at, at, $eb98 (=-$1468)
800BD5F8	addu   at, at, s2
800BD5FC	lbu    v1, $0000(at)
800BD600	nop
800BD604	sll    v0, v1, $05
800BD608	addu   v0, v0, v1
800BD60C	lui    v1, $800a
800BD610	lw     v1, $c544(v1)
800BD614	sll    v0, v0, $02
800BD618	addu   v0, v0, v1
800BD61C	lh     a0, $0060(v0)
800BD620	jal    funcda480 [$800da480]
800BD624	addu   a1, s0, zero
800BD628	addu   a0, s1, zero
800BD62C	jal    funcda368 [$800da368]
800BD630	addu   a1, s0, zero
800BD634	lui    v0, $8007
800BD638	lbu    v0, $1e24(v0)
800BD63C	lui    v1, $800a
800BD640	lbu    v1, $fe8c(v1)
800BD644	andi   v0, v0, $0001
800BD648	or     v1, v1, v0
800BD64C	beq    v1, zero, Lbd678 [$800bd678]
800BD650	sll    s0, s4, $10
800BD654	sra    s0, s0, $10
800BD658	addu   a0, s0, zero
800BD65C	ori    a1, zero, $0007
800BD660	jal    funcda124 [$800da124]
800BD664	addu   a2, s1, zero
800BD668	addu   a0, s0, zero
800BD66C	ori    a1, zero, $0007
800BD670	jal    funcda194 [$800da194]
800BD674	ori    a2, zero, $0007

Lbd678:	; 800BD678
800BD678	lui    v0, $8007
800BD67C	lbu    v0, $1e24(v0)
800BD680	nop
800BD684	andi   v0, v0, $0002
800BD688	beq    v0, zero, Lbda90 [$800bda90]
800BD68C	sll    v0, s4, $10
800BD690	jal    funcd4840 [$800d4840]
800BD694	addu   a0, s1, zero
800BD698	j      Lbda90 [$800bda90]
800BD69C	sll    v0, s4, $10

Lbd6a0:	; 800BD6A0
800BD6A0	lui    at, $8007
800BD6A4	addiu  at, at, $078c
800BD6A8	addu   at, at, s2
800BD6AC	lbu    v0, $0000(at)
800BD6B0	nop
800BD6B4	beq    v0, v1, Lbda0c [$800bda0c]
800BD6B8	nop
800BD6BC	lui    s0, $800e
800BD6C0	addiu  s0, s0, $4254
800BD6C4	lui    a1, $800a
800BD6C8	addiu  a1, a1, $0258
800BD6CC	jal    funcda334 [$800da334]
800BD6D0	addu   a0, s0, zero
800BD6D4	lui    at, $8007
800BD6D8	addiu  at, at, $078c
800BD6DC	addu   at, at, s2
800BD6E0	lbu    v1, $0000(at)
800BD6E4	lui    s1, $800e
800BD6E8	addiu  s1, s1, $4288
800BD6EC	sll    v0, v1, $01
800BD6F0	addu   v0, v0, v1
800BD6F4	sll    v0, v0, $03
800BD6F8	lui    at, $8008
800BD6FC	addiu  at, at, $e7ac (=-$1854)
800BD700	addu   at, at, v0
800BD704	lh     a0, $0000(at)
800BD708	jal    funcda480 [$800da480]
800BD70C	addu   a1, s1, zero
800BD710	addu   a0, s0, zero
800BD714	jal    funcda368 [$800da368]
800BD718	addu   a1, s1, zero
800BD71C	lui    a1, $800a
800BD720	addiu  a1, a1, $025c
800BD724	jal    funcda368 [$800da368]
800BD728	addu   a0, s0, zero
800BD72C	lui    at, $8007
800BD730	addiu  at, at, $078c
800BD734	addu   at, at, s2
800BD738	lbu    v1, $0000(at)
800BD73C	nop
800BD740	sll    v0, v1, $01
800BD744	addu   v0, v0, v1
800BD748	sll    v0, v0, $03
800BD74C	lui    at, $8008
800BD750	addiu  at, at, $e7ae (=-$1852)
800BD754	addu   at, at, v0
800BD758	lh     a0, $0000(at)
800BD75C	jal    funcda480 [$800da480]
800BD760	addu   a1, s1, zero
800BD764	addu   a0, s0, zero
800BD768	jal    funcda368 [$800da368]
800BD76C	addu   a1, s1, zero
800BD770	lui    v0, $8007
800BD774	lbu    v0, $1e24(v0)
800BD778	lui    v1, $800a
800BD77C	lbu    v1, $fe8c(v1)
800BD780	andi   v0, v0, $0001
800BD784	or     v1, v1, v0
800BD788	beq    v1, zero, Lbd7a0 [$800bd7a0]
800BD78C	sll    a0, s4, $10
800BD790	sra    a0, a0, $10
800BD794	ori    a1, zero, $0003
800BD798	jal    funcda124 [$800da124]
800BD79C	addu   a2, s0, zero

Lbd7a0:	; 800BD7A0
800BD7A0	lui    v0, $8007
800BD7A4	lbu    v0, $1e24(v0)
800BD7A8	nop
800BD7AC	andi   v0, v0, $0002
800BD7B0	beq    v0, zero, Lbd7c0 [$800bd7c0]
800BD7B4	nop
800BD7B8	jal    funcd4840 [$800d4840]
800BD7BC	addu   a0, s0, zero

Lbd7c0:	; 800BD7C0
800BD7C0	lui    a1, $800a
800BD7C4	addiu  a1, a1, $0260
800BD7C8	jal    funcda334 [$800da334]
800BD7CC	addu   a0, s0, zero
800BD7D0	lui    at, $8007
800BD7D4	addiu  at, at, $078c
800BD7D8	addu   at, at, s2
800BD7DC	lbu    v1, $0000(at)
800BD7E0	nop
800BD7E4	sll    v0, v1, $01
800BD7E8	addu   v0, v0, v1
800BD7EC	sll    v0, v0, $03
800BD7F0	lui    at, $8008
800BD7F4	addiu  at, at, $e7b0 (=-$1850)
800BD7F8	addu   at, at, v0
800BD7FC	lh     a0, $0000(at)
800BD800	jal    funcda480 [$800da480]
800BD804	addu   a1, s1, zero
800BD808	addu   a0, s0, zero
800BD80C	jal    funcda368 [$800da368]
800BD810	addu   a1, s1, zero
800BD814	lui    v0, $8007
800BD818	lbu    v0, $1e24(v0)
800BD81C	lui    v1, $800a
800BD820	lbu    v1, $fe8c(v1)
800BD824	andi   v0, v0, $0001
800BD828	or     v1, v1, v0
800BD82C	beq    v1, zero, Lbd844 [$800bd844]
800BD830	sll    a0, s4, $10
800BD834	sra    a0, a0, $10
800BD838	ori    a1, zero, $0004
800BD83C	jal    funcda124 [$800da124]
800BD840	addu   a2, s0, zero

Lbd844:	; 800BD844
800BD844	lui    v0, $8007
800BD848	lbu    v0, $1e24(v0)
800BD84C	nop
800BD850	andi   v0, v0, $0002
800BD854	beq    v0, zero, Lbd864 [$800bd864]
800BD858	nop
800BD85C	jal    funcd4840 [$800d4840]
800BD860	addu   a0, s0, zero

Lbd864:	; 800BD864
800BD864	lui    a1, $800a
800BD868	addiu  a1, a1, $0264
800BD86C	jal    funcda334 [$800da334]
800BD870	addu   a0, s0, zero
800BD874	lui    at, $8007
800BD878	addiu  at, at, $078c
800BD87C	addu   at, at, s2
800BD880	lbu    v1, $0000(at)
800BD884	nop
800BD888	sll    v0, v1, $01
800BD88C	addu   v0, v0, v1
800BD890	sll    v0, v0, $03
800BD894	lui    at, $8008
800BD898	addiu  at, at, $e7b2 (=-$184e)
800BD89C	addu   at, at, v0
800BD8A0	lh     a0, $0000(at)
800BD8A4	jal    funcda480 [$800da480]
800BD8A8	addu   a1, s1, zero
800BD8AC	addu   a0, s0, zero
800BD8B0	jal    funcda368 [$800da368]
800BD8B4	addu   a1, s1, zero
800BD8B8	lui    a1, $800a
800BD8BC	addiu  a1, a1, $0268
800BD8C0	jal    funcda368 [$800da368]
800BD8C4	addu   a0, s0, zero
800BD8C8	lui    at, $8007
800BD8CC	addiu  at, at, $078c
800BD8D0	addu   at, at, s2
800BD8D4	lbu    v1, $0000(at)
800BD8D8	nop
800BD8DC	sll    v0, v1, $01
800BD8E0	addu   v0, v0, v1
800BD8E4	sll    v0, v0, $03
800BD8E8	lui    at, $8008
800BD8EC	addiu  at, at, $e7b4 (=-$184c)
800BD8F0	addu   at, at, v0
800BD8F4	lh     a0, $0000(at)
800BD8F8	jal    funcda480 [$800da480]
800BD8FC	addu   a1, s1, zero
800BD900	addu   a0, s0, zero
800BD904	jal    funcda368 [$800da368]
800BD908	addu   a1, s1, zero
800BD90C	lui    v0, $8007
800BD910	lbu    v0, $1e24(v0)
800BD914	lui    v1, $800a
800BD918	lbu    v1, $fe8c(v1)
800BD91C	andi   v0, v0, $0001
800BD920	or     v1, v1, v0
800BD924	beq    v1, zero, Lbd93c [$800bd93c]
800BD928	sll    a0, s4, $10
800BD92C	sra    a0, a0, $10
800BD930	ori    a1, zero, $0005
800BD934	jal    funcda124 [$800da124]
800BD938	addu   a2, s0, zero

Lbd93c:	; 800BD93C
800BD93C	lui    v0, $8007
800BD940	lbu    v0, $1e24(v0)
800BD944	nop
800BD948	andi   v0, v0, $0002
800BD94C	beq    v0, zero, Lbd95c [$800bd95c]
800BD950	nop
800BD954	jal    funcd4840 [$800d4840]
800BD958	addu   a0, s0, zero

Lbd95c:	; 800BD95C
800BD95C	lui    a1, $800a
800BD960	addiu  a1, a1, $026c
800BD964	jal    funcda334 [$800da334]
800BD968	addu   a0, s0, zero
800BD96C	lui    at, $8007
800BD970	addiu  at, at, $078c
800BD974	addu   at, at, s2
800BD978	lbu    v1, $0000(at)
800BD97C	nop
800BD980	sll    v0, v1, $01
800BD984	addu   v0, v0, v1
800BD988	sll    v0, v0, $03
800BD98C	lui    at, $8008
800BD990	addiu  at, at, $e7b6 (=-$184a)
800BD994	addu   at, at, v0
800BD998	lh     a0, $0000(at)
800BD99C	jal    funcda480 [$800da480]
800BD9A0	addu   a1, s1, zero
800BD9A4	addu   a0, s0, zero
800BD9A8	jal    funcda368 [$800da368]
800BD9AC	addu   a1, s1, zero
800BD9B0	lui    v0, $8007
800BD9B4	lbu    v0, $1e24(v0)
800BD9B8	lui    v1, $800a
800BD9BC	lbu    v1, $fe8c(v1)
800BD9C0	andi   v0, v0, $0001
800BD9C4	or     v1, v1, v0
800BD9C8	beq    v1, zero, Lbd9e0 [$800bd9e0]
800BD9CC	sll    a0, s4, $10
800BD9D0	sra    a0, a0, $10
800BD9D4	ori    a1, zero, $0006
800BD9D8	jal    funcda124 [$800da124]
800BD9DC	addu   a2, s0, zero

Lbd9e0:	; 800BD9E0
800BD9E0	lui    v0, $8007
800BD9E4	lbu    v0, $1e24(v0)
800BD9E8	nop
800BD9EC	andi   v0, v0, $0002
800BD9F0	beq    v0, zero, Lbda00 [$800bda00]
800BD9F4	nop
800BD9F8	jal    funcd4840 [$800d4840]
800BD9FC	addu   a0, s0, zero

Lbda00:	; 800BDA00
800BDA00	sll    a0, s4, $10
800BDA04	j      Lbda7c [$800bda7c]
800BDA08	sra    a0, a0, $10

Lbda0c:	; 800BDA0C
800BDA0C	lui    v0, $8007
800BDA10	lbu    v0, $1e24(v0)
800BDA14	lui    v1, $800a
800BDA18	lbu    v1, $fe8c(v1)
800BDA1C	andi   v0, v0, $0001
800BDA20	or     v1, v1, v0
800BDA24	beq    v1, zero, Lbda8c [$800bda8c]
800BDA28	sll    s0, s4, $10
800BDA2C	sra    s0, s0, $10
800BDA30	addu   a0, s0, zero
800BDA34	ori    a1, zero, $0003
800BDA38	lui    s1, $800a
800BDA3C	addiu  s1, s1, $0270
800BDA40	jal    funcda124 [$800da124]
800BDA44	addu   a2, s1, zero
800BDA48	addu   a0, s0, zero
800BDA4C	ori    a1, zero, $0004
800BDA50	jal    funcda124 [$800da124]
800BDA54	addu   a2, s1, zero
800BDA58	addu   a0, s0, zero
800BDA5C	ori    a1, zero, $0005
800BDA60	jal    funcda124 [$800da124]
800BDA64	addu   a2, s1, zero
800BDA68	addu   a0, s0, zero
800BDA6C	ori    a1, zero, $0006
800BDA70	jal    funcda124 [$800da124]
800BDA74	addu   a2, s1, zero
800BDA78	addu   a0, s0, zero

Lbda7c:	; 800BDA7C
800BDA7C	lui    a2, $800a
800BDA80	addiu  a2, a2, $0270
800BDA84	jal    funcda124 [$800da124]
800BDA88	ori    a1, zero, $0007

Lbda8c:	; 800BDA8C
800BDA8C	sll    v0, s4, $10

Lbda90:	; 800BDA90
800BDA90	sra    s0, v0, $10
800BDA94	ori    v0, zero, $0004
800BDA98	beq    s0, v0, Lbeaa4 [$800beaa4]
800BDA9C	nop
800BDAA0	lui    s1, $800e
800BDAA4	addiu  s1, s1, $4254
800BDAA8	lui    a1, $800a
800BDAAC	addiu  a1, a1, $0274
800BDAB0	jal    funcda334 [$800da334]
800BDAB4	addu   a0, s1, zero
800BDAB8	lui    s2, $800e
800BDABC	addiu  s2, s2, $4288
800BDAC0	lui    a0, $8007
800BDAC4	lh     a0, $1e38(a0)
800BDAC8	jal    funcda480 [$800da480]
800BDACC	addu   a1, s2, zero
800BDAD0	addu   a0, s1, zero
800BDAD4	jal    funcda368 [$800da368]
800BDAD8	addu   a1, s2, zero
800BDADC	lui    a1, $800a
800BDAE0	addiu  a1, a1, $0278
800BDAE4	jal    funcda368 [$800da368]
800BDAE8	addu   a0, s1, zero
800BDAEC	lui    a0, $8007
800BDAF0	lh     a0, $1e3c(a0)
800BDAF4	jal    funcda480 [$800da480]
800BDAF8	addu   a1, s2, zero
800BDAFC	addu   a0, s1, zero
800BDB00	jal    funcda368 [$800da368]
800BDB04	addu   a1, s2, zero
800BDB08	lui    v0, $8007
800BDB0C	lbu    v0, $1e24(v0)
800BDB10	lui    v1, $800a
800BDB14	lbu    v1, $fe8c(v1)
800BDB18	andi   v0, v0, $0001
800BDB1C	or     v1, v1, v0
800BDB20	beq    v1, zero, Lbdb44 [$800bdb44]
800BDB24	addu   a0, s0, zero
800BDB28	ori    a1, zero, $0008
800BDB2C	jal    funcda124 [$800da124]
800BDB30	addu   a2, s1, zero
800BDB34	addu   a0, s0, zero
800BDB38	ori    a1, zero, $0008
800BDB3C	jal    funcda194 [$800da194]
800BDB40	ori    a2, zero, $0003

Lbdb44:	; 800BDB44
800BDB44	lui    v0, $8007
800BDB48	lbu    v0, $1e24(v0)
800BDB4C	nop
800BDB50	andi   v0, v0, $0002
800BDB54	beq    v0, zero, Lbdb64 [$800bdb64]
800BDB58	nop
800BDB5C	jal    funcd4840 [$800d4840]
800BDB60	addu   a0, s1, zero

Lbdb64:	; 800BDB64
800BDB64	lui    a1, $800a
800BDB68	addiu  a1, a1, $027c
800BDB6C	jal    funcda334 [$800da334]
800BDB70	addu   a0, s1, zero
800BDB74	lui    s3, $800a
800BDB78	addiu  s3, s3, $ac1e (=-$53e2)
800BDB7C	lh     v1, $0000(s3)
800BDB80	nop
800BDB84	sll    v0, v1, $05
800BDB88	addu   v0, v0, v1
800BDB8C	sll    v0, v0, $02
800BDB90	lui    at, $8007
800BDB94	addiu  at, at, $4f16
800BDB98	addu   at, at, v0
800BDB9C	lhu    v1, $0000(at)
800BDBA0	nop
800BDBA4	sll    v0, v1, $01
800BDBA8	addu   v0, v0, v1
800BDBAC	lui    v1, $800e
800BDBB0	lw     v1, $4274(v1)
800BDBB4	sll    v0, v0, $03
800BDBB8	addu   v0, v0, v1
800BDBBC	lh     a0, $0000(v0)
800BDBC0	jal    funcda480 [$800da480]
800BDBC4	addu   a1, s2, zero
800BDBC8	addu   a0, s1, zero
800BDBCC	jal    funcda368 [$800da368]
800BDBD0	addu   a1, s2, zero
800BDBD4	lui    v0, $8007
800BDBD8	lbu    v0, $1e24(v0)
800BDBDC	lui    v1, $800a
800BDBE0	lbu    v1, $fe8c(v1)
800BDBE4	andi   v0, v0, $0001
800BDBE8	or     v1, v1, v0
800BDBEC	beq    v1, zero, Lbdc10 [$800bdc10]
800BDBF0	addu   a0, s0, zero
800BDBF4	ori    a1, zero, $0009
800BDBF8	jal    funcda124 [$800da124]
800BDBFC	addu   a2, s1, zero
800BDC00	addu   a0, s0, zero
800BDC04	ori    a1, zero, $0009
800BDC08	jal    funcda194 [$800da194]
800BDC0C	ori    a2, zero, $0002

Lbdc10:	; 800BDC10
800BDC10	lui    v0, $8007
800BDC14	lbu    v0, $1e24(v0)
800BDC18	nop
800BDC1C	andi   v0, v0, $0002
800BDC20	beq    v0, zero, Lbdc34 [$800bdc34]
800BDC24	addu   a0, s1, zero
800BDC28	jal    funcd4840 [$800d4840]
800BDC2C	addu   a0, s1, zero
800BDC30	addu   a0, s1, zero

Lbdc34:	; 800BDC34
800BDC34	lui    s7, $800a
800BDC38	addiu  s7, s7, $0288
800BDC3C	jal    funcda334 [$800da334]
800BDC40	addu   a1, s7, zero
800BDC44	lh     v1, $0000(s3)
800BDC48	nop
800BDC4C	sll    v0, v1, $05
800BDC50	addu   v0, v0, v1
800BDC54	sll    v0, v0, $02
800BDC58	lui    at, $8007
800BDC5C	addiu  at, at, $4f16
800BDC60	addu   at, at, v0
800BDC64	lhu    v1, $0000(at)
800BDC68	nop
800BDC6C	sll    v0, v1, $01
800BDC70	addu   v0, v0, v1
800BDC74	lui    v1, $800e
800BDC78	lw     v1, $4274(v1)
800BDC7C	sll    v0, v0, $03
800BDC80	addu   v0, v0, v1
800BDC84	lh     a0, $0002(v0)
800BDC88	jal    funcda480 [$800da480]
800BDC8C	addu   a1, s2, zero
800BDC90	addu   a0, s1, zero
800BDC94	jal    funcda368 [$800da368]
800BDC98	addu   a1, s2, zero
800BDC9C	addu   a0, s1, zero
800BDCA0	lui    s5, $800a
800BDCA4	addiu  s5, s5, $028c
800BDCA8	jal    funcda368 [$800da368]
800BDCAC	addu   a1, s5, zero
800BDCB0	lh     v1, $0000(s3)
800BDCB4	nop
800BDCB8	sll    v0, v1, $05
800BDCBC	addu   v0, v0, v1
800BDCC0	sll    v0, v0, $02
800BDCC4	lui    at, $8007
800BDCC8	addiu  at, at, $4f16
800BDCCC	addu   at, at, v0
800BDCD0	lhu    v1, $0000(at)
800BDCD4	nop
800BDCD8	sll    v0, v1, $01
800BDCDC	addu   v0, v0, v1
800BDCE0	lui    v1, $800e
800BDCE4	lw     v1, $4274(v1)
800BDCE8	sll    v0, v0, $03
800BDCEC	addu   v0, v0, v1
800BDCF0	lh     a0, $0004(v0)
800BDCF4	jal    funcda480 [$800da480]
800BDCF8	addu   a1, s2, zero
800BDCFC	addu   a0, s1, zero
800BDD00	jal    funcda368 [$800da368]
800BDD04	addu   a1, s2, zero
800BDD08	lui    v0, $8007
800BDD0C	lbu    v0, $1e24(v0)
800BDD10	lui    v1, $800a
800BDD14	lbu    v1, $fe8c(v1)
800BDD18	andi   v0, v0, $0001
800BDD1C	or     v1, v1, v0
800BDD20	beq    v1, zero, Lbdd34 [$800bdd34]
800BDD24	addu   a0, s0, zero
800BDD28	ori    a1, zero, $000a
800BDD2C	jal    funcda124 [$800da124]
800BDD30	addu   a2, s1, zero

Lbdd34:	; 800BDD34
800BDD34	lui    v0, $8007
800BDD38	lbu    v0, $1e24(v0)
800BDD3C	nop
800BDD40	andi   v0, v0, $0002
800BDD44	beq    v0, zero, Lbdd54 [$800bdd54]
800BDD48	nop
800BDD4C	jal    funcd4840 [$800d4840]
800BDD50	addu   a0, s1, zero

Lbdd54:	; 800BDD54
800BDD54	lui    a1, $800a
800BDD58	addiu  a1, a1, $0290
800BDD5C	jal    funcda334 [$800da334]
800BDD60	addu   a0, s1, zero
800BDD64	lh     v1, $0000(s3)
800BDD68	nop
800BDD6C	sll    v0, v1, $05
800BDD70	addu   v0, v0, v1
800BDD74	sll    v0, v0, $02
800BDD78	lui    at, $8007
800BDD7C	addiu  at, at, $4f16
800BDD80	addu   at, at, v0
800BDD84	lhu    v1, $0000(at)
800BDD88	nop
800BDD8C	sll    v0, v1, $01
800BDD90	addu   v0, v0, v1
800BDD94	lui    v1, $800e
800BDD98	lw     v1, $4274(v1)
800BDD9C	sll    v0, v0, $03
800BDDA0	addu   v0, v0, v1
800BDDA4	lh     a0, $0008(v0)
800BDDA8	jal    funcda480 [$800da480]
800BDDAC	addu   a1, s2, zero
800BDDB0	addu   a0, s1, zero
800BDDB4	jal    funcda368 [$800da368]
800BDDB8	addu   a1, s2, zero
800BDDBC	lui    v0, $8007
800BDDC0	lbu    v0, $1e24(v0)
800BDDC4	lui    v1, $800a
800BDDC8	lbu    v1, $fe8c(v1)
800BDDCC	andi   v0, v0, $0001
800BDDD0	or     v1, v1, v0
800BDDD4	beq    v1, zero, Lbddf8 [$800bddf8]
800BDDD8	addu   a0, s0, zero
800BDDDC	ori    a1, zero, $000b
800BDDE0	jal    funcda124 [$800da124]
800BDDE4	addu   a2, s1, zero
800BDDE8	addu   a0, s0, zero
800BDDEC	ori    a1, zero, $000b
800BDDF0	jal    funcda194 [$800da194]
800BDDF4	ori    a2, zero, $0004

Lbddf8:	; 800BDDF8
800BDDF8	lui    v0, $8007
800BDDFC	lbu    v0, $1e24(v0)
800BDE00	nop
800BDE04	andi   v0, v0, $0002
800BDE08	beq    v0, zero, Lbde1c [$800bde1c]
800BDE0C	addu   a0, s1, zero
800BDE10	jal    funcd4840 [$800d4840]
800BDE14	addu   a0, s1, zero
800BDE18	addu   a0, s1, zero

Lbde1c:	; 800BDE1C
800BDE1C	jal    funcda334 [$800da334]
800BDE20	addu   a1, s7, zero
800BDE24	lh     v1, $0000(s3)
800BDE28	nop
800BDE2C	sll    v0, v1, $05
800BDE30	addu   v0, v0, v1
800BDE34	sll    v0, v0, $02
800BDE38	lui    at, $8007
800BDE3C	addiu  at, at, $4f16
800BDE40	addu   at, at, v0
800BDE44	lhu    v1, $0000(at)
800BDE48	nop
800BDE4C	sll    v0, v1, $01
800BDE50	addu   v0, v0, v1
800BDE54	lui    v1, $800e
800BDE58	lw     v1, $4274(v1)
800BDE5C	sll    v0, v0, $03
800BDE60	addu   v0, v0, v1
800BDE64	lh     a0, $000a(v0)
800BDE68	jal    funcda480 [$800da480]
800BDE6C	addu   a1, s2, zero
800BDE70	addu   a0, s1, zero
800BDE74	jal    funcda368 [$800da368]
800BDE78	addu   a1, s2, zero
800BDE7C	addu   a0, s1, zero
800BDE80	jal    funcda368 [$800da368]
800BDE84	addu   a1, s5, zero
800BDE88	lh     v1, $0000(s3)
800BDE8C	nop
800BDE90	sll    v0, v1, $05
800BDE94	addu   v0, v0, v1
800BDE98	sll    v0, v0, $02
800BDE9C	lui    at, $8007
800BDEA0	addiu  at, at, $4f16
800BDEA4	addu   at, at, v0
800BDEA8	lhu    v1, $0000(at)
800BDEAC	nop
800BDEB0	sll    v0, v1, $01
800BDEB4	addu   v0, v0, v1
800BDEB8	lui    v1, $800e
800BDEBC	lw     v1, $4274(v1)
800BDEC0	sll    v0, v0, $03
800BDEC4	addu   v0, v0, v1
800BDEC8	lh     a0, $000c(v0)
800BDECC	jal    funcda480 [$800da480]
800BDED0	addu   a1, s2, zero
800BDED4	addu   a0, s1, zero
800BDED8	jal    funcda368 [$800da368]
800BDEDC	addu   a1, s2, zero
800BDEE0	lui    v0, $8007
800BDEE4	lbu    v0, $1e24(v0)
800BDEE8	lui    v1, $800a
800BDEEC	lbu    v1, $fe8c(v1)
800BDEF0	andi   v0, v0, $0001
800BDEF4	or     v1, v1, v0
800BDEF8	beq    v1, zero, Lbdf0c [$800bdf0c]
800BDEFC	addu   a0, s0, zero
800BDF00	ori    a1, zero, $000c
800BDF04	jal    funcda124 [$800da124]
800BDF08	addu   a2, s1, zero

Lbdf0c:	; 800BDF0C
800BDF0C	lui    v0, $8007
800BDF10	lbu    v0, $1e24(v0)
800BDF14	nop
800BDF18	andi   v0, v0, $0002
800BDF1C	beq    v0, zero, Lbdf2c [$800bdf2c]
800BDF20	nop
800BDF24	jal    funcd4840 [$800d4840]
800BDF28	addu   a0, s1, zero

Lbdf2c:	; 800BDF2C
800BDF2C	lui    a1, $800a
800BDF30	addiu  a1, a1, $029c
800BDF34	jal    funcda334 [$800da334]
800BDF38	addu   a0, s1, zero
800BDF3C	lh     v1, $0000(s3)
800BDF40	nop
800BDF44	sll    v0, v1, $05
800BDF48	addu   v0, v0, v1
800BDF4C	sll    v0, v0, $02
800BDF50	lui    at, $8007
800BDF54	addiu  at, at, $4f16
800BDF58	addu   at, at, v0
800BDF5C	lhu    v1, $0000(at)
800BDF60	nop
800BDF64	sll    v0, v1, $01
800BDF68	addu   v0, v0, v1
800BDF6C	lui    v1, $800e
800BDF70	lw     v1, $4274(v1)
800BDF74	sll    v0, v0, $03
800BDF78	addu   v0, v0, v1
800BDF7C	lh     a0, $0010(v0)
800BDF80	jal    funcda480 [$800da480]
800BDF84	addu   a1, s2, zero
800BDF88	addu   a0, s1, zero
800BDF8C	jal    funcda368 [$800da368]
800BDF90	addu   a1, s2, zero
800BDF94	lui    v0, $8007
800BDF98	lbu    v0, $1e24(v0)
800BDF9C	lui    v1, $800a
800BDFA0	lbu    v1, $fe8c(v1)
800BDFA4	andi   v0, v0, $0001
800BDFA8	or     v1, v1, v0
800BDFAC	beq    v1, zero, Lbdfd8 [$800bdfd8]
800BDFB0	sll    s0, s4, $10
800BDFB4	sra    s0, s0, $10
800BDFB8	addu   a0, s0, zero
800BDFBC	ori    a1, zero, $000d
800BDFC0	jal    funcda124 [$800da124]
800BDFC4	addu   a2, s1, zero
800BDFC8	addu   a0, s0, zero
800BDFCC	ori    a1, zero, $000d
800BDFD0	jal    funcda194 [$800da194]
800BDFD4	ori    a2, zero, $0003

Lbdfd8:	; 800BDFD8
800BDFD8	lui    v0, $8007
800BDFDC	lbu    v0, $1e24(v0)
800BDFE0	nop
800BDFE4	andi   v0, v0, $0002
800BDFE8	beq    v0, zero, Lbdffc [$800bdffc]
800BDFEC	addu   a0, s1, zero
800BDFF0	jal    funcd4840 [$800d4840]
800BDFF4	addu   a0, s1, zero
800BDFF8	addu   a0, s1, zero

Lbdffc:	; 800BDFFC
800BDFFC	jal    funcda334 [$800da334]
800BE000	addu   a1, s7, zero
800BE004	lh     v1, $0000(s3)
800BE008	nop
800BE00C	sll    v0, v1, $05
800BE010	addu   v0, v0, v1
800BE014	sll    v0, v0, $02
800BE018	lui    at, $8007
800BE01C	addiu  at, at, $4f16
800BE020	addu   at, at, v0
800BE024	lhu    v1, $0000(at)
800BE028	nop
800BE02C	sll    v0, v1, $01
800BE030	addu   v0, v0, v1
800BE034	lui    v1, $800e
800BE038	lw     v1, $4274(v1)
800BE03C	sll    v0, v0, $03
800BE040	addu   v0, v0, v1
800BE044	lh     a0, $0012(v0)
800BE048	jal    funcda480 [$800da480]
800BE04C	addu   a1, s2, zero
800BE050	addu   a0, s1, zero
800BE054	jal    funcda368 [$800da368]
800BE058	addu   a1, s2, zero
800BE05C	addu   a0, s1, zero
800BE060	jal    funcda368 [$800da368]
800BE064	addu   a1, s5, zero
800BE068	lh     v1, $0000(s3)
800BE06C	nop
800BE070	sll    v0, v1, $05
800BE074	addu   v0, v0, v1
800BE078	sll    v0, v0, $02
800BE07C	lui    at, $8007
800BE080	addiu  at, at, $4f16
800BE084	addu   at, at, v0
800BE088	lhu    v1, $0000(at)
800BE08C	nop
800BE090	sll    v0, v1, $01
800BE094	addu   v0, v0, v1
800BE098	lui    v1, $800e
800BE09C	lw     v1, $4274(v1)
800BE0A0	sll    v0, v0, $03
800BE0A4	addu   v0, v0, v1
800BE0A8	lh     a0, $0014(v0)
800BE0AC	jal    funcda480 [$800da480]
800BE0B0	addu   a1, s2, zero
800BE0B4	addu   a0, s1, zero
800BE0B8	jal    funcda368 [$800da368]
800BE0BC	addu   a1, s2, zero
800BE0C0	lui    v0, $8007
800BE0C4	lbu    v0, $1e24(v0)
800BE0C8	lui    v1, $800a
800BE0CC	lbu    v1, $fe8c(v1)
800BE0D0	andi   v0, v0, $0001
800BE0D4	or     v1, v1, v0
800BE0D8	beq    v1, zero, Lbe0f0 [$800be0f0]
800BE0DC	sll    a0, s4, $10
800BE0E0	sra    a0, a0, $10
800BE0E4	ori    a1, zero, $000e
800BE0E8	jal    funcda124 [$800da124]
800BE0EC	addu   a2, s1, zero

Lbe0f0:	; 800BE0F0
800BE0F0	lui    v0, $8007
800BE0F4	lbu    v0, $1e24(v0)
800BE0F8	nop
800BE0FC	andi   v0, v0, $0002
800BE100	beq    v0, zero, Lbe110 [$800be110]
800BE104	nop
800BE108	jal    funcd4840 [$800d4840]
800BE10C	addu   a0, s1, zero

Lbe110:	; 800BE110
800BE110	lui    a1, $800a
800BE114	addiu  a1, a1, $02a8
800BE118	jal    funcda334 [$800da334]
800BE11C	addu   a0, s1, zero
800BE120	sll    v0, s6, $10
800BE124	sra    s3, v0, $10
800BE128	lui    at, $8008
800BE12C	addiu  at, at, $eb98 (=-$1468)
800BE130	addu   at, at, s3
800BE134	lbu    v1, $0000(at)
800BE138	nop
800BE13C	sll    v0, v1, $05
800BE140	addu   v0, v0, v1
800BE144	lui    v1, $800a
800BE148	lw     v1, $c544(v1)
800BE14C	sll    v0, v0, $02
800BE150	addu   v0, v0, v1
800BE154	lh     a0, $0040(v0)
800BE158	jal    funcda480 [$800da480]
800BE15C	addu   a1, s2, zero
800BE160	addu   a0, s1, zero
800BE164	jal    funcda368 [$800da368]
800BE168	addu   a1, s2, zero
800BE16C	lui    v0, $8007
800BE170	lbu    v0, $1e24(v0)
800BE174	lui    v1, $800a
800BE178	lbu    v1, $fe8c(v1)
800BE17C	andi   v0, v0, $0001
800BE180	or     v1, v1, v0
800BE184	beq    v1, zero, Lbe1b0 [$800be1b0]
800BE188	sll    s0, s4, $10
800BE18C	sra    s0, s0, $10
800BE190	addu   a0, s0, zero
800BE194	ori    a1, zero, $000f
800BE198	jal    funcda124 [$800da124]
800BE19C	addu   a2, s1, zero
800BE1A0	addu   a0, s0, zero
800BE1A4	ori    a1, zero, $000f
800BE1A8	jal    funcda194 [$800da194]
800BE1AC	ori    a2, zero, $0002

Lbe1b0:	; 800BE1B0
800BE1B0	lui    v0, $8007
800BE1B4	lbu    v0, $1e24(v0)
800BE1B8	nop
800BE1BC	andi   v0, v0, $0002
800BE1C0	beq    v0, zero, Lbe1d4 [$800be1d4]
800BE1C4	addu   a0, s1, zero
800BE1C8	jal    funcd4840 [$800d4840]
800BE1CC	addu   a0, s1, zero
800BE1D0	addu   a0, s1, zero

Lbe1d4:	; 800BE1D4
800BE1D4	jal    funcda334 [$800da334]
800BE1D8	addu   a1, s7, zero
800BE1DC	lui    at, $8008
800BE1E0	addiu  at, at, $eb98 (=-$1468)
800BE1E4	addu   at, at, s3
800BE1E8	lbu    v1, $0000(at)
800BE1EC	nop
800BE1F0	sll    v0, v1, $05
800BE1F4	addu   v0, v0, v1
800BE1F8	lui    v1, $800a
800BE1FC	lw     v1, $c544(v1)
800BE200	sll    v0, v0, $02
800BE204	addu   v0, v0, v1
800BE208	lh     a0, $0046(v0)
800BE20C	jal    funcda480 [$800da480]
800BE210	addu   a1, s2, zero
800BE214	addu   a0, s1, zero
800BE218	jal    funcda368 [$800da368]
800BE21C	addu   a1, s2, zero
800BE220	addu   a0, s1, zero
800BE224	jal    funcda368 [$800da368]
800BE228	addu   a1, s5, zero
800BE22C	lui    at, $8008
800BE230	addiu  at, at, $eb98 (=-$1468)
800BE234	addu   at, at, s3
800BE238	lbu    v1, $0000(at)
800BE23C	nop
800BE240	sll    v0, v1, $05
800BE244	addu   v0, v0, v1
800BE248	lui    v1, $800a
800BE24C	lw     v1, $c544(v1)
800BE250	sll    v0, v0, $02
800BE254	addu   v0, v0, v1
800BE258	lh     a0, $004c(v0)
800BE25C	jal    funcda480 [$800da480]
800BE260	addu   a1, s2, zero
800BE264	addu   a0, s1, zero
800BE268	jal    funcda368 [$800da368]
800BE26C	addu   a1, s2, zero
800BE270	lui    v0, $8007
800BE274	lbu    v0, $1e24(v0)
800BE278	lui    v1, $800a
800BE27C	lbu    v1, $fe8c(v1)
800BE280	andi   v0, v0, $0001
800BE284	or     v1, v1, v0
800BE288	beq    v1, zero, Lbe2a0 [$800be2a0]
800BE28C	sll    a0, s4, $10
800BE290	sra    a0, a0, $10
800BE294	ori    a1, zero, $0010
800BE298	jal    funcda124 [$800da124]
800BE29C	addu   a2, s1, zero

Lbe2a0:	; 800BE2A0
800BE2A0	lui    v0, $8007
800BE2A4	lbu    v0, $1e24(v0)
800BE2A8	nop
800BE2AC	andi   v0, v0, $0002
800BE2B0	beq    v0, zero, Lbe2c0 [$800be2c0]
800BE2B4	nop
800BE2B8	jal    funcd4840 [$800d4840]
800BE2BC	addu   a0, s1, zero

Lbe2c0:	; 800BE2C0
800BE2C0	lui    a1, $800a
800BE2C4	addiu  a1, a1, $02b4
800BE2C8	jal    funcda334 [$800da334]
800BE2CC	addu   a0, s1, zero
800BE2D0	addu   a1, s2, zero
800BE2D4	lui    a0, $800a
800BE2D8	lbu    a0, $d289(a0)
800BE2DC	lui    v0, $800a
800BE2E0	lbu    v0, $d288(v0)
800BE2E4	sll    a0, a0, $08
800BE2E8	jal    funcda480 [$800da480]
800BE2EC	or     a0, v0, a0
800BE2F0	addu   a0, s1, zero
800BE2F4	jal    funcda368 [$800da368]
800BE2F8	addu   a1, s2, zero
800BE2FC	lui    v0, $800a
800BE300	lw     v0, $c6e0(v0)
800BE304	nop
800BE308	lbu    v0, $0032(v0)
800BE30C	nop
800BE310	beq    v0, zero, Lbe34c [$800be34c]
800BE314	nop
800BE318	lui    v0, $8008
800BE31C	lbu    v0, $1dc4(v0)
800BE320	nop
800BE324	beq    v0, zero, Lbe33c [$800be33c]
800BE328	nop
800BE32C	lui    a1, $800a
800BE330	addiu  a1, a1, $0238
800BE334	j      Lbe37c [$800be37c]
800BE338	addu   a0, s1, zero

Lbe33c:	; 800BE33C
800BE33C	lui    a1, $800a
800BE340	addiu  a1, a1, $02b8
800BE344	j      Lbe37c [$800be37c]
800BE348	addu   a0, s1, zero

Lbe34c:	; 800BE34C
800BE34C	lui    v0, $8008
800BE350	lbu    v0, $1dc4(v0)
800BE354	nop
800BE358	beq    v0, zero, Lbe370 [$800be370]
800BE35C	nop
800BE360	lui    a1, $800a
800BE364	addiu  a1, a1, $02bc
800BE368	j      Lbe37c [$800be37c]
800BE36C	addu   a0, s1, zero

Lbe370:	; 800BE370
800BE370	addu   a0, s1, zero
800BE374	lui    a1, $800a
800BE378	addiu  a1, a1, $02c0

Lbe37c:	; 800BE37C
800BE37C	jal    funcda368 [$800da368]
800BE380	nop
800BE384	lui    s1, $800e
800BE388	addiu  s1, s1, $4254
800BE38C	lui    a1, $800a
800BE390	addiu  a1, a1, $02c4
800BE394	jal    funcda368 [$800da368]
800BE398	addu   a0, s1, zero
800BE39C	lui    s0, $800e
800BE3A0	addiu  s0, s0, $4288
800BE3A4	lui    a0, $800a
800BE3A8	lbu    a0, $cbdc(a0)
800BE3AC	jal    funcda424 [$800da424]
800BE3B0	addu   a1, s0, zero
800BE3B4	addu   a0, s1, zero
800BE3B8	jal    funcda368 [$800da368]
800BE3BC	addu   a1, s0, zero
800BE3C0	lui    a0, $800a
800BE3C4	lbu    a0, $cbdd(a0)
800BE3C8	jal    funcda424 [$800da424]
800BE3CC	addu   a1, s0, zero
800BE3D0	addu   a0, s1, zero
800BE3D4	jal    funcda368 [$800da368]
800BE3D8	addu   a1, s0, zero
800BE3DC	lui    a0, $800a
800BE3E0	lbu    a0, $cbde(a0)
800BE3E4	jal    funcda424 [$800da424]
800BE3E8	addu   a1, s0, zero
800BE3EC	addu   a0, s1, zero
800BE3F0	jal    funcda368 [$800da368]
800BE3F4	addu   a1, s0, zero
800BE3F8	lui    v0, $800a
800BE3FC	lw     v0, $c6e0(v0)
800BE400	nop
800BE404	lbu    v0, $003b(v0)
800BE408	nop
800BE40C	beq    v0, zero, Lbe424 [$800be424]
800BE410	addu   a0, s1, zero
800BE414	lui    a1, $800a
800BE418	addiu  a1, a1, $02c8
800BE41C	j      Lbe42c [$800be42c]
800BE420	nop

Lbe424:	; 800BE424
800BE424	lui    a1, $800a
800BE428	addiu  a1, a1, $02c0

Lbe42c:	; 800BE42C
800BE42C	jal    funcda368 [$800da368]
800BE430	nop
800BE434	lui    v0, $8007
800BE438	lbu    v0, $1e24(v0)
800BE43C	lui    v1, $800a
800BE440	lbu    v1, $fe8c(v1)
800BE444	andi   v0, v0, $0001
800BE448	or     v1, v1, v0
800BE44C	beq    v1, zero, Lbe47c [$800be47c]
800BE450	sll    s0, s4, $10
800BE454	sra    s0, s0, $10
800BE458	addu   a0, s0, zero
800BE45C	lui    a2, $800e
800BE460	addiu  a2, a2, $4254
800BE464	jal    funcda124 [$800da124]
800BE468	ori    a1, zero, $0011
800BE46C	addu   a0, s0, zero
800BE470	ori    a1, zero, $0011
800BE474	jal    funcda194 [$800da194]
800BE478	ori    a2, zero, $0006

Lbe47c:	; 800BE47C
800BE47C	lui    v0, $8007
800BE480	lbu    v0, $1e24(v0)
800BE484	nop
800BE488	andi   v0, v0, $0002
800BE48C	beq    v0, zero, Lbe4a4 [$800be4a4]
800BE490	nop
800BE494	lui    a0, $800e
800BE498	addiu  a0, a0, $4254
800BE49C	jal    funcd4840 [$800d4840]
800BE4A0	nop

Lbe4a4:	; 800BE4A4
800BE4A4	lui    s1, $800e
800BE4A8	addiu  s1, s1, $4254
800BE4AC	lui    a1, $800a
800BE4B0	addiu  a1, a1, $02cc
800BE4B4	jal    funcda334 [$800da334]
800BE4B8	addu   a0, s1, zero
800BE4BC	lui    s0, $800e
800BE4C0	addiu  s0, s0, $4288
800BE4C4	lui    a0, $8007
800BE4C8	lhu    a0, $5e12(a0)
800BE4CC	jal    funcda480 [$800da480]
800BE4D0	addu   a1, s0, zero
800BE4D4	addu   a0, s1, zero
800BE4D8	jal    funcda368 [$800da368]
800BE4DC	addu   a1, s0, zero
800BE4E0	lui    a1, $800a
800BE4E4	addiu  a1, a1, $02d0
800BE4E8	jal    funcda368 [$800da368]
800BE4EC	addu   a0, s1, zero
800BE4F0	lui    a0, $8007
800BE4F4	lhu    a0, $5e10(a0)
800BE4F8	jal    funcda480 [$800da480]
800BE4FC	addu   a1, s0, zero
800BE500	addu   a0, s1, zero
800BE504	jal    funcda368 [$800da368]
800BE508	addu   a1, s0, zero
800BE50C	lui    v0, $8007
800BE510	lbu    v0, $16d4(v0)
800BE514	nop
800BE518	beq    v0, zero, Lbe530 [$800be530]
800BE51C	nop
800BE520	lui    a1, $800a
800BE524	addiu  a1, a1, $02d4
800BE528	jal    funcda368 [$800da368]
800BE52C	addu   a0, s1, zero

Lbe530:	; 800BE530
800BE530	lui    v0, $8007
800BE534	lbu    v0, $1e24(v0)
800BE538	lui    v1, $800a
800BE53C	lbu    v1, $fe8c(v1)
800BE540	andi   v0, v0, $0001
800BE544	or     v1, v1, v0
800BE548	beq    v1, zero, Lbe6a0 [$800be6a0]
800BE54C	sll    v0, s4, $10
800BE550	sra    s0, v0, $10
800BE554	addu   a0, s0, zero
800BE558	ori    a1, zero, $0012
800BE55C	jal    funcda124 [$800da124]
800BE560	addu   a2, s1, zero
800BE564	lui    v0, $801a
800BE568	lui    v1, $8007
800BE56C	lw     v1, $5e10(v1)
800BE570	ori    v0, v0, $ffff
800BE574	sltu   v0, v0, v1
800BE578	beq    v0, zero, Lbe5c0 [$800be5c0]
800BE57C	lui    v0, $801a
800BE580	lui    v0, $800a
800BE584	lbu    v0, $d29b(v0)
800BE588	nop
800BE58C	andi   v0, v0, $0010
800BE590	beq    v0, zero, Lbe5a4 [$800be5a4]
800BE594	addu   a0, s0, zero
800BE598	ori    a1, zero, $0012
800BE59C	j      Lbe5ac [$800be5ac]
800BE5A0	ori    a2, zero, $0005

Lbe5a4:	; 800BE5A4
800BE5A4	ori    a1, zero, $0012
800BE5A8	ori    a2, zero, $0003

Lbe5ac:	; 800BE5AC
800BE5AC	jal    funcda194 [$800da194]
800BE5B0	nop
800BE5B4	lui    v0, $801a
800BE5B8	lui    v1, $8007
800BE5BC	lw     v1, $5e10(v1)

Lbe5c0:	; 800BE5C0
800BE5C0	ori    v0, v0, $dfff
800BE5C4	sltu   v0, v0, v1
800BE5C8	beq    v0, zero, Lbe5e0 [$800be5e0]
800BE5CC	sll    a0, s4, $10
800BE5D0	sra    a0, a0, $10
800BE5D4	ori    a1, zero, $0012
800BE5D8	j      Lbe698 [$800be698]
800BE5DC	ori    a2, zero, $0005

Lbe5e0:	; 800BE5E0
800BE5E0	lui    v0, $801a
800BE5E4	ori    v0, v0, $afff
800BE5E8	sltu   v0, v0, v1
800BE5EC	beq    v0, zero, Lbe600 [$800be600]
800BE5F0	sra    a0, a0, $10
800BE5F4	ori    a1, zero, $0012
800BE5F8	j      Lbe698 [$800be698]
800BE5FC	ori    a2, zero, $0004

Lbe600:	; 800BE600
800BE600	lui    v0, $801a
800BE604	ori    v0, v0, $7fff
800BE608	sltu   v0, v0, v1
800BE60C	beq    v0, zero, Lbe624 [$800be624]
800BE610	sll    a0, s4, $10
800BE614	sra    a0, a0, $10
800BE618	ori    a1, zero, $0012
800BE61C	j      Lbe698 [$800be698]
800BE620	ori    a2, zero, $0001

Lbe624:	; 800BE624
800BE624	lui    v0, $801a
800BE628	ori    v0, v0, $3fff
800BE62C	sltu   v0, v0, v1
800BE630	beq    v0, zero, Lbe644 [$800be644]
800BE634	sra    a0, a0, $10
800BE638	ori    a1, zero, $0012
800BE63C	j      Lbe698 [$800be698]
800BE640	ori    a2, zero, $0003

Lbe644:	; 800BE644
800BE644	lui    v0, $8019
800BE648	ori    v0, v0, $ffff
800BE64C	sltu   v0, v0, v1
800BE650	beq    v0, zero, Lbe668 [$800be668]
800BE654	sll    a0, s4, $10
800BE658	sra    a0, a0, $10
800BE65C	ori    a1, zero, $0012
800BE660	j      Lbe698 [$800be698]
800BE664	ori    a2, zero, $0002

Lbe668:	; 800BE668
800BE668	lui    v0, $8019
800BE66C	ori    v0, v0, $7fff
800BE670	sltu   v0, v0, v1
800BE674	beq    v0, zero, Lbe688 [$800be688]
800BE678	sra    a0, a0, $10
800BE67C	ori    a1, zero, $0012
800BE680	j      Lbe698 [$800be698]
800BE684	addu   a2, zero, zero

Lbe688:	; 800BE688
800BE688	sll    a0, s4, $10
800BE68C	sra    a0, a0, $10
800BE690	ori    a1, zero, $0012
800BE694	ori    a2, zero, $0007

Lbe698:	; 800BE698
800BE698	jal    funcda194 [$800da194]
800BE69C	nop

Lbe6a0:	; 800BE6A0
800BE6A0	lui    v0, $8007
800BE6A4	lbu    v0, $1e24(v0)
800BE6A8	nop
800BE6AC	andi   v0, v0, $0002
800BE6B0	beq    v0, zero, Lbe6c8 [$800be6c8]
800BE6B4	nop
800BE6B8	lui    a0, $800e
800BE6BC	addiu  a0, a0, $4254
800BE6C0	jal    funcd4840 [$800d4840]
800BE6C4	nop

Lbe6c8:	; 800BE6C8
800BE6C8	lui    s0, $800e
800BE6CC	addiu  s0, s0, $4288
800BE6D0	lui    a0, $800a
800BE6D4	lbu    a0, $d391(a0)
800BE6D8	jal    funcda424 [$800da424]
800BE6DC	addu   a1, s0, zero
800BE6E0	lui    s1, $800e
800BE6E4	addiu  s1, s1, $4254
800BE6E8	addu   a0, s1, zero
800BE6EC	jal    funcda334 [$800da334]
800BE6F0	addu   a1, s0, zero
800BE6F4	lui    a0, $800a
800BE6F8	lbu    a0, $d392(a0)
800BE6FC	jal    funcda424 [$800da424]
800BE700	addu   a1, s0, zero
800BE704	addu   a0, s1, zero
800BE708	jal    funcda368 [$800da368]
800BE70C	addu   a1, s0, zero
800BE710	lui    a0, $800a
800BE714	lbu    a0, $d393(a0)
800BE718	jal    funcda424 [$800da424]
800BE71C	addu   a1, s0, zero
800BE720	addu   a0, s1, zero
800BE724	jal    funcda368 [$800da368]
800BE728	addu   a1, s0, zero
800BE72C	lui    v0, $800a
800BE730	lhu    v0, $d78a(v0)
800BE734	nop
800BE738	andi   v0, v0, $0001
800BE73C	beq    v0, zero, Lbe754 [$800be754]
800BE740	addu   a0, s1, zero
800BE744	lui    a1, $800a
800BE748	addiu  a1, a1, $02d8
800BE74C	j      Lbe75c [$800be75c]
800BE750	nop

Lbe754:	; 800BE754
800BE754	lui    a1, $800a
800BE758	addiu  a1, a1, $0238

Lbe75c:	; 800BE75C
800BE75C	jal    funcda368 [$800da368]
800BE760	nop
800BE764	lui    v0, $800a
800BE768	lhu    v0, $d78a(v0)
800BE76C	nop
800BE770	andi   v0, v0, $0002
800BE774	beq    v0, zero, Lbe794 [$800be794]
800BE778	nop
800BE77C	lui    a0, $800e
800BE780	addiu  a0, a0, $4254
800BE784	lui    a1, $800a
800BE788	addiu  a1, a1, $02c4
800BE78C	j      Lbe7a4 [$800be7a4]
800BE790	nop

Lbe794:	; 800BE794
800BE794	lui    a0, $800e
800BE798	addiu  a0, a0, $4254
800BE79C	lui    a1, $800a
800BE7A0	addiu  a1, a1, $0238

Lbe7a4:	; 800BE7A4
800BE7A4	jal    funcda368 [$800da368]
800BE7A8	nop
800BE7AC	lui    v0, $800a
800BE7B0	lhu    v0, $d78a(v0)
800BE7B4	nop
800BE7B8	andi   v0, v0, $0004
800BE7BC	beq    v0, zero, Lbe7dc [$800be7dc]
800BE7C0	nop
800BE7C4	lui    a0, $800e
800BE7C8	addiu  a0, a0, $4254
800BE7CC	lui    a1, $800a
800BE7D0	addiu  a1, a1, $0240
800BE7D4	j      Lbe7ec [$800be7ec]
800BE7D8	nop

Lbe7dc:	; 800BE7DC
800BE7DC	lui    a0, $800e
800BE7E0	addiu  a0, a0, $4254
800BE7E4	lui    a1, $800a
800BE7E8	addiu  a1, a1, $0238

Lbe7ec:	; 800BE7EC
800BE7EC	jal    funcda368 [$800da368]
800BE7F0	nop
800BE7F4	lui    v0, $800a
800BE7F8	lhu    v0, $d78a(v0)
800BE7FC	nop
800BE800	andi   v0, v0, $0008
800BE804	beq    v0, zero, Lbe824 [$800be824]
800BE808	nop
800BE80C	lui    a0, $800e
800BE810	addiu  a0, a0, $4254
800BE814	lui    a1, $800a
800BE818	addiu  a1, a1, $02dc
800BE81C	j      Lbe834 [$800be834]
800BE820	nop

Lbe824:	; 800BE824
800BE824	lui    a0, $800e
800BE828	addiu  a0, a0, $4254
800BE82C	lui    a1, $800a
800BE830	addiu  a1, a1, $0238

Lbe834:	; 800BE834
800BE834	jal    funcda368 [$800da368]
800BE838	nop
800BE83C	lui    v0, $800a
800BE840	lhu    v0, $d78a(v0)
800BE844	nop
800BE848	andi   v0, v0, $0010
800BE84C	beq    v0, zero, Lbe86c [$800be86c]
800BE850	nop
800BE854	lui    a0, $800e
800BE858	addiu  a0, a0, $4254
800BE85C	lui    a1, $800a
800BE860	addiu  a1, a1, $02e0
800BE864	j      Lbe87c [$800be87c]
800BE868	nop

Lbe86c:	; 800BE86C
800BE86C	lui    a0, $800e
800BE870	addiu  a0, a0, $4254
800BE874	lui    a1, $800a
800BE878	addiu  a1, a1, $0238

Lbe87c:	; 800BE87C
800BE87C	jal    funcda368 [$800da368]
800BE880	nop
800BE884	lui    v0, $800a
800BE888	lhu    v0, $d78a(v0)
800BE88C	nop
800BE890	andi   v0, v0, $0020
800BE894	beq    v0, zero, Lbe8b4 [$800be8b4]
800BE898	nop
800BE89C	lui    a0, $800e
800BE8A0	addiu  a0, a0, $4254
800BE8A4	lui    a1, $800a
800BE8A8	addiu  a1, a1, $02e4
800BE8AC	j      Lbe8c4 [$800be8c4]
800BE8B0	nop

Lbe8b4:	; 800BE8B4
800BE8B4	lui    a0, $800e
800BE8B8	addiu  a0, a0, $4254
800BE8BC	lui    a1, $800a
800BE8C0	addiu  a1, a1, $0238

Lbe8c4:	; 800BE8C4
800BE8C4	jal    funcda368 [$800da368]
800BE8C8	nop
800BE8CC	lui    v0, $800a
800BE8D0	lhu    v0, $d78a(v0)
800BE8D4	nop
800BE8D8	andi   v0, v0, $0040
800BE8DC	beq    v0, zero, Lbe8fc [$800be8fc]
800BE8E0	nop
800BE8E4	lui    a0, $800e
800BE8E8	addiu  a0, a0, $4254
800BE8EC	lui    a1, $800a
800BE8F0	addiu  a1, a1, $02e8
800BE8F4	j      Lbe90c [$800be90c]
800BE8F8	nop

Lbe8fc:	; 800BE8FC
800BE8FC	lui    a0, $800e
800BE900	addiu  a0, a0, $4254
800BE904	lui    a1, $800a
800BE908	addiu  a1, a1, $0238

Lbe90c:	; 800BE90C
800BE90C	jal    funcda368 [$800da368]
800BE910	nop
800BE914	lui    v0, $800a
800BE918	lhu    v0, $d78a(v0)
800BE91C	nop
800BE920	andi   v0, v0, $0080
800BE924	beq    v0, zero, Lbe944 [$800be944]
800BE928	nop
800BE92C	lui    a0, $800e
800BE930	addiu  a0, a0, $4254
800BE934	lui    a1, $800a
800BE938	addiu  a1, a1, $023c
800BE93C	j      Lbe954 [$800be954]
800BE940	nop

Lbe944:	; 800BE944
800BE944	lui    a0, $800e
800BE948	addiu  a0, a0, $4254
800BE94C	lui    a1, $800a
800BE950	addiu  a1, a1, $0238

Lbe954:	; 800BE954
800BE954	jal    funcda368 [$800da368]
800BE958	nop
800BE95C	lui    v0, $800a
800BE960	lhu    v0, $d78a(v0)
800BE964	nop
800BE968	andi   v0, v0, $0100
800BE96C	beq    v0, zero, Lbe98c [$800be98c]
800BE970	nop
800BE974	lui    a0, $800e
800BE978	addiu  a0, a0, $4254
800BE97C	lui    a1, $800a
800BE980	addiu  a1, a1, $02ec
800BE984	j      Lbe99c [$800be99c]
800BE988	nop

Lbe98c:	; 800BE98C
800BE98C	lui    a0, $800e
800BE990	addiu  a0, a0, $4254
800BE994	lui    a1, $800a
800BE998	addiu  a1, a1, $0238

Lbe99c:	; 800BE99C
800BE99C	jal    funcda368 [$800da368]
800BE9A0	nop
800BE9A4	lui    v0, $800a
800BE9A8	lhu    v0, $d78a(v0)
800BE9AC	nop
800BE9B0	andi   v0, v0, $0200
800BE9B4	beq    v0, zero, Lbe9d4 [$800be9d4]
800BE9B8	nop
800BE9BC	lui    a0, $800e
800BE9C0	addiu  a0, a0, $4254
800BE9C4	lui    a1, $800a
800BE9C8	addiu  a1, a1, $02f0
800BE9CC	j      Lbe9e4 [$800be9e4]
800BE9D0	nop

Lbe9d4:	; 800BE9D4
800BE9D4	lui    a0, $800e
800BE9D8	addiu  a0, a0, $4254
800BE9DC	lui    a1, $800a
800BE9E0	addiu  a1, a1, $0238

Lbe9e4:	; 800BE9E4
800BE9E4	jal    funcda368 [$800da368]
800BE9E8	nop
800BE9EC	lui    v0, $800a
800BE9F0	lhu    v0, $d78a(v0)
800BE9F4	nop
800BE9F8	andi   v0, v0, $0400
800BE9FC	beq    v0, zero, Lbea1c [$800bea1c]
800BEA00	nop
800BEA04	lui    a0, $800e
800BEA08	addiu  a0, a0, $4254
800BEA0C	lui    a1, $800a
800BEA10	addiu  a1, a1, $02f4
800BEA14	j      Lbea2c [$800bea2c]
800BEA18	nop

Lbea1c:	; 800BEA1C
800BEA1C	lui    a0, $800e
800BEA20	addiu  a0, a0, $4254
800BEA24	lui    a1, $800a
800BEA28	addiu  a1, a1, $0238

Lbea2c:	; 800BEA2C
800BEA2C	jal    funcda368 [$800da368]
800BEA30	nop
800BEA34	lui    v0, $8007
800BEA38	lbu    v0, $1e24(v0)
800BEA3C	lui    v1, $800a
800BEA40	lbu    v1, $fe8c(v1)
800BEA44	andi   v0, v0, $0001
800BEA48	or     v1, v1, v0
800BEA4C	beq    v1, zero, Lbea7c [$800bea7c]
800BEA50	sll    s0, s4, $10
800BEA54	sra    s0, s0, $10
800BEA58	addu   a0, s0, zero
800BEA5C	lui    a2, $800e
800BEA60	addiu  a2, a2, $4254
800BEA64	jal    funcda124 [$800da124]
800BEA68	ori    a1, zero, $0013
800BEA6C	addu   a0, s0, zero
800BEA70	ori    a1, zero, $0013
800BEA74	jal    funcda194 [$800da194]
800BEA78	addu   a2, zero, zero

Lbea7c:	; 800BEA7C
800BEA7C	lui    v0, $8007
800BEA80	lbu    v0, $1e24(v0)
800BEA84	nop
800BEA88	andi   v0, v0, $0002
800BEA8C	beq    v0, zero, Lbeaa4 [$800beaa4]
800BEA90	nop
800BEA94	lui    a0, $800e
800BEA98	addiu  a0, a0, $4254
800BEA9C	jal    funcd4840 [$800d4840]
800BEAA0	nop

Lbeaa4:	; 800BEAA4
800BEAA4	lw     ra, $0030(sp)
800BEAA8	lw     s7, $002c(sp)
800BEAAC	lw     s6, $0028(sp)
800BEAB0	lw     s5, $0024(sp)
800BEAB4	lw     s4, $0020(sp)
800BEAB8	lw     s3, $001c(sp)
800BEABC	lw     s2, $0018(sp)
800BEAC0	lw     s1, $0014(sp)
800BEAC4	lw     s0, $0010(sp)
800BEAC8	addiu  sp, sp, $0038
800BEACC	jr     ra 
800BEAD0	nop


funcbead4:	; 800BEAD4
800BEAD4	lui    v0, $8007
800BEAD8	lbu    v0, $1e24(v0)
800BEADC	addiu  sp, sp, $ffd8 (=-$28)
800BEAE0	sw     s2, $0018(sp)
800BEAE4	addu   s2, a0, zero
800BEAE8	sw     s1, $0014(sp)
800BEAEC	addu   s1, a1, zero
800BEAF0	sw     ra, $0024(sp)
800BEAF4	sw     s4, $0020(sp)
800BEAF8	sw     s3, $001c(sp)
800BEAFC	andi   v0, v0, $0004
800BEB00	beq    v0, zero, Lbeb30 [$800beb30]
800BEB04	sw     s0, $0010(sp)
800BEB08	lui    v0, $8007
800BEB0C	lbu    v0, $22c4(v0)
800BEB10	nop
800BEB14	lui    at, $8011
800BEB18	addiu  at, at, $4498
800BEB1C	addu   at, at, v0
800BEB20	lbu    v0, $0000(at)
800BEB24	nop
800BEB28	beq    v0, zero, Lbec80 [$800bec80]
800BEB2C	nop

Lbeb30:	; 800BEB30
800BEB30	lui    s0, $800e
800BEB34	addiu  s0, s0, $4254
800BEB38	lui    a1, $800e
800BEB3C	addiu  a1, a1, $0630
800BEB40	jal    funcda334 [$800da334]
800BEB44	addu   a0, s0, zero
800BEB48	addu   a0, s0, zero
800BEB4C	jal    funcda368 [$800da368]
800BEB50	addu   a1, s2, zero
800BEB54	lui    v0, $800a
800BEB58	lbu    v0, $d820(v0)
800BEB5C	nop
800BEB60	andi   v0, v0, $0001
800BEB64	beq    v0, zero, Lbeb78 [$800beb78]
800BEB68	ori    a0, zero, $0003
800BEB6C	addu   a1, zero, zero
800BEB70	jal    funcda124 [$800da124]
800BEB74	addu   a2, s0, zero

Lbeb78:	; 800BEB78
800BEB78	lui    v0, $800a
800BEB7C	lbu    v0, $d820(v0)
800BEB80	nop
800BEB84	andi   v0, v0, $0002
800BEB88	beq    v0, zero, Lbeb98 [$800beb98]
800BEB8C	addiu  s4, s1, $0001
800BEB90	jal    funcd4840 [$800d4840]
800BEB94	addu   a0, s0, zero

Lbeb98:	; 800BEB98
800BEB98	beq    s1, zero, Lbec80 [$800bec80]
800BEB9C	addu   s2, s0, zero
800BEBA0	lui    s3, $800e
800BEBA4	addiu  s3, s3, $4288

loopbeba8:	; 800BEBA8
800BEBA8	lui    a1, $800a
800BEBAC	addiu  a1, a1, $02f8
800BEBB0	jal    funcda334 [$800da334]
800BEBB4	addu   a0, s2, zero
800BEBB8	subu   s0, s4, s1
800BEBBC	addu   a0, s0, zero
800BEBC0	jal    funcda424 [$800da424]
800BEBC4	addu   a1, s3, zero
800BEBC8	addu   a0, s2, zero
800BEBCC	jal    funcda368 [$800da368]
800BEBD0	addu   a1, s3, zero
800BEBD4	lui    a1, $800a
800BEBD8	addiu  a1, a1, $02fc
800BEBDC	jal    funcda368 [$800da368]
800BEBE0	addu   a0, s2, zero
800BEBE4	lui    v0, $8007
800BEBE8	lbu    v0, $22c4(v0)
800BEBEC	nop
800BEBF0	sll    v0, v0, $01
800BEBF4	lui    at, $8008
800BEBF8	addiu  at, at, $31fc
800BEBFC	addu   at, at, v0
800BEC00	lhu    v1, $0000(at)
800BEC04	lui    v0, $800a
800BEC08	lw     v0, $c6dc(v0)
800BEC0C	nop
800BEC10	addu   v0, v0, v1
800BEC14	addu   v0, v0, s0
800BEC18	lbu    a0, $0000(v0)
800BEC1C	jal    funcda444 [$800da444]
800BEC20	addu   a1, s3, zero
800BEC24	addu   a0, s2, zero
800BEC28	jal    funcda368 [$800da368]
800BEC2C	addu   a1, s3, zero
800BEC30	lui    v0, $800a
800BEC34	lbu    v0, $d820(v0)
800BEC38	nop
800BEC3C	andi   v0, v0, $0001
800BEC40	beq    v0, zero, Lbec58 [$800bec58]
800BEC44	ori    a0, zero, $0003
800BEC48	sll    a1, s0, $10
800BEC4C	sra    a1, a1, $10
800BEC50	jal    funcda124 [$800da124]
800BEC54	addu   a2, s2, zero

Lbec58:	; 800BEC58
800BEC58	lui    v0, $800a
800BEC5C	lbu    v0, $d820(v0)
800BEC60	nop
800BEC64	andi   v0, v0, $0002
800BEC68	beq    v0, zero, Lbec78 [$800bec78]
800BEC6C	addiu  s1, s1, $ffff (=-$1)
800BEC70	jal    funcd4840 [$800d4840]
800BEC74	addu   a0, s2, zero

Lbec78:	; 800BEC78
800BEC78	bne    s1, zero, loopbeba8 [$800beba8]
800BEC7C	nop

Lbec80:	; 800BEC80
800BEC80	lw     ra, $0024(sp)
800BEC84	lw     s4, $0020(sp)
800BEC88	lw     s3, $001c(sp)
800BEC8C	lw     s2, $0018(sp)
800BEC90	lw     s1, $0014(sp)
800BEC94	lw     s0, $0010(sp)
800BEC98	addiu  sp, sp, $0028
800BEC9C	jr     ra 
800BECA0	nop


funcbeca4:	; 800BECA4
800BECA4	addiu  sp, sp, $ffe0 (=-$20)
800BECA8	lui    v0, $8007
800BECAC	lbu    v0, $1e24(v0)
800BECB0	addu   v1, a0, zero
800BECB4	sw     s1, $0014(sp)
800BECB8	addu   s1, a1, zero
800BECBC	sw     s0, $0010(sp)
800BECC0	addu   s0, a2, zero
800BECC4	andi   v0, v0, $0004
800BECC8	beq    v0, zero, Lbecf8 [$800becf8]
800BECCC	sw     ra, $0018(sp)
800BECD0	lui    v0, $8007
800BECD4	lbu    v0, $22c4(v0)
800BECD8	nop
800BECDC	lui    at, $8011
800BECE0	addiu  at, at, $4498
800BECE4	addu   at, at, v0
800BECE8	lbu    v0, $0000(at)
800BECEC	nop
800BECF0	beq    v0, zero, Lbedf8 [$800bedf8]
800BECF4	nop

Lbecf8:	; 800BECF8
800BECF8	lui    a0, $800e
800BECFC	addiu  a0, a0, $4254
800BED00	jal    funcda334 [$800da334]
800BED04	addu   a1, v1, zero
800BED08	ori    v0, zero, $0002
800BED0C	beq    s0, v0, Lbed58 [$800bed58]
800BED10	slti   v0, s0, $0003
800BED14	beq    v0, zero, Lbed2c [$800bed2c]
800BED18	ori    v0, zero, $0001
800BED1C	beq    s0, v0, Lbed40 [$800bed40]
800BED20	nop
800BED24	j      Lbed88 [$800bed88]
800BED28	nop

Lbed2c:	; 800BED2C
800BED2C	ori    v0, zero, $0004
800BED30	beq    s0, v0, Lbed70 [$800bed70]
800BED34	nop
800BED38	j      Lbed88 [$800bed88]
800BED3C	nop

Lbed40:	; 800BED40
800BED40	lui    a1, $800e
800BED44	addiu  a1, a1, $4288
800BED48	jal    funcda424 [$800da424]
800BED4C	addu   a0, s1, zero
800BED50	j      Lbeda0 [$800beda0]
800BED54	nop

Lbed58:	; 800BED58
800BED58	lui    a1, $800e
800BED5C	addiu  a1, a1, $4288
800BED60	jal    funcda444 [$800da444]
800BED64	addu   a0, s1, zero
800BED68	j      Lbeda0 [$800beda0]
800BED6C	nop

Lbed70:	; 800BED70
800BED70	lui    a1, $800e
800BED74	addiu  a1, a1, $4288
800BED78	jal    funcda480 [$800da480]
800BED7C	addu   a0, s1, zero
800BED80	j      Lbeda0 [$800beda0]
800BED84	nop

Lbed88:	; 800BED88
800BED88	lui    a0, $800e
800BED8C	addiu  a0, a0, $4288
800BED90	lui    a1, $800a
800BED94	addiu  a1, a1, $0270
800BED98	jal    funcda334 [$800da334]
800BED9C	nop

Lbeda0:	; 800BEDA0
800BEDA0	lui    s0, $800e
800BEDA4	addiu  s0, s0, $4254
800BEDA8	lui    a1, $800e
800BEDAC	addiu  a1, a1, $4288
800BEDB0	jal    funcda368 [$800da368]
800BEDB4	addu   a0, s0, zero
800BEDB8	lui    v0, $800a
800BEDBC	lbu    v0, $d820(v0)
800BEDC0	nop
800BEDC4	andi   v0, v0, $0001
800BEDC8	beq    v0, zero, Lbedd8 [$800bedd8]
800BEDCC	ori    a0, zero, $0002
800BEDD0	jal    funcd9f00 [$800d9f00]
800BEDD4	addu   a1, s0, zero

Lbedd8:	; 800BEDD8
800BEDD8	lui    v0, $800a
800BEDDC	lbu    v0, $d820(v0)
800BEDE0	nop
800BEDE4	andi   v0, v0, $0002
800BEDE8	beq    v0, zero, Lbedf8 [$800bedf8]
800BEDEC	nop
800BEDF0	jal    funcd4840 [$800d4840]
800BEDF4	addu   a0, s0, zero

Lbedf8:	; 800BEDF8
800BEDF8	lw     ra, $0018(sp)
800BEDFC	lw     s1, $0014(sp)
800BEE00	lw     s0, $0010(sp)
800BEE04	addiu  sp, sp, $0020
800BEE08	jr     ra 
800BEE0C	nop



////////////////////////////////////////////////////////
read_memory_block_one_byte
800BEE10-800BF3A8
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
store_memory_block_one_byte
800BF3AC-800BF904
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
read_memory_block_two_bytes
800BF908-800C0244
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
store_memory_block_two_bytes
800C0248-800C0B50
////////////////////////////////////////////////////////



800C0B54	lui    v0, $800a
800C0B58	lbu    v0, $d820(v0)
800C0B5C	addiu  sp, sp, $ffe8 (=-$18)
800C0B60	sw     ra, $0014(sp)
800C0B64	andi   v0, v0, $0003
800C0B68	beq    v0, zero, Lc0bc0 [$800c0bc0]
800C0B6C	sw     s0, $0010(sp)
800C0B70	lui    a0, $800a
800C0B74	lbu    a0, $a058(a0)
800C0B78	lui    s0, $800e
800C0B7C	addiu  s0, s0, $4288
800C0B80	jal    funcda444 [$800da444]
800C0B84	addu   a1, s0, zero
800C0B88	lui    a1, $800a
800C0B8C	addiu  a1, a1, $04c0
800C0B90	jal    funcda368 [$800da368]
800C0B94	addu   a0, s0, zero
800C0B98	addu   a0, s0, zero
800C0B9C	jal    funcbead4 [$800bead4]
800C0BA0	ori    a1, zero, $0008
800C0BA4	ori    a0, zero, $0003
800C0BA8	ori    a1, zero, $007f
800C0BAC	addu   a2, zero, zero
800C0BB0	jal    funcda214 [$800da214]
800C0BB4	addu   a3, zero, zero
800C0BB8	j      Lc0bd4 [$800c0bd4]
800C0BBC	ori    v0, zero, $0001

Lc0bc0:	; 800C0BC0
800C0BC0	lui    a0, $800a
800C0BC4	addiu  a0, a0, $04c4
800C0BC8	jal    funcd4848 [$800d4848]
800C0BCC	nop
800C0BD0	ori    v0, zero, $0001

Lc0bd4:	; 800C0BD4
800C0BD4	lw     ra, $0014(sp)
800C0BD8	lw     s0, $0010(sp)
800C0BDC	addiu  sp, sp, $0018
800C0BE0	jr     ra 
800C0BE4	nop

800C0BE8	lui    v0, $8007
800C0BEC	lbu    v0, $22c4(v0)
800C0BF0	lui    v1, $8008
800C0BF4	addiu  v1, v1, $31fc
800C0BF8	sll    v0, v0, $01
800C0BFC	addu   v0, v0, v1
800C0C00	lhu    v1, $0000(v0)
800C0C04	nop
800C0C08	addiu  v1, v1, $0001

Lc0c0c:	; 800C0C0C
800C0C0C	sh     v1, $0000(v0)
800C0C10	jr     ra 
800C0C14	ori    v0, zero, $0001

800C0C18	lui    v0, $800a
800C0C1C	lbu    v0, $d820(v0)
800C0C20	addiu  sp, sp, $ffe0 (=-$20)
800C0C24	sw     ra, $0018(sp)
800C0C28	sw     s1, $0014(sp)
800C0C2C	andi   v0, v0, $0003
800C0C30	beq    v0, zero, Lc0c48 [$800c0c48]
800C0C34	sw     s0, $0010(sp)
800C0C38	lui    a0, $800a
800C0C3C	addiu  a0, a0, $04d4

funcc0c40:	; 800C0C40
800C0C40	jal    funcbead4 [$800bead4]
800C0C44	ori    a1, zero, $0002

Lc0c48:	; 800C0C48
800C0C48	lui    v0, $8007
800C0C4C	lbu    v0, $22c4(v0)
800C0C50	lui    s0, $8007
800C0C54	addiu  s0, s0, $16dc
800C0C58	sll    v0, v0, $01
800C0C5C	addu   a2, v0, s0
800C0C60	lhu    a1, $0000(a2)
800C0C64	nop
800C0C68	bne    a1, zero, Lc0d10 [$800c0d10]
800C0C6C	nop
800C0C70	lui    s1, $8008
800C0C74	addiu  s1, s1, $31fc
800C0C78	addu   a1, v0, s1
800C0C7C	lhu    v0, $0000(a1)
800C0C80	lui    v1, $800a
800C0C84	lw     v1, $c6dc(v1)
800C0C88	nop
800C0C8C	addu   v0, v1, v0
800C0C90	lbu    a0, $0001(v0)
800C0C94	nop
800C0C98	sh     a0, $0000(a2)
800C0C9C	lhu    v0, $0000(a1)
800C0CA0	nop
800C0CA4	addu   v1, v1, v0
800C0CA8	lbu    v0, $0002(v1)
800C0CAC	lui    v1, $800a
800C0CB0	lbu    v1, $d820(v1)
800C0CB4	sll    v0, v0, $08
800C0CB8	or     a0, a0, v0
800C0CBC	andi   v1, v1, $0003
800C0CC0	beq    v1, zero, Lc0cdc [$800c0cdc]
800C0CC4	sh     a0, $0000(a2)
800C0CC8	lui    a0, $800a
800C0CCC	addiu  a0, a0, $04dc
800C0CD0	lhu    a1, $0000(a2)
800C0CD4	jal    funcbeca4 [$800beca4]
800C0CD8	ori    a2, zero, $0004

Lc0cdc:	; 800C0CDC
800C0CDC	lui    v0, $8007
800C0CE0	lbu    v0, $22c4(v0)
800C0CE4	nop

Lc0ce8:	; 800C0CE8
800C0CE8	sll    a0, v0, $01
800C0CEC	addu   v0, a0, s0
800C0CF0	lhu    v0, $0000(v0)
800C0CF4	nop
800C0CF8	bne    v0, zero, Lc0dc8 [$800c0dc8]
800C0CFC	ori    v0, zero, $0001
800C0D00	addu   a0, a0, s1
800C0D04	lhu    v1, $0000(a0)
800C0D08	j      Lc0dc4 [$800c0dc4]
800C0D0C	addiu  v1, v1, $0003

Lc0d10:	; 800C0D10
800C0D10	ori    v0, zero, $0001
800C0D14	bne    a1, v0, Lc0d7c [$800c0d7c]
800C0D18	nop
800C0D1C	lui    v0, $800a
800C0D20	lbu    v0, $d820(v0)
800C0D24	nop
800C0D28	andi   v0, v0, $0003
800C0D2C	beq    v0, zero, Lc0d44 [$800c0d44]
800C0D30	ori    a1, zero, $0001
800C0D34	lui    a0, $800a
800C0D38	addiu  a0, a0, $04e8
800C0D3C	jal    funcbeca4 [$800beca4]
800C0D40	ori    a2, zero, $0004

Lc0d44:	; 800C0D44
800C0D44	lui    v1, $8007
800C0D48	lbu    v1, $22c4(v1)
800C0D4C	nop
800C0D50	sll    v1, v1, $01
800C0D54	addu   v0, v1, s0
800C0D58	sh     zero, $0000(v0)
800C0D5C	lui    v0, $8008
800C0D60	addiu  v0, v0, $31fc
800C0D64	addu   v1, v1, v0
800C0D68	lhu    a0, $0000(v1)
800C0D6C	addu   v0, zero, zero
800C0D70	addiu  a0, a0, $0003
800C0D74	j      Lc0dc8 [$800c0dc8]
800C0D78	sh     a0, $0000(v1)

Lc0d7c:	; 800C0D7C
800C0D7C	lui    v0, $800a

funcc0d80:	; 800C0D80
800C0D80	lbu    v0, $d820(v0)
800C0D84	nop
800C0D88	andi   v0, v0, $0003
800C0D8C	beq    v0, zero, Lc0da4 [$800c0da4]
800C0D90	nop
800C0D94	lui    a0, $800a
800C0D98	addiu  a0, a0, $04f4
800C0D9C	jal    funcbeca4 [$800beca4]
800C0DA0	ori    a2, zero, $0004

Lc0da4:	; 800C0DA4
800C0DA4	lui    a0, $8007
800C0DA8	lbu    a0, $22c4(a0)
800C0DAC	nop
800C0DB0	sll    a0, a0, $01
800C0DB4	addu   a0, a0, s0
800C0DB8	lhu    v1, $0000(a0)
800C0DBC	ori    v0, zero, $0001
800C0DC0	addiu  v1, v1, $ffff (=-$1)

Lc0dc4:	; 800C0DC4
800C0DC4	sh     v1, $0000(a0)

Lc0dc8:	; 800C0DC8
800C0DC8	lw     ra, $0018(sp)
800C0DCC	lw     s1, $0014(sp)
800C0DD0	lw     s0, $0010(sp)
800C0DD4	addiu  sp, sp, $0020
800C0DD8	jr     ra 
800C0DDC	nop

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

800C13B0	lui    v0, $800a
800C13B4	lbu    v0, $d820(v0)
800C13B8	addiu  sp, sp, $ffd0 (=-$30)
800C13BC	sw     ra, $002c(sp)
800C13C0	sw     s2, $0028(sp)
800C13C4	sw     s1, $0024(sp)
800C13C8	andi   v0, v0, $0003
800C13CC	beq    v0, zero, Lc13e4 [$800c13e4]
800C13D0	sw     s0, $0020(sp)
800C13D4	lui    a0, $800a
800C13D8	addiu  a0, a0, $05b0
800C13DC	jal    funcbead4 [$800bead4]
800C13E0	ori    a1, zero, $0008

Lc13e4:	; 800C13E4
800C13E4	lui    v0, $8007
800C13E8	lbu    v0, $22c4(v0)
800C13EC	nop
800C13F0	sll    v0, v0, $01
800C13F4	lui    at, $8008
800C13F8	addiu  at, at, $31fc
800C13FC	addu   at, at, v0
800C1400	lhu    v1, $0000(at)
800C1404	lui    v0, $800a
800C1408	lw     v0, $c6dc(v0)
800C140C	ori    a0, zero, $0002
800C1410	addu   v0, v0, v1
800C1414	lbu    s0, $0001(v0)
800C1418	ori    a1, zero, $0005
800C141C	jal    read_memory_block_two_bytes [$800bf908]
800C1420	srl    s0, s0, $04
800C1424	lui    v1, $8007
800C1428	lbu    v1, $22c4(v1)
800C142C	nop
800C1430	sll    v1, v1, $01
800C1434	lui    at, $8008
800C1438	addiu  at, at, $31fc
800C143C	addu   at, at, v1
800C1440	lhu    a1, $0000(at)
800C1444	lui    v1, $800a
800C1448	lw     v1, $c6dc(v1)
800C144C	ori    a0, zero, $0003
800C1450	addu   v1, v1, a1
800C1454	lbu    v1, $0004(v1)
800C1458	ori    a1, zero, $0007
800C145C	jal    read_memory_block_two_bytes [$800bf908]
800C1460	addu   s2, v1, v0
800C1464	lui    v1, $8007
800C1468	lbu    v1, $22c4(v1)
800C146C	nop
800C1470	sll    v1, v1, $01
800C1474	lui    at, $8008
800C1478	addiu  at, at, $31fc
800C147C	addu   at, at, v1
800C1480	lhu    a1, $0000(at)
800C1484	lui    v1, $800a
800C1488	lw     v1, $c6dc(v1)
800C148C	ori    a0, zero, $0004
800C1490	addu   v1, v1, a1
800C1494	lbu    v1, $0004(v1)
800C1498	ori    a1, zero, $0009
800C149C	jal    read_memory_block_one_byte [$800bee10]
800C14A0	addu   s1, v1, v0
800C14A4	addu   a1, v0, zero
800C14A8	addiu  s0, s0, $ffff (=-$1)
800C14AC	sltiu  v0, s0, $000f
800C14B0	beq    v0, zero, Lc161c [$800c161c]
800C14B4	sll    v0, s0, $02
800C14B8	lui    at, $800a
800C14BC	addiu  at, at, $05bc
800C14C0	addu   at, at, v0
800C14C4	lw     v0, $0000(at)
800C14C8	nop
800C14CC	jr     v0 
800C14D0	nop

800C14D4	addiu  s2, s2, $0100
800C14D8	addiu  s1, s1, $0100
800C14DC	addiu  s2, s2, $0100
800C14E0	addiu  s1, s1, $0100
800C14E4	addiu  s2, s2, $0100
800C14E8	addiu  s1, s1, $0100
800C14EC	addiu  s2, s2, $0100
800C14F0	addiu  s1, s1, $0100
800C14F4	sll    v0, s2, $10
800C14F8	sra    v0, v0, $10
800C14FC	slti   v0, v0, $0500
800C1500	bne    v0, zero, Lc150c [$800c150c]
800C1504	sll    v0, s1, $10
800C1508	ori    s2, zero, $04ff

Lc150c:	; 800C150C
800C150C	sra    v0, v0, $10
800C1510	slti   v0, v0, $0500
800C1514	bne    v0, zero, Lc1520 [$800c1520]
800C1518	addu   a0, s2, zero
800C151C	ori    s1, zero, $04ff

Lc1520:	; 800C1520
800C1520	sll    v0, a0, $10
800C1524	sra    v0, v0, $10
800C1528	sll    v1, s1, $10
800C152C	sra    v1, v1, $10
800C1530	slt    v0, v1, v0
800C1534	bne    v0, zero, Lc161c [$800c161c]
800C1538	andi   a1, a1, $00ff
800C153C	sll    v0, a0, $10

loopc1540:	; 800C1540
800C1540	sra    a2, v0, $10
800C1544	lui    at, $800a
800C1548	addiu  at, at, $d288 (=-$2d78)
800C154C	addu   at, at, a2
800C1550	lbu    v0, $0000(at)
800C1554	nop
800C1558	beq    v0, a1, Lc1580 [$800c1580]
800C155C	addiu  v0, a0, $0001
800C1560	addu   a0, v0, zero
800C1564	sll    v0, v0, $10
800C1568	sra    v0, v0, $10
800C156C	slt    v0, v1, v0
800C1570	beq    v0, zero, loopc1540 [$800c1540]
800C1574	sll    v0, a0, $10
800C1578	j      Lc1620 [$800c1620]
800C157C	ori    a0, zero, $0006

Lc1580:	; 800C1580
800C1580	ori    a0, zero, $0006
800C1584	j      Lc1628 [$800c1628]
800C1588	ori    a1, zero, $000a

loopc158c:	; 800C158C
800C158C	ori    a0, zero, $0006
800C1590	j      Lc1628 [$800c1628]
800C1594	ori    a1, zero, $000a
800C1598	sll    v0, s2, $10
800C159C	sra    v0, v0, $10
800C15A0	slti   v0, v0, $0100
800C15A4	bne    v0, zero, Lc15b0 [$800c15b0]
800C15A8	sll    v0, s1, $10
800C15AC	ori    s2, zero, $00ff

Lc15b0:	; 800C15B0
800C15B0	sra    v0, v0, $10
800C15B4	slti   v0, v0, $0100
800C15B8	bne    v0, zero, Lc15c4 [$800c15c4]
800C15BC	addu   a0, s2, zero
800C15C0	ori    s1, zero, $00ff

Lc15c4:	; 800C15C4
800C15C4	sll    v0, a0, $10
800C15C8	sra    v0, v0, $10
800C15CC	sll    v1, s1, $10
800C15D0	sra    v1, v1, $10
800C15D4	slt    v0, v1, v0
800C15D8	bne    v0, zero, Lc161c [$800c161c]
800C15DC	andi   a1, a1, $00ff
800C15E0	sll    v0, a0, $10

loopc15e4:	; 800C15E4
800C15E4	sra    a2, v0, $10
800C15E8	lui    at, $8007
800C15EC	addiu  at, at, $5e24
800C15F0	addu   at, at, a2
800C15F4	lbu    v0, $0000(at)
800C15F8	nop
800C15FC	beq    v0, a1, loopc158c [$800c158c]
800C1600	addiu  v0, a0, $0001
800C1604	addu   a0, v0, zero
800C1608	sll    v0, v0, $10
800C160C	sra    v0, v0, $10
800C1610	slt    v0, v1, v0
800C1614	beq    v0, zero, loopc15e4 [$800c15e4]
800C1618	sll    v0, a0, $10

Lc161c:	; 800C161C
800C161C	ori    a0, zero, $0006

Lc1620:	; 800C1620
800C1620	ori    a1, zero, $000a
800C1624	addiu  a2, zero, $ffff (=-$1)

Lc1628:	; 800C1628
800C1628	jal    store_memory_block_two_bytes [$800c0248]
800C162C	nop
800C1630	lui    v1, $8007
800C1634	lbu    v1, $22c4(v1)
800C1638	lui    v0, $8008
800C163C	addiu  v0, v0, $31fc
800C1640	sll    v1, v1, $01
800C1644	addu   v1, v1, v0
800C1648	lhu    a0, $0000(v1)
800C164C	addu   v0, zero, zero
800C1650	addiu  a0, a0, $000b
800C1654	sh     a0, $0000(v1)
800C1658	lw     ra, $002c(sp)
800C165C	lw     s2, $0028(sp)
800C1660	lw     s1, $0024(sp)
800C1664	lw     s0, $0020(sp)
800C1668	addiu  sp, sp, $0030
800C166C	jr     ra 
800C1670	nop

800C1674	lui    v0, $800a
800C1678	lbu    v0, $d820(v0)
800C167C	addiu  sp, sp, $ffe8 (=-$18)
800C1680	sw     ra, $0014(sp)
800C1684	andi   v0, v0, $0003
800C1688	beq    v0, zero, Lc16a0 [$800c16a0]
800C168C	sw     s0, $0010(sp)
800C1690	lui    a0, $800a
800C1694	addiu  a0, a0, $05f8
800C1698	jal    funcbead4 [$800bead4]
800C169C	ori    a1, zero, $0003

Lc16a0:	; 800C16A0
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



////////////////////////////////////////////////////
// 0xD0 LINE
800C1858-800C1AB0
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// 0xD3 SLINE
800C1AE4-800C1BF0
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// 0xD1 LINON
800C1BF4-800C1D20
////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x2B SLIP
800C1D24-800C1DE0
////////////////////////////////////////////////////////



800C1DE4	lui    v0, $800a
800C1DE8	lbu    v0, $d820(v0)
800C1DEC	addiu  sp, sp, $ffe8 (=-$18)
800C1DF0	andi   v0, v0, $0003
800C1DF4	beq    v0, zero, Lc1e0c [$800c1e0c]
800C1DF8	sw     ra, $0010(sp)
800C1DFC	lui    a0, $800a
800C1E00	addiu  a0, a0, $0640
800C1E04	jal    funcbead4 [$800bead4]
800C1E08	ori    a1, zero, $0005

Lc1e0c:	; 800C1E0C
800C1E0C	jal    funcc2000 [$800c2000]
800C1E10	nop
800C1E14	beq    v0, zero, Lc1e70 [$800c1e70]
800C1E18	nop
800C1E1C	lui    v0, $800a
800C1E20	lbu    v0, $d820(v0)
800C1E24	nop
800C1E28	andi   v0, v0, $0003
800C1E2C	beq    v0, zero, Lc1e44 [$800c1e44]
800C1E30	addu   a1, zero, zero
800C1E34	lui    a0, $800a
800C1E38	addiu  a0, a0, $0644
800C1E3C	jal    funcbeca4 [$800beca4]
800C1E40	addu   a2, zero, zero

Lc1e44:	; 800C1E44
800C1E44	lui    v0, $8007
800C1E48	lbu    v0, $22c4(v0)
800C1E4C	lui    v1, $8008
800C1E50	addiu  v1, v1, $31fc
800C1E54	sll    v0, v0, $01
800C1E58	addu   v0, v0, v1
800C1E5C	lhu    v1, $0000(v0)
800C1E60	nop
800C1E64	addiu  v1, v1, $0006
800C1E68	j      Lc1ed8 [$800c1ed8]
800C1E6C	sh     v1, $0000(v0)

Lc1e70:	; 800C1E70
800C1E70	lui    v0, $800a
800C1E74	lbu    v0, $d820(v0)
800C1E78	nop
800C1E7C	andi   v0, v0, $0003
800C1E80	beq    v0, zero, Lc1e98 [$800c1e98]
800C1E84	addu   a1, zero, zero
800C1E88	lui    a0, $800a
800C1E8C	addiu  a0, a0, $064c
800C1E90	jal    funcbeca4 [$800beca4]
800C1E94	addu   a2, zero, zero

Lc1e98:	; 800C1E98
800C1E98	lui    a0, $8007
800C1E9C	lbu    a0, $22c4(a0)
800C1EA0	lui    v0, $8008
800C1EA4	addiu  v0, v0, $31fc
800C1EA8	sll    a0, a0, $01
800C1EAC	addu   a0, a0, v0
800C1EB0	lhu    v1, $0000(a0)
800C1EB4	lui    v0, $800a
800C1EB8	lw     v0, $c6dc(v0)
800C1EBC	nop
800C1EC0	addu   v0, v0, v1
800C1EC4	lhu    v1, $0000(a0)
800C1EC8	lbu    v0, $0005(v0)
800C1ECC	addiu  v1, v1, $0005
800C1ED0	addu   v0, v0, v1
800C1ED4	sh     v0, $0000(a0)

Lc1ed8:	; 800C1ED8
800C1ED8	addu   v0, zero, zero
800C1EDC	lw     ra, $0010(sp)
800C1EE0	addiu  sp, sp, $0018
800C1EE4	jr     ra 
800C1EE8	nop

800C1EEC	lui    v0, $800a
800C1EF0	lbu    v0, $d820(v0)
800C1EF4	addiu  sp, sp, $ffe8 (=-$18)
800C1EF8	andi   v0, v0, $0003
800C1EFC	beq    v0, zero, Lc1f14 [$800c1f14]
800C1F00	sw     ra, $0010(sp)
800C1F04	lui    a0, $800a
800C1F08	addiu  a0, a0, $0658
800C1F0C	jal    funcbead4 [$800bead4]
800C1F10	ori    a1, zero, $0006

Lc1f14:	; 800C1F14
800C1F14	jal    funcc2000 [$800c2000]
800C1F18	nop
800C1F1C	beq    v0, zero, Lc1f78 [$800c1f78]
800C1F20	nop
800C1F24	lui    v0, $800a
800C1F28	lbu    v0, $d820(v0)
800C1F2C	nop
800C1F30	andi   v0, v0, $0003
800C1F34	beq    v0, zero, Lc1f4c [$800c1f4c]
800C1F38	addu   a1, zero, zero
800C1F3C	lui    a0, $800a
800C1F40	addiu  a0, a0, $065c
800C1F44	jal    funcbeca4 [$800beca4]
800C1F48	addu   a2, zero, zero

Lc1f4c:	; 800C1F4C
800C1F4C	lui    v0, $8007
800C1F50	lbu    v0, $22c4(v0)
800C1F54	lui    v1, $8008
800C1F58	addiu  v1, v1, $31fc
800C1F5C	sll    v0, v0, $01
800C1F60	addu   v0, v0, v1
800C1F64	lhu    v1, $0000(v0)
800C1F68	nop
800C1F6C	addiu  v1, v1, $0007
800C1F70	j      Lc1fec [$800c1fec]
800C1F74	sh     v1, $0000(v0)

Lc1f78:	; 800C1F78
800C1F78	lui    v0, $800a
800C1F7C	lbu    v0, $d820(v0)
800C1F80	nop
800C1F84	andi   v0, v0, $0003
800C1F88	beq    v0, zero, Lc1fa0 [$800c1fa0]
800C1F8C	addu   a1, zero, zero
800C1F90	lui    a0, $800a
800C1F94	addiu  a0, a0, $0668
800C1F98	jal    funcbeca4 [$800beca4]
800C1F9C	addu   a2, zero, zero

Lc1fa0:	; 800C1FA0
800C1FA0	lui    a1, $8007
800C1FA4	lbu    a1, $22c4(a1)
800C1FA8	lui    v0, $8008
800C1FAC	addiu  v0, v0, $31fc
800C1FB0	sll    a1, a1, $01
800C1FB4	addu   a1, a1, v0
800C1FB8	lhu    v1, $0000(a1)
800C1FBC	lui    v0, $800a
800C1FC0	lw     v0, $c6dc(v0)
800C1FC4	nop
800C1FC8	addu   v0, v0, v1
800C1FCC	lbu    v1, $0006(v0)
800C1FD0	lbu    a0, $0005(v0)
800C1FD4	lhu    v0, $0000(a1)
800C1FD8	sll    v1, v1, $08
800C1FDC	or     a0, a0, v1
800C1FE0	addiu  a0, a0, $0005
800C1FE4	addu   v0, v0, a0
800C1FE8	sh     v0, $0000(a1)

Lc1fec:	; 800C1FEC
800C1FEC	addu   v0, zero, zero
800C1FF0	lw     ra, $0010(sp)
800C1FF4	addiu  sp, sp, $0018

Lc1ff8:	; 800C1FF8
800C1FF8	jr     ra 

Lc1ffc:	; 800C1FFC
800C1FFC	nop


funcc2000:	; 800C2000
800C2000	lui    v0, $8007
800C2004	lbu    v0, $22c4(v0)
800C2008	addiu  sp, sp, $ffe8 (=-$18)
800C200C	sw     ra, $0014(sp)
800C2010	sw     s0, $0010(sp)

Lc2014:	; 800C2014
800C2014	sll    v0, v0, $01
800C2018	lui    at, $8008
800C201C	addiu  at, at, $31fc
800C2020	addu   at, at, v0
800C2024	lhu    v1, $0000(at)
800C2028	lui    v0, $800a
800C202C	lw     v0, $c6dc(v0)
800C2030	nop
800C2034	addu   v0, v0, v1
800C2038	lbu    a1, $0004(v0)
800C203C	nop
800C2040	sltiu  v0, a1, $000b
800C2044	beq    v0, zero, Lc224c [$800c224c]
800C2048	sll    v0, a1, $02
800C204C	lui    at, $800a
800C2050	addiu  at, at, $0684
800C2054	addu   at, at, v0
800C2058	lw     v0, $0000(at)
800C205C	nop
800C2060	jr     v0 
800C2064	nop

800C2068	ori    a0, zero, $0001
800C206C	jal    read_memory_block_one_byte [$800bee10]
800C2070	ori    a1, zero, $0002
800C2074	ori    a0, zero, $0002
800C2078	ori    a1, zero, $0003
800C207C	jal    read_memory_block_one_byte [$800bee10]
800C2080	addu   s0, v0, zero
800C2084	xor    s0, s0, v0
800C2088	andi   s0, s0, $00ff
800C208C	j      Lc2274 [$800c2274]
800C2090	sltiu  s0, s0, $0001
800C2094	ori    a0, zero, $0001
800C2098	jal    read_memory_block_one_byte [$800bee10]
800C209C	ori    a1, zero, $0002
800C20A0	ori    a0, zero, $0002
800C20A4	ori    a1, zero, $0003
800C20A8	jal    read_memory_block_one_byte [$800bee10]
800C20AC	addu   s0, v0, zero
800C20B0	xor    s0, s0, v0
800C20B4	andi   s0, s0, $00ff
800C20B8	j      Lc2274 [$800c2274]
800C20BC	sltu   s0, zero, s0
800C20C0	ori    a0, zero, $0001
800C20C4	jal    read_memory_block_one_byte [$800bee10]
800C20C8	ori    a1, zero, $0002
800C20CC	ori    a0, zero, $0002
800C20D0	ori    a1, zero, $0003
800C20D4	jal    read_memory_block_one_byte [$800bee10]
800C20D8	addu   s0, v0, zero
800C20DC	andi   s0, s0, $00ff
800C20E0	andi   v0, v0, $00ff
800C20E4	sltu   v0, v0, s0
800C20E8	j      Lc2274 [$800c2274]
800C20EC	addu   s0, v0, zero
800C20F0	ori    a0, zero, $0001
800C20F4	jal    read_memory_block_one_byte [$800bee10]
800C20F8	ori    a1, zero, $0002
800C20FC	ori    a0, zero, $0002
800C2100	ori    a1, zero, $0003
800C2104	jal    read_memory_block_one_byte [$800bee10]
800C2108	addu   s0, v0, zero
800C210C	andi   s0, s0, $00ff
800C2110	andi   v0, v0, $00ff
800C2114	j      Lc2274 [$800c2274]
800C2118	sltu   s0, s0, v0
800C211C	ori    a0, zero, $0001
800C2120	jal    read_memory_block_one_byte [$800bee10]
800C2124	ori    a1, zero, $0002
800C2128	ori    a0, zero, $0002
800C212C	ori    a1, zero, $0003
800C2130	jal    read_memory_block_one_byte [$800bee10]
800C2134	addu   s0, v0, zero
800C2138	andi   s0, s0, $00ff
800C213C	andi   v0, v0, $00ff
800C2140	sltu   s0, s0, v0
800C2144	j      Lc2274 [$800c2274]
800C2148	xori   s0, s0, $0001
800C214C	ori    a0, zero, $0001
800C2150	jal    read_memory_block_one_byte [$800bee10]
800C2154	ori    a1, zero, $0002
800C2158	ori    a0, zero, $0002
800C215C	ori    a1, zero, $0003
800C2160	jal    read_memory_block_one_byte [$800bee10]
800C2164	addu   s0, v0, zero
800C2168	andi   s0, s0, $00ff
800C216C	andi   v0, v0, $00ff
800C2170	sltu   v0, v0, s0
800C2174	j      Lc2274 [$800c2274]
800C2178	xori   s0, v0, $0001
800C217C	ori    a0, zero, $0001
800C2180	jal    read_memory_block_one_byte [$800bee10]
800C2184	ori    a1, zero, $0002
800C2188	ori    a0, zero, $0002
800C218C	ori    a1, zero, $0003
800C2190	jal    read_memory_block_one_byte [$800bee10]
800C2194	addu   s0, v0, zero
800C2198	j      Lc2274 [$800c2274]
800C219C	and    s0, s0, v0
800C21A0	ori    a0, zero, $0001
800C21A4	jal    read_memory_block_one_byte [$800bee10]
800C21A8	ori    a1, zero, $0002
800C21AC	ori    a0, zero, $0002
800C21B0	ori    a1, zero, $0003
800C21B4	jal    read_memory_block_one_byte [$800bee10]
800C21B8	addu   s0, v0, zero
800C21BC	j      Lc2274 [$800c2274]
800C21C0	xor    s0, s0, v0
800C21C4	ori    a0, zero, $0001
800C21C8	jal    read_memory_block_one_byte [$800bee10]
800C21CC	ori    a1, zero, $0002
800C21D0	ori    a0, zero, $0002
800C21D4	ori    a1, zero, $0003
800C21D8	jal    read_memory_block_one_byte [$800bee10]
800C21DC	addu   s0, v0, zero
800C21E0	j      Lc2274 [$800c2274]
800C21E4	or     s0, s0, v0
800C21E8	ori    a0, zero, $0001
800C21EC	jal    read_memory_block_one_byte [$800bee10]
800C21F0	ori    a1, zero, $0002
800C21F4	ori    a0, zero, $0002
800C21F8	ori    a1, zero, $0003
800C21FC	jal    read_memory_block_one_byte [$800bee10]
800C2200	addu   s0, v0, zero
800C2204	ori    v1, zero, $0001
800C2208	sllv   v1, v0, v1
800C220C	j      Lc2274 [$800c2274]
800C2210	and    s0, s0, v1
800C2214	ori    a0, zero, $0001
800C2218	jal    read_memory_block_one_byte [$800bee10]
800C221C	ori    a1, zero, $0002
800C2220	ori    a0, zero, $0002
800C2224	ori    a1, zero, $0003
800C2228	jal    read_memory_block_one_byte [$800bee10]
800C222C	addu   s0, v0, zero
800C2230	ori    v1, zero, $0001
800C2234	sllv   v1, v0, v1
800C2238	and    s0, s0, v1
800C223C	andi   v0, s0, $00ff
800C2240	sltiu  v0, v0, $0001
800C2244	j      Lc2274 [$800c2274]
800C2248	addu   s0, v0, zero

Lc224c:	; 800C224C
800C224C	lui    v0, $800a
800C2250	lbu    v0, $d820(v0)
800C2254	nop
800C2258	andi   v0, v0, $0003
800C225C	beq    v0, zero, Lc2278 [$800c2278]
800C2260	andi   v0, s0, $00ff
800C2264	lui    a0, $800a
800C2268	addiu  a0, a0, $0674
800C226C	jal    funcbeca4 [$800beca4]
800C2270	ori    a2, zero, $0002

Lc2274:	; 800C2274
800C2274	andi   v0, s0, $00ff

Lc2278:	; 800C2278
800C2278	lw     ra, $0014(sp)
800C227C	lw     s0, $0010(sp)
800C2280	addiu  sp, sp, $0018
800C2284	jr     ra 
800C2288	nop

800C228C	lui    v0, $800a
800C2290	lbu    v0, $d820(v0)
800C2294	addiu  sp, sp, $ffe8 (=-$18)
800C2298	andi   v0, v0, $0003
800C229C	beq    v0, zero, Lc22b4 [$800c22b4]
800C22A0	sw     ra, $0010(sp)
800C22A4	lui    a0, $800a
800C22A8	addiu  a0, a0, $06b0
800C22AC	jal    funcbead4 [$800bead4]
800C22B0	ori    a1, zero, $0007

Lc22b4:	; 800C22B4
800C22B4	jal    funcc24a8 [$800c24a8]
800C22B8	nop
800C22BC	beq    v0, zero, Lc2318 [$800c2318]
800C22C0	nop
800C22C4	lui    v0, $800a
800C22C8	lbu    v0, $d820(v0)
800C22CC	nop
800C22D0	andi   v0, v0, $0003
800C22D4	beq    v0, zero, Lc22ec [$800c22ec]
800C22D8	addu   a1, zero, zero
800C22DC	lui    a0, $800a
800C22E0	addiu  a0, a0, $06b4
800C22E4	jal    funcbeca4 [$800beca4]
800C22E8	addu   a2, zero, zero

Lc22ec:	; 800C22EC
800C22EC	lui    v0, $8007
800C22F0	lbu    v0, $22c4(v0)
800C22F4	lui    v1, $8008
800C22F8	addiu  v1, v1, $31fc
800C22FC	sll    v0, v0, $01
800C2300	addu   v0, v0, v1
800C2304	lhu    v1, $0000(v0)
800C2308	nop
800C230C	addiu  v1, v1, $0008
800C2310	j      Lc2380 [$800c2380]
800C2314	sh     v1, $0000(v0)

Lc2318:	; 800C2318
800C2318	lui    v0, $800a
800C231C	lbu    v0, $d820(v0)
800C2320	nop
800C2324	andi   v0, v0, $0003
800C2328	beq    v0, zero, Lc2340 [$800c2340]
800C232C	addu   a1, zero, zero
800C2330	lui    a0, $800a
800C2334	addiu  a0, a0, $06c0
800C2338	jal    funcbeca4 [$800beca4]
800C233C	addu   a2, zero, zero

Lc2340:	; 800C2340
800C2340	lui    a0, $8007
800C2344	lbu    a0, $22c4(a0)
800C2348	lui    v0, $8008
800C234C	addiu  v0, v0, $31fc
800C2350	sll    a0, a0, $01
800C2354	addu   a0, a0, v0
800C2358	lhu    v1, $0000(a0)
800C235C	lui    v0, $800a
800C2360	lw     v0, $c6dc(v0)
800C2364	nop
800C2368	addu   v0, v0, v1
800C236C	lhu    v1, $0000(a0)
800C2370	lbu    v0, $0007(v0)
800C2374	addiu  v1, v1, $0007
800C2378	addu   v0, v0, v1
800C237C	sh     v0, $0000(a0)

Lc2380:	; 800C2380
800C2380	addu   v0, zero, zero
800C2384	lw     ra, $0010(sp)
800C2388	addiu  sp, sp, $0018
800C238C	jr     ra 
800C2390	nop

800C2394	lui    v0, $800a
800C2398	lbu    v0, $d820(v0)
800C239C	addiu  sp, sp, $ffe8 (=-$18)
800C23A0	andi   v0, v0, $0003
800C23A4	beq    v0, zero, Lc23bc [$800c23bc]
800C23A8	sw     ra, $0010(sp)
800C23AC	lui    a0, $800a
800C23B0	addiu  a0, a0, $06cc
800C23B4	jal    funcbead4 [$800bead4]
800C23B8	ori    a1, zero, $0008

Lc23bc:	; 800C23BC
800C23BC	jal    funcc24a8 [$800c24a8]
800C23C0	nop
800C23C4	beq    v0, zero, Lc2420 [$800c2420]
800C23C8	nop
800C23CC	lui    v0, $800a
800C23D0	lbu    v0, $d820(v0)
800C23D4	nop
800C23D8	andi   v0, v0, $0003
800C23DC	beq    v0, zero, Lc23f4 [$800c23f4]
800C23E0	addu   a1, zero, zero
800C23E4	lui    a0, $800a
800C23E8	addiu  a0, a0, $06d4
800C23EC	jal    funcbeca4 [$800beca4]
800C23F0	addu   a2, zero, zero

Lc23f4:	; 800C23F4
800C23F4	lui    v0, $8007
800C23F8	lbu    v0, $22c4(v0)
800C23FC	lui    v1, $8008
800C2400	addiu  v1, v1, $31fc
800C2404	sll    v0, v0, $01

Lc2408:	; 800C2408
800C2408	addu   v0, v0, v1
800C240C	lhu    v1, $0000(v0)
800C2410	nop
800C2414	addiu  v1, v1, $0009
800C2418	j      Lc2494 [$800c2494]

funcc241c:	; 800C241C
800C241C	sh     v1, $0000(v0)

Lc2420:	; 800C2420
800C2420	lui    v0, $800a
800C2424	lbu    v0, $d820(v0)
800C2428	nop
800C242C	andi   v0, v0, $0003
800C2430	beq    v0, zero, Lc2448 [$800c2448]
800C2434	addu   a1, zero, zero
800C2438	lui    a0, $800a
800C243C	addiu  a0, a0, $06e0
800C2440	jal    funcbeca4 [$800beca4]
800C2444	addu   a2, zero, zero

Lc2448:	; 800C2448
800C2448	lui    a1, $8007
800C244C	lbu    a1, $22c4(a1)
800C2450	lui    v0, $8008
800C2454	addiu  v0, v0, $31fc
800C2458	sll    a1, a1, $01
800C245C	addu   a1, a1, v0
800C2460	lhu    v1, $0000(a1)
800C2464	lui    v0, $800a
800C2468	lw     v0, $c6dc(v0)
800C246C	nop
800C2470	addu   v0, v0, v1
800C2474	lbu    v1, $0008(v0)
800C2478	lbu    a0, $0007(v0)
800C247C	lhu    v0, $0000(a1)
800C2480	sll    v1, v1, $08
800C2484	or     a0, a0, v1
800C2488	addiu  a0, a0, $0007
800C248C	addu   v0, v0, a0
800C2490	sh     v0, $0000(a1)

Lc2494:	; 800C2494
800C2494	addu   v0, zero, zero
800C2498	lw     ra, $0010(sp)
800C249C	addiu  sp, sp, $0018
800C24A0	jr     ra 
800C24A4	nop


funcc24a8:	; 800C24A8
800C24A8	lui    v0, $8007
800C24AC	lbu    v0, $22c4(v0)
800C24B0	addiu  sp, sp, $ffe8 (=-$18)
800C24B4	sw     ra, $0014(sp)
800C24B8	sw     s0, $0010(sp)
800C24BC	sll    v0, v0, $01
800C24C0	lui    at, $8008
800C24C4	addiu  at, at, $31fc
800C24C8	addu   at, at, v0
800C24CC	lhu    v1, $0000(at)
800C24D0	lui    v0, $800a
800C24D4	lw     v0, $c6dc(v0)
800C24D8	nop
800C24DC	addu   v0, v0, v1
800C24E0	lbu    a1, $0006(v0)
800C24E4	nop
800C24E8	sltiu  v0, a1, $000b
800C24EC	beq    v0, zero, Lc2714 [$800c2714]
800C24F0	sll    v0, a1, $02
800C24F4	lui    at, $800a
800C24F8	addiu  at, at, $06ec
800C24FC	addu   at, at, v0
800C2500	lw     v0, $0000(at)
800C2504	nop
800C2508	jr     v0 
800C250C	nop

800C2510	ori    a0, zero, $0001
800C2514	jal    read_memory_block_two_bytes [$800bf908]
800C2518	ori    a1, zero, $0002
800C251C	ori    a0, zero, $0002
800C2520	ori    a1, zero, $0004
800C2524	jal    read_memory_block_two_bytes [$800bf908]
800C2528	addu   s0, v0, zero
800C252C	xor    s0, s0, v0
800C2530	sll    s0, s0, $10
800C2534	j      Lc273c [$800c273c]
800C2538	sltiu  s0, s0, $0001
800C253C	ori    a0, zero, $0001
800C2540	jal    read_memory_block_two_bytes [$800bf908]
800C2544	ori    a1, zero, $0002
800C2548	ori    a0, zero, $0002
800C254C	ori    a1, zero, $0004
800C2550	jal    read_memory_block_two_bytes [$800bf908]
800C2554	addu   s0, v0, zero
800C2558	xor    s0, s0, v0
800C255C	sll    s0, s0, $10
800C2560	j      Lc273c [$800c273c]
800C2564	sltu   s0, zero, s0
800C2568	ori    a0, zero, $0001
800C256C	jal    read_memory_block_two_bytes [$800bf908]
800C2570	ori    a1, zero, $0002
800C2574	ori    a0, zero, $0002
800C2578	ori    a1, zero, $0004
800C257C	jal    read_memory_block_two_bytes [$800bf908]
800C2580	addu   s0, v0, zero
800C2584	sll    s0, s0, $10
800C2588	sra    s0, s0, $10
800C258C	sll    v0, v0, $10
800C2590	sra    v0, v0, $10
800C2594	slt    v0, v0, s0
800C2598	j      Lc273c [$800c273c]
800C259C	addu   s0, v0, zero
800C25A0	ori    a0, zero, $0001
800C25A4	jal    read_memory_block_two_bytes [$800bf908]
800C25A8	ori    a1, zero, $0002
800C25AC	ori    a0, zero, $0002
800C25B0	ori    a1, zero, $0004
800C25B4	jal    read_memory_block_two_bytes [$800bf908]
800C25B8	addu   s0, v0, zero
800C25BC	sll    s0, s0, $10
800C25C0	sra    s0, s0, $10
800C25C4	sll    v0, v0, $10
800C25C8	sra    v0, v0, $10
800C25CC	j      Lc273c [$800c273c]
800C25D0	slt    s0, s0, v0
800C25D4	ori    a0, zero, $0001
800C25D8	jal    read_memory_block_two_bytes [$800bf908]
800C25DC	ori    a1, zero, $0002
800C25E0	ori    a0, zero, $0002
800C25E4	ori    a1, zero, $0004
800C25E8	jal    read_memory_block_two_bytes [$800bf908]
800C25EC	addu   s0, v0, zero
800C25F0	sll    s0, s0, $10
800C25F4	sra    s0, s0, $10
800C25F8	sll    v0, v0, $10
800C25FC	sra    v0, v0, $10
800C2600	slt    s0, s0, v0
800C2604	j      Lc273c [$800c273c]
800C2608	xori   s0, s0, $0001
800C260C	ori    a0, zero, $0001
800C2610	jal    read_memory_block_two_bytes [$800bf908]
800C2614	ori    a1, zero, $0002
800C2618	ori    a0, zero, $0002
800C261C	ori    a1, zero, $0004
800C2620	jal    read_memory_block_two_bytes [$800bf908]
800C2624	addu   s0, v0, zero
800C2628	sll    s0, s0, $10
800C262C	sra    s0, s0, $10
800C2630	sll    v0, v0, $10
800C2634	sra    v0, v0, $10
800C2638	slt    v0, v0, s0
800C263C	j      Lc273c [$800c273c]
800C2640	xori   s0, v0, $0001
800C2644	ori    a0, zero, $0001
800C2648	jal    read_memory_block_two_bytes [$800bf908]
800C264C	ori    a1, zero, $0002
800C2650	ori    a0, zero, $0002
800C2654	ori    a1, zero, $0004
800C2658	jal    read_memory_block_two_bytes [$800bf908]
800C265C	addu   s0, v0, zero
800C2660	j      Lc273c [$800c273c]
800C2664	and    s0, s0, v0
800C2668	ori    a0, zero, $0001
800C266C	jal    read_memory_block_two_bytes [$800bf908]
800C2670	ori    a1, zero, $0002
800C2674	ori    a0, zero, $0002
800C2678	ori    a1, zero, $0004
800C267C	jal    read_memory_block_two_bytes [$800bf908]
800C2680	addu   s0, v0, zero
800C2684	j      Lc273c [$800c273c]
800C2688	xor    s0, s0, v0
800C268C	ori    a0, zero, $0001
800C2690	jal    read_memory_block_two_bytes [$800bf908]
800C2694	ori    a1, zero, $0002
800C2698	ori    a0, zero, $0002
800C269C	ori    a1, zero, $0004
800C26A0	jal    read_memory_block_two_bytes [$800bf908]
800C26A4	addu   s0, v0, zero
800C26A8	j      Lc273c [$800c273c]
800C26AC	or     s0, s0, v0
800C26B0	ori    a0, zero, $0001
800C26B4	jal    read_memory_block_two_bytes [$800bf908]
800C26B8	ori    a1, zero, $0002
800C26BC	ori    a0, zero, $0002
800C26C0	ori    a1, zero, $0004
800C26C4	jal    read_memory_block_two_bytes [$800bf908]
800C26C8	addu   s0, v0, zero
800C26CC	ori    v1, zero, $0001
800C26D0	sllv   v1, v0, v1
800C26D4	j      Lc273c [$800c273c]
800C26D8	and    s0, s0, v1
800C26DC	ori    a0, zero, $0001
800C26E0	jal    read_memory_block_two_bytes [$800bf908]
800C26E4	ori    a1, zero, $0002
800C26E8	ori    a0, zero, $0002
800C26EC	ori    a1, zero, $0004
800C26F0	jal    read_memory_block_two_bytes [$800bf908]
800C26F4	addu   s0, v0, zero
800C26F8	ori    v1, zero, $0001
800C26FC	sllv   v1, v0, v1
800C2700	and    s0, s0, v1
800C2704	andi   v0, s0, $00ff
800C2708	sltiu  v0, v0, $0001
800C270C	j      Lc273c [$800c273c]
800C2710	addu   s0, v0, zero

Lc2714:	; 800C2714
800C2714	lui    v0, $800a
800C2718	lbu    v0, $d820(v0)
800C271C	nop
800C2720	andi   v0, v0, $0003
800C2724	beq    v0, zero, Lc2740 [$800c2740]
800C2728	andi   v0, s0, $00ff
800C272C	lui    a0, $800a
800C2730	addiu  a0, a0, $0674
800C2734	jal    funcbeca4 [$800beca4]
800C2738	ori    a2, zero, $0002

Lc273c:	; 800C273C
800C273C	andi   v0, s0, $00ff

Lc2740:	; 800C2740
800C2740	lw     ra, $0014(sp)
800C2744	lw     s0, $0010(sp)
800C2748	addiu  sp, sp, $0018
800C274C	jr     ra 
800C2750	nop

800C2754	lui    v0, $800a
800C2758	lbu    v0, $d820(v0)
800C275C	addiu  sp, sp, $ffe8 (=-$18)
800C2760	andi   v0, v0, $0003
800C2764	beq    v0, zero, Lc277c [$800c277c]
800C2768	sw     ra, $0010(sp)
800C276C	lui    a0, $800a
800C2770	addiu  a0, a0, $06b0
800C2774	jal    funcbead4 [$800bead4]
800C2778	ori    a1, zero, $0007

Lc277c:	; 800C277C
800C277C	jal    funcc2970 [$800c2970]
800C2780	nop
800C2784	beq    v0, zero, Lc27e0 [$800c27e0]
800C2788	nop
800C278C	lui    v0, $800a
800C2790	lbu    v0, $d820(v0)
800C2794	nop
800C2798	andi   v0, v0, $0003
800C279C	beq    v0, zero, Lc27b4 [$800c27b4]
800C27A0	addu   a1, zero, zero
800C27A4	lui    a0, $800a
800C27A8	addiu  a0, a0, $06b4
800C27AC	jal    funcbeca4 [$800beca4]
800C27B0	addu   a2, zero, zero

Lc27b4:	; 800C27B4
800C27B4	lui    v0, $8007
800C27B8	lbu    v0, $22c4(v0)
800C27BC	lui    v1, $8008
800C27C0	addiu  v1, v1, $31fc
800C27C4	sll    v0, v0, $01
800C27C8	addu   v0, v0, v1
800C27CC	lhu    v1, $0000(v0)
800C27D0	nop
800C27D4	addiu  v1, v1, $0008
800C27D8	j      Lc2848 [$800c2848]
800C27DC	sh     v1, $0000(v0)

Lc27e0:	; 800C27E0
800C27E0	lui    v0, $800a
800C27E4	lbu    v0, $d820(v0)
800C27E8	nop
800C27EC	andi   v0, v0, $0003
800C27F0	beq    v0, zero, Lc2808 [$800c2808]
800C27F4	addu   a1, zero, zero
800C27F8	lui    a0, $800a
800C27FC	addiu  a0, a0, $06c0
800C2800	jal    funcbeca4 [$800beca4]
800C2804	addu   a2, zero, zero

Lc2808:	; 800C2808
800C2808	lui    a0, $8007
800C280C	lbu    a0, $22c4(a0)
800C2810	lui    v0, $8008
800C2814	addiu  v0, v0, $31fc
800C2818	sll    a0, a0, $01
800C281C	addu   a0, a0, v0
800C2820	lhu    v1, $0000(a0)
800C2824	lui    v0, $800a
800C2828	lw     v0, $c6dc(v0)
800C282C	nop
800C2830	addu   v0, v0, v1
800C2834	lhu    v1, $0000(a0)
800C2838	lbu    v0, $0007(v0)
800C283C	addiu  v1, v1, $0007
800C2840	addu   v0, v0, v1
800C2844	sh     v0, $0000(a0)

Lc2848:	; 800C2848
800C2848	addu   v0, zero, zero
800C284C	lw     ra, $0010(sp)
800C2850	addiu  sp, sp, $0018
800C2854	jr     ra 
800C2858	nop

800C285C	lui    v0, $800a
800C2860	lbu    v0, $d820(v0)
800C2864	addiu  sp, sp, $ffe8 (=-$18)
800C2868	andi   v0, v0, $0003
800C286C	beq    v0, zero, Lc2884 [$800c2884]
800C2870	sw     ra, $0010(sp)
800C2874	lui    a0, $800a
800C2878	addiu  a0, a0, $06cc
800C287C	jal    funcbead4 [$800bead4]
800C2880	ori    a1, zero, $0008

Lc2884:	; 800C2884
800C2884	jal    funcc2970 [$800c2970]
800C2888	nop
800C288C	beq    v0, zero, Lc28e8 [$800c28e8]
800C2890	nop
800C2894	lui    v0, $800a
800C2898	lbu    v0, $d820(v0)
800C289C	nop
800C28A0	andi   v0, v0, $0003
800C28A4	beq    v0, zero, Lc28bc [$800c28bc]
800C28A8	addu   a1, zero, zero
800C28AC	lui    a0, $800a
800C28B0	addiu  a0, a0, $06d4
800C28B4	jal    funcbeca4 [$800beca4]
800C28B8	addu   a2, zero, zero

Lc28bc:	; 800C28BC
800C28BC	lui    v0, $8007
800C28C0	lbu    v0, $22c4(v0)
800C28C4	lui    v1, $8008
800C28C8	addiu  v1, v1, $31fc
800C28CC	sll    v0, v0, $01
800C28D0	addu   v0, v0, v1
800C28D4	lhu    v1, $0000(v0)
800C28D8	nop
800C28DC	addiu  v1, v1, $0009
800C28E0	j      Lc295c [$800c295c]
800C28E4	sh     v1, $0000(v0)

Lc28e8:	; 800C28E8
800C28E8	lui    v0, $800a
800C28EC	lbu    v0, $d820(v0)
800C28F0	nop
800C28F4	andi   v0, v0, $0003
800C28F8	beq    v0, zero, Lc2910 [$800c2910]
800C28FC	addu   a1, zero, zero
800C2900	lui    a0, $800a
800C2904	addiu  a0, a0, $06e0
800C2908	jal    funcbeca4 [$800beca4]
800C290C	addu   a2, zero, zero

Lc2910:	; 800C2910
800C2910	lui    a1, $8007
800C2914	lbu    a1, $22c4(a1)
800C2918	lui    v0, $8008
800C291C	addiu  v0, v0, $31fc
800C2920	sll    a1, a1, $01
800C2924	addu   a1, a1, v0
800C2928	lhu    v1, $0000(a1)
800C292C	lui    v0, $800a
800C2930	lw     v0, $c6dc(v0)
800C2934	nop
800C2938	addu   v0, v0, v1
800C293C	lbu    v1, $0008(v0)
800C2940	lbu    a0, $0007(v0)
800C2944	lhu    v0, $0000(a1)
800C2948	sll    v1, v1, $08
800C294C	or     a0, a0, v1
800C2950	addiu  a0, a0, $0007
800C2954	addu   v0, v0, a0
800C2958	sh     v0, $0000(a1)

Lc295c:	; 800C295C
800C295C	addu   v0, zero, zero
800C2960	lw     ra, $0010(sp)
800C2964	addiu  sp, sp, $0018
800C2968	jr     ra 
800C296C	nop


funcc2970:	; 800C2970
800C2970	lui    v0, $8007
800C2974	lbu    v0, $22c4(v0)
800C2978	addiu  sp, sp, $ffe8 (=-$18)
800C297C	sw     ra, $0014(sp)
800C2980	sw     s0, $0010(sp)
800C2984	sll    v0, v0, $01
800C2988	lui    at, $8008
800C298C	addiu  at, at, $31fc
800C2990	addu   at, at, v0
800C2994	lhu    v1, $0000(at)
800C2998	lui    v0, $800a
800C299C	lw     v0, $c6dc(v0)
800C29A0	nop
800C29A4	addu   v0, v0, v1
800C29A8	lbu    a1, $0006(v0)
800C29AC	nop
800C29B0	sltiu  v0, a1, $000b
800C29B4	beq    v0, zero, Lc2bbc [$800c2bbc]
800C29B8	sll    v0, a1, $02
800C29BC	lui    at, $800a
800C29C0	addiu  at, at, $071c
800C29C4	addu   at, at, v0
800C29C8	lw     v0, $0000(at)
800C29CC	nop
800C29D0	jr     v0 
800C29D4	nop

800C29D8	ori    a0, zero, $0001
800C29DC	jal    read_memory_block_two_bytes [$800bf908]
800C29E0	ori    a1, zero, $0002
800C29E4	ori    a0, zero, $0002
800C29E8	ori    a1, zero, $0004
800C29EC	jal    read_memory_block_two_bytes [$800bf908]
800C29F0	addu   s0, v0, zero
800C29F4	xor    s0, s0, v0
800C29F8	andi   s0, s0, $ffff
800C29FC	j      Lc2be4 [$800c2be4]
800C2A00	sltiu  s0, s0, $0001
800C2A04	ori    a0, zero, $0001
800C2A08	jal    read_memory_block_two_bytes [$800bf908]
800C2A0C	ori    a1, zero, $0002
800C2A10	ori    a0, zero, $0002
800C2A14	ori    a1, zero, $0004
800C2A18	jal    read_memory_block_two_bytes [$800bf908]
800C2A1C	addu   s0, v0, zero
800C2A20	xor    s0, s0, v0
800C2A24	andi   s0, s0, $ffff
800C2A28	j      Lc2be4 [$800c2be4]
800C2A2C	sltu   s0, zero, s0
800C2A30	ori    a0, zero, $0001
800C2A34	jal    read_memory_block_two_bytes [$800bf908]
800C2A38	ori    a1, zero, $0002
800C2A3C	ori    a0, zero, $0002
800C2A40	ori    a1, zero, $0004
800C2A44	jal    read_memory_block_two_bytes [$800bf908]
800C2A48	addu   s0, v0, zero
800C2A4C	andi   s0, s0, $ffff
800C2A50	andi   v0, v0, $ffff
800C2A54	sltu   v0, v0, s0
800C2A58	j      Lc2be4 [$800c2be4]
800C2A5C	addu   s0, v0, zero
800C2A60	ori    a0, zero, $0001
800C2A64	jal    read_memory_block_two_bytes [$800bf908]
800C2A68	ori    a1, zero, $0002
800C2A6C	ori    a0, zero, $0002
800C2A70	ori    a1, zero, $0004
800C2A74	jal    read_memory_block_two_bytes [$800bf908]
800C2A78	addu   s0, v0, zero
800C2A7C	andi   s0, s0, $ffff
800C2A80	andi   v0, v0, $ffff
800C2A84	j      Lc2be4 [$800c2be4]
800C2A88	sltu   s0, s0, v0
800C2A8C	ori    a0, zero, $0001
800C2A90	jal    read_memory_block_two_bytes [$800bf908]
800C2A94	ori    a1, zero, $0002
800C2A98	ori    a0, zero, $0002
800C2A9C	ori    a1, zero, $0004
800C2AA0	jal    read_memory_block_two_bytes [$800bf908]
800C2AA4	addu   s0, v0, zero
800C2AA8	andi   s0, s0, $ffff
800C2AAC	andi   v0, v0, $ffff
800C2AB0	sltu   s0, s0, v0
800C2AB4	j      Lc2be4 [$800c2be4]
800C2AB8	xori   s0, s0, $0001
800C2ABC	ori    a0, zero, $0001
800C2AC0	jal    read_memory_block_two_bytes [$800bf908]
800C2AC4	ori    a1, zero, $0002
800C2AC8	ori    a0, zero, $0002
800C2ACC	ori    a1, zero, $0004
800C2AD0	jal    read_memory_block_two_bytes [$800bf908]
800C2AD4	addu   s0, v0, zero
800C2AD8	andi   s0, s0, $ffff
800C2ADC	andi   v0, v0, $ffff
800C2AE0	sltu   v0, v0, s0
800C2AE4	j      Lc2be4 [$800c2be4]
800C2AE8	xori   s0, v0, $0001
800C2AEC	ori    a0, zero, $0001
800C2AF0	jal    read_memory_block_two_bytes [$800bf908]
800C2AF4	ori    a1, zero, $0002
800C2AF8	ori    a0, zero, $0002
800C2AFC	ori    a1, zero, $0004
800C2B00	jal    read_memory_block_two_bytes [$800bf908]
800C2B04	addu   s0, v0, zero
800C2B08	j      Lc2be4 [$800c2be4]
800C2B0C	and    s0, s0, v0
800C2B10	ori    a0, zero, $0001
800C2B14	jal    read_memory_block_two_bytes [$800bf908]
800C2B18	ori    a1, zero, $0002
800C2B1C	ori    a0, zero, $0002
800C2B20	ori    a1, zero, $0004
800C2B24	jal    read_memory_block_two_bytes [$800bf908]
800C2B28	addu   s0, v0, zero
800C2B2C	j      Lc2be4 [$800c2be4]
800C2B30	xor    s0, s0, v0
800C2B34	ori    a0, zero, $0001
800C2B38	jal    read_memory_block_two_bytes [$800bf908]
800C2B3C	ori    a1, zero, $0002
800C2B40	ori    a0, zero, $0002
800C2B44	ori    a1, zero, $0004
800C2B48	jal    read_memory_block_two_bytes [$800bf908]
800C2B4C	addu   s0, v0, zero
800C2B50	j      Lc2be4 [$800c2be4]
800C2B54	or     s0, s0, v0
800C2B58	ori    a0, zero, $0001
800C2B5C	jal    read_memory_block_two_bytes [$800bf908]
800C2B60	ori    a1, zero, $0002
800C2B64	ori    a0, zero, $0002
800C2B68	ori    a1, zero, $0004
800C2B6C	jal    read_memory_block_two_bytes [$800bf908]
800C2B70	addu   s0, v0, zero
800C2B74	ori    v1, zero, $0001
800C2B78	sllv   v1, v0, v1
800C2B7C	j      Lc2be4 [$800c2be4]
800C2B80	and    s0, s0, v1
800C2B84	ori    a0, zero, $0001
800C2B88	jal    read_memory_block_two_bytes [$800bf908]
800C2B8C	ori    a1, zero, $0002
800C2B90	ori    a0, zero, $0002
800C2B94	ori    a1, zero, $0004
800C2B98	jal    read_memory_block_two_bytes [$800bf908]
800C2B9C	addu   s0, v0, zero
800C2BA0	ori    v1, zero, $0001
800C2BA4	sllv   v1, v0, v1
800C2BA8	and    s0, s0, v1
800C2BAC	andi   v0, s0, $00ff
800C2BB0	sltiu  v0, v0, $0001
800C2BB4	j      Lc2be4 [$800c2be4]
800C2BB8	addu   s0, v0, zero

Lc2bbc:	; 800C2BBC
800C2BBC	lui    v0, $800a
800C2BC0	lbu    v0, $d820(v0)
800C2BC4	nop
800C2BC8	andi   v0, v0, $0003
800C2BCC	beq    v0, zero, Lc2be8 [$800c2be8]
800C2BD0	andi   v0, s0, $00ff
800C2BD4	lui    a0, $800a
800C2BD8	addiu  a0, a0, $0674
800C2BDC	jal    funcbeca4 [$800beca4]
800C2BE0	ori    a2, zero, $0002

Lc2be4:	; 800C2BE4
800C2BE4	andi   v0, s0, $00ff

Lc2be8:	; 800C2BE8
800C2BE8	lw     ra, $0014(sp)
800C2BEC	lw     s0, $0010(sp)
800C2BF0	addiu  sp, sp, $0018
800C2BF4	jr     ra 
800C2BF8	nop

800C2BFC	lui    v0, $800a
800C2C00	lbu    v0, $d820(v0)
800C2C04	addiu  sp, sp, $ffe8 (=-$18)
800C2C08	andi   v0, v0, $0003
800C2C0C	beq    v0, zero, Lc2c24 [$800c2c24]
800C2C10	sw     ra, $0010(sp)
800C2C14	lui    a0, $800a
800C2C18	addiu  a0, a0, $0748
800C2C1C	jal    funcbead4 [$800bead4]
800C2C20	ori    a1, zero, $0003

Lc2c24:	; 800C2C24
800C2C24	lui    v0, $8007
800C2C28	lbu    v0, $22c4(v0)
800C2C2C	nop
800C2C30	sll    v0, v0, $01
800C2C34	lui    at, $8008
800C2C38	addiu  at, at, $31fc
800C2C3C	addu   at, at, v0
800C2C40	lhu    v1, $0000(at)
800C2C44	lui    v0, $800a
800C2C48	lw     v0, $c6dc(v0)
800C2C4C	nop
800C2C50	addu   v0, v0, v1
800C2C54	lbu    v0, $0002(v0)
800C2C58	nop
800C2C5C	andi   v0, v0, $0002
800C2C60	bne    v0, zero, Lc2c80 [$800c2c80]
800C2C64	nop
800C2C68	lui    v0, $800a
800C2C6C	lw     v0, $c6e0(v0)
800C2C70	nop
800C2C74	lhu    a0, $0068(v0)
800C2C78	j      Lc2c90 [$800c2c90]
800C2C7C	nop

Lc2c80:	; 800C2C80
800C2C80	lui    v0, $800a
800C2C84	lw     v0, $c6e0(v0)
800C2C88	nop
800C2C8C	lhu    a0, $0078(v0)

Lc2c90:	; 800C2C90
800C2C90	jal    funcc2e00 [$800c2e00]
800C2C94	nop
800C2C98	lw     ra, $0010(sp)
800C2C9C	addiu  sp, sp, $0018
800C2CA0	jr     ra 
800C2CA4	nop

800C2CA8	lui    v0, $800a
800C2CAC	lbu    v0, $d820(v0)
800C2CB0	addiu  sp, sp, $ffe8 (=-$18)
800C2CB4	andi   v0, v0, $0003
800C2CB8	beq    v0, zero, Lc2cd0 [$800c2cd0]
800C2CBC	sw     ra, $0010(sp)
800C2CC0	lui    a0, $800a
800C2CC4	addiu  a0, a0, $0750
800C2CC8	jal    funcbead4 [$800bead4]
800C2CCC	ori    a1, zero, $0003

Lc2cd0:	; 800C2CD0
800C2CD0	lui    v0, $8007
800C2CD4	lbu    v0, $22c4(v0)
800C2CD8	nop
800C2CDC	sll    v0, v0, $01
800C2CE0	lui    at, $8008
800C2CE4	addiu  at, at, $31fc
800C2CE8	addu   at, at, v0
800C2CEC	lhu    v1, $0000(at)
800C2CF0	lui    v0, $800a
800C2CF4	lw     v0, $c6dc(v0)
800C2CF8	nop
800C2CFC	addu   v0, v0, v1
800C2D00	lbu    v0, $0002(v0)
800C2D04	nop
800C2D08	andi   v0, v0, $0002
800C2D0C	bne    v0, zero, Lc2d2c [$800c2d2c]
800C2D10	nop
800C2D14	lui    v0, $800a

Lc2d18:	; 800C2D18
800C2D18	lw     v0, $c6e0(v0)
800C2D1C	nop
800C2D20	lhu    a0, $0070(v0)
800C2D24	j      Lc2d3c [$800c2d3c]
800C2D28	nop

Lc2d2c:	; 800C2D2C
800C2D2C	lui    v0, $800a
800C2D30	lw     v0, $c6e0(v0)
800C2D34	nop
800C2D38	lhu    a0, $0080(v0)

Lc2d3c:	; 800C2D3C
800C2D3C	jal    funcc2e00 [$800c2e00]
800C2D40	nop
800C2D44	lw     ra, $0010(sp)
800C2D48	addiu  sp, sp, $0018
800C2D4C	jr     ra 
800C2D50	nop

800C2D54	lui    v0, $800a
800C2D58	lbu    v0, $d820(v0)
800C2D5C	addiu  sp, sp, $ffe8 (=-$18)
800C2D60	andi   v0, v0, $0003
800C2D64	beq    v0, zero, Lc2d7c [$800c2d7c]
800C2D68	sw     ra, $0010(sp)
800C2D6C	lui    a0, $800a
800C2D70	addiu  a0, a0, $0758
800C2D74	jal    funcbead4 [$800bead4]
800C2D78	ori    a1, zero, $0003

Lc2d7c:	; 800C2D7C
800C2D7C	lui    v0, $8007
800C2D80	lbu    v0, $22c4(v0)
800C2D84	nop
800C2D88	sll    v0, v0, $01
800C2D8C	lui    at, $8008
800C2D90	addiu  at, at, $31fc
800C2D94	addu   at, at, v0
800C2D98	lhu    v1, $0000(at)
800C2D9C	lui    v0, $800a
800C2DA0	lw     v0, $c6dc(v0)
800C2DA4	nop
800C2DA8	addu   v0, v0, v1
800C2DAC	lbu    v0, $0002(v0)
800C2DB0	nop
800C2DB4	andi   v0, v0, $0002
800C2DB8	bne    v0, zero, Lc2dd8 [$800c2dd8]
800C2DBC	nop
800C2DC0	lui    v0, $800a
800C2DC4	lw     v0, $c6e0(v0)
800C2DC8	nop
800C2DCC	lhu    a0, $0074(v0)
800C2DD0	j      Lc2de8 [$800c2de8]
800C2DD4	nop

Lc2dd8:	; 800C2DD8
800C2DD8	lui    v0, $800a
800C2DDC	lw     v0, $c6e0(v0)
800C2DE0	nop
800C2DE4	lhu    a0, $0084(v0)

Lc2de8:	; 800C2DE8
800C2DE8	jal    funcc2e00 [$800c2e00]
800C2DEC	nop
800C2DF0	lw     ra, $0010(sp)
800C2DF4	addiu  sp, sp, $0018
800C2DF8	jr     ra 
800C2DFC	nop


funcc2e00:	; 800C2E00
800C2E00	addiu  sp, sp, $ffd0 (=-$30)
800C2E04	sw     s3, $0024(sp)
800C2E08	addu   s3, a0, zero
800C2E0C	lui    v0, $8007
800C2E10	lbu    v0, $22c4(v0)
800C2E14	addu   a1, s3, zero
800C2E18	sw     ra, $0028(sp)
800C2E1C	sw     s2, $0020(sp)
800C2E20	sw     s1, $001c(sp)
800C2E24	sw     s0, $0018(sp)
800C2E28	sll    v0, v0, $01
800C2E2C	lui    at, $8008
800C2E30	addiu  at, at, $31fc
800C2E34	addu   at, at, v0
800C2E38	lhu    v1, $0000(at)
800C2E3C	lui    v0, $800a
800C2E40	lw     v0, $c6dc(v0)
800C2E44	lui    s1, $8008
800C2E48	addiu  s1, s1, $31fc
800C2E4C	addu   v0, v0, v1
800C2E50	lbu    v1, $0002(v0)
800C2E54	lbu    s0, $0001(v0)
800C2E58	lui    v0, $800a
800C2E5C	lbu    v0, $d820(v0)
800C2E60	sll    v1, v1, $08
800C2E64	or     s2, s0, v1
800C2E68	andi   v0, v0, $0003
800C2E6C	beq    v0, zero, Lc2e9c [$800c2e9c]
800C2E70	addu   s0, s2, zero
800C2E74	lui    a0, $800a
800C2E78	addiu  a0, a0, $0760
800C2E7C	andi   a1, a1, $ffff
800C2E80	jal    funcbeca4 [$800beca4]
800C2E84	ori    a2, zero, $0004
800C2E88	lui    a0, $800a
800C2E8C	addiu  a0, a0, $076c
800C2E90	addu   a1, s0, zero
800C2E94	jal    funcbeca4 [$800beca4]
800C2E98	ori    a2, zero, $0004

Lc2e9c:	; 800C2E9C
800C2E9C	and    v0, s3, s2
800C2EA0	beq    v0, zero, Lc2ef8 [$800c2ef8]
800C2EA4	nop
800C2EA8	lui    v0, $800a
800C2EAC	lbu    v0, $d820(v0)
800C2EB0	nop
800C2EB4	andi   v0, v0, $0003
800C2EB8	beq    v0, zero, Lc2ed0 [$800c2ed0]
800C2EBC	addu   a1, zero, zero
800C2EC0	lui    a0, $800a
800C2EC4	addiu  a0, a0, $0778
800C2EC8	jal    funcbeca4 [$800beca4]
800C2ECC	addu   a2, zero, zero

Lc2ed0:	; 800C2ED0
800C2ED0	lui    v1, $8007
800C2ED4	lbu    v1, $22c4(v1)
800C2ED8	nop
800C2EDC	sll    v1, v1, $01
800C2EE0	addu   v1, v1, s1
800C2EE4	lhu    v0, $0000(v1)
800C2EE8	nop
800C2EEC	addiu  v0, v0, $0004
800C2EF0	j      Lc2f58 [$800c2f58]
800C2EF4	sh     v0, $0000(v1)

Lc2ef8:	; 800C2EF8
800C2EF8	lui    v0, $800a
800C2EFC	lbu    v0, $d820(v0)
800C2F00	nop
800C2F04	andi   v0, v0, $0003
800C2F08	beq    v0, zero, Lc2f20 [$800c2f20]
800C2F0C	addu   a1, zero, zero
800C2F10	lui    a0, $800a
800C2F14	addiu  a0, a0, $0784
800C2F18	jal    funcbeca4 [$800beca4]
800C2F1C	addu   a2, zero, zero

Lc2f20:	; 800C2F20
800C2F20	lui    a0, $8007
800C2F24	lbu    a0, $22c4(a0)
800C2F28	lui    v0, $800a
800C2F2C	lw     v0, $c6dc(v0)
800C2F30	sll    a0, a0, $01
800C2F34	addu   a0, a0, s1
800C2F38	lhu    v1, $0000(a0)
800C2F3C	nop
800C2F40	addu   v0, v0, v1
800C2F44	lhu    v1, $0000(a0)
800C2F48	lbu    v0, $0003(v0)
800C2F4C	addiu  v1, v1, $0003
800C2F50	addu   v0, v0, v1
800C2F54	sh     v0, $0000(a0)

Lc2f58:	; 800C2F58
800C2F58	addu   v0, zero, zero
800C2F5C	lw     ra, $0028(sp)
800C2F60	lw     s3, $0024(sp)
800C2F64	lw     s2, $0020(sp)
800C2F68	lw     s1, $001c(sp)
800C2F6C	lw     s0, $0018(sp)
800C2F70	addiu  sp, sp, $0030
800C2F74	jr     ra 
800C2F78	nop



////////////////////////////////
// 0x01 REQ
800C2F7C-800C2FF8
////////////////////////////////



////////////////////////////////
// 0x02 REQSW
800C2FFC-800C3078
////////////////////////////////



////////////////////////////////
// 0x03 REQEW
800C307C-800C30F8
////////////////////////////////



////////////////////////////////
// 0x04 PREQ
800C30FC-800C31E0
////////////////////////////////



////////////////////////////////
// 0x05 PRQSW
800C31E4-800C32C8
////////////////////////////////


////////////////////////////////
// 0x06 PRQEW
800C32CC-800C33B0
////////////////////////////////



////////////////////////////////
funcc33b4
800C33B4-800C3A1C
////////////////////////////////



////////////////////////////////
// 0x00 RET
800C3A20-800C3C30
////////////////////////////////



////////////////////////////////
// 0x07 RETTO
800C3C34-800C3E9C
////////////////////////////////



800C3EA0	lui    v0, $800a
800C3EA4	lbu    v0, $d820(v0)
800C3EA8	addiu  sp, sp, $ffe8 (=-$18)
800C3EAC	andi   v0, v0, $0003
800C3EB0	beq    v0, zero, Lc3ec8 [$800c3ec8]
800C3EB4	sw     ra, $0010(sp)
800C3EB8	lui    a0, $800a
800C3EBC	addiu  a0, a0, $0820
800C3EC0	jal    funcbead4 [$800bead4]
800C3EC4	ori    a1, zero, $0001

Lc3ec8:	; 800C3EC8
800C3EC8	lui    v1, $8007
800C3ECC	lbu    v1, $22c4(v1)
800C3ED0	lui    v0, $8008
800C3ED4	addiu  v0, v0, $31fc
800C3ED8	sll    v1, v1, $01
800C3EDC	addu   v1, v1, v0
800C3EE0	lhu    a0, $0000(v1)
800C3EE4	lui    v0, $800a
800C3EE8	lw     v0, $c6dc(v0)
800C3EEC	nop
800C3EF0	addu   v0, v0, a0
800C3EF4	lbu    a0, $0001(v0)
800C3EF8	lhu    v0, $0000(v1)
800C3EFC	nop
800C3F00	subu   v0, v0, a0
800C3F04	sh     v0, $0000(v1)
800C3F08	ori    v0, zero, $0001
800C3F0C	lw     ra, $0010(sp)
800C3F10	addiu  sp, sp, $0018
800C3F14	jr     ra 
800C3F18	nop

800C3F1C	lui    v0, $800a
800C3F20	lbu    v0, $d820(v0)
800C3F24	addiu  sp, sp, $ffe8 (=-$18)
800C3F28	andi   v0, v0, $0003
800C3F2C	beq    v0, zero, Lc3f44 [$800c3f44]
800C3F30	sw     ra, $0010(sp)
800C3F34	lui    a0, $800a
800C3F38	addiu  a0, a0, $0828
800C3F3C	jal    funcbead4 [$800bead4]
800C3F40	ori    a1, zero, $0002

Lc3f44:	; 800C3F44
800C3F44	lui    a1, $8007
800C3F48	lbu    a1, $22c4(a1)
800C3F4C	lui    v0, $8008
800C3F50	addiu  v0, v0, $31fc
800C3F54	sll    a1, a1, $01
800C3F58	addu   a1, a1, v0
800C3F5C	lhu    v1, $0000(a1)
800C3F60	lui    v0, $800a
800C3F64	lw     v0, $c6dc(v0)
800C3F68	nop
800C3F6C	addu   v0, v0, v1
800C3F70	lbu    a0, $0002(v0)
800C3F74	lbu    v0, $0001(v0)
800C3F78	lhu    v1, $0000(a1)
800C3F7C	sll    a0, a0, $08
800C3F80	or     v0, v0, a0
800C3F84	subu   v1, v1, v0
800C3F88	ori    v0, zero, $0001
800C3F8C	sh     v1, $0000(a1)
800C3F90	lw     ra, $0010(sp)
800C3F94	addiu  sp, sp, $0018
800C3F98	jr     ra 
800C3F9C	nop

800C3FA0	lui    v0, $800a
800C3FA4	lbu    v0, $d820(v0)
800C3FA8	addiu  sp, sp, $ffe8 (=-$18)
800C3FAC	andi   v0, v0, $0003
800C3FB0	beq    v0, zero, Lc3fc8 [$800c3fc8]
800C3FB4	sw     ra, $0010(sp)
800C3FB8	lui    a0, $800a
800C3FBC	addiu  a0, a0, $0830
800C3FC0	jal    funcbead4 [$800bead4]
800C3FC4	ori    a1, zero, $0001

Lc3fc8:	; 800C3FC8
800C3FC8	lui    a0, $8007
800C3FCC	lbu    a0, $22c4(a0)
800C3FD0	lui    v0, $8008
800C3FD4	addiu  v0, v0, $31fc
800C3FD8	sll    a0, a0, $01
800C3FDC	addu   a0, a0, v0
800C3FE0	lhu    v1, $0000(a0)
800C3FE4	lui    v0, $800a
800C3FE8	lw     v0, $c6dc(v0)
800C3FEC	nop
800C3FF0	addu   v0, v0, v1
800C3FF4	lhu    v1, $0000(a0)
800C3FF8	lbu    v0, $0001(v0)
800C3FFC	addiu  v1, v1, $0001
800C4000	addu   v0, v0, v1

Lc4004:	; 800C4004
800C4004	sh     v0, $0000(a0)
800C4008	addu   v0, zero, zero
800C400C	lw     ra, $0010(sp)
800C4010	addiu  sp, sp, $0018
800C4014	jr     ra 
800C4018	nop

800C401C	lui    v0, $800a
800C4020	lbu    v0, $d820(v0)
800C4024	addiu  sp, sp, $ffe8 (=-$18)
800C4028	andi   v0, v0, $0003
800C402C	beq    v0, zero, Lc4044 [$800c4044]
800C4030	sw     ra, $0010(sp)
800C4034	lui    a0, $800a
800C4038	addiu  a0, a0, $0838
800C403C	jal    funcbead4 [$800bead4]
800C4040	ori    a1, zero, $0002

Lc4044:	; 800C4044
800C4044	lui    a1, $8007
800C4048	lbu    a1, $22c4(a1)
800C404C	lui    v0, $8008
800C4050	addiu  v0, v0, $31fc
800C4054	sll    a1, a1, $01
800C4058	addu   a1, a1, v0
800C405C	lhu    v1, $0000(a1)
800C4060	lui    v0, $800a
800C4064	lw     v0, $c6dc(v0)
800C4068	nop
800C406C	addu   v0, v0, v1
800C4070	lbu    a0, $0002(v0)
800C4074	lbu    v1, $0001(v0)
800C4078	lhu    v0, $0000(a1)
800C407C	sll    a0, a0, $08
800C4080	or     v1, v1, a0
800C4084	addiu  v0, v0, $0001
800C4088	addu   v1, v1, v0
800C408C	addu   v0, zero, zero
800C4090	sh     v1, $0000(a1)
800C4094	lw     ra, $0010(sp)
800C4098	addiu  sp, sp, $0018
800C409C	jr     ra 
800C40A0	nop

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

800C43C4	lui    v0, $800a
800C43C8	lbu    v0, $d820(v0)
800C43CC	addiu  sp, sp, $ffe8 (=-$18)
800C43D0	andi   v0, v0, $0003
800C43D4	beq    v0, zero, Lc43ec [$800c43ec]
800C43D8	sw     ra, $0010(sp)
800C43DC	lui    a0, $800a
800C43E0	addiu  a0, a0, $085c
800C43E4	jal    funcbead4 [$800bead4]
800C43E8	ori    a1, zero, $0008

Lc43ec:	; 800C43EC
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
// 0x70 BATTLE
800C45AC-800C46A0
////////////////////////////////



////////////////////////////////
// clear_akao
800C46A4-800C46CC
////////////////////////////////



////////////////////////////////
// 0xF2 AKAO
800C46D0-800C4800
////////////////////////////////



////////////////////////////////
// 0xDA AKAO2
800C4804-800C4938
////////////////////////////////



////////////////////////////////
// 0xF1 SOUND
800C493C-800C49E8
////////////////////////////////



////////////////////////////////
// 0xF0 MUSIC
800C49EC-800C4A3C
////////////////////////////////



////////////////////////////////
// 0xF3 MUSVT
800C4A40-800C4A90
////////////////////////////////



////////////////////////////////
// 0xF4 MUSVM
800C4A94-800C4AE4
////////////////////////////////



////////////////////////////////
// 0xFD CMUSC
800C4AE8-800C4BC8
////////////////////////////////



////////////////////////////////
// set_and_apply_field_music_params
800C4BCC-800C4C98
////////////////////////////////



////////////////////////////////
// get_akao_offset_in_field
800C4C9C-800C4CE4
////////////////////////////////



////////////////////////////////
// 0xF6 BMUSC
800C4CE8-800C4DE4
////////////////////////////////



////////////////////////////////
// 0xFC FMUSC
800C4DE8-800C4EE4
////////////////////////////////



////////////////////////////////
// 0x21 TUTOR
800C4EE8-800C5068
////////////////////////////////



////////////////////////////////
// 0xF5 MULCK
800C506C-800C50E8
////////////////////////////////



////////////////////////////////
// 0x27 BGMOVIE
800C50EC-800C5190
////////////////////////////////



////////////////////////////////
// 0x61 SCRLO
800C5194-800C5238
////////////////////////////////



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
// 0x33 UC
800C532C-800C5410
////////////////////////////////



////////////////////////////////
// 0x71 BTLON
800C5414-800C54B8
////////////////////////////////



800C54BC	lui    v0, $800a
800C54C0	lbu    v0, $d820(v0)
800C54C4	addiu  sp, sp, $ffe0 (=-$20)
800C54C8	andi   v0, v0, $0003
800C54CC	beq    v0, zero, Lc54e4 [$800c54e4]
800C54D0	sw     ra, $0018(sp)
800C54D4	lui    a0, $800a
800C54D8	addiu  a0, a0, $0908
800C54DC	jal    funcbead4 [$800bead4]
800C54E0	ori    a1, zero, $0001

Lc54e4:	; 800C54E4
800C54E4	lui    v0, $8007
800C54E8	lbu    v0, $22c4(v0)
800C54EC	nop
800C54F0	sll    v0, v0, $01
800C54F4	lui    at, $8008
800C54F8	addiu  at, at, $31fc
800C54FC	addu   at, at, v0
800C5500	lhu    v1, $0000(at)
800C5504	lui    v0, $800a
800C5508	lw     v0, $c6dc(v0)
800C550C	nop
800C5510	addu   v0, v0, v1
800C5514	lui    v1, $800a
800C5518	lw     v1, $c6e0(v1)
800C551C	lbu    v0, $0001(v0)
800C5520	nop
800C5524	sb     v0, $0038(v1)
800C5528	lui    v1, $8007
800C552C	lbu    v1, $22c4(v1)
800C5530	lui    v0, $8008
800C5534	addiu  v0, v0, $31fc
800C5538	sll    v1, v1, $01
800C553C	addu   v1, v1, v0
800C5540	lhu    v0, $0000(v1)
800C5544	nop
800C5548	addiu  v0, v0, $0002
800C554C	sh     v0, $0000(v1)
800C5550	addu   v0, zero, zero
800C5554	lw     ra, $0018(sp)
800C5558	addiu  sp, sp, $0020
800C555C	jr     ra 
800C5560	nop

800C5564	lui    v0, $800a
800C5568	lbu    v0, $d820(v0)
800C556C	addiu  sp, sp, $ffe0 (=-$20)
800C5570	andi   v0, v0, $0003
800C5574	beq    v0, zero, Lc558c [$800c558c]
800C5578	sw     ra, $0018(sp)
800C557C	lui    a0, $800a
800C5580	addiu  a0, a0, $0910
800C5584	jal    funcbead4 [$800bead4]
800C5588	ori    a1, zero, $0001

Lc558c:	; 800C558C
800C558C	lui    v0, $8007
800C5590	lbu    v0, $22c4(v0)
800C5594	nop
800C5598	sll    v0, v0, $01
800C559C	lui    at, $8008
800C55A0	addiu  at, at, $31fc
800C55A4	addu   at, at, v0
800C55A8	lhu    v1, $0000(at)
800C55AC	lui    v0, $800a
800C55B0	lw     v0, $c6dc(v0)
800C55B4	nop
800C55B8	addu   v0, v0, v1
800C55BC	lui    v1, $800a
800C55C0	lw     v1, $c6e0(v1)
800C55C4	lbu    v0, $0001(v0)
800C55C8	nop
800C55CC	sb     v0, $0039(v1)
800C55D0	lui    v1, $8007
800C55D4	lbu    v1, $22c4(v1)
800C55D8	lui    v0, $8008
800C55DC	addiu  v0, v0, $31fc
800C55E0	sll    v1, v1, $01
800C55E4	addu   v1, v1, v0
800C55E8	lhu    v0, $0000(v1)
800C55EC	nop
800C55F0	addiu  v0, v0, $0002
800C55F4	sh     v0, $0000(v1)
800C55F8	addu   v0, zero, zero

funcc55fc:	; 800C55FC
800C55FC	lw     ra, $0018(sp)
800C5600	addiu  sp, sp, $0020
800C5604	jr     ra 
800C5608	nop

800C560C	lui    v0, $800a
800C5610	lbu    v0, $d820(v0)
800C5614	addiu  sp, sp, $ffe8 (=-$18)
800C5618	andi   v0, v0, $0003
800C561C	beq    v0, zero, Lc5634 [$800c5634]
800C5620	sw     ra, $0010(sp)
800C5624	lui    a0, $800a
800C5628	addiu  a0, a0, $0918
800C562C	jal    funcbead4 [$800bead4]
800C5630	addu   a1, zero, zero

Lc5634:	; 800C5634
800C5634	lui    v0, $800a
800C5638	lw     v0, $c6e0(v0)
800C563C	ori    v1, zero, $001a
800C5640	sb     v1, $0001(v0)
800C5644	lui    v0, $800a
800C5648	lw     v0, $c6e0(v0)
800C564C	nop
800C5650	sh     zero, $0026(v0)
800C5654	ori    v0, zero, $0001
800C5658	lw     ra, $0010(sp)
800C565C	addiu  sp, sp, $0018
800C5660	jr     ra 
800C5664	nop



////////////////////////////////
// 0xBF CC
800C5668-800C573C
////////////////////////////////



////////////////////////////////
// 0xA1 CHAR
800C5740-800C5894
////////////////////////////////



////////////////////////////////
// 0xA2 DFANM
800C5898-800C5A28
////////////////////////////////



////////////////////////////////
// 0xDC CCANM
800C5A2C-800C5B34
////////////////////////////////



////////////////////////////////
// funcc5b38
800C5B38-800C5CE4
////////////////////////////////



////////////////////////////////
// 0xA3 ANIME1
// 0xAE ANIME2
800C5CE8-800C5E7C
////////////////////////////////



////////////////////////////////
// 0xAF ANIM!1
// 0xBA ANIM!2
800C5E80-800C5FF0
////////////////////////////////



////////////////////////////////
// 0xB0 CANIM1
// 0xBB CANIM2
800C5FF4-800C63C8
////////////////////////////////



////////////////////////////////
// 0xB1 CANM!1
// 0xBC CANM!2
800C63CC-800C6744
////////////////////////////////



////////////////////////////////
// 0xAC ANIMW
800C6748-800C6848
////////////////////////////////



////////////////////////////////
// 0xDD ANIMB
800C684C-800C6920
////////////////////////////////



////////////////////////////////
// 0xA8 MOVE
800C6924-800C6D60
////////////////////////////////



////////////////////////////////
// 0xAD FMOVE
800C6D64-800C6FD4
////////////////////////////////



////////////////////////////////
// 0xA9 CMOVE
800C6FD8-800C7288
////////////////////////////////



////////////////////////////////
// 0xDB FCFIX
800C728C-800C7350
////////////////////////////////



////////////////////////////////
// 0xC0 JUMP
800C7354-800C75EC
////////////////////////////////



////////////////////////////////
// 0xC2 LADER
800C75F0-800C7C38
////////////////////////////////



800C7C3C	lui    v0, $800a
800C7C40	lbu    v0, $d820(v0)
800C7C44	addiu  sp, sp, $ffe8 (=-$18)
800C7C48	andi   v0, v0, $0003
800C7C4C	beq    v0, zero, Lc7c64 [$800c7c64]
800C7C50	sw     ra, $0010(sp)
800C7C54	lui    a0, $800a
800C7C58	addiu  a0, a0, $099c
800C7C5C	jal    funcbead4 [$800bead4]
800C7C60	ori    a1, zero, $0001

Lc7c64:	; 800C7C64
800C7C64	lui    v0, $8007
800C7C68	lbu    v0, $22c4(v0)
800C7C6C	nop
800C7C70	sll    v0, v0, $01
800C7C74	lui    at, $8008
800C7C78	addiu  at, at, $31fc
800C7C7C	addu   at, at, v0
800C7C80	lhu    v1, $0000(at)
800C7C84	lui    v0, $800a
800C7C88	lw     v0, $c6dc(v0)
800C7C8C	nop
800C7C90	addu   v0, v0, v1
800C7C94	lbu    v0, $0001(v0)
800C7C98	nop
800C7C9C	lui    at, $800a
800C7CA0	addiu  at, at, $d391 (=-$2c6f)
800C7CA4	addu   at, at, v0
800C7CA8	lbu    a0, $0000(at)
800C7CAC	ori    v0, zero, $00ff
800C7CB0	bne    a0, v0, Lc7cc0 [$800c7cc0]
800C7CB4	nop
800C7CB8	j      Lc7cd0 [$800c7cd0]
800C7CBC	ori    a0, zero, $00ff

Lc7cc0:	; 800C7CC0
800C7CC0	lui    at, $800a
800C7CC4	addiu  at, at, $ad30 (=-$52d0)
800C7CC8	addu   at, at, a0
800C7CCC	lbu    a0, $0000(at)

Lc7cd0:	; 800C7CD0
800C7CD0	jal    funcc7d5c [$800c7d5c]
800C7CD4	nop
800C7CD8	lw     ra, $0010(sp)
800C7CDC	addiu  sp, sp, $0018
800C7CE0	jr     ra 
800C7CE4	nop



////////////////////////////////
// 0xAA MOVA
800C7CE8-800C7D58
////////////////////////////////



////////////////////////////////
// funcc7d5c
800C7D5C-800C8148
////////////////////////////////



////////////////////////////////
// 0xB6 DIRA
800C814C-800C81BC
////////////////////////////////



800C81C0	lui    v0, $800a
800C81C4	lbu    v0, $d820(v0)
800C81C8	addiu  sp, sp, $ffe8 (=-$18)
800C81CC	andi   v0, v0, $0003
800C81D0	beq    v0, zero, Lc81e8 [$800c81e8]
800C81D4	sw     ra, $0010(sp)
800C81D8	lui    a0, $800a
800C81DC	addiu  a0, a0, $09b4
800C81E0	jal    funcbead4 [$800bead4]
800C81E4	ori    a1, zero, $0001

Lc81e8:	; 800C81E8
800C81E8	lui    v0, $8007
800C81EC	lbu    v0, $22c4(v0)
800C81F0	nop
800C81F4	sll    v0, v0, $01
800C81F8	lui    at, $8008
800C81FC	addiu  at, at, $31fc
800C8200	addu   at, at, v0
800C8204	lhu    v1, $0000(at)
800C8208	lui    v0, $800a
800C820C	lw     v0, $c6dc(v0)
800C8210	nop
800C8214	addu   v0, v0, v1
800C8218	lbu    v0, $0001(v0)
800C821C	nop
800C8220	lui    at, $800a
800C8224	addiu  at, at, $d391 (=-$2c6f)
800C8228	addu   at, at, v0
800C822C	lbu    a0, $0000(at)
800C8230	ori    v0, zero, $00ff
800C8234	bne    a0, v0, Lc8244 [$800c8244]
800C8238	nop
800C823C	j      Lc8254 [$800c8254]
800C8240	ori    a0, zero, $00ff

Lc8244:	; 800C8244
800C8244	lui    at, $800a
800C8248	addiu  at, at, $ad30 (=-$52d0)
800C824C	addu   at, at, a0
800C8250	lbu    a0, $0000(at)

Lc8254:	; 800C8254
800C8254	jal    set_direction_to_current_entity_by_entity_id [$800c826c]
800C8258	nop
800C825C	lw     ra, $0010(sp)
800C8260	addiu  sp, sp, $0018
800C8264	jr     ra 
800C8268	nop



////////////////////////////////
// set_direction_to_current_entity_by_entity_id
800C826C-800C8510
////////////////////////////////



////////////////////////////////
// 0xAB TURA
800C8514-800C8584
////////////////////////////////



800C8588	lui    v0, $800a
800C858C	lbu    v0, $d820(v0)
800C8590	addiu  sp, sp, $ffe8 (=-$18)
800C8594	andi   v0, v0, $0003
800C8598	beq    v0, zero, Lc85b0 [$800c85b0]
800C859C	sw     ra, $0010(sp)
800C85A0	lui    a0, $800a
800C85A4	addiu  a0, a0, $09c4
800C85A8	jal    funcbead4 [$800bead4]
800C85AC	ori    a1, zero, $0003

Lc85b0:	; 800C85B0
800C85B0	lui    v0, $8007
800C85B4	lbu    v0, $22c4(v0)
800C85B8	nop
800C85BC	sll    v0, v0, $01
800C85C0	lui    at, $8008
800C85C4	addiu  at, at, $31fc
800C85C8	addu   at, at, v0
800C85CC	lhu    v1, $0000(at)
800C85D0	lui    v0, $800a
800C85D4	lw     v0, $c6dc(v0)
800C85D8	nop
800C85DC	addu   v0, v0, v1
800C85E0	lbu    v0, $0001(v0)
800C85E4	nop
800C85E8	lui    at, $800a
800C85EC	addiu  at, at, $d391 (=-$2c6f)
800C85F0	addu   at, at, v0
800C85F4	lbu    a0, $0000(at)
800C85F8	ori    v0, zero, $00ff
800C85FC	bne    a0, v0, Lc860c [$800c860c]
800C8600	nop
800C8604	j      Lc861c [$800c861c]
800C8608	ori    a0, zero, $00ff

Lc860c:	; 800C860C
800C860C	lui    at, $800a
800C8610	addiu  at, at, $ad30 (=-$52d0)
800C8614	addu   at, at, a0
800C8618	lbu    a0, $0000(at)

Lc861c:	; 800C861C
800C861C	jal    funcc8634 [$800c8634]
800C8620	nop
800C8624	lw     ra, $0010(sp)
800C8628	addiu  sp, sp, $0018
800C862C	jr     ra 
800C8630	nop



////////////////////////////////
// funcc8634
800C8634-800C8B94
////////////////////////////////



////////////////////////////////
// 0xC3 OFST
800C8B98-800C8F60
////////////////////////////////



////////////////////////////////
// 0xC4 OFSTW
800C8F64-800C907C
////////////////////////////////



////////////////////////////////
// 0xDE TURNW
800C9080-800C91D4
////////////////////////////////



////////////////////////////////
// 0xB5 TURN
800C91D8-800C9558
////////////////////////////////



////////////////////////////////
// 0xB4 TURNGEN
800C955C-800C9A1C
////////////////////////////////



////////////////////////////////
// 0xB3 DIR
800C9A20-800C9B84
////////////////////////////////



////////////////////////////////
// 0xC6 SLIDR
800C9B88-800C9C80
////////////////////////////////



////////////////////////////////
// 0xD7 SLDR2
800C9C84-800C9D7C
////////////////////////////////



////////////////////////////////
// 0xC5 TALKR
800C9D80-800C9E78
////////////////////////////////



////////////////////////////////
// 0xD6 TLKR2
800C9E7C-800C9F74
////////////////////////////////



////////////////////////////////
// 0xB2 MSPED
800C9F78-800CA070
////////////////////////////////



////////////////////////////////
// 0xBD ASPED
800CA074-800CA154
////////////////////////////////



////////////////////////////////
// 0xB7 GETDIR
800CA158-800CA250
////////////////////////////////



800CA254	lui    v0, $8007
800CA258	lbu    v0, $22c4(v0)
800CA25C	addiu  sp, sp, $ffe8 (=-$18)
800CA260	sw     ra, $0014(sp)
800CA264	sw     s0, $0010(sp)
800CA268	sll    v0, v0, $01
800CA26C	lui    at, $8008
800CA270	addiu  at, at, $31fc
800CA274	addu   at, at, v0
800CA278	lhu    v1, $0000(at)
800CA27C	lui    v0, $800a
800CA280	lw     v0, $c6dc(v0)
800CA284	nop
800CA288	addu   v0, v0, v1
800CA28C	lbu    v1, $0002(v0)
800CA290	nop
800CA294	sltiu  v0, v1, $0003
800CA298	beq    v0, zero, Lca354 [$800ca354]
800CA29C	nop
800CA2A0	lui    at, $800a
800CA2A4	addiu  at, at, $d391 (=-$2c6f)
800CA2A8	addu   at, at, v1
800CA2AC	lbu    v0, $0000(at)
800CA2B0	ori    v1, zero, $00ff
800CA2B4	beq    v0, v1, Lca354 [$800ca354]
800CA2B8	nop
800CA2BC	lui    at, $800a
800CA2C0	addiu  at, at, $ad30 (=-$52d0)
800CA2C4	addu   at, at, v0
800CA2C8	lbu    s0, $0000(at)
800CA2CC	nop
800CA2D0	beq    s0, v1, Lca354 [$800ca354]
800CA2D4	nop
800CA2D8	lui    at, $8008
800CA2DC	addiu  at, at, $eb98 (=-$1468)
800CA2E0	addu   at, at, s0
800CA2E4	lbu    v0, $0000(at)
800CA2E8	nop
800CA2EC	beq    v0, v1, Lca354 [$800ca354]
800CA2F0	nop
800CA2F4	lui    v0, $800a
800CA2F8	lbu    v0, $d820(v0)
800CA2FC	nop
800CA300	andi   v0, v0, $0003
800CA304	beq    v0, zero, Lca31c [$800ca31c]
800CA308	nop
800CA30C	lui    a0, $800a
800CA310	addiu  a0, a0, $0a60
800CA314	jal    funcbead4 [$800bead4]
800CA318	ori    a1, zero, $0003

Lca31c:	; 800CA31C
800CA31C	lui    at, $8008
800CA320	addiu  at, at, $eb98 (=-$1468)
800CA324	addu   at, at, s0
800CA328	lbu    v0, $0000(at)
800CA32C	ori    a0, zero, $0002
800CA330	sll    v1, v0, $05
800CA334	addu   v1, v1, v0
800CA338	lui    v0, $800a
800CA33C	lw     v0, $c544(v0)
800CA340	sll    v1, v1, $02
800CA344	addu   v1, v1, v0
800CA348	lbu    a2, $0038(v1)
800CA34C	jal    store_memory_block_one_byte [$800bf3ac]
800CA350	ori    a1, zero, $0003

Lca354:	; 800CA354
800CA354	lui    v0, $8007
800CA358	lbu    v0, $22c4(v0)
800CA35C	lui    v1, $8008
800CA360	addiu  v1, v1, $31fc
800CA364	sll    v0, v0, $01
800CA368	addu   v0, v0, v1
800CA36C	lhu    v1, $0000(v0)
800CA370	nop
800CA374	addiu  v1, v1, $0004
800CA378	sh     v1, $0000(v0)
800CA37C	addu   v0, zero, zero
800CA380	lw     ra, $0014(sp)
800CA384	lw     s0, $0010(sp)
800CA388	addiu  sp, sp, $0018
800CA38C	jr     ra 
800CA390	nop



////////////////////////////////
// 0xB9 GETAI
800CA394-800CA48C
////////////////////////////////



////////////////////////////////
// 0xB8 GETAXY
800CA490-800CA5D0
////////////////////////////////



800CA5D4	lui    v0, $8007
800CA5D8	lbu    v0, $22c4(v0)
800CA5DC	lui    v1, $800a
800CA5E0	lbu    v1, $d820(v1)
800CA5E4	addiu  sp, sp, $ffd8 (=-$28)
800CA5E8	sw     s1, $001c(sp)
800CA5EC	lui    s1, $8008
800CA5F0	addiu  s1, s1, $31fc
800CA5F4	sw     ra, $0020(sp)
800CA5F8	sw     s0, $0018(sp)
800CA5FC	sll    v0, v0, $01
800CA600	lui    at, $8008
800CA604	addiu  at, at, $31fc
800CA608	addu   at, at, v0
800CA60C	lhu    a0, $0000(at)
800CA610	lui    v0, $800a
800CA614	lw     v0, $c6dc(v0)
800CA618	andi   v1, v1, $0003
800CA61C	addu   v0, v0, a0
800CA620	lbu    s0, $0003(v0)
800CA624	beq    v1, zero, Lca63c [$800ca63c]
800CA628	andi   s0, s0, $00ff
800CA62C	lui    a0, $800a
800CA630	addiu  a0, a0, $0a78
800CA634	jal    funcbead4 [$800bead4]
800CA638	ori    a1, zero, $0007

Lca63c:	; 800CA63C
800CA63C	lui    at, $8008
800CA640	addiu  at, at, $eb98 (=-$1468)
800CA644	addu   at, at, s0
800CA648	lbu    v1, $0000(at)
800CA64C	ori    v0, zero, $00ff
800CA650	beq    v1, v0, Lca73c [$800ca73c]
800CA654	ori    a0, zero, $0001
800CA658	sll    v0, v1, $05
800CA65C	addu   v0, v0, v1
800CA660	lui    v1, $800a
800CA664	lw     v1, $c544(v1)
800CA668	sll    v0, v0, $02
800CA66C	addu   v0, v0, v1
800CA670	lw     a2, $000c(v0)
800CA674	ori    a1, zero, $0004
800CA678	sll    a2, a2, $04
800CA67C	jal    store_memory_block_two_bytes [$800c0248]
800CA680	sra    a2, a2, $10
800CA684	lui    at, $8008
800CA688	addiu  at, at, $eb98 (=-$1468)
800CA68C	addu   at, at, s0
800CA690	lbu    v1, $0000(at)
800CA694	ori    a0, zero, $0002
800CA698	sll    v0, v1, $05
800CA69C	addu   v0, v0, v1
800CA6A0	lui    v1, $800a
800CA6A4	lw     v1, $c544(v1)
800CA6A8	sll    v0, v0, $02
800CA6AC	addu   v0, v0, v1
800CA6B0	lw     a2, $0010(v0)
800CA6B4	ori    a1, zero, $0005
800CA6B8	sll    a2, a2, $04
800CA6BC	jal    store_memory_block_two_bytes [$800c0248]
800CA6C0	sra    a2, a2, $10
800CA6C4	lui    at, $8008
800CA6C8	addiu  at, at, $eb98 (=-$1468)
800CA6CC	addu   at, at, s0
800CA6D0	lbu    v1, $0000(at)
800CA6D4	ori    a0, zero, $0003
800CA6D8	sll    v0, v1, $05
800CA6DC	addu   v0, v0, v1
800CA6E0	lui    v1, $800a
800CA6E4	lw     v1, $c544(v1)
800CA6E8	sll    v0, v0, $02
800CA6EC	addu   v0, v0, v1
800CA6F0	lw     a2, $0014(v0)
800CA6F4	ori    a1, zero, $0006
800CA6F8	sll    a2, a2, $04
800CA6FC	jal    store_memory_block_two_bytes [$800c0248]
800CA700	sra    a2, a2, $10
800CA704	lui    at, $8008
800CA708	addiu  at, at, $eb98 (=-$1468)
800CA70C	addu   at, at, s0
800CA710	lbu    v1, $0000(at)
800CA714	ori    a0, zero, $0004
800CA718	sll    v0, v1, $05
800CA71C	addu   v0, v0, v1
800CA720	lui    v1, $800a
800CA724	lw     v1, $c544(v1)
800CA728	sll    v0, v0, $02
800CA72C	addu   v0, v0, v1
800CA730	lh     a2, $0072(v0)
800CA734	jal    store_memory_block_two_bytes [$800c0248]
800CA738	ori    a1, zero, $0007

Lca73c:	; 800CA73C
800CA73C	lui    v1, $8007
800CA740	lbu    v1, $22c4(v1)
800CA744	nop
800CA748	sll    v1, v1, $01
800CA74C	addu   v1, v1, s1
800CA750	lhu    v0, $0000(v1)
800CA754	nop
800CA758	addiu  v0, v0, $0008
800CA75C	sh     v0, $0000(v1)
800CA760	addu   v0, zero, zero
800CA764	lw     ra, $0020(sp)
800CA768	lw     s1, $001c(sp)
800CA76C	lw     s0, $0018(sp)
800CA770	addiu  sp, sp, $0028
800CA774	jr     ra 
800CA778	nop

800CA77C	lui    v0, $8007
800CA780	lbu    v0, $22c4(v0)
800CA784	lui    v1, $800a
800CA788	lbu    v1, $d820(v1)
800CA78C	addiu  sp, sp, $ffe8 (=-$18)
800CA790	sw     ra, $0014(sp)
800CA794	sw     s0, $0010(sp)
800CA798	sll    v0, v0, $01
800CA79C	lui    at, $8008
800CA7A0	addiu  at, at, $31fc
800CA7A4	addu   at, at, v0
800CA7A8	lhu    a0, $0000(at)
800CA7AC	lui    v0, $800a
800CA7B0	lw     v0, $c6dc(v0)
800CA7B4	andi   v1, v1, $0003
800CA7B8	addu   v0, v0, a0
800CA7BC	lbu    s0, $0003(v0)
800CA7C0	beq    v1, zero, Lca7dc [$800ca7dc]
800CA7C4	andi   v1, s0, $00ff
800CA7C8	lui    a0, $800a
800CA7CC	addiu  a0, a0, $0a80
800CA7D0	jal    funcbead4 [$800bead4]
800CA7D4	ori    a1, zero, $0007
800CA7D8	andi   v1, s0, $00ff

Lca7dc:	; 800CA7DC
800CA7DC	sltiu  v0, v1, $0003
800CA7E0	beq    v0, zero, Lca91c [$800ca91c]
800CA7E4	nop
800CA7E8	lui    at, $800a
800CA7EC	addiu  at, at, $d391 (=-$2c6f)
800CA7F0	addu   at, at, v1
800CA7F4	lbu    v1, $0000(at)
800CA7F8	nop
800CA7FC	sltiu  v0, v1, $0009
800CA800	beq    v0, zero, Lca91c [$800ca91c]
800CA804	ori    v0, zero, $00ff
800CA808	lui    at, $800a
800CA80C	addiu  at, at, $ad30 (=-$52d0)
800CA810	addu   at, at, v1
800CA814	lbu    s0, $0000(at)
800CA818	nop
800CA81C	lui    at, $8008
800CA820	addiu  at, at, $eb98 (=-$1468)
800CA824	addu   at, at, s0
800CA828	lbu    v1, $0000(at)
800CA82C	nop
800CA830	beq    v1, v0, Lca91c [$800ca91c]
800CA834	ori    a0, zero, $0001
800CA838	sll    v0, v1, $05
800CA83C	addu   v0, v0, v1
800CA840	lui    v1, $800a
800CA844	lw     v1, $c544(v1)
800CA848	sll    v0, v0, $02
800CA84C	addu   v0, v0, v1
800CA850	lw     a2, $000c(v0)
800CA854	ori    a1, zero, $0004
800CA858	sll    a2, a2, $04
800CA85C	jal    store_memory_block_two_bytes [$800c0248]
800CA860	sra    a2, a2, $10
800CA864	lui    at, $8008
800CA868	addiu  at, at, $eb98 (=-$1468)
800CA86C	addu   at, at, s0
800CA870	lbu    v1, $0000(at)
800CA874	ori    a0, zero, $0002
800CA878	sll    v0, v1, $05
800CA87C	addu   v0, v0, v1
800CA880	lui    v1, $800a
800CA884	lw     v1, $c544(v1)
800CA888	sll    v0, v0, $02
800CA88C	addu   v0, v0, v1
800CA890	lw     a2, $0010(v0)
800CA894	ori    a1, zero, $0005
800CA898	sll    a2, a2, $04
800CA89C	jal    store_memory_block_two_bytes [$800c0248]
800CA8A0	sra    a2, a2, $10
800CA8A4	lui    at, $8008
800CA8A8	addiu  at, at, $eb98 (=-$1468)
800CA8AC	addu   at, at, s0
800CA8B0	lbu    v1, $0000(at)
800CA8B4	ori    a0, zero, $0003
800CA8B8	sll    v0, v1, $05
800CA8BC	addu   v0, v0, v1
800CA8C0	lui    v1, $800a
800CA8C4	lw     v1, $c544(v1)
800CA8C8	sll    v0, v0, $02
800CA8CC	addu   v0, v0, v1
800CA8D0	lw     a2, $0014(v0)
800CA8D4	ori    a1, zero, $0006
800CA8D8	sll    a2, a2, $04
800CA8DC	jal    store_memory_block_two_bytes [$800c0248]
800CA8E0	sra    a2, a2, $10
800CA8E4	lui    at, $8008
800CA8E8	addiu  at, at, $eb98 (=-$1468)
800CA8EC	addu   at, at, s0
800CA8F0	lbu    v1, $0000(at)
800CA8F4	ori    a0, zero, $0004
800CA8F8	sll    v0, v1, $05
800CA8FC	addu   v0, v0, v1
800CA900	lui    v1, $800a
800CA904	lw     v1, $c544(v1)
800CA908	sll    v0, v0, $02
800CA90C	addu   v0, v0, v1
800CA910	lh     a2, $0072(v0)
800CA914	jal    store_memory_block_two_bytes [$800c0248]
800CA918	ori    a1, zero, $0007

Lca91c:	; 800CA91C
800CA91C	lui    v0, $8007
800CA920	lbu    v0, $22c4(v0)
800CA924	lui    v1, $8008
800CA928	addiu  v1, v1, $31fc
800CA92C	sll    v0, v0, $01
800CA930	addu   v0, v0, v1
800CA934	lhu    v1, $0000(v0)
800CA938	nop
800CA93C	addiu  v1, v1, $0008
800CA940	sh     v1, $0000(v0)
800CA944	addu   v0, zero, zero
800CA948	lw     ra, $0014(sp)
800CA94C	lw     s0, $0010(sp)
800CA950	addiu  sp, sp, $0018
800CA954	jr     ra 
800CA958	nop



////////////////////////////////
// 0xA4 VISI
800CA95C-800CAA20
////////////////////////////////



////////////////////////////////
// 0x7E TLKON
800CAA24-800CAAE8
////////////////////////////////



////////////////////////////////
// 0xA5 XYZI
800CAAEC-800CAC94
////////////////////////////////



////////////////////////////////
// 0xA7 XYZ
800CAC98-800CADF8
////////////////////////////////



////////////////////////////////
// 0xA6 XYI
800CADFC-800CAF5C
////////////////////////////////



////////////////////////////////
// 0x40 MESSAGE
800CAF60-800CB018
////////////////////////////////



////////////////////////////////
// 0x43 MPNAM
800CB01C-800CB0B4
////////////////////////////////



////////////////////////////////
// 0x48 ASK
800CB0B8-800CB1C8
////////////////////////////////



////////////////////////////////
// 0x2E WCLS
800CB1CC-800CB288
////////////////////////////////



////////////////////////////////
// 0x2F WSIZE
800CB28C-800CB350
////////////////////////////////



////////////////////////////////
// 0x50 WINDOW
800CB354-800CB44C
////////////////////////////////



////////////////////////////////
// 0x55 WROW
800CB450-800CB4F4
////////////////////////////////



////////////////////////////////
// 0x51 WMOVE
800CB4F8-800CB5BC
////////////////////////////////



////////////////////////////////
// 0x53 WREST
800CB5C0-800CB65C
////////////////////////////////



////////////////////////////////
// 0x54 WCLSE
800CB660-800CB714
////////////////////////////////



////////////////////////////////
// 0x52 WMODE
800CB718-800CB7BC
////////////////////////////////



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

800CC9EC	lui    v0, $800a
800CC9F0	lbu    v0, $d820(v0)
800CC9F4	addiu  sp, sp, $ffe8 (=-$18)
800CC9F8	andi   v0, v0, $0003
800CC9FC	beq    v0, zero, Lcca14 [$800cca14]
800CCA00	sw     ra, $0010(sp)
800CCA04	lui    a0, $800a
800CCA08	addiu  a0, a0, $0bc0
800CCA0C	jal    funcbead4 [$800bead4]
800CCA10	ori    a1, zero, $0002

Lcca14:	; 800CCA14
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
// 0xE0 BGON
800CCA68-800CCB0C
////////////////////////////////



////////////////////////////////
// 0xE0 BGOFF
800CCB10-800CCBB8
////////////////////////////////



////////////////////////////////
// 0xE4 BGCLR
800CCBBC-800CCC38
////////////////////////////////



////////////////////////////////
// 0xE2 BGROL
800CCC3C-800CCCC4
////////////////////////////////



////////////////////////////////
// 0xE3 BGROL2
800CCCC8-800CCD50
////////////////////////////////



800CCD54	lui    v0, $800a
800CCD58	lbu    v0, $d820(v0)
800CCD5C	addiu  sp, sp, $ffe8 (=-$18)
800CCD60	andi   v0, v0, $0003
800CCD64	beq    v0, zero, Lccd7c [$800ccd7c]
800CCD68	sw     ra, $0010(sp)
800CCD6C	lui    a0, $800a
800CCD70	addiu  a0, a0, $0be8
800CCD74	jal    funcbead4 [$800bead4]
800CCD78	ori    a1, zero, $0001

Lccd7c:	; 800CCD7C
800CCD7C	lui    v0, $8007
800CCD80	lbu    v0, $16cc(v0)
800CCD84	nop
800CCD88	beq    v0, zero, Lccdbc [$800ccdbc]
800CCD8C	nop
800CCD90	lui    v1, $8007
800CCD94	lbu    v1, $22c4(v1)
800CCD98	lui    v0, $8008
800CCD9C	addiu  v0, v0, $31fc
800CCDA0	sll    v1, v1, $01
800CCDA4	addu   v1, v1, v0
800CCDA8	lhu    a0, $0000(v1)
800CCDAC	addu   v0, zero, zero
800CCDB0	addiu  a0, a0, $0002
800CCDB4	j      Lcce84 [$800cce84]
800CCDB8	sh     a0, $0000(v1)

Lccdbc:	; 800CCDBC
800CCDBC	lui    v1, $800a
800CCDC0	lw     v1, $c6e0(v1)
800CCDC4	nop
800CCDC8	lbu    a0, $0001(v1)
800CCDCC	nop
800CCDD0	beq    a0, zero, Lcce34 [$800cce34]
800CCDD4	ori    v0, zero, $0003
800CCDD8	bne    a0, v0, Lcce84 [$800cce84]
800CCDDC	ori    v0, zero, $0001
800CCDE0	lh     a0, $0026(v1)
800CCDE4	nop
800CCDE8	beq    a0, v0, Lcce80 [$800cce80]
800CCDEC	ori    v0, zero, $0002
800CCDF0	bne    a0, v0, Lcce84 [$800cce84]
800CCDF4	ori    v0, zero, $0001
800CCDF8	sb     zero, $0001(v1)
800CCDFC	lui    v0, $800a
800CCE00	lw     v0, $c6e0(v0)
800CCE04	lui    a0, $8007
800CCE08	lbu    a0, $22c4(a0)
800CCE0C	sh     zero, $0026(v0)
800CCE10	lui    v0, $8008
800CCE14	addiu  v0, v0, $31fc
800CCE18	sll    a0, a0, $01
800CCE1C	addu   a0, a0, v0
800CCE20	lhu    v1, $0000(a0)
800CCE24	addu   v0, zero, zero
800CCE28	addiu  v1, v1, $0002
800CCE2C	j      Lcce84 [$800cce84]
800CCE30	sh     v1, $0000(a0)

Lcce34:	; 800CCE34
800CCE34	ori    v0, zero, $0003
800CCE38	sb     v0, $0001(v1)
800CCE3C	lui    v0, $8007
800CCE40	lbu    v0, $22c4(v0)
800CCE44	nop
800CCE48	sll    v0, v0, $01
800CCE4C	lui    at, $8008
800CCE50	addiu  at, at, $31fc
800CCE54	addu   at, at, v0
800CCE58	lhu    v1, $0000(at)
800CCE5C	lui    v0, $800a
800CCE60	lw     v0, $c6dc(v0)
800CCE64	nop
800CCE68	addu   v0, v0, v1
800CCE6C	lui    v1, $800a
800CCE70	lw     v1, $c6e0(v1)
800CCE74	lbu    v0, $0001(v0)
800CCE78	sh     zero, $0026(v1)
800CCE7C	sh     v0, $0002(v1)

Lcce80:	; 800CCE80
800CCE80	ori    v0, zero, $0001

Lcce84:	; 800CCE84
800CCE84	lw     ra, $0010(sp)
800CCE88	addiu  sp, sp, $0018
800CCE8C	jr     ra 
800CCE90	nop

800CCE94	lui    v0, $800a
800CCE98	lbu    v0, $d820(v0)
800CCE9C	addiu  sp, sp, $ffe8 (=-$18)
800CCEA0	andi   v0, v0, $0003
800CCEA4	beq    v0, zero, Lccebc [$800ccebc]
800CCEA8	sw     ra, $0010(sp)
800CCEAC	lui    a0, $800a
800CCEB0	addiu  a0, a0, $0bf0
800CCEB4	jal    funcbead4 [$800bead4]
800CCEB8	addu   a1, zero, zero

Lccebc:	; 800CCEBC
800CCEBC	lui    v1, $8007
800CCEC0	lbu    v1, $16cc(v1)
800CCEC4	ori    v0, zero, $0001
800CCEC8	lui    at, $8007
800CCECC	sb     v0, $1c1c(at)
800CCED0	beq    v1, zero, Lccef8 [$800ccef8]
800CCED4	ori    v0, zero, $0004
800CCED8	lui    v1, $8007
800CCEDC	lbu    v1, $22c4(v1)
800CCEE0	lui    v0, $8008
800CCEE4	addiu  v0, v0, $31fc
800CCEE8	lui    at, $8011
800CCEEC	sh     zero, $44d4(at)
800CCEF0	j      Lccfa8 [$800ccfa8]
800CCEF4	sll    v1, v1, $01

Lccef8:	; 800CCEF8
800CCEF8	lui    a0, $800a
800CCEFC	lw     a0, $c6e0(a0)
800CCF00	nop
800CCF04	lbu    v1, $0001(a0)
800CCF08	nop
800CCF0C	beq    v1, v0, Lccf40 [$800ccf40]
800CCF10	slti   v0, v1, $0005
800CCF14	beq    v0, zero, Lccf2c [$800ccf2c]
800CCF18	nop
800CCF1C	beq    v1, zero, Lccfc0 [$800ccfc0]
800CCF20	ori    v0, zero, $0004
800CCF24	j      Lccfd8 [$800ccfd8]
800CCF28	ori    v0, zero, $0001

Lccf2c:	; 800CCF2C
800CCF2C	ori    v0, zero, $0014
800CCF30	beq    v1, v0, Lccf94 [$800ccf94]
800CCF34	ori    v0, zero, $0001
800CCF38	j      Lccfd8 [$800ccfd8]
800CCF3C	nop

Lccf40:	; 800CCF40
800CCF40	lh     v1, $0026(a0)
800CCF44	ori    v0, zero, $0001
800CCF48	beq    v1, v0, Lccfd4 [$800ccfd4]
800CCF4C	ori    v0, zero, $0002
800CCF50	bne    v1, v0, Lccfd8 [$800ccfd8]
800CCF54	ori    v0, zero, $0001
800CCF58	sb     zero, $0001(a0)
800CCF5C	lui    v0, $800a
800CCF60	lw     v0, $c6e0(v0)
800CCF64	lui    a0, $8007
800CCF68	lbu    a0, $22c4(a0)
800CCF6C	sh     zero, $0026(v0)
800CCF70	lui    v0, $8008
800CCF74	addiu  v0, v0, $31fc
800CCF78	sll    a0, a0, $01
800CCF7C	addu   a0, a0, v0
800CCF80	lhu    v1, $0000(a0)
800CCF84	addu   v0, zero, zero
800CCF88	addiu  v1, v1, $0001
800CCF8C	j      Lccfd8 [$800ccfd8]
800CCF90	sh     v1, $0000(a0)

Lccf94:	; 800CCF94
800CCF94	lui    v1, $8007
800CCF98	lbu    v1, $22c4(v1)
800CCF9C	lui    v0, $8008
800CCFA0	addiu  v0, v0, $31fc
800CCFA4	sll    v1, v1, $01

Lccfa8:	; 800CCFA8
800CCFA8	addu   v1, v1, v0
800CCFAC	lhu    a0, $0000(v1)
800CCFB0	addu   v0, zero, zero
800CCFB4	addiu  a0, a0, $0001
800CCFB8	j      Lccfd8 [$800ccfd8]
800CCFBC	sh     a0, $0000(v1)

Lccfc0:	; 800CCFC0
800CCFC0	sb     v0, $0001(a0)
800CCFC4	lui    v0, $800a
800CCFC8	lw     v0, $c6e0(v0)
800CCFCC	nop
800CCFD0	sh     zero, $0026(v0)

Lccfd4:	; 800CCFD4
800CCFD4	ori    v0, zero, $0001

Lccfd8:	; 800CCFD8
800CCFD8	lw     ra, $0010(sp)
800CCFDC	addiu  sp, sp, $0018
800CCFE0	jr     ra 
800CCFE4	nop

800CCFE8	lui    v0, $800a
800CCFEC	lbu    v0, $d820(v0)
800CCFF0	addiu  sp, sp, $ffe8 (=-$18)
800CCFF4	andi   v0, v0, $0003
800CCFF8	beq    v0, zero, Lcd010 [$800cd010]
800CCFFC	sw     ra, $0010(sp)
800CD000	lui    a0, $800a
800CD004	addiu  a0, a0, $0bf8
800CD008	jal    funcbead4 [$800bead4]
800CD00C	ori    a1, zero, $0002

Lcd010:	; 800CD010
800CD010	lui    v0, $8007
800CD014	lbu    v0, $16cc(v0)
800CD018	nop
800CD01C	bne    v0, zero, Lcd068 [$800cd068]
800CD020	ori    a0, zero, $0002
800CD024	lui    v0, $800a
800CD028	lw     v0, $c6e0(v0)
800CD02C	nop
800CD030	lh     a2, $0088(v0)
800CD034	jal    store_memory_block_two_bytes [$800c0248]
800CD038	ori    a1, zero, $0002
800CD03C	lui    a0, $8007
800CD040	lbu    a0, $22c4(a0)
800CD044	lui    v0, $8008
800CD048	addiu  v0, v0, $31fc
800CD04C	sll    a0, a0, $01
800CD050	addu   a0, a0, v0
800CD054	lhu    v1, $0000(a0)
800CD058	addu   v0, zero, zero
800CD05C	addiu  v1, v1, $0003
800CD060	j      Lcd0b4 [$800cd0b4]
800CD064	sh     v1, $0000(a0)

Lcd068:	; 800CD068
800CD068	lui    a2, $8011
800CD06C	lh     a2, $44d4(a2)
800CD070	jal    store_memory_block_two_bytes [$800c0248]
800CD074	ori    a1, zero, $0002
800CD078	addu   v0, zero, zero
800CD07C	lui    a1, $8007
800CD080	lbu    a1, $22c4(a1)
800CD084	lui    v1, $8008
800CD088	addiu  v1, v1, $31fc
800CD08C	sll    a1, a1, $01
800CD090	addu   a1, a1, v1
800CD094	lui    v1, $8011
800CD098	lhu    v1, $44d4(v1)
800CD09C	lhu    a0, $0000(a1)
800CD0A0	addiu  v1, v1, $0001
800CD0A4	addiu  a0, a0, $0003
800CD0A8	lui    at, $8011
800CD0AC	sh     v1, $44d4(at)
800CD0B0	sh     a0, $0000(a1)

Lcd0b4:	; 800CD0B4
800CD0B4	lw     ra, $0010(sp)
800CD0B8	addiu  sp, sp, $0018
800CD0BC	jr     ra 
800CD0C0	nop

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
// 0x64 SCR2D
800CD16C-800CD210
////////////////////////////////



////////////////////////////////
// 0x62 SCRLC
800CD214-800CD2E4
////////////////////////////////



////////////////////////////////
// 0x63 SCRLA
800CD2E8-800CD3EC
////////////////////////////////



////////////////////////////////
// 0x6F SCRLP
800CD3F0-800CD550
////////////////////////////////



////////////////////////////////
// 0x65 SCRCC
800CD554-800CD5EC
////////////////////////////////



////////////////////////////////
// 0x66 SCR2DC
800CD5F0-800CD6AC
////////////////////////////////



////////////////////////////////
// 0x68 SCR2DL
800CD6B0-800CD76C
////////////////////////////////



////////////////////////////////
// 0x67 SCRLW
800CD770-800CD830
////////////////////////////////



////////////////////////////////
// 0xE5 STPAL
800CD834-800CD918
////////////////////////////////



////////////////////////////////
// 0xEB STPLS
800CD91C-800CDA20
////////////////////////////////



////////////////////////////////
// 0xE6 LDPAL
800CDA24-800CDB08
////////////////////////////////



////////////////////////////////
// 0xEC LDPLS
800CDB0C-800CDC10
////////////////////////////////



////////////////////////////////
// funccdc14
800CDC14-800CDC24
////////////////////////////////



////////////////////////////////
// 0xE7 CPPAL
800CDC28-800CDD3C
////////////////////////////////



////////////////////////////////
// 0xED CPPAL2
800CDD40-800CDE88
////////////////////////////////



////////////////////////////////
// 0xE8 RTPAL
800CDE8C-800CE050
////////////////////////////////



////////////////////////////////
// 0xEE RTPAL2
800CE054-800CE210
////////////////////////////////



////////////////////////////////
// 0xE9 ADPAL
800CE214-800CE47C
////////////////////////////////



////////////////////////////////
// 0xEF ADPAL2
800CE480-800CE6F0
////////////////////////////////



////////////////////////////////
// 0xEA MPPAL2
800CE6F4-800CE900
////////////////////////////////



////////////////////////////////
// 0xDF MPPAL
800CE904-800CEB1C
////////////////////////////////



////////////////////////////////
// field_set_1st_party_character_as_manual_model
800CEB20-800CEB90
////////////////////////////////



////////////////////////////////
// 0xA0 PC
800CEB94-800CEE40
////////////////////////////////



////////////////////////////////
// 0xC8 PRTYP
800CEE44-800CF024
////////////////////////////////



////////////////////////////////
// 0xC9 PRTYM
800CF028-800CF13C
////////////////////////////////



////////////////////////////////
// 0xCA PRTYE
800CF140-800CF1FC
////////////////////////////////



800CF200	lui    v0, $800a
800CF204	lbu    v0, $d820(v0)
800CF208	addiu  sp, sp, $ffd8 (=-$28)
800CF20C	sw     ra, $0024(sp)
800CF210	sw     s2, $0020(sp)
800CF214	sw     s1, $001c(sp)
800CF218	andi   v0, v0, $0003
800CF21C	beq    v0, zero, Lcf234 [$800cf234]
800CF220	sw     s0, $0018(sp)
800CF224	lui    a0, $800a
800CF228	addiu  a0, a0, $0cb4
800CF22C	jal    funcbead4 [$800bead4]
800CF230	ori    a1, zero, $0005

Lcf234:	; 800CF234
800CF234	addu   s1, zero, zero
800CF238	addiu  s2, sp, $0010

loopcf23c:	; 800CF23C
800CF23C	addiu  s0, s1, $0001
800CF240	sll    a0, s0, $10
800CF244	sra    a0, a0, $10
800CF248	addiu  a1, s1, $0003
800CF24C	sll    a1, a1, $10
800CF250	jal    read_memory_block_one_byte [$800bee10]
800CF254	sra    a1, a1, $10
800CF258	addu   v1, s2, s1
800CF25C	sb     v0, $0000(v1)
800CF260	addu   s1, s0, zero
800CF264	slti   v0, s1, $0003
800CF268	bne    v0, zero, loopcf23c [$800cf23c]
800CF26C	nop
800CF270	jal    funccf368 [$800cf368]
800CF274	addiu  a0, sp, $0010
800CF278	lui    v1, $8007
800CF27C	lbu    v1, $22c4(v1)
800CF280	lui    v0, $8008
800CF284	addiu  v0, v0, $31fc
800CF288	sll    v1, v1, $01
800CF28C	addu   v1, v1, v0
800CF290	lhu    a0, $0000(v1)
800CF294	addu   v0, zero, zero
800CF298	addiu  a0, a0, $0006
800CF29C	sh     a0, $0000(v1)
800CF2A0	lw     ra, $0024(sp)
800CF2A4	lw     s2, $0020(sp)
800CF2A8	lw     s1, $001c(sp)
800CF2AC	lw     s0, $0018(sp)
800CF2B0	addiu  sp, sp, $0028
800CF2B4	jr     ra 
800CF2B8	nop

800CF2BC	lui    v0, $800a
800CF2C0	lbu    v0, $d820(v0)
800CF2C4	addiu  sp, sp, $ffe8 (=-$18)
800CF2C8	sw     ra, $0014(sp)
800CF2CC	andi   v0, v0, $0003
800CF2D0	beq    v0, zero, Lcf2e8 [$800cf2e8]
800CF2D4	sw     s0, $0010(sp)
800CF2D8	lui    a0, $800a
800CF2DC	addiu  a0, a0, $0cbc
800CF2E0	jal    funcbead4 [$800bead4]
800CF2E4	ori    a1, zero, $0005

Lcf2e8:	; 800CF2E8
800CF2E8	addu   v1, zero, zero

loopcf2ec:	; 800CF2EC
800CF2EC	addiu  s0, v1, $0001
800CF2F0	sll    a0, s0, $10
800CF2F4	sra    a0, a0, $10
800CF2F8	addiu  a1, v1, $0003
800CF2FC	sll    a1, a1, $10
800CF300	lui    at, $800a
800CF304	addiu  at, at, $d391 (=-$2c6f)
800CF308	addu   at, at, v1
800CF30C	lbu    a2, $0000(at)
800CF310	jal    store_memory_block_one_byte [$800bf3ac]
800CF314	sra    a1, a1, $10
800CF318	addu   v1, s0, zero
800CF31C	slti   v0, v1, $0003
800CF320	bne    v0, zero, loopcf2ec [$800cf2ec]
800CF324	nop
800CF328	lui    v0, $8007
800CF32C	lbu    v0, $22c4(v0)
800CF330	lui    v1, $8008
800CF334	addiu  v1, v1, $31fc
800CF338	sll    v0, v0, $01
800CF33C	addu   v0, v0, v1
800CF340	lhu    v1, $0000(v0)
800CF344	nop
800CF348	addiu  v1, v1, $0006
800CF34C	sh     v1, $0000(v0)
800CF350	addu   v0, zero, zero
800CF354	lw     ra, $0014(sp)
800CF358	lw     s0, $0010(sp)
800CF35C	addiu  sp, sp, $0018
800CF360	jr     ra 
800CF364	nop



////////////////////////////////
// funccf368
800CF368-800CF4C8
////////////////////////////////



////////////////////////////////
// funccf4cc
800CF4CC-800CF59C
////////////////////////////////



////////////////////////////////
// field_copy_party_to_battle_party
800CF5A0-800CF608
////////////////////////////////



////////////////////////////////
// funccf60c
800CF60C-800CF668
////////////////////////////////



////////////////////////////////
// funccf66c
800CF66C-800CF6BC
////////////////////////////////



////////////////////////////////
// funccf6c0
800CF6C0-800CF714
////////////////////////////////



800CF718	lui    v0, $800a
800CF71C	lbu    v0, $d820(v0)
800CF720	addiu  sp, sp, $ffe0 (=-$20)
800CF724	sw     ra, $001c(sp)
800CF728	andi   v0, v0, $0003
800CF72C	beq    v0, zero, Lcf744 [$800cf744]
800CF730	sw     s0, $0018(sp)
800CF734	lui    a0, $800a
800CF738	addiu  a0, a0, $0cc4
800CF73C	jal    funcbead4 [$800bead4]
800CF740	ori    a1, zero, $0002

Lcf744:	; 800CF744
800CF744	lui    v0, $8007
800CF748	lbu    v0, $22c4(v0)
800CF74C	addu   a0, zero, zero
800CF750	sll    v0, v0, $01
800CF754	lui    at, $8008
800CF758	addiu  at, at, $31fc
800CF75C	addu   at, at, v0
800CF760	lhu    v1, $0000(at)
800CF764	lui    v0, $800a
800CF768	lw     v0, $c6dc(v0)
800CF76C	lui    s0, $8008
800CF770	addiu  s0, s0, $31fc
800CF774	addu   v0, v0, v1
800CF778	lbu    v1, $0001(v0)

loopcf77c:	; 800CF77C
800CF77C	lui    at, $800a
800CF780	addiu  at, at, $d391 (=-$2c6f)
800CF784	addu   at, at, a0
800CF788	lbu    v0, $0000(at)
800CF78C	nop
800CF790	bne    v0, v1, Lcf7e8 [$800cf7e8]
800CF794	nop
800CF798	lui    v0, $800a
800CF79C	lbu    v0, $d820(v0)
800CF7A0	nop
800CF7A4	andi   v0, v0, $0003
800CF7A8	beq    v0, zero, Lcf7c0 [$800cf7c0]
800CF7AC	addu   a1, zero, zero
800CF7B0	lui    a0, $800a
800CF7B4	addiu  a0, a0, $0ccc
800CF7B8	jal    funcbeca4 [$800beca4]
800CF7BC	addu   a2, zero, zero

Lcf7c0:	; 800CF7C0
800CF7C0	lui    a0, $8007
800CF7C4	lbu    a0, $22c4(a0)
800CF7C8	nop
800CF7CC	sll    a0, a0, $01
800CF7D0	addu   a0, a0, s0
800CF7D4	lhu    v1, $0000(a0)
800CF7D8	addu   v0, zero, zero
800CF7DC	addiu  v1, v1, $0003
800CF7E0	j      Lcf860 [$800cf860]
800CF7E4	sh     v1, $0000(a0)

Lcf7e8:	; 800CF7E8
800CF7E8	addiu  a0, a0, $0001
800CF7EC	slti   v0, a0, $0003
800CF7F0	bne    v0, zero, loopcf77c [$800cf77c]
800CF7F4	nop
800CF7F8	lui    v0, $800a
800CF7FC	lbu    v0, $d820(v0)
800CF800	nop
800CF804	andi   v0, v0, $0003
800CF808	beq    v0, zero, Lcf820 [$800cf820]
800CF80C	addu   a1, zero, zero
800CF810	lui    a0, $800a
800CF814	addiu  a0, a0, $0cd8
800CF818	jal    funcbeca4 [$800beca4]
800CF81C	addu   a2, zero, zero

Lcf820:	; 800CF820
800CF820	lui    v0, $8008
800CF824	addiu  v0, v0, $31fc
800CF828	lui    a1, $8007
800CF82C	lbu    a1, $22c4(a1)
800CF830	lui    a0, $800a
800CF834	lw     a0, $c6dc(a0)
800CF838	sll    a1, a1, $01
800CF83C	addu   a1, a1, v0
800CF840	lhu    v1, $0000(a1)
800CF844	addu   v0, zero, zero
800CF848	addu   a0, a0, v1
800CF84C	lhu    v1, $0000(a1)
800CF850	lbu    a0, $0002(a0)
800CF854	addiu  v1, v1, $0002
800CF858	addu   a0, a0, v1
800CF85C	sh     a0, $0000(a1)

Lcf860:	; 800CF860
800CF860	lw     ra, $001c(sp)
800CF864	lw     s0, $0018(sp)
800CF868	addiu  sp, sp, $0020
800CF86C	jr     ra 
800CF870	nop

800CF874	lui    v0, $800a
800CF878	lbu    v0, $d820(v0)
800CF87C	addiu  sp, sp, $ffe0 (=-$20)
800CF880	sw     ra, $001c(sp)
800CF884	andi   v0, v0, $0003
800CF888	beq    v0, zero, Lcf8a0 [$800cf8a0]
800CF88C	sw     s0, $0018(sp)
800CF890	lui    a0, $800a
800CF894	addiu  a0, a0, $0ce4
800CF898	jal    funcbead4 [$800bead4]
800CF89C	ori    a1, zero, $0002

Lcf8a0:	; 800CF8A0
800CF8A0	lui    v0, $8007
800CF8A4	lbu    v0, $22c4(v0)
800CF8A8	nop
800CF8AC	sll    v0, v0, $01
800CF8B0	lui    at, $8008
800CF8B4	addiu  at, at, $31fc
800CF8B8	addu   at, at, v0
800CF8BC	lhu    v1, $0000(at)
800CF8C0	lui    v0, $800a
800CF8C4	lw     v0, $c6dc(v0)
800CF8C8	nop
800CF8CC	addu   v0, v0, v1
800CF8D0	lui    v1, $800a
800CF8D4	lhu    v1, $d78a(v1)
800CF8D8	lbu    v0, $0001(v0)
800CF8DC	lui    s0, $8008
800CF8E0	addiu  s0, s0, $31fc
800CF8E4	srav   v1, v0, v1
800CF8E8	andi   v1, v1, $0001
800CF8EC	beq    v1, zero, Lcf944 [$800cf944]
800CF8F0	nop
800CF8F4	lui    v0, $800a
800CF8F8	lbu    v0, $d820(v0)
800CF8FC	nop
800CF900	andi   v0, v0, $0003
800CF904	beq    v0, zero, Lcf91c [$800cf91c]
800CF908	addu   a1, zero, zero
800CF90C	lui    a0, $800a
800CF910	addiu  a0, a0, $0cec
800CF914	jal    funcbeca4 [$800beca4]
800CF918	addu   a2, zero, zero

Lcf91c:	; 800CF91C
800CF91C	lui    a0, $8007
800CF920	lbu    a0, $22c4(a0)
800CF924	nop
800CF928	sll    a0, a0, $01
800CF92C	addu   a0, a0, s0
800CF930	lhu    v1, $0000(a0)
800CF934	addu   v0, zero, zero
800CF938	addiu  v1, v1, $0003
800CF93C	j      Lcf9a4 [$800cf9a4]
800CF940	sh     v1, $0000(a0)

Lcf944:	; 800CF944
800CF944	lui    v0, $800a
800CF948	lbu    v0, $d820(v0)
800CF94C	nop
800CF950	andi   v0, v0, $0003
800CF954	beq    v0, zero, Lcf96c [$800cf96c]
800CF958	addu   a1, zero, zero
800CF95C	lui    a0, $800a
800CF960	addiu  a0, a0, $0cf8
800CF964	jal    funcbeca4 [$800beca4]
800CF968	addu   a2, zero, zero

Lcf96c:	; 800CF96C
800CF96C	lui    a1, $8007
800CF970	lbu    a1, $22c4(a1)
800CF974	lui    a0, $800a
800CF978	lw     a0, $c6dc(a0)
800CF97C	sll    a1, a1, $01
800CF980	addu   a1, a1, s0
800CF984	lhu    v1, $0000(a1)
800CF988	addu   v0, zero, zero
800CF98C	addu   a0, a0, v1
800CF990	lhu    v1, $0000(a1)
800CF994	lbu    a0, $0002(a0)
800CF998	addiu  v1, v1, $0002
800CF99C	addu   a0, a0, v1
800CF9A0	sh     a0, $0000(a1)

Lcf9a4:	; 800CF9A4
800CF9A4	lw     ra, $001c(sp)
800CF9A8	lw     s0, $0018(sp)
800CF9AC	addiu  sp, sp, $0020
800CF9B0	jr     ra 
800CF9B4	nop



////////////////////////////////
// 0xCD MMBud
800CF9B8-800CFAEC
////////////////////////////////



////////////////////////////////
// 0xCE MMBLK
800CFAF0-800CFB80
////////////////////////////////



////////////////////////////////
// 0xCF MMBUK
800CFB84-800CFC18
////////////////////////////////



////////////////////////////////
// 0xC7 SOLID
800CFC1C-800CFCE0
////////////////////////////////



////////////////////////////////
// 0x6A VWOFT
800CFD10-800CFE74
////////////////////////////////



800CFE78	lui    v0, $800a
800CFE7C	lbu    v0, $d820(v0)
800CFE80	addiu  sp, sp, $ffe8 (=-$18)
800CFE84	sw     ra, $0014(sp)
800CFE88	andi   v0, v0, $0003
800CFE8C	beq    v0, zero, Lcfea4 [$800cfea4]
800CFE90	sw     s0, $0010(sp)
800CFE94	lui    a0, $800a
800CFE98	addiu  a0, a0, $0d2c
800CFE9C	jal    funcbead4 [$800bead4]
800CFEA0	ori    a1, zero, $0001

Lcfea4:	; 800CFEA4
800CFEA4	lui    v0, $8007
800CFEA8	lbu    v0, $22c4(v0)
800CFEAC	lui    a0, $800a
800CFEB0	lbu    a0, $d392(a0)
800CFEB4	lui    at, $800e
800CFEB8	sb     v0, $48f0(at)
800CFEBC	ori    v0, zero, $00ff
800CFEC0	beq    a0, v0, Lcff14 [$800cff14]
800CFEC4	ori    s0, zero, $0001
800CFEC8	lui    v0, $8007
800CFECC	lbu    v0, $22c4(v0)
800CFED0	nop
800CFED4	sll    v0, v0, $01
800CFED8	lui    at, $8008
800CFEDC	addiu  at, at, $31fc
800CFEE0	addu   at, at, v0
800CFEE4	lhu    v1, $0000(at)
800CFEE8	lui    v0, $800a
800CFEEC	lw     v0, $c6dc(v0)
800CFEF0	lui    at, $800a
800CFEF4	addiu  at, at, $ad30 (=-$52d0)
800CFEF8	addu   at, at, a0
800CFEFC	lbu    a0, $0000(at)
800CFF00	addu   v0, v0, v1
800CFF04	lbu    a1, $0001(v0)
800CFF08	jal    funcd0518 [$800d0518]
800CFF0C	nop
800CFF10	addu   s0, v0, zero

Lcff14:	; 800CFF14
800CFF14	lui    a0, $800a
800CFF18	lbu    a0, $d393(a0)
800CFF1C	ori    v0, zero, $00ff
800CFF20	beq    a0, v0, Lcff78 [$800cff78]
800CFF24	nop
800CFF28	lui    v0, $8007
800CFF2C	lbu    v0, $22c4(v0)
800CFF30	nop
800CFF34	sll    v0, v0, $01
800CFF38	lui    at, $8008
800CFF3C	addiu  at, at, $31fc
800CFF40	addu   at, at, v0
800CFF44	lhu    v1, $0000(at)
800CFF48	lui    v0, $800a
800CFF4C	lw     v0, $c6dc(v0)
800CFF50	lui    at, $800a
800CFF54	addiu  at, at, $ad30 (=-$52d0)
800CFF58	addu   at, at, a0
800CFF5C	lbu    a0, $0000(at)
800CFF60	addu   v0, v0, v1
800CFF64	lbu    a1, $0001(v0)
800CFF68	jal    funcd0518 [$800d0518]
800CFF6C	nop
800CFF70	j      Lcff7c [$800cff7c]
800CFF74	addu   v1, v0, zero

Lcff78:	; 800CFF78
800CFF78	ori    v1, zero, $0001

Lcff7c:	; 800CFF7C
800CFF7C	sll    v0, s0, $10
800CFF80	beq    v0, zero, Ld0098 [$800d0098]
800CFF84	sll    v0, v1, $10
800CFF88	beq    v0, zero, Ld0098 [$800d0098]
800CFF8C	addu   a1, zero, zero
800CFF90	ori    a2, zero, $00ff
800CFF94	sll    v0, a1, $10

loopcff98:	; 800CFF98
800CFF98	sra    a0, v0, $10
800CFF9C	lui    at, $800a
800CFFA0	addiu  at, at, $d391 (=-$2c6f)
800CFFA4	addu   at, at, a0
800CFFA8	lbu    v1, $0000(at)
800CFFAC	nop
800CFFB0	beq    v1, a2, Ld0034 [$800d0034]
800CFFB4	addiu  v0, a1, $0001
800CFFB8	lui    at, $800a
800CFFBC	addiu  at, at, $ad30 (=-$52d0)
800CFFC0	addu   at, at, v1
800CFFC4	lbu    v0, $0000(at)
800CFFC8	nop
800CFFCC	lui    at, $8008
800CFFD0	addiu  at, at, $1d90
800CFFD4	addu   at, at, v0
800CFFD8	sb     zero, $0000(at)
800CFFDC	bne    a0, zero, Ld0034 [$800d0034]
800CFFE0	addiu  v0, a1, $0001
800CFFE4	lui    at, $800a
800CFFE8	addiu  at, at, $ad30 (=-$52d0)
800CFFEC	addu   at, at, v1
800CFFF0	lbu    v0, $0000(at)
800CFFF4	nop
800CFFF8	beq    v0, a2, Ld0030 [$800d0030]
800CFFFC	nop
800D0000	lui    at, $8008
800D0004	addiu  at, at, $eb98 (=-$1468)
800D0008	addu   at, at, v0
800D000C	lbu    v0, $0000(at)
800D0010	nop
800D0014	sll    v1, v0, $05
800D0018	addu   v1, v1, v0
800D001C	lui    v0, $800a
800D0020	lw     v0, $c544(v0)
800D0024	sll    v1, v1, $02
800D0028	addu   v1, v1, v0
800D002C	sb     zero, $0059(v1)

Ld0030:	; 800D0030
800D0030	addiu  v0, a1, $0001

Ld0034:	; 800D0034
800D0034	addu   a1, v0, zero
800D0038	sll    v0, v0, $10
800D003C	sra    v0, v0, $10
800D0040	slti   v0, v0, $0003
800D0044	bne    v0, zero, loopcff98 [$800cff98]
800D0048	sll    v0, a1, $10
800D004C	lui    a0, $800a
800D0050	lw     a0, $c6e0(a0)
800D0054	lui    v1, $8008
800D0058	lbu    v1, $1dc4(v1)
800D005C	addu   v0, zero, zero
800D0060	sb     v1, $0032(a0)
800D0064	lui    a1, $8007
800D0068	lbu    a1, $22c4(a1)
800D006C	lui    v1, $8008
800D0070	addiu  v1, v1, $31fc
800D0074	sll    a1, a1, $01
800D0078	addu   a1, a1, v1
800D007C	lhu    v1, $0000(a1)
800D0080	ori    a0, zero, $00ff
800D0084	lui    at, $800e
800D0088	sb     a0, $48f0(at)
800D008C	addiu  v1, v1, $0002
800D0090	j      Ld016c [$800d016c]
800D0094	sh     v1, $0000(a1)

Ld0098:	; 800D0098
800D0098	lui    v0, $800a
800D009C	lw     v0, $c6e0(v0)
800D00A0	ori    a2, zero, $0001
800D00A4	sb     a2, $0032(v0)
800D00A8	lui    v0, $800a
800D00AC	lbu    v0, $d391(v0)
800D00B0	ori    v1, zero, $00ff
800D00B4	beq    v0, v1, Ld0168 [$800d0168]
800D00B8	nop
800D00BC	lui    at, $800a
800D00C0	addiu  at, at, $ad30 (=-$52d0)
800D00C4	addu   at, at, v0
800D00C8	lbu    a1, $0000(at)
800D00CC	nop
800D00D0	beq    a1, v1, Ld016c [$800d016c]
800D00D4	ori    v0, zero, $0001
800D00D8	lui    at, $8008
800D00DC	addiu  at, at, $eb98 (=-$1468)
800D00E0	addu   at, at, a1
800D00E4	lbu    v1, $0000(at)
800D00E8	lui    at, $8008
800D00EC	addiu  at, at, $1d90
800D00F0	addu   at, at, a1
800D00F4	sb     a2, $0000(at)
800D00F8	sll    v0, v1, $05
800D00FC	addu   v0, v0, v1
800D0100	lui    v1, $800a
800D0104	lw     v1, $c544(v1)
800D0108	sll    v0, v0, $02
800D010C	addu   v0, v0, v1
800D0110	sb     zero, $005d(v0)
800D0114	lui    at, $8008
800D0118	addiu  at, at, $eb98 (=-$1468)
800D011C	addu   at, at, a1
800D0120	lbu    v1, $0000(at)
800D0124	lui    a0, $800a
800D0128	lw     a0, $c544(a0)
800D012C	sll    v0, v1, $05
800D0130	addu   v0, v0, v1
800D0134	sll    v0, v0, $02
800D0138	addu   v0, v0, a0
800D013C	sh     zero, $006a(v0)
800D0140	lui    at, $8008
800D0144	addiu  at, at, $eb98 (=-$1468)
800D0148	addu   at, at, a1
800D014C	lbu    v1, $0000(at)
800D0150	nop
800D0154	sll    v0, v1, $05
800D0158	addu   v0, v0, v1
800D015C	sll    v0, v0, $02
800D0160	addu   v0, v0, a0
800D0164	sb     a2, $0059(v0)

Ld0168:	; 800D0168
800D0168	ori    v0, zero, $0001

Ld016c:	; 800D016C
800D016C	lw     ra, $0014(sp)
800D0170	lw     s0, $0010(sp)
800D0174	addiu  sp, sp, $0018
800D0178	jr     ra 
800D017C	nop



////////////////////////////////
// 0x09 SPLIT
800D0180-800D0514
////////////////////////////////



funcd0518:	; 800D0518
800D0518	addiu  sp, sp, $ffa8 (=-$58)
800D051C	sw     s1, $0044(sp)
800D0520	addu   s1, a0, zero
800D0524	sw     s2, $0048(sp)
800D0528	addu   s2, s1, zero
800D052C	sw     s3, $004c(sp)
800D0530	addu   s3, a1, zero
800D0534	lui    a1, $800a
800D0538	lbu    a1, $d391(a1)
800D053C	ori    v0, zero, $00ff
800D0540	sw     ra, $0050(sp)
800D0544	beq    a1, v0, Ld090c [$800d090c]
800D0548	sw     s0, $0040(sp)
800D054C	lui    v0, $800a
800D0550	lbu    v0, $d820(v0)
800D0554	lui    at, $800a
800D0558	addiu  at, at, $ad30 (=-$52d0)
800D055C	addu   at, at, a1
800D0560	lbu    s0, $0000(at)
800D0564	andi   v0, v0, $0003
800D0568	beq    v0, zero, Ld05ac [$800d05ac]
800D056C	addu   a1, s0, zero
800D0570	lui    a0, $800a
800D0574	addiu  a0, a0, $0d3c
800D0578	jal    funcbeca4 [$800beca4]
800D057C	ori    a2, zero, $0002
800D0580	lui    v0, $800a
800D0584	lbu    v0, $d820(v0)
800D0588	nop
800D058C	andi   v0, v0, $0003
800D0590	beq    v0, zero, Ld05ac [$800d05ac]
800D0594	sll    a1, s1, $10
800D0598	lui    a0, $800a
800D059C	addiu  a0, a0, $0d48
800D05A0	sra    a1, a1, $10
800D05A4	jal    funcbeca4 [$800beca4]
800D05A8	ori    a2, zero, $0002

Ld05ac:	; 800D05AC
800D05AC	addu   s1, s0, zero
800D05B0	ori    v1, zero, $00ff
800D05B4	beq    s1, v1, Ld090c [$800d090c]
800D05B8	sll    v0, s2, $10
800D05BC	sra    s0, v0, $10
800D05C0	beq    s0, v1, Ld090c [$800d090c]
800D05C4	ori    v0, zero, $0001
800D05C8	lui    at, $8008
800D05CC	addiu  at, at, $1d90
800D05D0	addu   at, at, s0
800D05D4	lbu    v1, $0000(at)
800D05D8	nop
800D05DC	beq    v1, v0, Ld07ac [$800d07ac]
800D05E0	slti   v0, v1, $0002
800D05E4	beq    v0, zero, Ld05fc [$800d05fc]
800D05E8	nop
800D05EC	beq    v1, zero, Ld0618 [$800d0618]
800D05F0	addiu  a0, sp, $0018
800D05F4	j      Ld0918 [$800d0918]
800D05F8	addu   v0, zero, zero

Ld05fc:	; 800D05FC
800D05FC	ori    v0, zero, $0002
800D0600	beq    v1, v0, Ld0868 [$800d0868]
800D0604	ori    v0, zero, $0003
800D0608	beq    v1, v0, Ld0918 [$800d0918]
800D060C	ori    v0, zero, $0001
800D0610	j      Ld0918 [$800d0918]
800D0614	addu   v0, zero, zero

Ld0618:	; 800D0618
800D0618	lui    at, $8008
800D061C	addiu  at, at, $eb98 (=-$1468)
800D0620	addu   at, at, s0
800D0624	lbu    v1, $0000(at)
800D0628	lui    a2, $800a
800D062C	lw     a2, $c544(a2)
800D0630	sll    v0, v1, $05
800D0634	addu   v0, v0, v1
800D0638	sll    v0, v0, $02
800D063C	addu   v0, v0, a2
800D0640	lw     v0, $000c(v0)
800D0644	nop
800D0648	sra    v0, v0, $0c
800D064C	sw     v0, $0018(sp)
800D0650	lui    at, $8008
800D0654	addiu  at, at, $eb98 (=-$1468)
800D0658	addu   at, at, s0
800D065C	lbu    v1, $0000(at)
800D0660	nop
800D0664	sll    v0, v1, $05
800D0668	addu   v0, v0, v1
800D066C	sll    v0, v0, $02
800D0670	addu   v0, v0, a2
800D0674	lw     v0, $0010(v0)
800D0678	nop
800D067C	sra    v0, v0, $0c
800D0680	sw     v0, $001c(sp)
800D0684	lui    at, $8008
800D0688	addiu  at, at, $eb98 (=-$1468)
800D068C	addu   at, at, s0
800D0690	lbu    v1, $0000(at)
800D0694	nop
800D0698	sll    v0, v1, $05
800D069C	addu   v0, v0, v1
800D06A0	sll    v0, v0, $02
800D06A4	addu   v0, v0, a2
800D06A8	lw     v0, $0014(v0)
800D06AC	nop
800D06B0	sra    v0, v0, $0c
800D06B4	sw     v0, $0020(sp)
800D06B8	lui    at, $8008
800D06BC	addiu  at, at, $eb98 (=-$1468)
800D06C0	addu   at, at, s1
800D06C4	lbu    v1, $0000(at)
800D06C8	nop
800D06CC	sll    v0, v1, $05
800D06D0	addu   v0, v0, v1
800D06D4	sll    v0, v0, $02
800D06D8	addu   v0, v0, a2
800D06DC	lw     v0, $000c(v0)
800D06E0	nop
800D06E4	sra    v0, v0, $0c
800D06E8	sw     v0, $0028(sp)
800D06EC	lui    at, $8008
800D06F0	addiu  at, at, $eb98 (=-$1468)
800D06F4	addu   at, at, s1
800D06F8	lbu    v1, $0000(at)
800D06FC	nop
800D0700	sll    v0, v1, $05
800D0704	addu   v0, v0, v1
800D0708	sll    v0, v0, $02
800D070C	addu   v0, v0, a2
800D0710	lw     v0, $0010(v0)
800D0714	nop
800D0718	sra    v0, v0, $0c
800D071C	sw     v0, $002c(sp)
800D0720	lui    at, $8008
800D0724	addiu  at, at, $eb98 (=-$1468)
800D0728	addu   at, at, s1
800D072C	lbu    v1, $0000(at)
800D0730	addiu  a1, sp, $0028
800D0734	sll    v0, v1, $05
800D0738	addu   v0, v0, v1
800D073C	sll    v0, v0, $02
800D0740	addu   v0, v0, a2
800D0744	lw     v0, $0014(v0)
800D0748	addiu  a2, sp, $0038
800D074C	sra    v0, v0, $0c
800D0750	jal    calculate_direction_by_vectors [$800a8640]
800D0754	sw     v0, $0030(sp)
800D0758	lui    at, $8008
800D075C	addiu  at, at, $eb98 (=-$1468)
800D0760	addu   at, at, s0
800D0764	lbu    a1, $0000(at)
800D0768	addu   a0, s0, zero
800D076C	sll    v1, a1, $05
800D0770	addu   v1, v1, a1
800D0774	lui    a1, $800a
800D0778	lw     a1, $c544(a1)
800D077C	sll    v1, v1, $02
800D0780	addu   v1, v1, a1
800D0784	lbu    a1, $0038(v1)
800D0788	jal    funcd1350 [$800d1350]
800D078C	andi   a2, v0, $00ff
800D0790	ori    v0, zero, $0002
800D0794	lui    at, $8008
800D0798	addiu  at, at, $1d90
800D079C	addu   at, at, s0
800D07A0	sb     v0, $0000(at)
800D07A4	j      Ld0918 [$800d0918]
800D07A8	addu   v0, zero, zero

Ld07ac:	; 800D07AC
800D07AC	jal    funcd1200 [$800d1200]
800D07B0	addu   a0, s0, zero
800D07B4	beq    v0, zero, Ld0914 [$800d0914]
800D07B8	ori    a0, zero, $0001
800D07BC	lui    at, $8008
800D07C0	addiu  at, at, $eb98 (=-$1468)
800D07C4	addu   at, at, s0
800D07C8	lbu    v1, $0000(at)
800D07CC	nop
800D07D0	sll    v0, v1, $05
800D07D4	addu   v0, v0, v1
800D07D8	lui    v1, $800a
800D07DC	lw     v1, $c544(v1)
800D07E0	sll    v0, v0, $02
800D07E4	addu   v0, v0, v1
800D07E8	sb     a0, $0059(v0)
800D07EC	lui    at, $8008
800D07F0	addiu  at, at, $eb98 (=-$1468)
800D07F4	addu   at, at, s0
800D07F8	lbu    v1, $0000(at)
800D07FC	nop
800D0800	sll    v0, v1, $05
800D0804	addu   v0, v0, v1
800D0808	lui    v1, $800a
800D080C	lw     v1, $c544(v1)
800D0810	sll    v0, v0, $02
800D0814	addu   v0, v0, v1
800D0818	sb     a0, $005b(v0)
800D081C	lui    at, $8008
800D0820	addiu  at, at, $eb98 (=-$1468)
800D0824	addu   at, at, s0
800D0828	lbu    a0, $0000(at)
800D082C	nop
800D0830	sll    v1, a0, $05
800D0834	addu   v1, v1, a0
800D0838	lui    a0, $800a
800D083C	lw     a0, $c544(a0)
800D0840	sll    v1, v1, $02
800D0844	addu   v1, v1, a0
800D0848	sb     zero, $005c(v1)
800D084C	ori    v1, zero, $0003
800D0850	lui    at, $8008
800D0854	addiu  at, at, $1d90
800D0858	addu   at, at, s0
800D085C	sb     v1, $0000(at)
800D0860	j      Ld0918 [$800d0918]
800D0864	ori    v0, zero, $0001

Ld0868:	; 800D0868
800D0868	jal    funcd152c [$800d152c]
800D086C	addu   a0, s0, zero
800D0870	beq    v0, zero, Ld0914 [$800d0914]
800D0874	addu   a0, s0, zero
800D0878	lui    at, $8008
800D087C	addiu  at, at, $eb98 (=-$1468)
800D0880	addu   at, at, s1
800D0884	lbu    v1, $0000(at)
800D0888	sll    a3, s3, $10
800D088C	sll    v0, v1, $05
800D0890	addu   v0, v0, v1
800D0894	lui    v1, $800a
800D0898	lw     v1, $c544(v1)
800D089C	sll    v0, v0, $02
800D08A0	addu   v0, v0, v1
800D08A4	lw     a1, $000c(v0)
800D08A8	lw     a2, $0010(v0)
800D08AC	sra    a3, a3, $10
800D08B0	sw     zero, $0010(sp)
800D08B4	sll    a1, a1, $04
800D08B8	sra    a1, a1, $10
800D08BC	sll    a2, a2, $04
800D08C0	jal    funcd0b4c [$800d0b4c]
800D08C4	sra    a2, a2, $10
800D08C8	ori    v0, zero, $0001
800D08CC	lui    at, $8008
800D08D0	addiu  at, at, $1d90
800D08D4	addu   at, at, s0
800D08D8	sb     v0, $0000(at)
800D08DC	lui    v0, $800a
800D08E0	lbu    v0, $d820(v0)
800D08E4	nop
800D08E8	andi   v0, v0, $0003
800D08EC	beq    v0, zero, Ld0914 [$800d0914]
800D08F0	addu   a1, zero, zero
800D08F4	lui    a0, $800a
800D08F8	addiu  a0, a0, $0d54
800D08FC	jal    funcbeca4 [$800beca4]
800D0900	addu   a2, zero, zero
800D0904	j      Ld0918 [$800d0918]
800D0908	addu   v0, zero, zero

Ld090c:	; 800D090C
800D090C	j      Ld0918 [$800d0918]
800D0910	ori    v0, zero, $0001

Ld0914:	; 800D0914
800D0914	addu   v0, zero, zero

Ld0918:	; 800D0918
800D0918	lw     ra, $0050(sp)
800D091C	lw     s3, $004c(sp)
800D0920	lw     s2, $0048(sp)
800D0924	lw     s1, $0044(sp)
800D0928	lw     s0, $0040(sp)
800D092C	addiu  sp, sp, $0058
800D0930	jr     ra 
800D0934	nop



////////////////////////////////////////////////////////
// funcd0938
800D0938-800D0B48
////////////////////////////////////////////////////////



funcd0b4c:	; 800D0B4C
800D0B4C	addiu  sp, sp, $ffa0 (=-$60)
800D0B50	sw     s0, $0038(sp)
800D0B54	addu   s0, a2, zero
800D0B58	lui    a2, $800a
800D0B5C	lbu    a2, $d391(a2)
800D0B60	sw     s7, $0054(sp)
800D0B64	addu   s7, a0, zero
800D0B68	sw     s4, $0048(sp)
800D0B6C	addu   s4, a1, zero
800D0B70	sw     s5, $004c(sp)
800D0B74	addu   s5, s0, zero
800D0B78	sw     s6, $0050(sp)
800D0B7C	addu   s6, a3, zero
800D0B80	sw     s2, $0040(sp)
800D0B84	lhu    s2, $0070(sp)
800D0B88	ori    v0, zero, $00ff
800D0B8C	sw     ra, $0058(sp)
800D0B90	sw     s3, $0044(sp)
800D0B94	beq    a2, v0, Ld11d0 [$800d11d0]
800D0B98	sw     s1, $003c(sp)
800D0B9C	lui    at, $800a
800D0BA0	addiu  at, at, $ad30 (=-$52d0)
800D0BA4	addu   at, at, a2
800D0BA8	lbu    s1, $0000(at)
800D0BAC	nop
800D0BB0	beq    s1, v0, Ld11d0 [$800d11d0]
800D0BB4	nop
800D0BB8	lui    v0, $800a
800D0BBC	lbu    v0, $d820(v0)
800D0BC0	nop
800D0BC4	andi   v0, v0, $0003
800D0BC8	beq    v0, zero, Ld0c14 [$800d0c14]
800D0BCC	ori    s3, zero, $0001
800D0BD0	lui    a0, $800a
800D0BD4	addiu  a0, a0, $0d6c
800D0BD8	sll    a1, a1, $10
800D0BDC	sra    a1, a1, $10
800D0BE0	jal    funcbeca4 [$800beca4]
800D0BE4	ori    a2, zero, $0004
800D0BE8	lui    v0, $800a
800D0BEC	lbu    v0, $d820(v0)
800D0BF0	nop
800D0BF4	andi   v0, v0, $0003
800D0BF8	beq    v0, zero, Ld0c14 [$800d0c14]
800D0BFC	sll    a1, s0, $10
800D0C00	lui    a0, $800a
800D0C04	addiu  a0, a0, $0d78
800D0C08	sra    a1, a1, $10
800D0C0C	jal    funcbeca4 [$800beca4]
800D0C10	ori    a2, zero, $0004

Ld0c14:	; 800D0C14
800D0C14	sll    v0, s7, $10
800D0C18	sra    s0, v0, $10
800D0C1C	lui    at, $8008
800D0C20	addiu  at, at, $eb98 (=-$1468)
800D0C24	addu   at, at, s0
800D0C28	lbu    v1, $0000(at)
800D0C2C	nop
800D0C30	sll    v0, v1, $05
800D0C34	addu   v0, v0, v1
800D0C38	lui    v1, $800a
800D0C3C	lw     v1, $c544(v1)
800D0C40	sll    v0, v0, $02
800D0C44	addu   v0, v0, v1
800D0C48	sb     s3, $005c(v0)
800D0C4C	lui    at, $8008
800D0C50	addiu  at, at, $eb98 (=-$1468)
800D0C54	addu   at, at, s0
800D0C58	lbu    v1, $0000(at)
800D0C5C	nop
800D0C60	sll    v0, v1, $05
800D0C64	addu   v0, v0, v1
800D0C68	lui    v1, $800a
800D0C6C	lw     v1, $c544(v1)
800D0C70	sll    v0, v0, $02
800D0C74	addu   v0, v0, v1
800D0C78	sb     s3, $0059(v0)
800D0C7C	lui    at, $8008
800D0C80	addiu  at, at, $eb98 (=-$1468)
800D0C84	addu   at, at, s0
800D0C88	lbu    v1, $0000(at)
800D0C8C	nop
800D0C90	sll    v0, v1, $05
800D0C94	addu   v0, v0, v1
800D0C98	lui    v1, $800a
800D0C9C	lw     v1, $c544(v1)
800D0CA0	sll    v0, v0, $02
800D0CA4	addu   v0, v0, v1
800D0CA8	beq    s2, zero, Ld0ddc [$800d0ddc]
800D0CAC	sb     s3, $005b(v0)
800D0CB0	addu   a2, s1, zero
800D0CB4	lui    at, $8008
800D0CB8	addiu  at, at, $eb98 (=-$1468)
800D0CBC	addu   at, at, s0
800D0CC0	lbu    v0, $0000(at)
800D0CC4	lui    at, $8008
800D0CC8	addiu  at, at, $eb98 (=-$1468)
800D0CCC	addu   at, at, a2
800D0CD0	lbu    a0, $0000(at)
800D0CD4	lui    a1, $800a
800D0CD8	lw     a1, $c544(a1)
800D0CDC	sll    v1, v0, $05
800D0CE0	addu   v1, v1, v0
800D0CE4	sll    v1, v1, $02
800D0CE8	sll    v0, a0, $05
800D0CEC	addu   v0, v0, a0
800D0CF0	sll    v0, v0, $02
800D0CF4	addu   v0, v0, a1
800D0CF8	lw     v0, $000c(v0)
800D0CFC	addu   v1, v1, a1
800D0D00	sw     v0, $000c(v1)
800D0D04	lui    at, $8008
800D0D08	addiu  at, at, $eb98 (=-$1468)
800D0D0C	addu   at, at, s0
800D0D10	lbu    v0, $0000(at)
800D0D14	lui    at, $8008
800D0D18	addiu  at, at, $eb98 (=-$1468)
800D0D1C	addu   at, at, a2
800D0D20	lbu    a0, $0000(at)
800D0D24	sll    v1, v0, $05
800D0D28	addu   v1, v1, v0
800D0D2C	sll    v1, v1, $02
800D0D30	sll    v0, a0, $05
800D0D34	addu   v0, v0, a0
800D0D38	sll    v0, v0, $02
800D0D3C	addu   v0, v0, a1
800D0D40	lw     v0, $0010(v0)
800D0D44	addu   v1, v1, a1
800D0D48	sw     v0, $0010(v1)
800D0D4C	lui    at, $8008
800D0D50	addiu  at, at, $eb98 (=-$1468)
800D0D54	addu   at, at, s0
800D0D58	lbu    v0, $0000(at)
800D0D5C	lui    at, $8008
800D0D60	addiu  at, at, $eb98 (=-$1468)
800D0D64	addu   at, at, a2
800D0D68	lbu    a0, $0000(at)
800D0D6C	sll    v1, v0, $05
800D0D70	addu   v1, v1, v0
800D0D74	sll    v1, v1, $02
800D0D78	sll    v0, a0, $05
800D0D7C	addu   v0, v0, a0
800D0D80	sll    v0, v0, $02
800D0D84	addu   v0, v0, a1
800D0D88	lw     v0, $0014(v0)
800D0D8C	addu   v1, v1, a1
800D0D90	sw     v0, $0014(v1)
800D0D94	lui    at, $8008
800D0D98	addiu  at, at, $eb98 (=-$1468)
800D0D9C	addu   at, at, s0
800D0DA0	lbu    v0, $0000(at)
800D0DA4	lui    at, $8008
800D0DA8	addiu  at, at, $eb98 (=-$1468)
800D0DAC	addu   at, at, a2
800D0DB0	lbu    a0, $0000(at)
800D0DB4	sll    v1, v0, $05
800D0DB8	addu   v1, v1, v0
800D0DBC	sll    v1, v1, $02
800D0DC0	sll    v0, a0, $05
800D0DC4	addu   v0, v0, a0
800D0DC8	sll    v0, v0, $02
800D0DCC	addu   v0, v0, a1
800D0DD0	lhu    v0, $0072(v0)
800D0DD4	addu   v1, v1, a1
800D0DD8	sh     v0, $0072(v1)

Ld0ddc:	; 800D0DDC
800D0DDC	sll    a3, s4, $10
800D0DE0	sra    a3, a3, $10
800D0DE4	lui    at, $8008
800D0DE8	addiu  at, at, $eb98 (=-$1468)
800D0DEC	addu   at, at, s0
800D0DF0	lbu    v1, $0000(at)
800D0DF4	lui    a0, $800a
800D0DF8	lw     a0, $c544(a0)
800D0DFC	sll    v0, v1, $05
800D0E00	addu   v0, v0, v1
800D0E04	sll    v0, v0, $02
800D0E08	addu   v0, v0, a0
800D0E0C	sh     zero, $0068(v0)
800D0E10	lui    at, $8008
800D0E14	addiu  at, at, $eb98 (=-$1468)
800D0E18	addu   at, at, s0
800D0E1C	lbu    v1, $0000(at)
800D0E20	sll    a1, s5, $10
800D0E24	sll    v0, v1, $05
800D0E28	addu   v0, v0, v1
800D0E2C	sll    v0, v0, $02
800D0E30	addu   v0, v0, a0
800D0E34	sb     zero, $0037(v0)
800D0E38	lui    at, $8008
800D0E3C	addiu  at, at, $eb98 (=-$1468)
800D0E40	addu   at, at, s0
800D0E44	lbu    v1, $0000(at)
800D0E48	lui    a2, $800a
800D0E4C	lw     a2, $c544(a2)
800D0E50	sll    v0, v1, $05
800D0E54	addu   v0, v0, v1
800D0E58	sll    v0, v0, $02
800D0E5C	addu   v0, v0, a2
800D0E60	sll    v1, a3, $0c
800D0E64	sw     v1, $0078(v0)
800D0E68	lui    at, $8008
800D0E6C	addiu  at, at, $eb98 (=-$1468)
800D0E70	addu   at, at, s0
800D0E74	lbu    v1, $0000(at)
800D0E78	sra    a1, a1, $10
800D0E7C	sll    v0, v1, $05
800D0E80	addu   v0, v0, v1
800D0E84	sll    v0, v0, $02
800D0E88	addu   v0, v0, a2
800D0E8C	sll    v1, a1, $0c
800D0E90	sw     v1, $007c(v0)
800D0E94	lui    at, $8008
800D0E98	addiu  at, at, $eb98 (=-$1468)
800D0E9C	addu   at, at, s0
800D0EA0	lbu    v1, $0000(at)
800D0EA4	lui    at, $8008
800D0EA8	addiu  at, at, $eb98 (=-$1468)
800D0EAC	addu   at, at, s0
800D0EB0	lbu    a0, $0000(at)
800D0EB4	sll    v0, v1, $05
800D0EB8	addu   v0, v0, v1
800D0EBC	sll    v0, v0, $02
800D0EC0	addu   v0, v0, a2
800D0EC4	lhu    v0, $0070(v0)
800D0EC8	sll    v1, v1, $01
800D0ECC	lui    at, $800e
800D0ED0	addiu  at, at, $42a8
800D0ED4	addu   at, at, v1
800D0ED8	sh     v0, $0000(at)
800D0EDC	sll    v0, a0, $05
800D0EE0	addu   v0, v0, a0
800D0EE4	sll    v0, v0, $02
800D0EE8	addu   v0, v0, a2
800D0EEC	lw     v0, $000c(v0)
800D0EF0	nop
800D0EF4	sra    v0, v0, $0c
800D0EF8	sw     v0, $0010(sp)
800D0EFC	lui    at, $8008
800D0F00	addiu  at, at, $eb98 (=-$1468)
800D0F04	addu   at, at, s0
800D0F08	lbu    v1, $0000(at)
800D0F0C	nop
800D0F10	sll    v0, v1, $05
800D0F14	addu   v0, v0, v1
800D0F18	sll    v0, v0, $02
800D0F1C	addu   v0, v0, a2
800D0F20	lw     v0, $0010(v0)
800D0F24	nop
800D0F28	sra    v0, v0, $0c
800D0F2C	sw     v0, $0014(sp)
800D0F30	lui    at, $8008
800D0F34	addiu  at, at, $eb98 (=-$1468)
800D0F38	addu   at, at, s0
800D0F3C	lbu    v1, $0000(at)
800D0F40	nop
800D0F44	sll    v0, v1, $05
800D0F48	addu   v0, v0, v1
800D0F4C	sll    v0, v0, $02
800D0F50	addu   v0, v0, a2
800D0F54	lw     v0, $0014(v0)
800D0F58	addiu  a0, sp, $0010
800D0F5C	sw     a3, $0020(sp)
800D0F60	sw     a1, $0024(sp)
800D0F64	sra    v0, v0, $0c
800D0F68	sw     v0, $0018(sp)
800D0F6C	lui    at, $8008
800D0F70	addiu  at, at, $eb98 (=-$1468)
800D0F74	addu   at, at, s0
800D0F78	lbu    v1, $0000(at)
800D0F7C	addiu  a1, sp, $0020
800D0F80	sll    v0, v1, $05
800D0F84	addu   v0, v0, v1
800D0F88	sll    v0, v0, $02
800D0F8C	addu   v0, v0, a2
800D0F90	lw     v0, $0014(v0)
800D0F94	addiu  a2, sp, $0030
800D0F98	sra    v0, v0, $0c
800D0F9C	jal    calculate_direction_by_vectors [$800a8640]
800D0FA0	sw     v0, $0028(sp)
800D0FA4	sll    v0, s6, $10
800D0FA8	lw     a0, $0030(sp)
800D0FAC	sra    v0, v0, $10
800D0FB0	sll    a0, a0, $08
800D0FB4	div    a0, v0
800D0FB8	bne    v0, zero, Ld0fc4 [$800d0fc4]
800D0FBC	nop
800D0FC0	break   $01c00

Ld0fc4:	; 800D0FC4
800D0FC4	addiu  at, zero, $ffff (=-$1)
800D0FC8	bne    v0, at, Ld0fdc [$800d0fdc]
800D0FCC	lui    at, $8000
800D0FD0	bne    a0, at, Ld0fdc [$800d0fdc]
800D0FD4	nop
800D0FD8	break   $01800

Ld0fdc:	; 800D0FDC
800D0FDC	mflo   a0
800D0FE0	lui    at, $8008
800D0FE4	addiu  at, at, $eb98 (=-$1468)
800D0FE8	addu   at, at, s0
800D0FEC	lbu    v1, $0000(at)
800D0FF0	lui    a1, $800a
800D0FF4	lw     a1, $c544(a1)
800D0FF8	sll    v0, v1, $05
800D0FFC	addu   v0, v0, v1
800D1000	sll    v0, v0, $02
800D1004	addu   v0, v0, a1
800D1008	sh     a0, $0070(v0)
800D100C	lui    at, $8008
800D1010	addiu  at, at, $eb98 (=-$1468)
800D1014	addu   at, at, s0
800D1018	lbu    v1, $0000(at)
800D101C	nop
800D1020	sll    v0, v1, $05
800D1024	addu   v0, v0, v1
800D1028	sll    v0, v0, $02
800D102C	addu   a0, v0, a1
800D1030	lhu    v0, $0070(a0)
800D1034	nop
800D1038	sltiu  v0, v0, $0601
800D103C	bne    v0, zero, Ld105c [$800d105c]
800D1040	ori    v0, zero, $0001
800D1044	lbu    v1, $005e(a0)
800D1048	ori    v0, zero, $0002
800D104C	beq    v1, v0, Ld1148 [$800d1148]
800D1050	ori    v0, zero, $0002
800D1054	j      Ld1070 [$800d1070]
800D1058	sb     v0, $005e(a0)

Ld105c:	; 800D105C
800D105C	lbu    v1, $005e(a0)
800D1060	nop
800D1064	beq    v1, v0, Ld114c [$800d114c]
800D1068	sll    v1, s7, $10
800D106C	sb     s3, $005e(a0)

Ld1070:	; 800D1070
800D1070	lui    at, $8008
800D1074	addiu  at, at, $eb98 (=-$1468)
800D1078	addu   at, at, s0
800D107C	lbu    v1, $0000(at)
800D1080	lui    a2, $800a
800D1084	lw     a2, $c544(a2)
800D1088	sll    v0, v1, $05
800D108C	addu   v0, v0, v1
800D1090	sll    v0, v0, $02
800D1094	addu   v0, v0, a2
800D1098	ori    v1, zero, $0010
800D109C	sh     v1, $0060(v0)
800D10A0	lui    at, $8008
800D10A4	addiu  at, at, $eb98 (=-$1468)
800D10A8	addu   at, at, s0
800D10AC	lbu    v1, $0000(at)
800D10B0	nop
800D10B4	sll    v0, v1, $05
800D10B8	addu   v0, v0, v1
800D10BC	sll    v0, v0, $02
800D10C0	addu   v0, v0, a2
800D10C4	sh     zero, $0062(v0)
800D10C8	lui    at, $8008
800D10CC	addiu  at, at, $eb98 (=-$1468)
800D10D0	addu   at, at, s0
800D10D4	lbu    a0, $0000(at)
800D10D8	lui    v1, $8008
800D10DC	lw     v1, $357c(v1)
800D10E0	sll    v0, a0, $03
800D10E4	addu   v0, v0, v1
800D10E8	lbu    a1, $0004(v0)
800D10EC	lui    v1, $8005
800D10F0	lw     v1, $a62c(v1)
800D10F4	sll    v0, a1, $03
800D10F8	addu   v0, v0, a1
800D10FC	lw     v1, $0004(v1)
800D1100	sll    v0, v0, $02
800D1104	addu   v0, v0, v1
800D1108	sll    v1, a0, $05
800D110C	addu   v1, v1, a0
800D1110	sll    v1, v1, $02
800D1114	lhu    a1, $001a(v0)
800D1118	lw     a0, $001c(v0)
800D111C	lui    at, $8007
800D1120	addiu  at, at, $4f02
800D1124	addu   at, at, v1
800D1128	lbu    v0, $0000(at)
800D112C	addu   a1, a1, a0
800D1130	sll    v0, v0, $04
800D1134	addu   v0, v0, a1
800D1138	lhu    v0, $0000(v0)
800D113C	addu   v1, v1, a2
800D1140	addiu  v0, v0, $ffff (=-$1)
800D1144	sh     v0, $0064(v1)

Ld1148:	; 800D1148
800D1148	sll    v1, s7, $10

Ld114c:	; 800D114C
800D114C	sra    v1, v1, $10
800D1150	lui    at, $8008
800D1154	addiu  at, at, $eb98 (=-$1468)
800D1158	addu   at, at, v1
800D115C	lbu    v0, $0000(at)
800D1160	lui    at, $8008
800D1164	addiu  at, at, $eb98 (=-$1468)
800D1168	addu   at, at, v1
800D116C	lbu    a0, $0000(at)
800D1170	ori    a1, zero, $0001
800D1174	lui    at, $8007
800D1178	addiu  at, at, $56e8
800D117C	addu   at, at, v0
800D1180	sb     a1, $0000(at)
800D1184	sll    v0, a0, $05
800D1188	addu   v0, v0, a0
800D118C	lui    a0, $800a
800D1190	lw     a0, $c544(a0)
800D1194	sll    v0, v0, $02
800D1198	addu   v0, v0, a0
800D119C	sb     a1, $005d(v0)
800D11A0	lui    at, $8008
800D11A4	addiu  at, at, $eb98 (=-$1468)
800D11A8	addu   at, at, v1
800D11AC	lbu    v1, $0000(at)
800D11B0	nop
800D11B4	sll    v0, v1, $05
800D11B8	addu   v0, v0, v1
800D11BC	lui    v1, $800a
800D11C0	lw     v1, $c544(v1)
800D11C4	sll    v0, v0, $02
800D11C8	addu   v0, v0, v1
800D11CC	sh     zero, $006a(v0)

Ld11d0:	; 800D11D0
800D11D0	lw     ra, $0058(sp)
800D11D4	lw     s7, $0054(sp)
800D11D8	lw     s6, $0050(sp)
800D11DC	lw     s5, $004c(sp)
800D11E0	lw     s4, $0048(sp)
800D11E4	lw     s3, $0044(sp)
800D11E8	lw     s2, $0040(sp)
800D11EC	lw     s1, $003c(sp)
800D11F0	lw     s0, $0038(sp)
800D11F4	addiu  sp, sp, $0060
800D11F8	jr     ra 
800D11FC	nop


funcd1200:	; 800D1200
800D1200	addiu  sp, sp, $ffe8 (=-$18)
800D1204	sll    a0, a0, $10
800D1208	sw     s0, $0010(sp)
800D120C	sra    s0, a0, $10
800D1210	sw     ra, $0014(sp)
800D1214	lui    at, $8008
800D1218	addiu  at, at, $eb98 (=-$1468)
800D121C	addu   at, at, s0
800D1220	lbu    v1, $0000(at)
800D1224	nop
800D1228	sll    v0, v1, $05
800D122C	addu   v0, v0, v1
800D1230	lui    v1, $800a
800D1234	lw     v1, $c544(v1)
800D1238	sll    v0, v0, $02
800D123C	addu   v0, v0, v1
800D1240	lh     v1, $006a(v0)
800D1244	ori    v0, zero, $0002
800D1248	bne    v1, v0, Ld133c [$800d133c]
800D124C	addu   v0, zero, zero
800D1250	lui    v0, $800a
800D1254	lbu    v0, $d820(v0)
800D1258	nop
800D125C	andi   v0, v0, $0003
800D1260	beq    v0, zero, Ld1278 [$800d1278]
800D1264	addu   a1, zero, zero
800D1268	lui    a0, $800a
800D126C	addiu  a0, a0, $0d84
800D1270	jal    funcbeca4 [$800beca4]
800D1274	addu   a2, zero, zero

Ld1278:	; 800D1278
800D1278	lui    at, $8008
800D127C	addiu  at, at, $eb98 (=-$1468)
800D1280	addu   at, at, s0
800D1284	lbu    v1, $0000(at)
800D1288	nop
800D128C	sll    v0, v1, $05
800D1290	addu   v0, v0, v1
800D1294	lui    v1, $800a
800D1298	lw     v1, $c544(v1)
800D129C	sll    v0, v0, $02
800D12A0	addu   v0, v0, v1
800D12A4	sb     zero, $005d(v0)
800D12A8	lui    at, $8008
800D12AC	addiu  at, at, $eb98 (=-$1468)
800D12B0	addu   at, at, s0
800D12B4	lbu    v1, $0000(at)
800D12B8	nop
800D12BC	sll    v0, v1, $05
800D12C0	addu   v0, v0, v1
800D12C4	lui    v1, $800a
800D12C8	lw     v1, $c544(v1)
800D12CC	sll    v0, v0, $02
800D12D0	addu   v0, v0, v1
800D12D4	sh     zero, $006a(v0)
800D12D8	lui    at, $8008
800D12DC	addiu  at, at, $eb98 (=-$1468)
800D12E0	addu   at, at, s0
800D12E4	lbu    v1, $0000(at)
800D12E8	lui    at, $8008
800D12EC	addiu  at, at, $eb98 (=-$1468)
800D12F0	addu   at, at, s0
800D12F4	lbu    a0, $0000(at)
800D12F8	ori    v0, zero, $0001
800D12FC	lui    at, $8007
800D1300	addiu  at, at, $56e8
800D1304	addu   at, at, v1
800D1308	sb     zero, $0000(at)
800D130C	sll    v1, a0, $05
800D1310	addu   v1, v1, a0
800D1314	sll    v1, v1, $02
800D1318	sll    a0, a0, $01
800D131C	lui    a1, $800a
800D1320	lw     a1, $c544(a1)
800D1324	lui    at, $800e
800D1328	addiu  at, at, $42a8
800D132C	addu   at, at, a0
800D1330	lhu    a0, $0000(at)
800D1334	addu   v1, v1, a1
800D1338	sh     a0, $0070(v1)

Ld133c:	; 800D133C
800D133C	lw     ra, $0014(sp)
800D1340	lw     s0, $0010(sp)
800D1344	addiu  sp, sp, $0018
800D1348	jr     ra 
800D134C	nop


funcd1350:	; 800D1350
800D1350	lui    v0, $800a
800D1354	lbu    v0, $d820(v0)
800D1358	addiu  sp, sp, $ffe0 (=-$20)
800D135C	sw     s0, $0010(sp)
800D1360	addu   s0, a0, zero
800D1364	sw     s1, $0014(sp)
800D1368	addu   s1, a1, zero
800D136C	sw     s2, $0018(sp)
800D1370	addu   s2, a2, zero
800D1374	andi   v0, v0, $0003
800D1378	beq    v0, zero, Ld1394 [$800d1394]
800D137C	sw     ra, $001c(sp)
800D1380	lui    a0, $800a
800D1384	addiu  a0, a0, $0d90
800D1388	andi   a1, s2, $00ff
800D138C	jal    funcbeca4 [$800beca4]
800D1390	ori    a2, zero, $0002

Ld1394:	; 800D1394
800D1394	sll    v0, s0, $10
800D1398	sra    a1, v0, $10
800D139C	lui    at, $8008
800D13A0	addiu  at, at, $eb98 (=-$1468)
800D13A4	addu   at, at, a1
800D13A8	lbu    v1, $0000(at)
800D13AC	ori    v0, zero, $00ff
800D13B0	beq    v1, v0, Ld1510 [$800d1510]
800D13B4	sll    v0, v1, $05
800D13B8	addu   v0, v0, v1
800D13BC	sll    v0, v0, $02
800D13C0	lui    a0, $800a
800D13C4	lw     a0, $c544(a0)
800D13C8	andi   v1, s1, $00ff
800D13CC	addu   v0, v0, a0
800D13D0	sh     v1, $003c(v0)
800D13D4	lui    at, $8008
800D13D8	addiu  at, at, $eb98 (=-$1468)
800D13DC	addu   at, at, a1
800D13E0	lbu    v1, $0000(at)
800D13E4	nop
800D13E8	sll    v0, v1, $05
800D13EC	addu   v0, v0, v1
800D13F0	sll    v0, v0, $02
800D13F4	addu   v0, v0, a0
800D13F8	ori    v1, zero, $0002
800D13FC	sb     v1, $003b(v0)
800D1400	lui    at, $8008
800D1404	addiu  at, at, $eb98 (=-$1468)
800D1408	addu   at, at, a1
800D140C	lbu    v1, $0000(at)
800D1410	nop
800D1414	sll    v0, v1, $05
800D1418	addu   v0, v0, v1
800D141C	lui    v1, $800a
800D1420	lw     v1, $c544(v1)
800D1424	sll    v0, v0, $02
800D1428	addu   v0, v0, v1
800D142C	sb     zero, $003a(v0)
800D1430	lui    at, $8008
800D1434	addiu  at, at, $eb98 (=-$1468)
800D1438	addu   at, at, a1
800D143C	lbu    v1, $0000(at)
800D1440	nop
800D1444	sll    v0, v1, $05
800D1448	addu   v0, v0, v1
800D144C	lui    v1, $800a
800D1450	lw     v1, $c544(v1)
800D1454	sll    v0, v0, $02
800D1458	addu   v0, v0, v1
800D145C	ori    v1, zero, $0010
800D1460	sb     v1, $0039(v0)
800D1464	lui    at, $8008
800D1468	addiu  at, at, $eb98 (=-$1468)
800D146C	addu   at, at, a1
800D1470	lbu    v1, $0000(at)
800D1474	lui    a0, $800a
800D1478	lw     a0, $c544(a0)
800D147C	sll    v0, v1, $05
800D1480	addu   v0, v0, v1
800D1484	sll    v0, v0, $02
800D1488	addu   v0, v0, a0
800D148C	andi   v1, s2, $00ff
800D1490	sh     v1, $003e(v0)
800D1494	lui    at, $8008
800D1498	addiu  at, at, $eb98 (=-$1468)
800D149C	addu   at, at, a1
800D14A0	lbu    v1, $0000(at)
800D14A4	nop
800D14A8	sll    v0, v1, $05
800D14AC	addu   v0, v0, v1
800D14B0	sll    v0, v0, $02
800D14B4	addu   a2, v0, a0
800D14B8	lhu    a1, $003e(a2)
800D14BC	lhu    a3, $003c(a2)
800D14C0	nop
800D14C4	subu   v1, a1, a3
800D14C8	sll    v0, v1, $10
800D14CC	bgez   v0, Ld14dc [$800d14dc]
800D14D0	addu   a0, v1, zero
800D14D4	nor    v0, zero, v1
800D14D8	addiu  a0, v0, $0001

Ld14dc:	; 800D14DC
800D14DC	sll    v0, a0, $10
800D14E0	sra    v0, v0, $10
800D14E4	slti   v0, v0, $0081
800D14E8	bne    v0, zero, Ld1510 [$800d1510]
800D14EC	sll    v1, a1, $10
800D14F0	sra    v1, v1, $10
800D14F4	sll    v0, a3, $10
800D14F8	sra    v0, v0, $10
800D14FC	slt    v0, v0, v1
800D1500	bne    v0, zero, Ld150c [$800d150c]
800D1504	addiu  v0, a1, $ff00 (=-$100)
800D1508	addiu  v0, a1, $0100

Ld150c:	; 800D150C
800D150C	sh     v0, $003e(a2)

Ld1510:	; 800D1510
800D1510	lw     ra, $001c(sp)
800D1514	lw     s2, $0018(sp)
800D1518	lw     s1, $0014(sp)
800D151C	lw     s0, $0010(sp)
800D1520	addiu  sp, sp, $0020
800D1524	jr     ra 
800D1528	nop


funcd152c:	; 800D152C
800D152C	addiu  sp, sp, $ffe8 (=-$18)
800D1530	sll    a0, a0, $10
800D1534	sw     s0, $0010(sp)
800D1538	sra    s0, a0, $10
800D153C	sw     ra, $0014(sp)
800D1540	lui    at, $8008
800D1544	addiu  at, at, $eb98 (=-$1468)
800D1548	addu   at, at, s0
800D154C	lbu    v1, $0000(at)
800D1550	ori    v0, zero, $00ff
800D1554	bne    v1, v0, Ld1564 [$800d1564]
800D1558	sll    v0, v1, $05
800D155C	j      Ld1640 [$800d1640]
800D1560	ori    v0, zero, $0001

Ld1564:	; 800D1564
800D1564	addu   v0, v0, v1
800D1568	lui    v1, $800a
800D156C	lw     v1, $c544(v1)
800D1570	sll    v0, v0, $02
800D1574	addu   v0, v0, v1
800D1578	lbu    v1, $003b(v0)
800D157C	ori    v0, zero, $0003
800D1580	bne    v1, v0, Ld1640 [$800d1640]
800D1584	addu   v0, zero, zero
800D1588	lui    v0, $800a
800D158C	lbu    v0, $d820(v0)
800D1590	nop
800D1594	andi   v0, v0, $0003
800D1598	beq    v0, zero, Ld15b0 [$800d15b0]
800D159C	addu   a1, zero, zero
800D15A0	lui    a0, $800a
800D15A4	addiu  a0, a0, $0d9c
800D15A8	jal    funcbeca4 [$800beca4]
800D15AC	addu   a2, zero, zero

Ld15b0:	; 800D15B0
800D15B0	lui    at, $8008
800D15B4	addiu  at, at, $eb98 (=-$1468)
800D15B8	addu   at, at, s0
800D15BC	lbu    v1, $0000(at)
800D15C0	nop
800D15C4	sll    v0, v1, $05
800D15C8	addu   v0, v0, v1
800D15CC	lui    v1, $800a
800D15D0	lw     v1, $c544(v1)
800D15D4	sll    v0, v0, $02
800D15D8	addu   v0, v0, v1
800D15DC	sb     zero, $003b(v0)
800D15E0	lui    at, $8008
800D15E4	addiu  at, at, $eb98 (=-$1468)
800D15E8	addu   at, at, s0
800D15EC	lbu    v1, $0000(at)
800D15F0	nop
800D15F4	sll    v0, v1, $05
800D15F8	addu   v0, v0, v1
800D15FC	lui    v1, $800a
800D1600	lw     v1, $c544(v1)
800D1604	sll    v0, v0, $02
800D1608	addu   v0, v0, v1
800D160C	sb     zero, $003a(v0)
800D1610	lui    at, $8008
800D1614	addiu  at, at, $eb98 (=-$1468)
800D1618	addu   at, at, s0
800D161C	lbu    a0, $0000(at)
800D1620	ori    v0, zero, $0001
800D1624	sll    v1, a0, $05
800D1628	addu   v1, v1, a0
800D162C	lui    a0, $800a
800D1630	lw     a0, $c544(a0)
800D1634	sll    v1, v1, $02
800D1638	addu   v1, v1, a0
800D163C	sb     zero, $0039(v1)

Ld1640:	; 800D1640
800D1640	lw     ra, $0014(sp)
800D1644	lw     s0, $0010(sp)
800D1648	addiu  sp, sp, $0018
800D164C	jr     ra 
800D1650	nop



////////////////////////////////
// 0x6B FADE
800D1654-800D1848
////////////////////////////////



////////////////////////////////
// 0x25 NFADE
800D184C-800D1958
////////////////////////////////



////////////////////////////////
// 0x6C FADEW
800D195C-800D1A7C
////////////////////////////////



////////////////////////////////
// 0x6D IDLCK
800D1A80-800D1B90
////////////////////////////////



////////////////////////////////
// 0x56 GWCOL
800D1B94-800D1C64
////////////////////////////////



////////////////////////////////
// 0x57 SWCOL
800D1C68-800D1D38
////////////////////////////////



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
// 0x5E SHAKE
800D1DB8-800D1F1C
////////////////////////////////



800D1F20	lui    v0, $800a
800D1F24	lbu    v0, $d820(v0)
800D1F28	addiu  sp, sp, $ffe8 (=-$18)
800D1F2C	sw     ra, $0014(sp)
800D1F30	andi   v0, v0, $0003
800D1F34	beq    v0, zero, Ld1f4c [$800d1f4c]
800D1F38	sw     s0, $0010(sp)
800D1F3C	lui    a0, $800a
800D1F40	addiu  a0, a0, $0e48
800D1F44	jal    funcbead4 [$800bead4]
800D1F48	ori    a1, zero, $0004

Ld1f4c:	; 800D1F4C
800D1F4C	ori    a0, zero, $0002
800D1F50	jal    read_memory_block_one_byte [$800bee10]
800D1F54	ori    a1, zero, $0004
800D1F58	ori    a0, zero, $0001
800D1F5C	ori    a1, zero, $0002
800D1F60	andi   s0, v0, $00ff
800D1F64	jal    read_memory_block_two_bytes [$800bf908]
800D1F68	sll    s0, s0, $09
800D1F6C	lui    v1, $800a
800D1F70	lbu    v1, $d820(v1)
800D1F74	nop
800D1F78	andi   v1, v1, $0003
800D1F7C	beq    v1, zero, Ld1f98 [$800d1f98]
800D1F80	or     s0, s0, v0
800D1F84	lui    a0, $800a
800D1F88	addiu  a0, a0, $0e50
800D1F8C	andi   a1, s0, $ffff
800D1F90	jal    funcbeca4 [$800beca4]
800D1F94	ori    a2, zero, $0004

Ld1f98:	; 800D1F98
800D1F98	jal    func25380 [$80025380]
800D1F9C	andi   a0, s0, $ffff
800D1FA0	lui    v1, $8007
800D1FA4	lbu    v1, $22c4(v1)
800D1FA8	lui    v0, $8008
800D1FAC	addiu  v0, v0, $31fc
800D1FB0	sll    v1, v1, $01
800D1FB4	addu   v1, v1, v0
800D1FB8	lhu    a0, $0000(v1)
800D1FBC	addu   v0, zero, zero
800D1FC0	addiu  a0, a0, $0005
800D1FC4	sh     a0, $0000(v1)
800D1FC8	lw     ra, $0014(sp)
800D1FCC	lw     s0, $0010(sp)
800D1FD0	addiu  sp, sp, $0018
800D1FD4	jr     ra 
800D1FD8	nop

800D1FDC	lui    v0, $800a
800D1FE0	lbu    v0, $d820(v0)
800D1FE4	addiu  sp, sp, $ffe8 (=-$18)
800D1FE8	sw     ra, $0014(sp)
800D1FEC	andi   v0, v0, $0003
800D1FF0	beq    v0, zero, Ld2008 [$800d2008]
800D1FF4	sw     s0, $0010(sp)
800D1FF8	lui    a0, $800a
800D1FFC	addiu  a0, a0, $0e58
800D2000	jal    funcbead4 [$800bead4]
800D2004	ori    a1, zero, $0004

Ld2008:	; 800D2008
800D2008	ori    a0, zero, $0002
800D200C	jal    read_memory_block_one_byte [$800bee10]
800D2010	ori    a1, zero, $0004
800D2014	ori    a0, zero, $0001
800D2018	ori    a1, zero, $0002
800D201C	andi   s0, v0, $00ff
800D2020	jal    read_memory_block_two_bytes [$800bf908]
800D2024	sll    s0, s0, $09
800D2028	lui    v1, $800a
800D202C	lbu    v1, $d820(v1)
800D2030	nop
800D2034	andi   v1, v1, $0003
800D2038	beq    v1, zero, Ld2054 [$800d2054]
800D203C	or     s0, s0, v0
800D2040	lui    a0, $800a
800D2044	addiu  a0, a0, $0e60
800D2048	andi   a1, s0, $ffff
800D204C	jal    funcbeca4 [$800beca4]
800D2050	ori    a2, zero, $0004

Ld2054:	; 800D2054
800D2054	jal    func25288 [$80025288]
800D2058	andi   a0, s0, $ffff
800D205C	lui    v1, $8007
800D2060	lbu    v1, $22c4(v1)
800D2064	lui    v0, $8008
800D2068	addiu  v0, v0, $31fc
800D206C	sll    v1, v1, $01
800D2070	addu   v1, v1, v0
800D2074	lhu    a0, $0000(v1)
800D2078	addu   v0, zero, zero
800D207C	addiu  a0, a0, $0005
800D2080	sh     a0, $0000(v1)
800D2084	lw     ra, $0014(sp)
800D2088	lw     s0, $0010(sp)
800D208C	addiu  sp, sp, $0018
800D2090	jr     ra 
800D2094	nop

800D2098	lui    v0, $800a
800D209C	lbu    v0, $d820(v0)
800D20A0	addiu  sp, sp, $ffe8 (=-$18)
800D20A4	sw     ra, $0014(sp)
800D20A8	andi   v0, v0, $0003
800D20AC	beq    v0, zero, Ld20c4 [$800d20c4]
800D20B0	sw     s0, $0010(sp)
800D20B4	lui    a0, $800a
800D20B8	addiu  a0, a0, $0e68
800D20BC	jal    funcbead4 [$800bead4]
800D20C0	ori    a1, zero, $0004

Ld20c4:	; 800D20C4
800D20C4	ori    a0, zero, $0001
800D20C8	jal    read_memory_block_two_bytes [$800bf908]
800D20CC	ori    a1, zero, $0002
800D20D0	jal    func25310 [$80025310]
800D20D4	andi   a0, v0, $ffff
800D20D8	lui    v1, $800a
800D20DC	lbu    v1, $d820(v1)
800D20E0	nop
800D20E4	andi   v1, v1, $0003
800D20E8	beq    v1, zero, Ld2104 [$800d2104]
800D20EC	addu   s0, v0, zero
800D20F0	lui    a0, $800a
800D20F4	addiu  a0, a0, $0e70
800D20F8	andi   a1, s0, $ffff
800D20FC	jal    funcbeca4 [$800beca4]
800D2100	ori    a2, zero, $0004

Ld2104:	; 800D2104
800D2104	andi   v1, s0, $ffff
800D2108	ori    v0, zero, $ffff
800D210C	bne    v1, v0, Ld2118 [$800d2118]
800D2110	ori    a0, zero, $0002
800D2114	addu   s0, zero, zero

Ld2118:	; 800D2118
800D2118	ori    a1, zero, $0004
800D211C	andi   a2, s0, $ffff
800D2120	jal    store_memory_block_one_byte [$800bf3ac]
800D2124	srl    a2, a2, $09
800D2128	lui    a0, $8007
800D212C	lbu    a0, $22c4(a0)
800D2130	lui    v0, $8008
800D2134	addiu  v0, v0, $31fc
800D2138	sll    a0, a0, $01
800D213C	addu   a0, a0, v0
800D2140	lhu    v1, $0000(a0)
800D2144	addu   v0, zero, zero
800D2148	addiu  v1, v1, $0005
800D214C	sh     v1, $0000(a0)
800D2150	lw     ra, $0014(sp)
800D2154	lw     s0, $0010(sp)
800D2158	addiu  sp, sp, $0018
800D215C	jr     ra 
800D2160	nop

800D2164	lui    v0, $800a
800D2168	lbu    v0, $d820(v0)
800D216C	addiu  sp, sp, $ffd0 (=-$30)
800D2170	sw     ra, $002c(sp)
800D2174	andi   v0, v0, $0003
800D2178	beq    v0, zero, Ld2190 [$800d2190]
800D217C	sw     s0, $0028(sp)
800D2180	lui    a0, $800a
800D2184	addiu  a0, a0, $0e78
800D2188	jal    funcbead4 [$800bead4]
800D218C	ori    a1, zero, $0008

Ld2190:	; 800D2190
800D2190	lui    v0, $8007
800D2194	lbu    v0, $22c4(v0)
800D2198	nop
800D219C	sll    v0, v0, $01
800D21A0	lui    at, $8008
800D21A4	addiu  at, at, $31fc
800D21A8	addu   at, at, v0
800D21AC	lhu    v1, $0000(at)
800D21B0	lui    v0, $800a
800D21B4	lw     v0, $c6dc(v0)
800D21B8	nop
800D21BC	addu   v0, v0, v1
800D21C0	lbu    v0, $0001(v0)
800D21C4	lui    s0, $8008
800D21C8	addiu  s0, s0, $31fc
800D21CC	addiu  v1, v0, $ff0b (=-$f5)
800D21D0	sltiu  v0, v1, $000b
800D21D4	beq    v0, zero, Ld2734 [$800d2734]
800D21D8	sll    v0, v1, $02
800D21DC	lui    at, $800a
800D21E0	addiu  at, at, $0ee4
800D21E4	addu   at, at, v0
800D21E8	lw     v0, $0000(at)
800D21EC	nop
800D21F0	jr     v0 
800D21F4	nop

800D21F8	lui    v0, $800a
800D21FC	lbu    v0, $d820(v0)
800D2200	nop
800D2204	andi   v0, v0, $0003
800D2208	beq    v0, zero, Ld2220 [$800d2220]
800D220C	addu   s0, zero, zero
800D2210	lui    a0, $800a
800D2214	addiu  a0, a0, $0e80
800D2218	jal    funcbead4 [$800bead4]
800D221C	ori    a1, zero, $0008

Ld2220:	; 800D2220
800D2220	ori    a0, s0, $c600

loopd2224:	; 800D2224
800D2224	jal    func25288 [$80025288]
800D2228	andi   a0, a0, $ffff
800D222C	addiu  s0, s0, $0001
800D2230	slti   v0, s0, $0200
800D2234	bne    v0, zero, loopd2224 [$800d2224]
800D2238	ori    a0, s0, $c600
800D223C	j      Ld2480 [$800d2480]
800D2240	nop
800D2244	lui    v0, $800a
800D2248	lbu    v0, $d820(v0)
800D224C	nop
800D2250	andi   v0, v0, $0003
800D2254	beq    v0, zero, Ld226c [$800d226c]
800D2258	nop
800D225C	lui    a0, $800a
800D2260	addiu  a0, a0, $0e88
800D2264	jal    funcbead4 [$800bead4]
800D2268	ori    a1, zero, $0008

Ld226c:	; 800D226C
800D226C	jal    func33a90 [$80033a90]
800D2270	nop
800D2274	j      Ld2480 [$800d2480]
800D2278	nop
800D227C	lui    v0, $800a
800D2280	lbu    v0, $d820(v0)
800D2284	nop
800D2288	andi   v0, v0, $0003
800D228C	beq    v0, zero, Ld22a4 [$800d22a4]
800D2290	nop
800D2294	lui    a0, $800a
800D2298	addiu  a0, a0, $0e90
800D229C	jal    funcbead4 [$800bead4]
800D22A0	ori    a1, zero, $0008

Ld22a4:	; 800D22A4
800D22A4	lui    v0, $8007
800D22A8	lbu    v0, $22c4(v0)
800D22AC	nop
800D22B0	sll    v0, v0, $01
800D22B4	lui    at, $8008
800D22B8	addiu  at, at, $31fc
800D22BC	addu   at, at, v0
800D22C0	lhu    v1, $0000(at)
800D22C4	lui    v0, $800a
800D22C8	lw     v0, $c6dc(v0)
800D22CC	nop
800D22D0	addu   v0, v0, v1
800D22D4	lbu    a0, $0002(v0)
800D22D8	lbu    a1, $0003(v0)
800D22DC	jal    funcd7c98 [$800d7c98]
800D22E0	nop
800D22E4	lui    a0, $8007
800D22E8	lbu    a0, $22c4(a0)
800D22EC	lui    v0, $8008
800D22F0	addiu  v0, v0, $31fc
800D22F4	sll    a0, a0, $01
800D22F8	addu   a0, a0, v0
800D22FC	lhu    v1, $0000(a0)
800D2300	addu   v0, zero, zero
800D2304	j      Ld277c [$800d277c]
800D2308	addiu  v1, v1, $0004
800D230C	lui    v0, $800a
800D2310	lbu    v0, $d820(v0)
800D2314	nop
800D2318	andi   v0, v0, $0003
800D231C	beq    v0, zero, Ld2334 [$800d2334]
800D2320	nop
800D2324	lui    a0, $800a
800D2328	addiu  a0, a0, $0e98
800D232C	jal    funcbead4 [$800bead4]
800D2330	ori    a1, zero, $0002

Ld2334:	; 800D2334
800D2334	lui    v0, $8008
800D2338	addiu  v0, v0, $31fc
800D233C	lui    a0, $8007
800D2340	lbu    a0, $22c4(a0)
800D2344	lui    a1, $800a
800D2348	lw     a1, $c6dc(a1)
800D234C	sll    a0, a0, $01
800D2350	addu   a0, a0, v0
800D2354	lhu    v1, $0000(a0)
800D2358	nop
800D235C	addu   a1, a1, v1
800D2360	lhu    v1, $0000(a0)
800D2364	lbu    a1, $0002(a1)
800D2368	addiu  v1, v1, $0003
800D236C	sh     v1, $0000(a0)
800D2370	lui    at, $8007
800D2374	sb     a1, $16cc(at)
800D2378	j      Ld2780 [$800d2780]
800D237C	addu   v0, zero, zero
800D2380	lui    v0, $800a
800D2384	lbu    v0, $d820(v0)
800D2388	nop
800D238C	andi   v0, v0, $0003
800D2390	beq    v0, zero, Ld23a8 [$800d23a8]
800D2394	nop
800D2398	lui    a0, $800a
800D239C	addiu  a0, a0, $0ea0
800D23A0	jal    funcbead4 [$800bead4]
800D23A4	ori    a1, zero, $0002

Ld23a8:	; 800D23A8
800D23A8	lui    v0, $8008
800D23AC	addiu  v0, v0, $31fc
800D23B0	lui    a0, $8007
800D23B4	lbu    a0, $22c4(a0)
800D23B8	lui    a1, $800a
800D23BC	lw     a1, $c6dc(a1)
800D23C0	sll    a0, a0, $01
800D23C4	addu   a0, a0, v0
800D23C8	lhu    v1, $0000(a0)
800D23CC	nop
800D23D0	addu   a1, a1, v1
800D23D4	lhu    v1, $0000(a0)
800D23D8	lbu    a1, $0002(a1)
800D23DC	addiu  v1, v1, $0003
800D23E0	sh     v1, $0000(a0)
800D23E4	lui    at, $8007
800D23E8	sb     a1, $1e30(at)
800D23EC	j      Ld2780 [$800d2780]
800D23F0	addu   v0, zero, zero
800D23F4	lui    v0, $800a
800D23F8	lbu    v0, $d820(v0)
800D23FC	nop
800D2400	andi   v0, v0, $0003
800D2404	beq    v0, zero, Ld241c [$800d241c]
800D2408	addu   s0, zero, zero
800D240C	lui    a0, $800a
800D2410	addiu  a0, a0, $0ea8
800D2414	jal    funcbead4 [$800bead4]
800D2418	ori    a1, zero, $0008

Ld241c:	; 800D241C
800D241C	ori    a0, s0, $c600

loopd2420:	; 800D2420
800D2420	jal    func25380 [$80025380]
800D2424	andi   a0, a0, $ffff
800D2428	addiu  s0, s0, $0001
800D242C	slti   v0, s0, $0200
800D2430	bne    v0, zero, loopd2420 [$800d2420]
800D2434	ori    a0, s0, $c600
800D2438	j      Ld2480 [$800d2480]
800D243C	nop
800D2440	lui    v0, $800a
800D2444	lbu    v0, $d820(v0)
800D2448	nop
800D244C	andi   v0, v0, $0003
800D2450	beq    v0, zero, Ld2468 [$800d2468]
800D2454	addu   s0, zero, zero
800D2458	lui    a0, $800a
800D245C	addiu  a0, a0, $0eb0
800D2460	jal    funcbead4 [$800bead4]
800D2464	ori    a1, zero, $0008

Ld2468:	; 800D2468
800D2468	jal    func2542c [$8002542c]
800D246C	addu   a0, s0, zero
800D2470	addiu  s0, s0, $0001
800D2474	slti   v0, s0, $0050
800D2478	bne    v0, zero, Ld2468 [$800d2468]
800D247C	nop

Ld2480:	; 800D2480
800D2480	lui    v1, $8007
800D2484	lbu    v1, $22c4(v1)
800D2488	lui    v0, $8008
800D248C	addiu  v0, v0, $31fc
800D2490	sll    v1, v1, $01
800D2494	addu   v1, v1, v0
800D2498	lhu    a0, $0000(v1)
800D249C	addu   v0, zero, zero
800D24A0	addiu  a0, a0, $0002
800D24A4	j      Ld2780 [$800d2780]
800D24A8	sh     a0, $0000(v1)
800D24AC	lui    v0, $800a
800D24B0	lbu    v0, $d820(v0)
800D24B4	nop
800D24B8	andi   v0, v0, $0003
800D24BC	beq    v0, zero, Ld24d8 [$800d24d8]
800D24C0	ori    a0, zero, $0004
800D24C4	lui    a0, $800a
800D24C8	addiu  a0, a0, $0eb8
800D24CC	jal    funcbead4 [$800bead4]
800D24D0	ori    a1, zero, $0003
800D24D4	ori    a0, zero, $0004

Ld24d8:	; 800D24D8
800D24D8	jal    read_memory_block_one_byte [$800bee10]
800D24DC	ori    a1, zero, $0003
800D24E0	lui    a0, $8007
800D24E4	lbu    a0, $22c4(a0)
800D24E8	nor    v0, zero, v0
800D24EC	lui    at, $800a
800D24F0	sb     v0, $d7d0(at)
800D24F4	lui    v0, $8008
800D24F8	addiu  v0, v0, $31fc
800D24FC	sll    a0, a0, $01
800D2500	addu   a0, a0, v0
800D2504	lhu    v1, $0000(a0)
800D2508	addu   v0, zero, zero
800D250C	j      Ld277c [$800d277c]
800D2510	addiu  v1, v1, $0004
800D2514	lui    v0, $800a
800D2518	lbu    v0, $d820(v0)
800D251C	nop
800D2520	andi   v0, v0, $0003
800D2524	beq    v0, zero, Ld2540 [$800d2540]
800D2528	ori    a0, zero, $0004
800D252C	lui    a0, $800a
800D2530	addiu  a0, a0, $0ec0
800D2534	jal    funcbead4 [$800bead4]
800D2538	ori    a1, zero, $0003
800D253C	ori    a0, zero, $0004

Ld2540:	; 800D2540
800D2540	lui    a2, $800a
800D2544	lbu    a2, $d7d0(a2)
800D2548	ori    a1, zero, $0003
800D254C	nor    a2, zero, a2
800D2550	jal    store_memory_block_one_byte [$800bf3ac]
800D2554	andi   a2, a2, $00ff
800D2558	lui    a0, $8007
800D255C	lbu    a0, $22c4(a0)
800D2560	lui    v0, $8008
800D2564	addiu  v0, v0, $31fc
800D2568	sll    a0, a0, $01
800D256C	addu   a0, a0, v0
800D2570	lhu    v1, $0000(a0)
800D2574	addu   v0, zero, zero
800D2578	j      Ld277c [$800d277c]
800D257C	addiu  v1, v1, $0004
800D2580	lui    v0, $800a
800D2584	lbu    v0, $d820(v0)
800D2588	nop
800D258C	andi   v0, v0, $0003
800D2590	beq    v0, zero, Ld25a8 [$800d25a8]
800D2594	nop
800D2598	lui    a0, $800a
800D259C	addiu  a0, a0, $0ec8
800D25A0	jal    funcbead4 [$800bead4]
800D25A4	ori    a1, zero, $0008

Ld25a8:	; 800D25A8
800D25A8	ori    a0, zero, $0003
800D25AC	jal    read_memory_block_one_byte [$800bee10]
800D25B0	ori    a1, zero, $0003
800D25B4	jal    system_get_character_name_offset [$800257cc]
800D25B8	andi   a0, v0, $00ff
800D25BC	lui    v1, $8007
800D25C0	lbu    v1, $22c4(v1)
800D25C4	addu   a2, v0, zero
800D25C8	sll    v1, v1, $01
800D25CC	lui    at, $8008
800D25D0	addiu  at, at, $31fc
800D25D4	addu   at, at, v1
800D25D8	lhu    a0, $0000(at)
800D25DC	lui    v1, $800a
800D25E0	lw     v1, $c6dc(v1)
800D25E4	nop
800D25E8	addu   v1, v1, a0
800D25EC	lbu    v0, $0002(v1)
800D25F0	lbu    v1, $0005(v1)
800D25F4	andi   a0, v0, $000f
800D25F8	ori    v0, zero, $000b
800D25FC	beq    a0, v0, Ld263c [$800d263c]
800D2600	addu   a1, zero, zero
800D2604	slti   v0, a0, $000c
800D2608	beq    v0, zero, Ld2620 [$800d2620]
800D260C	ori    v0, zero, $0003
800D2610	beq    a0, v0, Ld2640 [$800d2640]
800D2614	andi   a0, v1, $ffff
800D2618	j      Ld2648 [$800d2648]
800D261C	nop

Ld2620:	; 800D2620
800D2620	ori    v0, zero, $000d
800D2624	beq    a0, v0, Ld2638 [$800d2638]
800D2628	ori    v0, zero, $000f
800D262C	bne    a0, v0, Ld2648 [$800d2648]
800D2630	andi   a0, v1, $ffff
800D2634	ori    a1, zero, $0100

Ld2638:	; 800D2638
800D2638	addiu  a1, a1, $0100

Ld263c:	; 800D263C
800D263C	addiu  a1, a1, $0100

Ld2640:	; 800D2640
800D2640	addiu  a1, a1, $0100
800D2644	andi   a0, v1, $ffff

Ld2648:	; 800D2648
800D2648	blez   a0, Ld267c [$800d267c]
800D264C	addu   s0, zero, zero
800D2650	andi   a3, a1, $ffff
800D2654	lui    t0, $800a
800D2658	addiu  t0, t0, $d288 (=-$2d78)

loopd265c:	; 800D265C
800D265C	lbu    v0, $0000(a2)
800D2660	addu   v1, a3, s0
800D2664	addiu  s0, s0, $0001
800D2668	addu   v1, v1, t0
800D266C	sb     v0, $0000(v1)
800D2670	slt    v0, s0, a0
800D2674	bne    v0, zero, loopd265c [$800d265c]
800D2678	addiu  a2, a2, $0001

Ld267c:	; 800D267C
800D267C	andi   v0, a1, $ffff
800D2680	addu   v0, v0, s0
800D2684	ori    v1, zero, $00ff
800D2688	lui    at, $800a
800D268C	addiu  at, at, $d288 (=-$2d78)
800D2690	addu   at, at, v0
800D2694	sb     v1, $0000(at)
800D2698	lui    a0, $8007
800D269C	lbu    a0, $22c4(a0)
800D26A0	lui    v0, $8008
800D26A4	addiu  v0, v0, $31fc
800D26A8	sll    a0, a0, $01
800D26AC	addu   a0, a0, v0
800D26B0	lhu    v1, $0000(a0)
800D26B4	addu   v0, zero, zero
800D26B8	j      Ld277c [$800d277c]
800D26BC	addiu  v1, v1, $0006
800D26C0	lui    v0, $800a
800D26C4	lbu    v0, $d820(v0)
800D26C8	nop
800D26CC	andi   v0, v0, $0003
800D26D0	beq    v0, zero, Ld26e8 [$800d26e8]
800D26D4	nop
800D26D8	lui    a0, $800a
800D26DC	addiu  a0, a0, $0ed0
800D26E0	jal    funcbead4 [$800bead4]
800D26E4	ori    a1, zero, $0008

Ld26e8:	; 800D26E8
800D26E8	lui    v0, $8008
800D26EC	addiu  v0, v0, $31fc
800D26F0	lui    a0, $8007
800D26F4	lbu    a0, $22c4(a0)
800D26F8	lui    a1, $800a
800D26FC	lw     a1, $c6dc(a1)
800D2700	sll    a0, a0, $01
800D2704	addu   a0, a0, v0
800D2708	lhu    v1, $0000(a0)
800D270C	nop
800D2710	addu   a1, a1, v1
800D2714	lhu    v1, $0000(a0)
800D2718	lbu    a1, $0002(a1)
800D271C	addiu  v1, v1, $0003
800D2720	sh     v1, $0000(a0)
800D2724	lui    at, $8007
800D2728	sb     a1, $1c1c(at)
800D272C	j      Ld2780 [$800d2780]
800D2730	addu   v0, zero, zero

Ld2734:	; 800D2734
800D2734	lui    v0, $800a
800D2738	lbu    v0, $d820(v0)
800D273C	nop
800D2740	andi   v0, v0, $0003
800D2744	beq    v0, zero, Ld275c [$800d275c]
800D2748	nop
800D274C	lui    a0, $800a
800D2750	addiu  a0, a0, $0ed8
800D2754	jal    funcbead4 [$800bead4]
800D2758	ori    a1, zero, $0008

Ld275c:	; 800D275C
800D275C	lui    a0, $8007
800D2760	lbu    a0, $22c4(a0)
800D2764	nop
800D2768	sll    a0, a0, $01
800D276C	addu   a0, a0, s0
800D2770	lhu    v1, $0000(a0)
800D2774	addu   v0, zero, zero
800D2778	addiu  v1, v1, $0002

Ld277c:	; 800D277C
800D277C	sh     v1, $0000(a0)

Ld2780:	; 800D2780
800D2780	lw     ra, $002c(sp)
800D2784	lw     s0, $0028(sp)
800D2788	addiu  sp, sp, $0030
800D278C	jr     ra 
800D2790	nop



////////////////////////////////
// 0x2D BGSCR
800D2794-800D28A4
////////////////////////////////



////////////////////////////////
// 0x2C BGPDH
800D28A8-800D2988
////////////////////////////////



800D298C	lui    v0, $800a
800D2990	lbu    v0, $d820(v0)
800D2994	addiu  sp, sp, $ffe8 (=-$18)
800D2998	sw     ra, $0014(sp)
800D299C	andi   v0, v0, $0003
800D29A0	beq    v0, zero, Ld29b8 [$800d29b8]
800D29A4	sw     s0, $0010(sp)
800D29A8	lui    a0, $800a
800D29AC	addiu  a0, a0, $0f20
800D29B0	jal    funcbead4 [$800bead4]
800D29B4	ori    a1, zero, $0006

Ld29b8:	; 800D29B8
800D29B8	ori    a0, zero, $0001
800D29BC	jal    read_memory_block_one_byte [$800bee10]
800D29C0	ori    a1, zero, $0003
800D29C4	andi   s0, v0, $00ff
800D29C8	ori    a0, zero, $0002
800D29CC	jal    read_memory_block_one_byte [$800bee10]
800D29D0	ori    a1, zero, $0004
800D29D4	andi   v0, v0, $00ff
800D29D8	sll    v0, v0, $08
800D29DC	or     s0, s0, v0
800D29E0	ori    a0, zero, $0003
800D29E4	jal    read_memory_block_one_byte [$800bee10]
800D29E8	ori    a1, zero, $0005
800D29EC	andi   v0, v0, $00ff
800D29F0	sll    v0, v0, $10
800D29F4	or     s0, s0, v0
800D29F8	ori    a0, zero, $0004
800D29FC	jal    read_memory_block_one_byte [$800bee10]
800D2A00	ori    a1, zero, $0006
800D2A04	sll    v0, v0, $18
800D2A08	jal    func2542c [$8002542c]
800D2A0C	or     a0, s0, v0
800D2A10	addiu  v1, zero, $ffff (=-$1)
800D2A14	bne    v0, v1, Ld2a2c [$800d2a2c]
800D2A18	ori    v0, zero, $0001
800D2A1C	lui    at, $800a
800D2A20	sb     zero, $d5a7(at)
800D2A24	j      Ld2a34 [$800d2a34]
800D2A28	nop

Ld2a2c:	; 800D2A2C
800D2A2C	lui    at, $800a
800D2A30	sb     v0, $d5a7(at)

Ld2a34:	; 800D2A34
800D2A34	lui    v1, $8007
800D2A38	lbu    v1, $22c4(v1)
800D2A3C	lui    v0, $8008
800D2A40	addiu  v0, v0, $31fc
800D2A44	sll    v1, v1, $01
800D2A48	addu   v1, v1, v0
800D2A4C	lhu    a0, $0000(v1)
800D2A50	addu   v0, zero, zero
800D2A54	addiu  a0, a0, $0007
800D2A58	sh     a0, $0000(v1)
800D2A5C	lw     ra, $0014(sp)
800D2A60	lw     s0, $0010(sp)
800D2A64	addiu  sp, sp, $0018
800D2A68	jr     ra 
800D2A6C	nop

800D2A70	lui    v0, $800a
800D2A74	lbu    v0, $d820(v0)
800D2A78	addiu  sp, sp, $ffe0 (=-$20)
800D2A7C	sw     ra, $001c(sp)
800D2A80	andi   v0, v0, $0003
800D2A84	beq    v0, zero, Ld2a9c [$800d2a9c]
800D2A88	sw     s0, $0018(sp)
800D2A8C	lui    a0, $800a
800D2A90	addiu  a0, a0, $0f28
800D2A94	jal    funcbead4 [$800bead4]
800D2A98	ori    a1, zero, $0007

Ld2a9c:	; 800D2A9C
800D2A9C	ori    a0, zero, $0001
800D2AA0	jal    read_memory_block_one_byte [$800bee10]
800D2AA4	ori    a1, zero, $0003
800D2AA8	andi   s0, v0, $00ff
800D2AAC	ori    a0, zero, $0002
800D2AB0	jal    read_memory_block_one_byte [$800bee10]
800D2AB4	ori    a1, zero, $0004
800D2AB8	andi   v0, v0, $00ff
800D2ABC	sll    v0, v0, $08
800D2AC0	or     s0, s0, v0
800D2AC4	ori    a0, zero, $0003
800D2AC8	jal    read_memory_block_one_byte [$800bee10]
800D2ACC	ori    a1, zero, $0005
800D2AD0	andi   v0, v0, $00ff
800D2AD4	sll    v0, v0, $10
800D2AD8	or     s0, s0, v0
800D2ADC	ori    a0, zero, $0004
800D2AE0	jal    read_memory_block_one_byte [$800bee10]
800D2AE4	ori    a1, zero, $0006
800D2AE8	lui    v1, $8007
800D2AEC	lbu    v1, $22c4(v1)
800D2AF0	nop
800D2AF4	sll    v1, v1, $01
800D2AF8	lui    at, $8008
800D2AFC	addiu  at, at, $31fc
800D2B00	addu   at, at, v1
800D2B04	lhu    a0, $0000(at)
800D2B08	lui    v1, $800a
800D2B0C	lw     v1, $c6dc(v1)
800D2B10	sll    v0, v0, $18
800D2B14	addu   v1, v1, a0
800D2B18	lbu    a1, $0007(v1)
800D2B1C	jal    func25648 [$80025648]
800D2B20	or     a0, s0, v0
800D2B24	lui    a0, $8007
800D2B28	lbu    a0, $22c4(a0)
800D2B2C	lui    v0, $8008
800D2B30	addiu  v0, v0, $31fc
800D2B34	sll    a0, a0, $01
800D2B38	addu   a0, a0, v0
800D2B3C	lhu    v1, $0000(a0)
800D2B40	addu   v0, zero, zero
800D2B44	addiu  v1, v1, $0008
800D2B48	sh     v1, $0000(a0)
800D2B4C	lw     ra, $001c(sp)
800D2B50	lw     s0, $0018(sp)
800D2B54	addiu  sp, sp, $0020
800D2B58	jr     ra 
800D2B5C	nop

800D2B60	lui    v0, $800a
800D2B64	lbu    v0, $d820(v0)
800D2B68	addiu  sp, sp, $ffe0 (=-$20)
800D2B6C	sw     ra, $001c(sp)
800D2B70	andi   v0, v0, $0003
800D2B74	beq    v0, zero, Ld2b8c [$800d2b8c]
800D2B78	sw     s0, $0018(sp)
800D2B7C	lui    a0, $800a
800D2B80	addiu  a0, a0, $0f30
800D2B84	jal    funcbead4 [$800bead4]
800D2B88	ori    a1, zero, $0008

Ld2b8c:	; 800D2B8C
800D2B8C	ori    a0, zero, $0001
800D2B90	jal    read_memory_block_one_byte [$800bee10]
800D2B94	ori    a1, zero, $0004
800D2B98	andi   s0, v0, $00ff
800D2B9C	ori    a0, zero, $0002
800D2BA0	jal    read_memory_block_one_byte [$800bee10]
800D2BA4	ori    a1, zero, $0005
800D2BA8	andi   v0, v0, $00ff
800D2BAC	sll    v0, v0, $08
800D2BB0	or     s0, s0, v0
800D2BB4	ori    a0, zero, $0003
800D2BB8	jal    read_memory_block_one_byte [$800bee10]
800D2BBC	ori    a1, zero, $0006
800D2BC0	andi   v0, v0, $00ff
800D2BC4	sll    v0, v0, $10
800D2BC8	or     s0, s0, v0
800D2BCC	ori    a0, zero, $0004
800D2BD0	jal    read_memory_block_one_byte [$800bee10]
800D2BD4	ori    a1, zero, $0007
800D2BD8	lui    v1, $8007
800D2BDC	lbu    v1, $22c4(v1)
800D2BE0	nop
800D2BE4	sll    v1, v1, $01
800D2BE8	lui    at, $8008
800D2BEC	addiu  at, at, $31fc
800D2BF0	addu   at, at, v1
800D2BF4	lhu    a0, $0000(at)
800D2BF8	lui    v1, $800a
800D2BFC	lw     v1, $c6dc(v1)
800D2C00	sll    v0, v0, $18
800D2C04	addu   v1, v1, a0
800D2C08	lbu    a1, $0008(v1)
800D2C0C	jal    func25650 [$80025650]
800D2C10	or     a0, s0, v0
800D2C14	ori    a0, zero, $0006
800D2C18	ori    a1, zero, $0009
800D2C1C	jal    store_memory_block_one_byte [$800bf3ac]
800D2C20	andi   a2, v0, $00ff
800D2C24	lui    a0, $8007
800D2C28	lbu    a0, $22c4(a0)
800D2C2C	lui    v0, $8008
800D2C30	addiu  v0, v0, $31fc
800D2C34	sll    a0, a0, $01
800D2C38	addu   a0, a0, v0
800D2C3C	lhu    v1, $0000(a0)
800D2C40	addu   v0, zero, zero
800D2C44	addiu  v1, v1, $000a
800D2C48	sh     v1, $0000(a0)
800D2C4C	lw     ra, $001c(sp)
800D2C50	lw     s0, $0018(sp)
800D2C54	addiu  sp, sp, $0020
800D2C58	jr     ra 
800D2C5C	nop



////////////////////////////////
// 0x49 MENU
800D2C60-800D2E90
////////////////////////////////



////////////////////////////////
// 0x4A MENU2
800D2E94-800D2F38
////////////////////////////////



800D2F3C	lui    v0, $800a
800D2F40	lbu    v0, $d820(v0)
800D2F44	addiu  sp, sp, $ffe0 (=-$20)
800D2F48	sw     ra, $001c(sp)
800D2F4C	andi   v0, v0, $0003
800D2F50	beq    v0, zero, Ld2f68 [$800d2f68]
800D2F54	sw     s0, $0018(sp)
800D2F58	lui    a0, $800a
800D2F5C	addiu  a0, a0, $0f40
800D2F60	jal    funcbead4 [$800bead4]
800D2F64	ori    a1, zero, $0003

Ld2f68:	; 800D2F68
800D2F68	lui    v0, $8007
800D2F6C	lbu    v0, $22c4(v0)
800D2F70	nop
800D2F74	sll    v0, v0, $01
800D2F78	lui    at, $8008
800D2F7C	addiu  at, at, $31fc
800D2F80	addu   at, at, v0
800D2F84	lhu    v1, $0000(at)
800D2F88	lui    v0, $800a
800D2F8C	lw     v0, $c6dc(v0)
800D2F90	nop
800D2F94	addu   v0, v0, v1
800D2F98	lbu    v1, $0002(v0)
800D2F9C	lui    s0, $8008
800D2FA0	addiu  s0, s0, $31fc
800D2FA4	slti   v0, v1, $0003
800D2FA8	beq    v0, zero, Ld2fc8 [$800d2fc8]
800D2FAC	ori    a0, zero, $0002
800D2FB0	lui    at, $800a
800D2FB4	addiu  at, at, $cbdc (=-$3424)
800D2FB8	addu   at, at, v1
800D2FBC	lbu    a2, $0000(at)
800D2FC0	jal    store_memory_block_one_byte [$800bf3ac]
800D2FC4	ori    a1, zero, $0003

Ld2fc8:	; 800D2FC8
800D2FC8	lui    v1, $8007
800D2FCC	lbu    v1, $22c4(v1)
800D2FD0	nop
800D2FD4	sll    v1, v1, $01
800D2FD8	addu   v1, v1, s0
800D2FDC	lhu    v0, $0000(v1)
800D2FE0	nop
800D2FE4	addiu  v0, v0, $0004
800D2FE8	sh     v0, $0000(v1)
800D2FEC	addu   v0, zero, zero
800D2FF0	lw     ra, $001c(sp)
800D2FF4	lw     s0, $0018(sp)
800D2FF8	addiu  sp, sp, $0020
800D2FFC	jr     ra 
800D3000	nop



////////////////////////////////////////////////////////
// 0x41 MPARA
800D3004-800D3120
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x42 MPRA2
800D3124-800D3260
////////////////////////////////////////////////////////




////////////////////////////////////////////////////////
// 0xD4 SIN
800D3264-800D332C
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0xD5 COS
800D3330-800D33F8
////////////////////////////////////////////////////////



funcd33fc:	; 800D33FC
800D33FC	addiu  sp, sp, $ffe0 (=-$20)
800D3400	sw     s1, $0014(sp)
800D3404	addu   s1, zero, zero
800D3408	sw     s2, $0018(sp)
800D340C	ori    s2, zero, $00ff
800D3410	sw     ra, $001c(sp)
800D3414	sw     s0, $0010(sp)
800D3418	sll    v0, s1, $10

loopd341c:	; 800D341C
800D341C	sra    s0, v0, $10
800D3420	lui    at, $800a
800D3424	addiu  at, at, $cbdc (=-$3424)
800D3428	addu   at, at, s0
800D342C	lbu    v0, $0000(at)
800D3430	nop
800D3434	beq    v0, s2, Ld3450 [$800d3450]
800D3438	addiu  v0, s1, $0001
800D343C	jal    func20058 [$80020058]
800D3440	addu   a0, s0, zero
800D3444	jal    func1786c [$8001786c]
800D3448	addu   a0, s0, zero
800D344C	addiu  v0, s1, $0001

Ld3450:	; 800D3450
800D3450	addu   s1, v0, zero
800D3454	sll    v0, v0, $10
800D3458	sra    v0, v0, $10
800D345C	slti   v0, v0, $0003
800D3460	bne    v0, zero, loopd341c [$800d341c]
800D3464	sll    v0, s1, $10
800D3468	jal    func17678 [$80017678]
800D346C	nop
800D3470	lw     ra, $001c(sp)
800D3474	lw     s2, $0018(sp)
800D3478	lw     s1, $0014(sp)
800D347C	lw     s0, $0010(sp)
800D3480	addiu  sp, sp, $0020
800D3484	jr     ra 
800D3488	nop


funcd348c:	; 800D348C
800D348C	addiu  sp, sp, $ffe0 (=-$20)
800D3490	sw     ra, $001c(sp)
800D3494	sw     s2, $0018(sp)
800D3498	sw     s1, $0014(sp)
800D349C	jal    funcd33fc [$800d33fc]
800D34A0	sw     s0, $0010(sp)
800D34A4	addu   s0, zero, zero
800D34A8	ori    s2, zero, $00ff
800D34AC	lui    s1, $8005
800D34B0	addiu  s1, s1, $91d0 (=-$6e30)
800D34B4	addu   a0, s0, zero

loopd34b8:	; 800D34B8
800D34B8	jal    func258bc [$800258bc]
800D34BC	ori    a1, zero, $2710
800D34C0	addu   a0, s0, zero
800D34C4	jal    func25a44 [$80025a44]
800D34C8	ori    a1, zero, $2710
800D34CC	lui    at, $800a
800D34D0	addiu  at, at, $cbdc (=-$3424)
800D34D4	addu   at, at, s0
800D34D8	lbu    v0, $0000(at)
800D34DC	nop
800D34E0	beq    v0, s2, Ld3520 [$800d3520]
800D34E4	addiu  s0, s0, $0001
800D34E8	sll    v0, v0, $02
800D34EC	addu   v0, v0, s1
800D34F0	lw     v1, $0000(v0)
800D34F4	nop
800D34F8	slti   v0, v1, $0009
800D34FC	beq    v0, zero, Ld3524 [$800d3524]
800D3500	slti   v0, s0, $0003
800D3504	sll    v0, v1, $05
800D3508	addu   v0, v0, v1
800D350C	sll    v0, v0, $02
800D3510	lui    at, $800a
800D3514	addiu  at, at, $c757 (=-$38a9)
800D3518	addu   at, at, v0
800D351C	sb     zero, $0000(at)

Ld3520:	; 800D3520
800D3520	slti   v0, s0, $0003

Ld3524:	; 800D3524
800D3524	bne    v0, zero, loopd34b8 [$800d34b8]
800D3528	addu   a0, s0, zero
800D352C	lw     ra, $001c(sp)
800D3530	lw     s2, $0018(sp)
800D3534	lw     s1, $0014(sp)
800D3538	lw     s0, $0010(sp)
800D353C	addiu  sp, sp, $0020
800D3540	jr     ra 
800D3544	nop

800D3548	lui    v0, $800a
800D354C	lbu    v0, $d820(v0)
800D3550	addiu  sp, sp, $ffe0 (=-$20)
800D3554	andi   v0, v0, $0003
800D3558	beq    v0, zero, Ld3570 [$800d3570]
800D355C	sw     ra, $0018(sp)
800D3560	lui    a0, $800a
800D3564	addiu  a0, a0, $0f60
800D3568	jal    funcbead4 [$800bead4]
800D356C	addu   a1, zero, zero

Ld3570:	; 800D3570
800D3570	addu   v1, zero, zero
800D3574	addiu  a0, sp, $0010

loopd3578:	; 800D3578
800D3578	lui    at, $800a
800D357C	addiu  at, at, $cbdc (=-$3424)
800D3580	addu   at, at, v1
800D3584	lbu    v0, $0000(at)
800D3588	addiu  v1, v1, $0001
800D358C	sb     v0, $0000(a0)
800D3590	slti   v0, v1, $0003
800D3594	bne    v0, zero, loopd3578 [$800d3578]
800D3598	addiu  a0, a0, $0001
800D359C	ori    v1, zero, $0002
800D35A0	lui    v0, $800a
800D35A4	addiu  v0, v0, $cbde (=-$3422)

loopd35a8:	; 800D35A8
800D35A8	sb     v1, $0000(v0)
800D35AC	addiu  v1, v1, $ffff (=-$1)
800D35B0	bgez   v1, loopd35a8 [$800d35a8]
800D35B4	addiu  v0, v0, $ffff (=-$1)
800D35B8	jal    funcd348c [$800d348c]
800D35BC	nop
800D35C0	ori    v1, zero, $0002
800D35C4	ori    v0, zero, $0005

loopd35c8:	; 800D35C8
800D35C8	lui    at, $800a
800D35CC	addiu  at, at, $cbd9 (=-$3427)
800D35D0	addu   at, at, v0
800D35D4	sb     v0, $0000(at)
800D35D8	addiu  v1, v1, $ffff (=-$1)
800D35DC	bgez   v1, loopd35c8 [$800d35c8]
800D35E0	addiu  v0, v0, $ffff (=-$1)
800D35E4	jal    funcd348c [$800d348c]
800D35E8	nop
800D35EC	ori    v1, zero, $0002
800D35F0	ori    v0, zero, $0008

loopd35f4:	; 800D35F4
800D35F4	lui    at, $800a
800D35F8	addiu  at, at, $cbd6 (=-$342a)
800D35FC	addu   at, at, v0
800D3600	sb     v0, $0000(at)
800D3604	addiu  v1, v1, $ffff (=-$1)
800D3608	bgez   v1, loopd35f4 [$800d35f4]
800D360C	addiu  v0, v0, $ffff (=-$1)
800D3610	jal    funcd348c [$800d348c]
800D3614	nop
800D3618	addu   v1, zero, zero
800D361C	addiu  a0, sp, $0010

loopd3620:	; 800D3620
800D3620	lbu    v0, $0000(a0)
800D3624	nop
800D3628	lui    at, $800a
800D362C	addiu  at, at, $cbdc (=-$3424)
800D3630	addu   at, at, v1
800D3634	sb     v0, $0000(at)
800D3638	addiu  v1, v1, $0001
800D363C	slti   v0, v1, $0003
800D3640	bne    v0, zero, loopd3620 [$800d3620]
800D3644	addiu  a0, a0, $0001
800D3648	jal    funcd348c [$800d348c]
800D364C	nop
800D3650	lui    v0, $8007
800D3654	lbu    v0, $22c4(v0)
800D3658	lui    v1, $8008
800D365C	addiu  v1, v1, $31fc
800D3660	sll    v0, v0, $01
800D3664	addu   v0, v0, v1
800D3668	lhu    v1, $0000(v0)
800D366C	nop
800D3670	addiu  v1, v1, $0001
800D3674	sh     v1, $0000(v0)
800D3678	addu   v0, zero, zero
800D367C	lw     ra, $0018(sp)
800D3680	addiu  sp, sp, $0020
800D3684	jr     ra 
800D3688	nop

800D368C	lui    v0, $800a
800D3690	lbu    v0, $d820(v0)
800D3694	addiu  sp, sp, $ffe8 (=-$18)
800D3698	sw     ra, $0014(sp)
800D369C	andi   v0, v0, $0003
800D36A0	beq    v0, zero, Ld36b8 [$800d36b8]
800D36A4	sw     s0, $0010(sp)
800D36A8	lui    a0, $800a
800D36AC	addiu  a0, a0, $0f68
800D36B0	jal    funcbead4 [$800bead4]
800D36B4	addu   a1, zero, zero

Ld36b8:	; 800D36B8
800D36B8	jal    funcd33fc [$800d33fc]
800D36BC	addu   s0, zero, zero
800D36C0	addu   a0, s0, zero

loopd36c4:	; 800D36C4
800D36C4	jal    func258bc [$800258bc]
800D36C8	ori    a1, zero, $2710
800D36CC	addu   a0, s0, zero
800D36D0	jal    func25a44 [$80025a44]
800D36D4	ori    a1, zero, $2710
800D36D8	addiu  s0, s0, $0001
800D36DC	slti   v0, s0, $0003
800D36E0	bne    v0, zero, loopd36c4 [$800d36c4]
800D36E4	addu   a0, s0, zero
800D36E8	lui    v0, $8007
800D36EC	lbu    v0, $22c4(v0)
800D36F0	lui    v1, $8008
800D36F4	addiu  v1, v1, $31fc
800D36F8	sll    v0, v0, $01
800D36FC	addu   v0, v0, v1
800D3700	lhu    v1, $0000(v0)
800D3704	nop
800D3708	addiu  v1, v1, $0001
800D370C	sh     v1, $0000(v0)
800D3710	addu   v0, zero, zero
800D3714	lw     ra, $0014(sp)
800D3718	lw     s0, $0010(sp)
800D371C	addiu  sp, sp, $0018
800D3720	jr     ra 
800D3724	nop

800D3728	lui    v0, $800a
800D372C	lbu    v0, $d820(v0)
800D3730	addiu  sp, sp, $ffe0 (=-$20)
800D3734	sw     ra, $0018(sp)
800D3738	sw     s1, $0014(sp)
800D373C	andi   v0, v0, $0003
800D3740	beq    v0, zero, Ld3758 [$800d3758]
800D3744	sw     s0, $0010(sp)
800D3748	lui    a0, $800a
800D374C	addiu  a0, a0, $0f70
800D3750	jal    funcbead4 [$800bead4]
800D3754	ori    a1, zero, $0004

Ld3758:	; 800D3758
800D3758	jal    funcd33fc [$800d33fc]
800D375C	nop
800D3760	lui    v0, $8007
800D3764	lbu    v0, $22c4(v0)
800D3768	nop
800D376C	sll    v0, v0, $01
800D3770	lui    at, $8008
800D3774	addiu  at, at, $31fc
800D3778	addu   at, at, v0
800D377C	lhu    v1, $0000(at)
800D3780	lui    v0, $800a
800D3784	lw     v0, $c6dc(v0)
800D3788	nop
800D378C	addu   v0, v0, v1
800D3790	lbu    s1, $0002(v0)
800D3794	nop
800D3798	lui    at, $800a
800D379C	addiu  at, at, $d391 (=-$2c6f)
800D37A0	addu   at, at, s1
800D37A4	lbu    v1, $0000(at)
800D37A8	ori    v0, zero, $00ff
800D37AC	beq    v1, v0, Ld3800 [$800d3800]
800D37B0	nop
800D37B4	addu   s1, v1, zero
800D37B8	addu   s0, zero, zero

loopd37bc:	; 800D37BC
800D37BC	lui    at, $800a
800D37C0	addiu  at, at, $cbdc (=-$3424)
800D37C4	addu   at, at, s0
800D37C8	lbu    v0, $0000(at)
800D37CC	nop
800D37D0	bne    v0, s1, Ld37f0 [$800d37f0]
800D37D4	ori    a0, zero, $0002
800D37D8	jal    read_memory_block_two_bytes [$800bf908]
800D37DC	ori    a1, zero, $0003
800D37E0	addu   a0, s0, zero
800D37E4	sll    v0, v0, $10
800D37E8	jal    func25a44 [$80025a44]
800D37EC	sra    a1, v0, $10

Ld37f0:	; 800D37F0
800D37F0	addiu  s0, s0, $0001
800D37F4	slti   v0, s0, $0003
800D37F8	bne    v0, zero, loopd37bc [$800d37bc]
800D37FC	nop

Ld3800:	; 800D3800
800D3800	lui    v1, $8007
800D3804	lbu    v1, $22c4(v1)
800D3808	lui    v0, $8008
800D380C	addiu  v0, v0, $31fc
800D3810	sll    v1, v1, $01
800D3814	addu   v1, v1, v0
800D3818	lhu    a0, $0000(v1)
800D381C	addu   v0, zero, zero
800D3820	addiu  a0, a0, $0005
800D3824	sh     a0, $0000(v1)
800D3828	lw     ra, $0018(sp)
800D382C	lw     s1, $0014(sp)
800D3830	lw     s0, $0010(sp)
800D3834	addiu  sp, sp, $0020
800D3838	jr     ra 
800D383C	nop

800D3840	lui    v0, $800a
800D3844	lbu    v0, $d820(v0)
800D3848	addiu  sp, sp, $ffe0 (=-$20)
800D384C	sw     ra, $0018(sp)
800D3850	sw     s1, $0014(sp)
800D3854	andi   v0, v0, $0003
800D3858	beq    v0, zero, Ld3870 [$800d3870]
800D385C	sw     s0, $0010(sp)
800D3860	lui    a0, $800a
800D3864	addiu  a0, a0, $0f74
800D3868	jal    funcbead4 [$800bead4]
800D386C	ori    a1, zero, $0004

Ld3870:	; 800D3870
800D3870	jal    funcd33fc [$800d33fc]
800D3874	nop
800D3878	lui    v0, $8007
800D387C	lbu    v0, $22c4(v0)
800D3880	nop
800D3884	sll    v0, v0, $01
800D3888	lui    at, $8008
800D388C	addiu  at, at, $31fc
800D3890	addu   at, at, v0
800D3894	lhu    v1, $0000(at)
800D3898	lui    v0, $800a
800D389C	lw     v0, $c6dc(v0)
800D38A0	nop
800D38A4	addu   v0, v0, v1
800D38A8	lbu    s1, $0002(v0)
800D38AC	nop
800D38B0	lui    at, $800a
800D38B4	addiu  at, at, $d391 (=-$2c6f)
800D38B8	addu   at, at, s1
800D38BC	lbu    v1, $0000(at)
800D38C0	ori    v0, zero, $00ff
800D38C4	beq    v1, v0, Ld3918 [$800d3918]
800D38C8	nop
800D38CC	addu   s1, v1, zero
800D38D0	addu   s0, zero, zero

loopd38d4:	; 800D38D4
800D38D4	lui    at, $800a
800D38D8	addiu  at, at, $cbdc (=-$3424)
800D38DC	addu   at, at, s0
800D38E0	lbu    v0, $0000(at)
800D38E4	nop
800D38E8	bne    v0, s1, Ld3908 [$800d3908]
800D38EC	ori    a0, zero, $0002
800D38F0	jal    read_memory_block_two_bytes [$800bf908]
800D38F4	ori    a1, zero, $0003
800D38F8	addu   a0, s0, zero
800D38FC	sll    v0, v0, $10
800D3900	jal    func25988 [$80025988]
800D3904	sra    a1, v0, $10

Ld3908:	; 800D3908
800D3908	addiu  s0, s0, $0001
800D390C	slti   v0, s0, $0003
800D3910	bne    v0, zero, loopd38d4 [$800d38d4]
800D3914	nop

Ld3918:	; 800D3918
800D3918	lui    v1, $8007
800D391C	lbu    v1, $22c4(v1)
800D3920	lui    v0, $8008
800D3924	addiu  v0, v0, $31fc
800D3928	sll    v1, v1, $01
800D392C	addu   v1, v1, v0
800D3930	lhu    a0, $0000(v1)
800D3934	addu   v0, zero, zero
800D3938	addiu  a0, a0, $0005
800D393C	sh     a0, $0000(v1)
800D3940	lw     ra, $0018(sp)
800D3944	lw     s1, $0014(sp)
800D3948	lw     s0, $0010(sp)
800D394C	addiu  sp, sp, $0020
800D3950	jr     ra 
800D3954	nop

800D3958	lui    v0, $800a
800D395C	lbu    v0, $d820(v0)
800D3960	addiu  sp, sp, $ffe0 (=-$20)
800D3964	sw     ra, $0018(sp)
800D3968	sw     s1, $0014(sp)
800D396C	andi   v0, v0, $0003
800D3970	beq    v0, zero, Ld3988 [$800d3988]
800D3974	sw     s0, $0010(sp)
800D3978	lui    a0, $800a
800D397C	addiu  a0, a0, $0f78
800D3980	jal    funcbead4 [$800bead4]
800D3984	ori    a1, zero, $0004

Ld3988:	; 800D3988
800D3988	jal    funcd33fc [$800d33fc]
800D398C	nop
800D3990	lui    v0, $8007
800D3994	lbu    v0, $22c4(v0)
800D3998	nop
800D399C	sll    v0, v0, $01
800D39A0	lui    at, $8008
800D39A4	addiu  at, at, $31fc
800D39A8	addu   at, at, v0
800D39AC	lhu    v1, $0000(at)
800D39B0	lui    v0, $800a
800D39B4	lw     v0, $c6dc(v0)
800D39B8	nop
800D39BC	addu   v0, v0, v1
800D39C0	lbu    s1, $0002(v0)
800D39C4	nop
800D39C8	lui    at, $800a
800D39CC	addiu  at, at, $d391 (=-$2c6f)
800D39D0	addu   at, at, s1
800D39D4	lbu    v1, $0000(at)
800D39D8	ori    v0, zero, $00ff
800D39DC	beq    v1, v0, Ld3a30 [$800d3a30]
800D39E0	nop
800D39E4	addu   s1, v1, zero
800D39E8	addu   s0, zero, zero

loopd39ec:	; 800D39EC
800D39EC	lui    at, $800a
800D39F0	addiu  at, at, $cbdc (=-$3424)
800D39F4	addu   at, at, s0
800D39F8	lbu    v0, $0000(at)
800D39FC	nop
800D3A00	bne    v0, s1, Ld3a20 [$800d3a20]
800D3A04	ori    a0, zero, $0002
800D3A08	jal    read_memory_block_two_bytes [$800bf908]
800D3A0C	ori    a1, zero, $0003
800D3A10	addu   a0, s0, zero
800D3A14	sll    v0, v0, $10
800D3A18	jal    func258bc [$800258bc]
800D3A1C	sra    a1, v0, $10

Ld3a20:	; 800D3A20
800D3A20	addiu  s0, s0, $0001
800D3A24	slti   v0, s0, $0003
800D3A28	bne    v0, zero, loopd39ec [$800d39ec]
800D3A2C	nop

Ld3a30:	; 800D3A30
800D3A30	lui    v1, $8007
800D3A34	lbu    v1, $22c4(v1)
800D3A38	lui    v0, $8008
800D3A3C	addiu  v0, v0, $31fc
800D3A40	sll    v1, v1, $01
800D3A44	addu   v1, v1, v0
800D3A48	lhu    a0, $0000(v1)
800D3A4C	addu   v0, zero, zero
800D3A50	addiu  a0, a0, $0005
800D3A54	sh     a0, $0000(v1)
800D3A58	lw     ra, $0018(sp)
800D3A5C	lw     s1, $0014(sp)
800D3A60	lw     s0, $0010(sp)
800D3A64	addiu  sp, sp, $0020
800D3A68	jr     ra 
800D3A6C	nop

800D3A70	lui    v0, $800a
800D3A74	lbu    v0, $d820(v0)
800D3A78	addiu  sp, sp, $ffe0 (=-$20)
800D3A7C	sw     ra, $0018(sp)
800D3A80	sw     s1, $0014(sp)
800D3A84	andi   v0, v0, $0003
800D3A88	beq    v0, zero, Ld3aa0 [$800d3aa0]
800D3A8C	sw     s0, $0010(sp)
800D3A90	lui    a0, $800a
800D3A94	addiu  a0, a0, $0f7c
800D3A98	jal    funcbead4 [$800bead4]
800D3A9C	ori    a1, zero, $0004

Ld3aa0:	; 800D3AA0
800D3AA0	jal    funcd33fc [$800d33fc]
800D3AA4	nop
800D3AA8	lui    v0, $8007
800D3AAC	lbu    v0, $22c4(v0)
800D3AB0	nop
800D3AB4	sll    v0, v0, $01
800D3AB8	lui    at, $8008
800D3ABC	addiu  at, at, $31fc
800D3AC0	addu   at, at, v0
800D3AC4	lhu    v1, $0000(at)
800D3AC8	lui    v0, $800a
800D3ACC	lw     v0, $c6dc(v0)
800D3AD0	nop
800D3AD4	addu   v0, v0, v1
800D3AD8	lbu    s1, $0002(v0)
800D3ADC	nop
800D3AE0	lui    at, $800a
800D3AE4	addiu  at, at, $d391 (=-$2c6f)
800D3AE8	addu   at, at, s1
800D3AEC	lbu    v1, $0000(at)
800D3AF0	ori    v0, zero, $00ff
800D3AF4	beq    v1, v0, Ld3b48 [$800d3b48]
800D3AF8	nop
800D3AFC	addu   s1, v1, zero
800D3B00	addu   s0, zero, zero

loopd3b04:	; 800D3B04
800D3B04	lui    at, $800a
800D3B08	addiu  at, at, $cbdc (=-$3424)
800D3B0C	addu   at, at, s0
800D3B10	lbu    v0, $0000(at)
800D3B14	nop
800D3B18	bne    v0, s1, Ld3b38 [$800d3b38]
800D3B1C	ori    a0, zero, $0002
800D3B20	jal    read_memory_block_two_bytes [$800bf908]
800D3B24	ori    a1, zero, $0003
800D3B28	addu   a0, s0, zero
800D3B2C	sll    v0, v0, $10
800D3B30	jal    func25800 [$80025800]
800D3B34	sra    a1, v0, $10

Ld3b38:	; 800D3B38
800D3B38	addiu  s0, s0, $0001
800D3B3C	slti   v0, s0, $0003
800D3B40	bne    v0, zero, loopd3b04 [$800d3b04]
800D3B44	nop

Ld3b48:	; 800D3B48
800D3B48	lui    v1, $8007
800D3B4C	lbu    v1, $22c4(v1)
800D3B50	lui    v0, $8008
800D3B54	addiu  v0, v0, $31fc
800D3B58	sll    v1, v1, $01
800D3B5C	addu   v1, v1, v0
800D3B60	lhu    a0, $0000(v1)
800D3B64	addu   v0, zero, zero
800D3B68	addiu  a0, a0, $0005
800D3B6C	sh     a0, $0000(v1)
800D3B70	lw     ra, $0018(sp)
800D3B74	lw     s1, $0014(sp)
800D3B78	lw     s0, $0010(sp)
800D3B7C	addiu  sp, sp, $0020
800D3B80	jr     ra 
800D3B84	nop

800D3B88	lui    v0, $800a
800D3B8C	lbu    v0, $d820(v0)
800D3B90	addiu  sp, sp, $ffe8 (=-$18)
800D3B94	sw     ra, $0014(sp)
800D3B98	andi   v0, v0, $0003
800D3B9C	beq    v0, zero, Ld3bb4 [$800d3bb4]
800D3BA0	sw     s0, $0010(sp)
800D3BA4	lui    a0, $800a
800D3BA8	addiu  a0, a0, $0f80
800D3BAC	jal    funcbead4 [$800bead4]
800D3BB0	ori    a1, zero, $0005

Ld3bb4:	; 800D3BB4
800D3BB4	ori    a0, zero, $0001
800D3BB8	jal    read_memory_block_two_bytes [$800bf908]
800D3BBC	ori    a1, zero, $0002
800D3BC0	andi   s0, v0, $ffff
800D3BC4	ori    a0, zero, $0002
800D3BC8	jal    read_memory_block_two_bytes [$800bf908]
800D3BCC	ori    a1, zero, $0004
800D3BD0	sll    v0, v0, $10
800D3BD4	jal    func25b48 [$80025b48]
800D3BD8	or     a0, s0, v0
800D3BDC	lui    a0, $8007
800D3BE0	lbu    a0, $22c4(a0)
800D3BE4	lui    v0, $8008
800D3BE8	addiu  v0, v0, $31fc
800D3BEC	sll    a0, a0, $01
800D3BF0	addu   a0, a0, v0
800D3BF4	lhu    v1, $0000(a0)
800D3BF8	addu   v0, zero, zero
800D3BFC	addiu  v1, v1, $0006
800D3C00	sh     v1, $0000(a0)
800D3C04	lw     ra, $0014(sp)
800D3C08	lw     s0, $0010(sp)
800D3C0C	addiu  sp, sp, $0018
800D3C10	jr     ra 
800D3C14	nop

800D3C18	lui    v0, $800a
800D3C1C	lbu    v0, $d820(v0)
800D3C20	addiu  sp, sp, $ffe8 (=-$18)
800D3C24	sw     ra, $0014(sp)
800D3C28	andi   v0, v0, $0003
800D3C2C	beq    v0, zero, Ld3c44 [$800d3c44]
800D3C30	sw     s0, $0010(sp)
800D3C34	lui    a0, $800a
800D3C38	addiu  a0, a0, $0f88
800D3C3C	jal    funcbead4 [$800bead4]
800D3C40	ori    a1, zero, $0005

Ld3c44:	; 800D3C44
800D3C44	ori    a0, zero, $0001
800D3C48	jal    read_memory_block_two_bytes [$800bf908]
800D3C4C	ori    a1, zero, $0002
800D3C50	andi   s0, v0, $ffff
800D3C54	ori    a0, zero, $0002
800D3C58	jal    read_memory_block_two_bytes [$800bf908]
800D3C5C	ori    a1, zero, $0004
800D3C60	sll    v0, v0, $10
800D3C64	jal    func25b10 [$80025b10]
800D3C68	or     a0, s0, v0
800D3C6C	lui    a0, $8007
800D3C70	lbu    a0, $22c4(a0)
800D3C74	lui    v0, $8008
800D3C78	addiu  v0, v0, $31fc
800D3C7C	sll    a0, a0, $01
800D3C80	addu   a0, a0, v0
800D3C84	lhu    v1, $0000(a0)
800D3C88	addu   v0, zero, zero
800D3C8C	addiu  v1, v1, $0006
800D3C90	sh     v1, $0000(a0)
800D3C94	lw     ra, $0014(sp)
800D3C98	lw     s0, $0010(sp)
800D3C9C	addiu  sp, sp, $0018
800D3CA0	jr     ra 
800D3CA4	nop

800D3CA8	lui    v0, $800a
800D3CAC	lbu    v0, $d820(v0)
800D3CB0	addiu  sp, sp, $ffe8 (=-$18)
800D3CB4	sw     ra, $0014(sp)
800D3CB8	andi   v0, v0, $0003
800D3CBC	beq    v0, zero, Ld3cd4 [$800d3cd4]
800D3CC0	sw     s0, $0010(sp)
800D3CC4	lui    a0, $800a
800D3CC8	addiu  a0, a0, $0f90
800D3CCC	jal    funcbead4 [$800bead4]
800D3CD0	ori    a1, zero, $0003

Ld3cd4:	; 800D3CD4
800D3CD4	jal    func25b7c [$80025b7c]
800D3CD8	nop
800D3CDC	ori    a0, zero, $0001
800D3CE0	ori    a1, zero, $0002
800D3CE4	addu   s0, v0, zero
800D3CE8	sll    a2, s0, $10
800D3CEC	jal    store_memory_block_two_bytes [$800c0248]
800D3CF0	sra    a2, a2, $10
800D3CF4	ori    a0, zero, $0002
800D3CF8	ori    a1, zero, $0003
800D3CFC	jal    store_memory_block_two_bytes [$800c0248]
800D3D00	sra    a2, s0, $10
800D3D04	lui    a0, $8007
800D3D08	lbu    a0, $22c4(a0)
800D3D0C	lui    v0, $8008
800D3D10	addiu  v0, v0, $31fc
800D3D14	sll    a0, a0, $01
800D3D18	addu   a0, a0, v0
800D3D1C	lhu    v1, $0000(a0)
800D3D20	addu   v0, zero, zero
800D3D24	addiu  v1, v1, $0004
800D3D28	sh     v1, $0000(a0)
800D3D2C	lw     ra, $0014(sp)
800D3D30	lw     s0, $0010(sp)
800D3D34	addiu  sp, sp, $0018
800D3D38	jr     ra 
800D3D3C	nop



////////////////////////////////////////////////////
// 0xF7 CHMPH
800D3D40-800D3DC8
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// 0xFE CHMST
800D3DCC-800D3E60
////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x38 STTIM
800D3E64-800D3F2C
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x36 WSPCL
800D3F30-800D4034
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x37 WNUMB
800D4038-800D415C
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x72 BTLMD
800D4160-800D4210
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x22 BTMD2
800D4214-800D42FC
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x23 BTRLD
800D4300-800D4374
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x4B BTLTB
800D4378-800D441C
////////////////////////////////////////////////////////



800D4420	lui    v0, $800a
800D4424	lbu    v0, $d820(v0)
800D4428	addiu  sp, sp, $ffe8 (=-$18)
800D442C	andi   v0, v0, $0003
800D4430	beq    v0, zero, Ld4448 [$800d4448]
800D4434	sw     ra, $0010(sp)
800D4438	lui    a0, $800a
800D443C	addiu  a0, a0, $0fe0
800D4440	jal    funcbead4 [$800bead4]
800D4444	ori    a1, zero, $0008

Ld4448:	; 800D4448
800D4448	lui    v1, $8007
800D444C	lbu    v1, $22c4(v1)
800D4450	nop
800D4454	lui    at, $8008
800D4458	addiu  at, at, $eb98 (=-$1468)
800D445C	addu   at, at, v1
800D4460	lbu    a0, $0000(at)
800D4464	ori    v0, zero, $00ff
800D4468	beq    a0, v0, Ld44ac [$800d44ac]
800D446C	sll    v0, a0, $05
800D4470	addu   v0, v0, a0
800D4474	sll    v1, v1, $01
800D4478	lui    at, $8008
800D447C	addiu  at, at, $31fc
800D4480	addu   at, at, v1
800D4484	lhu    a0, $0000(at)
800D4488	lui    v1, $800a
800D448C	lw     v1, $c6dc(v1)
800D4490	sll    v0, v0, $02
800D4494	addu   v1, v1, a0
800D4498	lui    a0, $800a
800D449C	lw     a0, $c544(a0)
800D44A0	lbu    v1, $0001(v1)
800D44A4	addu   v0, v0, a0
800D44A8	sb     v1, $0008(v0)

Ld44ac:	; 800D44AC
800D44AC	lui    v0, $8007
800D44B0	lbu    v0, $22c4(v0)
800D44B4	lui    v1, $8008
800D44B8	addiu  v1, v1, $31fc
800D44BC	sll    v0, v0, $01
800D44C0	addu   v0, v0, v1
800D44C4	lhu    v1, $0000(v0)
800D44C8	nop
800D44CC	addiu  v1, v1, $0002
800D44D0	sh     v1, $0000(v0)
800D44D4	addu   v0, zero, zero
800D44D8	lw     ra, $0010(sp)
800D44DC	addiu  sp, sp, $0018
800D44E0	jr     ra 
800D44E4	nop



////////////////////////////////////////////////////////
// 0x28 KAWAI
800D44E8-800D477C
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// 0x29 KAWIW
800D4780-800D4834
////////////////////////////////////////////////////////



800D4838	jr     ra 
800D483C	nop


funcd4840:	; 800D4840
800D4840	jr     ra 
800D4844	nop


funcd4848:	; 800D4848
800D4848	addiu  sp, sp, $ffe0 (=-$20)
800D484C	sw     s0, $0018(sp)
800D4850	addu   s0, a0, zero
800D4854	addu   a0, zero, zero
800D4858	ori    a1, zero, $0064
800D485C	ori    a2, zero, $0064
800D4860	ori    a3, zero, $0096
800D4864	ori    v0, zero, $000c
800D4868	sw     ra, $001c(sp)
800D486C	jal    funcd828c [$800d828c]
800D4870	sw     v0, $0010(sp)
800D4874	addu   a0, zero, zero
800D4878	ori    a1, zero, $007f
800D487C	addu   a2, zero, zero
800D4880	jal    funcda214 [$800da214]
800D4884	addu   a3, zero, zero
800D4888	addu   a0, zero, zero
800D488C	jal    funcd9f00 [$800d9f00]
800D4890	addu   a1, s0, zero
800D4894	ori    v0, zero, $0001
800D4898	lui    at, $8009
800D489C	sb     v0, $5dcc(at)
800D48A0	ori    v0, zero, $0004
800D48A4	lui    at, $800a
800D48A8	sb     v0, $9ffc(at)
800D48AC	lw     ra, $001c(sp)
800D48B0	lw     s0, $0018(sp)
800D48B4	addiu  sp, sp, $0020
800D48B8	jr     ra 
800D48BC	nop


funcd48c0:	; 800D48C0
800D48C0	addiu  sp, sp, $ffe8 (=-$18)
800D48C4	sw     s0, $0010(sp)
800D48C8	addu   s0, zero, zero
800D48CC	sw     ra, $0014(sp)
800D48D0	lui    at, $8007
800D48D4	sb     zero, $1e2c(at)

loopd48d8:	; 800D48D8
800D48D8	sll    a0, s0, $10
800D48DC	jal    reset_window [$800d493c]
800D48E0	sra    a0, a0, $10
800D48E4	addiu  s0, s0, $0001
800D48E8	slti   v0, s0, $0004
800D48EC	bne    v0, zero, loopd48d8 [$800d48d8]
800D48F0	nop
800D48F4	lui    v1, $800a
800D48F8	lw     v1, $c6dc(v1)
800D48FC	nop
800D4900	lhu    v0, $0004(v1)
800D4904	nop
800D4908	beq    v0, zero, Ld4920 [$800d4920]
800D490C	addu   v0, v0, v1
800D4910	lui    at, $8008
800D4914	sw     v0, $e7a8(at)
800D4918	j      Ld4928 [$800d4928]
800D491C	nop

Ld4920:	; 800D4920
800D4920	lui    at, $8008
800D4924	sw     zero, $e7a8(at)

Ld4928:	; 800D4928
800D4928	lw     ra, $0014(sp)
800D492C	lw     s0, $0010(sp)
800D4930	addiu  sp, sp, $0018
800D4934	jr     ra 
800D4938	nop



////////////////////////////////////////////////////////
reset_window
800D493C-800D4B24
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
set_state_to_close
800D4B28-800D4BBC
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
set_window_style_cbc
800D4BC0-800D4BF8
////////////////////////////////////////////////////////



funcd4bfc:	; 800D4BFC
800D4BFC	addu   a0, zero, zero
800D4C00	ori    a2, zero, $00ff
800D4C04	lui    a1, $8011
800D4C08	addiu  a1, a1, $445c
800D4C0C	addu   v1, zero, zero

loopd4c10:	; 800D4C10
800D4C10	lui    at, $8008
800D4C14	addiu  at, at, $32a0
800D4C18	addu   at, at, v1
800D4C1C	sh     zero, $0000(at)
800D4C20	lui    at, $8008
800D4C24	addiu  at, at, $3286
800D4C28	addu   at, at, v1
800D4C2C	sh     zero, $0000(at)
800D4C30	lui    at, $8008
800D4C34	addiu  at, at, $326c
800D4C38	addu   at, at, a0
800D4C3C	sb     a2, $0000(at)
800D4C40	sh     zero, $0000(a1)
800D4C44	addiu  a1, a1, $0002
800D4C48	addiu  a0, a0, $0001
800D4C4C	slti   v0, a0, $0004
800D4C50	bne    v0, zero, loopd4c10 [$800d4c10]
800D4C54	addiu  v1, v1, $0030
800D4C58	lui    at, $8007
800D4C5C	sb     zero, $1e2c(at)
800D4C60	jr     ra 
800D4C64	nop



/////////////////////////////////////////////////////////
set_window_x_y_width_height
800D4C68-800D4E20
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
add_x_y_to_window_position
800D4E24-800D4E84
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
set_window_height
800D4E88-800D4EB0
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
manage_window_states
800D4EB4-800D5224
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
manage_ask_window_states
800D5228-800D574C
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
play_window_pointer_click_sound
800D5750-800D5798
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
dialog_window_init
800D579C-800D5A5C
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
dialog_window_growth
800D5A60-800D5C98
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
dialog_copy_text_from_field
800D5C9C-800D6D40
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
dialog_scroll_text
800D6D44-800D6E08
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
dialog_scroll_text_during_ok
800D6E0C-800D6F68
////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
dialog_init_next_window
800D6F6C-800D7078
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
dialog_window_discrease
800D707C-800D7268
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
get_variable_for_window_from_memory_bank
800D726C-800D7758
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
convert_digit_to_string
800D775C-800D7858
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
convert_digit_to_string_with_space
800D785C-800D796C
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
convert_hex_to_string
800D7970-800D7A54
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
copy_dialog_to_map_name
800D7A58-800D7C94
////////////////////////////////////////////////////////



funcd7c98:	; 800D7C98
800D7C98	lui    v0, $8008
800D7C9C	lw     v0, $e7a8(v0)
800D7CA0	addiu  sp, sp, $ffe0 (=-$20)
800D7CA4	sw     ra, $0018(sp)
800D7CA8	sw     s1, $0014(sp)
800D7CAC	bne    v0, zero, Ld7ccc [$800d7ccc]
800D7CB0	sw     s0, $0010(sp)
800D7CB4	lui    a0, $800a
800D7CB8	addiu  a0, a0, $10dc
800D7CBC	jal    funcd4848 [$800d4848]
800D7CC0	nop
800D7CC4	j      Ld7d54 [$800d7d54]
800D7CC8	nop

Ld7ccc:	; 800D7CCC
800D7CCC	addu   s0, v0, zero
800D7CD0	addu   s1, zero, zero
800D7CD4	sll    a0, a0, $10
800D7CD8	sra    a0, a0, $10
800D7CDC	sll    v0, a1, $10
800D7CE0	sra    v0, v0, $0f
800D7CE4	addu   v1, v0, s0
800D7CE8	addu   v0, v0, s0
800D7CEC	lbu    v1, $0002(v1)
800D7CF0	lbu    v0, $0003(v0)
800D7CF4	addu   s0, s0, v1
800D7CF8	sll    v0, v0, $08
800D7CFC	jal    system_get_character_name_offset [$800257cc]
800D7D00	addu   s0, s0, v0
800D7D04	addu   a0, v0, zero
800D7D08	lbu    v1, $0000(s0)
800D7D0C	ori    v0, zero, $00ff
800D7D10	beq    v1, v0, Ld7d40 [$800d7d40]
800D7D14	sll    v0, s1, $10
800D7D18	ori    v1, zero, $00ff

loopd7d1c:	; 800D7D1C
800D7D1C	lbu    v0, $0000(s0)
800D7D20	addiu  s0, s0, $0001
800D7D24	addiu  s1, s1, $0001
800D7D28	sb     v0, $0000(a0)
800D7D2C	lbu    v0, $0000(s0)
800D7D30	nop
800D7D34	bne    v0, v1, loopd7d1c [$800d7d1c]
800D7D38	addiu  a0, a0, $0001
800D7D3C	sll    v0, s1, $10

Ld7d40:	; 800D7D40
800D7D40	sra    v0, v0, $10
800D7D44	slti   v0, v0, $0009
800D7D48	beq    v0, zero, Ld7d54 [$800d7d54]
800D7D4C	ori    v0, zero, $00ff
800D7D50	sb     v0, $0000(a0)

Ld7d54:	; 800D7D54
800D7D54	lw     ra, $0018(sp)
800D7D58	lw     s1, $0014(sp)
800D7D5C	lw     s0, $0010(sp)
800D7D60	addiu  sp, sp, $0020
800D7D64	jr     ra 
800D7D68	nop


funcd7d6c:	; 800D7D6C
800D7D6C	addiu  sp, sp, $ffb0 (=-$50)
800D7D70	ori    v1, zero, $0001
800D7D74	ori    v0, zero, $0762
800D7D78	sw     ra, $0048(sp)
800D7D7C	sw     s3, $0044(sp)
800D7D80	sw     s2, $0040(sp)
800D7D84	sw     s1, $003c(sp)
800D7D88	sw     s0, $0038(sp)

loopd7d8c:	; 800D7D8C
800D7D8C	lui    at, $800e
800D7D90	addiu  at, at, $08c0
800D7D94	addu   at, at, v0
800D7D98	sb     v1, $0000(at)
800D7D9C	addiu  v0, v0, $fe86 (=-$17a)
800D7DA0	bgez   v0, loopd7d8c [$800d7d8c]
800D7DA4	addu   s0, zero, zero
800D7DA8	ori    a2, zero, $0003
800D7DAC	ori    a1, zero, $0074
800D7DB0	lui    v0, $800e
800D7DB4	addiu  v0, v0, $1028
800D7DB8	addiu  a0, v0, $1580
800D7DBC	addu   v1, v0, zero
800D7DC0	ori    v0, zero, $0001
800D7DC4	lui    at, $800a
800D7DC8	sb     v0, $d824(at)
800D7DCC	lui    at, $800e
800D7DD0	sh     zero, $1024(at)
800D7DD4	lui    at, $8007
800D7DD8	sb     zero, $1c08(at)
800D7DDC	lui    at, $800e
800D7DE0	sh     zero, $4210(at)

loopd7de4:	; 800D7DE4
800D7DE4	sb     a2, $0003(v1)
800D7DE8	sb     a1, $0007(v1)
800D7DEC	sb     a2, $0003(a0)
800D7DF0	sb     a1, $0007(a0)
800D7DF4	lbu    v0, $0007(v1)
800D7DF8	addiu  s0, s0, $0001
800D7DFC	ori    v0, v0, $0001
800D7E00	sb     v0, $0007(v1)
800D7E04	lbu    v0, $0007(a0)
800D7E08	addiu  v1, v1, $0010
800D7E0C	ori    v0, v0, $0001
800D7E10	sb     v0, $0007(a0)
800D7E14	slti   v0, s0, $0158
800D7E18	bne    v0, zero, loopd7de4 [$800d7de4]
800D7E1C	addiu  a0, a0, $0010
800D7E20	addu   s0, zero, zero
800D7E24	ori    a0, zero, $01e7
800D7E28	lui    v1, $800e
800D7E2C	addiu  v1, v1, $4200

loopd7e30:	; 800D7E30
800D7E30	subu   v0, a0, s0
800D7E34	sll    v0, v0, $06
800D7E38	ori    v0, v0, $0010
800D7E3C	sh     v0, $0000(v1)
800D7E40	addiu  s0, s0, $0001
800D7E44	slti   v0, s0, $0008
800D7E48	bne    v0, zero, loopd7e30 [$800d7e30]
800D7E4C	addiu  v1, v1, $0002
800D7E50	addu   s0, zero, zero
800D7E54	ori    a2, zero, $0003
800D7E58	ori    a1, zero, $0060
800D7E5C	lui    v0, $800e
800D7E60	addiu  v0, v0, $3fa8
800D7E64	addiu  a0, v0, $00c0
800D7E68	addu   v1, v0, zero

loopd7e6c:	; 800D7E6C
800D7E6C	sb     a2, $0003(v1)
800D7E70	sb     a1, $0007(v1)
800D7E74	sb     a2, $0003(a0)
800D7E78	sb     a1, $0007(a0)
800D7E7C	lbu    v0, $0007(v1)
800D7E80	addiu  s0, s0, $0001
800D7E84	ori    v0, v0, $0002
800D7E88	sb     v0, $0007(v1)
800D7E8C	lbu    v0, $0007(a0)
800D7E90	addiu  v1, v1, $0010
800D7E94	ori    v0, v0, $0002
800D7E98	sb     v0, $0007(a0)
800D7E9C	slti   v0, s0, $000c
800D7EA0	bne    v0, zero, loopd7e6c [$800d7e6c]
800D7EA4	addiu  a0, a0, $0010
800D7EA8	addu   s0, zero, zero
800D7EAC	ori    a3, zero, $0005
800D7EB0	ori    a2, zero, $0048
800D7EB4	lui    a1, $5555
800D7EB8	ori    a1, a1, $5555
800D7EBC	lui    v0, $800e
800D7EC0	addiu  v0, v0, $3b28
800D7EC4	addiu  a0, v0, $0240
800D7EC8	addu   v1, v0, zero

loopd7ecc:	; 800D7ECC
800D7ECC	sb     a3, $0003(v1)
800D7ED0	sb     a2, $0007(v1)
800D7ED4	sw     a1, $0014(v1)
800D7ED8	sb     a3, $0003(a0)
800D7EDC	sb     a2, $0007(a0)
800D7EE0	sw     a1, $0014(a0)
800D7EE4	addiu  a0, a0, $0018
800D7EE8	addiu  s0, s0, $0001
800D7EEC	slti   v0, s0, $0018
800D7EF0	bne    v0, zero, loopd7ecc [$800d7ecc]
800D7EF4	addiu  v1, v1, $0018
800D7EF8	jal    func43cc0 [$80043cc0]
800D7EFC	nop
800D7F00	ori    v1, zero, $0001
800D7F04	beq    v0, v1, Ld7f20 [$800d7f20]
800D7F08	addu   s0, zero, zero
800D7F0C	jal    func43cc0 [$80043cc0]
800D7F10	nop
800D7F14	ori    v1, zero, $0002
800D7F18	bne    v0, v1, Ld7f24 [$800d7f24]
800D7F1C	ori    a3, zero, $001f

Ld7f20:	; 800D7F20
800D7F20	ori    a3, zero, $002f

Ld7f24:	; 800D7F24
800D7F24	andi   s3, a3, $ffff
800D7F28	lui    v0, $800e
800D7F2C	addiu  v0, v0, $4128
800D7F30	addiu  s2, v0, $0048
800D7F34	addu   s1, v0, zero

loopd7f38:	; 800D7F38
800D7F38	addu   a0, s1, zero
800D7F3C	addu   a1, zero, zero
800D7F40	addu   a2, zero, zero
800D7F44	addu   a3, s3, zero
800D7F48	jal    func44a68 [$80044a68]
800D7F4C	sw     zero, $0010(sp)
800D7F50	addu   a0, s2, zero
800D7F54	addu   a1, zero, zero
800D7F58	addu   a2, zero, zero
800D7F5C	addu   a3, s3, zero
800D7F60	jal    func44a68 [$80044a68]
800D7F64	sw     zero, $0010(sp)
800D7F68	addiu  s2, s2, $000c
800D7F6C	addiu  s0, s0, $0001
800D7F70	slti   v0, s0, $0006
800D7F74	bne    v0, zero, loopd7f38 [$800d7f38]
800D7F78	addiu  s1, s1, $000c
800D7F7C	lw     ra, $0048(sp)
800D7F80	lw     s3, $0044(sp)
800D7F84	lw     s2, $0040(sp)
800D7F88	lw     s1, $003c(sp)
800D7F8C	lw     s0, $0038(sp)
800D7F90	addiu  sp, sp, $0050
800D7F94	jr     ra 
800D7F98	nop


funcd7f9c:	; 800D7F9C
800D7F9C	addiu  sp, sp, $ffd8 (=-$28)
800D7FA0	ori    a0, zero, $0005
800D7FA4	ori    a1, zero, $006c
800D7FA8	addu   a2, zero, zero
800D7FAC	ori    a3, zero, $006c
800D7FB0	sw     s1, $001c(sp)
800D7FB4	ori    s1, zero, $0052
800D7FB8	sw     ra, $0020(sp)
800D7FBC	sw     s0, $0018(sp)
800D7FC0	jal    funcd828c [$800d828c]
800D7FC4	sw     s1, $0010(sp)
800D7FC8	lui    s0, $800e
800D7FCC	addiu  s0, s0, $4254
800D7FD0	lui    a1, $800a
800D7FD4	addiu  a1, a1, $12a8
800D7FD8	jal    funcda334 [$800da334]
800D7FDC	addu   a0, s0, zero
800D7FE0	lui    a1, $800a
800D7FE4	lw     a1, $c6dc(a1)
800D7FE8	addu   a0, s0, zero
800D7FEC	jal    funcda368 [$800da368]
800D7FF0	addiu  a1, a1, $0010
800D7FF4	ori    a0, zero, $0005
800D7FF8	jal    funcd9f00 [$800d9f00]
800D7FFC	addu   a1, s0, zero
800D8000	lui    a1, $800a
800D8004	addiu  a1, a1, $12b0
800D8008	jal    funcda334 [$800da334]
800D800C	addu   a0, s0, zero
800D8010	lui    a1, $800a
800D8014	lw     a1, $c6dc(a1)
800D8018	addu   a0, s0, zero
800D801C	jal    funcda368 [$800da368]
800D8020	addiu  a1, a1, $0018
800D8024	ori    a0, zero, $0005
800D8028	jal    funcd9f00 [$800d9f00]
800D802C	addu   a1, s0, zero
800D8030	lui    a1, $800a
800D8034	addiu  a1, a1, $12b8
800D8038	jal    funcd9f00 [$800d9f00]
800D803C	ori    a0, zero, $0005
800D8040	lui    a1, $800a
800D8044	addiu  a1, a1, $12c0
800D8048	jal    funcd9f00 [$800d9f00]
800D804C	ori    a0, zero, $0005
800D8050	lui    a1, $800a
800D8054	addiu  a1, a1, $12c8
800D8058	jal    funcd9f00 [$800d9f00]
800D805C	ori    a0, zero, $0005
800D8060	ori    a0, zero, $0005
800D8064	lui    a2, $800a
800D8068	addiu  a2, a2, $12d0
800D806C	jal    funcda124 [$800da124]
800D8070	ori    a1, zero, $0005
800D8074	ori    a0, zero, $0005
800D8078	lui    a2, $800a
800D807C	addiu  a2, a2, $12dc
800D8080	jal    funcda124 [$800da124]
800D8084	ori    a1, zero, $0006
800D8088	jal    funcda2cc [$800da2cc]
800D808C	ori    a0, zero, $0005
800D8090	ori    a0, zero, $0004
800D8094	ori    a1, zero, $006c
800D8098	ori    a2, zero, $0052
800D809C	ori    a3, zero, $006c
800D80A0	jal    funcd828c [$800d828c]
800D80A4	sw     s1, $0010(sp)
800D80A8	ori    a0, zero, $0004
800D80AC	lui    s0, $800e
800D80B0	addiu  s0, s0, $0628
800D80B4	jal    funcd9f00 [$800d9f00]
800D80B8	addu   a1, s0, zero
800D80BC	jal    funcda2cc [$800da2cc]
800D80C0	ori    a0, zero, $0004
800D80C4	ori    a0, zero, $0003
800D80C8	ori    a1, zero, $006c
800D80CC	ori    a2, zero, $00a4
800D80D0	ori    a3, zero, $006c
800D80D4	ori    v0, zero, $005c
800D80D8	jal    funcd828c [$800d828c]
800D80DC	sw     v0, $0010(sp)
800D80E0	lui    a1, $800e
800D80E4	addiu  a1, a1, $0630
800D80E8	jal    funcd9f00 [$800d9f00]
800D80EC	ori    a0, zero, $0003
800D80F0	jal    funcda2cc [$800da2cc]
800D80F4	ori    a0, zero, $0003
800D80F8	ori    a0, zero, $0001
800D80FC	addu   a1, zero, zero
800D8100	addu   a2, zero, zero
800D8104	ori    a3, zero, $006c
800D8108	ori    v0, zero, $00ca
800D810C	jal    funcd828c [$800d828c]
800D8110	sw     v0, $0010(sp)
800D8114	ori    a0, zero, $0001
800D8118	jal    funcd9f00 [$800d9f00]
800D811C	addu   a1, s0, zero
800D8120	jal    funcda2cc [$800da2cc]
800D8124	ori    a0, zero, $0001
800D8128	ori    a0, zero, $0005
800D812C	ori    v0, zero, $0003
800D8130	lui    at, $800a
800D8134	sb     v0, $9ffc(at)
800D8138	ori    v0, zero, $0004
800D813C	lui    at, $8008
800D8140	sb     v0, $ebcc(at)
800D8144	ori    v0, zero, $0008
800D8148	lui    at, $8008
800D814C	sb     v0, $ebdc(at)
800D8150	ori    v0, zero, $0005
800D8154	lui    at, $8007
800D8158	sb     zero, $1e24(at)
800D815C	lui    at, $800a
800D8160	sb     zero, $d820(at)
800D8164	lui    at, $8007
800D8168	sb     zero, $0788(at)
800D816C	lui    at, $8007
800D8170	sb     v0, $1c08(at)
800D8174	jal    funcda1d4 [$800da1d4]
800D8178	ori    a1, zero, $0004
800D817C	lw     ra, $0020(sp)
800D8180	lw     s1, $001c(sp)
800D8184	lw     s0, $0018(sp)
800D8188	addiu  sp, sp, $0028
800D818C	jr     ra 
800D8190	nop

800D8194	addiu  sp, sp, $ffe0 (=-$20)
800D8198	addu   t0, a0, zero
800D819C	addu   t1, a1, zero
800D81A0	addu   t2, a2, zero
800D81A4	addu   a1, a3, zero
800D81A8	addu   a0, zero, zero
800D81AC	sll    a3, a3, $10
800D81B0	sra    a3, a3, $10
800D81B4	sw     ra, $001c(sp)
800D81B8	sw     s0, $0018(sp)
800D81BC	sll    v0, a0, $10

loopd81c0:	; 800D81C0
800D81C0	sra    s0, v0, $10
800D81C4	sll    v1, s0, $01
800D81C8	addu   v1, v1, s0
800D81CC	sll    v0, v1, $06
800D81D0	subu   v0, v0, v1
800D81D4	sll    v0, v0, $01
800D81D8	lui    at, $800e
800D81DC	addiu  at, at, $08c0
800D81E0	addu   at, at, v0
800D81E4	lbu    v0, $0000(at)
800D81E8	nop
800D81EC	beq    v0, zero, Ld8228 [$800d8228]
800D81F0	addiu  v0, a0, $0001
800D81F4	sw     a3, $0010(sp)
800D81F8	addu   a0, s0, zero
800D81FC	sll    a1, t0, $10
800D8200	sra    a1, a1, $10
800D8204	sll    a2, t1, $10
800D8208	sra    a2, a2, $10
800D820C	sll    a3, t2, $10
800D8210	jal    funcd8334 [$800d8334]
800D8214	sra    a3, a3, $10
800D8218	jal    funcd84cc [$800d84cc]
800D821C	addu   a0, s0, zero
800D8220	j      Ld8278 [$800d8278]
800D8224	addu   v0, s0, zero

Ld8228:	; 800D8228
800D8228	addu   a0, v0, zero
800D822C	sll    v0, v0, $10
800D8230	sra    v0, v0, $10
800D8234	slti   v0, v0, $0006
800D8238	bne    v0, zero, loopd81c0 [$800d81c0]
800D823C	sll    v0, a0, $10
800D8240	sll    v0, a1, $10
800D8244	sra    v0, v0, $10
800D8248	sw     v0, $0010(sp)
800D824C	addu   a0, zero, zero
800D8250	sll    a1, t0, $10
800D8254	sra    a1, a1, $10
800D8258	sll    a2, t1, $10
800D825C	sra    a2, a2, $10
800D8260	sll    a3, t2, $10
800D8264	jal    funcd8334 [$800d8334]
800D8268	sra    a3, a3, $10
800D826C	jal    funcd84cc [$800d84cc]
800D8270	addu   a0, zero, zero
800D8274	addu   v0, zero, zero

Ld8278:	; 800D8278
800D8278	lw     ra, $001c(sp)
800D827C	lw     s0, $0018(sp)
800D8280	addiu  sp, sp, $0020
800D8284	jr     ra 
800D8288	nop


funcd828c:	; 800D828C
800D828C	addiu  sp, sp, $ffe0 (=-$20)
800D8290	sll    a0, a0, $10
800D8294	sw     s0, $0018(sp)
800D8298	sra    s0, a0, $10
800D829C	addu   a0, s0, zero
800D82A0	sll    a1, a1, $10
800D82A4	sll    a2, a2, $10
800D82A8	sll    a3, a3, $10
800D82AC	sra    a1, a1, $10
800D82B0	sra    a2, a2, $10
800D82B4	lh     v0, $0030(sp)
800D82B8	sra    a3, a3, $10
800D82BC	sw     ra, $001c(sp)
800D82C0	jal    funcd8334 [$800d8334]
800D82C4	sw     v0, $0010(sp)
800D82C8	sll    v1, s0, $01
800D82CC	addu   v1, v1, s0
800D82D0	sll    v0, v1, $06
800D82D4	subu   v0, v0, v1
800D82D8	sll    a0, v0, $01
800D82DC	lui    at, $800e
800D82E0	addiu  at, at, $08c0
800D82E4	addu   at, at, a0
800D82E8	lbu    v1, $0000(at)
800D82EC	ori    v0, zero, $0002
800D82F0	beq    v1, v0, Ld8308 [$800d8308]
800D82F4	ori    v0, zero, $0001
800D82F8	jal    funcd84cc [$800d84cc]
800D82FC	addu   a0, s0, zero
800D8300	j      Ld8320 [$800d8320]
800D8304	nop

Ld8308:	; 800D8308
800D8308	lui    at, $800e
800D830C	addiu  at, at, $08c0
800D8310	addu   at, at, a0
800D8314	sb     zero, $0000(at)
800D8318	lui    at, $800a
800D831C	sb     v0, $d824(at)

Ld8320:	; 800D8320
800D8320	lw     ra, $001c(sp)
800D8324	lw     s0, $0018(sp)
800D8328	addiu  sp, sp, $0020
800D832C	jr     ra 
800D8330	nop


funcd8334:	; 800D8334
800D8334	sll    a0, a0, $10
800D8338	sra    a0, a0, $10
800D833C	sll    v0, a0, $01
800D8340	addu   v0, v0, a0
800D8344	sll    v1, v0, $06
800D8348	subu   v1, v1, v0
800D834C	sll    v1, v1, $01
800D8350	lui    at, $800e
800D8354	addiu  at, at, $0748
800D8358	addu   at, at, v1
800D835C	sh     a1, $0000(at)
800D8360	lui    at, $800e
800D8364	addiu  at, at, $074a
800D8368	addu   at, at, v1
800D836C	sh     a2, $0000(at)
800D8370	lui    at, $800e
800D8374	addiu  at, at, $074c
800D8378	addu   at, at, v1
800D837C	sh     a3, $0000(at)
800D8380	lhu    a0, $0010(sp)
800D8384	ori    v0, zero, $0001
800D8388	lui    at, $800a
800D838C	sb     v0, $d824(at)
800D8390	lui    at, $800e
800D8394	addiu  at, at, $074e
800D8398	addu   at, at, v1
800D839C	sh     a0, $0000(at)
800D83A0	jr     ra 
800D83A4	nop

800D83A8	ori    v0, zero, $0001
800D83AC	sll    a0, a0, $10
800D83B0	sra    a0, a0, $10
800D83B4	sll    v1, a0, $01
800D83B8	addu   v1, v1, a0
800D83BC	lui    at, $800a
800D83C0	sb     v0, $d824(at)
800D83C4	sll    v0, v1, $06
800D83C8	subu   v0, v0, v1
800D83CC	sll    v0, v0, $01
800D83D0	lui    at, $800e
800D83D4	addiu  at, at, $0748
800D83D8	addu   at, at, v0
800D83DC	lhu    v1, $0000(at)
800D83E0	lui    at, $800e
800D83E4	addiu  at, at, $074a
800D83E8	addu   at, at, v0
800D83EC	lhu    a0, $0000(at)
800D83F0	addu   v1, v1, a1
800D83F4	addu   a0, a0, a2
800D83F8	lui    at, $800e
800D83FC	addiu  at, at, $0748
800D8400	addu   at, at, v0
800D8404	sh     v1, $0000(at)
800D8408	lui    at, $800e
800D840C	addiu  at, at, $074a
800D8410	addu   at, at, v0
800D8414	sh     a0, $0000(at)
800D8418	jr     ra 
800D841C	nop

800D8420	ori    v0, zero, $0001
800D8424	sll    a0, a0, $10
800D8428	sra    a0, a0, $10
800D842C	sll    v1, a0, $01
800D8430	addu   v1, v1, a0
800D8434	lui    at, $800a
800D8438	sb     v0, $d824(at)
800D843C	sll    v0, v1, $06
800D8440	subu   v0, v0, v1
800D8444	sll    v0, v0, $01
800D8448	lui    at, $800e
800D844C	addiu  at, at, $074c
800D8450	addu   at, at, v0
800D8454	lhu    v1, $0000(at)
800D8458	lui    at, $800e
800D845C	addiu  at, at, $074e
800D8460	addu   at, at, v0
800D8464	lhu    a0, $0000(at)
800D8468	addu   v1, v1, a1
800D846C	addu   a0, a0, a2
800D8470	lui    at, $800e
800D8474	addiu  at, at, $074c
800D8478	addu   at, at, v0
800D847C	sh     v1, $0000(at)
800D8480	lui    at, $800e
800D8484	addiu  at, at, $074e
800D8488	addu   at, at, v0
800D848C	sh     a0, $0000(at)
800D8490	jr     ra 
800D8494	nop

800D8498	sll    a0, a0, $10
800D849C	sra    a0, a0, $10
800D84A0	sll    v1, a0, $01
800D84A4	addu   v1, v1, a0
800D84A8	sll    v0, v1, $06
800D84AC	subu   v0, v0, v1
800D84B0	sll    v0, v0, $01
800D84B4	lui    at, $800e
800D84B8	addiu  at, at, $08c0
800D84BC	addu   at, at, v0
800D84C0	lbu    v0, $0000(at)
800D84C4	jr     ra 
800D84C8	sltiu  v0, v0, $0001


funcd84cc:	; 800D84CC
800D84CC	addu   a2, a0, zero
800D84D0	addu   a1, zero, zero
800D84D4	sll    a0, a0, $10
800D84D8	sra    a0, a0, $10
800D84DC	sll    v0, a0, $01
800D84E0	addu   v0, v0, a0
800D84E4	sll    v1, v0, $06
800D84E8	subu   v1, v1, v0
800D84EC	sll    v1, v1, $01
800D84F0	lui    v0, $800e
800D84F4	addiu  v0, v0, $08a8
800D84F8	addu   a0, v1, v0

loopd84fc:	; 800D84FC
800D84FC	lui    at, $800e
800D8500	addiu  at, at, $0758
800D8504	addu   at, at, v1
800D8508	sb     zero, $0000(at)
800D850C	sb     zero, $0000(a0)
800D8510	addiu  a0, a0, $0001
800D8514	addiu  a1, a1, $0001
800D8518	slti   v0, a1, $0018
800D851C	bne    v0, zero, loopd84fc [$800d84fc]
800D8520	addiu  v1, v1, $000e
800D8524	sll    v0, a2, $10
800D8528	sra    v0, v0, $10
800D852C	sll    v1, v0, $01
800D8530	addu   v1, v1, v0
800D8534	sll    v0, v1, $06
800D8538	subu   v0, v0, v1
800D853C	sll    v0, v0, $01
800D8540	ori    v1, zero, $0007
800D8544	lui    at, $800e
800D8548	addiu  at, at, $0750
800D854C	addu   at, at, v0
800D8550	sb     v1, $0000(at)
800D8554	ori    v1, zero, $000f
800D8558	lui    at, $800e
800D855C	addiu  at, at, $0751
800D8560	addu   at, at, v0
800D8564	sb     v1, $0000(at)
800D8568	ori    v1, zero, $001f
800D856C	lui    at, $800e
800D8570	addiu  at, at, $0752
800D8574	addu   at, at, v0
800D8578	sb     v1, $0000(at)
800D857C	lui    at, $800e
800D8580	addiu  at, at, $0756
800D8584	addu   at, at, v0
800D8588	sh     zero, $0000(at)
800D858C	lui    at, $800e
800D8590	addiu  at, at, $0754
800D8594	addu   at, at, v0
800D8598	sh     zero, $0000(at)
800D859C	lui    at, $800e
800D85A0	addiu  at, at, $08c0
800D85A4	addu   at, at, v0
800D85A8	sb     zero, $0000(at)
800D85AC	ori    v0, zero, $0001
800D85B0	lui    at, $800a
800D85B4	sb     v0, $d824(at)
800D85B8	jr     ra 
800D85BC	nop


funcd85c0:	; 800D85C0
800D85C0	lui    v0, $800e
800D85C4	lhu    v0, $1024(v0)
800D85C8	lui    at, $800e
800D85CC	sh     zero, $41b8(at)
800D85D0	lui    at, $800e
800D85D4	sh     zero, $41c0(at)
800D85D8	lui    at, $800e
800D85DC	sh     zero, $41bc(at)
800D85E0	lui    at, $800e
800D85E4	sh     zero, $41c4(at)
800D85E8	xori   v0, v0, $0001
800D85EC	lui    at, $800e
800D85F0	sh     v0, $1024(at)
800D85F4	jr     ra 
800D85F8	nop

800D85FC	lui    v0, $800a
800D8600	lbu    v0, $d824(v0)
800D8604	addiu  sp, sp, $ffe0 (=-$20)
800D8608	sw     s2, $0018(sp)
800D860C	addu   s2, a0, zero
800D8610	sw     ra, $001c(sp)
800D8614	sw     s1, $0014(sp)
800D8618	beq    v0, zero, Ld8694 [$800d8694]
800D861C	sw     s0, $0010(sp)
800D8620	jal    funcd85c0 [$800d85c0]
800D8624	addu   s0, zero, zero
800D8628	lui    v0, $800e
800D862C	lh     v0, $1024(v0)
800D8630	addu   s1, zero, zero
800D8634	ori    a1, zero, $0007
800D8638	sll    a0, v0, $03
800D863C	subu   a0, a0, v0
800D8640	sll    a0, a0, $02
800D8644	lui    v0, $800e
800D8648	addiu  v0, v0, $41c8
800D864C	jal    func4418c [$8004418c]
800D8650	addu   a0, a0, v0

loopd8654:	; 800D8654
800D8654	lui    at, $800e
800D8658	addiu  at, at, $08c0
800D865C	addu   at, at, s1
800D8660	lbu    v0, $0000(at)
800D8664	nop
800D8668	bne    v0, zero, Ld867c [$800d867c]
800D866C	addiu  s1, s1, $017a
800D8670	sll    a0, s0, $10
800D8674	jal    funcd8710 [$800d8710]
800D8678	sra    a0, a0, $10

Ld867c:	; 800D867C
800D867C	addiu  s0, s0, $0001
800D8680	slti   v0, s0, $0006
800D8684	bne    v0, zero, loopd8654 [$800d8654]
800D8688	nop
800D868C	lui    at, $800a
800D8690	sb     zero, $d824(at)

Ld8694:	; 800D8694
800D8694	lui    a3, $00ff
800D8698	ori    a3, a3, $ffff
800D869C	lui    a1, $800e
800D86A0	addiu  a1, a1, $41e0
800D86A4	lui    v0, $800e
800D86A8	lh     v0, $1024(v0)
800D86AC	lui    t0, $ff00
800D86B0	sll    a0, v0, $03
800D86B4	subu   a0, a0, v0
800D86B8	sll    a0, a0, $02
800D86BC	addu   a2, a0, a1
800D86C0	addiu  a1, a1, $ffe8 (=-$18)
800D86C4	addu   a0, a0, a1
800D86C8	lw     v1, $0000(a2)
800D86CC	lw     v0, $0000(s2)
800D86D0	and    v1, v1, t0
800D86D4	and    v0, v0, a3
800D86D8	or     v1, v1, v0
800D86DC	sw     v1, $0000(a2)
800D86E0	lw     v0, $0000(s2)
800D86E4	and    a0, a0, a3
800D86E8	and    v0, v0, t0
800D86EC	or     v0, v0, a0
800D86F0	sw     v0, $0000(s2)
800D86F4	lw     ra, $001c(sp)
800D86F8	lw     s2, $0018(sp)
800D86FC	lw     s1, $0014(sp)
800D8700	lw     s0, $0010(sp)
800D8704	addiu  sp, sp, $0020
800D8708	jr     ra 
800D870C	nop


funcd8710:	; 800D8710
800D8710	lui    v0, $800e
800D8714	lh     v0, $41bc(v0)
800D8718	addiu  sp, sp, $ff78 (=-$88)
800D871C	sw     s5, $007c(sp)
800D8720	addu   s5, a0, zero
800D8724	sw     ra, $0080(sp)
800D8728	sw     s4, $0078(sp)
800D872C	sw     s3, $0074(sp)
800D8730	sw     s2, $0070(sp)
800D8734	sw     s1, $006c(sp)
800D8738	slti   v0, v0, $0018
800D873C	beq    v0, zero, Ld9bdc [$800d9bdc]
800D8740	sw     s0, $0068(sp)
800D8744	sll    a1, a0, $10
800D8748	sra    a1, a1, $10
800D874C	sll    v0, a1, $01
800D8750	addu   v0, v0, a1
800D8754	sll    a0, v0, $06
800D8758	subu   a0, a0, v0
800D875C	sll    a0, a0, $01
800D8760	addu   s1, zero, zero
800D8764	lui    at, $800e
800D8768	addiu  at, at, $074a
800D876C	addu   at, at, a0
800D8770	lhu    v1, $0000(at)
800D8774	addu   s0, a0, zero
800D8778	addiu  v0, v1, $0002
800D877C	addu   s2, v0, zero
800D8780	sll    v0, v0, $10
800D8784	sra    a2, v0, $10
800D8788	lui    v0, $800e
800D878C	addiu  v0, v0, $0758
800D8790	addu   s3, s0, v0
800D8794	sll    v1, v1, $10
800D8798	lui    at, $800e
800D879C	addiu  at, at, $074e
800D87A0	addu   at, at, s0
800D87A4	lh     v0, $0000(at)
800D87A8	sra    v1, v1, $10
800D87AC	addu   v1, v1, v0
800D87B0	addiu  v1, v1, $fff8 (=-$8)
800D87B4	slt    v1, a2, v1
800D87B8	beq    v1, zero, Ld8840 [$800d8840]
800D87BC	addu   s4, a1, zero
800D87C0	sll    a1, s1, $10

loopd87c4:	; 800D87C4
800D87C4	addiu  s1, s1, $0001
800D87C8	lui    at, $800e
800D87CC	addiu  at, at, $0748
800D87D0	addu   at, at, s0
800D87D4	lh     a3, $0000(at)
800D87D8	sra    a1, a1, $10
800D87DC	sw     a2, $0010(sp)
800D87E0	sll    a2, a1, $03
800D87E4	subu   a2, a2, a1
800D87E8	sll    a2, a2, $01
800D87EC	addu   a0, s4, zero
800D87F0	addu   a2, s3, a2
800D87F4	jal    funcd9c04 [$800d9c04]
800D87F8	addiu  a3, a3, $0002
800D87FC	addiu  v1, s2, $000a
800D8800	addu   s2, v1, zero
800D8804	sll    v1, v1, $10
800D8808	lui    at, $800e
800D880C	addiu  at, at, $074a
800D8810	addu   at, at, s0
800D8814	lh     v0, $0000(at)
800D8818	lui    at, $800e
800D881C	addiu  at, at, $074e
800D8820	addu   at, at, s0
800D8824	lh     a0, $0000(at)
800D8828	sra    a2, v1, $10
800D882C	addu   v0, v0, a0
800D8830	addiu  v0, v0, $fff8 (=-$8)
800D8834	slt    v0, a2, v0
800D8838	bne    v0, zero, loopd87c4 [$800d87c4]
800D883C	sll    a1, s1, $10

Ld8840:	; 800D8840
800D8840	sll    v0, s5, $10
800D8844	sra    t5, v0, $10
800D8848	sll    v1, t5, $01
800D884C	addu   v1, v1, t5
800D8850	sll    v0, v1, $06
800D8854	subu   v0, v0, v1
800D8858	sll    t7, v0, $01
800D885C	lui    at, $800e
800D8860	addiu  at, at, $0756
800D8864	addu   at, at, t7
800D8868	lh     v0, $0000(at)
800D886C	nop
800D8870	beq    v0, zero, Ld8f2c [$800d8f2c]
800D8874	lui    t3, $00ff
800D8878	lui    t2, $800e
800D887C	addiu  t2, t2, $3b28
800D8880	lui    v0, $800e
800D8884	lh     v0, $1024(v0)
800D8888	lui    v1, $800e
800D888C	lh     v1, $41bc(v1)
800D8890	sll    a0, v0, $03
800D8894	addu   a0, a0, v0
800D8898	sll    a0, a0, $06
800D889C	sll    v0, v1, $01
800D88A0	addu   v0, v0, v1
800D88A4	sll    v0, v0, $03
800D88A8	addu   a0, a0, v0
800D88AC	lui    at, $800e
800D88B0	addiu  at, at, $0748
800D88B4	addu   at, at, t7
800D88B8	lhu    v0, $0000(at)
800D88BC	addu   a0, a0, t2
800D88C0	addiu  v0, v0, $0002
800D88C4	sh     v0, $0008(a0)
800D88C8	lui    at, $800e
800D88CC	addiu  at, at, $0756
800D88D0	addu   at, at, t7
800D88D4	lh     v0, $0000(at)
800D88D8	ori    t3, t3, $ffff
800D88DC	addiu  v0, v0, $ffff (=-$1)
800D88E0	sll    v1, v0, $02
800D88E4	addu   v1, v1, v0
800D88E8	lui    at, $800e
800D88EC	addiu  at, at, $074a
800D88F0	addu   at, at, t7
800D88F4	lhu    v0, $0000(at)
800D88F8	sll    v1, v1, $01
800D88FC	addu   v0, v0, v1
800D8900	addiu  v0, v0, $000a
800D8904	sh     v0, $000a(a0)
800D8908	lui    at, $800e
800D890C	addiu  at, at, $074c
800D8910	addu   at, at, t7
800D8914	lhu    v0, $0000(at)
800D8918	lui    at, $800e
800D891C	addiu  at, at, $0748
800D8920	addu   at, at, t7
800D8924	lhu    v1, $0000(at)
800D8928	addiu  v0, v0, $fffe (=-$2)
800D892C	addu   v1, v1, v0
800D8930	sh     v1, $000c(a0)
800D8934	lui    at, $800e
800D8938	addiu  at, at, $0756
800D893C	addu   at, at, t7
800D8940	lh     v0, $0000(at)
800D8944	lui    t6, $800e
800D8948	addiu  t6, t6, $41c8
800D894C	addiu  v0, v0, $ffff (=-$1)
800D8950	sll    v1, v0, $02
800D8954	addu   v1, v1, v0
800D8958	lui    at, $800e
800D895C	addiu  at, at, $074a
800D8960	addu   at, at, t7
800D8964	lhu    v0, $0000(at)
800D8968	sll    v1, v1, $01
800D896C	addu   v0, v0, v1
800D8970	addiu  v0, v0, $000a
800D8974	sh     v0, $000e(a0)
800D8978	lui    at, $800e
800D897C	addiu  at, at, $074c
800D8980	addu   at, at, t7
800D8984	lhu    v0, $0000(at)
800D8988	lui    at, $800e
800D898C	addiu  at, at, $0748
800D8990	addu   at, at, t7
800D8994	lhu    v1, $0000(at)
800D8998	addiu  v0, v0, $fffe (=-$2)
800D899C	addu   v1, v1, v0
800D89A0	sh     v1, $0010(a0)
800D89A4	lui    at, $800e
800D89A8	addiu  at, at, $0756
800D89AC	addu   at, at, t7
800D89B0	lh     v0, $0000(at)
800D89B4	sll    t5, t5, $02
800D89B8	addiu  v0, v0, $ffff (=-$1)
800D89BC	sll    v1, v0, $02
800D89C0	addu   v1, v1, v0
800D89C4	lui    at, $800e
800D89C8	addiu  at, at, $074a
800D89CC	addu   at, at, t7
800D89D0	lhu    v0, $0000(at)
800D89D4	sll    v1, v1, $01
800D89D8	addu   v0, v0, v1
800D89DC	sh     v0, $0012(a0)
800D89E0	lui    at, $800e
800D89E4	addiu  at, at, $0750
800D89E8	addu   at, at, t7
800D89EC	lbu    v0, $0000(at)
800D89F0	lui    t4, $ff00
800D89F4	ori    v0, v0, $003f
800D89F8	sb     v0, $0004(a0)
800D89FC	lui    v0, $800e
800D8A00	lh     v0, $1024(v0)
800D8A04	lui    a0, $800e
800D8A08	lh     a0, $41bc(a0)
800D8A0C	sll    v1, v0, $03
800D8A10	addu   v1, v1, v0
800D8A14	sll    v1, v1, $06
800D8A18	sll    v0, a0, $01
800D8A1C	addu   v0, v0, a0
800D8A20	sll    v0, v0, $03
800D8A24	addu   v1, v1, v0
800D8A28	lui    at, $800e
800D8A2C	addiu  at, at, $0751
800D8A30	addu   at, at, t7
800D8A34	lbu    v0, $0000(at)
800D8A38	addu   v1, v1, t2
800D8A3C	srl    v0, v0, $01
800D8A40	sb     v0, $0005(v1)
800D8A44	lui    v0, $800e
800D8A48	lh     v0, $1024(v0)
800D8A4C	lui    a0, $800e
800D8A50	lh     a0, $41bc(a0)
800D8A54	sll    v1, v0, $03
800D8A58	addu   v1, v1, v0
800D8A5C	sll    v1, v1, $06
800D8A60	sll    v0, a0, $01
800D8A64	addu   v0, v0, a0
800D8A68	sll    v0, v0, $03
800D8A6C	addu   v1, v1, v0
800D8A70	lui    at, $800e
800D8A74	addiu  at, at, $0752
800D8A78	addu   at, at, t7
800D8A7C	lbu    v0, $0000(at)
800D8A80	addu   v1, v1, t2
800D8A84	sb     v0, $0006(v1)
800D8A88	lui    v0, $800e
800D8A8C	lh     v0, $1024(v0)
800D8A90	lui    t0, $800e
800D8A94	lh     t0, $41bc(t0)
800D8A98	sll    a1, v0, $03
800D8A9C	addu   a2, a1, v0
800D8AA0	sll    a2, a2, $06
800D8AA4	sll    a0, t0, $01
800D8AA8	addu   a0, a0, t0
800D8AAC	sll    a0, a0, $03
800D8AB0	addu   a3, a2, a0
800D8AB4	addu   a3, a3, t2
800D8AB8	subu   a1, a1, v0
800D8ABC	sll    a1, a1, $02
800D8AC0	addu   a1, a1, t5
800D8AC4	addu   a1, a1, t6
800D8AC8	addu   a0, a0, t2
800D8ACC	addu   a0, a2, a0
800D8AD0	and    a0, a0, t3
800D8AD4	addiu  t0, t0, $0001
800D8AD8	lw     v1, $0000(a3)
800D8ADC	lw     v0, $0000(a1)
800D8AE0	and    v1, v1, t4
800D8AE4	and    v0, v0, t3
800D8AE8	or     v1, v1, v0
800D8AEC	sw     v1, $0000(a3)
800D8AF0	sll    v1, t0, $10
800D8AF4	lw     v0, $0000(a1)
800D8AF8	sra    v1, v1, $10
800D8AFC	and    v0, v0, t4
800D8B00	or     v0, v0, a0
800D8B04	sw     v0, $0000(a1)
800D8B08	sll    v0, v1, $01
800D8B0C	addu   v0, v0, v1
800D8B10	sll    v0, v0, $03
800D8B14	addu   a2, a2, v0
800D8B18	lui    at, $800e
800D8B1C	addiu  at, at, $0748
800D8B20	addu   at, at, t7
800D8B24	lhu    v0, $0000(at)
800D8B28	addu   a2, a2, t2
800D8B2C	addiu  v0, v0, $0002
800D8B30	sh     v0, $0008(a2)
800D8B34	lui    at, $800e
800D8B38	addiu  at, at, $0756
800D8B3C	addu   at, at, t7
800D8B40	lh     v0, $0000(at)
800D8B44	nop
800D8B48	addiu  v0, v0, $ffff (=-$1)
800D8B4C	sll    v1, v0, $02
800D8B50	addu   v1, v1, v0
800D8B54	lui    at, $800e
800D8B58	addiu  at, at, $074a
800D8B5C	addu   at, at, t7
800D8B60	lhu    v0, $0000(at)
800D8B64	sll    v1, v1, $01
800D8B68	addu   v0, v0, v1
800D8B6C	addiu  v0, v0, $000a
800D8B70	sh     v0, $000a(a2)
800D8B74	lui    at, $800e
800D8B78	addiu  at, at, $0748
800D8B7C	addu   at, at, t7
800D8B80	lhu    v0, $0000(at)
800D8B84	nop
800D8B88	addiu  v0, v0, $0002
800D8B8C	sh     v0, $000c(a2)
800D8B90	lui    at, $800e
800D8B94	addiu  at, at, $0756
800D8B98	addu   at, at, t7
800D8B9C	lh     v0, $0000(at)
800D8BA0	nop
800D8BA4	addiu  v0, v0, $ffff (=-$1)
800D8BA8	sll    v1, v0, $02
800D8BAC	addu   v1, v1, v0
800D8BB0	lui    at, $800e
800D8BB4	addiu  at, at, $074a
800D8BB8	addu   at, at, t7
800D8BBC	lhu    v0, $0000(at)
800D8BC0	sll    v1, v1, $01
800D8BC4	addu   v0, v0, v1
800D8BC8	sh     v0, $000e(a2)
800D8BCC	lui    at, $800e
800D8BD0	addiu  at, at, $074c
800D8BD4	addu   at, at, t7
800D8BD8	lhu    v0, $0000(at)
800D8BDC	lui    at, $800e
800D8BE0	addiu  at, at, $0748
800D8BE4	addu   at, at, t7
800D8BE8	lhu    v1, $0000(at)
800D8BEC	addiu  v0, v0, $fffe (=-$2)
800D8BF0	addu   v1, v1, v0
800D8BF4	sh     v1, $0010(a2)
800D8BF8	lui    at, $800e
800D8BFC	addiu  at, at, $0756
800D8C00	addu   at, at, t7
800D8C04	lh     v1, $0000(at)
800D8C08	lui    at, $800e
800D8C0C	sh     t0, $41bc(at)
800D8C10	addiu  v1, v1, $ffff (=-$1)
800D8C14	sll    v0, v1, $02
800D8C18	addu   v0, v0, v1
800D8C1C	lui    at, $800e
800D8C20	addiu  at, at, $074a
800D8C24	addu   at, at, t7
800D8C28	lhu    v1, $0000(at)
800D8C2C	sll    v0, v0, $01
800D8C30	addu   v1, v1, v0
800D8C34	sh     v1, $0012(a2)
800D8C38	lui    at, $800e
800D8C3C	addiu  at, at, $0750
800D8C40	addu   at, at, t7
800D8C44	lbu    v0, $0000(at)
800D8C48	nop
800D8C4C	sll    v0, v0, $02
800D8C50	ori    v0, v0, $007f
800D8C54	sb     v0, $0004(a2)
800D8C58	lui    v0, $800e
800D8C5C	lh     v0, $1024(v0)
800D8C60	lui    a0, $800e
800D8C64	lh     a0, $41bc(a0)
800D8C68	sll    v1, v0, $03
800D8C6C	addu   v1, v1, v0
800D8C70	sll    v1, v1, $06
800D8C74	sll    v0, a0, $01
800D8C78	addu   v0, v0, a0
800D8C7C	sll    v0, v0, $03
800D8C80	addu   v1, v1, v0
800D8C84	lui    at, $800e
800D8C88	addiu  at, at, $0751
800D8C8C	addu   at, at, t7
800D8C90	lbu    v0, $0000(at)
800D8C94	addu   v1, v1, t2
800D8C98	ori    v0, v0, $003f
800D8C9C	sb     v0, $0005(v1)
800D8CA0	lui    v0, $800e
800D8CA4	lh     v0, $1024(v0)
800D8CA8	lui    a0, $800e
800D8CAC	lh     a0, $41bc(a0)
800D8CB0	sll    v1, v0, $03
800D8CB4	addu   v1, v1, v0
800D8CB8	sll    v1, v1, $06
800D8CBC	sll    v0, a0, $01
800D8CC0	addu   v0, v0, a0
800D8CC4	sll    v0, v0, $03
800D8CC8	addu   v1, v1, v0
800D8CCC	lui    at, $800e
800D8CD0	addiu  at, at, $0752
800D8CD4	addu   at, at, t7
800D8CD8	lbu    v0, $0000(at)
800D8CDC	addu   v1, v1, t2
800D8CE0	sll    v0, v0, $01
800D8CE4	ori    v0, v0, $003f
800D8CE8	sb     v0, $0006(v1)
800D8CEC	lui    t0, $800e
800D8CF0	lh     t0, $1024(t0)
800D8CF4	lui    t1, $800e
800D8CF8	lh     t1, $41bc(t1)
800D8CFC	sll    a0, t0, $03
800D8D00	addu   a2, a0, t0
800D8D04	sll    a2, a2, $06
800D8D08	sll    a1, t1, $01
800D8D0C	addu   a1, a1, t1
800D8D10	sll    a1, a1, $03
800D8D14	addu   a3, a2, a1
800D8D18	addu   a3, a3, t2
800D8D1C	subu   a0, a0, t0
800D8D20	sll    a0, a0, $02
800D8D24	addu   a0, a0, t5
800D8D28	addu   a0, a0, t6
800D8D2C	addu   a1, a1, t2
800D8D30	addu   a2, a2, a1
800D8D34	and    a2, a2, t3
800D8D38	lw     v1, $0000(a3)
800D8D3C	lw     v0, $0000(a0)
800D8D40	and    v1, v1, t4
800D8D44	and    v0, v0, t3
800D8D48	or     v1, v1, v0
800D8D4C	sw     v1, $0000(a3)
800D8D50	lw     v0, $0000(a0)
800D8D54	lui    t2, $800e
800D8D58	addiu  t2, t2, $3fa8
800D8D5C	and    v0, v0, t4
800D8D60	or     v0, v0, a2
800D8D64	sw     v0, $0000(a0)
800D8D68	sll    a0, t0, $01
800D8D6C	addu   a0, a0, t0
800D8D70	lui    v0, $800e
800D8D74	lh     v0, $41c0(v0)

funcd8d78:	; 800D8D78
800D8D78	sll    a0, a0, $06
800D8D7C	sll    v0, v0, $04
800D8D80	addu   a0, a0, v0
800D8D84	lui    at, $800e
800D8D88	addiu  at, at, $0748
800D8D8C	addu   at, at, t7
800D8D90	lhu    v0, $0000(at)
800D8D94	addu   a0, a0, t2
800D8D98	addiu  v0, v0, $0002
800D8D9C	sh     v0, $0008(a0)
800D8DA0	lui    at, $800e
800D8DA4	addiu  at, at, $0756
800D8DA8	addu   at, at, t7
800D8DAC	lh     v1, $0000(at)
800D8DB0	addiu  t1, t1, $0001
800D8DB4	lui    at, $800e
800D8DB8	sh     t1, $41bc(at)
800D8DBC	addiu  v1, v1, $ffff (=-$1)
800D8DC0	sll    v0, v1, $02
800D8DC4	addu   v0, v0, v1
800D8DC8	lui    at, $800e
800D8DCC	addiu  at, at, $074a
800D8DD0	addu   at, at, t7
800D8DD4	lhu    v1, $0000(at)
800D8DD8	sll    v0, v0, $01
800D8DDC	addu   v1, v1, v0
800D8DE0	sh     v1, $000a(a0)
800D8DE4	lui    at, $800e
800D8DE8	addiu  at, at, $074c
800D8DEC	addu   at, at, t7
800D8DF0	lhu    v0, $0000(at)
800D8DF4	ori    v1, zero, $000a
800D8DF8	sh     v1, $000e(a0)
800D8DFC	addiu  v0, v0, $fffc (=-$4)
800D8E00	sh     v0, $000c(a0)
800D8E04	lui    at, $800e
800D8E08	addiu  at, at, $0750
800D8E0C	addu   at, at, t7
800D8E10	lbu    v0, $0000(at)
800D8E14	nop
800D8E18	sll    v0, v0, $01
800D8E1C	ori    v0, v0, $007f
800D8E20	sb     v0, $0004(a0)
800D8E24	lui    v1, $800e
800D8E28	lh     v1, $1024(v1)
800D8E2C	nop
800D8E30	sll    v0, v1, $01
800D8E34	addu   v0, v0, v1
800D8E38	lui    v1, $800e
800D8E3C	lh     v1, $41c0(v1)
800D8E40	sll    v0, v0, $06
800D8E44	sll    v1, v1, $04
800D8E48	addu   v0, v0, v1
800D8E4C	lui    at, $800e
800D8E50	addiu  at, at, $0751
800D8E54	addu   at, at, t7
800D8E58	lbu    v1, $0000(at)
800D8E5C	addu   v0, v0, t2
800D8E60	srl    v1, v1, $01
800D8E64	sb     v1, $0005(v0)
800D8E68	lui    v1, $800e
800D8E6C	lh     v1, $1024(v1)
800D8E70	nop
800D8E74	sll    v0, v1, $01
800D8E78	addu   v0, v0, v1
800D8E7C	lui    v1, $800e
800D8E80	lh     v1, $41c0(v1)
800D8E84	sll    v0, v0, $06
800D8E88	sll    v1, v1, $04
800D8E8C	addu   v0, v0, v1
800D8E90	lui    at, $800e
800D8E94	addiu  at, at, $0752
800D8E98	addu   at, at, t7
800D8E9C	lbu    v1, $0000(at)
800D8EA0	addu   v0, v0, t2
800D8EA4	ori    v1, v1, $003f
800D8EA8	sb     v1, $0006(v0)
800D8EAC	lui    v0, $800e
800D8EB0	lh     v0, $1024(v0)
800D8EB4	lui    t0, $800e
800D8EB8	lh     t0, $41c0(t0)
800D8EBC	sll    a1, v0, $01
800D8EC0	addu   a1, a1, v0
800D8EC4	sll    a1, a1, $06
800D8EC8	sll    a3, t0, $04
800D8ECC	addu   a2, a1, a3
800D8ED0	addu   a2, a2, t2
800D8ED4	sll    a0, v0, $03
800D8ED8	subu   a0, a0, v0
800D8EDC	sll    a0, a0, $02
800D8EE0	addu   a0, a0, t5
800D8EE4	addu   a0, a0, t6
800D8EE8	addiu  t0, t0, $0001
800D8EEC	addu   a3, a3, t2
800D8EF0	addu   a1, a1, a3
800D8EF4	lw     v1, $0000(a2)
800D8EF8	lw     v0, $0000(a0)
800D8EFC	and    v1, v1, t4
800D8F00	and    v0, v0, t3
800D8F04	or     v1, v1, v0
800D8F08	sw     v1, $0000(a2)
800D8F0C	lw     v0, $0000(a0)
800D8F10	and    a1, a1, t3
800D8F14	lui    at, $800e
800D8F18	sh     t0, $41c0(at)
800D8F1C	and    v0, v0, t4
800D8F20	or     v0, v0, a1
800D8F24	j      Ld91f0 [$800d91f0]
800D8F28	sw     v0, $0000(a0)

Ld8f2c:	; 800D8F2C
800D8F2C	lui    at, $800e
800D8F30	addiu  at, at, $0754
800D8F34	addu   at, at, t7
800D8F38	lh     v0, $0000(at)
800D8F3C	nop
800D8F40	beq    v0, zero, Ld8f50 [$800d8f50]
800D8F44	addu   v1, v0, zero
800D8F48	j      Ld8f84 [$800d8f84]
800D8F4C	addiu  s1, v1, $ffff (=-$1)

Ld8f50:	; 800D8F50
800D8F50	lui    v0, $6666
800D8F54	lui    at, $800e
800D8F58	addiu  at, at, $074e
800D8F5C	addu   at, at, t7
800D8F60	lh     v1, $0000(at)
800D8F64	ori    v0, v0, $6667
800D8F68	addiu  v1, v1, $0002
800D8F6C	mult   v1, v0
800D8F70	sra    v1, v1, $1f
800D8F74	mfhi   v0
800D8F78	sra    v0, v0, $02
800D8F7C	subu   v0, v0, v1
800D8F80	addiu  s1, v0, $ffff (=-$1)

Ld8f84:	; 800D8F84
800D8F84	lui    t3, $800e
800D8F88	addiu  t3, t3, $3b28
800D8F8C	sll    t0, s5, $10
800D8F90	sra    t0, t0, $10
800D8F94	lui    v0, $800e
800D8F98	lh     v0, $1024(v0)
800D8F9C	lui    v1, $800e
800D8FA0	lh     v1, $41bc(v1)
800D8FA4	sll    a0, v0, $03
800D8FA8	addu   a0, a0, v0
800D8FAC	sll    a0, a0, $06
800D8FB0	sll    v0, v1, $01
800D8FB4	addu   v0, v0, v1
800D8FB8	sll    v0, v0, $03
800D8FBC	addu   a0, a0, v0
800D8FC0	sll    v0, t0, $01
800D8FC4	addu   v0, v0, t0
800D8FC8	sll    a2, v0, $06
800D8FCC	subu   a2, a2, v0
800D8FD0	sll    a2, a2, $01
800D8FD4	lui    at, $800e
800D8FD8	addiu  at, at, $0748
800D8FDC	addu   at, at, a2
800D8FE0	lhu    v0, $0000(at)
800D8FE4	addu   a0, a0, t3
800D8FE8	addiu  v0, v0, $0002
800D8FEC	sh     v0, $0008(a0)
800D8FF0	sll    v0, s1, $10
800D8FF4	sra    v0, v0, $10
800D8FF8	sll    a1, v0, $02
800D8FFC	addu   a1, a1, v0
800D9000	lui    at, $800e
800D9004	addiu  at, at, $074a
800D9008	addu   at, at, a2
800D900C	lhu    v0, $0000(at)
800D9010	sll    a1, a1, $01
800D9014	addu   v0, v0, a1
800D9018	addiu  v0, v0, $000a
800D901C	sh     v0, $000a(a0)
800D9020	lui    at, $800e
800D9024	addiu  at, at, $074c
800D9028	addu   at, at, a2
800D902C	lhu    v0, $0000(at)
800D9030	lui    at, $800e
800D9034	addiu  at, at, $0748
800D9038	addu   at, at, a2
800D903C	lhu    v1, $0000(at)
800D9040	addiu  v0, v0, $fffe (=-$2)
800D9044	addu   v1, v1, v0
800D9048	sh     v1, $000c(a0)
800D904C	lui    at, $800e
800D9050	addiu  at, at, $074a
800D9054	addu   at, at, a2
800D9058	lhu    v0, $0000(at)
800D905C	lui    t2, $00ff
800D9060	addu   v0, v0, a1
800D9064	addiu  v0, v0, $000a
800D9068	sh     v0, $000e(a0)
800D906C	lui    at, $800e
800D9070	addiu  at, at, $074c
800D9074	addu   at, at, a2
800D9078	lhu    v0, $0000(at)
800D907C	lui    at, $800e
800D9080	addiu  at, at, $0748
800D9084	addu   at, at, a2
800D9088	lhu    v1, $0000(at)
800D908C	addiu  v0, v0, $fffe (=-$2)
800D9090	addu   v1, v1, v0
800D9094	sh     v1, $0010(a0)
800D9098	lui    at, $800e
800D909C	addiu  at, at, $074a
800D90A0	addu   at, at, a2
800D90A4	lhu    v0, $0000(at)
800D90A8	ori    t2, t2, $ffff
800D90AC	addu   v0, v0, a1
800D90B0	sh     v0, $0012(a0)
800D90B4	lui    at, $800e
800D90B8	addiu  at, at, $0750
800D90BC	addu   at, at, a2
800D90C0	lbu    v0, $0000(at)
800D90C4	lui    a3, $800e
800D90C8	addiu  a3, a3, $41c8
800D90CC	srl    v0, v0, $01
800D90D0	ori    v0, v0, $003f
800D90D4	sb     v0, $0004(a0)
800D90D8	lui    v0, $800e
800D90DC	lh     v0, $1024(v0)
800D90E0	lui    a0, $800e
800D90E4	lh     a0, $41bc(a0)
800D90E8	sll    v1, v0, $03
800D90EC	addu   v1, v1, v0
800D90F0	sll    v1, v1, $06
800D90F4	sll    v0, a0, $01
800D90F8	addu   v0, v0, a0
800D90FC	sll    v0, v0, $03
800D9100	addu   v1, v1, v0
800D9104	lui    at, $800e
800D9108	addiu  at, at, $0751
800D910C	addu   at, at, a2
800D9110	lbu    v0, $0000(at)
800D9114	addu   v1, v1, t3
800D9118	sll    v0, v0, $02
800D911C	ori    v0, v0, $007f
800D9120	sb     v0, $0005(v1)
800D9124	lui    v0, $800e
800D9128	lh     v0, $1024(v0)
800D912C	lui    a0, $800e
800D9130	lh     a0, $41bc(a0)
800D9134	sll    v1, v0, $03
800D9138	addu   v1, v1, v0
800D913C	sll    v1, v1, $06
800D9140	sll    v0, a0, $01
800D9144	addu   v0, v0, a0
800D9148	sll    v0, v0, $03
800D914C	addu   v1, v1, v0
800D9150	lui    at, $800e
800D9154	addiu  at, at, $0752
800D9158	addu   at, at, a2
800D915C	lbu    v0, $0000(at)
800D9160	addu   v1, v1, t3
800D9164	ori    v0, v0, $003f
800D9168	sb     v0, $0006(v1)
800D916C	lui    v1, $800e
800D9170	lh     v1, $1024(v1)
800D9174	lui    t1, $800e
800D9178	lh     t1, $41bc(t1)
800D917C	sll    v0, v1, $03
800D9180	addu   a1, v0, v1
800D9184	sll    a1, a1, $06
800D9188	sll    a0, t1, $01
800D918C	addu   a0, a0, t1
800D9190	sll    a0, a0, $03
800D9194	addu   a2, a1, a0
800D9198	addu   a2, a2, t3
800D919C	subu   v0, v0, v1
800D91A0	addu   t0, t0, v0
800D91A4	sll    t0, t0, $02
800D91A8	addu   t0, t0, a3
800D91AC	lui    a3, $ff00
800D91B0	addiu  t1, t1, $0001
800D91B4	addu   a0, a0, t3
800D91B8	addu   a1, a1, a0
800D91BC	lw     v1, $0000(a2)
800D91C0	lw     v0, $0000(t0)
800D91C4	and    v1, v1, a3
800D91C8	and    v0, v0, t2
800D91CC	or     v1, v1, v0
800D91D0	sw     v1, $0000(a2)
800D91D4	lw     v0, $0000(t0)
800D91D8	and    a1, a1, t2
800D91DC	and    v0, v0, a3
800D91E0	or     v0, v0, a1
800D91E4	sw     v0, $0000(t0)
800D91E8	lui    at, $800e
800D91EC	sh     t1, $41bc(at)

Ld91f0:	; 800D91F0
800D91F0	lui    a3, $800e
800D91F4	addiu  a3, a3, $3b28
800D91F8	sll    a1, s5, $10
800D91FC	sra    a1, a1, $10
800D9200	lui    v0, $800e
800D9204	lh     v0, $1024(v0)
800D9208	lui    v1, $800e
800D920C	lh     v1, $41bc(v1)
800D9210	sll    a0, v0, $03
800D9214	addu   a0, a0, v0
800D9218	sll    a0, a0, $06
800D921C	sll    v0, v1, $01
800D9220	addu   v0, v0, v1
800D9224	sll    v0, v0, $03
800D9228	addu   a0, a0, v0
800D922C	sll    v1, a1, $01
800D9230	addu   v1, v1, a1
800D9234	sll    v0, v1, $06
800D9238	subu   v0, v0, v1
800D923C	sll    a2, v0, $01
800D9240	lui    at, $800e
800D9244	addiu  at, at, $0748
800D9248	addu   at, at, a2
800D924C	lhu    v0, $0000(at)
800D9250	addu   a0, a0, a3
800D9254	sh     v0, $0008(a0)
800D9258	lui    at, $800e
800D925C	addiu  at, at, $074a
800D9260	addu   at, at, a2
800D9264	lhu    v0, $0000(at)
800D9268	lui    at, $800e
800D926C	addiu  at, at, $074e
800D9270	addu   at, at, a2
800D9274	lhu    v1, $0000(at)
800D9278	nop
800D927C	addu   v0, v0, v1
800D9280	sh     v0, $000a(a0)
800D9284	lui    at, $800e
800D9288	addiu  at, at, $0748
800D928C	addu   at, at, a2
800D9290	lhu    v0, $0000(at)
800D9294	lui    at, $800e
800D9298	addiu  at, at, $074c
800D929C	addu   at, at, a2
800D92A0	lhu    v1, $0000(at)
800D92A4	nop
800D92A8	addu   v0, v0, v1
800D92AC	sh     v0, $000c(a0)
800D92B0	lui    at, $800e
800D92B4	addiu  at, at, $074a
800D92B8	addu   at, at, a2
800D92BC	lhu    v0, $0000(at)
800D92C0	lui    at, $800e
800D92C4	addiu  at, at, $074e
800D92C8	addu   at, at, a2
800D92CC	lhu    v1, $0000(at)
800D92D0	nop
800D92D4	addu   v0, v0, v1
800D92D8	sh     v0, $000e(a0)
800D92DC	lui    at, $800e
800D92E0	addiu  at, at, $0748
800D92E4	addu   at, at, a2
800D92E8	lhu    v0, $0000(at)
800D92EC	lui    at, $800e
800D92F0	addiu  at, at, $074c
800D92F4	addu   at, at, a2
800D92F8	lhu    v1, $0000(at)
800D92FC	nop
800D9300	addu   v0, v0, v1
800D9304	sh     v0, $0010(a0)
800D9308	lui    at, $800e
800D930C	addiu  at, at, $074a
800D9310	addu   at, at, a2
800D9314	lhu    v0, $0000(at)
800D9318	lui    v1, $8007
800D931C	lbu    v1, $1c08(v1)
800D9320	nop
800D9324	bne    a1, v1, Ld93d8 [$800d93d8]
800D9328	sh     v0, $0012(a0)
800D932C	lui    at, $800e
800D9330	addiu  at, at, $0750
800D9334	addu   at, at, a2
800D9338	lbu    v0, $0000(at)
800D933C	nop
800D9340	srl    v0, v0, $01
800D9344	sb     v0, $0004(a0)
800D9348	lui    v0, $800e
800D934C	lh     v0, $1024(v0)
800D9350	lui    a0, $800e
800D9354	lh     a0, $41bc(a0)
800D9358	sll    v1, v0, $03
800D935C	addu   v1, v1, v0
800D9360	sll    v1, v1, $06
800D9364	sll    v0, a0, $01
800D9368	addu   v0, v0, a0
800D936C	sll    v0, v0, $03
800D9370	addu   v1, v1, v0
800D9374	lui    at, $800e
800D9378	addiu  at, at, $0751
800D937C	addu   at, at, a2
800D9380	lbu    v0, $0000(at)
800D9384	addu   v1, v1, a3
800D9388	srl    v0, v0, $01
800D938C	sb     v0, $0005(v1)
800D9390	lui    v0, $800e
800D9394	lh     v0, $1024(v0)
800D9398	lui    a0, $800e
800D939C	lh     a0, $41bc(a0)
800D93A0	sll    v1, v0, $03
800D93A4	addu   v1, v1, v0
800D93A8	sll    v1, v1, $06
800D93AC	sll    v0, a0, $01
800D93B0	addu   v0, v0, a0
800D93B4	sll    v0, v0, $03
800D93B8	addu   v1, v1, v0
800D93BC	lui    at, $800e
800D93C0	addiu  at, at, $0752
800D93C4	addu   at, at, a2
800D93C8	lbu    v0, $0000(at)
800D93CC	addu   v1, v1, a3
800D93D0	j      Ld9474 [$800d9474]
800D93D4	srl    v0, v0, $01

Ld93d8:	; 800D93D8
800D93D8	lui    at, $800e
800D93DC	addiu  at, at, $0750
800D93E0	addu   at, at, a2
800D93E4	lbu    v0, $0000(at)
800D93E8	nop
800D93EC	sb     v0, $0004(a0)
800D93F0	lui    v0, $800e
800D93F4	lh     v0, $1024(v0)
800D93F8	lui    a0, $800e
800D93FC	lh     a0, $41bc(a0)
800D9400	sll    v1, v0, $03
800D9404	addu   v1, v1, v0
800D9408	sll    v1, v1, $06
800D940C	sll    v0, a0, $01
800D9410	addu   v0, v0, a0
800D9414	sll    v0, v0, $03
800D9418	addu   v1, v1, v0
800D941C	lui    at, $800e
800D9420	addiu  at, at, $0751
800D9424	addu   at, at, a2
800D9428	lbu    v0, $0000(at)
800D942C	addu   v1, v1, a3
800D9430	sb     v0, $0005(v1)
800D9434	lui    v0, $800e
800D9438	lh     v0, $1024(v0)
800D943C	lui    a0, $800e
800D9440	lh     a0, $41bc(a0)
800D9444	sll    v1, v0, $03
800D9448	addu   v1, v1, v0
800D944C	sll    v1, v1, $06
800D9450	sll    v0, a0, $01
800D9454	addu   v0, v0, a0
800D9458	sll    v0, v0, $03
800D945C	addu   v1, v1, v0
800D9460	lui    at, $800e
800D9464	addiu  at, at, $0752
800D9468	addu   at, at, a2
800D946C	lbu    v0, $0000(at)
800D9470	addu   v1, v1, a3

Ld9474:	; 800D9474
800D9474	sb     v0, $0006(v1)
800D9478	lui    t2, $00ff
800D947C	ori    t2, t2, $ffff
800D9480	lui    t4, $800e
800D9484	addiu  t4, t4, $3b28
800D9488	sll    t1, s5, $10
800D948C	sra    t1, t1, $10
800D9490	lui    v1, $800e
800D9494	addiu  v1, v1, $41c8
800D9498	lui    t0, $ff00
800D949C	lui    v0, $800e
800D94A0	lh     v0, $1024(v0)
800D94A4	lui    t3, $800e
800D94A8	lh     t3, $41bc(t3)
800D94AC	sll    a1, v0, $03
800D94B0	addu   a3, a1, v0
800D94B4	sll    a3, a3, $06
800D94B8	sll    a0, t3, $01
800D94BC	addu   a0, a0, t3
800D94C0	sll    a0, a0, $03
800D94C4	addu   a2, a3, a0
800D94C8	addu   a2, a2, t4
800D94CC	subu   a1, a1, v0
800D94D0	addu   a1, t1, a1
800D94D4	sll    a1, a1, $02
800D94D8	addu   a1, a1, v1
800D94DC	addu   a0, a0, t4
800D94E0	addu   a0, a3, a0
800D94E4	and    a0, a0, t2
800D94E8	addiu  t3, t3, $0001
800D94EC	lw     v1, $0000(a2)
800D94F0	lw     v0, $0000(a1)
800D94F4	and    v1, v1, t0
800D94F8	and    v0, v0, t2
800D94FC	or     v1, v1, v0
800D9500	sw     v1, $0000(a2)
800D9504	sll    v1, t3, $10
800D9508	lw     v0, $0000(a1)
800D950C	sra    v1, v1, $10
800D9510	and    v0, v0, t0
800D9514	or     v0, v0, a0
800D9518	sw     v0, $0000(a1)
800D951C	sll    v0, v1, $01
800D9520	addu   v0, v0, v1
800D9524	sll    v0, v0, $03
800D9528	addu   a3, a3, v0
800D952C	sll    v1, t1, $01
800D9530	addu   v1, v1, t1
800D9534	sll    v0, v1, $06
800D9538	subu   v0, v0, v1
800D953C	sll    a1, v0, $01
800D9540	lui    at, $800e
800D9544	addiu  at, at, $0748
800D9548	addu   at, at, a1
800D954C	lhu    v0, $0000(at)
800D9550	addu   a3, a3, t4
800D9554	sh     v0, $0008(a3)
800D9558	lui    at, $800e
800D955C	addiu  at, at, $074a
800D9560	addu   at, at, a1
800D9564	lhu    v0, $0000(at)
800D9568	lui    at, $800e
800D956C	addiu  at, at, $074e
800D9570	addu   at, at, a1
800D9574	lhu    v1, $0000(at)
800D9578	nop
800D957C	addu   v0, v0, v1
800D9580	sh     v0, $000a(a3)
800D9584	lui    at, $800e
800D9588	addiu  at, at, $0748
800D958C	addu   at, at, a1
800D9590	lhu    v0, $0000(at)
800D9594	nop
800D9598	sh     v0, $000c(a3)
800D959C	lui    at, $800e
800D95A0	addiu  at, at, $074a
800D95A4	addu   at, at, a1
800D95A8	lhu    v0, $0000(at)
800D95AC	nop
800D95B0	sh     v0, $000e(a3)
800D95B4	lui    at, $800e
800D95B8	addiu  at, at, $0748
800D95BC	addu   at, at, a1
800D95C0	lhu    v0, $0000(at)
800D95C4	lui    at, $800e
800D95C8	addiu  at, at, $074c
800D95CC	addu   at, at, a1
800D95D0	lhu    v1, $0000(at)
800D95D4	nop
800D95D8	addu   v0, v0, v1
800D95DC	sh     v0, $0010(a3)
800D95E0	lui    at, $800e
800D95E4	addiu  at, at, $074a
800D95E8	addu   at, at, a1
800D95EC	lhu    v0, $0000(at)
800D95F0	lui    v1, $8007
800D95F4	lbu    v1, $1c08(v1)
800D95F8	lui    at, $800e
800D95FC	sh     t3, $41bc(at)
800D9600	bne    t1, v1, Ld96c0 [$800d96c0]
800D9604	sh     v0, $0012(a3)
800D9608	lui    at, $800e
800D960C	addiu  at, at, $0750
800D9610	addu   at, at, a1
800D9614	lbu    v0, $0000(at)
800D9618	nop
800D961C	sll    v0, v0, $02
800D9620	ori    v0, v0, $007f
800D9624	sb     v0, $0004(a3)
800D9628	lui    v0, $800e
800D962C	lh     v0, $1024(v0)
800D9630	lui    a0, $800e
800D9634	lh     a0, $41bc(a0)
800D9638	sll    v1, v0, $03
800D963C	addu   v1, v1, v0
800D9640	sll    v1, v1, $06
800D9644	sll    v0, a0, $01
800D9648	addu   v0, v0, a0
800D964C	sll    v0, v0, $03
800D9650	addu   v1, v1, v0
800D9654	lui    at, $800e
800D9658	addiu  at, at, $0751
800D965C	addu   at, at, a1
800D9660	lbu    v0, $0000(at)
800D9664	addu   v1, v1, t4
800D9668	sll    v0, v0, $02
800D966C	ori    v0, v0, $007f
800D9670	sb     v0, $0005(v1)
800D9674	lui    v0, $800e
800D9678	lh     v0, $1024(v0)
800D967C	lui    a0, $800e
800D9680	lh     a0, $41bc(a0)
800D9684	sll    v1, v0, $03
800D9688	addu   v1, v1, v0
800D968C	sll    v1, v1, $06
800D9690	sll    v0, a0, $01
800D9694	addu   v0, v0, a0
800D9698	sll    v0, v0, $03
800D969C	addu   v1, v1, v0
800D96A0	lui    at, $800e
800D96A4	addiu  at, at, $0752
800D96A8	addu   at, at, a1
800D96AC	lbu    v0, $0000(at)
800D96B0	addu   v1, v1, t4
800D96B4	sll    v0, v0, $02
800D96B8	j      Ld9774 [$800d9774]
800D96BC	ori    v0, v0, $007f

Ld96c0:	; 800D96C0
800D96C0	lui    at, $800e
800D96C4	addiu  at, at, $0750
800D96C8	addu   at, at, a1
800D96CC	lbu    v0, $0000(at)
800D96D0	nop
800D96D4	sll    v0, v0, $01
800D96D8	ori    v0, v0, $003f
800D96DC	sb     v0, $0004(a3)
800D96E0	lui    v0, $800e
800D96E4	lh     v0, $1024(v0)
800D96E8	lui    a0, $800e
800D96EC	lh     a0, $41bc(a0)
800D96F0	sll    v1, v0, $03
800D96F4	addu   v1, v1, v0
800D96F8	sll    v1, v1, $06
800D96FC	sll    v0, a0, $01
800D9700	addu   v0, v0, a0
800D9704	sll    v0, v0, $03
800D9708	addu   v1, v1, v0
800D970C	lui    at, $800e
800D9710	addiu  at, at, $0751
800D9714	addu   at, at, a1
800D9718	lbu    v0, $0000(at)
800D971C	addu   v1, v1, t4
800D9720	sll    v0, v0, $01
800D9724	ori    v0, v0, $003f
800D9728	sb     v0, $0005(v1)
800D972C	lui    v0, $800e
800D9730	lh     v0, $1024(v0)
800D9734	lui    a0, $800e
800D9738	lh     a0, $41bc(a0)
800D973C	sll    v1, v0, $03
800D9740	addu   v1, v1, v0
800D9744	sll    v1, v1, $06
800D9748	sll    v0, a0, $01
800D974C	addu   v0, v0, a0
800D9750	sll    v0, v0, $03
800D9754	addu   v1, v1, v0
800D9758	lui    at, $800e
800D975C	addiu  at, at, $0752
800D9760	addu   at, at, a1
800D9764	lbu    v0, $0000(at)
800D9768	addu   v1, v1, t4
800D976C	sll    v0, v0, $01
800D9770	ori    v0, v0, $003f

Ld9774:	; 800D9774
800D9774	sb     v0, $0006(v1)
800D9778	lui    t3, $00ff
800D977C	ori    t3, t3, $ffff
800D9780	lui    t5, $800e
800D9784	addiu  t5, t5, $3b28
800D9788	sll    t2, s5, $10
800D978C	sra    t2, t2, $10
800D9790	lui    v0, $800e
800D9794	addiu  v0, v0, $41c8
800D9798	lui    t0, $ff00
800D979C	lui    t1, $800e
800D97A0	lh     t1, $1024(t1)
800D97A4	lui    t4, $800e
800D97A8	lh     t4, $41bc(t4)
800D97AC	sll    a0, t1, $03
800D97B0	addu   a2, a0, t1
800D97B4	sll    a2, a2, $06
800D97B8	sll    a1, t4, $01
800D97BC	addu   a1, a1, t4
800D97C0	sll    a1, a1, $03
800D97C4	addu   a3, a2, a1
800D97C8	addu   a3, a3, t5
800D97CC	subu   a0, a0, t1
800D97D0	addu   a0, t2, a0
800D97D4	sll    a0, a0, $02
800D97D8	addu   a0, a0, v0
800D97DC	addu   a1, a1, t5
800D97E0	addu   a2, a2, a1
800D97E4	and    a2, a2, t3
800D97E8	lw     v1, $0000(a3)
800D97EC	lw     v0, $0000(a0)
800D97F0	and    v1, v1, t0
800D97F4	and    v0, v0, t3
800D97F8	or     v1, v1, v0
800D97FC	sw     v1, $0000(a3)
800D9800	sll    v1, t2, $01
800D9804	lw     v0, $0000(a0)
800D9808	addu   v1, v1, t2
800D980C	and    v0, v0, t0
800D9810	or     v0, v0, a2
800D9814	lui    a2, $800e
800D9818	addiu  a2, a2, $3fa8
800D981C	sw     v0, $0000(a0)
800D9820	sll    a0, t1, $01
800D9824	addu   a0, a0, t1
800D9828	lui    v0, $800e
800D982C	lh     v0, $41c0(v0)
800D9830	sll    a0, a0, $06
800D9834	sll    v0, v0, $04
800D9838	addu   a0, a0, v0
800D983C	sll    v0, v1, $06
800D9840	subu   v0, v0, v1
800D9844	sll    a1, v0, $01
800D9848	lui    at, $800e
800D984C	addiu  at, at, $0748
800D9850	addu   at, at, a1
800D9854	lhu    v0, $0000(at)
800D9858	lui    v1, $8007
800D985C	lbu    v1, $1c08(v1)
800D9860	addu   a0, a0, a2
800D9864	sh     v0, $0008(a0)
800D9868	lui    at, $800e
800D986C	addiu  at, at, $074a
800D9870	addu   at, at, a1
800D9874	lhu    v0, $0000(at)
800D9878	nop
800D987C	sh     v0, $000a(a0)
800D9880	lui    at, $800e
800D9884	addiu  at, at, $074c
800D9888	addu   at, at, a1
800D988C	lhu    v0, $0000(at)
800D9890	nop
800D9894	sh     v0, $000c(a0)
800D9898	lui    at, $800e
800D989C	addiu  at, at, $074e
800D98A0	addu   at, at, a1
800D98A4	lhu    v0, $0000(at)
800D98A8	addiu  t4, t4, $0001
800D98AC	lui    at, $800e
800D98B0	sh     t4, $41bc(at)
800D98B4	bne    t2, v1, Ld9960 [$800d9960]
800D98B8	sh     v0, $000e(a0)
800D98BC	lui    at, $800e
800D98C0	addiu  at, at, $0750
800D98C4	addu   at, at, a1
800D98C8	lbu    v0, $0000(at)
800D98CC	nop
800D98D0	sll    v0, v0, $01
800D98D4	sb     v0, $0004(a0)
800D98D8	lui    v1, $800e
800D98DC	lh     v1, $1024(v1)
800D98E0	nop
800D98E4	sll    v0, v1, $01
800D98E8	addu   v0, v0, v1
800D98EC	lui    v1, $800e
800D98F0	lh     v1, $41c0(v1)
800D98F4	sll    v0, v0, $06
800D98F8	sll    v1, v1, $04
800D98FC	addu   v0, v0, v1
800D9900	lui    at, $800e
800D9904	addiu  at, at, $0751
800D9908	addu   at, at, a1
800D990C	lbu    v1, $0000(at)
800D9910	addu   v0, v0, a2
800D9914	sll    v1, v1, $01
800D9918	sb     v1, $0005(v0)
800D991C	lui    v1, $800e
800D9920	lh     v1, $1024(v1)
800D9924	nop
800D9928	sll    v0, v1, $01
800D992C	addu   v0, v0, v1
800D9930	lui    v1, $800e
800D9934	lh     v1, $41c0(v1)
800D9938	sll    v0, v0, $06
800D993C	sll    v1, v1, $04
800D9940	addu   v0, v0, v1
800D9944	lui    at, $800e
800D9948	addiu  at, at, $0752
800D994C	addu   at, at, a1
800D9950	lbu    v1, $0000(at)
800D9954	addu   v0, v0, a2
800D9958	j      Ld99f4 [$800d99f4]
800D995C	sll    v1, v1, $01

Ld9960:	; 800D9960
800D9960	lui    at, $800e
800D9964	addiu  at, at, $0750
800D9968	addu   at, at, a1
800D996C	lbu    v0, $0000(at)
800D9970	nop
800D9974	sb     v0, $0004(a0)
800D9978	lui    v1, $800e
800D997C	lh     v1, $1024(v1)
800D9980	nop
800D9984	sll    v0, v1, $01
800D9988	addu   v0, v0, v1
800D998C	lui    v1, $800e
800D9990	lh     v1, $41c0(v1)
800D9994	sll    v0, v0, $06
800D9998	sll    v1, v1, $04
800D999C	addu   v0, v0, v1
800D99A0	lui    at, $800e
800D99A4	addiu  at, at, $0751
800D99A8	addu   at, at, a1
800D99AC	lbu    v1, $0000(at)
800D99B0	addu   v0, v0, a2
800D99B4	sb     v1, $0005(v0)
800D99B8	lui    v1, $800e
800D99BC	lh     v1, $1024(v1)
800D99C0	nop
800D99C4	sll    v0, v1, $01
800D99C8	addu   v0, v0, v1
800D99CC	lui    v1, $800e
800D99D0	lh     v1, $41c0(v1)
800D99D4	sll    v0, v0, $06
800D99D8	sll    v1, v1, $04
800D99DC	addu   v0, v0, v1
800D99E0	lui    at, $800e
800D99E4	addiu  at, at, $0752
800D99E8	addu   at, at, a1
800D99EC	lbu    v1, $0000(at)
800D99F0	addu   v0, v0, a2

Ld99f4:	; 800D99F4
800D99F4	sb     v1, $0006(v0)
800D99F8	lui    v1, $800e
800D99FC	lh     v1, $4210(v1)
800D9A00	ori    v0, zero, $0002
800D9A04	beq    v1, v0, Ld9a64 [$800d9a64]
800D9A08	slti   v0, v1, $0003
800D9A0C	beq    v0, zero, Ld9b38 [$800d9b38]
800D9A10	ori    v0, zero, $0001
800D9A14	bne    v1, v0, Ld9b3c [$800d9b3c]
800D9A18	lui    t2, $00ff
800D9A1C	lui    t3, $800e
800D9A20	addiu  t3, t3, $3fa8
800D9A24	lui    v1, $800e
800D9A28	lh     v1, $1024(v1)
800D9A2C	ori    t2, t2, $ffff
800D9A30	sll    v0, v1, $01
800D9A34	addu   v0, v0, v1
800D9A38	lui    v1, $800e
800D9A3C	lh     v1, $41c0(v1)
800D9A40	sll    v0, v0, $06
800D9A44	sll    v1, v1, $04
800D9A48	addu   v0, v0, v1
800D9A4C	addu   v0, v0, t3
800D9A50	lbu    v1, $0007(v0)
800D9A54	lui    t1, $800e
800D9A58	addiu  t1, t1, $41c8
800D9A5C	j      Ld9aac [$800d9aac]
800D9A60	ori    v1, v1, $0002

Ld9a64:	; 800D9A64
800D9A64	lui    t3, $800e
800D9A68	addiu  t3, t3, $3fa8
800D9A6C	lui    t2, $00ff
800D9A70	lui    v1, $800e
800D9A74	lh     v1, $1024(v1)
800D9A78	ori    t2, t2, $ffff
800D9A7C	sll    v0, v1, $01
800D9A80	addu   v0, v0, v1
800D9A84	lui    v1, $800e
800D9A88	lh     v1, $41c0(v1)
800D9A8C	sll    v0, v0, $06
800D9A90	sll    v1, v1, $04
800D9A94	addu   v0, v0, v1
800D9A98	addu   v0, v0, t3
800D9A9C	lbu    v1, $0007(v0)
800D9AA0	lui    t1, $800e
800D9AA4	addiu  t1, t1, $41c8
800D9AA8	andi   v1, v1, $00fd

Ld9aac:	; 800D9AAC
800D9AAC	sb     v1, $0007(v0)
800D9AB0	sll    v0, s5, $10
800D9AB4	sra    v0, v0, $0e
800D9AB8	lui    v1, $800e
800D9ABC	lh     v1, $1024(v1)
800D9AC0	lui    t0, $800e
800D9AC4	lh     t0, $41c0(t0)
800D9AC8	sll    a1, v1, $01
800D9ACC	addu   a1, a1, v1
800D9AD0	sll    a1, a1, $06
800D9AD4	sll    a3, t0, $04
800D9AD8	addu   a2, a1, a3
800D9ADC	addu   a2, a2, t3
800D9AE0	sll    a0, v1, $03
800D9AE4	subu   a0, a0, v1
800D9AE8	sll    a0, a0, $02
800D9AEC	addu   a0, a0, v0
800D9AF0	addu   a0, a0, t1
800D9AF4	lui    t1, $ff00
800D9AF8	addiu  t0, t0, $0001
800D9AFC	addu   a3, a3, t3
800D9B00	addu   a1, a1, a3
800D9B04	lw     v1, $0000(a2)
800D9B08	lw     v0, $0000(a0)
800D9B0C	and    v1, v1, t1
800D9B10	and    v0, v0, t2
800D9B14	or     v1, v1, v0
800D9B18	sw     v1, $0000(a2)
800D9B1C	lw     v0, $0000(a0)
800D9B20	and    a1, a1, t2
800D9B24	lui    at, $800e
800D9B28	sh     t0, $41c0(at)
800D9B2C	and    v0, v0, t1
800D9B30	or     v0, v0, a1
800D9B34	sw     v0, $0000(a0)

Ld9b38:	; 800D9B38
800D9B38	lui    t2, $00ff

Ld9b3c:	; 800D9B3C
800D9B3C	ori    t2, t2, $ffff
800D9B40	lui    t3, $800e
800D9B44	addiu  t3, t3, $4128
800D9B48	sll    v0, s5, $10
800D9B4C	lui    t1, $800e
800D9B50	addiu  t1, t1, $41c8
800D9B54	sra    v0, v0, $0e
800D9B58	lui    v1, $800e
800D9B5C	lh     v1, $1024(v1)
800D9B60	lui    t0, $800e
800D9B64	lh     t0, $41c4(t0)
800D9B68	sll    a0, v1, $03
800D9B6C	addu   a2, a0, v1
800D9B70	sll    a2, a2, $03
800D9B74	sll    a1, t0, $01
800D9B78	addu   a1, a1, t0
800D9B7C	sll    a1, a1, $02
800D9B80	addu   a3, a2, a1
800D9B84	addu   a3, a3, t3
800D9B88	subu   a0, a0, v1
800D9B8C	sll    a0, a0, $02
800D9B90	addu   a0, a0, v0
800D9B94	addu   a0, a0, t1
800D9B98	lui    t1, $ff00
800D9B9C	addiu  t0, t0, $0001
800D9BA0	addu   a1, a1, t3
800D9BA4	addu   a2, a2, a1
800D9BA8	lw     v1, $0000(a3)
800D9BAC	lw     v0, $0000(a0)
800D9BB0	and    v1, v1, t1
800D9BB4	and    v0, v0, t2
800D9BB8	or     v1, v1, v0
800D9BBC	sw     v1, $0000(a3)
800D9BC0	lw     v0, $0000(a0)
800D9BC4	and    a2, a2, t2
800D9BC8	lui    at, $800e
800D9BCC	sh     t0, $41c4(at)
800D9BD0	and    v0, v0, t1
800D9BD4	or     v0, v0, a2
800D9BD8	sw     v0, $0000(a0)

Ld9bdc:	; 800D9BDC
800D9BDC	lw     ra, $0080(sp)
800D9BE0	lw     s5, $007c(sp)
800D9BE4	lw     s4, $0078(sp)
800D9BE8	lw     s3, $0074(sp)
800D9BEC	lw     s2, $0070(sp)
800D9BF0	lw     s1, $006c(sp)
800D9BF4	lw     s0, $0068(sp)
800D9BF8	addiu  sp, sp, $0088
800D9BFC	jr     ra 
800D9C00	nop


funcd9c04:	; 800D9C04
800D9C04	addiu  sp, sp, $fff8 (=-$8)
800D9C08	addu   t2, a2, zero
800D9C0C	lbu    v0, $0000(t2)
800D9C10	lw     t9, $0018(sp)
800D9C14	beq    v0, zero, Ld9ef4 [$800d9ef4]
800D9C18	addu   t3, a3, zero
800D9C1C	sll    a0, a0, $10
800D9C20	sra    a0, a0, $10
800D9C24	sll    v1, a0, $01
800D9C28	addu   v1, v1, a0
800D9C2C	sll    v0, v1, $06
800D9C30	subu   v0, v0, v1
800D9C34	sll    t5, v0, $01
800D9C38	lui    t6, $800e
800D9C3C	addiu  t6, t6, $1028
800D9C40	sll    v0, a1, $10
800D9C44	sra    t8, v0, $10
800D9C48	sll    t7, a0, $02
800D9C4C	lui    t4, $00ff
800D9C50	ori    t4, t4, $ffff

Ld9c54:	; 800D9C54
800D9C54	lui    at, $800e
800D9C58	addiu  at, at, $0748
800D9C5C	addu   at, at, t5
800D9C60	lh     v0, $0000(at)
800D9C64	lui    at, $800e
800D9C68	addiu  at, at, $074c
800D9C6C	addu   at, at, t5
800D9C70	lh     v1, $0000(at)
800D9C74	nop
800D9C78	addu   v0, v0, v1
800D9C7C	addiu  v0, v0, $fff8 (=-$8)
800D9C80	slt    v0, v0, t3
800D9C84	bne    v0, zero, Ld9ef4 [$800d9ef4]
800D9C88	nop
800D9C8C	lui    v0, $800e
800D9C90	lh     v0, $41b8(v0)
800D9C94	nop
800D9C98	slti   v0, v0, $0158
800D9C9C	beq    v0, zero, Ld9ef4 [$800d9ef4]
800D9CA0	nop
800D9CA4	lbu    v0, $0000(t2)
800D9CA8	nop
800D9CAC	addiu  v1, v0, $ffe0 (=-$20)
800D9CB0	sltiu  v0, v1, $0020
800D9CB4	beq    v0, zero, Ld9d38 [$800d9d38]
800D9CB8	sll    v0, v1, $02
800D9CBC	lui    at, $800a
800D9CC0	addiu  at, at, $12e8
800D9CC4	addu   at, at, v0
800D9CC8	lw     v0, $0000(at)
800D9CCC	nop
800D9CD0	jr     v0 
800D9CD4	nop

800D9CD8	j      Ld9d78 [$800d9d78]
800D9CDC	ori    a0, zero, $003f
800D9CE0	j      Ld9d78 [$800d9d78]
800D9CE4	ori    a0, zero, $00d5
800D9CE8	j      Ld9d78 [$800d9d78]
800D9CEC	ori    a0, zero, $00b2
800D9CF0	j      Ld9d78 [$800d9d78]
800D9CF4	ori    a0, zero, $00b3
800D9CF8	j      Ld9d78 [$800d9d78]
800D9CFC	ori    a0, zero, $00d4
800D9D00	j      Ld9d78 [$800d9d78]
800D9D04	ori    a0, zero, $00d0
800D9D08	j      Ld9d78 [$800d9d78]
800D9D0C	ori    a0, zero, $00cf
800D9D10	j      Ld9d78 [$800d9d78]
800D9D14	ori    a0, zero, $00ae
800D9D18	j      Ld9d78 [$800d9d78]
800D9D1C	ori    a0, zero, $00af
800D9D20	j      Ld9d78 [$800d9d78]
800D9D24	ori    a0, zero, $00da
800D9D28	j      Ld9d78 [$800d9d78]
800D9D2C	ori    a0, zero, $00d6
800D9D30	j      Ld9d78 [$800d9d78]
800D9D34	ori    a0, zero, $00d9

Ld9d38:	; 800D9D38
800D9D38	lbu    v1, $0000(t2)
800D9D3C	nop
800D9D40	sltiu  v0, v1, $003a
800D9D44	beq    v0, zero, Ld9d58 [$800d9d58]
800D9D48	sltiu  v0, v1, $0061
800D9D4C	lbu    v0, $0000(t2)
800D9D50	j      Ld9d78 [$800d9d78]
800D9D54	addiu  a0, v0, $0003

Ld9d58:	; 800D9D58
800D9D58	bne    v0, zero, Ld9d6c [$800d9d6c]
800D9D5C	nop
800D9D60	lbu    v0, $0000(t2)
800D9D64	j      Ld9d78 [$800d9d78]
800D9D68	addiu  a0, v0, $0053

Ld9d6c:	; 800D9D6C
800D9D6C	lbu    v0, $0000(t2)
800D9D70	nop
800D9D74	addiu  a0, v0, $0073

Ld9d78:	; 800D9D78
800D9D78	lui    v1, $800e
800D9D7C	lh     v1, $1024(v1)
800D9D80	addiu  t2, t2, $0001
800D9D84	sll    v0, v1, $01
800D9D88	addu   v0, v0, v1
800D9D8C	sll    v0, v0, $02
800D9D90	subu   v0, v0, v1
800D9D94	sll    v0, v0, $02
800D9D98	subu   v0, v0, v1
800D9D9C	lui    v1, $800e
800D9DA0	lh     v1, $41b8(v1)
800D9DA4	sll    v0, v0, $07
800D9DA8	sll    v1, v1, $04
800D9DAC	addu   v0, v0, v1
800D9DB0	addu   v0, v0, t6
800D9DB4	andi   v1, a0, $000f
800D9DB8	sll    v1, v1, $03
800D9DBC	addiu  v1, v1, $ff80 (=-$80)
800D9DC0	sb     v1, $000c(v0)
800D9DC4	lui    v1, $800e
800D9DC8	lh     v1, $1024(v1)
800D9DCC	lui    a3, $ff00
800D9DD0	sll    v0, v1, $01
800D9DD4	addu   v0, v0, v1
800D9DD8	sll    v0, v0, $02
800D9DDC	subu   v0, v0, v1
800D9DE0	sll    v0, v0, $02
800D9DE4	subu   v0, v0, v1
800D9DE8	lui    v1, $800e
800D9DEC	lh     v1, $41b8(v1)
800D9DF0	sll    v0, v0, $07
800D9DF4	sll    v1, v1, $04
800D9DF8	addu   v0, v0, v1
800D9DFC	addu   v0, v0, t6
800D9E00	srl    v1, a0, $01
800D9E04	andi   v1, v1, $0078
800D9E08	addiu  v1, v1, $ff80 (=-$80)
800D9E0C	sb     v1, $000d(v0)
800D9E10	lui    v0, $800e
800D9E14	addiu  v0, v0, $08a8
800D9E18	addu   v0, t5, v0
800D9E1C	addu   v0, v0, t8
800D9E20	lui    v1, $800e
800D9E24	lh     v1, $1024(v1)
800D9E28	lui    t1, $800e
800D9E2C	lh     t1, $41b8(t1)
800D9E30	sll    a1, v1, $01
800D9E34	addu   a1, a1, v1
800D9E38	sll    a1, a1, $02
800D9E3C	subu   a1, a1, v1
800D9E40	sll    a1, a1, $02
800D9E44	subu   a1, a1, v1
800D9E48	sll    a1, a1, $07
800D9E4C	sll    t0, t1, $04
800D9E50	addu   a0, a1, t0
800D9E54	addu   a2, a0, t6
800D9E58	addiu  t1, t1, $0001
800D9E5C	sh     t3, $0008(a2)
800D9E60	sh     t9, $000a(a2)
800D9E64	lbu    v0, $0000(v0)
800D9E68	addu   t0, t0, t6
800D9E6C	sll    v0, v0, $01
800D9E70	lui    at, $800e
800D9E74	addiu  at, at, $4200
800D9E78	addu   at, at, v0
800D9E7C	lhu    v0, $0000(at)
800D9E80	addu   a1, a1, t0
800D9E84	lui    at, $800e
800D9E88	addiu  at, at, $1036
800D9E8C	addu   at, at, a0
800D9E90	sh     v0, $0000(at)
800D9E94	lui    v0, $800e
800D9E98	addiu  v0, v0, $41c8
800D9E9C	sll    a0, v1, $03
800D9EA0	subu   a0, a0, v1
800D9EA4	sll    a0, a0, $02
800D9EA8	addu   a0, a0, t7
800D9EAC	addu   a0, a0, v0
800D9EB0	lw     v1, $0000(a2)
800D9EB4	lw     v0, $0000(a0)
800D9EB8	and    v1, v1, a3
800D9EBC	and    v0, v0, t4
800D9EC0	or     v1, v1, v0
800D9EC4	sw     v1, $0000(a2)
800D9EC8	lw     v0, $0000(a0)
800D9ECC	and    a1, a1, t4
800D9ED0	lui    at, $800e
800D9ED4	sh     t1, $41b8(at)
800D9ED8	and    v0, v0, a3
800D9EDC	or     v0, v0, a1
800D9EE0	sw     v0, $0000(a0)
800D9EE4	lbu    v0, $0000(t2)
800D9EE8	nop
800D9EEC	bne    v0, zero, Ld9c54 [$800d9c54]
800D9EF0	addiu  t3, t3, $0008

Ld9ef4:	; 800D9EF4
800D9EF4	addiu  sp, sp, $0008
800D9EF8	jr     ra 
800D9EFC	nop


funcd9f00:	; 800D9F00
800D9F00	addiu  sp, sp, $ffe0 (=-$20)
800D9F04	sll    a0, a0, $10
800D9F08	sra    a0, a0, $10
800D9F0C	sll    v1, a0, $01
800D9F10	addu   v1, v1, a0
800D9F14	sll    v0, v1, $06
800D9F18	subu   v0, v0, v1
800D9F1C	sw     s1, $0014(sp)
800D9F20	sll    s1, v0, $01
800D9F24	sw     s0, $0010(sp)
800D9F28	lui    s0, $800e
800D9F2C	addiu  s0, s0, $0758
800D9F30	sw     ra, $0018(sp)
800D9F34	lui    at, $800e
800D9F38	addiu  at, at, $0754
800D9F3C	addu   at, at, s1
800D9F40	lh     v0, $0000(at)
800D9F44	addu   v1, s1, s0
800D9F48	sll    a0, v0, $03
800D9F4C	subu   a0, a0, v0
800D9F50	sll    a0, a0, $01
800D9F54	jal    funcda334 [$800da334]
800D9F58	addu   a0, v1, a0
800D9F5C	lui    a0, $6666
800D9F60	addiu  s0, s0, $fff0 (=-$10)
800D9F64	lui    at, $800e
800D9F68	addiu  at, at, $0754
800D9F6C	addu   at, at, s1
800D9F70	lhu    v0, $0000(at)
800D9F74	addu   s0, s1, s0
800D9F78	addiu  v0, v0, $0001
800D9F7C	sh     v0, $000c(s0)
800D9F80	lui    at, $800e
800D9F84	addiu  at, at, $074e
800D9F88	addu   at, at, s1
800D9F8C	lh     v1, $0000(at)
800D9F90	ori    a0, a0, $6667
800D9F94	addiu  v1, v1, $fff8 (=-$8)
800D9F98	mult   v1, a0
800D9F9C	sra    v1, v1, $1f
800D9FA0	lui    at, $800e
800D9FA4	addiu  at, at, $0754
800D9FA8	addu   at, at, s1
800D9FAC	lh     a0, $0000(at)
800D9FB0	mfhi   v0
800D9FB4	sra    v0, v0, $02
800D9FB8	subu   v0, v0, v1
800D9FBC	slt    v0, v0, a0
800D9FC0	beq    v0, zero, Ld9fd8 [$800d9fd8]
800D9FC4	ori    v0, zero, $0001
800D9FC8	lui    at, $800e
800D9FCC	addiu  at, at, $0754
800D9FD0	addu   at, at, s1
800D9FD4	sh     zero, $0000(at)

Ld9fd8:	; 800D9FD8
800D9FD8	lui    at, $800a
800D9FDC	sb     v0, $d824(at)
800D9FE0	ori    v0, zero, $0001
800D9FE4	lw     ra, $0018(sp)
800D9FE8	lw     s1, $0014(sp)
800D9FEC	lw     s0, $0010(sp)
800D9FF0	addiu  sp, sp, $0020
800D9FF4	jr     ra 
800D9FF8	nop

800D9FFC	addiu  sp, sp, $ffe0 (=-$20)
800DA000	sw     s1, $0014(sp)
800DA004	addu   s1, a2, zero
800DA008	sll    a0, a0, $10
800DA00C	sra    a0, a0, $10
800DA010	sll    v1, a0, $01
800DA014	addu   v1, v1, a0
800DA018	sll    v0, v1, $06
800DA01C	subu   v0, v0, v1
800DA020	sw     s2, $0018(sp)
800DA024	sll    s2, v0, $01
800DA028	sw     s0, $0010(sp)
800DA02C	lui    s0, $800e
800DA030	addiu  s0, s0, $0758
800DA034	sw     ra, $001c(sp)
800DA038	lui    at, $800e
800DA03C	addiu  at, at, $0754
800DA040	addu   at, at, s2
800DA044	lh     v0, $0000(at)
800DA048	addu   v1, s2, s0
800DA04C	sll    a0, v0, $03
800DA050	subu   a0, a0, v0
800DA054	sll    a0, a0, $01
800DA058	jal    funcda334 [$800da334]
800DA05C	addu   a0, v1, a0
800DA060	addiu  v0, s0, $0150
800DA064	addu   v0, s2, v0
800DA068	lui    a0, $6666
800DA06C	lui    at, $800e
800DA070	addiu  at, at, $0754
800DA074	addu   at, at, s2
800DA078	lh     v1, $0000(at)
800DA07C	addiu  s0, s0, $fff0 (=-$10)
800DA080	addu   v0, v0, v1
800DA084	sb     s1, $0000(v0)
800DA088	lui    at, $800e
800DA08C	addiu  at, at, $0754
800DA090	addu   at, at, s2
800DA094	lhu    v0, $0000(at)
800DA098	addu   s0, s2, s0
800DA09C	addiu  v0, v0, $0001
800DA0A0	sh     v0, $000c(s0)
800DA0A4	lui    at, $800e
800DA0A8	addiu  at, at, $074e
800DA0AC	addu   at, at, s2
800DA0B0	lh     v1, $0000(at)
800DA0B4	ori    a0, a0, $6667
800DA0B8	addiu  v1, v1, $fff8 (=-$8)
800DA0BC	mult   v1, a0
800DA0C0	sra    v1, v1, $1f
800DA0C4	lui    at, $800e
800DA0C8	addiu  at, at, $0754
800DA0CC	addu   at, at, s2
800DA0D0	lh     a0, $0000(at)
800DA0D4	mfhi   v0
800DA0D8	sra    v0, v0, $02
800DA0DC	subu   v0, v0, v1
800DA0E0	slt    v0, v0, a0
800DA0E4	beq    v0, zero, Lda0fc [$800da0fc]
800DA0E8	ori    v0, zero, $0001
800DA0EC	lui    at, $800e
800DA0F0	addiu  at, at, $0754
800DA0F4	addu   at, at, s2
800DA0F8	sh     zero, $0000(at)

Lda0fc:	; 800DA0FC
800DA0FC	lui    at, $800a
800DA100	sb     v0, $d824(at)
800DA104	ori    v0, zero, $0001
800DA108	lw     ra, $001c(sp)
800DA10C	lw     s2, $0018(sp)
800DA110	lw     s1, $0014(sp)
800DA114	lw     s0, $0010(sp)
800DA118	addiu  sp, sp, $0020
800DA11C	jr     ra 
800DA120	nop


funcda124:	; 800DA124
800DA124	addiu  sp, sp, $ffe8 (=-$18)
800DA128	sll    a0, a0, $10
800DA12C	sra    a0, a0, $10
800DA130	sll    v0, a0, $01
800DA134	addu   v0, v0, a0
800DA138	sll    v1, v0, $06
800DA13C	subu   v1, v1, v0
800DA140	sll    v1, v1, $01
800DA144	lui    v0, $800e
800DA148	addiu  v0, v0, $0758
800DA14C	addu   v1, v1, v0
800DA150	sll    a1, a1, $10
800DA154	sra    a1, a1, $10
800DA158	sll    a0, a1, $03
800DA15C	subu   a0, a0, a1
800DA160	sll    a0, a0, $01
800DA164	addu   a0, v1, a0
800DA168	sw     ra, $0010(sp)
800DA16C	jal    funcda334 [$800da334]
800DA170	addu   a1, a2, zero
800DA174	ori    v0, zero, $0001
800DA178	lui    at, $800a
800DA17C	sb     v0, $d824(at)
800DA180	ori    v0, zero, $0001
800DA184	lw     ra, $0010(sp)
800DA188	addiu  sp, sp, $0018
800DA18C	jr     ra 
800DA190	nop


funcda194:	; 800DA194
800DA194	sll    a0, a0, $10
800DA198	sra    a0, a0, $10
800DA19C	sll    v1, a0, $01
800DA1A0	addu   v1, v1, a0
800DA1A4	sll    v0, v1, $06
800DA1A8	subu   v0, v0, v1
800DA1AC	sll    v0, v0, $01
800DA1B0	sll    a1, a1, $10
800DA1B4	sra    a1, a1, $10
800DA1B8	lui    v1, $800e
800DA1BC	addiu  v1, v1, $08a8
800DA1C0	addu   v0, v0, v1
800DA1C4	addu   v0, v0, a1
800DA1C8	sb     a2, $0000(v0)
800DA1CC	jr     ra 
800DA1D0	ori    v0, zero, $0001


funcda1d4:	; 800DA1D4
800DA1D4	sll    a0, a0, $10
800DA1D8	sra    a0, a0, $10
800DA1DC	sll    v1, a0, $01
800DA1E0	addu   v1, v1, a0
800DA1E4	sll    v0, v1, $06
800DA1E8	subu   v0, v0, v1
800DA1EC	sll    v0, v0, $01
800DA1F0	lui    at, $800e
800DA1F4	addiu  at, at, $0756
800DA1F8	addu   at, at, v0
800DA1FC	sh     a1, $0000(at)
800DA200	ori    v0, zero, $0001
800DA204	lui    at, $800a
800DA208	sb     v0, $d824(at)
800DA20C	jr     ra 
800DA210	nop


funcda214:	; 800DA214
800DA214	sll    a0, a0, $10
800DA218	sra    a0, a0, $10
800DA21C	sll    v1, a0, $01
800DA220	addu   v1, v1, a0
800DA224	sll    v0, v1, $06
800DA228	subu   v0, v0, v1
800DA22C	sll    v1, v0, $01
800DA230	lui    at, $800e
800DA234	addiu  at, at, $08c0
800DA238	addu   at, at, v1
800DA23C	lbu    v0, $0000(at)
800DA240	nop
800DA244	bne    v0, zero, Lda284 [$800da284]
800DA248	ori    v0, zero, $0001
800DA24C	lui    at, $800e
800DA250	addiu  at, at, $0750
800DA254	addu   at, at, v1
800DA258	sb     a1, $0000(at)
800DA25C	lui    at, $800e
800DA260	addiu  at, at, $0751
800DA264	addu   at, at, v1
800DA268	sb     a2, $0000(at)
800DA26C	lui    at, $800e
800DA270	addiu  at, at, $0752
800DA274	addu   at, at, v1
800DA278	sb     a3, $0000(at)
800DA27C	lui    at, $800a
800DA280	sb     v0, $d824(at)

Lda284:	; 800DA284
800DA284	jr     ra 
800DA288	nop

800DA28C	sll    a0, a0, $10
800DA290	sra    a0, a0, $10
800DA294	sll    v0, a0, $01
800DA298	addu   v0, v0, a0
800DA29C	sll    v1, v0, $06
800DA2A0	subu   v1, v1, v0
800DA2A4	sll    v1, v1, $01
800DA2A8	ori    v0, zero, $0001
800DA2AC	lui    at, $800e
800DA2B0	addiu  at, at, $08c0
800DA2B4	addu   at, at, v1
800DA2B8	sb     v0, $0000(at)
800DA2BC	lui    at, $800a
800DA2C0	sb     v0, $d824(at)
800DA2C4	jr     ra 
800DA2C8	nop


funcda2cc:	; 800DA2CC
800DA2CC	sll    a0, a0, $10
800DA2D0	sra    a0, a0, $10
800DA2D4	sll    v0, a0, $01
800DA2D8	addu   v0, v0, a0
800DA2DC	sll    v1, v0, $06
800DA2E0	subu   v1, v1, v0
800DA2E4	sll    v1, v1, $01
800DA2E8	ori    v0, zero, $0002
800DA2EC	lui    at, $800e
800DA2F0	addiu  at, at, $08c0
800DA2F4	addu   at, at, v1
800DA2F8	sb     v0, $0000(at)
800DA2FC	ori    v0, zero, $0001
800DA300	lui    at, $800a
800DA304	sb     v0, $d824(at)
800DA308	jr     ra 
800DA30C	nop

800DA310	lui    v0, $800e
800DA314	lhu    v0, $4210(v0)
800DA318	nop
800DA31C	addiu  v0, v0, $0001
800DA320	andi   v0, v0, $0003
800DA324	lui    at, $800e
800DA328	sh     v0, $4210(at)
800DA32C	jr     ra 
800DA330	nop


funcda334:	; 800DA334
800DA334	lbu    v0, $0000(a1)
800DA338	nop
800DA33C	beq    v0, zero, Lda360 [$800da360]
800DA340	nop

loopda344:	; 800DA344
800DA344	lbu    v0, $0000(a1)
800DA348	addiu  a1, a1, $0001
800DA34C	sb     v0, $0000(a0)
800DA350	lbu    v0, $0000(a1)
800DA354	nop
800DA358	bne    v0, zero, loopda344 [$800da344]
800DA35C	addiu  a0, a0, $0001

Lda360:	; 800DA360
800DA360	jr     ra 
800DA364	sb     zero, $0000(a0)


funcda368:	; 800DA368
800DA368	lbu    v0, $0000(a0)
800DA36C	nop
800DA370	beq    v0, zero, Lda390 [$800da390]
800DA374	nop
800DA378	addiu  a0, a0, $0001

loopda37c:	; 800DA37C
800DA37C	lbu    v0, $0000(a0)
800DA380	nop
800DA384	bne    v0, zero, loopda37c [$800da37c]
800DA388	addiu  a0, a0, $0001
800DA38C	addiu  a0, a0, $ffff (=-$1)

Lda390:	; 800DA390
800DA390	lbu    v0, $0000(a1)
800DA394	nop
800DA398	beq    v0, zero, Lda3bc [$800da3bc]
800DA39C	nop

loopda3a0:	; 800DA3A0
800DA3A0	lbu    v0, $0000(a1)
800DA3A4	addiu  a1, a1, $0001
800DA3A8	sb     v0, $0000(a0)
800DA3AC	lbu    v0, $0000(a1)
800DA3B0	nop
800DA3B4	bne    v0, zero, loopda3a0 [$800da3a0]
800DA3B8	addiu  a0, a0, $0001

Lda3bc:	; 800DA3BC
800DA3BC	jr     ra 
800DA3C0	sb     zero, $0000(a0)

800DA3C4	lbu    v0, $0000(a0)
800DA3C8	nop
800DA3CC	beq    v0, zero, Lda3e8 [$800da3e8]
800DA3D0	addu   v1, zero, zero

loopda3d4:	; 800DA3D4
800DA3D4	addiu  a0, a0, $0001
800DA3D8	lbu    v0, $0000(a0)
800DA3DC	nop
800DA3E0	bne    v0, zero, loopda3d4 [$800da3d4]
800DA3E4	addiu  v1, v1, $0001

Lda3e8:	; 800DA3E8
800DA3E8	jr     ra 
800DA3EC	addu   v0, v1, zero

800DA3F0	addiu  sp, sp, $fff8 (=-$8)
800DA3F4	beq    a2, zero, Lda418 [$800da418]
800DA3F8	addiu  v1, a2, $ffff (=-$1)
800DA3FC	addiu  a2, zero, $ffff (=-$1)

loopda400:	; 800DA400
800DA400	lbu    v0, $0000(a1)
800DA404	addiu  a1, a1, $0001
800DA408	addiu  v1, v1, $ffff (=-$1)
800DA40C	sb     v0, $0000(a0)
800DA410	bne    v1, a2, loopda400 [$800da400]
800DA414	addiu  a0, a0, $0001

Lda418:	; 800DA418
800DA418	addiu  sp, sp, $0008
800DA41C	jr     ra 
800DA420	nop


funcda424:	; 800DA424
800DA424	andi   a0, a0, $000f
800DA428	sb     zero, $0001(a1)
800DA42C	lui    at, $800e
800DA430	addiu  at, at, $0208
800DA434	addu   at, at, a0
800DA438	lbu    v0, $0000(at)
800DA43C	jr     ra 
800DA440	sb     v0, $0000(a1)


funcda444:	; 800DA444
800DA444	andi   v0, a0, $00f0
800DA448	sra    v0, v0, $04
800DA44C	sb     zero, $0002(a1)
800DA450	lui    at, $800e
800DA454	addiu  at, at, $0208
800DA458	addu   at, at, v0
800DA45C	lbu    v0, $0000(at)
800DA460	andi   a0, a0, $000f
800DA464	sb     v0, $0000(a1)
800DA468	lui    at, $800e
800DA46C	addiu  at, at, $0208
800DA470	addu   at, at, a0
800DA474	lbu    v0, $0000(at)
800DA478	jr     ra 
800DA47C	sb     v0, $0001(a1)


funcda480:	; 800DA480
800DA480	andi   v0, a0, $f000
800DA484	sra    v0, v0, $0c
800DA488	sb     zero, $0004(a1)
800DA48C	lui    at, $800e
800DA490	addiu  at, at, $0208
800DA494	addu   at, at, v0
800DA498	lbu    v0, $0000(at)
800DA49C	nop
800DA4A0	sb     v0, $0000(a1)
800DA4A4	andi   v0, a0, $0f00
800DA4A8	sra    v0, v0, $08
800DA4AC	lui    at, $800e
800DA4B0	addiu  at, at, $0208
800DA4B4	addu   at, at, v0
800DA4B8	lbu    v0, $0000(at)
800DA4BC	nop
800DA4C0	sb     v0, $0001(a1)
800DA4C4	andi   v0, a0, $00f0
800DA4C8	sra    v0, v0, $04
800DA4CC	lui    at, $800e
800DA4D0	addiu  at, at, $0208
800DA4D4	addu   at, at, v0
800DA4D8	lbu    v0, $0000(at)
800DA4DC	andi   a0, a0, $000f
800DA4E0	sb     v0, $0002(a1)
800DA4E4	lui    at, $800e
800DA4E8	addiu  at, at, $0208
800DA4EC	addu   at, at, a0
800DA4F0	lbu    v0, $0000(at)
800DA4F4	jr     ra 
800DA4F8	sb     v0, $0003(a1)

800DA4FC	addu   t1, zero, zero
800DA500	ori    v1, zero, $2710
800DA504	addu   t0, zero, zero
800DA508	lui    t2, $6666
800DA50C	ori    t2, t2, $6667
800DA510	addu   a3, a1, zero

loopda514:	; 800DA514
800DA514	div    a0, v1
800DA518	bne    v1, zero, Lda524 [$800da524]
800DA51C	nop
800DA520	break   $01c00

Lda524:	; 800DA524
800DA524	addiu  at, zero, $ffff (=-$1)
800DA528	bne    v1, at, Lda53c [$800da53c]
800DA52C	lui    at, $8000
800DA530	bne    a0, at, Lda53c [$800da53c]
800DA534	nop
800DA538	break   $01800

Lda53c:	; 800DA53C
800DA53C	mflo   a2
800DA540	bne    t1, zero, Lda550 [$800da550]
800DA544	nop
800DA548	beq    a2, zero, Lda574 [$800da574]
800DA54C	mult   a2, v1

Lda550:	; 800DA550
800DA550	ori    t1, zero, $0001
800DA554	lui    at, $800e
800DA558	addiu  at, at, $0208
800DA55C	addu   at, at, a2
800DA560	lbu    v0, $0000(at)
800DA564	addiu  t0, t0, $0001
800DA568	sb     v0, $0000(a3)
800DA56C	addiu  a3, a3, $0001
800DA570	mult   a2, v1

Lda574:	; 800DA574
800DA574	mflo   v0
800DA578	mult   v1, t2
800DA57C	subu   a0, a0, v0
800DA580	sra    v1, v1, $1f
800DA584	mfhi   v0
800DA588	sra    v0, v0, $02
800DA58C	subu   v1, v0, v1
800DA590	slti   v0, v1, $0002
800DA594	beq    v0, zero, loopda514 [$800da514]
800DA598	addu   v0, a1, t0
800DA59C	lui    at, $800e
800DA5A0	addiu  at, at, $0208
800DA5A4	addu   at, at, a0
800DA5A8	lbu    v1, $0000(at)
800DA5AC	sb     zero, $0001(v0)
800DA5B0	jr     ra 
800DA5B4	sb     v1, $0000(v0)