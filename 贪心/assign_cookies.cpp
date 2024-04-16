#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

/// leetcode 455 分发饼干
/// @brief 对每个孩子 i，都有一个胃口值  g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
///        如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
///        每个孩子最多只能给一块饼干
///        时间复杂度：O(nlogn) 空间复杂度：O(1)
///        贪心算法：局部最优推导全局最优  本题中应先满足胃口值大的

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 遍历胃口，如果满足，j--，如果不满足，s中已无法满足这个胃口值，跳过同样j--
        for(int i = s.size() - 1, j = g.size() - 1; i >= 0 && j >= 0; j--)
        {
            if (s[i] >= g[j])  // 饼干满足胃口值，饼干-1,i--，胃口-1,j--
            {
                count++;
                i--;
            }
        }
        return count;
    }
};