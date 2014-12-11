include_directories(
    ${QGears_INCLUDE_DIRS}
)

aux_source_directory( lua/src Lua_FILES )
aux_source_directory( luabind/luabind LuaBind_FILES )

add_subdirectory(tinyxml)

add_library(Lua STATIC ${Lua_FILES})
add_library(LuaBind STATIC ${LuaBind_FILES})
target_link_libraries(LuaBind Lua)

