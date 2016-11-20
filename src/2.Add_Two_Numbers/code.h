#pragma once

namespace Add_Two_Numbers
{
    using namespace std;

    struct ListNode
    {
        int val;
        ListNode* next;

        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution
    {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    };
}
