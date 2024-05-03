#include <iostream>
#include <algorithm>
#include "TreeNode_def.h"

/// leetcode 110 平衡二叉树
/// @brief 给定一个二叉树，判断它是否是高度平衡的二叉树。
/// 求深度用前序（中左右） 求高度用后序（左右中）

class Solution
{
public:
    // 返回以该节点为根节点的二叉树的高度，如果不是平衡二叉树了则返回-1
    int getHeight(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;
        return std::abs(leftHeight - rightHeight) > 1 ? -1 : 1 + std::max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root)
    {
        return getHeight(root) == -1 ? false : true;
    }
};