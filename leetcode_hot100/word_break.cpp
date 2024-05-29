#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_set;
using std::max;

/// leetcode 139 单词拆分
/// @brief 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
///        注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
/// 时间复杂度O(n^2) 空间复杂度O(n)

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> set; // 建立哈希表用于去重和快速查找
        for (const string& word : wordDict)
        {
            set.insert(word);
        }
        // dp[i]：s[0, i-1]组成的字符串能否被空格拆分为若干个字典中出现的单词
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 0; j < i; j++) // 枚举分割
            {
                if (dp[j] && set.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};