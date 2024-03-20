#include <iostream>
#include <stack>
#include <string>

using namespace std;

/// leetcode 20
/// @brief 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
/// 有效字符串需满足：
///     左括号必须用相同类型的右括号闭合。
///     左括号必须以正确的顺序闭合。
///     注意空字符串可被认为是有效字符串。
///     时间复杂度：O(n)     空间复杂度：O(n)

class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> st;
        if (s.size() % 2) return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 栈空说明右括号多了  || 和栈顶元素不相等说明没有对应的左括号匹配
            else if (st.empty() || s[i] != st.top()) return false;
            // 匹配一个，弹出
            else st.pop();
        }
        // 如果全部匹配，栈应该为空
        return st.empty();
    }
};