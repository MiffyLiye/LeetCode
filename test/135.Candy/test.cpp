#include "catch/catch.hpp"
#include "135.Candy/code.h"

using namespace std;
using namespace Candy;

TEST_CASE("Give minimum candies", "[Candy]")
{
    auto ratings = vector<int>{2};
    Solution x;

    auto actual = x.candy(ratings);

    auto expected = 1;
    REQUIRE(actual == expected);
}

TEST_CASE("Higher ratings get more than neighbours", "[Candy]")
{
    auto ratings = vector<int>{2, 3};
    Solution x;

    auto actual = x.candy(ratings);

    auto expected = 3;
    REQUIRE(actual == expected);
}
