
IF(WINDOWS_BUILD)

ELSEIF(ANDOIRD_BUILD)

ENDIF(WINDOWS_BUILD)

# folder
SET ( _HEADER_FILES 
cderror.h
cdjpeg.h
jchuff.h
jconfig.h
jdct.h
jdhuff.h
jerror.h
jinclude.h
jmemsys.h
jmorecfg.h
jpegint.h
jpeglib.h
jversion.h
transupp.h
)

# folder
SET ( _SOURCE_FILES
cdjpeg.c
cjpeg.c
ckconfig.c
djpeg.c
example.c
jcapimin.c
jcapistd.c
jccoefct.c
jccolor.c
jcdctmgr.c
jchuff.c
jcmainct.c
jcinit.c
jcmarker.c
jcmaster.c
jcomapi.c
jcparam.c
jcphuff.c
jcprepct.c
jcsample.c
jctrans.c
jdapimin.c
jdapistd.c
jccoefct.c
jccolor.c
jcdctmgr.c
jchuff.c
jcinit.c
jcmainct.c
jcmarker.c
jcmaster.c
jcomapi.c
jcparam.c
jcphuff.c
jcprepct.c
jcsample.c
jctrans.c
jdapimin.c
jdapistd.c
jdatadst.c
jdatasrc.c
jdcoefct.c
jdcolor.c
jddctmgr.c
jdhuff.c
jdinput.c
jdmainct.c
jdmarker.c
jdmaster.c
jdmerge.c
jdphuff.c
jdpostct.c
jdsample.c
jdtrans.c
jerror.c
jfdctflt.c
jfdctfst.c
jfdctint.c
jidctflt.c
jidctfst.c
jidctfst.c
jidctint.c
jidctred.c
jmemmgr.c
jmemnobs.c
jpegtran.c
jquant1.c
jquant2.c
jutils.c
rdbmp.c
rdcolmap.c
rdgif.c
rdjpgcom.c
rdppm.c
rdrle.c
rdswitch.c
rdtarga.c
transupp.c
wrbmp.c
wrgif.c
wrjpgcom.c
wrppm.c
wrrle.c
wrtarga.c
)
#<-------- Additional Include Directories ------------------>
INCLUDE_DIRECTORIES(
	
)

ADD_LIBRARY( 
	LibJPEG
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}

)

ADD_DEFINITIONS(
	-D_UNICODE
	-DUNICODE
	-D_LIB
    -D_CRT_SECURE_NO_DEPRECATE
)


#Organize projects into folders
SET_PROPERTY(TARGET LibJPEG PROPERTY FOLDER "2.Externals/FreeImage")


