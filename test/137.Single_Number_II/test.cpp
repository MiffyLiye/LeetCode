#include "../include/catch.hpp"
#include "../../src/137.Single_Number_II/code.h"

using namespace std;
using namespace Single_Number_II;

TEST_CASE("Single Number II", "[Single Number II]")
{
    auto nums = vector<int>{1, 1, 1, 2};
    Solution x;

    auto actual = x.singleNumber(nums);

    auto expected = 2;
    REQUIRE(actual == expected);
}
