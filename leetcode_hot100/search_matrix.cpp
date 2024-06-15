#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

/// @brief 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
///         每行的元素从左到右升序排列。
///         每列的元素从上到下升序排列。


using namespace std;

// Z字形查找 时间复杂度O(n+m) 空间复杂度O(1)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int x = 0, y = m - 1;
        while (x < n && y >= 0)
        {
            if (matrix[x][y] == target)
            {
                return true;
            }
            if (matrix[x][y] > target)
            {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
};

// 对每一行数据进行二分查找 时间复杂度O(mlogn) 空间复杂度O(1)
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for (const auto& row : matrix)
        {
            // std::lower_bound 底层实现为二分查找 复杂度O(logn) 找到第一个不小于给定值的第一个元素的位置
            auto it = std::lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target)
            {
                return true;
            }
        }
        return false;
    }
};