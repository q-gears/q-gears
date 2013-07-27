FFVII.Characters = {}



FFVII.Characters.Cloud = {
    -- field related
    enable = false,
    party_lock = false,



    -- battle related
    unit_type = FFVII.Battle.Type.ALLY,

    max_hp = 318,
    current_hp = 318,
    max_mp = 57,
    current_mp = 57,
    level = 7,
    -- primary stats
    strength = 19,
    vitality = 18,
    magic = 25,
    spirit = 18,
    dexterity = 9,
    luck = 16,
    -- derived stats
    physical_power = 37, -- attack
    physical_defense = 18, -- vitality
    physical_dodge = 0,
    magic_power = 25, -- magic
    magic_defense = 0, -- spirit
    speed = 9, -- calculated from dexterity
    luck = 4, -- luck

    row = FFVII.Battle.Row.FRONT,

    battle_speed = 0,
    timer = 0,



    on_start = function(self)
        while true do
            local dir = self.entity:get_rotation()
            dir = dir + 1
            self.entity:set_rotation( dir )
            script:wait( 0 )
        end

        return 0;
    end;
}
