

# let releae build typed generate debug information 
SET( RELEASE_BUILD_TYPE_GENERATE_DEBUG_INFORMATION ON )

SET_PROPERTY( GLOBAL PROPERTY DEBUG_CONFIGURATIONS "Debug" )
 
###SET the configuration types
IF ( CMAKE_CONFIGURATION_TYPES )

	SET( CMAKE_CONFIGURATION_TYPES Debug Release)
	SET( CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
	"Reset the configurations to what we need"
	FORCE )

ENDIF( CMAKE_CONFIGURATION_TYPES )

###multi thread
FOREACH( flag_var
		CMAKE_CXX_FLAGS
		CMAKE_CXX_FLAGS_DEBUG
		CMAKE_CXX_FLAGS_RELEASE
		)

IF( ${flag_var} MATCHES "/MT" )
	STRING( REGEX REPLACE "/MT" "/MD" ${flag_var} "${${flag_var}}" )
	#force update this on the CMAKE GUI
	SET(${flag_var} "${${flag_var}}" CACHE STRING
	"Reset the configurations to what we need"
	FORCE )

ENDIF( ${flag_var} MATCHES "/MT" )

IF( ${flag_var} MATCHES "/MTd" )
	STRING( REGEX REPLACE "/MTd" "/MDd" ${flag_var} "${${flag_var}}" )
	#force update this on the CMAKE GUI
	SET(${flag_var} "${${flag_var}}" CACHE STRING
	"Reset the configurations to what we need"
	FORCE )
ENDIF( ${flag_var} MATCHES "/MTd" )

ENDFOREACH( flag_var )

### let release build type generate debug information
IF ( ${RELEASE_BUILD_TYPE_GENERATE_DEBUG_INFORMATION} )
	FOREACH( flag_var
			CMAKE_CXX_FLAGS_RELEASE
	)

	IF( NOT ${flag_var} MATCHES "/Zi" )
		
		SET( ${flag_var} "${${flag_var}} /Zi" CACHE STRING 
		"Let release build type generate debug info"
		FORCE )
		
	ENDIF( NOT ${flag_var} MATCHES "/Zi" )
	ENDFOREACH( flag_var )
ENDIF ( ${RELEASE_BUILD_TYPE_GENERATE_DEBUG_INFORMATION} )

#Organize projects into folders
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

#Add definitions
ADD_DEFINITIONS(
	-D__WIN32__
	-DWIN32 )
		
### specify output directory
SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/Win" )
SET( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/Win" )
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/Bin/Win" )

