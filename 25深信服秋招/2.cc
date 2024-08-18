#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/// @brief AC40

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // vector<int> dp(n);
    // dp[0] = nums[0];
    // dp[1] = max(dp[0], nums[1]);
    // for (int i = 2; i < n; ++i)
    // {
    //     dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    // }

    // cout << dp[n - 1] << endl;

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][1] = nums[0];
    dp[0][0] = 0; 
    dp[1][0] = max(dp[0][0], dp[0][1]);
    dp[1][1] = nums[1];
    for (int i = 2; i < n; ++i)
    {
        dp[i][0] = max((ll)dp[i - 1][0], (ll)dp[i - 1][1]);
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + (ll)nums[i];
    }
    ll result = max(dp[n - 1][0], dp[n - 1][1]);
    cout << result << endl; 

    return 0;
}