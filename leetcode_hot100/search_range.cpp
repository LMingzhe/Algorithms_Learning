#include <iostream>
#include <vector>

using std::vector;

/// leetcode 34 在排序数组中查找元素的第一个和最后一个位置
/// @brief 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
///        请你找出给定目标值在数组中的开始位置和结束位置。如果数组中不存在目标值 target，返回 [-1, -1]。      
///        你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
/// 二分查找 时间复杂度O(logn) 空间复杂度O(1)

class Solution
{
private:
    // 找到第一个等于target的位置（lower=true）
    // 找到第一个大于target的位置（lower=false）
    int binarySearch(vector<int>& nums, int target, bool lower)
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                index = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return index;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() == 0) return {-1, -1};
        // 第一等于target的位置
        int leftIndex = binarySearch(nums, target, true);
        // 最后一个等于target的位置 = 第一个大于target的位置 - 1
        int rightIndex = binarySearch(nums, target, false) - 1;
        // 验证两个下标是否合法
        if (leftIndex <= rightIndex && rightIndex < nums.size() 
                && nums[leftIndex] == target && nums[rightIndex] == target)
        {
            return {leftIndex, rightIndex};
        }
        return {-1, -1};
    }
};