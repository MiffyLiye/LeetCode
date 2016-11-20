#include "code.h"
#include <stack>

using namespace std;

namespace Binary_Tree_Preorder_Traversal
{
    void pre_order_traversal_recursive(TreeNode* root, vector<int>& v)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            v.push_back(root->val);
            pre_order_traversal_recursive(root->left, v);
            pre_order_traversal_recursive(root->right, v);
            return;
        }
    }

    vector<int> pre_order_traversal(TreeNode* root)
    {
        vector<int> v;
        pre_order_traversal_recursive(root, v);
        return v;
    }

    vector<int> pre_order_traversal_non_recursive(TreeNode* root)
    {
        stack<TreeNode*> s;
        vector<int> v{};
        if (root != nullptr)
        {
            s.push(root);
        }
        else
        {
            return v;
        }

        while (s.size() != 0)
        {
            auto n = s.top();
            s.pop();
            v.push_back(n->val);
            if (n->right != nullptr)
            {
                s.push(n->right);
            }
            if (n->left != nullptr)
            {
                s.push(n->left);
            }
        }

        return v;
    }

    vector<int> Solution::preorderTraversal(TreeNode* root)
    {
        return pre_order_traversal_non_recursive(root);
    }
}