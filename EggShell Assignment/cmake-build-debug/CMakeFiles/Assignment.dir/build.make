# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /cygdrive/c/Users/User/.CLion2018.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/User/.CLion2018.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment.dir/flags.make

CMakeFiles/Assignment.dir/main.c.o: CMakeFiles/Assignment.dir/flags.make
CMakeFiles/Assignment.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assignment.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment.dir/main.c.o   -c "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/main.c"

CMakeFiles/Assignment.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/main.c" > CMakeFiles/Assignment.dir/main.c.i

CMakeFiles/Assignment.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/main.c" -o CMakeFiles/Assignment.dir/main.c.s

CMakeFiles/Assignment.dir/tinyShell.c.o: CMakeFiles/Assignment.dir/flags.make
CMakeFiles/Assignment.dir/tinyShell.c.o: ../tinyShell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Assignment.dir/tinyShell.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment.dir/tinyShell.c.o   -c "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/tinyShell.c"

CMakeFiles/Assignment.dir/tinyShell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment.dir/tinyShell.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/tinyShell.c" > CMakeFiles/Assignment.dir/tinyShell.c.i

CMakeFiles/Assignment.dir/tinyShell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment.dir/tinyShell.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/tinyShell.c" -o CMakeFiles/Assignment.dir/tinyShell.c.s

CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.o: CMakeFiles/Assignment.dir/flags.make
CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.o: ../linenoise-master/linenoise.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.o   -c "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/linenoise-master/linenoise.c"

CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/linenoise-master/linenoise.c" > CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.i

CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/linenoise-master/linenoise.c" -o CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.s

CMakeFiles/Assignment.dir/Controllers.c.o: CMakeFiles/Assignment.dir/flags.make
CMakeFiles/Assignment.dir/Controllers.c.o: ../Controllers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Assignment.dir/Controllers.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment.dir/Controllers.c.o   -c "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/Controllers.c"

CMakeFiles/Assignment.dir/Controllers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment.dir/Controllers.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/Controllers.c" > CMakeFiles/Assignment.dir/Controllers.c.i

CMakeFiles/Assignment.dir/Controllers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment.dir/Controllers.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/Controllers.c" -o CMakeFiles/Assignment.dir/Controllers.c.s

CMakeFiles/Assignment.dir/Printing.c.o: CMakeFiles/Assignment.dir/flags.make
CMakeFiles/Assignment.dir/Printing.c.o: ../Printing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Assignment.dir/Printing.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment.dir/Printing.c.o   -c "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/Printing.c"

CMakeFiles/Assignment.dir/Printing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment.dir/Printing.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/Printing.c" > CMakeFiles/Assignment.dir/Printing.c.i

CMakeFiles/Assignment.dir/Printing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment.dir/Printing.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/Printing.c" -o CMakeFiles/Assignment.dir/Printing.c.s

# Object files for target Assignment
Assignment_OBJECTS = \
"CMakeFiles/Assignment.dir/main.c.o" \
"CMakeFiles/Assignment.dir/tinyShell.c.o" \
"CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.o" \
"CMakeFiles/Assignment.dir/Controllers.c.o" \
"CMakeFiles/Assignment.dir/Printing.c.o"

# External object files for target Assignment
Assignment_EXTERNAL_OBJECTS =

Assignment.exe: CMakeFiles/Assignment.dir/main.c.o
Assignment.exe: CMakeFiles/Assignment.dir/tinyShell.c.o
Assignment.exe: CMakeFiles/Assignment.dir/linenoise-master/linenoise.c.o
Assignment.exe: CMakeFiles/Assignment.dir/Controllers.c.o
Assignment.exe: CMakeFiles/Assignment.dir/Printing.c.o
Assignment.exe: CMakeFiles/Assignment.dir/build.make
Assignment.exe: CMakeFiles/Assignment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Assignment.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment.dir/build: Assignment.exe

.PHONY : CMakeFiles/Assignment.dir/build

CMakeFiles/Assignment.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment.dir/clean

CMakeFiles/Assignment.dir/depend:
	cd "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment" "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment" "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug" "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug" "/cygdrive/c/Users/User/Downloads/Operating System Assignement/Juan/EggShell Assignment/cmake-build-debug/CMakeFiles/Assignment.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment.dir/depend
