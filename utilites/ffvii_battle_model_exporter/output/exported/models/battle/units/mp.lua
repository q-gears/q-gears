// animation scripts
+00 [][]     0000 - if this is not 0 we add 0x40 bit to 8015190b
+02 []       80 - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     015e - collision radius. Set to 801518e4+6
+06 [][]     0640 - to 801518ec
+08 [][]     0640 - to 801518ee
+0a [][]     0000 - to 801518f0
+0c [][]     0096
+0e [][]     fda8
+10 [][]     fc18 - filler?
+12 array of joints (bone indexes)
    02 00 00 00 00 00 11 08 00 00 03 1b 16 00 00 00
+22 [][]     0000 - filler?
+24 array of 8 offsets to something
    00000188 0000018c 00000190 00000194 00000198 0000019c 000001a0 000001a4
+44 array of 4 something
    0172 0132 0172 0000
+4c array of 6 something
    0c02 f9b9 0579 0000 ff60 0000
+58 array of 6 something
    0145 fe79 0d6f 0000 ff20 0080
+64 [][]     00c8
+66 [][]     0000 - filler?
+68 array of 32 offsets to animation scripts
    000000e8 000000ec 000000f0 000000f4 00000108 0000011c 00000120 00000124
    00000128 0000012c 00000130 00000138 00000144 00000150 00000158 00000160
    00000168 00000170 00000178 00000180 00000134 00000140 0000014c 00000154
    0000015c 00000164 0000016c 00000174 0000017c 00000184 0000013c 00000148

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
    show_action_name(); -- EA
    play_animation(2);
    set_effect("machinegun_fire", 07, 01b8, 01, 0a); -- AD
    play_sound_for_attacker(01, 0010); -- D8
    execute_attack(08); -- F7
    play_animation(3);
    play_animation(4);
    play_animation(5);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_4()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(6);
    move_to_target("linear_movement", 0320, 0000, 04); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(7);
    execute_attack(04); -- F7
    play_animation(8);
    return_position(); -- FA
    set_effect("foot_dust"); -- F0
    play_animation(9);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
