#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

/// leetcode 90
/// @brief 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
///        解集不能包含重复的子集。
///        时间复杂度：O(n*2^n)  空间复杂度：O(n)

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int>& nums, int startIndex)
    {
        result.push_back(path);
        if (startIndex >= nums.size())
        {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        result.clear();
        path.clear();
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};