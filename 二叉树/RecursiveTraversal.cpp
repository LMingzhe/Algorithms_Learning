#include <iostream>
#include <vector>
#include "TreeNode_def.h"

using namespace std;

/// @brief 二叉树递归实现三种遍历方式
/// 递归三要素：
///         1.确定递归函数的参数和返回值
///         2.确定终止条件
///         3.确定单层递归的逻辑

// 二叉树前序遍历 中-左-右
class Solution
{
public:
    void traversal(TreeNode* cur, std::vector<int>& vec)
    {
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }

    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 中序遍历 左-中-右
class Solution
{
public:
    void traversal(TreeNode* cur, std::vector<int>& vec)
    {
        if (cur == nullptr) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }

    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 二叉树前序遍历 中-左-右
class Solution
{
public:
    void traversal(TreeNode* cur, std::vector<int>& vec)
    {
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }

    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 后序遍历 左-右-中
class Solution
{
public:
    void traversal(TreeNode* cur, std::vector<int>& vec)
    {
        if (cur == nullptr) return;
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }

    std::vector<int> posorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        traversal(root, result);
        return result;
    }
};

