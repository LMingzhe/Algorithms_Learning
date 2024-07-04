#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// leetcode 438 找到字符串中所有子母异位词
/// @brief 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
///        异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

// 滑动窗口法
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int sLen = s.size();
        int pLen = p.size();

        if (sLen < pLen)
        {
            return {};
        }

        vector<int> result;
        vector<int> sCount(26);
        vector<int> pCount(26);
        
        for (int i = 0; i < pLen; i++)
        {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }

        if (sCount == pCount)
        {
            result.push_back(0);
        }

        for (int i = 0; i < sLen - pLen; i++)
        {
            sCount[s[i] - 'a']--;
            sCount[s[i + pLen] - 'a']++;
            if (sCount == pCount) 
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
