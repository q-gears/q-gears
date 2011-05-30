-- created by Tori

entity = {
};



temp0  = 0; -- pallette scroller for LIGHT
temp1  = 0; -- manage TV
temp2  = 0; -- manage TV
temp3  = 0; -- here we store triangle_id of cloud
temp5  = 0; -- here we store x of cloud
temp7  = 0; -- here we store y of cloud
temp9  = 0; -- here we store z of cloud
tempc  = 0; -- random container
tempd  = 0; -- for chose dialog
temp11 = 0; -- checked in tk. Пока не стоит - вызываем рандом для двух аваланчей
temp14 = 0; -- checked in cloud
temp15 = 0; -- checked in marine
temp1a = 0; -- looks like state of pinball lift. 0 - top
temp1b = 0;
temp1d = 0; -- triangles to check
temp1f = 0; -- triangles to check
temp21 = 0;
temp26 = 0; -- checked in cloud. Set to 1 after first dialog with tifa is over.



entity["COUNTER"] = {
    on_start = function(self)
--916:	bgclr(0,6)
--919:	bgon(0,6,0)

        return 0;
    end;

    script1 = function(self)
--923:	bgoff(0,6,0)
--927:	bgon(0,6,1)

        return 0;
    end;

    script2 = function(self)
--92c:	bgoff(0,6,1)
--930:	bgon(0,6,0)

        return 0;
    end;
};



entity["LIGHT"] = {
    on_start = function(self)
        --BGCLR(0,5)
        --BGON(0,5,0)

        --STPAL(0,8,0,FF)

        while true do
            temp0 = 255;

            while temp0 > 250 do
                --ADPAL(0,55,50,0,10,0,0,0,FF)
                --LDPAL(0,10,8,FF)
                temp0 = temp0 - 1;
                --Wait(2)
            end;

            --LDPAL(0,0,8,FF)
            --RANDOM(5,0)
            --MOD(50,0,3)
            --INC(5,0)

            while temp0 > 0 do
                --BGOFF(0,5,0)
                --Wait(1)
                --BGON(0,5,0)
                --Wait(1)
                temp0 = temp0 - 1;
            end;

            --wait(3C)
        end;

        return 0;
    end;
};



entity["TV"] = {
    on_start = function(self)
        --BGCLR(0,2)
        --BGCLR(0,3)
        temp2 = 1;
        temp1 = 0;

        while true do
            if temp2 == 1 then
                --BGOFF(0,3,0)
                --Wait(1)
                --BGON(0,3,0)
            else

                while temp2 == 0 do
                    --RANDOM(5,1)
                    --MOD(50,1,5)
                    --INC(5,1)
                    --MUL(50,1,1E)

                    while temp1 > 0 do
                        --Wait(1)
                        temp1 = temp1 - 1;
                        if temp2 == 1 then
                            temp1 = 0;
                        end;
                    end;

                    --BGON(0,2,1)
                    --Wait(2)
                    --BGOFF(0,2,1)
                end;

                --Wait(2)
                --BGOFF(0,2,0)
                --BGOFF(0,2,1)
            end;
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



entity["SECRET"] = {
    on_start = function(self)
--a0c:	bgclr(0,4)

        return 0;
    end;

    script1 = function(self)
--a11:	bgon(0,4,0)

        return 0;
    end;

    script2 = function(self)
--a16:	bgoff(0,4,0)

        return 0;
    end;
};



entity["flagdr"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        return 0;
    end;
};



entity["special"] = {
    -- not needed really
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress < 72 then
            --CharMovable(Off)
            --MenuAccess(Off)
        end;

        return 0;
    end;
};



entity["produce"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 105 then
            --MUSIC(0)
        else
            --MUSIC(1)
        end;
        --MPNAM(0)
        --VWOFT(0,0,0,0,0,0)



        if progress >= 105 then
            REQSW(A,C8)
        elseif progress >= 84 then
            CharMovable(Off)
            MenuAccess(Off)
            REQSW(A,C7)
        elseif progress == 81 then
            REQSW(A,C6)
        elseif progress == 78 then
            REQSW(A,C5)
        elseif progress == 72 then
            if(<30>[D5] 09 1)
            {
                REQSW(A,C4)
            }
            else
            {
                REQEW(A,C3)
            }
        elseif progress == 69 then
            CharMovable(Off)
            MenuAccess(Off)
            SCR2D(0,E8,FF,DF,FF)
            REQEW(A,42)
        else
            --CharMovable(Off)
            --MenuAccess(Off)
            script:request_start_wait("stagedr", "script1", 2);
            script:request_start_wait("direct", "script1", 6);
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;
};



entity["direct"] = {
    on_start = function(self)
        script:request_end_wait("TK", "script1", 6);

        local flags211 = game:variable_get("bank3[211]");
        local flags212 = game:variable_get("bank3[212]");
        if bit.band(flags212, hex.to_dec('0x02')) == 0 and
           bit.band(flags211, hex.to_dec('0x04')) == 0 then
            BITON(30,D3,2)
            REQSW(12,C5)
            REQEW(19,C4)
            REQSW(14,A4)
        end;

        return 0;
    end;

    script1 = function(self)
        script:request_end_wait("TK", "script1", 6);

        local flags211 = game:variable_get("bank3[211]")
        game:variable_set("bank3[211]", bit.bor(flags211, hex.to_dec('0x04')));

        script:request_start_wait("cloud", "script5", 6);
        script:request_end_wait("marine", "script4", 6);
        script:request_start_wait("tifa", "script4", 5);

        return 0;
    end;

    script2 = function(self)
--aeb:	wait(1,0)
        script:request_end_wait("tifa", "script8", 4);

        return 0;
    end;
};



entity["ID"] = {
    on_start = function(self)
        temp1b = 42;
        temp1d = 62; -- triangles to check
        temp1f = 1; -- triangles to check
        temp21 = 49;

        while true do
            local flags212 = game:variable_get("bank3[212]");
            local flags213 = game:variable_get("bank3[213]");

            AXYZI(66,66,12,5,7,9,3) -- get position if cloud
            if temp3 == temp1f and
               bit.band(flags213, hex.to_dec('0x02')) == 0 and
               bit.band(flags212, hex.to_dec('0x02')) and
               bit.band(flags212, hex.to_dec('0x04')) == 0 then
                REQSW(14,4F)
            end;

            if temp3 == temp1d and
               bit.band(flags212, hex.to_dec('0x02')) and
               bit.band(flags212, hex.to_dec('0x04')) == 0 then
                CharMovable(Off)
                MenuAccess(Off)
                BITON(30,D4,2)
                REQEW(12,49)
                REQSW(14,4C)
            end;
        end;

        return 0;
    end;
};



entity["AD"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["stagedr"] = {
    on_start = function(self)
--c8b:	idlck(4,0,1)
--c8f:	idlck(4,0,1)
--c93:	idlck(20,0,1)
--c97:	idlck(3f,0,1)
--c9b:	idlck(9,0,1)
--c9f:	idlck(8,0,1)

        return 0;
    end;

    script1 = function(self)
        script:request("cloud", "script3", 6);
        script:request("aval", "script4", 6);
        script:request("avas", "script4", 6);
        script:request("avaw", "script3", 6);
        script:request("tifa", "script3", 6);
        script:request("marine", "script3", 6);

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



entity["TK"] = {
    on_start = function(self)
        local flags212 = game:variable_get("bank3[212]");
        if bit.band(flags212, hex.to_dec('0x01')) == 0 then
            while true do
                --Wait(3C)
                if temp11 == 0 then
                    --Wait(3C)
                    script:request("avas", "script3", 6);
                    --Wait(3C)
                    script:request("aval", "script3", 6);
                end;
            end;
        end;

        return 0;
    end;

    script1 = function(self)
--d97:	wait(1e,0)

        return 0;
    end;
};



entity["random"] = {
    on_start = function(self)
        while true do
--d9c:	random(5,c)
        end;

        return 0;
    end;

    script1 = function(self)
--da2:	random(5,c)

        return 0;
    end;
};



entity["BGanim"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        return 0;
    end;
};



entity["border1"] = {
    on_start = function(self)
--dc4:	line(ff,0,d0,ff,0,0,12,1,30,0,0,0)
--dd2:	linon(0)

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
--e22:	mpjpo(1)
--e24:	linon(1)

        return 0;
    end;
};



entity["border2"] = {
    on_start = function(self)
--e27:	line(cc,ff,bb,0,0,0,f8,ff,ad,0,0,0)

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



entity["border3"] = {
    on_start = function(self)
--e6b:	line(f2,ff,87,ff,0,0,0,0,93,0,0,0)
--e79:	linon(0)

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



entity["border4"] = {
    on_start = function(self)
--ea2:	line(33,0,30,0,0,0,31,0,a0,ff,0,0)
--eb0:	linon(0)

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



entity["cloud"] = {
    on_start = function(self)
--ecf:	char(0)
--ed1:	pc(0)
--ed3:	solid(1)
--ed5:	slidr(0,0)
--ed8:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        local flags213 = game:variable_get("bank3[213]")
        if bit.band(flags213, hex.to_dec('0x02')) then
            --CharMovable(Off)
            --MenuAccess(Off)
            --XYZI(0,-23,B6,-FF,0)
            -- pinball went up
            script:request_start_wait("pinball", "script6", 6);

            --LADER(0,0,E1,FF,98,0,0,0,14,0,1,0,80,1)
            script:request_start_wait("SECRET", "script2", 2);

            --MOVE(0,E1,FF,66,0)

            -- unset pinball lift bit
            game:variable_set("bank3[209]", bit.band(flags213, hex.to_dec('0xFD')));

            local flags213 = game:variable_get("bank3[214]")
            if bit.band(flags214, hex.to_dec('0x20')) == 0 then
                flags213 = game:variable_get("bank3[213]")
                if bit.band(flags213, hex.to_dec('0x01')) then
                    REQSW(11,C8)
                    ANIME1(3,1)
                    REQSW(1B,C5)
                    MOVE(0,D7,FF,10,0)
                    DIR(0,20)
                    IDLCK(1E,0,1)
                    IDLCK(1E,0,1)
                end;

                --CharMovable(On)
                --MenuAccess(On)
            end;
        else
            --XYZI(0,C0,D,0,1C)
            --DIR(0,C0)
        end;

        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        if temp14 == 0 then
            --MSPED(0,0,4)
            --MOVE(0,20,0,F0,FF)
            --DFANM(0,1)
            --SCR2D(0,A0,FF,8A,FF)
            --SCR2DL(0,0,DE,FF,FD,FF,28,0)
            --ANIME1(4,1)
            --DIR(0,B0)
            --ANIME1(5,1)
            --DIR(0,A8)
            --CANM!2(6,0,E,1)

            while temp26 ~= 1 do
                --DIRA(19)
            end;
        elseif temp14 == 1 then
            --SCR2DC(0,0,DE,FF,AD,FF,1E,0)
            --SCRLW
            --SCRCC
            --CharMovable(On)
            --MenuAccess(On)
            script:request_start_wait("border1", "script8", 6);
        end;

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        local flags213 = game:variable_get("bank3[214]")
        if bit.band(flags214, hex.to_dec('0x20')) then
            --ANIM!2(A,1)
        else
            --CANM!2(6,E,1D,1)
            --ANIME1(B,1)
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

    script16 = function(self)
        return 0;
    end;

    script17 = function(self)
        return 0;
    end;

    script18 = function(self)
        return 0;
    end;

    script19 = function(self)
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
        return 0;
    end;

    script24 = function(self)
        return 0;
    end;

    script25 = function(self)
        return 0;
    end;
};



entity["ballet"] = {
    on_start = function(self)
--1320:	char(1)
--1322:	pc(1)
--1324:	tlkon(1)
--1326:	solid(1)
--1328:	visi(0)
--132a:	solid(1)
--132c:	talkr(0,0)

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

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;
};



entity["tifa"] = {
    on_start = function(self)
--173e:	char(2)
--1740:	pc(2)
--1742:	tlkon(0)
--1744:	solid(0)
--1746:	visi(1)
--1748:	solid(1)
--174a:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)

        local flags214 = game:variable_get("bank3[214]")
        local progress = game:variable_get("progress_game");

        if bit.band(flags214, hex.to_dec('0x20')) then
            if(<30>[D6] 09 7)
            {
                CharMovable(Off)
                MenuAccess(Off)
                TURA(12,A,2)
                CreateWindow(0,8,A0,95,39)
                Dialog(0,3C)
                CharMovable(On)
                MenuAccess(On)
            }
            else
            {
                TURA(12,A,2)
                CharMovable(Off)
                MenuAccess(Off)
                ASPED(0,30,0)
                ANIM!2(3,1)
                ASPED(0,10,0)
                BITON(30,D6,7)
                SETBYTE(50,D,0)
                CreateWindow(0,8,A0,130,39)
                Choice(5,0,39,1,2,D)
                if(<50>[D] == 1)
                {
                    PLUS!(10,6,5)
                    CANM!2(4,0,7,1)
                    CANM!2(4,7,E,1)
                    CANM!2(5,0,E,1)
                    CreateWindow(0,8,A0,ED,39)
                    Dialog(0,3A)
                    CANM!2(5,E,1D,1)
                }
                if(<50>[D] == 2)
                {
                    PLUS!(10,4,5)
                    CANM!2(5,0,E,1)
                    CreateWindow(0,8,A0,CE,39)
                    Dialog(0,3B)
                    CANM!2(5,E,1D,1)
                }
                Dialog(0,3C)
                SETBYTE(50,23,1)
                CharMovable(On)
                MenuAccess(On)
            }
        elseif progress >= 90 then
            TURA(12,A,2)
            REQSW(15,C1)
        elseif progress == 81 then
            TURA(12,A,2)
            CreateWindow(2,8,A0,E5,39)
            Dialog(2,43)
        elseif progress == 78 then
            TURA(12,A,2)
            CreateWindow(0,8,A0,C6,39)
            Dialog(0,42)
        elseif progress == 72 then
            if(<30>[D4] 09 2)
            {
                DFANM(0,1)
                TURA(12,A,2)
                CreateWindow(0,8,A0,CF,39)
                Dialog(0,28)
            }
            else
            {
                TURA(12,A,2)
                CreateWindow(0,8,A0,98,39)
                Dialog(0,1B)
            }
        elseif progress == 69 then
            --TURA(12,A,2)
            --CreateWindow(0,8,A0,C4,39)
            --Dialog(0,40)
        end;

        CharMovable(On)
        MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        local flags213 = game:variable_get("bank3[213]")
        if bit.band(flags213, hex.to_dec('0x01')) then
            --SolidObject(Off)
            --SLIDR(0,0)
            --MOVE(0,3B,0,BE,FF)
            --TURNGEN(0,40,0,A,2)
        else
            --XYZI(0,-110,-10F,0,6)
            --DIR(0,40)
        end;

        return 0;
    end;

    script4 = function(self)
        --MSPED(0,0,8)
        --MOVE(0,F6,FE,CA,FF)
        --ASPED(0,20,0)
        --CANM!2(6,0,E,1)
        --IDLCK(9,0,0)
        --IDLCK(8,0,0)
        --SOUND(0,AC,0,40)
        script:request_start_wait("COUNTER", "script1", 2);
        --MOVE(0,F6,FE,4C,0)
        --DIR(0,0)
        --CANM!2(6,0,9,1)
        script:request_start_wait("COUNTER", "script2", 2);
        --SOUND(0,AF,0,40)
        --ASPED(0,10,0)
        --DFANM(2,1)
        --FMOVE(0,F0,FE,AC,0)
        --DFANM(0,1)
        --DIRA(19)
        --CANM!2(7,0,D,1)
        --CreateWindow(3,AA,8,E0,39)
        --Dialog(3,2)
        script:request_start_wait("marine", "script7", 6);
        --Wait(1E)
        --CANM!2(7,21,31,1)
        script:request_start_wait("marine", "script5", 5);
        --MSPED(0,0,6)
        --SCR2DL(0,0,E8,FF,DF,FF,1E,0)
        --MOVE(0,B9,FF,35,0)
        while temp26 ~= 1 do
        end;

        return 0;
    end;

    script5 = function(self)
        --ANIM!2(3,1)
        --CreateWindow(1,8,8,E5,39)
        --Dialog(1,3)
        --ANIM!2(8,1)
        tempd = 0;
        --Choice(5,1,4,1,2,D)

        script:request_start_wait("avas", "script11", 2);
        script:request_start_wait("aval", "script11", 2);

        if tempd == 1 then
            local flags211 = game:variable_get("bank3[211]")
            game:variable_set("bank3[211]", bit.bor(flags211, hex.to_dec('0x01')));
            --CreateWindow(1,8,8,ED,39)
            --Dialog(1,5)
        elseif tempd == 2 then
            --MSPED(0,0,4)
            --MOVE(0,D7,FF,25,0)
            script:request_start_wait("marine", "script7", 4);
            --DIRA(12)
            --ANIM!2(9,1)
            --CreateWindow(1,8,8,109,39)
            --Dialog(1,6)
        end;

        --DIR(0,28)
        --Wait(1E)
        --CharMovable(Off)
        --MenuAccess(Off)
        --MMB+-(1,2)
        --MENU(0,6,2)
        game:variable_set("progress_game", 69);
        temp26 = 1;

        --SCR2D(0,E8,FF,DF,FF)
        --IDLCK(9,0,1)
        --IDLCK(8,0,1)
        script:request_start_wait("direct", "script2", 6);

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
        local flags111 = game:variable_get("bank3[111]")
        -- if we not buy flower from aeris
        if bit.band(flags111, hex.to_dec('0x01')) == 0 then
            --MSPED(0,0,4)
            --MOVE(0,A3,FF,2A,0)
            --DFANM(F,1)
            --DIRA(12)
            --CreateWindow(1,8,8,CF,39)
            --Dialog(1,6E)
        else
            --MOVE(0,DF,FF,B,0)
            --DIRA(12)
            --CANM!2(10,0,E,1)
            --CreateWindow(1,8,8,B9,39)
            --Dialog(1,8)
            --CANM!2(10,E,1D,1)
            --CreateWindow(1,8,8,133,39)
            --Dialog(1,9)
            script:request("cloud", "script8", 2);

            tempd = 0;
            --CreateWindow(1,BE,8,D9,49)
            --Choice(5,1,A,2,3,D)
            --CreateWindow(1,8,8,CF,39)
            if tempd == 2 then
                local love_point_tifa = game:variable_get("love_point_tifa");
                love_point_tifa = love_point_tifa + 5;
                game:variable_set("love_point_tifa", love_point_tifa);

                local flags211 = game:variable_get("bank3[211]")
                game:variable_set("bank3[211]", bit.bor(flags211, hex.to_dec('0x08')));

                --MOVE(0,BE,FF,23,0)
                --DFANM(F,1)
                --DIRA(12)
                script:request_start_wait("avas", "script11", 2);
                script:request_start_wait("aval", "script11", 2);
                --CreateWindow(1,8,8,CF,39)
                --Dialog(1,B)
                script:request_start_wait("flower", "script4", 6);
                --MOVE(0,A3,FF,2A,0)
                --DIR(0,C0)
                --ANIME1(C,1)
                --Dialog(1,C)
                --ANIME2(11,1)
                --TURA(12,A,2)
            elseif tempd == 3 then
                local love_point_barret = game:variable_get("love_point_barret");
                love_point_barret = love_point_barret + 5;
                game:variable_set("love_point_barret", love_point_barret);

                local flags211 = game:variable_get("bank3[211]")
                game:variable_set("bank3[211]", bit.bor(flags211, hex.to_dec('0x10')));

                --CANM!2(12,0,E,1)
                script:request_start_wait("marine", "script11", 2);
                --MOVE(0,8B,FF,16,0)
                --DIRA(12)
            end;
        end;

        temp15 = 1;
        script:request_end_wait("marine", "script11", 2);
        script:request_start_wait("flower", "script6", 2);
        script:request_start_wait("cash", "script3", 6);
        script:request_start_wait("camera", "script3", 6);

        --TALKR(0,46)
        --SolidObject(On)
        --SLIDR(0,1)
        temp14 = 1;
        script:request_start_wait("cloud", "script5", 6);

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

    script16 = function(self)
        return 0;
    end;

    script17 = function(self)
        return 0;
    end;

    script18 = function(self)
        return 0;
    end;

    script19 = function(self)
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
};



entity["mes"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        return 0;
    end;
};



entity["avaw"] = {
    on_start = function(self)
--2280:	char(3)
--2282:	solid(1)
--2284:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--22b2:	xyzi(0,0,b8,0,83,ff,0,0,3d,0)
--22bd:	dir(0,f8)
--22c0:	dfanm(3,1)

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



entity["aval"] = {
    on_start = function(self)
--23c8:	char(4)
--23ca:	solid(1)
--23cc:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        local flags212 = game:variable_get("bank3[212]");
        if bit.band(flags212, hex.to_dec('0x01')) == 0 and
           temp11 ~= 1 then
            script:request("random", "script1", 2);
            if tempc > 128 then
                --DFANM(3,1)
            else
                --ANIM!2(3,1)
            end;
        end;

        return 0;
    end;

    script4 = function(self)
--241e:	xyzi(0,0,be,ff,b4,ff,0,0,18,0)
--2429:	dir(0,24)
--242c:	dfanm(3,1)

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

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
--249a:	canm!2(7,0,e,1)
--249f:	wait(1e,0)
--24a2:	canm!2(7,f,1d,1)

        return 0;
    end;

    script12 = function(self)
        return 0;
    end;

    script13 = function(self)
        return 0;
    end;
};



entity["avas"] = {
    on_start = function(self)
--253d:	char(5)
--253f:	solid(1)
--2541:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        local flags212 = game:variable_get("bank3[212]");
        if bit.band(flags212, hex.to_dec('0x01')) == 0 and
           temp11 ~= 1 then
            script:request("random", "script1", 2);
            if tempc > 128 then
                --DFANM(3,1)
            else
                --DFANM(4,1)
            end;
        end;

        return 0;
    end;

    script4 = function(self)
--2593:	xyzi(0,0,69,0,bd,ff,0,0,2f,0)
--259e:	dir(0,8)
--25a1:	dfanm(4,1)

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

    script9 = function(self)
        return 0;
    end;

    script10 = function(self)
        return 0;
    end;

    script11 = function(self)
--2620:	canim2(8,0,e,1)
--2625:	wait(1e,0)
--2628:	canm!2(8,e,1d,1)

        return 0;
    end;

    script12 = function(self)
        return 0;
    end;

    script13 = function(self)
        return 0;
    end;
};



entity["marine"] = {
    on_start = function(self)
--26ba:	char(6)
--26bc:	solid(1)
--26be:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        local flags214 = game:variable_get("bank3[214]")
        if bit.band(flags214, hex.to_dec('0x20')) then
            --XYZI(0,-10C,-69,0,7)
            --DIR(0,40)
            --TALKR(0,C8)

            while true do
                --MOVE(0,EE,FE,F5,FE)
                --DIR(0,C0)
                --AKAO(0,0,0,2A,40,DB,0,0,0,0,0,0,0)
                --DFANM(4,1)
                --Wait(1E)
                --MOVE(0,F5,FE,CB,FF)
                script:request_end_wait("random", "script1", 2);
                if tempc > 128 then
                    --DIR(0,40)
                    --DFANM(5,1)
                    --AKAO(0,0,0,2A,40,DB,0,0,0,0,0,0,0)
                    --Wait(8)
                    --Wait(4)
                else
                    --DIR(0,40)
                    --ANIM!1(6,1)
                    --Wait(A)
                    --AKAO(0,0,0,2A,40,BB,0,0,0,0,0,0,0)
                    --ANIMW
                    --AKAO(0,0,0,29,40,B9,0,0,0,0,0,0,0)
                    --ANIME2(3,1)
                end;

                --Wait(3C)
            end;
        else
            --XYZI(0,-63,-27,0,18)
            --DIR(0,40)
            --CANM!2(7,0,0,1)
        end;

        return 0;
    end;

    -- марлин выбегает нам навстречу и кричит папа.
    script4 = function(self)
--279f:	akao(0,0,0,28,40,db,0,0,0,0,0,0,0)
--27ad:	canm!2(7,0,e,1)
--27b2:	window(3,64,0,8,0,4a,0,19,0)
--27bc:	message(3,1)
--27bf:	dira(12)
--27c1:	anime1(8,1)
--27c4:	msped(0,0,10)
--27c8:	move(0,29,ff,92,0)
--27ce:	asped(0,20,0)
--27d2:	anime1(9,1)
--27d5:	anime1(9,1)
--27d8:	asped(0,10,0)
--27dc:	dfanm(2,1)
--27df:	fmove(0,ed,fe,dc,0)
--27e5:	fmove(0,b1,fe,da,0)
--27eb:	fmove(0,b5,fe,d6,0)
--27f1:	dfanm(2,1)
--27f4:	dfanm(a,1)

        return 0;
    end;

    script5 = function(self)
--27f8:	wait(1e,0)
--27fb:	msped(0,0,8)
--27ff:	dfanm(2,1)
--2802:	fmove(0,9f,ff,5b,0)
--2808:	anime1(0,1)
        script:request("tifa", "script5", 4);
--280e:	dfanm(b,1)
--2811:	wait(3c,0)
--2814:	wait(3c,0)
--2817:	dfanm(3,1)

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        local flags214 = game:variable_get("bank3[214]")
        if bit.band(flags214, hex.to_dec('0x20')) then
            --MSPED(0,0,8)
            --IDLCK(9,0,0)
            --IDLCK(8,0,0)
            --MOVE(0,F3,FE,D5,FF)
            --ANIM!2(0,1)
            --DIR(0,40)
            --CreateWindow(1,64,8,98,39)
            --Dialog(1,3E)
            --SCRLC(0,3C,0,3)
            --PartySet(0,1,2)
            --CharJoin(A)
            --SCRLW
            --SCRCC
            game:variable_set("progress_game", 108);
            --CharMovable(On)
            --MenuAccess(On)
            --MSPED(0,0,8)
            --DFANM(2,1)
            --FMOVE(0,F2,FE,72,FF)
            --IDLCK(9,0,1)
            --IDLCK(8,0,1)
            --DFANM(0,1)
            --MSPED(0,0,4)
        else
            --DFANM(3,1)
            while temp14 ~= 1 do
            end;
            --ASPED(0,10,0)
            --DFANM(3,1)
        end;

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
        if temp15 == 0 then
            --ASPED(0,20,0)
            --ANIME1(E,1)
            --MSPED(0,0,8)
            --MOVA(12)
            script:request_start_wait("flower", "script5", 6);
            --MOVE(0,87,FF,37,0)
            --DIR(0,40)
            --ASPED(0,10,0)
            script:request_start_wait("flower", "script6", 6);
        elseif temp15 == 1 then
            --SolidObject(On)
            --TALKR(0,46)
            --SLIDR(0,1E)
        end;

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



entity["camera"] = {
    on_start = function(self)
--29e0:	char(7)
--29e2:	tlkon(1)
--29e4:	solid(1)
--29e6:	visi(0)
--29e8:	slidr(0,0)
--29eb:	solid(1)
--29ed:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
        CharMovable(Off)
        MenuAccess(Off)
        if(<30>[D4] 09 1)
        {
        }
        else
        {
            if(<50>[25] == 1)
            {
                CreateWindow(2,8,A0,134,39)
                Dialog(2,49)
            }
            else
            {
                REQSW(17,2A)
                CreateWindow(2,8,A0,10A,39)
                Dialog(2,45)
                CreateWindow(2,8,A0,CD,39)
                SETBYTE(50,D,0)
                Choice(5,2,46,1,2,D)
                if(<50>[D] == 1)
                {
                    CreateWindow(2,8,A0,11C,39)
                    Dialog(2,48)
                }
                if(<50>[D] == 2)
                {
                    CreateWindow(2,8,A0,126,39)
                    Dialog(2,47)
                }
                SETBYTE(50,25,1)
            }
        }

        CharMovable(On)
        MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2a68:	xyzi(0,0,e3,ff,83,ff,29,0,51,0)
--2a73:	tlkon(1)
--2a75:	solid(1)
--2a77:	visi(0)
--2a79:	tlkon(0)
--2a7b:	talkr(0,46)

        return 0;
    end;
};



entity["pinball"] = {
    on_start = function(self)
--2a7f:	char(8)
--2a81:	xyzi(0,0,dd,ff,42,1,0,0,0,0)
--2a8c:	dir(0,0)
--2a8f:	slidr(0,78)
--2a92:	talkr(0,64)

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
        script:request_end_wait("SECRET", "script1", 2);
--2b0a:	tlkon(0)
--2b0c:	solid(0)
--2b0e:	visi(1)
--2b10:	sound(0,a5,0,40)
--2b15:	lader(0,0,dd,ff,42,1,0,0,0,0,1,1,0,1)
--2b24:	sound(0,0,0,40)
        temp1a = 0;
        script:request_end_wait("SECRET", "script2", 2);

        return 0;
    end;

    script7 = function(self)
        return 0;
    end;
};



entity["cash"] = {
    on_start = function(self)
--2b50:	char(9)
--2b52:	tlkon(1)
--2b54:	solid(1)
--2b56:	visi(0)
--2b58:	solid(1)
--2b5a:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
 CharMovable(Off)
 MenuAccess(Off)
 if(<30>[D4] 09 1)
 {
 }
 else
 {
  REQSW(18,2A)
  CreateWindow(2,8,A0,12A,39)
  SETBYTE(50,D,0)
  Choice(5,2,4A,1,2,D)
  if(<50>[D] == 1)
  {
   CreateWindow(2,8,A0,126,39)
   Dialog(2,4B)
  }
  if(<50>[D] == 2)
  {
   CreateWindow(2,8,A0,A1,39)
   Dialog(2,4C)
  }
 }
 CharMovable(On)
 MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--2baf:	xyzi(0,0,6f,0,82,ff,29,0,4b,0)
--2bba:	tlkon(1)
--2bbc:	solid(1)
--2bbe:	visi(0)
--2bc0:	tlkon(0)
--2bc2:	talkr(0,46)

        return 0;
    end;
};




entity["flower"] = {
    on_start = function(self)
--2bc6:	char(10)
--2bc8:	tlkon(1)
--2bca:	solid(1)
--2bcc:	visi(0)
--2bce:	solid(1)
--2bd0:	talkr(0,0)

        return 0;
    end;

    script1 = function(self)
 CharMovable(Off)
 MenuAccess(Off)
 if(<30>[D4] 09 1)
 {
 }
 else
 {
  CreateWindow(2,8,A0,E5,39)
  Dialog(2,4D)
 }
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
--2bf5:	jump(0,0,b9,ff,14,0,15,0,5,0)
--2c00:	wait(1e,0)
--2c03:	tlkon(1)
--2c05:	solid(1)
--2c07:	visi(0)

        return 0;
    end;

    script5 = function(self)
--2c0a:	jump(0,0,b9,ff,14,0,15,0,5,0)
--2c15:	wait(1e,0)
--2c18:	tlkon(1)
--2c1a:	solid(1)
--2c1c:	visi(0)

        return 0;
    end;

    script6 = function(self)
--2c1f:	xyzi(0,0,b7,0,45,ff,29,0,48,0)
--2c2a:	tlkon(1)
--2c2c:	solid(1)
--2c2e:	visi(0)
--2c30:	tlkon(0)
--2c32:	talkr(0,46)

        return 0;
    end;
};



entity["cefi"] = {
    on_start = function(self)
--2c36:	char(11)
--2c38:	solid(1)
--2c3a:	ofst(0,0,0,1c,1,1a,1,1e,fc,0,0)
--2c46:	tlkon(1)
--2c48:	solid(1)
--2c4a:	visi(0)
--2c4d:	anime1(0,1)

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
};
