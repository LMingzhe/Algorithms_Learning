#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// leetcode 300 最长递增子序列
/// @brief 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
/// 时间复杂度:O(n^2) 空间复杂度O:(n)

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1); // dp[i]:表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                // dp[i]的状态由 dp[0] ~ dp[i -1] 决定
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result) result = dp[i]; // 取长的子序列
        }
        return result;
    }
};