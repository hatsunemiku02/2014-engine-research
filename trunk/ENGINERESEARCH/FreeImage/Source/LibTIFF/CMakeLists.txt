
IF(WINDOWS_BUILD)

ELSEIF(ANDOIRD_BUILD)

ENDIF(WINDOWS_BUILD)
INCLUDE_DIRECTORIES(
../libtiff/libtiff
)
# folder
SET ( _HEADER_FILES 
t4.h                 
tiff.h               
tiffconf.vc.h
tiffconf.wince.h    
tiffio.h            
tiffiop.h
tiffvers.h           
tif_config.h         
tif_config.vc.h
tif_config.wince.h   
tif_dir.h            
tif_fax3.h
tif_predict.h        
uvcode.h      
)

# folder
SET ( _SOURCE_FILES    
mkspans.c                    
tif_aux.c         
tif_close.c       
tif_codec.c
tif_color.c      
tif_compress.c    
tif_dir.c         
tif_dirinfo.c
tif_dirread.c     
tif_dirwrite.c    
tif_dumpmode.c    
tif_error.c
tif_extension.c   
tif_fax3.c        
tif_fax3sm.c      
tif_flush.c
tif_getimage.c    
tif_jbig.c        
tif_jpeg.c        
tif_luv.c
tif_lzw.c         
tif_next.c        
tif_ojpeg.c
tif_open.c        
tif_packbits.c    
tif_pixarlog.c    
tif_predict.c
tif_print.c       
tif_read.c        
tif_strip.c       
tif_swab.c
tif_thunder.c     
tif_tile.c               
tif_version.c       
tif_warning.c  
tif_write.c       
tif_zip.c       
)
# folder
IF(WIN32)
SET ( _P_SOURCE_FILES
tif_msdos.c          
tif_win32.c   
)   
ENDIF(WIN32)

IF(ANDOIRD_BUILD)
SET ( _P_SOURCE_FILES
tif_unix.c 
) 
ENDIF(ANDOIRD_BUILD)
#<-------- Additional Include Directories ------------------>
INCLUDE_DIRECTORIES(
	
)

ADD_LIBRARY( 
	LibTIFF
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}
	${_P_SOURCE_FILES}
)

ADD_DEFINITIONS(
	-D_LIB
    -D_CRT_SECURE_NO_DEPRECATE
)


#Organize projects into folders
SET_PROPERTY(TARGET LibTIFF PROPERTY FOLDER "2.Externals/FreeImage")