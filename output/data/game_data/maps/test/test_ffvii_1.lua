map = {}

map.i = 0;


map[ "Cloud" ] = {
    on_start = function()
        local entity = game:get_entity( "Cloud" )
        entity:move_walkmesh( 1, 1 )
        return 0
    end,

    animation1 = function()
        map.i = 0;
        local entity = game:get_entity( "Cloud" )
        while map.i < 5 do
            entity:play_animation( "idle" )
            map.i = map.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation2 = function()
        map.i = 0;
        local entity = game:get_entity( "Cloud" )
        while map.i < 5 do
            entity:play_animation( "walk" )
            map.i = map.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation3 = function()
        map.i = 0;
        local entity = game:get_entity( "Cloud" )
        while map.i < 5 do
            entity:play_animation( "run" )
            map.i = map.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation4 = function()
        map.i = 0;
        local entity = game:get_entity( "Cloud" )
        while map.i < 5 do
            entity:play_animation( "jump" )
            map.i = map.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation5 = function()
        map.i = 0;
        local entity = game:get_entity( "Cloud" )
        while map.i < 5 do
            entity:play_animation( "talk_no" )
            map.i = map.i + 1
            entity:animation_sync()
        end

        return 0
    end,
}



map[ "TreasureChest" ] = {
    on_start = function()
        local entity = game:get_entity( "TreasureChest" )
        entity:play_animation_stop( "idle" )
        return 0
    end,
}



map[ "Manager" ] = {
    on_start = function()
        script:request( "Cloud", "animation5", 5 )
        script:request( "Cloud", "animation1", 1 )
        script:request( "Cloud", "animation3", 3 )
        script:request( "Cloud", "animation2", 2 )
        script:request( "Cloud", "animation4", 4 )

        return 0
    end,
}