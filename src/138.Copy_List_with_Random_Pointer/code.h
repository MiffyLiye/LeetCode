#pragma once

namespace Copy_List_with_Random_Pointer
{
    struct RandomListNode
    {
        int label;
        RandomListNode* next, * random;

        RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
    };

    class Solution
    {
    public:
        RandomListNode* copyRandomList(RandomListNode* head);
    };
}
