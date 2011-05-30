000000002C01200320030000FA00EEFD
90FC2000000000000000002020000000
00000000A0010000A4010000A8010000
AC010000B0010000B4010000B8010000
BC0100005901190159010000160B78FC
A304000060FF00003EFE78FBDF080000
A0FF00002C010000

E8000000  0 EC000000  1 F0000000  2 F4000000  3
08010000  4 34010000  5 380100003C010000
40010000440100004801000050010000
5C010000680100007001000078010000
80010000880100009001000098010000
4C01000058010000640100006C010000
740100007C010000840100008C010000
940100009C0100005401000060010000

A9C900C1
01F6E5EE
E5EE0000
FC F0 02    D1640038FF04 F702 03    04    FA 05    E5 EE
E8 B600AAC607 FC EA 06    E2C5F3FBB80B0000F401F3E1C5F3C907CA08EC09E2C5F3FAF401F3E1C5F3 E5 C60E EE



function action1_Hurt()
    play_animation(1); -- 01
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action3_DrillDrive()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(2); -- 02
    move_to_target("linear_movement", 0x0064, 0xff38, 0x04); --D1 6400 38FF 04
    execute_attack(0x02); -- F7 02
    play_animation(3); -- 03
    play_animation(4); -- 04
    return_position(); --FA
    play_animation(5); -- 05
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action4_Fire()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6 00
    unpause_camera(); -- AA
    set_unit_fade_time(0x7); -- C6 07
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(6); -- 06
// E2 - add 0x02 flag to 80151922.
    set_unit_fade_wait(); -- C5
    wait(); -- F3
// FB[B80B][0000]
    set_wait(0x01); -- F4 01
    wait(); -- F3
// E1
    set_unit_fade_wait(); -- C5
    wait(); -- F3
    jump_label(); -- C9
    play_animation(7); -- 07
    jump_if_not_loaded(); -- CA
    play_animation(8); -- 08
    execute_additional_effect(); -- EC
    play_animation(9); -- 09
// E2
    set_unit_fade_wait(); -- C5
    wait(); -- F3
    return_position(); --FA
    set_wait(0x01); -- F4 01
    wait(); -- F3
// E1
    set_unit_fade_wait(); -- C5
    wait(); -- F3
    return_direction(); -- E5
    set_unit_fade_time(0xe); -- C6 0E
    return_to_idle(); -- EE
end;
