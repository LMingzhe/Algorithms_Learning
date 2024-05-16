#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::max;

/// leetcode 53 最大子数组和
/// @brief 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
///        子数组是数组中的一个连续部分。
/// 时间复杂度O(n) 空间复杂度O(1)

// 贪心算法 
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int result = std::numeric_limits<int>::min();
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > result) result = count;
            if (count <= 0) count = 0; // 重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};

// 动态规划
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> dp(nums.size()); // dp[i]:0~i以i结尾的连续子数组最大和
        dp[0] = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > maxSum) maxSum = dp[i];
        }
        return maxSum;
    }
};

// 动态规划-滚动数组
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = nums[0];
        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre = max(pre + nums[i], nums[i]);
            maxSum = max(pre, maxSum);
        }
        return maxSum;
    }
};

