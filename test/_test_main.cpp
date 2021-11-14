// #include "testlib/foo.h"

// int main(int argc, char *argv[]) {
//   foo_print_version();
//   return 0;
// }

#include <gtest/gtest.h>
#include "atom/atom.hpp"

int main(int argc, char** argv)
{
    std::cout<<atom::atom_version()<<std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}