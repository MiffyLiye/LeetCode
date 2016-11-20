#pragma once

namespace Linked_List_Cycle_II
{
    struct ListNode
    {
        int val;
        ListNode* next;

        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution
    {
    public:
        ListNode* detectCycle(ListNode* head);
    };
}
