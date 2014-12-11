include_directories(
    ${QGears_INCLUDE_DIRS}
)

add_subdirectory(tinyxml)
add_subdirectory( lua )

aux_source_directory( luabind/luabind LuaBind_header_FILES )
aux_source_directory( luabind/luabind/details LuaBind_header_details_FILES )
aux_source_directory( luabind/src LuaBind_src_FILES )

add_library(LuaBind STATIC ${LuaBind_src_FILES} ${LuaBind_header_FILES} ${LuaBind_header_details_FILES})
target_link_libraries(LuaBind Lua)

