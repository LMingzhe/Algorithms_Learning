#include <iostream>
#include <vector>
#include <string>
#include "TreeNode_def.h"

using std::vector;
using std::string;

class Solution
{
private:
    vector<int> path;
    vector<string> result;

    void backtracking(TreeNode* cur)
    {
        path.push_back(cur->val); // 中
        // 递归终止条件，找到叶子节点
        if (!cur->left && !cur->right)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += std::to_string(path[i]);
                sPath += "->";
            }
            sPath += std::to_string(path[path.size() - 1]); // 记录最后一个节点
            result.push_back(sPath);
            return;
        }
        if (cur->left)  // 左
        {
            backtracking(cur->left);
            path.pop_back();
        }
        if (cur->right)  // 右
        {
            backtracking(cur->right);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if (root == nullptr) return result;
        backtracking(root);
        return result;
    }
};