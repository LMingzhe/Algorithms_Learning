#include <bits/stdc++.h>

using namespace std;

// AC 60%

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<pair<int, int>> grid(n);
    vector<int> disX(n);
    int maxX = 0;
    int avg = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        grid[i] = {x, y};
        disX[i] = x;
        maxX = max(maxX, x);
        avg += x;
    }
    avg /= n;
    int result = INT_MAX;
    for (int y = 0; y <= maxX; ++y)
    {
        int length = 0;
        for (int i = 0; i < n; ++i)
        {
            length += abs(disX[i] - y);
        }
        if (length < result) result = length;
    }

    cout << result << endl;

    return 0;
}
