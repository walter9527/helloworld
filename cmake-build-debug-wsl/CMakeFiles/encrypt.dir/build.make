# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/walter/CLionProjects/lesson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/encrypt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/encrypt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/encrypt.dir/flags.make

CMakeFiles/encrypt.dir/encrypt/encrypt.c.o: CMakeFiles/encrypt.dir/flags.make
CMakeFiles/encrypt.dir/encrypt/encrypt.c.o: ../encrypt/encrypt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/encrypt.dir/encrypt/encrypt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/encrypt.dir/encrypt/encrypt.c.o   -c /mnt/c/Users/walter/CLionProjects/lesson/encrypt/encrypt.c

CMakeFiles/encrypt.dir/encrypt/encrypt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/encrypt.dir/encrypt/encrypt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/walter/CLionProjects/lesson/encrypt/encrypt.c > CMakeFiles/encrypt.dir/encrypt/encrypt.c.i

CMakeFiles/encrypt.dir/encrypt/encrypt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/encrypt.dir/encrypt/encrypt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/walter/CLionProjects/lesson/encrypt/encrypt.c -o CMakeFiles/encrypt.dir/encrypt/encrypt.c.s

CMakeFiles/encrypt.dir/common/common.c.o: CMakeFiles/encrypt.dir/flags.make
CMakeFiles/encrypt.dir/common/common.c.o: ../common/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/encrypt.dir/common/common.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/encrypt.dir/common/common.c.o   -c /mnt/c/Users/walter/CLionProjects/lesson/common/common.c

CMakeFiles/encrypt.dir/common/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/encrypt.dir/common/common.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/walter/CLionProjects/lesson/common/common.c > CMakeFiles/encrypt.dir/common/common.c.i

CMakeFiles/encrypt.dir/common/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/encrypt.dir/common/common.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/walter/CLionProjects/lesson/common/common.c -o CMakeFiles/encrypt.dir/common/common.c.s

# Object files for target encrypt
encrypt_OBJECTS = \
"CMakeFiles/encrypt.dir/encrypt/encrypt.c.o" \
"CMakeFiles/encrypt.dir/common/common.c.o"

# External object files for target encrypt
encrypt_EXTERNAL_OBJECTS =

encrypt: CMakeFiles/encrypt.dir/encrypt/encrypt.c.o
encrypt: CMakeFiles/encrypt.dir/common/common.c.o
encrypt: CMakeFiles/encrypt.dir/build.make
encrypt: CMakeFiles/encrypt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable encrypt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/encrypt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/encrypt.dir/build: encrypt

.PHONY : CMakeFiles/encrypt.dir/build

CMakeFiles/encrypt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/encrypt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/encrypt.dir/clean

CMakeFiles/encrypt.dir/depend:
	cd /mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/walter/CLionProjects/lesson /mnt/c/Users/walter/CLionProjects/lesson /mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl /mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl /mnt/c/Users/walter/CLionProjects/lesson/cmake-build-debug-wsl/CMakeFiles/encrypt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/encrypt.dir/depend

