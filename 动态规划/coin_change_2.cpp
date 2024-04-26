#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// leetcode 518 零钱兑换2
/// @brief 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。
/// 时间复杂度：O(mn) m 是amount，n 是 coins 的长度 空间复杂度：O(m)

class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // NOTE 求组合数就是外层for循环遍历物品，内层for遍历背包
        // NOTE 求排列数就是外层for遍历背包，内层for循环遍历物品
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[i] = dp[i] + dp[i - coins[i]];
            }
        }
        return dp[amount];
    }
};