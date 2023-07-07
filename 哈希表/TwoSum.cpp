#include <iostream>
#include <unordered_map>
#include <vector>


/// leetcode 1 两数之和
/// @brief 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
///        你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
///        时间复杂度O(n) 空间复杂的O(n)

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
         std::unordered_map<int, int> map;
         for (int i = 0; i < nums.size(); i++)
         {
            auto iter = map.find(target - nums[i]);
            if(iter != map.end())
            {
                return {iter->second, i};
            }
            map.insert(std::pair<int, int>(nums[i], i));
         }
         return {};
    }
};