# Set SOURCES variable
file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/atom/*.cpp)
set(SOURCES
  ${CPP_FILES}
)

# Set HEADERS_PUBLIC variable (public headers, included in the library)
file(GLOB_RECURSE HPP_FILES ${PROJECT_SOURCE_DIR}/atom/*.hpp)
set(HEADERS_PUBLIC
  ${HPP_FILES}
)

# Set HEADERS_PRIVATE variable, if needed.
# (these private headers won't be included in the library)
# set(HEADERS_PRIVATE
#     foo_private.h
# )

include(${PROJECT_SOURCE_DIR}/cmake/LibraryConfig.cmake)
