entity = {
};

cloud = field:load_model("cloud", 5850);
field:set_entity_to_character(cloud, 0);

barret = field:load_model("barret", 5851);
biggs = field:load_model("biggs", 5852);
jessie = field:load_model("jessie", 5853);
wedge = field:load_model("wedge", 5854);



entity["director"] = {
    on_start = function(self)
        --MPNAM (04)

        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --MUSIC (00)
            --UC (01)
            --MENU2 (01)
        elseif progress > 33
            --MUSIC (01)
            --IDLCK (00,00,01)
            --AKAO (00,00,00,A0,40,00,00,00,00,00,00,00,00)
            --SOUND (00,88,00,40)
        end;

        if progress == 33 then
            --SCR2D (00,00,00,00,00)
            --SCRLW ()
            --PMVIE (16)
            script:request("sound_effect", "play", 2);
            --MOVIE ()
            script:request_end_wait("cloud", "scene3", 2);
            --WAIT (10,00)
            script:request_start_wait("barret", "scene3", 2);
            --WAIT (18,00)
            script:request_start_wait("biggs", "scene3", 2);
            --WAIT (10,00)
            script:request_start_wait("jessie", "scene3", 2);
            --WAIT (18,00)
            script:request_end_wait("wedge", "scene3", 2);
            --WAIT (0A,00)
            script:request_start_wait("barret", "scene4", 2);
            --WINDOW (01,6E,00,28,00,F1,00,29,00)
            --MESSAGE (01,00)
            script:request_end_wait("barret", "scene5", 3);
            script:request_start_wait("barret", "scene6", 2);
            --WINDOW (01,28,00,28,00,D6,00,39,00)
            --MESSAGE (01,01)
            script:request_end_wait("barret", "scene7", 3);
            script:request_start_wait("biggs", "scene4", 2);
            script:request_start_wait("wedge", "scene4", 2);
            script:request_start_wait("jessie", "scene4", 2);
            --WAIT (0A,00)
            script:request("biggs", "scene5", 3);
            script:request("jessie", "scene5", 3);
            script:request_end_wait("wedge", "scene5", 3);
            script:request_start_wait("barret", "scene9", 2);
            --WAIT (08,00)
            script:request_start_wait("cloud", "scene4", 2);
            --WINDOW (01,64,00,46,00,89,00,29,00)
            --MESSAGE (01,02)
            script:request_end_wait("cloud", "scene5", 3);
            script:request_end_wait("barret", "scene8", 3);
            script:request_start_wait("barret", "scene4", 2);
            --WINDOW (01,64,00,2D,00,FE,00,39,00)
            --MESSAGE (01,03)
            script:request_end_wait("barret", "scene5", 3);
            --PRTYM (01)
            script:request("barret", "scenea", 2);
            --SCRLC (00,10,00,02)
            --SCRLW ()
            --SCRCC ()
            --SCRLW ()
            game:variable_set("progress_game", 36);
            --IDLCK (00,00,01)
            --HMPMAX3 ()
            --UC (00)
            --MENU2 (00)
        end;

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,29,06,13,EB,00,00,0A,00)
            --DIR (00,C0)
            --TLKON (01)
            --SOLID (01)
            --VISI (00)
        end;

        return 0;
    end;



    scene3 = function(self)
        --TLKON (00)
        --SOLID (00)
        --VISI (01)
        --MSPED (00,00,0C)
        --DFANM (03,01)
        --JUMP (00,00,7C,05,13,EB,0B,00,0A,00)
        --MSPED (00,40,08)
        --DFANM (04,01)
        --FMOVE (00,4A,05,13,EB)
        --MSPED (00,00,0C)
        --DFANM (03,01)
        --FMOVE (00,F6,04,13,EB)
        --ANIM!2 (05,01)
        --DFANM (00,01)
        --ANIME1 (06,01)
        --DIR (00,40)

        return 0;
    end;



    scene4 = function(self)
        --CANM!2 (07,00,0E,01)

        return 0;
    end;



    scene5 = function(self)
        --CANM!2 (08,0E,15,01)

        return 0;
    end;
};



entity["barret"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,5E,06,13,EB,00,00,0F,00)
            --DIR (00,C0)
            --SLIDR (00,01)
            --SOLID (01)
        end;

        return 0;
    end;



    scene3 = function(self)
        --TLKON (00)
        --SOLID (00)
        --VISI (01)
        --MSPED (00,00,0C)
        --DFANM (03,01)
        --JUMP (00,00,A8,05,3B,EB,0B,00,0A,00)
        --FMOVE (00,4C,05,5A,EB)
        --ANIM!2 (04,01)
        --MOVE (00,0E,05,96,EB)
        --DFANM (00,01)
        --ANIME1 (05,01)
        --DIR (00,20)

        return 0;
    end;



    scene4 = function(self)
        --CANM!2 (06,00,0E,01)

        return 0;
    end;



    scene5 = function(self)
        --CANM!2 (06,0E,1D,01)

        return 0;
    end;



    scene6 = function(self)
        --CANM!2 (07,00,13,01)

        return 0;
    end;



    scene7 = function(self)
        --CANM!2 (07,13,1D,01)

        return 0;
    end;



    scene8 = function(self)
        --DFANM (00,01)
        --ASPED (00,20,00)
        --ANIME1 (05,01)
        --ASPED (00,10,00)
        --DIR (00,DE)

        return 0;
    end;



    scene9 = function(self)
        --MOVE (00,51,05,D1,EB)

        return 0;
    end;



    scenea = function(self)
        --ASPED (00,20,00)
        --ANIME1 (05,01)
        --ASPED (00,10,00)
        --DIR (00,5E)
        --MSPED (00,00,0C)
        --MOVE (00,AA,05,C6,EC)
        --MOVE (00,63,03,E7,EC)
        --MOVE (00,03,03,CF,EB)
        --MOVE (00,77,02,EA,EB)
        --TLKON (01)
        --SOLID (01)
        --VISI (00)

        return 0;
    end;
};



entity["biggs"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,5E,06,13,EB,00,00,0F,00)
            --DIR (00,C0)
            --SLIDR (00,01)
        end;

        return 0;
    end;



    scene3 = function(self)
        --TLKON (00)
        --SOLID (00)
        --VISI (01)
        --MSPED (00,00,0C)
        --DFANM (03,01)
        --FMOVE (00,03,06,13,EB)
        --FMOVE (00,CF,05,B5,EB)
        --DFANM (00,01)
        --ANIME1 (04,01)
        --DIRA (02)

        return 0;
    end;



    scene4 = function(self)
        --ANIME1 (05,01)

        return 0;
    end;



    scene5 = function(self)
        --MSPED (00,00,0C)
        --DFANM (02,01)
        --FMOVE (00,CF,05,1C,EA)
        --JUMP (00,00,E6,05,7E,E9,21,00,11,00)
        --TLKON (01)
        --SOLID (01)
        --VISI (00)

        return 0;
    end;
};



entity["jessie"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,5E,06,13,EB,00,00,0F,00)
            --DIR (00,C0)
            --SLIDR (00,01)
        end;

        return 0;
    end;



    scene3 = function(self)
        --TLKON (00)
        --SOLID (00)
        --VISI (01)
        --MSPED (00,00,0C)
        --DFANM (03,01)
        --FMOVE (00,03,06,13,EB)
        --FMOVE (00,7F,05,81,EB)
        --FMOVE (00,48,05,C8,EB)
        --DFANM (00,01)
        --ANIME1 (04,01)
        --DIR (00,15)

        return 0;
    end;



    scene4 = function(self)
        --ANIME1 (05,01)

        return 0;
    end;



    scene5 = function(self)
        --MSPED (00,00,0C)
        --MOVE (00,AA,05,C6,EC)
        --MOVE (00,63,03,E7,EC)
        --MOVE (00,03,03,CF,EB)
        --MOVE (00,77,02,EA,EB)
        --TLKON (01)
        --SOLID (01)
        --VISI (00)

        return 0;
    end;
};



entity["wedge"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 33 then
            --XYZI (00,00,5E,06,13,EB,00,00,0F,00)
            --DIR (00,C0)
            --SLIDR (00,01)
        end;

        return 0;
    end;



    scene3 = function(self)
        --TLKON (00)
        --SOLID (00)
        --VISI (01)
        --DFANM (03,01)
        --MSPED (00,00,0C)
        --FMOVE (00,E0,05,13,EB)
        --FMOVE (00,A8,05,F3,E9)
        --FMOVE (00,F2,04,6C,EA)
        --FMOVE (00,B2,05,6C,EA)
        --FMOVE (00,F2,04,6C,EA)
        --FMOVE (00,B2,05,6C,EA)
        --CANM!2 (04,00,22,01)
        --CANM!2 (04,22,27,01)
        --DFANM (00,01)
        --ANIME1 (05,01)
        --MOVE (00,81,05,3B,EB)
        --DIRA (02)

        return 0;
    end;



    scene4 = function(self)
        --ANIME1 (06,01)

        return 0;
    end;



    scene5 = function(self)
        --MSPED (00,00,0C)
        --DFANM (02,01)
        --FMOVE (00,01,05,59,EA)
        --DFANM (07,01)
        --JUMP (00,00,8E,04,F6,E9,25,00,11,00)
        --TLKON (01)
        --SOLID (01)
        --VISI (00)

        return 0;
    end;
};



entity["sound_effect"] = {
    on_start = function(self)
        return 0;
    end;

    play = function(self)
        --WAIT (08,00)
        --SOUND (00,98,00,40)
        --WAIT (1E,00)
        --SOUND (00,00,00,40)
        --SOUND (00,88,00,40)
    end;
};
