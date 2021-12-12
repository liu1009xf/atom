#include <gtest/gtest.h>
#include <iostream>
#include <atom/atom.hpp>

#include "atom/mpl.hpp"

TEST(MPL_TEST, replace_value_type) {
    constexpr bool s = std::is_same_v<
        std::vector<double>,
        atom::mpl::replace_value_type<std::vector<int>, double>::type>;
    EXPECT_TRUE(s);
}

TEST(MPL_TEST, variant_append) {
    using t = atom::mpl::replace_value_type <
        std::vector<std::variant<std::monostate>>,
        atom::mpl::variant_append<std::variant<std::monostate>, int>>::type;
    constexpr bool s = std::is_same_v<
        std::vector<std::variant<std::monostate, int>>,
        t>;
    EXPECT_TRUE(s);
}

TEST(MPL_TEST, variant_append_duplicate) {
    using t = atom::mpl::replace_value_type <
        std::vector<std::variant<std::monostate>>,
        atom::mpl::variant_append<std::variant<std::monostate, int>, int>>::type;
    constexpr bool s = std::is_same_v<
        std::vector<std::variant<std::monostate, int>>,
        t>;
    EXPECT_TRUE(s);
}

struct Print {
    template<typename T>
    void operator()(T) {}
    void operator()(int a) {
        std::cout << a << std::endl;
    }
};

TEST(MPL_TEST, variant_cast) {
    using t = atom::mpl::variant_append<std::variant<std::monostate, int>, double>;
    std::variant<std::monostate, int>  a(1);
    t a1 = atom::mpl::variant_cast(a);
    std::visit(Print(), a1);
    
}

TEST(MPL_TEST, all_test1) {
    constexpr bool is_int = std::is_same_v<int, int>;
    constexpr bool is_double = std::is_same_v<double, double>;
    constexpr bool is_long = std::is_same_v<long, long>;
    constexpr bool result = atom::mpl::all<is_double, is_int, is_long>::value;
    EXPECT_TRUE(result);
}

TEST(MPL_TEST, all_test2) {
    constexpr bool is_int = std::is_same_v<double, int>;
    constexpr bool is_double = std::is_same_v<double, double>;
    constexpr bool is_long = std::is_same_v<long, long>;
    constexpr bool result = atom::mpl::all<is_double, is_int, is_long>::value;
    EXPECT_FALSE(result);
}

TEST(MPL_TEST, any_test1) {
    constexpr bool is_int = std::is_same_v<double, int>;
    constexpr bool is_double = std::is_same_v<double, double>;
    constexpr bool is_long = std::is_same_v<long, long>;
    constexpr bool result = atom::mpl::any<is_double, is_int, is_long>::value;
    EXPECT_TRUE(result);
}

TEST(MPL_TEST, any_test2) {
    constexpr bool is_int = std::is_same_v<double, int>;
    constexpr bool is_double = std::is_same_v<int, double>;
    constexpr bool is_long = std::is_same_v<double, long>;
    constexpr bool result = atom::mpl::any<is_double, is_int, is_long>::value;
    EXPECT_FALSE(result);
}
