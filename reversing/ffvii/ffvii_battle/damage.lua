damage = function(attacker, target, attack)
    local damage = 0;

    if attack.formula == "physical" then
        damage = attacker.data.attack;
        -- calculate base damage
        damage = damage + ((attacker.data.level + damage) / 32) * ((attacker.data.level * damage) / 32);
        -- apply attack data power
        damage = damage * attack.power;
        -- apply defense
        damage = damage * (512 - target.data.defense) / 512;
        -- random
        damage = damage * (15 + math.random()) / 16;
    elseif attack.formula == "magical" then
        damage = attacker.data.magic_attack;
        -- calculate base damage
        damage = (attacker.data.level + damage) * 6;
        -- apply attack data power
        damage = damage * attack.power;
        -- apply defense
        damage = damage * (512 - target.data.magic_defense) / 512;
        -- random
        damage = damage * (15 + math.random()) / 16;
    end;

    return damage;
end;
