#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    if (nums.size() == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int curSum = std::accumulate(nums.begin(), nums.end(), 0);

    if (curSum % x == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(nums.begin(), nums.end());
    int target = curSum % x;
    int removeNum = target;
    int addNum = x - target; 

    int result = INT_MAX;
    int cnt = 0;
    int curRemove = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == removeNum)
        {
            result = 1;
            break;
        }
        
        // if (nums[i] < removeNum)
        // {
        //     result = min(result, 1 + )
        // }

        if (curRemove < removeNum)
        {
            curRemove += nums[i];
            cnt++;
        } else if (curRemove == removeNum) {
            break;
        } else {
            cnt += curRemove - removeNum;
        }
    }
    result = min(result, min(cnt, addNum));
    
    cout << result << endl;

    return 0;
}
