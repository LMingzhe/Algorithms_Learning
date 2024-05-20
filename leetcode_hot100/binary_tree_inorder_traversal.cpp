#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode_def.h"

using std::vector;
using std::stack;

/// leetcode 94 二叉树中序遍历
/// @brief 给定一个二叉树的根节点 root ，返回 它的 中序 遍历。

// 递归
class Solution
{
private:
    vector<int> result;
    void traversal(TreeNode* root)
    {
        if (root == nullptr) return;
        traversal(root->left);       // 左
        result.push_back(root->val);  // 中
        traversal(root->right);      // 右
    }
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr) return {};
        traversal(root);
        return result;
    }
};

// 迭代
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == nullptr) return result;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;  // 左
            } 
            else 
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val); // 中
                cur = cur->right; // 右
            }
        }
        return result;
    }
};