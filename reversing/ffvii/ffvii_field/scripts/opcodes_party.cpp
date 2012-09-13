0x74 GETPC 800d2f3c

0xCB IFPRTYQ 800cf718
0xCC IFMEMBQ 800cf874



////////////////////////////////
// 0x0A SPTYE
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
////////////////////////////////



////////////////////////////////
// 0x0B GTPYE
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



////////////////////////////////
// 0x39 GOLDu
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
////////////////////////////////



////////////////////////////////
// 0x3A GOLDd
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
////////////////////////////////



////////////////////////////////
// 0x3B CHGLD
current_entity        = bu[800722c4];
script_pointer_offset = 800831fc + current_entity * 2;

system_get_party_gil;
gil = V0;
A0 = 1;
A1 = 2;
A2 = (gil << 10) >> 10;
store_memory_block_two_bytes;

A0 = 2;
A1 = 3;
A2 = gil >> 10;
store_memory_block_two_bytes;

[script_pointer_offset] = h(hu[script_pointer_offset] + 4);
////////////////////////////////



////////////////////////////////
// 0x3C HMPMAX1
// 0x3D HMPMAX2
// 0x3F HMPMAX3
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
////////////////////////////////



////////////////////////////////
// 0x3E MHMMX
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
////////////////////////////////



////////////////////////////////
// 0x45 MPu
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
////////////////////////////////



////////////////////////////////
// 0x47 MPd
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
////////////////////////////////



////////////////////////////////
// 0x4D HPu
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
////////////////////////////////



////////////////////////////////
// 0x4F HPd
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
////////////////////////////////



////////////////////////////////
// 0x58 STITM
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
////////////////////////////////



////////////////////////////////
// 0x59 DLITM
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
////////////////////////////////



////////////////////////////////
// 0x5A CKITM
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
////////////////////////////////



////////////////////////////////
// 0x5B SMTRA
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
////////////////////////////////



////////////////////////////////
// 0x5C DMTRA
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
////////////////////////////////



////////////////////////////////
// 0x5D CMTRA
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



////////////////////////////////
// 0xC8 PRTYP
V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];
character_id = bu[V0 + V1 + 1];



// if character already in party
A0 = 0;
loopceeac:	; 800CEEAC
    V0 = bu[8009c6e4 + 0cad + A0]; // party info in savemap
    if (V0 == character_id)
    {
        V1 = bu[800722c4];
        [800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

        field_set_1st_party_character_as_manual_model;

        field_copy_party_to_battle_party;

        return 0;
    }

    A0 = A0 + 1;
    V0 = A0 < 3;
800CEEFC	bne    v0, zero, loopceeac [$800ceeac]



// if not in party
A0 = 0;
loopcef14:	; 800CEF14
    V0 = bu[8009c6e4 + 0cad + A0]; // party info in savemap

    if (V0 == ff)
    {
        [8009c6e4 + 0cad + A0] = b(character_id);

        if (character_id != ff)
        {
            V1 = hu[8009c6e4 + +10a6];
            V0 = 1 << character_id;
            V1 = V1 | V0;
            [8009c6e4 + +10a6] = h(V1);
        }

        V1 = bu[800722c4];
        [800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

        field_set_1st_party_character_as_manual_model;

        field_copy_party_to_battle_party;

        return 0;
    }

    A0 = A0 + 1;
    V0 = A0 < 3;
800CEF70	bne    v0, zero, loopcef14 [$800cef14]



// else add in last slot
[8009c6e4 + 0cad + 2] = b(character_id);
if (character_id != ff)
{
    V1 = hu[8009c6e4 + +10a6];
    V0 = 1 << character_id;
    V1 = V1 | V0;
    [8009c6e4 + +10a6] = h(V1);
}

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

A0 = A0;
field_set_1st_party_character_as_manual_model;

A0 = 1;
field_copy_party_to_battle_party;

return 0;
////////////////////////////////



////////////////////////////////
// 0xC9 PRTYM
V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];
character_id = bu[V0 + V1 + 1];

i = 0;
loopcf098:	; 800CF098
    V0 = bu[8009d391 + i];
    if (V0 == character_id)
    {
        [8009d391 + i] = b(ff);

        field_copy_party_to_battle_party;

        field_set_1st_party_character_as_manual_model;

        V1 = bu[800722c4];
        [800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);
        return 0;
    }

    i = i + 1
    V0 = i < 3;
800CF0EC	bne    v0, zero, loopcf098 [$800cf098]

field_copy_party_to_battle_party;
field_set_1st_party_character_as_manual_model;

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCA PRTYE
A0 = 0;
loopcf178:	; 800CF178
    V0 = bu[800722c4];
    V1 = hu[800831fc + V0 * 2];
    V0 = w[8009c6dc];
    [SP + 10 + A0] = b(bu[V0 + V1 + A0 + 1]);

    A0 = A0 + 1;
    V0 = A0 < 3;
800CF1B4	bne    v0, zero, loopcf178 [$800cf178]

A0 = SP + 10;
funccf368;

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 4);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCD MMBud
V0 = bu[800722c4];
V1 = hu[800831fc + V0 * 2];
V0 = w[8009c6dc];
A2 = bu[V0 + V1 + 2];
V1 = bu[V0 + V1 + 1];

if (V1 != 0)
{
    A0 = hu[8009c6e4 + 10a6];
    V1 = 1 << A2;
    A0 = A0 | V1;
    [8009c6e4 + 10a6] = h(A0);
}
else
{
    V1 = hu[8009c6e4 + 10a6];
    V0 = 1 << A2;
    V0 = 0 NOR V0;
    V1 = V1 & V0;
    [8009c6e4 + 10a6] = h(V1);

    V1 = 0;
    loopcfa6c:	; 800CFA6C
        V0 = bu[8009d391 + V1];
        if (V0 == A2)
        {
            [8009d391 + V1] = b(ff);
        }

        V1 = V1 + 1;
        V0 = V1 < 3;
    800CFAAC	bne    v0, zero, loopcfa6c [$800cfa6c]
}

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 3);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCE MMBLK
A0 = bu[800722c4];
V1 = hu[800831fc + A0 * 2];
V0 = w[8009c6dc];
A1 = bu[V0 + V1 + 1];

V0 = hu[8009c6e4 + 10a4];
V1 = 1 << A1;
V0 = V0 | V1;
[8009c6e4 + 10a4] = h(V0);

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

return 0;
////////////////////////////////



////////////////////////////////
// 0xCF MMBUK
A0 = bu[800722c4];
V1 = hu[800831fc + A0 * 2];
V0 = w[8009c6dc];
A1 = bu[V0 + V1 + 1];

V0 = hu[8009c6e4 + 10a4];
V1 = 1 << A1;
V0 = 0 NOR V1;
V1 = V1 & V0;
[8009c6e4 + 10a4] = h(V1);

V1 = bu[800722c4];
[800831fc + V1 * 2] = h(hu[800831fc + V1 * 2] + 2);

return 0;
////////////////////////////////








////////////////////////////////
// field_set_1st_party_character_as_manual_model
V0 = bu[8009c6e4 + 0cad];
if (V0 != ff) // if character exist
{
    A0 = bu[8009ad30 + V0];
    if (A0 != ff) // if entity exist
    {
        V0 = bu[8007eb98 + A0];
        if (V1 != ff) // if model exist
        {
            V1 = w[8009c6e0];
            V0 = bu[8007eb98 + A0];
            [V1 + 2a] = h(V0); // manual model id
        }
    }
}
////////////////////////////////



////////////////////////////////
// field_copy_party_to_battle_party
A0 = 8009c6e4 + 04f8; // party used in battle
A1 = 8009c6e4 + 0cad; // party
A2 = SP + 10; // if something in A1 which is not in A0
A3 = SP + 18; // if something in A0 which is not in A1
funccf4cc;

// remove characters from battle party if they removed from party
A0 = 8009c6e4 + 04f8;
A1 = SP + 18;
funccf66c;

// add missing characters
A0 = 8009c6e4 + 04f8;
A1 = SP + 10;
funccf6c0;

[80071e34] = b(1);
////////////////////////////////



////////////////////////////////
// funccf4cc
i = 0;
loopcf4dc:	; 800CF4DC
    [A2 + i] = b(ff);
    [A3 + i] = b(ff);

    i = i + 1;
    V0 = i < 3;
800CF4EC	bne    v0, zero, loopcf4dc [$800cf4dc]



i = 0;
loopcf500:	; 800CF500
    T2 = bu[A1 + i];

    V1 = 0;
    loopcf508:	; 800CF508
        V0 = bu[A0 + V1];

        if (T2 == V0)
        {
            break;
        }

        V1 = V1 + 1;
        V0 = V1 < 3;
    800CF520	bne    v0, zero, loopcf508 [$800cf508]

    if (V1 == 3)
    {
        [A2] = b(bu[A1 + i])
        A2 = A2 + 1;
    }

    i = i + 1;
    V0 = i < 3;
800CF540	bne    v0, zero, loopcf500 [$800cf500]



i = 0;
loopcf54c:	; 800CF54C
    T0 = bu[A0 + i];

    V1 = 0;
    loopcf558:	; 800CF558
        V0 = bu[A1 + V1];

        if (T0 == V0)
        {
            break;
        }

        V1 = V1 + 1;
        V0 = V1 < 3;
    800CF570	bne    v0, zero, loopcf558 [$800cf558]

    if (V1 == 3)
    {
        [A3] = b(bu[A0 + i]);
        A3 = A3 + 1;
    }

    V0 = i < 3;
800CF590	bne    v0, zero, loopcf54c [$800cf54c]
////////////////////////////////



////////////////////////////////
// funccf66c
//A0 = 8009c6e4 + 04f8; // party used in battle
//A1 = SP + 18; // if something in A0 which is not in A1

i = 0;
loopcf674:	; 800CF674
    j = 0;
    loopcf680:	; 800CF680
        if (bu[A1 + i] == bu[A0 + j])
        {
            [A0 + j] = b(ff);
        }

        j = j + 1;
        V0 = j < 3;
    800CF6A0	bne    v0, zero, loopcf680 [$800cf680]

    i = i + 1;
    V0 = i < 3;
800CF6B0	bne    v0, zero, loopcf674 [$800cf674]
////////////////////////////////



////////////////////////////////
// funccf6c0
A0 = 8009c6e4 + 04f8; // party used in battle
A1 = SP + 10; // if something in party which is not in battle party

i = 0;
loopcf6c8:	; 800CF6C8
    j = 0;
    loopcf6d4:	; 800CF6D4
        if (bu[A0 + j] == ff)
        {
            [A0 + j] = b(b[A1 + i]);

            break;
        }

        j = j + 1;
        V0 = j < 3;
    800CF6F8	bne    v0, zero, loopcf6d4 [$800cf6d4]

    i = i + 1;
    V0 = i < 3;
800CF708	bne    v0, zero, loopcf6c8 [$800cf6c8]
////////////////////////////////



////////////////////////////////
// funccf368
i = 0;
loopcf37c:	; 800CF37C
    V0 = bu[A0 + i];
    if (V0 != ff)
    {
        j = 0;
        loopcf39c:	; 800CF39C
            if (bu[8009c6e4 + 0cad + j] == bu[A0 + i])
            {
                [8009c6e4 + 0cad + j] = b(ff);
            }

            j = j + 1;
            V0 = j < 3;
        800CF3BC	bne    v0, zero, loopcf39c [$800cf39c]
    }

    i = i + 1;
    V0 = i < 3;
800CF3CC	bne    v0, zero, loopcf37c [$800cf37c]



i = 0;
loopcf3e0:	; 800CF3E0
    V0 = bu[8009c6e4 + 0cad + i];
    if (V0 != ff)
    {
        j = 0;
        loopcf3f8:	; 800CF3F8
            V0 = bu[A0 + j];
            if (V0 == ff)
            {
                [A0 + j] = b(bu[8009c6e4 + 0cad + i]);
                break;
            }

            j = j + 1;
            V0 = j < 3;
        800CF420	bne    v0, zero, loopcf3f8 [$800cf3f8]
    }

    i = i + 1;
    V0 = i < 3;
800CF430	bne    v0, zero, loopcf3e0 [$800cf3e0]



i = 0;
loopcf450:	; 800CF450
    V0 = bu[A0 + i];
    if (V0 == fe)
    {
        [A0 + i] = b(ff);
    }

    [8009d391 + i] = b(bu[A0 + i]);

    V0 = bu[A0 + i];
    if (V0 != ff)
    {
        V0 = bu[A0 + i];
        V1 = hu[8009c6e4 + 10a6];
        V0 = 1 << V0;
        V1 = V1 | V0;
        [8009c6e4 + 10a6] = h(V1);
    }

    i = i + 1;
    V0 = i < 3;
800CF4A4	bne    v0, zero, loopcf450 [$800cf450]



field_copy_party_to_battle_party;
field_set_1st_party_character_as_manual_model;
////////////////////////////////