#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

/// @brief 简单题，注意类型大小溢出

bool isPerfectNum(ll& num)
{
    string numStr = to_string(num);
    if (numStr.size() == 1 && numStr == "0") return false;
    int cnt = 0;
    for (const auto& ch : numStr)
    {
        if (ch != '0') cnt++;
        if (cnt > 1) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll product = (ll)nums[i] * nums[j];
            if (isPerfectNum(product))
            {
                result++;
            }
        }
    }
    cout << result << endl;
    return 0;
}
