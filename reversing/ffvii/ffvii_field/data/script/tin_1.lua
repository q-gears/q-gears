-- created by Tori

entity = {
};



temp0 = 0;
temp1 = 0;
temp2 = 0;
temp3 = 0;
temp4 = 0;
temp5 = 0;
temp6 = 10;
temp7 = 0;

temp12 = 0;
temp13 = 0;

temp19 = 0;
temp1a = 0;

temp1e = 0;
temp1f = 0;
temp20 = 0;
temp21 = 0;
temp22 = 0;



entity["DR_AN1"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--c30:	bgoff(0,3,0)

        return 0;
    end;

    script2 = function(self)
--c35:	bgon(0,3,0)

        return 0;
    end;
};



entity["DR_AN2"] = {
    on_start = function(self)
--c3a:	bgon(0,6,1)

        return 0;
    end;

    script1 = function(self)
--c40:	bgoff(0,6,1)
--c44:	bgon(0,6,2)
--c48:	wait(3,0)
--c4b:	bgoff(0,6,2)
--c4f:	bgon(0,6,3)
--c53:	wait(3,0)
--c56:	bgoff(0,6,3)
--c5a:	bgon(0,6,4)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["TR_AN"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        temp0 = 1;
        temp7 = 0;

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["TR_AN2"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        temp1 = 1;

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["TURI"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        temp2 = 1;

        return 0;
    end;

    script2 = function(self)
        temp2 = 0;

        return 0;
    end;
};



entity["ELEC"] = {
    on_start = function(self)
        while true do
            if temp0 == 1 then
--cb9:	bgon(0,1,1)
--cbd:	wait(2,0)
--cc0:	bgoff(0,1,1)
--cc4:	bgon(0,1,2)
--cc8:	wait(2,0)
--ccb:	bgoff(0,1,2)
--ccf:	bgon(0,1,3)
--cd3:	wait(2,0)
--cd6:	bgoff(0,1,3)
                if temp5 == 10 then
                    temp7 = 1;
                else
                    temp5 = temp5 + 1;
                end;
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["TURI1"] = {
    on_start = function(self)
--cef:	bgon(0,4,1)

        while true do
            if temp7 ~= 0 then
                while temp0 == 1 do
--d02:	wait(7,0)
--d05:	bgoff(0,4,1)
--d09:	bgon(0,4,2)
--d0d:	wait(7,0)
--d10:	bgoff(0,4,2)
--d14:	bgon(0,4,1)
--d18:	wait(7,0)
--d1b:	bgoff(0,4,1)
--d1f:	bgon(0,4,3)
--d23:	wait(7,0)
--d26:	bgoff(0,4,3)
--d2a:	bgon(0,4,1)

                    script:wait(0);
                end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["TURI2"] = {
    on_start = function(self)
--d33:	bgon(0,5,1)
        while true do
            if temp7 == 0 then
--d3e:	wait(a,0)
            else
                while temp0 == 1 do
--d49:	wait(7,0)
--d4c:	bgoff(0,5,1)
--d50:	bgon(0,5,2)
--d54:	wait(7,0)
--d57:	bgoff(0,5,2)
--d5b:	bgon(0,5,1)
--d5f:	wait(7,0)
--d62:	bgoff(0,5,1)
--d66:	bgon(0,5,3)
--d6a:	wait(7,0)
--d6d:	bgoff(0,5,3)
--d71:	bgon(0,5,1)

                    script:wait(0);
                end;
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["LIGHT"] = {
    on_start = function(self)
        while true do
            if temp7 ~= 0 then
                while temp0 == 1 do
--d91:	bgon(0,2,1)
                    while temp4 < 6 do
                        temp4 = temp4 + 1;
                    end;

                    temp4 = 0;
--da5:	bgoff(0,2,1)
--da9:	bgon(0,2,2)

                    while temp4 < 6 do
                        temp4 = temp4 + 1;
                    end;

                    temp4 = 0;
--dbd:	bgoff(0,2,2)
--dc1:	bgon(0,2,3)

                    while temp4 < 6 do
                        temp4 = temp4 + 1;
                    end;

                    temp4 = 0;
--dd5:	bgoff(0,2,3)
--dd9:	bgon(0,2,4)

                    while temp4 < 6 do
                        temp4 = temp4 + 1;
                    end;

                    temp4 = 0;
--ded:	bgoff(0,2,4)

                    if temp6 == 2 then
--df7:	random(5,3)
--dfa:	mod(50,3,5)
                        if temp3 <= 1 then
--e04:	wait(5,0)
                        elseif temp3 == 2 then
--e0f:	wait(a,0)
                        elseif temp3 == 3 then
--e1a:	wait(1e,0)
                        else
e1f:	wait(1,0)--
                        end;
                    end;

--e22:	bgon(0,2,1)
                    if temp6 > 2 then
                        temp6 = temp6 - 1;
                    end;

                    script:wait(0);
                end;
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["ELEC2"] = {
    on_start = function(self)
        while true do
            if temp1 == 1 then
--e3c:	bgon(0,1,1)
--e40:	wait(2,0)
--e43:	bgoff(0,1,1)
--e47:	bgon(0,1,2)
--e4b:	wait(2,0)
--e4e:	bgoff(0,1,2)
--e52:	bgon(0,1,3)
--e56:	wait(2,0)
--e59:	bgoff(0,1,3)
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["TURI1-2"] = {
    on_start = function(self)
--e62:	bgon(0,4,1)

        while true then
            if temp1 == 1 then
--e75:	wait(7,0)
--e78:	bgoff(0,4,1)
--e7c:	bgon(0,4,2)
--e80:	wait(7,0)
--e83:	bgoff(0,4,2)
--e87:	bgon(0,4,1)
--e8b:	wait(7,0)
--e8e:	bgoff(0,4,1)
--e92:	bgon(0,4,3)
--e96:	wait(7,0)
--e99:	bgoff(0,4,3)
--e9d:	bgon(0,4,1)
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["TURI2-2"] = {
    on_start = function(self)
--ea6:	bgon(0,5,1)

        while true do
            if temp1 == 1 then
--ebc:	wait(7,0)
--ebf:	bgoff(0,5,1)
--ec3:	bgon(0,5,2)
--ec7:	wait(7,0)
--eca:	bgoff(0,5,2)
--ece:	bgon(0,5,1)
--ed2:	wait(7,0)
--ed5:	bgoff(0,5,1)
--ed9:	bgon(0,5,3)
--edd:	wait(7,0)
--ee0:	bgoff(0,5,3)
--ee4:	bgon(0,5,1)
            end;

            script:wait(0);

        end;

        return 0;
    end;
};



entity["LIGHT2"] = {
    on_start = function(self)
        while true do
            if temp1 == 1 then
--ef4:	random(5,3)
--ef7:	mod(50,3,5)
                if temp3 <= 1 then
--f01:	wait(5,0)
                elseif temp3 == 2 then
--f0c:	wait(a,0)
                elseif temp3 == 3 then
--f17:	wait(1e,0)
                else
--f1c:	wait(1,0)
                end;

--f1f:	bgon(0,2,1)
--f23:	wait(2,0)
--f26:	bgoff(0,2,1)
--f2a:	bgon(0,2,2)
--f2e:	wait(2,0)
--f31:	bgoff(0,2,2)
--f35:	bgon(0,2,3)
--f39:	wait(2,0)
--f3c:	bgoff(0,2,3)
--f40:	bgon(0,2,4)
--f44:	wait(2,0)
--f47:	bgoff(0,2,4)
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["TURI1-3"] = {
    on_start = function(self)
--f50:	bgon(0,4,1)

        while true do
            if temp2 == 1 then
--f63:	wait(7,0)
--f66:	bgoff(0,4,1)
--f6a:	bgon(0,4,2)
--f6e:	wait(7,0)
--f71:	bgoff(0,4,2)
--f75:	bgon(0,4,1)
--f79:	wait(7,0)
--f7c:	bgoff(0,4,1)
--f80:	bgon(0,4,3)
--f84:	wait(7,0)
--f87:	bgoff(0,4,3)
--f8b:	bgon(0,4,1)
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["TURI2-3"] = {
    on_start = function(self)
--f94:	bgon(0,5,1)

        while true do
            if temp2 == 0 then
--eb1:	wait(a,0)
            elseif temp2 == 1 then
--faa:	wait(7,0)
--fad:	bgoff(0,5,1)
--fb1:	bgon(0,5,2)
--fb5:	wait(7,0)
--fb8:	bgoff(0,5,2)
--fbc:	bgon(0,5,1)
--fc0:	wait(7,0)
--fc3:	bgoff(0,5,1)
--fc7:	bgon(0,5,3)
--fcb:	wait(7,0)
--fce:	bgoff(0,5,3)
--fd2:	bgon(0,5,1)
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["WALL"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--fdd:	bgon(0,7,0)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["produce"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--fef:	mpnam(1)
        else
--ff3:	mpnam(0)
--ff5:	akao(0,0,0,c0,7f,0,0,0,0,0,0,0,0)
--1003:	music(0)
        end;

--1006:	idlck(47,0,1)
--100a:	idlck(46,0,1)
--100e:	idlck(3c,0,1)
--1012:	idlck(3e,0,1)

        if progress >= 108 then
            script:request_start_wait("DR_AN1", "script2", 4);
        else
            script:request_start_wait("TR_AN2", "script1", 4);
            script:request_start_wait("DR_AN1", "script2", 4);
        end;

        return 0;
    end;
};



entity["direct"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --MUSIC(1)
            --Wait(1E)
            --PMJMP(8C,0)
            --IDLCK(47,0,0)
            script:request_end_wait("cloud", "script13", 6);
            --IDLCK(47,0,1)
            script:request_start_wait("ballet", "script11", 6);
            script:request_start_wait("tifa", "script3", 6);
        else
            if progress >= 51 then
                local flag = game:variable_get("bank3[223]")
                if flag & 0x04 then
                    --CharMovable(Off)
                    --MenuAccess(Off)
                    script:request_start_wait("AD2", "script1", 6);
                end;
            else
                if progress >= 48 then
                    --CharMovable(Off)
                    --MenuAccess(Off)
                    --Wait(3C)
                    --AKAO(0,0,0,28,40,3B,0,0,0,0,0,0,0)
                    --WMODE(0,2,0)
                    --CreateWindow(0,1C,8,FA,49)
                    --Dialog(0,20)
                    --WMODE(0,0,0)
                    script:request_start_wait("ballet", "script3", 6);
                end;
            end;
        end;

        return 0;
    end;

    script1 = function(self)
--109f:	pmvie(18)
        script:request_start_wait("AD2", "script3", 2);
--10a4:	movie(f2)
        --AKAO(0,0,0,2A,40,0,0,0,0,0,0,0,0)
        --ChangeField(92,0,B5,F4,40,D,1A,0,0) -- mds7st3

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        temp20 = 1;
--10e2:	idlck(34,0,1)
        script:request_start_wait("border3", "script7", 6);
--10e9:	akao(0,0,0,2b,40,3b,0,0,0,0,0,0,0)
--10f7:	wmode(0,2,0)
--10fb:	window(0,1c,0,8,0,d4,0,29,0)
--1105:	message(0,6a)
--1108:	wclse(3)

        return 0;
    end;
};



entity["AD"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--110d:	wmode(0,2,0)
--1111:	akao(0,0,0,2b,40,3b,0,0,0,0,0,0,0)
--111f:	window(0,1c,0,8,0,7,1,29,0)
--1129:	message(0,69)

        return 0;
    end;
};



entity["AD2"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--112f:	wait(3c,0)
--1132:	akao(0,0,0,29,40,96,0,0,0,0,0,0,0)
--1140:	fade(0,0,a0,0,0,20,6,0)
--1149:	fadew
        script:request_start_wait("avaw", "script7", 6);

        while temp1e ~= 1 do
--114d:	akao(0,0,0,28,40,a0,1,0,0,0,0,0,0)
--115b:	wait(10,0)
--115e:	fade(0,0,ff,0,0,40,9,ff)
--1167:	wait(1,0)
--116a:	fade(0,0,d2,aa,aa,40,2,0)
        end;

--117d:	fade(0,0,c8,c8,c8,20,a,0)
--1186:	fadew
--1187:	wait(a,0)
--118a:	fade(0,0,a0,a0,a0,80,2,0)
--1193:	fadew
--1194:	fade(0,0,0,0,0,80,1,ff)
--119d:	fadew
--119e:	fade(0,0,a0,a0,a0,80,2,0)
--11a7:	fadew
--11a8:	fade(0,0,0,0,0,80,1,ff)
--11b1:	fadew
--11b2:	akao(0,0,0,28,40,0,0,0,0,0,0,0,0)
--11c0:	akao(0,0,0,29,40,0,0,0,0,0,0,0,0)
--11ce:	fade(0,0,0,0,0,8,5,ff)

        return 0;
    end;

    script2 = function(self)
        --Wait(3C)
        --AKAO(0,0,0,29,40,96,0,0,0,0,0,0,0)
        --FADE(0,0,A0,0,0,20,6,0)
        --WaitForFade

        while temp1e != 1 do
            --AKAO(0,0,0,28,40,A0,1,0,0,0,0,0,0)
            --Wait(10)
            --FADE(0,0,FF,0,0,40,9,FF)
            --Wait(1)
            --FADE(0,0,D2,AA,AA,40,2,0)
        end;

        --FADE(0,0,C8,C8,C8,20,A,0)
        --WaitForFade
        --Wait(A)
        --FADE(0,0,A0,A0,A0,80,2,0)
        --WaitForFade
        --FADE(0,0,0,0,0,80,1,FF)
        --WaitForFade
        --FADE(0,0,A0,A0,A0,80,2,0)
        --WaitForFade
        --FADE(0,0,0,0,0,80,1,FF)
        --WaitForFade
        --AKAO(0,0,0,28,40,0,0,0,0,0,0,0,0)
        --AKAO(0,0,0,29,40,0,0,0,0,0,0,0,0)
        --FADE(0,0,0,0,0,8,5,FF)

        return 0;
    end;

    script3 = function(self)
--127e:	wait(1,0)
--1281:	akao2(0,0,0,ca,78,0,0,0,ff,7f,0,0,0,0)
--1290:	fade(0,0,0,0,0,ff,1,ff)

        return 0;
    end;

    script4 = function(self)
--129c:	jmpb(129c)

        return 0;
    end;
};



entity["shake"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--12a8:	scr2d(0,12,0,2,0)
        else
--12b0:	akao(0,0,0,a2,40,0,0,0,0,0,0,0,0)
--12be:	akao(0,0,0,2a,40,9a,0,0,0,0,0,0,0)
--12cc:	scr2d(0,12,0,2,0)
            while true do
                script:request_end_wait("random", "script1", 6);
--12d5:	shake(0,0,2,0,0,5,2)
--12dd:	wait(a,0)
--12e0:	shake(0,0,0,0,1,0,1)
--12e8:	wait(f,0)
            end;
        end;

        return 0;
    end;

    script1 = function(self)
--12ee:	scr2d(0,12,0,2,0)
        while true do
            script:request_end_wait("random", "script1", 6);
--12f7:	shake(0,0,2,0,0,5,2)
--12ff:	wait(a,0)
--1302:	shake(0,0,0,0,1,0,1)
--130a:	wait(f,0)
        end;

        return 0;
    end;
};



entity["random"] = {
    on_start = function(self)
        while true do
--1311:	random(5,12)

            script:wait(0);
        end;

        return 0;
    end;

    script1 = function(self)
--1317:	random(5,12)
        if temp12 > 64 then
            temp19 = 10;
        elseif temp12 > 128 then
            temp19 = 15;
        elseif temp12 > 192 then
            temp19 = 20;
        end;

        return 0;
    end;
};



entity["timkp"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--133f:	sttim(0,0,0,0,f)
--1345:	wait(1,0)
        script:request_start_wait("timkp2", "script1", 6);
--134b:	wmode(3,1,1)
--134f:	window(3,8,0,a0,0,32,1,39,0)
--1359:	wspcl(3,1,38,19)
--135e:	message(3,68)

        return 0;
    end;
};



entity["timkp2"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        while true do
            local minutes = game:variable_get("bank1[ 21]");
            local seconds = game:variable_get("bank1[ 22]");

            if minutes == 0 then
                if seconds == 15 then
                    script:request_start_wait("mapj2", "script7", 6);
                else if seconds == 0 then
--1379:	idlck(34,0,1)
                    script:request_end_wait("direct", "script3", 6);
                    break;
                end;
            end;

            script:wait(0);
        end;

        return 0;
    end;
};



entity["AD3"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--1387:	join(8)
        script:request_start_wait("timkp", "script1", 6);

        return 0;
    end;
};



entity["border0"] = {
    on_start = function(self)
--138d:	line(e2,ff,8b,2,cb,ff,21,0,8b,2,cb,ff)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--13a3:	linon(0)
--13a5:	idlck(17,0,1)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--13ab:	akao(0,0,0,28,40,a7,0,0,0,0,0,0,0)
        script:request_end_wait("DR_AN1", "script1", 6);
--13bc:	wait(a,0)
--13bf:	mapjump(8a,0,ff,ff,c4,ff,11,0,80) -- cargoin

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;
};



entity["border1"] = {
    on_start = function(self)
--13d4:	line(cb,ff,97,fe,cb,ff,36,0,70,fe,cb,ff)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            if temp20 ~= 1 then
--13fa:	mapjump(8c,0,c,0,73,2,1d,0,0) -- tin_2
            end
        else
--1406:	uc(1)
--1408:	menu2(1)
--140a:	linon(0)
            script:request_start_wait("cloud", "script4", 6);
            script:request_end_wait("guard1", "script4", 6);
--1412:	idlck(34,0,1)
--1416:	uc(0)
--1418:	menu2(0)
        end;

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;
};



entity["border2"] = {
    on_start = function(self)
--1425:	line(c9,ff,2e,ff,cb,ff,34,0,24,ff,cb,ff)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--143b:	linon(1)
        else
            local flag = game:variable_get("bank3[223]")
            if (flag & 0x04) == 0x00 then
--1445:	linon(0)
            end;
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--1451:	uc(1)
--1453:	menu2(1)
--1455:	linon(0)
            script:request_start_wait("cloud", "script24", 6);
        else
--145c:	uc(1)
--145e:	menu2(1)
--1460:	linon(0)
            script:request_end_wait("ballet", "script8", 6);
            script:request_start_wait("avaw", "script8", 6);
            script:request_end_wait("cloud", "script7", 6);
        end;

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;
};



entity["border3"] = {
    on_start = function(self)
--1476:	line(c8,ff,c4,fe,cb,ff,19,0,af,fe,cb,ff)
--1484:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--1488:	uc(1)
--148a:	menu2(1)
        script:request_start_wait("cloud", "script30", 6);
--148f:	prtye(0,1,2)
--1493:	split(0,0,0,4f,0,b1,fe,c0,8,0,a,ff,0,a)
--14a2:	wcls(0)
--14a4:	wcls(1)
--14a6:	wcls(2)
--14a8:	wcls(3)
        script:request_start_wait("cloud", "script8", 6);
        script:request_end_wait("ballet", "script16", 6);
        script:request_start_wait("cloud", "script9", 6);
        script:request_end_wait("tifa", "script18", 4);
        script:request_start_wait("cloud", "script8", 6);
        script:request_end_wait("ballet", "script17", 6);
        script:request_end_wait("tifa", "script19", 6);
        script:request_end_wait("cloud", "script31", 6);

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
--14c7:	linon(1)

        return 0;
    end;

    script8 = function(self)
        return 0;
    end;
};



entity["mapj2"] = {
    on_start = function(self)
--14cd:	line(cb,ff,97,fe,cb,ff,3c,0,86,fe,cb,ff)
--14db:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--14df:	mapjump(8c,0,c,0,73,2,1d,0,0) -- tin_2
        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
--14ee:	linon(1)

        return 0;
    end;

    script8 = function(self)
        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
--14f4:	char(0)
--14f6:	pc(0)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--1501:	tlkon(1)
--1503:	solid(1)
--1505:	visi(0)
        elseif progress >= 51 then
            local flag = game:variable_get("bank3[223]")
            if flag & 0x04 then
--1517:	xyzi(0,0,48,0,c1,fe,cb,ff,2f,0)
--1522:	dir(0,40)
--1525:	wait(3c,0)
--1528:	anime1(3,1)
--152b:	anime1(4,1)
            end;
        elseif progress == 48
--1538:	tlkon(1)
--153a:	solid(1)
--153c:	visi(0)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1540:	xyzi(0,0,2,0,19,2,cb,ff,1c,0)
--154b:	dir(0,0)
--154e:	tlkon(0)
--1550:	solid(0)
--1552:	visi(1)
--1554:	akao(0,0,0,28,40,a7,0,0,0,0,0,0,0)
        script:request_end_wait("DR_AN1", "script2", 6);

        game:variable_set("progress_game", 51);

--156a:	uc(0)
--156c:	menu2(0)

        return 0;
    end;

    script4 = function(self)
--156f:	solid(1)
--1571:	slidr(0,0)
--1574:	msped(0,0,4)
--1578:	move(0,5,0,e0,fe)
--157e:	anime1(5,1)
--1581:	solid(0)
--1583:	slidr(0,22)

        return 0;
    end;

    script5 = function(self)
--1587:	canm!1(6,0,e,1)
--158c:	tura(22,4,2)

        return 0;
    end;

    script6 = function(self)
--1591:	canm!2(6,f,1d,1)
--1596:	uc(0)
--1598:	menu2(0)

        return 0;
    end;

    script7 = function(self)
--159b:	solid(1)
--159d:	slidr(0,0)
--15a0:	msped(0,0,4)
--15a4:	move(0,c9,ff,83,ff)
--15aa:	dir(0,c0)
--15ad:	canm!2(7,0,13,1)
--15b2:	wait(3c,0)
--15b5:	window(3,64,0,8,0,c1,0,39,0)
--15bf:	message(3,3)
        script:request_start_wait("ballet", "script9", 6);
--15c5:	canm!2(7,14,1d,1)
--15ca:	wait(1e,0)
--15cd:	canm!1(6,0,e,1)
--15d2:	turngen(0,60,1,a,2)
        script:request_start_wait("ballet", "script10", 6);

        return 0;
    end;

    script8 = function(self)
--15dc:	anime2(8,1)
--15df:	tura(1f,a,2)

        return 0;
    end;

    script9 = function(self)
--15e4:	anime2(9,1)
--15e7:	tura(20,a,2)

        return 0;
    end;

    script10 = function(self)
--15ec:	canm!2(a,0,1d,1)
--15f1:	window(3,8,0,8,0,bd,0,39,0)
--15fb:	message(3,9)

        return 0;
    end;

    script11 = function(self)
--15ff:	anime2(8,1)
--1602:	turngen(0,c0,2,a,1)
--1608:	canm!2(6,0,e,1)
--160d:	window(3,8,0,8,0,cb,0,39,0)
--1617:	message(3,c)
--161a:	canm!2(6,f,1d,1)
--161f:	canm!2(7,0,e,1)
--1624:	wait(1e,0)

        return 0;
    end;

    script12 = function(self)
        return 0;
    end;

    script13 = function(self)
--162f:	xyzi(0,0,55,ff,33,2,cb,ff,47,0)
--163a:	tlkon(0)
--163c:	solid(0)
--163e:	visi(1)
--1640:	solid(1)
--1642:	slidr(0,0)
--1645:	msped(0,0,8)
--1649:	move(0,b1,ff,33,2)
--164f:	akao(0,0,0,28,0,77,0,0,0,0,0,0,0)
--165d:	anime2(8,1)
--1660:	turngen(0,0,2,a,1)

        return 0;
    end;

    script14 = function(self)
--1667:	anime2(4,1)
--166a:	tura(1f,a,2)
--166e:	window(3,8,0,8,0,e0,0,29,0)
--1678:	message(3,3c)

        return 0;
    end;

    script15 = function(self)
        return 0;
    end;

    script16 = function(self)
--1680:	anime1(3,1)

        return 0;
    end;

    script17 = function(self)
--1684:	anime1(b,1)
--1687:	canm!2(6,0,e,1)
--168c:	window(3,8,0,8,0,c3,0,29,0)
--1696:	message(3,42)

        return 0;
    end;

    script18 = function(self)
--169a:	canm!2(c,0,e,1)

        return 0;
    end;

    script19 = function(self)
--16a0:	canm!2(c,f,1d,1)
--16a5:	canm!2(6,0,e,1)

        return 0;
    end;

    script20 = function(self)
        return 0;
    end;

    script21 = function(self)
        return 0;
    end;

    script22 = function(self)
        return 0;
    end;

    script23 = function(self)
--1704:	canm!1(6,f,1d,1)
--1709:	turngen(0,0,2,a,1)
--170f:	solid(0)
--1711:	slidr(0,22)
--1714:	uc(0)
--1716:	menu2(0)

        return 0;
    end;

    script24 = function(self)
--1719:	move(0,2,0,c2,fe)
--171f:	msped(0,0,4)
--1723:	move(0,36,0,bb,fe)
--1729:	canm!1(6,0,e,1)
        script:request_start_wait("tifa", "script17", 5);

        return 0;
    end;

    script25 = function(self)
--1732:	msped(0,0,4)
--1736:	move(0,40,0,bb,fe)
--173c:	canm!1(6,0,e,1)

        return 0;
    end;

    script26 = function(self)
--1742:	canm!2(6,f,1d,1)
--1747:	anime1(d,1)

        return 0;
    end;

    script27 = function(self)
--174b:	anime2(8,1)
--174e:	turngen(0,e0,2,a,1)
--1754:	canm!2(e,0,13,1)

        return 0;
    end;

    script28 = function(self)
--175a:	animw
--175b:	canm!1(6,0,e,1)
--1760:	dfanm(f,1)

        return 0;
    end;

    script29 = function(self)
--1764:	canm!2(c,f,1d,1)
--1769:	canm!2(10,0,e,1)
--176e:	solid(0)
--1770:	slidr(0,22)

        return 0;
    end;

    script30 = function(self)
--1774:	solid(1)
--1776:	slidr(0,0)
--1779:	msped(0,0,8)
--177d:	move(0,0,0,a3,fe)
--1783:	dir(0,0)
--1786:	anime1(4,1)
--1789:	dfanm(0,1)

        return 0;
    end;

    script31 = function(self)
--178d:	pmjmp(a1,0)
--1790:	anime2(8,1)
--1793:	turngen(0,0,2,a,1)
--1799:	anime1(5,1)
--179c:	solid(1)
--179e:	slidr(0,0)
--17a1:	move(0,6f,0,cf,fe)
--17a7:	anime2(11,1)
--17aa:	wait(f,0)
--17ad:	akao(0,0,0,28,7f,e9,0,0,0,0,0,0,0)
--17bb:	jump(0,0,ce,0,c9,fe,3b,0,c,0)
--17c6:	tlkon(1)
--17c8:	solid(1)
--17ca:	visi(0)
--17cc:	akao(0,0,0,c1,ff,0,0,0,0,0,0,0,0)
--17da:	akao(0,0,0,a4,ff,0,0,0,0,0,0,0,0)
--17e8:	akao(0,0,0,a5,ff,0,0,0,0,0,0,0,0)
--17f6:	akao(0,0,0,a6,ff,0,0,0,0,0,0,0,0)
--1804:	akao(0,0,0,a7,ff,0,0,0,0,0,0,0,0)
        script:request_start_wait("AD2", "script4", 0);
--1815:	fade(0,0,0,0,0,8,2,0)
--181e:	fadew
--181f:	wait(64,0)
--1822:	akao(0,0,0,28,40,0,0,0,0,0,0,0,0)
--1830:	akao(0,0,0,29,40,0,0,0,0,0,0,0,0)
--183e:	akao(0,0,0,2a,40,0,0,0,0,0,0,0,0)
--184c:	akao(0,0,0,2b,40,0,0,0,0,0,0,0,0)
--185a:	music(2)
--185c:	akao(0,0,0,c0,7f,0,0,0,0,0,0,0,0)
--186a:	akao(0,0,0,a0,7f,0,0,0,0,0,0,0,0)
--1878:	akao(0,0,0,a1,7f,0,0,0,0,0,0,0,0)
--1886:	akao(0,0,0,a2,7f,0,0,0,0,0,0,0,0)
--1894:	akao(0,0,0,a3,7f,0,0,0,0,0,0,0,0)
        game:variable_set("bank3[127]", 2);
--18a6:	mapjump(a1,0,15,0,93,fe,30,0,80)

        return 0;
    end;
};



entity["ballet"] = {
    on_start = function(self)
--18b1:	char(1)
--18b3:	pc(1)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
-- we do nothing
        elseif progress >= 51 then
--18c8:	xyzi(0,0,c6,ff,27,0,cb,ff,27,0)
--18d3:	dir(0,40)
--18d6:	tlkon(0)
--18d8:	solid(0)
--18da:	visi(1)
--18dc:	dfanm(3,1)
        else
--18e1:	tlkon(1)
--18e3:	solid(1)
--18e5:	visi(0)
        end;

        return 0;
    end;

    script1 = function(self)
--18e8:	uc(1)
--18ea:	menu2(1)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--18f4:	wsizw(1,64,0,8,0,4,1,49,0)
--18fe:	asped(0,20,0)
--1902:	anim!1(4,1)
--1905:	message(1,50)
--1908:	animw
--1909:	asped(0,10,0)
        else
--190f:	wsizw(0,8,0,8,0,b9,0,39,0)
--1919:	message(0,d)
        end;

--191c:	uc(0)
--191e:	menu2(0)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1922:	akao(0,0,0,28,40,a7,0,0,0,0,0,0,0)
        script:request_end_wait("DR_AN1", "script1", 6);
--1933:	xyzi(0,0,f9,ff,62,2,cb,ff,1d,0)
--193e:	dir(0,0)
--1941:	tlkon(0)
--1943:	solid(0)
--1945:	visi(1)
--1947:	solid(1)
--1949:	slidr(0,0)
--194c:	msped(0,0,8)
--1950:	move(0,28,0,b1,1)
        script:request_start_wait("avaf", "script3", 6);
        script:request_start_wait("usan", "script3", 6);
--195c:	move(0,12,0,20,0)
--1962:	dfanm(5,1)
--1965:	wait(3c,0)
--1968:	dfanm(6,1)
--196b:	wait(1e,0)
--196e:	anime2(7,1)
--1971:	move(0,c6,ff,27,0)
--1977:	anim!1(8,1)
--197a:	turngen(0,40,1,a,2)
--1980:	anim!1(9,1)
--1983:	wait(f,0)
--1986:	akao(0,0,0,28,0,ab,1,0,0,0,0,0,0)
--1994:	animw
--1995:	anim!2(a,1)
        script:request_start_wait("guard1", "script3", 6);
--199b:	dfanm(3,1)

        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
--19bb:	canim2(b,8,e,1)

        return 0;
    end;

    script7 = function(self)
--19c1:	canm!2(b,e,15,1)
--19c6:	wait(3c,0)
--19c9:	canm!2(b,15,1d,1)

        return 0;
    end;

    script8 = function(self)
--19cf:	canm!2(d,0,1d,1)
--19d4:	window(0,8,0,8,0,fa,0,39,0)
--19de:	message(0,2)

        return 0;
    end;

    script9 = function(self)
--19e2:	asped(0,20,0)
--19e6:	canm!2(d,1e,3b,1)
--19eb:	anim!2(e,1)
--19ee:	dfanm(0,1)
--19f1:	move(0,0,0,de,ff)
--19f7:	anime2(8,1)
--19fa:	tura(1e,a,2)
--19fe:	asped(0,10,0)
--1a02:	canm!2(f,0,e,1)
--1a07:	window(0,8,0,8,0,d5,0,39,0)
--1a11:	message(0,4)
--1a14:	canm!2(f,f,1d,1)
        script:request_start_wait("aval", "script9", 6);
        script:request_start_wait("avaf", "script9", 6);

        return 0;
    end;

    script10 = function(self)
--1a20:	move(0,fe,ff,1d,ff)
        script:request_start_wait("cloud", "script8", 6);
--1a29:	asped(0,10,0)
--1a2d:	anim!1(10,1)
--1a30:	tura(1e,a,2)
--1a34:	window(0,8,0,8,0,5,1,29,0)
--1a3e:	message(0,5)
--1a41:	move(0,e2,ff,d5,fe)
--1a47:	canm!2(11,0,e,1)
        script:request_start_wait("aval", "script7", 6);
--1a4f:	window(0,8,0,8,0,a,1,29,0)
--1a59:	message(0,7)
--1a5c:	canm!2(11,f,1d,1)
--1a61:	move(0,1a,0,be,fe)
--1a67:	dira(23)
--1a69:	anime1(12,1)
        script:request_start_wait("avaf", "script7", 6);
--1a6f:	window(0,8,0,8,0,f8,0,49,0)
--1a79:	message(0,8)
--1a7c:	anime2(8,1)
--1a7f:	tura(1e,a,2)
        script:request_end_wait("cloud", "script10", 6);
--1a86:	move(0,9,0,f5,fe)
--1a8c:	window(0,8,0,8,0,7,1,49,0)
--1a96:	message(0,a)
--1a99:	window(0,8,0,8,0,df,0,39,0)
--1aa3:	asped(0,10,0)
--1aa7:	anim!2(13,1)
--1aaa:	message(0,b)
        script:request_end_wait("cloud", "script11", 6);
--1ab0:	akao(0,0,0,a6,0,a,0,0,0,0,0,0,0)
--1abe:	fade(0,0,0,0,0,10,2,0)
--1ac7:	fadew
--1ac8:	akao(0,0,0,2a,40,0,0,0,0,0,0,0,0)
--1ad6:	akao(0,0,0,a2,7f,0,0,0,0,0,0,0,0)
        script:request_start_wait("direct", "script1", 6);

        return 0;
    end;

    script11 = function(self)
--1ae8:	xyzi(0,0,b1,ff,38,2,cb,ff,1e,0)
--1af3:	tlkon(0)
--1af5:	solid(0)
--1af7:	visi(1)
--1af9:	solid(1)
--1afb:	slidr(0,0)
--1afe:	msped(0,0,8)
--1b02:	move(0,1,0,38,2)
--1b08:	move(0,1,0,d8,0)
--1b0e:	anime2(14,1)
--1b11:	window(1,8,0,8,0,89,0,29,0)
--1b1b:	message(1,2e)
--1b1e:	dfanm(6,1)
        script:request_start_wait("aval", "script10", 6);
--1b24:	wait(4,0)
        script:request_start_wait("avaf", "script10", 6);
--1b2a:	wait(4,0)
        script:request_start_wait("avaw", "script10", 6);
--1b30:	window(1,8,0,8,0,ec,0,29,0)
--1b3a:	message(1,2f)

        return 0;
    end;

    script12 = function(self)
--1b3e:	move(0,12,0,5b,fe)
--1b44:	dir(0,0)
--1b47:	canm!1(15,0,c,1)
--1b4c:	turngen(0,4,2,a,1)
--1b52:	wait(1e,0)
--1b55:	window(0,8,0,8,0,93,0,29,0)
--1b5f:	message(0,31)
--1b62:	canm!1(15,c,10,1)
--1b67:	turngen(0,fc,2,a,1)
--1b6d:	wait(1e,0)
--1b70:	window(0,8,0,8,0,c5,0,29,0)
--1b7a:	message(0,32)
--1b7d:	canm!1(15,10,14,1)
--1b82:	turngen(0,4,2,a,1)
--1b88:	wait(1e,0)
--1b8b:	canm!1(16,0,e,1)
--1b90:	turngen(0,80,2,a,1)
--1b96:	move(0,10,0,43,ff)
--1b9c:	turngen(0,c0,2,4,1)
--1ba2:	canm!2(17,0,e,1)
--1ba7:	window(1,8,0,8,0,c7,0,39,0)
--1bb1:	message(1,33)
        script:request_start_wait("shain1", "script5", 5);

        return 0;
    end;

    script13 = function(self)
--1bb8:	asped(0,20,0)
--1bbc:	canm!2(17,e,1d,1)
--1bc1:	move(0,e6,ff,45,ff)
--1bc7:	anim!1(18,1)
--1bca:	wait(a,0)
--1bcd:	sound(0,1c,0,40)
--1bd2:	animw
--1bd3:	turngen(0,c8,2,4,1)
        script:request_end_wait("shain1", "script6", 4);
--1bdc:	canm!1(13,0,e,1)
--1be1:	jump(0,0,12,0,75,ff,2a,0,6,0)
--1bec:	tura(25,6,2)
--1bf0:	window(2,64,0,8,0,ad,0,29,0)
--1bfa:	message(2,38)
        script:request_start_wait("shain1", "script7", 4);
        script:request_end_wait("tifa", "script4", 6);
--1c03:	asped(0,10,0)
--1c07:	canm!1(13,f,1d,1)
--1c0c:	window(2,64,0,8,0,94,0,39,0)
--1c16:	message(2,3b)
        script:request_start_wait("tifa", "script5", 6);
--1c1c:	move(0,f0,ff,36,1)
        script:request_end_wait("cloud", "script14", 6);
--1c25:	anim!2(f,1)
--1c28:	window(1,64,0,8,0,db,0,39,0)
--1c32:	message(1,3d)
--1c35:	akao(0,0,0,28,40,90,1,0,0,0,0,0,0)
--1c43:	fade(0,0,fa,fa,fa,ff,2,0)
--1c4c:	wait(1,0)
--1c4f:	fade(0,0,0,0,0,ff,1,ff)
--1c58:	fade(0,0,fa,fa,fa,ff,2,0)
--1c61:	wait(1,0)
--1c64:	fade(0,0,0,0,0,ff,1,ff)
--1c6d:	fade(0,0,fa,fa,fa,ff,2,0)
--1c76:	wait(1,0)
--1c79:	fade(0,0,0,0,0,ff,1,ff)
--1c82:	wait(3c,0)
--1c85:	akao(0,0,0,28,40,6,1,0,0,0,0,0,0)
--1c93:	wait(a,0)
--1c96:	akao(0,0,0,28,40,d3,0,0,0,0,0,0,0)
--1ca4:	shake(0,0,2,0,0,8,4)
        script:request_end_wait("TURI", "script1", 6);
        script:request_start_wait("tifa", "script7", 6);
        script:request_start_wait("cloud", "script16", 6);
--1cb5:	dfanm(16,1)
--1cb8:	wait(3c,0)
--1cbb:	akao(0,0,0,29,40,ca,0,0,0,0,0,0,0)
--1cc9:	shake(0,0,0,0,1,0,1)
        script:request_end_wait("TURI", "script2", 2);
--1cd4:	akao(0,0,0,28,40,35,0,0,0,0,0,0,0)
--1ce2:	dfanm(6,1)
        script:request_end_wait("tifa", "script8", 6);
--1ce8:	akao(0,0,0,2a,40,d3,0,0,0,0,0,0,0)
        script:request_start_wait("shake", "script1", 6);
        script:request_end_wait("TR_AN", "script1", 2);
--1cfc:	wait(1e,0)
        script:request_end_wait("cloud", "script17", 6);
--1d02:	tura(1e,a,2)
--1d06:	canm!2(f,0,e,1)
--1d0b:	window(1,64,0,8,0,cf,0,39,0)
--1d15:	message(1,43)
--1d18:	canm!2(f,f,1d,1)
--1d1d:	canm!2(11,0,e,1)
--1d22:	dfanm(19,1)
--1d25:	window(1,64,0,8,0,e7,0,39,0)
--1d2f:	message(1,44)
        script:request_end_wait("tifa", "script9", 6);
--1d35:	canm!2(1a,0,7,1)
--1d3a:	window(1,64,0,8,0,b5,0,39,0)
--1d44:	message(1,46)
--1d47:	canm!2(1a,8,e,1)
--1d4c:	akao(0,0,0,28,40,3b,0,0,0,0,0,0,0)
        script:request_start_wait("tifa", "script10", 6);
        script:request_start_wait("cloud", "script18", 6);
--1d60:	canm!2(1b,0,e,1)
--1d65:	wmode(2,2,0)
--1d69:	window(2,1c,0,8,0,1a,1,29,0)
--1d73:	message(2,47)
--1d76:	wmode(2,0,0)
        script:request_start_wait("cloud", "script19", 6);
--1d7d:	canm!2(1b,f,1d,1)
        script:request_end_wait("tifa", "script11", 6);
--1d85:	anim!1(8,1)
--1d88:	turngen(0,0,2,a,1)
--1d8e:	wait(4,0)
--1d91:	move(0,e9,ff,3d,0)
        script:request_start_wait("tifa", "script12", 6);
--1d9a:	anim!1(10,1)
--1d9d:	turngen(0,80,2,a,1)
--1da3:	window(1,64,0,8,0,d1,0,39,0)
--1dad:	message(1,49)
--1db0:	slidr(0,0)
--1db3:	solid(1)
--1db5:	move(0,3a,0,eb,ff)
        script:request_start_wait("tifa", "script16", 6);
--1dbe:	asped(0,20,0)
--1dc2:	anim!1(8,1)
--1dc5:	turngen(0,c0,2,4,1)
--1dcb:	animw
--1dcc:	asped(0,10,0)
--1dd0:	anim!1(9,1)
--1dd3:	wait(f,0)
--1dd6:	akao(0,0,0,28,7f,ab,1,0,0,0,0,0,0)
--1de4:	animw
--1de5:	anim!2(a,1)
--1de8:	dfanm(3,1)

        return 0;
    end;

    script14 = function(self)
--1dec:	asped(0,20,0)
--1df0:	anim!2(e,1)
--1df3:	asped(0,10,0)
--1df7:	anim!1(1c,1)
--1dfa:	tura(1e,a,2)
--1dfe:	move(0,2,0,f2,fe)
--1e04:	dfanm(6,1)
--1e07:	anime2(1d,1)
--1e0a:	wsizw(1,8,0,8,0,8d,0,29,0)
--1e14:	message(1,5b)
--1e17:	animw
        script:request_start_wait("avaw", "script11", 6);

        return 0;
    end;

    script15 = function(self)
--1e1c:	anime1(13,1)
--1e1f:	wsizw(1,8,0,8,0,8f,0,39,0)
--1e29:	message(1,5d)
--1e2c:	prtye(0,1,2)
--1e30:	tura(1e,4,2)
        script:request_end_wait("AD", "script1", 6);
--1e37:	anime2(7,1)
--1e3a:	message(1,5e)
        script:request_end_wait("AD3", "script1", 6);
--1e40:	uc(0)
--1e42:	menu2(0)

        return 0;
    end;

    script16 = function(self)
--1e45:	anime1(1e,1)
--1e48:	wsizw(1,be,0,8,0,df,0,39,0)
--1e52:	message(1,5f)

        return 0;
    end;

    script17 = function(self)
--1e56:	idlck(46,0,1)
--1e5a:	anime2(8,1)
--1e5d:	turngen(0,40,2,a,1)
--1e63:	asped(0,20,0)
--1e67:	anim!1(18,1)
--1e6a:	wait(a,0)
--1e6d:	sound(0,1c,0,40)
--1e72:	akao(0,0,0,2b,7f,a7,0,0,0,0,0,0,0)
        script:request_end_wait("DR_AN2", "script1", 2);
        script:request_end_wait("WALL", "script1", 2);
--1e86:	asped(0,10,0)
--1e8a:	anime2(8,1)
--1e8d:	tura(1e,a,2)
--1e91:	wsizw(1,be,0,8,0,d4,0,39,0)
--1e9b:	message(1,61)
--1e9e:	anime2(8,1)
--1ea1:	turngen(0,40,2,a,1)
--1ea7:	anime2(1f,1)
--1eaa:	wait(a,0)
--1ead:	akao(0,0,0,28,7f,e9,0,0,0,0,0,0,0)
--1ebb:	jump(0,0,ce,0,c9,fe,3b,0,c,0)
--1ec6:	tlkon(1)
--1ec8:	solid(1)
--1eca:	visi(0)

        return 0;
    end;
};



entity["tifa"] = {
    on_start = function(self)
--1ecd:	char(2)
--1ecf:	pc(2)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1edf:	xyzi(0,0,b1,ff,38,2,cb,ff,1e,0)
--1eea:	tlkon(0)
--1eec:	solid(0)
--1eee:	visi(1)
--1ef0:	solid(1)
--1ef2:	slidr(0,0)
--1ef5:	msped(0,0,8)
--1ef9:	move(0,48,0,6,2)
--1eff:	turngen(0,0,2,a,1)

        return 0;
    end;

    script4 = function(self)
--1f06:	move(0,f4,ff,c7,1)
--1f0c:	msped(0,0,10)
--1f10:	move(0,e1,ff,8d,ff)
--1f16:	msped(0,0,8)
--1f1a:	anime2(3,1)
--1f1d:	wsizw(0,27,0,31,0,a3,0,29,0)
--1f27:	message(0,3a)

        return 0;
    end;

    script5 = function(self)
--1f2b:	anime1(4,1)
--1f2e:	move(0,1f,0,e2,0)

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
--1f4a:	canm!2(6,0,9,1)
--1f4f:	dfanm(7,1)

        return 0;
    end;

    script8 = function(self)
--1f53:	tura(1e,a,2)
--1f57:	dfanm(0,1)
--1f5a:	wsizw(2,be,0,8,0,bf,0,49,0)
--1f64:	message(2,41)

        return 0;
    end;

    script9 = function(self)
--1f68:	anim!2(3,1)
--1f6b:	wsizw(2,be,0,8,0,cd,0,29,0)
--1f75:	message(2,45)

        return 0;
    end;

    script10 = function(self)
--1f79:	turngen(0,0,2,a,1)
--1f7f:	canm!2(8,0,e,1)

        return 0;
    end;

    script11 = function(self)
--1f85:	canm!2(8,f,1d,1)
--1f8a:	anime2(9,1)
--1f8d:	tura(1e,a,2)
--1f91:	wsizw(2,be,0,8,0,f8,0,39,0)
--1f9b:	message(2,48)

        return 0;
    end;

    script12 = function(self)
--1f9f:	tura(1f,a,2)

        return 0;
    end;

    script13 = function(self)
        return 0;
    end;

    script14 = function(self)
        return 0;
    end;

    script15 = function(self)
        return 0;
    end;

    script16 = function(self)
--1fe3:	move(0,f3,ff,f2,ff)
--1fe9:	move(0,25,0,cd,fe)
--1fef:	anim!2(c,1)
--1ff2:	wsizw(2,be,0,8,0,c,1,39,0)
--1ffc:	message(2,55)
--1fff:	slidr(0,0)
--2002:	msped(0,0,4)
--2006:	move(0,66,0,d1,fe)
--200c:	dir(0,40)
--200f:	canm!2(8,0,e,1)
        script:request_start_wait("cloud", "script23", 6);

        while temp20 ~= 1 do
--2017:	canm!2(8,f,13,1)
--201c:	wait(3c,0)
--201f:	canm!2(8,9,e,1)
--2024:	wait(3c,0)
        end;

        return 0;
    end;

    script17 = function(self)
--2032:	wait(1e,0)
--2035:	anime2(9,1)
--2038:	tura(1e,a,2)
--203c:	canm!2(a,0,e,1)
--2041:	dfanm(b,1)
--2044:	wsizw(2,be,0,8,0,e5,0,39,0)
--204e:	message(2,56)
        script:request_end_wait("cloud", "script26", 6);
--2054:	canm!2(a,f,1d,1)
--2059:	anim!1(9,1)
--205c:	turngen(0,40,2,a,1)
        script:request_end_wait("cloud", "script25", 6);
        script:request_start_wait("AD2", "script2", 6);
--2068:	wait(3c,0)
--206b:	akao(0,0,0,c1,3c,0,0,0,0,0,0,0,0)
        script:request_start_wait("cloud", "script16", 6);
--207c:	canm!2(6,0,9,1)
--2081:	dfanm(7,1)
--2084:	wait(3c,0)
        script:request_start_wait("cloud", "script28", 6);
--208a:	anim!1(9,1)
--208d:	tura(1e,a,2)
--2091:	wsizw(2,be,0,8,0,dd,0,49,0)
--209b:	message(2,57)
--209e:	akao(0,0,0,2b,40,3c,0,0,0,0,0,0,0)
        script:request_start_wait("cloud", "script18", 6);
--20af:	canm!2(8,0,e,1)
--20b4:	dfanm(7,1)
--20b7:	wmode(0,2,0)
--20bb:	wsizw(0,1c,0,8,0,ef,0,29,0)
--20c5:	message(0,58)
        script:request_start_wait("cloud", "script29", 6);
--20cb:	wsizw(0,1c,0,8,0,ef,0,29,0)
--20d5:	message(0,59)
        temp21 = 1;
--20dc:	canm!2(8,f,1d,1)
--20e1:	akao(0,0,0,c0,7f,0,0,0,0,0,0,0,0)
--20ef:	music(3)
        script:request_start_wait("ballet", "script14", 6);
--20f4:	wsizw(2,be,0,8,0,93,0,29,0)
--20fe:	message(2,5a)
        script:request_end_wait("cloud", "script27", 6);

        return 0;
    end;

    script18 = function(self)
--2107:	dfanm(0,1)
--210a:	wsizw(1,64,0,8,0,89,0,29,0)
--2114:	message(1,60)

        return 0;
    end;

    script19 = function(self)
--2118:	solid(1)
--211a:	slidr(0,0)
--211d:	msped(0,0,8)
--2121:	move(0,27,0,cf,fe)
--2127:	move(0,6f,0,cf,fe)
--212d:	anime2(9,1)
--2130:	tura(1e,a,2)
--2134:	wsizw(1,64,0,8,0,ea,0,39,0)
--213e:	message(1,62)
--2141:	anime2(9,1)
--2144:	turngen(0,40,2,a,1)
--214a:	anime2(d,1)
--214d:	wait(f,0)
--2150:	akao(0,0,0,28,7f,e9,0,0,0,0,0,0,0)
--215e:	jump(0,0,ce,0,c9,fe,3b,0,c,0)
--2169:	tlkon(1)
--216b:	solid(1)
--216d:	visi(0)

        return 0;
    end;
};



entity["aval"] = {
    on_start = function(self)
--2170:	char(3)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--217b:	xyzi(0,0,d0,ff,82,ff,cb,ff,2b,0)
--2186:	ofst(0,0,0,0,0,0,0,8,0,0,0)
--2192:	dir(0,36)
            while true do
--2195:	canm!2(3,0,0,1)
--219a:	wait(1e,0)
--219d:	canm!2(3,0,e,1)
--21a2:	wait(1e,0)
--21a5:	canm!2(3,f,1d,1)
--21aa:	wait(1e,0)
--21ad:	asped(0,8,0)
--21b1:	canm!2(4,0,e,1)
--21b6:	wait(3c,0)
--21b9:	canm!2(4,f,1d,1)
--21be:	asped(0,10,0)
--21c2:	wait(3c,0)
            end;
        elseif progress >= 51 then
--21d1:	xyzi(0,0,a1,ff,dc,fe,cb,ff,32,0)
--21dc:	dir(0,20)
--21df:	canm!2(5,0,0,1)
            local flags = game:variable_get("bank3[223]");
            if flags & 0x01 then
                --DIR(0,40)
                --KAWAI(0,0,0,0,0)
            elseif flags & 0x04 then
                --DIR(0,40)
                --KAWAI(0,0,0,0,0)
            end;
        else
            --TalkSwitch(Off)
            --SolidObject(Off)
            --VISI(Off)
        end;

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        local flags = game:variable_get("bank3[223]")
        if bit.band(flags, hex.to_dec('0x04')) then
            --WSIZW(1,8,0,8,0,E7,0,49,0)
            --Dialog(1,1A)
        else
            --CANM!2(5,0,E,1)
            if bit.band(flags, hex.to_dec('0x01')) then
                --KAWAI(0,1,1,0,0)
                --TURA(1E,A,2)
                --WSIZW(1,8,0,8,0,1B,1,39,0)
                --Dialog(1,19)
                --TURNGEN(0,40,2,A,1)
                --KAWAI(0,0,0,0,0)
            else
                game:variable_set("bank3[223]", bit.bor(flags, hex.to_dec('0x01')));
                --WSIZW(1,8,0,8,0,7,1,39,0)
                --Dialog(1,18)
            end;

            --CANM!2(5,F,1D,1)
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2276:	xyzi(0,0,f9,ff,62,2,cb,ff,1d,0)
--2281:	tlkon(0)
--2283:	solid(0)
--2285:	visi(1)
--2287:	solid(1)
--2289:	slidr(0,0)
--228c:	msped(0,0,8)
--2290:	move(0,c6,ff,1b,2)
        script:request_start_wait("avaw", "script3", 6);

        return 0;
    end;

    script4 = function(self)
--229a:	move(0,fa,ff,da,1)
--22a0:	move(0,db,ff,31,1)
--22a6:	dir(0,c0)
--22a9:	dfanm(6,1)

        return 0;
    end;

    script5 = function(self)
--22ad:	move(0,fd,ff,8b,ff)
--22b3:	turngen(0,40,0,a,2)

        return 0;
    end;

    script6 = function(self)
--22ba:	move(0,1,0,c1,fe)
--22c0:	move(0,a1,ff,dc,fe)
--22c6:	dir(0,20)
--22c9:	dfanm(5,1)
--22cc:	canm!2(5,0,0,1)
--22d1:	solid(0)
--22d3:	slidr(0,22)

        return 0;
    end;

    script7 = function(self)
--22d7:	wait(a,0)
--22da:	kawai(7)

        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    script9 = function(self)
--2307:	solid(1)
--2309:	slidr(0,0)

        return 0;
    end;

    script10 = function(self)
--230d:	animw
--230e:	asped(0,20,0)
--2312:	anim!2(9,1)
--2315:	asped(0,10,0)
--2319:	tura(1f,8,2)
--231d:	anime2(a,1)
--2320:	turngen(0,80,2,a,1)
--2326:	solid(1)
--2328:	msped(0,0,8)
--232c:	move(0,9,0,84,fe)
--2332:	tlkon(1)
--2334:	solid(1)
--2336:	visi(0)

        return 0;
    end;
};



entity["avaw"] = {
    on_start = function(self)
--2339:	char(4)
--233b:	slidr(0,a)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--2347:	xyzi(0,0,2f,0,26,ff,cb,ff,2a,0)
--2352:	ofst(0,0,0,8,0,0,0,0,0,0,0)
--235e:	dir(0,b0)
            while true do
--2361:	canm!2(3,9,9,1)
--2366:	wait(1e,0)
--2369:	canm!2(3,9,e,1)
--236e:	wait(1e,0)
            end;
        elseif progress >= 51 then
--237d:	xyzi(0,0,6e,0,af,fe,cb,ff,37,0)
--2388:	dir(0,60)
--238b:	canm!2(4,0,e,1)
        else
--2392:	tlkon(1)
--2394:	solid(1)
--2396:	visi(0)
        end;

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        --CANM!1(4,F,1D,1)
        --Wait(4)
        --TURA(1E,A,2)

        local flag = game:variable_get("bank3[223]")
        if bit.band(flag, hex.to_dec('0x04')) then
            if temp1f == 1 then
                --WSIZW(3,8,0,8,0,B8,0,39,0)
                --Dialog(3,14)
                --ANIME2(5,1)
                --TURNGEN(0,60,1,A,2)
                --CANM!1(4,0,E,1)
            else
                temp13 = 0;

                --WSIZW(3,8,0,8,0,DC,0,49,0)
                --Choice(5,3,11,2,3,13)
                if temp13 == 2 then
                    --CANM!2(6,0,E,1)
                    --WSIZW(3,8,0,8,0,11,1,39,0)
                    --Dialog(3,12)
                    --CANM!2(6,F,1D,1)
                elseif temp13 == 3 then
                    --ANIME2(7,1)
                    --WSIZW(3,8,0,8,0,9,1,39,0)
                    --Dialog(3,13)
                    local love_point_tifa = game:variable_get("love_point_tifa");
                    love_point_tifa = love_point_tifa - 3;
                    game:variable_set("love_point_tifa", love_point_tifa);
                end;

                --ANIME2(5,1)
                --TURNGEN(0,60,1,A,2)
                --CANM!1(4,0,E,1)
                temp1f = 1;
            end;
        else
            --CharMovable(Off)
            --MenuAccess(Off)
            --PMJMP(8F,0)
            --ANIME1(7,1)
            --WSIZW(3,8,0,8,0,F5,0,39,0)
            --Dialog(3,E)
            --CANM!1(4,0,E,1)
            --TURNGEN(0,60,1,A,2)
            --WSIZW(3,8,0,8,0,DD,0,49,0)
            --Dialog(3,10)
            game:variable_set("bank3[223]", bit.bor(flag, hex.to_dec('0x04')));
            --Wait(A)
            --ChangeField(8F,0,0,0,0,0,0,0,1C) -- rootmap
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2478:	xyzi(0,0,f9,ff,62,2,cb,ff,1d,0)
--2483:	tlkon(0)
--2485:	solid(0)
--2487:	visi(1)
--2489:	solid(1)
--248b:	slidr(0,0)
--248e:	msped(0,0,8)
--2492:	move(0,ff,ff,bb,1)

        return 0;
    end;

    script4 = function(self)
--2499:	move(0,1,0,19,1)
--249f:	dir(0,e0)
--24a2:	dfanm(8,1)
        script:request_start_wait("avaf", "script4", 6);
        script:request_start_wait("aval", "script4", 6);

        return 0;
    end;

    script5 = function(self)
--24ac:	move(0,fd,ff,47,ff)
--24b2:	turngen(0,40,0,a,2)

        return 0;
    end;

    script6 = function(self)
--24b9:	move(0,1,0,c1,fe)
--24bf:	move(0,6e,0,af,fe)
--24c5:	dir(0,60)
--24c8:	dfanm(0,1)
--24cb:	canm!2(4,0,e,1)
--24d0:	solid(0)
--24d2:	slidr(0,22)

        return 0;
    end;

    script7 = function(self)
--24d6:	anime2(9,1)
--24d9:	tura(1e,a,2)
--24dd:	anime2(a,1)
--24e0:	window(0,8,0,8,0,f9,0,39,0)
--24ea:	message(0,15)
--24ed:	animw
        script:request_start_wait("cloud", "script5", 6);
--24f1:	canm!2(b,0,e,1)
--24f6:	window(0,8,0,8,0,c7,0,39,0)
--2500:	message(0,16)
--2503:	canm!2(b,e,13,1)
--2508:	anime2(a,1)
--250b:	window(0,8,0,8,0,ed,0,39,0)
--2515:	message(0,17)
        temp1e = 1;
--251c:	wait(a,0)
--251f:	anime2(5,1)
--2522:	turngen(0,60,1,a,2)
        script:request_start_wait("cloud", "script6", 6);

        return 0;
    end;

    script8 = function(self)
--252c:	canm!1(4,f,1d,1)
--2531:	tura(1e,a,2)

        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
--253a:	animw
--253b:	asped(0,20,0)
--253f:	anim!2(d,1)
--2542:	tura(1f,4,2)
--2546:	anime2(9,1)
--2549:	asped(0,10,0)
--254d:	turngen(0,80,2,a,1)
--2553:	msped(0,0,8)
--2557:	move(0,9,0,84,fe)
--255d:	akao(0,0,0,28,40,a7,0,0,0,0,0,0,0)
--256b:	tlkon(1)
--256d:	solid(1)
--256f:	visi(0)
        script:request_start_wait("shain1", "script4", 6);

        return 0;
    end;

    script11 = function(self)
--2575:	akao(0,0,0,28,40,9a,0,0,0,0,0,0,0)
--2583:	tlkon(0)
--2585:	solid(0)
--2587:	visi(1)
--2589:	move(0,2,0,c2,fe)
--258f:	dfanm(e,1)
--2592:	window(2,64,0,8,0,c6,0,29,0)
--259c:	message(2,5c)
--259f:	move(0,9,0,84,fe)
--25a5:	tlkon(1)
--25a7:	solid(1)
--25a9:	visi(0)
        script:request_start_wait("ballet", "script15", 6);

        return 0;
    end;
};



entity["avaf"] = {
    on_start = function(self)
--25af:	char(5)
--25b1:	slidr(0,a)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--25bd:	xyzi(0,0,2f,0,c2,ff,cb,ff,28,0)
--25c8:	dir(0,c0)
--25cb:	canm!2(3,0,9,1)
--25d0:	wait(1e,0)
--25d3:	canm!2(3,9,13,1)
--25d8:	wait(1e,0)
--25db:	canm!2(3,13,1d,1)
--25e0:	wait(1e,0)
        elseif progress >= 51 then
--25ed:	xyzi(0,0,55,0,dc,fe,cb,ff,2e,0)
--25f8:	dir(0,58)
--25fb:	dfanm(4,1)
--25fe:	solid(0)
--2600:	slidr(0,22)
            while true do
--2603:	canim2(4,0,0,1)
--2608:	wait(3c,0)
--260b:	anime1(4,1)
--260e:	wait(1e,0)
            end;
        elseif progress == 48 then
--261d:	tlkon(1)
--261f:	solid(1)
--2621:	visi(0)
        end;

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        --ANIMW
        --ANIM!1(5,1)
        --TURA(1E,A,2)

        local flag = game:variable_get("bank3[223]")
        if bit.band(flag, hex.to_dec('0x04')) then
            --WSIZW(1,8,0,8,0,C4,0,39,0)
            --Dialog(1,1F)
        elseif bit.band(flag, hex.to_dec('0x02')) then
            --WSIZW(2,8,0,8,0,F,1,39,0)
            --Dialog(2,1B)
        else
            if temp1a == 1 then
                --CharMovable(Off)
                --MenuAccess(Off)
                temp13 = 0;

                --WSIZW(2,8,0,8,0,E4,0,49,0)
                --Choice(5,2,1C,2,3,13)
                if temp13 == 2 then
                    --WSIZW(2,8,0,8,0,1E,1,39,0)
                    --Dialog(2,1D)
                elseif temp13 == 3 then
                    --WSIZW(2,8,0,8,0,1B,1,39,0)
                    --Dialog(2,1E)
                end;
                game:variable_set("bank3[223]", bit.bor(flag, hex.to_dec('0x02')));

                --CharMovable(On)
                --MenuAccess(On)
            else
                --WSIZW(2,8,0,8,0,F,1,39,0)
                --Dialog(2,1B)
                temp1a = 1;
            end;
        end;

        --CharMovable(On)
        --MenuAccess(On)
        --TURNGEN(0,58,1,A,2)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--26c6:	xyzi(0,0,f9,ff,62,2,cb,ff,1d,0)
--26d1:	tlkon(0)
--26d3:	solid(0)
--26d5:	visi(1)
--26d7:	solid(1)
--26d9:	slidr(0,0)
--26dc:	msped(0,0,8)
--26e0:	move(0,38,0,ee,1)
        script:request_start_wait("aval", "script3", 6);

        return 0;
    end;

    script4 = function(self)
--26ea:	move(0,fa,ff,da,1)
--26f0:	move(0,2f,0,28,1)
--26f6:	dir(0,0)
--26f9:	dfanm(6,1)

        return 0;
    end;

    script5 = function(self)
--26fd:	move(0,fd,ff,dc,ff)
--2703:	turngen(0,40,0,a,2)

        return 0;
    end;

    script6 = function(self)
--270a:	move(0,1,0,c1,fe)
--2710:	move(0,55,0,dc,fe)
--2716:	dir(0,58)
--2719:	dfanm(4,1)
--271c:	solid(0)
--271e:	slidr(0,22)
        while true do
--2721:	canim2(4,0,0,1)
--2726:	wait(3c,0)
--2729:	anime1(4,1)
--272c:	wait(1e,0)
        end;

        return 0;
    end;

    script7 = function(self)
--2732:	wait(a,0)
--2735:	anim!2(7,1)
--2738:	tura(1f,a,2)
--273c:	canm!2(8,0,e,1)

        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    script9 = function(self)
--2762:	solid(1)
--2764:	slidr(0,0)

        return 0;
    end;

    script10 = function(self)
--2768:	animw
--2769:	anim!2(b,1)
--276c:	tura(1f,a,2)
--2770:	anime2(7,1)
--2773:	turngen(0,80,2,a,1)
--2779:	wait(a,0)
--277c:	msped(0,0,8)
--2780:	move(0,9,0,84,fe)
--2786:	tlkon(1)
--2788:	solid(1)
--278a:	visi(0)

        return 0;
    end;
};



entity["guard1"] = {
    on_start = function(self)
--278d:	char(6)
--278f:	tlkon(1)
--2791:	solid(1)
--2793:	visi(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        script:request_end_wait("avaw", "script4", 6);
        script:request_end_wait("avaw", "script5", 6);
--279e:	wait(1e,0)
        script:request_start_wait("avaf", "script5", 6);
        script:request_end_wait("aval", "script5", 6);
        script:request_start_wait("shain1", "script3", 6);

        return 0;
    end;

    script4 = function(self)
--27ab:	akao(0,0,0,28,40,a7,0,0,0,0,0,0,0)
--27b9:	xyzi(0,0,f3,ff,c,fe,cb,ff,35,0)
--27c4:	dir(0,80)
--27c7:	tlkon(0)
--27c9:	solid(0)
--27cb:	visi(1)
--27cd:	solid(1)
--27cf:	slidr(0,0)
--27d2:	msped(0,0,8)
--27d6:	move(0,2,0,b1,fe)
--27dc:	anime2(3,1)
--27df:	window(0,8,0,8,0,10,1,29,0)
--27e9:	message(0,26)
--27ec:	turngen(0,0,1,a,2)
--27f2:	move(0,f3,ff,c,fe)
--27f8:	tlkon(1)
--27fa:	solid(1)
--27fc:	visi(0)

        return 0;
    end;
};



entity["shain1"] = {
    on_start = function(self)
--27ff:	char(7)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--280a:	xyzi(0,0,48,0,a1,fe,cb,ff,2f,0)
--2815:	dir(0,48)
            while true do
--2818:	canm!2(3,e,e,1)
--281d:	wait(1e,0)
--2820:	canm!2(3,e,1d,1)
--2825:	canm!2(4,0,e,1)
--282a:	wait(1e,0)
--282d:	canm!2(4,e,1d,1)
--2832:	wait(1e,0)
--2835:	canm!2(3,0,e,1)
--283a:	wait(1e,0)
            end;
        elseif progress >= 51 then
--2849:	tlkon(1)
--284b:	solid(1)
--284d:	visi(0)
        else
--2851:	xyzi(0,0,5b,0,dc,fe,cb,ff,2e,0)
--285c:	dir(0,78)
--285f:	solid(1)
--2861:	slidr(0,0)
--2864:	dfanm(5,1)
        end;

        return 0;
    end;

    script1 = function(self)
--2868:	wsizw(2,8,0,8,0,d7,0,49,0)
--2872:	message(2,67)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2877:	anim!2(0,1)
--287a:	turngen(0,c0,0,a,2)
--2880:	msped(0,0,8)
--2884:	move(0,ff,ff,87,fe)
--288a:	dfanm(6,1)
--288d:	turngen(0,0,0,a,2)
--2893:	canm!2(7,0,e,1)
--2898:	window(0,8,0,8,0,d3,0,29,0)
--28a2:	message(0,27)
--28a5:	canm!2(7,f,1d,1)
--28aa:	anime1(8,1)
--28ad:	move(0,f3,ff,c,fe)
--28b3:	tlkon(1)
--28b5:	solid(1)
--28b7:	visi(0)
        script:request_start_wait("avaw", "script6", 6);
        script:request_start_wait("aval", "script6", 6);
        script:request_start_wait("avaf", "script6", 6);
        script:request_start_wait("cloud", "script3", 6);
        script:request_start_wait("ballet", "script6", 6);

        return 0;
    end;

    script4 = function(self)
--28c9:	wait(1e,0)
--28cc:	solid(1)
--28ce:	slidr(0,0)
--28d1:	turngen(0,0,2,a,1)
--28d7:	animw
--28d8:	canm!2(7,0,e,1)
--28dd:	wsizw(0,be,0,8,0,f2,0,29,0)
--28e7:	message(0,30)
--28ea:	canm!2(7,f,1d,1)
        script:request_start_wait("ballet", "script12", 6);
--28f2:	msped(0,0,6)
--28f6:	move(0,9,0,eb,fe)
--28fc:	move(0,c9,ff,51,ff)
--2902:	dir(0,40)
--2905:	anim!2(9,1)
--2908:	asped(0,20,0)
--290c:	dfanm(a,1)

        return 0;
    end;

    script5 = function(self)
--2912:	canm!2(b,0,5,1)
--2917:	jump(0,0,c9,ff,51,ff,2b,0,4,0)
--2922:	window(0,8,0,8,0,52,0,19,0)
--292c:	message(0,34)
--292f:	window(0,8,0,8,0,b0,0,29,0)
--2939:	message(0,35)
        script:request_start_wait("ballet", "script13", 6);
        while true do
--293f:	canm!2(b,5,9,1)
        end;

        return 0;
    end;

    script6 = function(self)
--2947:	jump(0,0,c9,ff,51,ff,2b,0,8,0)
--2952:	window(0,8,0,8,0,79,0,19,0)
--295c:	message(0,36)
--295f:	window(0,8,0,8,0,30,1,39,0)
--2969:	message(0,37)

        return 0;
    end;

    script7 = function(self)
--296d:	animw
--296e:	canm!2(c,0,5,1)
--2973:	window(1,8,0,8,0,6,1,39,0)
--297d:	message(1,39)

        while true do
--2980:	canm!2(c,5,9,1)
        end;

        return 0;
    end;
};



entity["dranker"] = {
    on_start = function(self)
--2988:	char(8)
--298a:	talkr(0,96)
        local progress = game:variable_get("progress_game");
        if progress >= 108 then
--2995:	tlkon(1)
--2997:	solid(1)
--2999:	visi(0)
        else
--299d:	xyzi(0,0,c6,ff,f7,0,cb,ff,25,0)
--29a8:	dir(0,40)
--29ab:	solid(1)
--29ad:	slidr(0,0)
        end;

        while true do
--29b1:	dfanm(0,2)
--29b4:	canm!2(0,0,b,2)
--29b9:	wait(3c,0)
--29bc:	canm!2(0,b,12,2)
--29c1:	wait(3c,0)
--29c4:	canm!2(0,b,12,2)
--29c9:	wait(3c,0)
        end;

        return 0;
    end;

    script1 = function(self)
--29cf:	uc(1)
--29d1:	menu2(1)
--29d3:	wsizw(0,8,0,8,0,1a,1,39,0)
--29dd:	message(0,2d)
        script:request_start_wait("ballet", "script7", 6);
--29e3:	uc(0)
--29e5:	menu2(0)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["beggar"] = {
    on_start = function(self)
--29e9:	char(9)
--29eb:	xyzi(0,0,58,0,c9,1,e9,ff,49,0)
--29f6:	dir(0,0)
--29f9:	solid(1)
--29fb:	slidr(0,0)
--29fe:	talkr(0,c8)

        while true do
--2a02:	anime1(1,2)
--2a05:	dfanm(1,2)
--2a08:	wait(3c,0)
--2a0b:	wait(3c,0)
--2a0e:	canm!2(0,0,e,2)
--2a13:	wait(3c,0)
--2a16:	canm!2(0,f,1d,2)
        end;

        return 0;
    end;

    script1 = function(self)
--2a1e:	uc(1)
--2a20:	menu2(1)
--2a22:	canm!2(0,0,e,2)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            if temp 22 == 1 then
--2a35:	wsizw(1,94,0,8,0,d3,0,29,0)
--2a3f:	message(1,66)
            elseif temp21 == 1 then
--2a4a:	wsizw(1,94,0,8,0,da,0,39,0)
--2a54:	message(1,64)
--2a57:	akao(0,0,0,28,40,68,1,0,0,0,0,0,0)
--2a65:	st-itm(0,7,0,1)
--2a6a:	window(2,3d,0,a,0,b6,0,19,0)
--2a74:	message(2,65)
                temp22 = 1;
            else
--2a7d:	window(1,94,0,8,0,5,1,39,0)
--2a87:	message(1,63)
            end;
        else
--2a8c:	window(1,94,0,8,0,d0,0,39,0)
--2a96:	message(1,21)
--2a99:	canm!2(0,f,1d,2)
        end;

--2a9e:	uc(0)
--2aa0:	menu2(0)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["usan"] = {
    on_start = function(self)
--2aa4:	char(10)

        local progress = game:variable_get("progress_game");
        if progress >= 51 then
--2aae:	tlkon(1)
--2ab0:	solid(1)
--2ab2:	visi(0)
        else
--2ab6:	xyzi(0,0,d2,ff,9a,fe,cb,ff,34,0)
--2ac1:	dir(0,a0)
--2ac4:	solid(1)
--2ac6:	slidr(0,0)
        end;

        while true do
--2aca:	canm!2(1,0,13,1)
--2acf:	wait(3c,0)
--2ad2:	canm!2(1,14,2c,1)
--2ad7:	wait(3c,0)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2ade:	canm!1(1,0,13,1)
--2ae3:	tura(1f,a,2)
--2ae7:	animw
--2ae8:	asped(0,20,0)
--2aec:	canm!2(1,14,2c,1)
--2af1:	anim!2(2,1)
        script:request_start_wait("woman3", "script3", 6);
--2af7:	wait(1e,0)
--2afa:	canm!1(1,0,13,1)
--2aff:	turngen(0,20,1,a,2)
--2b05:	msped(0,0,8)
--2b09:	asped(0,10,0)
--2b0d:	dfanm(3,1)
--2b10:	fmove(0,f9,ff,9,fe)
--2b16:	tlkon(1)
--2b18:	solid(1)
--2b1a:	visi(0)

        return 0;
    end;
};



entity["woman3"] = {
    on_start = function(self)
--2b1f:	char(11)

        local progress = game:variable_get("progress_game");
        if progress >= 51 then
--2b29:	tlkon(1)
--2b2b:	solid(1)
--2b2d:	visi(0)
        else
--2b31:	xyzi(0,0,a5,ff,dc,fe,cb,ff,33,0)
--2b3c:	dir(0,20)
--2b3f:	solid(1)
--2b41:	slidr(0,0)
        end;

        while true do
--2b45:	anim!2(1,1)
--2b48:	wait(3c,0)
--2b4b:	wait(3c,0)
--2b4e:	wait(1e,0)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2b55:	canm!2(2,0,e,1)
--2b5a:	wait(1e,0)
--2b5d:	canm!2(2,f,1d,1)
--2b62:	msped(0,0,8)
--2b66:	dfanm(3,1)
--2b69:	fmove(0,e4,ff,ad,fe)
--2b6f:	fmove(0,f9,ff,9,fe)
--2b75:	tlkon(1)
--2b77:	solid(1)
--2b79:	visi(0)

        return 0;
    end;
};