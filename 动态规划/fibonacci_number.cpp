#include <iostream>
#include <vector>

using std::vector;

/// leetcode 509 斐波那契数列
/// @brief 动态规划五步曲：
///        1.确定dp数组以及下标的含义
///        2.确定递推公式
///        3.dp数组如何初始化
///        4.确定遍历顺序
///        5.举例推导dp数组

// 动态规划 时间复杂度：O(n) 空间复杂度：O(n)
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 动态规划 时间复杂度：O(n) 时间复杂度：O(n)
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

// 递归方法 时间复杂度：O(2^n) 空间复杂度：O(n)
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};