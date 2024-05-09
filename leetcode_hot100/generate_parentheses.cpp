#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/// leetcode 22 括号生成
/// @brief 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

class Solution
{
private:
    vector<string> result;
    string combin;
    
    void backtracking(int n, int left, int right)
    {
        if (combin.size() == n * 2) // 终止条件
        {
            result.push_back(combin);
            return;
        }

        if (left < n) // 先加左括号
        {
            combin.push_back('(');
            backtracking(n, left + 1, right);
            combin.pop_back();
        }

        if (right < left) // 再加右括号，右括号必须小于等于左括号
        {
            combin.push_back(')');
            backtracking(n, left, right + 1);
            combin.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        result.clear();
        combin.clear();
        backtracking(n, 0, 0);
        return result;
    }
};