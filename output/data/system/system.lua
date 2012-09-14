-- create containers for all script entitys
System = {}
EntityContainer = {}
UiContainer = {}



function table.copy( t )
    if type( t ) ~= "table" then
        return t
    end

    local mt = getmetatable( t )
    local res = {}

    for k, v in pairs( t ) do
        if type( v ) == "table" then
            v = table.copy( v )
        end

        res[ k ] = v
    end

    setmetatable( res, mt )

    return res
end