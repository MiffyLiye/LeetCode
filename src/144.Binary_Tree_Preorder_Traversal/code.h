#pragma once

#include <vector>

namespace Binary_Tree_Preorder_Traversal
{
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class Solution
    {
    public:
        std::vector<int> preorderTraversal(TreeNode* root);
    };
}
