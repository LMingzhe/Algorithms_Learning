#include<iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

/// leetcode 746
/// @brief 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
///        你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
///        请你计算并返回达到楼梯顶部的最低花费。
///  时间复杂度：O(n) 空间复杂度：O(n)

class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> dp(cost.size() + 1); // 到达第i个台阶的最低花费dp[i]
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < cost.size() + 1; i++)
        {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
            /* 简化空间复杂度
                int dp[2];  // 空间复杂度O(1)
                int dpN = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
                int dp[0] = dp[1];
                int dp[1] = dpN;
                return dp[1];
            */
        }
        return dp[cost.size()];
    }
};