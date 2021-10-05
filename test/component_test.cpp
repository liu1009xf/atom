#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "atom/component/data/tick_data.hpp"
#include <atom/basic/datetime/timepoint.hpp>

TEST(Component, tick_data) {
    std::map<std::string, double> dd = { {"bid", 101.2}, {"ask", 101.3} };
    atom::component::TickData td(
        "2014-09-21 12:35:34.113000 +0000",
        "%Y-%m-%d %T %z",
        dd
    );
    EXPECT_EQ(atom::util::timepoint2Str(td.getTime()),
        "2014-09-21 12:35:34.113000 +0000");
    EXPECT_EQ(td.getData("bid"), 101.2);
    EXPECT_EQ(td.getData("ask"), 101.3);
}
