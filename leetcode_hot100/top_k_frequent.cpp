#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/// leetcode 347 前K个高频元素
/// @brief 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

// 优先队列，时间复杂度O(nlogk) 空间复杂度O(n)
class Solution
{
public:
    // 重载运算符，用于建立小顶堆
    struct mycomparison
    {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>&  rhs)
        {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // 统计元素出现频率
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        // 使用优先队列定义小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};