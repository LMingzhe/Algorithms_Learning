#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "TreeNode_def.h"

using namespace std;

/// leetcode 打家劫舍3
/// @brief 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
///        除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
///        给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

// 动态规划 时间复杂度O(n)  空间复杂度O(n)
class Solution
{
private:
    unordered_map<TreeNode*, int> selected;   // 选择节点的情况下，该节点的子树上被选择的节点的最大权值和
    unordered_map<TreeNode*, int> noSelected; // 不选择节点的情况下，该节点的子树上被选择的节点的最大权值和

    // 深度优先后续遍历
    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left); // 左
        dfs(root->right); // 右
        // 中
        // 选择当前节点，则其左右孩子节点不能被选择
        selected[root] = root->val + noSelected[root->left] + noSelected[root->right];
        // 不选择当前节点，则其左右孩子节点可选择也可不选择
        noSelected[root] = max(selected[root->left], noSelected[root->left]) +
                           max(selected[root->right], noSelected[root->right]);
    }
public:
    int rob(TreeNode* root)
    {
        dfs(root);
        return max(selected[root], noSelected[root]);
    }
};