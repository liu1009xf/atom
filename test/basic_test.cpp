#include <gtest/gtest.h>
#include <iostream>
#include <string>

// #include "atom/event.hpp"
#include "atom/basic.hpp"
#include "atom/basic/operator.hpp"

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
TEST(Basic_QuoteTest, Quote)
{
    atom::Quote<double, unsigned long int> q(101, 100);
    EXPECT_EQ(q.value(), 101);
    EXPECT_EQ(q.qty(), 100);
}

TEST(Basic_QuoteTest, BidAskExist)
{
    atom::Quote<double, unsigned long int> bid(100, 100); 
    atom::Quote<double, unsigned long int> ask(101, 100);

    atom::TwoWayQuote<atom::Quote<double, unsigned long int>> q(bid, ask);
    EXPECT_EQ(q.ask(), 101);
    EXPECT_EQ(q.bid(), 100);
    EXPECT_EQ(q.askQty(), 100);
    EXPECT_EQ(q.bidQty(), 100);
}

TEST(Basic_QuoteTest, BidOnly)
{
    atom::Quote<double, unsigned long int> bid(100, 100);

    atom::TwoWayQuote<atom::Quote<double, unsigned long int>> q(bid, std::nullopt);
    EXPECT_EQ(q.bid(), 100);
    EXPECT_EQ(q.bidQty(), 100);
    EXPECT_TRUE(q.hasBid());
    EXPECT_FALSE(q.hasAsk());
}

TEST(Basic_QuoteTest, AskOnly)
{
    atom::Quote<double, unsigned long int> ask(100, 100);

    atom::TwoWayQuote<atom::Quote<double, unsigned long int>> q(std::nullopt, ask);
    EXPECT_EQ(q.ask(), 100);
    EXPECT_EQ(q.askQty(), 100);
    EXPECT_FALSE(q.hasBid());
    EXPECT_TRUE(q.hasAsk());
}

TEST(Basic_QuoteBuilderTest, AskOnly)
{
    atom::TwoWayQuote<> q = atom::TwoWayQuoteBuilder<>().askPrice(101)
        .bidPrice(100)
        .bidQty(1000)
        .askQty(10000);
    EXPECT_EQ(q.ask(), 101);
    EXPECT_EQ(q.bid(), 100);
    EXPECT_EQ(q.askQty(), 10000);
    EXPECT_EQ(q.bidQty(), 1000);
}


TEST(Basic_PositionTest, Instantiate)
{
    atom::Position<>();
    atom::Position<>(std::string("B"), 100.0, 133.0);
}

struct PositionTest : public ::testing::Test
{
    PositionTest()
        : p1(atom::Position<>( std::string("B"), 100.0, 100.0)),
        p2(atom::Position<>(std::string("S"), 100.0, 120.0)),
        p3(atom::Position<>(std::string("B"), 100.0, 100.0)),
        p4(atom::Position<>(std::string("B"), 200.0, 400.0))
    {
    }
    atom::Position<> p1;
    atom::Position<> p2;
    atom::Position<> p3;
    atom::Position<> p4;
};

TEST_F(PositionTest, qty_sanity) {
    EXPECT_EQ(p1.qty(), 100.0);
}
TEST_F(PositionTest, price_sanity) {
    EXPECT_EQ(p1.price(), 100.0);
}
TEST_F(PositionTest, position_sum_case_1) {
    EXPECT_EQ(p1 + p3, atom::Position<>(std::string("B"), 200.0, 100.0));
}

TEST_F(PositionTest, position_sum_case_2) {
    EXPECT_EQ(p1 + p2, atom::Position<>(std::string("B"), 0, 100.0));
}

TEST_F(PositionTest, position_sum_case_3) {
    EXPECT_EQ(p1 + p4, atom::Position<>(std::string("B"), 300, 300));
}

// TEST_F(PositionTest, value_sanity) {
//     EXPECT_EQ(p1.value(), 13300.0);
// }

// TEST_F(PositionTest, marketvalue_sanity) {
//     EXPECT_EQ(p1.marketValue(100), 10000.0);
// }

// TEST_F(PositionTest, unrealisedProfit_sanity) {
//     EXPECT_EQ(p1.unrealisedProfit(100), -3300.0);
// }

// TEST_F(PositionTest, combinable_sanity) {
//     bool b1 = atom::op::combinable<decltype(p1), decltype(p2)>::apply(p1, p2);
//     bool b2 = atom::op::combinable<decltype(p2), decltype(p1)>::apply(p2, p1);
//     bool b3 = atom::op::combinable<decltype(p3), decltype(p1)>::apply(p3, p1);
//     bool b4 = atom::op::combinable<decltype(p1), decltype(p3)>::apply(p1, p3);

//     EXPECT_TRUE(b1);
//     EXPECT_TRUE(b2);
//     EXPECT_FALSE(b3);
//     EXPECT_FALSE(b4);
// }

struct ContractTest : public ::testing::Test
{
    using WithMetaQuote = atom::WithMeta<atom::Contract<>, std::map<std::string, std::string>>;
    ContractTest()
        : p1(atom::Contract<>(std::string("AMD"), std::string("Stock"), 1, "USD")),
        p2(WithMetaQuote(std::map<std::string, std::string>{{ "exchange", "Nasdaq" }},
            std::string("AMD"), std::string("Stock"), 1, "USD")),
        p3(atom::Contract<>(std::string("AMD"), std::string("Stock"), 1, "USD"))
    {
    }
    atom::Contract<> p1;
    WithMetaQuote p2;
    atom::Contract<> p3;
};

TEST_F(ContractTest, sym_sanity)
{
    EXPECT_EQ(p1.sym(), "AMD");
    EXPECT_EQ(p2.sym(), "AMD");
}

TEST_F(ContractTest, assetType_sanity)
{
    EXPECT_EQ(p1.assetType(), "Stock");
    EXPECT_EQ(p2.assetType(), "Stock");
}

TEST_F(ContractTest, multiplier_sanity)
{
    EXPECT_EQ(p1.multiplier(), 1);
    EXPECT_EQ(p2.multiplier(), 1);
}

TEST_F(ContractTest, denominated_sanity)
{
    EXPECT_EQ(p1.denominated(), "USD");
    EXPECT_EQ(p2.denominated(), "USD");
}

TEST_F(ContractTest, meta_sanity)
{
    EXPECT_EQ(p2.meta().at("exchange"), "Nasdaq");
}

TEST_F(ContractTest, equality_sanity)
{
    EXPECT_EQ(p1, p3);
}
