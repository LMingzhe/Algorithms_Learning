#include <iostream>
#include <vector>

using std::vector;

/// leetcode 75 颜色分类
/// @brief 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
/// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。必须在不使用库内置的 sort 函数的情况下解决这个问题。

// 双指针法 时间复杂度O(n) 空间复杂度O(1) 
class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        int p0 = 0; // 指向下一个0的位置
        int p1 = 0; // 指向下一个1的位置
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1) // 处理搜索到1的情况
            {
                std::swap(nums[i], nums[p1]);
                p1++;
            }
            else if (nums[i] == 0) // 处理搜索到0的情况
            {
                std::swap(nums[i], nums[p0]);
                if (p0 < p1) std::swap(nums[i], nums[p1]); // p0在p1前面，会交换到一个1出去，再交换回来
                // 处理搜索到0的情况，两个指针同时加，确保 p0 <= p1，不会把0交换出去
                p0++;
                p1++;
            }
        }
    }
};