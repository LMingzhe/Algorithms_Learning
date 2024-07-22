#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// fixme 超时，通过率10%

bool isInfluence(const vector<int>& building, const int& x0, const int& y0)
{
    if (max(abs(x0 - building[0]), abs(y0 - building[1])) <= building[2])
    {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> buildings(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            cin >> buildings[i][k];
        }
    }    

    // 时间复杂度 O(nq) 近似 O(n^2)
    int q;
    cin >> q;
    while (q--)
    {
        int x0, y0;
        cin >> x0 >> y0;
        int cnt = 0;
        for (const auto& building : buildings)
        {
            if (isInfluence(building, x0, y0))
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}