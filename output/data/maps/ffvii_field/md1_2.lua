EntityContainer = {}



EntityContainer[ "Background" ] = {
    on_start = function( self )
        local temp5_27 = 0;

        while true do
            if temp5_27 > 2 then
                temp5_27 = 0
            end

            local number = math.random( 0, 3 )
            if number == 0 then
                number = 1
            end

            for v = 0, number, 1 do
                background2d:play_animation( "Warning" .. temp5_27 .. "Zizizi" )
                background2d:animation_sync()
            end

            background2d:play_animation( "Warning" .. temp5_27 )
            background2d:animation_sync()

            background2d:play_animation( "WarningBlank" )
            background2d:animation_sync()

            temp5_27 = temp5_27 + 1
        end

        return 0
    end,
}
