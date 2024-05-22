#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// leetcode 121 买卖股票的最佳时机
/// @brief 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
///        你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
///        返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

// 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        // 动态数据 dp[i][0] 第i天不持有股票所得最多现金
        //         dp[i][1] 第i天持有股票所得最多现金
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[n - 1][0];
    }
};

// 时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], -prices[i]);
        }
        return dp[(n - 1) % 2][0];
    }
};