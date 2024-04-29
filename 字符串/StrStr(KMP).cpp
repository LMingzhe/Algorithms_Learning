#include <iostream>
#include <string>

/// leetcode 28 找出字符串中第一个匹配项的下标
/// @brief 给定一个 haystack(文本串长度为n) 字符串和一个 needle(模式串长度为m) 字符串，
///        haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
///        实际就是实现KMP算法
///        最长公共子序列： abcfjabc 最长公共子序列长度为3(abc)
///   前缀表（next数组）：当字符不匹配的时候应该指针应该移动的位置，其实就是移动到最长公共子序列长度的下一个值，因为前面部分已经确定能匹配了        
///    eg：模式串下标   0  1  2  3  4  5
///        模式串      a  a  b  a  a  f
///        前缀表      0  1  0  1  2  0
///        时间复杂度：O(n+m) next数组构建为O(m) 匹配过程O(n)

// 将前缀表统一右移一位，初始为-1
class Solution_v1
{
public:
    void getNext(int* next, const std::string& s)
    {
        // j:指向前缀末尾 并表示i(不包括i)之前字符串的最长公共子串长度，也就是i-1(包括i-1)之前的公共子串长度
        // i:指向后缀末尾
        // 1.初始化
        int j = -1;
        next[0] = j;

        for (int i = 1; i < s.size(); i++)  // 注意i从1开始
        {
            // 2.处理前后缀不同情况
            while (j >= 0 && s[i] != s[j + 1])  // 前后缀不相同了
            {
                j = next[j];  // 向前回退
            }

            // 3.处理前后缀相同情况
            if (s[i] == s[j + 1]) j++;  // 找到相同的前后缀

            next[i] = j;  // 将j（前缀的长度）赋给next[i]
        }
    }

    int strStr(std::string haystack, std::string needle)
    {
        if (needle.size() == 0) return 0;

        int next[needle.size()];
        getNext(next, needle);

        int j = -1;  // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])  
            {
                j = next[j];
            }

            if (haystack[i] == needle[j + 1]) j++;

            if (j == needle.size() - 1) return (i - needle.size() + 1);
        }

        return -1;
    }
};



// 将前缀表当作next数组
class Solution_v2 
{
public:
    void getNext(int* next, const std::string& s)
    {
        // j:指向前缀末尾 并表示i(包括i)之前字符串的最长公共子串长度
        // i:指向后缀末尾
        // 初始化
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            // 处理前后缀不相同的情况
            while(j > 0 && s[j] != s[i])
            {
                j = next[j - 1];  // 向前回退
            }

            // 处理前后缀相同情况
            if (s[j] == s[i])
            {
                j++;
            }

            next[i] = j;
        }
    }

    int strStr(std::string haystack, std::string needle)
    {
        if (needle.size() == 0) return 0;

        // 构建next数组
        int next[needle.size()];
        getNext(next, needle);

        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j]) j++;

            if (j == needle.size()) return (i - needle.size() + 1);
        }

        return -1;
    }
};