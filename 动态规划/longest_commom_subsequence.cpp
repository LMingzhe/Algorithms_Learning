#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::max;

/// leetcode 1143 最长公共子序列
/// @brief 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。(不要求连续)
/// 时间复杂度: O(n * m)，其中 n 和 m 分别为 text1 和 text2 的长度
/// 空间复杂度: O(n * m)

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1]) // 找到一个公共元素
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    // 没有找到公共元素，取text[0, i-2]与text2[0, j-1]的最长公共子序列和
                    //                 text2[0， i-1]与text2[0, j-2]的最长公共子序列中的最大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};