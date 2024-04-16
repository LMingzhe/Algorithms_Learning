#include <iostream>
#include <vector>

using std::vector;

/// leetcode 376 摆动序列
/// @brief 给定一个整数序列，返回作为摆动序列的最长子序列的长度。 
///        通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。
///  时间复杂度：O(n) 空间复杂度：O(1)

class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() <= 1) return nums.size();
        int preDiff = 0; // 当前一对差值
        int curDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个树，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff; // 注意这里，只在摆动变化的时候更新prediff
            }
        }
        return result;
    }
};

// TODO 动态规划解法待补充
class Solution_dp
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        
    }
};