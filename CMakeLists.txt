cmake_minimum_required(VERSION 2.6)
project(QGears)
set (CMAKE_PACKAGE_ICON q-gears.png)
#set( CMAKE_VERBOSE_MAKEFILE on )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/dependencies/cotire/CMake")
include(cotire)

# The version number.
set(QGears_VERSION_MAJOR 0)
set(QGears_VERSION_MINOR 22)
set(QGears_VERSION_PATCH 0)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
  message("CMAKE_BUILD_TYPE was empty defaulting to Release")
endif ()

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE} CMAKE_BINARY_DIR is ${CMAKE_BINARY_DIR}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin_release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin_release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin_release)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin_debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin_debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin_debug)

# Generate header containing window title/version information
set(QGEARS_VERSION "Q-Gears v${QGears_VERSION_MAJOR}.${QGears_VERSION_MINOR}.${QGears_VERSION_PATCH} (pre-alpha walk carefully)")
configure_file(configure_version_file.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/configure_version_file.cmake @ONLY)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/qgears_version.h
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/configure_version_file.cmake
  DEPENDS
    ${CMAKE_CURRENT_BINARY_DIR}/configure_version_file.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/QGearsMain/include/qgears_version.h.in
  COMMENT "Configuring qgears_version.h"
  VERBATIM)
add_custom_target(configure_qgears_version ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/qgears_version.h)

# Enable Visual Studio solution "folders"
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON) 

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

set(CMAKE_DEBUG_POSTFIX "_d")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX
    "${QGears_SOURCE_DIR}/output" CACHE PATH "Q-Gears install prefix" FORCE
  )
endif()

find_package(Qt4 REQUIRED)
find_package(ZLIB REQUIRED)
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
    ${QGears_INCLUDE_DIRS}
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
	${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SUDM
)


if (MSVC)
# Build cpp files on all cores, up virtual mem for PCH's as cotire really makes the compiler scream
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /Zm193")
# Shut up about insecure functions, as this is cross platform code we can't use the Win32 specifc functions
add_definitions( -D_CRT_SECURE_NO_WARNINGS )
else()
# Enable C++11, you may need to use -std=c++0x if using an older gcc compiler
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
endif()

if (UNIX AND $ENV{COVERAGE}==1)
      message("Setting coverage compiler options")
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") # debug, no optimisation
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage") # enabling coverage
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
# DO NOT include on win32 - causes CRT dlls to be included
#INCLUDE(InstallRequiredSystemLibraries)

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
    SET(CPACK_WIX_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/wix.template.in")
    SET(CPACK_WIX_UPGRADE_GUID 8fbb893f-5622-4f6d-a7f6-c221f7be5d52)

    # TODO: Set MSI banner image, copyright info etc, also include startmenu/desktop shortcuts
    #set the name of the installer default formating is name-version-os

    # If empty assume release
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "" OR "${CMAKE_BUILD_TYPE}" STREQUAL "Release")
        message("RELEASE installer build")
        install(FILES ${PROJECT_SOURCE_DIR}/output/resources.cfg DESTINATION ./)
        install(FILES ${PROJECT_SOURCE_DIR}/output/plugins.cfg DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/OgreMain.dll DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/RenderSystem_GL.dll DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/OGREOVERLAY.DLL DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/release/OIS.DLL DESTINATION ./)
        install(FILES ${QT_PLUGINS_DIR}/../bin/QtCore4.dll DESTINATION ./)
        install(FILES ${QT_PLUGINS_DIR}/../bin/QtGui4.dll DESTINATION ./)
    else()
        message("DEBUG installer build")
        install(FILES ${PROJECT_SOURCE_DIR}/output/resources_d.cfg DESTINATION ./)
        install(FILES ${PROJECT_SOURCE_DIR}/output/plugins_d.cfg DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/OgreMain_d.dll DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/RenderSystem_GL_d.dll DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/OGREOVERLAY_D.DLL DESTINATION ./)
        install(FILES ${OGRE_CMAKE_MODULE_PATH}/../bin/debug/OIS_D.DLL DESTINATION ./)
        install(FILES ${QT_PLUGINS_DIR}/../bin/QtCored4.dll DESTINATION ./)
        install(FILES ${QT_PLUGINS_DIR}/../bin/QtGuid4.dll DESTINATION ./)
    endif()
elseif(APPLE)
    # APPLE is also UNIX, so must check for APPLE before UNIX
    SET(CPACK_GENERATOR "DragNDrop")
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "" OR "${CMAKE_BUILD_TYPE}" STREQUAL "Release")
       set(OSX_BIN_DIR "${CMAKE_BINARY_DIR}/bin_release")
       message("DEBUG installer build, CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR} OSX_BIN_DIR=${OSX_BIN_DIR}")
    else()
       set(OSX_BIN_DIR "${CMAKE_BINARY_DIR}/bin_debug")
       message("RELEASE installer build, CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR} OSX_BIN_DIR=${OSX_BIN_DIR}")
    endif()
    install(FILES ${PROJECT_SOURCE_DIR}/output/resources.cfg DESTINATION ./)
    install(FILES ${PROJECT_SOURCE_DIR}/output/plugins.cfg DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/Ogre DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/RenderSystem_GL DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/OgreOverlay DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_thread-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_date_time-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_system-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_atomic-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_chrono-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_program_options-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_filesystem-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/libboost_filesystem-mt.dylib DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/QtCore DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/QtGui DESTINATION ./)
    install(FILES ${OSX_BIN_DIR}/liblua.dylib DESTINATION ./)
elseif(UNIX)
    # On Linux generate TAR.GZ,DEB and RPM packages
    #Find out what architecture are we running on and set the package architecture 
    
    # set the generic files needing to be installed
    install( FILES ${PROJECT_SOURCE_DIR}/q-gears.png DESTINATION ./share/pixmaps/ )
    install( FILES ${PROJECT_SOURCE_DIR}/q-gears.desktop DESTINATION ./share/applications/ )
    install( FILES ${PROJECT_SOURCE_DIR}/debian/menu DESTINATION share/menu/ RENAME q-gears )
    install( FILES ${PROJECT_SOURCE_DIR}/output/plugins.cfg_linux DESTINATION share/q-gears/ RENAME plugins.cfg PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ GROUP_WRITE WORLD_WRITE WORLD_READ)
    install( FILES ${PROJECT_SOURCE_DIR}/output/resources.cfg_linux DESTINATION share/q-gears/ RENAME resources.cfg PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ GROUP_WRITE WORLD_WRITE WORLD_READ)
    install( FILES ${PROJECT_SOURCE_DIR}/output/q-gears.cfg_linux DESTINATION share/q-gears/ RENAME q-gears.cfg PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ GROUP_WRITE WORLD_WRITE WORLD_READ)
        
    if(EXISTS "/usr/lib/x86_64-linux-gnu/OGRE-1.9.0/RenderSystem_GL.so.1.9.0")
      install( FILES /usr/lib/x86_64-linux-gnu/OGRE-1.9.0/RenderSystem_GL.so.1.9.0 DESTINATION lib/q-gears/plugins/ )
    elseif(EXISTS "/usr/lib/i386-linux-gnu/OGRE-1.9.0/RenderSystem_GL.so.1.9.0")
      install( FILES /usr/lib/i386-linux-gnu/OGRE-1.9.0/RenderSystem_GL.so.1.9.0 DESTINATION lib/q-gears/plugins/ )
    endif()
        
    SET(CPACK_SOURCE_GENERATOR "TGZ;TZ")
    SET(CPACK_GENERATOR "TGZ")
    #detect Distro Family DEB , RPM 
    if(EXISTS "/etc/lsb-release")
        set(DistroType DEB)
    elseif(EXISTS "/etc/debian_release")
        set(DistroType DEB)
    elseif(EXISTS "/etc/fedora-release")
        set(DistroType RPM)
    endif()
    message(STATUS "Distro Detected: ${DistroType} ")

    if(DistroType MATCHES "DEB")
      # Setup DEB package properties
      MESSAGE(STATUS "DEB ADDED TO GENERATION LIST")
      SET(CPACK_GENERATOR "${CPACK_GENERATOR};DEB")
    endif()
    if(EXISTS "/usr/bin/rpmbuild")
      MESSAGE(STATUS "RPM ADDED TO GENERATION LIST (RPM IS DISABLED IN CMAKELISTS)")
    #  Uncomment to allow for rpm files to be built.   
    #  SET(CPACK_GENERATOR "${CPACK_GENERATOR};RPM")
    endif()
    
    # Setup DEB package properties
    SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Chris Rizzitello <sithlord48@gmail.com>")
    
    
    #Set DEBIAN INFO
    SET(CPACK_DEBIAN_PACKAGE_SECTION games)
    SET(CPACK_DEBIAN_PACKAGE_PRIORITY extra)
    #SET(CPACK_PACKAGE_EXECUTABLE )
    EXECUTE_PROCESS(COMMAND dpkg --print-architecture OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE OUTPUT_STRIP_TRAILING_WHITESPACE)
    MESSAGE (STATUS "Architecture: ${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
    #we should need no longer need postinst since we have added extra install steps to what it would.
    #SET(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA ${CMAKE_SOURCE_DIR}/debian/postinst )
    #set the name to be debian package like.
    SET(CPACK_PACKAGE_FILE_NAME "q-gears_${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
    #SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libogre-1.9, libois,libboost-program-options,libboost-filesystem,libvorbis,libopenal,libboost-test,zlib1g")
    SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libogre-1.9.0, libois-1.3.0,libboost-program-options1.54.0,libboost-filesystem1.54.0,libvorbis0a,libvorbisfile3,libvorbisenc2,libopenal1,libboost-test1.54.0,zlib1g,liblua5.1-0")

    #Set RPM info
      SET(CPACK_RPM_PACKAGE_SUMMARY CPACK_PACKAGE_DESCRIPTION_SUMMARY)
      SET(CPACK_RPM_PACKAGE_NAME CPACK_PACKAGE_NAME)
      SET(CPACK_RPM_PACKAGE_VERSION CPACK_PACKAGE_VERSION)
      SET(CPACK_RPM_PACKAGE_RELEASE 1)
      SET(CPACK_RPM_PACKAGE_LICENSE "GPLv3+")
      SET(CPACK_RPM_PACKAGE_GROUP games)
      SET(CPACK_RPM_PACKAGE_VENDOR)
      SET(CPACK_RPM_PACKAGE_DESCRIPTION)
      #REQUIREMENTS NEED TO BE CHECKED USING FEDORA.
      #SET(CPACK_RPM_PACKAGE_REQUIRES "ogre,ois,boost,vorbis,lua,zlib1g")

endif()

SET_PROPERTY(TARGET liblua PROPERTY FOLDER "3rdparty")
SET_PROPERTY(TARGET buildvm PROPERTY FOLDER "3rdparty")
SET_PROPERTY(TARGET LuaBind PROPERTY FOLDER "3rdparty")
SET_PROPERTY(TARGET luajit PROPERTY FOLDER "3rdparty")
SET_PROPERTY(TARGET minilua PROPERTY FOLDER "3rdparty")
SET_PROPERTY(TARGET TinyXml PROPERTY FOLDER "3rdparty")
SET_PROPERTY(TARGET Sudm_Lib PROPERTY FOLDER "q-gears")


INCLUDE(CPack)
#End of install instructions
