#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "atom/basic.hpp"

TEST(Decorator_Test, Meta_dec) {
    std::map<std::string, std::string> meta1{ {"vender","AAA"} };
    atom::WithMeta<atom::Quote<>, std::map<std::string, std::string>> q(meta1, 100.23, 1000);
    EXPECT_EQ(q.value(), 100.23);
    EXPECT_EQ(q.qty(), 1000);
    EXPECT_EQ(q.meta().at("vender"), "AAA");
    EXPECT_EQ(q.meta(std::string("vender")), "AAA");
    EXPECT_EQ(q.meta("vender"), "AAA");
}
