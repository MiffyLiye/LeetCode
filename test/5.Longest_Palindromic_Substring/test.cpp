#include "catch/catch.hpp"
#include "5.Longest_Palindromic_Substring/code.h"

using namespace std;
using namespace Longest_Palindromic_Substring;

TEST_CASE("Find the longest palindromic substring in s.",
          "[Longest Palindromic Substring]")
{
    auto s = string{"babad"};
    Solution x;

    auto actual = x.longestPalindrome(s);

    auto expected = string{"bab"};
    auto orExpected = string{"aba"};
    auto found = actual == expected || actual == orExpected;
    REQUIRE(found);
}

TEST_CASE("cbbd -> bb",
          "[Longest Palindromic Substring]")
{
    auto s = string{"cbbd"};
    Solution x;

    auto actual = x.longestPalindrome(s);

    auto expected = string{"bb"};
    REQUIRE(actual == expected);
}