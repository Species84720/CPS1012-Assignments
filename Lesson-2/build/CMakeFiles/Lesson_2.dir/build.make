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
CMAKE_COMMAND = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build"

# Include any dependencies generated for this target.
include CMakeFiles/Lesson_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lesson_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lesson_2.dir/flags.make

CMakeFiles/Lesson_2.dir/main.c.o: CMakeFiles/Lesson_2.dir/flags.make
CMakeFiles/Lesson_2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lesson_2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lesson_2.dir/main.c.o   -c "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/main.c"

CMakeFiles/Lesson_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lesson_2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/main.c" > CMakeFiles/Lesson_2.dir/main.c.i

CMakeFiles/Lesson_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lesson_2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/main.c" -o CMakeFiles/Lesson_2.dir/main.c.s

CMakeFiles/Lesson_2.dir/Print_String.c.o: CMakeFiles/Lesson_2.dir/flags.make
CMakeFiles/Lesson_2.dir/Print_String.c.o: ../Print_String.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Lesson_2.dir/Print_String.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lesson_2.dir/Print_String.c.o   -c "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/Print_String.c"

CMakeFiles/Lesson_2.dir/Print_String.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lesson_2.dir/Print_String.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/Print_String.c" > CMakeFiles/Lesson_2.dir/Print_String.c.i

CMakeFiles/Lesson_2.dir/Print_String.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lesson_2.dir/Print_String.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/Print_String.c" -o CMakeFiles/Lesson_2.dir/Print_String.c.s

# Object files for target Lesson_2
Lesson_2_OBJECTS = \
"CMakeFiles/Lesson_2.dir/main.c.o" \
"CMakeFiles/Lesson_2.dir/Print_String.c.o"

# External object files for target Lesson_2
Lesson_2_EXTERNAL_OBJECTS =

Lesson_2: CMakeFiles/Lesson_2.dir/main.c.o
Lesson_2: CMakeFiles/Lesson_2.dir/Print_String.c.o
Lesson_2: CMakeFiles/Lesson_2.dir/build.make
Lesson_2: CMakeFiles/Lesson_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Lesson_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lesson_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lesson_2.dir/build: Lesson_2

.PHONY : CMakeFiles/Lesson_2.dir/build

CMakeFiles/Lesson_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lesson_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lesson_2.dir/clean

CMakeFiles/Lesson_2.dir/depend:
	cd "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2" "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2" "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build" "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build" "/mnt/c/Users/User/Downloads/Operating System Assignement/Juan/Lesson-2/build/CMakeFiles/Lesson_2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lesson_2.dir/depend
