#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/// @brief 从 x 到 y，只有顺时针走和逆时针走两种方法，取二者最小值即可
///        注意使用long long类型，结果可能会超过int类型最大值

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // dists[i] 表示顺时针从 i -> i+1 站的距离 dists[n] 表示顺时针 n -> 1 站距离
    vector<int> dists(n + 1); 
    dists[0] = 0; // dists[0] 无意义，置0
    for (int i = 1; i <= n; i++)
    {
        int dist;
        cin >> dist;
        dists[i] = dist;
    }

    int x, y;
    cin >> x >> y;
    // 求整个环距离。注意，这里 0要带L 表示 long long 类型，不然会溢出导致计算错误
    long long ringLen = accumulate(dists.begin(), dists.end(), 0L);
    if (x == y)
    {
        cout << 0 << endl;
        return 0;
    } else if (x > y) { // 因为要顺时针计算，所以如果x大于y，交换两个的值，这并不影响结果
        swap(x, y);
    }
    long long result = 0;
    for (int i = x; i < y; i++) // x 到 y 顺时针的距离
    {
        result += dists[i];
    }
    result = min(result, ringLen - result); // 取顺时针和逆时针中的最小值
    cout << result << endl;
    return 0;
}
