#include "../include/catch.hpp"
#include "../../src/150.Evaluate_Reverse_Polish_Notation/code.h"

using namespace std;
using namespace Evaluate_Reverse_Polish_Notation;

TEST_CASE("Evaluate Reverse Polish Notation", "[Evaluate Reverse Polish Notation]")
{
    auto tokens = vector<string>{"2", "1", "+", "3", "*"};
    Solution x;

    auto actual = x.evalRPN(tokens);

    REQUIRE(actual == 9);
}

TEST_CASE("Evaluate Reverse Polish Notation 2", "[Evaluate Reverse Polish Notation]")
{
    auto tokens = vector<string>{"4", "13", "5", "/", "+"};
    Solution x;

    auto actual = x.evalRPN(tokens);

    REQUIRE(actual == 6);
}