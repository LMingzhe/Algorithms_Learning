#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::min;

/// leetcode 72 编辑距离
/// @brief 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
/// 你可以对一个单词进行如下三种操作：1.插入一个字符 2.删除一个字符 3.替换一个字符
/// 官方题解：https://leetcode.cn/problems/edit-distance/solutions/188223/bian-ji-ju-chi-by-leetcode-solution/

// 动态规划，时间复杂度O(nm) 空间复杂度O(nm)
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // D[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // 初始化
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++)
        {
            dp[0][j] = j;
        }

        // dp
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                int left = dp[i][j - 1] + 1; // 左
                int up = dp[i - 1][j] + 1;   // 上
                int left_up = dp[i - 1][j - 1]; // 左上方
                // 如果最后一个字母（A的第i个，B的第j个）不相同，则需要+1做一次操作，注意字符串下标从0开始要
                if (word1[i - 1] != word2[j - 1]) left_up += 1; 
                dp[i][j] = min(left, min(up, left_up));
            }
        }
        return dp[n][m];
    }
};