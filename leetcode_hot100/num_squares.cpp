#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

/// leetcode 279 完全平方数
/// @brief 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
///        完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
///        例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

// 动态规划 时间复杂度O(n(n^1/2))  空间复杂度O(n^1/2)
class Solution  
{
public:
    int numSquares(int n )
    {
        // f[i] 表示最少需要多少个数的平方来表示整数 i。
        vector<int> f(n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int minn = std::numeric_limits<int>::max();
            for (int j = 1; j * j <= i; j++) // 枚举 [1, n^1/2] 的数
            {
                minn = min(minn, f[i - j*j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};

// 数学方法 时间复杂度O(n^1/2)  空间复杂度O(1)
// 四平方和定理：任意一个正整数都可以被表示为至多四个正整数的平方和。这给出了本题的答案的上界。
//         当且仅当 n≠4^k×(8m+7)时，n 可以被表示为至多三个正整数的平方和
//         因此当 n=4^k×(8m+7)时，n 只能被表示为四个正整数的平方和
//         当 n≠4^k×(8m+7)时，答案会是1，2，3中的一个
class Solution 
{
public:
    // 判断是否为完全平方数
    bool isPerfectSuare(int x)
    {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x)
    {
        while (x % 4 == 0)
        {
            x / 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n) 
    {
        if (isPerfectSuare(n))
        {
            return 1;
        }

        if (checkAnswer4(n))
        {
            return 4;
        }
        
        for (int i = 1; i * i < n; i++)
        {
            int j = n - i * i;
            if (isPerfectSuare(j))
            {
                return 2;
            }
        }
        return 3;
    }
};