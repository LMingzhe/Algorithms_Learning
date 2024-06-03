#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::max_element;

/// leetcode 152 乘积最大子数组
/// @brief 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），
///        并返回该子数组所对应的乘积。测试用例的答案是一个 32-位 整数。

// FIXME 这道题leetcode新加了一个用例 [0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0]
// FIXME 导致大小益处，使用long long也无法解决，官方题解暂未更新

// 动态规划 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        // 表示以第i个元素结尾的乘积最大子数组的乘积
        vector<int> maxF(nums.size());
        // 表示以第i个元素结尾的乘积最小子数组的乘积 要考虑负数的情况，需要找到前面的最小值，所以需要维护这样一个数组
        vector<int> minF(nums.size());
        maxF[0] = nums[0];
        minF[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxF[i] = max(maxF[i - 1] * nums[i], max(minF[i - 1] * nums[i], nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(maxF[i - 1] * nums[i], nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};