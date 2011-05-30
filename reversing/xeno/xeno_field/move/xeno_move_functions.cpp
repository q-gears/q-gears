////////////////////////////////
// func7ae28
8007AE30	addu   s1, a0, zero
8007AE38	addu   s3, a1, zero
8007AE40	addu   s4, a2, zero
8007AE48	addu   s2, a3, zero
8007AE50	andi   s0, s2, $0fff
8007AE54	addu   a0, s0, zero
func3f774; // cos

8007AE6C	addu   a0, s0, zero
8007AE70	lw     v1, $0000(s1)
8007AE74	sll    v0, v0, $06
8007AE78	addu   v1, v1, v0
8007AE80	sw     v1, $0018(sp)
func3f758; // sin

8007AE84	addiu  a0, sp, $0018
8007AE88	addiu  s6, s3, $0020
8007AE8C	addu   a1, s6, zero
8007AE90	addu   a2, s3, zero
8007AE94	addu   a3, s4, zero
8007AE98	sll    v0, v0, $06
8007AE9C	addiu  s5, sp, $0028
8007AEA0	lw     v1, $0008(s1)
8007AEA4	addiu  s7, zero, $ffff (=-$1)
8007AEA8	subu   v1, v1, v0
8007AEAC	sw     v1, $0020(sp)
8007AEB0	sw     s5, $0010(sp)
8007AEB4	jal    func7bca8 [$8007bca8]
8007AEB8	sw     s7, $0014(sp)
8007AEBC	bne    v0, s7, L7aed0 [$8007aed0]
8007AEC0	sll    v0, s2, $10
8007AEC4	sll    a0, s2, $10
8007AEC8	j      L7af8c [$8007af8c]
8007AECC	sra    a0, a0, $10

L7aed0:	; 8007AED0
8007AED0	sra    s2, v0, $10
8007AED4	addiu  s0, s2, $ff00 (=-$100)
8007AED8	andi   s0, s0, $0fff
8007AEE0	addu   a0, s0, zero
func3f774; // cos

8007AEE4	addu   a0, s0, zero
8007AEE8	lw     v1, $0000(s1)
8007AEEC	sll    v0, v0, $06
8007AEF0	addu   v1, v1, v0
8007AEF8	sw     v1, $0018(sp)
func3f758; // sin

8007AEFC	addiu  a0, sp, $0018
8007AF00	addu   a1, s6, zero
8007AF04	addu   a2, s3, zero
8007AF08	addu   a3, s4, zero
8007AF0C	lw     v1, $0008(s1)
8007AF10	sll    v0, v0, $06
8007AF14	subu   v1, v1, v0
8007AF18	sw     v1, $0020(sp)
8007AF1C	sw     s5, $0010(sp)
8007AF20	jal    func7bca8 [$8007bca8]
8007AF24	sw     s7, $0014(sp)
8007AF28	beq    v0, s7, L7af88 [$8007af88]
8007AF2C	addiu  s0, s2, $0100
8007AF30	andi   s0, s0, $0fff
8007AF38	addu   a0, s0, zero
func3f774; // cos

8007AF3C	addu   a0, s0, zero
8007AF40	lw     v1, $0000(s1)
8007AF44	sll    v0, v0, $06
8007AF48	addu   v1, v1, v0
8007AF50	sw     v1, $0018(sp)
func3f758; // sin

8007AF54	addiu  a0, sp, $0018
8007AF58	addu   a1, s6, zero
8007AF5C	addu   a2, s3, zero
8007AF60	addu   a3, s4, zero
8007AF64	lw     v1, $0008(s1)
8007AF68	sll    v0, v0, $06
8007AF6C	subu   v1, v1, v0
8007AF70	sw     v1, $0020(sp)
8007AF74	sw     s5, $0010(sp)
8007AF78	jal    func7bca8 [$8007bca8]
8007AF7C	sw     s7, $0014(sp)
8007AF80	bne    v0, s7, L7afbc [$8007afbc]
8007AF84	addiu  a0, sp, $0018

L7af88:	; 8007AF88
8007AF88	addu   a0, s2, zero

L7af8c:	; 8007AF8C
8007AF8C	lw     v0, $0000(s1)
8007AF90	addu   a1, s4, zero
8007AF94	sw     v0, $0018(sp)
8007AF98	lw     v0, $0004(s1)
8007AF9C	addiu  a2, sp, $0018
8007AFA0	sw     v0, $001c(sp)
8007AFA4	lw     v0, $0008(s1)
8007AFA8	addu   a3, zero, zero
8007AFB0	sw     v0, $0020(sp)
field_get_move_vector_to_move_along_with_line;

8007AFB4	j      L7afe0 [$8007afe0]
8007AFB8	addiu  a0, sp, $0018

L7afbc:	; 8007AFBC
8007AFBC	lw     v0, $0000(s1)
8007AFC0	nop
8007AFC4	sw     v0, $0018(sp)
8007AFC8	lw     v0, $0004(s1)
8007AFCC	nop
8007AFD0	sw     v0, $001c(sp)
8007AFD4	lw     v0, $0008(s1)
8007AFD8	nop
8007AFDC	sw     v0, $0020(sp)

L7afe0:	; 8007AFE0
8007AFE0	addiu  a1, s3, $0020
8007AFE4	addu   a2, s3, zero
8007AFE8	addu   a3, s4, zero
8007AFEC	addiu  v0, sp, $0028
8007AFF0	sw     v0, $0010(sp)
8007AFF4	jal    func7bca8 [$8007bca8]
8007AFF8	sw     zero, $0014(sp)
8007AFFC	addiu  v1, zero, $ffff (=-$1)
8007B000	beq    v0, v1, L7b048 [$8007b048]
8007B004	lui    v1, $0004
8007B008	lw     v0, $0000(s3)
8007B00C	nop
8007B010	and    v0, v0, v1
8007B014	bne    v0, zero, L7b050 [$8007b050]
8007B018	nop
8007B01C	lh     v0, $002a(sp)
8007B020	lw     v1, $0024(s3)
8007B024	sll    v0, v0, $10
8007B028	slt    v0, v0, v1
8007B02C	beq    v0, zero, L7b05c [$8007b05c]
8007B030	nop
8007B034	lui    v0, $800b
8007B038	lw     v0, $d070(v0)
8007B03C	nop
8007B040	bne    v0, zero, L7b05c [$8007b05c]
8007B044	nop

L7b048:	; 8007B048
8007B048	j      L7b0a4 [$8007b0a4]
8007B04C	addiu  v0, zero, $ffff (=-$1)

L7b050:	; 8007B050
8007B050	lhu    v0, $00ec(s3)
8007B054	nop
8007B058	sh     v0, $002a(sp)

L7b05c:	; 8007B05C
8007B05C	lh     v0, $002a(sp)
8007B060	lw     v1, $0024(s3)
8007B064	lw     a0, $0018(sp)
8007B068	sll    v0, v0, $10
8007B06C	subu   v0, v0, v1
8007B070	sw     v0, $001c(sp)
8007B074	sw     a0, $0000(s1)
8007B078	lw     v0, $001c(sp)
8007B07C	nop
8007B080	sw     v0, $0004(s1)
8007B084	lw     v0, $0020(sp)
8007B088	lw     a0, $0004(s1)
8007B08C	sw     v0, $0008(s1)
8007B090	lw     v1, $0024(s3)
8007B094	addu   v0, zero, zero
8007B098	addu   v1, v1, a0
8007B09C	sra    v1, v1, $10
8007B0A0	sh     v1, $0072(s3)

L7b0a4:	; 8007B0A4
////////////////////////////////



////////////////////////////////
// func7bca8
8007BCA8	addiu  sp, sp, $ff80 (=-$80)
8007BCAC	addu   t1, a0, zero
8007BCB0	addu   t0, a1, zero
8007BCB4	sw     ra, $007c(sp)
8007BCB8	sw     fp, $0078(sp)
8007BCBC	sw     s7, $0074(sp)
8007BCC0	sw     s6, $0070(sp)
8007BCC4	sw     s5, $006c(sp)
8007BCC8	sw     s4, $0068(sp)
8007BCCC	sw     s3, $0064(sp)
8007BCD0	sw     s2, $0060(sp)
8007BCD4	sw     s1, $005c(sp)
8007BCD8	sw     s0, $0058(sp)
8007BCDC	sw     a2, $0028(sp)
8007BCE0	lh     v0, $0010(a2)
8007BCE4	nop
8007BCE8	sll    v1, v0, $01
8007BCEC	addu   v1, v1, a2
8007BCF0	sll    v0, v0, $02
8007BCF4	lh     s0, $0008(v1)
8007BCF8	addiu  v1, zero, $ffff (=-$1)
8007BCFC	lui    at, $800b
8007BD00	addu   at, at, v0
8007BD04	lw     s5, $eff8(at)
8007BD08	lui    at, $800b
8007BD0C	addu   at, at, v0
8007BD10	lw     s6, $f008(at)
8007BD14	bne    s0, v1, L7bd2c [$8007bd2c]
8007BD18	addu   s7, a3, zero
8007BD1C	j      L7c31c [$8007c31c]
8007BD20	addiu  v0, zero, $ffff (=-$1)

L7bd24:	; 8007BD24
8007BD24	j      L7c044 [$8007c044]
8007BD28	addiu  s0, zero, $ffff (=-$1)

L7bd2c:	; 8007BD2C
8007BD2C	lw     a1, $0000(t0)
8007BD30	lw     v1, $0000(t1)
8007BD34	lw     a3, $0008(t0)
8007BD38	lw     a0, $0008(t1)
8007BD3C	lw     t2, $0090(sp)
8007BD40	addu   v1, a1, v1
8007BD44	sra    v1, v1, $10
8007BD48	sh     v1, $0000(t2)
8007BD4C	sll    v1, v1, $10
8007BD50	addu   a0, a3, a0
8007BD54	sra    a0, a0, $10
8007BD58	addu   fp, v1, a0
8007BD5C	sra    a1, a1, $10
8007BD60	sll    a1, a1, $10
8007BD64	lw     v0, $0008(t0)
8007BD68	lw     a2, $0008(t1)
8007BD6C	sra    a3, a3, $10
8007BD70	sw     zero, $0038(sp)
8007BD74	sh     zero, $0002(t2)
8007BD78	addu   v0, v0, a2
8007BD7C	sra    v0, v0, $10
8007BD80	sh     v0, $0004(t2)
8007BD84	lw     t2, $0028(sp)
8007BD88	addu   a1, a1, a3
8007BD8C	sw     a1, $0040(sp)
8007BD90	lh     v1, $0010(t2)
8007BD94	lw     v0, $0004(t2)
8007BD98	addiu  v1, v1, $0003
8007BD9C	srlv   v0, v1, v0
8007BDA0	andi   v0, v0, $0001
8007BDA4	bne    v0, zero, L7bdc4 [$8007bdc4]
8007BDA8	nop
8007BDAC	lui    v0, $800b
8007BDB0	lbu    v0, $16a0(v0)
8007BDB4	nop
8007BDB8	sltiu  v0, v0, $0001
8007BDBC	subu   v0, zero, v0
8007BDC0	sw     v0, $0038(sp)

L7bdc4:	; 8007BDC4
8007BDC4	sw     zero, $0048(sp)

L7bdc8:	; 8007BDC8
8007BDC8	sw     s0, $0030(sp)
8007BDCC	sll    a1, s0, $03
8007BDD0	subu   a1, a1, s0
8007BDD4	sll    a1, a1, $01
8007BDD8	addu   a1, a1, s5
8007BDDC	lh     v0, $0000(a1)
8007BDE0	addu   a2, fp, zero
8007BDE4	sll    v0, v0, $03
8007BDE8	addu   v0, v0, s6
8007BDEC	lh     v1, $0000(v0)
8007BDF0	lh     v0, $0004(v0)
8007BDF4	sll    v1, v1, $10
8007BDF8	addu   s4, v1, v0
8007BDFC	lh     v0, $0002(a1)
8007BE00	addu   a0, s4, zero
8007BE04	sll    v0, v0, $03
8007BE08	addu   v0, v0, s6
8007BE0C	lh     v1, $0000(v0)
8007BE10	lh     v0, $0004(v0)
8007BE14	sll    v1, v1, $10
8007BE18	addu   s3, v1, v0
8007BE1C	lh     v0, $0004(a1)
8007BE20	addu   a1, s3, zero
8007BE24	sll    v0, v0, $03
8007BE28	addu   v0, v0, s6
8007BE2C	lh     v1, $0000(v0)
8007BE30	lh     v0, $0004(v0)
8007BE34	sll    v1, v1, $10
8007BE38	jal    system_side_of_vector [$8004a5b4]
8007BE3C	addu   s2, v1, v0
8007BE40	srl    s1, v0, $1f
8007BE44	addu   a0, s3, zero
8007BE48	addu   a1, s2, zero
8007BE4C	jal    system_side_of_vector [$8004a5b4]
8007BE50	addu   a2, fp, zero
8007BE54	bgez   v0, L7be60 [$8007be60]
8007BE58	addu   a0, s2, zero
8007BE5C	ori    s1, s1, $0002

L7be60:	; 8007BE60
8007BE60	addu   a1, s4, zero
8007BE64	jal    system_side_of_vector [$8004a5b4]
8007BE68	addu   a2, fp, zero
8007BE6C	bgez   v0, L7be7c [$8007be7c]
8007BE70	sltiu  v0, s1, $0008
8007BE74	ori    s1, s1, $0004
8007BE78	sltiu  v0, s1, $0008

L7be7c:	; 8007BE7C
8007BE7C	beq    v0, zero, L7bf98 [$8007bf98]
8007BE80	sll    v0, s1, $02
8007BE84	lui    at, $8007
8007BE88	addu   at, at, v0
8007BE8C	lw     v0, $f23c(at)
8007BE90	nop
8007BE94	jr     v0 
8007BE98	nop

8007BE9C	ori    t2, zero, $00ff
8007BEA0	j      L7bf98 [$8007bf98]
8007BEA4	sw     t2, $0048(sp)
8007BEA8	sll    v0, s0, $03
8007BEAC	subu   v0, v0, s0
8007BEB0	sll    v0, v0, $01
8007BEB4	addu   v0, v0, s5
8007BEB8	lh     s0, $0006(v0)
8007BEBC	j      L7bf9c [$8007bf9c]
8007BEC0	sll    v0, s0, $03
8007BEC4	sll    v0, s0, $03
8007BEC8	subu   v0, v0, s0
8007BECC	sll    v0, v0, $01
8007BED0	addu   v0, v0, s5
8007BED4	lh     s0, $0008(v0)
8007BED8	j      L7bf9c [$8007bf9c]
8007BEDC	sll    v0, s0, $03
8007BEE0	addu   a0, s3, zero
8007BEE4	lw     a2, $0040(sp)
8007BEE8	jal    system_side_of_vector [$8004a5b4]
8007BEEC	addu   a1, fp, zero
8007BEF0	bltz   v0, L7bf34 [$8007bf34]
8007BEF4	sll    v0, s0, $03
8007BEF8	j      L7bf68 [$8007bf68]
8007BEFC	subu   v0, v0, s0
8007BF00	sll    v0, s0, $03
8007BF04	subu   v0, v0, s0
8007BF08	sll    v0, v0, $01
8007BF0C	addu   v0, v0, s5
8007BF10	lh     s0, $000a(v0)
8007BF14	j      L7bf9c [$8007bf9c]
8007BF18	sll    v0, s0, $03
8007BF1C	addu   a0, s4, zero
8007BF20	lw     a2, $0040(sp)
8007BF24	jal    system_side_of_vector [$8004a5b4]
8007BF28	addu   a1, fp, zero
8007BF2C	bltz   v0, L7bf7c [$8007bf7c]
8007BF30	sll    v0, s0, $03

L7bf34:	; 8007BF34
8007BF34	subu   v0, v0, s0
8007BF38	sll    v0, v0, $01
8007BF3C	addu   v0, v0, s5
8007BF40	lh     s0, $0006(v0)
8007BF44	j      L7bf98 [$8007bf98]
8007BF48	ori    s1, zero, $0001
8007BF4C	addu   a0, s2, zero
8007BF50	lw     a2, $0040(sp)
8007BF54	jal    system_side_of_vector [$8004a5b4]
8007BF58	addu   a1, fp, zero
8007BF5C	bgez   v0, L7bf7c [$8007bf7c]
8007BF60	sll    v0, s0, $03
8007BF64	subu   v0, v0, s0

L7bf68:	; 8007BF68
8007BF68	sll    v0, v0, $01
8007BF6C	addu   v0, v0, s5
8007BF70	lh     s0, $0008(v0)
8007BF74	j      L7bf98 [$8007bf98]
8007BF78	ori    s1, zero, $0002

L7bf7c:	; 8007BF7C
8007BF7C	subu   v0, v0, s0
8007BF80	sll    v0, v0, $01
8007BF84	addu   v0, v0, s5
8007BF88	lh     s0, $000a(v0)
8007BF8C	j      L7bf98 [$8007bf98]
8007BF90	ori    s1, zero, $0004
8007BF94	addiu  s0, zero, $ffff (=-$1)

L7bf98:	; 8007BF98
8007BF98	sll    v0, s0, $03

L7bf9c:	; 8007BF9C
8007BF9C	subu   v0, v0, s0
8007BFA0	sll    v0, v0, $01
8007BFA4	addu   v0, v0, s5
8007BFA8	lbu    v0, $000c(v0)
8007BFAC	lui    v1, $800b
8007BFB0	lw     v1, $eff4(v1)
8007BFB4	lw     t2, $0028(sp)
8007BFB8	sll    v0, v0, $02
8007BFBC	addu   v0, v0, v1
8007BFC0	lw     v0, $0000(v0)
8007BFC4	lw     a1, $0000(t2)
8007BFC8	lw     t2, $0038(sp)
8007BFCC	nop
8007BFD0	and    a0, v0, t2
8007BFD4	srl    v0, a1, $09
8007BFD8	andi   v0, v0, $0003
8007BFDC	srl    v1, a0, $03
8007BFE0	and    v0, v0, v1
8007BFE4	bne    v0, zero, L7bd24 [$8007bd24]
8007BFE8	srl    v0, a1, $08
8007BFEC	andi   v0, v0, $0007
8007BFF0	srl    v1, a0, $05
8007BFF4	and    v0, v0, v1
8007BFF8	bne    v0, zero, L7bd24 [$8007bd24]
8007BFFC	lui    v0, $0080
8007C000	and    v0, a0, v0
8007C004	beq    v0, zero, L7c024 [$8007c024]
8007C008	addiu  v0, zero, $ffff (=-$1)
8007C00C	lw     t2, $0028(sp)
8007C010	nop
8007C014	lh     v0, $0010(t2)
8007C018	nop
8007C01C	beq    v0, zero, L7bd24 [$8007bd24]
8007C020	addiu  v0, zero, $ffff (=-$1)

L7c024:	; 8007C024
8007C024	beq    s0, v0, L7c0c4 [$8007c0c4]
8007C028	ori    v0, zero, $0002
8007C02C	lw     t2, $0048(sp)
8007C030	nop
8007C034	addiu  t2, t2, $0001
8007C038	slti   v0, t2, $0020
8007C03C	bne    v0, zero, L7bdc8 [$8007bdc8]
8007C040	sw     t2, $0048(sp)

L7c044:	; 8007C044
8007C044	addiu  v1, zero, $ffff (=-$1)
8007C048	beq    s0, v1, L7c0c0 [$8007c0c0]
8007C04C	ori    v0, zero, $0020
8007C050	lw     t2, $0048(sp)
8007C054	nop
8007C058	beq    t2, v0, L7c0c0 [$8007c0c0]
8007C05C	nop
8007C060	lw     t2, $0094(sp)
8007C064	nop
8007C068	bne    t2, v1, L7c078 [$8007c078]
8007C06C	sll    v0, s0, $03
8007C070	j      L7c31c [$8007c31c]
8007C074	addu   v0, zero, zero

L7c078:	; 8007C078
8007C078	subu   v0, v0, s0
8007C07C	sll    v0, v0, $01
8007C080	addu   v0, v0, s5
8007C084	lh     a0, $0000(v0)
8007C088	lh     a1, $0002(v0)
8007C08C	lh     a2, $0004(v0)
8007C090	lw     a3, $0090(sp)
8007C094	addiu  v0, sp, $0018
8007C098	sw     v0, $0010(sp)
8007C09C	sll    a0, a0, $03
8007C0A0	addu   a0, s6, a0
8007C0A4	sll    a1, a1, $03
8007C0A8	addu   a1, s6, a1
8007C0AC	sll    a2, a2, $03
8007C0B0	jal    field_calculate_walkmesh_height [$8007a690]
8007C0B4	addu   a2, s6, a2
8007C0B8	j      L7c31c [$8007c31c]
8007C0BC	addu   v0, zero, zero

L7c0c0:	; 8007C0C0
8007C0C0	ori    v0, zero, $0002

L7c0c4:	; 8007C0C4
8007C0C4	beq    s1, v0, L7c1a8 [$8007c1a8]
8007C0C8	slti   v0, s1, $0003
8007C0CC	beq    v0, zero, L7c0e4 [$8007c0e4]
8007C0D0	ori    v0, zero, $0001
8007C0D4	beq    s1, v0, L7c0f8 [$8007c0f8]
8007C0D8	addiu  v0, zero, $ffff (=-$1)
8007C0DC	j      L7c31c [$8007c31c]
8007C0E0	nop

L7c0e4:	; 8007C0E4
8007C0E4	ori    v0, zero, $0004
8007C0E8	beq    s1, v0, L7c258 [$8007c258]
8007C0EC	addiu  v0, zero, $ffff (=-$1)
8007C0F0	j      L7c31c [$8007c31c]
8007C0F4	nop

L7c0f8:	; 8007C0F8
8007C0F8	lw     t2, $0030(sp)
8007C0FC	nop
8007C100	sll    v1, t2, $03
8007C104	subu   v1, v1, t2
8007C108	sll    v1, v1, $01
8007C10C	addu   v1, v1, s5
8007C110	lh     v0, $0000(v1)
8007C114	nop
8007C118	sll    v0, v0, $03
8007C11C	addu   v0, v0, s6
8007C120	lhu    v0, $0000(v0)
8007C124	nop
8007C128	sh     v0, $0000(s7)
8007C12C	lh     v0, $0000(v1)
8007C130	nop
8007C134	sll    v0, v0, $03
8007C138	addu   v0, v0, s6
8007C13C	lhu    v0, $0002(v0)
8007C140	nop
8007C144	sh     v0, $0002(s7)
8007C148	lh     v0, $0000(v1)
8007C14C	nop
8007C150	sll    v0, v0, $03
8007C154	addu   v0, v0, s6
8007C158	lhu    v0, $0004(v0)
8007C15C	nop
8007C160	sh     v0, $0004(s7)
8007C164	lh     v0, $0002(v1)
8007C168	nop
8007C16C	sll    v0, v0, $03
8007C170	addu   v0, v0, s6
8007C174	lhu    v0, $0000(v0)
8007C178	nop
8007C17C	sh     v0, $0008(s7)
8007C180	lh     v0, $0002(v1)
8007C184	nop
8007C188	sll    v0, v0, $03
8007C18C	addu   v0, v0, s6
8007C190	lhu    v0, $0002(v0)
8007C194	nop
8007C198	sh     v0, $000a(s7)
8007C19C	lh     v0, $0002(v1)
8007C1A0	j      L7c308 [$8007c308]
8007C1A4	sll    v0, v0, $03

L7c1a8:	; 8007C1A8
8007C1A8	lw     t2, $0030(sp)
8007C1AC	nop
8007C1B0	sll    v1, t2, $03
8007C1B4	subu   v1, v1, t2
8007C1B8	sll    v1, v1, $01
8007C1BC	addu   v1, v1, s5
8007C1C0	lh     v0, $0002(v1)
8007C1C4	nop
8007C1C8	sll    v0, v0, $03
8007C1CC	addu   v0, v0, s6
8007C1D0	lhu    v0, $0000(v0)
8007C1D4	nop
8007C1D8	sh     v0, $0000(s7)
8007C1DC	lh     v0, $0002(v1)
8007C1E0	nop
8007C1E4	sll    v0, v0, $03
8007C1E8	addu   v0, v0, s6
8007C1EC	lhu    v0, $0002(v0)
8007C1F0	nop
8007C1F4	sh     v0, $0002(s7)
8007C1F8	lh     v0, $0002(v1)
8007C1FC	nop
8007C200	sll    v0, v0, $03
8007C204	addu   v0, v0, s6
8007C208	lhu    v0, $0004(v0)
8007C20C	nop
8007C210	sh     v0, $0004(s7)
8007C214	lh     v0, $0004(v1)
8007C218	nop
8007C21C	sll    v0, v0, $03
8007C220	addu   v0, v0, s6
8007C224	lhu    v0, $0000(v0)
8007C228	nop
8007C22C	sh     v0, $0008(s7)
8007C230	lh     v0, $0004(v1)
8007C234	nop
8007C238	sll    v0, v0, $03
8007C23C	addu   v0, v0, s6
8007C240	lhu    v0, $0002(v0)
8007C244	nop
8007C248	sh     v0, $000a(s7)
8007C24C	lh     v0, $0004(v1)
8007C250	j      L7c308 [$8007c308]
8007C254	sll    v0, v0, $03

L7c258:	; 8007C258
8007C258	lw     t2, $0030(sp)
8007C25C	nop
8007C260	sll    v1, t2, $03
8007C264	subu   v1, v1, t2
8007C268	sll    v1, v1, $01
8007C26C	addu   v1, v1, s5
8007C270	lh     v0, $0004(v1)
8007C274	nop
8007C278	sll    v0, v0, $03
8007C27C	addu   v0, v0, s6
8007C280	lhu    v0, $0000(v0)
8007C284	nop
8007C288	sh     v0, $0000(s7)
8007C28C	lh     v0, $0004(v1)
8007C290	nop
8007C294	sll    v0, v0, $03
8007C298	addu   v0, v0, s6
8007C29C	lhu    v0, $0002(v0)
8007C2A0	nop
8007C2A4	sh     v0, $0002(s7)
8007C2A8	lh     v0, $0004(v1)
8007C2AC	nop
8007C2B0	sll    v0, v0, $03
8007C2B4	addu   v0, v0, s6
8007C2B8	lhu    v0, $0004(v0)
8007C2BC	nop
8007C2C0	sh     v0, $0004(s7)
8007C2C4	lh     v0, $0000(v1)
8007C2C8	nop
8007C2CC	sll    v0, v0, $03
8007C2D0	addu   v0, v0, s6
8007C2D4	lhu    v0, $0000(v0)
8007C2D8	nop
8007C2DC	sh     v0, $0008(s7)
8007C2E0	lh     v0, $0000(v1)
8007C2E4	nop
8007C2E8	sll    v0, v0, $03
8007C2EC	addu   v0, v0, s6
8007C2F0	lhu    v0, $0002(v0)
8007C2F4	nop
8007C2F8	sh     v0, $000a(s7)
8007C2FC	lh     v0, $0000(v1)
8007C300	nop
8007C304	sll    v0, v0, $03

L7c308:	; 8007C308
8007C308	addu   v0, v0, s6
8007C30C	lhu    v0, $0004(v0)
8007C310	nop
8007C314	sh     v0, $000c(s7)
8007C318	addiu  v0, zero, $ffff (=-$1)

L7c31c:	; 8007C31C
8007C31C	lw     ra, $007c(sp)
8007C320	lw     fp, $0078(sp)
8007C324	lw     s7, $0074(sp)
8007C328	lw     s6, $0070(sp)
8007C32C	lw     s5, $006c(sp)
8007C330	lw     s4, $0068(sp)
8007C334	lw     s3, $0064(sp)
8007C338	lw     s2, $0060(sp)
8007C33C	lw     s1, $005c(sp)
8007C340	lw     s0, $0058(sp)
8007C344	addiu  sp, sp, $0080
8007C348	jr     ra 
8007C34C	nop
////////////////////////////////



////////////////////////////////
// func7b0d4
// main move ???

// SP = SP - a8
// A0 - some address (SP + 10) // vector to which we rotated if it not 0
// A1 - entity structure
// A2 - address to store line that we can't intersect
// A3 - rotation 0x0XXX
// return -1 if we can't move, 0 otherwise.

move_vector = A0;
entity_structure = A1;
intersect_line = A2;
rotation = A3;



// check first rotation
angle1 = (rotation - 100) & 0fff;

A0 = angle1;
func3f774; // cos
[SP + 20] = w(w[move_vector + 0] + (V0 << 6));

A0 = angle1;
func3f758; // sin
[SP + 28] = w(w[move_vector + 8] - (V0 << 6));

A0 = SP + 20; // move vector
A1 = entity_structure + 20; // current pos
A2 = entity_structure;
A3 = intersect_line; // address to store line that we can't intersect
A4 = SP + 40; // address of final point
A5 = -1; // we don't need to calculate height of final point
A6 = SP + 70; // we store material here
field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

if (V0 != -1)
{



    // check second rotation
    angle2 = (rotation + 100) & 0fff;

    A0 = angle2;
    func3f774; // cos
    [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

    A0 = angle2;
    func3f758; // sin
    [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

    A0 = SP + 20;
    A1 = entity_structure + 20;
    A2 = entity_structure;
    A3 = intersect_line;
    A4 = SP + 40;
    A5 = -1;
    A6 = SP + 70;
    field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

    if (V0 != -1)
    {



        // check straight
        A0 = rotation & 0fff;
        func3f774; // cos
        [SP + 20] = w(w[move_vector + 0] + (V0 << 6));

        A0 = rotation & 0fff;
        func3f758; // sin
        [SP + 28] = w(w[move_vector + 8] - (V0 << 6));

        A0 = SP + 20;
        A1 = entity_structure + 20;
        A2 = entity_structure;
        A3 = intersect_line;
        A4 = SP + 40;
        A5 = -1;
        A6 = SP + 70;
        field_check_walkmesh_triangle_and_calculate_height; // 0 - can move, -1 - can't move

        if (V0 != -1)
        {
            [SP + 20] = w(w[move_vector + 0]);
            [SP + 24] = w(w[move_vector + 4]);
            [SP + 28] = w(w[move_vector + 8]);
            8007B274	j      L7b2a0 [$8007b2a0]
        }
    }
}

[SP + 20] = w(w[move_vector + 0]);
[SP + 24] = w(w[move_vector + 4]);
[SP + 28] = w(w[move_vector + 8]);

A0 = rotation;
A1 = intersect_line;
A2 = SP + 20;
field_get_move_vector_to_move_along_with_line;

L7b2a0:	; 8007B2A0
A0 = SP + 20;
A1 = entity_structure + 20;
A2 = entity_structure;
A3 = intersect_line;
A4 = SP + 40;
A5 = 0;
A6 = SP + 70;
field_check_walkmesh_triangle_and_calculate_height; // check triangle

if (V0 != -1)
{
    // store move vector
    [SP + 30] = w(w[SP + 20]);
    [SP + 34] = w(w[SP + 24]);
    [SP + 38] = w(w[SP + 28]);

    // store new position
    [SP + 48] = h(hu[SP + 40]);
    [SP + 4a] = h(hu[SP + 42]);
    [SP + 4c] = h(hu[SP + 44]);

    start_y = h[entity_structure + 26]; // y current
    end_y = h[SP + 42]; // y calculated

    // if we do something that can bother movement
    if ((end_y < start_y) ||
        (w[SP + 70] & 00200000) ||
        ((w[SP + 70] & 00420000) && (w[entity_structure + 14] & 00420000)) ||
        (((w[SP + 70] & 00420000) == 0) && (end_y < start_y + 40)))
    {
        V0 = w[SP + 20];
        V0 = -V0;
        V0 = V0 >> 8;
        [SP + 50] = w(V0);

        V1 = w[SP + 28];
        V1 = -V1;
        V1 = V1 >> 8;
        [SP + 58] = w(V1);

        V0 = h[SP + 42];
        A2 = w[entity_structure + 24];
        V0 = V0 << 10;
        V0 = V0 - A2;
        V0 = V0 >> 8;
        [SP + 54] = w(V0);

        A0 = SP + 50;
        A1 = SP + 60;
        system_normalize_word_vector_T0_T1_T2_to_word;

        A0 = w[SP + 20] >> 8;
        A1 = w[SP + 28] >> 8;
        length_of_vector_by_x_y;

        T2 = V0 * w[SP + 60];
        V0 = V0 * w[SP + 64];
        V1 = V0 * w[SP + 68];
        V0 = -T2;
        [SP + 20] = w(V0 >> 4);
        [SP + 24] = w(T0 >> 4);
        V0 = -V1;
        [SP + 28] = w(V0 >> 4);

        A0 = SP + 20;
        A1 = entity_structure + 20;
        A2 = entity_structure;
        A3 = intersect_line;
        [SP + 10] = w(SP + 40);
        [SP + 14] = w(0);
        [SP + 18] = w(SP + 70);
        field_check_walkmesh_triangle_and_calculate_height; // check triangle

        if (V0 == -1)
        {
            return -1;
        }

        [entity_structure + 0] = w(w[entity_structure + 0] | 04000000);
    }
    else
    {
        // restore previous position
        [SP + 20] = w(w[SP + 30]);
        [SP + 24] = w(w[SP + 34]);
        [SP + 28] = w(w[SP + 38]);

        [SP + 40] = h(hu[SP + 48]);
        [SP + 42] = h(hu[SP + 4a]);
        [SP + 44] = h(hu[SP + 4c]);
    }

    [SP + 24] = w((h[SP + 42] << 10) - w[entity_structure + 24]);
    [move_vector + 0] = w(w[SP + 20]);
    [move_vector + 4] = w(w[SP + 24]);
    [move_vector + 8] = w(w[SP + 28]);
    [entity_structure + 72] = h((w[entity_structure + 24] + w[move_vector + 4]) >> 10);

    return 0;
}

return -1;
////////////////////////////////




////////////////////////////////
// field_check_walkmesh_triangle_and_calculate_height
// A0 - move vector
// A1 - current pos
// A2 - entity structure
// A3 - address to store line that we can't intersect
// A4 - address of final point
// A5 - if -1 then we don't need to really calculate height of final point
//      if 00000080 then we can go only down. Simulate material 00400000.
// A6 - pointer to store material
// return -1 if we can't move, 0 otherwise.

move_vector             = A0;
current_pos             = A1;
entity_structure        = A2;
intersect_line          = A3;

walkmesh_id             = h[entity_structure + 10];
triangle_id             = h[entity_structure + 08 + walkmesh_id * 2];

walkmesh_vertex_data  = w[800af008 + walkmesh_id * 4];
walkmesh_triangle_data    = w[800aeff8 + walkmesh_id * 4];
walkmesh_material_data  = w[800aeff4];

if (triangle_id != -1)
{
    move_x              = w[move_vector + 0];
    move_z              = w[move_vector + 8];
    start_x             = w[current_pos + 0];
    start_y             = w[current_pos + 4];
    start_z             = w[current_pos + 8];
    end_x               = (start_x + move_x) >> 10;
    end_z               = (start_z + move_z) >> 10;
    start_x_z           = ((start_x >> 10) << 10) + (start_z >> 10);
    ending_point_x_z    = (end_x << 10) + end_z;

    [A4 + 0] = h(end_x);
    [A4 + 2] = h(0);
    [A4 + 4] = h(end_z);

    if (((w[entity_structure + 4] >> (walkmesh_id + 3)) & 1) == 0 && bu[800b16a0] == 0)
    {
        material_mask = ffffffff;
    }
    else
    {
        material_mask = 00000000;
    }



    material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
    material = w[walkmesh_material_data + material_id * 4];

    if ((material & material_mask & 00400000) || (A5 == 00000080))
    {
        material_go_only_down = 1;
    }
    else
    {
        material_go_only_down = 0;
    }



    triangle_check_count = 0;

    L7b68c:	; 8007B68C
        current_triangle_id = triangle_id;

        V0 = h[walkmesh_triangle_data + triangle_id * e + 00];
        a_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 02];
        b_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        V0 = h[walkmesh_triangle_data + triangle_id * e + 04];
        c_x_z = (h[walkmesh_vertex_data + V0 * 8 + 00] << 10) + h[walkmesh_vertex_data + V0 * 8 + 04];

        A0 = a_x_z;
        A1 = b_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;
        S2 = V0 >>> 1f;

        A0 = b_x_z;
        A1 = c_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;

        if (V0 < 0)
        {
            S2 = S2 | 2;
        }

        A0 = c_x_z;
        A1 = a_x_z;
        A2 = ending_point_x_z;
        system_side_of_vector;

        if (V0 < 0)
        {
            S2 = S2 | 4;
        }

        switch (S2)
        {
            case 0: // we not cross anything
            {
                triangle_check_count = ff;
            }
            break;

            case 1:
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 06];
            }

            case 2:
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + 08];
            }
            break;

            case 3:
            {
                A0 = b_x_z;
                A1 = ending_point_x_z;
                A2 = start_x_z;
                system_side_of_vector;

                if (V0 >= 0)
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                    S2 = 2;
                }
                else
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                    S2 = 1;
                }
            }
            break;

            case 4:
            {
                triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
            }
            break;

            case 5:
            {
                A0 = a_x_z;
                A1 = ending_point_x_z;
                A2 = start_x_z;
                system_side_of_vector;

                if (V0 >= 0)
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 6];
                    S2 = 1;
                }
                else
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                    S2 = 4;
                }
            }
            break;

            case 6:
            {
                A0 = c_x_z;
                A1 = ending_point_x_z;
                A2 = start_x_z;
                system_side_of_vector;

                if (V0 >= 0)
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + a];
                    S2 = 4;
                }
                else
                {
                    triangle_id = h[walkmesh_triangle_data + triangle_id * e + 8];
                    S2 = 2;
                }
            }
            break;

            case 7:
            {
                triangle_id = -1;
            }
            break;
        }

        if (triangle_id == -1)
        {
            break;
        }

        material_id = bu[walkmesh_triangle_data + triangle_id * e + c];
        material = w[walkmesh_material_data + material_id * 4];

        [A6] = w(material & material_mask);
        type_of_unpassability = (w[A6] >> 5)

        type_of_entity = ((w[entity_structure + 0] & 00000700) >> 8);

        if ((type_of_entity & type_of_unpassability) || ((w[A6] & 10000000) && (walkmesh_id == 0)))
        {
            triangle_id = -1;
        }
        else if ((w[A6] & 00400000) && material_go_only_down == 0) // we check both triangles start and end.
        {
            A0 = h[walkmesh_triangle_data + triangle_id * e + 0];
            A1 = h[walkmesh_triangle_data + triangle_id * e + 2];
            A2 = h[walkmesh_triangle_data + triangle_id * e + 4];

            A0 = walkmesh_vertex_data + A0 * 8;
            A1 = walkmesh_vertex_data + A1 * 8;
            A2 = walkmesh_vertex_data + A2 * 8;
            A3 = A4;
            [SP + 10] = w(SP + 18);
            field_calculate_walkmesh_height;

            new_y = h[A4 + 2];

            if (new_y < (start_y >> 10)) // Y is less on top
            {
                triangle_id = -1;
            }
        }

        if (triangle_id == -1)
        {
            break;
        }

        triangle_check_count = triangle_check_count + 1;
        V0 = triangle_check_count < 20;
    8007B970	bne    v0, zero, L7b68c [$8007b68c]



    if (triangle_id != -1 && triangle_check_count != 20)
    {
        if (A5 != -1)
        {
            A0 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 0] * 8;
            A1 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 2] * 8;
            A2 = walkmesh_vertex_data + h[walkmesh_triangle_data + triangle_id * e + 4] * 8;
            A3 = A4; // pos
            [SP + 10] = w(SP + 18); // address to store normal
            field_calculate_walkmesh_height;
        }
        return 0;
    }



    if (S2 == 1)
    {
        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
        [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
        [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
    }
    else if (S2 == 2)
    {
        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 2];
        [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
        [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
    }
    else if (S2 == 4)
    {
        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 4];
        [intersect_line + 0] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + 2] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + 4] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);

        V0 = h[walkmesh_triangle_data + current_triangle_id * e + 0];
        [intersect_line + 8] = h(hu[walkmesh_vertex_data + V0 * 8 + 0]);
        [intersect_line + a] = h(hu[walkmesh_vertex_data + V0 * 8 + 2]);
        [intersect_line + c] = h(hu[walkmesh_vertex_data + V0 * 8 + 4]);
    }
}

return -1;
////////////////////////////////



////////////////////////////////
// field_calculate_walkmesh_height
// SP = SP - 58;
A_vec = A0;
B_vec = A1;
C_vec = A2;
P_vec = A3;
S4 = w[SP + 68];

[SP + 30] = w(h[B_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[B_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[B_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 10;
system_normalize_word_vector_T0_T1_T2_to_word;

[SP + 30] = w(h[C_vec + 0] - h[A_vec + 0]);
[SP + 34] = w(h[C_vec + 2] - h[A_vec + 2]);
[SP + 38] = w(h[C_vec + 4] - h[A_vec + 4]);
A0 = SP + 30;
A1 = SP + 20;
system_normalize_word_vector_T0_T1_T2_to_word;

A0 = SP + 10;
A1 = SP + 20;
A2 = S4; // normal
system_outer_product2_A0_A1_to_A2;

if (w[S4 + 4] == 0)
{
    [P_vec + 2] = h(0);
}
else
{
    [P_vec + 2] = h(hu[A_vec + 2] - (w[S4 + 0] * (h[P_vec + 0] - h[A_vec + 0]) + w[S4 + 8] * (h[P_vec + 4] - h[A_vec + 4])) / w[S4 + 4]);
}
////////////////////////////////



////////////////////////////////
// field_get_move_vector_to_move_along_with_line
// A0 - rotation;
// A1 - intersect_line;
// A2 - move_vector

intersect_line = A1;
move_vector = A2;

S1 = (c00 - A0) & fff;

A0 = h[intersect_line + c] - h[intersect_line + 4];
A1 = h[intersect_line + 8] - h[intersect_line + 0];
system_get_rotation_based_on_vector_x_y;

A0 = (0 - V0) & fff; // rotation along line that we can't intersect 

S1 = (S1 + A0) & fff;

if ((S1 - 80) >= f01)
{
    [move_vector + 0] = w(0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(0);

    return A0;
}
else
{
    if (S1 < 800)
    {
        [SP + 10] = w(h[intersect_line + 0] - h[intersect_line + 8]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + 4] - h[intersect_line + c]);

        A0 = A0 + 800;
    }
    else
    {
        [SP + 10] = w(h[intersect_line + 8] - h[intersect_line + 0]);
        [SP + 14] = w(0);
        [SP + 18] = w(h[intersect_line + c] - h[intersect_line + 4]);
    }

    S3 = A0 & fff;

    A0 = SP + 10;
    A1 = SP + 20;
    system_normalize_word_vector_T0_T1_T2_to_word;

    A0 = w[move_vector + 0] >> c;
    A1 = w[move_vector + 8] >> c;
    length_of_vector_by_x_y;

    [move_vector + 0] = w(w[SP + 20] * V0);
    [move_vector + 4] = w(0);
    [move_vector + 8] = w(w[SP + 28] * V0);

    return S3;
}
////////////////////////////////