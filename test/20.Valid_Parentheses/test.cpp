#include "catch/catch.hpp"
#include "20.Valid_Parentheses/code.h"

using namespace std;
using namespace Valid_Parentheses;

TEST_CASE("when matches","[Valid Parentheses]")
{
    auto s = string{"{[()]}"};
    Solution x;

    auto is_valid = x.isValid(s);

    REQUIRE(is_valid);
}

TEST_CASE("when not match","[Valid Parentheses]")
{
    auto s = string{"(]"};
    Solution x;

    auto is_valid = x.isValid(s);

    REQUIRE(!is_valid);
}

TEST_CASE("when more left parentheses","[Valid Parentheses]")
{
    auto s = string{"("};
    Solution x;

    auto is_valid = x.isValid(s);

    REQUIRE(!is_valid);
}

TEST_CASE("when less left parentheses","[Valid Parentheses]")
{
    auto s = string{"]"};
    Solution x;

    auto is_valid = x.isValid(s);

    REQUIRE(!is_valid);
}