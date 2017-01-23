
IF(WINDOWS_BUILD)

ELSEIF(ANDOIRD_BUILD)

ENDIF(WINDOWS_BUILD)

# folder
SET ( _HEADER_FILES 
bio.h            
cio.h            
dwt.h            
event.h
fix.h            
image.h          
int.h            
j2k.h
j2k_lib.h        
jp2.h            
jpt.h            
mct.h
mqc.h            
openjpeg.h       
opj_includes.h   
pi.h
raw.h           
t1.h             
t1_luts.h        
t2.h
tcd.h            
tgt.h     
)

# folder
SET ( _SOURCE_FILES
bio.c                
cio.c                
dwt.c
event.c              
image.c              
j2k.c
j2k_lib.c            
jp2.c                
jpt.c
mct.c                
mqc.c                
openjpeg.c
pi.c                 
raw.c                
t1.c
t1_generate_luts.c   
t2.c                 
tcd.c
tgt.c        
)
#<-------- Additional Include Directories ------------------>
INCLUDE_DIRECTORIES(
	
)

ADD_LIBRARY( 
	LibOpenJPEG
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)

ADD_DEFINITIONS(
	-D_LIB
	-DOPJ_STATIC
	-D_CRT_SECURE_NO_DEPRECATE
)


#Organize projects into folders
SET_PROPERTY(TARGET LibOpenJPEG PROPERTY FOLDER "2.Externals/FreeImage")


