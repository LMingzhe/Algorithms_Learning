#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// fixme 未完成

int main(int argc, char const *argv[])
{
    int n, A, B, C;
    cin >> n >> A >> B >> C;
    vector<vector<int>> buildings(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> buildings[i][j];
        }
    }


    // 0 1 背包的思路，具体数据结构怎么写？
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = 0;
    
    for (int i = 1; i < n; i++)
    {
        
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + buildings[i][3];
    }

    cout << max(dp[n- 1][0], dp[n - 1][1]) << endl;

    return 0;
}
