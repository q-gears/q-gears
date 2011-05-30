000000005E01600960090000CEFF12FD
1EFB0200000000001307000003231F00
0000000084010000880100008C010000
9001000094010000980100009C010000
A00100007201320172010000E60679F9
8008000090FF0000450179FFEF0C0000
20FF0000C8000000

E8000000  0 EC000000  1 F0000000  2 F4000000  3
08010000  4 18010000  5 1C01000020010000
24010000280100002C01000034010000
400100004C010000540100005C010000
640100006C010000740100007C010000
300100003C0100004801000050010000
58010000600100006801000070010000
78010000800100003801000044010000

A9C900C1
01F6E5EE
0AE5EE00
FCF002D04C0401F003F70104FAF005E5EE000000
E8B600AAFCEA06C907CA08EC09E5EE0A0000000000000



function action1_Hurt()
    play_animation(1); -- 01
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action3_Handclaw()
    enemy_set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(2); -- 02
// D0[4C04][01] - jump to enemy
    set_effect("foot_dust"); -- F0
    play_animation(3); -- 03
    execute_attack(0x01); -- F7 01
    play_animation(4); -- 04
    return_position(); --FA
    set_effect("foot_dust"); -- F0
    play_animation(5); -- 05
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action4_BeamGun()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6 00
    unpause_camera(); -- AA
    enemy_set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(6); -- 06
    jump_label(); -- C9
    play_animation(7); -- 07
    jump_if_not_loaded(); -- CA
    play_animation(8); -- 08
    execute_additional_effect(); -- EC
    play_animation(9); -- 09
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
