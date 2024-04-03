#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "TreeNode_def.h"

using namespace std;

/// @brief 迭代法实现二叉树的前、中、后序遍历

// 前序遍历 中-左-右
class Solution
{
public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::stack<TreeNode*> st;
        std::vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if (cur->right) st.push(cur->right);  // 右树先入栈，这样是后出
            if (cur->left)  st.push(cur->left);   // 左树后入栈，比右树先出
        }
        return result;
    }
};

// 中序遍历 左-中-右
class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::stack<TreeNode*> st;
        std::vector<int> result;
        if (root == nullptr) return result;
        TreeNode* cur = root;
        while (cur != nullptr && !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;  // 左
            }
            else
            {
                TreeNode* node = st.top();  // 从栈里弹出的数据，就是要处理的数据
                st.pop();
                result.push_back(node->val);  // 中
                st.push(cur->right);  // 右
            }
        }
    }
};


// 后序遍历 左-右-中
class Solution
{
public:
    std::vector<int> posorderTraversal(TreeNode* root)
    {
        std::stack<TreeNode*> st;
        std::vector<int> result;
        if (root == nullptr) return result;
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            result.push_back(cur->val);
            st.pop();
            if (cur->left)  st.push(cur->left);   // 左树先进栈，后出
            if (cur->right) st.push(cur->right);  // 右树后进栈，先出
        }
        reverse(result.begin(), result.end());        // 前面遍历的顺序是 中-右-左，只要将结果反转，
        return result;                                // 即为后续遍历 左-右-中
    }
};