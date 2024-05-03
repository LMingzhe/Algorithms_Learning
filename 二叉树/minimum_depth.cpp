#include <iostream>
#include <limits>
#include <queue>
#include <algorithm>
#include "TreeNode_def.h"

using std::queue;
using std::min;
using std::max;

/// leetcode 111 二叉树最小深度
/// @brief 给定一个二叉树，找出其最小深度。

// 递归前序遍历实现 
class Solution
{
private:
    int depth;
    int result;

public:
    void backtracking(TreeNode* node)
    {
        if (node == nullptr) return;
        depth++;
        if (!node->left && !node->right)
        {
            result = depth < result ? depth : result;
            depth--;
            return;
        }
        else
        {
            backtracking(node->left);
            backtracking(node->right);
            depth--;
        }
    }

    int minDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        depth = 0;
        result = std::numeric_limits<int>::max();
        backtracking(root);
        return result;
    }
};

// 迭代层序遍历实现
class Solution_v2
{
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                // 当左右孩子都为空的时候，说明是最低点的一层了，退出
                if (!node->left && !node->right)
                {
                    return depth;
                }
            }
        }
        return depth;
    }
};

// 递归-后续遍历实现
class Solution_v3
{
public:
    int getDepth(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int leftDepth = getDepth(node->left);   // 左
        int rightDepth = getDepth(node->right); // 右
        // 中
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == nullptr && node->right != nullptr)
        {
            return 1 + rightDepth;
        }
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != nullptr && node->right == nullptr)
        {
            return 1 + leftDepth;
        }
        int depth = 1 + min(leftDepth, rightDepth);
        return depth;
    }

    int minDepth(TreeNode* root)
    {
        return getDepth(root);
    }
};