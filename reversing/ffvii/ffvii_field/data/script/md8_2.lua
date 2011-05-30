entity = {
};

cloud = field:load_model("cloud", 5850);
field:set_entity_to_character(cloud, 0);

aeris = field:load_model("aeris", 5851);
people1 = field:load_model("people1", 5852);
people2 = field:load_model("people2", 5852);
people3 = field:load_model("people3", 5852);

temp0 = 0;
temp1 = 0;
temp2 = 0;
temp3 = 0;
temp4 = 0;
temp6 = 0;

entity["director"] = {
    on_start = function(self)
        SOUND (00,00,00,3F)
        AKAO (00,00,00,A0,FF,00,00,00,00,00,00,00,00)
        MUSIC (00)

        local progress = game:variable_get("progress_game");
        if progress == 36 then
            UC (01)
            MENU2 (01)
            SCR2D (00,28,00,83,00)
            SCRLW ()
            WAIT (5A,00)
            SCR2DL (00,00,28,00,9B,FF,96,00)

            temp0 = 1;
            temp4 = 1;

            SCRLW ()
            BITON (30,42,00)
            WAIT (24,00)

            script:request_end_wait("cloud", "scene3", 2);
            script:request("aeris", "scene6", 3);

            WINDOW (02,3C,00,1E,00,64,00,29,00)
            MESSAGE (02,00)

            script:request_end_wait("cloud", "scene4", 2);
            temp2 = 1;
            script:request_start_wait("aeris", "scene4", 4);

            WINDOW (02,3C,00,91,00,D1,00,49,00)
            temp1 = 2; -- variable for 1st ask
            ASK (05,02,01,02,03,01)

            script:request_end_wait("aeris", "scene4", 5);

            temp5 = 1;

            if temp1 == 2 then
                temp2 = 3;
                script:request_start_wait("aeris", "scene4", 2);

                WINDOW (02,3C,00,91,00,CC,00,49,00)
                MESSAGE (02,02)

                script:request_end_wait("aeris", "scene4", 3);
                script:request("aeris", "scene3", 2);
            else
                temp3 = 1;

                script:request_end_wait("cloud", "scene5", 2);

                temp1 = 2;

                WINDOW (00,A0,00,91,00,FD,00,49,00)
                ASK (05,00,03,02,03,01)

                script:request_end_wait("cloud", "scene5", 3);

                if temp1 == 2 then
                    temp2 = 5;
                    script:request_start_wait("aeris", "scene4", 2);

                    WINDOW (02,3C,00,91,00,97,00,49,00)
                    MESSAGE (02,05)
                else
                    temp2 = 12;
                    script:request_start_wait("aeris", "scene4", 2);

                    WINDOW (02,64,00,91,00,56,00,39,00)
                    MESSAGE (02,04)

                    script:request_end_wait("aeris", "scene4", 3);
                    temp2 = 5;
                    script:request_start_wait("aeris", "scene4", 2);

                    WINDOW (02,3C,00,91,00,C7,00,49,00)
                    MESSAGE (02,07)
                end;

                temp1 = 0;

                WINDOW (00,A0,00,91,00,5F,00,29,00)
                ASK (05,00,06,00,01,01)

                if temp1 == 0 then
                    temp2 = 6;
                    script:request_start_wait("aeris", "scene4", 3);

                    WINDOW (02,5A,00,91,00,7C,00,29,00)
                    MESSAGE (02,08)

                    script:request_end_wait("aeris", "scene4", 4);
                    script:request_start_wait("aeris", "scene4", 2);

                    WINDOW (02,82,00,91,00,70,00,29,00)
                    MESSAGE (02,09)

                    script:request_end_wait("aeris", "scene4", 3);
                    script:request("aeris", "scene3", 2);

                    GOLD- (00,01,00,00,00)
                    BITON (30,6F,00)
                else
                    temp2 = 10;
                    script:request_start_wait("aeris", "scene4", 3);

                    WINDOW (02,3C,00,91,00,7D,00,29,00)
                    MESSAGE (02,0A)

                    script:request_end_wait("aeris", "scene4", 4);
                    script:request("aeris", "scene3", 2);
                end;
            end;

            game:variable_set("progress_game", 39);

            SCRLC (00,1E,00,02)
            SCRLW ()
            SCRCC ()
            SCRLW ()
            UC (00)
            MENU2 (00)
        end;

        temp6 = 1;

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        SOLID (01)

        return 0;
    end;



    scene3 = function(self)
        XYZI (00,00,92,F1,0F,53,02,01,02,00)
        MOVE (00,6B,F0,92,52)

        return 0;
    end;



    scene4 = function(self)
        ASPED (00,20,00)
        DFANM (03,01)
        TURNGEN (00,96,01,07,01)
        DFANM (04,01)
        ASPED (00,10,00)

        return 0;
    end;



    scene5 = function(self)
        if temp3 == 1 then
            CANM!2 (05,00,0E,01)
            temp3 = 2;
        elseif temp3 == 2 then
            CANM!2 (05,0E,1D,01)
        end;

        return 0;
    end;
};



entity["aeris"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 36 then
            DIR (00,18)
            XYZI (00,00,1E,F0,19,53,02,01,09,00)
            SLIDR (00,01)
            SOLID (01)
        end;

        ANIM!2 (02,01)
        ANIM!2 (02,01)
        DFANM (00,01)

        return 0;
    end;



    scene3 = function(self)
        MSPED (00,F0,05)
        MOVE (00,2B,F0,C5,51)
        MOVE (00,DD,F0,C1,50)
        MOVE (00,A3,F0,07,50)
        TLKON (01)
        SOLID (01)
        VISI (00)

        return 0;
    end;



    scene4 = function(self)
        if temp2 == 1 then
            CANM!2(3,0,1D,1)
            temp2 = 2;
        elseif temp2 == 2 then
            CANM!2(3,1D,27,1)
        elseif temp2 == 3 then
            CANM!2(4,0,9,1)
            temp2 = 4;
        elseif temp2 == 4 then
            CANM!2(4,9,13,1)
        elseif temp2 == 5 then
            ANIM!2(5,1)
        elseif temp2 == 6 then
            ANIM!2(6,1)
            temp2 = 7;
        elseif temp2 == 7 then
            ANIM!2(7,1)
            temp2 = 8;
        elseif temp2 == 8 then
            CANM!2(8,0,E,1)
            temp2 = 9;
        elseif temp2 == 9 then
            CANM!2(8,E,1D,1)
        elseif temp2 == 10 then
            CANM!2(9,0,1A,1)
            temp2 = 11;
        elseif temp2 == 11 then
            CANM!2(9,1A,27,1)
        elseif temp2 == 12 then
            CANM!2(A,0,1A,1)
            temp2 = 13;
        elseif temp2 == 13 then
            CANM!2(A,1A,27,1)
        end;

        return 0;
    end;



    scene5 = function(self)
        SOUND (00,AF,00,3F)
        ANIM!2 (0B,01)
        ANIM!2 (0C,01)
        ANIM!2 (0D,01)

        return 0;
    end;



    scene6 = function(self)
        MOVE (00,41,F0,D8,52)

        return 0;
    end;



    scene7 = function(self)

        return 0;
    end;
};



entity["people1"] = {
    on_start = function(self)
        XYZI (00,00,44,EF,55,52,02,01,10,00)
        SLIDR (00,01)
        SOLID (01)

        local progress = game:variable_get("progress_game");
        if progress ~= 36 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        else
            while temp4 == 0 do
                script:wait(0);
            end;

            WAIT (5A,00)
            MSPED (00,00,0A)
            MOVE (00,4B,F0,24,52)
            MOVE (00,04,F1,24,52)
            MOVE (00,FB,F0,D4,50)
            MOVE (00,8E,F0,F2,4F)
            TLKON (01)
            SOLID (01)
            VISI (00)
        end;

        return 0;
    end;
};



entity["people2"] = {
    on_start = function(self)
        CHAR (03)
        XYZI (00,00,21,F1,5E,51,02,01,1D,00)
        SLIDR (00,01)
        SOLID (01)
        TLKON (01)
        SOLID (01)
        VISI (00)

        local progress = game:variable_get("progress_game");
        if progress == 36 then
            TLKON (00)
            SOLID (00)
            VISI (01)
            SLIDR (00,01)
            SOLID (01)

            while temp4 == 0 do
                script:wait(0);
            end;

            WAIT (5A,00)
            MSPED (00,00,0A)
            MOVE (00,46,F0,CD,50)
            MOVE (00,1C,F0,4E,52)
            MOVE (00,11,EF,5D,52)
            MOVE (00,FB,EF,32,52)
            MOVE (00,FE,F0,DF,51)
            MOVE (00,7B,F0,CB,4F)
            TLKON (01)
            SOLID (01)
            VISI (00)

            while temp6 == 0 do
                script:wait(0);
            end;
        end;

        while true do
            MSPED (00,00,0A)
            RANDOM (05,07)
            if temp7 > 0xF0 then
                RANDOM (05,07)
                AND (50,07,03)

                if temp7 == 1 then
                    XYZI (00,00,33,EF,5C,52,02,01,10,00)
                    TLKON (00)
                    SOLID (00)
                    VISI (01)
                    SLIDR (00,01)
                    SOLID (01)
                    MOVE (00,53,F0,38,52)
                    MOVE (00,59,F0,D0,50)
                    MOVE (00,D6,F0,CD,50)
                    MOVE (00,7B,F0,CB,4F)
                    TLKON (01)
                    SOLID (01)
                    VISI (00)
                elseif temp7 == 2 then
                    XYZI (00,00,7B,F0,CB,4F,02,01,29,00)
                    TLKON (00)
                    SOLID (00)
                    VISI (01)
                    SLIDR (00,01)
                    SOLID (01)
                    MOVE (00,03,F1,1A,51)
                    MOVE (00,6F,F0,01,52)
                    MOVE (00,2F,F1,30,53)
                    MOVE (00,58,F2,0D,53)
                    MOVE (00,8C,F2,0D,53)
                    TLKON (01)
                    SOLID (01)
                    VISI (00)
                elseif temp7 == 3 then
                    XYZI (00,00,8C,F2,0D,53,02,01,23,00)
                    TLKON (00)
                    SOLID (00)
                    VISI (01)
                    SLIDR (00,01)
                    SOLID (01)
                    MOVE (00,58,F2,0D,53)
                    MOVE (00,2F,F1,30,53)
                    MOVE (00,25,F0,AE,51)
                    MOVE (00,A7,EF,68,52)
                    MOVE (00,0E,EF,5D,52)
                    TLKON (01)
                    SOLID (01)
                    VISI (00)
                end;
            end;

            WAIT (3C,00)
        end;

        return 0;
    end;
};



entity["people3"] = {
    on_start = function(self)
        CHAR (04)
        XYZI (00,00,3C,F1,AD,52,02,01,24,00)
        SLIDR (00,01)
        SOLID (01)

        local progress = game:variable_get("progress_game");
        if progress ~= 36 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        else
            while temp4 == 0 do
                script:wait(0);
            end;

            WAIT (41,00)
            MSPED (00,00,0A)
            MOVE (00,42,F0,F0,52)

            script:request("aeris", "scene5", 2);

            MOVE (00,38,F0,90,51)
            MOVE (00,99,EF,64,52)
            MOVE (00,0A,EF,55,52)
        end;

        return 0;
    end;
};
