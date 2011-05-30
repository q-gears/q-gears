// animation scripts
+00 [][]     0000 - if this is not 0 we add 0x40 bit to 8015190b
+02 []       00 - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     015e - collision radius. Set to 801518e4+6
+06 [][]     07d0 - to 801518ec
+08 [][]     0c80 - to 801518ee
+0a [][]     ff60 - to 801518f0
+0c [][]     0032
+0e [][]     fd58
+10 [][]     fb96 - filler?
+12 array of joints (bone indexes)
    03 00 00 00 00 00 18 13 05 0e 05 25 1f 00 00 00
+22 [][]     0000 - filler?
+24 array of 8 offsets to something
    000001c4 000001c8 000001cc 000001d0 000001d4 000001d8 000001dc 000001e0
+44 array of 4 something
    0172 0132 0172 0000
+4c array of 6 something
    0c9c f138 fcd7 0000 0000 0000
+58 array of 6 something
    fcce ff78 f579 0000 ff30 0000
+64 [][]     012c
+66 [][]     0000 - filler?
+68 array of 32 offsets to animation scripts
    000000e8 000000ec 000000f0 000000f4 00000108 0000011c 0000012c 0000013c
    0000014c 00000154 00000170 00000178 00000184 00000190 00000198 0000015c
    000001a4 000001ac 000001b4 000001bc 00000174 00000180 0000018c 00000194
    0000019c 000001a0 000001a8 000001b0 000001b8 000001c0 0000017c 00000188

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
    play_animation(14);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_3()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(2);
    move_to_target("linear_movement", 012c, 0000, 08); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(3);
    execute_attack(0f); -- F7
    play_animation(4);
    return_position(); -- FA
    set_effect("foot_dust"); -- F0
    play_animation(5);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_4()
    set_direction(); -- FC
    show_action_name(); -- EA
    set_effect("foot_dust"); -- F0
    play_animation(6);
    move_to_target("linear_movement", 03e8, 0000, 08); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(7);
    execute_attack(05); -- F7
    play_animation(8);
    return_position(); -- FA
    set_effect("foot_dust"); -- F0
    play_animation(9);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_5()
    load_additional_effect(); -- E8
    play_animation(0);
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(10);
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
    load_additional_effect(); -- E8
    play_animation(0);
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(10);
    jump_label(); -- C9
    play_animation(11);
    jump_if_not_loaded(); -- CA
    play_animation(12);
    execute_additional_effect(); -- EC
    play_animation(13);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_7()
    load_additional_effect(); -- E8
    play_animation(0);
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(14);
    jump_label(); -- C9
    play_animation(15);
    jump_if_not_loaded(); -- CA
    play_animation(16);
    execute_additional_effect(); -- EC
    play_animation(17);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_8()
    execute_hurt(0f); -- BE
    execute_damage(05); -- C2
    return_to_idle(); -- EE
end;

function action_script_9()
    execute_hurt(00); -- BE
    execute_hurt(0f); -- BE
    execute_damage(05); -- C2
    return_to_idle(); -- EE
end;

function action_script_15()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(2);
    move_to_target("linear_movement", 012c, 0000, 08); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(3);
    execute_attack(0f); -- F7
    play_animation(4);
    return_position(); -- FA
    set_effect("foot_dust"); -- F0
    play_animation(5);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
