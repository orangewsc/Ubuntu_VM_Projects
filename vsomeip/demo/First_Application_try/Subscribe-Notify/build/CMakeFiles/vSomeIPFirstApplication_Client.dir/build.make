# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/build

# Include any dependencies generated for this target.
include CMakeFiles/vSomeIPFirstApplication_Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vSomeIPFirstApplication_Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vSomeIPFirstApplication_Client.dir/flags.make

CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o: CMakeFiles/vSomeIPFirstApplication_Client.dir/flags.make
CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o: ../src/client-example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o -c /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/src/client-example.cpp

CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/src/client-example.cpp > CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.i

CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/src/client-example.cpp -o CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.s

CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.requires:

.PHONY : CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.requires

CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.provides: CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.requires
	$(MAKE) -f CMakeFiles/vSomeIPFirstApplication_Client.dir/build.make CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.provides.build
.PHONY : CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.provides

CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.provides.build: CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o


# Object files for target vSomeIPFirstApplication_Client
vSomeIPFirstApplication_Client_OBJECTS = \
"CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o"

# External object files for target vSomeIPFirstApplication_Client
vSomeIPFirstApplication_Client_EXTERNAL_OBJECTS =

../bin/vSomeIPFirstApplication_Client: CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o
../bin/vSomeIPFirstApplication_Client: CMakeFiles/vSomeIPFirstApplication_Client.dir/build.make
../bin/vSomeIPFirstApplication_Client: /usr/local/vsomeip-3.1.20/lib/libvsomeip3.so.3.1.20
../bin/vSomeIPFirstApplication_Client: CMakeFiles/vSomeIPFirstApplication_Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/vSomeIPFirstApplication_Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vSomeIPFirstApplication_Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vSomeIPFirstApplication_Client.dir/build: ../bin/vSomeIPFirstApplication_Client

.PHONY : CMakeFiles/vSomeIPFirstApplication_Client.dir/build

CMakeFiles/vSomeIPFirstApplication_Client.dir/requires: CMakeFiles/vSomeIPFirstApplication_Client.dir/src/client-example.cpp.o.requires

.PHONY : CMakeFiles/vSomeIPFirstApplication_Client.dir/requires

CMakeFiles/vSomeIPFirstApplication_Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vSomeIPFirstApplication_Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vSomeIPFirstApplication_Client.dir/clean

CMakeFiles/vSomeIPFirstApplication_Client.dir/depend:
	cd /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/build /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/build /home/wsc/Projects/vsomeip/demo/First_Application_try/Subscribe-Notify/build/CMakeFiles/vSomeIPFirstApplication_Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vSomeIPFirstApplication_Client.dir/depend

