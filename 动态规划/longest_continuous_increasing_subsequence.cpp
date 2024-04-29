#include <iostream>
#include <vector>

using std::vector;

/// leetcode 674 最长连续递增序列
/// @brief 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

// 动态规划解法 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};

// 非动态规划解法(原来这个是贪心) 时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        if (nums.size() <= 1) return nums.size();
        int length = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1]) length++;
            else length = 1;

            if (length > result) result = length;
        }
        return result;
    }
};