#pragma once

namespace Insertion_Sort_List
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution
    {
    public:
        ListNode* insertionSortList(ListNode* head);
    };
}
