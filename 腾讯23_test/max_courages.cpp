#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

/// @brief 贪心，注意最后结果可能溢出int范围

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int attack = 0;
    ll result = 0;
    // 贪心算法，先与当前战斗力最强的怪物战斗一次，增加最大的勇气值，再与当前战斗力最小的怪物战斗一次，
    // 将战斗力降到最小，使得下次与战斗力最强的怪物战斗能获得的勇气值最大。上面两个过程交替进行。
    for (int i = 0; i < n / 2; ++i)
    {
        int old = attack;
        attack = a[n - i - 1];
        result += (ll)a[n - i - 1] - old;
        attack = a[i];
    }

    // 如果n是奇数，还要补上与中间怪物的一次战斗
    if (n % 2 != 0)
    {
        int index = n / 2;
        if (attack < a[index])
        {
            int old = attack;
            attack = a[index];
            result += (ll)a[index] - old;
        } else {
            attack = a[index];
        }
    }

    cout << result << endl;

    return 0;
}
