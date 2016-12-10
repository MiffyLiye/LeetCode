#pragma once

namespace Merge_Two_Sorted_Lists
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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    };
}
