entity = {
};

cloud = field:load_model("cloud", 5850);
barret = field:load_model("barret", 5851);
biggs = field:load_model("biggs", 5852);
jessie = field:load_model("jessie", 5853);
wedge = field:load_model("wedge", 5854);



scene_progress1 = 0;
scene_progress2 = 0;



entity["director"] = {
    on_start = function(self)
        --MUSIC (00)
        --SOUND (00,3D,00,3F)

        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --FADE (00,00,00,00,00,01,04,00)
            --UC (01)
            --MENU2 (01)

            --FADE (00,00,00,00,00,02,01,FF)
            --PMJMP (85,00)
            --FADEW ()
            --WAIT (1E,00)
            script:request_start_wait("biggs", "scene1", 2);
            --WINDOW (01,48,00,3C,00,E5,00,39,00)
            --MESSAGE (01,00)
            script:request_end_wait("biggs", "scene2", 3);
            --WINDOW (01,C8,00,46,00,45,00,29,00)
            --MESSAGE (01,01)
            scene_progress2 = 1;
            --WAIT (1E,00)
            script:request_start_wait("barret", "scene1", 2);
            --WINDOW (01,60,00,46,00,89,00,29,00)
            --MESSAGE (01,02)
            --WAIT (1E,00)
            scene_progress1 = 1;

            while scene_progress1 < 2 then
                script:wait(0);
            end;

            script:request("text", "scene1", 2);
            script:request("cloud", "scene1", 6);
            script:request("barret", "scene2", 6);
            script:request("biggs", "scene3", 6);
            script:request("wedge", "scene1", 6);

            while scene_progress1 < 7 then
                script:wait(0);
            end;

            script:request("cloud", "scene2", 2);
            script:request("barret", "scene3", 2);
            script:request("wedge", "scene2", 2);
            script:request("biggs", "scene4", 2);
            script:request("jessie", "scene1", 2);

            --WAIT (30,00)
            --MAPJUMP (85,00,5D,06,13,EB,0F,00,C0)
        end;

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,13,00,77,01,00,00,05,00)
            --DFANM (03,01)
            --DIR (00,E0)
            --SLIDR (00,01)
            --SOLID (01)
        end;

        return 0;
    end;



    scene1 = function(self)
        --ANIM!2 (04,01)
        scene_progress1 = scene_progress1 + 1;

        return 0;
    end;



    scene2 = function(self)
        --DFANM (02,01)
        --MSPED (00,00,0B)
        --FMOVE (00,D4,FF,48,03)

        return 0;
    end;
};



entity["barret"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,9C,FF,ED,01,00,00,05,00)
            --SLIDR (00,01)
            --SOLID (01)
            --CANM!2 (03,00,00,01)
        end;

        return 0;
    end;



    scene1 = function(self)
        --ANIM!2 (04,01)

        return 0;
    end;



    scene2 = function(self)
        --ANIM!2 (03,01)
        scene_progress1 = scene_progress1 + 1;

        return 0;
    end;



    scene3 = function(self)
        --DFANM (02,01)
        --MSPED (00,00,0A)
        --FMOVE (00,A6,FF,F7,02)

        return 0;
    end;
};



entity["biggs"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,D7,FF,BB,02,00,00,07,00)
            --SLIDR (00,01)
            --SOLID (01)
            --CANM!2 (03,00,00,01)

            while true do
                if scene_progress2 ~= 0 then
                    --ANIM!2 (03,01)
                end;

                script:wait(0);
            end;
        end;

        return 0;
    end;



    scene1 = function(self)
        --CANM!2(6,0,9,1)

        return 0;
    end;



    scene2 = function(self)
        --CANM!2 (06,09,13,01)

        return 0;
    end;



    scene3 = function(self)
        --ANIM!2 (04,01)
        scene_progress1 = scene_progress1 + 1;

        return 0;
    end;



    scene4 = function(self)
        --ANIME1 (05,01)
        --DIR (00,00)
        --DFANM (02,01)
        --MSPED (00,00,0A)
        --FMOVE (00,EC,FF,60,03)

        return 0;
    end;

};



entity["jessie"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,BF,FF,5F,00,00,00,01,00)
            --DIR (00,C0)
            --SLIDR (00,01)
            --SOLID (01)


            while true do
                if scene_progress1 == 0 then
                    --ANIM!2 (03,01)
                else
                    --SOUND (00,00,00,3F)
                    --ANIM!2 (04,01)
                    --ASPED (00,20,00)
                    --ANIM!2 (05,01)
                    scene_progress1 = scene_progress1 + 1;
                    break;
                end;

                script:wait(0);
            end;
        end;

        return 0;
    end;



    scene1 = function(self)
        --ASPED (00,10,00)
        --DFANM (02,01)
        --MSPED (00,00,0A)
        --FMOVE (00,E5,FF,70,02)

        return 0;
    end;
};



entity["wedge"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,44,00,F5,00,00,00,03,00)
            --SLIDR (00,01)
            --SOLID (01)
            --DIRA (05)

            while true do
                --ANIM!2 (03,01)

                script:wait(0);
            end;
        end;

        return 0;
    end;



    scene1 = function(self)
        --DFANM (02,01)
        scene_progress1 = scene_progress1 + 1;

        return 0;
    end;



    scene2 = function(self)
        --MSPED (00,00,0A)
        --MOVE (00,B0,FF,E9,02)

        return 0;
    end;
};



entity["text"] = {
    on_start = function(self)
        return 0;
    end;

    scene1 = function(self)
        --WINDOW (00,46,00,32,00,B4,00,39,00)
        --MESSAGE (00,03)
        scene_progress1 = scene_progress1 + 1;
    end;
};