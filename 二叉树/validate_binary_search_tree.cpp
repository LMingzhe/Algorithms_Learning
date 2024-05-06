#include <iostream>
#include <vector>
#include "TreeNode_def.h"   

using std::vector;

/// leetcode 98 验证二叉搜索树
/// @brief 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

class Solution
{
private:
    vector<int> result;

public:
    void traversal(TreeNode* node)
    {
        if (node == nullptr) return;
        traversal(node->left);
        result.push_back(node->val);
        traversal(node->right);
    }
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) return true;
        traversal(root); // 中序遍历 左-中-右，如果数组有序则为二叉搜索树
        for (int i = 1; i < result.size(); i++)
        {
            if (result[i] <= result[i - 1]) return false;
        }
        return true;
    }
};

// 不用辅助数组，直接在遍历中比较
class Solution_v2
{
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) return true;

        bool left = isValidBST(root->left); // 左

        if (pre != nullptr && pre->val >= root->val) return false; // 中
        pre = root; // 记录前一个节点

        bool right = isValidBST(root->right); // 右

        return left && right;
    }
};