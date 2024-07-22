#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//note 层序遍历构造二叉树 
TreeNode* constructBinaryTree(const vector<string>& levelOrder)
{
    if (levelOrder.empty()) return NULL;

    TreeNode* root = new TreeNode(stoi(levelOrder[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        TreeNode* cur = q.front();
        q.pop();

        if (i < levelOrder.size() && levelOrder[i] != "null")
        {
            cur->left = new TreeNode(stoi(levelOrder[i]));
            q.push(cur->left);
        }
        i++;

        if (i < levelOrder.size() && levelOrder[i] != "null")
        {
            cur->right = new TreeNode(stoi(levelOrder[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

int result = 0;

// 树形dp
int dfs(TreeNode* node)
{
    if (node == nullptr) return 0;
    int leftPath = dfs(node->left);
    int rightPath = dfs(node->right);
    
    int leftNum = 0, rightNum = 0;
    if (node->left != nullptr && node->left->val == node->val)
    {
        leftNum = leftPath + 1;
    }
    if (node->right != nullptr && node->right->val == node->val)
    {
        rightNum = rightPath + 1;
    }
    result = max(result, leftNum + rightNum); // fixme 为什么是加？可以横跨左右子树？
    return max(leftNum, rightNum);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> levelOrder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> levelOrder[i];
    }
    TreeNode* root = constructBinaryTree(levelOrder);
    dfs(root);
    cout << result << endl;
    return 0;
}
