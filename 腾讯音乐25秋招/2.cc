#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return TreeNode类
     */
    queue<TreeNode*> que;
    void getTreeDeep(TreeNode* root, int& deep, int curDeep)
    {
        deep = max(deep, curDeep);
        if (root->left) getTreeDeep(root->left, deep, curDeep + 1);
        if (root->right) getTreeDeep(root->right, deep, curDeep + 1);
    }

    TreeNode* makeCompleteTree(TreeNode* root) 
    {
        // write code here
        int treeDeep = 0;
        getTreeDeep(root, treeDeep, 1);
        if (treeDeep == 1) return root;

        int curDeep = 1;
        if (root->left)
        {
            que.push(root->left);
        } else {
            root->left = new TreeNode(-1);
            que.push(root->left);
        }
        if (root->right)
        {
            que.push(root->right);
        } else {
            root->right = new TreeNode(-1);
            que.push(root->right);
        }

        int flag = 0;
        while (!que.empty())
        {
            curDeep++;
            int size = que.size();
            if (curDeep == treeDeep)
            {
                size = flag * 2;
            } 
            while (size--)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (curDeep == treeDeep)
                {
                    if (cur->val == -1)
                    {
                        cur->val = 1;
                    }
                } else if (curDeep == treeDeep - 1) {
                    static int index = 1;
                    if (cur->val == 1)
                    {
                        if (cur->left || cur->right) flag = index;
                        if (cur->left)
                        {
                            que.push(cur->left);
                        } else {
                            cur->left = new TreeNode(-1);
                            que.push(cur->right);
                        }
                        if (cur->right)
                        {
                            que.push(cur->right);
                        } else {
                            cur->right = new TreeNode(-1);
                            que.push(cur->right);
                        }
                    }
                    ++index;
                } else {
                    if (cur->val == -1)
                    {
                        cur->val = 1;
                        cur->left = new TreeNode(-1);
                        cur->right = new TreeNode(-1);
                        que.push(cur->left);
                        que.push(cur->right);
                    } else {
                        if (cur->left) 
                        {
                            que.push(cur->left);
                        } else {
                            cur->left = new TreeNode(-1);
                            que.push(cur->left);
                        }

                        if (cur->right)
                        {
                            que.push(cur->right);
                        } else {
                            cur->right = new TreeNode(-1);
                            que.push(cur->right);
                        }
                    }
                }
            }
            
            if (curDeep == treeDeep)
            {
                break;
            }
        }
        return root;
    }
};