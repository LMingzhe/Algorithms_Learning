#include <iostream>
#include <queue>

using namespace std;

/// leetcode 225
/// @brief 使用队列实现栈的下列操作：
///                              push(x) -- 元素 x 入栈
///                              pop() -- 移除栈顶元素
///                              top() -- 获取栈顶元素
///                              empty() -- 返回栈是否为空
/// 时间复杂度：pop为O(n) 其他为O(1) 空间复杂度：O(n)

class MyStack
{
public:
    std::queue<int> que;
    MyStack() {}

    // 元素 x 入栈
    void push(int x)
    {
        que.push(x);
    }

    // 移除栈顶元素
    int pop()
    {   
        int index = que.size() - 1;
        // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
        for (int i = 0; i < index ; i++)
        {
            que.push(que.front());
            que.pop();
        }
        // 此时弹出的元素就是栈顶元素了
        int result = que.front();
        que.pop();
        return result;
    }

    // 获取栈顶元素
    int top()
    {
        return que.back();  
    }

    // 返回栈是否为空
    bool empty()
    {
        return que.empty();
    }
};