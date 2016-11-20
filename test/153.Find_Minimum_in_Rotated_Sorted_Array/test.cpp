#include "../include/catch.hpp"
#include "../../src/153.Find_Minimum_in_Rotated_Sorted_Array/code.h"

using namespace std;
using namespace Find_Minimum_in_Rotated_Sorted_Array;

TEST_CASE("Find Minimum in Rotated Sorted Array","[Find Minimum in Rotated Sorted Array]")
{
    auto nums = vector<int>{3,4,5,6,7,0,1,2};
    Solution x;

    auto actual = x.findMin(nums);

    REQUIRE(actual == 0);
}

