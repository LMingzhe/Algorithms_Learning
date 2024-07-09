#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/// @brief dijkstra 算法单源最短路径
/// 时间复杂度O(n^2) 空间复杂度O(n^2)

int main(int argc, char const *argv[])
{
    int n, m, p1, p2, val;
    cin >> n >> m;

    // 有向图，下标0不用，从1开始
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    // 存储从源点到每个节点的最短距离
    vector<int> minDist(n + 1, INT_MAX);

    // 记录顶点是否被访问过
    vector<bool> visisted(n + 1, false);

    minDist[start] = 0; // 起始点到自身的距离为0；

    // 用于记录上一个节点，打印最短路径
    vector<int> parent(n + 1, -1);

    // 遍历所有节点
    for (int i = 1; i <= n; i++)
    {
        // 用于搜索距离源点最近且未确定的节点参数，初始时从源节点1开始
        int minVal = INT_MAX;
        int cur = 1;

        // 1.选距离源点最近且未访问过的点
        for (int v = 1; v <= n; v++)
        {
            if (!visisted[v] && minDist[v] < minVal)
            {
                minVal = minDist[v];
                cur = v;
            }
        }

        // 2.标记该节点已访问
        visisted[cur] = true;

        // 3.更新cur所连接的未访问节点到源节点的距离
        for (int v = 1; v <= n; v++)
        {
            if (!visisted[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v])
            {
                minDist[v] = minDist[cur] + grid[cur][v];
                parent[v] = cur; // 更新最短路径
            }
        }
    }

    if (minDist[end] == INT_MAX) cout << -1 << endl; // 终点不可达
    else cout << minDist[end] << endl; // 到达终点最短路径

    // 输出最短路径
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << "->" << i <<endl;
    }

    return 0;
}
