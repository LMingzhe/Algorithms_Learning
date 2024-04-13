#include <iostream>
#include <vector>

using std::vector;

/// leetcode 
/// @brief 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
///        解集不能包含重复的子集。
///        时间复杂度：O(n*2^n)  空间复杂度：O(n)

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex)
    {
        result.push_back(path);  // 收集子集
        if (startIndex >= nums.size())
        {
            return;
        }

        // 求取子集问题，不需要任何剪枝！因为子集就是要遍历整棵树
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};