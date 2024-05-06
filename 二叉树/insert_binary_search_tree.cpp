#include <iostream>
#include "TreeNode_def.h"

/// leetcode 701 二叉搜索树中的插入操作
/// @brief 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 
///        返回插入后二叉搜索树的根节点。 输入数据保证，新值和原始二叉搜索树中的任意节点值都不同。

class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr) return new TreeNode(val);
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        if (val > root->val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};