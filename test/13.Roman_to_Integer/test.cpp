#include "catch/catch.hpp"
#include "13.Roman_to_Integer/code.h"

using namespace std;
using namespace Roman_to_Integer;

TEST_CASE("Roman to Integer",
          "[Roman to Integer]")
{
    auto s = string{"MCMXII"};
    Solution x;

    auto actual = x.romanToInt(s);

    auto expected = 1912;
    REQUIRE(actual == expected);
}
