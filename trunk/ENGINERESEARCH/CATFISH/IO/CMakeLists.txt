MACRO( _MACRO_EXECUTABLE_BASE_LIB arg_TargetName )
TARGET_LINK_LIBRARIES(
)

ENDMACRO ( _MACRO_EXECUTABLE_BASE_LIB )



# folder
SET ( _HEADER_FILES 
	FileReader.h
	IODLLCOMMON.h
)

# folder
SET ( _SOURCE_FILES
	FileReader.cpp
)
#<-------- Additional Include Directories ------------------>
IF(ANDROID_BUILD)
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -landroid -lGLESv2 -lEGL -llog -lc -lm" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-soname,libLua -Wl,--no-undefined" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -shared -Wl,-z,noexecstack " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lgnustl_static -lgcc" )
ENDIF(ANDROID_BUILD)

IF(ANDROID_BUILD)
ADD_LIBRARY( 
	IO 
	SHARED
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libsupc++.a
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a 
)
ELSE(ANDROID_BUILD)
ADD_LIBRARY( 
	IO 
	SHARED
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}
)
ENDIF()

#generate debug information
FOREACH( flag_var
		CMAKE_EXE_LINKER_FLAGS
		CMAKE_EXE_LINKER_FLAGS_DEBUG
		CMAKE_EXE_LINKER_FLAGS_RELEASE
)

IF( NOT ${flag_var} MATCHES "/DEBUG" )	
	#force update this on the CMAKE GUI
	SET( ${flag_var} "${${flag_var}} /DEBUG" CACHE STRING "" FORCE)	
ENDIF( NOT ${flag_var} MATCHES "/DEBUG" )
ENDFOREACH( flag_var )


#Organize projects into folders
SET_PROPERTY(TARGET IO PROPERTY FOLDER "1.Base")


