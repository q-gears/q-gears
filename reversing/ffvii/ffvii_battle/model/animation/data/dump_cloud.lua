0000
80
00
9001
000A
000A
00000000E0FC
7CFC
0200000000000D080300031712000000 - joints
0000380400003804000038040000
38040000380400003804000038040000
3804000080013201800100009903A8FD
FFF90000DCFD000001FD58FFABF90000
30FE00002C010000

94010000 1
9C010000 2
A0010000 3
B0010000 4
C0010000 5
C4010000 6
CC010000 7
D0010000 8
D4010000 9
E4010000 a
E8010000 b
EC010000 c
F0010000 d
F4010000 e
00020000 f
FC010000 // 10
04020000 // 12
98010000 // 13
18030000 // 16
2C030000 // 17
58030000 // 18
6C030000 // 19
78030000 // 1a
84030000 // 1b
38030000 // 1c
20020000 // 1e
90020000 // 22
90020000 // 23
84020000 // 25
EC020000 // 26
FC020000 // 27
C8020000 C8020000 B0020000 B0020000 0C030000 0C030000 90010000 90010000
90010000 90010000 90010000 90010000 90010000 90010000 90010000 90010000
90010000 90010000 90010000 90010000 94030000 B8030000 D8030000 E8030000
0C040000 18040000 28040000 24040000 E4030000 94030000 90010000 90010000
90010000 90010000




-- 6C020000 // 14 24 attack
function action20_36_Attack()
    enemy_set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_sound_for_attacker(0x00, 0x001a); -- D8 00 1A00
    play_animation(26); -- 1A
    move_to_target("linear_movement", 0x04B0, 0x0000, 0x04); --D1 B004 0000 04
    set_effect("foot_dust"); -- F0
    play_animation(27); -- 1B
    execute_attack(0x01); -- F7 01
    play_animation(30); -- 1E
    play_animation(28); -- 1C
    return_position(); --FA
    set_effect("foot_dust"); -- F0
    play_animation(29); -- 1D
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



-- 10020000 // 11 1d magic
function action17_29_Magic()
    load_additional_effect(); -- E8
    enemy_set_direction(); -- FC
    play_animation(3); -- 03
ED
E6
    show_action_name(); -- EA
    play_animation(12); -- 0C
    play_animation(13); -- 0D
    execute_additional_effect(); -- EC
    play_animation(14); -- 0E
    play_animation(4); -- 04
    return_position(); --FA
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



-- 84020000 // 15 slashall
function action21_Slashall()
    enemy_set_direction(); -- FC
    play_animation(3); -- 03
ED
    execute_attack(0x10); -- F7 10
    play_animation(31); -- 1F
    play_animation(4); -- 04
    return_position(); --FA
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



-- 30020000 // 1f summon
function action31_Summon()
    load_additional_effect(); -- E8
    enemy_set_direction(); -- FC
    play_animation(3); -- 03
ED
A5
    show_action_name(); -- EA
    play_animation(12); -- 0C
    play_animation(13); -- 0D
    execute_additional_effect(); -- EC
    set_wait(0x0f); -- F4 0F
    wait(); -- F3
    play_animation(14); -- 0E
    play_animation(4); -- 04
    return_position(); --FA
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



-- 44020000 // 20
function action32()
    load_additional_effect(); -- E8
    enemy_set_direction(); -- FC
    play_animation(3); -- 03
ED
    play_sound_for_attacker(0x06, 0x0015); -- D8 06 1500
    play_animation(9); -- 09
    show_action_name(); -- EA
EB
    set_wait(0x0a); -- F4 0A
    wait(); -- F3
    play_animation(4); -- 04
    return_position(); --FA
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



-- 58020000 // 21 item coin throw witem
function action33_Item()
    load_additional_effect(); -- E8
    enemy_set_direction(); -- FC
    play_animation(3); -- 03
ED
    play_sound_for_attacker(0x06, 0x0015); -- D8 06 1500
    play_animation(10); -- 0A
    show_action_name(); -- EA
EB
    set_wait(0x0a); -- F4 0A
    wait(); -- F3
    play_animation(4); -- 04
    return_position(); --FA
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
