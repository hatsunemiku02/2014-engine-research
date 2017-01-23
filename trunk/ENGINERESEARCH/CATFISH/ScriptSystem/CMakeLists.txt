

SET(LUA_INCLUDE_DIR  ${PROJECT_SOURCE_DIR}/lua-5.2.2/src)
IF(WINDOWS_BUILD)
SET(LUA_LIB_DIR ${PROJECT_SOURCE_DIR}/Bin/Win)
ELSE(WINDOWS_BUILD)
SET(LUA_LIB_DIR ${PROJECT_SOURCE_DIR}/Bin/android/)
ENDIF(WINDOWS_BUILD)


MESSAGE( STATUS "LUA_INCLUDE_DIR:" ${LUA_INCLUDE_DIR} )	
MESSAGE( STATUS "LUA_LIB_DIR:" ${LUA_LIB_DIR} )

INCLUDE_DIRECTORIES( ${LUA_INCLUDE_DIR} )
LINK_DIRECTORIES( ${LUA_LIB_DIR} )


# folder
SET ( _HEADER_FILES 
	SDLLCommon.h
	LuaDomain.h
	LuaRootScript.h
	LuaScript.h
	LuaUtitly.h
	ScriptDefines.h
	ScriptFooWarpper.h
	ScriptObjWarpper.h
	ScriptSys.h
)

# folder
SET ( _SOURCE_FILES
	LuaDomain.cpp
	LuaRootScript.cpp
	LuaScript.cpp
	LuaUtitly.cpp
	ScriptFooWarpper.cpp
	ScriptObjWarpper.cpp
	ScriptSys.cpp
)
#<-------- Additional Include Directories ------------------>
IF(ANDROID_BUILD)
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -landroid -lGLESv2 -lEGL -llog -lc -lm" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-soname,libScriptSystem -Wl,--no-undefined" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -shared -Wl,-z,noexecstack " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lgnustl_static -lgcc" )
ENDIF(ANDROID_BUILD)

ADD_LIBRARY( 
	ScriptSystem 
	SHARED
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)
ADD_DEPENDENCIES(
	ScriptSystem
	Lua
)

IF(WIN32)
TARGET_LINK_LIBRARIES(
#target
	ScriptSystem
	Lua.lib
)
ELSE(WIN32)
TARGET_LINK_LIBRARIES(
#target
	ScriptSystem
	${LUA_LIB_DIR}/libLua.so
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a 
)
ENDIF(WIN32)



ADD_DEFINITIONS(

)


#Organize projects into folders
SET_PROPERTY(TARGET ScriptSystem PROPERTY FOLDER "3.Modules")


