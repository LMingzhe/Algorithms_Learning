#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

/// leetcode 39 组合总和
/// @brief 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
///        找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
///        candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

// 求组合问题是经典的回溯问题
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    // 一个集合来求组合的话，就需要index
    // 多个集合取组合，各个集合之间相互不影响，那么就不用startIndex
    void backtracking(vector<int>& candidates, int target, int index)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) // 剪枝加速
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        result.clear();
        path.clear();
        sum = 0;
        sort(candidates.begin(), candidates.end()); // 剪枝需要有序
        backtracking(candidates, target, 0);
        return result;
    }
};