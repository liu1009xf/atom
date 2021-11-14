#include <gtest/gtest.h>
#include <iostream>
#include <atom/atom.hpp>

#include "atom/basic/mpl/container.hpp"
#include "atom/basic/mpl/variant.hpp"

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
