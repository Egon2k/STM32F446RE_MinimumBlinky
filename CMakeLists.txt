cmake_minimum_required (VERSION 3.5.2 FATAL_ERROR)
project (HelloArm C)

set(CMAKE_EXECUTABLE_SUFFIX ".bin")

set(build_name "HelloArm")
set(linker_file ${CMAKE_CURRENT_SOURCE_DIR}/STM32F446RETX_RAM.ld)
set(target_hex ${build_name})

set(src_c main.c)
set(src_asm startup_stm32f446retx.S)

set(srcs ${src_c} 
         ${src_asm})

add_executable(${target_hex} ${srcs})
set_target_properties(${target_hex} PROPERTIES LINK_DEPENDS ${linker_file})

