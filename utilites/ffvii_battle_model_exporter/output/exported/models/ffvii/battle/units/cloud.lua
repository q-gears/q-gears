// animation scripts
+00 [][]     0000 - if this is not 0 we add 0x40 bit to 8015190b
+02 []       80 - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     0190 - collision radius. Set to 801518e4+6
+06 [][]     0a00 - to 801518ec
+08 [][]     0a00 - to 801518ee
+0a [][]     0000 - to 801518f0
+0c [][]     0000
+0e [][]     fce0
+10 [][]     fc7c - filler?
+12 array of joints (bone indexes)
    02 00 00 00 00 00 0d 08 03 00 03 17 12 00 00 00
+22 [][]     0000 - filler?
+24 array of 8 offsets to something
    00000438 00000438 00000438 00000438 00000438 00000438 00000438 00000438
+44 array of 4 something
    0180 0132 0180 0000
+4c array of 6 something
    0399 fda8 f9ff 0000 fddc 0000
+58 array of 6 something
    fd01 ff58 f9ab 0000 fe30 0000
+64 [][]     012c
+66 [][]     0000 - filler?
+68 array of 32 offsets to animation scripts
    00000190 00000194 0000019c 000001a0 000001b0 000001c0 000001c4 000001cc
    000001d0 000001d4 000001e4 000001e8 000001ec 000001f0 000001f4 00000200
    000001fc 00000210 00000204 00000198 0000026c 00000284 00000318 0000032c
    00000358 0000036c 00000378 00000384 00000338 00000210 00000220 00000230

function action_script_1()
    play_animation(1);
    [ACTION_OPCODE fe]
end;

function action_script_2()
    return_direction(); -- E5
    play_animation(6);
    [ACTION_OPCODE f1]
end;

function action_script_3()
    [ACTION_OPCODE b3]
end;

function action_script_4()
    [ACTION_OPCODE b3]
end;

function action_script_5()
    play_animation(15);
    [ACTION_OPCODE f2]
end;

function action_script_6()
    play_animation(16);
    play_animation(17);
    [ACTION_OPCODE f2]
end;

function action_script_7()
    play_animation(18);
    [ACTION_OPCODE f2]
end;

function action_script_8()
    play_animation(5);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_9()
    [ACTION_OPCODE ab]
end;

function action_script_10()
    play_animation(19);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_11()
    play_animation(24);
    play_animation(25);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_12()
    [ACTION_OPCODE b4]
end;

function action_script_13()
    [ACTION_OPCODE 95]
end;

function action_script_14()
    [ACTION_OPCODE c4]
end;

function action_script_15()
    [ACTION_OPCODE e7]
end;

function action_script_16()
    play_animation(4);
    return_position(); -- FA
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_17()
    load_additional_effect(); -- E8
    set_direction(); -- FC
    play_animation(3);
    [ACTION_OPCODE ed]
end;

function action_script_18()
    return_direction(); -- E5
    [ACTION_OPCODE c4]
end;

function action_script_19()
    play_animation(16);
    [ACTION_OPCODE fe]
end;

function action_script_20()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_sound_for_attacker(00, 001a); -- D8
    play_animation(26);
    move_to_target("linear_movement", 04b0, 0000, 04); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(27);
    execute_attack(01); -- F7
    play_animation(30);
    play_animation(28);
    return_position(); -- FA
    set_effect("foot_dust"); -- F0
    play_animation(29);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_21()
    set_direction(); -- FC
    play_animation(3);
    [ACTION_OPCODE ed]
end;

function action_script_22()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_sound_for_attacker(00, 001a); -- D8
    play_animation(26);
    move_to_target("linear_movement", 04b0, 0000, 04); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(27);
    execute_attack(01); -- F7
    play_animation(30);
    [ACTION_OPCODE 9e]
end;

function action_script_23()
    execute_attack(01); -- F7
    play_animation(34);
    play_animation(35);
    return_position(); -- FA
    set_effect("foot_dust"); -- F0
    play_animation(29);
    return_direction(); -- E5
    return_to_idle(); -- EE
end;

function action_script_24()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_sound_for_attacker(00, 001a); -- D8
    play_animation(26);
    move_to_target("linear_movement", 04b0, 0000, 04); -- D1
    set_effect("foot_dust"); -- F0
    play_animation(27);
    execute_attack(01); -- F7
    play_animation(30);
    [ACTION_OPCODE 9e]
end;

function action_script_25()
    return_direction(); -- E5
    [ACTION_OPCODE bd]
end;

function action_script_26()
    return_direction(); -- E5
    [ACTION_OPCODE bd]
end;

function action_script_27()
    return_direction(); -- E5
    [ACTION_OPCODE bd]
end;

function action_script_28()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_sound_for_attacker(00, 001a); -- D8
    play_animation(26);
    [ACTION_OPCODE cc]
end;

function action_script_29()
    load_additional_effect(); -- E8
    set_direction(); -- FC
    play_animation(3);
    [ACTION_OPCODE ed]
end;

function action_script_30()
    load_additional_effect(); -- E8
    set_direction(); -- FC
    play_animation(3);
    [ACTION_OPCODE ed]
end;

function action_script_31()
    load_additional_effect(); -- E8
    set_direction(); -- FC
    play_animation(3);
    [ACTION_OPCODE ed]
end;
