funca7a48:	; 800A7A48
800A7A48	addiu  sp, sp, $ffe8 (=-$18)
800A7A4C	sw     ra, $0014(sp)
800A7A50	jal    funca8198 [$800a8198]
800A7A54	sw     s0, $0010(sp)
800A7A58	lui    s0, $8006

loopa7a5c:	; 800A7A5C
800A7A5C	lw     v0, $794c(s0)
800A7A60	nop
800A7A64	lw     v0, $001c(v0)
800A7A68	nop
800A7A6C	lh     a0, $003a(v0)
800A7A70	jal    funca7aac [$800a7aac]
800A7A74	nop
800A7A78	lw     v0, $794c(s0)
800A7A7C	nop
800A7A80	lw     v0, $0000(v0)
800A7A84	nop
800A7A88	andi   v0, v0, $0003
800A7A8C	beq    v0, zero, loopa7a5c [$800a7a5c]
800A7A90	nop
800A7A94	jal    funca82f8 [$800a82f8]
800A7A98	nop
800A7A9C	lw     ra, $0014(sp)
800A7AA0	lw     s0, $0010(sp)
800A7AA4	jr     ra 
800A7AA8	addiu  sp, sp, $0018


funca7aac:	; 800A7AAC
800A7AAC	addiu  sp, sp, $ffe8 (=-$18)
800A7AB0	sw     ra, $0014(sp)
800A7AB4	jal    funca85f4 [$800a85f4]
800A7AB8	sw     s0, $0010(sp)
800A7ABC	lui    s0, $8006

loopa7ac0:	; 800A7AC0
800A7AC0	lw     v0, $794c(s0)
800A7AC4	nop
800A7AC8	lw     v0, $001c(v0)
800A7ACC	nop
800A7AD0	lh     a0, $000c(v0)
800A7AD4	jal    funca7b10 [$800a7b10]
800A7AD8	nop
800A7ADC	lw     v0, $794c(s0)
800A7AE0	nop
800A7AE4	lw     v0, $0000(v0)
800A7AE8	nop
800A7AEC	andi   v0, v0, $0007
800A7AF0	beq    v0, zero, loopa7ac0 [$800a7ac0]
800A7AF4	nop
800A7AF8	jal    funca8698 [$800a8698]
800A7AFC	nop
800A7B00	lw     ra, $0014(sp)
800A7B04	lw     s0, $0010(sp)
800A7B08	jr     ra 
800A7B0C	addiu  sp, sp, $0018


funca7b10:	; 800A7B10
800A7B10	addiu  sp, sp, $ffe0 (=-$20)
800A7B14	sw     ra, $0018(sp)
800A7B18	sw     s1, $0014(sp)
800A7B1C	jal    funca89c4 [$800a89c4]
800A7B20	sw     s0, $0010(sp)
800A7B24	jal    func1300c [$8001300c]
800A7B28	addiu  a0, zero, $0001
800A7B2C	lui    s0, $8006
800A7B30	addiu  s1, s0, $794c

La7b34:	; 800A7B34
800A7B34	jal    funcae788 [$800ae788]
800A7B38	nop
800A7B3C	jal    func19194 [$80019194]
800A7B40	nop
800A7B44	lui    v0, $8007
800A7B48	lw     v0, $3990(v0)
800A7B4C	lui    v1, $0400
800A7B50	and    v0, v0, v1
800A7B54	beq    v0, zero, La7b88 [$800a7b88]
800A7B58	lui    v0, $8007
800A7B5C	lw     v1, $39a0(v0)
800A7B60	nop
800A7B64	andi   v0, v1, $00f8
800A7B68	beq    v0, zero, La7b88 [$800a7b88]
800A7B6C	lui    v0, $00fe
800A7B70	ori    v0, v0, $0001
800A7B74	and    v0, v1, v0
800A7B78	bne    v0, zero, La7b88 [$800a7b88]
800A7B7C	nop
800A7B80	jal    funcaf740 [$800af740]
800A7B84	nop

La7b88:	; 800A7B88
800A7B88	lw     v0, $794c(s0)
800A7B8C	nop
800A7B90	lw     v0, $001c(v0)
800A7B94	nop
800A7B98	lw     v0, $0000(v0)
800A7B9C	nop
800A7BA0	andi   v0, v0, $0100
800A7BA4	bne    v0, zero, La8030 [$800a8030]
800A7BA8	nop
800A7BAC	jal    funcadb74 [$800adb74]
800A7BB0	nop
800A7BB4	lw     v0, $794c(s0)
800A7BB8	nop
800A7BBC	lw     a2, $001c(v0)
800A7BC0	nop
800A7BC4	lw     a1, $0000(a2)
800A7BC8	nop
800A7BCC	andi   v0, a1, $0001
800A7BD0	bne    v0, zero, La7c28 [$800a7c28]
800A7BD4	lui    v0, $8007
800A7BD8	lw     v0, $3990(v0)
800A7BDC	lui    v1, $0004
800A7BE0	and    v0, v0, v1
800A7BE4	beq    v0, zero, La7c28 [$800a7c28]
800A7BE8	lui    v0, $8007
800A7BEC	lw     a0, $39a0(v0)
800A7BF0	ori    v1, v1, $00f0
800A7BF4	and    v1, a0, v1
800A7BF8	beq    v1, zero, La7c28 [$800a7c28]
800A7BFC	lui    v0, $04fa
800A7C00	ori    v0, v0, $0009
800A7C04	and    v0, a0, v0
800A7C08	bne    v0, zero, La7c28 [$800a7c28]
800A7C0C	ori    v0, a1, $0002
800A7C10	sw     v0, $0000(a2)
800A7C14	addu   a0, zero, zero
800A7C18	jal    func32120 [$80032120]
800A7C1C	addu   a1, a0, zero
800A7C20	jal    func4a9e8 [$8004a9e8]
800A7C24	nop

La7c28:	; 800A7C28
800A7C28	lw     v0, $794c(s0)
800A7C2C	nop
800A7C30	lw     v0, $001c(v0)
800A7C34	nop
800A7C38	lw     v0, $0000(v0)
800A7C3C	nop
800A7C40	andi   v0, v0, $0002
800A7C44	bne    v0, zero, La7da8 [$800a7da8]
800A7C48	nop
800A7C4C	jal    func4bc38 [$8004bc38]
800A7C50	nop
800A7C54	addiu  v1, v0, $fffd (=-$3)
800A7C58	sltiu  v0, v1, $0006
800A7C5C	beq    v0, zero, La7da8 [$800a7da8]
800A7C60	lui    v0, $800a
800A7C64	addiu  v0, v0, $7004
800A7C68	sll    v1, v1, $02
800A7C6C	addu   v1, v1, v0
800A7C70	lw     v0, $0000(v1)
800A7C74	nop
800A7C78	jr     v0 
800A7C7C	nop

800A7C80	lw     v0, $794c(s0)
800A7C84	nop
800A7C88	lw     v0, $001c(v0)
800A7C8C	nop
800A7C90	lw     v0, $08e4(v0)
800A7C94	nop
800A7C98	lw     v0, $000c(v0)
800A7C9C	nop
800A7CA0	lw     v1, $0014(v0)
800A7CA4	addiu  v0, zero, $0002
800A7CA8	jal    funcaed04 [$800aed04]
800A7CAC	sb     v0, $004a(v1)
800A7CB0	j      La7da8 [$800a7da8]
800A7CB4	nop
800A7CB8	lw     a0, $794c(s0)
800A7CBC	nop
800A7CC0	lw     v0, $001c(a0)
800A7CC4	nop
800A7CC8	lw     v0, $08e4(v0)
800A7CCC	nop
800A7CD0	lw     v0, $000c(v0)
800A7CD4	nop
800A7CD8	lw     a1, $0014(v0)
800A7CDC	nop
800A7CE0	lh     v1, $000a(a1)
800A7CE4	addiu  v0, zero, $3e80
800A7CE8	bne    v1, v0, La7cf8 [$800a7cf8]
800A7CEC	addiu  v0, zero, $0004
800A7CF0	j      La7d90 [$800a7d90]
800A7CF4	sb     v0, $004a(a1)

La7cf8:	; 800A7CF8
800A7CF8	lw     v0, $0000(a0)
800A7CFC	nop
800A7D00	ori    v0, v0, $0008
800A7D04	j      La7da8 [$800a7da8]
800A7D08	sw     v0, $0000(a0)
800A7D0C	lw     v0, $794c(s0)
800A7D10	nop
800A7D14	lw     v0, $001c(v0)
800A7D18	nop
800A7D1C	lw     v0, $08e4(v0)
800A7D20	nop
800A7D24	lw     v0, $000c(v0)
800A7D28	nop
800A7D2C	lw     v1, $0014(v0)
800A7D30	j      La7d8c [$800a7d8c]
800A7D34	addiu  v0, zero, $0003
800A7D38	lw     v0, $794c(s0)
800A7D3C	nop
800A7D40	lw     v0, $001c(v0)
800A7D44	nop
800A7D48	lw     v0, $08e4(v0)
800A7D4C	nop
800A7D50	lw     v0, $000c(v0)
800A7D54	nop
800A7D58	lw     v1, $0014(v0)
800A7D5C	j      La7d8c [$800a7d8c]
800A7D60	addiu  v0, zero, $0009
800A7D64	lw     v0, $794c(s0)

La7d68:	; 800A7D68
800A7D68	nop
800A7D6C	lw     v0, $001c(v0)

La7d70:	; 800A7D70
800A7D70	nop
800A7D74	lw     v0, $08e4(v0)

La7d78:	; 800A7D78
800A7D78	nop
800A7D7C	lw     v0, $000c(v0)

La7d80:	; 800A7D80
800A7D80	nop
800A7D84	lw     v1, $0014(v0)

La7d88:	; 800A7D88
800A7D88	addiu  v0, zero, $0007

La7d8c:	; 800A7D8C
800A7D8C	sb     v0, $004a(v1)

La7d90:	; 800A7D90
800A7D90	lw     v1, $794c(s0)
800A7D94	nop
800A7D98	lw     v0, $0000(v1)
800A7D9C	nop
800A7DA0	ori    v0, v0, $0002
800A7DA4	sw     v0, $0000(v1)

La7da8:	; 800A7DA8
800A7DA8	lw     v0, $794c(s0)
800A7DAC	nop
800A7DB0	lw     v0, $001c(v0)
800A7DB4	nop
800A7DB8	lw     v0, $0000(v0)
800A7DBC	nop
800A7DC0	andi   v0, v0, $0001
800A7DC4	bne    v0, zero, La7dd4 [$800a7dd4]
800A7DC8	nop
800A7DCC	jal    func32100 [$80032100]
800A7DD0	nop

La7dd4:	; 800A7DD4
800A7DD4	lw     a0, $794c(s0)
800A7DD8	nop
800A7DDC	lw     a1, $0000(a0)
800A7DE0	lui    v0, $0010
800A7DE4	and    v0, a1, v0
800A7DE8	beq    v0, zero, La7e14 [$800a7e14]
800A7DEC	ori    v0, a1, $0008
800A7DF0	lw     v1, $001c(a0)
800A7DF4	sw     v0, $0000(a0)
800A7DF8	lw     a0, $08e4(v1)
800A7DFC	nop
800A7E00	lw     v0, $0000(a0)
800A7E04	lui    v1, $0001
800A7E08	or     v0, v0, v1
800A7E0C	j      La8054 [$800a8054]
800A7E10	sw     v0, $0000(a0)

La7e14:	; 800A7E14
800A7E14	lw     v0, $001c(a0)
800A7E18	nop
800A7E1C	lw     v0, $0000(v0)
800A7E20	nop
800A7E24	andi   v0, v0, $0008
800A7E28	bne    v0, zero, La7e38 [$800a7e38]
800A7E2C	nop
800A7E30	jal    funcbfee0 [$800bfee0]
800A7E34	nop

La7e38:	; 800A7E38
800A7E38	lw     v0, $794c(s0)
800A7E3C	nop
800A7E40	lw     v0, $001c(v0)
800A7E44	nop
800A7E48	lw     v0, $0000(v0)
800A7E4C	nop
800A7E50	andi   v0, v0, $0004
800A7E54	bne    v0, zero, La7e64 [$800a7e64]
800A7E58	nop
800A7E5C	jal    funcab3cc [$800ab3cc]
800A7E60	nop

La7e64:	; 800A7E64
800A7E64	lw     v0, $794c(s0)
800A7E68	nop
800A7E6C	lw     v0, $001c(v0)
800A7E70	nop
800A7E74	lw     v0, $08e4(v0)
800A7E78	nop
800A7E7C	lw     v0, $0000(v0)
800A7E80	nop
800A7E84	andi   v0, v0, $0008
800A7E88	bne    v0, zero, La7ea0 [$800a7ea0]
800A7E8C	nop
800A7E90	jal    funcc60f0 [$800c60f0]
800A7E94	nop
800A7E98	jal    funcc7100 [$800c7100]
800A7E9C	nop

La7ea0:	; 800A7EA0
800A7EA0	lw     v0, $794c(s0)
800A7EA4	nop
800A7EA8	lw     v0, $001c(v0)
800A7EAC	nop
800A7EB0	lw     v0, $08e4(v0)
800A7EB4	nop
800A7EB8	lw     v0, $0000(v0)
800A7EBC	nop
800A7EC0	andi   v0, v0, $0010
800A7EC4	bne    v0, zero, La7ed4 [$800a7ed4]
800A7EC8	nop
800A7ECC	jal    func54b78 [$80054b78]
800A7ED0	nop

La7ed4:	; 800A7ED4
800A7ED4	lw     v0, $794c(s0)
800A7ED8	nop
800A7EDC	lw     v0, $001c(v0)
800A7EE0	nop
800A7EE4	lw     v0, $0000(v0)
800A7EE8	nop
800A7EEC	andi   v0, v0, $0010
800A7EF0	bne    v0, zero, La7f00 [$800a7f00]
800A7EF4	nop
800A7EF8	jal    funcafde8 [$800afde8]
800A7EFC	nop

La7f00:	; 800A7F00
800A7F00	lw     v0, $794c(s0)
800A7F04	nop
800A7F08	lw     v0, $001c(v0)
800A7F0C	nop
800A7F10	lw     v0, $0000(v0)
800A7F14	nop
800A7F18	andi   v0, v0, $0008
800A7F1C	bne    v0, zero, La7f2c [$800a7f2c]
800A7F20	nop
800A7F24	jal    funcb3684 [$800b3684]
800A7F28	nop

La7f2c:	; 800A7F2C
800A7F2C	lw     v0, $794c(s0)
800A7F30	nop
800A7F34	lw     v0, $001c(v0)
800A7F38	nop
800A7F3C	lw     v0, $08e4(v0)
800A7F40	nop
800A7F44	lw     v0, $0000(v0)
800A7F48	nop
800A7F4C	andi   v0, v0, $0001
800A7F50	bne    v0, zero, La7f60 [$800a7f60]
800A7F54	nop
800A7F58	jal    func23a0c [$80023a0c]
800A7F5C	nop

La7f60:	; 800A7F60
800A7F60	lw     v0, $794c(s0)
800A7F64	nop
800A7F68	lw     v0, $001c(v0)
800A7F6C	nop
800A7F70	lw     v0, $08e4(v0)
800A7F74	nop
800A7F78	lw     v0, $0000(v0)
800A7F7C	nop
800A7F80	andi   v0, v0, $0800
800A7F84	bne    v0, zero, La7f94 [$800a7f94]
800A7F88	nop
800A7F8C	jal    func32098 [$80032098]
800A7F90	nop

La7f94:	; 800A7F94
800A7F94	lw     v0, $0000(s1)
800A7F98	nop
800A7F9C	lw     v0, $001c(v0)
800A7FA0	nop
800A7FA4	lw     v0, $08e4(v0)
800A7FA8	nop
800A7FAC	lw     v0, $0000(v0)
800A7FB0	nop
800A7FB4	andi   v0, v0, $0004
800A7FB8	bne    v0, zero, La7fc8 [$800a7fc8]
800A7FBC	nop
800A7FC0	jal    funcaed6c [$800aed6c]
800A7FC4	nop

La7fc8:	; 800A7FC8
800A7FC8	lw     v0, $0000(s1)
800A7FCC	nop
800A7FD0	lw     v0, $001c(v0)
800A7FD4	nop
800A7FD8	lw     v0, $08e4(v0)
800A7FDC	nop
800A7FE0	lw     v0, $0000(v0)
800A7FE4	nop
800A7FE8	andi   v0, v0, $0080
800A7FEC	bne    v0, zero, La7ffc [$800a7ffc]
800A7FF0	nop
800A7FF4	jal    func23a4c [$80023a4c]
800A7FF8	nop

La7ffc:	; 800A7FFC
800A7FFC	lw     v0, $0000(s1)
800A8000	nop
800A8004	lw     v0, $001c(v0)
800A8008	nop
800A800C	lw     v0, $08e4(v0)
800A8010	nop
800A8014	lw     v0, $0000(v0)
800A8018	nop
800A801C	andi   v0, v0, $1000
800A8020	bne    v0, zero, La8030 [$800a8030]
800A8024	nop

La8028:	; 800A8028
800A8028	jal    func2246c [$8002246c]
800A802C	nop

La8030:	; 800A8030
800A8030	jal    funcae930 [$800ae930]
800A8034	nop
800A8038	lw     v0, $794c(s0)
800A803C	nop
800A8040	lw     v0, $0000(v0)
800A8044	nop
800A8048	andi   v0, v0, $000f
800A804C	beq    v0, zero, La7b34 [$800a7b34]
800A8050	nop

La8054:	; 800A8054
800A8054	jal    funcb4f9c [$800b4f9c]
800A8058	nop
800A805C	beq    v0, zero, La806c [$800a806c]
800A8060	nop
800A8064	jal    funcb4a5c [$800b4a5c]
800A8068	nop

La806c:	; 800A806C
800A806C	jal    funcb54cc [$800b54cc]
800A8070	nop
800A8074	andi   v0, v0, $00ff
800A8078	beq    v0, zero, La8088 [$800a8088]
800A807C	nop
800A8080	jal    funcb50a4 [$800b50a4]
800A8084	nop

La8088:	; 800A8088
800A8088	jal    funca8e58 [$800a8e58]
800A808C	nop
800A8090	lw     ra, $0018(sp)
800A8094	lw     s1, $0014(sp)
800A8098	lw     s0, $0010(sp)
800A809C	jr     ra 
800A80A0	addiu  sp, sp, $0020


funca80a4:	; 800A80A4
800A80A4	addiu  sp, sp, $ffe0 (=-$20)
800A80A8	sw     s0, $0018(sp)
800A80AC	lui    s0, $8006
800A80B0	lw     v0, $794c(s0)
800A80B4	sw     ra, $001c(sp)
800A80B8	lw     v0, $001c(v0)
800A80BC	nop
800A80C0	lw     v0, $08e4(v0)
800A80C4	nop
800A80C8	lw     v0, $000c(v0)
800A80CC	nop
800A80D0	lw     v0, $0014(v0)
800A80D4	nop
800A80D8	lw     a0, $000c(v0)
800A80DC	jal    func1f3488 [$801f3488]
800A80E0	nop
800A80E4	lw     v0, $794c(s0)
800A80E8	nop
800A80EC	sb     zero, $0008(v0)
800A80F0	lw     v1, $794c(s0)
800A80F4	lui    a0, $0010
800A80F8	lw     v0, $0000(v1)
800A80FC	lw     a1, $001c(v1)
800A8100	or     v0, v0, a0
800A8104	sw     v0, $0000(v1)
800A8108	lw     v0, $0000(a1)
800A810C	lui    v1, $2000
800A8110	and    v0, v0, v1
800A8114	beq    v0, zero, La8178 [$800a8178]
800A8118	ori    v0, zero, $ffff
800A811C	lhu    v1, $081c(a1)
800A8120	nop
800A8124	beq    v1, v0, La8178 [$800a8178]
800A8128	ori    a0, zero, $8301
800A812C	addiu  a2, zero, $001e
800A8130	addu   a3, zero, zero
800A8134	addu   a1, v1, zero
800A8138	addiu  s0, zero, $001d
800A813C	jal    funcb0124 [$800b0124]
800A8140	sw     zero, $0010(sp)

loopa8144:	; 800A8144
800A8144	jal    func15c58 [$80015c58]
800A8148	addu   a0, zero, zero
800A814C	addiu  s0, s0, $ffff (=-$1)
800A8150	bgez   s0, loopa8144 [$800a8144]
800A8154	lui    v0, $8006
800A8158	lw     v0, $794c(v0)
800A815C	addiu  a0, zero, $0100
800A8160	lw     v0, $001c(v0)
800A8164	addu   a2, zero, zero
800A8168	lhu    a1, $081c(v0)
800A816C	addu   a3, a2, zero
800A8170	jal    funcb0124 [$800b0124]
800A8174	sw     zero, $0010(sp)

La8178:	; 800A8178
800A8178	lui    v1, $8006
800A817C	lhu    v0, $7950(v1)
800A8180	lw     ra, $001c(sp)
800A8184	lw     s0, $0018(sp)
800A8188	addiu  v0, v0, $0001
800A818C	sh     v0, $7950(v1)
800A8190	jr     ra 
800A8194	addiu  sp, sp, $0020


funca8198:	; 800A8198
800A8198	addiu  sp, sp, $ffd8 (=-$28)
800A819C	sw     ra, $0020(sp)
800A81A0	sw     s1, $001c(sp)
800A81A4	jal    funca8344 [$800a8344]
800A81A8	sw     s0, $0018(sp)
800A81AC	lui    s0, $8006
800A81B0	lw     v0, $794c(s0)
800A81B4	nop
800A81B8	lw     v0, $001c(v0)
800A81BC	nop
800A81C0	lw     s1, $08e4(v0)
800A81C4	jal    funca8380 [$800a8380]
800A81C8	nop
800A81CC	addiu  a0, zero, $00e0
800A81D0	lw     v1, $794c(s0)
800A81D4	addiu  v0, zero, $0002
800A81D8	jal    func1cd04 [$8001cd04]
800A81DC	sb     v0, $0009(v1)
800A81E0	jal    func1cfb4 [$8001cfb4]
800A81E4	nop
800A81E8	jal    func1300c [$8001300c]
800A81EC	addiu  a0, zero, $0001
800A81F0	addu   a0, zero, zero
800A81F4	lw     a1, $794c(s0)
800A81F8	lui    v0, $800b
800A81FC	lw     v1, $001c(a1)
800A8200	addiu  v0, v0, $ab30 (=-$54d0)
800A8204	sw     v0, $0838(v1)
800A8208	lui    v0, $800b
800A820C	lw     v1, $001c(a1)
800A8210	addiu  v0, v0, $0124
800A8214	sw     v0, $083c(v1)
800A8218	lui    v0, $800b
800A821C	lw     v1, $001c(a1)
800A8220	addiu  v0, v0, $36e0
800A8224	jal    func21cdc [$80021cdc]
800A8228	sw     v0, $08bc(v1)
800A822C	lw     v1, $794c(s0)
800A8230	addiu  a0, zero, $fff8 (=-$8)
800A8234	lw     v0, $0000(v1)
800A8238	lw     a1, $001c(v1)
800A823C	and    v0, v0, a0
800A8240	sw     v0, $0000(v1)
800A8244	sw     zero, $084c(a1)
800A8248	lw     v0, $001c(v1)
800A824C	nop
800A8250	sb     zero, $0039(v0)
800A8254	sb     zero, $0038(v0)
800A8258	lw     v0, $794c(s0)
800A825C	nop
800A8260	lw     v1, $001c(v0)
800A8264	ori    v0, zero, $ffff
800A8268	sh     v0, $0836(v1)
800A826C	jal    funcb1d60 [$800b1d60]
800A8270	sh     v0, $0834(v1)
800A8274	jal    funcac5f0 [$800ac5f0]
800A8278	nop
800A827C	jal    funca847c [$800a847c]
800A8280	nop
800A8284	jal    funca83e0 [$800a83e0]
800A8288	nop
800A828C	jal    func239d0 [$800239d0]
800A8290	nop
800A8294	lw     v0, $794c(s0)
800A8298	nop
800A829C	lw     v0, $001c(v0)
800A82A0	nop
800A82A4	lw     v0, $0000(v0)
800A82A8	lui    v1, $0040
800A82AC	and    v0, v0, v1
800A82B0	beq    v0, zero, La82cc [$800a82cc]
800A82B4	ori    a0, zero, $8601
800A82B8	sw     zero, $0010(sp)
800A82BC	addu   a1, zero, zero
800A82C0	addiu  a2, zero, $0078
800A82C4	jal    funcb0124 [$800b0124]
800A82C8	addu   a3, a1, zero

La82cc:	; 800A82CC
800A82CC	jal    func2fc30 [$8002fc30]
800A82D0	nop
800A82D4	lui    v0, $8006
800A82D8	lw     v0, $7948(v0)
800A82DC	nop
800A82E0	sw     v0, $0004(s1)
800A82E4	lw     ra, $0020(sp)
800A82E8	lw     s1, $001c(sp)
800A82EC	lw     s0, $0018(sp)
800A82F0	jr     ra 
800A82F4	addiu  sp, sp, $0028


funca82f8:	; 800A82F8
800A82F8	addiu  sp, sp, $ffe8 (=-$18)
800A82FC	sw     ra, $0010(sp)
800A8300	addiu  v1, zero, $0001
800A8304	lui    v0, $8007
800A8308	addiu  v0, v0, $39b0
800A830C	addiu  v0, v0, $0002

loopa8310:	; 800A8310
800A8310	sb     zero, $0001(v0)
800A8314	sb     zero, $0000(v0)
800A8318	addiu  v1, v1, $ffff (=-$1)
800A831C	bgez   v1, loopa8310 [$800a8310]
800A8320	addiu  v0, v0, $fffe (=-$2)
800A8324	jal    funcb1ce4 [$800b1ce4]
800A8328	nop
800A832C	jal    funca8588 [$800a8588]
800A8330	nop
800A8334	lw     ra, $0010(sp)
800A8338	nop
800A833C	jr     ra 
800A8340	addiu  sp, sp, $0018


funca8344:	; 800A8344
800A8344	lui    a0, $0002
800A8348	ori    a0, a0, $8000
800A834C	lui    v0, $8006
800A8350	lui    a1, $8006
800A8354	lw     v1, $7944(v0)
800A8358	lui    v0, $8006
800A835C	lw     v0, $794c(v0)
800A8360	addu   v1, v1, a0
800A8364	addiu  a0, v1, $2000
800A8368	lw     v0, $001c(v0)
800A836C	addiu  v1, v1, $2050
800A8370	sw     a0, $7948(a1)
800A8374	sw     v1, $7948(a1)
800A8378	jr     ra 
800A837C	sw     a0, $08e4(v0)


funca8380:	; 800A8380
800A8380	lui    v0, $8006
800A8384	lw     v0, $794c(v0)
800A8388	nop
800A838C	lw     v0, $001c(v0)
800A8390	addiu  a0, zero, $002b
800A8394	lw     v1, $08e4(v0)
800A8398	addiu  v0, zero, $ffff (=-$1)
800A839C	sh     v0, $000a(v1)
800A83A0	addiu  v0, zero, $ffff (=-$1)
800A83A4	sw     zero, $0000(v1)
800A83A8	sw     zero, $0004(v1)
800A83AC	sb     zero, $0008(v1)
800A83B0	sb     zero, $0009(v1)
800A83B4	sw     v0, $0014(v1)
800A83B8	sw     v0, $0018(v1)
800A83BC	sw     v0, $0020(v1)
800A83C0	sw     zero, $0010(v1)
800A83C4	sw     zero, $000c(v1)

loopa83c8:	; 800A83C8
800A83C8	addu   v0, v1, a0
800A83CC	addiu  a0, a0, $ffff (=-$1)
800A83D0	bgez   a0, loopa83c8 [$800a83c8]
800A83D4	sb     zero, $0024(v0)
800A83D8	jr     ra 
800A83DC	nop


funca83e0:	; 800A83E0
800A83E0	addiu  sp, sp, $ffe8 (=-$18)
800A83E4	addiu  a0, zero, $0004
800A83E8	lui    a1, $0009
800A83EC	ori    a1, a1, $0164
800A83F0	addu   a2, zero, zero
800A83F4	sw     ra, $0014(sp)
800A83F8	jal    func1c7fc [$8001c7fc]
800A83FC	sw     s0, $0010(sp)
800A8400	addiu  a0, zero, $0005
800A8404	lui    a1, $0009
800A8408	ori    a1, a1, $0164
800A840C	addu   a2, zero, zero
800A8410	jal    func1c7fc [$8001c7fc]
800A8414	addu   s0, v0, zero
800A8418	lui    v1, $0014
800A841C	ori    v1, v1, $6f00
800A8420	addu   a1, s0, zero
800A8424	addu   s0, v0, zero
800A8428	lui    v0, $8006
800A842C	addu   a2, s0, zero
800A8430	lw     a0, $7944(v0)
800A8434	addu   a3, zero, zero
800A8438	jal    func1daa4 [$8001daa4]
800A843C	addu   a0, a0, v1
800A8440	jal    func130a4 [$800130a4]
800A8444	addu   a0, zero, zero
800A8448	lui    v0, $8006
800A844C	lw     v0, $794c(v0)
800A8450	nop
800A8454	lw     v0, $001c(v0)
800A8458	nop
800A845C	lw     v1, $08e4(v0)
800A8460	nop
800A8464	sw     s0, $0020(v1)
800A8468	lw     ra, $0014(sp)
800A846C	lw     s0, $0010(sp)
800A8470	addu   v0, zero, zero
800A8474	jr     ra 
800A8478	addiu  sp, sp, $0018


funca847c:	; 800A847C
800A847C	addiu  sp, sp, $ffd8 (=-$28)
800A8480	addiu  a0, zero, $2714
800A8484	sw     ra, $0024(sp)
800A8488	jal    func220e8 [$800220e8]
800A848C	sw     s0, $0020(sp)
800A8490	beq    v0, zero, La84d0 [$800a84d0]
800A8494	addiu  a0, zero, $0001
800A8498	jal    func21e5c [$80021e5c]
800A849C	addiu  a0, zero, $2714
800A84A0	lui    v1, $8006
800A84A4	lw     a0, $7948(v1)
800A84A8	lw     a1, $0008(v0)
800A84AC	lw     a2, $000c(v0)
800A84B0	jal    func1daa4 [$8001daa4]
800A84B4	addu   a3, zero, zero
800A84B8	jal    func22390 [$80022390]
800A84BC	addiu  a0, zero, $2714
800A84C0	jal    func130a4 [$800130a4]
800A84C4	addu   a0, zero, zero
800A84C8	j      La8538 [$800a8538]
800A84CC	lui    v0, $8006

La84d0:	; 800A84D0
800A84D0	jal    func1e218 [$8001e218]
800A84D4	addiu  a1, zero, $2714
800A84D8	lui    v1, $8006
800A84DC	addu   s0, v1, zero
800A84E0	lui    v1, $8006
800A84E4	lw     a3, $7948(v1)
800A84E8	lw     a2, $000c(v0)
800A84EC	lw     v1, $0004(v0)
800A84F0	lw     a0, $794c(s0)
800A84F4	subu   a2, a2, v1
800A84F8	sll    a2, a2, $0b
800A84FC	lw     a0, $001c(a0)
800A8500	addiu  v1, zero, $ffff (=-$1)
800A8504	sw     zero, $0010(sp)
800A8508	sw     v1, $0014(sp)
800A850C	sw     zero, $0018(sp)
800A8510	lw     a1, $0004(v0)
800A8514	jal    func2177c [$8002177c]
800A8518	addiu  a0, a0, $0854

loopa851c:	; 800A851C
800A851C	lw     v0, $794c(s0)
800A8520	nop
800A8524	lw     a0, $001c(v0)
800A8528	jal    func217c4 [$800217c4]
800A852C	addiu  a0, a0, $0854
800A8530	bne    v0, zero, loopa851c [$800a851c]
800A8534	lui    v0, $8006

La8538:	; 800A8538
800A8538	lw     a1, $794c(v0)
800A853C	nop
800A8540	lw     v0, $001c(a1)
800A8544	lui    v1, $8006
800A8548	lw     a0, $08e4(v0)
800A854C	lw     v0, $7948(v1)
800A8550	nop
800A8554	sw     v0, $0010(a0)
800A8558	lw     v0, $001c(a1)
800A855C	nop
800A8560	lw     v0, $08e4(v0)
800A8564	nop
800A8568	lw     a0, $0010(v0)
800A856C	jal    func1c750 [$8001c750]
800A8570	addu   a1, zero, zero
800A8574	lw     ra, $0024(sp)
800A8578	lw     s0, $0020(sp)
800A857C	addu   v0, zero, zero
800A8580	jr     ra 
800A8584	addiu  sp, sp, $0028


funca8588:	; 800A8588
800A8588	addiu  sp, sp, $ffe8 (=-$18)
800A858C	sw     s0, $0010(sp)
800A8590	lui    s0, $8006
800A8594	lw     v0, $794c(s0)
800A8598	sw     ra, $0014(sp)

funca859c:	; 800A859C
800A859C	lw     v0, $001c(v0)
800A85A0	nop
800A85A4	lw     v0, $08e4(v0)
800A85A8	nop
800A85AC	lw     a0, $0010(v0)
800A85B0	nop
800A85B4	beq    a0, zero, La85e0 [$800a85e0]
800A85B8	nop
800A85BC	jal    func1c784 [$8001c784]
800A85C0	nop
800A85C4	lw     v0, $794c(s0)
800A85C8	nop
800A85CC	lw     v0, $001c(v0)
800A85D0	nop
800A85D4	lw     v0, $08e4(v0)
800A85D8	nop
800A85DC	sw     zero, $0010(v0)

La85e0:	; 800A85E0
800A85E0	lw     ra, $0014(sp)
800A85E4	lw     s0, $0010(sp)
800A85E8	addu   v0, zero, zero
800A85EC	jr     ra 
800A85F0	addiu  sp, sp, $0018


funca85f4:	; 800A85F4
800A85F4	addiu  sp, sp, $ffe0 (=-$20)
800A85F8	sw     s0, $0010(sp)
800A85FC	lui    s0, $8006

funca8600:	; 800A8600
800A8600	lw     v0, $794c(s0)
800A8604	sw     ra, $001c(sp)
800A8608	sw     s2, $0018(sp)
800A860C	sw     s1, $0014(sp)
800A8610	lw     v0, $001c(v0)
800A8614	nop
800A8618	lw     v0, $08e4(v0)
800A861C	addu   s2, a0, zero
800A8620	lw     v0, $0004(v0)
800A8624	lui    s1, $8006
800A8628	jal    funca86fc [$800a86fc]
800A862C	sw     v0, $7948(s1)
800A8630	lw     v0, $794c(s0)
800A8634	nop
800A8638	lw     v0, $001c(v0)
800A863C	nop
800A8640	lw     v0, $08e4(v0)
800A8644	nop
800A8648	lw     s0, $000c(v0)
800A864C	jal    funca8724 [$800a8724]
800A8650	nop
800A8654	jal    func1cfb4 [$8001cfb4]
800A8658	nop
800A865C	addu   a1, s2, zero
800A8660	jal    funca87dc [$800a87dc]
800A8664	addu   a0, s0, zero
800A8668	addu   a0, s0, zero
800A866C	jal    funca879c [$800a879c]
800A8670	addu   a1, s2, zero
800A8674	lw     v0, $7948(s1)
800A8678	nop
800A867C	sw     v0, $0004(s0)
800A8680	lw     ra, $001c(sp)
800A8684	lw     s2, $0018(sp)
800A8688	lw     s1, $0014(sp)
800A868C	lw     s0, $0010(sp)
800A8690	jr     ra 
800A8694	addiu  sp, sp, $0020


funca8698:	; 800A8698
800A8698	addiu  sp, sp, $ffe0 (=-$20)
800A869C	sw     s1, $0014(sp)
800A86A0	lui    s1, $8006
800A86A4	lw     v0, $794c(s1)
800A86A8	sw     ra, $0018(sp)
800A86AC	sw     s0, $0010(sp)
800A86B0	lw     v1, $001c(v0)
800A86B4	nop
800A86B8	lw     v0, $08e4(v1)
800A86BC	nop
800A86C0	lw     s0, $000c(v0)
800A86C4	lh     a1, $003a(v1)
800A86C8	jal    funca8990 [$800a8990]
800A86CC	addu   a0, s0, zero
800A86D0	lw     v0, $794c(s1)
800A86D4	nop
800A86D8	lw     v1, $001c(v0)
800A86DC	lhu    v0, $0010(s0)
800A86E0	nop
800A86E4	sh     v0, $003a(v1)
800A86E8	lw     ra, $0018(sp)
800A86EC	lw     s1, $0014(sp)
800A86F0	lw     s0, $0010(sp)
800A86F4	jr     ra 
800A86F8	addiu  sp, sp, $0020


funca86fc:	; 800A86FC
800A86FC	lui    v0, $8006
800A8700	lw     v0, $794c(v0)
800A8704	lui    a1, $8006
800A8708	lw     v0, $001c(v0)
800A870C	lw     v1, $7948(a1)
800A8710	lw     a0, $08e4(v0)
800A8714	addiu  v0, v1, $0038
800A8718	sw     v0, $7948(a1)
800A871C	jr     ra 
800A8720	sw     v1, $000c(a0)


funca8724:	; 800A8724
800A8724	lui    v0, $8006
800A8728	lw     v1, $794c(v0)
800A872C	nop
800A8730	lw     v0, $001c(v1)
800A8734	nop
800A8738	lw     v0, $08e4(v0)
800A873C	nop
800A8740	lw     a0, $000c(v0)
800A8744	nop
800A8748	sw     zero, $0000(a0)
800A874C	sw     zero, $0004(a0)
800A8750	sw     zero, $0008(a0)
800A8754	sw     zero, $000c(a0)
800A8758	lw     v0, $001c(v1)
800A875C	nop
800A8760	lhu    v0, $003a(v0)
800A8764	addiu  v1, zero, $0001
800A8768	sw     zero, $0014(a0)
800A876C	sh     v0, $0010(a0)

loopa8770:	; 800A8770
800A8770	addu   v0, a0, v1
800A8774	addiu  v1, v1, $ffff (=-$1)
800A8778	bgez   v1, loopa8770 [$800a8770]
800A877C	sb     zero, $0012(v0)
800A8780	addiu  v1, zero, $001f

loopa8784:	; 800A8784
800A8784	addu   v0, a0, v1
800A8788	addiu  v1, v1, $ffff (=-$1)
800A878C	bgez   v1, loopa8784 [$800a8784]
800A8790	sb     zero, $0018(v0)
800A8794	jr     ra 
800A8798	nop


funca879c:	; 800A879C
800A879C	addiu  sp, sp, $ffe8 (=-$18)
800A87A0	sw     s0, $0010(sp)
800A87A4	addu   s0, a0, zero
800A87A8	andi   v0, a1, $ffff
800A87AC	lui    a1, $0006
800A87B0	addiu  a0, zero, $0004
800A87B4	or     a1, v0, a1
800A87B8	sw     ra, $0014(sp)
800A87BC	jal    func1c7fc [$8001c7fc]
800A87C0	addu   a2, zero, zero
800A87C4	sw     v0, $0008(s0)
800A87C8	lw     ra, $0014(sp)
800A87CC	lw     s0, $0010(sp)
800A87D0	addu   v0, zero, zero
800A87D4	jr     ra 
800A87D8	addiu  sp, sp, $0018


funca87dc:	; 800A87DC
800A87DC	addiu  sp, sp, $ffc8 (=-$38)
800A87E0	sw     s4, $0030(sp)
800A87E4	addu   s4, a0, zero
800A87E8	sw     s3, $002c(sp)
800A87EC	lui    s3, $8006

La87f0:	; 800A87F0
800A87F0	andi   a1, a1, $ffff
800A87F4	lw     v1, $794c(s3)
800A87F8	lui    v0, $0006
800A87FC	sw     s2, $0028(sp)
800A8800	or     s2, a1, v0
800A8804	sw     ra, $0034(sp)
800A8808	sw     s1, $0024(sp)
800A880C	sw     s0, $0020(sp)
800A8810	lw     s0, $001c(v1)
800A8814	addu   a0, s2, zero
800A8818	jal    func220e8 [$800220e8]
800A881C	addiu  s1, s0, $0854
800A8820	beq    v0, zero, La8908 [$800a8908]
800A8824	addiu  v0, zero, $ffff (=-$1)
800A8828	jal    func21e5c [$80021e5c]

funca882c:	; 800A882C
800A882C	addu   a0, s2, zero
800A8830	lui    s1, $8006
800A8834	lw     a0, $7948(s1)
800A8838	lw     a3, $794c(s3)
800A883C	lw     v1, $0008(v0)
800A8840	lw     a1, $000c(v0)
800A8844	lw     a2, $001c(a3)
800A8848	addu   v1, v1, a1
800A884C	sw     v1, $0874(a2)
800A8850	lw     a1, $001c(a3)
800A8854	lw     v1, $000c(v0)
800A8858	nop
800A885C	sw     v1, $0864(a1)

funca8860:	; 800A8860
800A8860	lw     a1, $001c(a3)
800A8864	lw     v1, $001c(v0)
800A8868	nop
800A886C	sw     v1, $0858(a1)
800A8870	lw     a1, $0008(v0)
800A8874	lw     a2, $000c(v0)
800A8878	jal    func1daa4 [$8001daa4]
800A887C	addu   a3, zero, zero
800A8880	jal    func22390 [$80022390]
800A8884	addu   a0, s2, zero
800A8888	jal    func130a4 [$800130a4]
800A888C	addu   a0, zero, zero
800A8890	lw     v0, $794c(s3)
800A8894	nop
800A8898	lw     v1, $001c(v0)
800A889C	nop
800A88A0	lw     t0, $0864(v1)
800A88A4	lw     v0, $0858(v1)
800A88A8	nop
800A88AC	slt    v0, t0, v0
800A88B0	beq    v0, zero, La8940 [$800a8940]
800A88B4	addiu  a0, v1, $0854
800A88B8	addu   s0, s3, zero
800A88BC	lw     a2, $0804(v1)
800A88C0	addiu  v0, zero, $ffff (=-$1)
800A88C4	sw     t0, $0010(sp)
800A88C8	sw     v0, $0014(sp)
800A88CC	sw     zero, $0018(sp)
800A88D0	lw     a1, $07fc(v1)
800A88D4	lw     a3, $7948(s1)
800A88D8	sll    a2, a2, $0b
800A88DC	jal    func2177c [$8002177c]
800A88E0	addu   a3, a3, t0

loopa88e4:	; 800A88E4
800A88E4	lw     v0, $794c(s0)
800A88E8	nop
800A88EC	lw     a0, $001c(v0)
800A88F0	jal    func217c4 [$800217c4]
800A88F4	addiu  a0, a0, $0854
800A88F8	bne    v0, zero, loopa88e4 [$800a88e4]
800A88FC	nop
800A8900	j      La8944 [$800a8944]
800A8904	lui    s0, $8006

La8908:	; 800A8908
800A8908	addu   a0, s1, zero
800A890C	lw     a2, $0804(s0)
800A8910	sw     v0, $0014(sp)
800A8914	lui    v0, $8006
800A8918	sw     zero, $0010(sp)
800A891C	sw     zero, $0018(sp)
800A8920	lw     a1, $07fc(s0)
800A8924	lw     a3, $7948(v0)
800A8928	jal    func2177c [$8002177c]
800A892C	sll    a2, a2, $0b

loopa8930:	; 800A8930
800A8930	jal    func217c4 [$800217c4]
800A8934	addu   a0, s1, zero
800A8938	bne    v0, zero, loopa8930 [$800a8930]
800A893C	nop

La8940:	; 800A8940
800A8940	lui    s0, $8006

La8944:	; 800A8944
800A8944	lw     a0, $7948(s0)
800A8948	addu   a1, zero, zero
800A894C	jal    func1c750 [$8001c750]
800A8950	sw     a0, $000c(s4)
800A8954	lw     a0, $000c(s4)
800A8958	jal    func1ca70 [$8001ca70]
800A895C	nop
800A8960	lw     v1, $7948(s0)
800A8964	lw     ra, $0034(sp)
800A8968	lw     s4, $0030(sp)
800A896C	lw     s3, $002c(sp)
800A8970	lw     s2, $0028(sp)
800A8974	lw     s1, $0024(sp)
800A8978	addu   v1, v1, v0
800A897C	sw     v1, $7948(s0)
800A8980	lw     s0, $0020(sp)
800A8984	addu   v0, zero, zero
800A8988	jr     ra 
800A898C	addiu  sp, sp, $0038


funca8990:	; 800A8990
800A8990	addiu  sp, sp, $ffe8 (=-$18)
800A8994	sw     s0, $0010(sp)
800A8998	addu   s0, a0, zero
800A899C	sw     ra, $0014(sp)
800A89A0	lw     a0, $000c(s0)
800A89A4	jal    func1c784 [$8001c784]
800A89A8	nop
800A89AC	sw     zero, $000c(s0)
800A89B0	lw     ra, $0014(sp)
800A89B4	lw     s0, $0010(sp)
800A89B8	addu   v0, zero, zero
800A89BC	jr     ra 
800A89C0	addiu  sp, sp, $0018



////////////////////////////////
// funca89c4
// we load field here
800A89C4-800A8E54
////////////////////////////////



funca8e58:	; 800A8E58
800A8E58	addiu  sp, sp, $ffd8 (=-$28)
800A8E5C	sw     s0, $0018(sp)
800A8E60	lui    s0, $8006
800A8E64	lw     v0, $794c(s0)
800A8E68	sw     ra, $0020(sp)

funca8e6c:	; 800A8E6C
800A8E6C	sw     s1, $001c(sp)
800A8E70	lw     v0, $001c(v0)
800A8E74	nop
800A8E78	lw     v0, $08e4(v0)
800A8E7C	nop
800A8E80	lw     v0, $000c(v0)
800A8E84	nop
800A8E88	lw     s1, $0014(v0)
800A8E8C	jal    func130a4 [$800130a4]
800A8E90	addu   a0, zero, zero
800A8E94	lw     v0, $794c(s0)
800A8E98	nop
800A8E9C	lw     v0, $001c(v0)
800A8EA0	nop
800A8EA4	lh     a1, $000c(v0)
800A8EA8	jal    funcb1e04 [$800b1e04]
800A8EAC	addu   a0, s1, zero
800A8EB0	lui    a1, $ffff
800A8EB4	ori    a1, a1, $0006
800A8EB8	lui    v1, $8007
800A8EBC	lw     v0, $3998(v1)
800A8EC0	lw     a0, $794c(s0)
800A8EC4	and    v0, v0, a1
800A8EC8	sw     v0, $3998(v1)
800A8ECC	lw     v0, $001c(a0)
800A8ED0	nop
800A8ED4	lh     a1, $000c(v0)
800A8ED8	jal    funcaa0a8 [$800aa0a8]
800A8EDC	addu   a0, s1, zero
800A8EE0	lw     v0, $794c(s0)
800A8EE4	nop
800A8EE8	lw     v0, $001c(v0)
800A8EEC	nop
800A8EF0	lh     a1, $000c(v0)
800A8EF4	jal    funcaa074 [$800aa074]
800A8EF8	addu   a0, s1, zero
800A8EFC	jal    funcaaa54 [$800aaa54]
800A8F00	nop
800A8F04	addu   a1, zero, zero
800A8F08	addiu  t0, zero, $fffe (=-$2)
800A8F0C	addu   a2, a1, zero

funca8f10:	; 800A8F10
800A8F10	lw     a3, $794c(s0)

loopa8f14:	; 800A8F14
800A8F14	nop

funca8f18:	; 800A8F18
800A8F18	lw     v0, $001c(a3)
800A8F1C	nop
800A8F20	lw     v0, $08d8(v0)
800A8F24	nop
800A8F28	addu   a0, a2, v0
800A8F2C	lw     v1, $0000(a0)
800A8F30	nop
800A8F34	andi   v0, v1, $0001
800A8F38	beq    v0, zero, La8f44 [$800a8f44]
800A8F3C	and    v0, v1, t0
800A8F40	sw     v0, $0000(a0)

La8f44:	; 800A8F44
800A8F44	addiu  a1, a1, $0001
800A8F48	slti   v0, a1, $0009
800A8F4C	bne    v0, zero, loopa8f14 [$800a8f14]
800A8F50	addiu  a2, a2, $0014
800A8F54	lui    v0, $8006
800A8F58	lw     v1, $794c(v0)
800A8F5C	nop
800A8F60	lw     v0, $001c(v1)
800A8F64	nop
800A8F68	lbu    v0, $0038(v0)
800A8F6C	nop
800A8F70	beq    v0, zero, La8fcc [$800a8fcc]
800A8F74	addu   a1, zero, zero
800A8F78	addu   a3, v1, zero
800A8F7C	addiu  t0, zero, $fffe (=-$2)
800A8F80	addu   a2, a1, zero

loopa8f84:	; 800A8F84
800A8F84	lw     v0, $001c(a3)
800A8F88	nop

funca8f8c:	; 800A8F8C
800A8F8C	lw     v0, $08e0(v0)
800A8F90	nop
800A8F94	addu   a0, a2, v0
800A8F98	lw     v1, $0000(a0)
800A8F9C	nop
800A8FA0	andi   v0, v1, $0001
800A8FA4	beq    v0, zero, La8fb0 [$800a8fb0]
800A8FA8	and    v0, v1, t0
800A8FAC	sw     v0, $0000(a0)

La8fb0:	; 800A8FB0
800A8FB0	lw     v0, $001c(a3)
800A8FB4	nop
800A8FB8	lbu    v0, $0038(v0)
800A8FBC	addiu  a1, a1, $0001
800A8FC0	slt    v0, a1, v0
800A8FC4	bne    v0, zero, loopa8f84 [$800a8f84]
800A8FC8	addiu  a2, a2, $0014

La8fcc:	; 800A8FCC
800A8FCC	addiu  a1, zero, $0001
800A8FD0	lui    v0, $8006
800A8FD4	lw     a2, $794c(v0)

loopa8fd8:	; 800A8FD8
800A8FD8	nop
800A8FDC	lw     v1, $001c(a2)
800A8FE0	sll    a0, a1, $02
800A8FE4	addu   v1, v1, a0
800A8FE8	lw     v0, $07fc(v1)
800A8FEC	nop
800A8FF0	sw     v0, $07ec(v1)
800A8FF4	lw     v0, $001c(a2)
800A8FF8	nop
800A8FFC	addu   v0, v0, a0
800A9000	lw     v1, $0804(v0)
800A9004	addiu  a1, a1, $ffff (=-$1)
800A9008	bgez   a1, loopa8fd8 [$800a8fd8]
800A900C	sw     v1, $07f4(v0)
800A9010	lui    v0, $8006
800A9014	lw     v0, $794c(v0)
800A9018	nop
800A901C	lw     v0, $001c(v0)
800A9020	nop
800A9024	lw     v0, $08e4(v0)
800A9028	nop

funca902c:	; 800A902C
800A902C	lw     v0, $000c(v0)
800A9030	nop
800A9034	lw     v0, $0014(v0)
800A9038	nop
800A903C	lbu    v0, $004a(v0)
800A9040	nop
800A9044	addiu  v1, v0, $ffff (=-$1)
800A9048	sltiu  v0, v1, $0009
800A904C	beq    v0, zero, La9318 [$800a9318]
800A9050	lui    v0, $800a
800A9054	addiu  v0, v0, $701c
800A9058	sll    v1, v1, $02
800A905C	addu   v1, v1, v0
800A9060	lw     v0, $0000(v1)
800A9064	nop
800A9068	jr     v0 
800A906C	nop

800A9070	lui    s0, $8006
800A9074	lw     v0, $794c(s0)
800A9078	nop
800A907C	lw     a2, $001c(v0)
800A9080	lh     a0, $000a(s1)
800A9084	addiu  a1, a2, $07fc
800A9088	jal    funcaa0f4 [$800aa0f4]
800A908C	addiu  a2, a2, $0804

funca9090:	; 800A9090
800A9090	lw     v1, $794c(s0)
800A9094	nop
800A9098	lw     a2, $001c(v1)
800A909C	addu   a0, v0, zero
800A90A0	addiu  a1, a2, $0800
800A90A4	jal    funcaa194 [$800aa194]
800A90A8	addiu  a2, a2, $0808
800A90AC	lw     a0, $794c(s0)

funca90b0:	; 800A90B0
800A90B0	lhu    v0, $000a(s1)
800A90B4	lw     v1, $001c(a0)
800A90B8	nop
800A90BC	sh     v0, $000e(v1)
800A90C0	addiu  v0, zero, $0002
800A90C4	sb     v0, $0008(a0)
800A90C8	lw     v1, $794c(s0)
800A90CC	j      La91f8 [$800a91f8]
800A90D0	addiu  v0, zero, $0001
800A90D4	lui    s0, $8006
800A90D8	lw     v0, $794c(s0)
800A90DC	nop
800A90E0	lw     a2, $001c(v0)
800A90E4	lh     a0, $000a(s1)
800A90E8	addiu  a1, a2, $0800
800A90EC	jal    funcaa290 [$800aa290]
800A90F0	addiu  a2, a2, $0808
800A90F4	lw     v1, $794c(s0)
800A90F8	nop
800A90FC	lw     a2, $001c(v1)
800A9100	addu   a0, v0, zero
800A9104	addiu  a1, a2, $07fc
800A9108	jal    funcaa330 [$800aa330]
800A910C	addiu  a2, a2, $0804
800A9110	lw     a0, $794c(s0)
800A9114	lhu    v1, $000a(s1)
800A9118	lw     a1, $001c(a0)
800A911C	nop
800A9120	sh     v1, $07dc(a1)
800A9124	lw     v1, $001c(a0)
800A9128	nop
800A912C	sh     v0, $07de(v1)
800A9130	addiu  v0, zero, $0003
800A9134	sb     v0, $0008(a0)
800A9138	lw     v1, $794c(s0)
800A913C	j      La91f8 [$800a91f8]
800A9140	addiu  v0, zero, $0001
800A9144	lui    s0, $8006
800A9148	lw     v0, $794c(s0)
800A914C	nop
800A9150	lw     a1, $001c(v0)
800A9154	nop
800A9158	lw     v0, $0000(a1)
800A915C	lui    v1, $2000
800A9160	and    v0, v0, v1
800A9164	beq    v0, zero, La9180 [$800a9180]
800A9168	addiu  a0, zero, $0800
800A916C	addu   a2, zero, zero
800A9170	lhu    a1, $081c(a1)
800A9174	addu   a3, a2, zero
800A9178	jal    funcb0124 [$800b0124]
800A917C	sw     zero, $0010(sp)

La9180:	; 800A9180
800A9180	jal    funcb1c4c [$800b1c4c]
800A9184	nop
800A9188	jal    func56228 [$80056228]
800A918C	nop
800A9190	lw     v1, $794c(s0)
800A9194	addiu  v0, zero, $0009
800A9198	sb     v0, $0008(v1)
800A919C	lw     v1, $794c(s0)
800A91A0	j      La91f8 [$800a91f8]
800A91A4	addiu  v0, zero, $0001
800A91A8	addiu  a0, zero, $ffff (=-$1)
800A91AC	jal    func5546c [$8005546c]
800A91B0	addu   a1, zero, zero
800A91B4	jal    func56228 [$80056228]
800A91B8	nop
800A91BC	lui    a0, $8006
800A91C0	lw     v1, $794c(a0)
800A91C4	j      La91ec [$800a91ec]
800A91C8	addiu  v0, zero, $0007
800A91CC	addiu  a0, zero, $ffff (=-$1)
800A91D0	jal    func5546c [$8005546c]
800A91D4	addu   a1, zero, zero
800A91D8	jal    func56228 [$80056228]
800A91DC	nop
800A91E0	lui    a0, $8006
800A91E4	lw     v1, $794c(a0)
800A91E8	addiu  v0, zero, $0004

La91ec:	; 800A91EC
800A91EC	sb     v0, $0008(v1)
800A91F0	lw     v1, $794c(a0)
800A91F4	addiu  v0, zero, $0001

La91f8:	; 800A91F8
800A91F8	j      La9324 [$800a9324]
800A91FC	sb     v0, $000a(v1)
800A9200	lui    s0, $8006
800A9204	lw     v0, $794c(s0)
800A9208	nop
800A920C	lw     a2, $001c(v0)
800A9210	nop
800A9214	lw     a0, $08e4(a2)
800A9218	nop
800A921C	lw     v0, $0000(a0)
800A9220	lui    v1, $0001
800A9224	and    v0, v0, v1
800A9228	beq    v0, zero, La9244 [$800a9244]
800A922C	lui    a1, $8006
800A9230	lw     v0, $000c(a0)
800A9234	nop
800A9238	lh     a2, $0010(v0)

funca923c:	; 800A923C
800A923C	j      La9278 [$800a9278]
800A9240	nop

La9244:	; 800A9244
800A9244	addiu  a1, a2, $0800
800A9248	lh     a0, $000a(s1)
800A924C	jal    funcaa290 [$800aa290]
800A9250	addiu  a2, a2, $0808
800A9254	lw     v1, $794c(s0)
800A9258	nop
800A925C	lw     a2, $001c(v1)
800A9260	addu   a0, v0, zero
800A9264	addiu  a1, a2, $07fc
800A9268	jal    funcaa330 [$800aa330]
800A926C	addiu  a2, a2, $0804
800A9270	addu   a2, v0, zero
800A9274	lui    a1, $8006

La9278:	; 800A9278
800A9278	lw     a0, $794c(a1)
800A927C	nop
800A9280	lw     v0, $001c(a0)
800A9284	nop
800A9288	lhu    v0, $003a(v0)
800A928C	lui    v1, $0006
800A9290	or     v0, v0, v1
800A9294	beq    a2, v0, La92b0 [$800a92b0]
800A9298	nop
800A929C	lw     v0, $0000(a0)
800A92A0	nop
800A92A4	ori    v0, v0, $0004
800A92A8	sw     v0, $0000(a0)
800A92AC	lw     a0, $794c(a1)

La92b0:	; 800A92B0
800A92B0	nop
800A92B4	lw     v0, $001c(a0)
800A92B8	nop
800A92BC	lw     a1, $08e4(v0)
800A92C0	lui    v1, $fffe
800A92C4	lw     v0, $0000(a1)
800A92C8	ori    v1, v1, $ffff
800A92CC	and    v0, v0, v1
800A92D0	sw     v0, $0000(a1)
800A92D4	lw     v0, $001c(a0)
800A92D8	nop
800A92DC	lw     v0, $08e4(v0)
800A92E0	nop
800A92E4	lw     v0, $000c(v0)
800A92E8	nop
800A92EC	sh     a2, $0010(v0)
800A92F0	lw     v0, $001c(a0)
800A92F4	nop
800A92F8	lw     v1, $08e4(v0)
800A92FC	lhu    v0, $000c(v0)
800A9300	nop
800A9304	sh     v0, $000a(v1)
800A9308	lw     v1, $001c(a0)
800A930C	lhu    v0, $000a(s1)
800A9310	j      La9324 [$800a9324]
800A9314	sh     v0, $000c(v1)

La9318:	; 800A9318
800A9318	addiu  a0, zero, $0039
800A931C	jal    func2eb64 [$8002eb64]
800A9320	addiu  a1, zero, $00c9

La9324:	; 800A9324
800A9324	lui    v0, $8006
800A9328	lw     v0, $794c(v0)
800A932C	nop
800A9330	lw     v1, $001c(v0)
800A9334	addiu  v0, zero, $ffff (=-$1)
800A9338	sw     v0, $07e4(v1)
800A933C	lw     ra, $0020(sp)
800A9340	lw     s1, $001c(sp)
800A9344	lw     s0, $0018(sp)
800A9348	jr     ra 
800A934C	addiu  sp, sp, $0028


funca9350:	; 800A9350
800A9350	lui    v0, $8006
800A9354	lui    a0, $8006
800A9358	lw     v0, $794c(v0)
800A935C	lw     v1, $7948(a0)
800A9360	lw     v0, $001c(v0)
800A9364	addiu  a3, v1, $0090
800A9368	lw     v0, $08e4(v0)
800A936C	addiu  a2, v1, $0270
800A9370	sw     a3, $7948(a0)
800A9374	sw     a2, $7948(a0)
800A9378	lw     a1, $000c(v0)
800A937C	addiu  v0, v1, $0330
800A9380	sw     v0, $7948(a0)
800A9384	addiu  v0, v1, $006c
800A9388	sw     v1, $0014(a1)
800A938C	sw     v0, $0028(v1)
800A9390	sw     a3, $0054(v1)
800A9394	jr     ra 
800A9398	sw     a2, $0058(v1)


funca939c:	; 800A939C
800A939C	lui    v0, $8006
800A93A0	lw     v0, $794c(v0)
800A93A4	lui    v1, $0010
800A93A8	lw     v0, $001c(v0)
800A93AC	ori    v1, v1, $6700
800A93B0	lw     v0, $08e4(v0)
800A93B4	addiu  a1, zero, $0017
800A93B8	lw     v0, $000c(v0)
800A93BC	addiu  a3, zero, $ffff (=-$1)
800A93C0	lw     a0, $0014(v0)
800A93C4	lui    v0, $8006
800A93C8	sb     zero, $0008(a0)
800A93CC	lw     v0, $7944(v0)
800A93D0	addiu  a2, zero, $01cc
800A93D4	sw     zero, $0000(a0)
800A93D8	sw     zero, $0004(a0)
800A93DC	sw     zero, $000c(a0)
800A93E0	sw     zero, $004c(a0)
800A93E4	sw     zero, $0014(a0)
800A93E8	sw     zero, $0018(a0)
800A93EC	sh     zero, $0030(a0)
800A93F0	sw     zero, $0010(a0)
800A93F4	sw     zero, $002c(a0)
800A93F8	sw     zero, $0020(a0)
800A93FC	sb     zero, $0042(a0)
800A9400	sb     zero, $0043(a0)
800A9404	sw     zero, $0044(a0)
800A9408	sb     zero, $0048(a0)
800A940C	sb     zero, $0049(a0)
800A9410	sw     zero, $001c(a0)
800A9414	addu   v0, v0, v1
800A9418	sw     v0, $0034(a0)

loopa941c:	; 800A941C
800A941C	lw     v0, $0054(a0)
800A9420	addiu  a1, a1, $ffff (=-$1)
800A9424	addu   v0, v0, a2
800A9428	addiu  a2, a2, $ffec (=-$14)
800A942C	addiu  v1, v0, $0008
800A9430	sw     zero, $0000(v0)
800A9434	sb     a3, $0004(v0)
800A9438	sb     zero, $0005(v0)
800A943C	sb     zero, $0007(v0)
800A9440	sb     zero, $0006(v0)
800A9444	sb     zero, $0002(v1)
800A9448	sb     zero, $0001(v1)
800A944C	addiu  v1, v0, $000c
800A9450	sb     zero, $0008(v0)
800A9454	sb     zero, $000b(v0)
800A9458	sb     zero, $0002(v1)
800A945C	sb     zero, $0001(v1)
800A9460	sb     zero, $000c(v0)
800A9464	sb     zero, $000f(v0)
800A9468	bgez   a1, loopa941c [$800a941c]
800A946C	sw     zero, $0010(v0)
800A9470	addu   a1, zero, zero
800A9474	addiu  v0, zero, $00a0
800A9478	sh     v0, $0038(a0)
800A947C	addiu  v0, zero, $0070
800A9480	sh     v0, $003a(a0)
800A9484	ori    v0, zero, $ffff
800A9488	sh     v0, $003c(a0)

La948c:	; 800A948C
800A948C	sh     v0, $003e(a0)
800A9490	addiu  v0, zero, $007f
800A9494	sb     zero, $0041(a0)
800A9498	sb     zero, $0009(a0)
800A949C	sb     v0, $005c(a0)
800A94A0	sb     v0, $005d(a0)
800A94A4	sb     zero, $005f(a0)
800A94A8	sh     zero, $0052(a0)
800A94AC	sh     zero, $0050(a0)
800A94B0	sw     zero, $0024(a0)
800A94B4	sll    v0, a1, $02

loopa94b8:	; 800A94B8
800A94B8	lw     v1, $0028(a0)
800A94BC	addiu  a1, a1, $0001
800A94C0	addu   v0, v0, v1
800A94C4	sw     zero, $0000(v0)
800A94C8	slti   v0, a1, $0009
800A94CC	bne    v0, zero, loopa94b8 [$800a94b8]
800A94D0	sll    v0, a1, $02
800A94D4	addiu  a1, zero, $000f
800A94D8	addiu  t0, zero, $00ff
800A94DC	ori    a2, zero, $ffff
800A94E0	addiu  a3, zero, $ffff (=-$1)
800A94E4	addiu  v1, zero, $00b4
800A94E8	addu   v0, a3, zero
800A94EC	sh     v0, $000a(a0)
800A94F0	addiu  v0, zero, $0001
800A94F4	sb     zero, $0040(a0)

funca94f8:	; 800A94F8
800A94F8	sb     v0, $004a(a0)
800A94FC	sb     zero, $004b(a0)

loopa9500:	; 800A9500
800A9500	lw     v0, $0058(a0)
800A9504	addiu  a1, a1, $ffff (=-$1)
800A9508	addu   v0, v0, v1
800A950C	addiu  v1, v1, $fff4 (=-$c)
800A9510	sb     t0, $0000(v0)
800A9514	sb     zero, $0001(v0)
800A9518	sh     a2, $0002(v0)
800A951C	sh     a2, $0004(v0)
800A9520	sh     a3, $0006(v0)
800A9524	sh     a2, $000a(v0)
800A9528	bgez   a1, loopa9500 [$800a9500]
800A952C	sh     a2, $0008(v0)
800A9530	addu   a1, zero, zero
800A9534	sb     zero, $005e(a0)
800A9538	sb     zero, $0060(a0)
800A953C	sh     zero, $0062(a0)
800A9540	sw     zero, $0064(a0)

loopa9544:	; 800A9544
800A9544	addu   v0, a0, a1
800A9548	addiu  a1, a1, $ffff (=-$1)
800A954C	bgez   a1, loopa9544 [$800a9544]
800A9550	sb     zero, $0061(v0)
800A9554	addiu  a1, zero, $0003

loopa9558:	; 800A9558
800A9558	addu   v0, a0, a1
800A955C	addiu  a1, a1, $ffff (=-$1)
800A9560	bgez   a1, loopa9558 [$800a9558]
800A9564	sb     zero, $0068(v0)
800A9568	jr     ra 
800A956C	nop


funca9570:	; 800A9570
800A9570	lui    v0, $8006
800A9574	lw     a1, $794c(v0)
800A9578	addiu  sp, sp, $ffe8 (=-$18)
800A957C	sw     ra, $0010(sp)
800A9580	lw     t2, $001c(a1)
800A9584	nop
800A9588	lw     a2, $08e4(t2)
800A958C	nop
800A9590	lw     v0, $0000(a2)
800A9594	lui    v1, $0001
800A9598	and    v0, v0, v1
800A959C	beq    v0, zero, La97c4 [$800a97c4]
800A95A0	addiu  a3, zero, $ffff (=-$1)
800A95A4	lui    a0, $0014
800A95A8	addu   t4, a1, zero
800A95AC	lw     a1, $0014(t4)
800A95B0	ori    a0, a0, $c700
800A95B4	lw     t1, $0008(a1)
800A95B8	lui    v0, $8006
800A95BC	sll    v1, t1, $0b
800A95C0	addu   v1, v1, a0
800A95C4	lw     a0, $7944(v0)
800A95C8	lw     v0, $0048(a1)
800A95CC	addu   t3, a0, v1
800A95D0	subu   v0, v0, t1
800A95D4	sll    v0, v0, $0b
800A95D8	addu   t0, t3, v0
800A95DC	lw     v1, $0044(a1)
800A95E0	lw     v0, $000c(a2)
800A95E4	addu   a2, t2, zero
800A95E8	sll    v1, v1, $03
800A95EC	lw     v0, $0014(v0)
800A95F0	addu   v1, t0, v1
800A95F4	lh     a0, $000a(v0)
800A95F8	lhu    v0, $fff8(v1)
800A95FC	j      La9614 [$800a9614]
800A9600	addiu  a1, v1, $fff8 (=-$8)

loopa9604:	; 800A9604
800A9604	sltu   v0, a1, t0
800A9608	bne    v0, zero, La9644 [$800a9644]
800A960C	nop
800A9610	lhu    v0, $0000(a1)

La9614:	; 800A9614
800A9614	nop
800A9618	bne    v0, a0, loopa9604 [$800a9604]
800A961C	addiu  a1, a1, $fff8 (=-$8)
800A9620	addiu  a1, a1, $0008
800A9624	lw     v0, $0004(a1)
800A9628	lhu    a3, $0002(a1)
800A962C	sw     v0, $0800(a2)
800A9630	lw     v0, $000c(a1)
800A9634	lw     v1, $0004(a1)
800A9638	nop
800A963C	subu   v0, v0, v1
800A9640	sw     v0, $0808(a2)

La9644:	; 800A9644
800A9644	lw     v1, $0014(t4)
800A9648	nop
800A964C	lw     v0, $0028(v1)
800A9650	lw     v1, $0024(v1)
800A9654	subu   v0, v0, t1
800A9658	sll    v0, v0, $0b
800A965C	addu   t0, t3, v0
800A9660	sll    v1, v1, $03
800A9664	addu   v1, t0, v1
800A9668	lhu    v0, $fff8(v1)
800A966C	j      La9684 [$800a9684]
800A9670	addiu  a1, v1, $fff8 (=-$8)

loopa9674:	; 800A9674
800A9674	sltu   v0, a1, t0
800A9678	bne    v0, zero, La96b8 [$800a96b8]
800A967C	lui    v0, $8006
800A9680	lhu    v0, $0000(a1)

La9684:	; 800A9684
800A9684	nop
800A9688	bne    v0, a3, loopa9674 [$800a9674]
800A968C	addiu  a1, a1, $fff8 (=-$8)
800A9690	addiu  a1, a1, $0008
800A9694	lw     v0, $0004(a1)
800A9698	nop
800A969C	sw     v0, $07fc(a2)
800A96A0	lw     v0, $000c(a1)
800A96A4	lw     v1, $0004(a1)
800A96A8	nop
800A96AC	subu   v0, v0, v1
800A96B0	sw     v0, $0804(a2)
800A96B4	lui    v0, $8006

La96b8:	; 800A96B8
800A96B8	lw     a0, $794c(v0)
800A96BC	nop
800A96C0	lw     v0, $001c(a0)
800A96C4	nop
800A96C8	lw     v0, $08e4(v0)
800A96CC	nop
800A96D0	lw     v0, $000c(v0)
800A96D4	nop
800A96D8	sh     a3, $0010(v0)
800A96DC	lw     v1, $001c(a0)
800A96E0	addiu  v0, zero, $ffff (=-$1)
800A96E4	sw     v0, $08a8(v1)
800A96E8	lw     v1, $001c(a0)
800A96EC	ori    v0, zero, $ffff
800A96F0	sh     v0, $084a(v1)
800A96F4	lw     v1, $0014(t4)
800A96F8	nop
800A96FC	lw     v0, $0098(v1)
800A9700	lw     v1, $0094(v1)
800A9704	subu   v0, v0, t1
800A9708	sll    v0, v0, $0b
800A970C	addu   t0, t3, v0
800A9710	sll    v1, v1, $03
800A9714	addu   a3, t0, v1
800A9718	addiu  a1, a3, $fff8 (=-$8)
800A971C	lw     t1, $001c(a0)
800A9720	lhu    v1, $fff8(a3)
800A9724	lhu    v0, $081c(t1)
800A9728	nop
800A972C	bne    v1, v0, La9750 [$800a9750]
800A9730	addiu  a2, a3, $fffc (=-$4)
800A9734	lw     v0, $fffc(a3)
800A9738	nop
800A973C	sw     v0, $08a8(t1)
800A9740	lhu    v0, $0008(a2)
800A9744	lhu    v1, $fffc(a3)
800A9748	j      La978c [$800a978c]

La974c:	; 800A974C
800A974C	nop

La9750:	; 800A9750
800A9750	addiu  a1, a1, $fff8 (=-$8)

loopa9754:	; 800A9754
800A9754	sltu   v0, a1, t0
800A9758	bne    v0, zero, La9798 [$800a9798]
800A975C	addiu  a2, a2, $fff8 (=-$8)
800A9760	lw     a3, $001c(a0)
800A9764	lhu    v1, $0000(a1)

funca9768:	; 800A9768
800A9768	lhu    v0, $081c(a3)
800A976C	nop
800A9770	bne    v1, v0, loopa9754 [$800a9754]
800A9774	addiu  a1, a1, $fff8 (=-$8)
800A9778	lw     v0, $0000(a2)
800A977C	nop
800A9780	sw     v0, $08a8(a3)
800A9784	lhu    v0, $0008(a2)
800A9788	lhu    v1, $0000(a2)

La978c:	; 800A978C
800A978C	lw     a0, $001c(a0)
800A9790	subu   v0, v0, v1
800A9794	sh     v0, $084a(a0)

La9798:	; 800A9798
800A9798	jal    funcac5f0 [$800ac5f0]
800A979C	nop
800A97A0	lui    v0, $8006
800A97A4	lw     v0, $794c(v0)
800A97A8	nop
800A97AC	lw     v0, $001c(v0)
800A97B0	nop
800A97B4	lw     a0, $085c(v0)
800A97B8	lw     a1, $0864(v0)
800A97BC	jal    func22280 [$80022280]
800A97C0	nop

La97c4:	; 800A97C4
800A97C4	lw     ra, $0010(sp)
800A97C8	nop
800A97CC	jr     ra 
800A97D0	addiu  sp, sp, $0018


funca97d4:	; 800A97D4
800A97D4	addiu  sp, sp, $ffe8 (=-$18)
800A97D8	sw     s0, $0010(sp)
800A97DC	addu   s0, a0, zero
800A97E0	andi   v0, a1, $ffff
800A97E4	lui    a1, $0005
800A97E8	addiu  a0, zero, $0004
800A97EC	or     a1, v0, a1
800A97F0	sw     ra, $0014(sp)
800A97F4	jal    func1c7fc [$8001c7fc]
800A97F8	addu   a2, zero, zero
800A97FC	sw     v0, $000c(s0)
800A9800	lw     ra, $0014(sp)
800A9804	lw     s0, $0010(sp)
800A9808	addu   v0, zero, zero
800A980C	jr     ra 
800A9810	addiu  sp, sp, $0018


funca9814:	; 800A9814
800A9814	addiu  sp, sp, $ffe8 (=-$18)
800A9818	sw     s0, $0010(sp)
800A981C	addu   s0, a0, zero
800A9820	addiu  a0, zero, $0004
800A9824	andi   v0, a1, $ffff
800A9828	lui    a1, $001e
800A982C	or     a1, v0, a1
800A9830	sw     ra, $0014(sp)
800A9834	jal    func1c7fc [$8001c7fc]
800A9838	addu   a2, zero, zero
800A983C	beq    v0, zero, La984c [$800a984c]
800A9840	sw     v0, $004c(s0)
800A9844	jal    func54a28 [$80054a28]
800A9848	addu   a0, v0, zero

La984c:	; 800A984C
800A984C	lw     ra, $0014(sp)
800A9850	lw     s0, $0010(sp)
800A9854	addu   v0, zero, zero
800A9858	jr     ra 
800A985C	addiu  sp, sp, $0018



////////////////////////////////
// funca9860
800A9860-800A9950
////////////////////////////////



funca9954:	; 800A9954
800A9954	addiu  sp, sp, $ffe8 (=-$18)
800A9958	sw     s0, $0010(sp)
800A995C	sw     ra, $0014(sp)
800A9960	jal    funcaa0c8 [$800aa0c8]
800A9964	addu   s0, a0, zero
800A9968	addiu  a0, zero, $0004
800A996C	andi   v0, v0, $ffff
800A9970	lui    a1, $001f
800A9974	or     a1, v0, a1
800A9978	jal    func1c7fc [$8001c7fc]
800A997C	addu   a2, zero, zero
800A9980	sw     v0, $001c(s0)
800A9984	lw     ra, $0014(sp)
800A9988	lw     s0, $0010(sp)
800A998C	addu   v0, zero, zero
800A9990	jr     ra 
800A9994	addiu  sp, sp, $0018


funca9998:	; 800A9998
800A9998	addiu  sp, sp, $ffd8 (=-$28)
800A999C	sw     ra, $0020(sp)
800A99A0	sw     s1, $001c(sp)
800A99A4	sw     s0, $0018(sp)

loopa99a8:	; 800A99A8
800A99A8	sw     zero, $0010(sp)

funca99ac:	; 800A99AC
800A99AC	addiu  a0, zero, $0c00
800A99B0	addiu  a1, zero, $ffff (=-$1)
800A99B4	addu   a2, zero, zero
800A99B8	jal    funcb0124 [$800b0124]
800A99BC	addu   a3, a2, zero
800A99C0	bne    v0, zero, loopa99a8 [$800a99a8]
800A99C4	lui    s0, $8006
800A99C8	lw     v0, $794c(s0)
800A99CC	nop
800A99D0	lw     a1, $001c(v0)
800A99D4	nop
800A99D8	lw     v0, $0000(a1)
800A99DC	lui    v1, $0040
800A99E0	and    v0, v0, v1
800A99E4	beq    v0, zero, La9a20 [$800a9a20]
800A99E8	addiu  a0, zero, $0100
800A99EC	addu   a2, zero, zero
800A99F0	lhu    a1, $081c(a1)
800A99F4	addu   a3, a2, zero
800A99F8	jal    funcb0124 [$800b0124]
800A99FC	sw     zero, $0010(sp)
800A9A00	lw     v0, $794c(s0)
800A9A04	nop
800A9A08	lw     a0, $001c(v0)
800A9A0C	lui    v1, $ffbf
800A9A10	lw     v0, $0000(a0)
800A9A14	ori    v1, v1, $ffff
800A9A18	and    v0, v0, v1
800A9A1C	sw     v0, $0000(a0)

La9a20:	; 800A9A20
800A9A20	lw     v0, $794c(s0)
800A9A24	nop
800A9A28	lw     v0, $001c(v0)
800A9A2C	nop
800A9A30	lw     v0, $08e4(v0)
800A9A34	nop
800A9A38	lw     v0, $0020(v0)
800A9A3C	addiu  s1, zero, $ffff (=-$1)
800A9A40	beq    v0, s1, La9a98 [$800a9a98]
800A9A44	nop
800A9A48	jal    func55df4 [$80055df4]
800A9A4C	nop
800A9A50	lui    a3, $0014
800A9A54	ori    a3, a3, $6f00
800A9A58	lw     v0, $794c(s0)
800A9A5C	addiu  a2, zero, $0001
800A9A60	lw     v0, $001c(v0)
800A9A64	lui    v1, $8006
800A9A68	lw     v0, $08e4(v0)
800A9A6C	lw     a0, $7944(v1)
800A9A70	lw     a1, $0020(v0)
800A9A74	jal    func55e14 [$80055e14]
800A9A78	addu   a0, a0, a3

funca9a7c:	; 800A9A7C
800A9A7C	lw     v0, $794c(s0)
800A9A80	nop
800A9A84	lw     v0, $001c(v0)
800A9A88	nop
800A9A8C	lw     v0, $08e4(v0)
800A9A90	nop
800A9A94	sw     s1, $0020(v0)

La9a98:	; 800A9A98
800A9A98	lw     ra, $0020(sp)
800A9A9C	lw     s1, $001c(sp)
800A9AA0	lw     s0, $0018(sp)
800A9AA4	jr     ra 
800A9AA8	addiu  sp, sp, $0028


funca9aac:	; 800A9AAC
800A9AAC	lui    v0, $8006
800A9AB0	lw     v0, $794c(v0)
800A9AB4	addiu  sp, sp, $ffd0 (=-$30)
800A9AB8	sw     ra, $0028(sp)
800A9ABC	sw     s5, $0024(sp)
800A9AC0	sw     s4, $0020(sp)
800A9AC4	sw     s3, $001c(sp)
800A9AC8	sw     s2, $0018(sp)
800A9ACC	sw     s1, $0014(sp)
800A9AD0	sw     s0, $0010(sp)
800A9AD4	lw     v0, $001c(v0)
800A9AD8	nop
800A9ADC	lw     v0, $08e4(v0)
800A9AE0	nop
800A9AE4	lw     v0, $000c(v0)
800A9AE8	nop
800A9AEC	lw     v0, $0014(v0)
800A9AF0	nop
800A9AF4	lbu    v0, $0060(v0)
800A9AF8	nop
800A9AFC	beq    v0, zero, La9bb4 [$800a9bb4]
800A9B00	lui    v0, $800d
800A9B04	addiu  s5, v0, $9f20 (=-$60e0)
800A9B08	addiu  s4, zero, $ffff (=-$1)

La9b0c:	; 800A9B0C
800A9B0C	lui    v0, $8006
800A9B10	lw     v0, $794c(v0)
800A9B14	nop

La9b18:	; 800A9B18
800A9B18	lw     v0, $001c(v0)
800A9B1C	nop
800A9B20	lw     v0, $08e4(v0)
800A9B24	nop
800A9B28	lw     v0, $000c(v0)
800A9B2C	addiu  s3, zero, $ffff (=-$1)
800A9B30	lw     v0, $0014(v0)
800A9B34	lui    s2, $7fff
800A9B38	lbu    v0, $0060(v0)
800A9B3C	nop
800A9B40	addu   s0, v0, s3
800A9B44	bltz   s0, La9b94 [$800a9b94]
800A9B48	ori    s2, s2, $ffff
800A9B4C	sll    v0, s0, $02
800A9B50	addu   s1, v0, s5

loopa9b54:	; 800A9B54
800A9B54	lw     a1, $0000(s1)
800A9B58	nop
800A9B5C	beq    a1, s4, La9b88 [$800a9b88]
800A9B60	nop
800A9B64	jal    func1e218 [$8001e218]
800A9B68	addiu  a0, zero, $000a
800A9B6C	lw     v1, $0004(v0)
800A9B70	nop
800A9B74	slt    v0, v1, s2
800A9B78	beq    v0, zero, La9b88 [$800a9b88]
800A9B7C	nop
800A9B80	addu   s3, s0, zero
800A9B84	addu   s2, v1, zero

La9b88:	; 800A9B88
800A9B88	addiu  s0, s0, $ffff (=-$1)
800A9B8C	bgez   s0, loopa9b54 [$800a9b54]
800A9B90	addiu  s1, s1, $fffc (=-$4)

La9b94:	; 800A9B94
800A9B94	beq    s3, s4, La9bb4 [$800a9bb4]
800A9B98	sll    s0, s3, $02
800A9B9C	addu   s0, s0, s5
800A9BA0	lw     a0, $0000(s0)
800A9BA4	jal    funcaa4e8 [$800aa4e8]
800A9BA8	nop
800A9BAC	j      La9b0c [$800a9b0c]
800A9BB0	sw     s4, $0000(s0)

La9bb4:	; 800A9BB4
800A9BB4	lw     ra, $0028(sp)
800A9BB8	lw     s5, $0024(sp)
800A9BBC	lw     s4, $0020(sp)
800A9BC0	lw     s3, $001c(sp)
800A9BC4	lw     s2, $0018(sp)
800A9BC8	lw     s1, $0014(sp)
800A9BCC	lw     s0, $0010(sp)
800A9BD0	addu   v0, zero, zero
800A9BD4	jr     ra 
800A9BD8	addiu  sp, sp, $0030



////////////////////////////////
// funca9bdc
800A9BDC-800AA018
////////////////////////////////



funcaa01c:	; 800AA01C
800AA01C	addiu  sp, sp, $ffe0 (=-$20)
800AA020	sw     s0, $0010(sp)
800AA024	addu   s0, a0, zero
800AA028	sw     s1, $0014(sp)
800AA02C	addu   s1, a1, zero
800AA030	addiu  a0, zero, $0004
800AA034	lui    a1, $001c
800AA038	sw     ra, $0018(sp)
800AA03C	jal    func1c7fc [$8001c7fc]
800AA040	addu   a2, zero, zero
800AA044	lhu    v1, $0030(v0)
800AA048	nop
800AA04C	sh     v1, $0000(s0)
800AA050	lhu    v1, $0032(v0)
800AA054	nop

Laa058:	; 800AA058
800AA058	sh     v1, $0000(s1)
800AA05C	lw     ra, $0018(sp)
800AA060	lw     s1, $0014(sp)
800AA064	lw     s0, $0010(sp)
800AA068	addu   v0, zero, zero
800AA06C	jr     ra 
800AA070	addiu  sp, sp, $0020


funcaa074:	; 800AA074
800AA074	addiu  sp, sp, $ffe8 (=-$18)
800AA078	sw     s0, $0010(sp)
800AA07C	addu   s0, a0, zero
800AA080	sw     ra, $0014(sp)
800AA084	lw     a0, $0024(s0)
800AA088	jal    func1c784 [$8001c784]

funcaa08c:	; 800AA08C
800AA08C	nop
800AA090	sw     zero, $0024(s0)
800AA094	lw     ra, $0014(sp)
800AA098	lw     s0, $0010(sp)
800AA09C	addu   v0, zero, zero
800AA0A0	jr     ra 
800AA0A4	addiu  sp, sp, $0018


funcaa0a8:	; 800AA0A8
800AA0A8	addiu  sp, sp, $ffe8 (=-$18)
800AA0AC	sw     ra, $0010(sp)
800AA0B0	jal    func54f80 [$80054f80]
800AA0B4	nop
800AA0B8	lw     ra, $0010(sp)
800AA0BC	addu   v0, zero, zero
800AA0C0	jr     ra 
800AA0C4	addiu  sp, sp, $0018



////////////////////////////////
// funcaa0c8
800AA0C8-800AA0F0
////////////////////////////////



funcaa0f4:	; 800AA0F4
800AA0F4	addu   a3, zero, zero
800AA0F8	lui    t0, $8006
800AA0FC	lw     v0, $794c(t0)
800AA100	andi   a0, a0, $ffff
800AA104	lw     v0, $001c(v0)
800AA108	lui    v1, $0011
800AA10C	lw     v0, $07e4(v0)
800AA110	or     a0, a0, v1
800AA114	lhu    v1, $0002(v0)
800AA118	nop
800AA11C	beq    v1, zero, Laa18c [$800aa18c]
800AA120	addiu  v0, v0, $0004
800AA124	addu   v1, v0, zero

loopaa128:	; 800AA128
800AA128	lw     v0, $0000(v1)
800AA12C	nop
800AA130	bne    v0, a0, Laa160 [$800aa160]
800AA134	nop
800AA138	beq    a1, zero, Laa14c [$800aa14c]
800AA13C	nop

funcaa140:	; 800AA140
800AA140	lw     v0, $0004(v1)
800AA144	nop
800AA148	sw     v0, $0000(a1)

Laa14c:	; 800AA14C
800AA14C	beq    a2, zero, Laa18c [$800aa18c]
800AA150	nop
800AA154	lw     v0, $0008(v1)
800AA158	j      Laa18c [$800aa18c]
800AA15C	sw     v0, $0000(a2)

Laa160:	; 800AA160
800AA160	lw     v0, $794c(t0)
800AA164	nop
800AA168	lw     v0, $001c(v0)
800AA16C	nop
800AA170	lw     v0, $07e4(v0)
800AA174	nop
800AA178	lhu    v0, $0002(v0)
800AA17C	addiu  a3, a3, $0001
800AA180	slt    v0, a3, v0
800AA184	bne    v0, zero, loopaa128 [$800aa128]
800AA188	addiu  v1, v1, $0010

Laa18c:	; 800AA18C
800AA18C	jr     ra 
800AA190	addu   v0, a0, zero


funcaa194:	; 800AA194
800AA194	lui    v0, $8006
800AA198	lw     v0, $794c(v0)
800AA19C	nop
800AA1A0	lw     v0, $001c(v0)
800AA1A4	addiu  t1, zero, $ffff (=-$1)
800AA1A8	lw     v0, $07e4(v0)
800AA1AC	addu   a3, zero, zero
800AA1B0	lhu    v1, $0002(v0)
800AA1B4	nop
800AA1B8	beq    v1, zero, Laa1f0 [$800aa1f0]
800AA1BC	addiu  t2, v0, $0004
800AA1C0	addu   t0, v1, zero
800AA1C4	addu   v1, t2, zero

loopaa1c8:	; 800AA1C8
800AA1C8	lw     v0, $0000(v1)
800AA1CC	nop
800AA1D0	bne    v0, a0, Laa1e4 [$800aa1e4]
800AA1D4	addiu  a3, a3, $0001
800AA1D8	lw     t1, $000c(v1)
800AA1DC	j      Laa1f4 [$800aa1f4]
800AA1E0	lui    v1, $8006

Laa1e4:	; 800AA1E4
800AA1E4	slt    v0, a3, t0
800AA1E8	bne    v0, zero, loopaa1c8 [$800aa1c8]
800AA1EC	addiu  v1, v1, $0010

Laa1f0:	; 800AA1F0
800AA1F0	lui    v1, $8006

Laa1f4:	; 800AA1F4
800AA1F4	lw     v0, $794c(v1)
800AA1F8	nop
800AA1FC	lw     v0, $001c(v0)
800AA200	nop
800AA204	lw     v0, $07e4(v0)
800AA208	nop
800AA20C	lhu    v0, $0002(v0)
800AA210	nop
800AA214	beq    v0, zero, Laa288 [$800aa288]
800AA218	addu   a3, zero, zero
800AA21C	addu   a0, v1, zero
800AA220	addu   v1, t2, zero

loopaa224:	; 800AA224
800AA224	lw     v0, $0000(v1)
800AA228	nop
800AA22C	bne    v0, t1, Laa25c [$800aa25c]

Laa230:	; 800AA230
800AA230	nop
800AA234	beq    a1, zero, Laa248 [$800aa248]
800AA238	nop
800AA23C	lw     v0, $0004(v1)
800AA240	nop
800AA244	sw     v0, $0000(a1)

Laa248:	; 800AA248
800AA248	beq    a2, zero, Laa288 [$800aa288]

funcaa24c:	; 800AA24C
800AA24C	nop
800AA250	lw     v0, $0008(v1)
800AA254	j      Laa288 [$800aa288]
800AA258	sw     v0, $0000(a2)

Laa25c:	; 800AA25C
800AA25C	lw     v0, $794c(a0)
800AA260	nop
800AA264	lw     v0, $001c(v0)
800AA268	nop
800AA26C	lw     v0, $07e4(v0)
800AA270	nop
800AA274	lhu    v0, $0002(v0)
800AA278	addiu  a3, a3, $0001
800AA27C	slt    v0, a3, v0
800AA280	bne    v0, zero, loopaa224 [$800aa224]
800AA284	addiu  v1, v1, $0010

Laa288:	; 800AA288
800AA288	jr     ra 
800AA28C	addu   v0, t1, zero


funcaa290:	; 800AA290
800AA290	addu   a3, zero, zero
800AA294	lui    t0, $8006
800AA298	lw     v0, $794c(t0)
800AA29C	andi   a0, a0, $ffff
800AA2A0	lw     v0, $001c(v0)
800AA2A4	lui    v1, $0005
800AA2A8	lw     v0, $07e4(v0)

Laa2ac:	; 800AA2AC
800AA2AC	or     a0, a0, v1

Laa2b0:	; 800AA2B0
800AA2B0	lhu    v1, $0002(v0)
800AA2B4	nop
800AA2B8	beq    v1, zero, Laa328 [$800aa328]
800AA2BC	addiu  v0, v0, $0004
800AA2C0	addu   v1, v0, zero

loopaa2c4:	; 800AA2C4
800AA2C4	lw     v0, $0000(v1)
800AA2C8	nop
800AA2CC	bne    v0, a0, Laa2fc [$800aa2fc]
800AA2D0	nop

Laa2d4:	; 800AA2D4
800AA2D4	beq    a1, zero, Laa2e8 [$800aa2e8]
800AA2D8	nop
800AA2DC	lw     v0, $0004(v1)
800AA2E0	nop
800AA2E4	sw     v0, $0000(a1)

Laa2e8:	; 800AA2E8
800AA2E8	beq    a2, zero, Laa328 [$800aa328]
800AA2EC	nop
800AA2F0	lw     v0, $0008(v1)
800AA2F4	j      Laa328 [$800aa328]
800AA2F8	sw     v0, $0000(a2)

Laa2fc:	; 800AA2FC
800AA2FC	lw     v0, $794c(t0)
800AA300	nop
800AA304	lw     v0, $001c(v0)
800AA308	nop
800AA30C	lw     v0, $07e4(v0)
800AA310	nop
800AA314	lhu    v0, $0002(v0)
800AA318	addiu  a3, a3, $0001
800AA31C	slt    v0, a3, v0
800AA320	bne    v0, zero, loopaa2c4 [$800aa2c4]
800AA324	addiu  v1, v1, $0010

Laa328:	; 800AA328
800AA328	jr     ra 
800AA32C	addu   v0, a0, zero


funcaa330:	; 800AA330
800AA330	lui    v0, $8006
800AA334	lw     v0, $794c(v0)
800AA338	nop
800AA33C	lw     v0, $001c(v0)
800AA340	nop
800AA344	lw     t0, $07e4(v0)
800AA348	nop
800AA34C	lhu    v0, $0002(t0)
800AA350	addiu  v1, t0, $0004
800AA354	sll    v0, v0, $04
800AA358	addu   a3, v1, v0
800AA35C	sltu   v0, v1, a3
800AA360	beq    v0, zero, Laa39c [$800aa39c]
800AA364	addiu  t1, zero, $ffff (=-$1)

loopaa368:	; 800AA368
800AA368	lw     v0, $0000(v1)
800AA36C	nop
800AA370	bne    v0, a0, Laa384 [$800aa384]
800AA374	nop
800AA378	lw     t1, $000c(v1)
800AA37C	j      Laa398 [$800aa398]
800AA380	addiu  v1, t0, $0004

Laa384:	; 800AA384
800AA384	addiu  v1, v1, $0010
800AA388	sltu   v0, v1, a3
800AA38C	bne    v0, zero, loopaa368 [$800aa368]
800AA390	nop
800AA394	addiu  v1, t0, $0004

Laa398:	; 800AA398
800AA398	sltu   v0, v1, a3

Laa39c:	; 800AA39C
800AA39C	beq    v0, zero, Laa3ec [$800aa3ec]
800AA3A0	addiu  a0, t0, $000c

loopaa3a4:	; 800AA3A4
800AA3A4	lw     v0, $0000(v1)
800AA3A8	nop
800AA3AC	bne    v0, t1, Laa3dc [$800aa3dc]
800AA3B0	nop
800AA3B4	beq    a1, zero, Laa3c8 [$800aa3c8]
800AA3B8	nop
800AA3BC	lw     v0, $fffc(a0)
800AA3C0	nop
800AA3C4	sw     v0, $0000(a1)

Laa3c8:	; 800AA3C8
800AA3C8	beq    a2, zero, Laa3ec [$800aa3ec]
800AA3CC	nop
800AA3D0	lw     v0, $0000(a0)
800AA3D4	j      Laa3ec [$800aa3ec]
800AA3D8	sw     v0, $0000(a2)

Laa3dc:	; 800AA3DC
800AA3DC	addiu  v1, v1, $0010
800AA3E0	sltu   v0, v1, a3
800AA3E4	bne    v0, zero, loopaa3a4 [$800aa3a4]
800AA3E8	addiu  a0, a0, $0010

Laa3ec:	; 800AA3EC
800AA3EC	jr     ra 
800AA3F0	addu   v0, t1, zero


funcaa3f4:	; 800AA3F4
800AA3F4	addiu  sp, sp, $ffe8 (=-$18)
800AA3F8	sw     ra, $0014(sp)
800AA3FC	jal    funcaaef8 [$800aaef8]
800AA400	sw     s0, $0010(sp)
800AA404	addu   s0, v0, zero
800AA408	addiu  v0, zero, $ffff (=-$1)
800AA40C	beq    s0, v0, Laa4ac [$800aa4ac]
800AA410	addu   v0, zero, zero
800AA414	jal    funcaaec4 [$800aaec4]
800AA418	addu   a0, s0, zero
800AA41C	addu   s0, v0, zero
800AA420	addiu  a0, zero, $0004
800AA424	addu   a1, s0, zero
800AA428	jal    func1c7fc [$8001c7fc]
800AA42C	addu   a2, zero, zero
800AA430	bne    v0, zero, Laa4ac [$800aa4ac]
800AA434	addu   v0, zero, zero
800AA438	lui    v0, $8006
800AA43C	lw     a0, $794c(v0)
800AA440	nop

Laa444:	; 800AA444
800AA444	lw     v0, $001c(a0)
800AA448	nop
800AA44C	lw     v0, $08e4(v0)
800AA450	nop
800AA454	lw     v0, $000c(v0)
800AA458	nop
800AA45C	lw     v0, $0014(v0)
800AA460	lui    v1, $800d
800AA464	lbu    v0, $0060(v0)
800AA468	addiu  v1, v1, $9f20 (=-$60e0)
800AA46C	sll    v0, v0, $02
800AA470	addu   v0, v0, v1
800AA474	sw     s0, $0000(v0)
800AA478	lw     v0, $001c(a0)
800AA47C	nop
800AA480	lw     v0, $08e4(v0)
800AA484	nop
800AA488	lw     v0, $000c(v0)
800AA48C	nop
800AA490	lw     v1, $0014(v0)
800AA494	nop
800AA498	lbu    v0, $0060(v1)
800AA49C	nop
800AA4A0	addiu  v0, v0, $0001
800AA4A4	sb     v0, $0060(v1)
800AA4A8	addu   v0, zero, zero

Laa4ac:	; 800AA4AC
800AA4AC	lw     ra, $0014(sp)
800AA4B0	lw     s0, $0010(sp)
800AA4B4	jr     ra 
800AA4B8	addiu  sp, sp, $0018


funcaa4bc:	; 800AA4BC
800AA4BC	addiu  v1, zero, $000f
800AA4C0	addiu  a0, zero, $ffff (=-$1)
800AA4C4	lui    v0, $800d
800AA4C8	addiu  v0, v0, $9f20 (=-$60e0)
800AA4CC	addiu  v0, v0, $003c

loopaa4d0:	; 800AA4D0
800AA4D0	sw     a0, $0000(v0)
800AA4D4	addiu  v1, v1, $ffff (=-$1)

Laa4d8:	; 800AA4D8
800AA4D8	bgez   v1, loopaa4d0 [$800aa4d0]
800AA4DC	addiu  v0, v0, $fffc (=-$4)
800AA4E0	jr     ra 
800AA4E4	nop


funcaa4e8:	; 800AA4E8
800AA4E8	addiu  sp, sp, $ffa8 (=-$58)
800AA4EC	sw     s0, $0030(sp)
800AA4F0	addu   s0, a0, zero
800AA4F4	addiu  a0, zero, $000a
800AA4F8	addu   a1, s0, zero
800AA4FC	sw     ra, $0054(sp)
800AA500	sw     fp, $0050(sp)

funcaa504:	; 800AA504
800AA504	sw     s7, $004c(sp)
800AA508	sw     s6, $0048(sp)
800AA50C	sw     s5, $0044(sp)
800AA510	sw     s4, $0040(sp)
800AA514	sw     s3, $003c(sp)
800AA518	sw     s2, $0038(sp)
800AA51C	jal    func1e218 [$8001e218]
800AA520	sw     s1, $0034(sp)
800AA524	addu   s1, v0, zero
800AA528	lw     v0, $000c(s1)
800AA52C	lw     v1, $0004(s1)
800AA530	addu   a0, s0, zero
800AA534	subu   v0, v0, v1
800AA538	jal    funcac344 [$800ac344]
800AA53C	sll    s3, v0, $0b
800AA540	addu   s2, v0, zero
800AA544	lw     v0, $0004(s2)
800AA548	nop
800AA54C	bne    v0, zero, Laa5d4 [$800aa5d4]
800AA550	addu   a2, s3, zero
800AA554	addu   a0, s0, zero
800AA558	jal    funcac3d8 [$800ac3d8]
800AA55C	addu   a1, s3, zero
800AA560	beq    v0, zero, Laa574 [$800aa574]
800AA564	addu   a2, s3, zero
800AA568	lw     a3, $0004(s2)
800AA56C	j      Laa580 [$800aa580]
800AA570	lui    v1, $8006

Laa574:	; 800AA574
800AA574	lui    v0, $8006

Laa578:	; 800AA578
800AA578	lw     a3, $7948(v0)

Laa57c:	; 800AA57C
800AA57C	lui    v1, $8006

Laa580:	; 800AA580
800AA580	lw     v0, $794c(v1)
800AA584	addu   s0, v1, zero
800AA588	lw     a0, $001c(v0)
800AA58C	addiu  v0, zero, $ffff (=-$1)
800AA590	sw     zero, $0010(sp)
800AA594	sw     v0, $0014(sp)
800AA598	sw     zero, $0018(sp)
800AA59C	lw     a1, $0004(s1)
800AA5A0	jal    func2177c [$8002177c]
800AA5A4	addiu  a0, a0, $0854

loopaa5a8:	; 800AA5A8
800AA5A8	lw     v0, $794c(s0)
800AA5AC	nop
800AA5B0	lw     a0, $001c(v0)
800AA5B4	jal    func217c4 [$800217c4]
800AA5B8	addiu  a0, a0, $0854
800AA5BC	bne    v0, zero, loopaa5a8 [$800aa5a8]
800AA5C0	nop
800AA5C4	lw     v0, $0004(s2)
800AA5C8	nop
800AA5CC	beq    v0, zero, Laa600 [$800aa600]
800AA5D0	addu   a2, s3, zero

Laa5d4:	; 800AA5D4
800AA5D4	lui    s1, $8006
800AA5D8	lw     a0, $7948(s1)
800AA5DC	lw     a1, $0004(s2)
800AA5E0	jal    func1daa4 [$8001daa4]
800AA5E4	addu   a3, zero, zero
800AA5E8	addu   a0, zero, zero
800AA5EC	jal    func130a4 [$800130a4]
800AA5F0	addu   s0, v0, zero
800AA5F4	lw     a0, $7948(s1)
800AA5F8	jal    funcac67c [$800ac67c]
800AA5FC	addu   a0, a0, s0

Laa600:	; 800AA600
800AA600	addiu  a0, zero, $0004
800AA604	lui    a1, $001c
800AA608	jal    func1c7fc [$8001c7fc]
800AA60C	addu   a2, zero, zero
800AA610	addiu  a1, zero, $0002
800AA614	lui    a2, $001b
800AA618	addu   a3, zero, zero
800AA61C	lui    v1, $8006
800AA620	addu   s2, a3, zero
800AA624	lw     s0, $7948(v1)
800AA628	addu   s1, v0, zero
800AA62C	jal    func1c8b0 [$8001c8b0]
800AA630	addu   a0, s0, zero
800AA634	addu   a0, s0, zero
800AA638	addiu  a1, zero, $0002
800AA63C	lui    a2, $001b
800AA640	ori    a2, a2, $0001
800AA644	addu   a3, zero, zero
800AA648	jal    func1c8b0 [$8001c8b0]
800AA64C	sw     v0, $0024(sp)
800AA650	addiu  a1, zero, $0002
800AA654	lui    a2, $0012
800AA658	lw     a0, $0024(sp)
800AA65C	addu   a3, zero, zero
800AA660	jal    func1c8b0 [$8001c8b0]
800AA664	sw     v0, $0020(sp)
800AA668	lui    v1, $00ff
800AA66C	addiu  s6, v0, $0004
800AA670	lw     v0, $0004(s6)
800AA674	ori    v1, v1, $ffff
800AA678	and    v0, v0, v1
800AA67C	lbu    v1, $0007(s6)
800AA680	addu   fp, s6, v0
800AA684	sll    v0, v1, $02
800AA688	addu   s7, fp, v0
800AA68C	addu   v0, s7, v0
800AA690	beq    v1, zero, Laa7cc [$800aa7cc]
800AA694	sw     v0, $0028(sp)
800AA698	addu   s0, v0, zero
800AA69C	addu   s4, s7, zero
800AA6A0	addu   s3, fp, zero

loopaa6a4:	; 800AA6A4
800AA6A4	addiu  a1, zero, $0002
800AA6A8	andi   v0, s2, $ffff
800AA6AC	lui    a2, $0004
800AA6B0	or     a2, v0, a2
800AA6B4	lw     a0, $0020(sp)
800AA6B8	jal    func1c8b0 [$8001c8b0]
800AA6BC	addu   a3, zero, zero
800AA6C0	lh     v1, $0000(s0)
800AA6C4	nop
800AA6C8	andi   v1, v1, $0001
800AA6CC	beq    v1, zero, Laa7b0 [$800aa7b0]
800AA6D0	addu   s5, v0, zero
800AA6D4	addiu  v0, zero, $0100
800AA6D8	lhu    a0, $0000(s1)
800AA6DC	lh     a3, $0000(s1)
800AA6E0	lh     t0, $0002(s1)
800AA6E4	lhu    v1, $0002(s1)
800AA6E8	bne    t0, v0, Laa6fc [$800aa6fc]
800AA6EC	addiu  v0, a0, $0040
800AA6F0	sh     v0, $0000(s1)
800AA6F4	j      Laa700 [$800aa700]
800AA6F8	addiu  v0, zero, $0180

Laa6fc:	; 800AA6FC
800AA6FC	addiu  v0, v1, $ff80 (=-$80)

Laa700:	; 800AA700
800AA700	sh     v0, $0002(s1)
800AA704	lh     v1, $0000(s1)
800AA708	lh     v0, $0020(s1)
800AA70C	lhu    a0, $0000(s1)
800AA710	bne    v1, v0, Laa720 [$800aa720]
800AA714	addu   t1, t0, zero
800AA718	addiu  v0, a0, $0040
800AA71C	sh     v0, $0000(s1)

Laa720:	; 800AA720
800AA720	andi   v1, t0, $0100
800AA724	sra    v1, v1, $04
800AA728	lhu    v0, $000a(s1)
800AA72C	lh     a2, $000a(s1)
800AA730	lhu    a0, $0008(s1)
800AA734	addiu  v0, v0, $0002
800AA738	sh     v0, $000a(s1)
800AA73C	andi   v0, a3, $03ff
800AA740	sra    v0, v0, $06
800AA744	ori    v0, v0, $0080
800AA748	or     v1, v1, v0
800AA74C	andi   v0, t0, $0200
800AA750	sll    v0, v0, $02
800AA754	or     v1, v1, v0
800AA758	sll    a0, a0, $10
800AA75C	sh     v1, $0000(s3)
800AA760	sll    v1, a2, $06
800AA764	sra    v0, a0, $14
800AA768	andi   v0, v0, $003f
800AA76C	or     v1, v1, v0
800AA770	sra    a1, a0, $10
800AA774	sh     v1, $0002(s3)
800AA778	bgez   t0, Laa784 [$800aa784]
800AA77C	sh     zero, $0000(s4)
800AA780	addiu  t1, t0, $00ff

Laa784:	; 800AA784
800AA784	addu   a0, s5, zero
800AA788	sra    v0, t1, $08
800AA78C	sll    v0, v0, $08
800AA790	subu   v0, t0, v0
800AA794	sh     v0, $0002(s4)
800AA798	sh     a3, $0004(s0)
800AA79C	sh     t0, $0006(s0)
800AA7A0	jal    func1d9cc [$8001d9cc]
800AA7A4	sw     t0, $0010(sp)
800AA7A8	jal    func1d8a8 [$8001d8a8]
800AA7AC	addu   a0, s5, zero

Laa7b0:	; 800AA7B0
800AA7B0	addiu  s0, s0, $0008
800AA7B4	addiu  s4, s4, $0004
800AA7B8	lbu    v0, $0007(s6)
800AA7BC	addiu  s2, s2, $0001
800AA7C0	slt    v0, s2, v0
800AA7C4	bne    v0, zero, loopaa6a4 [$800aa6a4]
800AA7C8	addiu  s3, s3, $0004

Laa7cc:	; 800AA7CC
800AA7CC	lbu    v0, $0007(s6)
800AA7D0	nop
800AA7D4	beq    v0, zero, Laa988 [$800aa988]
800AA7D8	addu   s2, zero, zero
800AA7DC	lw     s0, $0028(sp)
800AA7E0	addu   s4, s7, zero
800AA7E4	addu   s3, fp, zero

Laa7e8:	; 800AA7E8
800AA7E8	addiu  a1, zero, $0002
800AA7EC	andi   v0, s2, $ffff
800AA7F0	lui    a2, $0004
800AA7F4	or     a2, v0, a2
800AA7F8	lw     a0, $0020(sp)
800AA7FC	jal    func1c8b0 [$8001c8b0]
800AA800	addu   a3, zero, zero
800AA804	lh     t2, $0000(s0)
800AA808	addu   s5, v0, zero
800AA80C	andi   v0, t2, $0001
800AA810	bne    v0, zero, Laa96c [$800aa96c]
800AA814	nop
800AA818	lh     t1, $0012(s1)
800AA81C	lhu    a0, $0010(s1)
800AA820	lh     a3, $0010(s1)
800AA824	lhu    v1, $0012(s1)
800AA828	slti   v0, t1, $01e0
800AA82C	bne    v0, zero, Laa858 [$800aa858]
800AA830	addiu  v0, a0, $ffc0 (=-$40)
800AA834	sh     v0, $0010(s1)
800AA838	j      Laa85c [$800aa85c]
800AA83C	addiu  v0, zero, $0100

loopaa840:	; 800AA840
800AA840	lhu    v0, $0004(v1)
800AA844	nop
800AA848	sh     v0, $0004(s0)
800AA84C	lhu    v0, $0006(v1)
800AA850	j      Laa958 [$800aa958]
800AA854	sh     v0, $0006(s0)

Laa858:	; 800AA858
800AA858	addiu  v0, v1, $0020

Laa85c:	; 800AA85C
800AA85C	sh     v0, $0012(s1)
800AA860	addu   t0, t1, zero
800AA864	andi   v1, t1, $0100
800AA868	sra    v1, v1, $04
800AA86C	lhu    v0, $001a(s1)
800AA870	lh     a2, $001a(s1)
800AA874	lhu    a0, $0018(s1)
800AA878	addiu  v0, v0, $0002
800AA87C	sh     v0, $001a(s1)
800AA880	andi   v0, a3, $03ff
800AA884	sra    v0, v0, $06
800AA888	ori    v0, v0, $0080
800AA88C	or     v1, v1, v0
800AA890	andi   v0, t1, $0200
800AA894	sll    v0, v0, $02
800AA898	or     v1, v1, v0
800AA89C	sll    a0, a0, $10

Laa8a0:	; 800AA8A0
800AA8A0	sh     v1, $0000(s3)
800AA8A4	sll    v1, a2, $06
800AA8A8	sra    v0, a0, $14
800AA8AC	andi   v0, v0, $003f
800AA8B0	or     v1, v1, v0
800AA8B4	sra    a1, a0, $10
800AA8B8	sh     v1, $0002(s3)
800AA8BC	bgez   t1, Laa8c8 [$800aa8c8]
800AA8C0	sh     zero, $0000(s4)
800AA8C4	addiu  t0, t1, $00ff

Laa8c8:	; 800AA8C8
800AA8C8	addiu  v1, t2, $fffe (=-$2)
800AA8CC	addu   a0, v1, zero
800AA8D0	sra    v0, t0, $08
800AA8D4	sll    v0, v0, $08
800AA8D8	bgez   v1, Laa8e4 [$800aa8e4]
800AA8DC	subu   t0, t1, v0
800AA8E0	addiu  a0, t2, $0005

Laa8e4:	; 800AA8E4
800AA8E4	sra    v0, a0, $03
800AA8E8	sll    v0, v0, $03
800AA8EC	subu   v0, v1, v0
800AA8F0	sll    a0, v0, $05
800AA8F4	addiu  v1, a0, $0100
800AA8F8	bgez   v1, Laa904 [$800aa904]
800AA8FC	addu   v0, v1, zero
800AA900	addiu  v0, a0, $017f

Laa904:	; 800AA904
800AA904	sra    v0, v0, $07
800AA908	sll    v0, v0, $07
800AA90C	subu   v0, v1, v0
800AA910	subu   v0, t0, v0
800AA914	sh     v0, $0002(s4)
800AA918	sh     a3, $0000(s0)
800AA91C	sh     t1, $0002(s0)
800AA920	lbu    v0, $0007(s6)

Laa924:	; 800AA924
800AA924	nop
800AA928	addiu  a0, v0, $ffff (=-$1)
800AA92C	bltz   a0, Laa958 [$800aa958]
800AA930	addiu  t0, t2, $ffff (=-$1)
800AA934	lw     t3, $0028(sp)
800AA938	sll    v0, a0, $03
800AA93C	addu   v1, v0, t3

loopaa940:	; 800AA940
800AA940	lh     v0, $0000(v1)
800AA944	nop
800AA948	beq    v0, t0, loopaa840 [$800aa840]
800AA94C	addiu  a0, a0, $ffff (=-$1)
800AA950	bgez   a0, loopaa940 [$800aa940]
800AA954	addiu  v1, v1, $fff8 (=-$8)

Laa958:	; 800AA958
800AA958	sw     t1, $0010(sp)
800AA95C	jal    func1d9cc [$8001d9cc]
800AA960	addu   a0, s5, zero
800AA964	jal    func1d8a8 [$8001d8a8]
800AA968	addu   a0, s5, zero

Laa96c:	; 800AA96C
800AA96C	addiu  s0, s0, $0008
800AA970	addiu  s4, s4, $0004
800AA974	lbu    v0, $0007(s6)
800AA978	addiu  s2, s2, $0001
800AA97C	slt    v0, s2, v0
800AA980	bne    v0, zero, Laa7e8 [$800aa7e8]
800AA984	addiu  s3, s3, $0004

Laa988:	; 800AA988
800AA988	jal    func130a4 [$800130a4]
800AA98C	addu   a0, zero, zero
800AA990	lui    v0, $8006
800AA994	lw     a0, $794c(v0)
800AA998	nop
800AA99C	lw     v0, $001c(a0)
800AA9A0	nop
800AA9A4	lw     v0, $08e4(v0)
800AA9A8	nop
800AA9AC	lw     v0, $000c(v0)
800AA9B0	nop
800AA9B4	lw     v1, $0014(v0)

Laa9b8:	; 800AA9B8
800AA9B8	lw     t3, $0024(sp)

Laa9bc:	; 800AA9BC
800AA9BC	lbu    v0, $0040(v1)
800AA9C0	lw     v1, $0028(v1)
800AA9C4	sll    v0, v0, $02
800AA9C8	addu   v0, v0, v1
800AA9CC	sw     t3, $0000(v0)
800AA9D0	lw     v0, $001c(a0)
800AA9D4	nop
800AA9D8	lw     v0, $08e4(v0)
800AA9DC	nop
800AA9E0	lw     v0, $000c(v0)
800AA9E4	nop
800AA9E8	lw     v1, $0014(v0)
800AA9EC	addu   a1, zero, zero
800AA9F0	lbu    v0, $0040(v1)
800AA9F4	lw     a0, $0024(sp)
800AA9F8	addiu  v0, v0, $0001
800AA9FC	jal    func1c750 [$8001c750]
800AAA00	sb     v0, $0040(v1)
800AAA04	lw     a0, $0024(sp)
800AAA08	jal    func1ca70 [$8001ca70]
800AAA0C	nop
800AAA10	lui    v1, $8006
800AAA14	lw     t3, $0024(sp)
800AAA18	lw     ra, $0054(sp)
800AAA1C	lw     fp, $0050(sp)
800AAA20	lw     s7, $004c(sp)
800AAA24	lw     s6, $0048(sp)
800AAA28	lw     s5, $0044(sp)
800AAA2C	lw     s4, $0040(sp)
800AAA30	lw     s3, $003c(sp)
800AAA34	lw     s2, $0038(sp)
800AAA38	lw     s1, $0034(sp)
800AAA3C	lw     s0, $0030(sp)
800AAA40	addu   a0, t3, v0
800AAA44	addu   v0, zero, zero
800AAA48	sw     a0, $7948(v1)
800AAA4C	jr     ra 
800AAA50	addiu  sp, sp, $0058


funcaaa54:	; 800AAA54
800AAA54	lui    v1, $8006
800AAA58	lw     v0, $794c(v1)
800AAA5C	addiu  sp, sp, $ffe0 (=-$20)
800AAA60	sw     ra, $0018(sp)
800AAA64	sw     s1, $0014(sp)
800AAA68	sw     s0, $0010(sp)
800AAA6C	lw     v0, $001c(v0)
800AAA70	nop
800AAA74	lw     v0, $08e4(v0)
800AAA78	nop
800AAA7C	lw     v0, $000c(v0)
800AAA80	nop
800AAA84	lw     v0, $0014(v0)
800AAA88	nop
800AAA8C	lbu    v0, $0040(v0)
800AAA90	nop
800AAA94	addiu  s0, v0, $ffff (=-$1)
800AAA98	bltz   s0, Laaae8 [$800aaae8]
800AAA9C	addu   s1, v1, zero

loopaaaa0:	; 800AAAA0
800AAAA0	lw     v0, $794c(s1)
800AAAA4	nop
800AAAA8	lw     v0, $001c(v0)
800AAAAC	nop
800AAAB0	lw     v0, $08e4(v0)
800AAAB4	nop
800AAAB8	lw     v0, $000c(v0)
800AAABC	nop
800AAAC0	lw     v0, $0014(v0)
800AAAC4	nop
800AAAC8	lw     v1, $0028(v0)
800AAACC	sll    v0, s0, $02
800AAAD0	addu   v0, v0, v1
800AAAD4	lw     a0, $0000(v0)
800AAAD8	jal    func1c784 [$8001c784]
800AAADC	addiu  s0, s0, $ffff (=-$1)
800AAAE0	bgez   s0, loopaaaa0 [$800aaaa0]
800AAAE4	nop

Laaae8:	; 800AAAE8
800AAAE8	lui    v0, $8006
800AAAEC	lw     v0, $794c(v0)
800AAAF0	nop
800AAAF4	lw     v0, $001c(v0)
800AAAF8	nop
800AAAFC	lw     v0, $08e4(v0)
800AAB00	nop
800AAB04	lw     v0, $000c(v0)
800AAB08	nop
800AAB0C	lw     v1, $0014(v0)
800AAB10	nop
800AAB14	sb     zero, $0040(v1)
800AAB18	lw     ra, $0018(sp)
800AAB1C	lw     s1, $0014(sp)
800AAB20	lw     s0, $0010(sp)
800AAB24	addu   v0, zero, zero
800AAB28	jr     ra 
800AAB2C	addiu  sp, sp, $0020

800AAB30	addiu  sp, sp, $ffc0 (=-$40)
800AAB34	sw     s3, $002c(sp)
800AAB38	addu   s3, a0, zero
800AAB3C	sw     s1, $0024(sp)
800AAB40	addu   s1, a1, zero
800AAB44	sw     s5, $0034(sp)
800AAB48	addiu  s5, zero, $ffff (=-$1)
800AAB4C	addu   a0, s1, zero
800AAB50	sw     ra, $0038(sp)
800AAB54	sw     s4, $0030(sp)
800AAB58	sw     s2, $0028(sp)
800AAB5C	jal    func4ab64 [$8004ab64]
800AAB60	sw     s0, $0020(sp)
800AAB64	addu   a0, v0, zero
800AAB68	sltiu  v0, a0, $0009
800AAB6C	beq    v0, zero, Laab84 [$800aab84]
800AAB70	lui    s0, $8006
800AAB74	jal    func1e350 [$8001e350]
800AAB78	addu   s4, a0, zero
800AAB7C	j      Laabc8 [$800aabc8]
800AAB80	addu   s2, v0, zero

Laab84:	; 800AAB84
800AAB84	lw     v0, $794c(s0)
800AAB88	nop
800AAB8C	lw     v0, $001c(v0)
800AAB90	nop
800AAB94	lbu    v0, $0039(v0)
800AAB98	nop
800AAB9C	addiu  s4, v0, $0009

Laaba0:	; 800AABA0
800AABA0	jal    func1e350 [$8001e350]
800AABA4	addu   a0, s4, zero
800AABA8	lw     v1, $794c(s0)
800AABAC	nop
800AABB0	lw     a0, $001c(v1)
800AABB4	nop
800AABB8	lbu    v1, $0039(a0)
800AABBC	addu   s2, v0, zero
800AABC0	addiu  v1, v1, $0001

funcaabc4:	; 800AABC4
800AABC4	sb     v1, $0039(a0)

Laabc8:	; 800AABC8
800AABC8	jal    funcaaec4 [$800aaec4]
800AABCC	addu   a0, s3, zero
800AABD0	addu   s3, v0, zero
800AABD4	addiu  a0, zero, $0004
800AABD8	addu   a1, s3, zero
800AABDC	addu   a2, zero, zero
800AABE0	sw     s3, $0004(s2)
800AABE4	jal    func1c7fc [$8001c7fc]
800AABE8	sw     s1, $000c(s2)
800AABEC	lw     v1, $0008(s2)
800AABF0	addu   a0, s3, zero
800AABF4	jal    funcaaf5c [$800aaf5c]
800AABF8	sw     v0, $0008(v1)
800AABFC	addiu  a0, zero, $0004
800AAC00	addu   a1, v0, zero
800AAC04	jal    func1c7fc [$8001c7fc]
800AAC08	addu   a2, zero, zero
800AAC0C	lw     v1, $0008(s2)
800AAC10	beq    v0, zero, Laac60 [$800aac60]
800AAC14	sw     v0, $000c(v1)
800AAC18	lw     v0, $0008(s2)
800AAC1C	nop
800AAC20	lw     v1, $000c(v0)
800AAC24	nop
800AAC28	lw     v0, $000c(v1)
800AAC2C	nop
800AAC30	bltz   v0, Laac60 [$800aac60]
800AAC34	addu   v0, v1, v0
800AAC38	lw     a0, $0010(v1)

Laac3c:	; 800AAC3C
800AAC3C	nop

Laac40:	; 800AAC40
800AAC40	beq    a0, zero, Laac60 [$800aac60]
800AAC44	sw     v0, $000c(v1)
800AAC48	lw     v0, $0008(s2)
800AAC4C	nop
800AAC50	lw     v0, $000c(v0)
800AAC54	nop
800AAC58	addu   v0, v0, a0
800AAC5C	sw     v0, $0010(v1)

Laac60:	; 800AAC60
800AAC60	addu   a0, s3, zero
800AAC64	addiu  a1, sp, $0010
800AAC68	addiu  a2, sp, $0014
800AAC6C	jal    funcaafd4 [$800aafd4]
800AAC70	addiu  a3, sp, $0018
800AAC74	lw     v0, $0008(s2)
800AAC78	nop
800AAC7C	lw     v0, $0008(v0)
800AAC80	nop
800AAC84	lw     v1, $0010(v0)
800AAC88	nop
800AAC8C	bltz   v1, Laac98 [$800aac98]
800AAC90	addu   s1, zero, zero
800AAC94	addu   v1, v1, v0

Laac98:	; 800AAC98
800AAC98	lbu    a1, $0003(v0)
800AAC9C	nop
800AACA0	sltu   v0, s1, a1
800AACA4	beq    v0, zero, Laacc4 [$800aacc4]
800AACA8	addu   a0, zero, zero

loopaacac:	; 800AACAC
800AACAC	lhu    v0, $0000(v1)
800AACB0	addiu  a0, a0, $0001
800AACB4	addu   s1, s1, v0
800AACB8	sltu   v0, a0, a1
800AACBC	bne    v0, zero, loopaacac [$800aacac]
800AACC0	addiu  v1, v1, $0028

Laacc4:	; 800AACC4
800AACC4	lui    s0, $8006
800AACC8	sll    s1, s1, $01
800AACCC	lw     v0, $794c(s0)
800AACD0	lw     a0, $0008(s2)
800AACD4	lw     v0, $001c(v0)
800AACD8	lw     a2, $0008(a0)
800AACDC	lw     v0, $08e4(v0)
800AACE0	lbu    v1, $0002(a2)
800AACE4	lw     v0, $000c(v0)
800AACE8	lbu    a2, $0003(a2)
800AACEC	lw     v0, $0014(v0)
800AACF0	sll    v1, v1, $05
800AACF4	lw     a1, $0020(v0)
800AACF8	sll    v0, a2, $01
800AACFC	addu   v0, v0, a2
800AAD00	sll    v0, v0, $02
800AAD04	addu   v1, v1, v0
800AAD08	jal    funcb6438 [$800b6438]
800AAD0C	addu   s1, s1, v1

A0 = w[S2 + 8];
A1 = w[SP + 10];
A2 = w[SP + 14];
funcb6584; // we prepare render packets here

800AAD24	lw     v0, $794c(s0)
800AAD28	nop
800AAD2C	lw     v0, $001c(v0)
800AAD30	nop
800AAD34	lw     v0, $08e4(v0)
800AAD38	nop
800AAD3C	lw     v0, $000c(v0)
800AAD40	nop
800AAD44	lw     v1, $0014(v0)
800AAD48	nop
800AAD4C	lw     v0, $0020(v1)
800AAD50	nop
800AAD54	addu   v0, v0, s1
800AAD58	jal    funcac620 [$800ac620]
800AAD5C	sw     v0, $0020(v1)
800AAD60	addiu  a0, zero, $0008
800AAD64	addu   a1, s3, zero
800AAD68	jal    func1c7fc [$8001c7fc]
800AAD6C	lui    a2, $0012
800AAD70	addu   a0, v0, zero
800AAD74	lbu    v0, $0001(a0)
800AAD78	nop
800AAD7C	addiu  v1, v0, $ffff (=-$1)
800AAD80	bltz   v1, Laadb4 [$800aadb4]
800AAD84	addiu  a2, a0, $0004
800AAD88	lhu    a1, $0004(a0)
800AAD8C	andi   a0, s3, $ffff
800AAD90	lui    a3, $0019

loopaad94:	; 800AAD94
800AAD94	bne    a1, a0, Laada8 [$800aada8]
800AAD98	nop
800AAD9C	lhu    v0, $0008(a2)
800AADA0	nop
800AADA4	or     s5, v0, a3

Laada8:	; 800AADA8
800AADA8	addiu  v1, v1, $ffff (=-$1)
800AADAC	bgez   v1, loopaad94 [$800aad94]
800AADB0	nop

Laadb4:	; 800AADB4
800AADB4	addiu  v0, zero, $ffff (=-$1)
800AADB8	beq    s5, v0, Laadec [$800aadec]
800AADBC	addiu  a0, zero, $0004
800AADC0	addu   a1, s5, zero
800AADC4	jal    func1c7fc [$8001c7fc]
800AADC8	addu   a2, zero, zero
800AADCC	lw     v1, $0008(s2)
800AADD0	nop
800AADD4	sw     v0, $0050(v1)

Laadd8:	; 800AADD8
800AADD8	lw     v0, $0008(s2)
800AADDC	lw     a1, $0018(sp)
800AADE0	lw     a0, $0050(v0)
800AADE4	jal    funcbb3c4 [$800bb3c4]
800AADE8	nop

Laadec:	; 800AADEC
800AADEC	lui    v0, $8006
800AADF0	lw     v0, $794c(v0)
800AADF4	nop
800AADF8	lw     v0, $001c(v0)
800AADFC	nop
800AAE00	lw     v0, $08e4(v0)
800AAE04	nop
800AAE08	lw     v0, $000c(v0)
800AAE0C	nop
800AAE10	lw     v0, $0014(v0)
800AAE14	nop
800AAE18	lw     v0, $0018(v0)
800AAE1C	nop
800AAE20	beq    v0, zero, Laae54 [$800aae54]
800AAE24	slti   v0, s4, $0009
800AAE28	beq    v0, zero, Laae40 [$800aae40]
800AAE2C	addu   a0, s4, zero
800AAE30	jal    funcc74a8 [$800c74a8]
800AAE34	addu   a1, s2, zero
800AAE38	j      Laae4c [$800aae4c]
800AAE3C	addu   a0, s4, zero

Laae40:	; 800AAE40
800AAE40	jal    funcc74f0 [$800c74f0]
800AAE44	addu   a0, s2, zero
800AAE48	addu   a0, s4, zero

Laae4c:	; 800AAE4C
800AAE4C	jal    funcc3e18 [$800c3e18]
800AAE50	addiu  a1, zero, $0001

Laae54:	; 800AAE54
800AAE54	lui    v0, $8006
800AAE58	lw     v0, $794c(v0)
800AAE5C	nop
800AAE60	lw     v0, $001c(v0)
800AAE64	nop
800AAE68	lw     v0, $08e4(v0)
800AAE6C	nop
800AAE70	lw     v0, $000c(v0)
800AAE74	nop
800AAE78	lw     a0, $0014(v0)
800AAE7C	nop
800AAE80	lw     v0, $0000(a0)
800AAE84	lui    v1, $0001
800AAE88	or     v0, v0, v1
800AAE8C	sw     v0, $0000(a0)
800AAE90	lw     v1, $0000(s2)
800AAE94	addu   v0, s4, zero
800AAE98	ori    v1, v1, $0001
800AAE9C	sw     v1, $0000(s2)
800AAEA0	lw     ra, $0038(sp)
800AAEA4	lw     s5, $0034(sp)
800AAEA8	lw     s4, $0030(sp)
800AAEAC	lw     s3, $002c(sp)
800AAEB0	lw     s2, $0028(sp)
800AAEB4	lw     s1, $0024(sp)
800AAEB8	lw     s0, $0020(sp)

Laaebc:	; 800AAEBC
800AAEBC	jr     ra 
800AAEC0	addiu  sp, sp, $0040


funcaaec4:	; 800AAEC4
800AAEC4	andi   v1, a0, $ffff
800AAEC8	addiu  v0, zero, $00b9
800AAECC	bne    v1, v0, Laaef0 [$800aaef0]
800AAED0	lui    v0, $8008
800AAED4	lh     v0, $aef0(v0)
800AAED8	nop
800AAEDC	slti   v0, v0, $283c
800AAEE0	bne    v0, zero, Laaef0 [$800aaef0]
800AAEE4	nop
800AAEE8	lui    a0, $0002
800AAEEC	ori    a0, a0, $004c

Laaef0:	; 800AAEF0
800AAEF0	jr     ra 
800AAEF4	addu   v0, a0, zero


funcaaef8:	; 800AAEF8
800AAEF8	lui    v0, $8006
800AAEFC	lw     v0, $794c(v0)
800AAF00	nop
800AAF04	lw     v0, $001c(v0)
800AAF08	nop
800AAF0C	lw     v1, $07e4(v0)
800AAF10	nop
800AAF14	lhu    v0, $0002(v1)
800AAF18	nop
800AAF1C	addiu  a1, v0, $ffff (=-$1)
800AAF20	bltz   a1, Laaf54 [$800aaf54]
800AAF24	addiu  v1, v1, $0004
800AAF28	sll    v0, a1, $04
800AAF2C	addu   v1, v0, v1

loopaaf30:	; 800AAF30
800AAF30	lw     v0, $000c(v1)
800AAF34	nop
800AAF38	bne    v0, a0, Laaf4c [$800aaf4c]
800AAF3C	addiu  a1, a1, $ffff (=-$1)
800AAF40	lw     v0, $0000(v1)
800AAF44	jr     ra 
800AAF48	nop


Laaf4c:	; 800AAF4C
800AAF4C	bgez   a1, loopaaf30 [$800aaf30]
800AAF50	addiu  v1, v1, $fff0 (=-$10)

Laaf54:	; 800AAF54
800AAF54	jr     ra 
800AAF58	addiu  v0, zero, $ffff (=-$1)


funcaaf5c:	; 800AAF5C
800AAF5C	addiu  sp, sp, $ffe8 (=-$18)
800AAF60	sw     s0, $0010(sp)
800AAF64	addu   s0, a0, zero
800AAF68	addiu  a0, zero, $0008
800AAF6C	addu   a1, s0, zero
800AAF70	sw     ra, $0014(sp)
800AAF74	jal    func1c7fc [$8001c7fc]
800AAF78	lui    a2, $0012
800AAF7C	addu   v1, v0, zero
800AAF80	lbu    v0, $0001(v1)
800AAF84	nop
800AAF88	addiu  v0, v0, $ffff (=-$1)
800AAF8C	bltz   v0, Laafc0 [$800aafc0]
800AAF90	addiu  a1, v1, $0004
800AAF94	lhu    v1, $0004(v1)
800AAF98	andi   a0, s0, $ffff
800AAF9C	lui    a2, $0003

loopaafa0:	; 800AAFA0
800AAFA0	bne    v1, a0, Laafb4 [$800aafb4]
800AAFA4	nop
800AAFA8	lhu    v0, $0002(a1)
800AAFAC	j      Laafc4 [$800aafc4]
800AAFB0	or     v0, v0, a2

Laafb4:	; 800AAFB4
800AAFB4	addiu  v0, v0, $ffff (=-$1)
800AAFB8	bgez   v0, loopaafa0 [$800aafa0]
800AAFBC	nop

Laafc0:	; 800AAFC0
800AAFC0	addiu  v0, zero, $ffff (=-$1)

Laafc4:	; 800AAFC4
800AAFC4	lw     ra, $0014(sp)
800AAFC8	lw     s0, $0010(sp)
800AAFCC	jr     ra 
800AAFD0	addiu  sp, sp, $0018



////////////////////////////////
// funcaafd4
800AAFD4
S0 = A0;
S1 = A1;
S2 = A2;
S3 = A3;

A0 = 8;
A1 = S0;
A2 = 120000;
func1c7fc;

A2 = V0;

V0 = bu[A2 + 1];
if (V0 - 1 >= 0)
{
    loopab034:	; 800AB034
        if (hu[A2 + 4] == S0 & ffff))
        {
            V0 = A2 + 4 + w[A2 + 8] & 00ffffff;
            [S1] = w(V0);
            V0 = V0 + bu[A2 + b] * 4;
            [S2] = w(V0);
            [S3] = w(V0 + bu[A2 + b] * 4);

            return;
        }

        A2 = A2 + c;
        V1 = V1 - 1;
    800AB088	bgez   v1, loopab034 [$800ab034]
}

800AB0AC
////////////////////////////////



funcab0b0:	; 800AB0B0
800AB0B0	lw     a0, $0050(a0)
800AB0B4	nop
800AB0B8	beq    a0, zero, Lab108 [$800ab108]
800AB0BC	nop
800AB0C0	lhu    v0, $0000(a0)
800AB0C4	nop
800AB0C8	addiu  v1, v0, $ffff (=-$1)
800AB0CC	bltz   v1, Lab108 [$800ab108]
800AB0D0	addiu  a0, a0, $0004
800AB0D4	sll    v0, v1, $02
800AB0D8	addu   v0, v0, v1
800AB0DC	sll    v0, v0, $02
800AB0E0	addu   a0, v0, a0

loopab0e4:	; 800AB0E4
800AB0E4	lbu    v0, $0000(a0)
800AB0E8	nop
800AB0EC	andi   v0, v0, $0001
800AB0F0	beq    v0, zero, Lab100 [$800ab100]
800AB0F4	addiu  v1, v1, $ffff (=-$1)
800AB0F8	jr     ra 
800AB0FC	addiu  v0, zero, $0001


Lab100:	; 800AB100
800AB100	bgez   v1, loopab0e4 [$800ab0e4]
800AB104	addiu  a0, a0, $ffec (=-$14)

Lab108:	; 800AB108
800AB108	jr     ra 
800AB10C	addu   v0, zero, zero


funcab110:	; 800AB110
800AB110	addiu  sp, sp, $ffd0 (=-$30)
800AB114	sw     s3, $001c(sp)
800AB118	addu   s3, a0, zero
800AB11C	sw     s1, $0014(sp)
800AB120	addu   s1, zero, zero
800AB124	sw     ra, $0028(sp)
800AB128	sw     s5, $0024(sp)
800AB12C	sw     s4, $0020(sp)
800AB130	sw     s2, $0018(sp)
800AB134	jal    func4ae9c [$8004ae9c]
800AB138	sw     s0, $0010(sp)
800AB13C	addu   s0, v0, zero
800AB140	beq    s0, zero, Lab1d4 [$800ab1d4]
800AB144	nop
800AB148	addiu  s5, zero, $0001
800AB14C	addiu  s4, zero, $0004
800AB150	addu   s2, s3, zero

loopab154:	; 800AB154
800AB154	lw     a0, $0004(s0)
800AB158	nop
800AB15C	lbu    v0, $000e(a0)
800AB160	nop
800AB164	bne    v0, s5, Lab1c4 [$800ab1c4]
800AB168	nop
800AB16C	lbu    v0, $000f(a0)
800AB170	nop
800AB174	andi   v0, v0, $0001
800AB178	beq    v0, zero, Lab1c4 [$800ab1c4]
800AB17C	nop
800AB180	lbu    v0, $0005(a0)
800AB184	nop
800AB188	bne    v0, s4, Lab1c4 [$800ab1c4]
800AB18C	nop
800AB190	lbu    a0, $003b(a0)

Lab194:	; 800AB194
800AB194	jal    func1e350 [$8001e350]
800AB198	nop
800AB19C	addu   a0, v0, zero
800AB1A0	lw     v0, $0008(a0)
800AB1A4	nop
800AB1A8	lw     v0, $001c(v0)
800AB1AC	nop
800AB1B0	bne    v0, zero, Lab1c4 [$800ab1c4]
800AB1B4	nop
800AB1B8	sw     a0, $0000(s2)
800AB1BC	addiu  s2, s2, $0004
800AB1C0	addiu  s1, s1, $0001

Lab1c4:	; 800AB1C4
800AB1C4	lw     s0, $0000(s0)
800AB1C8	nop
800AB1CC	bne    s0, zero, loopab154 [$800ab154]
800AB1D0	nop

Lab1d4:	; 800AB1D4
800AB1D4	jal    func4ae9c [$8004ae9c]
800AB1D8	nop
800AB1DC	addu   s0, v0, zero
800AB1E0	beq    s0, zero, Lab2a4 [$800ab2a4]
800AB1E4	lui    v0, $8006

loopab1e8:	; 800AB1E8
800AB1E8	lw     a0, $0004(s0)
800AB1EC	nop
800AB1F0	lbu    v1, $000e(a0)
800AB1F4	addiu  v0, zero, $0001
800AB1F8	bne    v1, v0, Lab294 [$800ab294]
800AB1FC	nop
800AB200	lbu    v0, $000f(a0)
800AB204	nop
800AB208	andi   v0, v0, $0001
800AB20C	beq    v0, zero, Lab294 [$800ab294]
800AB210	addiu  v0, zero, $0004
800AB214	lbu    v1, $0005(a0)
800AB218	nop
800AB21C	bne    v1, v0, Lab294 [$800ab294]
800AB220	nop
800AB224	lbu    a0, $003b(a0)
800AB228	jal    func1e350 [$8001e350]
800AB22C	nop
800AB230	addu   a0, v0, zero
800AB234	lw     v0, $0008(a0)
800AB238	nop
800AB23C	lw     a3, $001c(v0)
800AB240	nop
800AB244	beq    a3, zero, Lab294 [$800ab294]
800AB248	nop
800AB24C	blez   s1, Lab294 [$800ab294]
800AB250	addu   a2, zero, zero
800AB254	addu   v1, s3, zero
800AB258	sll    v0, s1, $02
800AB25C	addu   a1, v0, s3

loopab260:	; 800AB260
800AB260	lw     v0, $0000(v1)
800AB264	nop
800AB268	lw     v0, $0008(v0)

funcab26c:	; 800AB26C
800AB26C	nop
800AB270	bne    v0, a3, Lab284 [$800ab284]
800AB274	nop
800AB278	sw     a0, $0000(a1)
800AB27C	j      Lab294 [$800ab294]
800AB280	addiu  s1, s1, $0001

Lab284:	; 800AB284
800AB284	addiu  a2, a2, $0001
800AB288	slt    v0, a2, s1
800AB28C	bne    v0, zero, loopab260 [$800ab260]
800AB290	addiu  v1, v1, $0004

Lab294:	; 800AB294
800AB294	lw     s0, $0000(s0)
800AB298	nop
800AB29C	bne    s0, zero, loopab1e8 [$800ab1e8]
800AB2A0	lui    v0, $8006

Lab2a4:	; 800AB2A4
800AB2A4	lw     v0, $794c(v0)
800AB2A8	nop
800AB2AC	lw     v0, $001c(v0)
800AB2B0	nop
800AB2B4	lw     v0, $08e4(v0)
800AB2B8	nop
800AB2BC	lw     v0, $000c(v0)
800AB2C0	nop
800AB2C4	lw     v0, $0014(v0)

funcab2c8:	; 800AB2C8
800AB2C8	nop
800AB2CC	lb     v0, $0042(v0)
800AB2D0	nop
800AB2D4	beq    v0, zero, Lab3a8 [$800ab3a8]
800AB2D8	addu   v0, s1, zero
800AB2DC	blez   s1, Lab3a8 [$800ab3a8]
800AB2E0	addu   a2, zero, zero
800AB2E4	lui    v0, $000f
800AB2E8	ori    v0, v0, $1700
800AB2EC	lui    v1, $8006
800AB2F0	lw     v1, $7944(v1)
800AB2F4	addu   t1, s3, zero
800AB2F8	addu   t2, v1, v0

loopab2fc:	; 800AB2FC
800AB2FC	lw     v0, $0000(t1)
800AB300	nop
800AB304	lw     t0, $0008(v0)
800AB308	nop
800AB30C	lw     v0, $0008(t0)
800AB310	nop
800AB314	lw     v1, $0010(v0)
800AB318	nop
800AB31C	bltz   v1, Lab328 [$800ab328]
800AB320	addu   a1, zero, zero

funcab324:	; 800AB324
800AB324	addu   v1, v1, v0

Lab328:	; 800AB328
800AB328	lbu    a3, $0003(v0)
800AB32C	nop
800AB330	sltu   v0, a1, a3
800AB334	beq    v0, zero, Lab354 [$800ab354]
800AB338	addu   a0, zero, zero

loopab33c:	; 800AB33C
800AB33C	lhu    v0, $0000(v1)
800AB340	addiu  a0, a0, $0001
800AB344	addu   a1, a1, v0
800AB348	sltu   v0, a0, a3
800AB34C	bne    v0, zero, loopab33c [$800ab33c]
800AB350	addiu  v1, v1, $0028

Lab354:	; 800AB354
800AB354	lw     v0, $0008(t0)
800AB358	sll    a1, a1, $01
800AB35C	lbu    v1, $0002(v0)
800AB360	lbu    a0, $0003(v0)
800AB364	sll    v1, v1, $05
800AB368	sll    v0, a0, $01
800AB36C	addu   v0, v0, a0
800AB370	sll    v0, v0, $02
800AB374	addu   v1, v1, v0
800AB378	lw     v0, $0010(t0)
800AB37C	addu   a1, a1, v1
800AB380	addu   v0, v0, a1
800AB384	sltu   v0, v0, t2
800AB388	bne    v0, zero, Lab394 [$800ab394]
800AB38C	nop
800AB390	sw     zero, $0000(t1)

Lab394:	; 800AB394
800AB394	addiu  a2, a2, $0001
800AB398	slt    v0, a2, s1
800AB39C	bne    v0, zero, loopab2fc [$800ab2fc]
800AB3A0	addiu  t1, t1, $0004
800AB3A4	addu   v0, s1, zero

Lab3a8:	; 800AB3A8
800AB3A8	lw     ra, $0028(sp)
800AB3AC	lw     s5, $0024(sp)
800AB3B0	lw     s4, $0020(sp)
800AB3B4	lw     s3, $001c(sp)
800AB3B8	lw     s2, $0018(sp)
800AB3BC	lw     s1, $0014(sp)
800AB3C0	lw     s0, $0010(sp)
800AB3C4	jr     ra 
800AB3C8	addiu  sp, sp, $0030



////////////////////////////////
// funcab3cc
800AB3CC-800ABA94
////////////////////////////////



funcaba98:	; 800ABA98
800ABA98	lui    v0, $8006
800ABA9C	lw     v0, $794c(v0)
800ABAA0	addiu  sp, sp, $ffb8 (=-$48)
800ABAA4	sw     s5, $0034(sp)
800ABAA8	addu   s5, a1, zero
800ABAAC	sw     s6, $0038(sp)
800ABAB0	addu   s6, a2, zero
800ABAB4	sw     ra, $0044(sp)
800ABAB8	sw     fp, $0040(sp)
800ABABC	sw     s7, $003c(sp)
800ABAC0	sw     s4, $0030(sp)
800ABAC4	sw     s3, $002c(sp)

Labac8:	; 800ABAC8
800ABAC8	sw     s2, $0028(sp)
800ABACC	sw     s1, $0024(sp)
800ABAD0	sw     s0, $0020(sp)
800ABAD4	lw     v0, $001c(v0)
800ABAD8	addu   s7, a3, zero
800ABADC	lw     v0, $08e4(v0)
800ABAE0	lw     fp, $0058(sp)
800ABAE4	lw     v1, $000c(v0)
800ABAE8	sll    v0, a0, $02
800ABAEC	lw     v1, $0014(v1)
800ABAF0	addu   v0, v0, a0
800ABAF4	lw     v1, $0054(v1)
800ABAF8	sll    v0, v0, $02
800ABAFC	jal    func1e350 [$8001e350]
800ABB00	addu   s0, v1, v0
800ABB04	addu   s3, v0, zero
800ABB08	sltiu  v0, s5, $0014
800ABB0C	beq    v0, zero, Labff8 [$800abff8]
800ABB10	lui    v0, $800a
800ABB14	addiu  v0, v0, $7040
800ABB18	sll    v1, s5, $02
800ABB1C	addu   v1, v1, v0
800ABB20	lw     v0, $0000(v1)
800ABB24	nop
800ABB28	jr     v0 
800ABB2C	nop

800ABB30	andi   v1, s6, $00ff
800ABB34	addiu  v0, zero, $00ff
800ABB38	bne    v1, v0, Labb50 [$800abb50]
800ABB3C	lui    v1, $fffe
800ABB40	lw     v0, $0000(s3)

Labb44:	; 800ABB44
800ABB44	ori    v1, v1, $ffff
800ABB48	j      Labb7c [$800abb7c]
800ABB4C	and    v0, v0, v1

Labb50:	; 800ABB50
800ABB50	lb     v0, $0005(s0)
800ABB54	nop
800ABB58	beq    s6, v0, Labb70 [$800abb70]
800ABB5C	lui    v1, $0004

funcabb60:	; 800ABB60
800ABB60	lw     v0, $0000(s3)
800ABB64	nop
800ABB68	or     v0, v0, v1
800ABB6C	sw     v0, $0000(s3)

Labb70:	; 800ABB70
800ABB70	lw     v0, $0000(s3)
800ABB74	lui    v1, $0001
800ABB78	or     v0, v0, v1

Labb7c:	; 800ABB7C
800ABB7C	sw     v0, $0000(s3)
800ABB80	j      Labff8 [$800abff8]
800ABB84	sb     s6, $0005(s0)
800ABB88	beq    s6, zero, Labbb0 [$800abbb0]
800ABB8C	lui    v1, $0010
800ABB90	lw     v0, $0008(s3)
800ABB94	nop
800ABB98	sh     s7, $005a(v0)
800ABB9C	lw     v0, $0000(s3)
800ABBA0	nop
800ABBA4	or     v0, v0, v1
800ABBA8	j      Labff8 [$800abff8]
800ABBAC	sw     v0, $0000(s3)

Labbb0:	; 800ABBB0
800ABBB0	lui    v1, $ffef
800ABBB4	lw     v0, $0000(s3)
800ABBB8	ori    v1, v1, $ffff
800ABBBC	and    v0, v0, v1
800ABBC0	j      Labff8 [$800abff8]

funcabbc4:	; 800ABBC4
800ABBC4	sw     v0, $0000(s3)
800ABBC8	lw     s1, $0010(s0)
800ABBCC	nop
800ABBD0	bne    s1, zero, Labc84 [$800abc84]
800ABBD4	lui    v0, $8006
800ABBD8	lw     a0, $794c(v0)
800ABBDC	nop
800ABBE0	lw     v0, $001c(a0)
800ABBE4	nop
800ABBE8	lw     v0, $08e4(v0)
800ABBEC	nop
800ABBF0	lw     v0, $000c(v0)
800ABBF4	nop
800ABBF8	lw     v0, $0014(v0)
800ABBFC	nop
800ABC00	lw     v0, $0020(v0)
800ABC04	nop
800ABC08	addu   s1, v0, zero
800ABC0C	sw     s1, $0010(s0)
800ABC10	sw     zero, $0000(s1)
800ABC14	lw     v1, $0004(s3)
800ABC18	addiu  v0, s1, $0014
800ABC1C	sw     v0, $0008(s1)
800ABC20	addiu  v0, s1, $00ac
800ABC24	sw     v0, $000c(s1)
800ABC28	addiu  v0, zero, $1000
800ABC2C	sw     zero, $0010(s1)
800ABC30	sw     s3, $00f8(s1)
800ABC34	sh     zero, $00fc(s1)
800ABC38	sh     zero, $00fe(s1)
800ABC3C	sh     zero, $0100(s1)
800ABC40	sh     zero, $0104(s1)
800ABC44	sh     v0, $0106(s1)
800ABC48	sh     zero, $0108(s1)
800ABC4C	sw     zero, $010c(s1)
800ABC50	sw     v1, $0004(s1)
800ABC54	lw     v0, $001c(a0)
800ABC58	nop
800ABC5C	lw     v0, $08e4(v0)
800ABC60	nop
800ABC64	lw     v0, $000c(v0)
800ABC68	nop
800ABC6C	lw     v1, $0014(v0)
800ABC70	nop
800ABC74	lw     v0, $0020(v1)
800ABC78	nop
800ABC7C	addiu  v0, v0, $0110
800ABC80	sw     v0, $0020(v1)

Labc84:	; 800ABC84
800ABC84	lw     v0, $0000(s1)
800ABC88	nop
800ABC8C	andi   v0, v0, $0001
800ABC90	bne    v0, zero, Labe64 [$800abe64]
800ABC94	addu   s4, s1, zero
800ABC98	lw     v0, $000c(s3)
800ABC9C	lw     v1, $000c(s1)
800ABCA0	addiu  a0, v0, $0040

loopabca4:	; 800ABCA4
800ABCA4	lw     t0, $0000(v0)
800ABCA8	lw     t1, $0004(v0)
800ABCAC	lw     t2, $0008(v0)
800ABCB0	lw     t3, $000c(v0)
800ABCB4	sw     t0, $0000(v1)
800ABCB8	sw     t1, $0004(v1)
800ABCBC	sw     t2, $0008(v1)
800ABCC0	sw     t3, $000c(v1)
800ABCC4	addiu  v0, v0, $0010
800ABCC8	bne    v0, a0, loopabca4 [$800abca4]
800ABCCC	addiu  v1, v1, $0010
800ABCD0	lw     t0, $0000(v0)
800ABCD4	lw     t1, $0004(v0)
800ABCD8	lw     t2, $0008(v0)
800ABCDC	sw     t0, $0000(v1)
800ABCE0	sw     t1, $0004(v1)
800ABCE4	sw     t2, $0008(v1)
800ABCE8	lw     v0, $0008(s3)
800ABCEC	lw     v1, $0008(s4)
800ABCF0	lw     v0, $0008(v0)
800ABCF4	addiu  a1, sp, $0010
800ABCF8	sw     v0, $0008(v1)
800ABCFC	lw     v0, $0008(s3)
800ABD00	lw     v1, $0008(s4)
800ABD04	lw     v0, $000c(v0)
800ABD08	addiu  a2, sp, $0014
800ABD0C	sw     v0, $000c(v1)
800ABD10	lw     a0, $0004(s4)
800ABD14	jal    funcaafd4 [$800aafd4]
800ABD18	addiu  a3, sp, $0018
800ABD1C	lw     v0, $0008(s4)
800ABD20	nop
800ABD24	lw     v0, $0008(v0)
800ABD28	nop
800ABD2C	lw     v1, $0010(v0)
800ABD30	nop
800ABD34	bltz   v1, Labd40 [$800abd40]
800ABD38	addu   s2, zero, zero
800ABD3C	addu   v1, v1, v0

Labd40:	; 800ABD40
800ABD40	lbu    a1, $0003(v0)
800ABD44	nop
800ABD48	sltu   v0, s2, a1
800ABD4C	beq    v0, zero, Labd6c [$800abd6c]
800ABD50	addu   a0, zero, zero

loopabd54:	; 800ABD54
800ABD54	lhu    v0, $0000(v1)
800ABD58	addiu  a0, a0, $0001
800ABD5C	addu   s2, s2, v0
800ABD60	sltu   v0, a0, a1
800ABD64	bne    v0, zero, loopabd54 [$800abd54]
800ABD68	addiu  v1, v1, $0028

Labd6c:	; 800ABD6C
800ABD6C	lui    s0, $8006
800ABD70	sll    s2, s2, $01
800ABD74	lw     v0, $794c(s0)
800ABD78	lw     a0, $0008(s4)
800ABD7C	lw     v0, $001c(v0)
800ABD80	lw     a2, $0008(a0)
800ABD84	lw     v0, $08e4(v0)
800ABD88	lbu    v1, $0002(a2)
800ABD8C	lw     v0, $000c(v0)
800ABD90	lbu    a2, $0003(a2)
800ABD94	lw     v0, $0014(v0)
800ABD98	sll    v1, v1, $05
800ABD9C	lw     a1, $0020(v0)
800ABDA0	sll    v0, a2, $01
800ABDA4	addu   v0, v0, a2
800ABDA8	sll    v0, v0, $02
800ABDAC	addu   v1, v1, v0
800ABDB0	jal    funcb6438 [$800b6438]
800ABDB4	addu   s2, s2, v1
A0 = w[S4 + 8];
A1 = w[SP + 10];
A2 = w[SP + 14];
funcb6584; // we prepare render packets here

800ABDCC	lw     v0, $794c(s0)
800ABDD0	nop

Labdd4:	; 800ABDD4
800ABDD4	lw     v0, $001c(v0)
800ABDD8	nop
800ABDDC	lw     v0, $08e4(v0)
800ABDE0	nop
800ABDE4	lw     v0, $000c(v0)
800ABDE8	nop
800ABDEC	lw     v1, $0014(v0)
800ABDF0	nop
800ABDF4	lw     v0, $0020(v1)
800ABDF8	addiu  a0, zero, $0009
800ABDFC	addu   v0, v0, s2
800ABE00	sw     v0, $0020(v1)
800ABE04	lw     a1, $0004(s4)
800ABE08	jal    func1c7fc [$8001c7fc]
800ABE0C	lui    a2, $0019
800ABE10	addu   a1, v0, zero
800ABE14	addiu  v0, zero, $ffff (=-$1)
800ABE18	beq    a1, v0, Labe48 [$800abe48]
800ABE1C	addiu  a0, zero, $0004
800ABE20	jal    func1c7fc [$8001c7fc]
800ABE24	addu   a2, zero, zero
800ABE28	lw     v1, $0008(s4)
800ABE2C	nop
800ABE30	sw     v0, $0050(v1)
800ABE34	lw     v0, $0008(s4)
800ABE38	lw     a1, $0018(sp)
800ABE3C	lw     a0, $0050(v0)
800ABE40	jal    funcbb3c4 [$800bb3c4]
800ABE44	nop

Labe48:	; 800ABE48
800ABE48	jal    funcac620 [$800ac620]
800ABE4C	nop
800ABE50	lui    v1, $0200
800ABE54	lw     v0, $0000(s1)
800ABE58	ori    v1, v1, $0001
800ABE5C	or     v0, v0, v1
800ABE60	sw     v0, $0000(s1)

Labe64:	; 800ABE64
800ABE64	addiu  v0, zero, $0009
800ABE68	beq    s5, v0, Labf24 [$800abf24]
800ABE6C	slti   v0, s5, $000a
800ABE70	beq    v0, zero, Labe88 [$800abe88]
800ABE74	addiu  v0, zero, $0008
800ABE78	beq    s5, v0, Labea4 [$800abea4]
800ABE7C	nop
800ABE80	j      Labff8 [$800abff8]
800ABE84	nop

Labe88:	; 800ABE88
800ABE88	addiu  v0, zero, $000a
800ABE8C	beq    s5, v0, Labf34 [$800abf34]
800ABE90	addiu  v0, zero, $000b
800ABE94	beq    s5, v0, Labf44 [$800abf44]
800ABE98	addiu  v0, zero, $0002
800ABE9C	j      Labff8 [$800abff8]
800ABEA0	nop

Labea4:	; 800ABEA4
800ABEA4	beq    s6, zero, Labf10 [$800abf10]
800ABEA8	lui    v1, $feff
800ABEAC	lw     v1, $0008(s4)
800ABEB0	lw     v0, $0008(s3)
800ABEB4	nop
800ABEB8	sw     v0, $0060(v1)
800ABEBC	lw     v1, $0008(s4)
800ABEC0	lw     v0, $0104(s1)
800ABEC4	nop
800ABEC8	sw     v0, $0064(v1)
800ABECC	lw     v1, $0008(s4)
800ABED0	lw     v0, $0108(s1)
800ABED4	nop
800ABED8	sw     v0, $0068(v1)
800ABEDC	lw     v1, $0008(s4)
800ABEE0	lw     v0, $00fc(s1)
800ABEE4	nop
800ABEE8	sw     v0, $006c(v1)
800ABEEC	lw     v1, $0008(s4)
800ABEF0	lw     v0, $0100(s1)
800ABEF4	nop
800ABEF8	sw     v0, $0070(v1)
800ABEFC	lw     v0, $0000(s1)
800ABF00	lui    v1, $0100
800ABF04	or     v0, v0, v1
800ABF08	j      Labff8 [$800abff8]
800ABF0C	sw     v0, $0000(s1)

Labf10:	; 800ABF10
800ABF10	lw     v0, $0000(s1)
800ABF14	ori    v1, v1, $ffff
800ABF18	and    v0, v0, v1
800ABF1C	j      Labff8 [$800abff8]
800ABF20	sw     v0, $0000(s1)

Labf24:	; 800ABF24
800ABF24	sh     s6, $00fc(s1)
800ABF28	sh     s7, $00fe(s1)
800ABF2C	j      Labff8 [$800abff8]
800ABF30	sh     fp, $0100(s1)

Labf34:	; 800ABF34
800ABF34	sh     s6, $0104(s1)
800ABF38	sh     s7, $0106(s1)
800ABF3C	j      Labff8 [$800abff8]
800ABF40	sh     fp, $0108(s1)

Labf44:	; 800ABF44
800ABF44	sb     s6, $010c(s1)
800ABF48	sb     s7, $010d(s1)
800ABF4C	sb     fp, $010e(s1)
800ABF50	j      Labff8 [$800abff8]
800ABF54	sb     v0, $010f(s1)
800ABF58	addu   a0, s3, zero
800ABF5C	addu   a1, s6, zero
800ABF60	jal    funcb2100 [$800b2100]
800ABF64	addu   a2, s7, zero
800ABF68	addu   v1, v0, zero
800ABF6C	bne    v1, zero, Labf94 [$800abf94]
800ABF70	addiu  v0, zero, $0011
800ABF74	addiu  v0, zero, $0013
800ABF78	beq    s5, v0, Labf90 [$800abf90]
800ABF7C	addu   a0, s3, zero
800ABF80	addu   a1, s6, zero
800ABF84	jal    funcb21a0 [$800b21a0]
800ABF88	addu   a2, s7, zero
800ABF8C	addu   v1, v0, zero

Labf90:	; 800ABF90
800ABF90	addiu  v0, zero, $0011

Labf94:	; 800ABF94
800ABF94	beq    s5, v0, Labfd8 [$800abfd8]
800ABF98	slti   v0, s5, $0012
800ABF9C	beq    v0, zero, Labfb4 [$800abfb4]
800ABFA0	addiu  v0, zero, $0010
800ABFA4	beq    s5, v0, Labfd0 [$800abfd0]
800ABFA8	nop
800ABFAC	j      Labff8 [$800abff8]
800ABFB0	nop

Labfb4:	; 800ABFB4
800ABFB4	addiu  v0, zero, $0012
800ABFB8	beq    s5, v0, Labfe0 [$800abfe0]
800ABFBC	addiu  v0, zero, $0013
800ABFC0	beq    s5, v0, Labfec [$800abfec]
800ABFC4	addu   a0, s3, zero
800ABFC8	j      Labff8 [$800abff8]
800ABFCC	nop

Labfd0:	; 800ABFD0
800ABFD0	j      Labff8 [$800abff8]
800ABFD4	sh     fp, $0008(v1)

Labfd8:	; 800ABFD8
800ABFD8	j      Labff8 [$800abff8]
800ABFDC	sh     fp, $000a(v1)

Labfe0:	; 800ABFE0
800ABFE0	sltu   v0, zero, fp
800ABFE4	j      Labff8 [$800abff8]
800ABFE8	sb     v0, $0001(v1)

Labfec:	; 800ABFEC
800ABFEC	addu   a1, s6, zero
800ABFF0	jal    funcb2218 [$800b2218]
800ABFF4	addu   a2, s7, zero

Labff8:	; 800ABFF8
800ABFF8	lw     ra, $0044(sp)
800ABFFC	lw     fp, $0040(sp)
800AC000	lw     s7, $003c(sp)
800AC004	lw     s6, $0038(sp)
800AC008	lw     s5, $0034(sp)
800AC00C	lw     s4, $0030(sp)
800AC010	lw     s3, $002c(sp)
800AC014	lw     s2, $0028(sp)
800AC018	lw     s1, $0024(sp)
800AC01C	lw     s0, $0020(sp)
800AC020	addu   v0, zero, zero
800AC024	jr     ra 
800AC028	addiu  sp, sp, $0048


funcac02c:	; 800AC02C
800AC02C	addiu  sp, sp, $ffc0 (=-$40)
800AC030	sw     s5, $002c(sp)
800AC034	sw     a1, $0044(sp)
800AC038	addiu  s5, a1, $ffff (=-$1)
800AC03C	sw     ra, $003c(sp)
800AC040	sw     fp, $0038(sp)
800AC044	sw     s7, $0034(sp)
800AC048	sw     s6, $0030(sp)
800AC04C	sw     s4, $0028(sp)
800AC050	sw     s3, $0024(sp)
800AC054	sw     s2, $0020(sp)
800AC058	sw     s1, $001c(sp)
800AC05C	sw     s0, $0018(sp)
800AC060	bltz   s5, Lac1b8 [$800ac1b8]
800AC064	sw     a0, $0040(sp)
800AC068	lui    fp, $0001
800AC06C	lui    s7, $0002
800AC070	sll    v0, s5, $02
800AC074	addu   s6, v0, a0

loopac078:	; 800AC078
800AC078	lw     s0, $0000(s6)
800AC07C	nop
800AC080	beq    s0, zero, Lac1ac [$800ac1ac]
800AC084	lui    v0, $8006
800AC088	lw     v0, $794c(v0)
800AC08C	addu   a1, zero, zero
800AC090	lw     v0, $001c(v0)
800AC094	lw     v1, $000c(s0)
800AC098	lw     v0, $08e4(v0)
800AC09C	lbu    a0, $003b(v1)
800AC0A0	lw     v1, $000c(v0)
800AC0A4	sll    v0, a0, $02
800AC0A8	lw     v1, $0014(v1)
800AC0AC	addu   v0, v0, a0
800AC0B0	lw     v1, $0054(v1)
800AC0B4	sll    v0, v0, $02
800AC0B8	addu   s1, v1, v0
800AC0BC	lw     v1, $0000(s0)
800AC0C0	lw     v0, $0000(s1)
800AC0C4	and    s2, v1, fp
800AC0C8	and    v0, v0, fp
800AC0CC	xor    s4, v0, s2
800AC0D0	lui    v0, $0004
800AC0D4	and    s3, v1, v0
800AC0D8	bne    s4, zero, Lac0f0 [$800ac0f0]
800AC0DC	and    v1, v1, s7
800AC0E0	bne    s3, zero, Lac0f0 [$800ac0f0]
800AC0E4	nop
800AC0E8	beq    v1, zero, Lac0f4 [$800ac0f4]
800AC0EC	nop

Lac0f0:	; 800AC0F0
800AC0F0	addiu  a1, zero, $0001

Lac0f4:	; 800AC0F4
800AC0F4	beq    a1, zero, Lac1ac [$800ac1ac]
800AC0F8	nop
800AC0FC	lw     v0, $0000(s0)
800AC100	nop
800AC104	and    v0, v0, fp
800AC108	beq    v0, zero, Lac11c [$800ac11c]
800AC10C	addiu  a1, zero, $0001
800AC110	lw     a0, $0008(s0)
800AC114	j      Lac124 [$800ac124]
800AC118	nop

Lac11c:	; 800AC11C
800AC11C	lw     a0, $0008(s0)
800AC120	addu   a1, zero, zero

Lac124:	; 800AC124
800AC124	jal    funcba190 [$800ba190]
800AC128	nop
800AC12C	beq    s2, zero, Lac14c [$800ac14c]
800AC130	nop
800AC134	lbu    a1, $0005(s1)
800AC138	lw     a0, $0008(s0)
800AC13C	sll    a1, a1, $18
800AC140	sra    a1, a1, $13
800AC144	jal    funcba3cc [$800ba3cc]
800AC148	andi   a1, a1, $ffe0

Lac14c:	; 800AC14C
800AC14C	lw     v1, $0000(s0)
800AC150	nop
800AC154	and    v0, v1, s7
800AC158	beq    v0, zero, Lac16c [$800ac16c]
800AC15C	lui    v0, $fffd
800AC160	ori    v0, v0, $ffff
800AC164	and    v0, v1, v0
800AC168	sw     v0, $0000(s0)

Lac16c:	; 800AC16C
800AC16C	lui    v1, $fffb
800AC170	lw     v0, $0000(s0)
800AC174	ori    v1, v1, $ffff
800AC178	and    v0, v0, v1
800AC17C	bne    s4, zero, Lac18c [$800ac18c]
800AC180	sw     v0, $0000(s0)
800AC184	beq    s3, zero, Lac198 [$800ac198]
800AC188	lui    v1, $fffe

Lac18c:	; 800AC18C
800AC18C	or     v0, v0, s7
800AC190	sw     v0, $0000(s0)
800AC194	lui    v1, $fffe

Lac198:	; 800AC198
800AC198	lw     v0, $0000(s1)
800AC19C	ori    v1, v1, $ffff
800AC1A0	and    v0, v0, v1
800AC1A4	or     v0, v0, s2
800AC1A8	sw     v0, $0000(s1)

Lac1ac:	; 800AC1AC
800AC1AC	addiu  s5, s5, $ffff (=-$1)
800AC1B0	bgez   s5, loopac078 [$800ac078]
800AC1B4	addiu  s6, s6, $fffc (=-$4)

Lac1b8:	; 800AC1B8
800AC1B8	lw     t0, $0044(sp)
800AC1BC	nop
800AC1C0	addiu  s5, t0, $ffff (=-$1)
800AC1C4	bltz   s5, Lac314 [$800ac314]
800AC1C8	sll    v0, s5, $02
800AC1CC	lw     t0, $0040(sp)
800AC1D0	nop
800AC1D4	addu   s6, v0, t0

loopac1d8:	; 800AC1D8
800AC1D8	lw     s0, $0000(s6)
800AC1DC	nop
800AC1E0	beq    s0, zero, Lac308 [$800ac308]

Lac1e4:	; 800AC1E4
800AC1E4	lui    v0, $8006
800AC1E8	lw     v0, $794c(v0)
800AC1EC	nop
800AC1F0	lw     v0, $001c(v0)
800AC1F4	lw     v1, $000c(s0)
800AC1F8	lw     v0, $08e4(v0)
800AC1FC	lbu    a0, $003b(v1)
800AC200	lw     v1, $000c(v0)
800AC204	sll    v0, a0, $02
800AC208	lw     v1, $0014(v1)

Lac20c:	; 800AC20C
800AC20C	addu   v0, v0, a0
800AC210	lw     v1, $0054(v1)
800AC214	sll    v0, v0, $02
800AC218	addu   s1, v1, v0
800AC21C	lw     s2, $0010(s1)
800AC220	nop
800AC224	beq    s2, zero, Lac308 [$800ac308]
800AC228	lui    v1, $0100
800AC22C	lw     v0, $0000(s2)
800AC230	nop
800AC234	and    v0, v0, v1
800AC238	beq    v0, zero, Lac308 [$800ac308]
800AC23C	nop
800AC240	lw     a0, $0008(s2)

funcac244:	; 800AC244
800AC244	jal    funcbc33c [$800bc33c]
800AC248	addu   s1, zero, zero
800AC24C	lw     v0, $00f8(s2)
800AC250	nop
800AC254	lw     v0, $000c(v0)
800AC258	lw     a0, $0008(s2)
800AC25C	lbu    a1, $003a(v0)
funcb7f14; // we build animation bone matrixes here
800AC264	addu   s4, s2, zero
800AC268	lw     v0, $0008(s2)
800AC26C	nop

Lac270:	; 800AC270
800AC270	lw     v0, $0008(v0)
800AC274	nop
800AC278	lbu    s3, $0003(v0)
800AC27C	nop

funcac280:	; 800AC280
800AC280	beq    s3, zero, Lac2b4 [$800ac2b4]
800AC284	nop

loopac288:	; 800AC288
800AC288	andi   s0, s1, $00ff
800AC28C	addu   a1, s0, zero
800AC290	lw     a0, $0008(s4)
800AC294	jal    funcb61a4 [$800b61a4]
800AC298	addiu  s1, s1, $0001
800AC29C	lw     a0, $0008(s4)
800AC2A0	jal    funcbc600 [$800bc600]
800AC2A4	addu   a1, s0, zero
800AC2A8	slt    v0, s1, s3
800AC2AC	bne    v0, zero, loopac288 [$800ac288]
800AC2B0	nop

Lac2b4:	; 800AC2B4
800AC2B4	lbu    v0, $010f(s2)
800AC2B8	nop
800AC2BC	beq    v0, zero, Lac308 [$800ac308]
800AC2C0	nop
800AC2C4	addiu  s1, s3, $ffff (=-$1)
800AC2C8	bltz   s1, Lac2f8 [$800ac2f8]
800AC2CC	nop

loopac2d0:	; 800AC2D0
800AC2D0	lbu    a2, $010c(s2)
800AC2D4	lbu    a3, $010d(s2)
800AC2D8	lbu    v0, $010e(s2)
800AC2DC	andi   a1, s1, $00ff
800AC2E0	sw     v0, $0010(sp)
800AC2E4	lw     a0, $0008(s4)
800AC2E8	jal    funcb9e4c [$800b9e4c]
800AC2EC	addiu  s1, s1, $ffff (=-$1)
800AC2F0	bgez   s1, loopac2d0 [$800ac2d0]
800AC2F4	nop

Lac2f8:	; 800AC2F8
800AC2F8	lbu    v0, $010f(s2)
800AC2FC	nop
800AC300	addiu  v0, v0, $ffff (=-$1)
800AC304	sb     v0, $010f(s2)

Lac308:	; 800AC308
800AC308	addiu  s5, s5, $ffff (=-$1)
800AC30C	bgez   s5, loopac1d8 [$800ac1d8]
800AC310	addiu  s6, s6, $fffc (=-$4)

Lac314:	; 800AC314
800AC314	lw     ra, $003c(sp)
800AC318	lw     fp, $0038(sp)
800AC31C	lw     s7, $0034(sp)
800AC320	lw     s6, $0030(sp)
800AC324	lw     s5, $002c(sp)
800AC328	lw     s4, $0028(sp)
800AC32C	lw     s3, $0024(sp)
800AC330	lw     s2, $0020(sp)
800AC334	lw     s1, $001c(sp)
800AC338	lw     s0, $0018(sp)
800AC33C	jr     ra 
800AC340	addiu  sp, sp, $0040


funcac344:	; 800AC344
800AC344	andi   a0, a0, $ffff
800AC348	addiu  a1, zero, $0009
800AC34C	lui    v0, $800d
800AC350	addiu  v0, v0, $9ccc (=-$6334)
800AC354	addiu  v1, v0, $006c

loopac358:	; 800AC358
800AC358	lh     v0, $0002(v1)
800AC35C	nop
800AC360	bne    v0, a0, Lac370 [$800ac370]
800AC364	addiu  a1, a1, $ffff (=-$1)
800AC368	jr     ra 
800AC36C	addu   v0, v1, zero


Lac370:	; 800AC370
800AC370	bgez   a1, loopac358 [$800ac358]
800AC374	addiu  v1, v1, $fff4 (=-$c)
800AC378	jr     ra 

funcac37c:	; 800AC37C
800AC37C	addu   v0, zero, zero


funcac380:	; 800AC380
800AC380	lui    a3, $801e
800AC384	beq    a0, zero, Lac390 [$800ac390]
800AC388	ori    a3, a3, $df00
800AC38C	sw     zero, $0000(a0)

Lac390:	; 800AC390
800AC390	addiu  a2, zero, $0009
800AC394	lui    v0, $800d
800AC398	addiu  v0, v0, $9ccc (=-$6334)
800AC39C	addiu  a1, v0, $006c

loopac3a0:	; 800AC3A0
800AC3A0	lw     v1, $0004(a1)
800AC3A4	nop
800AC3A8	beq    v1, zero, Lac3c4 [$800ac3c4]
800AC3AC	sltu   v0, v1, a3
800AC3B0	beq    v0, zero, Lac3c4 [$800ac3c4]
800AC3B4	nop
800AC3B8	beq    a0, zero, Lac3c4 [$800ac3c4]
800AC3BC	addu   a3, v1, zero
800AC3C0	sw     a1, $0000(a0)

Lac3c4:	; 800AC3C4
800AC3C4	addiu  a2, a2, $ffff (=-$1)
800AC3C8	bgez   a2, loopac3a0 [$800ac3a0]
800AC3CC	addiu  a1, a1, $fff4 (=-$c)
800AC3D0	jr     ra 
800AC3D4	addu   v0, a3, zero


funcac3d8:	; 800AC3D8
800AC3D8	addiu  sp, sp, $ffe0 (=-$20)
800AC3DC	sw     s1, $0014(sp)
800AC3E0	addu   s1, a1, zero
800AC3E4	sw     ra, $0018(sp)
800AC3E8	jal    funcac344 [$800ac344]
800AC3EC	sw     s0, $0010(sp)
800AC3F0	addu   a0, zero, zero
800AC3F4	jal    funcac380 [$800ac380]
800AC3F8	addu   s0, v0, zero
800AC3FC	lui    v1, $8006
800AC400	lw     v1, $794c(v1)
800AC404	nop
800AC408	lw     v1, $001c(v1)
800AC40C	nop
800AC410	lw     v1, $08e4(v1)
800AC414	nop
800AC418	lw     v1, $000c(v1)
800AC41C	nop
800AC420	lw     v1, $0014(v1)
800AC424	nop
800AC428	lw     v1, $0020(v1)
800AC42C	nop
800AC430	bne    v1, zero, Lac440 [$800ac440]
800AC434	addu   a0, v0, zero
800AC438	lui    v0, $8006
800AC43C	lw     v1, $7948(v0)

Lac440:	; 800AC440
800AC440	subu   a0, a0, s1
800AC444	sltu   v0, v1, a0
800AC448	bne    v0, zero, Lac458 [$800ac458]
800AC44C	addiu  v0, zero, $0001
800AC450	j      Lac460 [$800ac460]
800AC454	addu   v0, zero, zero

Lac458:	; 800AC458
800AC458	sw     a0, $0004(s0)
800AC45C	sw     s1, $0008(s0)

Lac460:	; 800AC460
800AC460	lw     ra, $0018(sp)
800AC464	lw     s1, $0014(sp)
800AC468	lw     s0, $0010(sp)
800AC46C	jr     ra 
800AC470	addiu  sp, sp, $0020


funcac474:	; 800AC474
800AC474	addiu  sp, sp, $ffe0 (=-$20)
800AC478	lui    a0, $801e
800AC47C	ori    a0, a0, $df00
800AC480	addiu  a3, zero, $0009
800AC484	lui    v0, $8006
800AC488	lw     t2, $794c(v0)
800AC48C	lui    v0, $800d
800AC490	addiu  t3, v0, $9f20 (=-$60e0)
800AC494	lui    v0, $800d
800AC498	addiu  v0, v0, $9ccc (=-$6334)
800AC49C	addiu  a2, v0, $006c
800AC4A0	sw     ra, $001c(sp)
800AC4A4	sw     s2, $0018(sp)
800AC4A8	sw     s1, $0014(sp)
800AC4AC	sw     s0, $0010(sp)

loopac4b0:	; 800AC4B0
800AC4B0	lw     v0, $0004(a2)
800AC4B4	lh     t1, $0002(a2)
800AC4B8	beq    v0, zero, Lac530 [$800ac530]
800AC4BC	nop
800AC4C0	lw     v0, $001c(t2)
800AC4C4	nop
800AC4C8	lw     v0, $08e4(v0)
800AC4CC	nop
800AC4D0	lw     v0, $000c(v0)
800AC4D4	nop
800AC4D8	lw     v0, $0014(v0)
800AC4DC	nop
800AC4E0	lbu    v0, $0060(v0)
800AC4E4	nop
800AC4E8	addiu  a1, v0, $ffff (=-$1)
800AC4EC	bltz   a1, Lac520 [$800ac520]
800AC4F0	addu   t0, zero, zero
800AC4F4	sll    v0, a1, $02
800AC4F8	addu   v1, v0, t3

loopac4fc:	; 800AC4FC
800AC4FC	lhu    v0, $0000(v1)
800AC500	nop
800AC504	bne    v0, t1, Lac514 [$800ac514]
800AC508	nop
800AC50C	j      Lac520 [$800ac520]
800AC510	addiu  t0, zero, $0001

Lac514:	; 800AC514
800AC514	addiu  a1, a1, $ffff (=-$1)
800AC518	bgez   a1, loopac4fc [$800ac4fc]
800AC51C	addiu  v1, v1, $fffc (=-$4)

Lac520:	; 800AC520
800AC520	bne    t0, zero, Lac530 [$800ac530]
800AC524	nop
800AC528	sw     zero, $0004(a2)
800AC52C	sw     zero, $0008(a2)

Lac530:	; 800AC530
800AC530	addiu  a3, a3, $ffff (=-$1)
800AC534	bgez   a3, loopac4b0 [$800ac4b0]
800AC538	addiu  a2, a2, $fff4 (=-$c)
800AC53C	lui    v0, $800d
800AC540	addiu  s2, v0, $9ccc (=-$6334)

Lac544:	; 800AC544
800AC544	addu   t0, zero, zero
800AC548	addiu  a2, zero, $ffff (=-$1)
800AC54C	addiu  a3, zero, $0009
800AC550	addiu  a1, s2, $006c

loopac554:	; 800AC554
800AC554	lw     v1, $0008(a1)
800AC558	lw     v0, $0004(a1)
800AC55C	nop
800AC560	beq    v0, zero, Lac584 [$800ac584]
800AC564	addu   v1, v0, v1
800AC568	sltu   v0, a0, v1
800AC56C	bne    v0, zero, Lac584 [$800ac584]
800AC570	sltu   v0, t0, v1
800AC574	beq    v0, zero, Lac584 [$800ac584]
800AC578	nop
800AC57C	addu   t0, v1, zero
800AC580	addu   a2, a3, zero

Lac584:	; 800AC584
800AC584	addiu  a3, a3, $ffff (=-$1)
800AC588	bgez   a3, loopac554 [$800ac554]
800AC58C	addiu  a1, a1, $fff4 (=-$c)
800AC590	addiu  v0, zero, $ffff (=-$1)
800AC594	beq    a2, v0, Lac5d0 [$800ac5d0]
800AC598	sll    v0, a2, $01
800AC59C	addu   v0, v0, a2
800AC5A0	sll    v0, v0, $02
800AC5A4	addu   s1, v0, s2
800AC5A8	lw     a2, $0008(s1)
800AC5AC	lw     a1, $0004(s1)
800AC5B0	subu   s0, a0, a2
800AC5B4	beq    a1, s0, Lac5c8 [$800ac5c8]
800AC5B8	addu   a0, s0, zero
800AC5BC	jal    func1daa4 [$8001daa4]
800AC5C0	addu   a3, zero, zero
800AC5C4	sw     s0, $0004(s1)

Lac5c8:	; 800AC5C8
800AC5C8	j      Lac544 [$800ac544]
800AC5CC	addu   a0, s0, zero

Lac5d0:	; 800AC5D0
800AC5D0	jal    func130a4 [$800130a4]
800AC5D4	addu   a0, zero, zero
800AC5D8	lw     ra, $001c(sp)
800AC5DC	lw     s2, $0018(sp)
800AC5E0	lw     s1, $0014(sp)
800AC5E4	lw     s0, $0010(sp)
800AC5E8	jr     ra 
800AC5EC	addiu  sp, sp, $0020


funcac5f0:	; 800AC5F0
800AC5F0	addiu  v1, zero, $0009
800AC5F4	lui    v0, $800d
800AC5F8	addiu  v0, v0, $9ccc (=-$6334)
800AC5FC	addiu  v0, v0, $006c

loopac600:	; 800AC600
800AC600	sh     zero, $0000(v0)
800AC604	sw     zero, $0004(v0)
800AC608	sw     zero, $0008(v0)
800AC60C	addiu  v1, v1, $ffff (=-$1)
800AC610	bgez   v1, loopac600 [$800ac600]
800AC614	addiu  v0, v0, $fff4 (=-$c)
800AC618	jr     ra 
800AC61C	nop


funcac620:	; 800AC620
800AC620	lui    v0, $8006
800AC624	lw     v0, $794c(v0)
800AC628	addiu  sp, sp, $ffe8 (=-$18)
800AC62C	sw     ra, $0010(sp)
800AC630	lw     v0, $001c(v0)
800AC634	nop
800AC638	lw     v0, $08e4(v0)
800AC63C	nop
800AC640	lw     v0, $000c(v0)
800AC644	nop
800AC648	lw     v0, $0014(v0)
800AC64C	nop
800AC650	lw     a0, $0020(v0)
800AC654	nop
800AC658	bne    a0, zero, Lac664 [$800ac664]
800AC65C	lui    v0, $8006
800AC660	lw     a0, $7948(v0)

Lac664:	; 800AC664
800AC664	jal    funcac67c [$800ac67c]
800AC668	nop
800AC66C	lw     ra, $0010(sp)
800AC670	nop
800AC674	jr     ra 
800AC678	addiu  sp, sp, $0018


funcac67c:	; 800AC67C
800AC67C	addiu  a1, zero, $0009
800AC680	lui    v0, $800d
800AC684	addiu  v0, v0, $9ccc (=-$6334)
800AC688	addiu  v1, v0, $006c

loopac68c:	; 800AC68C
800AC68C	lw     v0, $0004(v1)
800AC690	nop
800AC694	beq    v0, zero, Lac6ac [$800ac6ac]
800AC698	sltu   v0, a0, v0
800AC69C	bne    v0, zero, Lac6ac [$800ac6ac]
800AC6A0	nop
800AC6A4	sw     zero, $0008(v1)
800AC6A8	sw     zero, $0004(v1)

Lac6ac:	; 800AC6AC
800AC6AC	addiu  a1, a1, $ffff (=-$1)
800AC6B0	bgez   a1, loopac68c [$800ac68c]
800AC6B4	addiu  v1, v1, $fff4 (=-$c)
800AC6B8	jr     ra 
800AC6BC	nop


funcac6c0:	; 800AC6C0
800AC6C0	addiu  sp, sp, $ff60 (=-$a0)
800AC6C4	sll    v0, a1, $02
800AC6C8	addu   v0, v0, a1
800AC6CC	sll    v0, v0, $03
800AC6D0	sw     fp, $0098(sp)
800AC6D4	addu   fp, a0, v0
800AC6D8	addu   a0, a1, zero
800AC6DC	sw     ra, $009c(sp)
800AC6E0	sw     s7, $0094(sp)
800AC6E4	sw     s6, $0090(sp)
800AC6E8	sw     s5, $008c(sp)
800AC6EC	sw     s4, $0088(sp)
800AC6F0	sw     s3, $0084(sp)
800AC6F4	sw     s2, $0080(sp)
800AC6F8	sw     s1, $007c(sp)
800AC6FC	jal    func1e350 [$8001e350]
800AC700	sw     s0, $0078(sp)
800AC704	addu   s1, v0, zero
800AC708	lw     v0, $0000(s1)
800AC70C	nop
800AC710	andi   v0, v0, $0010
800AC714	bne    v0, zero, Lad41c [$800ad41c]
800AC718	sw     zero, $0070(sp)
800AC71C	lui    v0, $8006
800AC720	lw     v0, $794c(v0)
800AC724	nop
800AC728	lw     v0, $001c(v0)
800AC72C	nop
800AC730	lw     v0, $08e4(v0)
800AC734	nop
800AC738	lw     v0, $000c(v0)
800AC73C	nop
800AC740	lw     v0, $0014(v0)
800AC744	nop
800AC748	lw     s0, $001c(v0)
800AC74C	nop
800AC750	beq    s0, zero, Lac784 [$800ac784]
800AC754	addu   a0, fp, zero
800AC758	lw     a1, $0004(s1)
800AC75C	jal    funcb3294 [$800b3294]
800AC760	addu   a0, s0, zero
800AC764	bne    v0, zero, Lac774 [$800ac774]
800AC768	addu   a0, s0, zero
800AC76C	jal    funcb3294 [$800b3294]
800AC770	addiu  a1, zero, $ffff (=-$1)

Lac774:	; 800AC774
800AC774	lb     v0, $0007(v0)
800AC778	nop
800AC77C	sw     v0, $0070(sp)
800AC780	addu   a0, fp, zero

Lac784:	; 800AC784
800AC784	addu   a1, s1, zero
800AC788	jal    funcad488 [$800ad488]
800AC78C	addiu  a2, sp, $0010
800AC790	lui    a3, $8006
800AC794	lw     v0, $794c(a3)
800AC798	nop
800AC79C	lw     v0, $001c(v0)
800AC7A0	nop
800AC7A4	lw     v0, $08e4(v0)
800AC7A8	nop
800AC7AC	lw     v0, $000c(v0)
800AC7B0	nop
800AC7B4	lw     v0, $0014(v0)
800AC7B8	nop
800AC7BC	lh     v1, $0050(v0)
800AC7C0	nop
800AC7C4	bgez   v1, Lac7d0 [$800ac7d0]
800AC7C8	addu   a1, v1, zero
800AC7CC	addiu  a1, v1, $003f

Lac7d0:	; 800AC7D0
800AC7D0	lh     a0, $0052(v0)
800AC7D4	sra    v0, a1, $06
800AC7D8	sll    v0, v0, $06
800AC7DC	subu   v0, v1, v0
800AC7E0	sll    v0, v0, $10
800AC7E4	sra    s3, v0, $0f
800AC7E8	bgez   a0, Lac7f4 [$800ac7f4]
800AC7EC	addu   a2, a0, zero
800AC7F0	addiu  a2, a0, $00ff

Lac7f4:	; 800AC7F4
800AC7F4	addu   s5, zero, zero
800AC7F8	addiu  s4, s3, $001f
800AC7FC	sra    v0, a2, $08
800AC800	sll    v0, v0, $08
800AC804	subu   v0, a0, v0
800AC808	sll    v0, v0, $10
800AC80C	sra    s1, v0, $10
800AC810	addiu  s2, s1, $001f
800AC814	addiu  s0, sp, $0030
800AC818	addu   s7, s5, zero

Lac81c:	; 800AC81C
800AC81C	lui    t1, $8006
800AC820	lw     v0, $794c(t1)
800AC824	nop
800AC828	lw     a0, $001c(v0)
800AC82C	nop
800AC830	lw     v0, $08e4(a0)
800AC834	nop
800AC838	lw     v0, $0000(v0)
800AC83C	nop
800AC840	andi   v0, v0, $0200
800AC844	beq    v0, zero, Lac880 [$800ac880]
800AC848	addu   s6, zero, zero
800AC84C	lui    v1, $e600
800AC850	lbu    v0, $0008(a0)
800AC854	ori    v1, v1, $0002
800AC858	sll    v0, v0, $04
800AC85C	addu   v0, s7, v0
800AC860	addu   v0, fp, v0
800AC864	lw     s6, $0008(v0)
800AC868	addiu  v0, zero, $0002
800AC86C	sb     v0, $0003(s6)
800AC870	addiu  v0, s6, $000c
800AC874	sw     v1, $0004(s6)
800AC878	j      Lac898 [$800ac898]
800AC87C	sw     zero, $0008(s6)

Lac880:	; 800AC880
800AC880	lbu    v0, $0008(a0)
800AC884	nop
800AC888	sll    v0, v0, $04
800AC88C	addu   v0, s7, v0
800AC890	addu   v0, fp, v0
800AC894	lw     v0, $0008(v0)

Lac898:	; 800AC898
800AC898	nop
800AC89C	sw     v0, $0000(s0)
800AC8A0	lw     v1, $0000(s0)
800AC8A4	addiu  v0, zero, $0009
800AC8A8	sb     v0, $0003(v1)
800AC8AC	lw     v1, $0000(s0)
800AC8B0	addiu  v0, zero, $002c
800AC8B4	sb     v0, $0007(v1)
800AC8B8	lw     v1, $0000(s0)
800AC8BC	nop
800AC8C0	lbu    v0, $0007(v1)
800AC8C4	nop
800AC8C8	ori    v0, v0, $0002
800AC8CC	sb     v0, $0007(v1)
800AC8D0	lw     v1, $0000(s0)
800AC8D4	lbu    v0, $0000(fp)
800AC8D8	nop
800AC8DC	sb     v0, $0004(v1)
800AC8E0	lw     v1, $0000(s0)
800AC8E4	lbu    v0, $0000(fp)
800AC8E8	nop
800AC8EC	sb     v0, $0005(v1)
800AC8F0	lw     v1, $0000(s0)
800AC8F4	lbu    v0, $0000(fp)
800AC8F8	lui    t1, $8006
800AC8FC	sb     v0, $0006(v1)
800AC900	lw     v0, $794c(t1)
800AC904	nop
800AC908	lw     v0, $001c(v0)
800AC90C	nop
800AC910	lw     v0, $08e4(v0)
800AC914	nop
800AC918	lw     v0, $000c(v0)
800AC91C	nop
800AC920	lw     v0, $0014(v0)
800AC924	nop
800AC928	lhu    a0, $0052(v0)
800AC92C	lhu    v0, $0050(v0)
800AC930	andi   v1, a0, $0100
800AC934	sll    v1, v1, $10
800AC938	sra    v1, v1, $14
800AC93C	andi   v0, v0, $03ff
800AC940	srl    v0, v0, $06
800AC944	ori    v0, v0, $00c0
800AC948	or     v1, v1, v0
800AC94C	andi   a0, a0, $0200
800AC950	sll    a0, a0, $02
800AC954	lw     v0, $0000(s0)
800AC958	or     v1, v1, a0
800AC95C	sh     v1, $0016(v0)
800AC960	lw     v1, $0000(s0)
800AC964	addiu  v0, zero, $3fd0
800AC968	sh     v0, $000e(v1)
800AC96C	addiu  v0, zero, $0001
800AC970	beq    s5, v0, Laca08 [$800aca08]
800AC974	slti   v0, s5, $0002
800AC978	beq    v0, zero, Lac990 [$800ac990]
800AC97C	addiu  v0, zero, $0002
800AC980	beq    s5, zero, Lac9a8 [$800ac9a8]
800AC984	nop
800AC988	j      Lacb28 [$800acb28]
800AC98C	nop

Lac990:	; 800AC990
800AC990	beq    s5, v0, Laca68 [$800aca68]
800AC994	addiu  v0, zero, $0003
800AC998	beq    s5, v0, Lacac8 [$800acac8]
800AC99C	lui    t1, $8006
800AC9A0	j      Lacb2c [$800acb2c]
800AC9A4	nop

Lac9a8:	; 800AC9A8
800AC9A8	lw     v0, $0030(sp)
800AC9AC	nop
800AC9B0	sb     s3, $000c(v0)
800AC9B4	lw     v0, $0030(sp)
800AC9B8	nop
800AC9BC	sb     s1, $000d(v0)
800AC9C0	lw     v0, $0030(sp)
800AC9C4	nop
800AC9C8	sb     s4, $0014(v0)
800AC9CC	lw     v0, $0030(sp)
800AC9D0	nop
800AC9D4	sb     s1, $0015(v0)
800AC9D8	lw     v0, $0030(sp)
800AC9DC	nop
800AC9E0	sb     s3, $001c(v0)
800AC9E4	lw     v0, $0030(sp)
800AC9E8	nop
800AC9EC	sb     s2, $001d(v0)
800AC9F0	lw     v0, $0030(sp)
800AC9F4	nop
800AC9F8	sb     s4, $0024(v0)
800AC9FC	lw     v0, $0030(sp)
800ACA00	j      Lacb28 [$800acb28]
800ACA04	sb     s2, $0025(v0)

Laca08:	; 800ACA08
800ACA08	lw     v0, $0034(sp)
800ACA0C	nop
800ACA10	sb     s4, $000c(v0)
800ACA14	lw     v0, $0034(sp)
800ACA18	nop
800ACA1C	sb     s1, $000d(v0)
800ACA20	lw     v0, $0034(sp)
800ACA24	nop
800ACA28	sb     s3, $0014(v0)
800ACA2C	lw     v0, $0034(sp)
800ACA30	nop
800ACA34	sb     s1, $0015(v0)
800ACA38	lw     v0, $0034(sp)
800ACA3C	nop
800ACA40	sb     s4, $001c(v0)
800ACA44	lw     v0, $0034(sp)
800ACA48	nop
800ACA4C	sb     s2, $001d(v0)
800ACA50	lw     v0, $0034(sp)
800ACA54	nop
800ACA58	sb     s3, $0024(v0)
800ACA5C	lw     v0, $0034(sp)
800ACA60	j      Lacb28 [$800acb28]
800ACA64	sb     s2, $0025(v0)

Laca68:	; 800ACA68
800ACA68	lw     v0, $0038(sp)
800ACA6C	nop
800ACA70	sb     s3, $000c(v0)
800ACA74	lw     v0, $0038(sp)
800ACA78	nop
800ACA7C	sb     s2, $000d(v0)
800ACA80	lw     v0, $0038(sp)
800ACA84	nop
800ACA88	sb     s4, $0014(v0)
800ACA8C	lw     v0, $0038(sp)
800ACA90	nop
800ACA94	sb     s2, $0015(v0)
800ACA98	lw     v0, $0038(sp)
800ACA9C	nop
800ACAA0	sb     s3, $001c(v0)
800ACAA4	lw     v0, $0038(sp)
800ACAA8	nop
800ACAAC	sb     s1, $001d(v0)
800ACAB0	lw     v0, $0038(sp)
800ACAB4	nop
800ACAB8	sb     s4, $0024(v0)
800ACABC	lw     v0, $0038(sp)
800ACAC0	j      Lacb28 [$800acb28]
800ACAC4	sb     s1, $0025(v0)

Lacac8:	; 800ACAC8
800ACAC8	lw     v0, $003c(sp)
800ACACC	nop
800ACAD0	sb     s4, $000c(v0)
800ACAD4	lw     v0, $003c(sp)
800ACAD8	nop
800ACADC	sb     s2, $000d(v0)
800ACAE0	lw     v0, $003c(sp)
800ACAE4	nop
800ACAE8	sb     s3, $0014(v0)
800ACAEC	lw     v0, $003c(sp)
800ACAF0	nop
800ACAF4	sb     s2, $0015(v0)
800ACAF8	lw     v0, $003c(sp)
800ACAFC	nop
800ACB00	sb     s4, $001c(v0)
800ACB04	lw     v0, $003c(sp)
800ACB08	nop
800ACB0C	sb     s1, $001d(v0)
800ACB10	lw     v0, $003c(sp)
800ACB14	nop
800ACB18	sb     s3, $0024(v0)
800ACB1C	lw     v0, $003c(sp)
800ACB20	nop
800ACB24	sb     s1, $0025(v0)

Lacb28:	; 800ACB28
800ACB28	lui    t1, $8006

Lacb2c:	; 800ACB2C
800ACB2C	lw     v0, $794c(t1)
800ACB30	nop
800ACB34	lw     v0, $001c(v0)
800ACB38	nop
800ACB3C	lw     v0, $08e4(v0)
800ACB40	nop
800ACB44	lw     v0, $0000(v0)
800ACB48	nop
800ACB4C	andi   v0, v0, $0200
800ACB50	beq    v0, zero, Lacb8c [$800acb8c]
800ACB54	lui    v1, $e600
800ACB58	ori    v1, v1, $0002
800ACB5C	lw     a1, $0000(s0)
800ACB60	addiu  v0, zero, $0002
800ACB64	addiu  a1, a1, $0028
800ACB68	sb     v0, $0003(a1)
800ACB6C	sw     v1, $0004(a1)
800ACB70	sw     zero, $0008(a1)
800ACB74	lw     a0, $0000(s0)
800ACB78	jal    func62b4c [$80062b4c]
800ACB7C	nop
800ACB80	lw     a1, $0000(s0)
800ACB84	jal    func62b4c [$80062b4c]
800ACB88	addu   a0, s6, zero

Lacb8c:	; 800ACB8C
800ACB8C	addiu  s0, s0, $0004
800ACB90	addiu  s5, s5, $0001
800ACB94	slti   v0, s5, $0004
800ACB98	bne    v0, zero, Lac81c [$800ac81c]
800ACB9C	addiu  s7, s7, $0004
800ACBA0	lui    a2, $8006
800ACBA4	lw     v0, $794c(a2)
800ACBA8	nop
800ACBAC	lw     v0, $001c(v0)
800ACBB0	nop
800ACBB4	addiu  v0, v0, $0018
800ACBB8	lw     t4, $0000(v0)
800ACBBC	lw     t5, $0004(v0)
800ACBC0	ctc2   t4,vxy0
800ACBC4	ctc2   t5,vz0
800ACBC8	lw     t4, $0008(v0)
800ACBCC	lw     t5, $000c(v0)
800ACBD0	lw     t6, $0010(v0)
800ACBD4	ctc2   t4,vxy1
800ACBD8	ctc2   t5,vz1
800ACBDC	ctc2   t6,vxy2
800ACBE0	addiu  v1, sp, $0010
800ACBE4	lhu    t4, $0000(v1)
800ACBE8	lhu    t5, $0006(v1)
800ACBEC	lhu    t6, $000c(v1)
800ACBF0	mtc2   t4,l13l21
800ACBF4	mtc2   t5,l22l23
800ACBF8	mtc2   t6,l31l32
800ACBFC	nop
800ACC00	nop
800ACC04	gte_func18t1,dqb
800ACC08	mfc2   t4,l13l21
800ACC0C	mfc2   t5,l22l23
800ACC10	mfc2   t6,l31l32
800ACC14	sh     t4, $0000(v1)
800ACC18	sh     t5, $0006(v1)
800ACC1C	sh     t6, $000c(v1)
800ACC20	addiu  v0, sp, $0012
800ACC24	lhu    t4, $0000(v0)
800ACC28	lhu    t5, $0006(v0)
800ACC2C	lhu    t6, $000c(v0)
800ACC30	mtc2   t4,l13l21
800ACC34	mtc2   t5,l22l23
800ACC38	mtc2   t6,l31l32
800ACC3C	nop
800ACC40	nop
800ACC44	gte_func18t1,dqb
800ACC48	mfc2   t4,l13l21
800ACC4C	mfc2   t5,l22l23
800ACC50	mfc2   t6,l31l32
800ACC54	sh     t4, $0000(v0)
800ACC58	sh     t5, $0006(v0)
800ACC5C	sh     t6, $000c(v0)
800ACC60	addiu  v0, sp, $0014
800ACC64	lhu    t4, $0000(v0)
800ACC68	lhu    t5, $0006(v0)
800ACC6C	lhu    t6, $000c(v0)
800ACC70	mtc2   t4,l13l21
800ACC74	mtc2   t5,l22l23
800ACC78	mtc2   t6,l31l32
800ACC7C	nop
800ACC80	nop
800ACC84	gte_func18t1,dqb
800ACC88	mfc2   t4,l13l21
800ACC8C	mfc2   t5,l22l23
800ACC90	mfc2   t6,l31l32
800ACC94	sh     t4, $0000(v0)
800ACC98	sh     t5, $0006(v0)
800ACC9C	sh     t6, $000c(v0)
800ACCA0	lw     v0, $794c(a2)
800ACCA4	nop
800ACCA8	lw     v0, $001c(v0)
800ACCAC	nop
800ACCB0	addiu  v0, v0, $0018
800ACCB4	lw     t4, $0014(v0)
800ACCB8	lw     t5, $0018(v0)
800ACCBC	ctc2   t4,vz2
800ACCC0	lw     t6, $001c(v0)
800ACCC4	ctc2   t5,rgb
800ACCC8	ctc2   t6,otz
800ACCCC	addiu  v0, sp, $0024
800ACCD0	lhu    t5, $0004(v0)
800ACCD4	lhu    t4, $0000(v0)
800ACCD8	sll    t5, t5, $10
800ACCDC	or     t4, t4, t5
800ACCE0	mtc2   t4,r11r12
800ACCE4	lwc2   at, $0008(v0)
800ACCE8	nop
800ACCEC	nop
800ACCF0	gte_func18t0,r11r12
800ACCF4	swc2   t1, $0000(v0)
800ACCF8	swc2   t2, $0004(v0)
800ACCFC	swc2   t3, $0008(v0)
800ACD00	lw     t4, $0000(v1)
800ACD04	lw     t5, $0004(v1)
800ACD08	ctc2   t4,vxy0
800ACD0C	ctc2   t5,vz0
800ACD10	lw     t4, $0008(v1)
800ACD14	lw     t5, $000c(v1)
800ACD18	lw     t6, $0010(v1)
800ACD1C	ctc2   t4,vxy1
800ACD20	ctc2   t5,vz1
800ACD24	ctc2   t6,vxy2
800ACD28	lw     t4, $0014(v1)
800ACD2C	lw     t5, $0018(v1)
800ACD30	ctc2   t4,vz2
800ACD34	lw     t6, $001c(v1)
800ACD38	ctc2   t5,rgb
800ACD3C	ctc2   t6,otz
800ACD40	addiu  a1, zero, $f000 (=-$1000)
800ACD44	addiu  a0, zero, $1000
800ACD48	addiu  v1, sp, $0040
800ACD4C	sh     a1, $0040(sp)
800ACD50	sh     zero, $0042(sp)
800ACD54	sh     a0, $0044(sp)
800ACD58	lwc2   zero, $0000(v1)
800ACD5C	lwc2   at, $0004(v1)
800ACD60	nop
800ACD64	nop
800ACD68	gte_func16t8,r11r12
800ACD6C	lw     v0, $0030(sp)
800ACD70	nop
800ACD74	addiu  v0, v0, $0008
800ACD78	swc2   t6, $0000(v0)
800ACD7C	addiu  v0, sp, $0048
800ACD80	swc2   s3, $0000(v0)
800ACD84	sh     zero, $0040(sp)
800ACD88	sh     zero, $0042(sp)
800ACD8C	sh     a0, $0044(sp)
800ACD90	lwc2   zero, $0000(v1)
800ACD94	lwc2   at, $0004(v1)
800ACD98	nop
800ACD9C	nop
800ACDA0	gte_func16t8,r11r12
800ACDA4	lw     v0, $0030(sp)
800ACDA8	nop
800ACDAC	addiu  v0, v0, $0010
800ACDB0	swc2   t6, $0000(v0)
800ACDB4	lw     v0, $0034(sp)
800ACDB8	nop
800ACDBC	addiu  v0, v0, $0008
800ACDC0	swc2   t6, $0000(v0)
800ACDC4	addiu  v0, sp, $004c
800ACDC8	swc2   s3, $0000(v0)
800ACDCC	sh     a0, $0040(sp)
800ACDD0	sh     zero, $0042(sp)
800ACDD4	sh     a0, $0044(sp)
800ACDD8	lwc2   zero, $0000(v1)
800ACDDC	lwc2   at, $0004(v1)
800ACDE0	nop
800ACDE4	nop
800ACDE8	gte_func16t8,r11r12
800ACDEC	lw     v0, $0034(sp)
800ACDF0	nop
800ACDF4	addiu  v0, v0, $0010
800ACDF8	swc2   t6, $0000(v0)
800ACDFC	addiu  v0, sp, $0050
800ACE00	swc2   s3, $0000(v0)
800ACE04	sh     a1, $0040(sp)
800ACE08	sh     zero, $0042(sp)
800ACE0C	sh     zero, $0044(sp)
800ACE10	lwc2   zero, $0000(v1)
800ACE14	lwc2   at, $0004(v1)
800ACE18	nop
800ACE1C	nop
800ACE20	gte_func16t8,r11r12
800ACE24	lw     v0, $0030(sp)
800ACE28	nop
800ACE2C	addiu  v0, v0, $0018
800ACE30	swc2   t6, $0000(v0)
800ACE34	lw     v0, $0038(sp)
800ACE38	nop
800ACE3C	addiu  v0, v0, $0008
800ACE40	swc2   t6, $0000(v0)
800ACE44	addiu  v0, sp, $0054
800ACE48	swc2   s3, $0000(v0)
800ACE4C	sh     zero, $0040(sp)
800ACE50	sh     zero, $0042(sp)
800ACE54	sh     zero, $0044(sp)
800ACE58	lwc2   zero, $0000(v1)
800ACE5C	lwc2   at, $0004(v1)
800ACE60	nop
800ACE64	nop
800ACE68	gte_func16t8,r11r12
800ACE6C	lw     v0, $0030(sp)
800ACE70	nop
800ACE74	addiu  v0, v0, $0020
800ACE78	swc2   t6, $0000(v0)
800ACE7C	lw     v0, $0034(sp)
800ACE80	nop
800ACE84	addiu  v0, v0, $0018
800ACE88	swc2   t6, $0000(v0)
800ACE8C	lw     v0, $0038(sp)
800ACE90	nop
800ACE94	addiu  v0, v0, $0010
800ACE98	swc2   t6, $0000(v0)
800ACE9C	lw     v0, $003c(sp)
800ACEA0	nop
800ACEA4	addiu  v0, v0, $0008
800ACEA8	swc2   t6, $0000(v0)
800ACEAC	addiu  v0, sp, $0058
800ACEB0	swc2   s3, $0000(v0)
800ACEB4	sh     a0, $0040(sp)
800ACEB8	sh     zero, $0042(sp)
800ACEBC	sh     zero, $0044(sp)
800ACEC0	lwc2   zero, $0000(v1)
800ACEC4	lwc2   at, $0004(v1)
800ACEC8	nop
800ACECC	nop
800ACED0	gte_func16t8,r11r12
800ACED4	lw     v0, $0034(sp)
800ACED8	nop
800ACEDC	addiu  v0, v0, $0020
800ACEE0	swc2   t6, $0000(v0)
800ACEE4	lw     v0, $003c(sp)
800ACEE8	nop
800ACEEC	addiu  v0, v0, $0010
800ACEF0	swc2   t6, $0000(v0)
800ACEF4	addiu  v0, sp, $005c
800ACEF8	swc2   s3, $0000(v0)
800ACEFC	sh     a1, $0040(sp)
800ACF00	sh     zero, $0042(sp)
800ACF04	sh     a1, $0044(sp)
800ACF08	lwc2   zero, $0000(v1)
800ACF0C	lwc2   at, $0004(v1)
800ACF10	nop
800ACF14	nop
800ACF18	gte_func16t8,r11r12
800ACF1C	lw     v0, $0038(sp)
800ACF20	nop
800ACF24	addiu  v0, v0, $0018
800ACF28	swc2   t6, $0000(v0)
800ACF2C	addiu  v0, sp, $0060
800ACF30	swc2   s3, $0000(v0)
800ACF34	sh     zero, $0040(sp)
800ACF38	sh     zero, $0042(sp)
800ACF3C	sh     a1, $0044(sp)
800ACF40	lwc2   zero, $0000(v1)
800ACF44	lwc2   at, $0004(v1)
800ACF48	nop
800ACF4C	nop
800ACF50	gte_func16t8,r11r12
800ACF54	lw     v0, $0038(sp)
800ACF58	nop
800ACF5C	addiu  v0, v0, $0020
800ACF60	swc2   t6, $0000(v0)
800ACF64	lw     v0, $003c(sp)
800ACF68	nop
800ACF6C	addiu  v0, v0, $0018
800ACF70	swc2   t6, $0000(v0)
800ACF74	addiu  v0, sp, $0064
800ACF78	swc2   s3, $0000(v0)
800ACF7C	sh     a0, $0040(sp)
800ACF80	sh     zero, $0042(sp)
800ACF84	sh     a1, $0044(sp)
800ACF88	lwc2   zero, $0000(v1)
800ACF8C	lwc2   at, $0004(v1)
800ACF90	nop
800ACF94	nop
800ACF98	gte_func16t8,r11r12
800ACF9C	lw     v0, $003c(sp)
800ACFA0	nop
800ACFA4	addiu  v0, v0, $0020
800ACFA8	swc2   t6, $0000(v0)
800ACFAC	addiu  v0, sp, $0068
800ACFB0	swc2   s3, $0000(v0)
800ACFB4	lw     a1, $0048(sp)
800ACFB8	lw     v1, $004c(sp)
800ACFBC	nop
800ACFC0	slt    v0, a1, v1
800ACFC4	beq    v0, zero, Lacfd0 [$800acfd0]
800ACFC8	nop
800ACFCC	addu   a1, v1, zero

Lacfd0:	; 800ACFD0
800ACFD0	lw     v1, $0054(sp)
800ACFD4	nop
800ACFD8	slt    v0, a1, v1
800ACFDC	beq    v0, zero, Lacfe8 [$800acfe8]
800ACFE0	nop
800ACFE4	addu   a1, v1, zero

Lacfe8:	; 800ACFE8
800ACFE8	lw     v1, $0058(sp)
800ACFEC	nop
800ACFF0	slt    v0, a1, v1
800ACFF4	beq    v0, zero, Lad000 [$800ad000]
800ACFF8	nop
800ACFFC	addu   a1, v1, zero

Lad000:	; 800AD000
800AD000	lw     t0, $794c(a2)
800AD004	nop
800AD008	lw     a3, $001c(t0)
800AD00C	nop
800AD010	lw     v0, $08e4(a3)
800AD014	nop
800AD018	lw     v0, $000c(v0)
800AD01C	sra    v1, a1, $02
800AD020	lw     v0, $0014(v0)
800AD024	lw     t1, $0070(sp)
800AD028	lh     a0, $0030(v0)
800AD02C	addu   a1, v1, t1
800AD030	subu   v0, zero, a0
800AD034	slt    v0, v0, a1
800AD038	beq    v0, zero, Lad0d4 [$800ad0d4]
800AD03C	addiu  v0, zero, $1000
800AD040	subu   v0, v0, a0
800AD044	slt    v0, a1, v0
800AD048	beq    v0, zero, Lad0d4 [$800ad0d4]
800AD04C	lui    a2, $00ff
800AD050	ori    a2, a2, $ffff
800AD054	lbu    v0, $0008(a3)
800AD058	sll    a1, a1, $02
800AD05C	sll    v1, v0, $04
800AD060	addu   v1, fp, v1
800AD064	sll    v0, v0, $02
800AD068	addu   v0, a3, v0
800AD06C	lui    a3, $ff00
800AD070	lw     v0, $0010(v0)
800AD074	lw     a0, $0008(v1)
800AD078	addu   v0, a1, v0
800AD07C	lw     v1, $0000(a0)
800AD080	lw     v0, $0000(v0)
800AD084	and    v1, v1, a3
800AD088	and    v0, v0, a2
800AD08C	or     v1, v1, v0
800AD090	sw     v1, $0000(a0)
800AD094	lw     v0, $001c(t0)
800AD098	nop
800AD09C	lbu    a0, $0008(v0)
800AD0A0	nop
800AD0A4	sll    v1, a0, $02
800AD0A8	addu   v0, v0, v1
800AD0AC	sll    a0, a0, $04
800AD0B0	lw     v0, $0010(v0)
800AD0B4	addu   a0, fp, a0
800AD0B8	addu   a1, a1, v0
800AD0BC	lw     v1, $0000(a1)
800AD0C0	lw     v0, $0008(a0)
800AD0C4	and    v1, v1, a3
800AD0C8	and    v0, v0, a2
800AD0CC	or     v1, v1, v0
800AD0D0	sw     v1, $0000(a1)

Lad0d4:	; 800AD0D4
800AD0D4	lw     a1, $004c(sp)
800AD0D8	lw     v1, $0050(sp)
800AD0DC	nop
800AD0E0	slt    v0, a1, v1
800AD0E4	beq    v0, zero, Lad0f0 [$800ad0f0]
800AD0E8	nop
800AD0EC	addu   a1, v1, zero

Lad0f0:	; 800AD0F0
800AD0F0	lw     v1, $0058(sp)
800AD0F4	nop
800AD0F8	slt    v0, a1, v1
800AD0FC	beq    v0, zero, Lad108 [$800ad108]
800AD100	nop
800AD104	addu   a1, v1, zero

Lad108:	; 800AD108
800AD108	lw     v1, $005c(sp)
800AD10C	nop
800AD110	slt    v0, a1, v1
800AD114	beq    v0, zero, Lad120 [$800ad120]
800AD118	lui    v0, $8006
800AD11C	addu   a1, v1, zero

Lad120:	; 800AD120
800AD120	lw     t0, $794c(v0)
800AD124	nop
800AD128	lw     a3, $001c(t0)
800AD12C	nop
800AD130	lw     v0, $08e4(a3)
800AD134	nop
800AD138	lw     v0, $000c(v0)
800AD13C	sra    v1, a1, $02
800AD140	lw     v0, $0014(v0)
800AD144	lw     t1, $0070(sp)
800AD148	lh     a0, $0030(v0)
800AD14C	addu   a1, v1, t1
800AD150	subu   v0, zero, a0
800AD154	slt    v0, v0, a1
800AD158	beq    v0, zero, Lad1f4 [$800ad1f4]
800AD15C	addiu  v0, zero, $1000
800AD160	subu   v0, v0, a0
800AD164	slt    v0, a1, v0
800AD168	beq    v0, zero, Lad1f4 [$800ad1f4]
800AD16C	lui    a2, $00ff
800AD170	ori    a2, a2, $ffff
800AD174	lbu    v0, $0008(a3)
800AD178	sll    a1, a1, $02
800AD17C	sll    v1, v0, $04
800AD180	addu   v1, fp, v1
800AD184	sll    v0, v0, $02
800AD188	addu   v0, a3, v0
800AD18C	lui    a3, $ff00
800AD190	lw     v0, $0010(v0)
800AD194	lw     a0, $000c(v1)
800AD198	addu   v0, a1, v0
800AD19C	lw     v1, $0000(a0)
800AD1A0	lw     v0, $0000(v0)
800AD1A4	and    v1, v1, a3
800AD1A8	and    v0, v0, a2
800AD1AC	or     v1, v1, v0
800AD1B0	sw     v1, $0000(a0)
800AD1B4	lw     v0, $001c(t0)
800AD1B8	nop
800AD1BC	lbu    a0, $0008(v0)
800AD1C0	nop
800AD1C4	sll    v1, a0, $02
800AD1C8	addu   v0, v0, v1
800AD1CC	sll    a0, a0, $04
800AD1D0	lw     v0, $0010(v0)
800AD1D4	addu   a0, fp, a0
800AD1D8	addu   a1, a1, v0
800AD1DC	lw     v1, $0000(a1)
800AD1E0	lw     v0, $000c(a0)
800AD1E4	and    v1, v1, a3
800AD1E8	and    v0, v0, a2
800AD1EC	or     v1, v1, v0
800AD1F0	sw     v1, $0000(a1)

Lad1f4:	; 800AD1F4
800AD1F4	lw     a1, $0054(sp)
800AD1F8	lw     v1, $0060(sp)
800AD1FC	nop
800AD200	slt    v0, a1, v1
800AD204	beq    v0, zero, Lad210 [$800ad210]
800AD208	nop
800AD20C	addu   a1, v1, zero

Lad210:	; 800AD210
800AD210	lw     v1, $0064(sp)
800AD214	nop
800AD218	slt    v0, a1, v1
800AD21C	beq    v0, zero, Lad228 [$800ad228]
800AD220	lui    v0, $8006
800AD224	addu   a1, v1, zero

Lad228:	; 800AD228
800AD228	lw     t0, $794c(v0)
800AD22C	nop
800AD230	lw     a3, $001c(t0)
800AD234	nop
800AD238	lw     v0, $08e4(a3)
800AD23C	nop
800AD240	lw     v0, $000c(v0)
800AD244	sra    v1, a1, $02
800AD248	lw     v0, $0014(v0)
800AD24C	lw     t1, $0070(sp)
800AD250	lh     a0, $0030(v0)
800AD254	addu   a1, v1, t1
800AD258	subu   v0, zero, a0
800AD25C	slt    v0, v0, a1
800AD260	beq    v0, zero, Lad2fc [$800ad2fc]
800AD264	addiu  v0, zero, $1000
800AD268	subu   v0, v0, a0
800AD26C	slt    v0, a1, v0
800AD270	beq    v0, zero, Lad2fc [$800ad2fc]
800AD274	lui    a2, $00ff
800AD278	ori    a2, a2, $ffff
800AD27C	lbu    v0, $0008(a3)
800AD280	sll    a1, a1, $02
800AD284	sll    v1, v0, $04
800AD288	addu   v1, fp, v1
800AD28C	sll    v0, v0, $02
800AD290	addu   v0, a3, v0
800AD294	lui    a3, $ff00
800AD298	lw     v0, $0010(v0)
800AD29C	lw     a0, $0010(v1)
800AD2A0	addu   v0, a1, v0
800AD2A4	lw     v1, $0000(a0)
800AD2A8	lw     v0, $0000(v0)
800AD2AC	and    v1, v1, a3
800AD2B0	and    v0, v0, a2
800AD2B4	or     v1, v1, v0
800AD2B8	sw     v1, $0000(a0)
800AD2BC	lw     v0, $001c(t0)
800AD2C0	nop
800AD2C4	lbu    a0, $0008(v0)
800AD2C8	nop
800AD2CC	sll    v1, a0, $02
800AD2D0	addu   v0, v0, v1
800AD2D4	sll    a0, a0, $04
800AD2D8	lw     v0, $0010(v0)
800AD2DC	addu   a0, fp, a0
800AD2E0	addu   a1, a1, v0
800AD2E4	lw     v1, $0000(a1)
800AD2E8	lw     v0, $0010(a0)
800AD2EC	and    v1, v1, a3
800AD2F0	and    v0, v0, a2
800AD2F4	or     v1, v1, v0
800AD2F8	sw     v1, $0000(a1)

Lad2fc:	; 800AD2FC
800AD2FC	lw     a1, $0058(sp)
800AD300	lw     v1, $005c(sp)
800AD304	nop
800AD308	slt    v0, a1, v1
800AD30C	beq    v0, zero, Lad318 [$800ad318]
800AD310	nop
800AD314	addu   a1, v1, zero

Lad318:	; 800AD318
800AD318	lw     v1, $0064(sp)
800AD31C	nop
800AD320	slt    v0, a1, v1
800AD324	beq    v0, zero, Lad330 [$800ad330]
800AD328	nop
800AD32C	addu   a1, v1, zero

Lad330:	; 800AD330
800AD330	lw     v1, $0068(sp)
800AD334	nop
800AD338	slt    v0, a1, v1
800AD33C	beq    v0, zero, Lad348 [$800ad348]
800AD340	lui    v0, $8006
800AD344	addu   a1, v1, zero

Lad348:	; 800AD348
800AD348	lw     t0, $794c(v0)
800AD34C	nop
800AD350	lw     a3, $001c(t0)
800AD354	nop
800AD358	lw     v0, $08e4(a3)
800AD35C	nop
800AD360	lw     v0, $000c(v0)
800AD364	sra    v1, a1, $02
800AD368	lw     v0, $0014(v0)
800AD36C	lw     t1, $0070(sp)
800AD370	lh     a0, $0030(v0)
800AD374	addu   a1, v1, t1
800AD378	subu   v0, zero, a0
800AD37C	slt    v0, v0, a1
800AD380	beq    v0, zero, Lad41c [$800ad41c]
800AD384	addiu  v0, zero, $1000
800AD388	subu   v0, v0, a0
800AD38C	slt    v0, a1, v0
800AD390	beq    v0, zero, Lad41c [$800ad41c]
800AD394	lui    a2, $00ff
800AD398	ori    a2, a2, $ffff
800AD39C	lbu    v0, $0008(a3)
800AD3A0	sll    a1, a1, $02
800AD3A4	sll    v1, v0, $04
800AD3A8	addu   v1, fp, v1
800AD3AC	sll    v0, v0, $02
800AD3B0	addu   v0, a3, v0
800AD3B4	lui    a3, $ff00
800AD3B8	lw     v0, $0010(v0)
800AD3BC	lw     a0, $0014(v1)
800AD3C0	addu   v0, a1, v0
800AD3C4	lw     v1, $0000(a0)
800AD3C8	lw     v0, $0000(v0)
800AD3CC	and    v1, v1, a3
800AD3D0	and    v0, v0, a2
800AD3D4	or     v1, v1, v0
800AD3D8	sw     v1, $0000(a0)
800AD3DC	lw     v0, $001c(t0)
800AD3E0	nop
800AD3E4	lbu    a0, $0008(v0)
800AD3E8	nop
800AD3EC	sll    v1, a0, $02
800AD3F0	addu   v0, v0, v1
800AD3F4	sll    a0, a0, $04
800AD3F8	lw     v0, $0010(v0)
800AD3FC	addu   a0, fp, a0
800AD400	addu   a1, a1, v0
800AD404	lw     v1, $0000(a1)
800AD408	lw     v0, $0014(a0)
800AD40C	and    v1, v1, a3
800AD410	and    v0, v0, a2
800AD414	or     v1, v1, v0
800AD418	sw     v1, $0000(a1)

Lad41c:	; 800AD41C
800AD41C	lw     ra, $009c(sp)
800AD420	lw     fp, $0098(sp)
800AD424	lw     s7, $0094(sp)
800AD428	lw     s6, $0090(sp)
800AD42C	lw     s5, $008c(sp)
800AD430	lw     s4, $0088(sp)
800AD434	lw     s3, $0084(sp)
800AD438	lw     s2, $0080(sp)
800AD43C	lw     s1, $007c(sp)
800AD440	lw     s0, $0078(sp)
800AD444	jr     ra 
800AD448	addiu  sp, sp, $00a0


funcad44c:	; 800AD44C
800AD44C	addiu  sp, sp, $ffd8 (=-$28)
800AD450	addu   v1, a2, zero
800AD454	addiu  v0, zero, $0003
800AD458	sw     a1, $0014(sp)
800AD45C	addiu  a1, zero, $0100
800AD460	addiu  a2, zero, $00ff
800AD464	sw     a3, $0010(sp)
800AD468	addu   a3, v1, zero
800AD46C	sw     ra, $0020(sp)
800AD470	jal    func62e3c [$80062e3c]
800AD474	sw     v0, $0018(sp)
800AD478	lw     ra, $0020(sp)
800AD47C	nop
800AD480	jr     ra 
800AD484	addiu  sp, sp, $0028


funcad488:	; 800AD488
800AD488	addiu  sp, sp, $ff70 (=-$90)
800AD48C	sw     s2, $0080(sp)
800AD490	addu   s2, a0, zero
800AD494	sw     s3, $0084(sp)
800AD498	addu   s3, a1, zero
800AD49C	sw     ra, $0088(sp)
800AD4A0	sw     s1, $007c(sp)
800AD4A4	sw     s0, $0078(sp)
800AD4A8	lw     v0, $0000(s3)

funcad4ac:	; 800AD4AC
800AD4AC	nop
800AD4B0	andi   v0, v0, $0020
800AD4B4	beq    v0, zero, Lad5fc [$800ad5fc]
800AD4B8	addu   s1, a2, zero
800AD4BC	lw     a0, $0004(s2)
800AD4C0	jal    system_get_cos_by_rotation [$8004bb7c]
800AD4C4	andi   a0, a0, $0fff
800AD4C8	lw     a0, $0004(s2)
800AD4CC	addu   s0, v0, zero
800AD4D0	jal    system_get_sin_by_rotation [$8004bb80]
800AD4D4	andi   a0, a0, $0fff
800AD4D8	lw     v1, $0000(s2)
800AD4DC	nop
800AD4E0	srl    v1, v1, $08

funcad4e4:	; 800AD4E4
800AD4E4	andi   v1, v1, $0fff
800AD4E8	mult   s0, v1
800AD4EC	sh     zero, $0006(s1)
800AD4F0	mflo   v1
800AD4F4	sra    v1, v1, $0c
800AD4F8	sh     v1, $0000(s1)
800AD4FC	lw     v1, $0000(s2)
800AD500	subu   a1, zero, v0
800AD504	srl    v1, v1, $08
800AD508	andi   v1, v1, $0fff
800AD50C	mult   a1, v1
800AD510	sh     zero, $0002(s1)
800AD514	sh     zero, $000e(s1)
800AD518	addiu  v1, zero, $1000
800AD51C	sh     v1, $0008(s1)
800AD520	mflo   t0
800AD524	sra    v1, t0, $0c
800AD528	sh     v1, $000c(s1)
800AD52C	lw     v1, $0000(s2)
800AD530	nop
800AD534	srl    v1, v1, $14
800AD538	mult   v0, v1
800AD53C	sh     zero, $000a(s1)
800AD540	mflo   v1
800AD544	sra    v1, v1, $0c
800AD548	sh     v1, $0004(s1)
800AD54C	lw     v1, $0000(s2)
800AD550	nop
800AD554	srl    v1, v1, $14
800AD558	mult   s0, v1
800AD55C	mflo   v1
800AD560	sra    v1, v1, $0c
800AD564	sh     v1, $0010(s1)
800AD568	lw     a0, $0004(s2)
800AD56C	nop
800AD570	sll    v1, a0, $0a
800AD574	sra    v1, v1, $16
800AD578	mult   s0, v1
800AD57C	mflo   a2
800AD580	sra    a0, a0, $16
800AD584	nop
800AD588	mult   v0, a0
800AD58C	lw     v1, $000c(s3)
800AD590	nop
800AD594	lw     v1, $0014(v1)
800AD598	mflo   t0
800AD59C	addu   v0, a2, t0
800AD5A0	sra    v0, v0, $0c
800AD5A4	addu   v0, v0, v1
800AD5A8	sw     v0, $0014(s1)
800AD5AC	lw     v0, $000c(s3)
800AD5B0	nop
800AD5B4	lw     v0, $0018(v0)
800AD5B8	nop
800AD5BC	sw     v0, $0018(s1)
800AD5C0	lw     v1, $0004(s2)
800AD5C4	nop
800AD5C8	sll    v0, v1, $0a
800AD5CC	sra    v0, v0, $16
800AD5D0	mult   a1, v0
800AD5D4	mflo   v0
800AD5D8	sra    v1, v1, $16
800AD5DC	nop
800AD5E0	mult   s0, v1
800AD5E4	lw     v1, $000c(s3)
800AD5E8	nop
800AD5EC	lw     v1, $001c(v1)
800AD5F0	mflo   t0
800AD5F4	j      Lad91c [$800ad91c]
800AD5F8	addu   v0, v0, t0

Lad5fc:	; 800AD5FC
800AD5FC	lw     v0, $0008(s3)
800AD600	nop
800AD604	lw     v0, $0020(v0)
800AD608	nop
800AD60C	addiu  v1, v0, $0020
800AD610	lw     a1, $0020(v0)
800AD614	lw     v0, $0004(v1)
800AD618	addiu  a0, sp, $0010
800AD61C	sw     v0, $0004(a0)
800AD620	lw     v0, $0008(v1)
800AD624	nop
800AD628	sw     v0, $0008(a0)
800AD62C	lw     v0, $000c(v1)
800AD630	nop
800AD634	sw     v0, $000c(a0)
800AD638	lw     v0, $0010(v1)
800AD63C	nop
800AD640	sw     v0, $0010(a0)
800AD644	lw     v0, $0014(v1)
800AD648	nop
800AD64C	sw     v0, $0014(a0)
800AD650	lw     v0, $0018(v1)
800AD654	nop
800AD658	sw     v0, $0018(a0)
800AD65C	lw     v0, $001c(v1)
800AD660	sw     a1, $0010(sp)
800AD664	sw     v0, $001c(a0)
800AD668	addiu  v0, zero, $f000 (=-$1000)
800AD66C	sw     zero, $002c(sp)
800AD670	sw     zero, $0028(sp)
800AD674	sw     zero, $0024(sp)
800AD678	sh     zero, $0030(sp)
800AD67C	sh     v0, $0032(sp)
800AD680	sh     zero, $0034(sp)
800AD684	lw     t4, $0000(a0)
800AD688	lw     t5, $0004(a0)
800AD68C	ctc2   t4,vxy0
800AD690	ctc2   t5,vz0
800AD694	lw     t4, $0008(a0)
800AD698	lw     t5, $000c(a0)
800AD69C	lw     t6, $0010(a0)
800AD6A0	ctc2   t4,vxy1
800AD6A4	ctc2   t5,vz1
800AD6A8	ctc2   t6,vxy2
800AD6AC	lw     t4, $0014(a0)
800AD6B0	lw     t5, $0018(a0)
800AD6B4	ctc2   t4,vz2
800AD6B8	lw     t6, $001c(a0)
800AD6BC	ctc2   t5,rgb
800AD6C0	ctc2   t6,otz
800AD6C4	addiu  v0, sp, $0030
800AD6C8	lwc2   zero, $0000(v0)

Lad6cc:	; 800AD6CC
800AD6CC	lwc2   at, $0004(v0)

Lad6d0:	; 800AD6D0
800AD6D0	nop
800AD6D4	nop
800AD6D8	gte_func18t0,r11r12
800AD6DC	addiu  a0, sp, $0038
800AD6E0	swc2   t9, $0000(a0)
800AD6E4	swc2   k0, $0004(a0)
800AD6E8	swc2   k1, $0008(a0)
800AD6EC	addiu  s0, sp, $0068
800AD6F0	addu   a1, s0, zero
800AD6F4	jal    func62c2c [$80062c2c]
800AD6F8	sw     zero, $003c(sp)
800AD6FC	lw     v1, $0068(sp)
800AD700	addiu  v0, zero, $1000
800AD704	sw     v0, $005c(sp)
800AD708	lw     v0, $006c(sp)
800AD70C	sw     zero, $0058(sp)
800AD710	sw     zero, $0060(sp)
800AD714	subu   v1, zero, v1
800AD718	sw     v1, $0068(sp)
800AD71C	lw     v1, $0070(sp)
800AD720	subu   v0, zero, v0
800AD724	sw     v0, $006c(sp)
800AD728	addiu  v0, sp, $0058
800AD72C	subu   v1, zero, v1
800AD730	sw     v1, $0070(sp)
800AD734	lw     t4, $0000(v0)
800AD738	lw     t5, $0004(v0)
800AD73C	ctc2   t4,vxy0
800AD740	lw     t6, $0008(v0)
800AD744	ctc2   t5,vxy1
800AD748	ctc2   t6,vxy2
800AD74C	lwc2   t3, $0008(s0)
800AD750	lwc2   t1, $0000(s0)
800AD754	lwc2   t2, $0004(s0)
800AD758	nop
800AD75C	nop
800AD760	gte_func27t8,r11r12
800AD764	addiu  v0, sp, $0048
800AD768	swc2   t9, $0000(v0)
800AD76C	swc2   k0, $0004(v0)
800AD770	swc2   k1, $0008(v0)
800AD774	lw     v0, $0000(s2)
800AD778	lw     v1, $0048(sp)
800AD77C	srl    v0, v0, $08
800AD780	andi   v0, v0, $0fff
800AD784	mult   v1, v0
800AD788	mflo   v1
800AD78C	sra    v0, v1, $0c
800AD790	sh     v0, $0000(s1)
800AD794	lw     v0, $0000(s2)
800AD798	lw     v1, $004c(sp)
800AD79C	srl    v0, v0, $08
800AD7A0	andi   v0, v0, $0fff
800AD7A4	mult   v1, v0
800AD7A8	mflo   v1
800AD7AC	sra    v0, v1, $0c
800AD7B0	sh     v0, $0006(s1)
800AD7B4	lw     v0, $0000(s2)
800AD7B8	lw     v1, $0050(sp)
800AD7BC	srl    v0, v0, $08
800AD7C0	andi   v0, v0, $0fff
800AD7C4	mult   v1, v0
800AD7C8	mflo   v1
800AD7CC	sra    v0, v1, $0c
800AD7D0	sh     v0, $000c(s1)
800AD7D4	lhu    v0, $0058(sp)
800AD7D8	nop
800AD7DC	sh     v0, $0002(s1)
800AD7E0	lhu    v0, $005c(sp)
800AD7E4	nop
800AD7E8	sh     v0, $0008(s1)
800AD7EC	lhu    v0, $0060(sp)
800AD7F0	nop
800AD7F4	sh     v0, $000e(s1)
800AD7F8	lw     v0, $0000(s2)
800AD7FC	lw     v1, $0068(sp)
800AD800	srl    v0, v0, $14
800AD804	mult   v1, v0
800AD808	mflo   v1
800AD80C	sra    v0, v1, $0c
800AD810	sh     v0, $0004(s1)
800AD814	lw     v0, $0000(s2)
800AD818	lw     v1, $006c(sp)
800AD81C	srl    v0, v0, $14
800AD820	mult   v1, v0
800AD824	mflo   v1
800AD828	sra    v0, v1, $0c
800AD82C	sh     v0, $000a(s1)
800AD830	lw     v0, $0000(s2)
800AD834	lw     v1, $0070(sp)
800AD838	srl    v0, v0, $14
800AD83C	mult   v1, v0
800AD840	mflo   v1
800AD844	sra    v0, v1, $0c
800AD848	sh     v0, $0010(s1)
800AD84C	lw     v1, $0004(s2)
800AD850	lw     a0, $0048(sp)
800AD854	sll    v0, v1, $0a
800AD858	sra    v0, v0, $16
800AD85C	mult   a0, v0
800AD860	mflo   a0
800AD864	lw     v0, $0068(sp)
800AD868	sra    v1, v1, $16
800AD86C	mult   v0, v1
800AD870	lw     v0, $0008(s3)
800AD874	nop
800AD878	lw     v1, $0020(v0)
800AD87C	nop
800AD880	lw     v1, $0034(v1)
800AD884	mflo   t0
800AD888	addu   v0, a0, t0
800AD88C	sra    v0, v0, $0c
800AD890	addu   v0, v0, v1
800AD894	sw     v0, $0014(s1)
800AD898	lw     v1, $0004(s2)
800AD89C	lw     a0, $004c(sp)
800AD8A0	sll    v0, v1, $0a
800AD8A4	sra    v0, v0, $16
800AD8A8	mult   a0, v0
800AD8AC	mflo   a0
800AD8B0	lw     v0, $006c(sp)
800AD8B4	sra    v1, v1, $16
800AD8B8	mult   v0, v1
800AD8BC	lw     v1, $000c(s3)
800AD8C0	nop
800AD8C4	lw     v1, $0018(v1)
800AD8C8	mflo   t0
800AD8CC	addu   v0, a0, t0
800AD8D0	sra    v0, v0, $0c
800AD8D4	addu   v0, v0, v1
800AD8D8	sw     v0, $0018(s1)
800AD8DC	lw     v1, $0004(s2)
800AD8E0	lw     a0, $0050(sp)
800AD8E4	sll    v0, v1, $0a
800AD8E8	sra    v0, v0, $16
800AD8EC	mult   a0, v0
800AD8F0	mflo   a0
800AD8F4	lw     v0, $0070(sp)
800AD8F8	sra    v1, v1, $16
800AD8FC	mult   v0, v1
800AD900	lw     v0, $0008(s3)
800AD904	nop
800AD908	lw     v1, $0020(v0)

funcad90c:	; 800AD90C
800AD90C	nop
800AD910	lw     v1, $003c(v1)
800AD914	mflo   t0
800AD918	addu   v0, a0, t0

Lad91c:	; 800AD91C
800AD91C	sra    v0, v0, $0c
800AD920	addu   v0, v0, v1
800AD924	sw     v0, $001c(s1)
800AD928	lw     ra, $0088(sp)
800AD92C	lw     s3, $0084(sp)
800AD930	lw     s2, $0080(sp)
800AD934	lw     s1, $007c(sp)
800AD938	lw     s0, $0078(sp)
800AD93C	jr     ra 
800AD940	addiu  sp, sp, $0090



/////////////////////////////////////////////////////
// funcad944
800AD944-800ADA78
/////////////////////////////////////////////////////



funcada7c:	; 800ADA7C
800ADA7C	addiu  sp, sp, $ffe8 (=-$18)
800ADA80	sw     s0, $0010(sp)
800ADA84	lui    s0, $8006
800ADA88	lw     v0, $794c(s0)
800ADA8C	sw     ra, $0014(sp)
800ADA90	lw     v0, $001c(v0)
800ADA94	nop
800ADA98	lw     v0, $08e4(v0)
800ADA9C	nop
800ADAA0	lw     v0, $000c(v0)
800ADAA4	nop
800ADAA8	lw     v1, $0014(v0)
800ADAAC	lui    v0, $800d
800ADAB0	sh     zero, $9d44(v0)
800ADAB4	sb     a0, $0048(v1)
800ADAB8	lw     v0, $794c(s0)
800ADABC	nop
800ADAC0	lw     v0, $001c(v0)
800ADAC4	nop
800ADAC8	lw     v0, $08e4(v0)
800ADACC	nop
800ADAD0	lw     v0, $000c(v0)
800ADAD4	nop
800ADAD8	lw     v0, $0014(v0)
800ADADC	nop
800ADAE0	sb     a1, $0049(v0)
800ADAE4	lw     v0, $794c(s0)
800ADAE8	nop
800ADAEC	lw     v0, $001c(v0)
800ADAF0	nop
800ADAF4	lw     v0, $08e4(v0)
800ADAF8	nop
800ADAFC	lw     v0, $000c(v0)
800ADB00	nop
800ADB04	lw     v0, $0014(v0)
800ADB08	jal    funcac5f0 [$800ac5f0]
800ADB0C	sb     a2, $0043(v0)
800ADB10	jal    func223cc [$800223cc]
800ADB14	nop
800ADB18	lw     a0, $794c(s0)
800ADB1C	nop
800ADB20	lw     v0, $001c(a0)
800ADB24	nop
800ADB28	lw     v1, $08e4(v0)
800ADB2C	nop
800ADB30	lw     v0, $0000(v1)
800ADB34	nop
800ADB38	ori    v0, v0, $1000
800ADB3C	sw     v0, $0000(v1)
800ADB40	lw     v0, $001c(a0)
800ADB44	nop
800ADB48	lw     v0, $08e4(v0)
800ADB4C	nop
800ADB50	lw     v0, $000c(v0)
800ADB54	nop
800ADB58	lw     v1, $0014(v0)
800ADB5C	addiu  v0, zero, $0001
800ADB60	sb     v0, $0042(v1)
800ADB64	lw     ra, $0014(sp)
800ADB68	lw     s0, $0010(sp)
800ADB6C	jr     ra 
800ADB70	addiu  sp, sp, $0018


funcadb74:	; 800ADB74
800ADB74	lui    v0, $8006
800ADB78	lw     v0, $794c(v0)
800ADB7C	addiu  sp, sp, $ffd0 (=-$30)
800ADB80	sw     ra, $002c(sp)
800ADB84	sw     s2, $0028(sp)
800ADB88	sw     s1, $0024(sp)
800ADB8C	sw     s0, $0020(sp)
800ADB90	lw     v0, $001c(v0)
800ADB94	nop
800ADB98	lw     v0, $08e4(v0)
800ADB9C	nop
800ADBA0	lw     v0, $000c(v0)
800ADBA4	nop
800ADBA8	lw     v0, $0014(v0)
800ADBAC	nop
800ADBB0	lbu    v0, $0042(v0)
800ADBB4	nop
800ADBB8	addiu  v0, v0, $ffff (=-$1)
800ADBBC	sll    v0, v0, $18
800ADBC0	sra    v1, v0, $18
800ADBC4	sltiu  v0, v1, $0007
800ADBC8	beq    v0, zero, Lae4e0 [$800ae4e0]
800ADBCC	lui    v0, $800a
800ADBD0	addiu  v0, v0, $70b0
800ADBD4	sll    v1, v1, $02
800ADBD8	addu   v1, v1, v0
800ADBDC	lw     v0, $0000(v1)
800ADBE0	nop
800ADBE4	jr     v0 
800ADBE8	nop

800ADBEC	jal    func22b18 [$80022b18]
800ADBF0	nop
800ADBF4	bne    v0, zero, Lae4e0 [$800ae4e0]
800ADBF8	lui    s0, $8006
800ADBFC	lw     v0, $794c(s0)
800ADC00	nop
800ADC04	lw     a0, $001c(v0)
800ADC08	jal    func217c4 [$800217c4]
800ADC0C	addiu  a0, a0, $0854
800ADC10	bne    v0, zero, Ladc6c [$800adc6c]
800ADC14	addu   a0, zero, zero
800ADC18	jal    func1e218 [$8001e218]
800ADC1C	addiu  a1, zero, $0064
800ADC20	lui    t0, $000f
800ADC24	ori    t0, t0, $1700
800ADC28	lui    a1, $0001
800ADC2C	ori    a1, a1, $5000
800ADC30	lw     a2, $000c(v0)
800ADC34	lw     v1, $0004(v0)
800ADC38	lw     a0, $794c(s0)
800ADC3C	subu   a2, a2, v1
800ADC40	lw     a0, $001c(a0)
800ADC44	sll    a2, a2, $0b
800ADC48	sw     zero, $0010(sp)
800ADC4C	sw     a1, $0014(sp)
800ADC50	sw     zero, $0018(sp)
800ADC54	lw     a1, $0004(v0)
800ADC58	lui    v0, $8006
800ADC5C	lw     a3, $7944(v0)
800ADC60	addiu  a0, a0, $0854
800ADC64	jal    func2177c [$8002177c]
800ADC68	addu   a3, a3, t0

Ladc6c:	; 800ADC6C
800ADC6C	lw     v0, $794c(s0)
800ADC70	nop
800ADC74	lw     v0, $001c(v0)
800ADC78	nop
800ADC7C	lw     v0, $08e4(v0)
800ADC80	nop
800ADC84	lw     v0, $000c(v0)
800ADC88	nop
800ADC8C	lw     v1, $0014(v0)
800ADC90	j      Lae4dc [$800ae4dc]
800ADC94	addiu  v0, zero, $0002
800ADC98	lui    s0, $8006
800ADC9C	lw     v0, $794c(s0)
800ADCA0	nop
800ADCA4	lw     a0, $001c(v0)
800ADCA8	jal    func217c4 [$800217c4]
800ADCAC	addiu  a0, a0, $0854
800ADCB0	bne    v0, zero, Lae4e0 [$800ae4e0]
800ADCB4	lui    a0, $800d
800ADCB8	lw     v0, $794c(s0)
800ADCBC	nop
800ADCC0	lw     v0, $001c(v0)
800ADCC4	nop
800ADCC8	lw     v1, $08e4(v0)
800ADCCC	lhu    v0, $9d44(a0)
800ADCD0	lw     v1, $000c(v1)
800ADCD4	ori    v0, v0, $0008
800ADCD8	sh     v0, $9d44(a0)
800ADCDC	lw     v1, $0014(v1)
800ADCE0	j      Lae4dc [$800ae4dc]
800ADCE4	addiu  v0, zero, $0003
800ADCE8	lui    v0, $800d
800ADCEC	lhu    v0, $9d44(v0)
800ADCF0	nop
800ADCF4	andi   v0, v0, $0008
800ADCF8	bne    v0, zero, Lae4e0 [$800ae4e0]
800ADCFC	lui    s0, $8006
800ADD00	lw     v0, $794c(s0)
800ADD04	nop
800ADD08	lw     v0, $001c(v0)
800ADD0C	nop
800ADD10	lw     v0, $08e4(v0)
800ADD14	nop
800ADD18	lw     v0, $000c(v0)
800ADD1C	nop
800ADD20	lw     a0, $0014(v0)
800ADD24	lui    v0, $801a
800ADD28	addiu  v0, v0, $dc5c (=-$23a4)
800ADD2C	lbu    v1, $0048(a0)
800ADD30	lbu    a0, $0049(a0)

Ladd34:	; 800ADD34
800ADD34	sll    v1, v1, $03
800ADD38	addu   v1, v1, v0
800ADD3C	sll    v0, a0, $02

Ladd40:	; 800ADD40
800ADD40	addu   v0, v0, a0
800ADD44	lw     v1, $0004(v1)
800ADD48	sll    v0, v0, $02
800ADD4C	addu   v0, v0, v1
800ADD50	lw     a0, $0000(v0)
800ADD54	jal    func22ac4 [$80022ac4]
800ADD58	nop
800ADD5C	lw     v1, $794c(s0)
800ADD60	nop
800ADD64	lw     v1, $001c(v1)
800ADD68	nop
800ADD6C	lw     v1, $08e4(v1)
800ADD70	nop
800ADD74	lw     v1, $000c(v1)
800ADD78	nop
800ADD7C	lw     v1, $0014(v1)
800ADD80	jal    func22b18 [$80022b18]
800ADD84	sw     v0, $0044(v1)
800ADD88	bne    v0, zero, Lae4e0 [$800ae4e0]
800ADD8C	nop
800ADD90	lw     v0, $794c(s0)
800ADD94	nop
800ADD98	lw     v0, $001c(v0)
800ADD9C	nop
800ADDA0	lw     v0, $08e4(v0)
800ADDA4	nop
800ADDA8	lw     v0, $000c(v0)
800ADDAC	nop
800ADDB0	lw     v0, $0014(v0)
800ADDB4	nop
800ADDB8	lw     a0, $0044(v0)
800ADDBC	jal    func22ed4 [$80022ed4]
800ADDC0	nop
800ADDC4	lw     v0, $794c(s0)
800ADDC8	nop
800ADDCC	lw     v0, $001c(v0)
800ADDD0	nop
800ADDD4	lw     v0, $08e4(v0)
800ADDD8	nop
800ADDDC	lw     v0, $000c(v0)
800ADDE0	nop
800ADDE4	lw     v1, $0014(v0)
800ADDE8	j      Lae4dc [$800ae4dc]
800ADDEC	addiu  v0, zero, $0004
800ADDF0	jal    func22b18 [$80022b18]
800ADDF4	nop
800ADDF8	bne    v0, zero, Lae4e0 [$800ae4e0]
800ADDFC	lui    v0, $8006
800ADE00	lw     v0, $794c(v0)
800ADE04	nop
800ADE08	lw     v0, $001c(v0)
800ADE0C	nop
800ADE10	lw     v0, $08e4(v0)
800ADE14	nop
800ADE18	lw     v0, $000c(v0)
800ADE1C	nop
800ADE20	lw     v1, $0014(v0)
800ADE24	j      Lae4dc [$800ae4dc]
800ADE28	addiu  v0, zero, $0005
800ADE2C	lui    v0, $800d
800ADE30	lhu    v0, $9d44(v0)
800ADE34	nop
800ADE38	andi   v0, v0, $0001
800ADE3C	beq    v0, zero, Lae4e0 [$800ae4e0]

Lade40:	; 800ADE40
800ADE40	lui    s0, $8006
800ADE44	lw     a2, $794c(s0)
800ADE48	nop
800ADE4C	lw     v0, $001c(a2)
800ADE50	nop
800ADE54	lbu    v0, $0008(v0)
800ADE58	nop
800ADE5C	beq    v0, zero, Lade68 [$800ade68]
800ADE60	addiu  a1, zero, $0001
800ADE64	addiu  a1, zero, $0002

Lade68:	; 800ADE68
800ADE68	lui    v0, $800d
800ADE6C	addiu  a3, v0, $9ef0 (=-$6110)
800ADE70	addiu  v0, a1, $ffff (=-$1)
800ADE74	sll    v0, v0, $01
800ADE78	addu   a0, v0, a3
800ADE7C	addiu  v0, zero, $0600
800ADE80	addiu  v1, zero, $0019
800ADE84	sh     v0, $0010(a0)
800ADE88	ori    v0, v0, $0800
800ADE8C	sh     v1, $0000(a0)
800ADE90	sh     v0, $0010(a0)
800ADE94	lw     v0, $001c(a2)
800ADE98	nop
800ADE9C	lw     v0, $08e4(v0)
800ADEA0	nop
800ADEA4	lw     v0, $000c(v0)
800ADEA8	nop
800ADEAC	lw     v0, $0014(v0)
800ADEB0	nop
800ADEB4	lbu    v0, $0043(v0)
800ADEB8	nop
800ADEBC	beq    v0, zero, Laded8 [$800aded8]
800ADEC0	addu   v0, v1, zero
800ADEC4	lhu    v1, $0010(a0)
800ADEC8	ori    v0, v0, $0044
800ADECC	sh     v0, $0000(a0)
800ADED0	ori    v1, v1, $0001
800ADED4	sh     v1, $0010(a0)

Laded8:	; 800ADED8
800ADED8	addiu  v1, zero, $0040
800ADEDC	sll    v0, a1, $01
800ADEE0	addu   v0, v0, a3
800ADEE4	sh     v1, $0020(a0)
800ADEE8	sh     v1, $0028(v0)
800ADEEC	addiu  v1, zero, $0002
800ADEF0	lui    a0, $8007
800ADEF4	sh     v1, $0020(v0)
800ADEF8	lw     v0, $3998(a0)
800ADEFC	lui    a1, $0400
800ADF00	and    v0, v0, a1
800ADF04	bne    v0, zero, Ladf54 [$800adf54]
800ADF08	nop
800ADF0C	lw     v0, $794c(s0)
800ADF10	nop
800ADF14	lw     v0, $001c(v0)
800ADF18	nop
800ADF1C	lw     v0, $08e4(v0)
800ADF20	nop
800ADF24	lw     v0, $000c(v0)
800ADF28	nop
800ADF2C	lw     v1, $0014(v0)
800ADF30	nop
800ADF34	lw     v0, $0000(v1)
800ADF38	nop
800ADF3C	ori    v0, v0, $1000
800ADF40	sw     v0, $0000(v1)
800ADF44	lw     v0, $3998(a0)
800ADF48	nop
800ADF4C	or     v0, v0, a1
800ADF50	sw     v0, $3998(a0)

Ladf54:	; 800ADF54
800ADF54	addu   a0, zero, zero
800ADF58	lw     v1, $794c(s0)
800ADF5C	addiu  v0, zero, $0004
800ADF60	jal    func56248 [$80056248]
800ADF64	sb     v0, $0009(v1)
800ADF68	jal    func56228 [$80056228]
800ADF6C	nop
800ADF70	jal    func130a4 [$800130a4]
800ADF74	addu   a0, zero, zero
800ADF78	lw     v0, $794c(s0)
800ADF7C	nop
800ADF80	lw     v0, $001c(v0)
800ADF84	nop
800ADF88	lw     v0, $08e4(v0)
800ADF8C	nop
800ADF90	lw     v0, $000c(v0)
800ADF94	nop
800ADF98	lw     a1, $0014(v0)
800ADF9C	addiu  a0, zero, $0001
800ADFA0	jal    func1999b4 [$801999b4]
800ADFA4	addiu  a1, a1, $0034
800ADFA8	lw     v0, $794c(s0)
800ADFAC	nop
800ADFB0	lw     v0, $001c(v0)
800ADFB4	nop
800ADFB8	lw     v0, $08e4(v0)
800ADFBC	nop
800ADFC0	lw     v0, $000c(v0)
800ADFC4	nop
800ADFC8	lw     v0, $0014(v0)
800ADFCC	nop
800ADFD0	lbu    a0, $0043(v0)
800ADFD4	jal    func19a5b0 [$8019a5b0]
800ADFD8	nop
800ADFDC	lui    a0, $800b
800ADFE0	jal    func19ac3c [$8019ac3c]
800ADFE4	addiu  a0, a0, $e4f8 (=-$1b08)
800ADFE8	lw     v0, $794c(s0)
800ADFEC	nop
800ADFF0	lw     v0, $001c(v0)
800ADFF4	addiu  a0, zero, $0002
800ADFF8	lw     v0, $08e4(v0)
800ADFFC	lui    v1, $8007
800AE000	lw     v0, $000c(v0)
800AE004	lhu    v1, $1e34(v1)
800AE008	lw     a1, $0014(v0)
800AE00C	lui    v0, $800d
800AE010	sh     v1, $9d46(v0)
800AE014	lbu    a2, $005d(a1)

Lae018:	; 800AE018
800AE018	jal    func19ab98 [$8019ab98]
800AE01C	addiu  a1, zero, $0004
800AE020	lw     v0, $794c(s0)
800AE024	nop
800AE028	lw     v0, $001c(v0)
800AE02C	nop
800AE030	lw     v0, $08e4(v0)
800AE034	nop
800AE038	lw     v0, $000c(v0)
800AE03C	nop
800AE040	lw     v0, $0014(v0)
800AE044	nop
800AE048	lbu    a0, $0048(v0)
800AE04C	lbu    a1, $0049(v0)
800AE050	jal    func199b28 [$80199b28]
800AE054	nop
800AE058	lw     v0, $794c(s0)
800AE05C	nop
800AE060	lw     v0, $001c(v0)
800AE064	nop
800AE068	lw     v0, $08e4(v0)
800AE06C	nop
800AE070	lw     v0, $000c(v0)
800AE074	nop
800AE078	lw     v1, $0014(v0)
800AE07C	j      Lae4dc [$800ae4dc]
800AE080	addiu  v0, zero, $0006
800AE084	lui    s0, $800d
800AE088	lhu    v0, $9d44(s0)
800AE08C	nop
800AE090	andi   v0, v0, $0040
800AE094	beq    v0, zero, Lae0b8 [$800ae0b8]
800AE098	lui    v0, $8006
800AE09C	lw     v0, $794c(v0)
800AE0A0	nop
800AE0A4	lw     a1, $001c(v0)
800AE0A8	nop
800AE0AC	addiu  a0, a1, $0018
800AE0B0	jal    func19ad4c [$8019ad4c]
800AE0B4	addiu  a1, a1, $000a

Lae0b8:	; 800AE0B8
800AE0B8	lhu    v0, $9d44(s0)
800AE0BC	nop
800AE0C0	andi   v0, v0, $0002
800AE0C4	beq    v0, zero, Lae4e0 [$800ae4e0]
800AE0C8	nop
800AE0CC	jal    func12ad4 [$80012ad4]
800AE0D0	nop
800AE0D4	andi   v0, v0, $0002
800AE0D8	beq    v0, zero, Lae4e0 [$800ae4e0]
800AE0DC	nop
800AE0E0	jal    func199f30 [$80199f30]
800AE0E4	addu   a0, zero, zero
800AE0E8	jal    func19ad0c [$8019ad0c]
800AE0EC	addu   s1, v0, zero
800AE0F0	lhu    v1, $9d44(s0)
800AE0F4	nop
800AE0F8	andi   v1, v1, $0020
800AE0FC	bne    v1, zero, Lae148 [$800ae148]
800AE100	addu   s2, v0, zero
800AE104	lui    v0, $0001
800AE108	ori    v0, v0, $869e
800AE10C	sltu   v0, v0, s2
800AE110	bne    v0, zero, Lae148 [$800ae148]
800AE114	lui    v0, $8007
800AE118	lw     v0, $1e34(v0)
800AE11C	nop

Lae120:	; 800AE120
800AE120	subu   a0, s2, v0
800AE124	slti   v0, a0, $0004
800AE128	beq    v0, zero, Lae148 [$800ae148]
800AE12C	sll    a0, a0, $02
800AE130	jal    func56278 [$80056278]
800AE134	addu   a1, zero, zero
800AE138	lhu    v0, $9d44(s0)
800AE13C	nop
800AE140	ori    v0, v0, $0020
800AE144	sh     v0, $9d44(s0)

Lae148:	; 800AE148
800AE148	beq    s1, zero, Lae298 [$800ae298]
800AE14C	lui    a0, $8006
800AE150	lw     v0, $794c(a0)
800AE154	nop
800AE158	lw     v0, $001c(v0)
800AE15C	lui    a1, $800d
800AE160	lbu    v1, $0008(v0)
800AE164	addiu  a1, a1, $9f6c (=-$6094)
800AE168	xori   v1, v1, $0001
800AE16C	sll    v0, v1, $01
800AE170	addu   v0, v0, v1
800AE174	sll    v0, v0, $03
800AE178	addu   v0, v0, a1
800AE17C	addiu  v1, zero, $0002
800AE180	sb     v1, $0003(v0)
800AE184	lw     t0, $794c(a0)
800AE188	nop
800AE18C	lw     v0, $001c(t0)
800AE190	lui    a0, $e600
800AE194	lbu    v1, $0008(v0)
800AE198	ori    a0, a0, $0002
800AE19C	xori   v1, v1, $0001
800AE1A0	sll    v0, v1, $01
800AE1A4	addu   v0, v0, v1
800AE1A8	sll    v0, v0, $03
800AE1AC	addu   v0, v0, a1
800AE1B0	sw     a0, $0004(v0)
800AE1B4	lw     v0, $001c(t0)
800AE1B8	nop
800AE1BC	lbu    v1, $0008(v0)
800AE1C0	lui    a3, $00ff
800AE1C4	xori   v1, v1, $0001
800AE1C8	sll    v0, v1, $01
800AE1CC	addu   v0, v0, v1
800AE1D0	sll    v0, v0, $03
800AE1D4	addu   v0, v0, a1
800AE1D8	sw     zero, $0008(v0)
800AE1DC	lw     v1, $001c(t0)
800AE1E0	ori    a3, a3, $ffff
800AE1E4	lbu    v0, $0008(v1)
800AE1E8	lui    t1, $ff00
800AE1EC	xori   v0, v0, $0001
800AE1F0	sll    a0, v0, $01
800AE1F4	addu   a0, a0, v0
800AE1F8	sll    a0, a0, $03
800AE1FC	addu   a0, a0, a1
800AE200	sll    v0, v0, $02
800AE204	addu   v1, v1, v0
800AE208	lw     v0, $0010(v1)
800AE20C	lw     v1, $0000(a0)
800AE210	lw     v0, $0000(v0)
800AE214	and    v1, v1, t1
800AE218	and    v0, v0, a3
800AE21C	or     v1, v1, v0
800AE220	sw     v1, $0000(a0)
800AE224	lw     v0, $001c(t0)
800AE228	nop
800AE22C	lbu    a0, $0008(v0)
800AE230	nop
800AE234	xori   a0, a0, $0001
800AE238	sll    v1, a0, $02
800AE23C	addu   v0, v0, v1
800AE240	lw     a2, $0010(v0)
800AE244	sll    v0, a0, $01
800AE248	addu   v0, v0, a0
800AE24C	sll    v0, v0, $03
800AE250	addu   v0, v0, a1
800AE254	lw     v1, $0000(a2)
800AE258	and    v0, v0, a3
800AE25C	and    v1, v1, t1
800AE260	or     v1, v1, v0
800AE264	sw     v1, $0000(a2)
800AE268	lw     v1, $001c(t0)
800AE26C	nop
800AE270	lbu    v0, $0008(v1)
800AE274	nop
800AE278	xori   v0, v0, $0001
800AE27C	sll    v0, v0, $02
800AE280	addu   v1, v1, v0
800AE284	lw     a0, $0010(v1)
800AE288	jal    func13698 [$80013698]
800AE28C	nop
800AE290	j      Lae304 [$800ae304]
800AE294	lui    v0, $8007

Lae298:	; 800AE298
800AE298	lui    v0, $8006
800AE29C	lw     a0, $794c(v0)
800AE2A0	nop
800AE2A4	lw     v1, $001c(a0)
800AE2A8	nop
800AE2AC	lw     v0, $08e4(v1)
800AE2B0	nop
800AE2B4	lw     v0, $000c(v0)
800AE2B8	nop
800AE2BC	lw     v0, $0014(v0)
800AE2C0	nop
800AE2C4	lbu    v0, $0043(v0)
800AE2C8	nop
800AE2CC	beq    v0, zero, Lae304 [$800ae304]
800AE2D0	lui    v0, $8007
800AE2D4	lbu    v0, $0008(v1)
800AE2D8	nop
800AE2DC	bne    v0, zero, Lae300 [$800ae300]
800AE2E0	addu   v1, v0, zero
800AE2E4	sll    v0, v1, $02
800AE2E8	addu   v0, v0, v1
800AE2EC	lw     v1, $000c(a0)
800AE2F0	sll    v0, v0, $02
800AE2F4	addu   v0, v0, v1
800AE2F8	addiu  v1, zero, $01e0
800AE2FC	sh     v1, $0000(v0)

Lae300:	; 800AE300
800AE300	lui    v0, $8007

Lae304:	; 800AE304
800AE304	lw     v1, $1e34(v0)
800AE308	nop
800AE30C	slt    v0, v1, s2
800AE310	beq    v0, zero, Lae32c [$800ae32c]
800AE314	lui    v0, $800d
800AE318	lhu    v0, $9d46(v0)
800AE31C	nop
800AE320	slt    v0, v0, v1
800AE324	bne    v0, zero, Lae470 [$800ae470]
800AE328	lui    v0, $8007

Lae32c:	; 800AE32C
800AE32C	lui    v0, $800d
800AE330	lhu    v0, $9d44(v0)
800AE334	nop
800AE338	andi   v0, v0, $0100
800AE33C	bne    v0, zero, Lae470 [$800ae470]
800AE340	lui    v0, $8007
800AE344	lui    v0, $800d
800AE348	lhu    v0, $9d46(v0)
800AE34C	nop
800AE350	slt    v0, v0, v1
800AE354	bne    v0, zero, Lae444 [$800ae444]
800AE358	lui    v0, $800d
800AE35C	lui    s0, $8006
800AE360	lw     v0, $794c(s0)
800AE364	nop
800AE368	lw     v1, $001c(v0)
800AE36C	nop
800AE370	lbu    v0, $0008(v1)
800AE374	nop
800AE378	sll    v0, v0, $02
800AE37C	addu   v1, v1, v0
800AE380	lw     a0, $0010(v1)
800AE384	jal    func13590 [$80013590]
800AE388	addiu  a1, zero, $1000
800AE38C	lw     a1, $794c(s0)
800AE390	nop
800AE394	lw     a0, $001c(a1)
800AE398	nop
800AE39C	lw     v0, $0000(a0)
800AE3A0	addiu  v1, zero, $ffe2 (=-$1e)
800AE3A4	and    v0, v0, v1
800AE3A8	sw     v0, $0000(a0)
800AE3AC	lw     v0, $001c(a1)
800AE3B0	nop
800AE3B4	lw     a0, $08e4(v0)
800AE3B8	nop
800AE3BC	lw     v0, $0000(a0)
800AE3C0	addiu  v1, zero, $f1fe (=-$e02)
800AE3C4	and    v0, v0, v1
800AE3C8	sw     v0, $0000(a0)
800AE3CC	lw     v1, $001c(a1)
800AE3D0	nop
800AE3D4	lw     v0, $08e4(v1)
800AE3D8	nop
800AE3DC	lw     v0, $000c(v0)
800AE3E0	nop
800AE3E4	lw     v0, $0014(v0)
800AE3E8	nop
800AE3EC	lbu    v0, $0043(v0)
800AE3F0	nop
800AE3F4	beq    v0, zero, Lae42c [$800ae42c]
800AE3F8	lui    v0, $800d
800AE3FC	lbu    v0, $0008(v1)
800AE400	nop
800AE404	bne    v0, zero, Lae428 [$800ae428]
800AE408	addu   v1, v0, zero
800AE40C	sll    v0, v1, $02
800AE410	addu   v0, v0, v1
800AE414	lw     v1, $000c(a1)
800AE418	sll    v0, v0, $02
800AE41C	addu   v0, v0, v1
800AE420	addiu  v1, zero, $01e0
800AE424	sh     v1, $0000(v0)

Lae428:	; 800AE428
800AE428	lui    v0, $800d

Lae42c:	; 800AE42C
800AE42C	lhu    a1, $9d46(v0)
800AE430	lui    a0, $800a
800AE434	jal    func15c38 [$80015c38]
800AE438	addiu  a0, a0, $70a8

Lae43c:	; 800AE43C
800AE43C	j      Lae45c [$800ae45c]

Lae440:	; 800AE440
800AE440	lui    v1, $800d

Lae444:	; 800AE444
800AE444	addiu  v0, v0, $9ef0 (=-$6110)
800AE448	addiu  v1, zero, $001d
800AE44C	sh     v1, $0008(v0)
800AE450	addiu  v1, zero, $0e01

Lae454:	; 800AE454
800AE454	sh     v1, $0018(v0)
800AE458	lui    v1, $800d

Lae45c:	; 800AE45C
800AE45C	lhu    v0, $9d44(v1)
800AE460	nop
800AE464	ori    v0, v0, $0100
800AE468	sh     v0, $9d44(v1)
800AE46C	lui    v0, $8007

Lae470:	; 800AE470
800AE470	lhu    v1, $1e34(v0)
800AE474	lui    v0, $800d
800AE478	j      Lae4e0 [$800ae4e0]

funcae47c:	; 800AE47C
800AE47C	sh     v1, $9d46(v0)
800AE480	lui    v0, $800d
800AE484	lhu    v0, $9d44(v0)
800AE488	nop
800AE48C	andi   v0, v0, $0004
800AE490	beq    v0, zero, Lae4e0 [$800ae4e0]
800AE494	nop
800AE498	jal    func22b18 [$80022b18]
800AE49C	nop
800AE4A0	bne    v0, zero, Lae4e0 [$800ae4e0]
800AE4A4	nop
800AE4A8	jal    funcae5d4 [$800ae5d4]
800AE4AC	nop
800AE4B0	lui    v0, $8006
800AE4B4	lw     v0, $794c(v0)
800AE4B8	nop
800AE4BC	lw     v0, $001c(v0)
800AE4C0	nop
800AE4C4	lw     v0, $08e4(v0)
800AE4C8	nop
800AE4CC	lw     v0, $000c(v0)
800AE4D0	nop
800AE4D4	lw     v1, $0014(v0)
800AE4D8	addiu  v0, zero, $0008

Lae4dc:	; 800AE4DC
800AE4DC	sb     v0, $0042(v1)

Lae4e0:	; 800AE4E0
800AE4E0	lw     ra, $002c(sp)
800AE4E4	lw     s2, $0028(sp)
800AE4E8	lw     s1, $0024(sp)

Lae4ec:	; 800AE4EC
800AE4EC	lw     s0, $0020(sp)
800AE4F0	jr     ra 
800AE4F4	addiu  sp, sp, $0030


funcae4f8:	; 800AE4F8
800AE4F8	addiu  sp, sp, $ffe8 (=-$18)
800AE4FC	sw     s0, $0010(sp)
800AE500	lui    s0, $8006
800AE504	lw     a1, $794c(s0)
800AE508	sw     ra, $0014(sp)
800AE50C	lw     v0, $001c(a1)
800AE510	nop
800AE514	lw     v0, $08e4(v0)
800AE518	nop
800AE51C	lw     v0, $000c(v0)
800AE520	nop
800AE524	lw     v0, $0014(v0)
800AE528	nop
800AE52C	lw     v0, $0000(v0)
800AE530	nop
800AE534	andi   v0, v0, $1000
800AE538	beq    v0, zero, Lae584 [$800ae584]
800AE53C	lui    a0, $fbff
800AE540	lui    v1, $8007
800AE544	lw     v0, $3998(v1)
800AE548	ori    a0, a0, $ffff
800AE54C	and    v0, v0, a0
800AE550	sw     v0, $3998(v1)
800AE554	lw     v0, $001c(a1)
800AE558	nop
800AE55C	lw     v0, $08e4(v0)

Lae560:	; 800AE560
800AE560	nop
800AE564	lw     v0, $000c(v0)
800AE568	nop
800AE56C	lw     a0, $0014(v0)

funcae570:	; 800AE570
800AE570	nop
800AE574	lw     v0, $0000(a0)
800AE578	addiu  v1, zero, $efff (=-$1001)
800AE57C	and    v0, v0, v1
800AE580	sw     v0, $0000(a0)

Lae584:	; 800AE584
800AE584	jal    func19a9d8 [$8019a9d8]
800AE588	nop
800AE58C	jal    func22b28 [$80022b28]
800AE590	nop
800AE594	lw     v0, $794c(s0)
800AE598	nop
800AE59C	lw     v0, $001c(v0)
800AE5A0	lui    a0, $800d
800AE5A4	lw     v1, $08e4(v0)
800AE5A8	lhu    v0, $9d44(a0)
800AE5AC	lw     v1, $000c(v1)
800AE5B0	ori    v0, v0, $0004
800AE5B4	sh     v0, $9d44(a0)
800AE5B8	lw     v1, $0014(v1)
800AE5BC	addiu  v0, zero, $0007
800AE5C0	sb     v0, $0042(v1)
800AE5C4	lw     ra, $0014(sp)
800AE5C8	lw     s0, $0010(sp)
800AE5CC	jr     ra 
800AE5D0	addiu  sp, sp, $0018


funcae5d4:	; 800AE5D4
800AE5D4	lui    a3, $8006
800AE5D8	lw     a2, $794c(a3)
800AE5DC	addiu  sp, sp, $ffe0 (=-$20)
800AE5E0	sw     ra, $0018(sp)
800AE5E4	lw     a0, $001c(a2)
800AE5E8	nop
800AE5EC	lw     v0, $0000(a0)
800AE5F0	addiu  v1, zero, $ffa2 (=-$5e)
800AE5F4	and    v0, v0, v1
800AE5F8	sw     v0, $0000(a0)
800AE5FC	lui    a0, $800d
800AE600	lw     v1, $001c(a2)
800AE604	lhu    v0, $9d44(a0)

Lae608:	; 800AE608
800AE608	lw     a1, $08e4(v1)
800AE60C	andi   v0, v0, $fe00
800AE610	sh     v0, $9d44(a0)
800AE614	lw     v0, $0000(a1)
800AE618	addiu  v1, zero, $e1fe (=-$1e02)
800AE61C	and    v0, v0, v1
800AE620	sw     v0, $0000(a1)
800AE624	addiu  v0, zero, $0002
800AE628	sb     v0, $0009(a2)
800AE62C	lw     v1, $794c(a3)
800AE630	nop
800AE634	lw     a0, $000c(v1)
800AE638	addiu  v0, zero, $0140
800AE63C	sh     v0, $0000(a0)
800AE640	lw     v0, $000c(v1)
800AE644	nop
800AE648	sh     zero, $0014(v0)
800AE64C	lw     v0, $001c(v1)
800AE650	nop

Lae654:	; 800AE654
800AE654	lw     v0, $08e4(v0)
800AE658	nop
800AE65C	lw     v0, $000c(v0)
800AE660	addiu  a1, zero, $ffff (=-$1)
800AE664	lw     v0, $0014(v0)
800AE668	addu   a3, zero, zero
800AE66C	lbu    a2, $005c(v0)
800AE670	addiu  a0, zero, $6201
800AE674	jal    funcb0124 [$800b0124]
800AE678	sw     zero, $0010(sp)
800AE67C	lw     ra, $0018(sp)
800AE680	nop
800AE684	jr     ra 
800AE688	addiu  sp, sp, $0020


funcae68c:	; 800AE68C
800AE68C	lui    v0, $8006
800AE690	lw     v0, $794c(v0)
800AE694	addiu  sp, sp, $ffe8 (=-$18)
800AE698	sw     ra, $0010(sp)
800AE69C	lw     v0, $001c(v0)
800AE6A0	nop
800AE6A4	lw     v0, $08e4(v0)
800AE6A8	nop
800AE6AC	lw     v0, $000c(v0)
800AE6B0	nop
800AE6B4	lw     v0, $0014(v0)
800AE6B8	nop
800AE6BC	lb     v0, $0042(v0)
800AE6C0	nop
800AE6C4	addiu  v0, v0, $fffa (=-$6)
800AE6C8	sltiu  v0, v0, $0002
800AE6CC	beq    v0, zero, Lae6fc [$800ae6fc]
800AE6D0	lui    v0, $800d
800AE6D4	lhu    v0, $9d44(v0)
800AE6D8	nop
800AE6DC	andi   v0, v0, $0002
800AE6E0	beq    v0, zero, Lae6fc [$800ae6fc]
800AE6E4	nop
800AE6E8	jal    func12ad4 [$80012ad4]
800AE6EC	nop
800AE6F0	andi   v1, v0, $0002
800AE6F4	bne    v1, zero, Lae700 [$800ae700]
800AE6F8	addiu  v0, zero, $0001

Lae6fc:	; 800AE6FC
800AE6FC	addu   v0, zero, zero

Lae700:	; 800AE700
800AE700	lw     ra, $0010(sp)
800AE704	nop
800AE708	jr     ra 

Lae70c:	; 800AE70C
800AE70C	addiu  sp, sp, $0018

800AE710	addiu  sp, sp, $ffe8 (=-$18)
800AE714	addu   a2, a1, zero
800AE718	andi   a1, a0, $ffff
800AE71C	sw     ra, $0010(sp)
800AE720	jal    funcad944 [$800ad944]
800AE724	addu   a0, zero, zero
800AE728	lw     ra, $0010(sp)
800AE72C	nop
800AE730	jr     ra 
800AE734	addiu  sp, sp, $0018

800AE738	addiu  sp, sp, $ffe8 (=-$18)
800AE73C	addiu  a0, zero, $0002
800AE740	addu   a1, zero, zero

funcae744:	; 800AE744
800AE744	sw     ra, $0010(sp)
800AE748	jal    funcad944 [$800ad944]
800AE74C	addu   a2, a1, zero

funcae750:	; 800AE750
800AE750	lw     ra, $0010(sp)
800AE754	nop
800AE758	jr     ra 
800AE75C	addiu  sp, sp, $0018

800AE760	addiu  sp, sp, $ffe8 (=-$18)

funcae764:	; 800AE764
800AE764	addiu  a0, zero, $0001
800AE768	addu   a1, zero, zero
800AE76C	sw     ra, $0010(sp)
800AE770	jal    funcad944 [$800ad944]
800AE774	addu   a2, a1, zero
800AE778	lw     ra, $0010(sp)
800AE77C	nop
800AE780	jr     ra 
800AE784	addiu  sp, sp, $0018


funcae788:	; 800AE788
800AE788	addiu  sp, sp, $ffe8 (=-$18)
800AE78C	sw     s0, $0010(sp)
800AE790	lui    s0, $8006
800AE794	lw     v0, $794c(s0)
800AE798	sw     ra, $0014(sp)
800AE79C	lw     v1, $001c(v0)
800AE7A0	nop
800AE7A4	lw     v0, $08e4(v1)
800AE7A8	nop
800AE7AC	lw     v0, $0000(v0)
800AE7B0	nop
800AE7B4	andi   v0, v0, $0200
800AE7B8	beq    v0, zero, Lae8fc [$800ae8fc]
800AE7BC	nop
800AE7C0	lbu    v0, $0008(v1)
800AE7C4	nop

funcae7c8:	; 800AE7C8
800AE7C8	sll    v0, v0, $02
800AE7CC	addu   v0, v1, v0
800AE7D0	lw     a0, $0010(v0)
800AE7D4	jal    func134c8 [$800134c8]
800AE7D8	addiu  a1, zero, $1000
800AE7DC	lw     v0, $794c(s0)
800AE7E0	nop
800AE7E4	lw     v0, $001c(v0)
800AE7E8	lui    a1, $800d
800AE7EC	lbu    v1, $0008(v0)
800AE7F0	addiu  a1, a1, $9f60 (=-$60a0)
800AE7F4	xori   v1, v1, $0001
800AE7F8	sll    v0, v1, $01
800AE7FC	addu   v0, v0, v1
800AE800	sll    v0, v0, $03
800AE804	addu   v0, v0, a1
800AE808	addiu  v1, zero, $0002
800AE80C	sb     v1, $0003(v0)
800AE810	lw     a2, $794c(s0)
800AE814	nop
800AE818	lw     v0, $001c(a2)
800AE81C	nop
800AE820	lbu    v1, $0008(v0)
800AE824	nop
800AE828	xori   v1, v1, $0001
800AE82C	sll    v0, v1, $01
800AE830	addu   v0, v0, v1
800AE834	sll    v0, v0, $03
800AE838	addu   v0, v0, a1
800AE83C	lui    v1, $e600
800AE840	sw     v1, $0004(v0)
800AE844	lw     v0, $001c(a2)
800AE848	nop
800AE84C	lbu    v1, $0008(v0)
800AE850	lui    a3, $00ff
800AE854	xori   v1, v1, $0001
800AE858	sll    v0, v1, $01
800AE85C	addu   v0, v0, v1
800AE860	sll    v0, v0, $03
800AE864	addu   v0, v0, a1
800AE868	sw     zero, $0008(v0)
800AE86C	lw     v1, $001c(a2)
800AE870	ori    a3, a3, $ffff
800AE874	lbu    v0, $0008(v1)
800AE878	lui    t0, $ff00
800AE87C	xori   v0, v0, $0001
800AE880	sll    a0, v0, $01
800AE884	addu   a0, a0, v0
800AE888	sll    a0, a0, $03
800AE88C	addu   a0, a0, a1
800AE890	sll    v0, v0, $02
800AE894	addu   v1, v1, v0
800AE898	lw     v0, $0010(v1)
800AE89C	lw     v1, $0000(a0)
800AE8A0	lw     v0, $3ffc(v0)
800AE8A4	and    v1, v1, t0
800AE8A8	and    v0, v0, a3
800AE8AC	or     v1, v1, v0
800AE8B0	sw     v1, $0000(a0)
800AE8B4	lw     v0, $001c(a2)
800AE8B8	nop
800AE8BC	lbu    a0, $0008(v0)
800AE8C0	nop
800AE8C4	xori   a0, a0, $0001
800AE8C8	sll    v1, a0, $02
800AE8CC	addu   v0, v0, v1
800AE8D0	lw     a2, $0010(v0)
800AE8D4	sll    v0, a0, $01
800AE8D8	addu   v0, v0, a0
800AE8DC	sll    v0, v0, $03
800AE8E0	addu   v0, v0, a1
800AE8E4	lw     v1, $3ffc(a2)
800AE8E8	and    v0, v0, a3
800AE8EC	and    v1, v1, t0
800AE8F0	or     v1, v1, v0
800AE8F4	j      Lae918 [$800ae918]
800AE8F8	sw     v1, $3ffc(a2)

Lae8fc:	; 800AE8FC
800AE8FC	lbu    v0, $0008(v1)
800AE900	nop
800AE904	sll    v0, v0, $02
800AE908	addu   v0, v1, v0
800AE90C	lw     a0, $0010(v0)
800AE910	jal    func13590 [$80013590]
800AE914	addiu  a1, zero, $1000

Lae918:	; 800AE918
800AE918	jal    func4c204 [$8004c204]
800AE91C	nop
800AE920	lw     ra, $0014(sp)
800AE924	lw     s0, $0010(sp)
800AE928	jr     ra 
800AE92C	addiu  sp, sp, $0018


funcae930:	; 800AE930
800AE930	addiu  sp, sp, $ffe0 (=-$20)
800AE934	lui    v1, $8007
800AE938	lw     v0, $39a0(v1)
800AE93C	addiu  v1, v1, $39a0
800AE940	addiu  a0, zero, $0f09
800AE944	sw     ra, $0018(sp)
800AE948	sw     s1, $0014(sp)
800AE94C	andi   v0, v0, $0f09
800AE950	beq    v0, a0, Lae96c [$800ae96c]
800AE954	sw     s0, $0010(sp)
800AE958	lw     v0, $0004(v1)
800AE95C	nop
800AE960	and    v0, v0, a0
800AE964	bne    v0, a0, Lae988 [$800ae988]
800AE968	nop

Lae96c:	; 800AE96C
800AE96C	lui    v0, $8006
800AE970	lw     v1, $794c(v0)
800AE974	nop
800AE978	lw     v0, $0000(v1)
800AE97C	nop
800AE980	ori    v0, v0, $0001
800AE984	sw     v0, $0000(v1)

Lae988:	; 800AE988
800AE988	jal    func130a4 [$800130a4]
800AE98C	addu   a0, zero, zero
800AE990	jal    func12ad4 [$80012ad4]
800AE994	nop
800AE998	andi   v0, v0, $0002
800AE99C	bne    v0, zero, Laea00 [$800aea00]
800AE9A0	lui    s1, $8006
800AE9A4	lui    v0, $8006

Lae9a8:	; 800AE9A8
800AE9A8	lw     a1, $794c(v0)
800AE9AC	nop
800AE9B0	lw     a0, $001c(a1)
800AE9B4	nop
800AE9B8	lw     v0, $0000(a0)
800AE9BC	addiu  v1, zero, $001c
800AE9C0	andi   v0, v0, $001c
800AE9C4	bne    v0, v1, Lae9f0 [$800ae9f0]

funcae9c8:	; 800AE9C8
800AE9C8	lui    v0, $8006
800AE9CC	lw     v0, $08e4(a0)
800AE9D0	nop
800AE9D4	lw     v0, $0000(v0)
800AE9D8	nop
800AE9DC	andi   v0, v0, $0004
800AE9E0	beq    v0, zero, Lae9f0 [$800ae9f0]
800AE9E4	lui    v0, $8006
800AE9E8	j      Laea00 [$800aea00]
800AE9EC	sb     zero, $0009(a1)

Lae9f0:	; 800AE9F0
800AE9F0	lw     v1, $794c(v0)
800AE9F4	addiu  v0, zero, $0002
800AE9F8	sb     v0, $0009(v1)
800AE9FC	lui    s1, $8006

Laea00:	; 800AEA00
800AEA00	lw     v0, $794c(s1)
800AEA04	nop
800AEA08	lbu    a0, $0009(v0)
800AEA0C	jal    func15c58 [$80015c58]
800AEA10	lui    s0, $800d
800AEA14	jal    func12d28 [$80012d28]
800AEA18	addiu  a0, zero, $0001
800AEA1C	lhu    v0, $9d44(s0)
800AEA20	nop
800AEA24	andi   v0, v0, $0008
800AEA28	beq    v0, zero, Laea58 [$800aea58]
800AEA2C	nop
800AEA30	jal    func12d08 [$80012d08]
800AEA34	nop
800AEA38	jal    func12cf8 [$80012cf8]
800AEA3C	nop
800AEA40	jal    func12d18 [$80012d18]
800AEA44	nop

funcaea48:	; 800AEA48
800AEA48	lhu    v0, $9d44(s0)
800AEA4C	nop
800AEA50	andi   v0, v0, $fff7
800AEA54	sh     v0, $9d44(s0)

Laea58:	; 800AEA58
800AEA58	lw     a1, $794c(s1)
800AEA5C	nop
800AEA60	lw     v1, $001c(a1)
800AEA64	nop
800AEA68	lw     v0, $08e4(v1)
800AEA6C	nop
800AEA70	lw     v0, $0000(v0)
800AEA74	nop
800AEA78	andi   v0, v0, $0020
800AEA7C	bne    v0, zero, Laeaa4 [$800aeaa4]
800AEA80	nop
800AEA84	lbu    v0, $0008(v1)
800AEA88	nop
800AEA8C	sll    a0, v0, $02
800AEA90	addu   a0, a0, v0
800AEA94	lw     v0, $000c(a1)
800AEA98	sll    a0, a0, $02
800AEA9C	jal    func138d4 [$800138d4]
800AEAA0	addu   a0, v0, a0

Laeaa4:	; 800AEAA4
800AEAA4	lw     a2, $794c(s1)
800AEAA8	nop
800AEAAC	lw     a0, $001c(a2)

Laeab0:	; 800AEAB0
800AEAB0	nop
800AEAB4	lw     v0, $0000(a0)
800AEAB8	nop
800AEABC	andi   v0, v0, $0100
800AEAC0	bne    v0, zero, Laeb80 [$800aeb80]
800AEAC4	lui    s0, $8006
800AEAC8	lw     v0, $08e4(a0)
800AEACC	nop
800AEAD0	lw     v1, $0000(v0)
800AEAD4	nop
800AEAD8	andi   v0, v1, $0040
800AEADC	bne    v0, zero, Laeb80 [$800aeb80]
800AEAE0	andi   v0, v1, $0400
800AEAE4	beq    v0, zero, Laeb1c [$800aeb1c]
800AEAE8	andi   v0, v1, $0004
800AEAEC	lbu    v0, $0008(a0)
800AEAF0	nop
800AEAF4	sll    a0, v0, $01
800AEAF8	addu   a0, a0, v0
800AEAFC	sll    a0, a0, $03
800AEB00	subu   a0, a0, v0
800AEB04	lw     v0, $0010(a2)
800AEB08	sll    a0, a0, $02
800AEB0C	jal    func13708 [$80013708]
800AEB10	addu   a0, v0, a0
800AEB14	j      Laeb80 [$800aeb80]
800AEB18	lui    s0, $8006

Laeb1c:	; 800AEB1C
800AEB1C	beq    v0, zero, Laeb64 [$800aeb64]
800AEB20	lui    s0, $8006
800AEB24	lbu    v1, $0008(a0)
800AEB28	nop
800AEB2C	sll    v0, v1, $02
800AEB30	addu   v0, a0, v0
800AEB34	sll    a1, v1, $01
800AEB38	addu   a1, a1, v1
800AEB3C	sll    a1, a1, $03
800AEB40	subu   a1, a1, v1
800AEB44	sll    a1, a1, $02
800AEB48	lw     a0, $0010(v0)
800AEB4C	lw     v0, $0010(a2)
800AEB50	addiu  a0, a0, $3ffc
800AEB54	jal    func137c8 [$800137c8]
800AEB58	addu   a1, v0, a1
800AEB5C	j      Laeb80 [$800aeb80]
800AEB60	lui    s0, $8006

Laeb64:	; 800AEB64
800AEB64	lbu    v0, $0008(a0)
800AEB68	nop
800AEB6C	sll    v0, v0, $02
800AEB70	addu   v0, a0, v0
800AEB74	lw     a0, $0010(v0)
800AEB78	jal    func13698 [$80013698]
800AEB7C	nop

Laeb80:	; 800AEB80
800AEB80	lw     v0, $794c(s0)
800AEB84	nop
800AEB88	lw     v1, $001c(v0)
800AEB8C	nop
800AEB90	lw     v0, $0000(v1)
800AEB94	nop
800AEB98	andi   v0, v0, $0020
800AEB9C	bne    v0, zero, Laebd0 [$800aebd0]
800AEBA0	nop
800AEBA4	lbu    v0, $0008(v1)
800AEBA8	nop
800AEBAC	xori   v0, v0, $0001
800AEBB0	sb     v0, $0008(v1)
800AEBB4	lw     v0, $794c(s0)
800AEBB8	nop
800AEBBC	lw     v0, $001c(v0)
800AEBC0	nop
800AEBC4	lbu    a0, $0008(v0)
800AEBC8	jal    func2c0dc [$8002c0dc]
800AEBCC	nop

Laebd0:	; 800AEBD0
800AEBD0	lw     a3, $794c(s0)
800AEBD4	nop
800AEBD8	lw     a1, $001c(a3)
800AEBDC	nop
800AEBE0	lw     v1, $0000(a1)
800AEBE4	nop
800AEBE8	andi   v0, v1, $0100
800AEBEC	bne    v0, zero, Laecf0 [$800aecf0]
800AEBF0	lui    a0, $800d
800AEBF4	addu   t0, zero, zero
800AEBF8	lhu    v0, $9ef0(a0)
800AEBFC	addiu  a0, a0, $9ef0 (=-$6110)
800AEC00	or     v0, v1, v0
800AEC04	sw     v0, $0000(a1)
800AEC08	lw     a1, $001c(a3)
800AEC0C	lhu    v0, $0008(a0)
800AEC10	lw     v1, $0000(a1)
800AEC14	nor    v0, zero, v0
800AEC18	and    v1, v1, v0
800AEC1C	sw     v1, $0000(a1)
800AEC20	lw     v0, $001c(a3)
800AEC24	addu   a2, a0, zero
800AEC28	lw     a0, $08e4(v0)
800AEC2C	lhu    v1, $0010(a2)
800AEC30	lw     v0, $0000(a0)
800AEC34	addu   t1, a2, zero
800AEC38	or     v0, v0, v1
800AEC3C	sw     v0, $0000(a0)
800AEC40	lw     v0, $001c(a3)
800AEC44	addu   a3, t0, zero
800AEC48	lw     a0, $08e4(v0)
800AEC4C	lhu    v0, $0018(a2)
800AEC50	lw     v1, $0000(a0)
800AEC54	nor    v0, zero, v0
800AEC58	and    v1, v1, v0
800AEC5C	sw     v1, $0000(a0)
800AEC60	lui    a0, $800d
800AEC64	lhu    v0, $9d44(a0)
800AEC68	lhu    a1, $0020(a2)
800AEC6C	lhu    v1, $0028(a2)
800AEC70	or     v0, v0, a1
800AEC74	nor    v1, zero, v1
800AEC78	sh     v0, $9d44(a0)
800AEC7C	and    v0, v0, v1
800AEC80	sh     v0, $9d44(a0)

loopaec84:	; 800AEC84
800AEC84	addu   a1, zero, zero

loopaec88:	; 800AEC88
800AEC88	sll    a0, a1, $01
800AEC8C	addu   a0, a0, a3
800AEC90	addiu  a1, a1, $0001
800AEC94	sll    v0, a1, $01
800AEC98	addu   v0, v0, a3
800AEC9C	addu   v0, v0, t1
800AECA0	lhu    v1, $0000(v0)
800AECA4	addu   a0, a0, t1
800AECA8	sh     v1, $0000(a0)
800AECAC	lhu    v1, $0010(v0)
800AECB0	nop
800AECB4	sh     v1, $0010(a0)
800AECB8	lhu    v0, $0020(v0)
800AECBC	nop
800AECC0	sh     v0, $0020(a0)
800AECC4	slti   v0, a1, $0003
800AECC8	bne    v0, zero, loopaec88 [$800aec88]
800AECCC	nop
800AECD0	sh     zero, $0006(a2)
800AECD4	sh     zero, $0016(a2)
800AECD8	sh     zero, $0026(a2)
800AECDC	addiu  a2, a2, $0008
800AECE0	addiu  t0, t0, $0001
800AECE4	slti   v0, t0, $0002
800AECE8	bne    v0, zero, loopaec84 [$800aec84]
800AECEC	addiu  a3, a3, $0008

Laecf0:	; 800AECF0
800AECF0	lw     ra, $0018(sp)
800AECF4	lw     s1, $0014(sp)
800AECF8	lw     s0, $0010(sp)
800AECFC	jr     ra 
800AED00	addiu  sp, sp, $0020


funcaed04:	; 800AED04
800AED04	lui    v0, $8006
800AED08	lw     v0, $794c(v0)
800AED0C	nop
800AED10	lw     v0, $001c(v0)
800AED14	nop
800AED18	lw     v0, $08e4(v0)
800AED1C	nop
800AED20	lw     v0, $000c(v0)
800AED24	lui    a0, $800d
800AED28	lw     v0, $0014(v0)
800AED2C	addiu  v1, a0, $9ef0 (=-$6110)
800AED30	sb     zero, $0041(v0)
800AED34	addiu  v0, zero, $0004
800AED38	sh     v0, $001e(v1)
800AED3C	addiu  v0, zero, $0043
800AED40	sh     v0, $9ef0(a0)
800AED44	addiu  v0, zero, $003c
800AED48	sh     v0, $0004(v1)
800AED4C	addiu  v0, zero, $1919
800AED50	lui    a0, $8007
800AED54	sh     v0, $0014(v1)
800AED58	lw     v0, $3998(a0)
800AED5C	lui    v1, $0400
800AED60	or     v0, v0, v1
800AED64	jr     ra 
800AED68	sw     v0, $3998(a0)


funcaed6c:	; 800AED6C
800AED6C	addiu  sp, sp, $ffc0 (=-$40)
800AED70	sw     s3, $0034(sp)
800AED74	lui    s3, $8006
800AED78	lw     v0, $794c(s3)
800AED7C	sw     ra, $0038(sp)
800AED80	sw     s2, $0030(sp)
800AED84	sw     s1, $002c(sp)
800AED88	sw     s0, $0028(sp)
800AED8C	lw     v0, $001c(v0)
800AED90	nop
800AED94	lw     v0, $08e4(v0)
800AED98	nop
800AED9C	lw     v0, $000c(v0)
800AEDA0	nop
800AEDA4	lw     v1, $0014(v0)
800AEDA8	nop
800AEDAC	lb     v0, $0041(v1)
800AEDB0	nop
800AEDB4	bne    v0, zero, Laf104 [$800af104]
800AEDB8	lui    a0, $0015
800AEDBC	ori    a0, a0, $3f00
800AEDC0	lui    v0, $8008
800AEDC4	sw     zero, $bd28(v0)
800AEDC8	lui    v0, $8006
800AEDCC	lw     v0, $7944(v0)
800AEDD0	lui    v1, $8008
800AEDD4	addu   v0, v0, a0
800AEDD8	jal    funcac5f0 [$800ac5f0]
800AEDDC	sw     v0, $bd30(v1)
800AEDE0	lw     v0, $794c(s3)
800AEDE4	nop
800AEDE8	lw     v0, $001c(v0)
800AEDEC	nop
800AEDF0	lw     v0, $08e4(v0)
800AEDF4	nop
800AEDF8	lw     v0, $000c(v0)
800AEDFC	lui    v1, $8006
800AEE00	lw     a0, $0014(v0)
800AEE04	lw     v0, $7948(v1)
800AEE08	jal    func4ae00 [$8004ae00]
800AEE0C	sw     v0, $0020(a0)
800AEE10	addu   s0, v0, zero
800AEE14	beq    s0, zero, Laef7c [$800aef7c]
800AEE18	nop
800AEE1C	jal    funcc0f08 [$800c0f08]
800AEE20	nop
800AEE24	lhu    v0, $0014(s0)
800AEE28	lw     v1, $794c(s3)
800AEE2C	sh     v0, $0018(sp)
800AEE30	lhu    v0, $0018(s0)
800AEE34	nop
800AEE38	sh     v0, $001a(sp)
800AEE3C	lhu    v0, $001c(s0)
800AEE40	nop
800AEE44	sh     v0, $001c(sp)
800AEE48	lw     v1, $001c(v1)
800AEE4C	nop
800AEE50	addiu  v0, v1, $0018
800AEE54	lw     t4, $0000(v0)
800AEE58	lw     t5, $0004(v0)
800AEE5C	ctc2   t4,vxy0
800AEE60	ctc2   t5,vz0
800AEE64	lw     t4, $0008(v0)

funcaee68:	; 800AEE68
800AEE68	lw     t5, $000c(v0)
800AEE6C	lw     t6, $0010(v0)
800AEE70	ctc2   t4,vxy1
800AEE74	ctc2   t5,vz1
800AEE78	ctc2   t6,vxy2
800AEE7C	lw     t4, $0014(v0)
800AEE80	lw     t5, $0018(v0)
800AEE84	ctc2   t4,vz2
800AEE88	lw     t6, $001c(v0)
800AEE8C	ctc2   t5,rgb
800AEE90	ctc2   t6,otz
800AEE94	addiu  v0, sp, $0018
800AEE98	lwc2   zero, $0000(v0)
800AEE9C	lwc2   at, $0004(v0)
800AEEA0	nop
800AEEA4	nop
800AEEA8	gte_func16t8,r11r12
800AEEAC	lw     v0, $08e4(v1)
800AEEB0	nop
800AEEB4	lw     v0, $000c(v0)
800AEEB8	nop
800AEEBC	lw     v0, $0014(v0)
800AEEC0	nop
800AEEC4	addiu  v0, v0, $0038
800AEEC8	swc2   t6, $0000(v0)
800AEECC	lw     v0, $794c(s3)
800AEED0	nop
800AEED4	lw     v0, $001c(v0)
800AEED8	nop
800AEEDC	lw     v0, $08e4(v0)
800AEEE0	nop
800AEEE4	lw     v0, $000c(v0)
800AEEE8	nop
800AEEEC	lw     v1, $0014(v0)
800AEEF0	nop
800AEEF4	lhu    v0, $0038(v1)
800AEEF8	nop
800AEEFC	sltiu  v0, v0, $0140
800AEF00	beq    v0, zero, Laef24 [$800aef24]
800AEF04	lui    v0, $8006
800AEF08	lh     v0, $003a(v1)
800AEF0C	nop
800AEF10	bltz   v0, Laef20 [$800aef20]
800AEF14	slti   v0, v0, $00e0
800AEF18	bne    v0, zero, Laef74 [$800aef74]
800AEF1C	nop

Laef20:	; 800AEF20
800AEF20	lui    v0, $8006

Laef24:	; 800AEF24
800AEF24	lw     a0, $794c(v0)
800AEF28	nop
800AEF2C	lw     v0, $001c(a0)
800AEF30	nop
800AEF34	lw     v0, $08e4(v0)
800AEF38	nop
800AEF3C	lw     v0, $000c(v0)
800AEF40	nop
800AEF44	lw     v1, $0014(v0)
800AEF48	addiu  v0, zero, $00a0
800AEF4C	sh     v0, $0038(v1)
800AEF50	lw     v0, $001c(a0)
800AEF54	nop
800AEF58	lw     v0, $08e4(v0)
800AEF5C	nop
800AEF60	lw     v0, $000c(v0)
800AEF64	nop
800AEF68	lw     v1, $0014(v0)
800AEF6C	addiu  v0, zero, $0070
800AEF70	sh     v0, $003a(v1)

Laef74:	; 800AEF74
800AEF74	jal    funcc0fb0 [$800c0fb0]
800AEF78	nop

Laef7c:	; 800AEF7C
800AEF7C	jal    funcb238c [$800b238c]
800AEF80	lui    s0, $8006
800AEF84	lw     v0, $794c(s0)
800AEF88	nop
800AEF8C	lw     a0, $001c(v0)
800AEF90	nop
800AEF94	lw     v0, $08e4(a0)
800AEF98	nop
800AEF9C	lw     v0, $000c(v0)
800AEFA0	nop
800AEFA4	lw     v0, $0014(v0)
800AEFA8	lhu    v1, $081c(a0)
800AEFAC	lhu    v0, $003c(v0)
800AEFB0	nop
800AEFB4	beq    v1, v0, Laf008 [$800af008]
800AEFB8	lui    v1, $2000
800AEFBC	lw     v0, $0000(a0)
800AEFC0	nop
800AEFC4	and    v0, v0, v1
800AEFC8	beq    v0, zero, Laf008 [$800af008]
800AEFCC	addu   a0, zero, zero
800AEFD0	addiu  a1, zero, $000f
800AEFD4	jal    func559fc [$800559fc]
800AEFD8	addu   a2, a0, zero
800AEFDC	lw     v0, $794c(s0)
800AEFE0	nop
800AEFE4	lw     v0, $001c(v0)
800AEFE8	nop
800AEFEC	lw     v0, $08e4(v0)
800AEFF0	nop
800AEFF4	lw     v0, $000c(v0)
800AEFF8	nop
800AEFFC	lw     v1, $0014(v0)
800AF000	addiu  v0, zero, $0007
800AF004	sb     v0, $0009(v1)

Laf008:	; 800AF008
800AF008	lui    v0, $8006
800AF00C	lw     v0, $794c(v0)
800AF010	nop
800AF014	lw     a0, $001c(v0)
800AF018	nop
800AF01C	lhu    v1, $0830(a0)
800AF020	ori    v0, zero, $ffff
800AF024	beq    v1, v0, Laf050 [$800af050]
800AF028	lui    v1, $0200
800AF02C	lw     v0, $0000(a0)
800AF030	nop
800AF034	and    v0, v0, v1
800AF038	beq    v0, zero, Laf050 [$800af050]
800AF03C	lui    a1, $0010
800AF040	lw     a0, $0828(a0)
800AF044	addiu  a2, zero, $000f
800AF048	jal    func557a8 [$800557a8]
800AF04C	addu   a3, zero, zero

Laf050:	; 800AF050
800AF050	lui    v0, $8006
800AF054	lw     v0, $794c(v0)
800AF058	nop
800AF05C	lw     a0, $001c(v0)
800AF060	nop
800AF064	lhu    v1, $0832(a0)
800AF068	ori    v0, zero, $ffff
800AF06C	beq    v1, v0, Laf098 [$800af098]
800AF070	lui    v1, $0800
800AF074	lw     v0, $0000(a0)
800AF078	nop
800AF07C	and    v0, v0, v1
800AF080	beq    v0, zero, Laf098 [$800af098]
800AF084	lui    a1, $0020
800AF088	lw     a0, $082c(a0)
800AF08C	addiu  a2, zero, $000f
800AF090	jal    func557a8 [$800557a8]
800AF094	addu   a3, zero, zero

Laf098:	; 800AF098
800AF098	addiu  v1, zero, $0001
800AF09C	lui    v0, $8007
800AF0A0	addiu  v0, v0, $39b0
800AF0A4	addiu  v0, v0, $0002

loopaf0a8:	; 800AF0A8
800AF0A8	sb     zero, $0001(v0)
800AF0AC	sb     zero, $0000(v0)
800AF0B0	addiu  v1, v1, $ffff (=-$1)
800AF0B4	bgez   v1, loopaf0a8 [$800af0a8]
800AF0B8	addiu  v0, v0, $fffe (=-$2)
800AF0BC	jal    func56228 [$80056228]
800AF0C0	nop
800AF0C4	lui    v0, $8006
800AF0C8	lw     v0, $794c(v0)
800AF0CC	nop
800AF0D0	lw     v0, $001c(v0)
800AF0D4	nop
800AF0D8	lw     v0, $08e4(v0)
800AF0DC	nop
800AF0E0	lw     v0, $000c(v0)
800AF0E4	nop
800AF0E8	lw     v1, $0014(v0)
800AF0EC	nop
800AF0F0	lbu    v0, $0041(v1)
800AF0F4	nop
800AF0F8	addiu  v0, v0, $0001
800AF0FC	j      Laf680 [$800af680]
800AF100	sb     v0, $0041(v1)

Laf104:	; 800AF104
800AF104	lw     v0, $0000(v1)
800AF108	nop
800AF10C	andi   v0, v0, $0002
800AF110	bne    v0, zero, Laf3c4 [$800af3c4]
800AF114	lui    s0, $8006
800AF118	lui    a0, $0001
800AF11C	jal    func220e8 [$800220e8]
800AF120	ori    a0, a0, $000b
800AF124	beq    v0, zero, Laf310 [$800af310]
800AF128	lui    a0, $0001
800AF12C	jal    func21e5c [$80021e5c]
800AF130	ori    a0, a0, $000b
800AF134	lui    s0, $800d
800AF138	addiu  s1, s0, $9f98 (=-$6068)
800AF13C	addu   a0, s1, zero
800AF140	addiu  a1, zero, $0001
800AF144	jal    func134c8 [$800134c8]
800AF148	addu   s2, v0, zero
800AF14C	lw     v0, $794c(s3)
800AF150	nop
800AF154	lw     v0, $001c(v0)
800AF158	lui    a2, $800d
800AF15C	lbu    v1, $0008(v0)
800AF160	addiu  a2, a2, $9f60 (=-$60a0)
800AF164	xori   v1, v1, $0001
800AF168	sll    v0, v1, $01
800AF16C	addu   v0, v0, v1
800AF170	sll    v0, v0, $03
800AF174	addu   v0, v0, a2
800AF178	addiu  v1, zero, $0002
800AF17C	sb     v1, $0003(v0)
800AF180	lw     t0, $794c(s3)
800AF184	nop
800AF188	lw     v0, $001c(t0)
800AF18C	nop
800AF190	lbu    v1, $0008(v0)
800AF194	nop
800AF198	xori   v1, v1, $0001
800AF19C	sll    v0, v1, $01
800AF1A0	addu   v0, v0, v1
800AF1A4	sll    v0, v0, $03
800AF1A8	addu   v0, v0, a2
800AF1AC	lui    v1, $e600
800AF1B0	sw     v1, $0004(v0)
800AF1B4	lw     v0, $001c(t0)
800AF1B8	lui    t1, $00ff
800AF1BC	lbu    v1, $0008(v0)
800AF1C0	ori    t1, t1, $ffff
800AF1C4	xori   v1, v1, $0001
800AF1C8	sll    v0, v1, $01
800AF1CC	addu   v0, v0, v1

funcaf1d0:	; 800AF1D0
800AF1D0	sll    v0, v0, $03
800AF1D4	addu   v0, v0, a2
800AF1D8	sw     zero, $0008(v0)
800AF1DC	lw     v0, $001c(t0)
800AF1E0	addu   a0, s1, zero
800AF1E4	lbu    v1, $0008(v0)
800AF1E8	lui    a3, $ff00
800AF1EC	sll    v0, v1, $01
800AF1F0	addu   v0, v0, v1
800AF1F4	sll    v0, v0, $03
800AF1F8	addu   v0, v0, a2
800AF1FC	lw     a1, $0000(v0)
800AF200	lw     v1, $9f98(s0)
800AF204	and    a1, a1, a3
800AF208	and    v1, v1, t1
800AF20C	or     a1, a1, v1
800AF210	sw     a1, $0000(v0)
800AF214	lw     v0, $001c(t0)
800AF218	lw     v1, $9f98(s0)
800AF21C	lbu    a1, $0008(v0)
800AF220	and    v1, v1, a3
800AF224	sll    v0, a1, $01
800AF228	addu   v0, v0, a1
800AF22C	sll    v0, v0, $03
800AF230	addu   v0, v0, a2
800AF234	and    v0, v0, t1
800AF238	or     v1, v1, v0
800AF23C	jal    func13698 [$80013698]
800AF240	sw     v1, $9f98(s0)
800AF244	addiu  v0, zero, $0100
800AF248	sh     zero, $0020(sp)
800AF24C	sh     v0, $0022(sp)
800AF250	sh     v0, $0026(sp)
800AF254	lw     v0, $000c(s2)
800AF258	addiu  v1, zero, $0100
800AF25C	div    v0, v1
800AF260	bne    v1, zero, Laf26c [$800af26c]
800AF264	nop
800AF268	break   $01c00

Laf26c:	; 800AF26C
800AF26C	addiu  at, zero, $ffff (=-$1)
800AF270	bne    v1, at, Laf284 [$800af284]
800AF274	lui    at, $8000
800AF278	bne    v0, at, Laf284 [$800af284]
800AF27C	nop
800AF280	break   $01800

Laf284:	; 800AF284
800AF284	mflo   v0
800AF288	nop
800AF28C	srl    a0, v0, $01
800AF290	sh     a0, $0024(sp)
800AF294	lw     v0, $000c(s2)
800AF298	nop
800AF29C	div    v0, v1
800AF2A0	bne    v1, zero, Laf2ac [$800af2ac]
800AF2A4	nop
800AF2A8	break   $01c00

Laf2ac:	; 800AF2AC
800AF2AC	addiu  at, zero, $ffff (=-$1)
800AF2B0	bne    v1, at, Laf2c4 [$800af2c4]
800AF2B4	lui    at, $8000
800AF2B8	bne    v0, at, Laf2c4 [$800af2c4]
800AF2BC	nop
800AF2C0	break   $01800

Laf2c4:	; 800AF2C4
800AF2C4	mfhi   v1
800AF2C8	nop
800AF2CC	beq    v1, zero, Laf2d8 [$800af2d8]
800AF2D0	addiu  v0, a0, $0001
800AF2D4	sh     v0, $0024(sp)

Laf2d8:	; 800AF2D8
800AF2D8	lw     a1, $0008(s2)
800AF2DC	jal    func13350 [$80013350]

funcaf2e0:	; 800AF2E0
800AF2E0	addiu  a0, sp, $0020
800AF2E4	jal    func130a4 [$800130a4]
800AF2E8	addu   a0, zero, zero
800AF2EC	lh     a1, $0020(sp)
800AF2F0	lh     a2, $0022(sp)
800AF2F4	lh     a3, $0024(sp)
800AF2F8	lh     v0, $0026(sp)
800AF2FC	addu   a0, s2, zero
800AF300	jal    func219d8 [$800219d8]
800AF304	sw     v0, $0010(sp)
800AF308	j      Laf328 [$800af328]
800AF30C	lui    a1, $0015

Laf310:	; 800AF310
800AF310	jal    func2208c [$8002208c]
800AF314	nop
800AF318	lw     a0, $0004(v0)
800AF31C	jal    func22390 [$80022390]
800AF320	nop
800AF324	lui    a1, $0015

Laf328:	; 800AF328
800AF328	lui    v0, $8006
800AF32C	lw     a0, $7944(v0)
800AF330	jal    func22280 [$80022280]
800AF334	ori    a1, a1, $6f00
800AF338	ori    a0, zero, $d000
800AF33C	addiu  a1, zero, $027c
800AF340	addu   a2, zero, zero
800AF344	addiu  a3, zero, $0080
800AF348	addiu  s0, zero, $007f
800AF34C	jal    funcb0124 [$800b0124]
800AF350	sw     s0, $0010(sp)
800AF354	ori    a0, zero, $d000
800AF358	addiu  a1, zero, $027b
800AF35C	addu   a2, zero, zero
800AF360	addiu  a3, zero, $0080
800AF364	jal    funcb0124 [$800b0124]
800AF368	sw     s0, $0010(sp)
800AF36C	ori    a0, zero, $d000
800AF370	addiu  a1, zero, $027a
800AF374	addu   a2, zero, zero
800AF378	addiu  a3, zero, $0080
800AF37C	jal    funcb0124 [$800b0124]
800AF380	sw     s0, $0010(sp)
800AF384	lui    v0, $8006
800AF388	lw     v0, $794c(v0)
800AF38C	nop
800AF390	lw     v0, $001c(v0)
800AF394	nop
800AF398	lw     v0, $08e4(v0)
800AF39C	nop
800AF3A0	lw     v0, $000c(v0)
800AF3A4	nop
800AF3A8	lw     v1, $0014(v0)
800AF3AC	nop
800AF3B0	lw     v0, $0000(v1)
800AF3B4	nop
800AF3B8	ori    v0, v0, $0002
800AF3BC	sw     v0, $0000(v1)
800AF3C0	lui    s0, $8006

Laf3c4:	; 800AF3C4
800AF3C4	lw     v0, $794c(s0)
800AF3C8	nop
800AF3CC	lw     v0, $001c(v0)
800AF3D0	nop
800AF3D4	lw     v0, $08e4(v0)
800AF3D8	nop
800AF3DC	lw     v0, $000c(v0)
800AF3E0	nop
800AF3E4	lw     v1, $0014(v0)
800AF3E8	nop
800AF3EC	lw     v0, $0000(v1)

Laf3f0:	; 800AF3F0
800AF3F0	nop
800AF3F4	andi   v0, v0, $0001
800AF3F8	bne    v0, zero, Laf454 [$800af454]
800AF3FC	nop
800AF400	lh     a0, $0038(v1)
800AF404	lh     a1, $003a(v1)
800AF408	jal    func53a10 [$80053a10]
800AF40C	nop
800AF410	andi   v0, v0, $00ff
800AF414	beq    v0, zero, Laf454 [$800af454]
800AF418	nop
800AF41C	lw     v0, $794c(s0)
800AF420	nop
800AF424	lw     v0, $001c(v0)
800AF428	nop
800AF42C	lw     v0, $08e4(v0)
800AF430	nop
800AF434	lw     v0, $000c(v0)
800AF438	nop
800AF43C	lw     v1, $0014(v0)
800AF440	nop
800AF444	lw     v0, $0000(v1)
800AF448	nop
800AF44C	ori    v0, v0, $0001
800AF450	sw     v0, $0000(v1)

Laf454:	; 800AF454
800AF454	lui    s0, $8006
800AF458	lw     v0, $794c(s0)
800AF45C	nop
800AF460	lw     a1, $001c(v0)
800AF464	nop
800AF468	lw     v0, $08e4(a1)
800AF46C	nop
800AF470	lw     v0, $000c(v0)
800AF474	nop
800AF478	lw     a0, $0014(v0)
800AF47C	nop
800AF480	lb     v1, $0009(a0)
800AF484	lbu    v0, $0009(a0)
800AF488	blez   v1, Laf498 [$800af498]
800AF48C	addiu  v0, v0, $ffff (=-$1)
800AF490	j      Laf680 [$800af680]
800AF494	sb     v0, $0009(a0)

Laf498:	; 800AF498
800AF498	bne    v1, zero, Laf57c [$800af57c]
800AF49C	addiu  v0, zero, $ffff (=-$1)
800AF4A0	lhu    v1, $003c(a0)
800AF4A4	ori    v0, zero, $ffff
800AF4A8	beq    v1, v0, Laf550 [$800af550]
800AF4AC	lui    v0, $8006
800AF4B0	lhu    v0, $081c(a1)
800AF4B4	nop
800AF4B8	beq    v1, v0, Laf54c [$800af54c]
800AF4BC	lui    v1, $2000
800AF4C0	lw     v0, $0000(a1)
800AF4C4	nop
800AF4C8	and    v0, v0, v1
800AF4CC	beq    v0, zero, Laf4e8 [$800af4e8]
800AF4D0	addiu  a0, zero, $0800
800AF4D4	addu   a2, zero, zero
800AF4D8	lhu    a1, $081c(a1)
800AF4DC	addu   a3, a2, zero
800AF4E0	jal    funcb0124 [$800b0124]
800AF4E4	sw     zero, $0010(sp)

Laf4e8:	; 800AF4E8
800AF4E8	lw     v0, $794c(s0)
800AF4EC	nop
800AF4F0	lw     v0, $001c(v0)
800AF4F4	nop
800AF4F8	lw     v0, $08e4(v0)
800AF4FC	nop
800AF500	lw     v0, $000c(v0)
800AF504	addiu  a0, zero, $0700
800AF508	lw     v0, $0014(v0)
800AF50C	addu   a2, zero, zero
800AF510	lhu    a1, $003c(v0)

Laf514:	; 800AF514
800AF514	addu   a3, a2, zero
800AF518	jal    funcb0124 [$800b0124]
800AF51C	sw     zero, $0010(sp)
800AF520	lw     v0, $794c(s0)
800AF524	nop
800AF528	lw     v0, $001c(v0)
800AF52C	nop
800AF530	lw     v0, $08e4(v0)
800AF534	nop
800AF538	lw     v0, $000c(v0)
800AF53C	nop
800AF540	lw     v1, $0014(v0)
800AF544	j      Laf67c [$800af67c]

Laf548:	; 800AF548
800AF548	addiu  v0, zero, $ffff (=-$1)

Laf54c:	; 800AF54C
800AF54C	lui    v0, $8006

Laf550:	; 800AF550
800AF550	lw     v0, $794c(v0)
800AF554	nop
800AF558	lw     v0, $001c(v0)
800AF55C	nop

Laf560:	; 800AF560
800AF560	lw     v0, $08e4(v0)
800AF564	nop
800AF568	lw     v0, $000c(v0)
800AF56C	nop
800AF570	lw     v1, $0014(v0)
800AF574	j      Laf67c [$800af67c]

funcaf578:	; 800AF578
800AF578	addiu  v0, zero, $fffe (=-$2)

Laf57c:	; 800AF57C
800AF57C	bne    v1, v0, Laf5cc [$800af5cc]
800AF580	addiu  a0, zero, $0c00
800AF584	sw     zero, $0010(sp)
800AF588	addu   a1, v0, zero
800AF58C	addu   a2, zero, zero
800AF590	jal    funcb0124 [$800b0124]
800AF594	addu   a3, a2, zero
800AF598	bne    v0, zero, Laf680 [$800af680]
800AF59C	nop
800AF5A0	lw     v0, $794c(s0)
800AF5A4	nop
800AF5A8	lw     v0, $001c(v0)
800AF5AC	nop
800AF5B0	lw     v0, $08e4(v0)
800AF5B4	nop
800AF5B8	lw     v0, $000c(v0)
800AF5BC	nop
800AF5C0	lw     v1, $0014(v0)
800AF5C4	j      Laf67c [$800af67c]
800AF5C8	addiu  v0, zero, $fffe (=-$2)

Laf5cc:	; 800AF5CC
800AF5CC	addiu  v0, zero, $fffe (=-$2)
800AF5D0	bne    v1, v0, Laf684 [$800af684]
800AF5D4	lui    v0, $8006
800AF5D8	jal    funcb1c4c [$800b1c4c]
800AF5DC	nop
800AF5E0	lw     v0, $794c(s0)
800AF5E4	nop
800AF5E8	lw     a0, $001c(v0)
800AF5EC	nop
800AF5F0	lw     v0, $08e4(a0)
800AF5F4	nop
800AF5F8	lw     v0, $000c(v0)
800AF5FC	nop
800AF600	lw     a1, $0014(v0)
800AF604	nop
800AF608	lhu    v1, $003c(a1)
800AF60C	ori    v0, zero, $ffff
800AF610	beq    v1, v0, Laf650 [$800af650]
800AF614	lui    v1, $2000
800AF618	lw     v0, $0000(a0)
800AF61C	nop
800AF620	and    v0, v0, v1
800AF624	bne    v0, zero, Laf654 [$800af654]
800AF628	lui    v0, $8006
800AF62C	addu   a0, zero, zero
800AF630	addu   a2, a0, zero
800AF634	lhu    a1, $003c(a1)
800AF638	addu   a3, a0, zero
800AF63C	jal    funcb0124 [$800b0124]
800AF640	sw     zero, $0010(sp)
800AF644	addu   a0, zero, zero
800AF648	jal    func559c8 [$800559c8]
800AF64C	addiu  a1, zero, $007f

Laf650:	; 800AF650
800AF650	lui    v0, $8006

Laf654:	; 800AF654
800AF654	lw     v0, $794c(v0)
800AF658	nop
800AF65C	lw     v0, $001c(v0)
800AF660	nop
800AF664	lw     v0, $08e4(v0)
800AF668	nop
800AF66C	lw     v0, $000c(v0)
800AF670	nop
800AF674	lw     v1, $0014(v0)
800AF678	addiu  v0, zero, $fffd (=-$3)

Laf67c:	; 800AF67C
800AF67C	sb     v0, $0009(v1)

Laf680:	; 800AF680
800AF680	lui    v0, $8006

Laf684:	; 800AF684
800AF684	lw     a2, $794c(v0)
800AF688	nop
800AF68C	lw     a0, $001c(a2)
800AF690	nop
800AF694	lw     v0, $08e4(a0)
800AF698	nop
800AF69C	lw     v0, $000c(v0)
800AF6A0	nop
800AF6A4	lw     v1, $0014(v0)
800AF6A8	nop
800AF6AC	lw     v0, $0000(v1)
800AF6B0	nop
800AF6B4	andi   v0, v0, $0001
800AF6B8	beq    v0, zero, Laf724 [$800af724]
800AF6BC	addiu  v0, zero, $fffd (=-$3)
800AF6C0	lb     v1, $0009(v1)
800AF6C4	nop
800AF6C8	bne    v1, v0, Laf724 [$800af724]
800AF6CC	addiu  v1, zero, $ff80 (=-$80)
800AF6D0	lw     v0, $0000(a0)
800AF6D4	nop
800AF6D8	and    v0, v0, v1
800AF6DC	sw     v0, $0000(a0)
800AF6E0	lw     v0, $001c(a2)
800AF6E4	nop
800AF6E8	lw     a0, $08e4(v0)
800AF6EC	lui    a1, $fbff
800AF6F0	lw     v0, $0000(a0)
800AF6F4	addiu  v1, zero, $e6e6 (=-$191a)
800AF6F8	and    v0, v0, v1
800AF6FC	lui    v1, $8007
800AF700	sw     v0, $0000(a0)
800AF704	lw     v0, $3998(v1)
800AF708	ori    a1, a1, $ffff
800AF70C	and    v0, v0, a1
800AF710	sw     v0, $3998(v1)
800AF714	lw     v0, $0000(a2)
800AF718	nop
800AF71C	ori    v0, v0, $0002
800AF720	sw     v0, $0000(a2)

Laf724:	; 800AF724
800AF724	lw     ra, $0038(sp)
800AF728	lw     s3, $0034(sp)
800AF72C	lw     s2, $0030(sp)
800AF730	lw     s1, $002c(sp)
800AF734	lw     s0, $0028(sp)
800AF738	jr     ra 
800AF73C	addiu  sp, sp, $0040


funcaf740:	; 800AF740
800AF740	addiu  sp, sp, $ffb8 (=-$48)
800AF744	sw     s0, $0038(sp)
800AF748	lui    s0, $8006
800AF74C	lw     a0, $794c(s0)
800AF750	sw     ra, $0044(sp)
800AF754	sw     s2, $0040(sp)
800AF758	sw     s1, $003c(sp)
800AF75C	lw     v1, $001c(a0)
800AF760	nop
800AF764	lw     v0, $0000(v1)
800AF768	nop
800AF76C	xori   v0, v0, $0100
800AF770	sw     v0, $0000(v1)

Laf774:	; 800AF774
800AF774	lw     v0, $001c(a0)
800AF778	nop
800AF77C	lw     v0, $0000(v0)
800AF780	nop
800AF784	andi   v0, v0, $0100
800AF788	beq    v0, zero, Lafa78 [$800afa78]
800AF78C	nop
800AF790	jal    func5562c [$8005562c]
800AF794	addu   a0, zero, zero
800AF798	jal    func23f60 [$80023f60]
800AF79C	addiu  a0, zero, $0001
800AF7A0	addiu  v1, zero, $0001
800AF7A4	lui    v0, $8007
800AF7A8	addiu  v0, v0, $39b0
800AF7AC	addiu  v0, v0, $0002

loopaf7b0:	; 800AF7B0
800AF7B0	sb     zero, $0001(v0)
800AF7B4	sb     zero, $0000(v0)
800AF7B8	addiu  v1, v1, $ffff (=-$1)
800AF7BC	bgez   v1, loopaf7b0 [$800af7b0]
800AF7C0	addiu  v0, v0, $fffe (=-$2)
800AF7C4	lui    s0, $800d
800AF7C8	addiu  s0, s0, $9f98 (=-$6068)
800AF7CC	addu   a0, s0, zero
800AF7D0	jal    func134c8 [$800134c8]
800AF7D4	addiu  a1, zero, $0001
800AF7D8	addu   a2, s0, zero
800AF7DC	addiu  a3, zero, $00eb
800AF7E0	addu   s0, zero, zero
800AF7E4	addiu  v0, sp, $0030
800AF7E8	sw     v0, $0014(sp)
800AF7EC	lui    v0, $800d
800AF7F0	addiu  v0, v0, $9fa0 (=-$6060)
800AF7F4	lui    v1, $8007
800AF7F8	addiu  v1, v1, $86d0 (=-$7930)
800AF7FC	addiu  a0, zero, $0140

funcaf800:	; 800AF800
800AF800	sw     zero, $0010(sp)
800AF804	sw     v0, $0018(sp)
800AF808	lbu    v0, $075c(v1)
800AF80C	addiu  a1, zero, $00e0
800AF810	subu   a0, a0, v0
800AF814	srl    v0, a0, $1f
800AF818	addu   a0, a0, v0
800AF81C	lbu    v0, $075d(v1)
800AF820	sra    a0, a0, $01
800AF824	subu   a1, a1, v0
800AF828	srl    v0, a1, $1f
800AF82C	addu   a1, a1, v0
800AF830	jal    func27834 [$80027834]
800AF834	sra    a1, a1, $01
800AF838	jal    func2f800 [$8002f800]
800AF83C	nop
800AF840	andi   v0, v0, $00ff
800AF844	bne    v0, zero, Laf860 [$800af860]
800AF848	nop
800AF84C	jal    func2f810 [$8002f810]
800AF850	nop
800AF854	andi   v0, v0, $00ff
800AF858	beq    v0, zero, Laf864 [$800af864]
800AF85C	nop

Laf860:	; 800AF860
800AF860	addiu  s0, zero, $0001

Laf864:	; 800AF864
800AF864	jal    func2f864 [$8002f864]
800AF868	nop
800AF86C	beq    s0, zero, Laf994 [$800af994]
800AF870	lui    t3, $00ff
800AF874	bne    v0, zero, Laf998 [$800af998]
800AF878	ori    t3, t3, $ffff
800AF87C	jal    func2f854 [$8002f854]
800AF880	nop
800AF884	addiu  v1, zero, $0002
800AF888	bne    v0, v1, Laf8d8 [$800af8d8]
800AF88C	nop
800AF890	jal    func2fc10 [$8002fc10]
800AF894	addiu  a0, sp, $0028
800AF898	lbu    v0, $0028(sp)
800AF89C	lbu    v1, $002c(sp)
800AF8A0	lbu    a0, $002d(sp)
800AF8A4	addu   v0, v0, v1
800AF8A8	lbu    v1, $0029(sp)
800AF8AC	sra    v0, v0, $01
800AF8B0	sb     v0, $0020(sp)
800AF8B4	lbu    v0, $002a(sp)
800AF8B8	addu   v1, v1, a0
800AF8BC	lbu    a0, $002e(sp)
800AF8C0	sra    v1, v1, $01
800AF8C4	sb     v1, $0021(sp)
800AF8C8	addu   v0, v0, a0
800AF8CC	sra    v0, v0, $01
800AF8D0	j      Laf8e0 [$800af8e0]
800AF8D4	sb     v0, $0022(sp)

Laf8d8:	; 800AF8D8
800AF8D8	jal    func2f9a8 [$8002f9a8]
800AF8DC	addiu  a0, sp, $0020

Laf8e0:	; 800AF8E0
800AF8E0	lbu    v0, $0020(sp)
800AF8E4	nop
800AF8E8	sltiu  v0, v0, $00c8
800AF8EC	bne    v0, zero, Laf994 [$800af994]
800AF8F0	lui    t3, $00ff
800AF8F4	lbu    v0, $0021(sp)
800AF8F8	nop
800AF8FC	sltiu  v0, v0, $00c8
800AF900	bne    v0, zero, Laf998 [$800af998]
800AF904	ori    t3, t3, $ffff
800AF908	lbu    v0, $0022(sp)
800AF90C	nop
800AF910	sltiu  v0, v0, $00c8
800AF914	bne    v0, zero, Laf994 [$800af994]
800AF918	lui    t3, $00ff
800AF91C	lui    s1, $800d
800AF920	addiu  s1, s1, $9fa0 (=-$6060)
800AF924	lui    s0, $8007
800AF928	addiu  s0, s0, $86d0 (=-$7930)
800AF92C	lbu    v0, $0007(s1)
800AF930	lh     a0, $075e(s0)
800AF934	ori    v0, v0, $0002
800AF938	sb     v0, $0007(s1)
800AF93C	jal    func1da3c [$8001da3c]
800AF940	addiu  s1, s1, $0014
800AF944	lh     a0, $075e(s0)
800AF948	jal    func1da30 [$8001da30]
800AF94C	addu   s2, v0, zero
800AF950	lh     a0, $075e(s0)
800AF954	jal    func1da3c [$8001da3c]
800AF958	addu   s0, v0, zero
800AF95C	addu   a0, s1, zero
800AF960	addiu  a1, zero, $0001
800AF964	addu   a2, a1, zero
800AF968	andi   s2, s2, $0100
800AF96C	sra    s2, s2, $04
800AF970	andi   s0, s0, $03ff
800AF974	sra    s0, s0, $06
800AF978	ori    s0, s0, $0040
800AF97C	or     s2, s2, s0
800AF980	andi   v0, v0, $0200
800AF984	sll    v0, v0, $02
800AF988	jal    func2420c [$8002420c]
800AF98C	or     a3, s2, v0
800AF990	lui    t3, $00ff

Laf994:	; 800AF994
800AF994	ori    t3, t3, $ffff

Laf998:	; 800AF998
800AF998	lui    v1, $e100
800AF99C	ori    v1, v1, $0240
800AF9A0	lui    t4, $800d
800AF9A4	addiu  a0, t4, $9f98 (=-$6068)
800AF9A8	lui    t5, $800d
800AF9AC	addiu  a2, t5, $9fe0 (=-$6020)
800AF9B0	addiu  v0, zero, $0003
800AF9B4	sb     v0, $0003(a2)
800AF9B8	addiu  v0, zero, $0062
800AF9BC	sb     v0, $0007(a2)
800AF9C0	addiu  v0, zero, $0060
800AF9C4	sb     v0, $0004(a2)
800AF9C8	sb     v0, $0005(a2)
800AF9CC	sb     v0, $0006(a2)
800AF9D0	addiu  v0, zero, $0140
800AF9D4	sh     v0, $000c(a2)
800AF9D8	addiu  v0, zero, $00e0
800AF9DC	lui    t2, $800d
800AF9E0	addiu  t1, t2, $9f90 (=-$6070)
800AF9E4	sh     v0, $000e(a2)
800AF9E8	addiu  v0, zero, $0001
800AF9EC	lui    a1, $ff00
800AF9F0	sh     zero, $0008(a2)
800AF9F4	sh     zero, $000a(a2)
800AF9F8	and    a2, a2, t3
800AF9FC	sb     v0, $0003(t1)
800AFA00	sw     v1, $0004(t1)
800AFA04	and    t1, t1, t3
800AFA08	lw     t0, $9fe0(t5)
800AFA0C	lw     v1, $9f98(t4)
800AFA10	lw     a3, $9f90(t2)
800AFA14	and    t0, t0, a1
800AFA18	and    v0, v1, t3
800AFA1C	or     t0, t0, v0
800AFA20	and    v1, v1, a1
800AFA24	or     v1, v1, a2
800AFA28	and    a3, a3, a1
800AFA2C	and    v0, v1, t3
800AFA30	or     a3, a3, v0
800AFA34	and    a1, v1, a1
800AFA38	or     a1, a1, t1
800AFA3C	sw     t0, $9fe0(t5)
800AFA40	sw     v1, $9f98(t4)
800AFA44	sw     a3, $9f90(t2)
800AFA48	jal    func13698 [$80013698]
800AFA4C	sw     a1, $9f98(t4)
800AFA50	lui    v0, $8006
800AFA54	lw     v0, $794c(v0)
800AFA58	nop
800AFA5C	lw     v1, $001c(v0)
800AFA60	nop
800AFA64	lw     v0, $0000(v1)
800AFA68	nop
800AFA6C	ori    v0, v0, $0020
800AFA70	j      Lafaa8 [$800afaa8]
800AFA74	sw     v0, $0000(v1)

Lafa78:	; 800AFA78
800AFA78	jal    func23f60 [$80023f60]

Lafa7c:	; 800AFA7C
800AFA7C	addu   a0, zero, zero
800AFA80	jal    func55698 [$80055698]
800AFA84	addu   a0, zero, zero
800AFA88	lw     v0, $794c(s0)
800AFA8C	nop
800AFA90	lw     a0, $001c(v0)
800AFA94	nop
800AFA98	lw     v0, $0000(a0)
800AFA9C	addiu  v1, zero, $ffdf (=-$21)
800AFAA0	and    v0, v0, v1
800AFAA4	sw     v0, $0000(a0)

Lafaa8:	; 800AFAA8
800AFAA8	lw     ra, $0044(sp)
800AFAAC	lw     s2, $0040(sp)
800AFAB0	lw     s1, $003c(sp)
800AFAB4	lw     s0, $0038(sp)
800AFAB8	jr     ra 
800AFABC	addiu  sp, sp, $0048



////////////////////////////////
// funcafac0
800AFAC0-800AFCB8
////////////////////////////////



funcafcbc:	; 800AFCBC
800AFCBC	lui    v0, $8006
800AFCC0	lw     v0, $794c(v0)
800AFCC4	addiu  sp, sp, $ffd8 (=-$28)
800AFCC8	sw     ra, $0020(sp)
800AFCCC	sw     s3, $001c(sp)
800AFCD0	sw     s2, $0018(sp)
800AFCD4	sw     s1, $0014(sp)
800AFCD8	sw     s0, $0010(sp)
800AFCDC	lw     v1, $001c(v0)
800AFCE0	nop
800AFCE4	lw     v0, $08e4(v1)
800AFCE8	addu   s3, a0, zero
800AFCEC	lw     v0, $000c(v0)
800AFCF0	lh     a1, $000c(v1)
800AFCF4	lw     a0, $0014(v0)
800AFCF8	jal    funcaa0c8 [$800aa0c8]
800AFCFC	addu   s0, zero, zero
800AFD00	addu   s2, s3, zero
800AFD04	addiu  s3, s3, $0014
800AFD08	sw     s3, $0004(s2)
800AFD0C	addiu  s3, s3, $0020
800AFD10	ori    a1, zero, $ffff
800AFD14	addiu  v0, zero, $0001
800AFD18	addiu  a0, zero, $0010
800AFD1C	sh     v0, $0000(s2)
800AFD20	addu   v0, a0, zero
800AFD24	sb     a0, $0002(s2)
800AFD28	sb     v0, $0003(s2)
800AFD2C	sll    v0, s0, $01

loopafd30:	; 800AFD30
800AFD30	lw     v1, $0004(s2)
800AFD34	addiu  s0, s0, $0001
800AFD38	addu   v0, v0, v1
800AFD3C	sh     a1, $0000(v0)
800AFD40	slt    v0, s0, a0
800AFD44	bne    v0, zero, loopafd30 [$800afd30]
800AFD48	sll    v0, s0, $01
800AFD4C	sw     s3, $0008(s2)
800AFD50	lbu    v1, $0003(s2)
800AFD54	addu   s0, zero, zero
800AFD58	sll    v0, v1, $03
800AFD5C	addu   v0, v0, v1
800AFD60	sll    v0, v0, $02
800AFD64	beq    v1, zero, Lafd94 [$800afd94]
800AFD68	addu   s3, s3, v0
800AFD6C	addu   s1, s0, zero

loopafd70:	; 800AFD70
800AFD70	lw     a0, $0008(s2)
800AFD74	addiu  s0, s0, $0001
800AFD78	jal    funcb00b0 [$800b00b0]
800AFD7C	addu   a0, a0, s1
800AFD80	lbu    v0, $0003(s2)
800AFD84	nop
800AFD88	slt    v0, s0, v0
800AFD8C	bne    v0, zero, loopafd70 [$800afd70]

Lafd90:	; 800AFD90
800AFD90	addiu  s1, s1, $0024

Lafd94:	; 800AFD94
800AFD94	lui    v0, $8006
800AFD98	lw     v1, $794c(v0)
800AFD9C	addiu  v0, s3, $3000
800AFDA0	sw     s3, $000c(s2)

Lafda4:	; 800AFDA4
800AFDA4	sw     v0, $0010(s2)
800AFDA8	lw     v0, $001c(v1)
800AFDAC	nop
800AFDB0	lw     v0, $08e4(v0)
800AFDB4	nop
800AFDB8	lw     v0, $000c(v0)
800AFDBC	nop
800AFDC0	lw     v1, $0014(v0)
800AFDC4	addiu  v0, s3, $6000
800AFDC8	sw     s2, $0010(v1)
800AFDCC	lw     ra, $0020(sp)
800AFDD0	lw     s3, $001c(sp)
800AFDD4	lw     s2, $0018(sp)
800AFDD8	lw     s1, $0014(sp)
800AFDDC	lw     s0, $0010(sp)
800AFDE0	jr     ra 
800AFDE4	addiu  sp, sp, $0028


funcafde8:	; 800AFDE8
800AFDE8	lui    v0, $8006
800AFDEC	lw     v0, $794c(v0)

Lafdf0:	; 800AFDF0
800AFDF0	addiu  sp, sp, $ffa8 (=-$58)
800AFDF4	sw     ra, $0050(sp)
800AFDF8	sw     s5, $004c(sp)
800AFDFC	sw     s4, $0048(sp)
800AFE00	sw     s3, $0044(sp)
800AFE04	sw     s2, $0040(sp)
800AFE08	sw     s1, $003c(sp)
800AFE0C	sw     s0, $0038(sp)
800AFE10	lw     v0, $001c(v0)
800AFE14	nop
800AFE18	lw     v0, $08e4(v0)
800AFE1C	nop
800AFE20	lw     v0, $000c(v0)
800AFE24	nop
800AFE28	lw     v0, $0014(v0)
800AFE2C	nop
800AFE30	lw     s2, $0010(v0)
800AFE34	nop
800AFE38	beq    s2, zero, Lb008c [$800b008c]
800AFE3C	lui    v0, $800d
800AFE40	lhu    v0, $9d44(v0)
800AFE44	nop
800AFE48	andi   v0, v0, $0040
800AFE4C	beq    v0, zero, Lafe74 [$800afe74]
800AFE50	addiu  a0, sp, $0030
800AFE54	jal    func19ae0c [$8019ae0c]

Lafe58:	; 800AFE58
800AFE58	addiu  a1, sp, $0034
800AFE5C	lw     a0, $0030(sp)
800AFE60	lw     a1, $0034(sp)
800AFE64	jal    func16c40 [$80016c40]
800AFE68	nop
800AFE6C	j      Lafe80 [$800afe80]
800AFE70	lui    v0, $8006

Lafe74:	; 800AFE74
800AFE74	jal    funcc0f08 [$800c0f08]
800AFE78	nop
800AFE7C	lui    v0, $8006

Lafe80:	; 800AFE80
800AFE80	lw     v0, $794c(v0)
800AFE84	nop
800AFE88	lw     a0, $001c(v0)
800AFE8C	addu   s1, zero, zero
800AFE90	lbu    v1, $0008(a0)
800AFE94	lw     v0, $08e4(a0)
800AFE98	sll    v1, v1, $02
800AFE9C	addu   a1, s2, v1
800AFEA0	addu   a0, a0, v1
800AFEA4	lw     v0, $000c(v0)
800AFEA8	lw     s4, $000c(a1)
800AFEAC	lw     v0, $0014(v0)
800AFEB0	lw     v1, $0010(a0)
800AFEB4	lh     v0, $0030(v0)
800AFEB8	lbu    a0, $0003(s2)
800AFEBC	sll    v0, v0, $02
800AFEC0	beq    a0, zero, Lb006c [$800b006c]
800AFEC4	addu   s5, v1, v0
800AFEC8	addu   s3, s1, zero

Lafecc:	; 800AFECC
800AFECC	lw     v0, $0008(s2)
800AFED0	nop
800AFED4	addu   s0, v0, s3
800AFED8	lw     v0, $0018(s0)
800AFEDC	nop
800AFEE0	beq    v0, zero, Lb0058 [$800b0058]
800AFEE4	nop
800AFEE8	lw     v0, $0000(s0)
800AFEEC	nop
800AFEF0	andi   v0, v0, $0001
800AFEF4	beq    v0, zero, Lb0058 [$800b0058]
800AFEF8	addiu  v0, zero, $ffff (=-$1)

Lafefc:	; 800AFEFC
800AFEFC	lb     a0, $0002(s0)
800AFF00	nop
800AFF04	beq    a0, v0, Laff68 [$800aff68]
800AFF08	nop
800AFF0C	jal    func1e350 [$8001e350]
800AFF10	nop
800AFF14	lw     v1, $0008(v0)
800AFF18	lbu    v0, $0003(s0)
800AFF1C	nop
800AFF20	sll    v0, v0, $05
800AFF24	lw     a0, $0020(v1)
800AFF28	lhu    v1, $001c(s0)
800AFF2C	addu   a0, a0, v0
800AFF30	lhu    v0, $0014(a0)
800AFF34	addiu  a0, a0, $0014
800AFF38	addu   v0, v0, v1
800AFF3C	sh     v0, $0008(s0)
800AFF40	lhu    v0, $0004(a0)
800AFF44	lhu    v1, $001e(s0)
800AFF48	nop
800AFF4C	addu   v0, v0, v1
800AFF50	sh     v0, $000a(s0)
800AFF54	lhu    v0, $0008(a0)
800AFF58	lhu    v1, $0020(s0)
800AFF5C	nop
800AFF60	addu   v0, v0, v1
800AFF64	sh     v0, $000c(s0)

Laff68:	; 800AFF68
800AFF68	lhu    v0, $0010(s0)
800AFF6C	nop
800AFF70	sh     v0, $0028(sp)
800AFF74	lhu    v0, $0012(s0)
800AFF78	nop
800AFF7C	sh     v0, $002a(sp)
800AFF80	lhu    v0, $0014(s0)
800AFF84	sh     zero, $002e(sp)
800AFF88	sh     v0, $002c(sp)
800AFF8C	lh     v0, $0004(s0)
800AFF90	nop
800AFF94	sw     v0, $0010(sp)

Laff98:	; 800AFF98
800AFF98	lhu    v0, $0016(s0)
800AFF9C	nop
800AFFA0	sll    v0, v0, $10
800AFFA4	sra    v0, v0, $14
800AFFA8	sw     v0, $0014(sp)
800AFFAC	lbu    v0, $0000(s0)
800AFFB0	nop
800AFFB4	srl    v1, v0, $04
800AFFB8	slti   v0, v1, $0004
800AFFBC	beq    v0, zero, Laffcc [$800affcc]
800AFFC0	addiu  a2, s0, $0008
800AFFC4	j      Laffd4 [$800affd4]
800AFFC8	sw     v1, $0018(sp)

Laffcc:	; 800AFFCC
800AFFCC	addiu  v0, zero, $00ff
800AFFD0	sw     v0, $0018(sp)

Laffd4:	; 800AFFD4
800AFFD4	lbu    v0, $0007(s0)
800AFFD8	nop
800AFFDC	sll    v0, v0, $04
800AFFE0	sw     v0, $001c(sp)

Laffe4:	; 800AFFE4
800AFFE4	lh     v0, $0022(s0)
800AFFE8	addu   a0, s4, zero
800AFFEC	sll    v0, v0, $02
800AFFF0	addu   v0, s5, v0
800AFFF4	sw     v0, $0020(sp)
800AFFF8	lw     a1, $0018(s0)
800AFFFC	jal    funcc970c [$800c970c]
800B0000	addiu  a3, sp, $0028
800B0004	addu   s4, v0, zero
800B0008	lbu    v1, $0006(s0)
800B000C	lhu    v0, $0016(s0)
800B0010	sll    v1, v1, $18
800B0014	sra    v1, v1, $18
800B0018	addu   v0, v0, v1
800B001C	sh     v0, $0016(s0)
800B0020	sll    v0, v0, $10
800B0024	lhu    v1, $000e(s0)
800B0028	sra    a0, v0, $10

Lb002c:	; 800B002C
800B002C	sll    v1, v1, $10
800B0030	slt    v0, v0, v1
800B0034	bne    v0, zero, Lb0044 [$800b0044]
800B0038	nop
800B003C	j      Lb0058 [$800b0058]
800B0040	sh     zero, $0016(s0)

Lb0044:	; 800B0044
800B0044	bgez   a0, Lb0058 [$800b0058]
800B0048	sra    v0, v1, $14
800B004C	addiu  v0, v0, $ffff (=-$1)
800B0050	sll    v0, v0, $04
800B0054	sh     v0, $0016(s0)

Lb0058:	; 800B0058
800B0058	lbu    v0, $0003(s2)
800B005C	addiu  s1, s1, $0001

funcb0060:	; 800B0060
800B0060	slt    v0, s1, v0
800B0064	bne    v0, zero, Lafecc [$800afecc]
800B0068	addiu  s3, s3, $0024

Lb006c:	; 800B006C
800B006C	lui    v0, $800d
800B0070	lhu    v0, $9d44(v0)
800B0074	nop
800B0078	andi   v0, v0, $0040
800B007C	bne    v0, zero, Lb008c [$800b008c]
800B0080	nop
800B0084	jal    funcc0fb0 [$800c0fb0]
800B0088	nop

Lb008c:	; 800B008C
800B008C	lw     ra, $0050(sp)
800B0090	lw     s5, $004c(sp)
800B0094	lw     s4, $0048(sp)
800B0098	lw     s3, $0044(sp)
800B009C	lw     s2, $0040(sp)
800B00A0	lw     s1, $003c(sp)
800B00A4	lw     s0, $0038(sp)
800B00A8	jr     ra 
800B00AC	addiu  sp, sp, $0058


funcb00b0:	; 800B00B0
800B00B0	addu   a2, zero, zero
800B00B4	addu   a1, a0, zero
800B00B8	addiu  v0, zero, $1000
800B00BC	sh     v0, $0004(a0)
800B00C0	addiu  v0, zero, $0010
800B00C4	sb     v0, $0006(a0)
800B00C8	addiu  v0, zero, $0080
800B00CC	sb     v0, $0007(a0)
800B00D0	lw     v0, $0000(a0)
800B00D4	addiu  v1, zero, $fff0 (=-$10)
800B00D8	and    v0, v0, v1
800B00DC	ori    v0, v0, $00f1
800B00E0	sw     v0, $0000(a0)
800B00E4	addiu  v0, zero, $ffff (=-$1)
800B00E8	sb     v0, $0001(a0)
800B00EC	sb     v0, $0002(a0)
800B00F0	sb     zero, $0003(a0)

loopb00f4:	; 800B00F4
800B00F4	sh     zero, $0008(a1)
800B00F8	sh     zero, $0010(a1)
800B00FC	sh     zero, $001c(a1)
800B0100	addiu  a2, a2, $0001
800B0104	slti   v0, a2, $0003
800B0108	bne    v0, zero, loopb00f4 [$800b00f4]
800B010C	addiu  a1, a1, $0002
800B0110	sh     zero, $0016(a0)

Lb0114:	; 800B0114
800B0114	sh     zero, $000e(a0)
800B0118	sw     zero, $0018(a0)
800B011C	jr     ra 
800B0120	sh     zero, $0022(a0)



////////////////////////////////
// funcb0124
800B0124-800B1A1C
////////////////////////////////




funcb1a20:	; 800B1A20
800B1A20	lui    v1, $8006
800B1A24	lw     v0, $794c(v1)
800B1A28	addiu  sp, sp, $ffe8 (=-$18)
800B1A2C	sh     a0, $0000(sp)
800B1A30	sh     a1, $0002(sp)
800B1A34	sh     a2, $0004(sp)
800B1A38	lw     v0, $001c(v0)
800B1A3C	nop
800B1A40	addiu  v0, v0, $0018
800B1A44	lw     t4, $0000(v0)
800B1A48	lw     t5, $0004(v0)
800B1A4C	ctc2   t4,vxy0
800B1A50	ctc2   t5,vz0
800B1A54	lw     t4, $0008(v0)
800B1A58	lw     t5, $000c(v0)
800B1A5C	lw     t6, $0010(v0)
800B1A60	ctc2   t4,vxy1
800B1A64	ctc2   t5,vz1
800B1A68	ctc2   t6,vxy2
800B1A6C	lw     t4, $0014(v0)
800B1A70	lw     t5, $0018(v0)
800B1A74	ctc2   t4,vz2
800B1A78	lw     t6, $001c(v0)
800B1A7C	ctc2   t5,rgb
800B1A80	ctc2   t6,otz
800B1A84	lwc2   zero, $0000(sp)
800B1A88	lwc2   at, $0004(sp)

Lb1a8c:	; 800B1A8C
800B1A8C	nop
800B1A90	nop
800B1A94	gte_func16t8,r11r12
800B1A98	addiu  v0, sp, $0008
800B1A9C	swc2   t6, $0000(v0)
800B1AA0	addiu  v0, sp, $0010
800B1AA4	swc2   s3, $0000(v0)
800B1AA8	lw     a0, $0010(sp)
800B1AAC	nop
800B1AB0	bgez   a0, Lb1abc [$800b1abc]
800B1AB4	nop
800B1AB8	addiu  a0, a0, $0003

Lb1abc:	; 800B1ABC
800B1ABC	lw     v0, $794c(v1)
800B1AC0	nop
800B1AC4	lw     v0, $001c(v0)
800B1AC8	nop
800B1ACC	lw     v0, $08e4(v0)
800B1AD0	nop
800B1AD4	lw     v0, $000c(v0)
800B1AD8	nop
800B1ADC	lw     v0, $0014(v0)
800B1AE0	nop
800B1AE4	lh     v1, $0030(v0)
800B1AE8	sra    v0, a0, $02
800B1AEC	addu   v0, v0, v1
800B1AF0	bgez   v0, Lb1b00 [$800b1b00]
800B1AF4	sw     v0, $0010(sp)
800B1AF8	j      Lb1b10 [$800b1b10]
800B1AFC	sw     zero, $0010(sp)

Lb1b00:	; 800B1B00
800B1B00	slti   v0, v0, $1000

Lb1b04:	; 800B1B04
800B1B04	bne    v0, zero, Lb1b10 [$800b1b10]
800B1B08	addiu  v0, zero, $0fff
800B1B0C	sw     v0, $0010(sp)

Lb1b10:	; 800B1B10
800B1B10	lw     v0, $0010(sp)
800B1B14	nop
800B1B18	bgez   v0, Lb1b28 [$800b1b28]
800B1B1C	sra    a1, v0, $05
800B1B20	addiu  v0, v0, $001f
800B1B24	sra    a1, v0, $05

Lb1b28:	; 800B1B28
800B1B28	addiu  v0, zero, $0080
800B1B2C	subu   v0, v0, a1

Lb1b30:	; 800B1B30
800B1B30	lhu    v1, $0008(sp)
800B1B34	sll    a0, v0, $01
800B1B38	sltiu  v0, v1, $0140
800B1B3C	beq    v0, zero, Lb1b74 [$800b1b74]
800B1B40	sll    v0, v1, $10
800B1B44	sra    v0, v0, $10

funcb1b48:	; 800B1B48
800B1B48	mult   v0, a0
800B1B4C	mflo   v0
800B1B50	lui    v1, $6666
800B1B54	ori    v1, v1, $6667
800B1B58	mult   v0, v1
800B1B5C	sra    v0, v0, $1f
800B1B60	mfhi   v1
800B1B64	sra    v1, v1, $07
800B1B68	subu   v0, v1, v0
800B1B6C	j      Lb1c10 [$800b1c10]
800B1B70	addu   v0, v0, a1

Lb1b74:	; 800B1B74
800B1B74	sra    v0, v0, $10
800B1B78	bgez   v0, Lb1bc8 [$800b1bc8]
800B1B7C	nop
800B1B80	slti   v0, v0, $fec0 (=-$140)
800B1B84	beq    v0, zero, Lb1b94 [$800b1b94]
800B1B88	nop
800B1B8C	addiu  v0, zero, $fec0 (=-$140)
800B1B90	sh     v0, $0008(sp)

Lb1b94:	; 800B1B94
800B1B94	lh     v0, $0008(sp)
800B1B98	nop
800B1B9C	addiu  v0, v0, $0140
800B1BA0	mult   v0, a1
800B1BA4	mflo   v0
800B1BA8	lui    v1, $6666
800B1BAC	ori    v1, v1, $6667
800B1BB0	mult   v0, v1
800B1BB4	sra    v0, v0, $1f
800B1BB8	mfhi   v1
800B1BBC	sra    v1, v1, $07
800B1BC0	j      Lb1c10 [$800b1c10]
800B1BC4	subu   v0, v1, v0

Lb1bc8:	; 800B1BC8
800B1BC8	slti   v0, v0, $0280
800B1BCC	bne    v0, zero, Lb1bd8 [$800b1bd8]
800B1BD0	addiu  v0, zero, $027f
800B1BD4	sh     v0, $0008(sp)

Lb1bd8:	; 800B1BD8
800B1BD8	lh     v0, $0008(sp)
800B1BDC	nop
800B1BE0	addiu  v0, v0, $fec0 (=-$140)
800B1BE4	mult   v0, a1
800B1BE8	mflo   v0
800B1BEC	lui    v1, $6666
800B1BF0	ori    v1, v1, $6667
800B1BF4	mult   v0, v1
800B1BF8	sra    v0, v0, $1f
800B1BFC	mfhi   v1
800B1C00	sra    v1, v1, $07
800B1C04	subu   v0, v1, v0
800B1C08	addiu  v0, v0, $00ff
800B1C0C	subu   v0, v0, a1

Lb1c10:	; 800B1C10
800B1C10	sb     v0, $0000(a3)
800B1C14	lw     v0, $0010(sp)
800B1C18	addiu  v1, zero, $1000
800B1C1C	subu   v1, v1, v0
800B1C20	sll    v0, v1, $07
800B1C24	subu   v0, v0, v1
800B1C28	bgez   v0, Lb1c38 [$800b1c38]
800B1C2C	sra    v1, v0, $0c
800B1C30	addiu  v0, v0, $0fff
800B1C34	sra    v1, v0, $0c

Lb1c38:	; 800B1C38
800B1C38	lw     v0, $0028(sp)
800B1C3C	nop
800B1C40	sb     v1, $0000(v0)
800B1C44	jr     ra 
800B1C48	addiu  sp, sp, $0018


funcb1c4c:	; 800B1C4C
800B1C4C	addiu  sp, sp, $ffe0 (=-$20)
800B1C50	sw     s0, $0018(sp)
800B1C54	addiu  s0, zero, $0001
800B1C58	sw     ra, $001c(sp)

loopb1c5c:	; 800B1C5C
800B1C5C	sw     zero, $0010(sp)
800B1C60	andi   a0, s0, $0001
800B1C64	sll    a0, a0, $06
800B1C68	ori    a0, a0, $1880
800B1C6C	addu   a1, s0, zero

Lb1c70:	; 800B1C70
800B1C70	addu   a2, zero, zero
800B1C74	jal    funcb0124 [$800b0124]
800B1C78	addu   a3, a2, zero
800B1C7C	addiu  s0, s0, $ffff (=-$1)
800B1C80	bgez   s0, loopb1c5c [$800b1c5c]
800B1C84	nop
800B1C88	lw     ra, $001c(sp)
800B1C8C	lw     s0, $0018(sp)
800B1C90	jr     ra 
800B1C94	addiu  sp, sp, $0020


funcb1c98:	; 800B1C98
800B1C98	addiu  sp, sp, $ffe0 (=-$20)
800B1C9C	sw     s0, $0018(sp)
800B1CA0	addiu  s0, zero, $0001
800B1CA4	sw     ra, $001c(sp)

loopb1ca8:	; 800B1CA8
800B1CA8	sw     zero, $0010(sp)
800B1CAC	andi   a0, s0, $0001
800B1CB0	sll    a0, a0, $06
800B1CB4	ori    a0, a0, $1980
800B1CB8	addu   a1, s0, zero
800B1CBC	addu   a2, zero, zero
800B1CC0	jal    funcb0124 [$800b0124]
800B1CC4	addu   a3, a2, zero
800B1CC8	addiu  s0, s0, $ffff (=-$1)
800B1CCC	bgez   s0, loopb1ca8 [$800b1ca8]
800B1CD0	nop
800B1CD4	lw     ra, $001c(sp)
800B1CD8	lw     s0, $0018(sp)
800B1CDC	jr     ra 
800B1CE0	addiu  sp, sp, $0020


funcb1ce4:	; 800B1CE4
800B1CE4	addiu  sp, sp, $ffd8 (=-$28)
800B1CE8	sw     s0, $0018(sp)
800B1CEC	addiu  s0, zero, $0001
800B1CF0	sw     s2, $0020(sp)
800B1CF4	lui    s2, $8006
800B1CF8	sw     s1, $001c(sp)
800B1CFC	ori    s1, zero, $ffff
800B1D00	sw     ra, $0024(sp)

loopb1d04:	; 800B1D04
800B1D04	lw     v0, $794c(s2)
800B1D08	nop
800B1D0C	lw     v1, $001c(v0)
800B1D10	sll    v0, s0, $01
800B1D14	addu   v1, v1, v0
800B1D18	lhu    v0, $0830(v1)
800B1D1C	nop
800B1D20	beq    v0, s1, Lb1d3c [$800b1d3c]
800B1D24	addu   a1, v0, zero
800B1D28	sw     zero, $0010(sp)
800B1D2C	addiu  a0, zero, $5180
800B1D30	addu   a2, zero, zero
800B1D34	jal    funcb0124 [$800b0124]
800B1D38	addu   a3, a2, zero

Lb1d3c:	; 800B1D3C
800B1D3C	addiu  s0, s0, $ffff (=-$1)
800B1D40	bgez   s0, loopb1d04 [$800b1d04]

Lb1d44:	; 800B1D44
800B1D44	nop
800B1D48	lw     ra, $0024(sp)
800B1D4C	lw     s2, $0020(sp)
800B1D50	lw     s1, $001c(sp)
800B1D54	lw     s0, $0018(sp)
800B1D58	jr     ra 
800B1D5C	addiu  sp, sp, $0028


funcb1d60:	; 800B1D60
800B1D60	addiu  v1, zero, $0004
800B1D64	addiu  a1, zero, $ffff (=-$1)
800B1D68	lui    v0, $800d
800B1D6C	addiu  a2, v0, $9ff0 (=-$6010)
800B1D70	lui    v0, $800d
800B1D74	addiu  v0, v0, $9ff8 (=-$6008)
800B1D78	addiu  a0, v0, $0010

loopb1d7c:	; 800B1D7C
800B1D7C	sw     a1, $0000(a0)
800B1D80	addiu  a0, a0, $fffc (=-$4)
800B1D84	addu   v0, v1, a2
800B1D88	addiu  v1, v1, $ffff (=-$1)
800B1D8C	bgez   v1, loopb1d7c [$800b1d7c]
800B1D90	sb     a1, $0000(v0)
800B1D94	jr     ra 
800B1D98	nop


funcb1d9c:	; 800B1D9C
800B1D9C	lui    v0, $0003
800B1DA0	ori    v0, v0, $ffff
800B1DA4	slt    v0, v0, a0
800B1DA8	beq    v0, zero, Lb1dfc [$800b1dfc]
800B1DAC	addiu  a0, zero, $0004
800B1DB0	addu   t0, a0, zero
800B1DB4	addiu  a3, zero, $0001
800B1DB8	addiu  a1, zero, $ffff (=-$1)
800B1DBC	lui    v0, $800d
800B1DC0	addiu  a2, v0, $9ff0 (=-$6010)
800B1DC4	lui    v0, $800d
800B1DC8	addiu  v0, v0, $9ff8 (=-$6008)
800B1DCC	addiu  v1, v0, $0010

loopb1dd0:	; 800B1DD0
800B1DD0	lbu    v0, $0003(v1)
800B1DD4	nop
800B1DD8	beq    v0, t0, Lb1df0 [$800b1df0]
800B1DDC	nop
800B1DE0	beq    v0, a3, Lb1df0 [$800b1df0]
800B1DE4	addu   v0, a0, a2
800B1DE8	sw     a1, $0000(v1)
800B1DEC	sb     a1, $0000(v0)

Lb1df0:	; 800B1DF0
800B1DF0	addiu  a0, a0, $ffff (=-$1)
800B1DF4	bgez   a0, loopb1dd0 [$800b1dd0]
800B1DF8	addiu  v1, v1, $fffc (=-$4)

Lb1dfc:	; 800B1DFC
800B1DFC	jr     ra 
800B1E00	nop


funcb1e04:	; 800B1E04
800B1E04	addiu  sp, sp, $ffe0 (=-$20)
800B1E08	addiu  a1, zero, $0001
800B1E0C	lui    a2, $0008
800B1E10	sw     ra, $001c(sp)
800B1E14	sw     s2, $0018(sp)
800B1E18	sw     s1, $0014(sp)
800B1E1C	sw     s0, $0010(sp)
800B1E20	lw     s1, $0024(a0)
800B1E24	addu   a3, zero, zero
800B1E28	jal    func1c8b0 [$8001c8b0]
800B1E2C	addu   a0, s1, zero
800B1E30	addiu  s0, v0, $ffff (=-$1)
800B1E34	bltz   s0, Lb1e6c [$800b1e6c]
800B1E38	lui    s2, $0008
800B1E3C	addu   a0, s1, zero

loopb1e40:	; 800B1E40
800B1E40	addiu  a1, zero, $0002
800B1E44	andi   a2, s0, $ffff
800B1E48	or     a2, a2, s2
800B1E4C	jal    func1c8b0 [$8001c8b0]
800B1E50	addu   a3, zero, zero
800B1E54	addu   a0, v0, zero
800B1E58	jal    func5546c [$8005546c]
800B1E5C	addu   a1, zero, zero
800B1E60	addiu  s0, s0, $ffff (=-$1)
800B1E64	bgez   s0, loopb1e40 [$800b1e40]
800B1E68	addu   a0, s1, zero

Lb1e6c:	; 800B1E6C
800B1E6C	jal    func56228 [$80056228]
800B1E70	nop
800B1E74	lw     ra, $001c(sp)
800B1E78	lw     s2, $0018(sp)
800B1E7C	lw     s1, $0014(sp)
800B1E80	lw     s0, $0010(sp)
800B1E84	jr     ra 
800B1E88	addiu  sp, sp, $0020


funcb1e8c:	; 800B1E8C
800B1E8C	lui    v0, $8006
800B1E90	lw     v0, $794c(v0)
800B1E94	addiu  sp, sp, $ffb0 (=-$50)
800B1E98	sw     ra, $004c(sp)
800B1E9C	sw     fp, $0048(sp)
800B1EA0	sw     s7, $0044(sp)
800B1EA4	sw     s6, $0040(sp)
800B1EA8	sw     s5, $003c(sp)
800B1EAC	sw     s4, $0038(sp)
800B1EB0	sw     s3, $0034(sp)
800B1EB4	sw     s2, $0030(sp)
800B1EB8	sw     s1, $002c(sp)
800B1EBC	sw     s0, $0028(sp)
800B1EC0	sw     a0, $0050(sp)
800B1EC4	lw     v0, $001c(v0)
800B1EC8	nop
800B1ECC	lw     v0, $08e4(v0)
800B1ED0	nop
800B1ED4	lw     v0, $000c(v0)
800B1ED8	nop
800B1EDC	lw     v0, $0014(v0)
800B1EE0	nop
800B1EE4	lw     t0, $0058(v0)
800B1EE8	addiu  s6, a1, $ffff (=-$1)
800B1EEC	sw     t0, $0020(sp)
800B1EF0	lbu    fp, $004b(v0)
800B1EF4	bltz   s6, Lb20d0 [$800b20d0]
800B1EF8	lui    s7, $8008

Lb1efc:	; 800B1EFC
800B1EFC	lw     t0, $0050(sp)
800B1F00	sll    v0, s6, $02
800B1F04	addu   v0, v0, t0
800B1F08	lw     s5, $0000(v0)
800B1F0C	nop
800B1F10	beq    s5, zero, Lb20c4 [$800b20c4]
800B1F14	nop
800B1F18	lw     v0, $0000(s5)
800B1F1C	nop
800B1F20	andi   v0, v0, $0040
800B1F24	bne    v0, zero, Lb20c4 [$800b20c4]
800B1F28	nop
800B1F2C	addiu  s3, fp, $ffff (=-$1)
800B1F30	bltz   s3, Lb20c4 [$800b20c4]
800B1F34	sll    v0, s3, $01
800B1F38	addu   v0, v0, s3
800B1F3C	lw     t0, $0020(sp)
800B1F40	sll    v0, v0, $02
800B1F44	addu   s0, v0, t0

loopb1f48:	; 800B1F48
800B1F48	lw     a0, $000c(s5)
800B1F4C	lbu    v1, $0000(s0)
800B1F50	lbu    v0, $003b(a0)
800B1F54	nop
800B1F58	bne    v1, v0, Lb20b8 [$800b20b8]
800B1F5C	nop
800B1F60	lhu    v1, $0004(s0)
800B1F64	lhu    v0, $0036(a0)
800B1F68	nop
800B1F6C	bne    v1, v0, Lb20b8 [$800b20b8]
800B1F70	nop
800B1F74	lh     v1, $0006(s0)
800B1F78	lbu    v0, $003a(a0)
800B1F7C	nop
800B1F80	bne    v1, v0, Lb20b8 [$800b20b8]
800B1F84	addiu  a1, sp, $0018
800B1F88	addu   s4, zero, zero
800B1F8C	addiu  v0, zero, $0080
800B1F90	sh     zero, $0018(sp)
800B1F94	sh     zero, $001a(sp)
800B1F98	sh     zero, $001c(sp)
800B1F9C	sb     v0, $001e(sp)
800B1FA0	lw     v1, $000c(s5)
800B1FA4	addiu  v0, zero, $007f
800B1FA8	sb     v0, $001f(sp)
800B1FAC	lbu    a0, $003b(v1)
800B1FB0	jal    funcc76e8 [$800c76e8]
800B1FB4	addiu  a2, sp, $001a
800B1FB8	lh     a0, $0018(sp)
800B1FBC	addiu  v0, zero, $ffff (=-$1)
800B1FC0	beq    a0, v0, Lb1fe8 [$800b1fe8]
800B1FC4	lui    v1, $0001
800B1FC8	jal    funcc7800 [$800c7800]
800B1FCC	addiu  a1, sp, $001c
800B1FD0	lhu    v0, $001c(sp)

Lb1fd4:	; 800B1FD4
800B1FD4	nop
800B1FD8	sll    v0, v0, $10
800B1FDC	sra    v0, v0, $18
800B1FE0	sh     v0, $001c(sp)
800B1FE4	lui    v1, $0001

Lb1fe8:	; 800B1FE8
800B1FE8	lbu    v0, $0000(s0)
800B1FEC	lui    a0, $000f
800B1FF0	andi   s1, v0, $0003
800B1FF4	sllv   v1, s1, v1
800B1FF8	and    s1, v1, a0
800B1FFC	lhu    v0, $001c(sp)
800B2000	lui    a0, $0008
800B2004	srl    v0, v0, $03
800B2008	andi   v0, v0, $0002
800B200C	addu   v0, s0, v0
800B2010	lhu    v0, $0008(v0)
800B2014	lbu    v1, $0001(s0)
800B2018	nop
800B201C	beq    v1, zero, Lb2060 [$800b2060]
800B2020	or     s2, v0, a0
800B2024	lw     v1, $b720(s7)
800B2028	lui    v0, $8008
800B202C	addiu  v0, v0, $b92d (=-$46d3)
800B2030	sltu   v1, v1, v0
800B2034	bne    v1, zero, Lb2044 [$800b2044]
800B2038	nop
800B203C	jal    system_reset_random [$8004bf20]
800B2040	nop

Lb2044:	; 800B2044
800B2044	lw     v0, $b720(s7)
800B2048	nop
800B204C	lbu    v1, $0000(v0)
800B2050	addiu  v0, v0, $0001
800B2054	sw     v0, $b720(s7)
800B2058	sra    v1, v1, $04
800B205C	addiu  s4, v1, $fff8 (=-$8)

Lb2060:	; 800B2060
800B2060	lw     v0, $000c(s5)
800B2064	addiu  a3, sp, $001e
800B2068	lh     a0, $0014(v0)
800B206C	lh     a1, $0018(v0)
800B2070	lh     a2, $001c(v0)
800B2074	addiu  v0, sp, $001f
800B2078	jal    funcb1a20 [$800b1a20]
800B207C	sw     v0, $0010(sp)
800B2080	ori    a0, zero, $d000
800B2084	addu   a1, s2, zero
800B2088	lbu    a3, $001e(sp)
800B208C	lbu    v0, $001f(sp)
800B2090	addu   a2, s1, zero
800B2094	jal    funcb0124 [$800b0124]
800B2098	sw     v0, $0010(sp)
800B209C	beq    s4, zero, Lb20b8 [$800b20b8]
800B20A0	ori    a0, zero, $9203
800B20A4	sw     zero, $0010(sp)
800B20A8	addu   a1, s2, zero
800B20AC	addu   a2, s1, zero
800B20B0	jal    funcb0124 [$800b0124]
800B20B4	addu   a3, s4, zero

Lb20b8:	; 800B20B8
800B20B8	addiu  s3, s3, $ffff (=-$1)
800B20BC	bgez   s3, loopb1f48 [$800b1f48]
800B20C0	addiu  s0, s0, $fff4 (=-$c)

Lb20c4:	; 800B20C4
800B20C4	addiu  s6, s6, $ffff (=-$1)
800B20C8	bgez   s6, Lb1efc [$800b1efc]
800B20CC	nop

Lb20d0:	; 800B20D0
800B20D0	lw     ra, $004c(sp)
800B20D4	lw     fp, $0048(sp)
800B20D8	lw     s7, $0044(sp)
800B20DC	lw     s6, $0040(sp)
800B20E0	lw     s5, $003c(sp)
800B20E4	lw     s4, $0038(sp)
800B20E8	lw     s3, $0034(sp)
800B20EC	lw     s2, $0030(sp)
800B20F0	lw     s1, $002c(sp)
800B20F4	lw     s0, $0028(sp)
800B20F8	jr     ra 
800B20FC	addiu  sp, sp, $0050


funcb2100:	; 800B2100
800B2100	lui    v0, $8006
800B2104	lw     v0, $794c(v0)
800B2108	nop
800B210C	lw     v0, $001c(v0)
800B2110	andi   t0, a1, $ffff
800B2114	lw     v0, $08e4(v0)
800B2118	sll    a2, a2, $10
800B211C	lw     v0, $000c(v0)
800B2120	sra    a2, a2, $10
800B2124	lw     a1, $0014(v0)
800B2128	lw     v0, $000c(a0)
800B212C	lbu    v1, $004b(a1)
800B2130	lbu    a3, $003b(v0)
800B2134	lw     a1, $0058(a1)
800B2138	sll    v0, v1, $01
800B213C	addu   v0, v0, v1
800B2140	sll    v0, v0, $02
800B2144	addu   v0, a1, v0
800B2148	addiu  v1, v0, $fff4 (=-$c)
800B214C	addiu  a0, v0, $fffa (=-$6)

loopb2150:	; 800B2150
800B2150	lbu    v0, $0000(v1)
800B2154	nop
800B2158	bne    v0, a3, Lb2180 [$800b2180]
800B215C	nop
800B2160	lhu    v0, $fffe(a0)
800B2164	nop
800B2168	bne    v0, t0, Lb2180 [$800b2180]
800B216C	nop
800B2170	lh     v0, $0000(a0)
800B2174	nop
800B2178	beq    v0, a2, Lb2198 [$800b2198]
800B217C	addu   v0, v1, zero

Lb2180:	; 800B2180
800B2180	addiu  v1, v1, $fff4 (=-$c)
800B2184	sltu   v0, v1, a1
800B2188	beq    v0, zero, loopb2150 [$800b2150]
800B218C	addiu  a0, a0, $fff4 (=-$c)
800B2190	jr     ra 
800B2194	addu   v0, zero, zero


Lb2198:	; 800B2198
800B2198	jr     ra 
800B219C	nop


funcb21a0:	; 800B21A0
800B21A0	lui    v0, $8006
800B21A4	lw     v0, $794c(v0)
800B21A8	nop
800B21AC	lw     v0, $001c(v0)
800B21B0	nop
800B21B4	lw     v0, $08e4(v0)
800B21B8	nop
800B21BC	lw     v0, $000c(v0)
800B21C0	nop
800B21C4	lw     a3, $0014(v0)
800B21C8	nop
800B21CC	lbu    v0, $004b(a3)
800B21D0	nop
800B21D4	addiu  v1, v0, $0001
800B21D8	sb     v1, $004b(a3)
800B21DC	sll    v1, v0, $01
800B21E0	addu   v1, v1, v0
800B21E4	sll    v1, v1, $02
800B21E8	lw     t0, $000c(a0)
800B21EC	lw     v0, $0058(a3)
800B21F0	lbu    a3, $003b(t0)
800B21F4	addu   v0, v0, v1
800B21F8	sb     a3, $0000(v0)
800B21FC	lw     v1, $000c(a0)
800B2200	nop
800B2204	lhu    v1, $0034(v1)
800B2208	sh     a1, $0004(v0)
800B220C	sh     a2, $0006(v0)
800B2210	jr     ra 
800B2214	sh     v1, $0002(v0)


funcb2218:	; 800B2218
800B2218	lui    a3, $8006
800B221C	lw     v0, $794c(a3)
800B2220	nop
800B2224	lw     v0, $001c(v0)
800B2228	addu   t3, a0, zero
800B222C	lw     v0, $08e4(v0)
800B2230	andi   a1, a1, $ffff
800B2234	lw     v0, $000c(v0)
800B2238	sll    a2, a2, $10
800B223C	lw     a0, $0014(v0)
800B2240	sra    a2, a2, $10
800B2244	lbu    v1, $004b(a0)
800B2248	lw     t2, $0058(a0)
800B224C	sll    v0, v1, $01
800B2250	addu   v0, v0, v1
800B2254	sll    v0, v0, $02
800B2258	addu   v0, t2, v0
800B225C	addiu  a0, v0, $fff4 (=-$c)
800B2260	addu   t1, a0, zero
800B2264	addiu  t0, v0, $fffa (=-$6)

loopb2268:	; 800B2268
800B2268	lw     v0, $000c(t3)
800B226C	lbu    v1, $0000(a0)
800B2270	lbu    v0, $003b(v0)
800B2274	nop
800B2278	bne    v1, v0, Lb2310 [$800b2310]

Lb227c:	; 800B227C
800B227C	nop
800B2280	lhu    v0, $fffe(t0)
800B2284	nop
800B2288	bne    v0, a1, Lb2310 [$800b2310]
800B228C	nop
800B2290	lh     v0, $0000(t0)
800B2294	nop
800B2298	bne    v0, a2, Lb2310 [$800b2310]
800B229C	nop
800B22A0	beq    a0, t1, Lb22d8 [$800b22d8]
800B22A4	nop
800B22A8	lwl    t4, $0003(t1)
800B22AC	lwr    t4, $0000(t1)
800B22B0	lwl    t5, $0007(t1)
800B22B4	lwr    t5, $0004(t1)
800B22B8	lwl    t6, $000b(t1)
800B22BC	lwr    t6, $0008(t1)
800B22C0	swl    t4, $0003(a0)
800B22C4	swr    t4, $0000(a0)
800B22C8	swl    t5, $0007(a0)
800B22CC	swr    t5, $0004(a0)
800B22D0	swl    t6, $000b(a0)
800B22D4	swr    t6, $0008(a0)

Lb22d8:	; 800B22D8
800B22D8	lw     v0, $794c(a3)
800B22DC	nop
800B22E0	lw     v0, $001c(v0)
800B22E4	nop
800B22E8	lw     v0, $08e4(v0)
800B22EC	nop
800B22F0	lw     v0, $000c(v0)
800B22F4	nop
800B22F8	lw     v1, $0014(v0)
800B22FC	nop
800B2300	lbu    v0, $004b(v1)
800B2304	nop
800B2308	addiu  v0, v0, $ffff (=-$1)
800B230C	sb     v0, $004b(v1)

Lb2310:	; 800B2310
800B2310	addiu  a0, a0, $fff4 (=-$c)
800B2314	sltu   v0, a0, t2
800B2318	beq    v0, zero, loopb2268 [$800b2268]
800B231C	addiu  t0, t0, $fff4 (=-$c)
800B2320	jr     ra 
800B2324	addiu  v0, zero, $ffff (=-$1)


funcb2328:	; 800B2328
800B2328	lui    v0, $8006
800B232C	lw     v0, $794c(v0)
800B2330	nop
800B2334	lw     v0, $001c(v0)
800B2338	nop
800B233C	lw     v1, $07e4(v0)
800B2340	nop
800B2344	lhu    v0, $0002(v1)
800B2348	nop
800B234C	addiu  a1, v0, $ffff (=-$1)
800B2350	bltz   a1, Lb2384 [$800b2384]
800B2354	addiu  v1, v1, $0004
800B2358	sll    v0, a1, $04
800B235C	addu   v1, v0, v1

loopb2360:	; 800B2360
800B2360	lw     v0, $0000(v1)
800B2364	nop
800B2368	bne    v0, a0, Lb237c [$800b237c]
800B236C	addiu  a1, a1, $ffff (=-$1)
800B2370	lw     v0, $000c(v1)
800B2374	jr     ra 
800B2378	nop


Lb237c:	; 800B237C
800B237C	bgez   a1, loopb2360 [$800b2360]
800B2380	addiu  v1, v1, $fff0 (=-$10)

Lb2384:	; 800B2384
800B2384	jr     ra 
800B2388	addiu  v0, zero, $ffff (=-$1)


funcb238c:	; 800B238C
800B238C	lui    v0, $8006
800B2390	lw     a3, $794c(v0)

Lb2394:	; 800B2394
800B2394	nop

Lb2398:	; 800B2398
800B2398	lw     v1, $001c(a3)
800B239C	nop
800B23A0	lw     v0, $08e4(v1)
800B23A4	nop
800B23A8	lw     v0, $000c(v0)
800B23AC	nop
800B23B0	lw     a1, $0014(v0)

funcb23b4:	; 800B23B4
800B23B4	lhu    v0, $081c(v1)
800B23B8	nop
800B23BC	sh     v0, $003c(a1)
800B23C0	lw     a0, $001c(a3)
800B23C4	nop
800B23C8	lw     v0, $08e4(a0)
800B23CC	nop
800B23D0	lw     v0, $000c(v0)
800B23D4	lhu    a1, $000a(a1)
800B23D8	lw     v1, $0014(v0)
800B23DC	lhu    v0, $0820(a0)
800B23E0	addu   a2, zero, zero
800B23E4	sh     v0, $003e(v1)
800B23E8	lw     v0, $001c(a3)
800B23EC	lui    v1, $0011
800B23F0	lw     v0, $07e4(v0)
800B23F4	or     a1, a1, v1
800B23F8	lhu    v1, $0002(v0)
800B23FC	nop
800B2400	beq    v1, zero, Lb24ec [$800b24ec]
800B2404	addiu  t1, v0, $0004
800B2408	addu   t0, a3, zero
800B240C	addiu  t2, zero, $0009
800B2410	addu   a0, t1, zero

loopb2414:	; 800B2414
800B2414	lw     v0, $0000(a0)
800B2418	lw     a3, $000c(a0)
800B241C	bne    v0, a1, Lb24f4 [$800b24f4]
800B2420	lui    v0, $8006
800B2424	sra    v0, a3, $10
800B2428	andi   v0, v0, $00ff
800B242C	addiu  v1, zero, $0007
800B2430	bne    v0, v1, Lb24f4 [$800b24f4]
800B2434	lui    v0, $8006
800B2438	lw     v0, $001c(t0)

Lb243c:	; 800B243C
800B243C	nop

Lb2440:	; 800B2440
800B2440	lw     v0, $08e4(v0)
800B2444	nop
800B2448	lw     v0, $000c(v0)
800B244C	nop
800B2450	lw     v0, $0014(v0)
800B2454	nop
800B2458	sh     a3, $003c(v0)
800B245C	lw     v0, $001c(t0)
800B2460	nop
800B2464	lw     v0, $07e4(v0)
800B2468	nop
800B246C	lhu    v0, $0002(v0)
800B2470	nop
800B2474	beq    v0, zero, Lb24ec [$800b24ec]
800B2478	addu   a2, zero, zero
800B247C	addu   a0, t1, zero

loopb2480:	; 800B2480
800B2480	lw     a1, $000c(a0)
800B2484	lbu    v0, $0002(a0)
800B2488	lw     v1, $0000(a0)
800B248C	bne    v0, t2, Lb24c0 [$800b24c0]
800B2490	lui    v0, $8006
800B2494	bne    a1, a3, Lb24c0 [$800b24c0]
800B2498	nop
800B249C	lw     v0, $001c(t0)
800B24A0	nop
800B24A4	lw     v0, $08e4(v0)
800B24A8	nop
800B24AC	lw     v0, $000c(v0)
800B24B0	nop
800B24B4	lw     v0, $0014(v0)
800B24B8	jr     ra 
800B24BC	sh     v1, $003e(v0)


Lb24c0:	; 800B24C0
800B24C0	lw     v0, $794c(v0)
800B24C4	nop
800B24C8	lw     v0, $001c(v0)
800B24CC	nop
800B24D0	lw     v0, $07e4(v0)
800B24D4	nop
800B24D8	lhu    v0, $0002(v0)
800B24DC	addiu  a2, a2, $0001
800B24E0	slt    v0, a2, v0
800B24E4	bne    v0, zero, loopb2480 [$800b2480]
800B24E8	addiu  a0, a0, $0010

Lb24ec:	; 800B24EC
800B24EC	jr     ra 
800B24F0	nop


Lb24f4:	; 800B24F4
800B24F4	lw     v0, $794c(v0)
800B24F8	nop
800B24FC	lw     v0, $001c(v0)
800B2500	nop
800B2504	lw     v0, $07e4(v0)
800B2508	nop
800B250C	lhu    v0, $0002(v0)
800B2510	addiu  a2, a2, $0001
800B2514	slt    v0, a2, v0
800B2518	bne    v0, zero, loopb2414 [$800b2414]
800B251C	addiu  a0, a0, $0010
800B2520	jr     ra 
800B2524	nop


funcb2528:	; 800B2528
800B2528	addiu  sp, sp, $ff88 (=-$78)

Lb252c:	; 800B252C
800B252C	sw     s1, $005c(sp)
800B2530	addu   s1, zero, zero
800B2534	addiu  a3, zero, $0004
800B2538	addiu  a2, zero, $ffff (=-$1)

funcb253c:	; 800B253C
800B253C	addiu  t1, sp, $0048
800B2540	lui    v0, $8006
800B2544	lw     v0, $794c(v0)
800B2548	addiu  t0, sp, $0050
800B254C	sw     ra, $0070(sp)
800B2550	sw     s5, $006c(sp)
800B2554	sw     s4, $0068(sp)
800B2558	sw     s3, $0064(sp)
800B255C	sw     s2, $0060(sp)
800B2560	sw     s0, $0058(sp)
800B2564	lw     v0, $001c(v0)
800B2568	addiu  a1, sp, $0040
800B256C	lw     v0, $07e4(v0)
800B2570	addiu  a0, sp, $0028
800B2574	addu   t2, v0, a3

loopb2578:	; 800B2578
800B2578	sw     a2, $0000(a0)
800B257C	sw     a2, $0000(a1)
800B2580	addiu  a1, a1, $fffc (=-$4)
800B2584	addiu  a0, a0, $fffc (=-$4)
800B2588	addu   v0, t1, a3
800B258C	addu   v1, t0, a3
800B2590	addiu  a3, a3, $ffff (=-$1)
800B2594	sb     zero, $0000(v0)
800B2598	bgez   a3, loopb2578 [$800b2578]
800B259C	sb     a2, $0000(v1)
800B25A0	lui    v0, $8006
800B25A4	lw     v0, $794c(v0)
800B25A8	nop
800B25AC	lw     v0, $001c(v0)
800B25B0	nop
800B25B4	lw     v0, $07e4(v0)
800B25B8	nop
800B25BC	lhu    v0, $0002(v0)
800B25C0	nop
800B25C4	addiu  a3, v0, $ffff (=-$1)
800B25C8	bltz   a3, Lb2674 [$800b2674]
800B25CC	lui    v0, $800d
800B25D0	addiu  t7, zero, $0009
800B25D4	addiu  t6, zero, $0008
800B25D8	addiu  t5, v0, $9ff8 (=-$6008)
800B25DC	lui    v0, $800d
800B25E0	addiu  t4, v0, $9ff0 (=-$6010)
800B25E4	sll    v0, a3, $04
800B25E8	addu   t1, v0, t2

loopb25ec:	; 800B25EC
800B25EC	lbu    v0, $0002(t1)
800B25F0	lw     t0, $0000(t1)
800B25F4	bne    v0, t7, Lb2668 [$800b2668]
800B25F8	nop
800B25FC	lbu    v0, $000e(t1)
800B2600	nop
800B2604	bne    v0, t6, Lb2668 [$800b2668]
800B2608	addu   t3, zero, zero
800B260C	addiu  t2, zero, $ffff (=-$1)
800B2610	addiu  v1, zero, $0004
800B2614	addiu  a0, t5, $0010

loopb2618:	; 800B2618
800B2618	lw     v0, $0000(a0)
800B261C	nop
800B2620	bne    v0, t0, Lb2634 [$800b2634]
800B2624	addu   v0, v1, t4
800B2628	lb     t2, $0000(v0)
800B262C	j      Lb2640 [$800b2640]
800B2630	addiu  t3, zero, $0001

Lb2634:	; 800B2634
800B2634	addiu  v1, v1, $ffff (=-$1)
800B2638	bgez   v1, loopb2618 [$800b2618]
800B263C	addiu  a0, a0, $fffc (=-$4)

Lb2640:	; 800B2640
800B2640	sll    a0, s1, $02
800B2644	addu   a1, sp, s1
800B2648	addu   a2, a1, zero
800B264C	addu   v0, sp, a0
800B2650	sw     t0, $0018(v0)
800B2654	lw     v1, $0004(t1)
800B2658	addiu  s1, s1, $0001
800B265C	sw     v1, $0030(v0)
800B2660	sb     t3, $0048(a1)
800B2664	sb     t2, $0050(a2)

Lb2668:	; 800B2668
800B2668	addiu  a3, a3, $ffff (=-$1)
800B266C	bgez   a3, loopb25ec [$800b25ec]
800B2670	addiu  t1, t1, $fff0 (=-$10)

Lb2674:	; 800B2674
800B2674	addiu  a3, s1, $ffff (=-$1)
800B2678	bltz   a3, Lb2710 [$800b2710]
800B267C	sll    v0, a3, $02
800B2680	addiu  t3, zero, $0004
800B2684	addiu  t2, zero, $ffff (=-$1)
800B2688	addiu  t1, sp, $0050
800B268C	addu   a2, a3, t1
800B2690	addiu  v1, sp, $0018
800B2694	addu   t0, v0, v1

loopb2698:	; 800B2698
800B2698	lbu    v0, $0003(t0)
800B269C	nop
800B26A0	bne    v0, t3, Lb26fc [$800b26fc]
800B26A4	nop
800B26A8	lb     v0, $0000(a2)
800B26AC	nop
800B26B0	bne    v0, t2, Lb26fc [$800b26fc]
800B26B4	addu   a0, zero, zero

loopb26b8:	; 800B26B8
800B26B8	addiu  v1, s1, $ffff (=-$1)
800B26BC	bltz   v1, Lb26f0 [$800b26f0]
800B26C0	addiu  a1, zero, $0001
800B26C4	addu   v0, t1, v1

loopb26c8:	; 800B26C8
800B26C8	lb     v0, $0000(v0)
800B26CC	nop
800B26D0	bne    v0, a0, Lb26e4 [$800b26e4]
800B26D4	nop
800B26D8	addiu  a0, a0, $0001
800B26DC	j      Lb26f0 [$800b26f0]
800B26E0	addu   a1, zero, zero

Lb26e4:	; 800B26E4
800B26E4	addiu  v1, v1, $ffff (=-$1)
800B26E8	bgez   v1, loopb26c8 [$800b26c8]
800B26EC	addu   v0, t1, v1

Lb26f0:	; 800B26F0
800B26F0	beq    a1, zero, loopb26b8 [$800b26b8]
800B26F4	nop
800B26F8	sb     a0, $0000(a2)

Lb26fc:	; 800B26FC
800B26FC	addiu  a2, a2, $ffff (=-$1)
800B2700	addiu  a3, a3, $ffff (=-$1)
800B2704	bgez   a3, loopb2698 [$800b2698]
800B2708	addiu  t0, t0, $fffc (=-$4)
800B270C	addiu  a3, s1, $ffff (=-$1)

Lb2710:	; 800B2710
800B2710	bltz   a3, Lb2748 [$800b2748]
800B2714	addu   t0, zero, zero
800B2718	addiu  a0, zero, $0004
800B271C	addiu  v1, sp, $0018
800B2720	sll    v0, a3, $02
800B2724	addu   v1, v0, v1

loopb2728:	; 800B2728
800B2728	lbu    v0, $0003(v1)
800B272C	nop
800B2730	bne    v0, a0, Lb273c [$800b273c]
800B2734	nop
800B2738	addiu  t0, t0, $0001

Lb273c:	; 800B273C
800B273C	addiu  a3, a3, $ffff (=-$1)
800B2740	bgez   a3, loopb2728 [$800b2728]
800B2744	addiu  v1, v1, $fffc (=-$4)

Lb2748:	; 800B2748
800B2748	slti   v0, t0, $0002
800B274C	beq    v0, zero, Lb2858 [$800b2858]
800B2750	addiu  a3, zero, $0004
800B2754	addiu  t5, zero, $ffff (=-$1)

Lb2758:	; 800B2758
800B2758	lui    v0, $800d
800B275C	addiu  t6, v0, $9ff0 (=-$6010)
800B2760	addiu  t3, sp, $0050
800B2764	lui    v0, $800d
800B2768	addiu  v0, v0, $9ff8 (=-$6008)
800B276C	addiu  t2, v0, $0010
800B2770	addiu  t4, sp, $0018
800B2774	sll    v0, s1, $02
800B2778	addu   t1, v0, t4

loopb277c:	; 800B277C
800B277C	lw     a2, $0000(t2)
800B2780	nop
800B2784	beq    a2, t5, Lb284c [$800b284c]
800B2788	srl    v1, a2, $18
800B278C	addiu  v0, zero, $0004
800B2790	bne    v1, v0, Lb284c [$800b284c]
800B2794	nop
800B2798	addiu  a1, zero, $ffff (=-$1)
800B279C	addu   v1, s1, a1
800B27A0	bltz   v1, Lb27d0 [$800b27d0]
800B27A4	sll    v0, v1, $02
800B27A8	addu   a0, v0, t4

loopb27ac:	; 800B27AC
800B27AC	lw     v0, $0000(a0)
800B27B0	nop
800B27B4	bne    v0, a2, Lb27c4 [$800b27c4]
800B27B8	nop
800B27BC	j      Lb27d0 [$800b27d0]
800B27C0	addu   a1, a3, zero

Lb27c4:	; 800B27C4
800B27C4	addiu  v1, v1, $ffff (=-$1)
800B27C8	bgez   v1, loopb27ac [$800b27ac]
800B27CC	addiu  a0, a0, $fffc (=-$4)

Lb27d0:	; 800B27D0
800B27D0	bne    a1, t5, Lb284c [$800b284c]
800B27D4	addu   v0, a3, t6
800B27D8	addiu  a0, zero, $ffff (=-$1)
800B27DC	addu   v1, s1, a0
800B27E0	lb     a1, $0000(v0)
800B27E4	bltz   v1, Lb2810 [$800b2810]
800B27E8	addu   v0, t3, v1

loopb27ec:	; 800B27EC
800B27EC	lb     v0, $0000(v0)

Lb27f0:	; 800B27F0
800B27F0	nop
800B27F4	bne    v0, a1, Lb2804 [$800b2804]
800B27F8	nop
800B27FC	j      Lb2810 [$800b2810]
800B2800	addu   a0, v1, zero

Lb2804:	; 800B2804
800B2804	addiu  v1, v1, $ffff (=-$1)
800B2808	bgez   v1, loopb27ec [$800b27ec]
800B280C	addu   v0, t3, v1

Lb2810:	; 800B2810
800B2810	bne    a0, t5, Lb284c [$800b284c]
800B2814	sll    v0, s1, $02
800B2818	sw     a2, $0000(t1)
800B281C	addiu  t1, t1, $0004
800B2820	addu   v1, sp, s1
800B2824	addu   a0, t3, s1
800B2828	addiu  s1, s1, $0001
800B282C	addiu  t0, t0, $0001
800B2830	addu   v0, sp, v0
800B2834	sw     zero, $0030(v0)
800B2838	addiu  v0, zero, $0001
800B283C	sb     v0, $0048(v1)
800B2840	slti   v0, t0, $0002
800B2844	beq    v0, zero, Lb2858 [$800b2858]
800B2848	sb     a1, $0000(a0)

Lb284c:	; 800B284C
800B284C	addiu  a3, a3, $ffff (=-$1)
800B2850	bgez   a3, loopb277c [$800b277c]
800B2854	addiu  t2, t2, $fffc (=-$4)

Lb2858:	; 800B2858
800B2858	addiu  a3, zero, $0004
800B285C	lui    v0, $800d
800B2860	addiu  t1, v0, $9ff0 (=-$6010)
800B2864	addiu  t0, sp, $0050
800B2868	lui    v0, $800d
800B286C	addiu  v0, v0, $9ff8 (=-$6008)
800B2870	addiu  a2, v0, $0010
800B2874	addiu  a1, sp, $0028

loopb2878:	; 800B2878
800B2878	lw     v1, $0000(a1)
800B287C	addiu  a1, a1, $fffc (=-$4)
800B2880	addu   a0, a3, t1
800B2884	addu   v0, t0, a3
800B2888	addiu  a3, a3, $ffff (=-$1)
800B288C	sw     v1, $0000(a2)
800B2890	lbu    v0, $0000(v0)
800B2894	addiu  a2, a2, $fffc (=-$4)
800B2898	bgez   a3, loopb2878 [$800b2878]
800B289C	sb     v0, $0000(a0)
800B28A0	addiu  s3, sp, $0018
800B28A4	addiu  s2, zero, $ffff (=-$1)
800B28A8	addiu  s5, sp, $0048
800B28AC	addiu  s4, sp, $0030

Lb28b0:	; 800B28B0
800B28B0	lui    a2, $7fff
800B28B4	addiu  s0, zero, $ffff (=-$1)
800B28B8	addu   a3, s1, s0
800B28BC	bltz   a3, Lb291c [$800b291c]
800B28C0	ori    a2, a2, $ffff
800B28C4	sll    v0, a3, $02
800B28C8	addu   a1, v0, s4
800B28CC	addu   a0, v0, s3

loopb28d0:	; 800B28D0
800B28D0	lw     v0, $0000(a0)
800B28D4	nop
800B28D8	beq    v0, s2, Lb290c [$800b290c]
800B28DC	addu   v0, s5, a3
800B28E0	lbu    v0, $0000(v0)
800B28E4	nop
800B28E8	bne    v0, zero, Lb290c [$800b290c]
800B28EC	nop
800B28F0	lw     v1, $0000(a1)
800B28F4	nop
800B28F8	slt    v0, v1, a2
800B28FC	beq    v0, zero, Lb290c [$800b290c]
800B2900	nop
800B2904	addu   a2, v1, zero
800B2908	addu   s0, a3, zero

Lb290c:	; 800B290C
800B290C	addiu  a1, a1, $fffc (=-$4)
800B2910	addiu  a3, a3, $ffff (=-$1)
800B2914	bgez   a3, loopb28d0 [$800b28d0]
800B2918	addiu  a0, a0, $fffc (=-$4)

Lb291c:	; 800B291C
800B291C	beq    s0, s2, Lb2978 [$800b2978]
800B2920	sll    v0, s0, $02
800B2924	addu   v0, s3, v0
800B2928	addu   v1, sp, s0
800B292C	lw     a1, $0000(v0)
800B2930	lb     a3, $0050(v1)
800B2934	addiu  a0, zero, $7700
800B2938	sw     zero, $0010(sp)
800B293C	jal    funcb0124 [$800b0124]
800B2940	srl    a2, a1, $18

loopb2944:	; 800B2944
800B2944	sw     zero, $0010(sp)
800B2948	addiu  a0, zero, $0c00
800B294C	addiu  a1, zero, $ffff (=-$1)
800B2950	addu   a2, zero, zero
800B2954	jal    funcb0124 [$800b0124]

Lb2958:	; 800B2958
800B2958	addu   a3, a2, zero
800B295C	bne    v0, zero, loopb2944 [$800b2944]

Lb2960:	; 800B2960
800B2960	sll    v1, s0, $02
800B2964	addu   v0, s3, v1
800B2968	addu   v1, s4, v1

Lb296c:	; 800B296C
800B296C	sw     s2, $0000(v0)
800B2970	j      Lb28b0 [$800b28b0]
800B2974	sw     s2, $0000(v1)

Lb2978:	; 800B2978
800B2978	lw     ra, $0070(sp)
800B297C	lw     s5, $006c(sp)
800B2980	lw     s4, $0068(sp)
800B2984	lw     s3, $0064(sp)

funcb2988:	; 800B2988
800B2988	lw     s2, $0060(sp)
800B298C	lw     s1, $005c(sp)
800B2990	lw     s0, $0058(sp)
800B2994	addu   v0, zero, zero
800B2998	jr     ra 
800B299C	addiu  sp, sp, $0078


funcb29a0:	; 800B29A0
800B29A0	addiu  sp, sp, $ffe8 (=-$18)
800B29A4	lui    v0, $8006
800B29A8	lw     v0, $794c(v0)
800B29AC	addu   v1, a0, zero
800B29B0	sw     ra, $0014(sp)
800B29B4	sw     s0, $0010(sp)
800B29B8	lw     v0, $001c(v0)
800B29BC	addu   s0, a1, zero
800B29C0	lw     a0, $07e4(v0)
800B29C4	jal    func63088 [$80063088]
800B29C8	addu   a1, v1, zero
800B29CC	beq    s0, zero, Lb29e4 [$800b29e4]
800B29D0	addu   v1, v0, zero
800B29D4	lw     v0, $0008(v1)
800B29D8	nop
800B29DC	sll    v0, v0, $0b
800B29E0	sw     v0, $0000(s0)

Lb29e4:	; 800B29E4
800B29E4	lw     v0, $0004(v1)
800B29E8	lw     ra, $0014(sp)
800B29EC	lw     s0, $0010(sp)
800B29F0	jr     ra 
800B29F4	addiu  sp, sp, $0018

800B29F8	addiu  sp, sp, $ffd0 (=-$30)
800B29FC	sw     s2, $0018(sp)
800B2A00	addu   s2, a0, zero
800B2A04	sw     s4, $0020(sp)
800B2A08	addu   s4, zero, zero
800B2A0C	sw     s5, $0024(sp)
800B2A10	lui    s5, $8006
800B2A14	lw     v0, $794c(s5)
800B2A18	lui    a0, $0009
800B2A1C	sw     ra, $0028(sp)
800B2A20	sw     s3, $001c(sp)
800B2A24	sw     s1, $0014(sp)
800B2A28	sw     s0, $0010(sp)
800B2A2C	lw     v0, $001c(v0)
800B2A30	lw     s0, $0008(s2)
800B2A34	lhu    v0, $0852(v0)
800B2A38	lw     v1, $000c(s2)
800B2A3C	nop
800B2A40	bne    v1, zero, Lb2b00 [$800b2b00]
800B2A44	or     s3, v0, a0
800B2A48	addu   a0, s0, zero
800B2A4C	addiu  a1, zero, $0002
800B2A50	lui    a2, $001b
800B2A54	jal    func1c8b0 [$8001c8b0]
800B2A58	addu   a3, s4, zero
800B2A5C	addu   a0, v0, zero
800B2A60	addiu  v0, zero, $ffff (=-$1)
800B2A64	bne    a0, v0, Lb2aa0 [$800b2aa0]
800B2A68	addu   s1, s0, zero
800B2A6C	addu   a0, s0, zero
800B2A70	addiu  a1, zero, $0004
800B2A74	addu   a2, s3, zero
800B2A78	jal    func1c8b0 [$8001c8b0]
800B2A7C	addu   a3, s4, zero
800B2A80	addu   s0, v0, zero
800B2A84	jal    func1ca70 [$8001ca70]
800B2A88	addu   a0, s1, zero
800B2A8C	lw     v1, $794c(s5)
800B2A90	nop
800B2A94	lw     v1, $001c(v1)
800B2A98	j      Lb2b00 [$800b2b00]
800B2A9C	sw     v0, $087c(v1)

Lb2aa0:	; 800B2AA0
800B2AA0	addiu  a1, zero, $0004

Lb2aa4:	; 800B2AA4
800B2AA4	addu   a2, s3, zero
800B2AA8	jal    func1c8b0 [$8001c8b0]
800B2AAC	addu   a3, zero, zero
800B2AB0	addu   s0, v0, zero
800B2AB4	addu   a0, s1, zero
800B2AB8	addiu  a1, zero, $0002
800B2ABC	lui    a2, $001b

Lb2ac0:	; 800B2AC0
800B2AC0	ori    a2, a2, $0001
800B2AC4	jal    func1c8b0 [$8001c8b0]
800B2AC8	addu   a3, zero, zero
800B2ACC	lw     a1, $794c(s5)
800B2AD0	nop
800B2AD4	lw     a0, $001c(a1)
800B2AD8	nop
800B2ADC	lw     v1, $08c0(a0)
800B2AE0	nop
800B2AE4	subu   v0, v0, v1
800B2AE8	sw     v0, $087c(a0)
800B2AEC	lw     v0, $001c(a1)
800B2AF0	lw     a0, $000c(s2)
800B2AF4	lw     v0, $087c(v0)
800B2AF8	jal    funcb1d9c [$800b1d9c]
800B2AFC	subu   a0, v0, a0

Lb2b00:	; 800B2B00
800B2B00	lui    v0, $8006
800B2B04	lw     v0, $794c(v0)
800B2B08	nop
800B2B0C	lw     a2, $001c(v0)
800B2B10	lw     v0, $000c(s2)
800B2B14	lw     v1, $087c(a2)
800B2B18	lw     a0, $0010(s2)
800B2B1C	subu   a1, v1, v0
800B2B20	slt    v0, a0, a1
800B2B24	beq    v0, zero, Lb2b30 [$800b2b30]
800B2B28	nop
800B2B2C	addu   a1, a0, zero

Lb2b30:	; 800B2B30
800B2B30	lw     v0, $0008(s2)
800B2B34	andi   v1, s3, $ffff
800B2B38	addu   v0, v0, a1
800B2B3C	subu   a1, v0, s0
800B2B40	addiu  v0, zero, $0084
800B2B44	beq    v1, v0, Lb2b9c [$800b2b9c]
800B2B48	addu   v0, s4, zero
800B2B4C	lw     v0, $08e4(a2)
800B2B50	nop
800B2B54	lw     v0, $000c(v0)
800B2B58	nop
800B2B5C	lw     v1, $0014(v0)
800B2B60	nop
800B2B64	lw     v0, $0000(v1)
800B2B68	nop
800B2B6C	andi   v0, v0, $0010
800B2B70	beq    v0, zero, Lb2b8c [$800b2b8c]
800B2B74	addu   a0, s0, zero

Lb2b78:	; 800B2B78
800B2B78	lbu    a1, $005e(v1)
800B2B7C	jal    func56048 [$80056048]
800B2B80	addu   a2, zero, zero
800B2B84	j      Lb2b98 [$800b2b98]
800B2B88	addu   s4, v0, zero

Lb2b8c:	; 800B2B8C
800B2B8C	jal    func55e14 [$80055e14]
800B2B90	addu   a2, zero, zero
800B2B94	addu   s4, v0, zero

Lb2b98:	; 800B2B98
800B2B98	addu   v0, s4, zero

Lb2b9c:	; 800B2B9C
800B2B9C	sw     s0, $0008(s2)
800B2BA0	lw     ra, $0028(sp)
800B2BA4	lw     s5, $0024(sp)
800B2BA8	lw     s4, $0020(sp)
800B2BAC	lw     s3, $001c(sp)
800B2BB0	lw     s2, $0018(sp)
800B2BB4	lw     s1, $0014(sp)

Lb2bb8:	; 800B2BB8
800B2BB8	lw     s0, $0010(sp)
800B2BBC	jr     ra 
800B2BC0	addiu  sp, sp, $0030


funcb2bc4:	; 800B2BC4
800B2BC4	addiu  sp, sp, $ffe0 (=-$20)
800B2BC8	sw     s0, $0010(sp)
800B2BCC	addu   s0, a0, zero
800B2BD0	addiu  a1, zero, $0003
800B2BD4	lui    a2, $0007
800B2BD8	addu   a3, zero, zero
800B2BDC	sw     ra, $0018(sp)
800B2BE0	jal    func1c8b0 [$8001c8b0]
800B2BE4	sw     s1, $0014(sp)
800B2BE8	addu   a0, s0, zero
800B2BEC	addiu  a1, zero, $0004
800B2BF0	addu   s1, v0, zero
800B2BF4	addu   a2, s1, zero
800B2BF8	jal    func1c8b0 [$8001c8b0]
800B2BFC	addu   a3, zero, zero
800B2C00	addu   a0, s0, zero
800B2C04	addiu  a1, zero, $0005
800B2C08	addu   a2, s1, zero
800B2C0C	addu   a3, zero, zero
800B2C10	jal    func1c8b0 [$8001c8b0]

Lb2c14:	; 800B2C14
800B2C14	addu   s1, v0, zero
800B2C18	addu   a0, s0, zero
800B2C1C	addu   a1, s1, zero
800B2C20	jal    func15c28 [$80015c28]
800B2C24	addu   a2, v0, zero
800B2C28	lw     ra, $0018(sp)
800B2C2C	lw     s1, $0014(sp)
800B2C30	lw     s0, $0010(sp)
800B2C34	addu   v0, zero, zero
800B2C38	jr     ra 
800B2C3C	addiu  sp, sp, $0020


funcb2c40:	; 800B2C40
800B2C40	lui    v0, $8006
800B2C44	lw     v0, $794c(v0)
800B2C48	addiu  sp, sp, $ffe8 (=-$18)
800B2C4C	sw     ra, $0014(sp)
800B2C50	sw     s0, $0010(sp)
800B2C54	lw     s0, $001c(v0)
800B2C58	bne    a0, zero, Lb2c70 [$800b2c70]
800B2C5C	sb     a0, $0826(s0)
800B2C60	addiu  a0, zero, $ffff (=-$1)
800B2C64	jal    func15c58 [$80015c58]
800B2C68	sh     a1, $0842(s0)
800B2C6C	sw     v0, $08c4(s0)

Lb2c70:	; 800B2C70
800B2C70	lw     ra, $0014(sp)
800B2C74	lw     s0, $0010(sp)
800B2C78	jr     ra 
800B2C7C	addiu  sp, sp, $0018



////////////////////////////////
// funcb2c80
800B2C80-800B2CBC
////////////////////////////////



////////////////////////////////
// funcb2cc0
800B2CC0-800B2D0C
////////////////////////////////



funcb2d10:	; 800B2D10
800B2D10	addiu  sp, sp, $ffb0 (=-$50)
800B2D14	sw     s1, $002c(sp)
800B2D18	lui    s1, $8006
800B2D1C	lw     v0, $794c(s1)
800B2D20	sw     ra, $004c(sp)
800B2D24	sw     fp, $0048(sp)
800B2D28	sw     s7, $0044(sp)
800B2D2C	sw     s6, $0040(sp)
800B2D30	sw     s5, $003c(sp)
800B2D34	sw     s4, $0038(sp)

Lb2d38:	; 800B2D38
800B2D38	sw     s3, $0034(sp)
800B2D3C	sw     s2, $0030(sp)
800B2D40	sw     s0, $0028(sp)
800B2D44	sw     a0, $0050(sp)
800B2D48	sw     a1, $0054(sp)
800B2D4C	lw     v0, $001c(v0)
800B2D50	nop
800B2D54	lw     v0, $08e4(v0)
800B2D58	nop
800B2D5C	lw     v0, $000c(v0)
800B2D60	nop
800B2D64	lw     s0, $0014(v0)
800B2D68	nop
800B2D6C	lw     s5, $001c(s0)
800B2D70	nop
800B2D74	beq    s5, zero, Lb3188 [$800b3188]
800B2D78	nop
800B2D7C	jal    funcb3254 [$800b3254]
800B2D80	addu   a0, s5, zero
800B2D84	beq    v0, zero, Lb3188 [$800b3188]
800B2D88	addu   a0, s5, zero
800B2D8C	sw     zero, $0018(sp)
800B2D90	sw     zero, $001c(sp)
800B2D94	lw     fp, $0054(s0)
800B2D98	jal    funcb3294 [$800b3294]
800B2D9C	addiu  a1, zero, $ffff (=-$1)
800B2DA0	addu   a0, s5, zero
800B2DA4	addiu  a1, sp, $0018
800B2DA8	addiu  a2, sp, $001c
800B2DAC	jal    funcb3300 [$800b3300]
800B2DB0	addu   s7, v0, zero
800B2DB4	lw     t2, $0054(sp)
800B2DB8	nop
800B2DBC	addiu  s6, t2, $ffff (=-$1)
800B2DC0	bltz   s6, Lb30b8 [$800b30b8]
800B2DC4	nop

Lb2dc8:	; 800B2DC8
800B2DC8	lw     t2, $0050(sp)
800B2DCC	sll    v0, s6, $02
800B2DD0	addu   v0, v0, t2

funcb2dd4:	; 800B2DD4
800B2DD4	lw     s1, $0000(v0)
800B2DD8	nop
800B2DDC	beq    s1, zero, Lb30a0 [$800b30a0]
800B2DE0	addu   s3, zero, zero
800B2DE4	lw     v0, $000c(s1)
800B2DE8	addu   a0, s5, zero
800B2DEC	lbu    v1, $003b(v0)
800B2DF0	lw     a1, $0004(s1)
800B2DF4	sll    v0, v1, $02
800B2DF8	addu   v0, v0, v1
800B2DFC	sll    v0, v0, $02
800B2E00	jal    funcb3294 [$800b3294]
800B2E04	addu   s2, fp, v0
800B2E08	addu   a0, s5, zero
800B2E0C	addu   a1, s1, zero
800B2E10	addiu  a2, sp, $0020
800B2E14	lw     v1, $0000(s1)
800B2E18	addu   s0, v0, zero
800B2E1C	jal    funcb3378 [$800b3378]
800B2E20	andi   s4, v1, $0004

Lb2e24:	; 800B2E24
800B2E24	lbu    a0, $0004(s2)
800B2E28	lbu    v1, $0020(sp)
800B2E2C	nop
800B2E30	bne    a0, v1, Lb2e60 [$800b2e60]
800B2E34	addu   t1, v0, zero
800B2E38	lw     v0, $0000(s2)
800B2E3C	nop
800B2E40	andi   v0, v0, $0004
800B2E44	bne    s4, v0, Lb2e60 [$800b2e60]
800B2E48	nop
800B2E4C	lw     v0, $0000(s1)
800B2E50	nop
800B2E54	andi   v0, v0, $0100
800B2E58	bne    v0, zero, Lb2e64 [$800b2e64]
800B2E5C	nop

Lb2e60:	; 800B2E60
800B2E60	addiu  s3, zero, $0001

Lb2e64:	; 800B2E64
800B2E64	beq    s3, zero, Lb3080 [$800b3080]
800B2E68	nop
800B2E6C	lw     v0, $0000(s1)
800B2E70	nop
800B2E74	andi   v0, v0, $0400
800B2E78	bne    v0, zero, Lb2f40 [$800b2f40]
800B2E7C	nop
800B2E80	beq    s0, zero, Lb2e94 [$800b2e94]
800B2E84	addu   a2, zero, zero
800B2E88	lw     a3, $0004(s0)
800B2E8C	j      Lb2e98 [$800b2e98]
800B2E90	nop

Lb2e94:	; 800B2E94
800B2E94	lw     a3, $0004(s7)

Lb2e98:	; 800B2E98
800B2E98	beq    s4, zero, Lb2eb0 [$800b2eb0]
800B2E9C	nop
800B2EA0	lw     v0, $001c(sp)
800B2EA4	nop
800B2EA8	bne    v0, zero, Lb2ed4 [$800b2ed4]
800B2EAC	nop

Lb2eb0:	; 800B2EB0
800B2EB0	beq    t1, zero, Lb2ec4 [$800b2ec4]
800B2EB4	andi   a0, a3, $00ff
800B2EB8	lw     a2, $0004(t1)
800B2EBC	j      Lb2ee0 [$800b2ee0]
800B2EC0	andi   v0, a2, $00ff

Lb2ec4:	; 800B2EC4
800B2EC4	lw     v0, $0018(sp)
800B2EC8	nop
800B2ECC	beq    v0, zero, Lb2edc [$800b2edc]
800B2ED0	nop

Lb2ed4:	; 800B2ED4
800B2ED4	lw     a2, $0004(v0)
800B2ED8	andi   a0, a3, $00ff

Lb2edc:	; 800B2EDC
800B2EDC	andi   v0, a2, $00ff

Lb2ee0:	; 800B2EE0
800B2EE0	addu   a0, a0, v0
800B2EE4	sll    a0, a0, $03
800B2EE8	andi   a0, a0, $00ff
800B2EEC	andi   v0, a3, $ff00
800B2EF0	andi   v1, a2, $ff00
800B2EF4	addu   v0, v0, v1
800B2EF8	sll    v0, v0, $03
800B2EFC	andi   v0, v0, $ff00
800B2F00	or     a0, a0, v0
800B2F04	lui    a1, $00ff
800B2F08	and    v0, a3, a1

Lb2f0c:	; 800B2F0C
800B2F0C	and    v1, a2, a1
800B2F10	addu   v0, v0, v1
800B2F14	sll    v0, v0, $03
800B2F18	and    v0, v0, a1
800B2F1C	or     a0, a0, v0
800B2F20	lui    v0, $0100

funcb2f24:	; 800B2F24
800B2F24	or     a0, a0, v0
800B2F28	sw     a0, $000c(s2)
800B2F2C	sw     a0, $0008(s2)
800B2F30	lw     v0, $0000(s1)
800B2F34	nop
800B2F38	ori    v0, v0, $0100
800B2F3C	sw     v0, $0000(s1)

Lb2f40:	; 800B2F40
800B2F40	beq    s0, zero, Lb2f58 [$800b2f58]
800B2F44	nop
800B2F48	lb     a1, $0002(s0)
800B2F4C	lb     t0, $0003(s0)
800B2F50	j      Lb2f60 [$800b2f60]
800B2F54	nop

Lb2f58:	; 800B2F58
800B2F58	lb     a1, $0002(s7)
800B2F5C	lb     t0, $0003(s7)

Lb2f60:	; 800B2F60
800B2F60	beq    t1, zero, Lb2f78 [$800b2f78]
800B2F64	nop
800B2F68	lb     v0, $0002(t1)
800B2F6C	lb     v1, $0003(t1)
800B2F70	j      Lb2f94 [$800b2f94]
800B2F74	addu   a1, a1, v0

Lb2f78:	; 800B2F78
800B2F78	lw     v1, $0018(sp)
800B2F7C	nop
800B2F80	beq    v1, zero, Lb2f98 [$800b2f98]
800B2F84	nop
800B2F88	lb     v0, $0002(v1)
800B2F8C	lb     v1, $0003(v1)
800B2F90	addu   a1, a1, v0

Lb2f94:	; 800B2F94
800B2F94	addu   t0, t0, v1

Lb2f98:	; 800B2F98
800B2F98	sll    a1, a1, $03
800B2F9C	lui    t2, $8006
800B2FA0	lui    a3, $fff0
800B2FA4	ori    a3, a3, $00ff
800B2FA8	lw     v0, $794c(t2)
800B2FAC	lui    a2, $000f
800B2FB0	lw     v0, $001c(v0)
800B2FB4	lw     v1, $000c(s1)
800B2FB8	lw     v0, $08e4(v0)
800B2FBC	lbu    a0, $003b(v1)
800B2FC0	lw     v1, $000c(v0)
800B2FC4	sll    v0, a0, $02
800B2FC8	lw     v1, $0014(v1)
800B2FCC	addu   v0, v0, a0
800B2FD0	lw     v1, $002c(v1)
800B2FD4	sll    v0, v0, $03
800B2FD8	addu   v0, v0, v1
800B2FDC	sb     a1, $0000(v0)
800B2FE0	lw     a1, $794c(t2)
800B2FE4	ori    a2, a2, $ffff
800B2FE8	lw     v0, $001c(a1)
800B2FEC	lw     v1, $000c(s1)
800B2FF0	lw     v0, $08e4(v0)
800B2FF4	lbu    a0, $003b(v1)
800B2FF8	lw     v0, $000c(v0)
800B2FFC	sll    v1, a0, $02
800B3000	lw     v0, $0014(v0)
800B3004	addu   v1, v1, a0
800B3008	lw     v0, $002c(v0)
800B300C	sll    v1, v1, $03
800B3010	addu   v1, v1, v0
800B3014	sll    v0, t0, $03
800B3018	subu   v0, v0, t0
800B301C	sll    v0, v0, $01
800B3020	andi   v0, v0, $0fff
800B3024	lw     a0, $0000(v1)
800B3028	sll    v0, v0, $08
800B302C	and    a0, a0, a3
800B3030	or     a0, a0, v0
800B3034	sw     a0, $0000(v1)
800B3038	lw     v0, $001c(a1)
800B303C	lw     v1, $000c(s1)
800B3040	lw     v0, $08e4(v0)
800B3044	lbu    a0, $003b(v1)
800B3048	lw     v0, $000c(v0)
800B304C	sll    v1, a0, $02
800B3050	lw     v0, $0014(v0)
800B3054	addu   v1, v1, a0
800B3058	lw     v0, $002c(v0)
800B305C	sll    v1, v1, $03

Lb3060:	; 800B3060
800B3060	addu   v1, v1, v0
800B3064	sll    v0, t0, $01
800B3068	addu   v0, v0, t0
800B306C	lw     a0, $0000(v1)
800B3070	sll    v0, v0, $16
800B3074	and    a0, a0, a2
800B3078	or     a0, a0, v0
800B307C	sw     a0, $0000(v1)

Lb3080:	; 800B3080
800B3080	lbu    v0, $0020(sp)
800B3084	nop
800B3088	sb     v0, $0004(s2)
800B308C	lw     v0, $0000(s2)

funcb3090:	; 800B3090
800B3090	addiu  v1, zero, $fffb (=-$5)
800B3094	and    v0, v0, v1
800B3098	or     v0, v0, s4
800B309C	sw     v0, $0000(s2)

Lb30a0:	; 800B30A0
800B30A0	addiu  s6, s6, $ffff (=-$1)
800B30A4	bgez   s6, Lb2dc8 [$800b2dc8]
800B30A8	nop
800B30AC	lw     t2, $0054(sp)
800B30B0	nop
800B30B4	addiu  s6, t2, $ffff (=-$1)

Lb30b8:	; 800B30B8
800B30B8	bltz   s6, Lb3188 [$800b3188]
800B30BC	sll    v0, s6, $02
800B30C0	lw     t2, $0050(sp)
800B30C4	nop
800B30C8	addu   s7, v0, t2

loopb30cc:	; 800B30CC
800B30CC	lw     s1, $0000(s7)
800B30D0	nop
800B30D4	beq    s1, zero, Lb317c [$800b317c]
800B30D8	nop
800B30DC	lw     v0, $000c(s1)
800B30E0	nop
800B30E4	lbu    v1, $003b(v0)
800B30E8	nop
800B30EC	sll    v0, v1, $02
800B30F0	addu   v0, v0, v1
800B30F4	sll    v0, v0, $02
800B30F8	addu   s2, fp, v0
800B30FC	lw     v1, $0008(s2)
800B3100	nop
800B3104	sra    v0, v1, $18
800B3108	beq    v0, zero, Lb317c [$800b317c]
800B310C	nop
800B3110	lw     v0, $0008(s1)
800B3114	nop
800B3118	lw     v0, $0008(v0)
800B311C	nop
800B3120	lbu    v0, $0003(v0)

Lb3124:	; 800B3124
800B3124	nop
800B3128	addiu  s0, v0, $ffff (=-$1)
800B312C	bltz   s0, Lb3170 [$800b3170]
800B3130	andi   v0, v1, $00ff
800B3134	sll    s5, v0, $10
800B3138	sra    v0, v1, $08
800B313C	andi   v0, v0, $00ff
800B3140	sll    s4, v0, $10
800B3144	srl    v0, v1, $10
800B3148	andi   s3, v0, $00ff
800B314C	andi   a1, s0, $00ff

loopb3150:	; 800B3150
800B3150	sra    a2, s5, $10
800B3154	addiu  s0, s0, $ffff (=-$1)
800B3158	sw     s3, $0010(sp)

Lb315c:	; 800B315C
800B315C	lw     a0, $0008(s1)
800B3160	jal    funcb9e4c [$800b9e4c]
800B3164	sra    a3, s4, $10
800B3168	bgez   s0, loopb3150 [$800b3150]
800B316C	andi   a1, s0, $00ff

Lb3170:	; 800B3170
800B3170	lw     v0, $000c(s2)
800B3174	sw     zero, $000c(s2)

Lb3178:	; 800B3178
800B3178	sw     v0, $0008(s2)

Lb317c:	; 800B317C
800B317C	addiu  s6, s6, $ffff (=-$1)
800B3180	bgez   s6, loopb30cc [$800b30cc]
800B3184	addiu  s7, s7, $fffc (=-$4)

Lb3188:	; 800B3188
800B3188	lw     ra, $004c(sp)
800B318C	lw     fp, $0048(sp)
800B3190	lw     s7, $0044(sp)
800B3194	lw     s6, $0040(sp)
800B3198	lw     s5, $003c(sp)
800B319C	lw     s4, $0038(sp)
800B31A0	lw     s3, $0034(sp)
800B31A4	lw     s2, $0030(sp)
800B31A8	lw     s1, $002c(sp)
800B31AC	lw     s0, $0028(sp)
800B31B0	jr     ra 
800B31B4	addiu  sp, sp, $0050



////////////////////////////////
// funcb31b8
800B31B8-800B3250
////////////////////////////////



funcb3254:	; 800B3254
800B3254	beq    a0, zero, Lb328c [$800b328c]
800B3258	nop
800B325C	lbu    v0, $0009(a0)
800B3260	nop
800B3264	beq    v0, zero, Lb328c [$800b328c]
800B3268	nop
800B326C	lbu    v1, $0006(a0)
800B3270	nop
800B3274	sll    v0, v1, $01
800B3278	addu   v0, v0, v1
800B327C	sll    v0, v0, $02
800B3280	addiu  v0, v0, $000c
800B3284	jr     ra 
800B3288	addu   v0, a0, v0


Lb328c:	; 800B328C
800B328C	jr     ra 
800B3290	addu   v0, zero, zero


funcb3294:	; 800B3294
800B3294	lbu    v0, $0009(a0)
800B3298	nop
800B329C	beq    v0, zero, Lb32f0 [$800b32f0]
800B32A0	andi   a1, a1, $ffff
800B32A4	lbu    v0, $0006(a0)
800B32A8	andi   a1, a1, $ffff
800B32AC	sll    v1, v0, $01
800B32B0	addu   v1, v1, v0
800B32B4	sll    v1, v1, $02
800B32B8	addiu  v1, v1, $000c
800B32BC	lbu    v0, $0009(a0)
800B32C0	addu   a0, a0, v1
800B32C4	sll    v0, v0, $03
800B32C8	addu   v0, a0, v0
800B32CC	addiu  v1, v0, $fff8 (=-$8)

loopb32d0:	; 800B32D0
800B32D0	lhu    v0, $0000(v1)
800B32D4	nop
800B32D8	beq    v0, a1, Lb32f8 [$800b32f8]
800B32DC	nop
800B32E0	addiu  v1, v1, $fff8 (=-$8)
800B32E4	sltu   v0, v1, a0

Lb32e8:	; 800B32E8
800B32E8	beq    v0, zero, loopb32d0 [$800b32d0]
800B32EC	nop

Lb32f0:	; 800B32F0
800B32F0	jr     ra 
800B32F4	addu   v0, zero, zero


Lb32f8:	; 800B32F8
800B32F8	jr     ra 
800B32FC	addu   v0, v1, zero


funcb3300:	; 800B3300
800B3300	sw     zero, $0000(a1)
800B3304	sw     zero, $0000(a2)
800B3308	lbu    v0, $0007(a0)
800B330C	nop
800B3310	bne    v0, zero, Lb3320 [$800b3320]
800B3314	addiu  a3, a0, $000c
800B3318	jr     ra 
800B331C	addu   v0, zero, zero


Lb3320:	; 800B3320
800B3320	addiu  t1, zero, $0001
800B3324	lbu    v1, $0007(a0)
800B3328	addiu  t0, zero, $0002
800B332C	sllv   v0, t1, v1
800B3330	addu   v0, v0, v1
800B3334	sllv   v0, t0, v0
800B3338	addu   a0, a0, v0

loopb333c:	; 800B333C
800B333C	lb     v0, $0000(a0)
800B3340	nop
800B3344	bne    v0, t1, Lb3354 [$800b3354]
800B3348	nop
800B334C	j      Lb3360 [$800b3360]
800B3350	sw     a0, $0000(a1)

Lb3354:	; 800B3354
800B3354	bne    v0, t0, Lb3360 [$800b3360]
800B3358	nop
800B335C	sw     a0, $0000(a2)

Lb3360:	; 800B3360
800B3360	addiu  a0, a0, $fff4 (=-$c)
800B3364	sltu   v0, a0, a3
800B3368	beq    v0, zero, loopb333c [$800b333c]
800B336C	addu   v0, a3, zero
800B3370	jr     ra 
800B3374	nop


funcb3378:	; 800B3378
800B3378	addiu  sp, sp, $ffd8 (=-$28)
800B337C	sw     s0, $0018(sp)
800B3380	addu   s0, a0, zero
800B3384	sw     s1, $001c(sp)
800B3388	addu   s1, a2, zero
800B338C	sw     ra, $0020(sp)
800B3390	lw     v0, $000c(a1)
800B3394	nop
800B3398	lbu    a0, $003b(v0)
800B339C	jal    funcc76e8 [$800c76e8]
800B33A0	addiu  a1, sp, $0010
800B33A4	lbu    v0, $0007(s0)
800B33A8	nop
800B33AC	beq    v0, zero, Lb342c [$800b342c]
800B33B0	addiu  v0, zero, $00ff
800B33B4	lbu    v1, $0000(s1)
800B33B8	nop
800B33BC	bne    v1, v0, Lb33d4 [$800b33d4]
800B33C0	addiu  a3, s0, $000c

Lb33c4:	; 800B33C4
800B33C4	j      Lb3430 [$800b3430]
800B33C8	addu   v0, zero, zero

loopb33cc:	; 800B33CC
800B33CC	j      Lb3430 [$800b3430]
800B33D0	addu   v0, a0, zero

Lb33d4:	; 800B33D4
800B33D4	lbu    v1, $0007(s0)
800B33D8	nop
800B33DC	sll    v0, v1, $01
800B33E0	addu   v0, v0, v1
800B33E4	sll    v0, v0, $02
800B33E8	addu   a0, s0, v0

loopb33ec:	; 800B33EC
800B33EC	lb     v0, $0000(a0)
800B33F0	nop
800B33F4	bne    v0, zero, Lb341c [$800b341c]
800B33F8	nop
800B33FC	addiu  a1, zero, $0003
800B3400	lw     v1, $0008(a0)
800B3404	lh     a2, $0000(s1)

loopb3408:	; 800B3408
800B3408	andi   v0, v1, $00ff
800B340C	beq    v0, a2, loopb33cc [$800b33cc]
800B3410	addiu  a1, a1, $ffff (=-$1)
800B3414	bgez   a1, loopb3408 [$800b3408]
800B3418	sra    v1, v1, $08

Lb341c:	; 800B341C
800B341C	addiu  a0, a0, $fff4 (=-$c)
800B3420	sltu   v0, a0, a3
800B3424	beq    v0, zero, loopb33ec [$800b33ec]
800B3428	nop

Lb342c:	; 800B342C
800B342C	addu   v0, zero, zero

Lb3430:	; 800B3430
800B3430	lw     ra, $0020(sp)
800B3434	lw     s1, $001c(sp)
800B3438	lw     s0, $0018(sp)
800B343C	jr     ra 
800B3440	addiu  sp, sp, $0028


funcb3444:	; 800B3444
800B3444	addiu  sp, sp, $ffe0 (=-$20)
800B3448	sw     ra, $001c(sp)
800B344C	sw     s2, $0018(sp)
800B3450	sw     s1, $0014(sp)
800B3454	bne    a0, zero, Lb3668 [$800b3668]
800B3458	sw     s0, $0010(sp)
800B345C	bne    a1, zero, Lb3668 [$800b3668]

funcb3460:	; 800B3460
800B3460	nop
800B3464	beq    a2, zero, Lb362c [$800b362c]
800B3468	lui    s0, $8006
800B346C	lw     v0, $794c(s0)
800B3470	nop
800B3474	lw     v0, $001c(v0)
800B3478	nop
800B347C	lw     v0, $08e4(v0)
800B3480	nop
800B3484	lw     v0, $000c(v0)
800B3488	nop
800B348C	lw     a0, $0014(v0)
800B3490	nop
800B3494	lw     v0, $0000(a0)
800B3498	nop
800B349C	andi   v0, v0, $0100
800B34A0	bne    v0, zero, Lb35f0 [$800b35f0]
800B34A4	lui    v0, $8006
800B34A8	lw     s1, $0020(a0)
800B34AC	nop
800B34B0	bne    s1, zero, Lb34c8 [$800b34c8]
800B34B4	addu   a0, s1, zero
800B34B8	lui    v0, $8006
800B34BC	lw     s1, $7948(v0)
800B34C0	nop
800B34C4	addu   a0, s1, zero

Lb34c8:	; 800B34C8
800B34C8	jal    func221c0 [$800221c0]
800B34CC	addiu  a1, zero, $5000
800B34D0	beq    v0, zero, Lb34ec [$800b34ec]
800B34D4	nop
800B34D8	jal    func2208c [$8002208c]
800B34DC	nop
800B34E0	lw     a0, $0004(v0)
800B34E4	jal    func22390 [$80022390]
800B34E8	nop

Lb34ec:	; 800B34EC
800B34EC	lw     v0, $794c(s0)
800B34F0	nop
800B34F4	lw     v0, $001c(v0)
800B34F8	nop
800B34FC	lw     v0, $08e4(v0)
800B3500	nop
800B3504	lw     v0, $000c(v0)
800B3508	nop
800B350C	lw     v0, $0014(v0)
800B3510	nop
800B3514	lw     a0, $0020(v0)
800B3518	nop
800B351C	beq    a0, zero, Lb3584 [$800b3584]
800B3520	nop
800B3524	jal    func50be0 [$80050be0]
800B3528	addu   s1, a0, zero
800B352C	lw     a0, $794c(s0)
800B3530	nop
800B3534	lw     v1, $001c(a0)
800B3538	nop
800B353C	lw     v1, $08e4(v1)
800B3540	nop
800B3544	lw     v1, $000c(v1)
800B3548	nop
800B354C	lw     v1, $0014(v1)
800B3550	nop
800B3554	sw     v0, $0020(v1)
800B3558	lw     v0, $001c(a0)
800B355C	nop
800B3560	lw     v0, $08e4(v0)
800B3564	nop
800B3568	lw     v0, $000c(v0)
800B356C	nop
800B3570	lw     v0, $0014(v0)
800B3574	nop
800B3578	lw     v0, $0020(v0)
800B357C	j      Lb359c [$800b359c]
800B3580	subu   s2, v0, s1

Lb3584:	; 800B3584
800B3584	lui    s0, $8006
800B3588	lw     s1, $7948(s0)
800B358C	jal    func50be0 [$80050be0]
800B3590	addu   a0, s1, zero
800B3594	subu   s2, v0, s1
800B3598	sw     v0, $7948(s0)

Lb359c:	; 800B359C
800B359C	jal    funcac620 [$800ac620]
800B35A0	nop
800B35A4	addu   a0, s1, zero
800B35A8	jal    func22280 [$80022280]
800B35AC	addu   a1, s2, zero
800B35B0	lui    v0, $8006
800B35B4	lw     v0, $794c(v0)
800B35B8	nop
800B35BC	lw     v0, $001c(v0)
800B35C0	nop
800B35C4	lw     v0, $08e4(v0)
800B35C8	nop
800B35CC	lw     v0, $000c(v0)
800B35D0	nop
800B35D4	lw     v1, $0014(v0)
800B35D8	nop
800B35DC	lw     v0, $0000(v1)
800B35E0	nop
800B35E4	ori    v0, v0, $0100
800B35E8	sw     v0, $0000(v1)
800B35EC	lui    v0, $8006

Lb35f0:	; 800B35F0
800B35F0	lw     v0, $794c(v0)
800B35F4	nop
800B35F8	lw     v0, $001c(v0)
800B35FC	nop
800B3600	lw     v0, $08e4(v0)
800B3604	nop
800B3608	lw     v0, $000c(v0)
800B360C	nop
800B3610	lw     v1, $0014(v0)
800B3614	nop
800B3618	lw     v0, $0000(v1)
800B361C	nop
800B3620	ori    v0, v0, $0200
800B3624	j      Lb3668 [$800b3668]
800B3628	sw     v0, $0000(v1)

Lb362c:	; 800B362C
800B362C	lui    v0, $8006
800B3630	lw     v0, $794c(v0)
800B3634	nop
800B3638	lw     v0, $001c(v0)
800B363C	nop
800B3640	lw     v0, $08e4(v0)
800B3644	nop
800B3648	lw     v0, $000c(v0)
800B364C	nop
800B3650	lw     a0, $0014(v0)
800B3654	nop
800B3658	lw     v0, $0000(a0)
800B365C	addiu  v1, zero, $fdff (=-$201)
800B3660	and    v0, v0, v1
800B3664	sw     v0, $0000(a0)

Lb3668:	; 800B3668
800B3668	lw     ra, $001c(sp)
800B366C	lw     s2, $0018(sp)
800B3670	lw     s1, $0014(sp)
800B3674	lw     s0, $0010(sp)
800B3678	addu   v0, zero, zero
800B367C	jr     ra 
800B3680	addiu  sp, sp, $0020


funcb3684:	; 800B3684
800B3684	lui    v0, $8006
800B3688	lw     v0, $794c(v0)
800B368C	addiu  sp, sp, $ffe8 (=-$18)
800B3690	sw     ra, $0010(sp)
800B3694	lw     v0, $001c(v0)
800B3698	nop
800B369C	lw     v0, $08e4(v0)
800B36A0	nop
800B36A4	lw     v0, $000c(v0)
800B36A8	nop
800B36AC	lw     v0, $0014(v0)
800B36B0	nop
800B36B4	lw     v0, $0000(v0)
800B36B8	nop
800B36BC	andi   v0, v0, $0200
800B36C0	beq    v0, zero, Lb36d0 [$800b36d0]
800B36C4	nop
800B36C8	jal    func50aac [$80050aac]
800B36CC	nop

Lb36d0:	; 800B36D0
800B36D0	lw     ra, $0010(sp)
800B36D4	nop
800B36D8	jr     ra 
800B36DC	addiu  sp, sp, $0018

800B36E0	addiu  sp, sp, $ffe0 (=-$20)
800B36E4	addu   v1, a0, zero
800B36E8	sw     s2, $0018(sp)
800B36EC	addu   s2, zero, zero
800B36F0	sll    v0, a0, $18
800B36F4	sw     ra, $001c(sp)
800B36F8	sw     s1, $0014(sp)
800B36FC	bgez   v0, Lb370c [$800b370c]
800B3700	sw     s0, $0010(sp)
800B3704	addiu  v1, a0, $ff80 (=-$80)
800B3708	addiu  s2, zero, $0001

Lb370c:	; 800B370C
800B370C	andi   v1, v1, $00ff
800B3710	addiu  v0, zero, $0005
800B3714	beq    v1, v0, Lb3818 [$800b3818]
800B3718	addiu  v0, zero, $0011
800B371C	bne    v1, v0, Lb3a68 [$800b3a68]
800B3720	addiu  v0, zero, $ffff (=-$1)
800B3724	lui    s0, $0001
800B3728	beq    s2, zero, Lb3744 [$800b3744]
800B372C	ori    s0, s0, $000b
800B3730	lui    a0, $0001
800B3734	jal    funcb3d10 [$800b3d10]
800B3738	ori    a0, a0, $000b
800B373C	bne    v0, zero, Lb3a68 [$800b3a68]
800B3740	addiu  v0, zero, $ffff (=-$1)

Lb3744:	; 800B3744
800B3744	lui    a0, $0001
800B3748	jal    funcb3bd8 [$800b3bd8]
800B374C	ori    a0, a0, $000b
800B3750	bne    v0, zero, Lb3a68 [$800b3a68]
800B3754	addiu  v0, zero, $ffff (=-$1)
800B3758	lui    a0, $0001
800B375C	jal    func21e5c [$80021e5c]
800B3760	ori    a0, a0, $000b
800B3764	bne    v0, zero, Lb3a68 [$800b3a68]
800B3768	addiu  v0, zero, $ffff (=-$1)
800B376C	beq    s2, zero, Lb3784 [$800b3784]
800B3770	lui    a0, $0001
800B3774	jal    funcb3de4 [$800b3de4]
800B3778	ori    a0, a0, $000b
800B377C	j      Lb3790 [$800b3790]
800B3780	lui    v0, $8006

Lb3784:	; 800B3784
800B3784	jal    funcb3cac [$800b3cac]
800B3788	ori    a0, a0, $000b
800B378C	lui    v0, $8006

Lb3790:	; 800B3790
800B3790	lw     v0, $794c(v0)
800B3794	nop
800B3798	lw     v0, $001c(v0)
800B379C	nop
800B37A0	lw     v0, $08e4(v0)
800B37A4	nop
800B37A8	lw     v0, $000c(v0)
800B37AC	nop
800B37B0	lw     v0, $0014(v0)
800B37B4	nop
800B37B8	lw     v0, $0000(v0)
800B37BC	lui    v1, $0010
800B37C0	and    v0, v0, v1
800B37C4	beq    v0, zero, Lb3a30 [$800b3a30]
800B37C8	lui    v0, $8006
800B37CC	jal    func21e20 [$80021e20]
800B37D0	nop
800B37D4	addu   a0, v0, zero
800B37D8	beq    a0, zero, Lb37f8 [$800b37f8]
800B37DC	nop
800B37E0	lw     v0, $0004(a0)
800B37E4	nop
800B37E8	beq    v0, s0, Lb37f8 [$800b37f8]
800B37EC	nop
800B37F0	jal    func21c20 [$80021c20]
800B37F4	nop

Lb37f8:	; 800B37F8
800B37F8	bne    s2, zero, Lb39f4 [$800b39f4]
800B37FC	lui    v0, $8006
800B3800	jal    func21e5c [$80021e5c]
800B3804	addu   a0, s0, zero
800B3808	bne    v0, zero, Lb39f4 [$800b39f4]
800B380C	lui    v0, $8006
800B3810	j      Lb39b8 [$800b39b8]
800B3814	nop

Lb3818:	; 800B3818
800B3818	andi   v0, a1, $ffff
800B381C	lui    v1, $0005
800B3820	or     s1, v0, v1
800B3824	sltiu  v0, v0, $2328
800B3828	bne    v0, zero, Lb3838 [$800b3838]
800B382C	lui    v0, $8006

loopb3830:	; 800B3830
800B3830	j      Lb3a68 [$800b3a68]
800B3834	addiu  v0, zero, $ffff (=-$1)

Lb3838:	; 800B3838
800B3838	lw     v0, $794c(v0)
800B383C	nop
800B3840	lw     v0, $001c(v0)
800B3844	nop
800B3848	lw     a0, $07e4(v0)
800B384C	jal    func63088 [$80063088]
800B3850	addu   a1, s1, zero
800B3854	beq    v0, zero, loopb3830 [$800b3830]
800B3858	nop
800B385C	lw     v0, $0008(v0)
800B3860	nop
800B3864	beq    v0, zero, Lb3a68 [$800b3a68]
800B3868	addiu  v0, zero, $ffff (=-$1)
800B386C	beq    s2, zero, Lb3884 [$800b3884]
800B3870	nop
800B3874	jal    funcb3d10 [$800b3d10]
800B3878	addu   a0, s1, zero
800B387C	bne    v0, zero, Lb3a68 [$800b3a68]
800B3880	addiu  v0, zero, $ffff (=-$1)

Lb3884:	; 800B3884
800B3884	jal    funcb3bd8 [$800b3bd8]
800B3888	addu   a0, s1, zero
800B388C	bne    v0, zero, Lb3a68 [$800b3a68]
800B3890	addiu  v0, zero, $ffff (=-$1)
800B3894	jal    func21e5c [$80021e5c]
800B3898	addu   a0, s1, zero
800B389C	addu   s0, v0, zero
800B38A0	beq    s0, zero, Lb38f0 [$800b38f0]
800B38A4	nop
800B38A8	lhu    v0, $0002(s0)
800B38AC	nop
800B38B0	bne    v0, zero, Lb38f0 [$800b38f0]
800B38B4	nop
800B38B8	jal    func21a1c [$80021a1c]
800B38BC	addu   a0, s0, zero
800B38C0	bne    v0, zero, Lb3a68 [$800b3a68]
800B38C4	addiu  v0, zero, $ffff (=-$1)
800B38C8	jal    func21a1c [$80021a1c]
800B38CC	addu   a0, s0, zero
800B38D0	bne    v0, zero, Lb38f0 [$800b38f0]
800B38D4	nop
800B38D8	lw     v0, $001c(s0)
800B38DC	lw     v1, $000c(s0)
800B38E0	sra    v0, v0, $02
800B38E4	slt    v0, v0, v1
800B38E8	bne    v0, zero, Lb3a68 [$800b3a68]
800B38EC	addiu  v0, zero, $ffff (=-$1)

Lb38f0:	; 800B38F0
800B38F0	bne    s2, zero, Lb3908 [$800b3908]
800B38F4	addu   a0, s1, zero
800B38F8	jal    funcb3cac [$800b3cac]
800B38FC	addu   a0, s1, zero
800B3900	lui    a0, $0001
800B3904	ori    a0, a0, $000b

Lb3908:	; 800B3908
800B3908	jal    funcb3de4 [$800b3de4]
800B390C	nop
800B3910	lui    v0, $8006
800B3914	lw     v0, $794c(v0)
800B3918	nop
800B391C	lw     v0, $001c(v0)
800B3920	nop
800B3924	lw     v0, $08e4(v0)
800B3928	nop
800B392C	lw     v0, $000c(v0)
800B3930	nop
800B3934	lw     v0, $0014(v0)
800B3938	nop
800B393C	lw     v0, $0000(v0)
800B3940	lui    v1, $0010
800B3944	and    v0, v0, v1
800B3948	beq    v0, zero, Lb3a30 [$800b3a30]
800B394C	lui    v0, $8006
800B3950	jal    func21e20 [$80021e20]
800B3954	nop
800B3958	addu   s0, v0, zero
800B395C	beq    s0, zero, Lb398c [$800b398c]
800B3960	nop
800B3964	lw     v0, $0004(s0)
800B3968	nop
800B396C	beq    v0, s1, Lb398c [$800b398c]
800B3970	nop
800B3974	jal    func21a1c [$80021a1c]
800B3978	addu   a0, s0, zero
800B397C	beq    v0, zero, Lb398c [$800b398c]
800B3980	nop
800B3984	jal    func21c20 [$80021c20]
800B3988	addu   a0, s0, zero

Lb398c:	; 800B398C
800B398C	jal    func21e5c [$80021e5c]
800B3990	addu   a0, s1, zero
800B3994	bne    s2, zero, Lb39f0 [$800b39f0]
800B3998	nop
800B399C	beq    v0, zero, Lb39b4 [$800b39b4]
800B39A0	nop
800B39A4	lhu    v0, $0002(v0)
800B39A8	nop
800B39AC	beq    v0, zero, Lb39f4 [$800b39f4]
800B39B0	lui    v0, $8006

Lb39b4:	; 800B39B4
800B39B4	lui    v0, $8006

Lb39b8:	; 800B39B8
800B39B8	lw     v0, $794c(v0)
800B39BC	nop
800B39C0	lw     v0, $001c(v0)
800B39C4	nop
800B39C8	lw     v0, $08e4(v0)
800B39CC	nop
800B39D0	lw     v0, $000c(v0)
800B39D4	nop
800B39D8	lw     a0, $0014(v0)
800B39DC	lui    v1, $ffef
800B39E0	lw     v0, $0000(a0)
800B39E4	ori    v1, v1, $ffff
800B39E8	and    v0, v0, v1
800B39EC	sw     v0, $0000(a0)

Lb39f0:	; 800B39F0
800B39F0	lui    v0, $8006

Lb39f4:	; 800B39F4
800B39F4	lw     v0, $794c(v0)
800B39F8	nop
800B39FC	lw     v0, $001c(v0)
800B3A00	nop
800B3A04	lw     v0, $08e4(v0)
800B3A08	nop
800B3A0C	lw     v0, $000c(v0)
800B3A10	nop
800B3A14	lw     a0, $0014(v0)
800B3A18	nop
800B3A1C	lw     v0, $0000(a0)
800B3A20	lui    v1, $0080
800B3A24	or     v0, v0, v1
800B3A28	sw     v0, $0000(a0)
800B3A2C	lui    v0, $8006

Lb3a30:	; 800B3A30
800B3A30	lw     v0, $794c(v0)
800B3A34	nop
800B3A38	lw     v0, $001c(v0)
800B3A3C	nop
800B3A40	lw     v0, $08e4(v0)
800B3A44	nop
800B3A48	lw     v0, $000c(v0)
800B3A4C	nop
800B3A50	lw     a1, $0014(v0)
800B3A54	lui    a0, $0020
800B3A58	lw     v1, $0000(a1)
800B3A5C	addu   v0, zero, zero
800B3A60	or     v1, v1, a0
800B3A64	sw     v1, $0000(a1)

Lb3a68:	; 800B3A68
800B3A68	lw     ra, $001c(sp)
800B3A6C	lw     s2, $0018(sp)
800B3A70	lw     s1, $0014(sp)
800B3A74	lw     s0, $0010(sp)
800B3A78	jr     ra 
800B3A7C	addiu  sp, sp, $0020


funcb3a80:	; 800B3A80
800B3A80	addiu  sp, sp, $ffe8 (=-$18)
800B3A84	sw     ra, $0010(sp)
800B3A88	jal    func21c60 [$80021c60]
800B3A8C	nop
800B3A90	lui    v0, $8006
800B3A94	lw     v1, $794c(v0)
800B3A98	lui    v0, $800b
800B3A9C	addiu  v0, v0, $36e0
800B3AA0	lui    a0, $800b
800B3AA4	lw     v1, $001c(v1)
800B3AA8	addiu  a0, a0, $4894
800B3AAC	jal    func21cdc [$80021cdc]
800B3AB0	sw     v0, $08bc(v1)
800B3AB4	jal    funcb3acc [$800b3acc]
800B3AB8	nop
800B3ABC	lw     ra, $0010(sp)
800B3AC0	nop
800B3AC4	jr     ra 
800B3AC8	addiu  sp, sp, $0018


funcb3acc:	; 800B3ACC
800B3ACC	lui    v0, $800d
800B3AD0	sb     zero, $a050(v0)
800B3AD4	addiu  v1, zero, $0007
800B3AD8	addiu  a0, zero, $ffff (=-$1)
800B3ADC	lui    v0, $800d
800B3AE0	addiu  v0, v0, $a010 (=-$5ff0)
800B3AE4	addiu  v0, v0, $001c

loopb3ae8:	; 800B3AE8
800B3AE8	sw     a0, $0000(v0)
800B3AEC	addiu  v1, v1, $ffff (=-$1)
800B3AF0	bgez   v1, loopb3ae8 [$800b3ae8]
800B3AF4	addiu  v0, v0, $fffc (=-$4)
800B3AF8	lui    v0, $800d
800B3AFC	sb     zero, $a051(v0)
800B3B00	addiu  v1, zero, $0007
800B3B04	addiu  a0, zero, $ffff (=-$1)
800B3B08	lui    v0, $800d
800B3B0C	addiu  v0, v0, $a030 (=-$5fd0)
800B3B10	addiu  v0, v0, $001c

loopb3b14:	; 800B3B14
800B3B14	sw     a0, $0000(v0)
800B3B18	addiu  v1, v1, $ffff (=-$1)
800B3B1C	bgez   v1, loopb3b14 [$800b3b14]
800B3B20	addiu  v0, v0, $fffc (=-$4)
800B3B24	jr     ra 
800B3B28	nop


funcb3b2c:	; 800B3B2C
800B3B2C	beq    a0, zero, Lb3b38 [$800b3b38]
800B3B30	lui    v0, $800d
800B3B34	sw     a0, $9d58(v0)

Lb3b38:	; 800B3B38
800B3B38	jr     ra 
800B3B3C	nop


funcb3b40:	; 800B3B40
800B3B40	addiu  sp, sp, $ffe8 (=-$18)
800B3B44	lui    a0, $0001
800B3B48	sw     ra, $0010(sp)
800B3B4C	jal    funcb3bd8 [$800b3bd8]
800B3B50	ori    a0, a0, $000b
800B3B54	lw     ra, $0010(sp)
800B3B58	sltu   v0, zero, v0

funcb3b5c:	; 800B3B5C
800B3B5C	jr     ra 
800B3B60	addiu  sp, sp, $0018


funcb3b64:	; 800B3B64
800B3B64	addiu  sp, sp, $ffe8 (=-$18)
800B3B68	lui    a0, $0001
800B3B6C	sw     ra, $0010(sp)
800B3B70	jal    funcb3d10 [$800b3d10]
800B3B74	ori    a0, a0, $000b
800B3B78	lw     ra, $0010(sp)
800B3B7C	sltu   v0, zero, v0
800B3B80	jr     ra 
800B3B84	addiu  sp, sp, $0018


funcb3b88:	; 800B3B88
800B3B88	lui    v0, $800d
800B3B8C	lbu    v0, $a050(v0)
800B3B90	nop
800B3B94	addiu  a0, v0, $ffff (=-$1)
800B3B98	bltz   a0, Lb3bd0 [$800b3bd0]
800B3B9C	addiu  a1, zero, $0005
800B3BA0	lui    v0, $800d
800B3BA4	addiu  v0, v0, $a010 (=-$5ff0)
800B3BA8	sll    v1, a0, $02
800B3BAC	addu   v1, v1, v0

loopb3bb0:	; 800B3BB0
800B3BB0	lbu    v0, $0002(v1)
800B3BB4	nop
800B3BB8	bne    v0, a1, Lb3bc8 [$800b3bc8]
800B3BBC	addiu  a0, a0, $ffff (=-$1)
800B3BC0	jr     ra 
800B3BC4	addiu  v0, zero, $0001


Lb3bc8:	; 800B3BC8
800B3BC8	bgez   a0, loopb3bb0 [$800b3bb0]

Lb3bcc:	; 800B3BCC
800B3BCC	addiu  v1, v1, $fffc (=-$4)

Lb3bd0:	; 800B3BD0
800B3BD0	jr     ra 
800B3BD4	addu   v0, zero, zero


funcb3bd8:	; 800B3BD8
800B3BD8	lui    v0, $800d
800B3BDC	lbu    v0, $a050(v0)
800B3BE0	nop
800B3BE4	addiu  a1, v0, $ffff (=-$1)
800B3BE8	bltz   a1, Lb3c1c [$800b3c1c]
800B3BEC	lui    v0, $800d
800B3BF0	addiu  v0, v0, $a010 (=-$5ff0)
800B3BF4	sll    v1, a1, $02
800B3BF8	addu   v1, v1, v0

loopb3bfc:	; 800B3BFC
800B3BFC	lw     v0, $0000(v1)

funcb3c00:	; 800B3C00
800B3C00	nop
800B3C04	bne    v0, a0, Lb3c14 [$800b3c14]
800B3C08	addiu  a1, a1, $ffff (=-$1)
800B3C0C	jr     ra 
800B3C10	addu   v0, v1, zero


Lb3c14:	; 800B3C14
800B3C14	bgez   a1, loopb3bfc [$800b3bfc]
800B3C18	addiu  v1, v1, $fffc (=-$4)

Lb3c1c:	; 800B3C1C
800B3C1C	jr     ra 
800B3C20	addu   v0, zero, zero


funcb3c24:	; 800B3C24
800B3C24	lui    v1, $800d
800B3C28	lbu    v0, $a050(v1)
800B3C2C	nop
800B3C30	addiu  a1, v0, $ffff (=-$1)
800B3C34	bltz   a1, Lb3ca4 [$800b3ca4]
800B3C38	addu   a3, v1, zero
800B3C3C	lui    v0, $800d
800B3C40	addiu  t0, v0, $a010 (=-$5ff0)
800B3C44	sll    v0, a1, $02
800B3C48	addu   a2, v0, t0

loopb3c4c:	; 800B3C4C
800B3C4C	lw     v0, $0000(a2)
800B3C50	nop
800B3C54	bne    v0, a0, Lb3c98 [$800b3c98]
800B3C58	nop
800B3C5C	lbu    v0, $a050(a3)
800B3C60	nop
800B3C64	addiu  v1, v0, $ffff (=-$1)
800B3C68	slt    v0, a1, v1
800B3C6C	beq    v0, zero, Lb3c84 [$800b3c84]
800B3C70	sll    v0, v1, $02
800B3C74	addu   v0, v0, t0
800B3C78	lw     v0, $0000(v0)
800B3C7C	nop
800B3C80	sw     v0, $0000(a2)

Lb3c84:	; 800B3C84
800B3C84	lbu    v0, $a050(a3)
800B3C88	nop
800B3C8C	addiu  v0, v0, $ffff (=-$1)
800B3C90	jr     ra 
800B3C94	sb     v0, $a050(a3)


Lb3c98:	; 800B3C98
800B3C98	addiu  a1, a1, $ffff (=-$1)
800B3C9C	bgez   a1, loopb3c4c [$800b3c4c]
800B3CA0	addiu  a2, a2, $fffc (=-$4)

Lb3ca4:	; 800B3CA4
800B3CA4	jr     ra 
800B3CA8	nop


funcb3cac:	; 800B3CAC
800B3CAC	addiu  sp, sp, $ffe8 (=-$18)
800B3CB0	sw     s0, $0010(sp)
800B3CB4	sw     ra, $0014(sp)
800B3CB8	jal    funcb3bd8 [$800b3bd8]
800B3CBC	addu   s0, a0, zero
800B3CC0	bne    v0, zero, Lb3d00 [$800b3d00]
800B3CC4	lui    a1, $800d
800B3CC8	lbu    v0, $a050(a1)
800B3CCC	nop
800B3CD0	sltiu  v0, v0, $0008

Lb3cd4:	; 800B3CD4
800B3CD4	bne    v0, zero, Lb3ce4 [$800b3ce4]
800B3CD8	lui    v0, $800d
800B3CDC	j      Lb3d00 [$800b3d00]
800B3CE0	addu   v0, zero, zero

Lb3ce4:	; 800B3CE4
800B3CE4	lbu    v1, $a050(a1)
800B3CE8	addiu  v0, v0, $a010 (=-$5ff0)

funcb3cec:	; 800B3CEC
800B3CEC	sll    a0, v1, $02
800B3CF0	addu   v0, a0, v0
800B3CF4	addiu  v1, v1, $0001
800B3CF8	sb     v1, $a050(a1)
800B3CFC	sw     s0, $0000(v0)

Lb3d00:	; 800B3D00
800B3D00	lw     ra, $0014(sp)
800B3D04	lw     s0, $0010(sp)
800B3D08	jr     ra 
800B3D0C	addiu  sp, sp, $0018


funcb3d10:	; 800B3D10
800B3D10	lui    v0, $800d
800B3D14	lbu    v0, $a051(v0)
800B3D18	nop
800B3D1C	addiu  a1, v0, $ffff (=-$1)
800B3D20	bltz   a1, Lb3d54 [$800b3d54]
800B3D24	lui    v0, $800d
800B3D28	addiu  v0, v0, $a030 (=-$5fd0)
800B3D2C	sll    v1, a1, $02
800B3D30	addu   v1, v1, v0

loopb3d34:	; 800B3D34
800B3D34	lw     v0, $0000(v1)
800B3D38	nop
800B3D3C	bne    v0, a0, Lb3d4c [$800b3d4c]
800B3D40	addiu  a1, a1, $ffff (=-$1)
800B3D44	jr     ra 
800B3D48	addu   v0, v1, zero


Lb3d4c:	; 800B3D4C
800B3D4C	bgez   a1, loopb3d34 [$800b3d34]
800B3D50	addiu  v1, v1, $fffc (=-$4)

Lb3d54:	; 800B3D54
800B3D54	jr     ra 
800B3D58	addu   v0, zero, zero

800B3D5C	lui    v1, $800d
800B3D60	lbu    v0, $a051(v1)
800B3D64	nop
800B3D68	addiu  a1, v0, $ffff (=-$1)
800B3D6C	bltz   a1, Lb3ddc [$800b3ddc]
800B3D70	addu   a3, v1, zero
800B3D74	lui    v0, $800d
800B3D78	addiu  t0, v0, $a030 (=-$5fd0)
800B3D7C	sll    v0, a1, $02
800B3D80	addu   a2, v0, t0

loopb3d84:	; 800B3D84
800B3D84	lw     v0, $0000(a2)
800B3D88	nop
800B3D8C	bne    v0, a0, Lb3dd0 [$800b3dd0]
800B3D90	nop
800B3D94	lbu    v0, $a051(a3)
800B3D98	nop
800B3D9C	addiu  v1, v0, $ffff (=-$1)
800B3DA0	slt    v0, a1, v1
800B3DA4	beq    v0, zero, Lb3dbc [$800b3dbc]
800B3DA8	sll    v0, v1, $02
800B3DAC	addu   v0, v0, t0
800B3DB0	lw     v0, $0000(v0)
800B3DB4	nop
800B3DB8	sw     v0, $0000(a2)

Lb3dbc:	; 800B3DBC
800B3DBC	lbu    v0, $a051(a3)
800B3DC0	nop
800B3DC4	addiu  v0, v0, $ffff (=-$1)
800B3DC8	jr     ra 
800B3DCC	sb     v0, $a051(a3)


Lb3dd0:	; 800B3DD0
800B3DD0	addiu  a1, a1, $ffff (=-$1)
800B3DD4	bgez   a1, loopb3d84 [$800b3d84]
800B3DD8	addiu  a2, a2, $fffc (=-$4)

Lb3ddc:	; 800B3DDC
800B3DDC	jr     ra 
800B3DE0	nop


funcb3de4:	; 800B3DE4
800B3DE4	addiu  sp, sp, $ffe8 (=-$18)
800B3DE8	sw     s0, $0010(sp)
800B3DEC	sw     ra, $0014(sp)
800B3DF0	jal    funcb3d10 [$800b3d10]
800B3DF4	addu   s0, a0, zero
800B3DF8	bne    v0, zero, Lb3e38 [$800b3e38]
800B3DFC	lui    a1, $800d
800B3E00	lbu    v0, $a051(a1)
800B3E04	nop
800B3E08	sltiu  v0, v0, $0008
800B3E0C	bne    v0, zero, Lb3e1c [$800b3e1c]
800B3E10	lui    v0, $800d
800B3E14	j      Lb3e38 [$800b3e38]
800B3E18	addu   v0, zero, zero

Lb3e1c:	; 800B3E1C
800B3E1C	lbu    v1, $a051(a1)
800B3E20	addiu  v0, v0, $a030 (=-$5fd0)
800B3E24	sll    a0, v1, $02
800B3E28	addu   v0, a0, v0
800B3E2C	addiu  v1, v1, $0001
800B3E30	sb     v1, $a051(a1)
800B3E34	sw     s0, $0000(v0)

Lb3e38:	; 800B3E38
800B3E38	lw     ra, $0014(sp)
800B3E3C	lw     s0, $0010(sp)
800B3E40	jr     ra 
800B3E44	addiu  sp, sp, $0018


funcb3e48:	; 800B3E48
800B3E48	addiu  sp, sp, $ffc0 (=-$40)
800B3E4C	sw     s5, $0034(sp)
800B3E50	addu   s5, a0, zero
800B3E54	sw     s2, $0028(sp)

Lb3e58:	; 800B3E58
800B3E58	addu   s2, a1, zero
800B3E5C	sw     s4, $0030(sp)
800B3E60	addu   s4, a2, zero
800B3E64	sw     s3, $002c(sp)
800B3E68	addu   s3, a3, zero
800B3E6C	addiu  v0, zero, $ffff (=-$1)
800B3E70	sw     ra, $0038(sp)
800B3E74	sw     s1, $0024(sp)
800B3E78	beq    s5, v0, Lb3f14 [$800b3f14]

funcb3e7c:	; 800B3E7C
800B3E7C	sw     s0, $0020(sp)
800B3E80	beq    s4, zero, Lb3f14 [$800b3f14]
800B3E84	nop
800B3E88	bne    s2, zero, Lb3e98 [$800b3e98]
800B3E8C	nop
800B3E90	beq    s3, zero, Lb3f68 [$800b3f68]
800B3E94	addu   v0, zero, zero

Lb3e98:	; 800B3E98
800B3E98	jal    funcac380 [$800ac380]
800B3E9C	addu   a0, zero, zero
800B3EA0	addu   a0, v0, zero
800B3EA4	lui    v1, $0015
800B3EA8	lui    v0, $8006
800B3EAC	lw     v0, $7944(v0)
800B3EB0	ori    v1, v1, $3f00
800B3EB4	addu   v1, v0, v1
800B3EB8	sltu   v0, v1, a0
800B3EBC	beq    v0, zero, Lb3ec8 [$800b3ec8]
800B3EC0	nop
800B3EC4	addu   a0, v1, zero

Lb3ec8:	; 800B3EC8
800B3EC8	lui    v0, $800d
800B3ECC	lw     v0, $9d58(v0)
800B3ED0	nop
800B3ED4	subu   s0, a0, v0
800B3ED8	bgez   s0, Lb3ee4 [$800b3ee4]
800B3EDC	addu   v0, s0, zero
800B3EE0	addiu  v0, s0, $07ff

Lb3ee4:	; 800B3EE4
800B3EE4	sra    v0, v0, $0b
800B3EE8	bne    s2, zero, Lb3f00 [$800b3f00]
800B3EEC	sll    s0, v0, $0b
800B3EF0	addiu  v0, zero, $7fff
800B3EF4	slt    v0, v0, s0

funcb3ef8:	; 800B3EF8
800B3EF8	beq    v0, zero, Lb3f68 [$800b3f68]
800B3EFC	addu   v0, zero, zero

Lb3f00:	; 800B3F00
800B3F00	jal    func21cfc [$80021cfc]
800B3F04	nop
800B3F08	addu   s1, v0, zero
800B3F0C	bne    s1, zero, Lb3f1c [$800b3f1c]
800B3F10	nop

Lb3f14:	; 800B3F14
800B3F14	j      Lb3f68 [$800b3f68]
800B3F18	addu   v0, zero, zero

Lb3f1c:	; 800B3F1C
800B3F1C	bne    s2, zero, Lb3f34 [$800b3f34]
800B3F20	addu   a3, zero, zero
800B3F24	lui    v0, $800d
800B3F28	lw     a3, $9d58(v0)
800B3F2C	j      Lb3f38 [$800b3f38]
800B3F30	addu   a0, s1, zero

Lb3f34:	; 800B3F34
800B3F34	addu   a0, s1, zero

Lb3f38:	; 800B3F38
800B3F38	addu   a1, s2, zero
800B3F3C	addu   a2, s5, zero
800B3F40	sw     s0, $0010(sp)
800B3F44	sw     s3, $0014(sp)
800B3F48	sw     s4, $0018(sp)
800B3F4C	jal    func21974 [$80021974]
800B3F50	sw     s3, $001c(sp)
800B3F54	lui    a0, $800d
800B3F58	lw     v1, $9d58(a0)
800B3F5C	addu   v0, s1, zero
800B3F60	addu   v1, v1, s3
800B3F64	sw     v1, $9d58(a0)

Lb3f68:	; 800B3F68
800B3F68	lw     ra, $0038(sp)
800B3F6C	lw     s5, $0034(sp)
800B3F70	lw     s4, $0030(sp)
800B3F74	lw     s3, $002c(sp)
800B3F78	lw     s2, $0028(sp)
800B3F7C	lw     s1, $0024(sp)
800B3F80	lw     s0, $0020(sp)
800B3F84	jr     ra 
800B3F88	addiu  sp, sp, $0040


funcb3f8c:	; 800B3F8C
800B3F8C	addiu  sp, sp, $ffc8 (=-$38)
800B3F90	sw     s0, $0010(sp)
800B3F94	lui    s0, $8006

funcb3f98:	; 800B3F98
800B3F98	lw     v0, $794c(s0)
800B3F9C	sw     ra, $0034(sp)
800B3FA0	sw     fp, $0030(sp)
800B3FA4	sw     s7, $002c(sp)
800B3FA8	sw     s6, $0028(sp)
800B3FAC	sw     s5, $0024(sp)
800B3FB0	sw     s4, $0020(sp)
800B3FB4	sw     s3, $001c(sp)
800B3FB8	sw     s2, $0018(sp)
800B3FBC	sw     s1, $0014(sp)
800B3FC0	lw     v0, $001c(v0)
800B3FC4	nop
800B3FC8	lw     v0, $07e4(v0)
800B3FCC	jal    funcb3b64 [$800b3b64]
800B3FD0	addiu  fp, v0, $0004
800B3FD4	bne    v0, zero, Lb4090 [$800b4090]
800B3FD8	nop
800B3FDC	jal    funcb3b40 [$800b3b40]
800B3FE0	addu   s1, zero, zero
800B3FE4	beq    v0, zero, Lb3ff4 [$800b3ff4]
800B3FE8	nop

loopb3fec:	; 800B3FEC
800B3FEC	j      Lb4044 [$800b4044]
800B3FF0	addiu  s1, zero, $0001

Lb3ff4:	; 800B3FF4
800B3FF4	lw     v0, $794c(s0)
800B3FF8	nop
800B3FFC	lw     v0, $001c(v0)
800B4000	nop
800B4004	lw     v0, $07e4(v0)
800B4008	nop
800B400C	lhu    v0, $0002(v0)
800B4010	nop
800B4014	addiu  s0, v0, $ffff (=-$1)
800B4018	bltz   s0, Lb4044 [$800b4044]
800B401C	addiu  a0, zero, $0011
800B4020	sll    v0, s0, $04
800B4024	addu   v1, v0, fp

loopb4028:	; 800B4028
800B4028	lbu    v0, $0002(v1)
800B402C	nop

Lb4030:	; 800B4030
800B4030	beq    v0, a0, loopb3fec [$800b3fec]
800B4034	nop
800B4038	addiu  s0, s0, $ffff (=-$1)
800B403C	bgez   s0, loopb4028 [$800b4028]

funcb4040:	; 800B4040
800B4040	addiu  v1, v1, $fff0 (=-$10)

Lb4044:	; 800B4044
800B4044	beq    s1, zero, Lb4090 [$800b4090]
800B4048	addu   a0, zero, zero
800B404C	lui    a1, $0001
800B4050	jal    func1e218 [$8001e218]
800B4054	ori    a1, a1, $000b
800B4058	lui    a0, $0001
800B405C	ori    a0, a0, $000b
800B4060	lw     a2, $0004(v0)
800B4064	lw     a3, $000c(v0)
800B4068	addu   a1, zero, zero
800B406C	subu   a3, a3, a2
800B4070	jal    funcb3e48 [$800b3e48]
800B4074	sll    a3, a3, $0b
800B4078	jal    funcb3b40 [$800b3b40]
800B407C	nop
800B4080	beq    v0, zero, Lb4090 [$800b4090]
800B4084	lui    a0, $0001
800B4088	jal    funcb3c24 [$800b3c24]
800B408C	ori    a0, a0, $000b

Lb4090:	; 800B4090
800B4090	jal    funcb3b88 [$800b3b88]
800B4094	nop
800B4098	beq    v0, zero, Lb41ec [$800b41ec]
800B409C	lui    v0, $800d
800B40A0	lbu    v0, $a050(v0)
800B40A4	nop
800B40A8	beq    v0, zero, Lb4864 [$800b4864]
800B40AC	addu   s0, zero, zero
800B40B0	lui    s4, $8006
800B40B4	lui    v0, $800d
800B40B8	addiu  s3, v0, $a010 (=-$5ff0)

loopb40bc:	; 800B40BC
800B40BC	addiu  v0, zero, $0005
800B40C0	lbu    v1, $0002(s3)
800B40C4	lw     s1, $0000(s3)
800B40C8	bne    v1, v0, Lb4174 [$800b4174]
800B40CC	lui    v0, $800d
800B40D0	lw     v0, $794c(s4)
800B40D4	nop
800B40D8	lw     v0, $001c(v0)
800B40DC	nop
800B40E0	lw     a0, $07e4(v0)
800B40E4	jal    func63088 [$80063088]
800B40E8	addu   a1, s1, zero
800B40EC	addu   s2, v0, zero

Lb40f0:	; 800B40F0
800B40F0	beq    s2, zero, Lb4174 [$800b4174]
800B40F4	lui    v0, $800d
800B40F8	lw     v0, $794c(s4)
800B40FC	nop
800B4100	lw     a0, $001c(v0)
800B4104	lw     a1, $000c(s2)
800B4108	lh     v1, $003a(a0)
800B410C	andi   v0, a1, $ffff
800B4110	beq    v0, v1, Lb4150 [$800b4150]

funcb4114:	; 800B4114
800B4114	nop
800B4118	lw     a0, $07e4(a0)
800B411C	jal    func63088 [$80063088]
800B4120	nop
800B4124	addu   v1, v0, zero
800B4128	beq    v1, zero, Lb4150 [$800b4150]
800B412C	addu   a1, zero, zero
800B4130	lui    a0, $00ff
800B4134	ori    a0, a0, $ffff
800B4138	lw     a2, $0004(v1)
800B413C	lw     v0, $000c(s2)
800B4140	lw     a3, $0008(v1)
800B4144	and    a0, v0, a0
800B4148	jal    funcb3e48 [$800b3e48]
800B414C	sll    a3, a3, $0b

Lb4150:	; 800B4150
800B4150	addu   a0, s1, zero
800B4154	addu   a1, zero, zero
800B4158	lw     a3, $0008(s2)
800B415C	lw     a2, $0004(s2)
800B4160	jal    funcb3e48 [$800b3e48]
800B4164	sll    a3, a3, $0b
800B4168	jal    funcb3c24 [$800b3c24]
800B416C	addu   a0, s1, zero
800B4170	lui    v0, $800d

Lb4174:	; 800B4174
800B4174	lbu    v0, $a050(v0)
800B4178	addiu  s0, s0, $0001
800B417C	slt    v0, s0, v0
800B4180	bne    v0, zero, loopb40bc [$800b40bc]
800B4184	addiu  s3, s3, $0004

Lb4188:	; 800B4188
800B4188	j      Lb4864 [$800b4864]
800B418C	nop

Lb4190:	; 800B4190
800B4190	lw     s5, $0008(s1)
800B4194	j      Lb43b0 [$800b43b0]
800B4198	addu   s3, s0, zero

Lb419c:	; 800B419C
800B419C	j      Lb4474 [$800b4474]
800B41A0	addu   s3, s0, zero

Lb41a4:	; 800B41A4
800B41A4	lui    a0, $00ff
800B41A8	ori    a0, a0, $ffff
800B41AC	and    a0, v1, a0
800B41B0	addu   a1, zero, zero
800B41B4	lw     a3, $0008(v0)
800B41B8	lw     a2, $0004(v0)
800B41BC	jal    funcb3e48 [$800b3e48]
800B41C0	sll    a3, a3, $0b
800B41C4	j      Lb44e4 [$800b44e4]
800B41C8	lui    a0, $00ff

Lb41cc:	; 800B41CC
800B41CC	addu   s5, v1, zero
800B41D0	j      Lb462c [$800b462c]
800B41D4	addu   s3, s0, zero

Lb41d8:	; 800B41D8
800B41D8	lw     s5, $0008(s2)
800B41DC	j      Lb46e0 [$800b46e0]
800B41E0	addu   s3, s0, zero

Lb41e4:	; 800B41E4
800B41E4	j      Lb47ac [$800b47ac]
800B41E8	addu   s3, s0, zero

Lb41ec:	; 800B41EC
800B41EC	lui    v1, $8006
800B41F0	lw     v0, $794c(v1)
800B41F4	nop
800B41F8	lw     v0, $001c(v0)
800B41FC	addu   s5, zero, zero
800B4200	lw     v0, $07e4(v0)
800B4204	addiu  s3, zero, $ffff (=-$1)
800B4208	lhu    v0, $0002(v0)
800B420C	nop
800B4210	addu   s0, v0, s3
800B4214	bltz   s0, Lb42fc [$800b42fc]
800B4218	addu   s7, s3, zero
800B421C	addu   s6, v1, zero
800B4220	lui    s4, $51eb

Lb4224:	; 800B4224
800B4224	ori    s4, s4, $851f
800B4228	sll    v0, s0, $04
800B422C	addu   s2, v0, fp

loopb4230:	; 800B4230
800B4230	lw     v0, $0008(s2)

funcb4234:	; 800B4234
800B4234	lw     a0, $0000(s2)
800B4238	beq    v0, zero, Lb42f0 [$800b42f0]
800B423C	sra    v0, a0, $10
800B4240	andi   v0, v0, $00ff
800B4244	addiu  v1, zero, $0005
800B4248	bne    v0, v1, Lb42f0 [$800b42f0]
800B424C	andi   s1, a0, $ffff
800B4250	slti   v0, s1, $2328
800B4254	beq    v0, zero, Lb42f0 [$800b42f0]
800B4258	nop
800B425C	lw     v0, $794c(s6)
800B4260	nop
800B4264	lw     v0, $001c(v0)
800B4268	nop
800B426C	lw     v0, $08e4(v0)
800B4270	nop
800B4274	lh     v0, $000a(v0)
800B4278	nop
800B427C	beq    s1, v0, Lb42f0 [$800b42f0]
800B4280	nop
800B4284	jal    funcb3d10 [$800b3d10]
800B4288	nop
800B428C	bne    v0, zero, Lb42f0 [$800b42f0]
800B4290	mult   s1, s4
800B4294	lw     v0, $794c(s6)
800B4298	nop
800B429C	lw     v0, $001c(v0)
800B42A0	mfhi   a0
800B42A4	lhu    v1, $000c(v0)
800B42A8	nop
800B42AC	mult   v1, s4
800B42B0	sra    v0, s1, $1f
800B42B4	sra    a0, a0, $04
800B42B8	subu   a0, a0, v0
800B42BC	sra    v1, v1, $1f
800B42C0	mfhi   t1
800B42C4	sra    v0, t1, $04
800B42C8	subu   v0, v0, v1
800B42CC	bne    a0, v0, Lb42f0 [$800b42f0]
800B42D0	nop
800B42D4	lw     v1, $0008(s2)
800B42D8	nop
800B42DC	slt    v0, s5, v1
800B42E0	beq    v0, zero, Lb42f0 [$800b42f0]
800B42E4	nop
800B42E8	addu   s5, v1, zero
800B42EC	addu   s3, s0, zero

Lb42f0:	; 800B42F0
800B42F0	addiu  s0, s0, $ffff (=-$1)
800B42F4	bgez   s0, loopb4230 [$800b4230]
800B42F8	addiu  s2, s2, $fff0 (=-$10)

Lb42fc:	; 800B42FC
800B42FC	addiu  v0, zero, $ffff (=-$1)
800B4300	bne    s3, v0, Lb4480 [$800b4480]
800B4304	sll    v1, s3, $04
800B4308	lui    v1, $8006
800B430C	lw     v0, $794c(v1)
800B4310	nop
800B4314	lw     v0, $001c(v0)
800B4318	nop
800B431C	lw     v0, $07e4(v0)

funcb4320:	; 800B4320
800B4320	nop
800B4324	lhu    v0, $0002(v0)
800B4328	nop
800B432C	addiu  s0, v0, $ffff (=-$1)
800B4330	bltz   s0, Lb43b0 [$800b43b0]
800B4334	sll    v0, s0, $04
800B4338	addiu  s6, zero, $0005
800B433C	addu   s4, v1, zero
800B4340	addu   s1, v0, fp

loopb4344:	; 800B4344
800B4344	lw     v0, $0008(s1)
800B4348	lw     a0, $0000(s1)
800B434C	beq    v0, zero, Lb43a4 [$800b43a4]
800B4350	sra    v0, a0, $10
800B4354	andi   v0, v0, $00ff
800B4358	bne    v0, s6, Lb43a4 [$800b43a4]
800B435C	andi   s2, a0, $ffff
800B4360	slti   v0, s2, $2328
800B4364	beq    v0, zero, Lb43a4 [$800b43a4]
800B4368	nop
800B436C	jal    funcb3d10 [$800b3d10]
800B4370	nop
800B4374	bne    v0, zero, Lb43a4 [$800b43a4]
800B4378	nop
800B437C	lw     v0, $794c(s4)
800B4380	nop
800B4384	lw     v0, $001c(v0)
800B4388	nop
800B438C	lw     v0, $08e4(v0)

funcb4390:	; 800B4390
800B4390	nop
800B4394	lh     v0, $000a(v0)
800B4398	nop
800B439C	beq    s2, v0, Lb4190 [$800b4190]
800B43A0	nop

Lb43a4:	; 800B43A4
800B43A4	addiu  s0, s0, $ffff (=-$1)
800B43A8	bgez   s0, loopb4344 [$800b4344]
800B43AC	addiu  s1, s1, $fff0 (=-$10)

Lb43b0:	; 800B43B0
800B43B0	addiu  v0, zero, $ffff (=-$1)
800B43B4	bne    s3, v0, Lb4480 [$800b4480]
800B43B8	sll    v1, s3, $04
800B43BC	lui    v0, $8006
800B43C0	lw     v0, $794c(v0)
800B43C4	nop
800B43C8	lw     v0, $001c(v0)
800B43CC	nop
800B43D0	lw     v0, $07e4(v0)
800B43D4	nop
800B43D8	lhu    v0, $0002(v0)
800B43DC	nop
800B43E0	addiu  s0, v0, $ffff (=-$1)
800B43E4	bltz   s0, Lb4474 [$800b4474]
800B43E8	sll    v0, s0, $04
800B43EC	addiu  s2, zero, $0005
800B43F0	addu   s1, v0, fp

loopb43f4:	; 800B43F4
800B43F4	lw     v0, $0008(s1)
800B43F8	lw     a0, $0000(s1)
800B43FC	beq    v0, zero, Lb4468 [$800b4468]
800B4400	sra    v0, a0, $10
800B4404	andi   v0, v0, $00ff
800B4408	bne    v0, s2, Lb4468 [$800b4468]

funcb440c:	; 800B440C
800B440C	andi   v1, a0, $ffff
800B4410	slti   v0, v1, $2328
800B4414	beq    v0, zero, Lb4468 [$800b4468]
800B4418	lui    v0, $8006
800B441C	lw     v0, $794c(v0)
800B4420	nop
800B4424	lw     v0, $001c(v0)
800B4428	nop
800B442C	lw     v0, $08e4(v0)
800B4430	nop

funcb4434:	; 800B4434
800B4434	lh     v0, $000a(v0)
800B4438	nop
800B443C	beq    v1, v0, Lb4468 [$800b4468]
800B4440	nop
800B4444	jal    funcb3d10 [$800b3d10]
800B4448	nop
800B444C	bne    v0, zero, Lb4468 [$800b4468]
800B4450	nop
800B4454	lw     v0, $0008(s1)
800B4458	nop
800B445C	slt    v0, s5, v0
800B4460	bne    v0, zero, Lb419c [$800b419c]
800B4464	nop

Lb4468:	; 800B4468
800B4468	addiu  s0, s0, $ffff (=-$1)
800B446C	bgez   s0, loopb43f4 [$800b43f4]
800B4470	addiu  s1, s1, $fff0 (=-$10)

Lb4474:	; 800B4474
800B4474	addiu  v0, zero, $ffff (=-$1)

funcb4478:	; 800B4478
800B4478	beq    s3, v0, Lb4518 [$800b4518]
800B447C	sll    v1, s3, $04

Lb4480:	; 800B4480
800B4480	lui    v0, $8006
800B4484	lw     v0, $794c(v0)
800B4488	addu   v1, v1, fp
800B448C	lw     a0, $001c(v0)
800B4490	lw     a1, $000c(v1)
800B4494	lh     v1, $003a(a0)
800B4498	andi   v0, a1, $ffff
800B449C	beq    v0, v1, Lb44e0 [$800b44e0]
800B44A0	nop
800B44A4	lw     v0, $07e4(a0)
800B44A8	nop
800B44AC	lhu    v0, $0002(v0)
800B44B0	nop
800B44B4	addiu  s0, v0, $ffff (=-$1)
800B44B8	bltz   s0, Lb44e0 [$800b44e0]
800B44BC	addu   a0, a1, zero

funcb44c0:	; 800B44C0
800B44C0	sll    v0, s0, $04
800B44C4	addu   v0, v0, fp

loopb44c8:	; 800B44C8
800B44C8	lw     v1, $0000(v0)
800B44CC	nop
800B44D0	beq    v1, a0, Lb41a4 [$800b41a4]
800B44D4	addiu  s0, s0, $ffff (=-$1)
800B44D8	bgez   s0, loopb44c8 [$800b44c8]
800B44DC	addiu  v0, v0, $fff0 (=-$10)

Lb44e0:	; 800B44E0
800B44E0	lui    a0, $00ff

Lb44e4:	; 800B44E4
800B44E4	ori    a0, a0, $ffff
800B44E8	addu   a1, zero, zero
800B44EC	sll    v0, s3, $04
800B44F0	addu   v0, v0, fp
800B44F4	lw     v1, $0000(v0)
800B44F8	lw     a2, $0004(v0)
800B44FC	lw     a3, $0008(v0)
800B4500	and    s1, v1, a0
800B4504	addu   a0, s1, zero
800B4508	jal    funcb3e48 [$800b3e48]
800B450C	sll    a3, a3, $0b
800B4510	addu   s7, s1, zero
800B4514	addiu  v0, zero, $ffff (=-$1)

Lb4518:	; 800B4518
800B4518	beq    s7, v0, Lb4864 [$800b4864]
800B451C	lui    v1, $8006
800B4520	lw     v0, $794c(v1)
800B4524	nop
800B4528	lw     v0, $001c(v0)
800B452C	nop
800B4530	lw     v0, $07e4(v0)
800B4534	nop
800B4538	lhu    v0, $0002(v0)
800B453C	addiu  s3, zero, $ffff (=-$1)
800B4540	addu   s0, v0, s3
800B4544	bltz   s0, Lb462c [$800b462c]
800B4548	addu   s5, zero, zero
800B454C	addu   s6, v1, zero
800B4550	lui    s4, $51eb
800B4554	ori    s4, s4, $851f
800B4558	sll    v0, s0, $04
800B455C	addu   s2, v0, fp

loopb4560:	; 800B4560
800B4560	lw     v0, $0008(s2)
800B4564	lw     a0, $0000(s2)
800B4568	beq    v0, zero, Lb4620 [$800b4620]
800B456C	sra    v0, a0, $10
800B4570	andi   v0, v0, $00ff
800B4574	addiu  v1, zero, $0005
800B4578	bne    v0, v1, Lb4620 [$800b4620]
800B457C	andi   s1, a0, $ffff
800B4580	slti   v0, s1, $2328
800B4584	beq    v0, zero, Lb4620 [$800b4620]
800B4588	nop
800B458C	lw     v0, $794c(s6)
800B4590	nop
800B4594	lw     v0, $001c(v0)
800B4598	nop
800B459C	lw     v0, $08e4(v0)
800B45A0	nop
800B45A4	lh     v0, $000a(v0)
800B45A8	nop
800B45AC	beq    s1, v0, Lb4620 [$800b4620]
800B45B0	andi   v0, s7, $ffff
800B45B4	beq    s1, v0, Lb4620 [$800b4620]
800B45B8	nop
800B45BC	jal    funcb3d10 [$800b3d10]
800B45C0	nop
800B45C4	bne    v0, zero, Lb4620 [$800b4620]
800B45C8	mult   s1, s4
800B45CC	lw     v0, $794c(s6)
800B45D0	nop
800B45D4	lw     v0, $001c(v0)
800B45D8	mfhi   a0
800B45DC	lhu    v1, $000c(v0)
800B45E0	nop
800B45E4	mult   v1, s4
800B45E8	sra    v0, s1, $1f
800B45EC	sra    a0, a0, $04
800B45F0	subu   a0, a0, v0
800B45F4	sra    v1, v1, $1f
800B45F8	mfhi   t1
800B45FC	sra    v0, t1, $04
800B4600	subu   v0, v0, v1
800B4604	bne    a0, v0, Lb4620 [$800b4620]
800B4608	nop
800B460C	lw     v1, $0008(s2)
800B4610	nop
800B4614	slt    v0, s5, v1
800B4618	bne    v0, zero, Lb41cc [$800b41cc]
800B461C	nop

Lb4620:	; 800B4620
800B4620	addiu  s0, s0, $ffff (=-$1)
800B4624	bgez   s0, loopb4560 [$800b4560]
800B4628	addiu  s2, s2, $fff0 (=-$10)

Lb462c:	; 800B462C
800B462C	addiu  v0, zero, $ffff (=-$1)
800B4630	bne    s3, v0, Lb47b8 [$800b47b8]
800B4634	lui    v0, $8006
800B4638	lw     v0, $794c(v0)
800B463C	nop
800B4640	lw     v0, $001c(v0)
800B4644	nop
800B4648	lw     v0, $07e4(v0)
800B464C	nop
800B4650	lhu    v0, $0002(v0)
800B4654	nop
800B4658	addiu  s0, v0, $ffff (=-$1)
800B465C	bltz   s0, Lb46e0 [$800b46e0]
800B4660	sll    v0, s0, $04
800B4664	addiu  s4, zero, $0005
800B4668	addu   s2, v0, fp

loopb466c:	; 800B466C
800B466C	lw     v0, $0008(s2)
800B4670	lw     a0, $0000(s2)
800B4674	beq    v0, zero, Lb46d4 [$800b46d4]
800B4678	sra    v0, a0, $10
800B467C	andi   v0, v0, $00ff
800B4680	bne    v0, s4, Lb46d4 [$800b46d4]
800B4684	andi   s1, a0, $ffff
800B4688	slti   v0, s1, $2328
800B468C	beq    v0, zero, Lb46d4 [$800b46d4]
800B4690	andi   v0, s7, $ffff
800B4694	beq    s1, v0, Lb46d4 [$800b46d4]
800B4698	nop
800B469C	jal    funcb3d10 [$800b3d10]
800B46A0	nop
800B46A4	bne    v0, zero, Lb46d4 [$800b46d4]
800B46A8	lui    v0, $8006
800B46AC	lw     v0, $794c(v0)
800B46B0	nop
800B46B4	lw     v0, $001c(v0)
800B46B8	nop
800B46BC	lw     v0, $08e4(v0)
800B46C0	nop
800B46C4	lh     v0, $000a(v0)
800B46C8	nop
800B46CC	beq    s1, v0, Lb41d8 [$800b41d8]
800B46D0	nop

Lb46d4:	; 800B46D4
800B46D4	addiu  s0, s0, $ffff (=-$1)
800B46D8	bgez   s0, loopb466c [$800b466c]
800B46DC	addiu  s2, s2, $fff0 (=-$10)

Lb46e0:	; 800B46E0
800B46E0	addiu  v0, zero, $ffff (=-$1)
800B46E4	bne    s3, v0, Lb47bc [$800b47bc]
800B46E8	sll    v1, s3, $04
800B46EC	lui    v0, $8006
800B46F0	lw     v0, $794c(v0)
800B46F4	nop
800B46F8	lw     v0, $001c(v0)
800B46FC	nop
800B4700	lw     v0, $07e4(v0)
800B4704	nop
800B4708	lhu    v0, $0002(v0)
800B470C	nop
800B4710	addiu  s0, v0, $ffff (=-$1)
800B4714	bltz   s0, Lb47ac [$800b47ac]
800B4718	sll    v0, s0, $04
800B471C	addu   s1, v0, fp

loopb4720:	; 800B4720
800B4720	lw     v0, $0008(s1)
800B4724	lw     a0, $0000(s1)
800B4728	beq    v0, zero, Lb47a0 [$800b47a0]
800B472C	sra    v0, a0, $10
800B4730	andi   v0, v0, $00ff
800B4734	addiu  v1, zero, $0005
800B4738	bne    v0, v1, Lb47a0 [$800b47a0]
800B473C	andi   v1, a0, $ffff
800B4740	slti   v0, v1, $2328
800B4744	beq    v0, zero, Lb47a0 [$800b47a0]
800B4748	lui    v0, $8006
800B474C	lw     v0, $794c(v0)
800B4750	nop
800B4754	lw     v0, $001c(v0)
800B4758	nop
800B475C	lw     v0, $08e4(v0)
800B4760	nop
800B4764	lh     v0, $000a(v0)
800B4768	nop
800B476C	beq    v1, v0, Lb47a0 [$800b47a0]
800B4770	andi   v0, s7, $ffff
800B4774	beq    v1, v0, Lb47a0 [$800b47a0]
800B4778	nop
800B477C	jal    funcb3d10 [$800b3d10]
800B4780	nop
800B4784	bne    v0, zero, Lb47a0 [$800b47a0]
800B4788	nop
800B478C	lw     v0, $0008(s1)
800B4790	nop
800B4794	slt    v0, s5, v0
800B4798	bne    v0, zero, Lb41e4 [$800b41e4]
800B479C	nop

Lb47a0:	; 800B47A0
800B47A0	addiu  s0, s0, $ffff (=-$1)
800B47A4	bgez   s0, loopb4720 [$800b4720]
800B47A8	addiu  s1, s1, $fff0 (=-$10)

Lb47ac:	; 800B47AC
800B47AC	addiu  v0, zero, $ffff (=-$1)
800B47B0	beq    s3, v0, Lb4864 [$800b4864]
800B47B4	nop

Lb47b8:	; 800B47B8
800B47B8	sll    v1, s3, $04

Lb47bc:	; 800B47BC
800B47BC	lui    v0, $8006
800B47C0	lw     v0, $794c(v0)
800B47C4	addu   a2, v1, fp
800B47C8	lw     a0, $001c(v0)
800B47CC	lw     a1, $000c(a2)
800B47D0	lh     v1, $003a(a0)
800B47D4	andi   v0, a1, $ffff
800B47D8	beq    v0, v1, Lb4844 [$800b4844]
800B47DC	lui    v0, $00ff
800B47E0	lw     v0, $07e4(a0)
800B47E4	nop
800B47E8	lhu    v0, $0002(v0)
800B47EC	nop
800B47F0	addiu  s0, v0, $ffff (=-$1)
800B47F4	bltz   s0, Lb4864 [$800b4864]
800B47F8	addu   a0, a1, zero
800B47FC	sll    v0, s0, $04
800B4800	addu   v0, v0, fp

loopb4804:	; 800B4804
800B4804	addu   v1, v0, zero
800B4808	lw     a1, $0000(v1)
800B480C	nop
800B4810	beq    a1, a0, Lb4828 [$800b4828]
800B4814	addiu  s0, s0, $ffff (=-$1)
800B4818	bgez   s0, loopb4804 [$800b4804]
800B481C	addiu  v0, v1, $fff0 (=-$10)
800B4820	j      Lb4864 [$800b4864]
800B4824	nop

Lb4828:	; 800B4828
800B4828	lui    a0, $00ff
800B482C	ori    a0, a0, $ffff
800B4830	and    a0, a1, a0
800B4834	addiu  a1, zero, $0001
800B4838	lw     a2, $0004(v0)
800B483C	j      Lb485c [$800b485c]
800B4840	addiu  a3, zero, $ffff (=-$1)

Lb4844:	; 800B4844
800B4844	ori    v0, v0, $ffff
800B4848	addiu  a1, zero, $0001
800B484C	addiu  a3, zero, $ffff (=-$1)
800B4850	lw     a0, $0000(a2)
800B4854	lw     a2, $0004(a2)
800B4858	and    a0, a0, v0

Lb485c:	; 800B485C
800B485C	jal    funcb3e48 [$800b3e48]
800B4860	nop

Lb4864:	; 800B4864
800B4864	lw     ra, $0034(sp)
800B4868	lw     fp, $0030(sp)
800B486C	lw     s7, $002c(sp)
800B4870	lw     s6, $0028(sp)
800B4874	lw     s5, $0024(sp)
800B4878	lw     s4, $0020(sp)
800B487C	lw     s3, $001c(sp)
800B4880	lw     s2, $0018(sp)
800B4884	lw     s1, $0014(sp)
800B4888	lw     s0, $0010(sp)
800B488C	jr     ra 
800B4890	addiu  sp, sp, $0038

800B4894	addiu  sp, sp, $ffe0 (=-$20)
800B4898	sw     s0, $0010(sp)
800B489C	lui    s0, $8006
800B48A0	lw     v0, $794c(s0)
800B48A4	sw     ra, $0018(sp)
800B48A8	sw     s1, $0014(sp)
800B48AC	lw     v1, $001c(v0)
800B48B0	nop
800B48B4	lbu    v0, $0851(v1)
800B48B8	nop
800B48BC	addiu  v0, v0, $ffff (=-$1)
800B48C0	sltiu  v0, v0, $0005
800B48C4	beq    v0, zero, Lb48d4 [$800b48d4]
800B48C8	nop

Lb48cc:	; 800B48CC
800B48CC	j      Lb4a48 [$800b4a48]
800B48D0	addiu  v0, zero, $0001

Lb48d4:	; 800B48D4
800B48D4	lw     v0, $08e4(v1)
800B48D8	nop

Lb48dc:	; 800B48DC
800B48DC	lw     v0, $000c(v0)
800B48E0	nop
800B48E4	lw     a0, $0014(v0)
800B48E8	nop
800B48EC	lw     v1, $0000(a0)
800B48F0	lui    v0, $0080

Lb48f4:	; 800B48F4
800B48F4	and    v0, v1, v0
800B48F8	beq    v0, zero, Lb49dc [$800b49dc]
800B48FC	lui    s1, $0010
800B4900	jal    func21fb4 [$80021fb4]
800B4904	nop
800B4908	bgtz   v0, Lb4a48 [$800b4a48]
800B490C	addiu  v0, zero, $0001
800B4910	jal    func223cc [$800223cc]
800B4914	nop
800B4918	lw     v0, $794c(s0)

Lb491c:	; 800B491C
800B491C	nop
800B4920	lw     v0, $001c(v0)

Lb4924:	; 800B4924
800B4924	nop
800B4928	lw     v0, $08e4(v0)
800B492C	nop
800B4930	lw     v0, $000c(v0)
800B4934	nop
800B4938	lw     v1, $0014(v0)
800B493C	nop
800B4940	lw     v0, $0000(v1)
800B4944	nop
800B4948	and    v0, v0, s1
800B494C	bne    v0, zero, Lb49a0 [$800b49a0]
800B4950	nop
800B4954	lw     a0, $0020(v1)
800B4958	jal    funcb3b2c [$800b3b2c]
800B495C	nop
800B4960	jal    funcb3f8c [$800b3f8c]
800B4964	nop
800B4968	lw     v0, $794c(s0)
800B496C	nop
800B4970	lw     v0, $001c(v0)
800B4974	nop
800B4978	lw     v0, $08e4(v0)
800B497C	nop
800B4980	lw     v0, $000c(v0)
800B4984	nop
800B4988	lw     v1, $0014(v0)
800B498C	nop
800B4990	lw     v0, $0000(v1)
800B4994	nop
800B4998	or     v0, v0, s1
800B499C	sw     v0, $0000(v1)

Lb49a0:	; 800B49A0
800B49A0	lw     v0, $794c(s0)
800B49A4	nop
800B49A8	lw     v0, $001c(v0)
800B49AC	nop
800B49B0	lw     v0, $08e4(v0)
800B49B4	nop
800B49B8	lw     v0, $000c(v0)
800B49BC	nop
800B49C0	lw     a0, $0014(v0)
800B49C4	lui    v1, $ff7f
800B49C8	lw     v0, $0000(a0)
800B49CC	ori    v1, v1, $ffff
800B49D0	and    v0, v0, v1
800B49D4	j      Lb48cc [$800b48cc]
800B49D8	sw     v0, $0000(a0)

Lb49dc:	; 800B49DC
800B49DC	and    v0, v1, s1
800B49E0	bne    v0, zero, Lb4a48 [$800b4a48]
800B49E4	addu   v0, zero, zero
800B49E8	lui    v0, $0001
800B49EC	and    v0, v1, v0
800B49F0	beq    v0, zero, Lb4a48 [$800b4a48]
800B49F4	addu   v0, zero, zero
800B49F8	lw     a0, $0020(a0)
800B49FC	jal    funcb3b2c [$800b3b2c]
800B4A00	nop
800B4A04	jal    funcb3f8c [$800b3f8c]
800B4A08	nop
800B4A0C	lw     v0, $794c(s0)
800B4A10	nop
800B4A14	lw     v0, $001c(v0)
800B4A18	nop
800B4A1C	lw     v0, $08e4(v0)
800B4A20	nop
800B4A24	lw     v0, $000c(v0)
800B4A28	nop
800B4A2C	lw     v1, $0014(v0)
800B4A30	nop
800B4A34	lw     v0, $0000(v1)
800B4A38	nop
800B4A3C	or     v0, v0, s1
800B4A40	sw     v0, $0000(v1)
800B4A44	addu   v0, zero, zero

Lb4a48:	; 800B4A48
800B4A48	lw     ra, $0018(sp)
800B4A4C	lw     s1, $0014(sp)
800B4A50	lw     s0, $0010(sp)
800B4A54	jr     ra 
800B4A58	addiu  sp, sp, $0020


funcb4a5c:	; 800B4A5C
800B4A5C	addiu  sp, sp, $ffa8 (=-$58)
800B4A60	addiu  a0, zero, $0004
800B4A64	lui    a1, $0004
800B4A68	ori    a1, a1, $4e20
800B4A6C	addu   a2, zero, zero

Lb4a70:	; 800B4A70
800B4A70	sw     ra, $0050(sp)
800B4A74	sw     s7, $004c(sp)
800B4A78	sw     s6, $0048(sp)
800B4A7C	sw     s5, $0044(sp)
800B4A80	sw     s4, $0040(sp)
800B4A84	sw     s3, $003c(sp)
800B4A88	sw     s2, $0038(sp)
800B4A8C	sw     s1, $0034(sp)
800B4A90	jal    func1c7fc [$8001c7fc]
800B4A94	sw     s0, $0030(sp)
800B4A98	addu   s0, v0, zero
800B4A9C	addu   a0, s0, zero
800B4AA0	addiu  a1, sp, $0020
800B4AA4	jal    func1d910 [$8001d910]
800B4AA8	addiu  a2, sp, $0024
800B4AAC	lw     v0, $0024(sp)
800B4AB0	nop
800B4AB4	lhu    a2, $0004(v0)
800B4AB8	lhu    a3, $0006(v0)
800B4ABC	addu   a0, s0, zero
800B4AC0	sh     zero, $0000(v0)
800B4AC4	lw     v1, $0020(sp)
800B4AC8	addiu  a1, zero, $0100
800B4ACC	sh     a1, $0002(v0)
800B4AD0	sh     a1, $0000(v1)
800B4AD4	lhu    a1, $0004(v1)
800B4AD8	lhu    a2, $0006(v1)
800B4ADC	addiu  v0, zero, $00e0
800B4AE0	jal    func1d8a8 [$8001d8a8]
800B4AE4	sh     v0, $0002(v1)
800B4AE8	jal    func130a4 [$800130a4]
800B4AEC	addu   a0, zero, zero
800B4AF0	lui    v0, $8006
800B4AF4	lw     v0, $794c(v0)
800B4AF8	nop
800B4AFC	lw     v0, $001c(v0)
800B4B00	addu   s4, zero, zero
800B4B04	lw     v0, $08e4(v0)
800B4B08	addu   s1, s4, zero
800B4B0C	lw     v0, $000c(v0)
800B4B10	addiu  s0, zero, $0001
800B4B14	lw     v0, $0014(v0)
800B4B18	addiu  t2, zero, $0080
800B4B1C	lw     t1, $0020(v0)

loopb4b20:	; 800B4B20
800B4B20	sll    a3, s0, $02
800B4B24	addiu  s3, sp, $0010
800B4B28	addu   a0, s3, a3
800B4B2C	sw     t1, $0000(a0)
800B4B30	addu   v1, t1, zero
800B4B34	addiu  v0, zero, $0004
800B4B38	sb     v0, $0003(v1)
800B4B3C	lw     v1, $0000(a0)
800B4B40	addiu  v0, zero, $0064
800B4B44	sb     v0, $0007(v1)
800B4B48	lw     v0, $0000(a0)
800B4B4C	nop
800B4B50	sb     t2, $0004(v0)
800B4B54	lw     v0, $0000(a0)
800B4B58	addiu  t1, t1, $0014
800B4B5C	sb     t2, $0005(v0)
800B4B60	lw     v0, $0000(a0)
800B4B64	lui    t0, $e100
800B4B68	sb     t2, $0006(v0)
800B4B6C	lw     a1, $0024(sp)
800B4B70	ori    t0, t0, $0600
800B4B74	lh     v1, $0004(a1)
800B4B78	addiu  v0, zero, $0140
800B4B7C	sll    v1, v1, $02
800B4B80	subu   v0, v0, v1
800B4B84	lw     v1, $0000(a0)
800B4B88	sra    v0, v0, $01
800B4B8C	sh     v0, $0008(v1)
800B4B90	lh     v1, $0006(a1)
800B4B94	addiu  v0, zero, $00e0
800B4B98	subu   v0, v0, v1
800B4B9C	srl    v1, v0, $1f
800B4BA0	addu   v0, v0, v1
800B4BA4	lw     v1, $0000(a0)
800B4BA8	sra    v0, v0, $01
800B4BAC	sh     v0, $000a(v1)
800B4BB0	lw     v0, $0000(a0)
800B4BB4	addiu  s2, sp, $0018
800B4BB8	sb     zero, $000c(v0)
800B4BBC	lw     v0, $0000(a0)
800B4BC0	nop
800B4BC4	sb     zero, $000d(v0)
800B4BC8	lw     a2, $0024(sp)
800B4BCC	addu   a3, s2, a3
800B4BD0	lh     v0, $0004(a2)
800B4BD4	lw     v1, $0000(a0)
800B4BD8	sll    v0, v0, $02
800B4BDC	addiu  v0, v0, $ffff (=-$1)
800B4BE0	sh     v0, $0010(v1)
800B4BE4	lw     a1, $0000(a0)
800B4BE8	lhu    v1, $0006(a2)
800B4BEC	lw     v0, $0020(sp)
800B4BF0	addiu  s0, s0, $ffff (=-$1)
800B4BF4	sh     v1, $0012(a1)
800B4BF8	lhu    v1, $0002(v0)
800B4BFC	lhu    v0, $0000(v0)
800B4C00	lw     a0, $0000(a0)
800B4C04	sll    v1, v1, $06
800B4C08	srl    v0, v0, $04

Lb4c0c:	; 800B4C0C
800B4C0C	andi   v0, v0, $003f
800B4C10	or     v1, v1, v0
800B4C14	sh     v1, $000e(a0)
800B4C18	sw     t1, $0000(a3)

Lb4c1c:	; 800B4C1C
800B4C1C	addu   v1, t1, zero
800B4C20	addiu  v0, zero, $0001
800B4C24	sb     v0, $0003(v1)
800B4C28	lw     v0, $0024(sp)
800B4C2C	addiu  t1, t1, $0008
800B4C30	lhu    a0, $0002(v0)
800B4C34	lhu    v0, $0000(v0)
800B4C38	andi   v1, a0, $0100
800B4C3C	sll    v1, v1, $10
800B4C40	sra    v1, v1, $14
800B4C44	andi   v0, v0, $03ff
800B4C48	srl    v0, v0, $06
800B4C4C	or     v1, v1, v0
800B4C50	andi   a0, a0, $0200
800B4C54	sll    a0, a0, $10
800B4C58	sra    a0, a0, $10
800B4C5C	sll    a0, a0, $02
800B4C60	or     v1, v1, a0
800B4C64	lw     v0, $0000(a3)
800B4C68	or     v1, v1, t0
800B4C6C	bgez   s0, loopb4b20 [$800b4b20]
800B4C70	sw     v1, $0004(v0)
800B4C74	jal    funcac67c [$800ac67c]
800B4C78	addu   a0, t1, zero
800B4C7C	jal    func223cc [$800223cc]
800B4C80	lui    s5, $8006
800B4C84	addu   a0, zero, zero
800B4C88	addu   a1, a0, zero
800B4C8C	jal    func1ccb4 [$8001ccb4]
800B4C90	addu   a2, a0, zero
800B4C94	addu   s7, s3, zero
800B4C98	lui    s3, $00ff
800B4C9C	ori    s3, s3, $ffff
800B4CA0	lui    s6, $ff00

Lb4ca4:	; 800B4CA4
800B4CA4	lw     v0, $794c(s5)
800B4CA8	nop
800B4CAC	lw     v1, $001c(v0)
800B4CB0	nop
800B4CB4	lbu    v0, $0008(v1)
800B4CB8	nop
800B4CBC	sll    v0, v0, $02

Lb4cc0:	; 800B4CC0
800B4CC0	addu   v1, v1, v0
800B4CC4	lw     a0, $0010(v1)
800B4CC8	jal    func13590 [$80013590]
800B4CCC	addiu  a1, zero, $1000
800B4CD0	addiu  v0, zero, $0001
800B4CD4	beq    s1, v0, Lb4d38 [$800b4d38]
800B4CD8	slt    v0, s0, s4
800B4CDC	beq    s1, zero, Lb4cfc [$800b4cfc]
800B4CE0	addiu  v0, zero, $0002
800B4CE4	beq    s1, v0, Lb4d50 [$800b4d50]
800B4CE8	addiu  v0, zero, $0003
800B4CEC	beq    s1, v0, Lb4d84 [$800b4d84]
800B4CF0	slt    v0, s0, s4
800B4CF4	j      Lb4d98 [$800b4d98]
800B4CF8	nop

Lb4cfc:	; 800B4CFC
800B4CFC	addiu  s4, zero, $003c
800B4D00	addu   s0, zero, zero
800B4D04	addiu  a0, zero, $0001
800B4D08	addu   a1, a0, zero
800B4D0C	addu   a2, s0, zero
800B4D10	lui    a3, $00ff
800B4D14	jal    func320b8 [$800320b8]
800B4D18	ori    a3, a3, $ffff
800B4D1C	addiu  a0, zero, $0001
800B4D20	addu   a1, a0, zero
800B4D24	addu   a2, s4, zero
800B4D28	jal    func320b8 [$800320b8]
800B4D2C	addu   a3, s0, zero
800B4D30	j      Lb4d98 [$800b4d98]
800B4D34	addiu  s1, zero, $0001

Lb4d38:	; 800B4D38
800B4D38	bne    v0, zero, Lb4d98 [$800b4d98]
800B4D3C	addiu  s0, s0, $0001
800B4D40	addiu  s4, zero, $0078
800B4D44	addu   s0, zero, zero
800B4D48	j      Lb4d98 [$800b4d98]
800B4D4C	addiu  s1, zero, $0002

Lb4d50:	; 800B4D50
800B4D50	slt    v0, s0, s4
800B4D54	bne    v0, zero, Lb4d98 [$800b4d98]
800B4D58	addiu  s0, s0, $0001
800B4D5C	addiu  s4, zero, $003c
800B4D60	addu   s0, zero, zero
800B4D64	addiu  a0, zero, $0001
800B4D68	addu   a1, a0, zero
800B4D6C	addu   a2, s4, zero
800B4D70	lui    a3, $00ff
800B4D74	jal    func320b8 [$800320b8]
800B4D78	ori    a3, a3, $ffff
800B4D7C	j      Lb4d98 [$800b4d98]
800B4D80	addiu  s1, zero, $0003

Lb4d84:	; 800B4D84
800B4D84	beq    v0, zero, Lb4d94 [$800b4d94]
800B4D88	nop
800B4D8C	j      Lb4d98 [$800b4d98]
800B4D90	addiu  s0, s0, $0001

Lb4d94:	; 800B4D94
800B4D94	addiu  s1, zero, $0004

Lb4d98:	; 800B4D98
800B4D98	lw     a2, $794c(s5)
800B4D9C	nop
800B4DA0	lw     v1, $001c(a2)
800B4DA4	nop
800B4DA8	lbu    v0, $0008(v1)
800B4DAC	nop
800B4DB0	sll    v0, v0, $02
800B4DB4	addu   a0, s7, v0
800B4DB8	addu   v1, v1, v0
800B4DBC	lw     v0, $0010(v1)
800B4DC0	lw     a0, $0000(a0)
800B4DC4	lw     v0, $0020(v0)
800B4DC8	lw     v1, $0000(a0)
800B4DCC	lw     v0, $0000(v0)
800B4DD0	and    v1, v1, s6
800B4DD4	and    v0, v0, s3
800B4DD8	or     v1, v1, v0
800B4DDC	sw     v1, $0000(a0)
800B4DE0	lw     v0, $001c(a2)
800B4DE4	nop
800B4DE8	lbu    a0, $0008(v0)
800B4DEC	nop
800B4DF0	sll    a0, a0, $02
800B4DF4	addu   v0, v0, a0
800B4DF8	lw     v0, $0010(v0)
800B4DFC	addu   a0, s7, a0
800B4E00	lw     a1, $0020(v0)
800B4E04	lw     v0, $0000(a0)
800B4E08	lw     v1, $0000(a1)
800B4E0C	and    v0, v0, s3
800B4E10	and    v1, v1, s6
800B4E14	or     v1, v1, v0
800B4E18	sw     v1, $0000(a1)
800B4E1C	lw     v1, $001c(a2)
800B4E20	nop
800B4E24	lbu    v0, $0008(v1)
800B4E28	nop
800B4E2C	sll    v0, v0, $02
800B4E30	addu   a0, s2, v0
800B4E34	addu   v1, v1, v0
800B4E38	lw     v0, $0010(v1)
800B4E3C	lw     a0, $0000(a0)
800B4E40	lw     v0, $0020(v0)
800B4E44	lw     v1, $0000(a0)
800B4E48	lw     v0, $0000(v0)
800B4E4C	and    v1, v1, s6
800B4E50	and    v0, v0, s3
800B4E54	or     v1, v1, v0
800B4E58	sw     v1, $0000(a0)
800B4E5C	lw     v0, $001c(a2)
800B4E60	nop
800B4E64	lbu    a0, $0008(v0)
800B4E68	nop
800B4E6C	sll    a0, a0, $02
800B4E70	addu   v0, v0, a0
800B4E74	lw     v0, $0010(v0)
800B4E78	addu   a0, s2, a0
800B4E7C	lw     a1, $0020(v0)
800B4E80	lw     v0, $0000(a0)
800B4E84	lw     v1, $0000(a1)
800B4E88	and    v0, v0, s3
800B4E8C	and    v1, v1, s6
800B4E90	or     v1, v1, v0
800B4E94	jal    func32098 [$80032098]
800B4E98	sw     v1, $0000(a1)
800B4E9C	jal    func130a4 [$800130a4]
800B4EA0	addu   a0, zero, zero
800B4EA4	lw     v1, $794c(s5)
800B4EA8	addiu  v0, zero, $0002
800B4EAC	sb     v0, $0009(v1)
800B4EB0	lw     v0, $794c(s5)
800B4EB4	nop
800B4EB8	lbu    a0, $0009(v0)
800B4EBC	jal    func15c58 [$80015c58]
800B4EC0	nop
800B4EC4	jal    func12d28 [$80012d28]
800B4EC8	addiu  a0, zero, $0001
800B4ECC	lw     v1, $794c(s5)
800B4ED0	nop
800B4ED4	lw     v0, $001c(v1)
800B4ED8	nop
800B4EDC	lbu    v0, $0008(v0)
800B4EE0	nop
800B4EE4	sll    a0, v0, $02
800B4EE8	addu   a0, a0, v0
800B4EEC	lw     v0, $000c(v1)
800B4EF0	sll    a0, a0, $02
800B4EF4	jal    func138d4 [$800138d4]
800B4EF8	addu   a0, v0, a0
800B4EFC	lw     a2, $794c(s5)
800B4F00	nop
800B4F04	lw     a0, $001c(a2)
800B4F08	nop
800B4F0C	lbu    v1, $0008(a0)
800B4F10	nop
800B4F14	sll    v0, v1, $02
800B4F18	addu   a0, a0, v0
800B4F1C	sll    a1, v1, $01
800B4F20	addu   a1, a1, v1
800B4F24	sll    a1, a1, $03
800B4F28	subu   a1, a1, v1
800B4F2C	sll    a1, a1, $02
800B4F30	lw     v0, $0010(a2)
800B4F34	lw     a0, $0010(a0)
800B4F38	addu   a1, v0, a1
800B4F3C	jal    func137c8 [$800137c8]
800B4F40	addiu  a0, a0, $3ffc
800B4F44	lw     v0, $794c(s5)
800B4F48	nop
800B4F4C	lw     v1, $001c(v0)
800B4F50	nop
800B4F54	lbu    v0, $0008(v1)
800B4F58	nop
800B4F5C	xori   v0, v0, $0001
800B4F60	sb     v0, $0008(v1)
800B4F64	sltiu  v0, s1, $0004
800B4F68	bne    v0, zero, Lb4ca4 [$800b4ca4]
800B4F6C	nop
800B4F70	lw     ra, $0050(sp)
800B4F74	lw     s7, $004c(sp)
800B4F78	lw     s6, $0048(sp)
800B4F7C	lw     s5, $0044(sp)
800B4F80	lw     s4, $0040(sp)
800B4F84	lw     s3, $003c(sp)
800B4F88	lw     s2, $0038(sp)
800B4F8C	lw     s1, $0034(sp)
800B4F90	lw     s0, $0030(sp)
800B4F94	jr     ra 
800B4F98	addiu  sp, sp, $0058


funcb4f9c:	; 800B4F9C
800B4F9C	lui    v0, $8006
800B4FA0	lw     v0, $794c(v0)
800B4FA4	nop
800B4FA8	lw     a0, $001c(v0)
800B4FAC	nop
800B4FB0	lw     v0, $08e4(a0)
800B4FB4	nop
800B4FB8	lw     v0, $000c(v0)
800B4FBC	nop
800B4FC0	lw     a1, $0014(v0)
800B4FC4	nop
800B4FC8	lbu    v1, $004a(a1)
800B4FCC	addiu  v0, zero, $0001
800B4FD0	bne    v1, v0, Lb4ffc [$800b4ffc]
800B4FD4	addu   v0, zero, zero
800B4FD8	lh     v1, $000c(a0)
800B4FDC	addiu  v0, zero, $0034
800B4FE0	bne    v1, v0, Lb4ffc [$800b4ffc]
800B4FE4	addu   v0, zero, zero
800B4FE8	lh     a0, $000a(a1)
800B4FEC	addiu  v1, zero, $0064
800B4FF0	beq    a0, v1, Lb4ffc [$800b4ffc]
800B4FF4	addiu  v0, zero, $0001
800B4FF8	addu   v0, zero, zero

Lb4ffc:	; 800B4FFC
800B4FFC	jr     ra 
800B5000	nop


funcb5004:	; 800B5004
800B5004	lui    v1, $800d
800B5008	addiu  v1, v1, $a058 (=-$5fa8)
800B500C	addiu  v0, zero, $0001
800B5010	sllv   v0, a0, v0
800B5014	sb     v0, $0001(v1)
800B5018	lui    v0, $8006
800B501C	sb     a0, $0002(v1)
800B5020	sh     a1, $0004(v1)
800B5024	lw     a1, $794c(v0)
800B5028	addiu  v0, zero, $ffff (=-$1)
800B502C	sh     v0, $0006(v1)
800B5030	lw     v0, $001c(a1)
800B5034	nop
800B5038	lw     a0, $08e4(v0)
800B503C	nop
800B5040	lw     v0, $0000(a0)
800B5044	lui    v1, $0010
800B5048	or     v0, v0, v1
800B504C	sw     v0, $0000(a0)
800B5050	lw     v0, $0000(a1)
800B5054	nop
800B5058	ori    v0, v0, $0008
800B505C	jr     ra 
800B5060	sw     v0, $0000(a1)

800B5064	lui    v0, $800d
800B5068	lbu    v0, $a05a(v0)
800B506C	jr     ra 
800B5070	nop

800B5074	lui    v0, $800d
800B5078	lbu    v0, $a059(v0)
800B507C	jr     ra 
800B5080	nop

800B5084	lui    v0, $800d
800B5088	lh     v0, $a05c(v0)
800B508C	jr     ra 
800B5090	nop

800B5094	lui    v0, $800d
800B5098	lh     v0, $a05e(v0)
800B509C	jr     ra 
800B50A0	nop


funcb50a4:	; 800B50A4
800B50A4	addiu  sp, sp, $ffe0 (=-$20)
800B50A8	sw     ra, $0018(sp)
800B50AC	sw     s1, $0014(sp)
800B50B0	jal    funcb5114 [$800b5114]
800B50B4	sw     s0, $0010(sp)
800B50B8	lui    a0, $800d
800B50BC	lbu    v1, $a058(a0)
800B50C0	addiu  v0, zero, $0004
800B50C4	beq    v1, v0, Lb50f8 [$800b50f8]
800B50C8	addu   s1, a0, zero
800B50CC	addu   s0, v0, zero

loopb50d0:	; 800B50D0
800B50D0	jal    funcb5290 [$800b5290]
800B50D4	nop
800B50D8	jal    funcb52dc [$800b52dc]
800B50DC	nop
800B50E0	jal    funcb532c [$800b532c]
800B50E4	nop
800B50E8	lbu    v0, $a058(s1)
800B50EC	nop
800B50F0	bne    v0, s0, loopb50d0 [$800b50d0]
800B50F4	nop

Lb50f8:	; 800B50F8
800B50F8	jal    funcb51d0 [$800b51d0]
800B50FC	nop
800B5100	lw     ra, $0018(sp)
800B5104	lw     s1, $0014(sp)
800B5108	lw     s0, $0010(sp)
800B510C	jr     ra 
800B5110	addiu  sp, sp, $0020


funcb5114:	; 800B5114
800B5114	addiu  sp, sp, $ffe8 (=-$18)
800B5118	addu   a0, zero, zero
800B511C	sw     ra, $0014(sp)
800B5120	jal    func130a4 [$800130a4]
800B5124	sw     s0, $0010(sp)
800B5128	addu   a1, zero, zero
800B512C	lui    a2, $0400
800B5130	ori    a2, a2, $0300
800B5134	lui    v0, $8007
800B5138	addiu  v1, v0, $3998
800B513C	lui    v0, $800d
800B5140	addiu  a0, v0, $a058 (=-$5fa8)

loopb5144:	; 800B5144
800B5144	lw     v0, $0000(v1)
800B5148	addiu  a1, a1, $0001
800B514C	sw     v0, $0008(a0)
800B5150	sw     a2, $0000(v1)
800B5154	addiu  v1, v1, $0004
800B5158	slti   v0, a1, $0002
800B515C	bne    v0, zero, loopb5144 [$800b5144]
800B5160	addiu  a0, a0, $0004
800B5164	lui    s0, $800d
800B5168	addiu  v0, zero, $0001
800B516C	sb     v0, $a058(s0)
800B5170	lui    v0, $8006
800B5174	lw     v1, $794c(v0)
800B5178	addiu  v0, s0, $a058 (=-$5fa8)
800B517C	sb     zero, $0003(v0)
800B5180	lw     v0, $001c(v1)
800B5184	nop
800B5188	lw     v0, $08e4(v0)
800B518C	jal    func2de60 [$8002de60]
800B5190	sw     zero, $0000(v0)
800B5194	lui    v1, $800d
800B5198	lbu    a0, $a058(s0)
800B519C	addiu  v1, v1, $9d5c (=-$62a4)
800B51A0	sll    v0, a0, $01
800B51A4	addu   v0, v0, a0
800B51A8	sll    v0, v0, $02
800B51AC	addu   v0, v0, v1
800B51B0	lw     v0, $0000(v0)
800B51B4	nop
800B51B8	jalr   v0 ra
800B51BC	nop
800B51C0	lw     ra, $0014(sp)
800B51C4	lw     s0, $0010(sp)
800B51C8	jr     ra 
800B51CC	addiu  sp, sp, $0018


funcb51d0:	; 800B51D0
800B51D0	addiu  sp, sp, $ffe8 (=-$18)
800B51D4	lui    v0, $800d
800B51D8	sw     s0, $0010(sp)
800B51DC	lui    s0, $800d
800B51E0	lbu    a0, $a058(s0)
800B51E4	addiu  v0, v0, $9d5c (=-$62a4)
800B51E8	sw     ra, $0014(sp)
800B51EC	sll    v1, a0, $01
800B51F0	addu   v1, v1, a0
800B51F4	sll    v1, v1, $02
800B51F8	addu   v1, v1, v0
800B51FC	lw     v0, $0008(v1)
800B5200	nop
800B5204	beq    v0, zero, Lb5214 [$800b5214]
800B5208	nop
800B520C	jalr   v0 ra
800B5210	nop

Lb5214:	; 800B5214
800B5214	jal    func130a4 [$800130a4]
800B5218	addu   a0, zero, zero
800B521C	addu   a1, zero, zero
800B5220	lui    v0, $8007
800B5224	addiu  a0, v0, $3998
800B5228	addiu  v1, s0, $a058 (=-$5fa8)

loopb522c:	; 800B522C
800B522C	lw     v0, $0008(v1)
800B5230	addiu  v1, v1, $0004
800B5234	addiu  a1, a1, $0001
800B5238	sw     v0, $0000(a0)
800B523C	slti   v0, a1, $0002
800B5240	bne    v0, zero, loopb522c [$800b522c]
800B5244	addiu  a0, a0, $0004
800B5248	lui    v0, $8006
800B524C	lw     v0, $794c(v0)
800B5250	nop
800B5254	lw     v0, $001c(v0)
800B5258	nop
800B525C	lw     a0, $08e4(v0)
800B5260	nop
800B5264	lw     v0, $0000(a0)
800B5268	lui    v1, $0001
800B526C	or     v0, v0, v1
800B5270	jal    func1de50 [$8001de50]
800B5274	sw     v0, $0000(a0)
800B5278	jal    funca9570 [$800a9570]
800B527C	nop
800B5280	lw     ra, $0014(sp)
800B5284	lw     s0, $0010(sp)
800B5288	jr     ra 
800B528C	addiu  sp, sp, $0018


funcb5290:	; 800B5290
800B5290	lui    v0, $8006
800B5294	lw     v0, $794c(v0)
800B5298	addiu  sp, sp, $ffe8 (=-$18)
800B529C	sw     ra, $0010(sp)
800B52A0	lw     v1, $001c(v0)
800B52A4	nop
800B52A8	lbu    v0, $0008(v1)
800B52AC	nop
800B52B0	sll    v0, v0, $02
800B52B4	addu   v1, v1, v0
800B52B8	lw     a0, $0010(v1)
800B52BC	jal    func13590 [$80013590]
800B52C0	addiu  a1, zero, $1000
800B52C4	jal    func19194 [$80019194]
800B52C8	nop

Lb52cc:	; 800B52CC
800B52CC	lw     ra, $0010(sp)
800B52D0	nop
800B52D4	jr     ra 
800B52D8	addiu  sp, sp, $0018


funcb52dc:	; 800B52DC
800B52DC	addiu  sp, sp, $ffe8 (=-$18)
800B52E0	lui    v1, $800d
800B52E4	lui    v0, $800d
800B52E8	lbu    a0, $a058(v0)
800B52EC	addiu  v1, v1, $9d5c (=-$62a4)
800B52F0	sw     ra, $0010(sp)
800B52F4	sll    v0, a0, $01
800B52F8	addu   v0, v0, a0
800B52FC	sll    v0, v0, $02
800B5300	addu   v0, v0, v1
800B5304	lw     v0, $0004(v0)
800B5308	nop
800B530C	beq    v0, zero, Lb531c [$800b531c]
800B5310	nop
800B5314	jalr   v0 ra
800B5318	nop

Lb531c:	; 800B531C
800B531C	lw     ra, $0010(sp)
800B5320	nop
800B5324	jr     ra 
800B5328	addiu  sp, sp, $0018


funcb532c:	; 800B532C
800B532C	addiu  sp, sp, $ffe8 (=-$18)
800B5330	sw     ra, $0014(sp)
800B5334	jal    func32100 [$80032100]
800B5338	sw     s0, $0010(sp)
800B533C	jal    func23a0c [$80023a0c]
800B5340	lui    s0, $8006
800B5344	jal    func32098 [$80032098]
800B5348	nop
800B534C	jal    func23a4c [$80023a4c]
800B5350	nop
800B5354	jal    func130a4 [$800130a4]
800B5358	addu   a0, zero, zero
800B535C	jal    func15c58 [$80015c58]
800B5360	addu   a0, zero, zero
800B5364	jal    func12d28 [$80012d28]
800B5368	addiu  a0, zero, $0001
800B536C	lw     v1, $794c(s0)
800B5370	nop
800B5374	lw     v0, $001c(v1)
800B5378	nop
800B537C	lbu    v0, $0008(v0)
800B5380	nop
800B5384	sll    a0, v0, $02
800B5388	addu   a0, a0, v0
800B538C	lw     v0, $000c(v1)
800B5390	sll    a0, a0, $02
800B5394	jal    func138d4 [$800138d4]
800B5398	addu   a0, v0, a0
800B539C	lw     a3, $794c(s0)
800B53A0	nop
800B53A4	lw     v0, $001c(a3)
800B53A8	nop
800B53AC	lbu    a2, $0008(v0)
800B53B0	nop
800B53B4	sll    v1, a2, $02
800B53B8	addu   v0, v0, v1
800B53BC	sll    a1, a2, $01
800B53C0	addu   a1, a1, a2
800B53C4	sll    a1, a1, $03
800B53C8	subu   a1, a1, a2
800B53CC	sll    a1, a1, $02
800B53D0	lw     a0, $0010(v0)
800B53D4	lw     v0, $0010(a3)
800B53D8	addiu  a0, a0, $3ffc
800B53DC	jal    func137c8 [$800137c8]
800B53E0	addu   a1, v0, a1
800B53E4	lw     v0, $794c(s0)
800B53E8	nop
800B53EC	lw     v1, $001c(v0)
800B53F0	nop
800B53F4	lbu    v0, $0008(v1)
800B53F8	nop
800B53FC	xori   v0, v0, $0001
800B5400	sb     v0, $0008(v1)
800B5404	lw     v0, $794c(s0)
800B5408	nop
800B540C	lw     v0, $001c(v0)
800B5410	nop
800B5414	lbu    a0, $0008(v0)
800B5418	jal    func2c0dc [$8002c0dc]
800B541C	nop
800B5420	lw     ra, $0014(sp)
800B5424	lw     s0, $0010(sp)
800B5428	jr     ra 
800B542C	addiu  sp, sp, $0018


funcb5430:	; 800B5430
800B5430	addiu  sp, sp, $ffe0 (=-$20)
800B5434	sw     s0, $0010(sp)
800B5438	lui    s0, $800d
800B543C	lbu    v1, $a058(s0)
800B5440	sw     s1, $0014(sp)
800B5444	addu   s1, a0, zero
800B5448	sw     ra, $001c(sp)

Lb544c:	; 800B544C
800B544C	beq    s1, v1, Lb54b4 [$800b54b4]
800B5450	sw     s2, $0018(sp)
800B5454	lui    v0, $800d
800B5458	addiu  s2, v0, $9d5c (=-$62a4)
800B545C	sll    v0, v1, $01
800B5460	addu   v0, v0, v1
800B5464	sll    v0, v0, $02
800B5468	addu   v0, v0, s2
800B546C	lw     v0, $0008(v0)
800B5470	nop
800B5474	beq    v0, zero, Lb5484 [$800b5484]
800B5478	nop
800B547C	jalr   v0 ra
800B5480	nop

Lb5484:	; 800B5484
800B5484	sb     s1, $a058(s0)
800B5488	andi   v1, s1, $00ff
800B548C	sll    v0, v1, $01
800B5490	addu   v0, v0, v1
800B5494	sll    v0, v0, $02
800B5498	addu   v0, v0, s2
800B549C	lw     v0, $0000(v0)
800B54A0	nop
800B54A4	beq    v0, zero, Lb54b4 [$800b54b4]
800B54A8	nop
800B54AC	jalr   v0 ra
800B54B0	nop

Lb54b4:	; 800B54B4
800B54B4	lw     ra, $001c(sp)
800B54B8	lw     s2, $0018(sp)
800B54BC	lw     s1, $0014(sp)
800B54C0	lw     s0, $0010(sp)
800B54C4	jr     ra 
800B54C8	addiu  sp, sp, $0020


funcb54cc:	; 800B54CC
800B54CC	lui    v0, $8006
800B54D0	lw     v0, $794c(v0)
800B54D4	nop
800B54D8	lw     v0, $001c(v0)
800B54DC	nop
800B54E0	lw     v0, $08e4(v0)
800B54E4	nop
800B54E8	lw     v0, $0000(v0)
800B54EC	nop
800B54F0	srl    v0, v0, $14
800B54F4	jr     ra 
800B54F8	andi   v0, v0, $0001

800B54FC	addiu  sp, sp, $ffe8 (=-$18)
800B5500	sw     ra, $0010(sp)
800B5504	jal    func2f9d0 [$8002f9d0]
800B5508	nop
800B550C	jal    func35430 [$80035430]
800B5510	nop
800B5514	lui    a0, $800b
800B5518	jal    func3556c [$8003556c]
800B551C	addiu  a0, a0, $57c8
800B5520	lui    a0, $800a
800B5524	jal    func3575c [$8003575c]

Lb5528:	; 800B5528
800B5528	addiu  a0, a0, $717c
800B552C	lw     ra, $0010(sp)
800B5530	nop
800B5534	jr     ra 
800B5538	addiu  sp, sp, $0018

800B553C	addiu  sp, sp, $ffe8 (=-$18)
800B5540	sw     ra, $0010(sp)
800B5544	jal    func2c308 [$8002c308]
800B5548	addu   a0, zero, zero
800B554C	jal    funcb559c [$800b559c]
800B5550	nop
800B5554	jal    funcb5660 [$800b5660]
800B5558	nop
800B555C	jal    func35490 [$80035490]
800B5560	nop
800B5564	lw     ra, $0010(sp)
800B5568	nop
800B556C	jr     ra 
800B5570	addiu  sp, sp, $0018

800B5574	addiu  sp, sp, $ffe8 (=-$18)
800B5578	sw     ra, $0010(sp)
800B557C	jal    func35580 [$80035580]
800B5580	addu   a0, zero, zero
800B5584	jal    func3556c [$8003556c]
800B5588	addu   a0, zero, zero
800B558C	lw     ra, $0010(sp)
800B5590	nop
800B5594	jr     ra 
800B5598	addiu  sp, sp, $0018


funcb559c:	; 800B559C
800B559C	addiu  sp, sp, $ffe8 (=-$18)
800B55A0	sw     ra, $0014(sp)
800B55A4	jal    func2f810 [$8002f810]
800B55A8	sw     s0, $0010(sp)
800B55AC	andi   v0, v0, $00ff
800B55B0	bne    v0, zero, Lb5650 [$800b5650]
800B55B4	lui    v0, $8007
800B55B8	lw     v1, $7528(v0)
800B55BC	nop
800B55C0	andi   v0, v1, $0050
800B55C4	beq    v0, zero, Lb55f0 [$800b55f0]
800B55C8	lui    v0, $0001
800B55CC	jal    func2f488 [$8002f488]
800B55D0	addiu  a0, zero, $0067
800B55D4	lui    v1, $800d
800B55D8	addiu  v1, v1, $a058 (=-$5fa8)
800B55DC	lbu    v0, $0003(v1)
800B55E0	nop
800B55E4	xori   v0, v0, $0001
800B55E8	j      Lb5650 [$800b5650]
800B55EC	sb     v0, $0003(v1)

Lb55f0:	; 800B55F0
800B55F0	and    v0, v1, v0
800B55F4	beq    v0, zero, Lb5624 [$800b5624]
800B55F8	lui    v0, $800d
800B55FC	addiu  s0, v0, $a058 (=-$5fa8)
800B5600	lbu    v0, $0003(s0)
800B5604	nop
800B5608	bne    v0, zero, Lb5650 [$800b5650]
800B560C	nop
800B5610	jal    func2f488 [$8002f488]
800B5614	addiu  a0, zero, $0067
800B5618	addiu  v0, zero, $0001
800B561C	j      Lb5650 [$800b5650]
800B5620	sb     v0, $0003(s0)

Lb5624:	; 800B5624
800B5624	lui    v0, $0002
800B5628	and    v0, v1, v0
800B562C	beq    v0, zero, Lb5650 [$800b5650]
800B5630	nop
800B5634	jal    func2f488 [$8002f488]
800B5638	addiu  a0, zero, $0067
800B563C	jal    func2f9f0 [$8002f9f0]
800B5640	nop
800B5644	lui    a0, $800b
800B5648	jal    func2f8a8 [$8002f8a8]
800B564C	addiu  a0, a0, $5794

Lb5650:	; 800B5650
800B5650	lw     ra, $0014(sp)
800B5654	lw     s0, $0010(sp)
800B5658	jr     ra 
800B565C	addiu  sp, sp, $0018


funcb5660:	; 800B5660
800B5660	addiu  sp, sp, $ffd8 (=-$28)
800B5664	addiu  a2, zero, $000a
800B5668	lui    a3, $800a
800B566C	sw     s0, $0018(sp)
800B5670	lui    s0, $800d
800B5674	lh     a0, $9d98(s0)
800B5678	addiu  a3, a3, $7170
800B567C	sw     s1, $001c(sp)
800B5680	addiu  s1, s0, $9d98 (=-$6268)
800B5684	sw     ra, $0020(sp)
800B5688	sw     zero, $0010(sp)
800B568C	lh     a1, $0002(s1)
800B5690	addiu  a0, a0, $0008
800B5694	jal    func2b524 [$8002b524]
800B5698	addiu  a1, a1, $fffd (=-$3)
800B569C	jal    func35774 [$80035774]
800B56A0	addu   a0, zero, zero
800B56A4	addiu  a2, zero, $000a
800B56A8	lh     a0, $9d98(s0)
800B56AC	addu   a3, v0, zero
800B56B0	sw     zero, $0010(sp)
800B56B4	lh     a1, $0002(s1)
800B56B8	addiu  a0, a0, $000e
800B56BC	jal    func2b5fc [$8002b5fc]
800B56C0	addu   a1, a1, a2
800B56C4	jal    func35774 [$80035774]
800B56C8	addiu  a0, zero, $0001
800B56CC	addiu  a2, zero, $000a
800B56D0	lh     a0, $9d98(s0)
800B56D4	addu   a3, v0, zero
800B56D8	sw     zero, $0010(sp)
800B56DC	lh     a1, $0002(s1)
800B56E0	addiu  a0, a0, $0030
800B56E4	jal    func2b5fc [$8002b5fc]
800B56E8	addiu  a1, a1, $002e
800B56EC	jal    func35774 [$80035774]
800B56F0	addiu  a0, zero, $0002
800B56F4	addiu  a2, zero, $000a
800B56F8	lh     a0, $9d98(s0)

Lb56fc:	; 800B56FC
800B56FC	addu   a3, v0, zero
800B5700	sw     zero, $0010(sp)
800B5704	lh     a1, $0002(s1)
800B5708	addiu  a0, a0, $0030
800B570C	jal    func2b5fc [$8002b5fc]
800B5710	addiu  a1, a1, $003d
800B5714	jal    func2f810 [$8002f810]
800B5718	nop
800B571C	andi   v0, v0, $00ff
800B5720	bne    v0, zero, Lb5770 [$800b5770]
800B5724	lui    a0, $800d
800B5728	lhu    v0, $9d98(s0)
800B572C	lui    v1, $8007
800B5730	addiu  v0, v0, $0016
800B5734	sh     v0, $7de8(v1)
800B5738	lui    v0, $800d
800B573C	lbu    v0, $a05b(v0)
800B5740	lh     a0, $0002(s1)
800B5744	bne    v0, zero, Lb5754 [$800b5754]
800B5748	addiu  v1, v1, $7de8
800B574C	j      Lb5758 [$800b5758]
800B5750	addiu  v0, a0, $0032

Lb5754:	; 800B5754
800B5754	addiu  v0, a0, $0041

Lb5758:	; 800B5758
800B5758	sh     v0, $0002(v1)
800B575C	lui    v1, $8007
800B5760	addiu  v0, zero, $0009
800B5764	jal    func355e4 [$800355e4]
800B5768	sw     v0, $7dec(v1)
800B576C	lui    a0, $800d

Lb5770:	; 800B5770
800B5770	addiu  a0, a0, $9d98 (=-$6268)
800B5774	addiu  a1, zero, $000a
800B5778	jal    func2dee4 [$8002dee4]
800B577C	addiu  a2, zero, $0002
800B5780	lw     ra, $0020(sp)
800B5784	lw     s1, $001c(sp)
800B5788	lw     s0, $0018(sp)
800B578C	jr     ra 
800B5790	addiu  sp, sp, $0028

800B5794	lui    v0, $800d
800B5798	lbu    v0, $a05b(v0)
800B579C	addiu  sp, sp, $ffe8 (=-$18)
800B57A0	sw     ra, $0010(sp)
800B57A4	bne    v0, zero, Lb57b0 [$800b57b0]
800B57A8	addiu  a0, zero, $0003
800B57AC	addiu  a0, zero, $0002

Lb57b0:	; 800B57B0
800B57B0	jal    funcb5430 [$800b5430]
800B57B4	nop
800B57B8	lw     ra, $0010(sp)
800B57BC	nop
800B57C0	jr     ra 
800B57C4	addiu  sp, sp, $0018

800B57C8	addiu  sp, sp, $ffe0 (=-$20)
800B57CC	lui    v0, $8007
800B57D0	sw     s0, $0018(sp)
800B57D4	addiu  s0, v0, $7de8
800B57D8	sw     ra, $001c(sp)
800B57DC	jal    func2f810 [$8002f810]
800B57E0	sw     zero, $0008(s0)
800B57E4	andi   v0, v0, $00ff
800B57E8	bne    v0, zero, Lb5860 [$800b5860]
800B57EC	lui    v0, $800d
800B57F0	lbu    v0, $a05b(v0)
800B57F4	nop
800B57F8	bne    v0, zero, Lb5810 [$800b5810]
800B57FC	lui    v0, $8006
800B5800	jal    func35580 [$80035580]
800B5804	addu   a0, zero, zero
800B5808	j      Lb5854 [$800b5854]
800B580C	addiu  a0, zero, $0003

Lb5810:	; 800B5810
800B5810	lhu    a1, $0002(s0)
800B5814	lw     v1, $794c(v0)
800B5818	sh     zero, $0010(sp)
800B581C	sh     a1, $0012(sp)
800B5820	lw     v0, $000c(v1)
800B5824	nop
800B5828	lhu    v0, $0004(v0)
800B582C	nop
800B5830	sh     v0, $0014(sp)
800B5834	lw     v0, $000c(v1)
800B5838	nop
800B583C	lhu    v0, $0006(v0)
800B5840	addiu  a0, sp, $0010
800B5844	subu   v0, v0, a1
800B5848	jal    func35580 [$80035580]
800B584C	sh     v0, $0016(sp)
800B5850	addiu  a0, zero, $0004

Lb5854:	; 800B5854
800B5854	jal    func35774 [$80035774]
800B5858	nop
800B585C	sw     v0, $0008(s0)

Lb5860:	; 800B5860
800B5860	lw     ra, $001c(sp)
800B5864	lw     s0, $0018(sp)
800B5868	jr     ra 
800B586C	addiu  sp, sp, $0020

800B5870	addiu  sp, sp, $ffe8 (=-$18)
800B5874	addiu  a0, zero, $0004
800B5878	sw     ra, $0010(sp)
800B587C	jal    func32120 [$80032120]
800B5880	addiu  a1, zero, $0002
800B5884	lui    a0, $800b
800B5888	jal    func32628 [$80032628]
800B588C	addiu  a0, a0, $58b8
800B5890	jal    func32634 [$80032634]
800B5894	addu   a0, zero, zero
800B5898	lw     ra, $0010(sp)
800B589C	nop
800B58A0	jr     ra 
800B58A4	addiu  sp, sp, $0018

800B58A8	jr     ra 
800B58AC	nop

800B58B0	jr     ra 

Lb58b4:	; 800B58B4
800B58B4	nop

800B58B8	addiu  sp, sp, $ffe8 (=-$18)
800B58BC	sw     ra, $0010(sp)
800B58C0	jal    funcb5430 [$800b5430]
800B58C4	addiu  a0, zero, $0001
800B58C8	lw     ra, $0010(sp)
800B58CC	nop
800B58D0	jr     ra 
800B58D4	addiu  sp, sp, $0018

800B58D8	addiu  sp, sp, $ffe8 (=-$18)
800B58DC	lui    v0, $800d
800B58E0	addiu  v0, v0, $a058 (=-$5fa8)
800B58E4	addiu  a0, zero, $0008
800B58E8	sw     ra, $0010(sp)
800B58EC	lbu    a1, $0002(v0)
800B58F0	lh     v0, $0004(v0)
800B58F4	andi   a1, a1, $0003
800B58F8	sll    a1, a1, $0e
800B58FC	jal    func32120 [$80032120]
800B5900	or     a1, a1, v0
800B5904	lui    a0, $800b
800B5908	jal    func32628 [$80032628]
800B590C	addiu  a0, a0, $5938
800B5910	jal    func32634 [$80032634]
800B5914	addu   a0, zero, zero
800B5918	lw     ra, $0010(sp)
800B591C	nop
800B5920	jr     ra 
800B5924	addiu  sp, sp, $0018

800B5928	jr     ra 
800B592C	nop

800B5930	jr     ra 
800B5934	nop

800B5938	addiu  sp, sp, $ffe8 (=-$18)
800B593C	sw     ra, $0010(sp)
800B5940	jal    funcb5430 [$800b5430]
800B5944	addiu  a0, zero, $0004
800B5948	lw     ra, $0010(sp)
800B594C	nop
800B5950	jr     ra 
800B5954	addiu  sp, sp, $0018



////////////////////////////////
// funcb5958
800B5958-800B61A0
////////////////////////////////



////////////////////////////////
// funcb61a4
800B61A4-800B6434
////////////////////////////////



funcb6438:	; 800B6438
800B6438	lw     t0, $0008(a0)
800B643C	nop
800B6440	lhu    v1, $0000(t0)
800B6444	nop
800B6448	andi   v0, v1, $0001
800B644C	bne    v0, zero, Lb64d4 [$800b64d4]
800B6450	ori    v0, v1, $0001
800B6454	addu   a3, zero, zero
800B6458	sh     v0, $0000(t0)
800B645C	lw     v0, $000c(t0)
800B6460	lw     v1, $0010(t0)
800B6464	addu   v0, t0, v0
800B6468	sw     v0, $000c(t0)
800B646C	lbu    v0, $0003(t0)
800B6470	addu   v1, t0, v1
800B6474	beq    v0, zero, Lb64d4 [$800b64d4]
800B6478	sw     v1, $0010(t0)
800B647C	addiu  a2, v1, $0024

loopb6480:	; 800B6480
800B6480	addiu  a3, a3, $0001
800B6484	lw     v0, $fff0(a2)
800B6488	lw     v1, $fff8(a2)
800B648C	addu   v0, t0, v0
800B6490	sw     v0, $fff0(a2)
800B6494	lw     v0, $fff4(a2)
800B6498	addu   v1, t0, v1
800B649C	sw     v1, $fff8(a2)
800B64A0	lw     v1, $0000(a2)
800B64A4	addu   v0, t0, v0
800B64A8	sw     v0, $fff4(a2)
800B64AC	lw     v0, $fffc(a2)
800B64B0	addu   v1, t0, v1
800B64B4	sw     v1, $0000(a2)
800B64B8	addu   v0, t0, v0
800B64BC	sw     v0, $fffc(a2)
800B64C0	lbu    v0, $0003(t0)
800B64C4	nop
800B64C8	sltu   v0, a3, v0
800B64CC	bne    v0, zero, loopb6480 [$800b6480]
800B64D0	addiu  a2, a2, $0028

Lb64d4:	; 800B64D4
800B64D4	lw     v0, $0008(a0)
800B64D8	nop
800B64DC	lw     a2, $0010(v0)
800B64E0	nop
800B64E4	bltz   a2, Lb64f0 [$800b64f0]
800B64E8	addu   v1, zero, zero
800B64EC	addu   a2, a2, v0

Lb64f0:	; 800B64F0
800B64F0	lbu    t1, $0003(v0)
800B64F4	nop
800B64F8	sltu   v0, v1, t1
800B64FC	beq    v0, zero, Lb651c [$800b651c]
800B6500	addu   a3, zero, zero

loopb6504:	; 800B6504
800B6504	lhu    v0, $0000(a2)
800B6508	addiu  a3, a3, $0001
800B650C	addu   v1, v1, v0
800B6510	sltu   v0, a3, t1
800B6514	bne    v0, zero, loopb6504 [$800b6504]
800B6518	addiu  a2, a2, $0028

Lb651c:	; 800B651C
800B651C	addiu  v0, zero, $1000
800B6520	sll    v1, v1, $01
800B6524	sh     v0, $0054(a0)
800B6528	sh     v0, $0056(a0)
800B652C	sh     v0, $0058(a0)
800B6530	lhu    v0, $0000(a0)
800B6534	addu   v1, a1, v1
800B6538	sw     zero, $001c(a0)
800B653C	sw     zero, $0060(a0)
800B6540	sw     zero, $005c(a0)
800B6544	sw     zero, $0014(a0)
800B6548	sh     zero, $0074(a0)
800B654C	sh     zero, $0076(a0)
800B6550	sh     zero, $0078(a0)
800B6554	sw     a1, $0010(a0)
800B6558	sw     zero, $0050(a0)
800B655C	sw     v1, $0020(a0)
800B6560	ori    v0, v0, $0002
800B6564	sh     v0, $0000(a0)
800B6568	sh     zero, $0000(a0)
800B656C	lbu    v0, $0002(t0)
800B6570	nop
800B6574	sll    v0, v0, $05
800B6578	addu   v1, v1, v0
800B657C	jr     ra 
800B6580	sw     v1, $0044(a0)



////////////////////////////////
// funcb6584
800B6584-800B71DC
////////////////////////////////



800B71E0	lui    v0, $8006
800B71E4	lw     v0, $794c(v0)
800B71E8	addiu  sp, sp, $ffe0 (=-$20)
800B71EC	sw     s4, $0018(sp)
800B71F0	sw     s3, $0014(sp)
800B71F4	sw     s2, $0010(sp)
800B71F8	sw     s1, $000c(sp)
800B71FC	sw     s0, $0008(sp)
800B7200	lw     v0, $001c(v0)
800B7204	addu   a2, a0, zero
800B7208	lbu    a0, $0008(v0)
800B720C	andi   a1, a1, $00ff
800B7210	sll    v1, a0, $02
800B7214	addu   v0, v0, v1
800B7218	lw     s2, $0010(v0)
800B721C	sll    v0, a1, $02
800B7220	lw     v1, $0008(a2)
800B7224	addu   v0, v0, a1
800B7228	lw     v1, $0010(v1)
800B722C	sll    v0, v0, $03
800B7230	beq    a0, zero, Lb725c [$800b725c]
800B7234	addu   s4, v1, v0
800B7238	sll    v0, a1, $01
800B723C	addu   v0, v0, a1
800B7240	lw     v1, $0044(a2)
800B7244	sll    v0, v0, $02
800B7248	addu   v0, v0, v1
800B724C	lhu    v1, $0000(s4)
800B7250	lw     v0, $0004(v0)
800B7254	j      Lb7274 [$800b7274]
800B7258	addu   v0, v0, v1

Lb725c:	; 800B725C
800B725C	sll    v0, a1, $01
800B7260	addu   v0, v0, a1
800B7264	lw     v1, $0044(a2)
800B7268	sll    v0, v0, $02
800B726C	addu   v0, v0, v1
800B7270	lw     v0, $0004(v0)

Lb7274:	; 800B7274
800B7274	nop
800B7278	addu   t1, v0, zero
800B727C	addu   t2, zero, zero
800B7280	lhu    t8, $0002(s4)
800B7284	lb     v0, $0013(s4)
800B7288	lw     t7, $001c(s4)
800B728C	sll    v0, v0, $02
800B7290	beq    t8, zero, Lb73e0 [$800b73e0]
800B7294	subu   s2, s2, v0
800B7298	lui    v0, $8007
800B729C	addiu  s1, v0, $11a8
800B72A0	lui    s3, $ff00
800B72A4	lui    v0, $8007
800B72A8	addiu  s0, v0, $0520
800B72AC	lui    t9, $00ff
800B72B0	ori    t9, t9, $ffff
800B72B4	addiu  t5, t1, $0020
800B72B8	addiu  t6, t7, $0015

loopb72bc:	; 800B72BC
800B72BC	lw     v0, $0000(t7)
800B72C0	lw     v1, $ffef(t6)
800B72C4	srl    a0, v0, $10
800B72C8	srl    a1, v1, $10
800B72CC	andi   v0, v0, $ffff
800B72D0	andi   v1, v1, $ffff
800B72D4	sll    t4, v0, $02
800B72D8	addu   v0, t4, s1
800B72DC	sll    a0, a0, $02
800B72E0	lw     t0, $0000(v0)
800B72E4	addu   v0, a0, s1
800B72E8	sll    t3, v1, $02
800B72EC	addu   v1, t3, s1
800B72F0	lw     a3, $0000(v0)
800B72F4	lbu    v0, $0000(t6)
800B72F8	lw     a2, $0000(v1)
800B72FC	andi   v0, v0, $0002
800B7300	bne    v0, zero, Lb733c [$800b733c]
800B7304	addiu  t2, t2, $0001
800B7308	mtc2   t0,l33
800B730C	mtc2   a2,gbk
800B7310	mtc2   a3,rbk
800B7314	lw     v0, $0000(t1)
800B7318	nop
800B731C	and    v0, v0, s3
800B7320	sw     v0, $0000(t1)
800B7324	gte_func26zero,r11r12
800B7328	swc2   t8, $0000(sp)
800B732C	lw     v0, $0000(sp)
800B7330	nop
800B7334	blez   v0, Lb73c8 [$800b73c8]
800B7338	nop

Lb733c:	; 800B733C
800B733C	addu   v0, t4, s0
800B7340	addu   a0, a0, s0
800B7344	lw     v1, $0000(v0)
800B7348	lw     v0, $0000(a0)
800B734C	addu   a0, t3, s0
800B7350	sll    a1, a1, $02
800B7354	lw     a0, $0000(a0)
800B7358	addu   v1, v1, v0
800B735C	addu   v0, a1, s0
800B7360	addu   v1, v1, a0
800B7364	lw     v0, $0000(v0)
800B7368	addu   a1, a1, s1
800B736C	addu   v1, v1, v0
800B7370	sra    v1, v1, $04
800B7374	sw     v1, $0004(sp)
800B7378	sw     t0, $ffe8(t5)
800B737C	sw     a3, $fff0(t5)
800B7380	sw     a2, $fff8(t5)
800B7384	lw     v0, $0000(a1)
800B7388	nop
800B738C	sw     v0, $0000(t5)
800B7390	lw     a0, $0004(sp)
800B7394	lw     v1, $0000(t1)
800B7398	sll    a0, a0, $02
800B739C	addu   a0, a0, s2
800B73A0	lw     v0, $0000(a0)
800B73A4	and    v1, v1, s3
800B73A8	and    v0, v0, t9
800B73AC	or     v1, v1, v0
800B73B0	sw     v1, $0000(t1)
800B73B4	lw     v0, $0000(a0)
800B73B8	and    v1, t1, t9
800B73BC	and    v0, v0, s3
800B73C0	or     v0, v0, v1
800B73C4	sw     v0, $0000(a0)

Lb73c8:	; 800B73C8
800B73C8	addiu  t6, t6, $0018
800B73CC	addiu  t7, t7, $0018
800B73D0	addiu  t5, t5, $0028
800B73D4	sltu   v0, t2, t8
800B73D8	bne    v0, zero, loopb72bc [$800b72bc]
800B73DC	addiu  t1, t1, $0028

Lb73e0:	; 800B73E0
800B73E0	lhu    t8, $0004(s4)
800B73E4	addu   a1, t1, zero
800B73E8	beq    t8, zero, Lb7518 [$800b7518]
800B73EC	addu   t2, zero, zero
800B73F0	lui    v0, $8007
800B73F4	addiu  s3, v0, $11a8

funcb73f8:	; 800B73F8
800B73F8	lui    s1, $ff00
800B73FC	lui    v0, $8007
800B7400	addiu  s0, v0, $0520
800B7404	lui    t9, $00ff
800B7408	ori    t9, t9, $ffff
800B740C	addiu  t4, a1, $0018
800B7410	addiu  t6, t7, $0012

loopb7414:	; 800B7414
800B7414	lw     v0, $0000(t7)
800B7418	lhu    v1, $fff2(t6)
800B741C	srl    a0, v0, $10
800B7420	andi   v0, v0, $ffff
800B7424	sll    t5, v0, $02
800B7428	addu   v0, t5, s3
800B742C	sll    t3, a0, $02
800B7430	lw     t0, $0000(v0)
800B7434	addu   v0, t3, s3
800B7438	sll    t1, v1, $02
800B743C	addu   v1, t1, s3
800B7440	lw     a3, $0000(v0)
800B7444	lbu    v0, $0000(t6)
800B7448	lw     a2, $0000(v1)
800B744C	andi   v0, v0, $0002
800B7450	bne    v0, zero, Lb748c [$800b748c]
800B7454	addiu  t2, t2, $0001
800B7458	mtc2   t0,l33
800B745C	mtc2   a2,gbk
800B7460	mtc2   a3,rbk
800B7464	lw     v0, $0000(a1)
800B7468	nop

Lb746c:	; 800B746C
800B746C	and    v0, v0, s1
800B7470	sw     v0, $0000(a1)
800B7474	gte_func26zero,r11r12
800B7478	swc2   t8, $0000(sp)
800B747C	lw     v0, $0000(sp)
800B7480	nop
800B7484	blez   v0, Lb7500 [$800b7500]
800B7488	nop

Lb748c:	; 800B748C
800B748C	addu   a0, t5, s0
800B7490	addu   v1, t3, s0
800B7494	addu   v0, t1, s0
800B7498	lw     a0, $0000(a0)
800B749C	lw     v1, $0000(v1)
800B74A0	lw     v0, $0000(v0)
800B74A4	mtc2   a0,lr3lg1
800B74A8	mtc2   v1,lg2lg3
800B74AC	mtc2   v0,lb1lb2
800B74B0	sw     t0, $fff0(t4)
800B74B4	sw     a3, $fff8(t4)
800B74B8	gte_func26t8,r11r12
800B74BC	addiu  v0, sp, $0004
800B74C0	sw     a2, $0000(t4)
800B74C4	swc2   a3, $0000(v0)
800B74C8	lw     a0, $0004(sp)
800B74CC	lw     v1, $0000(a1)
800B74D0	sll    a0, a0, $02
800B74D4	addu   a0, a0, s2
800B74D8	lw     v0, $0000(a0)
800B74DC	and    v1, v1, s1
800B74E0	and    v0, v0, t9
800B74E4	or     v1, v1, v0
800B74E8	sw     v1, $0000(a1)
800B74EC	lw     v0, $0000(a0)
800B74F0	and    v1, a1, t9
800B74F4	and    v0, v0, s1
800B74F8	or     v0, v0, v1
800B74FC	sw     v0, $0000(a0)

Lb7500:	; 800B7500
800B7500	addiu  t6, t6, $0014
800B7504	addiu  t7, t7, $0014
800B7508	addiu  t4, t4, $0020
800B750C	sltu   v0, t2, t8
800B7510	bne    v0, zero, loopb7414 [$800b7414]
800B7514	addiu  a1, a1, $0020

Lb7518:	; 800B7518
800B7518	lhu    t8, $0006(s4)
800B751C	addu   t1, a1, zero
800B7520	beq    t8, zero, Lb7674 [$800b7674]
800B7524	addu   t2, zero, zero
800B7528	lui    v0, $8007
800B752C	addiu  s1, v0, $11a8
800B7530	lui    s3, $ff00
800B7534	lui    v0, $8007
800B7538	addiu  s0, v0, $0520
800B753C	lui    t9, $00ff
800B7540	ori    t9, t9, $ffff
800B7544	addiu  t5, t1, $002c
800B7548	addiu  t6, t7, $001c

loopb754c:	; 800B754C
800B754C	lw     v0, $0000(t7)
800B7550	lw     v1, $ffe8(t6)
800B7554	srl    a0, v0, $10
800B7558	srl    a1, v1, $10
800B755C	andi   v0, v0, $ffff
800B7560	andi   v1, v1, $ffff
800B7564	sll    t4, v0, $02

Lb7568:	; 800B7568
800B7568	addu   v0, t4, s1
800B756C	sll    a0, a0, $02
800B7570	lw     t0, $0000(v0)
800B7574	addu   v0, a0, s1
800B7578	sll    t3, v1, $02
800B757C	addu   v1, t3, s1
800B7580	lw     a3, $0000(v0)
800B7584	lbu    v0, $0000(t6)

Lb7588:	; 800B7588
800B7588	lw     a2, $0000(v1)
800B758C	andi   v0, v0, $0002
800B7590	bne    v0, zero, Lb75cc [$800b75cc]
800B7594	addiu  t2, t2, $0001
800B7598	mtc2   t0,l33
800B759C	mtc2   a2,gbk
800B75A0	mtc2   a3,rbk

Lb75a4:	; 800B75A4
800B75A4	lw     v0, $0000(t1)
800B75A8	nop
800B75AC	and    v0, v0, s3
800B75B0	sw     v0, $0000(t1)
800B75B4	gte_func26zero,r11r12
800B75B8	swc2   t8, $0000(sp)
800B75BC	lw     v0, $0000(sp)
800B75C0	nop
800B75C4	blez   v0, Lb765c [$800b765c]
800B75C8	nop

Lb75cc:	; 800B75CC
800B75CC	addu   v0, t4, s0
800B75D0	addu   a0, a0, s0
800B75D4	lw     v1, $0000(v0)
800B75D8	lw     v0, $0000(a0)
800B75DC	addu   a0, t3, s0
800B75E0	sll    a1, a1, $02
800B75E4	lw     a0, $0000(a0)
800B75E8	addu   v1, v1, v0
800B75EC	addu   v0, a1, s0
800B75F0	addu   v1, v1, a0
800B75F4	lw     v0, $0000(v0)
800B75F8	addu   a1, a1, s1

Lb75fc:	; 800B75FC
800B75FC	addu   v1, v1, v0
800B7600	sw     v1, $0004(sp)

Lb7604:	; 800B7604
800B7604	sw     t0, $ffdc(t5)
800B7608	sw     a3, $ffe8(t5)
800B760C	sw     a2, $fff4(t5)
800B7610	lw     v0, $0000(a1)
800B7614	nop
800B7618	sw     v0, $0000(t5)
800B761C	lw     a1, $0004(sp)
800B7620	lw     v1, $0000(t1)
800B7624	sra    a1, a1, $04
800B7628	sll    a0, a1, $02
800B762C	addu   a0, a0, s2
800B7630	lw     v0, $0000(a0)
800B7634	and    v1, v1, s3
800B7638	and    v0, v0, t9
800B763C	or     v1, v1, v0
800B7640	sw     v1, $0000(t1)
800B7644	lw     v1, $0000(a0)
800B7648	and    v0, t1, t9
800B764C	sw     a1, $0004(sp)
800B7650	and    v1, v1, s3
800B7654	or     v1, v1, v0
800B7658	sw     v1, $0000(a0)

Lb765c:	; 800B765C
800B765C	addiu  t6, t6, $0020
800B7660	addiu  t7, t7, $0020
800B7664	addiu  t5, t5, $0034
800B7668	sltu   v0, t2, t8
800B766C	bne    v0, zero, loopb754c [$800b754c]
800B7670	addiu  t1, t1, $0034

Lb7674:	; 800B7674
800B7674	lhu    t8, $0008(s4)
800B7678	addu   a1, t1, zero
800B767C	beq    t8, zero, Lb77ac [$800b77ac]
800B7680	addu   t2, zero, zero
800B7684	lui    v0, $8007
800B7688	addiu  s3, v0, $11a8
800B768C	lui    s1, $ff00
800B7690	lui    v0, $8007
800B7694	addiu  s0, v0, $0520
800B7698	lui    t9, $00ff
800B769C	ori    t9, t9, $ffff

Lb76a0:	; 800B76A0
800B76A0	addiu  t4, a1, $0020
800B76A4	addiu  t6, t7, $000f

loopb76a8:	; 800B76A8
800B76A8	lw     v0, $0000(t7)
800B76AC	lhu    v1, $fff5(t6)
800B76B0	srl    a0, v0, $10
800B76B4	andi   v0, v0, $ffff
800B76B8	sll    t5, v0, $02
800B76BC	addu   v0, t5, s3
800B76C0	sll    t3, a0, $02
800B76C4	lw     t0, $0000(v0)
800B76C8	addu   v0, t3, s3
800B76CC	sll    t1, v1, $02
800B76D0	addu   v1, t1, s3
800B76D4	lw     a3, $0000(v0)
800B76D8	lbu    v0, $0000(t6)
800B76DC	lw     a2, $0000(v1)
800B76E0	andi   v0, v0, $0002
800B76E4	bne    v0, zero, Lb7720 [$800b7720]
800B76E8	addiu  t2, t2, $0001
800B76EC	mtc2   t0,l33
800B76F0	mtc2   a2,gbk
800B76F4	mtc2   a3,rbk
800B76F8	lw     v0, $0000(a1)
800B76FC	nop
800B7700	and    v0, v0, s1
800B7704	sw     v0, $0000(a1)
800B7708	gte_func26zero,r11r12
800B770C	swc2   t8, $0000(sp)
800B7710	lw     v0, $0000(sp)
800B7714	nop
800B7718	blez   v0, Lb7794 [$800b7794]
800B771C	nop

Lb7720:	; 800B7720
800B7720	addu   a0, t5, s0
800B7724	addu   v1, t3, s0
800B7728	addu   v0, t1, s0
800B772C	lw     a0, $0000(a0)
800B7730	lw     v1, $0000(v1)

Lb7734:	; 800B7734
800B7734	lw     v0, $0000(v0)
800B7738	mtc2   a0,lr3lg1
800B773C	mtc2   v1,lg2lg3
800B7740	mtc2   v0,lb1lb2
800B7744	sw     t0, $ffe8(t4)
800B7748	sw     a3, $fff4(t4)
800B774C	gte_func26t8,r11r12
800B7750	addiu  v0, sp, $0004
800B7754	sw     a2, $0000(t4)
800B7758	swc2   a3, $0000(v0)

Lb775c:	; 800B775C
800B775C	lw     a0, $0004(sp)
800B7760	lw     v1, $0000(a1)
800B7764	sll    a0, a0, $02
800B7768	addu   a0, a0, s2
800B776C	lw     v0, $0000(a0)
800B7770	and    v1, v1, s1
800B7774	and    v0, v0, t9
800B7778	or     v1, v1, v0
800B777C	sw     v1, $0000(a1)
800B7780	lw     v0, $0000(a0)
800B7784	and    v1, a1, t9
800B7788	and    v0, v0, s1
800B778C	or     v0, v0, v1
800B7790	sw     v0, $0000(a0)

Lb7794:	; 800B7794
800B7794	addiu  t6, t6, $0018
800B7798	addiu  t7, t7, $0018
800B779C	addiu  t4, t4, $0028
800B77A0	sltu   v0, t2, t8
800B77A4	bne    v0, zero, loopb76a8 [$800b76a8]
800B77A8	addiu  a1, a1, $0028

Lb77ac:	; 800B77AC
800B77AC	lhu    t8, $000a(s4)
800B77B0	addu   t1, a1, zero
800B77B4	beq    t8, zero, Lb7904 [$800b7904]
800B77B8	addu   t2, zero, zero
800B77BC	lui    v0, $8007
800B77C0	addiu  s1, v0, $11a8
800B77C4	lui    s3, $ff00
800B77C8	lui    v0, $8007
800B77CC	addiu  s0, v0, $0520
800B77D0	lui    t9, $00ff
800B77D4	ori    t9, t9, $ffff
800B77D8	addiu  t5, t1, $0020
800B77DC	addiu  t6, t7, $0014

loopb77e0:	; 800B77E0
800B77E0	lw     v0, $0000(t7)
800B77E4	lw     v1, $fff0(t6)
800B77E8	srl    a0, v0, $10
800B77EC	srl    a1, v1, $10
800B77F0	andi   v0, v0, $ffff
800B77F4	andi   v1, v1, $ffff
800B77F8	sll    t4, v0, $02
800B77FC	addu   v0, t4, s1
800B7800	sll    a0, a0, $02
800B7804	lw     t0, $0000(v0)
800B7808	addu   v0, a0, s1
800B780C	sll    t3, v1, $02
800B7810	addu   v1, t3, s1
800B7814	lw     a3, $0000(v0)
800B7818	lbu    v0, $0000(t6)
800B781C	lw     a2, $0000(v1)
800B7820	andi   v0, v0, $0002
800B7824	bne    v0, zero, Lb7860 [$800b7860]
800B7828	addiu  t2, t2, $0001
800B782C	mtc2   t0,l33
800B7830	mtc2   a2,gbk
800B7834	mtc2   a3,rbk
800B7838	lw     v0, $0000(t1)
800B783C	nop
800B7840	and    v0, v0, s3
800B7844	sw     v0, $0000(t1)
800B7848	gte_func26zero,r11r12
800B784C	swc2   t8, $0000(sp)
800B7850	lw     v0, $0000(sp)
800B7854	nop
800B7858	blez   v0, Lb78ec [$800b78ec]
800B785C	nop

Lb7860:	; 800B7860
800B7860	addu   v0, t4, s0
800B7864	addu   a0, a0, s0

Lb7868:	; 800B7868
800B7868	lw     v1, $0000(v0)
800B786C	lw     v0, $0000(a0)
800B7870	addu   a0, t3, s0
800B7874	sll    a1, a1, $02
800B7878	lw     a0, $0000(a0)
800B787C	addu   v1, v1, v0
800B7880	addu   v0, a1, s0
800B7884	addu   v1, v1, a0
800B7888	lw     v0, $0000(v0)
800B788C	addu   a1, a1, s1
800B7890	addu   v1, v1, v0
800B7894	sra    v1, v1, $04
800B7898	sw     v1, $0004(sp)
800B789C	sw     t0, $ffe8(t5)
800B78A0	sw     a3, $fff0(t5)
800B78A4	sw     a2, $fff8(t5)
800B78A8	lw     v0, $0000(a1)
800B78AC	nop
800B78B0	sw     v0, $0000(t5)
800B78B4	lw     a0, $0004(sp)
800B78B8	lw     v1, $0000(t1)
800B78BC	sll    a0, a0, $02
800B78C0	addu   a0, a0, s2
800B78C4	lw     v0, $0000(a0)
800B78C8	and    v1, v1, s3
800B78CC	and    v0, v0, t9
800B78D0	or     v1, v1, v0
800B78D4	sw     v1, $0000(t1)
800B78D8	lw     v0, $0000(a0)
800B78DC	and    v1, t1, t9
800B78E0	and    v0, v0, s3

Lb78e4:	; 800B78E4
800B78E4	or     v0, v0, v1
800B78E8	sw     v0, $0000(a0)

Lb78ec:	; 800B78EC
800B78EC	addiu  t6, t6, $0018
800B78F0	addiu  t7, t7, $0018
800B78F4	addiu  t5, t5, $0024
800B78F8	sltu   v0, t2, t8

Lb78fc:	; 800B78FC
800B78FC	bne    v0, zero, loopb77e0 [$800b77e0]
800B7900	addiu  t1, t1, $0024

Lb7904:	; 800B7904
800B7904	lhu    t8, $000c(s4)
800B7908	addu   a1, t1, zero
800B790C	beq    t8, zero, Lb7a3c [$800b7a3c]
800B7910	addu   t2, zero, zero
800B7914	lui    v0, $8007

Lb7918:	; 800B7918
800B7918	addiu  s3, v0, $11a8
800B791C	lui    s1, $ff00
800B7920	lui    v0, $8007
800B7924	addiu  s0, v0, $0520
800B7928	lui    t9, $00ff
800B792C	ori    t9, t9, $ffff

Lb7930:	; 800B7930
800B7930	addiu  t4, a1, $0018
800B7934	addiu  t6, t7, $0013

loopb7938:	; 800B7938
800B7938	lw     v0, $0000(t7)
800B793C	lhu    v1, $fff1(t6)
800B7940	srl    a0, v0, $10
800B7944	andi   v0, v0, $ffff
800B7948	sll    t5, v0, $02
800B794C	addu   v0, t5, s3
800B7950	sll    t3, a0, $02

funcb7954:	; 800B7954
800B7954	lw     t0, $0000(v0)
800B7958	addu   v0, t3, s3
800B795C	sll    t1, v1, $02
800B7960	addu   v1, t1, s3
800B7964	lw     a3, $0000(v0)
800B7968	lbu    v0, $0000(t6)
800B796C	lw     a2, $0000(v1)
800B7970	andi   v0, v0, $0002
800B7974	bne    v0, zero, Lb79b0 [$800b79b0]
800B7978	addiu  t2, t2, $0001
800B797C	mtc2   t0,l33
800B7980	mtc2   a2,gbk
800B7984	mtc2   a3,rbk
800B7988	lw     v0, $0000(a1)
800B798C	nop
800B7990	and    v0, v0, s1
800B7994	sw     v0, $0000(a1)
800B7998	gte_func26zero,r11r12
800B799C	swc2   t8, $0000(sp)
800B79A0	lw     v0, $0000(sp)
800B79A4	nop
800B79A8	blez   v0, Lb7a24 [$800b7a24]
800B79AC	nop

Lb79b0:	; 800B79B0
800B79B0	addu   a0, t5, s0
800B79B4	addu   v1, t3, s0
800B79B8	addu   v0, t1, s0
800B79BC	lw     a0, $0000(a0)
800B79C0	lw     v1, $0000(v1)
800B79C4	lw     v0, $0000(v0)
800B79C8	mtc2   a0,lr3lg1
800B79CC	mtc2   v1,lg2lg3
800B79D0	mtc2   v0,lb1lb2
800B79D4	sw     t0, $fff0(t4)
800B79D8	sw     a3, $fff8(t4)
800B79DC	gte_func26t8,r11r12
800B79E0	addiu  v0, sp, $0004
800B79E4	sw     a2, $0000(t4)
800B79E8	swc2   a3, $0000(v0)
800B79EC	lw     a0, $0004(sp)
800B79F0	lw     v1, $0000(a1)
800B79F4	sll    a0, a0, $02
800B79F8	addu   a0, a0, s2
800B79FC	lw     v0, $0000(a0)
800B7A00	and    v1, v1, s1
800B7A04	and    v0, v0, t9
800B7A08	or     v1, v1, v0
800B7A0C	sw     v1, $0000(a1)
800B7A10	lw     v0, $0000(a0)

funcb7a14:	; 800B7A14
800B7A14	and    v1, a1, t9
800B7A18	and    v0, v0, s1
800B7A1C	or     v0, v0, v1
800B7A20	sw     v0, $0000(a0)

Lb7a24:	; 800B7A24
800B7A24	addiu  t6, t6, $0014
800B7A28	addiu  t7, t7, $0014
800B7A2C	addiu  t4, t4, $001c
800B7A30	sltu   v0, t2, t8
800B7A34	bne    v0, zero, loopb7938 [$800b7938]
800B7A38	addiu  a1, a1, $001c

Lb7a3c:	; 800B7A3C
800B7A3C	lhu    t8, $000e(s4)
800B7A40	addu   t1, a1, zero
800B7A44	beq    t8, zero, Lb7b98 [$800b7b98]
800B7A48	addu   t2, zero, zero
800B7A4C	lui    v0, $8007
800B7A50	addiu  s1, v0, $11a8
800B7A54	lui    s3, $ff00
800B7A58	lui    v0, $8007
800B7A5C	addiu  s0, v0, $0520
800B7A60	lui    t9, $00ff
800B7A64	ori    t9, t9, $ffff
800B7A68	addiu  t5, t1, $0014
800B7A6C	addiu  t6, t7, $000d

loopb7a70:	; 800B7A70
800B7A70	lw     v0, $0000(t7)
800B7A74	lw     v1, $fff7(t6)
800B7A78	srl    a0, v0, $10
800B7A7C	srl    a1, v1, $10
800B7A80	andi   v0, v0, $ffff
800B7A84	andi   v1, v1, $ffff

Lb7a88:	; 800B7A88
800B7A88	sll    t4, v0, $02
800B7A8C	addu   v0, t4, s1

Lb7a90:	; 800B7A90
800B7A90	sll    a0, a0, $02
800B7A94	lw     t0, $0000(v0)
800B7A98	addu   v0, a0, s1
800B7A9C	sll    t3, v1, $02
800B7AA0	addu   v1, t3, s1
800B7AA4	lw     a3, $0000(v0)
800B7AA8	lbu    v0, $0000(t6)
800B7AAC	lw     a2, $0000(v1)
800B7AB0	andi   v0, v0, $0002
800B7AB4	bne    v0, zero, Lb7af0 [$800b7af0]
800B7AB8	addiu  t2, t2, $0001
800B7ABC	mtc2   t0,l33
800B7AC0	mtc2   a2,gbk
800B7AC4	mtc2   a3,rbk
800B7AC8	lw     v0, $0000(t1)
800B7ACC	nop
800B7AD0	and    v0, v0, s3
800B7AD4	sw     v0, $0000(t1)
800B7AD8	gte_func26zero,r11r12
800B7ADC	swc2   t8, $0000(sp)
800B7AE0	lw     v0, $0000(sp)
800B7AE4	nop
800B7AE8	blez   v0, Lb7b80 [$800b7b80]
800B7AEC	nop

Lb7af0:	; 800B7AF0
800B7AF0	addu   v0, t4, s0
800B7AF4	addu   a0, a0, s0
800B7AF8	lw     v1, $0000(v0)
800B7AFC	lw     v0, $0000(a0)
800B7B00	addu   a0, t3, s0
800B7B04	sll    a1, a1, $02
800B7B08	lw     a0, $0000(a0)
800B7B0C	addu   v1, v1, v0
800B7B10	addu   v0, a1, s0
800B7B14	addu   v1, v1, a0
800B7B18	lw     v0, $0000(v0)
800B7B1C	addu   a1, a1, s1
800B7B20	addu   v1, v1, v0
800B7B24	sw     v1, $0004(sp)
800B7B28	sw     t0, $fff4(t5)
800B7B2C	sw     a3, $fff8(t5)
800B7B30	sw     a2, $fffc(t5)
800B7B34	lw     v0, $0000(a1)
800B7B38	nop
800B7B3C	sw     v0, $0000(t5)
800B7B40	lw     a1, $0004(sp)
800B7B44	lw     v1, $0000(t1)
800B7B48	sra    a1, a1, $04
800B7B4C	sll    a0, a1, $02
800B7B50	addu   a0, a0, s2
800B7B54	lw     v0, $0000(a0)
800B7B58	and    v1, v1, s3
800B7B5C	and    v0, v0, t9
800B7B60	or     v1, v1, v0
800B7B64	sw     v1, $0000(t1)
800B7B68	lw     v1, $0000(a0)
800B7B6C	and    v0, t1, t9
800B7B70	sw     a1, $0004(sp)
800B7B74	and    v1, v1, s3
800B7B78	or     v1, v1, v0
800B7B7C	sw     v1, $0000(a0)

Lb7b80:	; 800B7B80
800B7B80	addiu  t6, t6, $0010
800B7B84	addiu  t7, t7, $0010
800B7B88	addiu  t5, t5, $0018
800B7B8C	sltu   v0, t2, t8
800B7B90	bne    v0, zero, loopb7a70 [$800b7a70]

Lb7b94:	; 800B7B94
800B7B94	addiu  t1, t1, $0018

Lb7b98:	; 800B7B98
800B7B98	lhu    t8, $0010(s4)
800B7B9C	addu   a1, t1, zero
800B7BA0	beq    t8, zero, Lb7cd0 [$800b7cd0]
800B7BA4	addu   t2, zero, zero
800B7BA8	lui    v0, $8007
800B7BAC	addiu  s3, v0, $11a8
800B7BB0	lui    s1, $ff00
800B7BB4	lui    v0, $8007
800B7BB8	addiu  s0, v0, $0520
800B7BBC	lui    t9, $00ff
800B7BC0	ori    t9, t9, $ffff
800B7BC4	addiu  t4, a1, $0010
800B7BC8	addiu  t6, t7, $000b

loopb7bcc:	; 800B7BCC
800B7BCC	lw     v0, $0000(t7)
800B7BD0	lhu    v1, $fff9(t6)
800B7BD4	srl    a0, v0, $10
800B7BD8	andi   v0, v0, $ffff
800B7BDC	sll    t5, v0, $02

Lb7be0:	; 800B7BE0
800B7BE0	addu   v0, t5, s3
800B7BE4	sll    t3, a0, $02
800B7BE8	lw     t0, $0000(v0)
800B7BEC	addu   v0, t3, s3
800B7BF0	sll    t1, v1, $02
800B7BF4	addu   v1, t1, s3
800B7BF8	lw     a3, $0000(v0)
800B7BFC	lbu    v0, $0000(t6)
800B7C00	lw     a2, $0000(v1)
800B7C04	andi   v0, v0, $0002
800B7C08	bne    v0, zero, Lb7c44 [$800b7c44]
800B7C0C	addiu  t2, t2, $0001
800B7C10	mtc2   t0,l33
800B7C14	mtc2   a2,gbk
800B7C18	mtc2   a3,rbk
800B7C1C	lw     v0, $0000(a1)
800B7C20	nop
800B7C24	and    v0, v0, s1
800B7C28	sw     v0, $0000(a1)
800B7C2C	gte_func26zero,r11r12
800B7C30	swc2   t8, $0000(sp)
800B7C34	lw     v0, $0000(sp)
800B7C38	nop
800B7C3C	blez   v0, Lb7cb8 [$800b7cb8]
800B7C40	nop

Lb7c44:	; 800B7C44
800B7C44	addu   a0, t5, s0
800B7C48	addu   v1, t3, s0
800B7C4C	addu   v0, t1, s0
800B7C50	lw     a0, $0000(a0)
800B7C54	lw     v1, $0000(v1)
800B7C58	lw     v0, $0000(v0)

Lb7c5c:	; 800B7C5C
800B7C5C	mtc2   a0,lr3lg1
800B7C60	mtc2   v1,lg2lg3
800B7C64	mtc2   v0,lb1lb2
800B7C68	sw     t0, $fff8(t4)

Lb7c6c:	; 800B7C6C
800B7C6C	sw     a3, $fffc(t4)
800B7C70	gte_func26t8,r11r12
800B7C74	addiu  v0, sp, $0004
800B7C78	sw     a2, $0000(t4)
800B7C7C	swc2   a3, $0000(v0)
800B7C80	lw     a0, $0004(sp)
800B7C84	lw     v1, $0000(a1)
800B7C88	sll    a0, a0, $02
800B7C8C	addu   a0, a0, s2
800B7C90	lw     v0, $0000(a0)
800B7C94	and    v1, v1, s1

Lb7c98:	; 800B7C98
800B7C98	and    v0, v0, t9
800B7C9C	or     v1, v1, v0
800B7CA0	sw     v1, $0000(a1)
800B7CA4	lw     v0, $0000(a0)
800B7CA8	and    v1, a1, t9
800B7CAC	and    v0, v0, s1
800B7CB0	or     v0, v0, v1
800B7CB4	sw     v0, $0000(a0)

Lb7cb8:	; 800B7CB8
800B7CB8	addiu  t6, t6, $000c
800B7CBC	addiu  t7, t7, $000c
800B7CC0	addiu  t4, t4, $0014
800B7CC4	sltu   v0, t2, t8
800B7CC8	bne    v0, zero, loopb7bcc [$800b7bcc]
800B7CCC	addiu  a1, a1, $0014

Lb7cd0:	; 800B7CD0
800B7CD0	lw     s4, $0018(sp)
800B7CD4	lw     s3, $0014(sp)
800B7CD8	lw     s2, $0010(sp)
800B7CDC	lw     s1, $000c(sp)
800B7CE0	lw     s0, $0008(sp)
800B7CE4	jr     ra 
800B7CE8	addiu  sp, sp, $0020


funcb7cec:	; 800B7CEC
800B7CEC	lhu    v0, $0000(a0)
800B7CF0	nop
800B7CF4	andi   v0, v0, $0002
800B7CF8	beq    v0, zero, Lb7e28 [$800b7e28]
800B7CFC	addiu  sp, sp, $ffe0 (=-$20)
800B7D00	lhu    v1, $0054(a0)
800B7D04	addiu  v0, zero, $1000
800B7D08	sw     v0, $0000(sp)
800B7D0C	sw     zero, $0004(sp)
800B7D10	sw     v0, $0008(sp)
800B7D14	sw     zero, $000c(sp)
800B7D18	sw     v0, $0010(sp)
800B7D1C	sh     v1, $0000(sp)
800B7D20	addiu  v1, a0, $0024
800B7D24	lw     t4, $0000(v1)
800B7D28	lw     t5, $0004(v1)
800B7D2C	ctc2   t4,vxy0
800B7D30	ctc2   t5,vz0
800B7D34	lw     t4, $0008(v1)
800B7D38	lw     t5, $000c(v1)
800B7D3C	lw     t6, $0010(v1)
800B7D40	ctc2   t4,vxy1
800B7D44	ctc2   t5,vz1
800B7D48	ctc2   t6,vxy2

Lb7d4c:	; 800B7D4C
800B7D4C	lhu    t4, $0000(sp)
800B7D50	lhu    t5, $0006(sp)
800B7D54	lhu    t6, $000c(sp)
800B7D58	mtc2   t4,l13l21
800B7D5C	mtc2   t5,l22l23
800B7D60	mtc2   t6,l31l32
800B7D64	nop
800B7D68	nop
800B7D6C	gte_func18t1,dqb
800B7D70	lhu    v0, $0056(a0)
800B7D74	nop
800B7D78	sh     v0, $0008(sp)
800B7D7C	mfc2   t4,l13l21
800B7D80	mfc2   t5,l22l23
800B7D84	mfc2   t6,l31l32

Lb7d88:	; 800B7D88
800B7D88	sh     t4, $0000(v1)
800B7D8C	sh     t5, $0006(v1)
800B7D90	sh     t6, $000c(v1)
800B7D94	addiu  v0, sp, $0002
800B7D98	lhu    t4, $0000(v0)
800B7D9C	lhu    t5, $0006(v0)
800B7DA0	lhu    t6, $000c(v0)
800B7DA4	mtc2   t4,l13l21
800B7DA8	mtc2   t5,l22l23
800B7DAC	mtc2   t6,l31l32
800B7DB0	nop
800B7DB4	nop
800B7DB8	gte_func18t1,dqb
800B7DBC	lhu    v0, $0058(a0)
800B7DC0	nop
800B7DC4	sh     v0, $0010(sp)
800B7DC8	addiu  v0, a0, $0026
800B7DCC	mfc2   t4,l13l21
800B7DD0	mfc2   t5,l22l23
800B7DD4	mfc2   t6,l31l32
800B7DD8	sh     t4, $0000(v0)
800B7DDC	sh     t5, $0006(v0)
800B7DE0	sh     t6, $000c(v0)
800B7DE4	addiu  v0, sp, $0004
800B7DE8	lhu    t4, $0000(v0)
800B7DEC	lhu    t5, $0006(v0)
800B7DF0	lhu    t6, $000c(v0)
800B7DF4	mtc2   t4,l13l21

Lb7df8:	; 800B7DF8
800B7DF8	mtc2   t5,l22l23
800B7DFC	mtc2   t6,l31l32
800B7E00	nop
800B7E04	nop
800B7E08	gte_func18t1,dqb
800B7E0C	addiu  v0, a0, $0028
800B7E10	mfc2   t4,l13l21
800B7E14	mfc2   t5,l22l23
800B7E18	mfc2   t6,l31l32
800B7E1C	sh     t4, $0000(v0)
800B7E20	sh     t5, $0006(v0)
800B7E24	sh     t6, $000c(v0)

Lb7e28:	; 800B7E28
800B7E28	jr     ra 
800B7E2C	addiu  sp, sp, $0020

800B7E30	addiu  sp, sp, $fff0 (=-$10)
800B7E34	lhu    v0, $0000(a0)
800B7E38	lw     v1, $001c(a0)
800B7E3C	andi   a1, v0, $ffef
800B7E40	beq    v1, zero, Lb7e5c [$800b7e5c]
800B7E44	sh     a1, $0000(a0)
800B7E48	lhu    v0, $0000(v1)
800B7E4C	nop
800B7E50	andi   v0, v0, $0010
800B7E54	j      Lb7f08 [$800b7f08]
800B7E58	or     v0, a1, v0

Lb7e5c:	; 800B7E5C
800B7E5C	lhu    v0, $0038(a0)
800B7E60	nop
800B7E64	sh     v0, $0000(sp)
800B7E68	lhu    v0, $003c(a0)
800B7E6C	nop
800B7E70	sh     v0, $0002(sp)
800B7E74	lui    v0, $8006
800B7E78	lhu    v1, $0040(a0)
800B7E7C	lw     v0, $794c(v0)
800B7E80	sh     v1, $0004(sp)
800B7E84	lw     v0, $001c(v0)
800B7E88	nop
800B7E8C	addiu  v0, v0, $0018
800B7E90	lw     t4, $0000(v0)
800B7E94	lw     t5, $0004(v0)
800B7E98	ctc2   t4,vxy0
800B7E9C	ctc2   t5,vz0
800B7EA0	lw     t4, $0008(v0)
800B7EA4	lw     t5, $000c(v0)
800B7EA8	lw     t6, $0010(v0)
800B7EAC	ctc2   t4,vxy1
800B7EB0	ctc2   t5,vz1
800B7EB4	ctc2   t6,vxy2
800B7EB8	lw     t4, $0014(v0)
800B7EBC	lw     t5, $0018(v0)
800B7EC0	ctc2   t4,vz2
800B7EC4	lw     t6, $001c(v0)
800B7EC8	ctc2   t5,rgb
800B7ECC	ctc2   t6,otz
800B7ED0	lwc2   zero, $0000(sp)
800B7ED4	lwc2   at, $0004(sp)
800B7ED8	nop
800B7EDC	nop

Lb7ee0:	; 800B7EE0
800B7EE0	gte_func16t8,r11r12
800B7EE4	addiu  v0, sp, $0008
800B7EE8	swc2   s3, $0000(v0)
800B7EEC	lw     v0, $0008(sp)
800B7EF0	nop
800B7EF4	bne    v0, zero, Lb7f0c [$800b7f0c]
800B7EF8	nop
800B7EFC	lhu    v0, $0000(a0)
800B7F00	nop
800B7F04	ori    v0, v0, $0010

Lb7f08:	; 800B7F08
800B7F08	sh     v0, $0000(a0)

Lb7f0c:	; 800B7F0C
800B7F0C	jr     ra 
800B7F10	addiu  sp, sp, $0010



////////////////////////////////
// funcb7f14
800B7F14-800B8830
////////////////////////////////



800B8834	addiu  sp, sp, $ffb8 (=-$48)
800B8838	addu   v1, a3, zero
800B883C	sw     ra, $0044(sp)
800B8840	sw     fp, $0040(sp)
800B8844	sw     s7, $003c(sp)
800B8848	sw     s6, $0038(sp)
800B884C	sw     s5, $0034(sp)
800B8850	sw     s4, $0030(sp)
800B8854	sw     s3, $002c(sp)
800B8858	sw     s2, $0028(sp)
800B885C	sw     s1, $0024(sp)
800B8860	sw     s0, $0020(sp)
800B8864	sw     a0, $0048(sp)
800B8868	lhu    v0, $0000(a0)
800B886C	lw     a3, $0058(sp)
800B8870	andi   v0, v0, $0010
800B8874	bne    v0, zero, Lb8c50 [$800b8c50]
800B8878	sb     a1, $0010(sp)
800B887C	sll    s7, a3, $10
800B8880	sll    a2, a2, $10
800B8884	sra    s6, a2, $10
800B8888	sll    fp, v1, $10
800B888C	sra    s5, fp, $10
800B8890	andi   v1, a1, $00ff
800B8894	sll    v0, v1, $02
800B8898	sw     zero, $0014(sp)
800B889C	sw     a2, $0018(sp)
800B88A0	lw     a0, $0008(a0)
800B88A4	addu   v0, v0, v1
800B88A8	lw     v1, $0010(a0)
800B88AC	sll    v0, v0, $03
800B88B0	addu   s4, v1, v0

Lb88b4:	; 800B88B4
800B88B4	lbu    v0, $0010(sp)
800B88B8	lw     t0, $0048(sp)
800B88BC	sll    v1, v0, $01
800B88C0	addu   v1, v1, v0
800B88C4	sll    v1, v1, $02
800B88C8	lw     v0, $0044(t0)
800B88CC	lw     t0, $0014(sp)
800B88D0	addu   v1, v1, v0
800B88D4	lw     s2, $0004(v1)
800B88D8	beq    t0, zero, Lb88ec [$800b88ec]
800B88DC	nop
800B88E0	lhu    v0, $0000(s4)
800B88E4	nop
800B88E8	addu   s2, s2, v0

Lb88ec:	; 800B88EC
800B88EC	lhu    v0, $0002(s4)
800B88F0	nop
800B88F4	beq    v0, zero, Lb8938 [$800b8938]
800B88F8	addu   s1, zero, zero
800B88FC	addiu  s0, s2, $0004

loopb8900:	; 800B8900
800B8900	sra    a2, fp, $10
800B8904	sra    a3, s7, $10
800B8908	addiu  s2, s2, $0028
800B890C	addiu  s1, s1, $0001
800B8910	lw     t0, $0018(sp)
800B8914	lw     a0, $0000(s0)
800B8918	jal    funcba0f0 [$800ba0f0]
800B891C	sra    a1, t0, $10
800B8920	sw     v0, $0000(s0)
800B8924	lhu    v0, $0002(s4)
800B8928	nop
800B892C	sltu   v0, s1, v0
800B8930	bne    v0, zero, loopb8900 [$800b8900]
800B8934	addiu  s0, s0, $0028

Lb8938:	; 800B8938
800B8938	lhu    v0, $0004(s4)
800B893C	nop
800B8940	beq    v0, zero, Lb8984 [$800b8984]
800B8944	addu   s1, zero, zero
800B8948	addiu  s0, s2, $0004

loopb894c:	; 800B894C
800B894C	sra    a2, fp, $10
800B8950	sra    a3, s7, $10
800B8954	addiu  s2, s2, $0020
800B8958	addiu  s1, s1, $0001
800B895C	lw     t0, $0018(sp)
800B8960	lw     a0, $0000(s0)
800B8964	jal    funcba0f0 [$800ba0f0]
800B8968	sra    a1, t0, $10
800B896C	sw     v0, $0000(s0)
800B8970	lhu    v0, $0004(s4)
800B8974	nop
800B8978	sltu   v0, s1, v0
800B897C	bne    v0, zero, loopb894c [$800b894c]
800B8980	addiu  s0, s0, $0020

Lb8984:	; 800B8984
800B8984	lhu    v0, $0006(s4)
800B8988	nop
800B898C	beq    v0, zero, Lb8a18 [$800b8a18]
800B8990	addu   s1, zero, zero
800B8994	sra    s3, s7, $10
800B8998	addiu  s0, s2, $0028

loopb899c:	; 800B899C
800B899C	addu   a1, s6, zero
800B89A0	addu   a2, s5, zero
800B89A4	addu   a3, s3, zero
800B89A8	addiu  s2, s2, $0034
800B89AC	lw     a0, $ffdc(s0)
800B89B0	jal    funcba0f0 [$800ba0f0]
800B89B4	addiu  s1, s1, $0001
800B89B8	addu   a1, s6, zero
800B89BC	addu   a2, s5, zero
800B89C0	lw     a0, $ffe8(s0)
800B89C4	addu   a3, s3, zero
800B89C8	jal    funcba0f0 [$800ba0f0]
800B89CC	sw     v0, $ffdc(s0)
800B89D0	addu   a1, s6, zero
800B89D4	addu   a2, s5, zero
800B89D8	lw     a0, $fff4(s0)
800B89DC	addu   a3, s3, zero
800B89E0	jal    funcba0f0 [$800ba0f0]
800B89E4	sw     v0, $ffe8(s0)
800B89E8	addu   a1, s6, zero
800B89EC	addu   a2, s5, zero
800B89F0	lw     a0, $0000(s0)
800B89F4	addu   a3, s3, zero
800B89F8	jal    funcba0f0 [$800ba0f0]
800B89FC	sw     v0, $fff4(s0)

Lb8a00:	; 800B8A00
800B8A00	sw     v0, $0000(s0)
800B8A04	lhu    v0, $0006(s4)

Lb8a08:	; 800B8A08
800B8A08	nop
800B8A0C	sltu   v0, s1, v0
800B8A10	bne    v0, zero, loopb899c [$800b899c]
800B8A14	addiu  s0, s0, $0034

Lb8a18:	; 800B8A18
800B8A18	lhu    v0, $0008(s4)
800B8A1C	nop
800B8A20	beq    v0, zero, Lb8a94 [$800b8a94]

funcb8a24:	; 800B8A24
800B8A24	addu   s1, zero, zero
800B8A28	sra    s3, s7, $10
800B8A2C	addiu  s0, s2, $001c

loopb8a30:	; 800B8A30
800B8A30	addu   a1, s6, zero
800B8A34	addu   a2, s5, zero
800B8A38	addu   a3, s3, zero
800B8A3C	addiu  s2, s2, $0028
800B8A40	lw     a0, $ffe8(s0)
800B8A44	jal    funcba0f0 [$800ba0f0]
800B8A48	addiu  s1, s1, $0001
800B8A4C	addu   a1, s6, zero
800B8A50	addu   a2, s5, zero
800B8A54	lw     a0, $fff4(s0)
800B8A58	addu   a3, s3, zero
800B8A5C	jal    funcba0f0 [$800ba0f0]
800B8A60	sw     v0, $ffe8(s0)
800B8A64	addu   a1, s6, zero
800B8A68	addu   a2, s5, zero
800B8A6C	lw     a0, $0000(s0)
800B8A70	addu   a3, s3, zero
800B8A74	jal    funcba0f0 [$800ba0f0]
800B8A78	sw     v0, $fff4(s0)
800B8A7C	sw     v0, $0000(s0)
800B8A80	lhu    v0, $0008(s4)
800B8A84	nop
800B8A88	sltu   v0, s1, v0
800B8A8C	bne    v0, zero, loopb8a30 [$800b8a30]
800B8A90	addiu  s0, s0, $0028

Lb8a94:	; 800B8A94
800B8A94	lhu    v0, $000a(s4)
800B8A98	nop
800B8A9C	beq    v0, zero, Lb8b28 [$800b8b28]
800B8AA0	addu   s1, zero, zero
800B8AA4	sra    s3, s7, $10
800B8AA8	addiu  s0, s2, $001c

loopb8aac:	; 800B8AAC
800B8AAC	addu   a1, s6, zero
800B8AB0	addu   a2, s5, zero
800B8AB4	addu   a3, s3, zero
800B8AB8	addiu  s2, s2, $0024
800B8ABC	lw     a0, $ffe8(s0)
800B8AC0	jal    funcba0f0 [$800ba0f0]
800B8AC4	addiu  s1, s1, $0001
800B8AC8	addu   a1, s6, zero
800B8ACC	addu   a2, s5, zero
800B8AD0	lw     a0, $fff0(s0)
800B8AD4	addu   a3, s3, zero
800B8AD8	jal    funcba0f0 [$800ba0f0]
800B8ADC	sw     v0, $ffe8(s0)
800B8AE0	addu   a1, s6, zero
800B8AE4	addu   a2, s5, zero
800B8AE8	lw     a0, $fff8(s0)
800B8AEC	addu   a3, s3, zero
800B8AF0	jal    funcba0f0 [$800ba0f0]
800B8AF4	sw     v0, $fff0(s0)
800B8AF8	addu   a1, s6, zero
800B8AFC	addu   a2, s5, zero
800B8B00	lw     a0, $0000(s0)
800B8B04	addu   a3, s3, zero
800B8B08	jal    funcba0f0 [$800ba0f0]
800B8B0C	sw     v0, $fff8(s0)
800B8B10	sw     v0, $0000(s0)
800B8B14	lhu    v0, $000a(s4)
800B8B18	nop
800B8B1C	sltu   v0, s1, v0
800B8B20	bne    v0, zero, loopb8aac [$800b8aac]
800B8B24	addiu  s0, s0, $0024

Lb8b28:	; 800B8B28
800B8B28	lhu    v0, $000c(s4)
800B8B2C	nop
800B8B30	beq    v0, zero, Lb8ba4 [$800b8ba4]
800B8B34	addu   s1, zero, zero
800B8B38	sra    s3, s7, $10
800B8B3C	addiu  s0, s2, $0014

loopb8b40:	; 800B8B40
800B8B40	addu   a1, s6, zero

Lb8b44:	; 800B8B44
800B8B44	addu   a2, s5, zero
800B8B48	addu   a3, s3, zero
800B8B4C	addiu  s2, s2, $001c
800B8B50	lw     a0, $fff0(s0)
800B8B54	jal    funcba0f0 [$800ba0f0]
800B8B58	addiu  s1, s1, $0001
800B8B5C	addu   a1, s6, zero
800B8B60	addu   a2, s5, zero
800B8B64	lw     a0, $fff8(s0)
800B8B68	addu   a3, s3, zero
800B8B6C	jal    funcba0f0 [$800ba0f0]
800B8B70	sw     v0, $fff0(s0)
800B8B74	addu   a1, s6, zero
800B8B78	addu   a2, s5, zero
800B8B7C	lw     a0, $0000(s0)
800B8B80	addu   a3, s3, zero
800B8B84	jal    funcba0f0 [$800ba0f0]
800B8B88	sw     v0, $fff8(s0)
800B8B8C	sw     v0, $0000(s0)
800B8B90	lhu    v0, $000c(s4)
800B8B94	nop
800B8B98	sltu   v0, s1, v0
800B8B9C	bne    v0, zero, loopb8b40 [$800b8b40]
800B8BA0	addiu  s0, s0, $001c

Lb8ba4:	; 800B8BA4
800B8BA4	lhu    v0, $000e(s4)
800B8BA8	nop
800B8BAC	beq    v0, zero, Lb8bf0 [$800b8bf0]
800B8BB0	addu   s1, zero, zero
800B8BB4	addiu  s0, s2, $0004

loopb8bb8:	; 800B8BB8
800B8BB8	sra    a2, fp, $10
800B8BBC	sra    a3, s7, $10
800B8BC0	addiu  s2, s2, $0018
800B8BC4	addiu  s1, s1, $0001
800B8BC8	lw     t0, $0018(sp)
800B8BCC	lw     a0, $0000(s0)
800B8BD0	jal    funcba0f0 [$800ba0f0]
800B8BD4	sra    a1, t0, $10
800B8BD8	sw     v0, $0000(s0)
800B8BDC	lhu    v0, $000e(s4)
800B8BE0	nop
800B8BE4	sltu   v0, s1, v0

funcb8be8:	; 800B8BE8
800B8BE8	bne    v0, zero, loopb8bb8 [$800b8bb8]
800B8BEC	addiu  s0, s0, $0018

Lb8bf0:	; 800B8BF0
800B8BF0	lhu    v0, $0010(s4)
800B8BF4	nop
800B8BF8	beq    v0, zero, Lb8c38 [$800b8c38]
800B8BFC	addu   s1, zero, zero
800B8C00	addiu  s0, s2, $0004

loopb8c04:	; 800B8C04
800B8C04	sra    a2, fp, $10
800B8C08	sra    a3, s7, $10
800B8C0C	addiu  s1, s1, $0001
800B8C10	lw     t0, $0018(sp)
800B8C14	lw     a0, $0000(s0)
800B8C18	jal    funcba0f0 [$800ba0f0]
800B8C1C	sra    a1, t0, $10
800B8C20	sw     v0, $0000(s0)
800B8C24	lhu    v0, $0010(s4)
800B8C28	nop
800B8C2C	sltu   v0, s1, v0
800B8C30	bne    v0, zero, loopb8c04 [$800b8c04]
800B8C34	addiu  s0, s0, $0014

Lb8c38:	; 800B8C38
800B8C38	lw     t0, $0014(sp)
800B8C3C	nop
800B8C40	addiu  t0, t0, $0001
800B8C44	sltiu  v0, t0, $0002
800B8C48	bne    v0, zero, Lb88b4 [$800b88b4]
800B8C4C	sw     t0, $0014(sp)

Lb8c50:	; 800B8C50
800B8C50	lw     ra, $0044(sp)
800B8C54	lw     fp, $0040(sp)
800B8C58	lw     s7, $003c(sp)
800B8C5C	lw     s6, $0038(sp)
800B8C60	lw     s5, $0034(sp)
800B8C64	lw     s4, $0030(sp)
800B8C68	lw     s3, $002c(sp)
800B8C6C	lw     s2, $0028(sp)
800B8C70	lw     s1, $0024(sp)
800B8C74	lw     s0, $0020(sp)
800B8C78	jr     ra 
800B8C7C	addiu  sp, sp, $0048

800B8C80	addiu  sp, sp, $ffc0 (=-$40)
800B8C84	addu   t1, a3, zero
800B8C88	lw     a3, $0050(sp)
800B8C8C	addu   t0, a0, zero
800B8C90	sw     fp, $0038(sp)
800B8C94	addu   fp, a2, zero
800B8C98	sw     ra, $003c(sp)
800B8C9C	sw     s7, $0034(sp)
800B8CA0	sw     s6, $0030(sp)
800B8CA4	sw     s5, $002c(sp)
800B8CA8	sw     s4, $0028(sp)
800B8CAC	sw     s3, $0024(sp)
800B8CB0	sw     s2, $0020(sp)
800B8CB4	sw     s1, $001c(sp)
800B8CB8	sw     s0, $0018(sp)
800B8CBC	sh     t1, $0010(sp)
800B8CC0	lhu    v0, $0000(t0)
800B8CC4	nop
800B8CC8	andi   v0, v0, $0010
800B8CCC	bne    v0, zero, Lb9104 [$800b9104]
800B8CD0	addu   s7, a3, zero
800B8CD4	andi   a0, a1, $00ff
800B8CD8	sll    v0, a0, $01
800B8CDC	addu   v0, v0, a0
800B8CE0	lw     v1, $0044(t0)
800B8CE4	sll    v0, v0, $02
800B8CE8	addu   v0, v0, v1
800B8CEC	sll    v1, a0, $02
800B8CF0	addu   v1, v1, a0
800B8CF4	sll    v1, v1, $03
800B8CF8	lw     s3, $0004(v0)
800B8CFC	lui    v0, $8006
800B8D00	lw     v0, $794c(v0)
800B8D04	lw     a0, $0008(t0)
800B8D08	lw     v0, $001c(v0)
800B8D0C	lw     a0, $0010(a0)
800B8D10	lbu    v0, $0008(v0)
800B8D14	nop
800B8D18	beq    v0, zero, Lb8d2c [$800b8d2c]
800B8D1C	addu   s6, a0, v1
800B8D20	lhu    v0, $0000(s6)
800B8D24	nop
800B8D28	addu   s3, s3, v0

Lb8d2c:	; 800B8D2C
800B8D2C	lhu    v0, $0002(s6)
800B8D30	nop
800B8D34	beq    v0, zero, Lb8d80 [$800b8d80]
800B8D38	addu   s1, zero, zero
800B8D3C	sll    s5, a2, $10
800B8D40	sll    s4, t1, $10
800B8D44	sll    s2, a3, $10
800B8D48	addiu  s0, s3, $0004

loopb8d4c:	; 800B8D4C
800B8D4C	sra    a1, s5, $10
800B8D50	sra    a2, s4, $10
800B8D54	sra    a3, s2, $10

funcb8d58:	; 800B8D58
800B8D58	addiu  s3, s3, $0028
800B8D5C	lw     a0, $0000(s0)
800B8D60	jal    funcba0f0 [$800ba0f0]
800B8D64	addiu  s1, s1, $0001
800B8D68	sw     v0, $0000(s0)
800B8D6C	lhu    v0, $0002(s6)
800B8D70	nop
800B8D74	sltu   v0, s1, v0
800B8D78	bne    v0, zero, loopb8d4c [$800b8d4c]
800B8D7C	addiu  s0, s0, $0028

Lb8d80:	; 800B8D80
800B8D80	lhu    v0, $0004(s6)
800B8D84	nop
800B8D88	beq    v0, zero, Lb8dd8 [$800b8dd8]
800B8D8C	addu   s1, zero, zero
800B8D90	sll    s5, fp, $10
800B8D94	lhu    t2, $0010(sp)
800B8D98	sll    s2, s7, $10
800B8D9C	addiu  s0, s3, $0004
800B8DA0	sll    s4, t2, $10

loopb8da4:	; 800B8DA4
800B8DA4	sra    a1, s5, $10
800B8DA8	sra    a2, s4, $10
800B8DAC	sra    a3, s2, $10
800B8DB0	addiu  s3, s3, $0020
800B8DB4	lw     a0, $0000(s0)
800B8DB8	jal    funcba0f0 [$800ba0f0]
800B8DBC	addiu  s1, s1, $0001
800B8DC0	sw     v0, $0000(s0)
800B8DC4	lhu    v0, $0004(s6)
800B8DC8	nop
800B8DCC	sltu   v0, s1, v0
800B8DD0	bne    v0, zero, loopb8da4 [$800b8da4]
800B8DD4	addiu  s0, s0, $0020

Lb8dd8:	; 800B8DD8
800B8DD8	lhu    v0, $0006(s6)
800B8DDC	nop
800B8DE0	beq    v0, zero, Lb8e84 [$800b8e84]
800B8DE4	addu   s1, zero, zero
800B8DE8	sll    v0, fp, $10
800B8DEC	sra    s5, v0, $10
800B8DF0	lhu    t2, $0010(sp)
800B8DF4	addiu  s0, s3, $0028
800B8DF8	sll    v0, t2, $10
800B8DFC	sra    s4, v0, $10
800B8E00	sll    v0, s7, $10
800B8E04	sra    s2, v0, $10

loopb8e08:	; 800B8E08
800B8E08	addu   a1, s5, zero
800B8E0C	addu   a2, s4, zero
800B8E10	addu   a3, s2, zero
800B8E14	addiu  s3, s3, $0034
800B8E18	lw     a0, $ffdc(s0)
800B8E1C	jal    funcba0f0 [$800ba0f0]
800B8E20	addiu  s1, s1, $0001
800B8E24	addu   a1, s5, zero
800B8E28	addu   a2, s4, zero
800B8E2C	lw     a0, $ffe8(s0)
800B8E30	addu   a3, s2, zero
800B8E34	jal    funcba0f0 [$800ba0f0]
800B8E38	sw     v0, $ffdc(s0)
800B8E3C	addu   a1, s5, zero
800B8E40	addu   a2, s4, zero
800B8E44	lw     a0, $fff4(s0)
800B8E48	addu   a3, s2, zero
800B8E4C	jal    funcba0f0 [$800ba0f0]
800B8E50	sw     v0, $ffe8(s0)
800B8E54	addu   a1, s5, zero
800B8E58	addu   a2, s4, zero
800B8E5C	lw     a0, $0000(s0)
800B8E60	addu   a3, s2, zero
800B8E64	jal    funcba0f0 [$800ba0f0]
800B8E68	sw     v0, $fff4(s0)
800B8E6C	sw     v0, $0000(s0)
800B8E70	lhu    v0, $0006(s6)
800B8E74	nop
800B8E78	sltu   v0, s1, v0
800B8E7C	bne    v0, zero, loopb8e08 [$800b8e08]
800B8E80	addiu  s0, s0, $0034

Lb8e84:	; 800B8E84
800B8E84	lhu    v0, $0008(s6)

Lb8e88:	; 800B8E88
800B8E88	nop
800B8E8C	beq    v0, zero, Lb8f18 [$800b8f18]
800B8E90	addu   s1, zero, zero
800B8E94	sll    v0, fp, $10
800B8E98	sra    s5, v0, $10

funcb8e9c:	; 800B8E9C
800B8E9C	lhu    t2, $0010(sp)
800B8EA0	addiu  s0, s3, $001c
800B8EA4	sll    v0, t2, $10
800B8EA8	sra    s4, v0, $10
800B8EAC	sll    v0, s7, $10
800B8EB0	sra    s2, v0, $10

loopb8eb4:	; 800B8EB4
800B8EB4	addu   a1, s5, zero
800B8EB8	addu   a2, s4, zero
800B8EBC	addu   a3, s2, zero
800B8EC0	addiu  s3, s3, $0028
800B8EC4	lw     a0, $ffe8(s0)
800B8EC8	jal    funcba0f0 [$800ba0f0]
800B8ECC	addiu  s1, s1, $0001
800B8ED0	addu   a1, s5, zero
800B8ED4	addu   a2, s4, zero
800B8ED8	lw     a0, $fff4(s0)
800B8EDC	addu   a3, s2, zero
800B8EE0	jal    funcba0f0 [$800ba0f0]
800B8EE4	sw     v0, $ffe8(s0)
800B8EE8	addu   a1, s5, zero
800B8EEC	addu   a2, s4, zero
800B8EF0	lw     a0, $0000(s0)
800B8EF4	addu   a3, s2, zero
800B8EF8	jal    funcba0f0 [$800ba0f0]
800B8EFC	sw     v0, $fff4(s0)
800B8F00	sw     v0, $0000(s0)
800B8F04	lhu    v0, $0008(s6)
800B8F08	nop
800B8F0C	sltu   v0, s1, v0
800B8F10	bne    v0, zero, loopb8eb4 [$800b8eb4]
800B8F14	addiu  s0, s0, $0028

Lb8f18:	; 800B8F18
800B8F18	lhu    v0, $000a(s6)
800B8F1C	nop
800B8F20	beq    v0, zero, Lb8fc4 [$800b8fc4]
800B8F24	addu   s1, zero, zero
800B8F28	sll    v0, fp, $10
800B8F2C	sra    s5, v0, $10
800B8F30	lhu    t2, $0010(sp)
800B8F34	addiu  s0, s3, $001c
800B8F38	sll    v0, t2, $10
800B8F3C	sra    s4, v0, $10
800B8F40	sll    v0, s7, $10
800B8F44	sra    s2, v0, $10

loopb8f48:	; 800B8F48
800B8F48	addu   a1, s5, zero
800B8F4C	addu   a2, s4, zero
800B8F50	addu   a3, s2, zero
800B8F54	addiu  s3, s3, $0024
800B8F58	lw     a0, $ffe8(s0)
800B8F5C	jal    funcba0f0 [$800ba0f0]
800B8F60	addiu  s1, s1, $0001
800B8F64	addu   a1, s5, zero
800B8F68	addu   a2, s4, zero
800B8F6C	lw     a0, $fff0(s0)
800B8F70	addu   a3, s2, zero
800B8F74	jal    funcba0f0 [$800ba0f0]
800B8F78	sw     v0, $ffe8(s0)
800B8F7C	addu   a1, s5, zero
800B8F80	addu   a2, s4, zero
800B8F84	lw     a0, $fff8(s0)
800B8F88	addu   a3, s2, zero
800B8F8C	jal    funcba0f0 [$800ba0f0]
800B8F90	sw     v0, $fff0(s0)
800B8F94	addu   a1, s5, zero
800B8F98	addu   a2, s4, zero
800B8F9C	lw     a0, $0000(s0)
800B8FA0	addu   a3, s2, zero
800B8FA4	jal    funcba0f0 [$800ba0f0]
800B8FA8	sw     v0, $fff8(s0)
800B8FAC	sw     v0, $0000(s0)
800B8FB0	lhu    v0, $000a(s6)
800B8FB4	nop
800B8FB8	sltu   v0, s1, v0
800B8FBC	bne    v0, zero, loopb8f48 [$800b8f48]
800B8FC0	addiu  s0, s0, $0024

Lb8fc4:	; 800B8FC4
800B8FC4	lhu    v0, $000c(s6)
800B8FC8	nop
800B8FCC	beq    v0, zero, Lb9058 [$800b9058]
800B8FD0	addu   s1, zero, zero
800B8FD4	sll    v0, fp, $10
800B8FD8	sra    s5, v0, $10
800B8FDC	lhu    t2, $0010(sp)
800B8FE0	addiu  s0, s3, $0014
800B8FE4	sll    v0, t2, $10
800B8FE8	sra    s4, v0, $10
800B8FEC	sll    v0, s7, $10
800B8FF0	sra    s2, v0, $10

loopb8ff4:	; 800B8FF4
800B8FF4	addu   a1, s5, zero

funcb8ff8:	; 800B8FF8
800B8FF8	addu   a2, s4, zero
800B8FFC	addu   a3, s2, zero
800B9000	addiu  s3, s3, $001c
800B9004	lw     a0, $fff0(s0)
800B9008	jal    funcba0f0 [$800ba0f0]
800B900C	addiu  s1, s1, $0001
800B9010	addu   a1, s5, zero
800B9014	addu   a2, s4, zero
800B9018	lw     a0, $fff8(s0)
800B901C	addu   a3, s2, zero
800B9020	jal    funcba0f0 [$800ba0f0]
800B9024	sw     v0, $fff0(s0)
800B9028	addu   a1, s5, zero
800B902C	addu   a2, s4, zero
800B9030	lw     a0, $0000(s0)
800B9034	addu   a3, s2, zero
800B9038	jal    funcba0f0 [$800ba0f0]
800B903C	sw     v0, $fff8(s0)
800B9040	sw     v0, $0000(s0)
800B9044	lhu    v0, $000c(s6)
800B9048	nop
800B904C	sltu   v0, s1, v0
800B9050	bne    v0, zero, loopb8ff4 [$800b8ff4]
800B9054	addiu  s0, s0, $001c

Lb9058:	; 800B9058
800B9058	lhu    v0, $000e(s6)
800B905C	nop
800B9060	beq    v0, zero, Lb90b0 [$800b90b0]
800B9064	addu   s1, zero, zero
800B9068	sll    s5, fp, $10
800B906C	lhu    t2, $0010(sp)
800B9070	sll    s2, s7, $10
800B9074	addiu  s0, s3, $0004
800B9078	sll    s4, t2, $10

loopb907c:	; 800B907C
800B907C	sra    a1, s5, $10
800B9080	sra    a2, s4, $10
800B9084	sra    a3, s2, $10
800B9088	addiu  s3, s3, $0018
800B908C	lw     a0, $0000(s0)
800B9090	jal    funcba0f0 [$800ba0f0]
800B9094	addiu  s1, s1, $0001
800B9098	sw     v0, $0000(s0)
800B909C	lhu    v0, $000e(s6)
800B90A0	nop
800B90A4	sltu   v0, s1, v0
800B90A8	bne    v0, zero, loopb907c [$800b907c]
800B90AC	addiu  s0, s0, $0018

Lb90b0:	; 800B90B0
800B90B0	lhu    v0, $0010(s6)
800B90B4	nop
800B90B8	beq    v0, zero, Lb9104 [$800b9104]
800B90BC	addu   s1, zero, zero
800B90C0	sll    s5, fp, $10
800B90C4	lhu    t2, $0010(sp)
800B90C8	sll    s2, s7, $10
800B90CC	addiu  s0, s3, $0004
800B90D0	sll    s4, t2, $10

loopb90d4:	; 800B90D4
800B90D4	sra    a1, s5, $10
800B90D8	sra    a2, s4, $10
800B90DC	sra    a3, s2, $10
800B90E0	lw     a0, $0000(s0)
800B90E4	jal    funcba0f0 [$800ba0f0]
800B90E8	addiu  s1, s1, $0001
800B90EC	sw     v0, $0000(s0)
800B90F0	lhu    v0, $0010(s6)
800B90F4	nop
800B90F8	sltu   v0, s1, v0
800B90FC	bne    v0, zero, loopb90d4 [$800b90d4]
800B9100	addiu  s0, s0, $0014

Lb9104:	; 800B9104
800B9104	lw     ra, $003c(sp)
800B9108	lw     fp, $0038(sp)
800B910C	lw     s7, $0034(sp)
800B9110	lw     s6, $0030(sp)
800B9114	lw     s5, $002c(sp)
800B9118	lw     s4, $0028(sp)
800B911C	lw     s3, $0024(sp)
800B9120	lw     s2, $0020(sp)
800B9124	lw     s1, $001c(sp)
800B9128	lw     s0, $0018(sp)
800B912C	jr     ra 
800B9130	addiu  sp, sp, $0040

800B9134	addiu  sp, sp, $ffb0 (=-$50)
800B9138	addu   v1, a3, zero
800B913C	sw     ra, $004c(sp)
800B9140	sw     fp, $0048(sp)
800B9144	sw     s7, $0044(sp)
800B9148	sw     s6, $0040(sp)
800B914C	sw     s5, $003c(sp)
800B9150	sw     s4, $0038(sp)
800B9154	sw     s3, $0034(sp)
800B9158	sw     s2, $0030(sp)
800B915C	sw     s1, $002c(sp)
800B9160	sw     s0, $0028(sp)
800B9164	sw     a0, $0050(sp)
800B9168	lhu    v0, $0000(a0)
800B916C	lw     a3, $0060(sp)
800B9170	andi   v0, v0, $0010
800B9174	bne    v0, zero, Lb9708 [$800b9708]
800B9178	sb     a1, $0010(sp)

Lb917c:	; 800B917C
800B917C	sll    a3, a3, $10
800B9180	sll    a2, a2, $10
800B9184	sra    t0, a2, $10
800B9188	sll    v1, v1, $10

funcb918c:	; 800B918C
800B918C	sra    fp, v1, $10
800B9190	sw     v1, $001c(sp)
800B9194	andi   v1, a1, $00ff
800B9198	sll    v0, v1, $02
800B919C	sw     zero, $0014(sp)
800B91A0	sw     a3, $0020(sp)
800B91A4	sw     a2, $0018(sp)
800B91A8	sw     t0, $0024(sp)
800B91AC	lw     a0, $0008(a0)
800B91B0	addu   v0, v0, v1
800B91B4	lw     v1, $0010(a0)
800B91B8	sll    v0, v0, $03
800B91BC	addu   s3, v1, v0

Lb91c0:	; 800B91C0
800B91C0	lw     s5, $001c(s3)
800B91C4	lbu    v0, $0010(sp)
800B91C8	lw     t0, $0050(sp)
800B91CC	sll    v1, v0, $01
800B91D0	addu   v1, v1, v0
800B91D4	sll    v1, v1, $02
800B91D8	lw     v0, $0044(t0)
800B91DC	lw     t0, $0014(sp)
800B91E0	addu   v1, v1, v0
800B91E4	lw     s6, $0004(v1)
800B91E8	beq    t0, zero, Lb91fc [$800b91fc]
800B91EC	nop
800B91F0	lhu    v0, $0000(s3)
800B91F4	nop
800B91F8	addu   s6, s6, v0

Lb91fc:	; 800B91FC
800B91FC	lhu    v0, $0002(s3)
800B9200	nop

Lb9204:	; 800B9204
800B9204	beq    v0, zero, Lb925c [$800b925c]
800B9208	addu   s1, zero, zero
800B920C	addiu  s0, s6, $0007

loopb9210:	; 800B9210
800B9210	addiu  s6, s6, $0028
800B9214	lw     t0, $0018(sp)
800B9218	lw     a0, $0010(s5)
800B921C	addiu  s5, s5, $0018
800B9220	sra    a1, t0, $10
800B9224	lw     t0, $001c(sp)
800B9228	addiu  s1, s1, $0001
800B922C	sra    a2, t0, $10
800B9230	lw     t0, $0020(sp)
800B9234	lbu    s2, $0000(s0)
800B9238	jal    funcba0f0 [$800ba0f0]
800B923C	sra    a3, t0, $10
800B9240	sw     v0, $fffd(s0)
800B9244	sb     s2, $0000(s0)
800B9248	lhu    v0, $0002(s3)
800B924C	nop
800B9250	sltu   v0, s1, v0
800B9254	bne    v0, zero, loopb9210 [$800b9210]
800B9258	addiu  s0, s0, $0028

Lb925c:	; 800B925C
800B925C	lhu    v0, $0004(s3)
800B9260	nop
800B9264	beq    v0, zero, Lb92bc [$800b92bc]
800B9268	addu   s1, zero, zero
800B926C	addiu  s0, s6, $0007

loopb9270:	; 800B9270
800B9270	addiu  s6, s6, $0020
800B9274	lw     t0, $0018(sp)
800B9278	lw     a0, $0008(s5)
800B927C	addiu  s5, s5, $0014
800B9280	sra    a1, t0, $10
800B9284	lw     t0, $001c(sp)
800B9288	addiu  s1, s1, $0001
800B928C	sra    a2, t0, $10
800B9290	lw     t0, $0020(sp)
800B9294	lbu    s2, $0000(s0)
800B9298	jal    funcba0f0 [$800ba0f0]
800B929C	sra    a3, t0, $10
800B92A0	sw     v0, $fffd(s0)
800B92A4	sb     s2, $0000(s0)
800B92A8	lhu    v0, $0004(s3)
800B92AC	nop
800B92B0	sltu   v0, s1, v0
800B92B4	bne    v0, zero, loopb9270 [$800b9270]
800B92B8	addiu  s0, s0, $0020

Lb92bc:	; 800B92BC
800B92BC	lhu    v0, $0006(s3)
800B92C0	nop
800B92C4	beq    v0, zero, Lb93ac [$800b93ac]
800B92C8	addu   s1, zero, zero
800B92CC	lw     t0, $0020(sp)
800B92D0	nop
800B92D4	sra    s7, t0, $10
800B92D8	addiu  s4, s5, $0016
800B92DC	addiu  s0, s6, $0007

loopb92e0:	; 800B92E0
800B92E0	addu   a2, fp, zero
800B92E4	addu   a3, s7, zero
800B92E8	addiu  s6, s6, $0034
800B92EC	addiu  s5, s5, $0020
800B92F0	lw     a1, $0024(sp)
800B92F4	lhu    v0, $fffa(s4)
800B92F8	lw     v1, $0024(s3)
800B92FC	sll    v0, v0, $02
800B9300	addu   v1, v1, v0
800B9304	lw     a0, $0000(v1)
800B9308	lbu    s2, $0000(s0)
800B930C	jal    funcba0f0 [$800ba0f0]
800B9310	addiu  s1, s1, $0001
800B9314	lw     a1, $0024(sp)
800B9318	addu   a2, fp, zero
800B931C	sw     v0, $fffd(s0)
800B9320	lhu    v0, $fffc(s4)
800B9324	lw     v1, $0024(s3)
800B9328	sll    v0, v0, $02
800B932C	addu   v1, v1, v0
800B9330	lw     a0, $0000(v1)
800B9334	jal    funcba0f0 [$800ba0f0]
800B9338	addu   a3, s7, zero
800B933C	lw     a1, $0024(sp)
800B9340	addu   a2, fp, zero
800B9344	sw     v0, $0009(s0)
800B9348	lhu    v0, $fffe(s4)
800B934C	lw     v1, $0024(s3)
800B9350	sll    v0, v0, $02
800B9354	addu   v1, v1, v0
800B9358	lw     a0, $0000(v1)
800B935C	jal    funcba0f0 [$800ba0f0]
800B9360	addu   a3, s7, zero
800B9364	addu   a2, fp, zero
800B9368	lw     a1, $0024(sp)
800B936C	addu   a3, s7, zero
800B9370	sw     v0, $0015(s0)
800B9374	lhu    v0, $0000(s4)
800B9378	lw     v1, $0024(s3)
800B937C	sll    v0, v0, $02
800B9380	addu   v1, v1, v0
800B9384	lw     a0, $0000(v1)
800B9388	jal    funcba0f0 [$800ba0f0]
800B938C	addiu  s4, s4, $0020
800B9390	sw     v0, $0021(s0)
800B9394	sb     s2, $0000(s0)
800B9398	lhu    v0, $0006(s3)
800B939C	nop
800B93A0	sltu   v0, s1, v0
800B93A4	bne    v0, zero, loopb92e0 [$800b92e0]
800B93A8	addiu  s0, s0, $0034

Lb93ac:	; 800B93AC
800B93AC	lhu    v0, $0008(s3)
800B93B0	nop
800B93B4	beq    v0, zero, Lb9474 [$800b9474]
800B93B8	addu   s1, zero, zero
800B93BC	lw     t0, $0020(sp)
800B93C0	nop
800B93C4	sra    s7, t0, $10
800B93C8	addiu  s4, s5, $0014
800B93CC	addiu  s0, s6, $0007

loopb93d0:	; 800B93D0
800B93D0	addu   a2, fp, zero
800B93D4	addu   a3, s7, zero
800B93D8	addiu  s6, s6, $0028
800B93DC	addiu  s5, s5, $0018
800B93E0	lw     a1, $0024(sp)
800B93E4	lhu    v0, $fffc(s4)
800B93E8	lw     v1, $0024(s3)
800B93EC	sll    v0, v0, $02
800B93F0	addu   v1, v1, v0
800B93F4	lw     a0, $0000(v1)
800B93F8	lbu    s2, $0000(s0)
800B93FC	jal    funcba0f0 [$800ba0f0]
800B9400	addiu  s1, s1, $0001
800B9404	lw     a1, $0024(sp)
800B9408	addu   a2, fp, zero
800B940C	sw     v0, $fffd(s0)
800B9410	lhu    v0, $fffe(s4)
800B9414	lw     v1, $0024(s3)

funcb9418:	; 800B9418
800B9418	sll    v0, v0, $02
800B941C	addu   v1, v1, v0
800B9420	lw     a0, $0000(v1)
800B9424	jal    funcba0f0 [$800ba0f0]
800B9428	addu   a3, s7, zero
800B942C	addu   a2, fp, zero
800B9430	lw     a1, $0024(sp)
800B9434	addu   a3, s7, zero
800B9438	sw     v0, $0009(s0)
800B943C	lhu    v0, $0000(s4)
800B9440	lw     v1, $0024(s3)
800B9444	sll    v0, v0, $02
800B9448	addu   v1, v1, v0
800B944C	lw     a0, $0000(v1)
800B9450	jal    funcba0f0 [$800ba0f0]
800B9454	addiu  s4, s4, $0018
800B9458	sw     v0, $0015(s0)
800B945C	sb     s2, $0000(s0)
800B9460	lhu    v0, $0008(s3)
800B9464	nop
800B9468	sltu   v0, s1, v0
800B946C	bne    v0, zero, loopb93d0 [$800b93d0]
800B9470	addiu  s0, s0, $0028

Lb9474:	; 800B9474
800B9474	lhu    v0, $000a(s3)
800B9478	nop
800B947C	beq    v0, zero, Lb9564 [$800b9564]
800B9480	addu   s1, zero, zero
800B9484	lw     t0, $0020(sp)
800B9488	nop
800B948C	sra    s7, t0, $10
800B9490	addiu  s4, s5, $000e
800B9494	addiu  s0, s6, $0007

loopb9498:	; 800B9498
800B9498	addu   a2, fp, zero
800B949C	addu   a3, s7, zero
800B94A0	addiu  s6, s6, $0024
800B94A4	addiu  s5, s5, $0018
800B94A8	lw     a1, $0024(sp)
800B94AC	lhu    v0, $fffa(s4)
800B94B0	lw     v1, $0024(s3)
800B94B4	sll    v0, v0, $02
800B94B8	addu   v1, v1, v0
800B94BC	lw     a0, $0000(v1)
800B94C0	lbu    s2, $0000(s0)
800B94C4	jal    funcba0f0 [$800ba0f0]
800B94C8	addiu  s1, s1, $0001
800B94CC	lw     a1, $0024(sp)
800B94D0	addu   a2, fp, zero
800B94D4	sw     v0, $fffd(s0)
800B94D8	lhu    v0, $fffc(s4)
800B94DC	lw     v1, $0024(s3)
800B94E0	sll    v0, v0, $02
800B94E4	addu   v1, v1, v0
800B94E8	lw     a0, $0000(v1)
800B94EC	jal    funcba0f0 [$800ba0f0]
800B94F0	addu   a3, s7, zero
800B94F4	lw     a1, $0024(sp)
800B94F8	addu   a2, fp, zero
800B94FC	sw     v0, $0005(s0)
800B9500	lhu    v0, $fffe(s4)
800B9504	lw     v1, $0024(s3)
800B9508	sll    v0, v0, $02
800B950C	addu   v1, v1, v0
800B9510	lw     a0, $0000(v1)
800B9514	jal    funcba0f0 [$800ba0f0]
800B9518	addu   a3, s7, zero
800B951C	addu   a2, fp, zero
800B9520	lw     a1, $0024(sp)
800B9524	addu   a3, s7, zero
800B9528	sw     v0, $000d(s0)
800B952C	lhu    v0, $0000(s4)
800B9530	lw     v1, $0024(s3)
800B9534	sll    v0, v0, $02
800B9538	addu   v1, v1, v0
800B953C	lw     a0, $0000(v1)
800B9540	jal    funcba0f0 [$800ba0f0]
800B9544	addiu  s4, s4, $0018
800B9548	sw     v0, $0015(s0)
800B954C	sb     s2, $0000(s0)

funcb9550:	; 800B9550
800B9550	lhu    v0, $000a(s3)
800B9554	nop
800B9558	sltu   v0, s1, v0
800B955C	bne    v0, zero, loopb9498 [$800b9498]
800B9560	addiu  s0, s0, $0024

Lb9564:	; 800B9564
800B9564	lhu    v0, $000c(s3)
800B9568	nop
800B956C	beq    v0, zero, Lb962c [$800b962c]
800B9570	addu   s1, zero, zero
800B9574	lw     t0, $0020(sp)
800B9578	nop
800B957C	sra    s7, t0, $10
800B9580	addiu  s4, s5, $000c
800B9584	addiu  s0, s6, $0007

loopb9588:	; 800B9588
800B9588	addu   a2, fp, zero
800B958C	addu   a3, s7, zero
800B9590	addiu  s6, s6, $001c
800B9594	addiu  s5, s5, $0014
800B9598	lw     a1, $0024(sp)
800B959C	lhu    v0, $fffc(s4)
800B95A0	lw     v1, $0024(s3)
800B95A4	sll    v0, v0, $02
800B95A8	addu   v1, v1, v0
800B95AC	lw     a0, $0000(v1)
800B95B0	lbu    s2, $0000(s0)
800B95B4	jal    funcba0f0 [$800ba0f0]
800B95B8	addiu  s1, s1, $0001

funcb95bc:	; 800B95BC
800B95BC	lw     a1, $0024(sp)
800B95C0	addu   a2, fp, zero
800B95C4	sw     v0, $fffd(s0)
800B95C8	lhu    v0, $fffe(s4)
800B95CC	lw     v1, $0024(s3)
800B95D0	sll    v0, v0, $02
800B95D4	addu   v1, v1, v0
800B95D8	lw     a0, $0000(v1)
800B95DC	jal    funcba0f0 [$800ba0f0]
800B95E0	addu   a3, s7, zero
800B95E4	addu   a2, fp, zero
800B95E8	lw     a1, $0024(sp)
800B95EC	addu   a3, s7, zero
800B95F0	sw     v0, $0005(s0)
800B95F4	lhu    v0, $0000(s4)
800B95F8	lw     v1, $0024(s3)
800B95FC	sll    v0, v0, $02
800B9600	addu   v1, v1, v0
800B9604	lw     a0, $0000(v1)
800B9608	jal    funcba0f0 [$800ba0f0]
800B960C	addiu  s4, s4, $0014
800B9610	sw     v0, $000d(s0)
800B9614	sb     s2, $0000(s0)
800B9618	lhu    v0, $000c(s3)
800B961C	nop
800B9620	sltu   v0, s1, v0
800B9624	bne    v0, zero, loopb9588 [$800b9588]
800B9628	addiu  s0, s0, $001c

Lb962c:	; 800B962C
800B962C	lhu    v0, $000e(s3)
800B9630	nop
800B9634	beq    v0, zero, Lb9694 [$800b9694]
800B9638	addu   s1, zero, zero
800B963C	addiu  s0, s6, $0007

loopb9640:	; 800B9640
800B9640	addiu  s6, s6, $0018
800B9644	lw     t0, $0018(sp)
800B9648	lw     a0, $0008(s5)
800B964C	sra    a1, t0, $10
800B9650	lw     t0, $001c(sp)
800B9654	addiu  s5, s5, $0010
800B9658	sra    a2, t0, $10
800B965C	lw     t0, $0020(sp)
800B9660	lbu    s2, $0000(s0)
800B9664	jal    funcba0f0 [$800ba0f0]
800B9668	sra    a3, t0, $10
800B966C	lw     v1, $fffd(s0)
800B9670	addiu  s1, s1, $0001
800B9674	or     v1, v1, v0
800B9678	sw     v1, $fffd(s0)
800B967C	sb     s2, $0000(s0)
800B9680	lhu    v0, $000e(s3)
800B9684	nop
800B9688	sltu   v0, s1, v0
800B968C	bne    v0, zero, loopb9640 [$800b9640]
800B9690	addiu  s0, s0, $0018

Lb9694:	; 800B9694
800B9694	lhu    v0, $0010(s3)
800B9698	nop
800B969C	beq    v0, zero, Lb96f0 [$800b96f0]
800B96A0	addu   s1, zero, zero
800B96A4	addiu  s0, s6, $0007

loopb96a8:	; 800B96A8
800B96A8	lw     t0, $0018(sp)

funcb96ac:	; 800B96AC
800B96AC	lw     a0, $0008(s5)
800B96B0	addiu  s5, s5, $000c
800B96B4	sra    a1, t0, $10
800B96B8	lw     t0, $001c(sp)
800B96BC	addiu  s1, s1, $0001
800B96C0	sra    a2, t0, $10
800B96C4	lw     t0, $0020(sp)
800B96C8	lbu    s2, $0000(s0)
800B96CC	jal    funcba0f0 [$800ba0f0]
800B96D0	sra    a3, t0, $10
800B96D4	sw     v0, $fffd(s0)
800B96D8	sb     s2, $0000(s0)
800B96DC	lhu    v0, $0010(s3)
800B96E0	nop
800B96E4	sltu   v0, s1, v0
800B96E8	bne    v0, zero, loopb96a8 [$800b96a8]
800B96EC	addiu  s0, s0, $0014

Lb96f0:	; 800B96F0
800B96F0	lw     t0, $0014(sp)
800B96F4	nop
800B96F8	addiu  t0, t0, $0001
800B96FC	sltiu  v0, t0, $0002
800B9700	bne    v0, zero, Lb91c0 [$800b91c0]
800B9704	sw     t0, $0014(sp)

Lb9708:	; 800B9708
800B9708	lw     ra, $004c(sp)
800B970C	lw     fp, $0048(sp)
800B9710	lw     s7, $0044(sp)
800B9714	lw     s6, $0040(sp)
800B9718	lw     s5, $003c(sp)
800B971C	lw     s4, $0038(sp)
800B9720	lw     s3, $0034(sp)
800B9724	lw     s2, $0030(sp)
800B9728	lw     s1, $002c(sp)
800B972C	lw     s0, $0028(sp)
800B9730	jr     ra 
800B9734	addiu  sp, sp, $0050

800B9738	addiu  sp, sp, $ffa0 (=-$60)
800B973C	addu   t0, a0, zero
800B9740	sw     ra, $005c(sp)
800B9744	sw     fp, $0058(sp)
800B9748	sw     s7, $0054(sp)
800B974C	sw     s6, $0050(sp)
800B9750	sw     s5, $004c(sp)
800B9754	sw     s4, $0048(sp)
800B9758	sw     s3, $0044(sp)
800B975C	sw     s2, $0040(sp)
800B9760	sw     s1, $003c(sp)
800B9764	sw     s0, $0038(sp)
800B9768	sh     a2, $0010(sp)
800B976C	lhu    v0, $0000(t0)
800B9770	lhu    t1, $0070(sp)
800B9774	sh     a3, $0018(sp)
800B9778	andi   v0, v0, $0010
800B977C	bne    v0, zero, Lb9e1c [$800b9e1c]
800B9780	sh     t1, $0020(sp)
800B9784	andi   v1, a1, $00ff
800B9788	sll    v0, v1, $01
800B978C	addu   v0, v0, v1

Lb9790:	; 800B9790
800B9790	lw     a0, $0044(t0)
800B9794	sll    v0, v0, $02
800B9798	addu   v0, v0, a0
800B979C	lw     s3, $0004(v0)

funcb97a0:	; 800B97A0
800B97A0	sll    v0, v1, $02
800B97A4	addu   v0, v0, v1
800B97A8	sll    v0, v0, $03
800B97AC	lui    v1, $8006
800B97B0	lw     a0, $0008(t0)
800B97B4	lw     v1, $794c(v1)
800B97B8	lw     a0, $0010(a0)
800B97BC	lw     v1, $001c(v1)
800B97C0	addu   s4, a0, v0
800B97C4	lbu    v0, $0008(v1)
800B97C8	lw     s6, $001c(s4)
800B97CC	beq    v0, zero, Lb97e0 [$800b97e0]
800B97D0	nop
800B97D4	lhu    v0, $0000(s4)
800B97D8	nop
800B97DC	addu   s3, s3, v0

Lb97e0:	; 800B97E0
800B97E0	lhu    v0, $0002(s4)
800B97E4	nop
800B97E8	beq    v0, zero, Lb985c [$800b985c]
800B97EC	addu   s2, zero, zero
800B97F0	lui    s7, $00ff
800B97F4	ori    s7, s7, $ffff
800B97F8	sll    s5, a2, $10
800B97FC	addiu  s0, s3, $0007

loopb9800:	; 800B9800
800B9800	lw     v0, $0000(s3)
800B9804	nop
800B9808	and    v0, v0, s7
800B980C	beq    v0, zero, Lb9840 [$800b9840]
800B9810	sra    a1, s5, $10
800B9814	lhu    t1, $0018(sp)
800B9818	lw     a0, $0010(s6)
800B981C	lbu    s1, $0000(s0)
800B9820	sll    a2, t1, $10
800B9824	lhu    t1, $0020(sp)
800B9828	sra    a2, a2, $10
800B982C	sll    a3, t1, $10
800B9830	jal    funcba0f0 [$800ba0f0]
800B9834	sra    a3, a3, $10
800B9838	sw     v0, $fffd(s0)
800B983C	sb     s1, $0000(s0)

Lb9840:	; 800B9840
800B9840	addiu  s0, s0, $0028
800B9844	addiu  s3, s3, $0028
800B9848	lhu    v0, $0002(s4)
800B984C	addiu  s2, s2, $0001
800B9850	sltu   v0, s2, v0
800B9854	bne    v0, zero, loopb9800 [$800b9800]
800B9858	addiu  s6, s6, $0018

Lb985c:	; 800B985C
800B985C	lhu    v0, $0004(s4)
800B9860	nop
800B9864	beq    v0, zero, Lb98dc [$800b98dc]
800B9868	addu   s2, zero, zero
800B986C	lui    s7, $00ff
800B9870	ori    s7, s7, $ffff
800B9874	lhu    t1, $0010(sp)
800B9878	addiu  s0, s3, $0007
800B987C	sll    s5, t1, $10

loopb9880:	; 800B9880
800B9880	lw     v0, $0000(s3)
800B9884	nop
800B9888	and    v0, v0, s7
800B988C	beq    v0, zero, Lb98c0 [$800b98c0]
800B9890	sra    a1, s5, $10
800B9894	lhu    t1, $0018(sp)
800B9898	lw     a0, $0008(s6)

funcb989c:	; 800B989C
800B989C	lbu    s1, $0000(s0)
800B98A0	sll    a2, t1, $10
800B98A4	lhu    t1, $0020(sp)
800B98A8	sra    a2, a2, $10
800B98AC	sll    a3, t1, $10
800B98B0	jal    funcba0f0 [$800ba0f0]
800B98B4	sra    a3, a3, $10
800B98B8	sw     v0, $fffd(s0)
800B98BC	sb     s1, $0000(s0)

Lb98c0:	; 800B98C0
800B98C0	addiu  s0, s0, $0020
800B98C4	addiu  s3, s3, $0020
800B98C8	lhu    v0, $0004(s4)
800B98CC	addiu  s2, s2, $0001
800B98D0	sltu   v0, s2, v0
800B98D4	bne    v0, zero, loopb9880 [$800b9880]
800B98D8	addiu  s6, s6, $0014

Lb98dc:	; 800B98DC
800B98DC	lhu    v0, $0006(s4)
800B98E0	nop
800B98E4	beq    v0, zero, Lb99fc [$800b99fc]
800B98E8	addu   s2, zero, zero
800B98EC	lhu    t1, $0010(sp)
800B98F0	nop
800B98F4	sll    v0, t1, $10
800B98F8	sra    v0, v0, $10
800B98FC	addiu  s5, s6, $0016
800B9900	lhu    t1, $0018(sp)
800B9904	addiu  s0, s3, $0007
800B9908	sw     v0, $0028(sp)
800B990C	sll    v0, t1, $10
800B9910	lhu    t1, $0020(sp)
800B9914	sra    fp, v0, $10
800B9918	sll    v0, t1, $10
800B991C	sra    s7, v0, $10

loopb9920:	; 800B9920
800B9920	lui    v1, $00ff
800B9924	lw     v0, $0000(s3)
800B9928	ori    v1, v1, $ffff
800B992C	and    v0, v0, v1
800B9930	beq    v0, zero, Lb99dc [$800b99dc]
800B9934	addu   a2, fp, zero
800B9938	lw     a1, $0028(sp)
800B993C	lhu    v0, $fffa(s5)
800B9940	lw     v1, $0024(s4)
800B9944	sll    v0, v0, $02
800B9948	addu   v1, v1, v0
800B994C	lw     a0, $0000(v1)
800B9950	lbu    s1, $0000(s0)
800B9954	jal    funcba0f0 [$800ba0f0]
800B9958	addu   a3, s7, zero
800B995C	lw     a1, $0028(sp)
800B9960	addu   a2, fp, zero
800B9964	sw     v0, $fffd(s0)

Lb9968:	; 800B9968
800B9968	lhu    v0, $fffc(s5)
800B996C	lw     v1, $0024(s4)
800B9970	sll    v0, v0, $02
800B9974	addu   v1, v1, v0
800B9978	lw     a0, $0000(v1)
800B997C	jal    funcba0f0 [$800ba0f0]
800B9980	addu   a3, s7, zero
800B9984	lw     a1, $0028(sp)
800B9988	addu   a2, fp, zero
800B998C	sw     v0, $0009(s0)
800B9990	lhu    v0, $fffe(s5)

funcb9994:	; 800B9994
800B9994	lw     v1, $0024(s4)
800B9998	sll    v0, v0, $02
800B999C	addu   v1, v1, v0
800B99A0	lw     a0, $0000(v1)
800B99A4	jal    funcba0f0 [$800ba0f0]
800B99A8	addu   a3, s7, zero
800B99AC	lw     a1, $0028(sp)
800B99B0	addu   a2, fp, zero
800B99B4	sw     v0, $0015(s0)
800B99B8	lhu    v0, $0000(s5)
800B99BC	lw     v1, $0024(s4)
800B99C0	sll    v0, v0, $02
800B99C4	addu   v1, v1, v0
800B99C8	lw     a0, $0000(v1)
800B99CC	jal    funcba0f0 [$800ba0f0]
800B99D0	addu   a3, s7, zero
800B99D4	sw     v0, $0021(s0)
800B99D8	sb     s1, $0000(s0)

Lb99dc:	; 800B99DC
800B99DC	addiu  s0, s0, $0034
800B99E0	addiu  s3, s3, $0034
800B99E4	addiu  s5, s5, $0020
800B99E8	lhu    v0, $0006(s4)
800B99EC	addiu  s2, s2, $0001
800B99F0	sltu   v0, s2, v0
800B99F4	bne    v0, zero, loopb9920 [$800b9920]
800B99F8	addiu  s6, s6, $0020

Lb99fc:	; 800B99FC
800B99FC	lhu    v0, $0008(s4)
800B9A00	nop
800B9A04	beq    v0, zero, Lb9af4 [$800b9af4]
800B9A08	addu   s2, zero, zero
800B9A0C	lhu    t1, $0010(sp)
800B9A10	nop
800B9A14	sll    v0, t1, $10
800B9A18	sra    v0, v0, $10
800B9A1C	addiu  s5, s6, $0014
800B9A20	lhu    t1, $0018(sp)
800B9A24	addiu  s0, s3, $0007
800B9A28	sw     v0, $002c(sp)
800B9A2C	sll    v0, t1, $10
800B9A30	lhu    t1, $0020(sp)
800B9A34	sra    fp, v0, $10
800B9A38	sll    v0, t1, $10
800B9A3C	sra    s7, v0, $10

loopb9a40:	; 800B9A40
800B9A40	lui    v1, $00ff
800B9A44	lw     v0, $0000(s3)
800B9A48	ori    v1, v1, $ffff
800B9A4C	and    v0, v0, v1
800B9A50	beq    v0, zero, Lb9ad4 [$800b9ad4]
800B9A54	addu   a2, fp, zero
800B9A58	lw     a1, $002c(sp)

funcb9a5c:	; 800B9A5C
800B9A5C	lhu    v0, $fffc(s5)
800B9A60	lw     v1, $0024(s4)
800B9A64	sll    v0, v0, $02
800B9A68	addu   v1, v1, v0
800B9A6C	lw     a0, $0000(v1)
800B9A70	lbu    s1, $0000(s0)
800B9A74	jal    funcba0f0 [$800ba0f0]
800B9A78	addu   a3, s7, zero
800B9A7C	lw     a1, $002c(sp)
800B9A80	addu   a2, fp, zero
800B9A84	sw     v0, $fffd(s0)
800B9A88	lhu    v0, $fffe(s5)
800B9A8C	lw     v1, $0024(s4)
800B9A90	sll    v0, v0, $02
800B9A94	addu   v1, v1, v0
800B9A98	lw     a0, $0000(v1)
800B9A9C	jal    funcba0f0 [$800ba0f0]
800B9AA0	addu   a3, s7, zero
800B9AA4	lw     a1, $002c(sp)
800B9AA8	addu   a2, fp, zero
800B9AAC	sw     v0, $0009(s0)
800B9AB0	lhu    v0, $0000(s5)
800B9AB4	lw     v1, $0024(s4)
800B9AB8	sll    v0, v0, $02
800B9ABC	addu   v1, v1, v0
800B9AC0	lw     a0, $0000(v1)
800B9AC4	jal    funcba0f0 [$800ba0f0]
800B9AC8	addu   a3, s7, zero
800B9ACC	sw     v0, $0015(s0)
800B9AD0	sb     s1, $0000(s0)

Lb9ad4:	; 800B9AD4
800B9AD4	addiu  s0, s0, $0028
800B9AD8	addiu  s3, s3, $0028
800B9ADC	addiu  s5, s5, $0018
800B9AE0	lhu    v0, $0008(s4)

funcb9ae4:	; 800B9AE4
800B9AE4	addiu  s2, s2, $0001
800B9AE8	sltu   v0, s2, v0
800B9AEC	bne    v0, zero, loopb9a40 [$800b9a40]
800B9AF0	addiu  s6, s6, $0018

Lb9af4:	; 800B9AF4
800B9AF4	lhu    v0, $000a(s4)
800B9AF8	nop

funcb9afc:	; 800B9AFC
800B9AFC	beq    v0, zero, Lb9c14 [$800b9c14]
800B9B00	addu   s2, zero, zero
800B9B04	lhu    t1, $0010(sp)
800B9B08	nop
800B9B0C	sll    v0, t1, $10
800B9B10	sra    v0, v0, $10
800B9B14	addiu  s5, s6, $000e
800B9B18	lhu    t1, $0018(sp)
800B9B1C	addiu  s0, s3, $0007
800B9B20	sw     v0, $0030(sp)
800B9B24	sll    v0, t1, $10
800B9B28	lhu    t1, $0020(sp)
800B9B2C	sra    fp, v0, $10
800B9B30	sll    v0, t1, $10
800B9B34	sra    s7, v0, $10

loopb9b38:	; 800B9B38
800B9B38	lui    v1, $00ff
800B9B3C	lw     v0, $0000(s3)
800B9B40	ori    v1, v1, $ffff
800B9B44	and    v0, v0, v1
800B9B48	beq    v0, zero, Lb9bf4 [$800b9bf4]
800B9B4C	addu   a2, fp, zero
800B9B50	lw     a1, $0030(sp)
800B9B54	lhu    v0, $fffa(s5)
800B9B58	lw     v1, $0024(s4)
800B9B5C	sll    v0, v0, $02
800B9B60	addu   v1, v1, v0

funcb9b64:	; 800B9B64
800B9B64	lw     a0, $0000(v1)
800B9B68	lbu    s1, $0000(s0)
800B9B6C	jal    funcba0f0 [$800ba0f0]
800B9B70	addu   a3, s7, zero
800B9B74	lw     a1, $0030(sp)
800B9B78	addu   a2, fp, zero
800B9B7C	sw     v0, $fffd(s0)
800B9B80	lhu    v0, $fffc(s5)
800B9B84	lw     v1, $0024(s4)
800B9B88	sll    v0, v0, $02
800B9B8C	addu   v1, v1, v0
800B9B90	lw     a0, $0000(v1)
800B9B94	jal    funcba0f0 [$800ba0f0]
800B9B98	addu   a3, s7, zero
800B9B9C	lw     a1, $0030(sp)
800B9BA0	addu   a2, fp, zero
800B9BA4	sw     v0, $0005(s0)
800B9BA8	lhu    v0, $fffe(s5)
800B9BAC	lw     v1, $0024(s4)
800B9BB0	sll    v0, v0, $02
800B9BB4	addu   v1, v1, v0
800B9BB8	lw     a0, $0000(v1)
800B9BBC	jal    funcba0f0 [$800ba0f0]
800B9BC0	addu   a3, s7, zero
800B9BC4	lw     a1, $0030(sp)
800B9BC8	addu   a2, fp, zero
800B9BCC	sw     v0, $000d(s0)
800B9BD0	lhu    v0, $0000(s5)
800B9BD4	lw     v1, $0024(s4)
800B9BD8	sll    v0, v0, $02
800B9BDC	addu   v1, v1, v0
800B9BE0	lw     a0, $0000(v1)
800B9BE4	jal    funcba0f0 [$800ba0f0]
800B9BE8	addu   a3, s7, zero
800B9BEC	sw     v0, $0015(s0)
800B9BF0	sb     s1, $0000(s0)

Lb9bf4:	; 800B9BF4
800B9BF4	addiu  s0, s0, $0024
800B9BF8	addiu  s3, s3, $0024
800B9BFC	addiu  s5, s5, $0018
800B9C00	lhu    v0, $000a(s4)
800B9C04	addiu  s2, s2, $0001
800B9C08	sltu   v0, s2, v0
800B9C0C	bne    v0, zero, loopb9b38 [$800b9b38]
800B9C10	addiu  s6, s6, $0018

Lb9c14:	; 800B9C14
800B9C14	lhu    v0, $000c(s4)
800B9C18	nop
800B9C1C	beq    v0, zero, Lb9d0c [$800b9d0c]
800B9C20	addu   s2, zero, zero
800B9C24	lhu    t1, $0010(sp)
800B9C28	nop
800B9C2C	sll    v0, t1, $10

funcb9c30:	; 800B9C30
800B9C30	sra    v0, v0, $10
800B9C34	addiu  s5, s6, $000c
800B9C38	lhu    t1, $0018(sp)
800B9C3C	addiu  s0, s3, $0007
800B9C40	sw     v0, $0034(sp)
800B9C44	sll    v0, t1, $10
800B9C48	lhu    t1, $0020(sp)
800B9C4C	sra    fp, v0, $10
800B9C50	sll    v0, t1, $10
800B9C54	sra    s7, v0, $10

loopb9c58:	; 800B9C58
800B9C58	lui    v1, $00ff
800B9C5C	lw     v0, $0000(s3)
800B9C60	ori    v1, v1, $ffff
800B9C64	and    v0, v0, v1
800B9C68	beq    v0, zero, Lb9cec [$800b9cec]
800B9C6C	addu   a2, fp, zero
800B9C70	lw     a1, $0034(sp)

funcb9c74:	; 800B9C74
800B9C74	lhu    v0, $fffc(s5)
800B9C78	lw     v1, $0024(s4)
800B9C7C	sll    v0, v0, $02
800B9C80	addu   v1, v1, v0
800B9C84	lw     a0, $0000(v1)
800B9C88	lbu    s1, $0000(s0)
800B9C8C	jal    funcba0f0 [$800ba0f0]
800B9C90	addu   a3, s7, zero
800B9C94	lw     a1, $0034(sp)
800B9C98	addu   a2, fp, zero
800B9C9C	sw     v0, $fffd(s0)
800B9CA0	lhu    v0, $fffe(s5)
800B9CA4	lw     v1, $0024(s4)
800B9CA8	sll    v0, v0, $02
800B9CAC	addu   v1, v1, v0
800B9CB0	lw     a0, $0000(v1)
800B9CB4	jal    funcba0f0 [$800ba0f0]
800B9CB8	addu   a3, s7, zero
800B9CBC	lw     a1, $0034(sp)
800B9CC0	addu   a2, fp, zero
800B9CC4	sw     v0, $0005(s0)
800B9CC8	lhu    v0, $0000(s5)
800B9CCC	lw     v1, $0024(s4)
800B9CD0	sll    v0, v0, $02
800B9CD4	addu   v1, v1, v0
800B9CD8	lw     a0, $0000(v1)

funcb9cdc:	; 800B9CDC
800B9CDC	jal    funcba0f0 [$800ba0f0]
800B9CE0	addu   a3, s7, zero
800B9CE4	sw     v0, $000d(s0)
800B9CE8	sb     s1, $0000(s0)

Lb9cec:	; 800B9CEC
800B9CEC	addiu  s0, s0, $001c
800B9CF0	addiu  s3, s3, $001c
800B9CF4	addiu  s5, s5, $0014
800B9CF8	lhu    v0, $000c(s4)
800B9CFC	addiu  s2, s2, $0001
800B9D00	sltu   v0, s2, v0
800B9D04	bne    v0, zero, loopb9c58 [$800b9c58]
800B9D08	addiu  s6, s6, $0014

Lb9d0c:	; 800B9D0C
800B9D0C	lhu    v0, $000e(s4)
800B9D10	nop
800B9D14	beq    v0, zero, Lb9d9c [$800b9d9c]
800B9D18	addu   s2, zero, zero
800B9D1C	lui    s5, $00ff
800B9D20	ori    s5, s5, $ffff
800B9D24	addiu  s0, s3, $0007

loopb9d28:	; 800B9D28
800B9D28	lw     v0, $0000(s3)
800B9D2C	nop
800B9D30	and    v0, v0, s5

funcb9d34:	; 800B9D34
800B9D34	beq    v0, zero, Lb9d80 [$800b9d80]
800B9D38	nop
800B9D3C	lhu    t1, $0010(sp)
800B9D40	lw     a0, $0008(s6)
800B9D44	lbu    s1, $0000(s0)
800B9D48	sll    a1, t1, $10
800B9D4C	lhu    t1, $0018(sp)
800B9D50	sra    a1, a1, $10
800B9D54	sll    a2, t1, $10
800B9D58	lhu    t1, $0020(sp)
800B9D5C	sra    a2, a2, $10
800B9D60	sll    a3, t1, $10
800B9D64	jal    funcba0f0 [$800ba0f0]
800B9D68	sra    a3, a3, $10

funcb9d6c:	; 800B9D6C
800B9D6C	lw     v1, $fffd(s0)
800B9D70	nop
800B9D74	or     v1, v1, v0
800B9D78	sw     v1, $fffd(s0)
800B9D7C	sb     s1, $0000(s0)

Lb9d80:	; 800B9D80
800B9D80	addiu  s0, s0, $0018
800B9D84	addiu  s3, s3, $0018
800B9D88	lhu    v0, $000e(s4)
800B9D8C	addiu  s2, s2, $0001
800B9D90	sltu   v0, s2, v0
800B9D94	bne    v0, zero, loopb9d28 [$800b9d28]
800B9D98	addiu  s6, s6, $0010

Lb9d9c:	; 800B9D9C
800B9D9C	lhu    v0, $0010(s4)
800B9DA0	nop

funcb9da4:	; 800B9DA4
800B9DA4	beq    v0, zero, Lb9e1c [$800b9e1c]
800B9DA8	addu   s2, zero, zero
800B9DAC	lui    s7, $00ff
800B9DB0	ori    s7, s7, $ffff
800B9DB4	lhu    t1, $0010(sp)
800B9DB8	addiu  s0, s3, $0007
800B9DBC	sll    s5, t1, $10

loopb9dc0:	; 800B9DC0
800B9DC0	lw     v0, $0000(s3)
800B9DC4	nop
800B9DC8	and    v0, v0, s7
800B9DCC	beq    v0, zero, Lb9e00 [$800b9e00]
800B9DD0	sra    a1, s5, $10
800B9DD4	lhu    t1, $0018(sp)
800B9DD8	lw     a0, $0008(s6)

funcb9ddc:	; 800B9DDC
800B9DDC	lbu    s1, $0000(s0)
800B9DE0	sll    a2, t1, $10
800B9DE4	lhu    t1, $0020(sp)
800B9DE8	sra    a2, a2, $10
800B9DEC	sll    a3, t1, $10
800B9DF0	jal    funcba0f0 [$800ba0f0]
800B9DF4	sra    a3, a3, $10
800B9DF8	sw     v0, $fffd(s0)
800B9DFC	sb     s1, $0000(s0)

Lb9e00:	; 800B9E00
800B9E00	addiu  s0, s0, $0014
800B9E04	addiu  s3, s3, $0014
800B9E08	lhu    v0, $0010(s4)
800B9E0C	addiu  s2, s2, $0001
800B9E10	sltu   v0, s2, v0
800B9E14	bne    v0, zero, loopb9dc0 [$800b9dc0]
800B9E18	addiu  s6, s6, $000c

Lb9e1c:	; 800B9E1C
800B9E1C	lw     ra, $005c(sp)

funcb9e20:	; 800B9E20
800B9E20	lw     fp, $0058(sp)
800B9E24	lw     s7, $0054(sp)
800B9E28	lw     s6, $0050(sp)
800B9E2C	lw     s5, $004c(sp)
800B9E30	lw     s4, $0048(sp)
800B9E34	lw     s3, $0044(sp)
800B9E38	lw     s2, $0040(sp)
800B9E3C	lw     s1, $003c(sp)
800B9E40	lw     s0, $0038(sp)
800B9E44	jr     ra 
800B9E48	addiu  sp, sp, $0060


funcb9e4c:	; 800B9E4C
800B9E4C	addu   t1, a0, zero

funcb9e50:	; 800B9E50
800B9E50	lhu    v0, $0000(t1)
800B9E54	lw     a0, $0010(sp)
800B9E58	andi   v0, v0, $0010
800B9E5C	bne    v0, zero, Lba0e8 [$800ba0e8]
800B9E60	andi   a1, a1, $00ff
800B9E64	sll    v0, a1, $02
800B9E68	addu   v0, v0, a1
800B9E6C	lw     v1, $0008(t1)
800B9E70	sll    v0, v0, $03
800B9E74	lw     v1, $0010(v1)
800B9E78	sll    a0, a0, $10
800B9E7C	addu   t0, v1, v0
800B9E80	sll    v0, a3, $10
800B9E84	sra    v0, v0, $08

funcb9e88:	; 800B9E88
800B9E88	or     a0, a0, v0
800B9E8C	lui    v0, $8006
800B9E90	lw     v1, $794c(v0)
800B9E94	sll    v0, a2, $10
800B9E98	lw     v1, $001c(v1)
800B9E9C	sra    v0, v0, $10
800B9EA0	lbu    v1, $0008(v1)
800B9EA4	nop
800B9EA8	beq    v1, zero, Lb9ed4 [$800b9ed4]
800B9EAC	or     a0, a0, v0
800B9EB0	sll    v0, a1, $01
800B9EB4	addu   v0, v0, a1
800B9EB8	lw     v1, $0044(t1)
800B9EBC	sll    v0, v0, $02
800B9EC0	addu   v0, v0, v1
800B9EC4	lhu    v1, $0000(t0)
800B9EC8	lw     v0, $0004(v0)
800B9ECC	j      Lb9eec [$800b9eec]
800B9ED0	addu   a2, v0, v1

Lb9ed4:	; 800B9ED4
800B9ED4	sll    v0, a1, $01
800B9ED8	addu   v0, v0, a1
800B9EDC	lw     v1, $0044(t1)
800B9EE0	sll    v0, v0, $02
800B9EE4	addu   v0, v0, v1
800B9EE8	lw     a2, $0004(v0)

Lb9eec:	; 800B9EEC
800B9EEC	lhu    v0, $0002(t0)
800B9EF0	nop
800B9EF4	beq    v0, zero, Lb9f2c [$800b9f2c]
800B9EF8	addu   v1, zero, zero
800B9EFC	addiu  a1, a2, $0004

loopb9f00:	; 800B9F00
800B9F00	addiu  a2, a2, $0028
800B9F04	lbu    v0, $0003(a1)
800B9F08	addiu  v1, v1, $0001
800B9F0C	sll    v0, v0, $18
800B9F10	or     v0, a0, v0
800B9F14	sw     v0, $0000(a1)
800B9F18	lhu    v0, $0002(t0)
800B9F1C	nop
800B9F20	sltu   v0, v1, v0
800B9F24	bne    v0, zero, loopb9f00 [$800b9f00]
800B9F28	addiu  a1, a1, $0028

Lb9f2c:	; 800B9F2C
800B9F2C	lhu    v0, $0004(t0)
800B9F30	nop
800B9F34	beq    v0, zero, Lb9f6c [$800b9f6c]
800B9F38	addu   v1, zero, zero
800B9F3C	addiu  a1, a2, $0004

loopb9f40:	; 800B9F40
800B9F40	addiu  a2, a2, $0020
800B9F44	lbu    v0, $0003(a1)
800B9F48	addiu  v1, v1, $0001
800B9F4C	sll    v0, v0, $18
800B9F50	or     v0, a0, v0
800B9F54	sw     v0, $0000(a1)
800B9F58	lhu    v0, $0004(t0)
800B9F5C	nop
800B9F60	sltu   v0, v1, v0
800B9F64	bne    v0, zero, loopb9f40 [$800b9f40]
800B9F68	addiu  a1, a1, $0020

Lb9f6c:	; 800B9F6C
800B9F6C	lhu    v0, $0006(t0)
800B9F70	nop
800B9F74	beq    v0, zero, Lb9fac [$800b9fac]
800B9F78	addu   v1, zero, zero
800B9F7C	addiu  a1, a2, $0004

loopb9f80:	; 800B9F80
800B9F80	addiu  a2, a2, $0034
800B9F84	lbu    v0, $0003(a1)
800B9F88	addiu  v1, v1, $0001
800B9F8C	sll    v0, v0, $18
800B9F90	or     v0, a0, v0
800B9F94	sw     v0, $0000(a1)
800B9F98	lhu    v0, $0006(t0)
800B9F9C	nop
800B9FA0	sltu   v0, v1, v0
800B9FA4	bne    v0, zero, loopb9f80 [$800b9f80]
800B9FA8	addiu  a1, a1, $0034

Lb9fac:	; 800B9FAC
800B9FAC	lhu    v0, $0008(t0)
800B9FB0	nop
800B9FB4	beq    v0, zero, Lb9fec [$800b9fec]
800B9FB8	addu   v1, zero, zero
800B9FBC	addiu  a1, a2, $0004

loopb9fc0:	; 800B9FC0
800B9FC0	addiu  a2, a2, $0028
800B9FC4	lbu    v0, $0003(a1)
800B9FC8	addiu  v1, v1, $0001
800B9FCC	sll    v0, v0, $18
800B9FD0	or     v0, a0, v0
800B9FD4	sw     v0, $0000(a1)
800B9FD8	lhu    v0, $0008(t0)
800B9FDC	nop
800B9FE0	sltu   v0, v1, v0
800B9FE4	bne    v0, zero, loopb9fc0 [$800b9fc0]
800B9FE8	addiu  a1, a1, $0028

Lb9fec:	; 800B9FEC
800B9FEC	lhu    v0, $000a(t0)
800B9FF0	nop
800B9FF4	beq    v0, zero, Lba02c [$800ba02c]
800B9FF8	addu   v1, zero, zero
800B9FFC	addiu  a1, a2, $0004

loopba000:	; 800BA000
800BA000	addiu  a2, a2, $0024
800BA004	lbu    v0, $0003(a1)
800BA008	addiu  v1, v1, $0001
800BA00C	sll    v0, v0, $18
800BA010	or     v0, a0, v0
800BA014	sw     v0, $0000(a1)
800BA018	lhu    v0, $000a(t0)
800BA01C	nop
800BA020	sltu   v0, v1, v0
800BA024	bne    v0, zero, loopba000 [$800ba000]
800BA028	addiu  a1, a1, $0024

Lba02c:	; 800BA02C
800BA02C	lhu    v0, $000c(t0)
800BA030	nop
800BA034	beq    v0, zero, Lba06c [$800ba06c]
800BA038	addu   v1, zero, zero
800BA03C	addiu  a1, a2, $0004

loopba040:	; 800BA040
800BA040	addiu  a2, a2, $001c
800BA044	lbu    v0, $0003(a1)
800BA048	addiu  v1, v1, $0001
800BA04C	sll    v0, v0, $18
800BA050	or     v0, a0, v0
800BA054	sw     v0, $0000(a1)
800BA058	lhu    v0, $000c(t0)
800BA05C	nop
800BA060	sltu   v0, v1, v0
800BA064	bne    v0, zero, loopba040 [$800ba040]
800BA068	addiu  a1, a1, $001c

Lba06c:	; 800BA06C
800BA06C	lhu    v0, $000e(t0)
800BA070	nop
800BA074	beq    v0, zero, Lba0ac [$800ba0ac]

funcba078:	; 800BA078
800BA078	addu   v1, zero, zero
800BA07C	addiu  a1, a2, $0004

loopba080:	; 800BA080
800BA080	addiu  a2, a2, $0018
800BA084	lbu    v0, $0003(a1)
800BA088	addiu  v1, v1, $0001
800BA08C	sll    v0, v0, $18
800BA090	or     v0, a0, v0

funcba094:	; 800BA094
800BA094	sw     v0, $0000(a1)
800BA098	lhu    v0, $000e(t0)
800BA09C	nop
800BA0A0	sltu   v0, v1, v0
800BA0A4	bne    v0, zero, loopba080 [$800ba080]
800BA0A8	addiu  a1, a1, $0018

Lba0ac:	; 800BA0AC
800BA0AC	lhu    v0, $0010(t0)
800BA0B0	nop
800BA0B4	beq    v0, zero, Lba0e8 [$800ba0e8]
800BA0B8	addu   v1, zero, zero
800BA0BC	addiu  a1, a2, $0004

loopba0c0:	; 800BA0C0
800BA0C0	lbu    v0, $0003(a1)
800BA0C4	addiu  v1, v1, $0001
800BA0C8	sll    v0, v0, $18
800BA0CC	or     v0, a0, v0
800BA0D0	sw     v0, $0000(a1)
800BA0D4	lhu    v0, $0010(t0)
800BA0D8	nop
800BA0DC	sltu   v0, v1, v0
800BA0E0	bne    v0, zero, loopba0c0 [$800ba0c0]
800BA0E4	addiu  a1, a1, $0014

Lba0e8:	; 800BA0E8
800BA0E8	jr     ra 
800BA0EC	nop


funcba0f0:	; 800BA0F0
800BA0F0	srl    v0, a0, $10
800BA0F4	andi   v0, v0, $00ff
800BA0F8	addu   a3, a3, v0
800BA0FC	srl    v0, a0, $08
800BA100	andi   v0, v0, $00ff
800BA104	addu   a2, a2, v0
800BA108	andi   v1, a0, $00ff
800BA10C	lui    v0, $ff00
800BA110	and    a0, a0, v0
800BA114	addu   a1, a1, v1
800BA118	sll    a1, a1, $10
800BA11C	sra    a1, a1, $10
800BA120	slti   v0, a1, $0100
800BA124	bne    v0, zero, Lba134 [$800ba134]
800BA128	nop
800BA12C	j      Lba140 [$800ba140]
800BA130	ori    a0, a0, $00ff

Lba134:	; 800BA134
800BA134	blez   a1, Lba144 [$800ba144]
800BA138	sll    v0, a2, $10
800BA13C	or     a0, a0, a1

Lba140:	; 800BA140
800BA140	sll    v0, a2, $10

Lba144:	; 800BA144
800BA144	sra    v1, v0, $10
800BA148	slti   v0, v1, $0100
800BA14C	bne    v0, zero, Lba15c [$800ba15c]
800BA150	nop
800BA154	j      Lba168 [$800ba168]
800BA158	ori    a0, a0, $ff00

Lba15c:	; 800BA15C
800BA15C	blez   v1, Lba168 [$800ba168]
800BA160	sll    v0, v1, $08
800BA164	or     a0, a0, v0

Lba168:	; 800BA168
800BA168	sll    v0, a3, $10
800BA16C	sra    v1, v0, $10
800BA170	slti   v0, v1, $0100
800BA174	beq    v0, zero, Lba184 [$800ba184]
800BA178	lui    v0, $00ff
800BA17C	blez   v1, Lba188 [$800ba188]
800BA180	sll    v0, v1, $10

Lba184:	; 800BA184
800BA184	or     a0, a0, v0

Lba188:	; 800BA188
800BA188	jr     ra 
800BA18C	addu   v0, a0, zero


funcba190:	; 800BA190
800BA190	lhu    v0, $0000(a0)
800BA194	nop
800BA198	andi   v0, v0, $0010
800BA19C	bne    v0, zero, Lba3c4 [$800ba3c4]
800BA1A0	nop
800BA1A4	lw     v1, $0008(a0)
800BA1A8	nop
800BA1AC	lbu    v0, $0003(v1)
800BA1B0	nop

funcba1b4:	; 800BA1B4
800BA1B4	beq    v0, zero, Lba3c4 [$800ba3c4]
800BA1B8	addu   t2, zero, zero
800BA1BC	andi   a1, a1, $ffff
800BA1C0	addu   t4, t2, zero
800BA1C4	addu   t3, t2, zero

Lba1c8:	; 800BA1C8
800BA1C8	lw     v0, $0010(v1)
800BA1CC	nop
800BA1D0	addu   t1, v0, t3
800BA1D4	lui    v0, $8006
800BA1D8	lw     t0, $001c(t1)
800BA1DC	lw     v1, $794c(v0)
800BA1E0	lw     v0, $0044(a0)
800BA1E4	lw     v1, $001c(v1)
800BA1E8	addu   v0, t4, v0
800BA1EC	lbu    v1, $0008(v1)
800BA1F0	lw     a3, $0004(v0)
800BA1F4	beq    v1, zero, Lba208 [$800ba208]
800BA1F8	nop
800BA1FC	lhu    v0, $0000(t1)
800BA200	nop
800BA204	addu   a3, a3, v0

Lba208:	; 800BA208
800BA208	lhu    v0, $0002(t1)
800BA20C	nop
800BA210	beq    v0, zero, Lba270 [$800ba270]
800BA214	addu   a2, zero, zero
800BA218	addiu  v1, a3, $0007

loopba21c:	; 800BA21C
800BA21C	lbu    v0, $0015(t0)
800BA220	nop
800BA224	andi   v0, v0, $0001
800BA228	bne    v0, zero, Lba238 [$800ba238]
800BA22C	nop
800BA230	beq    a1, zero, Lba244 [$800ba244]
800BA234	nop

Lba238:	; 800BA238
800BA238	lbu    v0, $0000(v1)
800BA23C	j      Lba250 [$800ba250]
800BA240	ori    v0, v0, $0002

Lba244:	; 800BA244
800BA244	lbu    v0, $0000(v1)
800BA248	nop
800BA24C	andi   v0, v0, $00fd

Lba250:	; 800BA250
800BA250	sb     v0, $0000(v1)
800BA254	addiu  v1, v1, $0028
800BA258	addiu  a3, a3, $0028
800BA25C	lhu    v0, $0002(t1)
800BA260	addiu  a2, a2, $0001
800BA264	sltu   v0, a2, v0
800BA268	bne    v0, zero, loopba21c [$800ba21c]
800BA26C	addiu  t0, t0, $0018

Lba270:	; 800BA270
800BA270	lhu    v0, $0004(t1)
800BA274	nop
800BA278	beq    v0, zero, Lba2d8 [$800ba2d8]
800BA27C	addu   a2, zero, zero
800BA280	addiu  v1, a3, $0007

loopba284:	; 800BA284
800BA284	lbu    v0, $0012(t0)
800BA288	nop
800BA28C	andi   v0, v0, $0001
800BA290	bne    v0, zero, Lba2a0 [$800ba2a0]
800BA294	nop
800BA298	beq    a1, zero, Lba2ac [$800ba2ac]
800BA29C	nop

Lba2a0:	; 800BA2A0
800BA2A0	lbu    v0, $0000(v1)
800BA2A4	j      Lba2b8 [$800ba2b8]
800BA2A8	ori    v0, v0, $0002

Lba2ac:	; 800BA2AC
800BA2AC	lbu    v0, $0000(v1)
800BA2B0	nop
800BA2B4	andi   v0, v0, $00fd

Lba2b8:	; 800BA2B8
800BA2B8	sb     v0, $0000(v1)
800BA2BC	addiu  t0, t0, $0014
800BA2C0	addiu  v1, v1, $0020
800BA2C4	lhu    v0, $0004(t1)
800BA2C8	addiu  a2, a2, $0001
800BA2CC	sltu   v0, a2, v0
800BA2D0	bne    v0, zero, loopba284 [$800ba284]
800BA2D4	addiu  a3, a3, $0020

Lba2d8:	; 800BA2D8
800BA2D8	lhu    v0, $0006(t1)
800BA2DC	nop
800BA2E0	beq    v0, zero, Lba340 [$800ba340]
800BA2E4	addu   a2, zero, zero
800BA2E8	addiu  v1, a3, $0007

loopba2ec:	; 800BA2EC
800BA2EC	lbu    v0, $001c(t0)
800BA2F0	nop
800BA2F4	andi   v0, v0, $0001
800BA2F8	bne    v0, zero, Lba308 [$800ba308]
800BA2FC	nop
800BA300	beq    a1, zero, Lba314 [$800ba314]
800BA304	nop

Lba308:	; 800BA308
800BA308	lbu    v0, $0000(v1)
800BA30C	j      Lba320 [$800ba320]
800BA310	ori    v0, v0, $0002

Lba314:	; 800BA314
800BA314	lbu    v0, $0000(v1)
800BA318	nop
800BA31C	andi   v0, v0, $00fd

Lba320:	; 800BA320
800BA320	sb     v0, $0000(v1)
800BA324	addiu  t0, t0, $0020
800BA328	addiu  v1, v1, $0034
800BA32C	lhu    v0, $0006(t1)
800BA330	addiu  a2, a2, $0001
800BA334	sltu   v0, a2, v0
800BA338	bne    v0, zero, loopba2ec [$800ba2ec]
800BA33C	addiu  a3, a3, $0034

Lba340:	; 800BA340
800BA340	lhu    v0, $0008(t1)
800BA344	nop
800BA348	beq    v0, zero, Lba3a4 [$800ba3a4]
800BA34C	addu   a2, zero, zero
800BA350	addiu  v1, a3, $0007

loopba354:	; 800BA354
800BA354	lbu    v0, $000f(t0)
800BA358	nop
800BA35C	andi   v0, v0, $0001
800BA360	bne    v0, zero, Lba370 [$800ba370]
800BA364	nop
800BA368	beq    a1, zero, Lba37c [$800ba37c]
800BA36C	nop

Lba370:	; 800BA370
800BA370	lbu    v0, $0000(v1)
800BA374	j      Lba388 [$800ba388]
800BA378	ori    v0, v0, $0002

Lba37c:	; 800BA37C
800BA37C	lbu    v0, $0000(v1)
800BA380	nop
800BA384	andi   v0, v0, $00fd

Lba388:	; 800BA388
800BA388	sb     v0, $0000(v1)
800BA38C	addiu  t0, t0, $0018
800BA390	lhu    v0, $0008(t1)
800BA394	addiu  a2, a2, $0001
800BA398	sltu   v0, a2, v0
800BA39C	bne    v0, zero, loopba354 [$800ba354]
800BA3A0	addiu  v1, v1, $0028

Lba3a4:	; 800BA3A4
800BA3A4	addiu  t4, t4, $000c
800BA3A8	lw     v1, $0008(a0)
800BA3AC	nop
800BA3B0	lbu    v0, $0003(v1)
800BA3B4	addiu  t2, t2, $0001
800BA3B8	sltu   v0, t2, v0
800BA3BC	bne    v0, zero, Lba1c8 [$800ba1c8]
800BA3C0	addiu  t3, t3, $0028

Lba3c4:	; 800BA3C4
800BA3C4	jr     ra 
800BA3C8	nop


funcba3cc:	; 800BA3CC
800BA3CC	lhu    v0, $0000(a0)
800BA3D0	nop
800BA3D4	andi   v0, v0, $0010
800BA3D8	bne    v0, zero, Lba558 [$800ba558]
800BA3DC	nop
800BA3E0	lw     v1, $0008(a0)
800BA3E4	nop
800BA3E8	lbu    v0, $0003(v1)
800BA3EC	nop
800BA3F0	beq    v0, zero, Lba558 [$800ba558]
800BA3F4	addu   t1, zero, zero
800BA3F8	lui    v0, $8006

funcba3fc:	; 800BA3FC
800BA3FC	lw     t4, $794c(v0)
800BA400	addu   t3, t1, zero
800BA404	addu   t2, t1, zero

loopba408:	; 800BA408
800BA408	lw     v0, $0044(a0)
800BA40C	nop
800BA410	addu   v0, t3, v0
800BA414	lw     t0, $0004(v0)
800BA418	lw     v0, $001c(t4)
800BA41C	lw     v1, $0010(v1)
800BA420	lbu    v0, $0008(v0)
800BA424	nop
800BA428	beq    v0, zero, Lba43c [$800ba43c]
800BA42C	addu   v1, v1, t2
800BA430	lhu    v0, $0000(v1)
800BA434	nop
800BA438	addu   t0, t0, v0

Lba43c:	; 800BA43C
800BA43C	lhu    v0, $0002(v1)
800BA440	nop
800BA444	beq    v0, zero, Lba47c [$800ba47c]
800BA448	addu   a2, zero, zero
800BA44C	addiu  a3, t0, $0016

loopba450:	; 800BA450
800BA450	addiu  t0, t0, $0028
800BA454	lhu    v0, $0000(a3)
800BA458	addiu  a2, a2, $0001
800BA45C	andi   v0, v0, $ff9f
800BA460	or     v0, a1, v0
800BA464	sh     v0, $0000(a3)

funcba468:	; 800BA468
800BA468	lhu    v0, $0002(v1)
800BA46C	nop
800BA470	sltu   v0, a2, v0
800BA474	bne    v0, zero, loopba450 [$800ba450]
800BA478	addiu  a3, a3, $0028

Lba47c:	; 800BA47C
800BA47C	lhu    v0, $0004(v1)
800BA480	nop
800BA484	beq    v0, zero, Lba4bc [$800ba4bc]
800BA488	addu   a2, zero, zero
800BA48C	addiu  a3, t0, $0016

loopba490:	; 800BA490
800BA490	addiu  t0, t0, $0020
800BA494	lhu    v0, $0000(a3)
800BA498	addiu  a2, a2, $0001
800BA49C	andi   v0, v0, $ff9f
800BA4A0	or     v0, a1, v0
800BA4A4	sh     v0, $0000(a3)
800BA4A8	lhu    v0, $0004(v1)

funcba4ac:	; 800BA4AC
800BA4AC	nop
800BA4B0	sltu   v0, a2, v0
800BA4B4	bne    v0, zero, loopba490 [$800ba490]
800BA4B8	addiu  a3, a3, $0020

Lba4bc:	; 800BA4BC
800BA4BC	lhu    v0, $0006(v1)
800BA4C0	nop
800BA4C4	beq    v0, zero, Lba4fc [$800ba4fc]
800BA4C8	addu   a2, zero, zero
800BA4CC	addiu  a3, t0, $001a

loopba4d0:	; 800BA4D0
800BA4D0	addiu  t0, t0, $0034
800BA4D4	lhu    v0, $0000(a3)
800BA4D8	addiu  a2, a2, $0001
800BA4DC	andi   v0, v0, $ff9f
800BA4E0	or     v0, a1, v0
800BA4E4	sh     v0, $0000(a3)
800BA4E8	lhu    v0, $0006(v1)
800BA4EC	nop

funcba4f0:	; 800BA4F0
800BA4F0	sltu   v0, a2, v0
800BA4F4	bne    v0, zero, loopba4d0 [$800ba4d0]
800BA4F8	addiu  a3, a3, $0034

Lba4fc:	; 800BA4FC
800BA4FC	lhu    v0, $0008(v1)
800BA500	nop
800BA504	beq    v0, zero, Lba538 [$800ba538]
800BA508	addu   a2, zero, zero
800BA50C	addiu  a3, t0, $001a

loopba510:	; 800BA510
800BA510	lhu    v0, $0000(a3)
800BA514	addiu  a2, a2, $0001
800BA518	andi   v0, v0, $ff9f
800BA51C	or     v0, a1, v0
800BA520	sh     v0, $0000(a3)
800BA524	lhu    v0, $0008(v1)
800BA528	nop
800BA52C	sltu   v0, a2, v0
800BA530	bne    v0, zero, loopba510 [$800ba510]

funcba534:	; 800BA534
800BA534	addiu  a3, a3, $0028

Lba538:	; 800BA538
800BA538	addiu  t3, t3, $000c
800BA53C	lw     v1, $0008(a0)
800BA540	nop
800BA544	lbu    v0, $0003(v1)
800BA548	addiu  t1, t1, $0001
800BA54C	sltu   v0, t1, v0
800BA550	bne    v0, zero, loopba408 [$800ba408]
800BA554	addiu  t2, t2, $0028

Lba558:	; 800BA558
800BA558	jr     ra 
800BA55C	nop


funcba560:	; 800BA560
800BA560	addiu  sp, sp, $ff38 (=-$c8)
800BA564	sw     s3, $00ac(sp)
800BA568	addu   s3, a0, zero

Lba56c:	; 800BA56C
800BA56C	sw     ra, $00c4(sp)
800BA570	sw     fp, $00c0(sp)
800BA574	sw     s7, $00bc(sp)
800BA578	sw     s6, $00b8(sp)
800BA57C	sw     s5, $00b4(sp)
800BA580	sw     s4, $00b0(sp)
800BA584	sw     s2, $00a8(sp)
800BA588	sw     s1, $00a4(sp)
800BA58C	sw     s0, $00a0(sp)
800BA590	lw     s0, $000c(s3)
800BA594	nop
800BA598	bne    s0, zero, Lba760 [$800ba760]
800BA59C	addu   s5, a1, zero
800BA5A0	lw     v1, $001c(s3)
800BA5A4	nop
800BA5A8	beq    v1, zero, Lba6a0 [$800ba6a0]
800BA5AC	nop
800BA5B0	lbu    v0, $0004(s3)
800BA5B4	lw     v1, $0020(v1)
800BA5B8	sll    v0, v0, $05
800BA5BC	addu   v0, v0, v1
800BA5C0	lw     v1, $0000(v0)
800BA5C4	lw     a0, $0004(v0)
800BA5C8	lw     a1, $0008(v0)
800BA5CC	lw     a2, $000c(v0)
800BA5D0	lw     v0, $0020(s3)
800BA5D4	nop
800BA5D8	sw     v1, $0000(v0)
800BA5DC	lw     v0, $0020(s3)
800BA5E0	nop
800BA5E4	sw     a0, $0004(v0)
800BA5E8	lw     v0, $0020(s3)
800BA5EC	nop
800BA5F0	sw     a1, $0008(v0)
800BA5F4	lw     v0, $0020(s3)
800BA5F8	nop
800BA5FC	sw     a2, $000c(v0)
800BA600	lw     v1, $001c(s3)
800BA604	lbu    v0, $0004(s3)
800BA608	lw     v1, $0020(v1)
800BA60C	sll    v0, v0, $05
800BA610	addu   v0, v0, v1
800BA614	lw     v1, $0010(v0)
800BA618	lw     a0, $0014(v0)
800BA61C	lw     a1, $0018(v0)
800BA620	lw     a2, $001c(v0)
800BA624	lw     v0, $0020(s3)
800BA628	nop
800BA62C	sw     v1, $0010(v0)
800BA630	lw     v0, $0020(s3)
800BA634	nop
800BA638	sw     a0, $0014(v0)
800BA63C	lw     v0, $0020(s3)
800BA640	nop
800BA644	sw     a1, $0018(v0)
800BA648	lw     v0, $0020(s3)
800BA64C	nop
800BA650	sw     a2, $001c(v0)
800BA654	lw     a0, $0020(s3)
800BA658	lh     v1, $0074(s3)
800BA65C	lw     v0, $0014(a0)

funcba660:	; 800BA660
800BA660	nop
800BA664	addu   v0, v0, v1
800BA668	sw     v0, $0014(a0)
800BA66C	lw     a0, $0020(s3)
800BA670	lh     v1, $0076(s3)
800BA674	lw     v0, $0018(a0)
800BA678	nop
800BA67C	addu   v0, v0, v1
800BA680	sw     v0, $0018(a0)
800BA684	lw     a0, $0020(s3)
800BA688	lh     v1, $0078(s3)
800BA68C	lw     v0, $001c(a0)
800BA690	nop
800BA694	addu   v0, v0, v1
800BA698	j      Lbb060 [$800bb060]
800BA69C	sw     v0, $001c(a0)

Lba6a0:	; 800BA6A0
800BA6A0	lw     v1, $0020(s3)

funcba6a4:	; 800BA6A4
800BA6A4	lhu    v0, $0024(s3)
800BA6A8	nop
800BA6AC	sh     v0, $0000(v1)
800BA6B0	lhu    v0, $0026(s3)
800BA6B4	lw     v1, $0020(s3)
800BA6B8	subu   v0, zero, v0
800BA6BC	sh     v0, $0002(v1)
800BA6C0	lhu    v0, $0028(s3)
800BA6C4	lw     v1, $0020(s3)
800BA6C8	subu   v0, zero, v0
800BA6CC	sh     v0, $0004(v1)
800BA6D0	lw     v1, $0020(s3)
800BA6D4	lhu    v0, $002a(s3)
800BA6D8	nop
800BA6DC	sh     v0, $0006(v1)
800BA6E0	lhu    v0, $002c(s3)
800BA6E4	lw     v1, $0020(s3)
800BA6E8	subu   v0, zero, v0
800BA6EC	sh     v0, $0008(v1)
800BA6F0	lhu    v0, $002e(s3)
800BA6F4	lw     v1, $0020(s3)
800BA6F8	subu   v0, zero, v0
800BA6FC	sh     v0, $000a(v1)
800BA700	lw     v1, $0020(s3)
800BA704	lhu    v0, $0030(s3)
800BA708	nop
800BA70C	sh     v0, $000c(v1)
800BA710	lhu    v0, $0032(s3)
800BA714	lw     v1, $0020(s3)
800BA718	subu   v0, zero, v0
800BA71C	sh     v0, $000e(v1)
800BA720	lhu    v0, $0034(s3)
800BA724	lw     v1, $0020(s3)
800BA728	subu   v0, zero, v0
800BA72C	sh     v0, $0010(v1)
800BA730	lw     v1, $0020(s3)
800BA734	lw     v0, $0038(s3)
800BA738	nop
800BA73C	sw     v0, $0014(v1)
800BA740	lw     v1, $0020(s3)
800BA744	lw     v0, $003c(s3)
800BA748	nop
800BA74C	sw     v0, $0018(v1)
800BA750	lw     v1, $0020(s3)
800BA754	lw     v0, $0040(s3)
800BA758	j      Lbb060 [$800bb060]
800BA75C	sw     v0, $001c(v1)

Lba760:	; 800BA760
800BA760	lw     v0, $0008(s3)
800BA764	lui    s2, $1f80
800BA768	lbu    v0, $0002(v0)
800BA76C	nop
800BA770	sh     v0, $0090(sp)
800BA774	sltiu  v0, v0, $001f
800BA778	bne    v0, zero, Lba784 [$800ba784]
800BA77C	ori    s2, s2, $0018
800BA780	lw     s2, $0020(s3)

Lba784:	; 800BA784
800BA784	nop
800BA788	addu   s1, s2, zero
800BA78C	lui    t7, $1f80
800BA790	ori    t7, t7, $0008
800BA794	sw     t7, $0098(sp)
800BA798	sw     zero, $0000(t7)
800BA79C	sw     zero, $0004(t7)
800BA7A0	lw     s6, $000c(s0)
800BA7A4	lhu    v0, $000a(s0)
800BA7A8	lw     s4, $0010(s0)
800BA7AC	andi   v0, v0, $0001
800BA7B0	beq    v0, zero, Lba7c4 [$800ba7c4]
800BA7B4	lui    s7, $1f80
800BA7B8	lh     v0, $0004(s0)

Lba7bc:	; 800BA7BC
800BA7BC	j      Lba7e4 [$800ba7e4]
800BA7C0	sw     v0, $0014(s2)

Lba7c4:	; 800BA7C4
800BA7C4	andi   v0, s5, $ffff
800BA7C8	lhu    v1, $0004(s0)
800BA7CC	sll    v0, v0, $01

funcba7d0:	; 800BA7D0
800BA7D0	addu   v1, s0, v1
800BA7D4	addu   v0, v0, v1
800BA7D8	lh     v0, $0000(v0)
800BA7DC	nop
800BA7E0	sw     v0, $0014(s2)

Lba7e4:	; 800BA7E4
800BA7E4	lhu    v0, $000a(s0)
800BA7E8	nop
800BA7EC	andi   v0, v0, $0002
800BA7F0	beq    v0, zero, Lba804 [$800ba804]
800BA7F4	andi   v0, s5, $ffff
800BA7F8	lh     v0, $0006(s0)
800BA7FC	j      Lba820 [$800ba820]
800BA800	sw     v0, $0018(s1)

Lba804:	; 800BA804
800BA804	lhu    v1, $0006(s0)
800BA808	sll    v0, v0, $01
800BA80C	addu   v1, s0, v1
800BA810	addu   v0, v0, v1
800BA814	lh     v0, $0000(v0)
800BA818	nop
800BA81C	sw     v0, $0018(s1)

Lba820:	; 800BA820
800BA820	lhu    v0, $000a(s0)
800BA824	nop
800BA828	andi   v0, v0, $0004
800BA82C	beq    v0, zero, Lba840 [$800ba840]
800BA830	andi   v0, s5, $ffff
800BA834	lh     v0, $0008(s0)
800BA838	j      Lba85c [$800ba85c]
800BA83C	sw     v0, $001c(s1)

Lba840:	; 800BA840
800BA840	lhu    v1, $0008(s0)
800BA844	sll    v0, v0, $01

Lba848:	; 800BA848
800BA848	addu   v1, s0, v1
800BA84C	addu   v0, v0, v1
800BA850	lh     v0, $0000(v0)
800BA854	nop

funcba858:	; 800BA858
800BA858	sw     v0, $001c(s1)

Lba85c:	; 800BA85C
800BA85C	lhu    t8, $0090(sp)
800BA860	nop
800BA864	sll    v0, t8, $05
800BA868	addu   v0, s2, v0
800BA86C	sw     v0, $0088(sp)

loopba870:	; 800BA870
800BA870	lw     t3, $0004(s6)
800BA874	lw     t2, $0000(s6)
800BA878	srl    t4, t3, $10
800BA87C	andi   t5, t4, $0001
800BA880	bne    t5, zero, Lba894 [$800ba894]
800BA884	andi   t1, t2, $ffff
800BA888	addu   t1, t1, s0
800BA88C	addu   t1, t1, s5
800BA890	lb     t1, $0000(t1)

Lba894:	; 800BA894
800BA894	andi   t5, t4, $0002
800BA898	sll    t1, t1, $04
800BA89C	bne    t5, zero, Lba8b0 [$800ba8b0]
800BA8A0	srl    t2, t2, $10
800BA8A4	addu   t2, t2, s0
800BA8A8	addu   t2, t2, s5
800BA8AC	lb     t2, $0000(t2)

Lba8b0:	; 800BA8B0
800BA8B0	andi   t5, t4, $0004
800BA8B4	sll    t2, t2, $14
800BA8B8	bne    t5, zero, Lba8cc [$800ba8cc]
800BA8BC	andi   t3, t3, $ffff
800BA8C0	addu   t3, t3, s0
800BA8C4	addu   t3, t3, s5
800BA8C8	lb     t3, $0000(t3)

Lba8cc:	; 800BA8CC
800BA8CC	andi   t1, t1, $ffff
800BA8D0	or     t5, t2, t1
800BA8D4	sll    t3, t3, $04
800BA8D8	sw     t5, $0000(s7)
800BA8DC	sw     t3, $0004(s7)
800BA8E0	beq    s4, zero, Lba99c [$800ba99c]
800BA8E4	nop
800BA8E8	srl    t0, s5, $01
800BA8EC	andi   t6, s5, $0001

funcba8f0:	; 800BA8F0
800BA8F0	lw     t3, $0004(s4)
800BA8F4	lw     t2, $0000(s4)
800BA8F8	srl    t4, t3, $10
800BA8FC	andi   t5, t4, $0001
800BA900	bne    t5, zero, Lba920 [$800ba920]
800BA904	andi   t1, t2, $ffff
800BA908	addu   t1, t1, s0
800BA90C	addu   t1, t1, t0
800BA910	lb     t1, $0000(t1)
800BA914	beq    t6, zero, Lba920 [$800ba920]
800BA918	nop
800BA91C	srl    t1, t1, $04

Lba920:	; 800BA920
800BA920	andi   t5, t4, $0002
800BA924	andi   t1, t1, $000f
800BA928	bne    t5, zero, Lba948 [$800ba948]
800BA92C	srl    t2, t2, $10
800BA930	addu   t2, t2, s0
800BA934	addu   t2, t2, t0

funcba938:	; 800BA938
800BA938	lb     t2, $0000(t2)
800BA93C	beq    t6, zero, Lba948 [$800ba948]
800BA940	nop
800BA944	srl    t2, t2, $04

Lba948:	; 800BA948
800BA948	andi   t5, t4, $0004
800BA94C	andi   t2, t2, $000f
800BA950	bne    t5, zero, Lba970 [$800ba970]
800BA954	andi   t3, t3, $ffff
800BA958	addu   t3, t3, s0
800BA95C	addu   t3, t3, t0
800BA960	lb     t3, $0000(t3)
800BA964	beq    t6, zero, Lba970 [$800ba970]
800BA968	nop
800BA96C	srl    t3, t3, $04

Lba970:	; 800BA970
800BA970	andi   t5, t4, $0004
800BA974	andi   t3, t3, $000f
800BA978	lw     t4, $0000(s7)
800BA97C	lw     t5, $0004(s7)
800BA980	or     t4, t4, t1
800BA984	sll    t2, t2, $10
800BA988	or     t4, t4, t2
800BA98C	or     t5, t5, t3
800BA990	sw     t4, $0000(s7)

funcba994:	; 800BA994
800BA994	sw     t5, $0004(s7)
800BA998	addiu  s4, s4, $0008

Lba99c:	; 800BA99C
800BA99C	addiu  s6, s6, $0008
800BA9A0	addu   a0, s7, zero
800BA9A4	jal    system_create_matrix_from_angle_with_gte [$80031264]
800BA9A8	addu   a1, s1, zero
800BA9AC	lw     t7, $0088(sp)
800BA9B0	addiu  s1, s1, $0020
800BA9B4	sltu   v0, s1, t7
800BA9B8	bne    v0, zero, loopba870 [$800ba870]
800BA9BC	nop
800BA9C0	lw     v1, $001c(s3)
800BA9C4	nop
800BA9C8	beq    v1, zero, Lbaa6c [$800baa6c]
800BA9CC	addiu  v0, s3, $0024
800BA9D0	lbu    v0, $0004(s3)
800BA9D4	lw     v1, $0020(v1)
800BA9D8	sll    v0, v0, $05
800BA9DC	addu   v0, v0, v1
800BA9E0	lw     v1, $0000(v0)
800BA9E4	lw     a0, $0004(v0)
800BA9E8	lw     a1, $0008(v0)
800BA9EC	lw     v0, $000c(v0)
800BA9F0	sw     v1, $0000(s2)
800BA9F4	sw     a0, $0004(s2)
800BA9F8	sw     a1, $0008(s2)
800BA9FC	sw     v0, $000c(s2)
800BAA00	lw     v1, $001c(s3)
800BAA04	lbu    v0, $0004(s3)
800BAA08	lw     v1, $0020(v1)
800BAA0C	sll    v0, v0, $05
800BAA10	addu   v0, v0, v1
800BAA14	lw     v1, $0010(v0)
800BAA18	lw     a0, $0014(v0)
800BAA1C	lw     a1, $0018(v0)
800BAA20	lw     v0, $001c(v0)
800BAA24	sw     v1, $0010(s2)

funcbaa28:	; 800BAA28
800BAA28	sw     a0, $0014(s2)
800BAA2C	sw     a1, $0018(s2)
800BAA30	sw     v0, $001c(s2)
800BAA34	lh     v1, $0074(s3)
800BAA38	addu   v0, a0, zero
800BAA3C	addu   v0, v0, v1
800BAA40	sw     v0, $0014(s2)
800BAA44	lh     v1, $0076(s3)
800BAA48	addu   v0, a1, zero
800BAA4C	addu   v0, v0, v1
800BAA50	sw     v0, $0018(s2)
800BAA54	lh     v1, $0078(s3)
800BAA58	lw     v0, $001c(s2)
800BAA5C	nop
800BAA60	addu   v0, v0, v1
800BAA64	j      Lbab90 [$800bab90]
800BAA68	sw     v0, $001c(s2)

Lbaa6c:	; 800BAA6C
800BAA6C	lw     t4, $0000(v0)
800BAA70	lw     t5, $0004(v0)
800BAA74	ctc2   t4,vxy0
800BAA78	ctc2   t5,vz0
800BAA7C	lw     t4, $0008(v0)
800BAA80	lw     t5, $000c(v0)
800BAA84	lw     t6, $0010(v0)
800BAA88	ctc2   t4,vxy1
800BAA8C	ctc2   t5,vz1
800BAA90	ctc2   t6,vxy2
800BAA94	lw     t4, $0014(v0)
800BAA98	lw     t5, $0018(v0)
800BAA9C	ctc2   t4,vz2
800BAAA0	lw     t6, $001c(v0)
800BAAA4	ctc2   t5,rgb
800BAAA8	ctc2   t6,otz
800BAAAC	lhu    t4, $0000(s2)
800BAAB0	lhu    t5, $0006(s2)
800BAAB4	lhu    t6, $000c(s2)
800BAAB8	mtc2   t4,l13l21
800BAABC	mtc2   t5,l22l23
800BAAC0	mtc2   t6,l31l32
800BAAC4	addiu  v1, s2, $0002
800BAAC8	addiu  v0, s2, $0004
800BAACC	gte_func18t1,dqb
800BAAD0	mfc2   t4,l13l21
800BAAD4	mfc2   t5,l22l23
800BAAD8	mfc2   t6,l31l32
800BAADC	sh     t4, $0000(s2)
800BAAE0	sh     t5, $0006(s2)

funcbaae4:	; 800BAAE4
800BAAE4	sh     t6, $000c(s2)
800BAAE8	lhu    t4, $0000(v1)
800BAAEC	lhu    t5, $0006(v1)
800BAAF0	lhu    t6, $000c(v1)
800BAAF4	mtc2   t4,l13l21
800BAAF8	mtc2   t5,l22l23
800BAAFC	mtc2   t6,l31l32
800BAB00	nop
800BAB04	nop
800BAB08	gte_func18t1,dqb
800BAB0C	mfc2   t4,l13l21
800BAB10	mfc2   t5,l22l23
800BAB14	mfc2   t6,l31l32
800BAB18	sh     t4, $0000(v1)
800BAB1C	sh     t5, $0006(v1)
800BAB20	sh     t6, $000c(v1)
800BAB24	lhu    t4, $0000(v0)
800BAB28	lhu    t5, $0006(v0)
800BAB2C	lhu    t6, $000c(v0)
800BAB30	mtc2   t4,l13l21
800BAB34	mtc2   t5,l22l23
800BAB38	mtc2   t6,l31l32
800BAB3C	addiu  v1, s2, $0014
800BAB40	nop
800BAB44	gte_func18t1,dqb
800BAB48	mfc2   t4,l13l21
800BAB4C	mfc2   t5,l22l23
800BAB50	mfc2   t6,l31l32
800BAB54	sh     t4, $0000(v0)
800BAB58	sh     t5, $0006(v0)
800BAB5C	sh     t6, $000c(v0)
800BAB60	lhu    t5, $0004(v1)
800BAB64	lhu    t4, $0000(v1)
800BAB68	sll    t5, t5, $10
800BAB6C	or     t4, t4, t5
800BAB70	mtc2   t4,r11r12
800BAB74	lwc2   at, $0008(v1)
800BAB78	nop
800BAB7C	nop
800BAB80	gte_func18t0,r11r12
800BAB84	swc2   t9, $0000(v1)
800BAB88	swc2   k0, $0004(v1)
800BAB8C	swc2   k1, $0008(v1)

Lbab90:	; 800BAB90
800BAB90	addiu  s1, s2, $0020
800BAB94	addiu  t8, zero, $0001
800BAB98	sw     t8, $0080(sp)
800BAB9C	lw     v1, $0008(s3)
800BABA0	addiu  t7, sp, $0040
800BABA4	sw     t7, $009c(sp)
800BABA8	lw     v0, $000c(v1)

funcbabac:	; 800BABAC
800BABAC	lbu    v1, $0006(v1)
800BABB0	addiu  s4, v0, $0004
800BABB4	lbu    v0, $0003(s4)
800BABB8	addiu  s7, sp, $0010
800BABBC	sw     v1, $0084(sp)
800BABC0	sll    v0, v0, $05
800BABC4	addu   fp, s2, v0

Lbabc8:	; 800BABC8
800BABC8	lw     t4, $0000(fp)
800BABCC	lw     t5, $0004(fp)
800BABD0	ctc2   t4,vxy0
800BABD4	ctc2   t5,vz0
800BABD8	lw     t4, $0008(fp)
800BABDC	lw     t5, $000c(fp)
800BABE0	lw     t6, $0010(fp)
800BABE4	ctc2   t4,vxy1
800BABE8	ctc2   t5,vz1
800BABEC	ctc2   t6,vxy2
800BABF0	lhu    t4, $0000(s1)
800BABF4	lhu    t5, $0006(s1)
800BABF8	lhu    t6, $000c(s1)
800BABFC	mtc2   t4,l13l21
800BAC00	mtc2   t5,l22l23
800BAC04	mtc2   t6,l31l32
800BAC08	nop
800BAC0C	nop
800BAC10	gte_func18t1,dqb
800BAC14	lw     t4, $0014(fp)
800BAC18	lw     t5, $0018(fp)
800BAC1C	ctc2   t4,vz2
800BAC20	lw     t6, $001c(fp)
800BAC24	ctc2   t5,rgb
800BAC28	ctc2   t6,otz
800BAC2C	mfc2   t4,l13l21
800BAC30	mfc2   t5,l22l23
800BAC34	mfc2   t6,l31l32
800BAC38	sh     t4, $0000(s1)
800BAC3C	sh     t5, $0006(s1)
800BAC40	sh     t6, $000c(s1)
800BAC44	addiu  s6, s1, $0002
800BAC48	lhu    t4, $0000(s6)
800BAC4C	lhu    t5, $0006(s6)
800BAC50	lhu    t6, $000c(s6)
800BAC54	mtc2   t4,l13l21
800BAC58	mtc2   t5,l22l23
800BAC5C	mtc2   t6,l31l32
800BAC60	nop
800BAC64	nop
800BAC68	gte_func18t1,dqb
800BAC6C	lh     v0, $0000(s4)
800BAC70	lw     t8, $0098(sp)
800BAC74	nop
800BAC78	sw     v0, $0008(t8)
800BAC7C	mfc2   t4,l13l21
800BAC80	mfc2   t5,l22l23
800BAC84	mfc2   t6,l31l32
800BAC88	sh     t4, $0000(s6)
800BAC8C	sh     t5, $0006(s6)
800BAC90	sh     t6, $000c(s6)
800BAC94	addiu  s5, s1, $0004
800BAC98	lhu    t4, $0000(s5)
800BAC9C	lhu    t5, $0006(s5)
800BACA0	lhu    t6, $000c(s5)
800BACA4	mtc2   t4,l13l21
800BACA8	mtc2   t5,l22l23
800BACAC	mtc2   t6,l31l32
800BACB0	nop

funcbacb4:	; 800BACB4
800BACB4	nop
800BACB8	gte_func18t1,dqb
800BACBC	addiu  s4, s4, $0004
800BACC0	mfc2   t4,l13l21
800BACC4	mfc2   t5,l22l23
800BACC8	mfc2   t6,l31l32
800BACCC	sh     t4, $0000(s5)
800BACD0	sh     t5, $0006(s5)
800BACD4	sh     t6, $000c(s5)
800BACD8	lhu    t5, $0004(t8)
800BACDC	lhu    t4, $0000(t8)
800BACE0	sll    t5, t5, $10
800BACE4	or     t4, t4, t5
800BACE8	mtc2   t4,r11r12
800BACEC	lwc2   at, $0008(t8)
800BACF0	nop
800BACF4	nop
800BACF8	gte_func18t0,r11r12
800BACFC	lbu    v0, $0003(s4)
800BAD00	nop
800BAD04	sll    v0, v0, $05
800BAD08	addu   fp, s2, v0
800BAD0C	addiu  v0, s1, $0014
800BAD10	swc2   t9, $0000(v0)
800BAD14	swc2   k0, $0004(v0)
800BAD18	swc2   k1, $0008(v0)
800BAD1C	lw     t7, $0084(sp)
800BAD20	lw     t8, $0080(sp)
800BAD24	nop
800BAD28	bne    t7, t8, Lbafc4 [$800bafc4]
800BAD2C	addiu  t7, zero, $1000
800BAD30	sw     zero, $0020(sp)
800BAD34	sw     t7, $0024(sp)
800BAD38	sw     zero, $0028(sp)
800BAD3C	lh     v1, $0048(s3)

Lbad40:	; 800BAD40
800BAD40	lw     v0, $0014(s1)
800BAD44	nop
800BAD48	subu   v0, v0, v1
800BAD4C	sw     v0, $0010(sp)

Lbad50:	; 800BAD50
800BAD50	lh     v1, $004a(s3)
800BAD54	lw     v0, $0018(s1)
800BAD58	addiu  a0, sp, $0010
800BAD5C	subu   v0, v0, v1
800BAD60	sw     v0, $0014(sp)

funcbad64:	; 800BAD64
800BAD64	lh     v1, $004c(s3)
800BAD68	lw     v0, $001c(s1)
800BAD6C	lw     a1, $009c(sp)
800BAD70	subu   v0, v0, v1
800BAD74	jal    func62c2c [$80062c2c]
800BAD78	sw     v0, $0018(sp)
800BAD7C	addiu  v0, sp, $0020
800BAD80	lw     t4, $0000(v0)
800BAD84	lw     t5, $0004(v0)
800BAD88	ctc2   t4,vxy0
800BAD8C	lw     t6, $0008(v0)
800BAD90	ctc2   t5,vxy1
800BAD94	ctc2   t6,vxy2
800BAD98	lw     t8, $009c(sp)
800BAD9C	nop
800BADA0	lwc2   t3, $0008(t8)
800BADA4	lwc2   t1, $0000(t8)
800BADA8	lwc2   t2, $0004(t8)
800BADAC	nop
800BADB0	nop
800BADB4	gte_func27t8,r11r12
800BADB8	swc2   t9, $0000(s7)
800BADBC	swc2   k0, $0004(s7)
800BADC0	swc2   k1, $0008(s7)
800BADC4	addu   a0, s7, zero
800BADC8	addiu  s0, sp, $0030
800BADCC	jal    func62c2c [$80062c2c]
800BADD0	addu   a1, s0, zero

funcbadd4:	; 800BADD4
800BADD4	lw     t4, $0000(s0)
800BADD8	lw     t5, $0004(s0)
800BADDC	ctc2   t4,vxy0
800BADE0	lw     t6, $0008(s0)
800BADE4	ctc2   t5,vxy1
800BADE8	ctc2   t6,vxy2
800BADEC	lw     t7, $009c(sp)
800BADF0	nop
800BADF4	lwc2   t3, $0008(t7)
800BADF8	lwc2   t1, $0000(t7)
800BADFC	lwc2   t2, $0004(t7)
800BAE00	nop
800BAE04	nop
800BAE08	gte_func27t8,r11r12
800BAE0C	swc2   t9, $0000(s7)

Lbae10:	; 800BAE10
800BAE10	swc2   k0, $0004(s7)
800BAE14	swc2   k1, $0008(s7)
800BAE18	addu   a0, s7, zero
800BAE1C	jal    func62c2c [$80062c2c]
800BAE20	addiu  a1, sp, $0050
800BAE24	lhu    v0, $0030(sp)
800BAE28	nop
800BAE2C	sh     v0, $0000(s1)
800BAE30	lhu    v0, $0040(sp)
800BAE34	nop
800BAE38	sh     v0, $0002(s1)
800BAE3C	lhu    v0, $0050(sp)
800BAE40	nop

funcbae44:	; 800BAE44
800BAE44	sh     v0, $0004(s1)
800BAE48	lhu    v0, $0034(sp)
800BAE4C	nop
800BAE50	sh     v0, $0006(s1)
800BAE54	lhu    v0, $0044(sp)
800BAE58	nop
800BAE5C	sh     v0, $0008(s1)
800BAE60	lhu    v0, $0054(sp)
800BAE64	nop
800BAE68	sh     v0, $000a(s1)
800BAE6C	lhu    v0, $0038(sp)
800BAE70	nop
800BAE74	sh     v0, $000c(s1)
800BAE78	lhu    v0, $0048(sp)
800BAE7C	nop
800BAE80	sh     v0, $000e(s1)
800BAE84	lhu    v0, $0058(sp)
800BAE88	nop
800BAE8C	sh     v0, $0010(s1)
800BAE90	lhu    v0, $0000(s3)

Lbae94:	; 800BAE94
800BAE94	nop
800BAE98	andi   v0, v0, $0002
800BAE9C	beq    v0, zero, Lbafc4 [$800bafc4]
800BAEA0	addiu  t8, zero, $1000
800BAEA4	lhu    v0, $0054(s3)

Lbaea8:	; 800BAEA8
800BAEA8	addu   t7, t8, zero
800BAEAC	sw     t8, $0060(sp)
800BAEB0	sw     zero, $0064(sp)
800BAEB4	sw     t7, $0068(sp)
800BAEB8	sw     zero, $006c(sp)
800BAEBC	sw     t8, $0070(sp)
800BAEC0	sh     v0, $0060(sp)
800BAEC4	lw     t4, $0000(s1)
800BAEC8	lw     t5, $0004(s1)
800BAECC	ctc2   t4,vxy0

Lbaed0:	; 800BAED0
800BAED0	ctc2   t5,vz0
800BAED4	lw     t4, $0008(s1)
800BAED8	lw     t5, $000c(s1)
800BAEDC	lw     t6, $0010(s1)
800BAEE0	ctc2   t4,vxy1
800BAEE4	ctc2   t5,vz1
800BAEE8	ctc2   t6,vxy2
800BAEEC	addiu  v0, sp, $0060
800BAEF0	lhu    t4, $0000(v0)
800BAEF4	lhu    t5, $0006(v0)
800BAEF8	lhu    t6, $000c(v0)
800BAEFC	mtc2   t4,l13l21
800BAF00	mtc2   t5,l22l23
800BAF04	mtc2   t6,l31l32
800BAF08	nop
800BAF0C	nop
800BAF10	gte_func18t1,dqb
800BAF14	lhu    v0, $0056(s3)
800BAF18	nop
800BAF1C	sh     v0, $0068(sp)
800BAF20	mfc2   t4,l13l21
800BAF24	mfc2   t5,l22l23
800BAF28	mfc2   t6,l31l32
800BAF2C	sh     t4, $0000(s1)
800BAF30	sh     t5, $0006(s1)
800BAF34	sh     t6, $000c(s1)
800BAF38	addiu  v0, sp, $0062

funcbaf3c:	; 800BAF3C
800BAF3C	lhu    t4, $0000(v0)
800BAF40	lhu    t5, $0006(v0)
800BAF44	lhu    t6, $000c(v0)
800BAF48	mtc2   t4,l13l21
800BAF4C	mtc2   t5,l22l23
800BAF50	mtc2   t6,l31l32
800BAF54	nop
800BAF58	nop
800BAF5C	gte_func18t1,dqb
800BAF60	lhu    v0, $0058(s3)
800BAF64	nop
800BAF68	sh     v0, $0070(sp)
800BAF6C	mfc2   t4,l13l21

Lbaf70:	; 800BAF70
800BAF70	mfc2   t5,l22l23
800BAF74	mfc2   t6,l31l32
800BAF78	sh     t4, $0000(s6)
800BAF7C	sh     t5, $0006(s6)
800BAF80	sh     t6, $000c(s6)
800BAF84	addiu  v0, sp, $0064
800BAF88	lhu    t4, $0000(v0)
800BAF8C	lhu    t5, $0006(v0)
800BAF90	lhu    t6, $000c(v0)
800BAF94	mtc2   t4,l13l21
800BAF98	mtc2   t5,l22l23
800BAF9C	mtc2   t6,l31l32
800BAFA0	nop
800BAFA4	nop
800BAFA8	gte_func18t1,dqb
800BAFAC	mfc2   t4,l13l21
800BAFB0	mfc2   t5,l22l23
800BAFB4	mfc2   t6,l31l32
800BAFB8	sh     t4, $0000(s5)
800BAFBC	sh     t5, $0006(s5)
800BAFC0	sh     t6, $000c(s5)

Lbafc4:	; 800BAFC4
800BAFC4	addiu  s1, s1, $0020
800BAFC8	lw     t7, $0080(sp)
800BAFCC	lw     t8, $0088(sp)
800BAFD0	addiu  t7, t7, $0001
800BAFD4	sltu   v0, s1, t8

Lbafd8:	; 800BAFD8
800BAFD8	bne    v0, zero, Lbabc8 [$800babc8]
800BAFDC	sw     t7, $0080(sp)
800BAFE0	lhu    t7, $0090(sp)
800BAFE4	nop
800BAFE8	sltiu  v0, t7, $001f

funcbafec:	; 800BAFEC
800BAFEC	beq    v0, zero, Lbb060 [$800bb060]
800BAFF0	nop
800BAFF4	lw     s1, $0020(s3)
800BAFF8	addiu  a0, s2, $001c
800BAFFC	addiu  v1, s1, $001c

loopbb000:	; 800BB000
800BB000	lw     v0, $0000(s2)
800BB004	lw     a1, $ffe8(a0)
800BB008	lw     a2, $ffec(a0)
800BB00C	lw     a3, $fff0(a0)
800BB010	addiu  s2, s2, $0020
800BB014	sw     v0, $0000(s1)
800BB018	addiu  s1, s1, $0020
800BB01C	sw     a1, $ffe8(v1)
800BB020	sw     a2, $ffec(v1)

Lbb024:	; 800BB024
800BB024	sw     a3, $fff0(v1)
800BB028	lw     v0, $fff4(a0)
800BB02C	lw     a1, $fff8(a0)
800BB030	lw     a2, $fffc(a0)
800BB034	lw     a3, $0000(a0)
800BB038	addiu  a0, a0, $0020
800BB03C	sw     v0, $fff4(v1)
800BB040	sw     a1, $fff8(v1)
800BB044	sw     a2, $fffc(v1)
800BB048	sw     a3, $0000(v1)
800BB04C	lw     t8, $0088(sp)
800BB050	nop
800BB054	sltu   v0, s2, t8
800BB058	bne    v0, zero, loopbb000 [$800bb000]
800BB05C	addiu  v1, v1, $0020

Lbb060:	; 800BB060
800BB060	lw     ra, $00c4(sp)
800BB064	lw     fp, $00c0(sp)
800BB068	lw     s7, $00bc(sp)
800BB06C	lw     s6, $00b8(sp)
800BB070	lw     s5, $00b4(sp)
800BB074	lw     s4, $00b0(sp)
800BB078	lw     s3, $00ac(sp)
800BB07C	lw     s2, $00a8(sp)
800BB080	lw     s1, $00a4(sp)
800BB084	lw     s0, $00a0(sp)
800BB088	jr     ra 
800BB08C	addiu  sp, sp, $00c8


funcbb090:	; 800BB090
800BB090	addiu  sp, sp, $ffc0 (=-$40)
800BB094	sw     ra, $003c(sp)
800BB098	sw     fp, $0038(sp)
800BB09C	sw     s7, $0034(sp)
800BB0A0	sw     s6, $0030(sp)
800BB0A4	sw     s5, $002c(sp)
800BB0A8	sw     s4, $0028(sp)
800BB0AC	sw     s3, $0024(sp)
800BB0B0	sw     s2, $0020(sp)
800BB0B4	sw     s1, $001c(sp)
800BB0B8	sw     s0, $0018(sp)
800BB0BC	beq    a0, zero, Lbb394 [$800bb394]
800BB0C0	sw     a0, $0040(sp)
800BB0C4	lhu    v0, $0000(a0)
800BB0C8	nop
800BB0CC	beq    v0, zero, Lbb394 [$800bb394]
800BB0D0	addu   s7, zero, zero
800BB0D4	lui    fp, $8008
800BB0D8	sll    v0, s7, $02

Lbb0dc:	; 800BB0DC
800BB0DC	addu   v0, v0, s7
800BB0E0	sll    v0, v0, $02
800BB0E4	lw     a3, $0040(sp)
800BB0E8	addiu  v0, v0, $0004
800BB0EC	addu   s1, a3, v0
800BB0F0	lbu    v1, $0000(s1)
800BB0F4	nop
800BB0F8	andi   v0, v1, $0001
800BB0FC	beq    v0, zero, Lbb37c [$800bb37c]
800BB100	nop
800BB104	lbu    v0, $0001(s1)
800BB108	nop
800BB10C	beq    v0, zero, Lbb2c4 [$800bb2c4]
800BB110	andi   v0, v1, $0004

Lbb114:	; 800BB114
800BB114	lw     s4, $0008(s1)
800BB118	nop
800BB11C	sra    v0, s4, $0c
800BB120	addu   s6, v0, zero
800BB124	sll    v0, v0, $10
800BB128	sra    v1, v0, $10
800BB12C	lhu    v0, $000e(s1)
800BB130	bltz   v1, Lbb1e4 [$800bb1e4]
800BB134	sll    v0, v0, $10
800BB138	sra    v0, v0, $10
800BB13C	beq    v1, v0, Lbb1d8 [$800bb1d8]
800BB140	nop
800BB144	lbu    v0, $000c(s1)
800BB148	nop
800BB14C	beq    v0, zero, Lbb1d4 [$800bb1d4]
800BB150	addu   s2, zero, zero
800BB154	sll    s5, v1, $02
800BB158	addu   s3, s2, zero

loopbb15c:	; 800BB15C
800BB15C	lw     v0, $0010(s1)
800BB160	nop
800BB164	addu   s0, v0, s3
800BB168	lw     v0, $0008(s0)
800BB16C	nop
800BB170	addu   v0, s5, v0
800BB174	lhu    v0, $0000(v0)
800BB178	nop
800BB17C	sh     v0, $0010(sp)
800BB180	lw     v0, $0008(s0)
800BB184	nop
800BB188	addu   v0, s5, v0
800BB18C	lhu    v0, $0002(v0)
800BB190	nop
800BB194	sh     v0, $0012(sp)
800BB198	lhu    v0, $0004(s0)
800BB19C	nop
800BB1A0	sh     v0, $0014(sp)
800BB1A4	lhu    v0, $0006(s0)
800BB1A8	addiu  a0, sp, $0010
800BB1AC	sh     v0, $0016(sp)
800BB1B0	lh     a1, $0000(s0)
800BB1B4	lh     a2, $0002(s0)
800BB1B8	jal    func13410 [$80013410]
800BB1BC	addiu  s2, s2, $0001
800BB1C0	lbu    v0, $000c(s1)
800BB1C4	nop
800BB1C8	sltu   v0, s2, v0
800BB1CC	bne    v0, zero, loopbb15c [$800bb15c]
800BB1D0	addiu  s3, s3, $000c

Lbb1d4:	; 800BB1D4
800BB1D4	sh     s6, $000e(s1)

Lbb1d8:	; 800BB1D8
800BB1D8	lh     v0, $0002(s1)
800BB1DC	j      Lbb1e8 [$800bb1e8]
800BB1E0	addu   s4, s4, v0

Lbb1e4:	; 800BB1E4
800BB1E4	addiu  s4, s4, $1000

Lbb1e8:	; 800BB1E8
800BB1E8	lbu    v1, $0001(s1)
800BB1EC	sra    v0, s4, $0c
800BB1F0	slt    v0, v0, v1

funcbb1f4:	; 800BB1F4
800BB1F4	beq    v0, zero, Lbb204 [$800bb204]
800BB1F8	nop
800BB1FC	j      Lbb378 [$800bb378]
800BB200	sw     s4, $0008(s1)

Lbb204:	; 800BB204
800BB204	lhu    v0, $0006(s1)
800BB208	nop
800BB20C	beq    v0, zero, Lbb2a0 [$800bb2a0]
800BB210	lui    a3, $8008
800BB214	lw     v0, $b720(fp)
800BB218	addiu  a3, a3, $b92d (=-$46d3)
800BB21C	sltu   v0, v0, a3
800BB220	bne    v0, zero, Lbb250 [$800bb250]
800BB224	nop
800BB228	jal    system_reset_random [$8004bf20]
800BB22C	nop
800BB230	lw     v0, $b720(fp)
800BB234	lui    a3, $8008
800BB238	addiu  a3, a3, $b92d (=-$46d3)
800BB23C	sltu   v0, v0, a3
800BB240	bne    v0, zero, Lbb250 [$800bb250]
800BB244	nop
800BB248	jal    system_reset_random [$8004bf20]
800BB24C	nop

Lbb250:	; 800BB250
800BB250	lw     a1, $b720(fp)
800BB254	lhu    v1, $0006(s1)
800BB258	lbu    a0, $0000(a1)
800BB25C	addiu  v1, v1, $0001
800BB260	sll    v0, a0, $08
800BB264	or     v0, v0, a0
800BB268	mult   v1, v0
800BB26C	addiu  a1, a1, $0001
800BB270	sw     a1, $b720(fp)
800BB274	lhu    a0, $0004(s1)
800BB278	mflo   v1
800BB27C	bgez   v1, Lbb28c [$800bb28c]
800BB280	nop
800BB284	ori    v0, zero, $ffff
800BB288	addu   v1, v1, v0

Lbb28c:	; 800BB28C
800BB28C	sra    v0, v1, $10
800BB290	addu   v0, a0, v0
800BB294	sll    v0, v0, $0c
800BB298	j      Lbb374 [$800bb374]
800BB29C	subu   v0, zero, v0

Lbb2a0:	; 800BB2A0
800BB2A0	lbu    v1, $0000(s1)
800BB2A4	nop
800BB2A8	andi   v0, v1, $0002
800BB2AC	beq    v0, zero, Lbb2bc [$800bb2bc]
800BB2B0	andi   v0, v1, $00fc
800BB2B4	j      Lbb378 [$800bb378]
800BB2B8	sb     v0, $0000(s1)

Lbb2bc:	; 800BB2BC
800BB2BC	j      Lbb378 [$800bb378]
800BB2C0	sw     zero, $0008(s1)

Lbb2c4:	; 800BB2C4
800BB2C4	beq    v0, zero, Lbb378 [$800bb378]
800BB2C8	nop
800BB2CC	addu   s2, zero, zero
800BB2D0	lw     s4, $0008(s1)
800BB2D4	lbu    v0, $000c(s1)
800BB2D8	sra    v1, s4, $0c
800BB2DC	beq    v0, zero, Lbb368 [$800bb368]
800BB2E0	addu   s6, v1, zero
800BB2E4	sll    v0, v1, $10
800BB2E8	sra    s5, v0, $10
800BB2EC	addu   s3, s2, zero

loopbb2f0:	; 800BB2F0
800BB2F0	lw     v0, $0010(s1)
800BB2F4	nop
800BB2F8	addu   s0, v0, s3

Lbb2fc:	; 800BB2FC
800BB2FC	addu   a0, s0, zero
800BB300	lh     a2, $0002(s0)
800BB304	lh     a1, $0000(s0)
800BB308	jal    func13410 [$80013410]
800BB30C	subu   a2, a2, s5
800BB310	lhu    v0, $0000(s0)
800BB314	nop
800BB318	sh     v0, $0010(sp)
800BB31C	lhu    v0, $0002(s0)
800BB320	addiu  s2, s2, $0001
800BB324	subu   v0, v0, s6
800BB328	sh     v0, $0012(sp)
800BB32C	lhu    v0, $0004(s0)
800BB330	addiu  a0, sp, $0010
800BB334	sh     s6, $0016(sp)
800BB338	sh     v0, $0014(sp)
800BB33C	lh     a2, $0002(s0)
800BB340	lh     v0, $0006(s0)
800BB344	lh     a1, $0000(s0)
800BB348	addu   a2, a2, v0
800BB34C	jal    func13410 [$80013410]
800BB350	subu   a2, a2, s5
800BB354	lbu    v0, $000c(s1)
800BB358	nop
800BB35C	sltu   v0, s2, v0
800BB360	bne    v0, zero, loopbb2f0 [$800bb2f0]
800BB364	addiu  s3, s3, $000c

Lbb368:	; 800BB368
800BB368	lh     v1, $0002(s1)
800BB36C	andi   v0, s4, $0fff
800BB370	addu   v0, v0, v1

Lbb374:	; 800BB374
800BB374	sw     v0, $0008(s1)

Lbb378:	; 800BB378
800BB378	lw     a3, $0040(sp)

Lbb37c:	; 800BB37C
800BB37C	nop
800BB380	lhu    v0, $0000(a3)
800BB384	addiu  s7, s7, $0001
800BB388	sltu   v0, s7, v0
800BB38C	bne    v0, zero, Lbb0dc [$800bb0dc]
800BB390	sll    v0, s7, $02

Lbb394:	; 800BB394
800BB394	lw     ra, $003c(sp)
800BB398	lw     fp, $0038(sp)
800BB39C	lw     s7, $0034(sp)
800BB3A0	lw     s6, $0030(sp)
800BB3A4	lw     s5, $002c(sp)
800BB3A8	lw     s4, $0028(sp)
800BB3AC	lw     s3, $0024(sp)
800BB3B0	lw     s2, $0020(sp)
800BB3B4	lw     s1, $001c(sp)
800BB3B8	lw     s0, $0018(sp)
800BB3BC	jr     ra 
800BB3C0	addiu  sp, sp, $0040


funcbb3c4:	; 800BB3C4
800BB3C4	addu   t7, a0, zero
800BB3C8	beq    t7, zero, Lbb500 [$800bb500]
800BB3CC	nop
800BB3D0	lhu    v0, $0000(t7)
800BB3D4	nop
800BB3D8	beq    v0, zero, Lbb500 [$800bb500]
800BB3DC	addu   t6, zero, zero
800BB3E0	addu   t1, t7, zero

loopbb3e4:	; 800BB3E4
800BB3E4	lw     a2, $0014(t1)
800BB3E8	addiu  v0, zero, $0001
800BB3EC	sh     v0, $0012(t1)
800BB3F0	lui    v0, $8000
800BB3F4	sltu   v0, v0, a2
800BB3F8	bne    v0, zero, Lbb500 [$800bb500]
800BB3FC	nop
800BB400	beq    a2, zero, Lbb4ec [$800bb4ec]
800BB404	nop
800BB408	lbu    a3, $0011(t1)
800BB40C	addu   a2, a2, t7
800BB410	beq    a1, zero, Lbb44c [$800bb44c]
800BB414	sw     a2, $0014(t1)
800BB418	andi   a0, a3, $00ff
800BB41C	sll    a0, a0, $03
800BB420	addu   a0, a0, a1
800BB424	lhu    v0, $0000(a2)
800BB428	lhu    v1, $0004(a0)
800BB42C	nop
800BB430	addu   v0, v0, v1
800BB434	sh     v0, $0000(a2)
800BB438	lhu    v0, $0002(a2)
800BB43C	lhu    v1, $0006(a0)

Lbb440:	; 800BB440
800BB440	nop
800BB444	addu   v0, v0, v1
800BB448	sh     v0, $0002(a2)

Lbb44c:	; 800BB44C
800BB44C	lbu    v0, $0010(t1)
800BB450	nop
800BB454	beq    v0, zero, Lbb4ec [$800bb4ec]
800BB458	addu   t2, zero, zero
800BB45C	addu   t5, t1, zero
800BB460	andi   v0, a3, $00ff
800BB464	sll    v0, v0, $03
800BB468	addu   t3, v0, a1
800BB46C	addu   t0, a2, zero

loopbb470:	; 800BB470
800BB470	lw     a2, $0008(t0)
800BB474	nop
800BB478	addu   a2, a2, t7
800BB47C	beq    a1, zero, Lbb4d8 [$800bb4d8]
800BB480	sw     a2, $0008(t0)
800BB484	lbu    v0, $0005(t5)
800BB488	nop
800BB48C	beq    v0, zero, Lbb4d8 [$800bb4d8]
800BB490	addu   a3, zero, zero
800BB494	addu   t4, t1, zero
800BB498	addiu  a0, a2, $0002

loopbb49c:	; 800BB49C
800BB49C	lhu    v0, $0000(a2)

funcbb4a0:	; 800BB4A0
800BB4A0	lhu    v1, $0000(t3)
800BB4A4	addiu  a3, a3, $0001
800BB4A8	addu   v0, v0, v1
800BB4AC	sh     v0, $0000(a2)
800BB4B0	lhu    v0, $0000(a0)
800BB4B4	lhu    v1, $0002(t3)
800BB4B8	addiu  a2, a2, $0004
800BB4BC	addu   v0, v0, v1
800BB4C0	sh     v0, $0000(a0)
800BB4C4	lbu    v0, $0005(t4)
800BB4C8	nop
800BB4CC	sltu   v0, a3, v0
800BB4D0	bne    v0, zero, loopbb49c [$800bb49c]
800BB4D4	addiu  a0, a0, $0004

Lbb4d8:	; 800BB4D8
800BB4D8	lbu    v0, $0010(t5)
800BB4DC	addiu  t2, t2, $0001
800BB4E0	sltu   v0, t2, v0
800BB4E4	bne    v0, zero, loopbb470 [$800bb470]
800BB4E8	addiu  t0, t0, $000c

Lbb4ec:	; 800BB4EC
800BB4EC	lhu    v0, $0000(t7)
800BB4F0	addiu  t6, t6, $0001
800BB4F4	sltu   v0, t6, v0
800BB4F8	bne    v0, zero, loopbb3e4 [$800bb3e4]
800BB4FC	addiu  t1, t1, $0014

Lbb500:	; 800BB500
800BB500	jr     ra 
800BB504	nop


funcbb508:	; 800BB508
800BB508	lui    v0, $8006
800BB50C	lw     v0, $794c(v0)
800BB510	addiu  sp, sp, $fff8 (=-$8)
800BB514	sw     s0, $0000(sp)
800BB518	lw     v0, $001c(v0)
800BB51C	nop
800BB520	lhu    v0, $000a(v0)
800BB524	nop
800BB528	ctc2   v0,mac2
800BB52C	lui    v0, $8007
800BB530	addiu  t0, v0, $11a8
800BB534	lui    v0, $8007
800BB538	addiu  a3, v0, $0520
800BB53C	addu   t3, zero, zero
800BB540	andi   a1, a1, $00ff
800BB544	sll    v0, a1, $02
800BB548	addu   v0, v0, a1
800BB54C	sll    v0, v0, $03
800BB550	lw     a2, $0008(a0)
800BB554	lw     t2, $0020(a0)
800BB558	lw     v1, $0010(a2)
800BB55C	lbu    t7, $0002(a2)
800BB560	lh     a2, $005a(a0)
800BB564	addu   t8, v1, v0
800BB568	lw     a1, $0018(t8)
800BB56C	beq    t7, zero, Lbb708 [$800bb708]
800BB570	addu   t1, t3, zero
800BB574	addu   s0, t0, zero
800BB578	addu   t9, a3, zero

loopbb57c:	; 800BB57C
800BB57C	lw     v1, $0014(t8)
800BB580	sll    v0, t1, $01
800BB584	addu   v0, v0, v1
800BB588	lhu    a0, $0000(v0)
800BB58C	nop
800BB590	beq    a0, zero, Lbb6fc [$800bb6fc]
800BB594	addiu  t1, t1, $0001
800BB598	sll    v0, t3, $02
800BB59C	addu   t0, v0, s0
800BB5A0	addu   a3, v0, t9
800BB5A4	lw     t4, $0000(t2)
800BB5A8	lw     t5, $0004(t2)
800BB5AC	ctc2   t4,vxy0
800BB5B0	ctc2   t5,vz0
800BB5B4	lw     t4, $0008(t2)
800BB5B8	lw     t5, $000c(t2)
800BB5BC	lw     t6, $0010(t2)
800BB5C0	ctc2   t4,vxy1
800BB5C4	ctc2   t5,vz1

Lbb5c8:	; 800BB5C8
800BB5C8	ctc2   t6,vxy2
800BB5CC	lw     t4, $0014(t2)
800BB5D0	lw     t5, $0018(t2)
800BB5D4	ctc2   t4,vz2
800BB5D8	lw     t6, $001c(t2)
800BB5DC	ctc2   t5,rgb
800BB5E0	ctc2   t6,otz
800BB5E4	addu   v1, zero, zero

loopbb5e8:	; 800BB5E8
800BB5E8	lwc2   zero, $0000(a1)
800BB5EC	lwc2   at, $0004(a1)
800BB5F0	addiu  v1, v1, $0001
800BB5F4	addiu  a1, a1, $0008
800BB5F8	gte_func18t0,r11r12
800BB5FC	mfc2   t4,l13l21
800BB600	mfc2   t5,l22l23
800BB604	mfc2   t6,l31l32
800BB608	sh     t4, $0000(t0)
800BB60C	ori    t4, zero, $ffff
800BB610	slt    at, t5, a2
800BB614	bne    at, zero, Lbb628 [$800bb628]
800BB618	and    t6, t6, t4
800BB61C	addu   t5, a2, zero
800BB620	lui    at, $1000
800BB624	or     t6, t6, at

Lbb628:	; 800BB628
800BB628	sh     t5, $0002(t0)
800BB62C	sw     t6, $0000(a3)
800BB630	addiu  t0, t0, $0004
800BB634	sltu   v0, v1, a0
800BB638	bne    v0, zero, loopbb5e8 [$800bb5e8]
800BB63C	addiu  a3, a3, $0004
800BB640	sll    v1, t3, $02
800BB644	lui    v0, $8006
800BB648	lw     v0, $794c(v0)
800BB64C	addu   t0, v1, s0
800BB650	lw     v0, $001c(v0)
800BB654	addu   a3, v1, t9
800BB658	addiu  v0, v0, $0018
800BB65C	lw     t4, $0000(v0)
800BB660	lw     t5, $0004(v0)
800BB664	ctc2   t4,vxy0
800BB668	ctc2   t5,vz0
800BB66C	lw     t4, $0008(v0)
800BB670	lw     t5, $000c(v0)
800BB674	lw     t6, $0010(v0)
800BB678	ctc2   t4,vxy1
800BB67C	ctc2   t5,vz1
800BB680	ctc2   t6,vxy2
800BB684	lw     t4, $0014(v0)
800BB688	lw     t5, $0018(v0)
800BB68C	ctc2   t4,vz2
800BB690	lw     t6, $001c(v0)
800BB694	ctc2   t5,rgb
800BB698	ctc2   t6,otz
800BB69C	addu   v1, zero, zero

loopbb6a0:	; 800BB6A0
800BB6A0	lwc2   zero, $0000(t0)
800BB6A4	lwc2   at, $0000(a3)
800BB6A8	lwc2   v0, $0004(t0)
800BB6AC	lwc2   v1, $0004(a3)
800BB6B0	lwc2   a0, $0008(t0)
800BB6B4	lwc2   a1, $0008(a3)
800BB6B8	nop
800BB6BC	addiu  v1, v1, $0003
800BB6C0	gte_func17t0,r11r12
800BB6C4	swc2   t4, $0000(t0)
800BB6C8	swc2   t5, $0004(t0)
800BB6CC	swc2   t6, $0008(t0)
800BB6D0	addiu  t0, t0, $000c
800BB6D4	mfc2   t4,lr3lg1
800BB6D8	mfc2   t5,lg2lg3
800BB6DC	mfc2   t6,lb1lb2
800BB6E0	sh     t4, $0000(a3)
800BB6E4	sh     t5, $0004(a3)
800BB6E8	sh     t6, $0008(a3)
800BB6EC	sltu   v0, v1, a0
800BB6F0	bne    v0, zero, loopbb6a0 [$800bb6a0]
800BB6F4	addiu  a3, a3, $000c
800BB6F8	addu   t3, t3, a0

Lbb6fc:	; 800BB6FC
800BB6FC	sltu   v0, t1, t7
800BB700	bne    v0, zero, loopbb57c [$800bb57c]
800BB704	addiu  t2, t2, $0020

Lbb708:	; 800BB708
800BB708	lw     s0, $0000(sp)
800BB70C	jr     ra 
800BB710	addiu  sp, sp, $0008


funcbb714:	; 800BB714
800BB714	addiu  sp, sp, $ffd8 (=-$28)
800BB718	addu   a3, a0, zero
800BB71C	andi   a2, a1, $00ff
800BB720	sll    a0, a2, $02
800BB724	addu   a0, a0, a2
800BB728	lui    v0, $8006
800BB72C	lw     v0, $794c(v0)
800BB730	sll    a0, a0, $03
800BB734	sw     s7, $0024(sp)
800BB738	sw     s6, $0020(sp)
800BB73C	sw     s5, $001c(sp)
800BB740	sw     s4, $0018(sp)
800BB744	sw     s3, $0014(sp)
800BB748	sw     s2, $0010(sp)
800BB74C	sw     s1, $000c(sp)
800BB750	sw     s0, $0008(sp)

Lbb754:	; 800BB754
800BB754	lw     a1, $0008(a3)
800BB758	lw     v1, $001c(v0)
800BB75C	lw     v0, $0010(a1)
800BB760	lbu    a1, $0008(v1)
800BB764	addu   s6, v0, a0

Lbb768:	; 800BB768
800BB768	sll    v0, a1, $02
800BB76C	addu   v1, v1, v0
800BB770	lw     s4, $0010(v1)
800BB774	beq    a1, zero, Lbb79c [$800bb79c]
800BB778	sll    v0, a2, $01
800BB77C	addu   v0, v0, a2
800BB780	lw     v1, $0044(a3)
800BB784	sll    v0, v0, $02
800BB788	addu   v0, v0, v1
800BB78C	lhu    v1, $0000(s6)
800BB790	lw     v0, $0004(v0)
800BB794	j      Lbb7b0 [$800bb7b0]
800BB798	addu   v0, v0, v1

Lbb79c:	; 800BB79C
800BB79C	addu   v0, v0, a2
800BB7A0	lw     v1, $0044(a3)
800BB7A4	sll    v0, v0, $02
800BB7A8	addu   v0, v0, v1
800BB7AC	lw     v0, $0004(v0)

Lbb7b0:	; 800BB7B0
800BB7B0	nop
800BB7B4	addu   t5, v0, zero
800BB7B8	lhu    s0, $0002(s6)
800BB7BC	lw     t9, $001c(s6)
800BB7C0	beq    s0, zero, Lbb924 [$800bb924]
800BB7C4	addu   t6, zero, zero
800BB7C8	lui    v0, $8007
800BB7CC	addiu  s3, v0, $11a8
800BB7D0	lui    v0, $8007
800BB7D4	addiu  s2, v0, $0520
800BB7D8	lui    s5, $ff00
800BB7DC	lui    s1, $00ff
800BB7E0	ori    s1, s1, $ffff
800BB7E4	addiu  t7, t5, $0020
800BB7E8	addiu  t8, t9, $0015

loopbb7ec:	; 800BB7EC
800BB7EC	lui    t0, $3fff
800BB7F0	ori    t0, t0, $ffff
800BB7F4	lw     v1, $0000(t9)
800BB7F8	lw     t1, $ffef(t8)
800BB7FC	srl    a0, v1, $10
800BB800	srl    t3, t1, $10
800BB804	andi   v1, v1, $ffff
800BB808	sll    v1, v1, $02
800BB80C	addu   v0, v1, s3
800BB810	sll    a2, a0, $02
800BB814	lw     t4, $0000(v0)
800BB818	addu   v0, a2, s3
800BB81C	andi   a1, t1, $ffff
800BB820	sll    a1, a1, $02
800BB824	addu   a3, a1, s3
800BB828	addu   v1, v1, s2
800BB82C	addu   a2, a2, s2
800BB830	addu   a1, a1, s2
800BB834	lw     t2, $0000(v0)
800BB838	lw     v0, $0000(a2)
800BB83C	sll    a2, t3, $02
800BB840	lw     a0, $0000(v1)
800BB844	lw     a3, $0000(a3)
800BB848	lw     v1, $0000(a1)
800BB84C	addu   a0, a0, v0
800BB850	addu   v0, a2, s2
800BB854	lw     v0, $0000(v0)
800BB858	addu   a0, a0, v1
800BB85C	addu   a0, a0, v0
800BB860	slt    t0, t0, a0
800BB864	bne    t0, zero, Lbb90c [$800bb90c]
800BB868	addiu  t6, t6, $0001
800BB86C	lbu    v0, $0000(t8)
800BB870	nop
800BB874	andi   v0, v0, $0002
800BB878	bne    v0, zero, Lbb8b4 [$800bb8b4]
800BB87C	lui    v0, $000f
800BB880	mtc2   t4,l33
800BB884	mtc2   a3,gbk
800BB888	mtc2   t2,rbk
800BB88C	lw     v0, $0000(t5)
800BB890	nop
800BB894	and    v0, v0, s5
800BB898	sw     v0, $0000(t5)
800BB89C	gte_func26zero,r11r12
800BB8A0	swc2   t8, $0000(sp)
800BB8A4	lw     v0, $0000(sp)
800BB8A8	nop
800BB8AC	blez   v0, Lbb90c [$800bb90c]
800BB8B0	lui    v0, $000f

Lbb8b4:	; 800BB8B4
800BB8B4	ori    v0, v0, $ffff
800BB8B8	and    a0, a0, v0
800BB8BC	addu   v0, a2, s3
800BB8C0	sra    a0, a0, $04
800BB8C4	sll    a0, a0, $02
800BB8C8	sw     t4, $ffe8(t7)
800BB8CC	sw     t2, $fff0(t7)
800BB8D0	sw     a3, $fff8(t7)
800BB8D4	lw     v0, $0000(v0)
800BB8D8	addu   a0, a0, s4
800BB8DC	sw     v0, $0000(t7)
800BB8E0	lw     v1, $0000(t5)
800BB8E4	lw     v0, $0000(a0)
800BB8E8	and    v1, v1, s5
800BB8EC	and    v0, v0, s1
800BB8F0	or     v1, v1, v0
800BB8F4	sw     v1, $0000(t5)
800BB8F8	lw     v0, $0000(a0)
800BB8FC	and    v1, t5, s1
800BB900	and    v0, v0, s5
800BB904	or     v0, v0, v1
800BB908	sw     v0, $0000(a0)

Lbb90c:	; 800BB90C
800BB90C	addiu  t8, t8, $0018
800BB910	addiu  t9, t9, $0018
800BB914	addiu  t7, t7, $0028
800BB918	sltu   v0, t6, s0
800BB91C	bne    v0, zero, loopbb7ec [$800bb7ec]
800BB920	addiu  t5, t5, $0028

Lbb924:	; 800BB924
800BB924	lhu    s0, $0004(s6)
800BB928	addu   t7, t9, zero
800BB92C	addu   a2, t5, zero
800BB930	beq    s0, zero, Lbba8c [$800bba8c]
800BB934	addu   t6, zero, zero
800BB938	lui    v0, $8007
800BB93C	addiu  s3, v0, $11a8
800BB940	lui    v0, $8007
800BB944	addiu  s2, v0, $0520
800BB948	lui    s1, $ff00
800BB94C	lui    t5, $00ff
800BB950	ori    t5, t5, $ffff

Lbb954:	; 800BB954
800BB954	addiu  t0, a2, $0018
800BB958	addiu  t3, t7, $0012

loopbb95c:	; 800BB95C
800BB95C	lui    a1, $2fff
800BB960	ori    a1, a1, $ffff
800BB964	lw     v1, $0000(t7)
800BB968	lhu    t1, $fff2(t3)
800BB96C	srl    a0, v1, $10
800BB970	andi   v1, v1, $ffff

funcbb974:	; 800BB974
800BB974	sll    v1, v1, $02
800BB978	addu   v0, v1, s3
800BB97C	sll    a0, a0, $02
800BB980	lw     t4, $0000(v0)
800BB984	addu   v0, a0, s3
800BB988	lw     t2, $0000(v0)
800BB98C	sll    v0, t1, $02
800BB990	addu   v0, v0, s3
800BB994	addu   v1, v1, s2
800BB998	addu   a0, a0, s2
800BB99C	lw     a3, $0000(v0)
800BB9A0	sll    v0, t1, $02
800BB9A4	addu   v0, v0, s2
800BB9A8	lw     v1, $0000(v1)
800BB9AC	lw     a0, $0000(a0)
800BB9B0	lw     v0, $0000(v0)
800BB9B4	addu   v1, v1, a0
800BB9B8	addu   a0, v1, v0
800BB9BC	slt    a1, a1, a0
800BB9C0	bne    a1, zero, Lbba74 [$800bba74]
800BB9C4	addiu  t6, t6, $0001
800BB9C8	lbu    v0, $0000(t3)
800BB9CC	nop
800BB9D0	andi   v0, v0, $0002
800BB9D4	bne    v0, zero, Lbba10 [$800bba10]
800BB9D8	lui    v0, $000f
800BB9DC	mtc2   t4,l33
800BB9E0	mtc2   a3,gbk
800BB9E4	mtc2   t2,rbk
800BB9E8	lw     v0, $0000(a2)
800BB9EC	nop
800BB9F0	and    v0, v0, s1
800BB9F4	sw     v0, $0000(a2)
800BB9F8	gte_func26zero,r11r12
800BB9FC	swc2   t8, $0000(sp)
800BBA00	lw     v0, $0000(sp)
800BBA04	nop
800BBA08	blez   v0, Lbba74 [$800bba74]
800BBA0C	lui    v0, $000f

Lbba10:	; 800BBA10
800BBA10	ori    v0, v0, $ffff
800BBA14	lui    v1, $5555
800BBA18	ori    v1, v1, $5556
800BBA1C	and    v0, a0, v0
800BBA20	mult   v0, v1
800BBA24	sra    v0, v0, $1f
800BBA28	sw     t4, $fff0(t0)
800BBA2C	sw     t2, $fff8(t0)
800BBA30	sw     a3, $0000(t0)
800BBA34	lw     v1, $0000(a2)
800BBA38	mfhi   s7
800BBA3C	subu   a0, s7, v0
800BBA40	sra    a0, a0, $02
800BBA44	sll    a0, a0, $02
800BBA48	addu   a0, a0, s4
800BBA4C	lw     v0, $0000(a0)
800BBA50	and    v1, v1, s1
800BBA54	and    v0, v0, t5
800BBA58	or     v1, v1, v0
800BBA5C	sw     v1, $0000(a2)
800BBA60	lw     v0, $0000(a0)
800BBA64	and    v1, a2, t5
800BBA68	and    v0, v0, s1
800BBA6C	or     v0, v0, v1
800BBA70	sw     v0, $0000(a0)

Lbba74:	; 800BBA74
800BBA74	addiu  t3, t3, $0014
800BBA78	addiu  t7, t7, $0014
800BBA7C	addiu  t0, t0, $0020
800BBA80	sltu   v0, t6, s0
800BBA84	bne    v0, zero, loopbb95c [$800bb95c]
800BBA88	addiu  a2, a2, $0020

Lbba8c:	; 800BBA8C
800BBA8C	lhu    s0, $0006(s6)
800BBA90	addu   t9, t7, zero
800BBA94	addu   t5, a2, zero
800BBA98	beq    s0, zero, Lbbbfc [$800bbbfc]
800BBA9C	addu   t6, zero, zero
800BBAA0	lui    v0, $8007
800BBAA4	addiu  s3, v0, $11a8
800BBAA8	lui    v0, $8007
800BBAAC	addiu  s2, v0, $0520
800BBAB0	lui    s5, $ff00
800BBAB4	lui    s1, $00ff
800BBAB8	ori    s1, s1, $ffff
800BBABC	addiu  t7, t5, $002c
800BBAC0	addiu  t8, t9, $001c

loopbbac4:	; 800BBAC4
800BBAC4	lui    t0, $3fff
800BBAC8	ori    t0, t0, $ffff
800BBACC	lw     v1, $0000(t9)
800BBAD0	lw     t1, $ffe8(t8)
800BBAD4	srl    a0, v1, $10
800BBAD8	srl    t3, t1, $10
800BBADC	andi   v1, v1, $ffff
800BBAE0	sll    v1, v1, $02
800BBAE4	addu   v0, v1, s3
800BBAE8	sll    a2, a0, $02
800BBAEC	lw     t4, $0000(v0)
800BBAF0	addu   v0, a2, s3
800BBAF4	andi   a1, t1, $ffff
800BBAF8	sll    a1, a1, $02
800BBAFC	addu   a3, a1, s3
800BBB00	addu   v1, v1, s2
800BBB04	addu   a2, a2, s2
800BBB08	addu   a1, a1, s2
800BBB0C	lw     t2, $0000(v0)
800BBB10	lw     v0, $0000(a2)
800BBB14	sll    a2, t3, $02
800BBB18	lw     a0, $0000(v1)
800BBB1C	lw     a3, $0000(a3)
800BBB20	lw     v1, $0000(a1)
800BBB24	addu   a0, a0, v0

Lbbb28:	; 800BBB28
800BBB28	addu   v0, a2, s2
800BBB2C	lw     v0, $0000(v0)
800BBB30	addu   a0, a0, v1
800BBB34	addu   a0, a0, v0
800BBB38	slt    t0, t0, a0
800BBB3C	bne    t0, zero, Lbbbe4 [$800bbbe4]
800BBB40	addiu  t6, t6, $0001
800BBB44	lbu    v0, $0000(t8)
800BBB48	nop
800BBB4C	andi   v0, v0, $0002
800BBB50	bne    v0, zero, Lbbb8c [$800bbb8c]
800BBB54	lui    v0, $000f
800BBB58	mtc2   t4,l33
800BBB5C	mtc2   a3,gbk
800BBB60	mtc2   t2,rbk
800BBB64	lw     v0, $0000(t5)
800BBB68	nop
800BBB6C	and    v0, v0, s5
800BBB70	sw     v0, $0000(t5)
800BBB74	gte_func26zero,r11r12

Lbbb78:	; 800BBB78
800BBB78	swc2   t8, $0000(sp)
800BBB7C	lw     v0, $0000(sp)
800BBB80	nop
800BBB84	blez   v0, Lbbbe4 [$800bbbe4]
800BBB88	lui    v0, $000f

Lbbb8c:	; 800BBB8C
800BBB8C	ori    v0, v0, $ffff
800BBB90	and    a0, a0, v0
800BBB94	addu   v0, a2, s3
800BBB98	sra    a0, a0, $04
800BBB9C	sll    a0, a0, $02

Lbbba0:	; 800BBBA0
800BBBA0	sw     t4, $ffdc(t7)
800BBBA4	sw     t2, $ffe8(t7)

funcbbba8:	; 800BBBA8
800BBBA8	sw     a3, $fff4(t7)
800BBBAC	lw     v0, $0000(v0)
800BBBB0	addu   a0, a0, s4
800BBBB4	sw     v0, $0000(t7)
800BBBB8	lw     v1, $0000(t5)
800BBBBC	lw     v0, $0000(a0)
800BBBC0	and    v1, v1, s5
800BBBC4	and    v0, v0, s1
800BBBC8	or     v1, v1, v0
800BBBCC	sw     v1, $0000(t5)
800BBBD0	lw     v0, $0000(a0)
800BBBD4	and    v1, t5, s1
800BBBD8	and    v0, v0, s5

Lbbbdc:	; 800BBBDC
800BBBDC	or     v0, v0, v1
800BBBE0	sw     v0, $0000(a0)

Lbbbe4:	; 800BBBE4
800BBBE4	addiu  t8, t8, $0020
800BBBE8	addiu  t9, t9, $0020
800BBBEC	addiu  t7, t7, $0034
800BBBF0	sltu   v0, t6, s0
800BBBF4	bne    v0, zero, loopbbac4 [$800bbac4]
800BBBF8	addiu  t5, t5, $0034

Lbbbfc:	; 800BBBFC
800BBBFC	lhu    s0, $0008(s6)
800BBC00	addu   t7, t9, zero
800BBC04	addu   a2, t5, zero
800BBC08	beq    s0, zero, Lbbd64 [$800bbd64]
800BBC0C	addu   t6, zero, zero
800BBC10	lui    v0, $8007
800BBC14	addiu  s3, v0, $11a8
800BBC18	lui    v0, $8007
800BBC1C	addiu  s2, v0, $0520
800BBC20	lui    s1, $ff00
800BBC24	lui    t5, $00ff
800BBC28	ori    t5, t5, $ffff
800BBC2C	addiu  t0, a2, $0020
800BBC30	addiu  t3, t7, $000f

loopbbc34:	; 800BBC34
800BBC34	lui    a1, $2fff
800BBC38	ori    a1, a1, $ffff
800BBC3C	lw     v1, $0000(t7)
800BBC40	lhu    t1, $fff5(t3)
800BBC44	srl    a0, v1, $10
800BBC48	andi   v1, v1, $ffff
800BBC4C	sll    v1, v1, $02
800BBC50	addu   v0, v1, s3
800BBC54	sll    a0, a0, $02
800BBC58	lw     t4, $0000(v0)
800BBC5C	addu   v0, a0, s3
800BBC60	lw     t2, $0000(v0)
800BBC64	sll    v0, t1, $02
800BBC68	addu   v0, v0, s3
800BBC6C	addu   v1, v1, s2
800BBC70	addu   a0, a0, s2
800BBC74	lw     a3, $0000(v0)
800BBC78	sll    v0, t1, $02
800BBC7C	addu   v0, v0, s2
800BBC80	lw     v1, $0000(v1)
800BBC84	lw     a0, $0000(a0)
800BBC88	lw     v0, $0000(v0)
800BBC8C	addu   v1, v1, a0

Lbbc90:	; 800BBC90
800BBC90	addu   a0, v1, v0
800BBC94	slt    a1, a1, a0
800BBC98	bne    a1, zero, Lbbd4c [$800bbd4c]
800BBC9C	addiu  t6, t6, $0001
800BBCA0	lbu    v0, $0000(t3)
800BBCA4	nop
800BBCA8	andi   v0, v0, $0002
800BBCAC	bne    v0, zero, Lbbce8 [$800bbce8]
800BBCB0	lui    v0, $000f
800BBCB4	mtc2   t4,l33
800BBCB8	mtc2   a3,gbk
800BBCBC	mtc2   t2,rbk
800BBCC0	lw     v0, $0000(a2)
800BBCC4	nop
800BBCC8	and    v0, v0, s1
800BBCCC	sw     v0, $0000(a2)

Lbbcd0:	; 800BBCD0
800BBCD0	gte_func26zero,r11r12
800BBCD4	swc2   t8, $0000(sp)
800BBCD8	lw     v0, $0000(sp)
800BBCDC	nop
800BBCE0	blez   v0, Lbbd4c [$800bbd4c]
800BBCE4	lui    v0, $000f

Lbbce8:	; 800BBCE8
800BBCE8	ori    v0, v0, $ffff
800BBCEC	lui    v1, $5555
800BBCF0	ori    v1, v1, $5556
800BBCF4	and    v0, a0, v0
800BBCF8	mult   v0, v1
800BBCFC	sra    v0, v0, $1f
800BBD00	sw     t4, $ffe8(t0)
800BBD04	sw     t2, $fff4(t0)
800BBD08	sw     a3, $0000(t0)
800BBD0C	lw     v1, $0000(a2)
800BBD10	mfhi   s7
800BBD14	subu   a0, s7, v0
800BBD18	sra    a0, a0, $02
800BBD1C	sll    a0, a0, $02
800BBD20	addu   a0, a0, s4
800BBD24	lw     v0, $0000(a0)
800BBD28	and    v1, v1, s1
800BBD2C	and    v0, v0, t5
800BBD30	or     v1, v1, v0
800BBD34	sw     v1, $0000(a2)
800BBD38	lw     v0, $0000(a0)

funcbbd3c:	; 800BBD3C
800BBD3C	and    v1, a2, t5
800BBD40	and    v0, v0, s1
800BBD44	or     v0, v0, v1
800BBD48	sw     v0, $0000(a0)

Lbbd4c:	; 800BBD4C
800BBD4C	addiu  t3, t3, $0018
800BBD50	addiu  t7, t7, $0018
800BBD54	addiu  t0, t0, $0028
800BBD58	sltu   v0, t6, s0
800BBD5C	bne    v0, zero, loopbbc34 [$800bbc34]
800BBD60	addiu  a2, a2, $0028

Lbbd64:	; 800BBD64
800BBD64	lhu    s0, $000a(s6)
800BBD68	addu   t9, t7, zero
800BBD6C	addu   t5, a2, zero
800BBD70	beq    s0, zero, Lbbed4 [$800bbed4]
800BBD74	addu   t6, zero, zero
800BBD78	lui    v0, $8007
800BBD7C	addiu  s3, v0, $11a8
800BBD80	lui    v0, $8007
800BBD84	addiu  s2, v0, $0520
800BBD88	lui    s5, $ff00
800BBD8C	lui    s1, $00ff
800BBD90	ori    s1, s1, $ffff
800BBD94	addiu  t7, t5, $0020
800BBD98	addiu  t8, t9, $0014

loopbbd9c:	; 800BBD9C
800BBD9C	lui    t0, $3fff
800BBDA0	ori    t0, t0, $ffff
800BBDA4	lw     v1, $0000(t9)
800BBDA8	lw     t1, $fff0(t8)
800BBDAC	srl    a0, v1, $10
800BBDB0	srl    t3, t1, $10
800BBDB4	andi   v1, v1, $ffff
800BBDB8	sll    v1, v1, $02
800BBDBC	addu   v0, v1, s3
800BBDC0	sll    a2, a0, $02
800BBDC4	lw     t4, $0000(v0)
800BBDC8	addu   v0, a2, s3
800BBDCC	andi   a1, t1, $ffff
800BBDD0	sll    a1, a1, $02
800BBDD4	addu   a3, a1, s3
800BBDD8	addu   v1, v1, s2
800BBDDC	addu   a2, a2, s2
800BBDE0	addu   a1, a1, s2
800BBDE4	lw     t2, $0000(v0)
800BBDE8	lw     v0, $0000(a2)
800BBDEC	sll    a2, t3, $02
800BBDF0	lw     a0, $0000(v1)
800BBDF4	lw     a3, $0000(a3)
800BBDF8	lw     v1, $0000(a1)
800BBDFC	addu   a0, a0, v0
800BBE00	addu   v0, a2, s2
800BBE04	lw     v0, $0000(v0)
800BBE08	addu   a0, a0, v1
800BBE0C	addu   a0, a0, v0
800BBE10	slt    t0, t0, a0
800BBE14	bne    t0, zero, Lbbebc [$800bbebc]
800BBE18	addiu  t6, t6, $0001
800BBE1C	lbu    v0, $0000(t8)
800BBE20	nop
800BBE24	andi   v0, v0, $0002
800BBE28	bne    v0, zero, Lbbe64 [$800bbe64]
800BBE2C	lui    v0, $000f
800BBE30	mtc2   t4,l33
800BBE34	mtc2   a3,gbk
800BBE38	mtc2   t2,rbk
800BBE3C	lw     v0, $0000(t5)
800BBE40	nop
800BBE44	and    v0, v0, s5
800BBE48	sw     v0, $0000(t5)
800BBE4C	gte_func26zero,r11r12
800BBE50	swc2   t8, $0000(sp)
800BBE54	lw     v0, $0000(sp)
800BBE58	nop
800BBE5C	blez   v0, Lbbebc [$800bbebc]
800BBE60	lui    v0, $000f

Lbbe64:	; 800BBE64
800BBE64	ori    v0, v0, $ffff
800BBE68	and    a0, a0, v0
800BBE6C	addu   v0, a2, s3
800BBE70	sra    a0, a0, $04
800BBE74	sll    a0, a0, $02
800BBE78	sw     t4, $ffe8(t7)
800BBE7C	sw     t2, $fff0(t7)
800BBE80	sw     a3, $fff8(t7)
800BBE84	lw     v0, $0000(v0)
800BBE88	addu   a0, a0, s4
800BBE8C	sw     v0, $0000(t7)
800BBE90	lw     v1, $0000(t5)
800BBE94	lw     v0, $0000(a0)
800BBE98	and    v1, v1, s5
800BBE9C	and    v0, v0, s1
800BBEA0	or     v1, v1, v0
800BBEA4	sw     v1, $0000(t5)
800BBEA8	lw     v0, $0000(a0)
800BBEAC	and    v1, t5, s1
800BBEB0	and    v0, v0, s5
800BBEB4	or     v0, v0, v1
800BBEB8	sw     v0, $0000(a0)

Lbbebc:	; 800BBEBC
800BBEBC	addiu  t8, t8, $0018
800BBEC0	addiu  t9, t9, $0018
800BBEC4	addiu  t7, t7, $0024
800BBEC8	sltu   v0, t6, s0
800BBECC	bne    v0, zero, loopbbd9c [$800bbd9c]
800BBED0	addiu  t5, t5, $0024

Lbbed4:	; 800BBED4
800BBED4	lhu    s0, $000c(s6)
800BBED8	addu   t7, t9, zero
800BBEDC	addu   a2, t5, zero
800BBEE0	beq    s0, zero, Lbc03c [$800bc03c]
800BBEE4	addu   t6, zero, zero
800BBEE8	lui    v0, $8007
800BBEEC	addiu  s3, v0, $11a8
800BBEF0	lui    v0, $8007
800BBEF4	addiu  s2, v0, $0520
800BBEF8	lui    s1, $ff00
800BBEFC	lui    t5, $00ff
800BBF00	ori    t5, t5, $ffff
800BBF04	addiu  t0, a2, $0018
800BBF08	addiu  t3, t7, $0013

loopbbf0c:	; 800BBF0C
800BBF0C	lui    a1, $2fff
800BBF10	ori    a1, a1, $ffff
800BBF14	lw     v1, $0000(t7)

Lbbf18:	; 800BBF18
800BBF18	lhu    t1, $fff1(t3)
800BBF1C	srl    a0, v1, $10
800BBF20	andi   v1, v1, $ffff
800BBF24	sll    v1, v1, $02
800BBF28	addu   v0, v1, s3
800BBF2C	sll    a0, a0, $02

funcbbf30:	; 800BBF30
800BBF30	lw     t4, $0000(v0)
800BBF34	addu   v0, a0, s3
800BBF38	lw     t2, $0000(v0)
800BBF3C	sll    v0, t1, $02
800BBF40	addu   v0, v0, s3
800BBF44	addu   v1, v1, s2
800BBF48	addu   a0, a0, s2
800BBF4C	lw     a3, $0000(v0)
800BBF50	sll    v0, t1, $02
800BBF54	addu   v0, v0, s2
800BBF58	lw     v1, $0000(v1)

funcbbf5c:	; 800BBF5C
800BBF5C	lw     a0, $0000(a0)
800BBF60	lw     v0, $0000(v0)
800BBF64	addu   v1, v1, a0
800BBF68	addu   a0, v1, v0
800BBF6C	slt    a1, a1, a0
800BBF70	bne    a1, zero, Lbc024 [$800bc024]
800BBF74	addiu  t6, t6, $0001
800BBF78	lbu    v0, $0000(t3)
800BBF7C	nop
800BBF80	andi   v0, v0, $0002
800BBF84	bne    v0, zero, Lbbfc0 [$800bbfc0]
800BBF88	lui    v0, $000f
800BBF8C	mtc2   t4,l33
800BBF90	mtc2   a3,gbk
800BBF94	mtc2   t2,rbk
800BBF98	lw     v0, $0000(a2)
800BBF9C	nop
800BBFA0	and    v0, v0, s1
800BBFA4	sw     v0, $0000(a2)
800BBFA8	gte_func26zero,r11r12
800BBFAC	swc2   t8, $0000(sp)
800BBFB0	lw     v0, $0000(sp)
800BBFB4	nop
800BBFB8	blez   v0, Lbc024 [$800bc024]
800BBFBC	lui    v0, $000f

Lbbfc0:	; 800BBFC0
800BBFC0	ori    v0, v0, $ffff
800BBFC4	lui    v1, $5555
800BBFC8	ori    v1, v1, $5556
800BBFCC	and    v0, a0, v0
800BBFD0	mult   v0, v1
800BBFD4	sra    v0, v0, $1f
800BBFD8	sw     t4, $fff0(t0)
800BBFDC	sw     t2, $fff8(t0)
800BBFE0	sw     a3, $0000(t0)
800BBFE4	lw     v1, $0000(a2)
800BBFE8	mfhi   s7
800BBFEC	subu   a0, s7, v0
800BBFF0	sra    a0, a0, $02
800BBFF4	sll    a0, a0, $02
800BBFF8	addu   a0, a0, s4
800BBFFC	lw     v0, $0000(a0)
800BC000	and    v1, v1, s1
800BC004	and    v0, v0, t5
800BC008	or     v1, v1, v0
800BC00C	sw     v1, $0000(a2)
800BC010	lw     v0, $0000(a0)
800BC014	and    v1, a2, t5
800BC018	and    v0, v0, s1
800BC01C	or     v0, v0, v1
800BC020	sw     v0, $0000(a0)

Lbc024:	; 800BC024
800BC024	addiu  t3, t3, $0014
800BC028	addiu  t7, t7, $0014
800BC02C	addiu  t0, t0, $001c
800BC030	sltu   v0, t6, s0
800BC034	bne    v0, zero, loopbbf0c [$800bbf0c]
800BC038	addiu  a2, a2, $001c

Lbc03c:	; 800BC03C
800BC03C	lhu    s0, $000e(s6)
800BC040	addu   t9, t7, zero
800BC044	addu   t5, a2, zero
800BC048	beq    s0, zero, Lbc1ac [$800bc1ac]
800BC04C	addu   t6, zero, zero
800BC050	lui    v0, $8007
800BC054	addiu  s3, v0, $11a8
800BC058	lui    v0, $8007
800BC05C	addiu  s2, v0, $0520
800BC060	lui    s5, $ff00
800BC064	lui    s1, $00ff
800BC068	ori    s1, s1, $ffff
800BC06C	addiu  t7, t5, $0014
800BC070	addiu  t8, t9, $000d

loopbc074:	; 800BC074
800BC074	lui    t0, $3fff
800BC078	ori    t0, t0, $ffff
800BC07C	lw     v1, $0000(t9)
800BC080	lw     t1, $fff7(t8)
800BC084	srl    a0, v1, $10
800BC088	srl    t3, t1, $10
800BC08C	andi   v1, v1, $ffff
800BC090	sll    v1, v1, $02

Lbc094:	; 800BC094
800BC094	addu   v0, v1, s3
800BC098	sll    a2, a0, $02
800BC09C	lw     t4, $0000(v0)
800BC0A0	addu   v0, a2, s3
800BC0A4	andi   a1, t1, $ffff
800BC0A8	sll    a1, a1, $02
800BC0AC	addu   a3, a1, s3
800BC0B0	addu   v1, v1, s2
800BC0B4	addu   a2, a2, s2
800BC0B8	addu   a1, a1, s2
800BC0BC	lw     t2, $0000(v0)
800BC0C0	lw     v0, $0000(a2)
800BC0C4	sll    a2, t3, $02
800BC0C8	lw     a0, $0000(v1)
800BC0CC	lw     a3, $0000(a3)

funcbc0d0:	; 800BC0D0
800BC0D0	lw     v1, $0000(a1)
800BC0D4	addu   a0, a0, v0
800BC0D8	addu   v0, a2, s2
800BC0DC	lw     v0, $0000(v0)
800BC0E0	addu   a0, a0, v1
800BC0E4	addu   a0, a0, v0
800BC0E8	slt    t0, t0, a0
800BC0EC	bne    t0, zero, Lbc194 [$800bc194]
800BC0F0	addiu  t6, t6, $0001
800BC0F4	lbu    v0, $0000(t8)
800BC0F8	nop
800BC0FC	andi   v0, v0, $0002
800BC100	bne    v0, zero, Lbc13c [$800bc13c]
800BC104	lui    v0, $000f
800BC108	mtc2   t4,l33
800BC10C	mtc2   a3,gbk
800BC110	mtc2   t2,rbk
800BC114	lw     v0, $0000(t5)
800BC118	nop
800BC11C	and    v0, v0, s5
800BC120	sw     v0, $0000(t5)
800BC124	gte_func26zero,r11r12
800BC128	swc2   t8, $0000(sp)
800BC12C	lw     v0, $0000(sp)
800BC130	nop
800BC134	blez   v0, Lbc194 [$800bc194]
800BC138	lui    v0, $000f

Lbc13c:	; 800BC13C
800BC13C	ori    v0, v0, $ffff
800BC140	and    a0, a0, v0
800BC144	addu   v0, a2, s3
800BC148	sra    a0, a0, $04
800BC14C	sll    a0, a0, $02
800BC150	sw     t4, $fff4(t7)
800BC154	sw     t2, $fff8(t7)
800BC158	sw     a3, $fffc(t7)
800BC15C	lw     v0, $0000(v0)
800BC160	addu   a0, a0, s4
800BC164	sw     v0, $0000(t7)
800BC168	lw     v1, $0000(t5)
800BC16C	lw     v0, $0000(a0)
800BC170	and    v1, v1, s5
800BC174	and    v0, v0, s1
800BC178	or     v1, v1, v0
800BC17C	sw     v1, $0000(t5)
800BC180	lw     v0, $0000(a0)
800BC184	and    v1, t5, s1
800BC188	and    v0, v0, s5
800BC18C	or     v0, v0, v1
800BC190	sw     v0, $0000(a0)

Lbc194:	; 800BC194
800BC194	addiu  t8, t8, $0010
800BC198	addiu  t9, t9, $0010
800BC19C	addiu  t7, t7, $0018
800BC1A0	sltu   v0, t6, s0
800BC1A4	bne    v0, zero, loopbc074 [$800bc074]
800BC1A8	addiu  t5, t5, $0018

Lbc1ac:	; 800BC1AC
800BC1AC	lhu    s0, $0010(s6)
800BC1B0	addu   t7, t9, zero
800BC1B4	addu   a2, t5, zero
800BC1B8	beq    s0, zero, Lbc314 [$800bc314]
800BC1BC	addu   t6, zero, zero
800BC1C0	lui    v0, $8007
800BC1C4	addiu  s3, v0, $11a8
800BC1C8	lui    v0, $8007
800BC1CC	addiu  s2, v0, $0520
800BC1D0	lui    s1, $ff00
800BC1D4	lui    t5, $00ff
800BC1D8	ori    t5, t5, $ffff
800BC1DC	addiu  t0, a2, $0010

funcbc1e0:	; 800BC1E0
800BC1E0	addiu  t3, t7, $000b

loopbc1e4:	; 800BC1E4
800BC1E4	lui    a1, $2fff
800BC1E8	ori    a1, a1, $ffff
800BC1EC	lw     v1, $0000(t7)
800BC1F0	lhu    t1, $fff9(t3)
800BC1F4	srl    a0, v1, $10
800BC1F8	andi   v1, v1, $ffff
800BC1FC	sll    v1, v1, $02
800BC200	addu   v0, v1, s3
800BC204	sll    a0, a0, $02
800BC208	lw     t4, $0000(v0)
800BC20C	addu   v0, a0, s3

Lbc210:	; 800BC210
800BC210	lw     t2, $0000(v0)
800BC214	sll    v0, t1, $02
800BC218	addu   v0, v0, s3

funcbc21c:	; 800BC21C
800BC21C	addu   v1, v1, s2
800BC220	addu   a0, a0, s2
800BC224	lw     a3, $0000(v0)
800BC228	sll    v0, t1, $02
800BC22C	addu   v0, v0, s2
800BC230	lw     v1, $0000(v1)
800BC234	lw     a0, $0000(a0)
800BC238	lw     v0, $0000(v0)
800BC23C	addu   v1, v1, a0
800BC240	addu   a0, v1, v0
800BC244	slt    a1, a1, a0
800BC248	bne    a1, zero, Lbc2fc [$800bc2fc]
800BC24C	addiu  t6, t6, $0001
800BC250	lbu    v0, $0000(t3)
800BC254	nop
800BC258	andi   v0, v0, $0002
800BC25C	bne    v0, zero, Lbc298 [$800bc298]
800BC260	lui    v0, $000f
800BC264	mtc2   t4,l33
800BC268	mtc2   a3,gbk
800BC26C	mtc2   t2,rbk
800BC270	lw     v0, $0000(a2)
800BC274	nop
800BC278	and    v0, v0, s1
800BC27C	sw     v0, $0000(a2)
800BC280	gte_func26zero,r11r12
800BC284	swc2   t8, $0000(sp)
800BC288	lw     v0, $0000(sp)
800BC28C	nop
800BC290	blez   v0, Lbc2fc [$800bc2fc]
800BC294	lui    v0, $000f

Lbc298:	; 800BC298
800BC298	ori    v0, v0, $ffff
800BC29C	lui    v1, $5555
800BC2A0	ori    v1, v1, $5556
800BC2A4	and    v0, a0, v0
800BC2A8	mult   v0, v1
800BC2AC	sra    v0, v0, $1f
800BC2B0	sw     t4, $fff8(t0)
800BC2B4	sw     t2, $fffc(t0)
800BC2B8	sw     a3, $0000(t0)
800BC2BC	lw     v1, $0000(a2)
800BC2C0	mfhi   s7
800BC2C4	subu   a0, s7, v0
800BC2C8	sra    a0, a0, $02
800BC2CC	sll    a0, a0, $02
800BC2D0	addu   a0, a0, s4
800BC2D4	lw     v0, $0000(a0)
800BC2D8	and    v1, v1, s1
800BC2DC	and    v0, v0, t5
800BC2E0	or     v1, v1, v0
800BC2E4	sw     v1, $0000(a2)
800BC2E8	lw     v0, $0000(a0)
800BC2EC	and    v1, a2, t5
800BC2F0	and    v0, v0, s1
800BC2F4	or     v0, v0, v1
800BC2F8	sw     v0, $0000(a0)

Lbc2fc:	; 800BC2FC
800BC2FC	addiu  t3, t3, $000c
800BC300	addiu  t7, t7, $000c
800BC304	addiu  t0, t0, $0014
800BC308	sltu   v0, t6, s0
800BC30C	bne    v0, zero, loopbc1e4 [$800bc1e4]
800BC310	addiu  a2, a2, $0014

Lbc314:	; 800BC314
800BC314	lw     s7, $0024(sp)
800BC318	lw     s6, $0020(sp)
800BC31C	lw     s5, $001c(sp)
800BC320	lw     s4, $0018(sp)
800BC324	lw     s3, $0014(sp)
800BC328	lw     s2, $0010(sp)
800BC32C	lw     s1, $000c(sp)
800BC330	lw     s0, $0008(sp)
800BC334	jr     ra 
800BC338	addiu  sp, sp, $0028


funcbc33c:	; 800BC33C
800BC33C	addu   t0, a0, zero
800BC340	lw     v0, $0060(t0)
800BC344	nop
800BC348	beq    v0, zero, Lbc5f8 [$800bc5f8]
800BC34C	nop
800BC350	lh     v1, $0064(t0)
800BC354	lh     v0, $006c(t0)
800BC358	nop
800BC35C	mult   v0, v1
800BC360	lh     a2, $0066(t0)
800BC364	mflo   a1
800BC368	lh     v0, $006e(t0)
800BC36C	nop
800BC370	mult   v0, a2

Lbc374:	; 800BC374
800BC374	lh     a3, $0068(t0)
800BC378	mflo   a0
800BC37C	lh     v0, $0070(t0)
800BC380	nop
800BC384	mult   v0, a3
800BC388	mflo   t8
800BC38C	nop

Lbc390:	; 800BC390
800BC390	nop
800BC394	mult   v1, v1
800BC398	mflo   v0
800BC39C	nop
800BC3A0	nop
800BC3A4	mult   a2, a2
800BC3A8	mflo   t1
800BC3AC	nop
800BC3B0	nop
800BC3B4	mult   a3, a3
800BC3B8	mflo   t2
800BC3BC	nop
800BC3C0	nop
800BC3C4	mult   v1, a2
800BC3C8	mflo   t3
800BC3CC	nop
800BC3D0	nop
800BC3D4	mult   v1, a3
800BC3D8	mflo   t4
800BC3DC	nop
800BC3E0	nop
800BC3E4	mult   a2, a3
800BC3E8	addu   a0, a1, a0
800BC3EC	mflo   t6
800BC3F0	addu   a0, a0, t8
800BC3F4	sra    a0, a0, $0b
800BC3F8	mult   a0, v1
800BC3FC	mflo   t5
800BC400	nop
800BC404	nop
800BC408	mult   a0, a2
800BC40C	lui    a1, $1f80
800BC410	sra    v0, v0, $0b
800BC414	addiu  v1, zero, $1000
800BC418	subu   v0, v1, v0
800BC41C	sh     v0, $0000(a1)
800BC420	sra    v0, t1, $0b
800BC424	subu   v0, v1, v0
800BC428	sh     v0, $0008(a1)
800BC42C	sra    v0, t2, $0b

Lbc430:	; 800BC430
800BC430	subu   v1, v1, v0
800BC434	sra    v0, t3, $0b
800BC438	mflo   a2
800BC43C	sh     v0, $0006(a1)
800BC440	sh     v0, $0002(a1)
800BC444	mult   a0, a3
800BC448	sra    v0, t4, $0b
800BC44C	sh     v0, $000c(a1)
800BC450	sh     v0, $0004(a1)
800BC454	sra    v0, t6, $0b
800BC458	sh     v1, $0010(a1)
800BC45C	sh     v0, $000e(a1)
800BC460	sh     v0, $000a(a1)
800BC464	sra    v0, t5, $0c
800BC468	sw     v0, $0014(a1)
800BC46C	sra    v0, a2, $0c
800BC470	sw     v0, $0018(a1)
800BC474	mflo   v1
800BC478	sra    v0, v1, $0c
800BC47C	sw     v0, $001c(a1)
800BC480	lw     t4, $0000(a1)
800BC484	lw     t5, $0004(a1)
800BC488	ctc2   t4,vxy0
800BC48C	ctc2   t5,vz0
800BC490	lw     t4, $0008(a1)
800BC494	lw     t5, $000c(a1)
800BC498	lw     t6, $0010(a1)
800BC49C	ctc2   t4,vxy1
800BC4A0	ctc2   t5,vz1
800BC4A4	ctc2   t6,vxy2
800BC4A8	lw     v0, $0060(t0)
800BC4AC	nop
800BC4B0	addiu  v0, v0, $0024
800BC4B4	lhu    t4, $0000(v0)
800BC4B8	lhu    t5, $0006(v0)
800BC4BC	lhu    t6, $000c(v0)
800BC4C0	mtc2   t4,l13l21
800BC4C4	mtc2   t5,l22l23
800BC4C8	mtc2   t6,l31l32
800BC4CC	nop
800BC4D0	nop
800BC4D4	gte_func18t1,dqb
800BC4D8	addiu  v0, t0, $0024
800BC4DC	mfc2   t4,l13l21
800BC4E0	mfc2   t5,l22l23
800BC4E4	mfc2   t6,l31l32
800BC4E8	sh     t4, $0000(v0)
800BC4EC	sh     t5, $0006(v0)
800BC4F0	sh     t6, $000c(v0)
800BC4F4	lw     v0, $0060(t0)
800BC4F8	nop
800BC4FC	addiu  v0, v0, $0026
800BC500	lhu    t4, $0000(v0)
800BC504	lhu    t5, $0006(v0)
800BC508	lhu    t6, $000c(v0)
800BC50C	mtc2   t4,l13l21
800BC510	mtc2   t5,l22l23
800BC514	mtc2   t6,l31l32
800BC518	nop
800BC51C	nop
800BC520	gte_func18t1,dqb
800BC524	addiu  v0, t0, $0026
800BC528	mfc2   t4,l13l21
800BC52C	mfc2   t5,l22l23
800BC530	mfc2   t6,l31l32
800BC534	sh     t4, $0000(v0)
800BC538	sh     t5, $0006(v0)
800BC53C	sh     t6, $000c(v0)
800BC540	lw     v0, $0060(t0)
800BC544	nop
800BC548	addiu  v0, v0, $0028
800BC54C	lhu    t4, $0000(v0)
800BC550	lhu    t5, $0006(v0)
800BC554	lhu    t6, $000c(v0)
800BC558	mtc2   t4,l13l21
800BC55C	mtc2   t5,l22l23
800BC560	mtc2   t6,l31l32
800BC564	nop
800BC568	nop
800BC56C	gte_func18t1,dqb
800BC570	addiu  v0, t0, $0028
800BC574	mfc2   t4,l13l21
800BC578	mfc2   t5,l22l23
800BC57C	mfc2   t6,l31l32
800BC580	sh     t4, $0000(v0)
800BC584	sh     t5, $0006(v0)
800BC588	sh     t6, $000c(v0)
800BC58C	lw     t4, $0014(a1)
800BC590	lw     t5, $0018(a1)
800BC594	ctc2   t4,vz2
800BC598	lw     t6, $001c(a1)
800BC59C	ctc2   t5,rgb
800BC5A0	ctc2   t6,otz
800BC5A4	lw     v0, $0060(t0)
800BC5A8	nop
800BC5AC	addiu  v0, v0, $0038
800BC5B0	lhu    t5, $0004(v0)
800BC5B4	lhu    t4, $0000(v0)
800BC5B8	sll    t5, t5, $10
800BC5BC	or     t4, t4, t5
800BC5C0	mtc2   t4,r11r12
800BC5C4	lwc2   at, $0008(v0)
800BC5C8	nop
800BC5CC	nop
800BC5D0	gte_func18t0,r11r12
800BC5D4	addiu  v0, t0, $0038
800BC5D8	swc2   t9, $0000(v0)
800BC5DC	swc2   k0, $0004(v0)
800BC5E0	swc2   k1, $0008(v0)
800BC5E4	lw     v0, $0060(t0)
800BC5E8	nop
800BC5EC	lw     v0, $000c(v0)
800BC5F0	nop
800BC5F4	sw     v0, $000c(t0)

Lbc5f8:	; 800BC5F8
800BC5F8	jr     ra 
800BC5FC	nop


funcbc600:	; 800BC600
800BC600	lui    v0, $8006
800BC604	lw     v0, $794c(v0)
800BC608	addiu  sp, sp, $ffe0 (=-$20)
800BC60C	sw     s4, $0018(sp)
800BC610	sw     s3, $0014(sp)
800BC614	sw     s2, $0010(sp)
800BC618	sw     s1, $000c(sp)
800BC61C	sw     s0, $0008(sp)
800BC620	lw     v0, $001c(v0)
800BC624	addu   a2, a0, zero
800BC628	lbu    a0, $0008(v0)
800BC62C	andi   a1, a1, $00ff
800BC630	sll    v1, a0, $02
800BC634	addu   v0, v0, v1
800BC638	lw     s2, $0010(v0)
800BC63C	sll    v0, a1, $02
800BC640	lw     v1, $0008(a2)
800BC644	addu   v0, v0, a1
800BC648	lw     v1, $0010(v1)
800BC64C	sll    v0, v0, $03
800BC650	beq    a0, zero, Lbc67c [$800bc67c]
800BC654	addu   s4, v1, v0
800BC658	sll    v0, a1, $01
800BC65C	addu   v0, v0, a1
800BC660	lw     v1, $0044(a2)
800BC664	sll    v0, v0, $02
800BC668	addu   v0, v0, v1
800BC66C	lhu    v1, $0000(s4)
800BC670	lw     v0, $0004(v0)
800BC674	j      Lbc694 [$800bc694]
800BC678	addu   v0, v0, v1

Lbc67c:	; 800BC67C
800BC67C	sll    v0, a1, $01
800BC680	addu   v0, v0, a1
800BC684	lw     v1, $0044(a2)
800BC688	sll    v0, v0, $02
800BC68C	addu   v0, v0, v1
800BC690	lw     v0, $0004(v0)

Lbc694:	; 800BC694
800BC694	nop
800BC698	addu   t1, v0, zero
800BC69C	addu   t2, zero, zero
800BC6A0	lhu    t8, $0002(s4)
800BC6A4	lb     v0, $0013(s4)
800BC6A8	lw     t7, $001c(s4)
800BC6AC	sll    v0, v0, $02
800BC6B0	beq    t8, zero, Lbc800 [$800bc800]
800BC6B4	subu   s2, s2, v0
800BC6B8	lui    v0, $8007
800BC6BC	addiu  s1, v0, $11a8
800BC6C0	lui    s3, $ff00
800BC6C4	lui    v0, $8007
800BC6C8	addiu  s0, v0, $0520
800BC6CC	lui    t9, $00ff
800BC6D0	ori    t9, t9, $ffff
800BC6D4	addiu  t5, t1, $0020
800BC6D8	addiu  t6, t7, $0015

loopbc6dc:	; 800BC6DC
800BC6DC	lw     a0, $0000(t7)
800BC6E0	lw     v1, $ffef(t6)
800BC6E4	srl    a2, a0, $10
800BC6E8	srl    a1, v1, $10
800BC6EC	andi   a0, a0, $ffff
800BC6F0	andi   v1, v1, $ffff
800BC6F4	sll    t4, a0, $02
800BC6F8	addu   v0, t4, s1
800BC6FC	sll    a0, a2, $02
800BC700	lw     t0, $0000(v0)
800BC704	addu   v0, a0, s1
800BC708	sll    t3, v1, $02
800BC70C	addu   v1, t3, s1
800BC710	lw     a3, $0000(v0)
800BC714	lbu    v0, $0000(t6)
800BC718	lw     a2, $0000(v1)
800BC71C	andi   v0, v0, $0002
800BC720	bne    v0, zero, Lbc75c [$800bc75c]
800BC724	addiu  t2, t2, $0001
800BC728	mtc2   t0,l33
800BC72C	mtc2   a2,gbk
800BC730	mtc2   a3,rbk
800BC734	lw     v0, $0000(t1)
800BC738	nop
800BC73C	and    v0, v0, s3
800BC740	sw     v0, $0000(t1)
800BC744	gte_func26zero,r11r12
800BC748	swc2   t8, $0000(sp)
800BC74C	lw     v0, $0000(sp)
800BC750	nop
800BC754	bgez   v0, Lbc7e8 [$800bc7e8]

Lbc758:	; 800BC758
800BC758	nop

Lbc75c:	; 800BC75C
800BC75C	addu   v0, t4, s0
800BC760	addu   a0, a0, s0

Lbc764:	; 800BC764
800BC764	lw     v1, $0000(v0)
800BC768	lw     v0, $0000(a0)
800BC76C	addu   a0, t3, s0
800BC770	sll    a1, a1, $02
800BC774	lw     a0, $0000(a0)
800BC778	addu   v1, v1, v0
800BC77C	addu   v0, a1, s0
800BC780	addu   v1, v1, a0
800BC784	lw     v0, $0000(v0)
800BC788	addu   a1, a1, s1

funcbc78c:	; 800BC78C
800BC78C	addu   v1, v1, v0
800BC790	sra    v1, v1, $04
800BC794	sw     v1, $0004(sp)
800BC798	sw     t0, $ffe8(t5)
800BC79C	sw     a3, $fff0(t5)

Lbc7a0:	; 800BC7A0
800BC7A0	sw     a2, $fff8(t5)
800BC7A4	lw     v0, $0000(a1)
800BC7A8	nop
800BC7AC	sw     v0, $0000(t5)
800BC7B0	lw     a0, $0004(sp)
800BC7B4	lw     v1, $0000(t1)
800BC7B8	sll    a0, a0, $02
800BC7BC	addu   a0, a0, s2
800BC7C0	lw     v0, $0000(a0)
800BC7C4	and    v1, v1, s3
800BC7C8	and    v0, v0, t9
800BC7CC	or     v1, v1, v0
800BC7D0	sw     v1, $0000(t1)
800BC7D4	lw     v0, $0000(a0)
800BC7D8	and    v1, t1, t9
800BC7DC	and    v0, v0, s3
800BC7E0	or     v0, v0, v1
800BC7E4	sw     v0, $0000(a0)

Lbc7e8:	; 800BC7E8
800BC7E8	addiu  t6, t6, $0018
800BC7EC	addiu  t7, t7, $0018
800BC7F0	addiu  t5, t5, $0028
800BC7F4	sltu   v0, t2, t8
800BC7F8	bne    v0, zero, loopbc6dc [$800bc6dc]
800BC7FC	addiu  t1, t1, $0028

Lbc800:	; 800BC800
800BC800	lhu    t8, $0004(s4)
800BC804	addu   t6, t7, zero
800BC808	addu   a1, t1, zero
800BC80C	beq    t8, zero, Lbc944 [$800bc944]
800BC810	addu   t2, zero, zero
800BC814	lui    v0, $8007
800BC818	addiu  t9, v0, $11a8
800BC81C	lui    s1, $ff00
800BC820	lui    v0, $8007
800BC824	addiu  s0, v0, $0520
800BC828	lui    t7, $00ff

Lbc82c:	; 800BC82C
800BC82C	ori    t7, t7, $ffff
800BC830	addiu  t4, a1, $0018
800BC834	addiu  t5, t6, $0012

loopbc838:	; 800BC838
800BC838	lw     a0, $0000(t6)
800BC83C	lhu    v1, $fff2(t5)
800BC840	srl    a2, a0, $10
800BC844	andi   a0, a0, $ffff
800BC848	sll    v0, a0, $02
800BC84C	addu   v0, v0, t9
800BC850	sll    t3, a2, $02
800BC854	lw     t0, $0000(v0)
800BC858	addu   v0, t3, t9
800BC85C	sll    t1, v1, $02
800BC860	addu   v1, t1, t9
800BC864	lw     a3, $0000(v0)
800BC868	lbu    v0, $0000(t5)
800BC86C	lw     a2, $0000(v1)
800BC870	andi   v0, v0, $0002
800BC874	bne    v0, zero, Lbc8b0 [$800bc8b0]
800BC878	addiu  t2, t2, $0001
800BC87C	mtc2   t0,l33
800BC880	mtc2   a2,gbk
800BC884	mtc2   a3,rbk
800BC888	lw     v0, $0000(a1)
800BC88C	nop
800BC890	and    v0, v0, s1
800BC894	sw     v0, $0000(a1)
800BC898	gte_func26zero,r11r12
800BC89C	swc2   t8, $0000(sp)
800BC8A0	lw     v0, $0000(sp)
800BC8A4	nop
800BC8A8	bgez   v0, Lbc92c [$800bc92c]
800BC8AC	nop

Lbc8b0:	; 800BC8B0
800BC8B0	andi   v1, a0, $ffff
800BC8B4	sll    v1, v1, $02
800BC8B8	addu   v1, v1, s0
800BC8BC	addu   a0, t3, s0
800BC8C0	addu   v0, t1, s0
800BC8C4	lw     v1, $0000(v1)
800BC8C8	lw     a0, $0000(a0)
800BC8CC	lw     v0, $0000(v0)
800BC8D0	mtc2   v1,lr3lg1
800BC8D4	mtc2   a0,lg2lg3
800BC8D8	mtc2   v0,lb1lb2
800BC8DC	sw     t0, $fff0(t4)
800BC8E0	sw     a3, $fff8(t4)
800BC8E4	gte_func26t8,r11r12
800BC8E8	addiu  v0, sp, $0004
800BC8EC	sw     a2, $0000(t4)
800BC8F0	swc2   a3, $0000(v0)
800BC8F4	lw     a0, $0004(sp)
800BC8F8	lw     v1, $0000(a1)
800BC8FC	sll    a0, a0, $02
800BC900	addu   a0, a0, s2
800BC904	lw     v0, $0000(a0)
800BC908	and    v1, v1, s1
800BC90C	and    v0, v0, t7
800BC910	or     v1, v1, v0
800BC914	sw     v1, $0000(a1)
800BC918	lw     v0, $0000(a0)
800BC91C	and    v1, a1, t7
800BC920	and    v0, v0, s1
800BC924	or     v0, v0, v1
800BC928	sw     v0, $0000(a0)

Lbc92c:	; 800BC92C
800BC92C	addiu  t5, t5, $0014
800BC930	addiu  t6, t6, $0014
800BC934	addiu  t4, t4, $0020
800BC938	sltu   v0, t2, t8
800BC93C	bne    v0, zero, loopbc838 [$800bc838]
800BC940	addiu  a1, a1, $0020

Lbc944:	; 800BC944
800BC944	lhu    t8, $0006(s4)
800BC948	addu   t7, t6, zero
800BC94C	addu   t1, a1, zero
800BC950	beq    t8, zero, Lbcaa4 [$800bcaa4]
800BC954	addu   t2, zero, zero
800BC958	lui    v0, $8007
800BC95C	addiu  s1, v0, $11a8
800BC960	lui    s3, $ff00
800BC964	lui    v0, $8007
800BC968	addiu  s0, v0, $0520
800BC96C	lui    t9, $00ff
800BC970	ori    t9, t9, $ffff
800BC974	addiu  t5, t1, $002c
800BC978	addiu  t6, t7, $001c

loopbc97c:	; 800BC97C
800BC97C	lw     a0, $0000(t7)
800BC980	lw     v1, $ffe8(t6)
800BC984	srl    a2, a0, $10
800BC988	srl    a1, v1, $10
800BC98C	andi   a0, a0, $ffff
800BC990	andi   v1, v1, $ffff
800BC994	sll    t4, a0, $02
800BC998	addu   v0, t4, s1
800BC99C	sll    a0, a2, $02
800BC9A0	lw     t0, $0000(v0)
800BC9A4	addu   v0, a0, s1
800BC9A8	sll    t3, v1, $02
800BC9AC	addu   v1, t3, s1
800BC9B0	lw     a3, $0000(v0)
800BC9B4	lbu    v0, $0000(t6)
800BC9B8	lw     a2, $0000(v1)
800BC9BC	andi   v0, v0, $0002
800BC9C0	bne    v0, zero, Lbc9fc [$800bc9fc]
800BC9C4	addiu  t2, t2, $0001
800BC9C8	mtc2   t0,l33
800BC9CC	mtc2   a2,gbk
800BC9D0	mtc2   a3,rbk
800BC9D4	lw     v0, $0000(t1)
800BC9D8	nop
800BC9DC	and    v0, v0, s3
800BC9E0	sw     v0, $0000(t1)
800BC9E4	gte_func26zero,r11r12
800BC9E8	swc2   t8, $0000(sp)
800BC9EC	lw     v0, $0000(sp)
800BC9F0	nop
800BC9F4	bgez   v0, Lbca8c [$800bca8c]
800BC9F8	nop

Lbc9fc:	; 800BC9FC
800BC9FC	addu   v0, t4, s0
800BCA00	addu   a0, a0, s0
800BCA04	lw     v1, $0000(v0)
800BCA08	lw     v0, $0000(a0)
800BCA0C	addu   a0, t3, s0
800BCA10	sll    a1, a1, $02
800BCA14	lw     a0, $0000(a0)
800BCA18	addu   v1, v1, v0
800BCA1C	addu   v0, a1, s0
800BCA20	addu   v1, v1, a0
800BCA24	lw     v0, $0000(v0)
800BCA28	addu   a1, a1, s1
800BCA2C	addu   v1, v1, v0
800BCA30	sw     v1, $0004(sp)
800BCA34	sw     t0, $ffdc(t5)
800BCA38	sw     a3, $ffe8(t5)
800BCA3C	sw     a2, $fff4(t5)
800BCA40	lw     v0, $0000(a1)
800BCA44	nop
800BCA48	sw     v0, $0000(t5)
800BCA4C	lw     a1, $0004(sp)
800BCA50	lw     v1, $0000(t1)
800BCA54	sra    a1, a1, $04
800BCA58	sll    a0, a1, $02
800BCA5C	addu   a0, a0, s2
800BCA60	lw     v0, $0000(a0)
800BCA64	and    v1, v1, s3
800BCA68	and    v0, v0, t9
800BCA6C	or     v1, v1, v0
800BCA70	sw     v1, $0000(t1)
800BCA74	lw     v1, $0000(a0)

Lbca78:	; 800BCA78
800BCA78	and    v0, t1, t9
800BCA7C	sw     a1, $0004(sp)
800BCA80	and    v1, v1, s3
800BCA84	or     v1, v1, v0
800BCA88	sw     v1, $0000(a0)

Lbca8c:	; 800BCA8C
800BCA8C	addiu  t6, t6, $0020
800BCA90	addiu  t7, t7, $0020

Lbca94:	; 800BCA94
800BCA94	addiu  t5, t5, $0034
800BCA98	sltu   v0, t2, t8
800BCA9C	bne    v0, zero, loopbc97c [$800bc97c]
800BCAA0	addiu  t1, t1, $0034

Lbcaa4:	; 800BCAA4
800BCAA4	lhu    t8, $0008(s4)
800BCAA8	addu   t6, t7, zero
800BCAAC	addu   a1, t1, zero
800BCAB0	beq    t8, zero, Lbcbe0 [$800bcbe0]
800BCAB4	addu   t2, zero, zero
800BCAB8	lui    v0, $8007
800BCABC	addiu  t9, v0, $11a8
800BCAC0	lui    s1, $ff00
800BCAC4	lui    v0, $8007
800BCAC8	addiu  s0, v0, $0520
800BCACC	lui    t7, $00ff
800BCAD0	ori    t7, t7, $ffff
800BCAD4	addiu  t4, a1, $0020
800BCAD8	addiu  t5, t6, $000f

loopbcadc:	; 800BCADC
800BCADC	lw     a0, $0000(t6)
800BCAE0	lhu    v1, $fff5(t5)
800BCAE4	srl    a2, a0, $10
800BCAE8	andi   a0, a0, $ffff
800BCAEC	sll    a0, a0, $02
800BCAF0	addu   v0, a0, t9
800BCAF4	sll    t3, a2, $02
800BCAF8	lw     t0, $0000(v0)
800BCAFC	addu   v0, t3, t9
800BCB00	sll    t1, v1, $02
800BCB04	addu   v1, t1, t9
800BCB08	lw     a3, $0000(v0)
800BCB0C	lbu    v0, $0000(t5)
800BCB10	lw     a2, $0000(v1)
800BCB14	andi   v0, v0, $0002
800BCB18	bne    v0, zero, Lbcb54 [$800bcb54]
800BCB1C	addiu  t2, t2, $0001

Lbcb20:	; 800BCB20
800BCB20	mtc2   t0,l33
800BCB24	mtc2   a2,gbk
800BCB28	mtc2   a3,rbk
800BCB2C	lw     v0, $0000(a1)
800BCB30	nop
800BCB34	and    v0, v0, s1
800BCB38	sw     v0, $0000(a1)
800BCB3C	gte_func26zero,r11r12
800BCB40	swc2   t8, $0000(sp)
800BCB44	lw     v0, $0000(sp)
800BCB48	nop
800BCB4C	bgez   v0, Lbcbc8 [$800bcbc8]
800BCB50	nop

Lbcb54:	; 800BCB54
800BCB54	addu   a0, a0, s0
800BCB58	addu   v1, t3, s0
800BCB5C	addu   v0, t1, s0
800BCB60	lw     a0, $0000(a0)
800BCB64	lw     v1, $0000(v1)
800BCB68	lw     v0, $0000(v0)
800BCB6C	mtc2   a0,lr3lg1
800BCB70	mtc2   v1,lg2lg3
800BCB74	mtc2   v0,lb1lb2
800BCB78	sw     t0, $ffe8(t4)
800BCB7C	sw     a3, $fff4(t4)
800BCB80	gte_func26t8,r11r12
800BCB84	addiu  v0, sp, $0004
800BCB88	sw     a2, $0000(t4)
800BCB8C	swc2   a3, $0000(v0)
800BCB90	lw     a0, $0004(sp)
800BCB94	lw     v1, $0000(a1)
800BCB98	sll    a0, a0, $02
800BCB9C	addu   a0, a0, s2
800BCBA0	lw     v0, $0000(a0)
800BCBA4	and    v1, v1, s1
800BCBA8	and    v0, v0, t7
800BCBAC	or     v1, v1, v0
800BCBB0	sw     v1, $0000(a1)
800BCBB4	lw     v0, $0000(a0)
800BCBB8	and    v1, a1, t7
800BCBBC	and    v0, v0, s1
800BCBC0	or     v0, v0, v1
800BCBC4	sw     v0, $0000(a0)

Lbcbc8:	; 800BCBC8
800BCBC8	addiu  t5, t5, $0018
800BCBCC	addiu  t6, t6, $0018
800BCBD0	addiu  t4, t4, $0028
800BCBD4	sltu   v0, t2, t8
800BCBD8	bne    v0, zero, loopbcadc [$800bcadc]
800BCBDC	addiu  a1, a1, $0028

Lbcbe0:	; 800BCBE0
800BCBE0	lhu    t8, $000a(s4)
800BCBE4	addu   t7, t6, zero
800BCBE8	addu   t1, a1, zero
800BCBEC	beq    t8, zero, Lbcd3c [$800bcd3c]
800BCBF0	addu   t2, zero, zero
800BCBF4	lui    v0, $8007
800BCBF8	addiu  s1, v0, $11a8
800BCBFC	lui    s3, $ff00
800BCC00	lui    v0, $8007
800BCC04	addiu  s0, v0, $0520
800BCC08	lui    t9, $00ff
800BCC0C	ori    t9, t9, $ffff
800BCC10	addiu  t5, t1, $0020
800BCC14	addiu  t6, t7, $0014

loopbcc18:	; 800BCC18
800BCC18	lw     a0, $0000(t7)
800BCC1C	lw     v1, $fff0(t6)
800BCC20	srl    a2, a0, $10
800BCC24	srl    a1, v1, $10
800BCC28	andi   a0, a0, $ffff

Lbcc2c:	; 800BCC2C
800BCC2C	andi   v1, v1, $ffff
800BCC30	sll    t4, a0, $02
800BCC34	addu   v0, t4, s1
800BCC38	sll    a0, a2, $02

Lbcc3c:	; 800BCC3C
800BCC3C	lw     t0, $0000(v0)

Lbcc40:	; 800BCC40
800BCC40	addu   v0, a0, s1
800BCC44	sll    t3, v1, $02
800BCC48	addu   v1, t3, s1
800BCC4C	lw     a3, $0000(v0)
800BCC50	lbu    v0, $0000(t6)
800BCC54	lw     a2, $0000(v1)
800BCC58	andi   v0, v0, $0002
800BCC5C	bne    v0, zero, Lbcc98 [$800bcc98]
800BCC60	addiu  t2, t2, $0001

funcbcc64:	; 800BCC64
800BCC64	mtc2   t0,l33
800BCC68	mtc2   a2,gbk
800BCC6C	mtc2   a3,rbk
800BCC70	lw     v0, $0000(t1)
800BCC74	nop
800BCC78	and    v0, v0, s3
800BCC7C	sw     v0, $0000(t1)
800BCC80	gte_func26zero,r11r12
800BCC84	swc2   t8, $0000(sp)
800BCC88	lw     v0, $0000(sp)
800BCC8C	nop
800BCC90	bgez   v0, Lbcd24 [$800bcd24]
800BCC94	nop

Lbcc98:	; 800BCC98
800BCC98	addu   v0, t4, s0
800BCC9C	addu   a0, a0, s0
800BCCA0	lw     v1, $0000(v0)
800BCCA4	lw     v0, $0000(a0)
800BCCA8	addu   a0, t3, s0
800BCCAC	sll    a1, a1, $02
800BCCB0	lw     a0, $0000(a0)
800BCCB4	addu   v1, v1, v0
800BCCB8	addu   v0, a1, s0
800BCCBC	addu   v1, v1, a0
800BCCC0	lw     v0, $0000(v0)
800BCCC4	addu   a1, a1, s1
800BCCC8	addu   v1, v1, v0
800BCCCC	sra    v1, v1, $04
800BCCD0	sw     v1, $0004(sp)
800BCCD4	sw     t0, $ffe8(t5)
800BCCD8	sw     a3, $fff0(t5)
800BCCDC	sw     a2, $fff8(t5)
800BCCE0	lw     v0, $0000(a1)
800BCCE4	nop
800BCCE8	sw     v0, $0000(t5)
800BCCEC	lw     a0, $0004(sp)
800BCCF0	lw     v1, $0000(t1)
800BCCF4	sll    a0, a0, $02
800BCCF8	addu   a0, a0, s2
800BCCFC	lw     v0, $0000(a0)
800BCD00	and    v1, v1, s3
800BCD04	and    v0, v0, t9
800BCD08	or     v1, v1, v0
800BCD0C	sw     v1, $0000(t1)
800BCD10	lw     v0, $0000(a0)
800BCD14	and    v1, t1, t9
800BCD18	and    v0, v0, s3
800BCD1C	or     v0, v0, v1
800BCD20	sw     v0, $0000(a0)

Lbcd24:	; 800BCD24
800BCD24	addiu  t6, t6, $0018
800BCD28	addiu  t7, t7, $0018
800BCD2C	addiu  t5, t5, $0024
800BCD30	sltu   v0, t2, t8
800BCD34	bne    v0, zero, loopbcc18 [$800bcc18]
800BCD38	addiu  t1, t1, $0024

Lbcd3c:	; 800BCD3C
800BCD3C	lhu    t8, $000c(s4)
800BCD40	addu   t6, t7, zero
800BCD44	addu   a1, t1, zero
800BCD48	beq    t8, zero, Lbce78 [$800bce78]
800BCD4C	addu   t2, zero, zero
800BCD50	lui    v0, $8007
800BCD54	addiu  t9, v0, $11a8
800BCD58	lui    s1, $ff00
800BCD5C	lui    v0, $8007
800BCD60	addiu  s0, v0, $0520
800BCD64	lui    t7, $00ff
800BCD68	ori    t7, t7, $ffff
800BCD6C	addiu  t4, a1, $0018
800BCD70	addiu  t5, t6, $0013

loopbcd74:	; 800BCD74
800BCD74	lw     a0, $0000(t6)
800BCD78	lhu    v1, $fff1(t5)
800BCD7C	srl    a2, a0, $10
800BCD80	andi   a0, a0, $ffff
800BCD84	sll    a0, a0, $02
800BCD88	addu   v0, a0, t9
800BCD8C	sll    t3, a2, $02
800BCD90	lw     t0, $0000(v0)
800BCD94	addu   v0, t3, t9
800BCD98	sll    t1, v1, $02
800BCD9C	addu   v1, t1, t9
800BCDA0	lw     a3, $0000(v0)
800BCDA4	lbu    v0, $0000(t5)

Lbcda8:	; 800BCDA8
800BCDA8	lw     a2, $0000(v1)

Lbcdac:	; 800BCDAC
800BCDAC	andi   v0, v0, $0002

Lbcdb0:	; 800BCDB0
800BCDB0	bne    v0, zero, Lbcdec [$800bcdec]
800BCDB4	addiu  t2, t2, $0001
800BCDB8	mtc2   t0,l33

funcbcdbc:	; 800BCDBC
800BCDBC	mtc2   a2,gbk
800BCDC0	mtc2   a3,rbk
800BCDC4	lw     v0, $0000(a1)
800BCDC8	nop
800BCDCC	and    v0, v0, s1
800BCDD0	sw     v0, $0000(a1)
800BCDD4	gte_func26zero,r11r12
800BCDD8	swc2   t8, $0000(sp)
800BCDDC	lw     v0, $0000(sp)
800BCDE0	nop
800BCDE4	bgez   v0, Lbce60 [$800bce60]
800BCDE8	nop

Lbcdec:	; 800BCDEC
800BCDEC	addu   a0, a0, s0
800BCDF0	addu   v1, t3, s0
800BCDF4	addu   v0, t1, s0
800BCDF8	lw     a0, $0000(a0)
800BCDFC	lw     v1, $0000(v1)
800BCE00	lw     v0, $0000(v0)
800BCE04	mtc2   a0,lr3lg1
800BCE08	mtc2   v1,lg2lg3
800BCE0C	mtc2   v0,lb1lb2
800BCE10	sw     t0, $fff0(t4)
800BCE14	sw     a3, $fff8(t4)
800BCE18	gte_func26t8,r11r12
800BCE1C	addiu  v0, sp, $0004
800BCE20	sw     a2, $0000(t4)
800BCE24	swc2   a3, $0000(v0)
800BCE28	lw     a0, $0004(sp)
800BCE2C	lw     v1, $0000(a1)

Lbce30:	; 800BCE30
800BCE30	sll    a0, a0, $02
800BCE34	addu   a0, a0, s2
800BCE38	lw     v0, $0000(a0)
800BCE3C	and    v1, v1, s1
800BCE40	and    v0, v0, t7
800BCE44	or     v1, v1, v0
800BCE48	sw     v1, $0000(a1)
800BCE4C	lw     v0, $0000(a0)
800BCE50	and    v1, a1, t7
800BCE54	and    v0, v0, s1
800BCE58	or     v0, v0, v1
800BCE5C	sw     v0, $0000(a0)

Lbce60:	; 800BCE60
800BCE60	addiu  t5, t5, $0014
800BCE64	addiu  t6, t6, $0014
800BCE68	addiu  t4, t4, $001c
800BCE6C	sltu   v0, t2, t8
800BCE70	bne    v0, zero, loopbcd74 [$800bcd74]
800BCE74	addiu  a1, a1, $001c

Lbce78:	; 800BCE78
800BCE78	lhu    t8, $000e(s4)
800BCE7C	addu   t7, t6, zero
800BCE80	addu   t1, a1, zero
800BCE84	beq    t8, zero, Lbcfd8 [$800bcfd8]
800BCE88	addu   t2, zero, zero
800BCE8C	lui    v0, $8007
800BCE90	addiu  s1, v0, $11a8
800BCE94	lui    s3, $ff00
800BCE98	lui    v0, $8007
800BCE9C	addiu  s0, v0, $0520
800BCEA0	lui    t9, $00ff
800BCEA4	ori    t9, t9, $ffff
800BCEA8	addiu  t5, t1, $0014
800BCEAC	addiu  t6, t7, $000d

loopbceb0:	; 800BCEB0
800BCEB0	lw     a0, $0000(t7)
800BCEB4	lw     v1, $fff7(t6)
800BCEB8	srl    a2, a0, $10
800BCEBC	srl    a1, v1, $10
800BCEC0	andi   a0, a0, $ffff
800BCEC4	andi   v1, v1, $ffff
800BCEC8	sll    t4, a0, $02
800BCECC	addu   v0, t4, s1
800BCED0	sll    a0, a2, $02
800BCED4	lw     t0, $0000(v0)
800BCED8	addu   v0, a0, s1
800BCEDC	sll    t3, v1, $02
800BCEE0	addu   v1, t3, s1
800BCEE4	lw     a3, $0000(v0)
800BCEE8	lbu    v0, $0000(t6)
800BCEEC	lw     a2, $0000(v1)

funcbcef0:	; 800BCEF0
800BCEF0	andi   v0, v0, $0002
800BCEF4	bne    v0, zero, Lbcf30 [$800bcf30]
800BCEF8	addiu  t2, t2, $0001
800BCEFC	mtc2   t0,l33
800BCF00	mtc2   a2,gbk
800BCF04	mtc2   a3,rbk
800BCF08	lw     v0, $0000(t1)
800BCF0C	nop
800BCF10	and    v0, v0, s3
800BCF14	sw     v0, $0000(t1)
800BCF18	gte_func26zero,r11r12
800BCF1C	swc2   t8, $0000(sp)
800BCF20	lw     v0, $0000(sp)
800BCF24	nop
800BCF28	bgez   v0, Lbcfc0 [$800bcfc0]
800BCF2C	nop

Lbcf30:	; 800BCF30
800BCF30	addu   v0, t4, s0
800BCF34	addu   a0, a0, s0
800BCF38	lw     v1, $0000(v0)
800BCF3C	lw     v0, $0000(a0)
800BCF40	addu   a0, t3, s0
800BCF44	sll    a1, a1, $02
800BCF48	lw     a0, $0000(a0)
800BCF4C	addu   v1, v1, v0
800BCF50	addu   v0, a1, s0
800BCF54	addu   v1, v1, a0
800BCF58	lw     v0, $0000(v0)
800BCF5C	addu   a1, a1, s1
800BCF60	addu   v1, v1, v0
800BCF64	sw     v1, $0004(sp)
800BCF68	sw     t0, $fff4(t5)
800BCF6C	sw     a3, $fff8(t5)
800BCF70	sw     a2, $fffc(t5)
800BCF74	lw     v0, $0000(a1)
800BCF78	nop
800BCF7C	sw     v0, $0000(t5)
800BCF80	lw     a1, $0004(sp)
800BCF84	lw     v1, $0000(t1)
800BCF88	sra    a1, a1, $04
800BCF8C	sll    a0, a1, $02
800BCF90	addu   a0, a0, s2
800BCF94	lw     v0, $0000(a0)
800BCF98	and    v1, v1, s3
800BCF9C	and    v0, v0, t9
800BCFA0	or     v1, v1, v0
800BCFA4	sw     v1, $0000(t1)
800BCFA8	lw     v1, $0000(a0)
800BCFAC	and    v0, t1, t9
800BCFB0	sw     a1, $0004(sp)
800BCFB4	and    v1, v1, s3
800BCFB8	or     v1, v1, v0
800BCFBC	sw     v1, $0000(a0)

Lbcfc0:	; 800BCFC0
800BCFC0	addiu  t6, t6, $0010
800BCFC4	addiu  t7, t7, $0010
800BCFC8	addiu  t5, t5, $0018
800BCFCC	sltu   v0, t2, t8
800BCFD0	bne    v0, zero, loopbceb0 [$800bceb0]

Lbcfd4:	; 800BCFD4
800BCFD4	addiu  t1, t1, $0018

Lbcfd8:	; 800BCFD8
800BCFD8	lhu    t8, $0010(s4)
800BCFDC	addu   t6, t7, zero
800BCFE0	addu   a1, t1, zero
800BCFE4	beq    t8, zero, Lbd114 [$800bd114]
800BCFE8	addu   t2, zero, zero
800BCFEC	lui    v0, $8007
800BCFF0	addiu  t9, v0, $11a8
800BCFF4	lui    s1, $ff00
800BCFF8	lui    v0, $8007
800BCFFC	addiu  s0, v0, $0520
800BD000	lui    t7, $00ff
800BD004	ori    t7, t7, $ffff
800BD008	addiu  t4, a1, $0010
800BD00C	addiu  t5, t6, $000b

loopbd010:	; 800BD010
800BD010	lw     a0, $0000(t6)
800BD014	lhu    v1, $fff9(t5)
800BD018	srl    a2, a0, $10
800BD01C	andi   a0, a0, $ffff
800BD020	sll    a0, a0, $02
800BD024	addu   v0, a0, t9
800BD028	sll    t3, a2, $02
800BD02C	lw     t0, $0000(v0)
800BD030	addu   v0, t3, t9
800BD034	sll    t1, v1, $02
800BD038	addu   v1, t1, t9
800BD03C	lw     a3, $0000(v0)
800BD040	lbu    v0, $0000(t5)
800BD044	lw     a2, $0000(v1)
800BD048	andi   v0, v0, $0002
800BD04C	bne    v0, zero, Lbd088 [$800bd088]
800BD050	addiu  t2, t2, $0001
800BD054	mtc2   t0,l33
800BD058	mtc2   a2,gbk
800BD05C	mtc2   a3,rbk
800BD060	lw     v0, $0000(a1)
800BD064	nop
800BD068	and    v0, v0, s1
800BD06C	sw     v0, $0000(a1)
800BD070	gte_func26zero,r11r12
800BD074	swc2   t8, $0000(sp)
800BD078	lw     v0, $0000(sp)
800BD07C	nop
800BD080	bgez   v0, Lbd0fc [$800bd0fc]
800BD084	nop

Lbd088:	; 800BD088
800BD088	addu   a0, a0, s0
800BD08C	addu   v1, t3, s0
800BD090	addu   v0, t1, s0
800BD094	lw     a0, $0000(a0)
800BD098	lw     v1, $0000(v1)
800BD09C	lw     v0, $0000(v0)
800BD0A0	mtc2   a0,lr3lg1
800BD0A4	mtc2   v1,lg2lg3
800BD0A8	mtc2   v0,lb1lb2
800BD0AC	sw     t0, $fff8(t4)
800BD0B0	sw     a3, $fffc(t4)
800BD0B4	gte_func26t8,r11r12
800BD0B8	addiu  v0, sp, $0004
800BD0BC	sw     a2, $0000(t4)
800BD0C0	swc2   a3, $0000(v0)
800BD0C4	lw     a0, $0004(sp)
800BD0C8	lw     v1, $0000(a1)
800BD0CC	sll    a0, a0, $02
800BD0D0	addu   a0, a0, s2
800BD0D4	lw     v0, $0000(a0)
800BD0D8	and    v1, v1, s1
800BD0DC	and    v0, v0, t7
800BD0E0	or     v1, v1, v0
800BD0E4	sw     v1, $0000(a1)
800BD0E8	lw     v0, $0000(a0)
800BD0EC	and    v1, a1, t7
800BD0F0	and    v0, v0, s1
800BD0F4	or     v0, v0, v1
800BD0F8	sw     v0, $0000(a0)

Lbd0fc:	; 800BD0FC
800BD0FC	addiu  t5, t5, $000c
800BD100	addiu  t6, t6, $000c
800BD104	addiu  t4, t4, $0014
800BD108	sltu   v0, t2, t8
800BD10C	bne    v0, zero, loopbd010 [$800bd010]
800BD110	addiu  a1, a1, $0014

Lbd114:	; 800BD114
800BD114	lw     s4, $0018(sp)
800BD118	lw     s3, $0014(sp)
800BD11C	lw     s2, $0010(sp)
800BD120	lw     s1, $000c(sp)
800BD124	lw     s0, $0008(sp)
800BD128	jr     ra 
800BD12C	addiu  sp, sp, $0020



////////////////////////////////
// funcbd130
800BD130-800BD39C
////////////////////////////////



////////////////////////////////
// funcbd3a0
800BD3A0-800BD4D0
////////////////////////////////



funcbd4d4:	; 800BD4D4
800BD4D4	addiu  sp, sp, $ffd0 (=-$30)
800BD4D8	lui    v0, $800d
800BD4DC	sw     s2, $0018(sp)
800BD4E0	lw     s2, $9db4(v0)
800BD4E4	sw     ra, $0028(sp)
800BD4E8	sw     s5, $0024(sp)
800BD4EC	sw     s4, $0020(sp)
800BD4F0	sw     s3, $001c(sp)
800BD4F4	sw     s1, $0014(sp)
800BD4F8	sw     s0, $0010(sp)
800BD4FC	lw     v0, $000c(s2)
800BD500	addu   s1, zero, zero
800BD504	addu   v1, s2, v0
800BD508	lw     v0, $0010(s2)
800BD50C	lhu    s4, $0004(s2)
800BD510	nop
800BD514	beq    s4, zero, Lbd6fc [$800bd6fc]
800BD518	addu   s3, s2, v0
800BD51C	lui    v0, $800d
800BD520	addiu  s5, v0, $a068 (=-$5f98)
800BD524	addu   s0, v1, zero

Lbd528:	; 800BD528
800BD528	lw     v0, $0004(s0)
800BD52C	lbu    v1, $0000(s0)
800BD530	sra    t0, v0, $08
800BD534	andi   v0, v1, $0002
800BD538	beq    v0, zero, Lbd6ec [$800bd6ec]

funcbd53c:	; 800BD53C
800BD53C	andi   v0, v1, $0014
800BD540	beq    v0, zero, Lbd6ec [$800bd6ec]
800BD544	nop
800BD548	lbu    v1, $0004(s0)
800BD54C	lbu    v0, $0075(s5)
800BD550	nop
800BD554	bne    v1, v0, Lbd6ec [$800bd6ec]
800BD558	addu   a1, zero, zero
800BD55C	lw     v0, $000c(s0)
800BD560	lw     v1, $0000(s0)

Lbd564:	; 800BD564
800BD564	nop
800BD568	srl    a2, v1, $08
800BD56C	beq    a2, zero, Lbd5ac [$800bd5ac]
800BD570	addu   a3, s2, v0
800BD574	addu   a0, a3, zero

loopbd578:	; 800BD578
800BD578	lbu    v1, $0000(a0)
800BD57C	nop
800BD580	sll    v0, v1, $03
800BD584	subu   v0, v0, v1
800BD588	sll    v0, v0, $03
800BD58C	addu   v0, v0, s3
800BD590	lbu    v1, $0000(v0)
800BD594	addiu  a1, a1, $0001
800BD598	andi   v1, v1, $00fd
800BD59C	sb     v1, $0000(v0)

funcbd5a0:	; 800BD5A0
800BD5A0	sltu   v0, a1, a2
800BD5A4	bne    v0, zero, loopbd578 [$800bd578]
800BD5A8	addiu  a0, a0, $0002

Lbd5ac:	; 800BD5AC
800BD5AC	sra    v0, t0, $08
800BD5B0	sll    v0, v0, $01
800BD5B4	addu   a0, v0, a3
800BD5B8	lbu    v1, $0000(a0)
800BD5BC	nop
800BD5C0	sll    v0, v1, $03
800BD5C4	subu   v0, v0, v1
800BD5C8	sll    v0, v0, $03
800BD5CC	addu   v0, v0, s3
800BD5D0	lbu    v1, $0000(v0)
800BD5D4	nop
800BD5D8	ori    v1, v1, $0002
800BD5DC	sb     v1, $0000(v0)
800BD5E0	lb     v0, $0001(a0)
800BD5E4	nop
800BD5E8	bgez   v0, Lbd608 [$800bd608]
800BD5EC	addiu  v0, zero, $0001
800BD5F0	sb     zero, $0001(a0)
800BD5F4	lbu    v1, $0000(s0)
800BD5F8	sh     zero, $000a(s0)
800BD5FC	andi   v1, v1, $00fb
800BD600	j      Lbd700 [$800bd700]
800BD604	sb     v1, $0000(s0)

Lbd608:	; 800BD608
800BD608	lhu    v0, $000a(s0)
800BD60C	nop
800BD610	addiu  v0, v0, $0001
800BD614	sh     v0, $000a(s0)
800BD618	lb     v1, $0001(a0)
800BD61C	andi   v0, v0, $ffff
800BD620	slt    v0, v0, v1
800BD624	bne    v0, zero, Lbd6ec [$800bd6ec]
800BD628	nop
800BD62C	lbu    v1, $0004(s0)
800BD630	lh     v0, $0008(s0)
800BD634	sh     zero, $000a(s0)
800BD638	addu   v0, t0, v0
800BD63C	sll    v0, v0, $08
800BD640	or     v1, v1, v0
800BD644	lw     v0, $0000(s0)
800BD648	sra    a0, v1, $10
800BD64C	srl    a1, v0, $08
800BD650	slt    v0, a0, a1
800BD654	bne    v0, zero, Lbd690 [$800bd690]
800BD658	sw     v1, $0004(s0)
800BD65C	lbu    v0, $0000(s0)
800BD660	nop
800BD664	andi   v0, v0, $0020
800BD668	beq    v0, zero, Lbd688 [$800bd688]
800BD66C	andi   v0, v1, $00ff
800BD670	addiu  v1, a1, $ffff (=-$1)
800BD674	sll    v1, v1, $10
800BD678	or     v0, v0, v1
800BD67C	lh     a1, $0008(s0)
800BD680	j      Lbd6b4 [$800bd6b4]
800BD684	addu   a0, s1, zero

Lbd688:	; 800BD688
800BD688	j      Lbd6dc [$800bd6dc]
800BD68C	sw     v0, $0004(s0)

Lbd690:	; 800BD690
800BD690	bgez   a0, Lbd6ec [$800bd6ec]
800BD694	nop

funcbd698:	; 800BD698
800BD698	lbu    v0, $0000(s0)
800BD69C	nop
800BD6A0	andi   v0, v0, $0020
800BD6A4	beq    v0, zero, Lbd6c8 [$800bd6c8]
800BD6A8	addu   a0, s1, zero
800BD6AC	lh     a1, $0008(s0)
800BD6B0	andi   v0, v1, $00ff

Lbd6b4:	; 800BD6B4
800BD6B4	sw     v0, $0004(s0)
800BD6B8	jal    funcc17f0 [$800c17f0]
800BD6BC	subu   a1, zero, a1
800BD6C0	j      Lbd6dc [$800bd6dc]
800BD6C4	nop

Lbd6c8:	; 800BD6C8
800BD6C8	andi   v1, v1, $00ff
800BD6CC	addiu  v0, a1, $ffff (=-$1)
800BD6D0	sll    v0, v0, $10
800BD6D4	or     v1, v1, v0
800BD6D8	sw     v1, $0004(s0)

Lbd6dc:	; 800BD6DC
800BD6DC	lbu    v0, $0000(s0)
800BD6E0	nop
800BD6E4	andi   v0, v0, $00fb
800BD6E8	sb     v0, $0000(s0)

Lbd6ec:	; 800BD6EC
800BD6EC	addiu  s1, s1, $0001
800BD6F0	sltu   v0, s1, s4
800BD6F4	bne    v0, zero, Lbd528 [$800bd528]
800BD6F8	addiu  s0, s0, $0010

Lbd6fc:	; 800BD6FC
800BD6FC	addiu  v0, zero, $0001

Lbd700:	; 800BD700
800BD700	lw     ra, $0028(sp)
800BD704	lw     s5, $0024(sp)
800BD708	lw     s4, $0020(sp)
800BD70C	lw     s3, $001c(sp)
800BD710	lw     s2, $0018(sp)
800BD714	lw     s1, $0014(sp)
800BD718	lw     s0, $0010(sp)
800BD71C	jr     ra 
800BD720	addiu  sp, sp, $0030



////////////////////////////////
// funcbd724
800BD724-800BD880
////////////////////////////////



funcbd884:	; 800BD884
800BD884	addiu  sp, sp, $ffe0 (=-$20)
800BD888	addu   t4, a1, zero
800BD88C	addu   t5, a3, zero
800BD890	lui    v0, $800d

Lbd894:	; 800BD894
800BD894	lw     v1, $9da4(v0)
800BD898	addiu  v0, v0, $9da4 (=-$625c)
800BD89C	sw     ra, $0018(sp)
800BD8A0	sw     s1, $0014(sp)
800BD8A4	sw     s0, $0010(sp)
800BD8A8	lhu    a1, $0024(a0)
800BD8AC	lhu    a0, $0026(a0)
800BD8B0	lbu    t0, $0000(v1)
800BD8B4	lhu    v1, $000c(t4)
800BD8B8	sll    a3, t0, $02
800BD8BC	addu   a3, a3, v0

funcbd8c0:	; 800BD8C0
800BD8C0	addu   v1, v1, a1
800BD8C4	lhu    v0, $0004(a2)
800BD8C8	lw     s1, $0008(a3)
800BD8CC	addiu  v0, v0, $ff60 (=-$a0)
800BD8D0	subu   t1, v1, v0
800BD8D4	addu   t3, t1, zero
800BD8D8	lhu    v1, $000e(t4)
800BD8DC	lhu    v0, $0006(a2)
800BD8E0	addu   v1, v1, a0
800BD8E4	addiu  v0, v0, $ff90 (=-$70)
800BD8E8	subu   v1, v1, v0
800BD8EC	sll    v0, t1, $10

funcbd8f0:	; 800BD8F0
800BD8F0	blez   v0, Lbd978 [$800bd978]
800BD8F4	addu   t2, v1, zero
800BD8F8	sll    v0, t0, $01
800BD8FC	addu   v0, v0, t0
800BD900	sll    v0, v0, $05
800BD904	addiu  v0, v0, $000c
800BD908	addu   a2, t5, v0
800BD90C	sll    v0, v1, $10
800BD910	bgez   v0, Lbd91c [$800bd91c]
800BD914	addu   a1, v1, zero
800BD918	addu   a1, zero, zero

Lbd91c:	; 800BD91C
800BD91C	lui    a0, $00ff
800BD920	ori    a0, a0, $ffff
800BD924	lw     v1, $0000(a2)
800BD928	addiu  v0, zero, $00e0
800BD92C	sh     a1, $000a(a2)
800BD930	sh     a1, $000e(a2)

funcbd934:	; 800BD934
800BD934	lui    a1, $ff00
800BD938	sh     zero, $0008(a2)

funcbd93c:	; 800BD93C
800BD93C	sh     t1, $000c(a2)
800BD940	sh     zero, $0010(a2)
800BD944	sh     v0, $0012(a2)
800BD948	sh     t1, $0014(a2)
800BD94C	sh     v0, $0016(a2)
800BD950	lw     v0, $001c(s1)
800BD954	and    v1, v1, a1
800BD958	and    v0, v0, a0
800BD95C	or     v1, v1, v0
800BD960	sw     v1, $0000(a2)
800BD964	lw     v0, $001c(s1)
800BD968	and    a0, a2, a0
800BD96C	and    v0, v0, a1
800BD970	or     v0, v0, a0
800BD974	sw     v0, $001c(s1)

Lbd978:	; 800BD978
800BD978	sll    v0, t2, $10
800BD97C	blez   v0, Lbda20 [$800bda20]
800BD980	lui    v0, $800d
800BD984	lhu    v1, $0004(t4)
800BD988	lw     v0, $9da4(v0)
800BD98C	addu   v1, t3, v1
800BD990	addu   a1, v1, zero
800BD994	sll    v1, v1, $10
800BD998	sra    v1, v1, $10
800BD99C	lbu    a0, $0000(v0)
800BD9A0	slti   v1, v1, $0141
800BD9A4	sll    v0, a0, $01
800BD9A8	addu   v0, v0, a0
800BD9AC	sll    v0, v0, $05
800BD9B0	addiu  v0, v0, $000c
800BD9B4	addu   t0, t5, v0
800BD9B8	bne    v1, zero, Lbd9c4 [$800bd9c4]
800BD9BC	addiu  a2, t0, $0018
800BD9C0	addiu  a1, zero, $0140

Lbd9c4:	; 800BD9C4
800BD9C4	addu   a3, t2, zero
800BD9C8	lui    a0, $00ff
800BD9CC	ori    a0, a0, $ffff
800BD9D0	sh     a1, $000c(a2)
800BD9D4	sh     a1, $0014(a2)
800BD9D8	lui    a1, $ff00
800BD9DC	sh     zero, $0008(a2)
800BD9E0	sh     zero, $000a(a2)
800BD9E4	sh     zero, $000e(a2)

Lbd9e8:	; 800BD9E8
800BD9E8	sh     zero, $0010(a2)
800BD9EC	sh     a3, $0012(a2)
800BD9F0	sh     a3, $0016(a2)
800BD9F4	lw     v1, $0018(t0)
800BD9F8	lw     v0, $001c(s1)
800BD9FC	and    v1, v1, a1
800BDA00	and    v0, v0, a0
800BDA04	or     v1, v1, v0
800BDA08	sw     v1, $0018(t0)
800BDA0C	lw     v0, $001c(s1)
800BDA10	and    a0, a2, a0
800BDA14	and    v0, v0, a1
800BDA18	or     v0, v0, a0
800BDA1C	sw     v0, $001c(s1)

Lbda20:	; 800BDA20
800BDA20	sll    v0, t3, $10
800BDA24	lhu    a1, $0004(t4)
800BDA28	sra    v0, v0, $10
800BDA2C	addu   v0, v0, a1
800BDA30	slti   v0, v0, $0140
800BDA34	beq    v0, zero, Lbdae4 [$800bdae4]
800BDA38	lui    v0, $800d
800BDA3C	addu   a1, t3, a1
800BDA40	lhu    v1, $0006(t4)
800BDA44	lw     v0, $9da4(v0)
800BDA48	addu   v1, t2, v1
800BDA4C	addu   a3, v1, zero

Lbda50:	; 800BDA50
800BDA50	sll    v1, v1, $10
800BDA54	sra    v1, v1, $10
800BDA58	lbu    a0, $0000(v0)
800BDA5C	slti   v1, v1, $00e1

funcbda60:	; 800BDA60
800BDA60	sll    v0, a0, $01
800BDA64	addu   v0, v0, a0
800BDA68	sll    v0, v0, $05
800BDA6C	addiu  v0, v0, $000c
800BDA70	addu   t0, t5, v0
800BDA74	addiu  a2, t0, $0030
800BDA78	addiu  v0, zero, $0140
800BDA7C	bne    v1, zero, Lbda88 [$800bda88]
800BDA80	subu   v0, v0, a1
800BDA84	addiu  a3, zero, $00e0

Lbda88:	; 800BDA88
800BDA88	lui    a0, $00ff
800BDA8C	ori    a0, a0, $ffff
800BDA90	addu   v0, a1, v0
800BDA94	sh     a1, $0008(a2)
800BDA98	sh     a1, $0010(a2)
800BDA9C	lui    a1, $ff00
800BDAA0	sh     zero, $000a(a2)
800BDAA4	sh     v0, $000c(a2)
800BDAA8	sh     zero, $000e(a2)
800BDAAC	sh     a3, $0012(a2)
800BDAB0	sh     v0, $0014(a2)
800BDAB4	sh     a3, $0016(a2)
800BDAB8	lw     v1, $0030(t0)
800BDABC	lw     v0, $001c(s1)
800BDAC0	and    v1, v1, a1
800BDAC4	and    v0, v0, a0
800BDAC8	or     v1, v1, v0

funcbdacc:	; 800BDACC
800BDACC	sw     v1, $0030(t0)
800BDAD0	lw     v0, $001c(s1)
800BDAD4	and    a0, a2, a0
800BDAD8	and    v0, v0, a1
800BDADC	or     v0, v0, a0
800BDAE0	sw     v0, $001c(s1)

Lbdae4:	; 800BDAE4
800BDAE4	sll    v0, t2, $10
800BDAE8	lhu    a1, $0006(t4)
800BDAEC	sra    v0, v0, $10
800BDAF0	addu   v0, v0, a1
800BDAF4	slti   v0, v0, $00e0
800BDAF8	beq    v0, zero, Lbdba8 [$800bdba8]
800BDAFC	lui    v0, $800d
800BDB00	lw     v0, $9da4(v0)
800BDB04	nop
800BDB08	lbu    v1, $0000(v0)
800BDB0C	addu   a3, t3, zero
800BDB10	sll    v0, v1, $01
800BDB14	addu   v0, v0, v1
800BDB18	sll    v0, v0, $05
800BDB1C	addiu  v0, v0, $000c

funcbdb20:	; 800BDB20
800BDB20	addu   t0, t5, v0
800BDB24	sll    v0, a3, $10
800BDB28	bgez   v0, Lbdb34 [$800bdb34]
800BDB2C	addiu  a2, t0, $0048
800BDB30	addu   a3, zero, zero

Lbdb34:	; 800BDB34
800BDB34	addu   v0, t2, a1
800BDB38	addu   a1, v0, zero
800BDB3C	sll    v0, v0, $10
800BDB40	bgez   v0, Lbdb4c [$800bdb4c]
800BDB44	lui    a0, $00ff
800BDB48	addu   a1, zero, zero

Lbdb4c:	; 800BDB4C
800BDB4C	ori    a0, a0, $ffff
800BDB50	addiu  v1, zero, $0140
800BDB54	addiu  v0, zero, $00e0
800BDB58	sh     a1, $000a(a2)
800BDB5C	sh     a1, $000e(a2)
800BDB60	lui    a1, $ff00
800BDB64	sh     a3, $0008(a2)
800BDB68	sh     v1, $000c(a2)
800BDB6C	sh     a3, $0010(a2)
800BDB70	sh     v0, $0012(a2)
800BDB74	sh     v1, $0014(a2)
800BDB78	sh     v0, $0016(a2)
800BDB7C	lw     v1, $0048(t0)
800BDB80	lw     v0, $001c(s1)
800BDB84	and    v1, v1, a1
800BDB88	and    v0, v0, a0
800BDB8C	or     v1, v1, v0
800BDB90	sw     v1, $0048(t0)
800BDB94	lw     v0, $001c(s1)
800BDB98	and    a0, a2, a0
800BDB9C	and    v0, v0, a1
800BDBA0	or     v0, v0, a0
800BDBA4	sw     v0, $001c(s1)

Lbdba8:	; 800BDBA8
800BDBA8	lb     a1, $0000(t5)
800BDBAC	nop
800BDBB0	slti   v0, a1, $0004
800BDBB4	beq    v0, zero, Lbdc2c [$800bdc2c]
800BDBB8	addiu  a0, zero, $0002
800BDBBC	lui    v0, $800d

Lbdbc0:	; 800BDBC0
800BDBC0	lw     v0, $9da4(v0)
800BDBC4	addu   a2, zero, zero
800BDBC8	lbu    s0, $0000(v0)
800BDBCC	addu   a3, a2, zero
800BDBD0	sll    s0, s0, $03
800BDBD4	addiu  s0, s0, $00cc
800BDBD8	jal    func50cf8 [$80050cf8]
800BDBDC	addu   s0, t5, s0
800BDBE0	addu   a0, s0, zero
800BDBE4	addiu  a1, zero, $0001
800BDBE8	addu   a2, a1, zero
800BDBEC	jal    func2420c [$8002420c]
800BDBF0	andi   a3, v0, $ffff

Lbdbf4:	; 800BDBF4
800BDBF4	lui    a0, $00ff
800BDBF8	ori    a0, a0, $ffff
800BDBFC	lui    a1, $ff00
800BDC00	lw     v1, $0000(s0)

funcbdc04:	; 800BDC04
800BDC04	lw     v0, $001c(s1)
800BDC08	and    v1, v1, a1
800BDC0C	and    v0, v0, a0
800BDC10	or     v1, v1, v0
800BDC14	sw     v1, $0000(s0)
800BDC18	lw     v0, $001c(s1)
800BDC1C	and    s0, s0, a0
800BDC20	and    v0, v0, a1
800BDC24	or     v0, v0, s0
800BDC28	sw     v0, $001c(s1)

Lbdc2c:	; 800BDC2C
800BDC2C	lw     ra, $0018(sp)
800BDC30	lw     s1, $0014(sp)
800BDC34	lw     s0, $0010(sp)
800BDC38	addiu  v0, zero, $0001
800BDC3C	jr     ra 
800BDC40	addiu  sp, sp, $0020


funcbdc44:	; 800BDC44
800BDC44	lui    v0, $800d
800BDC48	lhu    v0, $9da0(v0)
800BDC4C	addiu  sp, sp, $ffb8 (=-$48)
800BDC50	sw     ra, $0040(sp)
800BDC54	sw     s7, $003c(sp)
800BDC58	sw     s6, $0038(sp)

Lbdc5c:	; 800BDC5C
800BDC5C	sw     s5, $0034(sp)
800BDC60	sw     s4, $0030(sp)

funcbdc64:	; 800BDC64
800BDC64	sw     s3, $002c(sp)
800BDC68	sw     s2, $0028(sp)
800BDC6C	sw     s1, $0024(sp)
800BDC70	bne    v0, zero, Lbdc80 [$800bdc80]
800BDC74	sw     s0, $0020(sp)
800BDC78	j      Lbdea8 [$800bdea8]
800BDC7C	addu   v0, zero, zero

Lbdc80:	; 800BDC80
800BDC80	lui    v0, $800d
800BDC84	addiu  s4, v0, $a068 (=-$5f98)
800BDC88	lui    v0, $800d
800BDC8C	lw     s3, $9db4(v0)
800BDC90	lui    v0, $8006
800BDC94	lw     v1, $0010(s3)
800BDC98	lw     a0, $794c(v0)
800BDC9C	addu   s7, s3, v1
800BDCA0	lbu    v1, $0008(a0)
800BDCA4	addiu  v0, zero, $0005
800BDCA8	bne    v1, v0, Lbdce8 [$800bdce8]
800BDCAC	addiu  v0, zero, $0001
800BDCB0	lw     a0, $001c(a0)

Lbdcb4:	; 800BDCB4
800BDCB4	nop
800BDCB8	lw     v0, $08e4(a0)

funcbdcbc:	; 800BDCBC
800BDCBC	nop
800BDCC0	lb     v1, $0008(v0)
800BDCC4	nop
800BDCC8	sll    v0, v1, $02
800BDCCC	addu   v0, v0, v1
800BDCD0	lw     v1, $08e0(a0)
800BDCD4	sll    v0, v0, $02
800BDCD8	addu   v0, v0, v1
800BDCDC	lw     a0, $000c(v0)
800BDCE0	j      Lbdcfc [$800bdcfc]
800BDCE4	nop

Lbdce8:	; 800BDCE8
800BDCE8	bne    v1, v0, Lbdcfc [$800bdcfc]
800BDCEC	addu   a0, zero, zero
800BDCF0	jal    func4ae00 [$8004ae00]
800BDCF4	nop
800BDCF8	addu   a0, v0, zero

Lbdcfc:	; 800BDCFC
800BDCFC	beq    a0, zero, Lbdd2c [$800bdd2c]
800BDD00	lui    v1, $800d
800BDD04	lhu    v0, $0014(a0)
800BDD08	lhu    v1, $a0de(v1)
800BDD0C	sh     v0, $0010(sp)
800BDD10	lhu    v0, $0018(a0)
800BDD14	nop
800BDD18	subu   v0, v0, v1

Lbdd1c:	; 800BDD1C
800BDD1C	sh     v0, $0012(sp)
800BDD20	lhu    v0, $001c(a0)

funcbdd24:	; 800BDD24
800BDD24	j      Lbdd38 [$800bdd38]
800BDD28	sh     v0, $0014(sp)

Lbdd2c:	; 800BDD2C
800BDD2C	sh     zero, $0010(sp)
800BDD30	sh     zero, $0012(sp)
800BDD34	sh     zero, $0014(sp)

Lbdd38:	; 800BDD38
800BDD38	jal    funcc0f08 [$800c0f08]
800BDD3C	nop
800BDD40	lui    v0, $800d
800BDD44	addiu  v0, v0, $a068 (=-$5f98)
800BDD48	lw     t0, $001c(v0)
800BDD4C	nop
800BDD50	lw     t4, $0000(t0)
800BDD54	lw     t5, $0004(t0)
800BDD58	ctc2   t4,vxy0
800BDD5C	ctc2   t5,vz0
800BDD60	lw     t4, $0008(t0)
800BDD64	lw     t5, $000c(t0)
800BDD68	lw     t6, $0010(t0)
800BDD6C	ctc2   t4,vxy1
800BDD70	ctc2   t5,vz1
800BDD74	ctc2   t6,vxy2
800BDD78	lw     t4, $0014(t0)

Lbdd7c:	; 800BDD7C
800BDD7C	lw     t5, $0018(t0)
800BDD80	ctc2   t4,vz2
800BDD84	lw     t6, $001c(t0)
800BDD88	ctc2   t5,rgb
800BDD8C	ctc2   t6,otz
800BDD90	lw     v0, $0020(v0)
800BDD94	nop
800BDD98	lhu    v0, $0000(v0)
800BDD9C	nop

funcbdda0:	; 800BDDA0
800BDDA0	ctc2   v0,mac2
800BDDA4	addiu  v0, sp, $0010
800BDDA8	lwc2   zero, $0000(v0)
800BDDAC	lwc2   at, $0004(v0)
800BDDB0	nop
800BDDB4	nop
800BDDB8	gte_func16t8,r11r12
800BDDBC	addiu  v0, sp, $0018
800BDDC0	swc2   t6, $0000(v0)
800BDDC4	lui    v0, $800d
800BDDC8	addiu  s1, v0, $a140 (=-$5ec0)
800BDDCC	lui    v0, $800d
800BDDD0	lhu    s6, $0018(sp)
800BDDD4	lhu    v0, $9da0(v0)
800BDDD8	lhu    s5, $001a(sp)
800BDDDC	beq    v0, zero, Lbdea4 [$800bdea4]
800BDDE0	addu   s2, zero, zero
800BDDE4	addiu  s0, s1, $0008

loopbdde8:	; 800BDDE8
800BDDE8	lhu    v0, $fffc(s0)
800BDDEC	nop
800BDDF0	sll    v1, v0, $03
800BDDF4	subu   v1, v1, v0
800BDDF8	sll    v1, v1, $03
800BDDFC	addu   a1, v1, s7
800BDE00	lbu    v0, $0000(a1)
800BDE04	nop
800BDE08	andi   v0, v0, $0002
800BDE0C	beq    v0, zero, Lbde84 [$800bde84]
800BDE10	nop
800BDE14	lbu    v1, $0024(a1)
800BDE18	lbu    v0, $0075(s4)
800BDE1C	nop
800BDE20	bne    v1, v0, Lbde84 [$800bde84]
800BDE24	nop
800BDE28	lhu    v1, $0024(s3)
800BDE2C	lhu    v0, $fffe(s0)
800BDE30	lhu    a0, $0000(s0)
800BDE34	subu   v1, s6, v1
800BDE38	addiu  v0, v0, $00a0
800BDE3C	subu   v1, v1, v0
800BDE40	lhu    v0, $0004(s4)
800BDE44	addiu  a0, a0, $0070
800BDE48	addu   v0, v0, v1
800BDE4C	sh     v0, $000c(a1)
800BDE50	lhu    v1, $0024(s3)

Lbde54:	; 800BDE54
800BDE54	lhu    v0, $0006(s4)
800BDE58	subu   v1, s5, v1
800BDE5C	subu   v1, v1, a0
800BDE60	addu   v0, v0, v1
800BDE64	sh     v0, $000e(a1)
800BDE68	lb     v0, $0000(s1)
800BDE6C	nop
800BDE70	bltz   v0, Lbde84 [$800bde84]
800BDE74	addu   a0, s3, zero

funcbde78:	; 800BDE78
800BDE78	addu   a2, s4, zero
800BDE7C	jal    funcbd884 [$800bd884]
800BDE80	addu   a3, s1, zero

Lbde84:	; 800BDE84
800BDE84	addiu  s2, s2, $0001
800BDE88	addiu  s0, s0, $00dc
800BDE8C	lui    v0, $800d
800BDE90	lhu    v1, $9da0(v0)
800BDE94	andi   v0, s2, $00ff
800BDE98	sltu   v0, v0, v1
800BDE9C	bne    v0, zero, loopbdde8 [$800bdde8]
800BDEA0	addiu  s1, s1, $00dc

Lbdea4:	; 800BDEA4
800BDEA4	addiu  v0, zero, $0001

Lbdea8:	; 800BDEA8
800BDEA8	lw     ra, $0040(sp)
800BDEAC	lw     s7, $003c(sp)
800BDEB0	lw     s6, $0038(sp)
800BDEB4	lw     s5, $0034(sp)
800BDEB8	lw     s4, $0030(sp)
800BDEBC	lw     s3, $002c(sp)

Lbdec0:	; 800BDEC0
800BDEC0	lw     s2, $0028(sp)
800BDEC4	lw     s1, $0024(sp)
800BDEC8	lw     s0, $0020(sp)
800BDECC	jr     ra 
800BDED0	addiu  sp, sp, $0048



////////////////////////////////
// funcbded4
800BDED4-800BE154
////////////////////////////////



////////////////////////////////
// funcbe158
800BE158-800BEDE4
////////////////////////////////



funcbede8:	; 800BEDE8
800BEDE8	addu   a3, zero, zero
800BEDEC	lw     v0, $0010(a0)
800BEDF0	lhu    t2, $0006(a0)
800BEDF4	nop
800BEDF8	beq    t2, zero, Lbf088 [$800bf088]
800BEDFC	addu   a0, a0, v0
800BEE00	addiu  t1, zero, $7fff
800BEE04	lui    v0, $800d
800BEE08	addiu  t0, v0, $a068 (=-$5f98)
800BEE0C	addu   a1, a0, zero

Lbee10:	; 800BEE10
800BEE10	lbu    v0, $0000(a1)
800BEE14	nop
800BEE18	andi   v0, v0, $0004
800BEE1C	beq    v0, zero, Lbeefc [$800beefc]
800BEE20	nop
800BEE24	lh     a2, $001c(a1)
800BEE28	nop
800BEE2C	beq    a2, zero, Lbee90 [$800bee90]
800BEE30	nop
800BEE34	beq    a2, t1, Lbee90 [$800bee90]
800BEE38	nop
800BEE3C	lh     v0, $000c(a1)
800BEE40	lbu    v1, $0020(a1)
800BEE44	sll    v0, v0, $08
800BEE48	or     a0, v0, v1
800BEE4C	addu   a0, a0, a2
800BEE50	lhu    v1, $0004(a1)
800BEE54	sra    v0, a0, $08
800BEE58	div    v0, v1
800BEE5C	bne    v1, zero, Lbee68 [$800bee68]
800BEE60	nop
800BEE64	break   $01c00

Lbee68:	; 800BEE68
800BEE68	addiu  at, zero, $ffff (=-$1)
800BEE6C	bne    v1, at, Lbee80 [$800bee80]
800BEE70	lui    at, $8000
800BEE74	bne    v0, at, Lbee80 [$800bee80]
800BEE78	nop
800BEE7C	break   $01800

Lbee80:	; 800BEE80
800BEE80	mfhi   v1
800BEE84	andi   v0, a0, $00ff
800BEE88	sh     v0, $0020(a1)
800BEE8C	sh     v1, $000c(a1)

Lbee90:	; 800BEE90
800BEE90	lh     a2, $001e(a1)
800BEE94	nop
800BEE98	beq    a2, zero, Lbeefc [$800beefc]
800BEE9C	nop
800BEEA0	beq    a2, t1, Lbeefc [$800beefc]
800BEEA4	nop
800BEEA8	lh     v0, $000e(a1)
800BEEAC	lbu    v1, $0022(a1)
800BEEB0	sll    v0, v0, $08
800BEEB4	or     a0, v0, v1
800BEEB8	addu   a0, a0, a2
800BEEBC	lhu    v1, $0006(a1)
800BEEC0	sra    v0, a0, $08
800BEEC4	div    v0, v1
800BEEC8	bne    v1, zero, Lbeed4 [$800beed4]
800BEECC	nop
800BEED0	break   $01c00

Lbeed4:	; 800BEED4
800BEED4	addiu  at, zero, $ffff (=-$1)
800BEED8	bne    v1, at, Lbeeec [$800beeec]
800BEEDC	lui    at, $8000
800BEEE0	bne    v0, at, Lbeeec [$800beeec]
800BEEE4	nop
800BEEE8	break   $01800

Lbeeec:	; 800BEEEC
800BEEEC	mfhi   v1
800BEEF0	andi   v0, a0, $00ff
800BEEF4	sh     v0, $0022(a1)
800BEEF8	sh     v1, $000e(a1)

Lbeefc:	; 800BEEFC
800BEEFC	lbu    v0, $0000(a1)
800BEF00	nop
800BEF04	andi   v0, v0, $0080

Lbef08:	; 800BEF08
800BEF08	beq    v0, zero, Lbeff4 [$800beff4]
800BEF0C	nop
800BEF10	lw     v0, $0024(a1)
800BEF14	nop
800BEF18	srl    v0, v0, $08
800BEF1C	andi   v0, v0, $0001
800BEF20	beq    v0, zero, Lbef90 [$800bef90]
800BEF24	nop
800BEF28	lh     a2, $001e(a1)
800BEF2C	nop
800BEF30	beq    a2, t1, Lbeff4 [$800beff4]
800BEF34	nop
800BEF38	lh     v0, $000e(a1)
800BEF3C	lbu    v1, $0022(a1)
800BEF40	sll    v0, v0, $08
800BEF44	or     a0, v0, v1
800BEF48	addu   a0, a0, a2
800BEF4C	lhu    v1, $0006(a1)
800BEF50	sra    v0, a0, $08
800BEF54	div    v0, v1
800BEF58	bne    v1, zero, Lbef64 [$800bef64]
800BEF5C	nop
800BEF60	break   $01c00

Lbef64:	; 800BEF64
800BEF64	addiu  at, zero, $ffff (=-$1)
800BEF68	bne    v1, at, Lbef7c [$800bef7c]
800BEF6C	lui    at, $8000
800BEF70	bne    v0, at, Lbef7c [$800bef7c]
800BEF74	nop
800BEF78	break   $01800

Lbef7c:	; 800BEF7C
800BEF7C	mfhi   v1
800BEF80	andi   v0, a0, $00ff
800BEF84	sh     v0, $0022(a1)
800BEF88	j      Lbeff4 [$800beff4]
800BEF8C	sh     v1, $000e(a1)

Lbef90:	; 800BEF90
800BEF90	lh     a2, $001c(a1)
800BEF94	nop
800BEF98	beq    a2, t1, Lbeff4 [$800beff4]
800BEF9C	nop
800BEFA0	lh     v0, $000c(a1)
800BEFA4	lbu    v1, $0020(a1)
800BEFA8	sll    v0, v0, $08
800BEFAC	or     a0, v0, v1
800BEFB0	addu   a0, a0, a2
800BEFB4	lhu    v1, $0004(a1)
800BEFB8	sra    v0, a0, $08
800BEFBC	div    v0, v1
800BEFC0	bne    v1, zero, Lbefcc [$800befcc]
800BEFC4	nop

funcbefc8:	; 800BEFC8
800BEFC8	break   $01c00

Lbefcc:	; 800BEFCC
800BEFCC	addiu  at, zero, $ffff (=-$1)
800BEFD0	bne    v1, at, Lbefe4 [$800befe4]
800BEFD4	lui    at, $8000
800BEFD8	bne    v0, at, Lbefe4 [$800befe4]
800BEFDC	nop
800BEFE0	break   $01800

Lbefe4:	; 800BEFE4
800BEFE4	mfhi   v1
800BEFE8	andi   v0, a0, $00ff
800BEFEC	sh     v0, $0020(a1)
800BEFF0	sh     v1, $000c(a1)

Lbeff4:	; 800BEFF4
800BEFF4	lbu    v0, $0000(a1)
800BEFF8	nop
800BEFFC	andi   v0, v0, $0008
800BF000	beq    v0, zero, Lbf078 [$800bf078]
800BF004	nop
800BF008	lh     v0, $0004(t0)
800BF00C	lh     v1, $00a4(t0)
800BF010	lh     a0, $001c(a1)
800BF014	subu   v0, v0, v1
800BF018	mult   v0, a0
800BF01C	lh     v0, $0008(a1)
800BF020	nop
800BF024	sll    v0, v0, $08
800BF028	mflo   t3
800BF02C	addu   a0, v0, t3
800BF030	sra    v0, a0, $08
800BF034	sh     v0, $000c(a1)
800BF038	andi   v0, a0, $00ff
800BF03C	sh     v0, $0020(a1)
800BF040	lh     v0, $0006(t0)
800BF044	lh     v1, $00a6(t0)
800BF048	lh     a0, $001e(a1)
800BF04C	subu   v0, v0, v1
800BF050	mult   v0, a0
800BF054	lh     v0, $000a(a1)
800BF058	nop
800BF05C	sll    v0, v0, $08
800BF060	mflo   t3
800BF064	addu   a0, v0, t3
800BF068	sra    v0, a0, $08
800BF06C	sh     v0, $000e(a1)
800BF070	andi   v0, a0, $00ff
800BF074	sh     v0, $0022(a1)

Lbf078:	; 800BF078
800BF078	addiu  a3, a3, $0001
800BF07C	slt    v0, a3, t2
800BF080	bne    v0, zero, Lbee10 [$800bee10]
800BF084	addiu  a1, a1, $0038

Lbf088:	; 800BF088
800BF088	lui    a2, $800d
800BF08C	lw     a3, $a068(a2)
800BF090	nop
800BF094	andi   v0, a3, $0080
800BF098	beq    v0, zero, Lbf0bc [$800bf0bc]
800BF09C	addiu  a1, a2, $a068 (=-$5f98)
800BF0A0	addiu  v0, zero, $ff7f (=-$81)
800BF0A4	lhu    v1, $0004(a1)
800BF0A8	lhu    a0, $0006(a1)
800BF0AC	and    v0, a3, v0
800BF0B0	sw     v0, $a068(a2)
800BF0B4	sh     v1, $0008(a1)
800BF0B8	sh     a0, $000a(a1)

Lbf0bc:	; 800BF0BC
800BF0BC	jr     ra 
800BF0C0	addiu  v0, zero, $0001


funcbf0c4:	; 800BF0C4
800BF0C4	lui    v0, $800d
800BF0C8	lw     v1, $a068(v0)
800BF0CC	addiu  sp, sp, $ffb8 (=-$48)
800BF0D0	sw     s0, $0020(sp)
800BF0D4	addiu  s0, v0, $a068 (=-$5f98)
800BF0D8	sw     ra, $0044(sp)
800BF0DC	sw     fp, $0040(sp)
800BF0E0	sw     s7, $003c(sp)
800BF0E4	sw     s6, $0038(sp)
800BF0E8	sw     s5, $0034(sp)
800BF0EC	sw     s4, $0030(sp)
800BF0F0	sw     s3, $002c(sp)
800BF0F4	sw     s2, $0028(sp)
800BF0F8	andi   v0, v1, $0040
800BF0FC	bne    v0, zero, Lbf10c [$800bf10c]
800BF100	sw     s1, $0024(sp)
800BF104	j      Lbf630 [$800bf630]
800BF108	addu   v0, zero, zero

Lbf10c:	; 800BF10C
800BF10C	andi   t0, v1, $0007
800BF110	sw     t0, $0018(sp)
800BF114	addiu  v0, t0, $ffff (=-$1)
800BF118	sltiu  v0, v0, $0003
800BF11C	beq    v0, zero, Lbf62c [$800bf62c]
800BF120	andi   a1, v1, $0008
800BF124	lui    a0, $800d

Lbf128:	; 800BF128
800BF128	lhu    fp, $0004(s0)
800BF12C	lhu    s3, $0006(s0)
800BF130	lhu    v1, $0014(s0)
800BF134	lhu    a2, $0010(s0)
800BF138	lhu    v0, $0016(s0)
800BF13C	lhu    a3, $0012(s0)
800BF140	lw     s4, $9db4(a0)
800BF144	lhu    a0, $0018(s0)
800BF148	lhu    t0, $001a(s0)
800BF14C	subu   s1, v1, a2
800BF150	subu   s2, v0, a3
800BF154	bne    a1, zero, Lbf200 [$800bf200]
800BF158	sh     t0, $0010(sp)
800BF15C	sll    v0, s1, $10
800BF160	sra    v0, v0, $10
800BF164	sll    a1, a0, $10
800BF168	sra    a1, a1, $10
800BF16C	mult   v0, a1
800BF170	mflo   t1
800BF174	sll    v1, t0, $10
800BF178	sra    v1, v1, $10
800BF17C	div    t1, v1
800BF180	bne    v1, zero, Lbf18c [$800bf18c]
800BF184	nop
800BF188	break   $01c00

Lbf18c:	; 800BF18C
800BF18C	addiu  at, zero, $ffff (=-$1)
800BF190	bne    v1, at, Lbf1a4 [$800bf1a4]
800BF194	lui    at, $8000
800BF198	bne    t1, at, Lbf1a4 [$800bf1a4]

Lbf19c:	; 800BF19C
800BF19C	nop
800BF1A0	break   $01800

Lbf1a4:	; 800BF1A4
800BF1A4	mflo   a0
800BF1A8	sll    v0, s2, $10
800BF1AC	sra    v0, v0, $10
800BF1B0	mult   v0, a1
800BF1B4	mflo   t1
800BF1B8	nop
800BF1BC	nop
800BF1C0	div    t1, v1
800BF1C4	bne    v1, zero, Lbf1d0 [$800bf1d0]
800BF1C8	nop
800BF1CC	break   $01c00

Lbf1d0:	; 800BF1D0
800BF1D0	addiu  at, zero, $ffff (=-$1)
800BF1D4	bne    v1, at, Lbf1e8 [$800bf1e8]
800BF1D8	lui    at, $8000
800BF1DC	bne    t1, at, Lbf1e8 [$800bf1e8]
800BF1E0	nop
800BF1E4	break   $01800

Lbf1e8:	; 800BF1E8
800BF1E8	mflo   v1
800BF1EC	addu   a0, a2, a0
800BF1F0	sh     a0, $0004(s0)
800BF1F4	addu   v1, a3, v1
800BF1F8	j      Lbf2a0 [$800bf2a0]
800BF1FC	sh     v1, $0006(s0)

Lbf200:	; 800BF200
800BF200	sll    a0, a0, $10
800BF204	lhu    t0, $0010(sp)
800BF208	sra    a0, a0, $05
800BF20C	sll    v0, t0, $10
800BF210	sra    v0, v0, $10
800BF214	div    a0, v0
800BF218	bne    v0, zero, Lbf224 [$800bf224]
800BF21C	nop
800BF220	break   $01c00

Lbf224:	; 800BF224
800BF224	addiu  at, zero, $ffff (=-$1)
800BF228	bne    v0, at, Lbf23c [$800bf23c]
800BF22C	lui    at, $8000
800BF230	bne    a0, at, Lbf23c [$800bf23c]

Lbf234:	; 800BF234
800BF234	nop
800BF238	break   $01800

Lbf23c:	; 800BF23C
800BF23C	mflo   a0
800BF240	jal    system_get_cos_by_rotation [$8004bb7c]
800BF244	addiu  a0, a0, $0800
800BF248	addiu  v1, v0, $1000
800BF24C	sll    v0, s1, $10
800BF250	sra    v0, v0, $10
800BF254	mult   v0, v1
800BF258	mflo   a0
800BF25C	bgez   a0, Lbf268 [$800bf268]
800BF260	sll    v0, s2, $10
800BF264	addiu  a0, a0, $1fff

Lbf268:	; 800BF268
800BF268	sra    v0, v0, $10
800BF26C	mult   v0, v1
800BF270	mflo   v1
800BF274	bgez   v1, Lbf280 [$800bf280]
800BF278	sra    a0, a0, $0d
800BF27C	addiu  v1, v1, $1fff

Lbf280:	; 800BF280
800BF280	lhu    v0, $0010(s0)
800BF284	nop
800BF288	addu   v0, v0, a0
800BF28C	sh     v0, $0004(s0)
800BF290	lhu    v0, $0012(s0)
800BF294	sra    v1, v1, $0d
800BF298	addu   v0, v0, v1
800BF29C	sh     v0, $0006(s0)

Lbf2a0:	; 800BF2A0
800BF2A0	lui    v0, $800d
800BF2A4	addiu  a1, v0, $a068 (=-$5f98)
800BF2A8	lhu    v0, $0004(a1)
800BF2AC	addu   s1, zero, zero
800BF2B0	subu   a0, v0, fp
800BF2B4	lhu    v0, $0006(a1)
800BF2B8	lhu    v1, $0006(s4)
800BF2BC	subu   s3, v0, s3
800BF2C0	lw     v0, $0010(s4)
800BF2C4	addu   fp, a0, zero
800BF2C8	beq    v1, zero, Lbf548 [$800bf548]
800BF2CC	addu   s2, s4, v0
800BF2D0	sll    v0, a0, $10
800BF2D4	sra    s7, v0, $10
800BF2D8	addu   s6, a1, zero
800BF2DC	lui    s5, $0001
800BF2E0	addiu  s0, s2, $0022

Lbf2e4:	; 800BF2E4
800BF2E4	lbu    v1, $0000(s2)
800BF2E8	nop
800BF2EC	andi   v0, v1, $0004
800BF2F0	beq    v0, zero, Lbf3fc [$800bf3fc]
800BF2F4	andi   v0, v1, $0080
800BF2F8	lh     v0, $fffa(s0)
800BF2FC	nop
800BF300	beq    v0, zero, Lbf318 [$800bf318]

Lbf304:	; 800BF304
800BF304	nop
800BF308	lhu    v0, $ffea(s0)
800BF30C	nop
800BF310	addu   v0, v0, fp
800BF314	sh     v0, $ffea(s0)

Lbf318:	; 800BF318
800BF318	lh     v0, $fffc(s0)
800BF31C	nop
800BF320	beq    v0, zero, Lbf338 [$800bf338]
800BF324	nop
800BF328	lhu    v0, $ffec(s0)
800BF32C	nop
800BF330	addu   v0, v0, s3
800BF334	sh     v0, $ffec(s0)

Lbf338:	; 800BF338
800BF338	lw     v0, $0002(s0)
800BF33C	nop
800BF340	srl    v0, v0, $08
800BF344	andi   v0, v0, $00fe
800BF348	addu   v0, v0, s6
800BF34C	lh     v0, $00c8(v0)
800BF350	nop
800BF354	sll    a1, v0, $08
800BF358	beq    a1, s5, Lbf3b0 [$800bf3b0]
800BF35C	sll    a0, s7, $10
800BF360	bgez   a1, Lbf384 [$800bf384]
800BF364	nop
800BF368	jal    funcc1dc4 [$800c1dc4]
800BF36C	subu   a1, zero, a1

Lbf370:	; 800BF370
800BF370	lh     v1, $ffea(s0)
800BF374	nop
800BF378	sll    v1, v1, $10
800BF37C	j      Lbf39c [$800bf39c]
800BF380	subu   a0, v1, v0

Lbf384:	; 800BF384
800BF384	jal    funcc1dc4 [$800c1dc4]
800BF388	nop
800BF38C	lh     v1, $ffea(s0)
800BF390	nop
800BF394	sll    v1, v1, $10
800BF398	addu   a0, v1, v0

Lbf39c:	; 800BF39C
800BF39C	sra    v0, a0, $10
800BF3A0	sh     v0, $ffea(s0)
800BF3A4	sra    v0, a0, $08
800BF3A8	andi   v0, v0, $00ff
800BF3AC	sh     v0, $fffe(s0)

Lbf3b0:	; 800BF3B0
800BF3B0	lw     v0, $0002(s0)
800BF3B4	nop
800BF3B8	srl    v0, v0, $08
800BF3BC	andi   v0, v0, $00fe
800BF3C0	addu   v0, v0, s6
800BF3C4	lh     v0, $00d0(v0)
800BF3C8	nop
800BF3CC	sll    a1, v0, $08
800BF3D0	beq    a1, s5, Lbf530 [$800bf530]
800BF3D4	sll    a0, s3, $10
800BF3D8	bgez   a1, Lbf504 [$800bf504]
800BF3DC	nop

Lbf3e0:	; 800BF3E0
800BF3E0	jal    funcc1dc4 [$800c1dc4]
800BF3E4	subu   a1, zero, a1
800BF3E8	lh     v1, $ffec(s0)
800BF3EC	nop
800BF3F0	sll    v1, v1, $10
800BF3F4	j      Lbf51c [$800bf51c]
800BF3F8	subu   a0, v1, v0

Lbf3fc:	; 800BF3FC
800BF3FC	beq    v0, zero, Lbf530 [$800bf530]
800BF400	nop
800BF404	lw     v0, $0002(s0)
800BF408	nop
800BF40C	srl    v0, v0, $08
800BF410	andi   v0, v0, $0001
800BF414	beq    v0, zero, Lbf430 [$800bf430]
800BF418	nop
800BF41C	lhu    v0, $ffec(s0)
800BF420	nop
800BF424	addu   v0, v0, s3
800BF428	j      Lbf440 [$800bf440]
800BF42C	sh     v0, $ffec(s0)

Lbf430:	; 800BF430
800BF430	lhu    v0, $ffea(s0)
800BF434	nop
800BF438	addu   v0, v0, fp
800BF43C	sh     v0, $ffea(s0)

Lbf440:	; 800BF440
800BF440	lw     v0, $0002(s0)

Lbf444:	; 800BF444
800BF444	nop
800BF448	srl    v0, v0, $08
800BF44C	andi   v0, v0, $00fe
800BF450	addu   v0, v0, s6
800BF454	lh     v0, $00c8(v0)

Lbf458:	; 800BF458
800BF458	nop
800BF45C	sll    a1, v0, $08
800BF460	beq    a1, s5, Lbf4b8 [$800bf4b8]
800BF464	sll    a0, s7, $10
800BF468	bgez   a1, Lbf48c [$800bf48c]

Lbf46c:	; 800BF46C
800BF46C	nop
800BF470	jal    funcc1dc4 [$800c1dc4]
800BF474	subu   a1, zero, a1
800BF478	lh     v1, $ffea(s0)
800BF47C	nop

Lbf480:	; 800BF480
800BF480	sll    v1, v1, $10
800BF484	j      Lbf4a4 [$800bf4a4]
800BF488	subu   a0, v1, v0

Lbf48c:	; 800BF48C
800BF48C	jal    funcc1dc4 [$800c1dc4]
800BF490	nop
800BF494	lh     v1, $ffea(s0)
800BF498	nop
800BF49C	sll    v1, v1, $10
800BF4A0	addu   a0, v1, v0

Lbf4a4:	; 800BF4A4
800BF4A4	sra    v0, a0, $10

Lbf4a8:	; 800BF4A8
800BF4A8	sh     v0, $ffea(s0)
800BF4AC	sra    v0, a0, $08
800BF4B0	andi   v0, v0, $00ff
800BF4B4	sh     v0, $fffe(s0)

Lbf4b8:	; 800BF4B8
800BF4B8	lw     v0, $0002(s0)

Lbf4bc:	; 800BF4BC
800BF4BC	nop
800BF4C0	srl    v0, v0, $08
800BF4C4	andi   v0, v0, $00fe
800BF4C8	addu   v0, v0, s6
800BF4CC	lh     v0, $00d0(v0)
800BF4D0	nop
800BF4D4	sll    a1, v0, $08
800BF4D8	beq    a1, s5, Lbf530 [$800bf530]
800BF4DC	sll    a0, s3, $10

Lbf4e0:	; 800BF4E0
800BF4E0	bgez   a1, Lbf504 [$800bf504]
800BF4E4	nop
800BF4E8	jal    funcc1dc4 [$800c1dc4]
800BF4EC	subu   a1, zero, a1
800BF4F0	lh     v1, $ffec(s0)
800BF4F4	nop
800BF4F8	sll    v1, v1, $10
800BF4FC	j      Lbf51c [$800bf51c]
800BF500	subu   a0, v1, v0

Lbf504:	; 800BF504
800BF504	jal    funcc1dc4 [$800c1dc4]
800BF508	nop

Lbf50c:	; 800BF50C
800BF50C	lh     v1, $ffec(s0)
800BF510	nop
800BF514	sll    v1, v1, $10
800BF518	addu   a0, v1, v0

Lbf51c:	; 800BF51C
800BF51C	sra    v0, a0, $10

Lbf520:	; 800BF520
800BF520	sh     v0, $ffec(s0)
800BF524	sra    v0, a0, $08
800BF528	andi   v0, v0, $00ff
800BF52C	sh     v0, $0000(s0)

Lbf530:	; 800BF530
800BF530	addiu  s0, s0, $0038

Lbf534:	; 800BF534
800BF534	lhu    v0, $0006(s4)
800BF538	addiu  s1, s1, $0001
800BF53C	slt    v0, s1, v0
800BF540	bne    v0, zero, Lbf2e4 [$800bf2e4]
800BF544	addiu  s2, s2, $0038

Lbf548:	; 800BF548
800BF548	lui    a3, $800d
800BF54C	addiu  a2, a3, $a068 (=-$5f98)
800BF550	addiu  a0, zero, $00a0
800BF554	lw     a1, $0018(s4)

funcbf558:	; 800BF558
800BF558	lbu    v1, $0075(a2)
800BF55C	addu   a1, s4, a1
800BF560	sll    v0, v1, $01
800BF564	addu   v0, v0, v1
800BF568	sll    v0, v0, $02
800BF56C	addu   v0, v0, v1

Lbf570:	; 800BF570
800BF570	sll    v0, v0, $02
800BF574	addu   a1, a1, v0
800BF578	lhu    v0, $0024(a1)
800BF57C	lh     v1, $0004(a2)
800BF580	sll    v0, v0, $10
800BF584	sra    v0, v0, $11
800BF588	subu   v1, v1, v0
800BF58C	subu   s1, a0, v1
800BF590	lhu    v0, $0026(a1)
800BF594	lh     v1, $0006(a2)
800BF598	sh     s1, $000c(a2)
800BF59C	sll    v0, v0, $10
800BF5A0	sra    v0, v0, $11
800BF5A4	subu   v1, v1, v0
800BF5A8	addiu  v0, zero, $0070
800BF5AC	subu   v0, v0, v1
800BF5B0	sh     v0, $000e(a2)
800BF5B4	lw     t0, $0018(sp)
800BF5B8	addiu  v0, zero, $0001
800BF5BC	bne    t0, v0, Lbf5d8 [$800bf5d8]
800BF5C0	addiu  v1, zero, $fff8 (=-$8)
800BF5C4	lw     v0, $a068(a3)
800BF5C8	nop
800BF5CC	and    v0, v0, v1
800BF5D0	ori    v0, v0, $0002
800BF5D4	sw     v0, $a068(a3)

Lbf5d8:	; 800BF5D8
800BF5D8	lhu    v1, $0018(a2)
800BF5DC	nop
800BF5E0	addiu  v1, v1, $0001
800BF5E4	sh     v1, $0018(a2)
800BF5E8	lhu    t0, $0010(sp)
800BF5EC	sll    v1, v1, $10
800BF5F0	sll    v0, t0, $10
800BF5F4	slt    v0, v0, v1
800BF5F8	beq    v0, zero, Lbf62c [$800bf62c]
800BF5FC	addiu  v0, zero, $0002
800BF600	lw     a0, $a068(a3)
800BF604	nop
800BF608	andi   v1, a0, $0007
800BF60C	bne    v1, v0, Lbf620 [$800bf620]
800BF610	addiu  v0, zero, $fff8 (=-$8)
800BF614	and    v0, a0, v0
800BF618	j      Lbf628 [$800bf628]
800BF61C	ori    v0, v0, $0084

Lbf620:	; 800BF620
800BF620	and    v0, a0, v0

Lbf624:	; 800BF624
800BF624	ori    v0, v0, $0080

Lbf628:	; 800BF628
800BF628	sw     v0, $a068(a3)

Lbf62c:	; 800BF62C
800BF62C	addiu  v0, zero, $0001

Lbf630:	; 800BF630
800BF630	lw     ra, $0044(sp)
800BF634	lw     fp, $0040(sp)

Lbf638:	; 800BF638
800BF638	lw     s7, $003c(sp)
800BF63C	lw     s6, $0038(sp)
800BF640	lw     s5, $0034(sp)
800BF644	lw     s4, $0030(sp)
800BF648	lw     s3, $002c(sp)
800BF64C	lw     s2, $0028(sp)
800BF650	lw     s1, $0024(sp)
800BF654	lw     s0, $0020(sp)
800BF658	jr     ra 
800BF65C	addiu  sp, sp, $0048


funcbf660:	; 800BF660
800BF660	lui    v0, $800d
800BF664	lw     v1, $a068(v0)
800BF668	addiu  sp, sp, $ffb8 (=-$48)
800BF66C	sw     ra, $0040(sp)
800BF670	sw     s5, $003c(sp)
800BF674	sw     s4, $0038(sp)
800BF678	sw     s3, $0034(sp)
800BF67C	sw     s2, $0030(sp)
800BF680	sw     s1, $002c(sp)
800BF684	andi   v0, v1, $0007
800BF688	bne    v0, zero, Lbf69c [$800bf69c]
800BF68C	sw     s0, $0028(sp)
800BF690	andi   v0, v1, $0040
800BF694	bne    v0, zero, Lbf6a4 [$800bf6a4]
800BF698	lui    v0, $8006

Lbf69c:	; 800BF69C
800BF69C	j      Lbfcc4 [$800bfcc4]
800BF6A0	addu   v0, zero, zero

Lbf6a4:	; 800BF6A4
800BF6A4	lw     v1, $794c(v0)
800BF6A8	nop
800BF6AC	lbu    a0, $0008(v1)
800BF6B0	addiu  v0, zero, $0005
800BF6B4	bne    a0, v0, Lbf6f4 [$800bf6f4]
800BF6B8	addiu  v0, zero, $0001
800BF6BC	lw     a0, $001c(v1)
800BF6C0	nop
800BF6C4	lw     v0, $08e4(a0)
800BF6C8	nop
800BF6CC	lb     v1, $0008(v0)
800BF6D0	nop
800BF6D4	sll    v0, v1, $02
800BF6D8	addu   v0, v0, v1
800BF6DC	lw     v1, $08e0(a0)
800BF6E0	sll    v0, v0, $02
800BF6E4	addu   v0, v0, v1
800BF6E8	lw     a0, $000c(v0)
800BF6EC	j      Lbf70c [$800bf70c]
800BF6F0	lui    v0, $800d

Lbf6f4:	; 800BF6F4
800BF6F4	bne    a0, v0, Lbf708 [$800bf708]
800BF6F8	addu   a0, zero, zero
800BF6FC	jal    func4ae00 [$8004ae00]
800BF700	nop
800BF704	addu   a0, v0, zero

Lbf708:	; 800BF708
800BF708	lui    v0, $800d

Lbf70c:	; 800BF70C
800BF70C	lui    v1, $800d
800BF710	lw     s5, $9db4(v0)
800BF714	addiu  a1, v1, $a068 (=-$5f98)
800BF718	lw     v0, $0018(s5)
800BF71C	lbu    v1, $0075(a1)
800BF720	addu   s0, s5, v0
800BF724	sll    v0, v1, $01
800BF728	addu   v0, v0, v1
800BF72C	sll    v0, v0, $02
800BF730	addu   v0, v0, v1
800BF734	sll    v0, v0, $02
800BF738	beq    a0, zero, Lbf76c [$800bf76c]
800BF73C	addu   s0, s0, v0
800BF740	lhu    v0, $0014(a0)
800BF744	nop
800BF748	sh     v0, $0010(sp)
800BF74C	lhu    v0, $0018(a0)
800BF750	lhu    v1, $0076(a1)
800BF754	nop
800BF758	subu   v0, v0, v1
800BF75C	sh     v0, $0012(sp)
800BF760	lhu    v0, $001c(a0)
800BF764	j      Lbf778 [$800bf778]
800BF768	sh     v0, $0014(sp)

Lbf76c:	; 800BF76C
800BF76C	sh     zero, $0010(sp)
800BF770	sh     zero, $0012(sp)
800BF774	sh     zero, $0014(sp)

Lbf778:	; 800BF778
800BF778	addiu  a0, sp, $0018
800BF77C	jal    func30aa4 [$80030aa4]
800BF780	addiu  a1, sp, $001c
800BF784	addiu  t7, zero, $00a0
800BF788	addiu  t8, zero, $0070
800BF78C	sll    t4, t7, $10
800BF790	sll    t5, t8, $10
800BF794	ctc2   t4,mac0
800BF798	ctc2   t5,mac1
800BF79C	lui    v1, $800d
800BF7A0	addiu  a1, v1, $a068 (=-$5f98)
800BF7A4	lw     t7, $001c(a1)
800BF7A8	nop
800BF7AC	lw     t4, $0000(t7)
800BF7B0	lw     t5, $0004(t7)
800BF7B4	ctc2   t4,vxy0
800BF7B8	ctc2   t5,vz0
800BF7BC	lw     t4, $0008(t7)
800BF7C0	lw     t5, $000c(t7)
800BF7C4	lw     t6, $0010(t7)
800BF7C8	ctc2   t4,vxy1
800BF7CC	ctc2   t5,vz1
800BF7D0	ctc2   t6,vxy2
800BF7D4	lw     t4, $0014(t7)
800BF7D8	lw     t5, $0018(t7)
800BF7DC	ctc2   t4,vz2
800BF7E0	lw     t6, $001c(t7)
800BF7E4	ctc2   t5,rgb
800BF7E8	ctc2   t6,otz
800BF7EC	lw     v0, $0020(a1)
800BF7F0	nop
800BF7F4	lhu    v0, $0000(v0)
800BF7F8	nop
800BF7FC	ctc2   v0,mac2
800BF800	addiu  v0, sp, $0010
800BF804	lwc2   zero, $0000(v0)
800BF808	lwc2   at, $0004(v0)
800BF80C	nop
800BF810	nop
800BF814	gte_func16t8,r11r12
800BF818	addiu  v0, sp, $0020
800BF81C	swc2   t6, $0000(v0)
800BF820	lw     t8, $0018(sp)
800BF824	lw     t7, $001c(sp)
800BF828	sll    t4, t8, $10
800BF82C	sll    t5, t7, $10
800BF830	ctc2   t4,mac0
800BF834	ctc2   t5,mac1
800BF838	lh     a0, $0020(sp)
800BF83C	lw     v0, $a068(v1)
800BF840	lh     a2, $0022(sp)
800BF844	andi   v0, v0, $0080
800BF848	beq    v0, zero, Lbf858 [$800bf858]
800BF84C	nop
800BF850	sh     a0, $002c(a1)
800BF854	sh     a2, $002e(a1)

Lbf858:	; 800BF858
800BF858	lh     v0, $002c(a1)
800BF85C	lh     v1, $002e(a1)
800BF860	addu   v0, v0, a0
800BF864	sra    a0, v0, $01
800BF868	addu   v1, v1, a2
800BF86C	sra    a2, v1, $01
800BF870	addiu  v0, zero, $0140
800BF874	subu   t0, v0, a0
800BF878	addiu  v1, zero, $00e0
800BF87C	subu   a3, v1, a2
800BF880	sh     a0, $002c(a1)
800BF884	sh     a2, $002e(a1)
800BF888	lhu    v0, $0024(s0)
800BF88C	lh     v1, $0020(s0)
800BF890	sll    v0, v0, $10
800BF894	sra    v0, v0, $11
800BF898	addu   a1, v0, v1
800BF89C	addiu  v1, a1, $ff60 (=-$a0)
800BF8A0	addu   t1, v1, a0
800BF8A4	lhu    v0, $0026(s0)
800BF8A8	lh     v1, $0022(s0)
800BF8AC	sll    v0, v0, $10
800BF8B0	sra    v0, v0, $11
800BF8B4	addu   v0, v0, v1
800BF8B8	addiu  v0, v0, $ff90 (=-$70)
800BF8BC	lh     v1, $0028(s0)
800BF8C0	addu   a2, v0, a2
800BF8C4	slt    v0, t1, v1
800BF8C8	bne    v0, zero, Lbf8e4 [$800bf8e4]
800BF8CC	addiu  v0, v1, $ff60 (=-$a0)
800BF8D0	lh     v1, $002a(s0)
800BF8D4	nop
800BF8D8	slt    v0, v1, t1
800BF8DC	beq    v0, zero, Lbf8e8 [$800bf8e8]
800BF8E0	addiu  v0, v1, $ff60 (=-$a0)

Lbf8e4:	; 800BF8E4
800BF8E4	subu   t0, a1, v0

Lbf8e8:	; 800BF8E8
800BF8E8	lh     a0, $002c(s0)
800BF8EC	nop
800BF8F0	slt    v0, a2, a0
800BF8F4	bne    v0, zero, Lbf910 [$800bf910]
800BF8F8	nop
800BF8FC	lh     a0, $002e(s0)
800BF900	nop
800BF904	slt    v0, a0, a2
800BF908	beq    v0, zero, Lbf930 [$800bf930]
800BF90C	lui    v1, $800d

Lbf910:	; 800BF910
800BF910	lhu    v0, $0026(s0)
800BF914	lh     v1, $0022(s0)
800BF918	sll    v0, v0, $10
800BF91C	sra    v0, v0, $11
800BF920	addu   v0, v0, v1
800BF924	addiu  v1, a0, $ff90 (=-$70)
800BF928	subu   a3, v0, v1
800BF92C	lui    v1, $800d

Lbf930:	; 800BF930
800BF930	lhu    v0, $0020(s0)
800BF934	addiu  a1, v1, $a068 (=-$5f98)
800BF938	subu   v0, t0, v0
800BF93C	sh     v0, $000c(a1)
800BF940	lhu    v0, $0022(s0)
800BF944	addiu  t2, sp, $0024
800BF948	subu   v0, a3, v0
800BF94C	sh     v0, $000e(a1)
800BF950	lw     v0, $a068(v1)
800BF954	nop
800BF958	andi   v0, v0, $0040
800BF95C	beq    v0, zero, Lbfa24 [$800bfa24]
800BF960	addiu  t3, sp, $0026
800BF964	sll    v1, t1, $10
800BF968	sra    v1, v1, $10
800BF96C	lh     v0, $0028(s0)
800BF970	lhu    a3, $0004(a1)
800BF974	lhu    t0, $0006(a1)
800BF978	lhu    a0, $0028(s0)
800BF97C	slt    v0, v1, v0
800BF980	beq    v0, zero, Lbf990 [$800bf990]
800BF984	nop
800BF988	j      Lbf9b4 [$800bf9b4]
800BF98C	sh     a0, $0004(a1)

Lbf990:	; 800BF990
800BF990	lh     v0, $002a(s0)
800BF994	nop
800BF998	slt    v0, v0, v1
800BF99C	lhu    v1, $002a(s0)
800BF9A0	beq    v0, zero, Lbf9b0 [$800bf9b0]
800BF9A4	nop
800BF9A8	j      Lbf9b4 [$800bf9b4]
800BF9AC	sh     v1, $0004(a1)

Lbf9b0:	; 800BF9B0
800BF9B0	sh     t1, $0004(a1)

Lbf9b4:	; 800BF9B4
800BF9B4	sll    v1, a2, $10
800BF9B8	sra    v1, v1, $10
800BF9BC	lh     v0, $002c(s0)
800BF9C0	lhu    a0, $002c(s0)
800BF9C4	slt    v0, v1, v0
800BF9C8	beq    v0, zero, Lbf9d8 [$800bf9d8]
800BF9CC	lui    v0, $800d
800BF9D0	j      Lbf9fc [$800bf9fc]
800BF9D4	sh     a0, $a06e(v0)

Lbf9d8:	; 800BF9D8
800BF9D8	lh     v0, $002e(s0)
800BF9DC	nop
800BF9E0	slt    v0, v0, v1
800BF9E4	lhu    v1, $002e(s0)
800BF9E8	beq    v0, zero, Lbf9f8 [$800bf9f8]
800BF9EC	lui    v0, $800d
800BF9F0	j      Lbf9fc [$800bf9fc]
800BF9F4	sh     v1, $a06e(v0)

Lbf9f8:	; 800BF9F8
800BF9F8	sh     a2, $a06e(v0)

Lbf9fc:	; 800BF9FC
800BF9FC	lui    v0, $800d
800BFA00	addiu  v0, v0, $a068 (=-$5f98)
800BFA04	lhu    v1, $0004(v0)
800BFA08	nop
800BFA0C	subu   v1, v1, a3
800BFA10	sh     v1, $0000(t2)
800BFA14	lhu    v0, $0006(v0)
800BFA18	nop
800BFA1C	subu   v0, v0, t0
800BFA20	sh     v0, $0000(t3)

Lbfa24:	; 800BFA24
800BFA24	addu   s2, zero, zero
800BFA28	lw     v0, $0010(s5)
800BFA2C	lhu    v1, $0006(s5)
800BFA30	nop
800BFA34	beq    v1, zero, Lbfcc0 [$800bfcc0]
800BFA38	addu   s1, s5, v0
800BFA3C	lui    v0, $800d
800BFA40	addiu  s4, v0, $a068 (=-$5f98)
800BFA44	lui    s3, $0001
800BFA48	addiu  s0, s1, $0022

Lbfa4c:	; 800BFA4C
800BFA4C	lbu    v1, $0000(s1)
800BFA50	nop
800BFA54	andi   v0, v1, $0004
800BFA58	beq    v0, zero, Lbfb6c [$800bfb6c]
800BFA5C	andi   v0, v1, $0080
800BFA60	lh     v0, $fffa(s0)
800BFA64	nop
800BFA68	beq    v0, zero, Lbfa84 [$800bfa84]
800BFA6C	nop
800BFA70	lhu    v0, $ffea(s0)
800BFA74	lhu    v1, $0024(sp)
800BFA78	nop
800BFA7C	addu   v0, v0, v1
800BFA80	sh     v0, $ffea(s0)

Lbfa84:	; 800BFA84
800BFA84	lh     v0, $fffc(s0)
800BFA88	nop
800BFA8C	beq    v0, zero, Lbfaa8 [$800bfaa8]
800BFA90	nop
800BFA94	lhu    v0, $ffec(s0)
800BFA98	lhu    v1, $0026(sp)
800BFA9C	nop
800BFAA0	addu   v0, v0, v1
800BFAA4	sh     v0, $ffec(s0)

Lbfaa8:	; 800BFAA8
800BFAA8	lw     v0, $0002(s0)
800BFAAC	lh     v1, $0024(sp)
800BFAB0	srl    v0, v0, $08
800BFAB4	andi   v0, v0, $00fe
800BFAB8	addu   v0, v0, s4
800BFABC	lh     v0, $00c8(v0)
800BFAC0	nop
800BFAC4	sll    a1, v0, $08
800BFAC8	beq    a1, s3, Lbfb20 [$800bfb20]
800BFACC	sll    a0, v1, $10
800BFAD0	bgez   a1, Lbfaf4 [$800bfaf4]
800BFAD4	nop
800BFAD8	jal    funcc1dc4 [$800c1dc4]

Lbfadc:	; 800BFADC
800BFADC	subu   a1, zero, a1

Lbfae0:	; 800BFAE0
800BFAE0	lh     v1, $ffea(s0)
800BFAE4	nop
800BFAE8	sll    v1, v1, $10
800BFAEC	j      Lbfb0c [$800bfb0c]
800BFAF0	subu   a0, v1, v0

Lbfaf4:	; 800BFAF4
800BFAF4	jal    funcc1dc4 [$800c1dc4]

Lbfaf8:	; 800BFAF8
800BFAF8	nop
800BFAFC	lh     v1, $ffea(s0)
800BFB00	nop
800BFB04	sll    v1, v1, $10
800BFB08	addu   a0, v1, v0

Lbfb0c:	; 800BFB0C
800BFB0C	sra    v0, a0, $10
800BFB10	sh     v0, $ffea(s0)
800BFB14	sra    v0, a0, $08
800BFB18	andi   v0, v0, $00ff
800BFB1C	sh     v0, $fffe(s0)

Lbfb20:	; 800BFB20
800BFB20	lw     v0, $0002(s0)
800BFB24	lh     v1, $0026(sp)
800BFB28	srl    v0, v0, $08
800BFB2C	andi   v0, v0, $00fe
800BFB30	addu   v0, v0, s4
800BFB34	lh     v0, $00d0(v0)
800BFB38	nop
800BFB3C	sll    a1, v0, $08
800BFB40	beq    a1, s3, Lbfca8 [$800bfca8]
800BFB44	sll    a0, v1, $10
800BFB48	bgez   a1, Lbfc7c [$800bfc7c]
800BFB4C	nop
800BFB50	jal    funcc1dc4 [$800c1dc4]
800BFB54	subu   a1, zero, a1
800BFB58	lh     v1, $ffec(s0)
800BFB5C	nop
800BFB60	sll    v1, v1, $10
800BFB64	j      Lbfc94 [$800bfc94]
800BFB68	subu   a0, v1, v0

Lbfb6c:	; 800BFB6C
800BFB6C	beq    v0, zero, Lbfca8 [$800bfca8]
800BFB70	nop
800BFB74	lw     v0, $0002(s0)
800BFB78	nop
800BFB7C	srl    v0, v0, $08
800BFB80	andi   v0, v0, $0001
800BFB84	beq    v0, zero, Lbfba4 [$800bfba4]
800BFB88	nop
800BFB8C	lhu    v0, $ffec(s0)
800BFB90	lhu    v1, $0026(sp)
800BFB94	nop
800BFB98	addu   v0, v0, v1
800BFB9C	j      Lbfbb8 [$800bfbb8]
800BFBA0	sh     v0, $ffec(s0)

Lbfba4:	; 800BFBA4
800BFBA4	lhu    v0, $ffea(s0)
800BFBA8	lhu    v1, $0024(sp)
800BFBAC	nop
800BFBB0	addu   v0, v0, v1
800BFBB4	sh     v0, $ffea(s0)

Lbfbb8:	; 800BFBB8
800BFBB8	lw     v0, $0002(s0)
800BFBBC	lh     v1, $0024(sp)
800BFBC0	srl    v0, v0, $08
800BFBC4	andi   v0, v0, $00fe
800BFBC8	addu   v0, v0, s4
800BFBCC	lh     v0, $00c8(v0)
800BFBD0	nop
800BFBD4	sll    a1, v0, $08
800BFBD8	beq    a1, s3, Lbfc30 [$800bfc30]
800BFBDC	sll    a0, v1, $10
800BFBE0	bgez   a1, Lbfc04 [$800bfc04]
800BFBE4	nop

Lbfbe8:	; 800BFBE8
800BFBE8	jal    funcc1dc4 [$800c1dc4]
800BFBEC	subu   a1, zero, a1
800BFBF0	lh     v1, $ffea(s0)
800BFBF4	nop
800BFBF8	sll    v1, v1, $10
800BFBFC	j      Lbfc1c [$800bfc1c]
800BFC00	subu   a0, v1, v0

Lbfc04:	; 800BFC04
800BFC04	jal    funcc1dc4 [$800c1dc4]
800BFC08	nop
800BFC0C	lh     v1, $ffea(s0)
800BFC10	nop
800BFC14	sll    v1, v1, $10
800BFC18	addu   a0, v1, v0

Lbfc1c:	; 800BFC1C
800BFC1C	sra    v0, a0, $10
800BFC20	sh     v0, $ffea(s0)
800BFC24	sra    v0, a0, $08
800BFC28	andi   v0, v0, $00ff
800BFC2C	sh     v0, $fffe(s0)

Lbfc30:	; 800BFC30
800BFC30	lw     v0, $0002(s0)
800BFC34	lh     v1, $0026(sp)
800BFC38	srl    v0, v0, $08
800BFC3C	andi   v0, v0, $00fe
800BFC40	addu   v0, v0, s4
800BFC44	lh     v0, $00d0(v0)

Lbfc48:	; 800BFC48
800BFC48	nop
800BFC4C	sll    a1, v0, $08
800BFC50	beq    a1, s3, Lbfca8 [$800bfca8]
800BFC54	sll    a0, v1, $10
800BFC58	bgez   a1, Lbfc7c [$800bfc7c]
800BFC5C	nop
800BFC60	jal    funcc1dc4 [$800c1dc4]
800BFC64	subu   a1, zero, a1
800BFC68	lh     v1, $ffec(s0)
800BFC6C	nop
800BFC70	sll    v1, v1, $10
800BFC74	j      Lbfc94 [$800bfc94]
800BFC78	subu   a0, v1, v0

Lbfc7c:	; 800BFC7C
800BFC7C	jal    funcc1dc4 [$800c1dc4]
800BFC80	nop
800BFC84	lh     v1, $ffec(s0)
800BFC88	nop
800BFC8C	sll    v1, v1, $10
800BFC90	addu   a0, v1, v0

Lbfc94:	; 800BFC94
800BFC94	sra    v0, a0, $10
800BFC98	sh     v0, $ffec(s0)
800BFC9C	sra    v0, a0, $08
800BFCA0	andi   v0, v0, $00ff
800BFCA4	sh     v0, $0000(s0)

Lbfca8:	; 800BFCA8
800BFCA8	addiu  s0, s0, $0038
800BFCAC	lhu    v0, $0006(s5)
800BFCB0	addiu  s2, s2, $0001
800BFCB4	slt    v0, s2, v0
800BFCB8	bne    v0, zero, Lbfa4c [$800bfa4c]
800BFCBC	addiu  s1, s1, $0038

Lbfcc0:	; 800BFCC0
800BFCC0	addiu  v0, zero, $0001

Lbfcc4:	; 800BFCC4
800BFCC4	lw     ra, $0040(sp)

Lbfcc8:	; 800BFCC8
800BFCC8	lw     s5, $003c(sp)
800BFCCC	lw     s4, $0038(sp)
800BFCD0	lw     s3, $0034(sp)
800BFCD4	lw     s2, $0030(sp)
800BFCD8	lw     s1, $002c(sp)
800BFCDC	lw     s0, $0028(sp)
800BFCE0	jr     ra 
800BFCE4	addiu  sp, sp, $0048



////////////////////////////////
// funcbfce8
800BFCE8-800BFEDC
////////////////////////////////



funcbfee0:	; 800BFEE0
800BFEE0	addiu  sp, sp, $ffd0 (=-$30)
800BFEE4	sw     ra, $0028(sp)
800BFEE8	sw     s5, $0024(sp)
800BFEEC	sw     s4, $0020(sp)
800BFEF0	sw     s3, $001c(sp)
800BFEF4	sw     s2, $0018(sp)
800BFEF8	sw     s1, $0014(sp)
800BFEFC	jal    funcbd4d4 [$800bd4d4]
800BFF00	sw     s0, $0010(sp)
800BFF04	lui    v0, $800d
800BFF08	addiu  v0, v0, $9da4 (=-$625c)
800BFF0C	lbu    v1, $0024(v0)
800BFF10	nop
800BFF14	beq    v1, zero, Lbff44 [$800bff44]
800BFF18	addu   a0, zero, zero
800BFF1C	addiu  a3, zero, $0010

funcbff20:	; 800BFF20
800BFF20	addiu  a2, zero, $0040
800BFF24	addu   a1, v1, zero
800BFF28	lw     v1, $0028(v0)

loopbff2c:	; 800BFF2C
800BFF2C	nop
800BFF30	lbu    v0, $0000(v1)
800BFF34	addiu  a0, a0, $0001
800BFF38	sltu   v0, a0, a1
800BFF3C	bne    v0, zero, loopbff2c [$800bff2c]
800BFF40	addiu  v1, v1, $000c

Lbff44:	; 800BFF44
800BFF44	jal    funcbf0c4 [$800bf0c4]
800BFF48	addu   s3, zero, zero
800BFF4C	jal    funcbf660 [$800bf660]
800BFF50	nop
800BFF54	lui    v0, $800d
800BFF58	addiu  s0, v0, $9da4 (=-$625c)
800BFF5C	lw     a0, $0010(s0)
800BFF60	jal    funcbede8 [$800bede8]
800BFF64	nop
800BFF68	jal    funcbdc44 [$800bdc44]
800BFF6C	nop
800BFF70	lui    v0, $800d
800BFF74	addiu  s4, v0, $a068 (=-$5f98)
800BFF78	lw     s1, $0010(s0)
800BFF7C	lhu    v0, $0004(s4)
800BFF80	lhu    v1, $0024(s1)
800BFF84	addiu  v0, v0, $ff60 (=-$a0)
800BFF88	subu   v1, v1, v0
800BFF8C	sh     v1, $0030(s1)
800BFF90	lhu    v0, $0006(s4)
800BFF94	lhu    v1, $0026(s1)
800BFF98	addiu  v0, v0, $ff90 (=-$70)
800BFF9C	subu   v1, v1, v0
800BFFA0	lw     v0, $0010(s1)
800BFFA4	sh     v1, $0032(s1)
800BFFA8	lhu    v1, $0006(s1)
800BFFAC	nop
800BFFB0	beq    v1, zero, Lc0010 [$800c0010]
800BFFB4	addu   a0, s1, v0
800BFFB8	addu   s5, s0, zero
800BFFBC	addu   s2, s3, zero
800BFFC0	addu   s0, a0, zero

loopbffc4:	; 800BFFC4
800BFFC4	lbu    v0, $0000(s0)
800BFFC8	nop
800BFFCC	andi   v0, v0, $0002
800BFFD0	beq    v0, zero, Lbfff8 [$800bfff8]
800BFFD4	nop
800BFFD8	lbu    v1, $0024(s0)
800BFFDC	lbu    v0, $0075(s4)
800BFFE0	nop
800BFFE4	bne    v1, v0, Lbfff8 [$800bfff8]
800BFFE8	addu   a0, s0, zero
800BFFEC	lw     a1, $001c(s5)
800BFFF0	jal    funcbe158 [$800be158]
800BFFF4	addu   a1, a1, s2

Lbfff8:	; 800BFFF8
800BFFF8	addiu  s2, s2, $0003
800BFFFC	lhu    v0, $0006(s1)

Lc0000:	; 800C0000
800C0000	addiu  s3, s3, $0001

Lc0004:	; 800C0004
800C0004	slt    v0, s3, v0
800C0008	bne    v0, zero, loopbffc4 [$800bffc4]
800C000C	addiu  s0, s0, $0038

Lc0010:	; 800C0010
800C0010	lw     ra, $0028(sp)

Lc0014:	; 800C0014
800C0014	lw     s5, $0024(sp)
800C0018	lw     s4, $0020(sp)

funcc001c:	; 800C001C
800C001C	lw     s3, $001c(sp)
800C0020	lw     s2, $0018(sp)

Lc0024:	; 800C0024
800C0024	lw     s1, $0014(sp)
800C0028	lw     s0, $0010(sp)

Lc002c:	; 800C002C
800C002C	addiu  v0, zero, $0001
800C0030	jr     ra 
800C0034	addiu  sp, sp, $0030


funcc0038:	; 800C0038
800C0038	lui    v0, $800d
800C003C	lw     v0, $a068(v0)
800C0040	addiu  sp, sp, $ffd0 (=-$30)
800C0044	sw     s0, $0020(sp)
800C0048	addu   s0, a0, zero
800C004C	sw     s1, $0024(sp)
800C0050	addu   s1, a1, zero

Lc0054:	; 800C0054
800C0054	andi   v0, v0, $0040
800C0058	bne    v0, zero, Lc0068 [$800c0068]
800C005C	sw     ra, $0028(sp)
800C0060	j      Lc02bc [$800c02bc]
800C0064	addu   v0, zero, zero

Lc0068:	; 800C0068
800C0068	lui    v0, $8006
800C006C	lw     v1, $794c(v0)
800C0070	nop
800C0074	lbu    a0, $0008(v1)

Lc0078:	; 800C0078
800C0078	addiu  v0, zero, $0005
800C007C	bne    a0, v0, Lc00bc [$800c00bc]
800C0080	addiu  v0, zero, $0001
800C0084	lw     a0, $001c(v1)
800C0088	nop
800C008C	lw     v0, $08e4(a0)
800C0090	nop

Lc0094:	; 800C0094
800C0094	lb     v1, $0008(v0)
800C0098	nop
800C009C	sll    v0, v1, $02
800C00A0	addu   v0, v0, v1
800C00A4	lw     v1, $08e0(a0)
800C00A8	sll    v0, v0, $02
800C00AC	addu   v0, v0, v1
800C00B0	lw     a3, $000c(v0)
800C00B4	j      Lc00d4 [$800c00d4]
800C00B8	lui    v0, $800d

Lc00bc:	; 800C00BC
800C00BC	bne    a0, v0, Lc00d0 [$800c00d0]
800C00C0	addu   a3, zero, zero
800C00C4	jal    func4ae00 [$8004ae00]
800C00C8	nop
800C00CC	addu   a3, v0, zero

Lc00d0:	; 800C00D0
800C00D0	lui    v0, $800d

Lc00d4:	; 800C00D4
800C00D4	lui    a1, $800d
800C00D8	addiu  a1, a1, $a068 (=-$5f98)
800C00DC	lw     a0, $9db4(v0)
800C00E0	lw     v0, $0004(a1)
800C00E4	lhu    v1, $0014(a3)

Lc00e8:	; 800C00E8
800C00E8	lw     a2, $0018(a0)
800C00EC	sw     v0, $0010(a1)
800C00F0	sh     v1, $0010(sp)
800C00F4	lhu    v0, $0018(a3)
800C00F8	addu   a2, a0, a2
800C00FC	lhu    a0, $0076(a1)
800C0100	lbu    v1, $0075(a1)
800C0104	subu   v0, v0, a0
800C0108	sh     v0, $0012(sp)
800C010C	sll    v0, v1, $01
800C0110	addu   v0, v0, v1
800C0114	sll    v0, v0, $02
800C0118	addu   v0, v0, v1

Lc011c:	; 800C011C
800C011C	sll    v0, v0, $02
800C0120	lhu    v1, $001c(a3)
800C0124	addu   a2, a2, v0
800C0128	sh     v1, $0014(sp)
800C012C	lh     v1, $0020(a2)
800C0130	lh     v0, $0022(a2)
800C0134	addiu  v1, v1, $00a0
800C0138	addiu  v0, v0, $0070
800C013C	sll    t4, v1, $10
800C0140	sll    t5, v0, $10
800C0144	ctc2   t4,mac0
800C0148	ctc2   t5,mac1
800C014C	lw     t0, $001c(a1)
800C0150	nop
800C0154	lw     t4, $0000(t0)
800C0158	lw     t5, $0004(t0)
800C015C	ctc2   t4,vxy0

funcc0160:	; 800C0160
800C0160	ctc2   t5,vz0
800C0164	lw     t4, $0008(t0)
800C0168	lw     t5, $000c(t0)
800C016C	lw     t6, $0010(t0)
800C0170	ctc2   t4,vxy1
800C0174	ctc2   t5,vz1
800C0178	ctc2   t6,vxy2
800C017C	lw     t4, $0014(t0)
800C0180	lw     t5, $0018(t0)
800C0184	ctc2   t4,vz2
800C0188	lw     t6, $001c(t0)
800C018C	ctc2   t5,rgb
800C0190	ctc2   t6,otz
800C0194	addiu  v0, sp, $0010
800C0198	lwc2   zero, $0000(v0)
800C019C	lwc2   at, $0004(v0)
800C01A0	nop
800C01A4	nop
800C01A8	gte_func16t8,r11r12
800C01AC	addiu  v0, sp, $0018
800C01B0	swc2   t6, $0000(v0)

Lc01b4:	; 800C01B4
800C01B4	lhu    v0, $0024(a2)
800C01B8	lh     a0, $0018(sp)
800C01BC	lhu    v1, $0026(a2)
800C01C0	sll    v0, v0, $10
800C01C4	sra    v0, v0, $11
800C01C8	addiu  v0, v0, $ff60 (=-$a0)
800C01CC	addu   a1, v0, a0
800C01D0	sll    v1, v1, $10
800C01D4	sra    v1, v1, $11
800C01D8	addiu  v1, v1, $ff90 (=-$70)
800C01DC	lh     v0, $001a(sp)
800C01E0	lh     a0, $0028(a2)
800C01E4	addu   v1, v1, v0
800C01E8	slt    v0, a1, a0
800C01EC	bne    v0, zero, Lc0208 [$800c0208]
800C01F0	nop
800C01F4	lh     a0, $002a(a2)
800C01F8	nop
800C01FC	slt    v0, a0, a1
800C0200	beq    v0, zero, Lc020c [$800c020c]
800C0204	nop

Lc0208:	; 800C0208
800C0208	addu   a1, a0, zero

Lc020c:	; 800C020C
800C020C	lh     a0, $002c(a2)
800C0210	nop
800C0214	slt    v0, v1, a0
800C0218	bne    v0, zero, Lc0234 [$800c0234]
800C021C	nop
800C0220	lh     a0, $002e(a2)
800C0224	nop
800C0228	slt    v0, a0, v1
800C022C	beq    v0, zero, Lc023c [$800c023c]
800C0230	lui    v0, $800d

Lc0234:	; 800C0234
800C0234	addu   v1, a0, zero
800C0238	lui    v0, $800d

Lc023c:	; 800C023C
800C023C	addiu  a0, v0, $a068 (=-$5f98)
800C0240	addiu  v0, zero, $ffff (=-$1)
800C0244	sh     a1, $0014(a0)
800C0248	bne    s0, v0, Lc025c [$800c025c]
800C024C	sh     v1, $0016(a0)
800C0250	addiu  v0, zero, $001e
800C0254	j      Lc0260 [$800c0260]
800C0258	sh     v0, $001a(a0)

Lc025c:	; 800C025C
800C025C	sh     s0, $001a(a0)

Lc0260:	; 800C0260
800C0260	lui    a0, $800d
800C0264	addiu  v0, a0, $a068 (=-$5f98)
800C0268	addiu  v1, zero, $0001
800C026C	sh     v1, $0018(v0)
800C0270	addiu  v0, zero, $ffff (=-$1)
800C0274	bne    s1, v0, Lc0294 [$800c0294]
800C0278	addiu  v1, zero, $fff0 (=-$10)
800C027C	lw     v0, $a068(a0)
800C0280	addiu  v1, zero, $fff8 (=-$8)
800C0284	and    v0, v0, v1
800C0288	ori    v0, v0, $0003
800C028C	j      Lc02b8 [$800c02b8]
800C0290	sw     v0, $a068(a0)

Lc0294:	; 800C0294
800C0294	lw     v0, $a068(a0)
800C0298	nop
800C029C	and    a1, v0, v1
800C02A0	ori    v1, a1, $0003
800C02A4	addiu  v0, zero, $0008
800C02A8	bne    s1, v0, Lc02b8 [$800c02b8]
800C02AC	sw     v1, $a068(a0)
800C02B0	ori    v0, a1, $000b
800C02B4	sw     v0, $a068(a0)

Lc02b8:	; 800C02B8
800C02B8	addiu  v0, zero, $0001

Lc02bc:	; 800C02BC
800C02BC	lw     ra, $0028(sp)
800C02C0	lw     s1, $0024(sp)
800C02C4	lw     s0, $0020(sp)
800C02C8	jr     ra 
800C02CC	addiu  sp, sp, $0030


funcc02d0:	; 800C02D0
800C02D0	addiu  sp, sp, $ffc0 (=-$40)

funcc02d4:	; 800C02D4
800C02D4	lui    v0, $800d
800C02D8	lui    t4, $800d
800C02DC	lhu    v1, $9da0(t4)
800C02E0	lw     t1, $0050(sp)
800C02E4	lw     t2, $0054(sp)
800C02E8	lw     t3, $0058(sp)
800C02EC	addiu  t0, v0, $a140 (=-$5ec0)
800C02F0	sw     ra, $003c(sp)
800C02F4	sw     fp, $0038(sp)
800C02F8	sw     s7, $0034(sp)
800C02FC	sw     s6, $0030(sp)
800C0300	sw     s5, $002c(sp)
800C0304	sw     s4, $0028(sp)
800C0308	sw     s3, $0024(sp)

funcc030c:	; 800C030C
800C030C	sw     s2, $0020(sp)
800C0310	sw     s1, $001c(sp)
800C0314	sw     s0, $0018(sp)
800C0318	sll    v0, v1, $03
800C031C	subu   v0, v0, v1
800C0320	sll    v0, v0, $03
800C0324	subu   v0, v0, v1
800C0328	sll    v0, v0, $02
800C032C	addu   v0, v0, t0
800C0330	addu   fp, t1, zero
800C0334	addu   s7, t2, zero
800C0338	sh     a0, $0004(v0)
800C033C	sh     a1, $0006(v0)

Lc0340:	; 800C0340
800C0340	sh     a2, $0008(v0)
800C0344	sb     a3, $0000(v0)
800C0348	sb     a3, $0010(sp)
800C034C	sll    a3, a3, $18
800C0350	bltz   a3, Lc060c [$800c060c]
800C0354	addu   s6, t3, zero

Lc0358:	; 800C0358
800C0358	addu   s5, zero, zero

funcc035c:	; 800C035C
800C035C	addu   s1, t4, zero
800C0360	addiu  s2, t0, $000c

funcc0364:	; 800C0364
800C0364	lhu    v1, $9da0(s1)
800C0368	addiu  s3, t0, $006c
800C036C	sll    v0, v1, $03
800C0370	subu   v0, v0, v1
800C0374	sll    v0, v0, $03
800C0378	subu   v0, v0, v1
800C037C	sll    v0, v0, $02
800C0380	addu   v0, v0, t0
800C0384	sb     t1, $0001(v0)
800C0388	lhu    v1, $9da0(s1)
800C038C	addiu  s4, zero, $0060
800C0390	sll    v0, v1, $03
800C0394	subu   v0, v0, v1
800C0398	sll    v0, v0, $03
800C039C	subu   v0, v0, v1
800C03A0	sll    v0, v0, $02
800C03A4	addu   v0, v0, t0
800C03A8	sb     t2, $0002(v0)
800C03AC	lhu    v1, $9da0(s1)

Lc03b0:	; 800C03B0
800C03B0	addu   s0, s5, zero
800C03B4	sll    v0, v1, $03
800C03B8	subu   v0, v0, v1
800C03BC	sll    v0, v0, $03
800C03C0	subu   v0, v0, v1
800C03C4	sll    v0, v0, $02
800C03C8	addu   v0, v0, t0
800C03CC	sb     t3, $0003(v0)

Lc03d0:	; 800C03D0
800C03D0	lhu    v0, $9da0(s1)
800C03D4	nop
800C03D8	sll    a0, v0, $03
800C03DC	subu   a0, a0, v0
800C03E0	sll    a0, a0, $03
800C03E4	subu   a0, a0, v0
800C03E8	sll    a0, a0, $02
800C03EC	addu   a0, a0, s2
800C03F0	jal    func630e8 [$800630e8]
800C03F4	addu   a0, a0, s0
800C03F8	lhu    v1, $9da0(s1)
800C03FC	nop
800C0400	sll    v0, v1, $03
800C0404	subu   v0, v0, v1

Lc0408:	; 800C0408
800C0408	sll    v0, v0, $03
800C040C	subu   v0, v0, v1
800C0410	sll    v0, v0, $02

Lc0414:	; 800C0414
800C0414	addu   v0, s0, v0
800C0418	addu   v0, v0, s2
800C041C	sb     fp, $0004(v0)
800C0420	lhu    v1, $9da0(s1)
800C0424	nop
800C0428	sll    v0, v1, $03
800C042C	subu   v0, v0, v1

funcc0430:	; 800C0430
800C0430	sll    v0, v0, $03
800C0434	subu   v0, v0, v1
800C0438	sll    v0, v0, $02
800C043C	addu   v0, s0, v0
800C0440	addu   v0, v0, s2
800C0444	sb     s7, $0005(v0)
800C0448	lhu    v1, $9da0(s1)
800C044C	nop
800C0450	sll    v0, v1, $03
800C0454	subu   v0, v0, v1
800C0458	sll    v0, v0, $03
800C045C	subu   v0, v0, v1
800C0460	sll    v0, v0, $02
800C0464	addu   v0, s0, v0
800C0468	addu   v0, v0, s2
800C046C	sb     s6, $0006(v0)
800C0470	lhu    v0, $9da0(s1)
800C0474	nop
800C0478	sll    a0, v0, $03
800C047C	subu   a0, a0, v0
800C0480	sll    a0, a0, $03
800C0484	subu   a0, a0, v0
800C0488	sll    a0, a0, $02
800C048C	addu   a0, a0, s2
800C0490	jal    func630e8 [$800630e8]
800C0494	addu   a0, a0, s4
800C0498	lhu    v1, $9da0(s1)
800C049C	nop
800C04A0	sll    v0, v1, $03
800C04A4	subu   v0, v0, v1
800C04A8	sll    v0, v0, $03
800C04AC	subu   v0, v0, v1
800C04B0	sll    v0, v0, $02
800C04B4	addu   v0, v0, s0
800C04B8	addu   v0, v0, s3

Lc04bc:	; 800C04BC
800C04BC	sb     fp, $0004(v0)
800C04C0	lhu    v1, $9da0(s1)
800C04C4	nop
800C04C8	sll    v0, v1, $03
800C04CC	subu   v0, v0, v1
800C04D0	sll    v0, v0, $03
800C04D4	subu   v0, v0, v1
800C04D8	sll    v0, v0, $02
800C04DC	addu   v0, v0, s0
800C04E0	addu   v0, v0, s3
800C04E4	sb     s7, $0005(v0)
800C04E8	lhu    v1, $9da0(s1)
800C04EC	nop
800C04F0	sll    v0, v1, $03
800C04F4	subu   v0, v0, v1
800C04F8	sll    v0, v0, $03
800C04FC	subu   v0, v0, v1
800C0500	sll    v0, v0, $02
800C0504	addu   v0, v0, s0
800C0508	addu   v0, v0, s3
800C050C	sb     s6, $0006(v0)
800C0510	lbu    t5, $0010(sp)
800C0514	nop
800C0518	sll    v0, t5, $18
800C051C	sra    v0, v0, $18
800C0520	slti   v0, v0, $0004
800C0524	bne    v0, zero, Lc0590 [$800c0590]
800C0528	nop
800C052C	lhu    v1, $9da0(s1)
800C0530	nop
800C0534	sll    v0, v1, $03
800C0538	subu   v0, v0, v1
800C053C	sll    v0, v0, $03
800C0540	subu   v0, v0, v1

funcc0544:	; 800C0544
800C0544	sll    v0, v0, $02
800C0548	addu   v0, s0, v0
800C054C	addu   v0, v0, s2
800C0550	lbu    v1, $0007(v0)
800C0554	nop
800C0558	andi   v1, v1, $00fd
800C055C	sb     v1, $0007(v0)
800C0560	lhu    v1, $9da0(s1)
800C0564	nop
800C0568	sll    v0, v1, $03
800C056C	subu   v0, v0, v1
800C0570	sll    v0, v0, $03
800C0574	subu   v0, v0, v1
800C0578	sll    v0, v0, $02
800C057C	addu   v0, v0, s0
800C0580	addu   v0, v0, s3

Lc0584:	; 800C0584
800C0584	lbu    v1, $0007(v0)
800C0588	j      Lc05f4 [$800c05f4]
800C058C	andi   v1, v1, $00fd

Lc0590:	; 800C0590
800C0590	lhu    v1, $9da0(s1)
800C0594	nop
800C0598	sll    v0, v1, $03
800C059C	subu   v0, v0, v1
800C05A0	sll    v0, v0, $03
800C05A4	subu   v0, v0, v1
800C05A8	sll    v0, v0, $02
800C05AC	addu   v0, s0, v0
800C05B0	addu   v0, v0, s2
800C05B4	lbu    v1, $0007(v0)
800C05B8	nop
800C05BC	ori    v1, v1, $0002
800C05C0	sb     v1, $0007(v0)
800C05C4	lhu    v1, $9da0(s1)
800C05C8	nop
800C05CC	sll    v0, v1, $03
800C05D0	subu   v0, v0, v1
800C05D4	sll    v0, v0, $03
800C05D8	subu   v0, v0, v1
800C05DC	sll    v0, v0, $02
800C05E0	addu   v0, v0, s0
800C05E4	addu   v0, v0, s3
800C05E8	lbu    v1, $0007(v0)
800C05EC	nop
800C05F0	ori    v1, v1, $0002

Lc05f4:	; 800C05F4
800C05F4	sb     v1, $0007(v0)
800C05F8	addiu  s4, s4, $0018
800C05FC	addiu  s5, s5, $0001
800C0600	sltiu  v0, s5, $0004
800C0604	bne    v0, zero, Lc03d0 [$800c03d0]
800C0608	addiu  s0, s0, $0018

Lc060c:	; 800C060C
800C060C	lui    v1, $800d
800C0610	lhu    v0, $9da0(v1)
800C0614	lw     ra, $003c(sp)
800C0618	lw     fp, $0038(sp)
800C061C	lw     s7, $0034(sp)
800C0620	lw     s6, $0030(sp)
800C0624	lw     s5, $002c(sp)
800C0628	lw     s4, $0028(sp)
800C062C	lw     s3, $0024(sp)
800C0630	lw     s2, $0020(sp)
800C0634	lw     s1, $001c(sp)
800C0638	lw     s0, $0018(sp)
800C063C	addiu  v0, v0, $0001
800C0640	sh     v0, $9da0(v1)
800C0644	addiu  v0, zero, $0001
800C0648	jr     ra 
800C064C	addiu  sp, sp, $0040

800C0650	addu   t4, a1, zero
800C0654	addu   t3, a2, zero
800C0658	lui    t5, $800d
800C065C	addiu  t1, t5, $9da4 (=-$625c)
800C0660	lw     v0, $0020(t1)
800C0664	nop
800C0668	addu   v0, v0, a0
800C066C	lbu    t6, $0000(v0)
800C0670	lw     t0, $0010(t1)
800C0674	beq    t6, zero, Lc070c [$800c070c]
800C0678	addu   t2, a3, zero
800C067C	sll    v0, a0, $03
800C0680	subu   v0, v0, a0
800C0684	lw     v1, $0010(t0)
800C0688	sll    v0, v0, $03

Lc068c:	; 800C068C
800C068C	addu   v1, t0, v1
800C0690	addu   v1, v1, v0
800C0694	lw     v0, $9da4(t5)
800C0698	lhu    a2, $0026(v1)
800C069C	lbu    v0, $0000(v0)
800C06A0	lw     t0, $0030(v1)
800C06A4	beq    v0, zero, Lc06b0 [$800c06b0]
800C06A8	addu   a3, zero, zero
800C06AC	andi   a3, a2, $ffff

Lc06b0:	; 800C06B0
800C06B0	andi   a2, a2, $ffff
800C06B4	beq    a2, zero, Lc06f4 [$800c06f4]
800C06B8	addu   a1, zero, zero

loopc06bc:	; 800C06BC
800C06BC	andi   v0, a1, $ffff
800C06C0	addiu  a1, a1, $0001
800C06C4	addu   v0, v0, a3
800C06C8	sll    v1, v0, $01
800C06CC	addu   v1, v1, v0
800C06D0	sll    v1, v1, $03
800C06D4	addu   v1, v1, t0
800C06D8	addiu  v1, v1, $0008
800C06DC	andi   v0, a1, $ffff
800C06E0	sltu   v0, v0, a2
800C06E4	sb     t4, $0004(v1)
800C06E8	sb     t3, $0005(v1)
800C06EC	bne    v0, zero, loopc06bc [$800c06bc]
800C06F0	sb     t2, $0006(v1)

Lc06f4:	; 800C06F4
800C06F4	lui    v0, $800d
800C06F8	lw     v1, $9dc4(v0)
800C06FC	addu   v0, zero, zero
800C0700	addu   v1, v1, a0
800C0704	jr     ra 
800C0708	sb     zero, $0000(v1)


Lc070c:	; 800C070C
800C070C	sll    v1, a0, $01
800C0710	lw     v0, $001c(t1)
800C0714	addu   v1, v1, a0
800C0718	addu   v0, v1, v0
800C071C	sb     a1, $0000(v0)
800C0720	lw     v0, $001c(t1)
800C0724	nop
800C0728	addu   v0, v1, v0

funcc072c:	; 800C072C
800C072C	sb     a2, $0001(v0)
800C0730	lw     v0, $001c(t1)
800C0734	nop
800C0738	addu   v1, v1, v0
800C073C	sb     a3, $0002(v1)
800C0740	sll    v0, a0, $03
800C0744	subu   v0, v0, a0
800C0748	lw     v1, $0010(t0)
800C074C	sll    v0, v0, $03
800C0750	addu   v1, t0, v1
800C0754	addu   v1, v1, v0
800C0758	lw     v0, $9da4(t5)
800C075C	lhu    a2, $0026(v1)
800C0760	lbu    v0, $0000(v0)
800C0764	lw     t0, $0030(v1)
800C0768	beq    v0, zero, Lc0774 [$800c0774]
800C076C	addu   a3, zero, zero
800C0770	andi   a3, a2, $ffff

Lc0774:	; 800C0774
800C0774	andi   a2, a2, $ffff
800C0778	sltu   v0, t6, a2
800C077C	beq    v0, zero, Lc07bc [$800c07bc]
800C0780	addu   a1, zero, zero

loopc0784:	; 800C0784
800C0784	andi   v0, a1, $ffff
800C0788	addiu  a1, a1, $0001
800C078C	addu   v0, v0, a3
800C0790	sll    v1, v0, $01
800C0794	addu   v1, v1, v0
800C0798	sll    v1, v1, $03
800C079C	addu   v1, v1, t0
800C07A0	addiu  v1, v1, $0008
800C07A4	andi   v0, a1, $ffff
800C07A8	sltu   v0, v0, a2
800C07AC	sb     t4, $0004(v1)
800C07B0	sb     t3, $0005(v1)
800C07B4	bne    v0, zero, loopc0784 [$800c0784]
800C07B8	sb     t2, $0006(v1)

Lc07bc:	; 800C07BC
800C07BC	lui    v0, $800d
800C07C0	lw     v1, $9dc4(v0)
800C07C4	addiu  v0, zero, $0001
800C07C8	addu   v1, v1, a0
800C07CC	addu   a0, v0, zero
800C07D0	jr     ra 

Lc07d4:	; 800C07D4
800C07D4	sb     a0, $0000(v1)

800C07D8	addiu  sp, sp, $ffd0 (=-$30)
800C07DC	addu   t6, a2, zero
800C07E0	addu   t7, a3, zero
800C07E4	andi   v0, t7, $00ff
800C07E8	addiu  v0, v0, $ffff (=-$1)
800C07EC	lui    t0, $800d
800C07F0	lw     t2, $0040(sp)
800C07F4	lbu    t3, $0044(sp)
800C07F8	lbu    t4, $0048(sp)
800C07FC	lbu    t5, $004c(sp)
800C0800	addiu  t0, t0, $9da4 (=-$625c)
800C0804	sw     ra, $002c(sp)
800C0808	sw     s2, $0028(sp)
800C080C	sw     s1, $0024(sp)
800C0810	sw     s0, $0020(sp)
800C0814	andi   v1, t2, $00ff
800C0818	subu   s1, v1, v0
800C081C	sll    t1, s1, $02
800C0820	addiu  t1, t1, $002c
800C0824	sll    v0, a0, $01
800C0828	addu   v0, v0, a0
800C082C	lw     v1, $0028(t0)
800C0830	sll    v0, v0, $02
800C0834	addu   s2, v1, v0
800C0838	lbu    a2, $0001(s2)
800C083C	addiu  v0, zero, $0080

funcc0840:	; 800C0840
800C0840	sb     v0, $0000(s2)
800C0844	sw     t1, $0008(s2)
800C0848	lw     a0, $0010(t0)
800C084C	sll    v0, a2, $03
800C0850	subu   v0, v0, a2
800C0854	sll    v0, v0, $03
800C0858	lw     v1, $0010(a0)
800C085C	lw     a2, $0034(t0)
800C0860	addu   v1, a0, v1
800C0864	addu   v0, v0, v1
800C0868	addu   t1, a2, t1
800C086C	lw     v0, $002c(v0)
800C0870	lw     v1, $002c(t0)
800C0874	addu   a0, a0, v0
800C0878	lw     a0, $0000(a0)
800C087C	lw     v0, $0028(t0)
800C0880	addu   s0, v1, a2
800C0884	sw     t1, $0034(t0)
800C0888	subu   v0, s0, v0
800C088C	sw     v0, $0004(s2)
800C0890	addiu  v0, zero, $0001
800C0894	andi   t1, a0, $01ff
800C0898	sb     v0, $0000(s0)
800C089C	sltiu  v0, t6, $0002
800C08A0	sb     s1, $0001(s0)
800C08A4	sb     a3, $0002(s0)
800C08A8	sb     t2, $0003(s0)
800C08AC	sw     t6, $0008(s0)
800C08B0	bne    v0, zero, Lc0a74 [$800c0a74]

Lc08b4:	; 800C08B4
800C08B4	sw     zero, $000c(s0)
800C08B8	andi   v1, t3, $00ff
800C08BC	sll    v0, v1, $10
800C08C0	andi   a2, t4, $00ff
800C08C4	sw     v0, $0010(sp)
800C08C8	sll    v0, a2, $10
800C08CC	andi   a3, t5, $00ff
800C08D0	sw     v0, $0014(sp)
800C08D4	sll    v0, a3, $10
800C08D8	andi   a1, a1, $00ff
800C08DC	addiu  t0, zero, $0001
800C08E0	beq    a1, t0, Lc0984 [$800c0984]
800C08E4	sw     v0, $0018(sp)
800C08E8	slti   v0, a1, $0002
800C08EC	beq    v0, zero, Lc0904 [$800c0904]
800C08F0	addiu  v0, zero, $0002
800C08F4	beq    a1, zero, Lc0914 [$800c0914]
800C08F8	sll    a1, v1, $18
800C08FC	j      Lc0b08 [$800c0b08]
800C0900	nop

Lc0904:	; 800C0904
800C0904	beq    a1, v0, Lc0a04 [$800c0a04]
800C0908	sll    a1, v1, $18

funcc090c:	; 800C090C
800C090C	j      Lc0b08 [$800c0b08]
800C0910	nop

Lc0914:	; 800C0914
800C0914	sll    v0, t6, $10
800C0918	divu   a1, v0
800C091C	bne    v0, zero, Lc0928 [$800c0928]
800C0920	nop
800C0924	break   $01c00

Lc0928:	; 800C0928
800C0928	mflo   a1

Lc092c:	; 800C092C
800C092C	sll    v1, a2, $18
800C0930	nop
800C0934	divu   v1, v0
800C0938	bne    v0, zero, Lc0944 [$800c0944]
800C093C	nop
800C0940	break   $01c00

Lc0944:	; 800C0944
800C0944	mflo   v1
800C0948	sll    a0, a3, $18
800C094C	nop
800C0950	divu   a0, v0
800C0954	bne    v0, zero, Lc0960 [$800c0960]
800C0958	nop
800C095C	break   $01c00

Lc0960:	; 800C0960
800C0960	mflo   a0
800C0964	sll    a1, a1, $08
800C0968	sll    v1, v1, $08
800C096C	sll    a0, a0, $08
800C0970	sw     a1, $0010(sp)
800C0974	sw     v1, $0014(sp)
800C0978	sw     a0, $0018(sp)
800C097C	j      Lc0b08 [$800c0b08]
800C0980	sh     zero, $0004(s0)

Lc0984:	; 800C0984
800C0984	sll    v0, v1, $18
800C0988	sll    a0, t6, $10
800C098C	divu   v0, a0
800C0990	bne    a0, zero, Lc099c [$800c099c]
800C0994	nop
800C0998	break   $01c00

Lc099c:	; 800C099C
800C099C	mflo   v0
800C09A0	sll    v1, a2, $18

funcc09a4:	; 800C09A4
800C09A4	nop
800C09A8	divu   v1, a0
800C09AC	bne    a0, zero, Lc09b8 [$800c09b8]
800C09B0	nop
800C09B4	break   $01c00

Lc09b8:	; 800C09B8
800C09B8	mflo   v1
800C09BC	sll    a1, a3, $18
800C09C0	nop
800C09C4	divu   a1, a0
800C09C8	bne    a0, zero, Lc09d4 [$800c09d4]
800C09CC	nop

Lc09d0:	; 800C09D0
800C09D0	break   $01c00

Lc09d4:	; 800C09D4
800C09D4	mflo   a1

funcc09d8:	; 800C09D8
800C09D8	sll    v0, v0, $08
800C09DC	subu   v0, zero, v0
800C09E0	sll    v1, v1, $08
800C09E4	subu   v1, zero, v1
800C09E8	sll    a1, a1, $08

funcc09ec:	; 800C09EC
800C09EC	subu   a1, zero, a1
800C09F0	sw     v0, $0010(sp)
800C09F4	sw     v1, $0014(sp)
800C09F8	sw     a1, $0018(sp)
800C09FC	j      Lc0b08 [$800c0b08]
800C0A00	sh     zero, $0004(s0)

Lc0a04:	; 800C0A04
800C0A04	sll    v0, t6, $10
800C0A08	divu   a1, v0
800C0A0C	bne    v0, zero, Lc0a18 [$800c0a18]
800C0A10	nop
800C0A14	break   $01c00

Lc0a18:	; 800C0A18
800C0A18	mflo   a1
800C0A1C	sll    v1, a2, $18
800C0A20	nop
800C0A24	divu   v1, v0
800C0A28	bne    v0, zero, Lc0a34 [$800c0a34]
800C0A2C	nop
800C0A30	break   $01c00

Lc0a34:	; 800C0A34
800C0A34	mflo   v1
800C0A38	sll    a0, a3, $18

funcc0a3c:	; 800C0A3C
800C0A3C	nop
800C0A40	divu   a0, v0
800C0A44	bne    v0, zero, Lc0a50 [$800c0a50]
800C0A48	nop
800C0A4C	break   $01c00

Lc0a50:	; 800C0A50
800C0A50	mflo   a0
800C0A54	sll    a1, a1, $08
800C0A58	sll    v1, v1, $08
800C0A5C	sll    a0, a0, $08
800C0A60	sw     a1, $0010(sp)
800C0A64	sw     v1, $0014(sp)
800C0A68	sw     a0, $0018(sp)
800C0A6C	j      Lc0b08 [$800c0b08]

funcc0a70:	; 800C0A70
800C0A70	sh     t0, $0004(s0)

Lc0a74:	; 800C0A74
800C0A74	andi   a1, a1, $00ff
800C0A78	addiu  v1, zero, $0001
800C0A7C	beq    a1, v1, Lc0ac4 [$800c0ac4]
800C0A80	slti   v0, a1, $0002
800C0A84	beq    v0, zero, Lc0a9c [$800c0a9c]
800C0A88	nop
800C0A8C	beq    a1, zero, Lc0ab0 [$800c0ab0]
800C0A90	andi   v0, t3, $00ff
800C0A94	j      Lc0b08 [$800c0b08]
800C0A98	nop

Lc0a9c:	; 800C0A9C
800C0A9C	addiu  v0, zero, $0002
800C0AA0	beq    a1, v0, Lc0af0 [$800c0af0]
800C0AA4	andi   v0, t3, $00ff
800C0AA8	j      Lc0b08 [$800c0b08]
800C0AAC	nop

Lc0ab0:	; 800C0AB0
800C0AB0	sw     v0, $0010(sp)
800C0AB4	andi   v0, t4, $00ff
800C0AB8	sw     v0, $0014(sp)
800C0ABC	j      Lc0ae4 [$800c0ae4]
800C0AC0	andi   v0, t5, $00ff

Lc0ac4:	; 800C0AC4
800C0AC4	andi   v0, t3, $00ff
800C0AC8	subu   v0, zero, v0

funcc0acc:	; 800C0ACC
800C0ACC	sw     v0, $0010(sp)
800C0AD0	andi   v0, t4, $00ff
800C0AD4	subu   v0, zero, v0
800C0AD8	sw     v0, $0014(sp)
800C0ADC	andi   v0, t5, $00ff
800C0AE0	subu   v0, zero, v0

Lc0ae4:	; 800C0AE4
800C0AE4	sw     v0, $0018(sp)
800C0AE8	j      Lc0b08 [$800c0b08]
800C0AEC	sh     zero, $0004(s0)

Lc0af0:	; 800C0AF0
800C0AF0	sw     v0, $0010(sp)
800C0AF4	andi   v0, t4, $00ff
800C0AF8	sw     v0, $0014(sp)
800C0AFC	andi   v0, t5, $00ff
800C0B00	sw     v0, $0018(sp)
800C0B04	sh     v1, $0004(s0)

Lc0b08:	; 800C0B08
800C0B08	lw     v0, $0010(sp)
800C0B0C	nop
800C0B10	sw     v0, $0010(s0)
800C0B14	lw     v0, $0014(sp)
800C0B18	addiu  a0, s0, $0024
800C0B1C	sw     v0, $0014(s0)
800C0B20	lw     v1, $0018(sp)
800C0B24	addiu  v0, zero, $002c
800C0B28	sw     v0, $001c(s0)
800C0B2C	sll    v0, s1, $01
800C0B30	lw     a1, $001c(s0)
800C0B34	addiu  v0, v0, $002c
800C0B38	sw     v0, $0020(s0)
800C0B3C	andi   v0, t7, $00ff
800C0B40	sh     v0, $0024(s0)
800C0B44	addiu  v0, zero, $0001
800C0B48	sh     t1, $0026(s0)
800C0B4C	sh     s1, $0028(s0)
800C0B50	sh     v0, $002a(s0)
800C0B54	addu   a1, s0, a1
800C0B58	jal    func133b0 [$800133b0]
800C0B5C	sw     v1, $0018(s0)
800C0B60	lw     v0, $0020(s0)
800C0B64	addu   a2, zero, zero
800C0B68	blez   s1, Lc0b94 [$800c0b94]

funcc0b6c:	; 800C0B6C
800C0B6C	addu   a0, s0, v0
800C0B70	andi   v0, a2, $ffff

loopc0b74:	; 800C0B74
800C0B74	sll    v0, v0, $01
800C0B78	addu   v0, v0, a0
800C0B7C	lhu    v1, $0000(v0)
800C0B80	addiu  a2, a2, $0001
800C0B84	andi   v0, a2, $ffff
800C0B88	slt    v0, v0, s1
800C0B8C	bne    v0, zero, loopc0b74 [$800c0b74]
800C0B90	andi   v0, a2, $ffff

Lc0b94:	; 800C0B94
800C0B94	lui    v1, $800d
800C0B98	addiu  v1, v1, $9da4 (=-$625c)
800C0B9C	lw     a0, $0034(v1)
800C0BA0	lw     a1, $0008(s2)
800C0BA4	nop
800C0BA8	addu   a0, a0, a1
800C0BAC	sw     a0, $0034(v1)
800C0BB0	lw     ra, $002c(sp)
800C0BB4	lw     s2, $0028(sp)
800C0BB8	lw     s1, $0024(sp)
800C0BBC	lw     s0, $0020(sp)
800C0BC0	addiu  v0, zero, $0001
800C0BC4	jr     ra 
800C0BC8	addiu  sp, sp, $0030


funcc0bcc:	; 800C0BCC
800C0BCC	lui    v0, $800d
800C0BD0	lw     a3, $9db4(v0)
800C0BD4	sll    v0, a0, $01
800C0BD8	addu   v0, v0, a0
800C0BDC	sll    v0, v0, $02
800C0BE0	addu   v0, v0, a0
800C0BE4	sll    v0, v0, $02
800C0BE8	lui    t0, $800d
800C0BEC	addiu  a1, t0, $a068 (=-$5f98)
800C0BF0	lw     v1, $0018(a3)
800C0BF4	lw     a2, $0020(a1)
800C0BF8	addu   v1, a3, v1
800C0BFC	addu   v1, v1, v0

Lc0c00:	; 800C0C00
800C0C00	lhu    v0, $0000(v1)

funcc0c04:	; 800C0C04
800C0C04	nop
800C0C08	sh     v0, $0000(a2)
800C0C0C	lhu    t1, $0000(v1)
800C0C10	nop
800C0C14	ctc2   t1,mac2
800C0C18	lw     a2, $001c(a1)
800C0C1C	lhu    v0, $0002(v1)
800C0C20	nop
800C0C24	sh     v0, $0000(a2)
800C0C28	lw     a2, $001c(a1)
800C0C2C	lhu    v0, $0004(v1)
800C0C30	nop
800C0C34	sh     v0, $0002(a2)

Lc0c38:	; 800C0C38
800C0C38	lw     a2, $001c(a1)
800C0C3C	lhu    v0, $0006(v1)
800C0C40	nop
800C0C44	sh     v0, $0004(a2)
800C0C48	lw     a2, $001c(a1)
800C0C4C	lhu    v0, $0008(v1)
800C0C50	nop
800C0C54	sh     v0, $0006(a2)
800C0C58	lw     a2, $001c(a1)
800C0C5C	lhu    v0, $000a(v1)
800C0C60	nop
800C0C64	sh     v0, $0008(a2)
800C0C68	lw     a2, $001c(a1)
800C0C6C	lhu    v0, $000c(v1)
800C0C70	nop
800C0C74	sh     v0, $000a(a2)
800C0C78	lw     a2, $001c(a1)

funcc0c7c:	; 800C0C7C
800C0C7C	lhu    v0, $000e(v1)
800C0C80	nop
800C0C84	sh     v0, $000c(a2)
800C0C88	lw     a2, $001c(a1)
800C0C8C	lhu    v0, $0010(v1)
800C0C90	nop
800C0C94	sh     v0, $000e(a2)
800C0C98	lw     a2, $001c(a1)
800C0C9C	lhu    v0, $0012(v1)

Lc0ca0:	; 800C0CA0
800C0CA0	nop
800C0CA4	sh     v0, $0010(a2)
800C0CA8	lw     a2, $001c(a1)
800C0CAC	lw     v0, $0014(v1)
800C0CB0	nop
800C0CB4	sw     v0, $0014(a2)
800C0CB8	lw     a2, $001c(a1)
800C0CBC	lw     v0, $0018(v1)
800C0CC0	nop
800C0CC4	sw     v0, $0018(a2)
800C0CC8	lw     a2, $001c(a1)
800C0CCC	lw     v0, $001c(v1)

funcc0cd0:	; 800C0CD0
800C0CD0	nop
800C0CD4	sw     v0, $001c(a2)
800C0CD8	lhu    v0, $002a(v1)
800C0CDC	nop
800C0CE0	sh     v0, $002a(a3)
800C0CE4	lhu    v0, $002e(v1)
800C0CE8	nop
800C0CEC	sh     v0, $002e(a3)
800C0CF0	sb     a0, $0075(a1)
800C0CF4	lui    a0, $8006
800C0CF8	lw     v0, $a068(t0)
800C0CFC	lw     a0, $794c(a0)
800C0D00	ori    v0, v0, $0080
800C0D04	sw     v0, $a068(t0)
800C0D08	lw     v0, $001c(a0)
800C0D0C	nop
800C0D10	lw     v0, $08e4(v0)
800C0D14	nop
800C0D18	lw     v0, $000c(v0)
800C0D1C	nop
800C0D20	lw     a0, $0014(v0)

funcc0d24:	; 800C0D24
800C0D24	lhu    v0, $0030(v1)
800C0D28	nop
800C0D2C	sh     v0, $0030(a0)
800C0D30	jr     ra 
800C0D34	addiu  v0, zero, $0001

800C0D38	jr     ra 
800C0D3C	nop


funcc0d40:	; 800C0D40
800C0D40	lw     t0, $0010(sp)
800C0D44	lw     v1, $0014(sp)
800C0D48	lui    v0, $800d
800C0D4C	sw     a0, $9da4(v0)
800C0D50	addiu  v0, v0, $9da4 (=-$625c)

Lc0d54:	; 800C0D54
800C0D54	sw     a1, $0004(v0)
800C0D58	sw     a2, $0008(v0)
800C0D5C	sw     a3, $000c(v0)
800C0D60	sw     zero, $0010(v0)
800C0D64	sb     zero, $0024(v0)

Lc0d68:	; 800C0D68
800C0D68	sw     zero, $0028(v0)
800C0D6C	sw     zero, $002c(v0)

Lc0d70:	; 800C0D70
800C0D70	sw     zero, $0030(v0)
800C0D74	sw     zero, $0034(v0)
800C0D78	sw     t0, $0014(v0)
800C0D7C	sw     v1, $0018(v0)
800C0D80	sw     v1, $001c(v0)
800C0D84	jr     ra 
800C0D88	sw     v1, $0020(v0)


funcc0d8c:	; 800C0D8C
800C0D8C	lui    v0, $800d
800C0D90	addiu  v0, v0, $9da4 (=-$625c)
800C0D94	sw     a0, $002c(v0)
800C0D98	sw     a1, $0030(v0)
800C0D9C	jr     ra 
800C0DA0	sw     zero, $0034(v0)


funcc0da4:	; 800C0DA4
800C0DA4	lui    v0, $800d
800C0DA8	jr     ra 
800C0DAC	sw     a0, $9db4(v0)


funcc0db0:	; 800C0DB0
800C0DB0	lui    v0, $800d
800C0DB4	lw     v0, $9db4(v0)
800C0DB8	nop
800C0DBC	lhu    a3, $0020(v0)
800C0DC0	lhu    v1, $0022(v0)
800C0DC4	addu   a3, a3, a0
800C0DC8	lhu    a0, $001c(v0)
800C0DCC	addu   v1, v1, a1
800C0DD0	sh     a3, $0020(v0)
800C0DD4	sh     v1, $0022(v0)
800C0DD8	sh     a3, $0024(v0)
800C0DDC	sh     v1, $0026(v0)
800C0DE0	addu   a0, a0, a2
800C0DE4	sh     a0, $001c(v0)
800C0DE8	sh     a0, $001e(v0)
800C0DEC	jr     ra 
800C0DF0	addiu  v0, zero, $0001


funcc0df4:	; 800C0DF4
800C0DF4	lui    t1, $800d
800C0DF8	lw     t2, $a068(t1)
800C0DFC	nop
800C0E00	andi   v0, t2, $0040
800C0E04	bne    v0, zero, Lc0e14 [$800c0e14]
800C0E08	addiu  t0, t1, $a068 (=-$5f98)
800C0E0C	jr     ra 
800C0E10	addu   v0, zero, zero


Lc0e14:	; 800C0E14
800C0E14	addiu  v0, zero, $0001
800C0E18	sh     v0, $0018(t0)
800C0E1C	addiu  v0, zero, $fff0 (=-$10)
800C0E20	sh     a0, $0014(t0)
800C0E24	and    a0, t2, v0
800C0E28	lw     v1, $0004(t0)
800C0E2C	addiu  v0, zero, $0008
800C0E30	sh     a1, $0016(t0)
800C0E34	sh     a2, $001a(t0)
800C0E38	sw     a0, $a068(t1)
800C0E3C	bne    a3, v0, Lc0e50 [$800c0e50]
800C0E40	sw     v1, $0010(t0)
800C0E44	or     v0, a0, v0
800C0E48	j      Lc0e54 [$800c0e54]
800C0E4C	sw     v0, $a068(t1)

Lc0e50:	; 800C0E50
800C0E50	sw     a0, $a068(t1)

Lc0e54:	; 800C0E54
800C0E54	lui    a0, $800d
800C0E58	lw     v1, $a068(a0)
800C0E5C	addiu  v0, zero, $0001
800C0E60	or     v1, v1, v0
800C0E64	jr     ra 
800C0E68	sw     v1, $a068(a0)


funcc0e6c:	; 800C0E6C
800C0E6C	lui    v0, $800d
800C0E70	addiu  v0, v0, $a068 (=-$5f98)
800C0E74	lhu    v1, $0004(v0)
800C0E78	nop
800C0E7C	sh     v1, $0000(a0)
800C0E80	lhu    v0, $0006(v0)
800C0E84	nop
800C0E88	sh     v0, $0000(a1)
800C0E8C	jr     ra 
800C0E90	addiu  v0, zero, $0001


funcc0e94:	; 800C0E94
800C0E94	addiu  sp, sp, $ffe8 (=-$18)
800C0E98	beq    a0, zero, Lc0ecc [$800c0ecc]
800C0E9C	sw     ra, $0010(sp)

Lc0ea0:	; 800C0EA0
800C0EA0	lui    v1, $800d
800C0EA4	lw     v0, $a068(v1)
800C0EA8	nop
800C0EAC	ori    v0, v0, $0040
800C0EB0	blez   a1, Lc0ee0 [$800c0ee0]
800C0EB4	sw     v0, $a068(v1)
800C0EB8	addu   a0, a1, zero
800C0EBC	jal    funcc0038 [$800c0038]
800C0EC0	addu   a1, a2, zero
800C0EC4	j      Lc0ee0 [$800c0ee0]

funcc0ec8:	; 800C0EC8
800C0EC8	nop

Lc0ecc:	; 800C0ECC
800C0ECC	lui    v0, $800d
800C0ED0	lw     v1, $a068(v0)
800C0ED4	addiu  a0, zero, $ffbf (=-$41)
800C0ED8	and    v1, v1, a0
800C0EDC	sw     v1, $a068(v0)

Lc0ee0:	; 800C0EE0
800C0EE0	lw     ra, $0010(sp)
800C0EE4	addiu  v0, zero, $0001
800C0EE8	jr     ra 
800C0EEC	addiu  sp, sp, $0018

800C0EF0	lui    v0, $800d
800C0EF4	lw     v0, $a068(v0)
800C0EF8	nop
800C0EFC	andi   v0, v0, $0040
800C0F00	jr     ra 
800C0F04	sltu   v0, zero, v0



////////////////////////////////
// funcc0f08
800C0F08-800C0FAC
////////////////////////////////



////////////////////////////////
// funcc0fb0
800C0FB0-800C0FF0
////////////////////////////////



800C0FF4	addiu  v0, zero, $ffff (=-$1)
800C0FF8	bne    a0, v0, Lc1010 [$800c1010]
800C0FFC	mult   a0, a0

Lc1000:	; 800C1000
800C1000	lui    v1, $800d
800C1004	addiu  v0, zero, $0e10
800C1008	j      Lc101c [$800c101c]
800C100C	sw     v0, $a0e0(v1)

Lc1010:	; 800C1010
800C1010	lui    v0, $800d
800C1014	mflo   a1
800C1018	sw     a1, $a0e0(v0)

Lc101c:	; 800C101C
800C101C	jr     ra 
800C1020	addiu  v0, zero, $0001


funcc1024:	; 800C1024
800C1024	lui    v0, $800d
800C1028	sh     a0, $a0de(v0)
800C102C	jr     ra 
800C1030	addiu  v0, zero, $0001

800C1034	lui    v0, $800d
800C1038	lw     v0, $a068(v0)
800C103C	nop
800C1040	andi   v0, v0, $0020
800C1044	jr     ra 
800C1048	sltu   v0, zero, v0


funcc104c:	; 800C104C
800C104C	lui    a2, $800d
800C1050	lw     v0, $a068(a2)
800C1054	nop
800C1058	andi   v0, v0, $0020
800C105C	bne    v0, zero, Lc106c [$800c106c]
800C1060	addiu  a1, a2, $a068 (=-$5f98)
800C1064	jr     ra 
800C1068	addu   v0, zero, zero


Lc106c:	; 800C106C
800C106C	lui    v0, $800d
800C1070	lw     v0, $9db4(v0)
800C1074	nop
800C1078	beq    v0, zero, Lc10f8 [$800c10f8]
800C107C	nop
800C1080	lw     v1, $0018(v0)
800C1084	lbu    a0, $0075(a1)
800C1088	addu   v1, v0, v1
800C108C	sll    v0, a0, $01
800C1090	addu   v0, v0, a0

Lc1094:	; 800C1094
800C1094	sll    v0, v0, $02
800C1098	addu   v0, v0, a0
800C109C	sll    v0, v0, $02
800C10A0	addu   v1, v1, v0
800C10A4	lhu    v0, $0028(v1)
800C10A8	nop
800C10AC	sh     v0, $0024(a1)
800C10B0	lhu    v0, $002a(v1)
800C10B4	nop

Lc10b8:	; 800C10B8
800C10B8	sh     v0, $0026(a1)
800C10BC	lhu    v0, $002c(v1)
800C10C0	nop
800C10C4	sh     v0, $0028(a1)
800C10C8	lhu    v0, $002e(v1)
800C10CC	addiu  a0, zero, $8000 (=-$8000)
800C10D0	sh     v0, $002a(a1)
800C10D4	addiu  v0, zero, $7fff
800C10D8	sh     a0, $0028(v1)
800C10DC	sh     v0, $002a(v1)
800C10E0	sh     a0, $002c(v1)
800C10E4	sh     v0, $002e(v1)
800C10E8	lw     v0, $a068(a2)
800C10EC	addiu  v1, zero, $ffdf (=-$21)
800C10F0	and    v0, v0, v1
800C10F4	sw     v0, $a068(a2)

Lc10f8:	; 800C10F8
800C10F8	jr     ra 
800C10FC	addiu  v0, zero, $0001


funcc1100:	; 800C1100
800C1100	lui    a2, $800d
800C1104	lw     v0, $a068(a2)
800C1108	nop
800C110C	andi   v0, v0, $0020
800C1110	beq    v0, zero, Lc1120 [$800c1120]
800C1114	addiu  a1, a2, $a068 (=-$5f98)
800C1118	jr     ra 
800C111C	addu   v0, zero, zero


Lc1120:	; 800C1120
800C1120	lui    v0, $800d
800C1124	lw     v0, $9db4(v0)
800C1128	nop
800C112C	beq    v0, zero, Lc1194 [$800c1194]
800C1130	nop
800C1134	lw     v1, $0018(v0)
800C1138	lbu    a0, $0075(a1)
800C113C	addu   v1, v0, v1
800C1140	sll    v0, a0, $01
800C1144	addu   v0, v0, a0
800C1148	sll    v0, v0, $02
800C114C	addu   v0, v0, a0

Lc1150:	; 800C1150
800C1150	sll    v0, v0, $02
800C1154	lhu    a0, $0024(a1)
800C1158	addu   v1, v1, v0
800C115C	sh     a0, $0028(v1)
800C1160	lhu    v0, $0026(a1)
800C1164	nop

Lc1168:	; 800C1168
800C1168	sh     v0, $002a(v1)
800C116C	lhu    v0, $0028(a1)
800C1170	nop
800C1174	sh     v0, $002c(v1)
800C1178	lhu    v0, $002a(a1)
800C117C	nop
800C1180	sh     v0, $002e(v1)

funcc1184:	; 800C1184
800C1184	lw     v0, $a068(a2)
800C1188	nop
800C118C	ori    v0, v0, $0020
800C1190	sw     v0, $a068(a2)

Lc1194:	; 800C1194
800C1194	jr     ra 
800C1198	addiu  v0, zero, $0001


funcc119c:	; 800C119C
800C119C	lui    v0, $800d

Lc11a0:	; 800C11A0
800C11A0	addiu  v0, v0, $a068 (=-$5f98)
800C11A4	sll    a0, a0, $02
800C11A8	addu   a0, a0, v0
800C11AC	lw     v1, $0010(sp)
800C11B0	addiu  v0, zero, $0001
800C11B4	sh     a1, $00a8(a0)
800C11B8	sh     a2, $00aa(a0)
800C11BC	sh     a3, $00b8(a0)
800C11C0	jr     ra 
800C11C4	sh     v1, $00ba(a0)


funcc11c8:	; 800C11C8
800C11C8	lui    v0, $800d
800C11CC	addiu  v0, v0, $a068 (=-$5f98)
800C11D0	sll    a0, a0, $01
800C11D4	addu   a0, a0, v0
800C11D8	addiu  v0, zero, $0001
800C11DC	sh     a1, $00c8(a0)
800C11E0	jr     ra 
800C11E4	sh     a2, $00d0(a0)


funcc11e8:	; 800C11E8
800C11E8	lui    v0, $800d
800C11EC	lw     v1, $9db4(v0)
800C11F0	nop
800C11F4	lw     v0, $0010(v1)
800C11F8	nop
800C11FC	addu   v1, v1, v0
800C1200	sll    v0, a0, $03
800C1204	subu   v0, v0, a0

Lc1208:	; 800C1208
800C1208	sll    v0, v0, $03
800C120C	addu   t0, v1, v0
800C1210	lhu    v1, $0008(t0)
800C1214	lhu    a0, $000a(t0)
800C1218	lw     v0, $0000(t0)
800C121C	addu   v1, v1, a1
800C1220	addu   t1, v1, zero
800C1224	addu   a2, a0, a2
800C1228	srl    v0, v0, $14
800C122C	addu   a3, a3, v0
800C1230	sll    v1, v1, $10
800C1234	sra    v1, v1, $10
800C1238	lh     v0, $0010(t0)
800C123C	lhu    a0, $0010(t0)
800C1240	slt    v0, v1, v0
800C1244	beq    v0, zero, Lc1254 [$800c1254]
800C1248	nop
800C124C	j      Lc1270 [$800c1270]
800C1250	addu   t1, a0, zero

Lc1254:	; 800C1254
800C1254	lh     v0, $0012(t0)
800C1258	nop
800C125C	slt    v0, v0, v1
800C1260	lhu    v1, $0012(t0)
800C1264	beq    v0, zero, Lc1270 [$800c1270]

Lc1268:	; 800C1268
800C1268	nop
800C126C	addu   t1, v1, zero

Lc1270:	; 800C1270
800C1270	sll    v1, a2, $10
800C1274	sra    v1, v1, $10
800C1278	lh     v0, $0014(t0)
800C127C	lhu    a0, $0014(t0)
800C1280	slt    v0, v1, v0
800C1284	beq    v0, zero, Lc1294 [$800c1294]
800C1288	nop
800C128C	j      Lc12b0 [$800c12b0]
800C1290	addu   a2, a0, zero

Lc1294:	; 800C1294
800C1294	lh     v0, $0016(t0)
800C1298	nop
800C129C	slt    v0, v0, v1
800C12A0	lhu    v1, $0016(t0)
800C12A4	beq    v0, zero, Lc12b0 [$800c12b0]
800C12A8	nop

Lc12ac:	; 800C12AC
800C12AC	addu   a2, v1, zero

Lc12b0:	; 800C12B0
800C12B0	lui    v0, $000f
800C12B4	ori    v0, v0, $ffff
800C12B8	lui    a1, $fff0
800C12BC	sll    v1, a3, $10
800C12C0	sra    v1, v1, $10
800C12C4	lw     a0, $0000(t0)
800C12C8	ori    a1, a1, $00ff

funcc12cc:	; 800C12CC
800C12CC	sh     t1, $0008(t0)
800C12D0	sh     a2, $000a(t0)
800C12D4	sh     t1, $000c(t0)
800C12D8	sh     a2, $000e(t0)
800C12DC	and    a0, a0, v0
800C12E0	sll    v0, v1, $14
800C12E4	or     a0, a0, v0
800C12E8	sw     a0, $0000(t0)
800C12EC	addu   v0, a0, zero
800C12F0	and    v0, v0, a1
800C12F4	andi   v1, v1, $0fff
800C12F8	sll    v1, v1, $08
800C12FC	or     v0, v0, v1
800C1300	sw     v0, $0000(t0)
800C1304	jr     ra 
800C1308	addiu  v0, zero, $0001

800C130C	lui    t0, $800d
800C1310	addiu  t0, t0, $9da4 (=-$625c)
800C1314	sll    v1, a0, $01
800C1318	lw     v0, $001c(t0)
800C131C	addu   v1, v1, a0
800C1320	addu   v0, v1, v0
800C1324	lbu    v0, $0000(v0)
800C1328	nop
800C132C	sb     v0, $0000(a1)
800C1330	lw     v0, $001c(t0)
800C1334	nop
800C1338	addu   v0, v1, v0
800C133C	lbu    v0, $0001(v0)
800C1340	nop
800C1344	sb     v0, $0000(a2)
800C1348	lw     v0, $001c(t0)
800C134C	nop
800C1350	addu   v1, v1, v0
800C1354	lbu    v0, $0002(v1)
800C1358	nop
800C135C	sb     v0, $0000(a3)
800C1360	jr     ra 
800C1364	addiu  v0, zero, $0001


funcc1368:	; 800C1368
800C1368	lui    t2, $800d
800C136C	addiu  t1, t2, $9da4 (=-$625c)
800C1370	sll    v1, a0, $01
800C1374	addu   v1, v1, a0
800C1378	lw     v0, $001c(t1)
800C137C	lw     t0, $0010(t1)
800C1380	addu   v0, v1, v0
800C1384	sb     a1, $0000(v0)
800C1388	lw     v0, $001c(t1)
800C138C	nop
800C1390	addu   v0, v1, v0
800C1394	sb     a2, $0001(v0)
800C1398	lw     v0, $001c(t1)
800C139C	nop
800C13A0	addu   v1, v1, v0
800C13A4	sb     a3, $0002(v1)
800C13A8	lw     v0, $0010(t0)
800C13AC	nop
800C13B0	addu   t0, t0, v0
800C13B4	sll    v0, a0, $03
800C13B8	subu   v0, v0, a0
800C13BC	sll    v0, v0, $03
800C13C0	addu   t0, t0, v0
800C13C4	lw     v0, $9da4(t2)
800C13C8	lhu    v1, $0026(t0)
800C13CC	lbu    v0, $0000(v0)
800C13D0	lw     t2, $0030(t0)
800C13D4	beq    v0, zero, Lc13e0 [$800c13e0]
800C13D8	addu   t1, zero, zero
800C13DC	andi   t1, v1, $ffff

Lc13e0:	; 800C13E0
800C13E0	andi   t0, v1, $ffff
800C13E4	beq    t0, zero, Lc1424 [$800c1424]
800C13E8	addu   a0, zero, zero

loopc13ec:	; 800C13EC
800C13EC	andi   v0, a0, $ffff
800C13F0	addiu  a0, a0, $0001
800C13F4	addu   v0, v0, t1
800C13F8	sll    v1, v0, $01
800C13FC	addu   v1, v1, v0
800C1400	sll    v1, v1, $03
800C1404	addu   v1, v1, t2
800C1408	addiu  v1, v1, $0008
800C140C	andi   v0, a0, $ffff
800C1410	sltu   v0, v0, t0
800C1414	sb     a1, $0004(v1)
800C1418	sb     a2, $0005(v1)
800C141C	bne    v0, zero, loopc13ec [$800c13ec]
800C1420	sb     a3, $0006(v1)

Lc1424:	; 800C1424
800C1424	jr     ra 
800C1428	addiu  v0, zero, $0001



////////////////////////////////
// funcc142c
800C142C-800C1478
////////////////////////////////



funcc147c:	; 800C147C
800C147C	lui    v0, $800d

Lc1480:	; 800C1480
800C1480	lw     v1, $9db4(v0)
800C1484	nop
800C1488	lw     v0, $0010(v1)
800C148C	nop
800C1490	addu   v1, v1, v0
800C1494	sll    v0, a0, $03
800C1498	subu   v0, v0, a0
800C149C	sll    v0, v0, $03
800C14A0	beq    a1, zero, Lc14b4 [$800c14b4]
800C14A4	addu   v1, v1, v0

Lc14a8:	; 800C14A8
800C14A8	lbu    v0, $0000(v1)
800C14AC	j      Lc14c0 [$800c14c0]
800C14B0	ori    v0, v0, $0004

Lc14b4:	; 800C14B4
800C14B4	lbu    v0, $0000(v1)
800C14B8	nop
800C14BC	andi   v0, v0, $00fb

Lc14c0:	; 800C14C0
800C14C0	sb     v0, $0000(v1)
800C14C4	addiu  v0, zero, $0001
800C14C8	sh     a2, $001c(v1)
800C14CC	sh     zero, $0020(v1)
800C14D0	sh     a3, $001e(v1)
800C14D4	jr     ra 
800C14D8	sh     zero, $0022(v1)


funcc14dc:	; 800C14DC
800C14DC	lui    v0, $800d
800C14E0	lw     v1, $9db4(v0)
800C14E4	nop
800C14E8	lw     v0, $0010(v1)
800C14EC	nop
800C14F0	addu   v1, v1, v0
800C14F4	sll    v0, a0, $03
800C14F8	subu   v0, v0, a0
800C14FC	sll    v0, v0, $03
800C1500	beq    a1, zero, Lc1514 [$800c1514]
800C1504	addu   v1, v1, v0
800C1508	lbu    v0, $0000(v1)
800C150C	j      Lc1520 [$800c1520]
800C1510	ori    v0, v0, $0001

Lc1514:	; 800C1514
800C1514	lbu    v0, $0000(v1)
800C1518	nop
800C151C	andi   v0, v0, $00fe

Lc1520:	; 800C1520
800C1520	sb     v0, $0000(v1)

funcc1524:	; 800C1524
800C1524	jr     ra 
800C1528	addiu  v0, zero, $0001


funcc152c:	; 800C152C
800C152C	lui    v0, $800d
800C1530	lw     v1, $9db4(v0)
800C1534	nop
800C1538	lw     v0, $0010(v1)
800C153C	nop
800C1540	addu   v1, v1, v0
800C1544	sll    v0, a0, $03
800C1548	subu   v0, v0, a0
800C154C	sll    v0, v0, $03
800C1550	addu   a0, v1, v0
800C1554	lw     v1, $0010(sp)
800C1558	beq    a1, zero, Lc156c [$800c156c]
800C155C	nop
800C1560	lbu    v0, $0000(a0)
800C1564	j      Lc1578 [$800c1578]
800C1568	ori    v0, v0, $0080

Lc156c:	; 800C156C
800C156C	lbu    v0, $0000(a0)
800C1570	nop
800C1574	andi   v0, v0, $007f

Lc1578:	; 800C1578
800C1578	beq    v1, zero, Lc1594 [$800c1594]
800C157C	sb     v0, $0000(a0)
800C1580	lw     v0, $0024(a0)
800C1584	sh     a3, $001c(a0)
800C1588	sh     a2, $001e(a0)
800C158C	j      Lc15a8 [$800c15a8]
800C1590	ori    v0, v0, $0100

Lc1594:	; 800C1594
800C1594	lw     v0, $0024(a0)
800C1598	addiu  v1, zero, $feff (=-$101)
800C159C	sh     a2, $001c(a0)
800C15A0	sh     a3, $001e(a0)
800C15A4	and    v0, v0, v1

Lc15a8:	; 800C15A8
800C15A8	sw     v0, $0024(a0)
800C15AC	addiu  v0, zero, $0001
800C15B0	sh     zero, $0020(a0)
800C15B4	jr     ra 
800C15B8	sh     zero, $0022(a0)


funcc15bc:	; 800C15BC
800C15BC	lui    v0, $800d
800C15C0	lw     v1, $9db4(v0)
800C15C4	nop
800C15C8	lw     v0, $0010(v1)
800C15CC	nop
800C15D0	addu   v1, v1, v0
800C15D4	sll    v0, a0, $03
800C15D8	subu   v0, v0, a0

funcc15dc:	; 800C15DC
800C15DC	sll    v0, v0, $03
800C15E0	beq    a1, zero, Lc15f4 [$800c15f4]
800C15E4	addu   v1, v1, v0
800C15E8	lbu    v0, $0000(v1)
800C15EC	j      Lc1600 [$800c1600]
800C15F0	ori    v0, v0, $0008

Lc15f4:	; 800C15F4
800C15F4	lbu    v0, $0000(v1)
800C15F8	nop
800C15FC	andi   v0, v0, $00f7

Lc1600:	; 800C1600
800C1600	sb     v0, $0000(v1)
800C1604	addiu  v0, zero, $0001
800C1608	sh     a2, $001c(v1)
800C160C	jr     ra 
800C1610	sh     a3, $001e(v1)


funcc1614:	; 800C1614
800C1614	lui    v0, $800d
800C1618	lw     v1, $9db4(v0)
800C161C	nop
800C1620	lw     v0, $0010(v1)
800C1624	nop
800C1628	addu   v1, v1, v0
800C162C	sll    v0, a0, $03
800C1630	subu   v0, v0, a0
800C1634	sll    v0, v0, $03
800C1638	addu   v1, v1, v0
800C163C	sh     a1, $000c(v1)
800C1640	sh     a1, $0008(v1)
800C1644	sh     a2, $000e(v1)
800C1648	sh     a2, $000a(v1)
800C164C	lui    v1, $800d
800C1650	lw     v0, $a068(v1)
800C1654	nop
800C1658	ori    v0, v0, $0080
800C165C	sw     v0, $a068(v1)
800C1660	jr     ra 
800C1664	addiu  v0, zero, $0001


funcc1668:	; 800C1668
800C1668	lui    v0, $800d
800C166C	lui    a2, $ffff
800C1670	lw     v1, $9db4(v0)
800C1674	ori    a2, a2, $01ff
800C1678	lw     v0, $0010(v1)
800C167C	andi   a1, a1, $007f
800C1680	addu   v1, v1, v0
800C1684	sll    v0, a0, $03
800C1688	subu   v0, v0, a0
800C168C	sll    v0, v0, $03
800C1690	addu   v1, v1, v0
800C1694	lw     v0, $0024(v1)
800C1698	sll    a1, a1, $09
800C169C	and    v0, v0, a2
800C16A0	or     v0, v0, a1
800C16A4	sw     v0, $0024(v1)
800C16A8	jr     ra 
800C16AC	addiu  v0, zero, $0001


funcc16b0:	; 800C16B0
800C16B0	lui    v0, $800d
800C16B4	lw     v0, $9db4(v0)
800C16B8	nop
800C16BC	lw     v1, $000c(v0)
800C16C0	sll    a0, a0, $04
800C16C4	addu   v0, v0, v1

Lc16c8:	; 800C16C8
800C16C8	addu   v0, v0, a0
800C16CC	lbu    a0, $0004(v0)
800C16D0	lbu    v1, $0000(v0)
800C16D4	sll    a1, a1, $10
800C16D8	sh     zero, $000a(v0)

Lc16dc:	; 800C16DC
800C16DC	or     a0, a0, a1
800C16E0	ori    v1, v1, $0002
800C16E4	sb     v1, $0000(v0)
800C16E8	sw     a0, $0004(v0)
800C16EC	jr     ra 
800C16F0	addiu  v0, zero, $0001


funcc16f4:	; 800C16F4
800C16F4	lui    v0, $800d
800C16F8	lw     v1, $9db4(v0)
800C16FC	sll    a0, a0, $04
800C1700	lw     v0, $000c(v1)

funcc1704:	; 800C1704
800C1704	addu   a2, zero, zero
800C1708	addu   v0, v1, v0
800C170C	addu   t0, v0, a0
800C1710	lw     v0, $000c(t0)
800C1714	lw     a0, $0010(v1)
800C1718	addu   a3, v1, v0
800C171C	lw     v0, $0000(t0)
800C1720	nop
800C1724	srl    v0, v0, $08
800C1728	beq    v0, zero, Lc179c [$800c179c]
800C172C	addu   a0, v1, a0

loopc1730:	; 800C1730
800C1730	bne    a2, a1, Lc175c [$800c175c]
800C1734	nop
800C1738	lbu    v0, $0000(a3)
800C173C	nop

Lc1740:	; 800C1740
800C1740	sll    v1, v0, $03
800C1744	subu   v1, v1, v0
800C1748	sll    v1, v1, $03
800C174C	addu   v1, v1, a0
800C1750	lbu    v0, $0000(v1)
800C1754	j      Lc1780 [$800c1780]
800C1758	ori    v0, v0, $0002

Lc175c:	; 800C175C
800C175C	lbu    v0, $0000(a3)
800C1760	nop
800C1764	sll    v1, v0, $03
800C1768	subu   v1, v1, v0
800C176C	sll    v1, v1, $03
800C1770	addu   v1, v1, a0
800C1774	lbu    v0, $0000(v1)
800C1778	nop
800C177C	andi   v0, v0, $00fd

Lc1780:	; 800C1780
800C1780	sb     v0, $0000(v1)
800C1784	lw     v0, $0000(t0)
800C1788	addiu  a2, a2, $0001
800C178C	srl    v0, v0, $08
800C1790	slt    v0, a2, v0

funcc1794:	; 800C1794
800C1794	bne    v0, zero, loopc1730 [$800c1730]
800C1798	addiu  a3, a3, $0002

Lc179c:	; 800C179C
800C179C	addiu  v0, zero, $0001
800C17A0	sb     v0, $0000(t0)
800C17A4	jr     ra 
800C17A8	addiu  v0, zero, $0001


funcc17ac:	; 800C17AC
800C17AC	lui    v0, $800d
800C17B0	lw     v0, $9db4(v0)
800C17B4	nop
800C17B8	lw     v1, $000c(v0)
800C17BC	sll    a0, a0, $04
800C17C0	addu   v0, v0, v1
800C17C4	beq    a1, zero, Lc17d8 [$800c17d8]
800C17C8	addu   v1, v0, a0
800C17CC	lbu    v0, $0000(v1)
800C17D0	j      Lc17e4 [$800c17e4]
800C17D4	ori    v0, v0, $0006

Lc17d8:	; 800C17D8
800C17D8	lbu    v0, $0000(v1)
800C17DC	nop
800C17E0	andi   v0, v0, $00f9

Lc17e4:	; 800C17E4
800C17E4	sb     v0, $0000(v1)
800C17E8	jr     ra 
800C17EC	addiu  v0, zero, $0001


funcc17f0:	; 800C17F0
800C17F0	lui    v0, $800d
800C17F4	lw     v0, $9db4(v0)
800C17F8	nop
800C17FC	lw     v1, $000c(v0)
800C1800	sll    a0, a0, $04
800C1804	addu   v0, v0, v1
800C1808	addu   v0, v0, a0
800C180C	sh     a1, $0008(v0)

Lc1810:	; 800C1810
800C1810	jr     ra 
800C1814	addiu  v0, zero, $0001

800C1818	lui    v0, $800d
800C181C	lw     v1, $9db4(v0)
800C1820	nop
800C1824	lw     v0, $000c(v1)
800C1828	sll    a0, a0, $04
800C182C	addu   v0, v1, v0
800C1830	addu   v0, v0, a0
800C1834	lw     a0, $000c(v0)
800C1838	lw     v0, $0000(v0)
800C183C	addu   v1, v1, a0

Lc1840:	; 800C1840
800C1840	srl    a0, v0, $08
800C1844	beq    a0, zero, Lc1860 [$800c1860]
800C1848	addu   a2, zero, zero

loopc184c:	; 800C184C
800C184C	sb     a1, $0001(v1)
800C1850	addiu  a2, a2, $0001

funcc1854:	; 800C1854
800C1854	slt    v0, a2, a0
800C1858	bne    v0, zero, loopc184c [$800c184c]
800C185C	addiu  v1, v1, $0002

Lc1860:	; 800C1860
800C1860	jr     ra 
800C1864	addiu  v0, zero, $0001


funcc1868:	; 800C1868
800C1868	lui    v0, $800d
800C186C	lw     v1, $9db4(v0)
800C1870	nop
800C1874	lw     v0, $000c(v1)
800C1878	sll    a0, a0, $04

Lc187c:	; 800C187C
800C187C	addu   v0, v1, v0
800C1880	addu   v0, v0, a0
800C1884	lw     v0, $000c(v0)
800C1888	sll    a1, a1, $01
800C188C	addu   v1, v1, v0
800C1890	addu   a1, a1, v1
800C1894	addiu  v0, zero, $0001
800C1898	jr     ra 
800C189C	sb     a2, $0001(a1)


funcc18a0:	; 800C18A0
800C18A0	lui    v0, $800d
800C18A4	lw     v0, $9db4(v0)
800C18A8	nop
800C18AC	lw     v1, $000c(v0)
800C18B0	sll    a0, a0, $04
800C18B4	addu   v0, v0, v1
800C18B8	addu   v0, v0, a0
800C18BC	lbu    v1, $0000(v0)

Lc18c0:	; 800C18C0
800C18C0	andi   a1, a1, $0030
800C18C4	or     v1, v1, a1
800C18C8	sb     v1, $0000(v0)
800C18CC	jr     ra 
800C18D0	addiu  v0, zero, $0001


funcc18d4:	; 800C18D4
800C18D4	addu   t0, a1, zero
800C18D8	lui    v0, $800d
800C18DC	lw     a1, $9db4(v0)
800C18E0	nop
800C18E4	lw     v0, $000c(a1)
800C18E8	sll    a0, a0, $04
800C18EC	addu   v0, a1, v0
800C18F0	addu   a3, v0, a0
800C18F4	lbu    v1, $0004(a3)
800C18F8	lw     a0, $000c(a3)
800C18FC	sll    v0, t0, $10
800C1900	sh     zero, $000a(a3)
800C1904	or     v1, v1, v0
800C1908	lbu    v0, $0000(a3)

Lc190c:	; 800C190C
800C190C	addu   a1, a1, a0
800C1910	sw     v1, $0004(a3)
800C1914	addiu  v1, zero, $ffff (=-$1)
800C1918	ori    v0, v0, $0006
800C191C	sb     v0, $0000(a3)

Lc1920:	; 800C1920
800C1920	sll    v0, a2, $01
800C1924	addu   v0, v0, a1
800C1928	sb     v1, $0001(v0)
800C192C	lh     v1, $0008(a3)
800C1930	nop

Lc1934:	; 800C1934
800C1934	blez   v1, Lc1944 [$800c1944]

funcc1938:	; 800C1938
800C1938	sltu   v0, a2, t0
800C193C	bne    v0, zero, Lc1954 [$800c1954]
800C1940	nop

Lc1944:	; 800C1944
800C1944	bgez   v1, Lc1964 [$800c1964]
800C1948	sltu   v0, t0, a2
800C194C	beq    v0, zero, Lc1964 [$800c1964]
800C1950	nop

Lc1954:	; 800C1954
800C1954	lhu    v0, $0008(a3)
800C1958	nop

Lc195c:	; 800C195C
800C195C	subu   v0, zero, v0
800C1960	sh     v0, $0008(a3)

Lc1964:	; 800C1964
800C1964	jr     ra 
800C1968	addiu  v0, zero, $0001


funcc196c:	; 800C196C
800C196C	addu   t1, a1, zero
800C1970	lui    v0, $800d
800C1974	lw     a1, $9db4(v0)
800C1978	nop
800C197C	lw     v0, $000c(a1)
800C1980	sll    a0, a0, $04
800C1984	addu   v0, a1, v0
800C1988	addu   a2, v0, a0
800C198C	addiu  v0, zero, $0100

funcc1990:	; 800C1990
800C1990	sh     v0, $0008(a2)
800C1994	addiu  v0, zero, $0001
800C1998	lbu    v1, $0004(a2)
800C199C	addu   a0, zero, zero
800C19A0	sh     zero, $000a(a2)
800C19A4	sb     v0, $0000(a2)
800C19A8	sw     v1, $0004(a2)

Lc19ac:	; 800C19AC
800C19AC	lw     v0, $0010(a1)
800C19B0	lw     v1, $000c(a2)
800C19B4	addu   t0, a1, v0
800C19B8	lw     v0, $0000(a2)
800C19BC	nop

Lc19c0:	; 800C19C0
800C19C0	srl    v0, v0, $08
800C19C4	beq    v0, zero, Lc1a44 [$800c1a44]
800C19C8	addu   a1, a1, v1
800C19CC	addu   a3, a1, zero

loopc19d0:	; 800C19D0
800C19D0	beq    t1, zero, Lc1a04 [$800c1a04]

Lc19d4:	; 800C19D4
800C19D4	nop
800C19D8	bne    a0, zero, Lc1a04 [$800c1a04]
800C19DC	nop
800C19E0	lbu    v0, $0000(a1)
800C19E4	nop
800C19E8	sll    v1, v0, $03
800C19EC	subu   v1, v1, v0
800C19F0	sll    v1, v1, $03
800C19F4	addu   v1, v1, t0

funcc19f8:	; 800C19F8
800C19F8	lbu    v0, $0000(v1)

Lc19fc:	; 800C19FC
800C19FC	j      Lc1a28 [$800c1a28]
800C1A00	ori    v0, v0, $0002

Lc1a04:	; 800C1A04
800C1A04	lbu    v0, $0000(a3)
800C1A08	nop
800C1A0C	sll    v1, v0, $03
800C1A10	subu   v1, v1, v0
800C1A14	sll    v1, v1, $03
800C1A18	addu   v1, v1, t0
800C1A1C	lbu    v0, $0000(v1)
800C1A20	nop
800C1A24	andi   v0, v0, $00fd

Lc1a28:	; 800C1A28
800C1A28	sb     v0, $0000(v1)
800C1A2C	lw     v0, $0000(a2)
800C1A30	addiu  a0, a0, $0001
800C1A34	srl    v0, v0, $08
800C1A38	slt    v0, a0, v0
800C1A3C	bne    v0, zero, loopc19d0 [$800c19d0]
800C1A40	addiu  a3, a3, $0002

Lc1a44:	; 800C1A44
800C1A44	jr     ra 
800C1A48	addiu  v0, zero, $0001

800C1A4C	lui    v1, $800d
800C1A50	sll    v0, a0, $01
800C1A54	addu   v0, v0, a0
800C1A58	lw     v1, $9dcc(v1)
800C1A5C	sll    v0, v0, $02

Lc1a60:	; 800C1A60
800C1A60	addu   v0, v0, v1
800C1A64	lbu    v0, $0000(v0)
800C1A68	nop
800C1A6C	sb     v0, $0000(a1)
800C1A70	jr     ra 
800C1A74	addiu  v0, zero, $0001

800C1A78	lui    v0, $800d

Lc1a7c:	; 800C1A7C
800C1A7C	lw     v0, $9dd0(v0)
800C1A80	sll    a0, a0, $09
800C1A84	jr     ra 
800C1A88	addu   v0, v0, a0


funcc1a8c:	; 800C1A8C
800C1A8C	lui    v0, $800d
800C1A90	lw     v1, $9db4(v0)
800C1A94	nop
800C1A98	lw     v0, $0018(v1)
800C1A9C	addiu  a1, a1, $00a0
800C1AA0	addu   v1, v1, v0
800C1AA4	sll    v0, a0, $01
800C1AA8	addu   v0, v0, a0
800C1AAC	sll    v0, v0, $02
800C1AB0	addu   v0, v0, a0
800C1AB4	sll    v0, v0, $02
800C1AB8	addu   t0, v1, v0
800C1ABC	sh     a1, $0028(t0)
800C1AC0	sll    a1, a1, $10
800C1AC4	sra    a1, a1, $10
800C1AC8	lh     v0, $0024(t0)
800C1ACC	lhu    a0, $0024(t0)
800C1AD0	addiu  v0, v0, $ff60 (=-$a0)
800C1AD4	slt    v0, v0, a1
800C1AD8	lw     a1, $0010(sp)
800C1ADC	beq    v0, zero, Lc1ae8 [$800c1ae8]
800C1AE0	addiu  v0, a0, $ff60 (=-$a0)
800C1AE4	sh     v0, $0028(t0)

Lc1ae8:	; 800C1AE8
800C1AE8	addiu  v0, a2, $ff60 (=-$a0)
800C1AEC	sh     v0, $002a(t0)
800C1AF0	sll    v0, v0, $10
800C1AF4	sra    v0, v0, $10
800C1AF8	slti   v0, v0, $00a0
800C1AFC	beq    v0, zero, Lc1b08 [$800c1b08]
800C1B00	addiu  v0, zero, $00a0
800C1B04	sh     v0, $002a(t0)

Lc1b08:	; 800C1B08
800C1B08	addiu  v1, a3, $0070
800C1B0C	sh     v1, $002c(t0)
800C1B10	sll    v1, v1, $10
800C1B14	lh     v0, $0026(t0)
800C1B18	sra    v1, v1, $10
800C1B1C	addiu  v0, v0, $ff90 (=-$70)
800C1B20	slt    v0, v0, v1
800C1B24	lhu    v1, $0026(t0)
800C1B28	beq    v0, zero, Lc1b34 [$800c1b34]
800C1B2C	addiu  v0, v1, $ff90 (=-$70)
800C1B30	sh     v0, $002c(t0)

Lc1b34:	; 800C1B34
800C1B34	addiu  v0, a1, $ff90 (=-$70)
800C1B38	sh     v0, $002e(t0)
800C1B3C	sll    v0, v0, $10
800C1B40	sra    v0, v0, $10
800C1B44	slti   v0, v0, $0070
800C1B48	beq    v0, zero, Lc1b54 [$800c1b54]
800C1B4C	addiu  v0, zero, $0070

Lc1b50:	; 800C1B50
800C1B50	sh     v0, $002e(t0)

Lc1b54:	; 800C1B54
800C1B54	jr     ra 
800C1B58	addiu  v0, zero, $0001


funcc1b5c:	; 800C1B5C
800C1B5C	lui    v0, $800d
800C1B60	lbu    v0, $a0dd(v0)
800C1B64	nop
800C1B68	sb     v0, $0000(a0)
800C1B6C	jr     ra 
800C1B70	addiu  v0, zero, $0001

800C1B74	lui    v0, $800d
800C1B78	lw     v1, $9db4(v0)
800C1B7C	nop
800C1B80	lw     v0, $0018(v1)
800C1B84	nop
800C1B88	addu   v1, v1, v0
800C1B8C	sll    v0, a0, $01
800C1B90	addu   v0, v0, a0
800C1B94	sll    v0, v0, $02
800C1B98	addu   v0, v0, a0
800C1B9C	sll    v0, v0, $02
800C1BA0	addu   v1, v1, v0
800C1BA4	addiu  v0, zero, $0001
800C1BA8	sh     a1, $0020(v1)
800C1BAC	jr     ra 
800C1BB0	sh     a2, $0022(v1)

800C1BB4	lui    v0, $800d
800C1BB8	lw     v1, $9db4(v0)
800C1BBC	nop
800C1BC0	lw     v0, $0018(v1)
800C1BC4	nop
800C1BC8	addu   v1, v1, v0
800C1BCC	sll    v0, a0, $01
800C1BD0	addu   v0, v0, a0
800C1BD4	sll    v0, v0, $02
800C1BD8	addu   v0, v0, a0
800C1BDC	sll    v0, v0, $02
800C1BE0	addu   v1, v1, v0
800C1BE4	lhu    v0, $0020(v1)
800C1BE8	nop
800C1BEC	sh     v0, $0000(a1)
800C1BF0	lhu    v0, $0022(v1)
800C1BF4	nop
800C1BF8	sh     v0, $0000(a2)
800C1BFC	jr     ra 
800C1C00	addiu  v0, zero, $0001

800C1C04	sll    v0, a0, $02
800C1C08	jr     ra 
800C1C0C	addiu  v0, v0, $002c

800C1C10	lui    v1, $800d
800C1C14	addiu  v1, v1, $9da4 (=-$625c)
800C1C18	lw     v0, $0034(v1)
800C1C1C	lw     a1, $002c(v1)
800C1C20	addu   a0, v0, a0
800C1C24	addu   v0, a1, v0
800C1C28	jr     ra 
800C1C2C	sw     a0, $0034(v1)

800C1C30	lui    v0, $800d
800C1C34	lw     a2, $9db4(v0)
800C1C38	nop
800C1C3C	lw     v0, $000c(a2)

Lc1c40:	; 800C1C40
800C1C40	addu   a1, zero, zero
800C1C44	addu   v1, a2, v0
800C1C48	lw     v0, $0010(a2)
800C1C4C	lhu    a3, $0004(a2)
800C1C50	nop
800C1C54	beq    a3, zero, Lc1cb8 [$800c1cb8]
800C1C58	addu   t0, a2, v0
800C1C5C	addiu  t2, zero, $0100
800C1C60	addiu  t1, zero, $0001
800C1C64	addu   a0, v1, zero

loopc1c68:	; 800C1C68
800C1C68	lbu    v1, $0004(a0)
800C1C6C	lw     v0, $000c(a0)
800C1C70	sh     t2, $0008(a0)
800C1C74	sh     zero, $000a(a0)
800C1C78	sb     t1, $0000(a0)
800C1C7C	addu   v0, a2, v0
800C1C80	sw     v1, $0004(a0)
800C1C84	lbu    v1, $0000(v0)
800C1C88	addiu  a1, a1, $0001
800C1C8C	sll    v0, v1, $03

Lc1c90:	; 800C1C90
800C1C90	subu   v0, v0, v1
800C1C94	sll    v0, v0, $03

Lc1c98:	; 800C1C98
800C1C98	addu   v0, v0, t0
800C1C9C	lbu    v1, $0000(v0)

funcc1ca0:	; 800C1CA0
800C1CA0	nop

Lc1ca4:	; 800C1CA4
800C1CA4	ori    v1, v1, $0002
800C1CA8	sb     v1, $0000(v0)
800C1CAC	sltu   v0, a1, a3
800C1CB0	bne    v0, zero, loopc1c68 [$800c1c68]
800C1CB4	addiu  a0, a0, $0010

Lc1cb8:	; 800C1CB8
800C1CB8	jr     ra 
800C1CBC	addiu  v0, zero, $0001

800C1CC0	lui    v0, $800d
800C1CC4	addiu  v0, v0, $9da4 (=-$625c)
800C1CC8	lbu    v1, $0024(v0)
800C1CCC	nop
800C1CD0	beq    v1, zero, Lc1d00 [$800c1d00]
800C1CD4	addu   a0, zero, zero
800C1CD8	addiu  a3, zero, $0010
800C1CDC	addiu  a2, zero, $0040
800C1CE0	addu   a1, v1, zero
800C1CE4	lw     v1, $0028(v0)

loopc1ce8:	; 800C1CE8
800C1CE8	nop
800C1CEC	lbu    v0, $0000(v1)
800C1CF0	addiu  a0, a0, $0001
800C1CF4	sltu   v0, a0, a1
800C1CF8	bne    v0, zero, loopc1ce8 [$800c1ce8]
800C1CFC	addiu  v1, v1, $000c

Lc1d00:	; 800C1D00
800C1D00	jr     ra 
800C1D04	addiu  v0, zero, $0001

800C1D08	jr     ra 
800C1D0C	addiu  v0, zero, $0001

800C1D10	lui    v0, $800d
800C1D14	lw     v1, $9db4(v0)
800C1D18	nop
800C1D1C	lw     v0, $0010(v1)
800C1D20	nop
800C1D24	addu   v1, v1, v0
800C1D28	sll    v0, a0, $03
800C1D2C	subu   v0, v0, a0
800C1D30	sll    v0, v0, $03
800C1D34	addu   v1, v1, v0
800C1D38	lhu    a0, $0026(v1)
800C1D3C	lw     t1, $0030(v1)
800C1D40	beq    a0, zero, Lc1da4 [$800c1da4]
800C1D44	addu   t0, zero, zero
800C1D48	andi   v1, t0, $ffff

loopc1d4c:	; 800C1D4C
800C1D4C	addiu  t0, t0, $0001

Lc1d50:	; 800C1D50
800C1D50	sll    v0, v1, $01
800C1D54	addu   v0, v0, v1
800C1D58	sll    v0, v0, $03

Lc1d5c:	; 800C1D5C
800C1D5C	addu   v0, v0, t1
800C1D60	addiu  v0, v0, $0008
800C1D64	addu   v1, v1, a0
800C1D68	sb     a1, $0004(v0)
800C1D6C	sb     a2, $0005(v0)
800C1D70	sb     a3, $0006(v0)
800C1D74	sll    v0, v1, $01
800C1D78	addu   v0, v0, v1
800C1D7C	sll    v0, v0, $03
800C1D80	addu   v0, v0, t1
800C1D84	addiu  v0, v0, $0008
800C1D88	sb     a1, $0004(v0)

funcc1d8c:	; 800C1D8C
800C1D8C	sb     a2, $0005(v0)
800C1D90	sb     a3, $0006(v0)
800C1D94	andi   v0, t0, $ffff
800C1D98	sltu   v0, v0, a0
800C1D9C	bne    v0, zero, loopc1d4c [$800c1d4c]
800C1DA0	andi   v1, t0, $ffff

Lc1da4:	; 800C1DA4
800C1DA4	jr     ra 
800C1DA8	addiu  v0, zero, $0001

800C1DAC	jr     ra 
800C1DB0	addiu  v0, zero, $0001

800C1DB4	jr     ra 
800C1DB8	addiu  v0, zero, $0001

800C1DBC	jr     ra 
800C1DC0	addiu  v0, zero, $0001




////////////////////////////////
// funcc1dc4
800C1DC4-800C1DDC
////////////////////////////////



800C1DE0	sra    a1, a1, $08
800C1DE4	div    a0, a1
800C1DE8	mflo   v0
800C1DEC	jr     ra 
800C1DF0	sll    v0, v0, $08

800C1DF4	ori    at, zero, $8000
800C1DF8	addu   v0, a0, at
800C1DFC	jr     ra 
800C1E00	sra    v0, v0, $10

800C1E04	ori    at, zero, $8000
800C1E08	addu   v0, a0, at
800C1E0C	jr     ra 
800C1E10	sra    v0, v0, $08


funcc1e14:	; 800C1E14
800C1E14	addu   t3, a0, zero
800C1E18	addu   t5, a1, zero
800C1E1C	addu   t4, a2, zero
800C1E20	lbu    t7, $0010(sp)
800C1E24	lbu    t6, $0014(sp)
800C1E28	sll    a1, t7, $01
800C1E2C	addu   v0, a1, t5
800C1E30	addu   t0, a1, t3

Lc1e34:	; 800C1E34
800C1E34	sll    a2, t6, $01
800C1E38	addu   v1, a2, a3
800C1E3C	addu   a0, a2, t4
800C1E40	lh     v0, $0000(v0)
800C1E44	lh     t1, $0000(t0)

Lc1e48:	; 800C1E48
800C1E48	lh     t0, $0000(v1)
800C1E4C	lh     a0, $0000(a0)
800C1E50	subu   v0, v0, t1
800C1E54	subu   t0, t0, a0
800C1E58	mult   v0, t0

Lc1e5c:	; 800C1E5C
800C1E5C	addu   a3, a1, a3
800C1E60	addu   a1, a1, t4
800C1E64	lh     v1, $0000(a3)
800C1E68	lh     a3, $0000(a1)
800C1E6C	addu   v0, a2, t3
800C1E70	lh     a1, $0000(v0)
800C1E74	mflo   t2
800C1E78	subu   v1, v1, a3
800C1E7C	subu   a0, a1, a0
800C1E80	mult   a0, v1

Lc1e84:	; 800C1E84
800C1E84	addu   a2, a2, t5

funcc1e88:	; 800C1E88
800C1E88	lh     v0, $0000(a2)
800C1E8C	mflo   a0
800C1E90	subu   v0, v0, a1
800C1E94	nop
800C1E98	mult   v0, v1
800C1E9C	mflo   v0
800C1EA0	subu   t1, t1, a3
800C1EA4	nop
800C1EA8	mult   t1, t0
800C1EAC	subu   t2, t2, v0
800C1EB0	mflo   v1
800C1EB4	subu   a0, a0, v1
800C1EB8	bgez   a0, Lc1ec4 [$800c1ec4]
800C1EBC	addu   v1, a0, zero
800C1EC0	subu   v1, zero, v1

Lc1ec4:	; 800C1EC4
800C1EC4	bltz   t2, Lc1edc [$800c1edc]
800C1EC8	slt    v0, t2, v1
800C1ECC	beq    v0, zero, Lc1eec [$800c1eec]
800C1ED0	addu   v0, zero, zero
800C1ED4	j      Lc1f90 [$800c1f90]
800C1ED8	nop

Lc1edc:	; 800C1EDC
800C1EDC	subu   v0, zero, t2
800C1EE0	slt    v0, v0, v1
800C1EE4	bne    v0, zero, Lc1f90 [$800c1f90]
800C1EE8	addu   v0, zero, zero

Lc1eec:	; 800C1EEC
800C1EEC	bltz   a0, Lc1f04 [$800c1f04]
800C1EF0	nop
800C1EF4	bgez   t2, Lc1f10 [$800c1f10]
800C1EF8	sll    a2, t6, $01
800C1EFC	bgtz   a0, Lc1f90 [$800c1f90]

funcc1f00:	; 800C1F00
800C1F00	addu   v0, zero, zero

Lc1f04:	; 800C1F04
800C1F04	bgez   t2, Lc1f90 [$800c1f90]
800C1F08	addu   v0, zero, zero
800C1F0C	sll    a2, t6, $01

Lc1f10:	; 800C1F10
800C1F10	addu   v1, a2, t3
800C1F14	addu   a3, a2, t4
800C1F18	sll    a0, t7, $01
800C1F1C	addu   v0, a0, t5
800C1F20	addu   a1, a0, t3

Lc1f24:	; 800C1F24
800C1F24	lh     t0, $0000(v1)
800C1F28	lh     v1, $0000(a3)
800C1F2C	lh     v0, $0000(v0)
800C1F30	lh     a1, $0000(a1)
800C1F34	subu   v1, t0, v1

Lc1f38:	; 800C1F38
800C1F38	subu   v0, v0, a1
800C1F3C	mult   v1, v0
800C1F40	addu   a0, a0, t4
800C1F44	addu   a2, a2, t5
800C1F48	lh     v1, $0000(a0)

Lc1f4c:	; 800C1F4C
800C1F4C	lh     v0, $0000(a2)
800C1F50	mflo   a3
800C1F54	subu   a1, a1, v1
800C1F58	subu   v0, v0, t0
800C1F5C	mult   a1, v0

Lc1f60:	; 800C1F60
800C1F60	mflo   v1
800C1F64	subu   a3, a3, v1
800C1F68	bltz   a3, Lc1f80 [$800c1f80]
800C1F6C	nop
800C1F70	bgez   t2, Lc1f88 [$800c1f88]
800C1F74	nop
800C1F78	bgtz   a3, Lc1f90 [$800c1f90]

funcc1f7c:	; 800C1F7C
800C1F7C	addu   v0, zero, zero

Lc1f80:	; 800C1F80
800C1F80	bgez   t2, Lc1f90 [$800c1f90]
800C1F84	addu   v0, zero, zero

Lc1f88:	; 800C1F88
800C1F88	jr     ra 
800C1F8C	addiu  v0, zero, $0001


Lc1f90:	; 800C1F90
800C1F90	jr     ra 
800C1F94	nop



////////////////////////////////
// field_get_next_walkmesh_triangle_address
800C1F98-800C20B4
////////////////////////////////



funcc20b8:	; 800C20B8
800C20B8	addiu  sp, sp, $0020



////////////////////////////////
// field_calculate_square_distance_point_to_line
800C20BC-800C238C
////////////////////////////////



////////////////////////////////
// funcc2390
800C2390-800C2520
////////////////////////////////



////////////////////////////////
// field_walkmesh_check_collide_with_triangle_unaccessable
800C2524-800C291C
////////////////////////////////



////////////////////////////////
// funcc2920
800C2920-800C2AEC
////////////////////////////////



////////////////////////////////
// funcc2af0
800C2AF0-800C31F4
////////////////////////////////



////////////////////////////////
// funcc31f8
800C31F8-800C3604
////////////////////////////////



////////////////////////////////
// funcc3608
800C3608-800C3B7C
////////////////////////////////



////////////////////////////////
// funcc3b80
800C3B80-800C3D24
////////////////////////////////



800C3D28	addiu  sp, sp, $ffe8 (=-$18)
800C3D2C	sw     s0, $0010(sp)
800C3D30	addu   s0, a0, zero
800C3D34	lui    v0, $8006
800C3D38	sw     ra, $0014(sp)
800C3D3C	sw     zero, $0000(s0)
800C3D40	lw     v1, $794c(v0)
800C3D44	nop
800C3D48	lbu    a0, $0008(v1)
800C3D4C	addiu  v0, zero, $0005
800C3D50	bne    a0, v0, Lc3d90 [$800c3d90]
800C3D54	addiu  v0, zero, $0001
800C3D58	lw     a0, $001c(v1)
800C3D5C	nop
800C3D60	lw     v0, $08e4(a0)
800C3D64	nop
800C3D68	lb     v1, $0008(v0)
800C3D6C	nop
800C3D70	sll    v0, v1, $02
800C3D74	addu   v0, v0, v1
800C3D78	lw     v1, $08e0(a0)
800C3D7C	sll    v0, v0, $02
800C3D80	addu   v0, v0, v1
800C3D84	lw     a2, $000c(v0)
800C3D88	j      Lc3db8 [$800c3db8]
800C3D8C	nop

Lc3d90:	; 800C3D90
800C3D90	bne    a0, v0, Lc3db8 [$800c3db8]
800C3D94	addu   a2, zero, zero
800C3D98	jal    func4ae00 [$8004ae00]
800C3D9C	nop
800C3DA0	j      Lc3db8 [$800c3db8]
800C3DA4	addu   a2, v0, zero

loopc3da8:	; 800C3DA8
800C3DA8	sw     v1, $0000(s0)
800C3DAC	lw     v0, $0004(t0)
800C3DB0	j      Lc3e08 [$800c3e08]
800C3DB4	addu   v0, v0, a1

Lc3db8:	; 800C3DB8
800C3DB8	beq    a2, zero, Lc3e04 [$800c3e04]
800C3DBC	lui    v0, $800d
800C3DC0	addiu  v0, v0, $9df0 (=-$6210)
800C3DC4	lhu    a0, $0002(v0)
800C3DC8	nop
800C3DCC	beq    a0, zero, Lc3e04 [$800c3e04]
800C3DD0	addu   v1, zero, zero
800C3DD4	addu   a3, a0, zero
800C3DD8	addu   t0, v0, zero
800C3DDC	lw     a0, $0004(t0)
800C3DE0	addu   a1, v1, zero

loopc3de4:	; 800C3DE4
800C3DE4	lw     v0, $0024(a0)
800C3DE8	nop
800C3DEC	beq    v0, a2, loopc3da8 [$800c3da8]
800C3DF0	addiu  a0, a0, $0028
800C3DF4	addiu  v1, v1, $0001
800C3DF8	slt    v0, v1, a3
800C3DFC	bne    v0, zero, loopc3de4 [$800c3de4]
800C3E00	addiu  a1, a1, $0028

Lc3e04:	; 800C3E04
800C3E04	addu   v0, zero, zero

Lc3e08:	; 800C3E08
800C3E08	lw     ra, $0014(sp)
800C3E0C	lw     s0, $0010(sp)
800C3E10	jr     ra 
800C3E14	addiu  sp, sp, $0018



////////////////////////////////
// funcc3e18
800C3E18-800C3EBC
////////////////////////////////



////////////////////////////////
// funcc3ec0
800C3EC0-800C4208
////////////////////////////////



800C420C	lui    t0, $800d
800C4210	addiu  t0, t0, $9df0 (=-$6210)
800C4214	andi   v1, a1, $ffff
800C4218	sll    v0, v1, $02
800C421C	addu   v0, v0, v1
800C4220	sll    v0, v0, $03
800C4224	lw     t1, $0010(t0)

Lc4228:	; 800C4228
800C4228	lw     a2, $001c(t0)
800C422C	addu   t1, t1, v0
800C4230	lh     v0, $0004(t1)
800C4234	lw     a3, $0008(t0)
800C4238	sll    v0, v0, $05
800C423C	addu   a2, a2, v0
800C4240	lhu    v0, $0008(a3)
800C4244	lhu    v1, $000a(a2)
800C4248	addiu  sp, sp, $fff8 (=-$8)
800C424C	addu   v0, v0, v1
800C4250	sh     v0, $0000(sp)
800C4254	lhu    v0, $000a(a3)
800C4258	lhu    v1, $000c(a2)
800C425C	nop
800C4260	addu   v0, v0, v1
800C4264	sh     v0, $0002(sp)
800C4268	lhu    v1, $000e(a2)
800C426C	sll    a2, a0, $02
800C4270	addu   a2, a2, a0
800C4274	lhu    v0, $000c(a3)
800C4278	sll    a2, a2, $03
800C427C	addu   v0, v0, v1
800C4280	sh     v0, $0004(sp)
800C4284	lw     v0, $0004(t0)
800C4288	lhu    v1, $0004(t1)
800C428C	addu   v0, a2, v0
800C4290	sh     v1, $0004(v0)
800C4294	lw     v0, $0004(t0)
800C4298	nop
800C429C	addu   v0, a2, v0
800C42A0	sh     a1, $0006(v0)
800C42A4	lw     v0, $0004(t0)
800C42A8	lh     v1, $0000(sp)
800C42AC	lh     a0, $001e(t1)
800C42B0	addu   v0, a2, v0
800C42B4	lw     v0, $0024(v0)
800C42B8	addu   v1, v1, a0
800C42BC	sw     v1, $0014(v0)
800C42C0	lw     v1, $0004(t0)
800C42C4	lhu    v0, $0002(sp)
800C42C8	lh     a0, $0020(t1)
800C42CC	addu   v1, a2, v1
800C42D0	sll    v0, v0, $10
800C42D4	sra    v0, v0, $10
800C42D8	lw     v1, $0024(v1)
800C42DC	addu   v0, v0, a0
800C42E0	sw     v0, $0018(v1)
800C42E4	lw     v1, $0004(t0)
800C42E8	lhu    v0, $0004(sp)
800C42EC	lh     a0, $0022(t1)
800C42F0	addu   v1, a2, v1
800C42F4	sll    v0, v0, $10
800C42F8	sra    v0, v0, $10
800C42FC	lw     v1, $0024(v1)
800C4300	addu   v0, v0, a0
800C4304	sw     v0, $001c(v1)
800C4308	lw     v0, $0004(t0)
800C430C	lh     v1, $0000(sp)
800C4310	lh     a0, $001e(t1)
800C4314	addu   v0, a2, v0
800C4318	lw     v0, $0024(v0)
800C431C	addu   v1, v1, a0
800C4320	sw     v1, $0040(v0)
800C4324	lw     v1, $0004(t0)
800C4328	lhu    v0, $0002(sp)
800C432C	lh     a0, $0020(t1)
800C4330	addu   v1, a2, v1
800C4334	sll    v0, v0, $10
800C4338	sra    v0, v0, $10
800C433C	lw     v1, $0024(v1)
800C4340	addu   v0, v0, a0
800C4344	sw     v0, $0044(v1)
800C4348	lw     v1, $0004(t0)
800C434C	lhu    v0, $0004(sp)
800C4350	addu   a2, a2, v1
800C4354	sll    v0, v0, $10
800C4358	sra    v0, v0, $10
800C435C	lh     v1, $0022(t1)
800C4360	lw     a0, $0024(a2)
800C4364	addu   v0, v0, v1
800C4368	sw     v0, $0048(a0)
800C436C	addiu  v0, zero, $0001

Lc4370:	; 800C4370
800C4370	jr     ra 

Lc4374:	; 800C4374
800C4374	addiu  sp, sp, $0008

800C4378	addiu  sp, sp, $fff8 (=-$8)

Lc437c:	; 800C437C
800C437C	lui    t1, $800d
800C4380	addiu  t1, t1, $9df0 (=-$6210)
800C4384	andi   v0, a1, $ffff
800C4388	sll    v0, v0, $05
800C438C	andi   a2, a2, $ffff
800C4390	sll    a2, a2, $02
800C4394	lw     a3, $001c(t1)
800C4398	lw     t0, $0008(t1)
800C439C	addu   a3, a3, v0
800C43A0	lhu    v0, $001e(a3)
800C43A4	lhu    v1, $000a(a3)
800C43A8	addu   v0, t0, v0
800C43AC	addu   a2, a2, v0
800C43B0	lhu    v0, $0008(t0)
800C43B4	lw     t2, $0000(a2)
800C43B8	addu   v0, v0, v1
800C43BC	sh     v0, $0000(sp)
800C43C0	lhu    v0, $000a(t0)
800C43C4	lhu    v1, $000c(a3)
800C43C8	nop
800C43CC	addu   v0, v0, v1
800C43D0	sh     v0, $0002(sp)
800C43D4	lhu    v1, $000e(a3)
800C43D8	sll    a3, a0, $02
800C43DC	addu   a3, a3, a0
800C43E0	lhu    v0, $000c(t0)
800C43E4	sll    a3, a3, $03
800C43E8	addu   v0, v0, v1
800C43EC	sh     v0, $0004(sp)
800C43F0	lw     v0, $0004(t1)
800C43F4	lw     t0, $0010(t1)
800C43F8	addu   v0, a3, v0
800C43FC	sh     a1, $0004(v0)
800C4400	lw     v0, $0004(t1)
800C4404	lhu    v1, $0000(a2)
800C4408	addu   v0, a3, v0
800C440C	sh     v1, $0006(v0)
800C4410	sll    v0, t2, $02
800C4414	addu   v0, v0, t2
800C4418	sll    v0, v0, $03
800C441C	addu   t0, t0, v0
800C4420	lw     v1, $0004(t1)
800C4424	lh     v0, $0000(sp)
800C4428	lh     a0, $001e(t0)
800C442C	addu   v1, a3, v1
800C4430	lw     v1, $0024(v1)
800C4434	addu   v0, v0, a0
800C4438	sw     v0, $0014(v1)
800C443C	lw     v1, $0004(t1)
800C4440	lhu    v0, $0002(sp)
800C4444	lh     a0, $0020(t0)
800C4448	addu   v1, a3, v1
800C444C	sll    v0, v0, $10
800C4450	sra    v0, v0, $10
800C4454	lw     v1, $0024(v1)
800C4458	addu   v0, v0, a0
800C445C	sw     v0, $0018(v1)
800C4460	lw     v1, $0004(t1)
800C4464	lhu    v0, $0004(sp)
800C4468	lh     a0, $0022(t0)
800C446C	addu   v1, a3, v1
800C4470	sll    v0, v0, $10
800C4474	sra    v0, v0, $10
800C4478	lw     v1, $0024(v1)
800C447C	addu   v0, v0, a0
800C4480	sw     v0, $001c(v1)
800C4484	lw     v0, $0004(t1)
800C4488	lh     v1, $0000(sp)
800C448C	lh     a0, $001e(t0)
800C4490	addu   v0, a3, v0
800C4494	lw     v0, $0024(v0)
800C4498	addu   v1, v1, a0
800C449C	sw     v1, $0040(v0)
800C44A0	lw     v1, $0004(t1)
800C44A4	lhu    v0, $0002(sp)
800C44A8	lh     a0, $0020(t0)
800C44AC	addu   v1, a3, v1
800C44B0	sll    v0, v0, $10
800C44B4	sra    v0, v0, $10
800C44B8	lw     v1, $0024(v1)
800C44BC	addu   v0, v0, a0
800C44C0	sw     v0, $0044(v1)
800C44C4	lw     v1, $0004(t1)
800C44C8	lhu    v0, $0004(sp)

Lc44cc:	; 800C44CC
800C44CC	addu   a3, a3, v1
800C44D0	sll    v0, v0, $10

Lc44d4:	; 800C44D4
800C44D4	sra    v0, v0, $10

Lc44d8:	; 800C44D8
800C44D8	lh     v1, $0022(t0)
800C44DC	lw     a0, $0024(a3)
800C44E0	addu   v0, v0, v1
800C44E4	sw     v0, $0048(a0)
800C44E8	addiu  v0, zero, $0001
800C44EC	jr     ra 
800C44F0	addiu  sp, sp, $0008



////////////////////////////////
// funcc44f4
800C44F4-800C45BC
////////////////////////////////



800C45C0	addiu  sp, sp, $ffa8 (=-$58)
800C45C4	sw     s7, $004c(sp)
800C45C8	addiu  s7, zero, $7fff
800C45CC	addiu  v0, zero, $ffff (=-$1)
800C45D0	sw     ra, $0054(sp)
800C45D4	sw     fp, $0050(sp)
800C45D8	sw     s6, $0048(sp)
800C45DC	sw     s5, $0044(sp)
800C45E0	sw     s4, $0040(sp)
800C45E4	sw     s3, $003c(sp)
800C45E8	sw     s2, $0038(sp)
800C45EC	sw     s1, $0034(sp)
800C45F0	sw     s0, $0030(sp)
800C45F4	sw     a3, $0064(sp)
800C45F8	sh     v0, $0000(a3)
800C45FC	lui    v0, $800d
800C4600	lw     t0, $0068(sp)
800C4604	addiu  v1, v0, $9df0 (=-$6210)
800C4608	sw     zero, $0000(t0)
800C460C	lw     s3, $0010(v1)
800C4610	lw     s6, $0008(v1)
800C4614	addu   fp, zero, zero
800C4618	sh     a0, $0010(sp)
800C461C	sh     a1, $0012(sp)
800C4620	sh     a2, $0014(sp)
800C4624	lhu    v0, $0024(s6)
800C4628	addu   s5, fp, zero
800C462C	beq    v0, zero, Lc47b0 [$800c47b0]
800C4630	sh     a1, $0028(sp)
800C4634	addu   s4, v1, zero
800C4638	addiu  s2, s3, $000c

loopc463c:	; 800C463C
800C463C	addu   a0, s6, zero
800C4640	addu   a2, s3, zero
800C4644	addiu  a3, sp, $0010
800C4648	lh     a1, $fff8(s2)
800C464C	lw     v0, $001c(s4)
800C4650	sll    a1, a1, $05
800C4654	jal    field_check_in_walkmesh_triangle [$800c4ec8]
800C4658	addu   a1, v0, a1
800C465C	andi   v0, v0, $00ff
800C4660	beq    v0, zero, Lc478c [$800c478c]
800C4664	nop
800C4668	lh     a0, $fffa(s2)
800C466C	nop
800C4670	bltz   a0, Lc470c [$800c470c]
800C4674	nop
800C4678	lh     a1, $0010(sp)
800C467C	lh     v0, $0012(sp)
800C4680	lh     v1, $0014(sp)
800C4684	sw     a1, $0018(sp)
800C4688	sw     v0, $001c(sp)
800C468C	sw     v1, $0020(sp)
800C4690	lw     s0, $0014(s4)
800C4694	sll    v0, a0, $04
800C4698	addu   s0, s0, v0
800C469C	lw     a0, $0000(s0)
800C46A0	jal    funcc1dc4 [$800c1dc4]
800C46A4	sll    a1, a1, $10
800C46A8	addu   s1, v0, zero
800C46AC	lw     a1, $0020(sp)
800C46B0	lw     a0, $0008(s0)
800C46B4	jal    funcc1dc4 [$800c1dc4]
800C46B8	sll    a1, a1, $10
800C46BC	lw     a0, $0018(s2)
800C46C0	lw     a1, $000c(s0)
800C46C4	subu   a0, a0, s1
800C46C8	jal    funcc1dc4 [$800c1dc4]
800C46CC	subu   a0, a0, v0
800C46D0	sra    v0, v0, $10
800C46D4	sw     v0, $001c(sp)
800C46D8	lh     v1, $fff8(s2)
800C46DC	lw     a0, $001c(s4)
800C46E0	sll    v1, v1, $05
800C46E4	addu   v1, v1, a0
800C46E8	lh     a0, $000c(v1)
800C46EC	lh     v1, $0006(v1)
800C46F0	nop
800C46F4	subu   a0, a0, v1
800C46F8	addu   v0, v0, a0
800C46FC	sw     v0, $001c(sp)
800C4700	lhu    v0, $001c(sp)
800C4704	j      Lc4750 [$800c4750]
800C4708	sh     v0, $0012(sp)

Lc470c:	; 800C470C
800C470C	lh     v0, $fff8(s2)

Lc4710:	; 800C4710
800C4710	lw     a1, $001c(s4)
800C4714	lh     v1, $0000(s2)
800C4718	lw     a0, $000c(s4)
800C471C	sll    v0, v0, $05
800C4720	addu   a1, a1, v0
800C4724	sll    v0, v1, $01
800C4728	addu   v0, v0, v1
800C472C	sll    v0, v0, $01
800C4730	addu   a0, a0, v0
800C4734	lw     v1, $0008(s4)
800C4738	lhu    a1, $000c(a1)

Lc473c:	; 800C473C
800C473C	lhu    v1, $000a(v1)
800C4740	lhu    v0, $0002(a0)
800C4744	addu   v1, v1, a1
800C4748	addu   v0, v0, v1
800C474C	sh     v0, $0012(sp)

Lc4750:	; 800C4750
800C4750	lhu    t0, $0028(sp)
800C4754	lh     v1, $0012(sp)
800C4758	sll    v0, t0, $10
800C475C	sra    v0, v0, $10
800C4760	slt    v0, v1, v0
800C4764	bne    v0, zero, Lc478c [$800c478c]
800C4768	slt    v0, v1, s7
800C476C	beq    v0, zero, Lc478c [$800c478c]
800C4770	nop
800C4774	lw     t0, $0064(sp)
800C4778	addiu  fp, zero, $0001
800C477C	sh     s5, $0000(t0)
800C4780	lw     t0, $0068(sp)
800C4784	addu   s7, v1, zero
800C4788	sw     s3, $0000(t0)

Lc478c:	; 800C478C
800C478C	addiu  s2, s2, $0028
800C4790	addiu  v0, s5, $0001
800C4794	addu   s5, v0, zero
800C4798	sll    v0, v0, $10

Lc479c:	; 800C479C
800C479C	lhu    v1, $0024(s6)
800C47A0	sra    v0, v0, $10
800C47A4	slt    v0, v0, v1
800C47A8	bne    v0, zero, loopc463c [$800c463c]
800C47AC	addiu  s3, s3, $0028

Lc47b0:	; 800C47B0
800C47B0	addu   v0, fp, zero
800C47B4	lw     ra, $0054(sp)
800C47B8	lw     fp, $0050(sp)
800C47BC	lw     s7, $004c(sp)
800C47C0	lw     s6, $0048(sp)
800C47C4	lw     s5, $0044(sp)
800C47C8	lw     s4, $0040(sp)
800C47CC	lw     s3, $003c(sp)
800C47D0	lw     s2, $0038(sp)
800C47D4	lw     s1, $0034(sp)
800C47D8	lw     s0, $0030(sp)
800C47DC	jr     ra 
800C47E0	addiu  sp, sp, $0058


funcc47e4:	; 800C47E4
800C47E4	lui    v0, $800d
800C47E8	addiu  t0, v0, $9df0 (=-$6210)

Lc47ec:	; 800C47EC
800C47EC	lw     a3, $0008(t0)
800C47F0	nop
800C47F4	lhu    v0, $0032(a3)
800C47F8	sll    a0, a0, $05
800C47FC	addu   v0, a3, v0
800C4800	beq    a1, zero, Lc4870 [$800c4870]
800C4804	addu   a2, v0, a0
800C4808	lhu    v0, $001e(a2)
800C480C	lhu    v1, $0000(a2)
800C4810	addu   a1, a3, v0
800C4814	lhu    v0, $001c(a2)
800C4818	ori    v1, v1, $0001
800C481C	sh     v1, $0000(a2)
800C4820	lw     a3, $0010(t0)
800C4824	beq    v0, zero, Lc48d0 [$800c48d0]
800C4828	addu   a0, zero, zero

loopc482c:	; 800C482C
800C482C	lw     v1, $0000(a1)
800C4830	nop
800C4834	sll    v0, v1, $02
800C4838	addu   v0, v0, v1
800C483C	sll    v0, v0, $03
800C4840	addu   v0, v0, a3
800C4844	lhu    v1, $0000(v0)
800C4848	nop
800C484C	ori    v1, v1, $0001
800C4850	sh     v1, $0000(v0)
800C4854	lhu    v0, $001c(a2)
800C4858	addiu  a0, a0, $0001
800C485C	slt    v0, a0, v0
800C4860	bne    v0, zero, loopc482c [$800c482c]
800C4864	addiu  a1, a1, $0004
800C4868	jr     ra 
800C486C	addiu  v0, zero, $0001


Lc4870:	; 800C4870
800C4870	lhu    v0, $001e(a2)
800C4874	lhu    v1, $0000(a2)
800C4878	addu   a1, a3, v0
800C487C	lhu    v0, $001c(a2)
800C4880	andi   v1, v1, $fffe
800C4884	sh     v1, $0000(a2)
800C4888	lw     a3, $0010(t0)
800C488C	beq    v0, zero, Lc48d0 [$800c48d0]
800C4890	addu   a0, zero, zero

loopc4894:	; 800C4894
800C4894	lw     v1, $0000(a1)
800C4898	nop
800C489C	sll    v0, v1, $02
800C48A0	addu   v0, v0, v1
800C48A4	sll    v0, v0, $03
800C48A8	addu   v0, v0, a3
800C48AC	lhu    v1, $0000(v0)
800C48B0	nop
800C48B4	andi   v1, v1, $fffe
800C48B8	sh     v1, $0000(v0)
800C48BC	lhu    v0, $001c(a2)
800C48C0	addiu  a0, a0, $0001
800C48C4	slt    v0, a0, v0
800C48C8	bne    v0, zero, loopc4894 [$800c4894]

Lc48cc:	; 800C48CC
800C48CC	addiu  a1, a1, $0004

Lc48d0:	; 800C48D0
800C48D0	addiu  v0, zero, $0001
800C48D4	jr     ra 
800C48D8	nop

800C48DC	addiu  sp, sp, $ffc0 (=-$40)
800C48E0	lui    v0, $800d
800C48E4	addiu  a2, v0, $9df0 (=-$6210)
800C48E8	sw     ra, $0038(sp)
800C48EC	sw     s3, $0034(sp)
800C48F0	sw     s2, $0030(sp)
800C48F4	sw     s1, $002c(sp)
800C48F8	sw     s0, $0028(sp)
800C48FC	lw     v1, $0008(a2)
800C4900	nop
800C4904	bne    v1, zero, Lc4a24 [$800c4a24]
800C4908	addiu  v0, zero, $a329 (=-$5cd7)
800C490C	lui    v0, $8006
800C4910	lw     v1, $794c(v0)
800C4914	nop

Lc4918:	; 800C4918
800C4918	lbu    a0, $0008(v1)

Lc491c:	; 800C491C
800C491C	addiu  v0, zero, $0005
800C4920	bne    a0, v0, Lc4968 [$800c4968]
800C4924	addiu  v0, zero, $0001
800C4928	lw     a0, $001c(v1)
800C492C	nop
800C4930	lw     v0, $08e4(a0)
800C4934	nop
800C4938	lb     v1, $0008(v0)

funcc493c:	; 800C493C
800C493C	nop

Lc4940:	; 800C4940
800C4940	sll    v0, v1, $02
800C4944	addu   v0, v0, v1
800C4948	lw     v1, $08e0(a0)
800C494C	sll    v0, v0, $02
800C4950	addu   v0, v0, v1
800C4954	lw     v0, $000c(v0)
800C4958	nop
800C495C	lh     v0, $0018(v0)
800C4960	j      Lc4b14 [$800c4b14]
800C4964	nop

Lc4968:	; 800C4968
800C4968	bne    a0, v0, Lc4b14 [$800c4b14]
800C496C	addu   v0, zero, zero
800C4970	jal    func4ae00 [$8004ae00]
800C4974	nop
800C4978	lh     v0, $0018(v0)
800C497C	j      Lc4b14 [$800c4b14]
800C4980	nop

loopc4984:	; 800C4984
800C4984	lh     a1, $0010(sp)
800C4988	lh     v0, $0012(sp)
800C498C	lh     v1, $0014(sp)
800C4990	sw     a1, $0018(sp)
800C4994	sw     v0, $001c(sp)
800C4998	sw     v1, $0020(sp)
800C499C	lw     s0, $0014(s3)
800C49A0	sll    v0, a0, $04
800C49A4	addu   s0, s0, v0
800C49A8	lw     a0, $0000(s0)
800C49AC	jal    funcc1dc4 [$800c1dc4]
800C49B0	sll    a1, a1, $10
800C49B4	addu   s1, v0, zero

Lc49b8:	; 800C49B8
800C49B8	lw     a1, $0020(sp)
800C49BC	lw     a0, $0008(s0)
800C49C0	jal    funcc1dc4 [$800c1dc4]
800C49C4	sll    a1, a1, $10
800C49C8	lw     a0, $0024(s2)

Lc49cc:	; 800C49CC
800C49CC	lw     a1, $000c(s0)
800C49D0	subu   a0, a0, s1
800C49D4	jal    funcc1dc4 [$800c1dc4]
800C49D8	subu   a0, a0, v0
800C49DC	sra    v0, v0, $10
800C49E0	sw     v0, $001c(sp)
800C49E4	lh     v1, $0004(s2)
800C49E8	lw     a0, $001c(s3)
800C49EC	sll    v1, v1, $05
800C49F0	addu   v1, v1, a0
800C49F4	lh     a0, $000c(v1)
800C49F8	lh     v1, $0006(v1)
800C49FC	nop
800C4A00	subu   a0, a0, v1
800C4A04	addu   v0, v0, a0
800C4A08	sw     v0, $001c(sp)
800C4A0C	lhu    v1, $001c(sp)
800C4A10	nop
800C4A14	sll    v0, v1, $10
800C4A18	sra    v0, v0, $10
800C4A1C	j      Lc4b14 [$800c4b14]
800C4A20	sh     v1, $0012(sp)

Lc4a24:	; 800C4A24
800C4A24	sh     a0, $0010(sp)
800C4A28	sh     v0, $0012(sp)
800C4A2C	sh     a1, $0014(sp)
800C4A30	lhu    v0, $0024(v1)
800C4A34	lw     s2, $0010(a2)
800C4A38	beq    v0, zero, Lc4b10 [$800c4b10]
800C4A3C	addu   s1, zero, zero

Lc4a40:	; 800C4A40
800C4A40	addu   s3, a2, zero
800C4A44	addiu  s0, s2, $000c

loopc4a48:	; 800C4A48
800C4A48	addu   a2, s2, zero
800C4A4C	addiu  a3, sp, $0010
800C4A50	lw     a0, $0008(s3)
800C4A54	lh     a1, $fff8(s0)

Lc4a58:	; 800C4A58
800C4A58	lw     v0, $001c(s3)
800C4A5C	sll    a1, a1, $05
800C4A60	jal    field_check_in_walkmesh_triangle [$800c4ec8]
800C4A64	addu   a1, v0, a1
800C4A68	andi   v0, v0, $00ff
800C4A6C	beq    v0, zero, Lc4af0 [$800c4af0]
800C4A70	addiu  s1, s1, $0001
800C4A74	lh     a0, $fffa(s0)
800C4A78	nop
800C4A7C	bgez   a0, loopc4984 [$800c4984]
800C4A80	nop
800C4A84	lw     v0, $0008(s3)
800C4A88	nop

Lc4a8c:	; 800C4A8C
800C4A8C	lhu    a0, $000a(v0)
800C4A90	nop
800C4A94	sh     a0, $0012(sp)
800C4A98	lh     v0, $fff8(s0)
800C4A9C	lw     v1, $001c(s3)
800C4AA0	sll    v0, v0, $05
800C4AA4	addu   v0, v0, v1
800C4AA8	lhu    v0, $000c(v0)
800C4AAC	nop
800C4AB0	addu   a0, a0, v0
800C4AB4	sh     a0, $0012(sp)
800C4AB8	lh     v1, $0000(s0)
800C4ABC	nop
800C4AC0	sll    v0, v1, $01
800C4AC4	addu   v0, v0, v1
800C4AC8	lw     v1, $000c(s3)
800C4ACC	sll    v0, v0, $01
800C4AD0	addu   v0, v0, v1
800C4AD4	lhu    v0, $0002(v0)
800C4AD8	nop
800C4ADC	addu   a0, a0, v0
800C4AE0	sll    v0, a0, $10
800C4AE4	sra    v0, v0, $10
800C4AE8	j      Lc4b14 [$800c4b14]
800C4AEC	sh     a0, $0012(sp)

Lc4af0:	; 800C4AF0
800C4AF0	addiu  s0, s0, $0028
800C4AF4	lw     v0, $0008(s3)
800C4AF8	nop
800C4AFC	lhu    v1, $0024(v0)
800C4B00	andi   v0, s1, $ffff
800C4B04	sltu   v0, v0, v1
800C4B08	bne    v0, zero, loopc4a48 [$800c4a48]
800C4B0C	addiu  s2, s2, $0028

Lc4b10:	; 800C4B10
800C4B10	addiu  v0, zero, $8001 (=-$7fff)

Lc4b14:	; 800C4B14
800C4B14	lw     ra, $0038(sp)
800C4B18	lw     s3, $0034(sp)
800C4B1C	lw     s2, $0030(sp)
800C4B20	lw     s1, $002c(sp)
800C4B24	lw     s0, $0028(sp)
800C4B28	jr     ra 
800C4B2C	addiu  sp, sp, $0040



////////////////////////////////
// funcc4b30
800C4B30-800C4EC4
////////////////////////////////



////////////////////////////////
// field_check_in_walkmesh_triangle
800C4EC8-800C5198
////////////////////////////////



////////////////////////////////
// funcc519c
800C519C-800C5A78
////////////////////////////////



800C5A7C	addiu  sp, sp, $ffc0 (=-$40)
800C5A80	sw     s7, $0034(sp)
800C5A84	addu   s7, a0, zero
800C5A88	sw     ra, $003c(sp)
800C5A8C	sw     fp, $0038(sp)
800C5A90	sw     s6, $0030(sp)
800C5A94	sw     s5, $002c(sp)
800C5A98	sw     s4, $0028(sp)
800C5A9C	sw     s3, $0024(sp)
800C5AA0	sw     s2, $0020(sp)
800C5AA4	sw     s1, $001c(sp)
800C5AA8	beq    s7, zero, Lc60c0 [$800c60c0]
800C5AAC	sw     s0, $0018(sp)
800C5AB0	lui    a0, $800a
800C5AB4	jal    func15c38 [$80015c38]
800C5AB8	addiu  a0, a0, $71f4
800C5ABC	lui    a0, $800a
800C5AC0	jal    func15c38 [$80015c38]
800C5AC4	addiu  a0, a0, $7204
800C5AC8	lui    a0, $800a
800C5ACC	addiu  a0, a0, $7214
800C5AD0	lhu    a1, $0000(s7)
800C5AD4	jal    func15c38 [$80015c38]
800C5AD8	addu   s6, zero, zero
800C5ADC	lui    a0, $800a
800C5AE0	lh     a1, $0002(s7)
800C5AE4	lh     a2, $0004(s7)
800C5AE8	lh     a3, $0006(s7)
800C5AEC	jal    func15c38 [$80015c38]
800C5AF0	addiu  a0, a0, $723c
800C5AF4	lui    a0, $800a
800C5AF8	lh     a1, $0008(s7)
800C5AFC	lh     a2, $000a(s7)
800C5B00	lh     a3, $000c(s7)
800C5B04	jal    func15c38 [$80015c38]

Lc5b08:	; 800C5B08
800C5B08	addiu  a0, a0, $7260
800C5B0C	lui    a0, $800a
800C5B10	lh     a1, $000e(s7)
800C5B14	lh     a2, $0010(s7)
800C5B18	lh     a3, $0012(s7)
800C5B1C	jal    func15c38 [$80015c38]
800C5B20	addiu  a0, a0, $7284
800C5B24	lui    a0, $800a
800C5B28	lh     a1, $0014(s7)
800C5B2C	lh     a2, $0016(s7)
800C5B30	lh     a3, $0018(s7)
800C5B34	jal    func15c38 [$80015c38]
800C5B38	addiu  a0, a0, $72a8
800C5B3C	lui    a0, $800a
800C5B40	lh     a1, $001a(s7)
800C5B44	lh     a2, $001c(s7)
800C5B48	lh     a3, $001e(s7)
800C5B4C	jal    func15c38 [$80015c38]
800C5B50	addiu  a0, a0, $72cc
800C5B54	lui    a0, $800a
800C5B58	lh     a1, $0020(s7)
800C5B5C	jal    func15c38 [$80015c38]
800C5B60	addiu  a0, a0, $72f0
800C5B64	lui    a0, $800a
800C5B68	lh     a1, $0022(s7)
800C5B6C	jal    func15c38 [$80015c38]
800C5B70	addiu  a0, a0, $7304
800C5B74	lui    a0, $800a
800C5B78	lhu    a1, $0024(s7)
800C5B7C	jal    func15c38 [$80015c38]
800C5B80	addiu  a0, a0, $731c
800C5B84	lui    a0, $800a
800C5B88	lhu    a1, $0026(s7)
800C5B8C	jal    func15c38 [$80015c38]
800C5B90	addiu  a0, a0, $7334
800C5B94	lhu    v0, $0026(s7)
800C5B98	lhu    v1, $0024(s7)
800C5B9C	nop
800C5BA0	beq    v1, zero, Lc5c9c [$800c5c9c]
800C5BA4	addu   s1, s7, v0
800C5BA8	addiu  s0, s1, $001c

loopc5bac:	; 800C5BAC
800C5BAC	lui    a0, $800a
800C5BB0	addiu  a0, a0, $734c
800C5BB4	addu   a1, s6, zero
800C5BB8	lhu    a2, $0000(s1)
800C5BBC	addiu  s1, s1, $0028
800C5BC0	jal    func15c38 [$80015c38]
800C5BC4	addiu  s6, s6, $0001
800C5BC8	lui    a0, $800a
800C5BCC	lhu    a1, $ffe6(s0)
800C5BD0	jal    func15c38 [$80015c38]
800C5BD4	addiu  a0, a0, $7368
800C5BD8	lui    a0, $800a
800C5BDC	lh     a1, $ffe8(s0)
800C5BE0	jal    func15c38 [$80015c38]
800C5BE4	addiu  a0, a0, $7378
800C5BE8	lui    a0, $800a
800C5BEC	lh     a1, $ffea(s0)
800C5BF0	jal    func15c38 [$80015c38]
800C5BF4	addiu  a0, a0, $7390
800C5BF8	lui    a0, $800a
800C5BFC	lh     a1, $ffec(s0)
800C5C00	jal    func15c38 [$80015c38]
800C5C04	addiu  a0, a0, $73a8
800C5C08	lui    a0, $800a
800C5C0C	lh     a1, $ffee(s0)
800C5C10	jal    func15c38 [$80015c38]
800C5C14	addiu  a0, a0, $73bc
800C5C18	lui    a0, $800a
800C5C1C	lw     a1, $0008(s0)
800C5C20	jal    func15c38 [$80015c38]
800C5C24	addiu  a0, a0, $73d0
800C5C28	lui    a0, $800a
800C5C2C	lh     a1, $0002(s0)
800C5C30	lh     a2, $0004(s0)
800C5C34	lh     a3, $0006(s0)
800C5C38	jal    func15c38 [$80015c38]
800C5C3C	addiu  a0, a0, $73e0
800C5C40	lui    a0, $800a
800C5C44	lh     a1, $fff0(s0)
800C5C48	lh     a2, $fff2(s0)
800C5C4C	lh     a3, $fff4(s0)
800C5C50	jal    func15c38 [$80015c38]
800C5C54	addiu  a0, a0, $7400
800C5C58	lui    a0, $800a
800C5C5C	lh     a1, $fff6(s0)
800C5C60	lh     a2, $fff8(s0)
800C5C64	lh     a3, $fffa(s0)
800C5C68	jal    func15c38 [$80015c38]
800C5C6C	addiu  a0, a0, $7424
800C5C70	lui    a0, $800a
800C5C74	lh     a1, $fffc(s0)
800C5C78	lh     a2, $fffe(s0)
800C5C7C	lh     a3, $0000(s0)
800C5C80	jal    func15c38 [$80015c38]
800C5C84	addiu  a0, a0, $7448
800C5C88	lhu    v0, $0024(s7)
800C5C8C	nop
800C5C90	slt    v0, s6, v0
800C5C94	bne    v0, zero, loopc5bac [$800c5bac]
800C5C98	addiu  s0, s0, $0028

Lc5c9c:	; 800C5C9C
800C5C9C	lui    a0, $800a
800C5CA0	addiu  a0, a0, $746c
800C5CA4	lhu    a1, $0028(s7)
800C5CA8	jal    func15c38 [$80015c38]
800C5CAC	addu   s6, zero, zero
800C5CB0	lui    a0, $800a
800C5CB4	lhu    a1, $002a(s7)
800C5CB8	jal    func15c38 [$80015c38]
800C5CBC	addiu  a0, a0, $7480
800C5CC0	lhu    v0, $002a(s7)
800C5CC4	lhu    v1, $0028(s7)
800C5CC8	nop
800C5CCC	beq    v1, zero, Lc5d10 [$800c5d10]
800C5CD0	addu   s0, s7, v0
800C5CD4	lui    s2, $800a
800C5CD8	lui    s1, $800a

loopc5cdc:	; 800C5CDC
800C5CDC	addiu  a0, s2, $7494
800C5CE0	addu   a1, s6, zero
800C5CE4	lhu    a2, $0000(s0)
800C5CE8	jal    func15c38 [$80015c38]
800C5CEC	addiu  s6, s6, $0001
800C5CF0	lh     a1, $0002(s0)
800C5CF4	jal    func15c38 [$80015c38]
800C5CF8	addiu  a0, s1, $74b0
800C5CFC	lhu    v0, $0028(s7)
800C5D00	nop
800C5D04	slt    v0, s6, v0
800C5D08	bne    v0, zero, loopc5cdc [$800c5cdc]
800C5D0C	addiu  s0, s0, $0004

Lc5d10:	; 800C5D10
800C5D10	lui    a0, $800a
800C5D14	addiu  a0, a0, $74c4
800C5D18	lhu    a1, $002c(s7)
800C5D1C	jal    func15c38 [$80015c38]
800C5D20	addu   s6, zero, zero
800C5D24	lui    a0, $800a
800C5D28	lhu    a1, $002e(s7)
800C5D2C	jal    func15c38 [$80015c38]
800C5D30	addiu  a0, a0, $74e4
800C5D34	lhu    v0, $002e(s7)
800C5D38	lhu    v1, $002c(s7)
800C5D3C	nop
800C5D40	beq    v1, zero, Lc5e84 [$800c5e84]
800C5D44	addu   fp, s7, v0
800C5D48	addiu  s4, fp, $0002

loopc5d4c:	; 800C5D4C
800C5D4C	lui    a0, $800a
800C5D50	addiu  a0, a0, $7504
800C5D54	addu   a1, s6, zero
800C5D58	lhu    a2, $0000(fp)
800C5D5C	jal    func15c38 [$80015c38]
800C5D60	addu   s3, zero, zero
800C5D64	lui    a0, $800a
800C5D68	lhu    a1, $0000(s4)
800C5D6C	jal    func15c38 [$80015c38]
800C5D70	addiu  a0, a0, $7520
800C5D74	lui    a0, $800a
800C5D78	lw     a1, $0006(s4)
800C5D7C	jal    func15c38 [$80015c38]
800C5D80	addiu  a0, a0, $7538
800C5D84	lui    a0, $800a
800C5D88	lh     a1, $0002(s4)
800C5D8C	jal    func15c38 [$80015c38]
800C5D90	addiu  a0, a0, $7550
800C5D94	lui    a0, $800a
800C5D98	lhu    a1, $0004(s4)
800C5D9C	jal    func15c38 [$80015c38]
800C5DA0	addiu  a0, a0, $7568
800C5DA4	lui    a0, $800a
800C5DA8	lw     a1, $000a(s4)
800C5DAC	jal    func15c38 [$80015c38]
800C5DB0	addiu  a0, a0, $757c
800C5DB4	lw     v0, $000a(s4)
800C5DB8	lhu    v1, $0000(s4)
800C5DBC	nop
800C5DC0	beq    v1, zero, Lc5e6c [$800c5e6c]
800C5DC4	addu   s5, s7, v0
800C5DC8	addiu  s1, s5, $0004

loopc5dcc:	; 800C5DCC
800C5DCC	lui    a0, $800a
800C5DD0	addiu  a0, a0, $7594
800C5DD4	addu   a1, s3, zero
800C5DD8	lhu    a2, $0000(s5)
800C5DDC	jal    func15c38 [$80015c38]
800C5DE0	addu   s2, zero, zero
800C5DE4	lui    a0, $800a
800C5DE8	lh     a1, $fffe(s1)
800C5DEC	jal    func15c38 [$80015c38]
800C5DF0	addiu  a0, a0, $75b8
800C5DF4	lui    a0, $800a
800C5DF8	lhu    a1, $0000(s1)
800C5DFC	jal    func15c38 [$80015c38]
800C5E00	addiu  a0, a0, $75dc
800C5E04	lui    a0, $800a
800C5E08	lhu    a1, $0002(s1)
800C5E0C	jal    func15c38 [$80015c38]
800C5E10	addiu  a0, a0, $7600
800C5E14	lhu    v0, $0002(s1)
800C5E18	lhu    v1, $0000(s1)
800C5E1C	nop
800C5E20	beq    v1, zero, Lc5e54 [$800c5e54]
800C5E24	addu   s0, s7, v0
800C5E28	lui    t0, $800a

loopc5e2c:	; 800C5E2C
800C5E2C	addiu  a0, t0, $761c
800C5E30	addu   a1, s3, zero
800C5E34	lw     a2, $0000(s0)
800C5E38	jal    func15c38 [$80015c38]
800C5E3C	addiu  s0, s0, $0004
800C5E40	lhu    v0, $0000(s1)
800C5E44	addiu  s2, s2, $0001
800C5E48	slt    v0, s2, v0
800C5E4C	bne    v0, zero, loopc5e2c [$800c5e2c]
800C5E50	lui    t0, $800a

Lc5e54:	; 800C5E54
800C5E54	addiu  s1, s1, $0008
800C5E58	lhu    v0, $0000(s4)
800C5E5C	addiu  s3, s3, $0001
800C5E60	slt    v0, s3, v0
800C5E64	bne    v0, zero, loopc5dcc [$800c5dcc]
800C5E68	addiu  s5, s5, $0008

Lc5e6c:	; 800C5E6C
800C5E6C	addiu  s4, s4, $0010
800C5E70	lhu    v0, $002c(s7)
800C5E74	addiu  s6, s6, $0001
800C5E78	slt    v0, s6, v0
800C5E7C	bne    v0, zero, loopc5d4c [$800c5d4c]
800C5E80	addiu  fp, fp, $0010

Lc5e84:	; 800C5E84
800C5E84	lui    a0, $800a
800C5E88	addiu  a0, a0, $763c
800C5E8C	lhu    a1, $0030(s7)
800C5E90	jal    func15c38 [$80015c38]
800C5E94	addu   s6, zero, zero
800C5E98	lui    a0, $800a
800C5E9C	lhu    a1, $0032(s7)
800C5EA0	jal    func15c38 [$80015c38]
800C5EA4	addiu  a0, a0, $7650
800C5EA8	lhu    v0, $0032(s7)
800C5EAC	lhu    v1, $0030(s7)
800C5EB0	nop
800C5EB4	beq    v1, zero, Lc5fc0 [$800c5fc0]
800C5EB8	addu   s2, s7, v0
800C5EBC	lui    s4, $800a
800C5EC0	addiu  s1, s2, $001c

loopc5ec4:	; 800C5EC4
800C5EC4	lui    a0, $800a
800C5EC8	addiu  a0, a0, $7664
800C5ECC	addu   a1, s6, zero
800C5ED0	lhu    a2, $0000(s2)
800C5ED4	jal    func15c38 [$80015c38]
800C5ED8	addu   s3, zero, zero
800C5EDC	lui    a0, $800a
800C5EE0	lhu    a1, $ffe6(s1)
800C5EE4	jal    func15c38 [$80015c38]
800C5EE8	addiu  a0, a0, $767c
800C5EEC	lui    a0, $800a
800C5EF0	lh     a1, $ffe8(s1)
800C5EF4	lh     a2, $ffea(s1)
800C5EF8	lh     a3, $ffec(s1)
800C5EFC	jal    func15c38 [$80015c38]
800C5F00	addiu  a0, a0, $7694
800C5F04	lui    a0, $800a
800C5F08	lh     a1, $ffee(s1)
800C5F0C	lh     a2, $fff0(s1)
800C5F10	lh     a3, $fff2(s1)
800C5F14	jal    func15c38 [$80015c38]
800C5F18	addiu  a0, a0, $76bc
800C5F1C	lui    a0, $800a
800C5F20	lh     a1, $fff4(s1)
800C5F24	lh     a2, $fff6(s1)
800C5F28	lh     a3, $fff8(s1)
800C5F2C	jal    func15c38 [$80015c38]
800C5F30	addiu  a0, a0, $76e4
800C5F34	lui    a0, $800a
800C5F38	lh     a1, $fffa(s1)
800C5F3C	lh     a2, $fffc(s1)
800C5F40	lh     a3, $fffe(s1)
800C5F44	jal    func15c38 [$80015c38]
800C5F48	addiu  a0, a0, $770c
800C5F4C	lui    a0, $800a
800C5F50	lhu    a1, $0000(s1)
800C5F54	jal    func15c38 [$80015c38]
800C5F58	addiu  a0, a0, $7734
800C5F5C	lui    a0, $800a
800C5F60	lhu    a1, $0002(s1)
800C5F64	jal    func15c38 [$80015c38]
800C5F68	addiu  a0, a0, $7750
800C5F6C	lhu    v0, $0002(s1)
800C5F70	lhu    v1, $0000(s1)
800C5F74	nop
800C5F78	beq    v1, zero, Lc5fa8 [$800c5fa8]
800C5F7C	addu   s0, s7, v0
800C5F80	addiu  a0, s4, $7770

loopc5f84:	; 800C5F84
800C5F84	addu   a1, s3, zero
800C5F88	lw     a2, $0000(s0)
800C5F8C	jal    func15c38 [$80015c38]
800C5F90	addiu  s0, s0, $0004
800C5F94	lhu    v0, $0000(s1)
800C5F98	addiu  s3, s3, $0001
800C5F9C	slt    v0, s3, v0
800C5FA0	bne    v0, zero, loopc5f84 [$800c5f84]
800C5FA4	addiu  a0, s4, $7770

Lc5fa8:	; 800C5FA8
800C5FA8	addiu  s1, s1, $0020
800C5FAC	lhu    v0, $0030(s7)
800C5FB0	addiu  s6, s6, $0001
800C5FB4	slt    v0, s6, v0
800C5FB8	bne    v0, zero, loopc5ec4 [$800c5ec4]
800C5FBC	addiu  s2, s2, $0020

Lc5fc0:	; 800C5FC0
800C5FC0	lui    a0, $800a
800C5FC4	addiu  a0, a0, $7790
800C5FC8	lhu    a1, $0038(s7)
800C5FCC	jal    func15c38 [$80015c38]
800C5FD0	addu   s6, zero, zero
800C5FD4	lui    a0, $800a
800C5FD8	lhu    a1, $003a(s7)
800C5FDC	jal    func15c38 [$80015c38]
800C5FE0	addiu  a0, a0, $77a4
800C5FE4	lhu    v0, $003a(s7)
800C5FE8	lhu    v1, $0038(s7)
800C5FEC	nop
800C5FF0	beq    v1, zero, Lc6038 [$800c6038]
800C5FF4	addu   s1, s7, v0
800C5FF8	lui    s2, $800a
800C5FFC	addiu  s0, s1, $0004

loopc6000:	; 800C6000
800C6000	addiu  a0, s2, $77bc
800C6004	addu   a1, s6, zero
800C6008	lh     a3, $fffe(s0)
800C600C	lh     v0, $0000(s0)
800C6010	addiu  s0, s0, $0006
800C6014	lh     a2, $0000(s1)
800C6018	addiu  s1, s1, $0006
800C601C	jal    func15c38 [$80015c38]
800C6020	sw     v0, $0010(sp)
800C6024	lhu    v0, $0038(s7)
800C6028	addiu  s6, s6, $0001
800C602C	slt    v0, s6, v0
800C6030	bne    v0, zero, loopc6000 [$800c6000]
800C6034	nop

Lc6038:	; 800C6038
800C6038	lui    a0, $800a
800C603C	addiu  a0, a0, $77d0
800C6040	lhu    a1, $0034(s7)
800C6044	jal    func15c38 [$80015c38]
800C6048	addu   s6, zero, zero
800C604C	lui    a0, $800a
800C6050	lhu    a1, $0036(s7)
800C6054	jal    func15c38 [$80015c38]
800C6058	addiu  a0, a0, $77e4
800C605C	lhu    v0, $0036(s7)
800C6060	lhu    v1, $0034(s7)
800C6064	nop
800C6068	beq    v1, zero, Lc60c0 [$800c60c0]
800C606C	addu   s1, s7, v0
800C6070	lui    s3, $800a
800C6074	lui    s2, $800a
800C6078	addiu  s0, s1, $000c

loopc607c:	; 800C607C
800C607C	addiu  a0, s3, $77fc
800C6080	addu   a1, s6, zero
800C6084	lw     v0, $fffc(s0)
800C6088	addiu  s6, s6, $0001
800C608C	sw     v0, $0010(sp)
800C6090	lw     a2, $0000(s1)
800C6094	lw     a3, $fff8(s0)
800C6098	jal    func15c38 [$80015c38]
800C609C	addiu  s1, s1, $0010
800C60A0	lw     a1, $0000(s0)
800C60A4	jal    func15c38 [$80015c38]
800C60A8	addiu  a0, s2, $7814
800C60AC	lhu    v0, $0034(s7)
800C60B0	nop
800C60B4	slt    v0, s6, v0
800C60B8	bne    v0, zero, loopc607c [$800c607c]
800C60BC	addiu  s0, s0, $0010

Lc60c0:	; 800C60C0
800C60C0	lw     ra, $003c(sp)
800C60C4	lw     fp, $0038(sp)
800C60C8	lw     s7, $0034(sp)
800C60CC	lw     s6, $0030(sp)
800C60D0	lw     s5, $002c(sp)
800C60D4	lw     s4, $0028(sp)
800C60D8	lw     s3, $0024(sp)
800C60DC	lw     s2, $0020(sp)
800C60E0	lw     s1, $001c(sp)
800C60E4	lw     s0, $0018(sp)
800C60E8	jr     ra 
800C60EC	addiu  sp, sp, $0040


funcc60f0:	; 800C60F0
800C60F0	addiu  sp, sp, $ffb8 (=-$48)
800C60F4	lui    v0, $800d
800C60F8	addiu  v0, v0, $9df0 (=-$6210)
800C60FC	sw     ra, $0044(sp)
800C6100	sw     fp, $0040(sp)
800C6104	sw     s7, $003c(sp)
800C6108	sw     s6, $0038(sp)
800C610C	sw     s5, $0034(sp)
800C6110	sw     s4, $0030(sp)
800C6114	sw     s3, $002c(sp)
800C6118	sw     s2, $0028(sp)
800C611C	sw     s1, $0024(sp)
800C6120	sw     s0, $0020(sp)
800C6124	lw     s5, $0008(v0)
800C6128	lw     s3, $0020(v0)
800C612C	lhu    t2, $002c(s5)
800C6130	nop
800C6134	sh     t2, $0018(sp)
800C6138	lw     fp, $0010(v0)
800C613C	beq    t2, zero, Lc63d4 [$800c63d4]
800C6140	addu   s7, zero, zero
800C6144	addiu  s2, s3, $0008

Lc6148:	; 800C6148
800C6148	lhu    v1, $0000(s3)
800C614C	nop
800C6150	andi   v0, v1, $0001
800C6154	beq    v0, zero, Lc63b8 [$800c63b8]
800C6158	andi   v0, v1, $000c
800C615C	beq    v0, zero, Lc63b8 [$800c63b8]
800C6160	addiu  t0, zero, $ffff (=-$1)
800C6164	addu   s0, zero, zero
800C6168	lw     v0, $0004(s2)
800C616C	lhu    v1, $fffa(s2)
800C6170	nop
800C6174	beq    v1, zero, Lc620c [$800c620c]
800C6178	addu   s4, s5, v0
800C617C	addu   t1, v1, zero
800C6180	addu   a2, zero, zero

loopc6184:	; 800C6184
800C6184	andi   v0, s0, $ffff
800C6188	sll    v0, v0, $03
800C618C	addu   v0, v0, s4
800C6190	addu   t2, zero, zero
800C6194	lhu    v1, $0006(v0)
800C6198	lhu    a0, $0004(v0)
800C619C	nop
800C61A0	sltu   v0, t2, a0
800C61A4	beq    v0, zero, Lc61f8 [$800c61f8]
800C61A8	addu   a1, s5, v1
800C61AC	addu   a3, a0, zero

loopc61b0:	; 800C61B0
800C61B0	lw     v0, $0000(a1)
800C61B4	nop
800C61B8	sll    v1, v0, $02
800C61BC	addu   v1, v1, v0
800C61C0	sll    v1, v1, $03
800C61C4	addu   v1, v1, fp
800C61C8	lhu    a0, $0000(v1)
800C61CC	nop
800C61D0	andi   v0, a0, $0001
800C61D4	beq    v0, zero, Lc61e0 [$800c61e0]
800C61D8	andi   v0, a0, $fffe
800C61DC	addu   t0, s0, zero

Lc61e0:	; 800C61E0
800C61E0	sh     v0, $0000(v1)
800C61E4	addiu  a2, a2, $0001
800C61E8	andi   v0, a2, $ffff
800C61EC	sltu   v0, v0, a3
800C61F0	bne    v0, zero, loopc61b0 [$800c61b0]
800C61F4	addiu  a1, a1, $0004

Lc61f8:	; 800C61F8
800C61F8	addiu  s0, s0, $0001
800C61FC	andi   v0, s0, $ffff
800C6200	sltu   v0, v0, t1
800C6204	bne    v0, zero, loopc6184 [$800c6184]
800C6208	addu   a2, zero, zero

Lc620c:	; 800C620C
800C620C	lw     s6, $0000(s2)
800C6210	addu   a2, zero, zero
800C6214	srl    s0, s6, $08
800C6218	andi   v0, s0, $ffff
800C621C	sll    v0, v0, $03
800C6220	addu   v0, v0, s4
800C6224	lhu    v1, $0006(v0)
800C6228	lhu    a0, $0004(v0)
800C622C	nop
800C6230	beq    a0, zero, Lc6270 [$800c6270]
800C6234	addu   a1, s5, v1

loopc6238:	; 800C6238
800C6238	lw     v1, $0000(a1)
800C623C	nop
800C6240	sll    v0, v1, $02
800C6244	addu   v0, v0, v1
800C6248	sll    v0, v0, $03
800C624C	addu   v0, v0, fp
800C6250	lhu    v1, $0000(v0)
800C6254	addiu  a2, a2, $0001
800C6258	ori    v1, v1, $0001
800C625C	sh     v1, $0000(v0)
800C6260	andi   v0, a2, $ffff
800C6264	sltu   v0, v0, a0
800C6268	bne    v0, zero, loopc6238 [$800c6238]
800C626C	addiu  a1, a1, $0004

Lc6270:	; 800C6270
800C6270	sll    v0, t0, $10
800C6274	sra    a3, v0, $10
800C6278	andi   s1, s0, $ffff
800C627C	beq    a3, s1, Lc62ac [$800c62ac]
800C6280	addu   a0, s5, zero
800C6284	sw     s1, $0010(sp)
800C6288	addu   a1, s3, zero
800C628C	sll    s0, s1, $03
800C6290	addu   s0, s4, s0
800C6294	jal    funcc6c04 [$800c6c04]
800C6298	addu   a2, s0, zero
800C629C	addu   a0, s5, zero
800C62A0	addu   a1, s3, zero
800C62A4	jal    funcc6da4 [$800c6da4]
800C62A8	addu   a2, s0, zero

Lc62ac:	; 800C62AC
800C62AC	sll    v0, s1, $03
800C62B0	addu   s0, v0, s4
800C62B4	lh     v0, $0002(s0)
800C62B8	nop
800C62BC	bgez   v0, Lc62e0 [$800c62e0]
800C62C0	addiu  v0, zero, $0001
800C62C4	sh     zero, $0002(s0)
800C62C8	sh     zero, $fffe(s2)
800C62CC	lhu    v1, $0000(s3)
800C62D0	nop
800C62D4	andi   v1, v1, $fffb
800C62D8	j      Lc63d8 [$800c63d8]
800C62DC	sh     v1, $0000(s3)

Lc62e0:	; 800C62E0
800C62E0	lhu    v0, $fffe(s2)
800C62E4	nop
800C62E8	addiu  v0, v0, $0001
800C62EC	sh     v0, $fffe(s2)
800C62F0	lh     v1, $0002(s0)
800C62F4	andi   v0, v0, $ffff
800C62F8	slt    v0, v0, v1
800C62FC	bne    v0, zero, Lc63b8 [$800c63b8]
800C6300	nop
800C6304	lh     v0, $fffc(s2)
800C6308	lhu    a1, $fffa(s2)
800C630C	sh     zero, $fffe(s2)
800C6310	addu   v0, s6, v0
800C6314	sra    v1, v0, $08
800C6318	sw     v0, $0000(s2)
800C631C	slt    v0, v1, a1
800C6320	bne    v0, zero, Lc635c [$800c635c]
800C6324	nop
800C6328	lhu    v0, $0000(s3)
800C632C	nop
800C6330	andi   v0, v0, $0010
800C6334	beq    v0, zero, Lc6354 [$800c6354]
800C6338	andi   a0, s7, $ffff
800C633C	addiu  v0, a1, $ffff (=-$1)
800C6340	sll    v0, v0, $08
800C6344	lhu    a1, $fffc(s2)
800C6348	ori    v0, v0, $00ff
800C634C	j      Lc6380 [$800c6380]
800C6350	sw     v0, $0000(s2)

Lc6354:	; 800C6354
800C6354	j      Lc63a8 [$800c63a8]
800C6358	sw     zero, $0000(s2)

Lc635c:	; 800C635C
800C635C	bgez   v1, Lc63b8 [$800c63b8]
800C6360	nop
800C6364	lhu    v0, $0000(s3)
800C6368	nop
800C636C	andi   v0, v0, $0010
800C6370	beq    v0, zero, Lc6398 [$800c6398]
800C6374	andi   a0, s7, $ffff
800C6378	lhu    a1, $fffc(s2)
800C637C	sw     zero, $0000(s2)

Lc6380:	; 800C6380
800C6380	subu   a1, zero, a1
800C6384	sll    a1, a1, $10
800C6388	jal    funcc7bc4 [$800c7bc4]
800C638C	sra    a1, a1, $10
800C6390	j      Lc63a8 [$800c63a8]
800C6394	nop

Lc6398:	; 800C6398
800C6398	addiu  v0, a1, $ffff (=-$1)
800C639C	sll    v0, v0, $08
800C63A0	ori    v0, v0, $00ff
800C63A4	sw     v0, $0000(s2)

Lc63a8:	; 800C63A8
800C63A8	lhu    v0, $0000(s3)
800C63AC	nop
800C63B0	andi   v0, v0, $fffb
800C63B4	sh     v0, $0000(s3)

Lc63b8:	; 800C63B8
800C63B8	addiu  s2, s2, $0010
800C63BC	addiu  s7, s7, $0001
800C63C0	lhu    v1, $0018(sp)
800C63C4	andi   v0, s7, $ffff
800C63C8	sltu   v0, v0, v1
800C63CC	bne    v0, zero, Lc6148 [$800c6148]
800C63D0	addiu  s3, s3, $0010

Lc63d4:	; 800C63D4
800C63D4	addiu  v0, zero, $0001

Lc63d8:	; 800C63D8
800C63D8	lw     ra, $0044(sp)
800C63DC	lw     fp, $0040(sp)
800C63E0	lw     s7, $003c(sp)
800C63E4	lw     s6, $0038(sp)
800C63E8	lw     s5, $0034(sp)
800C63EC	lw     s4, $0030(sp)
800C63F0	lw     s3, $002c(sp)
800C63F4	lw     s2, $0028(sp)
800C63F8	lw     s1, $0024(sp)
800C63FC	lw     s0, $0020(sp)
800C6400	jr     ra 
800C6404	addiu  sp, sp, $0048


funcc6408:	; 800C6408
800C6408	addiu  sp, sp, $ffd0 (=-$30)
800C640C	sw     s3, $0024(sp)
800C6410	addu   s3, a1, zero
800C6414	lui    v0, $800d
800C6418	addiu  a1, v0, $9df0 (=-$6210)
800C641C	sw     ra, $0028(sp)
800C6420	sw     s2, $0020(sp)
800C6424	sw     s1, $001c(sp)
800C6428	sw     s0, $0018(sp)
800C642C	lw     s2, $0008(a1)
800C6430	nop
800C6434	lhu    v0, $002c(s2)
800C6438	nop
800C643C	sltu   v0, a0, v0
800C6440	beq    v0, zero, Lc6468 [$800c6468]
800C6444	sll    v1, a0, $04
800C6448	lw     v0, $0020(a1)
800C644C	nop
800C6450	addu   s1, v0, v1
800C6454	lhu    v1, $0002(s1)
800C6458	nop
800C645C	sltu   v0, s3, v1
800C6460	bne    v0, zero, Lc6470 [$800c6470]
800C6464	addiu  t1, zero, $ffff (=-$1)

Lc6468:	; 800C6468
800C6468	j      Lc65b0 [$800c65b0]
800C646C	addu   v0, zero, zero

Lc6470:	; 800C6470
800C6470	lw     v0, $000c(s1)
800C6474	addu   t0, zero, zero
800C6478	beq    v1, zero, Lc6508 [$800c6508]
800C647C	addu   s0, s2, v0
800C6480	addu   t2, a1, zero
800C6484	addiu  a2, s0, $0004

loopc6488:	; 800C6488
800C6488	addu   a3, zero, zero
800C648C	lhu    v0, $0002(a2)
800C6490	lhu    v1, $0000(a2)
800C6494	nop
800C6498	beq    v1, zero, Lc64ec [$800c64ec]
800C649C	addu   a1, s2, v0

loopc64a0:	; 800C64A0
800C64A0	lw     v1, $0000(a1)
800C64A4	nop
800C64A8	sll    v0, v1, $02
800C64AC	addu   v0, v0, v1
800C64B0	lw     v1, $0010(t2)
800C64B4	sll    v0, v0, $03
800C64B8	addu   v1, v1, v0
800C64BC	lhu    a0, $0000(v1)
800C64C0	nop
800C64C4	andi   v0, a0, $0001
800C64C8	beq    v0, zero, Lc64d4 [$800c64d4]
800C64CC	andi   v0, a0, $fffe
800C64D0	addu   t1, t0, zero

Lc64d4:	; 800C64D4
800C64D4	sh     v0, $0000(v1)
800C64D8	lhu    v0, $0000(a2)
800C64DC	addiu  a3, a3, $0001
800C64E0	slt    v0, a3, v0
800C64E4	bne    v0, zero, loopc64a0 [$800c64a0]
800C64E8	addiu  a1, a1, $0004

Lc64ec:	; 800C64EC
800C64EC	lhu    v0, $0002(s1)
800C64F0	addiu  t0, t0, $0001
800C64F4	slt    v0, t0, v0
800C64F8	bne    v0, zero, loopc6488 [$800c6488]
800C64FC	addiu  a2, a2, $0008
800C6500	lw     v0, $000c(s1)
800C6504	addu   t0, zero, zero

Lc6508:	; 800C6508
800C6508	addu   s0, s2, v0
800C650C	sll    v0, s3, $03
800C6510	addu   s0, s0, v0
800C6514	lhu    v0, $0006(s0)
800C6518	lhu    v1, $0004(s0)
800C651C	nop
800C6520	beq    v1, zero, Lc6570 [$800c6570]
800C6524	addu   a1, s2, v0

funcc6528:	; 800C6528
800C6528	lui    v0, $800d
800C652C	addiu  a0, v0, $9df0 (=-$6210)

loopc6530:	; 800C6530
800C6530	lw     v1, $0000(a1)
800C6534	nop
800C6538	sll    v0, v1, $02
800C653C	addu   v0, v0, v1
800C6540	lw     v1, $0010(a0)
800C6544	sll    v0, v0, $03
800C6548	addu   v1, v1, v0
800C654C	lhu    v0, $0000(v1)
800C6550	nop
800C6554	ori    v0, v0, $0001
800C6558	sh     v0, $0000(v1)
800C655C	lhu    v0, $0004(s0)
800C6560	addiu  t0, t0, $0001
800C6564	slt    v0, t0, v0
800C6568	bne    v0, zero, loopc6530 [$800c6530]
800C656C	addiu  a1, a1, $0004

Lc6570:	; 800C6570
800C6570	sll    v0, t1, $10
800C6574	sra    a3, v0, $10
800C6578	beq    s3, a3, Lc65a4 [$800c65a4]
800C657C	andi   v0, s3, $ffff
800C6580	sw     v0, $0010(sp)
800C6584	addu   a0, s2, zero
800C6588	addu   a1, s1, zero
800C658C	jal    funcc6c04 [$800c6c04]
800C6590	addu   a2, s0, zero
800C6594	addu   a0, s2, zero
800C6598	addu   a1, s1, zero
800C659C	jal    funcc6da4 [$800c6da4]
800C65A0	addu   a2, s0, zero

Lc65a4:	; 800C65A4
800C65A4	sll    v0, s3, $08
800C65A8	sw     v0, $0008(s1)
800C65AC	addiu  v0, zero, $0001

Lc65b0:	; 800C65B0
800C65B0	lw     ra, $0028(sp)
800C65B4	lw     s3, $0024(sp)
800C65B8	lw     s2, $0020(sp)
800C65BC	lw     s1, $001c(sp)
800C65C0	lw     s0, $0018(sp)
800C65C4	jr     ra 
800C65C8	addiu  sp, sp, $0030


funcc65cc:	; 800C65CC
800C65CC	addiu  sp, sp, $ff88 (=-$78)
800C65D0	sw     s2, $0060(sp)
800C65D4	addu   s2, a3, zero
800C65D8	lui    v0, $800d
800C65DC	sw     s5, $006c(sp)
800C65E0	addiu  s5, v0, $9df0 (=-$6210)
800C65E4	sw     ra, $0074(sp)
800C65E8	sw     s6, $0070(sp)
800C65EC	sw     s4, $0068(sp)

Lc65f0:	; 800C65F0
800C65F0	sw     s3, $0064(sp)
800C65F4	sw     s1, $005c(sp)
800C65F8	sw     s0, $0058(sp)
800C65FC	lh     v0, $0004(a2)
800C6600	lw     s1, $001c(s5)
800C6604	lhu    a3, $0008(a0)
800C6608	sll    v0, v0, $05
800C660C	addu   t7, s1, v0
800C6610	lhu    v0, $000a(t7)
800C6614	nop
800C6618	addu   a3, a3, v0
800C661C	sh     a3, $0010(sp)
800C6620	lhu    t1, $000a(a0)
800C6624	lhu    v0, $000c(t7)
800C6628	nop
800C662C	addu   t1, t1, v0
800C6630	sh     t1, $0012(sp)
800C6634	lhu    t4, $000c(a0)
800C6638	lhu    v0, $000e(t7)
800C663C	nop
800C6640	addu   t4, t4, v0
800C6644	sh     t4, $0014(sp)
800C6648	lhu    t0, $003a(a0)
800C664C	lh     v1, $000c(a2)
800C6650	addu   t0, a0, t0
800C6654	sll    v0, v1, $01
800C6658	addu   v0, v0, v1
800C665C	sll    v0, v0, $01
800C6660	addu   v0, v0, t0
800C6664	lhu    t6, $0000(v0)
800C6668	nop
800C666C	sh     t6, $0018(sp)
800C6670	lh     v1, $000e(a2)
800C6674	nop
800C6678	sll    v0, v1, $01
800C667C	addu   v0, v0, v1
800C6680	sll    v0, v0, $01
800C6684	addu   v0, v0, t0
800C6688	lhu    t2, $0000(v0)
800C668C	nop
800C6690	sh     t2, $0020(sp)
800C6694	lh     v1, $0010(a2)
800C6698	nop
800C669C	sll    v0, v1, $01
800C66A0	addu   v0, v0, v1
800C66A4	sll    v0, v0, $01
800C66A8	addu   v0, v0, t0
800C66AC	lhu    t5, $0000(v0)
800C66B0	addu   s4, a1, zero
800C66B4	sh     t5, $0028(sp)
800C66B8	lw     v0, $0024(s4)
800C66BC	nop
800C66C0	lhu    a1, $0014(v0)
800C66C4	nop
800C66C8	subu   a1, a1, a3
800C66CC	sh     a1, $0030(sp)
800C66D0	lh     v1, $000c(a2)
800C66D4	nop
800C66D8	sll    v0, v1, $01
800C66DC	addu   v0, v0, v1
800C66E0	sll    v0, v0, $01
800C66E4	addu   v0, v0, t0
800C66E8	lhu    v0, $0002(v0)
800C66EC	nop
800C66F0	sh     v0, $001a(sp)
800C66F4	lh     v1, $000e(a2)
800C66F8	nop
800C66FC	sll    v0, v1, $01
800C6700	addu   v0, v0, v1
800C6704	sll    v0, v0, $01
800C6708	addu   v0, v0, t0
800C670C	lhu    v0, $0002(v0)
800C6710	nop
800C6714	sh     v0, $0022(sp)
800C6718	lh     v1, $0010(a2)
800C671C	nop
800C6720	sll    v0, v1, $01
800C6724	addu   v0, v0, v1
800C6728	sll    v0, v0, $01
800C672C	addu   v0, v0, t0
800C6730	lhu    v0, $0002(v0)
800C6734	nop
800C6738	sh     v0, $002a(sp)
800C673C	lw     v0, $0024(s4)
800C6740	nop
800C6744	lhu    v0, $0018(v0)
800C6748	nop
800C674C	subu   v0, v0, t1
800C6750	sh     v0, $0032(sp)
800C6754	lh     v1, $000c(a2)
800C6758	nop
800C675C	sll    v0, v1, $01
800C6760	addu   v0, v0, v1
800C6764	sll    v0, v0, $01
800C6768	addu   v0, v0, t0
800C676C	lhu    t1, $0004(v0)
800C6770	sll    t2, t2, $10
800C6774	sh     t1, $001c(sp)
800C6778	lh     v1, $000e(a2)
800C677C	sra    t2, t2, $10
800C6780	sll    v0, v1, $01
800C6784	addu   v0, v0, v1
800C6788	sll    v0, v0, $01
800C678C	addu   v0, v0, t0
800C6790	lhu    a3, $0004(v0)
800C6794	sll    a1, a1, $10
800C6798	sh     a3, $0024(sp)
800C679C	lh     v1, $0010(a2)
800C67A0	sra    a1, a1, $10
800C67A4	sll    v0, v1, $01
800C67A8	addu   v0, v0, v1
800C67AC	sll    v0, v0, $01
800C67B0	addu   v0, v0, t0
800C67B4	lhu    v1, $0004(v0)
800C67B8	subu   s0, t2, a1
800C67BC	sh     v1, $002c(sp)
800C67C0	lw     v0, $0024(s4)
800C67C4	sll    v1, v1, $10
800C67C8	lhu    t3, $001c(v0)
800C67CC	sra    v1, v1, $10
800C67D0	subu   t3, t3, t4
800C67D4	sll    v0, t3, $10
800C67D8	sra    v0, v0, $10
800C67DC	subu   t7, v1, v0
800C67E0	mult   s0, t7
800C67E4	sll    t5, t5, $10
800C67E8	sra    t5, t5, $10
800C67EC	sll    a3, a3, $10
800C67F0	sra    a3, a3, $10
800C67F4	mflo   s3
800C67F8	subu   a2, t5, a1
800C67FC	subu   t4, a3, v0
800C6800	mult   a2, t4
800C6804	sll    t1, t1, $10
800C6808	mflo   t9
800C680C	sra    t1, t1, $10
800C6810	subu   v0, t1, v0
800C6814	mult   a2, v0
800C6818	sll    t6, t6, $10
800C681C	mflo   t8
800C6820	sra    t6, t6, $10
800C6824	subu   a1, t6, a1
800C6828	mult   a1, t7
800C682C	mflo   t7
800C6830	nop
800C6834	nop
800C6838	mult   a1, t4
800C683C	mflo   a1
800C6840	nop
800C6844	nop
800C6848	mult   s0, v0
800C684C	subu   t2, t2, t6
800C6850	subu   v1, v1, t1
800C6854	sh     t3, $0034(sp)
800C6858	subu   a2, s3, t9
800C685C	sw     a2, $0038(sp)
800C6860	subu   t3, t8, t7
800C6864	mflo   v0
800C6868	sw     t3, $003c(sp)
800C686C	subu   t4, a1, v0
800C6870	mult   t2, v1
800C6874	sw     t4, $0040(sp)
800C6878	lh     v0, $0004(s2)
800C687C	lhu    a1, $0008(a0)
800C6880	sll    v0, v0, $05
800C6884	addu   t7, s1, v0
800C6888	lhu    v0, $000a(t7)
800C688C	subu   t5, t5, t6
800C6890	addu   a1, a1, v0
800C6894	sh     a1, $0010(sp)
800C6898	lhu    v0, $000a(a0)
800C689C	lhu    v1, $000c(t7)
800C68A0	subu   a3, a3, t1
800C68A4	addu   v0, v0, v1
800C68A8	mflo   t2
800C68AC	sh     v0, $0012(sp)
800C68B0	lhu    v0, $000c(a0)
800C68B4	mult   t5, a3
800C68B8	lhu    v1, $000e(t7)
800C68BC	nop
800C68C0	addu   v0, v0, v1

Lc68c4:	; 800C68C4
800C68C4	sh     v0, $0014(sp)
800C68C8	lh     v1, $000c(s2)
800C68CC	nop
800C68D0	sll    v0, v1, $01
800C68D4	addu   v0, v0, v1
800C68D8	sll    v0, v0, $01
800C68DC	addu   v0, v0, t0
800C68E0	lhu    v1, $0000(v0)

Lc68e4:	; 800C68E4
800C68E4	mflo   t1
800C68E8	sll    v0, v1, $10
800C68EC	sra    v0, v0, $10
800C68F0	mult   a2, v0
800C68F4	sh     v1, $0018(sp)
800C68F8	lh     v1, $000e(s2)
800C68FC	nop
800C6900	sll    v0, v1, $01
800C6904	addu   v0, v0, v1
800C6908	sll    v0, v0, $01
800C690C	addu   v0, v0, t0
800C6910	lhu    v1, $0000(v0)
800C6914	mflo   a3
800C6918	sll    v0, v1, $10
800C691C	sra    v0, v0, $10
800C6920	mult   t3, v0
800C6924	sh     v1, $0020(sp)
800C6928	lh     v1, $0010(s2)
800C692C	nop
800C6930	sll    v0, v1, $01
800C6934	addu   v0, v0, v1
800C6938	sll    v0, v0, $01
800C693C	addu   v0, v0, t0
800C6940	lhu    v1, $0000(v0)
800C6944	mflo   a0
800C6948	sll    v0, v1, $10
800C694C	sra    v0, v0, $10
800C6950	mult   t4, v0
800C6954	sh     v1, $0028(sp)
800C6958	lh     v1, $000c(s2)
800C695C	subu   t2, t2, t1
800C6960	sll    v0, v1, $01
800C6964	mflo   t5
800C6968	addu   a0, a3, a0
800C696C	addu   a0, a0, t5
800C6970	div    a0, t2
800C6974	bne    t2, zero, Lc6980 [$800c6980]
800C6978	nop
800C697C	break   $01c00

Lc6980:	; 800C6980
800C6980	addiu  at, zero, $ffff (=-$1)
800C6984	bne    t2, at, Lc6998 [$800c6998]
800C6988	lui    at, $8000
800C698C	bne    a0, at, Lc6998 [$800c6998]
800C6990	nop
800C6994	break   $01800

Lc6998:	; 800C6998
800C6998	mflo   a0
800C699C	addu   v0, v0, v1
800C69A0	sll    v0, v0, $01
800C69A4	addu   v0, v0, t0
800C69A8	lhu    v0, $0002(v0)
800C69AC	nop
800C69B0	sh     v0, $001a(sp)
800C69B4	lh     v1, $000e(s2)
800C69B8	nop
800C69BC	sll    v0, v1, $01
800C69C0	addu   v0, v0, v1
800C69C4	sll    v0, v0, $01
800C69C8	addu   v0, v0, t0
800C69CC	lhu    v0, $0002(v0)
800C69D0	nop
800C69D4	sh     v0, $0022(sp)
800C69D8	lh     v1, $0010(s2)
800C69DC	nop
800C69E0	sll    v0, v1, $01
800C69E4	addu   v0, v0, v1
800C69E8	sll    v0, v0, $01
800C69EC	addu   v0, v0, t0
800C69F0	lhu    v0, $0002(v0)
800C69F4	nop
800C69F8	sh     v0, $002a(sp)
800C69FC	lh     v1, $000c(s2)
800C6A00	nop
800C6A04	sll    v0, v1, $01
800C6A08	addu   v0, v0, v1
800C6A0C	sll    v0, v0, $01
800C6A10	addu   v0, v0, t0
800C6A14	lhu    v1, $0004(v0)
800C6A18	nop
800C6A1C	sll    v0, v1, $10
800C6A20	sra    v0, v0, $10
800C6A24	mult   a2, v0
800C6A28	sh     v1, $001c(sp)
800C6A2C	lh     v1, $000e(s2)
800C6A30	nop
800C6A34	sll    v0, v1, $01
800C6A38	addu   v0, v0, v1
800C6A3C	sll    v0, v0, $01
800C6A40	addu   v0, v0, t0
800C6A44	lhu    v1, $0004(v0)
800C6A48	mflo   a3
800C6A4C	sll    v0, v1, $10
800C6A50	sra    v0, v0, $10
800C6A54	mult   t3, v0
800C6A58	sh     v1, $0024(sp)
800C6A5C	lh     v1, $0010(s2)
800C6A60	nop
800C6A64	sll    v0, v1, $01
800C6A68	addu   v0, v0, v1
800C6A6C	sll    v0, v0, $01
800C6A70	addu   v0, v0, t0
800C6A74	lhu    v1, $0004(v0)
800C6A78	mflo   a2
800C6A7C	sll    v0, v1, $10
800C6A80	sra    v0, v0, $10
800C6A84	mult   t4, v0
800C6A88	mflo   t0
800C6A8C	addu   v0, a3, a2
800C6A90	addu   v0, v0, t0
800C6A94	div    v0, t2
800C6A98	bne    t2, zero, Lc6aa4 [$800c6aa4]
800C6A9C	nop
800C6AA0	break   $01c00

Lc6aa4:	; 800C6AA4
800C6AA4	addiu  at, zero, $ffff (=-$1)
800C6AA8	bne    t2, at, Lc6abc [$800c6abc]
800C6AAC	lui    at, $8000
800C6AB0	bne    v0, at, Lc6abc [$800c6abc]
800C6AB4	nop
800C6AB8	break   $01800

Lc6abc:	; 800C6ABC
800C6ABC	mflo   v0
800C6AC0	sll    a1, a1, $10
800C6AC4	sra    a1, a1, $10
800C6AC8	sh     v1, $002c(sp)
800C6ACC	sw     a0, $0048(sp)
800C6AD0	sw     v0, $0050(sp)
800C6AD4	lw     v0, $0024(s4)
800C6AD8	addu   a0, a0, a1
800C6ADC	sw     a0, $0014(v0)
800C6AE0	lh     a0, $0014(sp)
800C6AE4	lw     v0, $0050(sp)
800C6AE8	lw     v1, $0024(s4)
800C6AEC	addu   v0, v0, a0
800C6AF0	sw     v0, $001c(v1)
800C6AF4	lh     v1, $0006(s2)
800C6AF8	nop
800C6AFC	bltz   v1, Lc6b88 [$800c6b88]
800C6B00	sll    v1, v1, $04
800C6B04	lw     s0, $0014(s5)
800C6B08	lw     v0, $0024(s4)
800C6B0C	addu   s0, s0, v1
800C6B10	lw     a1, $0014(v0)
800C6B14	lw     a0, $0000(s0)
800C6B18	jal    funcc1dc4 [$800c1dc4]
800C6B1C	sll    a1, a1, $10
800C6B20	lw     v1, $0024(s4)
800C6B24	addu   s1, v0, zero
800C6B28	lw     a1, $001c(v1)
800C6B2C	lw     a0, $0008(s0)
800C6B30	jal    funcc1dc4 [$800c1dc4]
800C6B34	sll    a1, a1, $10
800C6B38	lw     a0, $0024(s2)
800C6B3C	lw     a1, $000c(s0)
800C6B40	subu   a0, a0, s1
800C6B44	jal    funcc1dc4 [$800c1dc4]
800C6B48	subu   a0, a0, v0
800C6B4C	lw     v1, $0024(s4)
800C6B50	sra    v0, v0, $10
800C6B54	sw     v0, $0018(v1)
800C6B58	lh     v0, $0004(s2)
800C6B5C	lw     v1, $001c(s5)
800C6B60	lw     a1, $0024(s4)
800C6B64	sll    v0, v0, $05
800C6B68	addu   v0, v0, v1
800C6B6C	lh     v1, $000c(v0)
800C6B70	lh     a0, $0006(v0)
800C6B74	lw     v0, $0018(a1)
800C6B78	subu   v1, v1, a0
800C6B7C	addu   v0, v0, v1
800C6B80	j      Lc6bd8 [$800c6bd8]
800C6B84	sw     v0, $0018(a1)

Lc6b88:	; 800C6B88
800C6B88	lh     v0, $0004(s2)
800C6B8C	lw     a1, $001c(s5)
800C6B90	lh     v1, $000c(s2)
800C6B94	lw     a0, $000c(s5)
800C6B98	sll    v0, v0, $05
800C6B9C	addu   a1, a1, v0
800C6BA0	sll    v0, v1, $01
800C6BA4	addu   v0, v0, v1
800C6BA8	sll    v0, v0, $01
800C6BAC	addu   a0, a0, v0
800C6BB0	lw     v1, $0008(s5)
800C6BB4	lhu    a1, $000c(a1)
800C6BB8	lhu    v1, $000a(v1)
800C6BBC	lhu    v0, $0002(a0)
800C6BC0	addu   v1, v1, a1
800C6BC4	addu   v0, v0, v1
800C6BC8	sll    v0, v0, $10
800C6BCC	lw     v1, $0024(s4)
800C6BD0	sra    v0, v0, $10
800C6BD4	sw     v0, $0018(v1)

Lc6bd8:	; 800C6BD8
800C6BD8	lw     ra, $0074(sp)
800C6BDC	lw     s6, $0070(sp)
800C6BE0	lw     s5, $006c(sp)
800C6BE4	lw     s4, $0068(sp)
800C6BE8	lw     s3, $0064(sp)
800C6BEC	lw     s2, $0060(sp)
800C6BF0	lw     s1, $005c(sp)
800C6BF4	lw     s0, $0058(sp)
800C6BF8	addiu  v0, zero, $0001
800C6BFC	jr     ra 
800C6C00	addiu  sp, sp, $0078


funcc6c04:	; 800C6C04
800C6C04	addiu  sp, sp, $ffc0 (=-$40)
800C6C08	sw     fp, $0038(sp)
800C6C0C	addu   fp, a0, zero
800C6C10	sll    a3, a3, $10
800C6C14	sra    a3, a3, $10
800C6C18	addiu  v0, zero, $ffff (=-$1)
800C6C1C	sw     ra, $003c(sp)
800C6C20	sw     s7, $0034(sp)
800C6C24	sw     s6, $0030(sp)
800C6C28	sw     s5, $002c(sp)
800C6C2C	sw     s4, $0028(sp)
800C6C30	sw     s3, $0024(sp)
800C6C34	sw     s2, $0020(sp)
800C6C38	sw     s1, $001c(sp)
800C6C3C	bne    a3, v0, Lc6c4c [$800c6c4c]
800C6C40	sw     s0, $0018(sp)
800C6C44	j      Lc6d74 [$800c6d74]
800C6C48	addu   v0, zero, zero

Lc6c4c:	; 800C6C4C
800C6C4C	addu   s7, zero, zero
800C6C50	lui    v0, $800d
800C6C54	addiu  a0, v0, $9df0 (=-$6210)
800C6C58	lw     v0, $000c(a1)
800C6C5C	lw     s4, $0004(a0)
800C6C60	addu   s5, fp, v0
800C6C64	sll    v0, a3, $03
800C6C68	addu   s5, s5, v0
800C6C6C	lhu    v0, $0006(a2)
800C6C70	lhu    v1, $0002(a0)
800C6C74	addu   v0, fp, v0
800C6C78	beq    v1, zero, Lc6d70 [$800c6d70]
800C6C7C	sw     v0, $0010(sp)
800C6C80	addu   s6, a0, zero
800C6C84	addiu  s3, s4, $0004

loopc6c88:	; 800C6C88
800C6C88	lhu    v0, $0000(s4)
800C6C8C	nop
800C6C90	andi   v0, v0, $0001
800C6C94	beq    v0, zero, Lc6d54 [$800c6d54]
800C6C98	nop
800C6C9C	addu   s1, zero, zero
800C6CA0	lhu    v0, $0006(s5)
800C6CA4	lhu    v1, $0004(s5)
800C6CA8	nop
800C6CAC	beq    v1, zero, Lc6d54 [$800c6d54]
800C6CB0	addu   s2, fp, v0

loopc6cb4:	; 800C6CB4
800C6CB4	lh     v1, $0002(s3)
800C6CB8	lw     v0, $0000(s2)
800C6CBC	nop
800C6CC0	bne    v1, v0, Lc6d3c [$800c6d3c]
800C6CC4	sll    a2, v1, $02
800C6CC8	addu   a2, a2, v1
800C6CCC	andi   s0, s1, $ffff
800C6CD0	sll    s0, s0, $02
800C6CD4	sll    a2, a2, $03
800C6CD8	lw     t0, $0010(sp)
800C6CDC	addu   a0, fp, zero
800C6CE0	addu   s0, s0, t0
800C6CE4	lw     v0, $0000(s0)
800C6CE8	addu   a1, s4, zero
800C6CEC	sll    a3, v0, $02
800C6CF0	addu   a3, a3, v0
800C6CF4	lw     v0, $0010(s6)
800C6CF8	sll    a3, a3, $03
800C6CFC	addu   a2, v0, a2
800C6D00	jal    funcc65cc [$800c65cc]
800C6D04	addu   a3, v0, a3
800C6D08	lhu    v0, $0000(s0)
800C6D0C	nop
800C6D10	sh     v0, $0002(s3)
800C6D14	lw     v1, $0000(s0)
800C6D18	nop
800C6D1C	sll    v0, v1, $02
800C6D20	addu   v0, v0, v1
800C6D24	lw     v1, $0010(s6)
800C6D28	sll    v0, v0, $03

Lc6d2c:	; 800C6D2C
800C6D2C	addu   v0, v0, v1
800C6D30	lhu    v0, $0004(v0)
800C6D34	nop
800C6D38	sh     v0, $0000(s3)

Lc6d3c:	; 800C6D3C
800C6D3C	addiu  s1, s1, $0001
800C6D40	lhu    v1, $0004(s5)
800C6D44	andi   v0, s1, $ffff
800C6D48	sltu   v0, v0, v1
800C6D4C	bne    v0, zero, loopc6cb4 [$800c6cb4]
800C6D50	addiu  s2, s2, $0004

Lc6d54:	; 800C6D54
800C6D54	addiu  s3, s3, $0028
800C6D58	addiu  s7, s7, $0001
800C6D5C	lhu    v1, $0002(s6)
800C6D60	andi   v0, s7, $ffff
800C6D64	sltu   v0, v0, v1
800C6D68	bne    v0, zero, loopc6c88 [$800c6c88]
800C6D6C	addiu  s4, s4, $0028

Lc6d70:	; 800C6D70
800C6D70	addiu  v0, zero, $0001

Lc6d74:	; 800C6D74
800C6D74	lw     ra, $003c(sp)
800C6D78	lw     fp, $0038(sp)
800C6D7C	lw     s7, $0034(sp)
800C6D80	lw     s6, $0030(sp)
800C6D84	lw     s5, $002c(sp)
800C6D88	lw     s4, $0028(sp)
800C6D8C	lw     s3, $0024(sp)
800C6D90	lw     s2, $0020(sp)
800C6D94	lw     s1, $001c(sp)
800C6D98	lw     s0, $0018(sp)
800C6D9C	jr     ra 
800C6DA0	addiu  sp, sp, $0040


funcc6da4:	; 800C6DA4
800C6DA4	addu   t3, zero, zero
800C6DA8	lhu    v0, $0006(a2)
800C6DAC	lhu    v1, $0004(a2)
800C6DB0	nop
800C6DB4	beq    v1, zero, Lc6e8c [$800c6e8c]
800C6DB8	addu   a0, a0, v0
800C6DBC	lui    v0, $800d

Lc6dc0:	; 800C6DC0
800C6DC0	addiu  t2, v0, $9df0 (=-$6210)

loopc6dc4:	; 800C6DC4
800C6DC4	lw     v0, $0000(a0)
800C6DC8	addu   t0, zero, zero
800C6DCC	sll    v1, v0, $02
800C6DD0	addu   v1, v1, v0
800C6DD4	lw     v0, $0010(t2)
800C6DD8	sll    v1, v1, $03
800C6DDC	addu   t1, v0, v1
800C6DE0	andi   v0, t0, $ffff

loopc6de4:	; 800C6DE4
800C6DE4	sll    v0, v0, $01
800C6DE8	addu   a1, t1, v0
800C6DEC	lh     v1, $0018(a1)
800C6DF0	nop
800C6DF4	bltz   v1, Lc6e60 [$800c6e60]
800C6DF8	sll    v0, v1, $02
800C6DFC	addu   v0, v0, v1
800C6E00	lw     v1, $0010(t2)
800C6E04	sll    v0, v0, $03
800C6E08	addu   a3, v1, v0
800C6E0C	lh     v1, $0004(t1)
800C6E10	lh     v0, $0004(a3)
800C6E14	nop
800C6E18	beq    v1, v0, Lc6e60 [$800c6e60]
800C6E1C	nop
800C6E20	lh     v0, $0012(a1)
800C6E24	lw     v1, $0018(t2)
800C6E28	sll    v0, v0, $02
800C6E2C	addu   v1, v1, v0
800C6E30	lh     v0, $0002(v1)
800C6E34	lhu    v1, $0002(v1)
800C6E38	bltz   v0, Lc6e60 [$800c6e60]
800C6E3C	sll    v0, v1, $01
800C6E40	lhu    v1, $0000(a0)
800C6E44	addu   v0, a3, v0
800C6E48	sh     v1, $0018(v0)
800C6E4C	lh     v0, $0012(v0)
800C6E50	lw     v1, $0018(t2)
800C6E54	sll    v0, v0, $02
800C6E58	addu   v1, v1, v0
800C6E5C	sh     t0, $0002(v1)

Lc6e60:	; 800C6E60
800C6E60	addiu  t0, t0, $0001
800C6E64	andi   v0, t0, $ffff
800C6E68	sltiu  v0, v0, $0003
800C6E6C	bne    v0, zero, loopc6de4 [$800c6de4]
800C6E70	andi   v0, t0, $ffff
800C6E74	addiu  t3, t3, $0001
800C6E78	lhu    v1, $0004(a2)
800C6E7C	andi   v0, t3, $ffff
800C6E80	sltu   v0, v0, v1
800C6E84	bne    v0, zero, loopc6dc4 [$800c6dc4]
800C6E88	addiu  a0, a0, $0004

Lc6e8c:	; 800C6E8C
800C6E8C	jr     ra 
800C6E90	addiu  v0, zero, $0001


funcc6e94:	; 800C6E94
800C6E94	addu   a0, zero, zero
800C6E98	addiu  a2, zero, $0002
800C6E9C	addiu  a1, zero, $0100
800C6EA0	lui    v0, $800d
800C6EA4	addiu  v1, v0, $ae98 (=-$5168)

loopc6ea8:	; 800C6EA8
800C6EA8	sh     a2, $0000(v1)
800C6EAC	sh     zero, $0002(v1)
800C6EB0	sh     zero, $0004(v1)
800C6EB4	sh     zero, $0006(v1)
800C6EB8	sh     zero, $0010(v1)
800C6EBC	sw     zero, $0014(v1)
800C6EC0	sh     a1, $0012(v1)
800C6EC4	sh     zero, $0008(v1)
800C6EC8	sh     zero, $000a(v1)
800C6ECC	sh     zero, $000c(v1)
800C6ED0	sh     zero, $000e(v1)
800C6ED4	addiu  a0, a0, $0001
800C6ED8	slti   v0, a0, $001e
800C6EDC	bne    v0, zero, loopc6ea8 [$800c6ea8]
800C6EE0	addiu  v1, v1, $0018
800C6EE4	jr     ra 
800C6EE8	addiu  v0, zero, $0001


funcc6eec:	; 800C6EEC
800C6EEC	addiu  sp, sp, $ffe0 (=-$20)
800C6EF0	sll    v1, a0, $01
800C6EF4	addu   v1, v1, a0
800C6EF8	sll    v1, v1, $03
800C6EFC	lui    v0, $800d
800C6F00	addiu  v0, v0, $ae98 (=-$5168)
800C6F04	sw     s0, $0010(sp)
800C6F08	addu   s0, v1, v0
800C6F0C	sw     ra, $001c(sp)
800C6F10	sw     s2, $0018(sp)
800C6F14	sw     s1, $0014(sp)
800C6F18	lh     v1, $0012(s0)
800C6F1C	lw     v0, $0014(s0)
800C6F20	lhu    a1, $0008(s0)
800C6F24	addu   v0, v0, v1
800C6F28	lhu    v1, $000a(s0)
800C6F2C	sra    a0, v0, $08
800C6F30	sw     v0, $0014(s0)
800C6F34	lhu    v0, $0010(s0)

Lc6f38:	; 800C6F38
800C6F38	subu   v1, v1, a1
800C6F3C	beq    v0, zero, Lc70dc [$800c70dc]
800C6F40	addu   s2, v1, zero
800C6F44	lh     v0, $0012(s0)
800C6F48	nop
800C6F4C	beq    v0, zero, Lc70dc [$800c70dc]
800C6F50	sll    v0, v1, $10
800C6F54	sra    s1, v0, $10
800C6F58	blez   s1, Lc70e8 [$800c70e8]
800C6F5C	addu   v0, zero, zero
800C6F60	lhu    v1, $0006(s0)
800C6F64	nop
800C6F68	beq    v1, zero, Lc6f80 [$800c6f80]
800C6F6C	addiu  v0, zero, $0001
800C6F70	beq    v1, v0, Lc6f88 [$800c6f88]
800C6F74	nop
800C6F78	j      Lc6ffc [$800c6ffc]
800C6F7C	nop

Lc6f80:	; 800C6F80
800C6F80	j      Lc7008 [$800c7008]
800C6F84	addu   v1, a1, a0

Lc6f88:	; 800C6F88
800C6F88	sll    a0, a0, $0c
800C6F8C	div    a0, s1
800C6F90	bne    s1, zero, Lc6f9c [$800c6f9c]
800C6F94	nop
800C6F98	break   $01c00

Lc6f9c:	; 800C6F9C
800C6F9C	addiu  at, zero, $ffff (=-$1)
800C6FA0	bne    s1, at, Lc6fb4 [$800c6fb4]
800C6FA4	lui    at, $8000
800C6FA8	bne    a0, at, Lc6fb4 [$800c6fb4]
800C6FAC	nop
800C6FB0	break   $01800

Lc6fb4:	; 800C6FB4
800C6FB4	mflo   a0
800C6FB8	nop
800C6FBC	sll    a0, a0, $10
800C6FC0	sra    a0, a0, $10
800C6FC4	jal    system_get_cos_by_rotation [$8004bb7c]
800C6FC8	addiu  a0, a0, $0800
800C6FCC	sll    v0, v0, $10
800C6FD0	sra    v0, v0, $10
800C6FD4	addiu  v0, v0, $1000
800C6FD8	mult   s1, v0
800C6FDC	mflo   v0
800C6FE0	bgez   v0, Lc6fec [$800c6fec]
800C6FE4	nop
800C6FE8	addiu  v0, v0, $1fff

Lc6fec:	; 800C6FEC
800C6FEC	lhu    v1, $0008(s0)
800C6FF0	sra    v0, v0, $0d
800C6FF4	j      Lc7008 [$800c7008]
800C6FF8	addu   v1, v1, v0

Lc6ffc:	; 800C6FFC
800C6FFC	lhu    v0, $0008(s0)
800C7000	nop
800C7004	addu   v1, v0, a0

Lc7008:	; 800C7008
800C7008	lhu    v0, $000c(s0)
800C700C	sh     v1, $000c(s0)
800C7010	sll    v1, v1, $10
800C7014	sra    v1, v1, $10
800C7018	sh     v0, $000e(s0)
800C701C	lh     v0, $000a(s0)
800C7020	lhu    a0, $000a(s0)
800C7024	slt    v0, v0, v1
800C7028	beq    v0, zero, Lc7084 [$800c7084]
800C702C	nop
800C7030	lhu    v0, $0000(s0)
800C7034	nop
800C7038	andi   v0, v0, $0010
800C703C	beq    v0, zero, Lc7058 [$800c7058]
800C7040	nop
800C7044	lhu    v0, $0012(s0)
800C7048	sh     a0, $000c(s0)
800C704C	subu   v0, zero, v0
800C7050	j      Lc7064 [$800c7064]
800C7054	sh     v0, $0012(s0)

Lc7058:	; 800C7058
800C7058	lhu    v0, $0008(s0)
800C705C	nop
800C7060	sh     v0, $000c(s0)

Lc7064:	; 800C7064
800C7064	sll    v0, s2, $10
800C7068	sra    v0, v0, $08
800C706C	lhu    v1, $0000(s0)
800C7070	addiu  v0, v0, $ff00 (=-$100)
800C7074	sw     v0, $0014(s0)
800C7078	andi   v1, v1, $fffb
800C707C	j      Lc70e4 [$800c70e4]
800C7080	sh     v1, $0000(s0)

Lc7084:	; 800C7084
800C7084	lh     v0, $0008(s0)
800C7088	nop
800C708C	slt    v0, v1, v0
800C7090	lhu    v1, $0008(s0)
800C7094	beq    v0, zero, Lc70e8 [$800c70e8]
800C7098	addiu  v0, zero, $0001
800C709C	lhu    v0, $0000(s0)
800C70A0	nop
800C70A4	andi   v0, v0, $0010
800C70A8	beq    v0, zero, Lc70c4 [$800c70c4]
800C70AC	nop
800C70B0	lhu    v0, $0012(s0)
800C70B4	sh     v1, $000c(s0)
800C70B8	subu   v0, zero, v0
800C70BC	j      Lc70c8 [$800c70c8]
800C70C0	sh     v0, $0012(s0)

Lc70c4:	; 800C70C4
800C70C4	sh     a0, $000c(s0)

Lc70c8:	; 800C70C8
800C70C8	lhu    v0, $0000(s0)
800C70CC	sw     zero, $0014(s0)
800C70D0	andi   v0, v0, $fffb
800C70D4	j      Lc70e4 [$800c70e4]
800C70D8	sh     v0, $0000(s0)

Lc70dc:	; 800C70DC
800C70DC	j      Lc70e8 [$800c70e8]
800C70E0	addu   v0, zero, zero

Lc70e4:	; 800C70E4
800C70E4	addiu  v0, zero, $0001

Lc70e8:	; 800C70E8
800C70E8	lw     ra, $001c(sp)
800C70EC	lw     s2, $0018(sp)
800C70F0	lw     s1, $0014(sp)
800C70F4	lw     s0, $0010(sp)
800C70F8	jr     ra 
800C70FC	addiu  sp, sp, $0020


funcc7100:	; 800C7100
800C7100	addiu  sp, sp, $ffd0 (=-$30)
800C7104	lui    v0, $800d
800C7108	sw     s2, $0018(sp)
800C710C	addiu  s2, v0, $ae98 (=-$5168)
800C7110	sw     s1, $0014(sp)
800C7114	addu   s1, zero, zero
800C7118	lui    v0, $800d
800C711C	sw     s3, $001c(sp)
800C7120	addiu  s3, v0, $9df0 (=-$6210)
800C7124	sw     s5, $0024(sp)
800C7128	addiu  s5, zero, $0001
800C712C	sw     s4, $0020(sp)
800C7130	addiu  s4, zero, $0002
800C7134	sw     s0, $0010(sp)
800C7138	addiu  s0, s2, $0004
800C713C	sw     ra, $0028(sp)

loopc7140:	; 800C7140
800C7140	lhu    v1, $0000(s2)
800C7144	nop
800C7148	andi   v0, v1, $0001
800C714C	beq    v0, zero, Lc729c [$800c729c]
800C7150	andi   v0, v1, $000c
800C7154	beq    v0, zero, Lc729c [$800c729c]
800C7158	nop
800C715C	lhu    v1, $fffe(s0)
800C7160	lw     a0, $001c(s3)
800C7164	lhu    v0, $0000(s0)
800C7168	sll    v1, v1, $05
800C716C	addu   a0, a0, v1
800C7170	sll    v0, v0, $01
800C7174	addu   a0, a0, v0
800C7178	lhu    v0, $0004(a0)
800C717C	lhu    v1, $0008(s0)
800C7180	nop
800C7184	addu   v0, v0, v1
800C7188	sh     v0, $000a(a0)
800C718C	lhu    v0, $0002(s3)
800C7190	lw     a3, $0004(s3)
800C7194	beq    v0, zero, Lc7294 [$800c7294]
800C7198	addu   t0, zero, zero
800C719C	lui    v0, $800d
800C71A0	addiu  t1, v0, $9df0 (=-$6210)
800C71A4	addiu  a2, a3, $0024

loopc71a8:	; 800C71A8
800C71A8	lhu    v0, $0000(a3)
800C71AC	nop
800C71B0	andi   v0, v0, $0001
800C71B4	beq    v0, zero, Lc727c [$800c727c]
800C71B8	nop
800C71BC	lh     v1, $ffe0(a2)
800C71C0	lhu    v0, $fffe(s0)
800C71C4	nop
800C71C8	bne    v1, v0, Lc727c [$800c727c]
800C71CC	nop
800C71D0	lh     v0, $ffe2(a2)
800C71D4	nop
800C71D8	bltz   v0, Lc727c [$800c727c]
800C71DC	nop
800C71E0	lhu    v0, $0000(s0)
800C71E4	lw     a1, $0000(a2)
800C71E8	lh     v1, $0008(s0)
800C71EC	lh     a0, $000a(s0)
800C71F0	sll    v0, v0, $02
800C71F4	addu   a1, a1, v0
800C71F8	lw     v0, $0014(a1)
800C71FC	subu   v1, v1, a0
800C7200	addu   v0, v0, v1
800C7204	sw     v0, $0014(a1)
800C7208	lhu    v1, $0000(s0)
800C720C	nop
800C7210	beq    v1, s5, Lc7254 [$800c7254]
800C7214	slti   v0, v1, $0002
800C7218	beq    v0, zero, Lc7230 [$800c7230]
800C721C	nop
800C7220	beq    v1, zero, Lc7240 [$800c7240]
800C7224	nop
800C7228	j      Lc7280 [$800c7280]
800C722C	addiu  a2, a2, $0028

Lc7230:	; 800C7230
800C7230	beq    v1, s4, Lc7268 [$800c7268]
800C7234	nop
800C7238	j      Lc7280 [$800c7280]
800C723C	addiu  a2, a2, $0028

Lc7240:	; 800C7240
800C7240	lw     v0, $0000(a2)
800C7244	nop
800C7248	lw     v1, $0014(v0)
800C724C	j      Lc727c [$800c727c]
800C7250	sw     v1, $0040(v0)

Lc7254:	; 800C7254
800C7254	lw     v0, $0000(a2)
800C7258	nop
800C725C	lw     v1, $0018(v0)
800C7260	j      Lc727c [$800c727c]
800C7264	sw     v1, $0044(v0)

Lc7268:	; 800C7268
800C7268	lw     v0, $0000(a2)
800C726C	nop
800C7270	lw     v1, $001c(v0)
800C7274	nop
800C7278	sw     v1, $0048(v0)

Lc727c:	; 800C727C
800C727C	addiu  a2, a2, $0028

Lc7280:	; 800C7280
800C7280	lhu    v0, $0002(t1)
800C7284	addiu  t0, t0, $0001
800C7288	slt    v0, t0, v0
800C728C	bne    v0, zero, loopc71a8 [$800c71a8]
800C7290	addiu  a3, a3, $0028

Lc7294:	; 800C7294
800C7294	jal    funcc6eec [$800c6eec]
800C7298	addu   a0, s1, zero

Lc729c:	; 800C729C
800C729C	addiu  s0, s0, $0018
800C72A0	addiu  s1, s1, $0001
800C72A4	slti   v0, s1, $001e
800C72A8	bne    v0, zero, loopc7140 [$800c7140]
800C72AC	addiu  s2, s2, $0018
800C72B0	lw     ra, $0028(sp)
800C72B4	lw     s5, $0024(sp)
800C72B8	lw     s4, $0020(sp)
800C72BC	lw     s3, $001c(sp)
800C72C0	lw     s2, $0018(sp)
800C72C4	lw     s1, $0014(sp)
800C72C8	lw     s0, $0010(sp)
800C72CC	addiu  v0, zero, $0001
800C72D0	jr     ra 
800C72D4	addiu  sp, sp, $0030

800C72D8	addiu  sp, sp, $ffe0 (=-$20)
800C72DC	lui    v0, $800d
800C72E0	addiu  v1, v0, $9df0 (=-$6210)
800C72E4	sw     ra, $0018(sp)
800C72E8	sw     s1, $0014(sp)
800C72EC	sw     s0, $0010(sp)
800C72F0	sw     a0, $0008(v1)
800C72F4	lhu    v0, $003a(a0)
800C72F8	nop
800C72FC	addu   v0, a0, v0
800C7300	sw     v0, $000c(v1)
800C7304	lhu    v0, $0026(a0)
800C7308	nop
800C730C	addu   v0, a0, v0
800C7310	sw     v0, $0010(v1)
800C7314	lhu    v0, $0036(a0)
800C7318	nop
800C731C	addu   v0, a0, v0
800C7320	sw     v0, $0014(v1)
800C7324	lhu    v0, $002a(a0)
800C7328	nop
800C732C	addu   v0, a0, v0
800C7330	sw     v0, $0018(v1)
800C7334	lhu    v0, $0032(a0)
800C7338	nop
800C733C	addu   v0, a0, v0
800C7340	sw     v0, $001c(v1)
800C7344	lhu    v0, $002e(a0)
800C7348	nop
800C734C	addu   v0, a0, v0
800C7350	sw     v0, $0020(v1)
800C7354	lhu    v0, $002c(a0)
800C7358	nop
800C735C	beq    v0, zero, Lc738c [$800c738c]
800C7360	addu   s0, zero, zero
800C7364	addu   s1, v1, zero

loopc7368:	; 800C7368
800C7368	jal    funcc79b0 [$800c79b0]
800C736C	addu   a0, s0, zero
800C7370	lw     v0, $0008(s1)
800C7374	nop
800C7378	lhu    v0, $002c(v0)
800C737C	addiu  s0, s0, $0001
800C7380	slt    v0, s0, v0
800C7384	bne    v0, zero, loopc7368 [$800c7368]
800C7388	nop

Lc738c:	; 800C738C
800C738C	jal    funcc6e94 [$800c6e94]
800C7390	nop
800C7394	lw     ra, $0018(sp)
800C7398	lw     s1, $0014(sp)
800C739C	lw     s0, $0010(sp)
800C73A0	addiu  v0, zero, $0001
800C73A4	jr     ra 
800C73A8	addiu  sp, sp, $0020

800C73AC	addiu  sp, sp, $ffe0 (=-$20)
800C73B0	sw     s1, $0014(sp)
800C73B4	addu   s1, zero, zero
800C73B8	lui    v0, $800d
800C73BC	addiu  v1, v0, $9df0 (=-$6210)
800C73C0	sw     ra, $001c(sp)
800C73C4	sw     s2, $0018(sp)
800C73C8	sw     s0, $0010(sp)
800C73CC	lhu    v0, $0002(v1)
800C73D0	nop
800C73D4	beq    v0, zero, Lc7414 [$800c7414]
800C73D8	addu   s0, s1, zero
800C73DC	addu   s2, v1, zero

loopc73e0:	; 800C73E0
800C73E0	sll    a0, s0, $10
800C73E4	jal    funcc44f4 [$800c44f4]
800C73E8	sra    a0, a0, $10
800C73EC	blez   v0, Lc73f8 [$800c73f8]

Lc73f0:	; 800C73F0
800C73F0	addiu  v0, s0, $0001
800C73F4	addiu  s1, s1, $0001

Lc73f8:	; 800C73F8
800C73F8	addu   s0, v0, zero
800C73FC	sll    v0, v0, $10
800C7400	lhu    v1, $0002(s2)
800C7404	sra    v0, v0, $10
800C7408	slt    v0, v0, v1
800C740C	bne    v0, zero, loopc73e0 [$800c73e0]
800C7410	nop

Lc7414:	; 800C7414
800C7414	andi   v0, s1, $ffff
800C7418	lw     ra, $001c(sp)
800C741C	lw     s2, $0018(sp)
800C7420	lw     s1, $0014(sp)
800C7424	lw     s0, $0010(sp)
800C7428	jr     ra 
800C742C	addiu  sp, sp, $0020



////////////////////////////////
// funcc7430
800C7430-800C744C
////////////////////////////////



800C7450	jr     ra 
800C7454	addiu  v0, zero, $0001

800C7458	addiu  v0, zero, $0001
800C745C	jr     ra 
800C7460	sw     v0, $0000(a0)



////////////////////////////////
// funcc7464
800C7464-800C7470
////////////////////////////////



800C7474	lui    v0, $800d
800C7478	lbu    v0, $9df1(v0)
800C747C	nop
800C7480	sb     v0, $0000(a0)
800C7484	jr     ra 
800C7488	addiu  v0, zero, $0001


funcc748c:	; 800C748C
800C748C	lui    v0, $800d
800C7490	sll    v1, a0, $02
800C7494	addu   v1, v1, a0
800C7498	lw     v0, $9df4(v0)
800C749C	sll    v1, v1, $03
800C74A0	jr     ra 
800C74A4	addu   v0, v0, v1


funcc74a8:	; 800C74A8
800C74A8	lui    a2, $800d
800C74AC	addiu  a2, a2, $9df0 (=-$6210)
800C74B0	sll    v1, a0, $02
800C74B4	addu   v1, v1, a0
800C74B8	lw     v0, $0004(a2)
800C74BC	sll    v1, v1, $03
800C74C0	addu   v0, v1, v0
800C74C4	sh     zero, $0000(v0)
800C74C8	lw     v0, $0004(a2)
800C74CC	nop
800C74D0	addu   v0, v1, v0
800C74D4	sh     zero, $0002(v0)
800C74D8	lw     v0, $0004(a2)
800C74DC	lw     a0, $000c(a1)
800C74E0	addu   v1, v1, v0
800C74E4	addiu  v0, zero, $0001
800C74E8	jr     ra 
800C74EC	sw     a0, $0024(v1)


funcc74f0:	; 800C74F0
800C74F0	lui    a1, $800d
800C74F4	addiu  a1, a1, $9df0 (=-$6210)
800C74F8	lhu    v1, $0002(a1)
800C74FC	nop
800C7500	sll    v0, v1, $02
800C7504	addu   v0, v0, v1
800C7508	lw     v1, $0004(a1)
800C750C	sll    v0, v0, $03
800C7510	addu   v0, v0, v1
800C7514	sh     zero, $0000(v0)
800C7518	lhu    v1, $0002(a1)
800C751C	nop
800C7520	sll    v0, v1, $02
800C7524	addu   v0, v0, v1
800C7528	lw     v1, $0004(a1)
800C752C	sll    v0, v0, $03
800C7530	addu   v0, v0, v1
800C7534	sh     zero, $0002(v0)
800C7538	lhu    v1, $0002(a1)
800C753C	lw     a0, $000c(a0)
800C7540	sll    v0, v1, $02
800C7544	addu   v0, v0, v1
800C7548	lw     v1, $0004(a1)
800C754C	sll    v0, v0, $03
800C7550	addu   v0, v0, v1
800C7554	sw     a0, $0024(v0)
800C7558	lhu    v0, $0002(a1)
800C755C	nop
800C7560	addiu  v0, v0, $0001
800C7564	sh     v0, $0002(a1)
800C7568	jr     ra 
800C756C	addiu  v0, zero, $0001



////////////////////////////////
// funcc7570
800C7570-800C75B0
////////////////////////////////



funcc75b4:	; 800C75B4
800C75B4	lui    v1, $800d
800C75B8	sll    v0, a0, $02
800C75BC	addu   v0, v0, a0
800C75C0	lw     v1, $9df4(v1)
800C75C4	sll    v0, v0, $03
800C75C8	addu   v0, v0, v1
800C75CC	lw     v0, $001c(v0)
800C75D0	nop
800C75D4	sw     v0, $0000(a1)
800C75D8	jr     ra 
800C75DC	addiu  v0, zero, $0001

800C75E0	lui    v1, $800d
800C75E4	sll    v0, a0, $02
800C75E8	addu   v0, v0, a0
800C75EC	lw     v1, $9df4(v1)
800C75F0	sll    v0, v0, $03
800C75F4	addu   v0, v0, v1
800C75F8	lw     v0, $0020(v0)
800C75FC	nop
800C7600	sw     v0, $0000(a1)
800C7604	jr     ra 
800C7608	addiu  v0, zero, $0001

800C760C	lui    t0, $800d
800C7610	addiu  t0, t0, $9df0 (=-$6210)
800C7614	sll    v0, a0, $02
800C7618	addu   v0, v0, a0
800C761C	lw     v1, $0004(t0)
800C7620	sll    v0, v0, $03
800C7624	addu   v1, v1, v0
800C7628	lh     v1, $0006(v1)
800C762C	lw     a0, $0010(sp)
800C7630	sll    v0, v1, $02
800C7634	addu   v0, v0, v1
800C7638	lw     v1, $0010(t0)
800C763C	sll    v0, v0, $03
800C7640	addu   v1, v1, v0
800C7644	lh     v0, $0006(v1)
800C7648	lw     v1, $0014(t0)
800C764C	sll    v0, v0, $04
800C7650	addu   v1, v1, v0
800C7654	lw     v0, $0000(v1)
800C7658	nop
800C765C	sw     v0, $0000(a1)
800C7660	lw     v0, $0004(v1)
800C7664	nop
800C7668	sw     v0, $0000(a2)
800C766C	lw     v0, $0008(v1)

Lc7670:	; 800C7670
800C7670	nop
800C7674	sw     v0, $0000(a3)
800C7678	lw     v0, $000c(v1)
800C767C	nop
800C7680	sw     v0, $0000(a0)
800C7684	jr     ra 
800C7688	addiu  v0, zero, $0001


funcc768c:	; 800C768C
800C768C	lui    a3, $800d
800C7690	addiu  a3, a3, $9df0 (=-$6210)
800C7694	sll    v0, a0, $02
800C7698	addu   v0, v0, a0
800C769C	lw     v1, $0004(a3)
800C76A0	sll    v0, v0, $03
800C76A4	addu   v1, v1, v0
800C76A8	lh     v1, $0006(v1)
800C76AC	nop
800C76B0	sll    v0, v1, $02
800C76B4	addu   v0, v0, v1
800C76B8	lw     v1, $0010(a3)
800C76BC	sll    v0, v0, $03
800C76C0	addu   v1, v1, v0
800C76C4	lhu    v0, $000a(v1)
800C76C8	nop
800C76CC	subu   v0, zero, v0
800C76D0	sh     v0, $0000(a1)
800C76D4	lhu    v0, $0008(v1)
800C76D8	nop

Lc76dc:	; 800C76DC
800C76DC	sh     v0, $0000(a2)
800C76E0	jr     ra 
800C76E4	addiu  v0, zero, $0001


funcc76e8:	; 800C76E8
800C76E8	lui    v1, $800d
800C76EC	sll    v0, a0, $02
800C76F0	addu   v0, v0, a0
800C76F4	lw     v1, $9df4(v1)
800C76F8	sll    v0, v0, $03
800C76FC	addu   v1, v1, v0
800C7700	lhu    v0, $0006(v1)
800C7704	nop
800C7708	sh     v0, $0000(a1)
800C770C	lhu    v0, $0004(v1)
800C7710	nop
800C7714	sh     v0, $0000(a2)
800C7718	jr     ra 
800C771C	addiu  v0, zero, $0001


funcc7720:	; 800C7720
800C7720	lui    v1, $800d
800C7724	sll    v0, a0, $02
800C7728	addu   v0, v0, a0
800C772C	lw     v1, $9df4(v1)

funcc7730:	; 800C7730
800C7730	sll    v0, v0, $03
800C7734	addu   v1, v1, v0
800C7738	lw     a0, $0024(v1)
800C773C	nop
800C7740	lw     v0, $0040(a0)

Lc7744:	; 800C7744
800C7744	nop
800C7748	sw     v0, $0014(a0)
800C774C	lw     a0, $0024(v1)
800C7750	nop
800C7754	lw     v0, $0044(a0)
800C7758	nop
800C775C	sw     v0, $0018(a0)
800C7760	lw     a0, $0024(v1)
800C7764	nop
800C7768	lw     v0, $0048(a0)
800C776C	nop
800C7770	sw     v0, $001c(a0)
800C7774	lhu    v0, $0008(v1)
800C7778	lhu    a0, $000a(v1)
800C777C	sh     v0, $0004(v1)
800C7780	addiu  v0, zero, $0001
800C7784	jr     ra 
800C7788	sh     a0, $0006(v1)



/////////////////////////////////////////////////////
// funcc778c
800C778C-800C77D8
/////////////////////////////////////////////////////



800C77DC	lui    v0, $800d
800C77E0	lhu    v0, $9dde(v0)
800C77E4	nop
800C77E8	sh     v0, $0000(a0)
800C77EC	lui    v0, $800d
800C77F0	addiu  v0, v0, $aa98 (=-$5568)
800C77F4	sw     v0, $0000(a1)
800C77F8	jr     ra 
800C77FC	addiu  v0, zero, $0001


funcc7800:	; 800C7800
800C7800	lui    v1, $800d
800C7804	addiu  v1, v1, $9df0 (=-$6210)
800C7808	sll    a0, a0, $10
800C780C	sra    a0, a0, $10
800C7810	lw     a2, $0008(v1)
800C7814	lbu    v1, $0001(v1)
800C7818	lhu    v0, $0026(a2)
800C781C	sll    v1, v1, $08
800C7820	addu   a2, a2, v0
800C7824	sll    v0, a0, $02
800C7828	addu   v0, v0, a0
800C782C	sll    v0, v0, $03
800C7830	addu   a2, a2, v0
800C7834	lhu    v0, $0000(a2)
800C7838	ori    v1, v1, $00ff
800C783C	and    v0, v0, v1
800C7840	sh     v0, $0000(a1)
800C7844	jr     ra 
800C7848	addiu  v0, zero, $0001

800C784C	lui    v0, $800d
800C7850	sll    a0, a0, $10
800C7854	lw     v1, $9df8(v0)
800C7858	sra    a0, a0, $10
800C785C	lhu    v0, $0026(v1)
800C7860	andi   a1, a1, $00ff
800C7864	addu   v1, v1, v0
800C7868	sll    v0, a0, $02
800C786C	addu   v0, v0, a0
800C7870	sll    v0, v0, $03
800C7874	addu   v1, v1, v0
800C7878	lbu    v0, $0000(v1)
800C787C	sll    a1, a1, $08
800C7880	or     a1, a1, v0
800C7884	addiu  v0, zero, $0001
800C7888	jr     ra 
800C788C	sh     a1, $0000(v1)

800C7890	lui    a2, $800d
800C7894	addiu  a2, a2, $9df0 (=-$6210)
800C7898	lw     v1, $0008(a2)
800C789C	sll    a0, a0, $10
800C78A0	lhu    v0, $0026(v1)
800C78A4	sra    a0, a0, $10
800C78A8	addu   v1, v1, v0
800C78AC	sll    v0, a0, $02
800C78B0	addu   v0, v0, a0
800C78B4	sll    v0, v0, $03
800C78B8	addu   v1, v1, v0
800C78BC	lhu    v0, $0000(v1)
800C78C0	lbu    v1, $0001(a2)
800C78C4	srl    v0, v0, $08
800C78C8	and    v0, v0, v1
800C78CC	sb     v0, $0000(a1)
800C78D0	jr     ra 
800C78D4	addiu  v0, zero, $0001

800C78D8	lui    v0, $800d
800C78DC	lw     v1, $9df8(v0)
800C78E0	sll    a0, a0, $10
800C78E4	lhu    v0, $0026(v1)
800C78E8	sra    a0, a0, $10
800C78EC	addu   v1, v1, v0
800C78F0	sll    v0, a0, $02
800C78F4	addu   v0, v0, a0
800C78F8	sll    v0, v0, $03
800C78FC	addu   v1, v1, v0
800C7900	lhu    v0, $0004(v1)
800C7904	nop
800C7908	sh     v0, $0000(a1)
800C790C	jr     ra 
800C7910	addiu  v0, zero, $0001

800C7914	lui    v0, $800d
800C7918	lhu    v0, $9de0(v0)
800C791C	nop
800C7920	sh     v0, $0000(a0)
800C7924	lui    v0, $800d
800C7928	addiu  v0, v0, $aab8 (=-$5548)
800C792C	sw     v0, $0000(a1)
800C7930	jr     ra 
800C7934	addiu  v0, zero, $0001

800C7938	lui    v0, $800d
800C793C	lw     v0, $9df8(v0)
800C7940	sll    a0, a0, $10
800C7944	lhu    v1, $002a(v0)
800C7948	sra    a0, a0, $0e
800C794C	addu   v0, v0, v1
800C7950	addu   v0, v0, a0
800C7954	lhu    v0, $0000(v0)
800C7958	nop
800C795C	sh     v0, $0000(a1)
800C7960	jr     ra 
800C7964	addiu  v0, zero, $0001

800C7968	lui    v0, $800d
800C796C	lw     v0, $9df8(v0)
800C7970	nop
800C7974	lhu    v1, $0032(v0)
800C7978	sll    a0, a0, $05
800C797C	addu   v0, v0, v1
800C7980	addu   v0, v0, a0
800C7984	lhu    v1, $000a(v0)
800C7988	nop
800C798C	sh     v1, $0000(a1)
800C7990	lhu    v1, $000c(v0)
800C7994	nop
800C7998	sh     v1, $0000(a2)
800C799C	lhu    v0, $000e(v0)
800C79A0	nop
800C79A4	sh     v0, $0000(a3)
800C79A8	jr     ra 
800C79AC	addiu  v0, zero, $0001


funcc79b0:	; 800C79B0
800C79B0	addiu  sp, sp, $ffc8 (=-$38)
800C79B4	lui    v0, $800d
800C79B8	addiu  a1, v0, $9df0 (=-$6210)
800C79BC	sw     ra, $0030(sp)
800C79C0	sw     s7, $002c(sp)
800C79C4	sw     s6, $0028(sp)
800C79C8	sw     s5, $0024(sp)
800C79CC	sw     s4, $0020(sp)
800C79D0	sw     s3, $001c(sp)
800C79D4	sw     s2, $0018(sp)
800C79D8	sw     s1, $0014(sp)
800C79DC	sw     s0, $0010(sp)
800C79E0	lw     s6, $0008(a1)
800C79E4	nop
800C79E8	lhu    v0, $002c(s6)
800C79EC	nop
800C79F0	sltu   v0, a0, v0
800C79F4	bne    v0, zero, Lc7a04 [$800c7a04]
800C79F8	addu   s3, zero, zero
800C79FC	j      Lc7acc [$800c7acc]
800C7A00	addu   v0, zero, zero

Lc7a04:	; 800C7A04
800C7A04	lw     v1, $0020(a1)
800C7A08	sll    v0, a0, $04
800C7A0C	addu   s5, v1, v0
800C7A10	lw     v0, $000c(s5)
800C7A14	lhu    v1, $0002(s5)
800C7A18	nop

Lc7a1c:	; 800C7A1C
800C7A1C	beq    v1, zero, Lc7ac8 [$800c7ac8]
800C7A20	addu   s4, s6, v0
800C7A24	addu   s7, a1, zero
800C7A28	addiu  s2, s4, $0004

loopc7a2c:	; 800C7A2C
800C7A2C	addu   s0, zero, zero
800C7A30	lhu    v0, $0002(s2)
800C7A34	lhu    v1, $0000(s2)
800C7A38	nop
800C7A3C	beq    v1, zero, Lc7ab0 [$800c7ab0]
800C7A40	addu   s1, s6, v0

loopc7a44:	; 800C7A44
800C7A44	lw     v0, $0000(s1)
800C7A48	nop
800C7A4C	sll    v1, v0, $02
800C7A50	addu   v1, v1, v0
800C7A54	lw     v0, $0010(s7)
800C7A58	sll    v1, v1, $03
800C7A5C	bne    s3, zero, Lc7a88 [$800c7a88]
800C7A60	addu   v1, v0, v1
800C7A64	addu   a0, s6, zero
800C7A68	addu   a1, s5, zero
800C7A6C	lhu    v0, $0000(v1)
800C7A70	addu   a2, s4, zero
800C7A74	ori    v0, v0, $0001
800C7A78	jal    funcc6da4 [$800c6da4]
800C7A7C	sh     v0, $0000(v1)
800C7A80	j      Lc7a9c [$800c7a9c]
800C7A84	addiu  s1, s1, $0004

Lc7a88:	; 800C7A88
800C7A88	lhu    v0, $0000(v1)

Lc7a8c:	; 800C7A8C
800C7A8C	nop
800C7A90	andi   v0, v0, $fffe
800C7A94	sh     v0, $0000(v1)
800C7A98	addiu  s1, s1, $0004

Lc7a9c:	; 800C7A9C
800C7A9C	lhu    v0, $0000(s2)
800C7AA0	addiu  s0, s0, $0001
800C7AA4	slt    v0, s0, v0
800C7AA8	bne    v0, zero, loopc7a44 [$800c7a44]
800C7AAC	nop

Lc7ab0:	; 800C7AB0
800C7AB0	addiu  s2, s2, $0008
800C7AB4	lhu    v0, $0002(s5)
800C7AB8	addiu  s3, s3, $0001
800C7ABC	slt    v0, s3, v0
800C7AC0	bne    v0, zero, loopc7a2c [$800c7a2c]
800C7AC4	addiu  s4, s4, $0008

Lc7ac8:	; 800C7AC8
800C7AC8	addiu  v0, zero, $0001

Lc7acc:	; 800C7ACC
800C7ACC	lw     ra, $0030(sp)
800C7AD0	lw     s7, $002c(sp)
800C7AD4	lw     s6, $0028(sp)
800C7AD8	lw     s5, $0024(sp)
800C7ADC	lw     s4, $0020(sp)
800C7AE0	lw     s3, $001c(sp)
800C7AE4	lw     s2, $0018(sp)
800C7AE8	lw     s1, $0014(sp)
800C7AEC	lw     s0, $0010(sp)
800C7AF0	jr     ra 
800C7AF4	addiu  sp, sp, $0038


funcc7af8:	; 800C7AF8
800C7AF8	lui    v0, $800d
800C7AFC	addiu  v1, v0, $9df0 (=-$6210)
800C7B00	lw     v0, $0008(v1)
800C7B04	nop
800C7B08	lhu    v0, $002c(v0)
800C7B0C	nop
800C7B10	sltu   v0, a0, v0
800C7B14	bne    v0, zero, Lc7b24 [$800c7b24]
800C7B18	sll    v0, a0, $04
800C7B1C	jr     ra 
800C7B20	addu   v0, zero, zero


Lc7b24:	; 800C7B24
800C7B24	lw     v1, $0020(v1)
800C7B28	nop
800C7B2C	addu   a2, v1, v0
800C7B30	lhu    v0, $0002(a2)
800C7B34	nop
800C7B38	sltu   v0, a1, v0
800C7B3C	beq    v0, zero, Lc7b60 [$800c7b60]
800C7B40	addiu  v0, zero, $0001
800C7B44	lhu    a0, $0000(a2)
800C7B48	sll    v1, a1, $08
800C7B4C	sw     v1, $0008(a2)
800C7B50	sh     zero, $0006(a2)
800C7B54	or     a0, a0, v0
800C7B58	jr     ra 
800C7B5C	sh     a0, $0000(a2)


Lc7b60:	; 800C7B60
800C7B60	jr     ra 
800C7B64	addu   v0, zero, zero


funcc7b68:	; 800C7B68
800C7B68	lui    v0, $800d
800C7B6C	addiu  v1, v0, $9df0 (=-$6210)
800C7B70	lw     v0, $0008(v1)
800C7B74	nop
800C7B78	lhu    v0, $002c(v0)
800C7B7C	nop
800C7B80	sltu   v0, a0, v0

funcc7b84:	; 800C7B84
800C7B84	bne    v0, zero, Lc7b94 [$800c7b94]
800C7B88	sll    v0, a0, $04

Lc7b8c:	; 800C7B8C
800C7B8C	jr     ra 
800C7B90	addu   v0, zero, zero


Lc7b94:	; 800C7B94
800C7B94	lw     v1, $0020(v1)
800C7B98	beq    a1, zero, Lc7bac [$800c7bac]
800C7B9C	addu   v1, v1, v0
800C7BA0	lhu    v0, $0000(v1)
800C7BA4	j      Lc7bb8 [$800c7bb8]
800C7BA8	ori    v0, v0, $0005

Lc7bac:	; 800C7BAC
800C7BAC	lhu    v0, $0000(v1)
800C7BB0	nop
800C7BB4	andi   v0, v0, $fffa

Lc7bb8:	; 800C7BB8
800C7BB8	sh     v0, $0000(v1)
800C7BBC	jr     ra 
800C7BC0	addiu  v0, zero, $0001


funcc7bc4:	; 800C7BC4
800C7BC4	lui    v0, $800d
800C7BC8	addiu  v1, v0, $9df0 (=-$6210)
800C7BCC	lw     v0, $0008(v1)
800C7BD0	nop
800C7BD4	lhu    v0, $002c(v0)
800C7BD8	nop
800C7BDC	sltu   v0, a0, v0
800C7BE0	beq    v0, zero, Lc7bfc [$800c7bfc]

Lc7be4:	; 800C7BE4
800C7BE4	addiu  v0, zero, $0001
800C7BE8	lw     v1, $0020(v1)
800C7BEC	sll    a0, a0, $04
800C7BF0	addu   v1, v1, a0
800C7BF4	jr     ra 
800C7BF8	sh     a1, $0004(v1)


Lc7bfc:	; 800C7BFC
800C7BFC	jr     ra 
800C7C00	addu   v0, zero, zero


funcc7c04:	; 800C7C04
800C7C04	lui    v0, $800d
800C7C08	addiu  v1, v0, $9df0 (=-$6210)
800C7C0C	lw     t0, $0008(v1)
800C7C10	nop
800C7C14	lhu    v0, $002c(t0)
800C7C18	nop
800C7C1C	sltu   v0, a0, v0
800C7C20	bne    v0, zero, Lc7c30 [$800c7c30]
800C7C24	addu   a2, zero, zero
800C7C28	jr     ra 
800C7C2C	addu   v0, zero, zero


Lc7c30:	; 800C7C30
800C7C30	lw     v1, $0020(v1)

Lc7c34:	; 800C7C34
800C7C34	sll    v0, a0, $04
800C7C38	addu   a3, v1, v0
800C7C3C	lw     v0, $000c(a3)
800C7C40	lhu    v1, $0002(a3)
800C7C44	nop
800C7C48	beq    v1, zero, Lc7c68 [$800c7c68]
800C7C4C	addu   a0, t0, v0

loopc7c50:	; 800C7C50
800C7C50	sh     a1, $0002(a0)
800C7C54	lhu    v0, $0002(a3)
800C7C58	addiu  a2, a2, $0001
800C7C5C	slt    v0, a2, v0
800C7C60	bne    v0, zero, loopc7c50 [$800c7c50]
800C7C64	addiu  a0, a0, $0008

Lc7c68:	; 800C7C68
800C7C68	jr     ra 
800C7C6C	addiu  v0, zero, $0001


funcc7c70:	; 800C7C70
800C7C70	lui    v0, $800d
800C7C74	addiu  v1, v0, $9df0 (=-$6210)
800C7C78	lw     a3, $0008(v1)
800C7C7C	nop
800C7C80	lhu    v0, $002c(a3)
800C7C84	nop
800C7C88	sltu   v0, a0, v0
800C7C8C	bne    v0, zero, Lc7c9c [$800c7c9c]
800C7C90	sll    v0, a0, $04
800C7C94	jr     ra 
800C7C98	addu   v0, zero, zero


Lc7c9c:	; 800C7C9C
800C7C9C	lw     v1, $0020(v1)
800C7CA0	nop
800C7CA4	addu   v1, v1, v0

Lc7ca8:	; 800C7CA8
800C7CA8	lhu    v0, $0002(v1)
800C7CAC	nop
800C7CB0	sltu   v0, a1, v0
800C7CB4	beq    v0, zero, Lc7cd4 [$800c7cd4]

Lc7cb8:	; 800C7CB8
800C7CB8	addiu  v0, zero, $0001
800C7CBC	lw     v1, $000c(v1)
800C7CC0	sll    a0, a1, $03
800C7CC4	addu   v1, a3, v1

funcc7cc8:	; 800C7CC8
800C7CC8	addu   v1, v1, a0
800C7CCC	jr     ra 
800C7CD0	sh     a2, $0002(v1)


Lc7cd4:	; 800C7CD4
800C7CD4	jr     ra 
800C7CD8	addu   v0, zero, zero


funcc7cdc:	; 800C7CDC
800C7CDC	lui    v0, $800d
800C7CE0	addiu  v1, v0, $9df0 (=-$6210)
800C7CE4	lw     v0, $0008(v1)
800C7CE8	nop
800C7CEC	lhu    v0, $002c(v0)
800C7CF0	nop
800C7CF4	sltu   v0, a0, v0
800C7CF8	beq    v0, zero, Lc7d28 [$800c7d28]
800C7CFC	addu   a2, a1, zero
800C7D00	sll    v0, a0, $04
800C7D04	lw     a1, $0020(v1)
800C7D08	andi   a0, a2, $0018
800C7D0C	addu   a1, a1, v0
800C7D10	lhu    v1, $0000(a1)
800C7D14	addiu  v0, zero, $0001
800C7D18	andi   v1, v1, $ffe7
800C7D1C	or     v1, v1, a0
800C7D20	jr     ra 
800C7D24	sh     v1, $0000(a1)


Lc7d28:	; 800C7D28
800C7D28	jr     ra 
800C7D2C	addu   v0, zero, zero


funcc7d30:	; 800C7D30
800C7D30	lui    v0, $800d
800C7D34	addiu  a3, v0, $9df0 (=-$6210)
800C7D38	lw     t0, $0008(a3)
800C7D3C	nop
800C7D40	lhu    v0, $002c(t0)
800C7D44	nop
800C7D48	sltu   v0, a0, v0
800C7D4C	beq    v0, zero, Lc7d74 [$800c7d74]
800C7D50	sll    v1, a0, $04

Lc7d54:	; 800C7D54
800C7D54	lw     v0, $0020(a3)
800C7D58	nop
800C7D5C	addu   a3, v0, v1
800C7D60	lhu    v1, $0002(a3)
800C7D64	nop
800C7D68	sltu   v0, a1, v1
800C7D6C	bne    v0, zero, Lc7d7c [$800c7d7c]
800C7D70	sltu   v0, a2, v1

Lc7d74:	; 800C7D74
800C7D74	jr     ra 
800C7D78	addu   v0, zero, zero


Lc7d7c:	; 800C7D7C
800C7D7C	beq    v0, zero, Lc7d74 [$800c7d74]
800C7D80	sll    v0, a1, $08
800C7D84	lw     v1, $000c(a3)
800C7D88	sw     v0, $0008(a3)
800C7D8C	lhu    v0, $0000(a3)
800C7D90	sll    a0, a2, $03
800C7D94	sh     zero, $0006(a3)
800C7D98	addu   v1, t0, v1
800C7D9C	addu   v1, v1, a0

Lc7da0:	; 800C7DA0
800C7DA0	ori    v0, v0, $0005
800C7DA4	sh     v0, $0000(a3)
800C7DA8	addiu  v0, zero, $ffff (=-$1)

funcc7dac:	; 800C7DAC
800C7DAC	sh     v0, $0002(v1)
800C7DB0	lh     v1, $0004(a3)
800C7DB4	nop
800C7DB8	blez   v1, Lc7dc8 [$800c7dc8]
800C7DBC	sltu   v0, a2, a1
800C7DC0	bne    v0, zero, Lc7dd8 [$800c7dd8]
800C7DC4	nop

Lc7dc8:	; 800C7DC8
800C7DC8	bgez   v1, Lc7de8 [$800c7de8]
800C7DCC	sltu   v0, a1, a2
800C7DD0	beq    v0, zero, Lc7de8 [$800c7de8]
800C7DD4	nop

Lc7dd8:	; 800C7DD8
800C7DD8	lhu    v0, $0004(a3)
800C7DDC	nop
800C7DE0	subu   v0, zero, v0
800C7DE4	sh     v0, $0004(a3)

Lc7de8:	; 800C7DE8
800C7DE8	jr     ra 
800C7DEC	addiu  v0, zero, $0001


funcc7df0:	; 800C7DF0
800C7DF0	lui    v0, $800d
800C7DF4	addiu  a2, v0, $9df0 (=-$6210)
800C7DF8	lw     t2, $0008(a2)
800C7DFC	nop
800C7E00	lhu    v0, $002c(t2)
800C7E04	nop
800C7E08	sltu   v0, a0, v0
800C7E0C	bne    v0, zero, Lc7e1c [$800c7e1c]
800C7E10	sll    v0, a0, $04
800C7E14	jr     ra 
800C7E18	addu   v0, zero, zero


Lc7e1c:	; 800C7E1C
800C7E1C	lw     v1, $0020(a2)

Lc7e20:	; 800C7E20
800C7E20	nop
800C7E24	addu   t1, v1, v0

Lc7e28:	; 800C7E28
800C7E28	addiu  v0, zero, $0100
800C7E2C	sh     v0, $0004(t1)
800C7E30	addiu  v0, zero, $0002
800C7E34	sh     v0, $0000(t1)
800C7E38	lw     v0, $000c(t1)
800C7E3C	lhu    v1, $0002(t1)
800C7E40	addu   t0, zero, zero
800C7E44	sw     zero, $0008(t1)
800C7E48	sh     zero, $0006(t1)
800C7E4C	beq    v1, zero, Lc7ee0 [$800c7ee0]
800C7E50	addu   v0, t2, v0
800C7E54	addu   t3, a2, zero
800C7E58	addiu  a3, v0, $0004

loopc7e5c:	; 800C7E5C
800C7E5C	addu   a0, zero, zero
800C7E60	lhu    v0, $0002(a3)
800C7E64	lhu    v1, $0000(a3)
800C7E68	nop
800C7E6C	beq    v1, zero, Lc7ecc [$800c7ecc]
800C7E70	addu   a2, t2, v0

loopc7e74:	; 800C7E74
800C7E74	lw     v0, $0000(a2)
800C7E78	nop
800C7E7C	sll    v1, v0, $02
800C7E80	addu   v1, v1, v0
800C7E84	lw     v0, $0010(t3)
800C7E88	sll    v1, v1, $03
800C7E8C	beq    a1, zero, Lc7ea8 [$800c7ea8]
800C7E90	addu   v1, v0, v1
800C7E94	bne    t0, zero, Lc7ea8 [$800c7ea8]
800C7E98	nop
800C7E9C	lhu    v0, $0000(v1)
800C7EA0	j      Lc7eb4 [$800c7eb4]
800C7EA4	ori    v0, v0, $0001

Lc7ea8:	; 800C7EA8
800C7EA8	lhu    v0, $0000(v1)
800C7EAC	nop
800C7EB0	andi   v0, v0, $fffe

Lc7eb4:	; 800C7EB4
800C7EB4	sh     v0, $0000(v1)

Lc7eb8:	; 800C7EB8
800C7EB8	lhu    v0, $0000(a3)
800C7EBC	addiu  a0, a0, $0001
800C7EC0	slt    v0, a0, v0
800C7EC4	bne    v0, zero, loopc7e74 [$800c7e74]
800C7EC8	addiu  a2, a2, $0004

Lc7ecc:	; 800C7ECC
800C7ECC	lhu    v0, $0002(t1)
800C7ED0	addiu  t0, t0, $0001
800C7ED4	slt    v0, t0, v0
800C7ED8	bne    v0, zero, loopc7e5c [$800c7e5c]
800C7EDC	addiu  a3, a3, $0008

Lc7ee0:	; 800C7EE0
800C7EE0	jr     ra 
800C7EE4	addiu  v0, zero, $0001


funcc7ee8:	; 800C7EE8
800C7EE8	lui    v0, $800d
800C7EEC	addiu  a2, v0, $9df0 (=-$6210)
800C7EF0	lw     v0, $0008(a2)
800C7EF4	nop
800C7EF8	lhu    v0, $002c(v0)
800C7EFC	nop
800C7F00	sltu   v0, a0, v0
800C7F04	beq    v0, zero, Lc7f2c [$800c7f2c]
800C7F08	sll    v1, a0, $04
800C7F0C	lw     v0, $0020(a2)
800C7F10	nop
800C7F14	addu   v0, v0, v1
800C7F18	lw     v1, $0008(v0)
800C7F1C	addiu  v0, zero, $0001
800C7F20	sra    v1, v1, $08
800C7F24	jr     ra 
800C7F28	sw     v1, $0000(a1)


Lc7f2c:	; 800C7F2C
800C7F2C	jr     ra 
800C7F30	addu   v0, zero, zero


funcc7f34:	; 800C7F34
800C7F34	addiu  sp, sp, $ffe8 (=-$18)
800C7F38	sll    v1, a0, $01
800C7F3C	addu   v1, v1, a0
800C7F40	sll    v1, v1, $03
800C7F44	lui    v0, $800d
800C7F48	addiu  v0, v0, $ae98 (=-$5168)
800C7F4C	addu   v1, v1, v0
800C7F50	sw     ra, $0010(sp)
800C7F54	lhu    v0, $0000(v1)
800C7F58	sll    a1, a1, $08
800C7F5C	sw     a1, $0014(v1)
800C7F60	ori    v0, v0, $0005
800C7F64	jal    funcc6eec [$800c6eec]
800C7F68	sh     v0, $0000(v1)
800C7F6C	lw     ra, $0010(sp)
800C7F70	addiu  v0, zero, $0001
800C7F74	jr     ra 
800C7F78	addiu  sp, sp, $0018


funcc7f7c:	; 800C7F7C
800C7F7C	addiu  sp, sp, $ffe8 (=-$18)
800C7F80	sll    v1, a0, $01
800C7F84	addu   v1, v1, a0
800C7F88	sll    v1, v1, $03
800C7F8C	lui    v0, $800d
800C7F90	addiu  v0, v0, $ae98 (=-$5168)
800C7F94	addu   v1, v1, v0
800C7F98	sll    a1, a1, $08

Lc7f9c:	; 800C7F9C
800C7F9C	sw     ra, $0010(sp)
800C7FA0	sw     a1, $0014(v1)
800C7FA4	jal    funcc6eec [$800c6eec]
800C7FA8	sh     zero, $0000(v1)
800C7FAC	lw     ra, $0010(sp)
800C7FB0	addiu  v0, zero, $0001
800C7FB4	jr     ra 
800C7FB8	addiu  sp, sp, $0018


funcc7fbc:	; 800C7FBC
800C7FBC	addiu  sp, sp, $ffe8 (=-$18)
800C7FC0	sw     ra, $0010(sp)
800C7FC4	sll    v1, a0, $01
800C7FC8	addu   v1, v1, a0
800C7FCC	sll    v1, v1, $03
800C7FD0	lui    v0, $800d
800C7FD4	addiu  v0, v0, $ae98 (=-$5168)
800C7FD8	beq    a1, zero, Lc7fec [$800c7fec]
800C7FDC	addu   v1, v1, v0
800C7FE0	lhu    v0, $0000(v1)
800C7FE4	j      Lc7ff8 [$800c7ff8]
800C7FE8	ori    v0, v0, $0005

Lc7fec:	; 800C7FEC
800C7FEC	lhu    v0, $0000(v1)
800C7FF0	nop
800C7FF4	andi   v0, v0, $fffa

Lc7ff8:	; 800C7FF8
800C7FF8	jal    funcc6eec [$800c6eec]
800C7FFC	sh     v0, $0000(v1)
800C8000	lw     ra, $0010(sp)
800C8004	addiu  v0, zero, $0001

Lc8008:	; 800C8008
800C8008	jr     ra 
800C800C	addiu  sp, sp, $0018


funcc8010:	; 800C8010
800C8010	sll    v1, a0, $01
800C8014	addu   v1, v1, a0
800C8018	sll    v1, v1, $03
800C801C	lui    v0, $800d
800C8020	addiu  v0, v0, $ae98 (=-$5168)
800C8024	addu   v1, v1, v0
800C8028	lhu    v0, $0000(v1)
800C802C	andi   a1, a1, $0018
800C8030	andi   v0, v0, $ffe7
800C8034	or     v0, v0, a1
800C8038	sh     v0, $0000(v1)
800C803C	jr     ra 
800C8040	addiu  v0, zero, $0001


funcc8044:	; 800C8044
800C8044	sll    v0, a0, $01
800C8048	addu   v0, v0, a0
800C804C	sll    v0, v0, $03

Lc8050:	; 800C8050
800C8050	lui    v1, $800d
800C8054	addiu  v1, v1, $ae98 (=-$5168)
800C8058	addu   v0, v0, v1
800C805C	sh     a1, $0002(v0)
800C8060	jr     ra 
800C8064	addiu  v0, zero, $0001


funcc8068:	; 800C8068
800C8068	sll    v0, a0, $01
800C806C	addu   v0, v0, a0
800C8070	sll    v0, v0, $03
800C8074	lui    v1, $800d
800C8078	addiu  v1, v1, $ae98 (=-$5168)
800C807C	addu   v0, v0, v1
800C8080	sh     a1, $0012(v0)
800C8084	jr     ra 

Lc8088:	; 800C8088
800C8088	addiu  v0, zero, $0001


funcc808c:	; 800C808C
800C808C	sll    v0, a0, $01
800C8090	addu   v0, v0, a0
800C8094	sll    v0, v0, $03
800C8098	lui    v1, $800d
800C809C	addiu  v1, v1, $ae98 (=-$5168)
800C80A0	addu   v0, v0, v1
800C80A4	sh     a1, $0006(v0)
800C80A8	jr     ra 
800C80AC	addiu  v0, zero, $0001


funcc80b0:	; 800C80B0
800C80B0	sll    v1, a0, $01

Lc80b4:	; 800C80B4
800C80B4	addu   v1, v1, a0
800C80B8	sll    v1, v1, $03
800C80BC	lui    v0, $800d
800C80C0	addiu  v0, v0, $ae98 (=-$5168)

Lc80c4:	; 800C80C4
800C80C4	addu   v1, v1, v0
800C80C8	sh     a1, $0008(v1)
800C80CC	addu   v0, a1, zero
800C80D0	sh     a2, $000a(v1)

Lc80d4:	; 800C80D4
800C80D4	subu   a2, a2, v0
800C80D8	addiu  v0, zero, $0001
800C80DC	jr     ra 
800C80E0	sh     a2, $0010(v1)


funcc80e4:	; 800C80E4
800C80E4	sll    v0, a0, $01
800C80E8	addu   v0, v0, a0
800C80EC	sll    v0, v0, $03
800C80F0	lui    v1, $800d
800C80F4	addiu  v1, v1, $ae98 (=-$5168)
800C80F8	addu   v0, v0, v1
800C80FC	sh     a1, $0004(v0)

Lc8100:	; 800C8100
800C8100	jr     ra 
800C8104	addiu  v0, zero, $0001

800C8108	sll    v1, a0, $01
800C810C	addu   v1, v1, a0
800C8110	sll    v1, v1, $03
800C8114	lui    v0, $800d
800C8118	addiu  v0, v0, $ae98 (=-$5168)
800C811C	jr     ra 
800C8120	addu   v0, v1, v0


funcc8124:	; 800C8124
800C8124	lui    v0, $8006
800C8128	lw     v0, $794c(v0)
800C812C	addiu  sp, sp, $ffd8 (=-$28)
800C8130	sw     ra, $0020(sp)
800C8134	sw     s3, $001c(sp)
800C8138	sw     s2, $0018(sp)
800C813C	sw     s1, $0014(sp)
800C8140	sw     s0, $0010(sp)
800C8144	lw     v0, $001c(v0)
800C8148	nop
800C814C	lw     a0, $080c(v0)
800C8150	nop
800C8154	beq    a0, zero, Lc816c [$800c816c]
800C8158	addiu  v0, zero, $00ff
800C815C	lbu    v1, $0000(a0)
800C8160	nop
800C8164	bne    v1, v0, Lc8174 [$800c8174]
800C8168	addu   v0, a0, zero

Lc816c:	; 800C816C
800C816C	jal    func35774 [$80035774]
800C8170	addiu  a0, zero, $0001

Lc8174:	; 800C8174
800C8174	addu   a0, v0, zero
800C8178	jal    func2b980 [$8002b980]
800C817C	addu   a1, zero, zero
800C8180	addiu  a0, v0, $0010
800C8184	slti   v0, a0, $0044
800C8188	beq    v0, zero, Lc8194 [$800c8194]
800C818C	addu   s3, zero, zero
800C8190	addiu  a0, zero, $0044

Lc8194:	; 800C8194
800C8194	lui    v0, $800d
800C8198	addiu  v0, v0, $b188 (=-$4e78)
800C819C	addiu  s2, v0, $0008
800C81A0	lui    v1, $800d
800C81A4	addiu  v1, v1, $9e20 (=-$61e0)
800C81A8	addu   s0, v1, zero
800C81AC	addu   s1, v0, zero
800C81B0	addiu  v0, zero, $0134
800C81B4	subu   v0, v0, a0
800C81B8	sh     a0, $002c(s0)
800C81BC	sh     v0, $0028(s0)

loopc81c0:	; 800C81C0
800C81C0	lwl    a3, $0003(s0)
800C81C4	lwr    a3, $0000(s0)
800C81C8	lwl    t0, $0007(s0)
800C81CC	lwr    t0, $0004(s0)
800C81D0	swl    a3, $000f(s1)
800C81D4	swr    a3, $000c(s1)
800C81D8	swl    t0, $0013(s1)
800C81DC	swr    t0, $0010(s1)
800C81E0	addu   a0, s2, zero
800C81E4	addu   a1, zero, zero
800C81E8	jal    func63118 [$80063118]
800C81EC	addu   a2, a1, zero
800C81F0	addiu  s2, s2, $0010
800C81F4	addiu  s0, s0, $0008
800C81F8	addiu  s3, s3, $0001
800C81FC	slti   v0, s3, $0006
800C8200	bne    v0, zero, loopc81c0 [$800c81c0]
800C8204	addiu  s1, s1, $0010
800C8208	lui    v0, $8007
800C820C	lbu    v0, $7e51(v0)
800C8210	nop
800C8214	beq    v0, zero, Lc8268 [$800c8268]
800C8218	lui    s1, $800d
800C821C	addiu  s1, s1, $b190 (=-$4e70)
800C8220	addu   a0, s1, zero
800C8224	lui    s0, $800d
800C8228	addiu  s0, s0, $9e60 (=-$61a0)
800C822C	addu   a1, s0, zero
800C8230	jal    func63118 [$80063118]
800C8234	addiu  a2, zero, $0001
800C8238	addiu  a0, s1, $0010
800C823C	addiu  a1, s0, $0010
800C8240	jal    func63118 [$80063118]
800C8244	addiu  a2, zero, $0001
800C8248	addiu  a0, s1, $0020
800C824C	addiu  a1, s0, $0020
800C8250	jal    func63118 [$80063118]

Lc8254:	; 800C8254
800C8254	addiu  a2, zero, $0001
800C8258	addiu  a0, s1, $0030
800C825C	addiu  a1, s0, $0030
800C8260	jal    func63118 [$80063118]
800C8264	addiu  a2, zero, $0001

Lc8268:	; 800C8268
800C8268	lw     ra, $0020(sp)
800C826C	lw     s3, $001c(sp)

Lc8270:	; 800C8270
800C8270	lw     s2, $0018(sp)
800C8274	lw     s1, $0014(sp)
800C8278	lw     s0, $0010(sp)
800C827C	jr     ra 
800C8280	addiu  sp, sp, $0028

800C8284	addiu  sp, sp, $ffe8 (=-$18)
800C8288	lui    v0, $8007
800C828C	lw     v1, $7528(v0)
800C8290	lui    v0, $0001
800C8294	and    v0, v1, v0
800C8298	beq    v0, zero, Lc82b8 [$800c82b8]
800C829C	sw     ra, $0010(sp)
800C82A0	jal    func2f488 [$8002f488]

Lc82a4:	; 800C82A4
800C82A4	addiu  a0, zero, $0065
800C82A8	jal    func362c8 [$800362c8]
800C82AC	nop
800C82B0	j      Lc8344 [$800c8344]
800C82B4	nop

Lc82b8:	; 800C82B8
800C82B8	lui    v0, $0002
800C82BC	and    v0, v1, v0
800C82C0	beq    v0, zero, Lc82d8 [$800c82d8]
800C82C4	andi   v0, v1, $0010
800C82C8	jal    funcc923c [$800c923c]
800C82CC	nop
800C82D0	j      Lc8344 [$800c8344]
800C82D4	nop

Lc82d8:	; 800C82D8
800C82D8	beq    v0, zero, Lc8310 [$800c8310]
800C82DC	nop
800C82E0	jal    func2f488 [$8002f488]
800C82E4	addiu  a0, zero, $0067
800C82E8	lui    v0, $800d
800C82EC	lbu    v1, $b188(v0)
800C82F0	nop
800C82F4	beq    v1, zero, Lc8304 [$800c8304]
800C82F8	addiu  v0, v0, $b188 (=-$4e78)

Lc82fc:	; 800C82FC
800C82FC	j      Lc8308 [$800c8308]
800C8300	addiu  v1, v1, $ffff (=-$1)

Lc8304:	; 800C8304
800C8304	addiu  v1, zero, $0006

Lc8308:	; 800C8308
800C8308	j      Lc8344 [$800c8344]
800C830C	sb     v1, $0000(v0)

Lc8310:	; 800C8310
800C8310	andi   v0, v1, $0040
800C8314	beq    v0, zero, Lc8344 [$800c8344]
800C8318	nop
800C831C	jal    func2f488 [$8002f488]
800C8320	addiu  a0, zero, $0067
800C8324	lui    v0, $800d
800C8328	lbu    v1, $b188(v0)
800C832C	addiu  a0, v0, $b188 (=-$4e78)
800C8330	sltiu  v0, v1, $0006
800C8334	bne    v0, zero, Lc8340 [$800c8340]
800C8338	addiu  v0, v1, $0001
800C833C	addu   v0, zero, zero

Lc8340:	; 800C8340
800C8340	sb     v0, $0000(a0)

Lc8344:	; 800C8344
800C8344	lw     ra, $0010(sp)

Lc8348:	; 800C8348
800C8348	nop
800C834C	jr     ra 
800C8350	addiu  sp, sp, $0018

800C8354	addiu  sp, sp, $ffe0 (=-$20)
800C8358	lui    v0, $8007

Lc835c:	; 800C835C
800C835C	lw     v1, $7528(v0)
800C8360	lui    v0, $0001
800C8364	sw     ra, $001c(sp)

Lc8368:	; 800C8368
800C8368	sw     s2, $0018(sp)
800C836C	sw     s1, $0014(sp)

Lc8370:	; 800C8370
800C8370	and    v0, v1, v0
800C8374	beq    v0, zero, Lc8390 [$800c8390]
800C8378	sw     s0, $0010(sp)
800C837C	jal    func2f488 [$8002f488]
800C8380	addiu  a0, zero, $0065
800C8384	lui    v0, $800d
800C8388	j      Lc8414 [$800c8414]
800C838C	sb     zero, $b189(v0)

Lc8390:	; 800C8390
800C8390	lui    v0, $0002
800C8394	and    v0, v1, v0
800C8398	beq    v0, zero, Lc83c0 [$800c83c0]
800C839C	andi   v0, v1, $0010
800C83A0	jal    func2f488 [$8002f488]
800C83A4	addiu  a0, zero, $0067
800C83A8	lui    v0, $800d
800C83AC	lbu    a0, $b188(v0)
800C83B0	jal    func361cc [$800361cc]
800C83B4	addiu  a0, a0, $0001
800C83B8	j      Lc8414 [$800c8414]
800C83BC	nop

Lc83c0:	; 800C83C0
800C83C0	beq    v0, zero, Lc83e0 [$800c83e0]
800C83C4	lui    v0, $8007
800C83C8	addiu  s2, v0, $7e50
800C83CC	lbu    s0, $0003(s2)
800C83D0	jal    func337d0 [$800337d0]
800C83D4	addu   a0, s0, zero
800C83D8	j      Lc8400 [$800c8400]
800C83DC	addu   s1, v0, zero

Lc83e0:	; 800C83E0
800C83E0	andi   v0, v1, $0040

Lc83e4:	; 800C83E4
800C83E4	beq    v0, zero, Lc8414 [$800c8414]
800C83E8	lui    v0, $8007
800C83EC	addiu  s2, v0, $7e50
800C83F0	lbu    s0, $0003(s2)
800C83F4	jal    func3380c [$8003380c]
800C83F8	addu   a0, s0, zero
800C83FC	addu   s1, v0, zero

Lc8400:	; 800C8400
800C8400	beq    s0, s1, Lc8414 [$800c8414]
800C8404	nop
800C8408	jal    func2f488 [$8002f488]
800C840C	addiu  a0, zero, $0067
800C8410	sb     s1, $0003(s2)

Lc8414:	; 800C8414
800C8414	lw     ra, $001c(sp)
800C8418	lw     s2, $0018(sp)
800C841C	lw     s1, $0014(sp)
800C8420	lw     s0, $0010(sp)
800C8424	jr     ra 
800C8428	addiu  sp, sp, $0020

800C842C	addiu  sp, sp, $ffe8 (=-$18)

Lc8430:	; 800C8430
800C8430	lui    v0, $8007
800C8434	lw     v1, $7528(v0)
800C8438	lui    v0, $0001
800C843C	sw     ra, $0014(sp)
800C8440	and    v0, v1, v0
800C8444	beq    v0, zero, Lc847c [$800c847c]
800C8448	sw     s0, $0010(sp)

Lc844c:	; 800C844C
800C844C	jal    func2f488 [$8002f488]
800C8450	addiu  a0, zero, $0065
800C8454	lui    v0, $800d
800C8458	addiu  v1, v0, $b188 (=-$4e78)
800C845C	lbu    v0, $0004(v1)
800C8460	nop
800C8464	bne    v0, zero, Lc8474 [$800c8474]
800C8468	nop
800C846C	j      Lc85a8 [$800c85a8]
800C8470	sb     zero, $0001(v1)

Lc8474:	; 800C8474
800C8474	j      Lc85a8 [$800c85a8]
800C8478	sb     zero, $0004(v1)

Lc847c:	; 800C847C
800C847C	andi   v0, v1, $0010
800C8480	beq    v0, zero, Lc84e0 [$800c84e0]
800C8484	andi   v0, v1, $0040

Lc8488:	; 800C8488
800C8488	jal    func2f488 [$8002f488]
800C848C	addiu  a0, zero, $0067
800C8490	lui    v0, $800d
800C8494	addiu  v1, v0, $b188 (=-$4e78)
800C8498	lbu    v0, $0004(v1)
800C849C	nop

Lc84a0:	; 800C84A0
800C84A0	bne    v0, zero, Lc84c4 [$800c84c4]
800C84A4	addu   v0, v1, zero
800C84A8	lbu    a0, $0002(v1)
800C84AC	nop
800C84B0	bne    a0, zero, Lc84bc [$800c84bc]
800C84B4	addiu  v1, a0, $ffff (=-$1)
800C84B8	addiu  v1, zero, $0003

Lc84bc:	; 800C84BC
800C84BC	j      Lc85a8 [$800c85a8]
800C84C0	sb     v1, $0002(v0)

Lc84c4:	; 800C84C4
800C84C4	lbu    v1, $0003(v0)
800C84C8	nop
800C84CC	bne    v1, zero, Lc84d8 [$800c84d8]
800C84D0	addiu  v1, v1, $ffff (=-$1)
800C84D4	addiu  v1, zero, $0003

Lc84d8:	; 800C84D8
800C84D8	j      Lc85a8 [$800c85a8]
800C84DC	sb     v1, $0003(v0)

Lc84e0:	; 800C84E0
800C84E0	beq    v0, zero, Lc8548 [$800c8548]
800C84E4	lui    v0, $0002
800C84E8	jal    func2f488 [$8002f488]
800C84EC	addiu  a0, zero, $0067
800C84F0	lui    v0, $800d
800C84F4	addiu  v1, v0, $b188 (=-$4e78)
800C84F8	lbu    v0, $0004(v1)
800C84FC	nop
800C8500	bne    v0, zero, Lc8528 [$800c8528]
800C8504	addu   a0, v1, zero
800C8508	lbu    a0, $0002(v1)
800C850C	nop
800C8510	sltiu  v0, a0, $0003
800C8514	bne    v0, zero, Lc8520 [$800c8520]
800C8518	addiu  v0, a0, $0001
800C851C	addu   v0, zero, zero

Lc8520:	; 800C8520
800C8520	j      Lc85a8 [$800c85a8]
800C8524	sb     v0, $0002(v1)

Lc8528:	; 800C8528
800C8528	lbu    v1, $0003(a0)
800C852C	nop
800C8530	sltiu  v0, v1, $0003
800C8534	bne    v0, zero, Lc8540 [$800c8540]
800C8538	addiu  v0, v1, $0001
800C853C	addu   v0, zero, zero

Lc8540:	; 800C8540
800C8540	j      Lc85a8 [$800c85a8]
800C8544	sb     v0, $0003(a0)

Lc8548:	; 800C8548
800C8548	and    v0, v1, v0
800C854C	beq    v0, zero, Lc85a8 [$800c85a8]
800C8550	lui    v0, $800d
800C8554	addiu  s0, v0, $b188 (=-$4e78)
800C8558	lbu    v0, $0004(s0)
800C855C	nop
800C8560	bne    v0, zero, Lc8584 [$800c8584]
800C8564	nop
800C8568	jal    func2f488 [$8002f488]
800C856C	addiu  a0, zero, $0067
800C8570	lbu    v1, $0002(s0)
800C8574	addiu  v0, zero, $0001
800C8578	sb     v0, $0004(s0)
800C857C	j      Lc85a8 [$800c85a8]
800C8580	sb     v1, $0003(s0)

Lc8584:	; 800C8584
800C8584	jal    func2f488 [$8002f488]
800C8588	addiu  a0, zero, $0067
800C858C	lbu    a0, $0002(s0)
800C8590	lbu    a1, $0003(s0)
800C8594	jal    funcc85b8 [$800c85b8]
800C8598	nop
800C859C	lbu    v0, $0003(s0)

Lc85a0:	; 800C85A0
800C85A0	sb     zero, $0004(s0)
800C85A4	sb     v0, $0002(s0)

Lc85a8:	; 800C85A8
800C85A8	lw     ra, $0014(sp)
800C85AC	lw     s0, $0010(sp)
800C85B0	jr     ra 
800C85B4	addiu  sp, sp, $0018


funcc85b8:	; 800C85B8
800C85B8	addiu  sp, sp, $ffe0 (=-$20)
800C85BC	addu   t1, a0, zero
800C85C0	addu   t0, a1, zero
800C85C4	sw     ra, $0018(sp)

Lc85c8:	; 800C85C8
800C85C8	sw     s1, $0014(sp)
800C85CC	bne    t1, t0, Lc8624 [$800c8624]
800C85D0	sw     s0, $0010(sp)
800C85D4	lui    v0, $8006
800C85D8	lw     v0, $794c(v0)
800C85DC	nop
800C85E0	lw     v0, $001c(v0)
800C85E4	sll    v1, t0, $02
800C85E8	addu   v0, v0, v1
800C85EC	lw     a0, $054c(v0)
800C85F0	nop
800C85F4	beq    a0, zero, Lc86b4 [$800c86b4]

Lc85f8:	; 800C85F8
800C85F8	addiu  v1, zero, $fdff (=-$201)
800C85FC	lw     v0, $0034(a0)
800C8600	nop
800C8604	and    v1, v0, v1
800C8608	srl    v0, v0, $09
800C860C	andi   v0, v0, $0001
800C8610	xori   v0, v0, $0001
800C8614	sll    v0, v0, $09
800C8618	or     v1, v1, v0
800C861C	j      Lc86b4 [$800c86b4]
800C8620	sw     v1, $0034(a0)

Lc8624:	; 800C8624
800C8624	lui    s0, $8006
800C8628	lui    a1, $800d
800C862C	addiu  a1, a1, $b188 (=-$4e78)
800C8630	lbu    a0, $0002(a1)
800C8634	lw     a3, $794c(s0)
800C8638	lbu    v0, $0003(a1)
800C863C	sll    a0, a0, $02
800C8640	lw     v1, $001c(a3)
800C8644	sll    v0, v0, $02
800C8648	addu   a0, v1, a0
800C864C	addu   v1, v1, v0
800C8650	lw     v0, $054c(v1)
800C8654	lw     a2, $054c(a0)
800C8658	sw     v0, $054c(a0)
800C865C	addu   a0, t1, zero
800C8660	lbu    v0, $0003(a1)
800C8664	addu   a1, t0, zero
800C8668	lw     v1, $001c(a3)
800C866C	sll    v0, v0, $02
800C8670	addu   v1, v1, v0
800C8674	jal    funcc86c8 [$800c86c8]
800C8678	sw     a2, $054c(v1)
800C867C	lui    v0, $8007
800C8680	addiu  s1, v0, $7e50
800C8684	lw     v1, $794c(s0)
800C8688	lbu    v0, $0003(s1)
800C868C	lw     v1, $001c(v1)
800C8690	sll    v0, v0, $02
800C8694	addu   v1, v1, v0

Lc8698:	; 800C8698
800C8698	lw     v0, $054c(v1)
800C869C	nop
800C86A0	bne    v0, zero, Lc86b4 [$800c86b4]
800C86A4	nop
800C86A8	jal    func3378c [$8003378c]
800C86AC	nop
800C86B0	sb     v0, $0003(s1)

Lc86b4:	; 800C86B4
800C86B4	lw     ra, $0018(sp)
800C86B8	lw     s1, $0014(sp)
800C86BC	lw     s0, $0010(sp)
800C86C0	jr     ra 
800C86C4	addiu  sp, sp, $0020


funcc86c8:	; 800C86C8
800C86C8	addiu  sp, sp, $ffa0 (=-$60)
800C86CC	sw     s0, $0040(sp)
800C86D0	addu   s0, a1, zero
800C86D4	addiu  a1, sp, $0010
800C86D8	sw     s2, $0048(sp)
800C86DC	addiu  s2, sp, $0018
800C86E0	addu   a2, s2, zero

Lc86e4:	; 800C86E4
800C86E4	sw     s3, $004c(sp)
800C86E8	addiu  s3, sp, $0020

Lc86ec:	; 800C86EC
800C86EC	addu   a3, s3, zero
800C86F0	sw     ra, $0058(sp)
800C86F4	sw     s5, $0054(sp)
800C86F8	sw     s4, $0050(sp)
800C86FC	jal    func28a40 [$80028a40]
800C8700	sw     s1, $0044(sp)
800C8704	addu   a0, s0, zero
800C8708	addiu  s1, sp, $0028
800C870C	addu   a1, s1, zero
800C8710	addiu  s4, sp, $0030
800C8714	addu   a2, s4, zero
800C8718	addiu  s5, sp, $0038
800C871C	jal    func28a40 [$80028a40]

Lc8720:	; 800C8720
800C8720	addu   a3, s5, zero
800C8724	addiu  a0, sp, $0010
800C8728	lui    s0, $8007
800C872C	addiu  s0, s0, $6f80
800C8730	jal    func133b0 [$800133b0]
800C8734	addu   a1, s0, zero

Lc8738:	; 800C8738
800C8738	jal    func130a4 [$800130a4]
800C873C	addu   a0, zero, zero
800C8740	addu   a0, s2, zero
800C8744	addiu  a1, zero, $03c0
800C8748	jal    func13410 [$80013410]
800C874C	addiu  a2, zero, $01b0
800C8750	jal    func130a4 [$800130a4]
800C8754	addu   a0, zero, zero
800C8758	addu   a0, s3, zero
800C875C	addiu  a1, zero, $03d0
800C8760	jal    func13410 [$80013410]
800C8764	addiu  a2, zero, $01b0

Lc8768:	; 800C8768
800C8768	jal    func130a4 [$800130a4]
800C876C	addu   a0, zero, zero
800C8770	lh     a1, $0010(sp)
800C8774	lh     a2, $0012(sp)

Lc8778:	; 800C8778
800C8778	jal    func13410 [$80013410]
800C877C	addu   a0, s1, zero

Lc8780:	; 800C8780
800C8780	jal    func130a4 [$800130a4]
800C8784	addu   a0, zero, zero
800C8788	lh     a1, $0018(sp)
800C878C	lh     a2, $001a(sp)
800C8790	jal    func13410 [$80013410]

Lc8794:	; 800C8794
800C8794	addu   a0, s4, zero
800C8798	jal    func130a4 [$800130a4]
800C879C	addu   a0, zero, zero
800C87A0	lh     a1, $0020(sp)
800C87A4	lh     a2, $0022(sp)
800C87A8	jal    func13410 [$80013410]
800C87AC	addu   a0, s5, zero
800C87B0	jal    func130a4 [$800130a4]
800C87B4	addu   a0, zero, zero
800C87B8	addu   a0, s1, zero
800C87BC	addu   a1, s0, zero
800C87C0	addiu  v0, zero, $03c0
800C87C4	addiu  v1, zero, $01b0
800C87C8	sh     v0, $0018(sp)
800C87CC	addiu  v0, zero, $03d0
800C87D0	sh     v1, $001a(sp)
800C87D4	sh     v0, $0020(sp)
800C87D8	jal    func13350 [$80013350]
800C87DC	sh     v1, $0022(sp)
800C87E0	jal    func130a4 [$800130a4]
800C87E4	addu   a0, zero, zero
800C87E8	lh     a1, $0030(sp)
800C87EC	lh     a2, $0032(sp)
800C87F0	jal    func13410 [$80013410]
800C87F4	addu   a0, s2, zero
800C87F8	jal    func130a4 [$800130a4]

Lc87fc:	; 800C87FC
800C87FC	addu   a0, zero, zero
800C8800	lh     a1, $0038(sp)
800C8804	lh     a2, $003a(sp)
800C8808	jal    func13410 [$80013410]
800C880C	addu   a0, s3, zero
800C8810	jal    func130a4 [$800130a4]
800C8814	addu   a0, zero, zero
800C8818	lw     ra, $0058(sp)
800C881C	lw     s5, $0054(sp)
800C8820	lw     s4, $0050(sp)
800C8824	lw     s3, $004c(sp)
800C8828	lw     s2, $0048(sp)
800C882C	lw     s1, $0044(sp)
800C8830	lw     s0, $0040(sp)

Lc8834:	; 800C8834
800C8834	jr     ra 
800C8838	addiu  sp, sp, $0060


funcc883c:	; 800C883C
800C883C	addiu  sp, sp, $ffc8 (=-$38)
800C8840	addu   a3, a0, zero
800C8844	lui    v0, $8006
800C8848	lw     v0, $794c(v0)
800C884C	sll    a0, a3, $04
800C8850	sw     ra, $0034(sp)
800C8854	sw     s2, $0030(sp)
800C8858	sw     s1, $002c(sp)
800C885C	sw     s0, $0028(sp)
800C8860	lw     v1, $001c(v0)
800C8864	sll    v0, a3, $02
800C8868	addu   v1, v1, v0
800C886C	lui    v0, $800d
800C8870	addiu  v0, v0, $b194 (=-$4e6c)

Lc8874:	; 800C8874
800C8874	addu   s0, a0, v0
800C8878	lw     s2, $054c(v1)

Lc887c:	; 800C887C
800C887C	lh     v1, $0000(s0)
800C8880	lw     v0, $0034(s2)

Lc8884:	; 800C8884
800C8884	nop
800C8888	srl    v0, v0, $09
800C888C	andi   v0, v0, $0001
800C8890	bne    v0, zero, Lc889c [$800c889c]
800C8894	addiu  a0, v1, $0008

Lc8898:	; 800C8898
800C8898	addiu  a0, v1, $0016

Lc889c:	; 800C889C
800C889C	addiu  a2, zero, $0014
800C88A0	lh     a1, $0002(s0)
800C88A4	addiu  v0, zero, $002d
800C88A8	sw     v0, $0010(sp)

Lc88ac:	; 800C88AC
800C88AC	lhu    v0, $0010(s2)
800C88B0	addiu  a1, a1, $0001
800C88B4	sltiu  v0, v0, $0001

Lc88b8:	; 800C88B8
800C88B8	jal    func283e0 [$800283e0]
800C88BC	sw     v0, $0014(sp)
800C88C0	addiu  a2, zero, $0014
800C88C4	lh     a0, $0000(s0)
800C88C8	lh     a1, $0002(s0)
800C88CC	addu   a3, s2, zero
800C88D0	sw     zero, $0010(sp)
800C88D4	addiu  a0, a0, $003c
800C88D8	jal    func2b5fc [$8002b5fc]
800C88DC	addiu  a1, a1, $0003
800C88E0	lh     a0, $0000(s0)
800C88E4	lh     a1, $0002(s0)
800C88E8	lbu    a3, $0038(s2)
800C88EC	addiu  a2, zero, $0014
800C88F0	sw     zero, $0010(sp)
800C88F4	addiu  a0, a0, $0086
800C88F8	jal    func26fc4 [$80026fc4]
800C88FC	addiu  a1, a1, $0004
800C8900	addiu  a1, sp, $0018
800C8904	addiu  a2, zero, $0002
800C8908	lbu    a0, $000b(s2)
800C890C	jal    func2bae4 [$8002bae4]

Lc8910:	; 800C8910
800C8910	addiu  a3, zero, $0001
800C8914	addiu  a2, zero, $0014
800C8918	lh     a0, $0000(s0)
800C891C	lh     a1, $0002(s0)
800C8920	addiu  a3, zero, $00b4
800C8924	sw     zero, $0010(sp)
800C8928	addiu  a0, a0, $003c
800C892C	jal    func275dc [$800275dc]
800C8930	addiu  a1, a1, $0012
800C8934	addiu  a2, zero, $0014
800C8938	lh     a0, $0000(s0)
800C893C	lh     a1, $0002(s0)
800C8940	addiu  a3, sp, $0018
800C8944	sw     zero, $0010(sp)
800C8948	addiu  a0, a0, $0060
800C894C	jal    func2b56c [$8002b56c]
800C8950	addiu  a1, a1, $0012
800C8954	addiu  a2, zero, $0014
800C8958	lh     a0, $0000(s0)
800C895C	lh     a1, $0002(s0)
800C8960	addiu  a3, zero, $00af
800C8964	sw     zero, $0010(sp)
800C8968	addiu  a0, a0, $003c
800C896C	jal    func275dc [$800275dc]
800C8970	addiu  a1, a1, $001b
800C8974	addiu  a1, sp, $0018
800C8978	addiu  a2, zero, $0004
800C897C	lhu    a0, $0010(s2)
800C8980	jal    func2bae4 [$8002bae4]
800C8984	addiu  a3, zero, $0001
800C8988	addiu  v0, zero, $002f
800C898C	sb     v0, $001c(sp)
800C8990	lhu    a0, $0010(s2)
800C8994	nop
800C8998	beq    a0, zero, Lc89cc [$800c89cc]
800C899C	nop
800C89A0	lhu    v1, $0018(s2)
800C89A4	lui    v0, $aaaa
800C89A8	ori    v0, v0, $aaab

Lc89ac:	; 800C89AC
800C89AC	multu  v1, v0
800C89B0	mfhi   t0

Lc89b4:	; 800C89B4
800C89B4	srl    v0, t0, $02
800C89B8	andi   v0, v0, $ffff
800C89BC	sltu   v0, v0, a0
800C89C0	xori   v0, v0, $0001
800C89C4	j      Lc89d0 [$800c89d0]
800C89C8	sll    s1, v0, $02

Lc89cc:	; 800C89CC
800C89CC	addiu  s1, zero, $0003

Lc89d0:	; 800C89D0
800C89D0	addiu  a1, sp, $001d
800C89D4	addiu  a2, zero, $ffff (=-$1)

Lc89d8:	; 800C89D8
800C89D8	lhu    a0, $0018(s2)
800C89DC	jal    func2bae4 [$8002bae4]
800C89E0	addiu  a3, zero, $0001
800C89E4	addiu  a2, zero, $0014
800C89E8	lh     a0, $0000(s0)
800C89EC	lh     a1, $0002(s0)
800C89F0	addiu  a3, sp, $0018
800C89F4	sw     s1, $0010(sp)
800C89F8	addiu  a0, a0, $0052
800C89FC	jal    func2b56c [$8002b56c]
800C8A00	addiu  a1, a1, $001b
800C8A04	addiu  a2, zero, $0014
800C8A08	lh     a0, $0000(s0)
800C8A0C	lh     a1, $0002(s0)
800C8A10	addiu  a3, zero, $00b0
800C8A14	sw     zero, $0010(sp)
800C8A18	addiu  a0, a0, $003c
800C8A1C	jal    func275dc [$800275dc]
800C8A20	addiu  a1, a1, $0024
800C8A24	addiu  a1, sp, $0018
800C8A28	addiu  a2, zero, $0003
800C8A2C	lh     a0, $0012(s2)
800C8A30	jal    func2bae4 [$8002bae4]
800C8A34	addiu  a3, zero, $0001
800C8A38	lui    v1, $2aaa

funcc8a3c:	; 800C8A3C
800C8A3C	addiu  v0, zero, $002f
800C8A40	sb     v0, $001b(sp)
800C8A44	lhu    v0, $001a(s2)
800C8A48	ori    v1, v1, $aaab
800C8A4C	sll    v0, v0, $10
800C8A50	sra    a0, v0, $10
800C8A54	mult   a0, v1
800C8A58	addiu  a1, sp, $001c
800C8A5C	addiu  a2, zero, $ffff (=-$1)
800C8A60	addiu  a3, zero, $0001
800C8A64	sra    v0, v0, $1f
800C8A68	lh     v1, $0012(s2)
800C8A6C	mfhi   t0
800C8A70	subu   v0, t0, v0
800C8A74	sll    v0, v0, $10
800C8A78	sra    v0, v0, $10
800C8A7C	slt    v0, v0, v1
800C8A80	xor    v0, v0, a3
800C8A84	jal    func2bae4 [$8002bae4]
800C8A88	sll    s1, v0, $02
800C8A8C	addiu  a2, zero, $0014
800C8A90	lh     a0, $0000(s0)
800C8A94	lh     a1, $0002(s0)
800C8A98	addiu  a3, sp, $0018
800C8A9C	sw     s1, $0010(sp)
800C8AA0	addiu  a0, a0, $0059
800C8AA4	jal    func2b56c [$8002b56c]
800C8AA8	addiu  a1, a1, $0024
800C8AAC	addiu  a2, zero, $0014
800C8AB0	lh     a0, $0000(s0)
800C8AB4	lh     a1, $0002(s0)
800C8AB8	lbu    a3, $0017(s2)
800C8ABC	lbu    v0, $001f(s2)
800C8AC0	addiu  a0, a0, $009b
800C8AC4	addu   a1, a1, a2
800C8AC8	jal    func273c0 [$800273c0]
800C8ACC	sw     v0, $0010(sp)
800C8AD0	lw     ra, $0034(sp)

Lc8ad4:	; 800C8AD4
800C8AD4	lw     s2, $0030(sp)
800C8AD8	lw     s1, $002c(sp)
800C8ADC	lw     s0, $0028(sp)
800C8AE0	jr     ra 
800C8AE4	addiu  sp, sp, $0038


funcc8ae8:	; 800C8AE8
800C8AE8	addiu  sp, sp, $ffd8 (=-$28)
800C8AEC	lui    a3, $0030
800C8AF0	ori    a3, a3, $002e
800C8AF4	sw     s2, $0018(sp)
800C8AF8	lui    s2, $00ff
800C8AFC	sw     s3, $001c(sp)
800C8B00	lui    s3, $8007
800C8B04	addiu  v0, zero, $0003
800C8B08	lw     v1, $7170(s3)
800C8B0C	ori    s2, s2, $ffff
800C8B10	sw     s4, $0020(sp)
800C8B14	lui    s4, $8007
800C8B18	sw     s0, $0010(sp)
800C8B1C	sll    s0, a1, $02
800C8B20	sw     s1, $0014(sp)
800C8B24	lui    s1, $ff00
800C8B28	sw     ra, $0024(sp)
800C8B2C	sb     v0, $0003(v1)

Lc8b30:	; 800C8B30
800C8B30	lw     a2, $7170(s3)
800C8B34	lui    v0, $6200
800C8B38	sw     v0, $0004(a2)
800C8B3C	lh     v0, $0000(a0)

Lc8b40:	; 800C8B40
800C8B40	lh     v1, $0002(a0)
800C8B44	addiu  a1, zero, $0001
800C8B48	sw     a3, $000c(a2)
800C8B4C	lw     a3, $716c(s4)
800C8B50	addiu  a0, a2, $0010
800C8B54	sw     a0, $7170(s3)
800C8B58	addiu  v0, v0, $0008
800C8B5C	andi   v0, v0, $ffff
800C8B60	sll    v1, v1, $10
800C8B64	or     v0, v0, v1
800C8B68	lw     v1, $0000(a2)
800C8B6C	addu   a3, s0, a3

Lc8b70:	; 800C8B70
800C8B70	sw     v0, $0008(a2)
800C8B74	lw     v0, $0000(a3)
800C8B78	and    v1, v1, s1
800C8B7C	and    v0, v0, s2
800C8B80	or     v1, v1, v0
800C8B84	sw     v1, $0000(a2)
800C8B88	lw     v0, $0000(a3)
800C8B8C	and    a2, a2, s2
800C8B90	and    v0, v0, s1
800C8B94	or     v0, v0, a2
800C8B98	addu   a2, a1, zero

Lc8b9c:	; 800C8B9C
800C8B9C	sw     v0, $0000(a3)
800C8BA0	jal    func2420c [$8002420c]
800C8BA4	addu   a3, zero, zero
800C8BA8	lw     v0, $716c(s4)
800C8BAC	lw     a0, $7170(s3)

Lc8bb0:	; 800C8BB0
800C8BB0	addu   s0, s0, v0
800C8BB4	lw     v1, $0000(a0)

Lc8bb8:	; 800C8BB8
800C8BB8	lw     v0, $0000(s0)
800C8BBC	and    v1, v1, s1
800C8BC0	and    v0, v0, s2
800C8BC4	or     v1, v1, v0
800C8BC8	sw     v1, $0000(a0)
800C8BCC	addiu  v1, a0, $0008
800C8BD0	lw     v0, $0000(s0)
800C8BD4	and    a0, a0, s2
800C8BD8	sw     v1, $7170(s3)
800C8BDC	and    v0, v0, s1
800C8BE0	or     v0, v0, a0
800C8BE4	sw     v0, $0000(s0)
800C8BE8	lw     ra, $0024(sp)
800C8BEC	lw     s4, $0020(sp)
800C8BF0	lw     s3, $001c(sp)
800C8BF4	lw     s2, $0018(sp)
800C8BF8	lw     s1, $0014(sp)
800C8BFC	lw     s0, $0010(sp)
800C8C00	jr     ra 

Lc8c04:	; 800C8C04
800C8C04	addiu  sp, sp, $0028


funcc8c08:	; 800C8C08
800C8C08	addiu  sp, sp, $ffc8 (=-$38)
800C8C0C	sw     ra, $0030(sp)
800C8C10	sw     s1, $002c(sp)
800C8C14	jal    func24030 [$80024030]
800C8C18	sw     s0, $0028(sp)
800C8C1C	lui    s0, $800d
800C8C20	addiu  a2, zero, $0013
800C8C24	lw     v1, $9ea0(s0)
800C8C28	addiu  a3, zero, $00b1
800C8C2C	lh     a0, $0000(v1)
800C8C30	lh     a1, $0002(v1)
800C8C34	addu   s1, v0, zero
800C8C38	sw     zero, $0010(sp)
800C8C3C	addiu  a0, a0, $0006
800C8C40	jal    func275dc [$800275dc]
800C8C44	addiu  a1, a1, $0008
800C8C48	lw     v0, $9ea0(s0)
800C8C4C	addiu  a2, zero, $0013

Lc8c50:	; 800C8C50
800C8C50	lh     a0, $0000(v0)
800C8C54	lh     a1, $0002(v0)
800C8C58	addiu  a3, zero, $00b2

Lc8c5c:	; 800C8C5C
800C8C5C	sw     zero, $0010(sp)
800C8C60	addiu  a0, a0, $0006
800C8C64	jal    func275dc [$800275dc]
800C8C68	addiu  a1, a1, $0015
800C8C6C	addu   a0, s1, zero
800C8C70	addiu  a1, sp, $0018
800C8C74	jal    func2aa04 [$8002aa04]
800C8C78	addiu  a2, zero, $0001
800C8C7C	lw     v1, $9ea0(s0)
800C8C80	addiu  a2, zero, $0013
800C8C84	lh     a0, $0000(v1)
800C8C88	lh     a1, $0002(v1)
800C8C8C	addiu  a3, sp, $0018
800C8C90	sw     v0, $0010(sp)
800C8C94	addu   a0, a0, a2
800C8C98	jal    func2b56c [$8002b56c]
800C8C9C	addiu  a1, a1, $0009
800C8CA0	lui    v0, $8006
800C8CA4	lw     v0, $794c(v0)
800C8CA8	addiu  a1, sp, $0018
800C8CAC	lw     v0, $001c(v0)
800C8CB0	addiu  a2, zero, $0007
800C8CB4	lw     a0, $0560(v0)
800C8CB8	jal    func2bae4 [$8002bae4]
800C8CBC	addiu  a3, zero, $0001
800C8CC0	addiu  a0, sp, $0018
800C8CC4	lui    a1, $800d
800C8CC8	jal    func63108 [$80063108]
800C8CCC	addiu  a1, a1, $9ea4 (=-$615c)
800C8CD0	lw     v0, $9ea0(s0)
800C8CD4	addiu  a2, zero, $0013
800C8CD8	lh     a0, $0000(v0)
800C8CDC	lh     a1, $0002(v0)
800C8CE0	addiu  a3, sp, $0018
800C8CE4	sw     zero, $0010(sp)
800C8CE8	addu   a0, a0, a2
800C8CEC	jal    func2b56c [$8002b56c]

Lc8cf0:	; 800C8CF0
800C8CF0	addiu  a1, a1, $0016
800C8CF4	lui    v0, $8007
800C8CF8	lw     v1, $9ea0(s0)
800C8CFC	lw     a3, $04c0(v0)
800C8D00	lh     a0, $0000(v1)
800C8D04	lh     a1, $0002(v1)
800C8D08	addiu  a2, zero, $0013
800C8D0C	sw     zero, $0010(sp)
800C8D10	addiu  a0, a0, $0006
800C8D14	jal    func2b524 [$8002b524]

funcc8d18:	; 800C8D18
800C8D18	addiu  a1, a1, $fffd (=-$3)
800C8D1C	addiu  a1, zero, $0014
800C8D20	lw     a0, $9ea0(s0)
800C8D24	jal    func2dee4 [$8002dee4]
800C8D28	addiu  a2, zero, $0002
800C8D2C	lw     ra, $0030(sp)
800C8D30	lw     s1, $002c(sp)
800C8D34	lw     s0, $0028(sp)
800C8D38	jr     ra 
800C8D3C	addiu  sp, sp, $0038


funcc8d40:	; 800C8D40
800C8D40	addiu  sp, sp, $ffe0 (=-$20)
800C8D44	sw     s0, $0018(sp)
800C8D48	lui    s0, $800d
800C8D4C	lui    v0, $8007
800C8D50	lw     v1, $9ea8(s0)
800C8D54	lw     a3, $046c(v0)
800C8D58	sw     ra, $001c(sp)
800C8D5C	lh     a0, $0000(v1)
800C8D60	lh     a1, $0002(v1)
800C8D64	addiu  a2, zero, $0013
800C8D68	sw     zero, $0010(sp)
800C8D6C	addiu  a0, a0, $0008
800C8D70	jal    func2b524 [$8002b524]
800C8D74	addiu  a1, a1, $fffd (=-$3)
800C8D78	addiu  a1, zero, $0014
800C8D7C	lw     a0, $9ea8(s0)
800C8D80	jal    func2dee4 [$8002dee4]
800C8D84	addiu  a2, zero, $0002
800C8D88	addiu  a1, zero, $0014
800C8D8C	lw     a0, $9ea8(s0)
800C8D90	jal    func2705c [$8002705c]
800C8D94	addiu  a2, zero, $0002
800C8D98	lui    v0, $8006
800C8D9C	lw     v0, $794c(v0)
800C8DA0	nop
800C8DA4	lw     a3, $001c(v0)
800C8DA8	nop
800C8DAC	lw     v0, $080c(a3)
800C8DB0	nop
800C8DB4	beq    v0, zero, Lc8dec [$800c8dec]
800C8DB8	nop
800C8DBC	lbu    v1, $0000(v0)
800C8DC0	addiu  v0, zero, $00ff
800C8DC4	beq    v1, v0, Lc8dec [$800c8dec]
800C8DC8	addiu  a2, zero, $0013
800C8DCC	lw     v0, $9ea8(s0)
800C8DD0	nop
800C8DD4	lh     a0, $0000(v0)
800C8DD8	lh     a1, $0002(v0)
800C8DDC	sw     zero, $0010(sp)

funcc8de0:	; 800C8DE0
800C8DE0	lw     a3, $080c(a3)
800C8DE4	j      Lc8e14 [$800c8e14]
800C8DE8	addiu  a0, a0, $0008

Lc8dec:	; 800C8DEC
800C8DEC	jal    func35774 [$80035774]
800C8DF0	addiu  a0, zero, $0001
800C8DF4	lui    v1, $800d
800C8DF8	lw     v1, $9ea8(v1)
800C8DFC	addiu  a2, zero, $0013
800C8E00	lh     a0, $0000(v1)
800C8E04	lh     a1, $0002(v1)
800C8E08	addu   a3, v0, zero
800C8E0C	sw     zero, $0010(sp)
800C8E10	addiu  a0, a0, $0008

Lc8e14:	; 800C8E14
800C8E14	jal    func2b5fc [$8002b5fc]
800C8E18	addiu  a1, a1, $0007
800C8E1C	lw     ra, $001c(sp)
800C8E20	lw     s0, $0018(sp)
800C8E24	jr     ra 
800C8E28	addiu  sp, sp, $0020


funcc8e2c:	; 800C8E2C
800C8E2C	addiu  sp, sp, $ffe0 (=-$20)

Lc8e30:	; 800C8E30
800C8E30	sw     s1, $0014(sp)
800C8E34	lui    s1, $800d
800C8E38	sw     s0, $0010(sp)
800C8E3C	addiu  s0, s1, $b188 (=-$4e78)

Lc8e40:	; 800C8E40
800C8E40	lui    v0, $8007
800C8E44	sw     ra, $001c(sp)
800C8E48	sw     s2, $0018(sp)
800C8E4C	lbu    a0, $0001(s0)
800C8E50	lw     v0, $7e54(v0)
800C8E54	addiu  a0, a0, $ffff (=-$1)

Lc8e58:	; 800C8E58
800C8E58	sltiu  a0, a0, $0002
800C8E5C	xori   a0, a0, $0001
800C8E60	andi   v0, v0, $0003
800C8E64	sltu   v0, zero, v0
800C8E68	jal    func35674 [$80035674]
800C8E6C	addu   s2, v0, zero
800C8E70	jal    func2f810 [$8002f810]
800C8E74	nop
800C8E78	andi   v0, v0, $00ff
800C8E7C	bne    v0, zero, Lc8ffc [$800c8ffc]

funcc8e80:	; 800C8E80
800C8E80	nop
800C8E84	lbu    v0, $0001(s0)
800C8E88	nop
800C8E8C	beq    v0, zero, Lc8e9c [$800c8e9c]
800C8E90	andi   v0, s2, $00ff
800C8E94	beq    v0, zero, Lc8ed0 [$800c8ed0]
800C8E98	lui    v0, $800d

Lc8e9c:	; 800C8E9C
800C8E9C	lui    v1, $8007
800C8EA0	addiu  v0, zero, $00e0
800C8EA4	sh     v0, $7de8(v1)

Lc8ea8:	; 800C8EA8
800C8EA8	addiu  v1, v1, $7de8
800C8EAC	lbu    a0, $b188(s1)
800C8EB0	addiu  v0, zero, $0001
800C8EB4	sw     v0, $0004(v1)
800C8EB8	sll    v0, a0, $04
800C8EBC	subu   v0, v0, a0
800C8EC0	addiu  v0, v0, $0011
800C8EC4	jal    func355e4 [$800355e4]
800C8EC8	sh     v0, $0002(v1)

Lc8ecc:	; 800C8ECC
800C8ECC	lui    v0, $800d

Lc8ed0:	; 800C8ED0
800C8ED0	addiu  s0, v0, $b188 (=-$4e78)
800C8ED4	lbu    v0, $0001(s0)
800C8ED8	addiu  s1, zero, $0001
800C8EDC	bne    v0, s1, Lc8f24 [$800c8f24]
800C8EE0	lui    a0, $8007
800C8EE4	addiu  a1, a0, $7de8
800C8EE8	addiu  v0, zero, $000c
800C8EEC	lui    v1, $8007
800C8EF0	sw     v0, $0004(a1)
800C8EF4	lhu    v0, $000c(s0)
800C8EF8	lbu    v1, $7e53(v1)
800C8EFC	addiu  v0, v0, $fff2 (=-$e)
800C8F00	sh     v0, $7de8(a0)
800C8F04	sllv   v0, s1, v1
800C8F08	addu   v0, v0, v1

Lc8f0c:	; 800C8F0C
800C8F0C	sll    v0, v0, $03
800C8F10	subu   v0, v0, v1
800C8F14	sllv   v0, s1, v0
800C8F18	addiu  v0, v0, $0020
800C8F1C	jal    func355e4 [$800355e4]
800C8F20	sh     v0, $0002(a1)

Lc8f24:	; 800C8F24
800C8F24	lbu    v1, $0001(s0)
800C8F28	addiu  v0, zero, $0002
800C8F2C	bne    v1, v0, Lc8ffc [$800c8ffc]
800C8F30	nop
800C8F34	lbu    v0, $0004(s0)
800C8F38	nop
800C8F3C	bne    v0, s1, Lc8fbc [$800c8fbc]
800C8F40	lui    a0, $8007
800C8F44	addiu  a1, a0, $7de8
800C8F48	addiu  v0, zero, $000b
800C8F4C	sw     v0, $0004(a1)
800C8F50	lhu    v0, $000c(s0)
800C8F54	lbu    v1, $0003(s0)
800C8F58	addiu  v0, v0, $fff6 (=-$a)
800C8F5C	sh     v0, $7de8(a0)
800C8F60	sll    v0, v1, $01
800C8F64	addu   v0, v0, v1
800C8F68	sll    v0, v0, $03
800C8F6C	subu   v0, v0, v1
800C8F70	sll    v0, v0, $01
800C8F74	addiu  v0, v0, $0024
800C8F78	jal    func355e4 [$800355e4]
800C8F7C	sh     v0, $0002(a1)
800C8F80	andi   v0, s2, $00ff
800C8F84	beq    v0, zero, Lc8ffc [$800c8ffc]
800C8F88	addiu  a2, zero, $000c
800C8F8C	lh     a0, $000c(s0)
800C8F90	lbu    v0, $0002(s0)
800C8F94	addiu  a0, a0, $fff2 (=-$e)
800C8F98	sll    a1, v0, $01
800C8F9C	addu   a1, a1, v0
800C8FA0	sll    a1, a1, $03

Lc8fa4:	; 800C8FA4
800C8FA4	subu   a1, a1, v0
800C8FA8	sll    a1, a1, $01
800C8FAC	jal    func270ec [$800270ec]
800C8FB0	addiu  a1, a1, $0020
800C8FB4	j      Lc8ffc [$800c8ffc]
800C8FB8	nop

Lc8fbc:	; 800C8FBC
800C8FBC	bne    v0, zero, Lc8ffc [$800c8ffc]
800C8FC0	addiu  a1, a0, $7de8
800C8FC4	addiu  v0, zero, $000c
800C8FC8	sw     v0, $0004(a1)
800C8FCC	lhu    v0, $000c(s0)
800C8FD0	lbu    v1, $0002(s0)
800C8FD4	addiu  v0, v0, $fff2 (=-$e)
800C8FD8	sh     v0, $7de8(a0)
800C8FDC	sll    v0, v1, $01
800C8FE0	addu   v0, v0, v1
800C8FE4	sll    v0, v0, $03
800C8FE8	subu   v0, v0, v1
800C8FEC	sll    v0, v0, $01
800C8FF0	addiu  v0, v0, $0020
800C8FF4	jal    func355e4 [$800355e4]
800C8FF8	sh     v0, $0002(a1)

Lc8ffc:	; 800C8FFC
800C8FFC	lw     ra, $001c(sp)
800C9000	lw     s2, $0018(sp)
800C9004	lw     s1, $0014(sp)
800C9008	lw     s0, $0010(sp)
800C900C	jr     ra 
800C9010	addiu  sp, sp, $0020


Lc9014:	; 800C9014
800C9014	addiu  sp, sp, $ffe8 (=-$18)
800C9018	lui    v0, $8007
800C901C	lui    a0, $800d
800C9020	addiu  a1, a0, $b188 (=-$4e78)
800C9024	sw     ra, $0014(sp)
800C9028	sw     s0, $0010(sp)
800C902C	lbu    v1, $0001(a1)
800C9030	addiu  s0, v0, $7de8
800C9034	bne    v1, zero, Lc9050 [$800c9050]
800C9038	sw     zero, $0008(s0)
800C903C	lbu    a0, $b188(a0)

funcc9040:	; 800C9040
800C9040	jal    func3631c [$8003631c]
800C9044	nop
800C9048	j      Lc90c0 [$800c90c0]
800C904C	sw     v0, $0008(s0)

Lc9050:	; 800C9050
800C9050	addiu  v0, zero, $0001
800C9054	bne    v1, v0, Lc909c [$800c909c]
800C9058	nop
800C905C	lbu    a0, $b188(a0)
800C9060	nop
800C9064	addu   v1, a0, v0
800C9068	addiu  v0, zero, $0003
800C906C	bne    v1, v0, Lc9084 [$800c9084]
800C9070	addiu  v0, zero, $0004
800C9074	jal    funcc92c8 [$800c92c8]
800C9078	nop
800C907C	j      Lc90c0 [$800c90c0]
800C9080	nop

Lc9084:	; 800C9084
800C9084	bne    v1, v0, Lc90b4 [$800c90b4]
800C9088	addiu  a0, a0, $0002
800C908C	jal    funcc90d0 [$800c90d0]
800C9090	nop
800C9094	j      Lc90c0 [$800c90c0]
800C9098	nop

Lc909c:	; 800C909C
800C909C	addiu  v0, zero, $0002
800C90A0	bne    v1, v0, Lc90c0 [$800c90c0]
800C90A4	nop
800C90A8	lbu    a0, $0004(a1)
800C90AC	nop
800C90B0	addiu  a0, a0, $000b

Lc90b4:	; 800C90B4
800C90B4	jal    func35774 [$80035774]
800C90B8	nop
800C90BC	sw     v0, $0008(s0)

Lc90c0:	; 800C90C0
800C90C0	lw     ra, $0014(sp)
800C90C4	lw     s0, $0010(sp)
800C90C8	jr     ra 
800C90CC	addiu  sp, sp, $0018


funcc90d0:	; 800C90D0
800C90D0	lui    v0, $8006
800C90D4	lui    v1, $8007
800C90D8	lw     a0, $794c(v0)
800C90DC	lbu    v0, $7e53(v1)
800C90E0	addiu  sp, sp, $ffd8 (=-$28)
800C90E4	sw     ra, $0020(sp)
800C90E8	sw     s3, $001c(sp)
800C90EC	sw     s2, $0018(sp)
800C90F0	sw     s1, $0014(sp)
800C90F4	sw     s0, $0010(sp)
800C90F8	lw     v1, $001c(a0)
800C90FC	sll    v0, v0, $02
800C9100	addu   v1, v1, v0
800C9104	lw     s2, $054c(v1)
800C9108	nop
800C910C	beq    s2, zero, Lc9220 [$800c9220]
800C9110	nop
800C9114	lbu    v0, $000b(s2)
800C9118	nop
800C911C	sltiu  v0, v0, $0063
800C9120	bne    v0, zero, Lc9134 [$800c9134]
800C9124	lui    v1, $8007
800C9128	lw     s3, $000c(s2)
800C912C	j      Lc914c [$800c914c]
800C9130	addu   a0, zero, zero

Lc9134:	; 800C9134
800C9134	lbu    v0, $000b(s2)
800C9138	addiu  v1, v1, $df5c (=-$20a4)
800C913C	sll    v0, v0, $02
800C9140	addu   v0, v0, v1

Lc9144:	; 800C9144
800C9144	lw     s3, $0000(v0)
800C9148	addu   a0, zero, zero

Lc914c:	; 800C914C
800C914C	jal    func2be44 [$8002be44]
800C9150	addu   a1, s2, zero
800C9154	lui    s0, $800d
800C9158	addiu  s0, s0, $b168 (=-$4e98)
800C915C	addu   a1, s0, zero
800C9160	addiu  a2, zero, $0007
800C9164	lw     a0, $000c(s2)
800C9168	jal    func2bae4 [$8002bae4]
800C916C	addiu  a3, zero, $0001
800C9170	lui    s1, $800d
800C9174	addiu  s1, s1, $b178 (=-$4e88)
800C9178	addu   a1, s1, zero
800C917C	addiu  a2, zero, $0007
800C9180	lw     a0, $000c(s2)
800C9184	addiu  a3, zero, $0001

Lc9188:	; 800C9188
800C9188	jal    func2bae4 [$8002bae4]
800C918C	subu   a0, s3, a0
800C9190	addiu  a0, zero, $0001
800C9194	lui    a1, $800d

Lc9198:	; 800C9198
800C9198	jal    func2be44 [$8002be44]
800C919C	addiu  a1, a1, $9ec0 (=-$6140)
800C91A0	addiu  a0, zero, $0002
800C91A4	jal    func2be44 [$8002be44]
800C91A8	addu   a1, s0, zero
800C91AC	addiu  a0, zero, $0003
800C91B0	lui    a1, $800d
800C91B4	jal    func2be44 [$8002be44]
800C91B8	addiu  a1, a1, $9ec4 (=-$613c)
800C91BC	addiu  a0, zero, $0004
800C91C0	lui    a1, $800d
800C91C4	jal    func2be44 [$8002be44]
800C91C8	addiu  a1, a1, $9ecc (=-$6134)
800C91CC	addiu  a0, zero, $0005
800C91D0	jal    func2be44 [$8002be44]
800C91D4	addu   a1, s1, zero
800C91D8	addiu  a0, zero, $0006
800C91DC	lui    a1, $800d
800C91E0	jal    func2be44 [$8002be44]
800C91E4	addiu  a1, a1, $9ed4 (=-$612c)
800C91E8	lbu    v0, $0038(s2)
800C91EC	nop
800C91F0	beq    v0, zero, Lc9200 [$800c9200]
800C91F4	lui    v0, $800d
800C91F8	j      Lc9208 [$800c9208]
800C91FC	addiu  a1, v0, $9ee4 (=-$611c)

Lc9200:	; 800C9200
800C9200	lui    v0, $800d
800C9204	addiu  a1, v0, $9edc (=-$6124)

Lc9208:	; 800C9208
800C9208	jal    func2be44 [$8002be44]
800C920C	addiu  a0, zero, $0007
800C9210	jal    func35774 [$80035774]
800C9214	addiu  a0, zero, $0005
800C9218	lui    v1, $8007
800C921C	sw     v0, $7df0(v1)

Lc9220:	; 800C9220
800C9220	lw     ra, $0020(sp)
800C9224	lw     s3, $001c(sp)
800C9228	lw     s2, $0018(sp)
800C922C	lw     s1, $0014(sp)
800C9230	lw     s0, $0010(sp)
800C9234	jr     ra 
800C9238	addiu  sp, sp, $0028


funcc923c:	; 800C923C
800C923C	addiu  sp, sp, $ffe0 (=-$20)
800C9240	sw     s0, $0010(sp)
800C9244	lui    s0, $800d
800C9248	lbu    v0, $b188(s0)
800C924C	sw     s1, $0014(sp)
800C9250	addiu  s1, s0, $b188 (=-$4e78)
800C9254	addiu  a0, v0, $0001
800C9258	addiu  v0, zero, $0005
800C925C	beq    a0, v0, Lc9294 [$800c9294]
800C9260	sw     ra, $0018(sp)
800C9264	jal    func36300 [$80036300]
800C9268	nop
800C926C	andi   v0, v0, $00ff
800C9270	bne    v0, zero, Lc928c [$800c928c]
800C9274	addiu  v0, zero, $0001
800C9278	lbu    a0, $b188(s0)
800C927C	jal    func361cc [$800361cc]
800C9280	addiu  a0, a0, $0001
800C9284	j      Lc92a0 [$800c92a0]
800C9288	nop

Lc928c:	; 800C928C
800C928C	j      Lc92a0 [$800c92a0]
800C9290	sb     v0, $0001(s1)

Lc9294:	; 800C9294
800C9294	addiu  v0, zero, $0002

Lc9298:	; 800C9298
800C9298	sb     v0, $0001(s1)
800C929C	sb     zero, $0004(s1)

Lc92a0:	; 800C92A0
800C92A0	jal    func2f488 [$8002f488]
800C92A4	addiu  a0, zero, $0067
800C92A8	lw     ra, $0018(sp)
800C92AC	lw     s1, $0014(sp)
800C92B0	lw     s0, $0010(sp)
800C92B4	jr     ra 
800C92B8	addiu  sp, sp, $0020

800C92BC	lui    v0, $8007
800C92C0	jr     ra 
800C92C4	sb     zero, $7e51(v0)


funcc92c8:	; 800C92C8
800C92C8	addiu  sp, sp, $ffd0 (=-$30)
800C92CC	lui    v0, $8007
800C92D0	sw     s6, $0028(sp)
800C92D4	addiu  s6, v0, $9018 (=-$6fe8)
800C92D8	lui    v0, $8007
800C92DC	sw     s5, $0024(sp)
800C92E0	addiu  s5, v0, $a218 (=-$5de8)
800C92E4	lui    v0, $800d
800C92E8	sw     s3, $001c(sp)
800C92EC	addiu  s3, v0, $9eac (=-$6154)
800C92F0	lui    v0, $8006
800C92F4	lui    v1, $8007
800C92F8	lw     a0, $794c(v0)
800C92FC	lbu    v0, $7e53(v1)
800C9300	sw     s1, $0014(sp)
800C9304	addu   s1, zero, zero
800C9308	sw     s2, $0018(sp)
800C930C	addiu  s2, zero, $0005
800C9310	sw     ra, $002c(sp)
800C9314	sw     s4, $0020(sp)
800C9318	sw     s0, $0010(sp)
800C931C	lw     v1, $001c(a0)
800C9320	sll    v0, v0, $02

Lc9324:	; 800C9324
800C9324	addu   v1, v1, v0

Lc9328:	; 800C9328
800C9328	lw     s4, $054c(v1)

loopc932c:	; 800C932C
800C932C	lw     a1, $0000(s3)
800C9330	jal    func2be44 [$8002be44]
800C9334	addu   a0, s1, zero
800C9338	addu   v0, s4, s1
800C933C	lbu    s0, $0039(v0)
800C9340	addiu  v0, zero, $00ff
800C9344	beq    s0, v0, Lc9368 [$800c9368]
800C9348	sll    v0, s0, $03

Lc934c:	; 800C934C
800C934C	addu   v0, v0, s0
800C9350	sll    v0, v0, $01
800C9354	addu   v0, v0, s6
800C9358	lhu    a1, $0000(v0)
800C935C	addu   a0, s2, zero
800C9360	j      Lc9378 [$800c9378]
800C9364	addu   a1, a1, s5

Lc9368:	; 800C9368
800C9368	jal    func35774 [$80035774]
800C936C	addiu  a0, zero, $000d
800C9370	addu   a0, s2, zero

funcc9374:	; 800C9374
800C9374	addu   a1, v0, zero

Lc9378:	; 800C9378
800C9378	jal    func2be44 [$8002be44]
800C937C	addiu  s2, s2, $0001
800C9380	addu   a0, s1, zero
800C9384	jal    func2be74 [$8002be74]
800C9388	addu   a1, s0, zero
800C938C	addiu  s1, s1, $0001
800C9390	slti   v0, s1, $0005
800C9394	bne    v0, zero, loopc932c [$800c932c]
800C9398	addiu  s3, s3, $0004
800C939C	jal    func35774 [$80035774]
800C93A0	addiu  a0, zero, $0004
800C93A4	lw     ra, $002c(sp)
800C93A8	lw     s6, $0028(sp)
800C93AC	lw     s5, $0024(sp)
800C93B0	lw     s4, $0020(sp)
800C93B4	lw     s3, $001c(sp)
800C93B8	lw     s2, $0018(sp)
800C93BC	lw     s1, $0014(sp)
800C93C0	lw     s0, $0010(sp)
800C93C4	lui    v1, $8007
800C93C8	sw     v0, $7df0(v1)
800C93CC	jr     ra 
800C93D0	addiu  sp, sp, $0030

800C93D4	addiu  sp, sp, $ffd8 (=-$28)
800C93D8	lui    v0, $8007
800C93DC	sw     s1, $001c(sp)
800C93E0	addiu  s1, v0, $7e50
800C93E4	sw     ra, $0020(sp)
800C93E8	sw     s0, $0018(sp)
800C93EC	lbu    v0, $0001(s1)
800C93F0	nop
800C93F4	beq    v0, zero, Lc9408 [$800c9408]
800C93F8	lui    v0, $800d
800C93FC	sb     zero, $b188(v0)
800C9400	addiu  v0, v0, $b188 (=-$4e78)
800C9404	sb     zero, $0002(v0)

Lc9408:	; 800C9408
800C9408	lui    a0, $800a
800C940C	addiu  a0, a0, $7860
800C9410	lui    v0, $800d
800C9414	jal    func3575c [$8003575c]
800C9418	sb     zero, $b189(v0)
800C941C	jal    funcc8124 [$800c8124]
800C9420	lui    s0, $8006
800C9424	lw     v1, $794c(s0)
800C9428	addiu  v0, zero, $0008
800C942C	sh     v0, $0010(sp)
800C9430	sh     v0, $0012(sp)
800C9434	addiu  v0, zero, $00e8
800C9438	sh     v0, $0014(sp)
800C943C	lw     v0, $000c(v1)
800C9440	nop
800C9444	lhu    v0, $0006(v0)
800C9448	addiu  a0, sp, $0010
800C944C	addiu  v0, v0, $fff1 (=-$f)
800C9450	jal    func35580 [$80035580]
800C9454	sh     v0, $0016(sp)

Lc9458:	; 800C9458
800C9458	lui    a0, $800d
800C945C	jal    func3556c [$8003556c]
800C9460	addiu  a0, a0, $9014 (=-$6fec)
800C9464	jal    func35674 [$80035674]
800C9468	addiu  a0, zero, $0001
800C946C	lw     v1, $794c(s0)
800C9470	lbu    v0, $0003(s1)
800C9474	lw     v1, $001c(v1)
800C9478	sll    v0, v0, $02
800C947C	addu   v1, v1, v0
800C9480	lw     v0, $054c(v1)

Lc9484:	; 800C9484
800C9484	nop
800C9488	bne    v0, zero, Lc949c [$800c949c]
800C948C	nop
800C9490	jal    func3378c [$8003378c]
800C9494	nop
800C9498	sb     v0, $0003(s1)

Lc949c:	; 800C949C
800C949C	lw     ra, $0020(sp)
800C94A0	lw     s1, $001c(sp)
800C94A4	lw     s0, $0018(sp)
800C94A8	jr     ra 
800C94AC	addiu  sp, sp, $0028

800C94B0	addiu  sp, sp, $ffe8 (=-$18)
800C94B4	sw     ra, $0010(sp)

funcc94b8:	; 800C94B8
800C94B8	jal    funcc951c [$800c951c]
800C94BC	nop
800C94C0	jal    funcc9580 [$800c9580]
800C94C4	nop
800C94C8	jal    funcc95b8 [$800c95b8]
800C94CC	nop
800C94D0	lw     ra, $0010(sp)
800C94D4	nop

Lc94d8:	; 800C94D8
800C94D8	jr     ra 
800C94DC	addiu  sp, sp, $0018

800C94E0	addiu  sp, sp, $ffe8 (=-$18)
800C94E4	sw     ra, $0010(sp)
800C94E8	jal    func35674 [$80035674]
800C94EC	addiu  a0, zero, $0001
800C94F0	jal    func35580 [$80035580]
800C94F4	addu   a0, zero, zero
800C94F8	jal    func3556c [$8003556c]
800C94FC	addu   a0, zero, zero
800C9500	lw     ra, $0010(sp)
800C9504	nop

Lc9508:	; 800C9508
800C9508	jr     ra 
800C950C	addiu  sp, sp, $0018


funcc9510:	; 800C9510
800C9510	lui    v0, $800d
800C9514	jr     ra 
800C9518	sb     a0, $b188(v0)


funcc951c:	; 800C951C
800C951C	lui    v0, $8007
800C9520	lbu    v0, $7e51(v0)
800C9524	addiu  sp, sp, $ffe8 (=-$18)
800C9528	bne    v0, zero, Lc9570 [$800c9570]
800C952C	sw     ra, $0010(sp)
800C9530	jal    func2f810 [$8002f810]
800C9534	nop
800C9538	andi   v0, v0, $00ff
800C953C	bne    v0, zero, Lc9570 [$800c9570]
800C9540	lui    v1, $800d
800C9544	lui    v0, $800d
800C9548	lbu    v0, $b189(v0)
800C954C	addiu  v1, v1, $9e14 (=-$61ec)
800C9550	sll    v0, v0, $02

Lc9554:	; 800C9554
800C9554	addu   v0, v0, v1
800C9558	lw     v0, $0000(v0)
800C955C	nop
800C9560	beq    v0, zero, Lc9570 [$800c9570]
800C9564	nop
800C9568	jalr   v0 ra
800C956C	nop

Lc9570:	; 800C9570
800C9570	lw     ra, $0010(sp)
800C9574	nop
800C9578	jr     ra 
800C957C	addiu  sp, sp, $0018


funcc9580:	; 800C9580
800C9580	addiu  sp, sp, $ffe8 (=-$18)
800C9584	sw     ra, $0010(sp)
800C9588	jal    funcc8c08 [$800c8c08]

Lc958c:	; 800C958C
800C958C	nop
800C9590	jal    funcc8d40 [$800c8d40]
800C9594	nop
800C9598	jal    funcc9630 [$800c9630]
800C959C	nop
800C95A0	jal    funcc8e2c [$800c8e2c]
800C95A4	nop
800C95A8	lw     ra, $0010(sp)
800C95AC	nop
800C95B0	jr     ra 
800C95B4	addiu  sp, sp, $0018


funcc95b8:	; 800C95B8
800C95B8	lui    v0, $8007
800C95BC	lbu    v0, $7e51(v0)
800C95C0	addiu  sp, sp, $ffe0 (=-$20)
800C95C4	sw     ra, $001c(sp)
800C95C8	sw     s2, $0018(sp)
800C95CC	sw     s1, $0014(sp)
800C95D0	beq    v0, zero, Lc9618 [$800c9618]
800C95D4	sw     s0, $0010(sp)
800C95D8	addu   s2, zero, zero
800C95DC	lui    v0, $800d
800C95E0	addiu  v0, v0, $b188 (=-$4e78)
800C95E4	addiu  s1, v0, $0008
800C95E8	addu   s0, v0, zero

loopc95ec:	; 800C95EC
800C95EC	lw     v0, $0014(s0)

Lc95f0:	; 800C95F0
800C95F0	nop
800C95F4	beq    v0, zero, Lc9604 [$800c9604]
800C95F8	nop
800C95FC	jal    func631ac [$800631ac]

funcc9600:	; 800C9600
800C9600	addu   a0, s1, zero

Lc9604:	; 800C9604
800C9604	addiu  s1, s1, $0010
800C9608	addiu  s2, s2, $0001
800C960C	slti   v0, s2, $0006
800C9610	bne    v0, zero, loopc95ec [$800c95ec]
800C9614	addiu  s0, s0, $0010

Lc9618:	; 800C9618
800C9618	lw     ra, $001c(sp)
800C961C	lw     s2, $0018(sp)
800C9620	lw     s1, $0014(sp)
800C9624	lw     s0, $0010(sp)
800C9628	jr     ra 
800C962C	addiu  sp, sp, $0020


funcc9630:	; 800C9630
800C9630	addiu  sp, sp, $ffd8 (=-$28)
800C9634	sw     s1, $001c(sp)
800C9638	addu   s1, zero, zero
800C963C	lui    v0, $800d
800C9640	sw     s0, $0018(sp)
800C9644	addiu  s0, v0, $b194 (=-$4e6c)
800C9648	sw     ra, $0020(sp)

loopc964c:	; 800C964C
800C964C	lhu    v0, $0000(s0)
800C9650	nop
800C9654	addiu  v0, v0, $0082
800C9658	sh     v0, $0010(sp)
800C965C	lhu    a0, $0002(s0)

Lc9660:	; 800C9660
800C9660	addiu  v0, zero, $0072
800C9664	sh     v0, $0014(sp)
800C9668	lui    v0, $8006
800C966C	lw     v1, $794c(v0)
800C9670	addiu  v0, zero, $0012
800C9674	sh     v0, $0016(sp)
800C9678	sh     a0, $0012(sp)
800C967C	lw     v0, $001c(v1)
800C9680	sll    v1, s1, $02
800C9684	addu   v0, v0, v1
800C9688	lw     v0, $054c(v0)
800C968C	nop
800C9690	beq    v0, zero, Lc96a4 [$800c96a4]
800C9694	addu   a0, s0, zero
800C9698	jal    funcc883c [$800c883c]
800C969C	addu   a0, s1, zero
800C96A0	addu   a0, s0, zero

Lc96a4:	; 800C96A4
800C96A4	jal    funcc8ae8 [$800c8ae8]
800C96A8	addiu  a1, zero, $0014
800C96AC	addiu  a0, sp, $0010
800C96B0	addiu  a1, zero, $0014
800C96B4	jal    func2dee4 [$8002dee4]
800C96B8	addu   a2, zero, zero
800C96BC	addu   a0, s0, zero
800C96C0	addiu  a1, zero, $0014
800C96C4	jal    func2dee4 [$8002dee4]
800C96C8	addu   a2, zero, zero
800C96CC	addu   a0, s0, zero
800C96D0	addiu  a1, zero, $0015
800C96D4	jal    func2705c [$8002705c]
800C96D8	addu   a2, zero, zero
800C96DC	addiu  s1, s1, $0001
800C96E0	slti   v0, s1, $0004
800C96E4	bne    v0, zero, loopc964c [$800c964c]
800C96E8	addiu  s0, s0, $0010
800C96EC	lw     ra, $0020(sp)
800C96F0	lw     s1, $001c(sp)
800C96F4	lw     s0, $0018(sp)
800C96F8	jr     ra 
800C96FC	addiu  sp, sp, $0028


funcc9700:	; 800C9700
800C9700	lhu    v0, $0000(a0)
800C9704	jr     ra 
800C9708	andi   v0, v0, $7fff


funcc970c:	; 800C970C
800C970C	addiu  sp, sp, $ff70 (=-$90)
800C9710	sw     s3, $007c(sp)
800C9714	lw     s3, $00a0(sp)
800C9718	sw     s4, $0080(sp)
800C971C	lw     s4, $00a8(sp)
800C9720	sw     s5, $0084(sp)
800C9724	addu   s5, a0, zero
800C9728	sw     s1, $0074(sp)

funcc972c:	; 800C972C
800C972C	addu   s1, a1, zero
800C9730	sw     s2, $0078(sp)
800C9734	addu   s2, a3, zero
800C9738	sw     ra, $0088(sp)
800C973C	bne    s2, zero, Lc9750 [$800c9750]
800C9740	sw     s0, $0070(sp)
800C9744	addiu  s2, sp, $0020
800C9748	sw     zero, $0020(sp)
800C974C	sw     zero, $0024(sp)

Lc9750:	; 800C9750
800C9750	lhu    v0, $0000(s1)
800C9754	lw     v1, $00a4(sp)
800C9758	andi   a1, v0, $7fff
800C975C	slt    v0, v1, a1
800C9760	bne    v0, zero, Lc9798 [$800c9798]
800C9764	sll    v0, a1, $01
800C9768	div    v1, a1
800C976C	bne    a1, zero, Lc9778 [$800c9778]
800C9770	nop
800C9774	break   $01c00

Lc9778:	; 800C9778
800C9778	addiu  at, zero, $ffff (=-$1)
800C977C	bne    a1, at, Lc9790 [$800c9790]
800C9780	lui    at, $8000
800C9784	bne    v1, at, Lc9790 [$800c9790]
800C9788	nop
800C978C	break   $01800

Lc9790:	; 800C9790
800C9790	mfhi   v1

funcc9794:	; 800C9794
800C9794	sll    v0, a1, $01

Lc9798:	; 800C9798
800C9798	addiu  a1, v0, $0008
800C979C	sll    a0, v1, $01
800C97A0	addu   v0, s1, a1

Lc97a4:	; 800C97A4
800C97A4	lhu    v1, $0000(v0)
800C97A8	addiu  v0, v0, $0002
800C97AC	sw     v0, $0048(sp)
800C97B0	sll    v1, v1, $01
800C97B4	addu   v0, v0, v1
800C97B8	addiu  v0, v0, $0002
800C97BC	sw     v0, $004c(sp)
800C97C0	andi   v0, s4, $0003
800C97C4	lhu    v1, $0002(s1)
800C97C8	sll    v0, v0, $05
800C97CC	or     v1, v1, v0
800C97D0	sw     v1, $0058(sp)
800C97D4	lhu    v0, $0004(s1)
800C97D8	nop
800C97DC	sw     v0, $005c(sp)
800C97E0	lbu    v0, $0006(s1)
800C97E4	addu   a0, a0, s1
800C97E8	addiu  v0, v0, $ffff (=-$1)
800C97EC	sll    v0, v0, $01
800C97F0	sw     v0, $0054(sp)
800C97F4	lbu    v0, $0007(s1)
800C97F8	lui    v1, $8006
800C97FC	addiu  v0, v0, $ffff (=-$1)
800C9800	sll    v0, v0, $01
800C9804	sw     v0, $0050(sp)
800C9808	lhu    a1, $0008(a0)
800C980C	lw     v1, $794c(v1)
800C9810	addu   v0, s1, a1
800C9814	lbu    v0, $0000(v0)
800C9818	addiu  a1, a1, $0001
800C981C	sw     v0, $0064(sp)
800C9820	lw     v0, $001c(v1)
800C9824	addu   s1, s1, a1
800C9828	addiu  v0, v0, $0018
800C982C	lw     t4, $0000(v0)
800C9830	lw     t5, $0004(v0)
800C9834	ctc2   t4,vxy0
800C9838	ctc2   t5,vz0
800C983C	lw     t4, $0008(v0)

Lc9840:	; 800C9840
800C9840	lw     t5, $000c(v0)
800C9844	lw     t6, $0010(v0)
800C9848	ctc2   t4,vxy1
800C984C	ctc2   t5,vz1
800C9850	ctc2   t6,vxy2
800C9854	lw     t4, $0014(v0)
800C9858	lw     t5, $0018(v0)
800C985C	ctc2   t4,vz2
800C9860	lw     t6, $001c(v0)
800C9864	ctc2   t5,rgb
800C9868	ctc2   t6,otz
800C986C	lwc2   zero, $0000(a2)
800C9870	lwc2   at, $0004(a2)
800C9874	nop
800C9878	nop
800C987C	gte_func18t0,r11r12
800C9880	addu   a0, s2, zero
800C9884	addiu  s0, sp, $0028
800C9888	jal    func316d8 [$800316d8]
800C988C	addu   a1, s0, zero
800C9890	bltz   s3, Lc98ac [$800c98ac]
800C9894	addu   a0, s0, zero
800C9898	addiu  a1, sp, $0010
800C989C	sw     s3, $0018(sp)
800C98A0	sw     s3, $0014(sp)
800C98A4	jal    func548e8 [$800548e8]
800C98A8	sw     s3, $0010(sp)

Lc98ac:	; 800C98AC
800C98AC	addiu  v0, sp, $003c
800C98B0	swc2   t9, $0000(v0)
800C98B4	swc2   k0, $0004(v0)
800C98B8	swc2   k1, $0008(v0)
800C98BC	lh     v0, $0006(s2)
800C98C0	nop
800C98C4	beq    v0, zero, Lc98d4 [$800c98d4]
800C98C8	nop
800C98CC	jal    func632f4 [$800632f4]
800C98D0	addu   a0, s0, zero

Lc98d4:	; 800C98D4
800C98D4	lw     t4, $0000(s0)
800C98D8	lw     t5, $0004(s0)
800C98DC	ctc2   t4,vxy0
800C98E0	ctc2   t5,vz0
800C98E4	lw     t4, $0008(s0)
800C98E8	lw     t5, $000c(s0)
800C98EC	lw     t6, $0010(s0)
800C98F0	ctc2   t4,vxy1
800C98F4	ctc2   t5,vz1
800C98F8	ctc2   t6,vxy2
800C98FC	lw     t4, $0014(s0)
800C9900	lw     t5, $0018(s0)
800C9904	ctc2   t4,vz2
800C9908	lw     t6, $001c(s0)
800C990C	ctc2   t5,rgb
800C9910	ctc2   t6,otz
800C9914	addiu  v0, zero, $00ff
800C9918	bne    s4, v0, Lc9924 [$800c9924]
800C991C	addiu  v0, zero, $002e
800C9920	addiu  v0, zero, $002c

Lc9924:	; 800C9924
800C9924	sw     v0, $0068(sp)
800C9928	addu   a0, s1, zero
800C992C	addiu  a1, sp, $0048
800C9930	lw     v0, $00ac(sp)
800C9934	lw     a3, $00b0(sp)
800C9938	addu   a2, s5, zero
800C993C	jal    funcc9ab8 [$800c9ab8]
800C9940	sw     v0, $0060(sp)
800C9944	lw     ra, $0088(sp)
800C9948	lw     s5, $0084(sp)
800C994C	lw     s4, $0080(sp)
800C9950	lw     s3, $007c(sp)
800C9954	lw     s2, $0078(sp)
800C9958	lw     s1, $0074(sp)
800C995C	lw     s0, $0070(sp)
800C9960	jr     ra 
800C9964	addiu  sp, sp, $0090


funcc9968:	; 800C9968
800C9968	addiu  sp, sp, $ffc8 (=-$38)
800C996C	sw     ra, $0030(sp)
800C9970	sw     s5, $002c(sp)
800C9974	sw     s4, $0028(sp)
800C9978	sw     s3, $0024(sp)
800C997C	sw     s2, $0020(sp)
800C9980	sw     s1, $001c(sp)
800C9984	sw     s0, $0018(sp)
800C9988	lw     a1, $0000(a0)
800C998C	nop
800C9990	addu   s3, a0, a1
800C9994	lw     a1, $0004(a0)
800C9998	addu   s2, zero, zero
800C999C	addu   s1, a0, a1
800C99A0	lw     a1, $0000(s3)
800C99A4	lw     s4, $0008(a0)
800C99A8	nop
800C99AC	blez   s4, Lc9a1c [$800c9a1c]
800C99B0	addu   s5, a0, a1

loopc99b4:	; 800C99B4
800C99B4	lhu    v0, $0000(s1)
800C99B8	nop
800C99BC	sh     v0, $0010(sp)

Lc99c0:	; 800C99C0
800C99C0	lhu    v0, $0002(s1)
800C99C4	nop
800C99C8	sh     v0, $0012(sp)
800C99CC	lhu    v1, $0004(s1)
800C99D0	nop

Lc99d4:	; 800C99D4
800C99D4	sh     v1, $0014(sp)
800C99D8	sll    v1, v1, $10
800C99DC	lhu    a2, $0006(s1)
800C99E0	sra    v1, v1, $10
800C99E4	sll    v0, a2, $10
800C99E8	sra    v0, v0, $10
800C99EC	mult   v1, v0
800C99F0	addiu  a0, sp, $0010
800C99F4	addiu  s2, s2, $0001
800C99F8	addiu  s1, s1, $0008

Lc99fc:	; 800C99FC
800C99FC	addu   a1, s1, zero
800C9A00	sh     a2, $0016(sp)
800C9A04	mflo   a3
800C9A08	jal    func13350 [$80013350]
800C9A0C	sll    s0, a3, $01

Lc9a10:	; 800C9A10
800C9A10	slt    v0, s2, s4
800C9A14	bne    v0, zero, loopc99b4 [$800c99b4]
800C9A18	addu   s1, s1, s0

Lc9a1c:	; 800C9A1C
800C9A1C	lw     s1, $0004(s3)
800C9A20	addiu  s3, s3, $0008
800C9A24	blez   s1, Lc9a94 [$800c9a94]

funcc9a28:	; 800C9A28
800C9A28	addu   s2, zero, zero
800C9A2C	addiu  s0, s3, $0006

loopc9a30:	; 800C9A30
800C9A30	lhu    v0, $0000(s3)
800C9A34	nop
800C9A38	sh     v0, $0010(sp)
800C9A3C	lhu    v0, $fffc(s0)
800C9A40	nop
800C9A44	sh     v0, $0012(sp)
800C9A48	lhu    v0, $fffe(s0)
800C9A4C	addiu  a0, sp, $0010
800C9A50	sh     v0, $0014(sp)
800C9A54	lhu    v0, $0000(s0)
800C9A58	addu   a1, s5, zero
800C9A5C	jal    func13350 [$80013350]
800C9A60	sh     v0, $0016(sp)
800C9A64	lh     v1, $0014(sp)
800C9A68	lh     v0, $0016(sp)
800C9A6C	nop
800C9A70	mult   v1, v0
800C9A74	addiu  s3, s3, $0008
800C9A78	addiu  s2, s2, $0001
800C9A7C	mflo   a3
800C9A80	sll    v0, a3, $01
800C9A84	addu   s5, s5, v0
800C9A88	slt    v0, s2, s1
800C9A8C	bne    v0, zero, loopc9a30 [$800c9a30]
800C9A90	addiu  s0, s0, $0008

Lc9a94:	; 800C9A94
800C9A94	lw     ra, $0030(sp)
800C9A98	lw     s5, $002c(sp)
800C9A9C	lw     s4, $0028(sp)
800C9AA0	lw     s3, $0024(sp)
800C9AA4	lw     s2, $0020(sp)
800C9AA8	lw     s1, $001c(sp)
800C9AAC	lw     s0, $0018(sp)
800C9AB0	jr     ra 
800C9AB4	addiu  sp, sp, $0038


funcc9ab8:	; 800C9AB8
800C9AB8	addiu  sp, sp, $fff0 (=-$10)
800C9ABC	sw     s3, $000c(sp)
800C9AC0	sw     s2, $0008(sp)
800C9AC4	sw     s1, $0004(sp)
800C9AC8	sw     s0, $0000(sp)
800C9ACC	lw     t5, $0008(a1)
800C9AD0	lw     t6, $000c(a1)
800C9AD4	lw     t3, $0004(a1)
800C9AD8	lw     t2, $0000(a1)
800C9ADC	lw     t0, $0010(a1)
800C9AE0	lw     t1, $0014(a1)
800C9AE4	sll    t0, t0, $10
800C9AE8	sll    t1, t1, $10
800C9AEC	lw     t7, $0018(a1)
800C9AF0	lw     t4, $001c(a1)
800C9AF4	lw     s3, $0020(a1)
800C9AF8	mtc2   zero,r13r21
800C9AFC	mtc2   zero,r31r32
800C9B00	mtc2   zero,trx
800C9B04	beq    t4, zero, Lc9cb0 [$800c9cb0]
800C9B08	sll    s3, s3, $18

Lc9b0c:	; 800C9B0C
800C9B0C	lb     s2, $0000(a0)
800C9B10	lb     s1, $0001(a0)
800C9B14	sll    s2, s2, $02
800C9B18	subu   v0, s2, t5
800C9B1C	addu   s0, s2, t5

Lc9b20:	; 800C9B20
800C9B20	sll    s1, s1, $02
800C9B24	subu   v1, s1, t6
800C9B28	addu   s1, s1, t6
800C9B2C	andi   v0, v0, $ffff
800C9B30	andi   s0, s0, $ffff
800C9B34	sll    v1, v1, $10
800C9B38	sll    s1, s1, $10
800C9B3C	or     t8, v0, v1
800C9B40	mtc2   t8,r11r12
800C9B44	or     a1, s0, v1
800C9B48	mtc2   a1,r22r23
800C9B4C	or     t8, v0, s1
800C9B50	mtc2   t8,r33
800C9B54	or     a1, s0, s1
800C9B58	nop
800C9B5C	gte_func17t0,r11r12
800C9B60	lbu    v0, $0002(a0)

Lc9b64:	; 800C9B64
800C9B64	addiu  a0, a0, $0003
800C9B68	andi   v1, v0, $000f
800C9B6C	sll    v1, v1, $01
800C9B70	addu   v1, v1, t2
800C9B74	lhu    s0, $0000(v1)
800C9B78	srl    t8, t5, $01
800C9B7C	andi   v1, s0, $00ff
800C9B80	srl    s0, s0, $08
800C9B84	addu   s1, v1, t8
800C9B88	srl    t8, t6, $01
800C9B8C	addu   s2, s0, t8
800C9B90	sll    s0, s0, $08
800C9B94	sll    s2, s2, $08
800C9B98	or     t8, v1, s0
800C9B9C	or     t8, t8, t1
800C9BA0	sw     t8, $000c(a2)
800C9BA4	or     t8, s1, s0
800C9BA8	or     t8, t8, t0
800C9BAC	sw     t8, $0014(a2)
800C9BB0	or     t8, v1, s2
800C9BB4	sw     t8, $001c(a2)
800C9BB8	swc2   t4, $0008(a2)
800C9BBC	swc2   t5, $0010(a2)
800C9BC0	swc2   t6, $0018(a2)
800C9BC4	mfc2   s0,ofx
800C9BC8	or     t8, s1, s2
800C9BCC	beq    s0, zero, Lc9cb0 [$800c9cb0]
800C9BD0	sw     t8, $0024(a2)
800C9BD4	mfc2   s1,lb1lb2
800C9BD8	mtc2   a1,r11r12
800C9BDC	srl    s2, v0, $04
800C9BE0	sll    s2, s2, $02
800C9BE4	addu   s2, s2, t3
800C9BE8	gte_func16t8,r11r12
800C9BEC	lbu    v1, $0002(s2)
800C9BF0	lhu    v0, $0000(s2)
800C9BF4	sll    v1, v1, $10
800C9BF8	swc2   t6, $0020(a2)
800C9BFC	bltz   t7, Lc9c5c [$800c9c5c]
800C9C00	or     v0, v0, v1
800C9C04	mtc2   t7,l11l12
800C9C08	andi   v1, v0, $00ff
800C9C0C	mtc2   v1,l13l21
800C9C10	srl    s0, v0, $08
800C9C14	andi   s0, s0, $00ff
800C9C18	mtc2   s0,l22l23
800C9C1C	srl    v1, v0, $10
800C9C20	andi   v1, v1, $00ff
800C9C24	mtc2   v1,l31l32
800C9C28	nop
800C9C2C	nop
800C9C30	gte_func28t8,r11r12
800C9C34	mfc2   v0,l13l21
800C9C38	mfc2   v1,l22l23
800C9C3C	andi   v0, v0, $00ff
800C9C40	andi   v1, v1, $00ff
800C9C44	sll    v1, v1, $08
800C9C48	mfc2   s0,l31l32
800C9C4C	or     v0, v0, v1
800C9C50	andi   s0, s0, $00ff
800C9C54	sll    s0, s0, $10
800C9C58	or     v0, v0, s0

Lc9c5c:	; 800C9C5C
800C9C5C	or     v0, v0, s3
800C9C60	sw     v0, $0004(a2)
800C9C64	addu   s2, s1, zero
800C9C68	sra    s0, s2, $02
800C9C6C	sll    s0, s0, $02
800C9C70	addu   s1, s0, a3
800C9C74	lw     v1, $0000(s1)
800C9C78	lui    v0, $0900
800C9C7C	sll    s0, v1, $08
800C9C80	srl    s0, s0, $08
800C9C84	or     s0, s0, v0
800C9C88	sw     s0, $0000(a2)
800C9C8C	sll    v0, a2, $08
800C9C90	srl    v0, v0, $08
800C9C94	srl    s0, v1, $18
800C9C98	sll    s0, s0, $18

Lc9c9c:	; 800C9C9C
800C9C9C	or     s0, s0, v0
800C9CA0	sw     s0, $0000(s1)
800C9CA4	addiu  t4, t4, $ffff (=-$1)
800C9CA8	bne    t4, zero, Lc9b0c [$800c9b0c]
800C9CAC	addiu  a2, a2, $0028

Lc9cb0:	; 800C9CB0
800C9CB0	addu   v0, a2, zero
800C9CB4	lw     s3, $000c(sp)
800C9CB8	lw     s2, $0008(sp)
800C9CBC	lw     s1, $0004(sp)
800C9CC0	lw     s0, $0000(sp)
800C9CC4	jr     ra 
800C9CC8	addiu  sp, sp, $0010
