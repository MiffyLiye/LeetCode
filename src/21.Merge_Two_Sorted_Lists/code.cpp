#include "code.h"
#include <tuple>

using namespace std;

namespace Merge_Two_Sorted_Lists
{
    tuple<ListNode*, ListNode*> get_smaller_and_nullable_larger_lists(ListNode* left, ListNode* right)
    {
        if (left == nullptr)
        {
            return make_tuple(right, left);
        }
        if (right == nullptr)
        {
            return make_tuple(left, right);
        }
        return left->val < right->val ? make_tuple(left, right) : make_tuple(right, left);
    }

    ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        ListNode* smaller;
        ListNode* larger;
        tie(smaller, larger) = get_smaller_and_nullable_larger_lists(l1, l2);

        auto head = smaller;
        auto tail = head;
        smaller = smaller->next;

        while (smaller != nullptr && larger != nullptr)
        {
            tie(smaller, larger) = get_smaller_and_nullable_larger_lists(smaller, larger);
            tail->next = smaller;
            tail = tail->next;
            smaller = smaller->next;
        }

        auto remaining = smaller != nullptr ? smaller : larger;
        while (remaining != nullptr)
        {
            tail->next = remaining;
            tail = tail->next;
            remaining = remaining->next;
        }

        return head;
    }
}
