cmake_minimum_required(VERSION 2.8.11)

project(QGears)

# The version number.
set(QGears_VERSION_MAJOR 0)
set(QGears_VERSION_MINOR 21)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX
    "${QGears_SOURCE_DIR}/output" CACHE PATH "Q-Gears install prefix" FORCE
  )
endif()


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
#not sure what the minimal version is that Q-Gears requires
find_package(Boost 1.43 COMPONENTS system thread chrono date_time)

find_path(OGRE_SDK
  NAMES include/OGRE/Ogre.h include/OIS/OIS.h
  DOC "Ogre SDK Path"
)

set(OGRE_LIBRARY_DIRS
  ${OGRE_SDK}/lib
  ${OGRE_SDK}/lib/opt
  ${OGRE_SDK}/lib/release
  ${OGRE_SDK}/lib/release/opt
  ${OGRE_SDK}/lib/debug
  ${OGRE_SDK}/lib/debug/opt
)

find_library(OGRE_MAIN_LIBRARIES
  OgreMain
  ${OGRE_LIBRARY_DIRS}
)
find_library(OGRE_OIS_LIBRARIES
  ois
)

set(OGRE_INCLUDE_DIRS
  ${OGRE_SDK}/include/OGRE
  ${OGRE_SDK}/include/OIS
)

set(OGRE_LIBRARIES
  ${OGRE_MAIN_LIBRARIES}
  ${OGRE_OIS_LIBRARIES}
)

set(CMAKE_DEBUG_POSTFIX _d)

add_subdirectory(QGearsMain)
add_subdirectory(PlugIns)
add_subdirectory(utilities)
