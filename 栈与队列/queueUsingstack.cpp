#include <iostream>
#include <stack>

using namespace std;

/// leetcode 232
/// @brief 使用栈实现队列的下列操作：
///                             push(x) -- 将一个元素放入队列的尾部。
///                             pop() -- 从队列首部移除元素。
///                             peek() -- 返回队列首部的元素。
///                             empty() -- 返回队列是否为空。
/// 时间复杂度： pop和peek为O(n) push和empty为O(1)   空间复杂度：O(n)

class MyQueue
{
public:
    std::stack<int> in;
    std::stack<int> out;

    MyQueue() {}
    
    // 将一个元素放入队列的尾部
    void push(int x)
    {
        in.push(x);
    }

    // 从队列首部移除元素
    int pop()
    {
        // 只有输出栈空时，将输入栈数据全部导入到输出栈中，再弹出输出栈第一个数据
        // 输出栈不空时，直接弹出输出栈顶层数据即可
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int result = out.top();
        out.pop();
        return result;
    }

    // 返回队列首部的元素
    int peek()
    {
        // 直接使用已有的pop函数
        int result = this->pop();
        // 因为pop函数弹出了元素result，所以再添加回去
        out.push(result);
        return result;
    }

    // 返回队列是否为空
    bool empty()
    {
        return in.empty() && out.empty();
    }

};