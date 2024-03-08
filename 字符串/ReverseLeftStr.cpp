#include <iostream>
#include <string>
#include <algorithm>

/// @brief 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
///        比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"
///            时间复杂度: O(n) 空间复杂度：O(1)


class Solution
{
public:
    std::string reverseLeftWords(std::string s, int n)
    {
        std::reverse(s.begin(), s.begin() + n);
        std::reverse(s.begin() + n, s.end());
        std::reverse(s.begin(), s.end());
    }
};