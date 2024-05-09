#include <iostream>

/// leetcode 9 回文数
/// @brief 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
///        不使用 string
/// 时间复杂度O(logn) 空间复杂度O(1)

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 当 x < 0 时，x 不是回文数。
        // 非0数字的最后一位数字为0也不是回文数
        if (x < 0 || x % 10 == 0 && x != 0) return false;

        int revertedNumber = 0;
        // 反转一半数字，当 x <= revertedNumber 时，说明已经翻转了一半数字
        while (x > revertedNumber)
        {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};