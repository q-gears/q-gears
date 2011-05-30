//////////////////////////////////////////////////////
// formula function called from here
// funcabb0c
address = w[80063014];

S3 = A0; // attacker id
S0 = A1; // target id
funca2fd0;
S1 = V0;

[S1 + 0] = b(S0);
[S1 + 1] = b(S3);
[S1 + 4] = h(0);



[800f83e0 + S0 * 68 + 17] = b(ff);

// cover apply. this can change target.
A0 = S1;
funcaa950;



A0 = b[S1 + 0];
funcac73c;



if (b[S1 + 0] != S0) // if target changed
{
    funca3240;

    [address + 218] = w(w[address + 218] | 00000020);
}

S0 = w[address + 208];



funcae82c; // get status and element immunities to current attack



funcab308; // do some modification acording to this attack immunities/weakness



// if this is heal attack
V0 = w[address + 44];
if (V0 & 0200)
{
    [address + 220] = w(w[address + 220] | 0001);
}

V0 = w[address + 6c] & 0001; // damage to mp
if (V0 == 0)
{
    [address + 220] = w(w[address + 220] | 0004);
}

if (w[800f83e0 + S0 * 68 + 4] & 00004000) // if undamagable
{
    [address + 218] = w(w[address + 218] | 00000001);
}

// if not automiss
if ((w[address + 218] & 00000001) == 0)
{
    // formula run
    funcad4ec;
}



A0 = 3;
funca8e84;



V0 = w[address + 48];
if(V0 == 0)
{
    [address + 218] = w(w[address + 218] | 0002);
}



A0 = S0;
funcacd88;
if (V0 != 0)
{
    [address + 230] = w(20); // nullify
}



funcab480; // death/halve/double/miss/recovery related



S2 = 0;
if ((w[address + 6c] & 0200) == 0) // can be reflected
{
    V0 = hu[800f4958];
    V0 = V0 >> S0;
    if ((V0 & 0001) == 0)
    {
        V0 = w[address + 228];
        V0 = V0 >>> 12;
        S2 = V0 & 0001; // reflect status
    }
}



// if we can hit target and target is alive but flag miss if not dead set - then we miss
V0 = w[address + 6c];
if ((V0 & 0100) == 0) // miss if target not dead
{
    if (S2 == 0) // not reflecting
    {
        if ((w[address + 228] & 00000001) == 0) // target not dead
        {
            if ((w[address + 230] & c1) == 0) // not recovery death or absorb
            {
                [address + 218] = w(w[address + 218] | 00000001);
            }
        }
    }
}



if ((w[address + 218] & 00000001) == 0)
{
    [address + e0] = w(w[address + e0] + 1);
    [S1 + 4] = h(hu[S1 + 4] | 0001);

    A0 = 4;
    funca8e84;

    if (w[address + 0] != S0)
    {
        V1 = w[address + 78];
        V0 = 1 << S0;
        V1 = V1 | V0;
        [address + 78] = w(V1);
    }

    if (w[address + 218] & 00000004 && w[address + b0] < 9)
    {
        funca2974;
    }

    if (S2 != 0)
    {
        A0 = S3; // attacker id
        A1 = S0; // target id
        funcaa6e8; // return 1 if player attackes enemy or otherwise
        if (V0 == 0)
        {
            V1 = b[800f494c + S0];
            if (V1 == -1)
            {
                A0 = S0;
                funcaa700;

                A0 = V0;
                get_last_significant_bit_number;

                [800f494c + S0] = b(V0);
                V1 = V0;
            }
        }
        else
        {
            V1 = S3;
        }

        800ABEAC	sll    a0, s0, $01
        800ABEB0	lui    v0, $800f
        800ABEB4	lw     v0, $4920(v0)
        800ABEB8	ori    s2, zero, $0001
        800ABEBC	ori    v0, v0, $0002
        800ABEC0	lui    at, $800f
        800ABEC4	sw     v0, $4920(at)
        800ABEC8	lui    v0, $800f
        800ABECC	addiu  v0, v0, $4938
        800ABED0	addu   a0, a0, v0
        800ABED4	lhu    v0, $0000(a0)
        800ABED8	sllv   v1, v1, s2
        800ABEDC	or     v0, v0, v1
        800ABEE0	jal    funcaca24 [$800aca24]
        800ABEE4	sh     v0, $0000(a0)
        800ABEE8	lui    a0, $8006
        800ABEEC	lw     a0, $3014(a0)
        800ABEF0	nop
        800ABEF4	lw     v1, $0200(a0)
        800ABEF8	nop
        800ABEFC	lw     v0, $0034(v1)
        800ABF00	lui    a1, $0004
        800ABF04	and    v0, v0, a1
        800ABF08	beq    v0, zero, Labf30 [$800abf30]
        800ABF0C	nop
        800ABF10	lui    v0, $800f
        800ABF14	lhu    v0, $4958(v0)
        800ABF18	sllv   v1, s0, s2
        800ABF1C	or     v0, v0, v1
        800ABF20	lui    at, $800f
        800ABF24	sh     v0, $4958(at)
        800ABF28	j      Labf58 [$800abf58]
        800ABF2C	nop

        Labf30:	; 800ABF30
        800ABF30	lbu    v0, $0028(v1)
        800ABF34	nop
        800ABF38	beq    v0, zero, Labf48 [$800abf48]
        800ABF3C	addiu  v0, v0, $ffff (=-$1)
        800ABF40	j      Labf58 [$800abf58]
        800ABF44	sb     v0, $0028(v1)

        Labf48:	; 800ABF48
        800ABF48	lw     v0, $023c(a0)
        800ABF4C	nop
        800ABF50	or     v0, v0, a1
        800ABF54	sw     v0, $023c(a0)

        Labf58:	; 800ABF58
        800ABF58	lui    v1, $8006
        800ABF5C	lw     v1, $3014(v1)
        800ABF60	nop
        800ABF64	lw     v0, $0218(v1)
        800ABF68	nop
        800ABF6C	ori    v0, v0, $0002
        800ABF70	sw     v0, $0218(v1)
        800ABF74	lhu    v0, $0004(s1)
        800ABF78	nop
        800ABF7C	ori    v0, v0, $0002
        800ABF80	sh     v0, $0004(s1)
        800ABF84	slti   v0, s0, $0003
        if (V0 != 0)
        {
            [address + 224] = w(a);
        }
    }

    Labf94:	; 800ABF94
    800ABF94	lui    v0, $8006
    800ABF98	lw     v0, $3014(v0)
    800ABF9C	nop
    800ABFA0	lw     v0, $0218(v0)
    800ABFA4	nop
    800ABFA8	andi   v0, v0, $4000
    800ABFAC	beq    v0, zero, Labfc4 [$800abfc4]
    800ABFB0	nop
    800ABFB4	lhu    v0, $0004(s1)
    800ABFB8	nop
    800ABFBC	ori    v0, v0, $0010
    800ABFC0	sh     v0, $0004(s1)

    Labfc4:	; 800ABFC4
    800ABFC4	lui    v0, $8006
    800ABFC8	lw     v0, $3014(v0)
    800ABFCC	nop
    800ABFD0	lw     v0, $0218(v0)
    800ABFD4	nop
    800ABFD8	andi   v0, v0, $8000
    800ABFDC	beq    v0, zero, Lac004 [$800ac004]
    800ABFE0	slti   v0, s0, $0003
    800ABFE4	lhu    v0, $0004(s1)
    800ABFE8	nop
    800ABFEC	ori    v0, v0, $0020
    800ABFF4	sh     v0, $0004(s1)
}
else
{
    funcaca24;
}

800AC000	slti   v0, s0, $0003

Lac004:	; 800AC004
if (V0 != 0)
{
    V1 = hu[800F5E76 + S0 * 34];
    A1 = hu[800F5E74 + S0 * 34]
}
else
{
    V1 = 2707; // 9999
    A1 = 3E7; // 999
}

A0 = address;
V0 = w[address + 220];
if (V0 & 0004)
{
    V1 = A1;
}

V0 = w[address + 214];
if (V1 < V0)
{
    [address + 214] = w(V1);
}

A0 = S0;
funcace14;

800AC088	beq    v0, zero, Lac0a0 [$800ac0a0]
800AC08C	nop
800AC090	lui    v0, $8006
800AC094	lw     v0, $3014(v0)
800AC098	nop
800AC09C	sw     zero, $0214(v0)

Lac0a0:	; 800AC0A0
800AC0A0	lui    a0, $8006
800AC0A4	lw     a0, $3014(a0)
800AC0A8	nop
800AC0AC	lw     v0, $0214(a0)
800AC0B0	nop
800AC0B4	beq    v0, zero, Lac0f4 [$800ac0f4]
800AC0B8	nop
800AC0BC	lw     v0, $0000(a0)
800AC0C0	nop
800AC0C4	sll    v1, v0, $04
800AC0C8	addu   v1, v1, v0
800AC0CC	sll    v1, v1, $02
800AC0D0	lui    at, $800f
800AC0D4	addu   at, at, v1
800AC0D8	lhu    v1, $5bf4(at)
800AC0DC	ori    v0, zero, $1e61
800AC0E0	bne    v1, v0, Lac0f4 [$800ac0f4]
800AC0E4	nop
800AC0E8	sw     v1, $0214(a0)
800AC0EC	lui    a0, $8006
800AC0F0	lw     a0, $3014(a0)

Lac0f4:	; 800AC0F4
800AC0F4	nop
800AC0F8	lw     v1, $0218(a0)
800AC0FC	nop
800AC100	andi   v0, v1, $0003
800AC104	bne    v0, zero, Lac1d8 [$800ac1d8]
800AC108	andi   v0, v1, $0001
800AC10C	lw     v0, $0220(a0)
800AC110	nop
800AC114	andi   v0, v0, $0001
800AC118	bne    v0, zero, Lac140 [$800ac140]
800AC11C	nop
800AC120	lw     v0, $0000(a0)
800AC124	nop
800AC128	beq    v0, s0, Lac140 [$800ac140]
800AC12C	ori    v0, zero, $0001
800AC130	lw     v1, $00a8(a0)
800AC134	sllv   v0, s0, v0
800AC138	or     v1, v1, v0
800AC13C	sw     v1, $00a8(a0)

Lac140:	; 800AC140
800AC140	lui    a0, $8006
800AC144	lw     a0, $3014(a0)
800AC148	nop
800AC14C	lw     v1, $0250(a0)
800AC150	addiu  v0, zero, $ffff (=-$1)
800AC154	bne    v1, v0, Lac170 [$800ac170]
800AC158	nop
800AC15C	lw     v0, $0214(a0)
800AC160	nop
800AC164	sw     v0, $0250(a0)
800AC168	lui    a0, $8006
800AC16C	lw     a0, $3014(a0)

Lac170:	; 800AC170
800AC170	nop
800AC174	lw     v0, $0220(a0)
[address + 24c] = w(w[address + 68]);
800AC17C	andi   v0, v0, $0002
800AC180	beq    v0, zero, Lac194 [$800ac194]

800AC188	lw     v0, $0058(a0)
800AC18C	j      Lac1a0 [$800ac1a0]
800AC190	sw     v0, $0248(a0)

Lac194:	; 800AC194
800AC194	lw     v0, $0054(a0)
800AC198	nop
800AC19C	sw     v0, $0248(a0)

Lac1a0:	; 800AC1A0
V1 = address;
V0 = w[address + 220];
V0 = V0 & 0001;
if (V0 == 0)
{
    800AC1C0	lw     v0, $0250(v1)
    800AC1C4	nop
    800AC1C8	bne    v0, zero, Lac200 [$800ac200]
    800AC1CC	ori    v0, zero, $0033
}

[address + 224] = w(33);
800AC1D0	j      Lac208 [$800ac208]

Lac1d8:	; 800AC1D8
800AC1D8	beq    v0, zero, Lac1ec [$800ac1ec]
800AC1DC	nop
800AC1E0	lw     v0, $005c(a0)
800AC1E4	j      Lac208 [$800ac208]
800AC1E8	sw     v0, $0248(a0)

Lac1ec:	; 800AC1EC
800AC1EC	lw     v0, $0230(a0)
800AC1F0	lw     v1, $0054(a0)
800AC1F4	andi   v0, v0, $0001
800AC1F8	beq    v0, zero, Lac208 [$800ac208]
800AC1FC	sw     v1, $0248(a0)

Lac200:	; 800AC200
800AC200	jal    funcac6b4 [$800ac6b4]
800AC204	addu   a0, zero, zero

Lac208:	; 800AC208
V1 = address;
A0 = w[address + 218];
if (A0 & 00000001)
{
    800AC228	addu   t2, zero, zero
    800AC22C	addu   t0, v1, zero
    800AC230	ori    t7, zero, $0001
    800AC234	lui    v0, $800a
    800AC238	addiu  v0, v0, $03a0
    800AC23C	addiu  t6, v0, $0008
    800AC240	addu   t1, v0, zero
    800AC244	lw     v0, $022c(t0)
    800AC248	lw     a0, $0228(t0)
    800AC24C	nor    t5, zero, v0
    800AC250	addu   t3, a0, zero

    loopac254:	; 800AC254
    800AC254	addu   a1, zero, zero
    800AC258	addu   t4, t1, zero
    800AC25C	addu   a3, t6, zero
    800AC260	addu   a2, t1, zero

    loopac264:	; 800AC264
    800AC264	lw     v1, $0238(t0)
    800AC268	lw     v0, $0000(a2)
    800AC26C	nop
    800AC270	and    v0, v1, v0
    800AC274	beq    v0, zero, Lac2d4 [$800ac2d4]
    800AC278	nop
    800AC27C	bne    t2, t7, Lac2b8 [$800ac2b8]
    800AC280	xori   v0, a1, $0001
    800AC284	sll    v0, v0, $02
    800AC288	addu   v0, v0, t6
    800AC28C	lw     v0, $0000(v0)
    800AC290	nop
    800AC294	and    v0, t3, v0
    800AC298	beq    v0, zero, Lac2b8 [$800ac2b8]
    800AC29C	xori   v0, a1, $0001
    800AC2A0	lw     v0, $0000(a3)
    800AC2A4	nop
    800AC2A8	nor    v0, zero, v0
    800AC2AC	and    v0, v1, v0
    800AC2B0	sw     v0, $0238(t0)
    800AC2B4	xori   v0, a1, $0001

    Lac2b8:	; 800AC2B8
    800AC2B8	sll    v0, v0, $02
    800AC2BC	addu   v0, v0, t4
    800AC2C0	lw     v1, $023c(t0)
    800AC2C4	lw     v0, $0000(v0)
    800AC2C8	nop
    800AC2CC	or     v1, v1, v0
    800AC2D0	sw     v1, $023c(t0)

    Lac2d4:	; 800AC2D4
    800AC2D4	addiu  a3, a3, $0004
    800AC2D8	addiu  a1, a1, $0001
    800AC2DC	slti   v0, a1, $0002
    800AC2E0	bne    v0, zero, loopac264 [$800ac264]
    800AC2E4	addiu  a2, a2, $0004
    800AC2E8	addiu  t2, t2, $0001
    800AC2EC	slti   v0, t2, $0002
    800AC2F0	bne    v0, zero, loopac254 [$800ac254]
    800AC2F4	addiu  t1, t1, $0008
    800AC2F8	lui    a1, $8006
    800AC2FC	lw     a1, $3014(a1)
    800AC300	nop
    800AC304	lw     v1, $0250(a1)
    800AC308	addiu  v0, zero, $fffe (=-$2)
    if (V1 == V0)
    {
        800AC314	ori    t5, t5, $0001
    }
    800AC318	lw     v0, $0238(a1)
    800AC31C	lw     v1, $023c(a1)
    800AC320	and    v0, v0, t5
    800AC324	or     t3, t3, v0
    800AC328	and    v1, v1, t5
    800AC32C	nor    v1, zero, v1
    800AC330	lw     v0, $0240(a1)
    800AC334	and    t3, t3, v1
    800AC338	and    v0, v0, t5
    800AC33C	xor    t3, t3, v0
    800AC340	sll    v0, s0, $01
    800AC344	addu   v0, v0, s0
    800AC348	sll    v0, v0, $02
    800AC34C	addu   v0, v0, s0
    800AC350	sll    v0, v0, $03
    800AC354	sw     t3, $0228(a1)
    800AC358	lui    at, $8010
    800AC35C	addu   at, at, v0
    800AC360	sw     t3, $83e0(at)


    if (A0 != T3)
    {
        V0 = w[address + 244];
        V0 = T3 & V0;
        if (V0 != 0)
        {
            800AC380	lw     v0, $0000(a1)
            800AC384	nop
            if (V0 != S0)
            {
                800AC38C	ori    v0, zero, $0001
                800AC390	lw     v1, $00a8(a1)
                800AC394	sllv   v0, s0, v0
                800AC398	or     v1, v1, v0
                800AC39C	sw     v1, $00a8(a1)
            }
        }

        V0 = A0 XOR T3;
        if (V1 & 0001)
        {
            A0 = A0 & 1;
            funcac6b4;
        }
        else
        {
            800AC3C0	lhu    v0, $0004(s1)
            800AC3C4	nop
            800AC3C8	ori    v0, v0, $0008
            800AC3D0	sh     v0, $0004(s1)
        }
    }
    else
    {
        800AC3D4	lw     v0, $0218(a1)
        800AC3D8	lui    v1, $0080
        800AC3DC	or     v0, v0, v1
        800AC3E4	sw     v0, $0218(a1)
    }
}
else
{
    V0 = A0 | 00800000
    [address + 218] = w(V0);
}

// apply damage to stats
funcad0fc;

800AC3F8	lui    a1, $8006
800AC3FC	lw     a1, $3014(a1)
800AC400	lui    v1, $0004
800AC404	lw     a0, $0218(a1)
800AC408	ori    v1, v1, $0001
800AC40C	and    v0, a0, v1
800AC410	bne    v0, v1, Lac420 [$800ac420]
800AC414	addiu  v0, zero, $fffd (=-$3)
800AC418	and    v0, a0, v0
800AC41C	sw     v0, $0218(a1)

Lac420:	; 800AC420
800AC420	lui    v1, $8006
800AC424	lw     v1, $3014(v1)
800AC428	nop
800AC42C	lw     a0, $0218(v1)
800AC430	nop
800AC434	andi   v0, a0, $0002
800AC438	bne    v0, zero, Lac464 [$800ac464]
800AC43C	lui    v0, $0080
A1 = h[address + 250];
A2 = hu[address + 220]; // 1f800220 damage flags (heal damage to mp critical)
A3 = h[address + 248]; // impact sound
[SP + 10] = w(h[address + 24c]);
800AC450	addu   a0, s1, zero
800AC454	jal    funcaba68 [$800aba68]

800AC45C	j      Lac478 [$800ac478]
800AC460	nop

Lac464:	; 800AC464
800AC464	and    v0, a0, v0
800AC468	beq    v0, zero, Lac478 [$800ac478]
800AC46C	nop
800AC470	jal    funcad088 [$800ad088]
800AC474	addu   a0, s1, zero

Lac478:	; 800AC478
800AC478	lui    v0, $8006
800AC47C	lw     v0, $3014(v0)
800AC480	nop
800AC484	lw     v0, $006c(v0)
800AC488	nop
800AC48C	andi   v0, v0, $0010
800AC490	bne    v0, zero, Lac4a0 [$800ac4a0]
800AC494	nop
800AC498	jal    funcad420 [$800ad420]
800AC49C	nop

Lac4a0:	; 800AC4A0
800AC4A0	lui    v1, $8006
800AC4A4	lw     v1, $3014(v1)
800AC4A8	nop
800AC4AC	lw     v0, $0090(v1)
800AC4B0	nop
800AC4B4	andi   v0, v0, $0080
800AC4B8	beq    v0, zero, Lac4f4 [$800ac4f4]
800AC4BC	lui    v0, $51eb
800AC4C0	lw     a2, $0214(v1)
800AC4C4	ori    v0, v0, $851f
800AC4C8	mult   a2, v0
800AC4CC	ori    a3, zero, $0001
800AC4D0	lw     a0, $00f4(v1)
800AC4D4	lw     a1, $0208(v1)
800AC4D8	sra    a2, a2, $1f
800AC4DC	mfhi   t8
800AC4E0	sra    v0, t8, $05
800AC4E4	jal    funcad324 [$800ad324]
800AC4E8	subu   a2, v0, a2
800AC4EC	lui    v1, $8006
800AC4F0	lw     v1, $3014(v1)

Lac4f4:	; 800AC4F4
800AC4F4	nop
800AC4F8	lw     v0, $0090(v1)
800AC4FC	nop
800AC500	andi   v0, v0, $0040
800AC504	beq    v0, zero, Lac538 [$800ac538]

Lac508:	; 800AC508
800AC508	lui    v0, $6666
800AC50C	lw     a2, $0214(v1)
800AC510	ori    v0, v0, $6667
800AC514	mult   a2, v0
800AC518	ori    a3, zero, $0002
800AC51C	lw     a0, $00f4(v1)
800AC520	lw     a1, $0208(v1)
800AC524	sra    a2, a2, $1f
800AC528	mfhi   t8
800AC52C	sra    v0, t8, $02
800AC530	jal    funcad324 [$800ad324]
800AC534	subu   a2, v0, a2

Lac538:	; 800AC538
800AC538	slti   v0, s0, $0003
800AC53C	beq    v0, zero, Lac598 [$800ac598]
800AC540	sll    v0, s0, $01
800AC544	lui    v1, $8006
800AC548	lw     v1, $3014(v1)
800AC54C	nop
800AC550	lw     v0, $0000(v1)
800AC554	nop
800AC558	slti   v0, v0, $0004
800AC55C	bne    v0, zero, Lac598 [$800ac598]
800AC560	sll    v0, s0, $01
800AC564	lw     v0, $0204(v1)
800AC568	nop
800AC56C	lw     v0, $0024(v0)
800AC570	nop
800AC574	beq    v0, zero, Lac594 [$800ac594]
800AC578	ori    v0, zero, $000d
800AC57C	lw     v1, $0028(v1)
800AC580	nop
800AC584	bne    v1, v0, Lac598 [$800ac598]
800AC588	sll    v0, s0, $01
800AC58C	jal    funcab788 [$800ab788]
800AC590	nop

Lac594:	; 800AC594
Lac598:	; 800AC598
A0 = S0 * 68;
[S1 + 8] = w(w[800f83e0 + A0 + 0]);
[S1 + 2] = b(w[address + 224]);
V1 = w[80063014];
800AC5CC	lui    v0, $8006
800AC5D0	lw     v0, $3014(v0)
800AC5D4	nop
800AC5D8	lw     v0, $0218(v0)
800AC5DC	nop
800AC5E0	andi   v0, v0, $0020
800AC5E4	beq    v0, zero, Lac5f0 [$800ac5f0]
800AC5E8	ori    v0, zero, $0009
800AC5EC	sb     v0, $0002(s1)

Lac5f0:	; 800AC5F0
V0 = w[800f83e0 + A0];
if (V0 & 1)
{
    [S1 + 4] = h((hu[S1 + 4] | 4) & fff7);

    800AC610	lui    a0, $8006
    800AC614	lw     a0, $3014(a0)
    800AC624	ori    v0, zero, $0001
    800AC628	lw     v1, $007c(a0)
    800AC62C	sllv   v0, s0, v0
    800AC630	or     v1, v1, v0
    800AC634	sw     v1, $007c(a0)
    800AC638	lw     v1, $0028(a0)
    800AC63C	ori    v0, zero, $001a
    800AC640	bne    v1, v0, Lac694 [$800ac694]
    800AC644	sll    a0, s0, $04
    800AC648	lui    at, $8016
    800AC64C	addu   at, at, a0
    800AC650	lbu    v0, $36bc(at)
    800AC654	nop
    800AC658	sltiu  v0, v0, $0011
    800AC65C	beq    v0, zero, Lac670 [$800ac670]
    800AC660	ori    v0, zero, $0008
    800AC664	lui    at, $8016
    800AC668	addu   at, at, a0
    800AC66C	sb     v0, $36bc(at)

    Lac670:	; 800AC670
    800AC670	addu   a0, s1, zero
    800AC674	lui    v0, $8006
    800AC678	lw     v0, $3014(v0)
    800AC67C	addiu  a1, zero, $fffe (=-$2)
    800AC680	lh     a3, $0248(v0)
    [SP + 10] = w(h[address + 68]);
    800AC688	addu   a2, zero, zero
    800AC68C	jal    funcaba68 [$800aba68]
}

Lac694:	; 800AC694
//////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcad4ec
address = w[80063014];
V0 = w[address + a0]; // high

switch (V0)
{
    case 0x01 0x06 0x0A:
    {
        upper_function_00; // physical hit
        upper_function_02; // critical hit
    }
    break;

    case 0x02 0x07:
    {
        upper_function_01; // magical hit
    }
    break;

    case 0x03 0x4 0x5:
    {
        upper_function_03; // do nothing
    }
    break;

    case 0x08:
    {
        upper_function_07; // hit by hit % target level
    }
    break;

    case 0x09:
    {
        upper_function_06; // hit if can be manipulated
    }
    break;

    case 0x0B:
    {
        upper_function_00; // physical hit
    }
    break;
}



if (w[address + 48] != 0) // power modifier
{
    A0 = 0;
    funca8e84;

    formula = w[address + a4]; // lower
    switch (formula)
    {
        case 00: lower_function_00; break;
        case 01: lower_function_01; break; // physical damage
        case 02: lower_function_02; break; // magical damage
        case 03: lower_function_03; break; // current hp% or current mp%
        case 04: lower_function_04; break; // max hp% or max mp%
        case 05: lower_function_05; break; // magical heal
        case 06: lower_function_06; break; // fixed damage
        case 07: lower_function_07; break; // item damage
        case 08: lower_function_08; break; // recovery
        case 09: lower_function_09; break; // not used
        case 0a: lower_function_0a; break; // not used
        case 10: lower_function_10; break; // custom 00 white wind (damage = current hp of attacker)
        case 11: lower_function_11; break; // custom 01 (damage = max hp - current hp)
        case 12 13 14 15 16 17: break;
        case 18: lower_function_18; break; // custom 08 ()
34E20A80 19
5CE20A80 1a
A0E20A80 1b
18E30A80 1c
78E30A80 1d
        default: return;
    }

    A0 = 1;
    funca8e84;
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funca8e84
address = V1 = w[80063014];
A3 = w[address + bc];
if (A3 != -1)
{
0400 3C00 0400 2000 0100 2400 1000 1000 0400 0200 0200 0200 0200 0100 2000 0400
2400 1000 1000 0400 2000 1000 1000 1000 3000 1000 2000 1000 1000 1400 0100 0100
0100 0100 0100 1800
    V0 = hu[800a02c0 + A3 * 2];
    V0 = V0 >> A0;
    if (V0 & 1)
    {
        A2 = w[address + 0];

        V1 = 800f5e60 + A2 * 34;
        if (A3 < 24)
        {
            V0 = w[800a0308 + A3 * 4];

F08F0A80 2
2C900A80 3
3C900A80 4
B4900A80 5
18910A80 6
E4910A80 7
94920A80 8
D0920A80 9
2C940A80 f
3C940A80 10
C0940A80 11
F8940A80 12
58950A80 13
78960A80 14
C0960A80 16
D8960A80 17
F0960A80 18
8C970A80 19
30980A80 1a
B4980A80 1b
F4980A80 1c
18990A80 1d

            800A8F24	jr     v0 

            // set multiple attack
            case 0:
            {
                [address + b0] = w(w[address + c0]);
                return;
            }

448F0A80 1
            800A8F44	ori    v0, zero, $0003
            800A8F48	beq    a0, v0, La9b1c [$800a9b1c]
            800A8F4C	slti   v0, a0, $0004
            800A8F50	beq    v0, zero, La8f68 [$800a8f68]
            800A8F54	ori    v0, zero, $0002
            800A8F58	beq    a0, v0, La8f84 [$800a8f84]
            800A8F5C	addu   v0, zero, zero
            800A8F60	j      La9bf8 [$800a9bf8]
            800A8F64	nop

            La8f68:	; 800A8F68
            800A8F68	ori    v0, zero, $0004
            800A8F6C	beq    a0, v0, La970c [$800a970c]
            800A8F70	ori    v0, zero, $0005
            800A8F74	beq    a0, v0, La8f9c [$800a8f9c]
            800A8F78	addu   v0, zero, zero
            800A8F7C	j      La9bf8 [$800a9bf8]
            800A8F80	nop

            La8f84:	; 800A8F84
            800A8F84	lui    v0, $8006
            800A8F88	lw     v0, $3014(v0)
            800A8F8C	nop
            800A8F90	lw     v1, $0090(v0)
            800A8F94	j      La9948 [$800a9948]
            800A8F98	lui    a0, $0004

            La8f9c:	; 800A8F9C
            800A8F9C	lui    a0, $8006
            800A8FA0	lw     a0, $3014(a0)
            800A8FA4	nop
            800A8FA8	lw     v0, $00e0(a0)
            800A8FAC	nop
            800A8FB0	bne    v0, zero, La9bf8 [$800a9bf8]
            800A8FB4	addu   v0, zero, zero
            800A8FB8	lw     v0, $00b4(a0)
            800A8FBC	ori    v1, zero, $0061
            800A8FC0	sw     v1, $0098(a0)
            800A8FC4	addiu  v0, v0, $0001
            800A8FC8	jal    funca2f24 [$800a2f24]
            800A8FCC	sw     v0, $00b4(a0)
            800A8FD0	lui    v0, $8006
            800A8FD4	lw     v0, $3014(v0)
            800A8FD8	nop
            800A8FDC	lw     a0, $0098(v0)
            800A8FE0	jal    funca2d68 [$800a2d68]
            800A8FE4	nop
            800A8FE8	j      La9bf8 [$800a9bf8]
            800A8FEC	addu   v0, zero, zero
            800A8FF0	jal    get_random_byte_from_table [$80014b70]
            800A8FF4	nop
            800A8FF8	lui    a0, $8006
            800A8FFC	lw     a0, $3014(a0)
            800A9000	nop
            800A9004	lw     v1, $00c0(a0)
            800A9008	andi   v0, v0, $00ff
            800A900C	slt    v0, v0, v1
            800A9010	beq    v0, zero, La9bf8 [$800a9bf4]
            800A9014	ori    v0, zero, $0060
            800A9018	sw     v0, $002c(a0)
            800A901C	jal    funca8e34 [$800a8e34]
            800A9020	sw     v0, $0098(a0)
            800A9024	j      La9bf8 [$800a9bf8]
            800A9028	addu   v0, zero, zero
            800A902C	jal    funcaa1c8 [$800aa1c8]
            800A9030	nop
            800A9034	j      La9bf8 [$800a9bf8]
            800A9038	addu   v0, zero, zero
            800A903C	lui    a2, $8006
            800A9040	lw     a2, $3014(a2)
            800A9044	nop
            800A9048	lw     v1, $0208(a2)
            800A904C	addiu  a1, zero, $fffe (=-$2)
            800A9050	sll    v0, v1, $01
            800A9054	addu   v0, v0, v1
            800A9058	sll    v0, v0, $02
            800A905C	addu   v0, v0, v1
            800A9060	sll    v0, v0, $03
            800A9064	lw     v1, $0234(a2)
            800A9068	lui    at, $8010
            800A906C	addu   at, at, v0
            800A9070	lw     a0, $83e4(at)
            800A9074	lw     v0, $0220(a2)
            800A9078	and    v1, v1, a1
            800A907C	sw     v1, $0234(a2)
            800A9080	addiu  v1, zero, $fffd (=-$3)
            800A9084	and    v0, v0, v1
            800A9088	srl    a0, a0, $07
            800A908C	sw     v0, $0220(a2)
            800A9090	lw     v0, $00c0(a2)
            800A9094	andi   a0, a0, $0001
            800A9098	bne    a0, v0, La9bf8 [$800a9bf8]
            800A909C	addu   v0, zero, zero
            800A90A0	lw     v0, $0234(a2)
            800A90A4	nop
            800A90A8	ori    v0, v0, $0001
            800A90AC	j      La9bf8 [$800a9bf4]
            800A90B0	sw     v0, $0234(a2)
            800A90B4	ori    v0, zero, $0002
            800A90B8	beq    a0, v0, La90d0 [$800a90d0]
            800A90BC	ori    v0, zero, $0005
            800A90C0	beq    a0, v0, La90fc [$800a90fc]
            800A90C4	addu   v0, zero, zero
            800A90C8	j      La9bf8 [$800a9bf8]
            800A90CC	nop

            La90d0:	; 800A90D0
            800A90D0	lui    v0, $8016
            800A90D4	lhu    v0, $3624(v0)
            800A90D8	nop
            800A90DC	andi   v0, v0, $0004
            800A90E0	bne    v0, zero, La9bf8 [$800a9bf8]
            800A90E4	addu   v0, zero, zero
            800A90E8	lui    v1, $8006
            800A90EC	lw     v1, $3014(v1)
            800A90F0	ori    v0, zero, $0036
            800A90F4	j      La9bf8 [$800a9bf4]
            800A90F8	sw     v0, $00dc(v1)

            La90fc:	; 800A90FC
            800A90FC	lui    v1, $8010
            800A9100	addiu  v1, v1, $83c6 (=-$7c3a)
            800A9104	lhu    v0, $0000(v1)
            800A9108	nop
            800A910C	ori    v0, v0, $0008
            800A9110	j      La9bf8 [$800a9bf4]
            800A9114	sh     v0, $0000(v1)
            800A9118	lui    v1, $8006
            800A911C	lw     v1, $3014(v1)
            800A9120	nop
            800A9124	lw     v0, $0208(v1)
            800A9128	nop
            800A912C	slti   v0, v0, $0003
            800A9130	beq    v0, zero, La9240 [$800a9240]
            800A9134	nop
            800A9138	lw     v1, $0004(v1)
            800A913C	lui    t3, $800a
            800A9140	addiu  t3, t3, $d260 (=-$2da0)
            800A9144	sll    v0, v1, $02
            800A9148	addu   v0, v0, v1
            800A914C	sll    v0, v0, $02
            800A9150	sh     v0, $0010(sp)
            800A9154	lw     v1, $0000(t3)
            800A9158	andi   v0, v0, $ffff
            800A915C	sltu   v0, v1, v0
            800A9160	beq    v0, zero, La916c [$800a916c]
            800A9164	nop
            800A9168	sh     v1, $0010(sp)

            La916c:	; 800A916C
            800A916C	lhu    t2, $0010(sp)
            800A9170	nop
            800A9174	andi   t0, t2, $ffff
            800A9178	beq    t0, zero, La9240 [$800a9240]
            800A917C	sll    v0, a2, $01
            800A9180	addu   v0, v0, a2
            800A9184	sll    v0, v0, $02
            800A9188	addu   v0, v0, a2
            800A918C	sll    t1, v0, $03
            800A9190	lui    at, $8010
            800A9194	addu   at, at, t1
            800A9198	lhu    a3, $8430(at)
            800A919C	ori    v0, zero, $fffe
            800A91A0	addu   v1, a3, t0
            800A91A4	slt    v0, v0, v1
            800A91A8	bne    v0, zero, La9240 [$800a9240]
            800A91AC	addu   a0, a2, zero
            800A91B0	ori    a1, zero, $0055
            800A91B4	ori    a2, zero, $0001
            800A91B8	addu   v0, a3, t2
            800A91BC	lui    at, $8010
            800A91C0	addu   at, at, t1
            800A91C4	sh     v0, $8430(at)
            800A91C8	lw     v0, $0000(t3)
            800A91CC	addiu  a3, sp, $0010
            800A91D0	subu   v0, v0, t0
            800A91D4	jal    funcb0ffc [$800b0ffc]
            800A91D8	sw     v0, $0000(t3)
            800A91DC	j      La9240 [$800a9240]
            800A91E0	nop
            800A91E4	sll    v0, a2, $01
            800A91E8	addu   v0, v0, a2
            800A91EC	sll    v0, v0, $02
            800A91F0	addu   v0, v0, a2
            800A91F4	sll    v0, v0, $03
            800A91F8	lui    at, $8010
            800A91FC	addu   at, at, v0
            800A9200	lhu    v1, $8432(at)
            800A9204	ori    v0, zero, $ffff
            800A9208	bne    v1, v0, La9240 [$800a9240]
            800A920C	nop
            800A9210	lui    v0, $8006
            800A9214	lw     v0, $3014(v0)
            800A9218	nop
            800A921C	lw     v0, $0208(v0)
            800A9220	nop
            800A9224	slti   v0, v0, $0003
            800A9228	beq    v0, zero, La9240 [$800a9240]
            800A922C	addu   a0, zero, zero
            800A9230	addu   a1, a2, zero
            800A9234	ori    a2, zero, $000b
            800A9238	jal    funca7254 [$800a7254]
            800A923C	addu   a3, zero, zero

            La9240:	; 800A9240
            800A9240	lui    a0, $8006
            800A9244	lw     a0, $3014(a0)
            800A9248	nop
            800A924C	lw     v0, $0048(a0)
            800A9250	nop
            800A9254	bne    v0, zero, La9bf8 [$800a9bf8]
            800A9258	addu   v0, zero, zero
            800A925C	lw     v0, $0218(a0)
            800A9260	lw     v1, $0208(a0)
            800A9264	ori    v0, v0, $0002
            800A9268	sw     v0, $0218(a0)
            800A926C	sll    v0, v1, $01
            800A9270	addu   v0, v0, v1
            800A9274	sll    v0, v0, $02
            800A9278	addu   v0, v0, v1
            800A927C	sll    v0, v0, $03
            800A9280	lui    at, $8010
            800A9284	addu   at, at, v0
            800A9288	lbu    v0, $83f1(at)
            800A928C	j      La9bf8 [$800a9bf4]
            800A9290	sw     v0, $0224(a0)
            800A9294	jal    func14ba8 [$80014ba8]
            800A9298	ori    a0, zero, $0007
            800A929C	lui    a1, $8006
            800A92A0	lw     a1, $3014(a1)
            800A92A4	nop
            800A92A8	lw     v1, $0024(a1)
            800A92AC	andi   v0, v0, $00ff
            800A92B0	sw     v0, $0048(a1)
            800A92B4	lw     a0, $0048(a1)
            800A92B8	addu   v1, v1, v0
            800A92BC	addiu  a0, a0, $0004
            800A92C0	sll    a0, a0, $03
            800A92C4	sw     v1, $0024(a1)
            800A92C8	j      La9bf8 [$800a9bf4]
            800A92CC	sw     a0, $0048(a1)
            800A92D0	lui    a0, $8006
            800A92D4	lw     a0, $3014(a0)
            800A92D8	nop
            800A92DC	lw     v1, $0004(a0)
            800A92E0	lw     v0, $0254(a0)
            800A92E4	nop
            800A92E8	bne    v1, v0, La9bf8 [$800a9bf8]
            800A92EC	addu   v0, zero, zero

            V0 = w[address + 214];

            800A92F8	sll    v0, v0, $03
            800A92FC	j      La9bf8 [$800a9bf4]
            800A9300	sw     v0, $0214(a0)

            case a:
            {
                funcaa468;

                return 0;
            }
            break;

            case b:
            {
                funcaa4fc;

                return 0;
            }
            break;

            case c:
            {
                funcaa688;

                return 0;
            }
            break;

            case d:
            {
                total_level = 0;
                A0 = 0;

                A3 = w[address + 18];

                V1 = 4;
                loopa9350:	; 800A9350
                    V0 = A3 >> V1;
                    if (V0 & 1)
                    {
                        A0 = A0 + 1;
                        total_level = total_level + bu[800f83e0 + V1 * 68 + 9];
                    }

                    V1 = V1 + 1;
                    V0 = V1 < a;
                800A9380	bne    v0, zero, loopa9350 [$800a9350]

                if (A0 != 0)
                {
                    A1 = total_level / A0;
                }

                [address + 48] = w(A1);

                return;
            }
            break;

CC930A80 e
            800A93CC	addu   s1, zero, zero
            800A93D0	addiu  a2, zero, $fffe (=-$2)
            800A93D4	lui    a1, $8010
            800A93D8	addiu  a1, a1, $83e0 (=-$7c20)
            800A93DC	addu   a0, zero, zero

            loopa93e0:	; 800A93E0
            800A93E0	lw     v1, $0000(a1)
            800A93E4	nop
            800A93E8	andi   v0, v1, $0001
            800A93EC	beq    v0, zero, La9410 [$800a9410]
            800A93F0	and    v0, v1, a2
            800A93F4	sw     v0, $0000(a1)
            800A93F8	lui    at, $8010
            800A93FC	addu   at, at, a0
            800A9400	lw     v0, $8410(at)
            800A9404	lui    at, $8010
            800A9408	addu   at, at, a0
            800A940C	sw     v0, $840c(at)

            La9410:	; 800A9410
            800A9410	addiu  a1, a1, $0068
            800A9414	addiu  s1, s1, $0001
            800A9418	slti   v0, s1, $0003
            800A941C	bne    v0, zero, loopa93e0 [$800a93e0]

            La9420:	; 800A9420
            800A9420	addiu  a0, a0, $0068
            800A9424	j      La9bf8 [$800a9bf8]
            800A9428	addu   v0, zero, zero
            800A942C	jal    funca9c24 [$800a9c24]
            800A9430	nop
            800A9434	j      La9bf8 [$800a9bf8]
            800A9438	addu   v0, zero, zero
            800A943C	ori    v0, zero, $0002
            800A9440	beq    a0, v0, La9458 [$800a9458]
            800A9444	ori    v0, zero, $0005
            800A9448	beq    a0, v0, La94b0 [$800a94b0]
            800A944C	addu   v0, zero, zero
            800A9450	j      La9bf8 [$800a9bf8]
            800A9454	nop

            La9458:	; 800A9458
            800A9458	addu   a0, zero, zero
            800A945C	addu   s1, zero, zero
            800A9460	addiu  a1, zero, $ffff (=-$1)
            800A9464	addu   v1, zero, zero

            loopa9468:	; 800A9468
            800A9468	lui    at, $8010
            800A946C	addu   at, at, v1
            800A9470	lb     v0, $83e8(at)
            800A9474	nop
            800A9478	beq    v0, a1, La9484 [$800a9484]
            800A947C	nop
            800A9480	addiu  a0, a0, $0001

            La9484:	; 800A9484
            800A9484	addiu  s1, s1, $0001
            800A9488	slti   v0, s1, $0003
            800A948C	bne    v0, zero, loopa9468 [$800a9468]
            800A9490	addiu  v1, v1, $0068
            800A9494	slti   v0, a0, $0002
            800A9498	beq    v0, zero, La9bf8 [$800a9bf4]
            800A949C	ori    v0, zero, $0050
            800A94A0	lui    v1, $8006
            800A94A4	lw     v1, $3014(v1)
            800A94A8	j      La9bf8 [$800a9bf4]
            800A94AC	sw     v0, $00dc(v1)

            La94b0:	; 800A94B0
            800A94B0	jal    funca9da0 [$800a9da0]
            800A94B4	nop
            800A94B8	j      La9bf8 [$800a9bf8]
            800A94BC	addu   v0, zero, zero
            800A94C0	lui    v0, $8006
            800A94C4	lw     v0, $3014(v0)
            800A94C8	nop
            800A94CC	lw     a1, $0208(v0)
            800A94D0	nop
            800A94D4	slti   v0, a1, $0003
            800A94D8	beq    v0, zero, La9540 [$800a9540]
            800A94DC	ori    a0, zero, $0002
            800A94E0	ori    a2, zero, $0013
            800A94E4	ori    a3, zero, $0001
            800A94E8	jal    funca7254 [$800a7254]
            800A94EC	sllv   a3, a1, a3
            800A94F0	j      La9540 [$800a9540]
            800A94F4	nop
            800A94F8	lui    v0, $8006
            800A94FC	lw     v0, $3014(v0)
            800A9500	nop
            800A9504	lw     a1, $0208(v0)
            800A9508	ori    v0, zero, $0001
            800A950C	sllv   s0, a1, v0
            800A9510	slti   v0, a1, $0003
            800A9514	beq    v0, zero, La9528 [$800a9528]
            800A9518	ori    a0, zero, $0002
            800A951C	ori    a2, zero, $0013
            800A9520	jal    funca7254 [$800a7254]
            800A9524	addu   a3, s0, zero

            La9528:	; 800A9528
            800A9528	lui    v0, $800f
            800A952C	addiu  v0, v0, $7dcc
            800A9530	lhu    v1, $0000(v0)
            800A9534	nop
            800A9538	or     v1, v1, s0
            800A953C	sh     v1, $0000(v0)

            La9540:	; 800A9540
            800A9540	jal    funca2d0c [$800a2d0c]
            800A9544	nop
            800A9548	lui    v1, $8006
            800A954C	lw     v1, $3014(v1)
            800A9550	j      La9bf8 [$800a9bf4]
            800A9554	sw     v0, $0224(v1)
            800A9558	addu   a1, zero, zero
            800A955C	addu   s1, zero, zero
            800A9560	ori    s6, zero, $0001
            800A9564	lui    v0, $8006
            800A9568	lw     v0, $3014(v0)
            800A956C	sll    v1, a2, $04
            800A9570	sw     zero, $0018(v0)
            800A9574	sw     zero, $00b4(v0)
            800A9578	sll    v0, a2, $01
            800A957C	addu   v0, v0, a2
            800A9580	sll    v0, v0, $02
            800A9584	addu   v0, v0, a2
            800A9588	sll    v0, v0, $02
            800A958C	lui    at, $8016
            800A9590	addu   at, at, v1
            800A9594	lb     s4, $36b8(at)
            800A9598	lui    at, $800f
            800A959C	addu   at, at, v0
            800A95A0	lw     v0, $5e60(at)
            800A95A4	nop
            800A95A8	lhu    s2, $0022(v0)
            800A95AC	jal    func15afc [$80015afc]
            800A95B0	addu   a0, s4, zero
            800A95B4	addu   s5, v0, zero

            loopa95b8:	; 800A95B8
            800A95B8	lui    at, $8016
            800A95BC	addu   at, at, s1
            800A95C0	lbu    s3, $3778(at)
            800A95C4	ori    a0, zero, $007f
            800A95C8	addu   s0, zero, zero
            800A95CC	srav   v0, s0, s2

            loopa95d0:	; 800A95D0
            800A95D0	andi   v0, v0, $0001
            800A95D4	beq    v0, zero, La95fc [$800a95fc]
            800A95D8	nop
            800A95DC	addu   a0, s4, zero
            800A95E0	jal    func15afc [$80015afc]
            800A95E4	addu   a1, s0, zero
            800A95E8	addu   a0, v0, zero
            800A95EC	sllv   v0, s0, s6
            800A95F0	nor    v0, zero, v0
            800A95F4	j      La960c [$800a960c]
            800A95F8	and    s2, s2, v0

            La95fc:	; 800A95FC
            800A95FC	addiu  s0, s0, $0001
            800A9600	slti   v0, s0, $000c
            800A9604	bne    v0, zero, loopa95d0 [$800a95d0]
            800A9608	srav   v0, s0, s2

            La960c:	; 800A960C
            800A960C	beq    s3, zero, La9650 [$800a9650]
            800A9610	subu   a0, a0, s5
            800A9614	slti   v0, a0, $0007
            800A9618	beq    v0, zero, La9650 [$800a9650]
            800A961C	slti   v0, s3, $0002
            800A9620	bne    v0, zero, La962c [$800a962c]
            800A9624	addiu  a0, a0, $0062
            800A9628	ori    a0, a0, $0080

            La962c:	; 800A962C
            800A962C	jal    funca2d68 [$800a2d68]
            800A9630	nop
            800A9634	lui    v1, $8006
            800A9638	lw     v1, $3014(v1)
            800A963C	nop
            800A9640	lw     v0, $00b4(v1)
            800A9644	nop
            800A9648	addiu  v0, v0, $0001
            800A964C	sw     v0, $00b4(v1)

            La9650:	; 800A9650
            800A9650	addiu  s1, s1, $0001
            800A9654	slti   v0, s1, $0007
            800A9658	bne    v0, zero, loopa95b8 [$800a95b8]
            800A965C	lui    a0, $0001
            800A9660	lui    v0, $8006
            800A9664	lw     v0, $3014(v0)
            800A9668	nop
            800A966C	lw     v1, $0090(v0)
            800A9670	j      La994c [$800a994c]
            800A9674	or     v1, v1, a0
            800A9678	addu   s1, zero, zero
            800A967C	ori    a0, zero, $00ff
            800A9680	addu   v1, zero, zero

            loopa9684:	; 800A9684
            800A9684	beq    a2, s1, La9698 [$800a9698]
            800A9688	nop
            800A968C	lui    at, $800f
            800A9690	addu   at, at, v1
            800A9694	sh     a0, $5e68(at)

            La9698:	; 800A9698
            800A9698	addiu  s1, s1, $0001
            800A969C	slti   v0, s1, $0003
            800A96A0	bne    v0, zero, loopa9684 [$800a9684]
            800A96A4	addiu  v1, v1, $0034
            800A96A8	j      La9bf8 [$800a9bf8]
            800A96AC	addu   v0, zero, zero

            // Alters base damage and defense by [Modifier]% (Stackable, not to exceed 200) Hero Drink 
            case 15:
            {
                A0 = w[address + 208];
                A1 = w[address + c0];
                A2 = f;
                A1 = A1 - 64;
                funcb1268

                return 0;
            }
            break;

            800A96C0	lui    v0, $8006
            800A96C4	lw     v0, $3014(v0)
            800A96C8	addu   a0, a2, zero
            800A96CC	lw     a1, $00c0(v0)
            800A96D0	j      La9908 [$800a9908]
            800A96D4	ori    a2, zero, $0010
            800A96D8	lui    v0, $8006
            800A96DC	lw     v0, $3014(v0)
            800A96E0	addu   a0, a2, zero
            800A96E4	lw     a1, $00c0(v0)
            800A96E8	j      La9908 [$800a9908]
            800A96EC	ori    a2, zero, $0001
            800A96F0	ori    v0, zero, $0004
            800A96F4	beq    a0, v0, La970c [$800a970c]
            800A96F8	ori    v0, zero, $0005
            800A96FC	beq    a0, v0, La974c [$800a974c]
            800A9700	addu   v0, zero, zero
            800A9704	j      La9bf8 [$800a9bf8]
            800A9708	nop

            La970c:	; 800A970C
            800A970C	lui    v0, $8006
            800A9710	lw     v0, $3014(v0)
            800A9714	nop
            800A9718	lw     a1, $0208(v0)
            800A971C	nop
            800A9720	slti   v0, a1, $0004
            800A9724	bne    v0, zero, La9bf8 [$800a9bf8]
            800A9728	addu   v0, zero, zero
            800A972C	lui    v0, $800f
            800A9730	addiu  v0, v0, $7de0
            800A9734	ori    v1, zero, $0001
            800A9738	lhu    a0, $0000(v0)
            800A973C	sllv   v1, a1, v1
            800A9740	or     a0, a0, v1
            800A9744	j      La9bf8 [$800a9bf4]
            800A9748	sh     a0, $0000(v0)

            La974c:	; 800A974C
            800A974C	lui    v0, $8006
            800A9750	lw     v0, $3014(v0)
            800A9754	nop
            800A9758	lw     v1, $00c0(v0)
            800A975C	lw     a1, $0018(v0)
            800A9760	sw     v1, $0098(v0)
            800A9764	lw     a0, $0098(v0)
            800A9768	lw     v1, $00b4(v0)
            800A976C	sw     a1, $00ec(v0)
            800A9770	addiu  v1, v1, $0001
            800A9774	jal    funca2d68 [$800a2d68]
            800A9778	sw     v1, $00b4(v0)
            800A977C	lui    a0, $8006
            800A9780	lw     a0, $3014(a0)
            800A9784	j      La98a0 [$800a98a0]
            800A9788	lui    v1, $0008
            800A978C	jal    funcb12dc [$800b12dc]
            800A9790	nop
            800A9794	beq    v0, zero, La9bf8 [$800a9bf8]
            800A9798	addu   v0, zero, zero
            800A979C	lui    a0, $8006
            800A97A0	lw     a0, $3014(a0)
            800A97A4	nop
            800A97A8	lw     v1, $0208(a0)
            800A97AC	nop

            La97b0:	; 800A97B0
            800A97B0	slti   v0, v1, $0003
            800A97B4	beq    v0, zero, La9bf8 [$800a9bf4]
            800A97B8	sll    v0, v1, $01
            800A97BC	addu   v0, v0, v1
            800A97C0	sll    v0, v0, $02
            800A97C4	addu   v0, v0, v1
            800A97C8	sll    v0, v0, $03
            800A97CC	lui    at, $8010
            800A97D0	addu   at, at, v0
            800A97D4	lw     v0, $83e4(at)
            800A97D8	nop
            800A97DC	andi   v0, v0, $0040
            800A97E0	beq    v0, zero, La97ec [$800a97ec]
            800A97E4	ori    v1, zero, $0031
            800A97E8	ori    v1, zero, $0032

            La97ec:	; 800A97EC
            800A97EC	lw     v0, $0208(a0)
            800A97F0	sw     v1, $0224(a0)
            800A97F4	sll    v1, v0, $01
            800A97F8	addu   v1, v1, v0
            800A97FC	sll    v1, v1, $02
            800A9800	addu   v1, v1, v0
            800A9804	sll    v1, v1, $03
            800A9808	lui    at, $8010
            800A980C	addu   at, at, v1
            800A9810	lw     v0, $83e4(at)
            800A9814	nop
            800A9818	xori   v0, v0, $0040
            800A981C	lui    at, $8010
            800A9820	addu   at, at, v1
            800A9824	sw     v0, $83e4(at)
            800A9828	j      La9bf8 [$800a9bf8]
            800A982C	addu   v0, zero, zero
            800A9830	lui    a1, $8006
            800A9834	lw     a1, $3014(a1)
            800A9838	nop
            800A983C	lw     a2, $0018(a1)
            800A9840	nop
            800A9844	andi   v0, a2, $000f
            800A9848	beq    v0, zero, La9854 [$800a9854]
            800A984C	ori    a0, zero, $03f0
            800A9850	ori    a0, zero, $000f

            La9854:	; 800A9854
            800A9854	lui    v0, $8016
            800A9858	lhu    v0, $3766(v0)
            800A985C	lui    v1, $8016
            800A9860	lhu    v1, $3758(v1)
            800A9864	nor    v0, zero, v0
            800A9868	and    v1, v1, v0
            800A986C	and    v1, v1, a0
            800A9870	nor    v0, zero, a2
            800A9874	and    v1, v1, v0
            800A9878	lw     a0, $00c0(a1)
            800A987C	lw     v0, $00b4(a1)
            800A9880	sw     v1, $00ec(a1)
            800A9884	addiu  v0, v0, $0001
            800A9888	sw     v0, $00b4(a1)
            800A988C	jal    funca2d68 [$800a2d68]
            800A9890	sw     a0, $0098(a1)
            800A9894	lui    a0, $8006
            800A9898	lw     a0, $3014(a0)
            800A989C	lui    v1, $0028

            La98a0:	; 800A98A0
            800A98A0	lw     v0, $0090(a0)
            800A98A4	ori    v1, v1, $1000
            800A98A8	or     v0, v0, v1
            800A98AC	j      La9bf8 [$800a9bf4]
            800A98B0	sw     v0, $0090(a0)
            800A98B4	lui    v0, $8006
            800A98B8	lw     v0, $3014(v0)
            800A98BC	nop
            800A98C0	lw     a1, $0208(v0)
            800A98C4	nop
            800A98C8	slti   v0, a1, $0004
            800A98CC	bne    v0, zero, La9bf8 [$800a9bf8]
            800A98D0	addu   v0, zero, zero
            800A98D4	ori    v0, zero, $0001
            800A98D8	lui    a0, $800f
            800A98DC	addiu  a0, a0, $7dcc
            800A98E0	lhu    v1, $0000(a0)
            800A98E4	sllv   v0, a1, v0
            800A98E8	or     v1, v1, v0
            800A98EC	j      La9bf8 [$800a9bf4]
            800A98F0	sh     v1, $0000(a0)
            800A98F4	lui    v0, $8006
            800A98F8	lw     v0, $3014(v0)
            800A98FC	ori    a2, zero, $000c

            La9900:	; 800A9900
            800A9900	lw     a1, $00c0(v0)
            800A9904	lw     a0, $0208(v0)

            La9908:	; 800A9908
            800A9908	jal    funcb1268 [$800b1268]
            800A990C	addiu  a1, a1, $ff9c (=-$64)
            800A9910	j      La9bf8 [$800a9bf8]
            800A9914	addu   v0, zero, zero
            800A9918	ori    v0, zero, $0002
            800A991C	beq    a0, v0, La9934 [$800a9934]
            800A9920	ori    v0, zero, $0004
            800A9924	beq    a0, v0, La9954 [$800a9954]
            800A9928	ori    v0, zero, $0033
            800A992C	j      La9bf8 [$800a9bf8]
            800A9930	addu   v0, zero, zero

            La9934:	; 800A9934
            800A9934	lui    v0, $8006
            800A9938	lw     v0, $3014(v0)
            800A993C	nop
            800A9940	lw     v1, $0090(v0)
            800A9944	lui    a0, $0100

            La9948:	; 800A9948
            800A9948	or     v1, v1, a0

            La994c:	; 800A994C
            800A994C	j      La9bf8 [$800a9bf4]
            800A9950	sw     v1, $0090(v0)

            La9954:	; 800A9954
            800A9954	lui    v1, $8006
            800A9958	lw     v1, $3014(v1)
            800A995C	j      La9bf8 [$800a9bf4]
            800A9960	sw     v0, $0224(v1)

            case 1e:
            {
                power = w[address + c4];
                current_hp = hu[800f5bb8 + A2 * 44 + 3c];
                max_hp = w[800f83e0 + A2 * 68 + 30];

                [address + 48] = w(1 + (((current_hp * 3) / max_hp) * power));

                return 0;
            }
            break;

            case 1f:
            {
                power = w[address + c4];
                current_mp = hu[800f5bb8 + A2 * 44 + 3e];
                max_mp = hu[800f83e0 + A2 * 68 + 2a];

                [address + 48] = w(1 + (((current_mp * 3) / max_mp) * power));

                return 0;
            }
            break;

            case 20:
            {
                funcaa574;
            }
            break;

            case 21:
            {
                power = w[address + c4];
                V0 = w[800f5e60 + A2 * 34 + 0];
                number_of_kills = hu[V0 + 24];

                [address + 48] = w(a + (((number_of_kills / 80) * power) / 10));

                return 0;
            }
            break;

            case 22:
            {
                power = w[address + c4];

                limit_level = bu[800f5e60 + A2 * 34 + 5];
                limit_bar_value = hu[800f5e60 + A2 * 34 + a];

                [address + 48] = w(1 + (((limit_bar_value * (limit_level + 1) / 10) * power) / 10));

                return 0;
            }
            break;

009B0A80 23
            800A9B00	ori    v0, zero, $0003
            800A9B04	beq    a0, v0, La9b1c [$800a9b1c]
            800A9B08	ori    v0, zero, $0004
            800A9B0C	beq    a0, v0, La9b50 [$800a9b50]
            800A9B10	addu   v0, zero, zero
            800A9B14	j      La9bf8 [$800a9bf8]
            800A9B18	nop

            La9b1c:	; 800A9B1C
            800A9B1C	lui    v1, $8006
            800A9B20	lw     v1, $3014(v1)
            800A9B24	nop
            800A9B28	lw     v0, $0230(v1)
            800A9B2C	nop
            800A9B30	andi   v0, v0, $0080
            800A9B34	beq    v0, zero, La9bf8 [$800a9bf8]
            800A9B38	addu   v0, zero, zero
            800A9B3C	lw     v0, $0218(v1)
            800A9B40	nop
            800A9B44	ori    v0, v0, $0001
            800A9B48	j      La9bf8 [$800a9bf4]
            800A9B4C	sw     v0, $0218(v1)

            La9b50:	; 800A9B50
            800A9B50	lui    a2, $8006
            800A9B54	lw     a2, $3014(a2)
            800A9B58	nop
            800A9B5C	lw     a1, $0208(a2)
            800A9B60	nop
            800A9B64	slti   v0, a1, $0004
            800A9B68	bne    v0, zero, La9bf8 [$800a9bf8]
            800A9B6C	addu   v0, zero, zero
            800A9B70	ori    v1, zero, $0001
            800A9B74	lui    a0, $800f
            800A9B78	addiu  a0, a0, $7de0
            800A9B7C	lhu    v0, $0000(a0)
            800A9B80	sllv   v1, a1, v1
            800A9B84	or     v0, v0, v1
            800A9B88	sh     v0, $0000(a0)
            800A9B8C	lw     v0, $0208(a2)
            800A9B90	nop
            800A9B94	sll    v1, v0, $04
            800A9B98	addu   v1, v1, v0
            800A9B9C	sll    v1, v1, $02
            800A9BA0	lui    at, $800f
            800A9BA4	addu   at, at, v1
            800A9BA8	lbu    v0, $5be1(at)
            800A9BAC	nop
            800A9BB0	ori    v0, v0, $0001
            800A9BB4	lui    at, $800f
            800A9BB8	addu   at, at, v1
            800A9BBC	sb     v0, $5be1(at)
            800A9BC0	lui    v0, $8006
            800A9BC4	lw     v0, $3014(v0)
            800A9BC8	nop
            800A9BCC	lw     v1, $0208(v0)
            800A9BD0	nop
            800A9BD4	sll    v0, v1, $01
            800A9BD8	addu   v0, v0, v1
            800A9BDC	sll    v0, v0, $02
            800A9BE0	addu   v0, v0, v1
            800A9BE4	sll    v0, v0, $03
            800A9BE8	lui    at, $8010
            800A9BEC	addu   at, at, v0
            800A9BF0	sw     zero, $8438(at)
        }
    }
}

La9bf8:	; 800A9BF8
return 0;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// battle_copy_status_data_to_temp
status% = A0;
status_mask  = A1;
address = w[80063014];

[address + 80] = w(0);
[address + 84] = w(0);
[address + 88] = w(0);

A3 = status% >> 6;
if (A3 < 3)
{
    V0 = status% & 3f;
    real_status% = V0 << 2;
    if (status_mask < 0)
    {
        V0 = status_mask & 00000003;
        [address + 80] = w(80000000);
        [800f7dc6] = h(V0);
    }
    else
    {
        [address + 8c] = w(real_status%);
        [address + A3 * 4 + 80] = w(status_mask);
    }
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funca8d88
address = w[80063014];
[address + bc] = w(-1);

if (A0 != -1)
{
    [address + bc] = w(A0);
    [address + c0] = w(A1);

    A0 = 2;
    funca8e84;
}

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// battle_copy_target_type_data_to_temp
address = w[80063014];
V1 = w[address + 50];
if (V1 == FF)
{
    [address + 50] = w(A0);
}

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funca2fd0
pos = w[800f3948];

[800fa9d0 + pos * c + 3] = b(-1);

if (pos < 80)
{
    [800f3948] = w(pos + 1);
}
else
{
    A0 = 28;
    func155a4;
}

return 800fa9d0 + pos * c;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcacd88
address = w[80063014];
V0 = w[address + 6c];
if (V0 & 0004)
{
    if (w[800f83e0 + A0 * 68 + 4] & 00000200)
    {
        return 1;
    }
}
else
{
    if (w[800f83e0 + A0 * 68 + 4] & 00000100)
    {
        return 1;
    }
}

return 0;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcad0fc
address   = w[80063014];
target_id = w[address + 208]; // entity_id
V0 = w[address + 220];
A1 = w[address + 214]; // lower formula calculated damage.
if (A1 != 0)
{
    // damage to MP
    if (V0 & 0004)
    {
        A0 = hu[800F83E0 + target_id * 68 + 28];
        A2 = hu[800F83E0 + target_id * 68 + 2A];
        // heal flag
        A3 = V0 & 0001;
        add_sub_with_max_min_bound;
        [800F83E0 + target_id * 68 + 28] = h(V0);
    }
    // damage to HP
    else
    {
        S0 = w[800F83E0 + target_id * 68 + 2C];

        A0 = S0;
        A2 = w[800F83E0 + target_id * 68 + 30];
        // heal flag
        A3 = V0 & 0001;
        add_sub_with_max_min_bound;
        [800F83E0 + target_id * 68 + 2C] = w(V0);

        // if HP now 0 and was not 0
        if (V0 == 0 && S0 != 0)
        {
            // set dead status
            V0 = w[800F83E0 + target_id * 68 + 0];
            V0 = V0 | 00000001;
            [800F83E0 + target_id * 68 + 0] = w(V0);

            V0 = w[address + 90];
            if (V0 & 2000)
            {
                funca2db0;
            }
        }

        // if this is player
        if (target_id < 3)
        {
            V0 = w[address + 0];
            if (V0 >= 4 && S2 == 0)
            {
                A1 = w[address + 204];
                V0 = bu[A1 + 5];
                if (V0 < 4)
                {
                    V0 = bu[800F5BE1 + V1 * 44]
                    V0 = V0 & 0008;
                    if (V0 == 0)
                    {
                        V0 = w[A1 + 1C];
                        A2 = hu[A1 + 8];
                        if (V0 == 0)
                        {
                            A0 = 22;
                            A3 = 0100;
                            func155a4;
                        }
                        else
                        {
                            V1 = w[address + 214];
                            800AD268	lw     a1, $0228(a0)
                            V0 = w[800F83E0 + target_id * 68 + 30];
                            A0 = A1 & 0020;
                            V1 = (V1 * 12C) / V0;

                            800AD29C	beq    a0, zero, Lad2ac [$800ad2ac]
                            800AD2A0	andi   v0, a1, $0010
                            800AD2A4	j      Lad2b8 [$800ad2b8]
                            800AD2A8	ori    a3, zero, $0200

                            Lad2ac:	; 800AD2AC
                            800AD2AC	beq    v0, zero, Lad2bc [$800ad2bc]
                            800AD2B0	mult   v1, a3
                            800AD2B4	ori    a3, zero, $0080

                            Lad2b8:	; 800AD2B8
                            800AD2B8	mult   v1, a3

                            Lad2bc:	; 800AD2BC
                            800AD2BC	lui    v0, $8006
                            800AD2C0	lw     v0, $3014(v0)
                            800AD2C4	nop
                            800AD2C8	lw     a0, $0204(v0)
                            800AD2CC	mflo   v1
                            800AD2D0	lw     v0, $001c(a0)
                            800AD2D4	nop
                            800AD2D8	divu   v1, v0
                            800AD2DC	bne    v0, zero, Lad2e8 [$800ad2e8]
                            800AD2E0	nop
                            800AD2E4	break   $01c00

                            Lad2e8:	; 800AD2E8
                            800AD2E8	mflo   v0
                            800AD2EC	nop
                            800AD2F0	addu   a2, a2, v0
                            800AD2F4	slti   v0, a2, $0100
                            800AD2F8	bne    v0, zero, Lad304 [$800ad304]
                            800AD2FC	nop
                            800AD300	ori    a2, zero, $00ff

                            Lad304:	; 800AD304
                            800AD304	sh     a2, $0008(a0)
                        }
                    }
                }
            }
        }
    }
}

return;
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaa574
address = w[80063014];

total_ap = 0;

V1 = w[address + 0]
T0 = w[800f5e60 + V1 * 34 + 0]; // savemap address

T1 = 0;
loopaa5b8:	; 800AA5B8
    V1 = w[T0 + 40 + T1 * 4];
    ap = V1 >> 8;
    if (V1 != -1)
    {
        A2 = 0;
        materia_id = V1 & ff;

        A1 = 0;
        loopaa5e8:	; 800AA5E8
            V1 = hu[800730d0 + materia_id * 14 + A1 * 2];
            if (V1 != ffff)
            {
                A2 = V1 * 64;
            }

            A1 = A1 + 1;
            V0 = A1 < 4;
        800AA610	bne    v0, zero, loopaa5e8 [$800aa5e8]

        if (A2 < ap)
        {
            ap = A2;
        }

        total_ap = total_ap + ap;
    }

    T1 = T1 + 1;
    V0 = T1 < 8;
800AA634	bne    v0, zero, loopaa5b8 [$800aa5b8]

power = w[address + c4];
[address + 48] = w(1 + (power * (total_ap / 2710) / 10));
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaa4fc
address = w[80063014];

S0 = 1;

A0 = w[address + 0];
funcb10b4;

// if in near death
if (V0 != 0)
{
    S0 = 2;
}

// if death sentense
V0 = w[address + c8];
if (V0 & 00200000)
{
    S0 = S0 * 4;
}

V0 = w[address + 214];
[address + 214] = w(V0 * S0);
////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
// funcb10b4
max_hp = w[800f83e0 + A0 * 68 + 30];
current = w[800f83e0 + A0 * 68 + 2c];
return max_hp / 4 >= current;
/////////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaa468
address = w[80063014];

S1 = w[address + c8];

A0 = w[address + 0];
funcb10b4;

if (V0 != 0)
{
    S1 = S1 | 00000002;
}

// darkness, slow, silence, sadness, poison, near death
A0 = S1 & 0400029a;
count_active_bits;
S0 = V0;

// death sentence, slow-numb
A0 = S1 & 00202000;
count_active_bits;
V0 = V0 * 2;

S0 = S0 + V0;

damage = w[address + 214];
A1 = damage * (S0 + 1);
[address + 214] = w(A1);
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaa688
A1 = 1;

A0 = 0;
loopaa694:	; 800AA694
    V0 = w[800f83e0 + A0 * 68 + 0];
    if (V0 & 00000001)
    {
        A1 = A1 + 1;
    }

    A0 = A0 + 1;
    V0 = A0 < 3;
800AA6BC	bne    v0, zero, loopaa694 [$800aa694]

address = w[80063014];
damage = w[address + 214];
[address + 214] = w(damage * A1);
////////////////////////////////////////////////////



//////////////////////////////////////////////////////
// funcac6b4
V1 = w[800f3014];

if (A0 == 0)
{
    A0 = w[V1 + 228];
    if (A0 & 00000400) // in stop status
    {
        [V1 + 224] = w(30);
    }
    else if (A0 & 00000800) // in frog status
    {
        funca2d0c;

        [V1 + 224] = w(V0);
    }
    else
    {
        [V1 + 224] = w(5);
    }
}
else
{
    V0 = w[V1 + 208];
    if (V0 >= 4)
    {
        [V1 + 224] = w(39);
    }
}
//////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcb1268
A3 = 0;
loopb1284:	; 800B1284
    V0 = A2 >> A3;
    if (V0 & 1)
    {
        V0 = b[800f5bd8 + A0 * 44 + A3];
        V1 = V0 + A1;
        if (V1 >= 65)
        {
            V1 = 64;

        }

        if (V1 < 64)
        {
            V1 = 0 - 64;
        }

        [800f5bd8 + A0 * 44 + A3] = b(V1);
    }

    A3 = A3 + 1;
    V0 = A3 < 8;
800B12CC	bne    v0, zero, loopb1284 [$800b1284]
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaa950
FP = A0;
target_id = b[FP + 0];
address = w[80063014];

// go through left center and right fighters mask and search for target
A0 = 0;
loopaa990:	; 800AA990
    S7 = hu[8016376e + A0 * 2];
    V0 = S7 >> target_id;
    if (V0 & 1)
    {
        break;
    }

    A0 = A0 + 1;
    V0 = A0 < 3;
800AA9B0	bne    v0, zero, loopaa990 [$800aa990]

// if target player, damage != 0, we are not attacking ourself, there is only 1 attack, this is not magical attack
if ((target_id < 3) && (w[address + 48] != 0) && (target_id != w[address + 0]) && (w[address + b8] == 1) && ((w[address + 6c] & 0004) == 0))
{
    V1 = w[address + 80] | w[address + 84] | w[address + 88];
    V0 = V1 & 00000800;
    if (V0 == 0)
    {
        if (w[address + 28] != 20 || w[address + 24] == ff)
        {
            S2 = 0;
            S0 = 0;
            loopaaa60:	; 800AAA60
                V0 = bu[800f5bb8 + S0 * 44 + 29];
                V0 = V0 & 1;
                if (V0 == 0)
                {
                    // select from the same row mask
                    V0 = S7 >> S0;
                    if (V0 & 1)
                    {
                        S1 = bu[8009d84c + S0 * 440 + 1]; // cover modifier
                        if (S1 != 0)
                        {
                            // not self and not attacker
                            if (w[address + 0] != S0 && target_id != S0)
                            {
                                // units to cover must not be in statuses
                                V0 = w[800f83e0 + S0 * 68 + 0] & 86805c45;
                                if (V0 == 0)
                                {
                                    A0 = 64;
                                    func14ba8;
                                    if (V0 < S1)
                                    {
                                        V0 = 1 << S0;
                                        S2 = S2 | V0;
                                    }
                                }
                            }
                        }
                    }
                }

                S0 = S0 + 1;
                V0 = S0 < 3;
            800AAB10	bne    v0, zero, loopaaa60 [$800aaa60]

            A0 = hu[800f83a4 + 18];
            A0 = S2 & A0;
            select_random_bit;

            if (V0 != 0)
            {
                A0 = V0;
                get_last_significant_bit_number;
                [FP + 0] = b(V0);

                [FP + 1] = b(target_id);

                V0 = b[FP + 0];
                [800f83e0 + V0 * 68 + 17] = b(bu[800f83e0 + target_id * 68 + c]);
            }
        }
    }
}
////////////////////////////////////////////////////



//////////////////////////////////////////////////////
// funcac73c
S0 = A0; // target_id

address = w[80063014];

[address + 208] = w(S0);
[address + 20c] = w(-1);
[address + 210] = w(0);
[address + 214] = w(0);
[address + 218] = w(w[address + 90]);
[address + 21c] = w(0);
[address + 220] = w(0);
[address + 224] = w(bu[800f83e0 + S0 * 68 + 56]);
[address + 228] = w(w[800f83e0 + S0 * 68 + 0]);
[address + 230] = w(0);
[address + 234] = w(0);
[address + 238] = w(0);
[address + 23c] = w(0);
[address + 240] = w(0);
[address + 244] = w(0);
[address + 248] = w(-1);
[address + 24c] = w(-1);
[address + 250] = w(-1);
[address + 254] = w(bu[800f83e0 + S0 * 68 + 9]);
[address + 258] = w(w[800f83e0 + S0 * 68 + 2c]); // current hp
[address + 25c] = w(hu[800f83e0 + S0 * 68 + 28]); // current mp
[address + 260] = w(w[address + 3c]);

[address + 200] = w(800f5bb8 + S0 * 44);

if (S0 < 3)
{
    [address + 204] = w(800f5e60 + S0 * 34);
}
else
{
    [address + 204] = w(-1);
}

if (w[address + 48] == 0) // power modifier
{
    [address + 224] = w(33);
}

funcace88;
if (V0 != 0)
{
    A0 = address;
    A2 = address + c;
    [address + 244] = w(0);

    Lac89c:	; 800AC89C
    V0 = w[A0 + 80];
    [A0 + 238] = w(V0);
    if (A0 == address)
    {
        V0 = w[address + 228];
        if (V0 & 00004000)
        {
            [address + 238] = w(0);
        }
    }

    [address + 244] = w(w[address + 244] | w[A0 + 238]);

    A0 = A0 + 4;
    V0 = A0 < A2;
    800AC8D8	beq    v0, zero, Lac914 [$800ac914]

    800AC8E0	j      Lac89c [$800ac89c]
}
else
{
    V0 = w[address + 48];
    if (V0 == 0)
    {
        V0 = w[address + 218];
        V0 = V0 | 0001;
        [address + 218] = w(V0);
    }
}



A0 = w[address + 208];
A1 = 1;
A2 = w[address + 23c];
A2 = A2 & 00000001;
funcaf874; // get immunities
[address + 22c] = w(V0);


A0 = w[address + 6c];
if (A0 & 0400) // if not ignore defense calculation
{
    if (A0 & 0004)
    {
        A1 = hu[800f83e0 + S0 * 68 + 22]; // magic defense
        A2 = 3;
    }
    else
    {
        A1 = hu[800f83e0 + S0 * 68 + 20]; // defense
        A2 = 2;
    }

    A0 = S0;
    funcb1218; // calculate defense
    [address + 210] = w(V0);
}


V0 = w[address + 210];
if (V0 >= 201)
{
    [address + 210] = w(200);
}

if (S0 >= 4)
{
    [address + 20c] = w(h[80163658 + (S0 - 4) * 10]);
}
////////////////////////////////////////////////////



//////////////////////////////////////////////////////
// funcaca24
address = w[80063014];
[address + 214] = w(0);
[address + 230] = w(0);
[address + 238] = w(0);
[address + 23c] = w(0);
[address + 240] = w(0);
[address + 244] = w(0);
//////////////////////////////////////////////////////



//////////////////////////////////////////////////////
// funcace88
// check if we change status or not
address = w[80063014];
V0 = w[address + 0];
S0 = w[address + 8c];
A0 = w[address + 208];
A2 = bu[800f83e0 + V0 * 68 + e]; // magic power
A0 = hu[800f83e0 + A0 * 68 + 22]; // magic defense
A2 = A2 - A0;
V1 = w[address + 80];
V0 = w[address + 84];
A0 = w[address + 88];
S1 = V1 | V0 | A0;

V1 = w[address + 228];
V0 = V1 & 00000800;
if (V0 == S1)
{
    S0 = fc;
}

S2 = 1;
V0 = V1 & 00001000;
if (V0 == S1)
{
    S0 = fc;
}

V0 = w[address + 208];
V0 = V0 < 3;
if(V0 != 0)
{
    V0 = 00900100;
    V0 = S1 & V0;
    if (V0 != 0)
    {
        S0 = fc;
    }
}

if (S0 < fc)
{
    S0 = S0 + S0 * w[address + e8] / 64;

    V0 = w[address + 50];
    if ((V0 & c) != 4)
    {
        V0 = w[address + b8];
        if (V0 >= 2) // number of target
        {
            S0 = S0 * 2 / 3;
        }
    }

    V0 = w[address + ac];
    if (V0 != 0)
    {
        S0 = S0 >> 1;
    }

    A0 = 64;
    func14ba8;
    V0 = V0 & ff;
    V0 = V0 + 1;
    if (V0 >= S0)
    {
        S2 = 0;
    }
}

if (S1 & 1)
{
    V1 = hu[800f7dcc];
    V0 = w[address + 208];
    V1 = V1 >> V0;
    if (V1 & 1)
    {
        S2 = 0;
    }
}

return S2;
//////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaf874
//A0 = w[address + 208]; // target id
//A1 = 1;
//A2 = w[address + 23c]; // remove statuses
//A2 = A2 & 00000001;

A3 = w[800f5bb8 + A0 * 44 + 34]; // status protects

if (bu[800f5bb8 + A0 * 44 + 29] & 08)
{
    A3 = A3 | 00800840; // berserk frog confusion
}

if (A1 != 0)
{
    V1 = w[800f83e0 + A0 * 68];
    if (V1 & 20000000) // resist
    {
        A3 = A3 | 5fffffff; // everything exept imprisoned resist
    }

    if (V1 & 10000000) // death force
    {
        A3 = A3 | 00000001; // death
    }
}

if (w[800f83e0 + A0 * 68] & 01000000) // peerless
{
    A3 = A3 | 7fffffff; // everything exept imprisoned
}

if (A3 & 00000300) // slow or haste
{
    A3 = A3 | 00000300; // slow and haste
}

if (A0 < 3 && A2 != 0) // player and we remove death
{
    A3 = A3 & fffffffe; // remove immune to death
}

if (w[800f83e4 + A0 * 68] & 00001000) // small
{
    A3 = A3 | 00000001; // death
}

if (A3 & 00000001) // death
{
    A3 = A3 | 00200000; // death sentense
}

V0 = w[address + 6c];
V0 = V0 & 0080;
if (V0 == 0)
{
    A3 = 0;
}

return A3;
////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// funca3240
V0 = w[800f3944];
if (V0 != 0)
{
    V0 = V0 - 1;
    [80163798 + V0 * c + 8] = h(-1);
}
//////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcae82c
address = w[80063014];

// statuses to add/remove/change
A1 = 0;
V1 = 0;
loopae854:	; 800AE854
    A1 = A1 | w[address + 80 + V1 * 4];
    V1 = V1 + 1;
    V0 = V1 < 3;
800AE864	bne    v0, zero, loopae854 [$800ae854]



A0 = w[address + 44]; // attack elements
V0 = w[address + c];
V0 = V0 XOR 0004;
V0 = 0 < V0;
[SP + 10] = w(V0);
[SP + 14] = w(w[address + 84] & 00000001); // status to remove
A2 = w[address + 208]; // target entity_id
A3 = SP + 18;
funcae42c;



V0 = w[address + 48]; // power modifier
if (V0 != 0)
{
    V0 = w[SP + 4c]; // null status
    if (V0 != 0)
    {
        [SP + 4c] = w(0);
    }
}

V1 = 0;
S0 = 0;
loopae8dc:	; 800AE8DC
    V0 = w[SP + 18 + V1 * 4];
    if (V0 != 0)
    {
        V0 = V1;
        V0 = V0 >> 3;
        V0 = V0 << 3
        V0 = V1 - V0;
        V0 = 1 << V0;
        S0 = S0 | V0;
    }

    V1 = V1 + 1;
    V0 = V1 < 10;
800AE914	bne    v0, zero, loopae8dc [$800ae8dc]



V0 = w[address + 6c];
if (V0 & 0080)
{
    [address + 230] = w(S0 & ffff);
}
else // Ignore Status Effect Defense when attempting to Inflict 
{
    [address + 230] = w(0);
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcab308
address = w[80063014];

if (w[address + 230] & 40) // absorb
{
    A0 = w[address + 23c];
    [address + 23c] = w(w[address + 238]);
    [address + 238] = w(A0);
    if (A0 & 00000001)
    {
        [address + 238] = w(A0 & fffffffe);
        [address + 230] = w(01);
    }

    A0 = w[address + 23c];
    if (A0 & 00000001)
    {
        [address + 23c] = w(A0 & fffffffe);
        [address + 230] = w(80);
    }
}

if (w[address + 230] & 01) // death
{
    V1 = w[address + a4];
    if (V1  == 3 || V1 == 4)
    {
        A0 = 20;
        func14ba8; // chance 0-20
        V0 = V0 & ff;

        V1 = w[address + 48];
        if (V0 >= V1)
        {
            V0 = w[address + 230] & fe;
            [address + 230] = w(V0 | 20);
        }
    }
}

V0 = w[address + 48];
if (V0 == 0)
{
    if (w[address + 230] & 04) // double
    {
        [address + 260] = w(w[address + 260] << 1);
    }

    if (w[address + 230] & 10) // half
    {
        [address + 260] = w(w[address + 260] >> 1);
    }
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcab480
address = w[80063014];
A0 = w[address + 230];
if (A0 & 40) // absorb
{
    [address + 220] = w(w[address + 220] XOR 0001);
}
else
{
    if (A0 & 04) // double
    {
        [address + 214] = w(w[address + 214] * 2);
    }
    if (A0 & 10) // half
    {
        [address + 214] = w((w[address + 214] + 1) / 2);
    }
}

if (A0 & 01) // death
{
    if (w[address + 228] & 00000001) // target already dead
    {
        [address + 214] = w(0);
        [address + 218] = w(w[address + 218] | 3);
        [address + 230] = w(0);
        [address + 238] = w(0);
        [address + 23c] = w(0);
        [address + 240] = w(0);
        [address + 244] = w(0);
    }
    else
    {
        [address + 218] = w(w[address + 218] & fffffffd);
        [address + 220] = w(w[address + 220] & fffffffe);
        [address + 238] = w(w[address + 238] | 00000001); // status to add
        [address + 23c] = w(w[address + 23c] & fffffffe); // status to remove
        [address + 250] = w(fffffffe);
    }
}
else if (A0 & 80) // recovery
{
    V1 = w[address + 208];
    [800f840c + V1 * 68] = w(w[800f8410 + V1 * 68]);
    [800f8408 + V1 * 68] = h(hu[800f840a + V1 * 68]);

    [address + 218] = w(w[address + 218] & fffffffd);
    [address + 220] = w(1);
    [address + 238] = w(w[address + 238] & fffffffe);
    [address + 250] = w(fffffffd);
}
else
{
    if (A0 & 20) // nullify
    {
        if (w[address + 244] != 0 || (w[address + 44] & 0008) != 0)
        {
            [address + 218] = w(w[address + 218] | 00000001);
        }

        [address + 214] = w(0);
        [address + 230] = w(0);
        [address + 238] = w(0);
        [address + 23c] = w(0);
        [address + 240] = w(0);
        [address + 244] = w(0);
    }
}
////////////////////////////////////////////////////



////////////////////////////////////////////////////
// funcaa6e8
if ((A0 >= 4 && A1 < 4) || (A0 < 4 && A1 >= 4))
{
    return 1;
}

return 0;
////////////////////////////////////////////////////



////////////////////////////////////////////////
// funcaba68
S1 = hu[SP + 10];
S2 = A1; // damage
S3 = A2; // 1f800220 damage flags (heal damage to mp critical)
S0 = b[A0 + 0]; // target id
S4 = A3; // impact sound
funca311c;

[V0 + 2] = h(S2); // damage
[V0 + 4] = h(S3); // 1f800220 damage flags (heal damage to mp critical)
[V0 + 6] = h(w[800f83e0 + S0 * 68 + 2c]); // current hp
[V0 + 8] = h(hu[800f83e0 + S0 * 68 + 28]); // current mp
[V0 + a] = h(S4); // impact sound
[V0 + c] = h(S1);
////////////////////////////////////////////////



//////////////////////////////////////////////////////
// funca311c
V1 = w[800f394c];

[A0 + 3] = b(V1);
V0 = 800f9f3c + V1 * e;
[V0 + 0] = h(b[A0 + 0]); // target id
[V0 + 6] = h(ffff);
[V0 + 8] = h(ffff);

[800f394c] = w((w[800f394c] + 1) & 7f);
//////////////////////////////////////////////////////