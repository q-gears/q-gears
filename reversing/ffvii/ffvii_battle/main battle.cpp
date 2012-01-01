4523 (17699) -> 801B0000 BATTLE/BATTLE.X
4563 (17763) -> 801C0000 BATTLE/BATINI.X
458a (17802) -> 801C0000 BATTLE/SCENE.BIN (part)
init data, after we copy coords for all enemy we load camera data
45f8 (17912) -> 800698F0 STAGE1/CAMDAT0.LZS -> 801A0000
we read field ID and load field after that
48D0 (18640) -> 800698F0 STAGE1/STAGE09.LZS -> 801B0000
6200 (25088) -> 800698F0 ENEMY/ENEMY016.LZS -> 801B0000
755e (30046) -> 800698F0 ENEMY6/SEFFECT.LZS
(80067) -> CLOUD.LZS



////////////////////////////////
// 800A1160
// seems like total battle cycle

// copy party characters
S0 = 0;
loopa1188:	; 800A1188
    [80163790 + S0] = b(bu[8009cbdc + S0]);
    S0 = S0 + 1;
    V0 = S0 < 4;
800A11A8	bne    v0, zero, loopa1188 [$800a1188]



[80062d44 + 01d0] = w(-1); // reset battle error
[800617b8] = w(0);
[8016376a] = h(hu[800707be]); store previous battle result here.

S1 = hu[800707bc]; // battle id
if (S1 != ffff)
{
    FP = 1;

    La1200:	; 800A1200
        [80062f54] = w(S1); // battle to load
        [800707be] = h(0); // battle result

        if (FP != 1)
        {
            S0 = 800a3354;
            S2 = 801b0490;
            S3 = 800b33a4;
        }
        else
        {
            S0 = 0;
            S2 = 801b0050;
            S3 = 800b30e4;
        }

        A0 = 6;
        A1 = 801c0000;
        A2 = 0;
        func14578; // load BATTLE/BATINI.X

        A0 = S0;
        func145bc;

        A0 = 801c0000;
        A1 = 801b0000;
        func15ca0;

        A0 = S1;
        800A1270	jalr   s2 ra // call function where we init datas func1b0050

        800A1278	addu   s0, zero, zero
        800A127C	lui    a1, $800f
        800A1280	addiu  a1, a1, $5bc6
        800A1284	addu   a2, zero, zero
        800A1288	lui    v1, $8010
        800A128C	addiu  v1, v1, $83d0 (=-$7c30)
        800A1290	lhu    v0, $0000(v1)
        800A1294	addu   a0, zero, zero
        800A1298	andi   v0, v0, $fffd
        800A129C	sh     v0, $0000(v1)

        loopa12a0:	; 800A12A0
            800A12A0	lui    at, $8010
            800A12A4	addu   at, at, a2
            800A12A8	lw     v0, $83e0(at)
            800A12AC	addiu  a2, a2, $0068
            800A12B0	addiu  s0, s0, $0001
            V0 = V0 & 0fffffff;
            800A12B8	lui    at, $8016
            800A12BC	addu   at, at, a0
            800A12C0	sw     v0, $36c0(at)
            800A12C4	lui    at, $8016
            800A12C8	addu   at, at, a0
            800A12CC	sw     v0, $36c4(at)
            800A12D0	lbu    v0, $0000(a1)
            800A12D4	addiu  a0, a0, $0010
            800A12D8	ori    v0, v0, $000f
            800A12DC	sb     v0, $0000(a1)
            800A12E0	slti   v0, s0, $000a
            800A12E8	addiu  a1, a1, $0044
        800A12E4	bne    v0, zero, loopa12a0 [$800a12a0]

        800A12EC	jalr   s3 ra // we call function that loads field and camera here (stops when already show start of battle but no anyone take action)

        800A12F0	ori    s0, zero, $0004
        S4 = ff;
        800A12F8	ori    s3, zero, $0110
        800A12FC	ori    s2, zero, $0040
        800A1300	ori    s1, zero, $01a0

        loopa1304:	; 800A1304
            800A1304	lui    at, $8010
            800A1308	addu   at, at, s1
            800A130C	lbu    a1, $842f(at)
            800A1310	nop
            if (A1 != S4)
            {
                A0 = S0;
                funca4b3c;
            }

            800A1324	lui    at, $8016
            800A1328	addu   at, at, s2
            800A132C	lbu    v0, $36bc(at)
            800A1330	addiu  s2, s2, $0010
            800A1334	addiu  s1, s1, $0068
            800A1338	addiu  s0, s0, $0001
            800A133C	lui    at, $800f
            800A1340	addu   at, at, s3
            800A1344	sb     v0, $5be3(at)
            800A1350	addiu  s3, s3, $0044
            800A1348	slti   v0, s0, $000a
        800A134C	bne    v0, zero, loopa1304 [$800a1304]



        S0 = 0;
        loopa135c:	; 800A135C
            if( hu[800f5bb8 + S0 * 44 + 2] != 0 )
            {
                A0 = 0;
                A1 = S0; // unit id
                A2 = 6;
                A3 = 0;
                funca7254;
            }

            S0 = S0 + 1;
            V0 = S0 < 3;
        800A138C	bne    v0, zero, loopa135c [$800a135c]

        [800f83a4 + 22] = h(0);

        S3 = hu[8016375a];

        funca345c;

        // battle cycle
        La13a4:	; 800A13A4
            // if 1 we only execute topest priority (0)
            A0 = (hu[800f83a4 + 22] & 0025) ? 1 : 7;
            funca23e0; // battle queue function
            S4 = V0;



            // priority for ai actions??
            [800f7dde] = h(-1);



            // copy units statuses
            S0 = 0;
            loopa13e0:	; 800A13E0
                [801636b8 + S0 * 10 + 8] = w(w[800f83e0 + S0 * 68 + 00] & 0fffffff);

                S0 = S0 + 1;
                V0 = S0 < a;
            800A1408	bne    v0, zero, loopa13e0 [$800a13e0]



            funca3354;

            funcafecc;

            A0 = 2;
            funca72c8;

            loopa1428:	; 800A1428
                funcaf65c;
            800A1430	bne    v0, zero, loopa1428 [$800a1428]

            A0 = a;
            funca56b0;



            S0 = 0;
            loopa1448:	; 800A1448
                [800f5e60 + S0 * 34 + a] = h(hu[800f5e60 + S0 * 34 + 8]);

                S0 = S0 + 1;
                V0 = S0 < 3;
            800A1468	bne    v0, zero, loopa1448 [$800a1448]



            // copy units statuses
            S0 = 0;
            loopa147c:	; 800A147C
                V0 = w[800f83e0 + S0 * 68];
                V0 = V0 & 0fffffff;
                [801636c0 + S0 * 10] = w(V0);
                [801636c4 + S0 * 10] = w(V0);

                S0 = S0 + 1;
                V0 = S0 < a;
            800A14B0	bne    v0, zero, loopa147c [$800a147c]



            funca345c;

            A0 = 2;
            funca72c8;

            battle_update_unit_mask; // we update unit masks here.

            funca4480;



            S0 = 0;
            if (h[800f7dde] != -1)
            {
                S4 = 0;
            }



            loopa1500:	; 800A1500
                // if info in hud? not equal to "current MP"
                if (hu[800f5e60 + S0 * 34 + 0c] != hu[800F83E0 + S0 * 68 + 28])
                {
                    A0 = 0;
                    A1 = S0;
                    A2 = 0c;
                    A3 = 0f;
                    funca7254;
                }

                [800f5e60 + S0 * 34 + 0c] = h(hu[800F83E0 + S0 * 68 + 28])

                S0 = S0 + 1;
                V0 = S0 < 3;
            800A1538	bne    v0, zero, loopa1500 [$800a1500]



            V0 = hu[800f83a4 + 22];
            A0 = V0 & ffdd;
            [800f83a4 + 22] = h(A0);



            // some petrify check
            V0 = hu[800f7dce]; // petrified units
            V1 = hu[8016375a];
            V0 = 0 NOR V0;
            V1 = V1 & V0;
            if ((V1 & 000f) != 0) // if there are players that not petrified??
            {
                if ((V1 & 03f0) == 0) // and all monsters petrified or dead??
                {
                    [800f83a4 + 22] = h(A0 | 0020);
                }
            }
            else
            {
                [800f83a4 + 22] = h(A0 | 0022);
            }



            if (hu[8016376A] & 0002 && w[8009d268] == 0)
            {
                V0 = hu[800f83a4 + 22];
                V0 = V0 | 0030;
                [800f83a4 + 22] = h(V0);

                V0 = hu[800707be]; // battle result
                V0 = V0 | 0002;
                [800707be] = h(V0);

                V1 = hu[80163624];
                V1 = V1 & fff7;
                [80163624] = h(V1);
            }



            // possibly check to end battle
            if ((hu[800f83a4 + 2c] & 0004) && (bu[800f6b9b] == bu[800f6b94]))
            {
                V0 = hu[8016375a];
                V0 = V0 & S3;
                V1 = V0 & 03f0;
                V0 = S3 & 03f0;
                if (V0 != V1 && V1 != 0)
                {
                    funca4954;

                    if (V0 != 0)
                    {
                        break;
                    }
                }

                S3 = hu[8016375a];
            }

            V1 = hu[800f83a4 + 22];
            if (V1 & 0008)
            {
                break;
            }

        800A166C	beq    v1, zero, La13a4 [$800a13a4]
        800A1674	beq    s4, zero, La13a4 [$800a13a4]



        800A167C	lui    v0, $8016
        800A1680	lhu    v0, $376a(v0)
        800A1684	nop
        800A1688	andi   v0, v0, $0040
        800A168C	beq    v0, zero, La16b0 [$800a16b0]
        800A1690	nop
        V1 = hu[800f83a4 + 22];
        800A169C	andi   v0, v1, $0004
        800A16A0	beq    v0, zero, La16b0 [$800a16b0]
        800A16A4	andi   v0, v1, $fffb
        800A16A8	ori    v0, v0, $0002
        [800f83a4 + 22] = h(V0);

        La16b0:	; 800A16B0
        800A16B0	lui    v0, $8010
        800A16B4	lhu    v0, $83c6(v0)
        800A16B8	nop
        800A16BC	andi   v0, v0, $001e
        800A16C0	bne    v0, zero, La16f0 [$800a16f0]
        800A16C4	ori    s1, zero, $ffff
        800A16C8	lui    v0, $8016
        800A16CC	lhu    v0, $376a(v0)
        800A16D0	lui    s1, $8016
        800A16D4	lhu    s1, $3616(s1)
        800A16D8	andi   v0, v0, $0040
        800A16DC	beq    v0, zero, La16f4 [$800a16f4]
        800A16E0	ori    v0, zero, $ffff
        800A16E4	jal    funca35f8 [$800a35f8]
        800A16E8	nop
        800A16EC	addu   s1, v0, zero

        La16f0:	; 800A16F0
        800A16F0	ori    v0, zero, $ffff

        La16f4:	; 800A16F4
        FP = FP + 1;
    800A16F4	bne    s1, v0, La1200 [$800a1200]

    FP = FP - 1;
}

A0 = 8;
A1 = 801c0000;
A2 = 0;
func14578;

A0 = 800a3354;
func145bc;

A0 = 801c0000;
A1 = 801b0000;
func15ca0;

func1b000;

// copy party back
S0 = 0;
loopa1734:	; 800A1734
    [8009cbdc + S0] = b(bu[80163790 + S0]);
    S0 = S0 + 1;
    V0 = S0 < 4;
800A1754	bne    v0, zero, loopa1734 [$800a1734]

[8009c560] = h(1);

return 1;
////////////////////////////////