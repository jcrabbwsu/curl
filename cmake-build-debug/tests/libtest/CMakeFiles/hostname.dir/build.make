# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/e/Classes/423/zerocopy_fork/curl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug

# Include any dependencies generated for this target.
include tests/libtest/CMakeFiles/hostname.dir/depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/hostname.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/hostname.dir/flags.make

tests/libtest/CMakeFiles/hostname.dir/sethostname.c.o: tests/libtest/CMakeFiles/hostname.dir/flags.make
tests/libtest/CMakeFiles/hostname.dir/sethostname.c.o: ../tests/libtest/sethostname.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/hostname.dir/sethostname.c.o"
	cd /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hostname.dir/sethostname.c.o   -c /mnt/e/Classes/423/zerocopy_fork/curl/tests/libtest/sethostname.c

tests/libtest/CMakeFiles/hostname.dir/sethostname.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hostname.dir/sethostname.c.i"
	cd /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/e/Classes/423/zerocopy_fork/curl/tests/libtest/sethostname.c > CMakeFiles/hostname.dir/sethostname.c.i

tests/libtest/CMakeFiles/hostname.dir/sethostname.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hostname.dir/sethostname.c.s"
	cd /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/e/Classes/423/zerocopy_fork/curl/tests/libtest/sethostname.c -o CMakeFiles/hostname.dir/sethostname.c.s

# Object files for target hostname
hostname_OBJECTS = \
"CMakeFiles/hostname.dir/sethostname.c.o"

# External object files for target hostname
hostname_EXTERNAL_OBJECTS =

tests/libtest/.libs/libhostname-d.so: tests/libtest/CMakeFiles/hostname.dir/sethostname.c.o
tests/libtest/.libs/libhostname-d.so: tests/libtest/CMakeFiles/hostname.dir/build.make
tests/libtest/.libs/libhostname-d.so: tests/libtest/CMakeFiles/hostname.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared module .libs/libhostname-d.so"
	cd /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hostname.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/hostname.dir/build: tests/libtest/.libs/libhostname-d.so

.PHONY : tests/libtest/CMakeFiles/hostname.dir/build

tests/libtest/CMakeFiles/hostname.dir/clean:
	cd /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/hostname.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/hostname.dir/clean

tests/libtest/CMakeFiles/hostname.dir/depend:
	cd /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/Classes/423/zerocopy_fork/curl /mnt/e/Classes/423/zerocopy_fork/curl/tests/libtest /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/tests/libtest /mnt/e/Classes/423/zerocopy_fork/curl/cmake-build-debug/tests/libtest/CMakeFiles/hostname.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/hostname.dir/depend
