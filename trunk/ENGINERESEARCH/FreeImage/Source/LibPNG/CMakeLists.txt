
IF(WINDOWS_BUILD)

ELSEIF(ANDOIRD_BUILD)

ENDIF(WINDOWS_BUILD)
INCLUDE_DIRECTORIES(
../ZLib
)
# folder
SET ( _HEADER_FILES 
png.h       
pngconf.h    
)

# folder
SET ( _SOURCE_FILES
png.c        
pngerror.c   
pnggccrd.c   
pngget.c     
pngmem.c     
pngpread.c
pngread.c    
pngrio.c     
pngrtran.c   
pngrutil.c   
pngset.c     
pngtest.c
pngtrans.c   
pngvcrd.c    
pngwio.c     
pngwrite.c   
pngwtran.c   
pngwutil.c        
)
#<-------- Additional Include Directories ------------------>
INCLUDE_DIRECTORIES(
	
)

ADD_LIBRARY( 
	LibPNG
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)

ADD_DEFINITIONS(
)


#Organize projects into folders
SET_PROPERTY(TARGET LibPNG PROPERTY FOLDER "2.Externals/FreeImage")


