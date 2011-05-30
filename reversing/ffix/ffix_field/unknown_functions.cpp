////////////////////////////////
// funcb31b8
800B31B8	addu   t1, a0, zero
800B31BC	lui    v0, $8006
800B31C0	lw     v0, $794c(v0)
800B31C4	lw     v1, $000c(t1)
800B31C8	lw     v0, $001c(v0)
800B31CC	lbu    a0, $003b(v1)
800B31D0	lw     v1, $08e4(v0)
800B31D4	sll    v0, a0, $02
800B31D8	lw     v1, $000c(v1)
800B31DC	addu   v0, v0, a0
800B31E0	lw     v1, $0014(v1)
800B31E4	sll    v0, v0, $02
800B31E8	lw     v1, $0054(v1)
800B31EC	lw     a0, $0000(t1)
800B31F0	addu   t0, v1, v0
800B31F4	andi   v0, a0, $0800
800B31F8	beq    v0, zero, Lb3214 [$800b3214]
800B31FC	andi   v1, a1, $00ff
800B3200	addiu  v0, zero, $f7ff (=-$801)
800B3204	and    v0, a0, v0
800B3208	sw     v0, $0000(t1)
800B320C	jr     ra 
800B3210	addu   v0, zero, zero


Lb3214:	; 800B3214
800B3214	sll    v0, a2, $08
800B3218	andi   v0, v0, $ff00
800B321C	or     v1, v1, v0
800B3220	sll    v0, a3, $10
800B3224	lui    a0, $00ff
800B3228	and    v0, v0, a0
800B322C	or     v1, v1, v0
800B3230	lui    v0, $0100
800B3234	or     v1, v1, v0
800B3238	sw     v1, $000c(t0)
800B323C	sw     v1, $0008(t0)
800B3240	lw     v1, $0000(t1)
800B3244	addiu  v0, zero, $0001
800B3248	ori    v1, v1, $0c00
800B324C	jr     ra 
800B3250	sw     v1, $0000(t1)
////////////////////////////////



////////////////////////////////
// funcb2cc0
S0 = A1;
S2 = A2;
S2 = A3;

A0 = A0;
func1e350;

A0 = V0;
A1 = S0;
A2 = S1;
A3 = S2;
800B2CF0	jal    funcb31b8 [$800b31b8]
////////////////////////////////



////////////////////////////////
// funcc142c
V1 = w[800c9db4];
V1 = V1 + w[V1 + 10] + A0 * 38;
if (A1 != 0)
{
    [V1] = b(bu[V1] | 02);
}
else
{
    [V1] = b(bu[V1] & fd);
}

return 1;
////////////////////////////////



////////////////////////////////
// funcc7570
V1 = w[800c9df4];
[V1 + V0 * 28 + 1c] = w(A1);
[V1 + V0 * 28 + 20] = w(A1 * A1);
return 1;
////////////////////////////////



////////////////////////////////
// funcc3e18
A2 = A0;
if (A1 != 0)
{
    V0 = w[800c9df4];
    [V0 + A2 * 28 + 0] = h(hu[V0 + A2 * 28 + 0] | 0001);
}
else
{
    V0 = w[800c9df4];
    [V0 + A2 * 28 + 0] = h(hu[V0 + A2 * 28 + 0] & fffe);
    [V0 + A2 * 28 + 4] = h(-1);
    [V0 + A2 * 28 + 6] = h(-1);
    [V0 + A2 * 28 + 8] = h(-1);
    [V0 + A2 * 28 + a] = h(-1);
}

return 1;
////////////////////////////////



////////////////////////////////
// funcc0fb0
// restore screen offset to GPU
800C0FB8	jal    func12ad4 [$80012ad4]

if( V0 & 2 )
{
    return 1;
}

OFX = a0 << 10;
OFY = 70 << 10;

return 1;
////////////////////////////////



////////////////////////////////
// funcc0f08
// set screen offset to GPU
S0 = w[800c9db4] + bu[800ca068 + 75] * 34 + w[A0 + 18];

800C0F48	jal    func12ad4 [$80012ad4]

if( ( V0 & 2 ) && ( w[80071e34] >= 2 ) )
{
    return 1;
}

OFX = ( h[S0 + 20] + h[800ca068 + c] ) << 10;
OFY = ( h[S0 + 22] + h[800ca068 + e] ) << 10;

return 1;
////////////////////////////////



////////////////////////////////
// funcafac0
V0 = w[8006794c];
V0 = w[V0 + 1c];
V0 = w[V0 + 8e4]; // 800d1000
V0 = w[V0 + c];
V0 = w[V0 + 14];

S1 = A2;
V1 = w[V0 + 10];
A2 = A4;

if (V1 == 0)
{
    return;
}

S2 = A3;

V1 = w[V1 + 8];
S0 = V1 + A0 * 24;

if (A1 == 82)
{
    if (S1 != -1)
    {
        A0 = S0;
        800AFB38	jal    funcb00b0 [$800b00b0]

        800AFB40	addiu  a0, zero, $0004
        800AFB44	andi   v0, s1, $ffff
        800AFB48	lui    a1, $0016
        800AFB4C	or     a1, v0, a1
        800AFB50	addu   a2, zero, zero
        800AFB54	jal    func1c7fc [$8001c7fc]
        800AFB58	sb     s1, $0001(s0)
        800AFB5C	addu   a0, v0, zero
        800AFB60	jal    funcc9700 [$800c9700]
        800AFB64	sw     a0, $0018(s0)
        [S0 + e] = h(V0 * 10);
    }
    else
    {
        [S0 + 18] = w(0);
    }
}
else if (A1 == 83)
{
    if (S2 != 0)
    {
        800AFB88	addiu  v1, zero, $fff0 (=-$10)
        800AFB8C	lw     v0, $0000(s0)
        800AFB90	nop
        800AFB94	and    v1, v0, v1
        800AFB98	or     v0, s1, v0
        800AFBA0	andi   v0, v0, $000f
    }
    else
    {
        800AFB88	addiu  v1, zero, $fff0 (=-$10)
        800AFBA4	lw     v0, $0000(s0)
        800AFBA8	nor    a0, zero, s1
        800AFBAC	and    v1, v0, v1
        800AFBB0	andi   v0, v0, $000f
        800AFBB4	and    v0, v0, a0
    }

    800AFBB8	or     v1, v1, v0
    800AFBC0	sw     v1, $0000(s0)
}
else if (A1 == 87)
{
    800AFBD0	sh     s1, $0008(s0)
    800AFBD4	sh     s2, $000a(s0)
    800AFBDC	sh     a2, $000c(s0)
}
else if (A1 == 8c)
{
    800AFBE8	sh     s1, $0010(s0)
    800AFBEC	sh     s2, $0012(s0)
    800AFBF4	sh     a2, $0014(s0)
}
else if (A1 == 91)
{
    800AFC04	sh     s1, $0004(s0)
}
else if (A1 == 96)
{
    800AFC10	jal    func4b098 [$8004b098]
    800AFC14	addu   a0, s1, zero
    800AFC18	sb     v0, $0002(s0)
    800AFC20	sb     s2, $0003(s0)
}
else if (A1 == 9b)
{
    800AFC30	sb     s1, $0007(s0)
}
else if (A1 == 9c)
{
    800AFC3C	lw     v0, $0000(s0)
    800AFC40	addiu  v1, zero, $ff0f (=-$f1)
    800AFC44	and    v0, v0, v1
    800AFC48	andi   v1, s1, $000f
    800AFC4C	sll    v1, v1, $04
    800AFC50	or     v0, v0, v1
    800AFC58	sw     v0, $0000(s0)
}
else if (A1 == a0)
{
    800AFC68	sb     s1, $0006(s0)
}
else if (A1 == a1)
{
    [S0 + 16] = h(S1 * 10);
}
else if (A1 == a5)
{
    800AFC84	addiu  v0, zero, $00aa
    800AFC88	sh     s1, $001c(s0)
    800AFC8C	sh     s2, $001e(s0)
    800AFC94	sh     a2, $0020(s0)
}
else if (A1 == aa)
{
    [S0 + 22] = h(S1);
}
////////////////////////////////