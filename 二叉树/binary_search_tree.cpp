#include <iostream>
#include "TreeNode_def.h"

/// leetcode 700 二叉搜索树中的搜索 
/// @brief 给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
///        你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
/// 二叉搜索树：若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
///           若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
///           它的左、右子树也分别为二叉搜索树

class Solution
{
public:
    TreeNode* binarySearch(TreeNode* node, int val)
    {
        TreeNode* result = nullptr;
        if (node->val == val) result = node;
        if (val < node->val && node->left) result = binarySearch(node->left, val);
        if (val > node->val && node->right) result = binarySearch(node->right, val);
        return result;
    }

    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr) return nullptr;
        return binarySearch(root, val);
    }
};