#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// @brief 完全背包问题
///        有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
///        每件物品都有无限个（也就是可以放入背包多次），求解将哪些物品装入背包里物品价值总和最大。

class Solution
{
public:
    int completeBackpack(vector<int>& weight, vector<int>& value, int bagWeight)
    {
        vector<int> dp(bagWeight + 1);

        // NOTE 完全背包循环顺序可更换
        for (int i = 0; i < weight.size(); i++)
        {
            // NOTE 完全背包的物品可以添加多次，从小到大遍历
            for (int j = weight[i]; j <= bagWeight; j++) 
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }

        return dp[bagWeight];
    }
};