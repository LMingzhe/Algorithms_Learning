#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

using namespace std;

/// leetocde 621 任务调度器
/// @brief 给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表，用字母 A 到 Z 表示，以及一个冷却时间 n。每个周期或时间间隔允许完成一项任务。
///        任务可以按任何顺序完成，但有一个限制：两个 相同种类 的任务之间必须有长度为 n 的冷却时间。
///        返回完成所有任务所需要的 最短时间间隔 。

// 模拟CPU执行过程，时间复杂度 O(∣tasks∣⋅∣Σ∣) 空间复杂度 O(∣Σ∣) ∣Σ∣ 是数组 task 中出现任务的种类
class Solution
{
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        if (n == 0)
        {
            return tasks.size();
        }
        unordered_map<char, int> freq;
        for (char ch : tasks)
        {
            ++freq[ch];
        }
        
        int m = freq.size(); // 任务种类数
        vector<int> nextValid;
        vector<int> rest;
        for (auto [_, v] : freq)
        {
            nextValid.push_back(1);
            rest.push_back(v);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); ++i)
        {
            ++time;
            int minNextValid = INT_MAX; // 搜索下一次执行任务的最小时间，避免CPU处于待命状态时进行不必要的遍历
            for (int j = 0; j < m; ++j)
            {
                if (rest[j])
                {
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            time = max(time, minNextValid); // 直接跳到下一次执行时间点
            int best = -1;
            for (int j = 0; j < m; ++j)
            {
                if (rest[j] && nextValid[j] <= time)
                {
                    if (best == -1 || rest[j] > rest[best]) // 优先执行剩余任务次数最多的任务种类
                    {
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1;
            --rest[best];
        }
        return time;
    }
};