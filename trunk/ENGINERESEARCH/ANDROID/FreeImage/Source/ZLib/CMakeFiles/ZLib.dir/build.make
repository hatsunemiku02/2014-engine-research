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
include FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/depend.make

# Include the progress variables for this target.
include FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/progress.make

# Include the compile flags for this target's objects.
include FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o: ../FreeImage/Source/ZLib/adler32.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/adler32.c.o   -c ../../../../FreeImage/Source/ZLib/adler32.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/adler32.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/adler32.c > CMakeFiles/ZLib.dir/adler32.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/adler32.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/adler32.c -o CMakeFiles/ZLib.dir/adler32.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o: ../FreeImage/Source/ZLib/compress.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/compress.c.o   -c ../../../../FreeImage/Source/ZLib/compress.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/compress.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/compress.c > CMakeFiles/ZLib.dir/compress.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/compress.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/compress.c -o CMakeFiles/ZLib.dir/compress.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o: ../FreeImage/Source/ZLib/crc32.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/crc32.c.o   -c ../../../../FreeImage/Source/ZLib/crc32.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/crc32.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/crc32.c > CMakeFiles/ZLib.dir/crc32.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/crc32.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/crc32.c -o CMakeFiles/ZLib.dir/crc32.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o: ../FreeImage/Source/ZLib/deflate.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/deflate.c.o   -c ../../../../FreeImage/Source/ZLib/deflate.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/deflate.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/deflate.c > CMakeFiles/ZLib.dir/deflate.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/deflate.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/deflate.c -o CMakeFiles/ZLib.dir/deflate.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o: ../FreeImage/Source/ZLib/example.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/example.c.o   -c ../../../../FreeImage/Source/ZLib/example.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/example.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/example.c > CMakeFiles/ZLib.dir/example.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/example.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/example.c -o CMakeFiles/ZLib.dir/example.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o: ../FreeImage/Source/ZLib/gzio.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/gzio.c.o   -c ../../../../FreeImage/Source/ZLib/gzio.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/gzio.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/gzio.c > CMakeFiles/ZLib.dir/gzio.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/gzio.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/gzio.c -o CMakeFiles/ZLib.dir/gzio.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o: ../FreeImage/Source/ZLib/infback.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/infback.c.o   -c ../../../../FreeImage/Source/ZLib/infback.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/infback.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/infback.c > CMakeFiles/ZLib.dir/infback.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/infback.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/infback.c -o CMakeFiles/ZLib.dir/infback.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o: ../FreeImage/Source/ZLib/inffast.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/inffast.c.o   -c ../../../../FreeImage/Source/ZLib/inffast.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/inffast.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/inffast.c > CMakeFiles/ZLib.dir/inffast.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/inffast.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/inffast.c -o CMakeFiles/ZLib.dir/inffast.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o: ../FreeImage/Source/ZLib/inflate.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/inflate.c.o   -c ../../../../FreeImage/Source/ZLib/inflate.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/inflate.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/inflate.c > CMakeFiles/ZLib.dir/inflate.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/inflate.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/inflate.c -o CMakeFiles/ZLib.dir/inflate.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o: ../FreeImage/Source/ZLib/inftrees.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/inftrees.c.o   -c ../../../../FreeImage/Source/ZLib/inftrees.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/inftrees.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/inftrees.c > CMakeFiles/ZLib.dir/inftrees.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/inftrees.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/inftrees.c -o CMakeFiles/ZLib.dir/inftrees.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o: ../FreeImage/Source/ZLib/minigzip.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/minigzip.c.o   -c ../../../../FreeImage/Source/ZLib/minigzip.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/minigzip.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/minigzip.c > CMakeFiles/ZLib.dir/minigzip.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/minigzip.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/minigzip.c -o CMakeFiles/ZLib.dir/minigzip.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o: ../FreeImage/Source/ZLib/trees.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/trees.c.o   -c ../../../../FreeImage/Source/ZLib/trees.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/trees.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/trees.c > CMakeFiles/ZLib.dir/trees.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/trees.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/trees.c -o CMakeFiles/ZLib.dir/trees.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o: ../FreeImage/Source/ZLib/uncompr.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/uncompr.c.o   -c ../../../../FreeImage/Source/ZLib/uncompr.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/uncompr.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/uncompr.c > CMakeFiles/ZLib.dir/uncompr.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/uncompr.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/uncompr.c -o CMakeFiles/ZLib.dir/uncompr.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/flags.make
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o: ../FreeImage/Source/ZLib/zutil.c
	$(CMAKE_COMMAND) -E cmake_progress_report E:/DONOTOPEN/FUCKYOU/ANDROID/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/ZLib.dir/zutil.c.o   -c ../../../../FreeImage/Source/ZLib/zutil.c

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ZLib.dir/zutil.c.i"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -E ../../../../FreeImage/Source/ZLib/zutil.c > CMakeFiles/ZLib.dir/zutil.c.i

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ZLib.dir/zutil.c.s"
	cd FreeImage/Source/ZLib && D:/Android/android-ndk-r8d/toolchains/arm-linux-androideabi-4.4.3/prebuilt/windows/bin/arm-linux-androideabi-gcc.exe  $(C_DEFINES) $(C_FLAGS) -S ../../../../FreeImage/Source/ZLib/zutil.c -o CMakeFiles/ZLib.dir/zutil.c.s

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.requires:
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.provides: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.requires
	$(MAKE) -f FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.provides.build
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.provides

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.provides.build: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o

# Object files for target ZLib
ZLib_OBJECTS = \
"CMakeFiles/ZLib.dir/adler32.c.o" \
"CMakeFiles/ZLib.dir/compress.c.o" \
"CMakeFiles/ZLib.dir/crc32.c.o" \
"CMakeFiles/ZLib.dir/deflate.c.o" \
"CMakeFiles/ZLib.dir/example.c.o" \
"CMakeFiles/ZLib.dir/gzio.c.o" \
"CMakeFiles/ZLib.dir/infback.c.o" \
"CMakeFiles/ZLib.dir/inffast.c.o" \
"CMakeFiles/ZLib.dir/inflate.c.o" \
"CMakeFiles/ZLib.dir/inftrees.c.o" \
"CMakeFiles/ZLib.dir/minigzip.c.o" \
"CMakeFiles/ZLib.dir/trees.c.o" \
"CMakeFiles/ZLib.dir/uncompr.c.o" \
"CMakeFiles/ZLib.dir/zutil.c.o"

# External object files for target ZLib
ZLib_EXTERNAL_OBJECTS =

../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build.make
../Bin/android/libZLib.a: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library ../../../../Bin/android/libZLib.a"
	cd FreeImage/Source/ZLib && $(CMAKE_COMMAND) -P CMakeFiles/ZLib.dir/cmake_clean_target.cmake
	cd FreeImage/Source/ZLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ZLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build: ../Bin/android/libZLib.a
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/build

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/adler32.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/compress.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/crc32.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/deflate.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/example.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/gzio.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/infback.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inffast.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inflate.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/inftrees.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/minigzip.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/trees.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/uncompr.c.o.requires
FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires: FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/zutil.c.o.requires
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/requires

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/clean:
	cd FreeImage/Source/ZLib && $(CMAKE_COMMAND) -P CMakeFiles/ZLib.dir/cmake_clean.cmake
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/clean

FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" E:/DONOTOPEN/FUCKYOU E:/DONOTOPEN/FUCKYOU/FreeImage/Source/ZLib E:/DONOTOPEN/FUCKYOU/ANDROID E:/DONOTOPEN/FUCKYOU/ANDROID/FreeImage/Source/ZLib E:/DONOTOPEN/FUCKYOU/ANDROID/FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : FreeImage/Source/ZLib/CMakeFiles/ZLib.dir/depend

