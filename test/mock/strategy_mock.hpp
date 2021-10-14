#ifndef STRATEGY_MOCK_HPP
#define STRATEGY_MOCK_HPP

#include "atom/event.hpp"
#include "atom/basic.hpp"

#include <iostream>

namespace atom::mock
{
    struct StrategyMock
    {
        StrategyMock(std::ostream& os) :os_(os){  };

        template<typename T>
        void actOn(const T&) const {
            os_ << "bbb";
        };

        template<typename V>
        void actOn(const atom::TickEvent<atom::TwoWayQuote<V>>& te) const {
            auto ted = te.data();
            os_ << atom::util::timepoint2Str(te.datetime()) << std::endl;
            if (ted.hasBid()) {
                os_ << "bid: " << ted.bid()
                    << ", bidSize: " << ted.bidQty()
                    << std::endl;
            }
            if (ted.hasAsk()) {
                os_ << "ask: " << ted.ask()
                    << ", askSize: " << ted.askQty()
                    << std::endl;
            };
        }
        std::ostream& os_;
    };
} // namespace atom::mock
#endif