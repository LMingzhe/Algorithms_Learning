#include <iostream>
#include <vector>

using std::vector;

/// leetcode 33 搜索旋转排序数组
/// @brief 给你旋转后的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
///        必须设计一个时间复杂度为 O(log n) 的算法解决此问题
/// 时间复杂度O(logn) 空间复杂度O(1)

// 数组局部有序的二分查找
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) // 左边有序
            {
                if (target >= nums[0] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else // 右边有序
            {
                if (target > nums[mid] && target <= nums[nums.size() - 1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};