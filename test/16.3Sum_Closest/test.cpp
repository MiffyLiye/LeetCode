#include "../include/catch.hpp"
#include "../../src/16.3Sum_Closest/code.h"

using namespace std;
using namespace Three_Sum_Closest;

TEST_CASE("3Sum Closest",
          "[3Sum Closest]")
{
    auto num = vector<int>{-1, 2, 1, -4};
    auto target = 1;
    Solution x;

    auto actual = x.threeSumClosest(num, target);

    auto expected = 2;
    REQUIRE(actual == expected);
}
