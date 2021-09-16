#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include <atom/util/datetime/timepoint.hpp>

class DateTimeTest : public ::testing::Test
{
public:

    DateTimeTest()
        : st1("2014-09-21 12:35:34.113000 +0000"),
        st2("2014-09-21 12:35:34.113001 +0000"),
        st3("2014-09-21 12:35:34.112000 +0000")
    {
    }

    std::string st1;
    std::string st2;
    std::string st3;
};

TEST_F(DateTimeTest, strTimepointConversion) {
    auto t1 = atom::util::clock::detail::str2Timepoint(this->st1);
    auto t2 = atom::util::clock::detail::timepoint2Str(t1);
    EXPECT_EQ(st1, t2);
}

TEST_F(DateTimeTest, timepointComparasion) {
    auto t1 = atom::util::clock::detail::str2Timepoint(st1);
    auto t2 = atom::util::clock::detail::str2Timepoint(st2);
    auto t3 = atom::util::clock::detail::str2Timepoint(st3);
    ASSERT_GT(t2, t1);
    ASSERT_GT(t1, t3);
    ASSERT_GT(t2, t3);
    ASSERT_FALSE(t3 > t2);
    ASSERT_FALSE(t1 > t2);
    ASSERT_FALSE(t3 > t1);
    ASSERT_FALSE(t3 == t2);
    ASSERT_FALSE(t1 == t2);
    ASSERT_FALSE(t3 == t1);
}