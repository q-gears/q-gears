FFVII.Characters = {}



FFVII.Characters.Cloud = {
    enable = false,
    party_lock = false,

    entity = nil,

    on_start = function(self)
        self.entity = entity_manager:get_entity( "Cloud" )

        while true do
            script:wait( 0 )
        end

        return 0;
    end;
}
