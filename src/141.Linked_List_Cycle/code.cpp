#include "code.h"
#include <set>

using namespace std;

namespace Linked_List_Cycle
{
    bool has_cycle(ListNode* head)
    {
        set<ListNode*> s;
        while (head != nullptr)
        {
            if (s.find(head) != s.end())
            {
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
    }

    bool has_cycle_s(ListNode* head)
    {
        if (head == nullptr)
        {
            return false;
        }
        auto slower = head;
        auto faster = head->next;
        while (faster != nullptr)
        {
            if (slower == faster)
            {
                return true;
            }
            slower = slower->next;
            faster = (faster->next == nullptr) ? nullptr : faster->next->next;
        }
        return false;
    }

    bool Solution::hasCycle(ListNode* head)
    {
        return has_cycle_s(head);
    }
}