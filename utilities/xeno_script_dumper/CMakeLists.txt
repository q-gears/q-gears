include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
./src/GameDefine.h
./src/game/field/ScriptFile.h
./src/game/field/FieldModule.h
./src/game/field/FieldPackFile.h
./src/game/filesystem/File.h
./src/game/filetypes/ArchiveFile.h
./src/game/filetypes/ArchiveFile.cpp
./src/game/filetypes/SubPacketFile.h
./src/game/filetypes/PacketFile.h
./src/common/filesystem/driver/RealFileDriver.h
./src/common/filesystem/driver/NullFileDriver.h
./src/common/filesystem/driver/FileDriver.h
./src/common/filesystem/FileSystem.h
./src/common/filesystem/RealFileSystem.h
./src/common/TypeDefine.h
./src/common/utilites/Logger.h
./src/common/utilites/StdString.h
./src/common/utilites/Utilites.h
./src/common/utilites/NoCopy.h
./src/Main.h
./src/Define.h
)

set(SOURCE_FILES
./src/game/field/FieldPackFile.cpp
./src/game/field/FieldModule.cpp
./src/game/field/ScriptFile.cpp
./src/game/filesystem/File.cpp
./src/game/filetypes/SubPacketFile.cpp
./src/game/filetypes/ArchiveFile.cpp
./src/game/filetypes/PacketFile.cpp
./src/common/filesystem/RealFileSystem.cpp
./src/common/filesystem/driver/RealFileDriver.cpp
./src/common/filesystem/driver/NullFileDriver.cpp
./src/common/filesystem/driver/FileDriver.cpp
./src/common/filesystem/FileSystem.cpp
./src/common/utilites/Logger.cpp
./src/common/utilites/Utilites.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(xeno_script_dumper
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET xeno_script_dumper PROPERTY FOLDER "utilities")

if(WIN32)
  set_target_properties(xeno_script_dumper PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(xeno_script_dumper PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(xeno_script_dumper    ${LIBRARIES})

install(TARGETS xeno_script_dumper
    DESTINATION tools/xeno
)
