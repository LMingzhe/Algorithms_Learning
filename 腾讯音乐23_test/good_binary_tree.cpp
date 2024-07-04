#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

/// @brief 动态规划

const int MOD = 1000000007;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<int> dp(n + 1);
    // 初始化，空树和只有根节点的数也是好二叉树
    dp[0] = 1; 
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0) // 根据题意，能构成好二叉树的节点数量必定是奇数
        {
            dp[i] = 0;
            continue;
        }
        for (int left = 0; left < i; left++)
        {
            // 左右子树也必定是好二叉树
            dp[i] = (dp[i] + (ll)dp[left] * dp[i - 1 - left]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
