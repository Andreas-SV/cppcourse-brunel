# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/projects/cppcourse-brunel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/projects/cppcourse-brunel/build

# Include any dependencies generated for this target.
include CMakeFiles/Neurons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Neurons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Neurons.dir/flags.make

CMakeFiles/Neurons.dir/Neuron.cpp.o: CMakeFiles/Neurons.dir/flags.make
CMakeFiles/Neurons.dir/Neuron.cpp.o: ../Neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/student/projects/cppcourse-brunel/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Neurons.dir/Neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Neurons.dir/Neuron.cpp.o -c /home/student/projects/cppcourse-brunel/Neuron.cpp

CMakeFiles/Neurons.dir/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurons.dir/Neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/student/projects/cppcourse-brunel/Neuron.cpp > CMakeFiles/Neurons.dir/Neuron.cpp.i

CMakeFiles/Neurons.dir/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurons.dir/Neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/student/projects/cppcourse-brunel/Neuron.cpp -o CMakeFiles/Neurons.dir/Neuron.cpp.s

CMakeFiles/Neurons.dir/Neuron.cpp.o.requires:
.PHONY : CMakeFiles/Neurons.dir/Neuron.cpp.o.requires

CMakeFiles/Neurons.dir/Neuron.cpp.o.provides: CMakeFiles/Neurons.dir/Neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurons.dir/build.make CMakeFiles/Neurons.dir/Neuron.cpp.o.provides.build
.PHONY : CMakeFiles/Neurons.dir/Neuron.cpp.o.provides

CMakeFiles/Neurons.dir/Neuron.cpp.o.provides.build: CMakeFiles/Neurons.dir/Neuron.cpp.o

CMakeFiles/Neurons.dir/Network.cpp.o: CMakeFiles/Neurons.dir/flags.make
CMakeFiles/Neurons.dir/Network.cpp.o: ../Network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/student/projects/cppcourse-brunel/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Neurons.dir/Network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Neurons.dir/Network.cpp.o -c /home/student/projects/cppcourse-brunel/Network.cpp

CMakeFiles/Neurons.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurons.dir/Network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/student/projects/cppcourse-brunel/Network.cpp > CMakeFiles/Neurons.dir/Network.cpp.i

CMakeFiles/Neurons.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurons.dir/Network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/student/projects/cppcourse-brunel/Network.cpp -o CMakeFiles/Neurons.dir/Network.cpp.s

CMakeFiles/Neurons.dir/Network.cpp.o.requires:
.PHONY : CMakeFiles/Neurons.dir/Network.cpp.o.requires

CMakeFiles/Neurons.dir/Network.cpp.o.provides: CMakeFiles/Neurons.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurons.dir/build.make CMakeFiles/Neurons.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/Neurons.dir/Network.cpp.o.provides

CMakeFiles/Neurons.dir/Network.cpp.o.provides.build: CMakeFiles/Neurons.dir/Network.cpp.o

CMakeFiles/Neurons.dir/main.cpp.o: CMakeFiles/Neurons.dir/flags.make
CMakeFiles/Neurons.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/student/projects/cppcourse-brunel/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Neurons.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Neurons.dir/main.cpp.o -c /home/student/projects/cppcourse-brunel/main.cpp

CMakeFiles/Neurons.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurons.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/student/projects/cppcourse-brunel/main.cpp > CMakeFiles/Neurons.dir/main.cpp.i

CMakeFiles/Neurons.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurons.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/student/projects/cppcourse-brunel/main.cpp -o CMakeFiles/Neurons.dir/main.cpp.s

CMakeFiles/Neurons.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/Neurons.dir/main.cpp.o.requires

CMakeFiles/Neurons.dir/main.cpp.o.provides: CMakeFiles/Neurons.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurons.dir/build.make CMakeFiles/Neurons.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Neurons.dir/main.cpp.o.provides

CMakeFiles/Neurons.dir/main.cpp.o.provides.build: CMakeFiles/Neurons.dir/main.cpp.o

# Object files for target Neurons
Neurons_OBJECTS = \
"CMakeFiles/Neurons.dir/Neuron.cpp.o" \
"CMakeFiles/Neurons.dir/Network.cpp.o" \
"CMakeFiles/Neurons.dir/main.cpp.o"

# External object files for target Neurons
Neurons_EXTERNAL_OBJECTS =

Neurons: CMakeFiles/Neurons.dir/Neuron.cpp.o
Neurons: CMakeFiles/Neurons.dir/Network.cpp.o
Neurons: CMakeFiles/Neurons.dir/main.cpp.o
Neurons: CMakeFiles/Neurons.dir/build.make
Neurons: CMakeFiles/Neurons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Neurons"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Neurons.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Neurons.dir/build: Neurons
.PHONY : CMakeFiles/Neurons.dir/build

CMakeFiles/Neurons.dir/requires: CMakeFiles/Neurons.dir/Neuron.cpp.o.requires
CMakeFiles/Neurons.dir/requires: CMakeFiles/Neurons.dir/Network.cpp.o.requires
CMakeFiles/Neurons.dir/requires: CMakeFiles/Neurons.dir/main.cpp.o.requires
.PHONY : CMakeFiles/Neurons.dir/requires

CMakeFiles/Neurons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Neurons.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Neurons.dir/clean

CMakeFiles/Neurons.dir/depend:
	cd /home/student/projects/cppcourse-brunel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/projects/cppcourse-brunel /home/student/projects/cppcourse-brunel /home/student/projects/cppcourse-brunel/build /home/student/projects/cppcourse-brunel/build /home/student/projects/cppcourse-brunel/build/CMakeFiles/Neurons.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Neurons.dir/depend

