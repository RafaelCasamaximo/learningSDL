# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rfc/Documents/learningSDL/03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rfc/Documents/learningSDL/03/build

# Include any dependencies generated for this target.
include CMakeFiles/SDL03.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL03.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL03.dir/flags.make

CMakeFiles/SDL03.dir/main.cpp.o: CMakeFiles/SDL03.dir/flags.make
CMakeFiles/SDL03.dir/main.cpp.o: ../main.cpp
CMakeFiles/SDL03.dir/main.cpp.o: CMakeFiles/SDL03.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rfc/Documents/learningSDL/03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL03.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL03.dir/main.cpp.o -MF CMakeFiles/SDL03.dir/main.cpp.o.d -o CMakeFiles/SDL03.dir/main.cpp.o -c /home/rfc/Documents/learningSDL/03/main.cpp

CMakeFiles/SDL03.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL03.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rfc/Documents/learningSDL/03/main.cpp > CMakeFiles/SDL03.dir/main.cpp.i

CMakeFiles/SDL03.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL03.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rfc/Documents/learningSDL/03/main.cpp -o CMakeFiles/SDL03.dir/main.cpp.s

# Object files for target SDL03
SDL03_OBJECTS = \
"CMakeFiles/SDL03.dir/main.cpp.o"

# External object files for target SDL03
SDL03_EXTERNAL_OBJECTS =

SDL03: CMakeFiles/SDL03.dir/main.cpp.o
SDL03: CMakeFiles/SDL03.dir/build.make
SDL03: /usr/local/lib/libSDL2.so
SDL03: CMakeFiles/SDL03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rfc/Documents/learningSDL/03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SDL03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL03.dir/build: SDL03
.PHONY : CMakeFiles/SDL03.dir/build

CMakeFiles/SDL03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL03.dir/clean

CMakeFiles/SDL03.dir/depend:
	cd /home/rfc/Documents/learningSDL/03/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rfc/Documents/learningSDL/03 /home/rfc/Documents/learningSDL/03 /home/rfc/Documents/learningSDL/03/build /home/rfc/Documents/learningSDL/03/build /home/rfc/Documents/learningSDL/03/build/CMakeFiles/SDL03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL03.dir/depend

