#include "code.h"
#include <vector>

using namespace std;

namespace Insertion_Sort_List
{
    ListNode* list_insert(ListNode*& head, ListNode* link)
    {
        if (head == nullptr)
        {
            link->next = nullptr;
            return link;
        }
        if (head->val > link->val)
        {
            link->next = head;
            return link;
        }
        auto current = head;
        for (; current->next != nullptr; current = current->next)
        {
            if (current->next->val > link->val)
            {
                link->next = current->next;
                current->next = link;
                return head;
            }
        }
        current->next = link;
        link->next = nullptr;
        return head;
    }

    ListNode* insertion_sort_list(ListNode* head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* current = head->next;
        head->next = nullptr;

        while (current != nullptr)
        {
            auto t = current;
            current = current->next;
            head = list_insert(head, t);
        }
        return head;
    }

    ListNode* Solution::insertionSortList(ListNode* head)
    {
        return insertion_sort_list(head);
    }
}
