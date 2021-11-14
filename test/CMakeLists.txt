include(CTest)

# find package Foo (example library)
find_package(GTest REQUIRED)
file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(atom_test ${CPP_FILES})

target_link_libraries(atom_test PRIVATE 
    Atom::atom     
    GTest::GTest
    GTest::Main)

# define test
add_test(
    NAME atom_test
    COMMAND $<TARGET_FILE:atom_test>
)

# install(
#   TARGETS atom_test
#   RUNTIME DESTINATION bin
# )
