#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// @brief 考察层序遍历构造二叉树，路径搜索部分可使用前序遍历

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// 层序遍历构造二叉树
TreeNode* constructBinaryTree(const vector<int>& levelOrder)
{
    if (levelOrder.empty()) return nullptr;
    
    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(levelOrder[0]);
    que.push(root);
    int i = 1;
    while (!que.empty() && i < levelOrder.size())
    {
        TreeNode* cur = que.front();
        que.pop();

        if (i < levelOrder.size() && levelOrder[i] != -1)
        {
            TreeNode* leftSon = new TreeNode(levelOrder[i]);
            cur->left = leftSon;
            que.push(leftSon);
        }
        ++i;

        if (i < levelOrder.size() && levelOrder[i] != -1)
        {
            TreeNode* rightSon = new TreeNode(levelOrder[i]);
            cur->right = rightSon;
            que.push(rightSon);
        }
        ++i;
    }
    return root;
}

// 前序遍历
void dfs(TreeNode* root, int cnt_0, int cnt_1, int& result)
{
    root->val == 1? ++cnt_1 : ++cnt_0;

    if (root->left == nullptr && root->right == nullptr)
    {
        if (cnt_1 - cnt_0 == 1)
        {
            ++result;
        }
        return;
    }

    // 递归访问左右节点
    if (root->left) dfs(root->left, cnt_0, cnt_1, result);
    if (root->right) dfs(root->right, cnt_0, cnt_1, result);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> levelOrder;
    while (n--)
    {
        int val;
        cin >> val;
        levelOrder.push_back(val);
    }

    int result = 0;
    TreeNode* root = constructBinaryTree(levelOrder);
    dfs(root, 0, 0, result);

    cout << result << endl;
    return 0;
}
