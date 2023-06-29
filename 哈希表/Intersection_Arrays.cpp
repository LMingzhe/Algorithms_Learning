#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

/// leetcode 342 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 
/// @brief     时间复杂度: O(mn) 空间复杂度: O(n)

#

class Solution
{
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        std::unordered_set<int> nums_set(nums1.begin(), nums1.end());

        for (int num : nums2)  
        {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }

        return std::vector<int>(result_set.begin(), result_set.end());
        
    }
};