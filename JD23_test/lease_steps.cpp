#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

/// @brief 动态规划
// fixme k步，如何实现？

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> chessBoard(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            chessBoard[i][j] = line[j];
        }
    }
    // dp[i][j]：移动到(i, j)位置最少需要多少步
    vector<vector<int>> dp(n, vector<int>(m, std::numeric_limits<int>::max()));
    // 初始化
    for (int i = 0; i < m; i++)
    {
        if (chessBoard[0][i] != '*')
        {
            dp[0][i] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (chessBoard[i][0] != '*')
        {
            dp[i][0] = i;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (chessBoard[i][j] == '*') continue;
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    if (dp[n - 1][m - 1] == std::numeric_limits<int>::max())
    {
        cout << -1 << endl;
    } else {
        cout << dp[n - 1][m - 1] << endl;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (chessBoard[i][j] == '*') 
    //         {
    //             // int最大值表示不可达
    //             dp[i][j] = std::numeric_limits<int>::max();
    //         }
    //     }
    // }
    return 0;
}
