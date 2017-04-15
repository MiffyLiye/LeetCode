#include "catch/catch.hpp"
#include "14.Longest_Common_Prefix/code.h"

using namespace std;
using namespace Longest_Common_Prefix;

TEST_CASE("Longest Common Prefix",
          "[Longest Common Prefix]")
{
    auto strs = vector<string>{"homomorphic", "homeomorphism"};
    Solution x;

    auto actual = x.longestCommonPrefix(strs);

    auto expected = "hom";
    REQUIRE(actual == expected);
}
