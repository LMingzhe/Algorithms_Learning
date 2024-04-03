#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode_def.h"

using namespace std;

/// @brief 二叉树的层序遍历

// 广度优先方法，使用队列实现
class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> result;
        if (root == nullptr) return result;
        que.push(root);
        while (!que.empty())
        {   
            int size = que.size(); // 记录二叉树的某一层有多少个结点，从队列中弹出多少个值
            std::vector<int> level_result;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                level_result.push_back(node->val);
                if (node->left)  que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(level_result);
        }
        return result;
    }
};

// 递归方法实现
class Solution
{
public:
    void order(TreeNode* cur, std::vector<std::vector<int>>& result, int depth)
    {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(std::vector<int>()); // 只有访问到每层第一个元素时才会发生
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};