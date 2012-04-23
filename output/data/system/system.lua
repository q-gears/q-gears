System = {}



-- helper function that changes field maps through fadein and fadeout
load_field_map_request = function( map_name, position_x, position_y, position_z, rotation )
    if type( map_name ) == "string" and map_name ~= "" then
        System.MapChanger.map_name = map_name
        System.MapChanger.position_x = position_x
        System.MapChanger.position_y = position_y
        System.MapChanger.position_z = position_z
        System.MapChanger.rotation = rotation
        script:request( "System.MapChanger", "change_map", 0 )
    end
end



System[ "MapChanger" ] = {
    map_name = "",
    position_x = 0,
    position_y = 0,
    position_z = 0,
    rotation = 0;

    change_map = function( self )
        if self.map_name ~= "" then
            script:request_end_sync( "UiContainer.Fade", "fade_out", 0 )
            map( self.map_name )
            script:request_start_sync( "UiContainer.Fade", "fade_in", 0 )
            self.map_name = ""
        end

        return 0
    end,
}
