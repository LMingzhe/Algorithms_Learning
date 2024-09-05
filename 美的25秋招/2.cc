#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> coins;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string tmp;
    while(getline(ss, tmp, ' '))
    {
        coins.push_back(stoi(tmp));
    }
    int amount;
    cin >> amount;
    // for (int i = 0; i < coins.size(); ++i)
    // {
    //     cout << coins[i] << endl;
    // }
    // cout << amount << endl;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;    
    for (int i = 0; i < coins.size(); ++i)
    {
        for (int j = coins[i]; j <= amount; ++j)
        {
            if (dp[j - coins[i]] != INT_MAX)
            {
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
    }

    if (dp[amount] == INT_MAX)
    {
        cout << -1 << endl;
    } else {
        cout << dp[amount] << endl;
    }

    return 0;
}
