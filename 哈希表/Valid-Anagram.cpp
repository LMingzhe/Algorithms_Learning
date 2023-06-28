#include <iostream>
#include <string>


/// leetcode 242 有效的异位字母 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
/// @brief 时间复杂度为O(n)，空间上因为定义是的一个常量大小的辅助数组，所以空间复杂度为O(1)。

class Solution {
public:
    bool isAnagram(std::string s, std::string t) 
    {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int j = 0; j < t.size(); j++)
        {
            record[s[j] - 'a']--;
        }
        for (int k = 0; k < 26; k++)
        {
            if (record[k] != 0)
            {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
};