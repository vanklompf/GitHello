# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/shares/public/GitHello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shares/public/GitHello

# Include any dependencies generated for this target.
include CMakeFiles/client_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client_server.dir/flags.make

CMakeFiles/client_server.dir/client.cpp.o: CMakeFiles/client_server.dir/flags.make
CMakeFiles/client_server.dir/client.cpp.o: client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/shares/public/GitHello/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/client_server.dir/client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client_server.dir/client.cpp.o -c /home/shares/public/GitHello/client.cpp

CMakeFiles/client_server.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_server.dir/client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/shares/public/GitHello/client.cpp > CMakeFiles/client_server.dir/client.cpp.i

CMakeFiles/client_server.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_server.dir/client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/shares/public/GitHello/client.cpp -o CMakeFiles/client_server.dir/client.cpp.s

CMakeFiles/client_server.dir/client.cpp.o.requires:
.PHONY : CMakeFiles/client_server.dir/client.cpp.o.requires

CMakeFiles/client_server.dir/client.cpp.o.provides: CMakeFiles/client_server.dir/client.cpp.o.requires
	$(MAKE) -f CMakeFiles/client_server.dir/build.make CMakeFiles/client_server.dir/client.cpp.o.provides.build
.PHONY : CMakeFiles/client_server.dir/client.cpp.o.provides

CMakeFiles/client_server.dir/client.cpp.o.provides.build: CMakeFiles/client_server.dir/client.cpp.o

CMakeFiles/client_server.dir/server.cpp.o: CMakeFiles/client_server.dir/flags.make
CMakeFiles/client_server.dir/server.cpp.o: server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/shares/public/GitHello/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/client_server.dir/server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client_server.dir/server.cpp.o -c /home/shares/public/GitHello/server.cpp

CMakeFiles/client_server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_server.dir/server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/shares/public/GitHello/server.cpp > CMakeFiles/client_server.dir/server.cpp.i

CMakeFiles/client_server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_server.dir/server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/shares/public/GitHello/server.cpp -o CMakeFiles/client_server.dir/server.cpp.s

CMakeFiles/client_server.dir/server.cpp.o.requires:
.PHONY : CMakeFiles/client_server.dir/server.cpp.o.requires

CMakeFiles/client_server.dir/server.cpp.o.provides: CMakeFiles/client_server.dir/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/client_server.dir/build.make CMakeFiles/client_server.dir/server.cpp.o.provides.build
.PHONY : CMakeFiles/client_server.dir/server.cpp.o.provides

CMakeFiles/client_server.dir/server.cpp.o.provides.build: CMakeFiles/client_server.dir/server.cpp.o

CMakeFiles/client_server.dir/network_main.cpp.o: CMakeFiles/client_server.dir/flags.make
CMakeFiles/client_server.dir/network_main.cpp.o: network_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/shares/public/GitHello/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/client_server.dir/network_main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/client_server.dir/network_main.cpp.o -c /home/shares/public/GitHello/network_main.cpp

CMakeFiles/client_server.dir/network_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_server.dir/network_main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/shares/public/GitHello/network_main.cpp > CMakeFiles/client_server.dir/network_main.cpp.i

CMakeFiles/client_server.dir/network_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_server.dir/network_main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/shares/public/GitHello/network_main.cpp -o CMakeFiles/client_server.dir/network_main.cpp.s

CMakeFiles/client_server.dir/network_main.cpp.o.requires:
.PHONY : CMakeFiles/client_server.dir/network_main.cpp.o.requires

CMakeFiles/client_server.dir/network_main.cpp.o.provides: CMakeFiles/client_server.dir/network_main.cpp.o.requires
	$(MAKE) -f CMakeFiles/client_server.dir/build.make CMakeFiles/client_server.dir/network_main.cpp.o.provides.build
.PHONY : CMakeFiles/client_server.dir/network_main.cpp.o.provides

CMakeFiles/client_server.dir/network_main.cpp.o.provides.build: CMakeFiles/client_server.dir/network_main.cpp.o

# Object files for target client_server
client_server_OBJECTS = \
"CMakeFiles/client_server.dir/client.cpp.o" \
"CMakeFiles/client_server.dir/server.cpp.o" \
"CMakeFiles/client_server.dir/network_main.cpp.o"

# External object files for target client_server
client_server_EXTERNAL_OBJECTS =

client_server: CMakeFiles/client_server.dir/client.cpp.o
client_server: CMakeFiles/client_server.dir/server.cpp.o
client_server: CMakeFiles/client_server.dir/network_main.cpp.o
client_server: CMakeFiles/client_server.dir/build.make
client_server: CMakeFiles/client_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable client_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client_server.dir/build: client_server
.PHONY : CMakeFiles/client_server.dir/build

CMakeFiles/client_server.dir/requires: CMakeFiles/client_server.dir/client.cpp.o.requires
CMakeFiles/client_server.dir/requires: CMakeFiles/client_server.dir/server.cpp.o.requires
CMakeFiles/client_server.dir/requires: CMakeFiles/client_server.dir/network_main.cpp.o.requires
.PHONY : CMakeFiles/client_server.dir/requires

CMakeFiles/client_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client_server.dir/clean

CMakeFiles/client_server.dir/depend:
	cd /home/shares/public/GitHello && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shares/public/GitHello /home/shares/public/GitHello /home/shares/public/GitHello /home/shares/public/GitHello /home/shares/public/GitHello/CMakeFiles/client_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client_server.dir/depend

