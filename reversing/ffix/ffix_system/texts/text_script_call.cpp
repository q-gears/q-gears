////////////////////////////////
// func4ebc0
x_left = h[A0 + 0];
width = h[A0 + 2];
y_top = bu[A0 + 8];
height = h[A0 + 9];

A3 = 8007b9c0;
T0 = A3 + 160;

if (A3 < T0)
{
    loop4ebdc:	; 8004EBDC
        if (h[A3 + 8] != 0)
        {
            if (x_left < h[A3 + 4] + h[A3 + 18])
            {
                if (width + x_left > h[A3 + 4])
                {
                    if (y_top < h[A3 + 6] + bu[A3 + 27])
                    {
                        if (height + y_top > h[A3 + 6])
                        {
                            return 1;
                        }
                    }
                }
            }
        }

        A3 = A3 + 2c;
        V0 = A3 < T0;
    8004EC64	bne    v0, zero, loop4ebdc [$8004ebdc]
}

return 0;
////////////////////////////////



////////////////////////////////
// func38fd8
//    A0 = S1; // script_data
//    A1 = S0; // initial data
//    A2 = -1;
//    A3 = 0;
script = A0;
init_data = A1;
S1 = A2;
S3 = A3;
if (bu[script + 5] == 4) // if model
{
    [script + 8a] = h(hu[8007ae5c]);
    [script + 8c] = h(hu[8007ae60]);
    [script + 8e] = h(hu[8007ae64]);
}

[SP + 10] = h(hu[script + 14]);
[SP + 12] = h(hu[script + 18] + ((h[script + 32] * b[script + 2f]) >> 6) - 32);
[SP + 14] = h(hu[script + 1c]);

if (bu[script + 5] == 4)
{
    [SP + 10] = h(hu[SP + 10] + hu[script + 8a]);
    [SP + 12] = h(hu[SP + 12] + hu[script + 8c]);
    [SP + 14] = h(hu[SP + 14] + hu[script + 8e]);
}

A0 = SP + 10;
A1 = SP + 18; // store X
A2 = SP + 1c; // store Y
system_get_screen_coords_by_vector;
cur_x = w[SP + 18];
cur_y = w[SP + 1c];

if (S1 >= 0)
{
    tar_right = S1 & 1;
    tar_top = (S1 >> 1) & 1;
}
else
{
    A0 = w[8007aecc];

    if (bu[script + 7] == bu[A0 + 16ed])
    {
        A0 = bu[script + 93];
    }
    else
    {
        A0 = bu[A0 + 16ed];
    }

    V0 = w[8007aecc];
    V1 = w[V0 + 16d8];
    if (V1 != 0)
    {
        loop39104:	; 80039104
            V0 = w[V1 + 4];
            if (bu[V0 + 7] == A0)
            {
                break;
            }

            V1 = w[V1];
        80039124	bne    v1, zero, loop39104 [$80039104]
    }

    A0 = 0;
    if (V1 != 0)
    {
        A0 = w[V1 + 4];
    }

    if (A0 != 0)
    {
        [SP + 10] = h(hu[A0 + 14]);
        [SP + 12] = h(hu[A0 + 18] + ((h[A0 + 32] * b[A0 + 2f]) >> 6) - 32);
        [SP + 14] = h(hu[A0 + 1c]);

        if (bu[A0 + 5] == 4)
        {
            [SP + 10] = h(hu[SP + 10] + hu[A0 + 8a]);
            [SP + 12] = h(hu[SP + 12] + hu[A0 + 8c]);
            [SP + 14] = h(hu[SP + 14] + hu[A0 + 8e]);
        }

        A0 = SP + 10;
        A1 = SP + 20;
        A2 = SP + 24;
        system_get_screen_coords_by_vector;
        tar_x = w[SP + 20];
        tar_y = w[SP + 24];

        tar_right = cur_x < tar_x;
        tar_top = cur_y < tar_y;
    }
    else
    {
        tar_right = 0;
        tar_top = 1;
    }
}

if (S3 == 0)
{
    if (tar_right != 0)
    {
        tar_right = cur_x >= 28;
    }
    else
    {
        tar_right = cur_x >= 119;
    }
}



dialog_width = h[init_data + 2]; // width in pixels

if (tar_right != 0)
{
    cur_x = cur_x - 6;

    if (cur_x >= 131)
    {
        cur_x = 130;
    }
    if (cur_x < 20)
    {
        cur_x = 20;
    }

    A0 = cur_x - 18;
    A1 = cur_x - dialog_width + 8;
}
else
{
    cur_x = cur_x + 6;

    if (cur_x >= 121)
    {
        cur_x = 120;
    }
    if (cur_x < 10)
    {
        cur_x = 10;
    }

    A0 = cur_x - 8;
    A1 = cur_x - dialog_width + 18;
}

if (A0 > 138 - dialog_width)
{
    A0 = 138 - dialog_width;
}
if (A1 < 8)
{
    A1 = 8;
}

[init_data + 0] = h((A1 + A0) / 2);



dialog_height = bu[init_data + 9]; // height in pixels

if (tar_top != 0)
{
    V1 = cur_y - dialog_height - 10;
    if (S3 == 0)
    {
        if (V1 < 8)
        {
            tar_top = 0;
            V1 = cur_y + 20;

            if (V1 < 8)
            {
                V1 = 8;
            }
            else if (V1 > d4 - dialog_height)
            {
                V1 = d4 - dialog_height;
            }
        }
        else if (V1 > d4 - dialog_height)
        {
            V1 = d4 - dialog_height;
        }
    }
    else
    {
        if (V1 < 8)
        {
            V1 = 8;
        }
        else if (V1 > d4 - dialog_height)
        {
            V1 = d4 - dialog_height;
        }
    }
    [init_data + 8] = b(V1);
}
else
{
    V1 = cur_y + 20;

    if ((S3 == 0) && (V1 > d4 - dialog_height))
    {
        tar_top = 1;
        V1 = cur_y - dialog_height - 10;
    }

    if (V1 < 8)
    {
        V1 = 8;
    }
    else if (V1 > d4 - dialog_height)
    {
        V1 = d4 - dialog_height;
    }

    [init_data + 8] = b(V1);
}



if (S3 == 0)
{
    A0 = init_data;
    func4ebc0;

    if (V0 != 0)
    {
        tar_top = !tar_top;
        dialog_height = bu[init_data + 9];

        if (tar_top != 0)
        {
            V1 = cur_y - dialog_height - 10;
            if (V1 < 8)
            {
                tar_top = 0;
                V1 = cur_y + 20;
                if (V1 < 8)
                {
                    V1 = 8;
                }
                else if (V1 > d4 - dialog_height)
                {
                    V1 = d4 - dialog_height;
                }
            }
            else if (V1 > d4 - dialog_height)
            {
                V1 = d4 - dialog_height;
            }
        }
        else
        {
            V1 = cur_y + 20;
            if (V1 > d4 - dialog_height)
            {
                tar_top = 1;
                V1 = cur_y - dialog_height - 10;
            }

            if (V1 < 8)
            {
                V1 = 8;
            }
            else if (V1 > d4 - dialog_height)
            {
                V1 = d4 - dialog_height;
            }
        }

        [init_data + 8] = b(V1);
    }
}

[init_data + 4] = h(cur_x - hu[init_data + 0]);
[init_data + 6] = h((tar_top << 1) | tar_right);
return;
////////////////////////////////



////////////////////////////////
// func39660
// text related
script_data = A0;
A0 = A1; // value??
S2 = A2; // style flags
A1 = 8007ae5c;
A2 = 8007ae60;
A3 = 8007ae64;
func4e248; // parse some early 0xf9 opcode settings
S0 = V0; // 8007b940

[S0 + 4] = h(0);
[S0 + 6] = h(0);

if (S2 & 40)
{
    if (h[S0 + 2] < 72)
    {
        [S0 + 2] = h(72);
    }
}

if (S2 & 80)
{
    if (h[S0 + 2] < 1d)
    {
        [S0 + 2] = h(1d);
    }

    A2 = bu[S0 + a];

    if (A2 >= 50 && A2 < 54)
    {
        A2 = A2 & 3;
        A3 = 0;
    }
    else if (A2 < 5c && A2 >= 58)
    {
        A2 = A2 & 3;
        A3 = 1;
    }
    else
    {
        A2 = -1;
        A3 = 0;
    }

    A0 = script_data;
    A1 = S0; // initial data
    func38fd8;
}
else
{
    8003975C	lhu    v0, $0002(s0)
    80039760	lbu    a0, $000a(s0)
    80039764	lbu    a1, $0009(s0)
    80039768	sll    v1, v0, $10
    8003976C	addiu  v0, zero, $0053
    80039770	beq    a0, v0, L397d8 [$800397d8]
    80039774	sra    a2, v1, $10
    80039778	slti   v0, a0, $0054
    8003977C	beq    v0, zero, L397b0 [$800397b0]
    80039780	addiu  v0, zero, $0051
    80039784	beq    a0, v0, L39824 [$80039824]
    80039788	addiu  v0, zero, $000c
    8003978C	slti   v0, a0, $0052
    80039790	beq    v0, zero, L397fc [$800397fc]
    80039794	addiu  v0, zero, $0134
    80039798	beq    a0, zero, L39860 [$80039860]
    8003979C	addiu  v0, zero, $0050
    800397A0	beq    a0, v0, L3984c [$8003984c]
    800397A4	addiu  v0, zero, $0134
    800397A8	j      L39884 [$80039884]


    L397b0:	; 800397B0
    800397B0	addiu  v0, zero, $0055
    800397B4	beq    a0, v0, L397e4 [$800397e4]
    800397B8	slt    v0, a0, v0
    800397BC	bne    v0, zero, L39834 [$80039834]
    800397C0	sra    v0, v1, $11
    800397C4	addiu  v0, zero, $005c
    800397C8	beq    a0, v0, L3980c [$8003980c]
    800397CC	sra    v1, v1, $11
    800397D0	j      L39884 [$80039884]


    L397d8:	; 800397D8
    800397D8	addiu  v0, zero, $000c
    800397DC	j      L3987c [$8003987c]
    800397E0	sh     v0, $0000(s0)

    L397e4:	; 800397E4
    800397E4	sra    v0, v1, $11
    800397E8	addiu  v1, zero, $00a0
    800397EC	subu   v1, v1, v0
    800397F0	addiu  v0, zero, $000c
    800397F4	j      L3987c [$8003987c]
    800397F8	sh     v1, $0000(s0)

    L397fc:	; 800397FC
    800397FC	subu   v0, v0, a2
    80039800	sh     v0, $0000(s0)
    80039804	j      L3987c [$8003987c]
    80039808	addiu  v0, zero, $000c

    L3980c:	; 8003980C
    8003980C	addiu  v0, zero, $00a0
    80039810	subu   v0, v0, v1
    80039814	sra    v1, a1, $01
    80039818	sh     v0, $0000(s0)
    8003981C	j      L39878 [$80039878]
    80039820	addiu  v0, zero, $004a

    L39824:	; 80039824
    80039824	sh     v0, $0000(s0)
    80039828	addiu  v0, zero, $ffd0 (=-$30)
    8003982C	j      L3987c [$8003987c]
    80039830	subu   v0, v0, a1

    L39834:	; 80039834
    80039834	addiu  v1, zero, $00a0
    80039838	subu   v1, v1, v0
    8003983C	addiu  v0, zero, $ffd0 (=-$30)
    80039840	subu   v0, v0, a1
    80039844	j      L3987c [$8003987c]
    80039848	sh     v1, $0000(s0)

    L3984c:	; 8003984C
    8003984C	subu   v0, v0, a2
    80039850	sh     v0, $0000(s0)
    80039854	addiu  v0, zero, $ffd0 (=-$30)
    80039858	j      L3987c [$8003987c]
    8003985C	subu   v0, v0, a1

    L39860:	; 80039860
    80039860	sra    v1, v1, $11
    80039864	addiu  v0, zero, $00a0
    80039868	subu   v0, v0, v1
    8003986C	sra    v1, a1, $01
    80039870	sh     v0, $0000(s0)
    80039874	addiu  v0, zero, $006e

    L39878:	; 80039878
    80039878	subu   v0, v0, v1

    L3987c:	; 8003987C
    8003987C	sb     v0, $0008(s0)
}

L39884:	; 80039884
if (S2 & 04)
{
    if (h[S0 + 2] < 1d)
    {
        [S0 + 2] = h(1d);
    }
}

[S0 + 6] = h(hu[S0 + 6] | (S2 & 30));
return S0;
////////////////////////////////



////////////////////////////////
// func4e248
//A0 = A1; // value??
//A1 = 8007ae5c;
//A2 = 8007ae60;
//A3 = 8007ae64;

S4 = A1;
S5 = A2;
S6 = A3;
A1 = 0;

if (A0 >= 0)
{
    texts_data = w[8007b954];

    if (A0 < w[texts_data + 0]) // index less than number of texts
    {
        A1 = text_datas + 4;

        if (w[8007b708] == 4)
        {
            V0 = A0 * 4;
        }
        else
        {
            V0 = A0 * 8;
        }

        A2 = w[A1 + V0];

        [8007b942] = h(((A2 >> 10) & fff) + 9);

        if (w[8007b708] == 4) // if battle
        {
            V1 = A2 >> 1c;
        }
        else
        {
            V1 = bu[A1 + A0 * 8 + 6]; // number of lines
        }

        [8007b949] = b(V1 * e + 6);

        A1 = A1 + (A2 & ffff); // pointer to text data
    }
}

[SP + 10] = w(A1);

if (A1 != 0)
{
    S3 = 0;
    S1 = SP + 10;

    [8007bb90] = w(0);
    [8007b94a] = b(0);
    [8007b94b] = b(0);
    [S4] = w(0);
    [S5] = w(0);
    [S6] = w(0);

    L4e36c:	; 8004E36C
        V0 = w[SP + 10];
        V1 = bu[V0];
        [SP + 10] = w(V0 + 1);

        if (V1 != f9)
        {
            break;
        }

        V0 = w[S1];
        V1 = bu[V0];
        [S1] = w(V0 + 1);

        if (V1 - 3 >= 5d)
        {
            return 8007b940;
        }

        V0 = w[80011f1c + V1 * 4];

        8004E3C4	jr     v0 

        C8E40480 03
        28E70480 04
        28E70480 05
        28E70480 06
        CCE30480 07
        28E70480 08
        28E70480 09
        28E70480 0a
        F4E50480 0b
        28E70480 0c
        10E60480 0d
        28E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048004E6048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048028E7048004E4048014E5048014E5048014E5048014E5048014E5048014E5048028E7048028E7048014E5048014E5048014E5048014E5048014E5048028E7048028E7048028E50480

        8004E3CC	lw     v1, $0010(sp)
        [8007b960] = w(-1);
        8004E3D8	lbu    a0, $0000(v1)
        8004E3DC	addiu  v0, v1, $0001
        8004E3E0	sw     v0, $0010(sp)
        [8007b95c] = w(A0);
        8004E3E8	lbu    v0, $0001(v1)
        8004E3EC	addiu  v1, v1, $0002
        8004E3F0	sw     v1, $0010(sp)
        8004E3F4	lui    v1, $8008
        8004E3F8	addiu  v0, v0, $ffff (=-$1)
        8004E3FC	j      L4e72c [$8004e72c]
        8004E400	sw     v0, $b96c(v1)
        8004E404	lui    v0, $8008
        8004E408	lw     v1, $b974(v0)
        8004E40C	lw     v0, $0010(sp)
        [8007b960] = w(V1);
        8004E414	lbu    a1, $0000(v0)
        8004E418	addu   a2, v1, zero
        8004E41C	beq    a1, zero, L4e440 [$8004e440]
        8004E420	addiu  v1, a1, $ffff (=-$1)
        8004E424	addiu  a0, zero, $ffff (=-$1)

        loop4e428:	; 8004E428
            8004E428	xori   v0, a2, $0001
            8004E42C	andi   v0, v0, $0001
            8004E430	subu   a1, a1, v0
            8004E43C	sra    a2, a2, $01
            8004E434	addiu  v1, v1, $ffff (=-$1)
        8004E438	bne    v1, a0, loop4e428 [$8004e428]

        L4e440:	; 8004E440
        A2 = w[8007b960];
        8004E444	lw     v0, $0010(sp)
        [8007b95c] = w(A1);
        8004E44C	addu   a0, v0, zero
        8004E450	lbu    v1, $0000(v0)
        8004E454	addiu  v0, a0, $0001
        8004E458	sw     v0, $0010(sp)
        8004E45C	subu   v1, v1, a1
        8004E460	addiu  a1, zero, $ffff (=-$1)
        8004E464	sll    v0, v1, $03
        8004E468	subu   v0, v0, v1
        V1 = bu[8007b949];
        8004E470	sll    v0, v0, $01
        8004E474	subu   v1, v1, v0
        [8007b949] = b(V1);
        8004E47C	lbu    v1, $0001(a0)
        8004E480	addiu  a0, a0, $0002
        8004E484	addu   v1, v1, a1
        8004E488	beq    v1, a1, L4e4a8 [$8004e4a8]
        8004E48C	sw     a0, $0010(sp)
        8004E490	addu   a0, a1, zero

        loop4e494:	; 8004E494
            8004E494	andi   v0, a2, $0001
            8004E498	addu   a1, a1, v0
            8004E49C	addiu  v1, v1, $ffff (=-$1)
            8004E4A4	sra    a2, a2, $01
        8004E4A0	bne    v1, a0, loop4e494 [$8004e494]

        L4e4a8:	; 8004E4A8
        V1 = w[8007b95c];
        8004E4AC	nop
        8004E4B0	slt    v0, a1, v1
        if (V0 == 0)
        {
            8004E4BC	addiu  a1, v1, $ffff (=-$1)
        }

        8004E4B8	lui    v0, $8008
        8004E4C0	j      L4e72c [$8004e72c]
        8004E4C4	sw     a1, $b96c(v0)
        8004E4C8	lw     v0, $0010(sp)
        8004E4CC	nop
        8004E4D0	lbu    a0, $0000(v0)
        8004E4D4	addiu  a1, v0, $0001
        8004E4D8	sw     a1, $0010(sp)
        [8007b940] = h(A0);
        8004E4E0	lbu    v1, $0001(v0)
        8004E4E4	addiu  v0, v0, $0002
        8004E4E8	sw     v0, $0010(sp)
        8004E4EC	sll    v1, v1, $08
        8004E4F0	or     a0, a0, v1
        [8007b940] = h(A0);
        8004E4F8	lbu    v1, $0001(a1)
        8004E4FC	addiu  v0, v0, $0001
        8004E500	sw     v0, $0010(sp)
        8004E504	addiu  v0, zero, $00ff
        [8007b94a] = b(V0);
        [8007b948] = b(V1);
        8004E50C	j      L4e72c [$8004e72c]

        8004E514	lw     v0, $0010(sp)
        8004E518	nop
        8004E51C	lbu    v0, $ffff(v0)
        [8007b94a] = b(V0);
        8004E520	j      L4e72c [$8004e72c]

        8004E528	lw     v0, $0010(sp)
        8004E52C	nop
        8004E530	lbu    v0, $0000(v0)
        8004E534	nop
        8004E538	sw     v0, $0000(s4)
        8004E53C	lw     v1, $0010(sp)
        8004E540	nop
        8004E544	addiu  v0, v1, $0001
        8004E548	sw     v0, $0010(sp)
        8004E54C	lb     v0, $0001(v1)
        8004E550	lw     v1, $0000(s4)
        8004E554	sll    v0, v0, $08
        8004E558	or     v1, v1, v0
        8004E55C	sw     v1, $0000(s4)
        8004E560	lw     v1, $0010(sp)
        8004E564	nop
        8004E568	addiu  v0, v1, $0001
        8004E56C	sw     v0, $0010(sp)
        8004E570	lbu    v0, $0001(v1)
        8004E574	nop
        8004E578	sw     v0, $0000(s5)
        8004E57C	lw     v1, $0010(sp)
        8004E580	nop
        8004E584	addiu  v0, v1, $0001
        8004E588	sw     v0, $0010(sp)
        8004E58C	lb     v0, $0001(v1)
        8004E590	lw     v1, $0000(s5)
        8004E594	sll    v0, v0, $08
        8004E598	or     v1, v1, v0
        8004E59C	sw     v1, $0000(s5)
        8004E5A0	lw     v1, $0010(sp)
        8004E5A4	nop
        8004E5A8	addiu  v0, v1, $0001
        8004E5AC	sw     v0, $0010(sp)
        8004E5B0	lbu    v0, $0001(v1)
        8004E5B4	nop
        8004E5B8	sw     v0, $0000(s6)
        8004E5BC	lw     v1, $0010(sp)
        8004E5C0	nop
        8004E5C4	addiu  v0, v1, $0001
        8004E5C8	sw     v0, $0010(sp)
        8004E5CC	lb     v0, $0001(v1)
        8004E5D0	lw     v1, $0000(s6)
        8004E5D4	sll    v0, v0, $08
        8004E5D8	or     v1, v1, v0
        8004E5DC	sw     v1, $0000(s6)
        8004E5E0	lw     v0, $0010(sp)
        8004E5E4	nop
        8004E5E8	addiu  v0, v0, $0001
        8004E5EC	j      L4e72c [$8004e72c]
        8004E5F0	sw     v0, $0010(sp)
        8004E5F4	lui    v1, $8008
        8004E5F8	addiu  v0, zero, $0001
        8004E5FC	j      L4e72c [$8004e72c]
        8004E600	sw     v0, $bb90(v1)
        8004E604	addiu  v0, zero, $0001
        [8007b94b] = b(V0);
        8004E608	j      L4e72c [$8004e72c]

        8004E610	lw     v1, $0010(sp)
        8004E614	nop
        8004E618	lbu    a0, $0000(v1)
        8004E61C	addiu  v0, v1, $0001
        8004E620	sw     v0, $0010(sp)
        8004E624	sw     a0, $0014(sp)
        8004E628	lbu    v0, $0001(v1)
        8004E62C	addiu  v1, v1, $0002
        8004E630	sw     v1, $0010(sp)
        8004E634	sll    v0, v0, $08
        8004E638	or     a0, a0, v0
        8004E63C	ori    v0, zero, $ffff
        8004E640	beq    a0, v0, L4e72c [$8004e72c]
        8004E644	sw     a0, $0014(sp)

        loop4e648:	; 8004E648
        8004E648	lw     v1, $0014(sp)
        8004E64C	nop
        8004E650	andi   v0, v1, $0fff
        8004E654	sra    v1, v1, $0c
        8004E658	andi   v1, v1, $000f
        8004E65C	beq    v1, zero, L4e67c [$8004e67c]
        8004E660	sw     v0, $0014(sp)
        V0 = w[8007b960];
        8004E668	addiu  v1, v1, $ffff (=-$1)
        8004E66C	srav   v0, v1, v0
        8004E670	andi   v0, v0, $0001
        8004E674	beq    v0, zero, L4e6ac [$8004e6ac]
        8004E678	nop

        L4e67c:	; 8004E67C
        8004E67C	addiu  a0, sp, $0010
        8004E680	jal    func4c2c0 [$8004c2c0]
        8004E684	addiu  a1, sp, $0014
        V0 = h[8007b942];
        8004E68C	lw     v1, $0014(sp)
        8004E690	nop
        8004E694	slt    v0, v0, v1
        8004E698	beq    v0, zero, L4e6e8 [$8004e6e8]
        8004E69C	nop
        8004E6A0	lhu    v0, $0014(sp)
        [8007b942] = h(V0);
        8004E6A4	j      L4e6e8 [$8004e6e8]

        L4e6ac:	; 8004E6AC
        8004E6AC	lw     v0, $0000(s1)
        8004E6B0	nop
        8004E6B4	lbu    v1, $0000(v0)
        8004E6B8	addiu  v0, v0, $0001
        8004E6BC	sw     v0, $0000(s1)
        8004E6C0	addiu  v0, zero, $00ff
        8004E6C4	beq    v1, v0, L4e6e8 [$8004e6e8]
        8004E6C8	addiu  a0, sp, $0010
        8004E6CC	addu   a1, v0, zero

        loop4e6d0:	; 8004E6D0
        8004E6D0	lw     v0, $0000(a0)
        8004E6D4	nop
        8004E6D8	lbu    v1, $0000(v0)
        8004E6DC	addiu  v0, v0, $0001
        8004E6E0	bne    v1, a1, loop4e6d0 [$8004e6d0]
        8004E6E4	sw     v0, $0000(a0)

        L4e6e8:	; 8004E6E8
        8004E6E8	lw     v0, $0010(sp)
        8004E6EC	nop
        8004E6F0	lbu    a0, $0000(v0)
        8004E6F4	addiu  v1, v0, $0001
        8004E6F8	sw     v1, $0010(sp)
        8004E6FC	sw     a0, $0014(sp)
        8004E700	lbu    v1, $0001(v0)
        8004E704	addiu  v0, v0, $0002
        8004E708	sw     v0, $0010(sp)
        8004E70C	ori    v0, zero, $ffff
        8004E710	sll    v1, v1, $08
        8004E714	or     a0, a0, v1
        8004E718	bne    a0, v0, loop4e648 [$8004e648]
        8004E71C	sw     a0, $0014(sp)
        8004E720	j      L4e72c [$8004e72c]
        8004E724	nop

        L4e728:	; 8004E728
        8004E728	addiu  s3, zero, $0001

        L4e72c:	; 8004E72C
    8004E72C	beq    s3, zero, L4e36c [$8004e36c]
}

return 8007b940;
////////////////////////////////



////////////////////////////////
// func2dd00
if (A0 != 0)
{
    if (bu[A0 + 1c] != 0 && bu[A0 + 1c] != 2)
    {
        [A0 + 1c] = b(2);
        if (bu[80087149] != 2)
        {
            A1 = bu[A0 + 28];
            func2d1ac;
        }
    }
}
////////////////////////////////



////////////////////////////////
// func2d1ac
8002D1AC	addu   a2, a0, zero
8002D1B0	beq    a1, zero, L2d1c4 [$8002d1c4]
8002D1B4	sb     a1, $0028(a2)
8002D1B8	addiu  v0, zero, $0004
8002D1BC	bne    a1, v0, L2d250 [$8002d250]
8002D1C0	addiu  v0, zero, $0001

L2d1c4:	; 8002D1C4
8002D1C4	lh     v1, $0004(a2)
8002D1C8	lh     v0, $0012(a2)
8002D1CC	nop
8002D1D0	addu   v1, v1, v0
8002D1D4	addiu  v1, v1, $ffef (=-$11)
8002D1D8	div    v1, v0
8002D200	mflo   v1
8002D204	lh     a0, $0012(a2)
8002D208	lh     v0, $0006(a2)
8002D20C	nop
8002D210	addu   v0, v0, a0
8002D214	addiu  v0, v0, $ffef (=-$11)
8002D218	div    v0, a0
8002D240	mflo   v0
8002D244	sh     v1, $0014(a2)
8002D248	jr     ra 
8002D24C	sh     v0, $0016(a2)


L2d250:	; 8002D250
8002D250	bne    a1, v0, L2d2a4 [$8002d2a4]
8002D254	addiu  v0, zero, $0002
8002D258	lh     v0, $000e(a2)
8002D25C	lh     v1, $0012(a2)
8002D260	nop
8002D264	addu   v0, v0, v1
8002D268	addiu  v0, v0, $ffff (=-$1)
8002D26C	div    v0, v1
8002D294	mflo   v0
8002D298	sh     zero, $0014(a2)
8002D29C	jr     ra 
8002D2A0	sh     v0, $0016(a2)


L2d2a4:	; 8002D2A4
8002D2A4	bne    a1, v0, L2d384 [$8002d384]
8002D2A8	addiu  v0, zero, $0003
8002D2AC	lh     a1, $002a(a2)
8002D2B0	lh     v0, $0012(a2)
8002D2B4	nop
8002D2B8	addu   a1, a1, v0
8002D2BC	addiu  a1, a1, $fff7 (=-$9)
8002D2C0	div    a1, v0
8002D2E8	mflo   a1
8002D2EC	lh     v1, $0004(a2)
8002D2F0	lh     a0, $002a(a2)
8002D2F4	addiu  v1, v1, $ffe8 (=-$18)
8002D2F8	lh     v0, $0012(a2)
8002D2FC	subu   v1, v1, a0
8002D300	addu   v1, v1, v0
8002D304	addiu  v1, v1, $ffff (=-$1)
8002D308	div    v1, v0
8002D330	mflo   v1
8002D334	lh     a0, $0012(a2)
8002D338	lh     v0, $0006(a2)
8002D33C	nop
8002D340	addu   v0, v0, a0
8002D344	addiu  v0, v0, $ffef (=-$11)
8002D348	div    v0, a0
8002D370	mflo   v0
8002D374	sh     a1, $002c(a2)
8002D378	sh     v1, $002e(a2)
8002D37C	jr     ra 
8002D380	sh     v0, $0016(a2)


L2d384:	; 8002D384
8002D384	bne    a1, v0, L2d390 [$8002d390]
8002D388	nop
8002D38C	sb     zero, $001c(a2)

L2d390:	; 8002D390
8002D390	jr     ra 
8002D394	nop
////////////////////////////////



////////////////////////////////
// func2cf20
A3 = A0;
[A3 + 28] = b(A1);
if (A1 == 0)
{
    V0 = h[A3 + 4];
    V1 = h[A3 + 10];
    V0 = V0 + V1;
    V0 = V0 - 11;
    V0 = V0 / V1;

    A0 = h[A3 + 10];
    V1 = h[A3 + 6];
    V1 = V1 + A0;
    V1 = V1 - 11;
    V1 = V1 / A0;
    A1 = fffffffe;

    8002CFB0	and    v0, v0, a1
    8002CFB4	sh     v0, $0014(a3)
    8002CFB8	addu   a0, v0, zero
    8002CFBC	lhu    v0, $0010(a3)
    8002CFC0	nop
    8002CFC4	mult   a0, v0
    8002CFC8	mflo   a2
    8002CFCC	and    v1, v1, a1
    8002CFD0	nop
    8002CFD4	mult   v1, v0
    8002CFD8	sh     v1, $0016(a3)
    8002CFDC	addu   v0, a0, zero
    8002CFE0	sll    v0, v0, $10
    8002CFE4	mflo   a1
    8002CFE8	lhu    v1, $0010(a3)
    8002CFEC	sra    v0, v0, $11
    8002CFF0	mult   v1, v0
    8002CFF4	lhu    v0, $0016(a3)
    8002CFF8	mflo   a0
    8002CFFC	sll    v0, v0, $10
    8002D000	sra    v0, v0, $11
    8002D004	mult   v1, v0
    8002D008	lhu    v0, $0004(a3)
    8002D00C	lhu    v1, $0006(a3)
    8002D010	subu   v0, v0, a2
    8002D014	sh     v0, $000c(a3)
    8002D018	lhu    v0, $0000(a3)
    8002D01C	subu   v1, v1, a1
    8002D020	sh     v1, $000e(a3)
    8002D024	lhu    v1, $0002(a3)
    8002D028	addu   v0, v0, a0
    8002D02C	sh     v0, $0008(a3)
    8002D030	mflo   t4
    8002D034	addu   v1, v1, t4
    8002D038	jr     ra 
    8002D03C	sh     v1, $000a(a3)
}
if (A1 == 4)
{
    8002D04C	lh     v0, $0004(a3)
    8002D050	lh     v1, $0010(a3)
    8002D054	nop
    8002D058	addu   v0, v0, v1
    8002D05C	addiu  v0, v0, $ffef (=-$11)
    8002D060	div    v0, v1
    8002D088	mflo   v0
    8002D08C	nop
    8002D090	andi   v0, v0, $fffe
    8002D094	sh     v0, $0014(a3)
    8002D098	addu   v1, v0, zero
    8002D09C	lhu    v0, $0010(a3)
    8002D0A0	nop
    8002D0A4	mult   v1, v0
    8002D0A8	addu   v0, v1, zero
    8002D0AC	sll    v0, v0, $10
    8002D0B0	mflo   a0
    8002D0B4	lhu    v1, $0010(a3)
    8002D0B8	sra    v0, v0, $11
    8002D0BC	mult   v1, v0
    8002D0C0	lhu    v0, $0006(a3)
    8002D0C4	lhu    v1, $0002(a3)
    8002D0C8	sh     v0, $000e(a3)
    8002D0CC	lhu    v0, $0004(a3)
    8002D0D0	sh     zero, $0016(a3)
    8002D0D4	sh     v1, $000a(a3)
    8002D0D8	lhu    v1, $0000(a3)
    8002D0DC	subu   v0, v0, a0
    8002D0E0	sh     v0, $000c(a3)
    8002D0E4	mflo   a2
    8002D0E8	addu   v1, v1, a2
    8002D0F0	sh     v1, $0008(a3)
}
if (A1 == 1)
{
    V1 = h[A3 + 6] - h[A3 + 6] >> 2;
    V1 = (V1 + h[A3 + 10] - 1) / h[A3 + 10];
    [A3 + 14] = h(0);
    [A3 + 3b] = b(0);
    [A3 + 3a] = h(0);
    [A3 + a] = h(hu[A3 + 2]);
    [A3 + c] = h(hu[A3 + 4]);
    [A3 + e] = h(h[A3 + 6] >> 2);
    [A3 + 8] = h(hu[A3 + 0]);
    [A3 + 16] = h(V1);
}
else if (A1 == 3)
{
    [A3 + 8] = w(w[A3 + 0]);
    [A3 + c] = w(w[A3 + 4]);
    [A3 + 1c] = b(A1);
}
////////////////////////////////



////////////////////////////////
// func2ea7c
S2 = A0;
S0 = A3;

[S0 + 1a] = b(A2);
[S0 + 0] = w(w[S2 + 0]);
[S0 + 4] = w(w[S2 + 4]);
[S0 + 10] = h(7);
[S0 + 12] = h(5);
A2 = 8006bcfc + A2;
[S0 + 1c] = b(1);
[S0 + 23] = b(1);
[S0 + 1d] = b(0);
[S0 + 18] = h(A1);
[S0 + 4c] = w(0);
[S0 + 44] = w(0);
[S0 + 40] = w(0);
[S0 + 48] = w(0);

A0 = S0;
A1 = bu[A2];
func2cf20;

[S0 + 1f] = b((bu[S0 + 1a] XOR 3) < 1);

A0 = S0 + 30;
A1 = 0;
A2 = 0;
A3 = 0;
[SP + 10] = w(h[S2 + 6]);
8002EB2C	jal    func2edfc [$8002edfc]

[S0 + 29] = b(4);
[S0 + 1e] = b(1);
[S0 + 24] = w(0);
[S0 + 2a] = h(0);
return S0;
////////////////////////////////



////////////////////////////////
// func2dcac
if (A3 < a)
{
    A3 = 80077530 + A3 * 54;
    func2ea7c;

    return V0;
}

return 0;
////////////////////////////////



////////////////////////////////
// func4dcec
text_id = A0;
window_id = A1;
init_data = A2;
flags = A3;


// check if this text exist
V1 = 0;
if (text_id >= 0)
{
    A0 = w[8007b954];

    if( text_id < w[A0 + 0] )
    {
        V1 = A0 + 4;

        if (w[8007b708] != 2 && w[8007b708] != 4) // if not battle or battle debriefing
        {
            V0 = (text_id * 8) + 4;
        }
        else
        {
            V0 = text_id * 4;
        }

        V1 = V1 + hu[V1 + V0];
    }
}
if (V1 == 0)
{
    return;
}



S0 = 8007b9c0 + window_id * 2c;



// close window if already opened
if (h[S0 + 8] != 0)
{
    A0 = w[S0 + 14];
    if (A0 != 0)
    {
        func2dd00;
    }

    if( ( w[8007b968] >= 0 ) && ( w[8007b970] == h[S0 + a] ) )
    {
        [80068158] = w(w[8007b99c]);
    }

    if (h[S0 + 8] != 0)
    {
        [S0 + 8] = h(0);

        if (w[8007bb78] == S0)
        {
            [8007bb78] = w(w[S0 + 0]);
        }

        A0 = a;
        loop4de48:	; 8004DE48
            if( ( h[8007b9c0 + V0 * 2c + 8] != 0 ) && ( w[8007b9c0 + V0 * 2c + 0] == S0 ) )
            {
                [8007b9c0 + V0 * 2c + 0] = w(0);
            }

            V0 = V0 + 1;
            V0 = V0 < a;
        8004DE74	bne    v0, zero, loop4de48 [$8004de48]
    }
}



[S0 + 0] = w(w[8007bb78]);

if (h[init_data + 0] != 0)
{
    [S0 + 4] = h(hu[init_data + 0]);
    [S0 + 6] = h(bu[init_data + 8]);
}
else
{
    [S0 + 4] = h(a0 - h[init_data + 2] / 2);
    [S0 + 6] = h(78 - bu[init_data + 9] / 2);
}

[S0 + 8] = h(1);
[S0 + a] = h(window_id);
[S0 + c] = w(8004dad0);
[S0 + 10] = w(0);
[S0 + 14] = w(0);
[S0 + 18] = h(hu[init_data + 2]);
[S0 + 1a] = h(hu[init_data + 4]);
[S0 + 1c] = h(hu[init_data + 2]);
[S0 + 1e] = h(text_id);
[S0 + 20] = h(0);
[S0 + 22] = h(0);
[S0 + 24] = h(8);
[S0 + 26] = b(0);
[S0 + 27] = b(bu[init_data + 9]);
[S0 + 28] = b(10);
[S0 + 2a] = b(0);
[S0 + 2b] = b(bu[init_data + 6]);

V0 = w[8006794c];
V0 = w[V0 + 24];
[S0 + 29] = b(bu[8006e688 + ((V0 >> e) & 7)]);

if (bu[init_data + b] & 1 == 0)
{
    [8007bb78] = w(S0);
}

A2 = 4;
if ((hu[init_data + 6] & 0010) == 0)
{
    A2 = 3;
    if ((h[init_data + 4] == 0 && ((flags & 04) == 0))
    {
        A2 = 2;
    }
}

[SP + 10] = h(hu[S0 + 4]);
[SP + 12] = h(hu[S0 + 6]);
[SP + 14] = h(hu[S0 + 18] + 3);
[SP + 16] = h(bu[S0 + 27] + 3);

A0 = SP + 10;
A1 = 2;
A3 = window_id;
func2dcac;

[S0 + 14] = w(V0);

if (V0 != 0)
{
    [V0 + 50] = w(S0);

    A0 = w[S0 + 14];
    [A0 + 40] = w(8004f5d4);

    A0 = w[S0 + 14];
    [A0 + 44] = w(8004f660);

    A2 = h[init_data + 4];
    if (A2 != 0)
    {
        if ((flags & 04) == 0)
        {
            A0 = w[S0 + 14];
            A1 = hu[init_data + 6] & 3;
            8004E09C	jal    func2d398 [$8002d398]
        }
    }

    if (w[8007bb90] != 0)
    {
        A0 = w[S0 + 14];
        A1 = 3;
        8004E0BC	jal    func2cf20 [$8002cf20]
    }

    if (flags & 40)
    {
        A0 = w[S0 + 14];
        [A0 + 20] = h(6);
        [A0 + 22] = b(-3);
        [A0 + 24] = w(80011efc);
    }
    else if (flags & 08)
    {
        A0 = w[S0 + 14];
        [A0 + 20] = h(6);
        [A0 + 22] = b(-3);
        [A0 + 24] = w(80011f10);
    }
}



if ((bu[init_data + b] & 01) == 0)
{
    A1 = w[8007bb94];
    [8007b968] = w(-1);
    [8007b970] = w(window_id);
    [8007bb94] = w(0);
    [8007b958] = w(A1);
}

[8007bbc8] = w(w[8007bbc8] + 1)

A0 = 0;
8004E144	jal    func4ff98 [$8004ff98]
////////////////////////////////



////////////////////////////////
// func4d2c0
8004D2C8	addu   s1, a0, zero
8004D2E8	lh     v0, $0020(s1)
8004D2EC	addu   s5, a1, zero
8004D2F0	addu   v0, s5, v0
8004D2F4	sw     v0, $0018(sp)
8004D2F8	lbu    v1, $0026(s1)
8004D2FC	nop
8004D300	bne    v1, zero, L4d628 [$8004d628]
8004D304	addu   s3, v0, zero
8004D308	lbu    v0, $002a(s1)
8004D30C	nop
8004D310	bne    v0, zero, L4d618 [$8004d618]
8004D314	lui    v0, $8007
8004D318	addiu  s2, sp, $0018
8004D31C	addiu  s6, v0, $e688 (=-$1978)
8004D320	lui    s4, $8008

L4d324:	; 8004D324
    V0 = h[S1 + 24] + 8;

    8004D330	bne    v0, zero, L4d618 [$8004d618]

    S3 = w[SP + 18];
    V0 = bu[S3]; // 8004d340 : LBU     00000000 (v0), 0000 (800d1fc3 (s3)) [800d1fc3]
    [SP + 18] = w(S3 + 1);

    V1 = V0 - f7;
    8004D350	sw     v0, $001c(sp)
    8004D354	sltiu  v0, v1, $0009
    8004D358	beq    v0, zero, L4d5d4 [$8004d5d4]
    8004D35C	lui    v0, $8001
    8004D360	addiu  v0, v0, $1cb4
    8004D364	sll    v1, v1, $02
    8004D368	addu   v1, v1, v0
    8004D36C	lw     v0, $0000(v1)
    8004D370	nop
    8004D374	jr     v0 
    8004D378	nop

    8004D37C	lw     v0, $0018(sp)
    8004D380	nop
    8004D384	lbu    v1, $0000(v0)
    8004D388	addiu  v0, v0, $0001
    8004D38C	sw     v0, $0018(sp)
    8004D390	sltiu  v0, v1, $0088
    8004D394	beq    v0, zero, L4d5f8 [$8004d5f8]
    8004D398	sw     v1, $001c(sp)
    8004D39C	lui    v0, $8001
    8004D3A0	addiu  v0, v0, $1cdc
    8004D3A4	sll    v1, v1, $02
    8004D3A8	addu   v1, v1, v0
    8004D3AC	lw     v0, $0000(v1)
    8004D3B0	nop
    8004D3B4	jr     v0 
    8004D3B8	nop

    8004D3BC	addiu  a0, sp, $0018
    8004D3C0	lw     v0, $0018(sp)
    8004D3C4	addiu  a1, sp, $001c
    8004D3C8	addiu  v0, v0, $0002
    8004D3CC	jal    func4c2c0 [$8004c2c0]
    8004D3D0	sw     v0, $0018(sp)
    8004D3D4	j      L4d5f8 [$8004d5f8]
    8004D3D8	nop
    8004D3DC	lbu    v0, $0028(s1)
    8004D3E0	nop
    8004D3E4	andi   v0, v0, $0004
    8004D3E8	beq    v0, zero, L4d40c [$8004d40c]
    8004D3EC	nop
    8004D3F0	j      L4d58c [$8004d58c]
    8004D3F4	nop
    8004D3F8	lbu    v0, $0028(s1)
    8004D3FC	nop
    8004D400	andi   v0, v0, $00fb
    8004D404	ori    v0, v0, $0008
    8004D408	sb     v0, $0028(s1)

    L4d40c:	; 8004D40C
    8004D40C	lw     v0, $0000(s2)
    8004D410	nop
    8004D414	lbu    v1, $0000(v0)
    8004D418	addiu  v0, v0, $0001
    8004D41C	sb     v1, $0026(s1)
    8004D420	j      L4d5f8 [$8004d5f8]
    8004D424	sw     v0, $0000(s2)
    8004D428	lw     v0, $0000(s2)
    8004D42C	nop
    8004D430	lbu    v1, $0000(v0)
    8004D434	addiu  v0, v0, $0001
    8004D438	sb     v1, $0029(s1)
    8004D43C	j      L4d5f8 [$8004d5f8]
    8004D440	sw     v0, $0000(s2)
    8004D444	lui    v0, $8006
    8004D448	lw     v0, $794c(v0)
    8004D44C	nop
    8004D450	lw     v0, $0024(v0)
    8004D454	nop
    8004D458	srl    v0, v0, $0e
    8004D45C	andi   v0, v0, $0007
    8004D460	addu   v0, v0, s6
    8004D464	lbu    v0, $0000(v0)
    8004D468	j      L4d5f8 [$8004d5f8]
    8004D46C	sb     v0, $0029(s1)
    8004D470	lbu    v0, $0028(s1)
    8004D474	nop
    8004D478	ori    v0, v0, $0004
    8004D47C	j      L4d5f8 [$8004d5f8]
    8004D480	sb     v0, $0028(s1)
    8004D484	lw     v0, $0018(sp)
    8004D488	nop
    8004D48C	addiu  v0, v0, $0002
    8004D490	j      L4d5f8 [$8004d5f8]
    8004D494	sw     v0, $0018(sp)
    8004D498	lui    a0, $8008
    8004D49C	lui    v0, $8001
    8004D4A0	addiu  t1, v0, $1a6c
    8004D4A4	lwl    a2, $0003(t1)
    8004D4A8	lwr    a2, $0000(t1)
    8004D4AC	nop
    8004D4B0	swl    a2, $0013(sp)
    8004D4B4	swr    a2, $0010(sp)
    8004D4B8	lui    v0, $8008
    8004D4BC	lw     s0, $bb7c(v0)
    8004D4C0	jal    func19750 [$80019750]
    8004D4C4	addiu  a0, a0, $b99c (=-$4664)
    8004D4C8	jal    func19774 [$80019774]
    8004D4CC	addiu  a0, sp, $0010
    8004D4D0	lui    v0, $8008
    8004D4D4	sw     s0, $b968(v0)
    8004D4D8	lbu    v0, $0028(s1)
    8004D4DC	nop
    8004D4E0	ori    v0, v0, $0002
    8004D4E4	j      L4d5f8 [$8004d5f8]
    8004D4E8	sb     v0, $0028(s1)
    8004D4EC	addiu  v0, zero, $00ff
    8004D4F0	sb     v0, $0026(s1)
    8004D4F4	lbu    v0, $0028(s1)
    8004D4F8	nop
    8004D4FC	ori    v0, v0, $0040
    8004D500	j      L4d5f8 [$8004d5f8]
    8004D504	sb     v0, $0028(s1)
    8004D508	lbu    v0, $0028(s1)
    8004D50C	nop
    8004D510	ori    v0, v0, $0008
    8004D514	j      L4d5f8 [$8004d5f8]
    8004D518	sb     v0, $0028(s1)
    8004D51C	lw     v0, $0000(s2)
    8004D520	nop
    8004D524	lbu    v1, $0000(v0)
    8004D528	addiu  v0, v0, $0001
    8004D52C	sw     v1, $bbd8(s4)
    8004D530	j      L4d5f8 [$8004d5f8]
    8004D534	sw     v0, $0000(s2)
    8004D538	lw     v0, $bbd8(s4)
    8004D53C	nop
    8004D540	addiu  v0, v0, $0001
    8004D544	j      L4d5f8 [$8004d5f8]
    8004D548	sw     v0, $bbd8(s4)
    8004D54C	lw     v0, $0018(sp)
    8004D550	nop
    8004D554	addiu  v0, v0, $0001
    8004D558	sw     v0, $0018(sp)
    8004D55C	lw     v0, $0018(sp)
    8004D560	nop
    8004D564	addiu  v0, v0, $0001
    8004D568	sw     v0, $0018(sp)
    8004D56C	lbu    v0, $0028(s1)
    8004D570	nop
    8004D574	andi   v0, v0, $0004
    8004D578	bne    v0, zero, L4d5f8 [$8004d5f8]
    8004D57C	addiu  v0, zero, $0001
    8004D580	sb     v0, $002a(s1)
    8004D584	j      L4d5f8 [$8004d5f8]
    8004D588	sh     zero, $0024(s1)

    L4d58c:	; 8004D58C
    8004D58C	lw     v0, $0018(sp)
    8004D590	nop
    8004D594	addiu  v0, v0, $0001
    8004D598	j      L4d5f8 [$8004d5f8]
    8004D59C	sw     v0, $0018(sp)
    8004D5A0	addiu  v0, zero, $00ff
    8004D5A4	j      L4d5f8 [$8004d5f8]
    8004D5A8	sb     v0, $0026(s1)
    8004D5AC	lui    v1, $8008
    8004D5B0	lw     v0, $bb7c(v1)
    8004D5B4	nop
    8004D5B8	addiu  v0, v0, $0001
    8004D5BC	j      L4d5f8 [$8004d5f8]
    8004D5C0	sw     v0, $bb7c(v1)
    8004D5C4	lw     v0, $0018(sp)
    8004D5C8	nop
    8004D5CC	addiu  v0, v0, $0001
    8004D5D0	sw     v0, $0018(sp)

    L4d5d4:	; 8004D5D4
    8004D5D4	lbu    v0, $0028(s1)
    8004D5D8	nop
    8004D5DC	andi   v0, v0, $0004
    8004D5E0	bne    v0, zero, L4d5f8 [$8004d5f8]
    8004D5E4	nop
    8004D5E8	lhu    v0, $0024(s1)
    8004D5EC	nop
    8004D5F0	addiu  v0, v0, $fff8 (=-$8)
    8004D5F4	sh     v0, $0024(s1)

    L4d5f8:	; 8004D5F8
    8004D5F8	lbu    v0, $0026(s1)
    8004D5FC	nop
    8004D600	bne    v0, zero, L4d63c [$8004d63c]
    8004D604	subu   v0, s3, s5
    8004D608	lbu    v0, $002a(s1)
    8004D60C	nop
8004D610	beq    v0, zero, L4d324 [$8004d324]
8004D614	nop

L4d618:	; 8004D618
8004D618	lbu    v0, $0026(s1)
8004D61C	nop
8004D620	beq    v0, zero, L4d630 [$8004d630]
8004D624	nop

L4d628:	; 8004D628
8004D628	j      L4d63c [$8004d63c]
8004D62C	subu   v0, s3, s5

L4d630:	; 8004D630
8004D630	lw     v0, $0018(sp)
8004D634	nop
8004D638	subu   v0, v0, s5

L4d63c:	; 8004D63C
8004D63C	lbu    v1, $0026(s1)
8004D640	sh     v0, $0020(s1)
8004D644	addiu  v0, zero, $00ff
8004D648	bne    v1, v0, L4d660 [$8004d660]
8004D64C	nop
8004D650	lbu    v0, $0028(s1)
8004D654	nop
8004D658	andi   v0, v0, $00fb
8004D65C	sb     v0, $0028(s1)

L4d660:	; 8004D660
8004D660	lbu    v1, $0029(s1)
8004D664	lhu    v0, $0024(s1)
8004D668	nop
8004D66C	addu   v0, v0, v1
8004D670	sh     v0, $0024(s1)
////////////////////////////////