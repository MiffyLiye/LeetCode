#include "catch/catch.hpp"
#include "141.Linked_List_Cycle/code.h"

using namespace std;
using namespace Linked_List_Cycle;

TEST_CASE("Has no cycle", "[Linked List Cycle]")
{
    auto head = new ListNode(1);
    auto node = new ListNode(2);
    head->next = node;
    Solution x;

    auto has_cycle = x.hasCycle(head);

    REQUIRE(!has_cycle);
}

TEST_CASE("Has cycle", "[Linked List Cycle]")
{
    auto head = new ListNode(1);
    auto node = new ListNode(2);
    head->next = node;
    node->next = head;
    Solution x;

    auto has_cycle = x.hasCycle(head);

    REQUIRE(has_cycle);
}
