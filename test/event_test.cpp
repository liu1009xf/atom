#include <gtest/gtest.h>
#include <iostream>
#include <atom/event/tick_event.hpp>

TEST(Event, tick) {
    auto tick = atom::event::detail::TickEvent();
    EXPECT_EQ(tick.show(), 1);
}