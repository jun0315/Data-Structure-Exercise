# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "H:\Clion\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "H:\Clion\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "H:\Data Structure Exercise\exam\exam6\problem1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/problem1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problem1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problem1.dir/flags.make

CMakeFiles/problem1.dir/main.cpp.obj: CMakeFiles/problem1.dir/flags.make
CMakeFiles/problem1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problem1.dir/main.cpp.obj"
	H:\Clion\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\problem1.dir\main.cpp.obj -c "H:\Data Structure Exercise\exam\exam6\problem1\main.cpp"

CMakeFiles/problem1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem1.dir/main.cpp.i"
	H:\Clion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Data Structure Exercise\exam\exam6\problem1\main.cpp" > CMakeFiles\problem1.dir\main.cpp.i

CMakeFiles/problem1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem1.dir/main.cpp.s"
	H:\Clion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Data Structure Exercise\exam\exam6\problem1\main.cpp" -o CMakeFiles\problem1.dir\main.cpp.s

CMakeFiles/problem1.dir/Sort.cpp.obj: CMakeFiles/problem1.dir/flags.make
CMakeFiles/problem1.dir/Sort.cpp.obj: ../Sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/problem1.dir/Sort.cpp.obj"
	H:\Clion\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\problem1.dir\Sort.cpp.obj -c "H:\Data Structure Exercise\exam\exam6\problem1\Sort.cpp"

CMakeFiles/problem1.dir/Sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem1.dir/Sort.cpp.i"
	H:\Clion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Data Structure Exercise\exam\exam6\problem1\Sort.cpp" > CMakeFiles\problem1.dir\Sort.cpp.i

CMakeFiles/problem1.dir/Sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem1.dir/Sort.cpp.s"
	H:\Clion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Data Structure Exercise\exam\exam6\problem1\Sort.cpp" -o CMakeFiles\problem1.dir\Sort.cpp.s

CMakeFiles/problem1.dir/Solution.cpp.obj: CMakeFiles/problem1.dir/flags.make
CMakeFiles/problem1.dir/Solution.cpp.obj: ../Solution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/problem1.dir/Solution.cpp.obj"
	H:\Clion\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\problem1.dir\Solution.cpp.obj -c "H:\Data Structure Exercise\exam\exam6\problem1\Solution.cpp"

CMakeFiles/problem1.dir/Solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problem1.dir/Solution.cpp.i"
	H:\Clion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "H:\Data Structure Exercise\exam\exam6\problem1\Solution.cpp" > CMakeFiles\problem1.dir\Solution.cpp.i

CMakeFiles/problem1.dir/Solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problem1.dir/Solution.cpp.s"
	H:\Clion\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "H:\Data Structure Exercise\exam\exam6\problem1\Solution.cpp" -o CMakeFiles\problem1.dir\Solution.cpp.s

# Object files for target problem1
problem1_OBJECTS = \
"CMakeFiles/problem1.dir/main.cpp.obj" \
"CMakeFiles/problem1.dir/Sort.cpp.obj" \
"CMakeFiles/problem1.dir/Solution.cpp.obj"

# External object files for target problem1
problem1_EXTERNAL_OBJECTS =

problem1.exe: CMakeFiles/problem1.dir/main.cpp.obj
problem1.exe: CMakeFiles/problem1.dir/Sort.cpp.obj
problem1.exe: CMakeFiles/problem1.dir/Solution.cpp.obj
problem1.exe: CMakeFiles/problem1.dir/build.make
problem1.exe: CMakeFiles/problem1.dir/linklibs.rsp
problem1.exe: CMakeFiles/problem1.dir/objects1.rsp
problem1.exe: CMakeFiles/problem1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable problem1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\problem1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problem1.dir/build: problem1.exe

.PHONY : CMakeFiles/problem1.dir/build

CMakeFiles/problem1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\problem1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/problem1.dir/clean

CMakeFiles/problem1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "H:\Data Structure Exercise\exam\exam6\problem1" "H:\Data Structure Exercise\exam\exam6\problem1" "H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug" "H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug" "H:\Data Structure Exercise\exam\exam6\problem1\cmake-build-debug\CMakeFiles\problem1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/problem1.dir/depend

