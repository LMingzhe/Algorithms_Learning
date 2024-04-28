#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// leetcode  122 买卖股票最佳时机2
/// @brief 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
///        设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
///        注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
/// 时间复杂度:O(n) 空间复杂度:O(n)

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        /* 时间复杂度 O(1) 写法
            vector<vector<int>> dp(2, vector<int>(2));
        */
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            /*
                dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
                dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
            */
        }
        return dp[prices.size() - 1][1];
        /*
            return  dp[(prices.size() - 1) % 2][1];
        */
    }
};