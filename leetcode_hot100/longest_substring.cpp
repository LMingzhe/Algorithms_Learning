#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::unordered_set;
using std::max;

/// leetcode 3 无重复字符的最长字串
/// @brief 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。
/// 时间复杂度O(n) 空间复杂度O(n)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0) return 0;
        int result = 0;
        int right = -1; // 滑动窗口右指针，初始值为-1，相当于在字符串的左边界的左侧，还没开始移动
        unordered_set<char> set;
        // 枚举左指针的位置，初始值隐性地表示为-1
        for (int left = 0; left < s.size(); left++)
        {
            if (left != 0)
            {
                // 左指针向右移动一格，移除一个字符
                set.erase(s[left - 1]);
            }
            // 不停移动右指针，直到碰到重复字符
            while (right + 1 < s.size() && !set.count(s[right + 1]))
            {
                set.insert(s[right + 1]);
                right++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};