010001002C01B004B0040000CEFF12FD
1EFB0600000000000000001706000000
000000007C0100008001000084010000
880100008C0100009001000094010000
980100007201320172010000110F78F8
6408000040FF00009CFA38FC11120000
40FF000064000000

E8000000  0 EC000000  1 F0000000  2 F4000000  3
10010000  4 14010000  5 180100001C010000
2001000000010000240100002C010000
38010000440100004C01000054010000
5C010000640100006C01000074010000
28010000340100004001000048010000
50010000580100006001000068010000
7001000078010000300100003C010000

A9C900C1
01F6E5EE
E5EE0000
E800FC02C903CA04EC05E5EEC7FEFF09C7FFFF09C3F40FF3B8EE



function action1_Hurt()
    play_animation(1); -- 01
    play_die_if_dead(); -- F6
    return_direction(); -- E5
    return_to_idle(); -- EE
end;



function action3_LaserCannon()
    load_additional_effect(); -- E8
    play_animation(0); -- 00
    set_direction(); -- FC
    play_animation(2); -- 02
    jump_label(); -- C9
    play_animation(3); -- 03
    jump_if_not_loaded(); -- CA
    play_animation(4); -- 04
    execute_additional_effect(); -- EC
    play_animation(5); -- 05
    return_direction(); -- E5
    return_to_idle(); -- EE
end;
