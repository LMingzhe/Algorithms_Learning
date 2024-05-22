#include <iostream>
#include <vector>
#include <unordered_map>
#include "TreeNode_def.h"

using std::vector;

/// leetcode 105 从前序与中序遍历序列构造二叉树
/// @brief 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
///         inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

// 递归 
class Solution  
{
private:
    std::unordered_map<int, int> index;
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
                            int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right) return nullptr;

        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中找到根节点
        int inorder_root = index[preorder[preorder_root]];

        // 构造根节点
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left; // 得到左子树中的节点数目
        // 递归构造左子树，并连接到根节点
        root->left = myBuildTree(preorder, inorder, preorder_root + 1, preorder_root + size_left_subtree,
                                    inorder_left, inorder_root - 1);
        // 递归构造右子树，并连接到根节点
        root->right = myBuildTree(preorder, inorder, preorder_root + size_left_subtree + 1, preorder_right, 
                                    inorder_root + 1, inorder_right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();
        // 对中序遍历构造哈希表，用于快速定位根节点
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};