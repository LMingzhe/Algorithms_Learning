#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::max;

/// leetcode 647 回文子串
/// @brief 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
///        具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

// 动态规划解法 时间复杂度O(n^2) 空间复杂度O(n^2)
class Solution
{
public:
    int countSubstrings(string s)
    {
        // dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)  // 注意遍历顺序dp[i][j]依赖dp[i+1][j-1]，所以应该从下到上，从左到右
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j]) // 只有头尾相等才有可能是回文子串
                {
                    if (j - i <= 1)      // 情况一和情况二
                    {                    // 情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
                        result++;        // 情况二：下标i 与 j相差为1，例如aa，也是回文子串
                        dp[i][j] = true;
                    }
                    else                 // 情况三下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，
                    {                    //           我们看i到j区间是不是回文子串就看aba是不是回文就可以了，那么aba的区间就是 i+1 与 j-1区间，
                        if (dp[i + 1][j - 1])//       这个区间是不是回文就看dp[i + 1][j - 1]是否为true。
                        {
                            result++;
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
        return result;
    }
};

// 双指针解法 时间复杂度O(n^2) 空间复杂度O(1)
class Solution_v2
{
public:
    int countSubstrings(string s)
    {
        int result = 0;
        for (int i = 0; i < s.size(); i++)  // 确定回文串，找中心向两边扩散看是否对称
        {
            result += extend(s, i, i, s.size());      // 一个元素作为中心点
            result += extend(s, i, i + 1, s.size());  // 两个元素作为中心点
        }
        return result;
    }
    int extend(const string& s, int i, int j, int n)
    {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j])
        {
            res++;
            i--;
            j++;
        }
        return res;
    }
};
