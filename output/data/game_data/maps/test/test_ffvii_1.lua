entity = {}

entity.i = 0;


entity[ "Cloud" ] = {
    on_start = function()
        local entity = game:get_entity( "Cloud" )
        entity:move_walkmesh( 1, 1 )
        return 0
    end,

    animation1 = function()
        entity.i = 0;
        local entity = game:get_entity( "Cloud" )
        while entity.i < 5 do
            entity:play_animation( "idle" )
            entity.i = entity.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation2 = function()
        entity.i = 0;
        local entity = game:get_entity( "Cloud" )
        while entity.i < 5 do
            entity:play_animation( "walk" )
            entity.i = entity.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation3 = function()
        entity.i = 0;
        local entity = game:get_entity( "Cloud" )
        while entity.i < 5 do
            entity:play_animation( "run" )
            entity.i = entity.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation4 = function()
        entity.i = 0;
        local entity = game:get_entity( "Cloud" )
        while entity.i < 5 do
            entity:play_animation( "jump" )
            entity.i = entity.i + 1
            entity:animation_sync()
        end

        return 0
    end,

    animation5 = function()
        entity.i = 0;
        local entity = game:get_entity( "Cloud" )
        while entity.i < 5 do
            entity:play_animation( "talk_no" )
            entity.i = entity.i + 1
            entity:animation_sync()
        end

        return 0
    end,
}



entity[ "TreasureChest" ] = {
    on_start = function()
        local entity = game:get_entity( "TreasureChest" )
        entity:play_animation_stop( "idle" )
        return 0
    end,
}



entity[ "Manager" ] = {
    on_start = function()
        script:request( "Cloud", "animation5", 5 )
        script:request( "Cloud", "animation1", 1 )
        script:request( "Cloud", "animation3", 3 )
        script:request( "Cloud", "animation2", 2 )
        script:request( "Cloud", "animation4", 4 )

        return 0
    end,
}