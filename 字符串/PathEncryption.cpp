#include <iostream>
#include <string>

/// leetcode LCR 122 路径加密 剑指offer 05.替换空格
/// @brief 请实现一个函数，把字符串 s 中的每个空格替换成"%20"
/// 时间复杂度：O(n)  空间复杂度：O(1)

class Solution
{
public:
    std::string pathEncryption(std::string path)
    {
        int spaceCount = 0;
        int oldSize = path.size();
        for (auto c : path)
        {
            if (c == ' ')
            {
                spaceCount++;
            }
        }
        path.resize(path.size() + spaceCount * 2);
        int newSize = path.size();
        for (int i = newSize - 1, j = oldSize - 1; j < i; i--, j--)
        {
            if (path[j] != ' ')
            {
                path[i] = path[j];
            }
            else
            {
                path[i] = '0';
                path[i - 1] = '2';
                path[i - 2] = '%';
                i -= 2;
            }
        }
        return path;
    }
};