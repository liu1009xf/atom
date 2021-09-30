// #include "testlib/foo.h"

// int main(int argc, char *argv[]) {
//   foo_print_version();
//   return 0;
// }

#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}