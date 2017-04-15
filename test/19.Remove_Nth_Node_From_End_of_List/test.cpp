#include "catch/catch.hpp"
#include "19.Remove_Nth_Node_From_End_of_List/code.h"
#include <vector>

using namespace std;
using namespace Remove_Nth_Node_From_End_of_List;

namespace Remove_Nth_Node_From_End_of_List
{
    ListNode* get_list(vector<int> v)
    {
        if (v.size() == 0)
        {
            return nullptr;
        }
        else
        {
            ListNode* list = nullptr;
            ListNode* current = nullptr;
            for (size_t i = 0; i < v.size(); i++)
            {
                if (list == nullptr)
                {
                    list = new ListNode(v[i]);
                    current = list;
                }
                else
                {
                    current->next = new ListNode(v[i]);
                    current = current->next;
                }
            }
            return list;
        }
    }

    bool equals(ListNode* left, ListNode* right)
    {
        while (left != nullptr && right != nullptr)
        {
            if (left->val != right->val)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return left == nullptr && right == nullptr;
    }
}

TEST_CASE("When remove the middle node", "[Remove Nth Node From End of List]")
{
    auto head = get_list({1, 2, 3, 4, 5});
    Solution x;

    auto actual = x.removeNthFromEnd(head, 2);

    auto expected = get_list({1, 2, 3, 5});
    REQUIRE(equals(expected, actual));
}

TEST_CASE("When remove the first node", "[Remove Nth Node From End of List]")
{
    auto head = get_list({1, 2});
    Solution x;

    auto actual = x.removeNthFromEnd(head, 2);

    auto expected = get_list({2});
    REQUIRE(equals(expected, actual));
}

TEST_CASE("When remove the last node", "[Remove Nth Node From End of List]")
{
    auto head = get_list({1, 2});
    Solution x;

    auto actual = x.removeNthFromEnd(head, 1);

    auto expected = get_list({1});
    REQUIRE(equals(expected, actual));
}
