#include <iostream>
#include "TreeNode_def.h"

/// leetcode 450 删除二叉搜索树中的节点
/// @brief 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
///        返回二叉搜索树（有可能被更新）的根节点的引用。

class Solution
{
private:
    TreeNode* traversal(TreeNode* node, int key)
    {
        if (node->val == key)
        {
            if (node->left == nullptr && node->right == nullptr) // 叶子节点，直接删除
            {
                delete node; node = nullptr;
                return nullptr;
            }
            else if (node->right == nullptr) // 右子树为空，直接让左子树接替位置
            {
                TreeNode* left = node->left;
                delete node; node = nullptr;
                return left;
            }
            else if (node->left == nullptr) // 左子树为空，直接让右子树接替位置
            {
                TreeNode* right = node->right;
                delete node; node = nullptr;
                return right;
            }
            else // 左右两边都不为空
            {
                // 统一让左子树接任位置，右子树嫁接到左子树的最右边节点右孩子的位置
                TreeNode* _cur = node->left;
                while (_cur->right)
                {
                    _cur = _cur->right;
                }
                _cur->right = node->right;

                TreeNode* tmp = node;
                node = node->left;
                delete tmp; tmp = nullptr;
                return node;

                /* 统一让右子树接任位置，左子树法哪嫁接到右子树的最左边节点左孩子的位置
                    TreeNode* _cur = node->right;
                    while (_cur->left)
                    {
                        _cur = _cur->left;
                    }
                    _cur->left = node->left;
                    
                    TreeNode* tmp = node;
                    node = node->right;
                    delete tmp; tmp = nullptr;
                    return node;
                */
            }
        }

        // 非空才进入，不会遇到空结点情况；将新的节点返回给上一层，上一层用 node->left 或 node->right 接住
        if (key < node->val && node->left)  node->left = traversal(node->left, key);
        if (key > node->val && node->right) node->right = traversal(node->right, key); 
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) return root;
        return traversal(root, key);
    }
};