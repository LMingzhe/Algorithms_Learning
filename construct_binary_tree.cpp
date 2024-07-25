#include <iostream>
#include <queue>

using namespace std;

/// @brief 层序遍历构造二叉树

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructBinaryTree(const vector<string>& levelOrder)
{
    if (levelOrder.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(levelOrder[0]));
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while (!que.empty() && i < levelOrder.size())
    {
        TreeNode* cur = que.front();
        que.pop();

        if (i < levelOrder.size() && levelOrder[i] != "null")
        {
            TreeNode* left = new TreeNode(stoi(levelOrder[i]));
            cur->left = left;
        }
        ++i;

        if (i < levelOrder.size() && levelOrder[i] != "null")
        {
            TreeNode* right = new TreeNode(stoi(levelOrder[i]));
            cur->right = right;
        }
        ++i;
    }
    return root;
}