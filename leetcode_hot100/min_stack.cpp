#include <iostream>
#include <stack>
#include <limits.h>

using std::stack;

/// leetcode 155 最小栈
/// @brief 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
/// 实现 MinStack 类:
///   MinStack() 初始化堆栈对象。
///   void push(int val) 将元素val推入堆栈。
///   void pop() 删除堆栈顶部的元素。
///   int top() 获取堆栈顶部的元素。
///   int getMin() 获取堆栈中的最小元素。


class MinStack
{
private:
    stack<int> m_stack;
    stack<int> min_stack; // 辅助栈，保存每个元素插入时，栈内的最小值，与元素栈同步插入与删除
public:
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int val)
    {
        int min = val < min_stack.top() ? val : min_stack.top();
        m_stack.push(val);
        min_stack.push(min);
    }

    void pop()
    {
        m_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return m_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};