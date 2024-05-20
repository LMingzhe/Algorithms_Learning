#include <iostream>
#include <vector>
#include "TreeNode_def.h"

using std::vector;

/// leetcode 94 二叉树中序遍历
/// @brief 给定一个二叉树的根节点 root ，返回 它的 中序 遍历。

class Solution
{
private:
    vector<int> result;
    void traversal(TreeNode* root)
    {
        if (root == nullptr) return;
        traversal(root->left);       // 左
        result.push_back(root->val);  // 中
        traversal(root->right);      // 右
    }
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr) return {};
        traversal(root);
        return result;
    }
};