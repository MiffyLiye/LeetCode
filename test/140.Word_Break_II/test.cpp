#include "../include/catch.hpp"
#include "../../src/140.Word_Break_II/code.h"

#include <algorithm>

using namespace std;
using namespace Word_Break_II;

namespace Word_Break_II
{
    template<typename T, typename V>
    bool contains(T begin, T end, V value)
    {
        T i = find(begin, end, value);
        return i != end;
    }
}

TEST_CASE("Word Break II", "[Word Break II]")
{
    auto s = string{"catsanddog"};
    auto dict = unordered_set<string>{"cat", "cats", "and", "sand", "dog"};
    Solution x;

    auto solutions = x.wordBreak(s, dict);

    REQUIRE(solutions.size() == 2);
    REQUIRE(contains(solutions.begin(), solutions.end(), string{"cats and dog"}));
    REQUIRE(contains(solutions.begin(), solutions.end(), string{"cat sand dog"}));
}
