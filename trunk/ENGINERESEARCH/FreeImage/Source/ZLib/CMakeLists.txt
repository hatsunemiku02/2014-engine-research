
IF(WINDOWS_BUILD)

ELSEIF(ANDOIRD_BUILD)

ENDIF(WINDOWS_BUILD)

# folder
SET ( _HEADER_FILES 
crc32.h      
deflate.h    
inffast.h    
inffixed.h   
inflate.h    
inftrees.h
trees.h      
zconf.h      
zconf.in.h   
zlib.h       
zutil.h 
)

# folder
SET ( _SOURCE_FILES
adler32.c    
compress.c   
crc32.c      
deflate.c    
example.c    
gzio.c
infback.c    
inffast.c    
inflate.c    
inftrees.c   
minigzip.c   
trees.c
uncompr.c    
zutil.c 
)
#<-------- Additional Include Directories ------------------>
INCLUDE_DIRECTORIES(
	
)

ADD_LIBRARY( 
	ZLib
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)

ADD_DEFINITIONS(
	-D_UNICODE
	-DUNICODE
)


#Organize projects into folders
SET_PROPERTY(TARGET ZLib PROPERTY FOLDER "2.Externals/FreeImage")


