EntityContainer = {}



EntityContainer[ "Background" ] = {
    on_start = function( self )
        while true do
            background2d:play_animation( "Fan" )
            background2d:animation_sync()
        end

        return 0
    end,
}
