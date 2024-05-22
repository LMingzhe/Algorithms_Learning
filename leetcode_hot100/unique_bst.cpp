#include <iostream>
#include <vector>

using std::vector;

/// leetcode 96 不同的二叉搜索树
/// @brief 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

// 动态规划 时间复杂度O(n^2) 空间复杂度O(n)
class Solution
{
public:
    int numTrees(int n)
    {
        // G[n]:1～n n个节点能构成的二叉树个数
        vector<int> G(n + 1, 0);
        // 初始化
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }

        return G[n];
    }
};

// 数学方法，卡特兰树 Cn  C0 = 1; Cn+1 = 2(2n+1)*Cn/n+2
// 时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    int numTrees(int n)
    {
        long long C = 1;
        for (int i = 0; i < n; i++)
        {
            C = (2 * (2 * i + 1) * C) / (i + 2);
        }
        return (int)C;
    }
};