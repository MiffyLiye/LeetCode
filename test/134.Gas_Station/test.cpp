#include "../include/catch.hpp"
#include "../../src/134.Gas_Station/code.h"

using namespace std;
using namespace Gas_Station;

TEST_CASE("return start index when can complete circuit", "[Gas Station]")
{
    auto gas = vector<int>{1,2};
    auto cost = vector<int>{2,1};
    Solution x;

    auto actual = x.canCompleteCircuit(gas, cost);

    auto start_index = 1;
    REQUIRE(actual == start_index);
}

TEST_CASE("return -1 when cannot complete circuit", "[Gas Station]")
{
    auto gas = vector<int>{1,2};
    auto cost = vector<int>{2,2};
    Solution x;

    auto actual = x.canCompleteCircuit(gas, cost);

    REQUIRE(actual == -1);
}
