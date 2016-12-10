#pragma once

namespace Remove_Nth_Node_From_End_of_List
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
        ListNode* removeNthFromEnd(ListNode* head, int n);
    };
}
