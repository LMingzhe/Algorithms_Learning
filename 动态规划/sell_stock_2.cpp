#include <iostream>
#include <vector>
#include <limits>
#include<algorithm>

using std::vector;
using std::min;
using std::max;

/// leetcode 121 买卖股票最佳时期
/// @brief prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
///        你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
///        返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
// 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        /* 空间复杂度 O(1) 写法
            vector<vector<int>> dp(2, vector<int>(2));  // 2*2 数组
        */
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            /*
                dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
                dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
            */
        }
        return dp[prices.size() - 1][1];
    }
};

// 贪心做法 时间复杂度:O(n) 空间复杂度:O(1)
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int low = INT32_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            low = min(low, prices[i]);
            result = max(result, prices[i] - low);
        }
        return result;
    }
};