#include <iostream>
#include <string>
#include <algorithm>

/// leetcode 541 反转字符串2
/// @brief 给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
///        如果剩余字符少于 k 个，则将剩余字符全部反转。
///        如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

class Solution
{
public:
    void reverse(std::string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            std::swap(s[i], s[j]);
        }
    }
    std::string reverseStr(std::string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k < s.size())
            {
                reverse(s, i, i + k - 1);
            }
            else
            {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转
                reverse(s, i, s.size() - 1);
            }
        }
        return s;
    }
};
