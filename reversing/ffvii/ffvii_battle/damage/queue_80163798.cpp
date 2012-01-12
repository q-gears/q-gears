////////////////////////////////
// funcb6d6c
A0 = bu[801590e0];
V0 = A0 * c;
V1 = b[80163798 + V0];
if( V1 != -1 )
{
    S4 = 1f800004;
    S3 = 1f800008;
    S1 = -1;
    S5 = 80163798;
    S2 = 1;

    Lb6ddc:	; 800B6DDC
        V1 = b[80163798 + A0 * c + 1];
        switch( V1 )
        {
            case 5:
            {
                index = bu[801590e0];
                unit_id = b[80163798 + index * c + 0];

                [801518e4 + unit_id * b9c + 3e] = b(bu[801518e4 + unit_id * b9c + 3e] | 20);

                [80151200 + unit_id * 74] = w(w[801636b8 + unit_id * 10 + 8]); // unit status

                V1 = w[80151200 + unit_id * 74];
                if( V1 != 00000010 && V1 != 00000020 ) // sadness and fury
                {
                    [801518e4 + unit_id * b9c + 162] = h(hu[801518e4 + unit_id * b9c + 18]); // store rotation
                }

                funcb7fdc;
                [801590e0] = b(bu[801590e0] + 1);
            }
            break;



            case 0:
            {
                A0 = 800c494c;
                800B6F8C	jal    funcbc04c [$800bc04c]

                funcb7fdc;
                [801590e0] = b(bu[801590e0] + 1);
            }
            break;



            case 2: // A46F0B80
            {
                index = bu[801590e0];
                A0 = h[80163798 + index * c + 6]; // string index in buffer + 0x100
                A1 = bu[80163798 + index * c + 5]; // string argument
                A2 = bu[80163798 + index * c + 3]; // 0
                A3 = bu[80163798 + index * c + 2]; // 0
                funcc5c18;

                funcb7fdc;
                [801590e0] = b(bu[801590e0] + 1);
            }
            break;



            case 4: // 14700B80
            {
                if( bu[800f7de4] != 0 )
                {
                    index = bu[801590e0];
                    unit_id = b[80163798 + index * c + 0];

                    [800f7de4] = b(0);

                    [1f800004] = w(b[80163798 + index * c + 5] << 8); // animation action id
                    [1f800008] = w(h[801518ea + unit_id * b9c]);

                    A0 = 800c5694;
                    funcbbeac;
                    data_id = V0;

                    if( w[1f800004] < w[1f800008] )
                    {
                        V0 = w[1f800008] - w[1f800004];
                    }
                    else
                    {
                        V0 = w[1f800004] - w[1f800008];
                    }

                    [8015190a + unit_id * b9c] = b(0);

                    [80162978 + data_id * 20 + 2] = h(V0 / h[80163798 + index * c + 6]);
                    [80162978 + data_id * 20 + 4] = h(hu[80163798 + index * c + 6]);
                    [80162978 + data_id * 20 + 6] = h(unit_id);

                    [80163798 + index * c + 8] = h(-1);
                }

                funcb7fdc;
                if( bu[800f7de4] != 0 )
                {
                    [801590e0] = b(bu[801590e0] + 1);
                }
            }
            break;



            case 3: // 3C720B80
            {
                if( bu[800f7de4] != 0 )
                {
                    [800f7de4] = b(0);

                    800B7258	jal    funcbb684 [$800bb684]
                    800B725C	nop
                    800B7260	lui    v1, $8016
                    800B7264	lbu    v1, $90e0(v1)
                    800B7268	nop
                    800B726C	sll    v0, v1, $01
                    800B7270	addu   v0, v0, v1
                    800B7274	sll    v0, v0, $02
                    800B7278	lui    at, $8016
                    800B727C	addiu  at, at, $37a2
                    800B7280	addu   at, at, v0
                    800B7284	lh     v1, $0000(at)
                    800B7288	nop
                    800B728C	sll    v0, v1, $01
                    800B7290	addu   v0, v0, v1
                    800B7294	sll    v0, v0, $02
                    800B7298	lui    at, $8010
                    800B729C	addiu  at, at, $a9d1 (=-$562f)
                    800B72A0	addu   at, at, v0
                    800B72A4	lbu    v0, $0000(at)
                    800B72A8	nop
                    800B72AC	lui    at, $8016
                    800B72B0	sb     v0, $90cc(at)
                    800B72B4	lui    a0, $8016
                    800B72B8	lbu    a0, $90cc(a0)
                    800B72BC	nop
                    800B72C0	sll    v1, a0, $01
                    800B72C4	addu   v1, v1, a0
                    800B72C8	sll    v0, v1, $05
                    800B72CC	subu   v0, v0, v1
                    800B72D0	sll    v0, v0, $03
                    800B72D4	subu   v0, v0, a0
                    800B72D8	sll    v0, v0, $02
                    [801518e4 + V0 + 26] = b(S2);
                    800B72EC	jal    funcb7764 [$800b7764]
                    800B72F0	nop
                    800B72F4	lui    v1, $8016
                    800B72F8	lbu    v1, $90e0(v1)
                    800B72FC	nop
                    800B7300	sll    v0, v1, $01
                    800B7304	addu   v0, v0, v1
                    800B7308	sll    v0, v0, $02
                    800B730C	lui    at, $8016
                    800B7310	addiu  at, at, $37a2
                    800B7314	addu   at, at, v0
                    800B7318	lh     v1, $0000(at)
                    [800f9774] = b(0);
                    800B7324	sll    v0, v1, $01
                    800B7328	addu   v0, v0, v1
                    800B732C	sll    v0, v0, $02
                    800B7330	lui    at, $8010
                    800B7334	addiu  at, at, $a9d0 (=-$5630)
                    800B7338	addu   at, at, v0
                    800B733C	lb     v0, $0000(at)
                    800B7340	nop
                    800B7344	beq    v0, s1, Lb73c4 [$800b73c4]
                    800B7348	addiu  s0, zero, $ffff (=-$1)

                    loopb734c:	; 800B734C
                    800B734C	jal    funcb79f0 [$800b79f0]
                    800B7350	nop
                    800B7354	lui    v1, $8016
                    800B7358	lbu    v1, $90e0(v1)
                    800B735C	nop
                    800B7360	sll    v0, v1, $01
                    800B7364	addu   v0, v0, v1
                    800B7368	sll    v0, v0, $02
                    800B736C	lui    at, $8016
                    800B7370	addiu  at, at, $37a2
                    800B7374	addu   at, at, v0
                    800B7378	lhu    v1, $0000(at)
                    800B737C	addu   a0, v0, s5
                    800B7380	addiu  v1, v1, $0001
                    800B7384	sh     v1, $000a(a0)
                    800B7388	lui    at, $8016
                    800B738C	addiu  at, at, $37a2
                    800B7390	addu   at, at, v0
                    800B7394	lh     v1, $0000(at)
                    800B7398	nop
                    800B739C	sll    v0, v1, $01
                    800B73A0	addu   v0, v0, v1
                    800B73A4	sll    v0, v0, $02
                    800B73A8	lui    at, $8010
                    800B73AC	addiu  at, at, $a9d0 (=-$5630)
                    800B73B0	addu   at, at, v0
                    800B73B4	lb     v0, $0000(at)
                    800B73B8	nop
                    800B73BC	bne    v0, s0, loopb734c [$800b734c]
                    800B73C0	nop

                    Lb73c4:	; 800B73C4
                    800B73C4	ori    v0, zero, $0001
                    800B73C8	lui    at, $8015
                    800B73CC	sb     v0, $17bc(at)
                    800B73D0	jal    funcb7db4 [$800b7db4]
                    800B73D4	nop
                }

                funcb7fdc;

                if( bu[800f7de4] != 0 )
                {
                    [801590e0] = b(bu[801590e0] + 1);
                }
            }
            break;



            case 1:
            {
                if( bu[800f7de4] != 0 )
                {
                    800B73F4	lui    at, $800f
                    800B73F8	sb     zero, $7de4(at)
                    800B73FC	jal    funcbb684 [$800bb684]
                    800B7400	nop
                    800B7404	lui    v1, $8016
                    800B7408	lbu    v1, $90e0(v1)
                    800B740C	nop
                    800B7410	sll    v0, v1, $01
                    800B7414	addu   v0, v0, v1
                    800B7418	sll    v0, v0, $02
                    800B741C	lui    at, $8016
                    800B7420	addiu  at, at, $3798
                    800B7424	addu   at, at, v0
                    800B7428	lbu    v0, $0000(at)
                    800B742C	nop
                    800B7430	lui    at, $8016
                    800B7434	sb     v0, $90cc(at)
                    800B7438	lui    a0, $8016
                    800B743C	lbu    a0, $90cc(a0)
                    800B7440	nop
                    800B7444	sll    v1, a0, $01
                    800B7448	addu   v1, v1, a0
                    800B744C	sll    v0, v1, $05
                    800B7450	subu   v0, v0, v1
                    800B7454	sll    v0, v0, $03
                    800B7458	subu   v0, v0, a0
                    800B745C	sll    v0, v0, $02
                    800B7460	lui    at, $8015
                    800B7464	addiu  at, at, $1922
                    800B7468	addu   at, at, v0
                    800B746C	lbu    v1, $0000(at)
                    800B7470	nop
                    800B7474	ori    v1, v1, $0001
                    800B7478	lui    at, $8015
                    800B747C	addiu  at, at, $1922
                    800B7480	addu   at, at, v0
                    800B7484	sb     v1, $0000(at)
                    800B7488	lui    a0, $8016
                    800B748C	lbu    a0, $90cc(a0)
                    800B7490	nop
                    800B7494	sll    v1, a0, $01
                    800B7498	addu   v1, v1, a0
                    800B749C	sll    v0, v1, $05
                    800B74A0	subu   v0, v0, v1
                    800B74A4	sll    v0, v0, $03
                    800B74A8	subu   v0, v0, a0
                    800B74AC	sll    v0, v0, $02
                    800B74B0	lui    at, $8015
                    800B74B4	addiu  at, at, $190a
                    800B74B8	addu   at, at, v0
                    800B74BC	sb     zero, $0000(at)
                    funcb7764; // we call this function where we assign action to enemy unit
                    800B74C4	nop
                    800B74C8	lui    a1, $8016
                    800B74CC	lbu    a1, $90e0(a1)
                    800B74D0	nop
                    800B74D4	sll    v0, a1, $01
                    800B74D8	addu   v0, v0, a1
                    800B74DC	sll    v0, v0, $02
                    800B74E0	lui    at, $8016
                    800B74E4	addiu  at, at, $37a2
                    800B74E8	addu   at, at, v0
                    800B74EC	lh     v1, $0000(at)
                    [800f9774] = b(0);
                    800B74F8	j      Lb7690 [$800b7690]

                    Lb7624:	; 800B7624
                    800B7624	lui    at, $8010
                    800B7628	sb     v0, $a6d4(at)
                    800B762C	lui    at, $8016
                    800B7630	sb     v0, $1eec(at)
                    800B7634	lui    at, $8010
                    800B7638	sb     v0, $99e8(at)
                    [801031f0] = b(S2);

                    Lb7644:	; 800B7644
                    800B7644	lui    a1, $8016
                    800B7648	lbu    a1, $90e0(a1)
                    800B764C	nop
                    800B7650	sll    v0, a1, $01
                    800B7654	addu   v0, v0, a1
                    800B7658	sll    v0, v0, $02
                    800B765C	lui    at, $8016
                    800B7660	addiu  at, at, $37a2
                    800B7664	addu   at, at, v0
                    800B7668	lhu    v1, $0000(at)
                    800B766C	addu   a0, v0, s5
                    800B7670	addiu  v1, v1, $0001
                    800B7674	sh     v1, $000a(a0)
                    800B7678	lui    at, $8016
                    800B767C	addiu  at, at, $37a2
                    800B7680	addu   at, at, v0
                    800B7684	lh     v1, $0000(at)
                    800B7688	nop

                    Lb7690:	; 800B7690
                    V0 = b[800fa9d0 + V1 * c + 0];
                    if (V0 != -1)
                    {
                        V1 = h[801537a2 + A1 * c];
                        [800fafe0] = b(bu[800fa9d0 + V1 * c + 1]); // attacker id

                        funcb79f0;

                        V0 = bu[800f9774];

                        800B7558	bne    v0, s2, Lb7624 [$800b7624]
                        800B755C	ori    v0, zero, $000f
                        800B7560	lui    v0, $8016
                        800B7564	lbu    v0, $90e0(v0)
                        800B7568	nop
                        800B756C	sll    a0, v0, $01
                        800B7570	addu   a0, a0, v0
                        800B7574	sll    a0, a0, $02
                        800B7578	lui    at, $8016
                        800B757C	addiu  at, at, $37a2
                        800B7580	addu   at, at, a0
                        800B7584	lh     v1, $0000(at)
                        800B7588	nop
                        800B758C	sll    v0, v1, $01
                        800B7590	addu   v0, v0, v1
                        800B7594	sll    v0, v0, $02
                        V0 = bu[800fa9d0 + V0 + 0];
                        800B75A8	lui    at, $8016
                        800B75AC	addiu  at, at, $37a2
                        800B75B0	addu   at, at, a0
                        800B75B4	lh     v1, $0000(at)
                        800B75B8	lui    at, $8010
                        800B75BC	sb     v0, $a6d4(at)
                        [800f99e8] = b(V0);
                        800B75C8	lui    at, $8016
                        800B75CC	sb     v0, $1eec(at)
                        800B75D0	sll    v0, v1, $01
                        800B75D4	addu   v0, v0, v1
                        800B75D8	sll    a0, v0, $02
                        800B75DC	lui    at, $8010
                        800B75E0	addiu  at, at, $a9d2 (=-$562e)
                        800B75E4	addu   at, at, a0
                        800B75E8	lb     v1, $0000(at)
                        800B75EC	ori    v0, zero, $0009
                        if (V1 == V0)
                        {
                            800B75F8	lui    at, $8010
                            800B75FC	addiu  at, at, $a9d1 (=-$562f)
                            800B7600	addu   at, at, a0
                            800B7604	lbu    v0, $0000(at)
                            800B7608	nop
                            800B760C	lui    at, $8010
                            800B7610	sb     v0, $99e8(at)
                        }

                        [801031f0] = b(0);
                        800B7614	lui    at, $8010
                        800B7618	sb     zero, $31f0(at)
                        800B761C	j      Lb7644 [$800b7644]
                        800B7620	nop
                    }

                    800B76B4	jal    funcb7db4 [$800b7db4]
                }

                [801517bc] = b(0);

                funcb7fdc;

                if( bu[800f7de4] != 0 )
                {
                    [801590e0] = b(bu[801590e0] + 1);
                }
            }
            break;
        }

        A0 = bu[801690e0];
        V0 = b[80163798 + A0 * c + 0];
    800B7724	bne    v0, s1, Lb6ddc [$800b6ddc]
}

[801590e0] = b(0);
funcb7fdc;
////////////////////////////////



////////////////////////////////
// funcc5c18
T1 = 0;
loopc5c40:	; 800C5C40
    if( h[800f9da8 + T1 * 6] == -1 )
    {
        [800f9da8 + T1 * 6] = h(A0); // string index in buffer + 0x100
        [800f9daa + T1 * 6] = h(A3); // 0
        [800f9dac + T1 * 6] = b(A1 + ff); // string argument

        if( A2 == 0 ) // 0
        {
            [800f9dad + T1 * 6] = b(bu[8009d7bd] >> 2 + 4);
        }
        else
        {
            [800f9dad + T1 * 6] = b(A2);
        }

        break;
    }

    T1 = T1 + 1;
    V0 = T1 < 40;
800C5CA4	bne    v0, zero, loopc5c40 [$800c5c40]
////////////////////////////////
