#include "catch/catch.hpp"
#include "3.Longest_Substring_Without_Repeating_Characters/code.h"

using namespace std;
using namespace Longest_Substring_Without_Repeating_Characters;

TEST_CASE("Given a string, find the length of the longest substring without repeating characters.",
          "[Longest Substring Without Repeating Characters]")
{
    string s{"abcabcbb"};

    Solution x;

    REQUIRE(x.lengthOfLongestSubstring(s) == 3);
}

TEST_CASE("bbbbb -> b, 1",
          "[Longest Substring Without Repeating Characters]")
{
    string s{"bbbbb"};

    Solution x;

    REQUIRE(x.lengthOfLongestSubstring(s) == 1);
}

TEST_CASE("pwwkew -> wke, 3",
          "[Longest Substring Without Repeating Characters]")
{
    auto s = string{"pwwkew"};
    Solution x;

    auto actual = x.lengthOfLongestSubstring(s);
    REQUIRE(actual == 3);
}
