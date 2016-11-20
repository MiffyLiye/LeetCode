#include "../include/catch.hpp"
#include "../../src/1.Two_Sum/code.h"

using namespace std;
using namespace Two_Sum;

TEST_CASE("Return indices of the two numbers such that they add up to a specific target.",
          "[Two Sum]")
{
    auto numbers = vector<int> {2, 7, 11, 15};
    auto target = int{9};
    Solution x;

    auto actual = x.twoSum(numbers, target);

    auto expected = vector<int>{0, 1};
    REQUIRE(actual == expected);
}