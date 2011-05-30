
800a8c34 : LW      00000000 (v0), 002a (80191036 (s0)) [80191060]
800a9ae0 : LH      0000009d (v0), 0050 (80191034 (s2)) [80191084]
800a9aec : LH      00001000 (v0), 0050 (80191034 (s2)) [80191084]
800a9af8 : LH      00001000 (v0), 0050 (80191034 (s2)) [80191084]
800a9b1c : LHU     ffff9f87 (a3), 002a (80191034 (s2)) [8019105e]
800a9b28 : LHU     1f800360 (v0), 002a (80191034 (s2)) [8019105e]
800a8c8c : LH      00000028 (v0), 0004 (80191036 (s0)) [8019103a]
800a8c34 : LW      00000001 (v0), 002a (80191036 (s0)) [80191060]
800a9ae0 : LH      000000a5 (v0), 0050 (80191034 (s2)) [80191084]
800a9aec : LH      00001000 (v0), 0050 (80191034 (s2)) [80191084]
800a9af8 : LH      00001000 (v0), 0050 (80191034 (s2)) [80191084]
800a9b1c : LHU     ffffa8e7 (a3), 002a (80191034 (s2)) [8019105e]
800a9b28 : LHU     1f800360 (v0), 002a (80191034 (s2)) [8019105e]
800a8c8c : LH      0000002c (v0), 0004 (80191036 (s0)) [8019103a]
800a8c34 : LW      00000001 (v0), 002a (80191036 (s0)) [80191060]
800a9ae0 : LH      000000ad (v0), 0050 (80191034 (s2)) [80191084]
800a9aec : LH      00001000 (v0), 0050 (80191034 (s2)) [80191084]
800a9af8 : LH      00001000 (v0), 0050 (80191034 (s2)) [80191084]
800a9b1c : LHU     ffffb22b (a3), 002a (80191034 (s2)) [8019105e]
800a9b28 : LHU     1f800360 (v0), 002a (80191034 (s2)) [8019105e]
800a8c8c : LH      00000030 (v0), 0004 (80191036 (s0)) [8019103a]
800a8c34 : LW      00000001 (v0), 002a (80191036 (s0)) [80191060]



////////////////////////////////
// funca8b60
800A8B60	lui    v0, $800b
800A8B64	lw     v0, $d00c(v0)
800A8B68	addiu  sp, sp, $ffa0 (=-$60)
800A8B6C	sw     ra, $0058(sp)
800A8B70	sw     s5, $0054(sp)
800A8B74	sw     s4, $0050(sp)
800A8B78	sw     s3, $004c(sp)
800A8B7C	sw     s2, $0048(sp)
800A8B80	sw     s1, $0044(sp)
800A8B84	bne    v0, zero, La8d2c [$800a8d2c]
800A8B88	sw     s0, $0040(sp)
800A8B8C	lui    a1, $800b
800A8B90	addiu  a1, a1, $ef38 (=-$10c8)
800A8B94	lw     v0, $0000(a1)
800A8B98	lw     v1, $0004(a1)
800A8B9C	lw     a0, $0008(a1)
800A8BA0	sw     v0, $0010(sp)
800A8BA4	sw     v1, $0014(sp)
800A8BA8	sw     a0, $0018(sp)
800A8BAC	lw     v0, $000c(a1)
800A8BB0	lw     v1, $0010(a1)
800A8BB4	lw     a0, $0014(a1)
800A8BB8	sw     v0, $001c(sp)
800A8BBC	sw     v1, $0020(sp)
800A8BC0	sw     a0, $0024(sp)
800A8BC4	lw     v0, $0018(a1)
800A8BC8	lw     v1, $001c(a1)
800A8BCC	sw     v0, $0028(sp)
800A8BD0	sw     v1, $002c(sp)
800A8BD4	addu   s5, zero, zero

loopa8bd8:	; 800A8BD8
    800A8BD8	lui    at, $800b
    800A8BDC	addu   at, at, s5
    800A8BE0	lbu    v1, $0984(at)
    800A8BE4	ori    v0, zero, $0001
    800A8BE8	bne    v1, v0, La8cf8 [$800a8cf8]
    800A8BEC	addu   a2, zero, zero
    
    S3 = w[800c2dec + S5 * 4];

    800A8C00	addu   s4, zero, zero
    S0 = S3 + 2;

    loopa8c08:	; 800A8C08
        V1 = h[S0 + 4];

        800A8C10	beq    v1, zero, La8cd4 [$800a8cd4]
        800A8C14	sw     zero, $0030(sp)
        800A8C18	lhu    v0, $0000(s0)
        800A8C1C	nop
        800A8C20	bne    v0, zero, La8cc8 [$800a8cc8]
        800A8C24	nop
        800A8C28	blez   v1, La8ca0 [$800a8ca0]
        800A8C2C	addu   s2, zero, zero


        S1 = 0;
        loopa8c34:	; 800A8C34
            A1 = S1 + w[S0 + 2a];
            if (h[A1] == 0)
            {
                if (hu[S0 + 2] == 0)
                {
                    continue;
                }

                A0 = S3;
                A1 = S1 + w[S0 + 2a];
                A2 = SP + 30;
                800A8C60	jal    funca9b8c [$800a9b8c]
            }

            A0 = S3;
            A1 = S1 + w[S0 + 2a];
            A2 = SP + 10;
            800A8C80	jal    funca93f0 [$800a93f0]

            A2 = 1;
            S1 = S1 + c0;
            S2 = S2 + 1;
            V0 = S2 < h[S0 + 4];
        800A8C98	bne    v0, zero, loopa8c34 [$800a8c34]


        La8ca0:	; 800A8CA0
        800A8CA0	lhu    a0, $0002(s0)
        800A8CA4	nop
        800A8CA8	andi   v1, a0, $ffff
        800A8CAC	beq    v1, zero, La8cd4 [$800a8cd4]
        800A8CB0	ori    v0, zero, $7fff
        800A8CB4	beq    v1, v0, La8cc0 [$800a8cc0]
        800A8CB8	addiu  v0, a0, $ffff (=-$1)
        800A8CBC	sh     v0, $0002(s0)

        La8cc0:	; 800A8CC0
        800A8CC0	j      La8cd4 [$800a8cd4]
        800A8CC4	ori    a2, zero, $0001

        La8cc8:	; 800A8CC8
        800A8CC8	ori    a2, zero, $0001
        800A8CCC	addiu  v0, v0, $ffff (=-$1)
        800A8CD0	sh     v0, $0000(s0)

        La8cd4:	; 800A8CD4
        800A8CD4	addiu  s0, s0, $0078
        800A8CE4	addiu  s3, s3, $0078
        800A8CD8	addiu  s4, s4, $0001

        V0 = S4 < 8;
    800A8CE0	bne    v0, zero, loopa8c08 [$800a8c08]

    if (A2 == 0)
    {
        A0 = S5;
        800A8CF0	jal    funca8784 [$800a8784]
    }

    S5 = S5 + 1;
    V0 = S5 < 40;
800A8D00	bne    v0, zero, loopa8bd8 [$800a8bd8]


800A8D08	lui    v0, $800c
800A8D0C	lw     v0, $1b60(v0)
800A8D10	nop
800A8D14	bne    v0, zero, La8d2c [$800a8d2c]
800A8D18	nop
800A8D1C	lui    a0, $8007
800A8D20	addiu  a0, a0, $f458 (=-$ba8)
800A8D24	0C0A06C6	Æ...
800A8D28	nop

La8d2c:	; 800A8D2C
800A8D2C	lw     ra, $0058(sp)
800A8D30	lw     s5, $0054(sp)
800A8D34	lw     s4, $0050(sp)
800A8D38	lw     s3, $004c(sp)
800A8D3C	lw     s2, $0048(sp)
800A8D40	lw     s1, $0044(sp)
800A8D44	lw     s0, $0040(sp)
800A8D48	addiu  sp, sp, $0060
800A8D4C	jr     ra 
800A8D50	nop
////////////////////////////////



////////////////////////////////
// funca93f0
800A93F0	addiu  sp, sp, $ff28 (=-$d8)
800A93F4	sw     s2, $00c0(sp)
800A93F8	addu   s2, a0, zero
800A93FC	sw     s1, $00bc(sp)
800A9400	addu   s1, a1, zero
800A9404	sw     ra, $00d0(sp)
800A9408	sw     s5, $00cc(sp)
800A940C	sw     s4, $00c8(sp)

La9410:	; 800A9410
800A9410	sw     s3, $00c4(sp)
800A9414	sw     s0, $00b8(sp)
800A9418	lhu    v0, $0002(s1)
800A941C	nop
800A9420	beq    v0, zero, La9a20 [$800a9a20]
800A9424	addu   s0, a2, zero
800A9428	addiu  v0, v0, $ffff (=-$1)
800A942C	sh     v0, $0002(s1)
800A9430	andi   v0, v0, $ffff
800A9434	bne    v0, zero, La9b64 [$800a9b64]
800A9438	nop
800A943C	sw     zero, $004c(sp)
800A9440	sw     zero, $0048(sp)
800A9444	sw     zero, $0044(sp)
800A9448	lhu    v0, $002a(s2)
800A944C	nop
800A9450	srl    v0, v0, $04
800A9454	andi   v1, v0, $0003
800A9458	ori    v0, zero, $0001
800A945C	beq    v1, v0, La9698 [$800a9698]
800A9460	addu   s5, zero, zero
800A9464	slti   v0, v1, $0002
800A9468	beq    v0, zero, La9480 [$800a9480]
800A946C	nop
800A9470	beq    v1, zero, La95b0 [$800a95b0]
800A9474	addiu  s0, sp, $0030
800A9478	j      La9768 [$800a9768]
800A947C	nop

La9480:	; 800A9480
800A9480	ori    v0, zero, $0002
800A9484	beq    v1, v0, La96b8 [$800a96b8]
800A9488	ori    v0, zero, $0003
800A948C	bne    v1, v0, La9768 [$800a9768]
800A9490	addiu  s0, sp, $0030
800A9494	sh     zero, $0028(sp)
800A9498	lh     v1, $0052(s2)
800A949C	nop
800A94A0	sll    v0, v1, $01
800A94A4	addu   v0, v0, v1
800A94A8	sll    v0, v0, $03
800A94AC	subu   v0, v0, v1
800A94B0	lui    v1, $800b
800A94B4	lw     v1, $efe4(v1)
800A94B8	sll    v0, v0, $02
800A94BC	addu   v0, v0, v1
800A94C0	lw     v0, $004c(v0)
800A94C4	addiu  a0, sp, $0028
800A94C8	lhu    v0, $0108(v0)
800A94CC	addiu  a1, sp, $0030
800A94D0	sh     zero, $002c(sp)
800A94D4	jal    func3f5e0 [$8003f5e0]
800A94D8	sh     v0, $002a(sp)
800A94DC	lh     v1, $0052(s2)
800A94E0	lui    a0, $800b
800A94E4	lw     a0, $efe4(a0)
800A94E8	sll    v0, v1, $01
800A94EC	addu   v0, v0, v1
800A94F0	sll    v0, v0, $03
800A94F4	subu   v0, v0, v1
800A94F8	sll    v0, v0, $02
800A94FC	addu   v0, v0, a0
800A9500	lw     v0, $004c(v0)
800A9504	nop
800A9508	lh     v0, $0022(v0)
800A950C	nop
800A9510	sw     v0, $0070(sp)
800A9514	lh     v1, $0052(s2)
800A9518	nop
800A951C	sll    v0, v1, $01
800A9520	addu   v0, v0, v1
800A9524	sll    v0, v0, $03
800A9528	subu   v0, v0, v1
800A952C	sll    v0, v0, $02
800A9530	addu   v0, v0, a0
800A9534	lw     v0, $004c(v0)
800A9538	nop
800A953C	lh     v0, $0026(v0)
800A9540	nop
800A9544	sw     v0, $0074(sp)
800A9548	lh     v1, $0052(s2)
800A954C	nop
800A9550	sll    v0, v1, $01
800A9554	addu   v0, v0, v1
800A9558	sll    v0, v0, $03
800A955C	subu   v0, v0, v1
800A9560	sll    v0, v0, $02
800A9564	addu   v0, v0, a0
800A9568	lw     v0, $004c(v0)
800A956C	nop
800A9570	lh     v0, $002a(v0)
800A9574	nop
800A9578	sw     v0, $0078(sp)
800A957C	lh     v1, $0052(s2)
800A9580	nop
800A9584	sll    v0, v1, $01
800A9588	addu   v0, v0, v1
800A958C	sll    v0, v0, $03
800A9590	subu   v0, v0, v1
800A9594	sll    v0, v0, $02
800A9598	addu   v0, v0, a0
800A959C	lw     v0, $004c(v0)
800A95A0	nop
800A95A4	lhu    v0, $00f4(v0)
800A95A8	j      La9760 [$800a9760]
800A95AC	ori    s5, zero, $0001

La95b0:	; 800A95B0
800A95B0	sh     zero, $0028(sp)
800A95B4	lh     v1, $0052(s2)
800A95B8	nop
800A95BC	sll    v0, v1, $01
800A95C0	addu   v0, v0, v1
800A95C4	sll    v0, v0, $03
800A95C8	subu   v0, v0, v1
800A95CC	lui    v1, $800b
800A95D0	lw     v1, $efe4(v1)
800A95D4	sll    v0, v0, $02
800A95D8	addu   v0, v0, v1
800A95DC	lw     v0, $004c(v0)
800A95E0	addiu  a0, sp, $0028
800A95E4	lhu    v0, $0108(v0)
800A95E8	addiu  a1, sp, $0030
800A95EC	sh     zero, $002c(sp)
800A95F0	jal    func3f5e0 [$8003f5e0]
800A95F4	sh     v0, $002a(sp)
800A95F8	lh     v1, $0052(s2)
800A95FC	lui    a0, $800b
800A9600	lw     a0, $efe4(a0)
800A9604	sll    v0, v1, $01
800A9608	addu   v0, v0, v1
800A960C	sll    v0, v0, $03
800A9610	subu   v0, v0, v1
800A9614	sll    v0, v0, $02
800A9618	addu   v0, v0, a0
800A961C	lw     v0, $004c(v0)
800A9620	nop
800A9624	lh     v0, $0022(v0)
800A9628	nop
800A962C	sw     v0, $0070(sp)
800A9630	lh     v1, $0052(s2)
800A9634	nop
800A9638	sll    v0, v1, $01
800A963C	addu   v0, v0, v1
800A9640	sll    v0, v0, $03
800A9644	subu   v0, v0, v1
800A9648	sll    v0, v0, $02
800A964C	addu   v0, v0, a0
800A9650	lw     v0, $004c(v0)
800A9654	nop
800A9658	lh     v0, $0026(v0)
800A965C	nop
800A9660	sw     v0, $0074(sp)
800A9664	lh     v1, $0052(s2)
800A9668	nop
800A966C	sll    v0, v1, $01
800A9670	addu   v0, v0, v1
800A9674	sll    v0, v0, $03
800A9678	subu   v0, v0, v1
800A967C	sll    v0, v0, $02
800A9680	addu   v0, v0, a0
800A9684	lw     v0, $004c(v0)
800A9688	nop
800A968C	lh     v0, $002a(v0)
800A9690	j      La975c [$800a975c]
800A9694	sw     v0, $0078(sp)

La9698:	; 800A9698
800A9698	addiu  s0, sp, $0030
800A969C	addu   a0, s0, zero
800A96A0	lh     a2, $0072(s2)
800A96A4	lh     a3, $0074(s2)
800A96A8	jal    func1e72cc [$801e72cc]
800A96AC	addiu  a1, sp, $0050
800A96B0	j      La9724 [$800a9724]
800A96B4	addu   a0, s0, zero

La96b8:	; 800A96B8
800A96B8	addiu  s0, sp, $0030
800A96BC	lh     v1, $0052(s2)
800A96C0	addu   a0, s0, zero
800A96C4	sll    v0, v1, $01
800A96C8	addu   v0, v0, v1
800A96CC	sll    v0, v0, $03
800A96D0	subu   v0, v0, v1
800A96D4	lui    v1, $800b
800A96D8	lw     v1, $efe4(v1)
800A96DC	sll    v0, v0, $02
800A96E0	addu   v0, v0, v1
800A96E4	lw     v1, $002c(v0)
800A96E8	lw     a1, $0030(v0)
800A96EC	lw     a2, $0034(v0)
800A96F0	lw     a3, $0038(v0)
800A96F4	sw     v1, $0030(sp)
800A96F8	sw     a1, $0034(sp)
800A96FC	sw     a2, $0038(sp)
800A9700	sw     a3, $003c(sp)
800A9704	lw     v1, $003c(v0)
800A9708	lw     a1, $0040(v0)
800A970C	lw     a2, $0044(v0)
800A9710	lw     a3, $0048(v0)
800A9714	sw     v1, $0040(sp)
800A9718	sw     a1, $0044(sp)
800A971C	sw     a2, $0048(sp)
800A9720	sw     a3, $004c(sp)

La9724:	; 800A9724
800A9724	jal    func49da4 [$80049da4]
800A9728	nop
800A972C	jal    func49e34 [$80049e34]
800A9730	addu   a0, s0, zero
800A9734	lhu    v0, $000c(s2)
800A9738	addiu  a0, sp, $0028
800A973C	sh     v0, $0028(sp)
800A9740	lhu    v0, $000e(s2)
800A9744	addiu  a1, sp, $0070
800A9748	sh     v0, $002a(sp)
800A974C	lhu    v0, $0010(s2)
800A9750	addiu  a2, sp, $00b0
800A9754	jal    func4a584 [$8004a584]
800A9758	sh     v0, $002c(sp)

La975c:	; 800A975C
800A975C	ori    v0, zero, $1000

La9760:	; 800A9760
800A9760	sh     v0, $0050(s2)
800A9764	addiu  s0, sp, $0030

La9768:	; 800A9768
800A9768	addu   a0, s0, zero
800A976C	sw     zero, $004c(sp)
800A9770	sw     zero, $0048(sp)
800A9774	jal    func49da4 [$80049da4]
800A9778	sw     zero, $0044(sp)
800A977C	jal    func49e34 [$80049e34]
800A9780	addu   a0, s0, zero
800A9784	lw     v0, $0018(s1)
800A9788	addiu  s3, sp, $0028
800A978C	sh     v0, $0028(sp)
800A9790	lw     v0, $001c(s1)
800A9794	addu   a0, s3, zero
800A9798	sh     v0, $002a(sp)
800A979C	lw     v0, $0020(s1)
800A97A0	addiu  a1, sp, $0018
800A97A4	jal    func49484 [$80049484]
800A97A8	sh     v0, $002c(sp)
800A97AC	addiu  a0, sp, $0018
800A97B0	jal    system_normalize_word_vector_T0_T1_T2_to_word [$80048c24]
800A97B4	addiu  a1, s1, $0018
800A97B8	lw     v1, $0018(s1)
800A97BC	lw     v0, $0008(s2)
800A97C0	nop
800A97C4	mult   v1, v0
800A97C8	mflo   t0
800A97CC	lh     v1, $0024(s2)
800A97D0	sra    v0, t0, $0c
800A97D4	mult   v0, v1
800A97D8	lw     v1, $001c(s1)
800A97DC	mflo   t0
800A97E0	sw     t0, $0018(s1)
800A97E4	lw     v0, $0008(s2)
800A97E8	nop
800A97EC	mult   v1, v0
800A97F0	mflo   t0
800A97F4	lh     v1, $0024(s2)
800A97F8	sra    v0, t0, $0c
800A97FC	mult   v0, v1
800A9800	lw     v1, $0020(s1)
800A9804	mflo   t0
800A9808	sw     t0, $001c(s1)
800A980C	lw     v0, $0008(s2)
800A9810	nop
800A9814	mult   v1, v0
800A9818	mflo   t0
800A981C	lh     v1, $0024(s2)
800A9820	sra    v0, t0, $0c
800A9824	mult   v0, v1
800A9828	ori    s4, zero, $0001
800A982C	mflo   t0
800A9830	bne    s5, s4, La988c [$800a988c]
800A9834	sw     t0, $0020(s1)
800A9838	lh     v1, $0050(s2)
800A983C	lw     v0, $0008(s1)
800A9840	nop
800A9844	mult   v0, v1
800A9848	mflo   t0
800A984C	sra    v0, t0, $0c
800A9850	sw     v0, $0008(s1)
800A9854	lh     v1, $0050(s2)
800A9858	lw     v0, $000c(s1)
800A985C	nop
800A9860	mult   v0, v1
800A9864	mflo   t0
800A9868	sra    v0, t0, $0c
800A986C	sw     v0, $000c(s1)
800A9870	lh     v1, $0050(s2)
800A9874	lw     v0, $0010(s1)
800A9878	nop
800A987C	mult   v0, v1
800A9880	mflo   t0
800A9884	sra    v0, t0, $0c
800A9888	sw     v0, $0010(s1)

La988c:	; 800A988C
800A988C	jal    func49da4 [$80049da4]
800A9890	addu   a0, s0, zero
800A9894	jal    func49e34 [$80049e34]
800A9898	addu   a0, s0, zero
800A989C	lw     v0, $0008(s1)
800A98A0	addu   a0, s3, zero
800A98A4	sh     v0, $0028(sp)
800A98A8	lw     v0, $000c(s1)
800A98AC	addiu  a1, sp, $0018
800A98B0	sh     v0, $002a(sp)
800A98B4	lw     v0, $0010(s1)
800A98B8	addiu  a2, sp, $00b0
800A98BC	jal    func4a584 [$8004a584]
800A98C0	sh     v0, $002c(sp)
800A98C4	bne    s5, s4, La99d4 [$800a99d4]
800A98C8	addu   a0, s3, zero
800A98CC	addiu  s0, sp, $0050
800A98D0	lui    v0, $800b
800A98D4	lw     v0, $f588(v0)
800A98D8	lui    v1, $800b
800A98DC	lhu    v1, $ee62(v1)
800A98E0	addu   a1, s0, zero
800A98E4	sh     zero, $002c(sp)
800A98E8	addiu  v0, v0, $fc00 (=-$400)
800A98EC	subu   v1, zero, v1
800A98F0	sh     v0, $0028(sp)
800A98F4	jal    func4aa64 [$8004aa64]
800A98F8	sh     v1, $002a(sp)
800A98FC	jal    func49da4 [$80049da4]
800A9900	addu   a0, s0, zero
800A9904	jal    func49e34 [$80049e34]
800A9908	addu   a0, s0, zero
800A990C	addiu  a0, sp, $0080
800A9910	lw     v0, $001c(sp)
800A9914	addiu  a1, sp, $0090
800A9918	sw     zero, $0080(sp)
800A991C	sw     zero, $0088(sp)
800A9920	jal    func49834 [$80049834]
800A9924	sw     v0, $0084(sp)
800A9928	lw     a0, $0018(sp)
800A992C	lw     v0, $0090(sp)
800A9930	lw     v1, $0098(sp)
800A9934	lw     a1, $0094(sp)
800A9938	addu   a0, a0, v0
800A993C	lw     v0, $0020(sp)
800A9940	sw     a0, $0018(sp)
800A9944	sw     a1, $001c(sp)
800A9948	addu   v0, v0, v1
800A994C	sw     v0, $0020(sp)
800A9950	lh     v1, $0050(s2)
800A9954	lui    a1, $0100
800A9958	div    a1, v1
800A995C	mflo   v1
800A9960	lw     v0, $0070(sp)
800A9964	nop
800A9968	addu   v0, v0, a0
800A996C	mult   v0, v1
800A9970	mflo   t0
800A9974	sw     t0, $0008(s1)
800A9978	lh     v1, $0050(s2)
800A997C	nop
800A9980	div    a1, v1
800A9984	mflo   v1
800A9988	lw     a0, $001c(sp)
800A998C	lw     v0, $0074(sp)
800A9990	nop
800A9994	addu   v0, v0, a0
800A9998	mult   v0, v1
800A999C	mflo   t0
800A99A0	sw     t0, $000c(s1)
800A99A4	lh     v0, $0050(s2)
800A99A8	nop
800A99AC	div    a1, v0
800A99B0	mflo   a1
800A99B4	lw     v1, $0020(sp)
800A99B8	lw     v0, $0078(sp)
800A99BC	nop
800A99C0	addu   v0, v0, v1
800A99C4	mult   v0, a1
800A99C8	mflo   t0
800A99CC	j      La9b64 [$800a9b64]
800A99D0	sw     t0, $0010(s1)

La99d4:	; 800A99D4
800A99D4	lw     v0, $0070(sp)
800A99D8	lw     v1, $0018(sp)
800A99DC	nop
800A99E0	addu   v0, v0, v1
800A99E4	sll    v0, v0, $0c
800A99E8	sw     v0, $0008(s1)
800A99EC	lw     v0, $0074(sp)
800A99F0	lw     v1, $001c(sp)
800A99F4	nop
800A99F8	addu   v0, v0, v1
800A99FC	sll    v0, v0, $0c
800A9A00	sw     v0, $000c(s1)
800A9A04	lw     v0, $0078(sp)
800A9A08	lw     v1, $0020(sp)
800A9A0C	nop
800A9A10	addu   v0, v0, v1
800A9A14	sll    v0, v0, $0c
800A9A18	j      La9b64 [$800a9b64]
800A9A1C	sw     v0, $0010(s1)

La9a20:	; 800A9A20
800A9A20	lbu    a0, $0048(s1)
800A9A24	lw     v0, $0018(s1)
800A9A28	lw     v1, $0028(s1)
800A9A2C	lb     a1, $004c(s1)
800A9A30	lw     a2, $002c(s1)
800A9A34	lw     a3, $0030(s1)
800A9A38	addu   v0, v0, v1
800A9A3C	sw     v0, $0018(s1)
800A9A40	lw     v0, $001c(s1)
800A9A44	lw     v1, $0020(s1)
800A9A48	addu   v0, v0, a2
800A9A4C	sw     v0, $001c(s1)
800A9A50	lhu    v0, $0038(s1)
800A9A54	addu   v1, v1, a3
800A9A58	sw     v1, $0020(s1)
800A9A5C	lhu    v1, $003a(s1)
800A9A60	lhu    a3, $0042(s1)
800A9A64	lhu    a2, $0040(s1)
800A9A68	addu   v1, v1, a3
800A9A6C	sh     v1, $003a(s1)
800A9A70	lw     v1, $0008(s1)
800A9A74	addu   v0, v0, a2
800A9A78	sh     v0, $0038(s1)
800A9A7C	lhu    v0, $003c(s1)
800A9A80	lhu    a2, $0044(s1)
800A9A84	lw     a3, $0018(s1)
800A9A88	addu   v0, v0, a2
800A9A8C	sh     v0, $003c(s1)
800A9A90	lw     v0, $000c(s1)
800A9A94	lw     a2, $001c(s1)
800A9A98	addu   v1, v1, a3
800A9A9C	sw     v1, $0008(s1)
800A9AA0	lw     v1, $0010(s1)
800A9AA4	lw     a3, $0020(s1)
800A9AA8	addu   v0, v0, a2
800A9AAC	addu   v1, v1, a3
800A9AB0	sw     v0, $000c(s1)
800A9AB4	jal    funca8ff4 [$800a8ff4]
800A9AB8	sw     v1, $0010(s1)
800A9ABC	lbu    a0, $0049(s1)
800A9AC0	lb     a1, $004d(s1)
800A9AC4	jal    funca8ff4 [$800a8ff4]
800A9AC8	sb     v0, $0048(s1)
800A9ACC	lbu    a0, $004a(s1)
800A9AD0	lb     a1, $004e(s1)
800A9AD4	jal    funca8ff4 [$800a8ff4]
800A9AD8	sb     v0, $0049(s1)
800A9ADC	sb     v0, $004a(s1)
800A9AE0	lh     v0, $0050(s2)
800A9AE4	nop
800A9AE8	sw     v0, $00a0(sp)
800A9AEC	lh     v0, $0050(s2)
800A9AF0	nop
800A9AF4	sw     v0, $00a4(sp)
800A9AF8	lh     v0, $0050(s2)
800A9AFC	nop
800A9B00	sw     v0, $00a8(sp)
800A9B04	lhu    v1, $0004(s1)
800A9B08	ori    v0, zero, $0001
800A9B0C	beq    v1, v0, La9b44 [$800a9b44]
800A9B10	addu   a0, s1, zero
800A9B14	addu   a1, s0, zero
800A9B18	lh     a2, $0006(s1)
800A9B1C	lhu    a3, $002a(s2)
800A9B20	addiu  v0, sp, $00a0
800A9B24	sw     v0, $0010(sp)
800A9B28	lhu    v0, $002a(s2)
800A9B2C	srl    a3, a3, $01
800A9B30	andi   a3, a3, $0003
800A9B34	srl    v0, v0, $04
800A9B38	andi   v0, v0, $0003
800A9B3C	jal    funca902c [$800a902c]
800A9B40	sw     v0, $0014(sp)

La9b44:	; 800A9B44
800A9B44	lhu    v0, $0004(s1)
800A9B48	nop
800A9B4C	addiu  v0, v0, $ffff (=-$1)
800A9B50	sh     v0, $0004(s1)
800A9B54	andi   v0, v0, $ffff
800A9B58	bne    v0, zero, La9b64 [$800a9b64]
800A9B5C	nop
800A9B60	sh     zero, $0000(s1)

La9b64:	; 800A9B64
800A9B64	lw     ra, $00d0(sp)
800A9B68	lw     s5, $00cc(sp)
800A9B6C	lw     s4, $00c8(sp)
800A9B70	lw     s3, $00c4(sp)
800A9B74	lw     s2, $00c0(sp)
800A9B78	lw     s1, $00bc(sp)
800A9B7C	lw     s0, $00b8(sp)
800A9B80	addiu  sp, sp, $00d8
800A9B84	jr     ra 
800A9B88	nop
////////////////////////////////



////////////////////////////////
// funca9b8c
800A9B8C	addiu  sp, sp, $ffa8 (=-$58)
800A9B90	sw     s0, $0040(sp)
800A9B94	addu   s0, a0, zero
800A9B98	sw     s1, $0044(sp)
800A9B9C	addu   s1, a1, zero
800A9BA0	ori    v0, zero, $0001
800A9BA4	sw     ra, $0050(sp)
800A9BA8	sw     s3, $004c(sp)
800A9BAC	sw     s2, $0048(sp)
800A9BB0	sh     v0, $0000(s1)
800A9BB4	lw     v1, $0000(a2)
800A9BB8	lhu    v0, $0056(s0)
800A9BBC	nop
800A9BC0	addu   v0, v0, v1
800A9BC4	sh     v0, $0002(s1)
800A9BC8	lhu    v1, $0056(s0)
800A9BCC	lw     v0, $0000(a2)
800A9BD0	nop
800A9BD4	addu   v0, v0, v1
800A9BD8	sw     v0, $0000(a2)
800A9BDC	lhu    v0, $0058(s0)
800A9BE0	nop
800A9BE4	sh     v0, $0004(s1)
800A9BE8	lhu    v0, $002a(s0)
800A9BEC	nop
800A9BF0	andi   v0, v0, $0001
800A9BF4	beq    v0, zero, La9c0c [$800a9c0c]
800A9BF8	nop
800A9BFC	jal    system_get_random_2_bytes [$8003f8b0]
800A9C00	nop
800A9C04	j      La9c10 [$800a9c10]
800A9C08	andi   v0, v0, $0fff

La9c0c:	; 800A9C0C
800A9C0C	lhu    v0, $0076(s0)

La9c10:	; 800A9C10
800A9C10	nop
800A9C14	sh     v0, $0006(s1)
800A9C18	lhu    v0, $002a(s0)
800A9C1C	nop
800A9C20	andi   v0, v0, $0080
800A9C24	bne    v0, zero, La9c40 [$800a9c40]
800A9C28	nop
800A9C2C	lhu    a0, $0026(s0)
800A9C30	jal    funca8d54 [$800a8d54]
800A9C34	nop
800A9C38	j      La9c44 [$800a9c44]
800A9C3C	addu   s2, v0, zero

La9c40:	; 800A9C40
800A9C40	lhu    s2, $0026(s0)

La9c44:	; 800A9C44
800A9C44	jal    funca8d54 [$800a8d54]
800A9C48	ori    a0, zero, $0fff
800A9C4C	addu   s3, v0, zero
800A9C50	jal    func3f774 [$8003f774]
800A9C54	addu   a0, s3, zero
800A9C58	mult   v0, s2
800A9C5C	mflo   a3
800A9C60	sra    v0, a3, $0c
800A9C64	sw     v0, $0020(sp)
800A9C68	lhu    v0, $002a(s0)
800A9C6C	nop
800A9C70	andi   v0, v0, $0040
800A9C74	bne    v0, zero, La9c98 [$800a9c98]
800A9C78	nop
800A9C7C	jal    func3f758 [$8003f758]
800A9C80	addu   a0, s3, zero
800A9C84	mult   v0, s2
800A9C88	mflo   a3
800A9C8C	sra    v0, a3, $0c
800A9C90	j      La9c9c [$800a9c9c]
800A9C94	sw     v0, $0028(sp)

La9c98:	; 800A9C98
800A9C98	sw     zero, $0028(sp)

La9c9c:	; 800A9C9C
800A9C9C	lh     v1, $0052(s0)
800A9CA0	nop
800A9CA4	sll    v0, v1, $01
800A9CA8	addu   v0, v0, v1
800A9CAC	sll    v0, v0, $03
800A9CB0	subu   v0, v0, v1
800A9CB4	lui    v1, $800b
800A9CB8	lw     v1, $efe4(v1)
800A9CBC	sll    v0, v0, $02
800A9CC0	addu   v0, v0, v1
800A9CC4	lw     v1, $004c(v0)
800A9CC8	lui    v0, $800b
800A9CCC	lh     v0, $ee62(v0)
800A9CD0	lh     v1, $0108(v1)
800A9CD4	nop
800A9CD8	addu   v0, v0, v1
800A9CDC	andi   v0, v0, $0fff
800A9CE0	srl    v0, v0, $09
800A9CE4	lui    at, $800b
800A9CE8	addu   at, at, v0
800A9CEC	lbu    a0, $e948(at)
800A9CF0	lh     v0, $000c(s0)
800A9CF4	sll    a0, a0, $02
800A9CF8	addu   a0, s0, a0
800A9CFC	lh     v1, $0030(a0)
800A9D00	lw     a1, $0020(sp)
800A9D04	addu   v0, v0, v1
800A9D08	addu   a1, a1, v0
800A9D0C	sw     a1, $0020(sp)
800A9D10	lh     v1, $0010(s0)
800A9D14	lh     a0, $0032(a0)
800A9D18	lw     v0, $0028(sp)
800A9D1C	addu   v1, v1, a0
800A9D20	addu   v0, v0, v1
800A9D24	sw     v0, $0028(sp)
800A9D28	lh     v0, $000e(s0)
800A9D2C	nop
800A9D30	sw     v0, $0024(sp)
800A9D34	sw     a1, $0008(s1)
800A9D38	lw     v0, $0028(sp)
800A9D3C	nop
800A9D40	sw     v0, $0010(s1)
800A9D44	lw     v0, $0024(sp)
800A9D48	nop
800A9D4C	sw     v0, $000c(s1)
800A9D50	lhu    a0, $0028(s0)
800A9D54	jal    funca8d54 [$800a8d54]
800A9D58	nop
800A9D5C	addu   s2, v0, zero
800A9D60	jal    func3f774 [$8003f774]
800A9D64	addu   a0, s3, zero
800A9D68	mult   v0, s2
800A9D6C	addu   a0, s3, zero
800A9D70	lh     v0, $0014(s0)
800A9D74	mflo   a3
800A9D78	sra    v1, a3, $0c
800A9D7C	addu   v0, v0, v1
800A9D80	jal    func3f758 [$8003f758]
800A9D84	sw     v0, $0030(sp)
800A9D88	mult   v0, s2
800A9D8C	lh     v0, $0018(s0)
800A9D90	mflo   a3
800A9D94	sra    v1, a3, $0c
800A9D98	addu   v0, v0, v1
800A9D9C	sw     v0, $0038(sp)
800A9DA0	lw     v0, $0030(sp)
800A9DA4	lw     v1, $0020(sp)
800A9DA8	lh     a0, $0016(s0)
800A9DAC	subu   v0, v0, v1
800A9DB0	sw     a0, $0034(sp)
800A9DB4	sw     v0, $0018(s1)
800A9DB8	lw     v0, $0034(sp)
800A9DBC	lw     v1, $0024(sp)
800A9DC0	nop
800A9DC4	subu   v0, v0, v1
800A9DC8	sw     v0, $001c(s1)
800A9DCC	lw     v0, $0038(sp)
800A9DD0	lw     v1, $0028(sp)
800A9DD4	nop
800A9DD8	subu   v0, v0, v1
800A9DDC	sw     v0, $0020(s1)
800A9DE0	lh     v0, $001c(s0)
800A9DE4	nop
800A9DE8	sw     v0, $0028(s1)
800A9DEC	lh     v0, $001e(s0)
800A9DF0	nop
800A9DF4	sw     v0, $002c(s1)
800A9DF8	lh     v0, $0020(s0)
800A9DFC	nop
800A9E00	sw     v0, $0030(s1)
800A9E04	lhu    v0, $005a(s0)
800A9E08	nop
800A9E0C	sh     v0, $0038(s1)
800A9E10	lhu    v0, $005c(s0)
800A9E14	nop
800A9E18	sh     v0, $003a(s1)
800A9E1C	lhu    v0, $005e(s0)
800A9E20	nop
800A9E24	sh     v0, $003c(s1)
800A9E28	lhu    v0, $0062(s0)
800A9E2C	nop
800A9E30	sh     v0, $0040(s1)
800A9E34	lhu    v0, $0064(s0)
800A9E38	nop
800A9E3C	sh     v0, $0042(s1)
800A9E40	lhu    v0, $0066(s0)
800A9E44	nop
800A9E48	sh     v0, $0044(s1)
800A9E4C	lbu    v0, $006a(s0)
800A9E50	nop
800A9E54	sb     v0, $0048(s1)
800A9E58	lbu    v0, $006b(s0)
800A9E5C	nop
800A9E60	sb     v0, $0049(s1)
800A9E64	lbu    v0, $006c(s0)
800A9E68	nop
800A9E6C	sb     v0, $004a(s1)
800A9E70	lbu    v0, $006e(s0)
800A9E74	nop
800A9E78	sb     v0, $004c(s1)
800A9E7C	lbu    v0, $006f(s0)
800A9E80	nop
800A9E84	sb     v0, $004d(s1)
800A9E88	lbu    v0, $0070(s0)
800A9E8C	nop
800A9E90	sb     v0, $004e(s1)
800A9E94	lw     ra, $0050(sp)
800A9E98	lw     s3, $004c(sp)
800A9E9C	lw     s2, $0048(sp)
800A9EA0	lw     s1, $0044(sp)
800A9EA4	lw     s0, $0040(sp)
800A9EA8	addiu  sp, sp, $0058
800A9EAC	jr     ra 
800A9EB0	nop
////////////////////////////////