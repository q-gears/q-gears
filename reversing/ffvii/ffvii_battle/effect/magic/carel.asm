////////////////////////////////
// 801B0000-801B001C
// main
func1b0fcc;
////////////////////////////////



80000020	addiu  sp, sp, $ffe8 (=-$18)
80000024	addiu  a2, zero, $fe0c (=-$1f4)
80000028	lui    v0, $8015
8000002C	lh     v0, $169c(v0)
80000030	lui    v1, $8016
80000034	addiu  v1, v1, $2978
80000038	sw     ra, $0014(sp)
8000003C	sw     s0, $0010(sp)
80000040	sll    v0, v0, $05
80000044	addu   s0, v0, v1
80000048	lh     a1, $0010(s0)
8000004C	jal    $800d4368
80000050	addiu  a0, s0, $0004
80000054	lui    t0, $2e80
80000058	addiu  v0, zero, $fff0 (=-$10)
8000005C	ori    t0, t0, $8080
80000060	lui    at, $1f80
80000064	sh     v0, $0002(at)
80000068	lui    at, $1f80
8000006C	sh     v0, $0000(at)
80000070	lh     v0, $0002(s0)
80000074	lui    a1, $8015
80000078	lw     a1, $17c0(a1)
8000007C	lui    a3, $801d
80000080	lw     a3, $1134(a3)
80000084	lui    at, $801b
80000088	addiu  at, at, $111c
8000008C	addu   at, at, v0
80000090	lbu    v0, $0000(at)
80000094	lui    a0, $1f80
80000098	lui    at, $1f80
8000009C	sb     v0, $0004(at)
800000A0	lbu    v1, $000d(s0)
800000A4	ori    v0, zero, $001f
800000A8	lui    at, $1f80
800000AC	sb     v0, $0006(at)
800000B0	lui    at, $1f80
800000B4	sb     v0, $0007(at)
800000B8	lui    at, $1f80
800000BC	sb     v1, $0005(at)
800000C0	lhu    v0, $0016(s0)
800000C4	ori    a2, zero, $000c
800000C8	lui    at, $1f80
800000CC	sh     v0, $000c(at)
800000D0	lhu    v0, $000e(s0)
800000D4	lui    at, $1f80
800000D8	sw     t0, $0008(at)
800000DC	lui    at, $1f80
800000E0	sh     v0, $000e(at)
800000E4	jal    $800d6260
800000E8	addiu  a1, a1, $0070
800000EC	lui    v1, $8006
800000F0	lbu    v1, $2d98(v1)
800000F4	lui    at, $801d
800000F8	sw     v0, $1134(at)
800000FC	bne    v1, zero, L0148 [$80000148]
80000100	nop
80000104	lhu    v0, $0002(s0)
80000108	lbu    v1, $000d(s0)
8000010C	addiu  v0, v0, $0001
80000110	sh     v0, $0002(s0)
80000114	sll    v0, v0, $10
80000118	sra    a0, v0, $10
8000011C	ori    v0, zero, $0080
80000120	bne    v1, v0, L013c [$8000013c]
80000124	slti   v0, a0, $0009
80000128	slti   v0, a0, $0008
8000012C	beq    v0, zero, L0144 [$80000144]
80000130	addiu  v0, zero, $ffff (=-$1)
80000134	j      $801b0148
80000138	nop

L013c:	; 8000013C
8000013C	bne    v0, zero, L0148 [$80000148]
80000140	addiu  v0, zero, $ffff (=-$1)

L0144:	; 80000144
80000144	sh     v0, $0000(s0)

L0148:	; 80000148
80000148	lw     ra, $0014(sp)
8000014C	lw     s0, $0010(sp)
80000150	addiu  sp, sp, $0018
80000154	jr     ra 
80000158	nop



////////////////////////////////
// func1b015c
if (bu[80062d98] == 0)
{
    S1 = 80162978 + h[8015169c] * 20;

    target_id = h[S1 + 12];
    number_of_bones = h[801518e4 + target_id * b9c + 10];

    S3 = 0;
    L01a4:	; 800001A4
        func42da8; // random
        bone = (h[S1 + 14] + (V0 & 3) + 1) % number_of_bones;

        [S1 + 14] = h(bone);

        A0 = 801b0020;
        funcbbeac;
        S0 = 80162978 + V0 * 20;

        A0 = target_id;
        A1 = h[S1 + 14];
        A2 = S0 + 4;
        battle_get_point_by_model_bone;

        func42da8; // random
        [S0 + 4] = h(hu[S0 + 4] + (V0 % 1f4) - fa);

        func42da8; // random
        [S0 + 6] = h(hu[S0 + 6] + (V0 % 1f4) - fa);

        func42da8; // random
        [S0 + 8] = h(hu[S0 + 8] + (V0 % 1f4) - fa);

        [S0 + d] = b(bu[S1 + d]);
        [S0 + e] = h(hu[S1 + e]);

        func42da8; // random
        [S0 + 10] = h(V0 & fff + 1000);
        [S0 + 16] = h(hu[S1 + 16]);

        S3 = S3 + 1;
        V0 = S3 < 2;
    80000340	bne    v0, zero, L01a4 [$800001a4]

    [S1 + 2] = h(h[S1 + 2] + 1);

    if (h[S1 + 2] >= 1e)
    {
        A0 = target_id;
        funcd5774; // add hurt action to target

        [S1 + 0] = h(-1);
    }
}
////////////////////////////////



800003A0	addiu  sp, sp, $ffd8 (=-$28)
800003A4	lui    v0, $8015
800003A8	lh     v0, $169c(v0)
800003AC	lui    a0, $8006
800003B0	lbu    a0, $2d98(a0)
800003B4	lui    v1, $8016
800003B8	addiu  v1, v1, $2978
800003BC	sw     ra, $0020(sp)
800003C0	sw     s3, $001c(sp)
800003C4	sw     s2, $0018(sp)
800003C8	sw     s1, $0014(sp)
800003CC	sw     s0, $0010(sp)
800003D0	sll    v0, v0, $05
800003D4	bne    a0, zero, L0628 [$80000628]
800003D8	addu   s1, v0, v1
800003DC	addu   s3, zero, zero
800003E0	lui    s2, $1062
800003E4	ori    s2, s2, $4dd3

L03e8:	; 800003E8
800003E8	lui    a0, $801b
800003EC	addiu  a0, a0, $0020
800003F0	jal    $800bbeac
800003F4	addiu  s3, s3, $0001
800003F8	sll    s0, v0, $05
800003FC	lui    v0, $8016
80000400	addiu  v0, v0, $2978
80000404	jal    $80042da8
80000408	addu   s0, s0, v0
8000040C	andi   v0, v0, $0003
80000410	lh     a0, $0014(s1)
80000414	lh     a1, $0012(s1)
80000418	addu   a0, a0, v0
8000041C	sll    v1, a1, $01
80000420	addu   v1, v1, a1
80000424	sll    v0, v1, $05
80000428	subu   v0, v0, v1
8000042C	sll    v0, v0, $03
80000430	subu   v0, v0, a1
80000434	sll    v0, v0, $02
80000438	lui    at, $8015
8000043C	addiu  at, at, $18f4
80000440	addu   at, at, v0
80000444	lh     v0, $0000(at)
80000448	addiu  a0, a0, $0001
8000044C	div    a0, v0
80000450	bne    v0, zero, L045c [$8000045c]
80000454	nop
80000458	break   $01c00

L045c:	; 8000045C
8000045C	addiu  at, zero, $ffff (=-$1)
80000460	bne    v0, at, L0474 [$80000474]
80000464	lui    at, $8000
80000468	bne    a0, at, L0474 [$80000474]
8000046C	nop
80000470	break   $01800

L0474:	; 80000474
80000474	mfhi   a1
80000478	lh     a0, $0012(s1)
8000047C	addiu  a2, s0, $0004
80000480	sh     a1, $0014(s1)
80000484	sll    a1, a1, $10
80000488	jal    $800d3994
8000048C	sra    a1, a1, $10
80000490	jal    $80042da8
80000494	nop
80000498	mult   v0, s2
8000049C	lhu    a1, $0004(s0)
800004A0	sra    v1, v0, $1f
800004A4	addiu  a1, a1, $ff06 (=-$fa)
800004A8	mfhi   a0
800004AC	sra    a0, a0, $05
800004B0	subu   a0, a0, v1
800004B4	sll    v1, a0, $05
800004B8	subu   v1, v1, a0
800004BC	sll    v1, v1, $02
800004C0	addu   v1, v1, a0
800004C4	sll    v1, v1, $02
800004C8	subu   v0, v0, v1
800004CC	addu   a1, a1, v0
800004D0	jal    $80042da8
800004D4	sh     a1, $0004(s0)
800004D8	mult   v0, s2
800004DC	lhu    a1, $0006(s0)
800004E0	sra    v1, v0, $1f
800004E4	addiu  a1, a1, $ff06 (=-$fa)
800004E8	mfhi   a0
800004EC	sra    a0, a0, $05
800004F0	subu   a0, a0, v1
800004F4	sll    v1, a0, $05
800004F8	subu   v1, v1, a0
800004FC	sll    v1, v1, $02
80000500	addu   v1, v1, a0
80000504	sll    v1, v1, $02
80000508	subu   v0, v0, v1
8000050C	addu   a1, a1, v0
80000510	jal    $80042da8
80000514	sh     a1, $0006(s0)
80000518	mult   v0, s2
8000051C	lhu    a1, $0008(s0)
80000520	sra    v1, v0, $1f
80000524	addiu  a1, a1, $ff06 (=-$fa)
80000528	mfhi   a0
8000052C	sra    a0, a0, $05
80000530	subu   a0, a0, v1
80000534	sll    v1, a0, $05
80000538	subu   v1, v1, a0
8000053C	sll    v1, v1, $02
80000540	addu   v1, v1, a0
80000544	sll    v1, v1, $02
80000548	subu   v0, v0, v1
8000054C	addu   a1, a1, v0
80000550	jal    $80042da8
80000554	sh     a1, $0008(s0)
80000558	lui    v1, $5555
8000055C	ori    v1, v1, $5556
80000560	mult   v0, v1
80000564	sra    v1, v0, $1f
80000568	mfhi   a0
8000056C	subu   a0, a0, v1
80000570	sll    v1, a0, $01
80000574	addu   v1, v1, a0
80000578	subu   v0, v0, v1
8000057C	sll    v0, v0, $05
80000580	jal    $80042da8
80000584	sb     v0, $000d(s0)
80000588	lui    v1, $6666
8000058C	ori    v1, v1, $6667
80000590	mult   v0, v1
80000594	sra    v1, v0, $1f
80000598	mfhi   a0
8000059C	sra    a0, a0, $01
800005A0	subu   a0, a0, v1
800005A4	sll    v1, a0, $02
800005A8	addu   v1, v1, a0
800005AC	subu   v0, v0, v1
800005B0	sll    v0, v0, $01
800005B4	lui    at, $801b
800005B8	addiu  at, at, $1128
800005BC	addu   at, at, v0
800005C0	lhu    v0, $0000(at)
800005C4	jal    $80042da8
800005C8	sh     v0, $000e(s0)
800005CC	andi   v0, v0, $0fff
800005D0	addiu  v0, v0, $1000
800005D4	sh     v0, $0010(s0)
800005D8	lhu    v0, $0016(s1)
800005DC	nop
800005E0	sh     v0, $0016(s0)
800005E4	slti   v0, s3, $0002
800005E8	bne    v0, zero, L03e8 [$800003e8]
800005EC	nop
800005F0	lhu    v0, $0002(s1)
800005F4	nop
800005F8	addiu  v0, v0, $0001
800005FC	sh     v0, $0002(s1)
80000600	sll    v0, v0, $10
80000604	sra    v0, v0, $10
80000608	slti   v0, v0, $001e
8000060C	bne    v0, zero, L0628 [$80000628]
80000610	nop
80000614	lh     a0, $0012(s1)
80000618	jal    $800d5774
8000061C	nop
80000620	addiu  v0, zero, $ffff (=-$1)
80000624	sh     v0, $0000(s1)

L0628:	; 80000628
80000628	lw     ra, $0020(sp)
8000062C	lw     s3, $001c(sp)
80000630	lw     s2, $0018(sp)
80000634	lw     s1, $0014(sp)
80000638	lw     s0, $0010(sp)
8000063C	addiu  sp, sp, $0028
80000640	jr     ra 
80000644	nop

80000648	addiu  sp, sp, $ffe0 (=-$20)
8000064C	lui    v0, $8015
80000650	lh     v0, $169c(v0)
80000654	lui    a0, $8006
80000658	lbu    a0, $2d98(a0)
8000065C	lui    v1, $8016
80000660	addiu  v1, v1, $2978
80000664	sw     ra, $001c(sp)
80000668	sw     s2, $0018(sp)
8000066C	sw     s1, $0014(sp)
80000670	sw     s0, $0010(sp)
80000674	sll    v0, v0, $05
80000678	bne    a0, zero, L07f8 [$800007f8]
8000067C	addu   s1, v0, v1
80000680	addu   s2, zero, zero

loop0684:	; 80000684
80000684	lui    a0, $801b
80000688	addiu  a0, a0, $0020
8000068C	jal    $800bbeac
80000690	addiu  s2, s2, $0001
80000694	sll    s0, v0, $05
80000698	lui    v0, $8016
8000069C	addiu  v0, v0, $2978
800006A0	jal    $80042da8
800006A4	addu   s0, s0, v0
800006A8	andi   v0, v0, $0003
800006AC	lh     a0, $0014(s1)
800006B0	lh     a1, $0012(s1)
800006B4	addu   a0, a0, v0
800006B8	sll    v1, a1, $01
800006BC	addu   v1, v1, a1
800006C0	sll    v0, v1, $05
800006C4	subu   v0, v0, v1
800006C8	sll    v0, v0, $03
800006CC	subu   v0, v0, a1
800006D0	sll    v0, v0, $02
800006D4	lui    at, $8015
800006D8	addiu  at, at, $18f4
800006DC	addu   at, at, v0
800006E0	lh     v0, $0000(at)
800006E4	addiu  a0, a0, $0001
800006E8	div    a0, v0
800006EC	bne    v0, zero, L06f8 [$800006f8]
800006F0	nop
800006F4	break   $01c00

L06f8:	; 800006F8
800006F8	addiu  at, zero, $ffff (=-$1)
800006FC	bne    v0, at, L0710 [$80000710]
80000700	lui    at, $8000
80000704	bne    a0, at, L0710 [$80000710]
80000708	nop
8000070C	break   $01800

L0710:	; 80000710
80000710	mfhi   a1
80000714	lh     a0, $0012(s1)
80000718	addiu  a2, s0, $0004
8000071C	sh     a1, $0014(s1)
80000720	sll    a1, a1, $10
80000724	jal    $800d3994
80000728	sra    a1, a1, $10
8000072C	jal    $80042da8
80000730	nop
80000734	lhu    v1, $0004(s0)
80000738	andi   v0, v0, $01f4
8000073C	addiu  v1, v1, $ff06 (=-$fa)
80000740	addu   v1, v1, v0
80000744	jal    $80042da8
80000748	sh     v1, $0004(s0)
8000074C	lhu    v1, $0006(s0)
80000750	andi   v0, v0, $01f4
80000754	addiu  v1, v1, $ff06 (=-$fa)
80000758	addu   v1, v1, v0
8000075C	jal    $80042da8
80000760	sh     v1, $0006(s0)
80000764	lhu    v1, $0008(s0)
80000768	andi   v0, v0, $01f4
8000076C	addiu  v1, v1, $ff06 (=-$fa)
80000770	addu   v1, v1, v0
80000774	jal    $80042da8
80000778	sh     v1, $0008(s0)
8000077C	andi   v0, v0, $0001
80000780	sll    v1, v0, $01
80000784	addu   v1, v1, v0
80000788	sll    v1, v1, $05
8000078C	addiu  v1, v1, $0020
80000790	ori    v0, zero, $7887
80000794	sb     v1, $000d(s0)
80000798	jal    $80042da8
8000079C	sh     v0, $000e(s0)
800007A0	andi   v0, v0, $0fff
800007A4	addiu  v0, v0, $1000
800007A8	sh     v0, $0010(s0)
800007AC	lhu    v0, $0016(s1)
800007B0	nop
800007B4	sh     v0, $0016(s0)
800007B8	slti   v0, s2, $0002
800007BC	bne    v0, zero, loop0684 [$80000684]
800007C0	nop
800007C4	lhu    v0, $0002(s1)
800007C8	nop
800007CC	addiu  v1, v0, $0001
800007D0	sll    v0, v0, $10
800007D4	sra    v0, v0, $10
800007D8	slti   v0, v0, $000f
800007DC	bne    v0, zero, L07f8 [$800007f8]
800007E0	sh     v1, $0002(s1)
800007E4	lh     a0, $0012(s1)
800007E8	jal    $800d5774
800007EC	nop
800007F0	addiu  v0, zero, $ffff (=-$1)
800007F4	sh     v0, $0000(s1)

L07f8:	; 800007F8
800007F8	lw     ra, $001c(sp)
800007FC	lw     s2, $0018(sp)
80000800	lw     s1, $0014(sp)
80000804	lw     s0, $0010(sp)
80000808	addiu  sp, sp, $0020
8000080C	jr     ra 
80000810	nop

80000814	lui    v0, $8015
80000818	lh     v0, $169c(v0)
8000081C	lui    v1, $8016
80000820	addiu  v1, v1, $2978
80000824	sll    v0, v0, $05
80000828	addu   a0, v0, v1
8000082C	lh     v0, $0002(a0)
80000830	lui    v1, $801b
80000834	addiu  v1, v1, $1134
80000838	sll    v0, v0, $10
8000083C	addu   v0, v0, v1
80000840	lui    at, $801d
80000844	sw     v0, $1134(at)
80000848	lhu    v0, $0002(a0)
8000084C	lui    v1, $8016
80000850	lh     v1, $2080(v1)
80000854	xori   v0, v0, $0001
80000858	slti   v1, v1, $0002
8000085C	beq    v1, zero, L086c [$8000086c]
80000860	sh     v0, $0002(a0)
80000864	addiu  v0, zero, $ffff (=-$1)
80000868	sh     v0, $0000(a0)

L086c:	; 8000086C
8000086C	jr     ra 
80000870	nop

80000874	addiu  sp, sp, $ffe8 (=-$18)
80000878	sw     s0, $0010(sp)
8000087C	addu   s0, a0, zero
80000880	lui    a0, $801b
80000884	addiu  a0, a0, $015c
80000888	sw     ra, $0014(sp)
8000088C	jal    $800bbeac
80000890	nop
80000894	sll    v0, v0, $05
80000898	lui    v1, $8016
8000089C	addiu  v1, v1, $2978
800008A0	addu   v0, v0, v1
800008A4	ori    v1, zero, $7807
800008A8	sh     v1, $000e(v0)
800008AC	ori    v1, zero, $003a
800008B0	sh     s0, $0012(v0)
800008B4	sh     zero, $0014(v0)
800008B8	sb     zero, $000d(v0)
800008BC	sh     v1, $0016(v0)
800008C0	lw     ra, $0014(sp)
800008C4	lw     s0, $0010(sp)
800008C8	addiu  sp, sp, $0018
800008CC	jr     ra 
800008D0	nop

800008D4	addiu  sp, sp, $ffe0 (=-$20)
800008D8	sw     s0, $0010(sp)
800008DC	addu   s0, a0, zero
800008E0	sw     s1, $0014(sp)
800008E4	lui    a0, $801b
800008E8	addiu  a0, a0, $0814
800008EC	sw     ra, $0018(sp)
800008F0	jal    $800bbeac
800008F4	addu   s1, a1, zero
800008F8	jal    $800d54bc
800008FC	addu   a0, s0, zero
80000900	addu   a0, s0, zero
80000904	addu   a1, s1, zero
80000908	slti   v0, v0, $0005
8000090C	xori   v0, v0, $0001
80000910	subu   v0, zero, v0
80000914	lui    a3, $801b
80000918	addiu  a3, a3, $0874
8000091C	jal    $800d5444
80000920	andi   a2, v0, $000a
80000924	jal    $800d574c
80000928	addu   a0, s0, zero
8000092C	ori    a0, zero, $0020
80000930	addu   a1, v0, zero
80000934	jal    $800d55f4
80000938	ori    a2, zero, $0006
8000093C	lw     ra, $0018(sp)
80000940	lw     s1, $0014(sp)
80000944	lw     s0, $0010(sp)
80000948	addiu  sp, sp, $0020
8000094C	jr     ra 
80000950	nop

80000954	addiu  sp, sp, $ffe8 (=-$18)
80000958	sw     s0, $0010(sp)
8000095C	addu   s0, a0, zero
80000960	lui    a0, $801b
80000964	addiu  a0, a0, $015c
80000968	sw     ra, $0014(sp)
8000096C	jal    $800bbeac
80000970	nop
80000974	sll    v0, v0, $05
80000978	lui    v1, $8016
8000097C	addiu  v1, v1, $2978
80000980	addu   v0, v0, v1
80000984	ori    v1, zero, $0040
80000988	sb     v1, $000d(v0)
8000098C	ori    v1, zero, $7947
80000990	sh     v1, $000e(v0)
80000994	ori    v1, zero, $003a
80000998	sh     s0, $0012(v0)
8000099C	sh     zero, $0014(v0)
800009A0	sh     v1, $0016(v0)
800009A4	lw     ra, $0014(sp)
800009A8	lw     s0, $0010(sp)
800009AC	addiu  sp, sp, $0018
800009B0	jr     ra 
800009B4	nop

800009B8	addiu  sp, sp, $ffe0 (=-$20)
800009BC	sw     s0, $0010(sp)
800009C0	addu   s0, a0, zero
800009C4	sw     s1, $0014(sp)
800009C8	lui    a0, $801b
800009CC	addiu  a0, a0, $0814
800009D0	sw     ra, $0018(sp)
800009D4	jal    $800bbeac
800009D8	addu   s1, a1, zero
800009DC	jal    $800d54bc
800009E0	addu   a0, s0, zero
800009E4	addu   a0, s0, zero
800009E8	addu   a1, s1, zero
800009EC	slti   v0, v0, $0005
800009F0	xori   v0, v0, $0001
800009F4	subu   v0, zero, v0
800009F8	lui    a3, $801b
800009FC	addiu  a3, a3, $0954
80000A00	jal    $800d5444
80000A04	andi   a2, v0, $000a
80000A08	jal    $800d574c
80000A0C	addu   a0, s0, zero
80000A10	ori    a0, zero, $0020
80000A14	addu   a1, v0, zero
80000A18	jal    $800d55f4
80000A1C	ori    a2, zero, $0008
80000A20	lw     ra, $0018(sp)
80000A24	lw     s1, $0014(sp)
80000A28	lw     s0, $0010(sp)
80000A2C	addiu  sp, sp, $0020
80000A30	jr     ra 
80000A34	nop

80000A38	addiu  sp, sp, $ffe8 (=-$18)
80000A3C	sw     s0, $0010(sp)
80000A40	addu   s0, a0, zero
80000A44	lui    a0, $801b
80000A48	addiu  a0, a0, $03a0
80000A4C	sw     ra, $0014(sp)
80000A50	jal    $800bbeac
80000A54	nop
80000A58	sll    v0, v0, $05
80000A5C	lui    v1, $8016
80000A60	addiu  v1, v1, $2978
80000A64	addu   v0, v0, v1
80000A68	ori    v1, zero, $003a
80000A6C	sh     s0, $0012(v0)
80000A70	sh     zero, $0014(v0)
80000A74	sh     v1, $0016(v0)
80000A78	lw     ra, $0014(sp)
80000A7C	lw     s0, $0010(sp)
80000A80	addiu  sp, sp, $0018
80000A84	jr     ra 
80000A88	nop

80000A8C	addiu  sp, sp, $ffe0 (=-$20)
80000A90	sw     s0, $0010(sp)
80000A94	addu   s0, a0, zero
80000A98	sw     s1, $0014(sp)
80000A9C	lui    a0, $801b
80000AA0	addiu  a0, a0, $0814
80000AA4	sw     ra, $0018(sp)
80000AA8	jal    $800bbeac
80000AAC	addu   s1, a1, zero
80000AB0	jal    $800d54bc
80000AB4	addu   a0, s0, zero
80000AB8	addu   a0, s0, zero
80000ABC	addu   a1, s1, zero
80000AC0	slti   v0, v0, $0005
80000AC4	xori   v0, v0, $0001
80000AC8	subu   v0, zero, v0
80000ACC	lui    a3, $801b
80000AD0	addiu  a3, a3, $0a38
80000AD4	jal    $800d5444
80000AD8	andi   a2, v0, $000a
80000ADC	jal    $800d574c
80000AE0	addu   a0, s0, zero
80000AE4	ori    a0, zero, $0020
80000AE8	addu   a1, v0, zero
80000AEC	jal    $800d55f4
80000AF0	ori    a2, zero, $0045
80000AF4	lw     ra, $0018(sp)
80000AF8	lw     s1, $0014(sp)
80000AFC	lw     s0, $0010(sp)
80000B00	addiu  sp, sp, $0020
80000B04	jr     ra 
80000B08	nop

80000B0C	addiu  sp, sp, $ffe8 (=-$18)
80000B10	sw     s0, $0010(sp)
80000B14	addu   s0, a0, zero
80000B18	lui    a0, $801b
80000B1C	addiu  a0, a0, $0648
80000B20	sw     ra, $0014(sp)
80000B24	jal    $800bbeac
80000B28	nop
80000B2C	sll    v0, v0, $05
80000B30	lui    v1, $8016
80000B34	addiu  v1, v1, $2978
80000B38	addu   v0, v0, v1
80000B3C	ori    v1, zero, $003a
80000B40	sh     s0, $0012(v0)
80000B44	sh     zero, $0014(v0)
80000B48	sh     v1, $0016(v0)
80000B4C	lw     ra, $0014(sp)
80000B50	lw     s0, $0010(sp)
80000B54	addiu  sp, sp, $0018
80000B58	jr     ra 
80000B5C	nop

80000B60	addiu  sp, sp, $ffe0 (=-$20)
80000B64	sw     s0, $0010(sp)
80000B68	addu   s0, a0, zero
80000B6C	sw     s1, $0014(sp)
80000B70	lui    a0, $801b
80000B74	addiu  a0, a0, $0814
80000B78	sw     ra, $0018(sp)
80000B7C	jal    $800bbeac
80000B80	addu   s1, a1, zero
80000B84	jal    $800d54bc
80000B88	addu   a0, s0, zero
80000B8C	addu   a0, s0, zero
80000B90	addu   a1, s1, zero
80000B94	slti   v0, v0, $0005
80000B98	xori   v0, v0, $0001
80000B9C	subu   v0, zero, v0
80000BA0	lui    a3, $801b
80000BA4	addiu  a3, a3, $0b0c
80000BA8	jal    $800d5444
80000BAC	andi   a2, v0, $000a
80000BB0	jal    $800d574c
80000BB4	addu   a0, s0, zero
80000BB8	ori    a0, zero, $0020
80000BBC	addu   a1, v0, zero
80000BC0	jal    $800d55f4
80000BC4	ori    a2, zero, $005c
80000BC8	lw     ra, $0018(sp)
80000BCC	lw     s1, $0014(sp)
80000BD0	lw     s0, $0010(sp)
80000BD4	addiu  sp, sp, $0020
80000BD8	jr     ra 
80000BDC	nop

80000BE0	addiu  sp, sp, $ffe8 (=-$18)
80000BE4	sw     s0, $0010(sp)
80000BE8	addu   s0, a0, zero
80000BEC	lui    a0, $801b
80000BF0	addiu  a0, a0, $015c
80000BF4	sw     ra, $0014(sp)
80000BF8	jal    $800bbeac
80000BFC	nop
80000C00	sll    v0, v0, $05
80000C04	lui    v1, $8016
80000C08	addiu  v1, v1, $2978
80000C0C	addu   v0, v0, v1
80000C10	ori    v1, zero, $0060
80000C14	sb     v1, $000d(v0)
80000C18	ori    v1, zero, $7887
80000C1C	sh     v1, $000e(v0)
80000C20	ori    v1, zero, $003a
80000C24	sh     s0, $0012(v0)
80000C28	sh     zero, $0014(v0)
80000C2C	sh     v1, $0016(v0)
80000C30	lw     ra, $0014(sp)
80000C34	lw     s0, $0010(sp)
80000C38	addiu  sp, sp, $0018
80000C3C	jr     ra 
80000C40	nop

80000C44	addiu  sp, sp, $ffe0 (=-$20)
80000C48	sw     s0, $0010(sp)
80000C4C	addu   s0, a0, zero
80000C50	sw     s1, $0014(sp)
80000C54	lui    a0, $801b
80000C58	addiu  a0, a0, $0814
80000C5C	sw     ra, $0018(sp)
80000C60	jal    $800bbeac
80000C64	addu   s1, a1, zero
80000C68	jal    $800d54bc
80000C6C	addu   a0, s0, zero
80000C70	addu   a0, s0, zero
80000C74	addu   a1, s1, zero
80000C78	slti   v0, v0, $0005
80000C7C	xori   v0, v0, $0001
80000C80	subu   v0, zero, v0
80000C84	lui    a3, $801b
80000C88	addiu  a3, a3, $0be0
80000C8C	jal    $800d5444
80000C90	andi   a2, v0, $000a
80000C94	jal    $800d574c
80000C98	addu   a0, s0, zero
80000C9C	ori    a0, zero, $0020
80000CA0	addu   a1, v0, zero
80000CA4	jal    $800d55f4
80000CA8	ori    a2, zero, $005b
80000CAC	lw     ra, $0018(sp)
80000CB0	lw     s1, $0014(sp)
80000CB4	lw     s0, $0010(sp)
80000CB8	addiu  sp, sp, $0020
80000CBC	jr     ra 
80000CC0	nop

80000CC4	addiu  sp, sp, $ffe8 (=-$18)
80000CC8	sw     s0, $0010(sp)
80000CCC	addu   s0, a0, zero
80000CD0	lui    a0, $801b
80000CD4	addiu  a0, a0, $015c
80000CD8	sw     ra, $0014(sp)
80000CDC	jal    $800bbeac
80000CE0	nop
80000CE4	sll    v0, v0, $05
80000CE8	lui    v1, $8016
80000CEC	addiu  v1, v1, $2978
80000CF0	addu   v0, v0, v1
80000CF4	ori    v1, zero, $7a47
80000CF8	sh     v1, $000e(v0)
80000CFC	ori    v1, zero, $003a
80000D00	sh     s0, $0012(v0)
80000D04	sh     zero, $0014(v0)
80000D08	sb     zero, $000d(v0)
80000D0C	sh     v1, $0016(v0)
80000D10	lw     ra, $0014(sp)
80000D14	lw     s0, $0010(sp)
80000D18	addiu  sp, sp, $0018
80000D1C	jr     ra 
80000D20	nop

80000D24	addiu  sp, sp, $ffe0 (=-$20)
80000D28	sw     s0, $0010(sp)
80000D2C	addu   s0, a0, zero
80000D30	sw     s1, $0014(sp)
80000D34	lui    a0, $801b
80000D38	addiu  a0, a0, $0814
80000D3C	sw     ra, $0018(sp)
80000D40	jal    $800bbeac
80000D44	addu   s1, a1, zero
80000D48	jal    $800d54bc
80000D4C	addu   a0, s0, zero
80000D50	addu   a0, s0, zero
80000D54	addu   a1, s1, zero
80000D58	slti   v0, v0, $0005
80000D5C	xori   v0, v0, $0001
80000D60	subu   v0, zero, v0
80000D64	lui    a3, $801b
80000D68	addiu  a3, a3, $0cc4
80000D6C	jal    $800d5444
80000D70	andi   a2, v0, $000a
80000D74	jal    $800d574c
80000D78	addu   a0, s0, zero
80000D7C	ori    a0, zero, $0020
80000D80	addu   a1, v0, zero
80000D84	jal    $800d55f4
80000D88	ori    a2, zero, $001f
80000D8C	lw     ra, $0018(sp)
80000D90	lw     s1, $0014(sp)
80000D94	lw     s0, $0010(sp)
80000D98	addiu  sp, sp, $0020
80000D9C	jr     ra 
80000DA0	nop

80000DA4	addiu  sp, sp, $ffe8 (=-$18)
80000DA8	sw     s0, $0010(sp)
80000DAC	addu   s0, a0, zero
80000DB0	lui    a0, $801b
80000DB4	addiu  a0, a0, $015c
80000DB8	sw     ra, $0014(sp)
80000DBC	jal    $800bbeac
80000DC0	nop
80000DC4	sll    v0, v0, $05
80000DC8	lui    v1, $8016
80000DCC	addiu  v1, v1, $2978
80000DD0	addu   v0, v0, v1
80000DD4	ori    v1, zero, $0020
80000DD8	sb     v1, $000d(v0)
80000DDC	ori    v1, zero, $7907
80000DE0	sh     v1, $000e(v0)
80000DE4	ori    v1, zero, $003a
80000DE8	sh     s0, $0012(v0)
80000DEC	sh     zero, $0014(v0)
80000DF0	sh     v1, $0016(v0)
80000DF4	lw     ra, $0014(sp)
80000DF8	lw     s0, $0010(sp)
80000DFC	addiu  sp, sp, $0018
80000E00	jr     ra 
80000E04	nop

80000E08	addiu  sp, sp, $ffe0 (=-$20)
80000E0C	sw     s0, $0010(sp)
80000E10	addu   s0, a0, zero
80000E14	sw     s1, $0014(sp)
80000E18	lui    a0, $801b
80000E1C	addiu  a0, a0, $0814
80000E20	sw     ra, $0018(sp)
80000E24	jal    $800bbeac
80000E28	addu   s1, a1, zero
80000E2C	jal    $800d54bc
80000E30	addu   a0, s0, zero
80000E34	addu   a0, s0, zero
80000E38	addu   a1, s1, zero
80000E3C	slti   v0, v0, $0005
80000E40	xori   v0, v0, $0001
80000E44	subu   v0, zero, v0
80000E48	lui    a3, $801b
80000E4C	addiu  a3, a3, $0da4
80000E50	jal    $800d5444
80000E54	andi   a2, v0, $000a
80000E58	jal    $800d574c
80000E5C	addu   a0, s0, zero
80000E60	ori    a0, zero, $0020
80000E64	addu   a1, v0, zero
80000E68	jal    $800d55f4
80000E6C	ori    a2, zero, $001f
80000E70	lw     ra, $0018(sp)
80000E74	lw     s1, $0014(sp)
80000E78	lw     s0, $0010(sp)
80000E7C	addiu  sp, sp, $0020
80000E80	jr     ra 
80000E84	nop

80000E88	addiu  sp, sp, $ffe8 (=-$18)
80000E8C	sw     s0, $0010(sp)
80000E90	addu   s0, a0, zero
80000E94	lui    a0, $801b
80000E98	addiu  a0, a0, $015c
80000E9C	sw     ra, $0014(sp)
80000EA0	jal    $800bbeac
80000EA4	nop
80000EA8	sll    v0, v0, $05
80000EAC	lui    v1, $8016
80000EB0	addiu  v1, v1, $2978
80000EB4	addu   v0, v0, v1
80000EB8	ori    v1, zero, $0020
80000EBC	sb     v1, $000d(v0)
80000EC0	ori    v1, zero, $78c7
80000EC4	sh     v1, $000e(v0)
80000EC8	ori    v1, zero, $003a
80000ECC	sh     s0, $0012(v0)
80000ED0	sh     zero, $0014(v0)
80000ED4	sh     v1, $0016(v0)
80000ED8	lw     ra, $0014(sp)
80000EDC	lw     s0, $0010(sp)
80000EE0	addiu  sp, sp, $0018
80000EE4	jr     ra 
80000EE8	nop

80000EEC	addiu  sp, sp, $ffe0 (=-$20)
80000EF0	sw     s0, $0010(sp)
80000EF4	addu   s0, a0, zero
80000EF8	sw     s1, $0014(sp)
80000EFC	lui    a0, $801b
80000F00	addiu  a0, a0, $0814
80000F04	sw     ra, $0018(sp)
80000F08	jal    $800bbeac
80000F0C	addu   s1, a1, zero
80000F10	jal    $800d54bc
80000F14	addu   a0, s0, zero
80000F18	addu   a0, s0, zero
80000F1C	addu   a1, s1, zero
80000F20	slti   v0, v0, $0005
80000F24	xori   v0, v0, $0001
80000F28	subu   v0, zero, v0
80000F2C	lui    a3, $801b
80000F30	addiu  a3, a3, $0e88
80000F34	jal    $800d5444
80000F38	andi   a2, v0, $000a
80000F3C	jal    $800d574c
80000F40	addu   a0, s0, zero
80000F44	ori    a0, zero, $0020
80000F48	addu   a1, v0, zero
80000F4C	jal    $800d55f4
80000F50	ori    a2, zero, $017e
80000F54	lw     ra, $0018(sp)
80000F58	lw     s1, $0014(sp)
80000F5C	lw     s0, $0010(sp)
80000F60	addiu  sp, sp, $0020
80000F64	jr     ra 
80000F68	nop



////////////////////////////////
// func1b0f6c
target_id = A0;

A0 = 801b015c;
funcbbeac;

[80162978 + V0 * 20 + d] = b(0);
[80162978 + V0 * 20 + e] = h(7a07);
[80162978 + V0 * 20 + 12] = h(target_id);
[80162978 + V0 * 20 + 14] = h(0);
[80162978 + V0 * 20 + 16] = h(3a);
////////////////////////////////



////////////////////////////////
// func1b0fcc
80000FCC-80001034
S1 = A0;
S0 = A1;

A0 = 801b0814;
funcbbeac;

A0 = S1;
A1 = S0;
A2 = 0;
A3 = 801b0f6c; // call this func to all inits in target mask
funcd5444;



// play sound calculation
A0 = S1;
funcd574c; // calculate some sound param (volume maybe)
A0 = 20;
A1 = V0;
A2 = 166;
funcd55f4; // we play sound here
////////////////////////////////



80001038	addiu  sp, sp, $ffe8 (=-$18)
8000103C	sw     s0, $0010(sp)
80001040	addu   s0, a0, zero
80001044	lui    a0, $801b
80001048	addiu  a0, a0, $015c
8000104C	sw     ra, $0014(sp)
80001050	jal    $800bbeac
80001054	nop
80001058	sll    v0, v0, $05
8000105C	lui    v1, $8016
80001060	addiu  v1, v1, $2978
80001064	addu   v0, v0, v1
80001068	ori    v1, zero, $0020
8000106C	sb     v1, $000d(v0)
80001070	ori    v1, zero, $7847
80001074	sh     v1, $000e(v0)
80001078	ori    v1, zero, $003a
8000107C	sh     s0, $0012(v0)
80001080	sh     zero, $0014(v0)
80001084	sh     v1, $0016(v0)
80001088	lw     ra, $0014(sp)
8000108C	lw     s0, $0010(sp)
80001090	addiu  sp, sp, $0018
80001094	jr     ra 
80001098	nop

8000109C	addiu  sp, sp, $ffe0 (=-$20)
800010A0	sw     s0, $0010(sp)
800010A4	addu   s0, a0, zero
800010A8	sw     s1, $0014(sp)
800010AC	lui    a0, $801b
800010B0	addiu  a0, a0, $0814
800010B4	sw     ra, $0018(sp)
800010B8	jal    $800bbeac
800010BC	addu   s1, a1, zero
800010C0	jal    $800d54bc
800010C4	addu   a0, s0, zero
800010C8	addu   a0, s0, zero
800010CC	addu   a1, s1, zero
800010D0	slti   v0, v0, $0005
800010D4	xori   v0, v0, $0001
800010D8	subu   v0, zero, v0
800010DC	lui    a3, $801b
800010E0	addiu  a3, a3, $1038
800010E4	jal    $800d5444
800010E8	andi   a2, v0, $000a
800010EC	jal    $800d574c
800010F0	addu   a0, s0, zero
800010F4	ori    a0, zero, $0020
800010F8	addu   a1, v0, zero
800010FC	jal    $800d55f4
80001100	ori    a2, zero, $0007
80001104	lw     ra, $0018(sp)
80001108	lw     s1, $0014(sp)
8000110C	lw     s0, $0010(sp)
80001110	addiu  sp, sp, $0020
80001114	jr     ra 
80001118	nop
