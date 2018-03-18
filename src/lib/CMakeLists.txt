add_library(sample sample.c)

target_include_directories(sample PUBLIC includes)
set_target_properties(sample PROPERTIES PUBLIC_HEADER includes/sample.h)

set_target_properties(sample PROPERTIES SOVERSION 1)

install(TARGETS sample
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)
