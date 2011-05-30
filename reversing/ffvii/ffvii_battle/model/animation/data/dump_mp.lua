animation scripts
// 208
+00 [][]     0000                             - if this is not 0 we add 0x40 bit to 8015190b
+02 []       80                               - 0x3f - dead type. 0x80 - play secondary animation
+03 []       00
+04 [][]     5E01                             - collision radius. Set to 801518e4+6
+06 [][]     4006                             - 801518ec
+08 [][]     4006                             - 801518ee
+0a [][]     0000                             - 801518f0
+0c [][]     9600
+0e [][]     A8FD
+10
18FC

+12
02 00 00 00 00 00 11 08 00 00 03 1B 16 00 00 00 - effect joints (bones indexes) + 0x12

+22
0000

+24 [][][][] 88010000                         - offset to something1
+28 [][][][] 8C010000                         - offset to something2
+2c [][][][] 90010000                         - offset to something3
+30 [][][][] 94010000                         - offset to something4
+34 [][][][] 98010000                         - offset to something5
+38 [][][][] 9C010000                         - offset to something6
+3c [][][][] A0010000                         - offset to something7
+40 [][][][] A4010000                         - offset to something8

+44 [][]     7201                             - something 1.
+46 [][]     3201                             - something 2.
+48 [][]     7201                             - something 3.
+4a [][]     0000                             - something 4.

+4c [][]     020C                             - something 1.
+4e [][]     B9F9                             - something 2.
+50 [][]     7905                             - something 3.
+52 [][]     0000                             - something 4.
+54 [][]     60FF                             - something 5.
+56 [][]     0000                             - something 6.

+58 [][]     4501                             - something 1.
+5a [][]     79FE                             - something 2.
+5c [][]     6F0D                             - something 3.
+5e [][]     0000                             - something 4.
+60 [][]     20FF                             - something 5.
+62 [][]     8000                             - something 6.

+64 [][]     C800
0000

+68 array of 0x20 script offsets (0x4 size each)
E8000000 0  EC000000 1  F0000000 2  F4000000 3
08010000 4  1C010000 5  20010000 6  24010000 7
28010000 8  2C010000 9  30010000 a  38010000 b
44010000 c  50010000 d  58010000 e  60010000 f
68010000 10 70010000 11 78010000 12 80010000 13
34010000 14 40010000 15 4C010000 16 54010000 17
5C010000 18 64010000 19 6C010000 1a 74010000 1b
7C010000 1c 84010000 1d 3C010000 1e 48010000 1f
// data
A9C900C1 0
01F6E5EE 1
E5EE0000 2
FCEA02AD07B801010AD8011000F708030405E5EE 3
FCF006D12003000004F007F70408FAF009E5EE54 4



function action0_Idle()
// A9[][00] this increment pointer by 2 and execute animation on second pointer. This called if we back from other action using EE.
    jump_label(); -- C9
    play_animation(0); -- 00
    jump(); -- C1
end;



function action1_Hurt()
    play_animation(1); -- 01
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action2_???()
    return_direction(); -- E5
    return_to_idle(); -- EE
end;




function action3_MachineGun()
    set_direction(); -- FC
    show_action_name(); -- EA
    play_animation(2); -- 02
    set_effect("machinegun_fire", 0x07, 0x01b8, 0x01, 0x0a) -- AD 07 B801 01 0A
    play_sound_for_attacker(0x01, 0x0010); -- D8 01 1000
    execute_attack(0x08); -- F7 08
    play_animation(3); -- 03
    play_animation(4); -- 04
    play_animation(5); -- 05
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action4_Tonfa()
    set_direction(); -- FC
    set_effect("foot_dust"); -- F0
    play_animation(6); -- 06
    move_to_target("linear_movement", 0x0320, 0x0000, 0x04); --D1 2003 0000 04
    set_effect("foot_dust"); -- F0
    play_animation(7); -- 07
    execute_attack(0x04); -- F7 04
    play_animation(8); -- 08
    return_position(); --FA
    set_effect("foot_dust"); -- F0
    play_animation(9); -- 09
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
