#include "../include/catch.hpp"
#include "../../src/144.Binary_Tree_Preorder_Traversal/code.h"

using namespace std;
using namespace Binary_Tree_Preorder_Traversal;

TEST_CASE("Binary Tree Preorder Traversal", "[Binary Tree Preorder Traversal]")
{
    auto head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->right->left = new TreeNode(3);
    Solution x;

    auto actual = x.preorderTraversal(head);

    auto expected = vector<int>{1, 2, 3};
    REQUIRE(actual == expected);
}
