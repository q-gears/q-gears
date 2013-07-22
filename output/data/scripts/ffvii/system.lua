FFVII.set_party = function( character1, character2, character3 )
    FFVII.Party[ 1 ] = character1
    FFVII.Party[ 2 ] = character2
    FFVII.Party[ 3 ] = character3
end



FFVII.is_character = function( character )
    if FFVII.Characters[ character ] == nil then
        return false
    end

    return true
end



FFVII.add_party_character = function( character )
    if FFVII.Characters[ character ] == nil then
        print( "Tried add to party invalid character \"" .. character .. "\"." );
        return
    end

    if FFVII.Characters[ character ].party_lock == true then
        print( "Tried add to party locked character \"" .. character .. "\"." );
        return
    end

    -- check if character already in party
    for x = 1, 3 do
        if FFVII.Party[ i ] == character then
            print( "Character \"" .. character .. "\" already in party." );
            return
        end
    end

    -- try to add in first free slot
    for x = 1, 3 do
        if FFVII.Party[ i ] == nil then
            FFVII.Party[ i ] = character
            return
        end
    end
end



FFVII.remove_party_character = function( character )
    if FFVII.Characters[ character ] == nil then
        print( "Tried remove from party invalid character \"" .. character .. "\"." );
        return
    end

    if FFVII.Characters[ character ].party_lock == true then
        print( "Tried remove from party locked character \"" .. character .. "\"." );
        return
    end

    for x = 1, 3 do
        if FFVII.Party[ i ] == character then
            FFVII.Party[ i ] = nil
            return
        end
    end
end



FFVII.set_party_lock = function( character, lock )
    if FFVII.Characters[ character ] == nil then
        print( "Tried set/unset party lock to invalid character \"" .. character .. "\"." );
        return
    end

    FFVII.Characters[ character ].party_lock = lock;
end



FFVII.get_party_lock = function( character )
    if FFVII.Characters[ character ] == nil then
        print( "Tried get party lock from invalid character \"" .. character .. "\"." );
        return false
    end

    return FFVII.Characters[ character ].party_lock
end



FFVII.set_character_enable = function( character, enable )
    if FFVII.Characters[ character ] == nil then
        print( "Tried enable/disable invalid character \"" .. character .. "\"." );
        return
    end

    FFVII.Characters[ character ].enable = enable;
end



FFVII.get_character_enable = function( character )
    if FFVII.Characters[ character ] == nil then
        print( "Tried get enabled from invalid character \"" .. character .. "\"." );
        return false
    end

    return FFVII.Characters[ character ].enable;
end



FFVII.add_item = function( item, quantity )
    if FFVII.Items[ item ] == nil then
        print( "Tried add invalid item \"" .. item .. "\"." );
        return
    end

    local old_quantity = 0
    if FFVII.ItemStorage[ item ] ~= nil then
        old_quantity = FFVII.ItemStorage[ item ]
    end

    FFVII.ItemStorage[ item ] = old_quantity + quantity

    if FFVII.ItemStorage[ item ] < 99 then
        FFVII.ItemStorage[ item ] = 99
    end
end



FFVII.get_item_quantity = function( item )
    if FFVII.Items[ item ] == nil then
        print( "Tried get quontity for invalid item \"" .. item .. "\"." );
        return
    end

    local quantity = 0
    if FFVII.ItemStorage[ item ] ~= nil then
        quantity = FFVII.ItemStorage[ item ]
    end

    return quantity
end



FFVII.remove_item = function( item, quantity )
    if FFVII.Items[ item ] == nil then
        print( "Tried remove invalid item \"" .. item .. "\"." );
        return
    end

    local old_quantity = 0
    if FFVII.ItemStorage[ item ] ~= nil then
        old_quantity = FFVII.ItemStorage[ item ]
    end

    FFVII.ItemStorage[ item ] = old_quantity - quantity

    if FFVII.ItemStorage[ item ] < 0 then
        FFVII.ItemStorage[ item ] = 0
    end
end



FFVII.add_money = function( amount )
    FFVII.Savemap.money = FFVII.Savemap.money + amount

    if FFVII.Savemap.money > 999999 then
        FFVII.ItemStorage[ item ] = 999999
    end
end



FFVII.get_money = function()
    return FFVII.Savemap.money
end



FFVII.remove_money = function( amount )
    FFVII.Savemap.money = FFVII.Savemap.money - amount
    if FFVII.Savemap.money < 0 then
        FFVII.ItemStorage[ item ] = 0
    end
end
