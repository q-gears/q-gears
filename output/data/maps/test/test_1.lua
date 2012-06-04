EntityContainer = {}



EntityContainer[ "Robo" ] = {
    on_start = function( self )
        local robo = entity_manager:get_entity( "Robo" )
        script:wait( 5 )
        robo:move_auto_animation( false )
        robo:play_animation_stop( "ToFire" )

        return 0
    end,
}



EntityContainer[ "Weltall" ] = {
    on_start = function( self )
        local robo = entity_manager:get_entity( "Weltall" )
        script:wait( 5 )
        robo:move_auto_animation( false )
        robo:play_animation_stop( "9" )

        return 0
    end,
}
