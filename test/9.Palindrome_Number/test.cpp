#include "catch/catch.hpp"
#include "9.Palindrome_Number/code.h"

using namespace std;
using namespace Palindrome_Number;

TEST_CASE("Determine whether an integer is a palindrome",
          "[Palindrome Number]")
{
    auto a = 123321;
    Solution x;

    auto actual = x.isPalindrome(a);

    auto expected = true;
    REQUIRE(actual == expected);
}

TEST_CASE("12321 -> true",
          "[Palindrome Number]")
{
    auto a = 12321;
    Solution x;

    auto actual = x.isPalindrome(a);

    auto expected = true;
    REQUIRE(actual == expected);
}

TEST_CASE("123 -> false",
          "[Palindrome Number]")
{
    auto a = 123;
    Solution x;

    auto actual = x.isPalindrome(a);

    auto expected = false;
    REQUIRE(actual == expected);
}

TEST_CASE("-2147447412 -> false",
          "[Palindrome Number]")
{
    auto a = -2147447412;
    Solution x;

    auto actual = x.isPalindrome(a);

    auto expected = false;
    REQUIRE(actual == expected);
}
