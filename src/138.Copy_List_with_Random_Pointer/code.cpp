#include "code.h"
#include <stack>
#include <unordered_map>

using namespace std;

namespace Copy_List_with_Random_Pointer
{
    RandomListNode* copy_random_list(RandomListNode* head)
    {
        if (head == nullptr)
        {
            return head;
        }
        stack < RandomListNode * > to_do {};
        unordered_map < RandomListNode * , RandomListNode * > m {};

        to_do.push(head);
        auto new_node = new RandomListNode(head->label);

        m.insert({head, new_node});

        while (to_do.size() > 0)
        {
            auto x = to_do.top();
            to_do.pop();
            new_node = new RandomListNode(x->label);

            m.insert({x, new_node});
            if (x->next != nullptr && m.find(x->next) == m.end())
            {
                to_do.push(x->next);
            }
            if (x->random != nullptr && m.find(x->random) == m.end())
            {
                to_do.push(x->random);
            }
        }

        for (auto i = m.begin(); i != m.end(); i++)
        {
            i->second->next = (i->first->next == nullptr) ? nullptr : m[i->first->next];
            i->second->random = (i->first->random == nullptr) ? nullptr : m[i->first->random];
        }
        return m[head];
    }

    RandomListNode* Solution::copyRandomList(RandomListNode* head)
    {
        return copy_random_list(head);
    }
}