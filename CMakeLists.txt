cmake_minimum_required(VERSION 2.6)

project(QGears)

# The version number.
set(QGears_VERSION_MAJOR 0)
set(QGears_VERSION_MINOR 22)

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

find_package( ZLIB REQUIRED )

find_package(OGRE REQUIRED)

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
            find_package(Boost COMPONENTS unit_test_framework QUIET)
            set(QGears_TEST_LIBRARIES
                ${OGRE_LIBRARIES}
                ${Boost_LIBRARIES}
            )
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
)

# Enable C++11, you may need to use -std=c++0x if using an older compiler
if (MSVC)
else()
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
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
