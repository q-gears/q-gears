////////////////////////////////
// func1ddbf8
bone_data = A1;
[SP + 28] = w(A0);
[SP + 30] = w(bone_data);
[SP + 38] = w(A2);
[SP + 40] = w(A3);
[SP + 48] = w(0);
T4 = hu[bone_data + a];
S5 = 0;
[SP + 50] = w(T4);
if( T4 != 0 )
{
    S1 = bone_data + 4;

    L1ddc4c:	; 801DDC4C
        A1 = w[S1 + 6c];
        S0 = A1;
        if( A1 != 0 )
        {
            FP = bu[S0 + 2];
            V1 = FP & f;
            if( V1 < 9 )
            {
                V0 = w[801dc000 + V1 * 4];

                801DDC84	jr     v0 



                case 0: // 8CDC1D80
                {
                    if( ( FP & 10 ) == 0 )
                    {
                        A0 = w[S0 + 8];
                        [S1 + 50] = h(hu[A0 + 0]); // X
                        [S0 + 8] = w(A0 + 2);
                    }
                    if( ( FP & 20 ) == 0 )
                    {
                        A0 = w[S0 + 8];
                        [S1 + 52] = h(hu[A0 + 0]); // Y
                        [S0 + 8] = w(A0 + 2);
                    }
                    if( ( FP & 40 ) == 0 )
                    {
                        A0 = w[S0 + 8];
                        [S1 + 54] = h(hu[A0 + 0]); // Z
                        [S0 + 8] = w(A0 + 2);
                    }
                    801DDEB0	j      L1de308 [$801de308]
                }
                break;



                case 1: // F8DC1D80
                {
                    if( ( FP & 10 ) == 0 )
                    {
                        V1 = w[S0 + 8];

                        A0 = b[V1 + 0];
                        if( A0 != -80 )
                        {
                            [S1 + 50] = h(hu[S1 + 50] + A0);
                            [S0 + 8] = w(V1 + 1);
                        }
                        else
                        {
                            [S1 + 50] = h(bu[V1 + 1] | (b[V1 + 2] << 8));
                            [S0 + 8] = w(V1 + 3);
                        }
                    }

                    if( ( FP & 20 ) == 0 )
                    {
                        V1 = w[S0 + 8];

                        A0 = b[V1 + 0];
                        if( A0 != -80 )
                        {
                            [S1 + 52] = h(hu[S1 + 52] + A0);
                            [S0 + 8] = w(V1 + 1);
                        }
                        else
                        {
                            [S1 + 52] = h(bu[V1 + 1] | (b[V1 + 2] << 8));
                            [S0 + 8] = w(V1 + 3);
                        }
                    }

                    if( ( FP & 40 ) == 0 )
                    {
                        V1 = w[S0 + 8];

                        A0 = b[V1 + 0];
                        if( A0 != -80 )
                        {
                            [S1 + 54] = h(hu[S1 + 52] + A0);
                            [S0 + 8] = w(V1 + 1);
                        }
                        else
                        {
                            [S1 + 54] = h(bu[V1 + 1] | (b[V1 + 2] << 8));
                            [S0 + 8] = w(V1 + 3);
                        }
                    }

                    801DDE18	j      L1de308 [$801de308]
                }
                break;



                case 2: // 20DE1D80
                {
                    if( ( FP & 10 ) == 0 )
                    {
                        A0 = w[S0 + 8];
                        [S1 + 50] = h(hu[S1 + 50] + hu[A0 + 0]);
                        [S0 + 8] = w(A0 + 2);
                    }
                    if( ( FP & 20 ) == 0 )
                    {
                        A0 = w[S0 + 8];
                        [S1 + 52] = h(hu[S1 + 52] + hu[A0 + 0]);
                        [S0 + 8] = w(A0 + 2);
                    }
                    if( ( FP & 40 ) == 0 )
                    {
                        A0 = w[S0 + 8];
                        [S1 + 54] = h(hu[S1 + 54] + hu[A0 + 0]);
                        [S0 + 8] = w(A0 + 2);
                    }
                    801DDEB0	j      L1de308 [$801de308]
                }
                break;



                case 3: // B8DE1D80
                {
                    S6 = S0;
                    A0 = h[S0 + 10] + 1;
                    [S1 + 50] = h(hu[S0 + 4] + ((h[S0 + a] * A0) / h[S0 + 12])); // X
                    [S1 + 52] = h(hu[S0 + 6] + ((h[S0 + c] * A0) / h[S0 + 12])); // Y
                    [S1 + 54] = h(hu[S0 + 8] + ((h[S0 + e] * A0) / h[S0 + 12])); // Z
                    801DE154	j      L1de308 [$801de308]
                }
                break;



                case 4: // BCDF1D80
                {
                    801DDFBC	lh     a0, $000a(s0)
                    801DDFC0	lh     v0, $0050(s1)
                    801DDFC4	lh     a1, $0012(s0)
                    801DDFC8	subu   a0, a0, v0
                    801DDFCC	div    a0, a1
                    801DDFF4	mflo   a0
                    801DDFF8	lh     v1, $0052(s1)
                    801DDFFC	lh     v0, $000c(s0)
                    801DE000	nop
                    801DE004	subu   v0, v0, v1
                    801DE008	div    v0, a1
                    801DE030	mflo   a2
                    801DE034	lh     v0, $000e(s0)
                    801DE038	lh     v1, $0054(s1)
                    801DE03C	nop
                    801DE040	subu   v0, v0, v1
                    801DE044	div    v0, a1
                    801DE06C	mflo   v1
                    801DE070	addu   s6, s0, zero
                    801DE074	addu   a3, a0, zero
                    801DE078	sll    a0, a0, $10
                    801DE07C	addu   t0, a2, zero
                    801DE080	bne    a0, zero, L1de0c0 [$801de0c0]
                    801DE084	addu   t1, v1, zero
                    801DE088	sll    v0, a2, $10
                    801DE08C	bne    v0, zero, L1de0c0 [$801de0c0]
                    801DE090	sll    v0, v1, $10
                    801DE094	bne    v0, zero, L1de0c0 [$801de0c0]
                    801DE098	nop
                    801DE09C	lhu    v0, $000a(s0)
                    801DE0A0	sh     a1, $0010(s0)
                    801DE0A4	sh     v0, $0050(s1)
                    801DE0A8	lhu    v0, $000c(s0)
                    801DE0AC	nop
                    801DE0B0	sh     v0, $0052(s1)
                    801DE0B4	lhu    v0, $000e(s0)
                    801DE0B8	j      L1de308 [$801de308]
                    801DE0BC	sh     v0, $0054(s1)

                    L1de0c0:	; 801DE0C0
                    801DE0C0	lhu    v0, $0050(s1)
                    801DE0C4	lhu    v1, $0054(s1)
                    801DE0C8	addu   v0, a3, v0
                    801DE0CC	sh     v0, $0050(s1)
                    801DE0D0	lhu    v0, $0052(s1)
                    801DE0D4	addu   v1, t1, v1
                    801DE0D8	sh     v1, $0054(s1)
                    801DE0DC	addu   v0, t0, v0
                    801DE0E0	sh     v0, $0052(s1)
                    801DE0E8	sh     zero, $0010(s0)
                    801DE0E4	j      L1de308 [$801de308]
                }
                break;



                case 5: // ECE01D80
                {
                    801DE0EC	lhu    v1, $0004(s0)
                    801DE0F0	lhu    v0, $000a(s0)
                    801DE0F4	nop
                    801DE0F8	addu   v1, v1, v0
                    801DE0FC	sh     v1, $0004(s0)
                    801DE100	lhu    v0, $0050(s1)
                    801DE104	nop
                    801DE108	addu   v0, v0, v1
                    801DE10C	sh     v0, $0050(s1)
                    801DE110	lhu    v1, $0006(s0)
                    801DE114	lhu    v0, $000c(s0)
                    801DE118	nop
                    801DE11C	addu   v1, v1, v0
                    801DE120	sh     v1, $0006(s0)
                    801DE124	lhu    v0, $0052(s1)
                    801DE128	nop
                    801DE12C	addu   v0, v0, v1
                    801DE130	sh     v0, $0052(s1)
                    801DE134	lhu    v1, $0008(s0)
                    801DE138	lhu    v0, $000e(s0)
                    801DE13C	nop
                    801DE140	addu   v1, v1, v0
                    801DE144	sh     v1, $0008(s0)
                    801DE148	lhu    v0, $0054(s1)
                    801DE14C	addu   s6, s0, zero
                    801DE150	addu   v0, v0, v1
                    801DE158	sh     v0, $0054(s1)
                    801DE154	j      L1de308 [$801de308]
                }
                break;



                case 7: // 5CE11D80
                case 8: // 5CE11D80
                {
                801DE15C	lh     v1, $000a(s0)
                801DE160	lw     v0, $0058(s1)
                801DE164	nop
                801DE168	subu   s3, v1, v0
                801DE16C	mult   s3, s3
                801DE170	lh     v1, $000c(s0)
                801DE174	lw     v0, $005c(s1)
                801DE178	mflo   a1
                801DE17C	subu   s7, v1, v0
                801DE180	nop
                801DE184	mult   s7, s7
                801DE188	lh     v1, $000e(s0)
                801DE18C	lw     v0, $0060(s1)
                801DE190	mflo   a0
                801DE194	subu   s2, v1, v0
                801DE198	nop
                801DE19C	mult   s2, s2
                801DE1A0	addu   a1, a1, a0
                801DE1A4	mflo   a0
                801DE1AC	addu   a0, a1, a0
                system_square_root;

                801DE1B0	subu   a0, zero, s3
                801DE1B4	subu   a1, zero, s2
                801DE1B8	jal    func4b1d4 [$8004b1d4]
                801DE1BC	addiu  s4, v0, $0001
                801DE1C0	lh     v1, $0052(s1)
                801DE1C4	addu   s6, s0, zero
                801DE1C8	subu   v0, v0, v1
                801DE1CC	andi   a0, v0, $0fff
                801DE1D0	slti   v0, a0, $0800
                801DE1D8	addu   a1, v1, zero
                if( V0 == 0 )
                {
                    A0 = A0 - 1000;
                }

                S0 = h[S0 + 6] + (((S4 + h[S0 + 10]) / h[S0 + 8]) / h[S0 + 4]);
                801DE238	addu   v0, a0, zero
                if( A0 < 0 )
                {
                    V0 = 0 - V0;
                }

                801DE240	slt    v0, v0, s0
                801DE244	bne    v0, zero, L1de258 [$801de258]
                801DE248	addu   v0, a1, a0
                801DE24C	bgez   a0, L1de258 [$801de258]
                801DE250	addu   v0, a1, s0
                801DE254	subu   v0, a1, s0

                L1de258:	; 801DE258
                801DE258	sh     v0, $0052(s1)
                801DE25C	andi   v1, fp, $000f
                801DE260	ori    v0, zero, $0007
                801DE264	bne    v1, v0, L1de2dc [$801de2dc]
                801DE268	mult   s3, s3
                801DE26C	mflo   v0
                801DE270	nop
                801DE274	nop
                801DE278	mult   s2, s2
                801DE27C	mflo   a0
                801DE280	jal    system_square_root [$80048af4]
                801DE284	addu   a0, v0, a0
                801DE288	addu   a0, s7, zero
                801DE28C	jal    func4b1d4 [$8004b1d4]
                801DE290	addu   a1, v0, zero
                801DE294	lh     v1, $0050(s1)
                801DE298	nop
                801DE29C	subu   v0, v0, v1
                801DE2A0	andi   a0, v0, $0fff
                801DE2A4	slti   v0, a0, $0800
                801DE2A8	bne    v0, zero, L1de2b4 [$801de2b4]
                801DE2AC	nop
                801DE2B0	addiu  a0, a0, $f000 (=-$1000)

                L1de2b4:	; 801DE2B4
                801DE2B4	bgez   a0, L1de2c0 [$801de2c0]
                801DE2B8	addu   v0, a0, zero
                801DE2BC	subu   v0, zero, v0

                L1de2c0:	; 801DE2C0
                801DE2C0	slt    v0, v0, s0
                801DE2C4	bne    v0, zero, L1de2d8 [$801de2d8]
                801DE2C8	addu   v0, v1, a0
                801DE2CC	bgez   a0, L1de2d8 [$801de2d8]
                801DE2D0	addu   v0, v1, s0
                801DE2D4	subu   v0, v1, s0

                L1de2d8:	; 801DE2D8
                801DE2D8	sh     v0, $0050(s1)

                L1de2dc:	; 801DE2DC
                801DE2DC	lh     v0, $0010(s6)
                801DE2E0	nop
                801DE2E4	addu   v1, v0, zero
                801DE2E8	slti   v0, v0, $7d00
                801DE2EC	beq    v0, zero, L1de3e4 [$801de3e4]
                801DE2F0	ori    v0, zero, $0001
                801DE2F4	lhu    v0, $0012(s6)
                801DE2F8	nop
                801DE2FC	addu   v0, v1, v0
                801DE300	j      L1de3e4 [$801de3e0]
                801DE304	sh     v0, $0010(s6)
            }

            L1de308:	; 801DE308
            V0 = h[S0 + 10] + 1;
            V1 = h[S0 + 12];
            [S0 + 10] = h(V0);
            V0 = V0 < V1;

            801DE324	bne    v0, zero, L1de3c4 [$801de3c4]
            801DE328	nop
            801DE32C	lbu    v0, $0001(s0)
            801DE330	nop
            if( V0 == 0 )
            {
                V0 = bu[S0 + 3];
                T3 = w[SP + 38];
                if( V0 == T3 )
                {
                    S5 = S5 | 2;
                }

                801DE354	ori    s5, s5, $0200
                801DE358	lw     a0, $0028(sp)
                801DE35C	jal    func1df7a8 [$801df7a8]
                801DE360	addu   a1, s0, zero
                801DE364	j      L1de3e4 [$801de3e0]
                801DE368	sw     zero, $006c(s1)
            }

            801DE36C	lbu    v0, $0003(s0)
            801DE370	lw     t4, $0038(sp)
            801DE374	nop
            801DE37C	andi   v1, fp, $000f
            if( V0 == T4 )
            {
                S5 = S5 | 4;
            }

            801DE384	sltiu  v0, v1, $0003
            801DE388	beq    v0, zero, L1de3a0 [$801de3a0]
            801DE38C	ori    s5, s5, $0400
            801DE390	lw     v0, $0004(s0)
            801DE394	sh     zero, $0010(s0)
            801DE398	j      L1de3e4 [$801de3e0]
            801DE39C	sw     v0, $0008(s0)

            L1de3a0:	; 801DE3A0
            801DE3A0	addiu  v0, zero, $ffff (=-$1)
            801DE3A4	sh     v0, $0010(s0)
            801DE3A8	ori    v0, zero, $0005
            801DE3AC	bne    v1, v0, L1de3e4 [$801de3e4]
            801DE3B0	ori    v0, zero, $0001
            801DE3B4	sh     zero, $000a(s6)
            801DE3B8	sh     zero, $000c(s6)
            801DE3BC	j      L1de3e4 [$801de3e4]
            801DE3C0	sh     zero, $000e(s6)

            L1de3c4:	; 801DE3C4
            V0 = bu[S0 + 3];
            T3 = w[SP + 38];
            if( V0 == T3 )
            {
                S5 = S5 | 1;
            }
            S5 = S5 | 10;

            L1de3e4:	; 801DE3E4
            [S1 + 1] = b(1);
            [S1 + 0] = b(1);
        }



        A1 = w[S1 + 70];
        S0 = A1;
        if( A1 != 0 )
        {
            S2 = bu[S0 + 2];
            V1 = S2 & f;
            if( V1 < 6 )
            {
                V0 = w[801dc028 + V1 * 4];

                801DE424	jr     v0 

            2CE41D80 0

                801DE42C	lw     a0, $0008(s0)
                801DE430	andi   v0, s2, $0010
                801DE434	bne    v0, zero, L1de45c [$801de45c]
                801DE438	andi   v0, s2, $0020
                801DE43C	lh     v0, $0000(a0)
                801DE440	nop
                801DE444	sw     v0, $0058(s1)
                801DE448	lw     v0, $0008(s0)
                801DE44C	addiu  a0, a0, $0002
                801DE450	addiu  v0, v0, $0002

                L1de454:	; 801DE454
                801DE454	sw     v0, $0008(s0)
                801DE458	andi   v0, s2, $0020

                L1de45c:	; 801DE45C
                801DE45C	bne    v0, zero, L1de484 [$801de484]
                801DE460	andi   v0, s2, $0040
                801DE464	lh     v0, $0000(a0)
                801DE468	nop
                801DE46C	sw     v0, $005c(s1)
                801DE470	lw     v0, $0008(s0)
                801DE474	addiu  a0, a0, $0002
                801DE478	addiu  v0, v0, $0002
                801DE47C	sw     v0, $0008(s0)
                801DE480	andi   v0, s2, $0040

                L1de484:	; 801DE484
                801DE484	bne    v0, zero, L1de9f0 [$801de9f0]
                801DE488	nop
                801DE48C	lh     v0, $0000(a0)
                801DE490	nop
                801DE494	sw     v0, $0060(s1)
                801DE498	lw     v0, $0008(s0)
                801DE49C	nop
                801DE4A0	addiu  v0, v0, $0002
                801DE4A4	j      L1de9f0 [$801de9f0]

                L1de4a8:	; 801DE4A8
                801DE4A8	sw     v0, $0008(s0)

            ACE41D80 1

                801DE4AC	andi   v0, s2, $0010
                801DE4B0	bne    v0, zero, L1de510 [$801de510]
                801DE4B4	andi   v0, s2, $0020
                801DE4B8	lw     v1, $0008(s0)
                801DE4BC	nop
                801DE4C0	addiu  v0, v1, $0001
                801DE4C4	sw     v0, $0008(s0)
                801DE4C8	lb     a0, $0000(v1)

                L1de4cc:	; 801DE4CC
                801DE4CC	addiu  v0, zero, $ff80 (=-$80)
                801DE4D0	beq    a0, v0, L1de4e4 [$801de4e4]
                801DE4D4	nop
                801DE4D8	lw     v0, $0058(s1)
                801DE4DC	j      L1de508 [$801de508]
                801DE4E0	addu   v0, a0, v0

                L1de4e4:	; 801DE4E4
                801DE4E4	addiu  v0, v1, $0002
                801DE4E8	sw     v0, $0008(s0)
                801DE4EC	lbu    a0, $0001(v1)
                801DE4F0	addiu  v0, v1, $0003
                801DE4F4	sw     v0, $0008(s0)
                801DE4F8	lb     v0, $0002(v1)
                801DE4FC	nop
                801DE500	sll    v0, v0, $08
                801DE504	or     v0, a0, v0

                L1de508:	; 801DE508
                801DE508	sw     v0, $0058(s1)
                801DE50C	andi   v0, s2, $0020

                L1de510:	; 801DE510
                801DE510	bne    v0, zero, L1de570 [$801de570]
                801DE514	andi   v0, s2, $0040
                801DE518	lw     v1, $0008(s0)
                801DE51C	nop
                801DE520	addiu  v0, v1, $0001
                801DE524	sw     v0, $0008(s0)
                801DE528	lb     a0, $0000(v1)
                801DE52C	addiu  v0, zero, $ff80 (=-$80)
                801DE530	beq    a0, v0, L1de544 [$801de544]
                801DE534	nop
                801DE538	lw     v0, $005c(s1)
                801DE53C	j      L1de568 [$801de568]
                801DE540	addu   v0, a0, v0

                L1de544:	; 801DE544
                801DE544	addiu  v0, v1, $0002
                801DE548	sw     v0, $0008(s0)
                801DE54C	lbu    a0, $0001(v1)
                801DE550	addiu  v0, v1, $0003
                801DE554	sw     v0, $0008(s0)
                801DE558	lb     v0, $0002(v1)
                801DE55C	nop
                801DE560	sll    v0, v0, $08
                801DE564	or     v0, a0, v0

                L1de568:	; 801DE568
                801DE568	sw     v0, $005c(s1)
                801DE56C	andi   v0, s2, $0040

                L1de570:	; 801DE570
                801DE570	bne    v0, zero, L1de9f0 [$801de9f0]
                801DE574	nop
                801DE578	lw     v1, $0008(s0)
                801DE57C	nop
                801DE580	addiu  v0, v1, $0001
                801DE584	sw     v0, $0008(s0)
                801DE588	lb     a0, $0000(v1)
                801DE58C	addiu  v0, zero, $ff80 (=-$80)
                801DE590	beq    a0, v0, L1de5a4 [$801de5a4]
                801DE594	nop
                801DE598	lw     v0, $0060(s1)
                801DE5A0	addu   v0, a0, v0
                801DE9EC	sw     v0, $0060(s1)
                801DE824	j      L1de9f0 [$801de9e8]

                L1de5a4:	; 801DE5A4
                801DE5A4	addiu  v0, v1, $0002
                801DE5A8	sw     v0, $0008(s0)
                801DE5AC	lbu    a0, $0001(v1)
                801DE5B0	addiu  v0, v1, $0003
                801DE5B4	sw     v0, $0008(s0)
                801DE5B8	lb     v0, $0002(v1)
                801DE5BC	nop
                801DE5C0	sll    v0, v0, $08
                801DE5C8	or     v0, a0, v0
                801DE9EC	sw     v0, $0060(s1)
                801DE824	j      L1de9f0 [$801de9e8]

            CCE51D80 2

                801DE5CC	lw     a0, $0008(s0)
                801DE5D0	andi   v0, s2, $0010
                801DE5D4	bne    v0, zero, L1de5fc [$801de5fc]
                801DE5D8	nop
                801DE5DC	lhu    v0, $0000(a0)
                801DE5E0	nop
                801DE5E4	sh     v0, $0010(sp)
                801DE5E8	lw     v0, $0008(s0)
                801DE5EC	addiu  a0, a0, $0002
                801DE5F0	addiu  v0, v0, $0002
                801DE5F4	j      L1de600 [$801de600]
                801DE5F8	sw     v0, $0008(s0)

                L1de5fc:	; 801DE5FC
                801DE5FC	sh     zero, $0010(sp)

                L1de600:	; 801DE600
                801DE600	andi   v0, s2, $0020
                801DE604	bne    v0, zero, L1de62c [$801de62c]
                801DE608	nop
                801DE60C	lhu    v0, $0000(a0)
                801DE610	nop
                801DE614	sh     v0, $0012(sp)
                801DE618	lw     v0, $0008(s0)
                801DE61C	addiu  a0, a0, $0002

                L1de620:	; 801DE620
                801DE620	addiu  v0, v0, $0002
                801DE624	j      L1de630 [$801de630]
                801DE628	sw     v0, $0008(s0)

                L1de62c:	; 801DE62C
                801DE62C	sh     zero, $0012(sp)

                L1de630:	; 801DE630
                801DE630	andi   v0, s2, $0040
                801DE634	bne    v0, zero, L1de65c [$801de65c]
                801DE638	nop
                801DE63C	lhu    v0, $0000(a0)
                801DE640	nop
                801DE644	sh     v0, $0014(sp)
                801DE648	lw     v0, $0008(s0)
                801DE64C	nop
                801DE650	addiu  v0, v0, $0002
                801DE654	j      L1de660 [$801de660]
                801DE658	sw     v0, $0008(s0)

                L1de65c:	; 801DE65C
                801DE65C	sh     zero, $0014(sp)

                L1de660:	; 801DE660
                801DE660	lh     v1, $0010(sp)
                801DE664	lh     v0, $0048(s1)
                801DE668	nop
                801DE66C	mult   v1, v0
                801DE670	lh     v1, $0012(sp)
                801DE674	mflo   v0
                801DE678	sra    v0, v0, $0c
                801DE67C	sh     v0, $0010(sp)
                801DE680	lh     v0, $004a(s1)
                801DE684	nop
                801DE688	mult   v1, v0
                801DE68C	lh     v1, $0014(sp)
                801DE690	mflo   v0
                801DE694	sra    v0, v0, $0c
                801DE698	sh     v0, $0012(sp)
                801DE69C	lh     v0, $004c(s1)
                801DE6A0	nop
                801DE6A4	mult   v1, v0
                801DE6A8	addiu  a1, sp, $0010
                801DE6AC	lw     t4, $0030(sp)
                801DE6B0	addiu  a2, sp, $0018
                801DE6B4	addiu  a0, t4, $002c
                801DE6B8	mflo   v0
                801DE6BC	sra    v0, v0, $0c
                801DE6C0	jal    system_matrix_vector_multiply_GTE [$80049b94]
                801DE6C4	sh     v0, $0014(sp)
                801DE6C8	lw     v0, $0018(sp)
                801DE6CC	lw     t3, $0040(sp)
                801DE6D0	nop
                801DE6D4	mult   t3, v0
                801DE6D8	lw     v1, $0058(s1)
                801DE6DC	mflo   v0
                801DE6E0	sra    v0, v0, $0c
                801DE6E4	addu   v0, v0, v1
                801DE6E8	sw     v0, $0058(s1)
                801DE6EC	lw     v0, $001c(sp)
                801DE6F0	nop
                801DE6F4	mult   t3, v0
                801DE6F8	lw     v1, $005c(s1)
                801DE6FC	mflo   v0
                801DE700	sra    v0, v0, $0c
                801DE704	addu   v0, v0, v1
                801DE708	sw     v0, $005c(s1)
                801DE70C	lw     v0, $0020(sp)
                801DE710	nop
                801DE714	mult   t3, v0
                801DE718	lw     v1, $0060(s1)
                801DE71C	mflo   v0
                801DE724	sra    v0, v0, $0c
                801DE9E8	addu   v0, v0, v1
                801DE9EC	sw     v0, $0060(s1)
                801DE824	j      L1de9f0 [$801de9e8]



                case 3: // 28E71D80
                {
                    S6 = S0;
                    A0 = h[S0 + 10] + 1;
                    [S1 + 58] = w(h[S0 + 4] + (h[S0 + a] * A0) / h[S0 + 12]); // rot x
                    [S1 + 5c] = w(h[S0 + 6] + (h[S0 + c] * A0) / h[S0 + 12]); // rot y
                    [S1 + 60] = w(h[S0 + 8] + (h[S0 + e] * A0) / h[S0 + 12]); // rot z
                }
                break;



                case 4: // 2CE81D80
                {
                    S6 = S0;
                    A0 = (h[S0 + a] - w[S1 + 58]) / h[S0 + 12];
                    A2 = (h[S0 + c] - w[S1 + 5c]) / h[S0 + 12];
                    V1 = (h[S0 + e] - w[S1 + 60]) / h[S0 + 12];

                    if( ( A0 << 10 == 0 ) && ( A2 << 10 == 0 ) && ( V1 << 10 == 0 ) )
                    {
                        [S0 + 10] = h(h[S0 + 12]);
                        [S1 + 58] = w(h[S0 + a]);
                        [S1 + 5c] = w(h[S0 + c]);
                        [S1 + 60] = w(h[S0 + e]);
                    }
                    else
                    {
                        [S0 + 10] = h(0);
                        [S1 + 58] = w(w[S1 + 58] + ((A0 << 10) >> 10));
                        [S1 + 5c] = w(w[S1 + 5c] + ((A2 << 10) >> 10));
                        [S1 + 60] = w(w[S1 + 60] + ((V1 << 10) >> 10));
                    }
                }
                break;



                case 5: // 78E91D80
                {
                    S6 = S0;
                    [S0 + 4] = h(hu[S0 + 4] + hu[S0 + a]);
                    [S0 + 6] = h(hu[S0 + 6] + hu[S0 + c]);
                    [S0 + 8] = h(hu[S0 + 8] + hu[S0 + e]);
                    [S1 + 58] = w(w[S1 + 58] + h[S0 + 4]);
                    [S1 + 5c] = w(w[S1 + 5c] + h[S0 + 6]);
                    [S1 + 60] = w(w[S1 + 60] + h[S0 + 8]);
                }
                break;
            }

            L1de9f0:	; 801DE9F0
            801DE9F0	lhu    v0, $0010(s0)
            801DE9F4	lh     v1, $0012(s0)
            801DE9F8	addiu  v0, v0, $0001
            801DE9FC	sh     v0, $0010(s0)
            801DEA00	sll    v0, v0, $10
            801DEA04	sra    v0, v0, $10
            801DEA08	slt    v0, v0, v1
            801DEA0C	bne    v0, zero, L1deaac [$801deaac]
            801DEA10	nop
            801DEA14	lbu    v0, $0001(s0)
            801DEA18	nop
            801DEA1C	bne    v0, zero, L1dea54 [$801dea54]
            801DEA20	nop
            801DEA24	lbu    v0, $0003(s0)
            801DEA28	lw     t4, $0038(sp)
            801DEA2C	nop
            801DEA30	bne    v0, t4, L1dea3c [$801dea3c]
            801DEA34	nop
            801DEA38	ori    s5, s5, $0002

            L1dea3c:	; 801DEA3C
            801DEA3C	ori    s5, s5, $0200
            801DEA40	lw     a0, $0028(sp)
            801DEA44	jal    func1df7a8 [$801df7a8]
            801DEA48	addu   a1, s0, zero
            801DEA4C	j      L1deac8 [$801deac8]
            801DEA50	sw     zero, $0070(s1)

            L1dea54:	; 801DEA54
            801DEA54	lbu    v0, $0003(s0)
            801DEA58	lw     t3, $0038(sp)
            801DEA5C	nop
            801DEA60	bne    v0, t3, L1dea6c [$801dea6c]
            801DEA64	andi   v1, s2, $000f
            801DEA68	ori    s5, s5, $0004

            L1dea6c:	; 801DEA6C
            801DEA6C	sltiu  v0, v1, $0003
            801DEA70	beq    v0, zero, L1dea88 [$801dea88]
            801DEA74	ori    s5, s5, $0400
            801DEA78	lw     v0, $0004(s0)
            801DEA7C	sh     zero, $0010(s0)
            801DEA80	j      L1deac8 [$801deac8]
            801DEA84	sw     v0, $0008(s0)

            L1dea88:	; 801DEA88
            801DEA88	addiu  v0, zero, $ffff (=-$1)
            801DEA8C	sh     v0, $0010(s0)
            801DEA90	ori    v0, zero, $0005
            801DEA94	bne    v1, v0, L1deacc [$801deacc]
            801DEA98	ori    v0, zero, $0001
            801DEA9C	sh     zero, $000a(s6)
            801DEAA0	sh     zero, $000c(s6)
            801DEAA4	j      L1deacc [$801deacc]

            L1deaa8:	; 801DEAA8
            801DEAA8	sh     zero, $000e(s6)

            L1deaac:	; 801DEAAC
            801DEAAC	lbu    v0, $0003(s0)
            801DEAB0	lw     t4, $0038(sp)
            801DEAB4	nop
            801DEAB8	bne    v0, t4, L1deac4 [$801deac4]
            801DEABC	nop
            801DEAC0	ori    s5, s5, $0001

            L1deac4:	; 801DEAC4
            801DEAC4	ori    s5, s5, $0100

            L1deac8:	; 801DEAC8
            801DEAC8	ori    v0, zero, $0001

            L1deacc:	; 801DEACC
            801DEACC	sb     v0, $0000(s1)
        }

        L1dead0:	; 801DEAD0
        801DEAD0	lw     a1, $0074(s1)
        801DEAD4	nop
        801DEAD8	beq    a1, zero, L1deeb0 [$801deeb0]
        801DEADC	addu   s0, a1, zero
        801DEAE0	lbu    v0, $0002(s0)
        801DEAE4	nop
        801DEAE8	andi   t2, v0, $000f
        801DEAEC	andi   v1, t2, $00ff
        801DEAF0	ori    v0, zero, $0004
        801DEAF4	beq    v1, v0, L1dec2c [$801dec2c]
        801DEAF8	slti   v0, v1, $0005
        801DEAFC	beq    v0, zero, L1deb14 [$801deb14]
        801DEB00	ori    v0, zero, $0003
        801DEB04	beq    v1, v0, L1deb28 [$801deb28]
        801DEB08	nop
        801DEB0C	j      L1dede8 [$801dede8]
        801DEB10	nop

        L1deb14:	; 801DEB14
        801DEB14	ori    v0, zero, $0005
        801DEB18	beq    v1, v0, L1ded7c [$801ded7c]
        801DEB1C	nop
        801DEB20	j      L1dede8 [$801dede8]
        801DEB24	nop

        L1deb28:	; 801DEB28
        801DEB28	lhu    a0, $0010(s0)
        801DEB2C	lh     v0, $000a(s0)
        801DEB30	addiu  a0, a0, $0001
        801DEB34	sll    a0, a0, $10
        801DEB38	sra    a0, a0, $10
        801DEB3C	mult   v0, a0
        801DEB40	mflo   v1
        801DEB44	lh     v0, $0012(s0)
        801DEB48	nop
        801DEB4C	div    v1, v0
        801DEB74	mflo   v1
        801DEB78	lhu    v0, $0004(s0)
        801DEB7C	nop
        801DEB80	addu   v0, v0, v1
        801DEB84	sh     v0, $0048(s1)
        801DEB88	lh     v0, $000c(s0)
        801DEB8C	nop
        801DEB90	mult   v0, a0
        801DEB94	mflo   v1
        801DEB98	lh     v0, $0012(s0)
        801DEB9C	nop
        801DEBA0	div    v1, v0
        801DEBC8	mflo   v1
        801DEBCC	lhu    v0, $0006(s0)
        801DEBD0	nop
        801DEBD4	addu   v0, v0, v1
        801DEBD8	sh     v0, $004a(s1)
        801DEBDC	lh     v0, $000e(s0)
        801DEBE0	nop
        801DEBE4	mult   v0, a0
        801DEBE8	mflo   v1
        801DEBEC	lh     v0, $0012(s0)
        801DEBF0	nop
        801DEBF4	div    v1, v0
        801DEC1C	mflo   v1

        L1dec20:	; 801DEC20
        801DEC20	lhu    v0, $0008(s0)
        801DEC24	j      L1dede0 [$801dede0]
        801DEC28	addu   s6, s0, zero

        L1dec2c:	; 801DEC2C
        801DEC2C	lh     a0, $000a(s0)
        801DEC30	lh     v0, $0004(s0)
        801DEC34	lh     a1, $0012(s0)
        801DEC38	subu   a0, a0, v0
        801DEC3C	div    a0, a1
        801DEC64	mflo   a0
        801DEC68	lh     v1, $0006(s0)
        801DEC6C	lh     v0, $000c(s0)
        801DEC70	nop
        801DEC74	subu   v0, v0, v1
        801DEC78	div    v0, a1
        801DECA0	mflo   a2
        801DECA4	lh     v0, $000e(s0)
        801DECA8	lh     v1, $0008(s0)

        L1decac:	; 801DECAC
        801DECAC	nop
        801DECB0	subu   v0, v0, v1
        801DECB4	div    v0, a1
        801DECDC	mflo   v1
        801DECE0	addu   s6, s0, zero
        801DECE4	addu   a3, a0, zero
        801DECE8	sll    a0, a0, $10
        801DECEC	addu   t0, a2, zero
        801DECF0	bne    a0, zero, L1ded30 [$801ded30]
        801DECF4	addu   t1, v1, zero
        801DECF8	sll    v0, a2, $10
        801DECFC	bne    v0, zero, L1ded30 [$801ded30]
        801DED00	sll    v0, v1, $10
        801DED04	bne    v0, zero, L1ded30 [$801ded30]
        801DED08	nop
        801DED0C	lhu    v0, $000a(s0)
        801DED10	sh     a1, $0010(s0)
        801DED14	sh     v0, $0048(s1)
        801DED18	lhu    v0, $000c(s0)
        801DED1C	nop
        801DED20	sh     v0, $004a(s1)
        801DED24	lhu    v0, $000e(s0)
        801DED28	j      L1dede8 [$801dede8]
        801DED2C	sh     v0, $004c(s1)

        L1ded30:	; 801DED30
        801DED30	lhu    v0, $0004(s6)
        801DED34	lhu    v1, $0006(s6)
        801DED38	addu   v0, a3, v0
        801DED3C	sh     v0, $0004(s6)
        801DED40	lhu    v0, $0008(s6)
        801DED44	addu   v1, t0, v1
        801DED48	sh     v1, $0006(s6)
        801DED4C	lhu    v1, $0004(s6)
        801DED50	addu   v0, t1, v0
        801DED54	sh     v0, $0008(s6)
        801DED58	sh     v1, $0048(s1)
        801DED5C	lhu    v0, $0006(s6)
        801DED60	nop
        801DED64	sh     v0, $004a(s1)
        801DED68	lhu    v0, $0008(s6)
        801DED6C	nop
        801DED70	sh     v0, $004c(s1)
        801DED74	j      L1dede8 [$801dede8]
        801DED78	sh     zero, $0010(s0)

        L1ded7c:	; 801DED7C
        801DED7C	lhu    v1, $0004(s0)
        801DED80	lhu    v0, $000a(s0)
        801DED84	nop
        801DED88	addu   v1, v1, v0
        801DED8C	sh     v1, $0004(s0)
        801DED90	lhu    v0, $0048(s1)
        801DED94	nop
        801DED98	addu   v0, v0, v1
        801DED9C	sh     v0, $0048(s1)
        801DEDA0	lhu    v1, $0006(s0)
        801DEDA4	lhu    v0, $000c(s0)
        801DEDA8	nop
        801DEDAC	addu   v1, v1, v0
        801DEDB0	sh     v1, $0006(s0)
        801DEDB4	lhu    v0, $004a(s1)
        801DEDB8	nop
        801DEDBC	addu   v0, v0, v1
        801DEDC0	sh     v0, $004a(s1)
        801DEDC4	lhu    v1, $0008(s0)
        801DEDC8	lhu    v0, $000e(s0)
        801DEDCC	nop
        801DEDD0	addu   v1, v1, v0
        801DEDD4	sh     v1, $0008(s0)

        L1dedd8:	; 801DEDD8
        801DEDD8	lhu    v0, $004c(s1)
        801DEDDC	addu   s6, s0, zero

        L1dede0:	; 801DEDE0
        801DEDE0	addu   v0, v0, v1
        801DEDE4	sh     v0, $004c(s1)

        L1dede8:	; 801DEDE8
        801DEDE8	lhu    v0, $0010(s0)
        801DEDEC	lh     v1, $0012(s0)
        801DEDF0	addiu  v0, v0, $0001
        801DEDF4	sh     v0, $0010(s0)
        801DEDF8	sll    v0, v0, $10
        801DEDFC	sra    v0, v0, $10
        801DEE00	slt    v0, v0, v1
        801DEE04	bne    v0, zero, L1dee88 [$801dee88]
        801DEE08	nop
        801DEE0C	lbu    v0, $0001(s0)
        801DEE10	nop
        801DEE14	bne    v0, zero, L1dee4c [$801dee4c]
        801DEE18	nop
        801DEE1C	lbu    v0, $0003(s0)
        801DEE20	lw     t3, $0038(sp)
        801DEE24	nop
        801DEE28	bne    v0, t3, L1dee34 [$801dee34]
        801DEE2C	nop
        801DEE30	ori    s5, s5, $0002

        L1dee34:	; 801DEE34
        801DEE34	ori    s5, s5, $0200
        801DEE38	lw     a0, $0028(sp)
        801DEE3C	jal    func1df7a8 [$801df7a8]
        801DEE40	addu   a1, s0, zero
        801DEE44	j      L1deea4 [$801deea4]
        801DEE48	sw     zero, $0074(s1)

        L1dee4c:	; 801DEE4C
        801DEE4C	lbu    v0, $0003(s0)
        801DEE50	lw     t4, $0038(sp)

        L1dee54:	; 801DEE54
        801DEE54	nop

        L1dee58:	; 801DEE58
        801DEE58	bne    v0, t4, L1dee64 [$801dee64]

        L1dee5c:	; 801DEE5C
        801DEE5C	andi   v1, t2, $00ff
        801DEE60	ori    s5, s5, $0004

        L1dee64:	; 801DEE64
        801DEE64	addiu  v0, zero, $ffff (=-$1)
        801DEE68	sh     v0, $0010(s0)
        801DEE6C	ori    v0, zero, $0005
        801DEE70	bne    v1, v0, L1deea4 [$801deea4]
        801DEE74	ori    s5, s5, $0400
        801DEE78	sh     zero, $000a(s6)
        801DEE7C	sh     zero, $000c(s6)
        801DEE80	j      L1deea4 [$801deea4]
        801DEE84	sh     zero, $000e(s6)

        L1dee88:	; 801DEE88
        801DEE88	lbu    v0, $0003(s0)
        801DEE8C	lw     t3, $0038(sp)
        801DEE90	nop
        801DEE94	bne    v0, t3, L1deea0 [$801deea0]
        801DEE98	nop
        801DEE9C	ori    s5, s5, $0001

        L1deea0:	; 801DEEA0
        801DEEA0	ori    s5, s5, $0100

        L1deea4:	; 801DEEA4
        801DEEA4	ori    v0, zero, $0001

        L1deea8:	; 801DEEA8
        801DEEA8	sb     v0, $0001(s1)
        801DEEAC	sb     v0, $0000(s1)

        L1deeb0:	; 801DEEB0
        801DEEB0	addiu  s1, s1, $007c
        801DEEB4	lw     t3, $0030(sp)
        801DEEB8	lw     t4, $0048(sp)
        801DEEBC	addiu  t3, t3, $007c
        801DEEC0	sw     t3, $0030(sp)
        801DEEC4	lw     t3, $0050(sp)
        801DEEC8	addiu  t4, t4, $0001
        801DEED4	sw     t4, $0048(sp)
        801DEECC	sltu   v0, t4, t3
    801DEED0	bne    v0, zero, L1ddc4c [$801ddc4c]
}

return S5;
////////////////////////////////