#include "../include/catch.hpp"
#include "../../src/138.Copy_List_with_Random_Pointer/code.h"

using namespace std;
using namespace Copy_List_with_Random_Pointer;

TEST_CASE("Copy List with Random Pointer", "[Copy List with Random Pointer]")
{
    auto head = new RandomListNode(1);
    Solution x;

    auto copy = x.copyRandomList(head);

    REQUIRE(copy != head);
    REQUIRE(copy->label == 1);
    REQUIRE(copy->next == nullptr);
    REQUIRE(copy->random == nullptr);
}
