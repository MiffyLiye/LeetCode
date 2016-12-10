#include "code.h"

namespace Remove_Nth_Node_From_End_of_List
{
    // 6 ms
    ListNode* one_pass_remove_nth_from_end(ListNode* head, int n)
    {
        auto leader = head;
        auto after_n_follower = head;
        auto after_n_plus_1_follower = head;

        for (auto i = 0; i < n; i++)
        {
            leader = leader->next;
        }

        if (leader != nullptr)
        {
            leader = leader->next;
            after_n_follower = after_n_follower->next;
        }

        while (leader != nullptr)
        {
            leader = leader->next;
            after_n_follower = after_n_follower->next;
            after_n_plus_1_follower = after_n_plus_1_follower->next;
        }

        if (after_n_follower != head)
        {
            after_n_plus_1_follower->next = after_n_follower->next;
            return head;
        }

        return head->next;
    }

    // 9 ms
    ListNode* two_pass_remove_nth_from_end(ListNode* head, int n)
    {
        auto count_of_nodes = 0;
        auto counter = head;
        while (counter != nullptr)
        {
            count_of_nodes++;
            counter = counter->next;
        }

        if (n == count_of_nodes)
        {
            return head->next;
        }

        auto searcher = head;
        for (auto i = 0; i < count_of_nodes - n - 1; i++){
            searcher = searcher->next;
        }
        searcher->next = searcher->next->next;
        return head;
    }

    ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
    {
        return one_pass_remove_nth_from_end(head, n);
    }
}