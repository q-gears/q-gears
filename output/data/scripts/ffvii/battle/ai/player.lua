cloud = {
    on_start = function(self)
        return 0;
    end;

    on_action = function(self)
        return 0;
    end;

    script4 = function(self)
        temp0 = "";
        -- self_id used mask 0x2060 probably attacked unit in this case
        if bu[800f83e0 + self_id * 0x68 + 0x17] == 0x13 then
            temp0 = "1_80";
        else if bu[800f83e0 + self_id * 0x68 + 0x17] == 0x12 then
            temp0 = "1_81";
        else if bu[800f83e0 + self_id * 0x68 + 0x17] == 0x15 then
            temp0 = "1_82";
        else if bu[800f83e0 + self_id * 0x68 + 0x17] == 0x11 then
            temp0 = "1_83";
        end;

        if temp0 ~= "" then
            byte_to_change_old = game:variable_get(temp0);

            byte_to_change = byte_to_change_old + 3;

            if byte_to_change > 200 then
                byte_to_change = 200;
            end;

            game:variable_set(temp0, byte_to_change);

            printf("LOVEPARA CHR:%d, %d->%d", bu[800f83e0 + self_id * 0x68 + 0x17] - 16, byte_to_change_old, byte_to_change);
        end;

        return 0;
    end;

    script6 = function(self)
        for unit_id = 0, 2, 1 do
            if unit_dead(unit_id) == true then
                temp0 = "";
                if bu[800f83e0 + unit_id * 0x68 + 0xc] == 0x13 then
                    temp0 = "1_80";
                else if bu[800f83e0 + unit_id * 0x68 + 0xc] == 0x12 then
                    temp0 = "1_81";
                else if bu[800f83e0 + unit_id * 0x68 + 0xc] == 0x15 then
                    temp0 = "1_82";
                else if bu[800f83e0 + unit_id * 0x68 + 0xc] == 0x11 then
                    temp0 = "1_83";
                end;

                if temp0 ~= "" then
                    byte_to_change_old = game:variable_get(temp0);

                    byte_to_change = byte_to_change_old - 5;

                    if byte_to_change < 50 then
                        byte_to_change = 50;
                    end;

                    game:variable_set(temp0, byte_to_change);

                    printf("LOVEPARA CHR:%d, %d->%d", bu[800f83e0 + unit_id * 0x68 + 0x17] - 16, byte_to_change_old, byte_to_change);
                end;
            end;
        end;
    end;
};



sephiroth = {
    on_start = function(self)
        activate folowing bits
        800f83e0 + 4
        activate on_action script
        0x00000100;
        0x00000200;
        0x00000400;
        return 0;
    end;

    on_action = function(self)
        temp0 = 2;
        search_for_units_that_strong_to_earth_and_store_them_to_target_mask;

        if bu[0x800f83e0 + attacked_units * 0x68 + 0xb] >= 0x5 then
            printf("RESIST EARTH MONSTER");
            temp8 = 1;
        end;

        if young_cloud_is_dead == true then
            attack_mask = young_cloud_mask;
            temp4 = 8; -- life2
        else
            if there_only_one_opponent == true then
                SetRandomOpponentToAttack();
                if bu[0x800f83e0 + attacked_units * 0x68 + 0x4e] >= 0x10 then
                    temp4 = 0x1d; -- fire3
                else
                    temp0 = 1;
                end;
            else
                store_all_oponents_as_targets;

                rand = math.random(3) + temp8;
                if rand == 1 then
                    temp4 = 0x26; -- quake3
                    temp8 = 1;
                else if rand == 2 then
                    temp4 = 0x20; -- ice3
                else
                    temp4 = 0x23; -- bolt3
                end;
            end
        end;

        battle:run_command(temp0, temp4); -- type, attack_id

        return 0;
    end;
};
