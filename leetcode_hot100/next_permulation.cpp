#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/// leetcode 31 下一个排列
/// @brief 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
///        那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
/// 双指针法，需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。「较小数」尽量靠右，而「较大数」尽可能小
/// 时间复杂度O(n) 空间复杂度O(1)

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) // 首先从后向前查找第一个顺序对 (i,i+1)，满足 a[i] < a[i+1]
        {                                        // 这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;            // 如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素j满足 a[i]<a[j]。这样「较大数」即为a[j]。
            while (j >= i + 1 && nums[i] >= nums[j])
            {
                j--;
            }
            std::swap(nums[i], nums[j]);  // 交换a[i]与a[j]，此时可以证明区间 [i+1,n) 必为降序。
        }
        std::reverse(nums.begin() + i + 1, nums.end()); // 可以直接使用双指针反转区间 [i+1,n) 使其变为升序，而无需对该区间进行排序。
    }
};