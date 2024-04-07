#include <iostream>
#include <stack>
#include <queue>
#include "TreeNode_def.h"

using namespace std;

/// leetcode 226 
/// @brief 翻转二叉树
/// 针对二叉树的问题，解题之前一定要想清楚究竟是前中后序遍历，还是层序遍历。

// 递归法
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {   
        if (root == nullptr) return root;
        swap(root->left, root->right);  // 交换左右子树
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// 层序遍历 (广度优先)
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        std::queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);   // 交换左右子树
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};

// 迭代法（深度优先）前序遍历实现
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        std::stack<TreeNode*> st;
        if (root == nullptr) return root;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return root;
    }
};