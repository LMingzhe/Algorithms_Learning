#include <iostream> 
#include <vector>

using namespace std;

/// leetocode 494 目标和
/// @brief 给你一个非负整数数组 nums 和一个整数 target 。
///        向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
///        例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
///        返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

// 回朔 时间复杂度O(2^n) 空间复杂度O(n)
class Solution
{
public:
    int cnt = 0;
    void backtracking(vector<int>& nums, int target, int index, int sum)
    {
        if (index == nums.size())
        {
            if (sum == target)
            {
                cnt++;
            }
            return;
        }
        backtracking(nums, target, index + 1, sum + nums[index]);
        backtracking(nums, target, index + 1, sum - nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        backtracking(nums, target, 0, 0);
        return cnt;
    }
};

// 动态规划
class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (int& num : nums)
        {
            sum += sum;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0)
        {
            return;
        }

        // 动态规划部分类似01背包问题
        int n = nums.size(); // 这个可以看作物品重量
        int neg = diff / 2;  // 这个可以看作背包容量
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++)
            {
                if (num > j)
                {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
                }
            }
        }
        return dp[n][neg];
    }
};