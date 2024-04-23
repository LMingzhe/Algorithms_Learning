#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// @brief 01背包问题：有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
///                  每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。


class Solution
{
public:
    int zeroOneBackpack(vector<int>& weight, vector<int>& value, int bagWeight)
    {
        // dp[i][j]含义：表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
        vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));

        // 初始化，因为需要用到dp[i - 1]的值
        // j < weight[0]已在上方被初始化
        // j >= weight[0]的值就初始化为value[0]
        for (int j = weight[0]; j <= bagWeight; j++)
        {
            dp[0][j] = value[0];
        }

        for (int i = 1; i < weight.size(); i++)
        {
            for (int j = 0; j <= bagWeight; j++)
            {
                if (j < weight[i]) // 如果装不下，那么就继承dp[i - 1][j];
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else               // 如果能装下,就将值更新为 max(不装这个物品的最大值, 装这个物品的最大值)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        return dp[weight.size() - 1][bagWeight];
    }
};