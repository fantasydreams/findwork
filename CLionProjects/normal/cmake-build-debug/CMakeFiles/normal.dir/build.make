# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sharwen/Desktop/practice/CLionProjects/normal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sharwen/Desktop/practice/CLionProjects/normal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/normal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/normal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/normal.dir/flags.make

CMakeFiles/normal.dir/main.cpp.o: CMakeFiles/normal.dir/flags.make
CMakeFiles/normal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharwen/Desktop/practice/CLionProjects/normal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/normal.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/normal.dir/main.cpp.o -c /Users/sharwen/Desktop/practice/CLionProjects/normal/main.cpp

CMakeFiles/normal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/normal.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharwen/Desktop/practice/CLionProjects/normal/main.cpp > CMakeFiles/normal.dir/main.cpp.i

CMakeFiles/normal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/normal.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharwen/Desktop/practice/CLionProjects/normal/main.cpp -o CMakeFiles/normal.dir/main.cpp.s

# Object files for target normal
normal_OBJECTS = \
"CMakeFiles/normal.dir/main.cpp.o"

# External object files for target normal
normal_EXTERNAL_OBJECTS =

normal: CMakeFiles/normal.dir/main.cpp.o
normal: CMakeFiles/normal.dir/build.make
normal: CMakeFiles/normal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sharwen/Desktop/practice/CLionProjects/normal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable normal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/normal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/normal.dir/build: normal

.PHONY : CMakeFiles/normal.dir/build

CMakeFiles/normal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/normal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/normal.dir/clean

CMakeFiles/normal.dir/depend:
	cd /Users/sharwen/Desktop/practice/CLionProjects/normal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sharwen/Desktop/practice/CLionProjects/normal /Users/sharwen/Desktop/practice/CLionProjects/normal /Users/sharwen/Desktop/practice/CLionProjects/normal/cmake-build-debug /Users/sharwen/Desktop/practice/CLionProjects/normal/cmake-build-debug /Users/sharwen/Desktop/practice/CLionProjects/normal/cmake-build-debug/CMakeFiles/normal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/normal.dir/depend

