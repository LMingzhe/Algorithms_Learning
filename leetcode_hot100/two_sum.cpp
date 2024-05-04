#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

/// leetcode 1 两数之和

// 时间复杂度 O(n) 空间复杂度O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = map.find(target - nums[i]);
            if (it != map.end())
            {
                return {it->second, i};
            }
            map.insert(std::pair<int, int>(nums[i], i));
        }
        return {};
    }
};