System = {}



Savemap = {
    progress_game = 0,

    love_point_aeris = 50,
    love_point_tifa = 30,
    love_point_yuffie = 10,
    love_point_barret = 0,
    battle_love_aeris = 100,
    battle_love_tifa = 100,
    battle_love_yuffie = 100,
    battle_love_barret = 100,
}



-- helper function that changes field maps through fadein and fadeout
load_field_map_request = function( map_name, point_name )
    if type( map_name ) == "string" and map_name ~= "" then
        System.MapChanger.map_name = map_name
        System.MapChanger.point_name = point_name
        script:request( "System.MapChanger", "change_map", 0 )
    end
end



System[ "MapChanger" ] = {
    map_name = "",
    point_name = "",

    change_map = function( self )
        if self.map_name ~= "" then
            script:request_end_sync( "UiContainer.Fade", "fade_out", 0 )
            map( self.map_name )

            local point = entity_manager:get_entity_point( self.point_name )
            if point ~= nil then
                local x, y, z = point:get_point()
                local player = entity_manager:get_entity( "Player" )
                player:set_position( x, y, z )
            end

            script:request_start_sync( "UiContainer.Fade", "fade_in", 0 )
            self.map_name = ""
        end

        return 0
    end,
}
