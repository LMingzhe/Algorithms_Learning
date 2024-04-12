#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

/// leetcode 40 middle 
/// @brief 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
///        candidates 中的每个数字在每个组合中只能使用一次。 所有数字（包括目标数）都是正整数。解集不能包含重复的组合。
///        时间复杂度：O(n*2^n) 空间复杂度：O(n)

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;
    int sum = 0;

    void backtracking(vector<int>& candidates, int target, int startIndex)
    {
        // if (sum > target) 在 for 循环中剪枝，这部分可以去掉
        // {
        //     return;
        // }
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i-1] && used[i - 1] == false)
            {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i + 1);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        result.clear();
        path.clear();
        used.resize(candidates.size(), false);
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};