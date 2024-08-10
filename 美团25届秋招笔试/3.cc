#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
using ll = long long;

int find(queue<int> num_vec)
{
    vector<int> temp;
    while (!num_vec.empty())
    {
        temp.push_back(num_vec.front());
        num_vec.pop();
    }
    sort(temp.begin(), temp.end());
    int pre = temp[0];
    for (int i = 1; i < temp.size(); ++i)
    {
        if (temp[i] != ++pre) return pre;
    }
    return temp[temp.size() - 1] + 1;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        queue<int> num_vec;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            num_vec.push(tmp);
        }
        ll deleteOneCnt = 0;
        ll result = INT_MAX;
        while (!num_vec.empty())
        {
            // 全部删除
            int ret = find(num_vec);
            // cout << "ret: " << ret << endl;
            ll cnt = ret * k;
            result = min(cnt + deleteOneCnt, result);
            // cout << "result: " << result << endl;

            // 一次删除
            num_vec.pop();
            deleteOneCnt += x;
        }
        result = min(result, deleteOneCnt);
        cout << result << endl;
    }
    return 0;
}
