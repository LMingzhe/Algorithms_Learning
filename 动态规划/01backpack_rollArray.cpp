#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// @brief 使用滚动数组（一维数组）解决背包问题
///        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
///        其实可以发现如果把dp[i - 1]那一层拷贝到dp[i]上，表达式完全可以是：dp[i][j] = max(dp[i][j], dp[i][j - weight[i]] + value[i]);
///        与其把dp[i - 1]这一层拷贝到dp[i]上，不如只用一个一维数组了，只用dp[j]（一维数组，也可以理解是一个滚动数组）。
///        本质上使用一维数组模拟二维数组的遍历，因为下一层的数组值由上一层推导而来，可以进行覆盖。但记得要从右往左遍历。
///        但记得要从右往左遍历，因为二维数组中右下角的值由左上角决定

class Solution
{
public:
    int zeroOneBackpack(vector<int>& weight, vector<int>& value, int bagWeight)
    {
        // 使用滚动数组来维护dp结果
        // dp[i]：容量为j的背包，所背的物品价值可以最大为dp[j]
        vector<int> dp(bagWeight + 1, 0);

        // NOTE 注意1：一定要先遍历物品（如果先遍历背包容量，回导致背包里只放入了一个物品）
        for (int i = 0; i < weight.size(); i++)
        {
            // NOTE 注意2：背包容量一定要倒序遍历（保证物品i只被放入一次）
            for (int j = bagWeight; j >= weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }

        return dp[bagWeight];
    }
};