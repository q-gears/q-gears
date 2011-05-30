-- created by Tori

entity = {
};



temp25 = 0; -- set when talked to oyaji1
temp28 = 0; -- to jump to lower floor
temp29 = 0; -- to jump to lower floor
temp2a = 0; -- set to 1 when activate obasan
temp2d = 0; -- if we talk to battet before tifa return to bar (imposible)
temp2e = 0; -- set when talked to oyaji1
temp2f = 0; -- when barret free pass to bar



entity["door1"] = {
    on_start = function(self)
        --BGCLR(0,1)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["door2"] = {
    on_start = function(self)
        --BGCLR(0,2)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["door3"] = {
    on_start = function(self)
        --BGCLR(0,3)

        return 0;
    end;

    script1 = function(self)
        --BGON(0,3,0)

        return 0;
    end;

    script2 = function(self)
        --BGOFF(0,3,0)

        return 0;
    end;
};



entity["door4"] = {
    on_start = function(self)
        --BGCLR(0,4)

        return 0;
    end;

    script1 = function(self)
        --BGON (00,04,00)

        return 0;
    end;

    script2 = function(self)
        --BGOFF (00,04,00)

        return 0;
    end;
};



entity["door5"] = {
    on_start = function(self)
        --BGCLR(0,5)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["light"] = {
    on_start = function(self)
        temp0 = 66;

        --STPAL(0,E,0,FF)

        while true do
            while temp0 < 74 do
                temp0 = temp0 + 4;

                --MPPAL2(0,55,50,0,10,0,0,0,FF)
                --CPPAL(0,0,10,0)
                --LDPAL(0,10,E,FF)
            end;

            while temp0 > 56
                temp0 = temp0 + 4;

                --MPPAL2(0,55,50,0,10,0,0,0,FF)
                --CPPAL(0,0,10,0)
                --LDPAL(0,10,E,FF)
            end;
        end;

        return 0;
    end;
};



entity["flagdr"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["produce"] = {
    on_start = function(self)
        --MPNAM(0)
        --AKAO(0,0,0,29,40,0,0,0,0,0,0,0,0)
        --IDLCK(0,0,1)
        --IDLCK(1,0,1)
        --IDLCK(11,0,1)

        --VWOFT(0,0,0,0,0,0)

        local progress = game:variable_get("progress_game");
        local flags209 = game:variable_get("bank3[209]");
        local flags210 = game:variable_get("bank3[210]");
        local flags213 = game:variable_get("bank3[213]");

        if bit.band(flags210, hex.to_dec('0x10')) then
            IDLCK(11,0,0)
            REQSW(A,C8)
        elseif bit.band(flags213, hex.to_dec('0x40')) then
            IDLCK(11,0,0)
            REQSW(A,C7)
        elseif progress >= 90 then
            REQSW(A,C6)
        elseif progress == 87 then
            if bit.band(flags210, hex.to_dec('0x02')) == 0 then
                game:variable_set("bank3[210]", bit.bor(flags210, hex.to_dec('0x02')));

                CharMovable(Off)
                MenuAccess(Off)
                CC(19)
                MUSIC(0)
                REQEW(A,45)
                Wait(A)
                REQSW(8,42)
            end;
        elseif progress == 81 then
            if bit.band(flags210, hex.to_dec('0x08')) ~= 0 then
                REQSW(A,44)
            else
                REQSW(A,43)
                game:variable_set("bank3[210]", bit.bor(flags210, hex.to_dec('0x08')));
            end;
        elseif progress >= 72 then
            REQSW(A,42)
        elseif progress >= 63 then
            if bit.band(flags209, hex.to_dec('0x01')) ~= 0 then
                script:request_start_wait("stageDR", "script1", 2);
            else
                --CharMovable(Off)
                --MenuAccess(Off)
                script:request_start_wait("direct", "script1", 6);
                --SCR2D(0,68,0,88,0)
                --Wait(1)
                --SCR2DL(0,0,5,0,32,0,C8,0)
                --SCRLW
                --SCR2DL(0,0,C8,FF,3B,0,64,0)
                --SCRLW
                --SCR2DL(0,0,A0,FF,5C,0,50,0)
                --SCRLW
                --SCRCC
                --CharMovable(On)
                --MenuAccess(On)
            end;
        end;

        return 0;
    end;
};



entity["direct"] = {
    on_start = function(self)
        temp35 = 52;

        while true do
            local triangle_id = cloud:get_triangle();

            if triangle_id == 109 then
                local flags210 = game:variable_get("bank3[210]");
                local flags213 = game:variable_get("bank3[213]");

                if bit.band(flags213, hex.to_dec('0x40')) == 0 and -- if materia shop not opened
                   bit.band(flags210, hex.to_dec('0x02')) and
                   bit.band(flags210, hex.to_dec('0x04')) == 0 then
                    game:variable_set("bank3[210]", bit.bor(flags210, hex.to_dec('0x04')));

                    CharMovable(Off)
                    MenuAccess(Off)
                    REQEW(9,42)
                end;
            end;

            script:wait(0);
        end;

        return 0;
    end;

    script1 = function(self)
        local flags = game:variable_get("bank3[209]")
        if bit.band(flags, hex.to_dec('0x01')) == 0 then
            game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x01')));

            script:request_start_wait("aval", "script3", 5);
            script:request_start_wait("avas", "script3", 5);
            script:request_start_wait("avaw", "script3", 5);
            script:request_end_wait("ballet", "script5", 5);
            --Wait(1E)
            --SOUND(0,10,0,0)
            --Wait(A)
            --SOUND(0,10,0,0)
            script:request_start_wait("aval", "script4", 5);
            script:request_start_wait("avaw", "script4", 5);
            script:request_end_wait("avas", "script4", 5);
            script:request_start_wait("obasan", "script3", 6);
            --Wait(A)
            script:request_start_wait("man1", "script3", 6);
            script:request_start_wait("aval", "script5", 5);
            script:request_start_wait("avaw", "script5", 5);
            script:request_start_wait("avas", "script5", 5);
            --Wait(A)
            script:request_start_wait("woman1", "script3", 6);
            --Wait(A)
            script:request_start_wait("child1", "script3", 6);
            --Wait(A)
            script:request_end_wait("oyaji1", "script3", 6);
            --Wait(A)
            script:request_end_wait("ballet", "script6", 5);
            --Wait(A)
        end;

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["ad"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        script:request("cloud", "script4", 2);
        script:request("tifa", "script4", 2);

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["stagedr"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        flags = game:variable_get("bank3[209]");
        game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x08')));

        script:request_start_wait("ballet", "script3", 6);
        script:request_start_wait("avas", "script8", 6);
        script:request_start_wait("aval", "script8", 6);
        script:request_start_wait("avaw", "script8", 6);
        script:request_start_wait("man1", "script5", 6);
        script:request_start_wait("woman1", "script5", 6);
        script:request_start_wait("oyaji1", "script6", 6);
        script:request_start_wait("child1", "script5", 6);
        script:request_start_wait("obasan", "script5", 6);

        return 0;
    end;

    script2 = function(self)
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



entity["timekp"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["random"] = {
    on_start = function(self)
        while true do
            temp12 = RANDOM(5,C)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["bganim"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
--ca4:	sound(0,b4,0,40)
        script:request_start_wait("door4", "script1", 2);
--cac:	wait(f,0)
        script:request_start_wait("door4", "script2", 2);

        return 0;
    end;
};



-- line to go up on ledder
entity["border1"] = {
    on_start = function(self)
--cb3:	line(ec,fd,42,fb,10,1,be,fd,f,fb,14,1)
--cc1:	linon(1)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
--00cc7:	if-key(20,2,d)
            temp28 = 1;
--00ccf:	sound(0,15,0,40)
            script:request_start_wait("cloud", "script12", 6);
        end;

        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
--cda:	linon(0)

        return 0;
    end;

    script8 = function(self)
--cdd:	linon(1)

        return 0;
    end;
};



-- line to jump down from top floor
entity["border2"] = {
    on_start = function(self)
--ce0:	line(26,fe,5f,fb,e5,1,26,fe,25,fb,e5,1)
--cee:	linon(1)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        temp29 = 1;
        script:request_start_wait("cloud", "script12", 6);

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
--cfe:	linon(0)

        return 0;
    end;

    script8 = function(self)
--d01:	linon(1)

        return 0;
    end;
};



entity["border3"] = {
    on_start = function(self)
--d04:	line(7e,3,16,1,0,0,36,3,e0,fd,0,0)
--d12:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
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



-- line to enter bar
entity["border4"] = {
    on_start = function(self)
--d37:	line(22,1,7b,1,4c,0,46,1,6c,1,4c,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        --PMJMP(9A,0)
        --SOUND(0,B4,0,40)
        script:request_end_wait("door4", "script1", 2);
        script:request_start_wait("cloud", "script11", 2);
        Wait(F)
        script:request_end_wait("door4", "script2", 2);

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



entity["item"] = {
    on_start = function(self)
--d6a:	line(e,fd,95,fd,0,0,e4,fc,c5,fd,0,0)

        local flags213 = game:variable_get("bank3[213]");
        if bit.band(flags213, hex.to_dec('0x40')) then
            --LineSwitch(Off)
        end;

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        --WSIZW(0,32,0,8,0,A9,0,29,0)
        --Dialog(0,4F)
        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
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
};



-- writing on wall
entity["tatekan"] = {
    on_start = function(self)
--d9d:	line(ef,fc,c0,ff,0,0,f6,fc,5f,ff,0,0)

        return 0;
    end;

    on_talk = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        script:request_start_wait("cloud", "script3", 3);
        --WSIZW(0,8,0,A0,0,F6,0,69,0)
        --Dialog(0,50)
        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
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
};



-- looks like line used to start memories event on mds7
-- never used
entity["kaisou"] = {
    on_start = function(self)
--dca:	line(72,1,39,0,0,0,ee,0,39,0,0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        local flags210 = game:variable_get("bank3[210]");
        local flags213 = game:variable_get("bank3[213]");

        if bit.band(flags213, hex.to_dec('0x08')) and
           bit.band(flags210, hex.to_dec('0x01')) == 0 then
            game:variable_set("bank3[210]", bit.bor(flags210, hex.to_dec('0x01')));

            --CharMovable(Off)
            --MenuAccess(Off)
            script:request_end_wait("ad", "script1", 2);
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
};



entity["cloud"] = {
    on_start = function(self)
        --CHAR(0)
        --PC(0)
        --SLIDR(0,22)
        --TALKR(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        --CANM!2(3,0,E,1)
        --TURNGEN(0,C0,2,A,1)
        --WSIZW(1,64,0,8,0,C5,0,39,0)
        --Dialog(1,51)
        --CANM!2(3,F,1D,1)

        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script4 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        --CANM!2(4,0,7,1)
        --Wait(A)
        --MSPED(0,0,4)
        --SLIDR(0,0)
        --SolidObject(Off)
        --MOVE(0,90,1,FB,FF)
        --DIR(0,C0)
        --DFANM(5,1)
        --CANM!2(6,16,16,1)
        --Wait(3C)
        --CANM!2(6,16,1D,1)

        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script5 = function(self)
        --DIRA (17)
        --CANM!2 (07,00,0E,01)
        --WINDOW (01,BE,00,A0,00,77,00,39,00)
        --MESSAGE (01,05)
        --CANM!2 (07,0F,1D,01)

        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script6 = function(self)
        --CANM!2 (06,00,07,01)

        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script7 = function(self)
        --DIR (00,E0)
        --CANM!2 (08,00,0E,01)
        --WAIT (3C,00)
        --CANM!2 (09,00,13,01)
        --WAIT (1E,00)

        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
        local flags = game:variable_get("bank3[209]")
        game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x02')));

--f9e:	uc(1)
--fa0:	menu2(1)
--fa2:	move(0,32,1,df,1)
--fa8:	mapjump(9a,0,c,0,d,0,1a,0,c0) -- mds7pb_1

        return 0;
    end;

    script12 = function(self)
        if temp28 == 1 then
            script:request_start_wait("border2", "script7", 6);
            --SolidObject(Off)
            --SLIDR(0,0)
            --MOVE(0,EA,FD,41,FB)
            --SolidObject(On)
            --SLIDR(0,22)
            --LADER(0,0,26,FE,4F,FB,E5,1,A7,0,1,10,40,1)
            temp28 = 0;
            --Wait(A)
            script:request_start_wait("border2", "script8", 6);
        elseif temp29 == 1 then
            script:request_start_wait("border1", "script7", 6);
            --CharMovable(Off)
            --MenuAccess(Off)
            --DIR(0,C0)
            --DFANM(11,1)
            --Wait(F)
            --AKAO(0,0,0,28,40,E9,0,0,0,0,0,0,0)
            --JUMP(0,0,CE,FD,37,FB,9E,0,11,0)
            --AKAO(0,0,0,28,40,38,0,0,0,0,0,0,0)
            --Wait(14)
            --DFANM(0,1)
            --CharMovable(On)
            --MenuAccess(On)
            temp29 = 0;
            --Wait(A)
            script:request_start_wait("border1", "script8", 6);
        end;

        return 0;
    end;

    script13 = function(self)
--1039:	solid(1)
--103b:	slidr(0,0)
--103e:	move(0,1c,1,d5,ff)
--1044:	solid(0)
--1046:	slidr(0,22)

        return 0;
    end;

    script14 = function(self)
        return 0;
    end;

    script15 = function(self)
        return 0;
    end;
};



entity["ballet"] = {
    on_start = function(self)
        --CHAR(1)
        --PC(1)
        --XYZI(0,1F3,-50,0,4E)
        --SLIDR(0,30)
        --TALKR(0,46)
        --TalkSwitch(On)
        --SolidObject(On)
        --VISI(On)

        return 0;
    end;

    script1 = function(self)
        local flags = game:variable_get("bank3[209]")
        if bit.band(flags, hex.to_dec('0x10')) then
            --CharMovable(Off)
            --MenuAccess(Off)
            --TURA(15,A,2)
            --ANIME2(3,1)
            --WSIZW(3,8,0,8,0,DF,0,39,0)
            --Dialog(3,21)
            if temp2f == 0 then
                script:request_start_wait("cloud", "script13", 6);
                --SolidObject(Off)
                --MOVE(0,69,1,11,0)
                --SolidObject(On)
                temp2f = 1;
            end;
            --CharMovable(On)
            --MenuAccess(On)
            --TURNGEN(0,E0,2,A,1)
            --DFANM(4,1)
        elseif bit.band(flags, hex.to_dec('0x08')) then
            --CharMovable(Off)
            --MenuAccess(Off)
            --TURA(15,A,2)
            --WSIZW(3,8,0,8,0,8D,0,39,0)
            --Dialog(3,1D)
            if temp2f == 0 then
                script:request_start_wait("cloud", "script13", 6);
                --SolidObject(Off)
                --MOVE(0,69,1,11,0)
                --DIR(0,E0)
                --SolidObject(On)
                temp2f = 1;
            end;
            --CharMovable(On)
            --MenuAccess(On)

            local flags = game:variable_get("bank3[209]")
            game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x10')));

            --Wait(3C)
            --Wait(3C)
            --TURA(15,A,2)
            --ANIME2(3,1)
            --WSIZW(3,8,0,8,0,DF,0,39,0)
            --Dialog(3,21)
            --TURNGEN(0,E0,2,A,1)
            --DFANM(4,1)
        -- while tifa still outside (imposible in game)
        else
            if temp2d == 1 then
                --WSIZW(3,8,0,A0,0,E3,0,39,0)
                --Dialog(3,1F)
            else
                tempd = 0;
                --WSIZW(3,8,0,A0,0,E7,0,39,0)
                --Choice(5,3,1E,1,2,D)
                if tempd == 1 then
                    --WSIZW(3,8,0,A0,0,20,1,39,0)
                    --Dialog(3,20)
                elseif tempd == 2 then
                    --WSIZW(3,8,0,A0,0,E3,0,39,0)
                    --Dialog(3,1F)
                end;

                temp2d = 1;
            end;
        end;

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--117c:	xyzi(0,0,2b,1,2c,0,0,0,34,0)
--1187:	dir(0,0)
--118a:	dfanm(4,1)

        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
--119d:	solid(1)
--119f:	dfanm(2,1)
--11a2:	msped(0,0,c)
--11a6:	fmove(0,1d,1,24,0)
--11ac:	fmove(0,46,1,21,1)
        script:request_start_wait("BGanim", "script1", 2);
--11b5:	fmove(0,3a,1,a2,1)
--11bb:	tlkon(1)
--11bd:	solid(1)
--11bf:	visi(0)

        return 0;
    end;

    script6 = function(self)
--11c2:	xyzi(0,0,3a,1,a2,1,4c,0,3b,0)
--11cd:	tlkon(0)
--11cf:	solid(0)
--11d1:	visi(1)
--11d3:	dfanm(2,1)
        script:request_start_wait("BGanim", "script1", 2);
--11d9:	fmove(0,21,1,3b,1)
--11df:	dfanm(5,1)
--11e2:	msped(0,0,c)
        script:request("oyaji1", "script4", 2);
--11e9:	fmove(0,46,1,21,1)
--11ef:	solid(0)
--11f1:	slidr(0,30)
--11f4:	dir(0,0)
--11f7:	anim!2(6,1)
        script:request_start_wait("man1", "script4", 2);
        script:request_start_wait("woman1", "script4", 2);
        script:request_start_wait("child1", "script4", 2);
--1203:	solid(1)
--1205:	solid(0)
--1207:	anim!2(6,1)
--120a:	msped(0,0,4)
--120e:	dfanm(7,1)
        script:request_start_wait("oyaji1", "script5", 2);

        script:request_start_wait("aval", "script6", 5);
        script:request_start_wait("avaw", "script6", 5);
        script:request_start_wait("avas", "script6", 5);

--121d:	fmove(0,2b,1,2c,0)
--1223:	dir(0,0)
--1226:	dfanm(4,1)

        local flags = game:variable_get("bank3[209]")
        game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x20')));

--122d:	wait(a,0)
--1230:	anime1(8,1)

        script:request_start_wait("tifa", "script3", 6);

        script:request_start_wait("avaw", "script7", 5);
        script:request_start_wait("aval", "script7", 5);
        script:request_end_wait("avas", "script7", 5);

--123f:	wait(a,0)

        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;
};



entity["tifa"] = {
    on_start = function(self)
        --CHAR(2)
        --PC(2)
        --SLIDR(0,1E)
        --TALKR(0,46)
        --TalkSwitch(Off)
        --SolidObject(Off)
        --VISI(Off)
        --SolidObject(Off)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1340:	xyzi(0,0,31,1,a,2,4c,0,8f,0)
--134b:	tlkon(0)
--134d:	solid(0)
--134f:	visi(1)
--1351:	msped(0,0,c)
        script:request_start_wait("BGanim", "script1", 2);
--1358:	move(0,45,1,f7,0)

        local flags = game:variable_get("bank3[209]")
        game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x04')));

--1362:	dir(0,0)
--1365:	anime1(3,1)
--1368:	move(0,a6,0,39,1)
--136e:	dir(0,4)
--1371:	anime1(3,1)
--1374:	move(0,2b,2,2f,1)
--137a:	dir(0,28)
--137d:	anime1(3,1)
--1380:	move(0,47,1,2d,1)
        script:request_start_wait("BGanim", "script1", 2);

        flags = game:variable_get("bank3[209]")
        game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x08')));

--138d:	move(0,26,1,7,2)
--1393:	tlkon(1)
--1395:	solid(1)
--1397:	visi(0)

        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script4 = function(self)
        --PMJMP(26,1)
        --XYZI(0,13A,16B,4C,3A)
        --DIR(0,0)
        --TalkSwitch(On)
        --SolidObject(On)
        --VISI(On)
        --MSPED(0,0,8)
        --DFANM(2,1)

        -- open and close doors to bar when tifa run out
        script:request_start_wait("bganim", "script1", 3);

        --FMOVE(0,45,1,F7,0)
        --ANIM!2(4,1)
        --WSIZW(3,8,0,A0,0,B9,0,39,0)
        --Dialog(3,1)
        --MOVE(0,20,1,E4,FF)
        --DIRA(15)
        --ANIME1(5,1)
        --CANM!2(5,0,7,1)
        --Dialog(3,2)
        tempd = 0;
        WSIZW(3,BE,0,90,0,14,0,19,0)
        Choice(5,3,3,2,3,D)
        if tempd == 2 then
            game:variable_set("love_point_tifa", game:variable_get("love_point_tifa") + 5);
        end;

        script:request("obasan", "script4", 3);
        script:request("man1", "script8", 3);
        script:request("oyaji1", "script9", 3);

        --MOVE(0,FF,0,0,0)
        --DIRA(15)
        --ANIM!2(6,1)
        --WSIZW(3,8,0,A0,0,B9,0,39,0)
        --Dialog(3,4)

        script:request_end_wait("cloud", "script5", 2);

        --ANIME1(7,1)
        --DIR(0,E0)
        --CANM!2(8,0,9,1)
        --Dialog(3,6)
        --MOVE(0,62,1,89,FF)
        --DFANM(0,1)
        --DIRA(15)

        script:request_end_wait("cloud", "script6", 2);

        --CANM!2(9,0,10,1)
        --Dialog(3,7)
        --CANM!2(9,11,13,1)

        script:request_end_wait("cloud", "script7", 2);

        --Wait(A)

        game:variable_set("progress_game", 84);

        --ChangeField(26,1,0,0,0,0,31,0,0) -- nivl_e1

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



entity["avaw"] = {
    on_start = function(self)
--15e2:	char(3)
--15e4:	slidr(0,22)
--15e7:	talkr(0,46)
--15ea:	tlkon(1)
--15ec:	solid(1)
--15ee:	visi(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--15f3:	xyzi(0,0,b8,1,de,fe,0,0,4d,0)
--15fe:	tlkon(0)
--1600:	solid(0)
--1602:	visi(1)
--1604:	solid(1)
--1606:	talkr(0,1)
--1609:	dfanm(2,1)
--160c:	msped(0,0,8)
--1610:	fmove(0,a7,0,ff,ff)
--1616:	dir(0,e0)
--1619:	dfanm(3,1)

        return 0;
    end;

    script4 = function(self)
--161d:	anim!2(4,1)

        return 0;
    end;

    script5 = function(self)
--1621:	msped(0,0,c)
--1625:	move(0,e0,ff,15,0)
--162b:	dir(0,40)
--162e:	dfanm(3,1)

        return 0;
    end;

    script6 = function(self)
--1632:	msped(0,0,8)
--1636:	move(0,a7,0,ff,ff)
--163c:	dir(0,e0)
--163f:	dfanm(3,1)

        return 0;
    end;

    script7 = function(self)
--1643:	msped(0,0,8)
--1647:	move(0,92,0,a6,0)
--164d:	dir(0,60)
--1650:	dfanm(5,1)
--1653:	wait(f,0)
--1656:	jump(0,0,2d,1,3a,1,39,0,11,0)
--1661:	wait(14,0)
        script:request_start_wait("BGanim", "script1", 6);
--1667:	move(0,2c,1,eb,1)
--166d:	tlkon(1)
--166f:	solid(1)
--1671:	visi(0)

        return 0;
    end;

    script8 = function(self)
--1674:	tlkon(1)
--1676:	solid(1)
--1678:	visi(0)
--167a:	solid(1)
--167c:	talkr(0,1)

        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;
};



entity["awas"] = {
    on_start = function(self)
--16bf:	char(4)
--16c1:	slidr(0,22)
--16c4:	talkr(0,46)
--16c7:	tlkon(1)
--16c9:	solid(1)
--16cb:	visi(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--16d0:	xyzi(0,0,c7,2,f4,fe,0,0,4f,0)
--16db:	tlkon(0)
--16dd:	solid(0)
--16df:	visi(1)
--16e1:	solid(1)
--16e3:	talkr(0,1)
--16e6:	dfanm(2,1)
--16e9:	msped(0,0,8)
--16ed:	fmove(0,f,1,eb,ff)
--16f3:	dir(0,0)
--16f6:	dfanm(3,1)

        return 0;
    end;

    script4 = function(self)
--16fa:	anim!2(4,1)

        return 0;
    end;

    script5 = function(self)
--16fe:	msped(0,0,c)
--1702:	move(0,29,2,c7,ff)
--1708:	dir(0,c0)
--170b:	dfanm(3,1)

        return 0;
    end;

    script6 = function(self)
        --MSPED(0,0,8)
        --MOVE(0,1B,1,E0,FF)
        --DIR(0,0)
        --DFANM(3,1)

        return 0;
    end;

    script7 = function(self)
--1720:	msped(0,0,8)
--1724:	move(0,c6,1,d3,ff)
--172a:	move(0,19,2,b9,0)
--1730:	dfanm(5,1)
--1733:	wait(f,0)
--1736:	jump(0,0,1b,2,31,1,43,0,11,0)
--1741:	wait(14,0)
--1744:	move(0,2e,1,38,1)
--174a:	dir(0,80)
        script:request_start_wait("BGanim", "script1", 6);
--1750:	move(0,2c,1,eb,1)
--1756:	tlkon(1)
--1758:	solid(1)
--175a:	visi(0)

        return 0;
    end;

    script8 = function(self)
--175d:	tlkon(1)
--175f:	solid(1)
--1761:	visi(0)
--1763:	solid(1)
--1765:	talkr(0,1)

        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
        return 0;
    end;
};



entity["awal"] = {
    on_start = function(self)
--17c5:	char(5)
--17c7:	slidr(0,22)
--17ca:	talkr(0,46)
--17cd:	tlkon(1)
--17cf:	solid(1)
--17d1:	visi(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--17d6:	xyzi(0,0,5a,2,b7,ff,0,0,4f,0)
--17e1:	tlkon(0)
--17e3:	solid(0)
--17e5:	visi(1)
--17e7:	solid(1)
--17e9:	dfanm(3,1)
--17ec:	msped(0,0,8)
--17f0:	move(0,59,1,d,0)
--17f6:	dir(0,40)

        return 0;
    end;

    script4 = function(self)
--17fa:	anim!2(4,1)

        return 0;
    end;

    script5 = function(self)
--17fe:	msped(0,0,c)
--1802:	move(0,40,2,70,0)
--1808:	dir(0,e0)
--180b:	dfanm(3,1)

        return 0;
    end;

    script6 = function(self)
--180f:	msped(0,0,8)
--1813:	move(0,59,1,d,0)
--1819:	dir(0,0)
--181c:	dfanm(3,1)

        return 0;
    end;

    script7 = function(self)
--1820:	msped(0,0,c)
--1824:	move(0,19,2,b9,0)
--182a:	dfanm(5,1)
--182d:	wait(f,0)
--1830:	dir(0,80)
--1833:	jump(0,0,bf,1,2c,1,42,0,11,0)
--183e:	wait(14,0)
--1841:	move(0,2e,1,38,1)
--1847:	dir(0,80)
        script:request_start_wait("BGanim", "script1", 6);
--184d:	move(0,2c,1,eb,1)
--1853:	tlkon(1)
--1855:	solid(1)
--1857:	visi(0)

        return 0;
    end;

    script8 = function(self)
--185a:	tlkon(1)
--185c:	solid(1)
--185e:	visi(0)
--1860:	solid(1)
--1862:	talkr(0,1)

        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;
};



entity["man1"] = {
    on_start = function(self)
        --CHAR (06)
        --TLKON (01)
        --SOLID (01)
        --VISI (00)
        --SOLID (01)
        --TALKR (00,00)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            --TURNGEN(0,60,0,4,2)
            --TURNGEN(0,C0,0,4,2)
            --ANIM!2(3,1)
            --WSIZW(0,8,0,8,0,FE,0,39,0)
            --Dialog(0,45)
            script:request_start_wait("obasan", "script7", 3);
            --MSPED(0,0,16)
            --SolidObject(Off)
            --SLIDR(0,0)
            --MOVE(0,E4,6,82,FF)
            --MOVE(0,3B,7,E6,FE)
            --TalkSwitch(Off)
            --SolidObject(Off)
            --VISI(Off)
        elseif progress == 72 then
            --WSIZW(3,8,0,A0,0,CF,0,39,0)
            --Dialog(3,3E)
        else
            --TURA(15,A,2)
            --WSIZW(3,8,0,A0,0,F3,0,39,0)
            --Dialog(3,2D)
            --TURNGEN(0,80,2,A,1)
        end;

        CharMovable(On)
        MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
--196b:	asped(0,20,0)
--196f:	dfanm(1,1)
--1972:	msped(0,0,c)
--1976:	solid(1)
--1978:	fmove(0,26,0,86,fd)
--197e:	fmove(0,2a,ff,5b,fd)
--1984:	dir(0,70)
--1987:	solid(0)
--1989:	talkr(0,46)
--198c:	slidr(0,22)
--198f:	asped(0,10,0)
--1993:	dfanm(5,1)

        return 0;
    end;

    script5 = function(self)
--1997:	xyzi(0,0,26,ff,81,fd,0,0,70,0)
--19a2:	dir(0,70)
--19a5:	dfanm(5,1)
--19a8:	tlkon(0)
--19aa:	solid(0)
--19ac:	visi(1)
--19ae:	solid(0)
--19b0:	talkr(0,46)
--19b3:	slidr(0,22)

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script8 = function(self)
        --SolidObject(Off)
        --SLIDR(0,0)
        --XYZI(0,3C4,119,6E,5F)
        --TalkSwitch(On)
        --SolidObject(On)
        --VISI(On)
        --DFANM(7,1)
        --JUMP(0,0,D1,3,E9,FF,5B,0,14,0)
        --Wait(F)
        --CANM!2(7,2C,2C,1)
        --Wait(3C)
        --DIRA(17)
        --CANM!2(7,1D,1D,1)
        --ASPED(0,20,0)
        --DFANM(8,1)
        --FMOVE(0,CA,2,22,0)
        --CANM!2(8,E,E,1)

        while true do
            --Wait(1E)
            --DIR(0,C0)
            --Wait(1E)
            --DIRA(17)
        end;

        return 0;
    end;

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
        return 0;
    end;

    script12 = function(self)
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
};



entity["oyaji1"] = {
    on_start = function(self)
        --CHAR(7)
        --TalkSwitch(Off)
        --SolidObject(Off)
        --VISI(Off)
        --SolidObject(Off)
        --TALKR(0,1)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            local flags = game:variable_get("bank3[210]")
            if bit.band(flags, hex.to_dec('0x20')) then
                --TURA(15,A,2)
                --WSIZW(1,8,0,8,0,D5,0,39,0)
                --Dialog(1,49)
                --TURNGEN(0,C0,2,A,1)
            else
                --TURA(15,A,2)
                --WSIZW(1,8,0,8,0,BF,0,39,0)
                --Dialog(1,48)
                --TURNGEN(0,40,2,A,1)
            end;
        elseif progress == 72 then
            --TURA(15,A,2)
            if temp25 == 1 then
                --WSIZW(0,8,0,A0,0,32,1,39,0)
                --Dialog(0,3D)
            else
                --WSIZW(0,8,0,A0,0,16,1,39,0)
                --Dialog(0,3C)
                temp25 = 1;
            end;
            --TURNGEN(0,0,2,A,1)
        else
            --TURA(15,A,2)
            if temp2e == 1 then
                --WSIZW(0,8,0,A0,0,E3,0,39,0)
                --Dialog(0,36)
            else
                --WSIZW(0,8,0,A0,0,E8,0,39,0)
                --Dialog(0,2C)
                temp2e = 1;
            end;
            --TURNGEN(0,80,2,A,1)
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1d32:	wait(a,0)
--1d35:	msped(0,0,8)
--1d39:	xyzi(0,0,31,1,a,2,4c,0,8f,0)
--1d44:	tlkon(0)
--1d46:	solid(0)
--1d48:	visi(1)
--1d4a:	dfanm(2,1)
        script:request_start_wait("BGanim", "script1", 2);
--1d50:	fmove(0,46,1,21,1)
--1d56:	solid(0)
--1d58:	slidr(0,a)
--1d5b:	dir(0,80)
--1d5e:	asped(0,20,0)
--1d62:	dfanm(3,1)
--1d65:	wait(a,0)
--1d68:	asped(0,10,0)
--1d6c:	solid(1)

        return 0;
    end;

    script4 = function(self)
--1d6f:	dir(0,0)
--1d72:	dfanm(4,1)
--1d75:	msped(0,0,16)
--1d79:	move(0,39,1,4f,0)
--1d7f:	move(0,de,0,b9,ff)
--1d85:	anim!2(5,1)

        return 0;
    end;

    script5 = function(self)
--1d89:	solid(1)
--1d8b:	asped(0,20,0)
--1d8f:	dfanm(2,1)
--1d92:	fmove(0,94,ff,c1,fd)
--1d98:	solid(0)
--1d9a:	dir(0,80)
--1d9d:	anim!2(5,1)
--1da0:	solid(0)
--1da2:	slidr(0,22)
--1da5:	talkr(0,46)

        return 0;
    end;

    script6 = function(self)
--1da9:	xyzi(0,0,94,ff,c1,fd,0,0,4a,0)
--1db4:	dir(0,80)
--1db7:	canm!2(5,13,13,1)
--1dbc:	tlkon(0)
--1dbe:	solid(0)
--1dc0:	visi(1)
--1dc2:	solid(0)
--1dc4:	slidr(0,22)
--1dc7:	talkr(0,46)

        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script9 = function(self)
        --SolidObject(Off)
        --SLIDR(0,0)
        --XYZI(0,3C4,119,6E,5F)
        --TalkSwitch(On)
        --SolidObject(On)
        --VISI(On)
        --DFANM(6,1)
        --JUMP(0,0,C3,3,78,0,5E,0,19,0)
        --Wait(F)
        --CANM!2(6,2C,2C,1)
        --Wait(3C)
        --DIRA(17)
        --CANM!2(6,1D,1D,1)
        --ASPED(0,20,0)
        --DFANM(7,1)
        --FMOVE(0,F8,2,38,0)
        --CANM!2(7,1D,1D,1)

        while true do
            --Wait(3C)
            --DIR(0,E0)
            --Wait(3C)
            --DIRA(17)
        end;

        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
        return 0;
    end;

    script12 = function(self)
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
        return 0;
    end;
};



entity["woman1"] = {
    on_start = function(self)
--1fcd:	char(8)
--1fcf:	slidr(0,22)
--1fd2:	talkr(0,46)
--1fd5:	tlkon(1)
--1fd7:	solid(1)
--1fd9:	visi(0)
--1fdb:	solid(1)
--1fdd:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            local flags = game:variable_get("bank3[210]")
            if bit.band(flags, hex.to_dec('0x20')) then
                --TURA(15,A,2)
                --WSIZW(0,8,0,A0,0,16,1,39,0)
                --Dialog(0,4B)
            else
                --TURA(15,A,2)
                --WSIZW(0,8,0,8,0,2,1,39,0)
                --Dialog(0,4A)
                --TURNGEN(0,40,2,A,1)
            end;
        elseif progress == 72 then
            tempd = 0;
            --WSIZW(0,8,0,8,0,79,0,39,0)
            --Choice(5,0,38,1,2,D)
            if tempd == 1 then
                tempd = 0;
                --WSIZW(0,8,0,8,0,31,1,39,0)
                --Choice(5,0,39,1,2,D)
                if tempd == 1 then
                    --WSIZW(0,8,0,8,0,32,1,39,0)
                    --Dialog(0,3A)
                elseif tempd == 2
                    --WSIZW(0,8,0,8,0,CC,0,39,0)
                    --Dialog(0,3B)
                end;
                tempd = 0;
            elseif tempd == 2 then
                --WSIZW(0,8,0,8,0,CC,0,39,0)
                --Dialog(0,3B)
            end;
        else
            local flags = game:variable_get("bank3[209]")
            if bit.band(flags, hex.to_dec('0x40')) == 0 then
                --WREST(0)
                --TURA(15,A,2)
                tempd = 0;
                --WSIZW(0,8,0,8,0,70,0,39,0)
                --Choice(5,0,2E,1,2,D)
                if tempd == 1 then
                    --WSIZW(0,8,0,8,0,9B,0,19,0)
                    --Dialog(0,33)
                    --TURNGEN(0,C0,2,A,1)
                elseif tempd == 2 then
                    --WSIZW(0,8,0,8,0,26,1,49,0)
                    --Dialog(0,2F)
                    tempd = 0;
                    --Choice(5,0,30,1,2,D)
                    if tempd == 1 then
                        --WSIZW(0,8,0,8,0,9B,0,19,0)
                        --Dialog(0,33)
                        --TURNGEN(0,C0,2,A,1)
                    elseif tempd == 2 then
                        --WSIZW(0,8,0,8,0,6,1,39,0)
                        --WSIZW(0,8,0,8,0,30,1,39,0)
                        --Dialog(0,31)
                        game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x40')));
                        --TURNGEN(0,C0,2,A,1)
                    end;
                end;
            else
                --TURA(15,A,2)
                --WREST(0)
                --WSIZW(0,8,0,8,0,C6,0,39,0)
                --Dialog(0,32)
                --TURNGEN(0,C0,2,A,1)
            end;
        end;

        CharMovable(On)
        MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2152:	wait(a,0)
--2155:	xyzi(0,0,31,1,a,2,4c,0,8f,0)
--2160:	tlkon(0)
--2162:	solid(0)
--2164:	visi(1)
--2166:	dfanm(2,1)
--2169:	msped(0,0,b)
--216d:	sound(0,b4,0,40)
        script:request_start_wait("door4", "script1", 2);
--2175:	fmove(0,46,1,21,1)
--217b:	fmove(0,1d,1,24,0)
--2181:	fmove(0,85,1,d2,ff)
--2187:	dir(0,80)
--218a:	dfanm(3,1)

        return 0;
    end;

    script4 = function(self)
--218e:	solid(1)
--2190:	dfanm(2,1)
--2193:	msped(0,0,b)
--2197:	fmove(0,7c,2,b4,fe)
--219d:	fmove(0,cb,4,bc,ff)
--21a3:	dfanm(4,1)
--21a6:	solid(0)
--21a8:	slidr(0,22)
--21ab:	talkr(0,46)
--21ae:	dir(0,c0)

        return 0;
    end;

    script5 = function(self)
--21b2:	xyzi(0,0,cb,4,bc,ff,0,0,65,0)
--21bd:	dir(0,c0)
--21c0:	dfanm(4,1)
--21c3:	tlkon(0)
--21c5:	solid(0)
--21c7:	visi(1)
--21c9:	solid(0)
--21cb:	slidr(0,22)
--21ce:	talkr(0,46)

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

    script9 = function(self)
        return 0;
    end;
};



entity["child1"] = {
    on_start = function(self)
--229a:	char(9)
--229c:	slidr(0,22)
--229f:	talkr(0,46)
--22a2:	tlkon(1)
--22a4:	solid(1)
--22a6:	visi(0)
--22a8:	solid(1)
--22aa:	talkr(0,1)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local progress = game:variable_get("progress_game");
        if progress >= 108 then
            local flags = game:variable_get("bank3[210]")
            if bit.band(flags, hex.to_dec('0x20')) then
                --WSIZW(2,64,0,A0,0,FF,0,39,0)
                --Dialog(2,4E)
                --TURNGEN(0,80,2,A,1)
            else
                --TURA(15,A,2)
                --WSIZW(2,64,0,A0,0,E8,0,39,0)
                --WSIZW(2,64,0,64,0,E8,0,39,0)
                --Dialog(2,4D)
                --TURNGEN(0,40,2,A,1)
            end;
        elseif progress == 72 then
            --WSIZW(3,8,0,8,0,A7,0,39,0)
            --Dialog(3,37)
        else
            --WSIZW(3,8,0,8,0,AD,0,39,0)
            --Dialog(3,34)
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2323:	wait(a,0)
--2326:	xyzi(0,0,31,1,a,2,4c,0,8f,0)
--2331:	tlkon(0)
--2333:	solid(0)
--2335:	visi(1)
--2337:	dfanm(3,1)
--233a:	msped(0,0,a)
--233e:	fmove(0,46,1,21,1)
--2344:	fmove(0,1d,1,24,0)
--234a:	fmove(0,8c,1,19,0)
--2350:	dir(0,80)
--2353:	dfanm(4,1)

        return 0;
    end;

    script4 = function(self)
--2357:	dfanm(3,1)
--235a:	msped(0,0,a)
--235e:	fmove(0,23,2,be,fe)
--2364:	fmove(0,61,5,85,ff)
--236a:	fmove(0,3b,5,e6,ff)
--2370:	dfanm(4,1)
--2373:	dir(0,c0)
--2376:	solid(0)
--2378:	slidr(0,22)
--237b:	talkr(0,46)

        return 0;
    end;

    script5 = function(self)
--237f:	xyzi(0,0,3b,5,e6,ff,0,0,6b,0)
--238a:	dir(0,c0)
--238d:	dfanm(4,1)
--2390:	tlkon(0)
--2392:	solid(0)
--2394:	visi(1)
--2396:	solid(0)
--2398:	slidr(0,22)
--239b:	talkr(0,46)

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

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
        return 0;
    end;
};



entity["obasan"] = {
    on_start = function(self)
        --CHAR(A)
        --XYZI(0,3C1,82,0,5D)

        while true do
            --DIRA(16)
        end;

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local flags = game:variable_get("bank3[209]")
        if bit.band(flags, hex.to_dec('0x80')) then
            WSIZW(1,8,0,8,0,8E,0,39,0)
            Dialog(1,2B)
        -- never used
        elseif temp2a == 1 then
            WSIZW(1,8,0,8,0,AE,0,39,0)
            Dialog(1,2A)
        -- never used
        else
            WSIZW(1,8,0,8,0,AE,0,39,0)
            Dialog(1,29)
        end;

        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2583:	dir(0,0)
--2586:	wait(a,0)
--2589:	dir(0,e0)
--258c:	wait(1e,0)
        temp2a = 1;
--2593:	anim!2(3,1)
--2596:	dir(0,80)
--2599:	wait(a,0)
--259c:	msped(0,0,8)
--25a0:	move(0,c0,3,17,1)
        script:request_start_wait("door3", "script1", 2);

        local flags = game:variable_get("bank3[209]")
        game:variable_set("bank3[209]", bit.bor(flags, hex.to_dec('0x80')));

--25ad:	visi(0)
        script:request_start_wait("door3", "script2", 2);
--25b2:	xyzi(0,0,d9,3,59,1,6f,0,61,0)
--25bd:	slidr(0,64)
--25c0:	talkr(0,82)

        return 0;
    end;

    -- used in memories scene in mds7
    -- never used in game
    script4 = function(self)
        --AKAO(0,0,0,28,40,7A,0,0,0,0,0,0,0)

        script:request_start_wait("door3", "script1", 2);

        --XYZI(0,3C0,117,6D,5F)
        --TalkSwitch(On)
        --SolidObject(On)
        --VISI(On)
        --DIR(0,0)
        --ANIME1(4,1)
        --Wait(1E)

        script:request_start_wait("door3", "script2", 2);

        --TalkSwitch(Off)
        --SolidObject(Off)
        --VISI(Off)

        return 0;
    end;

    script5 = function(self)
--25f9:	xyzi(0,0,d9,3,59,1,6f,0,61,0)
--2604:	slidr(0,64)
--2607:	talkr(0,82)
--260a:	visi(0)

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        if temp2c == 2 then
            --AKAO(0,0,0,2A,40,7A,0,0,0,0,0,0,0)
            script:request_start_wait("door3", "script1", 2);
            --MOVE(0,C0,3,17,1)
            --TalkSwitch(Off)
            --SolidObject(Off)
            --VISI(Off)
            script:request_start_wait("door3", "script2", 2);
        elseif temp2c == 1 then
            --TURA(16,A,2)
        else
            --XYZI(0,3C4,10A,60,5F)
            --DIR(0,40)
            --TalkSwitch(On)
            --SolidObject(On)
            --VISI(On)
        end;

        return 0;
    end;
};
