#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// leetcode 287 寻找重复数
/// @brief 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。
///        假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。
///        你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
// 题解：https://leetcode.cn/problems/find-the-duplicate-number/solutions/261119/xun-zhao-zhong-fu-shu-by-leetcode-solution/

// 双指针法，时间复杂度O(nlogn)  空间复杂度O(1)
class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        int left = 1, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt <= mid) // 重复数target大于mid
            {
                left = mid + 1;
            } else { // 重复数target小于或等于mid
                right = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};