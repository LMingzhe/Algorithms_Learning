#include <iostream>
#include <unordered_map>
#include <vector>


/// leetcode 454 四数相加
/// @brief 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
///        为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。
///     时间复杂度: O(n^2)  间复杂度: O(n^2)（最坏情况下A和B的值各不相同，相加产生的数字个数为 n^2）
class Solution
{
public:
    int fourSumCount(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D)
    {
        std::unordered_map<int, int> umap;
        for (int a : A)
        {
            for (int b : B)
            {
                umap[a + b]++;
            }
        }

        int count;
        for (int c : C)
        {
            for (int d : D)
            {
                if (umap.find(0 - (c + d)) != umap.end())
                {
                    count += umap[0 - (c + d)];
                }
            }
        }

        return count;
    }
};