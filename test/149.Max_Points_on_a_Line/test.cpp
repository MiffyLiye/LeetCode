#include "catch/catch.hpp"
#include "149.Max_Points_on_a_Line/code.h"

using namespace std;
using namespace Max_Points_on_a_Line;

TEST_CASE("Max Points on a Line", "[Max Points on a Line]")
{
    auto points = vector<Point>{{0, 0},
                                {0, 1},
                                {1, 0},
                                {1, 1},
                                {1, 1}};
    Solution x;

    auto actual = x.maxPoints(points);

    REQUIRE(actual == 3);
}