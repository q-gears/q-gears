entity = {
};

cloud = field:load_model("cloud", 5850);
field:set_entity_to_character(cloud, 0);

barret = field:load_model("barret", 5851);
field:set_entity_to_character(barret, 1);

biggs = field:load_model("biggs", 5852);
jessie = field:load_model("jessie", 5853);
wedge = field:load_model("wedge", 5854);



entity["director"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress >= 27 then
            --SCR2D (00,E3,FF,28,00)
            --AKAO (00,00,00,29,40,3C,00,00,00,00,00,00,00)
        else
            --BTLMD2 (20,00)
            --MUSIC (00)
        end;

        --MPNAM (03)

        if progress < 27
            --REQ (09,C1) // open door sprite
            --IDLCK (0B,00,01)
        end;

        return 0;
    end;



    reactor_blow = function(self)
        --MVCAM (01)
        --PMVIE (15)
        --SETBYTE (50,14,01) // to check the movie
        game:variable_set("progress_game", 33);
        local mission1_flags = game:variable_get("mission1_flags");
        -- move lift to top
        game:variable_set("mission1_flags", bit.bor(mission1_flags, hex.to_dec('0x0001')));
        --MOVIE ()
        --MVCAM (00)

        local mission1_flags = game:variable_get("mission1_flags");
        if bit.band(mission1_flags, hex.to_dec('0x0080')) ~= 0 then
            --GAMEOVER ()
        end;

        --AKAO (00,00,00,29,40,00,00,00,00,00,00,00,00)
        --MUSIC (01)
        --AKAO (00,00,00,A1,7F,00,00,00,00,00,00,00,00)
        --AKAO (00,00,00,C1,00,7F,00,00,00,00,00,00,00)
        --MAPJUMP (88,00,EB,FF,9C,00,02,00,00) -- load md8_4

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 27 then
            field:pc_lock(true);
            --MenuAccess(Off)

            local mission1_flags = game:variable_get("mission1_flags");
            if bit.band(mission1_flags, hex.to_dec('0x0080')) ~= 0 then
                script:wait(0.27);
                script:request("director", "reactor_blow", 6);
                script:wait(0.67);
                --AKAO (00,00,00,29,40,00,00,00,00,00,00,00,00)
            end;
        end;

        return 0;
    end;
};



entity["barret"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 27 then
            local mission1_flags = game:variable_get("mission1_flags");
            if bit.band(mission1_flags, hex.to_dec('0x0080')) == 0 then
                barret:set_position_triangle(-36, -951, 491, 10);
                barret:set_visible(true);
                barret:set_speed(480);
                script:wait(0.13);
                --MOVE (00,06,00,29,F4)
                --MOVE (00,29,FB,1E,F4)
            end;
        end;

        return 0;
    end;
};



entity["biggs"] = {
    on_start = function(self)
        --DFANM (02,01)
        --MSPED (00,00,12)
        --DIR (00,B0)

        local progress = game:variable_get("progress_game");
        if progress < 10 then
            --XYZI (00,00,26,00,F5,FB,EB,01,01,00)
            biggs:set_solid(true);
            biggs:set_visible(true);
            --MOVE (00,E4,FF,CA,F4)
            --MOVE (00,0F,00,D5,FC)
            biggs:set_solid(false);
            biggs:set_visible(false);
        elseif progress == 27
            local mission1_flags = game:variable_get("mission1_flags");
            if bit.band(mission1_flags, hex.to_dec('0x0080')) == 0 then
                --XYZI (00,00,C0,00,52,F4,EB,01,05,00)
                biggs:set_solid(true);
                biggs:set_visible(true);
                --MOVE (00,06,00,29,F4)
                --MOVE (00,29,FB,1E,F4)
                biggs:set_solid(false);
                biggs:set_visible(false);
            end;
        end;

        return 0;
    end;
};



entity["jessie"] = {
    on_start = function(self)
        --DIR (00,B0)

        local progress = game:variable_get("progress_game");
        if progress < 10 then
            --XYZI (00,00,6D,01,EF,F3,EB,01,05,00)
            jessie:set_solid(true);
            jessie:set_visible(true);
            --MSPED (00,00,11)
            --MOVE (00,ED,FF,7F,F4)
            --MOVE (00,0F,00,D5,FC)
            jessie:set_solid(false);
            jessie:set_visible(false);
        elseif progress == 27
            local mission1_flags = game:variable_get("mission1_flags");
            if bit.band(mission1_flags, hex.to_dec('0x0080')) == 0 then
                --XYZI (00,00,1E,00,DD,FB,EB,01,01,00)
                jessie:set_visible(true);
                script:wait(1.67);
                --MSPED (00,00,17)
                --MOVE (00,40,00,00,F4)
                --MOVE (00,00,FF,10,F4)
                --DFANM (03,01)
                --FMOVE (00,40,FE)
                jessie:set_visible(false);
            end;
        end;

        return 0;
    end;
};



entity["wedge"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress < 10 then
            wedge:set_solid(true);
            wedge:set_visible(true);
            wedge:set_talkable(true);
            --XYZI (00,00,42,02,65,F4,EB,01,06,00)
            --MSPED (00,00,0F)
            --MOVE (00,83,FC,22,F4)
            --DIR (00,B0)
            --DFANM (03,01)
            game:variable_set("progress_game", 10);
        elseif progress >= 10 and progress < 27 then
            wedge:set_solid(true);
            wedge:set_visible(true);
            wedge:set_talkable(true);
            --XYZI (00,00,83,FC,22,F4,EB,01,02,00)
            --DIR (00,B0)
            --DFANM (03,01)
        elseif progress == 27 then
            local mission1_flags = game:variable_get("mission1_flags");
            if bit.band(mission1_flags, hex.to_dec('0x0080')) == 0 then
                wedge:set_solid(true);
                wedge:set_visible(true);
                --XYZI (00,00,83,FC,22,F4,EB,01,02,00)
                --WAIT (8C,00)
                --MSPED (00,00,0A)
                --MOVE (00,F4,FA,2A,F4)
                wedge:set_solid(false);
                wedge:set_visible(false);
            end;
        end;

        return 0;
    end;



    on_talk = function(self)
        field:pc_lock(true);
        --MenuAccess(Off)
        --WINDOW (01,0F,00,0A,00,CA,00,49,00)
        --MESSAGE (01,2B)
        --WINDOW (01,14,00,0A,00,CB,00,49,00)
        --MESSAGE (01,2C)
        --MenuAccess(On)
        field:pc_lock(false);
        return 0;
    end;
};
