# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/shahdelrefai/CLionProjects/Dots and Boxes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Dots_and_Boxes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Dots_and_Boxes.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Dots_and_Boxes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dots_and_Boxes.dir/flags.make

CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o: CMakeFiles/Dots_and_Boxes.dir/flags.make
CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o: /Users/shahdelrefai/CLionProjects/Dots\ and\ Boxes/Box.cpp
CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o: CMakeFiles/Dots_and_Boxes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o -MF CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o.d -o CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o -c "/Users/shahdelrefai/CLionProjects/Dots and Boxes/Box.cpp"

CMakeFiles/Dots_and_Boxes.dir/Box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dots_and_Boxes.dir/Box.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shahdelrefai/CLionProjects/Dots and Boxes/Box.cpp" > CMakeFiles/Dots_and_Boxes.dir/Box.cpp.i

CMakeFiles/Dots_and_Boxes.dir/Box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dots_and_Boxes.dir/Box.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shahdelrefai/CLionProjects/Dots and Boxes/Box.cpp" -o CMakeFiles/Dots_and_Boxes.dir/Box.cpp.s

CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o: CMakeFiles/Dots_and_Boxes.dir/flags.make
CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o: /Users/shahdelrefai/CLionProjects/Dots\ and\ Boxes/DotsAndBoxesGame.cpp
CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o: CMakeFiles/Dots_and_Boxes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o -MF CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o.d -o CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o -c "/Users/shahdelrefai/CLionProjects/Dots and Boxes/DotsAndBoxesGame.cpp"

CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shahdelrefai/CLionProjects/Dots and Boxes/DotsAndBoxesGame.cpp" > CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.i

CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shahdelrefai/CLionProjects/Dots and Boxes/DotsAndBoxesGame.cpp" -o CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.s

CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o: CMakeFiles/Dots_and_Boxes.dir/flags.make
CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o: /Users/shahdelrefai/CLionProjects/Dots\ and\ Boxes/Edge.cpp
CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o: CMakeFiles/Dots_and_Boxes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o -MF CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o.d -o CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o -c "/Users/shahdelrefai/CLionProjects/Dots and Boxes/Edge.cpp"

CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shahdelrefai/CLionProjects/Dots and Boxes/Edge.cpp" > CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.i

CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shahdelrefai/CLionProjects/Dots and Boxes/Edge.cpp" -o CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.s

CMakeFiles/Dots_and_Boxes.dir/main.cpp.o: CMakeFiles/Dots_and_Boxes.dir/flags.make
CMakeFiles/Dots_and_Boxes.dir/main.cpp.o: /Users/shahdelrefai/CLionProjects/Dots\ and\ Boxes/main.cpp
CMakeFiles/Dots_and_Boxes.dir/main.cpp.o: CMakeFiles/Dots_and_Boxes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Dots_and_Boxes.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dots_and_Boxes.dir/main.cpp.o -MF CMakeFiles/Dots_and_Boxes.dir/main.cpp.o.d -o CMakeFiles/Dots_and_Boxes.dir/main.cpp.o -c "/Users/shahdelrefai/CLionProjects/Dots and Boxes/main.cpp"

CMakeFiles/Dots_and_Boxes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dots_and_Boxes.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shahdelrefai/CLionProjects/Dots and Boxes/main.cpp" > CMakeFiles/Dots_and_Boxes.dir/main.cpp.i

CMakeFiles/Dots_and_Boxes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dots_and_Boxes.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shahdelrefai/CLionProjects/Dots and Boxes/main.cpp" -o CMakeFiles/Dots_and_Boxes.dir/main.cpp.s

CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o: CMakeFiles/Dots_and_Boxes.dir/flags.make
CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o: /Users/shahdelrefai/CLionProjects/Dots\ and\ Boxes/savedGame.cpp
CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o: CMakeFiles/Dots_and_Boxes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o -MF CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o.d -o CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o -c "/Users/shahdelrefai/CLionProjects/Dots and Boxes/savedGame.cpp"

CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/shahdelrefai/CLionProjects/Dots and Boxes/savedGame.cpp" > CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.i

CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/shahdelrefai/CLionProjects/Dots and Boxes/savedGame.cpp" -o CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.s

# Object files for target Dots_and_Boxes
Dots_and_Boxes_OBJECTS = \
"CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o" \
"CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o" \
"CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o" \
"CMakeFiles/Dots_and_Boxes.dir/main.cpp.o" \
"CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o"

# External object files for target Dots_and_Boxes
Dots_and_Boxes_EXTERNAL_OBJECTS =

Dots_and_Boxes: CMakeFiles/Dots_and_Boxes.dir/Box.cpp.o
Dots_and_Boxes: CMakeFiles/Dots_and_Boxes.dir/DotsAndBoxesGame.cpp.o
Dots_and_Boxes: CMakeFiles/Dots_and_Boxes.dir/Edge.cpp.o
Dots_and_Boxes: CMakeFiles/Dots_and_Boxes.dir/main.cpp.o
Dots_and_Boxes: CMakeFiles/Dots_and_Boxes.dir/savedGame.cpp.o
Dots_and_Boxes: CMakeFiles/Dots_and_Boxes.dir/build.make
Dots_and_Boxes: CMakeFiles/Dots_and_Boxes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Dots_and_Boxes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dots_and_Boxes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dots_and_Boxes.dir/build: Dots_and_Boxes
.PHONY : CMakeFiles/Dots_and_Boxes.dir/build

CMakeFiles/Dots_and_Boxes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dots_and_Boxes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dots_and_Boxes.dir/clean

CMakeFiles/Dots_and_Boxes.dir/depend:
	cd "/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/shahdelrefai/CLionProjects/Dots and Boxes" "/Users/shahdelrefai/CLionProjects/Dots and Boxes" "/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug" "/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug" "/Users/shahdelrefai/CLionProjects/Dots and Boxes/cmake-build-debug/CMakeFiles/Dots_and_Boxes.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Dots_and_Boxes.dir/depend

