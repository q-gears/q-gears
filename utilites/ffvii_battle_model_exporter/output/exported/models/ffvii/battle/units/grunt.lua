// animation scripts
+00 [][]     0000 - if this is not 0 we add 0x40 bit to 8015190b
+02 []       00 - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     015e - collision radius. Set to 801518e4+6
+06 [][]     0960 - to 801518ec
+08 [][]     0960 - to 801518ee
+0a [][]     0000 - to 801518f0
+0c [][]     ffce
+0e [][]     fd12
+10 [][]     fb1e - filler?
+12 array of joints (bone indexes)
    02 00 00 00 00 00 13 07 00 00 03 23 1f 00 00 00
+22 [][]     0000 - filler?
+24 array of 8 offsets to something
    00000184 00000188 0000018c 00000190 00000194 00000198 0000019c 000001a0
+44 array of 4 something
    0172 0132 0172 0000
+4c array of 6 something
    06e6 f979 0880 0000 ff90 0000
+58 array of 6 something
    0145 ff79 0cef 0000 ff20 0000
+64 [][]     00c8
+66 [][]     0000 - filler?
+68 array of 32 offsets to animation scripts
    000000e8 000000ec 000000f0 000000f4 00000108 00000118 0000011c 00000120
    00000124 00000128 0000012c 00000134 00000140 0000014c 00000154 0000015c
    00000164 0000016c 00000174 0000017c 00000130 0000013c 00000148 00000150
    00000158 00000160 00000168 00000170 00000178 00000180 00000138 00000144

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
    play_animation(10);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_3()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(2);
    [ACTION_OPCODE d0]
end;

function action_script_4()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6
    unpause_camera(); -- AA
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(6);
    jump_label(); -- C9
    play_animation(7);
    jump_if_not_loaded(); -- CA
    play_animation(8);
    execute_additional_effect(); -- EC
    play_animation(9);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
