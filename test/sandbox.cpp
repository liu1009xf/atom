#include <gtest/gtest.h>
#include <iostream>
#include <atom/foo.h>


#include <vector>
#include <functional>

#include "atom/basic/variant/observer.hpp"
#include "atom/event/tick_event.hpp"
#include "atom/engine/feed_engine.hpp"
#include "atom/agent/trader/trader.hpp"
#include "atom/basic/variant/contract.hpp"

TEST(Sandbox, test1) {
    atom::engine::detail::FeedEngine fe(atom::variant::contract{});
    atom::agent::Trader trader;
    atom::event::detail::TickEvent tick;
    fe.addObserver(trader);
    fe.notify(tick);
}
