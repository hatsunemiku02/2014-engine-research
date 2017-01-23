

SET(GRA_INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/CATFISH/GlesSyetem)
SET(IO_INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/CATFISH/IO)
SET(FI_INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/FreeImage/Source)

IF(WINDOWS_BUILD)
SET(ALL_LIB_DIR ${PROJECT_SOURCE_DIR}/Bin/Win)
ELSE(WINDOWS_BUILD)
SET(ALL_LIB_DIR ${PROJECT_SOURCE_DIR}/Bin/android/)
ENDIF(WINDOWS_BUILD)


MESSAGE( STATUS "GRA_INCLUDE_DIR:" ${GRA_INCLUDE_DIR} )	
MESSAGE( STATUS "IO_INCLUDE_DIR:" ${IO_INCLUDE_DIR} )	
MESSAGE( STATUS "FI_INCLUDE_DIR:" ${FI_INCLUDE_DIR} )	

MESSAGE( STATUS "ALL_LIB_DIR:" ${ALL_LIB_DIR} )

INCLUDE_DIRECTORIES(
	${GRA_INCLUDE_DIR} 
	${IO_INCLUDE_DIR}
	${FI_INCLUDE_DIR}
)
LINK_DIRECTORIES( ${ALL_LIB_DIR} )


# folder
SET ( _HEADER_FILES 
	ImagePhaser.h
	ImageRes.h
	RDllCommon.h
	Res.h
	ResMgr.h
	ObjMeshPhraser.h
	MeshRes.h
)

# folder
SET ( _SOURCE_FILES
	ImagePhaser.cpp
	ImageRes.cpp
	Res.cpp
	ResMgr.cpp
	ObjMeshPhraser.h
	MeshRes.h
)
#<-------- Additional Include Directories ------------------>
IF(ANDROID_BUILD)
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -landroid -lGLESv2 -lEGL -llog -lc -lm" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-soname,libResourcePhraser -Wl,--no-undefined" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -shared -Wl,-z,noexecstack " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lgnustl_static -lgcc" )
ENDIF(ANDROID_BUILD)

ADD_LIBRARY( 
	ResourcePhraser
	SHARED
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)
IF(WIN32)
TARGET_LINK_LIBRARIES(
#target
	ResourcePhraser
	GlesSystem.lib
	IO.lib
	FreeImaged.lib
)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(
#target
	ResourcePhraser
	${ALL_LIB_DIR}/libGlesSystem.so
	${ALL_LIB_DIR}/libIO.so
	${ALL_LIB_DIR}/libFreeImaged.so
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a 
)
ENDIF(WIN32)

ADD_DEPENDENCIES(
	ResourcePhraser
	IO
	FreeImaged
)

ADD_DEFINITIONS(

)



#Organize projects into folders
SET_PROPERTY(TARGET ResourcePhraser PROPERTY FOLDER "3.Modules")


