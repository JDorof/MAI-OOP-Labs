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
CMAKE_SOURCE_DIR = /home/justdema/OOP/MAI-OOP-Labs/lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justdema/OOP/MAI-OOP-Labs/lab6/build

# Include any dependencies generated for this target.
include CMakeFiles/lab.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab.dir/flags.make

CMakeFiles/lab.dir/src/entity.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/src/entity.cpp.o: ../src/entity.cpp
CMakeFiles/lab.dir/src/entity.cpp.o: CMakeFiles/lab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab.dir/src/entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab.dir/src/entity.cpp.o -MF CMakeFiles/lab.dir/src/entity.cpp.o.d -o CMakeFiles/lab.dir/src/entity.cpp.o -c /home/justdema/OOP/MAI-OOP-Labs/lab6/src/entity.cpp

CMakeFiles/lab.dir/src/entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/src/entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justdema/OOP/MAI-OOP-Labs/lab6/src/entity.cpp > CMakeFiles/lab.dir/src/entity.cpp.i

CMakeFiles/lab.dir/src/entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/src/entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justdema/OOP/MAI-OOP-Labs/lab6/src/entity.cpp -o CMakeFiles/lab.dir/src/entity.cpp.s

CMakeFiles/lab.dir/src/game.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/src/game.cpp.o: ../src/game.cpp
CMakeFiles/lab.dir/src/game.cpp.o: CMakeFiles/lab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab.dir/src/game.cpp.o -MF CMakeFiles/lab.dir/src/game.cpp.o.d -o CMakeFiles/lab.dir/src/game.cpp.o -c /home/justdema/OOP/MAI-OOP-Labs/lab6/src/game.cpp

CMakeFiles/lab.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justdema/OOP/MAI-OOP-Labs/lab6/src/game.cpp > CMakeFiles/lab.dir/src/game.cpp.i

CMakeFiles/lab.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justdema/OOP/MAI-OOP-Labs/lab6/src/game.cpp -o CMakeFiles/lab.dir/src/game.cpp.s

CMakeFiles/lab.dir/src/main.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/lab.dir/src/main.cpp.o: CMakeFiles/lab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab.dir/src/main.cpp.o -MF CMakeFiles/lab.dir/src/main.cpp.o.d -o CMakeFiles/lab.dir/src/main.cpp.o -c /home/justdema/OOP/MAI-OOP-Labs/lab6/src/main.cpp

CMakeFiles/lab.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justdema/OOP/MAI-OOP-Labs/lab6/src/main.cpp > CMakeFiles/lab.dir/src/main.cpp.i

CMakeFiles/lab.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justdema/OOP/MAI-OOP-Labs/lab6/src/main.cpp -o CMakeFiles/lab.dir/src/main.cpp.s

CMakeFiles/lab.dir/src/npc.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/src/npc.cpp.o: ../src/npc.cpp
CMakeFiles/lab.dir/src/npc.cpp.o: CMakeFiles/lab.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab.dir/src/npc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab.dir/src/npc.cpp.o -MF CMakeFiles/lab.dir/src/npc.cpp.o.d -o CMakeFiles/lab.dir/src/npc.cpp.o -c /home/justdema/OOP/MAI-OOP-Labs/lab6/src/npc.cpp

CMakeFiles/lab.dir/src/npc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/src/npc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/justdema/OOP/MAI-OOP-Labs/lab6/src/npc.cpp > CMakeFiles/lab.dir/src/npc.cpp.i

CMakeFiles/lab.dir/src/npc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/src/npc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/justdema/OOP/MAI-OOP-Labs/lab6/src/npc.cpp -o CMakeFiles/lab.dir/src/npc.cpp.s

# Object files for target lab
lab_OBJECTS = \
"CMakeFiles/lab.dir/src/entity.cpp.o" \
"CMakeFiles/lab.dir/src/game.cpp.o" \
"CMakeFiles/lab.dir/src/main.cpp.o" \
"CMakeFiles/lab.dir/src/npc.cpp.o"

# External object files for target lab
lab_EXTERNAL_OBJECTS =

lab: CMakeFiles/lab.dir/src/entity.cpp.o
lab: CMakeFiles/lab.dir/src/game.cpp.o
lab: CMakeFiles/lab.dir/src/main.cpp.o
lab: CMakeFiles/lab.dir/src/npc.cpp.o
lab: CMakeFiles/lab.dir/build.make
lab: CMakeFiles/lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/justdema/OOP/MAI-OOP-Labs/lab6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable lab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab.dir/build: lab
.PHONY : CMakeFiles/lab.dir/build

CMakeFiles/lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab.dir/clean

CMakeFiles/lab.dir/depend:
	cd /home/justdema/OOP/MAI-OOP-Labs/lab6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/justdema/OOP/MAI-OOP-Labs/lab6 /home/justdema/OOP/MAI-OOP-Labs/lab6 /home/justdema/OOP/MAI-OOP-Labs/lab6/build /home/justdema/OOP/MAI-OOP-Labs/lab6/build /home/justdema/OOP/MAI-OOP-Labs/lab6/build/CMakeFiles/lab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab.dir/depend

