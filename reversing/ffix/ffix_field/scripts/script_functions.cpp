////////////////////////////////
// funcc7464
[800c9df1] = b(A0);
return 1;
////////////////////////////////



////////////////////////////////
// funcb0124

// 0x01c7		0x7a_Add(03)ValueToStack(0x1cXXXXXX); 
//        A0 = c00;
//        A1 = ffffffff;
//        A2 = 0;
//        A3 = 0;
//        A4 = 0;

S6 = A1;
S1 = A2;
S3 = A3;
[SP + 58] = w(A0);
V0 = A0 >> 8;
S4 = V0 & f;

S5 = w[SP + 60]; // SP + 10

if (S4 == c)
{
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    V0 = bu[V0 + 851];

    800B0190	bne    v0, zero, Lb138c [$800b138c]
    800B0194	lui    v0, $8006
}

T1 = w[SP + 58];
A3 = 1;
V0 = T1 >> c;
A0 = V0 & 3;
if (A0 == 1)
{
    FP = 0;
    S2 = 0;
    [SP + 24] = w(0);
    V1 = S6 & ffff;
    S7 = V1 | 00080000;
    V0 = S4 - 5;

    800B0920	sltiu  v0, v0, $0002
    800B0924	bne    v0, zero, Lb0b38 [$800b0b38]
    800B0928	addu   a0, fp, zero
    800B092C	lw     t1, $0058(sp)
    800B0930	nop
    800B0934	sra    v0, t1, $07
    800B0938	andi   fp, v0, $0001
    800B093C	beq    fp, zero, Lb0b28 [$800b0b28]
    800B0940	addu   a1, s7, zero
    800B0944	beq    s4, zero, Lb095c [$800b095c]
    800B0948	addiu  v0, zero, $0008
    800B094C	beq    s4, v0, Lb095c [$800b095c]
    800B0950	addiu  v0, zero, $0009
    800B0954	bne    s4, v0, Lb0970 [$800b0970]
    800B0958	lui    v0, $8006

    Lb095c:	; 800B095C
    T2 = w[SP + 58];
    V0 = T2 >> 6;
    S2 = V0 & 1;
    800B0968	j      Lb09b4 [$800b09b4]
}
else if (A0 >= 2)
{
    V0 = 2;
    800B01C8	beq    a0, v0, Lb1050 [$800b1050]

    800B01CC	addiu  v0, zero, $0003
    800B01D0	beq    a0, v0, Lb1298 [$800b1298]

    800B01D4	addiu  v0, zero, $ffff (=-$1)
    800B01D8	j      Lb19f0 [$800b19f0]
    800B01DC	nop
}

800B01B8	beq    a0, zero, Lb01e0 [$800b01e0]
800B01BC	addiu  v0, zero, $ffff (=-$1)
800B01C0	j      Lb19f0 [$800b19f0]
800B01C4	nop



Lb01e0:	; 800B01E0
800B01E0	andi   v0, s6, $ffff
800B01E4	lui    v1, $0007
800B01E8	or     s7, v0, v1
800B01EC	sltiu  v0, s4, $000d
800B01F0	beq    v0, zero, Lb09ac [$800b09ac]
800B01F4	addiu  a3, zero, $ffff (=-$1)
V0 = 800a70cc;
V1 = S4 * 4;
E4020B80 0
8C050B80 1
E8050B80 2
1C070B80 3
C8070B80 4
AC090B80 5
78080B80 6
E4020B80 7
F8040B80 8
18020B80 9
E0080B80 a
A4080B80 b

800B0204	addu   v1, v1, v0
800B0208	lw     v0, $0000(v1)
800B020C	nop
800B0210	jr     v0 
800B0214	nop

800B0218	lui    a2, $8006
800B021C	lw     a1, $794c(a2)
800B0220	nop
800B0224	lw     a0, $001c(a1)
800B0228	nop
800B022C	lhu    v1, $07e8(a0)
800B0230	ori    v0, zero, $ffff
800B0234	beq    v1, v0, Lb029c [$800b029c]
800B0238	addu   t0, zero, zero
800B023C	lhu    v1, $07ea(a0)
800B0240	lh     v0, $000c(a0)
800B0244	nop
800B0248	bne    v1, v0, Lb02a0 [$800b02a0]
800B024C	lui    v0, $8006
800B0250	addu   v1, a0, zero
800B0254	lui    v0, $800d
800B0258	addiu  t0, zero, $0001
800B025C	sb     s4, $9d4c(v0)
800B0260	lbu    v0, $0850(v1)
800B0264	lui    a1, $0007
800B0268	sb     v0, $0826(v1)
800B026C	lw     a2, $794c(a2)
800B0270	lhu    s6, $07e8(v1)
800B0274	lw     a0, $001c(a2)
800B0278	lhu    a3, $0840(v1)
800B027C	lw     v0, $08ac(a0)
800B0280	or     s7, s6, a1
800B0284	sw     v0, $08a8(a0)
800B0288	lw     a0, $001c(a2)

Lb028c:	; 800B028C
800B028C	lui    v0, $0009
800B0290	lhu    v1, $08b0(a0)
800B0294	or     a3, a3, v0
800B0298	sh     v1, $084a(a0)

Lb029c:	; 800B029C
800B029C	lui    v0, $8006

Lb02a0:	; 800B02A0
800B02A0	lw     v1, $794c(v0)
800B02A4	nop
800B02A8	lw     v0, $001c(v1)
800B02AC	ori    a0, zero, $ffff
800B02B0	sh     a0, $07e8(v0)
800B02B4	lw     v0, $001c(v1)
800B02B8	nop
800B02BC	sh     a0, $0840(v0)
800B02C0	lw     v0, $001c(v1)
800B02C4	nop
800B02C8	sh     a0, $07ea(v0)
800B02CC	lw     a1, $001c(v1)
800B02D0	addiu  v0, zero, $ffff (=-$1)
800B02D4	sw     v0, $08ac(a1)
800B02D8	lw     v0, $001c(v1)
800B02DC	beq    t0, zero, Lb04b0 [$800b04b0]
800B02E0	sh     a0, $08b0(v0)
800B02E4	lui    s1, $8006
800B02E8	lw     v0, $794c(s1)
800B02EC	nop
800B02F0	lw     v0, $001c(v0)
800B02F4	nop
800B02F8	lbu    v0, $0851(v0)
800B02FC	nop
800B0300	bne    v0, zero, Lb19f0 [$800b19f0]

Lb0304:	; 800B0304
800B0304	addiu  v0, zero, $ffff (=-$1)
800B0308	lui    s0, $800d
800B030C	lb     v1, $9d4c(s0)
800B0310	nop
800B0314	bne    v1, v0, Lb0324 [$800b0324]
800B0318	addiu  v0, zero, $0009

funcb031c:	; 800B031C
800B031C	sb     s4, $9d4c(s0)
800B0320	lb     v1, $9d4c(s0)

Lb0324:	; 800B0324
800B0324	nop
800B0328	beq    v1, v0, Lb033c [$800b033c]
800B032C	nop
800B0330	jal    funcb2328 [$800b2328]
800B0334	addu   a0, s7, zero
800B0338	addu   a3, v0, zero

Lb033c:	; 800B033C
800B033C	lw     v0, $794c(s1)
800B0340	nop
800B0344	lw     a0, $001c(v0)
800B0348	nop
800B034C	lhu    v0, $081c(a0)
800B0350	nop
800B0354	bne    v0, s6, Lb036c [$800b036c]
800B0358	andi   v0, a3, $ffff
800B035C	lhu    v1, $0820(a0)
800B0360	nop
800B0364	beq    v1, v0, Lb040c [$800b040c]
800B0368	addiu  v0, zero, $0007

Lb036c:	; 800B036C
800B036C	lw     v1, $0000(a0)
800B0370	lui    v0, $2000
800B0374	and    v0, v1, v0
800B0378	beq    v0, zero, Lb0388 [$800b0388]
800B037C	lui    v0, $0020
800B0380	or     v0, v1, v0
800B0384	sw     v0, $0000(a0)

Lb0388:	; 800B0388
800B0388	lw     a1, $794c(s1)
800B038C	nop
800B0390	lw     a0, $001c(a1)
800B0394	lui    v1, $cfff
800B0398	lw     v0, $0000(a0)
800B039C	ori    v1, v1, $ffff
800B03A0	and    v0, v0, v1
800B03A4	sw     v0, $0000(a0)
800B03A8	lw     v0, $001c(a1)
800B03AC	nop

funcb03b0:	; 800B03B0
800B03B0	lw     v0, $08e4(v0)
800B03B4	nop
800B03B8	lw     v0, $000c(v0)
800B03BC	nop
800B03C0	lw     a0, $0014(v0)
800B03C4	nop
800B03C8	lw     v0, $0000(a0)
800B03CC	addiu  v1, zero, $ffef (=-$11)
800B03D0	and    v0, v0, v1
800B03D4	sw     v0, $0000(a0)
800B03D8	lw     v0, $001c(a1)
800B03DC	nop
800B03E0	sh     a3, $0820(v0)
800B03E4	lw     v1, $001c(a1)
800B03E8	lui    v0, $800d
800B03EC	sw     s7, $9d50(v0)
800B03F0	sh     s6, $081c(v1)
800B03F4	lw     v1, $001c(a1)
800B03F8	addiu  v0, zero, $0001
800B03FC	sb     v0, $0851(v1)
800B0400	lw     v0, $794c(s1)
800B0404	j      Lb19e0 [$800b19e0]
800B0408	nop

Lb040c:	; 800B040C
800B040C	lb     v1, $9d4c(s0)
800B0410	nop
800B0414	beq    v1, v0, Lb04a8 [$800b04a8]
800B0418	lui    v1, $800d
800B041C	lui    s0, $8006

Lb0420:	; 800B0420
800B0420	lw     v0, $794c(s0)
800B0424	nop
800B0428	lw     v0, $001c(v0)
800B042C	nop
800B0430	lw     a0, $0814(v0)
800B0434	jal    func55290 [$80055290]
800B0438	nop
800B043C	lw     v1, $794c(s0)
800B0440	nop
800B0444	lw     v1, $001c(v1)
800B0448	nop
800B044C	sb     v0, $0824(v1)
800B0450	lw     v0, $794c(s0)
800B0454	nop
800B0458	lw     a2, $001c(v0)
800B045C	nop
800B0460	lw     v0, $0000(a2)
800B0464	lui    v1, $2000

funcb0468:	; 800B0468
800B0468	and    v0, v0, v1
800B046C	bne    v0, zero, Lb0484 [$800b0484]
800B0470	addiu  a1, zero, $000a
800B0474	lbu    a0, $0824(a2)
800B0478	lbu    a3, $0826(a2)
800B047C	jal    func55a34 [$80055a34]
800B0480	addu   a2, zero, zero

Lb0484:	; 800B0484
800B0484	lw     v0, $794c(s0)
800B0488	nop
800B048C	lw     a0, $001c(v0)
800B0490	nop
800B0494	lw     v0, $0000(a0)
800B0498	lui    v1, $3000
800B049C	or     v0, v0, v1
800B04A0	sw     v0, $0000(a0)
800B04A4	lui    v1, $800d

Lb04a8:	; 800B04A8
800B04A8	addiu  v0, zero, $ffff (=-$1)
800B04AC	sb     v0, $9d4c(v1)

Lb04b0:	; 800B04B0
800B04B0	j      Lb19f0 [$800b19f0]
800B04B4	addu   v0, zero, zero

case c: //B8040B80
{
    V0 = w[8006794c];
    V0 = w[V0 + 1c];
    V0 = bu[V0 + 851];

800B04D4	bne    v0, zero, Lb138c [$800b138c]

    funcb2c80;

    if (V0 == 0)
    {
        return 0;
    }

    return 6;
}
break;



800B04F8	jal    func55310 [$80055310]
800B04FC	nop
800B0500	lui    a1, $8006
800B0504	lw     a0, $794c(a1)
800B0508	nop
800B050C	lw     v1, $001c(a0)
800B0510	nop
800B0514	lhu    v0, $081c(v1)
800B0518	nop
800B051C	sh     v0, $07e8(v1)
800B0520	lw     v1, $001c(a0)
800B0524	nop
800B0528	lhu    v0, $0820(v1)
800B052C	nop
800B0530	sh     v0, $0840(v1)
800B0534	lw     v1, $001c(a0)
800B0538	nop
800B053C	lbu    v0, $0826(v1)
800B0540	nop
800B0544	sb     v0, $0850(v1)
800B0548	lw     a0, $794c(a1)
800B054C	nop
800B0550	lw     v1, $001c(a0)
800B0554	nop
800B0558	lhu    v0, $000c(v1)
800B055C	nop
800B0560	sh     v0, $07ea(v1)
800B0564	lw     v1, $001c(a0)
800B0568	nop
800B056C	lw     v0, $08a8(v1)
800B0570	nop
800B0574	sw     v0, $08ac(v1)
800B0578	lw     v1, $001c(a0)
800B057C	nop
800B0580	lhu    v0, $084a(v1)
800B0584	nop
800B0588	sh     v0, $08b0(v1)
800B058C	lw     t2, $0058(sp)
800B0590	lui    s0, $8006
800B0594	lw     v0, $794c(s0)
800B0598	nop
800B059C	lw     v0, $001c(v0)
800B05A0	nop
800B05A4	lbu    a0, $0824(v0)
800B05A8	jal    func552b8 [$800552b8]
800B05AC	nop
800B05B0	lw     v0, $794c(s0)
800B05B4	nop
800B05B8	lw     v1, $001c(v0)
800B05BC	addiu  v0, zero, $007f

funcb05c0:	; 800B05C0
800B05C0	sb     v0, $0826(v1)
800B05C4	lw     v0, $794c(s0)
800B05C8	lui    a1, $dfff
800B05CC	lw     a0, $001c(v0)
800B05D0	ori    a1, a1, $ffff
800B05D4	lw     v1, $0000(a0)
800B05D8	addu   v0, zero, zero
800B05DC	and    v1, v1, a1
800B05E0	j      Lb19f0 [$800b19f0]
800B05E4	sw     v1, $0000(a0)
800B05E8	lw     t1, $0058(sp)
800B05EC	addiu  v0, zero, $0008
800B05F0	andi   v1, t1, $003f
800B05F4	beq    v1, v0, Lb19f0 [$800b19f0]
800B05F8	addu   v0, zero, zero
800B05FC	beq    v1, zero, Lb09ac [$800b09ac]
800B0600	slti   v0, v1, $0004
800B0604	bne    v0, zero, Lb0620 [$800b0620]
800B0608	addiu  v0, zero, $0002
800B060C	addiu  v0, zero, $0007
800B0610	beq    v1, v0, Lb06c4 [$800b06c4]
800B0614	addiu  v0, zero, $ffff (=-$1)
800B0618	j      Lb19f0 [$800b19f0]
800B061C	nop

Lb0620:	; 800B0620
800B0620	beq    v1, v0, Lb0694 [$800b0694]
800B0624	slti   v0, v1, $0003
800B0628	beq    v0, zero, Lb0640 [$800b0640]
800B062C	addiu  v0, zero, $0001
800B0630	beq    v1, v0, Lb065c [$800b065c]
800B0634	addiu  v0, zero, $ffff (=-$1)
800B0638	j      Lb19f0 [$800b19f0]
800B063C	nop

Lb0640:	; 800B0640
800B0640	addiu  v0, zero, $0003
800B0644	beq    v1, v0, Lb06a4 [$800b06a4]
800B0648	addiu  v0, zero, $0004
800B064C	beq    v1, v0, Lb06b4 [$800b06b4]
800B0650	addiu  v0, zero, $ffff (=-$1)
800B0654	j      Lb19f0 [$800b19f0]
800B0658	nop

Lb065c:	; 800B065C
800B065C	lui    s0, $8006
800B0660	lw     v0, $794c(s0)
800B0664	nop
800B0668	lw     v0, $001c(v0)
800B066C	nop
800B0670	lbu    a0, $0824(v0)
800B0674	jal    func559c8 [$800559c8]
800B0678	addu   a1, s1, zero
800B067C	lw     v0, $794c(s0)
800B0680	nop
800B0684	lw     v1, $001c(v0)
800B0688	addu   v0, zero, zero
800B068C	j      Lb19f0 [$800b19f0]
800B0690	sb     s1, $0826(v1)

Lb0694:	; 800B0694
800B0694	jal    func55b6c [$80055b6c]
800B0698	addu   a0, s1, zero
800B069C	j      Lb19f0 [$800b19f0]
800B06A0	addu   v0, zero, zero

Lb06a4:	; 800B06A4
800B06A4	jal    func55c08 [$80055c08]
800B06A8	addu   a0, s1, zero
800B06AC	j      Lb19f0 [$800b19f0]
800B06B0	addu   v0, zero, zero

Lb06b4:	; 800B06B4
800B06B4	jal    func55ca4 [$80055ca4]
800B06B8	addu   a0, s1, zero
800B06BC	j      Lb19f0 [$800b19f0]
800B06C0	addu   v0, zero, zero

Lb06c4:	; 800B06C4
800B06C4	lui    s0, $8006
800B06C8	lw     v0, $794c(s0)
800B06CC	nop
800B06D0	lw     v0, $001c(v0)
800B06D4	nop
800B06D8	lw     a0, $0814(v0)
800B06DC	jal    func553bc [$800553bc]
800B06E0	addu   a1, s1, zero
800B06E4	lw     v1, $794c(s0)
800B06E8	nop
800B06EC	lw     v1, $001c(v1)
800B06F0	nop
800B06F4	sb     v0, $0824(v1)
800B06F8	lw     v0, $794c(s0)
800B06FC	nop
800B0700	lw     a1, $001c(v0)
800B0704	lui    a0, $2000
800B0708	lw     v1, $0000(a1)
800B070C	addu   v0, zero, zero
800B0710	or     v1, v1, a0
800B0714	j      Lb19f0 [$800b19f0]
800B0718	sw     v1, $0000(a1)
800B071C	lw     t2, $0058(sp)
800B0720	addiu  v0, zero, $0002
800B0724	andi   v1, t2, $003f
800B0728	beq    v1, v0, Lb078c [$800b078c]
800B072C	slti   v0, v1, $0003
800B0730	beq    v0, zero, Lb0748 [$800b0748]
800B0734	addiu  v0, zero, $0001
800B0738	beq    v1, v0, Lb0764 [$800b0764]
800B073C	addiu  v0, zero, $ffff (=-$1)
800B0740	j      Lb19f0 [$800b19f0]
800B0744	nop

Lb0748:	; 800B0748
800B0748	addiu  v0, zero, $0003
800B074C	beq    v1, v0, Lb07a0 [$800b07a0]
800B0750	addiu  v0, zero, $0004
800B0754	beq    v1, v0, Lb07b4 [$800b07b4]
800B0758	addiu  v0, zero, $ffff (=-$1)
800B075C	j      Lb19f0 [$800b19f0]
800B0760	nop

Lb0764:	; 800B0764
800B0764	lui    v0, $8006
800B0768	lw     v0, $794c(v0)
800B076C	nop
800B0770	lw     v0, $001c(v0)
800B0774	addu   a1, s1, zero
800B0778	lbu    a0, $0824(v0)
800B077C	jal    func559fc [$800559fc]
800B0780	addu   a2, s3, zero
800B0784	j      Lb08d0 [$800b08d0]
800B0788	addu   a0, s3, zero

Lb078c:	; 800B078C
800B078C	addu   a0, s1, zero
800B0790	jal    func55b98 [$80055b98]
800B0794	addu   a1, s3, zero
800B0798	j      Lb19f0 [$800b19f0]
800B079C	addu   v0, zero, zero

Lb07a0:	; 800B07A0
800B07A0	addu   a0, s1, zero
800B07A4	jal    func55c34 [$80055c34]
800B07A8	addu   a1, s3, zero
800B07AC	j      Lb19f0 [$800b19f0]
800B07B0	addu   v0, zero, zero

Lb07b4:	; 800B07B4
800B07B4	addu   a0, s1, zero
800B07B8	jal    func55cd0 [$80055cd0]
800B07BC	addu   a1, s3, zero
800B07C0	j      Lb19f0 [$800b19f0]
800B07C4	addu   v0, zero, zero
800B07C8	lw     t1, $0058(sp)
800B07CC	addiu  v0, zero, $0002
800B07D0	andi   v1, t1, $003f
800B07D4	beq    v1, v0, Lb0830 [$800b0830]
800B07D8	slti   v0, v1, $0003
800B07DC	beq    v0, zero, Lb07f4 [$800b07f4]
800B07E0	addiu  v0, zero, $0001

Lb07e4:	; 800B07E4
800B07E4	beq    v1, v0, Lb0810 [$800b0810]
800B07E8	addiu  v0, zero, $ffff (=-$1)
800B07EC	j      Lb19f0 [$800b19f0]
800B07F0	nop

Lb07f4:	; 800B07F4
800B07F4	addiu  v0, zero, $0003

Lb07f8:	; 800B07F8
800B07F8	beq    v1, v0, Lb0848 [$800b0848]
800B07FC	addiu  v0, zero, $0004
800B0800	beq    v1, v0, Lb0860 [$800b0860]
800B0804	addiu  v0, zero, $ffff (=-$1)
800B0808	j      Lb19f0 [$800b19f0]
800B080C	nop

Lb0810:	; 800B0810
800B0810	lui    v0, $8006
800B0814	lw     v0, $794c(v0)
800B0818	addu   a1, s1, zero

funcb081c:	; 800B081C
800B081C	lw     v0, $001c(v0)
800B0820	nop
800B0824	lbu    a0, $0824(v0)
800B0828	j      Lb08c4 [$800b08c4]
800B082C	addu   a2, s3, zero

Lb0830:	; 800B0830
800B0830	addu   a0, s1, zero
800B0834	addu   a1, s3, zero
800B0838	jal    func55bcc [$80055bcc]
800B083C	addu   a2, s5, zero
800B0840	j      Lb19f0 [$800b19f0]
800B0844	addu   v0, zero, zero

Lb0848:	; 800B0848
800B0848	addu   a0, s1, zero
800B084C	addu   a1, s3, zero
800B0850	jal    func55c68 [$80055c68]
800B0854	addu   a2, s5, zero
800B0858	j      Lb19f0 [$800b19f0]
800B085C	addu   v0, zero, zero

Lb0860:	; 800B0860
800B0860	addu   a0, s1, zero
800B0864	addu   a1, s3, zero
800B0868	jal    func55d04 [$80055d04]
800B086C	addu   a2, s5, zero
800B0870	j      Lb19f0 [$800b19f0]
800B0874	addu   v0, zero, zero
800B0878	lw     t2, $0058(sp)
800B087C	addiu  v0, zero, $0001
800B0880	andi   v1, t2, $003f
800B0884	bne    v1, v0, Lb19f0 [$800b19f0]
800B0888	addiu  v0, zero, $ffff (=-$1)
800B088C	addu   a0, zero, zero
800B0890	addu   a1, s1, zero
800B0894	jal    func559fc [$800559fc]
800B0898	addu   a2, s3, zero
800B089C	j      Lb08d0 [$800b08d0]
800B08A0	addu   a0, s3, zero
800B08A4	lw     t1, $0058(sp)
800B08A8	addiu  v0, zero, $0001
800B08AC	andi   v1, t1, $003f
800B08B0	bne    v1, v0, Lb19f0 [$800b19f0]
800B08B4	addiu  v0, zero, $ffff (=-$1)
800B08B8	addu   a0, zero, zero
800B08BC	addu   a1, s1, zero
800B08C0	addu   a2, s3, zero

Lb08c4:	; 800B08C4
800B08C4	jal    func55a34 [$80055a34]
800B08C8	addu   a3, s5, zero
800B08CC	addu   a0, s5, zero

Lb08d0:	; 800B08D0
800B08D0	jal    funcb2c40 [$800b2c40]
800B08D4	addu   a1, s1, zero
800B08D8	j      Lb19f0 [$800b19f0]
800B08DC	addu   v0, zero, zero
800B08E0	lw     t2, $0058(sp)
800B08E4	addiu  v0, zero, $0006
800B08E8	andi   v1, t2, $003f
800B08EC	bne    v1, v0, Lb19f0 [$800b19f0]
800B08F0	addiu  v0, zero, $ffff (=-$1)
800B08F4	jal    func55604 [$80055604]
800B08F8	addu   a0, s6, zero
800B08FC	j      Lb19f0 [$800b19f0]
800B0900	addu   v0, zero, zero

Lb0970:	; 800B0970
800B0970	lw     v0, $794c(v0)
800B0974	nop
800B0978	lw     v1, $001c(v0)

loopb097c:	; 800B097C
800B097C	nop
800B0980	lhu    v0, $0830(v1)
800B0984	nop
800B0988	beq    v0, s6, Lb09a4 [$800b09a4]
800B098C	slti   v0, s2, $0002
800B0990	addiu  s2, s2, $0001
800B0994	slti   v0, s2, $0002
800B0998	bne    v0, zero, loopb097c [$800b097c]
800B099C	addiu  v1, v1, $0002
800B09A0	slti   v0, s2, $0002

Lb09a4:	; 800B09A4
800B09A4	bne    v0, zero, Lb09b8 [$800b09b8]
800B09A8	lui    v0, $0010

Lb09ac:	; 800B09AC
800B09AC	j      Lb19f0 [$800b19f0]
800B09B0	addiu  v0, zero, $ffff (=-$1)

Lb09b4:	; 800B09B4
800B09B4	lui    v0, $0010

Lb09b8:	; 800B09B8
800B09B8	sllv   v0, s2, v0
800B09BC	lui    v1, $0030
800B09C0	and    s1, v0, v1
800B09C4	sll    t1, s2, $01
800B09C8	lui    v0, $0200
800B09CC	sllv   v0, t1, v0
800B09D0	sra    t2, v0, $01
800B09D4	sw     t1, $002c(sp)
800B09D8	sw     v0, $0024(sp)
800B09DC	bne    s4, zero, Lb0b04 [$800b0b04]
800B09E0	sw     t2, $0028(sp)
800B09E4	lui    t1, $8006
800B09E8	lw     v0, $794c(t1)
800B09EC	lw     t2, $002c(sp)
800B09F0	lw     v1, $001c(v0)
800B09F4	nop
800B09F8	addu   v0, v1, t2
800B09FC	lhu    v0, $0830(v0)
800B0A00	nop
800B0A04	beq    v0, s6, Lb0b08 [$800b0b08]
800B0A08	lui    v0, $8006
800B0A0C	lw     v0, $0000(v1)
800B0A10	lw     t1, $0024(sp)
800B0A14	nop
800B0A18	and    v0, v0, t1
800B0A1C	beq    v0, zero, Lb0a58 [$800b0a58]
800B0A20	sll    v0, s2, $02
800B0A24	addu   v0, v1, v0
800B0A28	lw     a0, $0828(v0)
800B0A2C	jal    func5546c [$8005546c]
800B0A30	addu   a1, s1, zero
800B0A34	lui    t2, $8006
800B0A38	lw     v0, $794c(t2)
800B0A3C	lw     t1, $0024(sp)
800B0A40	lw     a0, $001c(v0)
800B0A44	lw     t2, $0028(sp)
800B0A48	lw     v0, $0000(a0)
800B0A4C	or     v1, t1, t2
800B0A50	xor    v0, v0, v1
800B0A54	sw     v0, $0000(a0)

Lb0a58:	; 800B0A58
800B0A58	addiu  a0, zero, $0004

Lb0a5c:	; 800B0A5C
800B0A5C	addu   a1, s7, zero
800B0A60	jal    func1c7fc [$8001c7fc]
800B0A64	addu   a2, zero, zero
800B0A68	addiu  a0, zero, $0005

funcb0a6c:	; 800B0A6C
800B0A6C	addu   a1, s7, zero
800B0A70	addu   a2, zero, zero
800B0A74	jal    func1c7fc [$8001c7fc]
800B0A78	addu   s0, v0, zero
800B0A7C	lui    t1, $8006
800B0A80	lw     v1, $794c(t1)
800B0A84	addu   a1, s0, zero
800B0A88	lw     v1, $001c(v1)
800B0A8C	sll    a0, s2, $02
800B0A90	addu   v1, v1, a0
800B0A94	lw     a0, $0828(v1)
800B0A98	jal    func15c28 [$80015c28]
800B0A9C	addu   a2, v0, zero
800B0AA0	lui    t2, $8006
800B0AA4	lw     v1, $794c(t2)
800B0AA8	lw     t1, $002c(sp)
800B0AAC	lw     v0, $001c(v1)
800B0AB0	nop
800B0AB4	addu   v0, v0, t1
800B0AB8	sh     s6, $0830(v0)
800B0ABC	lw     v0, $001c(v1)
800B0AC0	addiu  v1, zero, $007f
800B0AC4	addu   v0, v0, s2
800B0AC8	sb     v1, $08b8(v0)
800B0ACC	lw     v0, $794c(t2)
800B0AD0	nop
800B0AD4	lw     v0, $001c(v0)
800B0AD8	addiu  v1, zero, $0080
800B0ADC	addu   v0, v0, s2
800B0AE0	sb     v1, $08ba(v0)
800B0AE4	lw     v0, $794c(t2)
800B0AE8	nop
800B0AEC	lw     v1, $001c(v0)
800B0AF0	lw     t2, $0028(sp)
800B0AF4	lw     v0, $0000(v1)
800B0AF8	nop
800B0AFC	or     v0, v0, t2
800B0B00	sw     v0, $0000(v1)

Lb0b04:	; 800B0B04
800B0B04	lui    v0, $8006

Lb0b08:	; 800B0B08
800B0B08	lw     v0, $794c(v0)
800B0B0C	nop
800B0B10	lw     v0, $001c(v0)
800B0B14	sll    v1, s2, $02
800B0B18	addu   v0, v0, v1
800B0B1C	lw     a0, $0828(v0)
800B0B20	j      Lb0b3c [$800b0b3c]
800B0B24	sltiu  v0, s4, $000a

Lb0b28:	; 800B0B28
800B0B28	addiu  a0, zero, $0004
800B0B2C	jal    func1c7fc [$8001c7fc]
800B0B30	addu   a2, zero, zero
800B0B34	addu   a0, v0, zero

Lb0b38:	; 800B0B38
800B0B38	sltiu  v0, s4, $000a

Lb0b3c:	; 800B0B3C
800B0B3C	beq    v0, zero, Lb09ac [$800b09ac]
800B0B40	lui    v0, $800a
800B0B44	addiu  v0, v0, $7104
800B0B48	sll    v1, s4, $02
800B0B4C	addu   v1, v1, v0
800B0B50	lw     v0, $0000(v1)
800B0B54	nop
800B0B58	jr     v0 
800B0B5C	nop

800B0B60	lui    v0, $8006
800B0B64	lw     v0, $794c(v0)
800B0B68	nop
800B0B6C	lw     a2, $001c(v0)
800B0B70	sll    v0, s2, $01
800B0B74	addu   a1, a2, v0
800B0B78	lhu    v1, $0830(a1)
800B0B7C	ori    v0, zero, $ffff
800B0B80	beq    v1, v0, Lb0bbc [$800b0bbc]
800B0B84	addu   a3, zero, zero
800B0B88	lhu    v1, $08b4(a1)
800B0B8C	lh     v0, $000c(a2)
800B0B90	nop
800B0B94	bne    v1, v0, Lb0bc0 [$800b0bc0]
800B0B98	lui    v0, $8006
800B0B9C	lui    v0, $0010
800B0BA0	sllv   v0, s2, v0
800B0BA4	lui    v1, $0030
800B0BA8	and    s1, v0, v1
800B0BAC	addiu  a3, zero, $0001
800B0BB0	addu   v0, a2, s2
800B0BB4	lbu    s3, $08ba(v0)
800B0BB8	lbu    s5, $08b8(v0)

Lb0bbc:	; 800B0BBC
800B0BBC	lui    v0, $8006

Lb0bc0:	; 800B0BC0
800B0BC0	lw     v0, $794c(v0)
800B0BC4	nop
800B0BC8	lw     v0, $001c(v0)
800B0BCC	sll    v1, s2, $01
800B0BD0	addu   v0, v0, v1
800B0BD4	ori    v1, zero, $ffff
800B0BD8	beq    a3, zero, Lb04b0 [$800b04b0]
800B0BDC	sh     v1, $08b4(v0)
800B0BE0	beq    fp, zero, Lb0c0c [$800b0c0c]
800B0BE4	lui    v0, $8006
800B0BE8	lw     v0, $794c(v0)
800B0BEC	nop
800B0BF0	lw     v0, $001c(v0)
800B0BF4	lw     t1, $0024(sp)
800B0BF8	lw     v0, $0000(v0)
800B0BFC	nop
800B0C00	and    v0, v0, t1
800B0C04	bne    v0, zero, Lb0c1c [$800b0c1c]
800B0C08	nop

Lb0c0c:	; 800B0C0C
800B0C0C	addu   a1, s1, zero
800B0C10	addu   a2, s3, zero
800B0C14	jal    func553ec [$800553ec]
800B0C18	addu   a3, s5, zero

Lb0c1c:	; 800B0C1C
800B0C1C	beq    fp, zero, Lb04b0 [$800b04b0]
800B0C20	lui    v1, $8006
800B0C24	lw     v0, $794c(v1)
800B0C28	nop
800B0C2C	lw     v0, $001c(v0)
800B0C30	nop
800B0C34	addu   v0, v0, s2
800B0C38	sb     s3, $08ba(v0)
800B0C3C	lw     v0, $794c(v1)
800B0C40	nop
800B0C44	lw     v0, $001c(v0)
800B0C48	nop
800B0C4C	addu   v0, v0, s2
800B0C50	sb     s5, $08b8(v0)
800B0C54	lw     v0, $794c(v1)
800B0C58	nop
800B0C5C	lw     v1, $001c(v0)
800B0C60	lw     t2, $0024(sp)
800B0C64	lw     v0, $0000(v1)
800B0C68	nop
800B0C6C	or     v0, v0, t2
800B0C70	j      Lb04b0 [$800b04b0]
800B0C74	sw     v0, $0000(v1)
800B0C78	lui    v0, $8006
800B0C7C	lw     v0, $794c(v0)
800B0C80	nop
800B0C84	lw     a1, $001c(v0)
800B0C88	lw     t1, $0024(sp)
800B0C8C	lw     v0, $0000(a1)
800B0C90	nop
800B0C94	and    v0, v0, t1
800B0C98	beq    v0, zero, Lb04b0 [$800b04b0]
800B0C9C	sll    v0, s2, $01
800B0CA0	lhu    v1, $000c(a1)
800B0CA4	addu   v0, a1, v0
800B0CA8	sh     v1, $08b4(v0)
800B0CAC	lw     t2, $0058(sp)
800B0CB0	addiu  v0, zero, $0009
800B0CB4	andi   v1, t2, $003f
800B0CB8	bne    v1, v0, Lb0d44 [$800b0d44]
800B0CBC	nop
800B0CC0	beq    fp, zero, Lb0d44 [$800b0d44]
800B0CC4	lui    s0, $8006
800B0CC8	lw     v0, $794c(s0)
800B0CCC	nop
800B0CD0	lw     a0, $001c(v0)
800B0CD4	nop
800B0CD8	lw     v0, $0000(a0)
800B0CDC	lui    v1, $0200
800B0CE0	and    v0, v0, v1
800B0CE4	beq    v0, zero, Lb0cf8 [$800b0cf8]
800B0CE8	nop
800B0CEC	lw     a0, $0828(a0)
800B0CF0	jal    func5546c [$8005546c]
800B0CF4	lui    a1, $0010

Lb0cf8:	; 800B0CF8
800B0CF8	lw     v0, $794c(s0)
800B0CFC	nop
800B0D00	lw     a0, $001c(v0)
800B0D04	nop
800B0D08	lw     v0, $0000(a0)

Lb0d0c:	; 800B0D0C
800B0D0C	lui    v1, $0800
800B0D10	and    v0, v0, v1
800B0D14	beq    v0, zero, Lb0d28 [$800b0d28]
800B0D18	nop
800B0D1C	lw     a0, $082c(a0)
800B0D20	jal    func5546c [$8005546c]
800B0D24	lui    a1, $0020

Lb0d28:	; 800B0D28
800B0D28	lw     v0, $794c(s0)
800B0D2C	nop
800B0D30	lw     a0, $001c(v0)
800B0D34	lui    v1, $f5ff
800B0D38	lw     v0, $0000(a0)
800B0D3C	j      Lb0d6c [$800b0d6c]
800B0D40	ori    v1, v1, $ffff

Lb0d44:	; 800B0D44
800B0D44	jal    func5546c [$8005546c]
800B0D48	addu   a1, s1, zero

funcb0d4c:	; 800B0D4C
800B0D4C	beq    fp, zero, Lb04b0 [$800b04b0]
800B0D50	lui    v0, $8006
800B0D54	lw     v0, $794c(v0)
800B0D58	nop
800B0D5C	lw     a0, $001c(v0)
800B0D60	lw     t1, $0024(sp)
800B0D64	lw     v0, $0000(a0)
800B0D68	nor    v1, zero, t1

Lb0d6c:	; 800B0D6C
800B0D6C	and    v0, v0, v1
800B0D70	j      Lb04b0 [$800b04b0]
800B0D74	sw     v0, $0000(a0)
800B0D78	lw     t2, $0058(sp)
800B0D7C	addiu  v0, zero, $0003
800B0D80	andi   v1, t2, $003f
800B0D84	beq    v1, v0, Lb0e20 [$800b0e20]
800B0D88	slti   v0, v1, $0004
800B0D8C	beq    v0, zero, Lb0da4 [$800b0da4]
800B0D90	addiu  v0, zero, $0001
800B0D94	beq    v1, v0, Lb0dc0 [$800b0dc0]
800B0D98	addiu  v0, zero, $ffff (=-$1)
800B0D9C	j      Lb19f0 [$800b19f0]
800B0DA0	nop

Lb0da4:	; 800B0DA4
800B0DA4	addiu  v0, zero, $0005
800B0DA8	beq    v1, v0, Lb0df0 [$800b0df0]
800B0DAC	addiu  v0, zero, $0008
800B0DB0	beq    v1, v0, Lb04b0 [$800b04b0]
800B0DB4	addiu  v0, zero, $ffff (=-$1)
800B0DB8	j      Lb19f0 [$800b19f0]
800B0DBC	nop

Lb0dc0:	; 800B0DC0
800B0DC0	addu   a1, s1, zero
800B0DC4	jal    func55764 [$80055764]
800B0DC8	addu   a2, s3, zero
800B0DCC	beq    fp, zero, Lb04b0 [$800b04b0]
800B0DD0	lui    v0, $8006
800B0DD4	lw     v0, $794c(v0)
800B0DD8	nop
800B0DDC	lw     v0, $001c(v0)
800B0DE0	nop
800B0DE4	addu   v0, v0, s2
800B0DE8	j      Lb04b0 [$800b04b0]

Lb0dec:	; 800B0DEC
800B0DEC	sb     s3, $08b8(v0)

Lb0df0:	; 800B0DF0
800B0DF0	addu   a1, s1, zero
800B0DF4	jal    func55850 [$80055850]
800B0DF8	addu   a2, s3, zero
800B0DFC	beq    fp, zero, Lb04b0 [$800b04b0]
800B0E00	lui    v0, $8006

funcb0e04:	; 800B0E04
800B0E04	lw     v0, $794c(v0)
800B0E08	nop
800B0E0C	lw     v0, $001c(v0)
800B0E10	nop
800B0E14	addu   v0, v0, s2
800B0E18	j      Lb04b0 [$800b04b0]
800B0E1C	sb     s3, $08ba(v0)

Lb0e20:	; 800B0E20
800B0E20	addu   a1, s1, zero
800B0E24	jal    func5593c [$8005593c]
800B0E28	addu   a2, s3, zero
800B0E2C	j      Lb19f0 [$800b19f0]
800B0E30	addu   v0, zero, zero
800B0E34	lw     t1, $0058(sp)
800B0E38	addiu  v0, zero, $0003
800B0E3C	andi   v1, t1, $003f
800B0E40	beq    v1, v0, Lb0edc [$800b0edc]
800B0E44	slti   v0, v1, $0004
800B0E48	beq    v0, zero, Lb0e60 [$800b0e60]
800B0E4C	addiu  v0, zero, $0001
800B0E50	beq    v1, v0, Lb0e74 [$800b0e74]
800B0E54	addiu  v0, zero, $ffff (=-$1)
800B0E58	j      Lb19f0 [$800b19f0]
800B0E5C	nop

Lb0e60:	; 800B0E60
800B0E60	addiu  v0, zero, $0005
800B0E64	beq    v1, v0, Lb0ea8 [$800b0ea8]
800B0E68	addiu  v0, zero, $ffff (=-$1)
800B0E6C	j      Lb19f0 [$800b19f0]
800B0E70	nop

Lb0e74:	; 800B0E74
800B0E74	addu   a1, s1, zero
800B0E78	addu   a2, s3, zero
800B0E7C	jal    func557a8 [$800557a8]
800B0E80	addu   a3, s5, zero

Lb0e84:	; 800B0E84
800B0E84	beq    fp, zero, Lb04b0 [$800b04b0]
800B0E88	lui    v0, $8006
800B0E8C	lw     v0, $794c(v0)
800B0E90	nop
800B0E94	lw     v0, $001c(v0)
800B0E98	nop
800B0E9C	addu   v0, v0, s2
800B0EA0	j      Lb04b0 [$800b04b0]
800B0EA4	sb     s5, $08b8(v0)

Lb0ea8:	; 800B0EA8
800B0EA8	addu   a1, s1, zero
800B0EAC	addu   a2, s3, zero
800B0EB0	jal    func55894 [$80055894]
800B0EB4	addu   a3, s5, zero
800B0EB8	beq    fp, zero, Lb04b0 [$800b04b0]
800B0EBC	lui    v0, $8006
800B0EC0	lw     v0, $794c(v0)
800B0EC4	nop
800B0EC8	lw     v0, $001c(v0)
800B0ECC	nop
800B0ED0	addu   v0, v0, s2
800B0ED4	j      Lb04b0 [$800b04b0]
800B0ED8	sb     s5, $08ba(v0)

Lb0edc:	; 800B0EDC
800B0EDC	addu   a1, s1, zero
800B0EE0	addu   a2, s3, zero
800B0EE4	jal    func55980 [$80055980]
800B0EE8	addu   a3, s5, zero
800B0EEC	j      Lb19f0 [$800b19f0]
800B0EF0	addu   v0, zero, zero
800B0EF4	lw     t2, $0058(sp)

funcb0ef8:	; 800B0EF8
800B0EF8	addiu  v0, zero, $0003
800B0EFC	andi   v1, t2, $003f
800B0F00	beq    v1, v0, Lb0f8c [$800b0f8c]
800B0F04	slti   v0, v1, $0004
800B0F08	beq    v0, zero, Lb0f20 [$800b0f20]
800B0F0C	addiu  v0, zero, $0001
800B0F10	beq    v1, v0, Lb0f34 [$800b0f34]
800B0F14	addiu  v0, zero, $ffff (=-$1)
800B0F18	j      Lb19f0 [$800b19f0]
800B0F1C	nop

Lb0f20:	; 800B0F20
800B0F20	addiu  v0, zero, $0005
800B0F24	beq    v1, v0, Lb0f60 [$800b0f60]
800B0F28	addiu  v0, zero, $ffff (=-$1)
800B0F2C	j      Lb19f0 [$800b19f0]
800B0F30	nop

Lb0f34:	; 800B0F34
800B0F34	jal    func55704 [$80055704]
800B0F38	addu   a0, s1, zero
800B0F3C	beq    fp, zero, Lb04b0 [$800b04b0]
800B0F40	lui    v0, $8006
800B0F44	lw     v0, $794c(v0)
800B0F48	nop
800B0F4C	lw     v0, $001c(v0)
800B0F50	nop
800B0F54	sb     s1, $08b9(v0)
800B0F58	j      Lb04b0 [$800b04b0]
800B0F5C	sb     s1, $08b8(v0)

Lb0f60:	; 800B0F60
800B0F60	jal    func557f0 [$800557f0]
800B0F64	addu   a0, s1, zero
800B0F68	beq    fp, zero, Lb04b0 [$800b04b0]
800B0F6C	lui    v0, $8006
800B0F70	lw     v0, $794c(v0)
800B0F74	nop
800B0F78	lw     v0, $001c(v0)
800B0F7C	nop
800B0F80	sb     s1, $08bb(v0)
800B0F84	j      Lb04b0 [$800b04b0]
800B0F88	sb     s1, $08ba(v0)

Lb0f8c:	; 800B0F8C
800B0F8C	jal    func558dc [$800558dc]
800B0F90	addu   a0, s1, zero
800B0F94	j      Lb19f0 [$800b19f0]
800B0F98	addu   v0, zero, zero
800B0F9C	lw     t1, $0058(sp)
800B0FA0	addiu  v0, zero, $0003
800B0FA4	andi   v1, t1, $003f
800B0FA8	beq    v1, v0, Lb103c [$800b103c]
800B0FAC	slti   v0, v1, $0004
800B0FB0	beq    v0, zero, Lb0fc8 [$800b0fc8]
800B0FB4	addiu  v0, zero, $0001
800B0FB8	beq    v1, v0, Lb0fdc [$800b0fdc]
800B0FBC	addiu  v0, zero, $ffff (=-$1)

funcb0fc0:	; 800B0FC0
800B0FC0	j      Lb19f0 [$800b19f0]
800B0FC4	nop

Lb0fc8:	; 800B0FC8
800B0FC8	addiu  v0, zero, $0005
800B0FCC	beq    v1, v0, Lb100c [$800b100c]
800B0FD0	addiu  v0, zero, $ffff (=-$1)
800B0FD4	j      Lb19f0 [$800b19f0]
800B0FD8	nop

Lb0fdc:	; 800B0FDC
800B0FDC	addu   a0, s1, zero
800B0FE0	jal    func55730 [$80055730]
800B0FE4	addu   a1, s3, zero
800B0FE8	beq    fp, zero, Lb09ac [$800b09ac]
800B0FEC	lui    v0, $8006
800B0FF0	lw     v0, $794c(v0)
800B0FF4	nop
800B0FF8	lw     v0, $001c(v0)
800B0FFC	nop
800B1000	sb     s3, $08b9(v0)
800B1004	j      Lb09ac [$800b09ac]
800B1008	sb     s3, $08b8(v0)

Lb100c:	; 800B100C
800B100C	addu   a0, s1, zero
800B1010	jal    func5581c [$8005581c]
800B1014	addu   a1, s3, zero
800B1018	beq    fp, zero, Lb09ac [$800b09ac]
800B101C	lui    v0, $8006
800B1020	lw     v0, $794c(v0)
800B1024	nop
800B1028	lw     v0, $001c(v0)
800B102C	nop
800B1030	sb     s3, $08bb(v0)
800B1034	j      Lb09ac [$800b09ac]
800B1038	sb     s3, $08ba(v0)

Lb103c:	; 800B103C
800B103C	addu   a0, s1, zero
800B1040	jal    func55908 [$80055908]
800B1044	addu   a1, s3, zero
800B1048	j      Lb19f0 [$800b19f0]
800B104C	addiu  v0, zero, $ffff (=-$1)

Lb1050:	; 800B1050
800B1050	andi   v1, s6, $ffff
800B1054	lui    v0, $0018
800B1058	beq    s4, a3, Lb117c [$800b117c]
800B105C	or     s7, v1, v0

Lb1060:	; 800B1060
800B1060	slti   v0, s4, $0002
800B1064	beq    v0, zero, Lb107c [$800b107c]
800B1068	nop
800B106C	beq    s4, zero, Lb108c [$800b108c]
800B1070	addiu  v0, zero, $ffff (=-$1)
800B1074	j      Lb19f0 [$800b19f0]
800B1078	nop

Lb107c:	; 800B107C
800B107C	beq    s4, a0, Lb118c [$800b118c]
800B1080	addiu  v0, zero, $ffff (=-$1)
800B1084	j      Lb19f0 [$800b19f0]
800B1088	nop

Lb108c:	; 800B108C
800B108C	addiu  a0, zero, $0004
800B1090	addu   a1, s7, zero
800B1094	jal    func1c7fc [$8001c7fc]
800B1098	addu   a2, zero, zero
800B109C	lui    s0, $8006
800B10A0	lw     v1, $794c(s0)
800B10A4	nop
800B10A8	lw     v1, $001c(v1)
800B10AC	nop
800B10B0	lbu    v1, $0851(v1)
800B10B4	nop
800B10B8	bne    v1, zero, Lb09ac [$800b09ac]
800B10BC	addu   s2, v0, zero
800B10C0	jal    funcae68c [$800ae68c]
800B10C4	nop
800B10C8	beq    v0, zero, Lb1104 [$800b1104]
800B10CC	nop
800B10D0	lw     v0, $794c(s0)
800B10D4	nop
800B10D8	lw     v0, $001c(v0)
800B10DC	nop
800B10E0	lw     v0, $08e4(v0)
800B10E4	nop
800B10E8	lw     v0, $000c(v0)
800B10EC	nop
800B10F0	lw     v0, $0014(v0)
800B10F4	nop

funcb10f8:	; 800B10F8
800B10F8	lbu    a0, $005d(v0)
800B10FC	j      Lb1130 [$800b1130]
800B1100	nop

Lb1104:	; 800B1104
800B1104	lw     v0, $794c(s0)
800B1108	nop
800B110C	lw     v0, $001c(v0)
800B1110	nop
800B1114	lw     v0, $08e4(v0)
800B1118	nop
800B111C	lw     v0, $000c(v0)
800B1120	nop
800B1124	lw     v0, $0014(v0)
800B1128	nop
800B112C	lbu    a0, $005c(v0)

Lb1130:	; 800B1130
800B1130	jal    func56248 [$80056248]
800B1134	nop
800B1138	addu   a0, s2, zero
800B113C	addu   a1, s1, zero
800B1140	jal    func561c4 [$800561c4]
800B1144	addu   a2, s3, zero
800B1148	lui    v0, $8006
800B114C	lw     v0, $794c(v0)
800B1150	nop
800B1154	lw     v0, $001c(v0)
800B1158	nop
800B115C	lw     v0, $08e4(v0)
800B1160	nop
800B1164	lw     v0, $000c(v0)
800B1168	nop

Lb116c:	; 800B116C
800B116C	lw     v1, $0014(v0)
800B1170	addu   v0, zero, zero
800B1174	j      Lb19f0 [$800b19f0]
800B1178	sb     zero, $005f(v1)

Lb117c:	; 800B117C
800B117C	jal    func56228 [$80056228]
800B1180	nop
800B1184	j      Lb19f0 [$800b19f0]
800B1188	addu   v0, zero, zero

Lb118c:	; 800B118C
800B118C	lw     t2, $0058(sp)
800B1190	nop
800B1194	andi   v0, t2, $003f
800B1198	addiu  v1, v0, $ffff (=-$1)
800B119C	sltiu  v0, v1, $000c
800B11A0	beq    v0, zero, Lb09ac [$800b09ac]
800B11A4	lui    v0, $800a
800B11A8	addiu  v0, v0, $712c
800B11AC	sll    v1, v1, $02
800B11B0	addu   v1, v1, v0
800B11B4	lw     v0, $0000(v1)
800B11B8	nop
800B11BC	jr     v0 
800B11C0	nop

800B11C4	lui    v0, $8006
800B11C8	lw     v0, $794c(v0)
800B11CC	nop
800B11D0	lw     v0, $001c(v0)
800B11D4	nop
800B11D8	lw     v0, $08e4(v0)
800B11DC	nop
800B11E0	lw     v0, $000c(v0)
800B11E4	nop
800B11E8	lw     v0, $0014(v0)
800B11EC	jal    funcae68c [$800ae68c]
800B11F0	sb     s1, $005c(v0)
800B11F4	bne    v0, zero, Lb19f0 [$800b19f0]
800B11F8	addu   v0, zero, zero
800B11FC	jal    func56248 [$80056248]
800B1200	addu   a0, s1, zero
800B1204	j      Lb19f0 [$800b19f0]
800B1208	addu   v0, zero, zero
800B120C	lui    v0, $8006
800B1210	lw     v0, $794c(v0)
800B1214	nop
800B1218	lw     v0, $001c(v0)
800B121C	nop

Lb1220:	; 800B1220
800B1220	lw     v0, $08e4(v0)
800B1224	nop
800B1228	lw     v0, $000c(v0)
800B122C	nop
800B1230	lw     v0, $0014(v0)
800B1234	jal    funcae68c [$800ae68c]
800B1238	sb     s1, $005d(v0)
800B123C	beq    v0, zero, Lb19f0 [$800b19f0]
800B1240	addu   v0, zero, zero
800B1244	jal    func56248 [$80056248]
800B1248	addu   a0, s1, zero
800B124C	j      Lb19f0 [$800b19f0]

funcb1250:	; 800B1250
800B1250	addu   v0, zero, zero
800B1254	jal    func562b0 [$800562b0]
800B1258	addu   a0, s1, zero
800B125C	j      Lb19f0 [$800b19f0]
800B1260	addu   v0, zero, zero
800B1264	lui    v0, $8006
800B1268	lw     v0, $794c(v0)
800B126C	nop
800B1270	lw     v0, $001c(v0)
800B1274	nop
800B1278	lw     v0, $08e4(v0)
800B127C	nop
800B1280	lw     v0, $000c(v0)
800B1284	nop
800B1288	lw     v1, $0014(v0)
800B128C	addu   v0, zero, zero
800B1290	j      Lb19f0 [$800b19f0]
800B1294	sb     s1, $005f(v1)

Lb1298:	; 800B1298
800B1298	andi   v0, s6, $ffff
800B129C	lui    v1, $0009
800B12A0	or     s7, v0, v1
800B12A4	addiu  v0, zero, $0007
800B12A8	beq    s4, v0, Lb12c0 [$800b12c0]
800B12AC	lui    a2, $8006
800B12B0	beq    s4, a1, Lb1388 [$800b1388]
800B12B4	addiu  v0, zero, $ffff (=-$1)
800B12B8	j      Lb19f0 [$800b19f0]
800B12BC	nop

Lb12c0:	; 800B12C0
800B12C0	lw     a1, $794c(a2)
800B12C4	nop
800B12C8	lw     v0, $001c(a1)
800B12CC	nop
800B12D0	lw     v0, $08e4(v0)
800B12D4	nop
800B12D8	lw     v0, $000c(v0)
800B12DC	nop
800B12E0	lw     a0, $0014(v0)
800B12E4	nop
800B12E8	lw     v0, $0000(a0)
800B12EC	addiu  v1, zero, $ffef (=-$11)
800B12F0	and    v0, v0, v1
800B12F4	sw     v0, $0000(a0)
if (S1 == 4)
{
    800B1304	lw     v0, $001c(a1)
    800B1308	nop
    800B130C	lw     v0, $08e4(v0)
    800B1310	nop
    800B1314	lw     v0, $000c(v0)
    800B1318	nop
    800B131C	lw     v0, $0014(v0)
    800B1320	nop
    800B1324	sb     s3, $005e(v0)
    800B1328	lw     v0, $794c(a2)
    800B132C	nop
    800B1330	lw     v0, $001c(v0)
    800B1334	nop
    800B1338	lw     v0, $08e4(v0)
    800B133C	nop
    800B1340	lw     v0, $000c(v0)
    800B1344	nop
    800B1348	lw     v1, $0014(v0)
    800B134C	nop
    800B1350	lw     v0, $0000(v1)
    800B1354	nop
    800B1358	ori    v0, v0, $0010
    800B135C	sw     v0, $0000(v1)
}

[800c9d4c] = b(S4);
[800c9d50] = w(S7);
V1 = w[8006794c];
V1 = w[V1 + 1c];
[V1 + 851] = b(1);

800B137C	lw     v0, $794c(a2)
800B1380	j      Lb19e0 [$800b19e0]
800B1384	nop

Lb1388:	; 800B1388
800B1388	lui    v0, $8006

Lb138c:	; 800B138C
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = bu[V0 + 851];
V1 = V0 - 1;
V0 = V1 != 0 && V1 < 6;
800B13AC	beq    v0, zero, Lb19d8 [$800b19d8]

V0 = 800a715c;
V1 = V1 * 4;
800B13BC	addu   v1, v1, v0
800B13C0	lw     v0, $0000(v1)
800B13C4	nop
800B13C8	jr     v0 
800B13CC	nop

D0130B80 1
4C140B80 2
B8160B80 3
34180B80 4
F4180B80 5

Lb13d0:	; 800B13D0
800B13D0	jal    funcb2c80 [$800b2c80]
800B13D4	nop

Lb13d8:	; 800B13D8
800B13D8	bne    v0, zero, Lb19dc [$800b19dc]
800B13DC	lui    v0, $8006

Lb13e0:	; 800B13E0
800B13E0	lui    s0, $8006
800B13E4	lw     v0, $794c(s0)
800B13E8	nop
800B13EC	lw     a0, $001c(v0)
800B13F0	nop
800B13F4	lw     v0, $0000(a0)
800B13F8	lui    v1, $0020
800B13FC	and    v0, v0, v1
800B1400	beq    v0, zero, Lb1434 [$800b1434]
800B1404	nop
800B1408	lbu    a0, $0824(a0)
800B140C	jal    func552b8 [$800552b8]
800B1410	nop
800B1414	lw     v0, $794c(s0)
800B1418	nop
800B141C	lw     a0, $001c(v0)
800B1420	lui    v1, $ffdf
800B1424	lw     v0, $0000(a0)
800B1428	ori    v1, v1, $ffff
800B142C	and    v0, v0, v1
800B1430	sw     v0, $0000(a0)

Lb1434:	; 800B1434
800B1434	lw     v0, $794c(s0)
800B1438	nop
800B143C	lw     v1, $001c(v0)
800B1440	addiu  v0, zero, $0002

Lb1444:	; 800B1444
800B1444	j      Lb19d8 [$800b19d8]
800B1448	sb     v0, $0851(v1)
800B144C	lui    a0, $800d
800B1450	lw     v0, $9d50(a0)
800B1454	addiu  v1, zero, $0007
800B1458	sra    v0, v0, $10
800B145C	andi   v0, v0, $00ff
800B1460	bne    v0, v1, Lb1484 [$800b1484]
800B1464	lui    v0, $8006
800B1468	lw     v0, $794c(v0)
800B146C	nop
800B1470	lw     v1, $001c(v0)
800B1474	nop
800B1478	lhu    v0, $0820(v1)
800B147C	j      Lb149c [$800b149c]
800B1480	sh     v0, $0852(v1)

Lb1484:	; 800B1484
800B1484	lw     v0, $794c(v0)
800B1488	nop
800B148C	lw     v1, $001c(v0)
800B1490	lhu    v0, $9d50(a0)
800B1494	nop
800B1498	sh     v0, $0852(v1)

Lb149c:	; 800B149C
800B149C	lui    v0, $800d
800B14A0	lb     v1, $9d4c(v0)
800B14A4	addiu  v0, zero, $0009
800B14A8	bne    v1, v0, Lb14e4 [$800b14e4]
800B14AC	lui    s0, $800d
800B14B0	lui    v0, $8006
800B14B4	lw     v0, $794c(v0)
800B14B8	nop
800B14BC	lw     v1, $001c(v0)
800B14C0	nop
800B14C4	addu   v0, v1, zero
800B14C8	lw     a0, $08a8(v1)
800B14CC	lhu    v0, $084a(v0)
800B14D0	lui    v1, $800d
800B14D4	sll    v0, v0, $0b
800B14D8	sw     a0, $9d54(v1)
800B14DC	j      Lb1538 [$800b1538]
800B14E0	sw     v0, $0020(sp)

Lb14e4:	; 800B14E4
800B14E4	lw     a0, $9d50(s0)
800B14E8	jal    funcb29a0 [$800b29a0]
800B14EC	addiu  a1, sp, $0020
800B14F0	addu   a0, v0, zero
800B14F4	lw     v0, $9d50(s0)
800B14F8	lui    v1, $800d
800B14FC	sw     a0, $9d54(v1)
800B1500	addiu  v1, zero, $0007
800B1504	sra    v0, v0, $10

Lb1508:	; 800B1508
800B1508	andi   v0, v0, $00ff
800B150C	bne    v0, v1, Lb153c [$800b153c]
800B1510	lui    v0, $8006
800B1514	lw     v1, $794c(v0)
800B1518	nop
800B151C	lw     v0, $001c(v1)

funcb1520:	; 800B1520
800B1520	nop
800B1524	sw     a0, $08a8(v0)
800B1528	lw     v0, $0020(sp)
800B152C	lw     v1, $001c(v1)
800B1530	sra    v0, v0, $0b
800B1534	sh     v0, $084a(v1)

Lb1538:	; 800B1538
800B1538	lui    v0, $8006

Lb153c:	; 800B153C
800B153C	lw     v0, $794c(v0)
800B1540	nop
800B1544	lw     v1, $001c(v0)
800B1548	nop
800B154C	lw     v0, $08e4(v1)
800B1550	nop
800B1554	lw     v0, $000c(v0)
800B1558	nop
800B155C	lw     v0, $0014(v0)
800B1560	nop
800B1564	lw     v0, $0000(v0)
800B1568	nop
800B156C	andi   v0, v0, $0010
800B1570	bne    v0, zero, Lb1590 [$800b1590]
800B1574	lui    s0, $8006
800B1578	lhu    v1, $0852(v1)
800B157C	addiu  v0, zero, $0084
800B1580	beq    v1, v0, Lb1590 [$800b1590]
800B1584	nop
800B1588	jal    func55df4 [$80055df4]
800B158C	nop

Lb1590:	; 800B1590
800B1590	lw     a2, $794c(s0)
800B1594	nop
800B1598	lw     v1, $001c(a2)
800B159C	nop
800B15A0	lw     v0, $08e4(v1)
800B15A4	nop
800B15A8	lw     v0, $000c(v0)
800B15AC	nop
800B15B0	lw     v0, $0014(v0)
800B15B4	nop
800B15B8	lw     v0, $0020(v0)
800B15BC	nop
800B15C0	bne    v0, zero, Lb15d0 [$800b15d0]
800B15C4	lui    a0, $0015
800B15C8	lui    v0, $8006
800B15CC	lw     v0, $7948(v0)

Lb15d0:	; 800B15D0
800B15D0	nop
800B15D4	sw     v0, $08c0(v1)
800B15D8	lui    v1, $8006
800B15DC	lw     a1, $001c(a2)
800B15E0	lw     v1, $7944(v1)
800B15E4	lw     v0, $08c0(a1)
800B15E8	ori    a0, a0, $6f00
800B15EC	subu   v0, v0, v1
800B15F0	subu   a0, a0, v0
800B15F4	sw     a0, $0878(a1)
800B15F8	lw     v1, $001c(a2)
800B15FC	nop
800B1600	lw     v0, $08e4(v1)
800B1604	nop

Lb1608:	; 800B1608
800B1608	lw     v0, $0000(v0)
800B160C	nop
800B1610	andi   v0, v0, $0004
800B1614	bne    v0, zero, Lb162c [$800b162c]
800B1618	nop
800B161C	lw     v0, $0878(v1)
800B1620	nop
800B1624	addiu  v0, v0, $d000 (=-$3000)
800B1628	sw     v0, $0878(v1)

Lb162c:	; 800B162C
800B162C	lw     a3, $794c(s0)
800B1630	nop
800B1634	lw     a2, $001c(a3)
800B1638	nop
800B163C	lw     v1, $0878(a2)
800B1640	nop
800B1644	bgez   v1, Lb1650 [$800b1650]
800B1648	addu   a0, v1, zero
800B164C	addiu  a0, v1, $07ff

Lb1650:	; 800B1650
800B1650	lui    v0, $800d
800B1654	lw     a1, $9d54(v0)
800B1658	sra    v0, a0, $0b
800B165C	sll    v0, v0, $0b
800B1660	sw     v0, $0878(a2)
800B1664	lw     v0, $001c(a3)

Lb1668:	; 800B1668
800B1668	nop
800B166C	sw     zero, $087c(v0)
800B1670	lw     a2, $0020(sp)
800B1674	lw     a0, $001c(a3)
800B1678	sw     zero, $0010(sp)
800B167C	lw     v1, $001c(a3)
800B1680	lui    v0, $800b
800B1684	lw     v1, $0878(v1)
800B1688	addiu  v0, v0, $29f8
800B168C	sw     v0, $0018(sp)
800B1690	sw     v1, $0014(sp)
800B1694	lw     a3, $08c0(a0)
800B1698	jal    func2177c [$8002177c]
800B169C	addiu  a0, a0, $0854
800B16A0	lw     v0, $794c(s0)
800B16A4	nop
800B16A8	lw     v1, $001c(v0)
800B16AC	addiu  v0, zero, $0003
800B16B0	j      Lb19d8 [$800b19d8]
800B16B4	sb     v0, $0851(v1)
800B16B8	lui    s0, $8006
800B16BC	lw     v0, $794c(s0)
800B16C0	nop
800B16C4	lw     a0, $001c(v0)
800B16C8	jal    func217c4 [$800217c4]
800B16CC	addiu  a0, a0, $0854
800B16D0	bne    v0, zero, Lb19dc [$800b19dc]
800B16D4	lui    v0, $8006

Lb16d8:	; 800B16D8
800B16D8	jal    func55dcc [$80055dcc]
800B16DC	nop
800B16E0	bne    v0, zero, Lb19dc [$800b19dc]
800B16E4	lui    v0, $8006
800B16E8	lw     v0, $794c(s0)
800B16EC	nop
800B16F0	lw     v0, $001c(v0)
800B16F4	nop
800B16F8	lw     a0, $0874(v0)
800B16FC	jal    funcac67c [$800ac67c]
800B1700	nop
800B1704	lw     v0, $794c(s0)

Lb1708:	; 800B1708
800B1708	nop
800B170C	lw     v0, $001c(v0)
800B1710	nop
800B1714	lw     a0, $085c(v0)
800B1718	lw     a1, $0864(v0)
800B171C	jal    func22280 [$80022280]
800B1720	nop
800B1724	lw     a3, $794c(s0)
800B1728	nop
800B172C	lw     a2, $001c(a3)
800B1730	nop
800B1734	lw     v0, $0860(a2)
800B1738	lw     v1, $0864(a2)
800B173C	lw     a0, $087c(a2)

Lb1740:	; 800B1740
800B1740	addu   v0, v0, v1
800B1744	slt    v0, v0, a0
800B1748	beq    v0, zero, Lb17e0 [$800b17e0]
800B174C	lui    a1, $0015
800B1750	lw     v0, $085c(a2)
800B1754	ori    a1, a1, $6f00
800B1758	sw     v0, $08c0(a2)
800B175C	lui    v0, $8006
800B1760	lw     t0, $001c(a3)

funcb1764:	; 800B1764
800B1764	lw     v0, $7944(v0)
800B1768	lw     v1, $085c(t0)
800B176C	lw     a0, $08e4(t0)
800B1770	subu   v1, v1, v0
800B1774	lw     v0, $0000(a0)
800B1778	nop
800B177C	andi   v0, v0, $0004
800B1780	bne    v0, zero, Lb178c [$800b178c]
800B1784	subu   a2, a1, v1
800B1788	addiu  a2, a2, $d000 (=-$3000)

Lb178c:	; 800B178C
800B178C	bgez   a2, Lb1798 [$800b1798]
800B1790	addu   v1, a2, zero
800B1794	addiu  v1, a2, $07ff

Lb1798:	; 800B1798
800B1798	lui    v0, $800d
800B179C	lw     a1, $9d54(v0)
800B17A0	sra    v0, v1, $0b
800B17A4	sll    a2, v0, $0b
800B17A8	lui    v0, $800b
800B17AC	lw     v1, $0860(t0)
800B17B0	lw     a0, $0864(t0)
800B17B4	addiu  v0, v0, $29f8
800B17B8	sw     a2, $0014(sp)
800B17BC	sw     v0, $0018(sp)
800B17C0	addu   v1, v1, a0
800B17C4	sw     v1, $0010(sp)
800B17C8	lw     a2, $0858(t0)
800B17CC	lw     a3, $08c0(t0)
800B17D0	jal    func2177c [$8002177c]
800B17D4	addiu  a0, t0, $0854
800B17D8	j      Lb19dc [$800b19dc]
800B17DC	lui    v0, $8006

Lb17e0:	; 800B17E0
800B17E0	lui    v0, $800d
800B17E4	lbu    v1, $9d52(v0)
800B17E8	addiu  v0, zero, $0007
800B17EC	bne    v1, v0, Lb1820 [$800b1820]
800B17F0	lui    v0, $800d
800B17F4	lb     v1, $9d4c(v0)
800B17F8	addiu  v0, zero, $0009
800B17FC	beq    v1, v0, Lb1808 [$800b1808]
800B1800	addiu  v0, zero, $007f
800B1804	sb     v0, $0826(a2)

Lb1808:	; 800B1808
800B1808	lw     v0, $794c(s0)
800B180C	nop
800B1810	lw     v1, $001c(v0)
800B1814	addiu  v0, zero, $0004
800B1818	j      Lb19d8 [$800b19d8]
800B181C	sb     v0, $0851(v1)

Lb1820:	; 800B1820
800B1820	lw     a0, $001c(a3)
800B1824	addiu  v1, zero, $ffff (=-$1)
800B1828	sb     v1, $9d4c(v0)
800B182C	j      Lb19d8 [$800b19d8]
800B1830	sb     zero, $0851(a0)
800B1834	lui    s1, $8006
800B1838	lw     v0, $794c(s1)
800B183C	nop
800B1840	lw     v1, $001c(v0)
800B1844	nop
800B1848	lw     a3, $0860(v1)
800B184C	lw     v0, $0864(v1)
800B1850	lw     a1, $087c(v1)
800B1854	addu   v0, a3, v0
800B1858	subu   s0, v0, a1
800B185C	blez   s0, Lb1878 [$800b1878]
800B1860	addu   a2, s0, zero
800B1864	subu   a1, a1, a3
800B1868	lw     v0, $08c0(v1)
800B186C	lw     a0, $0814(v1)
800B1870	jal    func15c28 [$80015c28]
800B1874	addu   a1, v0, a1

Lb1878:	; 800B1878
800B1878	lw     a0, $794c(s1)
800B187C	addiu  v0, zero, $6800
800B1880	lw     v1, $001c(a0)
800B1884	subu   a3, v0, s0
800B1888	lw     v0, $0814(v1)
800B188C	addu   a2, a3, zero
800B1890	addu   v0, v0, s0
800B1894	bgez   a3, Lb18a0 [$800b18a0]
800B1898	sw     v0, $08c0(v1)
800B189C	addiu  a2, a3, $07ff

Lb18a0:	; 800B18A0
800B18A0	lui    v0, $800d
800B18A4	sra    v1, a2, $0b
800B18A8	lw     a0, $001c(a0)
800B18AC	lw     a1, $9d54(v0)
800B18B0	lw     v0, $0860(a0)
800B18B4	lw     a2, $0864(a0)
800B18B8	sll    a3, v1, $0b
800B18BC	sw     a3, $0014(sp)
800B18C0	sw     zero, $0018(sp)
800B18C4	addu   v0, v0, a2
800B18C8	sw     v0, $0010(sp)
800B18CC	lw     a2, $0858(a0)
800B18D0	lw     a3, $08c0(a0)
800B18D4	jal    func2177c [$8002177c]
800B18D8	addiu  a0, a0, $0854
800B18DC	lw     v0, $794c(s1)
800B18E0	nop
800B18E4	lw     v1, $001c(v0)
800B18E8	addiu  v0, zero, $0005
800B18EC	j      Lb19d8 [$800b19d8]
800B18F0	sb     v0, $0851(v1)
800B18F4	lui    s0, $8006
800B18F8	lw     v0, $794c(s0)
800B18FC	nop
800B1900	lw     a0, $001c(v0)
800B1904	jal    func217c4 [$800217c4]
800B1908	addiu  a0, a0, $0854
800B190C	bne    v0, zero, Lb19dc [$800b19dc]
800B1910	lui    v0, $8006
800B1914	lw     a3, $794c(s0)
800B1918	nop
800B191C	lw     a2, $001c(a3)
800B1920	nop
800B1924	lw     a0, $0860(a2)
800B1928	lw     v1, $0864(a2)
800B192C	lw     v0, $0858(a2)
800B1930	addu   a0, a0, v1
800B1934	slt    v0, a0, v0
800B1938	beq    v0, zero, Lb1988 [$800b1988]
800B193C	lui    v0, $800d
800B1940	lw     a1, $9d54(v0)
800B1944	lw     v1, $087c(a2)
800B1948	lw     v0, $0814(a2)
800B194C	subu   v1, a0, v1
800B1950	addu   v0, v0, v1
800B1954	sw     v0, $08c0(a2)
800B1958	addiu  v0, zero, $6800
800B195C	lw     a0, $001c(a3)
800B1960	subu   v0, v0, v1
800B1964	sw     v1, $0010(sp)
800B1968	sw     v0, $0014(sp)
800B196C	sw     zero, $0018(sp)
800B1970	lw     a2, $0858(a0)
800B1974	lw     a3, $08c0(a0)
800B1978	jal    func2177c [$8002177c]
800B197C	addiu  a0, a0, $0854
800B1980	j      Lb19dc [$800b19dc]
800B1984	lui    v0, $8006

Lb1988:	; 800B1988
800B1988	lw     a0, $0814(a2)
800B198C	jal    funcb2bc4 [$800b2bc4]
800B1990	nop
800B1994	lw     a1, $794c(s0)
800B1998	nop
800B199C	lw     a0, $001c(a1)
800B19A0	nop
800B19A4	lw     v0, $0000(a0)
800B19A8	lui    v1, $1000
800B19AC	or     v0, v0, v1
800B19B0	sw     v0, $0000(a0)
800B19B4	lw     v0, $001c(a1)
800B19B8	lui    a0, $800d
800B19BC	sb     zero, $0851(v0)
800B19C0	lb     v1, $9d4c(a0)
800B19C4	addiu  v0, zero, $0007
800B19C8	bne    v1, v0, Lb0420 [$800b0420]
800B19CC	lui    s0, $8006
800B19D0	addiu  v0, zero, $ffff (=-$1)
800B19D4	sb     v0, $9d4c(a0)

Lb19d8:	; 800B19D8
800B19D8	lui    v0, $8006

Lb19dc:	; 800B19DC
800B19DC	lw     v0, $794c(v0)

Lb19e0:	; 800B19E0
800B19E0	nop
800B19E4	lw     v0, $001c(v0)
800B19E8	nop
800B19EC	lbu    v0, $0851(v0)

Lb19f0:	; 800B19F0
////////////////////////////////



////////////////////////////////
// funcad944
V1 = A0 & f;
V0 = V1 < 6;
if (V0 != 0)
{
78D90A80 0
90D90A80 1
A0D90A80 2
24DA0A80 4
34DA0A80 5

    800AD978	sra    a0, a1, $08
    800AD97C	andi   a0, a0, $00ff
    800AD980	jal    funcada7c [$800ada7c]
    800AD984	andi   a1, a1, $00ff
    800AD988	j      Lada6c [$800ada6c]
    800AD98C	addu   v0, zero, zero
    800AD990	jal    funcae4f8 [$800ae4f8]
    800AD994	nop
    800AD998	j      Lada6c [$800ada6c]
    800AD99C	addu   v0, zero, zero
    800AD9A0	lui    v1, $800d
    800AD9A4	lhu    v0, $9d44(v1)
    800AD9A8	nop
    800AD9AC	ori    v0, v0, $0001
    800AD9B0	j      Lada68 [$800ada68]
    800AD9B4	sh     v0, $9d44(v1)

    case 3: // B8D90A80
    {
        A0 = w[8007794c];
        V1 = bu[A0 + b];

        if (V1 == ff)
        {
            return 11;
        }

        V0 = w[A0 + 1c];
        V0 = w[V0 + 8e4];
        V0 = w[V0 + c];
        V0 = w[V0 + 14];
        V1 = b[V0 + 42];
        if (V1 == 11)
        {
            return 11;
        }
        else if (V1 == 8)
        {
            return 1;
        }
        else if (V1 < 5)
        {
            return 10
        }
        else
        {
            return 0;
        }
    }
    break;



    800ADA24	jal    func19ab70 [$8019ab70]
    800ADA28	nop
    800ADA2C	j      Lada6c [$800ada6c]
    800ADA30	nop
    800ADA34	lui    v0, $8006
    800ADA38	lw     v0, $794c(v0)
    800ADA3C	nop
    800ADA40	lw     v0, $001c(v0)
    800ADA44	nop
    800ADA48	lw     v0, $08e4(v0)
    800ADA4C	nop
    800ADA50	lw     v0, $000c(v0)
    800ADA54	nop
    800ADA58	lw     v0, $0014(v0)
    800ADA5C	addu   a0, a1, zero
    800ADA60	jal    func19a5b0 [$8019a5b0]
    800ADA64	sb     a0, $0043(v0)
}
Lada68:	; 800ADA68
return 0;

Lada6c:	; 800ADA6C
////////////////////////////////



////////////////////////////////
// funcb2c80
V0 = w[8006794c];
S0 = w[V0 + 1c];

A0 = -1;
func15c58;
V0 = V0 - w[S0 + 8c4];
V0 = V0 < hu[S0 + 842];
////////////////////////////////