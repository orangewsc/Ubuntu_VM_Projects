# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wsc/Projects/processfork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsc/Projects/processfork/build

# Include any dependencies generated for this target.
include CMakeFiles/processfork.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/processfork.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/processfork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/processfork.dir/flags.make

CMakeFiles/processfork.dir/src/processfork.cpp.o: CMakeFiles/processfork.dir/flags.make
CMakeFiles/processfork.dir/src/processfork.cpp.o: ../src/processfork.cpp
CMakeFiles/processfork.dir/src/processfork.cpp.o: CMakeFiles/processfork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsc/Projects/processfork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/processfork.dir/src/processfork.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/processfork.dir/src/processfork.cpp.o -MF CMakeFiles/processfork.dir/src/processfork.cpp.o.d -o CMakeFiles/processfork.dir/src/processfork.cpp.o -c /home/wsc/Projects/processfork/src/processfork.cpp

CMakeFiles/processfork.dir/src/processfork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/processfork.dir/src/processfork.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsc/Projects/processfork/src/processfork.cpp > CMakeFiles/processfork.dir/src/processfork.cpp.i

CMakeFiles/processfork.dir/src/processfork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/processfork.dir/src/processfork.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsc/Projects/processfork/src/processfork.cpp -o CMakeFiles/processfork.dir/src/processfork.cpp.s

# Object files for target processfork
processfork_OBJECTS = \
"CMakeFiles/processfork.dir/src/processfork.cpp.o"

# External object files for target processfork
processfork_EXTERNAL_OBJECTS =

../bin/processfork: CMakeFiles/processfork.dir/src/processfork.cpp.o
../bin/processfork: CMakeFiles/processfork.dir/build.make
../bin/processfork: CMakeFiles/processfork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsc/Projects/processfork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/processfork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/processfork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/processfork.dir/build: ../bin/processfork
.PHONY : CMakeFiles/processfork.dir/build

CMakeFiles/processfork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/processfork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/processfork.dir/clean

CMakeFiles/processfork.dir/depend:
	cd /home/wsc/Projects/processfork/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsc/Projects/processfork /home/wsc/Projects/processfork /home/wsc/Projects/processfork/build /home/wsc/Projects/processfork/build /home/wsc/Projects/processfork/build/CMakeFiles/processfork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/processfork.dir/depend

