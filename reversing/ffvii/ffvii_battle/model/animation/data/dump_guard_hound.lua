000000005E01D007800C60FF320058FD
96FB0300000000001813050E05251F00
00000000C4010000C8010000CC010000
D0010000D4010000D8010000DC010000
E001000072013201720100009C0C38F1
D7FC000000000000CEFC78FF79F50000
30FF00002C010000

E8000000  0 EC000000  1 F0000000  2 F4000000  3
08010000  4 1C010000  5 2C010000  6 3C010000  7
4C010000  8 54010000  9 70010000  a 78010000  b
8401000090010000980100005C010000
A4010000AC010000B4010000BC010000
74010000800100008C01000094010000
9C010000A0010000A8010000B0010000
B8010000C00100007C01000088010000

A9C900C1 0
01F6E5EE 1
0EE5EE00 2
FCF002D12C01000008F003F70F04FAF005E5EE00 3
FCEAF006D1E803000008F007F70508FAF009E5EE 4
E800FCEA0AC90BCA0CEC0DE5EE000000 5
E800FCEA0AC90BCA0CEC0DE5EE000000 6
E800FCEA0EC90FCA10EC11E5EE000000 7
BE0FC205EE000000 8
BE00BE0FC205EE00FCF002D12C01000008F003F70F04FAF005E5EE 9
F5000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000






// idle
action = 0
800cb7cc : SH      00000000 (v0), 0000 (80154756 (at)) [80154756]
// sequence
A9 C9 00 C1
// opcodes
// A9[][00] this increment pointer by 2 and execute animation on second pointer. This called if we back from other action using EE.
    play_animation(0); -- 00
// 3 C1 (33) this reset pointer to 0 and then increment it until it points to opcode past C9




function action1_Hurt()
    play_animation(1); -- 01
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



// ???
action = 2
// sequence
    play_animation(e); -- 0e
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action3_Bite()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(2); -- 02
    move_to_target("linear_movement", 0x012c, 0x0000, 0x08); --D1 2C01 0000 08
    set_effect("foot_dust"); -- F0
    play_animation(3); -- 03
    execute_attack(0x0f); -- F7 0F
    play_animation(4); -- 04
    return_position(); --FA
    set_effect("foot_dust"); -- F0
    play_animation(5); -- 05
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action4_Tentacle()
    set_direction(); -- FC
    show_action_name(); -- EA
    set_effect("foot_dust"); -- F0
    play_animation(6); -- 06
    move_to_target("linear_movement", 0x03e8, 0x0000, 0x08); --D1 E803 0000 08
    set_effect("foot_dust"); -- F0
    play_animation(7); -- 07
    execute_attack(0x05); -- F7 05
    play_animation(8); -- 08
    return_position(); --FA
    set_effect("foot_dust"); -- F0
    play_animation(9); -- 09
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
