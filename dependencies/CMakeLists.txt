include_directories(
    ${QGears_INCLUDE_DIRS}
	luabind
	luajit/src
	luabind/luabind
	luabind/luabind/detail
	SUDM
)

add_subdirectory(tinyxml)
add_subdirectory(luajit)

SET(SUDM_AS_LIB TRUE CACHE BOOL "Build only lib")
add_subdirectory(SUDM)

 aux_source_directory( luabind/luabind LuaBind_header_FILES )
 aux_source_directory( luabind/luabind/details LuaBind_header_details_FILES )		
 aux_source_directory( luabind/src LuaBind_src_FILES )		
 add_library(LuaBind STATIC ${LuaBind_src_FILES} ${LuaBind_header_FILES} ${LuaBind_header_details_FILES})
 
 