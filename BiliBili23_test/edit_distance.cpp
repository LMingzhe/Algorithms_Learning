#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/// @brief 参考代码随想录 编辑距离 https://programmercarl.com/0072.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;

    // dp[i][j]：表示以下标i-1结尾的字符串s1和以下标j-1结尾的字符串s2，所需要删除元素的最小ASCII删除总和
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    // 初始化
    for (int i = 1; i <= s1.size(); i++) dp[i][0] = dp[i - 1][0] + s1[i - 1];
    for (int j = 1; j <= s2.size(); j++) dp[0][j] = dp[0][j - 1] + s2[j - 1];

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << endl;

    return 0;
}
