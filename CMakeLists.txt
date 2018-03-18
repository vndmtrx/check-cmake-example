# https://libcheck.github.io/check/
cmake_minimum_required(VERSION 3.1)

project(Sample C)

# Custom cmake modules
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Configure wether libraries will be static or shared linked
set(BUILD_SHARED_LIBS OFF)

# Determine minimum C
set(CMAKE_C_STANDARD 11)

# Enable debugging
set(CMAKE_BUILD_TYPE Debug)

# Enable Coverage Tests
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage -O0")

# Show all warning messages
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_subdirectory(src)

enable_testing()

add_subdirectory(tests)

# Add build target to generate Coverage Test Report to all compiled object files
add_custom_target(gcov
  COMMAND mkdir -p Coverage
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Testing
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_command(TARGET gcov POST_BUILD
  COMMAND find ${CMAKE_BINARY_DIR} -type f -name *.c.o -exec gcov {} "\;"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Coverage
  COMMENT "Coverage Reports Generated"
)

# Add 'Coverage' folder into clean target
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES Coverage)
