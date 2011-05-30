00000100BC0230113011D4FEDAFD96FB
A8F80B0000000000130609000D231A00
000B00009C010000A0010000A4010000
A8010000AC010000B0010000B4010000
B8010000B2015901B2010000750FF8FE
DB0D000070FE2C01FB00F8FA25150000
70FE2C01F4010000

E8000000  0 EC000000  1 F0000000  2 F4000000  3
08010000  4 24010000  5 34010000  6 38010000  7
3C010000 40010000 44010000 4C010000
58010000 64010000 6C010000 74010000
7C010000840100008C01000094010000
48010000540100006001000068010000
70010000780100008001000088010000
9001000098010000500100005C010000

A9C900C1
01F6E5EE
E5EE0000
FC0203AD068A02050AD8051000F70C0405E5EE00
FCEA0607AD078A02020AAD068A02020AD8021000F7090809F0E5EE00
E8B600AAEA0AC90BCA0CEC0DEE0A0D0A00000000000



function action1_Hurt()
    play_animation(1); -- 01
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action3_MachineGun()
    set_direction(); -- FC
    play_animation(2); -- 02
    play_animation(3); -- 03
    set_effect("machinegun_fire", 0x06, 0x028a, 0x05, 0x0a) -- AD 06 8A02 05 0A
    play_sound_for_attacker(0x05, 0x0010); -- D8 05 1000
    execute_attack(0x0c); -- F7 0C
    play_animation(4); -- 04
    play_animation(5); -- 05
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action4_WMachineGun()
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(6); -- 06
    play_animation(7); -- 07
    set_effect("machinegun_fire", 0x07, 0x028a, 0x02, 0x0a) -- AD 07 8A02 02 0A
    set_effect("machinegun_fire", 0x06, 0x028a, 0x02, 0x0a) -- AD 06 8A02 02 0A
    play_sound_for_attacker(0x02, 0x0010); -- D8 02 1000
    execute_attack(0x09); -- F7 09
    play_animation(8); -- 08
    play_animation(9); -- 09
    set_effect("foot_dust"); -- F0
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action5_SmokeShot()
    load_additional_effect(); -- E8
    pause_camera_finish_animation(0); -- B6 00
    unpause_camera(); -- AA
    show_action_name(); -- EA
    play_animation(10); -- 0A
    jump_label(); -- C9
    play_animation(11); -- 0B
    jump_if_not_loaded(); -- CA
    play_animation(12); -- 0C
    execute_additional_effect(); -- EC
    play_animation(13); -- 0D
    return_to_idle(); -- EE
end;
