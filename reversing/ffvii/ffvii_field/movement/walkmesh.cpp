////////////////////////////////
// funca5fb4
800A5FB4	lui    v0, $800a
800A5FB8	lbu    v0, $ac26(v0)
800A5FBC	addiu  sp, sp, $ffb8 (=-$48)
800A5FC0	sw     ra, $0044(sp)
800A5FC4	bne    v0, zero, La62ec [$800a62ec]
800A5FC8	sw     s0, $0040(sp)
800A5FCC	lui    v0, $800a
800A5FD0	lhu    v0, $ac1e(v0)
800A5FD4	nop
800A5FD8	lui    at, $8009
800A5FDC	sh     v0, $65e0(at)
800A5FE0	sll    v0, v0, $10
800A5FE4	sra    v0, v0, $10
800A5FE8	sll    v1, v0, $05
800A5FEC	addu   v1, v1, v0
800A5FF0	lui    v0, $800a
800A5FF4	lhu    v0, $ac16(v0)
800A5FF8	sll    a3, v1, $02
800A5FFC	lui    at, $8007
800A6000	addiu  at, at, $4f16
800A6004	addu   at, at, a3
800A6008	sh     v0, $0000(at)
800A600C	lui    a1, $800a
800A6010	lh     a1, $abf8(a1)
800A6014	ori    v0, zero, $7fff
800A6018	bne    a1, v0, La6140 [$800a6140]
800A601C	addiu  a0, sp, $0010
800A6020	lui    a2, $5555
800A6024	ori    a2, a2, $5556
800A6028	lui    at, $8007
800A602C	addiu  at, at, $4f16
800A6030	addu   at, at, a3
800A6034	lhu    v1, $0000(at)
800A6038	lui    a1, $800e
800A603C	lw     a1, $4274(a1)
800A6040	sll    v0, v1, $01
800A6044	addu   v0, v0, v1
800A6048	sll    v0, v0, $03
800A604C	addu   v0, v0, a1
800A6050	lh     v1, $0000(v0)
800A6054	lh     a0, $0008(v0)
800A6058	lh     v0, $0010(v0)
800A605C	addu   v1, v1, a0
800A6060	addu   v1, v1, v0
800A6064	mult   v1, a2
800A6068	sra    v1, v1, $1f
800A606C	mfhi   v0
800A6070	subu   v0, v0, v1
800A6074	lui    at, $8007
800A6078	addiu  at, at, $4f16
800A607C	addu   at, at, a3
800A6080	lhu    v1, $0000(at)
800A6084	sll    v0, v0, $0c
800A6088	lui    at, $8007
800A608C	addiu  at, at, $4eb0
800A6090	addu   at, at, a3
800A6094	sw     v0, $0000(at)
800A6098	sll    v0, v1, $01
800A609C	addu   v0, v0, v1
800A60A0	sll    v0, v0, $03
800A60A4	addu   v0, v0, a1
800A60A8	lh     v1, $0002(v0)
800A60AC	lh     a0, $000a(v0)
800A60B0	lh     v0, $0012(v0)
800A60B4	addu   v1, v1, a0
800A60B8	addu   v1, v1, v0
800A60BC	mult   v1, a2
800A60C0	sra    v1, v1, $1f
800A60C4	mfhi   v0
800A60C8	subu   v0, v0, v1
800A60CC	lui    at, $8007
800A60D0	addiu  at, at, $4f16
800A60D4	addu   at, at, a3
800A60D8	lhu    v1, $0000(at)
800A60DC	sll    v0, v0, $0c
800A60E0	lui    at, $8007
800A60E4	addiu  at, at, $4eb4
800A60E8	addu   at, at, a3
800A60EC	sw     v0, $0000(at)
800A60F0	sll    v0, v1, $01

La60f4:	; 800A60F4
800A60F4	addu   v0, v0, v1
800A60F8	sll    v0, v0, $03
800A60FC	addu   v0, v0, a1
800A6100	lh     v1, $0004(v0)
800A6104	lh     a0, $000c(v0)
800A6108	lh     v0, $0014(v0)
800A610C	addu   v1, v1, a0
800A6110	addu   v1, v1, v0
800A6114	mult   v1, a2
800A6118	sra    v1, v1, $1f
800A611C	mfhi   v0
800A6120	subu   v0, v0, v1
800A6124	sll    v0, v0, $0c
800A6128	lui    at, $8007
800A612C	addiu  at, at, $4eb8
800A6130	addu   at, at, a3
800A6134	sw     v0, $0000(at)
800A6138	j      La6284 [$800a6284]
800A613C	nop

La6140:	; 800A6140
800A6140	lui    at, $8007
800A6144	addiu  at, at, $4f16
800A6148	addu   at, at, a3
800A614C	lhu    v1, $0000(at)
800A6150	sll    v0, a1, $0c
800A6154	lui    at, $8007
800A6158	addiu  at, at, $4eb0
800A615C	addu   at, at, a3
800A6160	sw     v0, $0000(at)
800A6164	lui    v0, $800a
800A6168	lh     v0, $abfa(v0)
800A616C	sll    a2, v1, $01
800A6170	addu   a2, a2, v1
800A6174	sll    a2, a2, $03
800A6178	addiu  a1, a2, $0008
800A617C	lui    v1, $800e
800A6180	lw     v1, $4274(v1)
800A6184	sll    v0, v0, $0c
800A6188	lui    at, $8007
800A618C	addiu  at, at, $4eb4
800A6190	addu   at, at, a3
800A6194	sw     v0, $0000(at)
800A6198	addu   a1, a1, v1
800A619C	jal    walkmesh_vector_sub [$800a8df4]
800A61A0	addu   a2, a2, v1
800A61A4	lui    v1, $8009
800A61A8	lh     v1, $65e0(v1)
800A61AC	addiu  s0, sp, $0020
800A61B0	sll    v0, v1, $05
800A61B4	addu   v0, v0, v1
800A61B8	sll    v0, v0, $02
800A61BC	lui    at, $8007
800A61C0	addiu  at, at, $4f16
800A61C4	addu   at, at, v0
800A61C8	lhu    v0, $0000(at)
800A61CC	addu   a0, s0, zero
800A61D0	sll    a2, v0, $01
800A61D4	addu   a2, a2, v0
800A61D8	sll    a2, a2, $03
800A61DC	addiu  a1, a2, $0010
800A61E0	lui    v0, $800e
800A61E4	lw     v0, $4274(v0)
800A61E8	addiu  a2, a2, $0008
800A61EC	addu   a1, a1, v0
800A61F0	jal    walkmesh_vector_sub [$800a8df4]
800A61F4	addu   a2, a2, v0
800A61F8	addiu  a0, sp, $0010
800A61FC	lui    v0, $800a
800A6200	lh     v0, $abf8(v0)
800A6204	lui    a2, $800a
800A6208	lh     a2, $abfa(a2)
800A620C	lui    v1, $8009
800A6210	lh     v1, $65e0(v1)
800A6214	addu   a1, s0, zero
800A6218	sw     v0, $0030(sp)
800A621C	sll    v0, v1, $05
800A6220	addu   v0, v0, v1
800A6224	sll    v0, v0, $02
800A6228	sw     a2, $0034(sp)
800A622C	lui    at, $8007
800A6230	addiu  at, at, $4f16
800A6234	addu   at, at, v0
800A6238	lhu    v0, $0000(at)
800A623C	addiu  a2, sp, $0030
800A6240	sll    a3, v0, $01
800A6244	addu   a3, a3, v0
800A6248	lui    v0, $800e
800A624C	lw     v0, $4274(v0)
800A6250	sll    a3, a3, $03
800A6254	jal    walkmesh_calculate_z [$800a8e34]
800A6258	addu   a3, a3, v0
800A625C	lui    a0, $8009
800A6260	lh     a0, $65e0(a0)
800A6264	sll    v0, v0, $0c
800A6268	sll    v1, a0, $05
800A626C	addu   v1, v1, a0
800A6270	sll    v1, v1, $02
800A6274	lui    at, $8007
800A6278	addiu  at, at, $4eb8
800A627C	addu   at, at, v1
800A6280	sw     v0, $0000(at)

La6284:	; 800A6284
800A6284	lui    a1, $800a
800A6288	addiu  a1, a1, $ac04 (=-$53fc)
800A628C	lui    v0, $8009
800A6290	lh     v0, $65e0(v0)
800A6294	lh     v1, $0000(a1)
800A6298	sll    a0, v0, $05
800A629C	addu   a0, a0, v0
800A62A0	sll    a0, a0, $02
800A62A4	sll    v0, v1, $04
800A62A8	addu   v0, v0, v1
800A62AC	sra    v0, v0, $08
800A62B0	lui    at, $8007
800A62B4	addiu  at, at, $4f10
800A62B8	addu   at, at, a0
800A62BC	sh     v0, $0000(at)
800A62C0	lh     v0, $0000(a1)
800A62C4	ori    v1, zero, $0010
800A62C8	lui    at, $8007
800A62CC	addiu  at, at, $4f04
800A62D0	addu   at, at, a0
800A62D4	sh     v1, $0000(at)
800A62D8	sll    v0, v0, $01
800A62DC	lui    at, $8007
800A62E0	addiu  at, at, $4f14
800A62E4	addu   at, at, a0
800A62E8	sh     v0, $0000(at)

La62ec:	; 800A62EC
800A62EC	lui    a2, $800a
800A62F0	addiu  a2, a2, $ac1c (=-$53e4)
800A62F4	lh     v0, $0000(a2)
800A62F8	nop
800A62FC	blez   v0, La6348 [$800a6348]
800A6300	addu   a1, zero, zero
800A6304	sll    a0, a1, $10

loopa6308:	; 800A6308
800A6308	addiu  v1, a1, $0001
800A630C	addu   a1, v1, zero
800A6310	sra    a0, a0, $10
800A6314	sll    v0, a0, $05
800A6318	addu   v0, v0, a0
800A631C	sll    v0, v0, $02
800A6320	sll    v1, v1, $10
800A6324	lui    at, $8007
800A6328	addiu  at, at, $4ed9
800A632C	addu   at, at, v0
800A6330	sb     zero, $0000(at)
800A6334	lh     v0, $0000(a2)
800A6338	sra    v1, v1, $10
800A633C	slt    v1, v1, v0
800A6340	bne    v1, zero, loopa6308 [$800a6308]
800A6344	sll    a0, a1, $10

La6348:	; 800A6348
800A6348	lw     ra, $0044(sp)
800A634C	lw     s0, $0040(sp)
800A6350	addiu  sp, sp, $0048
800A6354	jr     ra 
800A6358	nop
////////////////////////////////
