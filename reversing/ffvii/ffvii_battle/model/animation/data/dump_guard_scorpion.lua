01001100B004602260222C01F2F9A8F8
C6F3020000000000090E021202272400
001B0000EC010000F0010000F4010000
F8010000FC0100000002000004020000
080200008002800180020000A92539EC
E50B00001FFF6BFE9309B9FDA01F0000
1FFD000044020000

E8000000  0 EC000000  1 F0000000  2 F4000000  3
14010000  4 34010000  5 44010000  6 50010000  7
54010000  8 58010000  9 78010000  a 88010000  b
AC010000  c B8010000  d 94010000  e C4010000  f
CC010000D4010000DC010000E4010000
A0010000A8010000B4010000BC010000
C0010000C8010000D0010000D8010000
E0010000E8010000A4010000B0010000

A9C900C1
01F6E5EE
E5EE0000
B600AAEA02FCAD061405080AAD071405080AD8081000F70F0304E505EE000000
B600AAEAF006FCD1C409000016F007BE21BE25BE2AC22A08FAF0E509EE000000
E8B600AAEA0AFCC90BCA0CEC0DE5EE00
B600AAB947000E14EE000000
14FEC000
15F6E5EE
B614AAEA16FCAD061405080AAD071405080AD8081000F70F1718E519EE000000
E8B614AAEA1AFCC91BCA1CEC1DE5EE00
B614AAB946141E00EE0000000EF464F314F464F3EE0A0D0A0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000



function action1_Hurt()
    play_animation(1); -- 01
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action3_Rifle()
    pause_camera_finish_animation(0); -- B6 00
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(2); -- 02
    set_direction(); -- FC
    set_effect("machinegun_fire", 0x06, 0x0514, 0x08, 0x0a) -- AD 06 1405 08 0A
    set_effect("machinegun_fire", 0x07, 0x0514, 0x08, 0x0a) -- AD 07 1405 08 0A
    play_sound_for_attacker(0x08, 0x0010); -- D8 08 1000
    execute_attack(0x0f); -- F7 0F
    play_animation(3); -- 03
    play_animation(4); -- 04
    return_direction(); -- E5
    play_animation(5); -- 05
    return_to_idle(); -- EE
end;



function action4_ScorpionTail()
    pause_camera_finish_animation(0); -- B6 00
    unpause_camera(); -- AA
    show_action_name(); -- EA
    set_effect("foot_dust"); -- F0
    play_animation(6); -- 06
    set_direction(); -- FC
    move_to_target("linear_movement", 0x09c4, 0x0000, 0x16); --D1 C409 0000 16
    set_effect("foot_dust"); -- F0
    play_animation(7); -- 07
    execute_hurt(0x21); -- BE 21
    execute_hurt(0x25); -- BE 25
    execute_hurt(0x2a); -- BE 2A
    execute_damage(0x2a); -- C2 2A
    play_animation(8); -- 08
    return_position(); --FA
    set_effect("foot_dust"); -- F0
    return_direction(); -- E5
    play_animation(9); -- 09
    return_to_idle(); -- EE
end;



function action5_SearchScope()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6 00
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(10); -- 0A
    set_direction(); -- FC
    jump_label(); -- C9
    play_animation(11); -- 0B
    jump_if_not_loaded(); -- CA
    play_animation(12); -- 0C
    execute_additional_effect(); -- EC
    play_animation(13); -- 0D
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action6()
    pause_camera_finish_animation(0); -- B6 00
    unpause_camera(); -- AA
    set_camera(71); -- B9 47
    play_animation(0); -- 00
    play_animation(14); -- 0E
    play_animation(20); -- 14
    return_to_idle(); -- EE
end;



function action9_Rifle()
    pause_camera_finish_animation(20); -- B6 14
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(22); -- 16
    set_direction(); -- FC
    set_effect("machinegun_fire", 0x06, 0x0514, 0x08, 0x0a) -- AD 06 1405 08 0A
    set_effect("machinegun_fire", 0x07, 0x0514, 0x08, 0x0a) -- AD 07 1405 08 0A
    play_sound_for_attacker(0x08, 0x0010); -- D8 08 1000
    execute_attack(0x0f); -- F7 0F
    play_animation(23); -- 17
    play_animation(24); -- 18
    return_direction(); -- E5
    play_animation(25); -- 19
    return_to_idle(); -- EE
end;



function action10_TailLaser()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(20); -- B6 14
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(26); -- 1A
    set_direction(); -- FC
    jump_label(); -- C9
    play_animation(27); -- 1B
    jump_if_not_loaded(); -- CA
    play_animation(28); -- 1C
    execute_additional_effect(); -- EC
    play_animation(29); -- 1D
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action11()
    pause_camera_finish_animation(20); -- B6 14
    unpause_camera(); -- AA
    set_camera(70); -- B9 46
    play_animation(20); -- 14
    play_animation(30); -- 1E
    play_animation(0); -- 00
    return_to_idle(); -- EE
end;
