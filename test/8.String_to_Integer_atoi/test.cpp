#include "catch/catch.hpp"
#include "8.String_to_Integer_atoi/code.h"

using namespace std;
using namespace String_to_Integer_atoi;

TEST_CASE("Implement atoi to convert a string to an integer.",
          "[String to Integer (atoi)]")
{
    auto s = string("123");
    Solution x;

    auto actual = x.atoi(s);

    auto expected = 123;
    REQUIRE(actual == expected);
}

TEST_CASE("discard white spaces",
          "[String to Integer (atoi)]")
{
    auto s = string("   123");
    Solution x;

    auto actual = x.atoi(s);

    auto expected = 123;
    REQUIRE(actual == expected);
}

TEST_CASE("positive value",
          "[String to Integer (atoi)]")
{
    auto s = string("   +123");
    Solution x;

    auto actual = x.atoi(s);

    auto expected = 123;
    REQUIRE(actual == expected);
}

TEST_CASE("negative value",
          "[String to Integer (atoi)]")
{
    auto s = string("   -123");
    Solution x;

    auto actual = x.atoi(s);

    auto expected = -123;
    REQUIRE(actual == expected);
}

TEST_CASE("ignore trailing characters",
          "[String to Integer (atoi)]")
{
    auto s = string("   -123xyz");
    Solution x;

    auto actual = x.atoi(s);

    auto expected = -123;
    REQUIRE(actual == expected);
}

TEST_CASE("invalid -> 0",
          "[String to Integer (atoi)]")
{
    auto s = string("   abc-123xyz");
    Solution x;

    auto actual = x.atoi(s);

    auto expected = 0;
    REQUIRE(actual == expected);
}

TEST_CASE("max -> max",
          "[String to Integer (atoi)]")
{
    auto s = to_string(numeric_limits<int>::max());
    Solution x;

    auto actual = x.atoi(s);

    auto expected = numeric_limits<int>::max();
    REQUIRE(actual == expected);
}

TEST_CASE("min -> min",
          "[String to Integer (atoi)]")
{
    auto s = to_string(numeric_limits<int>::min());
    Solution x;

    auto actual = x.atoi(s);

    auto expected = numeric_limits<int>::min();
    REQUIRE(actual == expected);
}

TEST_CASE("greater than max -> max",
          "[String to Integer (atoi)]")
{
    auto s = to_string(numeric_limits<int>::max()) + "0";
    Solution x;

    auto actual = x.atoi(s);

    auto expected = numeric_limits<int>::max();
    REQUIRE(actual == expected);
}

TEST_CASE("smaller than min -> min",
          "[String to Integer (atoi)]")
{
    auto s = to_string(numeric_limits<int>::min()) + "0";
    Solution x;

    auto actual = x.atoi(s);

    auto expected = numeric_limits<int>::min();
    REQUIRE(actual == expected);
}
