    #include <bits/stdc++.h>

    using namespace std;

    const int MOD = 10000009;
    const int Number = 233;
    using ll = long long;

    void oper(vector<vector<int>> &grid, int m, vector<int> optNums, int l, int r)
    {
        for (int i = l; i <= r; ++i)
        {
            if (m % 2 == 0)  // 偶操作 +
            {
                for (int j = 0; j < optNums.size(); ++j)
                {
                    if (j > grid[i].size() - 1)
                    {
                        grid[i].push_back(optNums[j]);
                    } else {
                        grid[i][j] += optNums[j];
                    }
                }

            } else { // 奇操作 -
                for (int j = 0; j < optNums.size(); ++j)
                {
                    if (j > grid[i].size() - 1)
                    {
                        grid[i].push_back(-optNums[j]);
                    } else {
                        grid[i][j] -= optNums[j];
                    }
                }
            }
        }
    }


    int main(int argc, char const *argv[])
    {
        int n, d, m;
        cin >> n >> d >> m;
        vector<vector<int>> grid(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int p;
            cin >> p;
            for (int k = 0; k <= p; ++k)
            {
                int temp;
                cin >> temp;
                grid[i].push_back(temp);
            }
        }

        for (int i = 1; i <= m; ++i)
        {
            int p, l, r;
            cin >> p >> l >> r;
            vector<int> optNums(p + 1);
            for (int i = 0; i <= p; ++i)
            {
                cin >> optNums[i];
            }
            oper(grid, i, optNums, l, r);
        }

        // 计算结果
        for (int i = 1; i <= n; ++i)
        {
            ll sum = 0;
            for (int k = 0; k < grid[i].size(); ++k)
            {
                sum += grid[i][k] * pow(Number, k);
                sum %= MOD;
            }
            cout << sum << " ";
        }
        cout << endl;
        return 0;
    }

