#---------------------------------------------------------------------------------
# Copyright (c) 2013,WebJet Enterprise Department.ChangYou
# All rights reserved.
# Date        Ver    Who          Comment
# 2013-3-13   1.0    SunHao      CrocssCompile
#---------------------------------------------------------------------------------

#android toolchain for andorid9
INCLUDE(CMAKEFORCECOMPILER)

SET( CMAKE_CROSSCOMPILING TRUE )
SET( CMAKE_SYSTEM_NAME Linux )
SET( CMAKE_SYSTEM_VERSION 1 )
SET( CMAKE_SYSTEM_PROCESSOR "armv7-a" )

#base path
SET( ANDROID_NDK_ROOT "D:/Android/android-ndk-r8d" CACHE PATH "ndkroot")
SET( ANDROID_NDK_TOOLCHAIN_ROOT "${ANDROID_NDK_ROOT}/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows" )

#SET compiler
SET( CMAKE_C_COMPILER "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-gcc.exe" )
SET( CMAKE_CXX_COMPILER "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-g++.exe" )

CMAKE_FORCE_C_COMPILER( "${CMAKE_C_COMPILER}" GNU )
CMAKE_FORCE_CXX_COMPILER( "${CMAKE_CXX_COMPILER}" GNU )

SET( CMAKE_MAKE_PROGRAM "${ANDROID_NDK_ROOT}/prebuilt/windows/bin/make.exe" CACHE PATH "make")
SET( CMAKE_STRIP "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-strip.exe" CACHE PATH "strip" )
SET( CMAKE_AR "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-ar.exe" CACHE PATH "archive" )
SET( CMAKE_LINKER "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-ld.exe" CACHE PATH "linker" ) 
SET( CMAKE_NM "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-nm.exe" CACHE PATH "nm" ) 
SET( CMAKE_OBJCOPY "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-objcopy.exe" CACHE PATH "objcopy" ) 
SET( CMAKE_OBJDUMP "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-objdump.exe" CACHE PATH "objdump" ) 
SET( CMAKE_RANLIB "${ANDROID_NDK_TOOLCHAIN_ROOT}/bin/arm-linux-androideabi-ranlib.exe" CACHE PATH "ranlib" ) 

#cache flags
SET( CMAKE_SHARED_LINKER_FLAGS "" CACHE STRING "linker flags" FORCE )

SET( CMAKE_FIND_ROOT_PATH "${ANDROID_NDK_ROOT}/platforms/android-14/arch-arm" " ${ANDROID_NDK_TOOLCHAIN_ROOT}" )

INCLUDE_DIRECTORIES( ${ANDROID_NDK_ROOT}/platforms/android-14/arch-arm/usr/include )
LINK_DIRECTORIES( ${ANDROID_NDK_ROOT}/platforms/android-14/arch-arm/usr/lib )

SET( LIBS "${ANDROID_NDK_ROOT}/platforms/android-14/arch-arm/usr/lib" )

SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--fix-cortex-a8 -L${LIBS} --sysroot=${LIBS}/../.. " )


SET ( CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER )
SET ( CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY )
SET ( CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY )