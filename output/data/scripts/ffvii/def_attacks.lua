FFVII.Attacks = {}



-- Machine Gun (272)
FFVII.Attacks.MachineGun = {
    name = "Machine Gun (272)",

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
}



-- Tonfa (273)
FFVII.Attacks.Tonfa = {
    name = "Tonfa (273)",

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
}
