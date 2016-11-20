#pragma once

namespace Linked_List_Cycle
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
        bool hasCycle(ListNode* head);
    };
}
