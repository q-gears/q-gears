-- Machine Gun (272)
MachineGun = {
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
    sound_id_normal = 15,
    sound_id_cricical = 15,
    sound_id_miss = 15,
    impact_effect_id = 45,
},


-- Tonfa (273)
Tonfa = {
    mp_cost = 0,
    power = 1.5,
    hit = 85,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",


    elements = {
        Hit,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 35,
    sound_id_cricical = 35,
    sound_id_miss = 35,
    impact_effect_id = 36,
},


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


-- Drilldrive (276)
Drilldrive = {
    mp_cost = 0,
    power = 1,
    hit = 100,

    formula = "0x11",
    target = "0x03",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xffff",


    elements = {
        Punch,
    },

    target_hurt_script_id = 0,
    sound_id_normal = 225,
    sound_id_cricical = 225,
    sound_id_miss = 225,
    impact_effect_id = 48,
},


-- Fire (27)
Fire = {
    mp_cost = 4,
    power = 0.5,
    hit = 100,

    formula = "0x22",
    target = "0x0f",
    additional_effect = "0xff",
    additional_effect_modifier = "0xff",
    special = "0xfdff",


    elements = {
        Fire,
    },

    target_hurt_script_id = 0,
    attack_effect_id = 27,
    camera_id_single = 6,
    camera_id_multiple = 36,
},


