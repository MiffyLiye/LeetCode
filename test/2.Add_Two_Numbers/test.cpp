#include "../include/catch.hpp"
#include "../../src/2.Add_Two_Numbers/code.h"

using namespace std;
using namespace Add_Two_Numbers;

namespace Add_Two_Numbers{
    ListNode* get_list(vector<int> v)
    {
        if (v.size() == 0)
        {
            return nullptr;
        } else
        {
            ListNode* list = nullptr;
            ListNode* current = nullptr;
            for (size_t i = 0; i < v.size(); i++)
            {
                if (list == nullptr)
                {
                    list = new ListNode(v[i]);
                    current = list;
                } else
                {
                    current->next = new ListNode(v[i]);
                    current = current->next;
                }
                if (current == nullptr)
                {
                    throw runtime_error("error! get_list: no enough space");
                }
            }
            return list;
        }
    }

    bool list_equals(ListNode* left, ListNode* right)
    {
        while (left != nullptr){
            if (right == nullptr) return false;
            if (left->val != right->val) return false;

            left = left->next;
            right = right->next;
        }
        return right == nullptr;
    }
}

TEST_CASE("Add the two numbers and return it as a linked list.",
          "[Add Two Numbers]")
{
    auto a = get_list({2, 4, 3});
    auto b = get_list({5, 6, 4});
    Solution x;

    auto actual = x.addTwoNumbers(a, b);

    auto expected = get_list({7, 0, 8});
    REQUIRE(list_equals(actual, expected));
}