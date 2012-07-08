////////////////////////////////
// func1ccb4
V0 = w[8006794c];
V0 = w[V0 + 10];
[V0 + 75] = b(A0);
[V0 + 76] = b(A1);
[V0 + 77] = b(A2);
[V0 + 19] = b(A0);
[V0 + 1a] = b(A1);
[V0 + 1b] = b(A2);
////////////////////////////////



////////////////////////////////
// func1cfb4
V0 = w[8006794c];
V0 = w[V0 + 1c];
if( V0 != 0 )
{
    A0 = 0;
    func15c58;

    V1 = w[8006794c];
    V0 = w[V1 + 1c];
    frame_id = bu[V0 + 8]; // frame buffer index
    A0 = w[V1 + c] + frame_id * 14;
    8001D00C	jal    func138d4 [$800138d4]

    S1 = 0;
    A0 = 80073c88;
    V1 = w[8006794c];
    A1 = w[V1 + 10] + (frame_id ^ 1) * 5c;
    A2 = 5c;
    8001D04C	jal    func1d0f8 [$8001d0f8]

    8001D054	jal    func2f800 [$8002f800]

    8001D05C	andi   v0, v0, $00ff
    8001D060	bne    v0, zero, L1d07c [$8001d07c]
    8001D064	nop
    8001D068	jal    func2f810 [$8002f810]
    8001D06C	nop
    8001D070	andi   v0, v0, $00ff
    8001D074	beq    v0, zero, L1d080 [$8001d080]
    8001D078	nop

    L1d07c:	; 8001D07C
    S1 = 1;

    L1d080:	; 8001D080
    8001D080	jal    func2f864 [$8002f864]
    8001D084	nop
    8001D088	addiu  a0, sp, $0010
    8001D08C	jal    func2f9a8 [$8002f9a8]
    8001D090	addu   s0, v0, zero
    8001D094	beq    s1, zero, L1d0cc [$8001d0cc]
    8001D098	lui    v0, $8007
    8001D09C	bne    s0, zero, L1d0cc [$8001d0cc]
    8001D0A0	lui    v1, $8007
    8001D0A4	addiu  v1, v1, $3c88
    8001D0A8	lbu    a0, $0010(sp)
    8001D0AC	lbu    a1, $0011(sp)
    8001D0B0	lbu    a2, $0012(sp)
    8001D0B4	addiu  v0, zero, $0001
    8001D0B8	sb     v0, $0018(v1)
    8001D0BC	sb     a0, $0019(v1)
    8001D0C0	sb     a1, $001a(v1)
    8001D0C4	j      L1d0d0 [$8001d0d0]
    8001D0C8	sb     a2, $001b(v1)

    L1d0cc:	; 8001D0CC
    8001D0CC	sb     zero, $3ca0(v0)

    L1d0d0:	; 8001D0D0
    A0 = 80073c88;
    8001D0D4	jal    func13708 [$80013708]

    A0 = 0;
    8001D0DC	jal    func130a4 [$800130a4]
}
////////////////////////////////



////////////////////////////////
// func12ad4
if( b[80071e32] == 0 )
{
    return 0;
}
else if( b[80071e32] == 1 )
{
    return 1;
}
else if( b[80071e32] >= 2 )
{
    V1 = 1;

    if( w[80071e34] > 0 )
    {
        V1 = V1 | 2;
    }

    if( b[80071e31] != 0 )
    {
        V1 = V1 | 4;
    }

    if( b[80071e30] == 1 )
    {
        V1 = V1 | 8;
    }

    if( b[80071e38] != 0 )
    {
        V1 = V1 | 10;
    }

    return V1;
}
////////////////////////////////



////////////////////////////////
// system_set_gte_ofx_ofy
OFX = A0 << 10;
OFY = A1 << 10;
////////////////////////////////



////////////////////////////////
// system_get_pointer_to_first_element_in_script_list
V1 = w[8007aecc];
if( V1 != 0 )
{
    return w[V1 + 16d8];
}

return 0;
////////////////////////////////



////////////////////////////////
// func32140
80032140	lui    t0, $8006
80032144	lw     a2, $794c(t0)
80032150	lw     v0, $001c(a2)
80032154	nop
80032158	lw     v0, $0000(v0)
8003215C	nop
80032160	andi   v0, v0, $0001
80032164	bne    v0, zero, L32228 [$80032228]
80032168	lui    a3, $8007
8003216C	addiu  v1, a3, $7db0
80032170	lbu    v0, $0005(v1)
80032174	nop
80032178	bne    v0, zero, L32228 [$80032228]
8003217C	nop
80032180	lbu    v0, $7db0(a3)
80032184	nop
80032188	bne    v0, zero, L32228 [$80032228]
8003218C	sltiu  v0, a0, $0009
80032190	beq    v0, zero, L32228 [$80032228]
80032194	addiu  v0, zero, $0001
80032198	sb     v0, $0005(v1)
8003219C	sb     a0, $0001(v1)
800321A0	sw     a1, $000c(v1)
800321A4	sw     zero, $001c(v1)
800321A8	sb     zero, $0006(v1)
800321AC	sb     zero, $0007(v1)
800321B0	sb     v0, $0009(v1)
800321B4	sb     v0, $000a(v1)
800321B8	sb     v0, $000b(v1)
800321BC	sw     zero, $0024(v1)
800321C0	sb     v0, $7db0(a3)
800321C4	lbu    v1, $0008(a2)
800321C8	addiu  v0, zero, $0001
if (V1 == 1)
{
    800321D4	lw     v0, $001c(a2)
    800321D8	nop
    800321DC	lw     v1, $08e4(v0)
    800321E0	nop
    800321E4	lw     v0, $0000(v1)
    800321E8	nop
    800321EC	ori    v0, v0, $1000
    800321F0	sw     v0, $0000(v1)
}

800321F4	lw     v0, $794c(t0)
800321F8	nop
800321FC	lw     v1, $001c(v0)
80032200	nop
80032204	lw     v0, $0000(v1)
80032208	nop
8003220C	ori    v0, v0, $0002
80032210	jal    func35430 [$80035430]
80032214	sw     v0, $0000(v1)
80032218	jal    func326b0 [$800326b0]
8003221C	nop
80032220	jal    func32980 [$80032980]
80032224	nop

L32228:	; 80032228
////////////////////////////////



////////////////////////////////
// func4ecc4
V1 = -1;

A1 = w[8007b960];
A0 = w[8007b958];


loop4ecd8:	; 8004ECD8
    if (A0 < 0)
    {
        break;
    }

    A0 = A0 - (A1 & 1);

    A1 = A1 >> 1;
    V1 = V1 + 1;
    V0 = V1 < f;
8004ECF0	bne    v0, zero, loop4ecd8 [$8004ecd8]

return V1;
////////////////////////////////



////////////////////////////////
// func32120
func32140;
////////////////////////////////



////////////////////////////////
// func4f058
if (A0 >= 0)
{
    A1 = w[8007b954];
    V0 = w[A1];
    if (A0 < V0)
    {
        A1 = w[8007b708];
        V1 = A1 + 4;
        
        V0 = A0 * 4;
        if (A1 != 2)
        {
            if (A1 != 4)
            {
                V0 = (A0 * 8) | 4;
            }
            else
            {
                V0 = A0 * 4;
            }
        }

        return V1 + hu[V1 + V0];
    }
}

return 0;
////////////////////////////////



////////////////////////////////
// func333b0
character_id = A0;
preset_id = A2;
S3 = A1;

V1 = w[8006794c];
data = w[V1 + 1c];
S0 = data + 3c + character_id * 90;

if (preset_id != ff)
{
    A0 = 0;
    loop33418:	; 80033418
        [S0 + 39 + A0] = b(bu[8006cad8 + preset_id * 5 + A0]);
        A0 = A0 + 1;
        V0 = A0 < 5;
    80033430	bne    v0, zero, loop33418 [$80033418]
}

A0 = w[S0 + 34] & f;
A1 = (bu[S0 + a] >> 4) & 1;
A2 = S0 + 39;
func33280;

[S0 + 34] = w((w[S0 + 34] & fffffe0f) | ((V0 & 1f) << 4));

if (S3 == 0)
{
    if (preset_id != ff)
    {
        [SP + 20] = h(hu[S0 + 10]);
        [SP + 22] = h(hu[S0 + 12]);
        [SP + 10] = w(w[S0 + 2c]);
        [SP + 14] = w(w[S0 + 30]);
        [SP + 24] = w(w[S0 + 39]); // equipment
        [SP + 28] = b(b[S0 + 3d]); // equipment
        [SP + 18] = w(w[S0 + 88]);
        [SP + 1c] = w(w[S0 + 8c]);

        A0 = SP + 10;
        A1 = SP + 30;
        800335DC	jal    func32e84 [$80032e84]

        [S0 + 10] = h(hu[SP + 30]);
        [S0 + 12] = h(hu[SP + 32]);
        [S0 + 18] = h(hu[SP + 34]);
        [S0 + 1a] = h(hu[SP + 36]);
        [S0 + 24] = b(bu[SP + 38]);
        [S0 + 25] = b(bu[SP + 39]);
        [S0 + 26] = b(bu[SP + 3a]);
        [S0 + 27] = b(bu[SP + 3b]);
        [S0 + 28] = b(bu[SP + 3e]);
        [S0 + 29] = b(bu[SP + 40]);
        [S0 + 2a] = b(bu[SP + 42]);
        [S0 + 2b] = b(bu[SP + 44]);
    }
}
else
{
    A1 = 0;
    A3 = 0;
    A0 = 0;
    loop334a4:	; 800334A4
        if (character_id != A0)
        {
            if ((w[data + 3c + A0 * 90 + 34] >> b) & 1)
            {
                A1 = A1 + 1;
                A3 = A3 + bu[data + 3c + A0 * 90 + b]; // level
            }
        }

        A0 = A0 + 1;
        V0 = A0 < 9;
    800334E4	bne    v0, zero, loop334a4 [$800334a4]

    if (A1 != 0)
    {
        A1 = A3 / A1;
    }
    else
    {
        A1 = 1;
    }

    if ((((w[S0 + 34] >> 4) & 1f) - a) >= 2)
    {
        if (A1 < bu[S0 + b]) // level
        {
            A1 = bu[S0 + b];
        }
    }

    A0 = character_id;
    A2 = 0;
    A3 = A2;
    8003356C	jal    func32c4c [$80032c4c]
}
////////////////////////////////



////////////////////////////////
// func33280
A1 = A1 != 0;

weapon_id = bu[A2]; // weapon id

A1 = bu[8006caa4 + A0 * 2 + A1];

if (A1 >= c)
{
    return -1;
}

V0 = w[80010cf4 + A1 * 4];

A0 = bu[80069018 + weapon_id * 12 + 8];
800332E0	jr     v0 

FC320380 2
38330380 3
40330380 4
48330380 5
50330380 6
64330380 7
6C330380 8
74330380 9
7C330380 a
A0330380 b

case 0: // E8320380
{
    V0 = A0 XOR 1;
    return 0 < V0;
}
break;

case 1: // F4320380
{
    return 2;
}
break;

800332FC	lui    v0, $8008
80033300	lhu    v0, $aef0(v0)
80033304	nop
80033308	sltiu  v0, v0, $283c
8003330C	bne    v0, zero, L33328 [$80033328]
80033310	addiu  v0, zero, $0007
80033314	bne    a0, v0, L33320 [$80033320]
80033318	addiu  v1, zero, $0005
8003331C	addiu  v1, zero, $0006

L33320:	; 80033320
80033320	jr     ra 
80033324	addu   v0, v1, zero


L33328:	; 80033328
80033328	bne    a0, v0, L33320 [$80033320]
8003332C	addiu  v1, zero, $0003
80033330	j      L33320 [$80033320]
80033334	addiu  v1, zero, $0004
80033338	jr     ra 
8003333C	addiu  v0, zero, $0007

80033340	jr     ra 
80033344	addiu  v0, zero, $000c

80033348	jr     ra 
8003334C	addiu  v0, zero, $0009

80033350	addiu  v0, zero, $0007
80033354	bne    a0, v0, L33320 [$80033320]
80033358	addiu  v1, zero, $000a
8003335C	j      L33320 [$80033320]
80033360	addiu  v1, zero, $000b
80033364	jr     ra 
80033368	addiu  v0, zero, $000d

8003336C	jr     ra 
80033370	addiu  v0, zero, $000e

80033374	jr     ra 
80033378	addiu  v0, zero, $000f

8003337C	lui    v0, $8008
80033380	lhu    v0, $aef0(v0)
80033384	nop
80033388	addiu  v0, v0, $fa24 (=-$5dc)
8003338C	sltiu  v0, v0, $0064
80033390	beq    v0, zero, L33320 [$80033320]
80033394	addiu  v1, zero, $0010
80033398	j      L33320 [$80033320]
8003339C	addiu  v1, zero, $0011
800333A0	jr     ra 
800333A4	addiu  v0, zero, $0012
////////////////////////////////



////////////////////////////////
// func53960
if ((bu[A0 + 38] & A1) == 0)
{
    return 1;
}
else
{
    [A0 + 38] = b(bu[A0 + 38] & (0 NOR A1));
    return 2;
}
////////////////////////////////



////////////////////////////////
// func33af4
V0 = w[8006794c];
data = w[V0 + 1c];

party_slot = A0;
character_id = A1;

prev = w[data + 54c + party_slot * 4];

if (character_id >= 9)
{
    character_id = -1;
}

if (character_id < 0)
{
    [data + 54c + party_slot * 4] = w(0);
}
else
{
    A0 = character_id;
    func33bd0;

    [data + 54c + party_slot * 4] = w(data + 3c + character_id * 90);
}

if (prev != w[data + 54c + party_slot * 4])
{
    [80077de0] = b(1);
}
////////////////////////////////



////////////////////////////////
// func33bd0
if (A0 < 9)
{
    V1 = w[8006794c];
    V1 = w[V1 + 1c];
    [V1 + 3c + A0 * 90 + 34] = w(w[V1 + 3c + A0 * 90 + 34] | 00000800);
}
////////////////////////////////



////////////////////////////////
// func1e350
V1 = w[8006794c];
V1 = w[V1 + 1c];

if (A0 >= 9)
{
    V1 = w[V1 + 8e0];
    V0 = A0 * 14 - b4;
}
else
{
    V1 = w[V1 + 8d8];
    V0 = A0 * 14;
}
return V1 + V0;
////////////////////////////////



////////////////////////////////
// func1e2ac
A1 = w[8006794c];

if (bu[A1 + 8] == 1) // field
{
    V0 = w[A1 + 1c];
    V0 = w[V0 + 8e4];
    V0 = w[V0 + c];
    V0 = w[V0 + 14];
    [V0 + a] = h(A0);
}
else if (bu[A1 + 8] == 2) // battle
{
    V0 = w[A1 + 1c];
    V0 = w[V0 + 8e4];
    V0 = w[V0 + 11c0];
    [V0 + 4] = h(A0);
}
else if (bu[A1 + 8] == 3)
{
    V0 = w[A1 + 1c];
    V0 = w[V0 + 8e4];
    V0 = w[V0 + 8];
    [V0 + 24] = h(A0);
}
////////////////////////////////



////////////////////////////////
// func21640
A0 = A0 & ffff;
func1e2ac;
////////////////////////////////



////////////////////////////////
// func21660
A0 = A0 & ffff;
func1e2ac;
////////////////////////////////



////////////////////////////////
// func625f8
A1 = 0;
A0 = 0;
loop6260c:	; 8006260C
    V0 = bu[80083248 + A0 * 6 + 6];
    if (V0 != ff)
    {
        A1 = A1 + 1;
    }

    A0 = A0 + 1;
    V0 = A0 < 69;
80062628	bne    v0, zero, loop6260c [$8006260c]

return A1;
////////////////////////////////



////////////////////////////////
// func4ea4c
S0 = 8007b9c0 + A0 * 2c;
if ((S0 != 0) && (h[S0 + 8] != 0))
{
    A0 = w[S0 + 14];
    if (A0 != 0)
    {
        8004EA9C	jal    func2dd00 [$8002dd00]
    }

    if ((w[8007b968] >= 0) && (w[8007b970] == h[S0 + a]))
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

        V1 = 0;
        if (V1 < V1 + 1b8)
        {
            loop4eb24:	; 8004EB24
                if ((h[8007b9c0 + V1 + 8] != 0) && (w[8007b9c0 + V1 + 0] == S0))
                {
                    [8007b9c0 + V1 + 0] = w(0);
                }

                V1 = V1 + 2c;
                V0 = V1 < 1b8;
            8004EB50	bne    v0, zero, loop4eb24 [$8004eb24]
        }
    }
}
////////////////////////////////



////////////////////////////////
// func4ea30
[8007bb78] = w(A0);
////////////////////////////////



////////////////////////////////
// func4ea3c
return w[8007bb78];
////////////////////////////////



////////////////////////////////
// func4b9b8
S0 = A0;

[S0 + 22] = h(hu[S0 + 52] & fff);

if (hu[S0 + 5a] != hu[S0 + 36])
{
    [S0 + 36] = h(hu[S0 + 5a]);
    [S0 + 3a] = b(0);
    [S0 + 64] = b(0);

    A0 = hu[S0 + 34];
    A1 = hu[S0 + 5a];
    system_get_number_of_frames_in_animation;
    [S0 + 38] = b(V0);
    [S0 + 5d] = b(bu[S0 + 69]);
}

[S0 + f] = b(bu[S0 + f] & 7f);
////////////////////////////////



////////////////////////////////
// system_get_number_of_frames_in_animation
animation_id = A1;
A0 = 4; // return type - address
A1 = 30000 | (animation_id & ffff);
A2 = 0;
func1c7fc;

return hu[V0 + 2];
////////////////////////////////



////////////////////////////////
// func398d0
S0 = A0;
rotation = A1;
steps = A3;

[S0 + 52] = h(rotation & fff);
rotation_current = hu[S0 + 22] & fff;

rotation_left = rotation - rotation_current;

if (A2 != 0)
{
    if (rotation_left >= 801)
    {
        rotation_left = rotation_left - 1000;
    }
    else if (rotation_left < -800)
    {
        rotation_left = rotation_left + 1000;
    }
}

if (rotation_left != 0)
{
    [S0 + 60] = b(0);
    [S0 + 61] = b(ff);
    [S0 + 80] = h(rotation_current);
    [S0 + 5a] = h(hu[S0 + 36]);
    [S0 + f] = b(bu[S0 + f] | 80);

    if (steps == 0)
    {
        steps = 10;
    }

    if (rotation_left >= 0)
    {
        A0 = hu[S0 + 34];
        A1 = hu[S0 + 4e];
        system_get_number_of_frames_in_animation;
        number_of_frames = V0;

        S1 = (number_of_frames * 10) / steps;

        if (rotation_left < 400)
        {
            S1 = (S1 * rotation_left) >> a;
        }

        if (S1 >= 6)
        {
            [S0 + 3a] = b(0);
            [S0 + 36] = h(hu[S0 + 4e]);
            [S0 + 6c] = h((rotation_left - 400) / S1);
            [S0 + 62] = b(80);
            [S0 + 64] = b(0);

            A0 = hu[S0 + 34];
            A1 = hu[S0 + 4e];
            system_get_number_of_frames_in_animation;

            [S0 + 38] = b(V0);

            V0 = w[8007aecc];
            if (bu[S0 + 7] == bu[V0 + 16ed])
            {
                [8007b710] = w(w[8007b710] + 1);
            }

            [S0 + 5d] = b((number_of_frames * 10) / S1);
            [S0 + 82] = h(rotation_left / S1);
        }
        else
        {
            [S0 + 6c] = h(7fff);

            if (rotation_current >= h[S0 + 52])
            {
                [S0 + 22] = h(rotation_current | f000);
            }
            else
            {
                [S0 + 22] = h(rotation_current);
            }

            if (S1 <= 0)
            {
                S1 = 1;
            }
            [S0 + 82] = h(rotation_left / S1);
        }
    }
    else
    {
        A0 = hu[S0 + 34];
        A1 = h[uS0 + 4c];
        system_get_number_of_frames_in_animation;
        number_of_frames = V0;

        S1 = (number_of_frames * 10) / steps;

        if (-rotation_left < 400)
        {
            S1 = (S1 * (-rotation_left)) >> a;
        }

        if (S1 >= 6)
        {
            [S0 + 3a] = b(0);
            [S0 + 36] = h(hu[S0 + 4c]);
            [S0 + 6c] = h((rotation_left + 400) / S1);
            [S0 + 62] = b(80);
            [S0 + 64] = b(0);

            A0 = hu[S0 + 34];
            A1 = hu[S0 + 4c];
            system_get_number_of_frames_in_animation;

            [S0 + 38] = b(V0);

            V0 = w[8007aecc];
            if (bu[S0 + 7] == bu[V0 + 16ed])
            {
                [8007b710] = w(w[8007b710] + 1);
            }

            [S0 + 5d] = b((number_of_frames * 10) / S1);
            [S0 + 82] = h(rotation_left / S1);
        }
        else
        {
            [S0 + 6c] = h(7ffe);

            if (rotation_current >= h[S0 + 52])
            {
                [S0 + 22] = h(rotation_current | 1000);
            }
            else
            {
                [S0 + 22] = h(rotation_current);
            }

            if (S1 <= 0)
            {
                S1 = 1;
            }
            [S0 + 82] = h(rotation_left / S1);
        }
    }
}
////////////////////////////////



////////////////////////////////
// func52e48
return A0 * A0 + A1 * A1 + A2 * A2;
////////////////////////////////



////////////////////////////////
// func5309c
[A0 + 0] = w[0];
[A0 + 4] = h(-A3);
system_rotate_vector_by_x_y_axis
////////////////////////////////



////////////////////////////////
// func38990
// perform move
dest_x = A0;
dest_z = A2;
S0 = w[8007b704];
S2 = A1;
S6 = A3;
S4 = bu[S0 + 5c];

move_x = dest_x - w[S0 + 14];
move_z = dest_z - w[S0 + 1c];

if (hu[S0 + 50] & 0020) // if set then we do not change rotation
{
    S1 = hu[S0 + 22] & 0fff;
}
else
{
    A0 = move_x;
    A1 = move_z;
    system_get_rotation_by_vector_x_y;
    S1 = V0; // set rotation by vector

    if ((S6 & 1) == 0)
    {
        V0 = hu[S0 + 22];
        V1 = V0 & 0fff;
        A0 = S1 - V1;
        if (A0 < 800)
        {
            A0 = A0 + 1000;
        }
        else if (A0 > 800)
        {
            A0 = A0 - 1000;
        }

        if (A0 == 0)
        {
            [S0 + 50] = h(hu[S0 + 50] | 0020);
        }

        V0 = bu[S0 + 5f];
        A2 = V0 << 3;
        if (A0 > 0)
        {
            if (A2 < A0)
            {
                S1 = V1 + A2;
            }
        }
        else
        {
            if (A0 < -A2)
            {
                S1 = V1 - A2;
            }
        }

        S1 = S1 & 0fff;
        [S0 + 22] = h(S1);
    }
}

if (S6 & 2)
{
    A0 = move_x;
    A1 = 0;
    A2 = move_z;
    S2 = S2 - w[S0 + 18];
    80038AAC	jal    func52ec0 [$80052ec0]

    A0 = -S2;
    A1 = -V0;
    system_get_rotation_by_vector_x_y;

    V1 = hu[S0 + 30] & 0fff;
    A1 = V0 & 0fff;
    A0 = A1 - V1;

    if (A0 < -800)
    {
        A0 = A0 + 1000;
    }
    else if (A0 >= 800)
    {
        A0 = A0 - 1000;
    }

    A2 = bu[S0 + 5f] * 8;
    if (A0 > 0)
    {
        if (A2 < A0)
        {
            A1 = V1 + A2;
        }
    }
    else
    {
        if (A0 < -A2)
        {
            A1 = V1 - A2;
        }
    }

    [S0 + 30] = h(A1 & fff);
}
else
{
    A1 = 0;
    S2 = 0;
}

A0 = SP + 10;
A2 = S1;
[SP + 10] = w[0];
[SP + 14] = h(-S4);
system_rotate_vector_by_x_y_axis;

[S0 + 14] = w(w[S0 + 14] + h[SP + 10])
[S0 + 18] = w(w[S0 + 18] + h[SP + 12]);
[S0 + 1c] = w(w[S0 + 1c] + h[SP + 14]);

A0 = S0;
A1 = 0;
A2 = SP + 18;
system_check_entity_collisions;
A1 = V0;

if ( (A1 != 0) && (w[SP + 18] <= 0) ) // if we cant move here move back
{
    [S0 + 14] = w(w[S0 + 14] - h[SP + 10]);
    [S0 + 18] = w(w[S0 + 18] - h[SP + 12]);
    [S0 + 1c] = w(w[S0 + 1c] - h[SP + 14]);
}

A0 = bu[S0 + 63];
V1 = A0 & ff;

if (V1 != 0 && V1 != ff)
{
    [S0 + 63] = b(A0 - 1);
}

S1 = bu[S0 + 63] > 0;

if (S6 < 0)
{
    S1 = 0;
    if ((A1 != S6) || (w[SP + 18] > 0))
    {
        S1 = 1;
    }
}



squared_distance = move_x * move_x + S2 * S2 + move_z * move_z;

if (squared_distance < S4 * S4) // if distance is less than move speed - finish move
{
    S1 = 0;
}
else if ( (hu[S0 + 50] & 0010) && (w[S0 + 78] < squared_distance) )
{
    S1 = 0;
}

if( ( w[S0 + 78] <= 7ffffffe ) && ( w[S0 + 78] > squared_distance ) )
{
    [S0 + 50] = h(hu[S0 + 50] | 0010);
}

[S0 + 78] = w(squared_distance);

if (S1 == 0)
{
    [S0 + 78] = w(7fffffff)
    [S0 + 30] = h(0);
    [S0 + 50] = h(hu[S0 + 50] & ffcf);
}

V0 = w[8007aecc];
if (bu[S0 + 7] == bu[V0 + 16ed])
{
    [8007b710] = w(w[8007b710] + 1);
}

return S1;
////////////////////////////////



////////////////////////////////
// func21698
A0 = 00020000 | hu[A0 + 34];
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 838];
800216C0	jalr   v0 ra

return V0;
////////////////////////////////



////////////////////////////////
// func2fc8c
if (A2 == 0)
{
    [80077c78 + 28] = w(A3);
}
else
{
    [80077c78 + 20] = w(w[80077c78 + 28]);

    V1 = bu[80077c78 + 0];

    [80077c78 + 0] = b(A0);
    [80077c78 + 1] = b(A1);
    [80077c78 + 2] = b(1);
    [80077c78 + 3] = b((A3 & 00ffffff ) != 0);
    [80077c78 + 5] = b(V1);
    [80077c78 + 8] = h(A2);
    [80077c78 + c] = w(0);
    [80077c78 + 10] = w(0);
    [80077c78 + 24] = w(A3);

    V0 = w[8006bd04 + A0 * 3 * 4];
    if (V0 != 0)
    {
        A0 = 80077c78;
        8002FD58	jalr   v0 ra
    }
}
////////////////////////////////



////////////////////////////////
// func31b6c
// jump here in func2fc8c if A0 == 1
80031B74	addu   s1, a0, zero
80031B80	lh     v0, $0008(s1)
80031B84	nop
80031B88	bne    v0, zero, L31b9c [$80031b9c]
80031B8C	lui    v0, $8007
80031B90	addiu  v0, zero, $0010
80031B94	sh     v0, $0008(s1)
80031B98	lui    v0, $8007

L31b9c:	; 80031B9C
80031B9C	lbu    a3, $0028(s1)
S0 = 80077d68;
80031BA4	sw     a3, $7d68(v0)
80031BA8	sw     a3, $0024(s0)
80031BAC	lbu    a0, $0029(s1)
80031BB0	nop
80031BB4	sw     a0, $0004(s0)
80031BB8	sw     a0, $0028(s0)
80031BBC	lbu    a1, $002a(s1)
80031BC0	nop
80031BC4	sw     a1, $0008(s0)
80031BC8	sw     a1, $002c(s0)
80031BCC	lbu    a2, $0024(s1)
80031BD0	nop
80031BD4	sw     a2, $000c(s0)
80031BD8	lbu    v0, $0025(s1)
80031BDC	subu   a2, a2, a3
80031BE0	sw     v0, $0010(s0)
80031BE4	lbu    v1, $0026(s1)
80031BE8	subu   v0, v0, a0
80031BEC	sw     a2, $003c(s0)
80031BF0	sw     v0, $0040(s0)
80031BF4	sw     v1, $0014(s0)
80031BF8	subu   v1, v1, a1
80031BFC	sw     v1, $0044(s0)
80031C00	lh     v0, $0008(s1)
80031C04	nop
80031C08	addiu  a1, v0, $ffff (=-$1)
80031C0C	bgtz   a1, L31c18 [$80031c18]
80031C10	nop
80031C14	addiu  a1, zero, $0001

L31c18:	; 80031C18
80031C18	jal    func2fd98 [$8002fd98]
80031C1C	addu   a0, a2, zero
80031C20	sw     v0, $0018(s0)
80031C24	lh     v0, $0008(s1)
80031C28	nop
80031C2C	addiu  a1, v0, $ffff (=-$1)
80031C30	bgtz   a1, L31c3c [$80031c3c]
80031C34	nop
80031C38	addiu  a1, zero, $0001

L31c3c:	; 80031C3C
80031C3C	lw     a0, $0040(s0)
80031C40	jal    func2fd98 [$8002fd98]
80031C44	nop
80031C48	sw     v0, $001c(s0)
80031C4C	lh     v0, $0008(s1)
80031C50	nop
80031C54	addiu  a1, v0, $ffff (=-$1)
80031C58	bgtz   a1, L31c64 [$80031c64]
80031C5C	nop
80031C60	addiu  a1, zero, $0001

L31c64:	; 80031C64
80031C64	lw     a0, $0044(s0)
80031C68	jal    func2fd98 [$8002fd98]
80031C6C	nop
80031C70	sw     v0, $0020(s0)
////////////////////////////////



////////////////////////////////
// func2fd98
if (A0 >= 0)
{
    return (A0 - 1 + A1) / A1;
}
else
{
    return (A0 + 1 - A1) / A1;
}
////////////////////////////////



////////////////////////////////
// func320b8
func2fc8c;
////////////////////////////////



////////////////////////////////
// func2f93c
V0 = hu[80077c78 + a];
[80077c78 + a] = h(A0);
return V0;
////////////////////////////////



////////////////////////////////
// func2f8e4
V0 = w[80077c78 + 1c];
if (A0 == 0)
{
    A0 = 1;
}
[80077c78 + 1c] = w(A0);
return V0;
////////////////////////////////



////////////////////////////////
// func2f8bc
V0 = bu[80077c78 + 4];
[80077c78 + 4] = b(0);
return V0;
////////////////////////////////



////////////////////////////////
// system_reset_random
[8007b720] = w(8007b724);

V0 = 8007b724;
V1 = 8007b744;

loop4bf30:	; 8004BF30
    [V0] = b(b[V0] XOR b[V0 + 1e9]);
    V0 = V0 + 1;
8004BF44	bne    v0, v1, loop4bf30 [$8004bf30]

V1 = 8007b744 + 1ec;

loop4bf50:	; 8004BF50
    [V0] = w(w[V0] XOR w[V0 - 20]);
    V0 = V0 + 4;
8004BF64	bne    v0, v1, loop4bf50 [$8004bf50]
////////////////////////////////



////////////////////////////////
// func4ed3c
A0 = 8007b9c0;
V1 = A0 + 1b8;

loop4ed58:	; 8004ED58
    if ( ( h[A0 + 8] != 0 ) && ( w[A0 + 14] != 0 ) )
    {
        V0 = w[A0 + 14];
        [V0 + 18] = h(0);
    }

    A0 = A0 + 2c;
    V0 = A0 < V1;
8004ED84	bne    v0, zero, loop4ed58 [$8004ed58]
////////////////////////////////



////////////////////////////////
// func4ec74
if (A0 < 8)
{
    [8007bba8 + A0 * 4] = w(A1);
}
////////////////////////////////



////////////////////////////////
// func15c58
V0 = w[800667b4];
A1 = w[800667b8];
S0 = w[V0];

loop15c7c:	; 80015C7C
    V0 = w[A1];
    [SP + 10] = w(V0);
    V1 = w[SP + 10];
    V0 = w[A1];
80015C94	bne    v1, v0, loop15c7c [$80015c7c]

V0 = w[SP + 10];
V1 = w[800667bc];
V0 = V0 - V1;
S1 = V0 & ffff;

if( A0 < 0 )
{
    return w[800678ec];
}

if( A0 == 1 )
{
    return S1;
}

if( A0 <= 0 )
{
    80015CDC	lui    v0, $8006
    80015CE0	lw     v0, $67c0(v0)
    80015CE4	nop
    80015CE8	addiu  v0, v0, $ffff (=-$1)
    80015CF0	addu   v0, v0, a0
}
else
{
    80015CF4	lui    v0, $8006
    80015CF8	lw     v0, $67c0(v0)
}


80015CFC	blez   a0, L15d08 [$80015d08]
80015D00	addu   a1, zero, zero
80015D04	addiu  a1, a0, $ffff (=-$1)

L15d08:	; 80015D08
80015D08	jal    func15dd0 [$80015dd0]
80015D0C	addu   a0, v0, zero
80015D10	lui    v0, $8006
80015D14	lw     v0, $67b4(v0)
80015D18	nop
80015D1C	lw     s0, $0000(v0)
80015D20	lui    a0, $8006
80015D24	lw     a0, $78ec(a0)
80015D28	addiu  a1, zero, $0001
80015D2C	jal    func15dd0 [$80015dd0]
80015D30	addiu  a0, a0, $0001
80015D34	lui    v0, $0040
80015D38	and    v0, s0, v0
if (V0 != 0)
{
    V1 = w[800667b4];
    V0 = w[V1];
    V0 = S0 XOR V0;
    A0 = 80000000;
    if (V0 >= 0)
    {
        loop15d64:	; 80015D64
            V0 = w[V1];
            V0 = S0 XOR V0;
            V0 = V0 & A0;
        80015D74	beq    v0, zero, loop15d64 [$80015d64]
    }
}

V0 = w[800678ec];
A0 = w[800667b8];
[800667c0] = w(V0);

loop15d94:	; 80015D94
    V0 = w[A0];
    [800667bc] = w(V0);
    V1 = w[800667bc];
    V0 = w[A0];
80015DB0	bne    v1, v0, loop15d94 [$80015d94]

return S1;
////////////////////////////////
