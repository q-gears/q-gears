-- helper function that changes field maps through fadein and fadeout
load_field_map_request = function( map_name, point_name )
    if type( map_name ) == "string" and map_name ~= "" then
        System.MapChanger.map_name = map_name
        System.MapChanger.point_name = point_name
        script:request( Script.SYSTEM, "MapChanger", "ffvii_field", 0 )
    end
end



set_entity_to_character = function( entity_name, character_name )
    if character_name == FFVII.Party[ 1 ] and entity_name ~= "" then
        if System.MapChanger.point_name ~= "" then
            local point = entity_manager:get_entity_point( System.MapChanger.point_name )
            if point ~= nil then
                local x, y, z = point:get_position()
                local rotation = point:get_rotation()
                local player = entity_manager:get_entity( entity_name )
                player:set_position( x, y, z )
                player:set_rotation( rotation )
                player:set_solid( true )
                player:set_visible( true )
            end
        end

        entity_manager:set_player_entity( entity_name )
    end
end



player_lock = function( lock )
    entity_manager:player_lock( lock )
    FFVII.MenuSettings.available = ( lock == false )
end



System[ "MapChanger" ] = {
    map_name = "",
    point_name = "",

    ffvii_field = function( self )
        if self.map_name ~= "" then
            player_lock( true ) -- disable menu and pc movement while load map
            script:request_end_sync( Script.UI, "Fade", "fade_out", 0 )
            map( self.map_name )
            player_lock( false ) -- enable menu and pc movement after load map
            self.map_name = ""
            script:request_end_sync( Script.UI, "Fade", "fade_in", 0 )
        end

        return 0
    end,

    ffvii_battle = function( self )
        if self.map_name ~= "" then
            player_lock( true ) -- disable menu and pc movement while load map
            script:request_end_sync( Script.UI, "Fade", "fade_out", 0 )
            map( self.map_name )
-- load battle ui
-- load player entity
            self.map_name = ""
            script:request_end_sync( Script.UI, "Fade", "fade_in", 0 )
        end

        return 0
    end,
}
