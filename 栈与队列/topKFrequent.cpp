#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/// leetcode 347
/// @brief 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
/// 时间复杂度：O(nlogk)  空间复杂度：O(n)

class Solution
{
public:
    class mycomparison
    {
    public:
        // 小顶堆排序
        bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };

    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        // 要统计元素出现频率
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        // 定义一个小顶堆，大小为k
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, mycomparison> pri_que;
        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }
        
        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        std::vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }
};