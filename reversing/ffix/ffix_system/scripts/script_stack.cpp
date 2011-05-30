////////////////////////////////
// system_script_parse_stack
S7 = 8007bcb8;
S4 = 8007b6f0;

L51f70:	; 80051F70
A0 = b[S6]; // read byte from opcode stream
S6 = S6 + 1;
if (A0 >= 80)
{
    A0 = A0;
    func51f18;

    [S7] = w(V0);
    S7 = S7 + 4;
    80051FB8	j      L51f70 [$80051f70]
}

38210580 06
58210580 07
981F0580 0c
9C210580 0d
8C210580 10
4C230580 26
A8230580 2f
D4230580 30
04240580 31
84240580 34
98250580 50
B0250580 51
E4250580 58
00260580 59
B0260580 5e
1C260580 5f
70260580 60
30260580 61
80250580 63
7C270580 6a



A1 = 8006e718 + A0 * 4;
A2 = w[A1];
80051F90	jr     a2 
80051F94	nop




L51f98:	; 80051F98
[S7] = w(1c000000 | V0);
S7 = S7 + 4;
80051FA4	j      L51f70 [$80051f70]

case 00 01 02 03 08 09 0a 0b 0f 2e 43 44 45 46 47 48 49 4a 4b 4c 4e 52 53 5a 5b 5c 64 65 67 68 69 6c 6e 6f 70 71 72 73 74 75 76 77 7b 7c: // C01F0580
{
    [S4] = w(S7);
    func37acc;
    S7 = w[S4];

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 1c 1d 1e 1f 22 23 54 55 56 57: // A4270580
{
    [S4] = w(S7);
    func372a4;
    S7 = w[S4];

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 04: // F8200580
{
    system_read_from_stack_command_from_script;
    T3 = V0;
    S7 = S7 + 4;
    A0 = V0 + 1;
    func51e8c;
    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 5: // 18210580
{
    system_read_from_stack_command_from_script;
    T3 = V0;
    S7 = S7 + 4;
    A0 = V0 - 1;
    func51e8c;
    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 0e: // 78210580
{
    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 == 0));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 11: // AC210580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script

    [S7] = w(1c000000 | ( V0 * T3 ) );
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 12: // CC210580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script

    800521DC	beq    t3, zero, L5281c [$8005281c]

    [S7] = w(1c000000 | (V0 / T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 13: // F4210580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script

    800521DC	beq    t3, zero, L5281c [$8005281c]

    [S7] = w(1c000000 | (V0 % T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 14: //1C220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    V0 = V0 + T3;

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 15: // 34220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 - T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 16: // 4C220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 << T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 17: // 64220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 >> T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 18: // 7C220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 < T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 19: // 94220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 > T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 1a: // AC220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 <= T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}

case 1b: // C8220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 >= T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}

case 20: // E4220580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    V0 = V0 XOR T3;
    V0 = V0 < 1;

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 21: // 00230580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    V0 = V0 XOR T3;
    V0 = 0 < V0;

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 24: // 1C230580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 & T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 25: // 34230580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;
    [S7] = w(1c000000 | (V0 XOR T3));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 27: // 64230580
{
    system_read_from_stack_command_from_script;
    S7 = S7 - 4;
    if (V0 != 0)
    {
        S7 = S7 + 4;
        system_read_from_stack_command_from_script;

        V0 = V0 != 0;
    }

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 28: // 84230580
{
    system_read_from_stack_command_from_script;
    S7 = S7 - 4;
    if (V0 == 0)
    {
        S7 = S7 + 4;
        system_read_from_stack_command_from_script;

        V0 = V0 != 0;
    }

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 29: // CC200580
{
    [S7] = w(18000000| bu[S6 + 0]);
    S7 = S7 + 4;
    S6 = S6 + 1;
    800520E0	j      L51f70 [$80051f70]
}
break;

case 2a: // EC270580
{
    [S4] = w(S7);
    system_count_bits_in_pop_stack;
    S7 = w[S4];

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 2b: // 04280580
{
    [S4] = w(S7);
    func37738;
    S7 = w[S4];

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 2c: // 4C250580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    A0 = V0;
    func51e8c;

    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 2d 36 37 38 39 3a 3b 3c 40 41 42: // D4270580
{
    [S4] = w(S7);
    func36ccc;
    S7 = w[S4];

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 32: // 34240580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A0 = V0 + T3;
    S7 = S7 + 4;
    T3 = A0;
    func51e8c;

    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 33: // 5C240580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A0 = V0 - T3;
    S7 = S7 + 4;
    T3 = A0;
    func51e8c;

    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 35: // AC240580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A0 = V0 >> T3;
    S7 = S7 + 4;
    T3 = A0;
    func51e8c;

    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 3d: // D4240580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A0 = V0 & T3;
    S7 = S7 + 4;
    T3 = A0;
    func51e8c;

    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 3e: // FC240580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A0 = V0 XOR T3;
    S7 = S7 + 4;
    T3 = A0;
    func51e8c;

    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 3f: // 24250580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A0 = V0 | T3;
    S7 = S7 + 4;
    T3 = A0;
    func51e8c;

    [S7] = w(1c000000 | T3);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 4d: // BC270580
{
    [S4] = w(S7);
    system_pick_random_active_bit;
    S7 = w[S4];

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 4f: // C8250580
{
    system_read_from_stack_command_from_script;

    [S7] = w( 1c000000 | ( ( V0 & w[8007b97c] & 03ffffff ) != 0 ) );
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 5d: // EC260580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A2 = w[8007b704];
    A0 = V0 - w[A2 + 14];
    A1 = T3 - w[A2 + 1c];
    system_get_rotation_by_vector_x_y;

    [S7] = w(1c000000 | ((V0 << 14) >> 18));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 62: // 68250580
{
    system_read_from_stack_command_from_script;

    A0 = V0 << 4;
    system_get_sin_by_rotation;

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}

case 66: // 28270580
{
    system_read_from_stack_command_from_script;
    T3 = V0;

    system_read_from_stack_command_from_script;

    A0 = V0;
    A1 = T3;
    system_get_rotation_by_vector_x_y;

    [S7] = w(1c000000 | (V0 >> 4));
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 6b: // 4C270580
{
    system_read_from_stack_command_from_script;

    A0 = V0;
    func4b85c;

    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 6d: // 64270580
{
    system_read_from_stack_command_from_script;

    A0 = V0;
    func378c4;
    [S7] = w(1c000000 | V0);
    S7 = S7 + 4;
    80051FA4	j      L51f70 [$80051f70]
}
break;

case 78: //5C200580
{
    [S7] = w(10000000 | (b[S6 + 0] << 8) | bu[S6 + 1]);
    S7 = S7 + 4;
    S6 = S6 + 2;
    8005207C	j      L51f70 [$80051f70]
}
break;

case 79: // 84200580
{
    [S7] = w(bu[S6 + 0] | 14000000);
    S7 = S7 + 4;
    S6 = S6 + 1;
    80052098	j      L51f70 [$80051f70]
}
break;

case 7a: // A0200580
{
    A0 = bu[S6];
    S6 = S6 + 1;
    func37d6c;

    [S7] = w(1c000000 | (V0 & 03ffffff));
    S7 = S7 + 4;

    800520C4	j      L51f70 [$80051f70]
}
break;

case 7d: // D81F0580
{
    [S7] = w(1c000000 | (bu[S6 + 1] << 8) | bu[S6 + 0]);
    S7 = S7 + 4;
    S6 = S6 + 2;
    80051FF8	j      L51f70 [$80051f70]
}
break;

case 7e: // 00200580
{
    [S7] = w(1c000000 | ((bu[S6 + 3] & 3) << 18) | bu[S6 + 2] << 10 | bu[S6 + 1] << 8 | bu[S6 + 0]);
    S7 = S7 + 4;
    S6 = S6 + 4;
    8005203C	j      L51f70 [$80051f70]
}
break;

case 7f: // E8200580
{
    [S4] = w(S7);

    return;
}


loop52044:	; 80052044
80052044	lbu    a0, $0000(s6)
80052048	addiu  s6, s6, $0001
8005204C	bne    a0, a1, loop52044 [$80052044]
80052050	nop
80052054	j      L51f70 [$80051f70]
80052058	nop

80052138	jal    system_read_from_stack_command_from_script [$80051d4c]
8005213C	nop
80052140	addiu  t3, v0, $0001
80052144	addiu  s7, s7, $0004
80052148	jal    func51e8c [$80051e8c]
8005214C	addu   a0, t3, zero
80052150	j      L51f98 [$80051f98]
80052154	addu   v0, t3, zero
80052158	jal    system_read_from_stack_command_from_script [$80051d4c]
8005215C	nop
80052160	addiu  t3, v0, $ffff (=-$1)
80052164	addiu  s7, s7, $0004
80052168	jal    func51e8c [$80051e8c]
8005216C	addu   a0, t3, zero
80052170	j      L51f98 [$80051f98]
80052174	addu   v0, t3, zero

8005218C	jal    system_read_from_stack_command_from_script [$80051d4c]
80052190	nop
80052194	j      L51f98 [$80051f98]
80052198	nor    v0, zero, v0
8005219C	jal    system_read_from_stack_command_from_script [$80051d4c]
800521A0	nop
800521A4	j      L51f98 [$80051f98]
800521A8	subu   v0, zero, v0

8005234C	jal    system_read_from_stack_command_from_script [$80051d4c]
80052350	nop
80052354	jal    system_read_from_stack_command_from_script [$80051d4c]
80052358	addu   t3, v0, zero
8005235C	j      L51f98 [$80051f98]
80052360	or     v0, v0, t3

800523A8	jal    system_read_from_stack_command_from_script [$80051d4c]
800523AC	nop
800523B0	jal    system_read_from_stack_command_from_script [$80051d4c]
800523B4	addu   t3, v0, zero
800523B8	mult   v0, t3
800523BC	addiu  s7, s7, $0004
800523C0	mflo   a0
800523C4	jal    func51e8c [$80051e8c]
800523C8	addu   t3, a0, zero
800523CC	j      L51f98 [$80051f98]
800523D0	addu   v0, t3, zero
800523D4	jal    system_read_from_stack_command_from_script [$80051d4c]
800523D8	nop
800523DC	jal    system_read_from_stack_command_from_script [$80051d4c]
800523E0	addu   t3, v0, zero
800523E4	beq    t3, zero, L5281c [$8005281c]
800523E8	addiu  s7, s7, $0004
800523EC	div    v0, t3
800523F0	mflo   a0
800523F4	jal    func51e8c [$80051e8c]
800523F8	addu   t3, a0, zero
800523FC	j      L51f98 [$80051f98]
80052400	addu   v0, t3, zero
80052404	jal    system_read_from_stack_command_from_script [$80051d4c]
80052408	nop
8005240C	jal    system_read_from_stack_command_from_script [$80051d4c]
80052410	addu   t3, v0, zero
80052414	beq    t3, zero, L5281c [$8005281c]
80052418	addiu  s7, s7, $0004
8005241C	div    v0, t3
80052420	mfhi   a0
80052424	jal    func51e8c [$80051e8c]
80052428	addu   t3, a0, zero
8005242C	j      L51f98 [$80051f98]
80052430	addu   v0, t3, zero

80052484	jal    system_read_from_stack_command_from_script [$80051d4c]
80052488	nop
8005248C	jal    system_read_from_stack_command_from_script [$80051d4c]
80052490	addu   t3, v0, zero
80052494	sllv   a0, t3, v0
80052498	addiu  s7, s7, $0004
8005249C	jal    func51e8c [$80051e8c]
800524A0	addu   t3, a0, zero
800524A4	j      L51f98 [$80051f98]
800524A8	addu   v0, t3, zero

80052580	jal    system_read_from_stack_command_from_script [$80051d4c]
80052584	nop
80052588	jal    system_get_cos_by_rotation [$8004bb7c]
8005258C	sll    a0, v0, $04
80052590	j      L51f98 [$80051f98]
80052594	nop
80052598	jal    system_read_from_stack_command_from_script [$80051d4c]
8005259C	nop
800525A0	jal    system_get_sin_by_rotation [$8004bb80]
800525A4	addu   a0, v0, zero
800525A8	j      L51f98 [$80051f98]
800525AC	nop
800525B0	jal    system_read_from_stack_command_from_script [$80051d4c]
800525B4	nop
800525B8	jal    system_get_cos_by_rotation [$8004bb7c]
800525BC	addu   a0, v0, zero
800525C0	j      L51f98 [$80051f98]
800525C4	nop

800525E4	jal    func4e904 [$8004e904]
800525E8	nop
800525EC	jal    system_read_from_stack_command_from_script [$80051d4c]
800525F0	addu   t3, v0, zero
800525F4	and    v0, v0, t3
800525F8	j      L51f98 [$80051f98]
800525FC	sltu   v0, zero, v0
80052600	jal    func4e8d4 [$8004e8d4]
80052604	nop
80052608	jal    system_read_from_stack_command_from_script [$80051d4c]
8005260C	addu   t3, v0, zero
80052610	and    v0, v0, t3
80052614	j      L51f98 [$80051f98]
80052618	sltu   v0, zero, v0
8005261C	lbu    a0, $0000(s6)
80052620	jal    system_get_entity_script_data_pointer [$8004b4c4]
80052624	addiu  s6, s6, $0001
80052628	j      L51f98 [$80051f98]
8005262C	nop
80052630	jal    system_read_from_stack_command_from_script [$80051d4c]
80052634	nop
80052638	lui    a2, $8008
8005263C	lw     a2, $b704(a2)
80052640	lui    a0, $8000
80052644	or     v0, v0, a0
80052648	lw     t3, $0014(v0)
8005264C	lw     v0, $001c(v0)
80052650	lw     a0, $0014(a2)
80052654	lw     a1, $001c(a2)
80052658	subu   a0, t3, a0
8005265C	subu   a2, v0, a1
80052660	jal    func52ec0 [$80052ec0]
80052664	addu   a1, zero, zero
80052668	j      L51f98 [$80051f98]
8005266C	nop
80052670	jal    system_read_from_stack_command_from_script [$80051d4c]
80052674	nop
80052678	lui    a2, $8008
8005267C	lw     a2, $b704(a2)
80052680	lui    a0, $8000
80052684	or     v0, v0, a0
80052688	lw     t3, $0014(v0)
8005268C	lw     v0, $001c(v0)
80052690	lw     a0, $0014(a2)
80052694	lw     a1, $001c(a2)
80052698	subu   a0, t3, a0
8005269C	jal    system_get_rotation_by_vector_x_y [$80052f24]
800526A0	subu   a1, v0, a1
800526A4	sll    v0, v0, $14
800526A8	j      L51f98 [$80051f98]
800526AC	sra    v0, v0, $18
800526B0	jal    system_read_from_stack_command_from_script [$80051d4c]
800526B4	nop
800526B8	jal    system_read_from_stack_command_from_script [$80051d4c]
800526BC	addu   t3, v0, zero
800526C0	lui    a2, $8008
800526C4	lw     a2, $b704(a2)
800526C8	nop
800526CC	lw     a0, $0014(a2)
800526D0	lw     a1, $001c(a2)
800526D4	subu   a0, v0, a0
800526D8	subu   a2, t3, a1
800526DC	jal    func52ec0 [$80052ec0]
800526E0	addu   a1, zero, zero

L526e4:	; 800526E4
800526E4	j      L51f98 [$80051f98]
800526E8	nop

8005277C	jal    system_read_from_stack_command_from_script [$80051d4c]
80052780	nop
80052784	lui    a0, $8008
80052788	lw     a0, $b704(a0)
8005278C	addu   a1, v0, zero
80052790	lhu    a0, $0034(a0)
80052794	jal    system_get_number_of_frames_in_animation [$800216d8]
80052798	nop
8005279C	j      L51f98 [$80051f98]
800527A0	nop

L5281c:	; 8005281C
8005281C	lui    a0, $8007
80052820	addiu  a0, a0, $e700 (=-$1900)
80052824	jal    func15c38 [$80015c38]
80052828	addiu  sp, sp, $fff0 (=-$10)
8005282C	j      L51f98 [$80051f98]
80052830	addiu  sp, sp, $0010
////////////////////////////////



////////////////////////////////
// func37acc
V1 = A0 - 8;
V0 = V1 < 6a;
80037AE0	beq    v0, zero, L37d58 [$80037d58]


[SP + 10] = w(0);

V0 = w[800113ec + V1 * 4];

80037B00	jr     v0 

087B0380 08 09 0a 0b
587D0380 0c 0d 0e 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2f 30 31 32 33 34 35 36 37 38 39 3a 3b 3c 3d 3e 3f 40 41 42 46 47 48 49 4a 4d 4e 4f 50 51 54 55 56 57 58 59 5d 5e 5f 60 61 62 63 66 67 68 69 6a 6b 6d
187B0380 0f 4b 4c
287B0380 2e 43 44 45
F07B0380 53
507D0380 5a 5b 5c
8C7B0380 65
487D0380 6c
387C0380 6e
807C0380 6f
C87C0380 70
087D0380 71
A07D0380 72
DC7D0380 73
F07D0380 74

case 52: // A87B0380
{
    system_read_from_stack_command_not_from_script;
    character_id = V0;
    if (character_id >= 9)
    {
        character_id = character_id - 4;
    }

    V0 = w[8006794c];
    S0 = w[V0 + 1c];
    V0 = hu[S0 + 3c + character_id * 90 + 10];

    return V0;
}
break;

case 64: // 387B0380
{
    system_read_from_stack_command_not_from_script; // read value from top of stack
    A0 = V0;

    if (A0 < 100)
    {
        func27f34;
    }
    else if (A0 < 200)
    {
        A0 = A0 - 100;
        func281a4
    }
    else
    {
        A0 = A0 - 200;
        func62560;
    }

    return V0;
}
break;

80037B08	jal    func36aac [$80036aac]
80037B0C	nop
80037B10	j      L37d58 [$80037d58]
80037B14	sw     v0, $0010(sp)
80037B18	jal    func36ffc [$80036ffc]
80037B1C	nop
80037B20	j      L37d58 [$80037d58]
80037B24	sw     v0, $0010(sp)
80037B28	jal    func37528 [$80037528]
80037B2C	nop
80037B30	j      L37d58 [$80037d58]
80037B34	sw     v0, $0010(sp)

80037B8C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037B90	nop
80037B94	addu   a0, v0, zero
80037B98	jal    funcc7ee8 [$800c7ee8]
80037B9C	addiu  a1, sp, $0010
80037BA0	j      L37d58 [$80037d58]
80037BA4	nop

80037BF0	lui    v0, $8006
80037BF4	lw     v0, $794c(v0)
80037BF8	nop
80037BFC	lw     s0, $001c(v0)
80037C00	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037C04	nop
80037C08	addu   v1, v0, zero
80037C0C	slti   v0, v1, $0009
80037C10	bne    v0, zero, L37c20 [$80037c20]
80037C14	sll    v0, v1, $03
80037C18	addiu  v1, v1, $fffc (=-$4)
80037C1C	sll    v0, v1, $03

L37c20:	; 80037C20
80037C20	addu   v0, v0, v1
80037C24	sll    v0, v0, $04
80037C28	addu   v0, s0, v0
80037C2C	lhu    v0, $0054(v0)
80037C30	j      L37d58 [$80037d58]
80037C34	sw     v0, $0010(sp)
80037C38	lui    v0, $8006
80037C3C	lw     v0, $794c(v0)
80037C40	nop
80037C44	lw     s0, $001c(v0)
80037C48	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037C4C	nop
80037C50	addu   v1, v0, zero
80037C54	slti   v0, v1, $0009
80037C58	bne    v0, zero, L37c68 [$80037c68]
80037C5C	sll    v0, v1, $03
80037C60	addiu  v1, v1, $fffc (=-$4)
80037C64	sll    v0, v1, $03

L37c68:	; 80037C68
80037C68	addu   v0, v0, v1
80037C6C	sll    v0, v0, $04
80037C70	addu   v0, s0, v0
80037C74	lh     v0, $004e(v0)
80037C78	j      L37d58 [$80037d58]
80037C7C	sw     v0, $0010(sp)
80037C80	lui    v0, $8006
80037C84	lw     v0, $794c(v0)
80037C88	nop
80037C8C	lw     s0, $001c(v0)
80037C90	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037C94	nop
80037C98	addu   v1, v0, zero
80037C9C	slti   v0, v1, $0009
80037CA0	bne    v0, zero, L37cb0 [$80037cb0]
80037CA4	sll    v0, v1, $03
80037CA8	addiu  v1, v1, $fffc (=-$4)
80037CAC	sll    v0, v1, $03

L37cb0:	; 80037CB0
80037CB0	addu   v0, v0, v1
80037CB4	sll    v0, v0, $04
80037CB8	addu   v0, s0, v0
80037CBC	lh     v0, $0056(v0)
80037CC0	j      L37d58 [$80037d58]
80037CC4	sw     v0, $0010(sp)
80037CC8	addiu  v0, zero, $ffff (=-$1)
80037CCC	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037CD0	sh     v0, $0014(sp)
80037CD4	addu   a0, v0, zero
80037CD8	beq    a0, zero, L37cfc [$80037cfc]
80037CDC	addiu  v0, zero, $0004
80037CE0	lbu    v1, $0005(a0)
80037CE4	nop
80037CE8	bne    v1, v0, L37cfc [$80037cfc]
80037CEC	addiu  a1, sp, $0014
80037CF0	lbu    a0, $003b(a0)
80037CF4	jal    funcc76e8 [$800c76e8]
80037CF8	addiu  a2, sp, $0016

L37cfc:	; 80037CFC
80037CFC	lh     v0, $0014(sp)
80037D00	j      L37d58 [$80037d58]
80037D04	sw     v0, $0010(sp)
80037D08	addiu  v0, zero, $ffff (=-$1)
80037D0C	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037D10	sh     v0, $0016(sp)
80037D14	addu   a0, v0, zero
80037D18	beq    a0, zero, L37d3c [$80037d3c]
80037D1C	addiu  v0, zero, $0004
80037D20	lbu    v1, $0005(a0)
80037D24	nop
80037D28	bne    v1, v0, L37d3c [$80037d3c]
80037D2C	addiu  a1, sp, $0014
80037D30	lbu    a0, $003b(a0)
80037D34	jal    funcc76e8 [$800c76e8]
80037D38	addiu  a2, sp, $0016

L37d3c:	; 80037D3C
80037D3C	lh     v0, $0016(sp)
80037D40	j      L37d58 [$80037d58]
80037D44	sw     v0, $0010(sp)
80037D48	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037D4C	nop
80037D50	jal    system_read_from_stack_command_not_from_script [$80052d40]
80037D54	nop

L37d58:	; 80037D58
return w[SP + 10];
////////////////////////////////



////////////////////////////////
// func372a4
stack = w[8007b6f0];
opcode = A0;

if (((w[stack - c] >> 1a) & 7) != 5)
{
    [8007b6f0] = w(stack - 8);
    system_read_from_stack_command_not_from_script;
    [8007b6f0] = w(stack);

    S2 = V0;
}
else
{
    S1 = w[stack - c] & 7;
    if (S1 == 2)
    {
        A0 = 0;
        battle_get_units_mask;
        [8007ae14] = h(V0);
    }
    else if (S1 == 3)
    {
        A0 = 1;
        battle_get_units_mask;
        [8007ae16] = h(V0);
    }
    else if (S1 == 4)
    {
        A0 = 2;
        battle_get_units_mask;
        [8007ae18] = h(V0);
    }

    S2 = hu[8007ae10 + S1 * 2];
}

system_read_from_stack_command_not_from_script;
S1 = V0;

S0 = 0;
S3 = 0;
S4 = 8007aed0;
S5 = 0;
loop373d0:	; 800373D0
    S3 = S3 >> 1;
    if (S2 & 1)
    {
        [8007b700] = w(w[S4]);

        switch( S6 )
        {
            case 22: // 4C740380
            {
                system_read_from_stack_command_not_from_script;
                S0 = V0 == S1;
            }
            break;

            case 54: // 74740380
            {
                system_read_from_stack_command_not_from_script;
                S0 = V0 & S1;
            }
            break;

04740380 1c
14740380 1d
24740380 1e
38740380 1f
60740380 23
84740380 55
98740380 56
A8740380 57

            80037404	jal    system_read_from_stack_command_not_from_script [$80052d40]
            80037408	nop
            8003740C	j      L374b8 [$800374b8]
            80037410	slt    s0, v0, s1
            80037414	jal    system_read_from_stack_command_not_from_script [$80052d40]
            80037418	nop
            8003741C	j      L374b8 [$800374b8]
            80037420	slt    s0, s1, v0
            80037424	jal    system_read_from_stack_command_not_from_script [$80052d40]
            80037428	nop
            8003742C	slt    v0, s1, v0
            80037430	j      L374b8 [$800374b8]
            80037434	xori   s0, v0, $0001
            80037438	jal    system_read_from_stack_command_not_from_script [$80052d40]
            8003743C	nop
            80037440	slt    v0, v0, s1
            80037444	j      L374b8 [$800374b8]
            80037448	xori   s0, v0, $0001

            80037460	jal    system_read_from_stack_command_not_from_script [$80052d40]
            80037464	nop
            80037468	xor    v0, v0, s1
            8003746C	j      L374b8 [$800374b8]
            80037470	sltu   s0, zero, v0

            80037484	jal    system_read_from_stack_command_not_from_script [$80052d40]
            80037488	nop
            8003748C	and    s0, v0, s1
            80037490	j      L374b8 [$800374b8]
            80037494	sltiu  s0, s0, $0001
            80037498	jal    system_read_from_stack_command_not_from_script [$80052d40]
            8003749C	nop
            800374A0	j      L374b4 [$800374b4]
            800374A4	xor    s0, v0, s1
            800374A8	jal    system_read_from_stack_command_not_from_script [$80052d40]
            800374AC	nop
            800374B0	or     s0, v0, s1

            L374b4:	; 800374B4
            800374B4	sltu   s0, zero, s0

            L374b8:	; 800374B8
        }

        S3 = S3 | (S0 << 7);
        [8007b6f0] = w(w[8007b6f0] + 4);
    }

    S2 = S2 >> 1;
    S4 = S4 + 4;
    S5 = S5 + 1;
    V0 = S5 < 8;
800374DC	bne    v0, zero, loop373d0 [$800373d0]

[8007b6f0] = w(w[8007b6f0] - 8);
return S3;
////////////////////////////////



////////////////////////////////
// func36ccc
A1 = w[8007b6f0];
S1 = A0;
A0 = w[A1 - c];
S2 = 0;

if (((A0 >> 1a) & 7) != 5)
{
    V0 = A1 - 8;
    [8007b6f0] = w(V0);
    80036DB0	jal    system_read_from_stack_command_not_from_script [$80052d40]

    V1 = w[8007b6f0];
    S3 = V0;
    [8007b6f0] = w(V1 + c);
}
else
{
    S0 = A0 & 7;
    V0 = 3;
    if (S0 == 2)
    {
        A0 = 0;
        battle_get_units_mask;
        [8007ae14] = h(V0);
    }
    else if (S0 == 3)
    {
        A0 = 1;
        battle_get_units_mask;
        [8007ae16] = h(V0);
    }
    else if (S0 == 4)
    {
        A0 = 2;
        battle_get_units_mask;
        [8007ae18] = h(V0);
    }

    S3 = hu[8007ae10 + S0 * 2];
}

S5 = 0;
system_read_from_stack_command_not_from_script;
S0 = V0;

S4 = 8007aed0;

L36dec:	; 80036DEC
    if (S3 & 1)
    {
        [8007b700] = w(w[S4]);

        switch(S1)
        {
            case 2d:
            {
                S2 = S0;
            }
            break;

            case 36:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 * S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 37:
            {
                system_read_from_stack_command_not_from_script;

                if (S0 != 0)
                {
                    S2 = V0 / S0;
                }
                else
                {
                    S2 = V0;
                }

                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 38:
            {
                system_read_from_stack_command_not_from_script;

                if (S0 != 0)
                {
                    S2 = V0 % S0;
                }
                else
                {
                    S2 = V0;
                }

                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 39:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 + S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 3a:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 - S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 3b:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 << S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 3c:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 >> S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 40:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 & S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 41:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 ^ S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;

            case 42:
            {
                system_read_from_stack_command_not_from_script;
                S2 = V0 | S0;
                [8007b6f0] = w(w[8007b6f0] + 4);
            }
            break;
        }

        A0 = S2;
        system_save_from_stack_command_not_from_script;
        [8007b6f0] = w(w[8007b6f0] + 4);
    }

    S3 = S3 >> 1;
    S4 = S4 + 4;
    S5 = S5 + 1;
    V0 = S5 < 8;
80036FB0	bne    v0, zero, L36dec [$80036dec]

[8007b6f0] = w(w[8007b6f0] - 8);
return S2;
////////////////////////////////