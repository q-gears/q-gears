entity = {
};

cloud = field:load_model("cloud", 5850);
field:set_entity_to_character(cloud, 0);

biggs = field:load_model("biggs", 5852);
jessie = field:load_model("jessie", 5853);
wedge = field:load_model("wedge", 5854);



entity["director"] = {
    on_start = function(self)
        --BTLMD2 (20,00)
        --MUSIC (00)
        --MPNAM (02)

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["biggs"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress < 8 then
            game:variable_set("progress_game", 8);

            biggs:set_position_triangle(3437, 31524, 642, 47);
            biggs:set_solid(true);
            biggs:set_visible(true);
            biggs:set_speed(480);
            biggs:move_to_position(3646, 31219, true);
            biggs:play_animation_wait("3", 0, -1, 1, false);
            biggs:move_to_position(4277, 31259, true);
            biggs:move_to_position(4364, 32052, true);
            biggs:move_to_position(3381, 32313, true);
            biggs:move_to_position(3010, 32350, true);
            biggs:set_solid(false);
            biggs:set_visible(false);
        end;

        return 0;
    end;
};



entity["jessie"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress < 8 then
            jessie:set_animation_default("3", 1);
            jessie:set_speed(480);
            jessie:set_direction(354.38);
            jessie:set_position_triangle(3574, 32483, 636, 12);
            jessie:set_solid(true);
            jessie:set_visible(true);
            script:wait(8.5);
            jessie:move_to_position(3381, 32313, true);
            jessie:move_to_position(3010, 32350, true);
            jessie:set_solid(false);
            jessie:set_visible(false);
        end;

        return 0;
    end;
};



entity["wedge"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress < 8 then
            wedge:set_animation_default("3", 1);
            wedge:set_speed(480);
            wedge:set_direction(354.38);
            wedge:set_position_triangle(4356, 31678, 652, 31);
            wedge:set_solid(true);
            wedge:set_visible(true);
            script:wait(4.27);
            wedge:move_to_position(4312, 32085, true);
            wedge:move_to_position(3381, 32313, true);
            wedge:move_to_position(3010, 32350, true);
            wedge:set_solid(false);
            wedge:set_visible(false);
        end;

        return 0;
    end;
};
