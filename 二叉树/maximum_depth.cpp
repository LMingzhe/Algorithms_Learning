#include <iostream>
#include <queue>
#include "TreeNode_def.h"

using std::queue;

/// leetcode 104 二叉树的最大深度
/// @brief 给定一个二叉树，找出其最大深度。

// 前序遍历实现 
class Solution
{
private:
    int result;
    int depth;
public:
    void backtracking(TreeNode* node)
    {
        if (node == nullptr) return;
        depth++;
        if (depth > result) result = depth;
        backtracking(node->left);
        backtracking(node->right);
        depth--;
    }
    int maxDepth(TreeNode* root)
    {
        result = 0;
        depth = 0;
        backtracking(root);
        return result;
    }
};

// 层序遍历实现
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
            }
        }
        return depth;
    }
};