#include <gtest/gtest.h>
#include <iostream>
#include <atom/atom.hpp>

#include "atom/trader/trader.hpp"

#include "atom/event.hpp"
#include "atom/basic.hpp"

#include "mock/strategy_mock.hpp"

TEST(Trader_Process_Test, Instantiate) {
    std::ostringstream output;
    atom::mock::StrategyMock st(output);
    atom::agent::Trader t(st);
}

TEST(Trader_Process_Test, TickEvent) {
    std::ostringstream output;
    std::ostringstream result;
    
    atom::mock::StrategyMock st(output);
    atom::agent::Trader t(st);

    atom::TwoWayQuote<> q =atom::TwoWayQuoteBuilder<>()
        .bidPrice(100.10)
        .bidQty(3000)
        .askPrice(101.20)
        .askQty(2000);

    atom::TickEvent<decltype(q)> te("2021-09-17T12:35:00", "%Y-%m-%dT%T", q);
    t.process(te);

    result << "2021-09-17 12:35:00.000000 +0000" << std::endl;
    result << "bid: " << "100.1"
        << ", bidSize: " << "3000"
        << std::endl;
    result << "ask: " << "101.2"
        << ", askSize: " << "2000"
        << std::endl;
    EXPECT_EQ(output.str(), result.str());
}
