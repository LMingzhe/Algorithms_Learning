#include <iostream>
#include <vector>
#include <list> // std::list 是一个双向链表实现，支持在任意位置进行插入/删除操作，但不支持随机访问
#include <queue>
#include <climits>

using namespace std;

/// @brief dijkstra 堆优化版
/// 时间复杂度O(ElogE) 空间复杂度O(N + E)

class mycomparison
{
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.second > rhs.second;
    }
};

struct Edge
{
    int to; // 邻接顶点
    int val; // 边的权重
    Edge(int t, int w) : to(t), val(w) {} 
};


int main(int argc, char const *argv[])
{
    int n, m, p1, p2, val;
    cin >> n >> m;

    // 使用邻接表来表示图，下标0不用，从1开始
    vector<list<Edge>> grid(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2, val));
    }

    int start = 1;
    int end = n;

    // 存储从源点到每个节点的最短距离
    vector<int> minDist(n + 1, INT_MAX);
    
    // 记录顶点是否被访问过
    vector<bool> visisted(n + 1, false);

    // 优先队列中存放 pair<节点， 源点到该节点的权值
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;

    // 初始化队列，源点到源点的距离为0，所以初始为0
    pq.push(pair<int, int>(start, 0));

    minDist[start] = 0; // 源点到自身的距离为0

    while (!pq.empty())
    {
        // 1. 第一步，选源点到哪个节点近且该节点未被访问过 （通过优先级队列来实现）
        pair<int, int> cur = pq.top();
        pq.pop();

        if (visisted[cur.first]) continue;

        // 2.第二步，该最近节点被标记访问过
        visisted[cur.first] = true;

        // 3.第三步，更新非访问节点到源点的距离（即更新minDist数组）
        for (const Edge& edge : grid[cur.first])
        {
            if (!visisted[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to])
            {
                minDist[edge.to] = minDist[cur.first] + edge.val;
                pq.push(pair<int, int>(edge.to, minDist[edge.to]));
            }
        }
    }

    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else cout << minDist[end] << endl;
    

    return 0;
}
