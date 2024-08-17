#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/// @brief AC100%

int main(int argc, char const *argv[])
{
    ll a, b;
    cin >> a >> b;
    ll target = b - a;
    ll z1 = 1, z2 = 3;
    ll index = 3;
    while (true)
    {
        if (z2 - z1 == target) break;
        else
        {
            z1 = z2;
            z2 += index;
            ++index;
        }
    }
    ll result = z2 - b;
    cout << result << endl;
    return 0;
}
