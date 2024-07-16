#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// leetcode 560 和为K的子树组
/// @brief 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
///        子数组是数组中元素的连续非空序列。

// 前缀和 + 哈希表
class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp; // 记录前缀和
        mp[0] = 1;
        int count = 0;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre += nums[i];
            if (mp.find(pre - k) != mp.end())
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

// 时间复杂度O(n^2) 空间复杂度O(1) 超时
class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int count = 0;
        for (int start = 0; start < nums.size(); start++)
        {
            int sum = 0;
            for (int end = start; end >= 0; end--)
            {
                sum += nums[end];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};