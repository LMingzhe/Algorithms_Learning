#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
using std::max;
using std::accumulate;

/// leetcode 416 分割等和子集
/// @brief 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
///        注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200
///        时间复杂度：O(n^2) 
///        空间复杂度：O(n)  虽然dp数组大小为常数，但可能为大常数

class Solution
{
public:
    bool canPartition(vector<int>& nums) // weight[i] == value[i]
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; // 不为整数，直接返回false；
        int target = sum / 2;
        // dp[i]：i表示背包重量，dp[i]表示当前i下，装了价值多少的东西 即 dp[i] <= i
        vector<int> dp(target + 1, 0); 
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 当dp[target] == target, 说明在背包容量为target时，正好装了价值target的物品
        if (dp[target] == target) return true; 
        return false;
    }
};