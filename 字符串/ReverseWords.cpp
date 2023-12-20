#include <iostream>
#include <string>

/// leetcode 151.翻转字符串里的单词
/// @brief 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括
///        如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个
///        思路步骤：使用双指针(快慢指针)法，快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组 慢指针：指向更新 新数组下标的位置
///                1.去除多余空格 2.反转整个字符串 3.逐个反转单次

class Solution
{
public:
    void reverse(std::string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            std::swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(std::string& s)
    {
        int slow = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (slow != 0) s[slow++] = ' ';
                while (i < s.size() && s[i] != ' ')
                {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    std::string reverseWords(std::string s)
    {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};