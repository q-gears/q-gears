-- Bite (274)
Bite = {
    mp_cost = 0,
    power = 1,
    hit = 100,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        Hit,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 25,
    sound_id_cricical = 25,
    sound_id_miss = 25,
    impact_effect_id = 48,
},


-- Tentacle (275)
Tentacle = {
    mp_cost = 0,
    power = 1.5,
    hit = 90,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        Hit,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 221,
    sound_id_cricical = 221,
    sound_id_miss = 221,
    impact_effect_id = 60,
},


-- Rifle (282)
Rifle = {
    mp_cost = 0,
    power = 1,
    hit = 100,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        Shoot,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 35,
    sound_id_cricical = 35,
    sound_id_miss = 35,
    impact_effect_id = 46,
},


-- Scorpion Tail (283)
ScorpionTail = {
    mp_cost = 0,
    power = 1.75,
    hit = 95,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        Shoot,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 35,
    sound_id_cricical = 35,
    sound_id_miss = 35,
    impact_effect_id = 61,
},


-- Search Scope (284)
SearchScope = {
    mp_cost = 0,
    power = 0,
    hit = 255,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        Shoot,
    },

    target_hurt_script_id = 0,
    attack_effect_id = 75,
    camera_id_single = 211,
    camera_id_multiple = 211,
},


-- Rifle (285)
Rifle = {
    mp_cost = 0,
    power = 1,
    hit = 100,

    formula = "0x11",
    target = "0x01",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        Shoot,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 15,
    sound_id_cricical = 15,
    sound_id_miss = 15,
    impact_effect_id = 46,
},


-- Tail Laser (286)
TailLaser = {
    mp_cost = 0,
    power = 3,
    hit = 120,

    formula = "0x11",
    target = "0x16",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        Shoot,
    },

    target_hurt_script_id = 2,
    attack_effect_id = 76,
    camera_id_single = 212,
    camera_id_multiple = 212,
},


--  (287)
Empty0x11f = {
    mp_cost = 0,
    power = 0,
    hit = 255,

    formula = "0x00",
    target = "0x00",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xff7f",

    elements = {},

    target_hurt_script_id = 0,
    camera_id_single = 272,
    camera_id_multiple = 272,
},


--  (288)
Empty0x120 = {
    mp_cost = 0,
    power = 0,
    hit = 255,

    formula = "0x00",
    target = "0x00",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xff7f",

    elements = {},

    target_hurt_script_id = 0,
},


-- Sickle (289)
UnknownAttackId0x0121 = {
    mp_cost = 0,
    power = 1,
    hit = 100,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {
        UnknownElement0x000a,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 226,
    sound_id_cricical = 226,
    sound_id_miss = 226,
    impact_effect_id = 18,
},


-- Silk (290)
UnknownAttackId0x0122 = {
    mp_cost = 0,
    power = 0,
    hit = 90,

    formula = "0x22",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",

    elements = {},

    status_add = {
        UnknownStatusId0x0009,
    },

    target_hurt_script_id = 1,
    attack_effect_id = 2,
    camera_id_single = 216,
    camera_id_multiple = 216,
},


