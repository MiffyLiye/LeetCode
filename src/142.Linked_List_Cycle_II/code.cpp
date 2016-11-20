#include "code.h"
#include <unordered_set>

using namespace std;

namespace Linked_List_Cycle_II
{
    ListNode* detect_cycle(ListNode* head)
    {
        unordered_set<ListNode*> s;
        while (head != nullptr)
        {
            if (s.find(head) != s.end())
            {
                return head;
            }
            s.insert(head);
            head = head->next;
        }
        return nullptr;
    }

    ListNode* Solution::detectCycle(ListNode* head)
    {
        return detect_cycle(head);
    }
}