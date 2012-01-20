////////////////////////////////
// funca85f4
800A85FC	lui    s0, $8006
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4];
V0 = w[V0 + 4];
800A861C	addu   s2, a0, zero

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
////////////////////////////////



////////////////////////////////
// funca7aac
800A7AB4	jal    funca85f4 [$800a85f4]

loopa7ac0:	; 800A7AC0
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    A0 = h[V0 + c];
    800A7AD4	jal    funca7b10 [$800a7b10]

    V0 = w[8006794c];
    V0 = w[V0] & 7;
800A7AF0	beq    v0, zero, loopa7ac0 [$800a7ac0]

800A7AF8	jal    funca8698 [$800a8698]
////////////////////////////////



////////////////////////////////
// funca7a48
800A7A50	jal    funca8198 [$800a8198]

loopa7a5c:	; 800A7A5C
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    A0 = h[V0 + 3a]; // start of character data
    funca7aac;


    V0 = w[8006794c];
    V0 = w[V0] & 3;
800A7A8C	beq    v0, zero, loopa7a5c [$800a7a5c]

800A7A94	jal    funca82f8 [$800a82f8]
////////////////////////////////



////////////////////////////////
// funca7b10
800A7B1C	jal    funca89c4 [$800a89c4]

A0 = 1;
800A7B24	jal    func1300c [$8001300c]

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
////////////////////////////////



////////////////////////////////
// funcb31b8
800B31B8	addu   t1, a0, zero
800B31BC	lui    v0, $8006
800B31C0	lw     v0, $794c(v0)
800B31C4	lw     v1, $000c(t1)
800B31C8	lw     v0, $001c(v0)
800B31CC	lbu    a0, $003b(v1)
800B31D0	lw     v1, $08e4(v0)
800B31D4	sll    v0, a0, $02
800B31D8	lw     v1, $000c(v1)
800B31DC	addu   v0, v0, a0
800B31E0	lw     v1, $0014(v1)
800B31E4	sll    v0, v0, $02
800B31E8	lw     v1, $0054(v1)
800B31EC	lw     a0, $0000(t1)
800B31F0	addu   t0, v1, v0
800B31F4	andi   v0, a0, $0800
800B31F8	beq    v0, zero, Lb3214 [$800b3214]
800B31FC	andi   v1, a1, $00ff
800B3200	addiu  v0, zero, $f7ff (=-$801)
800B3204	and    v0, a0, v0
800B3208	sw     v0, $0000(t1)
800B320C	jr     ra 
800B3210	addu   v0, zero, zero


Lb3214:	; 800B3214
800B3214	sll    v0, a2, $08
800B3218	andi   v0, v0, $ff00
800B321C	or     v1, v1, v0
800B3220	sll    v0, a3, $10
800B3224	lui    a0, $00ff
800B3228	and    v0, v0, a0
800B322C	or     v1, v1, v0
800B3230	lui    v0, $0100
800B3234	or     v1, v1, v0
800B3238	sw     v1, $000c(t0)
800B323C	sw     v1, $0008(t0)
800B3240	lw     v1, $0000(t1)
800B3244	addiu  v0, zero, $0001
800B3248	ori    v1, v1, $0c00
800B324C	jr     ra 
800B3250	sw     v1, $0000(t1)
////////////////////////////////



////////////////////////////////
// funcb2cc0
S0 = A1;
S2 = A2;
S2 = A3;

A0 = A0;
func1e350;

A0 = V0;
A1 = S0;
A2 = S1;
A3 = S2;
800B2CF0	jal    funcb31b8 [$800b31b8]
////////////////////////////////



////////////////////////////////
// funcc142c
V1 = w[800c9db4];
V1 = V1 + w[V1 + 10] + A0 * 38;
if (A1 != 0)
{
    [V1] = b(bu[V1] | 02);
}
else
{
    [V1] = b(bu[V1] & fd);
}

return 1;
////////////////////////////////



////////////////////////////////
// funcc7570
V1 = w[800c9df4];
[V1 + V0 * 28 + 1c] = w(A1);
[V1 + V0 * 28 + 20] = w(A1 * A1);
return 1;
////////////////////////////////



////////////////////////////////
// funcc3e18
A2 = A0;
if (A1 != 0)
{
    V0 = w[800c9df4];
    [V0 + A2 * 28 + 0] = h(hu[V0 + A2 * 28 + 0] | 0001);
}
else
{
    V0 = w[800c9df4];
    [V0 + A2 * 28 + 0] = h(hu[V0 + A2 * 28 + 0] & fffe);
    [V0 + A2 * 28 + 4] = h(-1);
    [V0 + A2 * 28 + 6] = h(-1);
    [V0 + A2 * 28 + 8] = h(-1);
    [V0 + A2 * 28 + a] = h(-1);
}

return 1;
////////////////////////////////



////////////////////////////////
// funcc0fb0
// restore screen offset to GPU
func12ad4;
if( V0 & 2 )
{
    return 1;
}

OFX = a0 << 10;
OFY = 70 << 10;

return 1;
////////////////////////////////



////////////////////////////////
// funcc0f08
// set screen offset to GPU
A0 = w[800c9db4];
S0 = A0 + bu[800ca068 + 75] * 34 + w[A0 + 18];

func12ad4;

if( ( ( V0 & 2 ) == 0 ) || ( w[80071e34] < 2 ) )
{
    OFX = ( h[S0 + 20] + h[800ca068 + c] ) << 10;
    OFY = ( h[S0 + 22] + h[800ca068 + e] ) << 10;
}

return 1;
////////////////////////////////



////////////////////////////////
// funcafac0
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4]; // 800d1000
V0 = w[V0 + c];
V0 = w[V0 + 14];

S1 = A2;
V1 = w[V0 + 10];
A2 = A4;

if (V1 == 0)
{
    return;
}

S2 = A3;

V1 = w[V1 + 8];
S0 = V1 + A0 * 24;

if (A1 == 82)
{
    if (S1 != -1)
    {
        A0 = S0;
        800AFB38	jal    funcb00b0 [$800b00b0]

        800AFB40	addiu  a0, zero, $0004
        800AFB44	andi   v0, s1, $ffff
        800AFB48	lui    a1, $0016
        800AFB4C	or     a1, v0, a1
        800AFB50	addu   a2, zero, zero
        800AFB54	jal    func1c7fc [$8001c7fc]
        800AFB58	sb     s1, $0001(s0)
        800AFB5C	addu   a0, v0, zero
        800AFB60	jal    funcc9700 [$800c9700]
        800AFB64	sw     a0, $0018(s0)
        [S0 + e] = h(V0 * 10);
    }
    else
    {
        [S0 + 18] = w(0);
    }
}
else if (A1 == 83)
{
    if (S2 != 0)
    {
        800AFB88	addiu  v1, zero, $fff0 (=-$10)
        800AFB8C	lw     v0, $0000(s0)
        800AFB90	nop
        800AFB94	and    v1, v0, v1
        800AFB98	or     v0, s1, v0
        800AFBA0	andi   v0, v0, $000f
    }
    else
    {
        800AFB88	addiu  v1, zero, $fff0 (=-$10)
        800AFBA4	lw     v0, $0000(s0)
        800AFBA8	nor    a0, zero, s1
        800AFBAC	and    v1, v0, v1
        800AFBB0	andi   v0, v0, $000f
        800AFBB4	and    v0, v0, a0
    }

    800AFBB8	or     v1, v1, v0
    800AFBC0	sw     v1, $0000(s0)
}
else if (A1 == 87)
{
    800AFBD0	sh     s1, $0008(s0)
    800AFBD4	sh     s2, $000a(s0)
    800AFBDC	sh     a2, $000c(s0)
}
else if (A1 == 8c)
{
    800AFBE8	sh     s1, $0010(s0)
    800AFBEC	sh     s2, $0012(s0)
    800AFBF4	sh     a2, $0014(s0)
}
else if (A1 == 91)
{
    800AFC04	sh     s1, $0004(s0)
}
else if (A1 == 96)
{
    800AFC10	jal    func4b098 [$8004b098]
    800AFC14	addu   a0, s1, zero
    800AFC18	sb     v0, $0002(s0)
    800AFC20	sb     s2, $0003(s0)
}
else if (A1 == 9b)
{
    800AFC30	sb     s1, $0007(s0)
}
else if (A1 == 9c)
{
    800AFC3C	lw     v0, $0000(s0)
    800AFC40	addiu  v1, zero, $ff0f (=-$f1)
    800AFC44	and    v0, v0, v1
    800AFC48	andi   v1, s1, $000f
    800AFC4C	sll    v1, v1, $04
    800AFC50	or     v0, v0, v1
    800AFC58	sw     v0, $0000(s0)
}
else if (A1 == a0)
{
    800AFC68	sb     s1, $0006(s0)
}
else if (A1 == a1)
{
    [S0 + 16] = h(S1 * 10);
}
else if (A1 == a5)
{
    800AFC84	addiu  v0, zero, $00aa
    800AFC88	sh     s1, $001c(s0)
    800AFC8C	sh     s2, $001e(s0)
    800AFC94	sh     a2, $0020(s0)
}
else if (A1 == aa)
{
    [S0 + 22] = h(S1);
}
////////////////////////////////