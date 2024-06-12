#include <iostream>
#include <TreeNode_def.h>
#include <unordered_map>

using namespace std;

/// leetcode 236 二叉树的最近公共祖先
/// @brief 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 递归，深度优先搜索 时间复杂度O(n) 空间复杂度O(n)
class Solution {
private:
    TreeNode* result;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);  // 左子树是否包含 p or q
        bool rson = dfs(root->right, p, q); // 右子树是否包含 p or q
        // 满足：1.左子数存在p or q，右子数存在另一个 或者满足：2.当前节点为p or q且以当前节点为根的左子树or右子树存在另一个
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)))
        {
            result = root;
        }
        return lson || rson || root->val == p->val || root->val == q->val;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        dfs(root, p, q);
        return result;
    }
};

// 存储父节点 利用节点的父节点信息从 p 结点开始不断往上跳，并记录已经访问过的节点，
// 再从 q 节点开始不断往上跳，如果碰到已经访问过的节点，那么这个节点就是我们要找的最近公共祖先。
// 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
private:
    unordered_map<int, TreeNode*> fatherMap;
    unordered_map<int, bool> viaMap;
    void dfs(TreeNode* root)
    {
        if (root->left != nullptr)
        {
            fatherMap[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr)
        {
            fatherMap[root->right->val] = root;
            dfs(root->right);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode*p, TreeNode* q)
    {
        // 记录每个节点的父节点
        fatherMap[root->val] = nullptr;
        dfs(root);

        // 从p开始往上遍历父节点，直至根节点
        while (p != nullptr)
        {
            viaMap[p->val] = true;
            p = fatherMap[p->val];
        }
        // 从p开始往上遍历父节点，第一个被访问过的节点即为p、q最近公共祖先
        while (q != nullptr)
        {
            if (viaMap[q->val]) return q;
            else q = fatherMap[q->val];
        }
        return nullptr;
    }
};