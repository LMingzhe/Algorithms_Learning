#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

/// leetcode 5 最长回文字串 本体可以结合 leetcode 647一起看，解法思想相同
/// @brief 给你一个字符串 s，找到 s 中最长的回文子串。
// 动态规划 时间复杂度O(n^2) 空间复杂度O(n^2)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int maxLen = 1;
        int begin = 0;
        // dp[i][j]：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // 注意遍历顺序dp[i][j]依赖dp[i+1][j-1]，所以应该从下到上，从左到右
        for (int i = s.size() -1; i >=0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j]) // 只有头尾相等才有可能是回文子串
                {
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                        if (j - i + 1 > maxLen)
                        {
                            maxLen = j - i + 1;
                            begin = i;
                        } 
                    }
                    else
                    {
                        if (dp[i + 1][j - 1])
                        {
                            dp[i][j] = true;
                            if (j - i + 1 > maxLen)
                            {
                                maxLen = j - i + 1;
                                begin = i;
                            } 
                        }
                    }
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};