#include <iostream>
#include "TreeNode_def.h"

/// leetcode 538 二叉搜索树转换为累加树
/// @brief 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
///        使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。


// 反中序遍历 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    int sum = 0;

    TreeNode* convertBST(TreeNode* root)
    {
        if (root != nullptr)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

// Morris遍历 时间复杂度O(n) 空间复杂度O(1)
// 从上往下利用空闲指针左指针构建新数，再从下往上计算值，并恢复原本的数结构
class Solution {
public:
    TreeNode* getSuccessor(TreeNode* node)
    {
        TreeNode* succ = node->right;
        while (succ->left != nullptr && succ->left != node)
        {
            succ = succ->left;
        }
        return succ;
    }

    TreeNode* convertBST(TreeNode* root) 
    {
        int sum = 0;
        TreeNode* node = root;

        while (node != nullptr)
        {
            if (node->right == nullptr)
            {
                sum += node->val;
                node->val = sum;
                node = node->left;
            } else {
                TreeNode* succ = getSuccessor(node);
                if (succ->left == nullptr) // 空闲左指针，指向当前node（从上往下）
                {
                    succ->left = node;
                    node = node->right;
                } else { // 左指针指向了node，恢复树形状，进行计算操作
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }
        return root;
    }
};