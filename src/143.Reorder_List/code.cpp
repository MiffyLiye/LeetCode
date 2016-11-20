#include "code.h"

namespace Reorder_List
{
    ListNode* reverse_list(ListNode* head)
    {
        if (head == nullptr)
        {
            return head;
        }
        auto current = head;
        auto current_next = head->next;
        head->next = nullptr;

        while (current_next != nullptr)
        {
            auto link = current_next->next;
            current_next->next = current;
            current = current_next;
            current_next = link;
        }
        return current;
    }

    void merge(ListNode* head, ListNode* a)
    {
        auto current = head;
        while (current != nullptr && a != nullptr)
        {
            auto t_current = current->next;
            current->next = a;
            a = a->next;
            current->next->next = t_current;
            current = t_current;
        }
    }

    void reorder_list(ListNode* head)
    {
        auto current = head;
        auto tail = head;
        if (head != nullptr)
        {
            tail = head->next;
        }
        else
        {
            return;
        }
        while (tail != nullptr && tail->next != nullptr)
        {
            current = current->next;
            tail = tail->next->next;

        }
        auto half_head = current->next;
        current->next = nullptr;
        half_head = reverse_list(half_head);
        merge(head, half_head);
    }

    void Solution::reorderList(ListNode* head)
    {
        reorder_list(head);
    }
}
