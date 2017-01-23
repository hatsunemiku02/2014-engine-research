


# Get environment variable, define it as ENV_$var and make sure backslashes are converted to forward slashes
MACRO( _MACRO_GETENV_PATH VAR )
	SET( ENV_${VAR} $ENV{${VAR}} )

	# replace won't work IF var is blank
	IF ( ENV_${VAR} )
	 STRING( REGEX REPLACE "\\\\" "/" ENV_${VAR} ${ENV_${VAR}} )
	ENDIF ( ENV_${VAR} )	   
ENDMACRO(_MACRO_GETENV_PATH)

#treat warring as error
MACRO( _MACRO_TREAT_WARRINGS_AS_ERRORS arg_TargetName )
IF ( GCC_COMPILER )
	#SunHao TODO: too many warrings, so just comment it. Recovery it later. 2013.3.6
    #SET (WARRING_AS_ERROR_PARAM "-Werror" )
    SET (WARRING_AS_ERROR_PARAM " " ) #give a null value to make CMake.exe happy
ENDIF( GCC_COMPILER )
	
IF ( MS_COMPILER )
    SET (WARRING_AS_ERROR_PARAM "/WX" )
ENDIF( MS_COMPILER )

	SET_TARGET_PROPERTIES( 	${arg_TargetName}
							PROPERTIES
							COMPILE_FLAGS ${WARRING_AS_ERROR_PARAM} )
							
ENDMACRO( _MACRO_TREAT_WARRINGS_AS_ERRORS )