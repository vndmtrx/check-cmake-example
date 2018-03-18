# If pkg-config is not installed on the system, then the CHECK_INSTALL_DIR var
# must be set to the install location of Check. For example, on Windows, this
# may be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")

find_package(Check REQUIRED)

include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)

# Since Check uses Threads to paralelize the tests, it's mandatory
# add pthread as a dependency, alongside the Check libraries.
add_executable(test_sample test_sample.c)
target_link_libraries(test_sample sample ${CHECK_LIBRARIES} pthread)

# Create testing target and redirect its output to `Testing` folder
add_test(NAME test_sample COMMAND test_sample WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)

# Aditional Valgrind test to check memory leaks in code
include(FindValgrind)

add_custom_target(valgrind_test_sample
  COMMAND ${VALGRIND_PROGRAM} --leak-check=full $<TARGET_FILE:test_sample>
  DEPENDS test_sample
)
