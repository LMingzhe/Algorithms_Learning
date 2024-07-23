#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// leetcode 

// 动态规划 时间复杂度O(n^2) 空间复杂度O(n^2)
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int result = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        ++result;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        ++result;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};

// 双指针法 时间复杂度O(n^2) 空间复杂度O(1)
class Solution {
public:
    int countSubstrings(string s) 
    {
        int result = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            result += extend(s, i, i, n);     // 奇数串
            result += extend(s, i, i + 1, n); // 偶数串
        }
        return result;
    }

    int extend(const string& s, int i, int j, int n)
    {
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j])
        {
            ++res;
            --i;
            ++j;
        }
        return res;
    }
};