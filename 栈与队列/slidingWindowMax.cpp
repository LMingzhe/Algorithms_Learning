#include <deque>
#include <vector>

using namespace std;

/// leetcode 239
/// @brief 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。
/// 时间复杂度：O(n) 空间复杂度O:(k) 

class Solution
{
private:
    class MyQueue // 单调队列
    {
    public:
        std::deque<int> que; // 使用deque来实现单调队列

        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        void pop(int value)
        {
            if (!que.empty() && value == que.front())
                que.pop_front();
        }
        
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        
        // 查询当前队列里的最大值，即队列前端front
        int front()
        {
            return que.front();
        }
    };
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        MyQueue que;
        std::vector<int> result;
        // 先将前k的元素放进队列
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        result.push_back(que.front());  // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);          // 滑动窗口移除最前面元素
            que.push(nums[i]);             // 滑动窗口前加入最后面的元素
            result.push_back(que.front());   // 记录对应的最大值
        }
        return result;
    }
};

