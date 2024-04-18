#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// leetcode 70 爬楼梯
/// @brief 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
///        每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
///  间复杂度：O(n) 空间复杂度：O(n)

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            // 到达n阶，最后一步只能爬1阶或者2阶
            // 所以爬n阶的方法数 = 爬n-1阶方法数 + 爬n-2阶方法数
            dp[i] = dp[i - 1] + dp[i - 2];
            /* 这里可以像斐波那契数列那样优化空间复杂度
                int dp[2];  // 空间复杂度O(1)
                int sum = dp[0] + dp[1];
                int dp[0] = dp[1];
                int dp[1] = sum;
                return dp[1];
            */
        }
        return dp[n];
    }
};