# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\elen_\CLionProjects\course

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\elen_\CLionProjects\course\cmake-build-debug

# Include any dependencies generated for this target.
include libs/data_structures/CMakeFiles/data_structures.dir/depend.make
# Include the progress variables for this target.
include libs/data_structures/CMakeFiles/data_structures.dir/progress.make

# Include the compile flags for this target's objects.
include libs/data_structures/CMakeFiles/data_structures.dir/flags.make

libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj: ../libs/data_structures/bitset/bitset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\bitset\bitset.c.obj -c C:\Users\elen_\CLionProjects\course\libs\data_structures\bitset\bitset.c

libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/bitset/bitset.c.i"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elen_\CLionProjects\course\libs\data_structures\bitset\bitset.c > CMakeFiles\data_structures.dir\bitset\bitset.c.i

libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/bitset/bitset.c.s"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elen_\CLionProjects\course\libs\data_structures\bitset\bitset.c -o CMakeFiles\data_structures.dir\bitset\bitset.c.s

libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj: ../libs/data_structures/unordered_array_set/unordered_array_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.obj -c C:\Users\elen_\CLionProjects\course\libs\data_structures\unordered_array_set\unordered_array_set.c

libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.i"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elen_\CLionProjects\course\libs\data_structures\unordered_array_set\unordered_array_set.c > CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.i

libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.s"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elen_\CLionProjects\course\libs\data_structures\unordered_array_set\unordered_array_set.c -o CMakeFiles\data_structures.dir\unordered_array_set\unordered_array_set.c.s

libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj: ../libs/data_structures/ordered_array_set/ordered_array_set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.obj -c C:\Users\elen_\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c

libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.i"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elen_\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c > CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.i

libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.s"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elen_\CLionProjects\course\libs\data_structures\ordered_array_set\ordered_array_set.c -o CMakeFiles\data_structures.dir\ordered_array_set\ordered_array_set.c.s

libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj: ../libs/data_structures/matrix/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\matrix\matrix.c.obj -c C:\Users\elen_\CLionProjects\course\libs\data_structures\matrix\matrix.c

libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/matrix/matrix.c.i"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elen_\CLionProjects\course\libs\data_structures\matrix\matrix.c > CMakeFiles\data_structures.dir\matrix\matrix.c.i

libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/matrix/matrix.c.s"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elen_\CLionProjects\course\libs\data_structures\matrix\matrix.c -o CMakeFiles\data_structures.dir\matrix\matrix.c.s

libs/data_structures/CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.obj: ../libs/data_structures/matrix_tasks/matrix_tasks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.obj"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\matrix_tasks\matrix_tasks.c.obj -c C:\Users\elen_\CLionProjects\course\libs\data_structures\matrix_tasks\matrix_tasks.c

libs/data_structures/CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.i"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elen_\CLionProjects\course\libs\data_structures\matrix_tasks\matrix_tasks.c > CMakeFiles\data_structures.dir\matrix_tasks\matrix_tasks.c.i

libs/data_structures/CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.s"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elen_\CLionProjects\course\libs\data_structures\matrix_tasks\matrix_tasks.c -o CMakeFiles\data_structures.dir\matrix_tasks\matrix_tasks.c.s

libs/data_structures/CMakeFiles/data_structures.dir/string/string.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/string/string.c.obj: ../libs/data_structures/string/string.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/string/string.c.obj"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\string\string.c.obj -c C:\Users\elen_\CLionProjects\course\libs\data_structures\string\string.c

libs/data_structures/CMakeFiles/data_structures.dir/string/string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/string/string.c.i"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elen_\CLionProjects\course\libs\data_structures\string\string.c > CMakeFiles\data_structures.dir\string\string.c.i

libs/data_structures/CMakeFiles/data_structures.dir/string/string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/string/string.c.s"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elen_\CLionProjects\course\libs\data_structures\string\string.c -o CMakeFiles\data_structures.dir\string\string.c.s

libs/data_structures/CMakeFiles/data_structures.dir/string/tasks/tasks.c.obj: libs/data_structures/CMakeFiles/data_structures.dir/flags.make
libs/data_structures/CMakeFiles/data_structures.dir/string/tasks/tasks.c.obj: ../libs/data_structures/string/tasks/tasks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object libs/data_structures/CMakeFiles/data_structures.dir/string/tasks/tasks.c.obj"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\string\tasks\tasks.c.obj -c C:\Users\elen_\CLionProjects\course\libs\data_structures\string\tasks\tasks.c

libs/data_structures/CMakeFiles/data_structures.dir/string/tasks/tasks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/string/tasks/tasks.c.i"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\elen_\CLionProjects\course\libs\data_structures\string\tasks\tasks.c > CMakeFiles\data_structures.dir\string\tasks\tasks.c.i

libs/data_structures/CMakeFiles/data_structures.dir/string/tasks/tasks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/string/tasks/tasks.c.s"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\elen_\CLionProjects\course\libs\data_structures\string\tasks\tasks.c -o CMakeFiles\data_structures.dir\string\tasks\tasks.c.s

# Object files for target data_structures
data_structures_OBJECTS = \
"CMakeFiles/data_structures.dir/bitset/bitset.c.obj" \
"CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj" \
"CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj" \
"CMakeFiles/data_structures.dir/matrix/matrix.c.obj" \
"CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.obj" \
"CMakeFiles/data_structures.dir/string/string.c.obj" \
"CMakeFiles/data_structures.dir/string/tasks/tasks.c.obj"

# External object files for target data_structures
data_structures_EXTERNAL_OBJECTS =

libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/bitset/bitset.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/unordered_array_set/unordered_array_set.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/ordered_array_set/ordered_array_set.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/matrix/matrix.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/matrix_tasks/matrix_tasks.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/string/string.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/string/tasks/tasks.c.obj
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/build.make
libs/data_structures/libdata_structures.a: libs/data_structures/CMakeFiles/data_structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\elen_\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C static library libdata_structures.a"
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean_target.cmake
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\data_structures.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/data_structures/CMakeFiles/data_structures.dir/build: libs/data_structures/libdata_structures.a
.PHONY : libs/data_structures/CMakeFiles/data_structures.dir/build

libs/data_structures/CMakeFiles/data_structures.dir/clean:
	cd /d C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean.cmake
.PHONY : libs/data_structures/CMakeFiles/data_structures.dir/clean

libs/data_structures/CMakeFiles/data_structures.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\elen_\CLionProjects\course C:\Users\elen_\CLionProjects\course\libs\data_structures C:\Users\elen_\CLionProjects\course\cmake-build-debug C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures C:\Users\elen_\CLionProjects\course\cmake-build-debug\libs\data_structures\CMakeFiles\data_structures.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/data_structures/CMakeFiles/data_structures.dir/depend

