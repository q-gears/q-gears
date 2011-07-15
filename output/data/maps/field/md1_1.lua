entity = {
};

cloud = field:load_model("cloud", 5850);
field:set_entity_to_character(cloud, 0);

barret = field:load_model("barret", 5851);
field:set_entity_to_character(barret, 1);

biggs = field:load_model("biggs", 5852);
jessie = field:load_model("jessie", 5853);
wedge = field:load_model("wedge", 5854);
door_left = field:load_model("door_left", 5855);
door_right = field:load_model("door_right", 5855);



entity["director"] = {
    on_start = function(self)
        --SCRCC                                                           --???
        --BTLMD(20,0)                                                     -- ???
        --MUSIC(0)                                                        -- ???
        --MPNAM(1)                                                        -- ???

        local progress = game:variable_get("progress_game");

        while true do
            triangle_id = cloud:get_triangle();

            if triangle_id == 62 and progress < 7 then
                field:pc_lock(true);
                --field:menu_lock(true);                                  -- ???
                --SCR2DC (00,00,A0,FF,3C,00,20,00)                        -- ???
                script:request("cloud", "go_to_scene", 6);
                game:variable_set("progress_game", 7);
                script:request_end_wait("biggs", "talk1", 6);
                script:wait(0.2);
                script:request_end_wait("jessie", "talk1", 6);
                script:wait(0.34);
                script:request_end_wait("biggs", "talk2", 5);
                script:wait(0.27);
                script:request_end_wait("cloud", "talk2", 6);
                script:wait(0.27);
                script:request_end_wait("barret", "talk1", 6);
                script:wait(0.4);
                --SOUND (00,34,00,40)                                     -- ???
                script:wait(0.27);
                --SOUND (00,20,00,40)                                     -- ???
                script:request("door_left", "open", 6);
                script:request("door_right", "open", 6);
                script:wait(0.34);
                script:request("jessie", "run_next_field", 6);
                script:wait(1);
                script:request("biggs", "run_next_field", 6);
                script:wait(0.2);
                script:request("wedge", "run_next_field", 6);
                script:wait(0.5);
                script:request_end_wait("barret", "talk2", 6);
                --PMJMP (76,00)                                           -- ???
                script:request_end_wait("barret", "run_next_field", 6);
                script:wait(1);
                --PMVIE (14)                                              -- ???
                --MOVIE ()                                                -- ???
                --field:jump_to_map(118, 3549, 30574, 60, 180)
                field:pc_lock(false);
                --field:menu_lock(false);                                  -- ???

                break;
            end;

            script:wait(0);
        end;

        return 0;
    end;



};



entity["cloud"] = {
    on_start = function(self)
        cloud:set_speed(480);

        return 0;
    end;



    go_to_scene = function(self)
        cloud:move_to_position(1148, 1358, true);
        cloud:set_direction(174.375);

        return 0;
    end;



    talk1 = function(self)
        cloud:play_animation_wait("3", 0, 0.24, 1, true);
        message:show_text_wait(0, 10006, 100, 150);
        cloud:play_animation_wait("3", 0.27, 0.47, 1, true);

        return 0;
    end;



    talk2 = function(self)
        cloud:play_animation_wait("4", 0, -1, 1, false);
        script:request_end_wait("biggs", "talk3", 6);
        cloud:play_animation_wait("3", 0, 0.24, 1, true);
        message:show_text_wait(0, 10008, 30, 150);
        cloud:play_animation_wait("3", 0.24, 0.47, 1, true);

        return 0;
    end;



    talk3 = function(self)
        script:wait(0.34);
        cloud:play_animation_wait("3", 0.47, 0.74, 1, true);

        return 0;
    end;



    talk4 = function(self)
        cloud:play_animation_wait("3", 0.74, 0.97, 1, true);

        return 0;
    end;



    run_next_field = function(self)
        --ASPED (00,20,00)                                      -- ???
        script:wait(0.6);
        cloud:play_animation_wait("5", 0, -1, 1, true);
        cloud:set_animation_default("0", 1);
        cloud:set_speed(300);
        cloud:move_to_position(1286, 2922, true);

        return 0;
    end;
};



entity["barret"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress < 7 then
            barret:set_position_triangle(2264, 1236, 1298, 71);
            barret:set_visible(true);
        end;

        return 0;
    end;



    talk1 = function(self)
        barret:set_speed(300);
        script:request_end_wait("cloud", "talk3", 6);
        barret:move_to_position(1526, 1302, true);
        barret:set_direction(241.875);
        message:show_text_wait(3, 10009, 25, 140);
        message:show_text_wait(3, 10010, 8, 150);

        return 0;
    end;



    talk2 = function(self)
        barret:set_speed(300);
        script:request_end_wait("cloud", "talk4", 6);
        barret:move_to_position(1126, 1872, true);
        script:wait(1);
        barret:turn_to_direction(16.875, Entity.CLOSEST, Field.SMOOTH, 0.34);
        script:wait(0.67);
        message:show_text_wait(0, 10011, 30, 20);
        script:wait(0.27);
        --MENU(0,6,1)                                 -- ???
        script:wait(0.67);
        message:show_text_wait(0, 10012, 10, 137);

        return 0;
    end;



    run_next_field = function(self)
        barret:move_to_position(1355, 3376, true);
        barret:set_visible(false);

        return 0;
    end;
};



entity["biggs"] = {
    on_start = function(self)
        biggs:set_position_triangle(1002, 1556, 1298, 63);
        biggs:set_direction(174.375);

        local progress = game:variable_get("progress_game");
        if progress < 7 then
            biggs:set_solid(true);
            biggs:set_visible(true);
        end;

        return 0;
    end;



    talk1 = function(self)
        biggs:turn_to_direction(39.375, Entity.CLOSEST, Field.SMOOTH, 0.34);
        script:wait(0.04);
        biggs:play_animation_wait("3", 0, 0.3, 1, true);
        message:show_text_wait(1, 10001, 8, 8);
        biggs:play_animation_wait("3", 0.34, 0.64, 1, false);

        return 0;
    end;



    talk2 = function(self)
        message:show_text_wait(1, 10004, 30, 10);
        biggs:play_animation_wait("3", 0, 0.47, 1, true);
        message:show_text_wait(1, 10005, 50, 10);
        biggs:play_animation_wait("3", 0.34, 0.64, 1, false);
        script:wait(0.1);
        --MENU (00,06,00)                                         -- ???
        script:request_end_wait("cloud", "talk1", 6);
        script:wait(0.2);
        biggs:play_animation_wait("3", 0, 0.47, 1, true);
        message:show_text_wait(1, 10007, 50, 20);

        return 0;
    end;



    talk3 = function(self)
        biggs:play_animation_wait("3", 0.34, 0.64, 1, false);

        return 0;
    end;



    run_next_field = function(self)
        biggs:set_speed(300);
        biggs:move_to_position(1171, 1748, true);
        biggs:move_to_position(1355, 3376, true);
        biggs:set_solid(false);
        biggs:set_visible(false);

        return 0;
    end;
};



entity["jessie"] = {
    on_start = function(self)
        jessie:set_position_triangle(1157, 1619, 1298, 62);
        jessie:set_direction(174.375);
        jessie:set_animation_default("3", 1);

        local progress = game:variable_get("progress_game");
        if progress < 7 then
            jessie:set_solid(true);
            jessie:set_visible(true);
        end;

        return 0;
    end;



    talk1 = function(self)
        jessie:play_animation_wait("4", 0, -1, 1, true);
        message:show_text_wait(2, 10002, 155, 8);
        message:show_text_wait(2, 10003, 120, 8);
        script:wait(0.27);
        jessie:set_animation_default("3", 1);

        return 0;
    end;



    run_next_field = function(self)
        jessie:set_speed(300);
        jessie:play_animation_wait("5", 0, -1, 1, false);
        jessie:move_to_position(1355, 3376, true);
        jessie:set_solid(false);
        jessie:set_visible(false);

        return 0;
    end;
};



entity["wedge"] = {
    on_start = function(self)
        wedge:set_position_triangle(1521, 1504, 1298, 70);
        wedge:set_direction(16.875);
        wedge:set_animation_default("3", 1);

        local progress = game:variable_get("progress_game");
        if progress < 7 then
            wedge:set_solid(true);
            wedge:set_visible(true);
        end;

        return 0;
    end;



    run_next_field = function(self)
        wedge:set_speed(300);
        wedge:move_to_position(1171, 1748, true);
        wedge:move_to_position(1355, 3376, true);
        wedge:set_solid(false);
        wedge:set_visible(false);

        return 0;
    end;
};



entity["door_left"] = {
    on_start = function(self)
        door_left:set_position_triangle(1088, 1845, 1298, 61);
        door_left:set_direction(354.375);
        door_left:set_animation_default("0", 1);

        local progress = game:variable_get("progress_game");
        if progress < 7 then
            door_left:set_visible(true);
        end;

        return 0;
    end;



    open = function(self)
            door_left:offset_to_position(-202, 0, 0, Field.LINEAR, 1.67);
            door_left:set_offset_wait()
            door_left:set_visible(false);
        return 0;
    end;
};



entity["door_right"] = {
    on_start = function(self)
        door_right:set_position_triangle(1263, 1824, 1298, 60);
        door_right:set_direction(174.375);
        door_right:set_animation_default("0", 1);

        local progress = game:variable_get("progress_game");
        if progress < 7 then
            door_right:set_visible(true);
        end;

        return 0;
    end;



    open = function(self)
            door_right:offset_to_position(184, 0, 0, Field.LINEAR, 1.67);
            door_right:set_offset_wait()
            door_right:set_visible(false);
        return 0;
    end;
};



entity["movie"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");
        if progress < 7 then
            local current_frame = 0;

            while current_frame <= 30 do
                --current_frame = MVIEF(6,9)                          -- ???
                script:wait(0);
            end;

            script:request_end_wait("cloud", "run_next_field", 6);
        end;

        return 0;
    end;
};



entity["gateway_to_md1stin"] = {
    on_start = function(self)
        return 0;
    end;

    on_talk = function(self)
        return 0;
    end;

    on_enter_line = function(self)
        return 0;
    end;

    on_leave_line = function(self)
        return 0;
    end;

    on_cross_line = function(self)
        field:pc_lock(true);
        field:jump_to_map(116, 3719, 29342, 35, 67.5);

        return 0;
    end;

    on_move_to_line = function(self)
        return 0;
    end;

    on_activate_line = function(self)
        return 0;
    end;
};



entity["gateway_to_md1_2"] = {
    on_start = function(self)
        return 0;
    end;

    on_talk = function(self)
        return 0;
    end;

    on_enter_line = function(self)
        return 0;
    end;

    on_leave_line = function(self)
        return 0;
    end;

    on_cross_line = function(self)
        field:pc_lock(true);
        field:jump_to_map(118, 3560, 30579, 58, 185.63);

        return 0;
    end;

    on_move_to_line = function(self)
        return 0;
    end;

    on_activate_line = function(self)
        return 0;
    end;
};
