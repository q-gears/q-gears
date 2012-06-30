// animation scripts
+00 [][]     0001 - if this is not 0 we add 0x40 bit to 8015190b
+02 []       11 - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     04b0 - collision radius. Set to 801518e4+6
+06 [][]     2260 - to 801518ec
+08 [][]     2260 - to 801518ee
+0a [][]     012c - to 801518f0
+0c [][]     f9f2
+0e [][]     f8a8
+10 [][]     f3c6 - filler?
+12 array of joints (bone indexes)
    02 00 00 00 00 00 09 0e 02 12 02 27 24 00 00 1b
+22 [][]     0000 - filler?
+24 array of 8 offsets to something
    000001ec 000001f0 000001f4 000001f8 000001fc 00000200 00000204 00000208
+44 array of 4 something
    0280 0180 0280 0000
+4c array of 6 something
    25a9 ec39 0be5 0000 ff1f fe6b
+58 array of 6 something
    0993 fdb9 1fa0 0000 fd1f 0000
+64 [][]     0244
+66 [][]     0000 - filler?
+68 array of 32 offsets to animation scripts
    000000e8 000000ec 000000f0 000000f4 00000114 00000134 00000144 00000150
    00000154 00000158 00000178 00000188 000001ac 000001b8 00000194 000001c4
    000001cc 000001d4 000001dc 000001e4 000001a0 000001a8 000001b4 000001bc
    000001c0 000001c8 000001d0 000001d8 000001e0 000001e8 000001a4 000001b0

function action_script_0()
    animation_reset(); -- A9 this increment pointer by 2 and execute animation on second pointer. This called if we back from other action using EE.
    jump_label(); -- C9
    play_animation(0);
    jump(); -- C1
end;

function action_script_1()
    play_animation(1);
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_2()
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_3()
    pause_camera_finish_animation(0); -- B6
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(2);
    set_direction(); -- FC
    set_effect("machinegun_fire", 06, 0514, 08, 0a); -- AD
    set_effect("machinegun_fire", 07, 0514, 08, 0a); -- AD
    play_sound_for_attacker(08, 0010); -- D8
    execute_attack(0f); -- F7
    play_animation(3);
    play_animation(4);
    return_direction(); -- E5
    play_animation(5);
    return_to_idle(); -- EE
end;

function action_script_4()
    pause_camera_finish_animation(0); -- B6
    unpause_camera(); -- AA
    show_action_name(); -- EA
    set_effect("foot_dust"); -- F0
    play_animation(6);
    set_direction(); -- FC
    move_to_target("linear_movement", 09c4, 0000, 16); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(7);
    execute_hurt(21); -- BE
    execute_hurt(25); -- BE
    execute_hurt(2a); -- BE
    execute_damage(2a); -- C2
    play_animation(8);
    return_position(); -- FA
    set_effect("foot_dust"); -- F0
    return_direction(); -- E5
    play_animation(9);
    return_to_idle(); -- EE
end;

function action_script_5()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(10);
    set_direction(); -- FC
    jump_label(); -- C9
    play_animation(11);
    jump_if_not_loaded(); -- CA
    play_animation(12);
    execute_additional_effect(); -- EC
    play_animation(13);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_6()
    pause_camera_finish_animation(0); -- B6
    unpause_camera(); -- AA
    set_camera(47); -- B9
    play_animation(0);
    play_animation(14);
    play_animation(20);
    return_to_idle(); -- EE
end;

function action_script_7()
    play_animation(20);
    [ACTION_OPCODE fe]
end;

function action_script_8()
    play_animation(21);
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_9()
    pause_camera_finish_animation(20); -- B6
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(22);
    set_direction(); -- FC
    set_effect("machinegun_fire", 06, 0514, 08, 0a); -- AD
    set_effect("machinegun_fire", 07, 0514, 08, 0a); -- AD
    play_sound_for_attacker(08, 0010); -- D8
    execute_attack(0f); -- F7
    play_animation(23);
    play_animation(24);
    return_direction(); -- E5
    play_animation(25);
    return_to_idle(); -- EE
end;

function action_script_10()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(20); -- B6
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(26);
    set_direction(); -- FC
    jump_label(); -- C9
    play_animation(27);
    jump_if_not_loaded(); -- CA
    play_animation(28);
    execute_additional_effect(); -- EC
    play_animation(29);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_11()
    pause_camera_finish_animation(20); -- B6
    unpause_camera(); -- AA
    set_camera(46); -- B9
    play_animation(20);
    play_animation(30);
    play_animation(0);
    return_to_idle(); -- EE
end;

function action_script_14()
    play_animation(14);
    set_wait(64); -- F4
    wait(); -- F3
    play_animation(20);
    set_wait(64); -- F4
    wait(); -- F3
    return_to_idle(); -- EE
end;
