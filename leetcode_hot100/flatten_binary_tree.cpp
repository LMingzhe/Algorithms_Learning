#include <iostream>
#include <vector>
#include "TreeNode_def.h"

using std::vector;

/// leetcode 114 二叉树展开为链表
/// @brief 给你二叉树的根结点 root ，请你将它展开为一个单链表：
///        展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
///        展开后的单链表应该与二叉树 先序遍历 顺序相同。

// 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    void traversal(TreeNode* root, vector<TreeNode*>& vec)
    {
        if (root == nullptr) return;
        vec.push_back(root);
        traversal(root->left, vec);
        traversal(root->right, vec);
    }
    void flatten(TreeNode* root)
    {   
        if (root == nullptr) return;
        vector<TreeNode*> vec;
        traversal(root, vec);
        for (int i = 0; i < vec.size() - 1; i++)
        {
            vec[i]->left = nullptr;
            vec[i]->right = vec[i + 1];
        }
        vec[vec.size() - 1]->left = nullptr;
        vec[vec.size() - 1]->right = nullptr;
    }
};

// 进阶：时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    void flatten(TreeNode* root)
    {   
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr) // 左子树为空，跳过不同处理
            {
                cur = cur->right;
                continue;
            }
            TreeNode* pre = cur->left;
            while (pre->right != nullptr) // 找到当前节点左子树中的最右节点(前驱节点)
            {
                pre = pre->right;
            }
            pre->right = cur->right; // 当前节点的右子树接到前驱节点的右子树上
            cur->right = cur->left;  // 当前节点的左子树接到当前节点的右子树上
            cur->left = nullptr;     // 左子树置空
            cur = cur->right;        // 移动到下一个待处理节点
        }
    }
};