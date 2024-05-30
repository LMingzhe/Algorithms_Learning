#include <iostream>
#include <vector>

using namespace std;

/// @brief 用bool数组保存帖子，true表示精华贴，注意区间是左闭右开区间。

int main(int argc, char** argv)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> posts(n + 1, false);
    while (m--)
    {
        int li, ri;
        cin >> li >> ri;
        for (int i = li; i < ri; i++) // 标识精华贴，左闭右开
        {
            posts[i] = true;
        }
    }
    
    int maxNum = 0;
    int left = 0;
    
    // note 这部分是滑动窗口法，计算复杂度会小一些
    int right = left + k - 1;
    if (right >= n) right = n - 1;
    for (int i = left; i <= right; i++)
    {
        if (posts[i]) maxNum++;
    }
    left++, right++;
    int cnt = maxNum;
    while (left < n)
    {
        if (right >= n) right = n - 1;
        if (right - left + 1 <= maxNum) break;
        if (posts[left - 1]) cnt--;
        if (posts[right]) cnt++;
        maxNum = max(maxNum, cnt);
        if (maxNum == k) break;
        left++, right++;
    }
    // note =======================

    // note 这部分代码比较暴力，好理解
    // while (left < n) 
    // {
    //     int right = left + k - 1;
    //     if (right >= n) right = n - 1;
    //     if (right - left + 1 <= maxNum) break;
    //     int cnt = 0;
    //     for (int i = left; i <= right; i++)
    //     {
    //         if (posts[i]) cnt++;
    //     }
    //     maxNum = max(maxNum, cnt);
    //     if (maxNum == k) break;
    //     left++;
    // }
    // note =======================

    cout << maxNum << endl;
    return 0;
}
