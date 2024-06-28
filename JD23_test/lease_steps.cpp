#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

/// @brief 动态规划

const int INF = 4e6;

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
    vector<vector<int>> dp(n, vector<int>(m, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (chessBoard[i][j] == '*') continue;
            // 向右移动k个格子
            for (int k = j + 1; k < m && chessBoard[i][k] == '.'; k++)
            {
                dp[i][k] = min(dp[i][k], dp[i][j] + 1);
            }
            // 向下移动k个格子
            for (int k = i + 1; k < n && chessBoard[k][j] == '.'; k++)
            {
                dp[k][j] = min(dp[k][j], dp[i][j] + 1);
            }
            // 向右下移动k个格子
            for (int k = 1; i + k < n && j + k < m && chessBoard[i + k][j + k] == '.'; k++)
            {
                dp[i + k][j + k] = min(dp[i + k][j + k], dp[i][j] + 1);
            }
        }
    }

    if (dp[n - 1][m - 1] == INF)
    {
        cout << -1 << endl;
    } else {
        cout << dp[n - 1][m - 1] << endl;
    }
    return 0;
}
