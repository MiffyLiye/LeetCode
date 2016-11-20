#include "../include/catch.hpp"
#include "../../src/7.Reverse_Integer/code.h"

using namespace std;
using namespace Reverse_Integer;

TEST_CASE("Reverse digits of an integer",
          "[Reverse Integer]")
{
    auto i = 123;
    Solution x;

    auto actual = x.reverse(i);

    auto expected = 321;
    REQUIRE(actual == expected);
}

TEST_CASE("-123 -> -321",
          "[Reverse Integer]")
{
    auto i = -123;
    Solution x;

    auto actual = x.reverse(i);

    auto expected = -321;
    REQUIRE(actual == expected);
}
