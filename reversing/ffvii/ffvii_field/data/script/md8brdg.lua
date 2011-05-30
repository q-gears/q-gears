entity = {
};



temp0 = 0;
temp1 = 0;
temp2 = 0;
temp3 = 0;
temp4 = 0;
temp5 = 0;
temp6 = 0;



entity["director"] = {
    on_start = function(self)
        MUSIC (00)
        BMUSC (01)
        MPNAM (08)

        BTLMD (08,00)
        return 0;
    end;

    scene3 = function(self)
        WSIZW (00,91,00,08,00,88,00,29,00)
        MESSAGE (00,00)

        script:request_start_wait("soldier1", "scene3", 2);

        WAIT (0F,00)

        script:request_start_wait("soldier1", "scene3", 2);

        script:request("soldier2", "scene3", 2);
        script:request("soldier1", "scene4", 3);
        script:request("soldier2", "scene4", 3);
        script:request("message2", "scene1", 2);

        while temp0 == 0 do
            script:wait(0);
        end;

        while temp0 == 1 do
            script:wait(0);
        end;

        WCLSE (02)

        while temp5 == 0 do
            script:wait(0);
        end;

        if temp4 == 2 then
            script:request_end_wait("cloud", "scene5", 2);

            BATTLE (00,48,01)

            script:request_end_wait("soldier1", "scene12", 4); -- hide
            script:request_end_wait("soldier2", "scene10", 4); -- hide

            WSIZW (02,91,00,08,00,88,00,29,00)

            script:request("tifa", "scene3", 2);

            MESSAGE (02,09)

            script:request_start_wait("message2", "scene4", 3); -- hide

            script:request("soldier1", "scene11", 4);
            script:request("soldier2", "scene9", 4);
            script:request("cloud", "scene4", 2);
            script:request("tifa", "scene3", 2);
        else
            script:request("cloud", "scene3", 2);
            script:request_start_wait("soldier1", "scene5", 4);
            temp1 = 2;
            script:request_start_wait("soldier1", "scene1", 3);
            script:request_start_wait("message1", "scene1", 3);
        end;

        script:request_end_wait("soldier2", "scene5", 5);
        script:request_start_wait("soldier2", "scene6", 2);

        WCLSE (02)

        script:request_end_wait("soldier1", "scene7", 2);
        script:request_start_wait("soldier1", "scene8", 2);

        while temp3 == 0 do
            script:wait(0);
        end;

        script:request_start_wait("cloud", "scene6", 3);
        script:request("message2", "scene2", 4);
        script:request("soldier3", "scene3", 2);
        script:request("soldier4", "scene3", 2);
        script:request("soldier8", "scene3", 2);

        while temp6 == 0 do
            script:wait(0);
        end;

        WCLSE (02)

        while temp5 == 0 do
            script:wait(0);
        end;

        if temp4 == 0 then
            BATTLE (00,49,01)
            REQEW (09,66)
            REQEW (0A,66)
            REQEW (0B,66)
            WSIZW (02,08,00,3C,00,6A,00,29,00)
            REQ (02,43)
            MESSAGE (02,01)
            REQSW (06,64)
            REQ (09,47)
            REQ (0A,47)
            REQ (0B,47)
            REQ (02,43)
        end;

        REQ (09,84)
        REQ (0A,84)
        REQ (0B,84)
        REQ (07,A9)
        REQ (08,A7)
        REQEW (01,47)
        SETBYTE (50,06,00)
        REQEW (01,46)
        REQ (06,A2)
        REQ (0C,43)
        REQ (0D,43)
        REQ (0E,43)
        IFUB (50,06,00,00,03)
        JMPB (06)
        WCLSE (02)
        IFUB (50,05,00,00,03)
        JMPB (06)
        IFUB (50,04,00,00,2D)
        BATTLE (00,4A,01)
        REQEW (0C,66)
        REQEW (0D,66)
        REQEW (0E,66)
        WSIZW (02,08,00,3C,00,67,00,29,00)
        REQ (02,43)
        MESSAGE (02,03)
        REQSW (06,64)
        REQ (0C,47)
        REQ (0D,47)
        REQ (0E,47)
        REQ (02,43)
        REQ (0C,84)
        REQ (0D,84)
        REQ (0E,84)
        REQEW (01,48)
        REQEW (01,49)
        REQSW (07,85)
        SETBYTE (50,01,05)
        REQSW (05,41)
        REQEW (07,A6)
        WAIT (0C,00)
        WCLSE (01)
        REQSW (01,4A)
        SETBYTE (50,01,06)
        REQSW (05,61)
        REQEW (01,6B)
        WAIT (08,00)
        WCLSE (01)
        REQSW (07,85)
        SETBYTE (50,01,07)
        REQSW (05,81)
        REQEW (07,A6)
        WAIT (1E,00)
        WCLSE (01)
        WAIT (05,00)
        REQ (07,4A)
        REQ (08,48)
        REQ (09,45)
        REQ (0A,45)
        REQ (0C,45)
        REQ (0D,45)
        REQ (0E,45)
        REQ (0B,45)
        AKAO (00,00,00,A0,FF,00,00,00,00,00,00,00,00)
        SOUND (00,90,01,3F)
        REQSW (01,4C)
        PMVIE (17)
        MOVIE ()
        FADE (00,00,00,00,00,01,04,00)
        AKAO (00,00,00,C1,5A,00,00,00,00,00,00,00,00)
        WAIT (5A,00)
        MUSIC (02)
        AKAO (00,00,00,C0,7F,00,00,00,00,00,00,00,00)
        MAPJUMP (8A,00,00,00,00,00,00,00,00)

        return 0;
    end;
};



entity["message1"] = {
    on_start = function(self)
        return 0;
    end;

    scene1 = function(self)
        if temp1 == 1 then
            WSIZW (02,3C,00,50,00,89,00,29,00)
            MESSAGE (02,04)
        elseif temp1 == 2 then
            WSIZW (02,87,00,28,00,46,00,29,00)
            MESSAGE (02,02)
        elseif temp1 == 3 then
            WSIZW (00,08,00,3C,00,6A,00,29,00)
            MESSAGE (00,01)
        elseif temp1 == 4 then
            WSIZW (02,D2,00,3C,00,67,00,29,00)
            MESSAGE (02,03)
        elseif temp1 == 5 then
            WSIZW (01,82,00,28,00,A9,00,29,00)
            MESSAGE (01,05)
        elseif temp1 == 6 then
            WSIZW (01,41,00,28,00,F8,00,39,00)
            MESSAGE (01,06)
        elseif temp1 == 7 then
            WSIZW (01,78,00,28,00,89,00,39,00)
            MESSAGE (01,07)
        end;

        return 0;
    end;
};



entity["message2"] = {
    on_start = function(self)
        return 0;
    end;

    scene1 = function(self)
        temp5 = 0;
        WSIZW (02,3C,00,50,00,89,00,49,00)
        temp4 = 2;
        ASK (05,02,0A,02,03,04)
        temp5 = 1;

        return 0;
    end;

    scene2 = function(self)
        temp5 = 0;
        WSIZW (02,3C,00,50,00,73,00,29,00)
        temp4 = 0;
        ASK (05,02,0C,00,01,04)
        temp5 = 1;

        return 0;
    end;

    scene4 = function(self)
        WSIZW (02,00,00,3C,00,89,00,29,00)
        MESSAGE (02,0B)

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        SOLID (01)

        return 0;
    end;

    scene3 = function(self)
        MSPED (00,00,0A)
        MOVE (00,5A,FE,53,01)
        MOVE (00,7D,FD,B7,00)
        temp3 = 1;

        return 0;
    end;

    scene4 = function(self)
        TURNGEN (00,00,02,08,01)
        MSPED (00,00,0A)
        MOVE (00,5A,FE,53,01)
        MOVE (00,7D,FD,B7,00)

        temp3 = 1;

        return 0;
    end;

    scene5 = function(self)
        TURNGEN (00,80,02,08,01)

        return 0;
    end;

    scene6 = function(self)
        ANIM!2 (03,01)

        return 0;
    end;

    scene7 = function(self)

        return 0;
    end;

    scene8 = function(self)

        return 0;
    end;

    scene9 = function(self)

        return 0;
    end;

    scene10 = function(self)

        return 0;
    end;

    scene11 = function(self)

        return 0;
    end;

    scene12 = function(self)

        return 0;
    end;
};



entity["tifa"] = {
    on_start = function(self)
        CHAR (01)
        PC (02)

        return 0;
    end;

    scene3 = function(self)
        WAIT (14,00)
        WCLSE (02)

        return 0;
    end;
};



entity["soldier1"] = {
    on_start = function(self)
        CHAR (03)
        XYZI (00,00,20,FE,BA,06,06,02,54,00)

        local progress = game:variable_get("progress_game");
        if progress != 39 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        end;

        SOLID (01)

        return 0;
    end;

    scene3 = function(self)
        MSPED (00,00,0A)
        MOVE (00,20,FE,00,05)

        temp0 = 1;

        return 0;
    end;

    scene4 = function(self)
        MSPED (00,00,04)
        MOVE (00,20,FE,C7,03)
        temp0 = 2;
        MOVE (00,20,FE,8E,03)

        return 0;
    end;

    scene5 = function(self)
        CANM!2 (03,00,0E,01)

        return 0;
    end;

    scene7 = function(self)
        CANM!2 (04,00,09,01)

        return 0;
    end;

    scene8 = function(self)
        while temp2 == 0 do
            SOUND (00,10,00,40)
            ANIM!2 (05,01)
        end;

        return 0;
    end;

    scene12 = function(self)
        TLKON (01)
        SOLID (01)
        VISI (00)

        return 0;
    end;
};



entity["soldier2"] = {
    on_start = function(self)
        CHAR (04)
        XYZI (00,00,98,FE,BA,06,06,02,54,00)

        local progress = game:variable_get("progress_game");
        if progress != 39 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        end;

        SOLID (01)

        return 0;
    end;

    scene3 = function(self)
        MSPED (00,00,0A)
        MOVE (00,98,FE,00,05)

        return 0;
    end;

    scene4 = function(self)
        MSPED (00,00,04)
        MOVE (00,98,FE,C8,03)

        return 0;
    end;

    scene5 = function(self)
        CANM!2 (04,00,09,01)

        return 0;
    end;

    scene6 = function(self)
        while temp2 == 0 do
            SOUND (00,10,00,40)
            ANIM!2 (05,01)
        end;

        return 0;
    end;

    scene10 = function(self)
        TLKON (01)
        SOLID (01)
        VISI (00)

        return 0;
    end;
};



entity["soldier3"] = {
    on_start = function(self)
        CHAR (05)
        XYZI (00,00,12,FC,2A,01,06,02,1F,00)
        DIR (00,40)

        local progress = game:variable_get("progress_game");
        if progress != 39 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        end;

        SOLID (01)

        return 0;
    end;

    scene3 = function(self)
        MSPED (00,00,07)
        DFANM (02,01)
        FMOVE (00,A9,FD,2A,01)
        DFANM (00,01)
        temp6 = 1;

        return 0;
    end;
};



entity["soldier4"] = {
    on_start = function(self)
        CHAR (06)
        XYZI (00,00,35,FC,93,00,06,02,1F,00)
        DIR (00,40)

        local progress = game:variable_get("progress_game");
        if progress != 39 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        end;

        SOLID (01)

        return 0;
    end;

    scene3 = function(self)
        MSPED (00,00,07)
        DFANM (02,01)
        FMOVE (00,19,FD,93,00)
        DFANM (00,01)

        return 0;
    end;
};



entity["soldier5"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["soldier6"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["soldier7"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["soldier8"] = {
    on_start = function(self)
        CHAR (07)
        XYZI (00,00,40,FE,67,FE,06,02,46,00)
        DIR (00,80)

        local progress = game:variable_get("progress_game");
        if progress != 39 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        end;

        SOLID (01)

        return 0;
    end;

    scene3 = function(self)
        MSPED (00,00,07)
        DFANM (02,01)
        FMOVE (00,40,FE,BE,FF)
        DFANM (00,01)

        return 0;
    end;
};



entity["trigger"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress != 39 then
            field:line_trigger_on("trigger", false);
        end;

        return 0;
    end;

    on_talk = function(self)
        return 0;
    end;

    on_enter_line = function(self)
        UC (01)
        MENU2 (01)
        script:request("director", "scene3", 2);
        field:line_trigger_on("trigger", false);

        return 0;
    end;

    on_leave_line = function(self)
        return 0;
    end;

    on_cross_line = function(self)
        return 0;
    end;

    on_move_to_line = function(self)
        return 0;
    end;

    on_activate_line = function(self)
        return 0;
    end;
};
