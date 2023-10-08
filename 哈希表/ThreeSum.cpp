#include <iostream>
#include <vector>
#include <algorithm>

/// leetcode 15 三数之和
/// @brief 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
///        请你找出所有满足条件且不重复的三元组。
///        双指针法：a=nums[i] b=nums[left] c=nums[right]
///            时间复杂度: O(n^2) 空间复杂度: O(1)

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            // a去重复
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else left++;
            }
        }
        return result;
    }
};