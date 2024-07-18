#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/// leetcode 739 每日温度
/// @brief 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
///        如果气温在这之后都不会升高，请在该位置用 0 来代替。

// 单调栈 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};




//fixme 暴力方法超时
class Solution  
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> result(n);
        result[n - 1] = 0;
        int flag = false;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (temperatures[j] > temperatures[i]) 
                {
                    result[i] = j - i;
                    flag = true;
                    break;
                }
            }
            if (!flag) result[i] = 0;
            flag = false;
        }
        return result;
    }
};