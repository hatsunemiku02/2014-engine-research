
SET(GLESEmulator_INCLUDE_DIR     ${PROJECT_SOURCE_DIR}/OpenSL/Include)

SET(GLESEmulator_LIB_DIR ${PROJECT_SOURCE_DIR}/OpenSL/Lib)

MESSAGE( STATUS "SLESEmulator_INCLUDE_DIR:" ${SLESEmulator_INCLUDE_DIR} )	
MESSAGE( STATUS "SLESEmulator_LIB_DIR:" ${SLESEmulator_LIB_DIR} )
IF(ANDROID_BUILD)
ELSE(ANDROID_BUILD)
INCLUDE_DIRECTORIES( ${GLESEmulator_INCLUDE_DIR} )
LINK_DIRECTORIES( ${GLESEmulator_LIB_DIR} )
ENDIF(ANDROID_BUILD)

# folder
SET ( _HEADER_FILES 
	SoundData.h
	SoundDecoderSL.h
	SoundDllCommon.h
	SoundSL.h
	Sound.h
	SoundSystemSL.h
	SoundSystem.h
)

# folder
SET ( _SOURCE_FILES
	SoundSystemSL.cpp
	SoundSL.cpp
	Sound.cpp
	SoundDecoderSL.cpp
	SoundSystem.cpp
)
#<-------- Additional Include Directories ------------------>
IF(ANDROID_BUILD)
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -landroid -llog -lc -lm -lOpenSLES" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-soname,libSoundSystem -Wl,--no-undefined " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -shared -Wl,-z,noexecstack " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lgnustl_static -lgcc" )
ENDIF(ANDROID_BUILD)

ADD_LIBRARY( 
	SoundSystem 
	SHARED
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)
IF(ANDROID_BUILD)
TARGET_LINK_LIBRARIES(
#target
	SoundSystem
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libsupc++.a
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a 
)
ELSE(ANDROID_BUILD)
TARGET_LINK_LIBRARIES(
#target
	SoundSystem
)
ENDIF(ANDROID_BUILD)


#Organize projects into folders
SET_PROPERTY(TARGET GlesSystem PROPERTY FOLDER "3.Modules")
ADD_CUSTOM_COMMAND(
	TARGET GenesisA
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${param_TargetFullPath} ${CMAKE_SOURCE_DIR}/ANDROID_SHELL/proj.android/libs/armeabi )

