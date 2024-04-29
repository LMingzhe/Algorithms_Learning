#include <iostream>
#include <vector>

using std::vector;

/// leetcode 718 最长重复子数组
/// @brief 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。（数组就是连续的）
/// 时间复杂度O(n*m) 空间复杂度O(n*m) n为A长度 m为B长度

class Solution
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        // dp[i][j]：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        /* 时间复杂度为O(m)的滚动数组写法
            vector<int> dp(nums2.size() + 1, 0);
        */
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > result) result = dp[i][j];
            }
            /*
                for (int j = nums2.size(); j >= 1; j--)
                {
                    if (nums1[i - 1] == nums2[j - 1]) dp[j] = dp[j - 1] + 1;
                    else dp[j] = 0; // 注意这里不相等要有赋0的操作
                }
                if (dp[j] > result) result = dp[j];
            */
        }
        return result;
    }
};