# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = E:/androidDevTools/cmake-2.8.8-win32-x86/bin/cmake.exe

# The command to remove a file.
RM = E:/androidDevTools/cmake-2.8.8-win32-x86/bin/cmake.exe -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = E:/androidDevTools/cmake-2.8.8-win32-x86/bin/cmake-gui.exe

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:/DONOTOPEN/FUCKYOU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:/DONOTOPEN/FUCKYOU/ANDROID

# Include any dependencies generated for this target.
include CATFISH/DemoA/CMakeFiles/Demo.dir/depend.make

# Include the progress variables for this target.
include CATFISH/DemoA/CMakeFiles/Demo.dir/progress.make

# Include the compile flags for this target's objects.
include CATFISH/DemoA/CMakeFiles/Demo.dir/flags.make

CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o: CATFISH/DemoA/CMakeFiles/Demo.dir/flags.make
CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o: ../CATFISH/DemoA/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o"
	cd CATFISH/DemoA && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Demo.dir/main.cpp.o -c ../../../CATFISH/DemoA/main.cpp

CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Demo.dir/main.cpp.i"
	cd CATFISH/DemoA && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E ../../../CATFISH/DemoA/main.cpp > CMakeFiles/Demo.dir/main.cpp.i

CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Demo.dir/main.cpp.s"
	cd CATFISH/DemoA && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S ../../../CATFISH/DemoA/main.cpp -o CMakeFiles/Demo.dir/main.cpp.s

CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.requires:
.PHONY : CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.requires

CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.provides: CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.requires
	$(MAKE) -f CATFISH/DemoA/CMakeFiles/Demo.dir/build.make CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.provides.build
.PHONY : CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.provides

CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.provides.build: CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o

# Object files for target Demo
Demo_OBJECTS = \
"CMakeFiles/Demo.dir/main.cpp.o"

# External object files for target Demo
Demo_EXTERNAL_OBJECTS =

../Bin/android/libDemo.so: CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o
../Bin/android/libDemo.so: CATFISH/DemoA/CMakeFiles/Demo.dir/build.make
../Bin/android/libDemo.so: ../Bin/android/libGlesSystem.so
../Bin/android/libDemo.so: ../Bin/android/libIO.so
../Bin/android/libDemo.so: ../Bin/android/libResourcePhraser.so
../Bin/android/libDemo.so: ../Bin/android/libScriptSystem.so
../Bin/android/libDemo.so: ../Bin/android/libSoundSystem.so
../Bin/android/libDemo.so: D:/Android/android-ndk-r8d/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../../Bin/android/libDemo.so"
	cd CATFISH/DemoA && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-g++.exe  -fPIC  -frtti -fexceptions  -Wfatal-errors -g  -Wl,--fix-cortex-a8 -LD:/Android/android-ndk-r8d/platforms/android-14/arch-arm/usr/lib --sysroot=D:/Android/android-ndk-r8d/platforms/android-14/arch-arm/usr/lib/../..  -landroid -lGLESv2 -lEGL -llog -lc -lm -Wl,-soname,libDemo -Wl,--no-undefined   -shared -Wl,-z,noexecstack  -lgnustl_static -lgcc -shared -Wl,-soname,libDemo.so -o ../../../Bin/android/libDemo.so $(Demo_OBJECTS) $(Demo_EXTERNAL_OBJECTS) -LD:/Android/android-ndk-r8d/platforms/android-14/arch-arm/usr/lib -LD:/Android/android-ndk-r8d/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi -L../../../Bin/android -lGlesSystem -lIO -lResourcePhraser -lScriptSystem -lSoundSystem D:/Android/android-ndk-r8d/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi/libgnustl_static.a -Wl,-rpath,D:/Android/android-ndk-r8d/platforms/android-14/arch-arm/usr/lib:D:/Android/android-ndk-r8d/sources/cxx-stl/gnu-libstdc++/4.4.3/libs/armeabi:E:/DONOTOPEN/FUCKYOU/Bin/android 

# Rule to build all files generated by this target.
CATFISH/DemoA/CMakeFiles/Demo.dir/build: ../Bin/android/libDemo.so
.PHONY : CATFISH/DemoA/CMakeFiles/Demo.dir/build

CATFISH/DemoA/CMakeFiles/Demo.dir/requires: CATFISH/DemoA/CMakeFiles/Demo.dir/main.cpp.o.requires
.PHONY : CATFISH/DemoA/CMakeFiles/Demo.dir/requires

CATFISH/DemoA/CMakeFiles/Demo.dir/clean:
	cd CATFISH/DemoA && $(CMAKE_COMMAND) -P CMakeFiles/Demo.dir/cmake_clean.cmake
.PHONY : CATFISH/DemoA/CMakeFiles/Demo.dir/clean

CATFISH/DemoA/CMakeFiles/Demo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" E:/DONOTOPEN/FUCKYOU E:/DONOTOPEN/FUCKYOU/CATFISH/DemoA E:/DONOTOPEN/FUCKYOU/ANDROID E:/DONOTOPEN/FUCKYOU/ANDROID/CATFISH/DemoA E:/DONOTOPEN/FUCKYOU/ANDROID/CATFISH/DemoA/CMakeFiles/Demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CATFISH/DemoA/CMakeFiles/Demo.dir/depend

