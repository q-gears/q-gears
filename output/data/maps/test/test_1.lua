EntityContainer = {}



EntityContainer[ "Cloud" ] = {
    on_start = function( self )
        local cloud = entity_manager:get_entity( "Cloud" )
        cloud:move_walkmesh( 1, 1 )
        return 0
    end,

    animation1 = function( self )
        local i = 0;
        local cloud = entity_manager:get_entity( "Cloud" )
        while i < 2 do
            cloud:play_animation( "TalkNo" )
            i = i + 1
            cloud:animation_sync()
        end

        --load_field_map_request( "test_ffvii_2" )

        return 0
    end,
}



EntityContainer[ "TreasureChest" ] = {
    on_start = function( self )
        local chest = entity_manager:get_entity( "TreasureChest" )
        chest:play_animation_stop( "Idle" )
        entity_manager:set_player_entity( "TreasureChest" )
        return 0
    end,
}



EntityContainer[ "Manager" ] = {
    on_start = function( self )
        script:request( "EntityContainer.Cloud", "animation1", 1 )

        return 0
    end,
}