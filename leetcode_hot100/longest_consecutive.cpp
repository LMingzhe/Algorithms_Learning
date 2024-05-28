#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::max;

/// leetcode 128 最长连续序列
/// @brief 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
///        请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
/// 时间复杂度O(n) 空间复杂度O(n)

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set;
        for (const int& num : nums) // 使用哈希表去重
        {
            num_set.insert(num);
        }
        int longestSeq = 0;
        for (const int& num : nums)
        {
            if (!num_set.count(num - 1)) // 只有前驱节点不存在的时候，才需要进入循环，因为如果前驱节点存在，后面肯定会遍历到
            {                                 // 不是从头开始遍历，无论如何也不可能超过从前驱节点开始遍历的序列长
                int currentNum = num;
                int currentSeq = 1;
                
                while (num_set.count(currentNum + 1)) // 直到找不到下一个数字为止
                {
                    currentNum++;
                    currentSeq++;
                }
                longestSeq = max(longestSeq, currentSeq);
            }
        }
        return longestSeq;
    }
};