#include <iostream>
#include <vector>
#include <algorithm>

/// leetcode 18 四数之和
/// @brief n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
///        使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
///        时间复杂度: O(n^3) 空间复杂度: O(1)

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0)
            {
                break;
            }

            // 对 nums[k] 去重
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }

            for (int i = k + 1; i < nums.size(); i++)
            {
                // 2级剪枝
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
                {
                    break;
                }

                // 对 nums[i] 去重
                if (i > k + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] == target)
                    {
                        result.push_back(std::vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (right > left && nums[left + 1] == nums[left]) left++;
                        while (right > left && nums[right - 1] == nums[right]) right--;
                        left++;
                        right--;
                    }
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    else if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
                    else left++;
                }
            }
        }
        return result;
    }
};