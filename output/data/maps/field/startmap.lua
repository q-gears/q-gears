entity = {
};

game:character_add_to_party(0);

cloud = field:load_model("cloud", 3200);
field:set_entity_to_character(cloud, 0);
yuffie = field:load_model("yuffie", 3201);



entity["cloud"] = {
    on_start = function(self)
        cloud:set_position_triangle(0, 0, 0, 1);

        return 0;
    end;



    on_talk = function(self)
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;
};



entity["yuffie"] = {
    on_start = function(self)
        yuffie:set_position_triangle(-74, -130, 0, 100);
        yuffie:set_direction(135);
        yuffie:set_solid_range(10);
        yuffie:set_talkable(true);
        yuffie:set_solid(true);
        yuffie:set_visible(true);

        return 0;
    end;



    on_talk = function(self)
        self:message1();
        return 0;
    end;



    on_collide = function(self)
        return 0;
    end;



    message1 = function(self)
        message:set_cursor(1, 0, 9);
        message:show_text_wait(1, 100, 0, 0);
        local cursor = message:get_cursor(1);

        if cursor == 0 then
            return self:message2(self);
        elseif cursor == 1 then
            --SETWORD(20,1E,0,0) // set active all menu
        elseif cursor == 2 then
            --Special(BattleLock,1)
        elseif cursor == 3 then
            --Special(BattleLock,0)
        elseif cursor == 4 then
            --Special(MovieLock,1)
        elseif cursor == 5 then
            --Special(MovieLock,0)
        elseif cursor == 6 then
            --Special(ResetAllStates)
        elseif cursor == 7 then
            --Special(DefaultName,0,2)
            --Special(DefaultName,1,3)
            --Special(DefaultName,2,4)
            --Special(DefaultName,3,5)
            --Special(DefaultName,5,6)
            --Special(DefaultName,6,7)
            --Special(DefaultName,8,8)
            --Special(DefaultName,4,A)
            --Special(DefaultName,7,9)
        elseif cursor == 8 then
            field:jump_to_map(116, 0, 0, 0, 0);
        end;

        return 0;
    end;



    message2 = function(self)
        message:set_cursor(1, 0, 4);
        message:show_text_wait(1, 101, 0, 0);
        local cursor = message:get_cursor(1);

        if cursor == 0 then
            return self:message1(self);
        elseif cursor == 1 then
            --AKAO(0,0,0,C0,7F,0,0,0,0,0,0,0,0)
            --AKAO(0,0,0,A0,7F,0,0,0,0,0,0,0,0)
            --AKAO(0,0,0,A1,7F,0,0,0,0,0,0,0,0)
            --AKAO(0,0,0,A2,7F,0,0,0,0,0,0,0,0)
            --AKAO(0,0,0,A3,7F,0,0,0,0,0,0,0,0)
            --AKAO2(0,0,0,C8,FF,7F,0,0,0,0,0,0,0,0)
            --AKAO2(0,0,0,E4,0,0,0,0,0,0,0,0,0,0)
            --AKAO2(0,0,0,B0,0,0,0,0,0,0,0,0,0,0)
            --AKAO2(0,0,0,B1,0,0,0,0,0,0,0,0,0,0)
            --AKAO2(0,0,0,B2,0,0,0,0,0,0,0,0,0,0)
            --AKAO2(0,0,0,B3,0,0,0,0,0,0,0,0,0,0)
            --MUSIC(0)
            --AKAO(0,0,0,28,3F,0,0,0,0,0,0,0,0)
            --AKAO(0,0,0,29,3F,0,0,0,0,0,0,0,0)
            --AKAO(0,0,0,2A,3F,0,0,0,0,0,0,0,0)
            --AKAO(0,0,0,2B,3F,0,0,0,0,0,0,0,0)
        elseif cursor == 2 then
            --Special(AddAllMateria)
            --Special(AddAllMateria)
            --Special(AddAllMateria)
        elseif cursor == 3 then
            --BATTLE(0,E7,3)
            --MHMMX
        end;

        return 0;
    end;
};
