cmake_minimum_required(VERSION 2.6)

project(QGears)

#set( CMAKE_VERBOSE_MAKEFILE on )

# The version number.
set(QGears_VERSION_MAJOR 0)
set(QGears_VERSION_MINOR 22)
set(QGears_VERSION_PATCH 0)

#if (APPLE)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m32")
#endif()

set(CMAKE_FRAMEWORK_PATH
      ${CMAKE_FRAMEWORK_PATH}
      ${CMAKE_CURRENT_SOURCE_DIR}/OgreSDK/lib/macosx/Release
      ${CMAKE_CURRENT_SOURCE_DIR}/OgreSDK/lib/macosx/Debug
   )

set(OGRE_FRAMEWORK_INCLUDES
      ${CMAKE_CURRENT_SOURCE_DIR}/OgreSDK/include
)

option(QGears_BUILD_PLUGINS     "Build the plugins"     TRUE)
option(QGears_BUILD_UTILITIES   "Build the utilities"   TRUE)
option(QGears_BUILD_TESTS       "Build the unit tests"  TRUE)
option(QGears_MULTITHREADING    "Enable multithreading" FALSE)
option(QGears_SOUND             "Enable Sound"          FALSE)

find_path(OGRE_CMAKE_MODULE_PATH FindOGRE.cmake
    HINTS
    "$ENV{OGRE_HOME}/CMake/"
    "/usr/local/lib/OGRE/cmake"
    "/usr/lib/OGRE/cmake"
    "/usr/share/OGRE/cmake/modules"
    "${CMAKE_CURRENT_SOURCE_DIR}/OgreSDK/CMake"
)
if(OGRE_CMAKE_MODULE_PATH-NOTFOUND)
    message(SEND_ERROR "Failed to find OGRE module path.")
else()
    set(CMAKE_MODULE_PATH "${OGRE_CMAKE_MODULE_PATH};${CMAKE_MODULE_PATH}")
endif()

set(CMAKE_MODULE_PATH "${OGRE_CMAKE_MODULE_PATH};${CMAKE_MODULE_PATH}")
set(CMAKE_MODULE_PATH 
  "${CMAKE_MODULE_PATH}"
  "${QGears_SOURCE_DIR}/CMake" 
)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "release" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
  message("RELEASE set")
endif ()

set(CMAKE_DEBUG_POSTFIX "_d")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX
    "${QGears_SOURCE_DIR}/output" CACHE PATH "Q-Gears install prefix" FORCE
  )
endif()

find_package( ZLIB REQUIRED )

find_package(OGRE REQUIRED)

find_package(OIS REQUIRED)

if(NOT OIS_FOUND)
        message(SEND_ERROR "Failed to find OIS.")
endif()

# Find Boost
if (NOT OGRE_BUILD_PLATFORM_IPHONE)
        if (WIN32)
                set(Boost_USE_STATIC_LIBS TRUE)
        else ()
                # Statically linking boost to a dynamic Ogre build doesn't work on Linux 64bit
                set(Boost_USE_STATIC_LIBS ${OGRE_STATIC})
        endif ()
        if (MINGW)
                # this is probably a bug in CMake: the boost find module tries to look for
                # boost libraries with name libboost_*, but CMake already prefixes library
                # search names with "lib". This is the workaround.
                set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "")
        endif ()

        set(Boost_ADDITIONAL_VERSIONS "1.55" "1.55.0" "1.53" "1.53.0" "1.52" "1.52.0" "1.51" "1.51.0" "1.50" "1.50.0" "1.49" "1.49.0" "1.48" "1.48.0" "1.47" "1.47.0" "1.46" "1.46.0" "1.45" "1.45.0" "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40")
        # Components that need linking (NB does not include header-only components like bind)
        set(OGRE_BOOST_COMPONENTS thread date_time)
        find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
        if (NOT Boost_FOUND)
                set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
                find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
        endif()

        if(Boost_FOUND AND Boost_VERSION GREATER 104900)
                set(OGRE_BOOST_COMPONENTS thread date_time system chrono)
                find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
        endif()

        # Set up referencing of Boost
        include_directories(${Boost_INCLUDE_DIR})
	if (NOT APPLE)        
	add_definitions(-DBOOST_ALL_NO_LIB)
	endif()

        set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})

        find_package(Boost COMPONENTS program_options filesystem QUIET)
        set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
        set(QGears_LIBRARIES ${OGRE_LIBRARIES})
		
        if(QGears_SOUND)
            find_package(OpenAL REQUIRED)
            find_package(OggVorbis REQUIRED)
            add_definitions(-DQGears_SOUND)
            set(QGears_LIBRARIES
                ${QGears_LIBRARIES}
                ${OPENAL_LIBRARY}
                ${OGGVORBIS_LIBRARIES}
            )
        endif()

        if(QGears_MULTITHREADING)
            # Find Threads
            find_package (Threads REQUIRED)
            set(QGears_LIBRARIES
                ${QGears_LIBRARIES}
                ${CMAKE_THREAD_LIBS_INIT}
            )
        endif()

        if(QGears_BUILD_TESTS)
	    message(STATUS "Looking for boost unit test..")
            find_package(Boost COMPONENTS unit_test_framework REQUIRED)
            set(QGears_TEST_LIBRARIES
                ${OGRE_LIBRARIES}
                ${Boost_LIBRARIES}
            )
            message(STATUS "Test libs = ${QGears_TEST_LIBRARIES}")
            # enable CTest
            enable_testing()
        endif()
endif()

set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${OGRE_Overlay_LIBRARIES})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

if (Boost_LIBRARIES STREQUAL "")
message(SEND_ERROR "Boost_LIBRARIES is not set")
endif()

set(QGears_INCLUDE_DIRS
    ${OIS_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
    ${OGRE_Overlay_INCLUDE_DIRS}
    ${OGRE_SAMPLES_INCLUDEPATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies
	${CMAKE_CURRENT_BINARY_DIR}/dependencies/luajit
	${CMAKE_CURRENT_SOURCE_DIR}/dependencies/luajit/src
	${CMAKE_CURRENT_SOURCE_DIR}/dependencies/luabind
	${CMAKE_CURRENT_SOURCE_DIR}/dependencies/luabind/luabind/detail
	${CMAKE_CURRENT_SOURCE_DIR}/dependencies/tinyxml
)


if (MSVC)
# Build cpp files on all cores
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
else()
# Enable C++11, you may need to use -std=c++0x if using an older gcc compiler
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
endif()

add_definitions(-DTIXML_USE_STL)
add_subdirectory(dependencies)
add_subdirectory(QGearsMain)
add_subdirectory(SupportedGames)

if(QGears_BUILD_PLUGINS)
    add_subdirectory(PlugIns)
endif()

if(QGears_BUILD_UTILITIES)
    add_subdirectory(utilities)
endif()

if(QGears_BUILD_TESTS)
    add_subdirectory(Tests)
endif()

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)

# Set generic CPack properties
INCLUDE(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "q-gears")
SET(CPACK_PACKAGE_VERSION ${QGears_VERSION_MAJOR}.${QGears_VERSION_MINOR}.${QGears_VERSION_PATCH})
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A Free Final Fantasy VII Engine")
# TODO: Need to set these up properly, installing build instructions is a bit strange :)
SET(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/COPYING.txt")
#SET(CPACK_RESOURCE_FILE_README "${PROJECT_SOURCE_DIR}/readme.md")

MESSAGE( STATUS "CMAKE_BUILD_TYPE:         " ${CMAKE_BUILD_TYPE} )
MESSAGE( STATUS "BOOST_ROOT:         " ${BOOST_ROOT} )

#OS SPECIFIC 
if(WIN32)
	# On Windows generate MSI packages
	SET(CPACK_GENERATOR "WIX")
	
	set(CPACK_WIX_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/wix.template.in")
	SET(CPACK_WIX_UPGRADE_GUID 8fbb893f-5622-4f6d-a7f6-c221f7be5d52)

# TODO: Set MSI banner image, copyright info etc, also include startmenu/desktop shortcuts
	#set the name of the installer default formating is name-version-os
	
	# If empty assume release
	if ("${CMAKE_BUILD_TYPE}" STREQUAL "" OR "${CMAKE_BUILD_TYPE}" STREQUAL "release")
		message("RELEASE installer build")
		install(FILES ${PROJECT_SOURCE_DIR}/output/resources.cfg DESTINATION ./)
		install(FILES ${PROJECT_SOURCE_DIR}/output/plugins.cfg DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/OgreMain.dll DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/RenderSystem_GL.dll DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/OGREOVERLAY.DLL DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/OIS.DLL DESTINATION ./)
		install(FILES "${BOOST_ROOT}/stage/lib/BOOST_SYSTEM-VC120-MT-1_55.DLL" DESTINATION ./)
	else()
		message("DEBUG installer build")
		install(FILES ${PROJECT_SOURCE_DIR}/output/resources_d.cfg DESTINATION ./)
		install(FILES ${PROJECT_SOURCE_DIR}/output/plugins_d.cfg DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/OgreMain_d.dll DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/RenderSystem_GL_d.dll DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/OGREOVERLAY_D.DLL DESTINATION ./)
		install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/OIS_D.DLL DESTINATION ./)
		install(FILES "${BOOST_ROOT}/stage/lib/BOOST_SYSTEM-VC120-MT-GD-1_55.DLL" DESTINATION ./)
	endif()
elseif(LINUX)
	# On Linux generate DEB packages
	SET(CPACK_GENERATOR "DEB")
	install( FILES ${PROJECT_SOURCE_DIR}/q-gears.png DESTINATION ./share/pixmaps/ )
	install( FILES ${PROJECT_SOURCE_DIR}/q-gears.desktop DESTINATION ./share/applications/ )
	
	# Setup DEB package properties
	SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Chris Rizzitello <sithlord48@gmail.com>")
	
	#Find out what architecture are we running on and set the package architecture 
	EXECUTE_PROCESS(COMMAND dpkg --print-architecture OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE OUTPUT_STRIP_TRAILING_WHITESPACE)
	MESSAGE ("Architecture: ${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
	
	SET(CPACK_DEBIAN_PACKAGE_SECTION games)
	SET(CPACK_DEBIAN_PACKAGE_PRIORITY extra)
	#SET(CPACK_PACKAGE_EXECUTABLE )
	SET(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA ${CMAKE_SOURCE_DIR}/debian/postinst )
	#set the name to be debian package like.
	SET(CPACK_PACKAGE_FILE_NAME "q-gears_${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
	#SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libogre-1.9, libois,libboost-program-options,libboost-filesystem,libvorbis,libopenal,libboost-test,zlib1g")
	SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libogre-1.9.0, libois-1.3.0,libboost-program-options1.54.0,libboost-filesystem1.54.0,libvorbis0a,libvorbisfile3,libvorbisenc2,libopenal1,libboost-test1.54.0,zlib1g")
elseif(APPLE)
	SET(CPACK_GENERATOR "DragNDrop")
 	install(FILES ${PROJECT_SOURCE_DIR}/output/resources.cfg DESTINATION ./)
	install(FILES ${PROJECT_SOURCE_DIR}/output/plugins.cfg DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../lib/macosx/Release/Ogre.framework/Ogre DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../lib/macosx/Release/RenderSystem_GL.framework/Versions/1.9.0/RenderSystem_GL DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../lib/macosx/Release/OgreOverlay.framework/Versions/1.9.0/OgreOverlay DESTINATION ./)

	# TODO: Fix up other files and use "otool" to fix dynlib + framework paths
        #install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/OIS.DLL DESTINATION ./)
        #install(FILES "${BOOST_ROOT}/stage/lib/BOOST_SYSTEM-VC120-MT-1_55.DLL" DESTINATION ./)
endif()


INCLUDE(CPack)
#End of install instructions
