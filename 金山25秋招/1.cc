#include <bits/stdc++.h>

using namespace std;

// AC 70%

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int maxSubarraySumCircular(vector<int>& nums) {
        // write code here

        int n = nums.size();

        vector<int> dp(2*n);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < 2 * n; ++i)
        {
            if (i <= n - 1)
            {
                dp[i] = max(dp[i-1] + nums[i], nums[i]);
                if (dp[i] > result) result = dp[i];
            } else {
                int index = i % n;
                dp[i] = max(dp[i - 1] + nums[index], nums[index]);
                if (dp[i] > result) result = max(dp[i] - nums[index], nums[index]);
            }
        }
    
        

        return result;
    }
};