#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

/// leetcode 394 字符串解码
/// @brief 给定一个经过编码的字符串，返回它解码后的字符串。
///  编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
///  你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
///  此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

// 栈操作 时间复杂度O(S) 空间复杂度O(S)
class Solution 
{
private:
    // 将字符数字转化为字符串返回
    string getDigits(string& s, size_t& ptr)
    {
        string ret = "";
        while (isdigit(s[ptr]))
        {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    // 将 vector<string> 中的字符串组合起来
    string getString(vector<string>& sub)
    {
        string ret;
        for (const auto& s : sub)
        {
            ret += s;
        }
        return ret;
    }

public:
    string decodeString(string s) 
    {
        vector<string> st; // 使用vector模拟栈操作
        size_t ptr = 0;

        while (ptr < s.length())
        {
            char cur = s[ptr];
            if (isdigit(cur))  // 数字字符，转化为string类型放入栈中
            {
                string digits = getDigits(s, ptr);
                st.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {  // 子母字符或'[' 转化为string类型，放入栈中
                st.push_back(string(1, s[ptr++]));
            } else {  // 遇到右括号']'
                ptr++;

                vector<string> sub; // 存储要组成的字符串
                while (st.back() != "[")
                {
                    sub.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back(); // 弹出'['
                reverse(sub.begin(), sub.end());
                int repTime = stoi(st.back()); // 获取数字，表示重复次数
                st.pop_back(); // 弹出数字字符
                string repSubstring = getString(sub); // 重复字串
                string s;
                while (repTime--)
                {
                    s += repSubstring;
                }
                st.push_back(s); // 再压入栈中
            }
        }
        return getString(st);
    }
};