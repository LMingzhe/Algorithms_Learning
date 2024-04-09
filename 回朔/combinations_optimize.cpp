#include <iostream>
#include <vector>

using std::vector;

/// @brief 组合剪枝优化
/// 时间复杂度：O(n*2^n) 空间复杂度：O(n)

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        // 剪枝：
        // 列表中剩余的元素 (n-i) >= 所需要的元素个数 (k-path.size())
        // 在集合n中至多从 i <= n - (k - path.size()) + 1 开始遍历，+1是因为包括起始位置，是一个左闭合的区间
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(n, k, startIndex + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};