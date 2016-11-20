#include "../include/catch.hpp"
#include "../../src/155.Min_Stack/code.hpp"

using namespace std;
using namespace Min_Stack;

TEST_CASE("Min Stack","[Min Stack]")
{
    auto min_stack = MinStack();
    min_stack.push(-2);
    min_stack.push(0);
    min_stack.push(-3);

    REQUIRE(min_stack.getMin() == -3);

    min_stack.pop();

    REQUIRE(min_stack.top() == 0);

    REQUIRE(min_stack.getMin() == -2);
}
