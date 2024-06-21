#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <list>

using namespace std;

/// @brief 树形dp 有点难，树形dp，一般是从下往上推

int maxN = 10005;
// dp[cur][1]：当前节点染色，那么当前节点为根节点及其左右子节点中，可以染色的最大数量
// dp[cur][0]：当前节点不染色，那么当前节点为根节点及其左右子节点中，可以染色的最大数量
vector<vector<int>> dp(maxN, vector<int>(2, 0));
vector<list<int>> grid(maxN); // 邻接表
vector<long> value(maxN); // 存储每个节点的权值

// 在树上进行动态规划
void dpOnTheTree(int cur)
{
    for (int child : grid[cur])
    {
        // 后序遍历，从下向上计算
        dpOnTheTree(child);
        // 情况一
        dp[cur][0] += max(dp[child][0], dp[child][1]);
    }

    // 计算dp[cur][1]
    for (int child : grid[cur])
    {
        long mul = value[cur] * value[child];
        long sqrtNum = (long)sqrt(mul);
        if (sqrtNum * sqrtNum == mul)
        {
            // 情况二
            // dp[cur][0]表示所有子节点染色或者不染色的最大染色数量
            // max(dp[child][0], dp[child][1]) 需要染色节点的当前孩子节点的最大染色数量
            // dp[cur][0] - max(dp[child][0], dp[child][1]) 除了要染色的节点及其当前子节点，其他孩子的最大染色数量
            // 最后 + dp[child][0] + 2, 就是本节点染色的最大染色节点数量
            dp[cur][1] = max(dp[cur][1], dp[cur][0] - max(dp[child][0], dp[child][1]) + dp[child][0] + 2);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }

    // 构建邻接表
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[x].push_back(y);
    }

    // 从根节点开始进行动态规划
    dpOnTheTree(1);
    
    // 输出最大染色节点数量
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}
