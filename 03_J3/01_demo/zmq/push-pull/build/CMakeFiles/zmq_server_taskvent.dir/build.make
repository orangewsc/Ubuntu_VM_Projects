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
CMAKE_SOURCE_DIR = /home/wsc/Projects/03_J3/01_demo/zmq/push-pull

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/build

# Include any dependencies generated for this target.
include CMakeFiles/zmq_server_taskvent.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zmq_server_taskvent.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zmq_server_taskvent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zmq_server_taskvent.dir/flags.make

CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o: CMakeFiles/zmq_server_taskvent.dir/flags.make
CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o: ../src/zmq_server_taskvent.cpp
CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o: CMakeFiles/zmq_server_taskvent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsc/Projects/03_J3/01_demo/zmq/push-pull/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o"
	/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc-6.5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o -MF CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o.d -o CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o -c /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/src/zmq_server_taskvent.cpp

CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.i"
	/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc-6.5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/src/zmq_server_taskvent.cpp > CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.i

CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.s"
	/home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/host/gcc-linaro-6.5.0-2018.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc-6.5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/src/zmq_server_taskvent.cpp -o CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.s

# Object files for target zmq_server_taskvent
zmq_server_taskvent_OBJECTS = \
"CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o"

# External object files for target zmq_server_taskvent
zmq_server_taskvent_EXTERNAL_OBJECTS =

../bin/zmq_server_taskvent: CMakeFiles/zmq_server_taskvent.dir/src/zmq_server_taskvent.cpp.o
../bin/zmq_server_taskvent: CMakeFiles/zmq_server_taskvent.dir/build.make
../bin/zmq_server_taskvent: /home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/prebuilts/root/usr/lib/libstdc++.so.6
../bin/zmq_server_taskvent: /home/wsc/opt/SAIC/02_J3/HorizonRobotics_PIE/J3/auto_sw/hbre/third_party/zmq/lib/aarch64/libzmq.so
../bin/zmq_server_taskvent: CMakeFiles/zmq_server_taskvent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsc/Projects/03_J3/01_demo/zmq/push-pull/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/zmq_server_taskvent"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zmq_server_taskvent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zmq_server_taskvent.dir/build: ../bin/zmq_server_taskvent
.PHONY : CMakeFiles/zmq_server_taskvent.dir/build

CMakeFiles/zmq_server_taskvent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zmq_server_taskvent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zmq_server_taskvent.dir/clean

CMakeFiles/zmq_server_taskvent.dir/depend:
	cd /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsc/Projects/03_J3/01_demo/zmq/push-pull /home/wsc/Projects/03_J3/01_demo/zmq/push-pull /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/build /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/build /home/wsc/Projects/03_J3/01_demo/zmq/push-pull/build/CMakeFiles/zmq_server_taskvent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zmq_server_taskvent.dir/depend

