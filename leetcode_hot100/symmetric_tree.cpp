#include <iostream>
#include <stack>
#include <queue>
#include "TreeNode_def.h"

using std::stack;
using std::queue;

/// leetcode 101 对称二叉树
/// @brief 给你一个二叉树的根节点 root ， 检查它是否轴对称。

// 递归法
class Solution
{
public:
    bool compare(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        bool ouside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = ouside && inside;

        return isSame;
    }
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

// 迭代法 用队列实现
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {
            // 两两比较
            TreeNode* leftNode = que.front();
            TreeNode* rightNode = que.front();
            que.pop(); que.pop();
            // 左节点为空、右节点为空，此时说明是对称的
            if (leftNode == nullptr && rightNode == nullptr) continue;
            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) return false;
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }

        return true;
    }
};

// 迭代法 用栈实现
class Solution  
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);

        while (!st.empty())
        {
            // 两两比较
            TreeNode* leftNode = st.top();
            TreeNode* rightNode = st.top();
            st.pop(); st.pop();
            // 左节点为空、右节点为空，此时说明是对称的
            if (leftNode == nullptr && rightNode == nullptr) continue;
            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) return false;
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }

        return true;
    }
};