include(CTest)

# find package Foo (example library)
find_package(GTest REQUIRED)

add_executable(atom_test bar.cpp bar_test.cpp)

target_link_libraries(atom_test PRIVATE 
    Atom::atom     
    GTest::GTest
    GTest::Main)

# define test
add_test(
    NAME atom_test
    COMMAND $<TARGET_FILE:atom_test>
)

install(
  TARGETS atom_test
  RUNTIME DESTINATION bin
)
