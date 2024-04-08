#include <iostream>
#include <stack>
#include <queue>
#include "TreeNode_def.h"

using namespace std;

/// leetcode 101
/// @brief 对称二叉树 给定一个二叉树，检查它是否是镜像对称的。

// 递归法
class Solution
{
public:
    // 确定递归函数参数和返回值
    bool compare(TreeNode* left, TreeNode* right)
    {   
        // 确定终止条件
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        // 确定单层递归逻辑
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        
        return isSame;
    }

    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

// 迭代法（队列实现）
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        std::queue<TreeNode*> que;
        que.push(root->left);  // 将左子树头结点加入队列
        que.push(root->right); // 将右子树头结点加入队列
        
        while (!que.empty())
        {
            // 两两比较
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            // 左节点为空、右节点为空，此时说明是对称的
            if (!leftNode && !rightNode) continue;
            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) 
            {
                return false;
            }
            que.push(leftNode->left);   // 加入左节点左孩子
            que.push(rightNode->right); // 加入右节点右孩子
            que.push(leftNode->right);  // 加入左节点右孩子
            que.push(rightNode->left);  // 加入右节点左孩子
        }

        return true;
    }
};

// 迭代法（栈实现）
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;
        std::stack<TreeNode*> st;  // 将队列换成栈，其他不变
        st.push(root->left);
        st.push(root->right);
        while (!st.empty())
        {
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* rightNode = st.top(); st.pop();

            if (!leftNode && !rightNode) continue;
            if (!leftNode || !rightNode || leftNode->val != rightNode->val)
            {
                return false;
            }

            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};