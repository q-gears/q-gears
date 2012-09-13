-- Guard Hound (17)
Guard Hound = {
    max_hp = 42,
    max_mp = 0,

    level = 3,
    physical_power = 8,
    physical_defense = 2,
    physical_dodge = 6,
    magic_power = 2,
    magic_defense = 1,
    speed = 64,
    luck = 6,

    back_damage_multiplier = 2,

    morph_item = Potion,

    reward_exp = 20,
    reward_ap = 2,
    reward_gil = 12,

    reward_items_drop = {
        Potion = 8,
    },

    elements = {},

    status_immunes = {},

    attacks = {
        Bite = {
            script_id = 3,
        },
        Tentacle = {
            script_id = 4,
        }
    },

    items_steal = {
        Potion = 32,
    },

    berserk_attack = Bite,

    manipulate_attacks = {
        Bite,
        Tentacle,
    },
},


-- Guard Scorpion(22)
Guard Scorpion= {
    max_hp = 800,
    max_mp = 0,

    level = 12,
    physical_power = 30,
    physical_defense = 20,
    physical_dodge = 0,
    magic_power = 15,
    magic_defense = 150,
    speed = 60,
    luck = 1,

    back_damage_multiplier = 2,

    morph_item = UnknownItemId0xffff,

    reward_exp = 100,
    reward_ap = 10,
    reward_gil = 100,

    reward_items_drop = {
        UnknownItemId0x00a1 = 63,
    },

    elements = {
        Lighting = "DoubleDamage",
        Gravity = "Nullify",
    },

    status_immunes = {
        Death,
        Sleep,
        Poison,
        Sadness,
        Fury,
        Confusion,
        Silence,
        Frog,
        Small,
        UnknownStatusId0x000d,
        UnknownStatusId0x000e,
        DeathSentence,
        UnknownStatusId0x0016,
        UnknownStatusId0x0017,
        Paralysis,
        Darkness,
    },

    attacks = {
        Rifle = {
            script_id = 3,
        },
        ScorpionTail = {
            script_id = 4,
        },
        SearchScope = {
            script_id = 5,
        },
        Rifle = {
            script_id = 9,
        },
        TailLaser = {
            script_id = 10,
        },
        Empty0x11f = {
            script_id = 6,
            camera_movement = 275,
        },
        Empty0x120 = {
            script_id = 11,
            camera_movement = 275,
        }
    },

    items_steal = {},

    manipulate_attacks = {},
},


-- Grashtrike (23)
Grashtrike = {
    max_hp = 42,
    max_mp = 0,

    level = 8,
    physical_power = 12,
    physical_defense = 9,
    physical_dodge = 3,
    magic_power = 15,
    magic_defense = 1,
    speed = 58,
    luck = 6,

    back_damage_multiplier = 2,

    morph_item = UnknownItemId0x0019,

    reward_exp = 20,
    reward_ap = 2,
    reward_gil = 20,

    reward_items_drop = {
        UnknownItemId0x0019 = 2,
    },

    elements = {},

    status_immunes = {},

    attacks = {
        UnknownAttackId0x0121 = {
            script_id = 3,
        },
        UnknownAttackId0x0122 = {
            script_id = 4,
            camera_movement = 275,
        }
    },

    items_steal = {
        UnknownItemId0x0019 = 32,
    },

    berserk_attack = UnknownAttackId0x0121,

    manipulate_attacks = {
        UnknownAttackId0x0121,
        UnknownAttackId0x0122,
    },
},


