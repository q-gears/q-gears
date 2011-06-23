entity = {}

entity.i = 0;


entity[ "Cloud" ] = {
    on_start = function()
        local cloud = game:get_entity( "Cloud" )
        cloud:move_walkmesh( 1, 1 )
        return 0
    end,

    animation1 = function()
        entity.i = 0;
        local cloud = game:get_entity( "Cloud" )
        while entity.i < 5 do
            cloud:play_animation( "idle" )
            entity.i = entity.i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation2 = function()
        entity.i = 0;
        local cloud = game:get_entity( "Cloud" )
        while entity.i < 5 do
            cloud:play_animation( "walk" )
            entity.i = entity.i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation3 = function()
        entity.i = 0;
        local cloud = game:get_entity( "Cloud" )
        while entity.i < 5 do
            cloud:play_animation( "run" )
            entity.i = entity.i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation4 = function()
        entity.i = 0;
        local cloud = game:get_entity( "Cloud" )
        while entity.i < 5 do
            cloud:play_animation( "jump" )
            entity.i = entity.i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation5 = function()
        entity.i = 0;
        local cloud = game:get_entity( "Cloud" )
        while entity.i < 5 do
            cloud:play_animation( "talk_no" )
            entity.i = entity.i + 1
            cloud:animation_sync()
        end

        return 0
    end,
}



entity[ "TreasureChest" ] = {
    on_start = function()
        local chest = game:get_entity( "TreasureChest" )
        chest:play_animation_stop( "idle" )
        return 0
    end,
}



entity[ "Manager" ] = {
    on_start = function()
        script:request( "entity.Cloud", "animation5", 5 )
        script:request( "entity.Cloud", "animation1", 1 )
        script:request( "entity.Cloud", "animation3", 3 )
        script:request( "entity.Cloud", "animation2", 2 )
        script:request( "entity.Cloud", "animation4", 4 )

        return 0
    end,
}