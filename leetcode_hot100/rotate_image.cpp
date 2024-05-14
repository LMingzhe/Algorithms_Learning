#include <iostream>
#include <vector>

using std::vector;

/// leetcode 旋转图像
/// @brief 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你原地将图像顺时针旋转 90 度。
/// 图像顺时针旋转90度公式：matrix[row][col] -> matrixnew​[col][n−row−1]
/// 图像先水平轴翻转 matrix[row][col] -> matrix[n−row−1][col]
///   再主对角线翻转                  -> matrix[col][n-row-1] 即可满足要求

/// 时间复杂度O(n^2) 空间复杂度O(1)
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        // 水平翻转图像 matrix[row][col] -> matrix[n−row−1][col]
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转 matrix[row][col] -> ​matrix[col][row]
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};