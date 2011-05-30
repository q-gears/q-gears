entity = {
};

cloud = field:load_model("cloud", 5800);
field:set_entity_to_character(cloud, 0);
barret = field:load_model("barret", 5801);
field:set_entity_to_character(barret, 1);
soldier0 = field:load_model("soldier0", 5802);
soldier1 = field:load_model("soldier1", 5802);
biggs = field:load_model("biggs", 5803);
jessie = field:load_model("jessie", 5804);
wedge = field:load_model("wedge", 5805);
guard0 = field:load_model("guard0", 5806);
guard1 = field:load_model("guard1", 5806);
guard_add = field:load_model("guard_add", 5806);



entity["director"] = {
    on_start = function(self)
        -- main init
        --field:screen_set_scroll(0, 40);                         -- ???

        local progress = game:variable_get("progress_game");

        if progress == 0 then
            --fade:black();
            --field:screen_set_scroll(0, 0);                      -- ???
            --AKAO(0,0,0,F0,0,0,0,0,0,0,0,0,0)                    -- ???
            field:random_encounter_on(false);
        end;

        --BTLMD(20,0)                                             -- ???

        if progress > 0 then
            --MUSIC(0)                                            -- ???
        end;

        --FMUSC(0)                                                -- ???
        --field:map_name(2000);                                   -- ???

        -- main action
        if progress == 0 then
            --AKAO2(0,0,0,C8,0,70,0,0,0,0,0,0,0,0)                -- ???
            script:request("movie", "movie_check", 6);

            --field:play_movie(53);                               -- ???
            --AKAO2(0,0,0,C8,FF,7F,0,0,0,0,0,0,0,0)               -- ???

            -- enable all menu exept materia and phs
            --game:variable_set("2_28", 763);

            -- set size of game party and remove everyone from party
            game:party_set_size(3);
            game:party_clear();
            game:character_add_to_party(0);
            --game_state:lock_member(0);                          -- ???

            game:variable_set("love_point_aeris", 50);
            game:variable_set("love_point_tifa", 30);
            game:variable_set("love_point_yuffie", 10);
            game:variable_set("love_point_barret", 0);

            -- unknown purpose data
            game:variable_set("1_80", 100);
            game:variable_set("1_81", 100);
            game:variable_set("1_82", 100);
            game:variable_set("1_83", 100);

            --SOUND(0,35,0,40)                                    -- ???
            script:wait(1);
            script:request("biggs", "from_train", 2);
            script:wait(1.1);
            script:request("guard1", "guard", 2);
            script:wait(1);
            script:request("guard0", "guard", 2);
            script:wait(2);
            --SOUND(0,39,0,40)                                    -- ???
            script:request("jessie", "from_train", 2);
            script:wait(2.34);
            script:request("wedge", "from_train", 2);
            script:wait(2.34);
            script:request("barret", "from_train", 2);
            script:wait(2.67);
            --SCR2DC(0,0,EC,FF,82,0,C,0)                          -- ???
            script:wait(0.5);
            script:request("cloud", "from_train", 2);
            script:wait(0.07);
            --SOUND(0,37,0,40)                                    -- ???
            script:wait(0.74);
            --SCR2DC(0,0,A,0,23,0,F,0)                            -- ???
            script:wait(0.74);
            --SOUND(0,38,0,40)                                    -- ???
            script:wait(1.94);

            message:show_text_wait(3, 10000, 40, 20);

            script:request("barret", "run_next_field", 2);
            script:wait(0.67);

            game:variable_set("progress_game", 1);

            field:pc_lock(false);
            --field:menu_lock(false);                             -- ???

            field:set_player_entity(cloud);

            while true do
                local triangle_id = cloud:get_triangle();

                if triangle_id == 12 then
                    game:variable_set("progress_game", 6);

                    field:pc_lock(true);
                    --field:menu_lock(true);            -- ???

                    script:request("soldier0", "battle_start", 2);
                    script:request_end_wait("soldier1", "battle_start", 2);
                    field:battle_run(300);
                    field:random_encounter_on(true); -- ???
                    field:pc_lock(false);
                    --field:menu_lock(false);             -- ???

                    break;
                end;

                script:wait(0);
            end;
        end;

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");

        if progress == 0 then
            cloud:set_talkable(false);
            cloud:set_solid(false);
            cloud:set_visible(false);

            field:pc_lock(true);
            --field:menu_lock(true);                --???

            cloud:set_position_triangle(3655, 27432, 310, 25);
            cloud:set_direction(180);
        end;

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    from_train = function(self)
        cloud:set_talkable(true);
        cloud:set_solid(true);
        cloud:set_visible(true);
        cloud:play_animation_wait("3", 0, -1, 1, false);

        return 0;
    end;
};



entity["barret"] = {
    on_start = function(self)
        local progress = game:variable_get("progress_game");

        if progress <= 1 then
            barret:set_position_triangle(3921, 27489, 323, 30);
        end;

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    from_train = function(self)
        barret:set_talkable(true);
        barret:set_solid(true);
        barret:set_visible(true);
        barret:set_speed(360);
        barret:move_to_position(3607, 27712, true);
        barret:set_direction(164.5);
        barret:play_animation_wait("3", 0, 1.3, 1, true);
        script:wait(1.34);
        barret:play_animation_wait("3", 1.3, -1, 1, true);

        return 0;
    end;



    run_next_field = function(self)
        barret:move_to_position(3836, 29295, true);
        barret:move_to_position(3578, 29360, true);
        barret:set_talkable(false);
        barret:set_solid(false);
        barret:set_visible(false);

        return 0;
    end;
};



entity["movie"] = {
    on_start = function(self)
        return 0
    end;



    movie_check = function(self)

        local current_frame = 0;

        while current_frame <= 20 do
            --current_frame = MVIEF(6,6)                          -- ???
            script:wait(0);
        end;

        fade:clear();

        while current_frame <= 664 do
            --current_frame = MVIEF(6,6)                          -- ???
            script:wait(0);
        end;

        --MUSIC(1)                                                -- ???
        --MULCK(1)                                                -- ???
        --AKAO2(0,0,0,C9,3C,0,FF,7F,0,0,0,0,0,0)                  -- ???

        return 0;
    end;
};



entity["soldier0"] = {
    on_start = function(self)
        soldier0:set_position_triangle(3634, 29284, 367, 36);
        soldier0:set_talkable(false);
        soldier0:set_solid(false);
        soldier0:set_visible(false);

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    battle_start = function(self)
        soldier0:set_visible(true);
        soldier0:set_speed(285);
        soldier0:move_to_position(3794, 29268, true);
        soldier0:move_to_position(3732, 28752, true);
        soldier0:set_talkable(false);
        soldier0:set_solid(false);
        soldier0:set_visible(false);

        return 0;
    end;
};



entity["soldier1"] = {
    on_start = function(self)
        soldier1:set_position_triangle(3634, 29284, 367, 36);
        soldier1:set_talkable(false);
        soldier1:set_solid(false);
        soldier1:set_visible(false);

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    battle_start = function(self)
        soldier1:set_visible(true);
        soldier1:set_speed(300);
        soldier1:move_to_position(3897, 29257, true);
        soldier1:move_to_position(3873, 28840, true);
        soldier1:set_talkable(false);
        soldier1:set_solid(false);
        soldier1:set_visible(false);

        return 0;
    end;
};



entity["biggs"] = {
    on_start = function(self)
        biggs:set_position_triangle(3840, 29184, 314, 3);
        biggs:set_direction(270);
        biggs:set_talkable(false);
        biggs:set_solid(false);
        biggs:set_visible(false);

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    from_train = function(self)
        biggs:set_visible(true);
        biggs:play_animation_wait("3", 0, -1, 1, false);
        script:wait(0.27);
        biggs:turn_to_direction(326.25, Entity.CLOSEST, Field.SMOOTH, 0.34);
        script:wait(0.34);
        biggs:play_animation_wait("4", 0, -1, 1, false);
        biggs:set_direction(146.25);
        script:wait(3.34);
        biggs:set_speed(300);
        biggs:move_to_position(3836, 29295, true);
        biggs:move_to_position(3578, 29360, true);
        biggs:set_talkable(false);
        biggs:set_solid(false);
        biggs:set_visible(false);

        return 0;
    end;
};



entity["jessie"] = {
    on_start = function(self)
        jessie:set_position_triangle(3986, 28214, 321, 34);
        jessie:set_talkable(false);
        jessie:set_solid(false);
        jessie:set_visible(false);

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    from_train = function(self)
        jessie:set_visible(true);
        jessie:set_speed(240);
        jessie:move_to_position(3672, 28221, true);
        jessie:set_direction(16.875);
        jessie:play_animation_wait("3", 0, 0.47, 1, true);
        script:wait(0.24);
        --SOUND(0,1C,0,40)                                    -- ???
        script:wait(0.77);
        jessie:play_animation_wait("3", 0.5, 0.8, 1, false);
        jessie:set_animation_default("0", 1);
        script:wait(1.34);
        jessie:move_to_position(3836, 29295, true);
        jessie:move_to_position(3578, 29360, true);
        jessie:set_talkable(false);
        jessie:set_solid(false);
        jessie:set_visible(false);

        return 0;
    end;
};



entity["wedge"] = {
    on_start = function(self)
        wedge:set_position_triangle(3794, 28317, 310, 14);
        wedge:set_direction(270);
        wedge:set_talkable(false);
        wedge:set_solid(false);
        wedge:set_visible(false);

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    from_train = function(self)
        wedge:set_visible(true);
        wedge:play_animation_wait("3", 0, -1, 1, false);
        script:wait(0.27);
        wedge:turn_to_direction(326.25, Entity.CLOSEST, Field.SMOOTH, 0.34)
        script:wait(2);
        wedge:set_speed(300);
        wedge:move_to_position(3836, 29295, true);
        wedge:move_to_position(3578, 29360, true);
        wedge:set_talkable(false);
        wedge:set_solid(false);
        wedge:set_visible(false);

        return 0;
    end;
};



entity["guard0"] = {
    on_start = function(self)
        guard0:set_position_triangle(3596, 27777, 310, 20);
        guard0:set_direction(90);
        guard0:set_visible(true);
        guard0:set_talkable(true);
        guard0:set_solid(true);

        local progress = game:variable_get("progress_game");
        if progress >= 1 then
            guard0:set_direction(191.25);
            guard0:set_position_triangle(3767, 27722, 310, 20);
            guard0:set_animation_default("3", 1);
        end;

        return 0;
    end;



    on_talk = function(self)
        field:pc_lock(true);
        --field:menu_lock(true);            -- ???

        local item_mask = game:variable_get("item_mask1");
        if bit.band(item_mask, hex.to_dec('0x0001')) == 0 then
            --SOUND(0,68,1,40)                -- ???
            message:show_text_wait(0, 5000, 83, 10);
            game:variable_set("item_mask1", bit.bor(item_mask, hex.to_dec('0x0001')));
            game:item_add(0, 1);
        elseif bit.band(item_mask, hex.to_dec('0x0002')) == 0 then
            --SOUND(0,68,1,40)                -- ???
            message:show_text_wait(0, 5000, 83, 10);
            game:variable_set("item_mask1", bit.bor(item_mask, hex.to_dec('0x0002')));
            game:item_add(0, 1);
        end;

        field:pc_lock(false);
        --field:menu_lock(false);             -- ???

        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    guard = function(self)
        guard0:set_solid(false);
        guard0:turn_to_direction(135, Entity.CLOSEST, Field.SMOOTH, 0.34);
        script:wait(1.07);
        guard0:play_animation_wait("4", 0, -1, 1, false);
        guard0:set_speed(240);
        script:wait(0.27);
        guard0:move_to_position(3704, 28044, true);
        guard0:set_direction(191.25);
        guard0:play_animation_wait("5", 0, -1, 1, true);
        script:request_end_wait("guard1", "activate", 6);
        guard0:set_talkable(false);
        guard0:set_solid(false);
        guard0:set_visible(false);

        return 0;
    end;
};



entity["guard1"] = {
    on_start = function(self)
        guard1:set_position_triangle(3696, 28733, 310, 9);
        guard1:set_direction(90);
        guard1:set_visible(true);
        guard0:set_talkable(true);
        guard0:set_solid(true);

        local progress = game:variable_get("progress_game");
        if progress >= 1 then
            guard1:set_direction(56.25);
            guard1:set_position_triangle(3920, 29160, 311, 3);
            guard1:set_animation_default("6", 1);
        end;

        return 0;
    end;



    on_talk = function(self)
        field:pc_lock(true);
        --field:menu_lock(true);            -- ???

        local item_mask = game:variable_get("item_mask1");
        if bit.band(item_mask, hex.to_dec('0x0001')) == 0 then
            --SOUND(0,68,1,40)                -- ???
            message:show_text_wait(0, 5000, 83, 10);
            game:variable_set("item_mask1", bit.bor(item_mask, hex.to_dec('0x0001')));
            game:item_add(0, 1);
        elseif bit.band(item_mask, hex.to_dec('0x0002')) == 0 then
            --SOUND(0,68,1,40)                -- ???
            message:show_text_wait(0, 5000, 83, 10);
            game:variable_set("item_mask1", bit.bor(item_mask, hex.to_dec('0x0002')));
            game:item_add(0, 1);
        end;

        field:pc_lock(false);
        --field:menu_lock(false);             -- ???

        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    guard = function(self)
        guard1:set_solid(true);
        guard1:play_animation_wait("4", 0, -1, 1, false);
        guard1:set_speed(480);
        guard1:move_to_position(3792, 29232, true);
        guard1:set_direction(56.25);
        guard1:play_animation_wait("7", 0, -1, 1, true);
        script:request("guard_add", "activate", 6);
        guard1:set_talkable(false);
        guard1:set_solid(false);
        guard1:set_visible(false);

        return 0;
    end;



    activate = function(self)
        guard1:set_animation_default("3", 1);
        guard1:set_position_triangle(3767, 27722, 310, 14);
        guard1:set_direction(191.25);
        guard1:set_talkable(true);
        guard1:set_solid(true);
        guard1:set_visible(true);

        return 0;
    end;
};



entity["guard_add"] = {
    on_start = function(self)
        guard_add:set_direction(56.25);
        guard_add:set_position_triangle(3920, 29160, 311, 3);
        guard_add:set_animation_default("6", 1);
        guard_add:set_talkable(false);
        guard_add:set_solid(false);
        guard_add:set_visible(false);

        return 0;
    end;



    on_talk = function(self)
        field:pc_lock(true);
        --field:menu_lock(true);            -- ???

        local item_mask = game:variable_get("item_mask1");
        if bit.band(item_mask, hex.to_dec('0x0001')) == 0 then
            --SOUND(0,68,1,40)                -- ???
            message:show_text_wait(0, 5000, 83, 10);
            game:variable_set("item_mask1", bit.bor(item_mask, hex.to_dec('0x0001')));
            game:item_add(0, 1);
        elseif bit.band(item_mask, hex.to_dec('0x0002')) == 0 then
            --SOUND(0,68,1,40)                -- ???
            message:show_text_wait(0, 5000, 83, 10);
            game:variable_set("item_mask1", bit.bor(item_mask, hex.to_dec('0x0002')));
            game:item_add(0, 1);
        end;

        field:pc_lock(false);
        --field:menu_lock(false);             -- ???

        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    activate = function(self)
        guard_add:set_talkable(true);
        guard_add:set_solid(true);
        guard_add:set_visible(true);

        return 0;
    end;
};



entity["gateway_to_md1_1"] = {
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
        field:jump_to_map(117, 1049, 400, 90, 81.56);

        return 0;
    end;

    on_move_to_line = function(self)
        return 0;
    end;

    on_activate_line = function(self)
        return 0;
    end;
};
