-- Mono Drive (18)
Mono Drive = {
    max_hp = 28,
    max_mp = 28,

    level = 2,
    physical_power = 3,
    physical_defense = 3,
    physical_dodge = 6,
    magic_power = 3,
    magic_defense = 2,
    speed = 49,
    luck = 2,

    back_damage_multiplier = 2,

    morph_item = Ether,

    reward_exp = 18,
    reward_ap = 3,
    reward_gil = 8,

    reward_items_drop = {
        Potion = 8,
        Ether = 2,
    },

    elements = {
        Earth = "Nullify",
        Wind = "DoubleDamage",
    },

    status_immunes = {
        Stop,
        Frog,
        Paralysis,
    },

    attacks = {
        Drilldrive = {
            script_id = 3,
        },
        Fire = {
            script_id = 4,
            camera_movement = 261,
        }
    },

    items_steal = {},

    berserk_attack = Drilldrive,

    manipulate_attacks = {
        Drilldrive,
        Fire,
    },
},


-- Grunt (19)
Grunt = {
    max_hp = 40,
    max_mp = 0,

    level = 7,
    physical_power = 12,
    physical_defense = 5,
    physical_dodge = 4,
    magic_power = 2,
    magic_defense = 1,
    speed = 58,
    luck = 8,

    back_damage_multiplier = 2,

    morph_item = Potion,

    reward_exp = 22,
    reward_ap = 2,
    reward_gil = 15,

    reward_items_drop = {
        Potion = 8,
        Potion = 8,
    },

    elements = {},

    status_immunes = {},

    attacks = {
        UnknownAttackId0x0115 = {
            script_id = 3,
        },
        UnknownAttackId0x0116 = {
            script_id = 4,
            camera_movement = 210,
        }
    },

    items_steal = {
        Grenade = 8,
    },

    berserk_attack = UnknownAttackId0x0115,

    manipulate_attacks = {
        UnknownAttackId0x0115,
        UnknownAttackId0x0116,
    },
},


-- 1st Ray (20)
1st Ray = {
    max_hp = 18,
    max_mp = 0,

    level = 4,
    physical_power = 10,
    physical_defense = 1,
    physical_dodge = 0,
    magic_power = 0,
    magic_defense = 0,
    speed = 40,
    luck = 0,

    back_damage_multiplier = 2,

    morph_item = Potion,

    reward_exp = 12,
    reward_ap = 1,
    reward_gil = 5,

    reward_items_drop = {},

    elements = {
        UnknownElement0x0002 = "DoubleDamage",
    },

    status_immunes = {
        UnknownStatusId0x0002,
        UnknownStatusId0x0003,
        UnknownStatusId0x0004,
        UnknownStatusId0x0005,
        Frog,
        UnknownStatusId0x000c,
        UnknownStatusId0x0015,
        Paralysis,
        UnknownStatusId0x001a,
    },

    attacks = {
        UnknownAttackId0x0117 = {
            script_id = 3,
            camera_movement = 240,
        }
    },

    items_steal = {},

    berserk_attack = UnknownAttackId0x0117,

    manipulate_attacks = {
        UnknownAttackId0x0117,
    },
},


