FFVII.Characters = {}



FFVII.Characters.Cloud = {
    enable = false,
    party_lock = false,

    on_start = function(self)
        while true do
            local dir = self.entity:get_rotation()
            dir = dir + 1
            self.entity:set_rotation( dir )
            script:wait( 0 )
        end

        return 0;
    end;
}
