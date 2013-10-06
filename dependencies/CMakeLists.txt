include_directories(
    ${QGears_INCLUDE_DIRS}
)

aux_source_directory( lua Lua_FILES )
aux_source_directory( luabind LuaBind_FILES )
aux_source_directory( tinyxml TinyXml_FILES )

add_library(Lua STATIC ${Lua_FILES})
add_library(LuaBind STATIC ${LuaBind_FILES})
target_link_libraries(LuaBind Lua)

add_library(TinyXml STATIC ${TinyXml_FILES})
