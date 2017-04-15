#include "catch/catch.hpp"
#include "152.Maximum_Product_Subarray/code.h"

using namespace std;
using namespace Maximum_Product_Subarray;

TEST_CASE("Maximum Product Subarray","[Maximum Product Subarray]")
{
    auto nums = vector<int>{2,3,-2,4};
    Solution x;

    auto actual = x.maxProduct(nums);

    REQUIRE(actual == 6);
}

