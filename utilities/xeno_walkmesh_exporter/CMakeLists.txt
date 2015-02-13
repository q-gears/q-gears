include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# define header and source files
set(HEADER_FILES
./src/core/input/InputFilter.h
./src/core/ui/MovableTextArea.h
./src/game/field/WalkmeshFile.h
./src/game/field/Walkmesh.h
./src/game/filesystem/File.h
./src/game/filesystem/FileStream.h
./src/game/filetypes/LzsFile.h
./src/game/filetypes/FontFile.h
./src/game/filetypes/BinGZipFile.h
./src/game/filetypes/image/Vram.h
./src/game/filetypes/TimFile.h
./src/common/filesystem/GameFileSystem.h
./src/common/filesystem/driver/RealFileDriver.h
./src/common/filesystem/driver/NullFileDriver.h
./src/common/filesystem/driver/FileDriver.h
./src/common/filesystem/XmlFile.h
./src/common/filesystem/FileSystem.h
./src/common/filesystem/RealFileSystem.h
./src/common/TypeDefine.h
./src/common/display/actor/Actor.h
./src/common/display/surface/SurfaceLoad.h
./src/common/display/surface/SurfaceLoadBmp.h
./src/common/display/surface/Surface.h
./src/common/display/surface/SurfaceSaveBmp.h
./src/common/display/3dTypes.h
./src/common/display/math
./src/common/display/math/VectorMath.h
./src/common/display/math/Matrix.cpp
./src/common/display/math/Vector.h
./src/common/display/math/MatrixMath.h
./src/common/display/math/Box.h
./src/common/display/math/Matrix.h
./src/common/utilites/Logger.h
./src/common/utilites/StdString.h
./src/common/utilites/Utilites.h
./src/common/utilites/NoCopy.h
./src/Main.h
./src/Define.h
)

set(SOURCE_FILES
./src/core/input/InputFilter.cpp
./src/core/ui/MovableTextArea.cpp
./src/game/field/Walkmesh.cpp
./src/game/field/WalkmeshFile.cpp
./src/game/filesystem/File.cpp
./src/game/filetypes/BinGZipFile.cpp
./src/game/filetypes/FontFile.cpp
./src/game/filetypes/LzsFile.cpp
./src/game/filetypes/TimFile.cpp
./src/game/filetypes/image/Vram.cpp
./src/common/filesystem/RealFileSystem.cpp
./src/common/filesystem/XmlFile.cpp
./src/common/filesystem/GameFileSystem.cpp
./src/common/filesystem/driver/RealFileDriver.cpp
./src/common/filesystem/driver/NullFileDriver.cpp
./src/common/filesystem/driver/FileDriver.cpp
./src/common/filesystem/FileSystem.cpp
./src/common/display/actor/Actor.cpp
./src/common/display/surface/SurfaceLoad.cpp
./src/common/display/surface/SurfaceLoadBmp.cpp
./src/common/display/surface/Surface.cpp
./src/common/display/surface/SurfaceSaveBmp.cpp
./src/common/display/math/Matrix.cpp
./src/common/display/math/VectorMath.cpp
./src/common/display/math/MatrixMath.cpp
./src/common/utilites/Logger.cpp
./src/common/utilites/Utilites.cpp
./src/Main.cpp
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(xeno_walkmesh_exporter
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET xeno_walkmesh_exporter PROPERTY FOLDER "utilities")

if (APPLE)
target_link_libraries(xeno_walkmesh_exporter "-framework CoreFoundation -framework Cocoa -framework IOKit")
endif()

if(WIN32)
  set_target_properties(xeno_walkmesh_exporter PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(xeno_walkmesh_exporter PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(xeno_walkmesh_exporter    ${LIBRARIES})

install(TARGETS xeno_walkmesh_exporter
    DESTINATION tools/xeno
)
