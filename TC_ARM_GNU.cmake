set(ARM_GT_BASEPATH "/cygdrive/c/projects/stm32/")
file(TO_CMAKE_PATH ${ARM_GT_BASEPATH} ARM_GT_BASEPATH)
set(COMPILER "arm-gnu-toolchain-12.2.mpacbti-bet1-mingw-w64-i686-arm-none-eabi")
set(ARM_GT_COMPPATH "${ARM_GT_BASEPATH}/${COMPILER}")

set(CMAKE_C_COMPILER "${ARM_GT_COMPPATH}/bin/arm-none-eabi-gcc.exe")
set(CMAKE_ASM_COMPILER "${ARM_GT_COMPPATH}/bin/arm-none-eabi-as.exe")