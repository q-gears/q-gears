// animation scripts
+00 [][]     0000 - if this is not 0 we add 0x40 bit to 8015190b
+02 []       00 - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     012c - collision radius. Set to 801518e4+6
+06 [][]     0320 - to 801518ec
+08 [][]     0320 - to 801518ee
+0a [][]     0000 - to 801518f0
+0c [][]     00fa
+0e [][]     fdee
+10 [][]     fc90 - filler?
+12 array of joints (bone indexes)
    20 00 00 00 00 00 00 00 00 20 20 00 00 00 00 00
+22 [][]     0000 - filler?
+24 array of 8 offsets to something
    000001a0 000001a4 000001a8 000001ac 000001b0 000001b4 000001b8 000001bc
+44 array of 4 something
    0159 0119 0159 0000
+4c array of 6 something
    0b16 fc78 04a3 0000 ff60 0000
+58 array of 6 something
    fe3e fb78 08df 0000 ffa0 0000
+64 [][]     012c
+66 [][]     0000 - filler?
+68 array of 32 offsets to animation scripts
    000000e8 000000ec 000000f0 000000f4 00000108 00000134 00000138 0000013c
    00000140 00000144 00000148 00000150 0000015c 00000168 00000170 00000178
    00000180 00000188 00000190 00000198 0000014c 00000158 00000164 0000016c
    00000174 0000017c 00000184 0000018c 00000194 0000019c 00000154 00000160

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
    set_effect("foot_dust"); -- F0
    play_animation(2);
    move_to_target("linear_movement", 0064, ff38, 04); -- D1
    execute_attack(02); -- F7
    play_animation(3);
    play_animation(4);
    return_position(); -- FA
    play_animation(5);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_4()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6
    unpause_camera(); -- AA
    set_unit_fade_time(07); -- C6
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(6);
    [ACTION_OPCODE e2]
end;
