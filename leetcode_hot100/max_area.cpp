#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

/// leetcode 11 盛最多水的容器
/// @brief 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
///        找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。

// 双指针法 时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;
        int result;
        while (left < right)
        {
            int area = (right - left) * min(height[right], height[left]);
            result = max(result, area);
            // 移动指向较小值的那个指针
            if (height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};


// 以为是动态规划，实际是暴力解，leetcode超内存了
class Solution_v2
{
public:
    int maxArea(vector<int>& height)
    {
        if (height.size() == 2) return min(height[0], height[1]);
        int result = 0;
        vector<int> dp(height.size(), 0);
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                dp[j] = max(dp[j - 1], (j - i) * min(height[i], height[j]));
                if (dp[j] > result) result = dp[j];
            }
        }
        return result;
    }
};