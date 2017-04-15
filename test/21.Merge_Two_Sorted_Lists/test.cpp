#include "catch/catch.hpp"
#include "21.Merge_Two_Sorted_Lists/code.h"

using namespace std;
using namespace Merge_Two_Sorted_Lists;

namespace Merge_Two_Sorted_Lists
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

TEST_CASE("Merge Two Sorted Lists", "[Merge Two Sorted Lists]")
{
    auto left = get_list({1, 3, 5});
    auto right = get_list({1, 2, 4});

    Solution x;

    auto actual = x.mergeTwoLists(left, right);

    auto expected = get_list({1, 1, 2, 3, 4, 5});
    REQUIRE(equals(expected, actual));
}

TEST_CASE("one empty list", "[Merge Two Sorted Lists]")
{
    auto left = get_list({1});
    auto right = get_list({});

    Solution x;

    auto actual = x.mergeTwoLists(left, right);

    auto expected = get_list({1});
    REQUIRE(equals(expected, actual));
}

TEST_CASE("two empty list", "[Merge Two Sorted Lists]")
{
    auto left = get_list({});
    auto right = get_list({});

    Solution x;

    auto actual = x.mergeTwoLists(left, right);

    auto expected = get_list({});
    REQUIRE(equals(expected, actual));
}
