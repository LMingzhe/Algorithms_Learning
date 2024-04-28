#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// leetcode 123 买卖股票最佳时机3
/// @brief 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
///        设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
///        注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
/// 时间复杂度O:(n) 空间复杂度:O(n)

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() == 0 || prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5));
        dp[0][0] = 0;             // dp[i][0] 没有操作
        dp[0][1] = -prices[0];    // dp[i][1] 第一次持有股票
        dp[0][2] = 0;             // dp[i][2] 第一次不持有股票
        dp[0][3] = -prices[0];    // dp[i][3] 第二次持有股票
        dp[0][4] = 0;             // dp[i][4] 第二次不持有股票
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return dp[prices.size() - 1][4];
    }
};