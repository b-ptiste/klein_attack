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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/main.c.obj: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\project.dir\main.c.obj -c C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\main.c

CMakeFiles/project.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\main.c > CMakeFiles\project.dir\main.c.i

CMakeFiles/project.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\main.c -o CMakeFiles\project.dir\main.c.s

CMakeFiles/project.dir/kleinAttack.c.obj: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/kleinAttack.c.obj: ../kleinAttack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/project.dir/kleinAttack.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\project.dir\kleinAttack.c.obj -c C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\kleinAttack.c

CMakeFiles/project.dir/kleinAttack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/kleinAttack.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\kleinAttack.c > CMakeFiles\project.dir\kleinAttack.c.i

CMakeFiles/project.dir/kleinAttack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/kleinAttack.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\kleinAttack.c -o CMakeFiles\project.dir\kleinAttack.c.s

CMakeFiles/project.dir/klein64.c.obj: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/klein64.c.obj: ../klein64.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/project.dir/klein64.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\project.dir\klein64.c.obj -c C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\klein64.c

CMakeFiles/project.dir/klein64.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/klein64.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\klein64.c > CMakeFiles\project.dir\klein64.c.i

CMakeFiles/project.dir/klein64.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/klein64.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\klein64.c -o CMakeFiles\project.dir\klein64.c.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/main.c.obj" \
"CMakeFiles/project.dir/kleinAttack.c.obj" \
"CMakeFiles/project.dir/klein64.c.obj"

# External object files for target project
project_EXTERNAL_OBJECTS =

project.exe: CMakeFiles/project.dir/main.c.obj
project.exe: CMakeFiles/project.dir/kleinAttack.c.obj
project.exe: CMakeFiles/project.dir/klein64.c.obj
project.exe: CMakeFiles/project.dir/build.make
project.exe: CMakeFiles/project.dir/linklibs.rsp
project.exe: CMakeFiles/project.dir/objects1.rsp
project.exe: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable project.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project.exe
.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug C:\Users\baptc\Documents\GM\INSA\2A\mobi\cyber\Project\CALLARD_Baptiste_project_KLEIN\project\cmake-build-debug\CMakeFiles\project.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend
