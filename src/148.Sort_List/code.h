#pragma once

namespace Sort_List
{
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution
    {
    public:
        ListNode *sortList(ListNode *head);
    };
}
