////////////////////////////////
// func589f0
800589F0	addiu  sp, sp, $ffc0 (=-$40)
800589F4	lui    v0, $8008
800589F8	addiu  v1, v0, $0a70
800589FC	lw     a0, $0a70(v0)
80058A00	lui    a1, $8008
80058A04	sw     ra, $0038(sp)
80058A08	sw     s7, $0034(sp)
80058A0C	sw     s6, $0030(sp)
80058A10	sw     s5, $002c(sp)
80058A14	sw     s4, $0028(sp)
80058A18	sw     s3, $0024(sp)
80058A1C	sw     s2, $0020(sp)
80058A20	sw     s1, $001c(sp)
80058A24	sw     s0, $0018(sp)
80058A28	lw     v0, $0010(v1)
80058A2C	lw     a1, $3174(a1)
80058A30	or     a0, a0, v0
80058A34	lui    v0, $8008
80058A38	lw     v1, $0a10(v0)
80058A3C	sw     zero, $0010(sp)
80058A40	lw     v0, $0004(v1)
80058A44	lw     v1, $0010(v1)
80058A48	nop
80058A4C	and    v0, v0, v1
80058A50	bne    v0, zero, L58a84 [$80058a84]
80058A54	or     s2, a0, a1
80058A58	lui    v0, $8008
80058A5C	lw     v1, $f790(v0)
80058A60	nop
80058A64	beq    v1, zero, L58c60 [$80058c60]
80058A68	lui    s0, $8008
80058A6C	lw     v0, $0004(v1)
80058A70	lw     v1, $0010(v1)
80058A74	nop
80058A78	and    v0, v0, v1
80058A7C	beq    v0, zero, L58a90 [$80058a90]
80058A80	lui    s6, $8008

L58a84:	; 80058A84
80058A84	jal    func588b0 [$800588b0]
80058A88	addu   a0, s2, zero
80058A8C	lui    s6, $8008

L58a90:	; 80058A90
80058A90	lw     a0, $f790(s6)
80058A94	nop
80058A98	beq    a0, zero, L58c5c [$80058c5c]
80058A9C	lui    v0, $8008
80058AA0	addiu  s7, v0, $3158
80058AA4	lw     v0, $0004(s7)
80058AA8	nop
80058AAC	andi   v0, v0, $0100
80058AB0	beq    v0, zero, L58ac4 [$80058ac4]
80058AB4	lui    v0, $8008
80058AB8	lw     a1, $f71c(v0)
80058ABC	jal    func58990 [$80058990]
80058AC0	nop

L58ac4:	; 80058AC4
80058AC4	lw     a1, $f790(s6)
80058AC8	nop
80058ACC	lw     v1, $0004(a1)
80058AD0	lw     v0, $0014(a1)
80058AD4	lw     a0, $000c(a1)
80058AD8	lui    s5, $8008
80058ADC	sw     a1, $0a10(s5)
80058AE0	and    v1, v1, v0
80058AE4	and    v0, a0, s2
80058AE8	nor    v0, zero, v0
80058AEC	and    s0, v1, v0
80058AF0	and    a0, s0, a0
80058AF4	nor    v0, zero, s2
80058AF8	lw     v1, $0008(a1)
80058AFC	nop
80058B00	and    a1, s0, v1
80058B04	beq    a1, zero, L58b4c [$80058b4c]
80058B08	and    s1, a0, v0
80058B0C	addu   a2, s1, zero
80058B10	lui    v0, $8008
80058B14	lw     a0, $f71c(v0)
80058B18	jal    func585e0 [$800585e0]
80058B1C	addiu  a3, sp, $0010
80058B20	lw     a0, $0a10(s5)
80058B24	nop
80058B28	lw     v0, $0008(a0)
80058B2C	nop
80058B30	nor    v0, zero, v0
80058B34	and    s0, s0, v0
80058B38	lw     v0, $0008(a0)
80058B3C	lw     v1, $0010(a0)
80058B40	nor    v0, zero, v0
80058B44	and    v1, v1, v0
80058B48	sw     v1, $0010(a0)

L58b4c:	; 80058B4C
80058B4C	lui    v0, $8008
80058B50	addiu  s4, v0, $f858 (=-$7a8)
80058B54	lw     a1, $0004(s4)
80058B58	lw     v0, $0014(s4)
80058B5C	lw     a0, $000c(s4)
80058B60	or     v1, s1, s2
80058B64	sw     s4, $0a10(s5)
80058B68	and    a1, a1, v0
80058B6C	and    v0, a0, v1
80058B70	nor    v0, zero, v0
80058B74	and    s3, a1, v0
80058B78	and    a0, s3, a0
80058B7C	nor    v1, zero, v1
80058B80	lw     v0, $0008(s4)
80058B84	nop
80058B88	and    a1, s3, v0
80058B8C	beq    a1, zero, L58bd4 [$80058bd4]
80058B90	and    s2, a0, v1
80058B94	lui    a0, $8008
80058B98	addiu  a0, a0, $bd48 (=-$42b8)
80058B9C	addu   a2, s2, zero
80058BA0	jal    func585e0 [$800585e0]
80058BA4	addiu  a3, sp, $0010
80058BA8	lw     a0, $0a10(s5)
80058BAC	nop
80058BB0	lw     v0, $0008(a0)
80058BB4	nop
80058BB8	nor    v0, zero, v0
80058BBC	and    s3, s3, v0
80058BC0	lw     v0, $0008(a0)
80058BC4	lw     v1, $0010(a0)
80058BC8	nor    v0, zero, v0
80058BCC	and    v1, v1, v0
80058BD0	sw     v1, $0010(a0)

L58bd4:	; 80058BD4
80058BD4	beq    s0, zero, L58c08 [$80058c08]
80058BD8	addu   a1, s0, zero
80058BDC	nor    a2, zero, s2
80058BE0	and    a2, s1, a2
80058BE4	lui    v0, $8008
80058BE8	lw     a0, $f71c(v0)
80058BEC	lw     v0, $f790(s6)
80058BF0	addiu  a3, sp, $0010
80058BF4	jal    func585e0 [$800585e0]
80058BF8	sw     v0, $0a10(s5)
80058BFC	lw     v0, $0a10(s5)
80058C00	sw     s4, $0a10(s5)
80058C04	sw     zero, $0010(v0)

L58c08:	; 80058C08
80058C08	beq    s3, zero, L58c30 [$80058c30]
80058C0C	lui    a0, $8008
80058C10	addiu  a0, a0, $bd48 (=-$42b8)
80058C14	addu   a1, s3, zero
80058C18	addu   a2, s2, zero
80058C1C	jal    func585e0 [$800585e0]
80058C20	addiu  a3, sp, $0010
80058C24	lw     v0, $0a10(s5)
80058C28	nop
80058C2C	sw     zero, $0010(v0)

L58c30:	; 80058C30
80058C30	lw     v0, $0004(s7)
80058C34	nop
80058C38	andi   v0, v0, $0100
80058C3C	beq    v0, zero, L58d08 [$80058d08]
80058C40	lui    v0, $8008
80058C44	lw     a0, $f790(s6)
80058C48	lw     a1, $f71c(v0)
80058C4C	jal    func589e0 [$800589e0]
80058C50	nop
80058C54	j      L58d0c [$80058d0c]
80058C58	lui    v0, $8008

L58c5c:	; 80058C5C
80058C5C	lui    s0, $8008

L58c60:	; 80058C60
80058C60	lw     a1, $0a10(s0)
80058C64	nop
80058C68	lw     v1, $0004(a1)
80058C6C	lw     v0, $0014(a1)
80058C70	lw     a0, $000c(a1)
80058C74	and    v1, v1, v0
80058C78	and    v0, a0, s2
80058C7C	nor    v0, zero, v0
80058C80	and    s3, v1, v0
80058C84	and    a0, s3, a0
80058C88	nor    v0, zero, s2
80058C8C	lw     v1, $0008(a1)
80058C90	nop
80058C94	and    a1, s3, v1
80058C98	beq    a1, zero, L58ce0 [$80058ce0]
80058C9C	and    s2, a0, v0
80058CA0	lui    a0, $8008
80058CA4	addiu  a0, a0, $bd48 (=-$42b8)
80058CA8	addu   a2, s2, zero
80058CAC	jal    func585e0 [$800585e0]
80058CB0	addiu  a3, sp, $0010
80058CB4	lw     a0, $0a10(s0)
80058CB8	nop
80058CBC	lw     v0, $0008(a0)
80058CC0	nop
80058CC4	nor    v0, zero, v0
80058CC8	and    s3, s3, v0
80058CCC	lw     v0, $0008(a0)
80058CD0	lw     v1, $0010(a0)
80058CD4	nor    v0, zero, v0
80058CD8	and    v1, v1, v0
80058CDC	sw     v1, $0010(a0)

L58ce0:	; 80058CE0
80058CE0	beq    s3, zero, L58d08 [$80058d08]
80058CE4	lui    a0, $8008
80058CE8	addiu  a0, a0, $bd48 (=-$42b8)
80058CEC	addu   a1, s3, zero
80058CF0	addu   a2, s2, zero
80058CF4	jal    func585e0 [$800585e0]
80058CF8	addiu  a3, sp, $0010
80058CFC	lw     v0, $0a10(s0)
80058D00	nop
80058D04	sw     zero, $0010(v0)

L58d08:	; 80058D08
80058D08	lui    v0, $8008

L58d0c:	; 80058D0C
80058D0C	addiu  a0, v0, $0a70
80058D10	lw     v1, $0a70(v0)
80058D14	lw     v0, $0008(a0)
80058D18	nop
80058D1C	and    s3, v1, v0
80058D20	beq    s3, zero, L58d98 [$80058d98]
80058D24	lui    v0, $8008
80058D28	addiu  s2, zero, $0100
80058D2C	addiu  s1, v0, $e3d8 (=-$1c28)
80058D30	lw     v0, $0010(sp)
80058D34	lw     v1, $0004(a0)
80058D38	addiu  s0, s1, $0034
80058D3C	or     v0, v0, v1
80058D40	sw     v0, $0010(sp)

loop58d44:	; 80058D44
80058D44	and    v0, s3, s2
80058D48	beq    v0, zero, L58d80 [$80058d80]
80058D4C	addu   a0, s1, zero
80058D50	jal    func58118 [$80058118]
80058D54	addu   a1, s2, zero
80058D58	lw     v0, $00e8(s0)
80058D5C	nop
80058D60	beq    v0, zero, L58d7c [$80058d7c]
80058D64	nor    v0, zero, s2
80058D68	lw     a0, $00e4(s0)
80058D6C	lw     a2, $0000(s0)
80058D70	jal    func57898 [$80057898]
80058D74	addiu  a1, s1, $0118
80058D78	nor    v0, zero, s2

L58d7c:	; 80058D7C
80058D7C	and    s3, s3, v0

L58d80:	; 80058D80
80058D80	sll    s2, s2, $01
80058D84	addiu  s0, s0, $0134
80058D88	bne    s3, zero, loop58d44 [$80058d44]
80058D8C	addiu  s1, s1, $0134
80058D90	lui    v0, $8008
80058D94	sw     zero, $0a74(v0)

L58d98:	; 80058D98
80058D98	lui    v0, $8008
80058D9C	addiu  s0, v0, $3158
80058DA0	lw     s3, $0008(s0)
80058DA4	nop
80058DA8	andi   v0, s3, $0080
80058DAC	beq    v0, zero, L58de4 [$80058de4]
80058DB0	lui    v0, $8008
80058DB4	lw     v0, $0a10(v0)
80058DB8	nop
80058DBC	lw     a0, $0048(v0)
80058DC0	nop
80058DC4	sll    a0, a0, $04
80058DC8	sra    a0, a0, $10
80058DCC	jal    func5933c [$8005933c]
80058DD0	addu   a1, a0, zero
80058DD4	lw     v0, $0008(s0)
80058DD8	addiu  v1, zero, $ff7f (=-$81)
80058DDC	and    v0, v0, v1
80058DE0	sw     v0, $0008(s0)

L58de4:	; 80058DE4
80058DE4	andi   v0, s3, $0010
80058DE8	beq    v0, zero, L58e3c [$80058e3c]
80058DEC	lui    v0, $8008
80058DF0	lw     v1, $0a70(v0)
80058DF4	nop
80058DF8	beq    v1, zero, L58e0c [$80058e0c]
80058DFC	addiu  v0, v0, $0a70
80058E00	lhu    a0, $0028(v0)
80058E04	j      L58e1c [$80058e1c]
80058E08	nop

L58e0c:	; 80058E0C
80058E0C	lui    v0, $8008
80058E10	lw     v0, $0a10(v0)
80058E14	nop
80058E18	lhu    a0, $006e(v0)

L58e1c:	; 80058E1C
80058E1C	jal    func592cc [$800592cc]
80058E20	nop
80058E24	lui    v0, $8008
80058E28	addiu  v0, v0, $3158
80058E2C	lw     v1, $0008(v0)
80058E30	addiu  a0, zero, $ffef (=-$11)
80058E34	and    v1, v1, a0
80058E38	sw     v1, $0008(v0)

L58e3c:	; 80058E3C
80058E3C	andi   v0, s3, $0100
80058E40	beq    v0, zero, L58ef0 [$80058ef0]
80058E44	lui    s1, $8008
80058E48	addiu  s1, s1, $0a70
80058E4C	lui    s3, $8008
80058E50	lui    s4, $8008
80058E54	lui    s0, $8008
80058E58	addiu  s0, s0, $323c
80058E5C	lw     a3, $001c(s1)
80058E60	lw     v0, $f790(s3)
80058E64	lw     v1, $0a10(s4)
80058E68	lw     a1, $003c(v0)
80058E6C	lw     a2, $003c(v1)
80058E70	jal    func59140 [$80059140]
80058E74	addu   a0, s0, zero
80058E78	addiu  s2, s0, $fffc (=-$4)
80058E7C	lw     a3, $0020(s1)
80058E80	lw     v0, $f790(s3)
80058E84	lw     v1, $0a10(s4)
80058E88	lw     a1, $0040(v0)
80058E8C	lw     a2, $0040(v1)
80058E90	jal    func59140 [$80059140]
80058E94	addu   a0, s2, zero
80058E98	lw     a3, $0024(s1)
80058E9C	lw     v0, $f790(s3)
80058EA0	lw     v1, $0a10(s4)
80058EA4	lw     a1, $0044(v0)
80058EA8	lw     a2, $0044(v1)
80058EAC	jal    func59140 [$80059140]
80058EB0	addiu  a0, s0, $0004
80058EB4	lw     a0, $fffc(s0)
80058EB8	jal    func575ec [$800575ec]
80058EBC	nop
80058EC0	lw     a0, $0004(s2)
80058EC4	jal    func57608 [$80057608]
80058EC8	nop
80058ECC	lw     a0, $0008(s2)
80058ED0	jal    func57624 [$80057624]
80058ED4	nop
80058ED8	lui    v1, $8008
80058EDC	addiu  v1, v1, $3158
80058EE0	lw     v0, $0008(v1)
80058EE4	addiu  a0, zero, $feff (=-$101)
80058EE8	and    v0, v0, a0
80058EEC	sw     v0, $0008(v1)

L58ef0:	; 80058EF0
80058EF0	lw     a0, $0010(sp)
80058EF4	nop
80058EF8	beq    a0, zero, L58f08 [$80058f08]
80058EFC	nop
80058F00	jal    func575b4 [$800575b4]
80058F04	nop

L58f08:	; 80058F08
80058F08	lw     ra, $0038(sp)
80058F0C	lw     s7, $0034(sp)
80058F10	lw     s6, $0030(sp)
80058F14	lw     s5, $002c(sp)
80058F18	lw     s4, $0028(sp)
80058F1C	lw     s3, $0024(sp)
80058F20	lw     s2, $0020(sp)
80058F24	lw     s1, $001c(sp)
80058F28	lw     s0, $0018(sp)
80058F2C	jr     ra 
80058F30	addiu  sp, sp, $0040
////////////////////////////////



////////////////////////////////
// func585e0
800585E0	addiu  sp, sp, $ffc0 (=-$40)
800585E4	lui    v0, $8008
800585E8	sw     fp, $0038(sp)
800585EC	addu   fp, v0, zero
800585F0	lw     v0, $0a10(fp)
800585F4	sw     s6, $0030(sp)
800585F8	addu   s6, a0, zero
800585FC	sw     s4, $0028(sp)
80058600	addu   s4, a1, zero
80058604	sw     s7, $0034(sp)
80058608	addu   s7, a3, zero
8005860C	sw     s2, $0020(sp)
80058610	addiu  s2, zero, $0001
80058614	sw     s5, $002c(sp)
80058618	addu   s5, zero, zero
8005861C	sw     s1, $001c(sp)
80058620	addiu  s1, s6, $0034
80058624	sw     ra, $003c(sp)
80058628	sw     s3, $0024(sp)
8005862C	sw     s0, $0018(sp)
80058630	sw     a2, $0048(sp)
80058634	lw     v0, $0010(v0)
80058638	addiu  s3, s6, $0118
8005863C	and    v0, s4, v0
80058640	sw     v0, $0010(sp)

L58644:	; 80058644
80058644	and    v0, s4, s2
80058648	beq    v0, zero, L587e8 [$800587e8]
8005864C	addu   a0, s6, zero
80058650	jal    func57d80 [$80057d80]
80058654	addu   a1, s2, zero
80058658	lw     v0, $00e8(s1)
8005865C	nop
80058660	beq    v0, zero, L587e0 [$800587e0]
80058664	lui    v0, $8008
80058668	lw     v0, $0ac4(v0)
8005866C	nop
80058670	and    v0, v0, s2
80058674	beq    v0, zero, L58684 [$80058684]
80058678	nop
8005867C	sh     zero, $00fe(s1)
80058680	sh     zero, $00fc(s1)

L58684:	; 80058684
80058684	lw     t0, $0010(sp)
80058688	nop
8005868C	and    v0, t0, s2
80058690	beq    v0, zero, L587c0 [$800587c0]
80058694	nop
80058698	lw     t0, $0048(sp)
8005869C	nop
800586A0	and    v0, t0, s2
800586A4	beq    v0, zero, L586c4 [$800586c4]
800586A8	addiu  t0, zero, $0001
800586AC	lw     v0, $0000(s7)
800586B0	sllv   v1, s5, t0
800586B4	or     v0, v0, v1
800586B8	sw     v0, $0000(s7)
800586BC	j      L58768 [$80058768]
800586C0	sw     s5, $00e4(s1)

L586c4:	; 800586C4
800586C4	lw     v0, $0a10(fp)
800586C8	nop
800586CC	lw     v0, $0008(v0)
800586D0	nop
800586D4	and    v0, v0, s2
800586D8	sltu   s0, zero, v0
800586DC	jal    func58578 [$80058578]
800586E0	addu   a0, s0, zero
800586E4	addu   a0, v0, zero
800586E8	addiu  t0, zero, $0018
800586EC	bne    a0, t0, L5873c [$8005873c]
800586F0	addiu  t0, zero, $0001
800586F4	lw     v1, $0a10(fp)
800586F8	nop
800586FC	lw     v0, $0000(v1)
80058700	addu   a0, s0, zero
80058704	ori    v0, v0, $0002
80058708	jal    func584c8 [$800584c8]
8005870C	sw     v0, $0000(v1)
80058710	addu   a0, v0, zero
80058714	addiu  t0, zero, $0018
80058718	bne    a0, t0, L5873c [$8005873c]
8005871C	addiu  t0, zero, $0001
80058720	lw     v1, $0a10(fp)
80058724	sw     a0, $00e4(s1)
80058728	lw     v0, $0000(v1)
8005872C	nop
80058730	ori    v0, v0, $0001
80058734	j      L58768 [$80058768]
80058738	sw     v0, $0000(v1)

L5873c:	; 8005873C
8005873C	sllv   v1, a0, t0
80058740	lui    t0, $8008
80058744	lw     v0, $0000(s7)
80058748	addiu  t0, t0, $f798 (=-$868)
8005874C	or     v0, v0, v1
80058750	sw     v0, $0000(s7)
80058754	sll    v0, a0, $03
80058758	addu   v0, v0, t0
8005875C	addiu  v1, zero, $7fff
80058760	sw     a0, $00e4(s1)
80058764	sh     v1, $0004(v0)

L58768:	; 80058768
80058768	lw     a0, $00e4(s1)
8005876C	nop
80058770	sltiu  v0, a0, $0018
80058774	beq    v0, zero, L587e4 [$800587e4]
80058778	nor    v0, zero, s2
8005877C	lhu    a2, $00fa(s1)
80058780	jal    func577ec [$800577ec]
80058784	addu   a1, s3, zero
80058788	lui    t0, $8008
8005878C	addiu  t0, t0, $31c8
80058790	lw     v0, $00e4(s1)
80058794	lw     v1, $0a10(fp)
80058798	sll    v0, v0, $02
8005879C	addu   v0, v0, t0
800587A0	sw     v1, $0000(v0)
800587A4	lui    v1, $8008
800587A8	addiu  v1, v1, $3158
800587AC	lw     v0, $0008(v1)
800587B0	nop
800587B4	ori    v0, v0, $0100
800587B8	j      L587e0 [$800587e0]
800587BC	sw     v0, $0008(v1)

L587c0:	; 800587C0
800587C0	lw     a0, $00e4(s1)
800587C4	nop
800587C8	sltiu  v0, a0, $0018
800587CC	beq    v0, zero, L587e4 [$800587e4]
800587D0	nor    v0, zero, s2
800587D4	lw     a2, $0000(s1)
800587D8	jal    func57898 [$80057898]
800587DC	addu   a1, s3, zero

L587e0:	; 800587E0
800587E0	nor    v0, zero, s2

L587e4:	; 800587E4
800587E4	and    s4, s4, v0

L587e8:	; 800587E8
800587E8	sll    s2, s2, $01
800587EC	addiu  s1, s1, $0134
800587F0	addiu  s3, s3, $0134
800587F4	addiu  s6, s6, $0134
800587F8	bne    s4, zero, L58644 [$80058644]
800587FC	addiu  s5, s5, $0001
80058800	lw     ra, $003c(sp)
80058804	lw     fp, $0038(sp)
80058808	lw     s7, $0034(sp)
8005880C	lw     s6, $0030(sp)
80058810	lw     s5, $002c(sp)
80058814	lw     s4, $0028(sp)
80058818	lw     s3, $0024(sp)
8005881C	lw     s2, $0020(sp)
80058820	lw     s1, $001c(sp)
80058824	lw     s0, $0018(sp)
80058828	jr     ra 
8005882C	addiu  sp, sp, $0040
////////////////////////////////



////////////////////////////////
// func57898
80057898	addiu  sp, sp, $ffe0 (=-$20)
8005789C	sw     s1, $0014(sp)
800578A0	addu   s1, a1, zero
800578A4	sw     ra, $001c(sp)
800578A8	sw     s2, $0018(sp)
800578AC	sw     s0, $0010(sp)
800578B0	lw     s0, $0004(s1)
800578B4	nop
800578B8	beq    s0, zero, L5799c [$8005799c]
800578BC	addu   s2, a0, zero
800578C0	andi   v0, s0, $0010
800578C4	beq    v0, zero, L578e4 [$800578e4]
800578C8	sw     zero, $0004(s1)
800578CC	addiu  v0, zero, $ffef (=-$11)
800578D0	lhu    a1, $0010(s1)
800578D4	jal    func57688 [$80057688]
800578D8	and    s0, s0, v0
800578DC	beq    s0, zero, L5799c [$8005799c]
800578E0	nop

L578e4:	; 800578E4
800578E4	andi   v0, s0, $0003
800578E8	beq    v0, zero, L57910 [$80057910]
800578EC	addiu  v0, zero, $fffc (=-$4)
800578F0	and    s0, s0, v0
800578F4	lh     a1, $0018(s1)
800578F8	lh     a2, $001a(s1)
800578FC	lhu    a3, $0016(s1)
80057900	jal    func57640 [$80057640]
80057904	addu   a0, s2, zero
80057908	beq    s0, zero, L5799c [$8005799c]
8005790C	nop

L57910:	; 80057910
80057910	andi   v0, s0, $0080
80057914	beq    v0, zero, L57934 [$80057934]
80057918	addiu  v0, zero, $ff7f (=-$81)
8005791C	and    s0, s0, v0
80057920	lw     a1, $0008(s1)
80057924	jal    func576a0 [$800576a0]
80057928	addu   a0, s2, zero
8005792C	beq    s0, zero, L5799c [$8005799c]
80057930	nop

L57934:	; 80057934
80057934	lui    v0, $0001
80057938	and    v0, s0, v0
8005793C	beq    v0, zero, L57960 [$80057960]
80057940	lui    v0, $fffe
80057944	ori    v0, v0, $ffff
80057948	and    s0, s0, v0
8005794C	lw     a1, $000c(s1)
80057950	jal    func576bc [$800576bc]
80057954	addu   a0, s2, zero
80057958	beq    s0, zero, L5799c [$8005799c]
8005795C	nop

L57960:	; 80057960
80057960	andi   v0, s0, $6600
80057964	beq    v0, zero, L57984 [$80057984]
80057968	addiu  v0, zero, $99ff (=-$6601)
8005796C	and    s0, s0, v0
80057970	lhu    a1, $0014(s1)
80057974	jal    func576f0 [$800576f0]
80057978	addu   a0, s2, zero
8005797C	beq    s0, zero, L5799c [$8005799c]
80057980	nop

L57984:	; 80057984
80057984	andi   v0, s0, $9900
80057988	beq    v0, zero, L5799c [$8005799c]
8005798C	nop
80057990	lhu    a1, $0012(s1)
80057994	jal    func576d8 [$800576d8]
80057998	addu   a0, s2, zero

L5799c:	; 8005799C
8005799C	lw     ra, $001c(sp)
800579A0	lw     s2, $0018(sp)
800579A4	lw     s1, $0014(sp)
800579A8	lw     s0, $0010(sp)
800579AC	jr     ra 
800579B0	addiu  sp, sp, $0020
////////////////////////////////
