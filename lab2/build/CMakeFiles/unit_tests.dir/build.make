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
CMAKE_SOURCE_DIR = /home/justdema/OOP/MAI-OOP-Labs/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justdema/OOP/MAI-OOP-Labs/lab2/build

# Include any dependencies generated for this target.
include CMakeFiles/unit_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unit_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit_tests.dir/flags.make

CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o: CMakeFiles/unit_tests.dir/flags.make
CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o: ../tests/unit_tests.cpp
CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o: CMakeFiles/unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o -MF CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o.d -o CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o -c /home/justdema/OOP/MAI-OOP-Labs/lab2/tests/unit_tests.cpp

CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justdema/OOP/MAI-OOP-Labs/lab2/tests/unit_tests.cpp > CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.i

CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justdema/OOP/MAI-OOP-Labs/lab2/tests/unit_tests.cpp -o CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.s

CMakeFiles/unit_tests.dir/src/solution.cpp.o: CMakeFiles/unit_tests.dir/flags.make
CMakeFiles/unit_tests.dir/src/solution.cpp.o: ../src/solution.cpp
CMakeFiles/unit_tests.dir/src/solution.cpp.o: CMakeFiles/unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unit_tests.dir/src/solution.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unit_tests.dir/src/solution.cpp.o -MF CMakeFiles/unit_tests.dir/src/solution.cpp.o.d -o CMakeFiles/unit_tests.dir/src/solution.cpp.o -c /home/justdema/OOP/MAI-OOP-Labs/lab2/src/solution.cpp

CMakeFiles/unit_tests.dir/src/solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/src/solution.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justdema/OOP/MAI-OOP-Labs/lab2/src/solution.cpp > CMakeFiles/unit_tests.dir/src/solution.cpp.i

CMakeFiles/unit_tests.dir/src/solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/src/solution.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justdema/OOP/MAI-OOP-Labs/lab2/src/solution.cpp -o CMakeFiles/unit_tests.dir/src/solution.cpp.s

# Object files for target unit_tests
unit_tests_OBJECTS = \
"CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o" \
"CMakeFiles/unit_tests.dir/src/solution.cpp.o"

# External object files for target unit_tests
unit_tests_EXTERNAL_OBJECTS =

unit_tests: CMakeFiles/unit_tests.dir/tests/unit_tests.cpp.o
unit_tests: CMakeFiles/unit_tests.dir/src/solution.cpp.o
unit_tests: CMakeFiles/unit_tests.dir/build.make
unit_tests: lib/libgtest_main.a
unit_tests: lib/libgtest.a
unit_tests: CMakeFiles/unit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable unit_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit_tests.dir/build: unit_tests
.PHONY : CMakeFiles/unit_tests.dir/build

CMakeFiles/unit_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit_tests.dir/clean

CMakeFiles/unit_tests.dir/depend:
	cd /home/justdema/OOP/MAI-OOP-Labs/lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justdema/OOP/MAI-OOP-Labs/lab2 /home/justdema/OOP/MAI-OOP-Labs/lab2 /home/justdema/OOP/MAI-OOP-Labs/lab2/build /home/justdema/OOP/MAI-OOP-Labs/lab2/build /home/justdema/OOP/MAI-OOP-Labs/lab2/build/CMakeFiles/unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit_tests.dir/depend

