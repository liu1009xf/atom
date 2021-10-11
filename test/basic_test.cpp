#include <gtest/gtest.h>
#include <iostream>
#include <string>

// #include "atom/event.hpp"
#include "atom/basic.hpp"
// #include <atom/basic/datetime/timepoint.hpp>

// TEST(Component, tick_data) {
//     atom::Quote q()
//     std::map<std::string, double> dd = { {"bid", 101.2}, {"ask", 101.3} };
//     atom::TickData<double> td(
//         "2014-09-21 12:35:34.113000 +0000",
//         "%Y-%m-%d %T %z",
//         dd
//     );
//     EXPECT_EQ(atom::util::timepoint2Str(td.getDatetime()),
//         "2014-09-21 12:35:34.113000 +0000");
//     EXPECT_EQ(td.getData("bid"), 101.2);
//     EXPECT_EQ(td.getData("ask"), 101.3);
// }
TEST(Basic, QuoteTest)
{
    atom::OneSideQuote<double, unsigned long int> bid(100, 100); 
    atom::OneSideQuote<double, unsigned long int> ask(101, 100);

    atom::Quote<atom::OneSideQuote<double, unsigned long int>> q(bid, ask);
    EXPECT_EQ(q.ask(), 101);
    EXPECT_EQ(q.bid(), 100);
    EXPECT_EQ(q.askQty(), 100);
    EXPECT_EQ(q.bidQty(), 100);
}