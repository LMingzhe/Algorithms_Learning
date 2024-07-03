#include <iostream>
#include <TreeNode_def.h>

using namespace std;

/// leetcode 437 路径总和3
/// @brief 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
///        路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

// 前序遍历 + 回朔 时间复杂度O(n^2) 空间复杂度O(n)
class Solution  
{
public:
    int pathNum = 0;
    long long weightSum = 0;
    // 回朔穷举
    void backtracking(TreeNode* root, int& targetSum)
    {
        weightSum += root->val;
        if (weightSum == targetSum)
        {
            pathNum++;
            // weightSum -= root->val;  // 这里符合条件时不能返回，因为后续还有可能有类似 -1->1 这种能抵消的路径
            // return;
        }
        if (root->left) backtracking(root->left, targetSum);
        if (root->right) backtracking(root->right, targetSum);
        weightSum -= root->val;
    }

    // 前序遍历
    void preorder(TreeNode* root, int& targetSum)
    {
        weightSum = 0;
        // 对每个节点做回朔穷举
        backtracking(root, targetSum);
        if (root->left) preorder(root->left, targetSum);
        if (root->right) preorder(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr) return 0;
        preorder(root, targetSum);
        return pathNum;
    }
};