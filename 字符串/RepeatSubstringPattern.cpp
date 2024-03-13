#include <string>

using namespace std;

/// leetcode 459
/// @brief 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。


/// @brief 解法1：移动匹配 判断字符串s是否由重复子串组成，只要两个s拼接在一起，里面还出现一个s的话，就说明是由重复子串组成。
///        时间复杂度O(n) 空间复杂度O(1)
class Solution_v1
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string t = s + s;
        t.erase(t.begin());     // 去头
        t.erase(t.end() - 1);   // 去尾
        if (t.find(s) != std::string::npos) return true;
        return false;
    }
};

/// @brief 解法2：KMP 在由重复子串组成的字符串中，最长相等前后缀不包含的子串就是最小重复子串
///        时间复杂度O(n) 空间复杂度O(n)
class Solution_v2
{
public:
    void getNext(int* next, const string& s)
    {
        int j = -1;
        next[0] = j;

        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }

            if (s[i] == s[j + 1]) j++;

            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0) return false;

        int len = s.size();
        int next[len];
        getNext(next, s);
        
        // 数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) return true;

        return false;

    }
};