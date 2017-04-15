#include "catch/catch.hpp"
#include "154.Find_Minimum_in_Rotated_Sorted_Array_II/code.h"

using namespace std;
using namespace Find_Minimum_in_Rotated_Sorted_Array_II;

TEST_CASE("duplicate in middle","[Find Minimum in Rotated Sorted Array II]")
{
    auto nums = vector<int>{3,4,5,6,7,7,7,7,0,1,2};
    Solution x;

    auto actual = x.findMin(nums);

    REQUIRE(actual == 0);
}

TEST_CASE("duplicate on edge","[Find Minimum in Rotated Sorted Array II]")
{
    auto nums = vector<int>{3,3,1,3};
    Solution x;

    auto actual = x.findMin(nums);

    REQUIRE(actual == 1);
}
