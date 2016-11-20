#include "../include/catch.hpp"
#include "../../src/10.Regular_Expression_Matching/code.h"

using namespace std;
using namespace Regular_Expression_Matching;

TEST_CASE("Implement regular expression matching with support for '.' and '*'.",
          "[Regular Expression Matching]")
{
    auto s = string{"aa"};
    auto p = string{"a"};
    Solution x;

    auto actual = x.isMatch(s, p);

    auto expected = false;
    REQUIRE(actual == expected);
}

TEST_CASE("aa -> aa -> true",
          "[Regular Expression Matching]")
{
    auto s = string{"aa"};
    auto p = string{"aa"};
    Solution x;

    auto actual = x.isMatch(s, p);

    auto expected = true;
    REQUIRE(actual == expected);
}

TEST_CASE("aaa -> aa -> false",
          "[Regular Expression Matching]")
{
    auto s = string{"aaa"};
    auto p = string{"aa"};
    Solution x;

    auto actual = x.isMatch(s, p);

    auto expected = false;
    REQUIRE(actual == expected);
}

TEST_CASE("aa -> a* -> true",
          "[Regular Expression Matching]")
{
    auto s = string{"aa"};
    auto p = string{"a*"};
    Solution x;

    auto actual = x.isMatch(s, p);

    auto expected = true;
    REQUIRE(actual == expected);
}

TEST_CASE("aa -> .* -> true",
          "[Regular Expression Matching]")
{
    auto s = string{"aa"};
    auto p = string{".*"};
    Solution x;

    auto actual = x.isMatch(s, p);

    auto expected = true;
    REQUIRE(actual == expected);
}

TEST_CASE("ab -> .* -> true",
          "[Regular Expression Matching]")
{
    auto s = string{"ab"};
    auto p = string{".*"};
    Solution x;

    auto actual = x.isMatch(s, p);

    auto expected = true;
    REQUIRE(actual == expected);
}

TEST_CASE("aab -> c*a*b -> true",
          "[Regular Expression Matching]")
{
    auto s = string{"aab"};
    auto p = string{"c*a*b"};
    Solution x;

    auto actual = x.isMatch(s, p);

    auto expected = true;
    REQUIRE(actual == expected);
}
