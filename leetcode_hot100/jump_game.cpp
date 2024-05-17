#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/// leetcode 55 跳跃游戏
/// @brief 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
///        判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

// 贪心算法 时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        int rightmost = 0; // 能够最远到达的位置
        for (int i = 0; i < n; i++)
        {
            if (i <= rightmost) // 更新最远到达位置
            {
                rightmost = std::max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) return true;
            }
            else break; // 一旦i超过目前能够到达的最远位置，就说明不可能到达最后一个下标了
        }
        return false;
    }
};