#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

/// @brief 单调队列实现滑动窗口

// 单调队列（从大到小）
class MyBigQueue
{
private:
    deque<int> que; // 使用deque来实现单调队列

public:
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int value)
    {
        if (!que.empty() && value == que.front())
        {
            que.pop_front();
        }
    }

    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int value)
    {
        while (!que.empty() && value > que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
    }

    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    int front()
    {
        return que.front();
    }
};

// 单调队列（从小到大）
class MySmallQueue
{
private:
    deque<int> que;

public:

    void pop(int value)
    {
        if (!que.empty() && value == que.front())
        {
            que.pop_front();
        }
    }

    void push(int value)
    {
        while (!que.empty() && value < que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
    }

    int front()
    {
        return que.front();
    }
};

int main(int argc, char const *argv[])
{
    string input;
    getline(cin, input);

    vector<int> nums;
    int k;

    // 找到并截取nums的部分
    int numsStart = input.find('[');
    int numsEnd = input.find(']');
    string numsStr = input.substr(numsStart + 1, numsEnd - numsStart - 1);

    // 用字符串流处理nums字符串，提取数字
    stringstream ss(numsStr);
    string temp;
    while (getline(ss, temp, ','))
    {
        nums.push_back(stoi(temp));
    }

    // 找到并提取k的值
    int kStart = input.find("k = ") + 4;
    k = stoi(input.substr(kStart));

    MyBigQueue queBig; // 获取区间最大值
    MySmallQueue queSmall; // 获取区间最小值

    // 先将前k的元素放进队列
    for (int i = 0; i < k; i++)
    {
        queBig.push(nums[i]);
        queSmall.push(nums[i]);
    }

    int result = queBig.front() - queSmall.front();
    for (int i = k; i < nums.size(); i++)
    {
        queBig.pop(nums[i - k]); // 滑动窗口移除最前面元素
        queBig.push(nums[i]);  // 滑动窗口前加入最后面的元素

        queSmall.pop(nums[i - k]);
        queSmall.push(nums[i]);

        result = max(result, queBig.front() - queSmall.front());
    }

    cout << result << endl;
    return 0;
}
