#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

/// leetcode 207 课程表
/// @brief 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
///  在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
///  例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
///  请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
// NOTE 经典的拓扑排序问题：对于图G中的任意一条有向边(u,v)，u在排列中都出现在v的前面。
//                       如果图G中存在环（即图G不是「有向无环图」），那么图G不存在拓扑排序。

// 深度优先搜索
class Solution  
{
private:
    vector<vector<int>> edges; // 记录图中出度的边，即 eged[u] = {v, x, y} 表示 u->v u->x u->y
    vector<int> visited; // 记录节点访问状态
    bool valid = true; // 记录是否发生回环

    void dfs(int u)
    {
        visited[u] = 1; // 状态：搜索中
        for (const auto& v : edges[u])
        {
            if (visited[v] == 0) // 状态：未搜索
            {
                dfs(v);
                if (!valid) return;
            } else if (visited[v] == 1) { // 深优搜索到状态为搜索中的节点，说明发生回环，不存在拓扑排序
                valid = false;
                return;
            }
        }
        visited[u] = 2; // 状态：已完成
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);

        // 构造图
        for (const auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }

        // 从未访问过的节点开始dfs
        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        return valid;
    }
};

// 广度优先搜索
class Solution  
{
private:
    vector<vector<int>> edgesOut; // 记录图中出度的边，即 eged[u] = {v, x, y} 表示 u->v u->x u->y
    vector<int> edgesIn; // 记录节点入度的边数

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        edgesOut.resize(numCourses);
        edgesIn.resize(numCourses);

        for (const auto& info : prerequisites)
        {
            edgesOut[info[1]].push_back(info[0]);
            edgesIn[info[0]]++;
        }

        queue<int> que; // 辅助队列
        int visited = 0; // 记录访问过的节点
        for (int i = 0; i < numCourses; i++)
        {
            if (edgesIn[i] == 0) // 入度为0的节点入队列
            {
                que.push(i);
                visited++;
            }
        }

        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (const auto& v : edgesOut[u]) // 删除以u为弧尾的边，也就是u的出度边 u->v 
            {
                edgesIn[v]--;
                if (edgesIn[v] == 0) // 入度为0的节点入队列
                {
                    que.push(v);
                    visited++;
                }
            }
        }

        // 最后所有节点都被访问过，说明存在拓扑排序，否则存在图中存在环
        return visited == numCourses;
    }
};