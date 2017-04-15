#include "catch/catch.hpp"
#include "145.Binary_Tree_Postorder_Traversal/code.h"

using namespace std;
using namespace Binary_Tree_Postorder_Traversal;

TEST_CASE("Binary Tree Postorder Traversal", "[Binary Tree Postorder Traversal]")
{
    auto head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->right->left = new TreeNode(3);
    Solution x;

    auto actual = x.postorderTraversal(head);

    auto expected = vector<int>{3, 2, 1};
    REQUIRE(actual == expected);
}
