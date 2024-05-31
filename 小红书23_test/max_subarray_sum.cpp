#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// @brief 动态规划 属于leetcode53最大字数组的变体

void subArray(vector<int>& array, int x)
{
    // note 这里更简单的方式 1.回朔+dp，这里的dp与leetcode53一致。整个数组不改+数组每个值都改一遍 求解最优解 时间复杂度会比较大
    // note               2.使用滚动数组可以把下面dp的空间复杂度降为O(1) 被折磨得脑壳疼，不改了。
    // dp[i]：表示以num[i]为结尾的子数组，能够获取的最大连续子数组和的情况
    // dp[i][0]：未修改前能够获取的最大连续子数组和
    // dp[i][1]：修改后能获得的最大连续子数组和
    vector<vector<int>> dp(array.size(), vector<int>(2));
    // 初始化dp数组
    dp[0][0] = array[0];
    dp[0][1] = x;
    int maxSum = max(dp[0][0], dp[0][1]);
    for (int i = 1; i < array.size(); i++)  
    {
        // 与leetcode53一致，若dp[i - 1][0]为负数，重新
        dp[i][0] = max(dp[i - 1][0] + array[i], array[i]);
        // note 原先我的写法是 ： dp[i][1] = max(dp[i-1][1] + array[i], dp[i-1][0] + x);
        // note 但这里缺少思考一种情况：当 x > dp[i-1][1] + array[i] 且 dp[i-1][0] + x < dp[i-1][1] + array[i] 时 (即 dp[i-1][0] < 0)
        // note                     dp[i][1]的最优值并非为 dp[i -1][1] + array[i]，而应该是 x，相当于把array[i]替换成x重新开始了一个新的子数组
        // note 这里真的很乱难理解，想了一个上午。。。。
        dp[i][1] = max(dp[i - 1][1] + array[i], max(dp[i - 1][0] + x, x));
        // cout << "dp[" << i << "][0]: " << dp[i][0] << endl; 
        // cout << "dp[" << i << "][1]: " << dp[i][1] << endl; 
        // note 更新最大和，注意这里需要比较dp[i][0]，因为不是一定要把某个数换成x才有最大和。比如 x为负数，而数组中均为正数
        maxSum = max(maxSum, max(dp[i][0], dp[i][1]));
        // cout << "maxSum: " << maxSum << endl;
    }
    cout << maxSum << endl;
}

int main(int argc, char** argv)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array;
        while(n--)
        {
            int num;
            cin >> num;
            array.push_back(num);
        }
        subArray(array, x);
    }
    return 0;
}
