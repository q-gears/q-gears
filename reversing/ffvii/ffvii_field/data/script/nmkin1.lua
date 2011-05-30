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
        field:lock_walkmesh(2, true);
        field:lock_walkmesh(8, true);
        field:lock_walkmesh(10, true);
        field:lock_walkmesh(37, true);
        field:lock_walkmesh(51, true);
        field:lock_walkmesh(52, true);
        field:lock_walkmesh(53, true);
        field:lock_walkmesh(61, true);



        local progress = game:variable_get("progress_game");
        if progress == 27 then
            --AKAO (00,00,00,29,40,3C,00,00,00,00,00,00,00)
            --BTLMD (22,00)
            --BMUSC (00)
        else
            --AKAO (00,00,00,C0,7F,00,00,00,00,00,00,00,00)
            --MULCK (00)
            --MUSIC (01)
            --BMUSC (02)
        end;

        if progress < 27 then
            field:random_encounter_on(false);
        end;

        --MPNAM (03)

        --REQ(B,C3)
        if progress == 27 then
            --REQ(1,C3)
        end;

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["barret"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 10 then
            --XYZI(0,-2B3,90A,-114,1E)
            --DIR(0,0)
            --TalkSwitch(On)
            --SolidObject(On)
            --VISI(On)
        end;

        return 0;
    end;
};
