first = 0;

test_pyramid = {
    attack = 0;

    on_start = function(self)
        if first == 0 then
            self.attack = 1;
            first = 1;
        end;

        return 0;
    end;

    on_action = function(self)
        if self.attack == 1 then
            fighter_self.data.current_hp = fighter_self.data.current_hp - 1;
        end

        return 0;
    end;
};
