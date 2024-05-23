#include <iostream>
#include <vector>

using std::vector;

/// leetcode 136 只出现一次的数字
/// @brief 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
///        你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

// 位运算-异或运算 时间复杂度O(n) 空间复杂度O(1)
// 1.任何数和0做异或运算，结果仍然是原来的数 2.任何数和其自身做异或运算，结果是0 3.异或运算满足交换律和结合律
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for (const auto& num : nums) // 根据异或运算性质，数组中所有数字异或运算值为单次出现元素
        {
            result ^= num;
        }
        return result;
    }
};