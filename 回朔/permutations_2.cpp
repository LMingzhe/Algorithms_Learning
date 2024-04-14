#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

/// leetcode 46 全排列
/// @brief 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
/// 时间复杂度: O(n! * n) 空间复杂度: O(n)

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;

    void backtracking(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 
            if (used[i] == true || (i>0 && nums[i] == nums[i-1] && used[i-1]==true)) // 去除深度上的重复，path中不含重复元素
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        result.clear();
        path.clear();
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums);
        return result;
    }
};