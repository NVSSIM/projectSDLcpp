# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/180/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/180/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug

# Include any dependencies generated for this target.
include Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.make

# Include the progress variables for this target.
include Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/progress.make

# Include the compile flags for this target's objects.
include Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o: ../Project_SDL_Part1_base/main.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o -MF CMakeFiles/SDL_part1.dir/main.cpp.o.d -o CMakeFiles/SDL_part1.dir/main.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/main.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/main.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/main.cpp > CMakeFiles/SDL_part1.dir/main.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/main.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/main.cpp -o CMakeFiles/SDL_part1.dir/main.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: ../Project_SDL_Part1_base/Project_SDL1.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o -MF CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o.d -o CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Project_SDL1.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Project_SDL1.cpp > CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Project_SDL1.cpp -o CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.o: ../Project_SDL_Part1_base/Character.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.o -MF CMakeFiles/SDL_part1.dir/Character.cpp.o.d -o CMakeFiles/SDL_part1.dir/Character.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Character.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Character.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Character.cpp > CMakeFiles/SDL_part1.dir/Character.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Character.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Character.cpp -o CMakeFiles/SDL_part1.dir/Character.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.o: ../Project_SDL_Part1_base/Position.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.o -MF CMakeFiles/SDL_part1.dir/Position.cpp.o.d -o CMakeFiles/SDL_part1.dir/Position.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Position.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Position.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Position.cpp > CMakeFiles/SDL_part1.dir/Position.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Position.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Position.cpp -o CMakeFiles/SDL_part1.dir/Position.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.o: ../Project_SDL_Part1_base/Ground.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.o -MF CMakeFiles/SDL_part1.dir/Ground.cpp.o.d -o CMakeFiles/SDL_part1.dir/Ground.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Ground.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Ground.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Ground.cpp > CMakeFiles/SDL_part1.dir/Ground.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Ground.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Ground.cpp -o CMakeFiles/SDL_part1.dir/Ground.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.o: ../Project_SDL_Part1_base/Sheep.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.o -MF CMakeFiles/SDL_part1.dir/Sheep.cpp.o.d -o CMakeFiles/SDL_part1.dir/Sheep.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheep.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Sheep.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheep.cpp > CMakeFiles/SDL_part1.dir/Sheep.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Sheep.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheep.cpp -o CMakeFiles/SDL_part1.dir/Sheep.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.o: ../Project_SDL_Part1_base/Wolf.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.o -MF CMakeFiles/SDL_part1.dir/Wolf.cpp.o.d -o CMakeFiles/SDL_part1.dir/Wolf.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Wolf.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Wolf.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Wolf.cpp > CMakeFiles/SDL_part1.dir/Wolf.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Wolf.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Wolf.cpp -o CMakeFiles/SDL_part1.dir/Wolf.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.o: ../Project_SDL_Part1_base/Sheperd.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.o -MF CMakeFiles/SDL_part1.dir/Sheperd.cpp.o.d -o CMakeFiles/SDL_part1.dir/Sheperd.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheperd.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Sheperd.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheperd.cpp > CMakeFiles/SDL_part1.dir/Sheperd.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Sheperd.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheperd.cpp -o CMakeFiles/SDL_part1.dir/Sheperd.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o: ../Project_SDL_Part1_base/Sheperd_dog.cpp
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o -MF CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o.d -o CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o -c /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheperd_dog.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.i"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheperd_dog.cpp > CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.s"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base/Sheperd_dog.cpp -o CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.s

# Object files for target SDL_part1
SDL_part1_OBJECTS = \
"CMakeFiles/SDL_part1.dir/main.cpp.o" \
"CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o" \
"CMakeFiles/SDL_part1.dir/Character.cpp.o" \
"CMakeFiles/SDL_part1.dir/Position.cpp.o" \
"CMakeFiles/SDL_part1.dir/Ground.cpp.o" \
"CMakeFiles/SDL_part1.dir/Sheep.cpp.o" \
"CMakeFiles/SDL_part1.dir/Wolf.cpp.o" \
"CMakeFiles/SDL_part1.dir/Sheperd.cpp.o" \
"CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o"

# External object files for target SDL_part1
SDL_part1_EXTERNAL_OBJECTS =

Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Character.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Position.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Ground.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheep.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Wolf.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Sheperd_dog.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/build.make
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable SDL_part1"
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL_part1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/build: Project_SDL_Part1_base/SDL_part1
.PHONY : Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/build

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/clean:
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base && $(CMAKE_COMMAND) -P CMakeFiles/SDL_part1.dir/cmake_clean.cmake
.PHONY : Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/clean

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/depend:
	cd /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1 /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/Project_SDL_Part1_base /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base /home/etsugo/Documents/projetSDLcpp/Project_SDL_Part1/cmake-build-debug/Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/depend

