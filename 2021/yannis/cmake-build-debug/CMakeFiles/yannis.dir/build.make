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
CMAKE_SOURCE_DIR = C:\Users\miche\CLionProjects\yannis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\miche\CLionProjects\yannis\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/yannis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/yannis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yannis.dir/flags.make

CMakeFiles/yannis.dir/main.c.obj: CMakeFiles/yannis.dir/flags.make
CMakeFiles/yannis.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\miche\CLionProjects\yannis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/yannis.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\yannis.dir\main.c.obj   -c C:\Users\miche\CLionProjects\yannis\main.c

CMakeFiles/yannis.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yannis.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\miche\CLionProjects\yannis\main.c > CMakeFiles\yannis.dir\main.c.i

CMakeFiles/yannis.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yannis.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\miche\CLionProjects\yannis\main.c -o CMakeFiles\yannis.dir\main.c.s

CMakeFiles/yannis.dir/conio.c.obj: CMakeFiles/yannis.dir/flags.make
CMakeFiles/yannis.dir/conio.c.obj: ../conio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\miche\CLionProjects\yannis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/yannis.dir/conio.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\yannis.dir\conio.c.obj   -c C:\Users\miche\CLionProjects\yannis\conio.c

CMakeFiles/yannis.dir/conio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yannis.dir/conio.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\miche\CLionProjects\yannis\conio.c > CMakeFiles\yannis.dir\conio.c.i

CMakeFiles/yannis.dir/conio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yannis.dir/conio.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\miche\CLionProjects\yannis\conio.c -o CMakeFiles\yannis.dir\conio.c.s

CMakeFiles/yannis.dir/rubiks.c.obj: CMakeFiles/yannis.dir/flags.make
CMakeFiles/yannis.dir/rubiks.c.obj: ../rubiks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\miche\CLionProjects\yannis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/yannis.dir/rubiks.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\yannis.dir\rubiks.c.obj   -c C:\Users\miche\CLionProjects\yannis\rubiks.c

CMakeFiles/yannis.dir/rubiks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/yannis.dir/rubiks.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\miche\CLionProjects\yannis\rubiks.c > CMakeFiles\yannis.dir\rubiks.c.i

CMakeFiles/yannis.dir/rubiks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/yannis.dir/rubiks.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\miche\CLionProjects\yannis\rubiks.c -o CMakeFiles\yannis.dir\rubiks.c.s

# Object files for target yannis
yannis_OBJECTS = \
"CMakeFiles/yannis.dir/main.c.obj" \
"CMakeFiles/yannis.dir/conio.c.obj" \
"CMakeFiles/yannis.dir/rubiks.c.obj"

# External object files for target yannis
yannis_EXTERNAL_OBJECTS =

yannis.exe: CMakeFiles/yannis.dir/main.c.obj
yannis.exe: CMakeFiles/yannis.dir/conio.c.obj
yannis.exe: CMakeFiles/yannis.dir/rubiks.c.obj
yannis.exe: CMakeFiles/yannis.dir/build.make
yannis.exe: CMakeFiles/yannis.dir/linklibs.rsp
yannis.exe: CMakeFiles/yannis.dir/objects1.rsp
yannis.exe: CMakeFiles/yannis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\miche\CLionProjects\yannis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable yannis.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\yannis.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yannis.dir/build: yannis.exe

.PHONY : CMakeFiles/yannis.dir/build

CMakeFiles/yannis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\yannis.dir\cmake_clean.cmake
.PHONY : CMakeFiles/yannis.dir/clean

CMakeFiles/yannis.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\miche\CLionProjects\yannis C:\Users\miche\CLionProjects\yannis C:\Users\miche\CLionProjects\yannis\cmake-build-debug C:\Users\miche\CLionProjects\yannis\cmake-build-debug C:\Users\miche\CLionProjects\yannis\cmake-build-debug\CMakeFiles\yannis.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yannis.dir/depend

