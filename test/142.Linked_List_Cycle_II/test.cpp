#include "../include/catch.hpp"
#include "../../src/142.Linked_List_Cycle_II/code.h"

using namespace std;
using namespace Linked_List_Cycle_II;

TEST_CASE("No cycle", "[Linked List Cycle II]")
{
    auto head = new ListNode(1);
    auto node = new ListNode(2);
    head->next = node;
    Solution x;

    auto cycle_head = x.detectCycle(head);

    REQUIRE(cycle_head == nullptr);
}

TEST_CASE("Cycle", "[Linked List Cycle II]")
{
    auto head = new ListNode(1);
    auto node = new ListNode(2);
    head->next = node;
    node->next = head;
    Solution x;

    auto cycle_head = x.detectCycle(head);

    REQUIRE(cycle_head == head);
}
