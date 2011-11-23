System = {}



-- helper function that changes field maps through fadein and fadeout
load_field_map_request = function( map_name )
    if type( map_name ) == "string" and map_name ~= "" then
        System.MapChanger.map_name = map_name
        script:request( "System.MapChanger", "change_map", 0 )
    end
end



System[ "MapChanger" ] = {
    map_name = "",

    change_map = function( self )
        if self.map_name ~= "" then
            script:request_end_sync( "Ui.Fade", "fade_out", 0 )
            map( self.map_name )
            script:request_start_sync( "Ui.Fade", "fade_in", 0 )
        end

        return 0
    end,
}
