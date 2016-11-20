#include "../include/catch.hpp"
#include "../../src/12.Integer_to_Roman/code.h"

using namespace std;
using namespace Integer_to_Roman;

TEST_CASE("Integer to Roman",
          "[Integer to Roman]")
{
    auto i = 1912;
    Solution x;

    auto actual = x.intToRoman(i);

    auto expected = "MCMXII";
    REQUIRE(actual == expected);
}
