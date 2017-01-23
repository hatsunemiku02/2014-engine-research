
IF(WINDOWS_BUILD)

ELSEIF(ANDOIRD_BUILD)

ENDIF(WINDOWS_BUILD)

# folder
SET ( _HEADER_FILES 

)

# folder
SET ( _SOURCE_FILES
	Source/FreeImage/BitmapAccess.cpp
	Source/FreeImage/CacheFile.cpp
	Source/FreeImage/ColorLookup.cpp
	Source/FreeImage/Conversion.cpp
	Source/FreeImage/Conversion4.cpp
	Source/FreeImage/Conversion8.cpp
	Source/FreeImage/Conversion16_555.cpp
	Source/FreeImage/Conversion16_565.cpp
	Source/FreeImage/Conversion24.cpp
	Source/FreeImage/Conversion32.cpp
	Source/FreeImage/ConversionRGBF.cpp
	Source/FreeImage/ConversionType.cpp
	Source/FreeImage/FreeImage.cpp
	Source/FreeImage/FreeImageC.c
	Source/FreeImage/FreeImageIO.cpp
	Source/FreeImage/GetType.cpp
	Source/FreeImage/Halftoning.cpp
	Source/FreeImage/J2KHelper.cpp
	Source/FreeImage/MemoryIO.cpp
	Source/FreeImage/MultiPage.cpp
	Source/FreeImage/NNQuantizer.cpp
	Source/FreeImage/PixelAccess.cpp
	Source/FreeImage/Plugin.cpp
	Source/FreeImage/PluginBMP.cpp
	Source/FreeImage/PluginCUT.cpp
	Source/FreeImage/PluginDDS.cpp
	Source/FreeImage/PluginEXR.cpp
	Source/FreeImage/PluginG3.cpp
	Source/FreeImage/PluginGIF.cpp
	Source/FreeImage/PluginHDR.cpp
	Source/FreeImage/PluginICO.cpp
	Source/FreeImage/PluginIFF.cpp
	Source/FreeImage/PluginJ2K.cpp
	Source/FreeImage/PluginJP2.cpp
	Source/FreeImage/PluginJPEG.cpp
	Source/FreeImage/PluginKOALA.cpp
	Source/FreeImage/PluginMNG.cpp
	Source/FreeImage/PluginPCD.cpp
	Source/FreeImage/PluginPCX.cpp
	Source/FreeImage/PluginPNG.cpp
	Source/FreeImage/PluginPNM.cpp
	Source/FreeImage/PluginPSD.cpp
	Source/FreeImage/PluginRAS.cpp
	Source/FreeImage/PluginSGI.cpp
	Source/FreeImage/PluginTARGA.cpp
	Source/FreeImage/PluginTIFF.cpp
	Source/FreeImage/PluginWBMP.cpp
	Source/FreeImage/PluginXBM.cpp
	Source/FreeImage/PluginXPM.cpp
	Source/FreeImage/tmoColorConvert.cpp
	Source/FreeImage/tmoDrago03.cpp
	Source/FreeImage/tmoFattal02.cpp
	Source/FreeImage/tmoReinhard05.cpp
	Source/FreeImage/ToneMapping.cpp
	Source/FreeImage/WuQuantizer.cpp
	Source/FreeImage/ZLibInterface.cpp
	
	Source/DeprecationManager/DeprecationMgr.cpp
	Source/Metadata/Exif.cpp
	Source/Metadata/FIRational.cpp
	Source/Metadata/FreeImageTag.cpp
	Source/Metadata/IPTC.cpp
	Source/Metadata/TagConversion.cpp
	Source/Metadata/TagLib.cpp
	Source/Metadata/XTIFF.cpp
	
	Source/FreeImageToolkit/BSplineRotate.cpp
	Source/FreeImageToolkit/Channels.cpp
	Source/FreeImageToolkit/ClassicRotate.cpp
	Source/FreeImageToolkit/Colors.cpp
	Source/FreeImageToolkit/CopyPaste.cpp
	Source/FreeImageToolkit/Display.cpp
	Source/FreeImageToolkit/Flip.cpp
	Source/FreeImageToolkit/JPEGTransform.cpp
	Source/FreeImageToolkit/MultigridPoissonSolver.cpp
	Source/FreeImageToolkit/Rescale.cpp
	Source/FreeImageToolkit/Resize.cpp
)
#<-------- Additional Include Directories ------------------>
INCLUDE_DIRECTORIES(
	Source
	Source/ZLib
	Source/DeprecationManager
	Source/OpenEXR/Half
	Source/OpenEXR/Iex
	Source/OpenEXR/IlmImf
	Source/OpenEXR/Imath
	Source/OpenEXR/IlmThread
)
IF(ANDROID_BUILD)
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -landroid -llog -lc -lm " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-soname,libFreeImaged -Wl,--no-undefined" )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -shared -Wl,-z,noexecstack " )
SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lgnustl_static -lgcc" )
ENDIF(ANDROID_BUILD)

ADD_LIBRARY( 
	FreeImaged 
	SHARED
	#head
	${_HEADER_FILES}
	#source
	${_SOURCE_FILES}
)
IF(ANDROID_BUILD)
TARGET_LINK_LIBRARIES(
#target
	FreeImaged
	LibJPEG
	LibMNG
	LibOpenJPEG
	LibPNG
	LibTIFF
	OpenEXR
	ZLib
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libsupc++.a
	${ANDROID_NDK_ROOT}/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a 
)
ELSE(ANDROID_BUILD)
TARGET_LINK_LIBRARIES(
#target
	FreeImaged
	LibJPEG
	LibMNG
	LibOpenJPEG
	LibPNG
	LibTIFF
	OpenEXR
	ZLib
)
ENDIF(ANDROID_BUILD)

ADD_DEFINITIONS(
	-D_USRDLL
	-DOPJ_STATIC
	-DFREEIMAGE_EXPORTS
	-D_CRT_SECURE_NO_DEPRECATE
)


#Organize projects into folders
SET_PROPERTY(TARGET FreeImaged PROPERTY FOLDER "2.Externals/FreeImage")


