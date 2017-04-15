#include "catch/catch.hpp"
#include "136.Single_Number/code.h"

using namespace std;
using namespace Single_Number;

TEST_CASE("Single Number", "[Single Number]")
{
    auto nums = vector<int>{1, 1, 2};
    Solution x;

    auto actual = x.singleNumber(nums);

    auto expected = 2;
    REQUIRE(actual == expected);
}
