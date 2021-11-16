#include <gtest/gtest.h>
#include <iostream>

#include "atom/feeder.hpp"
#include "atom/trader.hpp"
#include "mock/strategy_mock.hpp"

struct notifier {
    using event_type = atom::TickEvent<atom::TwoWayQuote<>>;
    template <typename T, typename O>
    static void apply(const T& event, const O& os) {
        for (auto& o : os) {
            o.process(event);
        }
    }
};

TEST(Feedertest, feeder) {
    std::ostringstream output;
    std::ostringstream result;

    atom::mock::StrategyMock st(output);
    using Td = atom::Trader<decltype(st), std::string, std::string>;
    Td t(st);

    atom::TwoWayQuote<> q = atom::TwoWayQuoteBuilder<>()
        .bidPrice(100.10)
        .bidQty(3000)
        .askPrice(101.20)
        .askQty(2000);

    atom::TickEvent<decltype(q)> te("2021-09-17T12:35:00", "%Y-%m-%dT%T", q);

    std::vector<Td> ts;
    ts.push_back(t);
    
    atom::Feeder<std::vector<Td>, notifier> f(ts);
    f.feed(te);

    result << "2021-09-17 12:35:00.000000 +0000" << std::endl;
    result << "bid: " << "100.1"
        << ", bidSize: " << "3000"
        << std::endl;
    result << "ask: " << "101.2"
        << ", askSize: " << "2000"
        << std::endl;
    std::cout<<output.str()<<std::endl;
    EXPECT_EQ(output.str(), result.str());
}
