# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/syktox/Documents/Projekte/TODO_List

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/syktox/Documents/Projekte/TODO_List/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/mylib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/mylib.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/mylib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/mylib.dir/flags.make

lib/CMakeFiles/mylib.dir/codegen:
.PHONY : lib/CMakeFiles/mylib.dir/codegen

lib/CMakeFiles/mylib.dir/mylib.cpp.o: lib/CMakeFiles/mylib.dir/flags.make
lib/CMakeFiles/mylib.dir/mylib.cpp.o: /Users/syktox/Documents/Projekte/TODO_List/lib/mylib.cpp
lib/CMakeFiles/mylib.dir/mylib.cpp.o: lib/CMakeFiles/mylib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/syktox/Documents/Projekte/TODO_List/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/mylib.dir/mylib.cpp.o"
	cd /Users/syktox/Documents/Projekte/TODO_List/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/mylib.dir/mylib.cpp.o -MF CMakeFiles/mylib.dir/mylib.cpp.o.d -o CMakeFiles/mylib.dir/mylib.cpp.o -c /Users/syktox/Documents/Projekte/TODO_List/lib/mylib.cpp

lib/CMakeFiles/mylib.dir/mylib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mylib.dir/mylib.cpp.i"
	cd /Users/syktox/Documents/Projekte/TODO_List/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/syktox/Documents/Projekte/TODO_List/lib/mylib.cpp > CMakeFiles/mylib.dir/mylib.cpp.i

lib/CMakeFiles/mylib.dir/mylib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/mylib.cpp.s"
	cd /Users/syktox/Documents/Projekte/TODO_List/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/syktox/Documents/Projekte/TODO_List/lib/mylib.cpp -o CMakeFiles/mylib.dir/mylib.cpp.s

# Object files for target mylib
mylib_OBJECTS = \
"CMakeFiles/mylib.dir/mylib.cpp.o"

# External object files for target mylib
mylib_EXTERNAL_OBJECTS =

lib/libmylib.a: lib/CMakeFiles/mylib.dir/mylib.cpp.o
lib/libmylib.a: lib/CMakeFiles/mylib.dir/build.make
lib/libmylib.a: lib/CMakeFiles/mylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/syktox/Documents/Projekte/TODO_List/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmylib.a"
	cd /Users/syktox/Documents/Projekte/TODO_List/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean_target.cmake
	cd /Users/syktox/Documents/Projekte/TODO_List/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mylib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/mylib.dir/build: lib/libmylib.a
.PHONY : lib/CMakeFiles/mylib.dir/build

lib/CMakeFiles/mylib.dir/clean:
	cd /Users/syktox/Documents/Projekte/TODO_List/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/mylib.dir/clean

lib/CMakeFiles/mylib.dir/depend:
	cd /Users/syktox/Documents/Projekte/TODO_List/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/syktox/Documents/Projekte/TODO_List /Users/syktox/Documents/Projekte/TODO_List/lib /Users/syktox/Documents/Projekte/TODO_List/build /Users/syktox/Documents/Projekte/TODO_List/build/lib /Users/syktox/Documents/Projekte/TODO_List/build/lib/CMakeFiles/mylib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/CMakeFiles/mylib.dir/depend

