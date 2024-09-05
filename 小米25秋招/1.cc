#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> makeA(n);
    vector<int> makeB(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> makeA[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> makeB[i];
    }

    int result = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        // result = min(makeA[i] + makeB[i], result);
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                result = min(result, makeA[i] + makeB[j]);
            } else {
                result = min(result, max(makeA[i], makeB[j]));
            }
        }
    }

    cout << result << endl;

    return 0;
}
