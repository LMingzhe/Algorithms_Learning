#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::sort;

/// leetcode 56 合并区间
/// @brief 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
///        请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
/// 时间复杂度O(nlogn) (排序) 空间复杂度O(logn)

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 0) return {};
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end()); // 排序，按左括号大小排序
        for (int i = 0; i < intervals.size(); i++)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            // 上一个区间的右值小于当前区间的左值，两个区间不重合
            if (!merged.size() || merged.back()[1] < L) 
            {
                merged.push_back({L, R});
            }
            else // 比较上个区间和当前区间的右值大小，取最大值
            {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};