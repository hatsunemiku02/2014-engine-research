#---------------------------------------------------------------------------------
# Copyright (c) 2011,WebJet Enterprise Department.ChangYou
# All rights reserved.
# Date        Ver    Who          Comment
# 2013-3-13   1.0    SunHao      CrocssCompile
#---------------------------------------------------------------------------------

ADD_DEFINITIONS(
	-D__ANDROID__
	-DANDROID )

#temp definitions	
IF ( ANDROID_OPTIMIZED )
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti -fexceptions  -Wfatal-errors" )
	SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexceptions -Wfatal-errors" )
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3" )
	SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3" )
	MESSAGE( STATUS "ANDROID_OPTIMIZED Turn On!" )
ELSE ( ANDROID_OPTIMIZED )
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti -fexceptions  -Wfatal-errors -g" )
	SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexceptions -Wfatal-errors -g" )
ENDIF ( ANDROID_OPTIMIZED )

IF ( ANDROID_NDEBUG )
	ADD_DEFINITIONS( -DNDEBUG )
	MESSAGE( STATUS "NDEBUG macro set!" )
ELSE( ANDROID_NDEBUG )
	ADD_DEFINITIONS( -D_DEBUG )
	MESSAGE( STATUS "_DEBUG macro set!" )
ENDIF ( ANDROID_NDEBUG )

IF ( SKIPCONVERT )
	ADD_DEFINITIONS( -DSKIPCONVERT )
ENDIF ( SKIPCONVERT )	


SET( ANDROID_GUN_LIB_STD_INCLUDE_PATH "${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/include" )
SET( ANDROID_GUN_LIB_STD_LIB_PATH "${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi" )
SET( ANDROID_GUN_LIB_STD_LIB_PATH_INCLUDE "${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/include" )
SET( ANDROID_PLATFORMS_ANDROID14_INCLUDE "${ANDROID_NDK_ROOT}/platforms/android-14/arch-arm/usr/include" )
SET( ANDROID_PLATFORMS_ANDROID14_LIB "${ANDROID_NDK_ROOT}/platforms/android-14/arch-arm/usr/lib" )
	
MESSAGE( STATUS "ANDROID_NDK_ROOT:" ${ANDROID_NDK_ROOT} )

INCLUDE_DIRECTORIES( ${ANDROID_GUN_LIB_STD_INCLUDE_PATH} )
INCLUDE_DIRECTORIES( ${ANDROID_GUN_LIB_STD_LIB_PATH_INCLUDE} )
INCLUDE_DIRECTORIES( ${ANDROID_PLATFORMS_ANDROID14_INCLUDE} )
LINK_DIRECTORIES( ${ANDROID_PLATFORMS_ANDROID14_LIB} )
LINK_DIRECTORIES( ${ANDROID_GUN_LIB_STD_LIB_PATH} )

### specify output directory
SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/android/" )
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/android/" )
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/android/" )