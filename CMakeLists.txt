#/*
#-----------------------------------------------------------------------------
#Filename:    CMakeLists.txt
#-----------------------------------------------------------------------------
#
#This source file is part of the
#   ___                 __    __ _ _    _
#  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
# //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
#/ \_// (_| | | |  __/  \  /\  /| |   <| |
#\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
#      |___/
#      Tutorial Framework
#      http://www.ogre3d.org/tikiwiki/
#-----------------------------------------------------------------------------
#*/
cmake_minimum_required(VERSION 2.6)

project(QGears)

# The version number.
set(QGears_VERSION_MAJOR 0)
set(QGears_VERSION_MINOR 21)

option(QGears_BUILD_PLUGINS     "Build the plugins"     FALSE)
option(QGears_BUILD_UTILITIES   "Build the utilities"   FALSE)
option(QGears_BUILD_TESTS       "Build the unit tests"  FALSE)

find_path(OGRE_CMAKE_MODULE_PATH FindOGRE.cmake
    HINTS
    "$ENV{OGRE_HOME}/CMake/"
    "/usr/local/lib/OGRE/cmake"
    "/usr/lib/OGRE/cmake"
    "/usr/share/OGRE/cmake"
)
if(OGRE_CMAKE_MODULE_PATH-NOTFOUND)
    message(SEND_ERROR "Failed to find OGRE module path.")
else()
    set(CMAKE_MODULE_PATH "${OGRE_CMAKE_MODULE_PATH};${CMAKE_MODULE_PATH}")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

set(CMAKE_DEBUG_POSTFIX "_d")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX
    "${QGears_SOURCE_DIR}/output" CACHE PATH "Q-Gears install prefix" FORCE
  )
endif()

find_package(OGRE REQUIRED)

#if(NOT "${OGRE_VERSION_NAME}" STREQUAL "Cthugha")
#  message(SEND_ERROR "You need Ogre 1.7 Cthugha to build this.")
#endif()

find_package(OIS REQUIRED)

if(NOT OIS_FOUND)
        message(SEND_ERROR "Failed to find OIS.")
endif()

# Find Boost
if (NOT OGRE_BUILD_PLATFORM_IPHONE)
        if (WIN32 OR APPLE)
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

        set(Boost_ADDITIONAL_VERSIONS "1.53" "1.53.0" "1.52" "1.52.0" "1.51" "1.51.0" "1.50" "1.50.0" "1.49" "1.49.0" "1.48" "1.48.0" "1.47" "1.47.0" "1.46" "1.46.0" "1.45" "1.45.0" "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40")
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
        add_definitions(-DBOOST_ALL_NO_LIB)
        set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})

        if(QGears_BUILD_TESTS)
            find_package(Boost COMPONENTS unit_test_framework QUIET)
            set(QGears_TEST_LIBRARIES
                ${OGRE_LIBRARIES}
                ${Boost_LIBRARIES}
            )
            # enable CTest
            enable_testing()
        endif()
endif()
#/*
#file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/bin)
#file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/media)

## post-build copy for win32
#if(WIN32 AND NOT MINGW)
#        add_custom_command( TARGET OgreApp PRE_BUILD
#                COMMAND if not exist .\\dist\\bin mkdir .\\dist\\bin )
#        add_custom_command( TARGET OgreApp POST_BUILD
#                COMMAND copy \"$(TargetPath)\" .\\dist\\bin )
#endif(WIN32 AND NOT MINGW)

#if(MINGW OR UNIX)
#        set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist/bin)
#endif(MINGW OR UNIX)

#if(WIN32)

#        install(TARGETS OgreApp
#                RUNTIME DESTINATION bin
#                CONFIGURATIONS All)

#        install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/Media
#                DESTINATION ./
#                CONFIGURATIONS Release RelWithDebInfo Debug
#        )

#        install(FILES ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
#                ${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
#                DESTINATION bin
#                CONFIGURATIONS Release RelWithDebInfo
#        )

#        install(FILES ${CMAKE_SOURCE_DIR}/dist/bin/plugins_d.cfg
#                ${CMAKE_SOURCE_DIR}/dist/bin/resources_d.cfg
#                DESTINATION bin
#                CONFIGURATIONS Debug
#        )

#        # NOTE: for the 1.7.1 sdk the OIS dll is called OIS.dll instead of libOIS.dll
#        # so you'll have to change that to make it work with 1.7.1
#        install(FILES ${OGRE_PLUGIN_DIR_REL}/OgreMain.dll
#                ${OGRE_PLUGIN_DIR_REL}/RenderSystem_Direct3D9.dll
#                ${OGRE_PLUGIN_DIR_REL}/RenderSystem_GL.dll
#                ${OGRE_PLUGIN_DIR_REL}/libOIS.dll
#                DESTINATION ./
#                CONFIGURATIONS Release RelWithDebInfo
#        )

#        install(FILES ${OGRE_PLUGIN_DIR_DBG}/OgreMain_d.dll
#                ${OGRE_PLUGIN_DIR_DBG}/RenderSystem_Direct3D9_d.dll
#                ${OGRE_PLUGIN_DIR_DBG}/RenderSystem_GL_d.dll
#                ${OGRE_PLUGIN_DIR_DBG}/libOIS_d.dll
#                DESTINATION bin
#                CONFIGURATIONS Debug
#        )

#   # as of sdk 1.7.2 we need to copy the boost dll's as well
#   # because they're not linked statically (it worked with 1.7.1 though)
#   install(FILES ${Boost_DATE_TIME_LIBRARY_RELEASE}
#      ${Boost_THREAD_LIBRARY_RELEASE}
#      DESTINATION bin
#      CONFIGURATIONS Release RelWithDebInfo
#   )

#   install(FILES ${Boost_DATE_TIME_LIBRARY_DEBUG}
#      ${Boost_THREAD_LIBRARY_DEBUG}
#      DESTINATION bin
#      CONFIGURATIONS Debug
#   )
#endif(WIN32)

if(UNIX)

#        install(TARGETS OgreApp
#                RUNTIME DESTINATION bin
#                CONFIGURATIONS All)

#        install(DIRECTORY ${CMAKE_SOURCE_DIR}/dist/media
#                DESTINATION ./
#                CONFIGURATIONS Release RelWithDebInfo Debug
#        )

#    get_filename_component(Plugin_RenderSystem_GL "${OGRE_RenderSystem_GL_LIBRARY_REL}" REALPATH)
#    install(FILES
#        ${Plugin_RenderSystem_GL}
#        DESTINATION ./
#        CONFIGURATIONS Release RelWithDebInfo Debug
#        RENAME RenderSystem_GL.so
#    )

#        install(FILES ${CMAKE_SOURCE_DIR}/dist/bin/plugins.cfg
#                ${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
#                DESTINATION bin
#                CONFIGURATIONS Release RelWithDebInfo Debug
#        )

endif(UNIX)
#*/

set(QGears_INCLUDE_DIRS
    ${OIS_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
    ${OGRE_SAMPLES_INCLUDEPATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/dependencies
)

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
