# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/mohamed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mohamed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohamed/Dev/C++/WonderAudio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamed/Dev/C++/WonderAudio/build

# Include any dependencies generated for this target.
include CMakeFiles/WonderAudio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WonderAudio.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WonderAudio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WonderAudio.dir/flags.make

CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o: CMakeFiles/WonderAudio.dir/flags.make
CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o: /home/mohamed/Dev/C++/WonderAudio/src/AudioDevice.cpp
CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o: CMakeFiles/WonderAudio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/WonderAudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o -MF CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o.d -o CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o -c /home/mohamed/Dev/C++/WonderAudio/src/AudioDevice.cpp

CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/WonderAudio/src/AudioDevice.cpp > CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.i

CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/WonderAudio/src/AudioDevice.cpp -o CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.s

CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o: CMakeFiles/WonderAudio.dir/flags.make
CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o: /home/mohamed/Dev/C++/WonderAudio/src/AudioSource.cpp
CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o: CMakeFiles/WonderAudio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/WonderAudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o -MF CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o.d -o CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o -c /home/mohamed/Dev/C++/WonderAudio/src/AudioSource.cpp

CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/WonderAudio/src/AudioSource.cpp > CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.i

CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/WonderAudio/src/AudioSource.cpp -o CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.s

CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o: CMakeFiles/WonderAudio.dir/flags.make
CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o: /home/mohamed/Dev/C++/WonderAudio/src/AudioData.cpp
CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o: CMakeFiles/WonderAudio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/WonderAudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o -MF CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o.d -o CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o -c /home/mohamed/Dev/C++/WonderAudio/src/AudioData.cpp

CMakeFiles/WonderAudio.dir/src/AudioData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WonderAudio.dir/src/AudioData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/WonderAudio/src/AudioData.cpp > CMakeFiles/WonderAudio.dir/src/AudioData.cpp.i

CMakeFiles/WonderAudio.dir/src/AudioData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WonderAudio.dir/src/AudioData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/WonderAudio/src/AudioData.cpp -o CMakeFiles/WonderAudio.dir/src/AudioData.cpp.s

# Object files for target WonderAudio
WonderAudio_OBJECTS = \
"CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o" \
"CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o" \
"CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o"

# External object files for target WonderAudio
WonderAudio_EXTERNAL_OBJECTS =

libWonderAudio.so: CMakeFiles/WonderAudio.dir/src/AudioDevice.cpp.o
libWonderAudio.so: CMakeFiles/WonderAudio.dir/src/AudioSource.cpp.o
libWonderAudio.so: CMakeFiles/WonderAudio.dir/src/AudioData.cpp.o
libWonderAudio.so: CMakeFiles/WonderAudio.dir/build.make
libWonderAudio.so: /usr/local/lib/libportaudio.so
libWonderAudio.so: CMakeFiles/WonderAudio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mohamed/Dev/C++/WonderAudio/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libWonderAudio.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WonderAudio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WonderAudio.dir/build: libWonderAudio.so
.PHONY : CMakeFiles/WonderAudio.dir/build

CMakeFiles/WonderAudio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WonderAudio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WonderAudio.dir/clean

CMakeFiles/WonderAudio.dir/depend:
	cd /home/mohamed/Dev/C++/WonderAudio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamed/Dev/C++/WonderAudio /home/mohamed/Dev/C++/WonderAudio /home/mohamed/Dev/C++/WonderAudio/build /home/mohamed/Dev/C++/WonderAudio/build /home/mohamed/Dev/C++/WonderAudio/build/CMakeFiles/WonderAudio.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/WonderAudio.dir/depend

