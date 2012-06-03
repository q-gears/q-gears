////////////////////////////////
// 0xDF MPPAL
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

src_id = bu[script + 4];
dst_id = bu[script + 5];

A0 = 6;
A1 = a;
read_memory_block_one_byte;
length = V0 + 1;

A0 = 1;
A1 = 6;
read_memory_block_one_byte;
start = V0;

A0 = 2;
A1 = 7;
read_memory_block_one_byte;
mulB = V0;

A0 = 3;
A1 = 8;
read_memory_block_one_byte;
mulG = V0;

A0 = 4;
A1 = 9;
read_memory_block_one_byte;
mulR = V0;

end = start + length;

if (start < end)
{
    S1 = start;
    loopcea00:	; 800CEA00
        A3 = hu[80095de0 + src_id * 20 + S1 * 2];
        if (A3 != 0)
        {
            A1 = (mulB * ((A3 >> 9) & 3f)) >> 7;
            if (A1 >= 20)
            {
                A1 = 1f;
            }

            V1 = (mulG * ((A3 >> 4) & 3f)) >> 7;
            if (V1 >= 20)
            {
                V1 = 1f;
            }

            A0 = (mulR * ((A3 << 1) & 3e)) >> 7;
            if (A0 >= 20)
            {
                A0 = 1f;
            }

            [80095de0 + dst_id * 20 + S1 * 2] = h((A3 & 8000) | (A1 << a) | (V1 << 5) | A0);

            if (hu[80095de0 + dst_id * 20 + S1 * 2] == 0)
            {
                [80095de0 + dst_id * 20 + S1 * 2] = h(8000);
            }
        }

        S1 = S1 + 1;
        V0 = S1 < end;
    800CEAC8	bne    v0, zero, loopcea00 [$800cea00]
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + b);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE5 STPAL
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

A0 = SP + 10;
funccdc14;

A0 = 1;
A1 = 2;
read_memory_block_one_byte;

[SP + 10] = h(0);                  // x
[SP + 12] = h(V0 + 1e0);           // y
[SP + 14] = h(bu[script + 4] + 1); // width
[SP + 16] = h(1);                  // height

A0 = 2;
A1 = 3;
read_memory_block_one_byte;

A0 = SP + 10;
A1 = 80095de0 + V0 * 20;
func44064;

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 5);
////////////////////////////////



////////////////////////////////
// 0xE6 LDPAL
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

A0 = SP + 10;
funccdc14;

A0 = 2;
A1 = 3;
read_memory_block_one_byte;
[SP + 10] = h(0);
[SP + 12] = h(V0 + 1e0);
[SP + 14] = h(bu[script + 4] + 1);
[SP + 16] = h(1);

A0 = 1;
A1 = 2;
read_memory_block_one_byte;

A0 = SP + 10;
A1 = 80095de0 + V0 * 20;
func44000;

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 5);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE7 CPPAL
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

length = bu[script + 4] + 1;

A0 = 1;
A1 = 2;
read_memory_block_one_byte;
S1 = V0;

A0 = 2;
A1 = 3;
read_memory_block_one_byte;


if( length != 0 )
{
    A1 = 0;
    loopcdcd0:	; 800CDCD0
        [80095de0 + V0 * 20 + A1 * 2] = h(hu[80095de0 + S1 * 20 + A1 * 2]);

        A1 = A1 + 1;
        V1 = A1 < length;
    800CDCF8	bne    v1, zero, loopcdcd0 [$800cdcd0]
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 5);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE8 RTPAL
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

size = bu[script + 6] + 1;

A0 = 1;
A1 = 3;
read_memory_block_one_byte;
src = V0;

A0 = 2;
A1 = 4;
read_memory_block_one_byte;
dst = V0;

A0 = 4;
A1 = 5;
read_memory_block_one_byte;
start = V0;

if (size >= start)
{
    A1 = start;
    A2 = 0;
    loopcdf5c:	; 800CDF5C
        [80095de0 + dst * 20 + A1 * 2] = h(hu[80095de0 + src * 20 + A2 * 2]);

        A1 = A1 + 1;
        A2 = A2 + 1;
        V0 = A2 > size;
    800CDF90	beq    v0, zero, loopcdf5c [$800cdf5c]
}

A2 = size - start;
if (size >= A2)
{
    A1 = 0;
    loopcdfd0:	; 800CDFD0
        [80095de0 + dst * 20 + A1 * 2] = h(hu[80095de0 + src * 20 + A2 * 2]);

        A1 = A1 + 1;
        A2 = A2 + 1;
        V0 = A2 > size;
    800CE004	beq    v0, zero, loopcdfd0 [$800cdfd0]
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 7);

return 0;
////////////////////////////////



////////////////////////////////
// 0xE9 ADPAL
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

S4 = bu[script + 9] + 1;

A0 = 1;
A1 = 4;
read_memory_block_one_byte;
S2 = V0;

A0 = 2;
A1 = 5;
read_memory_block_one_byte;
S3 = V0;

A0 = 3;
A1 = 6;
read_memory_block_one_byte;
S1 = V0;

A0 = 4;
A1 = 7;
read_memory_block_one_byte;
S0 = V0;

A0 = 5;
A1 = 8;
read_memory_block_one_byte;
T2 = V0;

if (S1 & 80)
{
    S1 = S1 ^ ff00;
}

if (S0 & 80)
{
    S0 = S0 ^ ff00;
}

if (T2 & 80)
{
    T2 = T2 ^ ff00;
}

T1 = 0;
A0 = S4;
V0 = S2 & ff;

if (A0 != 0)
{
    V1 = 80095de0;
    V0 = V0 * 20;
    T5 = V0 + V1;
    V0 = S3;
    V0 = V0 * 20;
    T4 = V0 + V1;
    T3 = A0;

    loopce32c:	; 800CE32C
        A1 = V1 * 2;
        V0 = A1 + T5;

        T0 = hu[V0];
        V0 = T0 & 1f;
        V0 = T2 + V0;

        A2 = V0;
        if (V0 >= 20)
        {
            A2 = 1f;
        }

        V0 = A2 << 10;
        A3 = T0 & ffff;
        if (V0 < 0)
        {
            A2 = 0;
        }

        800CE370	srl    v0, a3, $05
        800CE374	andi   v0, v0, $001f
        800CE378	addu   v0, s0, v0
        800CE37C	addu   v1, v0, zero
        if (V0 >= 20)
        {
            V1 = 1f;
        }

        V0 = V1 << 10;
        if (V0 < 0)
        {
            V1 = 0;
        }

        800CE3A0	srl    v0, a3, $0a
        800CE3A8	andi   v0, v0, $001f
        800CE3AC	addu   v0, s1, v0
        800CE3B0	addu   a0, v0, zero
        800CE3B4	sll    v0, v0, $10
        800CE3B8	sra    v0, v0, $10
        800CE3BC	slti   v0, v0, $0020
        if (V0 >= 20)
        {
            A0 = 1f;
        }

        800CE3C4	sll    v0, a0, $10
        A1 = A1 + T4;
        if (V0 < 0)
        {
            A0 = 0;
        }

        V0 = A0 << a;
        V1 = V1 * 20;
        V0 = V0 | V1;
        V0 = A2 | V0;
        V1 = T0 & 8000;
        V0 = V0 | V1;

        [A1] = h(V0);
        V0 = h[A1];

        if (V0 == 0 && A3 != 0)
        {
            [A1]= h(8000);
        }

        V0 = T1 + 1;
        T1 = V0;
        V0 = V0 < T3;
    800CE42C	bne    v0, zero, loopce32c [$800ce32c]
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + a);

return 0;
////////////////////////////////



////////////////////////////////
// 0xEA MPPAL2
struct = w[8009c6e0];
current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

length = bu[script + 9] + 1;

A0 = 1;
A1 = 4;
read_memory_block_one_byte
src_id = V0;

A0 = 2;
A1 = 5;
read_memory_block_one_byte
dst_id = V0;

A0 = 3;
A1 = 6;
read_memory_block_one_byte
mulB = V0;

A0 = 4;
A1 = 7;
read_memory_block_one_byte
mulG = V0;

A0 = 5;
A1 = 8;
read_memory_block_one_byte
mulR = V0;

if( length != 0 )
{
    T0 = 0;
    loopce7e8:	; 800CE7E8
        A3 = hu[80095de0 + src_id * 20 + T0 * 2];
        if( A3 != 0 )
        {
            A1 = ( mulB * ( ( A3 >> 9 ) & 3f ) ) >> 7;
            if( A1 >= 20 )
            {
                A1 = 1f;
            }

            V1 = ( mulG * ( ( A3 >> 4 ) & 3f ) ) >> 7;
            if( V1 >= 20 )
            {
                V1 = 1f;
            }

            A0 = ( mulR * ( ( A3 << 1 ) & 3e ) ) >> 7;
            if( A0 >= 20 )
            {
                A0 = 1f;
            }

            [80095de0 + dst_id * 20 + A2] = h((A3 & 8000) | (A1 << a) | (V1 << 5) | A0);

            if( hu[80095de0 + dst_id * 20 + A2] == 0 )
            {
                [80095de0 + dst_id * 20 + A2] = h(8000);
            }
        }

        T0 = T0 + 1;
        V0 = T0 < length;
    800CE8B0	bne    v0, zero, loopce7e8 [$800ce7e8]
}

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + a);

return 0;
////////////////////////////////



////////////////////////////////
// 0xEB STPLS
A0 = SP + 10;
funccdc14;

current_entity = bu[800722c4];
script = w[8009c6dc] + hu[800831fc + current_entity * 2];

[SP + 10] = h(bu[script + 3]);
[SP + 12] = h(1e0 + bu[script + 1]);
[SP + 14] = h(bu[script + 4] + 1);
[SP + 16] = h(1);

A0 = SP + 10;
A1 = 80095de0 + bu[script + 2] * 20 + bu[script + 3] * 2;
func44064;

[800831fc + current_entity * 2] = h(hu[800831fc + current_entity * 2] + 5);

return 0;
////////////////////////////////



////////////////////////////////
// 0xEC LDPLS
800CDB0C	lui    v0, $800a
800CDB10	lbu    v0, $d820(v0)
800CDB14	addiu  sp, sp, $ffe0 (=-$20)
800CDB18	sw     ra, $001c(sp)
800CDB1C	andi   v0, v0, $0003
800CDB20	beq    v0, zero, Lcdb38 [$800cdb38]
800CDB24	sw     s0, $0018(sp)
800CDB28	lui    a0, $800a
800CDB2C	addiu  a0, a0, $0c60
800CDB30	jal    funcbead4 [$800bead4]
800CDB34	ori    a1, zero, $0004

Lcdb38:	; 800CDB38
800CDB38	jal    funccdc14 [$800cdc14]
800CDB3C	addiu  a0, sp, $0010
800CDB40	lui    s0, $8008
800CDB44	addiu  s0, s0, $31fc
800CDB48	lui    a0, $8007
800CDB4C	lbu    a0, $22c4(a0)
800CDB50	lui    a1, $800a
800CDB54	lw     a1, $c6dc(a1)
800CDB58	sll    a0, a0, $01
800CDB5C	addu   a0, a0, s0
800CDB60	lhu    v0, $0000(a0)
800CDB64	nop
800CDB68	addu   v0, a1, v0
800CDB6C	lbu    v0, $0002(v0)
800CDB70	nop
800CDB74	addiu  v0, v0, $01e0
800CDB78	sh     v0, $0012(sp)
800CDB7C	lhu    v0, $0000(a0)
800CDB80	nop
800CDB84	addu   v0, a1, v0
800CDB88	lbu    a2, $0003(v0)
800CDB8C	nop
800CDB90	sh     a2, $0010(sp)
800CDB94	lhu    v0, $0000(a0)
800CDB98	ori    v1, zero, $0001
800CDB9C	addu   v0, a1, v0
800CDBA0	lbu    v0, $0004(v0)
800CDBA4	sll    a2, a2, $01
800CDBA8	sh     v1, $0016(sp)
800CDBAC	addiu  v0, v0, $0001
800CDBB0	sh     v0, $0014(sp)
800CDBB4	lhu    v0, $0000(a0)
800CDBB8	addiu  a0, sp, $0010
800CDBBC	addu   a1, a1, v0
800CDBC0	lui    v0, $8009
800CDBC4	addiu  v0, v0, $5de0
800CDBC8	lbu    a1, $0001(a1)
800CDBCC	addu   a2, a2, v0
800CDBD0	sll    a1, a1, $05
800CDBD4	jal    func44000 [$80044000]
800CDBD8	addu   a1, a1, a2
800CDBDC	lui    a0, $8007
800CDBE0	lbu    a0, $22c4(a0)
800CDBE4	nop
800CDBE8	sll    a0, a0, $01
800CDBEC	addu   a0, a0, s0
800CDBF0	lhu    v1, $0000(a0)
800CDBF4	addu   v0, zero, zero
800CDBF8	addiu  v1, v1, $0005
800CDBFC	sh     v1, $0000(a0)
800CDC00	lw     ra, $001c(sp)
800CDC04	lw     s0, $0018(sp)
800CDC08	addiu  sp, sp, $0020
800CDC0C	jr     ra 
800CDC10	nop
////////////////////////////////



////////////////////////////////
// 0xED CPPAL2
800CDD40	lui    v0, $800a
800CDD44	lbu    v0, $d820(v0)
800CDD48	addiu  sp, sp, $ffd8 (=-$28)
800CDD4C	sw     ra, $0020(sp)
800CDD50	sw     s3, $001c(sp)
800CDD54	sw     s2, $0018(sp)
800CDD58	sw     s1, $0014(sp)
800CDD5C	andi   v0, v0, $0003
800CDD60	beq    v0, zero, Lcdd78 [$800cdd78]
800CDD64	sw     s0, $0010(sp)
800CDD68	lui    a0, $800a
800CDD6C	addiu  a0, a0, $0c68
800CDD70	jal    funcbead4 [$800bead4]
800CDD74	ori    a1, zero, $0007

Lcdd78:	; 800CDD78
800CDD78	ori    a0, zero, $0004
800CDD7C	jal    read_memory_block_one_byte [$800bee10]
800CDD80	ori    a1, zero, $0007
800CDD84	ori    a0, zero, $0001
800CDD88	ori    a1, zero, $0005
800CDD8C	andi   s0, v0, $00ff
800CDD90	lui    v1, $8007
800CDD94	lbu    v1, $22c4(v1)
800CDD98	lui    v0, $800a
800CDD9C	lw     v0, $c6dc(v0)
800CDDA0	sll    v1, v1, $01
800CDDA4	lui    at, $8008
800CDDA8	addiu  at, at, $31fc
800CDDAC	addu   at, at, v1
800CDDB0	lhu    v1, $0000(at)
800CDDB4	nop
800CDDB8	addu   v0, v0, v1
800CDDBC	lbu    s3, $0003(v0)
800CDDC0	lbu    s2, $0004(v0)
800CDDC4	jal    read_memory_block_one_byte [$800bee10]
800CDDC8	addiu  s0, s0, $0001
800CDDCC	andi   s1, v0, $00ff
800CDDD0	ori    a0, zero, $0002
800CDDD4	jal    read_memory_block_one_byte [$800bee10]
800CDDD8	ori    a1, zero, $0006
800CDDDC	andi   a1, v0, $00ff
800CDDE0	addu   a0, s1, s0
800CDDE4	slt    v0, s1, a0
800CDDE8	beq    v0, zero, Lcde44 [$800cde44]
800CDDEC	sll    v1, s2, $05
800CDDF0	lui    v0, $8009
800CDDF4	addiu  v0, v0, $5de0
800CDDF8	addu   t0, v1, v0
800CDDFC	sll    v1, s3, $05
800CDE00	addu   a3, v1, v0
800CDE04	addu   a2, a0, zero

loopcde08:	; 800CDE08
800CDE08	sll    a0, s1, $10
800CDE0C	addiu  v0, s1, $0001
800CDE10	addu   s1, v0, zero
800CDE14	sll    v1, a1, $10
800CDE18	addiu  a1, a1, $0001
800CDE1C	sra    v1, v1, $0f
800CDE20	sra    a0, a0, $0f
800CDE24	addu   a0, a0, a3
800CDE28	addu   v1, v1, t0
800CDE2C	sll    v0, v0, $10
800CDE30	sra    v0, v0, $10
800CDE34	lhu    a0, $0000(a0)
800CDE38	slt    v0, v0, a2
800CDE3C	bne    v0, zero, loopcde08 [$800cde08]
800CDE40	sh     a0, $0000(v1)

Lcde44:	; 800CDE44
800CDE44	lui    v1, $8007
800CDE48	lbu    v1, $22c4(v1)
800CDE4C	lui    v0, $8008
800CDE50	addiu  v0, v0, $31fc
800CDE54	sll    v1, v1, $01
800CDE58	addu   v1, v1, v0
800CDE5C	lhu    a0, $0000(v1)
800CDE60	addu   v0, zero, zero
800CDE64	addiu  a0, a0, $0008
800CDE68	sh     a0, $0000(v1)
800CDE6C	lw     ra, $0020(sp)
800CDE70	lw     s3, $001c(sp)
800CDE74	lw     s2, $0018(sp)
800CDE78	lw     s1, $0014(sp)
800CDE7C	lw     s0, $0010(sp)
800CDE80	addiu  sp, sp, $0028
800CDE84	jr     ra 
800CDE88	nop
////////////////////////////////



////////////////////////////////
// 0xEE RTPAL2
800CE054	lui    v0, $800a
800CE058	lbu    v0, $d820(v0)
800CE05C	addiu  sp, sp, $ffd8 (=-$28)
800CE060	sw     ra, $0020(sp)
800CE064	sw     s3, $001c(sp)
800CE068	sw     s2, $0018(sp)
800CE06C	sw     s1, $0014(sp)
800CE070	andi   v0, v0, $0003
800CE074	beq    v0, zero, Lce08c [$800ce08c]
800CE078	sw     s0, $0010(sp)
800CE07C	lui    a0, $800a
800CE080	addiu  a0, a0, $0c70
800CE084	jal    funcbead4 [$800bead4]
800CE088	ori    a1, zero, $0007

Lce08c:	; 800CE08C
800CE08C	ori    a0, zero, $0004
800CE090	jal    read_memory_block_one_byte [$800bee10]
800CE094	ori    a1, zero, $0007
800CE098	ori    a0, zero, $0001
800CE09C	ori    a1, zero, $0005
800CE0A0	andi   s0, v0, $00ff
800CE0A4	lui    v1, $8007
800CE0A8	lbu    v1, $22c4(v1)
800CE0AC	lui    v0, $800a
800CE0B0	lw     v0, $c6dc(v0)
800CE0B4	sll    v1, v1, $01
800CE0B8	lui    at, $8008
800CE0BC	addiu  at, at, $31fc
800CE0C0	addu   at, at, v1
800CE0C4	lhu    v1, $0000(at)
800CE0C8	nop
800CE0CC	addu   v0, v0, v1
800CE0D0	lbu    s3, $0003(v0)
800CE0D4	lbu    s2, $0004(v0)
800CE0D8	jal    read_memory_block_one_byte [$800bee10]
800CE0DC	addiu  s0, s0, $0001
800CE0E0	ori    a0, zero, $0002
800CE0E4	ori    a1, zero, $0006
800CE0E8	jal    read_memory_block_one_byte [$800bee10]
800CE0EC	andi   s1, v0, $00ff
800CE0F0	addu   a2, s1, zero
800CE0F4	andi   t2, v0, $00ff
800CE0F8	addu   a1, t2, zero
800CE0FC	addu   s0, s0, s1
800CE100	slt    v0, s0, a1
800CE104	bne    v0, zero, Lce160 [$800ce160]
800CE108	addu   t1, s0, zero
800CE10C	lui    v0, $8009
800CE110	addiu  v0, v0, $5de0
800CE114	sll    v1, s2, $05
800CE118	addu   t0, v1, v0
800CE11C	sll    v1, s3, $05
800CE120	addu   a3, v1, v0

loopce124:	; 800CE124
800CE124	sll    v1, a2, $10
800CE128	addiu  a2, a2, $0001
800CE12C	sll    a0, a1, $10
800CE130	addiu  v0, a1, $0001
800CE134	addu   a1, v0, zero
800CE138	sra    a0, a0, $0f
800CE13C	sra    v1, v1, $0f
800CE140	addu   v1, v1, a3
800CE144	addu   a0, a0, t0
800CE148	sll    v0, v0, $10
800CE14C	sra    v0, v0, $10
800CE150	lhu    v1, $0000(v1)
800CE154	slt    v0, s0, v0
800CE158	beq    v0, zero, loopce124 [$800ce124]
800CE15C	sh     v1, $0000(a0)

Lce160:	; 800CE160
800CE160	subu   v0, t1, t2
800CE164	addu   a2, v0, zero
800CE168	addu   s0, t1, zero
800CE16C	slt    v0, s0, v0
800CE170	bne    v0, zero, Lce1cc [$800ce1cc]
800CE174	addu   a1, s1, zero
800CE178	lui    v0, $8009
800CE17C	addiu  v0, v0, $5de0
800CE180	sll    v1, s2, $05
800CE184	addu   t0, v1, v0
800CE188	sll    v1, s3, $05
800CE18C	addu   a3, v1, v0

loopce190:	; 800CE190
800CE190	sll    a0, a2, $10
800CE194	addiu  v0, a2, $0001
800CE198	addu   a2, v0, zero
800CE19C	sll    v1, a1, $10
800CE1A0	addiu  a1, a1, $0001
800CE1A4	sra    v1, v1, $0f
800CE1A8	sra    a0, a0, $0f
800CE1AC	addu   a0, a0, a3
800CE1B0	addu   v1, v1, t0
800CE1B4	sll    v0, v0, $10
800CE1B8	sra    v0, v0, $10
800CE1BC	lhu    a0, $0000(a0)
800CE1C0	slt    v0, s0, v0
800CE1C4	beq    v0, zero, loopce190 [$800ce190]
800CE1C8	sh     a0, $0000(v1)

Lce1cc:	; 800CE1CC
800CE1CC	lui    v1, $8007
800CE1D0	lbu    v1, $22c4(v1)
800CE1D4	lui    v0, $8008
800CE1D8	addiu  v0, v0, $31fc
800CE1DC	sll    v1, v1, $01
800CE1E0	addu   v1, v1, v0
800CE1E4	lhu    a0, $0000(v1)
800CE1E8	addu   v0, zero, zero
800CE1EC	addiu  a0, a0, $0008
800CE1F0	sh     a0, $0000(v1)
800CE1F4	lw     ra, $0020(sp)
800CE1F8	lw     s3, $001c(sp)
800CE1FC	lw     s2, $0018(sp)
800CE200	lw     s1, $0014(sp)
800CE204	lw     s0, $0010(sp)
800CE208	addiu  sp, sp, $0028
800CE20C	jr     ra 
800CE210	nop
////////////////////////////////



////////////////////////////////
// 0xEF ADPAL2
800CE480	lui    v0, $800a
800CE484	lbu    v0, $d820(v0)
800CE488	addiu  sp, sp, $ffd0 (=-$30)
800CE48C	sw     ra, $0028(sp)
800CE490	sw     s5, $0024(sp)
800CE494	sw     s4, $0020(sp)
800CE498	sw     s3, $001c(sp)
800CE49C	sw     s2, $0018(sp)
800CE4A0	sw     s1, $0014(sp)
800CE4A4	andi   v0, v0, $0003
800CE4A8	beq    v0, zero, Lce4c0 [$800ce4c0]
800CE4AC	sw     s0, $0010(sp)
800CE4B0	lui    a0, $800a
800CE4B4	addiu  a0, a0, $0c78
800CE4B8	jal    funcbead4 [$800bead4]
800CE4BC	ori    a1, zero, $0008

Lce4c0:	; 800CE4C0
800CE4C0	ori    a0, zero, $0006
800CE4C4	jal    read_memory_block_one_byte [$800bee10]
800CE4C8	ori    a1, zero, $000a
800CE4CC	ori    a0, zero, $0001
800CE4D0	ori    a1, zero, $0006
800CE4D4	lui    v1, $8007
800CE4D8	lbu    v1, $22c4(v1)
800CE4DC	andi   v0, v0, $00ff
800CE4E0	sll    v1, v1, $01
800CE4E4	lui    at, $8008
800CE4E8	addiu  at, at, $31fc
800CE4EC	addu   at, at, v1
800CE4F0	lhu    a2, $0000(at)
800CE4F4	lui    v1, $800a
800CE4F8	lw     v1, $c6dc(v1)
800CE4FC	nop
800CE500	addu   v1, v1, a2
800CE504	lbu    s4, $0004(v1)
800CE508	lbu    s5, $0005(v1)
800CE50C	jal    read_memory_block_one_byte [$800bee10]
800CE510	addiu  s3, v0, $0001
800CE514	ori    a0, zero, $0002
800CE518	ori    a1, zero, $0007
800CE51C	jal    read_memory_block_one_byte [$800bee10]
800CE520	andi   s2, v0, $00ff
800CE524	andi   s1, v0, $00ff
800CE528	ori    a0, zero, $0003
800CE52C	jal    read_memory_block_one_byte [$800bee10]
800CE530	ori    a1, zero, $0008
800CE534	andi   s0, v0, $00ff
800CE538	ori    a0, zero, $0004
800CE53C	jal    read_memory_block_one_byte [$800bee10]
800CE540	ori    a1, zero, $0009
800CE544	andi   t2, v0, $00ff
800CE548	andi   v0, s1, $0080
800CE54C	beq    v0, zero, Lce558 [$800ce558]
800CE550	andi   v0, s0, $0080
800CE554	xori   s1, s1, $ff00

Lce558:	; 800CE558
800CE558	beq    v0, zero, Lce564 [$800ce564]
800CE55C	andi   v0, t2, $0080
800CE560	xori   s0, s0, $ff00

Lce564:	; 800CE564
800CE564	beq    v0, zero, Lce570 [$800ce570]
800CE568	addu   t1, s2, zero
800CE56C	xori   t2, t2, $ff00

Lce570:	; 800CE570
800CE570	addu   a0, t1, s3
800CE574	slt    v0, t1, a0
800CE578	beq    v0, zero, Lce6a4 [$800ce6a4]
800CE57C	sll    v1, s4, $05
800CE580	lui    v0, $8009
800CE584	addiu  v0, v0, $5de0
800CE588	addu   t5, v1, v0
800CE58C	sll    v1, s5, $05
800CE590	addu   t4, v1, v0
800CE594	addu   t3, a0, zero
800CE598	sll    v0, t1, $10

loopce59c:	; 800CE59C
800CE59C	sra    a1, v0, $0f
800CE5A0	addu   v0, a1, t5
800CE5A4	lhu    t0, $0000(v0)
800CE5A8	nop
800CE5AC	andi   v0, t0, $001f
800CE5B0	addu   v0, t2, v0
800CE5B4	addu   a2, v0, zero
800CE5B8	sll    v0, v0, $10
800CE5BC	sra    v0, v0, $10
800CE5C0	slti   v0, v0, $0020
800CE5C4	bne    v0, zero, Lce5d4 [$800ce5d4]
800CE5C8	sll    v0, a2, $10
800CE5CC	ori    a2, zero, $001f
800CE5D0	sll    v0, a2, $10

Lce5d4:	; 800CE5D4
800CE5D4	bgez   v0, Lce5e0 [$800ce5e0]
800CE5D8	andi   a3, t0, $ffff
800CE5DC	addu   a2, zero, zero

Lce5e0:	; 800CE5E0
800CE5E0	srl    v0, a3, $05
800CE5E4	andi   v0, v0, $001f
800CE5E8	addu   v0, s0, v0
800CE5EC	addu   v1, v0, zero
800CE5F0	sll    v0, v0, $10
800CE5F4	sra    v0, v0, $10
800CE5F8	slti   v0, v0, $0020
800CE5FC	bne    v0, zero, Lce60c [$800ce60c]
800CE600	sll    v0, v1, $10
800CE604	ori    v1, zero, $001f
800CE608	sll    v0, v1, $10

Lce60c:	; 800CE60C
800CE60C	bgez   v0, Lce618 [$800ce618]
800CE610	srl    v0, a3, $0a
800CE614	addu   v1, zero, zero

Lce618:	; 800CE618
800CE618	andi   v0, v0, $001f
800CE61C	addu   v0, s1, v0
800CE620	addu   a0, v0, zero
800CE624	sll    v0, v0, $10
800CE628	sra    v0, v0, $10
800CE62C	slti   v0, v0, $0020
800CE630	bne    v0, zero, Lce640 [$800ce640]
800CE634	sll    v0, a0, $10
800CE638	ori    a0, zero, $001f
800CE63C	sll    v0, a0, $10

Lce640:	; 800CE640
800CE640	bgez   v0, Lce64c [$800ce64c]
800CE644	addu   a1, a1, t4
800CE648	addu   a0, zero, zero

Lce64c:	; 800CE64C
800CE64C	sll    v0, a0, $0a
800CE650	sll    v1, v1, $05
800CE654	or     v0, v0, v1
800CE658	or     v0, a2, v0
800CE65C	andi   v1, t0, $8000
800CE660	or     v0, v0, v1
800CE664	sh     v0, $0000(a1)
800CE668	lhu    v0, $0000(a1)
800CE66C	nop
800CE670	bne    v0, zero, Lce688 [$800ce688]
800CE674	nop
800CE678	beq    a3, zero, Lce68c [$800ce68c]
800CE67C	addiu  v0, t1, $0001
800CE680	ori    v0, zero, $8000
800CE684	sh     v0, $0000(a1)

Lce688:	; 800CE688
800CE688	addiu  v0, t1, $0001

Lce68c:	; 800CE68C
800CE68C	addu   t1, v0, zero
800CE690	sll    v0, v0, $10
800CE694	sra    v0, v0, $10
800CE698	slt    v0, v0, t3
800CE69C	bne    v0, zero, loopce59c [$800ce59c]
800CE6A0	sll    v0, t1, $10

Lce6a4:	; 800CE6A4
800CE6A4	lui    v1, $8007
800CE6A8	lbu    v1, $22c4(v1)
800CE6AC	lui    v0, $8008
800CE6B0	addiu  v0, v0, $31fc
800CE6B4	sll    v1, v1, $01
800CE6B8	addu   v1, v1, v0
800CE6BC	lhu    a0, $0000(v1)
800CE6C0	addu   v0, zero, zero
800CE6C4	addiu  a0, a0, $000b
800CE6C8	sh     a0, $0000(v1)
800CE6CC	lw     ra, $0028(sp)
800CE6D0	lw     s5, $0024(sp)
800CE6D4	lw     s4, $0020(sp)
800CE6D8	lw     s3, $001c(sp)
800CE6DC	lw     s2, $0018(sp)
800CE6E0	lw     s1, $0014(sp)
800CE6E4	lw     s0, $0010(sp)
800CE6E8	addiu  sp, sp, $0030
800CE6EC	jr     ra 
800CE6F0	nop
////////////////////////////////



////////////////////////////////
// funccdc14
[A0 + 0] = h(0);
[A0 + 2] = h(0);
[A0 + 4] = h(0);
[A0 + 6] = h(0);
////////////////////////////////