#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;

/// leetcode 198 打家劫舍
/// @brief 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
///         如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

// 动态规划 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        // dp[i]：表示前i间房屋能够偷窃到的最高总金额
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            // 第i间偷与不偷
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};