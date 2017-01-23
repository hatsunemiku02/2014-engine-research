
SET(GLESEmulator_INCLUDE_DIR     ${PROJECT_SOURCE_DIR}/GLESEmulator/Include)

SET(GLESEmulator_LIB_DIR ${PROJECT_SOURCE_DIR}/GLESEmulator/Lib)

MESSAGE( STATUS "GLESEmulator_INCLUDE_DIR:" ${GLESEmulator_INCLUDE_DIR} )	
MESSAGE( STATUS "GLESEmulator_LIB_DIR:" ${GLESEmulator_LIB_DIR} )
IF(ANDROID_BUILD)
ELSE(ANDROID_BUILD)
INCLUDE_DIRECTORIES( ${GLESEmulator_INCLUDE_DIR} )
LINK_DIRECTORIES( ${GLESEmulator_LIB_DIR} )
ENDIF(ANDROID_BUILD)

# folder
SET ( _HEADER_FILES 
	DrawEnums.h
	FrameBufferObj.h
	GDllCommon.h
	GDebug.h
	GlesDevice.h
	GpuProgram.h
	IndexBufferObj.h
	Shader.h
	Texture.h
	VertexBufferObj.h
	VertexComponent.h
	VertexLayout.h
	PrimitiveGroup.h

)

# folder
SET ( _SOURCE_FILES
	GDebug.cpp
	DrawEnums.cpp
	FrameBufferObj.cpp
	GlesDevice.cpp
	GpuProgram.cpp
	IndexBufferObj.cpp
	Shader.cpp
	Texture.cpp
	VertexBufferObj.cpp
	VertexComponent.cpp
	VertexLayout.cpp
	PrimitiveGroup.cpp
)
#<-------- Additional Include Directories ------------------>
IF(ANDROID_BUILD)
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -landroid -lGLESv2 -lEGL -llog -lc -lm" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-soname,libGlesSystem -Wl,--no-undefined " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -shared -Wl,-z,noexecstack " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lgnustl_static -lgcc" )
ENDIF(ANDROID_BUILD)

ADD_LIBRARY( 
	GlesSystem 
	SHARED
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)
IF(ANDROID_BUILD)
TARGET_LINK_LIBRARIES(
#target
	GlesSystem
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libsupc++.a
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a 
)
ELSE(ANDROID_BUILD)
TARGET_LINK_LIBRARIES(
#target
	GlesSystem
	libEGL.lib
	libGLESv2.lib
)
ENDIF(ANDROID_BUILD)
ADD_DEFINITIONS(
)


#Organize projects into folders
SET_PROPERTY(TARGET GlesSystem PROPERTY FOLDER "3.Modules")
ADD_CUSTOM_COMMAND(
	TARGET GenesisA
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${param_TargetFullPath} ${CMAKE_SOURCE_DIR}/ANDROID_SHELL/proj.android/libs/armeabi )

