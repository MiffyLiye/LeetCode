#include "code.h"

namespace Add_Two_Numbers
{
    ListNode* add_two_numbers(ListNode* a, ListNode* b)
    {
        auto current_a = a;
        auto current_b = b;
        ListNode* current = nullptr;
        auto carry = 0;

        while (current_a != nullptr && current_b != nullptr)
        {
            current_a->val += current_b->val + carry;
            if (current_a->val >= 10)
            {
                carry = 1;
                current_a->val -= 10;
            }
            else
            {
                carry = 0;
            }
            current = current_a;
            current_a = current_a->next;
            current_b = current_b->next;
        }

        while (current_a != nullptr || current_b != nullptr)
        {
            auto x = (current_a != nullptr) ? current_a : current_b;
            if (current != nullptr)
            {
                current->next = x;
                current_a = x;
                current_b = nullptr;
            }
            else
            {
                return x;
            }
            while (current_a != nullptr)
            {
                current_a->val += carry;
                if (current_a->val >= 10)
                {
                    carry = 1;
                    current_a->val -= 10;
                }
                else
                {
                    carry = 0;
                }
                current = current_a;
                current_a = current_a->next;
            }
        }


        if (carry == 0)
        {
            return a;
        }
        else
        {
            current->next = new ListNode(carry);
            return a;
        }
    }

    ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        return add_two_numbers(l1, l2);
    }
}
