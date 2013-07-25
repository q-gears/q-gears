EntityContainer = {}

EntityContainer[ "Mp1" ] = table.copy( FFVII.Enemies.MP )
EntityContainer[ "Mp2" ] = table.copy( FFVII.Enemies.MP )

EntityContainer[ "Mp1" ].row = FFVII.Battle.Row.FRONT
EntityContainer[ "Mp2" ].row = FFVII.Battle.Row.FRONT

FFVII.Battle.init()
