#include <iostream>
#include <vector>

using std::vector;

/// leetcode 77
/// @brief 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
///        回朔是递归的副产品，有回朔必定有递归
///        回朔是一种暴力算法，并不是什么高效的算法
/// 时间复杂度：O(n*2^n) 空间复杂度：O(n)

class Solution
{
private:
    vector<vector<int>> result;  // 存放符合条件结果的集合
    vector<int> path;            // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k) 
        {
            result.push_back(path);
            return;
        }
        
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);  // 处理节点
            backtracking(n, k, startIndex + 1);  // 递归
            path.pop_back();  // 回朔，撤销处理的节点
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