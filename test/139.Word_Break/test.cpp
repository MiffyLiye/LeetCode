#include "catch/catch.hpp"
#include "139.Word_Break/code.h"

using namespace std;
using namespace Word_Break;

TEST_CASE("Word Can Break", "[Word Break]")
{
    auto s = string{"leetcode"};
    auto dict = unordered_set<string>{"leet", "code"};
    Solution x;

    auto canBreak = x.wordBreak(s, dict);

    REQUIRE(canBreak);
}

TEST_CASE("Word Cannot Break", "[Word Break]")
{
    auto s = string{"leetcode"};
    auto dict = unordered_set<string>{"lee", "ode"};
    Solution x;

    auto canBreak = x.wordBreak(s, dict);

    REQUIRE(!canBreak);
}
