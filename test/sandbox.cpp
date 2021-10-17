#include <gtest/gtest.h>
#include <iostream>

#include "atom/event.hpp"
#include "atom/basic.hpp"
#include "atom/basic/variant/list_builder.hpp"

struct Visitor {

    Visitor(std::ostream& os) :os_(os) {  };
    template<typename T>
    auto operator ()(const T&) {
        os_ << "aaa" << std::endl;
    };

    auto operator ()(int i) {
        os_ << "i: " << i * 1 << std::endl;
    };
    auto operator ()(double d) {
        os_ << "d: " << d *2<< std::endl;
    };
    std::ostream& os_;
};

TEST(SANDBOX, test1) {
    std::ostringstream output;
    int i = 1;
    double d = 1.0;
    atom::variant::ListBuilder<std::vector<std::variant<std::monostate>>> lb;

    auto l = lb.push_back(d).push_back(d).list();

    auto v = Visitor(output);
    std::cout << l.size() << std::endl;
    bool s = std::is_same_v<decltype(l), std::vector<std::variant<std::monostate, double>>>;
    EXPECT_TRUE(s);
    for (auto x : l)
    {
        std::visit(v, x);
    }
    std::cout << output.str() << std::endl;
}
