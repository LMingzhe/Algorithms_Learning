#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

/// leetcode 581 最短无连续子树组
/// @brief 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
///        请你找出符合题意的 最短 子数组，并输出它的长度。

// 一次遍历 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left  = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (maxn > nums[i])
            {
                right = i;
            } else {
                maxn = nums[i];
            }
            if (minn < nums[n - i - 1])
            {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

// 排序 时间复杂度O(nlogn) 空间复杂度O(n)
class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        if(is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        vector<int> sorted_nums(nums);
        sort(nums.begin(), nums.end());
        int left = 0;
        while (nums[left] == sorted_nums[left])
        {
            left++;
        }
        int right = nums.size() - 1;
        while (nums[right] == sorted_nums[right])
        {
            right--;
        }
        return right - left + 1;
    }
};