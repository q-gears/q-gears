// animation scripts
+00 [][]     0000 - if this is not 0 we add 0x40 bit to 8015190b
+02 []       01 - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     02bc - collision radius. Set to 801518e4+6
+06 [][]     1130 - to 801518ec
+08 [][]     1130 - to 801518ee
+0a [][]     fed4 - to 801518f0
+0c [][]     fdda
+0e [][]     fb96
+10 [][]     f8a8 - filler?
+12 array of joints (bone indexes)
    0b 00 00 00 00 00 13 06 09 00 0d 23 1a 00 00 0b
+22 [][]     0000 - filler?
+24 array of 8 offsets to something
    0000019c 000001a0 000001a4 000001a8 000001ac 000001b0 000001b4 000001b8
+44 array of 4 something
    01b2 0159 01b2 0000
+4c array of 6 something
    0f75 fef8 0ddb 0000 fe70 012c
+58 array of 6 something
    00fb faf8 1525 0000 fe70 012c
+64 [][]     01f4
+66 [][]     0000 - filler?
+68 array of 32 offsets to animation scripts
    000000e8 000000ec 000000f0 000000f4 00000108 00000124 00000134 00000138
    0000013c 00000140 00000144 0000014c 00000158 00000164 0000016c 00000174
    0000017c 00000184 0000018c 00000194 00000148 00000154 00000160 00000168
    00000170 00000178 00000180 00000188 00000190 00000198 00000150 0000015c

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
    set_direction(); -- FC
    play_animation(2);
    play_animation(3);
    set_effect("machinegun_fire", 06, 028a, 05, 0a); -- AD
    play_sound_for_attacker(05, 0010); -- D8
    execute_attack(0c); -- F7
    play_animation(4);
    play_animation(5);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_4()
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(6);
    play_animation(7);
    set_effect("machinegun_fire", 07, 028a, 02, 0a); -- AD
    set_effect("machinegun_fire", 06, 028a, 02, 0a); -- AD
    play_sound_for_attacker(02, 0010); -- D8
    execute_attack(09); -- F7
    play_animation(8);
    play_animation(9);
    set_effect("foot_dust"); -- F0
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_5()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(10);
    jump_label(); -- C9
    play_animation(11);
    jump_if_not_loaded(); -- CA
    play_animation(12);
    execute_additional_effect(); -- EC
    play_animation(13);
    return_to_idle(); -- EE
end;
