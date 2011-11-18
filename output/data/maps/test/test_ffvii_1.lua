Entity = {}

i = 0;



Entity[ "MapChanger" ] = {
    on_start = function()
        script:request( "Entity.Cloud", "animation5", 5 )
        script:request( "Entity.Cloud", "animation1", 1 )
        script:request( "Entity.Cloud", "animation3", 3 )
        script:request( "Entity.Cloud", "animation2", 2 )
        script:request( "Entity.Cloud", "animation4", 4 )

        return 0
    end,
}



Entity[ "Cloud" ] = {
    on_start = function()
        local cloud = entity_manager:get_entity( "Cloud" )
        cloud:move_walkmesh( 1, 1 )
        return 0
    end,

    animation1 = function()
        i = 0;
        local cloud = entity_manager:get_entity( "Cloud" )
        while i < 5 do
            cloud:play_animation( "Idle" )
            i = i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation2 = function()
        i = 0;
        local cloud = entity_manager:get_entity( "Cloud" )
        while i < 5 do
            cloud:play_animation( "Walk" )
            i = i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation3 = function()
        i = 0;
        local cloud = entity_manager:get_entity( "Cloud" )
        while i < 5 do
            cloud:play_animation( "Run" )
            i = i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation4 = function()
        i = 0;
        local cloud = entity_manager:get_entity( "Cloud" )
        while i < 5 do
            cloud:play_animation( "Jump" )
            i = i + 1
            cloud:animation_sync()
        end

        return 0
    end,

    animation5 = function()
        i = 0;
        local cloud = entity_manager:get_entity( "Cloud" )
        while i < 5 do
            cloud:play_animation( "TalkNo" )
            i = i + 1
            cloud:animation_sync()
        end

        return 0
    end,
}



Entity[ "TreasureChest" ] = {
    on_start = function()
        local chest = entity_manager:get_entity( "TreasureChest" )
        chest:play_animation_stop( "Idle" )
        return 0
    end,
}



Entity[ "Manager" ] = {
    on_start = function()
        script:request( "Entity.Cloud", "animation5", 5 )
        script:request( "Entity.Cloud", "animation1", 1 )
        script:request( "Entity.Cloud", "animation3", 3 )
        script:request( "Entity.Cloud", "animation2", 2 )
        script:request( "Entity.Cloud", "animation4", 4 )

        return 0
    end,
}