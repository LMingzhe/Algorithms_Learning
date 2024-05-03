#include <iostream>
#include <queue>
#include <algorithm>
#include "TreeNode_def.h"

using std::queue;
using std::min;
using std::max;

/// leetcode 104 二叉树的最大深度
/// @brief 给定一个二叉树，找出其最大深度。
/// 二叉树节点的深度（前序）：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
/// 二叉树节点的高度（后序）：指从该节点到叶子节点的最长简单路径边的条数或者节点数（取决于高度从0开始还是从1开始）

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

// 后续遍历实现
class Solution
{
public:
    int getDepth(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int leftDepth = getDepth(node->left);           // 左
        int rightDepth = getDepth(node->right);         // 右
        int depth = 1 + max(leftDepth, rightDepth); // 中
        return depth;
    }

    int maxDepth(TreeNode* root)
    {
        return getDepth(root);
    }
};