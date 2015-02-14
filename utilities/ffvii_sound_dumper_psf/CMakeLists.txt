include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/libupse
)

# define header and source files
set(HEADER_FILES
./src/libupse/upse-ps1-spu-register-io.h
./src/libupse/upse-ps1-memory-manager.h
./src/libupse/upse-r3000-abstract.h
./src/libupse/upse-ps1-counters.h
./src/libupse/config.h
./src/libupse/upse-types.h
./src/libupse/upse-spu-internal.h
./src/libupse/upse-ps1-spu-abstract.h
./src/libupse/upse-ps1-executive.h
./src/libupse/upse-internal.h
./src/libupse/upse-ps1-hal.h
./src/libupse/upse-ps1-spu-reverb.h
./src/libupse/upse-ps1-bios-base.h
./src/libupse/upse.h
./src/libupse/upse-ps1-bios-private.h
./src/libupse/upse-string.h
./src/libupse/upse-ps1-spu-base.h
./src/libupse/upse-ps1-spu-dma-handler.h
./src/libupse/upse-ps1-dma-manager.h
./src/libupse/upse-ps1-spu-adsr-filter.h
./src/libupse/upse-debug.h
./src/walkthrough.hh
./src/typedefs.h
)

set(SOURCE_FILES
./src/main.cc
#./src/libupse/upse_ps1_spu_adsr_filter.c
#./src/libupse/upse_ps1_spu_reverb.c
#./src/libupse/upse_bios_manager.c
#./src/libupse/upse_ps1_spu_dma_handler.c
#./src/libupse/upse_ps1_spu_base.c
#./src/libupse/upse_r3000_abstract.c
#./src/libupse/upse_r3000_bytecode_evaluator.c
#./src/libupse/upse_unpack_psf.c
#./src/libupse/upse_ps1_counters.c
#./src/libupse/upse_ps1_hal.c
#./src/libupse/upse_ps1_memory_manager.c
#./src/libupse/upse_string.c
#./src/libupse/upse_ps1_dma_manager.c
#./src/libupse/upse_util.c
#./src/libupse/upse_ps1_bios_base.c
#./src/libupse/upse_ps1_executive.c
#./src/libupse/upse_ps1_spu_register_io.c
./src/walkthrough.cc
)

add_definitions(
    -DQGEARS_ADD_MANAGERS
)

add_executable(ff7_sound_dumper_psf
  ${HEADER_FILES}
  ${SOURCE_FILES}
)
SET_PROPERTY(TARGET ff7_sound_dumper_psf PROPERTY FOLDER "utilities")

if(WIN32)
  set_target_properties(ff7_sound_dumper_psf PROPERTIES WIN32_EXECUTABLE ON)
  if (MSVC)
    set_target_properties(ff7_sound_dumper_psf PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endif()

set(LIBRARIES
    Utility
    QGearsMain
    q-gears-data
)
target_link_libraries(ff7_sound_dumper_psf    ${LIBRARIES})

install(TARGETS ff7_sound_dumper_psf
    DESTINATION tools/ff7
)
