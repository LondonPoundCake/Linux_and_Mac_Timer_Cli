# For macOS builds

# Set the system name to Darwin (macOS)
set(CMAKE_SYSTEM_NAME Darwin)

# You can leave the system version as "Unknown" or retrieve the macOS version dynamically
set(CMAKE_SYSTEM_VERSION "Unknown")

# Compiler and compiler flags for macOS
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# No need to specify a target triple for macOS
# set(triple x86_64-pc-linux-gnu)  # Remove this line entirely

# Remove Linux-specific search paths
set(CMAKE_FIND_ROOT_PATH "")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Comment out or modify Linux-specific Clang options
# include("${CMAKE_CURRENT_LIST_DIR}/ClangOptions.cmake")
