# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = L:/Code/stl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = L:/Code/stl/build

# Include any dependencies generated for this target.
include CMakeFiles/test_stl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_stl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_stl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_stl.dir/flags.make

CMakeFiles/test_stl.dir/codegen:
.PHONY : CMakeFiles/test_stl.dir/codegen

CMakeFiles/test_stl.dir/test/test.c.obj: CMakeFiles/test_stl.dir/flags.make
CMakeFiles/test_stl.dir/test/test.c.obj: CMakeFiles/test_stl.dir/includes_C.rsp
CMakeFiles/test_stl.dir/test/test.c.obj: L:/Code/stl/test/test.c
CMakeFiles/test_stl.dir/test/test.c.obj: CMakeFiles/test_stl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=L:/Code/stl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_stl.dir/test/test.c.obj"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_stl.dir/test/test.c.obj -MF CMakeFiles/test_stl.dir/test/test.c.obj.d -o CMakeFiles/test_stl.dir/test/test.c.obj -c L:/Code/stl/test/test.c

CMakeFiles/test_stl.dir/test/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_stl.dir/test/test.c.i"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E L:/Code/stl/test/test.c > CMakeFiles/test_stl.dir/test/test.c.i

CMakeFiles/test_stl.dir/test/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_stl.dir/test/test.c.s"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S L:/Code/stl/test/test.c -o CMakeFiles/test_stl.dir/test/test.c.s

CMakeFiles/test_stl.dir/test/test_vector.c.obj: CMakeFiles/test_stl.dir/flags.make
CMakeFiles/test_stl.dir/test/test_vector.c.obj: CMakeFiles/test_stl.dir/includes_C.rsp
CMakeFiles/test_stl.dir/test/test_vector.c.obj: L:/Code/stl/test/test_vector.c
CMakeFiles/test_stl.dir/test/test_vector.c.obj: CMakeFiles/test_stl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=L:/Code/stl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_stl.dir/test/test_vector.c.obj"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_stl.dir/test/test_vector.c.obj -MF CMakeFiles/test_stl.dir/test/test_vector.c.obj.d -o CMakeFiles/test_stl.dir/test/test_vector.c.obj -c L:/Code/stl/test/test_vector.c

CMakeFiles/test_stl.dir/test/test_vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_stl.dir/test/test_vector.c.i"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E L:/Code/stl/test/test_vector.c > CMakeFiles/test_stl.dir/test/test_vector.c.i

CMakeFiles/test_stl.dir/test/test_vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_stl.dir/test/test_vector.c.s"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S L:/Code/stl/test/test_vector.c -o CMakeFiles/test_stl.dir/test/test_vector.c.s

CMakeFiles/test_stl.dir/test/test_map.c.obj: CMakeFiles/test_stl.dir/flags.make
CMakeFiles/test_stl.dir/test/test_map.c.obj: CMakeFiles/test_stl.dir/includes_C.rsp
CMakeFiles/test_stl.dir/test/test_map.c.obj: L:/Code/stl/test/test_map.c
CMakeFiles/test_stl.dir/test/test_map.c.obj: CMakeFiles/test_stl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=L:/Code/stl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_stl.dir/test/test_map.c.obj"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_stl.dir/test/test_map.c.obj -MF CMakeFiles/test_stl.dir/test/test_map.c.obj.d -o CMakeFiles/test_stl.dir/test/test_map.c.obj -c L:/Code/stl/test/test_map.c

CMakeFiles/test_stl.dir/test/test_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_stl.dir/test/test_map.c.i"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E L:/Code/stl/test/test_map.c > CMakeFiles/test_stl.dir/test/test_map.c.i

CMakeFiles/test_stl.dir/test/test_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_stl.dir/test/test_map.c.s"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S L:/Code/stl/test/test_map.c -o CMakeFiles/test_stl.dir/test/test_map.c.s

CMakeFiles/test_stl.dir/test/stu.c.obj: CMakeFiles/test_stl.dir/flags.make
CMakeFiles/test_stl.dir/test/stu.c.obj: CMakeFiles/test_stl.dir/includes_C.rsp
CMakeFiles/test_stl.dir/test/stu.c.obj: L:/Code/stl/test/stu.c
CMakeFiles/test_stl.dir/test/stu.c.obj: CMakeFiles/test_stl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=L:/Code/stl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test_stl.dir/test/stu.c.obj"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_stl.dir/test/stu.c.obj -MF CMakeFiles/test_stl.dir/test/stu.c.obj.d -o CMakeFiles/test_stl.dir/test/stu.c.obj -c L:/Code/stl/test/stu.c

CMakeFiles/test_stl.dir/test/stu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_stl.dir/test/stu.c.i"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E L:/Code/stl/test/stu.c > CMakeFiles/test_stl.dir/test/stu.c.i

CMakeFiles/test_stl.dir/test/stu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_stl.dir/test/stu.c.s"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S L:/Code/stl/test/stu.c -o CMakeFiles/test_stl.dir/test/stu.c.s

CMakeFiles/test_stl.dir/test/test_stack.c.obj: CMakeFiles/test_stl.dir/flags.make
CMakeFiles/test_stl.dir/test/test_stack.c.obj: CMakeFiles/test_stl.dir/includes_C.rsp
CMakeFiles/test_stl.dir/test/test_stack.c.obj: L:/Code/stl/test/test_stack.c
CMakeFiles/test_stl.dir/test/test_stack.c.obj: CMakeFiles/test_stl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=L:/Code/stl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/test_stl.dir/test/test_stack.c.obj"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_stl.dir/test/test_stack.c.obj -MF CMakeFiles/test_stl.dir/test/test_stack.c.obj.d -o CMakeFiles/test_stl.dir/test/test_stack.c.obj -c L:/Code/stl/test/test_stack.c

CMakeFiles/test_stl.dir/test/test_stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_stl.dir/test/test_stack.c.i"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E L:/Code/stl/test/test_stack.c > CMakeFiles/test_stl.dir/test/test_stack.c.i

CMakeFiles/test_stl.dir/test/test_stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_stl.dir/test/test_stack.c.s"
	C:/w64devkit/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S L:/Code/stl/test/test_stack.c -o CMakeFiles/test_stl.dir/test/test_stack.c.s

# Object files for target test_stl
test_stl_OBJECTS = \
"CMakeFiles/test_stl.dir/test/test.c.obj" \
"CMakeFiles/test_stl.dir/test/test_vector.c.obj" \
"CMakeFiles/test_stl.dir/test/test_map.c.obj" \
"CMakeFiles/test_stl.dir/test/stu.c.obj" \
"CMakeFiles/test_stl.dir/test/test_stack.c.obj"

# External object files for target test_stl
test_stl_EXTERNAL_OBJECTS =

test_stl.exe: CMakeFiles/test_stl.dir/test/test.c.obj
test_stl.exe: CMakeFiles/test_stl.dir/test/test_vector.c.obj
test_stl.exe: CMakeFiles/test_stl.dir/test/test_map.c.obj
test_stl.exe: CMakeFiles/test_stl.dir/test/stu.c.obj
test_stl.exe: CMakeFiles/test_stl.dir/test/test_stack.c.obj
test_stl.exe: CMakeFiles/test_stl.dir/build.make
test_stl.exe: libstl.a
test_stl.exe: CMakeFiles/test_stl.dir/linkLibs.rsp
test_stl.exe: CMakeFiles/test_stl.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=L:/Code/stl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable test_stl.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/test_stl.dir/objects.a
	C:/w64devkit/bin/ar.exe qc CMakeFiles/test_stl.dir/objects.a @CMakeFiles/test_stl.dir/objects1.rsp
	C:/w64devkit/bin/gcc.exe  -Wall -Wextra -O2 -O3 -DNDEBUG -Wl,--whole-archive CMakeFiles/test_stl.dir/objects.a -Wl,--no-whole-archive -o test_stl.exe -Wl,--out-implib,libtest_stl.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/test_stl.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/test_stl.dir/build: test_stl.exe
.PHONY : CMakeFiles/test_stl.dir/build

CMakeFiles/test_stl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_stl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_stl.dir/clean

CMakeFiles/test_stl.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" L:/Code/stl L:/Code/stl L:/Code/stl/build L:/Code/stl/build L:/Code/stl/build/CMakeFiles/test_stl.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_stl.dir/depend

