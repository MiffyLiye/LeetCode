

#include "catch/catch.hpp"
#include "11.Container_With_Most_Water/code.h"

using namespace std;
using namespace Container_With_Most_Water;

TEST_CASE("Container With Most Water",
          "[Container With Most Water]")
{
    auto height = vector<int>{1, 3, 5, 7, 11, 13, 17, 19};
    Solution x;

    auto actual = x.maxArea(height);

    auto expected = 33;
    REQUIRE(actual == expected);
}
