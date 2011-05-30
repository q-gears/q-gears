--direction pointer
--[[
08900E80 0
08910E80 8
28910E80 9
48910E80 a
68910E80 b
88910E80 c
A8910E80 d
C8910E80 e
E8910E80 f
10 08920E8028920E8048920E8068920E8088920E80A8920E80C8920E80E8920E8008930E8028930E8048930E8068930E8088930E80A8930E80C8930E80E8930E80
20 08940E8028940E8048940E8068940E8088940E80A8940E80C8940E80E8940E8008950E8028950E8048950E8068950E8088950E80A8950E80C8950E80E8950E80
30 08960E802C960E8054960E8078960E8098960E80B8960E80D8960E8018970E8044970E806C970E8088970E80A4970E80BC970E80D4970E80EC970E80
40 08980E80
41 28980E80
42 48980E80
43 68980E80
44 A4980E80
45 F8980E80
46 28990E80
47 40990E80
48 58990E80
49 70990E80
4b A8990E80C4990E80E8990E800C9A0E802C9A0E80
50 489A0E80609A0E80789A0E80909A0E80A89A0E80C49A0E80E49A0E80049B0E80F09B0E80CC9C0E80E89C0E80009D0E80189D0E80309D0E804C9D0E80
60 8C9D0E80AC9D0E80CC9D0E80EC9D0E800C9E0E802C9E0E804C9E0E80
]]

-- position pointer
--[[
F88F0E80 0
18900E80 1
38900E80 2
58900E80 3
78900E80 4
98900E80 5
B8900E80 6
D8900E80 7
F8900E80 8
18910E80 9
38910E80 a
58910E80 b
78910E80 c
98910E80 d
B8910E80 e
D8910E80 f
10 F8910E8018920E8038920E8058920E8078920E8098920E80B8920E80D8920E80F8920E8018930E8038930E8058930E8078930E8098930E80B8930E80D8930E80
20 F8930E8018940E8038940E8058940E8078940E8098940E80B8940E80D8940E80F8940E8018950E8038950E8058950E8078950E8098950E80B8950E80D8950E80
30 F8950E8018960E8040960E8068960E8088960E80A8960E80C8960E80E8960E8008970E8028970E8060970E8078970E8098970E80B0970E80C8970E80E0970E80
40 F8970E8018980E8038980E8058980E8078980E80D4980E801C990E8034990E804C990E8064990E807C990E809C990E80B4990E80D4990E80FC990E801C9A0E80
50 3C9A0E80549A0E806C9A0E80849A0E809C9A0E80B49A0E80D49A0E80F49A0E80149B0E80BC9C0E80DC9C0E80F49C0E800C9D0E80249D0E803C9D0E805C9D0E80
60 7C9D0E809C9D0E80BC9D0E80DC9D0E80FC9D0E801C9E0E803C9E0E80
]]

function camera_start_position_01()
end;
function camera_start_direction_01()
    set_direction(0x03e8, 0xfc18, 0x1388); --FA E803 18FC 8813
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_02()
end;
function camera_start_direction_02()
    set_direction(0xec78, 0xff9c, 0xec78); --FA 78EC 9CFF 78EC
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_03()
end;
function camera_start_direction_03()
    set_direction(0xfc18, 0xf830, 0xfc18); --FA 18FC 30F8 18FC
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_04()
end;
function camera_start_direction_04()
    set_direction(0xf830, 0xff9c, 0x2710); --FA 30F8 9CFF 1027
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_05()
end;
function camera_start_direction_05()
    set_direction(0xf448, 0xf060, 0x07d0); --FA 48F4 60F0 D007
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_06()
end;
function camera_start_direction_06()
    set_direction(0xf448, 0xec78, 0x0fa0); --FA 48F4 78EC A00F
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_07()
end;
function camera_start_direction_07()
    set_direction(0x03e8, 0xf830, 0x0fa0); --FA E803 30F8 A00F
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_3f()
end;
function camera_start_direction_3f()
    set_direction(0x0000, 0xf910, 0xf20c); --FA 0000 10F9 0CF2
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_4a()
end;
function camera_start_direction_4a()
    set_direction(0x03e8, 0x0000, 0xd8f0); --FA E803 0000 F0D8
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;



function camera_start_position_5f()
end;
function camera_start_direction_5f()
    set_direction(0xec78, 0xf448, 0x0190); --FA 78EC 48F4 9001
    set_transition("direct_transition", 0x3c); --E2 3C
    set_wait(0x3c); --F5 3C
    wait(); --F4
    loop(); --FF
end;
