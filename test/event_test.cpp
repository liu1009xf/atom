#include <gtest/gtest.h>
#include <iostream>

#include "atom/event.hpp"
#include "atom/basic.hpp"

TEST(Event_TickEvent, Instantiation) {
    atom::TickEvent<double> te(
        "2014-09-21 12:35:34.113000 +0000",
        2000);
    EXPECT_EQ(atom::util::timepoint2Str(te.datetime()),
        "2014-09-21 12:35:34.113000 +0000");
    EXPECT_EQ(te.data(), 2000);
}

TEST(Event_TickEvent, DateTimeFormat) {
    atom::TickEvent<double> te(
        "2014-09-21T12:35:34.113000",
        "%Y-%m-%dT%T",
        2000);
    EXPECT_EQ(atom::util::timepoint2Str(te.datetime()),
        "2014-09-21 12:35:34.113000 +0000");
    EXPECT_EQ(te.data(), 2000);
}

TEST(Event_TickEvent, InstantiationQuote) {
    atom::TickEvent<atom::Quote<>> te(
        "2014-09-21 12:35:34.113000 +0000",
        atom::Quote<>(102.99, 20000));
    EXPECT_EQ(atom::util::timepoint2Str(te.datetime()),
        "2014-09-21 12:35:34.113000 +0000");
    EXPECT_EQ(te.data().value(), 102.99);
    EXPECT_EQ(te.data().qty(), 20000);
}