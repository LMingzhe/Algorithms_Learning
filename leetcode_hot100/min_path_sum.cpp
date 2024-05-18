#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

/// leetcode 64 最小路径和
/// @brief 给定一个包含非负整数的 m x n 网格 grid ，
///        请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
///        每次只能向下或者向右移动一步。

// 动态规划 时间复杂度O(nm) 空间复杂度O(nm)
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        // dp[i][j]：到达[i][j]位置时数字总和最小值
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // 初始化dp数组
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};