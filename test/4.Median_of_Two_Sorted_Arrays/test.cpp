#include "../include/catch.hpp"
#include "../../src/4.Median_of_Two_Sorted_Arrays/code.h"

using namespace std;
using namespace Median_of_Two_Sorted_Arrays;

TEST_CASE("Find the median of the two sorted arrays.",
          "[Median of Two Sorted Arrays]")
{
    auto a = vector<int>{1, 3};
    auto b = vector<int>{2};
    Solution x;

    auto actual = x.findMedianSortedArrays(a.data(), static_cast<int>(a.size()), b.data(), static_cast<int>(b.size()));

    auto expected = 2;
    REQUIRE(actual == expected);
}

TEST_CASE("[1, 2] -> [3, 4] -> 2.5",
          "[Median of Two Sorted Arrays]")
{
    auto a = vector<int>{1, 2};
    auto b = vector<int>{3, 4};
    Solution x;

    auto actual = x.findMedianSortedArrays(a.data(), static_cast<int>(a.size()), b.data(), static_cast<int>(b.size()));

    auto expected = static_cast<double>(2 + 3) / 2;
    REQUIRE(actual == expected);
}