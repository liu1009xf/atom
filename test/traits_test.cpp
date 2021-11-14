#include <gtest/gtest.h>
#include <iostream>

#include "atom/basic/type_traits.hpp"
#include <optional>
#include <type_traits>
TEST(Type_Traits, optional1) {
    constexpr bool o = atom::traits::is_optional_of_v<std::string, int>;
    EXPECT_FALSE(o);
}
TEST(Type_Traits, optional2) {
    constexpr bool o = atom::traits::is_optional_of_v<int, int>;
    EXPECT_TRUE(o);
}
TEST(Type_Traits, optional3) {
    constexpr bool o = atom::traits::is_optional_of_v<std::nullopt_t, int>;
    EXPECT_TRUE(o);
}
TEST(Type_Traits, optional4) {
    constexpr bool o = atom::traits::is_optional_of_v<double, int>;
    EXPECT_TRUE(o);
}
TEST(Type_Traits, optional5) {
    constexpr bool o = atom::traits::is_optional_of_v<int, double>;
    EXPECT_TRUE(o);
}