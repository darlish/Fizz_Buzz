# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\miche\CLionProjects\untitled8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\miche\CLionProjects\untitled8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled8.dir/flags.make

CMakeFiles/untitled8.dir/library.c.obj: CMakeFiles/untitled8.dir/flags.make
CMakeFiles/untitled8.dir/library.c.obj: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\miche\CLionProjects\untitled8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled8.dir/library.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled8.dir\library.c.obj   -c C:\Users\miche\CLionProjects\untitled8\library.c

CMakeFiles/untitled8.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled8.dir/library.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\miche\CLionProjects\untitled8\library.c > CMakeFiles\untitled8.dir\library.c.i

CMakeFiles/untitled8.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled8.dir/library.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\miche\CLionProjects\untitled8\library.c -o CMakeFiles\untitled8.dir\library.c.s

# Object files for target untitled8
untitled8_OBJECTS = \
"CMakeFiles/untitled8.dir/library.c.obj"

# External object files for target untitled8
untitled8_EXTERNAL_OBJECTS =

libuntitled8.a: CMakeFiles/untitled8.dir/library.c.obj
libuntitled8.a: CMakeFiles/untitled8.dir/build.make
libuntitled8.a: CMakeFiles/untitled8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\miche\CLionProjects\untitled8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libuntitled8.a"
	$(CMAKE_COMMAND) -P CMakeFiles\untitled8.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled8.dir/build: libuntitled8.a

.PHONY : CMakeFiles/untitled8.dir/build

CMakeFiles/untitled8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled8.dir/clean

CMakeFiles/untitled8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\miche\CLionProjects\untitled8 C:\Users\miche\CLionProjects\untitled8 C:\Users\miche\CLionProjects\untitled8\cmake-build-debug C:\Users\miche\CLionProjects\untitled8\cmake-build-debug C:\Users\miche\CLionProjects\untitled8\cmake-build-debug\CMakeFiles\untitled8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled8.dir/depend

