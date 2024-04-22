#include <iostream>
#include <vector>

using std::vector;

/// leetcode 62 不同路径
/// @brief 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
///        机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
///        问总共有多少条不同的路径？

// 动态规划解法 时间复杂度:O(mxn) 空间复杂度:O(mxn)
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1) return 1; // 只有一行或一列的时候，只有一种解法
        int mesh[m][n];  // 记录到达坐标为(m,n)的网格有多少种解法

        // 初始化
        mesh[0][0] = 0;
        for (int i = 1; i < n; i++)  // 第一行初始化为1
        {
            mesh[0][i] = 1;
        }

        for (int i = 1; i < m; i++)  // 第一列初始化为1
        {
            mesh[i][0] = 1;
        }

        // 遍历网格
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                mesh[j][i] = mesh[j - 1][i] + mesh[j][i -1];
            }
        }

        /* 使用一个一维数组，节省空间
            int dp[n];  // 空间复杂度为:O(n)
            for (int i = 0; i < n; i++) dp[i] = 1;
            for (int j = 1; j < m; j++)
            {
                for (int i = 1; i < n; i++)
                {
                    dp[i] += dp[i - 1];
                }
            }
            return dp[n - 1];
        */

        return mesh[m - 1][n - 1];
    }
};

// 数论方法 时间复杂度:O(m) 空间复杂度:O(1)
// 一共m，n的话，无论怎么走，走到终点都需要 m + n - 2 步。
// 在这m + n - 2 步中，一定有 m - 1 步是要向下走的，不用管什么时候向下走。
// 可以转化为组合问题，给你m + n - 2个不同的数，随便取m - 1个数，有几种取法。
class Solution_v2
{
public:
    int uniquePaths(int m, int n)
    {
        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2;
        while (count--)
        {
            numerator *= t--;
            // 防止溢出，在计算分子的时候，不断除以分母
            while (denominator != 0 && numerator % denominator == 0)
            {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }
};