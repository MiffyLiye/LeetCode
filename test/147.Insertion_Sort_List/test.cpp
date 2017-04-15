#include "catch/catch.hpp"
#include "147.Insertion_Sort_List/code.h"

using namespace std;
using namespace Insertion_Sort_List;

namespace Insertion_Sort_List
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
                if (current == nullptr)
                {
                    throw;
                }
            }
            return list;
        }
    }

    bool equals(ListNode* left, ListNode* right)
    {
        while(left != nullptr && right != nullptr)
        {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return left == nullptr && right == nullptr;
    }
}

TEST_CASE("Insertion Sort List", "[Insertion Sort List]")
{
    auto list = get_list({1, 3, 5, 2, 4, 6});
    Solution x;

    list = x.insertionSortList(list);

    auto expected = get_list({1, 2, 3, 4, 5, 6});
    REQUIRE(equals(expected, list));
}