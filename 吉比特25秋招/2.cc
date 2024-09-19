#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    vector<int> dp(N);
    dp[0] = nums[0];
    int result = dp[0];

    for (int i = 1; i < N; ++i)
    {
        dp[i] = min(dp[i - 1] + nums[i], nums[i]);
        if (dp[i] < result) result = dp[i];
    }

    cout << result << endl;

    return 0;
}