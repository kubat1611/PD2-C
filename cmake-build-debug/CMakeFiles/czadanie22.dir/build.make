# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\JakubTeterycz\Documents\GitHub\PD2-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/czadanie22.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/czadanie22.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/czadanie22.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/czadanie22.dir/flags.make

CMakeFiles/czadanie22.dir/main.c.obj: CMakeFiles/czadanie22.dir/flags.make
CMakeFiles/czadanie22.dir/main.c.obj: C:/Users/JakubTeterycz/Documents/GitHub/PD2-C/main.c
CMakeFiles/czadanie22.dir/main.c.obj: CMakeFiles/czadanie22.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/czadanie22.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/czadanie22.dir/main.c.obj -MF CMakeFiles\czadanie22.dir\main.c.obj.d -o CMakeFiles\czadanie22.dir\main.c.obj -c C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\main.c

CMakeFiles/czadanie22.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/czadanie22.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\main.c > CMakeFiles\czadanie22.dir\main.c.i

CMakeFiles/czadanie22.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/czadanie22.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\main.c -o CMakeFiles\czadanie22.dir\main.c.s

# Object files for target czadanie22
czadanie22_OBJECTS = \
"CMakeFiles/czadanie22.dir/main.c.obj"

# External object files for target czadanie22
czadanie22_EXTERNAL_OBJECTS =

czadanie22.exe: CMakeFiles/czadanie22.dir/main.c.obj
czadanie22.exe: CMakeFiles/czadanie22.dir/build.make
czadanie22.exe: CMakeFiles/czadanie22.dir/linkLibs.rsp
czadanie22.exe: CMakeFiles/czadanie22.dir/objects1.rsp
czadanie22.exe: CMakeFiles/czadanie22.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable czadanie22.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\czadanie22.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/czadanie22.dir/build: czadanie22.exe
.PHONY : CMakeFiles/czadanie22.dir/build

CMakeFiles/czadanie22.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\czadanie22.dir\cmake_clean.cmake
.PHONY : CMakeFiles/czadanie22.dir/clean

CMakeFiles/czadanie22.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\JakubTeterycz\Documents\GitHub\PD2-C C:\Users\JakubTeterycz\Documents\GitHub\PD2-C C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\cmake-build-debug C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\cmake-build-debug C:\Users\JakubTeterycz\Documents\GitHub\PD2-C\cmake-build-debug\CMakeFiles\czadanie22.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/czadanie22.dir/depend

