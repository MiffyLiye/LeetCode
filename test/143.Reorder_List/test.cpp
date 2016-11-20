#include "../include/catch.hpp"
#include "../../src/143.Reorder_List/code.h"

using namespace std;
using namespace Reorder_List;

TEST_CASE("Reorder List", "[Reorder List]")
{
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution x;

    x.reorderList(head);

    REQUIRE(head->val == 1);
    REQUIRE(head->next->val == 4);
    REQUIRE(head->next->next->val == 2);
    REQUIRE(head->next->next->next->val == 3);
}
