#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// leetcode 221 最大正方形
/// @brief 表示以 (i,j)(i, j)(i,j) 为右下角，且只包含 111 的正方形的边长最大值。

// 动态规划 时间复杂度O(nm) 空间复杂度O(nm)
class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        // dp[i][j]:表示以 (i,j) 为右下角，且只包含 1 的正方形的边长最大值。
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int maxEdge = 0;

        // initial
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                maxEdge = 1;
            } 
        }
        for (int i = 0; i < cols; i++)
        {
            if (matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                maxEdge = 1;
            } 
        }

        // dp
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                {
                    // 以上方、左方、左上方位置为正方形右下角的最大正方形边长，取三者最小值，
                    // 即三个方向能与matrix[i][j]组成以matrix[i][j]为正方形右下角的最大正方形
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    maxEdge = max(maxEdge, dp[i][j]);
                }
            }
        }
        return maxEdge * maxEdge;
    }
};