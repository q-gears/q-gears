entity = {
};



entity["director"] = {
    on_start = function(self)
        BMUSC (00)
        MUSIC (01)

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        SOLID (01)

        return 0;
    end;
};



entity["people1"] = {
    on_start = function(self)
        CHAR (03)
        XYZI (00,00,C6,F1,F0,45,8D,01,80,00)

        return 0;
    end;

    on_talk = function(self)
        UC (01)
        MENU2 (01)
        CANM!2 (03,00,0E,01)
        MESSAGE (00,02)
        CANM!2 (03,0E,1D,01)
        UC (00)
        MENU2 (00)

        return 0;
    end;
};



entity["people2"] = {
    on_start = function(self)
        CHAR (04)
        XYZI (00,00,0D,F0,FA,4B,5F,01,59,00)

        while true do
            MOVE (00,16,EF,82,49)
            MOVE (00,FB,EF,75,47)
            MOVE (00,3B,F1,BF,46)
            MOVE (00,87,F1,98,47)
            MOVE (00,68,F0,C6,48)
            MOVE (00,D0,EF,78,49)
            MOVE (00,0D,F0,FA,4B)
        end;

        return 0;
    end;

    on_talk = function(self)
        UC (01)
        MENU2 (01)
        MESSAGE (00,00)
        UC (00)
        MENU2 (00)

        return 0;
    end;
};



entity["people3"] = {
    on_start = function(self)
        XYZI (00,00,37,EE,35,4B,78,01,5F,00)
        SLIDR (00,01)
        SOLID (01)
        TLKON (01)
        SOLID (01)
        VISI (00)

        IFUBL (30,42,01,0A,24,00)
            TLKON (00)
            SOLID (00)
            VISI (01)
            MSPED (00,00,0A)
            MOVE (00,83,EF,69,4B)
            MOVE (00,65,F0,05,4C)
            MOVE (00,35,F4,ED,4B)
            TLKON (01)
            SOLID (01)
            VISI (00)

        return 0;
    end;
};



entity["people4"] = {
    on_start = function(self)
        CHAR (06)
        XYZI (00,00,37,EE,35,4B,78,01,5F,00)
        SLIDR (00,01)
        SOLID (01)

        IFUB (30,42,01,0A,37)
            TLKON (00)
            SOLID (00)
            VISI (01)
            MSPED (00,00,0A)
            MOVE (00,72,F0,81,48)
            MOVE (00,89,F1,78,47)
            MOVE (00,3D,F1,9E,46)
            MOVE (00,98,F0,B8,45)
            MOVE (00,48,F0,C2,43)
            TLKON (01)
            SOLID (01)
            VISI (00)
            BITON (30,42,01)


        while true do
            RANDOM (05,00)
            if temp0 > 0xF0 then
                RANDOM (05,00)
                AND (50,00,03)

                if temp0 == 0 then
                    XYZI (00,00,37,EE,35,4B,78,01,5F,00)
                    TLKON (00)
                    SOLID (00)
                    VISI (01)
                    MSPED (00,00,0A)
                    MOVE (00,72,F0,81,48)
                    MOVE (00,89,F1,78,47)
                    MOVE (00,3D,F1,9E,46)
                    MOVE (00,98,F0,B8,45)
                    MOVE (00,48,F0,C2,43)
                    TLKON (01)
                    SOLID (01)
                    VISI (00)
                elseif temp0 == 1 then
                    XYZI (00,00,48,F0,C2,43,8D,01,8C,00)
                    TLKON (00)
                    SOLID (00)
                    VISI (01)
                    MSPED (00,00,0A)
                    MOVE (00,98,F0,B8,45)
                    MOVE (00,3D,F1,9E,46)
                    MOVE (00,89,F1,78,47)
                    MOVE (00,72,F0,81,48)
                    MOVE (00,37,EE,35,4B)
                    TLKON (01)
                    SOLID (01)
                    VISI (00)
                end;
            else
                WAIT (5A,00)
            end;
        end;

        return 0;
    end;
};



entity["people5"] = {
    on_start = function(self)
        CHAR (07)
        XYZI (00,00,CF,F3,31,4B,81,01,91,00)
        SLIDR (00,01)
        SOLID (01)

        IFUBL (30,42,01,0A,1E,00)
            TLKON (00)
            SOLID (00)
            VISI (01)
            MSPED (00,00,0A)
            MOVE (00,F7,F1,A8,4C)
            MOVE (00,F7,F1,97,4E)
            TLKON (01)
            SOLID (01)
            VISI (00)

        return 0;
    end;
};



entity["people6"] = {
    on_start = function(self)
        CHAR (08)
        XYZI (00,00,CF,F3,31,4B,81,01,91,00)
        SLIDR (00,01)
        SOLID (01)

        IFUB (30,42,01,0A,23)
            TLKON (00)
            SOLID (00)
            VISI (01)
            MSPED (00,00,0A)
            MOVE (00,10,F2,E4,4B)
            MOVE (00,12,F2,83,4A)
            MOVE (00,85,F3,52,49)
            TLKON (01)
            SOLID (01)
            VISI (00)

        return 0;
    end;
};



entity["people7"] = {
    on_start = function(self)
        CHAR (09)
        XYZI (00,00,37,EE,35,4B,78,01,5F,00)
        SLIDR (00,01)
        SOLID (01)

        return 0;
    end;
};



entity["potion"] = {
    on_start = function(self)
        CHAR (0A)
        XYZI (00,00,A8,EF,44,46,78,01,6E,00)

        local item_mask = game:variable_get("item_mask2");
        if bit.band(item_mask, hex.to_dec('0x01')) == 0 then
            TLKON (01)
            SOLID (01)
            VISI (00)
        end;

        KAWAI (0D,00,00)
        WAIT (01,00)
        KAWAI (0D,01)

        return 0;
    end;

    on_talk = function(self)
        UC (01)
        MENU2 (01)
        AKAO (00,00,00,2A,3F,68,01,00,00,00,00,00,00)
        WINDOW (01,53,00,78,00,8A,00,19,00)
        MESSAGE (01,03)

        local item_mask = game:variable_get("item_mask2");
        game:variable_set("item_mask2", bit.bor(item_mask, hex.to_dec('0x01')));
        game:item_add(0, 1);

        TLKON (01)
        SOLID (01)
        VISI (00)
        UC (00)
        MENU2 (00)

        return 0;
    end;
};
