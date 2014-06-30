#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        return pre_order_traversal_non_recursive(root);
    }
private:
    void pre_order_traversal_recursive(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        else {
            v.push_back(root->val);
            pre_order_traversal_recursive(root->left, v);
            pre_order_traversal_recursive(root->right, v);
            return;
        }
    }
    vector<int> pre_order_traversal(TreeNode* root) {
        vector<int> v;
        pre_order_traversal_recursive(root, v);
        return v;
    }

    vector<int> pre_order_traversal_non_recursive(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v {};
        if (root != nullptr) {
            s.push(root);
        }
        else {
            return v;
        }

        while (s.size() != 0) {
            auto n = s.top();
            s.pop();
            v.push_back(n->val);
            if (n->right != nullptr) {
                s.push(n->right);
            }
            if (n->left != nullptr) {
                s.push(n->left);
            }
        }

        return v;
    }
};

int main()
{
    TreeNode node_1(1);
    TreeNode node_2(2);

    TreeNode* root = &node_1;
    node_1.right = &node_2;

    Solution x;
    auto t = x.preorderTraversal(root);

    for (auto x:t) {
        cout << x << endl;
    }

    return 0;
}