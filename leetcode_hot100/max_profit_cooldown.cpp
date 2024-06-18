#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// leetcode 309 买卖股票的最佳时机含冷冻期
/// @brief 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
///        设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
///        卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
///        注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 动态规划 时间复杂度O(n)  空间复杂度O(n)
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        if (n == 0) return 0;
        // dp[i][0]:达到买入股票状态
        // dp[i][1]:达到保持卖出股票状态
        // dp[i][2]:达到今天就卖出股票状态
        // dp[i][3]:达到冷冻期状态
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0; 
        dp[0][3] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]));
    }
};