#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

/// leetcode 135 分发糖果
/// @brief n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
///        你需要按照以下要求，给这些孩子分发糖果：
///          1.每个孩子至少分配到 1 个糖果。 2.相邻两个孩子评分更高的孩子会获得更多的糖果。
///  时间复杂度：O(n) 空间复杂度：O(n)

class Solution
{
private:
    vector<int> candyVec;
public:
    int candy(vector<int>& ratings)
    {
        candyVec.resize(ratings.size(), 1);

        // 先确定右边评分大于左边的情况（从前向后遍历）
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1]) 
            {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }
        
        // 再确定左边大于右边的情况（从后向前遍历）
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                // 取最大值保证满足大于相邻的条件
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }

        int result = 0;
        for (const auto& cnt : candyVec)
        {
            result += cnt;
        }

        return result;
    }
};